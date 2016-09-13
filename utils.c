#include "utils.h"
#include "string.h"


///////////////////////////////////////////////////////////////////////////////
// perform checksum calc on the buffer - returns the result.
///////////////////////////////////////////////////////////////////////////////
UINT32 pvg610ChecksumCalc(
                 UINT32     currentChecksum,
                 BYTE      *pBuf,
                 UINT32     len,
                 BOOLEAN    lastCall)
{
    UINT32   ix, tmp, remainder;

    // check if endian conversion
    if (pvg610IsBigEndian())
    {
 //   printEthStringAdd(1,1);
    
    
        // calculate on whole number of DWORDs
        for (ix=0; ix < len / 4; ix++)
        {
            tmp = pvg610EndianConversion((BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
            currentChecksum += tmp;
        }

        // calculate on whatever's left
        remainder = len % 4;
        if (remainder)
        {
            tmp = pvg610EndianConversion(&pBuf[len-remainder], remainder);
            currentChecksum += tmp;
        }

        if (lastCall)
        {
            currentChecksum ^= 0xDEADBEEF;
        }

        currentChecksum = pvg610EndianConversion((BYTE*)&currentChecksum, sizeof(UINT32));
    }
    else
    {
        // calculate on whole number of DWORDs
    //    printEthStringAdd(1,2);

      //     printEthStringAdd(1,len);

        for (ix=0; ix < len / 4; ix++)
        {
            memcpy((BYTE*)&tmp, (BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
            currentChecksum += tmp;
       //      printEthStringAdd(1,tmp);
      //       printEthStringAdd(1,currentChecksum);

        }

        // calculate on whatever's left
        remainder = len % 4;
        if (remainder)
        {
            tmp = 0;
            memcpy((void*)&tmp, &pBuf[len-remainder], remainder);
            currentChecksum += tmp;
        //      printEthStringAdd(1,tmp);
         //        printEthStringAdd(1,currentChecksum);


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
BOOLEAN pvg610IsBigEndian()
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
UINT32 pvg610EndianConversion(BYTE *pBuf, UINT32 size)
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
BYTE pvg610BitCount(UINT32 num)
{
    BYTE count;

    for (count = 0; num != 0; num &= num - 1)
    {
        count++;
    }

    return count;
}


