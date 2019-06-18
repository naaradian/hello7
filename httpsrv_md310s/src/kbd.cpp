//kbd.cpp
#include "kbd.h"
#include "disp.h"
#include "Expert.h"
#include "menu.h"
#include "expdata.h"
Uint16 SPIA_Transmit1(Uint16);
void SPIA_Init1(void);
extern "C" void ResetWD();
//extern "C" void Pause(unsigned long);
//Uint32 KbdTimeOutVal 	=	150000l;
//tUint32 KbdTimeOutVal 	=	15000l;
//Uint32 KbdTimeOutVal 	=	1000l;
const Uint32 KbdTimeOutVal 	=	2000l;
Uint32 ScanCnt			= 	0l;
unsigned int State = 0;
unsigned long PCnt = 0;
unsigned int bytecnt = 0;
//to_start Uint32 KbdTimeOutVal 	=	1l;
//Uint32 KbdTimeOut 		=	KbdTimeOutVal;
Uint32 KbdTimeOut 		=	0l; //to read keys quickly after start
unsigned long ProgModeTimeOut 		=	0l; //to read keys quickly after start
const unsigned long ProgModeTime 	= 100000l;	//not work 10000l;//work 100000l;
Uint16 Ping;
//Uint16 CurrentKey;
Uint16 t3;
//extern "C" void Tcpipint(void);
/*
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(TCPParser, "ExtFuncs")
#endif
extern "C" void TCPParser(unsigned char* p)
{
	unsigned int Buffersize = 30;
	char CommandBuffer[30];
	char * Command;
	Command = &CommandBuffer[0];
//t	while(((*p) != 0) && Buffersize)
//	while((	while(((*p) != 0) && Buffersize) && Buffersize)
//	{
//	 *Command++ = (((*p)) & 0xff);
//	 *Command++ = (((*p++)>>8) & 0xff);
//	  Buffersize--;
//	}
	unsigned int i;
	for(i = 0; i < Buffersize; i++)
	{
//	if(((*p) & 0xff) != ';')
	if((((*p) & 0xff) != ';') 
	&& (((*p) & 0xff) != '.'))
	{
	 *Command++ = (((*p)) & 0xff);
	}
	else
	{
		if(i){ *Command = '\0';	break;}//not use ';' from previons command
	}
//	if(((*p)>>8 & 0xff) != ';')
	if((((*p)>>8 & 0xff) != ';')
	&& (((*p)>>8 & 0xff) != '.'))
	{
	 *Command++ = (((*p++)>>8) & 0xff);
	}
	else
	{
		if(i){ *Command = '\0';	break;}
	}	
	
	}
    UsedRemote.RunCommand(&CommandBuffer[0]);
//	ExpertRegs.XILR2 = 0x1;
//	UsedExp.State.Reg1.bit.Zumm  = 1;
//	while(time--);
//	UsedExp.State.Reg1.bit.Zumm  = 0;
//	ExpertRegs.XILR2 = 0x0;
}
*/

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Message, "ExtFuncs")
#endif
extern "C" void Message(char * mline0, char * mline1)
{
	UsedMenu.DrawMessage(mline0, mline1);
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(TCPAnswer, "ExtFuncs")
#endif
extern "C" char* TCPAnswer()
{

 	return &UsedRemote.TBuff[0];
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ProgModeClose, "ExtFuncs")
#endif
extern "C" void ProgModeClose()
{
if(	UsedExp.State.Reg1.bit.ProgMode)
	{
	PieCtrlRegs.PIECRTL.bit.ENPIE = 1; //enable interrupts
	UsedExp.State.Reg1.bit.ProgMode = 0;
	Message("   Prog Mode", "     Is Off");
	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(SendCommand, "ExtFuncs")
#endif	
extern "C" unsigned int SendCommand(unsigned int cmd)
	{
			unsigned int tmp;
			UsedExp.State.Reg1.bit.CsSpi = 1; //cs-on ????
			GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;
			tmp = SPIA_Transmit1((Uint16)cmd);
	//		Pause(1000l);
	//		cmd = (float64)tmp;
	return tmp;
	}
#ifdef __cplusplus	
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(SendData, "ExtFuncs")
#endif	
extern "C" void SendData(unsigned int cmd)
	{
		unsigned int tmp;
		tmp = SPIA_Transmit1((Uint16)cmd);
	}
#ifdef __cplusplus	
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(CsOff, "ExtFuncs")
#endif	
extern "C" void CsOff(void)
	{
		 GpioDataRegs.GPFSET.bit.GPIOF3 = 1; 
		 UsedExp.State.Reg1.bit.CsSpi = 0;
	}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(CheckReady, "ExtFuncs")
#endif	
extern "C" char CheckReady(void)
	{
 	char ret = 1;
 	unsigned int rdata;
 	rdata = SendCommand(0xD700);//a4
 	CsOff();
 //	ret = (rdata >> 2) & 0xf;
 //	ret = (rdata & 0x7f) ? 0 : 1;
 	ret = (rdata & 0x80) ? 0 : 1;
 	return ret;

	}
//#ifdef __cplusplus
//#pragma CODE_SECTION("ExtFuncs")
//#else
//#pragma CODE_SECTION(Pause, "ExtFuncs")
//#endif	
//extern "C" void Pause(unsigned long WaitValue)
//	{
 //		while(WaitValue)
//		{
//			WaitValue--;
//			ResetWD();
//		}
//	}	
//#ifdef __cplusplus	
//#pragma CODE_SECTION("ExtFuncs")
//#else
//#pragma CODE_SECTION(Init, "ExtFuncs")
//#endif	
//extern "C" void Init(void)
//	{
// 	UsedExp.State.Reg1.bit.CsSpi = 1; 
// 	GpioDataRegs.GPFCLEAR.bit.GPIOF3 = 1;
//	SPIA_Init1();
//	}		
#ifdef __cplusplus			
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetFlash, "ExtFuncs")
#endif	
extern "C" void GetFlash(unsigned char sb)
	{
//		static unsigned int State = 0;
		unsigned int BufferSize = 132;
	//	unsigned long FlashSize;
		unsigned char MovePos = 9;
		unsigned long cnt;
//		static unsigned int bytecnt = 0;
		static unsigned long addr;
		static unsigned char tmpa;
//		unsigned long WaitValue = 1500l; //800 -work
		unsigned long WaitValue = 3000l; //800 -work
		unsigned int cmd;
		static unsigned long u_StartPage; //to now not erase programm	
	//	ResetWD(); //use WD timer to have activity
//			EALLOW;
//			SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
//   			SysCtrlRegs.WDKEY = 0xAA;
//   			EDIS;
		switch(State)
		{
	case 0 : 
	//t				 Init();
	
	//	else
		if(bytecnt >= 4)
		{
		cnt = 0l; //add
		while(CheckReady()) //to test
		{
		//hier need watchdog
		cnt++;
		if (cnt >  WaitValue) break;
		ResetWD();
		}
		//	cnt = 0l;
				//		while(CheckReady())
				//		while(1)
				//		{
				//			cnt++;
				//			if (cnt > WaitValue) break;
				//			ResetWD();
				//		}
	//				 Pause(WaitValue);
			//	 Pause(5l);
					 PCnt = u_StartPage; //t
					 addr = (PCnt << MovePos);// & 0x1ffe00l;
					 tmpa = addr >> 16;
					 cmd = 0x8400 + tmpa; // added first byte af addr
			//		cmd = 0x8200 + tmpa; // added first byte af addr
			//		 cmd = 0x8700 + tmpa; // added first byte af addr
					  SendCommand(cmd);
					 cmd = addr;
					 //Pause(5l);
					 SendData(cmd);
				//	 Pause(WaitValue);
					 bytecnt = 0;
					 State ++;  //not break to go next step in this cyckle
		}
		else if(bytecnt < 2) //first four bytes - start page
		{
		u_StartPage <<= 16;
		u_StartPage += (unsigned long)sb;
		bytecnt++;
		break;
		}
		else if(bytecnt < 3) //next two bytes - buffersize
		{
		BufferSize = (unsigned long)sb;
		bytecnt++;
		break;
		}
		else if(bytecnt < 4) //next two bytes - MovePos
		{
		MovePos = (unsigned long)sb;
		bytecnt++;
		break;
		}	
			case 1 :	if(bytecnt < (BufferSize -1)) //fill buffer 1
						{
							bytecnt++;
							SendData(sb);
							break;
						}
						else //buffer full
						{
						SendData(sb);
						CsOff();
			//	cnt = 0l;
						while(CheckReady())
						{ResetWD();}
				//		while(1)
				//		{
				//			cnt++;
				//			if (cnt > WaitValue) break;
				//			ResetWD();
				//		}
			//t		 Pause(WaitValue);
				//	  Pause(500l);
				//	  Pause(50l);
				//	  Pause(5l);
						State++;
						cmd = 0x8300 + tmpa; // added first byte af addr
				//		cmd = 0x8600 + tmpa; // added first byte af addr
					 	SendCommand(cmd);
					 	cmd = addr;
						SendData(cmd);
						CsOff();
						break;
						}
			case 2 :	//check to rom is not busy and b1 -> mem
						PCnt++; //increment page counter
						addr = (PCnt << MovePos);

				//	    cnt = 0l;
				//		while(CheckReady()) //to test
					//	while(1) //to test
				//		{
							//hier need watchdog
				//			cnt++;
					//		if (cnt > WaitValue) break;
				//			ResetWD();
				//		}
				//test1		 Pause(WaitValue);
						 //	 Pause(5l);
						tmpa = (addr >> 16) & 0xff;
						cmd = 0x8700 + tmpa; // added first byte af addr
				//		cmd = 0x8500 + tmpa; // added first byte af addr
					 	SendCommand(cmd);
					 	cmd = addr;
					 	SendData(cmd);
					// 	Pause(50l);
						bytecnt = 0;
						State++;
			case 3 :	//fill buffer2
						if(bytecnt < (BufferSize - 1)) //fill buffer 2
						{
							bytecnt++;
							SendData(sb);
							break;
						}
						else //buffer full
						{
							//need cs off
							SendData(sb);
							CsOff();
				//	cnt = 0l;
						while(CheckReady())
							{ResetWD();}
				//		while(1)
				//		{
				//			cnt++;
				//			if (cnt > WaitValue) break;
				//			ResetWD();
				//		}
			//t		 Pause(WaitValue);
				//	 Pause(500l);
				// Pause(50l);
			//	 Pause(5l);
							State++;
							cmd = 0x8600 | tmpa; // added first byte af addr
					 		SendCommand(cmd);
							cmd = addr;
							SendData(cmd);
							CsOff();
							break;
						}
			case 4 :	//wait of rom is not busy and b2 -> mem
				//		cnt = 0l;
				//		while(CheckReady())
				//		while(1)
				//		{
				//			cnt++;
				//			if (cnt > WaitValue) break;
				//			ResetWD();
				//		}
			//test2		 Pause(WaitValue);
			//	 Pause(5l);
						PCnt++; //increment page counter
						addr = (PCnt << MovePos);
					 	tmpa = (addr >> 16) & 0xff;
						cmd = 0x8400 + tmpa; // added first byte af addr
				//		cmd = 0x8200 + tmpa; // added first byte af addr
					//	cmd = 0x8700 + tmpa; // added first byte af addr
					 	SendCommand(cmd);
					 	cmd = addr;
					 	SendData(cmd);
						bytecnt = 0;
						SendData(sb);
						bytecnt = 1; //one byte is written
						State = 1; //continue writing to buffer 1 for next byte 
						break;
			

			default: ;
		}
	
	}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetState, "ExtFuncs")
#endif	
extern "C" char GetState()
	{
	return(UsedExp.State.Reg1.bit.ProgMode);
//	UsedRemote.Receive(ToRem);
	}
#ifdef __cplusplus
//#pragma CODE_SECTION("ExtFuncs")
#pragma CODE_SECTION(".const")
#else
//#pragma CODE_SECTION(ResetWD, "ExtFuncs")
#pragma CODE_SECTION(ResetWD, ".const")
#endif	
extern "C" void ResetWD()
	{
//	if((!UsedExp.State.Reg1.bit.ProgMode))
//			{
			EALLOW;
			SysCtrlRegs.WDKEY = 0x55;  // Clear the WD counter
    		SysCtrlRegs.WDKEY = 0xAA;
   			EDIS;
  	//		}
	}	
/*
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(TCPSetRemBuf, "ExtFuncs")
#endif
extern "C" void TCPSetRemBuf()
{
// 	return   UsedRemote.pTBuff;
 //	return &UsedRemote.TBuff[0];
 UsedRemote.pTBuff = &UsedRemote.TBuff[0];
}
*/
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Ring, "ExtFuncs")
#endif
extern "C" void Ring(unsigned long time)
{
	ExpertRegs.XILR2 = 0x1;
//	UsedExp.State.Reg1.bit.Zumm  = 1;
	while(time--);
//	UsedExp.State.Reg1.bit.Zumm  = 0;
	ExpertRegs.XILR2 = 0x0;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetKey, "ExtFuncs")
#endif
extern "C" Uint16 GetKey()
{
	Uint16 Ping;
//	static unsigned int cntkey;
//	switch(cntkey)
//	{
	/*
	case 1: tmp = Enter; break;
	case 2: tmp = Up;  break;
	case 3: tmp = Enter;  break;
	case 4: tmp = Enter;  break;
	case 5: tmp = Up;  break;	
	case 6: tmp = Enter;  break;
	case 7: tmp = Enter; cntkey = 0; break;	
	
	default: tmp = None;
	used for WriteStorageC
	case 1: tmp = Enter; break;
	case 2: tmp = Up;  break;
	case 3: tmp = Right;  break;
	case 4: tmp = Up;  break;
	case 5: tmp = Right;  break;	
	case 6: tmp = Up;  break;
	case 7: tmp = Right; cntkey = 0; break;	
	default: tmp = None;	
	*/
//	}
	//Uint16 tmp = Right;
//	Uint16 tmp = Left;	
//	 cntkey++;
 // return tmp;

		Ping = ExpertRegs.KBDData & 0x3f;
		
		if(Ping != 0x3f) //any key pressed
 		{
 		 if(!UsedExp.State.Reg1.bit.KeyPing)
 		 { 
 		 	UsedExp.State.Reg1.bit.KeyPing = 1;
 			if(Ping == 0x0f) //preseed together esc and enter
 			{
 			UsedExp.State.Reg2.bit.DcrBoot = 0; //if turn on widch esc and enter - not need boot - run in loader
 // 		UsedExp.State.Reg2.bit.Some = 1; //need some update	
 			}
 		UsedExp.Zummer(1);
 //		UsedExp.KeyRingCounter = UsedExp.KeyRingInterval;
 //	ExpertRegs.XILR2 = 0x1; //zummer on - temporary hier
 		UsedExp.State.Reg1.bit.Frozen  = 0; //unfrozen display
 //		UsedExp.State.Reg1.bit.Zumm  = 1; //zummer on
 //		UsedExp.State.Reg2.bit.XILR2 = 1; //need load xilr2
  //		UsedExp.State.Reg2.bit.Some = 1; //need some update
//it is temporary
 //t		MDelay(500000l);
 //t		ExpertRegs.XILR2 = 0x0; //zummer off
 //t 		UsedExp.State.Reg1.bit.Zumm = 0; //zummer off
//it is temporary  			
  			switch(Ping)
	 		{
	 		case 0x2f: return Esc;
	 		case 0x1f: return Enter;
	 		case 0x37: return Up;
	 		case 0x3b: return Down;
	 		case 0x3d: return Left;
 			case 0x3e: return Right;
  			default:   return None;
  			}
  		 } //!keyPing
  		return None;
 		}
 		else //not pinget keys
 		{
 			UsedExp.State.Reg1.bit.KeyPing = 0; //key get off
 			return None;
 		}
 	
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(OperateScanCnt, "ExpertFuncs")
#endif
extern "C" void OperateScanCnt(void)
{
 static Uint32 Cnt = 0l;
 
//if((ScanCnt != TimerCounter) && (!UsedExp.State.Reg1.bit.ProgMode))
if(ScanCnt != TimerCounter)
{
	Cnt++;
// if(!(ScanCnt%1000l)) //50 ms? what need ?
// {
//  Tcpipint();
// }
/*
if( UsedExp.KeyRingCounter)
	{ 
	 UsedExp.KeyRingCounter--;
	 if(!UsedExp.KeyRingCounter)
	 {
	 UsedExp.Zummer(0);
//	 UsedExp.LoadDevises();
	 }
	}
*/
if(!KeyCounter )
  UsedExp.Zummer(0);
#ifdef _LDR
	if( UsedExp.LoadCounter && UsedExp.State.Reg2.bit.DcrBoot)
	{ 
	UsedExp.LoadCounter--;
	}
	if(! UsedExp.LoadCounter )
	{
	UsedExp.State.Reg2.bit.Boot = 1;
	UsedExp.State.Reg2.bit.Some = 1;
	UsedExp.LoadDevises();
	 } //need some update	
#endif //_LDR
#ifndef _LDR
// if(!(ScanCnt%UsedMenu.RedrawPeriod))
 if(Cnt == (UsedMenu.RedrawPeriod >> 2))
 {
		 if(UsedExp.State.Reg2.bit.Some)
	 	 {UsedExp.LoadDevises();}
	 	LossNumber.pControl->Operate(LossNumber.OprNum); 
	VCC18Number.pControl->Operate(VCC18Number.OprNum); 
 	 BerNumber.pControl->Operate(BerNumber.OprNum); 	 
 }
 else  if(Cnt == (UsedMenu.RedrawPeriod >> 1))
 {
 
 	ErrNumber.pControl->Operate(ErrNumber.OprNum); //this before volnumber
 				//	 break;
//		VolNumber.pControl->Operate(VolNumber.OprNum);  //celling VoilNumber
//moved up	 	ErrNumber.pControl->Operate(ErrNumber.OprNum); 
	//	case 1:
	
		 
	//				 break;
	//	case 2:

 	 
  	 if(UsedMenu.CurrentItem->pDataI0) 
	 	{UsedMenu.CurrentItem->pDataI0->DrawMDataI();}
 }
 else if(Cnt == UsedMenu.RedrawPeriod)
// if(1)
 {
 Cnt = 0l;
 //static unsigned char DivCounter = 0;
 //DivCounter++;
 //	switch(DivCounter)
 //	{
 	//	case 0 : 
 				//	DivCounter = 0;
		//			break;
	 	//hier need make celling values of MDataI
	 	//and redraw if it are visibled noe in menu 
	 	
//	 	VCC18Number.pControl->Operate(VCC18Number.OprNum);
	//}
	 //	case 3:
	// 	 if(UsedMenu.CurrentItem->pDataI0) 
	// 	{UsedMenu.CurrentItem->pDataI0->DrawMDataI();}
	 //				break;
	 //	case 4:	
	
	 	if(UsedMenu.CurrentItem->pDataI1)
	 	 {UsedMenu.CurrentItem->pDataI1->DrawMDataI();}
	 	// 			break;
//	 	 static char Hell[] = "  Expert3 Remote 9600 8 N 1";
	 	 //static char cnt = 0;
	 	 //cnt++;
//t	 	 if (Hell[cnt] == 0) {cnt = 0;}
//t	 	 SciaRegs.SCITXBUF = Hell[cnt]; //to test oot data to sci
	 //	 case 5: 
	 
//	 	 DivCounter = 0;
	 //	 break;
	 //	 default: break;
	 //	 }
	 	 
//to test	 	 
//	 	UsedMenu.DrawMessage(UsedMenu.CurrentItem->pDataP0->pMes0, 
//				UsedMenu.CurrentItem->pDataP0->pMes1);	 

	 
	} 
#endif //no _LDR	
// if(!(ScanCnt%10)) //imitate iterrupt to receive char
// {
//to_start 	UsedRemote.Receive(); // testing operate from rs232
// }
	ScanCnt = TimerCounter;
 } //TimerCounter	
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(OperateKbd, "ExpertFuncs")
#endif
extern "C" void OperateKbd(void)
{
//static int akbd;
//akbd++;
// if(!UsedExp.State.Reg1.bit.ProgMode) //not progmode
 //{
	if(KbdTimeOut)
	{
	KbdTimeOut--;
//	gotoxy(1, 1);
//	cprintf("%s", " _Wait   ");
	}
	else // ! KbdTimeOut
	{
	KbdTimeOut = KbdTimeOutVal;	
//	UsedMenu.CurrentKey = GetKey();	
//	if(UsedMenu.CurrentKey != None)
//	{
//	UsedMenu.CurrentKey = GetKey();
	UsedMenu.ServiceKey();
//	UsedMenu.Draw();	//?
	}
 		
//	Uint16 t4 = UsedMenu.GetCI();
//t	gotoxy(1, 1);
//t	cprintf("%s", " _ReadKbd   ");
//	}
//t	OperateScanCnt();
 //}
	
}


//___________end of file
