/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//    DESCRIPTION:                                                             //
//                                                                             //
//    AUTHOR:                                                                  //
//                                                                             //
//    HISTORY:                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

// include files
#ifdef HOSTDRIVER_EXPORTS
#include "ipConn.h"
#endif // HOSTDRIVER_EXPORTS
//#include <windows.h>      // MFC core and standard components
//#include <conio.h>
#include "hostProtocolStructs.h"
#include "hostDriver.h"
//#include "uart.h"
//#include "spi.h"
#include "iostream.h"
#include "defs610.h"

//_______________________________________________________________
#include "hello7.h"
#include <mqx.h>
#include <bsp.h>
#include "embisr.h"

#include "io_prv.h"
//_______________________________________________________________
// extern pointer fusart0_ptr;

// public data
//port extern CCommConnection theComm[2];
//port extern CSpiConnection  theSpi[2];
#ifdef HOSTDRIVER_EXPORTS
//port extern CIpConnection   theIp[2];
#endif // HOSTDRIVER_EXPORTS


//port HANDLE mutex = NULL;    // In "real" system, should be per device. We'll do with only single one.


#ifdef __cplusplus
extern "C" {
#endif



/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostOpen                                                   //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: all the things we want to do when we open the application     //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostOpen(void)
{

}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostClose                                                  //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: all the things we want to do when we close the application    //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostClose(void)
{

}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostDeviceReset                                               //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////

#ifndef PROG_BMDN2
void pvg610HostDeviceReset(BYTE deviceindex, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
{

unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block

unsigned char reset_byte;
unsigned char read_byte;

switch(deviceindex)
{
 case 0: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 1: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 2: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 3: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 4: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 5: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 6: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 7: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 8: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 9: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 10: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 11: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 12: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 13: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 14: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A;break;
 case 15: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + RESET_ADDR; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 16:
 case 17:
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23: addr_status = 	BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_ADR; addr_send =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_C;break;

 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
}

#else
void pvg610HostDeviceReset(BYTE deviceindex, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
{

unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block

unsigned char reset_byte;
unsigned char read_byte;

unsigned long form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
unsigned long form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);

switch(deviceindex)
{
 case 0: addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 1:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B;break;
 case 2:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 3:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 4:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 5:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 6:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 7:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 8:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 9:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 10:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 11:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 12:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 13:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 14:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 15:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 16:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A;   reset_byte = RES_A; break;
 case 17:addr_status = 	form_addr + RESET_ADDR; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B;   reset_byte = RES_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = form_addrs + ADDR_STATUS1; addr_data = form_addrs +  SPI_PORT_ADDR; addr_type =  form_addrs + SPI_ADR; addr_send =  form_addrs + SPI_SEND_ADDR;type_channel = CHANNEL_C;break;

 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
}



#endif



//delay_mcs(1000);

read_byte =  read_xil_char(addr_status);

//printf("\n\r reset dev : %d  - addr :%X  read %X data: %X ", deviceindex , addr_status, read_byte, (read_byte & reset_byte));
write_xil_char(addr_status, read_byte & reset_byte);
delay_mcs(100l);
write_xil_char(addr_status, read_byte | (~(reset_byte)));
//printf("\n\r  addr :%X  data: %X ", addr_status, (read_byte | (~(reset_byte))));
delay_mcs(1000l);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostSleep                                                     //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostSleep(UINT32 sleepTimeMicro)
{
  //port  Sleep((sleepTimeMicro+999)/1000);
  delay_mcs(sleepTimeMicro); //t
//  delay_mcs(sleepTimeMicro/1000); //t
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostTickGet                                                   //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
UINT32 pvg610HostTickGet(void)
{
  //   return(GetTickCount());
    return(timer);	  //temporary
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostMutexGet                                                  //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostMutexGet(BYTE deviceIndex)
{
/* port
    if (!mutex)
    {
        mutex = CreateMutex(NULL, TRUE , NULL);
    }
    else
    {
        WaitForSingleObject(mutex, INFINITE);
    }
	*/
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostMutexRelease                                              //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostMutexRelease(BYTE deviceIndex)
{
 /* port
    if (mutex)
    {
         ReleaseMutex(mutex);
    }
 */
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostUartDataSend                                              //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the uart                                   //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostUartDataSend(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen)
{
 //port   theComm[deviceIndex].Write(pBuff,buffLen);
// printf("\n\r");
#ifdef PRINT_USART_DATA    
//printEthStringAdd(0,0); 
//if(print_flag)
   //	printEthStringAdd(1,0x71); 

  //	printEthStringAdd(1,buffLen); 

#endif   

 for(UINT32 i = 0; i < buffLen; i++)
 {
#ifdef PRINT_USART_DATA 
//if(print_flag)   
//printEthStringAdd(1,*pBuff); 
#endif 
//delay_mcs(20);	   //t
  Transmit0c((unsigned char) (*pBuff++));
 // delay_mcs(20);	
  


// printf(" %02X", *pBuff++); //for test

   //	 fputc(*pBuff++, fusart0_ptr);
 }

#ifdef PRINT_USART_DATA    
//if(print_flag) 
//printEthStringAdd(1,0x11); 
//printEthStringAdd(2,0); 
#endif

}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostUartDataReceive                                           //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from the uart                                  //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostUartDataReceive(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen, UINT16 timeoutMilli, UINT32 *pReadBytes)
{
//port    theComm[deviceIndex].SetTimeout(timeoutMilli);
 //port   theComm[deviceIndex].Read(pBuff, buffLen, pReadBytes);

   if( GetUsart0Data(pBuff))
   {
     *pReadBytes = 1;

  //	  printf("+%02X", *pBuff++); //for test

   }
   else
   {
	 *pReadBytes = 0;
   }

}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostUartReceiverFlush                                         //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: flushing the uart rx                                          //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostUartReceiverFlush(BYTE deviceIndex)
{
 //port   theComm[deviceIndex].purgeRx();
}

#define REAL_SPI_SIZE (0xff)
/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostSpiDataSend                                               //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the spi                                    //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
unsigned char pvg610HostSpiDataSend(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen)
{
//port    theSpi[deviceIndex].Write(pTxBuff, buffLen);
//hier need work with hilix
// delay_mcs(1000); //t/tExChangeSpi(buffLen, pTxBuff);
// printf("\n\rspi send :");
 if(buffLen <= REAL_SPI_SIZE)
 {
#ifndef MANY_MODEMS
      WriteSpiB(buffLen, pTxBuff);
#else
 //	  WriteSpiB(buffLen, pTxBuff);
 	if(!(WriteSpiBm(deviceIndex, buffLen, pTxBuff))) return 0;
#endif


 }
 else
 {
#ifndef MANY_MODEMS
  WriteSpiB(REAL_SPI_SIZE, pTxBuff);
#else
 // WriteSpiB(REAL_SPI_SIZE, pTxBuff);
   if(!(WriteSpiBm(deviceIndex, REAL_SPI_SIZE, pTxBuff))) return 0;
#endif
 //t101026  delay_mcs(1000);	//??? can make lower
//t101027  delay_mcs(50); //t101026	
  for(long i = 0; i < REAL_SPI_SIZE; i++)
  pTxBuff++;
#ifndef MANY_MODEMS
  WriteSpiB((buffLen - REAL_SPI_SIZE), pTxBuff);	   //have 0x103
#else
 //WriteSpiB((buffLen - REAL_SPI_SIZE), pTxBuff);	   //have 0x103
  WriteSpiBm(deviceIndex, (buffLen - REAL_SPI_SIZE) , pTxBuff);
#endif


 }

 return 1;
}
#ifdef XIL_FLASH
extern "C" unsigned char WriteReadSpiBm(unsigned char , unsigned long ,
 unsigned char * , unsigned char * );


void pvg610HostSpiDataSendReceivex(BYTE deviceIndex, BYTE *pTxBuff,  
										BYTE *pRxBuff,UINT32 buffLen)
{
//port    theSpi[deviceIndex].Write(pTxBuff, buffLen);
//hier need work with hilix
// delay_mcs(1000); //t/tExChangeSpi(buffLen, pTxBuff);
// printf("\n\rspi send :");
// printfp("\n\r pvg610HostSpiDataSendReceivex ");
 //printfpd("deviceIndex  %d \n\r", deviceIndex);	 //t  27
// OperateBuffers_usart0t();


BYTE *pTxBuffp;
UINT32 buffLenp;
pTxBuffp = pTxBuff;
buffLenp = buffLen;
//printfp("\n\r write to  flash : ");
// OperateBuffers_usart0t();

//if(buffLenp)


#ifdef PR_FL 
   	   /*
 if(start_main_loop) 
{
	
   
while(buffLenp--)
 {
printfpd(" %02X", *pTxBuffp++);
OperateBuffers_usart0t();

 }

printfp("\n\r");
  }
  */	
#endif

  //ok return; //t121003

 if(buffLen <= REAL_SPI_SIZE)
 {
 //	  WriteSpiB(buffLen, pTxBuff);
 	  WriteReadSpiBm(deviceIndex,  buffLen,pTxBuff, pRxBuff);

 }
 else
 {

 while(buffLen > REAL_SPI_SIZE)
 {
 
 // WriteSpiB(REAL_SPI_SIZE, pTxBuff);
  WriteReadSpiBm(deviceIndex, REAL_SPI_SIZE, pTxBuff, pRxBuff );

 //120130 delay_mcs(1000);	//??? can make lower
//ok  delay_mcs(500); //120130	//??? can make lower
// delay_mcs(250);
  delay_mcs(50);

  for(long i = 0; i < REAL_SPI_SIZE; i++)
  pTxBuff++;
   pRxBuff++;
   buffLen -= REAL_SPI_SIZE;
  }



 //WriteSpiB((buffLen - REAL_SPI_SIZE), pTxBuff);	   //have 0x103
 // WriteSpiBm(deviceIndex, (buffLen - REAL_SPI_SIZE) , pTxBuff);
  WriteReadSpiBm(deviceIndex, (buffLen) , pTxBuff, pRxBuff);


 }

pTxBuffp = pRxBuff;
buffLenp = buffLen;

//printfp(" read from  flash : ");
//OperateBuffers_usart0t();
//while(buffLenp--)
// {
// printfpd(" %02X", *pTxBuffp++);
 //OperateBuffers_usart0t();
 //  }



}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostSpiDataSendx                                               //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the spi                                    //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostSpiDataSendx(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen)
{
//port    theSpi[deviceIndex].Write(pTxBuff, buffLen);
//hier need work with hilix
// delay_mcs(1000); //t/tExChangeSpi(buffLen, pTxBuff);
// printf("\n\rspi send :");
// printfp("\n\rpvg610HostSpiDataSendx  deviceindex:");
// printfpd(" %d", deviceIndex);

BYTE *pTxBuffp;
UINT32 buffLenp;
pTxBuffp = pTxBuff;
buffLenp = buffLen;
//printfp("\n\r write to  flash : ");

while(buffLenp--)
 {
// printfpd(" %02X", *pTxBuffp++);
   }



 if(buffLen <= REAL_SPI_SIZE)
 {
#ifndef MANY_MODEMS
      WriteSpiB(buffLen, pTxBuff);
#else
 //	  WriteSpiB(buffLen, pTxBuff);
 	  WriteSpiBm(deviceIndex, buffLen, pTxBuff);
#endif


 }
 else
 {

 while(buffLen > REAL_SPI_SIZE)
 {
 
#ifndef MANY_MODEMS
  WriteSpiB(REAL_SPI_SIZE, pTxBuff);
#else
 // WriteSpiB(REAL_SPI_SIZE, pTxBuff);
  WriteSpiBm(deviceIndex, REAL_SPI_SIZE, pTxBuff);
#endif

 //120130 delay_mcs(1000);	//??? can make lower
//ok  delay_mcs(500); //120130	//??? can make lower
//ok delay_mcs(250);
 delay_mcs(50);
  for(long i = 0; i < REAL_SPI_SIZE; i++)
  pTxBuff++;
   buffLen -= REAL_SPI_SIZE;
  }



#ifndef MANY_MODEMS
//  WriteSpiB((buffLen - REAL_SPI_SIZE), pTxBuff);	   //have 0x103
  WriteSpiB(buffLen), pTxBuff);	   //have 0x103
#else
 //WriteSpiB((buffLen - REAL_SPI_SIZE), pTxBuff);	   //have 0x103
 // WriteSpiBm(deviceIndex, (buffLen - REAL_SPI_SIZE) , pTxBuff);
  WriteSpiBm(deviceIndex, (buffLen) , pTxBuff);
#endif


 }


}

void pvg610HostSpiDataReceivex(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)
{

// printfp("\n\rpvg610HostSpiDataReceivex  deviceindex:");
// printfpd(" %d", deviceIndex);
//port    theSpi[deviceIndex].Read(pTxBuff, pRxBuff, buffLen);
//hier need work with hilix

 //  ExChangeSpi(buffLen, pTxBuff);
 unsigned char * BuffTmp;

//   	   BuffTmp =  ExChangeSpi(buffLen, pTxBuff);
#ifndef MANY_MODEMS
     BuffTmp =  ReadSpiB(buffLen);
#else
// BuffTmp =  ReadSpiB(buffLen);

	BuffTmp =  ReadSpiBm(deviceIndex, buffLen);
#endif

 if((buffLen > MAX_SP_LEN) || (!buffLen)) buffLen = MAX_SP_LEN;

// printfp("\n\r read from flash : ");
 while(buffLen--)
 {
// printfpd(" %02X", *BuffTmp);
  *pRxBuff++ = 	*BuffTmp++;
 }

}



#endif

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostSpiDataReceive                                            //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from the spi                                   //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostSpiDataReceive(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)
{
//port    theSpi[deviceIndex].Read(pTxBuff, pRxBuff, buffLen);
//hier need work with hilix

 //  ExChangeSpi(buffLen, pTxBuff);
 unsigned char * BuffTmp;

//   	   BuffTmp =  ExChangeSpi(buffLen, pTxBuff);
#ifndef MANY_MODEMS
     BuffTmp =  ReadSpiB(buffLen);
#else
// BuffTmp =  ReadSpiB(buffLen);

	BuffTmp =  ReadSpiBm(deviceIndex, buffLen);
#endif

 if((buffLen > MAX_SP_LEN) || (!buffLen)) buffLen = MAX_SP_LEN;
 while(buffLen--)
 {
  *pRxBuff++ = 	*BuffTmp++;
 }

}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostDpramDataWrite                                            //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the dpram                                  //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostDpramDataWrite(BYTE deviceIndex, UINT16 indirectAddress, BYTE *pBuff, UINT32 buffLen)
{
#ifdef HOSTDRIVER_EXPORTS
    if (theIp[deviceIndex].gIsIp)
    {
        if (buffLen < 8) {
             // silently discard...
            return;
        }
        theIp[deviceIndex].sendOverIp(pBuff, buffLen);
    }
    else
#endif // HOSTDRIVER_EXPORTS
    {
        // UDI: add DPRAM support to PC later?
        // need to round up to word size
    }
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostDpramDataRead                                             //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from the dpram                                 //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void pvg610HostDpramDataRead(BYTE deviceIndex, UINT16 indirectAddress, BYTE *pBuff, UINT32 buffLen)
{
#ifdef HOSTDRIVER_EXPORTS
    if (theIp[deviceIndex].gIsConnected)
    {
        if (indirectAddress == PVG610_DPRAM_RX_LEVEL_REG)
        {
            // convert to "words" in DPRAM
            UINT16 tmp = (theIp[deviceIndex].recvBufLen + 1) / 2;
            // copy response lenght
            *(UINT16*)pBuff = tmp;
        }
        else if (indirectAddress == PVG610_DPRAM_RX_RDATA_REG)
        {
             memcpy(pBuff, theIp[deviceIndex].recvBuf, buffLen);
        }
        else
        {
                  re
        }
    }
    else
#endif // HOSTDRIVER_EXPORTS
    {
        // UDI: add DPRAM support to PC later?
    }
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610HostDpramWait                                                 //
//                                                                             //
//  PARAMETERS:                                                                / /
//                                                                             //
//  DESCRIPTION: block on the receive side of the DPRAM till be PVG610 signals //
//               that it has responded. The function should block, waiting for //
//               the PVG610 DPRAM interrupt for the timeout specified.         //
//                                                                             //
//  RETURNS: TRUE if r rched timeout, FALSE if received interrupt              //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN pvg610HostDpramWait(BYTE deviceIndex, UINT16 timeoutMilli)
{
#ifdef HOSTDRIVER_EXPORTS
    if (theIp[deviceIndex].gIsConnected)
    {
        // perform recv() here, keep resulting (packet+len) somewhere
        theIp[deviceIndex].recvBufLen = theIp[deviceIndex].receiveFromIp(theIp[deviceIndex].recvBuf, PVG610_HOST_PROTOCOL_MAX_MSG_LEN);
        if (theIp[deviceIndex].recvBufLen < 0)
        {
            return (TRUE);
        }
        return (FALSE);
    }
    else
#endif // HOSTDRIVER_EXPORTS
    {
        // UDI: add DPRAM support to PC later?
        return TRUE;
    }
}



#ifdef __cplusplus
}
#endif


