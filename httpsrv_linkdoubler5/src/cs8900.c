//------------------------------------------------------------------------------
// Name: cs8900.c
// Func: ethernet driver for use with LAN controller CS8900A
// Ver.: 1.1
// Date: January 2004
// Auth: Andreas Dannenberg
//       MSP430 Applications
//       Texas Instruments Inc.
// Rem.: -
//------------------------------------------------------------------------------

//t#include "msp430x14x.h"
#include "support.h"
#include "cs8900.h"
#include "Expert.h"
//------------------------------------------------------------------------------
//unsigned int P3DIR, P3OUT, P5DIR, P5IN, P5OUT; //to test
//#ifdef __cplusplus
//#pragma CODE_SECTION("Cs8900Funcs")
//#else
//#pragma CODE_SECTION(DelayCycles, "Cs8900Funcs")
//#endif
//void DelayCycles(unsigned int Count)//to test
//{//test
//	do
//	{
//	  Count--;
//	}
//	while(Count)
	
//to test
//}//test
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(wait_ms, "Cs8900Funcs")
#endif
 void _wait_ms(unsigned long val)//test
{
//	unsigned long tmp = 40l; //to test
	    val *= 1005l; //to have value in ms: 1 val = 1 ms
		GpioDataRegs.GPBSET.all = 0x0080; //set data gpiob7
		do ResetWD();
		while(val--);
		GpioDataRegs.GPBCLEAR.all = 0x0080; //clear data gpiob7
	//	do ResetWD();
//	while(tmp--);//to test
}

#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(WriteDWBE, "Cs8900Funcs")
#endif
//t void WriteDWBE(unsigned char *Add, unsigned long Data)//test
 void WriteDWBE(unsigned int *Add, unsigned long Data)//test
{//test
  *Add = Data >> 24;
  *Add++ |= (Data >> 8) & 0xff00;
  *Add = (Data >> 8) & 0xff;
  *Add |= (Data & 0xff) << 8;
}//test
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(__swap_bytes, "Cs8900Funcs")
#endif
unsigned int __swap_bytes(unsigned int swb)
{
	unsigned int tmp = swb & 0xff;
	swb >>= 8;
	swb |= tmp << 8; 
	
//test
return swb;
}
//_______________________________
//const unsigned int MyMAC[] =                     // "M1-M2-M3-M4-M5-M6"
unsigned int MyMAC[] =
{

  MYMAC_1 + (unsigned int)(MYMAC_2 << 8),
  MYMAC_3 + (unsigned int)(MYMAC_4 << 8),
  MYMAC_5 + (unsigned int)(MYMAC_6 << 8)
};

static const TInitSeq InitSeq[] =
{
  PP_IA, MYMAC_1 + (MYMAC_2 << 8),               // set our MAC as Individual Address
  PP_IA + 2, MYMAC_3 + (MYMAC_4 << 8),
  PP_IA + 4, MYMAC_5 + (MYMAC_6 << 8),
  PP_LineCTL, SERIAL_RX_ON | SERIAL_TX_ON,       // configure the Physical Interface
  PP_RxCTL, RX_OK_ACCEPT | RX_IA_ACCEPT | RX_BROADCAST_ACCEPT,
  PP_TxCommand, TX_START_ALL_BYTES | TX_RUNT //not pad to 60 bits //my
  //PP_TxCommand, TX_START_ALL_BYTES  //pad to 60 bits //my
};
//------------------------------------------------------------------------------
// configure port-pins for use with LAN-controller,
// issue reset and send the configuration-sequence (InitSeq[])
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(Init2200, "Cs8900Funcs")
#endif
void Init2200(void)
{
//u8_t temp; 
unsigned char temp;
unsigned char uip_addr[6];
unsigned long wd;
//IT0 = FALSE; // Make /INT0 level triggered
//Link_Connected = FALSE; // Reset the status of the ethernet link
//CP2200_Active = FALSE; // Clear the result of ocsillator and reset bits
//CP2200_Osc_Ready = FALSE; // Ocsillator ready bits 

//SFRPAGE = CONFIG_PAGE; // Switch to ports SFR page
// Turn on the red LED during initialistation
//P4 |= AB4_LED1; // Green AB4 Board LED
// AB4_LED1 = TRUE; // Green AB4 Board LED 


// After every CP2200/1 reset, the following initialization procedure is recommended
// to ensure proper device operation:- 

// Step 1: Reset the CP2200. Wait for the reset pin to rise.
// This step takes the longest during a power-on reset. 

//P4 &= ~0x20; // Pull CP2200 reset pin low 
ExpertRegs.XILR2 = 0;
//for(;;)
_wait_ms(5); 

ExpertRegs.XILR2 = 2;
//P4 |= 0x20; // Allow reset pin to rise 

_wait_ms(100); 

//while(!(P4 & 0x20)); // Read state of /RST pin 


// Step 1a: Set Chip Select pin (or A15 on EMIF) 

//P5 = 0x20; // P5.7 

//SFRPAGE = LEGACY_PAGE; // Switch to ports SFR page 

// Turn on the Vdd monitor flag
//for(;;)
//{
//CP2200regs.VDMCN = 0x55; //to test
//CP2200regs.VDMCN = 0xAA; //to test
//ResetWD();
//}

CP2200regs.VDMCN |= VDMEN; 

CP2200regs.OSCPWR |= 0x01; 

wd = 100000l; //temp

//do ResetWD();
//for(;;)
//temp = CP2200regs.FLASHSTA;

while((CP2200regs.FLASHSTA & 0x08) && (wd--)); 

// Step 2: Wait for Oscillator Initialization to complete. The host processor will
// receive notification through the interrupt request signal once the
// oscillator has stabilized. Use INT0RD to avoid clearing self-initialisation bit 

// Step 3: Wait for Self Initialization to complete. The INT0 interrupt status register
// on page 30 should be checked to determine when Self Initialization completes.
// This will clear any pending interrupt. 
wd = 100000l; //temp
//for(;;)
//temp = CP2200regs.INT0RD;
while ((!(CP2200regs.INT0RD & OSCINT)) && (wd--)); 
wd = 100000l; //temp
while((!(CP2200regs.INT0 & SELFINTR)) && (wd--)); 

// Step 4: Disable interrupts (using INT0EN and INT1EN on page 32 and page 35) for events
// that will not be monitored or handled by the host processor.
// By default, all interrupts are enabled after every reset.
// Bit values in INT0EN
//#define EEOPINT 0x80 // Enable End of Packet Interrupt.
//#define ERXEINT 0x40 // Enable Receive FIFO Empty Interrupt.
//#define ESELFINT 0x20 // Enable Self Initialization Complete Interrupt.
//#define EOSCINT 0x10 // Enable Oscillator Initialization Complete Interrupt.
//#define EFLWEINT 0x08 // Enable Flash Write/Erase Operation Complete Interrupt.
//#define ETXINT 0x04 // Enable Packet Transmitted Interrupt.
//#define ERXFINT 0x02 // Enable Receive FIFO Full Interrupt.
//#define ERXINT 0x01 // Enable Packet Received Interrupt.
// Bit values in INT1EN
//#define EWAKEINT 0x20 // Enable “Wake-on-Lan” Interrupt.
//#define ELINKINT 0x10 // Enable Link Status Changed Interrupt.
//#define EJABINT 0x08 // Enable Jabber Detected Interrupt.
//#define EANFINT 0x04 // Enable Auto-Negotiation Failed Interrupt.
//#define ERFINT 0x02 // Enable Remote Fault Interrupt.
//#define EANCINT 0x01 // Enable Auto-Negotiation Complete Interrupt. 

CP2200regs.INT0EN = (ETXINT | ERXINT);
CP2200regs.INT0EN = (0x00); 

// Enable software and power fail resets
CP2200regs.RSTEN = (ESWRST | EPFRST); 

// Auto-Negotiation Complete
// An auto-negotiation attempt has completed. This interrupt
// only indicates completion, and not success. Occasionally,
// Auto-Negotiation attempts will not complete
// and/or fail; therefore, a 3 to 4 second timeout should be
// implemented. A successful auto-negotiation attempt is
// one that completes without failure. 

CP2200regs.INT0EN = (EFLWEINT | ETXINT | ERXFINT | ERXINT);
CP2200regs.INT1EN = (ELINKINT | EJABINT | ERFINT); 

// Step 5: Enable the desired Activity, Link, or Activity/Link LEDs using the IOPWR register
// on page 44. Note that separate link/activity LEDs are only available on 48-pin devices. 

CP2200regs.IOPWR = (ACTEN | LINKEN); 

// Step 6: Initialize the physical layer. See “15.6. Initializing the Physical Layer” on page 88
// for a detailed physical layer initialization procedure. 

// The physical layer should be configured to the desired mode before
// setting the enable bit PHYEN (PHYCN.7). 

// The following procedure should be used to initialize the physical layer: 

// Step 6a: Specify the Duplex Mode or enable Auto-Negotiation.
// Auto-Negotiation
// Important Note:
// When using auto-negotiation, the auto-negotiation enable bit,
// AUTONEG (PHYCF.4), must be set to “1” prior to setting PHYEN,
// TXEN, and RXEN to 1. To restart auto-negotiation, clear one
// of the three enable bits (PHYEN, TXEN, and RXEN) to “0” then
// set it back to “1”. 

CP2200regs.PHYCF = AUTONEG; // Auto-negotiate and polarity detection 

// Step 6b: Enable or Disable Loopback Mode in PHYCN.
// Disabled is default 

// Step 6c: Enable the desired functions such as Receiver Smart Squelch,
// Automatic Polarity Correction, Link Integrity, Jabber Protection,
// Remote Fault Advertisement, and PAUSE packet capability advertisement.
// Not required 

// Step 6d: If Automatic Polarity Correction is disabled, manually set the desired polarity.
// Automatic Polarity Correction is Enabled
_wait_ms(2);
//CP2200regs.PHYCF |= (SMSQ | LINKINTEG | JABBER | ADRFAULT | ADPAUSE | AUTOPOL); 
CP2200regs.PHYCF |= (SMSQ | LINKINTEG | JABBER |  ADPAUSE | AUTOPOL); 

// Step 6e: Enable the physical layer (PHYEN = 1), transmitter, and receiver.
_wait_ms(1);
CP2200regs.PHYCN |= PHYEN; 

// Step 6f: Wait 1 microsec. Wait the appropriate physical layer startup time
// specified in Table 22 on page 91. 

_wait_ms(1); 

// Step 6g: Enable the transmitter and receiver (TXEN = 1 and RXEN = 1). 

 CP2200regs.PHYCN |= (TXEN | RXEN); 
//CP2200regs.PHYCN |= (TXEN | RXEN | DPLXMD); 
//CP2200regs.RXFILT = 0;
// Step 6h: Wait the appropriate physical layer startup time,
// and wait for Auto-Negotiation (if enabled) to complete. 

 _wait_ms(5);
// while(CP2200regs.PHYSTA != 0x00); 

// Step 6i: Wait at least 75 ms for a link to be established. 

_wait_ms(200);
wd = 10000l; //temp
while((!(CP2200regs.PHYCN & LINKSTA)) && (wd--)); 

// Step 7: Initialize the media access controller (MAC). See “14.1. Initializing the MAC”
// on page 77 for a detailed MAC initialization procedure.
// Most MAC indirect registers can be left at their reset values. 

// Step 7a: Determine if the physical layer is set to full-duplex or half-duplex.
// The MAC must be set to the same duplex mode as the physical layer
// before sending or receiving any packets. 

temp = CP2200regs.PHYCN; 

// Step 7b: Write 0x00B3 (full-duplex) or 0x00B2 (half-duplex) to MACCF.
// The appropriate bits in this register may also be set or cleared
// to change padding options or MAC behavior. 

CP2200regs.MACADDR = MACCF;
CP2200regs.MACDATAL = (temp & DPLXMD) ? 0xb3 : 0xb2;
CP2200regs.MACDATAH = 0x00;
CP2200regs.MACRW = 0x01; 

// Step 7c: Write 0x0015 (full-duplex) or 0x0012 (half-duplex) to IPGT. 

CP2200regs.MACADDR = IPGT;
CP2200regs.MACDATAL = (temp & DPLXMD) ? 0x15 : 0x12;
CP2200regs.MACDATAH = 0x00;
CP2200regs.MACRW = 0x01; 

// Step 7d: Write 0x0C12 to IPGR. 

CP2200regs.MACADDR = IPGR;
CP2200regs.MACDATAL = 0x12;
CP2200regs.MACDATAH = 0x0C;
CP2200regs.MACRW = 0x01; 



// Step 7e: Program the 48-bit Ethernet MAC Address by writing to MACAD0:MACAD1:MACAD2.
// Set Node address 6 bytes from MCU FLASH (if valid and different from
// MAC address in CP2200). Otherwise read MAC from CP2200. 

//if (tmp_security_params.valid_flash != FLASH_VALID)
if (1)
{
// Set CP2200 Flash address regs to last 6 bytes containing factory set MAC address 

CP2200regs.FLASHADDRH = 0x1F;
CP2200regs.FLASHADDRL = 0xFA;
// Perform reversal for correct byte order
for (temp = 6; temp > 0; )
{
temp--;
//tmp_NIC_params.mac.addr[temp],uip_ethaddr.addr[temp] = CP2200regs.FLASHAUTORD;
	uip_addr[temp] = CP2200regs.FLASHAUTORD;
} 
}
CP2200regs.MACADDR = MACAD0;
CP2200regs.MACDATAL = uip_addr[1];
CP2200regs.MACDATAH = uip_addr[0];
CP2200regs.MACRW = 0x01;
CP2200regs.MACADDR = MACAD1;
CP2200regs.MACDATAL = uip_addr[3];
CP2200regs.MACDATAH = uip_addr[2];
CP2200regs.MACRW = 0x01;
CP2200regs.MACADDR = MACAD2;
CP2200regs.MACDATAL = uip_addr[5];
CP2200regs.MACDATAH = uip_addr[4];
CP2200regs.MACRW = 0x01; 

MyMAC[0] = uip_addr[5] + (unsigned int)(uip_addr[4] << 8);
MyMAC[1] = uip_addr[3] + (unsigned int)(uip_addr[2] << 8);
MyMAC[2] = uip_addr[1] + (unsigned int)(uip_addr[0] << 8);


// Step 7f: Write 0x0001 to MACCN to enable reception.
// If loopback mode or flow control is desired, set the appropriate bits
// to enable these functions. 

CP2200regs.MACADDR = MACCN;
CP2200regs.MACDATAL = 0x01;
CP2200regs.MACDATAH = 0x00;
CP2200regs.MACRW = 0x01; 

// Step 8: Configure the receive filter. See “12.3. Initializing the Receive Buffer,
// Filter and Hash Table” on page 57 for a detailed initialization procedure.
// Normally no additional initialisation is normally necessary 

// Other housekeeping arrangements
// Clear any interrupts pending
temp = CP2200regs.INT0;
temp = CP2200regs.INT1;
CP2200regs.RXCN = RXCLEAR; 
//CP2200regs.RXCN = 0x07;
//RX_Length = 0; 
//TX_EventPending = FALSE; // False to poll the CP220x receive hardware
//ARP_EventPending = FALSE; // clear the arp timer event flag 


// Turn off the Red LED after initialistation
//SFRPAGE = CONFIG_PAGE; // Switch to ports SFR page
//P4 &= ~AB4_LED1; // Green AB4 Board LED
//SFRPAGE = LEGACY_PAGE; // Restore to SFR page 0 after H/W init
// Step 9: The CP2200/1 is ready to transmit and receive packets. 

//return FALSE;
}
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(Init8900, "Cs8900Funcs")
#endif
void Init8900(void)
{
  unsigned int i;
 //t unsigned long TimeOut = 1000l; 	   // temporary 1000
	 unsigned long TimeOut = 10000l;
//t P3OUT = IOR | IOW;                             // reset outputs, control lines high
//t  P3DIR = 0xff;                                  // switch control port to output

//t P5OUT = 0;                                     // reset outputs
//t P5DIR = 0xff;                                  // switch data port to output
  ExCs8900.DATA0 = 0;	//to change using P5
  ExCs8900.DATA1 = 0;	//to change using P5
  
 //t DelayCycles(40000);                            // delay 10ms @ 8MHz MCLK to allow
 //tDelayCycles(40000);                            // time for CS8900 POR

  Write8900(ADD_PORT, PP_SelfCTL);               // set register
  Write8900(DATA_PORT, POWER_ON_RESET);          // reset the Ethernet-Controller
  
  do
  {
    Write8900(ADD_PORT, PP_SelfST);              // set register
    TimeOut--;
  }
//  while (!(Read8900(DATA_PORT) & INIT_DONE));    // wait until chip-reset is done
  while ((!(Read8900(DATA_PORT) & INIT_DONE)) && TimeOut);    // wait until chip-reset is done
  
  for (i = 0; i < sizeof InitSeq / sizeof (TInitSeq); i++) // configure the CS8900
  {
    Write8900(ADD_PORT, InitSeq[i].Addr);
 //   MDelay(10000l);
    Write8900(DATA_PORT, InitSeq[i].Data);
 //   MDelay(10000l);
  }
}
//------------------------------------------------------------------------------
// writes a word in little-endian byte order to
// a specified port-address
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(Write8900, "Cs8900Funcs")
#endif
void Write8900(unsigned char Address, unsigned int Data)
{

//  P5DIR = 0xff;                                  // data port to output
//  P3OUT = IOR | IOW | Address;                   // put address on bus
//  P5OUT = Data;                                  // write low order byte to data bus
//  P3OUT &= ~IOW;                                 // toggle IOW-signal
//  P3OUT = IOR | IOW | (Address + 1);             // and put next address on bus
//  P5OUT = Data >> 8;                             // write high order byte to data bus
//  P3OUT &= ~IOW;                                 // toggle IOW-signal
//  P3OUT |= IOW;
	switch(Address)
	{
	case TX_CMD_PORT :
						ExCs8900.CMD0 = Data;
						ExCs8900.CMD1 = Data >> 8; break;
	case TX_LEN_PORT :
						ExCs8900.LEN0 = Data;
						ExCs8900.LEN1 = Data >> 8; break;
	case ADD_PORT :
						ExCs8900.ADD0 = Data;
						ExCs8900.ADD1 = Data >> 8; break;
	case DATA_PORT :
						ExCs8900.DATA0 = Data;
						ExCs8900.DATA1 = Data >> 8; 
						break;																		
	default			:	break;						
	}
}
//------------------------------------------------------------------------------
// writes a word in little-endian byte order to TX_FRAME_PORT
//------------------------------------------------------------------------------
//#ifdef __cplusplus
//#pragma CODE_SECTION("Cs8900Funcs")
//#else
//#pragma CODE_SECTION(WriteFrame8900, "Cs8900Funcs")
//#endif
//void WriteFrame8900(unsigned int Data)
//{
//  P5DIR = 0xff;                                  // data port to output
//  P3OUT = IOR | IOW | TX_FRAME_PORT;             // put address on bus
//  P5OUT = Data;                                  // write low order byte to data bus
//  P3OUT &= ~IOW;                                 // toggle IOW-signal
//  P3OUT = IOR | IOW | (TX_FRAME_PORT + 1);       // and put next address on bus
//  P5OUT = Data >> 8;                             // write high order byte to data bus
//  P3OUT &= ~IOW;                                 // toggle IOW-signal
//  P3OUT |= IOW;
//}
//------------------------------------------------------------------------------
// copies bytes from MCU-memory to frame port
// NOTES:     * MCU-memory MUST start at word-boundary
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(CopyToFrame8900, "Cs8900Funcs")
#endif
void CopyToFrame8900(void *Source, unsigned int Size)
{
  unsigned int *pSource = Source;
  unsigned int tmp, temp, i;
// P5DIR = 0xff;                                  // data port to output
 //Size <<= 1;//to test!!!!
 unsigned long wd = 10000l; 
 //GpioDataRegs.GPBSET.all = 0x0080;
// while((CP2200regs.TXBUSY) && (wd--));
//MDelay(10l);
// tmp = CP2200regs.TXSTA2;
// if(!(tmp & TX_OK2))
if(!(CP2200regs.TXSTA2 & TX_OK2))
 {
 //temp = CP2200regs.PHYCN; 
 //CP2200regs.MACADDR = MACCF;
// CP2200regs.MACDATAL = (temp & DPLXMD) ? 0xb3 : 0xb2;
// CP2200regs.MACDATAH = 0x00;
// CP2200regs.MACDATAH = 0x40;
// CP2200regs.MACDATAH = 0x00;
// CP2200regs.MACRW = 0x01; 
// CP2200regs.PHYCN &= ~(TXEN);
// CP2200regs.PHYCN |= TXEN;
//Init2200();
CP2200regs.TXSTARTH = 0;
// MDelay(10l);
 CP2200regs.TXSTARTL = 0;
// MDelay(10l);
 //CP2200regs.RAMADDRH = 0;
// MDelay(10l);
// CP2200regs.RAMADDRL = 0;
CP2200regs.TXCN = TXGO2;
//while(CP2200regs.TXBUSY);// && (wd--));
//MDelay(10000l);
}

 
CP2200regs.TXSTARTH = 0;
// MDelay(10l);
CP2200regs.TXSTARTL = 0;
//CP2200regs.TXSTARTL = 0;
//CP2200regs.TXSTARTL = 0;
//CP2200regs.TXSTARTL = 0;
// MDelay(10000l);
 CP2200regs.RAMADDRH = 0;
// MDelay(10l);
 CP2200regs.RAMADDRL = 0;
// CP2200regs.TXSTARTH = 0;
// MDelay(10l);
 //CP2200regs.TXSTARTL = 0;
// MDelay(10l);
// CP2200regs.RAMADDRH = 0;
// MDelay(10l);
// CP2200regs.RAMADDRL = 0;
// _wait_ms(1);
// tCP2200regs.TXENDL = (Size -1) & 0xff;
//t CP2200regs.TXENDH = ((Size - 1) >> 8) & 0xff;
 //if((*pSource & 0xff) == 0x00)
 //{
 //for(;;)
 //{
 //}
 //}
// CP2200regs.TXAUTOWR = *pSource;
 // CP2200regs.TXSTARTH = 0;
// MDelay(1500l);
 // CP2200regs.TXAUTOWR = ((*pSource++) >> 8);
  //Size-= 2;
// CP2200regs.TXSTARTL = 0;
// MDelay(10l);
 //CP2200regs.RAMADDRH = 0;
// MDelay(10l);
// CP2200regs.RAMADDRL = 0;
//  while (Size > 1)
//long i;
 for (i = Size; i > 1; i-= 2)
  {
//   P3OUT = IOR | IOW | TX_FRAME_PORT;           // put address on bus
//    P5OUT = *pSource; 
//	  MDelay(1l);	 
                          // write low order byte to data bus
//2	  ExCs8900.FR0 = *pSource;
//MDelay(10l);
//	ResetWD();
	CP2200regs.TXAUTOWR = *pSource;// & 0xff;
//	CP2200regs.RAMTXDATA = *pSource & 0xff;
//	if(CP2200regs.RAMADDRL == 0xff)
//	{
//	CP2200regs.RAMADDRH++;
//	CP2200regs.RAMADDRL = 0;
//	}
//	else CP2200regs.RAMADDRL++;
//    P3OUT &= ~IOW;                               // toggle IOW-signal
//    P3OUT = IOR | IOW | (TX_FRAME_PORT + 1);     // and put next address on bus
//    P5OUT = (*pSource++) >> 8;        	           // write high order byte to data bus
   //   MDelay(10l);
      // hier was breack
  //2    ExCs8900.FR1 = (*pSource++) >> 8;
 // CP2200regs.RAMTXDATA = ((*pSource++) >> 8) & 0xff;
 CP2200regs.TXAUTOWR = ((*pSource++) >> 8);// & 0xff;
  // MDelay(10l);
//	if(CP2200regs.RAMADDRL == 0xff)
//	{
//	CP2200regs.RAMADDRH++;
//	CP2200regs.RAMADDRL = 0;
//	}
//	else CP2200regs.RAMADDRL++;
//    P3OUT &= ~IOW;                               // toggle IOW-signal
//    P3OUT |= IOW;
      Size -= 2;
  }
  
  if (Size)                                      // if odd num. of bytes...
  {
//    P3OUT = IOR | IOW | TX_FRAME_PORT;           // put address on bus
//    P5OUT = *pSource;                            // write byte to data bus
//    P3OUT &= ~IOW;                               // toggle IOW-signal
//    P3OUT |= IOW;
//2	  ExCs8900.FR0 = *pSource;
//	  CP2200regs.RAMTXDATA = *pSource & 0xff;
	  	CP2200regs.TXAUTOWR = *pSource;// & 0xff;
  }
 // MDelay(100l);
// CP2200regs.RAMADDRH = 0;
// MDelay(10l);
// CP2200regs.RAMADDRL = 0;
 // CP2200regs.TXSTARTH = 0; //as in data sheet
//  MDelay(10l);
 // CP2200regs.TXSTARTL = 0;
//t  CP2200regs.RAMADDRH = 0;
// MDelay(10l);
//t CP2200regs.RAMADDRL = 0;
  CP2200regs.TXSTARTH = 0; //as in data sheet
//  MDelay(10l);
  CP2200regs.TXSTARTL = 0;
  //  CP2200regs.TXSTARTH = 0; //as in data sheet
//  MDelay(10l);
 // CP2200regs.TXSTARTL = 0;
  //  CP2200regs.TXSTARTH = 0; //as in data sheet
//  MDelay(10l);
//  CP2200regs.TXSTARTL = 0;
 // CP2200regs.TXSTARTL = 0;
  MDelay(20l);
//  tmp = CP2200regs.INT0; //clear interrupt
  CP2200regs.TXCN = TXGO2; //all enover bits are overriden
 // tmp1 = CP2200regs.INT0RD & 0xff;
 MDelay(20l); 
// while(!(CP2200regs.INT0RD && TXINTR2));
//do{ResetWD();}
//while(CP2200regs.TXBUSY);
//GpioDataRegs.GPBCLEAR.all = 0x0080;
}
//------------------------------------------------------------------------------
// reads a word in little-endian byte order from
// a specified port-address
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(Read8900, "Cs8900Funcs")
#endif
unsigned int Read8900(unsigned char Address)
{
  unsigned int ReturnValue = 0;

//  P5DIR = 0x00;                                  // data port to input
//  P3OUT = IOR | IOW | Address;                   // put address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue = P5IN;                            // get low order byte from data bus
	ReturnValue = ExCs8900.DATA0 & 0xff;
//  P3OUT = IOR | IOW | (Address + 1);             // IOR high and put next address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue |= P5IN << 8;                      // get high order byte from data bus
	ReturnValue |= (((unsigned int)(ExCs8900.DATA1)) & 0xff) << 8;
//  P3OUT |= IOR;
//  P5DIR = 0xff;                                  // data port to output
  
  return ReturnValue;
}
//------------------------------------------------------------------------------
// reads a word in little-endian byte order from RX_FRAME_PORT
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(ReadFrame8900, "Cs8900Funcs")
#endif
unsigned int ReadFrame8900(void)
{
  unsigned int ReturnValue;

//  P5DIR = 0x00;                                  // data port to input
//  P3OUT = IOR | IOW | RX_FRAME_PORT;             // access to RX_FRAME_PORT
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue = P5IN;                            // get 1st byte from data bus (low-byte)
//2  ReturnValue = ExCs8900.FR0 & 0xff;
//MDelay(20l); 
	ReturnValue = CP2200regs.RXAUTORD & 0xff;
//  P3OUT = IOR | IOW | (RX_FRAME_PORT + 1);       // IOR high and put next address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//2  ReturnValue |= (unsigned int)(ExCs8900.FR1 & 0xff) << 8;                      // get 2nd byte from data bus (high-byte)
 //MDelay(20l); 
   ReturnValue |= (unsigned int)(CP2200regs.RXAUTORD & 0xff) << 8;                      // get 2nd byte from data bus (high-byte)
  
//  P3OUT |= IOR;
//  P5DIR = 0xff;                                  // data port to output
  
  return ReturnValue;
}
//------------------------------------------------------------------------------
// reads a word in big-endian byte order from RX_FRAME_PORT
// (useful to avoid permanent byte-swapping while reading
// TCP/IP-data)
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(ReadFrameBE8900, "Cs8900Funcs")
#endif
unsigned int ReadFrameBE8900(void)
{
  unsigned int ReturnValue;

//  P5DIR = 0x00;                                  // data port to input
//  P3OUT = IOR | IOW | RX_FRAME_PORT;             // access to RX_FRAME_PORT
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue = P5IN << 8;                       // get 1st byte from data bus (high-byte)
 //2 ReturnValue = (unsigned int)(ExCs8900.FR1 & 0xff);// << 8;
 //MDelay(20l); 
 	ReturnValue = CP2200regs.RXAUTORD & 0xff;
 	ReturnValue <<= 8;
//  P3OUT = IOR | IOW | (RX_FRAME_PORT + 1);       // IOR high and put next address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue |= P5IN;                           // get 2nd byte from data bus (low-byte)
 //2 ReturnValue |= (unsigned int)(ExCs8900.FR0 & 0xff) << 8;
 //MDelay(20l); 
 		ReturnValue |= CP2200regs.RXAUTORD & 0xff;
//  P3OUT |= IOR;
//  P5DIR = 0xff;                                  // data port to output
  
  return ReturnValue;
}
//------------------------------------------------------------------------------
// reads a word in little-endian byte order from
// a specified port-address
// NOTE: this func. xfers the high-byte 1st, must be used to
//       access some special registers (e.g. RxStatus)
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(ReadHB1ST8900, "Cs8900Funcs")
#endif
unsigned int ReadHB1ST8900(unsigned char Address)
{
  unsigned int ReturnValue;

//  P5DIR = 0x00;                                  // data port to input
//  P3OUT = IOR | IOW | (Address + 1);             // put address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue = P5IN << 8;                       // get high order byte from data bus
//  ReturnValue = (unsigned int)(ExCs8900.FR0) << 8;
//  ReturnValue = (unsigned int)(ExCs8900.FR1) << 8;  
//  P3OUT = IOR | IOW | Address;                   // IOR high and put next address on bus
//  P3OUT &= ~IOR;                                 // IOR-signal low
//  ReturnValue |= P5IN;                           // get low order byte from data bus
//  ReturnValue |= (unsigned int)(ExCs8900.FR1);
    //ReturnValue |= (unsigned int)(ExCs8900.FR0);  
 //   ReturnValue = (unsigned int)((ExCs8900.FR0) & 0xff);  
  //  MDelay(100l);
//  P3OUT |= IOR;
//  P5DIR = 0xff;                                  // data port to output
 //2  ReturnValue = (unsigned int)((ExCs8900.FR1) & 0xff) << 8;  
 //2   ReturnValue |= (unsigned int)((ExCs8900.FR0) & 0xff); 
// MDelay(2l); 
 	ReturnValue = (unsigned int)(CP2200regs.RXAUTORD & 0xff);
 //	MDelay(2l); 
    ReturnValue |= (unsigned int)(CP2200regs.RXAUTORD & 0xff) << 8;                      // get 2nd byte from data bus (high-byte)
   
  return ReturnValue;
}
//------------------------------------------------------------------------------
// copies bytes from frame port to MCU-memory
// NOTES:     * MCU-memory MUST start at word-boundary
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(CopyFromFrame8900, "Cs8900Funcs")
#endif
void CopyFromFrame8900(void *Dest, unsigned int Size)
{
  unsigned int *pDest = Dest;
  unsigned int tmp;

 // P5DIR = 0x00;                                  // data port to input

  while (Size > 1)
  {
    //P3OUT = IOR | IOW | RX_FRAME_PORT;           // access to RX_FRAME_PORT
   // P3OUT &= ~IOR;                               // IOR-signal low
   // *pDest = P5IN;                               // get 1st byte from data bus (low-byte)
//	*pDest = ExCs8900.FR0;
// MDelay(20l); //? need?
//2	*pDest = (ExCs8900.FR0 & 0xff);	
	tmp = CP2200regs.RXAUTORD & 0xff;
	*pDest = tmp;//(unsigned int)(tmp & 0xff);
   // P3OUT = IOR | IOW | (RX_FRAME_PORT + 1);     // IOR high and put next address on bus
   // P3OUT &= ~IOR;                               // IOR-signal low
   // *pDest++ |= P5IN << 8;                       // get 2nd byte from data bus (high-byte)
// MDelay(20l);
 	tmp = CP2200regs.RXAUTORD & 0xff;
 //2      *pDest++ |= (unsigned int)((ExCs8900.FR1) & 0xff) << 8;
  *pDest += tmp << 8;//((unsigned int)(tmp & 0xff)) << 8;
  //  P3OUT |= IOR;
  pDest++;
    Size -= 2;
  }
  
  if (Size)                                      // check for leftover byte...
  {
  //  P3OUT = IOR | IOW | RX_FRAME_PORT;           // access to RX_FRAME_PORT
  //  P3OUT &= ~IOR;                               // IOR-signal low
  //  *(unsigned char *)pDest = P5IN;              // get byte from data bus
 //2   *(unsigned char *)pDest = ExCs8900.FR0;
  *(unsigned char *)pDest = CP2200regs.RXAUTORD;
  //  P3OUT |= IOR;                                // IOR high
  }

 // P5DIR = 0xff;                                  // data port to output
}
//------------------------------------------------------------------------------
// does a dummy read on the CS8900A frame-I/O-port
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(DummyReadFrame8900, "Cs8900Funcs")
#endif
void DummyReadFrame8900(unsigned int Size)
{
	char tmp;
 // P5DIR = 0x00;                                  // data port to input
//???????????? - need read fr1 ??? or divide size to 2? 
 // while (Size)
 while (Size > 1)
  {
 //   P3OUT = IOR | IOW | RX_FRAME_PORT;           // access to RX_FRAME_PORT
 //   P3OUT &= ~IOR;   
 //   tmp = ExCs8900.DATA0;
//2    tmp = ExCs8900.FR0;
//MDelay(20l);
 	 tmp = CP2200regs.RXAUTORD;
//2    tmp = ExCs8900.FR1;
//MDelay(20l);
	 tmp = CP2200regs.RXAUTORD;
    Size--; 
    Size--;                            // IOR-signal low
  }
    if (Size)                                      // check for leftover byte...
  {
 //2  tmp = ExCs8900.FR0;
 	 tmp = CP2200regs.RXAUTORD;
  }
 // P3OUT |= IOR;                                  // IOR high
 // P5DIR = 0xff;                                  // data port to output
}
//------------------------------------------------------------------------------
// requests space in CS8900 on-chip memory for
// storing an outgoing frame
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(RequestSend, "Cs8900Funcs")
#endif
void RequestSend(unsigned int FrameSize)
{
 // Write8900(TX_CMD_PORT, TX_START_ALL_BYTES);
  //Write8900(TX_LEN_PORT, FrameSize);
  //need make request to send 2200:
  //for 2200 not need some!!!!
}
//------------------------------------------------------------------------------
// check if CS8900 is ready to accept the
// frame we want to send
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(Rdy4Tx, "Cs8900Funcs")
#endif
unsigned int Rdy4Tx(void)
{
 // Write8900(ADD_PORT, PP_BusST);
 //to get 2200 return Read8900(DATA_PORT) & READY_FOR_TX_NOW;
  //for 2200:
  unsigned int ret = 1;
 // if(!(CP2200regs.TXSTA2 & TX_OK2))
 if(0)
 {
 //temp = CP2200regs.PHYCN; 
 //CP2200regs.MACADDR = MACCF;
// CP2200regs.MACDATAL = (temp & DPLXMD) ? 0xb3 : 0xb2;
// CP2200regs.MACDATAH = 0x00;
// CP2200regs.MACDATAH = 0x40;
// CP2200regs.MACDATAH = 0x00;
// CP2200regs.MACRW = 0x01; 
// CP2200regs.PHYCN &= ~(TXEN);
// CP2200regs.PHYCN |= TXEN;
//Init2200();
CP2200regs.TXSTARTH = 0;
// MDelay(10l);
 CP2200regs.TXSTARTL = 0;
// MDelay(10l);
 //CP2200regs.RAMADDRH = 0;
// MDelay(10l);
// CP2200regs.RAMADDRL = 0;
CP2200regs.TXCN = TXGO2;
//while(CP2200regs.TXBUSY);// && (wd--));
//MDelay(10000l);
 ret = 0;
}
  if((CP2200regs.RXSTA & RXBUSY2) || (CP2200regs.TXBUSY & TXBUSY2)) ret = 0; 
 // return (~(CP2200regs.TXBUSY | 0xfe));//TxBusy
 return ret;

}

#ifdef __cplusplus
#pragma CODE_SECTION("Cs8900Funcs")
#else
#pragma CODE_SECTION(RdyEvTx, "Cs8900Funcs")
#endif
unsigned int RdyEvTx(void)
{
 // Write8900(ADD_PORT, PP_TxEvent);
  //return Read8900(DATA_PORT) & TX_OK;
  return CP2200regs.TXSTA2 & TXOK2;
  
}