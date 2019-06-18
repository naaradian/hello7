/*****************************************************************************************   
* MaxLinear, Inc. retains all right, title and interest (including all intellectual
* property rights) in and to this computer program, which is protected by applicable
* intellectual property laws.  Unless you have obtained a separate written license from
* MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., you are not authorized
* to utilize all or a part of this computer program for any purpose (including
* reproduction, distribution, modification, and compilation into object code), and you
* must immediately destroy or return all copies of this computer program.  If you are
* licensed by MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., your rights
* to utilize this computer program are limited by the terms of that license.
*
* This computer program contains trade secrets owned by MaxLinear, Inc. and, unless
* authorized by MaxLinear, Inc. in writing, you agree to maintain the confidentiality
* of this computer program and related information and to not disclose this computer
* program and related information to any other person or entity.
*
* Misuse of this computer program or any information contained in it may results in
* violations of applicable law.  MaxLinear, Inc. vigorously enforces its copyright,
* trade secret, patent, contractual, and other legal rights.
*
* THIS COMPUTER PROGRAM IS PROVIDED �AS IS� WITHOUT ANY WARRANTIES, AND MAXLINEAR, INC.
* EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE WARRANTIES OF
* MERCHANTIBILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NONINFRINGEMENT.
****************************************************************************************
*                                        Copyright (c) 2012, MaxLinear, Inc.
****************************************************************************************/



// include files
#ifdef HOSTDRIVER_EXPORTS
#include "ipConn.h"
#endif // HOSTDRIVER_EXPORTS

//#include <windows.h>      // MFC core and standard components
//#include "mmsystem.h"
//#include <conio.h>
//#include <iostream>

#include "hostCommLayer.h"
#include "hostDriver.h"
//#include "uart.h"
//#include "spi_u2c.h"
#include "defs_uw.h"
//#include "spi_sub20.h"
#include "hello7.h"

#pragma warning( disable : 4996)

// public data
//extern CCommConnection theComm[BCM_UW_DEVICES_NUM];
//extern SpiInterface *theSpi[BCM_UW_DEVICES_NUM];

#ifdef HOSTDRIVER_EXPORTS
extern CIpConnection   theIp[BCM_UW_DEVICES_NUM];
#endif // HOSTDRIVER_EXPORTS


//HANDLE apiMutex[BCM_UW_DEVICES_NUM] = {NULL,NULL,NULL,NULL};

//UINT gTickResolution;
unsigned int  gTickResolution;

#ifdef __cplusplus
extern "C" {
#endif



/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostOpen                                                    //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: all the things we want to do when we open the application     //
//                                                                             //
//  RETURNS: TRUE on failure, FALSE on success                                 //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHostOpen(void)
{
/*
    TIMECAPS caps;
    timeGetDevCaps(&caps, sizeof(caps));
    gTickResolution = MAX(caps.wPeriodMin, 2);      // the larger between 2 and minimal
    timeBeginPeriod(gTickResolution);
*/
    return(FALSE);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostClose                                                   //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: all the things we want to do when we close the application    //
//                                                                             //
//  RETURNS: TRUE on failure, FALSE on success                                 //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHostClose(void)
{
 //   timeEndPeriod(gTickResolution);
    return(FALSE);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostDeviceReset                                             //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostDeviceReset(BYTE deviceIndex)
{
/*
    char message[256];
    bool spiActive = ( (theSpi[deviceIndex] != NULL) &&                //SPI configured
                       (theSpi[deviceIndex]->IsOpened()) );            //SPI is currently open
    
    // ask user to press reset on emulation / evaludation board
    if ( (spiActive == FALSE) ||                                    //UART / MII
         (theSpi[deviceIndex]->ManualReset()) )                        //SPI "manual" mode
    {
        sprintf(message, "Reset the CPU of device %d and press OK when ready to proceed", deviceIndex + 1); 
        MessageBox(NULL, message, "BCM85xxx Boot Sequence", MB_OK);
    }
        
    if (spiActive == TRUE)
    {
        // handle reset via SPI (used as GPIO, even if UART or Ethernet)
        theSpi[deviceIndex]->ResetBoard(deviceIndex);
    }
	*/
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSleep                                                   //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostSleep(UINT32 sleepTimeMicro)
{
    UINT32 sleepTimeMilli;
//    LARGE_INTEGER before, after, freq;
//    LONGLONG countdiff;
//    LONGLONG elapsedMicro;

//    QueryPerformanceFrequency(&freq);
//    QueryPerformanceCounter(&before);

    // round up to milli - Windows cannot do less than 1 milli
    sleepTimeMilli = (sleepTimeMicro+999)/1000;
    // round up to tick resolution - Windows sleep does not guarentee behavior for below one tick, between tick and two, etc.
    // See http://msdn.microsoft.com/en-us/library/ms686298(VS.85).aspx
    sleepTimeMilli = ((sleepTimeMilli + gTickResolution - 1) / gTickResolution) * gTickResolution;

 //   Sleep(sleepTimeMilli);

//    QueryPerformanceCounter(&after);
//    countdiff = after.QuadPart - before.QuadPart;
//    elapsedMicro = (countdiff * 1000000) / freq.QuadPart;
//    if (sleepTimeMicro < 2000 && elapsedMicro < sleepTimeMicro)
//    {
//        elapsedMicro++;
//    }
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostTickGet                                                 //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
UINT32 bcmUwHostTickGet(void)
{
//    return(GetTickCount());
    return(111); //t
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostApiMutexGet                                             //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostApiMutexGet(BYTE deviceIndex)
{
/*
    if (!apiMutex[deviceIndex])
    {
        apiMutex[deviceIndex] = CreateMutex(NULL, TRUE, NULL);
    }
    else
    {
        WaitForSingleObject(apiMutex[deviceIndex], INFINITE);
    }
	*/
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostApiMutexRelease                                         //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION:                                                               //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostApiMutexRelease(BYTE deviceIndex)
{
 //   if (apiMutex[deviceIndex])
 //   {
 //        ReleaseMutex(apiMutex[deviceIndex]);
 //   }
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: General OS Mutex functions                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
  /*
bcmUwHostMutexHandle bcmUwHostMutexCreate(void)
{
    return(CreateMutex(NULL, FALSE, NULL));
//	return(111);
}
	 */
void bcmUwHostMutexDelete(bcmUwHostMutexHandle mutex)
{
    if (mutex != NULL)
    {
 //       CloseHandle(mutex);
    }
}

int bcmUwHostMutexLock(bcmUwHostMutexHandle mutex)
{
    UINT32 retVal;// = WaitForSingleObject(mutex, INFINITE);
 //   if (retVal == WAIT_OBJECT_0)
 //   {
 //       return(0);
 //   }
    return(1);
}

int bcmUwHostMutexUnlock(bcmUwHostMutexHandle mutex)
{
/*
    BOOL retVal;// = ReleaseMutex(mutex);
    if (retVal)
    {
        return(0);
    }
	*/
    return(1);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostUartDataSend                                            //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the uart                                   //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostUartDataSend(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen)
{
/* ?  size maximum so high
    #define MAX_UART_TRANSACTION_SIZE_BYTES         (1024 * 8)              // due to windows driver buffer size limitation
    UINT32 chunkLen;

    while (buffLen)
    {
        chunkLen = MIN(buffLen,                                   MAX_UART_TRANSACTION_SIZE_BYTES);
   //     theComm[deviceIndex].Write(pBuff, chunkLen);
        pBuff += chunkLen;
        buffLen -= chunkLen;
    }
	*/

 //  bcm_transmit_usart2L((char *)pBuff, buffLen);
   bcm_transmit_usart2((char *)pBuff, buffLen);

}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostUartDataReceive                                         //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from the uart                                  //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostUartDataReceive(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen, UINT32 timeoutMilli, UINT32 *pReadBytes)
{
//    theComm[deviceIndex].SetTimeout(timeoutMilli);
  //  theComm[deviceIndex].Read(pBuff, buffLen, pReadBytes);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostUartReceiverFlush                                       //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: flushing the uart rx                                          //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostUartReceiverFlush(BYTE deviceIndex)
{
  //  theComm[deviceIndex].purgeRx();
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiDataSend                                             //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to the spi                                    //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostSpiDataSend(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen)
{
//    if (theSpi[deviceIndex] != NULL)
//    {
//        theSpi[deviceIndex]->Write(pTxBuff, buffLen);
//    }
	SpiWriteCS2B(buffLen, (unsigned long)pTxBuff,  (unsigned long)pTxBuff);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiDataReceive                                          //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from the spi                                   //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostSpiDataReceive(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)
{
//    if (theSpi[deviceIndex] != NULL)
//    {
//        theSpi[deviceIndex]->Read(pTxBuff, pRxBuff, buffLen);
//    }
	SpiWriteCS2B(buffLen, (unsigned long)pTxBuff , (unsigned long)pRxBuff);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiModeSet                                              //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: sets SPI mode (four possible modes: 00,01,10,11)              //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostSpiModeSet(BYTE deviceIndex, int mode)
{
 //   if (theSpi[deviceIndex] != NULL)
 //   {
 //       theSpi[deviceIndex]->SPIModeSet(mode);
 //   }
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiMaxRateSet                                           //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: limits future SPI transactions to rate <= maxRateHz           //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostSpiMaxRateSet(BYTE deviceIndex, UINT32 maxRateHz)
{
    char message[256];

    // warn if rate < 300KHz - possible issue with DC
    if (maxRateHz < 300000)
    {
//        sprintf(message, "Setting SPI rate to rate %d", maxRateHz);
//        MessageBox(NULL, message, "BCM85xxx SPI Rate", MB_OK);
    }

//    if (theSpi[deviceIndex] != NULL)
//    {
//        theSpi[deviceIndex]->maxRateSet(maxRateHz);
//    }
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiIsDataReady                                          //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: Return current value of SPI data ready signal                 //
//                                                                             //
//  RETURNS: TRUE if "1", FALSE if "0"                                         //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHostSpiIsDataReady(BYTE deviceIndex)
{
//    if (theSpi[deviceIndex] != NULL)
//    {
//        return(theSpi[deviceIndex]->isDataReady());
//    }  

    return FALSE;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostSpiDataReadyWait                                        //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: Wait for SPI data ready to become "1" for this device/if      //
//                                                                             //
//  RETURNS: TRUE if reached timeout, FALSE if received interrupt              //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHostSpiDataReadyWait(BYTE deviceIndex, UINT32 timeoutMilli)
{
/*
    LARGE_INTEGER before, after, freq;
    LONGLONG countdiff;
    LONGLONG elapsedMicro;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&before);

    while (1)
    {
        // check signal (must poll on PCI w/ USB/SPI)
        if (bcmUwHostSpiIsDataReady(deviceIndex))
        {
            return(FALSE);
        }

        // timeout?
        QueryPerformanceCounter(&after);
        countdiff = after.QuadPart - before.QuadPart;
        elapsedMicro = (countdiff * 1000000) / freq.QuadPart;
        // It is a known Windows bug that on some platforms, QueryPerformanceCounter() may sporadically indicate jumps of few seconds.
        // In this case, the function will timeout, but this is not an issue, since the TX thread will re-trigger it.
        if (elapsedMicro > ((LONGLONG)timeoutMilli * 1000))
        {
            return(TRUE);
        }
    }
	*/
    return(FALSE);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostMIIDataWrite                                            //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: writes a buffer to Ethernet                                   //
//                                                                             //
//  RETURNS:                                                                   //
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHostMIIDataWrite(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen)
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
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostMIIDataRead                                             //
//                                                                             //
//  PARAMETERS:                                                                //
//                                                                             //
//  DESCRIPTION: reads a buffer from Ethernet                                  //
//                                                                             //
//  RETURNS: TRUE if reached timeout, FALSE if received interrupt              //
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHostMIIDataRead(BYTE deviceIndex, BYTE *pBuff, UINT32 maxLen, UINT32 *pBuffLen, UINT32 timeoutMilli)
{
#ifdef HOSTDRIVER_EXPORTS
    INT32 tmpLen;
    static UINT32 lastTimeoutMilli = 0;
    UINT32  startTime, elapsedTime;
    
    *pBuffLen = 0;                      //default answer for error cases

    startTime = bcmUwHostTickGet();      //note that on some platforms, this may not be accurate

    // attempt to receive the buffer
    if (theIp[deviceIndex].gIsConnected)
    {
        // set socket timeout just if needed
        if (lastTimeoutMilli != timeoutMilli)
        {
            (void)theIp[deviceIndex].setSocketTimeout(timeoutMilli);
            lastTimeoutMilli = timeoutMilli;
        }

        do {
            // perform recv() here
            tmpLen = theIp[deviceIndex].receiveFromIp(pBuff, maxLen);
            if (tmpLen <= 0)
            {
                elapsedTime = (bcmUwHostTickGet() - startTime); // what's the time?
                if (elapsedTime < lastTimeoutMilli)
                {
                    continue; //try to recv once again, workaround for winsock bug...
                }
                return(TRUE);
            }
            else // we got something
            {
                break;
            }
        } while(1);

        // copy the response
        *pBuffLen = tmpLen;
        return(FALSE);
    }
    return(TRUE);
#else
    return(TRUE);
#endif
}


#ifdef __cplusplus
}
#endif


