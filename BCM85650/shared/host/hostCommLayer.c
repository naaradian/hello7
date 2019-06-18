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


#include "string.h"
#include "stdio.h"
#include "hostCommLayer.h"
#include "hostDriver.h"
#include "endian_uw.h"
#include "hello7.h" 


/* Defines */
//#define SPI_POLLING_MODE                //SPI polling / Data-Ready (use GPIO)
//#define HOST_PROTOCOL_TX_LOG            //enable hostProtocol.log

#ifdef HOST_PROTOCOL_TX_LOG
    #ifdef WIN32
        #pragma warning( disable : 4996)    // allow usage of plain "fopen()"
    #endif

    FILE *pfHostMsg;
    #define BCM_UW_HCOMM_MSG_FILE_NAME  "hostProtocol.log"
#endif


#define BCM_UW_HCOMM_DEFAULT_TIMEOUT_MILLI          1000
#define BCM_UW_HCOMM_SPI_RX_MSG_SMALLEST_SIZE       16        // covers flag + header + flag + 2 more (stuffing, spare)
#define BCM_UW_HCOMM_MII_DEVICE_MAX_PACKET_LEN     (BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN)


typedef enum {
    BCM_UW_HCOMM_DESTUFF_IDLE_E,
    BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E,
    BCM_UW_HCOMM_DESTUFF_IN_MSG_E,
    BCM_UW_HCOMM_DESTUFF_ESC_CODE_DETECTED_E,
} BCM_UW_HCOMM_DESTUFF_STATE_MACHINE_ENUM;

typedef struct {
    // general information
    BCM_UW_COM_MEDIA_ENUM                   comMedia;                   // media type - per interface
    UINT32                                  refClockInHz;               // for calculating boot latencies and wait times
    BOOLEAN                                 enableForwarding;           // prevent forwarding while booting
    BYTE                                    deviceIndex;                // who am I?
    BYTE                                    remoteDeviceIndex;          // when IP, who is the host's device
    UINT32                                  rxTimeoutMilli;             // Timeout for receive operation

    // TX-related
    BYTE                                    pTxMsg[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + 4];   // 4 spare.
    UINT32                                  txTotalMsgSize;
    UINT32                                  txSeqNum;                   //sequence number given to this message on entry, needed to match response to request
    BYTE                                    txSentOpcode;               //keep requested opcode for validation

    // RX-related
    BYTE                                    pRxMsg[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + 4];   // destuff machine - working buffers
    UINT32                                  rxTotalMsgSize;                                     // destuff machine - accumulated length
    BCM_UW_HCOMM_DESTUFF_STATE_MACHINE_ENUM rxState;                    // destuff machine - state

    // Caller information
    BYTE                                   *pBufferToReceive;       // After receive, buffer should be directly copied to user's pointer, so we keep it
    UINT32                                 *pActualRxLen;           // After receive, buffer length is copied to here
    BCM_UW_ERROR_MSG_ENUM                  *pStatus;                // After receive, transaction status is copied to here
    BOOLEAN                                 forwardedMsg;           // indication for RX to give whole buffer, not just payload
} BCM_UW_HCOMM_DEVICE_STRUCT;


/* Globals */
BCM_UW_HCOMM_DEVICE_STRUCT  gBcmUwHostCommDatabase[BCM_UW_DEVICES_NUM];
BYTE                        gTxSpiFlagsBuf[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];



///////////////////////////////////////////////////////////////////////////////
// Local Function Prototypes
///////////////////////////////////////////////////////////////////////////////
// Transmit build / helper / global functions
void                    bcmUwHcommMessageBuild              (BCM_UW_HCOMM_DEVICE_STRUCT *pEntry, BYTE opcode, BYTE modemIndex, BYTE *pPayload, UINT32 payloadLen);
void                    bcmUwHcommMessageBuildForForward    (BCM_UW_HCOMM_DEVICE_STRUCT *pEntry, BYTE *pBuffer, UINT32 bufferLen);
void                    bcmUwHcommTxMessageStuff            (BYTE *pBuff, /*@out@*/BYTE *pStuffedBuff, UINT32 buffLen, UINT32 /*@out@*/*stuffedLen);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommRxReceivedMessageHandle   (BYTE deviceIndex, BYTE *pBufferReceived, UINT32 rxLen);
BOOLEAN                 bcmUwHcommRxMessageIsValid          (BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord);
UINT32                  bcmUwHcommSpiEstimatedRxMsgSizeGet  (BYTE deviceIndex);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommRxDestuffMachine          (BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord, BYTE *pBytesReceived, UINT32 rxLen, BOOLEAN *isComplete);

// Transmit functions
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommMessageSend               (BYTE deviceIndex);
void                    bcmUwHcommUartSend                  (BYTE deviceIndex);
void                    bcmUwHcommSpiSend                   (BYTE deviceIndex);
void                    bcmUwHcommMiiDeviceSend             (BYTE deviceIndex);
void                    bcmUwHcommIpClientSend              (BYTE deviceIndex);

// Receive functions
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommMessageReceive            (BYTE deviceIndex);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommUartReceive               (BYTE deviceIndex);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommSpiReceive                (BYTE deviceIndex);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommIpClientReceive           (BYTE deviceIndex);
BCM_UW_ERROR_MSG_ENUM   bcmUwHcommMiiDeviceReceive          (BYTE deviceIndex);

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Communication Control Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommOpen(void)
{
    UINT32 ix;

#ifdef HOST_PROTOCOL_TX_LOG
    pfHostMsg = fopen(BCM_UW_HCOMM_MSG_FILE_NAME , "w");
#endif
    // fill global SPI TX buf with flags
    memset(gTxSpiFlagsBuf, 0x7E, sizeof(gTxSpiFlagsBuf));

    // initializations per device
    for (ix=0; ix<BCM_UW_DEVICES_NUM; ix++)
    {
        // general initializations
        gBcmUwHostCommDatabase[ix].enableForwarding = FALSE;
        gBcmUwHostCommDatabase[ix].deviceIndex = (BYTE)ix;
        gBcmUwHostCommDatabase[ix].rxTimeoutMilli = BCM_UW_HCOMM_DEFAULT_TIMEOUT_MILLI;
        gBcmUwHostCommDatabase[ix].remoteDeviceIndex = 0;         // assume only one device, unless told otherwise later
        gBcmUwHostCommDatabase[ix].comMedia = BCM_UW_COM_MEDIA_NULL_E;
        gBcmUwHostCommDatabase[ix].txSeqNum = 0;
    }

    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommClose(void)
{
    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComConfigure(BYTE deviceIndex, BCM_UW_COM_MEDIA_ENUM media, BCM_UW_COM_MEDIA_ENUM dummy, UINT32 refClockInHz)
{
    BOOLEAN isBigEndian;
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;

    // Error handling
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return BCM_UW_INVALID_DEVICE_INDEX_E;
    }
    if (media >= BCM_UW_COM_MEDIA_MAX_E)
    {
        return BCM_UW_INVALID_MEDIA_E;
    }
    if (refClockInHz < 10000000 || refClockInHz > 200000000)
    {
        return BCM_UW_INVALID_PARAMS_E;
    }

    bcmUwHostApiMutexGet(deviceIndex);

    // configure endianity for future req/resp swapping
    isBigEndian = utilsUwIsBigEndian();
    bcmUwEndianConversionConfigure(isBigEndian);

    // initialize device in database
    gBcmUwHostCommDatabase[deviceIndex].comMedia = media;
    gBcmUwHostCommDatabase[deviceIndex].refClockInHz = refClockInHz;
    gBcmUwHostCommDatabase[deviceIndex].enableForwarding = ((media == BCM_UW_COM_MEDIA_NULL_E) ? FALSE : TRUE);

    // set initial SPI mode 1-1
    bcmUwHostSpiModeSet(deviceIndex, 3);
    // assume that SPI rate is implicitly set by user to some reasonable value

    bcmUwHostApiMutexRelease(deviceIndex);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComRemoteDeviceConfigure(BYTE deviceIndex, BYTE remoteDeviceIndex)
{
    // minimal error checking
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return(BCM_UW_INVALID_DEVICE_INDEX_E);
    }

    // no special check for remote device, since we cannot really know
    bcmUwHostApiMutexGet(deviceIndex);
    gBcmUwHostCommDatabase[deviceIndex].remoteDeviceIndex = remoteDeviceIndex;
    bcmUwHostApiMutexRelease(deviceIndex);
    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComTimeoutSet(BYTE deviceIndex, UINT32 timeoutInMilli)
{
    // minimal error checking
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return(BCM_UW_INVALID_DEVICE_INDEX_E);
    }

    bcmUwHostApiMutexGet(deviceIndex);
    gBcmUwHostCommDatabase[deviceIndex].rxTimeoutMilli = timeoutInMilli;
    bcmUwHostApiMutexRelease(deviceIndex);
    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComMessageForward(BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen)
{
    BYTE localResponse[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + 100];
    UINT32 localLen;
    BCM_UW_ERROR_MSG_ENUM retVal;
    BYTE deviceIndex;

    do
    {
        // sanity checks
        if (reqLen < BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN)
        {
            retVal = BCM_UW_INVALID_MSG_RX_E;
            localLen = 0;
            break;
        }
        // use stuff from the IP header
        deviceIndex = pReqBuffer[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET];    // take from buffer
        if (deviceIndex >= BCM_UW_DEVICES_NUM)
        {
            retVal = BCM_UW_INVALID_DEVICE_INDEX_E;
            localLen = 0;
            break;
        }

        // try to actually forward to the device
        retVal = bcmUwHostCommMessageForward(deviceIndex,
                                      pReqBuffer + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN, reqLen - BCM_UW_COM_IP_PROTOCOL_HEADER_LEN,
                                      localResponse + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN, &localLen);

        // if we got an error, disregard payload (send only IP header)
        if ( (retVal != BCM_UW_SUCCESS_MSG_E) && (retVal != BCM_UW_BOOT_PLL_ERROR_E) )
        {
            localLen = 0;
            break;
        }
    } while (0);

    // create proper response header
    localResponse[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET] = pReqBuffer[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET];
    localResponse[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET   ] = pReqBuffer[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET   ];
    localResponse[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET ] = retVal;
    localResponse[BCM_UW_COM_IP_PROTOCOL_MODE_OFFSET     ] = 0;

    // copy response to user's buffer and return
    memcpy(pRespBuffer, localResponse, localLen + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN);
    *pRespLen = localLen + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN;
    return(retVal);
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostCommBuildSendAndReceive
///////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommBuildSendAndReceive  (BYTE                        deviceIndex,        // to which device to send
                                                         BYTE                        *pTxPayloadBuff,    // payload to send (not including header or checksum)
                                                         UINT32                      txPayloadLen,       // payload length
                                                         BCM_UW_COM_OPCODE_ENUM      opcode,             // opcode
                                                         BYTE                        modemIndex,         // to which modem
                                                         BYTE                        *pRxPayloadBuff,    // Where to store the received payload (length assumed to be suffient)
                                                         UINT32                      *pActualRxLen,      // Where to indicate actual received payload length
                                                         BCM_UW_ERROR_MSG_ENUM       *pStatus)           // Where to place the status
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];

    //sanity check
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return(BCM_UW_INVALID_DEVICE_INDEX_E);
    }

    // mutex taken within the atomic "send and receive" function
//    bcmUwHostApiMutexGet(deviceIndex);

    // if media not initialized
    if (pDbRecord->comMedia == BCM_UW_COM_MEDIA_NULL_E)
    {
        bcmUwHostApiMutexRelease(deviceIndex);
        return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
    }

    // update nextSeqNum
    pDbRecord->txSeqNum++;
    pDbRecord->txSentOpcode = opcode;

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"CL: Want to send msg, opcode=%u, txSeqNum=%lu\n", opcode, pDbRecord->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK);
    fflush(pfHostMsg);
    #endif

    // build message - TX portion
    bcmUwHcommMessageBuild(pDbRecord,
                           (BYTE)opcode,
                           modemIndex,
                           pTxPayloadBuff,
                           txPayloadLen);

    // build message - RX portion
    pDbRecord->pBufferToReceive = pRxPayloadBuff;
    pDbRecord->pActualRxLen = pActualRxLen;
    pDbRecord->pStatus = pStatus;

    retVal = bcmUwHcommMessageSend(deviceIndex);
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
 //       bcmUwHostApiMutexRelease(deviceIndex);
        return (retVal);
    }
    
//190319   delay_mcs(10000); //100 ms now

    retVal = bcmUwHcommMessageReceive(deviceIndex);
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
  //      bcmUwHostApiMutexRelease(deviceIndex);
       printfp1("\n\rrsv wrong");
        return (retVal);
    }
//    else { 
//     printfp1("\n\rrcv ok");
//   } 

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"CL: Got response to send msg, opcode=%u\n", opcode);
    fflush(pfHostMsg);
    #endif

    // message received ok, return the error code of the messgae
    if (pStatus)
    {
        retVal = *(pDbRecord->pStatus);
//190320        if(flag_read == 3)
        if(flag_read > 6)
        printfpd1(" rec_st %d", *(pDbRecord->pStatus)); //without this print wrong! may be need delay&
    }

//    bcmUwHostApiMutexRelease(deviceIndex);
    return (retVal);
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostCommBuildSend
///////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommBuildSend    (BYTE                       deviceIndex,
                                                 BYTE                       *pTxPayloadBuff,
                                                 UINT32                     txPayloadLen,
                                                 BCM_UW_COM_OPCODE_ENUM     opcode,
                                                 BYTE                       modemIndex)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];

    //sanity check
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return(BCM_UW_INVALID_DEVICE_INDEX_E);
    }

    // mutex taken within the atomic "send" function
    bcmUwHostApiMutexGet(deviceIndex);

    // if media is NULL, cannot do anything, media not initialized
    if (pDbRecord->comMedia == BCM_UW_COM_MEDIA_NULL_E)
    {
        bcmUwHostApiMutexRelease(deviceIndex);
        return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
    }

    // update nextSeqNum
    pDbRecord->txSeqNum++;
    pDbRecord->txSentOpcode = opcode;

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"CL: Want to send tx-only msg, opcode=%d, txSeqNum=%lu\n", opcode, pDbRecord->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK);
    fflush(pfHostMsg);
    #endif

    // build message - TX portion
    bcmUwHcommMessageBuild(pDbRecord,
                           (BYTE)opcode,
                           modemIndex,
                           pTxPayloadBuff,
                           txPayloadLen);

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"CL: Inserted tx-only msg \n");
    fflush(pfHostMsg);
    #endif

    // build message - RX portion
    pDbRecord->pBufferToReceive = NULL;
    pDbRecord->pActualRxLen = NULL;
    pDbRecord->pStatus = NULL;

    retVal = bcmUwHcommMessageSend(deviceIndex);
    bcmUwHostApiMutexRelease(deviceIndex);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommMessageForward(BYTE deviceIndex, BYTE *pReqBuffer, UINT32 reqLen, BYTE *pRespBuffer, UINT32 *pRespLen)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_ERROR_MSG_ENUM forwardingVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"CL: Want to forward msg\n");
    fflush(pfHostMsg);
    #endif

    // check if this device has ever been configured
    if (pDbRecord->comMedia == BCM_UW_COM_MEDIA_NULL_E)
    {
        return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
    }

    // check if forwarding is disabled prior to taking mutex
    if (pDbRecord->enableForwarding == FALSE)
    {
        return(BCM_UW_HOST_BUSY_E);
    }

    // boot message? ignore it with error
    if (reqLen > BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN)
    {
        return(BCM_UW_INVALID_MSG_RX_E);
    }

    // Boot "TX only" opcode? ignore it with error
    if (pReqBuffer[BCM_UW_COM_OPCODE_OFFSET] == BCM_UW_COM_JUMP_TO_FW_MSG_OPCODE_E)
    {
        return(BCM_UW_INVALID_MSG_OPCODE_E);
    }

    bcmUwHostApiMutexGet(deviceIndex);

    do{
        // update nextSeqNum
        pDbRecord->txSeqNum++;
        pDbRecord->txSentOpcode = (BYTE)pReqBuffer[BCM_UW_COM_OPCODE_OFFSET];

        #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"CL: Want to send forward msg, txSeqNum=%lu\n", pDbRecord->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK);
        fflush(pfHostMsg);
        #endif

        // build message - TX portion
        bcmUwHcommMessageBuildForForward(pDbRecord,
                                       pReqBuffer,
                                       reqLen);

        // build message - RX portion
        pDbRecord->pBufferToReceive = pRespBuffer;
        pDbRecord->pActualRxLen     = pRespLen;
        pDbRecord->pStatus          = &forwardingVal;

        #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"CL: Inserted fwd msg \n");
        fflush(pfHostMsg);
        #endif

        // send to dest
        retVal = bcmUwHcommMessageSend(deviceIndex);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            break;
        }

        // receive from dest
        retVal = bcmUwHcommMessageReceive(deviceIndex);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"CL: Got response to fwd msg with error = %d \n", (int)retVal);
                fflush(pfHostMsg);
            #endif

            break;
        }
        else //forwarding OK - overide "local" success with the received "retVal"
        {
            retVal = forwardingVal;
        }

        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"CL: Got response to fwd msg \n");
            fflush(pfHostMsg);
        #endif
    } while(0);

    bcmUwHostApiMutexRelease(deviceIndex);
    return(retVal);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void bcmUwHostCommEnableMessageForwarding(BYTE deviceIndex, BOOLEAN enable)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    pDbRecord->enableForwarding = enable;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHostCommRawDataSend
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommRawDataSend(BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32 chunkLen, sleepTimeMicro;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];

    #ifdef HOST_PROTOCOL_TX_LOG
    fflush(pfHostMsg);
    fseek(pfHostMsg, 0, SEEK_SET);
    fprintf(pfHostMsg,"CL: raw data send\n");
    fflush(pfHostMsg);
    #endif
    switch (pDbRecord->comMedia)
    {
    case BCM_UW_COM_MEDIA_UART_E:
        bcmUwHostUartDataSend(deviceIndex, pBuff, buffLen);
        break;

    case BCM_UW_COM_MEDIA_SPI_E:
        // it takes 320 system clocks to the FW to handle 1 byte (worst case, no cache)
        sleepTimeMicro = (320 * 256)/(pDbRecord->refClockInHz/1000000);

        //set SPI speed to the limit (CPU clock before bootFW defined by API input)
        bcmUwHostSpiMaxRateSet(deviceIndex, pDbRecord->refClockInHz / 32);     // limit to APB/8 = refClock/32

        while (buffLen > 0)
        {
            chunkLen = MIN(buffLen, 256);
            bcmUwHostSpiDataSend(deviceIndex, pBuff, chunkLen);
            buffLen -= chunkLen;
            pBuff += chunkLen;
            bcmUwHostSleep(sleepTimeMicro);
        }

        // set SPI speed to maximal value - CPU clock after bootFW is 500MHz hard-coded
        // calculated as MIN(500MHz/32,8MHz)
        bcmUwHostSpiMaxRateSet(deviceIndex, 8000000); 
        break;

    case BCM_UW_COM_MEDIA_MII_DEVICE_E:
        // Silently ignore - bootFw not injected using raw data, but rather using TFTP
        break;

    case BCM_UW_COM_MEDIA_IP_CLIENT_E:
        // Silently ignore - bootFw not passed from IP client to host
        break;

    default:
        retVal = BCM_UW_MEDIA_NOT_INITIALIZED_E;
        break;
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
UINT32 bcmUwHostCommModifyRxTimeout(BYTE deviceIndex, UINT32 newRxTimeout)
{
    UINT32 temp;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];

    temp = pDbRecord->rxTimeoutMilli;
    pDbRecord->rxTimeoutMilli = newRxTimeout;
    return(temp);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommPostResetActions(BYTE deviceIndex)
{
    // reset destuffing state
    gBcmUwHostCommDatabase[deviceIndex].rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
    // flush pending rx data (UART)
    if (gBcmUwHostCommDatabase[deviceIndex].comMedia == BCM_UW_COM_MEDIA_UART_E)
    {
        bcmUwHostUartReceiverFlush(deviceIndex);
    }

    // got here? everything is OK
    return(BCM_UW_SUCCESS_MSG_E);
}

///////////////////////////////////////////////////////////////////////////////
// Build request message
///////////////////////////////////////////////////////////////////////////////
void bcmUwHcommMessageBuild(BCM_UW_HCOMM_DEVICE_STRUCT  *pEntry,
                            BYTE                         opcode,
                            BYTE                         modemIndex,
                            BYTE                         *pPayload,
                            UINT32                       payloadLen)
{
    UINT32 checksum;

    // copy message payload to fifo entry
    memcpy (pEntry->pTxMsg + BCM_UW_HOST_PROTOCOL_HEADER_LEN, pPayload, payloadLen);
    pEntry->txTotalMsgSize = payloadLen + BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN;

    // handle endian conversion if necessary
    bcmUwEndianRequestParamSwap((BCM_UW_COM_OPCODE_ENUM)opcode, pEntry->pTxMsg + BCM_UW_HOST_PROTOCOL_HEADER_LEN, pEntry->txTotalMsgSize - BCM_UW_HOST_PROTOCOL_HEADER_LEN);

    // build header
    pEntry->pTxMsg[BCM_UW_COM_OPCODE_OFFSET]  = opcode;
    pEntry->pTxMsg[BCM_UW_COM_FLAGS_OFFSET]   = (BYTE)( ((pEntry->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK) << BCM_UW_COM_FLAGS_SEQ_NUM_BIT) |
                                                        ((modemIndex << BCM_UW_COM_FLAGS_MODEM_INDEX_BIT) & (BCM_UW_COM_FLAGS_MODEM_INDEX_MASK << BCM_UW_COM_FLAGS_MODEM_INDEX_BIT)) );
    pEntry->pTxMsg[BCM_UW_COM_CODE_OFFSET]    = 0;
    pEntry->pTxMsg[BCM_UW_COM_MSG_LEN_OFFSET] = (BYTE)(pEntry->txTotalMsgSize - BCM_UW_HOST_PROTOCOL_HEADER_LEN - BCM_UW_CHECKSUM_LEN);

    // insert checksum
    checksum = utilsUwChecksumCalc(0, pEntry->pTxMsg + BCM_UW_COM_OPCODE_OFFSET, pEntry->txTotalMsgSize - BCM_UW_CHECKSUM_LEN - BCM_UW_COM_OPCODE_OFFSET, TRUE);
    memcpy((void*)(pEntry->pTxMsg + pEntry->txTotalMsgSize - BCM_UW_CHECKSUM_LEN), (void*)&checksum, BCM_UW_CHECKSUM_LEN);

    // other message information in entry
    pEntry->forwardedMsg = FALSE;
}

///////////////////////////////////////////////////////////////////////////////
// Build request message
///////////////////////////////////////////////////////////////////////////////
void bcmUwHcommMessageBuildForForward(BCM_UW_HCOMM_DEVICE_STRUCT  *pEntry,
                                      BYTE                         *pBuffer,
                                      UINT32                       bufferLen)
{
    UINT32 checksum;

    // copy the full monty to fifo entry
    memcpy (pEntry->pTxMsg, pBuffer, bufferLen);
    pEntry->txTotalMsgSize = bufferLen;

    // modify header
    pEntry->pTxMsg[BCM_UW_COM_FLAGS_OFFSET] &= (~BCM_UW_COM_FLAGS_SEQ_NUM_MASK << BCM_UW_COM_FLAGS_SEQ_NUM_BIT);                        // clear original(MDP) seqnum
    pEntry->pTxMsg[BCM_UW_COM_FLAGS_OFFSET] |= ((pEntry->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK) << BCM_UW_COM_FLAGS_SEQ_NUM_BIT);    // use local instead

    // recalculate checksum
    checksum = utilsUwChecksumCalc(0, pEntry->pTxMsg + BCM_UW_COM_OPCODE_OFFSET, pEntry->txTotalMsgSize - BCM_UW_CHECKSUM_LEN - BCM_UW_COM_OPCODE_OFFSET, TRUE);
    memcpy((void*)(pEntry->pTxMsg + pEntry->txTotalMsgSize - BCM_UW_CHECKSUM_LEN), (void*)&checksum, BCM_UW_CHECKSUM_LEN);

    // other message information in entry
    pEntry->forwardedMsg = TRUE;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommMessageSend(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;

    #ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"TX: dev=%d\n", deviceIndex);
    fflush(pfHostMsg);
    #endif

    // act on it
    switch (pDbRecord->comMedia)
    {
    case BCM_UW_COM_MEDIA_UART_E:
        bcmUwHcommUartSend(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_SPI_E:
        bcmUwHcommSpiSend(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_MII_DEVICE_E:
        bcmUwHcommMiiDeviceSend(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_IP_CLIENT_E:
        bcmUwHcommIpClientSend(deviceIndex);
        break;

    default:
        // nothing to do when not initialized
        retVal = BCM_UW_MEDIA_NOT_INITIALIZED_E;
        break;
    }

    return(retVal);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHcommTxMessageStuff
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHcommTxMessageStuff(BYTE *pBuff, BYTE *pStuffedBuff, UINT32 buffLen, UINT32 *stuffedLen)
{
    UINT32 ix, jx = 0;

    // initial flag
    pStuffedBuff[jx] = 0x7E;
    jx++;
    // go over the whole input buffer
    for (ix=0; ix<buffLen; ix++)
    {
        if (pBuff[ix] == 0x7E)
        {
            pStuffedBuff[jx] = 0x7D;
            pStuffedBuff[jx+1] = 0x5E;
            jx += 2;
        }
        else if (pBuff[ix] == 0x7D)
        {
            pStuffedBuff[jx] = 0x7D;
            pStuffedBuff[jx+1] = 0x5D;
            jx += 2;
        }
        else
        {
            pStuffedBuff[jx] = pBuff[ix];
            jx++;
        }
    }
    // ending flag
    pStuffedBuff[jx] = 0x7E;
    jx++;

    // copy resulting length
    *stuffedLen = jx;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHcommUartSend(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE pStuffedBuff[2 * BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + 2];     // worst case factor 2x + start / end flags
    UINT32 stuffedBuffLen;
    #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
    #endif

    // stuff the message locally - must happen before releasing the mutex
    bcmUwHcommTxMessageStuff(pDbRecord->pTxMsg, pStuffedBuff, pDbRecord->txTotalMsgSize, &stuffedBuffLen);

    #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"TX: UART (time=%ld, dev=%d): ", bcmUwHostTickGet(), deviceIndex);
        for (ix=0; ix<stuffedBuffLen; ix++)
        {
            fprintf(pfHostMsg,"%02X ",pStuffedBuff[ix]);
        }
        fprintf(pfHostMsg,"\n");
        fflush(pfHostMsg);
    #endif

    // and then send it
    bcmUwHostUartDataSend(deviceIndex, pStuffedBuff, stuffedBuffLen);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHcommSpiSend(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE pStuffedBuff[2 * BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + 2];     // worst case factor 2x + start / end flags
    UINT32 stuffedBuffLen;
 //   #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
//    #endif

    // stuff the message locally - must happen before releasing the mutex
    bcmUwHcommTxMessageStuff(pDbRecord->pTxMsg, pStuffedBuff, pDbRecord->txTotalMsgSize, &stuffedBuffLen);

 //   #ifdef HOST_PROTOCOL_TX_LOG
    //    fprintf(pfHostMsg,"TX:(%d ):", bcmUwHostTickGet(), deviceIndex);
      if(flag_read  > 6)  {
  //        printfpd1("\n\rTX:=%d ", bcmUwHostTickGet());
       printfpd1("\n\rTX(%d)", stuffedBuffLen);    
       for (ix=0; ix<stuffedBuffLen; ix++)
       {
          printfpd1("%02X ",pStuffedBuff[ix]);
       }
      } 
 //       printfp1("\n\r");
 //       fflush(pfHostMsg);
 //   #endif

    // and then send it
    bcmUwHostSpiDataSend(deviceIndex, pStuffedBuff, stuffedBuffLen);
//     delay_mcs(3000000);
    // and reset destuffing state
    pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHcommIpClientSend(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE localMsg[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN];
    UINT32 localLen;
    #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
    #endif

    // make local copy of the message, and add its header - must happen before releasing the mutex
    memcpy(localMsg + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN, pDbRecord->pTxMsg, pDbRecord->txTotalMsgSize);
    localMsg[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET   ] = pDbRecord->pTxMsg[BCM_UW_COM_FLAGS_OFFSET];         // this applies only on the "IP" leg
    localMsg[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET] = pDbRecord->remoteDeviceIndex;                     // this is the host's index
    localMsg[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET ] = BCM_UW_SUCCESS_MSG_E;
    localMsg[BCM_UW_COM_IP_PROTOCOL_MODE_OFFSET     ] = 0;
    localLen = pDbRecord->txTotalMsgSize + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN;

    #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"TX: IPC (dev=%d, localLen=%lu): ", deviceIndex, localLen);
        for (ix=0; ix<localLen; ix++)
        {
            fprintf(pfHostMsg,"%02X ",localMsg[ix]);
        }
        fprintf(pfHostMsg,"\n");
        fflush(pfHostMsg);
    #endif

    // and then send it
    bcmUwHostMIIDataWrite(deviceIndex, localMsg, localLen);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void bcmUwHcommMiiDeviceSend(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
    #endif

    #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"TX: MII (time=%ld, dev=%d): ", bcmUwHostTickGet() , deviceIndex);
        for (ix=0; ix<pDbRecord->txTotalMsgSize; ix++)
        {
            fprintf(pfHostMsg,"%02X ",pDbRecord->pTxMsg[ix]);
        }
        fprintf(pfHostMsg,"\n");
        fflush(pfHostMsg);
    #endif

    // and then send it
    bcmUwHostMIIDataWrite(deviceIndex, pDbRecord->pTxMsg, pDbRecord->txTotalMsgSize);
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommMessageReceive(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;

    switch (pDbRecord->comMedia)
    {
    case BCM_UW_COM_MEDIA_UART_E:
        retVal = bcmUwHcommUartReceive(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_SPI_E:
        retVal = bcmUwHcommSpiReceive(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_MII_DEVICE_E:
        retVal = bcmUwHcommMiiDeviceReceive(deviceIndex);
        break;

    case BCM_UW_COM_MEDIA_IP_CLIENT_E:
        retVal = bcmUwHcommIpClientReceive(deviceIndex);
        break;

    default:
        // nothing to do when not initialized
        retVal = BCM_UW_MEDIA_NOT_INITIALIZED_E;
        break;
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommUartReceive(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE        val;
    BOOLEAN     isComplete = FALSE;
    BOOLEAN     timeout = FALSE;
    UINT32      startTime;
    UINT32      bytesRead;
    UINT32      timeRemainingInMilli = pDbRecord->rxTimeoutMilli;

    startTime = bcmUwHostTickGet();
 //   while (!isComplete)
   if(1) 
    {
    //hier will be added delay
//      delay_mcs(10000);   //10 ms ?
//ok      delay_mcs(500000);   //500 ms
     delay_mcs(100000);  
//      delay_mcs(kdelay * 10);  
      wd_reset();
       OperateBuffers_usart2(); 
    /*
        // support for media change - not expected to occur in typical system
        if (pDbRecord->comMedia != BCM_UW_COM_MEDIA_UART_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: Media changed away from UART?\n");
                fflush(pfHostMsg);
            #endif
            pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
            return (BCM_UW_INVALID_MEDIA_E);
        }

        // what's the time?
        timeRemainingInMilli = pDbRecord->rxTimeoutMilli - (bcmUwHostTickGet() - startTime);
        timeout = timeRemainingInMilli > pDbRecord->rxTimeoutMilli;
        if (timeout)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"UART timeout\n");
                fflush(pfHostMsg);
            #endif
            return(BCM_UW_ERROR_IN_COM_RECEIVE_E);
        }
        // get and process 1 byte at a time
        // receive a byte, wait up to current timeout for each byte (can be any arbitrary)
        bcmUwHostUartDataReceive(deviceIndex, &val, 1, timeRemainingInMilli, &bytesRead);
        */
        // and parse into destuffing SM
   //     if (bytesRead > 0)
        if(RBufu2pos)
        {
        //    #ifdef HOST_PROTOCOL_TX_LOG
        //        fprintf(pfHostMsg,"RX: UART byte (time=%ld, dev=%d): val=%02X\n", bcmUwHostTickGet(), deviceIndex, val);
        //        fflush(pfHostMsg);
       //     #endif

       //     bcmUwHcommRxDestuffMachine(pDbRecord, &val, 1, &isComplete);
         printfpd1("\n\rSR%d>",RBufu2pos);
         bcmUwHcommRxDestuffMachine(pDbRecord, &RBUFU2[0], RBufu2pos, &isComplete);
         RBufu2pos = 0;
        }
        else {
            return(BCM_UW_ERROR_IN_COM_RECEIVE_E);
          }
    }

    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommSpiReceive(BYTE deviceIndex)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE     rxBuf[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BOOLEAN  timeout;
    UINT32   timeRemainingInMilli;
    UINT32   startTime;
    UINT32   estimatedMsgSize;
    BOOLEAN  isComplete = FALSE;

  //  #ifdef HOST_PROTOCOL_TX_LOG
        UINT32 ix;
 //   #endif

    startTime = bcmUwHostTickGet();  // note that on some platforms, this may not be accurate

    #ifndef SPI_POLLING_MODE
        // wait for data ready signal, up to rxTimeoutMilli which should cover common cases
        timeout = bcmUwHostSpiDataReadyWait(deviceIndex, pDbRecord->rxTimeoutMilli);
        if (timeout)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: SPI timeout while waiting for data ready\n");
            #endif
            return(BCM_UW_ERROR_IN_COM_RECEIVE_E);
        }
    #endif

  //  while (!isComplete)
    if(1)
    {
        // support for media change - not expected to occur in typical system
        if (pDbRecord->comMedia != BCM_UW_COM_MEDIA_SPI_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: Media changed away from SPI?\n");
                fflush(pfHostMsg);
            #endif
            pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
            return (BCM_UW_INVALID_MEDIA_E);
        }

        #ifdef SPI_POLLING_MODE
            // in the case where we would like to poll, but not inside message, we should sleep a bit
            if (pDbRecord->rxState == BCM_UW_HCOMM_DESTUFF_IDLE_E ||
                pDbRecord->rxState == BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E)
            {
                // sleep only in polling mode
                bcmUwHostSleep(1000);
            }
        #endif
        
   //      if( flag_read > 1)  delay_mcs(10000);   //80 ms
               
    //           delay_mcs(10000000); 
    //         printfp1("....Waiting .....");  
                
        // what's the time?
   /*
        timeRemainingInMilli = pDbRecord->rxTimeoutMilli - (bcmUwHostTickGet() - startTime);
        timeout = timeRemainingInMilli > pDbRecord->rxTimeoutMilli;
        if (timeout)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: SPI timeout\n");
            #endif
            return(BCM_UW_ERROR_IN_COM_RECEIVE_E);
        }
  */
        // best effort to know how many bytes to read
        estimatedMsgSize = bcmUwHcommSpiEstimatedRxMsgSizeGet(deviceIndex);
//        printfpd1("\n\rGR%d->", estimatedMsgSize);
        estimatedMsgSize += 25;//100320//ok100;//25; //25;//5;
         if(flag_read == 5)    estimatedMsgSize += 150;
         
  //      if(flag_read > 4) printfpd1("\n\rSR%d>", estimatedMsgSize);
        bcmUwHostSpiDataReceive(deviceIndex, gTxSpiFlagsBuf, rxBuf, estimatedMsgSize);

  //      #ifdef HOST_PROTOCOL_TX_LOG
 //190320        if(flag_read  == 3) {
             if(flag_read  > 6) {
                     printfp1("RX: SPI data - ");
            for (ix=0; ix<estimatedMsgSize; ix++)
            {
                printfpd1("%02X ",rxBuf[ix]);
            }
            printfp1("\n\r");
         }   
 //       #endif
//          retVal = BCM_UW_SUCCESS_MSG_E;//t
       retVal = bcmUwHcommRxDestuffMachine(pDbRecord, rxBuf, estimatedMsgSize, &isComplete);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: Destuff machine fatal error?\n");
            #endif
            printfp1(" Destuff wrong ");
            
            return(retVal);
        }
//        else { 
 //t          printfp1(" Destuff ok ");
//      } 
    }

    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommIpClientReceive(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    BYTE localMsg[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN];
    UINT32 localLen;
    BOOLEAN timeout;
    UINT32  timeRemainingInMilli;
    UINT32  startTime;
    BOOLEAN isComplete = FALSE;
    #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
    #endif

    startTime = bcmUwHostTickGet();  // note that on some platforms, this may not be accurate
    while(!isComplete)
    {
        // support for media change - not expected to occur in typical system
        if (pDbRecord->comMedia != BCM_UW_COM_MEDIA_IP_CLIENT_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: Media changed away from IPC?\n");
                fflush(pfHostMsg);
            #endif
            return (BCM_UW_INVALID_MEDIA_E);
        }

        // wait for packet, up to current timeout for it (can be any arbitrary)
        timeRemainingInMilli = pDbRecord->rxTimeoutMilli - (bcmUwHostTickGet() - startTime);// what's the time?
        if (timeRemainingInMilli > pDbRecord->rxTimeoutMilli)
        {
            timeout = TRUE; //remaining time has wrapped around, no point in continuing
        }
        else
        {
            timeout = bcmUwHostMIIDataRead(pDbRecord->deviceIndex, localMsg, sizeof(localMsg), &localLen, timeRemainingInMilli);
        }
        if (timeout)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: IPC timeout\n");
                fflush(pfHostMsg);
            #endif
            return(BCM_UW_HOST_BUSY_E); //IPC timeout (better than BCM_UW_ERROR_IN_COM_RECEIVE_E)
        }

        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"RX: IPC (dev=%d, localLen=%lu): ", deviceIndex, localLen);
            for (ix=0; ix<localLen; ix++)
            {
                fprintf(pfHostMsg,"%02X ",localMsg[ix]);
            }
            fprintf(pfHostMsg,"\n");
            fflush(pfHostMsg);
        #endif

        // disregard anything which does not look like "our" response
        if (localLen < BCM_UW_COM_IP_PROTOCOL_HEADER_LEN)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: IPC disregarding too small packet %lu\n", localLen);
                fflush(pfHostMsg);
            #endif
            continue;
        }

        // skip IP header, and copy internals to local database
        memcpy(pDbRecord->pRxMsg, localMsg + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN, localLen - BCM_UW_COM_IP_PROTOCOL_HEADER_LEN);

        // update message size
        pDbRecord->rxTotalMsgSize = localLen - BCM_UW_COM_IP_PROTOCOL_HEADER_LEN;

        // override fields with content of IP header prior to handling
        // this must be done after valid message checksum (with fields that remote host and FW modified)

        // restore original flags (seq, cpu)
        pDbRecord->pRxMsg[BCM_UW_COM_FLAGS_OFFSET] = localMsg[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET];

        // override error code - add "GW" error code to RX buffer - also if message is only error (localLen=4)
        if (localMsg[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET] != BCM_UW_SUCCESS_MSG_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: override error code with error=%d \n", (int)(localMsg[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET]));
                fflush(pfHostMsg);
            #endif

            pDbRecord->pRxMsg[BCM_UW_COM_CODE_OFFSET] = localMsg[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET];
        }

        // bingo, got a message
        if ( bcmUwHcommRxReceivedMessageHandle(pDbRecord->deviceIndex,
                                        pDbRecord->pRxMsg,
                                        pDbRecord->rxTotalMsgSize) == BCM_UW_SUCCESS_MSG_E)
        {
            isComplete = TRUE;
        }
    }
    return (BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommMiiDeviceReceive(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    UINT32 localLen;
    BOOLEAN timeout;
    UINT32  timeRemainingInMilli;
    UINT32  startTime;
    BOOLEAN isComplete = FALSE;

    #ifdef HOST_PROTOCOL_TX_LOG
    UINT32 ix;
    #endif

    startTime = bcmUwHostTickGet();  // note that on some platforms, this may not be accurate
    while(!isComplete)
    {
        // support for media change - not expected to occur in typical system
        if (pDbRecord->comMedia != BCM_UW_COM_MEDIA_MII_DEVICE_E)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: Media changed away from MII?\n");
                fflush(pfHostMsg);
            #endif
            return (BCM_UW_INVALID_MEDIA_E);
        }

        // wait for packet, up to current timeout for it (can be any arbitrary)
        timeRemainingInMilli = pDbRecord->rxTimeoutMilli - (bcmUwHostTickGet() - startTime);// what's the time?
        if (timeRemainingInMilli > pDbRecord->rxTimeoutMilli)
        {
            timeout = TRUE; //remaining time has wrapped around, no point in continuing
        }
        else
        {
             timeout = bcmUwHostMIIDataRead(pDbRecord->deviceIndex, pDbRecord->pRxMsg, sizeof(pDbRecord->pRxMsg), &localLen, timeRemainingInMilli);
        }
        if (timeout)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: MII timeout\n");
            #endif
            return(BCM_UW_ERROR_IN_COM_RECEIVE_E);
        }

        // disregard anything which does not look like "our" response`
        if (localLen > BCM_UW_HCOMM_MII_DEVICE_MAX_PACKET_LEN)
        {
            #ifdef HOST_PROTOCOL_TX_LOG
                fprintf(pfHostMsg,"RX: MII disregarding too big packet %lu\n", localLen);
                fflush(pfHostMsg);
            #endif
            continue;
        }

        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"RX: MII (time=%ld, dev=%d, len=%ld)\n", bcmUwHostTickGet(), deviceIndex, localLen);
            for (ix=0; ix<localLen; ix++)
            {
                fprintf(pfHostMsg,"%02X ",pDbRecord->pRxMsg[ix]);
            }
            fprintf(pfHostMsg,"\n");
            fflush(pfHostMsg);
        #endif

        // update message size
        pDbRecord->rxTotalMsgSize = localLen;

        // bingo, got a message
        if ( bcmUwHcommRxReceivedMessageHandle(pDbRecord->deviceIndex,
                                        pDbRecord->pRxMsg,
                                        pDbRecord->rxTotalMsgSize) == BCM_UW_SUCCESS_MSG_E)
        {
            isComplete = TRUE;
        }
    }
    return (BCM_UW_SUCCESS_MSG_E);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHcommSpiEstimatedRxMsgSizeGet
/////////////////////////////////////////////////////////////////////////////////
UINT32 bcmUwHcommSpiEstimatedRxMsgSizeGet(BYTE deviceIndex)
{
    BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    UINT32 guessedLen;
    UINT32 remainLen;

    // until we are inside the message, we cannot really know how much data to pull
    if (pDbRecord->rxState == BCM_UW_HCOMM_DESTUFF_IDLE_E ||                 // SM was never run
        pDbRecord->rxState == BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E ||           // flags in between messages
        pDbRecord->rxTotalMsgSize < BCM_UW_HOST_PROTOCOL_HEADER_LEN)   // inside message, but not enough of it received
    {
        return(BCM_UW_HCOMM_SPI_RX_MSG_SMALLEST_SIZE);
    }

    // we have enough of the message to speculate about its length
    guessedLen = pDbRecord->pRxMsg[BCM_UW_COM_MSG_LEN_OFFSET] + BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN;
    if (guessedLen <= pDbRecord->rxTotalMsgSize)
    {
        // this case should not typically occur, perhaps will result in checksum error, message validity issue, etc.?
        return(BCM_UW_HCOMM_SPI_RX_MSG_SMALLEST_SIZE);
    }
    remainLen = guessedLen - pDbRecord->rxTotalMsgSize;
    remainLen += (remainLen / 8);           // make room for stuffing - should be on average 2/256 only
    remainLen = MAX(remainLen, BCM_UW_HCOMM_SPI_RX_MSG_SMALLEST_SIZE);
    remainLen = MIN(remainLen, BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN);
    return(remainLen);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwHcommRxDestuffMachine
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommRxDestuffMachine(BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord,
                                                 BYTE                       *pBytesReceived,
                                                 UINT32                     rxLen,
                                                 BOOLEAN                    *isComplete)
{
 //   BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_INVALID_MSG_RX_E;//BCM_UW_SUCCESS_MSG_E;
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BYTE *pBuff = pDbRecord->pRxMsg;
    BOOLEAN isValid;
    BYTE val;
    UINT32 ix;
 //   printfp1("\n\r bcmUwHcommRxDestuffMachine");

    // assume FALSE until proven otherwise
    *isComplete = FALSE;

    // go over all bytes sequentially
    for (ix=0; ix<rxLen; ix++)
    {
        // extract value
        val = pBytesReceived[ix];
   //     printfpd1("rxs: %d", pDbRecord->rxState);
        // act on value
        switch (pDbRecord->rxState)
        {
        case BCM_UW_HCOMM_DESTUFF_IDLE_E:
            if (val == 0x7E)
            {
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E;
                pDbRecord->rxTotalMsgSize = 0;
            }
            break;

        case BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E:
            if (val == 0x7D)
            {
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_ESC_CODE_DETECTED_E;
            }
            else if (val != 0x7E)
            {
                pBuff[pDbRecord->rxTotalMsgSize] = val;
                pDbRecord->rxTotalMsgSize++;
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IN_MSG_E;
            }
            // else - must be another flag, no action taken
            break;

        case BCM_UW_HCOMM_DESTUFF_IN_MSG_E:
            if (val == 0x7D)
            {
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_ESC_CODE_DETECTED_E;
            }
            else if (val == 0x7E)
            {
                isValid = bcmUwHcommRxMessageIsValid(pDbRecord);
            
            
                if (isValid)
                {
//               printfp1(" Msg Valid! ");
                    // bingo, got a message
                    if ( bcmUwHcommRxReceivedMessageHandle(pDbRecord->deviceIndex,
                                                    pDbRecord->pRxMsg,
                                                    pDbRecord->rxTotalMsgSize) == BCM_UW_SUCCESS_MSG_E)
                    {
                        *isComplete = TRUE;
                        pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E;
                        pDbRecord->rxTotalMsgSize = 0;
            //             printfp1(" IsComplete! ");
                        return(BCM_UW_SUCCESS_MSG_E);
                    }
                    else { 
                           printfp1(" No IsComplete! ");
                  } 
                }
                else { 
                  printfp1(" Msg No Valid! ");
                  } 
                // in any case (good or bad), restart
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_FLAG_FOUND_E;
                pDbRecord->rxTotalMsgSize = 0;
            }
            else // just a regular byte
            {
                pBuff[pDbRecord->rxTotalMsgSize] = val;
                pDbRecord->rxTotalMsgSize++;
            }
            break;

        case BCM_UW_HCOMM_DESTUFF_ESC_CODE_DETECTED_E:
            if (val == 0x5E)
            {
                pBuff[pDbRecord->rxTotalMsgSize] = 0x7E;
                pDbRecord->rxTotalMsgSize++;
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IN_MSG_E;
            }
            else if (val == 0x5D)
            {
                pBuff[pDbRecord->rxTotalMsgSize] = 0x7D;
                pDbRecord->rxTotalMsgSize++;
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IN_MSG_E;
            }
            else
            {
                // FLAG/other while escaped - must be an error, ignore it and skip to next flag
                pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
                // retVal = BCM_UW_ERROR_IN_COM_RECEIVE_E;
            }
            break;

        default:
            pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
        }

        // if message is too long (and did not end by itself), ignore it and skip to next flag
        if (pDbRecord->rxTotalMsgSize > BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN)
   //     if(0)
        {
          printfp1("\n\r too big length! ");
        
            pDbRecord->rxState = BCM_UW_HCOMM_DESTUFF_IDLE_E;
            // retVal = BCM_UW_ERROR_IN_COM_RECEIVE_E;
        }
    }
    return(retVal);
}

///////////////////////////////////////////////////////////////////////////////
// Checks if there is an error in the msg buffer.
// return FALSE if error, else TRUE.
///////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwHcommRxMessageIsValid(BCM_UW_HCOMM_DEVICE_STRUCT *pDbRecord)
{
    UINT32 checksum;

    // check if at least header len and checksum len exist
    if (pDbRecord->rxTotalMsgSize < (BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN))
    {
        return(FALSE);
    }

    // check match between length in header and recieved length
    if ((UINT32)pDbRecord->rxTotalMsgSize !=
        (UINT32)(pDbRecord->pRxMsg[BCM_UW_COM_MSG_LEN_OFFSET] + BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN))
    {
        return(FALSE);
    }

    // compare the message checksum to the calculated checksum
    memcpy((void*)&checksum, &pDbRecord->pRxMsg[pDbRecord->rxTotalMsgSize - BCM_UW_CHECKSUM_LEN], BCM_UW_CHECKSUM_LEN);
    if (checksum != utilsUwChecksumCalc(0, &pDbRecord->pRxMsg[BCM_UW_COM_OPCODE_OFFSET], pDbRecord->rxTotalMsgSize - BCM_UW_CHECKSUM_LEN - BCM_UW_COM_OPCODE_OFFSET, TRUE))
    {
        return(FALSE);
    }

    // passed all filters - bingo, correct
    return(TRUE);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwHcommRxReceivedMessageHandle(BYTE deviceIndex, BYTE *pBufferReceived, UINT32 rxLen)
{
    BCM_UW_HCOMM_DEVICE_STRUCT  *pDbRecord = &gBcmUwHostCommDatabase[deviceIndex];
    UINT32                      rxSequenceNumber = (pBufferReceived[BCM_UW_COM_FLAGS_OFFSET] >> BCM_UW_COM_FLAGS_SEQ_NUM_BIT) & BCM_UW_COM_FLAGS_SEQ_NUM_MASK;
    BCM_UW_ERROR_MSG_ENUM       returnedError = (BCM_UW_ERROR_MSG_ENUM)pBufferReceived[BCM_UW_COM_CODE_OFFSET]; //if was error this value was overwrite by relay
    
    BCM_UW_COM_OPCODE_ENUM      rxOpcode = (BCM_UW_COM_OPCODE_ENUM)pBufferReceived[BCM_UW_COM_OPCODE_OFFSET];
    UINT32                      lenToUser = 0;
    BOOLEAN                     matchFound = FALSE;
//    printfp1("\n\rbcmUwHcommRxReceivedMessageHandle ");
 //t190312   if(flag_read > 0)  printfpd1(" _error %d ", returnedError);
 
//190320     if(flag_read == 3)  printfpd1(" _error %d ", returnedError);   
    if(flag_read > 6)  printfpd1(" _error %d ", returnedError);   
    #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"RX: Handle msg (dev=%d) start\n", deviceIndex);
        fflush(pfHostMsg);
    #endif

    #ifdef HOST_PROTOCOL_TX_LOG
        if (returnedError != BCM_UW_SUCCESS_MSG_E)
        {
            fprintf(pfHostMsg,"RX: Handle msg with error=%d \n", (int)returnedError);
            fflush(pfHostMsg);
        }
    #endif

    //verify input message params
    if ((pDbRecord->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK) != rxSequenceNumber) //verify sequence number match
    {
        //no match, assume rogue reponse, break for loop
        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"RX: Handle msg no match (sequence mismatch) txSeqNum=%lu != rxSequenceNumber=%lu\n", pDbRecord->txSeqNum & BCM_UW_COM_FLAGS_SEQ_NUM_MASK, rxSequenceNumber);
            fflush(pfHostMsg);
        #endif
        return(BCM_UW_INVALID_MSG_RX_E);
    }
    else if ( (pDbRecord->txSentOpcode != rxOpcode) && (rxLen!=0) ) //verify opcode match (should be shlikes)
    {                                                               //note: skip case of RX length zero (error message)
        //no match, assume rogue reponse, break for loop
        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"RX: Handle msg no match (opcode mismatch) txSentOpcode=%d != rxOpcode=%d (rxLen=%lu)\n", pDbRecord->txSentOpcode, rxOpcode, rxLen);
            fflush(pfHostMsg);
        #endif
        return(BCM_UW_INVALID_MSG_RX_E);
    }
    else
    {
        //match
        #ifdef HOST_PROTOCOL_TX_LOG
            fprintf(pfHostMsg,"RX: Handle msg match...\n");
            fflush(pfHostMsg);
        #endif

        // copy data to user's buffer (if given)
        if (pDbRecord->pBufferToReceive) //support data return also for messages returned with error (was - && returnedError == BCM_UW_SUCCESS_MSG_E)
        {
            if (pDbRecord->forwardedMsg) //message relay
            {
                // copy the full monty
                memcpy(pDbRecord->pBufferToReceive,
                       pBufferReceived,
                       rxLen);

                lenToUser = rxLen; // the full monty
            }
            else //local message
            {
                if (rxLen >= (BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN)) // sanity check (for messgaes returned with error)
                {
                    // swap response
                    bcmUwEndianResponseParamSwap(rxOpcode,
                                              &pBufferReceived[BCM_UW_HOST_PROTOCOL_HEADER_LEN],
                                              rxLen - (BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN));

                    // copy just the payload
                    memcpy(pDbRecord->pBufferToReceive,
                           &pBufferReceived[BCM_UW_HOST_PROTOCOL_HEADER_LEN],
                           rxLen - (BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN));

                    lenToUser = rxLen - (BCM_UW_HOST_PROTOCOL_HEADER_LEN + BCM_UW_CHECKSUM_LEN); // just the payload
             //       printfpd1("\n\r>ltu%d",  lenToUser);
                }
            }
        }
        
        if (pDbRecord->pActualRxLen)
        {
            *(pDbRecord->pActualRxLen) = lenToUser; // copy to user's len var
        }
//        printfpd1("\n\rr_status:%d", returnedError);

        if (pDbRecord->pStatus)
        {
        
            *(pDbRecord->pStatus) = returnedError; // copy to user's status var

            #ifdef HOST_PROTOCOL_TX_LOG
                if (returnedError != BCM_UW_SUCCESS_MSG_E)
                {
                    fprintf(pfHostMsg,"RX: copy error=%d \n", (int)returnedError);
                    fflush(pfHostMsg);
                }
            #endif
        }

        // break out of for loop - no point in moving forward
        matchFound = TRUE;
    }

    #ifdef HOST_PROTOCOL_TX_LOG
        fprintf(pfHostMsg,"RX: Handle msg (dev=%d) done\n", deviceIndex);
        fflush(pfHostMsg);
    #endif

    return(BCM_UW_SUCCESS_MSG_E);
}

///////////////////////////////////////////////////////////////////////////////
// Build request/response message
// the function will copy the complete msg to the pRetCompleteBuffer.
///////////////////////////////////////////////////////////////////////////////
void bcmUwResponseMsgBuild(BCM_UW_COM_OPCODE_ENUM opcode, BYTE* pReqBuffer, BYTE* pLocalResponse, UINT32 payloadLen, BCM_UW_ERROR_MSG_ENUM retVal)
{
    BYTE txTotalMsgSize = payloadLen;
    UINT32 checksum;
    BYTE seqNum, deviceId;

    seqNum      = pReqBuffer[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET];
    deviceId    = pReqBuffer[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET];

    //update the Response header
    pLocalResponse[BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET   ] = seqNum;
    pLocalResponse[BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET] = deviceId;
    pLocalResponse[BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET ] = (BYTE)retVal;
    pLocalResponse[BCM_UW_COM_IP_PROTOCOL_MODE_OFFSET     ] = 0;

    if (retVal == BCM_UW_SUCCESS_MSG_E) 
    {
        // build header
        pLocalResponse[BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_COM_OPCODE_OFFSET]  = opcode;
        pLocalResponse[BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_COM_FLAGS_OFFSET]   = seqNum;
        pLocalResponse[BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_COM_CODE_OFFSET]    = 0;
        pLocalResponse[BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_COM_MSG_LEN_OFFSET] = (BYTE)payloadLen - BCM_UW_COM_IP_PROTOCOL_HEADER_LEN - BCM_UW_CHECKSUM_LEN;

        // insert checksum
        checksum = utilsUwChecksumCalc(0, pLocalResponse + BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + BCM_UW_COM_OPCODE_OFFSET, txTotalMsgSize - BCM_UW_CHECKSUM_LEN - BCM_UW_COM_OPCODE_OFFSET, TRUE);
        memcpy((void*)(&pLocalResponse[BCM_UW_COM_IP_PROTOCOL_HEADER_LEN + payloadLen - BCM_UW_CHECKSUM_LEN + BCM_UW_COM_OPCODE_OFFSET]), (void*)&checksum, BCM_UW_CHECKSUM_LEN);
    }
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

