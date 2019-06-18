//remote.cpp
#include "remote.h"
#include "menu.h"
#include <string.h>

extern "C" void ResetWD();

#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(GetRem, "ExtFuncs")
#endif	
extern "C" void GetRem(unsigned char ToRem)
	{
	UsedRemote.Receive(ToRem);
	}
/*
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::ReadChar, "ExtFuncs")
#endif	
extern "C" char Remote::ReadChar()
{
static char ret;
//char * pret;
//	pret = &ret;
//to test	
static	char retstr[] = "return string#00B1;N02;C012345678;B2;B3;B9;B5.";//tstatic	char retstr[] = "return string#00B1;N0;C0;B2;B3;B5.";
//static	char retstr[] = "return string#00B1;C0;B2;B3;B5.";
static	char* pretstr = &retstr[0];
//	pretstr = &retstr[0];
	ret = *pretstr;
	pretstr++;
	if((ret == '\0') || (pretstr == 0)) 
	{
	pretstr = &retstr[0];
	}
//		pretstr++;
	ret = *pretstr; 
//to test
return ret;	
}
*/
#ifdef __cplusplus
#pragma CODE_SECTION("ExpertFuncs")
#else
#pragma CODE_SECTION(Remote::Remote, "ExpertFuncs")
#endif	
extern "C" Remote::Remote()
{
	RBuffSize = 128; //as in .h file
//	for (int i = 0; i < RBuffSize; i++)
//	{
	 RBuff[0] = 0;
//	}
	pRBuff = &RBuff[0];
	TBuffSize = 128; //as in .h file
//	for (int i = 0; i < TBuffSize; i++)
//	{
	 TBuff[0] = 0;
//	}
	pTBuff = &TBuff[0];	
	IdCommand = 0;
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::ParseBuffer, "ExtFuncs")
#endif	
extern "C" void Remote::ParseBuffer(char *pStart, const char *razd)
{
	char *p;
	p = strtok(pStart, razd);
	if(p) RunCommand(p);
	do {
	p = strtok('\0', razd);
	if(p)
	{
	 RunCommand(p);
	 }
	} while(p);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::ReplacePC, "ExtFuncs")
#endif	
extern "C" void Remote::ReplacePC()
{
 			pTBuff = &TBuff[0];
 			do
 			{
 			if(*pTBuff == '.') *pTBuff = ',';
 			}
 			while(*pTBuff++);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::Receive, "ExtFuncs")
#endif	
//extern "C" void Remote::Receive()
extern "C" void Remote::Receive(unsigned char SetOpChar)
{
	static char step = 0;
	static int16 CommandSize = 0;
//	char OpChar = ReadChar();
	char OpChar = SetOpChar;
//	ResetWD();
	if (step == 0) //need wait '#'
	{
//		ResetWD();
		if(OpChar == '#') 
		{
		CommandSize = 0; //start command
		step = 1;
		pRBuff = &RBuff[0];	
		}
	}
	else if (step == 1) // need wait property address
	{
		//need make address class
		if(OpChar == '0') //temporary first digit of address
		{
			step = 2;
		}
		else //bad addr
		{
			pRBuff = &RBuff[0];
			step = 0;
		}
	}
	else if (step == 2) // need wait property address
	{
		//need make address class
		if(OpChar == '0') //temporary second digit of address
		{
			step = 3;
			pTBuff = &TBuff[0];
			*pTBuff++ = '%';
			*pTBuff++ = '0';//temporary first digit of address
			*pTBuff++ = '0';//temporary second digit of address
		}
		else //bad addr
		{
			pRBuff = &RBuff[0];
			step = 0;
		}
	}	
	else if (step == 3) // write and finished command
	{
		//need make address class
		if(OpChar == '.') //wait end command  
		{
			*pRBuff = '\0'; //to finish string in buffer
			pRBuff = &RBuff[0];
			ParseBuffer(pRBuff, theAnyStrings.cRazd);
		//hier need get off all points from string (1.<- this points222e11)
	//t		pTBuff--;
	//t		strcpy(pTBuff++, theAnyStrings.cPoint); 
			*pTBuff = '\0'; //	
	    	ReplacePC();
			pTBuff--;
			pTBuff--;
			strcpy(pTBuff++, theAnyStrings.cPoint); 
			*pTBuff = '\0'; //					
			Transmit();
			pTBuff = &TBuff[0];
			pRBuff = &RBuff[0];
			step = 0;
		}
		else if(OpChar == '#') //wait  start new command if previons command is lost
		{
			pRBuff = &RBuff[0];
			*pRBuff++ = OpChar;
			step = 1;
		}
		else //write command to buffer
		{
			CommandSize++;
			if(CommandSize < RBuffSize)
			{
			*pRBuff++ = OpChar;
			}
			else
			{
			pRBuff = &RBuff[0];
			step = 0;			
			}
		}		
	}	
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::SendChar, "ExtFuncs")
#endif	
extern "C" void Remote::SendChar(char* pSend)
{

unsigned long tmp, cnt;
cnt = 0l;
do{ tmp = SciaRegs.SCICTL2.bit.TXRDY;
 cnt++;}
while((!(tmp)) && (cnt < 10000l));
SciaRegs.SCITXBUF = *pSend;
//hier need operate widch controller registers to send char 
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::Transmit, "ExtFuncs")
#endif	
extern "C" void Remote::Transmit()
{
			pTBuff = &TBuff[0];
			do
			{
			SendChar(pTBuff);
			}
			while(*pTBuff++);
}
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Remote::RunCommand, "ExtFuncs")
#endif	
extern "C" void Remote::RunCommand(char * pCommand)
{
	IdCommand = 0;
	CommandData.RunRemoteV(pCommand);
	ClkNumber.RunRemoteC(pCommand, 10); 
	RemNumber.RunRemoteC(pCommand, 10); 
	VolNumber.RunRemoteI(pCommand); 
	ErrNumber.RunRemoteI(pCommand); 
	BerNumber.RunRemoteI(pCommand); 
	LossNumber.RunRemoteI(pCommand); 
	InsBerData.RunRemoteV(pCommand); 
	PolRtData.RunRemoteV(pCommand); 
	PolRdData.RunRemoteV(pCommand); 
	PolSdData.RunRemoteV(pCommand); 
	PolTtData.RunRemoteV(pCommand); 
	RemBits.RunRemoteV(pCommand);
	RemParity.RunRemoteV(pCommand);
	Timing.RunRemoteV(pCommand); 
	SynceData.RunRemoteV(pCommand);
	LoopData.RunRemoteV(pCommand);
	InType.RunRemoteV(pCommand); 
	PatType.RunRemoteV(pCommand); 
	SpiData.RunRemoteC(pCommand, 16); 
	SpiCs.RunRemoteC(pCommand, 16); 
	LEDData.RunRemoteC(pCommand, 16); 
	VCC18Number.RunRemoteI(pCommand);
	
	if(!IdCommand) //not property command
	{
		strcpy(UsedRemote.pTBuff, theAnyStrings.cK1); 
		for(int16 i = strlen(theAnyStrings.cK1); i > 0; i--)
		{
		UsedRemote.pTBuff++;
		}
		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd);	
	}
//	pTBuff--; //replace ';' to '.'
//	strcpy(pTBuff, theAnyStrings.cPoint); 
}
//___________end of file
