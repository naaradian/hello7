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
* THIS COMPUTER PROGRAM IS PROVIDED “AS IS” WITHOUT ANY WARRANTIES, AND MAXLINEAR, INC.
* EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE WARRANTIES OF
* MERCHANTIBILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NONINFRINGEMENT.
****************************************************************************************
*                                        Copyright (c) 2012, MaxLinear, Inc.
****************************************************************************************/



#include <stdlib.h>
#include "string.h"
#include "defs_uw.h"
#include "utils_uw.h"
#include "hostProtocolStructs.h"
#include "bcm_uw_api.h"
#include "hostCommLayer.h"
#include "hostDriver.h"
#include "deviceconfig.h"
#include "hello7.h"

#include <mqx.h>
#include <bsp.h>
#include <log.h>
#include <klog.h>
#include <rtcs.h>
#include <charq.h>







///////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////
#define BCM_UW_BOOT_IS_ALIVE_TIMEOUT_MILLI          100       //is alive
#define BCM_UW_SPI_MAX_SPEED_MHZ                    8         // max SPI speed
#define BCM_UW_SIGNATURE_LEN                        128
#define FLASH_INDEX_BIT                             7

#define BCM_UW_LONG_API_MAX_TIMEOUT                 (7*60000)

#ifdef WIN32
    #pragma warning( disable : 4996)
#endif

///////////////////////////////////////////////////////////////////////////////
// MACROS
///////////////////////////////////////////////////////////////////////////////
//#define  RETURNED_LENGTH_CHECK(expectedLength)                        \
// if ((retVal == BCM_UW_SUCCESS_MSG_E) && (rxLen != (expectedLength))) \   
//   {                                                                  \
//    retVal = BCM_UW_INVALID_MSG_RX_E;                                 \
//  }
  
#define RETURNED_LENGTH_CHECK(expectedLength)                               \
    if ((retVal == BCM_UW_SUCCESS_MSG_E) && (rxLen != (expectedLength)))    \
    {                                                                       \
        retVal = retVal;         }  
//BCM_UW_INVALID_MSG_RX_E;                                   \
            
             
///////////////////////////////////////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////////////////////////////////////
bcmUwHostMutexHandle gSpiTransactionApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gI2cTransactionApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gModemIqSamplesGetApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gConfigFileLoadApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gDspApplicationLoadApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gDspBlockConfigApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gDspSubsystemConfigApiMutex[BCM_UW_DEVICES_NUM];
bcmUwHostMutexHandle gDspBootLoaderApiMutex[BCM_UW_DEVICES_NUM];


///////////////////////////////////////////////////////////////////////////////
// Local function prototypes
///////////////////////////////////////////////////////////////////////////////
BOOLEAN                 bcmUwIsAlive                (BYTE deviceIndex, UINT32 timeInMs, UINT32 tries);
BCM_UW_ERROR_MSG_ENUM   bcmUwFwSendAndJump          (BYTE deviceIndex, BYTE *pBuffer);
BCM_UW_ERROR_MSG_ENUM   bcmUwDeviceConfigFileParse  (char *pDcFile, UINT32 len, BYTE *pDcStruct);
BOOLEAN                 bcmUwCheckChecksum          (BYTE *pBuffer, UINT32 len);
BCM_UW_ERROR_MSG_ENUM   bcmUwLongApiProbe           (BYTE deviceIndex, BYTE scIndex, BYTE longJobID, UINT32 *internalRxLen, BYTE *retParams);

/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDCVariableSet using lookup table in deviceconfig.c
/////////////////////////////////////////////////////////////////////////////////
void bcmUwDCVariableSet(BYTE *pDcStructValuePos, UINT32 variableIndex, char *pDcFileValuePos)
{
    BYTE       varType;
    char       *ptr;
    BYTE       byt;
    UINT32     i;

    if (variableIndex < BCM_UW_DC_VARS_COUNT)
    {
        // get variable type
        varType = gBcmUwDcVarsTypes[variableIndex];

        // char[16] string case
        if ( varType == VAR_TYPE_TEXT )
        {
            memcpy(pDcStructValuePos, (const char *)pDcFileValuePos, 15);

            // force end of string
            pDcStructValuePos[15]= '\0';

            // find string delimiter
            ptr = strchr((char *)pDcStructValuePos, '"');

            // if found, put end of string at this point
            if (ptr != NULL)
            {
                *ptr = '\0';
            }
        }
        // "int" type case
        else if ( varType == VAR_TYPE_NTEXT )
        {
            i = atoi((const char *)pDcFileValuePos);

            if (utilsUwIsBigEndian())
            {
                i = utilsUwEndianConversion((BYTE*)&i, sizeof(UINT32));
            }
            memcpy(pDcStructValuePos, (BYTE *)&i, sizeof(UINT32));
        }
        else // char case
        {
            byt = (BYTE)atoi((const char *)pDcFileValuePos);

            memcpy(pDcStructValuePos, &byt, 1);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDcFileElementGet
/////////////////////////////////////////////////////////////////////////////////
char *bcmUwDcFileElementGet(char *pDcFilePos, char *element, char **elementPos, UINT32 *elementSize)
{
    char    *elementEnd;
    char    *pos;

    if (pDcFilePos == NULL)
    {
        return NULL;
    }

    // set default: next element not found
    elementEnd = NULL;

    // search for next element name
    pos =  strstr( pDcFilePos, element);

    // element found
    if (pos != NULL)
    {
        // set element position after element declaration
        pos += strlen(element);
        pos = strchr(pos,'\"');

        // start of element found
        if (pos != NULL)
        {
            // point to first char of element
            pos += 1;

            // search for end of element
            elementEnd = strchr(pos, '\"');

            // element end found
            if(elementEnd != NULL)
            {
                // get element size
                *elementSize = elementEnd - pos;
                *elementPos = pos;
            }
        }
    }

    return (elementEnd);
}

/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDcFileVariableValueSet
/////////////////////////////////////////////////////////////////////////////////
char *bcmUwDcFileVariableValueSet(char *pDcFilePos, UINT32 variableIndex, BYTE *pDcStructVariableValue)
{
    char   *valuePos;
    UINT32 valueSize;

    // find value in dc file
    pDcFilePos = bcmUwDcFileElementGet(pDcFilePos, "value=", &valuePos, &valueSize);

    // if found - get value according to type and set it in dc struct buf
    if (pDcFilePos != NULL)
    {
        bcmUwDCVariableSet(pDcStructVariableValue, variableIndex, valuePos);
    }

    return pDcFilePos;
}


/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDcFileVariableIndexGet
/////////////////////////////////////////////////////////////////////////////////
UINT32 bcmUwDcFileVariableIndexGet(char *variableName)
{
  UINT32  index = BCM_UW_DC_VARS_COUNT - 1;
 //  printfp1(" check (");
 //  printfp1(variableName);
 //  printfp1(")" );
 //   printfp1( gBcmUwDcVarsNames[0]);
 //   printfp1( gBcmUwDcVarsNames[1]);
 // search in variables names list (defined at deviceconfig.c)
    for ( index = 0; index < BCM_UW_DC_VARS_COUNT; index++)
     {
        // found - exit
         if ( strcmp(variableName, gBcmUwDcVarsNames[index]) == 0)
        {
   //         printfpd1("S:%d! ",index);
            break;
        }
    }
    return index;
}

/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDcFileNextVariableNameGet
/////////////////////////////////////////////////////////////////////////////////
char *bcmUwDcFileNextVariableNameGet(char *pDcFilePos, char *variableName)
{
    char    *namePos;
    UINT32  nameSize;

    // find variable name in dc file
    pDcFilePos = bcmUwDcFileElementGet(pDcFilePos, "name=", &namePos, &nameSize);

    // found
    if (pDcFilePos != NULL)
    {
        // legal name size
        if (nameSize <= BCM_UW_DC_VARS_NAMES_MAX_SIZE)
        {
            // copy name into null-terminated string
            strncpy(variableName, namePos, nameSize);
            variableName[nameSize] = '\0';
        }
        else
        {
            pDcFilePos = NULL;
        }
    }

    // return position after variable name
    return pDcFilePos;
}

/////////////////////////////////////////////////////////////////////////////////
// FUNCTION: bcmUwDeviceConfigFileParse
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwDeviceConfigFileParse (char* pDcFile, UINT32 len, BYTE *pDcStruct)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    char    variableName[BCM_UW_DC_VARS_NAMES_MAX_SIZE+1];
    UINT32  variableIndex;
    char    *pDcFilePos;
    BYTE    *pDcStructPos;
 //   UINT32 cnt = 5;          //temporary
  

    // point to start of dc file buffer [ null-terminated ]
    pDcFilePos = pDcFile;

    // while next variable exist
    while ((pDcFilePos = bcmUwDcFileNextVariableNameGet(pDcFilePos, variableName)) != NULL)
    {
        // get variable index
    //ok 
        variableIndex = bcmUwDcFileVariableIndexGet(variableName);
//       printfpd1("\n\r i:%d ", variableIndex);
        // get variable position in dc struct
       pDcStructPos = pDcStruct + gBcmUwDcVarsPositions[variableIndex];
//       printfpd1("pS:%x ", (unsigned long)pDcStructPos);
 //    printfpd1("\n\r sweep: %x ", gBcmUwDcVarsPositions[variableIndex]);
//     printfpd1("P: %x ", pDcStructPos);
       // set variable value (can be char, int, or 16-char string) in dc struct buffer
        pDcFilePos = bcmUwDcFileVariableValueSet(pDcFilePos, variableIndex, pDcStructPos);
//        printfpd1("pF:%x ", (unsigned long)pDcFilePos);
   //  if(!cnt--) break;
    }
 
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwIsAlive
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwIsAlive(BYTE deviceIndex, UINT32 timeInMs, UINT32 tries)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;

    BCM_UW_MODEM_VERSION_STRUCT ver;
    UINT32 savedTimeOutMilli;

    // save the current timeout val, and set the new timeout val
    savedTimeOutMilli = bcmUwHostCommModifyRxTimeout(deviceIndex, timeInMs);

    // Sleep 100 ms anyway
    bcmUwHostSleep((UINT32)timeInMs * 1000);

    while (tries)
    {
    delay_mcs(1000000);
        retVal = BCM_UW_API_VersionGet(deviceIndex, &ver);
        printfpd1("\n\r alive : %d", retVal);
        printfpd1("v :%d", ver.majorVersion);
        printfpd1(".%d",ver.minorVersion);
         printfpd1(".%d",ver.buildVersion);
        if (retVal == BCM_UW_INVALID_MSG_OPCODE_E || retVal == BCM_UW_SUCCESS_MSG_E) //12 or 0
        {
            // restore timeout
            (void)bcmUwHostCommModifyRxTimeout(deviceIndex, savedTimeOutMilli);
            printfp1(" alive true ");
            return(TRUE);
        }
       printfpd1(" tries :%d", tries);
        tries--;
    }

    // restore timeout
    (void)bcmUwHostCommModifyRxTimeout(deviceIndex, savedTimeOutMilli);
    return(FALSE);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: bcmUwFwSendAndJump
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwFwSendAndJump(BYTE deviceIndex, BYTE *pBuffer)
{
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_COM_BOOT_HEADER_MSG_STRUCT *pHeader;
    BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT *pRecordHeader;
    BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT nullRecordHeader = {0,0,0};
    INT32 totalLen;
    UINT32 offset = sizeof(UINT32); // skip the burn number
    UINT32 size;
    BOOLEAN bigEndian = utilsUwIsBigEndian();
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    // header message
    pHeader = (BCM_UW_COM_BOOT_HEADER_MSG_STRUCT *)&pBuffer[offset];
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                 (BYTE*)pHeader,
                                 sizeof(BCM_UW_COM_BOOT_HEADER_MSG_STRUCT),
                                 BCM_UW_COM_BOOT_HEADER_MSG_OPCODE_E,
                                 0,
                                 NULL,
                                 &rxLen,
                                 &rxStatus);
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    // skip the SW header and the boot fw
    offset += sizeof(BCM_UW_COM_BOOT_HEADER_MSG_STRUCT) + BCM_UW_BOOT_FW_SIZE_BYTES;

    // data messages
    if (bigEndian)
    {
        totalLen = utilsUwEndianConversion((BYTE*)&pHeader->totalLength, sizeof(UINT32)) - BCM_UW_BOOT_FW_SIZE_BYTES;
    }
    else
    {
        totalLen = pHeader->totalLength - BCM_UW_BOOT_FW_SIZE_BYTES;
    }

    while (totalLen > 0)
    {
 //190320     printfpd1("\rtotl :%d ", totalLen);
      OperateBuffers_usart1t();
      wd_reset();
        // if address bytes are all 0 ==> zero padding reached ==> no more data records to send.
        if (!memcmp(&pBuffer[offset],&nullRecordHeader, 4) || totalLen < sizeof(BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT))
        {
            offset += totalLen;
            break;
        }
        pRecordHeader = (BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT*)&pBuffer[offset];

        if (bigEndian)
        {
            size = utilsUwEndianConversion((BYTE*)&pRecordHeader->size, sizeof(UINT16));
        }
        else
        {
            size = pRecordHeader->size;
        }

 //t       printfp1("\n\r> start send");
 //t       OperateBuffers_usart1t();
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                    (BYTE*)&pBuffer[offset],
                                     sizeof(BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT) + size,
                                     BCM_UW_COM_BOOT_DATA_MSG_OPCODE_E,
                                     0,
                                     NULL,
                                     &rxLen,
                                     &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
          printfp1("\n\r> send wrong");
            return(retVal);
        }
        else { /* Body */
//t            printfp1("\n\r> send ok");
      } /* Endbody */
 //t        OperateBuffers_usart1t();
        //if (totalLen < 0)
        //{
        //    return(BCM_UW_BOOT_DATA_TOO_BIG_E);
        //}

        offset += sizeof(BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT) + size;
        totalLen -= sizeof(BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT) + size;
//t           printfp1("\n\r> next step");
//t            OperateBuffers_usart1t();
    }

    // checksum message
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                 (BYTE*)&pBuffer[offset],
                                 sizeof(UINT32) + BCM_UW_SIGNATURE_LEN,
                                 BCM_UW_COM_BOOT_CHECKSUM_MSG_OPCODE_E,
                                 0,
                                 NULL,
                                 &rxLen,
                                 &rxStatus);
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    // jump message
  //  printfp1("\n\r ...Jump\n\r");
    
    
    retVal = bcmUwHostCommBuildSend(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_JUMP_TO_FW_MSG_OPCODE_E,
                                       0);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN bcmUwCheckChecksum(BYTE *pBuffer, UINT32 len)
{
    UINT32 receivedChecksum;

    // compare the received checksum to the calculated checksum
    
    memcpy(&receivedChecksum, &pBuffer[len - BCM_UW_CHECKSUM_LEN - BCM_UW_SIGNATURE_LEN], BCM_UW_CHECKSUM_LEN);
    
    printfpd1("\n\r chsum : %d\n\r", receivedChecksum);
  
    
    if (utilsUwChecksumCalc(0, &pBuffer[4], len - 4 - BCM_UW_CHECKSUM_LEN - BCM_UW_SIGNATURE_LEN, TRUE) != receivedChecksum) // exclude burn number, checksum and signature
    {
        return(FALSE);
    }
    
//t    return(TRUE);
    return(FALSE); //t

}

//----------------------------------------------------
// Initialization and Communication Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_Open(void)
{
    BCM_UW_ERROR_MSG_ENUM retVal;
    int ix;

    // Initialize host driver
    if (TRUE == bcmUwHostOpen())
    {
        // on error - try to close just the driver
        bcmUwHostClose();
        return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
    }

    // Initialize host communication layer
    retVal = bcmUwHostCommOpen();
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        // on error - try to close the comm layer and then the driver
        bcmUwHostCommClose();
        bcmUwHostClose();
        return(retVal);
    }

    // Initialize API layer globals
    for (ix=0; ix<BCM_UW_DEVICES_NUM; ix++)
    {
    /*
        gSpiTransactionApiMutex[ix]    = bcmUwHostMutexCreate();
        gI2cTransactionApiMutex[ix]    = bcmUwHostMutexCreate();
        gModemIqSamplesGetApiMutex[ix] = bcmUwHostMutexCreate();
        gConfigFileLoadApiMutex[ix]    = bcmUwHostMutexCreate();
        gDspApplicationLoadApiMutex[ix] = bcmUwHostMutexCreate();
        gDspBlockConfigApiMutex[ix]     = bcmUwHostMutexCreate();
        gDspSubsystemConfigApiMutex[ix] = bcmUwHostMutexCreate();
        gDspBootLoaderApiMutex[ix]      = bcmUwHostMutexCreate();
  */
        // on error - close all
        if (gSpiTransactionApiMutex[ix]    == NULL ||
            gI2cTransactionApiMutex[ix]    == NULL ||
            gModemIqSamplesGetApiMutex[ix] == NULL ||
            gConfigFileLoadApiMutex[ix]    == NULL ||
            gDspApplicationLoadApiMutex[ix]== NULL ||
            gDspBlockConfigApiMutex[ix]    == NULL ||
            gDspSubsystemConfigApiMutex[ix]== NULL ||
            gDspBootLoaderApiMutex[ix]     == NULL)
        {
            BCM_UW_API_Close();
            return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
        }
    }

    return(BCM_UW_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_Close(void)
{
    BCM_UW_ERROR_MSG_ENUM retVal;
    BOOLEAN hostRetVal;
    int ix;

    // Close API layer globals
    for (ix=0; ix<BCM_UW_DEVICES_NUM; ix++)
    {
        bcmUwHostMutexDelete(gSpiTransactionApiMutex[ix]);
        bcmUwHostMutexDelete(gI2cTransactionApiMutex[ix]);
        bcmUwHostMutexDelete(gModemIqSamplesGetApiMutex[ix]);
        bcmUwHostMutexDelete(gConfigFileLoadApiMutex[ix]);
        bcmUwHostMutexDelete(gDspApplicationLoadApiMutex[ix]);
        bcmUwHostMutexDelete(gDspBlockConfigApiMutex[ix]);
        bcmUwHostMutexDelete(gDspSubsystemConfigApiMutex[ix]);
        bcmUwHostMutexDelete(gDspBootLoaderApiMutex[ix]);
    }

    // Close host communication layer
    retVal = bcmUwHostCommClose();
    if (BCM_UW_SUCCESS_MSG_E != retVal)
    {
        return(retVal);
    }

    // Close host driver
    hostRetVal = bcmUwHostClose();
    if (TRUE == hostRetVal)
    {
        return(BCM_UW_MEDIA_NOT_INITIALIZED_E);
    }
    return(BCM_UW_SUCCESS_MSG_E);
}




//----------------------------------------------------
// Boot and Configuration Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
// pBuffer - pointer to the FW file that includes:
//           1. Reserved field for burn number
//           2. Header
//           3. Boot FW code padded with zeroes
//           4. Boot FW Signatue
//           5. FW data records * N
//           6. Checksum
//           7. Boot FW Signatue
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, BCM_UW_DEVICE_RESET_TYPE_ENUM reserved)
{
printfp1("\n\r BCM_UW_API_FirmwareFromHostBoot ");
printfpd1( " len %d", len);
//#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
     
    //sanity check
    /* my
    if (len < BCM_UW_BOOT_FW_SIZE_BYTES)
    {
        return(BCM_UW_BOOT_DATA_TOO_SMALL_E);
    }
    if (deviceIndex >= BCM_UW_DEVICES_NUM)
    {
        return(BCM_UW_INVALID_DEVICE_INDEX_E);
    }

    bcmUwHostApiMutexGet(deviceIndex);
      */
      
 //ok   return 0; //t
      
//    if (bcmUwCheckChecksum(pBuffer, len) == FALSE)
    if(0)
    {
    //    bcmUwHostApiMutexRelease(deviceIndex);
        return(BCM_UW_BOOT_INVALID_CHECKSUM_E);
    }

    do
    {
//    printfp1("\n\r Checksum is not checked");
 //      printfp1("\n\r");
        // wait for old APIs to drain out
        bcmUwHostCommEnableMessageForwarding(deviceIndex, FALSE);

        // reset the chip
        bcmUwHostDeviceReset(deviceIndex);

        // inject boot fw - burn number and SW header are skipped.
        retVal = bcmUwHostCommRawDataSend(deviceIndex, &pBuffer[4 + sizeof(BCM_UW_COM_BOOT_HEADER_MSG_STRUCT)], BCM_UW_BOOT_FW_SIZE_BYTES);
//        retVal = bcmUwHostCommRawDataSend(deviceIndex, &pBuffer[0], BCM_UW_BOOT_FW_SIZE_BYTES);
    
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            break;
        }

        // flush pending rx data, start interrupts, etc.
        retVal = bcmUwHostCommPostResetActions(deviceIndex);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            break;
        }
         delay_mcs(2000000);
        // wait up to 1 second for boot fw
        if (bcmUwIsAlive(deviceIndex, BCM_UW_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
        {
     //       printfp1("\n\r is alive 1");
            // send FW and jump
            retVal = bcmUwFwSendAndJump(deviceIndex, pBuffer);  //need set size
            if (retVal != BCM_UW_SUCCESS_MSG_E)
            {
                break;
            }
     //           printfp1("\n\r is alive 2");

            // wait up to 3 seconds for fw
            if (!bcmUwIsAlive(deviceIndex, BCM_UW_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
            {
                retVal = BCM_UW_FW_NOT_ALIVE_E;
            }
        }
        else
        {
            retVal = BCM_UW_BOOT_FW_NOT_ALIVE_E;
        }
    } while (0);

    // end critical section
    bcmUwHostCommEnableMessageForwarding(deviceIndex, TRUE);
    bcmUwHostApiMutexRelease(deviceIndex);
    return(retVal);
//#else
//    return BCM_UW_API_NOT_SUPPORTED_E;
//#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
//#pragma BSS(".buff_2")
extern uchar TFTP_Buffer[TFTP_BUFFER_SIZE];
//#pragma BSS()


BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigure(BYTE       deviceIndex,
                                                 char       *pBuffer,
                                                 UINT32     len,
                                                 BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_ERROR_MSG_ENUM rxStatus;
    UINT32  rxLen;
    BYTE    pDcBuf[BCM_UW_DC_VARS_SIZE];
 //   BYTE * pDcBuf = &TFTP_Buffer[4000000];  //my
     
    BYTE    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    UINT32  dcSize;

    UINT32 bytesToSet;
    BCM_UW_COM_CFG_FILE_CHUNK_STRUCT cfgFileChunk;
    UINT32 bytesSetSoFar = 0;
    printfp1("\n\r  BCM_UW_API_DeviceConfigure");
//ok      return 0;
   // copy defaults from deviceconfig.c
    memcpy(pDcBuf, gBcmUwDcVarsDefaultValues, BCM_UW_DC_VARS_SIZE);
//ok    return 0;
    // parse dc file (pointed by pBuffer) into dc data buffer (BCM_UW_DEVCONF_STRUCT)
    retVal = bcmUwDeviceConfigFileParse(pBuffer, len, pDcBuf);
 //   retVal = 0; //t
 //   printfpd1("ret = %d",  retVal);
  //  return 0;
  //  printfpd1("\n\rParse:%d ", retVal);
    
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        printfp1("..... err get");
        return retVal;
    }

  //  bcmUwHostMutexLock(gConfigFileLoadApiMutex[deviceIndex]);

    cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    dcSize = BCM_UW_DC_VARS_SIZE;

    while (dcSize > 0)
    {
        bytesToSet = MIN(sizeof(cfgFileChunk.pBuffer), dcSize);
        memcpy((BYTE*)cfgFileChunk.pBuffer, &pDcBuf[bytesSetSoFar], bytesToSet);
 //       printfp1("\n\r bytestoset");
 //       printfpd1(" %d", bytesToSet);
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&cfgFileChunk,
                                           (bytesToSet+sizeof(BYTE)), // 1 byte for position
                                           BCM_UW_COM_DEV_CONFIG_FILE_LOAD_OPCODE_E,
                                           0, //device
                                           rxBuffer,
                                           &rxLen,
                                           &rxStatus);
   //     printfpd1("\n\r send ret:%d", retVal);
   //     delay_mcs(100000);
        if ((retVal != BCM_UW_SUCCESS_MSG_E) && (retVal != BCM_UW_BOOT_PLL_ERROR_E))
   //     if(0)
        {
            printfp1("\n\rerr send1");
            bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
            return(retVal);
        }

        dcSize -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (dcSize <= sizeof(cfgFileChunk.pBuffer))
        {
            cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }
        else
        {
            cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }

    bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));

    if ((retVal == BCM_UW_SUCCESS_MSG_E) || (retVal == BCM_UW_BOOT_PLL_ERROR_E))
    {
        memcpy(pDevConfRetStruct, rxBuffer, sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));
    }
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationParameterModify(BYTE   deviceIndex, 
                                                                    char   *paramName, 
                                                                    INT32  paramValue)
{
    BCM_UW_ERROR_MSG_ENUM                       retVal;
    UINT32                                      rxLen;
    BCM_UW_ERROR_MSG_ENUM                       rxStatus;
    UINT16                                      paramIndex;
    BYTE                                        paramType;
    BCM_UW_COM_DEVICE_CFG_PARAM_MODIFY_STRUCT   dCs;

    paramIndex = bcmUwDcFileVariableIndexGet(paramName);
    if (paramIndex == BCM_UW_DC_VARS_COUNT) //parameter not found
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }
    
    paramType = gBcmUwDcVarsTypes[paramIndex]; 
    if ( paramType == VAR_TYPE_TEXT ) //type not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    dCs.paramOffset = gBcmUwDcVarsPositions[paramIndex];
    dCs.paramValue  = paramValue;
    dCs.paramLength = ( paramType == VAR_TYPE_NTEXT ) ? sizeof(UINT32) : sizeof(BYTE);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&dCs,
                                       sizeof(BCM_UW_COM_DEVICE_CFG_PARAM_MODIFY_STRUCT),
                                       BCM_UW_COM_DEV_CONFIG_PARAM_MODIFY_OPCODE_E,
                                       0, //device
                                       NULL,
                                       &rxLen,
                                       &rxStatus);
    printfp1("\n\r Parameter Modify :");
    printfpd1(" %d ", retVal);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationStringParameterModify(BYTE   deviceIndex, 
                                                                      char   *paramName, 
                                                                      char   *paramValue)
{
    BCM_UW_ERROR_MSG_ENUM                           retVal;
    UINT32                                          rxLen;
    BCM_UW_ERROR_MSG_ENUM                           rxStatus;
    UINT16                                          paramIndex;
    BYTE                                            paramType;
    BCM_UW_COM_DEVICE_CFG_STRING_PARAM_MODIFY_STRUCT dCs;

    paramIndex = bcmUwDcFileVariableIndexGet(paramName);
    if (paramIndex == BCM_UW_DC_VARS_COUNT) //parameter not found
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }
    
    paramType = gBcmUwDcVarsTypes[paramIndex];
    if ( paramType != VAR_TYPE_TEXT ) //type not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }
     
    dCs.paramOffset = gBcmUwDcVarsPositions[paramIndex];
    dCs.paramLength = 16* sizeof(BYTE);

    memcpy(dCs.paramValue, paramValue, dCs.paramLength); 

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&dCs,
                                       sizeof(BCM_UW_COM_DEVICE_CFG_STRING_PARAM_MODIFY_STRUCT),
                                       BCM_UW_COM_DEV_CONFIG_STRING_PARAM_MODIFY_OPCODE_E,
                                       0, //device
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationStart(BYTE deviceIndex, BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_DEV_CONFIG_START_OPCODE_E,
                                       0, //device
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pDevConfRetStruct, rxBuffer, sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));
        printfp1(" dev cfg success ");
    }
    else { /* Body */
       printfp1(" dev cfg start wrong ");
       printfpd1(" %d ", retVal);
   } /* Endbody */

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationResultGet(BYTE deviceIndex, BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_DEV_CONFIG_RESULT_GET_OPCODE_E,
                                       0, //device
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pDevConfRetStruct, rxBuffer, sizeof(BCM_UW_DEVCONF_STATUS_STRUCT));
           printfp1("\n\r ans ok! ");

    }
    else { /* Body */
    printfp1("\n\r ans wrong! ");
   } /* Endbody */

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ConfigFileFromHostLoad(BYTE       deviceIndex,
                                                        BYTE       scIndex,
                                                        BYTE       *pBuffer,
                                                        UINT32     len) // in bytes
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_ERROR_MSG_ENUM perRetVal = BCM_UW_SUCCESS_MSG_E;
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    UINT32 bytesToSet;
    BCM_UW_COM_CFG_FILE_CHUNK_STRUCT cfgFileChunk;
    UINT32 bytesSetSoFar = 0;
    BYTE longJobID;

    //sanity check
    if (len < sizeof(BCM_UW_COM_MODEM_CONFIG_FILE_HEADER_STRUCT))
    {
        return BCM_UW_ERROR_CFG_FILE_LEN_TOO_SMALL_E;
    }

    // Function uses specific mutex
    bcmUwHostMutexLock(gConfigFileLoadApiMutex[deviceIndex]);

    cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    while (len > 0)
    {
        bytesToSet = MIN(sizeof(cfgFileChunk.pBuffer), len);
   //     printfpd1("\n\r bts:%d", bytesToSet);
  //      printfpd1("len:%d\n\r", len);

        memcpy((BYTE*)cfgFileChunk.pBuffer, &pBuffer[bytesSetSoFar], bytesToSet);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&cfgFileChunk,
                                           (bytesToSet + sizeof(BYTE)), // 1 byte for position
                                           BCM_UW_COM_LOAD_CONFIG_FILE_OPCODE_E,
                                           scIndex,
                                           &longJobID,
                                           &rxLen,
                                           &rxStatus);
                                           
  //      printfpd1("\n\ret %d\n\r", retVal);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            //handle peripheral error - store for API end
            if ( retVal == BCM_UW_PERIPHERAL_INVALID_SLAVE_ADDRESS_E ||
                 retVal == BCM_UW_PERIPHERAL_NOT_READY_E             ||
                 retVal == BCM_UW_PERIPHERAL_SPI_ERROR_E             ||
                 retVal == BCM_UW_PERIPHERAL_I2C_ERROR_E )
            {
                perRetVal = retVal;
                printfp1("\n\r wrong send1\n\r");
                break;
            }
            else
            {
                bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
                  printfpd1("\n\rwsd2 %d\n\r", retVal);

                return(retVal);
            }
        }

        retVal = bcmUwLongApiProbe(deviceIndex, scIndex, longJobID, &rxLen, NULL);
    //    printfpd1("\n\rretp:%d ", retVal);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
                  printfp1("\n\r wrong send3\n\r");

            return(retVal);
        }        

        len -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (len <= sizeof(cfgFileChunk.pBuffer))
        {
            cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }
        else
        {
            cfgFileChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
        
        OperateBuffers_usart1t();   
    }
    
 //   printfp1("\n\r send run "); 
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_RUN_CONFIG_FILE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);
//    printfpd1(" ret : %d", retVal);
    if (retVal == BCM_UW_SUCCESS_MSG_E) //overide retVal with perpheral retVal
    {
        retVal = perRetVal;
          printfp1(" cfg file  success ");
    }
    else { /* Body */
    printfp1(" cfg file  wrong ");
   } /* Endbody */

    bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ConfigFileExFromHostLoad(BYTE      deviceIndex,
                                                          BYTE      scIndex,
                                                          BYTE      *pTxBin,
                                                          UINT32    lenTx,
                                                          BYTE      *pRxBin,
                                                          UINT32    lenRx)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ASYMMETRY_CONFIG_EN_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    retVal = BCM_UW_API_ConfigFileFromHostLoad(deviceIndex, scIndex, pTxBin, lenTx);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    retVal = BCM_UW_API_ConfigFileFromHostLoad(deviceIndex, scIndex, pRxBin, lenRx);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationStart(BYTE    deviceIndex,
                                                    BYTE    scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_TX_RX_START_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationControlSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_TXRXOP_CONTROL_STRUCT *pTxRxOpCtrlStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)pTxRxOpCtrlStruct,
                                              sizeof(BCM_UW_TXRXOP_CONTROL_STRUCT),
                                              BCM_UW_COM_TX_RX_CTRL_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_TXRXOP_STATUS_STRUCT *txRxOpStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_TXRXOP_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_TXRXOP_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(txRxOpStruct, rxBuffer, sizeof(BCM_UW_TXRXOP_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_VersionGet(BYTE deviceIndex, BCM_UW_MODEM_VERSION_STRUCT *pVer)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_VERSION_GET_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

  //t  RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_VERSION_STRUCT));
    printfpd1("ret ver %d", retVal);
     printfpd1("_rxStatus %d",rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
      printfp1(" ok ");
       memcpy(pVer, rxBuffer, sizeof(BCM_UW_MODEM_VERSION_STRUCT));
    }
    else { /* Body */
    printfp1(" wrong ");
        memcpy(pVer, "00000000000000000000", sizeof(BCM_UW_MODEM_VERSION_STRUCT));

   } /* Endbody */

    return(retVal);
}

//----------------------------------------------------
// Host-related and General Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmEnableGet(BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsMask)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ALARM_ENABLE_GET_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ALARMS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pAlarmsMask, rxBuffer, sizeof(BCM_UW_ALARMS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmEnableSet(BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsMask)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)pAlarmsMask,
                                       sizeof(BCM_UW_ALARMS_STRUCT),
                                       BCM_UW_COM_ALARM_ENABLE_SET_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmStatusGet(BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ALARM_STATUS_GET_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ALARMS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pAlarmsStatus, rxBuffer, sizeof(BCM_UW_ALARMS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HostInfoGet(BYTE deviceIndex, BCM_UW_HOST_INFO_STRUCT *pInfo)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_HOST_INFO_GET_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_HOST_INFO_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pInfo, rxBuffer, sizeof(BCM_UW_HOST_INFO_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HostInfoSet(BYTE deviceIndex, BCM_UW_HOST_INFO_STRUCT *pInfo)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pInfo,
                                       sizeof(BCM_UW_HOST_INFO_STRUCT),
                                       BCM_UW_COM_HOST_INFO_SET_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_MailboxMessageSend(BYTE deviceIndex, BYTE scIndex, BCM_UW_MAILBOX_MESSAGE_STRUCT *pMbx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)pMbx,
                                       pMbx->msgLen + sizeof(pMbx->msgLen),
                                       BCM_UW_COM_MAILBOX_MESSAGE_SEND_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_MailboxMessageReceive(BYTE deviceIndex, BYTE scIndex, BCM_UW_MAILBOX_MESSAGE_STRUCT *pMbx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);


    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        BCM_UW_MAILBOX_MESSAGE_STRUCT *pRxMbx = (BCM_UW_MAILBOX_MESSAGE_STRUCT*)rxBuffer;

        RETURNED_LENGTH_CHECK(sizeof(pRxMbx->msgLen) + pRxMbx->msgLen);

        if (retVal == BCM_UW_SUCCESS_MSG_E)
        {
            memcpy((BYTE*)pMbx, rxBuffer, sizeof(BCM_UW_MAILBOX_MESSAGE_STRUCT));
        }
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TestBusSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_TESTBUS_SEL_ENUM testBus1, BCM_UW_TESTBUS_SEL_ENUM testBus2)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_TESTBUS_STRUCT testBusStruct;

    testBusStruct.testBus1 = (BYTE)testBus1; //handle ENUM
    testBusStruct.testBus2 = (BYTE)testBus2; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                 (BYTE*)&testBusStruct,
                                                 sizeof(BCM_UW_COM_TESTBUS_STRUCT),
                                                 BCM_UW_COM_TESTBUS_SET_OPCODE_E,
                                                 scIndex,
                                                 NULL,
                                                 &rxLen,
                                                 &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_InjectionBusSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_INJECTION_SEL_ENUM injSel)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)injSel; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                 &temp,
                                                 sizeof(temp),
                                                 BCM_UW_COM_INJECTION_SET_OPCODE_E,
                                                 scIndex,
                                                 NULL,
                                                 &rxLen,
                                                 &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PvtmonRead(BYTE deviceIndex, BCM_UW_PVTMON_STRUCT *pVts)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_PVTMON_GET_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_PVTMON_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pVts, rxBuffer, sizeof(BCM_UW_PVTMON_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsProcess(BYTE deviceIndex, BOOLEAN restart)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&restart,
                                       sizeof(BYTE),
                                       BCM_UW_COM_AVS_PROCESS_SET_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsStatusGet(BYTE deviceIndex, BCM_UW_AVS_STATUS_STRUCT *pData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_AVS_STATUS_GET_OPCODE_E,
                                              0, 
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_AVS_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pData, rxBuffer, sizeof(BCM_UW_AVS_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsRecommendedLvmGet(BYTE deviceIndex, BYTE *lvm)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    longJobID;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_AVS_REC_LVM_GET_OPCODE_E,
                                              0,
                                              &longJobID,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, rxBuffer); 
    }

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        *lvm = rxBuffer[0];
    }

    return(retVal);
}

//----------------------------------------------------
// Modem Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_STATUS_STRUCT *pMs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_STATUS_STRUCT));
 
 //   printfpd1(" rl:%d ", rxLen);
 //   printfpd1(" el:%d ",sizeof(BCM_UW_MODEM_STATUS_STRUCT));
    
    if (retVal == BCM_UW_SUCCESS_MSG_E)
 //   if(1)
    {
 //   printfp1("\n\r ret ok");
        memcpy(pMs, rxBuffer, sizeof(BCM_UW_MODEM_STATUS_STRUCT));
    } else { /* Body */
       printfp1("\n\rret wrong");
       printfpd1(" %d ", retVal);
   } /* Endbody */

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcquireCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT *pAc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pAc, rxBuffer, sizeof(BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemFecCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_FEC_COUNTERS_STRUCT *pFc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_FEC_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pFc, rxBuffer, sizeof(BCM_UW_MODEM_FEC_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqImbalanceStatusGet(BYTE deviceIndex,
                                                           BYTE scIndex,
                                                           BCM_UW_MODEM_IQ_IMBALANCE_STATUS_STRUCT *pIs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_IQ_IMBALANCE_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pIs, rxBuffer, sizeof(BCM_UW_MODEM_IQ_IMBALANCE_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemEqualizerStatusGet(BYTE                               deviceIndex,
                                                         BYTE                               scIndex,
                                                         BOOLEAN                            xpicSlave,
                                                         BCM_UW_MODEM_EQU_STATUS_STRUCT     *pEs)
{
    BCM_UW_MODEM_CHAIN_ENUM chain = (xpicSlave==FALSE) ? BCM_UW_CHAIN_MAIN_E : BCM_UW_CHAIN_XPIC_SLAVE_E;
    return BCM_UW_API_ModemEqualizerExStatusGet(deviceIndex, scIndex, chain, pEs);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemEqualizerExStatusGet(BYTE                             deviceIndex,
                                                           BYTE                             scIndex,
                                                           BCM_UW_MODEM_CHAIN_ENUM          chain,
                                                           BCM_UW_MODEM_EQU_STATUS_STRUCT   *pEs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    ix;
    UINT32                  *pTemp;

    BYTE chainRequest = (BYTE)chain; //handle ENUM

    //EQU - 1st chunk = 160Byte
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &chainRequest,
                                       sizeof(BYTE),
                                       BCM_UW_COM_MODEM_EQUALIZER_STATUS_GET0_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(40 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        //fill backwards compatible struct
        pTemp = ((UINT32*)rxBuffer) +16;
        for(ix=0;ix<24;ix++)
        {
            pEs->fffTaps[ix] = (UINT16)(((*pTemp)>>4)&0XFFFF);
            pTemp++;
        }
        //fill struct
        memcpy((BYTE*)pEs->fffTaps_20Bit, rxBuffer, 40*sizeof(UINT32));
    }
    else
    {
        return(retVal);
    }

    //EQU - 2nd chunk = 160Byte
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &chainRequest,
                                       sizeof(BYTE),
                                       BCM_UW_COM_MODEM_EQUALIZER_STATUS_GET1_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(40 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        //fill backwards compatible struct
        pTemp = ((UINT32*)rxBuffer);
        for(ix=0;ix<24;ix++)
        {
            pEs->fffTaps[24+ix] = (UINT16)(((*pTemp)>>4)&0XFFFF);
            pTemp++;
        }
        //fill struct
        memcpy((BYTE*)(pEs->fffTaps_20Bit+40), rxBuffer, 40*sizeof(UINT32));
    }

    //EchoCanceler = 128Byte
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &chainRequest,
                                       sizeof(BYTE),
                                       BCM_UW_COM_MODEM_ECHO_CANCELER_EQUALIZER_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(33 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        //fill struct
        memcpy((BYTE*)pEs->ec1Taps_20Bit, rxBuffer, 16*sizeof(UINT32));
        memcpy((BYTE*)pEs->ec2Taps_20Bit, rxBuffer + (16*sizeof(UINT32)), 16*sizeof(UINT32));
        memcpy((BYTE*)&pEs->ec1Delay, rxBuffer + (32*sizeof(UINT32)), 2*sizeof(UINT16));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemXpicStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_XPIC_STATUS_STRUCT *pXs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_XPIC_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_XPIC_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pXs, rxBuffer, sizeof(BCM_UW_MODEM_XPIC_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRsHistGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_RS_HIST_GET_STRUCT *pRhs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_RS_HIST_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_RS_HIST_GET_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pRhs, rxBuffer, sizeof(BCM_UW_MODEM_RS_HIST_GET_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREDISTORTION_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_PREDISTORTION_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pPs, rxBuffer, sizeof(BCM_UW_MODEM_PREDISTORTION_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsSet(BYTE deviceIndex,
                                                            BYTE scIndex,
                                                            BCM_UW_MODEM_PREDISTORTION_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)pPs,
                                       sizeof(BCM_UW_MODEM_PREDISTORTION_STRUCT),
                                       BCM_UW_COM_MODEM_PREDISTORTION_COEFS_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsExGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_EX_PREDISTORTION_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_PREDISTORTION_COEFS_EX_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_EX_PREDISTORTION_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pPs, rxBuffer, sizeof(BCM_UW_MODEM_EX_PREDISTORTION_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsExSet(BYTE deviceIndex,
                                                              BYTE scIndex,
                                                              BCM_UW_MODEM_EX_PREDISTORTION_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)pPs,
                                       sizeof(BCM_UW_MODEM_EX_PREDISTORTION_STRUCT),
                                       BCM_UW_COM_MODEM_PREDISTORTION_COEFS_EX_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPreemphasisCoefsGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREEMPHASIS_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_PREEMPHASIS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pPs, rxBuffer, sizeof(BCM_UW_MODEM_PREEMPHASIS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPreemphasisCoefsSet(BYTE deviceIndex,
                                                          BYTE scIndex,
                                                          BCM_UW_MODEM_PREEMPHASIS_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pPs,
                                       sizeof(BCM_UW_MODEM_PREEMPHASIS_STRUCT),
                                       BCM_UW_COM_MODEM_PREEMPHASIS_COEFS_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesGet(BYTE deviceIndex, BYTE scIndex, UINT16 numIqPairs, INT16 *pBuffer, BCM_UW_IQ_SAMPLES_SEL_ENUM inputSel)
{
    BCM_UW_ERROR_MSG_ENUM               retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_COM_IQ_SAMPLES_REC_STRUCT    iqSamplesRecParams;
    BCM_UW_COM_IQ_SAMPLES_REC_STRUCT    iqSamplesGetParams;
    UINT16                              numIqPairsChuckSize = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN / (2 * sizeof(UINT16));
    UINT16                              bufferIndex = 0;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BYTE                                rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    if (numIqPairs > 4096) //sanity check
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    // Function uses specific mutex
    bcmUwHostMutexLock(gModemIqSamplesGetApiMutex[deviceIndex]);

    iqSamplesRecParams.numIqPairs  = numIqPairs;
    iqSamplesRecParams.testBusSel  = (BYTE)inputSel; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&iqSamplesRecParams,
                                       sizeof(BCM_UW_COM_IQ_SAMPLES_REC_STRUCT),
                                       BCM_UW_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
        return(retVal);
    }

    bcmUwHostSleep(4000); // 4 msec, to ensure snapshot recording is done

    // start receiving data, assuming that by the time the msgs
    // reach destination, all required data has been recorded already (takes uSec)

    while (numIqPairs > 0)
    {
        iqSamplesGetParams.numIqPairs = (numIqPairs < numIqPairsChuckSize) ? numIqPairs : numIqPairsChuckSize;
        iqSamplesGetParams.testBusSel = (BYTE)inputSel;

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&iqSamplesGetParams,
                                           sizeof(BCM_UW_COM_IQ_SAMPLES_REC_STRUCT),
                                           BCM_UW_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E,
                                           scIndex,
                                           rxBuffer,
                                           &rxLen,
                                           &rxStatus);

        RETURNED_LENGTH_CHECK(iqSamplesGetParams.numIqPairs * 2 * sizeof(UINT16));

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
            return(retVal);
        }

        memcpy(pBuffer+bufferIndex, rxBuffer, iqSamplesGetParams.numIqPairs * 2 * sizeof(UINT16));
        bufferIndex += (iqSamplesGetParams.numIqPairs) * 2;

        if (numIqPairs < 60)
        {
            numIqPairs = 0; // out of while loop
        }
        else
        {
            numIqPairs -= numIqPairsChuckSize;
        }
    }

    bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesExGet(BYTE deviceIndex, BYTE scIndex, UINT32 *pBuffer, BCM_UW_IQ_SAMPLES_SEL_ENUM inputSel)
{
    BCM_UW_ERROR_MSG_ENUM               retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_COM_IQ_SAMPLES_REC_STRUCT    iqSamplesRecParams;
    UINT16                              samplesLeftToSend = 4096; //full OCLA
    UINT16                              samplesToGet;
    UINT16                              samplesPerTransmit = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN / (2 * sizeof(UINT32)); //High+Low (36bit)
    UINT16                              bufferIndex = 0;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BYTE                                rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    // Function uses specific mutex
    bcmUwHostMutexLock(gModemIqSamplesGetApiMutex[deviceIndex]);

    iqSamplesRecParams.numIqPairs  = samplesLeftToSend;
    iqSamplesRecParams.testBusSel  = (BYTE)inputSel; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&iqSamplesRecParams,
                                       sizeof(BCM_UW_COM_IQ_SAMPLES_REC_STRUCT),
                                       BCM_UW_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
        return(retVal);
    }

    bcmUwHostSleep(4000); // 4 msec, to ensure snapshot recording is done

    // start receiving data, assuming that by the time the msgs
    // reach destination, all required data has been recorded already (takes uSec)

    while (samplesLeftToSend > 0)
    {
        samplesToGet = (samplesLeftToSend < samplesPerTransmit) ? samplesLeftToSend : samplesPerTransmit;

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&samplesToGet,
                                           sizeof(UINT16),
                                           BCM_UW_COM_MODEM_IQ_SAMPLES_EX_GET_OPCODE_E,
                                           scIndex,
                                           rxBuffer,
                                           &rxLen,
                                           &rxStatus);

        RETURNED_LENGTH_CHECK(samplesToGet * 2 * sizeof(UINT32)); //High+Low (36bit)

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
            return(retVal);
        }

        memcpy((BYTE*)(pBuffer+bufferIndex), rxBuffer, samplesToGet * 2 * sizeof(UINT32)); //High+Low (36bit)
        bufferIndex += samplesToGet * 2;

        if (samplesLeftToSend < samplesPerTransmit)
        {
            samplesLeftToSend = 0; // out of while loop
        }
        else
        {
            samplesLeftToSend -= samplesToGet;
        }
    }

    bcmUwHostMutexUnlock(gModemIqSamplesGetApiMutex[deviceIndex]);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesSourceSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_TESTBUS_SEL_ENUM source)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                 (BYTE*)&source,
                                                 sizeof(BYTE),
                                                 BCM_UW_COM_MODEM_IQ_SAMPLES_SOURCE_SET_OPCODE_E,
                                                 scIndex,
                                                 NULL,
                                                 &rxLen,
                                                 &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcquireStart(BYTE                                 deviceIndex,
                                                   BYTE                                 scIndex,
                                                   BCM_UW_ACQUIRE_MODE_ENUM             acqMode,
                                                   BCM_UW_SPECTRAL_INVERSION_MODE_ENUM  siMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ACQUIRE_STRUCT acquireParams;

    acquireParams.acqMode = (BYTE)acqMode; //handle ENUM
    acquireParams.siMode = (BYTE)siMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&acquireParams,
                                       sizeof(BCM_UW_COM_ACQUIRE_STRUCT),
                                       BCM_UW_COM_ACQUIRE_START_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PreambleSet(BYTE   deviceIndex,
                                             BYTE   scIndex,
                                             BYTE   index)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    if (index > 3)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&index,
                                       sizeof(BYTE),
                                       BCM_UW_COM_PREAMBLE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxIqDelaySet(BYTE      deviceIndex,
                                              BYTE      scIndex,
                                              INT16     fdfFracDelay)
{
    BCM_UW_ERROR_MSG_ENUM       retVal;
    UINT32                      rxLen;
    BCM_UW_ERROR_MSG_ENUM       rxStatus;
    INT16                       tempFracDelay = fdfFracDelay;

    if ( (tempFracDelay > (7*1024)) || (tempFracDelay < -((7*1024)-1)) ) //sanity check (-7,7]
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&tempFracDelay,
                                       sizeof(INT16),
                                       BCM_UW_COM_MODEM_TX_IQ_DELAY_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetSet(BYTE deviceIndex, BYTE scIndex, INT32  offsetInKHz)
{
    return(BCM_UW_API_RxFreqOffsetExSet(deviceIndex, scIndex, (BCM_UW_MODEM_CHAIN_ENUM)0, offsetInKHz));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetSlaveSet(BYTE deviceIndex, BYTE scIndex, INT32 offsetInKHz)
{
    return(BCM_UW_API_RxFreqOffsetExSet(deviceIndex, scIndex, (BCM_UW_MODEM_CHAIN_ENUM)1, offsetInKHz));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetExSet(BYTE                     deviceIndex,
                                                   BYTE                     scIndex,
                                                   BCM_UW_MODEM_CHAIN_ENUM  chain,
                                                   INT32                    offsetInKHz)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_FREQ_OFFSET_STRUCT freqOffsetSt;

    //parameters validation
    if (chain == BCM_UW_CHAIN_MRCX_DIVERSITY_SLAVE_E) //also BCM_UW_CHAIN_MIMOX_SPATIAL_SLAVE_E
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    freqOffsetSt.chain       = (BYTE)chain; //handle ENUM
    freqOffsetSt.offsetInKHz = offsetInKHz;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&freqOffsetSt,
                                       sizeof(BCM_UW_COM_FREQ_OFFSET_STRUCT),
                                       BCM_UW_COM_MODEM_RX_FREQ_OFFSET_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxFreqOffsetSet(BYTE   deviceIndex,
                                                 BYTE   scIndex,
                                                 INT32  offsetInKHz)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    //parameters validation
    if (offsetInKHz > 200000 || offsetInKHz < -200000) 
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&offsetInKHz,
                                       sizeof(INT32),
                                       BCM_UW_COM_MODEM_TX_FREQ_OFFSET_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelaySet(BYTE deviceIndex, BYTE scIndex, BYTE delay)
{
    return(BCM_UW_API_ModemRxChainDelaySet(deviceIndex, scIndex, (BCM_UW_MODEM_CHAIN_ENUM)1, delay));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicSlaveMuteSet(BYTE deviceIndex, BYTE scIndex, BOOLEAN mute)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&mute,
                                       sizeof(BYTE),
                                       BCM_UW_COM_MODEM_MUTE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicToFddSet(BYTE    deviceIndex,
                                              BYTE    scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_XPIC_TO_FDD_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelayCalibrationStart(BYTE deviceIndex, BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_XPIC_DELAY_CALIBRATION_START_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelayCalibrationStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_XPIC_DELAY_CALIB_STRUCT *xpicDelayCalibStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_XPIC_DELAY_CALIBRATION_STATUS_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_XPIC_DELAY_CALIB_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)xpicDelayCalibStruct, rxBuffer, sizeof(BCM_UW_XPIC_DELAY_CALIB_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxChainDelaySet(BYTE                      deviceIndex,
                                                      BYTE                      scIndex,
                                                      BCM_UW_MODEM_CHAIN_ENUM   chain,
                                                      BYTE                      delay)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_XPIC_DELAY_STRUCT equDelaySet;

    equDelaySet.chain = (BYTE)chain; //handle ENUM
    equDelaySet.delay = delay;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&equDelaySet,
                                       sizeof(BCM_UW_COM_XPIC_DELAY_STRUCT),
                                       BCM_UW_COM_MODEM_DELAY_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxChainDelayGet(BYTE                      deviceIndex,
                                                      BYTE                      scIndex,
                                                      BCM_UW_MODEM_CHAIN_ENUM   chain,
                                                      BYTE                      *delay)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    
    BYTE chainRequest = (BYTE)chain; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &chainRequest,
                                              sizeof(BYTE),
                                              BCM_UW_COM_MODEM_DELAY_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        *delay = rxBuffer[0];
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_STATUS_STRUCT *pPs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_PROTECTION_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_PROTECTION_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pPs, rxBuffer, sizeof(BCM_UW_PROTECTION_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionModeSet(BYTE                            deviceIndex,
                                                   BYTE                            scIndex,
                                                   BCM_UW_PROTECTION_MODE_ENUM     protectionMode,
                                                   BCM_UW_PROTECTION_SYS_MODE_ENUM protectionSysMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_PROTECTION_MODE_STRUCT protModeSt;

    protModeSt.protectionMode    = (BYTE)protectionMode; //handle ENUM
    protModeSt.protectionSysMode = (BYTE)protectionSysMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&protModeSt,
                                       sizeof(BCM_UW_COM_PROTECTION_MODE_STRUCT),
                                       BCM_UW_COM_PROTECTION_MODE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionTxRxPhyIdSet(BYTE   deviceIndex,
                                                        BYTE   scIndex,
                                                        BYTE   txPhyId,
                                                        BYTE   rxPhyId)
{
    return BCM_UW_API_ProtectionTxRxPhyIdExSet(deviceIndex, scIndex, txPhyId, rxPhyId, 0); //no protectionTxPhyId
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionRxForceSet(BYTE                         deviceIndex,
                                                      BYTE                         scIndex,
                                                      BCM_UW_PROTECTION_MODE_ENUM  protectionMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)protectionMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                (BYTE *)&temp,
                                                sizeof(temp),
                                                BCM_UW_COM_PROTECTION_RX_FORCE_SET_OPCODE_E,
                                                scIndex,
                                                NULL,
                                                &rxLen,
                                                &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionTxRxPhyIdExSet(BYTE  deviceIndex,
                                                          BYTE  scIndex,
                                                          BYTE  txPhyId,
                                                          BYTE  rxPhyId,
                                                          BYTE  protectionTxPhyId)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_PROTECTION_TX_RX_PHYID_STRUCT phyIdStruct;

    phyIdStruct.txPhyId           = txPhyId;
    phyIdStruct.rxPhyId           = rxPhyId;
    phyIdStruct.protectionTxPhyId = protectionTxPhyId;
    
 //   printfpd1("\n\rsize:%d\n\r", sizeof(BCM_UW_COM_PROTECTION_TX_RX_PHYID_STRUCT));

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                               (BYTE*)&phyIdStruct,
                                               sizeof(BCM_UW_COM_PROTECTION_TX_RX_PHYID_STRUCT),
                                               BCM_UW_COM_PROTECTION_TX_RX_PHYID_SET_OPCODE_E,
                                               scIndex,
                                               NULL,
                                               &rxLen,
                                               &rxStatus);
//    printfpd1("\n\rretvalP:%d\n\r", retVal);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemLockCriteriaSet(BYTE                              deviceIndex,
                                                      BYTE                              scIndex,
                                                      BCM_UW_MODEM_LOCK_CRITERIA_ENUM   modemLockCriteria)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)modemLockCriteria; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&temp,
                                       sizeof(temp),
                                       BCM_UW_COM_ACQUIRE_LOCK_CRITERIA_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxFreqLimitSet(BYTE deviceIndex, BYTE scIndex, UINT16 fc0FreqLimitKHz)
{
    BCM_UW_ERROR_MSG_ENUM       retVal;
    UINT32                      rxLen;
    BCM_UW_ERROR_MSG_ENUM       rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&fc0FreqLimitKHz,
                                       sizeof(UINT16),
                                       BCM_UW_COM_MODEM_RX_FREQ_LIMIT_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

//----------------------------------------------------
// Modem Modes
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_MRC_STATUS_STRUCT *pStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    ind;

    //get MRC status
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_MRC_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_MODEM_MRC_STATUS_STRUCT)-(64*2*sizeof(UINT32)) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pStat, rxBuffer, sizeof(BCM_UW_MODEM_MRC_STATUS_STRUCT)-(64*2*sizeof(UINT32)) );
    }

    //get MRC combiner taps (16 master - first part)
    ind = 0;
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &ind,
                                       sizeof(ind),
                                       BCM_UW_COM_MODEM_MRC_COMBINER_EQU_STATUS_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(32 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)&pStat->combinerTapsMain[0], rxBuffer, 32*sizeof(UINT32));
    }

    //get MRC combiner taps (16 master - second part)
    ind = 1;
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &ind,
                                       sizeof(ind),
                                       BCM_UW_COM_MODEM_MRC_COMBINER_EQU_STATUS_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(32 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)&pStat->combinerTapsMain[32], rxBuffer, 32*sizeof(UINT32));
    }

    //get MRC combiner taps (16 diversity - first part)
    ind = 2;
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &ind,
                                       sizeof(ind),
                                       BCM_UW_COM_MODEM_MRC_COMBINER_EQU_STATUS_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(32 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)&pStat->combinerTapsDiversity[0], rxBuffer, 32*sizeof(UINT32));
    }

    //get MRC combiner taps (16 diversity - second part)
    ind = 3;
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &ind,
                                       sizeof(ind),
                                       BCM_UW_COM_MODEM_MRC_COMBINER_EQU_STATUS_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(32 * sizeof(UINT32));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)&pStat->combinerTapsDiversity[32], rxBuffer, 32*sizeof(UINT32));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoStatusGet(BYTE deviceIndex,
                                                    BYTE scIndex,
                                                    BCM_UW_MODEM_MIMO_STATUS_STRUCT* pStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_MIMO_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_MIMO_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pStat, rxBuffer, sizeof(BCM_UW_MODEM_MIMO_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoConfigurationSet(BYTE deviceIndex,
                                                           BYTE scIndex,
                                                           BCM_UW_MODEM_MIMO_CONFIGURATION_STRUCT *pConfig)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pConfig,
                                       sizeof(BCM_UW_MODEM_MIMO_CONFIGURATION_STRUCT),
                                       BCM_UW_COM_MIMO_CONFIGURE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoXcDelayCalibrationStart(BYTE deviceIndex,
                                                                  BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MIMO_DELAY_CALIB_START_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoXcDelayCalibrationStatusGet(BYTE deviceIndex,
                                                                      BYTE scIndex,
                                                                      BCM_UW_CALIB_STATUS_ENUM *xcCalibStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_MIMO_DELAY_CALIB_STATUS_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        *xcCalibStatus = (BCM_UW_CALIB_STATUS_ENUM)rxBuffer[0]; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoDiversityMuteSet(BYTE deviceIndex, BYTE scIndex, BOOLEAN mute)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&mute,
                                       sizeof(BYTE),
                                       BCM_UW_COM_MIMO_DIVERSITY_MUTE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcXcDelayCalibrationStart(BYTE deviceIndex,
                                                                  BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MRC_DELAY_CALIB_START_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcXcDelayCalibrationStatusGet(BYTE deviceIndex,
                                                                      BYTE scIndex,
                                                                      BCM_UW_CALIB_STATUS_ENUM *xcCalibStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_MRC_DELAY_CALIB_STATUS_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        *xcCalibStatus = (BCM_UW_CALIB_STATUS_ENUM)rxBuffer[0]; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RepeaterModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_REPEATER_MODE_ENUM upLinkMode, BCM_UW_REPEATER_MODE_ENUM downLinkMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_REPEATER_MODE_STRUCT rMs;

    rMs.upLinkMode   = (BYTE)upLinkMode;    //handle ENUM
    rMs.downLinkMode = (BYTE)downLinkMode;  //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&rMs,
                                              sizeof(BCM_UW_COM_REPEATER_MODE_STRUCT),
                                              BCM_UW_COM_MODEM_REPEATER_MODE_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RepeaterBaudSet(BYTE deviceIndex, BYTE scIndex, UINT32 upLinkBaudKhz, UINT32 downLinkBaudKhz)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_REPEATER_BAUD_STRUCT rBs;

    rBs.upLinkBaudKhz   = upLinkBaudKhz;
    rBs.downLinkBaudKhz = downLinkBaudKhz;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&rBs,
                                              sizeof(BCM_UW_COM_REPEATER_BAUD_STRUCT),
                                              BCM_UW_COM_MODEM_REPEATER_BAUD_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

//----------------------------------------------------
// Modem Filters
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemTxOutputFilterSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT *pTxOutFilter)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)pTxOutFilter,
                                              sizeof(BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT),
                                              BCM_UW_COM_MODEM_TX_OUTPUT_FILTER_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemTxOutputFilterGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT *pTxOutFilter)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_MODEM_TX_OUTPUT_FILTER_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pTxOutFilter, rxBuffer, sizeof(BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_MODE_ENUM adpdMode)
{
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   retVal;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)adpdMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&temp,
                                              sizeof(temp),
                                              BCM_UW_COM_ADPD_MODE_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdCalibrationStart(BYTE deviceIndex, BYTE scIndex)
{
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               retVal;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_ADPD_CALIB_START_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdCalibrationStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *adpdCalibStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    tempVal;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_ADPD_CALIB_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&tempVal, rxBuffer, sizeof(BYTE));
        *adpdCalibStatus = (BCM_UW_CALIB_STATUS_ENUM)tempVal; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdGearShiftSet(BYTE deviceIndex, BYTE scIndex, BOOLEAN isFastGear)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BYTE                            tempIsFastGear;

    tempIsFastGear = (BYTE)isFastGear;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &tempIsFastGear,
                                              sizeof(BYTE),
                                              BCM_UW_COM_ADPD_GEAR_SHIFT_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdAutoModeConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_AUTO_MODE_CONFIGURE_STRUCT *pAdpdAutoModeConfig)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)pAdpdAutoModeConfig,
                                              sizeof(BCM_UW_ADPD_AUTO_MODE_CONFIGURE_STRUCT),
                                              BCM_UW_COM_ADPD_AUTO_MODE_CONFIGURE_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdSystemFreeze(BYTE deviceIndex, BYTE scIndex, BOOLEAN isFreeze)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    longJobID;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&isFreeze,
                                              sizeof(isFreeze),
                                              BCM_UW_COM_ADPD_SYSTEM_FREEZE_OPCODE_E,
                                              scIndex,
                                              &longJobID,
                                              &rxLen,
                                              &rxStatus);
    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex, scIndex, longJobID, &rxLen, NULL); 
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_STATUS_STRUCT *adpdStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_ADPD_STATUS_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ADPD_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)adpdStatus, rxBuffer, sizeof(BCM_UW_ADPD_STATUS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerDelaySet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, UINT16 ec1Delay, UINT16 ec2Delay)
{
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   retVal;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ECHO_CANCELER_DELAY_STRUCT ecDelaySt;

    ecDelaySt.delay1 = ec1Delay;
    ecDelaySt.delay2 = ec2Delay;
    ecDelaySt.chain  = (BYTE)chain;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ecDelaySt,
                                              sizeof(BCM_UW_COM_ECHO_CANCELER_DELAY_STRUCT),
                                              BCM_UW_COM_ECHO_CANCELER_DELAY_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerCalibrationStart(BYTE deviceIndex, BYTE scIndex, UINT16 cableLengthMetersMin, UINT16 cableLengthMetersMax)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_ECHO_CANCELER_CABLE_STRUCT ecCableSt;

    ecCableSt.cableMin = cableLengthMetersMin;
    ecCableSt.cableMax = cableLengthMetersMax;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ecCableSt,
                                              sizeof(BCM_UW_COM_ECHO_CANCELER_CABLE_STRUCT),
                                              BCM_UW_COM_ECHO_CANCELER_CALIB_START_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerCalibrationStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *ecCalibStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    tempVal;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_ECHO_CANCELER_CALIB_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&tempVal, rxBuffer, sizeof(BYTE));
        *ecCalibStatus = (BCM_UW_CALIB_STATUS_ENUM)tempVal; //handle ENUM
    }

    return(retVal);
}

//----------------------------------------------------
// Diagnostic Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_LoopbackSet(BYTE deviceIndex, BCM_UW_LOOPBACK_STRUCT *lb)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    //parameter validation
    if (lb->loopbackType == BCM_UW_LOOPBACK_INTERFACE_E)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)lb,
                                       sizeof(BCM_UW_LOOPBACK_STRUCT),
                                       BCM_UW_COM_LOOPBACK_SET_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_CONFIG_STRUCT *digConfig)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)digConfig,
                                       sizeof(BCM_UW_DIG_CONFIG_STRUCT),
                                       BCM_UW_COM_DIG_CONFIGURE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigExConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_CONFIG_EX_STRUCT *digConfig)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)digConfig,
                                       sizeof(BCM_UW_DIG_CONFIG_EX_STRUCT),
                                       BCM_UW_COM_DIG_CONFIGURE_EX_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigNotchSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_NOTCH_STRUCT *digNotch)
{
    BCM_UW_ERROR_MSG_ENUM retVal;
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)digNotch,
                                       sizeof(BCM_UW_DIG_NOTCH_STRUCT),
                                       BCM_UW_COM_DIG_NOTCH_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigPaSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_PA_STRUCT *digPa)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)digPa,
                                       sizeof(BCM_UW_DIG_PA_STRUCT),
                                       BCM_UW_COM_DIG_PA_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_BerMonitorEnable(BYTE deviceIndex, BYTE scIndex, BOOLEAN enable)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&enable,
                                       sizeof(BYTE),
                                       BCM_UW_COM_BER_ENABLE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_BerCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_BER_COUNTERS_STRUCT *pBerCountersStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_BER_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_BER_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pBerCountersStruct, rxBuffer, sizeof(BCM_UW_BER_COUNTERS_STRUCT));
    }

    return(retVal);
}

//----------------------------------------------------
// ACM Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_COUNTERS_STRUCT *pMc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ACM_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ACM_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pMc, rxBuffer, sizeof(BCM_UW_ACM_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmConfigurationGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_CONFIGURATION_STRUCT *pCs)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ACM_CONFIGURATION_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ACM_CONFIGURATION_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pCs, rxBuffer, sizeof(BCM_UW_ACM_CONFIGURATION_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdGet(BYTE                         deviceIndex,
                                                      BYTE                         scIndex,
                                                      BCM_UW_ACM_TABLE_ENUM        engineTable,
                                                      BCM_UW_ACM_PROFILE_ENUM      profile,
                                                      INT16                        *mseTenthsVal,
                                                      BYTE                         *ldpcMantissaTenths,
                                                      BYTE                         *ldpcExponent,
                                                      BCM_UW_ACM_CRITERIA_ENUM     *criteria,
                                                      BCM_UW_ACM_PROFILE_ENUM      *nextProfile)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_ACM_THRESHOLD_STRUCT acmThresholdGetStruct;

    acmThresholdGetStruct.isChannelImproveTable = (BOOLEAN)engineTable; //handle ENUM
    acmThresholdGetStruct.profile               = (BYTE)profile; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmThresholdGetStruct,
                                       sizeof(BCM_UW_COM_ACM_THRESHOLD_STRUCT),
                                       BCM_UW_COM_ACM_THRESHOLD_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_COM_ACM_THRESHOLD_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&acmThresholdGetStruct, rxBuffer, sizeof(BCM_UW_COM_ACM_THRESHOLD_STRUCT));
        *mseTenthsVal       = acmThresholdGetStruct.mseTenthsVal;
        *ldpcMantissaTenths = acmThresholdGetStruct.ldpcMantissaTenths;
        *ldpcExponent       = acmThresholdGetStruct.ldpcExponent;
        *criteria           = (BCM_UW_ACM_CRITERIA_ENUM)acmThresholdGetStruct.criteria; //handle ENUM
        *nextProfile        = (BCM_UW_ACM_PROFILE_ENUM)acmThresholdGetStruct.nextProfile; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdSet(BYTE                      deviceIndex,
                                                      BYTE                      scIndex,
                                                      BCM_UW_ACM_TABLE_ENUM     engineTable,
                                                      BCM_UW_ACM_PROFILE_ENUM   profile,
                                                      INT16                     mseTenthsVal,
                                                      BYTE                      ldpcMantissaTenths,
                                                      BYTE                      ldpcExponent,
                                                      BCM_UW_ACM_CRITERIA_ENUM  criteria,
                                                      BCM_UW_ACM_PROFILE_ENUM   nextProfile)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BCM_UW_COM_ACM_THRESHOLD_STRUCT acmThresholdSetStruct;

    acmThresholdSetStruct.isChannelImproveTable = (BOOLEAN)engineTable; //handle ENUM
    acmThresholdSetStruct.profile               = (BYTE)profile; //handle ENUM
    acmThresholdSetStruct.mseTenthsVal          = mseTenthsVal;
    acmThresholdSetStruct.ldpcMantissaTenths    = ldpcMantissaTenths;
    acmThresholdSetStruct.ldpcExponent          = ldpcExponent;
    acmThresholdSetStruct.criteria              = (BYTE)criteria; //handle ENUM
    acmThresholdSetStruct.nextProfile           = (BYTE)nextProfile; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmThresholdSetStruct,
                                       sizeof(BCM_UW_COM_ACM_THRESHOLD_STRUCT),
                                       BCM_UW_COM_ACM_THRESHOLD_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdXpdGet(BYTE                       deviceIndex,
                                                         BYTE                       scIndex,
                                                         BCM_UW_ACM_TABLE_ENUM      engineTable,
                                                         BCM_UW_ACM_PROFILE_ENUM    profile,
                                                         UINT16                     *xpdTenthsVal)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT acmThresholdXpdGetStruct;

    acmThresholdXpdGetStruct.isChannelImproveTable = (BOOLEAN)engineTable; //handle ENUM
    acmThresholdXpdGetStruct.profile               = (BYTE)profile; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmThresholdXpdGetStruct,
                                       sizeof(BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT),
                                       BCM_UW_COM_ACM_THRESHOLD_XPD_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&acmThresholdXpdGetStruct, rxBuffer, sizeof(BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT));
        *xpdTenthsVal = acmThresholdXpdGetStruct.xpdTenthsVal;
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdXpdSet(BYTE                       deviceIndex,
                                                         BYTE                       scIndex,
                                                         BCM_UW_ACM_TABLE_ENUM      engineTable,
                                                         BCM_UW_ACM_PROFILE_ENUM    profile,
                                                         UINT16                     xpdTenthsVal)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT acmThresholdXpdSetStruct;

    acmThresholdXpdSetStruct.isChannelImproveTable = (BOOLEAN)engineTable; //handle ENUM
    acmThresholdXpdSetStruct.profile               = (BYTE)profile; //handle ENUM
    acmThresholdXpdSetStruct.xpdTenthsVal          = xpdTenthsVal;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmThresholdXpdSetStruct,
                                       sizeof(BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT),
                                       BCM_UW_COM_ACM_THRESHOLD_XPD_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmProfileMaskGet(BYTE    deviceIndex,
                                                        BYTE    scIndex,
                                                        UINT16  *profilesMask)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ACM_PROFILE_MASK_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(UINT16));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(profilesMask, rxBuffer, sizeof(UINT16));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmProfileEnable(BYTE     deviceIndex,
                                                       BYTE     scIndex,
                                                       UINT16   profilesMask)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&profilesMask,
                                       sizeof(UINT16),
                                       BCM_UW_COM_ACM_PROFILE_ENABLE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmEnhancedEngineModeGet(BYTE deviceIndex,
                                                          BYTE scIndex,
                                                          BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM *acmEnhancedEngineModeGet)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    tempVal;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_ACM_ENHANCED_ENGINE_MODE_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&tempVal, rxBuffer, sizeof(BYTE));
        *acmEnhancedEngineModeGet = (BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM)tempVal; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmEnhancedEngineModeSet(BYTE deviceIndex,
                                                          BYTE scIndex,
                                                          BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM acmEnhancedEngineModeSet)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE modeSet = (BYTE)acmEnhancedEngineModeSet; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &modeSet,
                                       sizeof(BYTE),
                                       BCM_UW_COM_ACM_ENHANCED_ENGINE_MODE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmEngineEnable(BYTE      deviceIndex,
                                                      BYTE      scIndex,
                                                      BOOLEAN   enableRxSensors,
                                                      BOOLEAN   enableTxSwitch)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ACM_ENABLE_STRUCT    acmEnable;

    acmEnable.enableRxSensors = enableRxSensors;
    acmEnable.enableTxSwitch = enableTxSwitch;
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmEnable,
                                       sizeof(BCM_UW_COM_ACM_ENABLE_STRUCT),
                                       BCM_UW_COM_ACM_ENGINE_ENABLE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmSwitch(BYTE                    deviceIndex,
                                                BYTE                    scIndex,
                                                BCM_UW_ACM_PROFILE_ENUM acmProfile,
                                                BOOLEAN                 isLocal)
{
    BCM_UW_ERROR_MSG_ENUM           retVal;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_ACM_SWITCH_STRUCT    acmSwitchParam;

    acmSwitchParam.acmProfile = (BYTE)acmProfile; //handle ENUM
    acmSwitchParam.isLocal    = isLocal;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmSwitchParam,
                                       sizeof(BCM_UW_COM_ACM_SWITCH_STRUCT),
                                       BCM_UW_COM_ACM_SWITCH_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmImproveIfNeeded(BYTE deviceIndex, BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal =  bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                        NULL,
                                        0,
                                        BCM_UW_COM_ACM_IMPROVE_OPCODE_E,
                                        scIndex,
                                        NULL,
                                        &rxLen,
                                        &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemGpmDynamicAllocationSet(BYTE      deviceIndex,
                                                              BYTE      scIndex,
                                                              UINT32    profile,
                                                              UINT32    gpiBwKbps,
                                                              UINT32    ethBwKbps,
                                                              UINT32    txRxMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ACM_GPM_DA_STRUCT acmGpmDynamicAllocationParams;

    acmGpmDynamicAllocationParams.profile   = profile;
    acmGpmDynamicAllocationParams.gpiBwKbps = gpiBwKbps;
    acmGpmDynamicAllocationParams.ethBwKbps = ethBwKbps;
    acmGpmDynamicAllocationParams.txRxMode  = txRxMode; //[0]TX+RX [1]TX [2]RX

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmGpmDynamicAllocationParams,
                                       sizeof(BCM_UW_COM_ACM_GPM_DA_STRUCT),
                                       BCM_UW_COM_ACM_GPM_DYNAMIC_ALLOCATION_SET_OPCODE,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmTxPowerGainUpdate(BYTE     deviceIndex,
                                                      BYTE     scIndex,
                                                      BYTE     profile,
                                                      UINT16   txGain)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ACM_TX_GAIN_STRUCT acmTxGainStruct;

    acmTxGainStruct.profile = profile;
    acmTxGainStruct.txGain  = txGain;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&acmTxGainStruct,
                                       sizeof(BCM_UW_COM_ACM_TX_GAIN_STRUCT),
                                       BCM_UW_COM_ACM_TX_POWER_GAIN_UPDATE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

//----------------------------------------------------
// Networking Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetFixedLatencySet(BYTE deviceIndex, BYTE scIndex, BYTE usecTenths)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                 &usecTenths,
                                                 sizeof(BYTE),
                                                 BCM_UW_COM_NET_FIXED_LATENCY_SET_OPCODE_E,
                                                 scIndex,
                                                 NULL,
                                                 &rxLen,
                                                 &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetAsymmetryDelayGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_FIFO_LEVELS_STRUCT *pFifoLevelStruct)
{
    UINT32                 rxLen;
    BCM_UW_ERROR_MSG_ENUM  retVal;
    BCM_UW_ERROR_MSG_ENUM  rxStatus;
    BYTE                   rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_NET_ASYM_DELAY_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_MODEM_FIFO_LEVELS_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {       
       memcpy((BYTE*)pFifoLevelStruct, rxBuffer, sizeof(BCM_UW_MODEM_FIFO_LEVELS_STRUCT));       
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_STATUS_STRUCT *plaStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    //parameter validation
    if (scIndex == 1)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_PLA_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_PLA_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(plaStatus, rxBuffer, sizeof(BCM_UW_PLA_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaLimitAcmSet(BYTE    deviceIndex,
                                                BYTE    scIndex,
                                                UINT16  plaAcmRatioHundredths)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    //parameter validation
    if (scIndex == 1)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&plaAcmRatioHundredths,
                                       sizeof(UINT16),
                                       BCM_UW_COM_PLA_ACM_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaLimitMseSet(BYTE  deviceIndex,
                                                BYTE  scIndex,
                                                INT16 mseThrLowTenths,
                                                INT16 mseThrHighTenths)
{
    BCM_UW_ERROR_MSG_ENUM                retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                               rxLen;
    BCM_UW_ERROR_MSG_ENUM                rxStatus;
    BCM_UW_COM_PLA_MSE_LIMIT_STRUCT      plaMseLimitStruct;

    //parameters validation
    if ( (scIndex == 1) || (mseThrHighTenths > mseThrLowTenths) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    plaMseLimitStruct.mseThrLowTenths  = mseThrLowTenths;
    plaMseLimitStruct.mseThrHighTenths = mseThrHighTenths;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&plaMseLimitStruct,
                                       sizeof(BCM_UW_COM_PLA_MSE_LIMIT_STRUCT),
                                       BCM_UW_COM_PLA_MSE_LIMIT_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_MODE_ENUM mode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)mode; //handle ENUM

    //parameter validation
    if (scIndex == 1)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &temp,
                                       sizeof(temp),
                                       BCM_UW_COM_PLA_MODE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaForceSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_FORCE_ENUM txForce, BCM_UW_PLA_FORCE_ENUM rxForce)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_PLA_FORCE_STRUCT plaForce;

    plaForce.txForce = (BYTE)txForce; //handle ENUM
    plaForce.rxForce = (BYTE)rxForce; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&plaForce,
                                       sizeof(BCM_UW_COM_PLA_FORCE_STRUCT),
                                       BCM_UW_COM_PLA_FORCE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_COUNTERS_STRUCT *plaCounters)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_PLA_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_PLA_COUNTERS_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)plaCounters, rxBuffer, sizeof(BCM_UW_PLA_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaCountersClear(BYTE deviceIndex, BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_PLA_COUNTERS_CLEAR_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PeerDeviceSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_API_PEER_DEVICE_ENUM peerDevice)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)peerDevice; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       &temp,
                                       sizeof(temp),
                                       BCM_UW_COM_PLA_PEER_DEVICE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationSizeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_FRAG_SIZE_ENUM fragSize)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)fragSize; //handle ENUM

    //parameter validation
    if (fragSize > BCM_UW_FRAG_SIZE_INIFINITE_E)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&temp,
                                       sizeof(temp),
                                       BCM_UW_COM_NET_FRAGMENTATION_SIZE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_FRAG_COUNTERS_STRUCT *fragCounters)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_NET_FRAGMENTATION_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_FRAG_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)fragCounters, rxBuffer, sizeof(BCM_UW_FRAG_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationCountersClear(BYTE deviceIndex, BYTE scIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_NET_FRAGMENTATION_COUNTERS_CLEAR_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxMacFifoStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MAC_FIFO_STATUS_STRUCT *fifoStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_NET_MACFIFO_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_MAC_FIFO_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)fifoStatus, rxBuffer, sizeof(BCM_UW_MAC_FIFO_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxMacFifoIndicationSet(BYTE deviceIndex, BYTE scIndex, BOOLEAN enable, UINT16 highPrioFlowFifoLevelTh, BYTE highPrioIndGPIO, UINT16 lowPrioFlowFifoLevelTh, BYTE lowPrioIndGPIO)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BYTE                                rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_TX_MAC_FIFO_IND_STRUCT   pFifoEmptyIndParams;

    //MC GPIO pin should be in range 2-39, excluding 8-11 
    if( ( highPrioIndGPIO < 2) || 
        ((highPrioIndGPIO > 7) && (highPrioIndGPIO < 12)) || 
        ( highPrioIndGPIO > 39) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    if( ( lowPrioIndGPIO < 2) || 
        ((lowPrioIndGPIO > 7) && (lowPrioIndGPIO < 12)) || 
        ( lowPrioIndGPIO > 39) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    pFifoEmptyIndParams.enable = enable;
    pFifoEmptyIndParams.highPrioFifoLevelTh = highPrioFlowFifoLevelTh;
    pFifoEmptyIndParams.highPrioIndGpio = highPrioIndGPIO;
    pFifoEmptyIndParams.lowPrioFifoLevelTh = lowPrioFlowFifoLevelTh;
    pFifoEmptyIndParams.lowPrioIndGpio = lowPrioIndGPIO;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&pFifoEmptyIndParams,
                                       sizeof(BCM_UW_COM_TX_MAC_FIFO_IND_STRUCT),
                                       BCM_UW_COM_NET_TXMAC_FIFO_IND_SET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_8KhzModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_8KHZ_MODE_ENUM clkOutMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    BYTE temp = (BYTE)clkOutMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&temp,
                                       sizeof(temp),
                                       BCM_UW_COM_NET_8KHZ_MODE_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsRtcCalibrationStart(BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_RTC_CALIB_MODE_ENUM calibMode, UINT16 calibPeriodMsec)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_PPS_RTC_CALIB_STRUCT ppsCalibSt;

    //parameters validation
    if ( (calibMode == BCM_UW_PPS_RTC_CALIB_MODE_AUTO_E) && ((calibPeriodMsec < 1000) || (calibPeriodMsec > 10000)) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    ppsCalibSt.calibMode        = (BYTE)calibMode; //handle ENUM
    ppsCalibSt.calibPeriodMsec = calibPeriodMsec;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ppsCalibSt,
                                              sizeof(BCM_UW_COM_PPS_RTC_CALIB_STRUCT),
                                              BCM_UW_COM_PPS_CALIB_START_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_SOURCE_ENUM source, UINT32 offsetNsec)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_PPS_CONFIGURE_STRUCT ppsCounfigSt;

    ppsCounfigSt.source       = (BYTE)source; //handle ENUM
    ppsCounfigSt.offsetNsec   = offsetNsec;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ppsCounfigSt,
                                              sizeof(BCM_UW_COM_PPS_CONFIGURE_STRUCT),
                                              BCM_UW_COM_PPS_CONFIGURE_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsOutputModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_OUTPUT_MODE_ENUM outputMode)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BYTE                            outputModeTemp = (BYTE)outputMode; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &outputModeTemp,
                                              sizeof(BYTE),
                                              BCM_UW_COM_PPS_OUTPUT_MODE_SET_OPCODE_E,
                                              scIndex,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsStatusGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_CALIB_STATUS_ENUM *calibStatus, BCM_UW_PPS_CALIB_FAIL_REASON_ENUM *calibFailReason)
{
    UINT32                            rxLen;
    BCM_UW_ERROR_MSG_ENUM             retVal;
    BCM_UW_ERROR_MSG_ENUM             rxStatus;
    BYTE                              rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_PPS_STATUS_GET_OPCODE_E,
                                              scIndex,
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_COM_PPS_STATUS_GET_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
       *calibStatus     = (BCM_UW_PPS_CALIB_STATUS_ENUM)rxBuffer[0];
       *calibFailReason = (BCM_UW_PPS_CALIB_FAIL_REASON_ENUM)rxBuffer[1];
    }
    
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortInitialize(BYTE deviceIndex, BYTE scIndex, BCM_UW_ETH_PORT_INITIALIZE_STRUCT *pInit)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    longJobID;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)pInit,
                                       sizeof(BCM_UW_ETH_PORT_INITIALIZE_STRUCT),
                                       BCM_UW_COM_ETH_PORT_INIT_OPCODE_E,
                                       scIndex,
                                       &longJobID,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex, scIndex, longJobID, &rxLen, NULL); 
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortFwLoad(BYTE deviceIndex, BYTE scIndex, BYTE *buff, UINT32 len)
{
    BCM_UW_ERROR_MSG_ENUM                          retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                                         rxLen;
    BCM_UW_ERROR_MSG_ENUM                          rxStatus;
    UINT32                                         bytesToSet = 0;
    BCM_UW_COM_ETH_PORT_FW_FILE_CHUNK_STRUCT       ethPortFwFileChunk;
    BCM_UW_COM_ETH_PORT_FW_FILE_HEADER_STRUCT      ethPortFwHdr;
    UINT32                                         bytesSetSoFar = 0;
    UINT32                                         fwLength = len-6;             //ignore 6 last bytes: CRC(2 bytes) + Version(4 bytes)   
    BYTE                                           maxFwFileChunkSize = 240;     //has to be div2 (HW limitation)

    // Function uses specific mutex
    bcmUwHostMutexLock(gConfigFileLoadApiMutex[deviceIndex]);

    ethPortFwHdr.uCodeFileLength = fwLength;
    memcpy(&ethPortFwHdr.uCodeChecksum, &buff[len-6], sizeof(UINT16));      //note: handles endianity
    memcpy(&ethPortFwHdr.uCodeVersion,  &buff[len-4], sizeof(UINT32));      //..

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&ethPortFwHdr,
                                       sizeof(BCM_UW_COM_ETH_PORT_FW_FILE_HEADER_STRUCT), 
                                       BCM_UW_COM_ETH_PORT_FW_DOWNLOAD_HDR_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);
//     printfpd1(" ret %d ", retVal);
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
       printfp1(" error ");
        bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
        return(retVal);
    }
    
    printfp1("\n\r go load :");
    ethPortFwFileChunk.position = BCM_UW_COM_ETH_PORT_FW_FILE_START_E;

    while (fwLength > 0)
    {
    printfpd1("\rfl:%d", fwLength);
        bytesToSet = MIN(maxFwFileChunkSize, fwLength);
        memcpy(&(ethPortFwFileChunk.pBuffer),&(buff[bytesSetSoFar]),bytesToSet);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE *)&ethPortFwFileChunk,
                                           (bytesToSet+sizeof(BYTE)), // 1 byte for position
                                           BCM_UW_COM_ETH_PORT_FW_DOWNLOAD_OPCODE_E,
                                           scIndex,
                                           NULL,
                                           &rxLen,
                                           &rxStatus);
  //      printfpd1(" eret %d ", retVal);
     if (retVal != BCM_UW_SUCCESS_MSG_E)
//       if(0)
        {
           printfp1(" ret to error");
            bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);
            return(retVal);
        }

        fwLength -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (fwLength <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1))
        {
            ethPortFwFileChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }
        else
        {
            ethPortFwFileChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }

    bcmUwHostMutexUnlock(gConfigFileLoadApiMutex[deviceIndex]);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortConfigure(BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_CONFIGURE_STRUCT *pConfig)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_ETH_PORT_CONFIGURE_EX_STRUCT ethPortConfig;
    BYTE                                longJobID;

    ethPortConfig.port = port;
    memcpy( &ethPortConfig.configParams, pConfig, sizeof(BCM_UW_ETH_PORT_CONFIGURE_STRUCT) );

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&ethPortConfig,
                                       sizeof(BCM_UW_COM_ETH_PORT_CONFIGURE_EX_STRUCT),
                                       BCM_UW_COM_ETH_PORT_CONFIGURE_OPCODE_E,
                                       scIndex,
                                       &longJobID,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
  //    printfp1("\n\r Ok!");
        retVal = bcmUwLongApiProbe(deviceIndex, scIndex, longJobID, &rxLen, NULL); 
    }
    else { /* Body */
    printfpd1("\n\r err ret:%d", retVal);
   } /* Endbody */

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortStatusGet(BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_STATUS_STRUCT *pData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&port,
                                       sizeof(BYTE),
                                       BCM_UW_COM_ETH_PORT_STATUS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ETH_PORT_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pData, rxBuffer, sizeof(BCM_UW_ETH_PORT_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortCountersClear(BYTE deviceIndex, BYTE scIndex, BYTE port)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&port,
                                       sizeof(BYTE),
                                       BCM_UW_COM_ETH_PORT_COUNTERS_CLEAR_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortRxCountersGet(BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT *pData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&port,
                                       sizeof(BYTE),
                                       BCM_UW_COM_ETH_PORT_RX_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pData, rxBuffer, sizeof(BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortTxCountersGet(BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT *pData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&port,
                                       sizeof(BYTE),
                                       BCM_UW_COM_ETH_PORT_TX_COUNTERS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pData, rxBuffer, sizeof(BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortClkSet(BYTE deviceIndex, BCM_UW_ETH_PORT_CLK_SRC_ENUM primaryClk, BCM_UW_ETH_PORT_CLK_SRC_ENUM secondaryClk)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ETH_PORT_CLK_SRC_STRUCT clkSrcSt;

    clkSrcSt.primary   = (BYTE)primaryClk; //handle ENUM
    clkSrcSt.secondary = (BYTE)secondaryClk; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&clkSrcSt,
                                       sizeof(BCM_UW_COM_ETH_PORT_CLK_SRC_STRUCT),
                                       BCM_UW_COM_ETH_PORT_CLK_SET_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

//----------------------------------------------------
// Header Compression Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcEngineEnable(BYTE deviceIndex, BOOLEAN enable)
{
    return(BCM_UW_API_HcExEngineEnable(deviceIndex, 0, enable));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcMaskSet(BYTE deviceIndex, BCM_UW_HC_ENGINE_ENUM engine, BYTE maskIndex, BCM_UW_HC_MASK_STRUCT *mask)
{
    return(BCM_UW_API_HcExMaskSet(deviceIndex, 0, engine, maskIndex, mask));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcTypeSet(BYTE deviceIndex, UINT16 packetType, BYTE engine1MaskIndex, BYTE engine2MaskIndex, UINT16 lenThreshold, UINT16 alternateType)
{
    return(BCM_UW_API_HcExTypeSet(deviceIndex, 0, packetType, engine1MaskIndex, engine2MaskIndex, lenThreshold, alternateType));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcLearningAndAgeingConfigure(BYTE deviceIndex, BCM_UW_HC_LEARNING_AGEING_STRUCT *pHCLa)
{
    return(BCM_UW_API_HcExLearningAndAgeingConfigure(deviceIndex, 0, pHCLa));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcDBRefreshConfigure(BYTE deviceIndex, BCM_UW_HC_DB_REFRESH_STRUCT *pHcDbRefresh)
{
    return(BCM_UW_API_HcExDBRefreshConfigure(deviceIndex, 0, pHcDbRefresh));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcDBFlush(BYTE deviceIndex, BCM_UW_HC_ENGINE_ENUM reserved)
{
    return(BCM_UW_API_HcExDBFlush(deviceIndex, 0, reserved));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcStatisticsGet(BYTE deviceIndex, BCM_UW_HC_STATISTIC_STRUCT *pHcStatistics)
{
    return(BCM_UW_API_HcExStatisticsGet(deviceIndex, 0, pHcStatistics));
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExEngineEnable(BYTE deviceIndex, BYTE scIndex, BOOLEAN enable)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)&enable,
                                   sizeof(BYTE),
                                   BCM_UW_COM_HC_ENGINE_ENABLE_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExMaskSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_ENGINE_ENUM engine, BYTE maskIndex, BCM_UW_HC_MASK_STRUCT *mask)
{
    BCM_UW_ERROR_MSG_ENUM           retVal;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_HC_MASK_SET_STRUCT   maskSet;

    maskSet.engine = (BYTE)engine; //handle ENUM
    maskSet.maskIndex = maskIndex;
    memcpy(&maskSet.mask, mask, 13);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)&maskSet,
                                   sizeof(BCM_UW_COM_HC_MASK_SET_STRUCT),
                                   BCM_UW_COM_HC_MASK_SET_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExTypeSet(BYTE deviceIndex, BYTE scIndex, UINT16 packetType, BYTE engine1MaskIndex, BYTE engine2MaskIndex, UINT16 lenThreshold, UINT16 alternateType)
{
    BCM_UW_ERROR_MSG_ENUM           retVal;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_HC_TYPE_SET_STRUCT   typeSetSt;

    typeSetSt.packetType    = packetType;
    typeSetSt.engine1MaskIndex  = engine1MaskIndex;
    typeSetSt.engine2MaskIndex  = engine2MaskIndex;
    typeSetSt.lenThreshold  = lenThreshold;
    typeSetSt.alternateType = alternateType;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE*)&typeSetSt,
                                   sizeof(BCM_UW_COM_HC_TYPE_SET_STRUCT),
                                   BCM_UW_COM_HC_TYPE_SET_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExLearningAndAgeingConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_LEARNING_AGEING_STRUCT *pHCLa)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    //parameters validation
    if ( (pHCLa->fixedBwThreshBps < 100)                    || 
         (pHCLa->fixedBwThreshBps > 10*1024*1024)           ||
         (pHCLa->dynamicLearningTableTargetPercent > 100)   ||
         (pHCLa->minDynamicBwThreshBps < 100)               || 
         (pHCLa->minDynamicBwThreshBps > 10*1024*1024)      ||
         (pHCLa->threshUpdateStepPercent < 1)               || 
         (pHCLa->threshUpdateStepPercent > 50)              ||
         (pHCLa->threshUpdatePeriodMsec < 100)              ||
         (pHCLa->measurementPeriodMsec < 30)                ||
         (pHCLa->measurementPeriodMsec > 1000) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)pHCLa,
                                   sizeof(BCM_UW_HC_LEARNING_AGEING_STRUCT),
                                   BCM_UW_COM_HC_LEARNING_AGEING_CONFIGURE_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExDBRefreshConfigure(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_DB_REFRESH_STRUCT *pHcDbRefresh)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    //parameters validation
    if ( (pHcDbRefresh->frequencyMsec < 60000) || (pHcDbRefresh->frequencyMsec > 86400000) || (pHcDbRefresh->rateEntries > 1024) )
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)pHcDbRefresh,
                                   sizeof(BCM_UW_HC_DB_REFRESH_STRUCT),
                                   BCM_UW_COM_HC_DB_REFRESH_CONFIGURE_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExDBFlush(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_ENGINE_ENUM reserved)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   NULL,
                                   0,
                                   BCM_UW_COM_HC_DB_QUICK_FLUSH_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExStatisticsGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_STATISTIC_STRUCT *pHcStatistics)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_HC_STATISTICS_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_HC_STATISTIC_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pHcStatistics, rxBuffer, sizeof(BCM_UW_HC_STATISTIC_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcParserTypeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_PARSER_TYPE_STRUCT *pParserType)
{
    BCM_UW_ERROR_MSG_ENUM retVal;
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)pParserType,
                                   sizeof(BCM_UW_HC_PARSER_TYPE_STRUCT),
                                   BCM_UW_COM_HC_PARSER_TYPE_SET_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcParserClassifierSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_PARSER_CLASSIFIER_STRUCT *pParserClassifier)
{
    BCM_UW_ERROR_MSG_ENUM retVal;
    UINT32 rxLen;
    BCM_UW_ERROR_MSG_ENUM rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)pParserClassifier,
                                   sizeof(BCM_UW_HC_PARSER_CLASSIFIER_STRUCT),
                                   BCM_UW_COM_HC_PARSER_CLASS_ID_SET_OPCODE_E,
                                   scIndex,
                                   NULL,
                                   &rxLen,
                                   &rxStatus);


    return(retVal);
}

//----------------------------------------------------
// Peripheral Access Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIOIntConfig(BYTE                     deviceIndex,
                                               BYTE                     bitIndex,
                                               BCM_UW_GPIO_INT_ENUM     intType,
                                               CPU_TYPE_ENUM            cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_GPIO_INT_CONFIG_STRUCT gpioIntConfigParams;

    gpioIntConfigParams.bitIndex = bitIndex;
    gpioIntConfigParams.intType  = (BYTE)intType; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&gpioIntConfigParams,
                                       sizeof(BCM_UW_COM_GPIO_INT_CONFIG_STRUCT),
                                       BCM_UW_COM_GPIO_INT_CONFIG_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIORead(BYTE                  deviceIndex,
                                          BCM_UW_GPIO_STRUCT    mask,
                                          BCM_UW_GPIO_STRUCT   *readData,
                                          CPU_TYPE_ENUM         cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&mask,
                                       sizeof(BCM_UW_GPIO_STRUCT),
                                       BCM_UW_COM_GPIO_READ_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_GPIO_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(readData, rxBuffer, sizeof(BCM_UW_GPIO_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIOWrite(BYTE                 deviceIndex,
                                           BCM_UW_GPIO_STRUCT   mask,
                                           BCM_UW_GPIO_STRUCT   data,
                                           CPU_TYPE_ENUM        cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_GPIO_WRITE_STRUCT     gpioWriteParams;

    gpioWriteParams.mask = mask;
    gpioWriteParams.data = data;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&gpioWriteParams,
                                       sizeof(BCM_UW_COM_GPIO_WRITE_STRUCT),
                                       BCM_UW_COM_GPIO_WRITE_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACWrite(BYTE deviceIndex, BCM_UW_AUXDAC_STRUCT *pAuxDac)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pAuxDac,
                                       sizeof(BCM_UW_AUXDAC_STRUCT),
                                       BCM_UW_COM_AUXDAC_WRITE_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACExWrite(BYTE deviceIndex, BCM_UW_AUXDAC_EX_STRUCT *pAuxDac)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pAuxDac,
                                       sizeof(BCM_UW_AUXDAC_EX_STRUCT),
                                       BCM_UW_COM_AUXDAC_EXT_WRITE_OPCODE_E,
                                       0,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACExRead(BYTE deviceIndex, BCM_UW_AUXDAC_EX_STRUCT *pAuxDac)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)pAuxDac,
                                       sizeof(BCM_UW_AUXDAC_EX_STRUCT),
                                       BCM_UW_COM_AUXDAC_EXT_READ_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_AUXDAC_EX_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pAuxDac, rxBuffer, sizeof(BCM_UW_AUXDAC_EX_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxADCRead(BYTE deviceIndex, BCM_UW_AUXADC_STRUCT *pAuxAdc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_AUXADC_READ_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_AUXADC_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pAuxAdc, rxBuffer, sizeof(BCM_UW_AUXADC_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetEthPhyRegGet(BYTE   deviceIndex,
                                                 BYTE   scIndex,
                                                 BYTE   phyId,
                                                 BYTE   regAddress,
                                                 UINT16 *value)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_ETH_PHY_REG_GET_STRUCT phyRegGet;

    phyRegGet.phyId      = phyId;
    phyRegGet.regAddress = regAddress;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&phyRegGet,
                                       sizeof(BCM_UW_COM_ETH_PHY_REG_GET_STRUCT),
                                       BCM_UW_COM_NET_ETH_PHY_REG_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(UINT16));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        // get phy register read value
        memcpy((BYTE*)value, rxBuffer, sizeof(UINT16));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetEthPhyRegSet(BYTE   deviceIndex,
                                                 BYTE   scIndex,
                                                 BYTE   phyId,
                                                 BYTE   regAddress,
                                                 UINT16 val)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_ETH_PHY_REG_SET_STRUCT   phyRegSet;

    phyRegSet.phyId      = phyId;
    phyRegSet.regAddress = regAddress;
    phyRegSet.val        = val;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&phyRegSet,
                                       sizeof(BCM_UW_COM_ETH_PHY_REG_SET_STRUCT),
                                       BCM_UW_COM_NET_ETH_PHY_REG_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_I2CTransaction(BYTE                      deviceIndex,
                                                BYTE                      slaveAddress,
                                                BYTE                      *txBuffer,
                                                BYTE                      txBufferLen,
                                                BYTE                      *rxBuffer,
                                                BYTE                      rxBufferLen,
                                                BCM_UW_I2C_FREQUENCY_ENUM frequency)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_PERIPHERAL_TX_STRUCT     peripheral;
    BYTE                                rxBufferTemp[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    if (txBufferLen + rxBufferLen > BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE)
    {
        return BCM_UW_PERIPHERAL_TOO_MANY_BYTES_E;
    }
    if (txBufferLen + rxBufferLen == 0)
    {
        return BCM_UW_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E;
    }

    // Function uses specific mutex
    bcmUwHostMutexLock(gI2cTransactionApiMutex[deviceIndex]);

    peripheral.phasePolarity = 0; //not relevant
    peripheral.frequency     = (BYTE)frequency; //handle ENUM
    peripheral.slaveAddress  = slaveAddress;
    peripheral.txBufferLen   = txBufferLen;
    peripheral.rxBufferLen   = rxBufferLen;
    memcpy((BYTE*)peripheral.txBuffer, txBuffer, txBufferLen);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&peripheral,
                                       BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE + txBufferLen, //header + tx buffer size
                                       BCM_UW_COM_I2C_TRANSACTION_OPCODE_E,
                                       0, //not relevant
                                       rxBufferTemp,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(rxBufferLen);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(rxBuffer, rxBufferTemp, rxBufferLen);
    }
    
    bcmUwHostMutexUnlock(gI2cTransactionApiMutex[deviceIndex]);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_SPITransaction(BYTE                            deviceIndex,
                                                BCM_UW_SPI_MASTER_CS_ENUM       spiMasterCs, 
                                                BYTE                            *txBuffer,
                                                BYTE                            txBufferLen,
                                                BYTE                            *rxBuffer,
                                                BCM_UW_SPI_PHASE_POLARITY_ENUM  phasePolarity,
                                                BCM_UW_SPI_FREQUENCY_ENUM       frequency)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_PERIPHERAL_TX_STRUCT     peripheral;
    BYTE                                rxBufferTemp[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    BYTE rxBufferLen = txBufferLen; //SPI rxBufferLen = txBufferLen

    if (txBufferLen + rxBufferLen > BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE)
    {
        return BCM_UW_PERIPHERAL_TOO_MANY_BYTES_E;
    }
    if ((txBufferLen == 0))
    {
        return BCM_UW_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E;
    }
    if ((BYTE)spiMasterCs > 16) //max CS number (see BCM_UW_SPI_MASTER_CS_ENUM))
    {
        return BCM_UW_PERIPHERAL_INVALID_SLAVE_ADDRESS_E;
    }

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    peripheral.phasePolarity = (BYTE)phasePolarity; //handle ENUM
    peripheral.frequency     = (BYTE)frequency;     //handle ENUM
    peripheral.slaveAddress  = (BYTE)spiMasterCs;   //handle ENUM
    peripheral.txBufferLen   = txBufferLen;         
    peripheral.rxBufferLen   = rxBufferLen;
    memcpy((BYTE*)peripheral.txBuffer, txBuffer, txBufferLen);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&peripheral,
                                       BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE + txBufferLen, //header + tx buffer size
                                       BCM_UW_COM_SPI_TRANSACTION_OPCODE_E,
                                       0, //not relevant
                                       rxBufferTemp,
                                       &rxLen,
                                       &rxStatus);


    RETURNED_LENGTH_CHECK(rxBufferLen);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(rxBuffer, rxBufferTemp, rxBufferLen); 
    }
    
    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return(retVal);
}

//----------------------------------------------------
// Debug Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GeneralControlSet(BYTE             deviceIndex,
                                                   BYTE             scIndex,
                                                   UINT32           opcode,
                                                   BYTE             length,
                                                   BYTE             *data,
                                                   CPU_TYPE_ENUM    cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_GENERAL_CONTROL_STRUCT generalControl;

    generalControl.opcode = opcode;
    length = MIN(length, sizeof(generalControl.pDataBuffer));
    generalControl.length = length;
    memcpy((BYTE*)generalControl.pDataBuffer, data, length);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&generalControl,
                                       (BYTE)(BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE + length), //const size
                                       BCM_UW_COM_GENERAL_CONTROL_SET_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GeneralControlGet(BYTE             deviceIndex,
                                                   BYTE             scIndex,
                                                   UINT32           opcode,
                                                   BYTE             *length,        //note: input and output
                                                   BYTE             *data,
                                                   CPU_TYPE_ENUM    cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_GENERAL_CONTROL_STRUCT  *pGeneralControl = (BCM_UW_COM_GENERAL_CONTROL_STRUCT*)&rxBuffer;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&opcode,   // send the opcode
                                       sizeof(UINT32),
                                       BCM_UW_COM_GENERAL_CONTROL_GET_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        if ( (pGeneralControl->length > BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE) ||     //sanity check message max size
             (pGeneralControl->length > *length) )                                                                          //allow return size to be shorter than allocated buffer size
        {
            *length = 0;
            return BCM_UW_API_INVALID_PARAMS_E;
        }

        *length = pGeneralControl->length;
        memcpy(data, (BYTE*)pGeneralControl->pDataBuffer, *length);
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DebugMsgGet(BYTE           deviceIndex,
                                             BYTE           scIndex,
                                             BYTE           *pBuffer,
                                             UINT32         *len,
                                             CPU_TYPE_ENUM  cpu)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_DEBUG_OPCODE_E,
                                       0,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pBuffer, rxBuffer, rxLen);
        *len = rxLen;
    }
    else
    {
        *len = 0;
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_registerRead
//
//  PARAMETERS:
//              scIndex    - [in] modem index
//              offset     - [in] register offset from modem base address
//              cpu        - [in] GP or MC
//              pVal       - [out] register value
//
//  DESCRIPTION:
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RegisterRead(BYTE          deviceIndex,
                                              BYTE          scIndex,
                                              UINT32        offset,     //19bit
                                              CPU_TYPE_ENUM cpu,
                                              UINT16        *pVal)
{
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_COM_READ_REGISTER_STRUCT registerToRead;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BYTE                            rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    registerToRead.offset = offset;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&registerToRead,
                                       sizeof(BCM_UW_COM_READ_REGISTER_STRUCT),
                                       BCM_UW_COM_REGISTER_READ_OPCODE_E,
                                       scIndex,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(UINT16));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pVal, rxBuffer, sizeof(UINT16));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_registerWrite
//
//  PARAMETERS:
//              scIndex    - [in] modem index
//              offset     - [in] register offset from modem base address
//              val        - [in] register value
//
//  DESCRIPTION:
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RegisterWrite(BYTE          deviceIndex,
                                               BYTE          scIndex,
                                               UINT32        offset,     //19bit
                                               CPU_TYPE_ENUM cpu,
                                               UINT16        val)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_WRITE_REGISTER_STRUCT    registerToWrite;

    registerToWrite.offset = offset;
    registerToWrite.value  = val;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&registerToWrite,
                                       sizeof(BCM_UW_COM_WRITE_REGISTER_STRUCT),
                                       BCM_UW_COM_REGISTER_WRITE_OPCODE_E,
                                       scIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

//----------------------------------------------------
// New Functions - WideBand
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxStatusGet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_WB_RX_STATUS_STRUCT *wbRxStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_WB_RX_STATUS_GET_OPCODE_E,
                                              (BYTE)wbRxIndex, //WB
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_WB_RX_STATUS_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)wbRxStat, rxBuffer, sizeof(BCM_UW_WB_RX_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxStatusGet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TX_STATUS_STRUCT *wbTxStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_WB_TX_STATUS_GET_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK( sizeof(BCM_UW_WB_TX_STATUS_STRUCT) );

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)wbTxStat, rxBuffer, sizeof(BCM_UW_WB_TX_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxFreqSet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, INT32 ncoFreqKHz)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ncoFreqKHz,
                                              sizeof(INT32),
                                              BCM_UW_COM_WB_RX_NCO_FREQ_SET_OPCODE_E,
                                              (BYTE)wbRxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxFreqSet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, INT32 ncoFreqKHz)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&ncoFreqKHz,
                                              sizeof(INT32),
                                              BCM_UW_COM_WB_TX_NCO_FREQ_SET_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqDelaySet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, INT16 fdfFracDelay)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    INT16                   tempFdfFracDelay = fdfFracDelay;

    if ( (tempFdfFracDelay > 4095) || (tempFdfFracDelay < -4095) )    //sanity check (-8,8)
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&tempFdfFracDelay,
                                              sizeof(tempFdfFracDelay),
                                              BCM_UW_COM_WB_RX_IQ_DELAY_SET_OPCODE_E,
                                              (BYTE)wbRxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxSet(BYTE                     deviceIndex,
                                           BCM_UW_WB_TX_NAME_ENUM   wbTxIndex,
                                           INT16                    diffPhaseDeg,
                                           INT16                    diffGainDB,
                                           INT16                    dcLeakageIPercent,
                                           INT16                    dcLeakageQPercent)
{
    BCM_UW_ERROR_MSG_ENUM           retVal;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_IQ_IMBALANCE_EX_STRUCT   iqImbTxTx; //high percision

    if (wbTxIndex > BCM_UW_WB_TX_1_E) //XC chains not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    iqImbTxTx.diffPhaseDeg      = diffPhaseDeg;
    iqImbTxTx.diffGainDB        = diffGainDB;
    iqImbTxTx.dcLeakageIPercent = dcLeakageIPercent;
    iqImbTxTx.dcLeakageQPercent = dcLeakageQPercent;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&iqImbTxTx,
                                              sizeof(BCM_UW_IQ_IMBALANCE_EX_STRUCT),
                                              BCM_UW_COM_WB_TXTX_SET_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxModeSet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_TXTX_MODE_ENUM txTxMode)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    tempMode;

    tempMode = (BYTE)txTxMode; //handle ENUM

    if (wbTxIndex > BCM_UW_WB_TX_1_E) //XC chains not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&tempMode,
                                       sizeof(tempMode),
                                       BCM_UW_COM_TX_TX_MODE_SET_OPCODE_E,
                                       (BYTE)wbTxIndex, //WB
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxDelaySet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, UINT16 txTxFracDelay)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    
    if (wbTxIndex > BCM_UW_WB_TX_1_E) //XC chains not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex, 
                                       (BYTE*)&txTxFracDelay,
                                       sizeof(txTxFracDelay),
                                       BCM_UW_COM_TX_TX_DELAY_SET_OPCODE_E,
                                       (BYTE)wbTxIndex, //WB
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxCalibrationStart(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    if (wbTxIndex > BCM_UW_WB_TX_1_E) //XC chains not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_TX_TX_CALIB_RESTART_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxCalibrationStatusGet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_CALIB_STATUS_ENUM *txTxCalibStatus)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    tempVal;

    if (wbTxIndex > BCM_UW_WB_TX_1_E) //XC chains not supported
    {
        return(BCM_UW_API_INVALID_PARAMS_E);
    }

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_TX_TX_CALIB_STATUS_GET_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(&tempVal, rxBuffer, sizeof(BYTE));
        *txTxCalibStatus = (BCM_UW_CALIB_STATUS_ENUM)tempVal; //handle ENUM
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqMismatchCorrectionSet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_IQ_MISMATCH_STRUCT *pIqmc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)pIqmc,
                                              sizeof(BCM_UW_IQ_MISMATCH_STRUCT),
                                              BCM_UW_COM_WB_RX_IQMC_DELAY_SET_OPCODE_E,
                                              (BYTE)wbRxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqMismatchCorrectionGet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_IQ_MISMATCH_STRUCT *pIqmc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       NULL,
                                       0,
                                       BCM_UW_COM_WB_RX_IQMC_DELAY_GET_OPCODE_E,
                                       (BYTE)wbRxIndex, //WB
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_IQ_MISMATCH_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pIqmc, rxBuffer, sizeof(BCM_UW_IQ_MISMATCH_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTransmitterModeSet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TRANSMITTER_MODE_STRUCT *tx)
{
    BCM_UW_WB_TRANSMITTER_MODE_EX_STRUCT itEx;

    itEx.transmitterMode        = tx->transmitterMode;         
    itEx.toneFreqKhz            = tx->toneFreqKhz;     
    itEx.useExplicitPower       = tx->useExplicitPower;     
    itEx.transmitPowerDbTenths  = tx->transmitPowerDbTenths;
    itEx.muteTimeMili           = 0; //force zero - no time mute

    return BCM_UW_API_WbTransmitterModeExSet(deviceIndex, wbTxIndex, &itEx);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTransmitterModeExSet(BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TRANSMITTER_MODE_EX_STRUCT *tx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)tx,
                                              sizeof(BCM_UW_WB_TRANSMITTER_MODE_EX_STRUCT),
                                              BCM_UW_COM_TRANSMITTER_MODE_SET_OPCODE_E,
                                              (BYTE)wbTxIndex, //WB
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSpectralInversionSet(BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BOOLEAN specInvOn)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&specInvOn,
                                       sizeof(BOOLEAN),
                                       BCM_UW_COM_WB_RX_SPECTRAL_INVERSION_SET_OPCODE_E,
                                       (BYTE)wbRxIndex, //WB
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSnapshotConfigure(BYTE                                 deviceIndex,
                                                       BCM_UW_WB_RX_NAME_ENUM               wbRxIndex,
                                                       BCM_UW_BLOCK_CHANNEL_INDEX_SEL_ENUM  blockSel,
                                                       BCM_UW_BLOCK_HOST_TB_SEL_ENUM        hostSel,
                                                       BYTE                                 dataMode,
                                                       BOOLEAN                              repeat,
                                                       BOOLEAN                              dummy1)

{
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    BCM_UW_COM_WB_SNAPSHOT_STRUCT   snapshotParams;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;

    snapshotParams.wbRxIndex = (BYTE)wbRxIndex; //handle ENUM
    snapshotParams.blockSel  = (BYTE)blockSel; //handle ENUM
    snapshotParams.hostSel   = (BYTE)hostSel; //handle ENUM
    snapshotParams.repeat    = repeat;
    snapshotParams.dataMode  = dataMode;
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&snapshotParams,
                                       sizeof(BCM_UW_COM_WB_SNAPSHOT_STRUCT),
                                       BCM_UW_COM_WB_SNAPSHOT_CONFIGURE_OPCODE_E,
                                       wbRxIndex,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSnapshotGet(BYTE deviceIndex, INT16 *pBuffer)
{
    BCM_UW_ERROR_MSG_ENUM  retVal = BCM_UW_SUCCESS_MSG_E;
    UINT16                 bufferIndex = 0;
    UINT32                 rxLen = 240; //15 lines x 16 bytes per chunk
    BCM_UW_ERROR_MSG_ENUM  rxStatus;
    BYTE                   rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    while (rxLen == 240)
    {
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  NULL,
                                                  0,
                                                  BCM_UW_COM_WB_SNAPSHOT_GET_OPCODE_E,
                                                  0, //WB
                                                  rxBuffer,
                                                  &rxLen,
                                                  &rxStatus);

        if (retVal == BCM_UW_SUCCESS_MSG_E)
        {
            memcpy( ((BYTE*)pBuffer)+bufferIndex, rxBuffer, rxLen );
            bufferIndex += rxLen;
        }
        else 
        {
            return(retVal);
        }
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcStatusGet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_STATUS_STRUCT* rxagcStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    BYTE temp = (BYTE)adcIndex; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &temp,
                                              sizeof(temp),
                                              BCM_UW_COM_WB_RX_AGC_STATUS_GET_OPCODE_E,
                                              0, //AGC
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_WB_RXAGC_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(rxagcStat, rxBuffer, sizeof(BCM_UW_WB_RXAGC_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcGainDistributionTableSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT *rxAgcGDTable)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT   msgChunk;
    UINT16                              bytesToSend = sizeof(BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT);
    UINT16                              bytesSent = 0;
    BYTE                                dataLen = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2;
    BOOLEAN                             isFirstChunk = TRUE;
    printfp1("B\n\rCM_UW_API_WbRxAgcGainDistributionTableSet");
    msgChunk.agcIndex = (BYTE)adcIndex; //handle ENUM
    msgChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;
    while (bytesSent < bytesToSend)
    {
   //    printfpd1(" %d", bytesSent);
 //t      delay_mcs(100000);
       
        if ((bytesToSend - bytesSent) <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
        {
            dataLen = bytesToSend - bytesSent;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        memcpy(msgChunk.pBuffer, (BYTE*)rxAgcGDTable + bytesSent, dataLen);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  (BYTE*)&msgChunk,
                                                  dataLen+2,
                                                  BCM_UW_COM_WB_RX_AGC_GAIN_DIST_TABLE_SET_OPCODE_E,
                                                  0, //AGC
                                                  NULL,
                                                  &rxLen,
                                                  &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
           printfp1("\n\r Error1!");
            return(retVal);
        }

        bytesSent += dataLen;

        if (isFirstChunk == TRUE)
        {
            isFirstChunk = FALSE;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcDbToDacTableSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *rxAgcDB2DACTable)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT   msgChunk;
    UINT16                              bytesToSend = sizeof(BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT);
    UINT16                              bytesSent = 0;
    BYTE                                dataLen = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2;
    BOOLEAN                             isFirstChunk = TRUE;

    printfp1("B\n\rBCM_UW_API_WbRxAgcDbToDacTableSet");
    printfpd1(" %d ", bytesToSend);
    msgChunk.agcIndex = (BYTE)adcIndex; //handle ENUM
    msgChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    while (bytesSent < bytesToSend)
    {
//        printfpd1(" %d", bytesSent);
 //t       delay_mcs(100000);
        if ((bytesToSend - bytesSent) <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
        {
//         printfp1(" ...final ");
            dataLen = bytesToSend - bytesSent;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        memcpy(msgChunk.pBuffer, (BYTE*)rxAgcDB2DACTable + bytesSent, dataLen);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  (BYTE*)&msgChunk,
                                                  dataLen+2,
                                                  BCM_UW_COM_WB_RX_AGC_DB_TO_DAC_TABLE_SET_OPCODE_E,
                                                  0, //AGC
                                                  NULL,
                                                  &rxLen,
                                                  &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            printfp1("\n\r Error2!");
            return(retVal);
        }

        bytesSent += dataLen;

        if (isFirstChunk == TRUE)
        {
            isFirstChunk = FALSE;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcFreeze(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BOOLEAN enable)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_AGC_FREEZE_STRUCT    agcFreezeSt;

    agcFreezeSt.index    = (BYTE)adcIndex; //handle ENUM
    agcFreezeSt.freezeEn = enable;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&agcFreezeSt,
                                              sizeof(BCM_UW_COM_AGC_FREEZE_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_FREEZE_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcGainDistributionRowForce(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BYTE row, BOOLEAN enable)
{
    UINT32                             rxLen;
    BCM_UW_ERROR_MSG_ENUM              retVal;
    BCM_UW_ERROR_MSG_ENUM              rxStatus;
    BCM_UW_COM_AGC_ROW_FORCE_STRUCT    agcRowForceSt;

    agcRowForceSt.index    = (BYTE)adcIndex; //handle ENUM
    agcRowForceSt.row      = row;
    agcRowForceSt.isEnable = enable;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&agcRowForceSt,
                                              sizeof(BCM_UW_COM_AGC_ROW_FORCE_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_ROW_FORCE_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcSetPointAndPeakSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, INT16 mainSetPointDbTenth, INT16 innerSetPointDbTenth, INT16 peakValueDbTenth)
{
    printfp1("\n\r BCM_UW_API_WbRxAgcSetPointAndPeakSet ");
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               retVal;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_SET_POINT_SET_STRUCT rxAgcSetpoint;

    rxAgcSetpoint.index                = (BYTE)adcIndex; //handle ENUM
    rxAgcSetpoint.mainSetPointDbTenth  = mainSetPointDbTenth;
    rxAgcSetpoint.innerSetPointDbTenth = innerSetPointDbTenth;
    rxAgcSetpoint.peakValueDbTenth     = peakValueDbTenth;
    
//t    printfpd1("\n\rs:%d",  sizeof(BCM_UW_COM_AGC_SET_POINT_SET_STRUCT));
//t    printfpd1("\n\rm:%d", rxAgcSetpoint.mainSetPointDbTenth);
//t    printfpd1("\n\ri:%d", rxAgcSetpoint.innerSetPointDbTenth);
//t    printfpd1("\n\rp:%d", rxAgcSetpoint.peakValueDbTenth);

//t    delay_mcs(500000);
    
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                    //          (BYTE*)(&rxAgcSetpoint +1),
                                              (BYTE*)(&rxAgcSetpoint),
//                                              sizeof(BCM_UW_COM_AGC_SET_POINT_SET_STRUCT)-1,
                                              sizeof(BCM_UW_COM_AGC_SET_POINT_SET_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_SETPOINT_SET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
                                              
   if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            printfp1("\n\r Error3!\n\r");
//            return(retVal);
        }
                                              

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBandwidthSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BYTE mainTrackIndex, BYTE gainModifierIndex)
{
    UINT32                                rxLen;
    BCM_UW_ERROR_MSG_ENUM                 retVal;
    BCM_UW_ERROR_MSG_ENUM                 rxStatus;
    BCM_UW_COM_AGC_BANDWIDTH_SET_STRUCT   rxAgcbandwidth;

    rxAgcbandwidth.index             = (BYTE)adcIndex;  //handle ENUM
    rxAgcbandwidth.mainTrackIndex    = mainTrackIndex;
    rxAgcbandwidth.gainModifierIndex = gainModifierIndex;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&rxAgcbandwidth,
                                              sizeof(BCM_UW_COM_AGC_BANDWIDTH_SET_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_BANDWIDTH_SET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBackoffOffsetSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, INT16 gainOffset0DbTenth, INT16 gainOffset1DbTenth, INT16 gainOffset2DbTenth, INT16 gainOffset3DbTenth)
{
    UINT32                                       rxLen;
    BCM_UW_ERROR_MSG_ENUM                        retVal;
    BCM_UW_ERROR_MSG_ENUM                        rxStatus;
    BCM_UW_COM_AGC_BACKOFF_OFFSET_SET_STRUCT     offSetSet;

    offSetSet.index              = (BYTE)adcIndex;  //handle ENUM
    offSetSet.gainOffset0DbTenth = gainOffset0DbTenth;
    offSetSet.gainOffset1DbTenth = gainOffset1DbTenth;
    offSetSet.gainOffset2DbTenth = gainOffset2DbTenth;
    offSetSet.gainOffset3DbTenth = gainOffset3DbTenth;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&offSetSet,
                                              sizeof(BCM_UW_COM_AGC_BACKOFF_OFFSET_SET_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_BACKOFF_OFFSET_SET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;

}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBackofCompensationSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_ANALOG_GAIN_ENUM analogGainIdx, INT16 totalGainCompensationDbTenth)
{
    UINT32                                       rxLen;
    BCM_UW_ERROR_MSG_ENUM                        retVal;
    BCM_UW_ERROR_MSG_ENUM                        rxStatus;
    BCM_UW_COM_AGC_BACKOFF_COMPENSATION_SET_STRUCT  compensationSet;

    compensationSet.index                        = (BYTE)adcIndex;  //handle ENUM
    compensationSet.analogGainIdx                = (BYTE)analogGainIdx;
    compensationSet.totalGainCompensationDbTenth = totalGainCompensationDbTenth;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&compensationSet,
                                              sizeof(BCM_UW_COM_AGC_BACKOFF_COMPENSATION_SET_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_BACKOFF_COMPENSATION_SET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcTableOffsetSet(BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BOOLEAN enable, INT16 offsetDbTenth)
{
    UINT32                                       rxLen;
    BCM_UW_ERROR_MSG_ENUM                        retVal;
    BCM_UW_ERROR_MSG_ENUM                        rxStatus;
    BCM_UW_COM_AGC_TABLE_OFFSET_SET_STRUCT       offSetSet;

    offSetSet.index              = (BYTE)adcIndex;  //handle ENUM
    offSetSet.enable             = enable;
    offSetSet.offsetDbTenth      = offsetDbTenth;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&offSetSet,
                                              sizeof(BCM_UW_COM_AGC_TABLE_OFFSET_SET_STRUCT),
                                              BCM_UW_COM_WB_RX_AGC_TABLE_OFFSET_SET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcStatusGet(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_TXAGC_STATUS_STRUCT *txagc)
{
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    BYTE temp = (BYTE)dacIndex; //handle ENUM

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &temp,
                                              sizeof(temp),
                                              BCM_UW_COM_WB_TX_AGC_STATUS_GET_OPCODE_E,
                                              0, //AGC
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_WB_TXAGC_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(txagc, rxBuffer, sizeof(BCM_UW_WB_TXAGC_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcConfigure(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BOOLEAN isOpenLoop, UINT16 targetPowerChangeRateDbHundredth)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_AGC_CONF_STRUCT      agcConfSt;

    agcConfSt.agcIndex          = (BYTE)dacIndex; //handle ENUM
    agcConfSt.isOpenLoop        = isOpenLoop;
    agcConfSt.targetPowerChangeRateDbHundredth = targetPowerChangeRateDbHundredth;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&agcConfSt,
                                              sizeof(BCM_UW_COM_AGC_CONF_STRUCT),
                                              BCM_UW_COM_WB_TX_AGC_CONFIGURE_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcTargetPowerSet(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, INT16 targetPower0DbmTenth, INT16 targetPower1DbmTenth)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_AGC_TARGET_STRUCT    agcTargetSt;

    agcTargetSt.agcIndex             = (BYTE)dacIndex; //handle ENUM
    agcTargetSt.targetPower0DbmTenth = targetPower0DbmTenth;
    agcTargetSt.targetPower1DbmTenth = targetPower1DbmTenth;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&agcTargetSt,
                                              sizeof(BCM_UW_COM_AGC_TARGET_STRUCT),
                                              BCM_UW_COM_WB_TX_AGC_TARGET_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcGainDistributionTableSet(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_STRUCT *txAgcGDTable)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT   msgChunk;
    UINT16                              bytesToSend = sizeof(BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_STRUCT);
    UINT16                              bytesSent = 0;
    BYTE                                dataLen = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2;
    BOOLEAN                             isFirstChunk = TRUE;

    msgChunk.agcIndex = (BYTE)dacIndex; //handle ENUM
    msgChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    while (bytesSent < bytesToSend)
    {
        if ((bytesToSend - bytesSent) <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
        {
            dataLen = bytesToSend - bytesSent;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        memcpy(msgChunk.pBuffer, (BYTE*)txAgcGDTable + bytesSent, dataLen);
        
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  (BYTE*)&msgChunk,
                                                  dataLen+2,
                                                  BCM_UW_COM_WB_TX_AGC_GAIN_DIST_TABLE_SET_OPCODE_E,
                                                  0, //AGC
                                                  NULL,
                                                  &rxLen,
                                                  &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return(retVal);
        }

        bytesSent += dataLen;

        if (isFirstChunk == TRUE)
        {
            isFirstChunk = FALSE;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcDbToDacTableSet(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *txAgcDB2DACTable)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT   msgChunk;
    UINT16                              bytesToSend = sizeof(BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT);
    UINT16                              bytesSent = 0;
    BYTE                                dataLen = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2;
    BOOLEAN                             isFirstChunk = TRUE;

    msgChunk.agcIndex = (BYTE)dacIndex; //handle ENUM
    msgChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    while (bytesSent < bytesToSend)
    {
        if ((bytesToSend - bytesSent) <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
        {
            dataLen = bytesToSend - bytesSent;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        memcpy(msgChunk.pBuffer, (BYTE*)txAgcDB2DACTable + bytesSent, dataLen);
        
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  (BYTE*)&msgChunk,
                                                  dataLen+2,
                                                  BCM_UW_COM_WB_TX_AGC_DB_TO_DAC_TABLE_SET_OPCODE_E,
                                                  0, //AGC
                                                  NULL,
                                                  &rxLen,
                                                  &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return(retVal);
        }

        bytesSent += dataLen;

        if (isFirstChunk == TRUE)
        {
            isFirstChunk = FALSE;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcAdcToDbmTableSet(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_AGC_ADC_TO_DBM_TABLE_STRUCT *txAgcAdc2DBMTable)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT   msgChunk;
    UINT16                              bytesToSend = sizeof(BCM_UW_WB_AGC_ADC_TO_DBM_TABLE_STRUCT);
    UINT16                              bytesSent = 0;
    BYTE                                dataLen = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2;
    BOOLEAN                             isFirstChunk = TRUE;

    msgChunk.agcIndex = (BYTE)dacIndex; //handle ENUM
    msgChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;

    while (bytesSent < bytesToSend)
    {
        if ((bytesToSend - bytesSent) <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
        {
            dataLen = bytesToSend - bytesSent;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        memcpy(msgChunk.pBuffer, (BYTE*)txAgcAdc2DBMTable + bytesSent, dataLen);
        
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                                  (BYTE*)&msgChunk,
                                                  dataLen+2,
                                                  BCM_UW_COM_WB_TX_AGC_ADC_TO_DBM_TABLE_SET_OPCODE_E,
                                                  0, //AGC
                                                  NULL,
                                                  &rxLen,
                                                  &rxStatus);
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return(retVal);
        }

        bytesSent += dataLen;

        if (isFirstChunk == TRUE)
        {
            isFirstChunk = FALSE;
            msgChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcFreeze(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BOOLEAN enable)
{
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           retVal;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_AGC_FREEZE_STRUCT agcFreezeSt;

    agcFreezeSt.index    = (BYTE)dacIndex; //handle ENUM
    agcFreezeSt.freezeEn = enable;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&agcFreezeSt,
                                              sizeof(BCM_UW_COM_AGC_FREEZE_STRUCT),
                                              BCM_UW_COM_WB_TX_AGC_FREEZE_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcGainDistributionRowForce(BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BYTE row, BOOLEAN enable)
{
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               retVal;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_AGC_ROW_FORCE_STRUCT     txagcRowForceSt;

    txagcRowForceSt.index    = (BYTE)dacIndex; //handle ENUM
    txagcRowForceSt.row      = row;
    txagcRowForceSt.isEnable = enable;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&txagcRowForceSt,
                                              sizeof(BCM_UW_COM_AGC_ROW_FORCE_STRUCT),
                                              BCM_UW_COM_WB_TX_AGC_ROW_FORCE_OPCODE_E,
                                              0, //AGC
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_AllInitialize(BYTE deviceIndex, BCM_UW_RF_ALL_INITIALIZE_STRUCT *initData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    longJobID;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)initData,
                                              sizeof(BCM_UW_RF_ALL_INITIALIZE_STRUCT),
                                              BCM_UW_COM_RF_ALL_INITIALIZE_OPCODE_E,
                                              0,
                                              &longJobID,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, NULL); 
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxStandbySet(BYTE deviceIndex, BYTE rfTxIdx, BOOLEAN isStandby)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE *)&isStandby,
                                              sizeof(isStandby),
                                              BCM_UW_COM_RF_TX_STANDBY_SET_OPCODE_E,
                                              (BYTE)rfTxIdx, //rf Tx Idx
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxPowerDown(BYTE deviceIndex, BYTE rfTxIdx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_TX_POWER_DOWN_OPCODE_E,
                                              (BYTE)rfTxIdx, //rf Tx Idx
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxAdpdEnable(BYTE deviceIndex, BYTE rfTxIdx, BOOLEAN isOn)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE *)&isOn,
                                              sizeof(isOn),
                                              BCM_UW_COM_RF_TX_ADPD_ENABLE_OPCODE_E,
                                              (BYTE)rfTxIdx, //rf Tx Idx
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxStatusGet(BYTE deviceIndex, BYTE rfTxIdx, BCM_UW_RF_TX_STATUS_STRUCT *txStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_TX_STATUS_GET_OPCODE_E,
                                              (BYTE)rfTxIdx, //rf Tx Idx
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_RF_TX_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(txStat, rxBuffer, sizeof(BCM_UW_RF_TX_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxStandbySet(BYTE deviceIndex, BYTE rfRxIdx, BOOLEAN isStandby)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE *)&isStandby,
                                              sizeof(isStandby),
                                              BCM_UW_COM_RF_RX_STANDBY_SET_OPCODE_E,
                                              (BYTE)rfRxIdx, //RF
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxPowerDown(BYTE deviceIndex, BYTE rfRxIdx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_RX_POWER_DOWN_OPCODE_E,
                                              (BYTE)rfRxIdx, //RF
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxRslGet(BYTE deviceIndex, BYTE rfRxIdx, BCM_UW_RF_RX_RSL_STRUCT *rslData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_RX_RSL_GET_OPCODE_E,
                                              (BYTE)rfRxIdx, //RF
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_RF_RX_RSL_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(rslData, rxBuffer, sizeof(BCM_UW_RF_RX_RSL_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxStatusGet(BYTE deviceIndex, BYTE rfRxIdx, BCM_UW_RF_RX_STATUS_STRUCT *rxStat)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_RX_STATUS_GET_OPCODE_E,
                                              (BYTE)rfRxIdx, //RF
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_RF_RX_STATUS_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(rxStat, rxBuffer, sizeof(BCM_UW_RF_RX_STATUS_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxTxLoopbackSet(BYTE deviceIndex, BYTE rfRxIdx, BOOLEAN isLoopbackOn)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE *)&isLoopbackOn,
                                              sizeof(isLoopbackOn),
                                              BCM_UW_COM_RF_RX_TX_LOOPBACK_SET_OPCODE_E,
                                              (BYTE)rfRxIdx, //RF
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_LoSharingSet(BYTE deviceIndex, BOOLEAN isTx, BYTE rfDevIdxMaster, BYTE rfDevIdxSlave)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    txBuffer[3] = { 0 };

    txBuffer[0] = isTx;
    txBuffer[1] = rfDevIdxMaster;
    txBuffer[2] = rfDevIdxSlave;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              txBuffer,
                                              sizeof(txBuffer),
                                              BCM_UW_COM_RF_LO_SHARING_SET_OPCODE_E,
                                              0,
                                              NULL,
                                              &rxLen,
                                              &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_ProgressErrorGet(BYTE deviceIndex, BCM_UW_RF_PROGRESS_ERROR_STRUCT *progressErrorData)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              NULL,
                                              0,
                                              BCM_UW_COM_RF_PROGRESS_ERROR_GET_OPCODE_E,
                                              (BYTE)0, //RF device index
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_RF_PROGRESS_ERROR_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(progressErrorData, rxBuffer, sizeof(BCM_UW_RF_PROGRESS_ERROR_STRUCT));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_InternalControl(BYTE    deviceIndex,
                                                    BYTE    rfDevIdx,
                                                    BOOLEAN isLong,
                                                    UINT32  subOpcode,
                                                    BYTE    *txData,
                                                    BYTE    txLength,
                                                    BYTE    *rxData,
                                                    BYTE    *rxLength)
{
    BCM_UW_ERROR_MSG_ENUM       retVal;
    UINT32                      rxLen;
    BCM_UW_ERROR_MSG_ENUM       rxStatus;
    BYTE                        rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_GENERAL_RF_CONTROL_STRUCT txControl;
    BYTE                        longJobID;

    txControl.opcode    = subOpcode;
    txControl.rfDevIdx  = rfDevIdx;
    txControl.length    = txLength;
    memcpy(txControl.pDataBuffer, txData, txLength);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&txControl,
                                              sizeof(txControl),
                                              BCM_UW_COM_RF_INTERNAL_CONTROL_OPCODE_E,
                                              0, //RF
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        *rxLength = 0; //error
        return(retVal);
    }
    
    if (isLong == TRUE) 
    {
        RETURNED_LENGTH_CHECK(sizeof(BYTE));
        
        if (retVal == BCM_UW_SUCCESS_MSG_E)
        {
            longJobID = rxBuffer[0];
            retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, rxBuffer); 
        }
            
        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return retVal;
        }        
    }

    if (rxData != NULL) 
    {
        memcpy(rxData, rxBuffer, rxLen);
        *rxLength = rxLen;        
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RegisterRead(BYTE                     deviceIndex,
                                                 BYTE                     rfIdx,
                                                 BCM_UW_RF_CHIP_TYPE_ENUM chipType,
                                                 UINT16                   regAddress,     
                                                 UINT16                   *pVal)
{
    BCM_UW_ERROR_MSG_ENUM              retVal;
    BCM_UW_COM_RF_READ_REGISTER_STRUCT registerToRead;
    UINT32                             rxLen;
    BCM_UW_ERROR_MSG_ENUM              rxStatus;
    BYTE                               rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    registerToRead.chipType  = chipType;
    registerToRead.offset    = regAddress;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&registerToRead,
                                       sizeof(BCM_UW_COM_RF_READ_REGISTER_STRUCT),
                                       BCM_UW_COM_RF_REGISTER_READ_OPCODE_E,
                                       rfIdx,
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(UINT16));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pVal, rxBuffer, sizeof(UINT16));
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RegisterWrite(BYTE                     deviceIndex,
                                                  BYTE                     rfIdx,
                                                  BCM_UW_RF_CHIP_TYPE_ENUM chipType,
                                                  UINT16                   regAddress,     
                                                  UINT16                   val)
{
    BCM_UW_ERROR_MSG_ENUM               retVal;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_RF_WRITE_REGISTER_STRUCT registerToWrite;

    registerToWrite.chipType = chipType;
    registerToWrite.offset   = regAddress;
    registerToWrite.value    = val;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&registerToWrite,
                                       sizeof(BCM_UW_COM_RF_WRITE_REGISTER_STRUCT),
                                       BCM_UW_COM_RF_REGISTER_WRITE_OPCODE_E,
                                       rfIdx,
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}


//----------------------------------------------------
// Flash Handling Functions
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashHeaderBurn(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_HEADER_STRUCT *header)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_FLASH_CHUNK_STRUCT       flashChunk;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    flashChunk.flashIndex = flashIndex;
    memcpy((BYTE*)flashChunk.pBuffer, (BYTE*)header, sizeof(BCM_UW_FLASH_HEADER_STRUCT));

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&flashChunk,
                                              sizeof(flashChunk),
                                              BCM_UW_COM_FLASH_HEADER_BURN_OPCODE_E,
                                              0, //FLASH
                                              NULL,
                                              &rxLen,
                                              &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
        return (retVal);
    }


    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return (retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashHeaderGet(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_HEADER_STRUCT *header)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              (BYTE*)&flashIndex,
                                              sizeof(flashIndex),
                                              BCM_UW_COM_FLASH_HEADER_GET_OPCODE_E,
                                              0, //FLASH
                                              rxBuffer,
                                              &rxLen,
                                              &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_FLASH_HEADER_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(header, rxBuffer, rxLen);
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashInfoGet(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_INFO_STRUCT *pVer)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    longJobID;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&flashIndex,
                                       sizeof(flashIndex),
                                       BCM_UW_COM_FLASH_INFO_GET_OPCODE_E,
                                       0, //FLASH
                                       &longJobID,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, rxBuffer); 
    }

    RETURNED_LENGTH_CHECK(sizeof(BCM_UW_FLASH_INFO_STRUCT));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy(pVer, rxBuffer, sizeof(BCM_UW_FLASH_INFO_STRUCT));
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
// Erase the older FW according to burn number and checksum calculation
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareErase(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    param;
    BYTE                    longJobID;

    /*
    |---------------|---------------|
    |     bit7      |     bit0-2    |
    |---------------|---------------|
    | firmwareIndex | flashIndex    |
    |---------------|---------------|
    */

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    param = ((BYTE)firmwareIndex << FLASH_INDEX_BIT) | (flashIndex & 0x7);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&param,
                                       sizeof(param),
                                       BCM_UW_COM_FLASH_FW_ERASE_OPCODE_E,
                                       0, //FLASH
                                       &longJobID,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, NULL); 
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
       
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
// Burn FW to flash: Assumed FW space is already erased 
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareBurn(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex, BYTE *buffer, UINT32 length)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    UINT32                          bytesToSet;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   flashChunk;
    UINT32                          bytesSetSoFar = 0;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    /*
    |---------------|---------------|
    |     bit7      |     bit0-2    |
    |---------------|---------------|
    | firmwareIndex | flashIndex    |
    |---------------|---------------|
    */
    flashChunk.flashIndex = ((BYTE)firmwareIndex << FLASH_INDEX_BIT) | (flashIndex & 0x7);

    //file Chunk put/write
    flashChunk.position = BCM_UW_COM_CONFIG_FILE_START_E;
    while (length > 0)
    {
        bytesToSet = MIN(sizeof(flashChunk.pBuffer), length);
        memcpy((BYTE*)flashChunk.pBuffer, &buffer[bytesSetSoFar], bytesToSet);
        flashChunk.buffLen = bytesToSet;

        if (bytesToSet == length)
        {
            flashChunk.position = BCM_UW_COM_CONFIG_FILE_END_E;
        }

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&flashChunk,
                                           sizeof(flashChunk),
                                           BCM_UW_COM_FLASH_FW_BURN_OPCODE_E,
                                           0, //FLASH
                                           NULL,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return(retVal);
        }

        length -= bytesToSet;
        bytesSetSoFar += bytesToSet;


        flashChunk.position = BCM_UW_COM_CONFIG_FILE_MIDDLE_E;
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareBurnEnd(BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    param;
    BYTE                    longJobID;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    /*
    |---------------|---------------|
    |     bit7      |     bit0-1    |
    |---------------|---------------|
    | firmwareIndex | flashIndex    |
    |---------------|---------------|
    */
    param = ((BYTE)firmwareIndex << FLASH_INDEX_BIT) | (flashIndex & 0x7);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&param,
                                       sizeof(param),
                                       BCM_UW_COM_FLASH_FW_BURNEND_OPCODE_E,
                                       0, //FLASH
                                       &longJobID,
                                       &rxLen,
                                       &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(BYTE));

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, NULL); 
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFSFormat(BYTE deviceIndex, BYTE flashIndex)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&flashIndex,
                                       sizeof(flashIndex),
                                       BCM_UW_COM_FLASH_FS_FORMAT_OPCODE_E,
                                       0, //FLASH
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFilePut(BYTE deviceIndex, BYTE flashIndex, BYTE *filename, BYTE *buffer, UINT32 length)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    UINT32                          bytesToSet;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   flashChunk;
    UINT32                          bytesSetSoFar = 0;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    flashChunk.flashIndex = flashIndex;
    strncpy((char*)flashChunk.filename, (char*)filename, sizeof(flashChunk.filename));

    // Delete if file exists
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&flashChunk,
                                       sizeof(flashChunk),
                                       BCM_UW_COM_FLASH_FILE_DELETE_OPCODE_E,
                                       0, //FLASH
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
        return(retVal);
    }

    //file Chunk put/write
    flashChunk.flashIndex = flashIndex;

    while (length > 0)
    {
        bytesToSet = MIN((BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_LONG_API_HEADER_SIZE - BCM_UW_COM_FLASH_CHUNK_HEADER_SIZE), length);
        memcpy((BYTE*)flashChunk.pBuffer, &buffer[bytesSetSoFar],bytesToSet);
        flashChunk.buffLen = bytesToSet;

        flashChunk.position = bytesToSet < length ? BCM_UW_COM_CONFIG_FILE_MIDDLE_E : BCM_UW_COM_CONFIG_FILE_END_E; // Calls Flash Sync on End

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&flashChunk,
                                           sizeof(flashChunk),
                                           BCM_UW_COM_FLASH_FILECHUNK_PUT_OPCODE_E,
                                           0, //FLASH
                                           NULL,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return(retVal);
        }

        length -= bytesToSet;
        bytesSetSoFar += bytesToSet;
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileGet(BYTE deviceIndex, BYTE flashIndex, BYTE *filename, BYTE *buffer, UINT32 bufLen, UINT32 *retLen)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   rxFlashChunk;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   txFlashChunk;
    UINT32                          bytesReadSoFar = 0;

    *retLen = 0;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    txFlashChunk.flashIndex = flashIndex;
    strncpy((char*)txFlashChunk.filename, (char*)filename, sizeof(txFlashChunk.filename));

    //file Chunk get/read
    txFlashChunk.buffLen = sizeof(rxFlashChunk.pBuffer);

    while(1)
    {
        txFlashChunk.position = bytesReadSoFar;

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&txFlashChunk,
                                           sizeof(txFlashChunk),
                                           BCM_UW_COM_FLASH_FILECHUNK_GET_OPCODE_E,
                                           0, //FLASH
                                           (BYTE*)&rxFlashChunk,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return(retVal);
        }

        if (bytesReadSoFar + rxFlashChunk.buffLen > bufLen)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return BCM_UW_INVALID_PARAMS_E;
        }

        memcpy((BYTE*)buffer+bytesReadSoFar, rxFlashChunk.pBuffer, rxFlashChunk.buffLen);
        bytesReadSoFar += rxFlashChunk.buffLen;
        *retLen = bytesReadSoFar;

        if (rxFlashChunk.buffLen < txFlashChunk.buffLen) // Read less than requested
        {
            break;
        }
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileDelete(BYTE deviceIndex, BYTE flashIndex, BYTE *filename)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   flashChunk;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    flashChunk.flashIndex = flashIndex;
    strncpy((char*)flashChunk.filename, (char*)filename, sizeof(flashChunk.filename));

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE*)&flashChunk,
                                       sizeof(flashChunk),
                                       BCM_UW_COM_FLASH_FILE_DELETE_OPCODE_E,
                                       0, //FLASH
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileList(BYTE deviceIndex, BYTE flashIndex, BYTE *buffer, UINT32 length)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   rxFlashChunk;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   txFlashChunk;
    UINT32                          bytesReadSoFar = 0;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    //file list get
    txFlashChunk.position = 0;
    txFlashChunk.flashIndex = flashIndex;
    txFlashChunk.buffLen = sizeof(rxFlashChunk.pBuffer);

    while(1)
    {
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&txFlashChunk,
                                           sizeof(txFlashChunk),
                                           BCM_UW_COM_FLASH_FILE_LIST_OPCODE_E,
                                           0, //FLASH
                                           (BYTE*)&rxFlashChunk,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return(retVal);
        }

        if (bytesReadSoFar + strlen((char*)rxFlashChunk.pBuffer) > length)
        {
            bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
            return BCM_UW_INVALID_PARAMS_E;
        }

        strncpy((char*)buffer+bytesReadSoFar, (char*)rxFlashChunk.pBuffer, length - bytesReadSoFar);
        bytesReadSoFar += strlen((char*)rxFlashChunk.pBuffer);
        
        if (rxFlashChunk.position == 0)
        {
            break;
        }

        txFlashChunk.position += rxFlashChunk.position;
    }

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);

    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileSizeGet(BYTE deviceIndex, BYTE flashIndex, BYTE *filename, UINT32 *size)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM           retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                          rxLen;
    BCM_UW_ERROR_MSG_ENUM           rxStatus;
    BCM_UW_COM_FLASH_CHUNK_STRUCT   flashChunk;

    // Function uses specific mutex
    bcmUwHostMutexLock(gSpiTransactionApiMutex[deviceIndex]);

    flashChunk.flashIndex = flashIndex;
    strncpy((char*)flashChunk.filename, (char*)filename, sizeof(flashChunk.filename));

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&flashChunk,
                                           sizeof(flashChunk),
                                           BCM_UW_COM_FLASH_FILE_SIZE_GET_OPCODE_E,
                                           0, //FLASH
                                           (BYTE*)size,
                                           &rxLen,
                                           &rxStatus);

    RETURNED_LENGTH_CHECK(sizeof(UINT32));

    bcmUwHostMutexUnlock(gSpiTransactionApiMutex[deviceIndex]);
    return retVal;
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspBootLoaderSet
//
//  PARAMETERS:
//              deviceIndex    - [in] device index
//              pDspBootLoader - [in] pointer to boot loader program
//              lenBytes       - [in] the length of boot loader program in bytes
//
//  DESCRIPTION: Sends the DSP boot loader program to MC
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspBootLoaderSet(BYTE deviceIndex, BYTE *pDspBootLoader, UINT32 lenBytes)
{
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  bytesToSet;
    BCM_UW_COM_DSP_BUFFER_CHUNK_STRUCT dspBufferChunk;
    UINT32                  bytesSetSoFar = 0;

    // Function uses specific mutex
    bcmUwHostMutexLock(gDspBootLoaderApiMutex[deviceIndex]);

    dspBufferChunk.dspIdx = 0xff; // not relevant for this API
    dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_START_E;

    // in case the total length of the DSP application is less than the max payload size
    if (lenBytes <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2))
    {
        dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_END_E;
    }

    while (lenBytes > 0)
    {
        bytesToSet = MIN((BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2),lenBytes);
        memcpy((BYTE*)dspBufferChunk.pBuffer,&pDspBootLoader[bytesSetSoFar],bytesToSet);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&dspBufferChunk,
                                           (bytesToSet+2*sizeof(BYTE)), // 1 byte for dspIdx and 1 byte for position
                                           BCM_UW_COM_DSP_BOOT_LOADER_SET_OPCODE_E,
                                           0,
                                           NULL,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gDspBootLoaderApiMutex[deviceIndex]);
            return(retVal);
        }

        lenBytes -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (lenBytes <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1))
        {
            dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_END_E;
        }
        else
        {
            dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_MIDDLE_E;
        }
    }

    bcmUwHostMutexUnlock(gDspBootLoaderApiMutex[deviceIndex]);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspSubsystemConfigure
//
//  PARAMETERS:
//              deviceIndex                 - [in] device index
//              pDspSubsystemConfigStruct   - [in] dsp subsytem configuration structure
//
//  DESCRIPTION: Configure DSP subsystem (e.g. GPIO, MCCI, logger, events, MCI route)
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspSubsystemConfigure(BYTE deviceIndex, BCM_UW_DSP_SUBSYSTEM_CONFIG_STRUCT *pDspSubsystemConfigStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  rxLen;
    UINT32                  ix;
    BCM_UW_COM_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT subsystemDspConfig;

    // Function uses specific mutex
    bcmUwHostMutexLock(gDspSubsystemConfigApiMutex[deviceIndex]);

    for (ix=0; ix<BCM_UW_NUM_OF_DSP_E; ix++)
    {
        subsystemDspConfig.dspIdx = ix;
        memcpy ((BYTE*)&subsystemDspConfig.subsystemBlockConfig,
                (BYTE*)&pDspSubsystemConfigStruct->perDspConfig[ix],
                sizeof(BCM_UW_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT));

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&subsystemDspConfig,
                                       sizeof(BCM_UW_COM_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT),
                                       BCM_UW_COM_DSP_SUBSYSTEM_PER_DSP_CONFIG_OPCODE_E,
                                       0, //DSP
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gDspSubsystemConfigApiMutex[deviceIndex]);
            return(retVal);
        }
    }

    bcmUwHostMutexUnlock(gDspSubsystemConfigApiMutex[deviceIndex]);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspBlockConfigure
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspIdx                  - [in] index of DSP according to BCM_UW_DSP_IDX_ENUM
//              pDspBlockConfigStruct   - [in] dsp configuration stucture
//
//  DESCRIPTION: Configure DSP block parameters (e.g. packer, depacker, FIFOs etc.)
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspBlockConfigure(BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_DSP_BLOCK_CONFIG_STRUCT *pDspBlockConfigStruct)
{
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  bytesToSet;
    BCM_UW_COM_DSP_BUFFER_CHUNK_STRUCT dspBufferChunk;
    UINT32                  bytesSetSoFar = 0;
    UINT32                  lenBytes;

    // Function uses specific mutex
    bcmUwHostMutexLock(gDspBlockConfigApiMutex[deviceIndex]);

    dspBufferChunk.dspIdx   = (BYTE)dspIdx; //handle ENUM
    dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_START_E;
    lenBytes = sizeof(BCM_UW_DSP_BLOCK_CONFIG_STRUCT);

    while (lenBytes > 0)
    {
        bytesToSet = MIN((BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2),lenBytes);
        memcpy((BYTE*)dspBufferChunk.pBuffer,((BYTE*)pDspBlockConfigStruct) + bytesSetSoFar, bytesToSet);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&dspBufferChunk,
                                           (bytesToSet + 2 *sizeof(BYTE)), // 1 byte for dspIdx and 1 byte for position
                                           BCM_UW_COM_DSP_BLOCK_CONFIG_OPCODE_E,
                                           0, //DSP
                                           NULL,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gDspBlockConfigApiMutex[deviceIndex]);
            return(retVal);
        }

        lenBytes -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (lenBytes <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1))
        {
            dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_END_E;
        }
        else
        {
            dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_MIDDLE_E;
        }
    }

    bcmUwHostMutexUnlock(gDspBlockConfigApiMutex[deviceIndex]);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspApplicationLoad
//
//  PARAMETERS:
//              deviceIndex     - [in] device index
//              dspIdx          - [in] DSP index [5:0]
//              pDspApplication - [in] pointer to DSP application program
//              lenBytes        - [in] length in bytes of the DSP application program
//
//  DESCRIPTION: Load DSP program and data memory.
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspApplicationLoad(BYTE                   deviceIndex,
                                                    BCM_UW_DSP_IDX_ENUM    dspIdx,
                                                    BYTE                   *pDspApplication,
                                                    UINT32                 lenBytes)
{
#ifndef BCM85820D_HL
    BCM_UW_ERROR_MSG_ENUM   retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  bytesToSet;
    BCM_UW_COM_DSP_BUFFER_CHUNK_STRUCT dspBufferChunk;
    UINT32                  bytesSetSoFar = 0;
    UINT32                  retries = 20;
    UINT32                  maxByteToSet;
    UINT32                  temp;
    BYTE                    longJobID;

    // Function uses specific mutex
    bcmUwHostMutexLock(gDspApplicationLoadApiMutex[deviceIndex]);

    dspBufferChunk.dspIdx   = (BYTE)dspIdx; //handle ENUM
    dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_START_E;

    // set maximum byte to set, make sure last chunk containing more than checksum
    maxByteToSet = BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2-2;
    temp = lenBytes % maxByteToSet;
    if (temp <= 4)
    {
        maxByteToSet-=4;
    }

    // in case the total length of the DSP application is less than the max payload size
    if (lenBytes <= maxByteToSet)
    {
        dspBufferChunk.position = BCM_UW_COM_DSP_CHUNK_END_E;
    }

    while (lenBytes > 0)
    {
        bytesToSet = MIN(maxByteToSet, lenBytes);
        memcpy((BYTE*)dspBufferChunk.pBuffer,&pDspApplication[bytesSetSoFar],bytesToSet);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                           (BYTE*)&dspBufferChunk,
                                           (bytesToSet+ 2 * sizeof(BYTE)), // 1 byte for dspIdx and 1 byte for position
                                           BCM_UW_COM_DSP_APP_LOAD_OPCODE_E,
                                           0,
                                           &longJobID,
                                           &rxLen,
                                           &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gDspApplicationLoadApiMutex[deviceIndex]);
            return(retVal);
        }

        retVal = bcmUwLongApiProbe(deviceIndex,0, longJobID, &rxLen, NULL);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            bcmUwHostMutexUnlock(gDspApplicationLoadApiMutex[deviceIndex]);
            return(retVal);
        }

        lenBytes -= bytesToSet;
        bytesSetSoFar += bytesToSet;
        dspBufferChunk.position = (lenBytes <= maxByteToSet) ? BCM_UW_COM_DSP_CHUNK_END_E : BCM_UW_COM_DSP_CHUNK_MIDDLE_E;
    }

    // validate boot done
    while (retries > 0)
    {
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                               (BYTE*)&dspBufferChunk,
                                               (sizeof(BYTE)), // 1 byte for dspIdx
                                               BCM_UW_COM_DSP_APP_LOAD_DONE_OPCODE_E,
                                               0, //DSP
                                               NULL,
                                               &rxLen,
                                               &rxStatus);
        retries--;
        if (retVal == BCM_UW_SUCCESS_MSG_E)
        {
            break;
        }
        bcmUwHostSleep(1000);
    }

    bcmUwHostMutexUnlock(gDspApplicationLoadApiMutex[deviceIndex]);
    return(retVal);
#else
    return BCM_UW_API_NOT_SUPPORTED_E;
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspStart
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspStartBitField        - [in] bit 0 for DSP 0 .. bit 5 for DSP5
//
//  DESCRIPTION: Starts “data path” for requested DSPs
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspStart(BYTE deviceIndex, BYTE dspStartBitField)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  rxLen;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   &dspStartBitField,
                                   sizeof(BYTE),
                                   BCM_UW_COM_DSP_START_OPCODE_E,
                                   0, //DSP
                                   NULL,
                                   &rxLen,
                                   &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspStop
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspStopBitField         - [in] bit 0 for DSP 0 .. bit 5 for DSP5
//
//  DESCRIPTION: Stops “data path” for requested DSPs
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspStop(BYTE deviceIndex, BYTE dspStopBitField)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    UINT32                  rxLen;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   &dspStopBitField,
                                   sizeof(BYTE),
                                   BCM_UW_COM_DSP_STOP_OPCODE_E,
                                   0, //DSP
                                   NULL,
                                   &rxLen,
                                   &rxStatus);
    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspDebugSet(BYTE deviceIndex, UINT32 opcode, BYTE length, BYTE *data)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BCM_UW_COM_GENERAL_CONTROL_STRUCT generalControl;

    generalControl.opcode = opcode;
    length                = MIN(length, sizeof(generalControl.pDataBuffer));
    generalControl.length = length;
    memcpy((BYTE*)generalControl.pDataBuffer, data, length);

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&generalControl,
                                       (BYTE)(BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE + length),
                                       BCM_UW_COM_DSP_DEBUG_SET_OPCODE_E,
                                       0, //DSP
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspDebugGet(BYTE deviceIndex, UINT32 opcode, BYTE lengthTx, BYTE *dataTx, BYTE *lengthRx, BYTE *dataRx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BCM_UW_COM_GENERAL_CONTROL_STRUCT *pGeneralControl = (BCM_UW_COM_GENERAL_CONTROL_STRUCT*)&rxBuffer;
    BCM_UW_COM_GENERAL_CONTROL_STRUCT generalControlTx;

    generalControlTx.opcode = opcode;
    lengthTx                = MIN(lengthTx, sizeof(generalControlTx.pDataBuffer));
    generalControlTx.length = lengthTx;
    memcpy((BYTE*)generalControlTx.pDataBuffer, dataTx, lengthTx);

    *lengthRx = 0;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&generalControlTx,
                                       (BYTE)(BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE + lengthTx),
                                       BCM_UW_COM_DSP_DEBUG_GET_OPCODE_E,
                                       0, //DSP
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        *lengthRx = MIN(pGeneralControl->length, BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE);
        memcpy(dataRx, (BYTE*)pGeneralControl->pDataBuffer, *lengthRx);
    }

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspMemoryWrite
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspMemory               - [in] memory type according to BCM_UW_DSP_MEMORY_TYPE_ENUM enum
//              startAddr               - [in] memory offset address
//              length                  - [in] amount of data in bytes to be written to dsp memory
//              data                    - [in] pointer to data to be set into the memory
//
//  DESCRIPTION: Writes the data array into the requested memory (DMEM or Shared memory)
//               the max length should be according to the actual memory size (HW)
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMemoryWrite(BYTE deviceIndex, BCM_UW_DSP_MEMORY_TYPE_ENUM dspMemory, UINT32 startAddr, UINT32 length, BYTE *data)
{
    BCM_UW_ERROR_MSG_ENUM               retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_DSP_MEMORY_WR_RD_STRUCT  memWr;
    UINT32                              dataOffset = 0;

    memWr.memoryType = (BYTE)dspMemory; //handle ENUM
    memWr.addr = startAddr;

    while (length>0)
    {
        memWr.length = MIN(length, BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE);
        memcpy(memWr.data, data + dataOffset, memWr.length);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)&memWr,
                                   (BYTE)(memWr.length + BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE), //const size
                                   BCM_UW_COM_DSP_MEM_WR_OPCODE_E,
                                   0, //DSP
                                   NULL,
                                   &rxLen,
                                   &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return(retVal);
        }

        dataOffset += memWr.length;
        length     -= memWr.length;
        memWr.addr += memWr.length;
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspMemoryRead
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspMemory               - [in] memory type according to BCM_UW_DSP_MEMORY_TYPE_ENUM enum
//              startAddr               - [in] memory offset address
//              length                  - [in] amount of data in bytes to be read from dsp memory
//              data                    - [Out] pointer to data was read from the  requested memory
//
//  DESCRIPTION: Read the data array from the requested memory (DMEM or Shared memory).
//               the max length should be according to the actual memory size (HW)
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMemoryRead(BYTE deviceIndex, BCM_UW_DSP_MEMORY_TYPE_ENUM dspMemory, UINT32 startAddr, UINT32 length,  BYTE *data)
{
    BCM_UW_ERROR_MSG_ENUM               retVal = BCM_UW_SUCCESS_MSG_E;
    UINT32                              rxLen;
    BCM_UW_ERROR_MSG_ENUM               rxStatus;
    BCM_UW_COM_DSP_MEMORY_WR_RD_STRUCT  memRd;
    BYTE                                rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    UINT32                              dataOffset = 0;

    memRd.memoryType = (BYTE)dspMemory;
    memRd.addr = startAddr;

    while (length>0)
    {
        memRd.length = MIN(length, BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE);

        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                   (BYTE *)&memRd,
                                   (BYTE)(memRd.length + BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE), //const size
                                   BCM_UW_COM_DSP_MEM_RD_OPCODE_E,
                                   0, //DSP
                                   rxBuffer,
                                   &rxLen,
                                   &rxStatus);

        if (retVal != BCM_UW_SUCCESS_MSG_E)
        {
            return(retVal);
        }
        memcpy(data + dataOffset, rxBuffer,  memRd.length);
        dataOffset += memRd.length;
        length     -= memRd.length;
        memRd.addr += memRd.length;
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspHostMsgGet
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspIdx                  - [in] DSP index [5:0]
//              length                  - [Out] length of DSP message
//              data                    - [Out] pointer to dataRx from DSP 
//
//  DESCRIPTION: Read the DSP-Host message 
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMailboxMessageReceive(BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_COM_DSP_HOST_MSG_STRUCT *pMbx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    rxBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];
    BYTE                    txBuffer = dspIdx;

    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&txBuffer,
                                       sizeof(txBuffer),
                                       BCM_UW_COM_DSP_MAILBOX_MESSAGE_RECEIVE_OPCODE_E,
                                       0, //DSP
                                       rxBuffer,
                                       &rxLen,
                                       &rxStatus);

    if (retVal == BCM_UW_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pMbx, rxBuffer, sizeof(BCM_UW_COM_DSP_HOST_MSG_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: BCM_UW_API_DspHostMsgSet
//
//  PARAMETERS:
//              deviceIndex             - [in] device index
//              dspIdx                  - [in] DSP index [5:0]
//              length                  - [in] length of DSP message
//              data                    - [in] pointer to dataTx to DSP
//
//  DESCRIPTION: Read the DSP-Host message 
//
//  RETURNS:    BCM_UW_ERROR_MSG_ENUM
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMailboxMessageSend(BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_COM_DSP_HOST_MSG_STRUCT *pMbx)
{
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;
    BYTE                    txBuffer[BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN];

    txBuffer[0] = dspIdx;
    memcpy(&txBuffer[1], (BYTE *)pMbx, sizeof(BCM_UW_COM_DSP_HOST_MSG_STRUCT));
                                      
    retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                       (BYTE *)&txBuffer,
                                       (pMbx->length + sizeof(pMbx->length) + 1),
                                       BCM_UW_COM_DSP_MAILBOX_MESSAGE_SEND_OPCODE_E,
                                       0, //DSP
                                       NULL,
                                       &rxLen,
                                       &rxStatus);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
BCM_UW_ERROR_MSG_ENUM bcmUwLongApiProbe(BYTE deviceIndex, BYTE scIndex, BYTE longJobID, UINT32 *internalRxLen, BYTE *retParams /* Optional */)
{
    BCM_UW_COM_LONG_API_PROBE_STRUCT longMsg;
    BCM_UW_ERROR_MSG_ENUM   retVal;
    UINT32                  rxLen;
    BCM_UW_ERROR_MSG_ENUM   rxStatus;    
    UINT32  startTime, elapsedTime;
    UINT32 cnt = 50;
    startTime = bcmUwHostTickGet(); //note that on some platforms, this may not be accurate
    
    while(TRUE) 
    {
 //    printfpd1("\n\r cnt:%d", cnt);
    
        retVal = bcmUwHostCommBuildSendAndReceive(deviceIndex,
                                              &longJobID,
                                              sizeof(BYTE),
                                              BCM_UW_COM_LONG_API_PROBE_OPCODE_E,
                                              scIndex,
                                              (BYTE*)&longMsg,
                                              &rxLen,
                                              &rxStatus);
        
        if (retVal == BCM_UW_API_NOT_READY_E) 
        {
            // Sleep in usec
            bcmUwHostSleep(BCM_UW_LONG_API_PROBE_TIMEOUT_MSEC * 1000);
        }
        else
        {
            break;
        }
    /*    
        elapsedTime = (bcmUwHostTickGet() - startTime); // what's the time?
        
        if (elapsedTime > BCM_UW_LONG_API_MAX_TIMEOUT)
        {
            return BCM_UW_API_GENERAL_ERROR_E; // LongAPI timed out
        }
  */      
        if(!cnt--) { 
       printfp1(" cnt - zero  ");
       break;
       }
       
    }
    
    if (retVal != BCM_UW_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = (BCM_UW_ERROR_MSG_ENUM)longMsg.txAckCode; 
    if ( (retParams != NULL) && (longMsg.len > 0) && (longMsg.len <= (BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_LONG_API_HEADER_SIZE)) ) 
    {
        memcpy(retParams, &longMsg.txMsg[0], longMsg.len);
    }

    (*internalRxLen) = longMsg.len;
    
    return (retVal);   
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

