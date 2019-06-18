/**********************************************************************
* File: test.cpp
* Devices: TMS320F2812, TMS320F2811, TMS320F2810
* Author: Nikitin A.A., LONIIR.
* Description: This function test the External Memory Interface.
* History:
*   25/10/05 - original (based on DSP28 header files v1.00, D. Alter)
**********************************************************************/

#include "test.h"

/**********************************************************************
* Function: test()
*
* Description: Test the external memory interface on the F2812.
**********************************************************************/
//#ifdef __cplusplus
//extern "C" {
//#endif
extern "C" void ResetWD();
unsigned long TestStorage(void)
{
	unsigned long Cnt;
	unsigned int  ReadBack;
	unsigned long Flag; 
	unsigned int* TAddr;
	Flag = 0l;
	TAddr = (unsigned int*)0x100000l;
	unsigned long Volume = 200l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0xff; //16 bit now
	ReadBack = (*TAddr++) & 0xff;
	if (ReadBack != 0xff)
		{
			Flag |= 1l;
		}
	}
	//_____________All Zeros
	TAddr = (unsigned int*)0x100000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0x0000; //16 bit now
	ReadBack = (*TAddr++) & 0xff;
	if (ReadBack != 0x00)
		{
			Flag |= 2l;
		}
	}
//______________All Zeros
//_____________AAAA
	TAddr = (unsigned int*)0x100000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0xAA; //16 bit now
	ReadBack = (*TAddr++) & 0xff;
	if (ReadBack != 0xAA)
		{
			Flag |= 4l;
		}
	}
//______________AAAA
//_____________5555
	TAddr = (unsigned int*)0x100000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0x55; //16 bit now
	ReadBack = (*TAddr++) & 0xff;
	if (ReadBack != 0x55)
		{
			Flag |= 8l;
		}
	}
//______________5555
//______________Volume
	TAddr = (unsigned int*)0x100000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr++ = Cnt; //16 bit now
	}
	TAddr = (unsigned int*)0x100000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{	
	ReadBack =  (*TAddr++) & 0xff;
	if (ReadBack != (Cnt & 0xFF))
		{
			Flag |= 10l;
		}
	}
//______________Volume	
	return Flag;
}
//#ifdef __cplusplus
//}
//#endif

//#ifdef __cplusplus
//extern "C" {
//#endif
//unsigned long Test(void)

#ifdef __cplusplus 
#pragma CODE_SECTION(".const") 
#else
#pragma CODE_SECTION(Test,".const");
#endif
unsigned long Test(void)
{
	unsigned long Volume = 0x80000l;
	unsigned long Cnt;
	unsigned int  ReadBack;
	unsigned long Flag; 
	unsigned int* TAddr;
	Flag = 0l;
	asm(" SETC INTM, DBGM");
//	for(;;) //loop
	{
//____________All Ones
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0xffff; //16 bit now
	ReadBack = *TAddr++;
	ResetWD();
	if (ReadBack != 0xffff)
		{
			Flag |= 1l;
		}
	}
//_____________All Ones
//_____________All Zeros
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0x0000; //16 bit now
	ReadBack = *TAddr++;
	ResetWD();
	if (ReadBack != 0x0000)
		{
			Flag |= 2l;
		}
	}
//______________All Zeros
//_____________AAAA
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0xAAAA; //16 bit now
	ReadBack = *TAddr++;
	ResetWD();
	if (ReadBack != 0xAAAA)
		{
			Flag |= 4l;
		}
	}
//______________AAAA
//_____________5555
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr = 0x5555; //16 bit now
	ReadBack = *TAddr++;
	ResetWD();
	if (ReadBack != 0x5555)
		{
			Flag |= 8l;
		}
	}
//______________5555
//______________Volume
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{
	*TAddr++ = Cnt; //16 bit now
	ResetWD();
	}
	TAddr = (unsigned int*)0x80000l;
	for(Cnt = 0; Cnt < Volume;Cnt++)
	{	
	ReadBack = *TAddr++;
	ResetWD();
	if (ReadBack != (Cnt & 0xFFFF))
		{
			Flag |= 10l;
		}
	}
//______________Volume
}
	return Flag;
} //end of test()

//#ifdef __cplusplus
//}
//#endif
/*** end of file *****************************************************/	
