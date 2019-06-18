/**********************************************************************
* File: PieVect_nonBIOS.c
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
* The PIE vector initialization table for the F281x.
**********************************************************************/
const struct PIE_VECT_TABLE PieVectTableInit = {

/*** Base vectors ***/
    PIE_RESERVED,                   // 0x000D00  reserved
    PIE_RESERVED,                   // 0x000D02  reserved
    PIE_RESERVED,                   // 0x000D04  reserved
    PIE_RESERVED,                   // 0x000D06  reserved
    PIE_RESERVED,                   // 0x000D08  reserved
    PIE_RESERVED,                   // 0x000D0A  reserved
    PIE_RESERVED,                   // 0x000D0C  reserved
    PIE_RESERVED,                   // 0x000D0E  reserved
    PIE_RESERVED,                   // 0x000D10  reserved
    PIE_RESERVED,                   // 0x000D12  reserved
    PIE_RESERVED,                   // 0x000D14  reserved
    PIE_RESERVED,                   // 0x000D16  reserved
    PIE_RESERVED,                   // 0x000D18  reserved
    INT13_ISR,                      // 0x000D1A  INT13 - XINT13 (or CPU Timer1, reserved for TI)
    INT14_ISR,                      // 0x000D1C  INT14 - CPU Timer2, reserved for TI
    DATALOG_ISR,                    // 0x000D1E  DATALOG - CPU data logging interrupt
    RTOSINT_ISR,                    // 0x000D20  RTOSINT - CPU RTOS interrupt
    EMUINT_ISR,                     // 0x000D22  EMUINT - CPU emulation interrupt
    NMI_ISR,                        // 0x000D24  NMI - XNMI interrupt
    ILLEGAL_ISR,                    // 0x000D26  ILLEGAL - illegal operation trap
    USER1_ISR,                      // 0x000D28  USER1 - software interrupt #1
    USER2_ISR,                      // 0x000D2A  USER2 - software interrupt #2
    USER3_ISR,                      // 0x000D2C  USER3 - software interrupt #3
    USER4_ISR,                      // 0x000D2E  USER4 - software interrupt #4
    USER5_ISR,                      // 0x000D30  USER5 - software interrupt #5
    USER6_ISR,                      // 0x000D32  USER6 - software interrupt #6
    USER7_ISR,                      // 0x000D34  USER7 - software interrupt #7
    USER8_ISR,                      // 0x000D36  USER8 - software interrupt #8
    USER9_ISR,                      // 0x000D38  USER9 - software interrupt #9
    USER10_ISR,                     // 0x000D3A  USER10 - software interrupt #10
    USER11_ISR,                     // 0x000D3C  USER11 - software interrupt #11
    USER12_ISR,                     // 0x000D3E  USER12 - software interrupt #12

/*** Core interrupt #1 re-map ***/
    PDPINTA_ISR,                    // 0x000D40  PDPINTA (EV-A)
    PDPINTB_ISR,                    // 0x000D42  PDPINTB (EV-B)
    rsvd_ISR,                       // 0x000D44  reserved
    XINT1_ISR,                      // 0x000D46  XINT1
    XINT2_ISR,                      // 0x000D48  XINT2
    ADCINT_ISR,                     // 0x000D4A  ADCINT (ADC)
    TINT0_ISR,                      // 0x000D4C  TINT0 (CPU TIMER 0)
    WAKEINT_ISR,                    // 0x000D4E  WAKEINT (LPM/WD)

/*** Core interrupt #2 re-map ***/
    CMP1INT_ISR,                    // 0x000D50  CMP1INT (EV-A)
    CMP2INT_ISR,                    // 0x000D52  CMP2INT (EV-A)
    CMP3INT_ISR,                    // 0x000D54  CMP3INT (EV-A)
    T1PINT_ISR,                     // 0x000D56  T1PINT (EV-A)
    T1CINT_ISR,                     // 0x000D58  T1CINT (EV-A)
    T1UFINT_ISR,                    // 0x000D5A  T1UFINT (EV-A)
    T1PINT_ISR,                     // 0x000D5C  T1OFINT (EV-A)
    rsvd_ISR,                       // 0x000D5E  reserved

/*** Core interrupt #3 re-map ***/
    T2PINT_ISR,                     // 0x000D60  T2PINT (EV-A)
    T2CINT_ISR,                     // 0x000D62  T2CINT (EV-A)
    T2UFINT_ISR,                    // 0x000D64  T2UFINT (EV-A)
    T2OFINT_ISR,                    // 0x000D66  T2OFINT (EV-A)
    CAPINT1_ISR,                    // 0x000D68  CAPINT1 (EV-A)
    CAPINT2_ISR,                    // 0x000D6A  CAPINT2 (EV-A)
    CAPINT3_ISR,                    // 0x000D6C  CAPINT3 (EV-A)
    rsvd_ISR,                       // 0x000D6E  reserved

/*** Core interrupt #4 re-map ***/
    CMP4INT_ISR,                    // 0x000D70  CMP4INT (EV-B)
    CMP5INT_ISR,                    // 0x000D72  CMP5INT (EV-B)
    CMP6INT_ISR,                    // 0x000D74  CMP6INT (EV-B)
    T3PINT_ISR,                     // 0x000D76  T3PINT (EV-B)
    T3CINT_ISR,                     // 0x000D78  T3CINT (EV-B)
    T3UFINT_ISR,                    // 0x000D7A  T3UFINT (EV-B)
    T3OFINT_ISR,                    // 0x000D7C  T3OFINT (EV-B)
    rsvd_ISR,                       // 0x000D7E  reserved

/*** Core interrupt #5 re-map ***/
    T4PINT_ISR,                     // 0x000D80  T4PINT (EV-B)
    T4CINT_ISR,                     // 0x000D82  T4CINT (EV-B)
    T4UFINT_ISR,                    // 0x000D84  T4UFINT (EV-B)
    T4OFINT_ISR,                    // 0x000D86  T4OFINT (EV-B)
    CAPINT4_ISR,                    // 0x000D88  CAPINT4 (EV-B)
    CAPINT5_ISR,                    // 0x000D8A  CAPINT5 (EV-B)
    CAPINT6_ISR,                    // 0x000D8C  CAPINT6 (EV-B)
    rsvd_ISR,                       // 0x000D8E  reserved

/*** Core interrupt #6 re-map ***/
    SPIRXINTA_ISR,                  // 0x000D90  SPIRXINTA (SPI)
    SPITXINTA_ISR,                  // 0x000D92  SPITXINTA (SPI)
    rsvd_ISR,                       // 0x000D94  reserved
    rsvd_ISR,                       // 0x000D96  reserved
    MRINTA_ISR,                     // 0x000D98  MRINT (McBSP)
    MXINTA_ISR,                     // 0x000D9A  MXINT (McBSP)
    rsvd_ISR,                       // 0x000D9C  reserved
    rsvd_ISR,                       // 0x000D9E  reserved

/*** Core interrupt #7 re-map ***/
    rsvd_ISR,                       // 0x000DA0  reserved
    rsvd_ISR,                       // 0x000DA2  reserved
    rsvd_ISR,                       // 0x000DA4  reserved
    rsvd_ISR,                       // 0x000DA6  reserved
    rsvd_ISR,                       // 0x000DA8  reserved
    rsvd_ISR,                       // 0x000DAA  reserved
    rsvd_ISR,                       // 0x000DAC  reserved
    rsvd_ISR,                       // 0x000DAE  reserved

/*** Core interrupt #8 re-map ***/
    rsvd_ISR,                       // 0x000DB0  reserved
    rsvd_ISR,                       // 0x000DB2  reserved
    rsvd_ISR,                       // 0x000DB4  reserved
    rsvd_ISR,                       // 0x000DB6  reserved
    rsvd_ISR,                       // 0x000DB8  reserved
    rsvd_ISR,                       // 0x000DBA  reserved
    rsvd_ISR,                       // 0x000DBC  reserved
    rsvd_ISR,                       // 0x000DBE  reserved

/*** Core interrupt #9 re-map ***/
    SCIRXINTA_ISR,                  // 0x000DC0  SCIRXINTA (SCI-A)
    SCITXINTA_ISR,                  // 0x000DC2  SCITXINTA (SCI-A)
    SCIRXINTB_ISR,                  // 0x000DC4  SCIRXINTB (SCI-B)
    SCITXINTB_ISR,                  // 0x000DC6  SCITXINTB (SCI-B)
    ECAN0INTA_ISR,                  // 0x000DC8  ECAN0INT (CAN)
    ECAN1INTA_ISR,                  // 0x000DCA  ECAN1INT (CAN)
    rsvd_ISR,                       // 0x000DCC  reserved
    rsvd_ISR,                       // 0x000DCE  reserved

/*** Core interrupt #10 re-map ***/
    rsvd_ISR,                       // 0x000DD0  reserved
    rsvd_ISR,                       // 0x000DD2  reserved
    rsvd_ISR,                       // 0x000DD4  reserved
    rsvd_ISR,                       // 0x000DD6  reserved
    rsvd_ISR,                       // 0x000DD8  reserved
    rsvd_ISR,                       // 0x000DDA  reserved
    rsvd_ISR,                       // 0x000DDC  reserved
    rsvd_ISR,                       // 0x000DDE  reserved

/*** Core interrupt #11 re-map ***/
    rsvd_ISR,                       // 0x000DE0  reserved
    rsvd_ISR,                       // 0x000DE2  reserved
    rsvd_ISR,                       // 0x000DE4  reserved
    rsvd_ISR,                       // 0x000DE6  reserved
    rsvd_ISR,                       // 0x000DE8  reserved
    rsvd_ISR,                       // 0x000DEA  reserved
    rsvd_ISR,                       // 0x000DEC  reserved
    rsvd_ISR,                       // 0x000DEE  reserved


/*** Core interrupt #12 re-map ***/
    rsvd_ISR,                       // 0x000DF0  reserved
    rsvd_ISR,                       // 0x000DF2  reserved
    rsvd_ISR,                       // 0x000DF4  reserved
    rsvd_ISR,                       // 0x000DF6  reserved
    rsvd_ISR,                       // 0x000DF8  reserved
    rsvd_ISR,                       // 0x000DFA  reserved
    rsvd_ISR,                       // 0x000DFC  reserved
    rsvd_ISR,                       // 0x000DFE  reserved

}; //end PieVectTableInit{}


/*** end of file *****************************************************/
