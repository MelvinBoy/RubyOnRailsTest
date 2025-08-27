// <~> --------------------------------------------------------------------------------
//   Dell confidential, proprietary information covered under NDA/SLA agreements
//   (c) Copyright 2023 Dell Inc. No source code distribution allowed without prior consent from Dell
// <~> --------------------------------------------------------------------------------
#include "Ec.h"
#include "Thermal.h"
#include "PeakPower.h"
#include "Rtc.h"

//These are bits 17-23 of Time Control Window for Per Plane Power Limit Data (Fig 3-38) of
//  PECI 3.0 spec rev 0.6. The formula is (1+X/4)*(2^Y) in time units (default 1mS)
//     where Y is bits[0-4] and X is bits [5-6]

//28 second for PL1 time window (tau)
#define PL1_TAU   0x6e
//10mS for PL2 time window / constant
#define PL2_TAU   0x23

// PL1, PsysPL1, PL2, PL3 control enable/disable by EC PEC
#define PL1_EN    1
#define PL2_EN    1
#define PL3_EN    0
#define PL4_EN    1

static const int SysPpPolicy[NUM_OF_PP_POLICY_SETTINGS]=
{
    PEAK_POWER_RSOC_THRESHOLD,    // PP_PEAK_POWER_RSOC_THRESHOLD
    RSOC_CHARGE_THERSHOLD,        // PPP_RSOC_CHARGE_THERSHOLD,
    PEAK_POWER_RSOC_HYST,         // PPP_PEAK_POWER_RSOC_HYST,
    SAFE_BAT_BURST,               // PPP_SAFE_BAT_BURST,
    DEFAULT_BAT_BURST,            // PPP_DEFAULT_BAT_BURST,
    E5_PL3_TIME_WINDOW,           // PPP_E5_PL3_TIME_WINDOW,
    E5_PL3_DUTY_CYLE,             // PPP_E5_PL3_DUTY_CYLE,
    E4_PL3_TIME_WINDOW,           // PPP_E4_PL3_TIME_WINDOW,
    E4_PL3_DUTY_CYLE,             // PPP_E4_PL3_DUTY_CYLE,
    PL1_TAU,                      // PPP_PL1_TAU,
    PL2_TAU,                      // PPP_PL2_TAU,
    PL1_EN,                       // PPP_PL1_EN,
    PL2_EN,                       // PPP_PL2_EN,
    PL3_EN,                       // PPP_PL3_EN,
    PL4_EN                        // PPP_PL3_EN,
};

//return platform-specific peak power policy setting
int SysPeakPowerPolicy(PeakPowerPolicyEnumTp Index)
{
    if(Index >= NUM_OF_PP_POLICY_SETTINGS)
    {
        DPRINTF(DEBUG_EVENT | DEBUG_ALWAYS | DEBUG_EVENT,("SysPeakPowerPolicy Index value incorrect !!"));
        return 0;
    }
    return SysPpPolicy[Index];
}

//
// System-specific PeakPower table structures
// Tributo_MTL_PeakPowerCharger parameter_v03_20230627.xlsx
//
#define mW(a) (a*8)

//CML42:14" UMA
#  define Tributo_ADL \
{                                                                              \
      /*{AcId,      BatId,      Pl1,  Pl2,  PsysPl2,  Pl3,   Pl4,  IccMax,*/   \
        {AC_0_W  ,      0,       27,   27,       27,    0,    27,      0},     \
        {AC_0_W  , BAT_55_WHR,   28,   55,       55,    0,   120,      0},     \
        {AC_30_W ,      0,       27,   27,       30,    0,    27,      0},     \
        {AC_30_W , BAT_55_WHR,   64,   64,       85,    0,   120,      0},     \
        {AC_45_W ,      0,       28,   28,       45,    0,    28,      0},     \
        {AC_45_W , BAT_55_WHR,   64,   64,      100,    0,   120,      0},     \
        {AC_60_W ,      0,       28,   44,       60,    0,    44,      0},     \
        {AC_60_W , BAT_55_WHR,   64,   64,      115,    0,   120,      0},     \
        END_OF_PP_TABLE                                                        \
};


static PeakPowerSettingTp PP_TBL_SYS0_CPU0_GFX0[]=Tributo_ADL;

//collection of all possible settings for this platform
typedef PeakPowerSettingTp *PeakPowerSettingPtrTp;
static const PeakPowerSettingPtrTp PeakPowerSettings[NUM_OF_SYS_FLAVORS][NUM_OF_CPUS_TDP][NUM_OF_GFXS] =
     PP_TBL_INIT_DATA;

//Minmum allowable setting for IccMax for each supported processor
//NOTE: If IccMax is ever set below this value CPU may shutdown or malfunction
//Tables below should not have any entries with IccMax below this value for a given processor
static const int MinIccMaxVal[NUM_OF_CPUS_TDP] = {31};

byte CpuTDPIndex()
{
    DPRINTF(DEBUG_PEAK_PWR, ("CpuTDPIndex():CpuTypeId:%x\n", CpuTypeId));
    return CPU0;
}

int GetMinIccMax()
{
    return MinIccMaxVal[CpuTDPIndex()];
}

//Get appropriate PP setting for this AC/battery combination
PeakPowerSettingTp *GetPpSettings(int AcCapacity, int BatCapacity)
{
    PeakPowerSettingTp *El, *Tbl, *MaxEl = NULL;
    //best match (in case we can't find exact match)
    int MaxAc = 0, MaxBat = 0;

    DPRINTF (DEBUG_PEAK_PWR, ("GetPpSettings(%d:%d:%d %d, %d)\n",
        SysIndex(), CpuTDPIndex(), GfxIndex(), AcCapacity, BatCapacity));

    Tbl = El = PeakPowerSettings[SysIndex()][CpuTDPIndex()][GfxIndex()];

    while (1)
    {
        //See if the end of table is reached
        if ((!El->AcId) && (!El->BatId) && (!El->Pl1))
            break;

        //See if we can find matching PP setting
        if ((El->AcId == AcCapacity) && (El->BatId == BatCapacity))
            return El;

        //Try to figure out the best match based on maximum combination of
        //AC/battery exceeding or equal to current AC/battery combintion
        //NOTE: AC adapter capacity is the leading/primary selection criteria

        //keep track of greatest (max) AC adapter capacity for this table
        if ((AcCapacity >= El->AcId) && (MaxAc < El->AcId))
        {
            MaxAc = El->AcId;
            //Update greatest battery capacity for this (max) AC adapter
            MaxBat = El->BatId;

            //make sure we rememebr this element ONLY if it has sufficient battery capacity
            MaxEl = (BatCapacity >= MaxBat) ? El : NULL;
        }

        //keep track of greatest battery capacity for max AC adapter
        if ((MaxAc == El->AcId) && (BatCapacity >= El->BatId) && (MaxBat < El->BatId))
        {
            MaxBat = El->BatId;
            //rememeber pointer to this element
            MaxEl = El;
        }

        //advance to next element
        El++;
    }

    if (MaxEl != NULL)
    {
        //return address to best matching element
        DPRINTF(DEBUG_PEAK_PWR, (" best match AC:%d, Bat:%d\n", MaxEl->AcId, MaxEl->BatId));
        return MaxEl;
    }

    //return address to first element - it should be default (disabled) PP setting
    DPRINTF(DEBUG_PEAK_PWR, (" Nothing found - use default/disable settigns\n"));
    return Tbl;
}

