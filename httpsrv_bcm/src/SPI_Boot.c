 // TI File $Revision: /main/3 $
// Checkin $Date: January 10, 2005   15:57:54 $
//###########################################################################
//
// FILE:    SPI_Boot.c   
//
// TITLE:   280x SPI Boot mode routines
//
// Functions:
//
//     Uint32 SPI_Boot(void)
//     inline void SPIA_Init(void)
//     inline void SPIA_Transmit(u16 cmdData)
//     inline void SPIA_ReservedFn(void);
//     Uint32 SPIA_GetWordData(void)
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

// Private functions
inline void SPIA_Init(void);
inline Uint16 SPIA_Transmit(Uint16 cmdData);
inline void SPIA_ReservedFn(void);
Uint16 SPIA_GetWordData(void);
uint16fptr GetWordData;
// External functions
void CopyData(void);
Uint32 GetLongData(void);
//#################################################
// void CopyData(void)
//-----------------------------------------------------
// This routine copies multiple blocks of data from the host
// to the specified RAM locations.  There is no error
// checking on any of the destination addresses.  
// That is it is assumed all addresses and block size
// values are correct. 
// 
// Multiple blocks of data are copied until a block 
// size of 00 00 is encountered. 
// 
//-----------------------------------------------------
                              
void CopyData()
{

   struct HEADER {
     Uint16 BlockSize;
     Uint32 DestAddr;
   } BlockHeader;
  
   Uint16 wordData;
   Uint16 i;
//   long cnt; //to test
   // Get the size in words of the first block 
   BlockHeader.BlockSize = (*GetWordData)();
   
   // While the block size is > 0 copy the data 
   // to the DestAddr.  There is no error checking
   // as it is assumed the DestAddr is a valid 
   // memory location
 //  cnt = 10l; //to test 
  while(BlockHeader.BlockSize != (Uint16)0x0000)
 //  while(cnt--)
   {
   
      BlockHeader.DestAddr = GetLongData();
      for(i = 1; i <= BlockHeader.BlockSize; i++)
      {
          wordData = (*GetWordData)();
       //    asm("	RPT #0x7F ||NOP"); 
          *(Uint16 *)BlockHeader.DestAddr++ = wordData;
       //    asm("	RPT #0x7F ||NOP"); 
      }
      
      // Get the size of the next block
      
      BlockHeader.BlockSize = (*GetWordData)();
   }
   return;
}

//#################################################
// Uint32 GetLongData(void)
//-----------------------------------------------------
// This routine fetches a 32-bit value from the peripheral
// input stream. 
//-----------------------------------------------------

Uint32 GetLongData()
{
    Uint32 longData;

    // Fetch the upper 1/2 of the 32-bit value 
    longData = ( (Uint32)(*GetWordData)() << 16);
    
    // Fetch the lower 1/2 of the 32-bit value
    longData |= (Uint32)(*GetWordData)();

    return longData;
}

//#################################################
// Uint32 SPI_Boot(void)
//--------------------------------------------
// This module is the main SPI boot routine. 
// It will load code via the SPI-A port.
//
// It will return a entry point address back
// to the ExitBoot routine. 
//--------------------------------------------
                                 
Uint32 SPI_Boot()
{
   Uint32 EntryAddr;
   long tmp;
   Uint16 tmpu;
   // Asign GetWordData to the SPI-A version of the
   // function.  GetWordData is a pointer to a function.
   GetWordData = SPIA_GetWordData;
   // 1. Init SPI-A and set 
   //    EEPROM chip enable - low
   SPIA_Init();
   // 2. Enable EEPROM and send EEPROM Read Command
//t   SPIA_Transmit(0x0300);
	  tmpu = SPIA_Transmit(0xE800); //command 0xe8 + first byte of address
	  tmpu = SPIA_Transmit(0x0000); //address
   	  tmpu = SPIA_Transmit(0x0000); //don't care
   	  tmpu = SPIA_Transmit(0x0000); //don't care
   // 3. Send Starting for the EEPROM address 16bit
   //    Sending 0x0000,0000 will work for address and data packets
 //  tmp = 2l;
//   do{
   tmpu = SPIA_GetWordData();
   tmpu = SPIA_GetWordData();
  // } while(tmp--);
   // 4. Check for 0x08AA data header, else go to flash
  if(SPIA_GetWordData() != 0x08AA) return FLASH_ENTRY_POINT;
   // 5.Check for Clock speed change and reserved words
   SPIA_ReservedFn();     
   // 6. Get point of entry address after load
   EntryAddr = GetLongData();   
   // 7. Receive and copy one or more code sections to  destination addresses 
   CopyData();
   // 8. Disable EEPROM chip enable - high
   //    Chip enable - high  
 //  GpioDataRegs.GPASET.bit.GPIO19 = 1;  //need gpiof3
   GpioDataRegs.GPFSET.bit.GPIOF3 = 1;
   return EntryAddr;
}

//#################################################
// void SPIA_Init(void)
//----------------------------------------------
// Initialize the SPI-A port for communications
// with the host.   
//----------------------------------------------
                 
inline void SPIA_Init()
{
    // Enable SPI-A clocks
    EALLOW;
//t03    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;
    SysCtrlRegs.LOSPCP.all = 0x0002;	
    // Enable FIFO reset bit only
    SpiaRegs.SPIFFTX.all=0x8000;
    // 8-bit character
    SpiaRegs.SPICCR.all = 0x0007;
    // Use internal SPICLK master mode and Talk mode
    SpiaRegs.SPICTL.all = 0x000E; 
    // Use the slowest baud rate
    SpiaRegs.SPIBRR     = 0x007f;
    // Relinquish SPI-A from reset
    SpiaRegs.SPICCR.all = 0x0087;
    // Enable SPISIMO/SPISOMI/SPICLK pins
    // Enable pull-ups on SPISIMO/SPISOMI/SPICLK/SPISTE pins
    // GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;
    // GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;
//t03    GpioCtrlRegs.GPAPUD.all &= 0xFFF0FFFF;                  
    // GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;
//t03    GpioCtrlRegs.GPAMUX2.all |= 0x00000015;
    // SPI-A pins are asynch
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3;        
//t03    GpioCtrlRegs.GPAQSEL2.all |= 0x0000003F;
    // IOPORT as output pin instead of SPISTE
//t03    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
//to03    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
    // Chip enable - low
    //GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;      //need gpiof3
    GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;			// 
    EDIS;
    return;
}

//#################################################
// Uint16 SPIA_Transmit(Uint16 cmdData)
//------------------------------------------------
// Send a byte/words through SPI transmit channel
//------------------------------------------------
                                
inline Uint16 SPIA_Transmit(Uint16 cmdData)
{
    Uint16 recvData;
    // Send Read command/dummy word to EEPROM to fetch a byte
    SpiaRegs.SPITXBUF = cmdData;                  
    while( (SpiaRegs.SPISTS.bit.INT_FLAG) !=1);
    // Clear SPIINT flag and capture received byte
    recvData = SpiaRegs.SPIRXBUF;     		 
    return recvData;  
}

//#################################################
// void SPIA_ReservedFn(void)
//-------------------------------------------------
// This function reads 8 reserved words in the header. 
// The first word has parameters for LOSPCP 
// and SPIBRR register 0xMSB:LSB, LSB = is a three 
// bit field for LOSPCP change MSB = is a 6bit field 
// for SPIBRR register update 
// 
// If either byte is the default value of the register 
// then no speed change occurs.  The default values 
// are LOSPCP = 0x02 and SPIBRR = 0x7F 
// The remaining reserved words are read and discarded 
// and then returns to the main routine. 
//-------------------------------------------------
                              
inline void SPIA_ReservedFn()
{
    Uint16 speedData;
    Uint16 i;
     Uint16 tmpu;
    
    // update LOSPCP register
    speedData = SPIA_Transmit((Uint16)0x0000);
    EALLOW;
//t    SysCtrlRegs.LOSPCP.all = speedData;	
    EDIS;
    asm("	RPT #0x0F ||NOP");     
    
    // update SPIBRR register 
    speedData = SPIA_Transmit((Uint16)0x0000);  
//t    SpiaRegs.SPIBRR  = speedData;
    asm("	RPT #0x0F ||NOP"); 

    // Read and discard the next 7 reserved words.
   
    for(i = 1; i <= 7; i++)
    {
       tmpu = SPIA_GetWordData();
    }
    return;
}

//#################################################
// Uint16 SPIA_GetWordData(void)
//-----------------------------------------------
// This routine fetches two bytes from the SPI-A
// port and puts them together to form a single
// 16-bit value.  It is assumed that the host is
// sending the data in the form MSB:LSB.
//-----------------------------------------------

Uint16 SPIA_GetWordData()
{
   Uint16 wordData;
   // Fetch the LSB
   wordData =  SPIA_Transmit(0x0000);
   // Fetch the MSB
   wordData |= (SPIA_Transmit(0x0000) << 8);
   return wordData;
}


