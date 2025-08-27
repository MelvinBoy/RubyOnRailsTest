// <~> --------------------------------------------------------------------------------
//   Dell confidential, proprietary information covered under NDA/SLA agreements
//   (c) Copyright 2022 Dell Inc. No source code distribution allowed without prior consent from Dell
// <~> --------------------------------------------------------------------------------

#include "Ec.h"
#include "UPD.h"
#include "PowerSource.h"
#if ENABLE_UPD_FLASH_LESS
#include "SysUsbPDPriv.h"
#include "SysMac.h"
#include "BoardId.h"
#endif

extern EC_GLOBAL_NOINIT UPD_PortStateTp UPD_PortStateTPS[SYS_MAX_UPD_TPS65994_PORTS];

//List of the Type-C port and the GPIO's that EC needs to assert in order to route
//Power from that port to the charger. Last entry, the terminator should always be 0
const power_source_switch power_source[]=
{
    {SMB_USBPD1,            0, 20, 0, 0, 20, 20, SysPort0PowerSourceHandler},
    {SMB_USBPD2,            0, 20, 0, 0, 20, 20, SysPort1PowerSourceHandler},
    {0, 0, 0, 0, 0}
};

const UpdPowerPolicyContext UPD_PowerPolicy_TBT[SYS_MAX_UPD_PORTS]=
{
    {1,UPD_CURRENT_3A,&UPD_PortStateTPS[1],UPD_CURRENT_1p5A},
    {1,UPD_CURRENT_3A,&UPD_PortStateTPS[0],UPD_CURRENT_1p5A}
};

const UpdPowerPolicyContext UPD_PowerPolicy_NonTBT[SYS_MAX_UPD_PORTS]=
{
    {0,UPD_CURRENT_1p5A,NULL,UPD_CURRENT_1p5A},
    {0,UPD_CURRENT_1p5A,NULL,UPD_CURRENT_1p5A}
};

const UpdPowerPolicyContext * SysUpdPwrPolicy(byte port_index,UPD_PortControllerTp ctrl)
{
    return &UPD_PowerPolicy_TBT[port_index];
}

// This table is the most important portion to make UPD related tasks work
const UPD_PortMapTp UPD_PORT_MAP[SYS_MAX_UPD_PORTS]=
{
    {UPD_PORT_CONTROLLER_TPS65994, UPD_Controller_0, Controller_Port_0, System_Port_0_IRQ, System_Port_0_SrcBit, SMB_USBPD1, SMBD_USBPD1},
    {UPD_PORT_CONTROLLER_TPS65994, UPD_Controller_1, Controller_Port_0, System_Port_1_IRQ, System_Port_1_SrcBit, SMB_USBPD2, SMBD_USBPD2}
};

void SysUPDIntEnable(int which)
{
    xDPRINTF (DEBUG_UPD, ("SysUPDIntEnable(%d)\n", which));
    switch(which)
    {
        case 0:
            nUPD1_SMBINT_Enable();
            break;
        case 1:
            nUPD2_SMBINT_Enable();
            break;
    }
}

void SysUPDIntDisable(int which)
{
    xDPRINTF (DEBUG_UPD, ("SysUPDIntDisable(%d)\n", which));

    switch(which)
    {
        case 0:
            nUPD1_SMBINT_Disable();
            break;
        case 1:
            nUPD2_SMBINT_Disable();
            break;
    }
}
byte SysUPDIntPinActive(byte PortIndex)
{
    byte result = 1;
    switch(PortIndex)
    {
        case 0:
            if(GPIO_RD(nUPD1_SMBINT))
                result = 0;
            break;
        case 1:
            if(GPIO_RD(nUPD2_SMBINT))
                result = 0;
            break;
        default:
            result = 0;
            DPRINTF (DEBUG_UPD, ("PortIndex error during UDP int check"));
            break;
    }
    DPRINTF (DEBUG_UPD, ("SysUPDIntPinActive - UPD PORT0_INT = %x  PORT1_INT = %x\n", GPIO_RD(nUPD1_SMBINT), GPIO_RD(nUPD2_SMBINT)));
    return result;
}

void SysHandleUsbPdInt(byte TaskPortIndex)
{
    if (TaskPortIndex == 0)
    {
        SysUPDIntDisable(0);
        while(SysUPDIntPinActive(TaskPortIndex))
        {
            UPD_PORT_DATA[0].PortControllerPtr->UPD_HandlePortInt(0);
        }
        SysUPDIntEnable(0);
    }
    else if(TaskPortIndex == 1)
    {
        SysUPDIntDisable(1);
        while(SysUPDIntPinActive(TaskPortIndex))
        {
            UPD_PORT_DATA[1].PortControllerPtr->UPD_HandlePortInt(1);
        }
        SysUPDIntEnable(1);
    }
}

int  SysUPD_GetPatch (const uint8_t **  Patch, int *  Size, byte* SysPatchVersion)
{
#if ENABLE_UPD_FLASH_LESS
    // Currently all ports are patched using the same binary data
    *Patch = SysUPD_Patch_Data;
    *Size  = sizeof (SysUPD_Patch_Data);

    SysPatchVersion[3] = (byte) ((SysUPD_Patch_Data_Version & 0xFF000000) >> 24);
    SysPatchVersion[2] = (byte) ((SysUPD_Patch_Data_Version & 0x00FF0000) >> 16);
    SysPatchVersion[1] = (byte) ((SysUPD_Patch_Data_Version & 0x0000FF00) >> 8);
    SysPatchVersion[0] = (byte) (SysUPD_Patch_Data_Version & 0x000000FF);
     return 0;
#else
    return -1;
#endif
}

#if ENABLE_UCSI
const SystemCapabilityConfig_Tp SystemCapabilityConfig =
{
    (Usb_Power_Delivery |
     Usb_TypeC_Current |
     bmPowerSource_AC_Supply|
     bmPowerSource_Battery),

    (Alternate_mode_details_supported |
     PDO_details_supported),

    SYS_MODE_NUM,      // bNumAltModes
    0x0,    // bcdBCVersion, supports BC 1.2
    0x300,  // bcdPDVersion, supports PD 3.0
    0x120,  // bcdUSBTypeCVersion, supports Type C spec is 1.2
};
#endif

const DeviceConfig_Tp DeviceConfig[SYS_MAX_UPD_PORTS] =
{
    {
        //PlatformModesMask
        (CUSTOM_MODE_DELL_DOCKING |
         DATA_MODE_TBT |
         DATA_MODE_DP |
         DATA_MODE_USB4 |
         DATA_MODE_USB3 |
         DATA_MODE_USB2),

#if ENABLE_UCSI
        //Operation_Mode
        (Supports_DFP_Only |
         Supports_USB_2 |
         Supports_USB_3 |
         Supports_Alternate_Mode |
         Supports_Provider |
         Supports_Consumer |
         Supports_Swap_to_DFP |
         Supports_Swap_to_SRC |
         Supports_Swap_to_SNK),
#endif

        //GPIOs
        0x00000000, //GPIOs: 0, 1, 2, 5, 6, 12, 13 (7, 8 disabled to not mess-up the boards)
        0x0,        //GPIO0
        0x0,        //1 //GPIO1
        0x0,        //2 //GPIO2
        0x0,        //GPIO3
        0x0,        //GPIO4
        0x0,        //GPIO5
        0x0,        //GPIO6
        0x0,        //GPIO7
        0x0,        //GPIO8
        0x0,        //GPIO9
        0x0,        //GPIO10
        0x0,        //GPIO11
        0x0,        //GPIO12
    },
    {
        //PlatformModesMask
        (CUSTOM_MODE_DELL_DOCKING |
         DATA_MODE_TBT |
         DATA_MODE_DP |
         DATA_MODE_USB4 |
         DATA_MODE_USB3 |
         DATA_MODE_USB2),

#if ENABLE_UCSI
        //Operation_Mode
        (Supports_DFP_Only |
         Supports_USB_2 |
         Supports_USB_3 |
         Supports_Alternate_Mode |
         Supports_Provider |
         Supports_Consumer |
         Supports_Swap_to_DFP |
         Supports_Swap_to_SRC |
         Supports_Swap_to_SNK),
#endif

        //GPIOs
        0x00000000, //GPIOs: 0, 1, 2, 5, 6, 12, 13 (7, 8 disabled to not mess-up the boards)
        0x0,        //GPIO0
        0x0,        //1 //GPIO1
        0x0,        //2 //GPIO2
        0x0,        //GPIO3
        0x0,        //GPIO4
        0x0,        //GPIO5
        0x0,        //GPIO6
        0x0,        //GPIO7
        0x0,        //GPIO8
        0x0,        //GPIO9
        0x0,        //GPIO10
        0x0,        //GPIO11
        0x0,        //GPIO12
    },
};

word SysUPDGetSupportedModes(byte PortIndex)
{
    word modes = DeviceConfig[PortIndex].PlatformModesMask;
    return modes;
}

// This was added to map the PD to SPI location.
byte UPD_GetHeadLocalPortRealIndex(byte instance, UPD_PortControllerTp ctrl)
{
    return instance;
}

byte SysPort0PowerSourceHandler(void *Context)
{
    int State = *(int*)Context;
    byte PortIndex = 0;
    if(State == ON)
    {
        Request_EnablePortProchot(&PortIndex);
    }
    else if(State == OFF)
    {
        Request_DisablePortProchot(&PortIndex);
    }

    return 0;
}

byte SysPort1PowerSourceHandler(void *Context)
{
    int State = *(int*)Context;
    byte PortIndex = 1;
    if(State == ON)
    {
        Request_EnablePortProchot(&PortIndex);
    }
    else if(State == OFF)
    {
        Request_DisablePortProchot(&PortIndex);
    }

    return 0;
}
