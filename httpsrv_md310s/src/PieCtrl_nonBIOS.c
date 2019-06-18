/**********************************************************************
* File: PieCtrl_nonBIOS.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
**********************************************************************/

#include "DSP281x_Device.h"

#ifdef EXAMPLE_BIOS
    #include "example_BIOS.h"
#endif

#ifdef EXAMPLE_NONBIOS
    #include "example_nonBIOS.h"
#endif


/**********************************************************************
* Function: InitPieCtrl()
*
* Description: Initializes and enables the PIE interrupts on the F281x.
**********************************************************************/
void InitPieCtrl(void)
{
/*** Disable interrupts ***/
	asm(" SETC INTM, DBGM");			// Disable global interrupts

/*** Initialize the PIE_RAM ***/
	PieCtrlRegs.PIECRTL.bit.ENPIE = 0;	// Disable the PIE
	asm(" EALLOW");						// Enable EALLOW protected register access
	memcpy(&PieVectTable, &PieVectTableInit, 256);
	asm(" EDIS");						// Disable EALLOW protected register access

/*** Disable all PIE interrupts ***/
	PieCtrlRegs.PIEIER1.all =  0x0000;
	PieCtrlRegs.PIEIER2.all =  0x0000;
	PieCtrlRegs.PIEIER3.all =  0x0000;
	PieCtrlRegs.PIEIER4.all =  0x0000;
	PieCtrlRegs.PIEIER5.all =  0x0000;
	PieCtrlRegs.PIEIER6.all =  0x0000;
	PieCtrlRegs.PIEIER7.all =  0x0000;
	PieCtrlRegs.PIEIER8.all =  0x0000;
	PieCtrlRegs.PIEIER9.all =  0x0000;
	PieCtrlRegs.PIEIER10.all = 0x0000;
	PieCtrlRegs.PIEIER11.all = 0x0000;
	PieCtrlRegs.PIEIER12.all = 0x0000;

/*** Clear any potentially pending PIEIFR flags ***/
	PieCtrlRegs.PIEIFR1.all  = 0x0000;
	PieCtrlRegs.PIEIFR2.all  = 0x0000;
	PieCtrlRegs.PIEIFR3.all  = 0x0000;	
	PieCtrlRegs.PIEIFR4.all  = 0x0000;
	PieCtrlRegs.PIEIFR5.all  = 0x0000;
	PieCtrlRegs.PIEIFR6.all  = 0x0000;
	PieCtrlRegs.PIEIFR7.all  = 0x0000;
	PieCtrlRegs.PIEIFR8.all  = 0x0000;
	PieCtrlRegs.PIEIFR9.all  = 0x0000;
	PieCtrlRegs.PIEIFR10.all = 0x0000;
	PieCtrlRegs.PIEIFR11.all = 0x0000;
	PieCtrlRegs.PIEIFR12.all = 0x0000;

/*** Acknowlege all PIE interrupt groups ***/
	PieCtrlRegs.PIEACK.all = 0xFFFF;

/*** Enable the PIE ***/
	PieCtrlRegs.PIECRTL.bit.ENPIE = 1;		// Enable the PIE

} //end of InitPieCtrl()


/*** end of file *****************************************************/
