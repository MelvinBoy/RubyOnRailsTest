// <~> --------------------------------------------------------------------------------
//   Dell confidential, proprietary information covered under NDA/SLA agreements
//   (c) Copyright 2000-2022 Dell Inc. No source code distribution allowed without prior consent from Dell
// <~> --------------------------------------------------------------------------------
#ifndef __DEBUG_H__
#define __DEBUG_H__

//
// This file contains EC debug definitions and macros
//

//
// Component-level debug enables
//

#define DEBUG_AC                 0
#define DEBUG_AC2                0
#define DEBUG_ACPI               0
#define DEBUG_ACPI_EC            0
#define DEBUG_ACPI_MUTE          0
#define DEBUG_AD_CONVERT         0
#define DEBUG_ADAPTIVE_C_STATE   0
#define DEBUG_ADV_BATT_MGMT      0
#define DEBUG_ADV_DEBUG_MENU     0
#define DEBUG_ADAPTER_AUTH       0
#define DEBUG_AIC                0
#define DEBUG_AIC_FLASH          0
#define DEBUG_ALS                0
#define DEBUG_ALWAYS             0
#define DEBUG_AMBIENT_RESPONSE   0
#define DEBUG_ANTENNA            0
#define DEBUG_ANTENNA_FLASH      0
#define DEBUG_ANTENNA_FUNCTION   0
#define DEBUG_AOS_VR             0
#define DEBUG_ASF                0
#define DEBUG_AUDIO              0
#define DEBUG_AUTO_NEGOTIATION   0
#define DEBUG_AUTO_ON            0
#define DEBUG_BASE               0
#define DEBUG_BAT_AUTH           0
#define DEBUG_BAT_BST            0
#define DEBUG_BAT_EMUL           0
#define DEBUG_BAT_GAUGE          0
#define DEBUG_BATT_CHG_CAP       0
#define DEBUG_BATT_MGMT          0
#define DEBUG_BATTERY            0
#define DEBUG_BATT_SERVICE_MODE  0
#define DEBUG_BC                 0
#define DEBUG_BPCC               0
#define DEBUG_CAMERA             0
#define DEBUG_CAMERA_HARD_MUTE   0
#define DEBUG_CAM_SHUTTER_CLOSED_LOOP 0
#define DEBUG_CAP_BUTTON         0
#define DEBUG_CAPABILITIES       0
#define DEBUG_CATERR             0
#define DEBUG_CHARGER            0
#define DEBUG_CHARGER_KEYS       0
#define DEBUG_CHG_DISABLE        0
#define DEBUG_CHROME             0
#define DEBUG_CMOS               0
#define DEBUG_CONFIG             0
#define DEBUG_CONNECTED_STANDBY  0
#define DEBUG_CPLD_ECMBOX        0
#define DEBUG_DASH_SMB           0      // Low level SMBus
#define DEBUG_DASH_MCTP          0      // MCTP protocol layer
#define DEBUG_DASH_PLDM          0      // PLDM protocal layer
#define DEBUG_DASH_HOST          0      // Host (i.e. mailbox commands)
#define DEBUG_DASH_PET           0      // PET (Platform Event Trap)
#define DEBUG_DASH_MISC          0      // Misc
#define DEBUG_DASH               (DEBUG_DASH_SMB || DEBUG_DASH_MCTP || DEBUG_DASH_PLDM || DEBUG_DASH_HOST || DEBUG_DASH_PET || DEBUG_DASH_MISC)
#define DEBUG_DDM                0
#define DEBUG_DELL_FLASH         0
#define DEBUG_DIAG               0
#define DEBUG_DIAG_BLINK         0
#define DEBUG_DIMM_SENSOR        0
#define DEBUG_DOCK               0
#define DEBUG_DOCK_INTR          0
#define DEBUG_DOCKPWR            0
#define DEBUG_DUAL_C_CABLE       0
#define DEBUG_DUAL_C_CABLE_FLASH 0
#define DEBUG_DPTF               0
#define DEBUG_DPTC               0
#define DEBUG_ECC_TIMING         0
#define DEBUG_ECI                0
#define DEBUG_ECI_SMB            0
#define DEBUG_ENCVARS            0
#define DEBUG_FAILSAFE           0
#define DEBUG_EECOLOR            0
#define DEBUG_EEPROM             0
#define DEBUG_ESPI               0
#define DEBUG_ESPI_OOB           0
#define DEBUG_EVENT              0
#define DEBUG_EVENT_TRACE        0
#define DEBUG_EXPCARD            0
#define DEBUG_FAN                0
#define DEBUG_FAN_TACH           0
#define DEBUG_FAN2               0
#define DEBUG_FnTEST             0
#define DEBUG_GPIO               0
#define DEBUG_GPIO_MONITOR       0
#define DEBUG_GPS                0
#define DEBUG_HISPEED_DASH       0
#define DEBUG_HISPEED_ECI        0
#define DEBUG_HOOKS              0
#define DEBUG_HOST               0
#define DEBUG_HW_QUERY           0
#define DEBUG_HW_CRYPTO          0
#define DEBUG_HW_CRYPTO_TESTS    0
#define DEBUG_ICH                0
#define DEBUG_IFUSE              0
#define DEBUG_IMON               0
#define DEBUG_IMVP_VR            0
#define DEBUG_INTR               0
#define DEBUG_INTRUSION          0
#define DEBUG_KBD                0
#define DEBUG_KBD_BKLT           0
#define DEBUG_KICKSTAND          0
#define DEBUG_LID                0
#define DEBUG_LINEARFANS         0
#define DEBUG_LINEARTHERMS       0
#define DEBUG_LINEARTHERMAL_LOG  0
#define DEBUG_LPC                0
#define DEBUG_MCP16              0
#define DEBUG_MBIST              0
#define DEBUG_MBOX               0
#define DEBUG_MBOX_LATENCY       0
#define DEBUG_MBOX_SECURITY      0
#define DEBUG_MIC_HARD_MUTE      0
#define DEBUG_MMIO               0
#define DEBUG_MISC_MBOX          0
#define DEBUG_MPLAB              0
#define DEBUG_MPS_VR             0
#define DEBUG_MSE                0
#define DEBUG_MTASK              0      // System Task
#define DEBUG_NVDC               0
#define DEBUG_NVIDIA_DDS         0
#define DEBUG_PAID               0
#define DEBUG_PANEL              0
#define DEBUG_PASSWORD           0
#define DEBUG_PAYLOAD            0      // for Static Binary Payloads feature
#define DEBUG_PBA                0
#define DEBUG_PCIE_BIFURCATION   0
#define DEBUG_PCMCIA             0
#define DEBUG_PEAK_PWR           0
#define DEBUG_PEAK_SHIFT         0
#define DEBUG_PECI               0
#define DEBUG_PECI_ERRORS       (0 || DEBUG_PECI)   // Just the PECI errors (things that are abnormal)
#define DEBUG_PECI_STATS         0                  // Collect statistics and periodically print them out the OUTDEV
#define DEBUG_PEN                0
#define DEBUG_PERM_DISABLE       0
#define DEBUG_PID                0
#define DEBUG_POA                0
#define DEBUG_PORT80_TWO_BYTES   0
#define DEBUG_POWER_PATH         0
#define DEBUG_POWER_PLANES       0
#define DEBUG_POWER_SOURCE       0
#define DEBUG_PPID               0
#define DEBUG_PPS                0
#define DEBUG_PROP_SERVICES      0
#define DEBUG_PROXIMITY          0
#define DEBUG_PS2_CMD            0
#define DEBUG_PS2_DEV            0
#define DEBUG_PS2_LATENCY        0
#define DEBUG_PSID               0
#define DEBUG_PSU                0
#define DEBUG_I2C_PSU            0
#define DEBUG_PUMP               0
#define DEBUG_PWR_SEQ            0
#define DEBUG_PWRB               0
#define DEBUG_PWRLED             0
#define DEBUG_PWRLIM             0
#define DEBUG_QMSPI              0
#define DEBUG_QSKEY              0
#define DEBUG_QUICKSET           0
#define DEBUG_RENESAS_VR         0
#define DEBUG_RGB_PERKEY         0
#define DEBUG_ROMAPI             0
#define DEBUG_ROT                0      // EC Root of Trust
#define DEBUG_RTC                0
#define DEBUG_RTC_CORRUPTION     0
#define DEBUG_RTC_RESET          0
#define DEBUG_AUTO_RTC_RESET     0
#define DEBUG_RTOS               0
#define DEBUG_RTOS_TWDG          0      // RTOS Task Watchdog
#define DEBUG_SALOMON_DOCK       0
#define DEBUG_SCAN               0
#define DEBUG_SHA256             0
#define DEBUG_SIGN_OF_LIFE       0
#define DEBUG_SKS_FLASH          0
#define DEBUG_TARGET_SMB         0
#define DEBUG_TARGET_SMB_CMD     0
#define DEBUG_SLEEP              0
#define DEBUG_SLEEP_UART         0
#define DEBUG_SLPX_TIMING1       0
#define DEBUG_SmartAMP           0
#define DEBUG_SMB                0
#define DEBUG_SMI                0
#define DEBUG_SMIKEY             0
#define DEBUG_SMOKELESS          0
#define DEBUG_SPI                0
#define DEBUG_SPI_TAMPER         0
#define DEBUG_STT                0
#define DEBUG_SYS_PDAT           0
#define DEBUG_SYSMGMT            0
#define DEBUG_TABLE_MODE         0
#define DEBUG_TABLED             0
#define DEBUG_TABLET             0
#define DEBUG_TABLET_CSR_FLASH   0
#define DEBUG_TABLET_PS          0
#define DEBUG_TABLETDOCK         0
#define DEBUG_TASK_NAME          0
#define DEBUG_TFR_FLASH          0
#define DEBUG_THERM              0
#define DEBUG_THERM_GRAPHICS     0
#define DEBUG_THERM_TABLE        0
#define DEBUG_THERMAL_GUI        0
#define DEBUG_TIMERS             0
#define DEBUG_TOUCHPAD           0
#define DEBUG_TP_BKLT            0
#define DEBUG_TREPORT            0
#define DEBUG_TRIN_CABLE_FLASH   0
#define DEBUG_TRIN_DOCK          0
#define DEBUG_TRIN_DOCK_FLASH    0
#define DEBUG_UCSI               0
#define DEBUG_UPD                1
#define DEBUG_UPD_FLASH_LESS     0
#define DEBUG_UPD_MSG            0
#define DEBUG_UPD_MUX            0
#define DEBUG_UPD_POWER_MGMT     0
#define DEBUG_UPD_PORT_STATE     0
#define DEBUG_UPD_CTRL_STATE     0
#define DEBUG_UPD3_STATE         0
#define DEBUG_UPD_STATE          (DEBUG_UPD_PORT_STATE || DEBUG_UPD_CTRL_STATE || DEBUG_UPD3_STATE)
#define DEBUG_UPD_TASK           0
#define DEBUG_USB                0
#define DEBUG_USB_HUB            0
#define DEBUG_USB_PWRSHARE       0
#define DEBUG_USBPD_FLASH        0
#define DEBUG_USBPD_DELL_DEVICE  0
#define DEBUG_VIBRATOR           0
#define DEBUG_VOLUME_BUTTON      0
#define DEBUG_WDT                0
#define DEBUG_WIGIG              0
#define DEBUG_WIRELESS_CHARGER   0
#define DEBUG_WIRELESS_LED       0
#define DEBUG_WIRELESS_SWITCH    0
#define DEBUG_WLAN               0
#define DEBUG_WOL                0
#define DEBUG_WPAN               0
#define DEBUG_WWAN               0



#define DBG_CONFIG_BARS          0
#define DBG_SLPX_TIMING1         0

//
//Switches to turn on test code for various features to assist in debugging
//
#define TEST_AC            0
#define PWRSEQ_CAPTURE     0

// do not check this in set to 1 for X or A revs.  Use with caution for T release.
#define DEBUG_MBOX_OS      1

//
// Set this flag to enable debug by default
//
#define DEBUG_FLAG_ALW_ON  1
// allow testing flash update on a system without an LPC bus
#define DEBUG_CMD_FLASH    0

//
// List of supported debug output devices
//
#define OUTDEV_NONE         0
#define OUTDEV_MCU          BIT0
#define OUTDEV_UART         BIT1
#define OUTDEV_BITBANG      BIT3
#define OUTDEV_BUFF         BIT4
#define OUTDEV_SPI          BIT5
#define OUTDEV_UART_HS      BIT6
#define OUTDEV_SWO          BIT7
#define OUTDEV_RTOS_TRACE   BIT8
#define OUTDEV_SEGGER_RTT   BIT9

//
// Default output debug device
//   - This can be set with an environment variable EC_DEBUG_DEV=xxx for private builds, where xxx is one of the OUTDEV_xxx definitions above
//   - We can't currently set OUTDEV_UART to be the default, since doing so will cause us to always enable the UART (which means we never sleep).
//

#ifndef OUTDEV_DEBUG
#  define OUTDEV_DEBUG (OUTDEV_UART_HS)
#endif
#define UART_TIMEOUT  0x010000  // signed long to prevent infinite wait on UART status bit

//
// Macro for debugging macros
//
// The MDB macro can be used to separate nested macro expansions so that you can see where each
//  nested macro sits in the expansion. This macro supports printing up to 4 arguments from the
//  macro being debugged, with empty arguments shown as "NO ARG".
//
// Debugging with the MDB macro:
//  Invoke make for the specific target you are looking at (e.g. Core/Kernel/ec_main.o) with
//   DEBUG_MACRO=1. This will create an intermediate file (.i) in the source location where
//   every macro using MDB will be "tagged" with START_MACRO/END_MACRO and the name passed in.
//  Ex. make -f GnuMakefile Core/Kernel/ec_main.o DEBUG_MACRO=1
//  NOTE!! If DEBUG_MACRO is set, the build will break... this is OK, since it should only
//   used for examining macros to verify correctness, but this is why you need to specify
//   the specific target.
//  NOTE 2!! The way macro_body is used for Metaware may cause problems if the argument is not wrapped
//   in parentheses when MDB is invoked/when the debugged macro (e.g DPRINTF) is defined. This is
//   completely avoided by using variadic macros (using ... and __VA_ARGS__) on newer compilers, but
//   Metaware does not support it.
// Adding MDB to existing macro definitions:
//  The following line:
//   #define DPRINTF { if (class) dprintf args ; }
//  should be changed to:
//   #define DPRINTF(class,args) MDB("DPRINTF(class,args)",class,args,NARG,NARG,{ if (class) dprintf args ; })
//  which now produces the following expansion for DPRINTF(1,("1+1=%d\n",(1+1))) :
//   START_MACRO "DPRINTF(class,args)" $[ ARG1::1, ARG2::("1+1=%d\n",(1+1)), ARG3::NOARG, ARG4::NOARG $] ===> $[ { if (1) dprintf ("1+1=%d\n",(1+1)) ; } $] END_MACRO "DPRINTF(class,args)"
#define NARG NOARG
#if defined(DEBUG_MACRO) && (DEBUG_MACRO==1)
# if defined(ARG1) || defined(ARG2) || defined(ARG3) || defined(ARG4) || defined(NOARG)
#  error Defining ARGx or NOARG breaks the DEBUG_MACRO support!
# endif
# if defined(TC_METAWARE) && (TC_METAWARE == 1)
#  define MDB(namestring,arg1,arg2,arg3,arg4,macro_body) START_MACRO namestring $[ ARG1::arg1, ARG2::arg2, ARG3::arg3, ARG4::arg4 $] ===> $[ macro_body $] END_MACRO namestring
# else
#  define MDB(namestring,arg1,arg2,arg3,arg4,...) START_MACRO namestring $[ ARG1::arg1, ARG2::arg2, ARG3::arg3, ARG4::arg4 $] ===> $[ __VA_ARGS__ $] END_MACRO namestring
# endif
#else
# if defined(TC_METAWARE) && (TC_METAWARE == 1)
# define MDB(namestring,arg1,arg2,arg3,arg4,macro_body) macro_body
# else
# define MDB(namestring,arg1,arg2,arg3,arg4,...) __VA_ARGS__
# endif
#endif

//
// Debug trace macros
//
#if (OUTDEV_DEBUG & OUTDEV_MCU)
#define TRACE(val)
#else
#define TRACE(val) { MCU->DATA = val; }
#endif

/*
    MCU debug port is runnig at CPU clock (24MHz), it is over 130 times faster than our
    normal SEROUTs (at 115.2Kbaud). With our debug code optimized I measured 650nS per
    byte/character transmit rate (370nS time per actual 8-bit transmission). MCU port can be
    used for debuging time sensitive EC issues in conjunction with Pegasus board from SMSC.

    Beware that current hardware layout of MCLK/MDAT is very poor resulting in a terrible
    signal quality (a lot of reflections) wich may lead to occasional data corruption of
    the debug stream. This would be different from one system to the next and will depend on
    the routing and cable quality between EC debug port and Pegasus. So DO NOT connect
    standard (WLAN) debug card if MCU is used (it will add more reflections further
    degrading MCLK/MDAT signals possibly making it unusable).

    Pegasus board also manages to get out of sync every now and then resulting in garbage data till it
    is power cycled/reset.

    To take advantage of MCU we need:
    1) Disable MCU traces in SMB code
    2) make it exclusive of other debug types (ex: UART/BITBANG) as they will slow us down
    3) reduce putc() in dprintf to barebone version (no bDEBUG_REPLAY support either)
    4) disconnect debug card as it will add reflections further degrading MCLK/MDAT signals
          (they are already very ugly and barely working due to routing topology
*/
#define MCU_DEBUG (OUTDEV_DEBUG & OUTDEV_MCU)

#if  MCU_DEBUG
#define TRBYTE(val); {MCU->DATA = (val);}

#define TRWORD(val);  {TRBYTE((val) & 0xFF); TRBYTE((val) >> 8);}
#define TREVENT(nbr); {TRBYTE(0xFD); TRWORD((nbr));}

#define TRACE0(nbr, cat, lvl, str);                     {TREVENT(nbr);}
#define TRACE1(nbr, cat, lvl, str, p1);                 {TREVENT(nbr); TRWORD(p1);}
#define TRACE2(nbr, cat, lvl, str, p1, p2);             {TREVENT(nbr); TRWORD(p1); TRWORD(p2);}
#define TRACE3(nbr, cat, lvl, str, p1, p2, p3);         {TREVENT(nbr); TRWORD(p1); TRWORD(p2); TRWORD(p3);}
#define TRACE4(nbr, cat, lvl, str, p1, p2, p3, p4);     {TREVENT(nbr); TRWORD(p1); TRWORD(p2); TRWORD(p3); TRWORD(p4);}
#define TRACE5(nbr, cat, lvl, str, p1, p2, p3, p4, p5); {TREVENT(nbr); TRWORD(p1); TRWORD(p2); TRWORD(p3); TRWORD(p4); TRWORD(p5);}

#define trace();
#define trace0(nbr, cat, lvl, str);
#define trace1(nbr, cat, lvl, str, p1);
#define trace2(nbr, cat, lvl, str, p1, p2);
#define trace3(nbr, cat, lvl, str, p1, p2, p3);
#define trace4(nbr, cat, lvl, str, p1, p2, p3, p4);
#define trace5(nbr, cat, lvl, str, p1, p2, p3, p4, p5);
#endif

#if DEBUG_TASK_NAME
# define DPRINTF_TASK_NAME()    dprintf_task_name()
#else
# define DPRINTF_TASK_NAME()
#endif

//
// Debug print macros
//
#define DPRINTF(class,args) { if (class) { DPRINTF_TASK_NAME(); dprintf args ; } }
#define xDPRINTF(...)
#define pPRINTF(args) DPRINTF(DEBUG_PWR_SEQ, args) //empty
#define DPRINTV(class,msg,buf,len) \
    { \
        if (class) \
        { \
            register int _i; \
            \
            DPRINTF_TASK_NAME(); \
            dprintf (msg); \
            for (_i = 0; _i < len; _i++) \
                dprintf (" %02x", buf[_i]); \
            dprintf ("\n"); \
        } \
    }
#define DPRINTVL(class,msg,buf,len) \
    { \
        if (class) \
        { \
            register int _i; \
            \
            DPRINTF_TASK_NAME(); \
            dprintf (msg); \
            for (_i = 0; _i < len; _i++) \
                dprintf (" %08lx", buf[_i]); \
            dprintf ("\n"); \
        } \
    }
#define DPRINTVS(class,msg,buf,len) \
    { \
        if (class) \
        { \
            register int _i; \
            \
            DPRINTF_TASK_NAME(); \
            dprintf (msg); \
            for (_i = 0; _i < len; _i++) \
            {                       \
                if (buf[_i])        \
                    dprintf ("%c", buf[_i]); \
                else       \
                    break; \
            }              \
            dprintf ("\n"); \
        } \
    }
#define xDPRINTV(class,msg,buf,len)
#define DPRINTF_DECIMAL(class,args) { if (class) { DPRINTF_TASK_NAME(); dprintf_decimal args ; } }
#define xDPRINTF_DECIMAL(class,args)

#define fn_tests_locked() (fn_tests_lock_state != 0xff)

extern void HandleDebugMbox();
extern void HandleDebugInitS5();
extern void HandleDebugInitPowerOn();
extern void ShowTodS0();
extern void ShowTodS5();
extern void DebugArmItmRtosInit();

#if DEBUG_EVENT_TRACE
//Element in trace FIFO
typedef struct
{
    byte TimeStamp;
    byte Context;
    word EventId;
} DebugInfoTp;

SERVICE_FLAG_EXT(bit_flag, SERVICE_DUMP_TRACE);

//how big is event trace buffer (x4 bytes)
#define EVENT_TRACE_BUF_SZ 700

//set relative time base to 0 in event trace at this instant
#define EVENT_TRACE_RST_TIME()   {EvtTrTimeBase = time_stamp();}

//The higher the compact level the less redundant information should be in the trace
//to preserve buffer space for meaningful capture
#define COMPACT_EVENT_TRACE 0

//reset nesting count/level
#define EVENT_TRACE_RST_NLEV()   {EvtTrNestLev = PrevEvtTrNestLev = 0;}

//Similar to scope trigger postition 0-100%.
//Make sure that we have at least this percentage of data captured in the trace prior to trigger
#define TRIGGER_POSITION 80
#define PRE_TRIGGER_FIFO_DEPTH ((EVENT_TRACE_BUF_SZ * TRIGGER_POSITION) / 100)

//Invoke this macro when the event capture should be triggered
// This means that writing of events will not go passed this point minus TRIGGER POSITION
#define EVENT_TRACE_TRIGGER() \
{   \
    dword intr_status; \
    if (!StopEvtTrWrAt) \
    {\
        _intr_save(intr_status); \
        StopEvtTrWrAt = (EvtTrWrPtr + EVENT_TRACE_BUF_SZ - PRE_TRIGGER_FIFO_DEPTH) % EVENT_TRACE_BUF_SZ; \
        if (!StopEvtTrWrAt) StopEvtTrWrAt++; \
        EvtTrRdPtr = StopEvtTrWrAt; \
        _intr_restore(intr_status); \
    } \
}

//Use this for time stamping (marking) in event FIFO when particular place in the code is reached
#define EVENT_TRACE_MARKER(n) \
{ \
    byte Id = n; \
}

//externs
extern void DumpEvtTrace();
extern EC_GLOBAL_S5INIT_BSS int StopEvtTrWrAt;
extern EC_GLOBAL_S5INIT_BSS dword EvtTrTimeBase;
extern EC_GLOBAL_S5INIT_BSS byte EvtTrNestLev, PrevEvtTrNestLev;
extern EC_GLOBAL_S5INIT_BSS int EvtTrRdPtr, EvtTrWrPtr;

#else //!DEBUG_EVENT_TRACE

#  define EVENT_TRACE_RST_TIME()
#  define EVENT_TRACE_RST_NLEV()
#  define EVENT_TRACE_TRIGGER()
#  define EVENT_TRACE_MARKER(n)

#endif //DEBUG_EVENT_TRACE


#   if defined(SCOPE_TRIGGER)
extern void scope_trigger(int stop);
extern void scope_untrigger();
#   endif

#   if DEBUG_CONFIG
extern void ec_dump();
#   endif

// support displaying EC debug output on the HOST UART through mailbox commands
#define ENABLE_DEBUG_REPLAY 0

// Set OUTDEV_DEBUG for high speed UART debug
#if (OUTDEV_DEBUG & OUTDEV_UART_HS)
#   undef OUTDEV_DEBUG
#   define OUTDEV_DEBUG (OUTDEV_UART | OUTDEV_UART_HS)
#endif

extern dword _fsrvflag[], _esrvflag[];
extern void dprintf_task_name();
extern void dprintf(const char *fmt, ...);
extern void dprintf_decimal (const char *prefix, word val, const char *suffix);
extern void dprintf_replay_mbox (int index);
extern void dprintf_replay_start ();
extern void debug_init();
extern void debug_enable_state();
extern void HandleDebugEcSleep(void *Context);
extern void ShowTod (const char *msg);
extern void ShowVersion (void);

#endif  // __DEBUG_H__
