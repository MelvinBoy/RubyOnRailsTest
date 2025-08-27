// <~> --------------------------------------------------------------------------------
//   Dell confidential, proprietary information covered under NDA/SLA agreements
//   (c) Copyright 2000-2030 Dell Inc. No source code distribution allowed without prior consent from Dell
// <~> --------------------------------------------------------------------------------
#ifndef _PS2_H_
#define _PS2_H_

union XDev
{
    struct
    {
        unsigned char _XDinh:1;
        // device is turned off.  used to:
        //      turn off touchpad (CHC) when external mouse is present.
        //      control when internal keyboard scanning is done.
        unsigned char _XDoff:1;
        unsigned char _XDrecv:1;
        unsigned char _XDkeyboard:1;
        unsigned char _XDmouse:1;
        // *this* mouse is the active one
        unsigned char _XDactive:1;
        // another mouse is active; ignore this one
        unsigned char _XDignore:1;
        // unused
        unsigned char _bit7:1;
    } BITS;

#               define XDinh BITS._XDinh
#               define XDoff BITS._XDoff
#               define XDrecv BITS._XDrecv
#               define XDkeyboard BITS._XDkeyboard
#               define XDmouse BITS._XDmouse
#               define XDactive BITS._XDactive
#               define XDignore BITS._XDignore
    byte BYTE;
};

typedef union PS2_STATUS
{
    struct
    {
        uint8_t RDATA_RDY:1;
        uint8_t RECV_TIMEOUT:1;
        uint8_t PE:1;
        uint8_t FE:1;
        uint8_t XMIT_IDLE:1;
        uint8_t XMIT_TIMEOUT:1;
        uint8_t RX_BUSY:1;
    } BITS;
    uint8_t BYTE;
} PS2_STAT_T;

#define PS2keyboard     BIT3
#define PS2mouse        BIT4

#define KBD_SIZE        64
#define MSE_SIZE        8

//How long before mouse is considered idle without any activity
#define MOUSE_IDLE_TIME 200

#define PS2_CONTROL_LOCK        0x40 /* 0100 0000 */
#define PS2_CONTROL_RECV        0x22 /* 0010 0010 */
#define PS2_CONTROL_SEND        0x03 /* 0000 0011 */
#define PS2_CONTROL_UNLOCK      PS2_CONTROL_RECV

#define stateCHA (Ps2DevState[0])
#if (NUM_PS2_CHANNELS > 1)
#define stateCHB (Ps2DevState[1])
#endif
#if (NUM_PS2_CHANNELS > 2)
#define stateCHC (Ps2DevState[2])
#endif

extern void HandlePs2Mbox();
extern void HandlePs2Ch0Service();
extern void HandlePs2Ch1Service();
extern void HandlePs2Ch2Service();
extern void HandlePs2Ch0Intr();
extern void HandlePs2Ch1Intr();
extern void HandlePs2Ch2Intr();
extern void IdleMouseHandler();
extern void SysWakeOnPs2();

extern void CCB42_SYNC();
extern bit KBD_CMD (int cmd, int len);
extern bit KBD_CMD2 (int cmd, int arg, int len);
extern void UNLOCK_PS2();
extern void PS2_LOCK_CH(int dev);
extern void PS2_UNLOCK_CH(int dev);
extern void PS2_CLEAR_STATUS(int dev);
extern PS2_STAT_T PS2_READ_STATUS(int dev);
extern void CH_LOCK (int dev);
extern EC_GLOBAL_S5INIT_BSS byte ch_input;
extern bit CHA_RECV(int ms);
extern bit CHB_RECV(int ms);
extern bit CHC_RECV(int ms);
extern int CH_RECEIVE (int dev);
extern int PS2_CH_RECEIVE(int dev);
extern void PS2_CH_SEND (int dev, uint8_t data);
extern void PS2_ENTER_S5(void);
extern void PS2_INIT(void);
extern bool PS2_IS_BUSY(void) ;
extern void PS2_HANDLE_RECV_TIMEOUT(int dev);
extern bit CHA_SEND(int cmd);
extern bit CHB_SEND(int cmd);
extern bit CHC_SEND(int cmd);
extern void KEYBOARD_LINE_TEST();
extern void MOUSE_LINE_TEST();
extern EC_GLOBAL_S5INIT_BSS byte RECONFIG_FROM_DOCK;
extern EC_GLOBAL_S5INIT_BSS byte RECONFIG_DONE;
extern EC_GLOBAL_S5INIT_BSS byte reconfig_block;
extern EC_GLOBAL_S5INIT_BSS byte SEC_flag;
extern void reconfig();
extern void reconfig_check();
extern void ps2_init();
extern void Ps2InitS5();
extern void Ps2AbortEcSleep(void *context);


# if NUM_PS2_CHANNELS
#include "Ps2.h" // taking this out creates build error due to missing XDev
extern EC_GLOBAL_S5INIT_BSS byte PRIVATE_MSE_CMD;
extern EC_GLOBAL_S5INIT_BSS byte PS2_EXCLUSIVE;
extern EC_GLOBAL_S5INIT_BSS union XDev Ps2DevState[NUM_PS2_CHANNELS];
extern EC_GLOBAL_S5INIT_BSS union XDev stateUSB;
extern bit MSE_CMD (int cmd, int len);
extern bit MSE_CMD2 (int cmd, int arg, int len);
extern struct PS2_REGISTERS *ps2_CH (int dev);
extern union XDev *state_CH (int dev);
extern void HANDLE_CH(int dev);
extern void HANDLE_UNLOCK (void);
# endif

#endif // _PS2_H_
