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


#ifndef _rf_progress_error_parse_
#define _rf_progress_error_parse_


#ifdef __cplusplus
extern "C" {
#endif

#include "rf_progress_error.h"
#include "bcm_uw_api.h"

#define GENERATE_STRING(STRING) #STRING,
#if 0
static const char *HALRF_PROGRESS_STRING[] = {
    FOREACH_RF_PRGORESS(GENERATE_STRING)
};

static const char *HALRF_ERROR_STRING[] = {
    FOREACH_RF_ERROR(GENERATE_STRING)
};
#endif
//////////////////////////////////////////////////////////////////////////////
// RF last error handlers
//////////////////////////////////////////////////////////////////////////////

#define RF_STACK_BUFFER_SIZE 200
void rf_StackTraceGet(char *stackBuffer, UINT32 stackBufferLen);
void rf_StackTraceSet( void );

BCM_UW_ERROR_MSG_ENUM rf_ProgressErrorBufferParse(BCM_UW_RF_PROGRESS_ERROR_STRUCT *progressErrorData, char *progressErrorBuffer, UINT32 progressErrorBufferLen, UINT16 *errorBitMap);

#ifdef __cplusplus
}
#endif


#endif /* _rf_progress_error_parse_ */




