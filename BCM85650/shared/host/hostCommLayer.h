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


#ifndef HOST_COMM_LAYER_H
#define HOST_COMM_LAYER_H

#include "defs_uw.h"
#include "bcm_uw_api.h"
#include "hostProtocolOpcodes.h"


///////////////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////////////

// open the comm layer - opens all threads, events, semaphores needed, etc.
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommOpen                     (void);

// close whatever's been openned
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommClose                    (void);

// complete "build, send and recieve" including building message from payload, endian swapping, etc.
// used mainly for local APIs
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommBuildSendAndReceive      (BYTE                       deviceIndex,            // to which device to send
                                                             /*@in@*/BYTE               *pTxPayloadBuff,        // payload to send (not including header or checksum)
                                                             UINT32                     txPayloadLen,           // payload length
                                                             BCM_UW_COM_OPCODE_ENUM     opcode,                 // opcode
                                                             BYTE                       modemIndex,             // to which modem
                                                             /*@out@*/BYTE              *pRxPayloadBuff,        // Where to store the received payload (length assumed to be suffient)
                                                             /*@out@*/UINT32            *pActualRxLen,          // Where to indicate actual received payload length
                                                             /*@out@*/BCM_UW_ERROR_MSG_ENUM *pStatus);        // Where to place the status, must be given otherwise will return OK even if not

// Partial "build, send (no receive)" including building message from payload, endian swapping, etc.
// response is never expected, not only to the user, but also to the hostComm layer
// used only in boot / upgrade scenarios
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommBuildSend                (BYTE                       deviceIndex,            // to which device to send
                                                             /*@in@*/BYTE               *pTxPayloadBuff,        // payload to send (not including header or checksum)
                                                             UINT32                     txPayloadLen,           // payload length
                                                             BCM_UW_COM_OPCODE_ENUM     opcode,                 // opcode
                                                             BYTE                       modemIndex);            // to which modem

// signal that boot is underway, not other messages can occur
void bcmUwHostCommEnableMessageForwarding                   (BYTE                       deviceIndex,
                                                             BOOLEAN                    enable);

// Raw data access. Must run in exclusive mode. Used in boot scenario only
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommRawDataSend              (BYTE                       deviceIndex,            // to which device to send
                                                             /*@in@*/BYTE               *pBuff,                 // raw buffer to send
                                                             UINT32                     buffLen);               // raw buffer length

// Modify / override user's specified API timeout.
// Used in boot / upgrade for quick, off the record, "is alive" polling
UINT32 bcmUwHostCommModifyRxTimeout                         (BYTE                       deviceIndex,
                                                             UINT32                     newRxTimeout);

// Perform actions that are needed after chip reset, e.g.
// Flush recevier and reset its state,
// Enable DPRAM interupts, etc.
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommPostResetActions         (BYTE                       deviceIndex);


// IP forwarding of remote client into comm layer
BCM_UW_ERROR_MSG_ENUM bcmUwHostCommMessageForward           (BYTE                       deviceIndex,            // to which device to send
                                                             /*@in@*/BYTE               *pReqBuffer,            // message to send (including header and checksum)
                                                             UINT32                     reqLen,                 // message length
                                                             /*@out@*/BYTE              *pRespBuffer,           // Where to store the received message (length assumed to be suffient)
                                                             /*@out@*/UINT32            *pRespLen);             // Where to indicate actual received message length



#ifdef __cplusplus  //allow cpp files to include c functions
extern "C" {
#endif

void bcmUwResponseMsgBuild(BCM_UW_COM_OPCODE_ENUM opcode, BYTE* pReqBuffer, BYTE* pLocalResponse, UINT32 payloadLen, BCM_UW_ERROR_MSG_ENUM retVal);

#ifdef __cplusplus
}
#endif


#endif //HOST_COMM_LAYER_H

