//expdata.cpp
#include "expdata.h"
#include "disp.h"
#include "menu.h"
#include "ds2174.h"
//define global timer counter in internal memory
Uint32 TimerCounter;
//Uint32 KeyCounter = 1000l;
//Uint32 KeyCounter = 10l;
Uint32 KeyCounter = 3l;
extern "C" void ResetWD(void);
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::ExDt, "ExtFuncs")
#endif	
extern "C" ExDt::ExDt()
{
// testexp = 5;
	State.Reg1.bit.Zumm = 0; //zummer off
	State.Reg1.bit.KeyPing = 0; //keys  are not pinget
	State.Reg1.bit.Frozen = 0; //display is not frozen
	State.Reg2.bit.LDDS = 1; //need load dds
	State.Reg2.bit.LDs2174 = 1; //need load ds2174
	State.Reg2.bit.Boot = 0; //not need boot
	State.Reg2.bit.XILR0 = 1;
	State.Reg2.bit.XILR1 = 1;
	State.Reg2.bit.XILR2 = 1;
	State.Reg1.bit.Init = 1; //initialize all classes not ended
	State.Reg2.bit.Some = 1;
	State.Reg1.bit.ProgMode = 0; //Programmer Mode off.
//	KeyRingCounter = 0;
//t	KeyRingInterval = 0x400l;
// /128	KeyRingInterval = 0x1000l;
//	KeyRingInterval = 0x10l;
	KeyRingInterval = 0x2l;
#ifdef _LDR
	State.Reg2.bit.DcrBoot = 1; //need decrement boot
//	LoadCounter = 40000l;// ~ 4 s
//	LoadCounter = 4000l; //	~0,4s
	LoadCounter = 3000l; //	~0,3s
#else
	State.Reg2.bit.DcrBoot = 0; //not boot
#endif //_LDR
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::Set, "ExtFuncs")
#endif	
extern "C" void ExDt::Set()
{
	switch(CommandData.Value)
	{
	case 0:  
	State.Reg1.bit.Start = 1; break; //Start
	case 1: 
	 State.Reg1.bit.Start = 0; 
	//to test		 InitBoot();
			break; //Stop
	case 2:  State.Reg1.bit.Start = 1;  //if saved clear - it worked as start
			 VolNumber.Value = 0;
			 ErrNumber.Value = 0;  
			 LossNumber.Value = 0; 
			 CommandData.Value = 1;
			 State.Reg1.bit.Start = 1;
			 break;//Clear	
	default: State.Reg1.bit.Start = 1;
			 CommandData.Value = 1;
		     break;
	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadDevises, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadDevises()
{

	if(State.Reg2.bit.LDDS)
	{
	ResetWD();
	LoadDDS();
	State.Reg2.bit.LDDS = 0;
	}

	if(State.Reg2.bit.XILR0)
	{
	LoadXILR0();
	State.Reg2.bit.XILR0 = 0;
	}
		
	if(State.Reg2.bit.XILR1)
	{
	LoadXILR1();
	State.Reg2.bit.XILR1 = 0;
	}	

	if(State.Reg2.bit.XILR2)
	{
	LoadXILR2();
	State.Reg2.bit.XILR2 = 0;
	}	
	if(State.Reg2.bit.LED)
	{
	LoadLED();
	State.Reg2.bit.LED = 0;
	}
	if(State.Reg2.bit.CLRERR)
	{
	ClearVE();
	State.Reg2.bit.CLRERR = 0;
	}	
	
	if(State.Reg2.bit.LDs2174)
	{
//	for(long t = 0l; t < 100000l; t++ )
	ResetWD();
	LoadDs2174();
	State.Reg2.bit.LDs2174 = 0;
	}
	
	if(State.Reg2.bit.Boot)
	{
	InitBoot();
//not need	State.Reg2.bit.Boot = 0;
	}	
	
	if(State.Reg2.bit.Draw)
	{
	UsedMenu.Draw();
	State.Reg2.bit.Draw = 0;
	}
		
	State.Reg2.bit.Some = 0; //all loaded
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::ClearVE, "ExtFuncs")
#endif	
extern "C" void ExDt::ClearVE()
{
	ErrNumber.Value = 0l;
	VolNumber.Value = 0l;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadLED, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadLED()
{
	unsigned char tmp = 0xfd;
	if(!State.Reg1.bit.Sync) tmp &= 0xfe; //led "RLoss" on
	if(State.Reg1.bit.All1s) tmp &= 0xf7; //led "all1s" on
	if(State.Reg1.bit.All0s) tmp &= 0xfb; //led "all0s" on	
	if((InsBerData.Value) ||(LoopData.Value))  tmp &= 0xef; //led "Test" 	on	
	ExpertRegs.LED = tmp; // hier writing to led
	LEDData.Value = tmp; //to have remote for led
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::Zummer, "ExtFuncs")
#endif	
extern "C" void ExDt::Zummer(unsigned char move)
{

	if(!move) //off
	{
		UsedExp.State.Reg1.bit.Zumm  = 0; //zummer 
 	}
	else //on
	{
	//	ExpertRegs.XILR2 = 0x1; //zummer on - temporary hier
 		UsedExp.State.Reg1.bit.Zumm  = 1; //zummer on
// 		KeyRingCounter = KeyRingInterval;
 		KeyCounter = KeyRingInterval;
 	}

	  //  UsedExp.State.Reg1.bit.Zumm = move ? 1 : 0;
		UsedExp.State.Reg2.bit.XILR2 = 1; //need load xilr2
  		UsedExp.State.Reg2.bit.Some = 1; //need some update
  		LoadDevises();
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::CheckLosses, "ExtFuncs")
#endif	
extern "C" void ExDt::CheckLosses()
{
	if((!(State.Reg1.bit.RLoss)) && (!(State.Reg1.bit.LossCell)))
	{
	 LossNumber.Value++;
	 State.Reg1.bit.LossCell = 1;
	}
	if(State.Reg1.bit.Sync && State.Reg1.bit.LossCell)
	{
     State.Reg1.bit.LossCell = 0;
     State.Reg2.bit.CLRERR = 1; //need clear errors and volume
  	 State.Reg2.bit.Some = 1; //need some update
	}
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::SetStatus, "ExtFuncs")
#endif	
extern "C" void ExDt::SetStatus(unsigned char tmp)
{
	
	State.Reg1.bit.RLoss = (tmp & 0x2) ? 0 : 1; //1 - loss of sync
	State.Reg1.bit.Sync  = (tmp & 0x1) ? 1 : 0; 
	State.Reg1.bit.All1s  = (tmp & 0x40) ? 1 : 0; 
	State.Reg1.bit.All0s  = (tmp & 0x20) ? 1 : 0; 
	State.Reg2.bit.LED = 1; //need load LED
  	State.Reg2.bit.Some = 1; //need some update
  	CheckLosses();
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadDs2174, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadDs2174()
{
	unsigned char tmp, tap0, tap1, tap2, tap3, tmpt;
	
//	tmp = 5;	//insert 10^-4
//	tmp = 2;
	
		
	tmp = 0;
	if(!SynceData.Value) tmp |= 0x80; //autoresync disabled 
	if(LoopData.Value) tmp |= 0x10; //loop enabled 
	Ds2174Regs.CONT1 = tmp;
	tmpt = Ds2174Regs.CONT1;
	
	
	MDelay(150000l);
	tmp = 0;
	
	switch(InsBerData.Value)
	{
		case 0: 	break;    //None
		case 1: 	tmp |= 1; break;//10^-1
		case 2: 	tmp |= 2; break;//10^-2
		case 3: 	tmp |= 3; break;//10^-3
		case 4: 	tmp |= 4; break;//10^-4
		case 5: 	tmp |= 5; break;//10^-5
		case 6: 	tmp |= 6; break;//10^-6
		case 7: 	tmp |= 7; break;//10^-7
		default:	break;
	}
		MDelay(150000l);
		tmp |= 0x30; //061006 set this bit to 1 to check  "self inversion"
	Ds2174Regs.CONT2 = tmp;
	tmp = 0;
		MDelay(150000l);
	Ds2174Regs.CONT3 = tmp;
	tmpt = Ds2174Regs.CONT3;
	MDelay(150000l);
	tmp = 0;
//t	if(PolTtData.Value) tmp |= 0x20; //line TT - invert tclko
	Ds2174Regs.CONT4 = tmp;
	tmpt = Ds2174Regs.CONT4;
//2^32 - 1	
//	tmp = 0x03;
	MDelay(150000l);
	switch(PatType.Value)
	{
//	case 3: tap0 = 0; 	 tap1 = 0; 		tap2 = 0; tap3 = 0; break; //1 in 32
//	case 1: tap0 = 1; 	 tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //all ones
	case 0: tap0 = 2; 	 tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //alt 0s 1s
//	case 0: tap0 = 1; 	 tap1 = 0;    tap2 = 0; tap3 = 0; break; //all zeros
	case 1: tap0 = 4; 	 tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //1 in 4
	case 2: tap0 = 5; 	 tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //2^3-1
	case 3: tap0 = 9; 	 tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //2^3-1	
	case 4: tap0 = 0x41; tap1 = 0; 	  tap2 = 0; tap3 = 0; break; //2^7	
	case 5: tap0 = 0x10; tap1 = 0x01; tap2 = 0; tap3 = 0; break; //2^9	
	case 6: tap0 = 0; 	 tap1 = 0x05; tap2 = 0; tap3 = 0; break; //2^11		
	case 7: tap0 = 0; 	 tap1 = 0x60; tap2 = 0; tap3 = 0; break; //2^15-1 O.153
	case 8: tap0 = 1; 	 tap1 = 0x40; tap2 = 0; tap3 = 0; break; //2^15-1 M64
	case 9: tap0 = 3; 	 tap1 = 0; 	  tap2 = 0x20; tap3 = 0x80; break; //2^32-1
	default: tap0 = 0; 	 tap1 = 0; 	  tap2 = 0; 	tap3 = 0; break;
	}
	if(PatType.Value < 2) //for meander and 1 in 4 previonsly set all ones
	{
	Ds2174Regs.TAP0 = 0;
	tmpt = Ds2174Regs.TAP0;
	MDelay(150000l);
//	Ds2174Regs.CONT2 = 0x1;
	Ds2174Regs.CONT2 = 0x0;
	tmpt = Ds2174Regs.CONT2;
	MDelay(150000l);
	}
	Ds2174Regs.TAP0 = tap0;
	tmpt = Ds2174Regs.TAP0;
	MDelay(150000l);
	//tmp = 0x00;
	Ds2174Regs.TAP1 = tap1;
	tmpt = Ds2174Regs.TAP1;
	MDelay(150000l);
	//tmp = 0x20;
	Ds2174Regs.TAP2 = tap2;	
	tmpt = Ds2174Regs.TAP2;
	MDelay(150000l);
	//tmp = 0x80;
	Ds2174Regs.TAP3 = tap3;	
	tmpt = Ds2174Regs.TAP3;
	//tmp = 0x00;
//	for(;;)
	
	MDelay(150000l);

 
 //   tmp = 0;
	Ds2174Regs.TEST = 0;
	tmpt = Ds2174Regs.TEST;
	
	
	
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::SetRs449, "ExtFuncs")
#endif	
extern "C" void ExDt::SetRs449(unsigned char state)
{
	if(!state) //off
	{
	//b1 and a5 are setted before
	 GpioDataRegs.GPBSET.all = 0x0001; //b0 set to one b1
//	 GpioDataRegs.GPASET.all = 0x0020; //a5 seeted before
	}
	else //oh
	{
	//b1 and a5 are setted before
	 GpioDataRegs.GPBCLEAR.all = 0x0001; //b0 to zero
	}
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadXILR0, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadXILR0()
{
	unsigned char tmp = 0;
//  tmp = ... some from state regs	
	if(!Timing.Value) {tmp |= 0x1;} // slave
	if(PolRtData.Value) {tmp |= 0x8;}// rt invert
	if(PolRdData.Value) {tmp |= 0x20;}// rd invert
	if(PolSdData.Value) {tmp |= 0x10;}// sd invert
	if(PolTtData.Value) {tmp |= 0x80;}// tt invert --new
	//	else {tmp &= 0xf7;} //
	ExpertRegs.XILR0 = tmp; //
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadXILR1, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadXILR1()
{
	unsigned char tmp = 0;
	unsigned char tmp1 = 0;
	if(ClkNumber.Value < 10000001l) {tmp |= 0x2;}//connect clocks directly
	else {tmp &= 0xfd;}	   //connect clocks *4
	switch(InType.Value)
	{
	case 0: tmp |= 0x4; break;
	case 1: tmp |= 0x8; tmp1 = 1;break; //rs449 - on
	case 2: tmp |= 0x10; break;
	case 3: tmp |= 0x20; tmp1 = 1; break; //rs449 +TTL
	default : break;
	}
//  tmp = ... some from state regs	
	SetRs449(0); //rs449 off ALWEIS before operate lvds to not conflict to lvds
	ExpertRegs.XILR1 = tmp; //hirer can be getted lvds on
	SetRs449(tmp1); //set required value 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadXILR2, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadXILR2()
{
	unsigned char tmp = 2; //to not reset cp2200
//		ExpertRegs.XILR2 = 0x1;
	if(UsedExp.State.Reg1.bit.Zumm) tmp |= 0x1; //hier can block zummer
//  tmp = ... some from state regs	
	ExpertRegs.XILR2 = tmp; //zummer on - temporary hier
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::GetData, "ExtFuncs")
#endif	
extern "C"  void ExDt::GetData()
{

	float64 ret = 0;
	Uint32 accum;
	unsigned char tmp;
//___________________________
//	tmp = 0; //need make from state!
//	Ds2174Regs.CONT4 = tmp;
//	tmp |= 0x4; //set count bit to read errors
//	Ds2174Regs.CONT4 = tmp;
//__________________________________	
	tmp = Ds2174Regs.STATUS;
	SetStatus(tmp);
//__________________________________	
	if(State.Reg1.bit.Sync && State.Reg1.bit.Start)
	{
	tmp = 0; //make from state !
	if(!SynceData.Value) tmp |= 0x80; //autoresync disabled
	if(LoopData.Value) tmp |= 0x10; //loop enabled 
	Ds2174Regs.CONT1 = tmp;
	MDelay(2000l);	
	tmp |= 0x20; //set lc
	Ds2174Regs.CONT1 = tmp;
	MDelay(2000l);
//	tmp &= 0xDF; //clear lc
//	Ds2174Regs.CONT1 = tmp;	
//	MDelay(150000l);
//___________________________
	tmp = 0; //need make from state!
	Ds2174Regs.CONT4 = tmp;
	MDelay(2000l);
//__________________________________	
	accum = 0l;
	ret += (float64)Ds2174Regs.CNT5 *(float64)(2147483648l)*(float64)(512l); //2^32
	ret += (float64)Ds2174Regs.CNT4 *(float64)(2147483648l) * (float64)(2l); //2^32
//	for(;;)
//	{
	accum += Ds2174Regs.CNT3;
	accum <<= 8;
	accum += Ds2174Regs.CNT2;
	accum <<= 8;	
	accum += Ds2174Regs.CNT1;
	accum <<= 8;
	accum += Ds2174Regs.CNT0;
	if((!State.Reg1.bit.Sync) or //led "RLoss" on
	(State.Reg1.bit.All1s) or  //led "all1s" on
	(State.Reg1.bit.All0s)) //led "all0s" on	
	{}
	else
	{VolNumber.Value += (float64)accum + ret;}
//	}
//_____________________________________	
//___________________________
	tmp = 4; //need make from state!
	Ds2174Regs.CONT4 = tmp;
	MDelay(2000l);
//__________________________________	
	accum = 0l;
	ret = 0;
	ret += (float64)Ds2174Regs.CNT5 *(float64)(2147483648l)*(float64)(512l); //2^32
	ret += (float64)Ds2174Regs.CNT4 *(float64)(2147483648l) * (float64)(2l); //2^32
	accum += Ds2174Regs.CNT3;
	accum <<= 8;
	accum += Ds2174Regs.CNT2;
	accum <<= 8;	
	accum += Ds2174Regs.CNT1;
	accum <<= 8;
	accum += Ds2174Regs.CNT0;
	if((!State.Reg1.bit.Sync) or //led "RLoss" on
	(State.Reg1.bit.All1s) or  //led "all1s" on
	(State.Reg1.bit.All0s)) //led "all0s" on	
	{}
	else	
	{ErrNumber.Value += (float64)accum + ret;}
	} //in sync
	else
	{
//	ErrNumber.Value = 0l;
//	VolNumber.Value = 0l;
	}
//_____________________________________	
//	ret = (float64)accum;
	
//	return ret;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 061006
	tmp = 0;
	
	switch(InsBerData.Value)
	{
		case 0: 	break;    //None
		case 1: 	tmp |= 1; break;//10^-1
		case 2: 	tmp |= 2; break;//10^-2
		case 3: 	tmp |= 3; break;//10^-3
		case 4: 	tmp |= 4; break;//10^-4
		case 5: 	tmp |= 5; break;//10^-5
		case 6: 	tmp |= 6; break;//10^-6
		case 7: 	tmp |= 7; break;//10^-7
		default:	break;
	}
		MDelay(2000l);
		tmp |= 0x30; //set this bit to 1 to check  "self inversion"
	Ds2174Regs.CONT2 = tmp;
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ExDt::LoadDDS, "ExtFuncs")
#endif	
extern "C" void ExDt::LoadDDS()
{
//DFase = (Fout * SystemClock) /(2^32)
//divide to 2^32 is shifting to 32 bits right
float64 DFase = ((ClkNumber.Value * 0x800000l) /234375l); //120 MHz / 2^9 = 234375
//float64 DFase = ((ClkNumber.Value * 0x1000000l * 6l) /234375l); //20 MHz / 2^9 = 234375
Uint32 LFase = DFase; 
	if(ClkNumber.Value >= 10000001l){LFase >>= 2;} //is connect through *4
// GpioDataRegs.GPBTOGGLE.all         = 0x001c;
//d2 - FQdds
//d3 - clkdds
//d4 - datadds
	GpioDataRegs.GPBCLEAR.all = 0x000C; // clk and fq to zero
//start serial mode	
	GpioDataRegs.GPBTOGGLE.all = 0x0008; //clk set
	GpioDataRegs.GPBTOGGLE.all = 0x0008; //clk clear
	GpioDataRegs.GPBTOGGLE.all = 0x0004; //fq set
	GpioDataRegs.GPBTOGGLE.all = 0x0004; //fq clear
//start serial mode	
	for(int i = 0; i < 32; i++) 
	{
		if(LFase & 0x1l) 
		{
		GpioDataRegs.GPBSET.all = 0x0010; //set data
		}
		else
		{
		GpioDataRegs.GPBCLEAR.all = 0x0010; //clear data
		}
		GpioDataRegs.GPBTOGGLE.all = 0x0008; //setclk
//		MDelay(100l);
		GpioDataRegs.GPBTOGGLE.all = 0x0008; //clearclk
		LFase >>= 1;
	}
	//one bit for use x6
	GpioDataRegs.GPBSET.all = 0x0010; //set data
//	GpioDataRegs.GPBCLEAR.all = 0x0010; //to test data
	GpioDataRegs.GPBTOGGLE.all = 0x0008; //setclk
//	MDelay(100l);
	GpioDataRegs.GPBTOGGLE.all = 0x0008; //clearclk
	//seven bits for phase , power up and setted zero
	GpioDataRegs.GPBCLEAR.all = 0x0010; //clear data
	for(int i = 0; i < 14; i++)  //13 - work!
	//if first time 15 next 14 - work!
	{
	GpioDataRegs.GPBTOGGLE.all = 0x0008; //set and clear clk
//	MDelay(100l);
	}
	GpioDataRegs.GPBSET.all = 0x0004; //set fq
//	GpioDataRegs.GPBTOGGLE.all = 0x0008; //set  clk
//	GpioDataRegs.GPBTOGGLE.all = 0x0008; //clear  clk
}
//_________end of file