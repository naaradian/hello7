***********************************************************************
* File: DelayUs.asm
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (D. Alter)
*   09/01/04 - fixed counter bug by zeroing AH (D. Alter)
***********************************************************************


**********************************************************************
* Function: DelayUs()                                                *
* Description: Implements a time delay.                              *
* DSP: TMS320F2812, TMS320F2811, TMS320F2810                         *
* Last Modified: 09/01/04                                            *
* Include files: none                                                *
* Function Prototype: void DelayUs(unsigned int)                     *
* Useage: DelayUs(Usec);                                             *
* Input Parameters: unsigned int Usec = time delay in microseconds   *
* Return Value: none                                                 *
* Notes: The execution time of this routine is based upon a 150 MHz  *
*        CPUCLK.  It also assumes that the function executes out of  *
*        internal RAM.  If executing out of internal flash, the      *
*        execution speed will be slightly slower.  However, the      *
*        inner loop of this function is essentially invariant to the *
*        memory it is running in.  Therefore, even when running in   *
*        flash memory, the basic loop time will be only slightly     *
*        longer than 1 us.                                           *   
**********************************************************************
       .def _DelayUs
       .text

_DelayUs:

		MOVB AH, #0                   ;zero AH

DelayUs1:
        RPT #143                      ;inner loop
     || NOP

        SUBB ACC,#1                   ;decrement outer loop counter
        BF DelayUs1, GT               ;branch for outer loop

        LRETR                         ;return

; end of function DelayUs() ******************************************


;end of file DelayUs.asm
       .end
