//disp.cpp
#include "disp.h"
#include "cs8900.h"
#include "expdata.h"
//#include "remote.h"
extern "C" void DelayUs(Uint16);
extern "C" void ResetWD(void);
#ifdef __cplusplus
//#pragma CODE_SECTION(".text:CSL_cfgInit")
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(MDelay, "ExpertFuncs")
//#pragma CODE_SECTION(CSL_cfgInit,".text:CSL_cfgInit")
#endif
extern "C" void MDelay(unsigned long i)
{
	i /= 5l;
	while(i) 
	{		i--; 
			ResetWD();
	}
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(ins_disp, "ExtFuncs")
//#pragma CODE_SECTION(CSL_cfgInit,".text:CSL_cfgInit")
#endif

//Uint16 t; //for test

extern "C" void ins_disp(char i)
{
/*
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	*/
//	MDelay(1000l);
//	MDelay(100000l);
 //	PieCtrlRegs.PIECRTL.bit.ENPIE = 0;	// Disable the PIE
	MDelay(1000l);
	ExpertRegs.DINS = i;
	MDelay(1000l);
//	MDelay(300l);
//	PieCtrlRegs.PIECRTL.bit.ENPIE = 1;	// Enable the PIE
//	MDelay(1000l); //work
//	MDelay(500l); //work
//	MDelay(200l);
//	MDelay(100l); //work!
//	MDelay(50l);  //not work!	
//	MDelay(10l); //not work!
//  outportb(dins,i);
//  while(inportb(dins)&0x80); my 080200
//  for(long idelay = 0; idelay <= 10000; idelay++)    //my 080200
//     long i1 = 0L;
//t -not need for simulator     while (i1 < 100L) i1 ++;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(_setcursortype, "ExpertFuncs")
#endif
extern "C" void _setcursortype(Uint16 t)
 {
 ins_disp(t == 1 ? 0xF : 0xC); //t == 1 : on blinking cursor
 }
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(gotoxy, "ExpertFuncs")
#endif
extern "C" void gotoxy(Uint16 x, Uint16 y)
 {
 ins_disp(0x38);//to not get off display to future need use ready signal
 //MDelay(1000l);
 if((!y) || (y > 2))  { y = 1;}
 if((!x) || (x > 16)) { x = 1;}
 ins_disp((char)((x-1) | (y == 2 ? 0xC0 : 0x80)));
 //MDelay(1000l);
 }
#ifdef __cplusplus
//#pragma CODE_SECTION(".text:CSL_cfgInit")
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(fill_disp, "ExpertFuncs")
//#pragma CODE_SECTION(CSL_cfgInit,".text:CSL_cfgInit")
#endif
extern "C" int fill_disp(const char *s)
 {
    register const char *sptr;
    sptr = s;
    while(*sptr)
     {
     	//DelayUs(9000);
  //   	MDelay(100000l);
 // 	PieCtrlRegs.PIECRTL.bit.ENPIE = 0;	// Disable the PIE
  		MDelay(1000l);
     	ExpertRegs.DDRAM = *sptr;
     //t	MDelay(5000l);
     //t	MDelay(1000l);
     	MDelay(1000l);
 //   PieCtrlRegs.PIECRTL.bit.ENPIE = 1; 	
//        outportb(ddram, *sptr);
//        while(inportb(dins) & 0x80); my 080200
//     long i1 = 0L;
//t - not need for simulator     while (i1 < 100L){ i1 ++;} //delay
        sptr++;
     }
    return sptr - s;
 }
 
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(cprintf, "ExtFuncs")
#endif  
extern "C" int cprintf(char const near *form, ...)
 {
  int iRet;
 	if(!UsedExp.State.Reg1.bit.Frozen)
 	{
    static char cStr[17];
    va_list arglist;
    va_start(arglist, form);
    iRet = vsprintf(cStr, form, arglist);
    fill_disp(cStr);
    va_end(arglist);
    }
    return iRet;
 }
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(cprintL, "ExpertFuncs")
#endif  
void printL( char x, char y, unsigned long LData)
 {
	gotoxy(x, y);
	cprintf("%15ld", LData);
 } 
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(InitDisp, "ExpertFuncs")
#endif 
extern "C" void InitDisp(void)
{
//recommend: 0x38, 0x38, 0x6, 0xe, 0x1
	ExpertRegs.LED = 0x00;//all on
	MDelay(1000000l);
	ins_disp(0x38);//2x8
	ins_disp(0x38);//t
	ins_disp(0x06);//t
//	ins_disp(0x0E);//t
	ins_disp(0x0C);//t
	ins_disp(0x01);//t
	ExpertRegs.LED = 0xfd;
//	
//t	ins_disp(0x1);//clear
//	DelayUs(7000);
//t	ins_disp(0x7);//shift
//	DelayUs(7000);
//t	ins_disp(0xC);//disp on, cur off, blink off
//	DelayUs(7000);
} 
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(Hello, "ExpertFuncs")
#endif	
extern "C" void Hello()
	{
	unsigned char tmp;
	unsigned char tmp1;
	ExCs8900.ADD0 = 0xff;
	ExCs8900.ADD1 = 0x0;
	tmp = ExCs8900.ADD0;
	tmp1 = ExCs8900.ADD1;
	
//	ins_disp(0xF); //blink
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	gotoxy(1, 1);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	ExpertRegs.DDRAM = 0x41;
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//	DelayUs(9000);
//t	cprintf("%7s", "Hello! ");
//t	gotoxy(1, 2);
//t	cprintf("%s", " How are You?   ");
//	ExpertRegs.DDRAM = 0x41;	
//	ExpertRegs.DDRAM = 0x42;
//	ExpertRegs.DDRAM = 0x43;
/*
	static char Hell[] = " Expert3 - klevo!";
	char* pHell;
	pHell = &Hell[0];
	fill_disp(pHell);
	*/
//tt	static char cnt = 0;
//tt	static char cnt1 = 0;
//tt	static char cnt2 = 0;
//tt	cnt2++;
//	cnt++;
//tt	if (Hell[cnt] == 0) {cnt = 0; //cnt2 = 0;
//tt	cnt1++;
//	sprintf(pHell," %d", cnt1);
//tt	}
//	unsigned char Ping = ExpertRegs.KBDData & 0x3f;
//tt	if(cnt2 != 1)
//tt	{
//tt	cnt++;
//	ExpertRegs.DDRAM = Hell[cnt];
/*
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);	
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);	
	*/
//t	MDelay(100000l);
//tt	ExpertRegs.DDRAM = Hell[cnt];	
//	ExpertRegs.DDRAM = 0x42; //symbol 'B' - view as command!!
//	MDelay(1000000l); //work
//	MDelay(100000l); //work
//	MDelay(10000l); //work!
//	MDelay(1000l); //work!
//t	MDelay(100l); //work!
//t	MDelay(10l);  //work!
//t	MDelay(1l); //work
/*	
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);	
	*/
//	ExpertRegs.DDRAM = Hell[cnt];
//tt	cnt2 = 0;
//tt	}
//tt	else if(cnt2 == 1)
//tt	{
//	MDelay(1000000l);
//tt	ExpertRegs.DINS = 0x80; //first position
//	MDelay(1000000l);
//	MDelay(1000l);
//tt	}
//	ExpertRegs.DDRAM = cnt1;
/*
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);
	DelayUs(9000);		
	*/
//	ExpertRegs.DINS = 0x55;
//	ins_disp(0x38);//2x8
//	ExpertRegs.DDRAM = 0x55;
//	ExpertRegs.DINS  = 0xAA;
	}
//end of file