//expert2.cpp
#include "tcpip.h"
#include "expert.h"
#include "expdata.h"
#include "disp.h"
#include "menu.h"
#include "kbd.h"
#include <stdlib.h>

extern "C" void InsertDynamicValues(void);

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(InitRemote, "ExpertFuncs")
#endif
void InitRemote()
{
 theCntFunc.Operate(19); //load serial port parameters
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(InitBer, "ExpertFuncs")
#endif
void InitBer()
{
#ifndef _LDR
//t  ExpertRegs.XILR2 = 0x1; //zummer on - temporary hier
 MDelay(1000000l);
 ExpertRegs.XILR2 = 0x0; //zummer off - temporary hier
#endif
 InitDisp();
#ifndef _LDR
 UsedExp.LoadDDS(); //first loading - for init
 UsedExp.Set(); //set counting state (start, stop) 
 UsedMenu.Draw();
 UsedMenu.Draw();
// ExpertRegs.XILR2 = 0x0; //zummer off - temporary hier
 VolNumber.Value = 0l;
 ErrNumber.Value = 0l;
#endif
 UsedExp.State.Reg1.bit.Init = 0; //initialize ended
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(memcpy8, "ExpertFuncs")
#endif
extern "C" void memcpy8(char* Rcv, char* Trn, unsigned int vol)
{
	while(vol > 1)
	{
	*Rcv = *Trn++;
//	*Rcv <<= 8;
	 *Rcv++ += (*Trn++ & 0xff) << 8;
//Trn++;
//	 Trn++;
	 vol--;
	 vol--;
	}
	if(vol) //last byte iv vol
	{
	*Rcv = *Trn;
//	*Rcv <<= 8;
	}

}

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(DevisePost, "ExpertFuncs")
#endif
extern "C" void DevisePost()
{
	char* ptmp;
	ptmp = &RData[0];
	while(*ptmp == '+') {
	ptmp++; } 
	switch(IntPort[2] & 0xff)
	{
	case '0':     if(RData[1] == '\0'){ Refresh = ((RData[0]& 0xff) - '0');}
	     else {Refresh = (((RData[0]& 0xff) - '0')* 10) + ((RData[1]& 0xff) - '0');}
 		 break;
	case '1': 
	//	 ClkNumber.ChangingValue = strtol(&RData[0], &ptmp, 0);
	//	 ClkNumber.Value = ClkNumber.ChangingValue;
//		 ScanCnt = UsedMenu.RedrawPeriod;
//		 ClkNumber.RunWebC((float64)strtol(&RData[0], &ptmp, 0));
		 ClkNumber.RunWebC((float64)strtol(ptmp, &ptmp, 0));
	     break;
	case '2':  //if is - it is checked
		 CommandData.Value = 2; //clear 
		 theCntFunc.Operate(1); //run for commanddata
		 break;
	default: ;
	}
}
//Uint16 t1; //for test
//_________end of file