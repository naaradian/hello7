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


#ifndef _HOST_DRIVER_H_
#define _HOST_DRIVER_H_

#include "defs_uw.h"
#include "bcm_uw_api.h"


#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------
    Init functions
------------------------------------------------------*/
BOOLEAN bcmUwHostOpen                   (void);
BOOLEAN bcmUwHostClose                  (void);

/*------------------------------------------------------
    General functions
------------------------------------------------------*/
void    bcmUwHostDeviceReset            (BYTE deviceIndex);
void    bcmUwHostSleep                  (UINT32 sleepTimeMicro);
UINT32  bcmUwHostTickGet                (void);
void    bcmUwHostApiMutexGet            (BYTE deviceIndex);
void    bcmUwHostApiMutexRelease        (BYTE deviceIndex);

/*------------------------------------------------------
    OS objects functions
------------------------------------------------------*/
typedef void* bcmUwHostMutexHandle;                    // handle to Mutex

/*------------------------------------------------------
    OS objects functions - mutex
------------------------------------------------------*/
bcmUwHostMutexHandle    bcmUwHostMutexCreate    (void);                                 // Create mutex. If return value is NULL, mutex creation failed
void                    bcmUwHostMutexDelete    (bcmUwHostMutexHandle mutex);           // Delete the mutex. Called from BCM_UW_API_Close() which may not be used by real systems.
int                     bcmUwHostMutexLock      (bcmUwHostMutexHandle mutex);           // lock / take / enter. Returns 0 on success, 1 on failure
                                                                                        // Thread is blocked until the mutex is unlocked by another holder
                                                                                        // lock may be called recursively by the same thread
int                     bcmUwHostMutexUnlock    (bcmUwHostMutexHandle mutex);           // unlock / give / exit. Returns 0 on success, 1 on failure
                                                                                        // in case the thread locked the mutex more than once, it is released only after being unlocked the same number of times

/*------------------------------------------------------
    UART functions
------------------------------------------------------*/
void    bcmUwHostUartReceiverFlush      (BYTE deviceIndex);
void    bcmUwHostUartDataSend           (BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen);
void    bcmUwHostUartDataReceive        (BYTE deviceIndex, /*@out@*/ BYTE *pBuff, UINT32 buffLen, UINT32 timeoutMilli, /*@out@*/ UINT32 *pReadBytes);

/*------------------------------------------------------
    SPI functions
------------------------------------------------------*/
void    bcmUwHostSpiDataSend            (BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen);
void    bcmUwHostSpiDataReceive         (BYTE deviceIndex, BYTE *pTxBuff, /*@out@*/ BYTE *pRxBuff, UINT32 buffLen);
void    bcmUwHostSpiModeSet             (BYTE deviceIndex, int mode);
void    bcmUwHostSpiMaxRateSet          (BYTE deviceIndex, UINT32 maxRateHz);
BOOLEAN bcmUwHostSpiIsDataReady         (BYTE deviceIndex);
BOOLEAN bcmUwHostSpiDataReadyWait       (BYTE deviceIndex, UINT32 timeoutMilli);

/*------------------------------------------------------
    MII functions
------------------------------------------------------*/
void    bcmUwHostMIIDataWrite           (BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen);
BOOLEAN bcmUwHostMIIDataRead            (BYTE deviceIndex, /*@out@*/ BYTE *pBuff, UINT32 maxLen, UINT32 /*@out@*/ *pBuffLen, UINT32 timeoutMilli);


#ifdef __cplusplus
}
#endif

#endif  /*_HOST_DRIVER_H_*/



