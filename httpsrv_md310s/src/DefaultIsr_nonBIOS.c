/**********************************************************************
* File: DefaultIsr_nonBIOS.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
*   03/23/04 - removed redundant PIE acknowlege from CAP1INT_ISR (D. Alter)
**********************************************************************/

#include "DSP281x_Device.h"
#include "Expert.h"
extern Uint32 TimerCounter; //to not use.h file widch classes - for 'C' it not get
extern Uint32 KeyCounter; 
#ifdef EXAMPLE_BIOS
    #include "example_BIOS.h"
#endif

#ifdef EXAMPLE_NONBIOS
    #include "example_nonBIOS.h"
#endif


/*** Global variables used by ADCINT_ISR() ***/
//#define ADC_buf_len	50					// ADC buffer length
#define ADC_buf_len	1					// ADC buffer length
Uint16 ADC_buf[ADC_buf_len];			// ADC buffer allocation

/*** Global variables used by CAPINT1_ISR() ***/
Uint16 CAP_rising = 0;					// Captured rising edge timestamp
Uint16 CAP_falling = 0;					// Captured falling edge timestamp
Uint16 CAP_width = 0;					// PWM pulse width computed using captures
//extern void Tcpipint(void);

/*********************************************************************/
interrupt void INT13_ISR(void)			// 0x000D1A  INT13 - XINT13 (or CPU Timer1, reserved for TI)
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
} // INT13_ISR

/*********************************************************************/
interrupt void INT14_ISR(void)			// 0x000D1C  INT14 - CPU Timer2, reserved for TI
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void DATALOG_ISR(void)		// 0x000D1E  DATALOG - CPU data logging interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void RTOSINT_ISR(void)		// 0x000D20  RTOSINT - CPU RTOS interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void EMUINT_ISR(void) 		// 0x000D22  EMUINT - CPU emulation interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void NMI_ISR(void)			// 0x000D24  NMI - XNMI interrupt
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void ILLEGAL_ISR(void)		// 0x000D26  ILLEGAL - illegal operation trap
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER1_ISR(void)			// 0x000D28  USER1 - software interrupt #1
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER2_ISR(void)			// 0x000D2A  USER2 - software interrupt #2
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER3_ISR(void)			// 0x000D2C  USER3 - software interrupt #3
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER4_ISR(void)			// 0x000D2E  USER4 - software interrupt #4
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER5_ISR(void)			// 0x000D30  USER5 - software interrupt #5
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER6_ISR(void)			// 0x000D32  USER6 - software interrupt #6
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER7_ISR(void)			// 0x000D34  USER7 - software interrupt #7
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER8_ISR(void)			// 0x000D36  USER8 - software interrupt #8
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER9_ISR(void)			// 0x000D38  USER9 - software interrupt #9
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER10_ISR(void)			// 0x000D3A  USER10 - software interrupt #10
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER11_ISR(void)			// 0x000D3C  USER11 - software interrupt #11
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void USER12_ISR(void)			// 0x000D3E  USER12 - software interrupt #12
{
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void PDPINTA_ISR(void)		// 0x000D40  PDPINTA (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
//t	asm (" ESTOP0");					// Emulator Halt instruction
	ExpertRegs.DDRAM = 'A';
//t	while(1);
}

/*********************************************************************/
interrupt void PDPINTB_ISR(void)		// 0x000D42  PDPINTB (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void XINT1_ISR(void)			// 0x000D46  XINT1
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}     

/*********************************************************************/
interrupt void XINT2_ISR(void)			// 0x000D48  XINT2
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	ExpertRegs.DDRAM = 'X';
	while(1);
}

/*********************************************************************/
interrupt void ADCINT_ISR(void)		// 0x000D4A  ADCINT (ADC)
{
static volatile Uint16 GPIOF14_count = 0;		// Counter for pin toggle
static Uint16 *ADC_buf_ptr = ADC_buf;			// Pointer to buffer

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;		// Must acknowledge the PIE group

/*** Manage the ADC registers ***/
	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;			// Reset SEQ1 to CONV00 state
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;			// Clear ADC SEQ1 interrupt flag

/*** Read the ADC result ***/
	*ADC_buf_ptr++ = AdcRegs.ADCRESULT0 >> 4;	// Read the result

/*** Brute-force the circular buffer ***/
	if( ADC_buf_ptr == (ADC_buf + ADC_buf_len) )
		ADC_buf_ptr = ADC_buf;					// Rewind the pointer to beginning

/*** Example: Toggle GPIOF14, which is connected to the LED on the eZdsp board ***/
//	if(GPIOF14_count++ > 12500)					// Toggle slowly to see the LED blink
	if(GPIOF14_count++ > 3)					// Toggle slowly to see the LED blink
	{
		GpioDataRegs.GPFTOGGLE.bit.GPIOF14 = 1;	// Toggle the pin
		GPIOF14_count = 0;						// Reset the counter
//		GpioDataRegs.GPBTOGGLE.all         = 0xffff;		
//		GpioDataRegs.GPBTOGGLE.all         = 0x001c; //for test		
	}
	TimerCounter++;
	if(KeyCounter) KeyCounter--;
//From TCPIP:
//	Tcpipint();
//	CpuTimer0.InterruptCount++;
//	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group
//	CpuTimer0.InterruptCount++;
// Next two lines for debug only - remove after inserting your ISR
//	asm (" ESTOP0");					// Emulator Halt instruction
//	while(1);
//  if (TAIV == 10) 
//	if (1)//to test                             // check for timer overflow, reset int.-flag
//  {
//    ISNGenHigh++;                                // upper 16 bits of initial sequence number
//    TCPTimer++;                                  // timer for retransmissions
//  }	
//From TCPIP	
	
} // end ADCINT_ISR()

/*********************************************************************/
//tinterrupt void TINT0_ISR(void)			// 0x000D4C  TINT0 (CPU TIMER 0)
//t{
//t	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
//t	asm (" ESTOP0");					// Emulator Halt instruction
//t	while(1);
//t}

/*********************************************************************/
interrupt void WAKEINT_ISR(void)		// 0x000D4E  WAKEINT (LPM/WD)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP1INT_ISR(void)		// 0x000D50  CMP1INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP2INT_ISR(void)		// 0x000D52  CMP2INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP3INT_ISR(void)		// 0x000D54  CMP3INT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T1PINT_ISR(void)			// 0x000D56  T1PINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group
  
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T1CINT_ISR(void)			// 0x000D58  T1CINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T1UFINT_ISR(void)		// 0x000D5A  T1UFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T1OFINT_ISR(void)		// 0x000D5C  T1OFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}
      
/*********************************************************************/
interrupt void T2PINT_ISR(void)			// 0x000D60  T2PINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	ExpertRegs.DDRAM = '1';
//t	while(1);
}

/*********************************************************************/
interrupt void T2CINT_ISR(void)			// 0x000D62  T2CINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T2UFINT_ISR(void)		// 0x000D64  T2UFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T2OFINT_ISR(void)		// 0x000D66  T2OFINT (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CAPINT1_ISR(void)		// 0x000D68  CAPINT1 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

/*** Manage the CAP1 registers ***/
	EvaRegs.EVAIFRC.bit.CAP1INT = 1;		// Clear the CAP1INT flag

/*** Read the CAP1FIFO ***/
	CAP_rising = EvaRegs.CAP1FIFO;			// Read the top entry
	CAP_falling = EvaRegs.CAP1FIFO;			// Read the 2nd entry

/*** Compute the duty cycle using signed math ***/
	CAP_width = (Uint16)( (int16)CAP_falling - (int16)CAP_rising );

}

/*********************************************************************/
interrupt void CAPINT2_ISR(void)		// 0x000D6A  CAPINT2 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CAPINT3_ISR(void)		// 0x000D6C  CAPINT3 (EV-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP4INT_ISR(void)		// 0x000D70  CMP4INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP5INT_ISR(void)		// 0x000D72  CMP5INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CMP6INT_ISR(void)		// 0x000D74  CMP6INT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T3PINT_ISR(void)			// 0x000D76  T3PINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T3CINT_ISR(void)			// 0x000D78  T3CINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T3UFINT_ISR(void)		// 0x000D7A  T3UFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T3OFINT_ISR(void)		// 0x000D7C  T3OFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}
     
/*********************************************************************/
interrupt void T4PINT_ISR(void)			// 0x000D80  T4PINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T4CINT_ISR(void)			// 0x000D82  T4CINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group
 
// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T4UFINT_ISR(void)		// 0x000D84  T4UFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void T4OFINT_ISR(void)		// 0x000D86  T4OFINT (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CAPINT4_ISR(void)		// 0x000D88  CAPINT4 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CAPINT5_ISR(void)		// 0x000D8A  CAPINT5 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void CAPINT6_ISR(void)		// 0x000D8C  CAPINT6 (EV-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SPIRXINTA_ISR(void)		// 0x000D90  SPIRXINTA (SPI)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SPITXINTA_ISR(void)		// 0x000D92  SPITXINTA (SPI)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void MRINTA_ISR(void)			// 0x000D98  MRINT (McBSP)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void MXINTA_ISR(void)			// 0x000D9A  MXINT (McBSP)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SCIRXINTA_ISR(void)		// 0x000DC0  SCIRXINTA (SCI-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SCITXINTA_ISR(void)		// 0x000DC2  SCITXINTA (SCI-A)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SCIRXINTB_ISR(void)		// 0x000DC4  SCIRXINTB (SCI-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void SCITXINTB_ISR(void)		// 0x000DC6  SCITXINTB (SCI-B)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void ECAN0INTA_ISR(void)		// 0x000DC8  ECAN0INT (CAN)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void ECAN1INTA_ISR(void)		// 0x000DCA  ECAN1INT (CAN)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	// Must acknowledge the PIE group

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}



/**********************************************************************
* Reserved ISRs
**********************************************************************/

interrupt void PIE_RESERVED(void)		// Reserved PIE base vector.
{
// This ISR is for reserved PIE base vectors.  It should never be reached by
// properly executing code.  If you get here, it means something is wrong.

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}

/*********************************************************************/
interrupt void rsvd_ISR(void)			// Reserved PIE group vector
{
// This ISR is for reserved PIE group vectors.  It should never be reached by
// properly executing code.  If you get here, it means something is wrong.

// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");					// Emulator Halt instruction
	while(1);
}


/*** end of file *****************************************************/
