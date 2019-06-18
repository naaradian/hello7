// TI File $Revision: /main/2 $
// Checkin $Date: January 10, 2005   14:39:40 $
//###########################################################################
//
// FILE:    SelectMode_Boot.c    
//
// TITLE:   280x Boot Mode selection routines
//
// Functions:
//
//      Uint32 SelectBootMode(void)      
//      inline void SelectMode_GPOISelect(void)
//
// Notes:
//
//###########################################################################
// $TI Release:$
// $Release Date:$
//###########################################################################

//#include "DSP280x_Device.h"
#include "DSP281x_Device.h"
#include "280x_Boot.h"

//extern Uint32 SCI_Boot(void);
extern Uint32 SPI_Boot(void);
/*
extern Uint32 Parallel_Boot(void);
extern Uint32 I2C_Boot(void);
extern Uint32 CAN_Boot();

//         GPIO18     GPIO29    GPIO34
//         SPICLKA    SCITXDA
//         SCITXB
//Flash       1          1        1
//SCI         1          1        0
//SPI         1          0        1
//I2C         1          0        0
//ECAN        0          1        1        
//RAM         0          1        0
//OTP         0          0        1
//I/0         0          0        0

#define FLASH_BOOT    7
#define SCI_BOOT      6
#define SPI_BOOT      5
#define I2C_BOOT      4
#define CAN_BOOT      3
#define RAM_BOOT      2
#define OTP_BOOT      1
#define PARALLEL_BOOT 0
*/
Uint32 SelectBootMode()
{

  Uint32 EntryAddr;
  /*
  Uint16 BootMode;
  
#ifdef _DEBUGSELECT
// To debug without having to select
// the boot mode via jumpers, define
// _DEBUGSELECT and comment out the
// appropriate boot mode to test

   EALLOW;
   SysCtrlRegs.WDCR = 0x0068;	// Disable watchdog module
   EDIS;

// EntryAddr = SCI_Boot();
// EntryAddr = SPI_Boot();
   EntryAddr = Parallel_Boot();
// EntryAddr = I2C_Boot();
// EntryAddr = CAN_Boot();


   EALLOW;
   SysCtrlRegs.WDCR = 0x0028; // Enable watchdog module
   SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
   SysCtrlRegs.WDKEY = 0xAA;
   EDIS;
#endif


#ifndef _DEBUGSELECT
  EALLOW;
  // Set MUX for BOOT Select
  GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;
  GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;
  GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;

  // Set DIR for BOOT Select
  GpioCtrlRegs.GPADIR.bit.GPIO18 = 0;
  GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;
  GpioCtrlRegs.GPBDIR.bit.GPIO34 = 0;    
  EDIS;
  
  // Form BootMode from BOOT select pins
  BootMode  = GpioDataRegs.GPADAT.bit.GPIO18 << 2;
  BootMode |= GpioDataRegs.GPADAT.bit.GPIO29 << 1;
  BootMode |= GpioDataRegs.GPBDAT.bit.GPIO34;

  // Read the password locations - this will unlock the
  // CSM only if the passwords are erased.  Otherwise it
  // will not have an effect.
  CsmPwl.PSWD0;
  CsmPwl.PSWD1;
  CsmPwl.PSWD2;
  CsmPwl.PSWD3;
  CsmPwl.PSWD4;
  CsmPwl.PSWD5;
  CsmPwl.PSWD6;
  CsmPwl.PSWD7;
  
  // First check for modes which do not require
  // a boot loader (Flash/RAM/OTP)
  if(BootMode == FLASH_BOOT) return FLASH_ENTRY_POINT;
  if(BootMode == RAM_BOOT)   return RAM_ENTRY_POINT;
  if(BootMode == OTP_BOOT)   return OTP_ENTRY_POINT;
  
  // Otherwise, disable the watchdog and check for the 
  // other boot modes that requre loaders
  EALLOW;
  SysCtrlRegs.WDCR = 0x0068;
  EDIS;

  if(BootMode == SCI_BOOT) EntryAddr = SCI_Boot();
  else if(BootMode == SPI_BOOT) EntryAddr = SPI_Boot();
  else if(BootMode == I2C_BOOT) EntryAddr = I2C_Boot();
  else if(BootMode == CAN_BOOT) EntryAddr = CAN_Boot();
  else if(BootMode == PARALLEL_BOOT) EntryAddr = Parallel_Boot();  
  else return FLASH_ENTRY_POINT; 

  EALLOW;
  SysCtrlRegs.WDCR = 0x0028; // Enable watchdog module
  SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
  SysCtrlRegs.WDKEY = 0xAA;
  EDIS;

#endif // end of not _DEBUGSELECT
*/
 EntryAddr = SPI_Boot();  //my
   return EntryAddr;

}

