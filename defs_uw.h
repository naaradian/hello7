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


#ifndef DEFS_UW_H
#define DEFS_UW_H

//--------------------------------------------------------------------------------------------
//define PACK usage - compiler wont add padding to defined structs (important for MSG structs)
//--------------------------------------------------------------------------------------------
#ifndef __PACK__
    #define __PACK__
#endif

#ifndef __PACK_PREFIX__
    #define __PACK_PREFIX__
#endif
//--------------------------------------------------------------------------------------------

#ifdef WIN32
    #include "basetsd.h"
    #ifndef TRUE
        #define TRUE    1
    #endif
    #ifndef FALSE
        #define FALSE   0
    #endif

    typedef unsigned char       BYTE;
    typedef unsigned char       BOOLEAN;
    typedef signed char         INT8;
    typedef unsigned char       UINT8;
    typedef unsigned short      UINT16;
    typedef signed short        INT16;
    typedef __int64             INT64;
    typedef unsigned __int64    UINT64;

#elif defined(__INCvxWorksh)
    #ifndef TRUE
        #define TRUE    1
    #endif
    #ifndef FALSE
        #define FALSE   0
    #endif

    typedef unsigned char       BYTE;
    typedef unsigned char       BOOLEAN;
    typedef signed char         INT8;
    typedef unsigned char       UINT8;
    typedef unsigned short      UINT16;
    typedef signed short        INT16;
    //typedef unsigned long     UINT32; // already defined
    //typedef signed long       INT32;  // already defined
    typedef long long           INT64;
    typedef unsigned long long  UINT64;

#else
    #ifndef TRUE
        #define TRUE    1
    #endif
    #ifndef FALSE
        #define FALSE   0
    #endif
    #ifndef NULL
        #define NULL    0
    #endif
    typedef unsigned char       BYTE;
    typedef unsigned char       BOOLEAN;
    typedef signed char         INT8;
    typedef unsigned char       UINT8;
    typedef unsigned short      UINT16;
    typedef signed short        INT16;
    typedef unsigned long       UINT32;
    typedef signed long         INT32;
    typedef unsigned long long  UINT64;
    typedef long long           INT64;
#endif


typedef enum {
    MC_E,           //=0
    GP_E            //=1
} CPU_TYPE_ENUM;


#ifndef BCM_UW_DEVICES_NUM
    #define BCM_UW_DEVICES_NUM      (4)
#endif

#ifndef MAX
    #define MAX(A,B) ((A)>(B) ? (A):(B))
#endif

#ifndef MIN
    #define MIN(A,B) ((A)<(B) ? (A):(B))
#endif

#ifndef ABS
    #define  ABS(A)  (((A) < 0) ? -(A):(A))
#endif

#ifndef SIGN
    #define SIGN(A)     ((A<0) ? (-1) : (1))
#endif

#define MASK_BIT_0          0x1
#define MASK_BIT_1          0x2
#define MASK_BIT_2          0x4
#define MASK_BIT_3          0x8
#define MASK_BIT_4         0x10
#define MASK_BIT_5         0x20
#define MASK_BIT_6         0x40
#define MASK_BIT_7         0x80
#define MASK_BIT_8        0x100
#define MASK_BIT_9        0x200
#define MASK_BIT_10       0x400
#define MASK_BIT_11       0x800
#define MASK_BIT_12      0x1000
#define MASK_BIT_13      0x2000
#define MASK_BIT_14      0x4000
#define MASK_BIT_15      0x8000
#define MASK_BIT_16     0x10000
#define MASK_BIT_17     0x20000
#define MASK_BIT_18     0x40000
#define MASK_BIT_19     0x80000
#define MASK_BIT_20    0x100000
#define MASK_BIT_21    0x200000
#define MASK_BIT_22    0x400000
#define MASK_BIT_23    0x800000
#define MASK_BIT_24   0x1000000
#define MASK_BIT_25   0x2000000
#define MASK_BIT_26   0x4000000
#define MASK_BIT_27   0x8000000
#define MASK_BIT_28  0x10000000
#define MASK_BIT_29  0x20000000
#define MASK_BIT_30  0x40000000
#define MASK_BIT_31  0x80000000

//SIGNEXT MACROS (for drivers)
#define GETMASK32(n)        (((UINT32)0x1<<(n-1)) + (((UINT32)0x1<<(n-1))-1))   //return mask at the size of input (2^n-1), 1<input<32
#define GETMASK64(n)        (((UINT64)0x1<<(n-1)) + (((UINT64)0x1<<(n-1))-1))   //1<input<64
#define SIGNEXT16(x,k)      ((INT16)((x & GETMASK32(k)) << (16-k)) >> (16-k))   //x=input, k=input size (highest bit)
#define SIGNEXT32(x,k)      ((INT32)((x & GETMASK32(k)) << (32-k)) >> (32-k))
#define SIGNEXT64(x,k)      ((INT64)((x & GETMASK64(k)) << (64-k)) >> (64-k))


#define LOW  0
#define HIGH 1

typedef union
{
    UINT32 dWord;
    UINT16 word[2];
} DWORD_TO_WORD_UNION;

typedef union
{
    UINT64 qWord;
    UINT16 word[4];
} QWORD_TO_WORD_UNION;

#endif //DEFS_UW_H

