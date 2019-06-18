#ifndef DEFS_610_H
#define DEFS_610_H

#ifndef __PACK__
    #define __PACK__
#endif

#ifndef __PACK_PREFIX__
    #define __PACK_PREFIX__
#endif

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
    typedef unsigned char       UINT8;
    typedef unsigned short      UINT16;
    typedef signed short        INT16;
    //typedef unsigned long     UINT32; // defined in <basetsd.h>
    //typedef signed long       INT32;  // defined in <basetsd.h>
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
    typedef unsigned char       BYTE;
    typedef unsigned char       BOOLEAN;
    typedef unsigned char       UINT8;
    typedef unsigned short      UINT16;
    typedef signed short        INT16;
    typedef unsigned long       UINT32;
    typedef signed long         INT32;
    typedef unsigned long long  UINT64;
    typedef long long           INT64;
#endif


//typedef enum {
//    FAIL_E      = 0,
//    SUCCESS_E   = 1
//} RETURN_ENUM;






#ifndef MAX
    #define MAX(A,B) ((A)>(B) ? (A):(B))
#endif
#ifndef MIN
    #define MIN(A,B) ((A)<(B) ? (A):(B))
#endif

#ifndef ABS
    #define  ABS(A)  ((A < 0) ? -A : A)
#endif

#ifndef SIGN
    #define SIGN(A)     ((A<0) ? (-1) : (1))
#endif
/*
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
 */
#endif      // DEFS_H

