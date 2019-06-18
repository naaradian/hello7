/**********************************************************************
* File: Adc.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
*   03/18/04 - fixed comment field for ADCTRL1.5 bit
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
* Function: InitAdc()
*
* Description: Initializes the ADC on the F281x.
**********************************************************************/
void InitAdc(void)
{

/*** Reset the ADC module ***/
	AdcRegs.ADCTRL1.bit.RESET = 1;		// Reset the ADC module
	asm(" RPT #10 || NOP");				// Must wait 12-cycles (worst-case) for ADC reset to take effect
	
/*** Must follow the proper ADC power-up sequence ***/
	AdcRegs.ADCTRL3.all = 0x00C8;		// first power-up ref and bandgap circuits
/*
 bit 15-8      0's:    reserved
 bit 7         1:      ADCRFDN, reference power, 1=power on
 bit 6         1:      ADCBGDN, bandgap power, 1=power on
 bit 5         0:      ADCPWDN, main ADC power, 1=power on
 bit 4-1       0100:   ADCCLKPS, clock prescaler, FCLK=HSPCLK/(2*ADCCLKPS)
 bit 0         0:      SMODE_SEL, 0=sequential sampling, 1=simultaneous sampling
*/

	DelayUs(7000);						// Wait 7ms before setting ADCPWDN
	AdcRegs.ADCTRL3.bit.ADCPWDN = 1;	// Set ADCPWDN=1 to power main ADC
	DelayUs(20);						// Wait 20us before using the ADC

/*** Configure the other ADC register ***/
	AdcRegs.ADCMAXCONV.all = 0x0000;
/*
 bit 15-7      0's:    reserved
 bit 6-4       000:    MAX_CONV2 value
 bit 3-0       0000:   MAX_CONV1 value (0 means 1 conversion)
*/

	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;	// Convert Channel 0

	AdcRegs.ADCTRL1.all = 0x0710;
/*
 bit 15        0:      reserved
 bit 14        0:      RESET, 0=no action, 1=reset ADC
 bit 13-12     00:     SUSMOD, 00=ignor emulation suspend
 bit 11-8      0111:   ACQ_PS (Acquisition), 0111 = 8 x ADCCLK
 bit 7         0:      CPS (Core clock), 0: ADCCLK=FCLK/1, 1: ADCCLK=FCLK/2
 bit 6         0:      CONT_RUN, 0=start/stop mode, 1=continuous run
 bit 5         0:      SEQ_OVRD, 0=disabled, 1=enabled
 bit 4         1:      SEQ_CASC, 0=dual sequencer, 1=cascaded sequencer
 bit 3-0       0000:   reserved
*/

	AdcRegs.ADCTRL2.all = 0x0900;
/*
 bit 15        0:      EVB_SOC_SEQ, 0=no action
 bit 14        0:      RST_SEQ1, 0=no action
 bit 13        0:      SOC_SEQ1, 0=clear any pending SOCs
 bit 12        0:      reserved
 bit 11        1:      INT_ENA_SEQ1, 1=enable interrupt
 bit 10        0:      INT_MOD_SEQ1, 0=int on every SEQ1 conv
 bit 9         0:      reserved
 bit 8         1:      EVA_SOC_SEQ1, 1=SEQ1 start from EVA
 bit 7         0:      EXT_SOC_SEQ1, 1=SEQ1 start from ADCSOC pin
 bit 6         0:      RST_SEQ2, 0=no action
 bit 5         0:      SOC_SEQ2, no effect in cascaded mode
 bit 4         0:      reserved
 bit 3         0:      INT_ENA_SEQ2, 0=int disabled
 bit 2         0:      INT_MOD_SEQ2, 0=int on every other SEQ2 conv
 bit 1         0:      reserved
 bit 0         0:      EVB_SOC_SEQ2, 1=SEQ2 started by EVB
*/

/*** Enable the ADC interrupt ***/
	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;	// Enable ADCINT in PIE group 1
	IER |= 0x0001;						// Enable INT1 in IER to enable PIE group

} // end AdcInit()


/*** end of file *****************************************************/
