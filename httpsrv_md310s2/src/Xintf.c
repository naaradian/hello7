
/**********************************************************************
* File: Xintf.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* Description: This function initializes the External Memory Interface.
*   Do not modify the timings of a zone while accessing that zone.
*   On F2811 and F2810 devices, there is no XINTF peripheral other than
*   the XCLKOUT pin.  This function can still be used to configure
*   XCLKOUT.
* History:
*   09/08/03 - original (based on DSP28 header files v1.00, D. Alter)
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
* Function: InitXintf()
*
* Description: Initializes the external memory interface on the F2812.
**********************************************************************/
void InitXintf(void)
{

/*** XINTCNF2 Register ***/
	XintfRegs.XINTCNF2.bit.XTIMCLK = 0;			// XTIMCLK=SYSCLKOUT/1
//	XintfRegs.XINTCNF2.bit.XTIMCLK = 1;			// my
	XintfRegs.XINTCNF2.bit.CLKOFF = 0;			// XCLKOUT is enabled
	XintfRegs.XINTCNF2.bit.CLKMODE = 0;			// XCLKOUT = XTIMCLK

// Make sure write buffer is empty before configuring buffering depth
	while(XintfRegs.XINTCNF2.bit.WLEVEL != 0);	// poll the WLEVEL bit
	XintfRegs.XINTCNF2.bit.WRBUFF = 0;			// No write buffering

/*** XBANK Register ***/
// Example: Assume Zone 7 is slow, so add additional BCYC cycles whenever
// switching from Zone 7 to another Zone.  This will help avoid bus contention.
	XintfRegs.XBANK.bit.BCYC = 7;				// Add 7 cycles
	XintfRegs.XBANK.bit.BANK = 7;				// select zone 7
//	XintfRegs.XBANK.bit.BANK = 0;				// select zone 0    
/*** Zone 0 Configuration ***/
/*
//	XintfRegs.XTIMING0.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING0.bit.X2TIMING = 1;	// Timing scale factor my
	XintfRegs.XTIMING0.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING0.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING0.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING0.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING0.bit.XRDACTIVE = 2;	// Read active time
	XintfRegs.XTIMING0.bit.XRDTRAIL = 0;	// Read trail time
	XintfRegs.XTIMING0.bit.XWRLEAD = 1;		// Write lead time
//	XintfRegs.XTIMING0.bit.XWRACTIVE = 2;	// Write active time
	XintfRegs.XTIMING0.bit.XWRACTIVE = 7;	// Write active time my
	XintfRegs.XTIMING0.bit.XWRTRAIL = 0;	// Write trail time
*/
//	XintfRegs.XTIMING0.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING0.bit.X2TIMING = 1;	// Timing scale factor my
	XintfRegs.XTIMING0.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING0.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING0.bit.USEREADY = 0;	// Disable XREADY
//tt	XintfRegs.XTIMING0.bit.USEREADY = 1;	// Enable XREADY
	XintfRegs.XTIMING0.bit.XRDLEAD = 3;		// Read lead time
	XintfRegs.XTIMING0.bit.XRDACTIVE = 7;	// Read active time
	XintfRegs.XTIMING0.bit.XRDTRAIL = 3;	// Read trail time
	XintfRegs.XTIMING0.bit.XWRLEAD = 3;		// Write lead time
//	XintfRegs.XTIMING0.bit.XWRACTIVE = 2;	// Write active time
//t	XintfRegs.XTIMING0.bit.XWRACTIVE = 4;	// Write active time my
	XintfRegs.XTIMING0.bit.XWRACTIVE = 7;	// Write active time my
//t	XintfRegs.XTIMING0.bit.XWRTRAIL = 0;	// Write trail time
	XintfRegs.XTIMING0.bit.XWRTRAIL = 3;

/*** Zone 1 Configuration ***/
//t	XintfRegs.XTIMING1.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING1.bit.X2TIMING = 1;
	XintfRegs.XTIMING1.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING1.bit.READYMODE = 1; 	// XREADY is asynchronous
//	XintfRegs.XTIMING1.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING1.bit.USEREADY = 1;	// Enable XREADY
//	XintfRegs.XTIMING1.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING1.bit.XRDLEAD = 3;		// Read lead time
//	XintfRegs.XTIMING1.bit.XRDACTIVE = 2;	// Read active time
	XintfRegs.XTIMING1.bit.XRDACTIVE = 7;	// Read active time
//	XintfRegs.XTIMING1.bit.XRDTRAIL = 0;	// Read trail time
	XintfRegs.XTIMING1.bit.XRDTRAIL = 3;	// Read trail time
//t	XintfRegs.XTIMING1.bit.XWRLEAD = 1;		// Write lead time
	XintfRegs.XTIMING1.bit.XWRLEAD = 3;		// Write lead time
//	XintfRegs.XTIMING1.bit.XWRLEAD = 3;	
//	XintfRegs.XTIMING1.bit.XWRACTIVE = 2;	// Write active time
	XintfRegs.XTIMING1.bit.XWRACTIVE = 7;
//	XintfRegs.XTIMING1.bit.XWRTRAIL = 0;	// Write trail time
	XintfRegs.XTIMING1.bit.XWRTRAIL = 3;	// Write trail time

/*** Zone 2 Configuration ***/
/*
	XintfRegs.XTIMING2.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING2.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING2.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING2.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING2.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING2.bit.XRDACTIVE = 2;	// Read active time
	XintfRegs.XTIMING2.bit.XRDTRAIL = 0;	// Read trail time
	XintfRegs.XTIMING2.bit.XWRLEAD = 1;		// Write lead time
	XintfRegs.XTIMING2.bit.XWRACTIVE = 2;	// Write active time
	XintfRegs.XTIMING2.bit.XWRTRAIL = 0;	// Write trail time
	*/

	XintfRegs.XTIMING2.bit.X2TIMING = 1;	// Timing scale factor = 1
	XintfRegs.XTIMING2.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING2.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING2.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING2.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING2.bit.XRDACTIVE = 1;	// Read active time
	XintfRegs.XTIMING2.bit.XRDTRAIL = 1;	// Read trail time
	XintfRegs.XTIMING2.bit.XWRLEAD = 2;		// Write lead time
	XintfRegs.XTIMING2.bit.XWRACTIVE = 2;	// Write active time
	XintfRegs.XTIMING2.bit.XWRTRAIL = 2;	// Write trail time
	
/*** Zone 6 Configuration ***/
	XintfRegs.XTIMING6.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING6.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING6.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING6.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING6.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING6.bit.XRDACTIVE = 7;	// Read active time
	XintfRegs.XTIMING6.bit.XRDTRAIL = 0;	// Read trail time
	XintfRegs.XTIMING6.bit.XWRLEAD = 1;		// Write lead time
	XintfRegs.XTIMING6.bit.XWRACTIVE = 7;	// Write active time
	XintfRegs.XTIMING6.bit.XWRTRAIL = 0;	// Write trail time

/*** Zone 7 Configuration ***/
	XintfRegs.XTIMING7.bit.X2TIMING = 0;	// Timing scale factor = 1
	XintfRegs.XTIMING7.bit.XSIZE = 3;		// Always write as 11b
	XintfRegs.XTIMING7.bit.READYMODE = 1; 	// XREADY is asynchronous
	XintfRegs.XTIMING7.bit.USEREADY = 0;	// Disable XREADY
	XintfRegs.XTIMING7.bit.XRDLEAD = 1;		// Read lead time
	XintfRegs.XTIMING7.bit.XRDACTIVE = 2;	// Read active time
	XintfRegs.XTIMING7.bit.XRDTRAIL = 0;	// Read trail time
	XintfRegs.XTIMING7.bit.XWRLEAD = 1;		// Write lead time
	XintfRegs.XTIMING7.bit.XWRACTIVE = 2;	// Write active time
	XintfRegs.XTIMING7.bit.XWRTRAIL = 0;	// Write trail time

/*** Force a complete pipeline flush to ensure that the write to the last register
     configured occurs before returning.  Safest thing to do is wait 8 full cycles.
***/
	asm(" RPT #6 || NOP");


} //end of InitXintf()

/*** end of file *****************************************************/	
