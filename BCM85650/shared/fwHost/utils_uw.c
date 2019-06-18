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


#include "utils_uw.h"
#include "string.h"
#include "hello7.h"


///////////////////////////////////////////////////////////////////////////////
// perform checksum calc on the buffer - returns the result.
///////////////////////////////////////////////////////////////////////////////
UINT32 utilsUwChecksumCalc(
                 UINT32     currentChecksum,
                 BYTE      *pBuf,
                 UINT32     len,
                 BOOLEAN    lastCall)
{
    UINT32   ix, tmp, remainder;

    // check if endian conversion
 //ok   return;
    
    if (utilsUwIsBigEndian())
    {
//    printfp1(" Point1");
        // calculate on whole number of DWORDs
        
        for (ix=0; ix < len / 4; ix++)
        {
            tmp = utilsUwEndianConversion((BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
            currentChecksum += tmp;
        }

        // calculate on whatever's left
        remainder = len % 4;
        if (remainder)
        {
            tmp = utilsUwEndianConversion(&pBuf[len-remainder], remainder);
            currentChecksum += tmp;
        }
            
        if (lastCall)
        {
            currentChecksum ^= 0xDEADBEEF;
        }

        currentChecksum = utilsUwEndianConversion((BYTE*)&currentChecksum, sizeof(UINT32));
    }
    else
    {
       //  printfp1(" Point2 ");
        // calculate on whole number of DWORDs
      //   printfpd1("Buf:%X", (UINT32)pBuf);   //Buf:20500004
     //    printfp1("\n\r");
        
        for (ix=0; ix < len / 4; ix++)
        {
            if(!ix %16) { 
         // printfp1("\n\r");
          OperateBuffers_usart1t();
          }
           memcpy((BYTE*)&tmp, (BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
       //     printfpd1(" %X",  (*(pBuf+ix*sizeof(UINT32)))); 
                    currentChecksum += tmp;
        }

        // calculate on whatever's left
        remainder = len % 4;
        if (remainder)
        {
            tmp = 0;
            memcpy((void*)&tmp, &pBuf[len-remainder], remainder);
            currentChecksum += tmp;
        }
         
        if (lastCall)
        {
            currentChecksum ^= 0xDEADBEEF;
        }
    }

    return(currentChecksum);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
BOOLEAN utilsUwIsBigEndian()
{
    UINT32   tmp = 1;
    BYTE     *ptr = (BYTE*)&tmp;

    // check if big endian
    if (*ptr == 0)
    {
        return TRUE;
    }
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
UINT32 utilsUwEndianConversion(BYTE *pBuf, UINT32 size)
{
    UINT32   tmp = 0;
    BYTE     *ptr = (BYTE*)&tmp;

    ptr[3] = pBuf[0];
    if (size > 1)     ptr[2] = pBuf[1];
    if (size > 2)     ptr[1] = pBuf[2];
    if (size > 3)     ptr[0] = pBuf[3];

    return tmp;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
BYTE utilsUwBitCount(UINT32 num)
{
    BYTE count;

    for (count = 0; num != 0; num &= num - 1)
    {
        count++;
    }

    return count;
}

