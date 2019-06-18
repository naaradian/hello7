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


#ifndef ENDIAN_UW_H
#define ENDIAN_UW_H

#include "defs_uw.h"
#include "hostProtocolOpcodes.h"
#include "hostProtocolStructs.h"

///////////////////////////////////////////////////////////////////////////////
// ENUM
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// External function decleration
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
// Configure endian swapping
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianConversionConfigure (BOOLEAN enabled);

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianRequestParamSwap    (BCM_UW_COM_OPCODE_ENUM    opcode,
                                     BYTE                      *pMsgBuffer,
                                     UINT32                    msgBufferLen);

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianResponseParamSwap   (BCM_UW_COM_OPCODE_ENUM    opcode,
                                     BYTE                      *pMsgBuffer,
                                     UINT32                    msgBufferLen);

#ifdef __cplusplus
}
#endif

#endif  //ENDIAN_H

