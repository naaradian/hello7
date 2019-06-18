/**********************************************************************
* File: Ev.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
*   01/27/04 - corrected pin names in comments for ACTRA register (D. Alter)
*   03/23/04 - corrected comment for GPTCONA.T1TOADC configuration (D. Alter)
*   09/01/04 - corrected TPSx comment for EvaRegs.T2CON configuration (D. Alter)

**********************************************************************/

#include "DSP281x_Device.h"

// EXAMPLE_BIOS or EXAMPLE_NONBIOS are defined in the CCS project build options
#ifdef EXAMPLE_BIOS
    #include "example_BIOS.h"
#endif

#ifdef EXAMPLE_NONBIOS
    #include "example_nonBIOS.h"
#endif


/*** Global variables used by InitEv() ***/
//to divide to 10  - 40 hz havw widch preskaler/128 #define ADC_sample_period   2999			// 2999 = 50KHz sampling w/ 150MHz CPUCLK
//#define ADC_sample_period   29999			// 2999 = 50KHz sampling w/ 150MHz CPUCLK
#define ADC_sample_period   60000			// 20 Hz
//#define ADC_sample_period   5999			// 2999 = 50KHz sampling w/ 150MHz CPUCLK
#define PWM_half_period    37500			// period/2 for 2kHz symmetric PWM
#define PWM_duty_cycle     28125			// 25% duty cycle

/**********************************************************************
* Function: InitEv()
*
* Description: Initializes the Event Managers on the F281x.
**********************************************************************/
void InitEv(void)
{

/**************************************/
/*** Configure the EXTCON registers ***/
/**************************************/
	EvaRegs.EXTCONA.all = 0x0001;
/*
 bit 15-4      0's:    reserved
 bit 3         0:      EVSOCE, 0 = disable EV start of ADC conversion output
 bit 2         0:      QEPIE, 0 = disable CAP3_QEPI as index input
 bit 1         0:      QEPIQUAL, 0 = CAP3_QEPI qual disabled
 bit 0         1:      INDCOE, 1 = independent compare enable
*/

	EvbRegs.EXTCONB.all = 0x0001;
/*
 bit 15-4      0's:    reserved
 bit 3         0:      EVSOCE, 0 = disable EV start of ADC conversion output
 bit 2         0:      QEPIE, 0 = disable CAP6_QEPI as index input
 bit 1         0:      QEPIQUAL, 0 = CAP6_QEPI qual disabled
 bit 0         1:      INDCOE, 1 = independent compare enable
*/


/******************************************************/
/*** Disable and clear all event manager interrupts ***/
/******************************************************/
	EvaRegs.EVAIMRA.all = 0x0000;		// Disable all EVA group A interrupts
	EvaRegs.EVAIMRB.all = 0x0000;		// Disable all EVA group B interrupts
    EvaRegs.EVAIMRC.all = 0x0000;		// Disable all EVA group C interrupts
    EvaRegs.EVAIFRA.all = 0xFFFF;       // Clear all EVA group A interrupts
    EvaRegs.EVAIFRB.all = 0xFFFF;		// Clear all EVA group B interrupts
    EvaRegs.EVAIFRC.all = 0xFFFF;		// Clear all EVA group C interrupts

	EvbRegs.EVBIMRA.all = 0x0000;		// Disable all EVB group A interrupts
	EvbRegs.EVBIMRB.all = 0x0000;		// Disable all EVB group B interrupts
    EvbRegs.EVBIMRC.all = 0x0000;		// Disable all EVB group C interrupts
    EvbRegs.EVBIFRA.all = 0xFFFF;       // Clear all EVB group A interrupts
    EvbRegs.EVBIFRB.all = 0xFFFF;		// Clear all EVB group B interrupts
    EvbRegs.EVBIFRC.all = 0xFFFF;		// Clear all EVB group C interrupts


/**************************************/
/*** Configure the GPTCONA register ***/
/**************************************/
//t	EvaRegs.GPTCONA.all = 0x0400;
		EvaRegs.GPTCONA.all = 0x1c50; //to_start
/*
 bit 15        0:      reserved
 bit 14        0:      T2STAT, read-only
 bit 13        0:      T1STAT, read-only
 bit 12        0:      T2CTRIPE, 0=disable timer2 compare trip
 bit 11        0:      T1CTRIPE, 0=disable timer1 compare trip
 bit 10-9      10:     T2TOADC, 10 = timer2 period flag starts ADC
 bit 8-7       00:     T1TOADC, 00 = timer1 does not start ADC
 bit 6         0:      TCOMPOE, 0 = Hi-z all timer compare outputs
 bit 5         0:      T2COMPOE, 0 = timer2 compare HI-z'd
 bit 4         0:      T1COMPOE, 0 = timer1 compare HI-z'd
 bit 3-2       00:     T2PIN, 00 = forced low
 bit 1-0       00:     T1PIN, 00 = forced low
*/


/************************************************************/
/*** Configure Timer 2 to trigger the ADC at a 50KHz rate ***/
/************************************************************/
	EvaRegs.T2CON.all = 0x0000;			// Disable timer
	EvaRegs.T2CNT = 0x0000;				// Clear timer counter
    EvaRegs.T2PR = ADC_sample_period;	// Set timer period

//to not use 50 kHz use 50/128 	EvaRegs.T2CON.all = 0xD040;			//enable timer
	EvaRegs.T2CON.all = 0xD740;			//enable timer 50 kHz/128
/*
 bit 15-14     11:     FREE/SOFT, 11 = ignor emulation suspend
 bit 13        0:      reserved
 bit 12-11     10:     TMODEx, 10 = continuous-up count mode
 bit 10-8      000:    TPSx, 000 = x/1 prescaler
 bit 10-8      111:    TPSx, 000 = x/128 prescaler 
 bit 7         0:      T2SWT1, 0 = use own TENABLE bit
 bit 6         1:      TENABLE, 1 = enable timer
 bit 5-4       00:     TCLKS, 00 = HSPCLK is clock source
 bit 3-2       00:     TCLD, 00 = reload compare reg on underflow
 bit 1         0:      TECMPR, 0 = enable timer compare
 bit 0         0:      SELT1PR, 0 = use own period register
*/


/************************************************************/
/*** Configure Timer 1 for 2KHz symmetric PWM on PWM1 pin ***/
/************************************************************/
	EvaRegs.T1CON.all = 0x0000;			// Disable timer
	EvaRegs.T1CNT = 0x0000;				// Clear timer counter
    EvaRegs.T1PR = PWM_half_period;		// Set timer period
	EvaRegs.DBTCONA.all = 0x0000;		// Deadband units off
	EvaRegs.CMPR1 = PWM_duty_cycle;		// Set PWM1 duty cycle
//	EvaRegs.T1CMPR = 0x0101;		//to_start

	EvaRegs.ACTRA.all = 0x0002;			// PWM1 set for active high
/*
 bit 15        0:      SVDIR, space vector dir is CCW (don't care)
 bit 14-12     000:    D2-D0, basic space vector is 000 (dont' care)
 bit 11-10     00:     CMP6ACTx, PWM6/GPIOA5 pin forced low
 bit 9-8       00:     CMP5ACTx, PWM5/GPIOA4 pin forced low
 bit 7-6       00:     CMP4ACTx, PWM4/GPIOA3 pin forced low
 bit 5-4       00:     CMP3ACTx, PWM3/GPIOA2 pin forced low
 bit 3-2       00:     CMP2ACTx, PWM2/GPIOA1 pin forced low
 bit 1-0       10:     CMP1ACTx, PWM1/GPIOA0 pin active high
*/

	EvaRegs.COMCONA.all = 0x8221;		// Init COMCONA
/*
 bit 15        1:      CENABLE, 1 = enable full compare operation
 bit 14-13     00:     CLDx, 00 = reload CMPRx regs on timer 1 underflow
 bit 12        0:      SVENABLE, 0 = space vector disabled
 bit 11-10     00:     ACTRLDx, 00 = reload ACTR on timer 1 underflow
 bit 9         1:      FCMPOE, 1 = enable PWM pins
 bit 8         0:      PDPINT, PDPINT status (read-only)
 bit 7         0:      FCMP3OE, compare 3 enable (1=enable)
 bit 6         0:      FCMP2OE, compare 2 enable (1=enable)
 bit 5         1:      FCMP1OE, compare 1 enable (1=enable)
 bit 4-3       00:     reserved
 bit 2         0:      C3TRIPE, compare 3 trip enable (1=enable)
 bit 1         0:      C2TRIPE, compare 2 trip enable (1=enable)
 bit 0         1:      C1TRIPE, compare 1 trip enable (1=enable)
*/

//t	EvaRegs.T1CON.all = 0xC840;			// Init T1CON, enable timer
	EvaRegs.T1CON.all = 0xC842;			// Init T1CON, enable timer
//	EvaRegs.T1CON.all = 0xd040;	//enable compare?		// Init T1CON, enable timer

//? d040
/*
 bit 15-14     11:     FREE/SOFT, 11 = ignor emulation suspend
 bit 13        0:      reserved
 bit 12-11     01:     TMODEx, 01 = continous-up/down count mode
 bit 10-8      000:    TPSx, 000 = x/1 prescaler
 bit 7         0:      T2SWT1, 0 = use own TENABLE bit
 bit 6         1:      TENABLE, 1 = enable timer
 bit 5-4       00:     TCLKS, 00 = CPUCLK is clock source
 bit 3-2       00:     TCLD, 00 = reload compare reg on underflow
 bit 1         0:      TECMPR, 0 = disable timer compare
 bit 0         0:      SELT1PR, 0 = use own period register
*/


/****************************/
/*** Setup Capture unit 1 ***/
/****************************/
	EvaRegs.CAPCONA.all = 0x0000;		// reset the capture units
/*
 bit 15        0:      CAPRES, 0 = reset the capture units and registers
*/

	EvaRegs.CAPCONA.all = 0xA2C0;		// Init CAPCONA register
/*
 bit 15        1:      CAPRES, 1 = no action
 bit 14-13     01:     CAP12EN, 01 = enable CAP1 and CAP2, QEP disabled
 bit 12        0:      CAP3EN, 0 = disable CAP3
 bit 11        0:      reserved
 bit 10        0:      CAP3TSEL, CAP3 uses:          0=timer2, 1=timer1
 bit 9         1:      CAP12TSEL, CAP1 and CAP2 use: 0=timer2, 1=timer1
 bit 8         0:      CAP3TOADC, 0 = CAP3 does not start ADC
 bit 7-6       11:     CAP1EDGE, 11 = CAP1 detects both rising and falling edges
 bit 5-4       00:     CAP2EDGE, 00 = CAP2 no detection
 bit 3-2       00:     CAP3EDGE, 00 = CAP3 no detection
 bit 1-0       00:     reserved
*/

//t	EvaRegs.EVAIMRC.bit.CAP1INT = 1;	// Enable CAPINT1
//t	PieCtrlRegs.PIEIER3.bit.INTx5 = 1;	// Enable CAPINT1 in PIE group 3
//t	IER |= 0x0004;						// Enable INT3 in IER to enable PIE group 3

} // end InitEv()


/*** end of file *****************************************************/
