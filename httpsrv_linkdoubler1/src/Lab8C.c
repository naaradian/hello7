//
//      Lab8C : TMS320F2812  Teaching CD ROM
//      (C) Frank Bormann
//
//###########################################################################
//
// FILE:	Lab8C.c
//
// TITLE:	DSP28 SCI - Communication to Windows - Hyperterminal
//			DSP waits to receive "Texas" from the PC and answers by
//			transmitting the string " Instruments" back to the PC	
//			Setup : 9600 Baud, 8 Bit , No Parity , 1 Stopbit	
//			SCI-TX INT to serve empty TX buffer
//	        SCI TX FIFO to fill in up to 16 characters
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  2.0 | 11 Nov 2003 | F.B. | adapted to header-files Version 1.00  
//###########################################################################

#include "DSP281x_Device.h"

// Prototype statements for functions found within this file.

void Gpio_select(void);
void SpeedUpRevA(void);
void InitSystem(void);  
void SCI_Init(void);  
interrupt void SCI_TX_isr(void); 
interrupt void SCI_RX_isr(void);

// Global Variables
char message[]={" Instruments\n\r"};
  
 
void main(void)
{
	InitSystem();		// Initialize the DSP's core Registers
	
	// Speed_up the silicon A Revision. 
	// No need to call this function for Rev. C  later silicon versions
	SpeedUpRevA();
	
	Gpio_select();		// Setup the GPIO Multiplex Registers
    
    InitPieCtrl();		// Function Call to init PIE-unit ( code : DSP281x_PieCtrl.c)
	
	InitPieVectTable(); // Function call to init PIE vector table ( code : DSP281x_PieVect.c )
	
    EALLOW;	// This is needed to write to EALLOW protected registers
	PieVectTable.TXAINT = &SCI_TX_isr; 
	PieVectTable.RXAINT = &SCI_RX_isr;
	EDIS;       // This is needed to disable write to EALLOW protected registers

    // Enable SCI_A_TX_INT in PIE
    PieCtrlRegs.PIEIER9.bit.INTx2 = 1;  
    // Enable SCI_A_RX_INT in PIE  
    PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
    
    // Enable CPU INT 9
    IER |= 0x100;	    
    
    // Enable global Interrupts and higher priority real-time debug events:
   	EINT;   // Enable Global interrupt INTM
   	ERTM;   // Enable Global realtime interrupt DBGM
   	
   	SCI_Init();
	while(1)
	{
		EALLOW;
		SysCtrlRegs.WDKEY = 0x55;		// Serve watchdog #1
	    SysCtrlRegs.WDKEY = 0xAA;		// Serce watchdog #2
		EDIS;
	}
} 	


void Gpio_select(void)
{
	EALLOW;
	GpioMuxRegs.GPAMUX.all = 0x0;	// all GPIO port Pin's to I/O
    GpioMuxRegs.GPBMUX.all = 0x0;   
    GpioMuxRegs.GPDMUX.all = 0x0;
    GpioMuxRegs.GPFMUX.all = 0x0;		 
    GpioMuxRegs.GPFMUX.bit.SCIRXDA_GPIOF5 = 1; //SCI-RX
    GpioMuxRegs.GPFMUX.bit.SCITXDA_GPIOF4 = 1; //SCI-TX 
    GpioMuxRegs.GPEMUX.all = 0x0; 
    GpioMuxRegs.GPGMUX.all = 0x0;			
										
    GpioMuxRegs.GPADIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPBDIR.all = 0x00FF;	// GPIO Port B15-B8 input , B7-B0 output
    GpioMuxRegs.GPDDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPEDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPFDIR.all = 0x0;	// GPIO PORT  as input
    GpioMuxRegs.GPGDIR.all = 0x0;	// GPIO PORT  as input

    GpioMuxRegs.GPAQUAL.all = 0x0;	// Set GPIO input qualifier values to zero
    GpioMuxRegs.GPBQUAL.all = 0x0;
    GpioMuxRegs.GPDQUAL.all = 0x0;
    GpioMuxRegs.GPEQUAL.all = 0x0;
    EDIS;
}     

void SpeedUpRevA(void)
{
// On TMX samples, to get the best performance of on chip RAM blocks M0/M1/L0/L1/H0 internal
// control registers bit have to be enabled. The bits are in Device emulation registers.
   	EALLOW;
   	DevEmuRegs.M0RAMDFT = 0x0300;
   	DevEmuRegs.M1RAMDFT = 0x0300;
   	DevEmuRegs.L0RAMDFT = 0x0300;
   	DevEmuRegs.L1RAMDFT = 0x0300;
   	DevEmuRegs.H0RAMDFT = 0x0300;
   	EDIS;
}

void InitSystem(void)
{
   	EALLOW;
   	SysCtrlRegs.WDCR= 0x00AF;		// Setup the watchdog 
   									// 0x00E8  to disable the Watchdog , Prescaler = 1
   									// 0x00AF  to NOT disable the Watchdog, Prescaler = 64
   	SysCtrlRegs.SCSR = 0; 			// Watchdog generates a RESET	
   	SysCtrlRegs.PLLCR.bit.DIV = 10;	// Setup the Clock PLL to multiply by 5
    
   	SysCtrlRegs.HISPCP.all = 0x1; // Setup Highspeed Clock Prescaler to divide by 2
   	SysCtrlRegs.LOSPCP.all = 0x2; // Setup Lowspeed CLock Prescaler to divide by 4
      	
   	// Peripheral clock enables set for the selected peripherals.   
   	SysCtrlRegs.PCLKCR.bit.EVAENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.EVBENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.SCIAENCLK=1;
   	SysCtrlRegs.PCLKCR.bit.SCIBENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.MCBSPENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.SPIENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.ECANENCLK=0;
   	SysCtrlRegs.PCLKCR.bit.ADCENCLK=0;
   	EDIS;
}

void SCI_Init(void)
{
	SciaRegs.SCICCR.all =0x0007;   	// 1 stop bit,  No loopback 
                                   	// No parity,8 char bits,
                                   	// async mode, idle-line protocol
	SciaRegs.SCICTL1.all =0x0003;  	// enable TX, RX, internal SCICLK, 
                                   	// Disable RX ERR, SLEEP, TXWAKE
	SciaRegs.SCIHBAUD = 487 >> 8 ;  // 9600 Baud ; LSPCLK = 37.5MHz
	SciaRegs.SCILBAUD = 487 & 0x00FF;	
	SciaRegs.SCICTL2.bit.TXINTENA = 1;	// Enable SCI-Transmit-interrupt 
	SciaRegs.SCICTL2.bit.RXBKINTENA = 1;  // Enable SCI-A-Receive-interrupt
	SciaRegs.SCIFFTX.all = 0xC060;	// bit 15 = 1 : relinquish from Reset
									// bit 14 = 1 : Enable FIFO Enhancement
									// bit 6 = 1 :  CLR TXFFINT-Flag
									// bit 5 = 1 :  enable TX FIFO match
									// bit 4-0 :  TX-ISR, if TX FIFO is 0
	
	SciaRegs.SCIFFRX.all = 0xE065;	// Rx interrupt level = 5	
	SciaRegs.SCICTL1.all = 0x0023;	// Relinquish SCI from Reset								  
}  

//===========================================================================
// SCI_A Transmit Interrupt Service
// Transmit the characters 2..26 of the string message[] 
//===========================================================================
interrupt void SCI_TX_isr(void)
{
	int i;
	for(i=0;i<16;i++)SciaRegs.SCITXBUF=message[i];	// 16 load operations
	// Reinitialize the PIE for next SCI-A TX-Interrupt
    PieCtrlRegs.PIEACK.all = 0x0100;   // Acknowledge interrupt to PIE
}
     
interrupt void SCI_RX_isr(void)
{
	int i;
	char buffer[16];
	for (i=0;i<16;i++) buffer[i]= SciaRegs.SCIRXBUF.all;
	
	if (strncmp(buffer, "Texas", 5) == 0)
	{
		SciaRegs.SCIFFTX.bit.TXFIFOXRESET =1; 
		SciaRegs.SCIFFTX.bit.TXINTCLR = 1 ;		
	}
	 	
	SciaRegs.SCIFFRX.bit.RXFIFORESET = 0;	// reset FIFO pointer  
	SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;	// enable operation
	SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;    // clear FIFO INT Flag
	PieCtrlRegs.PIEACK.all = 0x0100;   // Acknowledge interrupt to PIE
}
     
//===========================================================================
// End of SourceCode.
//===========================================================================

