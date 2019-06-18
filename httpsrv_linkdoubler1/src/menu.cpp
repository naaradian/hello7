//menu.cpp
#include "tcpip.h"
#include "menu.h"
#include "disp.h"
#include "kbd.h"
#include "expdata.h"
#include "280x_Boot.h"
#include "DSP281x_DefaultIsr.h"
#include <string.h>
#include <stdlib.h> //for strtod
Uint16 SPIA_Transmit1(Uint16);
void SPIA_Init1(void);
void SPIA_Init2(void);
extern "C" void scia_fifo_init(float, char, char);
//char cInsBers[] = "None 10^-110^-210^-310^-410^-510^-610^-7";

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(GetVal, "ExpertFuncs")
#endif	
extern "C" char* GetVal(char t)
{
static	char Buf[17] = "Test";
 		char* pBuf;
 		pBuf = &Buf[0]; 
 		unsigned int tmp;
 		switch(t)
 		{
 		case 1: 
 		 sprintf(pBuf, BerNumber.pFormat, BerNumber.Value); break;
 		case 2: 
 		 sprintf(pBuf, LossNumber.pFormat, LossNumber.Value); break;
 		case 3: 
 		 sprintf(pBuf, ErrNumber.pFormat, ErrNumber.Value); break;
 		case 4: 
 		 sprintf(pBuf, VolNumber.pFormat, VolNumber.Value); break; 
		case 5: 
 		 sprintf(pBuf, ClkNumber.pFormat, (int32)ClkNumber.Value); break;
		case 6: 
		 sprintf(pBuf, theAnyStrings.c2d, Refresh); break;
  		default:
 		 sprintf(pBuf, BerNumber.pFormat, BerNumber.Value); 
 		}	
//float64 ret = t;
return pBuf;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(AnyStrings::AnyStrings, "ExpertFuncs")
#endif	
extern "C" AnyStrings::AnyStrings()
	{
	//		strcpy(cBerString, "0123456789012345");
		strcpy(cLogoLd,    " IPD v.7.01.230 ");
	//	strcpy(cLogoLd,    "IP:172.16.3.222 ");
#ifdef _WRK		
		strcpy(cConfig,    " Configuration  ");
#else  //_WRK
	    strcpy(cConfig,    "Loader v6.12.13 ");
#endif	//no _WRK	
		strcpy(cGetCom,    " Get The Command");
		strcpy(cEmpty,     "                ");
		strcpy(cCommands,  "StartStop Clear");
		strcpy(cInsBers,   "None 10^-110^-210^-310^-410^-510^-610^-7");
		strcpy(cCommandF,  "%5s");
		strcpy(cCommandP,  "%6s");
		strcpy(cPhase,   "NormalInvert");
		strcpy(c87,   "87");
		strcpy(cNEO,   "NEO");
		strcpy(cInType,  "  LVDS     RS449    TTL    RS449-TTL");
//		strcpy(cPatType, " all ones  all zeros alt 0s 1s1 in 32   1 in 4    2^3-1     2^15-1    2^32-1    ");
//		strcpy(cPatType, " alt 0s 1s  2 in 3    2^3-1     2^15-1 O  2^15-1 M  2^32-1  ");
//		strcpy(cPatType, " alt 0s 1s  2 in 3    2^3-1     2^7-1     2^11-1    2^15-1 O  2^15-1 M  2^32-1  ");
		strcpy(cPatType, " alt 0s 1s  2 in 3    2^3-1     2^4-1     2^7-1     2^9-1     2^11-1    2^15-1 O  2^15-1 M  2^32-1  ");		
		strcpy(cmes0,      "   THIS VALUE   ");
		strcpy(cmes1,      "  IS NOT ALLOWED");
		strcpy(cVolume,    "%.4LE");
		strcpy(cVCC18,    "%.2Lf");
		strcpy(cBits,      "Bits:           ");
		strcpy(cmRemote,   "R:       B:  P: ");
		strcpy(cRemote,    "     Remote     ");
		strcpy(cBer,       "BER:            ");
		strcpy(cErr,       "Err:            ");
		strcpy(cLoss,      "Loss:           ");
		strcpy(cLoop,      "   Loop:        ");
		strcpy(cClocks,    "     Clocks     ");
		strcpy(cTest,      "      Test      ");
		strcpy(cInterface, "   Interface    ");
		strcpy(cMonitoring,"   Monitoring   ");	
		strcpy(cMonitoringVCC18,"VCC 1,8V:       ");	
		strcpy(cmInType,   "Interface Type  ");
		strcpy(cmPatType,  " Pattern  Type  ");
		strcpy(cmSynce,    "     Synce      ");
		strcpy(cmAutoSynce,"Autoresync:     ");
		strcpy(cOffOn,	   "OffOn ");
		strcpy(cRt       , "    RT:         ");
		strcpy(cRd       , "    RD:         ");
		strcpy(cTt       , "    TT:         ");
		strcpy(cSd       , "    SD:         ");
		strcpy(cmTiming  , " Mode:          ");
		strcpy(cTiming  , "Slave Master");
		strcpy(cInsBer,    "Inserted:       ");
		strcpy(cTrClocks,  " Transmit Clocks");	
		strcpy(cHz,        "              Hz");	
		strcpy(cFclkf,     "%11.1f");	
		strcpy(cFclk,      "%8ld");	
		strcpy(cRem,      "%6ld");	
		strcpy(cRemVol,	   "B2");
		strcpy(cRemErr,	   "B3");
		strcpy(cRemBer,	   "B1");
		strcpy(cRemLoss,   "B5");	
		strcpy(cRemLEDData,"B7");	
		strcpy(cRemCom,	   "N0");
		strcpy(cRemIns,	   "a07");
		strcpy(cRemSynce,  "a04");
		strcpy(cRemLoop,   "a05");
		strcpy(cRemClk,	   "C0");
		strcpy(cRemRem,	   "a16");
		strcpy(cRemBits,   "a17");
		strcpy(cRemParity, "a18");
		strcpy(cRemVCC18,  "a19");
		strcpy(cRemPolRt,  "a10");	
		strcpy(cRemPolRd,  "a13");
		strcpy(cRemPolTt,  "a14");
		strcpy(cRemPolSd,  "a15");
		strcpy(cRemTiming,  "a00");
		strcpy(cRemInType, "a09");
		strcpy(cRemPatType, "a08");
		strcpy(cRazd,	   ";");
		strcpy(c1d,		   "%1d");
		strcpy(c1X,		   "%1X");
		strcpy(c2X,		   "%02X");
		strcpy(c2d,		   "%2d");
		strcpy(cPoint,	   ".");
		strcpy(c8d,		   "%8ld");		
		strcpy(cK0,		   "K0");	
		strcpy(cK1,		   "K1");	
//		strcpy(c10s,	   "%10s");
		strcpy(cs,	   	   "%s");
		strcpy(c4X,	   	   "%4lX");
		strcpy(cRemSpi,	   "D0");
		strcpy(cRemSpiCs,	   "D1");
	}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(CntFunc::CntFunc, "ExpertFuncs")
#endif	
extern "C" CntFunc::CntFunc()
{
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(CntFunc::Control, "ExtFuncs")
#endif	
extern "C" Uint16 CntFunc::Control(Uint16 sel, float64 CValue)
{
	if (UsedExp.State.Reg1.bit.Init) return 1; //not check if init not ended
	switch(sel)
	{
	case 1:  if (CValue < 3l) {return 1;} else {return 0;} break;//For CommandData
	case 2:  return 1; break;//For VolNumber
	case 3:  return 1; break;//For ErrNumber	
	case 4:  return 1; break;//For BerNumber	
	case 5:  return 1; break;//For LossNumber	
	case 6:  //if ((Value <= 40000000l) && (Value >= 600l)){return 1;}
			if((!InType.Value) ||(InType.Value == 2) &&  //lvds or ttl
			(CValue <= 55000000l) && (CValue >= 600l)) {return 1;}
		    else if((CValue <= 10000000l) && (CValue >= 600l)) {return 1;} //rs449
		    else {return 0;} break;
		        //For ClkNumber	
	case 7:  return 1; break;//For InsBer	
	case 8:  return 1; break;//For SpiData
	case 11: if((!CValue) ||(CValue == 2) &&  //lvds or ttl
			(ClkNumber.Value <= 55000000l) && (ClkNumber.Value >= 600l)) {return 1;}
		    else if((ClkNumber.Value <= 10000000l) && (ClkNumber.Value >= 600l)) {return 1;} //rs449
		    else {return 0;} 	break;
	case 19: if((CValue <= 115200l) && (CValue >= 300l)) {return 1;}	
	    	 else {return 0;} break;
	default: return 1;
	}
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(CntFunc::Operate, "ExtFuncs")
#endif	
extern "C" void CntFunc::Operate(Uint16 sel)
{
	Uint16 tmp;
	switch(sel)
	{
	case 1: UsedExp.Set(); 
	 	    break; //For CommandItem
	case 2:// VolNumber.Value += 12345; break;//temporary//t060309
		 	//VolNumber.Value += UsedExp.GetBits();
		 	UsedExp.GetData(); break;
	case 3:// ErrNumber.Value += UsedExp.GetErrors();//t060309
			UsedExp.GetData(); break;
	//		ErrNumber.Value += 3; break;//t060309
	case 4: //for test
		//	for(;;)
		//	{BerNumber.Value = 0x55;}
			//for test
			if(VolNumber.Value){
			BerNumber.Value = 
			ErrNumber.Value / VolNumber.Value; }
			else{
			BerNumber.Value = 0l;}
			break;//temporary
	case 5: LossNumber.Value += 0; break;//temporary
	case 6: UsedExp.State.Reg2.bit.LDDS = 1; //load dds
			UsedExp.State.Reg2.bit.XILR1 = 1; //load ireg1
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;
	case 7:	UsedExp.State.Reg2.bit.LDs2174	= 1; //need load ds2174
			UsedExp.State.Reg2.bit.LED = 1;
			UsedExp.State.Reg2.bit.Some = 1; // need some load
			break;//temporary For ClkNumber	
	case 8:	 //spidata
			tmp = SPIA_Transmit1((Uint16)SpiData.Value);
			SpiData.ChangingValue = (float64)tmp;
			SpiData.Value = (float64)tmp;
			break;//temporary For ClkNumber			
	case 9:	 //spics
		    if(!SpiCs.Value) //stop counter to boot old programm
		    {
		    UsedExp.State.Reg2.bit.DcrBoot =0;
			}		  
			else if(SpiCs.Value == 1l)//1 => =>init + cs -on
			{
			UsedExp.State.Reg1.bit.CsSpi = 1;
			SPIA_Init1();
			}
			else if(SpiCs.Value == 2l)//1 => cs on
			{
			 UsedExp.State.Reg1.bit.CsSpi = 1;
			 GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;
			}
			else if(SpiCs.Value == 3l)//1 => cs off
			{
			 GpioDataRegs.GPFSET.bit.GPIOF3 = 1; 
			 UsedExp.State.Reg1.bit.CsSpi = 0;
			}
			else if(SpiCs.Value == 4) //start counter to boot old programm
		    {
		    UsedExp.State.Reg2.bit.DcrBoot = 1;
			}
			else if(SpiCs.Value == 5)	
			{
			EALLOW;
			SysCtrlRegs.SCSR = 0x0001;//enable wd reset and setting wd en
		//	SysCtrlRegs.WDCR = 0x0028;
		//	SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
   		//	SysCtrlRegs.WDKEY = 0xAA;
			SysCtrlRegs.WDCR = 0x0038; // immediatly reset: wdchk not "101" and wd enable
			EDIS;
			}
			else if(SpiCs.Value == 6)	//set progmode
			{
					UsedExp.State.Reg1.bit.ProgMode = 1;
					UsedExp.State.Reg1.bit.CsSpi = 1; 
 					GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;
 					ProgModeTimeOut = ProgModeTime;
				//	SPIA_Init1();
					SPIA_Init2();//high baud rate
					PieCtrlRegs.PIECRTL.bit.ENPIE = 0; //disable interrupts
					State = 0l; //programm state mashine to zero	
					bytecnt = 0;//byte counter to zero	
						Message("   Prog Mode", "     Is On");
			}
			break;//temporary For ClkNumber	
case 10:	UsedExp.State.Reg2.bit.XILR0 = 1; //rt
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;
case 11:	UsedExp.State.Reg2.bit.XILR1 = 1; //interface type
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;
case 12:	UsedExp.State.Reg2.bit.LDs2174 = 1; //pattern type
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;			
case 13:	UsedExp.State.Reg2.bit.XILR0 = 1; //timing
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;
case 14:	UsedExp.State.Reg2.bit.LDs2174 = 1; //synce
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;	
case 15:	UsedExp.State.Reg2.bit.LDs2174	= 1; //loop :need load ds2174
			UsedExp.State.Reg2.bit.LED = 1;
			UsedExp.State.Reg2.bit.Some = 1; // need some load	
			break;	
case 16:	UsedExp.State.Reg2.bit.XILR0 = 1; //rd
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;	
case 17:
		//	UsedExp.State.Reg2.bit.LDs2174 = 1; //tt
			UsedExp.State.Reg2.bit.XILR0 = 1; //tt
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;		
case 18:	UsedExp.State.Reg2.bit.XILR0 = 1; //sd
			UsedExp.State.Reg2.bit.Some = 1; //some load
			break;
case 19:
case 20:
case 21:
			scia_fifo_init(RemNumber.Value, RemBits.Value, RemParity.Value);
			break;			
case 22://	VCC18Number.Value = float64(1.81);											
			VCC18Number.Value = (float64(ADC_buf[0])*3l)/4095l;											
																														
default:	break;
	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(CntFunc::Remote, "ExtFuncs")
#endif	
extern "C" void CntFunc::Remote(Uint16 sel, char *pDCmd, char RCntNum)
{
//	float64 tmp;
//	char * end;
	switch(sel)
	{
	case 1: 
    	/*
		//	tmp = strtod(pDCmd, &end);
			tmp = strtod(pDCmd, &end);
			if(Control(RCntNum, tmp))
			{
			CommandData.ChangingValue =  tmp;
			CommandData.Value =  tmp;
			UsedMenu.WriteStorageV(CommandData.StorageAddr,(&CommandData.Value));
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
			UsedMenu.DrawMessage(CommandData.pMes0,CommandData.pMes1);
			}
			*/
			break; //For CommandItem
	case 2:  break;//temporary VolNumber
	case 3:  break;//temporary ErrNumber
	case 4:  break;//temporary BerNumber
	case 5:  break;//temporary LossNumber
	case 6:  /*
			 tmp = strtol(pDCmd, &end, 10);
			 if(Control(RCntNum, tmp))
			 {
			 ClkNumber.ChangingValue =  tmp;
			 ClkNumber.Value =  tmp;
			 UsedMenu.WriteStorageC(ClkNumber.StorageAddr,ClkNumber.Value);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else
			 {
			 UsedMenu.DrawMessage(ClkNumber.pMes0,ClkNumber.pMes1);
			 } */
	  	     break;//temporary For ClkNumber
	case 7:	 //insBerData 	     
	case 8:  //spidata  	     		
	default: break;
	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(MData::MData, "ExpertFuncs")
#endif	
extern "C" MData::MData()
{
 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataV::RunRemoteV, "ExtFuncs")
#endif	
extern "C" void MDataV::RunRemoteV(char * pCommand)
{
//volatile char tmp = 0; 
unsigned long tmpd;
char * end;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		UsedRemote.IdCommand = 1; //right command
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(UsedRemote.pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
		sprintf(UsedRemote.pTBuff, pRemFormat, Value);
		for(int16 i = RemChars; i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}		
//		UsedRemote.pTBuff += RemChars;
 //add;
//		 		tmp = 1;
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
//________________________________________

		tmpd = strtol(pCommand, &end, 16);
		//t	if(pControl->Control(CntNum, tmpd))
		   if(tmpd < Quantity)
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			UsedMenu.WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
			UsedMenu.DrawMessage(pMes0, pMes1);
			}
		
//________________________________________				
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(UsedRemote.pTBuff, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(int16 i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
		}
		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd);	

	//read parameters, check its and run commmmand or read data 
	}
//char ret = 0;
 //if commnd compared ret = 1;
 //return ret;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::RunWebC, "ExtFuncs")
#endif	
extern "C" void MDataC::RunWebC(float64 Val)
{
	if(Val)	{
	 if(theCntFunc.Control(CntNum, Val))
	 {	 	ChangingValue = Val;
		Value = Val;
//		UsedMenu.WriteStorageC(StorageAddr,(volatile char *)&Value);
	    UsedMenu.WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(OprNum);	 
	 	UsedMenu.Draw();//!!!! hier is redraw menu!
	 }
	 else
	 {
		UsedMenu.DrawMessage(pMes0,pMes1);
	 }
	}
}


#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::RunRemoteC, "ExtFuncs")
#endif	
extern "C" void MDataC::RunRemoteC(char * pCommand, char SysS)
{
float64 tmpl;
char * end;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		UsedRemote.IdCommand = 1; //right command
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(UsedRemote.pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
		Uint32 tmp = Value;
		sprintf(UsedRemote.pTBuff, pRemFormat, tmp);
		for(int16 i = RemChars; i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}		
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		//_____________________________	
		tmpl = (float64)strtol(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
			 ChangingValue =  tmpl;
			 Value =  tmpl;
			 UsedMenu.WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else
			 {
			 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
		//_____________________________
		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(UsedRemote.pTBuff, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(int16 i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
		}
		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd);	
	}
	//r
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataI::RunRemoteI, "ExtFuncs")
#endif	
extern "C" void MDataI::RunRemoteI(char * pCommand)
{
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		char *tmp;
		tmp =  UsedRemote.pTBuff;
		UsedRemote.IdCommand = 1; //right command
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(UsedRemote.pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
	//	UsedRemote.pTBuff++;//t
	//	UsedRemote.pTBuff++;//t
	
		sprintf(UsedRemote.pTBuff, pRemFormat, Value);
	//	UsedRemote.pTBuff++;
		for(int16 i = RemChars; i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}	
			
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}	
		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(UsedRemote.pTBuff, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(int16 i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
	}
		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd);	
}
	//r
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::WriteStorageC, "ExtFuncs")
#endif	
//extern "C" void Menu::WriteStorageC(volatile char * pWAddr, float64 * pWValf)
extern "C" void Menu::WriteStorageC(volatile char * pWAddr,
float64 ftmp)
// volatile char * ptmp)
{	
//	int32 WVal = WValf;
	 //rom is 8 -bits need write to bytes
	 /*
	*pWAddr++ = WVal >> 24;
	*pWAddr++ = WVal >> 16;
	*pWAddr++ = WVal >> 8;	
	*pWAddr++ = WVal;
	WVal = WValf;
	*pWAddr++ = WVal >> 24;
	*pWAddr++ = WVal >> 16;
	*pWAddr++ = WVal >> 8;	
	*pWAddr++ = WVal;	
	*/
//	void *ptmp;
//	ptmp = pWValf;
//	 char * ptmp1;
//	ptmp1 = (char *)ptmp;
	unsigned long lsb = ftmp;
	unsigned long msb = ftmp / 0xffffffffl;
//	for (int i = 0; i <= 3; i++)
//	{
	/*
//t		*pWAddr++ = *pWValf++;
		*pWAddr = (*ptmp);
		*pWAddr++;
		*pWAddr = ((*ptmp) >> 8); //go next 2 bytes
		*pWAddr++;
		*ptmp++;
//	    pWValf += 1l;
//	*pWAddr++ = *ptmp++;
*/
	
		
		
		
		
		
	
		*pWAddr = ((msb) >> 24); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((msb) >> 16); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((msb) >> 8); //go next 2 bytes
		*pWAddr++;
		*pWAddr = msb;
		*pWAddr++;
		*pWAddr = ((lsb) >> 24); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((lsb) >> 16); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((lsb) >> 8); //go next 2 bytes
		*pWAddr++;
		*pWAddr = lsb;
//		*pWAddr++;
//	}
}

//#ifdef __cplusplus
//#pragma CODE_SECTION("ExpertFuncs")
//#else
//#pragma CODE_SECTION(Menu::ReadStorageC, "ExpertFuncs")
//#endif	
//extern "C" int32 Menu::ReadStorageC(volatile char * pRAddr)
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::ReadStorageC, "ExtFuncs")
#endif	
extern "C" float64 * Menu::ReadStorageC(volatile char * pRAddr)
//extern "C" int32 ReadStorageC(char * pRAddr)
{	
static float64 RVal = 0;
	unsigned long lsb; 
	unsigned long msb;
//Uint16 test;
//Uint16 * ptest;
//ptest =&test;
float64 *pret;
	pret = & RVal;
//	volatile char *ptmp;
//	ptmp = (volatile char*)pret;
//int32 RVal;
//for(int i = 0; i <= 7; i++)
//{
//	pRAddr++;
//}
//	pRAddr += 8; //from higher address
/*
	for(int i = 0; i <= 3; i++)
	{
	test = *pRAddr++ & 0xff;
//	test <<= 8;
	test += ((*pRAddr++ & 0xff) << 8);
	*ptmp++ = test;
	
//	test = *pRAddr & 0xff;
//	*ptmp++ += (*pRAddr++) & 0xff;
//	*ptmp <<= 8;
	}
	*/
//for 8-bits rom, need read to Bytes

	msb = (*pRAddr & 0xff);
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);	
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);
	pRAddr++;	
//	ret += RVal;
	lsb = (*pRAddr & 0xff);
	pRAddr++;
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);
	pRAddr++;	
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);
	pRAddr++;
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);	
//	ret += RVal;	
//		pret = & ret;
	RVal = (msb * 0xffffffffl) + lsb;
return pret;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::WriteStorageV, "ExtFuncs")
#endif	
extern "C" void Menu::WriteStorageV(volatile char * pWAddr, volatile char* WVal)
{	
//*WVal++; //to keep lover byte
*pWAddr = (*WVal) & 0xff;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::ReadStorageV, "ExtFuncs")
#endif	
extern "C"  char* Menu::ReadStorageV(volatile char * pRAddr)
{	
static char RVal;
//	RVal = *pRAddr & 0xff;
static char* pRVal;
	pRVal = &RVal;
	RVal = *pRAddr & 0xff;
	return pRVal;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataV::MakeResultStrV, "ExtFuncs")
#endif	
extern "C" void MDataV::MakeResultStrV()
{	
char * pWorkPointer;
	pWorkPointer = pVariants; //begin from string of variants
int16 CharCnt;
int16 tmp;
	tmp = (int16)ChangingValue;
	tmp *= (int16)CharsInOne;
	for(CharCnt = 0; CharCnt < tmp; CharCnt++)
	{ pWorkPointer++;}
	strncpy(pResultStr, pWorkPointer, CharsInOne);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataV::DrawMDataV, "ExtFuncs")
#endif	
extern "C" void MDataV::DrawMDataV()
{	
	MakeResultStrV();
 	gotoxy(XPos, YPos);
//	cprintf(pFormat, pResultStr);
	cprintf(theAnyStrings.cs, pResultStr);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(MDataI::MDataI, "ExpertFuncs")
#endif	
 extern "C" MDataI::MDataI(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        CntFunc * SetpControl,
                        Uint16 SetOprNum,
                        char *SetpRemote
                        ,char * SetpRemFormat, char SetRemChars
                        ,char SetRemNum, char SetCntNum
                        )
{
	pResultStr = &ResultStr[0]; //set to start
	pFormat = pSetFormat;
	XPos = SetXPos;
 	YPos = SetYPos;
 	pControl = SetpControl;
  	OprNum = SetOprNum; 
  	Value = 0;	
  	pRemote = SetpRemote;
 	pRemFormat = SetpRemFormat;
 	RemChars = SetRemChars; 
 	RemNum = SetRemNum; 
 	CntNum = SetCntNum;	
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataI::MakeResultStrI, "ExtFuncs")
#endif	
extern "C" void MDataI::MakeResultStrI()
{	
	sprintf(pResultStr, pFormat, Value);

}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataI::DrawMDataI, "ExtFuncs")
#endif	
extern "C" void MDataI::DrawMDataI()
{	
	MakeResultStrI();
 	gotoxy(XPos, YPos);
//	cprintf(pFormat, pResultStr);
//	cprintf("%s", pResultStr);
//	cprintf(theAnyStrings.c10s, pResultStr);
	cprintf(theAnyStrings.cs, pResultStr);
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(MDataV::MDataV, "ExpertFuncs")
#endif	
extern "C" MDataV::MDataV(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        char SetChangable, 
//                        Uint16 SetStorageAddr,
                        volatile char* SetStorageAddr,
                        char* pSetVariants, char SetValue,
                        char SetCharsInOne, char SetQuantity,
                        CntFunc * SetpControl, Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                        char *SetpMes0, char *SetpMes1, char* SetpRemote
                        ,char * SetpRemFormat, char SetRemChars 
                        ,char SetRemNum
                        )
{
// pItemActive = pSetItem;	
 pFormat = pSetFormat;
 XPos = SetXPos;
 YPos = SetYPos;
 Changable = SetChangable;
 StorageAddr = SetStorageAddr;
 pVariants = pSetVariants;
 char *pSetValue;
// pSetValue = &SetValue;
 Value = 0;
 ChangingValue = 0;
 if(GetKey() != Enter)//temporary Esc, need Enter
 {
  pSetValue = UsedMenu.ReadStorageV(SetStorageAddr);
 }
 Value += (*pSetValue);
 ChangingValue += (*pSetValue);
 if(Value >= SetQuantity) //bad storage
 {
  Value = 0;
  ChangingValue = 0;
  pSetValue = &SetValue;
  Value += (*pSetValue);
  ChangingValue += (*pSetValue);
  UsedMenu.WriteStorageV(SetStorageAddr, (volatile char*)Value);
 }
 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 Quantity = SetQuantity;
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 pMes0 = SetpMes0;
 pMes1 = SetpMes1;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars;
 RemNum = SetRemNum;
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::MakeResultStrC, "ExtFuncs")
#endif	
extern "C" void MDataC::MakeResultStrC()
{	
//t	sprintf(pResultStr, pFormat, Value);
//	float32 tmp = Value;
//	int32 tmp = Value;
//	char RM[17];
//	char * pR;
//	pR = &RM[0];
	if(!DgAftPnt) //not have point
	{
	int32 tmp = ChangingValue;	
	sprintf(pResultStr, pFormat, tmp);
	}
	else
	{
//	float32 tmp = Value;
	sprintf(pResultStr, pFormat, ChangingValue);
	}
//this work	sprintf(pResultStrC, pFormat, 5678);
//	sprintf(pResultStr, pFormat, tmp);
//	sprintf(pR, pFormat, 5678);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::DrawMDataC, "ExtFuncs")
#endif	
extern "C" void MDataC::DrawMDataC()
{	

	MakeResultStrC();
 	gotoxy(XPos, YPos);
//	cprintf(pFormat, pResultStr);
	cprintf(theAnyStrings.cs, pResultStr);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::LastDigit, "ExtFuncs")
#endif	
extern "C" char MDataC::LastDigit()
{	
	char ret;
//	ret = 1 + CurXPos; 
//	ret -= CharsInOne;
//	ret -= XPos;
	ret = CharsInOne;
	ret += XPos;
	ret -= CurXPos;
	ret--;
	
	return ret;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(MDataC::Delta, "ExtFuncs")
#endif	
//extern "C" int32 MDataC::Delta(char Key)
extern "C" float64 MDataC::Delta(char Key)
{	
	float64 RetValue;
//	int32 RetValue;// = 1;
	float32 CurDig; //value of  digit on cursor
	float32 tmpDig;	
	int16 i;
	int16 Weight; //what positon from right border of Value?
//	char Weight1;
//	Weight = this->CharsInOne - (this->CurXPos - this->XPos) - 1;  //stepen of 10 or 16 for this value if it is integer
//	Weight = CharsInOne;//t
	Weight = (int16)(this->CharsInOne); 
	Weight = Weight + (int16)(this->XPos);
	Weight = Weight - 1;
	Weight = Weight - (int16)(this->CurXPos);
//	Weight1 = Weight - 1;
//	RetValue = Weight;//t
	RetValue = 1;
//	Weight = Weight -1;
//	Weight += this->XPos;
//	i = Weight;
	if(!(HexOrDec)) //Decimal
	{
		for(i = Weight; i > 0; i--)
		{
		RetValue *= 10;
  		}
	}
	else //HexDecimal
	{
		for(i = Weight; i > 0; i--)
		{
		RetValue *= 16;
		}	
	}
	if(DgAftPnt) //only for decimal
	{
		for(i = DgAftPnt; i > 0; i--) //
		{
		RetValue /= 10;
		}	
	}
	int32 iRet = (int32)RetValue;
	int32 iChVal = (int32)ChangingValue;
	int32 iCurDig;
	int32 iCurDig1;
	int32 iCurDig2;
	iCurDig = iChVal / iRet;
	iCurDig1 = iCurDig;	
//	CurDig = ChangingValue;
//	CurDig = CurDig / RetValue;
		if(HexOrDec == 0)//decimal
		{

		iCurDig = iCurDig / 10l;
		iCurDig = iCurDig * 10l;
		iCurDig2 = iCurDig1 - iCurDig;
//			tmpDig = CurDig / 10;
//			if(tmpDig < 1) {tmpDig == 0;}	//for float type
//			tmpDig = tmpDig * 10;
//			CurDig = CurDig - tmpDig;
			if(Key == Up)
			{
				if (iCurDig2 == 9) 
		 		{
		 		RetValue *= (-9);
		 		}
		 	}
		 	else //Down
		 	{
				if (iCurDig2 == 0) 
		 		{
		 		RetValue *= (-9);
		 		}		 	
		 	}	
		}
		else //hexdecimal
		{
//			CurDig = (ChangingValue / RetValue) % 0xf;
	//		tmpDig = CurDig / 0xf;
	//		if(tmpDig < 1) tmpDig == 0;	//for float type
	//		tmpDig = tmpDig * 0xf;
	//		CurDig = CurDig - tmpDig;	
//			iCurDig = iCurDig % 0xf;
		iCurDig = iCurDig / 0xfl;
		iCurDig = iCurDig * 0xfl;
		iCurDig2 = iCurDig1 - iCurDig;	
			if(Key == Up)
			{		
				if (iCurDig2 == 0xf) 
		 		{
		 		RetValue *= (-0xf);
		 		}	
		 	}
		 	else //Key == Down
		 	{
				if (iCurDig2 == 0) 
		 		{
		 		RetValue *= (-0xf);
		 		}			 	
		 	}	
		}  

	// hier need compare current value widch next 
	//after adding value and if 
	//after adding digit value is more as maximum digit need get minus value
//	RetValue = 1l; //to test
	return RetValue;
//treturn 1;
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(MDataC::MDataC, "ExpertFuncs")
#endif	
extern "C" MDataC::MDataC(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        char SetChangable, 
                        volatile char* SetStorageAddr,
 //                       char* pSetVariants,
                       // signed long SetValue,
  //                       char SetValue,
                        char SetCharsInOne,
 //                       char SetQuantity,
                        CntFunc * SetpControl,
                        Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                        char *SetpMes0, char *SetpMes1,
                      //  char SetHaveSign, 
                        char SetDgAftPnt,
                        char SetHexOrDec//,
                     //   ,int32 SetValue
                     ,float64 SetValue, char* SetpRemote
                     ,char * SetpRemFormat, char SetRemChars
                        ,char SetRemNum                     
                      //  char
                   //     unsigned long
                     //    SetValue
                        )
{
// pItemActive = pSetItem;	
//char SetValue = 123;
 //float64 tmpValue;
 float64* pSetValue; 
 pSetValue = &SetValue;
 pFormat = pSetFormat;
 XPos = SetXPos;
 CurXPos = SetXPos; 
 YPos = SetYPos;
 Changable = SetChangable;
 StorageAddr = SetStorageAddr;
 Value = 0l;
 ChangingValue = 0l;
 if(GetKey() != Enter)//temporary Esc, need Enter
 {
// Value = UsedMenu.ReadStorageC(SetStorageAddr);
//  SetValue = ReadStorageC(StorageAddr);
//t	SetValue = UsedMenu.ReadStorageC(SetStorageAddr);
	pSetValue = UsedMenu.ReadStorageC(SetStorageAddr);
//	SetValue = *ptmpValue;
 // Value = (float64)tmpValue;//t
 }
  Value += *pSetValue;//t
//t Value = SetValue; //to test temporary without storage
  ChangingValue += *pSetValue;
//need control 

 if(!(theCntFunc.Control(SetCntNum, Value))) //bad value in storage
 {
 	 pSetValue = &SetValue;
 	 Value = 0l;
 	 ChangingValue = 0l;
 	 Value += *pSetValue;//t
	 ChangingValue += *pSetValue;
	 UsedMenu.WriteStorageC(SetStorageAddr,Value);
 }
 
 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
// Quantity = SetQuantity;
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 pMes0 = SetpMes0;
 pMes1 = SetpMes1;
// HaveSign = SetHaveSign;
 DgAftPnt = SetDgAftPnt;
 HexOrDec = SetHexOrDec;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars; 
 RemNum = SetRemNum;
}

		 
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ErrorMessage, "ExtFuncs")
#endif
extern "C" void ErrorMessage()
{

}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(SetCursor, "ExtFuncs")
#endif	
extern "C" void Item::SetCursor()
	{
	/*
	gotoxy(1, 1);
	cprintf("%s", line0);
	gotoxy(1, 2);
	cprintf("%s", line1);	
	if(pDataP0) pDataP0->DrawMDataV();
	if(pDataP1) pDataP1->DrawMDataV();
	if(pDataP2) pDataP2->DrawMDataV();
	if(pDataC0) pDataC0->DrawMDataC();
	*/
		if (UsedMenu.MenuState.DataC0Changing)
		{
			gotoxy(pDataC0->CurXPos,pDataC0->YPos);
		}
		else if(UsedMenu.MenuState.DataP0Changing)
		{
			gotoxy(pDataP0->XPos,pDataP0->YPos);
		}
		else if(UsedMenu.MenuState.DataP1Changing)
		{
			gotoxy(pDataP1->XPos,pDataP1->YPos);	
		}
		else if(UsedMenu.MenuState.DataP2Changing)
		{
			gotoxy(pDataP2->XPos,pDataP2->YPos);	
		}
		
	}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(DrawItem, "ExtFuncs")
#endif	
extern "C" void Item::DrawItem()
	{
	gotoxy(1, 1);
	cprintf("%s", line0);
	gotoxy(1, 2);
	cprintf("%s", line1);
	if(pDataI0){ pDataI0->DrawMDataI(); gotoxy(pDataI0->XPos, pDataI0->YPos);}
	if(pDataI1){ pDataI1->DrawMDataI(); gotoxy(pDataI1->XPos, pDataI0->YPos);}
	if(pDataP0){ pDataP0->DrawMDataV(); gotoxy(pDataP0->XPos, pDataP0->YPos);}
	if(pDataP1){ pDataP1->DrawMDataV(); gotoxy(pDataP1->XPos, pDataP1->YPos);}
	if(pDataP2){ pDataP2->DrawMDataV(); gotoxy(pDataP2->XPos, pDataP2->YPos);} //go to p0 to start from p0 data
	if(pDataC0){ pDataC0->DrawMDataC(); gotoxy(pDataC0->XPos, pDataC0->YPos);}
	
	SetCursor(); //correctly set cursor
	}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(Item::Item, "ExpertFuncs")
#endif	
extern "C" Item::Item(char* l0, char* l1, 
		char v,Item* SetLeft,
 Item* SetRight, Item* SetUp, Item* SetDown,
 MDataV * SetpDataP0, MDataV * SetpDataP1, MDataV * SetpDataP2,
 MDataI* SetpDataI0, MDataI* SetpDataI1,
 MDataC* SetpDataC0)
// CntFunc * SetpControl, Uint16 SetCntNum,
// char * Setpmes0, char * Setpmes1)
 //void * SetpControl)
	{
//	char *p;
//	p = &line0[0];
//	strcpy(p, l0);
//	p = &line1[0];
//	strcpy(p, l1);
	line0 = l0;
	line1 = l1;
	visibled = v;	
	pItemLeft = SetLeft;
	pItemRight = SetRight;
	pItemUp = SetUp;
	pItemDown = SetDown;
	pDataP0 = SetpDataP0;
	pDataP1 = SetpDataP1;	
	pDataP2 = SetpDataP2;	
	pDataI0 = SetpDataI0;
	pDataI1 = SetpDataI1;
	pDataC0 = SetpDataC0;
//	pControl = SetpControl;
//	CntNum = SetCntNum;
//	pmes0 = Setpmes0;
//	pmes1 = Setpmes1;
	}	
/*	
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(Item::InitItem, "ExpertFuncs")
#endif	
extern "C" void Item::InitItem(Item* SetLeft, Item* SetRight, Item* SetUp, Item* SetDown)	
{
	pItemLeft = SetLeft;
	pItemRight = SetRight;
	pItemUp = SetUp;
	pItemDown = SetDown;
}	
*/

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::StartChanging, "ExtFuncs")
#endif
extern "C" void Menu::StartChanging()
{
	CurrentItem->DrawItem(); //to get off messages
	if(CurrentItem->pDataP0)
	{
	if(CurrentItem->pDataP0->Changable)
	 {
	 gotoxy(CurrentItem->pDataP0->XPos,CurrentItem->pDataP0->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP0Changing = 1;
	 }
	}
	else if(CurrentItem->pDataP1)
	{
	if(CurrentItem->pDataP1->Changable)
	 {
	 gotoxy(CurrentItem->pDataP1->XPos,CurrentItem->pDataP1->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP1Changing = 1;
	 }
	}
	else if(CurrentItem->pDataP2)
	{
	if(CurrentItem->pDataP2->Changable)
	 {
	 gotoxy(CurrentItem->pDataP2->XPos,CurrentItem->pDataP2->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP2Changing = 1;
	 }
	}
	else if(CurrentItem->pDataC0)
	{
	 if(CurrentItem->pDataC0->Changable)
	 {
	 gotoxy(CurrentItem->pDataC0->XPos,CurrentItem->pDataC0->YPos);
	 _setcursortype(1); //blink on
 	  MenuState.DataChanging = 1;	 
 	  MenuState.DataC0Changing = 1;
	 }
	}		
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::DrawMessage, "ExtFuncs")
#endif
extern "C" void Menu::DrawMessage(char * mline0, char * mline1)
{
	UsedExp.State.Reg1.bit.Frozen = 0; //unfrozen display
	gotoxy(1, 1);
	cprintf("%s", &theAnyStrings.cEmpty);
	gotoxy(1, 2);
	cprintf("%s", &theAnyStrings.cEmpty);
	gotoxy(1, 1);
	cprintf("%s", mline0);
	gotoxy(1, 2);
	cprintf("%s", mline1);
	UsedExp.State.Reg1.bit.Frozen = 1; //frozen display
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::StopChanging, "ExtFuncs")
#endif
extern "C" void Menu::StopChanging()
{
//need keep data value to ROM
//need load parameters to registers
//t if (CurrentItem->pControl->Control(CurrentItem->CntNum))
//if (1) //to test
// {
	if(CurrentItem->pDataP0)
	{
	 if(CurrentItem->pDataP0->pControl->
	 Control(CurrentItem->pDataP0->CntNum, 
	 CurrentItem->pDataP0->ChangingValue))
	 {
	 CurrentItem->pDataP0->Value = CurrentItem->pDataP0->ChangingValue;
	 WriteStorageV(CurrentItem->pDataP0->StorageAddr, (volatile char*)&CurrentItem->pDataP0->Value);
	 CurrentItem->pDataP0->pControl->Operate(CurrentItem->pDataP0->OprNum);
//to test
/*
	char tmp;
	char *ptmp;
//	ptmp = &tmp;
 	ptmp = ReadStorageV(CurrentItem->pDataP0->StorageAddr);	 
	char tmp1 = 0;
	tmp1 += (*ptmp);
	tmp = *ptmp;
	*/
	 }
	 else
	 {
	 CurrentItem->pDataP0->ChangingValue = CurrentItem->pDataP0->Value;
	 DrawMessage(CurrentItem->pDataP0->pMes0, 
				CurrentItem->pDataP0->pMes1);
	 }
	}

	if(CurrentItem->pDataP1)
	{
	 if(CurrentItem->pDataP1->pControl->
	 Control(CurrentItem->pDataP1->CntNum,
	 CurrentItem->pDataP1->ChangingValue))
	 {
	 CurrentItem->pDataP1->Value = CurrentItem->pDataP1->ChangingValue;
	 WriteStorageV(CurrentItem->pDataP1->StorageAddr, (volatile char*)&CurrentItem->pDataP1->Value);
	 CurrentItem->pDataP1->pControl->Operate(CurrentItem->pDataP1->OprNum);	 
	 }
	 else
	 {
		CurrentItem->pDataP1->ChangingValue = CurrentItem->pDataP1->Value;
//t		DrawMessage(CurrentItem->pmes0, CurrentItem->pmes1);
		DrawMessage(CurrentItem->pDataP1->pMes0, 
				CurrentItem->pDataP1->pMes1);
	 }
	}	

	if(CurrentItem->pDataP2)
	{
	 if(CurrentItem->pDataP2->pControl->
	 Control(CurrentItem->pDataP2->CntNum,
	 CurrentItem->pDataP2->ChangingValue))
	 {
	 CurrentItem->pDataP2->Value = CurrentItem->pDataP2->ChangingValue;
	 WriteStorageV(CurrentItem->pDataP2->StorageAddr, (volatile char*)&CurrentItem->pDataP2->Value);
	 CurrentItem->pDataP2->pControl->Operate(CurrentItem->pDataP2->OprNum);	 
	 }
	 else
	 {
		CurrentItem->pDataP2->ChangingValue = CurrentItem->pDataP2->Value;
//t		DrawMessage(CurrentItem->pmes0, CurrentItem->pmes1);
		DrawMessage(CurrentItem->pDataP2->pMes0, 
				CurrentItem->pDataP2->pMes1);
	 }
	}
		
	if(CurrentItem->pDataC0)
	{
	 if(CurrentItem->pDataC0->pControl->
	 Control(CurrentItem->pDataC0->CntNum,
	 CurrentItem->pDataC0->ChangingValue))
	 {
//	 CurrentItem->pDataC0->Value = 0l;
	 CurrentItem->pDataC0->Value = 
	 CurrentItem->pDataC0->ChangingValue;
//	 WriteStorageC(CurrentItem->pDataC0->StorageAddr, CurrentItem->pDataC0->Value);
//	 WriteStorageC(CurrentItem->pDataC0->StorageAddr, (volatile char *)(&CurrentItem->pDataC0->Value));
	 WriteStorageC(CurrentItem->pDataC0->StorageAddr, CurrentItem->pDataC0->Value);
	 CurrentItem->pDataC0->pControl->Operate(CurrentItem->pDataC0->OprNum);	 
//to test
//	float64 tmp;
//	float64 *ptmp;
//	ptmp = &tmp;
//	ptmp = ReadStorageC(CurrentItem->pDataC0->StorageAddr);
		 
	 }
	 else
	 {
		CurrentItem->pDataC0->ChangingValue = CurrentItem->pDataC0->Value;
//t		DrawMessage(CurrentItem->pmes0, CurrentItem->pmes1);
		DrawMessage(CurrentItem->pDataC0->pMes0, 
				CurrentItem->pDataC0->pMes1);
	 }
	}	
	_setcursortype(0); //blink off
	MenuState.DataChanging = 0;	
	MenuState.DataP0Changing = 0;
	MenuState.DataP1Changing = 0;
	MenuState.DataP2Changing = 0;
	MenuState.DataC0Changing = 0;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(Menu::Menu, "ExpertFuncs")
#endif
extern "C" Menu::Menu(Item * SetItem, Uint32 SetRedrawPeriod)
{
 CurrentItem = SetItem;
 MenuState.DataChanging = 0; //not changing now
 MenuState.DataP0Changing = 0; //not changing now
 MenuState.DataP1Changing = 0; //not changing now
 MenuState.DataP2Changing = 0; //not changing now
 MenuState.DataC0Changing = 0; //not changing now
// ScanCnt = 0;
 RedrawPeriod = SetRedrawPeriod;
//to_start Draw();
//	pCurrentKey = &CurrentKey;
}	


#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::Draw, "ExtFuncs")
#endif
extern "C" void Menu::Draw()
{
/*
 char c = (char) this->CurrentItem->ItemNumber;
 switch( c )
 {
 case 1: BerItem.DrawItem(); break;
 case 2: CommandItem.DrawItem(); break;
 default: BerItem.DrawItem(); break;
 }
 */
  this->CurrentItem->DrawItem();//to future
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::SetChange, "ExtFuncs")
#endif
extern "C" void Menu::SetChange(Uint16 SelChange)
{
	switch(SelChange)
	{
		case 0 :	 gotoxy(CurrentItem->pDataP0->XPos,CurrentItem->pDataP0->YPos);
			 		 MenuState.DataP0Changing = 1;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 0;
	 				 break;
	 	case 1 :	 gotoxy(CurrentItem->pDataP1->XPos,CurrentItem->pDataP1->YPos);
	 	 			 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 1;
 	 				 MenuState.DataP2Changing = 0;
 	 				 MenuState.DataC0Changing = 0;
 	 				 break;
 	 	case 2 :	 gotoxy(CurrentItem->pDataP2->XPos,CurrentItem->pDataP2->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 1;
	 				 MenuState.DataC0Changing = 0;
	 				 break;
 	 	case 3 :	 gotoxy(CurrentItem->pDataC0->XPos,CurrentItem->pDataC0->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 1;
	 				 CurrentItem->pDataC0->CurXPos = CurrentItem->pDataC0->XPos;
	 				 break;	 				 
		default:	 break;				 

	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateRight, "ExtFuncs")
#endif
extern "C" void Menu::OperateRight()
{
		if(MenuState.DataChanging == 0) //have data, it are not changing now
		{		
				do {this->CurrentItem = this->CurrentItem->pItemRight;}
				  while(!(this->CurrentItem->visibled));
		 		Draw(); 		  
		}
		else //data is changing
		{
			if(MenuState.DataP0Changing == 1)//now changed DataP0
			{
				if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
					 {
	 				 	 SetChange(1);
	 				 }
				else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
				 	 {
	 				 	 SetChange(2);
	 				 }		
				else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
				 	 {
	 				 	 SetChange(3);
	 				 }		
			}
			else if(MenuState.DataP1Changing == 1)//now changed DataP1
			{
				 if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
				 	 {
	 				 	 SetChange(2);
	 				 }		
				else if((CurrentItem->pDataC0) &&
						(CurrentItem->pDataC0->Changable))
					 {
	 					 SetChange(3);
	 				 }
				else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
	 				 }
			}//p1
			else if(MenuState.DataP2Changing == 1)//now changed DataP1
			{
				if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 					 SetChange(3);
					 }
				 else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
							(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
			}//p2
			else if(MenuState.DataC0Changing == 1)//now changed DataP1
			{
			 if(!(CurrentItem->pDataC0->LastDigit())) //cursor on last digit
				{
				 if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
				else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
				 	 {
	 	 				 SetChange(2);
	 				 }		
				else
					{
						 SetChange(3); //go first digit
					}
				} //lastdigit() != 0
			else //need to get to next digit
				{
				//change next digit
				CurrentItem->pDataC0->CurXPos++;
				if(CurrentItem->pDataC0->DgAftPnt)
				{
					if(CurrentItem->pDataC0->CurXPos ==
					(CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne -
					CurrentItem->pDataC0->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC0->CurXPos++;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC0->CurXPos, CurrentItem->pDataC0->YPos);
				}
			}//c0
		}
//	 Draw(); 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateLeft, "ExtFuncs")
#endif
extern "C" void Menu::OperateLeft()
{

		if(MenuState.DataChanging == 0) //have data, it are not changing now
		{		
				do {this->CurrentItem = this->CurrentItem->pItemLeft;}
				  while(!(this->CurrentItem->visibled));
				  Draw(); //after Draw() cursor in last position
		}
		else //data is changing
		{
			if(MenuState.DataP0Changing == 1)//now changed DataP0
			{
				if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
				else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
					 {
	 				 	 SetChange(2);
	 				 }
				else if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
				 	 {
	 				 	 SetChange(1);
	 				 }		
			}
			else if(MenuState.DataP1Changing == 1)//now changed DataP1
			{
				 if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
				 	 {
	 				 	 SetChange(0);
	 				 }		
				else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
				else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
					 {
	 					 SetChange(2);
	 				 }
			}//p1
			else if(MenuState.DataP2Changing == 1)//now changed DataP2
			{
				 
				 if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
					 {
	 					 SetChange(1);
					 }
				 else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	 {
	 	 				 SetChange(0);
	 				 }		
				else if((CurrentItem->pDataC0) &&
						(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			}//p2
			else if(MenuState.DataC0Changing == 1)//now changed DataC0
			{

				 if(CurrentItem->pDataC0->CurXPos ==
				 	CurrentItem->pDataC0->XPos)
				 { //go to next data or to lastdigit
					if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
					{
	 				 	 SetChange(2);
	 				 
					}
					else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	{
	 				 	 SetChange(1);
	 				}
					else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	{
	 				 	 SetChange(0);
	 				}	
					else //go last digit
					{
					CurrentItem->pDataC0->CurXPos =
					CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne - 1;
					gotoxy(CurrentItem->pDataC0->CurXPos,
							CurrentItem->pDataC0->YPos);
					}
				 }//first digit
			 else //not first digit
			 { // go to previons digit
				CurrentItem->pDataC0->CurXPos--;
				if(CurrentItem->pDataC0->DgAftPnt)
				{
					if(CurrentItem->pDataC0->CurXPos ==
					(CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne -
					CurrentItem->pDataC0->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC0->CurXPos--;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC0->CurXPos, 
					CurrentItem->pDataC0->YPos);
			 } //not first digit
		   } //changing DataC0
		} //data is changing
//		 Draw(); //after Draw() cursor in last position
//		 gotoxy(CurrentItem->pDataC0->CurXPos, 
//				CurrentItem->pDataC0->YPos);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateEnter, "ExtFuncs")
#endif
extern "C" void Menu::OperateEnter()
{
	if((CurrentItem->pDataP0 == NULL) && 
	   (CurrentItem->pDataP1 == NULL) &&
	   (CurrentItem->pDataP2 == NULL) &&
	   (CurrentItem->pDataC0 == NULL)
	   )//not have data
	{ 
		this->CurrentItem = this->CurrentItem->pItemDown;
	    if(!(this->CurrentItem->visibled))
		  {
			  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
			  while(!(this->CurrentItem->visibled));
		  }
	}
	else if(MenuState.DataChanging == 0) //have data, it are not changing now
	{
	StartChanging();
	//need set cursor to first data and blink cursor
	}
	else //  MenuState.DataChanging = 1
	{
	StopChanging();
	//need blink off 
	}
	Draw();
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateEsc, "ExtFuncs")
#endif
extern "C" void Menu::OperateEsc()
{
	if(MenuState.DataChanging == 0) //not have data or it are not changing now
	{
				  this->CurrentItem = this->CurrentItem->pItemUp;
				  if(!(this->CurrentItem->visibled))
				  {
				  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
				  while(!(this->CurrentItem->visibled));
				  }
	}
	else//data are changing now
	{
		if(CurrentItem->pDataP0)
		{
	 	CurrentItem->pDataP0->ChangingValue = 
	 	CurrentItem->pDataP0->Value;
		}
		if(CurrentItem->pDataP1)
		{
	 	CurrentItem->pDataP1->ChangingValue = 
	 	CurrentItem->pDataP1->Value;
		}
		if(CurrentItem->pDataP2)
		{
	 	CurrentItem->pDataP2->ChangingValue = 
	 	CurrentItem->pDataP2->Value;
		}
		if(CurrentItem->pDataC0)
		{
	 	CurrentItem->pDataC0->ChangingValue = 
	 	CurrentItem->pDataC0->Value;
		}
	}		
	_setcursortype(0); //blink off
	MenuState.DataChanging = 0;	
	MenuState.DataP0Changing = 0;
	MenuState.DataP1Changing = 0;
	MenuState.DataP2Changing = 0;
	MenuState.DataC0Changing = 0;		  
  	Draw(); 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateUp, "ExtFuncs")
#endif
extern "C" void Menu::OperateUp()
{
	if(MenuState.DataChanging == 1) //have data, it are changing now
	{	
		if(MenuState.DataP0Changing == 1)//now changed DataP0
		{
			if((CurrentItem->pDataP0->ChangingValue + 1) ==
			CurrentItem->pDataP0->Quantity)
			{
			CurrentItem->pDataP0->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP0->ChangingValue++;
			}
		}
		else if(MenuState.DataP1Changing == 1)//now changed DataP1
		{
			if((CurrentItem->pDataP1->ChangingValue + 1) ==
			CurrentItem->pDataP1->Quantity)
			{
			CurrentItem->pDataP1->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP1->ChangingValue++;
			}
		}
		else if(MenuState.DataP2Changing == 1)//now changed DataP2
		{
			if((CurrentItem->pDataP2->ChangingValue + 1) ==
			CurrentItem->pDataP2->Quantity)
			{
			CurrentItem->pDataP2->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP2->ChangingValue++;
			}
		}	
		else if(MenuState.DataC0Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC0->ChangingValue =
			CurrentItem->pDataC0->ChangingValue +
			CurrentItem->pDataC0->Delta(Up);
		}
	}
  Draw(); 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::OperateDown, "ExtFuncs")
#endif
extern "C" void Menu::OperateDown()
{
	if(MenuState.DataChanging == 1) //have data, it are changing now
	{	
		if(MenuState.DataP0Changing == 1)//now changed DataP0
		{
			if(CurrentItem->pDataP0->ChangingValue == 0)
			{
			CurrentItem->pDataP0->ChangingValue = 
				(CurrentItem->pDataP0->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP0->ChangingValue--;
			}
		}
		else if(MenuState.DataP1Changing == 1)//now changed DataP1
		{
			if(CurrentItem->pDataP1->ChangingValue == 0)
			{
			CurrentItem->pDataP1->ChangingValue = 
				(CurrentItem->pDataP1->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP1->ChangingValue--;
			}
		}
		else if(MenuState.DataP2Changing == 1)//now changed DataP2
		{
			if(CurrentItem->pDataP2->ChangingValue == 0)
			{
			CurrentItem->pDataP2->ChangingValue = 
				(CurrentItem->pDataP2->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP2->ChangingValue--;
			}
		}
		else if(MenuState.DataC0Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC0->ChangingValue =
			CurrentItem->pDataC0->ChangingValue -
			CurrentItem->pDataC0->Delta(Down);
		}
	}	
  Draw(); 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Menu::ServiceKey, "ExtFuncs")
#endif
extern "C" void Menu::ServiceKey()
{	
//	static Uint16 c1; 
//	CurrentKey = GetKey();
	switch(GetKey())
	{
	case None :   break;
	case Left :   OperateLeft();break;
	case Right:   OperateRight(); break;
	case Up   :   OperateUp(); break;
	case Down :	  OperateDown();break;	
	case Enter:   OperateEnter(); break;
	case Esc  :   OperateEsc(); break;
	default	  :	  break;		
	}
	
}	

//inline Uint16 SPIA_Transmit1(Uint16 cmdData)
Uint16 SPIA_Transmit1(Uint16 cmdData)
{
    Uint16 recvData;
    // Send Read command/dummy word to EEPROM to fetch a byte
    SpiaRegs.SPITXBUF = cmdData;                  
    while( (SpiaRegs.SPISTS.bit.INT_FLAG) !=1);
    // Clear SPIINT flag and capture received byte
    recvData = SpiaRegs.SPIRXBUF;     		 
    return ;  
}

void SPIA_Init1()
{
    // Enable SPI-A clocks
    EALLOW;
//t03    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;
    SysCtrlRegs.LOSPCP.all = 0x0002;	
    // Enable FIFO reset bit only
    SpiaRegs.SPIFFTX.all=0x8000;
    // 8-bit character
    //  SpiaRegs.SPICCR.all = 0x0007;
    //=> 16 - bit character
    SpiaRegs.SPICCR.all = 0x000F; //to test
    // Use internal SPICLK master mode and Talk mode
    SpiaRegs.SPICTL.all = 0x000E; 
    // Use the slowest baud rate
    SpiaRegs.SPIBRR     = 0x007f;
    // Relinquish SPI-A from reset
  //t  SpiaRegs.SPICCR.all = 0x0087; //8bit
    SpiaRegs.SPICCR.all = 0x008F;//16 bit
    // Enable SPISIMO/SPISOMI/SPICLK pins
    // Enable pull-ups on SPISIMO/SPISOMI/SPICLK/SPISTE pins
    // GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;
    // GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;
//t03    GpioCtrlRegs.GPAPUD.all &= 0xFFF0FFFF;                  
    // GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;
//t03    GpioCtrlRegs.GPAMUX2.all |= 0x00000015;
    // SPI-A pins are asynch
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3;        
//t03    GpioCtrlRegs.GPAQSEL2.all |= 0x0000003F;
    // IOPORT as output pin instead of SPISTE
//t03    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
//to03    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
    // Chip enable - low
    //GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;      //need gpiof3
 //no set hier cs   GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;			// 
    EDIS;
    return;
}


void SPIA_Init2()
{
    // Enable SPI-A clocks
    EALLOW;
//t03    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;
    SysCtrlRegs.LOSPCP.all = 0x0002;	
    // Enable FIFO reset bit only
    SpiaRegs.SPIFFTX.all=0x8000;
    // 8-bit character
    //  SpiaRegs.SPICCR.all = 0x0007;
    //=> 16 - bit character
    SpiaRegs.SPICCR.all = 0x000F; //to test
    // Use internal SPICLK master mode and Talk mode
  //test  SpiaRegs.SPICTL.all = 0x000E; 
    SpiaRegs.SPICTL.all = 0x0006; //test
   // SpiaRegs.SPICTL.all = 0x0004; //test
    // Use the slowest baud rate
  //  SpiaRegs.SPIBRR     = 0x004f;//work
  //   SpiaRegs.SPIBRR     = 0x002f; //work
  //   SpiaRegs.SPIBRR     = 0x001f; //work
 //    SpiaRegs.SPIBRR     = 0x000f;//??
  //   SpiaRegs.SPIBRR     = 0x0007;
     SpiaRegs.SPIBRR     = 0x0003;
 //test	   SpiaRegs.SPIBRR     = 0x007f;
 //	   SpiaRegs.SPIBRR     = 0x0000;//not work
  //	   SpiaRegs.SPIBRR     = 0x006f; //work
//not work  	   SpiaRegs.SPIBRR     = 0x0013; //
//not work	   SpiaRegs.SPIBRR     = 0x0027; //
 //		SpiaRegs.SPIBRR     = 0x0000; //
    // Relinquish SPI-A from reset
  //t  SpiaRegs.SPICCR.all = 0x0087; //8bit
  //  SpiaRegs.SPICCR.all = 0x008F;//16 bit
    SpiaRegs.SPICCR.all = 0x00CF;//16 bit data out on phase =1, in on rising edge
    // Enable SPISIMO/SPISOMI/SPICLK pins
    // Enable pull-ups on SPISIMO/SPISOMI/SPICLK/SPISTE pins
    // GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0; 
    // GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;
    // GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;
//t03    GpioCtrlRegs.GPAPUD.all &= 0xFFF0FFFF;                  
    // GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;
    // GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;
//t03    GpioCtrlRegs.GPAMUX2.all |= 0x00000015;
    // SPI-A pins are asynch
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;
    // GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3;        
//t03    GpioCtrlRegs.GPAQSEL2.all |= 0x0000003F;
    // IOPORT as output pin instead of SPISTE
//t03    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
//to03    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
    // Chip enable - low
    //GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;      //need gpiof3
 //no set hier cs   GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;			// 
    EDIS;
    return;
}
//#ifdef __cplusplus
//#pragma CODE_SECTION("ExpertFuncs")
//#else
//#pragma CODE_SECTION(InitMenu, "ExpertFuncs")
//#endif
//extern "C" void InitMenu()
//{
//	BerItem.InitItem(&CommandItem, &CommandItem, &BerItem, &BerItem);
//	CommandItem.InitItem(&BerItem, & BerItem, &CommandItem, &CommandItem);
// UsedMenu.SetCI(1);
// UsedMenu.CurrentItem = &BerItem;
 	
 //UsedMenu.CurrentItem = &CommandItem;
// UsedMenu.CurrentKey = None;
// UsedMenu.Draw();
//}
//MenuItem BerItem("BerTester");
//MenuItem* BerItem = new MenuItem("BerTester", 1);
//MenuItem* StartItem = new MenuItem("StartStop", 2);
/*
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(UsedMenu,"MenuFile");
#endif
*/
//Menu* UsedMenu = new Menu(1); //CurrenrItem is 1
//Menu* UsedMenu = new Menu(); //CurrenrItem is
//class Menu UsedMenu;
//UsedMenu.CurrentItem = 1;

/*
volatile Menu UsedMenu(1); //CurrenrItem is 1
*/
//}
//int t2 = UsedMenu.CurrentItem; //test
//___________end of file