/**********************************************************************
* File: SysCtrl.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
*   03/18/04 - added PLL lock delay loop (D. Alter)
**********************************************************************/

#include "DSP281x_Device.h"

// EXAMPLE_BIOS or EXAMPLE_NONBIOS are defined in the CCS project build options
#ifdef EXAMPLE_BIOS
    #include "example_BIOS.h"
#endif

#ifdef EXAMPLE_NONBIOS
    #include "example_nonBIOS.h"
#endif


/**********************************************************************
* Function: InitSysCtrl()
*
* Description: Initializes the F281x CPU.
**********************************************************************/
void InitSysCtrl(void)
{
volatile Uint16 i;					// General purpose Uint16
volatile int16 dummy;					// General purpose volatile int16

	asm(" EALLOW");						// Enable EALLOW protected register access

/*** Memory Protection Configuration ***/
	DevEmuRegs.PROTSTART = 0x0100;		// Write default value to protection start register
	DevEmuRegs.PROTRANGE = 0x00FF;		// Write default value to protection range register

/*** Unlock the Code Security Module if CSM not in use ***/
/* Unlocking the CSM will allow code running from non-secure memory
   to access code and data in secure memory.  One would only want to
   unsecure the CSM if code security were not desired, and therefore
   the CSM is not in use (otherwise, unlocking the CSM will compromise
   the security of user code).  If the CSM is not in use, the best
   thing to do is leave the password locations programmed to 0xFFFF,
   which is the flash ERASED state.  When all passwords are 0xFFFF,
   all that is required to unlock the CSM are dummy reads of the
   PWL locations.
*/
	dummy = CsmPwl.PSWD0;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD1;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD2;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD3;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD4;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD5;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD6;				// Dummy read of PWL locations
	dummy = CsmPwl.PSWD7;				// Dummy read of PWL locations

/*** Disable the Watchdog Timer ***/
	SysCtrlRegs.WDCR = 0x00E8;
/*
 bit 15-8      0's:    reserved
 bit 7         1:      WDFLAG, write 1 to clear
 bit 6         1:      WDDIS, 1=disable WD
 bit 5-3       101:    WDCHK, WD check bits, always write as 101b
 bit 2-0       000:    WDPS, WD prescale bits, 000: WDCLK=OSCCLK/512/1
*/

/* System and Control Register */
	SysCtrlRegs.SCSR = 0x0002;
/*
 bit 15-3      0's:    reserved
 bit 2         0:      WDINTS, WD interrupt status bit (read-only)
 bit 1         1:      WDENINT, 0=WD causes reset, 1=WD causes WDINT
 bit 0         0:      WDOVERRIDE, write 1 to disable disabling of the WD (clear-only)
*/

/*** Configure the PLL ***/
/* Note: The DSP/BIOS configuration tool can also be used to intialize the PLL
   instead of doing the initialization here.
*/
	SysCtrlRegs.PLLCR.all = 0x000A;			// PLLx5

/* Optionally wait at least 2^17 = 131072 cycles for the PLL to lock.  Prior to lock,
   the CPU runs off CLKIN.
*/
	for(i=0; i<510; i++) asm(" RPT #255 || NOP");

/*** Configure the clocks ***/
	SysCtrlRegs.HISPCP.all = 0x0000;		// Hi-speed periph clock prescaler, HSPCLK=SYSCLKOUT/1
	SysCtrlRegs.LOSPCP.all = 0x0002;		// Lo-speed periph clock prescaler, LOSPCLK=SYSCLKOUT/4

	SysCtrlRegs.PCLKCR.bit.ECANENCLK = 1;	// SYSCLK to CAN enabled
	SysCtrlRegs.PCLKCR.bit.MCBSPENCLK = 1;	// LSPCLK to McBSP enabled
	SysCtrlRegs.PCLKCR.bit.SCIBENCLK = 1;	// LSPCLK to SCIB enabled
	SysCtrlRegs.PCLKCR.bit.SCIAENCLK = 1;	// LSPCLK to SCIA enabled
	SysCtrlRegs.PCLKCR.bit.SPIENCLK = 1;	// LSPCLK to SPI enabled
	SysCtrlRegs.PCLKCR.bit.ADCENCLK = 1;	// HSPCLK to ADC enabled
	SysCtrlRegs.PCLKCR.bit.EVBENCLK = 1;	// HSPCLK to EVB enabled
	SysCtrlRegs.PCLKCR.bit.EVAENCLK = 1;	// HSPCLK to EVA enabled

/*** Configure the low-power modes ***/
	SysCtrlRegs.LPMCR0.all = 0x00FC;		// LPMCR0 set to default value
	SysCtrlRegs.LPMCR1.all = 0x0000;		// LPMCR1 set to default value

/*** Finish up ***/
	asm(" EDIS");						// Disable EALLOW protected register access

} //end InitSysCtrl()


/**********************************************************************
* Function: InitFlash()
* Description: Initializes the F281x flash timing registers.
* Notes:
*  1) This function MUST be executed out of RAM.  Executing it out of
*     OTP/FLASH will produce unpredictable results.
*  2) The flash registers are code security module protected.  Therefore,
*     you must either run this function from L0/L1 RAM, or you must
*     first unlock the CSM.  Note that unlocking the CSM as part of
*     the program flow can compromise the code security.
*  3) Final flash characterization needs to be performed by TI.  The
*     below settings may not meet final specifications, and are for
*     example purposes only.  Check the latest device datasheet for 
*     TMS qualified specifications.
**********************************************************************/
#pragma CODE_SECTION(InitFlash, "secureRamFuncs")
void InitFlash(void)
{
	asm(" EALLOW");									// Enable EALLOW protected register access
	FlashRegs.FPWR.bit.PWR = 3;						// Pump and bank set to active mode
	FlashRegs.FSTATUS.bit.V3STAT = 1;				// Clear the 3VSTAT bit
	FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;	// Sleep to standby transition cycles
	FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;	// Standby to active transition cycles
	FlashRegs.FBANKWAIT.bit.RANDWAIT = 5;			// Random access waitstates
	FlashRegs.FBANKWAIT.bit.PAGEWAIT = 5;			// Paged access waitstates
	FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;				// Random access waitstates
	FlashRegs.FOPT.bit.ENPIPE = 1;					// Enable the flash pipeline
	asm(" EDIS");									// Disable EALLOW protected register access

/*** Force a complete pipeline flush to ensure that the write to the last register
     configured occurs before returning.  Safest thing is to wait 8 full cycles. ***/

    asm(" RPT #6 || NOP");

} //end of InitFlash()

/*** end of file *****************************************************/
