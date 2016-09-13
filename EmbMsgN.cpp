//file EmbMsgN.cpp

struct EmbMsgN
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[ MAX_LEN];
	unsigned char STARTN()		{   return body[0]; 			}
	unsigned char Cycle()	{   return body[1]; 			}
	unsigned short AddrI()	{	return body[3]  + (body[2]<<8);}		// 2
	unsigned short AddrS()	{	return body[5]  + (body[4]<<8);}		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);}		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;}
 	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}
 	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }
	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return  MAX_LEN-counter; }
	int short IsEnd();
	int short IsEndOfHeader();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned short ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }
	void SetDir(unsigned char d) { dir= d; } // dir = 1 пришел с West, dir=2 прищел с East
	void Copy(EmbMsg m);
//__________________________________________________________________
	unsigned char ParseN(void);
	void SendAns(void);
	void SetCommandN(unsigned long);
	void RunCommandN1(void);
	void RunCommandN2(unsigned short);
	void RunCommandN3(unsigned char);
	void RunCommandN4(void);
	void RunCommandN5(unsigned char);
	void RunCommandN6(unsigned char);
	void RunCommandN7(unsigned char);
	void RunCommandN8(unsigned char);
	void RunCommandN80(unsigned short, unsigned short,unsigned short,unsigned short,unsigned short);

//	void SetStartAns(void);
//	void SetStopAns(void);
	unsigned long GetAnsLen(void){return current_posa;}
	unsigned char GetAns(unsigned long pos){return ans[pos];}
    void AddToAns(unsigned char);
	void AddToAnsDirect(unsigned char);

	unsigned char ChkCRCN(unsigned long);
//	void SetFreqN(unsigned short);
//	void SetAttN(unsigned char);

	unsigned long current_posr;
	unsigned long current_posw;
	unsigned char parsed_now;
	unsigned char ans[MAX_LEN];
	unsigned long current_posa; //answer
	unsigned char alarm;
 //	unsigned char lock;
//	unsigned char flagatt;
//	unsigned short curFreq;
//	unsigned char curAtt;
//	unsigned char curLev;

//___________________________________________________________________
};
//___________________________________________


extern "C" void SetFreqN(void);
extern "C" void SetFreqN80(unsigned char, unsigned char,unsigned char,unsigned char,unsigned char);

extern "C" void SetAttN(void);
extern "C" void SetAtt7N(void);
extern "C" void SetAtt8N(void);



unsigned char GetLevN(void);
unsigned char GetAttN(void);
unsigned char GetAtt2N(void);
unsigned char GetAtt3N(void);

unsigned short GetFreqN(void);
unsigned short GetLockN(void);
unsigned char GetAlarmN(void);
extern "C" unsigned char GetAddrN(void);
extern "C" void SetAddrN(unsigned char);


void TransN(unsigned char);

void EmbMsgN::AddToAnsDirect(unsigned char data)
{
//if(GetTestMode() == 0x50)
//{
  //	printf("\n\rans+> %02X", data);
//}

   ans[current_posa++] = data;
}


void EmbMsgN::AddToAns(unsigned char data)
{

//if(GetTestMode() == 0x50)
//{
//	printf("\n\rans+> %02X", data);
//}

 				if(current_posa < (MAX_LEN - 1))
				switch(data)
				{
								case 0x5A:  ans[current_posa++] =0x5A;  ans[current_posa++] =0x00; break;
								case 0x55: ans[current_posa++] =0x5A;  ans[current_posa++] =0x01; break;
								case 0xA5: ans[current_posa++] =0x5A;  ans[current_posa++] =0x02; break;
								case 0xAA: ans[current_posa++] =0x5A;  ans[current_posa++] =0x03; break;
								default: ans[current_posa++] = data;
				}
}


unsigned char EmbMsgN::ChkCRCN(unsigned long pos)
{
 unsigned char crc = 0;
 unsigned long i;
//  printfp("\n\r");
 for(i = pos;	i < (pos + body[pos + 1] + 2); i++)
{
  crc += body[i];
 // printf("i : %d  body[i] %0x%02X", i, body[i]);
// printfpd(" %02X", body[i]);
}
 crc += 1;
//  printfpd("> %02X", crc);

// if(GetTestMode() == 0x50)
//{
 	      //	printf("_%02X", byte);	  //test
//			printf("crc = 0x%02X", crc);
//}

 //printf("crc = 0x%02X", crc);
//   printfpd("? %02X", body[i]);
 if(crc  == body[i])
  {
   //	  	if(GetTestMode() == 0x50)
   //	  		{
 	//     	printf("_%02X", byte);	  //test
   	//  		printf("\n\rOk! = 0x%02X", crc);
	// 		}
//   printfp("ok");
  return 1; 
  }

 else
  {
//   printfp("bad");

  //	if(GetTestMode() == 0x50)
  //			{
 	      //	printf("_%02X", byte);	  //test
  	  //		 printf("\n\rBad! crs = 0x%02X i : %d body = 0x%02X", crc,i, body[i]);
  	//		}
 // return 0;
   return 1; //temporary

  }
}



void EmbMsgN::RunCommandN1(void)
{
// if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN1");
//}
unsigned char curcrc = 0; 

//AddToAns(MY_ADDRESS);
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += MY_ADDRESS;
AddToAns(COMM1_LEN);
curcrc += COMM1_LEN;
AddToAns(COMMANDN1);
curcrc += COMMANDN1;
AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN2(unsigned short freq)
{
static long cnt = 0l;
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN2");
//}
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM2_LEN);
curcrc += COMM2_LEN;
AddToAns(COMMANDN2);
curcrc += COMMANDN2;
#ifdef	 TEST_PRM_PCH_N_2
 //	printf("\n\r oldfreq = %d freq = %d",emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ,freq);
#endif //TEST_PRM_PCH_N_2

//______________________________________________________
	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
//091202	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
#ifdef PRM_N_KEEP_FREQ
 		   SetNeedWriteDevId();
#endif     // PRM_N_KEEP_FREQ
//______________________________________________________




SetFreqN();
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }
//	  delay1 = ZERO_DELAY;	//to send immediatly
 //	while((time1-timerun) < (unsigned long)RUN_TIME)
	while((time1-timerun) < (unsigned long)RUN_TIME_N)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }


AddToAns(GetLockN());
curcrc += GetLockN();
AddToAns(curcrc+1);
}


void EmbMsgN::RunCommandN80(unsigned short b0,unsigned short b1,unsigned short b2,unsigned short b3,unsigned short b4)
{
static long cnt = 0l;
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN2");
//}
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM80_LEN);
curcrc += COMM80_LEN;
AddToAns(COMMANDN80);
curcrc += COMMANDN80;
//______________________________________________________
 //	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
//091202	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
//	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
//#ifdef	   PROG_PRM_PCH_L
// 		   SetNeedWriteDevId();
//#endif     // PROG_PRM_PCH_L
//______________________________________________________

SetFreqN80(b0, b1, b2, b3, b4);
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }
//	  delay1 = ZERO_DELAY;	//to send immediatly
	while((time1-timerun) < (unsigned long)RUN_TIME_N)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }


AddToAns(RUN_OK);
curcrc += RUN_OK;
AddToAns(curcrc+1);
}

//_________________________________________________________
/*
void RunCommandN2(unsigned short freq)
{
static long cnt = 0l;
//printf("\n\rRunCommandN2");
unsigned char curcrc = 0; 

//______________________________________________________
	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L
//______________________________________________________

SetFreqN();
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }

	while((time1-timerun) < (unsigned long)RUN_TIME)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
 //if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }
}

*/



//_________________________________________________________




void EmbMsgN::RunCommandN3(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM3_LEN);
curcrc += COMM3_LEN;
AddToAns(COMMANDN3);
curcrc += COMMANDN3;
//________________________________________
	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; //MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");
//printfpd(" %X", att);
//_______________________________________
 SetAttN();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME_N)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}

//___________________________________________________________________100330
void EmbMsgN::RunCommandN7(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM7_LEN);
curcrc += COMM7_LEN;
AddToAns(COMMANDN7);
curcrc += COMMANDN7;
//________________________________________
	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2 = att; //MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

// printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>n7");
//printfpd(" %X", att);
//_______________________________________
 SetAtt7N();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME_N)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN8(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM8_LEN);
curcrc += COMM8_LEN;
AddToAns(COMMANDN8);
curcrc += COMMANDN8;
//________________________________________
   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3 = att;//MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N8");
//printfpd(" %X", att);
//_______________________________________
   SetAtt8N();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME_N)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}


//___________________________________________________________________100330




/* 100330

void EmbMsgN::RunCommandN4()
{

//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN4");
//}

unsigned short curLev = GetLevN();
unsigned char curAtt = GetAttN();
unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(COMMANDN4);
curcrc += COMMANDN4;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xff);  
curcrc += curFreq& 0xff;

AddToAns(curAtt);
curcrc += curAtt;
AddToAns(curLev);
curcrc += curLev;
//______________________________________
AddToAns(Rej);
curcrc += Rej;

AddToAns(Filtr);
curcrc += Filtr;
//_______________________________________


AddToAns(curcrc+1);
}

 */

void EmbMsgN::RunCommandN4()	 //100330
{

//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN4");
//}

unsigned short curLev = GetLevN();
unsigned char curAtt =  GetAttN();
unsigned char curAtt2 = GetAtt2N();
unsigned char curAtt3 = GetAtt3N();

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");
//printfpd(" %X", curAtt);
//printfpd(" %X", curAtt2);
//printfpd(" %X", curAtt3);
//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");


unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(COMMANDN4);
curcrc += COMMANDN4;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xff);  
curcrc += curFreq& 0xff;

AddToAns(curAtt);
curcrc += curAtt;
//AddToAns(curLev);
//curcrc += curLev;
//______________________________________
//AddToAns(Rej);	 //?
//curcrc += Rej;	 //?

AddToAns(Filtr);
curcrc += Filtr;
//_______________________________________
AddToAns(curAtt2);
curcrc += curAtt2;
AddToAns(curAtt3);
curcrc += curAtt3;


//_______________________________________
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN5(unsigned char rej)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN5");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM5_LEN);
curcrc += COMM5_LEN;
AddToAns(COMMANDN5);
curcrc += COMMANDN5;
//________________________________________
 //	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 //		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

 Rej = rej; //set global rejektor
//_______________________________________
// SetAttN();
 SetFreqN();
// delay1 = ZERO_DELAY;	//to send immediatly

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME_N)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);

}

void EmbMsgN::RunCommandN6(unsigned char filtr)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN6");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM6_LEN);
curcrc += COMM6_LEN;
AddToAns(COMMANDN6);
curcrc += COMMANDN6;
//________________________________________
 //	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 //		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

 Filtr = filtr; //set global filtr
//_______________________________________
// SetAttN();
 SetFreqN();
// delay1 = ZERO_DELAY;	//to send immediatly

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME_N)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);

}






void EmbMsgN::SetCommandN(unsigned long pos)
{
 switch(body[pos++])
 {

  case 1	: RunCommandN1(); break;
  case 2	: RunCommandN2((body[pos] << 8) + body[pos +1]); break;
  case 3	: RunCommandN3(body[pos]); break;
  case 4	: RunCommandN4(); break;
  case 5	: RunCommandN5(body[pos]); break;
  case 6	: RunCommandN6(body[pos]); break;
  case 7	: RunCommandN7(body[pos]); break;
  case 8	: /* 111012 RunCommandN8(body[pos]); */  break;
  case 0x80	: RunCommandN80(body[pos],body[pos+1],body[pos+2],body[pos+3],body[pos+4]); break;

  default 	: break;
 }
}

unsigned char EmbMsgN::ParseN(void)
{
parsed_now = 1;
unsigned long current_posr = 0;
unsigned long len;
unsigned char flag = 0;
//printf("\n\r 1");
// TransN('1');
//printf("\n\r>%d  - %d ",current_posr, current_posw);
 while(current_posr < current_posw)
 {
 // current_posr++;
 //printf(" %02X", body[current_posr++]);
// if(GetTestMode() == 0x50)
//{
// printf("\n\r 1");
//}
 //	if(0)
// TransN(body[current_posr]);
   if(body[current_posr++] ==  START_COMMAND)
   {
//if(GetTestMode() == 0x50)
//{
//printf(" 2");
//}
//TransN('2');

	len = body[current_posr + 1];
	if(body[current_posr] & MASK_REQUEST)
	{
//if(GetTestMode() == 0x50)
//{
//  printf(" 3");
//}
//TransN('3');
     if(((body[current_posr] & 0x7F) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
 //    if(((body[current_posr] & 0x7F) == (unsigned char)GetUSARTRem()) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))

     {
// if(GetTestMode() == 0x50)
//{
//printf(" 4");
//}
//TransN('4');
 	   if(ChkCRCN(current_posr))	  //now in current_posr is addr
 //	   if(1)
	   {
 //		printf("C");
//TransN('5');
	     flag = 1;
   //	     SetStartAns();
         SetCommandN(current_posr + 2);
	   }   //crc
     }	  //address
	 else	//address
	 {
//printf(" addr = 0x%02X" , body[current_posr]); //for debug
	 }
	} //Mask_request
	 else	//address
	 {
 //     printf("m"); //for debug
	 }

	  current_posr += len + 2;
	  if(current_posr > MAX_LEN) break;
   }  //start
 }	//while
 //if(flag)
 //{
 // SetStopAns();
//  SendAns();
// }
 // Init();
parsed_now = 0;  
 return flag;	 
} 
//____________________________________


void EmbMsgN::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsgN::Init()
{
	counter=0;
//t  for(int i=0; i<MAX_LEN; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
//___________________________________________
 current_posr = 0;
 current_posw = 0;
 parsed_now = 0;
 current_posa = 0;
//t for(i=0; i<MAX_LEN; i++) ans[i]=0;
// alarm = 0;
// lock = 0;
// flagatt = 0;
}

unsigned short EmbMsgN::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned short EmbMsgN::Add(unsigned char byte)
{
//_______________________________________
//t  if(parsed_now) return 0;
//_______________________________________ 
  if(counter<MAX_LEN)
	{
//________________________________
		current_posw++;
//________________________________
		body[counter++]=byte;
		return 1;
	}
	else
	    return 0;
}

int short EmbMsgN::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsgN::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned short EmbMsgN::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
 		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
}

unsigned short EmbMsgN::CalcCRC()
{
  int i;
	unsigned c=0;
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			body[Length()+11]=(c>>8)&0xFF;
			body[Length()+12]=c&0xFF;
			return c;
		}
		else return 0;
 } 
