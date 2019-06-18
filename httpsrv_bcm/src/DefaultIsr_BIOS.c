/**********************************************************************
* File: DefaultIsr_BIOS.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
**********************************************************************/

#include "DSP281x_Device.h"

// EXAMPLE_BIOS or EXAMPLE_NONBIOS are defined in the CCS project build options
#ifdef EXAMPLE_BIOS
    #include "example_BIOS.h"
#endif

#ifdef EXAMPLE_NONBIOS
    #include "example_nonBIOS.h"
#endif


/*** Global variables used by CAPINT1_ISR() ***/
Uint16 CAP_rising = 0;					// Captured rising edge timestamp
Uint16 CAP_falling = 0;					// Captured falling edge timestamp
Uint16 CAP_width = 0;					// PWM pulse width computed using captures


/*********************************************************************/
void INT13_ISR(void)					// 0x000D1A  INT13 - XINT13 (or CPU Timer1, reserved for TI)
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
} // INT13_ISR

/*********************************************************************/
void RTOSINT_ISR(void)		// 0x000D20  RTOSINT - CPU RTOS interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void NMI_ISR(void)			// 0x000D24  NMI - XNMI interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void ILLEGAL_ISR(void)		// 0x000D26  ILLEGAL - illegal operation trap
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER1_ISR(void)			// 0x000D28  USER0 - software interrupt #0
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER2_ISR(void)			// 0x000D2A  USER1 - software interrupt #1
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER3_ISR(void)			// 0x000D2C  USER2 - software interrupt #3
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER4_ISR(void)			// 0x000D2E  USER3 - software interrupt #3
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER5_ISR(void)			// 0x000D30  USER4 - software interrupt #4
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER6_ISR(void)			// 0x000D32  USER5 - software interrupt #5
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER7_ISR(void)			// 0x000D34  USER6 - software interrupt #6
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER8_ISR(void)			// 0x000D36  USER7 - software interrupt #7
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER9_ISR(void)			// 0x000D38  USER8 - software interrupt #8
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER10_ISR(void)			// 0x000D3A  USER9 - software interrupt #9
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER11_ISR(void)			// 0x000D3C  USER10 - software interrupt #10
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void USER12_ISR(void)			// 0x000D3E  USER11 - software interrupt #11
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void PDPINTA_ISR(void)		// 0x000D40  PDPINTA (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void PDPINTB_ISR(void)		// 0x000D42  PDPINTB (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void XINT1_ISR(void)			// 0x000D46  XINT1
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}     

/*********************************************************************/
void XINT2_ISR(void)			// 0x000D48  XINT2
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void ADCINT_ISR(void)			// 0x000D4A  ADCINT (ADC)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;		// Must acknowledge the PIE group

	SWI_post(&ADC_swi);					// post a SWI

} // end ADCINT_ISR()

/*********************************************************************/
void TINT0_ISR(void)			// 0x000D4C  TINT0 (CPU TIMER 0)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void WAKEINT_ISR(void)		// 0x000D4E  WAKEINT (LPM/WD)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP1INT_ISR(void)		// 0x000D50  CMP1INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP2INT_ISR(void)		// 0x000D52  CMP2INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP3INT_ISR(void)		// 0x000D54  CMP3INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T1PINT_ISR(void)			// 0x000D56  T1PINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T1CINT_ISR(void)			// 0x000D58  T1CINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T1UFINT_ISR(void)		// 0x000D5A  T1UFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T1OFINT_ISR(void)		// 0x000D5C  T1OFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}
      
/*********************************************************************/
void T2PINT_ISR(void)			// 0x000D60  T2PINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T2CINT_ISR(void)			// 0x000D62  T2CINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T2UFINT_ISR(void)		// 0x000D64  T2UFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T2OFINT_ISR(void)		// 0x000D66  T2OFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CAPINT1_ISR(void)		// 0x000D68  CAPINT1 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

/*** Manage the CAP1 registers ***/
	EvaRegs.EVAIFRC.bit.CAP1INT = 1;		// Clear the CAP1INT flag

/*** Read the CAP1FIFO ***/
	CAP_rising = EvaRegs.CAP1FIFO;			// Read the top entry
	CAP_falling = EvaRegs.CAP1FIFO;			// Read the 2nd entry

/*** Compute the pulse width cycle using signed math ***/
	CAP_width = (Uint16)( (int16)CAP_falling - (int16)CAP_rising );

}

/*********************************************************************/
void CAPINT2_ISR(void)		// 0x000D6A  CAPINT2 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CAPINT3_ISR(void)		// 0x000D6C  CAPINT3 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP4INT_ISR(void)		// 0x000D70  CMP4INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP5INT_ISR(void)		// 0x000D72  CMP5INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CMP6INT_ISR(void)		// 0x000D74  CMP6INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T3PINT_ISR(void)			// 0x000D76  T3PINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T3CINT_ISR(void)			// 0x000D78  T3CINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T3UFINT_ISR(void)		// 0x000D7A  T3UFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T3OFINT_ISR(void)		// 0x000D7C  T3OFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}
     
/*********************************************************************/
void T4PINT_ISR(void)			// 0x000D80  T4PINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T4CINT_ISR(void)			// 0x000D82  T4CINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group
 
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T4UFINT_ISR(void)		// 0x000D84  T4UFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void T4OFINT_ISR(void)		// 0x000D86  T4OFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CAPINT4_ISR(void)		// 0x000D88  CAPINT4 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CAPINT5_ISR(void)		// 0x000D8A  CAPINT5 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void CAPINT6_ISR(void)		// 0x000D8C  CAPINT6 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SPIRXINTA_ISR(void)		// 0x000D90  SPIRXINTA (SPI)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SPITXINTA_ISR(void)		// 0x000D92  SPITXINTA (SPI)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void MRINTA_ISR(void)			// 0x000D98  MRINT (McBSP)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void MXINTA_ISR(void)			// 0x000D9A  MXINT (McBSP)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SCIRXINTA_ISR(void)		// 0x000DC0  SCIRXINTA (SCI-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SCITXINTA_ISR(void)		// 0x000DC2  SCITXINTA (SCI-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SCIRXINTB_ISR(void)		// 0x000DC4  SCIRXINTB (SCI-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void SCITXINTB_ISR(void)		// 0x000DC6  SCITXINTB (SCI-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void ECAN0INTA_ISR(void)		// 0x000DC8  ECAN0INT (CAN)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
void ECAN1INTA_ISR(void)		// 0x000DCA  ECAN1INT (CAN)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}



/**********************************************************************
* Reserved ISRs
**********************************************************************/
void rsvd_ISR(void)			// Reserved vector
{
// This ISR is for reserved vectors.  It should never be reached by
// properly executing code.  If you get here, it means something is wrong.

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}


/*** end of file *****************************************************/
