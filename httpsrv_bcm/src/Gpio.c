/**********************************************************************
* File: Gpio.c
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


/**********************************************************************
* Function: InitGpio()
*
* Description: Initializes the shared GPIO pins on the F281x.
**********************************************************************/
void InitGpio(void)
{
	asm(" EALLOW");						// Enable EALLOW protected register access

/*** Group A pins ***/
	GpioMuxRegs.GPAQUAL.all=0x0000;					// Input qualifier disabled
	GpioMuxRegs.GPADIR.all = 0x0000;				// All group A GPIO are inputs

	GpioMuxRegs.GPAMUX.bit.C3TRIP_GPIOA15  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.C2TRIP_GPIOA14  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.C1TRIP_GPIOA13  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.TCLKINA_GPIOA12 = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.TDIRA_GPIOA11   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.CAP3QI1_GPIOA10 = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.CAP2Q2_GPIOA9   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.CAP1Q1_GPIOA8   = 1;		// 1: select periph function
	GpioMuxRegs.GPAMUX.bit.T2PWM_GPIOA7    = 0;		// 0: select GPIO function
//	GpioMuxRegs.GPAMUX.bit.T1PWM_GPIOA6    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.T1PWM_GPIOA6    = 1;		// 1: select periph function
	GpioMuxRegs.GPAMUX.bit.PWM6_GPIOA5     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.PWM5_GPIOA4     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.PWM4_GPIOA3     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.PWM3_GPIOA2     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.PWM2_GPIOA1     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPAMUX.bit.PWM1_GPIOA0     = 1;		// 1: select periph function

	GpioMuxRegs.GPADIR.all 				   = 0x0020; // 1: GPIOa5 get to m2
	GpioDataRegs.GPASET.all                = 0x0020; //line to one
/*** Group B pins ***/
	GpioMuxRegs.GPBQUAL.all = 0x0000;				// Input qualifier disabled
	GpioMuxRegs.GPBDIR.all = 0x0000;				// All group B GPIO are inputs
//	GpioMuxRegs.GPBDIR.all = 0x001C;				// All group B GPIO are inputs

	GpioMuxRegs.GPBMUX.bit.C6TRIP_GPIOB15  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.C5TRIP_GPIOB14  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.C4TRIP_GPIOB13  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.TCLKINB_GPIOB12 = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.TDIRB_GPIOB11   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.CAP6QI2_GPIOB10 = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.CAP5Q2_GPIOB9   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.CAP4Q1_GPIOB8   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.T4PWM_GPIOB7    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.T3PWM_GPIOB6    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.PWM12_GPIOB5    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.PWM11_GPIOB4    = 0;		// 0: select GPIO function on
	GpioMuxRegs.GPBMUX.bit.PWM10_GPIOB3    = 0;		// 0: select GPIO function on
	GpioMuxRegs.GPBMUX.bit.PWM9_GPIOB2     = 0;		// 0: select GPIO function on
	GpioMuxRegs.GPBMUX.bit.PWM8_GPIOB1     = 0;		// 0: select GPIO function
	GpioMuxRegs.GPBMUX.bit.PWM7_GPIOB0     = 0;		// 0: select GPIO function
	
//	GpioMuxRegs.GPBDIR.all 				   = 0xffff;				// 1: GPIOb4 is output (connected to LED on eZdsp)
//	GpioDataRegs.GPBSET.all                = 0xffff;			    // 1: set GPIOB4
//	GpioMuxRegs.GPBDIR.all 				   = 0x001c;				// 1: GPIOb4 is output (connected to LED on eZdsp)
//	GpioDataRegs.GPBSET.all                = 0x001c;	 //set dds lines to one
//	GpioMuxRegs.GPBDIR.all 				   = 0x001f;				// 1: GPIOb4 is output (connected to LED on eZdsp)
	GpioMuxRegs.GPBDIR.all 				   = 0x009f;				// 1: GPIOb7 is output - maked to view delay
	GpioDataRegs.GPBSET.all                = 0x001f; //added lines for interface M0 and M1     
/*** Group D pins ***/
	GpioMuxRegs.GPDQUAL.all=0x0000;					// Input qualifier disabled
	GpioMuxRegs.GPDDIR.all = 0x0000;				// All group D GPIO are inputs


	GpioMuxRegs.GPDMUX.bit.T4CTRIP_SOCB_GPIOD6 = 0;	// 0: select GPIO function
	GpioMuxRegs.GPDMUX.bit.T3CTRIP_PDPB_GPIOD5 = 0;	// 0: select GPIO function
	GpioMuxRegs.GPDMUX.bit.T2CTRIP_SOCA_GPIOD1 = 0;	// 0: select GPIO function
	GpioMuxRegs.GPDMUX.bit.T1CTRIP_PDPA_GPIOD0 = 0;	// 0: select GPIO function

/*** Group E pins ***/
	GpioMuxRegs.GPEQUAL.all=0x0000;					// Input qualifier disabled
	GpioMuxRegs.GPEDIR.all = 0x0000;				// All group E GPIO are inputs

	GpioMuxRegs.GPEMUX.bit.XNMI_XINT13_GPIOE2  = 0;	// 0: select GPIO function
	GpioMuxRegs.GPEMUX.bit.XINT2_ADCSOC_GPIOE1 = 0;	// 0: select GPIO function
	GpioMuxRegs.GPEMUX.bit.XINT1_XBIO_GPIOE0   = 0;	// 0: select GPIO function

/*** Group F pins ***/
	GpioMuxRegs.GPFDIR.all = 0x0000;				// All group F GPIO are inputs

	GpioMuxRegs.GPFMUX.bit.XF_GPIOF14      = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MDRA_GPIOF13    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MDXA_GPIOF12    = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MFSRA_GPIOF11   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MFSXA_GPIOF10   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MCLKRA_GPIOF9   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.MCLKXA_GPIOF8   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.CANRXA_GPIOF7   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.CANTXA_GPIOF6   = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SCIRXDA_GPIOF5  = 1;		// use as peripheral 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SCITXDA_GPIOF4  = 1;		// use as peripheral0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SPISTEA_GPIOF3  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SPICLKA_GPIOF2  = 1;//0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SPISOMIA_GPIOF1 = 1;//0;		// 0: select GPIO function
	GpioMuxRegs.GPFMUX.bit.SPISIMOA_GPIOF0 = 1;//0;		// 0: select GPIO function

	GpioMuxRegs.GPFDIR.bit.GPIOF14 = 1;				// 1: GPIOF14 is output (connected to LED on eZdsp)
	GpioDataRegs.GPFSET.bit.GPIOF14 = 1;			// 1: set GPIOF14 (turn LED on)
//for spi:
	GpioMuxRegs.GPFDIR.bit.GPIOF3 = 1;				// 1: GPIOF14 is output (connected to LED on eZdsp)
	GpioDataRegs.GPFSET.bit.GPIOF3 = 1;			// 1: set GPIOF14 (turn LED on)



/*** Group G pins ***/
	GpioMuxRegs.GPGDIR.all = 0x0000;				// All group G GPIO are inputs

	GpioMuxRegs.GPGMUX.bit.SCIRXDB_GPIOG5  = 0;		// 0: select GPIO function
	GpioMuxRegs.GPGMUX.bit.SCITXDB_GPIOG4  = 0;		// 0: select GPIO function

/*** Finish up ***/
	asm(" EDIS");						// Disable EALLOW protected register access

} //end InitGpio()


/*** end of file *****************************************************/
