/**********************************************************************
* File: main_nonBIOS.c
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: David M. Alter, Texas Instruments Inc.
* History:
*   09/08/03 - original (based on DSP281x header files v1.00, D. Alter)
**********************************************************************/

#include "DSP281x_Device.h"				// Peripheral address definitions
#include "example_nonBIOS.h"
#include "test.h"
#include "DSP281x_CpuTimers.h" 
#include "support.h"
#include "easyweb.h"
#include "tcpip.h"                               // easyWEB TCP/IP stack
#include "webside.c"                             // webside for our HTTP server (HTML)

//unsigned long t;
//#ifdef __cplusplus 
//#pragma DATA_SECTION("MenuFile") 
//#else
//#pragma DATA_SECTION(GetResponse,"MenuFile");
//#endif
//!!!!!!!!!!!!!!!!why send const - to data????????????????????????
//#ifdef __cplusplus 
//#pragma DATA_SECTION("MenuFileD") 
//#else
//#pragma DATA_SECTION(GetResponse,"MenuFileD");
//#endif
static const unsigned char GetResponse[] =       // 1st thing server sends to a client
{
  "HTTP/1.0 200 OK\r\n"                          // protocol ver 1.0, code 200, reason OK
 // "Content-Length:4456\r\n"
  "Content-Type: text/html\r\n"                  // type of data we want to send
  "\r\n"                                         // indicate end of HTTP-header
};

static unsigned char *PWebSide;                  // pointer to webside
//static unsigned int *PWebSide;                  // pointer to webside
//unsigned char *PWebSide; //t                 // pointer to webside
static unsigned int HTTPBytesToSend;             // bytes left to send
//unsigned int HTTPBytesToSend;             // bytes left to send
static unsigned char HTTPStatus;                 // status byte
//------------------------------------------------------------------------------
// samples and returns the AD-converter value of channel 7
// (associated with Port P6.7)
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetAD7Val, "ExtFuncs")
#endif
static unsigned int GetAD7Val(void)
{
 // ADC12MCTL0 = SREF_1 + INCH_7;                  // Select channel 7, Vref+
  
 // ADC12CTL0 |= ENC;                              // enable conversion
 // ADC12CTL0 |= ADC12SC;                          // sample & convert
  
//  while (ADC12CTL0 & ADC12SC);                   // wait until conversion is complete
  
//  ADC12CTL0 &= ~ENC;                             // disable conversion

  return 5;                         // Scale value
}
//------------------------------------------------------------------------------
// samples and returns AD-converter value of channel 10
// (MSP430 internal temperature reference diode)
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetTempVal, "ExtFuncs")
#endif
static unsigned int GetTempVal(void)
{
 // unsigned int i;
 // unsigned int ADCResult;

  //ADC12MCTL0 = SREF_1 + INCH_10;                 // Select channel A10, Vref+

 // ADC12CTL0 |= ENC;                              // enable conversion
 // ADC12CTL0 |= ADC12SC;                          // sample & convert
  
 // while (ADC12CTL0 & ADC12SC);                   // wait until conversion is complete
  
 // ADC12CTL0 &= ~ENC;                             // disable conversion

  //ADCResult = ADC12MEM0;                         // Read out ADC12 value

  //for (i = 0; i < sizeof Temp_Tab; i++)          // Get temperature value out
 //   if (ADCResult < Temp_Tab[i])                 // of table
   //   break;

 // return i << 1;                             // Scale value
   return 1; 
}
//------------------------------------------------------------------------------
// searches the TX-buffer for special strings and replaces them
// with dynamic values (AD-converter results)
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("TcpipFuncs")
#else
#pragma CODE_SECTION(InsertDynamicValues, "TcpipFuncs")
#endif
void InsertDynamicValues(void)
//void InsertDynamicValues(void)
{

  char *Key;
  char NewKey[17];
  int i;
  int tmp = TCPTxDataCount >> 1;
  if (TCPTxDataCount < 4) return;                // there can't be any special string
  
  Key = (char *)TCP_TX_BUF;
  
//t  for (i = 0; i < TCPTxDataCount - 3; i++)
  for (i = 0; i < tmp - 3; i++)
  {
  ResetWD();
    if ((*Key & 0xff) == 'B')
     if ((*Key >> 8)  == 'E')
       if ((*(Key + 1) & 0xff)  == 'R')
         if ((*(Key + 1) >> 8)  == ':')
   //t      if (*(Key + 2) == '1')                  // "AD7%"?
 //        if (1)
//            {
//t	sprintf(NewKey, "%11.1f", GetVal(1));  // insert AD converter value
//	sprintf(NewKey, "%6u", (unsigned int)GetVal(1));  // insert AD converter value
           memcpy8((Key + 3), GetVal(1), 11); 
    if ((*Key & 0xff) == 'E')
     if ((*Key >> 8)  == 'R')
       if ((*(Key + 1) & 0xff)  == ':')
         if ((*(Key + 1) >> 8)  == '.')
   //t      if (*(Key + 2) == '1')                  // "AD7%"?
 //        if (1)
//            {
//t	sprintf(NewKey, "%11.1f", GetVal(1));  // insert AD converter value
//	sprintf(NewKey, "%6u", (unsigned int)GetVal(1));  // insert AD converter value
           memcpy8((Key + 3), GetVal(1), 11);            
                         
                                                     // channel 7 (P6.7)
//t		memcpy(Key, NewKey, 6);               // channel 7 (P6.7)
         
  //       }
//         else if (*(Key + 2) == 'A')
//         {
//           sprintf(NewKey, "%3u", GetTempVal()); // insert AD converter value
//           memcpy(Key, NewKey, 3);               // channel 10 (temp.-diode)
//         }
    if ((*Key & 0xff) == 'L')
     if ((*Key >> 8)  == 'o')
       if ((*(Key + 1) & 0xff)  == 's')
        memcpy8((Key + 4), GetVal(2), 11); 
        
   if ((*Key & 0xff) == 'E')
     if ((*Key >> 8)  == 'r')
       if ((*(Key + 1) & 0xff)  == 'r')
        memcpy8((Key + 4), GetVal(3), 11); 

  if ((*Key & 0xff) == 'r')
     if ((*Key >> 8)  == 'r')
       if ((*(Key + 1) & 0xff)  == 'o')
        memcpy8((Key + 4), GetVal(3), 11); 
  
    if ((*Key & 0xff) == 'i')
     if ((*Key >> 8)  == 't')
       if ((*(Key + 1) & 0xff)  == 's')
        memcpy8((Key + 4), GetVal(4), 11);

     if ((*Key & 0xff) == 'B')
     if ((*Key >> 8)  == 'i')
       if ((*(Key + 1) & 0xff)  == 't')
        memcpy8((Key + 4), GetVal(4), 11);       
        
 /*       
  if (*Key == 'D')
     if (*(Key + 1)  == 'a')
       if (*(Key + 2)  == 't')
       	if (*(Key + 9)  == ':')
        memcpy((Key + 13), GetVal(5), 8);        
     */  
/*
    if (*Key  == 'n')
     if (*(Key + 1)  == 'a')
      if (*(Key + 2)  == 'm')
       if (*(Key + 6)  == '0')
       	if (*(Key + 7)  == '0')
       	  if (*(Key + 8)  == '1')
       		 memcpy((Key + 19), GetVal(5), 8);    
     */  
    if ((*Key & 0xff) == 'n')
     if ((*Key >> 8)  == 'a')
      if ((*(Key + 1) & 0xff)  == 'm')
       if ((*(Key + 3) & 0xff)  == '0')
       	if ((*(Key + 3) >> 8)  == '0')
       	  if ((*(Key + 4) & 0xff)  == '1')
       	  	 memcpy8((Key + 9), GetVal(5), 8);  
       		      
    if ((*Key & 0xff) == 'o')
     if ((*Key >> 8)  == 'n')
       if ((*(Key + 1) & 0xff)   == 't')
       	if ((*(Key + 1) >> 8)  == 'e')
       	 if ((*(Key + 3) & 0xff)   == '=')
        memcpy8((Key + 4), GetVal(6), 2); 
        
 if ((*Key & 0xff) == 'c')
     if ((*Key >> 8)  == 'o')
       if ((*(Key + 1) & 0xff)   == 'n')
       	if ((*(Key + 1) >> 8)  == 't')
        memcpy8((Key + 4), GetVal(6), 2);        
        
      Key++;
  }
}
//------------------------------------------------------------------------------
// This function implements a very simple dynamic HTTP-server.
// It waits until connected, then sends a HTTP-header and the
// HTML-code stored in memory. Before sending, it replaces
// some special strings with dynamic values.
// NOTE: For strings crossing page boundaries, replacing will
// not work. In this case, simply add some extra lines
// (e.g. CR and LFs) to the HTML-code.
//------------------------------------------------------------------------------
#ifdef __cplusplus
#pragma CODE_SECTION("TcpipFuncs")
#else
#pragma CODE_SECTION(HTTPServer, "TcpipFuncs")
#endif
static void HTTPServer(void)
{
//	static unsigned char *PWebSide;                  // pointer to webside
//t  if (SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
  if ((SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
		&& (TCPLocalPort == TCP_PORT_HTTP))			//my to make programmer  
  {
    if (SocketStatus & SOCK_DATA_AVAILABLE)      // check if remote TCP sent data
      TCPReleaseRxBuffer();                      // and throw it away

    if (SocketStatus & SOCK_TX_BUF_RELEASED)     // check if buffer is free for TX
    {
      if (!(HTTPStatus & HTTP_SEND_PAGE))        // init byte-counter and pointer to webside
      {                                          // if called the 1st time
//t        HTTPBytesToSend = ((sizeof(WebSide)) << 1) - 1;   // get HTML length, ignore trailing zero
//        HTTPBytesToSend = ((sizeof(WebSide)) << 1);   // get HTML length, ignore trailing zero
//t8        HTTPBytesToSend = ((sizeof(WebSide)) << 1) - 2;   // get HTML length, ignore trailing zero
//tt		HTTPBytesToSend = (sizeof(WebSide)) - 1; //t8  // get HTML length, ignore trailing zero
		HTTPBytesToSend = (sizeof(WebSide)) - 1 + sizeof(GetResponse) - 3; //t8  // get HTML length, ignore trailing zero
		PWebSide = (unsigned char *)WebSide;     // pointer to HTML-code
//		PWebSide = (unsigned int *)WebSide;     // pointer to HTML-code
	    HTTPStatus |= HTTP_SEND_PAGE;              // ok, 1st loop executed
	    //unsigned char * CPWebSide = PWebSide;
    //t6      memcpy(TCP_TX_BUF, GetResponse, (sizeof(GetResponse)) - 1);
      memcpy8(TCP_TX_BUF, GetResponse, (sizeof(GetResponse)) - 1); //t6
    //t6      memcpy(TCP_TX_BUF + sizeof(GetResponse) - 1, PWebSide,
      //t6    memcpy(TCP_TX_BUF + ((sizeof(GetResponse)) >> 1) - 1, PWebSide, //t6
       memcpy8(TCP_TX_BUF + ((sizeof(GetResponse)) >> 1) - 1, PWebSide, //t6
//          memcpy((TCP_TX_BUF + sizeof(GetResponse) - 1), CPWebSide, //t
      //t6      ((MAX_TCP_TX_DATA_SIZE >> 1) - (sizeof(GetResponse))  + 1));
            (MAX_TCP_TX_DATA_SIZE  - (sizeof(GetResponse))  - 1));
//t1          HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
//t7	 HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse);
//tt	     HTTPBytesToSend -= (MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse));
//		InsertDynamicValues();                   // exchange some strings...
 //       TCPTransmitTxBuffer();                   // xfer buffer 
			 if (HTTPBytesToSend  > MAX_TCP_TX_DATA_SIZE)
			 {
			 HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE;
			 PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse); //t7
			 TCPTxDataCount = MAX_TCP_TX_DATA_SIZE;
			 InsertDynamicValues();                   // exchange some strings...
       		 TCPTransmitTxBuffer();                   // xfer buffer 
			 }
			 else
			 {
			 
			 TCPTxDataCount = HTTPBytesToSend;
			 InsertDynamicValues();                   // exchange some strings...
        	 TCPTransmitTxBuffer();                   // xfer buffer 
			 TCPClose();                              // and close connection
      		 HTTPBytesToSend = 0;                     // all data sent
			 }
//			 HTTPBytesToSend += sizeof(GetResponse);
//t		  PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
//t7		   PWebSide += (MAX_TCP_TX_DATA_SIZE >> 1) - sizeof(GetResponse) + 1;
//tt		   PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse); //t7
	    
      } //first loop
	else //tt - not first loop	
	{ //not first loop
      if (HTTPBytesToSend > MAX_TCP_TX_DATA_SIZE)     // transmit a segment of MAX_SIZE
  //    if ((HTTPBytesToSend > MAX_TCP_TX_DATA_SIZE) || (!(HTTPStatus & HTTP_SEND_PAGE)) ) //tt  // transmit a segment of MAX_SIZE
      {//t5
    /* tt  
        if (!(HTTPStatus & HTTP_SEND_PAGE))           // 1st time, include HTTP-header
        {
//unsigned char * CPWebSide = PWebSide;
    //t6      memcpy(TCP_TX_BUF, GetResponse, (sizeof(GetResponse)) - 1);
      memcpy8(TCP_TX_BUF, GetResponse, (sizeof(GetResponse)) - 1); //t6
    //t6      memcpy(TCP_TX_BUF + sizeof(GetResponse) - 1, PWebSide,
      //t6    memcpy(TCP_TX_BUF + ((sizeof(GetResponse)) >> 1) - 1, PWebSide, //t6
       memcpy8(TCP_TX_BUF + ((sizeof(GetResponse)) >> 1) - 1, PWebSide, //t6
//          memcpy((TCP_TX_BUF + sizeof(GetResponse) - 1), CPWebSide, //t
      //t6      ((MAX_TCP_TX_DATA_SIZE >> 1) - (sizeof(GetResponse))  + 1));
            (MAX_TCP_TX_DATA_SIZE  - (sizeof(GetResponse))  - 1));
//t1          HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
//t7	 HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse);
//tt	     HTTPBytesToSend -= (MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse));
			 HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE;
			 HTTPBytesToSend += sizeof(GetResponse);
//t		  PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
//t7		   PWebSide += (MAX_TCP_TX_DATA_SIZE >> 1) - sizeof(GetResponse) + 1;
		   PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse); //t7
       }
        else //
        {
  //t5
  */ //tt
         memcpy8(TCP_TX_BUF, PWebSide, MAX_TCP_TX_DATA_SIZE );
     //     memcpy(TCP_TX_BUF + sizeof(GetResponse) - 1, PWebSide, (MAX_TCP_TX_DATA_SIZE >> 1));
          HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE;
          PWebSide += MAX_TCP_TX_DATA_SIZE;
//tt        } //httpstatus //t5
          
//        TCPTxDataCount = MAX_TCP_TX_DATA_SIZE;   // bytes to xfer
        TCPTxDataCount = MAX_TCP_TX_DATA_SIZE;   // bytes to xfer
        InsertDynamicValues();                   // exchange some strings...
        TCPTransmitTxBuffer();                   // xfer buffer
      } //httpbytestosend
      else if (HTTPBytesToSend)    //last loop              // transmit leftover bytes
      {
//t7        memcpy(TCP_TX_BUF, PWebSide, (HTTPBytesToSend >> 1));
        memcpy8(TCP_TX_BUF, PWebSide, HTTPBytesToSend);//t7
  //      memcpy(TCP_TX_BUF + sizeof(GetResponse) - 1, PWebSide, (HTTPBytesToSend >> 1));
        TCPTxDataCount = HTTPBytesToSend;        // bytes to xfer
        InsertDynamicValues();                   // exchange some strings...
        TCPTransmitTxBuffer();                   // send last segment
        TCPClose();                              // and close connection
        HTTPBytesToSend = 0;                     // all data sent
      } //httpbytestosend
	} //not first loop
  //tt    HTTPStatus |= HTTP_SEND_PAGE;              // ok, 1st loop executed
    }//SocketStatus & SOCK_TX_BUF_RELEASED
  } //SocketStatus & SOCK_DATA_AVAILABLE
  else
    HTTPStatus &= ~HTTP_SEND_PAGE;               // reset help-flag if not connected

}
//------------------------------------------------------------------------
//TCPIP server 
//------------------------------------------------------------------------



#ifdef __cplusplus
#pragma CODE_SECTION("TcpipFuncs")
#else
#pragma CODE_SECTION(TCPServer, "TcpipFuncs")
#endif
static void TCPServer(void)
{
  if ((SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
		&& (TCPLocalPort != TCP_PORT_HTTP))			//my to make programmer  
  {
    if (SocketStatus & SOCK_DATA_AVAILABLE)      // check if remote TCP sent data
     {
      TCPReleaseRxBuffer();  
      ProgModeTimeOut = ProgModeTime; //set iterval to next burst
     }
    else   if(ProgModeTimeOut)
 	{
 		ProgModeTimeOut--;
 	}
	 else
	{
 		ProgModeClose();
 	}  
  } //SocketStatus & SOCK_DATA_AVAILABLE
}
/**********************************************************************
* Function: main()
*
* Description: Main function for F281x example.
**********************************************************************/
void main(void)
{
unsigned long tmp;
/*** CPU Initialization ***/
 	InitSysCtrl();						// Initialize the CPU (FILE: SysCtrl.c)
	InitXintf();						// Initialize the external memory interface (FILE: Xintf.c)
	InitGpio();							// Initialize the shared GPIO pins (FILE: Gpio.c)
	InitPieCtrl();						// Initialize and enable the PIE (FILE: PieCtrl.c)

/*** Copy all FLASH sections that need to run from RAM (use memcpy() from RTS library) ***/

// Section secureRamFuncs contains user defined code that runs from CSM secured RAM
	memcpy(	&secureRamFuncs_runstart,
			&secureRamFuncs_loadstart,
			&secureRamFuncs_loadend - &secureRamFuncs_loadstart);

/*** Initialize the FLASH ***/
	InitFlash();						// Initialize the FLASH (FILE: SysCtrl.c)

/*** Peripheral Initialization ***/
	InitAdc();							// Initialize the ADC (FILE: Adc.c)
	InitEv();							// Initialize the Event Manager (FILE: Ev.c)
#ifndef _LDR  	//no loader
  //	EALLOW;
  //			SysCtrlRegs.SCSR = 0x0001;//enable wd reset and setting wd en
	//t wd off		SysCtrlRegs.WDCR = 0x002F;//wd en
//			SysCtrlRegs.WDCR = 0x0028;//wd en
//			SysCtrlRegs.WDCR = 0x00A8;
//			SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
  // 			SysCtrlRegs.WDKEY = 0xAA;
   	//		PieCtrlRegs.PIEIER1.bit.INTx8 = 1; //enable wd interrupt?
	//		SysCtrlRegs.WDCR = 0x0038; // immediatly reset: wdchk not "101" and wd enable
//	EDIS;
/*** Enable interrupts ***/
    SetDBGIER(IER);						// Configure the DBGIER for realtime debug
	asm(" CLRC INTM, DBGM");			// Enable global interrupts and realtime debug


/*** Test memory ***/
//not can test Ram if programm work in it
//	 t = Test();	
//	 if(t)
//	 {
//	 for(;;);
//	 }

//	InitBer();
//#ifndef _LDR	InitBer();	
//t	asm(" CLRC INTM, DBGM");	//t		// Enable global interrupts and realtime debug							//init display
//	asm(" CLRC INTM"); //t
//#endif // no _LDR	
	UseSci();
//_______________________________________
	TCPLowLevelInit();
    HTTPStatus = 0;                                // clear HTTP-server's flag register
    TCPLocalPort = TCP_PORT_HTTP;                  // set port we want to listen to
 	EALLOW;
  	PieVectTable.TINT0 = &TINT0_ISR;                                                 // start timer in continuous up-mode
  	EDIS;
  	InitCpuTimers();
  	ConfigCpuTimer(&CpuTimer0, 100, 262000); 		//after add this have messages about bad memory addresses
  	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
  	EINT;
  	ERTM;
  	CpuTimer0Regs.TCR.bit.TSS = 0;	//	Start timer
  	InitRemote();
  	//to test
  	//InitEv();							// Initialize the Event Manager (FILE: Ev.c)
//asm(" CLRC INTM, DBGM");//t
#endif //no _LDR	
  	//to test
  	
//t	TestStorage(); //to test
//	asm(" CLRC INTM, DBGM");			// Enable global interrupts and realtime debug
//_______________________________________	
//	UsedMenu.Draw();
//	InitBer();
	EALLOW;
			SysCtrlRegs.SCSR = 0x0001;
//test			SysCtrlRegs.WDCR = 0x0028;
	EDIS;		
/*** Main Loop ***/
	while(1)							// Dummy loop.  Wait for an interrupt.
	{
	
	/*** Disable interrupts ***/
//	asm(" SETC INTM, DBGM");			// Disable global interrupts
//	EALLOW;
//			SysCtrlRegs.SCSR = 0x0002; //can disable wd
////			SysCtrlRegs.WDCR = 0x0068; //disable wd
//	EDIS;
//	for(;;)
//	tmp = Test();
#ifndef _LDR
//	EALLOW;
//		tmp = SysCtrlRegs.WDCR;
//			SysCtrlRegs.SCSR = 0x0001;
//			SysCtrlRegs.WDCR = 0x0028;
			
//			SysCtrlRegs.WDCR = 0x0037;
//if((!UsedExp.State.Reg1.bit.ProgMode))
	//		{
	//		SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
   	//		SysCtrlRegs.WDKEY = 0xAA;
   		ResetWD();
   	//		}
   	//		PieCtrlRegs.PIEIER1.bit.INTx8 = 1; //enable wd interrupt?
	//		SysCtrlRegs.WDCR = 0x0038; // immediatly reset: wdchk not "101" and wd enable
	
//	EDIS;
#endif // no _LDR
		
//	InitBer();
//		asm(" NOP");
	//	DelayUs(9000);	
//		Hello();
	//	GetKey();
//		asm(" NOP");
	//	DelayUs(9000);
	
		OperateKbd();
		OperateScanCnt();
		
	//t	OperateKbd();
//t		SciaRegs.SCITXBUF= 0x55; //to test send data to comport 
	//	UsedExpert.testexp = 0xaa;
	    if (!(SocketStatus & SOCK_ACTIVE)){ TCPPassiveOpen();}   // listen for incoming TCP-connection
 //   	asm(" SETC INTM, DBGM");
    	DoNetworkStuff();
  //  	asm(" CLRC INTM, DBGM");
    //t	OperateKbd();                                     // handle network and easyWEB-stack
	    HTTPServer();
	    TCPServer();
	}
} //end of main()



/*** end of file *****************************************************/
