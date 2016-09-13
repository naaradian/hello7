//file prm_pch.cpp
#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include <mqx.h>
#include <bsp.h>
extern int ecount2;
unsigned char ascii[] = {
//0:	  
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xD5,0xDA,
0x20,0x20,0x32,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//32:
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x20,
//64:
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x20,0x5d,0x5e,0x20,
//96
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
//
//128:
0x20,0x20,0x27,0x20,0xca,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0xca,0xcb,0xdf,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//160:
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xfd,0xa2,0x20,0x20,0xc8,0x20,0x2d,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0xfe,0xdf,0xb5,0x20,0x20,0xc9,0x20,0x20,0x20,0x20,
//192:
0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,0xa8,
0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
//224:
0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,0xbe,
0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,0xc1,0xe6,0xc2,0xc4,0x62,0xc5,0xc6,0xc7
//256
};

void AsciiInit()
{
//0
for(int i = 0; i <= 14; i++)
{
 ascii[i] = 0x20;
}
ascii[15] = 0xD5;  ascii[16] = 0xDA; 

//16
ascii[17] = 0x20;	 ascii[18] = 0x20;	 ascii[19] = 0x32;
for(i = 20; i <= 33; i++)
{
 ascii[i] = 0x20;
}
for(i = 32; i <= 62; i++)
{
 ascii[i] = (i - 1);
}
 ascii[63] = 0x20;

for(i = 64; i <= 91; i++)
{
 ascii[i] = (i - 1);
}
ascii[92] = 0x20;	 ascii[93] = 0x5d;	 ascii[94] = 0x5e;	 ascii[95] = 0x20;
//96
for(i = 96; i <= 127; i++)
{
 ascii[i] = (i - 1);
}
//128
for(i = 128; i <= 129; i++)
{
 ascii[i] = 0x20;
}
ascii[130] = 0x27;	 ascii[131] = 0x20;	ascii[132] = 0xca;

for(i = 133; i <= 146; i++)
{
 ascii[i] = 0x20;
}

ascii[147] = 0xca; ascii[148] = 0xcb; ascii[149] = 0xdf;

for(i = 150; i <= 166; i++)
{
 ascii[i] = 0x20;
}

ascii[167] = 0xfd; ascii[168] = 0xa2;

for(i = 169; i <= 170; i++)
{
 ascii[i] = 0x20;
}
ascii[171] = 0xc8; ascii[172] = 0x20; ascii[173] = 0x2d;

for(i = 174; i <= 181; i++)
{
 ascii[i] = 0x20;
}

ascii[182] = 0xfe; ascii[183] = 0xdf; ascii[184] = 0xb5;

for(i = 185; i <= 186; i++)
{
 ascii[i] = 0x20;
}
ascii[187] = 0xc9;

for(i = 188; i <= 191; i++)
{
 ascii[i] = 0x20;
}
//192
ascii[192] = 0x41;	ascii[193] = 0xa0;	 ascii[194] = 0x42;	 ascii[195] = 0xa1;	
ascii[196] = 0xe0;	ascii[197] = 0x45;	 ascii[198] = 0xa3;	 ascii[199] = 0xc4;
ascii[200] = 0xa5;  ascii[201] = 0xa6;	 ascii[201] = 0x4b;	 ascii[203] = 0xa7;
ascii[204] = 0x4d;	ascii[205] = 0x48;	 ascii[206] = 0x4f;  ascii[207] = 0xa8;

ascii[208] = 0x50;	ascii[209] = 0x43;	 ascii[210] = 0x54;	 ascii[211] = 0xa9;
ascii[212] = 0xaa;	ascii[213] = 0x58;	 ascii[214] = 0xe1;	 ascii[215] = 0xab;
ascii[216] = 0xac;	ascii[217] = 0xe2;	 ascii[218] = 0xad;	 ascii[219] = 0xae;	 
ascii[220] = 0x62;	ascii[221] = 0xaf;	 ascii[222] = 0xb0;	 ascii[223] = 0xb1;
//224
ascii[224] = 0x61;	ascii[225] = 0xb2;	 ascii[226] = 0xb3;	 ascii[227] = 0xb4;
ascii[228] = 0xe3;  ascii[229] = 0x65;	 ascii[230] = 0xb6;	 ascii[231] = 0xb7;
ascii[232] = 0xb8;	ascii[233] = 0xb9;	 ascii[234] = 0xba;	 ascii[235] = 0xbb;
ascii[236] = 0xbc;	ascii[237] = 0xbd;	 ascii[238] = 0x6f;	 ascii[239] = 0xbe;

ascii[240] = 0x70;	ascii[241] = 0x63;	 ascii[242] = 0xbf;	 ascii[243] = 0x79;
ascii[244] = 0xe4;	ascii[245] = 0x78;	 ascii[246] = 0xe5;	 ascii[247] = 0xc0;
ascii[248] = 0xc1;	ascii[249] = 0xe6;	 ascii[250] = 0xc2;	 ascii[251] = 0xc4;	
ascii[252] = 0x62;	ascii[253] = 0xc5;	 ascii[254] = 0xc6;	 ascii[255] = 0xc7; 

}
union u2uc
{
    unsigned short u;
	unsigned char uc[2];
};
unsigned char HexChar(unsigned char s)
{
  if(s<=9) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 'x';
}
void ConvertToWin1251(char *str)
{
	int i=0;
	unsigned char ch;
  while(str[i])
	{
		ch=str[i];
		str[i]=ascii[ch];
		i++;
		if(i>=24)
		{
			str[i]=0; 
			return;
		}
	}
}
unsigned char Modify5A(unsigned char byte)
{
	switch(byte)
	{
		case 0x00: return 0x5A;
		case 0x01: return 0x55; 
		case 0x02: return 0xA5; 
		case 0x03: return 0xAA; 
		default: return 0;
	}

}
struct MsgStatus
{
	unsigned char readyToSend : 1;
	unsigned char isRS232 : 1;
	unsigned char isRS485 : 1;
	unsigned char reserved : 5;
};

union UnMsgStatus
{
	MsgStatus msgStatus;
	unsigned char byte;
};

struct TOM // [TRС00MEK]
{
	unsigned char K : 1; // K - признак получения пакета адресатом, устанавливается в "1" при получении пакета адресатом;
	unsigned char E : 1; // E - бит ошибки в CRC, устанавливается в "1" если не сходится CRC;
	unsigned char M : 1; // M - бит монитора, устанавливаемый в "1" при проходе кадром "активного монитора";
	unsigned char reserved : 2;
	unsigned char C : 1; // R - признак сообщение из RS-485 (был запрос маркера)
	unsigned char R : 1; // C - устанавливается в "1" если это запрос компьютера подключенного к станции.
	unsigned char T : 1; // T - бит маркера; 
//	TOM() { reserved=0; T=R=C=M=E=K=0; }
};

union UnTOM
{
	unsigned char byte;
	TOM tom;
};
//___________________________________________________________________________________
struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[270];
	unsigned char TOM()		{   return body[0]; 			}
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
	unsigned short IsFree() { return 270-counter; }
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
};

void EmbMsg::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsg::Init()
{
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
}

unsigned short EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned short EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
		return 1;
	}
	else
	  return 0;
}

int short EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsg::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned short EmbMsg::ChkCRC()
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

unsigned short EmbMsg::CalcCRC()
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

//___________________________________________________________________________________
#ifdef PROG_PRM_PCH_N

#define MAX_LEN	(270)

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

	void SetStartAns(void);
	void SetStopAns(void);
	unsigned long GetAnsLen(void){return current_posa;}
	unsigned char GetAns(unsigned long pos){return ans[pos];}
    void AddToAns(unsigned char);
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

#define START_COMMAND	(0xAA)
#define STOP_COMMAND	(0x55)
#define MY_ADDRESS		(0x01) //make in future
#define BRD_ADDRESS		(0xFF) //addr for all
#define MASK_REQUEST	(0x80)
#define	COMM1_LEN		(1)
#define	COMM2_LEN		(1)
#define	COMM3_LEN		(1)
#define	COMM4_LEN		(4)
unsigned char SetFreqN(unsigned short);
unsigned char SetAttN(unsigned char);
unsigned char GetLevN(void);
unsigned char GetAttN(void);
unsigned short GetFreqN(void);
unsigned short GetLockN(void);
unsigned char GetAlarmN(void);
void TransN(unsigned char);




void EmbMsgN::AddToAns(unsigned char data)
{
 if(current_posa < MAX_LEN)
 ans[current_posa++] = data;
}

void EmbMsgN::SetStartAns(void)
{
 AddToAns(START_COMMAND);
// ans[current_posa++] = MY_ADDRESS;
}

void EmbMsgN::SetStopAns(void)
{
 AddToAns(STOP_COMMAND);
}

unsigned char EmbMsgN::ChkCRCN(unsigned long pos)
{
 unsigned char crc = 0;
 unsigned long i;

 for(i = pos;	i < (pos + body[pos + 1] + 2); i++)
{
  crc += body[i];
//  printf("i : %d  body[i] %0x%02X", i, body[i]);
}
 crc += 1;
// printf("crc = 0x%02X", crc);
 if(crc  == body[i+1])
  return 1; //temporary
 else
  return 0;
}

void EmbMsgN::RunCommandN1(void)
{
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM1_LEN);
curcrc += COMM1_LEN;
AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN2(unsigned short freq)
{
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM2_LEN);
curcrc += COMM2_LEN;
SetFreqN(freq);
AddToAns(GetLockN());
curcrc += GetLockN();
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN3(unsigned char att)
{
unsigned char curcrc = 0; 
unsigned char flag;

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM3_LEN);
curcrc += COMM3_LEN;
flag = SetAttN(att);
AddToAns(flag);
curcrc += flag;
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN4()
{
unsigned short curLev = GetLevN();
unsigned char curAtt = GetAttN();
unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xf);  
curcrc += curFreq& 0xf;
AddToAns(curAtt);
curcrc += curAtt;
AddToAns(curLev);
curcrc += curLev;
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
// printf(" %02X", body[current_posr++]);
//printf("\n\r 1");
 //	if(0)
// TransN(body[current_posr]);
   if(body[current_posr++] ==  START_COMMAND)
   {
//printf(" 2");
//TransN('2');

	len = body[current_posr + 1];
	if(body[current_posr] & MASK_REQUEST)
	{
//printf(" 3");
//TransN('3');
     if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
     {
//printf(" 4");
//TransN('4');
 	   if(ChkCRCN(current_posr))	  //now in current_posr is addr
 //	   if(1)
	   {
// 		printf("C");
//TransN('5');
	     flag = 1;
	     SetStartAns();
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
 if(flag)
 {
  SetStopAns();
//  SendAns();
 }
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
 
#endif // PROG_PRM_PCH_N 
/////////////////////
#define   EmbMsgBuffer_Size (32)
struct EmbMsgBuffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
   EmbMsg Buff[EmbMsgBuffer_Size];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned short Used();
    unsigned short Free();
};

void EmbMsgBuffer::Init()
{
  BuffSize = EmbMsgBuffer_Size;
  Head = 0;
  Tail = 0;
}

void EmbMsgBuffer::Add(EmbMsg &msg)
{
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize)
  {
   
   Head = 0;
   }
}

void EmbMsgBuffer::Get(EmbMsg &msg)
{
  if(++Tail < BuffSize) 
	{
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[Tail-1].body[i];
	}
	else
	{
		Tail = 0;
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[BuffSize-1].body[i];
	}
}

unsigned short EmbMsgBuffer::Used()
{
  int n = Head - Tail;

  if( n >= 0 )
  {
    return n;
   }
  else
  {	 
   return n+BuffSize;
  }
}

unsigned short EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}
/////////////////////
struct Emb2TypeVer
{
	unsigned short type;
	unsigned short softVer;
	unsigned short ctrlNumber;
	unsigned short ctrlYear;
	unsigned short ctrlVer1;
	unsigned short ctrlVer2;
	unsigned char signature_hardware[16];
	unsigned char signature_software[16];
};

union UnEmb2TypeVer
{
	Emb2TypeVer emb2TypeVer;
	unsigned char byte[44];
};

struct StateBMD155
{
	unsigned char state;  // Бит 0: "0" - остутсвтие связи с ППУ1, "1" - норма
									// Бит 1: "0" - остутсвтие связи с ППУ2, "1" - норма
									// Бит 1: "0" - остутсвтие связи ПИ, "1" - норма
	unsigned char state2;  // Состояние платы интерфейсов
	unsigned char ppu1_bytes[16];
	unsigned char ppu2_bytes[16];														// 34
	unsigned long count_no_correct_block1;									// 42
	unsigned long count_no_correct_block2;									// 46
	unsigned long count_no_correct_result;									// 50
	unsigned long count_notRS1;															// 54
	unsigned long count_notRS2;															// 58
	unsigned long count_block;															// 62
	unsigned char mod; // Состояние платы интерфейсов       // 63
	unsigned char dem1; // Сососяние платы интерфейсов      // 64
	unsigned char dem2; // Состояние платы интерфейсов      // 65
	unsigned char state_dem1; // Состояние платы интерфейсов// 66
	unsigned char state_dem2; // Состояние платы интерфейсов// 67
	unsigned char statePI; // Состояние платы интерфейсов		// 68	
	unsigned char loopPI; // Состояние шлейфов							// 69
	unsigned char demPI; // Состояние демодуляторов					// 70
};

union UnStateBMD155
{
	StateBMD155 stateBMD155;
	unsigned char byte[72];
};
	
struct StatePUM
{
	unsigned char ver;						// 1   //0
	unsigned char reserv; 				// 2	   //1
	unsigned char reserv1;	 //my					// 1 //2
	unsigned char reserv2;	 //my						 //3
	unsigned long ulBlock;				// 6	 +2		  //4 5 6 7
	unsigned long ulErrOut;				// 10	 +2		 //8,9,10,11
	unsigned long ulErrAfterRS1;	// 14		 +2
	unsigned long ulErrAfterRS2;	// 18	    +2
	unsigned long ulErrBeforeRS1;	// 22	   +2
	unsigned long ulErrBeforeRS2;	// 26	   +2
	unsigned char state[16];			// 42	 +2
};

union UnStatePUM
{
	StatePUM statePUM;
	unsigned char byte[44];
};

struct Command
{
	unsigned char chan;
	unsigned char command;
	unsigned char par;
	unsigned char done;
};

struct Emb2NetStat
{
	unsigned long selfPacketSend; // 4
	unsigned long selfPacketRecv; // 4
	unsigned long allPacketRecv;  // 4
	unsigned short requestMarker; // 2
	unsigned short genMarker;     // 2
	unsigned short highID;        // 2
	unsigned short buffModPd;        // 2
	unsigned short buffModPm;        // 2
	unsigned short buffTransPd;        // 2
	unsigned short buffTransPm;        // 2
	unsigned short buff232Pd;        // 2
	unsigned short buff232Pm;        // 2
	unsigned short markerTime; //2 
	unsigned char ready_transit; //1 
	unsigned char ready_mod; //1 
};

union UnEmb2NetStat
{
	Emb2NetStat emb2NetStat;
	unsigned char byte[32];
};

struct LtDiod
{
	unsigned char alarmIn1		 : 1;	
	unsigned char alarmSync1  : 1; 	
	unsigned char alarmLevel1 : 1; 
	unsigned char alarmBoard1 : 1; 
	unsigned char alarmIn2		 : 1; 
	unsigned char alarmSync2  : 1; 
	unsigned char alarmLevel2 : 1; 
	unsigned char alarmBoard2 : 1; 	
}; 

union UnLtDiod
{
	unsigned char byte;
	LtDiod ltDiod;
};

struct BmdState
{
	unsigned char alarmIn1		: 1; 
	unsigned char alarmSync1 : 1; 
	unsigned char alarmIn2   : 1; 
	unsigned char alarmSync2 : 1; 
	unsigned char reserv			: 4; 
}; 

union UnBmdState
{
	unsigned char byte;
	BmdState bmdState;
};
////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0;
unsigned char tmpg;
unsigned long cntflag6;


void Callback0()
{
  time1++;
}

struct Emb5StatusGeterodin
{
//unsigned long number;
unsigned long frequ;
unsigned long get1;
unsigned long get2;
};

union uEmb5StatusGeterodin
{
 Emb5StatusGeterodin emb5statusgeterodin;
 unsigned char byte[12];
};


EmbTimerCallback embTimerCallback0;
EmbMsgBuffer rBuffEmbMsg;
EmbMsgBuffer tBuffEmbMsgWest;
EmbMsgBuffer tBuffEmbMsgEast;
EmbMsg embMsg232;
EmbMsg embMsg232E;
EmbMsg embMsgWest;
EmbMsg embMsgEast;
EmbMsg embMsgAns;
EmbMsg embMsgTemp;
EmbMsg *embMsgRequest;
EmbRS232 embRS232;
EmbRS485 embRS485;
EmbMsg embMsg485E;

EmbSerialMD34AVT embSerialACT155;

#ifdef PROG_PRM_PCH_N
EmbMsgN embMsg485;	//091113
#endif
 
	char ch;
	long f_len;
	unsigned char flagRequest=0;
//	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned long timerun;
	unsigned char breakflag;
	unsigned char breakflag4;
	unsigned char breakflag1;



#ifdef PRM_PCH_DEBUG1
	unsigned long time1start=0, time1finish=0;
#endif //PRM_PCH_DEBUG1

	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned long time1test=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];
    unsigned char * bt;
	unsigned short addr1;
	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
	unsigned char mode5A=0, mode5AWest=0, mode5AEast=0;
	unsigned char mode5A232E = 0;
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;
	unsigned char cycle=0;
	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned short err_tr=0;
	unsigned short err_md=0;
	UnStateBMD155 unStateBMD155;
	UnEmb2TypeVer unEmb2TypeVer; 
	UnStatePUM unStatePUM;
	UnEmb2NetStat unEmb2NetStat;
	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;
	long count_notRS1;
	long count_notRS2;
	long err_tmp;
	int rrr=0;
	int i232;
	unsigned short aI, aS, aR;
	UnLtDiod unLtDiod;
	UnBmdState unBmdState;
	unsigned long send41, send42, received1, received2, good1, good2, bad1, bad2;		//t
	unsigned char   setf1, setatt1, setf2, setatt2, modescan1, modescan2;
	signed long curval1, curval2;


char ProtocolFromModACT155()
{
	int ic=0;
	static char test23 = 0;
	while(embSerialACT155.UsedMod())
	{
			switch(westByte)
			{
			case 0x55: time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgWest.Init(); break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgWest.Init();	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
					if(mode5AWest) { embMsgWest.Add(Modify5A(westByte)); mode5AWest=0;	}
					else embMsgWest.Add(westByte);
				}
			}

			if(embMsgWest.IsEnd())
			{
 
				if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
				{
  		   	if(1)
   		   	{
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgWest.FullSize(); i++) 
					{
						switch(embMsgWest.body[i])
						{
					 	case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgWest.body[i]);						}
							}
					 }
				   embSerialACT155.AddTransit(0x55);

				}
					
				if(embMsgWest.AddrS()==SelfID())
				{
					embMsgWest.SetDir(1);
				    rBuffEmbMsg.Add(embMsgWest);
					embMsgWest.Init();
				}
				recieveWest = 0;
			}
//		if(!recieveWest)
		{
			if(tBuffEmbMsgWest.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgWest.Get(embMsgA);


				embSerialACT155.AddTransit(0x55);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgA.body[i]);
					}
  				}
				    embSerialACT155.AddTransit(0x55);
			}
 		}  //is end
	}	  //while
 return 0;
}

char ProtocolFromTransitACT155()
{
	int ic=0;

	while(embSerialACT155.UsedTransit())
	{
 		eastByte = embSerialACT155.GetTransit();
		switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit = time3Marker = time1;  break; // Маркеров здесь НЕТ!
						// Если в буффере есть пакет на передачу, то передаем его
				case 0x5A: mode5AEast=1; ready_transit=1; break;
				default:
					if(markerEast==1)	markerEast=2; 
					if(recieveEast==1)
					{
						if(mode5AEast) { embMsgEast.Add(Modify5A(eastByte)); mode5AEast=0;	}
						else embMsgEast.Add(eastByte); 
					}
		}
		if(embMsgEast.IsEnd())
		{
			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{
  			 if(1)
   		   	{
   	  			embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgEast.FullSize(); i++) 
				{

					switch(embMsgEast.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgEast.body[i]);
					}
				}
			   embSerialACT155.AddMod(0x55);
			 }
				countSend++;
			}

		
	 	 	if(embMsgEast.AddrS()==SelfID())
			{
					embMsgEast.SetDir(2);
				    rBuffEmbMsg.Add(embMsgWest);
				embMsgEast.Init();
			}
		}	 //is end
//		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
				embSerialACT155.AddMod(0x55);
				embSerialACT155.AddMod(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgA.body[i]);
					}
 				}
				embSerialACT155.AddMod(0x55);
			}
	  		}  //(1)
			}	 //while
	return 0;
}
void Check2InitTransitMod()
{
	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
		// Если произошло изменение ready_transit или ready_mod из "0" в "1"
		// то time3Marker = 0; под пакет 2355 байта и скорость 64К*8/11=46545
	if(time1-time3BlankMod>500) 
	{
		recieveWest=0; 
		time3BlankMod = time1;
		embSerialACT155.AddTransit(0x55);
	}
	if(time1-time3BlankTransit>500)
	{
		recieveEast=0; 
		time3BlankTransit = time1;
		embSerialACT155.AddMod(0x55);
	}
	if((time1-time3highID)>10000) 
	{
		time3highID=time1;
	}		
		if(unEmb2NetStat.emb2NetStat.buffModPm<embSerialACT155.UsedMod()) unEmb2NetStat.emb2NetStat.buffModPm = embSerialACT155.UsedMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPm<embSerialACT155.UsedTransit()) unEmb2NetStat.emb2NetStat.buffTransPm = embSerialACT155.UsedTransit();
		if(unEmb2NetStat.emb2NetStat.buffModPd<embSerialACT155.UsedSendMod()) unEmb2NetStat.emb2NetStat.buffModPd = embSerialACT155.UsedSendMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPd<embSerialACT155.UsedSendTransit()) unEmb2NetStat.emb2NetStat.buffTransPd = embSerialACT155.UsedSendTransit();
		if(unEmb2NetStat.emb2NetStat.buff232Pm<embRS232.UsedReceive()) unEmb2NetStat.emb2NetStat.buff232Pm = embRS232.UsedReceive();
		if(unEmb2NetStat.emb2NetStat.buff232Pd<embRS232.UsedTrans()) unEmb2NetStat.emb2NetStat.buff232Pd = embRS232.UsedTrans();
//		if(!recieveEast)
		{
 				if(!embSerialACT155.UsedSendMod()) 
				{	
   					if(tBuffEmbMsgEast.Used())
					{
	 					EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);
  						embSerialACT155.AddMod(0x55);
						embSerialACT155.AddMod(0xAA);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
							case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
							case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
							case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
							default: embSerialACT155.AddMod(embMsgA.body[i]);
							}
	   					}
						embSerialACT155.AddMod(0x55);
					}
				}
		}

//		if(!recieveWest)
		{
			if(!embSerialACT155.UsedSendTransit()) 
			{	


				if(tBuffEmbMsgWest.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					tBuffEmbMsgWest.Get(embMsgA);
					embSerialACT155.AddTransit(0x55);
					embSerialACT155.AddTransit(0xAA);
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgA.body[i]);
						}
			   //			ResetWatchDog();
					}
					embSerialACT155.AddTransit(0x55);
				}
			}
  		}
 	}

unsigned long ErrResSNMP;
unsigned long timeres;
unsigned char start_count;
union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
//	unsigned char uc[2];
	unsigned char uc[4];
};
unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;
UL2UC ul2uc;
UI2UC ui2uc;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct EmbMsgUD
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];
	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned short CRC() {	return body[body[1]+2]; }
	unsigned char Body(int i) { return body[i+2]; }
	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 64-counter; }
	int  short IsEnd();
	unsigned short ChkCRC();
	unsigned short TestCRC();
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsgUD::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++)
#ifndef TEST_RECEIVE
   body[i]=0;
#else // TEST_RECEIVE
   body[i]=0x97;
#endif //TEST_RECEIVE



}

unsigned short EmbMsgUD::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsgUD::IsEnd()
{
  if(counter>2)
		if(counter==Length()+3)
			return 1;
	return 0;
} 

unsigned short EmbMsgUD::ChkCRC()
{
  //	printf("\n\r CRC(): %02X , TestCRC : %02X", CRC(),TestCRC());	 //for test
	if(CRC()==TestCRC()) return 1;
	else 
	return 0;
}

unsigned short EmbMsgUD::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
	 	body[Length()+2]=c+1;
	return (unsigned char)(c+1);
	}
	else return 0;
} 

unsigned short EmbMsgUD::TestCRC()
{
  int i;
	unsigned char c=0;
	if(body[1]<64) 
	{
		for(i=0; i<body[1]; i++) c += body[i+2];
	 	return (unsigned char)(c+1);
	}
	else return 0;
}
//>>>>>>>>>>>added types

struct Emb5CommandRecieverSetFrequ
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned long frequ;  // Число соответствующие частоте приема 
				// в количестве шагов сетки 100КГц
  //	unsigned char lock;
};


union UnEmb5CommandRecieverSetFrequ
{
	Emb5CommandRecieverSetFrequ emb5commandrecieversetfrequ;
 	unsigned char byte[5];
 //	unsigned char byte[6]; //added lock
};

struct Emb5CommandRPUSetAtt
{
 	unsigned char number; 	 // Код канала РПУ (1..2)	
	unsigned char stepAtt; // установить шаг аттенюатора 
				 //(число шагов уточняется в процессе разработки))
};

union UnEmb5CommandRPUSetAtt
{
	Emb5CommandRPUSetAtt emb5commandrpusetatt; 	 // 	
	unsigned char byte[2];
};



	
struct Emb5CommandRecieverSetAtt
{
	unsigned char number; 	 // Код канала РПУ (1..2)	
	unsigned char stepAtt; // установить шаг аттенюатора 
				 //(число шагов уточняется в процессе разработки))
};

union UnEmb5CommandRecieverSetAtt
{
	Emb5CommandRecieverSetAtt emb5commandrecieversetatt; 	 // Код канала РПУ (1..2)	
	unsigned char byte[2];
};

struct Emb5CommandRecieverSetSendStatus
{
	unsigned char number; 		// Код канала РПУ (1..2)
	unsigned char getGenStatus; 	// 0 – выключение генерации сообщения статуса, 
					// 1 – включение генерации сообщения статуса, 
					// 2 – однократный запрос статуса
};

union UnEmb5CommandRecieverSetSendStatus
{
	Emb5CommandRecieverSetSendStatus emb5commandrecieversetsendstatus; 	 // Код канала РПУ (1..2)	
	unsigned char byte[2];
};


struct Emb5GetRPUState
{
	unsigned char number; 	 // Код канала РПУ (1..2)	
};

union UnEmb5GetRPUState
{
	Emb5GetRPUState emb5getrpustate; 	 // Код канала РПУ (1..2)	
	unsigned char byte[1];
};


struct Emb5Acknowledge
{
	unsigned char number; 		// Код канала РПУ (1..2)
	unsigned char AcknowledgeType; // код подтверждаемой команды (см. таблицу 2.2)
}; // 1 байт


union UnEmb5Acknowledge
{
	Emb5Acknowledge emb5acknowledge; 	 // Код канала РПУ (1..2)	
	unsigned char byte[2];
};


struct Emb5Exception
{
	unsigned char number; 		// Код канала РПУ (1..2)
   	unsigned short ExceptionCode; // код ошибки: 0 – сбой при выполнении команды;
//	unsigned char rezerved;
          // 1 – авария устройства
};

union UnEmb5Exception
{
	Emb5Exception emb5exception; 	 // Код канала РПУ (1..2)	
	unsigned char byte[3];
};


struct Emb5StatusReciever
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned char type; // Диапазон РПУ 1..3
	unsigned char status; // см. ниже описание <status>
	unsigned char stepAtt; // Шаг аттенюатора
	unsigned long frequ; // Число соответствующие частоте приема с шагом 100КГц
	unsigned short signalLevel; // уровень сигнала на входе РПУ в dbm
   	unsigned char genStatus; // Состояние статуса генерации 
				  // (0 -выкл, 1- вкл, 2- одиночный запрос)
	unsigned char lock;
}; // 12 байт

union UnEmb5StatusReciever
{
	Emb5StatusReciever emb5statusreciever; 	 // Код канала РПУ (1..2)	
   //	unsigned char byte[11];
	unsigned char byte[12];
};

struct Emb5ScanFreq
{
 unsigned char number;
 unsigned long frequStart;	   //? long after short - wil be work?
 unsigned short step;
 unsigned short numOfStep; //2...500
};

union UnEmb5ScanFreq
{
	Emb5ScanFreq emb5scanfreq; 	 // 	
	unsigned char byte[9];
};


struct Emb5StatusFrequScan
{
unsigned char number;
unsigned long frequStart;
unsigned short step;
unsigned short numOfStep;
unsigned char att;
unsigned short level[501];
};

union UnEmb5StatusFrequScan
{
	Emb5StatusFrequScan emb5statusfrequscan; 	 // Код канала РПУ (1..2)	
	unsigned char byte[1016];
};

struct EmbUpDownStatus
{
 //unsigned long number;
 unsigned long sendup;
 unsigned long received;
 unsigned long crc_ok;
 unsigned long crc_bad;
};

union UnEmbUpDownStatus
{
	EmbUpDownStatus embupdownstatus; 	 // Код канала РПУ (1..2)	
	unsigned char byte[20];
};

//status
//{
//	бит 0 — захват есть(1)/нет(0) синтезатора (частота установилась)
//	бит 1 — резерв;
//	бит 2 — резерв;
//	бит 3 — резерв;
//	бит 4 — резерв;
//	бит 5 — резерв;
//	бит 6 — резерв;
//	бит 7 — резерв;
//}

//struct Emb2TypeVer
//{
//	unsigned short type;       // Тип устройства ПРМ-ПЧ (в классификации ЗАО «Радиан»
//	unsigned short softVer;    // Версия ПО ПРМ-ПЧ
//	unsigned short ctrlNumber; // Это идентификатор устройства
//	unsigned short ctrlYear;   // Служебная информация ЗАР «Радиан»
//	unsigned short ctrlVer1;   // Служебная информация ЗАР «Радиан»
//	unsigned short ctrlVer2;   // Служебная информация ЗАР «Радиан»
//	unsigned char signature_hardware[16]; // Параметры «софта», если потребуются
//	unsigned char signature_software[16]; // Конфигурация «железа»  описана ниже
//}; // 44 байта


//signature_hardware[0] = диапазон модуля на входе 1;
//signature_hardware[1] = тип фильтра на входе 1;
//signature_hardware[2] = питание на входе 1;
//signature_hardware[3] = Версия ПО РПУ;
//signature_hardware[4] = диапазон модуля на входе 3;
//signature_hardware[5] = тип фильтра на входе 3;
//signature_hardware[6] = питание на входе 3;
//signature_hardware[7]  = резерв;
//signature_hardware[8] = диапазон модуля на входе 2;
//signature_hardware[9] =  тип фильтра на входе 2;
//signature_hardware[10] =  питание на входе 2;
//signature_hardware[11] =  Версия ПО РПУ;
//signature_hardware[12] = резерв;
//signature_hardware[13] = резерв;
//signature_hardware[14] = резерв;
//signature_hardware[15] = резерв;

struct Emb5RPUState
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned char type; // Диапазон РПУ 1..3
	unsigned char u48; // уровень напряжения питания +48В текущий
	unsigned char u48min; // уровень напр. +48В минимальный за период с прошлого опроса
	unsigned char u48max; // уровень напр. +48В максимальный за период с прошлого опроса
	unsigned char u24; // уровень напряжения питания +24В текущий
	unsigned char u24min; // уровень напр. +24В минимальный за период с прошлого опроса
	unsigned char u24max; // уровень напр. +24В максимальный за период с прошлого опроса
	unsigned char u7; // уровень напряжения питания +7В текущий
	unsigned char u7min; // уровень напр. +7В минимальный за период с прошлого опроса
	unsigned char u7max; // уровень напр. +7В максимальный за период с прошлого опроса
	unsigned char u5; // уровень напряжения питания +5В текущий
	unsigned char u5min; // уровень напр. +5В минимальный за период с прошлого опроса
	unsigned char u5max; // уровень напр. +5В максимальный за период с прошлого опроса
	unsigned char u_5; // уровень напряжения питания -5В текущий
	unsigned char u_5min; // уровень напр. -5В минимальный за период с прошлого опроса
	unsigned char u_5max; // уровень напр. -5В максимальный за период с прошлого опроса	
	unsigned char temp; // уровень температуры текущий
	unsigned char temp_min; // уровень температуры минимальный за период с прошлого опроса
	unsigned char temp_max; // уровень температуры максимальный за период с прошлого опроса
}; // 20 байт


union UnEmb5RPUState
{
	Emb5RPUState emb5rpustate; 	 // Код канала РПУ (1..2)	
	unsigned char byte[20];
};
//<<<<<<<<<<<added types

UnEmbUpDownStatus 	embUpDownStatus1;
//UnEmbUpDownStatus 	embUpDownStatus2;

UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ1;
//UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ2;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt1;
//UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt2;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt1;
//UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt2;





UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus1;
//UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus2;

UnEmb5GetRPUState emb5GetRPUState1;
//UnEmb5GetRPUState emb5GetRPUState2;

UnEmb5Acknowledge	emb5Acknowledge1;
//UnEmb5Acknowledge	emb5Acknowledge2;

UnEmb5Exception emb5Exception1;
//UnEmb5Exception emb5Exception2;

UnEmb5StatusReciever emb5StatusReciever1;
//UnEmb5StatusReciever emb5StatusReciever2;

UnEmb5RPUState emb5RPUState1;
//UnEmb5RPUState emb5RPUState2;

UnEmb5ScanFreq	 emb5ScanFreq1;
//UnEmb5ScanFreq	 emb5ScanFreq2;

UnEmb5StatusFrequScan  emb5StatusFrequScan1;
//UnEmb5StatusFrequScan  emb5StatusFrequScan2;

EmbMsgUD embMsgUD_1;
//EmbMsgUD embMsgUD_2;
EmbMsgUD embMsgUDRequest_1;
//EmbMsgUD embMsgUDRequest_2;

unsigned ans1=0;//, ans2=0;
unsigned short delay1;//, delay2;  //my

unsigned short countMod;
unsigned short countTransit;

#ifdef TEST_RECEIVE
unsigned long sendp;
unsigned long receivep, receivepb;
unsigned long delta, delta_old;
unsigned long st_count;
unsigned char pped;
unsigned char countt, countr;
unsigned long countsend;

unsigned long countr_bad,countr_ok, countr_all, countta;



#endif //TEST_RECEIVE
unsigned char isreceived1;
//unsigned char isreceived2;
//unsigned char isreceived3;
unsigned char isreceived4;
//unsigned char isreceived5;
unsigned char isreceived6;







unsigned short requestMod=0;
unsigned short requestTransit=0;

#ifdef PRM_PCH_THREE_LINES
  /*
UnEmbUpDownStatus 	embUpDownStatus3;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ3;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt3;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt3;

UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus3;
UnEmb5GetRPUState emb5GetRPUState3;
UnEmb5Acknowledge	emb5Acknowledge3;
UnEmb5Exception emb5Exception3;
UnEmb5StatusReciever emb5StatusReciever3;
UnEmb5RPUState emb5RPUState3;
UnEmb5ScanFreq	 emb5ScanFreq3;
UnEmb5StatusFrequScan  emb5StatusFrequScan3;
EmbMsgUD embMsgUD_3;
EmbMsgUD embMsgUDRequest_3;
unsigned ans3=0;
unsigned short delay3;  //my
unsigned short countPower=0;
unsigned short requestPower=0;
unsigned char   setf3, setatt3, modescan3;
unsigned char  ready_power, old_ready_power; 
unsigned long  time3old;
signed long curval3;
unsigned char request3;
unsigned char markerPower;
unsigned long time3BlankPower;
unsigned char delete_msgPower;
unsigned char recievePower;
unsigned char mode5APower;
EmbMsgBuffer tBuffEmbMsgPower;
			 */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
unsigned short countTransit4, countTransit5, countTransit6;
unsigned short requestTransit4,requestTransit5, requestTransit6;
unsigned short fl1,fl4,fl5,fl6;

 unsigned char start4, start5,start6;


//___________________________
unsigned char mode5AWest2;
unsigned short countMod2=0;
unsigned char mode5AWest3;
unsigned short countMod3=0;


struct EmbPUPM2
{
  unsigned char freq3;
  unsigned char freq2;
  unsigned char freq1;
  unsigned char freq0;
  unsigned char att;
  unsigned char prm;
  unsigned char type;
  unsigned char verp;
  unsigned char verh;
};

union uEmbPUPM2
{
  EmbPUPM2 embpupm2;
  unsigned char byte[9];
};

uEmbPUPM2 pupm1;   //first channel
uEmbPUPM2 pupm2;   //second channel
uEmbPUPM2 pupm3;   //third channel  new


//___________________________
/*
struct Emb5StatusGeterodin
{
unsigned long number;
unsigned long frequ;
unsigned long get1;
unsigned long get2;
};
*/

uEmb5StatusGeterodin	  uemb5statusgeterodin1;
//uEmb5StatusGeterodin	  uemb5statusgeterodin2;
//uEmb5StatusGeterodin	  uemb5statusgeterodin3;
uEmb5StatusGeterodin	  uemb5statusgeterodin4;
//uEmb5StatusGeterodin	  uemb5statusgeterodin5;
uEmb5StatusGeterodin	  uemb5statusgeterodin6;







UnEmbUpDownStatus 	embUpDownStatus4;
//UnEmbUpDownStatus 	embUpDownStatus5;
UnEmbUpDownStatus 	embUpDownStatus6;

UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ4;
//UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ5;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ6;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt4;
//UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt5;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt6;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt4;
//UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt5;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt6;

UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus4;
//UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus5;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus6;

UnEmb5GetRPUState emb5GetRPUState4;
//UnEmb5GetRPUState emb5GetRPUState5;
UnEmb5GetRPUState emb5GetRPUState6;

UnEmb5Acknowledge	emb5Acknowledge4;
//UnEmb5Acknowledge	emb5Acknowledge5;
UnEmb5Acknowledge	emb5Acknowledge6;


UnEmb5Exception emb5Exception4;
//UnEmb5Exception emb5Exception5;
UnEmb5Exception emb5Exception6;

UnEmb5StatusReciever emb5StatusReciever4;
//UnEmb5StatusReciever emb5StatusReciever5;
UnEmb5StatusReciever emb5StatusReciever6;

UnEmb5RPUState emb5RPUState4;
//UnEmb5RPUState emb5RPUState5;
UnEmb5RPUState emb5RPUState6;

UnEmb5ScanFreq	 emb5ScanFreq4;
//UnEmb5ScanFreq	 emb5ScanFreq5;
UnEmb5ScanFreq	 emb5ScanFreq6;

UnEmb5StatusFrequScan  emb5StatusFrequScan4;
//UnEmb5StatusFrequScan  emb5StatusFrequScan5;
UnEmb5StatusFrequScan  emb5StatusFrequScan6;

EmbMsgUD embMsgUD_4;
//EmbMsgUD embMsgUD_5;
EmbMsgUD embMsgUD_6;

EmbMsgUD embMsgUDRequest_4;
//EmbMsgUD embMsgUDRequest_5;
EmbMsgUD embMsgUDRequest_6;


unsigned ans4=0;
//unsigned ans5=0;
unsigned ans6=0;

unsigned short delay4;  //my
//unsigned short delay5; 
unsigned short delay6; 


unsigned short countPower4=0;
//unsigned short countPower5=0;
unsigned short countPower6=0;

unsigned short requestPower4=0;
//unsigned short requestPower5=0;
unsigned short requestPower6=0;

unsigned char   setf4, setatt4, modescan4;
//unsigned char   setf5, setatt5, modescan5;
unsigned char   setf6, setatt6, modescan6;

unsigned char  ready_power4, old_ready_power4; 
//unsigned char  ready_power5, old_ready_power5;
unsigned char  ready_power6, old_ready_power6;

unsigned long  time4old;
//unsigned long  time5old;
unsigned long  time6old;

signed long curval4;
//signed long curval5;
signed long curval6;
#endif //PRM_PCH_SIX_LINES

#ifdef PROG_PRM_PCH_L
unsigned char NeedWriteID;
unsigned char test_shift_mode;

#endif //PROG_PRM_PCH_L

unsigned char Band1, Band4, Band6;

extern "C" signed short ConvVal(unsigned short val)
{
 /*
float fval = (float)val;
// fval *= 0.0221; 
// fval -= 98.2;
 fval *= 0.0227; 
 fval -= 91.649;
return (signed short)fval;
 */
//signed short fval = val * 0.0227 - 91.649;
signed char fval = (val & 0xFFF) * 0.0227 - 91.649;
return 	fval;
//return 	val & 0x0fff;
}

extern "C" void ParseUD_1()
{
 if(modescan1)
 {
 if(curval1 >= 0)
 {
 emb5StatusFrequScan1.emb5statusfrequscan.level[curval1] = ConvVal( (((unsigned short)embMsgUD_1.Body(2)&0x0F) << 8) + 	embMsgUD_1.Body(1));
 }
 else
 {
 }
  return;
 }
 		
// if(start1) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = 1; //have power on 1
 switch(embMsgUD_1.Body(0))
 {
  case 0:  //if(start1) 
  {unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = embMsgUD_1.Body(1) &  PUPM2_TYPE_CONV_MASK;
  pupm1.embpupm2.type   =   unEmb2TypeVer.emb2TypeVer.signature_hardware[0];

    	   Band1 = embMsgUD_1.Body(1);}	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever1.emb5statusreciever.status =  embMsgUD_1.Body(2) >> 4;
			emb5StatusReciever1.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_1.Body(2)&0x0F) << 8) + embMsgUD_1.Body(1));
			emb5StatusReciever1.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_1.Body(3));
			emb5StatusReciever1.emb5statusreciever.lock =  (unsigned short)embMsgUD_1.Body(2) >> 7;
 			break;
  case 22:	emb5RPUState1.emb5rpustate.temp =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.temp_min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.temp_max =  embMsgUD_1.Body(3); break;
  case 23:	emb5RPUState1.emb5rpustate.u48 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u48min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u48max =  embMsgUD_1.Body(3);  break;
  case 24:	emb5RPUState1.emb5rpustate.u24 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u24min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u24max =  embMsgUD_1.Body(3); break;
  case 25:	emb5RPUState1.emb5rpustate.u7 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u7min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u7max =  embMsgUD_1.Body(3);	break;
  case 26:	emb5RPUState1.emb5rpustate.u5 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u5min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u5max =  embMsgUD_1.Body(3);	 break;
  case 27:	emb5RPUState1.emb5rpustate.u_5 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u_5min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u_5max =  embMsgUD_1.Body(3);  break;

//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[0] =  embMsgUD_1.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[2] =  embMsgUD_1.Body(1);	break;
  case 30:	WriteStatus1 = embMsgUD_1.Body(1); break;
  case 31:	ReadStatus1[0] = embMsgUD_1.Body(1); 
			ReadStatus1[1] = embMsgUD_1.Body(2); 
			ReadStatus1[2] = embMsgUD_1.Body(3);
#ifdef TEST_PUPM2
			printfpd("<%02X,", ReadStatus1[0]);
	 		printfpd("%02X,", ReadStatus1[1]);
     		printfpd("%02X>", ReadStatus1[2]);
#endif
			
			
			 break;
  case 32:	ReadAtt1[0] = embMsgUD_1.Body(1); 
			ReadAtt1[1] = embMsgUD_1.Body(2); 
			ReadAtt1[2] = embMsgUD_1.Body(3); break;
//#endif	// PROG_PRM_PCH_L_61

  default : break;
 }
}
   /*
extern "C" void ParseUD_2()	 //need make!
{

if(modescan2)
 {
 if(curval2 >= 0)
 {
  emb5StatusFrequScan2.emb5statusfrequscan.level[curval2] = ConvVal( (((unsigned short)embMsgUD_2.Body(2)&0x0F) << 8) + 	embMsgUD_2.Body(1));
 }
 else
 {
  }
  return;
 }		
 if(start2) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[10] = 1; //have power on 2

 switch(embMsgUD_2.Body(0))
 {
  case 0: if(start2)
   { unEmb2TypeVer.emb2TypeVer.signature_hardware[8] = embMsgUD_2.Body(1) & DEVICE_TYPE_MASK; 
   		  Band2 = embMsgUD_2.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever2.emb5statusreciever.status =  embMsgUD_2.Body(2) >> 4;
			emb5StatusReciever2.emb5statusreciever.signalLevel =  ConvVal((((unsigned short)embMsgUD_2.Body(2)&0x0F)  << 8) + 	embMsgUD_2.Body(1));
 		   	emb5StatusReciever2.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_2.Body(3));  //	break;
 		break;	   //for test
  case 22:	emb5RPUState2.emb5rpustate.temp =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.temp_min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.temp_max =  embMsgUD_2.Body(3);
  case 23:	emb5RPUState2.emb5rpustate.u48 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u48min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u48max =  embMsgUD_2.Body(3);
  case 24:	emb5RPUState2.emb5rpustate.u24 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u24min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u24max =  embMsgUD_2.Body(3);
  case 25:	emb5RPUState2.emb5rpustate.u7 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u7min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u7max =  embMsgUD_2.Body(3);
  case 26:	emb5RPUState2.emb5rpustate.u5 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u5min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u5max =  embMsgUD_2.Body(3);
  case 27:	emb5RPUState2.emb5rpustate.u_5 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u_5min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u_5max =  embMsgUD_2.Body(3);
//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[8] =  embMsgUD_2.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[10] =  embMsgUD_2.Body(1);	break;
  case 30:	WriteStatus2 = embMsgUD_2.Body(1); break;
  case 31:	ReadStatus2[0] = embMsgUD_2.Body(1); 
			ReadStatus2[1] = embMsgUD_2.Body(2); 
			ReadStatus2[2] = embMsgUD_2.Body(3); break;
  case 32:	ReadAtt2[0] = embMsgUD_2.Body(1); 
			ReadAtt2[1] = embMsgUD_2.Body(2); 
			ReadAtt2[2] = embMsgUD_2.Body(3); break;

//#endif	// PROG_PRM_PCH_L_61
  default : break;
 }
}
	  */
#ifdef PRM_L_KEEP_FREQ
unsigned long DelayWriteTime;
#endif

extern "C" void InitIOPins()
{
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222  
}

unsigned char rs485_addr;
//______________________________________
unsigned char NeedRunCommand;
unsigned char current_command_counter;
unsigned char current_command_state;

unsigned char current_command_type;
unsigned char current_command_crc;
unsigned char current_command_length;
unsigned char current_command_data_counter;
unsigned char current_command_data[MAX_DATA_SIZE1];
unsigned char BufferCommand[MAX_DATA_SIZE1 + 2];
unsigned char BufferAnswer[MAX_DATA_SIZE1 + 2];



unsigned char CommandLength[COMMANDS_QUANTITY + 1];
unsigned char CommandDataLength[COMMANDS_QUANTITY + 1];
unsigned char modeFE, modeFC;
unsigned char sended_ans;

 /*
struct EmbPUPM2
{
  unsigned char freq3;
  unsigned char freq2;
  unsigned char freq1;
  unsigned char freq0;
  unsigned char att;
  unsigned char prm;
  unsigned char type;
  unsigned char verp;
  unsigned char verh;
};

union uEmbPUPM2
{
  EmbPUPM2 embpupm2;
  unsigned char byte[9];
};

uEmbPUPM2 pupm1;   //first channel
uEmbPUPM2 pupm2;   //second channel
   */
//need do not forgot make replacing fe, fc
#define ADDR_FRQ1  (250)  //unsigned char!!!!
#define ADDR_FRQ4  (251)
#define ADDR_FRQ14  (252)


extern "C" unsigned char RunWriting(unsigned char addr, unsigned char data)
{
unsigned char ret = 1;
unsigned long timerun;
#ifdef TEST_PRINT_SPI
printfpd("\n\rwr addr : %x", addr);
#endif

#ifdef TEST_PRINT_SPI
printfpd("data : %x", data);
#endif


 breakflag1 = 1;
 breakflag4 = 1;


switch(addr)
{
 case 0x00:  pupm1.byte[0] = data;	return 2;//SetFreqPUPM2(1); break;
 case 0x01:  pupm1.byte[1] = data;	return 2;//SetFreqPUPM2(1); break;
 case 0x02:  pupm1.byte[2] = data;	return 2;//SetFreqPUPM2(1);  break;
 case 0x03:  pupm1.byte[3] = data;	return 2;//SetFreqPUPM2(1);  break;
 case 0x04:  pupm1.byte[4] = data;  breakflag1 = 0;	SetAttPUPM2(1);	  break;
 case 0x10:  pupm2.byte[0] = data;	return 3;//SetFreqPUPM2(4);  break;
 case 0x11:  pupm2.byte[1] = data;	return 3;//SetFreqPUPM2(4);  break;
 case 0x12:  pupm2.byte[2] = data;	return 3;//SetFreqPUPM2(4);  break;
 case 0x13:  pupm2.byte[3] = data;	return 3;//SetFreqPUPM2(4);  break;
 case 0x14:  pupm2.byte[4] = data;	breakflag4 = 0; SetAttPUPM2(4);	  break;
 case (unsigned char)(ADDR_FRQ1):   breakflag1 = 0; SetFreqPUPM2(1); break;
 case (unsigned char)(ADDR_FRQ4):  breakflag4 = 0;  SetFreqPUPM2(4); break;
 case (unsigned char)(ADDR_FRQ14):  breakflag1 = 0; breakflag4 = 0; SetFreqPUPM2(1); SetFreqPUPM2(4); break;

 default :  return 0;
}

 timerun = time1;
// breakflag = 0;
 

  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
	 
	while(((time1-timerun) < RUN_TIME_PUPM2)	&& 	(time1 >= timerun))
	{
 //	  if(breakflag) break;
 	  if(breakflag1 &&  breakflag4) break;
  //	  if((breakflag) || (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  message++; 
 	  PRM_PCH();
	}


//return breakflag;
return (breakflag1 &&  breakflag4);
}

extern "C" unsigned char AddrPm1(unsigned char addr)
{
if(addr < 0x10) return 1;
return 0;
}

extern "C" unsigned char RunReading(unsigned char addr, unsigned char* data)
{
unsigned char ret = 1;
unsigned long timerun;

#ifdef TEST_PRINT_SPI
printfpd(" rd addr : %x", addr);
#endif

 breakflag1 = 1;
 breakflag4 = 1;


switch(addr)
{
 case 0x00:  *data = pupm1.byte[0];  return 2;// GetCode1();	 break;
 case 0x01:  *data = pupm1.byte[1];  return 2;// GetCode1();	 break;
 case 0x02:  *data = pupm1.byte[2];  return 2;// GetCode1();	 break;
 case 0x03:  *data = pupm1.byte[3];  return 2;// GetCode1();	 break;
 case 0x04:  *data = pupm1.byte[4];  return 2;//  GetCode1();	 break;
 case 0x05:  *data = pupm1.byte[5];  return 2;// GetCode1();	 break;
 case 0x06:  *data = pupm1.byte[6];  return 2;// GetCode1();	 break;
 case 0x07:  *data = pupm1.byte[7];  return 2;// GetCode1();	 break;
 case 0x08:  *data = pupm1.byte[8];  return 2;// GetCode1();	 break;
 case 0x10:  *data = pupm2.byte[0];  return 3;// GetCode4();	 break;
 case 0x11:  *data = pupm2.byte[1];  return 3;// GetCode4();	 break;
 case 0x12:  *data = pupm2.byte[2];  return 3;// GetCode4();	 break;
 case 0x13:  *data = pupm2.byte[3];  return 3;//    GetCode4();	 break;
 case 0x14:  *data = pupm2.byte[4];  return 3;//    GetCode4();	 break;
 case 0x15:  *data = pupm2.byte[5];  return 3;//    GetCode4();	 break;
 case 0x16:  *data = pupm2.byte[6];  return 3;//    GetCode4();	 break;
 case 0x17:  *data = pupm2.byte[7];  return 3;//    GetCode4();	 break;
 case 0x18:  *data = pupm2.byte[8];  return 3;//    GetCode4();	 break;
 case (unsigned char)(ADDR_FRQ1):   breakflag1 = 0; GetCode1(); break;
 case (unsigned char)(ADDR_FRQ4):   breakflag4 = 0; GetCode4(); break;
 case (unsigned char)(ADDR_FRQ14):  breakflag1 = 0; breakflag4 = 0; GetCode1(); GetCode4(); break;
 default : *data = 0; return 0;
}

 timerun = time1;
// breakflag = 0;
  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
	 
	while(((time1-timerun) < RUN_TIME_PUPM2)	&& 	(time1 >= timerun))
	{
 	  if(breakflag1 && breakflag4) break;
 //	  if(breakflag) break;
  //	  if((breakflag) || (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  message++; 
 	  PRM_PCH();
	}



  //if(!breakflag)
 /*
   if((!breakflag1) || (!breakflag4))
	{
	 *data = 0;
	 if(AddrPm1(addr))
	 {
	  pupm1.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  	  pupm1.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  	  pupm1.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
      pupm1.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
      pupm1.embpupm2.att   =  0;
	  }
	  else
	  {
	  pupm2.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  	  pupm2.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  	  pupm2.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
      pupm2.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
      pupm2.embpupm2.att   =  0;
	  }
	}
*/

#ifndef MAKET_PLATA	 


 if(!breakflag1) 
 	{
 	  pupm1.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  	  pupm1.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  	  pupm1.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
      pupm1.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
      pupm1.embpupm2.att   =  0;
 //130218	  pupm1.embpupm2.prm |= ((unsigned char)PM_OK);
	   pupm1.embpupm2.prm &= ~((unsigned char)PM_OK);

	  pupm1.embpupm2.type  =  0;
	}

if(!breakflag4) 
 	{
 	  pupm2.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  	  pupm2.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  	  pupm2.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
      pupm2.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
      pupm2.embpupm2.att   =  0;
 //130218      pupm2.embpupm2.prm |= ((unsigned char)PM_OK);
	   pupm2.embpupm2.prm &= ~((unsigned char)PM_OK);
      pupm2.embpupm2.type  =  0;
	}

#endif //maket

return (breakflag1 && breakflag4);
}



extern "C" unsigned char RunCommandPUPM1()
{
#ifdef TEST_PRINT_SPI
printfpd("\n\rcurrent_command_type : %d ", current_command_type);
//printfpd("\n\r>write length : %d ",CommandDataLength[current_command_type]);
printfpd("\n\r>current_command_data[0]: %X ",current_command_data[0]);
printfpd("\n\r>current_command_data[1]: %X ",current_command_data[1]);
//printfpd(" %02X ",current_command_data[0]);
//printfpd(";%02X ",current_command_data[1]);
// return;
#endif
 unsigned char ret = 1;
 unsigned char ans;
 unsigned char flag1 = 0;
 unsigned char flag4 = 0;
 ans =  RunWriting(current_command_data[0], current_command_data[1]);

switch(ans)
	{
	 case 0 : ret = 0;	break;
	 case 2 : flag1 = 1; break;
     case 3 : flag4 = 1; break;
	 default : break;
	}

//  if(flag1 && flag4)
//  {
//  if(!RunWriting((unsigned char)(ADDR_FRQ14), 0)) ret = 0;
//  }
//  else
//  {
  if(flag1) {  if(!RunWriting((unsigned char)(ADDR_FRQ1), 0)) ret = 0;}	   //set freq1
  if(flag4) {  if(!RunWriting((unsigned char)(ADDR_FRQ4), 0)) ret = 0;}	   //set freq4
//  }
 return ret;



 return RunWriting(current_command_data[0], current_command_data[1]);
}

extern "C" unsigned long RunCommandPUPM2()
{
 unsigned char ret = 1;
// unsigned char di = 2;
 unsigned char di = 0;
 unsigned char ans;
 unsigned char flag1 = 0;
 unsigned char flag4 = 0;

#ifdef TEST_PRINT_SPI
printfpd("\n\rcurrent_command_type : %d ", current_command_type);
printfpd("\n\r>write length : %d ",CommandDataLength[current_command_type]);
printfpd("\n\r>current_command_data[0]: %X ",current_command_data[0]);
printfpd("\n\r>current_command_data[1]: %X ",current_command_data[1]);

//printfpd(" %02X ",current_command_data[0]);
//printfpd(";%02X ",current_command_data[1]);

// return;
#endif

  for(unsigned char addr = firstaddr; addr < firstaddr + CommandDataLength[current_command_type]; addr++)
  {
	ans =  RunWriting(addr, current_command_data[di++]);
//    if(!RunWriting(addr, current_command_data[di++])) ret = 0;
	switch(ans)
	{
	 case 0 : ret = 0;	break;
	 case 2 : flag1 = 1; break;
     case 3 : flag4 = 1; break;
	 default : break;
	}
  }

  if(flag1 && flag4)
  {
  if(!RunWriting((unsigned char)(ADDR_FRQ14), 0)) ret = 0;
  }
  else
  {
  if(flag1) {  if(!RunWriting((unsigned char)(ADDR_FRQ1), 0)) ret = 0;}	   //set freq1
  if(flag4) {  if(!RunWriting((unsigned char)(ADDR_FRQ4), 0)) ret = 0;}	   //set freq4
  }
 return ret;
}

extern "C" unsigned long RunCommandPUPM3(unsigned char *anslen)
{
 unsigned char ret = 1;
 unsigned char di = 2;
 unsigned char anslen1 =  *anslen;
 unsigned char startanslen = anslen1;
 unsigned char ans;
 unsigned char flag1 = 0;
 unsigned char flag4 = 0;

#ifdef TEST_PRINT_SPI
printfpd("\n\rcurrent_command_type : %d ", current_command_type);
//printfpd("\n\r>write length : %d ",CommandDataLength[current_command_type]);
printfpd("\n\r>current_command_data[0]: %X ",current_command_data[0]);
printfpd("\n\r>current_command_data[1]: %X ",current_command_data[1]);

//printfpd(" %02X ",current_command_data[0]);
//printfpd(";%02X ",current_command_data[1]);

// return;
#endif


   if(current_command_data[0] > current_command_data[1])  return 0;
   if(current_command_data[1] > 0x18)  return 0;   //max high address

//find flags only
   for(unsigned char addr = current_command_data[0]; addr <= current_command_data[1]; addr++)
  {
	if(anslen1 > (MAX_DATA_SIZE1 - 4 )) return 0;

    ans =  RunReading(addr, &BufferAnswer[anslen1]);
 	switch(ans)
	{
	 case 0 : ret = 0;	break;
	 case 2 : flag1 = 1; break;
     case 3 : flag4 = 1; break;
	 default : break;
	}
  }


//check of connecting devices and set params of unconnected to zero
  if(flag1 && flag4)
  {
    if(!RunReading((unsigned char)(ADDR_FRQ14), 0)) 
    {
  	ret = 0;
    }
  }
  else
  {
  if(flag1) {  if(!RunReading((unsigned char)(ADDR_FRQ1), 0)) ret = 0;}	   //set freq1
  if(flag4) {  if(!RunReading((unsigned char)(ADDR_FRQ4), 0)) ret = 0;}	   //set freq4
  }

/* 130212
 if(!ret)	 //set data to zero
 {
	for(unsigned char ip = startanslen; ip < anslen1; ip++)
	{
	if(BufferAnswer[ip] == START_SYM){anslen1--;}
	if(BufferAnswer[ip] == STOP_SYM) {anslen1--;}
	BufferAnswer[ip] = 0;
	} 
 }
*/

//read final parameters

   for( addr = current_command_data[0]; addr <= current_command_data[1]; addr++)
  {
	if(anslen1 > (MAX_DATA_SIZE1 - 4 )) return 0;

    RunReading(addr, &BufferAnswer[anslen1]);
 	if(BufferAnswer[anslen1] == START_SYM){anslen1++;  BufferAnswer[anslen1] = 0;}
	if(BufferAnswer[anslen1] == STOP_SYM) {anslen1++;  BufferAnswer[anslen1] = 0;}
	anslen1++;
   }
 *anslen = anslen1;


 return ret;

}
 /*
extern "C" unsigned long SendAnsBadCode()
{
 return 5;
}

extern "C" unsigned long SendAnsBadCRC()
{
 return 5;
}

extern "C" unsigned long SendAnsNoFormat()
{
 return 5;
}
   
#define START_SYM 0xFE
#define STOP_SYM  0xFC
  */

/*
#define START_ADDR_PRM2 (0x10)

extern "C" unsigned char PrmConnected()
{
 unsigned char ret = 0;
 if(current_command_data[0] < START_ADDR_PRM2) 
 {
   if(pupm1.embpupm2.prm) ret = 1;
 }
 else
 {
   if(pupm2.embpupm2.prm) ret = 1;
 }
#ifdef TEST_PUPM2
 printfpd("\n\r connected %d", ret);
#endif
 return ret;
}

	*/

extern "C" void SetRunCommandPUPM2(unsigned char code)
{

 unsigned char anslen = 0;
 unsigned char crc = 0;
   /*
if(sended_ans)	//i receive my answer
 {
  sended_ans = 0;

#ifdef TEST_PRINT_SPI
printfp(" Skip ans ");
#endif

  return; 
 }
 */
 	
#ifdef TEST_PRINT_SPI
printfp("\n\r SetRunCommandPUPM2 Command ");
printfpd(":%d ",current_command_type);
//printfpd(" %02X ",current_command_data[0]);
//printfpd(";%02X ",current_command_data[1]);

// return;
#endif
//#ifdef BACK_TO_SSC
//SetLineDataSSC2ToSSC2Data();
//#endif

BufferAnswer[0] = START_SYM;
BufferAnswer[1] = START_SYM;
BufferAnswer[2] = code;
BufferAnswer[3] = rs485_addr;
anslen =4;

 switch(code)
 {
 case 0:
  
  switch(current_command_type)
 {
  case 1	: if(!RunCommandPUPM1()) 		BufferAnswer[2] = CODE_NOT_CONNECT; break;
  case 2	: if(!RunCommandPUPM2()) 		BufferAnswer[2] = CODE_NOT_CONNECT; break;
  case 3	: if(!RunCommandPUPM3(&anslen)) BufferAnswer[2] = CODE_NOT_CONNECT; break;
 
  default 	: BufferAnswer[2] = CODE_BAD_COP; break;
 }	//	  current_command_type
 break;
   /*
 case 1:  anslen = SendAnsBadCode(); break;
 case 2:  anslen = SendAnsBadCRC(); break;
 case 3:  anslen = SendAnsNoFormat(); break;
 */
 default :   break;
 }	 //code

 /*
if(!PrmConnected())  
 {
    BufferAnswer[2] = CODE_NOT_CONNECT; 
 }
  */

#ifdef TEST_PRINT_SPI
printfp("\n\ranswer crc:");
#endif

for(unsigned long i = 2; i < anslen; i++)	//start symbols do not count
 {


   crc += BufferAnswer[i];

#ifdef TEST_PRINT_SPI
printfpd("+%02X ",BufferAnswer[i]);
#endif

//#ifdef TEST_PRINT_SPI
//printfpd("->%02X ",crc);
//#endif
 
}

#ifdef TEST_PRINT_SPI
printfpd("->%02X ",crc);
#endif


  BufferAnswer[anslen++] = crc;
  BufferAnswer[anslen++] = STOP_SYM;
  BufferAnswer[anslen++] = STOP_SYM;

 sended_ans = 1;

#ifdef TEST_PRINT_SPI
printfp("\n\rsend Ans> ");
#endif


 for(i = 0; i < anslen; i++)
 {
   ToPdcTu1(BufferAnswer[i]);

#ifdef TEST_PRINT_SPI
printfpd("%02X ",BufferAnswer[i]);
#endif
    BufferAnswer[i] = 0;

 }

 OperateBuffers_usart1t(); 

} 
unsigned long prm_counter;

//_______________________________________
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////



extern "C" void Init_PRM_PCH(void)
{

 prm_counter = 0;

sended_ans = 0;

CommandDataLength[0] = 6;  //dummy command
CommandDataLength[1] = 6;
//130208CommandDataLength[2] = 7; //celling in receive
CommandDataLength[2] = 15; //celling in receive




CommandDataLength[3] = 6; //celling in receive


modeFE = modeFC = 0;
current_command_state = WAITING_COMMAND;

rs485_addr = 0;

#ifdef PRM_L_KEEP_FREQ
 DelayWriteTime = 0;
#endif

 //  embMsg485.Init();   //091113

 Band1 = 0;
// Band2 = 0;
// Band3 = 0;
 Band4 = 0;
// Band5 = 0;
// Band6 = 0;





#ifdef PROG_PRM_PCH_L
 NeedWriteID = 0;
 test_shift_mode = 0;
#endif //PROG_PRM_PCH_L


//char any;
 embMsgUD_1.Init();
 //embMsgUD_2.Init();
 embMsgUDRequest_1.Init();
// embMsgUDRequest_2.Init();
#ifdef PRM_PCH_THREE_LINES
/*
 embMsgUD_3.Init();
 embMsgUDRequest_3.Init();
 setf3 = 0;
 setatt3 = 1; //0911090;
 ready_power=0;
 old_ready_power=0; 
 modescan3 = 0;
 curval3	= 0;
 for(i=0; i<16; i++)
	{
	 embUpDownStatus3.byte[i] = 0;
	 any = inportb(0x507);	 //clear
	 any = inportb(0x509);
	 any = inportb(0x50B);


	}
  time3old=0;
  request3=0;
  time3BlankPower=0; 
  markerPower=0; ready_power=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgPower=0;  recievePower=0; 
  mode5APower=0;  
  tBuffEmbMsgPower.Init();
  request3=0;
  delay3 = NO_SCAN_DELAY;
  countPower=0;
  requestPower=0;
  */
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
countTransit4 = 0;countTransit5 = 0; countTransit6 = 0;
fl1=fl4=0; 
requestTransit4 = 0; requestTransit5 = 0; requestTransit6 = 0;
 start4 = 1;
// start5 = 1;
 start6 = 1;
//_______________________________
 mode5AWest2=0; 
 countMod2=0;
 mode5AWest3 = 0;
 countMod3=0;
//_______________________________
 embMsgUD_4.Init();
// embMsgUD_5.Init();
 embMsgUD_6.Init();
 embMsgUDRequest_4.Init();
// embMsgUDRequest_5.Init();
 embMsgUDRequest_6.Init();
 setf4 = 0;
// setf5 = 0;
 setf6 = 0;
 setatt4 = 1; //0911090;
// setatt5 = 1; //0911090;
 setatt6 = 1; //0911090;
 ready_power4=0;
// ready_power5=0;
 ready_power6=0;
 old_ready_power4=0; 
// old_ready_power5=0; 
 old_ready_power6=0; 
 modescan4 = 0;
// modescan5 = 0;
 modescan6 = 0;
 curval4	= 0;
// curval5	= 0;
 curval6	= 0;
 for(i=0; i<16; i++)
	{
	 embUpDownStatus4.byte[i] = 0;
// 	 embUpDownStatus5.byte[i] = 0;
 	 embUpDownStatus6.byte[i] = 0;
 	}
  time4old=0;
//  time5old=0;
  time6old=0;
  delay4 = NO_SCAN_DELAY;
//  delay5 = NO_SCAN_DELAY;
  delay6 = NO_SCAN_DELAY;
#endif // PRM_PCH_SIX_LINES

//#ifndef	PROG_PRM_PCH_L
// RestoreParameters();
// SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
//  SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
//#else
// SetAttRPU1();
//not need now SetAttRPU2();
//not need now SetAttRPU3();
//#endif //PROG_PRM_PCH_L

 setf1 = 0;
 setatt1 = 1; //0911090;
// setf2 = 0;
// setatt2 = 1; //0911090;
 modescan1 = 0;
// modescan2 = 0;
 curval1	= 0;
// curval2	= 0;
 for(i=0; i<16; i++)
	{
		embUpDownStatus1.byte[i] = 0;
//		embUpDownStatus2.byte[i] = 0;
	}

 for(i=0; i < (MAX_DATA_SIZE1 + 2); i++)
	{
       BufferAnswer[i]	= 0;
	}

ans1=0;// ans2=0;
delay1 = NO_SCAN_DELAY;
//delay2 = NO_SCAN_DELAY;
countMod=0;

#ifdef TEST_RECEIVE
 sendp = 0;
 receivep = 0;
 receivepb = 0;
 delta = 0;
 delta_old = 0;
 countt = 0;
 countr = 0;

countr_bad = 0;countr_ok = 0; countr_all = 0; countta = 0;

#endif //TEST_RECEIVE
isreceived1 = 0;
//isreceived2 = 0;
//isreceived3 = 0;
isreceived4 = 0;
//isreceived5 = 0;
isreceived6 = 0;







countTransit=0;
requestMod=0;
requestTransit=0;
cntflag6 = 0;
ErrResSNMP = 0l;
timeres = 0l;
start_count = 0;
send41 = 0l; send42 =0l; received1 =0l; received2 =0l; good1 =0l; good2 =0l; bad1 =0l; bad2 =0l;
AsciiInit();
EmbInit(); //my
  time1=0;
  flagRequest=0;
 // serr=0xFF; crc_temp=0;
  i=0;
  time1old=0; time2old=0;
  timerun=0;
  breakflag = 0;
   request1=0; request2=0;
  time3Marker=0; time3BlankTransit=0; time3BlankMod=0;
  time1test=0;
  markerWest=0; markerEast=0; ready_transit=0; ready_mod=0; dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgWest=0; delete_msgEast=0; recieveWest=0; recieveEast=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0; mode5AWest=0; mode5AEast=0; 
  mode5A232E = 0;  //1021
  mode5A485E = 0;  //1021
  mode5A485  = 0;  //1021
  cycle=0;
	ttbb=0;
	mtbb=0;
	count_tr=0;
	count_md=0;
	err_tr=0;
	err_md=0;
	rrr=0;
	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
	rBuffEmbMsg.Init();
 	embSerialACT155.Init();
    embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}
	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=0;
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;
 	unEmb2TypeVer.emb2TypeVer.type       = 0x0900;	  //???
 	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;  //add suppourt protocol	rs232 from ethernet protocol 888
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();	//was 0
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();	//was 0
	for(i=0; i<12; i++)
	{
  //		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
#ifndef PROG_PRM_PCH_L_6   //it are init before in read devise id
for(i=12; i<14; i++)
	{
  //		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
#endif


for(i=14; i<16; i++)
	{
  //		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}

 	bt = (unsigned char *)(NVRAM_BASE);

	unEmb2TypeVer.emb2TypeVer.signature_software[0] = *bt;
	unEmb2TypeVer.emb2TypeVer.signature_software[1] = *(bt+1);
	unEmb2TypeVer.emb2TypeVer.signature_software[2] = *(bt+2);
	unEmb2TypeVer.emb2TypeVer.signature_software[3] = *(bt+3);
	unEmb2TypeVer.emb2TypeVer.signature_software[4] = *(bt+4);
	unEmb2TypeVer.emb2TypeVer.signature_software[5] = *(bt+5);
	unEmb2TypeVer.emb2TypeVer.signature_software[6] = *(bt+6);
	unEmb2TypeVer.emb2TypeVer.signature_software[7] = *(bt+7);
	unEmb2TypeVer.emb2TypeVer.signature_software[8] = *(bt+8);
	unEmb2TypeVer.emb2TypeVer.signature_software[9] = *(bt+9);
	unEmb2TypeVer.emb2TypeVer.signature_software[10] = *(bt+10);
	unEmb2TypeVer.emb2TypeVer.signature_software[11] = *(bt+11);
	unEmb2TypeVer.emb2TypeVer.signature_software[12] = *(bt+12);
	unEmb2TypeVer.emb2TypeVer.signature_software[13] = *(bt+13);
	unEmb2TypeVer.emb2TypeVer.signature_software[14] = *(bt+14);
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15); 


//#ifdef PROG_PRM_PCH_L_61
   unEmb2TypeVer.emb2TypeVer.signature_software[14] = test_shift_mode;
//#endif

 	embMsgTemp.Init();

  //	outportb(4,0xff); // get all leds off

#ifdef PROG_PRM_PCH_C
    outportb(POWER_PORT, CH_PW_MASK);// | CH2_MASK  | CH3_MASK)); //get on  channel 1
 	delay1 = START_TIMEOUT;
#endif //PROG_PRM_PCH_C

#ifdef PROG_PRM_PCH_S

//#ifndef PROG_PRM_PCH_L
    outportb(POWER_PORT2, CH_PW_MASK);// | CH2_MASK  | CH3_MASK)); //get on  channel 1
 	delay4 = START_TIMEOUT;


    outportb(POWER_PORT3, CH_PW_MASK);// | CH2_MASK  | CH3_MASK)); //get on  channel 1
 	delay6 = START_TIMEOUT;


	while(embSerialACT155.UsedTransit())
		{
   			byte = embSerialACT155.GetTransit();
		} 
//091113	AlarmPmOn2();


//#endif //PROG_PRM_PCH_L

   while(embSerialACT155.UsedMod())
		{
   			byte = embSerialACT155.GetMod();
		} 

   while(embSerialACT155.UsedPower())
		{
   			byte = embSerialACT155.GetPower();
		} 


//091113	AlarmPmOn();
#endif //PROG_PRM_PCH_C

#ifndef	PROG_PRM_PCH_L
 RestoreParameters();
// SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
//  SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#else
// SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
//not need now SetAttRPU2();
//not need now SetAttRPU3();
#ifdef	PROG_PRM_PCH_L_6
//  SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#endif //PROG_PRM_PCH_L_6

#endif //PROG_PRM_PCH_L
 InitIOPins();

  pupm1.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  pupm1.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  pupm1.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
  pupm1.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
  pupm1.embpupm2.att   =  0;//emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;
  pupm1.embpupm2.prm   =  1;
  pupm1.embpupm2.type  =  0;
  pupm1.embpupm2.verp  =  1;
  pupm1.embpupm2.verh  =  1;

  pupm2.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>24;
  pupm2.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>16;
  pupm2.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>8;
  pupm2.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
  pupm2.embpupm2.att   =  0;//emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;
  pupm2.embpupm2.prm   =  1;
  pupm2.embpupm2.type  =  0;
  pupm2.embpupm2.verp  =  1;
  pupm2.embpupm2.verh  =  1;

  pupm3.embpupm2.freq3 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>24;
  pupm3.embpupm2.freq2 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>16;
  pupm3.embpupm2.freq1 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>8;
  pupm3.embpupm2.freq0 =  0;//emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
  pupm3.embpupm2.att   =  0;//emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;
  pupm3.embpupm2.prm   =  1;
  pupm3.embpupm2.type  =  0;
  pupm3.embpupm2.verp  =  1;
  pupm3.embpupm2.verh  =  1;
}


extern "C" void ClearMod()
{
    while(embSerialACT155.UsedMod())
		{
   			 embSerialACT155.GetMod();
		} 
}

extern "C" void ClearTransit()
{
while(embSerialACT155.UsedTransit())
		{
   		   embSerialACT155.GetTransit();
		} 
}


extern "C" void ClearPower()
{
while(embSerialACT155.UsedPower())
		{
   		   embSerialACT155.GetPower();
		} 
}







#ifdef PROG_PRM_PCH_C
 /*
extern "C" void CheckPower()
{
unsigned char tmppp;
   	 tmppp =  inportb(LED_PORT);
	if(!(inportb(POWER_PORT) & ALL_CH_POWER_ON))
	{
     tmppp &= ALARM_POWER;
	 }
	else
	{
     tmppp |= NO_ALARM_POWER;
	}

   if(!(inportb(POWER_PORT) & ( CH1_MASK + CH2_MASK + CH3_MASK)))
   {
  	  tmppp |= NO_ALARM_INPUT + NO_ALARM_PM;
    }
 	 outportb(LED_PORT, tmppp);
}
  */
#endif

#define PERIOD_READ_ADDRESS	(1000) //1c


extern "C" void ReadAddress()
{
unsigned long status;

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  status = pio_ptr->PDSR; //
  rs485_addr = (status >> 8);
#ifdef TEST_PARSING_COMMANDS
  rs485_addr = 2;
#endif


}

//unsigned long prm_counter;

extern "C" void PRM_PCH()
{


 prm_counter++;

static unsigned  long timer;

if(timer > time1)  timer = time1;

if(time1 > (timer + (unsigned long)PERIOD_READ_ADDRESS))
{
//printfpd("\r+ %d", timer);
//printfpd(".. %d", time1);

 timer = time1;

 ReadAddress();
 /*
#ifdef TEST_PRINT_SPI
 printfpd("\n\rmy addr: %d", rs485_addr);
 #endif
 */
//   ToPdcTu0(1);

#ifdef TEST_PARSING_COMMANDS
TestParsing();
#endif
}
else
{
//printfpd("\r %d", timer);
//printfpd(" %d", time1);

}

 
#ifdef PROG_PRM_PCH_C
#ifndef PROG_PRM_PCH_S
  unsigned char tmpp;
#endif //no PROG_PRM_PCH_S
  unsigned char power_port;
  power_port = inportb(POWER_PORT);
#endif // PROG_PRM_PCH_C

#ifdef PROG_PRM_PCH_S
  unsigned char power_port2;		  //for transit channel
  power_port2 = inportb(POWER_PORT2);
#endif // PROG_PRM_PCH_S

  unsigned char power_port3;		  //for power channel
  power_port3 = inportb(POWER_PORT3);



//______________________________________________________________________________________>>_1
//#ifdef PROG_PRM_PCH_S
//if(power_port & CH_PW_MASK_RD)
//#endif // PROG_PRM_PCH_S

 	while(embSerialACT155.UsedMod())
 //		while(0)
		{

   			byte = embSerialACT155.GetMod();
#ifdef TEST_RECEIVE
//_______________________________________________
// if(modescan1)
//	{ 
	  /*
		countr_all++;
		 if(byte != countr)
		  {
           countr_bad++;

		  printf("\n\r need : %02X receive : %02X",countr,  byte);
		  countr = byte + 1; 
		  }
		  else
		  {
			countr_ok++;

		   printf("\n\r receive : %02X",  byte);

		  countr++;
		  }
		  break;
	 */
//  }
//______________________________________________
#endif


			switch(byte)
			{
				case 0xAA: embMsgUD_1.Init();  isreceived1 = 1; break; // Пакет
				case 0x5A: mode5AWest=1; break;
				case 0x55: break;
				default:
					if(mode5AWest) 
					{
						if(isreceived1) { embMsgUD_1.Add(Modify5A(byte));}
						mode5AWest=0;
					}
					else
					{
					 if(isreceived1) 
					 {
					 embMsgUD_1.Add(byte);
					 }
					 }
			}	//switch


		if(embMsgUD_1.IsEnd())
			{
			isreceived1 = 0;
					
   //	  			countMod=0;

#ifdef PRM_PCH_DEBUG
  if(GetTestMode() == 0x50)
			{
			printfp("\n\rans:>");
 				for(i=0; i<12; i++)
				{
					{
							printfpd(".%0X",embMsgUD_1.Body(i));
					}
				}
			}
#endif
 #ifndef PROG_PRM_PCH_C
	         	AlarmsOff1();
#else // PROG_PRM_PCH_C
				AlarmPmOff();
#endif // PROG_PRM_PCH_C
   				embUpDownStatus1.embupdownstatus.received++;
#ifdef PRM_PCH_DEBUG1
 // if(countMod > 1)		//for TEST!!!!
#endif //PRM_PCH_DEBUG1
if(embMsgUD_1.ChkCRC())
	{ 
	 breakflag = 1;
     breakflag1 = 1;

	 if(GetTestMode() == 0x50)
			{
				printfpd("crc - ok countMod :%0d",countMod);
		  
			}


				 //		countMod=0;
#ifdef PRM_PCH_DEBUG1
			 time1finish = time1;
	 	  //	 if(GetTestMode() == 0x5A) 
	   	  //	 {
	   //	 	 printf("\n\rst: %ld fin: %ld d : %d count :%d", time1start, time1finish,delay1, countMod);
	   //	 printf("\n\rcrc ok");
	   	//	 }
#endif // PRM_PCH_DEBUG1
	//		 if(GetTestMode() == 0x5A) 
	  // 		 {
	   //	 	 printf("\n\rst: %ld fin: %ld d : %d count :%d", time1start, time1finish,delay1, countMod);
	  //	 printf("\n\rcrc ok");
	  // 		 }
			  countMod=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan1)
	   {
   	   	embMsgUDRequest_1.Init();  //in modescan1 = 1 it is init immediatly
		delay1 = NO_SCAN_DELAY;
	   }
#endif //COMMAND_RESENDING


#ifdef PROG_PRM_PCH_S
fl1 = 1; 
 // pupm1.embpupm2.att = 1;
  pupm1.embpupm2.prm |= ((unsigned char)PM_OK);	 //130218
 //130218 pupm1.embpupm2.prm &= ~((unsigned char)PM_OK);
  /*
  pupm1.embpupm2.freq3 =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>24;
  pupm1.embpupm2.freq2 =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>16;
  pupm1.embpupm2.freq1 =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ >>8;
  pupm1.embpupm2.freq0 =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
   */


#endif // PROG_PRM_PCH_S

#ifdef TEST_RECEIVE
 receivep++;
#endif //TEST_RECEIVE


	      ParseUD_1();	 //t
				 embUpDownStatus1.embupdownstatus.crc_ok++; 
				  embMsgUD_1.Init(); //100119
  	  }	 //crc
				else 
				{

#ifdef TEST_RECEIVE
 receivepb++;

 // 	printf("\n\r>");
 //	printf("c: %d l: %d e: > %d", embMsgUD_1.counter, embMsgUD_1.Length(), embMsgUD_1.IsEnd());

 //	printf("\n\r");
//_________________________________________________________
   for(i=0; i<12; i++)
				{
	 //				printf(".%02X",embMsgUD_1.body[i]);
				}


//_________________________________________________________



#endif //TEST_RECEIVE
				 embUpDownStatus1.embupdownstatus.crc_bad++;  
	 		   //		if(GetTestMode() == 0x5A) 
	   		   //		{
	   	 	 	//		printf("\n\rcrc bad");
	   		 	//	}
				 embMsgUD_1.Init(); //100119
 	}	//crc
  				break;
			}	//is end
 		}  //while

#ifdef TEST_RECEIVE
 

//________________________________
   //	 if(!(countsend % 200))
   /*
	 if(!(countsend % 5000))
	 {
    countta++;
	embSerialACT155.AddMod(countt++);
	printf("\n\r send: %02X", countt);
 	printf("\n\rrec-bad: %ld recok: %ld r-all: %ld  t-all: %ld", countr_bad,countr_ok, countr_all, countta);

	 return;

	 }
	 countsend++;
   */
//__________________________________
// sendp++;
#endif //TEST_RECEIVE

//if(
//(!(start1)) && (!(start2)) && (!(start3))&& (!(start4))&& (!(start5))&& (!(start6))
//)return; //t100915

#ifndef PROG_PRM_PCH_C
		if((time1-time1old) > delay1) // 10
#else
//   		if( ((time1-time1old) > delay1)	 && (power_port & CH1_MASK))
		/*
	  	printfpd("\r rw:%x ", power_port);
		printfpd(" t1:%d ", time1);
		printfpd(" t1o:%d ", time1old);
		printfpd(" del:%d ", delay1);
	//	 printfpd(" power_port:%x ", power_port);
   //		printfpd(" t4o:%d ", time4old);
   //     printfpd(" del4:%d ", delay4);
 //	printfpd(" t6o:%d ", time6old);
  //      printfpd(" del6:%d ", delay6);
	    printfpd(" rTr1:%d ",	requestMod);
	    printfpd(" rTr4:%d ",	requestTransit4);
	    printfpd(" rTr6:%d ",	requestTransit6);

		 */

 tmpg =  power_port & CH_PW_MASK_RD;

   //		 printfpd(" tmpg:%x ", tmpg);

   		if(tmpg && ((time1-time1old) > delay1))//	 && (power_port & CH1_MASK))
   //		if(tmpg)//	 && (power_port & CH1_MASK))
#endif
		{

	  //	 printfpd("\n\r _rw:%d \r\n", power_port);


	  			time1old = time1;



#ifdef PROG_PRM_PCH_C
#ifndef PROG_PRM_PCH_S

  	if(!(inportb(STATUS_PORT) & SEARCH_CHANNEL1)) //t
   	{
 	 tmpp = inportb(LED_PORT);
  	 outportb(LED_PORT, (tmpp | NO_ALARM_INPUT));
    }	  //status
  else
  {
   tmpp = inportb(LED_PORT);
   outportb(LED_PORT, (tmpp & ALARM_INPUT));
  }
#endif // no PROG_PRM_PCH_S
#endif // PROG_PRM_PCH_C

  		   if(modescan1)
		   {
		   delay1 = SCAN_DELAY;
			MakeNextStepScan1(); 
		   }
		   else
		   {
#ifndef COMMAND_RESENDING
		     delay1 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countMod) delay1 = NO_SCAN_DELAY;
			 else delay1 = RESENDING_DELAY;
#endif // COMMAND_RESENDING
		   }

	//  if(GetTestMode() == 0x5A) 
  	//  {
  	//    printf("\n\rNR");
  	//  }


		   	
			if(embMsgUDRequest_1.IsReadyToSend())
			{


#ifdef PRM_PCH_DEBUG
printfp("\n\rmbMsgUDRequest_1.IsReadyToSend \n\r");
#endif// PRM_PCH_DEBUG


#ifdef TEST_RECEIVE
 //sendp++;


//__________________________________
// sendp++;



 delta = sendp - receivep;
 if(delta != delta_old)
 // if(GetTestMode() == 0x5D) 
  //	  {
 //	  printf("\n\r>%ld",delta);
 //	  delta_old = delta;
 //	  }
 sendp++;

/*
if(pped)
{
  embMsgUDRequest_1.body[embMsgUDRequest_1.body[1]+2]	= ~(embMsgUDRequest_1.body[embMsgUDRequest_1.body[1]+2]);
  pped = 0;
}
else
{
  pped = 1;
}
*/

#endif //TEST_RECEIVE

#ifdef PRM_PCH_DEBUG1
         if(!countMod)	time1start = time1; //for test
	  //	    printf("\n\r countMOD : %d send  time : %ld",countMod, time1);
   //		    printf("\n\r t=  %ld d = %d m= %ld", time1, delay1, modescan1);
#endif // PRM_PCH_DEBUG1
	  /*
  	   if(GetTestMode() == 0x5A) 
  	  {
  	    printf("\n\r t=  %ld d = %d m= %ld", time1, delay1, modescan1);
  	  }
		 */
 
   
				countMod++;

#ifdef COMMAND_RESENDING
			    if(!modescan1) delay1 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

			    embUpDownStatus1.embupdownstatus.sendup++;		
				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
				printfp("\n\rreq1>");
		   	}
#endif
  				for(i=0; i<embMsgUDRequest_1.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
	 		  	  printfpd("_%02X",embMsgUDRequest_1.body[i]);
			}
#endif

					switch(embMsgUDRequest_1.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgUDRequest_1.body[i]);
					}
				}
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_1.Init();
#else  // COMMAND_RESENDING
	  if(modescan1)	
	  {embMsgUDRequest_1.Init();
  //	  printf("\n\r init"); //t
	  }
#endif //COMMAND_RESENDING

 			}
			else
			{
 			   if(Roulette1())
			   {
#ifdef PRM_PCH_DEBUG1
			   if(!countMod)	time1start = time1; //for test
#endif // PRM_PCH_DEBUG1

 				countMod++;
			    embUpDownStatus1.embupdownstatus.sendup++;
 				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printfp("\n\rans1>");
			}
#endif
 				for(i=0; i<embMsgUDRequest_1.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printfpd(".%02X",embMsgUDRequest_1.body[i]);
			}
#endif
					switch(embMsgUDRequest_1.body[i])
					{
						case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
						case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
						case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
						case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
						default: embSerialACT155.AddMod(embMsgUDRequest_1.body[i]);
					}
				}
				embMsgUDRequest_1.Init();
				}
			}
//time}

#ifndef PROG_PRM_PCH_C
if(countMod>TRY_SEND) 
		{

		 unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = 0;
		 unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = 0;
 	 	 AlarmsOn1();
		 setf1 = 0;
		 setatt1 = 1; //0911090;
		}
#else
	if(countMod>TRY_SEND) 
{
	 setf1 = 0;
	 setatt1 = 1; //0911090;
#ifdef COMMAND_RESENDING
	 embMsgUDRequest_1.Init();
#endif //COMMAND_RESENDING
}

#ifdef PROG_PRM_PCH_S
if(countMod> TRY_SEND) 
{
	fl1 = 0; 
 //	pupm1.embpupm2.att = 0;
  	pupm1.embpupm2.prm &= ~((unsigned char)PM_OK);
 //130218 	 pupm1.embpupm2.prm |= ((unsigned char)PM_OK);
 
  /*
	pupm1.embpupm2.freq3 = 0;
	pupm1.embpupm2.freq2 = 0;
	pupm1.embpupm2.freq1 = 0;
	pupm1.embpupm2.freq0 = 0;
	*/

}
#endif // PROG_PRM_PCH_S

#endif

} //time 091110
//after hier - ok!!!!
//if(
//(!(start1)) && (!(start2)) && (!(start3))&& (!(start4))&& (!(start5))&& (!(start6))
//)return; //t100915



//_______________________________________________________________________________________<<

//_______________________________________________________________________________________>>
#ifdef PROG_PRM_PCH_S //hier will make 5 channells add 2 to modem and make 3 to transit


//______________________________________________________________________________________>>_2
/*
if(power_port & CH2_MASK)
	while(embSerialACT155.UsedMod())
		{
   			byte = embSerialACT155.GetMod();
			switch(byte)
			{
				case 0xAA: embMsgUD_2.Init();  isreceived2 = 1; break; // Пакет
				case 0x5A: mode5AWest2=1; break;
				case 0x55: break;
				default:
					if(mode5AWest2) 
					{
					   if(isreceived2) {	embMsgUD_2.Add(Modify5A(byte));	}
						mode5AWest2=0;
					}
					else  {
					
					   if(isreceived2) {embMsgUD_2.Add(byte); }
					 }
			}
			if(embMsgUD_2.IsEnd())
			{	
			   isreceived2 = 0;
	  	//	 countMod2=0;

#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
  		 		printf("\n\r>");

				for(i=0; i<12; i++)
				{
					{
							printf(".%0X",embMsgUD_2.Body(i));
					}
				}
			 }
#endif
				AlarmPmOff();  //
   				embUpDownStatus2.embupdownstatus.received++;
				if(embMsgUD_2.ChkCRC())	{ breakflag = 1;
				 countMod2=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan2)
   	   	{
   	   	embMsgUDRequest_2.Init();  //in modescan1 = 1 it is init immediatly
		delay2 = NO_SCAN_DELAY;
	   }

#endif //COMMAND_RESENDING

				  fl2 = 1;
			 	  ParseUD_2();	 //t
			      embUpDownStatus2.embupdownstatus.crc_ok++;  }
				else {embUpDownStatus2.embupdownstatus.crc_bad++;  }
				 embMsgUD_2.Init();
				break;
			}  //is end
 		}	//while
		if( ((time1-time2old) > delay2)	 && (!(start1)) &&  (power_port & CH2_MASK)) //t
		{
	  			time2old = time1;
  		   if(modescan2)
		   {
		   delay2 = SCAN_DELAY;
			MakeNextStepScan2(); 
		   }
		   else
		   {
	//	   delay2 = NO_SCAN_DELAY;
#ifndef COMMAND_RESENDING
		     delay2 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countMod2) delay2 = NO_SCAN_DELAY;
			 else delay2 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

		   }	
			if(embMsgUDRequest_2.IsReadyToSend())
			{
					countMod2++;
#ifdef COMMAND_RESENDING
			    if(!modescan2) delay2 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

  
			embUpDownStatus2.embupdownstatus.sendup++;		
				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
				printf("\n\r_FF_AA");
		   	}
#endif
  				for(i=0; i<embMsgUDRequest_2.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		 		  	  printf("_%02X",embMsgUDRequest_2.body[i]);
			}
#endif

					switch(embMsgUDRequest_2.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgUDRequest_2.body[i]);
					}
				}
 //  	 	embMsgUDRequest_2.Init();
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_2.Init();
#else  // COMMAND_RESENDING
	  if(modescan2)	embMsgUDRequest_2.Init();
#endif //COMMAND_RESENDING

 			}
			else
			{
 			   if(Roulette2())
			   {
 				countMod2++;
			   embUpDownStatus2.embupdownstatus.sendup++;
 				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf("\n\r.FF.AA");
		    }
#endif
 				for(i=0; i<embMsgUDRequest_2.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf(".%02X",embMsgUDRequest_2.body[i]);
			}
#endif
					switch(embMsgUDRequest_2.body[i])
					{
						case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
						case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
						case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
						case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
						default: embSerialACT155.AddMod(embMsgUDRequest_2.body[i]);
					}
				}
				embMsgUDRequest_2.Init();
				}
			}
//09110}

if(countMod2>5) 
{
  		 setf2 = 0;
  		 setatt2 = 1; //0911090;
		 fl2 = 0;
#ifdef COMMAND_RESENDING
	 embMsgUDRequest_2.Init();
#endif //COMMAND_RESENDING

}

} //091110
*/
//_______________________________________________________________________________________<<	_2
//______________________________________________________________________________________>>_3
   /*
if(power_port & CH3_MASK)
	while(embSerialACT155.UsedMod())
		{
   			byte = embSerialACT155.GetMod();
			switch(byte)
			{
				case 0xAA: embMsgUD_3.Init(); isreceived3 = 1; break; // Пакет
				case 0x5A: mode5AWest3=1; break;
				case 0x55: break;
				default:
					if(mode5AWest3) 
					{
						 if(isreceived3) {	embMsgUD_3.Add(Modify5A(byte));	}
						mode5AWest3=0;
					}
					else
					{
					 if(isreceived3) {	 embMsgUD_3.Add(byte);	 }
					 }
			}
			if(embMsgUD_3.IsEnd())
			{		
	  	   //		countMod3=0;
			   isreceived3 = 0;
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
  		 		printf("\n\r>");

				for(i=0; i<12; i++)
				{
					{
							printf(".%0X",embMsgUD_3.Body(i));
					}
				}
			}
#endif
				AlarmPmOff();  //
   				embUpDownStatus3.embupdownstatus.received++;
				if(embMsgUD_3.ChkCRC())	{  breakflag = 1;
						countMod3=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan3)
   	   	{
   	   	embMsgUDRequest_3.Init();  //in modescan1 = 1 it is init immediatly
		delay3 = NO_SCAN_DELAY;
	   }

#endif //COMMAND_RESENDING

				fl3 = 1;
			 	  ParseUD_3();	 //t
				 embUpDownStatus3.embupdownstatus.crc_ok++;  }
				else {embUpDownStatus3.embupdownstatus.crc_bad++;  }
				 embMsgUD_3.Init();
				break;
			}
 		}
		if( ((time1-time3old) > delay3)	 && (!(start2)) &&  (power_port & CH3_MASK)) //t
		{
	  			time3old = time1;
  		   if(modescan3)
		   {
		   delay3 = SCAN_DELAY;
			MakeNextStepScan3(); 
		   }
		   else
		   {
 //		   delay3 = NO_SCAN_DELAY;
#ifndef COMMAND_RESENDING
		     delay3 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countMod3) delay3 = NO_SCAN_DELAY;
			 else delay3 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

		   }	
			if(embMsgUDRequest_3.IsReadyToSend())
			{
					countMod3++;
#ifdef COMMAND_RESENDING
			    if(!modescan3) delay3 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

			embUpDownStatus3.embupdownstatus.sendup++;		
				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
				printf("\n\r_FF_AA");
			}
#endif
  				for(i=0; i<embMsgUDRequest_3.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		 		  	  printf("_%02X",embMsgUDRequest_3.body[i]);
		     }
#endif

					switch(embMsgUDRequest_3.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgUDRequest_3.body[i]);
					}
				}
 //  	 	embMsgUDRequest_3.Init();
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_3.Init();
#else  // COMMAND_RESENDING
	  if(modescan3)	embMsgUDRequest_3.Init();
#endif //COMMAND_RESENDING

 			}
			else
			{
 			   if(Roulette3())
			   {
 				countMod3++;
			   embUpDownStatus3.embupdownstatus.sendup++;
 				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf("\n\r.FF.AA");
				  }
#endif
 				for(i=0; i<embMsgUDRequest_3.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf(".%02X",embMsgUDRequest_3.body[i]);
			 }
#endif
					switch(embMsgUDRequest_3.body[i])
					{
						case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
						case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
						case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
						case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
						default: embSerialACT155.AddMod(embMsgUDRequest_3.body[i]);
					}
				}
				embMsgUDRequest_3.Init();
				}
			}
//091110}
if(countMod3>5) 
{
  		 setf3 = 0;
  		 setatt3 = 1; //0911090;
		 fl3 = 0;
#ifdef COMMAND_RESENDING
	 embMsgUDRequest_3.Init();
#endif //COMMAND_RESENDING

}
} //091110
			   */
//_______________________________________________________________________________________<<	_3
//#ifndef PROG_PRM_PCH_L
//_______________________________________________________________________________________>>_4
//if(power_port2 & CH_PW_MASK_RD)
		while(embSerialACT155.UsedTransit())
		{
			byte = embSerialACT155.GetTransit();
		  //	 printf(".%0X", byte);	//t

			switch(byte)
			{
				case 0xAA: embMsgUD_4.Init(); isreceived4 = 1; break; // Пакет
				case 0x5A: mode5AEast=1; break;
				default:
					if(mode5AEast) 
					{
						 if(isreceived4) { embMsgUD_4.Add(Modify5A(byte));	}
						mode5AEast=0;
					}
					else 
					{
					  if(isreceived4) {embMsgUD_4.Add(byte); }
					 }
			}
			if(embMsgUD_4.IsEnd())
			{		
		  			//	countTransit4=0;
			 isreceived4 = 0;
			 
 	   
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			 printfp("\n\rans4>");
				for(i=0; i<12; i++)
				{
					
						printfpd(".%0X",embMsgUD_4.Body(i));
					
				}
		   	}
#endif // PRM_PCH_DEBUG
				AlarmPmOff2();  //make in future
				embUpDownStatus4.embupdownstatus.received++;
				if(embMsgUD_4.ChkCRC())	{
				
				  breakflag = 1;
				    breakflag4 = 1;

 if(GetTestMode() == 0x50)
			{
				printfp("crc4 - ok ");
		  
			}

					countTransit4=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan4)
   	   	{
   	   	embMsgUDRequest_4.Init();  //in modescan1 = 1 it is init immediatly
		delay4 = NO_SCAN_DELAY;
	   }

#endif //COMMAND_RESENDING

				fl4 =1;
				
			//		pupm2.embpupm2.att = 1;

	 			pupm2.embpupm2.prm |= ((unsigned char)PM_OK);
	 //130218 			 pupm2.embpupm2.prm &= ~((unsigned char)PM_OK);

			   /*
  				pupm2.embpupm2.freq3 =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>24;
  				pupm2.embpupm2.freq2 =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>16;
  				pupm2.embpupm2.freq1 =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ >>8;
 				pupm2.embpupm2.freq0 =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
				  */


				ParseUD_4();
				embUpDownStatus4.embupdownstatus.crc_ok++;  
			 }
				else { embUpDownStatus4.embupdownstatus.crc_bad++;	}
				 embMsgUD_4.Init();
				break;
			}
		}
   //		if( ((time1-time4old) > delay4)	 &&  (power_port2 & CH4_MASK)) // <<<! make later
		if( ((time1-time4old) > delay4)	 &&  (power_port2 & CH_PW_MASK_RD)) // <<<! make later
		{
			time4old = time1;

//if(GetTestMode() == 0x50)
  //			{

	//   	  printfp("\n\r >>4");	 //ok
	  //	  }

  		  if(modescan4)
		   {
//if(GetTestMode() == 0x50)
  //			{

	//   	  printfp("\n\r >>4a");	 //no
	  //	  }

			MakeNextStepScan4(); 
			delay4 = SCAN_DELAY;
		   }	
		   else
		   {

//if(GetTestMode() == 0x50)
  	 //		{

	   //	  printfp("\n\r >>4b");	 //ok
		//  }

//			delay4 = NO_SCAN_DELAY;
#ifndef COMMAND_RESENDING
		     delay4 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countTransit4) delay4 = NO_SCAN_DELAY;
			 else delay4 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

		   }


//if(GetTestMode() == 0x50)
  //			{

	//   	  printfp("\n\r >>4_1");	 //ok
	  //	  }


			if(embMsgUDRequest_4.IsReadyToSend())
			{

//if(GetTestMode() == 0x50)
  //			{

	//   	  printfp("\n\r >>4_2");	 //no
	  //	  }



					countTransit4++;
#ifdef COMMAND_RESENDING
			    if(!modescan4) delay4 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

			embUpDownStatus4.embupdownstatus.sendup++;
	  
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		 		  printfp("\n\rreq4>-FF-AA");
				  }
#endif //PRM_PCH_DEBUG

				embSerialACT155.AddTransit(0xFF);
		 		embSerialACT155.AddTransit(0xAA);
	  	 		for(i=0; i<embMsgUDRequest_4.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		   	  printfpd("-%02X",embMsgUDRequest_4.body[i]);
		    }
#endif //PRM_PCH_DEBUG
					switch(embMsgUDRequest_4.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_4.body[i]);
					}
				}
   //			   embMsgUDRequest_4.Init();
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_4.Init();
#else  // COMMAND_RESENDING
	  if(modescan4)	embMsgUDRequest_4.Init();
#endif //COMMAND_RESENDING

			}
			else
			{

//if(GetTestMode() == 0x50)
  //			{

	//   	  printfp("\n\r >>4_3");	 //no
	  //	  }

		 		if (Roulette4())
				{

//if(GetTestMode() == 0x50)
 //			{

  //	   	  printfp("\n\r >>4_4");	 //no
  //		  }



						countTransit4++;
			 	embUpDownStatus4.embupdownstatus.sendup++;


				embSerialACT155.AddTransit(0xFF);
				embSerialACT155.AddTransit(0xAA);

#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printfp("\n\r+FF+AA");
			}
#endif
 				for(i=0; i<embMsgUDRequest_4.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printfpd("+%02X",embMsgUDRequest_4.body[i]);
		     }
#endif

// 				for(i=0; i<embMsgUDRequest_4.Length()+3; i++) 
//				{
					switch(embMsgUDRequest_4.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_4.body[i]);
					}
				}
						embMsgUDRequest_4.Init();	//060919
				}
			}
//091110}

		if(countTransit4 > TRY_SEND) 
		{
  		 setf4 = 0;
  		 setatt4 = 1; //0911090;
		 fl4 = 0; 
		  /*
	    pupm2.embpupm2.att = 0;
		pupm2.embpupm2.freq3 = 0;
	 	pupm2.embpupm2.freq2 = 0;
	 	pupm2.embpupm2.freq1 = 0;
	 	pupm2.embpupm2.freq0 = 0;
		   */


	 	 pupm2.embpupm2.prm &= ~((unsigned char)PM_OK);
   //130218 		 pupm2.embpupm2.prm |= ((unsigned char)PM_OK);

#ifdef COMMAND_RESENDING
	 embMsgUDRequest_4.Init();
#endif //COMMAND_RESENDING

		}
} //091110
//_______________________________________________________________________________________<<_4

//_______________________________________________________________________________________>>_5
   /*
if(power_port2 & CH5_MASK)
		while(embSerialACT155.UsedTransit())
		{
			byte = embSerialACT155.GetTransit();
		  //	 printf(".%0X", byte);	//t

			switch(byte)
			{
				case 0xAA: embMsgUD_5.Init(); isreceived5 = 1; break; // Пакет
				case 0x5A: mode5AEast=1; break;
				default:
					if(mode5AEast) 
					{
						 if(isreceived5) { embMsgUD_5.Add(Modify5A(byte));}
						mode5AEast=0;
					}
					else 
					{
					if(isreceived5) { embMsgUD_5.Add(byte);	}
					}
			}
			if(embMsgUD_5.IsEnd())
			{		
		 // 	  countTransit5=0;
		   isreceived5 = 0;	
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
				printf("\n\r>");
				for(i=0; i<12; i++)
				{
					
						printf(".%0X",embMsgUD_5.Body(i));
					
				}
		  	}
#endif // PRM_PCH_DEBUG
				AlarmPmOff2();  //make in future
				embUpDownStatus5.embupdownstatus.received++;
				if(embMsgUD_5.ChkCRC())	{	breakflag = 1;
				 	  countTransit5=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan5)
   	   	{
   	   	embMsgUDRequest_5.Init();  //in modescan1 = 1 it is init immediatly
		delay5 = NO_SCAN_DELAY;
	   }

#endif //COMMAND_RESENDING
				 
				  fl5 = 1;
				ParseUD_5();
				embUpDownStatus5.embupdownstatus.crc_ok++;   }
				else { embUpDownStatus5.embupdownstatus.crc_bad++;	}
				 embMsgUD_5.Init();
				break;
			}
		}
		if( ((time1-time5old) > delay5)	 && (!(start4)) &&  (power_port2 & CH5_MASK)) // <<<4 is finished
		{
			time5old = time1;
  		  if(modescan5)
		   {
			MakeNextStepScan5(); 
			delay5 = SCAN_DELAY;
		   }	
		   else
		   {
//			delay5 = NO_SCAN_DELAY;
#ifndef COMMAND_RESENDING
		     delay5 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countTransit5) delay5 = NO_SCAN_DELAY;
			 else delay5 = RESENDING_DELAY;
#endif // COMMAND_RESENDING



		   }
			if(embMsgUDRequest_5.IsReadyToSend())
			{
					countTransit5++;
#ifdef COMMAND_RESENDING
			    if(!modescan5) delay5 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

			embUpDownStatus5.embupdownstatus.sendup++;
	  
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		 		  printf("\n\r.FF.AA");
		     }
#endif //PRM_PCH_DEBUG

				embSerialACT155.AddTransit(0xFF);
		 		embSerialACT155.AddTransit(0xAA);
	  	 		for(i=0; i<embMsgUDRequest_5.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		   	  printf(".%02X",embMsgUDRequest_5.body[i]);
			}
#endif //PRM_PCH_DEBUG
					switch(embMsgUDRequest_5.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_5.body[i]);
					}
				}
  //			   embMsgUDRequest_5.Init();
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_5.Init();
#else  // COMMAND_RESENDING
	  if(modescan5)	embMsgUDRequest_5.Init();
#endif //COMMAND_RESENDING

			}
			else
			{
		 		if (Roulette5())
				{
						countTransit5++;
			 	embUpDownStatus5.embupdownstatus.sendup++;


				embSerialACT155.AddTransit(0xFF);
				embSerialACT155.AddTransit(0xAA);

#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf("\n\r.FF.AA");
		    }
#endif
 				for(i=0; i<embMsgUDRequest_5.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf(".%02X",embMsgUDRequest_5.body[i]);
		    }
#endif

// 				for(i=0; i<embMsgUDRequest_5.Length()+3; i++) 
//				{
					switch(embMsgUDRequest_5.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_5.body[i]);
					}
				}
						embMsgUDRequest_5.Init();	//060919
				}
			}
//091110}

		if(countTransit5>5) 
		{
  		 setf5 = 0;
  		 setatt5 = 1; //0911090;
		 fl5 = 0;
#ifdef COMMAND_RESENDING
	 embMsgUDRequest_5.Init();
#endif //COMMAND_RESENDING

		}
} //091110
//_______________________________________________________________________________________<<_5
*/

//_______________________________________________________________________________________>>_6

//if(power_port2 & CH6_MASK)
//if(power_port3 & CH_PW_MASK_RD)
	 //	while(embSerialACT155.UsedTransit())
		while(embSerialACT155.UsedPower())
		{
			byte = embSerialACT155.GetPower();
		  //	 printf(".%0X", byte);	//t

			switch(byte)
			{
				case 0xAA: embMsgUD_6.Init(); isreceived6 = 1; break; // Пакет
				case 0x5A: mode5AEast=1; break;
				default:
					if(mode5AEast) 
					{
					    if(isreceived6) {	embMsgUD_6.Add(Modify5A(byte));}
						mode5AEast=0;
					}
					else
					 {
					    if(isreceived6) { embMsgUD_6.Add(byte);}
					 }
			}
			if(embMsgUD_6.IsEnd())
			{		
		  		   //		countTransit6=0;
			  isreceived6 = 0;		  
 	   
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
				printf("\n\r>");
				for(i=0; i<12; i++)
				{
					
						printf(".%0X",embMsgUD_6.Body(i));
					
				}
		   	}
#endif // PRM_PCH_DEBUG
				AlarmPmOff2();  //make in future
				embUpDownStatus6.embupdownstatus.received++;
				if(embMsgUD_6.ChkCRC())	{  breakflag = 1;
						countTransit6=0;
#ifdef COMMAND_RESENDING
   	   if(!modescan6)
   	   {
   	   	embMsgUDRequest_6.Init();  //in modescan1 = 1 it is init immediatly
		delay6 = NO_SCAN_DELAY;
	   }

#endif //COMMAND_RESENDING

				fl6 =1;
				ParseUD_6();
				embUpDownStatus6.embupdownstatus.crc_ok++;   }
				else { embUpDownStatus6.embupdownstatus.crc_bad++;	}
				 embMsgUD_6.Init();
				break;
			}
		}
	//	if( ((time1-time6old) > delay6)	 && (!(start5)) &&  (power_port2 & CH6_MASK)) // <<<5 is finished  
		if( ((time1-time6old) > delay6)	  &&  (power_port3 & CH_PW_MASK_RD)) // <<<5 is finished
			{
			time6old = time1;
  		  if(modescan6)
		   {
			MakeNextStepScan6(); 
			delay6 = SCAN_DELAY;
		   }	
		   else
		   {
//			delay6 = NO_SCAN_DELAY;
#ifndef COMMAND_RESENDING
		     delay6 = NO_SCAN_DELAY;
#else  // COMMAND_RESENDING
			 if(!countTransit6) delay6 = NO_SCAN_DELAY;
			 else delay6 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

		   }
		if(embMsgUDRequest_6.IsReadyToSend())
			{
					countTransit6++;
#ifdef COMMAND_RESENDING
			    if(!modescan6) delay6 = RESENDING_DELAY;
#endif // COMMAND_RESENDING

			embUpDownStatus6.embupdownstatus.sendup++;
	  
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		 		  printf("\n\r.FF.AA");
			}
#endif //PRM_PCH_DEBUG

				embSerialACT155.AddPower(0xFF);
		 		embSerialACT155.AddPower(0xAA);
	  	 		for(i=0; i<embMsgUDRequest_6.Length()+5; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
		   	  printf(".%02X",embMsgUDRequest_6.body[i]);
			}
#endif //PRM_PCH_DEBUG
					switch(embMsgUDRequest_6.body[i])
					{
					case 0x5A: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x00); break;
					case 0x55: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x01); break;
					case 0xA5: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x02); break;
					case 0xAA: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x03); break;
					default: embSerialACT155.AddPower(embMsgUDRequest_6.body[i]);
					}
				}
//			   embMsgUDRequest_6.Init();
#ifndef COMMAND_RESENDING
   	 	embMsgUDRequest_6.Init();
#else  // COMMAND_RESENDING
	  if(modescan6)	embMsgUDRequest_6.Init();
#endif //COMMAND_RESENDING

			}
			else
			{
		 		if (Roulette6())
				{
						countTransit6++;
			 	embUpDownStatus6.embupdownstatus.sendup++;


				embSerialACT155.AddPower(0xFF);
				embSerialACT155.AddPower(0xAA);
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf("\n\r.FF.AA");
		    }
#endif
 				for(i=0; i<embMsgUDRequest_6.Length()+3; i++) 
				{
#ifdef PRM_PCH_DEBUG
if(GetTestMode() == 0x50)
			{
			  	  printf(".%02X",embMsgUDRequest_6.body[i]);
		    }
#endif

// 				for(i=0; i<embMsgUDRequest_6.Length()+3; i++) 
//				{
					switch(embMsgUDRequest_6.body[i])
					{
					case 0x5A: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x00); break;
					case 0x55: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x01); break;
					case 0xA5: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x02); break;
					case 0xAA: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x03); break;
					default: embSerialACT155.AddPower(embMsgUDRequest_6.body[i]);
					}
				}
						embMsgUDRequest_6.Init();	//060919
				}
			}
//091110}

		if(countTransit6>5) 
		{
  		 setf6 = 0;
  		 setatt6 = 1; //0911090;
		 fl6 = 0;
#ifdef COMMAND_RESENDING
	 embMsgUDRequest_6.Init();
#endif //COMMAND_RESENDING

		}
} //091110

//_______________________________________________________________________________________<<_6
//#endif //no   PROG_PRM_PCH_L

#endif // PROG_PRM_PCH_S


//if(
//(!(start1)) && (!(start2)) && (!(start3))&& (!(start4))&& (!(start5))&& (!(start6))
//)return; //t100915

//________________________________________________________________________________________<<







//===============================================
#ifdef PROG_PRM_PCH_C
 CheckAlarmsPm();
#endif //   PROG_PRM_PCH_C
//===============================================
 		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;
#ifdef PRM_PCH_THREE_LINES
   //		old_ready_power = ready_power; 
#endif // PRM_PCH_THREE_LINES



#ifdef	   PROG_PRM_PCH_L
		
 		   if(GetNeedWriteDevId())
		   {
	   //	   printf("\n\r Write!!"); //t
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }
		   
#endif     // PROG_PRM_PCH_L


//////////////////////////////////////////////////
  /*
#ifndef PROG_PRM_PCH_N

// #include checkremoteprm_pch.inc
// #include answerprm_pch.inc
// ????
 #include checkremotepupm2.c
 #include answerpupm2.c
	 

#endif //PROG_PRM_PCH_N
   */
}

//#ifdef PROG_PRM_PCH_N

extern "C" void Remote_PRM_PCH(void)
{
// #include checkremoteprm_pch.inc
// #include answerprm_pch.inc
 #include checkremotepupm3_1.c
 #include answerpupm3_1.c

}

//#endif //PROG_PRM_PCH_N





//}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : none
* Comments         :
*    This routine is used to port embisr to be called from timer isr
*END*----------------------------------------------------------------------*/

extern "C" void time_notify_core(void)	// called frequency = 1 ms
 {
 //hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;
   	TimerCounter1 ++;
 	timeres++; 
  } 

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq1(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq1
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq1()
{
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{
#ifdef IncEmbSerialMD34AVT
  embSerialACT155.IsrXX();
#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
   my_int_enable_irq0();
}
//#ifdef PROG_BMD155

//__________________________________________________________________________________
struct EmbHittite
{
	unsigned bit0: 1;
	unsigned bit1: 1;
	unsigned bit2: 1;
	unsigned bit3: 1;
	unsigned bit4: 1;
	unsigned bit5: 1;
	unsigned bit6: 1;
	unsigned bit7: 1;
};

union UnEmbHittite
{
	EmbHittite eh;
	unsigned char b;
};

typedef	unsigned long long __int64;

//#include "formula9.c"
#include "formula_1L.cpp"

//#include "formula9tst3.c"
//#include "formula9tst7.c"
//#include "formula9tst8.c"


extern "C" void  ParseCommand1()
{
	 add_char_TCP_buff(TYPE_AUTO);
	 for(long i = 0; i < 44; i++)
	 {
	   add_char_TCP_buff(unEmb2TypeVer.byte[i]);
	 }
	 breakflag =1; 
}

extern "C" void  GetCode1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
   /*
extern "C" void  GetCode2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
		*/


extern "C" void  GetLockLevel1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
 /*
extern "C" void  GetLockLevel2()
{

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
			  */
extern "C" void  GetTemp1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
  /*
extern "C" void  GetTemp2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
		*/
extern "C" void  Get48_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
	/*
extern "C" void  Get48_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
		   */
extern "C" void  Get24_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
   /*
extern "C" void  Get24_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
	*/
extern "C" void  Get7_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
 /*
extern "C" void  Get7_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
   */
extern "C" void  Get5_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
   /*
extern "C" void  Get5_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
	 */
extern "C" void  Get5M_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
	  /*
extern "C" void  Get5M_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
	 */


extern "C" void  SetFreq1()
{
static unsigned char b2_keep = 0;
 if(GetTestMode() == 0x50)
{
 printfpd("\n\rf> %d", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
}

unsigned char * b = Formula1L(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ,Band1);

#ifdef PRM_USE_ATT_C12 
b[3] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
#endif

unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin1.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin1.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin1.emb5statusgeterodin.get2 = *get2;

 
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }
//____________________________________________________________________________
//	printf("\n\r freq1 = %ld" , emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FORMULA_LEN); //em
			    for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , b[i]);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetAtt1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
	  /*
extern "C" void  SetAttRPU1(unsigned char val)
{

#ifdef MAX_LOW_ATT
   unEmb2TypeVer.emb2TypeVer.signature_software[12] = FIX_ATT;
   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = FIX_ATT >> 1;
   val = FIX_ATT;
#endif


AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);
//#ifdef PROG_PRM_PCH_L_61
	_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);
//#endif

//____
//added 14
//____

  val >>= 1;

  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_15;} else{pio_ptr->SODR = MASK_BIT_15;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_17;} else{pio_ptr->SODR = MASK_BIT_17;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_19;} else{pio_ptr->SODR = MASK_BIT_19;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_22;} else{pio_ptr->SODR = MASK_BIT_22;}

//#ifdef PROG_PRM_PCH_L_61
   pio_ptr->CODR = MASK_BIT_14; //set olweis to zero 14
//#endif
}
	  */
	/*
extern "C" void  SetAttRPU1_5bits(unsigned char val)
{
 // printfp("setattrpu1_5bits");
#ifdef MAX_LOW_ATT
   unEmb2TypeVer.emb2TypeVer.signature_software[12] = FIX_ATT;
   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = FIX_ATT >> 1;
   val = FIX_ATT;
#endif


AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   

//____
//added 14
//____

  val >>= 1;
  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_14;} else{pio_ptr->SODR = MASK_BIT_14;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_15;} else{pio_ptr->SODR = MASK_BIT_15;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_17;} else{pio_ptr->SODR = MASK_BIT_17;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_19;} else{pio_ptr->SODR = MASK_BIT_19;}
  if(!(val & MASK_BIT_4)) { pio_ptr->CODR = MASK_BIT_22;} else{pio_ptr->SODR = MASK_BIT_22;}
  
}

	   */



//extern "C" void  SetAttRPU2()
//{
			   
//}

//extern "C" void  SetAttRPU3()
//{
			   
//}
	/*
extern "C" void  SetAttRPU4(unsigned char val)
{

 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);
//#ifdef PROG_PRM_PCH_L_61
	_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);
//#endif


//___________________
// +7
//_____________________

val >>= 1;


  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_8;} else{pio_ptr->SODR = MASK_BIT_8;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_10;} else{pio_ptr->SODR = MASK_BIT_10;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_12;} else{pio_ptr->SODR = MASK_BIT_12;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_13;} else{pio_ptr->SODR = MASK_BIT_13;}
//#ifdef PROG_PRM_PCH_L_61
   pio_ptr->CODR = MASK_BIT_7; //set olweis to zero 7
//#endif
			   
}

extern "C" void  SetAttRPU4_5bits(unsigned char val)
{

 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);




//___________________
// +7
//_____________________

val >>= 1;

  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_7;} else{pio_ptr->SODR = MASK_BIT_7;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_8;} else{pio_ptr->SODR = MASK_BIT_8;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_10;} else{pio_ptr->SODR = MASK_BIT_10;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_12;} else{pio_ptr->SODR = MASK_BIT_12;}
  if(!(val & MASK_BIT_4)) { pio_ptr->CODR = MASK_BIT_13;} else{pio_ptr->SODR = MASK_BIT_13;}
			   
}

	 */
//extern "C" void  SetAttRPU5()
//{
			   
//}
//extern "C" void  SetAttRPU6()
//{
			   
//}


   /*

extern "C" void  SetFreq2()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ,Band2);

unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin2.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin2.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin2.emb5statusgeterodin.get2 = *get2;



 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i, b[i]);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  SetAtt2()
{

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_2.SetBody(1, emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
	   */
extern "C" void  KeepParam(unsigned long dataparam , unsigned long addrparam)
{
 unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;		  
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
}

extern "C" unsigned long  RestoreParam(unsigned long addrparam)
{
 unsigned long dataparam = 0;
 unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
   dataparam = *(bt + addrparam + NVRAM_PARAMETERS_STORAGE);		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 8;		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 16;		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 24;	
 return  dataparam;
}

extern "C" void  RestoreParameters()
{

   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ1_ADDR);
   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
 //  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ2_ADDR);
 //  emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT1_ADDR);
//091104   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 //  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT2_ADDR);
//091104   emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT1_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU1();
 //  emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT2_ADDR_RPU);
 //   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU2();


#ifdef PRM_PCH_THREE_LINES
		   /*
   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ3_ADDR);
   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT3_ADDR);
//091104   emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT3_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
 //	 SetAttRPU3();
			  */

#endif //PRM_PCH_THREE_LINES


#ifdef PRM_PCH_SIX_LINES
//_______________________________________________________________________________________________
   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ4_ADDR);
   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT4_ADDR);
   emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT4_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt;
   //	 SetAttRPU4();
  /*
   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ5_ADDR);
   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT5_ADDR);
   emb5StatusReciever5.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT5_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU5();


   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ6_ADDR);
   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT6_ADDR);
   emb5StatusReciever6.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT6_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU6();
	 */
//_______________________________________________________________________________________________
#endif //PRM_PCH_SIX_LINES






}
extern "C" void  ParseCommand2(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
       	   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
		   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
		   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
		   SetFreq1();
			// Stephany19++;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
		/*
case  2 : 
		   modescan2 = 0;
		  countMod2 = 0;
	      delay2 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ , FREQ2_ADDR);
		   emb5StatusReciever2.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
		   SetFreq2();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
					 */
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
		  modescan3 = 0;
		  countMod3 = 0;
		  delay3 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ , FREQ3_ADDR);
		   emb5StatusReciever3.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
		   SetFreq3();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L
			 break;
			 */
#endif //PRM_PCH_THREE_LINES
#ifdef PRM_PCH_SIX_LINES
//____________________________________________________________________
case  4 : 
		  modescan4 = 0;
		  countTransit4 = 0;
		  delay4 = NO_SCAN_DELAY;

		   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ , FREQ4_ADDR);
		   emb5StatusReciever4.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
		   SetFreq4();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
//____________________________________________________________________
//____________________________________________________________________
/*
case  5 : 

		  modescan5 = 0;
		  countTransit5 = 0;
		  delay5 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ , FREQ5_ADDR);
		   emb5StatusReciever5.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
		   SetFreq5();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
//____________________________________________________________________
   */
//____________________________________________________________________
case  6 : 
		  modescan6 = 0;
		  countTransit6 = 0;
		  delay6 = NO_SCAN_DELAY;
		  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ , FREQ6_ADDR);
		   emb5StatusReciever6.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
		   SetFreq6();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
			 
//____________________________________________________________________


#endif //PRM_PCH_SIX_LINES


default :    
  break;
	}

}

#define CORR_MASK (0x7F)

extern "C" unsigned char MakeAtt(unsigned char inpval)
{
  unsigned char outval;
  unsigned char ht;
//  unsigned char lt;
/*
  if(inpval > 60) {lt = 0xf; ht = 0xf;}
  else if(inpval >= 30) {	ht = 0xf; lt = ((inpval - 30) >> 1);}
  else{ht = inpval >> 1; lt = 0;}
  outval = (ht << 4) + lt;
  outval &= CORR_MASK;
*/
  if(inpval <= 30) ht = inpval >> 1;
  else ht = 0x0f;
  outval = ht << 4;
  return outval;
}

extern "C" unsigned char MakeAttBack(unsigned char inpval)
{
  unsigned char outval;
  unsigned char ht;
  unsigned char lt;

  lt = inpval & 0xf;
  ht = (inpval & 0xf0) >> 4;
/*
  if(lt) {outval = ((lt << 1) + 30);}
  else 	 {outval = ht << 1;}
*/
  outval = ht << 1;
  return outval;
}


extern "C" void  ParseCommand3(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
		 		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);
		   SetAtt1();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	  //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt , ATT2_ADDR);		  
		    SetAtt2();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
				*/
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	//		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt , ATT3_ADDR);		  
		    SetAtt3();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
				*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt , ATT4_ADDR);		  
		    SetAtt4();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________
		   /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	 //		emb5StatusReciever5.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt , ATT5_ADDR);		  
		    SetAtt5();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________
   */
//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	//		emb5StatusReciever6.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt , ATT6_ADDR);		  
		    SetAtt6();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
			
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

}

extern "C" void  ParseCommand4(char *IPBuff)
{
 long i;
	  breakflag =1; 


	 add_char_TCP_buff(TYPE_STATUS);

switch(IPBuff[1])
	{
case  1 :  
			 modescan1 = 0;
  			 delay1 = NO_SCAN_DELAY;
			 emb5StatusReciever1.emb5statusreciever.genStatus =  2; //IPBuff[2];
			 add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever1.byte[i]);
	 		} 
  			break;
			/*
case  2 :   
			  modescan2 = 0;
			  delay2 = NO_SCAN_DELAY;

			  emb5StatusReciever2.emb5statusreciever.genStatus = 2;// IPBuff[2];
		    add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever2.byte[i]);
	 		}
 			break;
			*/
#ifdef PRM_PCH_THREE_LINES
		/*
case  3 :   
			  modescan3 = 0;
			  delay3 = NO_SCAN_DELAY;
			  emb5StatusReciever3.emb5statusreciever.genStatus = 2;// IPBuff[2];
		    add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever3.byte[i]);
	 		}
 			break;
			*/
 #endif //  PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//__________________________________________________________
case  4 :   
			  modescan4 = 0;
			  delay4 = NO_SCAN_DELAY;
			  emb5StatusReciever4.emb5statusreciever.genStatus = 2;// IPBuff[2];
		    add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever4.byte[i]);
	 		}
 			break;

//__________________________________________________________
//__________________________________________________________
/*
case  5 :   
			  modescan5 = 0;
			  delay5 = NO_SCAN_DELAY;
			  emb5StatusReciever5.emb5statusreciever.genStatus = 2;// IPBuff[2];
		    add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever5.byte[i]);
	 		}
 			break;

//__________________________________________________________
*/
//__________________________________________________________
case  6 :   
			  modescan6 = 0;
			  delay6 = NO_SCAN_DELAY;
			  emb5StatusReciever6.emb5statusreciever.genStatus = 2;// IPBuff[2];
		    add_char_TCP_buff(IPBuff[1]);
			 for(i = 1; i < 11; i++)
	 		{
	   				add_char_TCP_buff(emb5StatusReciever6.byte[i]);
	 		}
 			break;
				  
//__________________________________________________________
 #endif //  PRM_PCH_SIX_LINES
			    
default :  
  	add_char_TCP_buff(TYPE_RUN_BAD);
	add_char_TCP_buff(IPBuff[1]);
 	break;
	}
}

extern "C" void  ParseCommand6(char *IPBuff)
{
 breakflag =1; 

	 add_char_TCP_buff(CODE_RPU_STATE);
	 long i;
	switch(IPBuff[1])
	{
case  1 :  for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState1.byte[i]);
	 		}
  			break;
			 /*
case  2 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState2.byte[i]);
	 		}
 			break;
			*/
#ifdef PRM_PCH_THREE_LINES
  /*
case  3 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState3.byte[i]);
	 		}
			break;
			*/
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES

case  4 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState4.byte[i]);
	 		}
			break;
			/*
case  5 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState5.byte[i]);
	 		}
			break;
			*/
case  6 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState6.byte[i]);
	 		}
			break;
			
#endif // PRM_PCH_SIX_LINES
default : 
 	add_char_TCP_buff(TYPE_RUN_BAD);
	add_char_TCP_buff(IPBuff[1]);
  break;

	 }
}

extern "C" void  ParseCommand7(char *IPBuff)
{
  	 breakflag =1; 
	switch(IPBuff[1])
	{
case  1 : 
		 if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

 			emb5ScanFreq1.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq1.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq1.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
		 //	printf("\n\r 8 : 0x%x 9 : 0x%x", IPBuff[8],IPBuff[9]);
		 //   message = 	IPBuff[8] +  (IPBuff[9] << 8) + 1;
			if(emb5ScanFreq1.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq1.emb5scanfreq.numOfStep = MAX_STEPS;
 			emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq1.emb5scanfreq.frequStart;
   			emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan1.emb5statusfrequscan.number =   emb5ScanFreq1.emb5scanfreq.number;
			emb5StatusFrequScan1.emb5statusfrequscan.frequStart =   emb5ScanFreq1.emb5scanfreq.frequStart;
			emb5StatusFrequScan1.emb5statusfrequscan.step =   emb5ScanFreq1.emb5scanfreq.step;
			emb5StatusFrequScan1.emb5statusfrequscan.numOfStep =   emb5ScanFreq1.emb5scanfreq.numOfStep;
			emb5StatusFrequScan1.emb5statusfrequscan.att =   emb5StatusReciever1.emb5statusreciever.stepAtt;
			modescan1 = 1; //start scan	channel1
   			curval1 = -2;
			emb5ScanFreq1.emb5scanfreq.numOfStep += (unsigned short)2; //to have last data(first answer is emty ) and +1 have last receive - modescan setted to zero in requests 
  		    delay1 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq1.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan1.emb5statusfrequscan.level[i] = ConvVal(0);
				}
 			break;
			/*
case  2 : 
 		  if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

 			emb5ScanFreq2.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq2.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq2.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq2.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq2.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq2.emb5scanfreq.frequStart;
   			emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan2.emb5statusfrequscan.number =   emb5ScanFreq2.emb5scanfreq.number;
			emb5StatusFrequScan2.emb5statusfrequscan.frequStart =   emb5ScanFreq2.emb5scanfreq.frequStart;
			emb5StatusFrequScan2.emb5statusfrequscan.step =   emb5ScanFreq2.emb5scanfreq.step;
			emb5StatusFrequScan2.emb5statusfrequscan.numOfStep =   emb5ScanFreq2.emb5scanfreq.numOfStep;
			emb5StatusFrequScan2.emb5statusfrequscan.att =   emb5StatusReciever2.emb5statusreciever.stepAtt;
		    modescan2 = 1; //start scan channel2
  	        curval2 = -2;
		   	emb5ScanFreq2.emb5scanfreq.numOfStep += (unsigned short)2;
	  		delay2 = SCAN_DELAY;
	  		for(i = 0; i < emb5ScanFreq2.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan2.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
			*/
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq3.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq3.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq3.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq3.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq3.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq3.emb5scanfreq.frequStart;
   			emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan3.emb5statusfrequscan.number =   emb5ScanFreq3.emb5scanfreq.number;
			emb5StatusFrequScan3.emb5statusfrequscan.frequStart =   emb5ScanFreq3.emb5scanfreq.frequStart;
			emb5StatusFrequScan3.emb5statusfrequscan.step =   emb5ScanFreq3.emb5scanfreq.step;
			emb5StatusFrequScan3.emb5statusfrequscan.numOfStep =   emb5ScanFreq3.emb5scanfreq.numOfStep;
			emb5StatusFrequScan3.emb5statusfrequscan.att =   emb5StatusReciever3.emb5statusreciever.stepAtt;
		    modescan3 = 1; //start scan channel2
	    	curval3 = -2;
		   	emb5ScanFreq3.emb5scanfreq.numOfStep += (unsigned short)2;
			delay3 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq3.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan3.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
			*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//__________________________________________________________________4
case  4 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq4.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq4.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq4.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq4.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq4.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq4.emb5scanfreq.frequStart;
   			emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan4.emb5statusfrequscan.number =   emb5ScanFreq4.emb5scanfreq.number;
			emb5StatusFrequScan4.emb5statusfrequscan.frequStart =   emb5ScanFreq4.emb5scanfreq.frequStart;
			emb5StatusFrequScan4.emb5statusfrequscan.step =   emb5ScanFreq4.emb5scanfreq.step;
			emb5StatusFrequScan4.emb5statusfrequscan.numOfStep =   emb5ScanFreq4.emb5scanfreq.numOfStep;
			emb5StatusFrequScan4.emb5statusfrequscan.att =   emb5StatusReciever4.emb5statusreciever.stepAtt;
		    modescan4 = 1; //start scan channel2
	    	curval4 = -2;
		   	emb5ScanFreq4.emb5scanfreq.numOfStep += (unsigned short)2;
			delay4 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq4.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan4.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
//__________________________________________________________________________________4

//__________________________________________________________________5
/*
case  5 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq5.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq5.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq5.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq5.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq5.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq5.emb5scanfreq.frequStart;
   			emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan5.emb5statusfrequscan.number =   emb5ScanFreq5.emb5scanfreq.number;
			emb5StatusFrequScan5.emb5statusfrequscan.frequStart =   emb5ScanFreq5.emb5scanfreq.frequStart;
			emb5StatusFrequScan5.emb5statusfrequscan.step =   emb5ScanFreq5.emb5scanfreq.step;
			emb5StatusFrequScan5.emb5statusfrequscan.numOfStep =   emb5ScanFreq5.emb5scanfreq.numOfStep;
			emb5StatusFrequScan5.emb5statusfrequscan.att =   emb5StatusReciever5.emb5statusreciever.stepAtt;
		    modescan5 = 1; //start scan channel2
	    	curval5 = -2;
		   	emb5ScanFreq5.emb5scanfreq.numOfStep += (unsigned short)2;
			delay5 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq5.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan5.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
//__________________________________________________________________________________5
   */
//__________________________________________________________________6
case  6 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq6.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq6.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq6.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq6.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq6.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq6.emb5scanfreq.frequStart;
   			emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan6.emb5statusfrequscan.number =   emb5ScanFreq6.emb5scanfreq.number;
			emb5StatusFrequScan6.emb5statusfrequscan.frequStart =   emb5ScanFreq6.emb5scanfreq.frequStart;
			emb5StatusFrequScan6.emb5statusfrequscan.step =   emb5ScanFreq6.emb5scanfreq.step;
			emb5StatusFrequScan6.emb5statusfrequscan.numOfStep =   emb5ScanFreq6.emb5scanfreq.numOfStep;
			emb5StatusFrequScan6.emb5statusfrequscan.att =   emb5StatusReciever6.emb5statusreciever.stepAtt;
		    modescan6 = 1; //start scan channel2
	    	curval6 = -2;
		   	emb5ScanFreq6.emb5scanfreq.numOfStep += (unsigned short)2;
			delay6 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq6.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan6.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
			
//__________________________________________________________________________________4


#endif //PRM_PCH_SIX_LINES
default :  	  add_char_TCP_buff(TYPE_RUN_BAD);
		      add_char_TCP_buff(IPBuff[1]);
     		  add_char_TCP_buff(CODE_COMMAND_7);
 break;
	 }
}
extern "C" void  ParseCommand8(char *IPBuff)
{
 //	 add_char_TCP_buff(REQUEST_SCAN);
	 long i;
 breakflag =1; 
	switch(IPBuff[1])
	{
case  1 : 
		   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan1 = 0;
			delay1 = NO_SCAN_DELAY;
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.att);		//9
		 	for(i = 14; i <  ((emb5StatusFrequScan1.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan1.byte[i]);
	 		}
 			break;
			/*
case  2 : 
			if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan2 = 0;
  			delay2 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan2.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan2.byte[i]);
	 		}
			break;
			*/

#ifdef PRM_PCH_THREE_LINES
		  /*
case  3 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan3 = 0;
		    delay3 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan3.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan3.byte[i]);
	 		}
			break;
			*/
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//________________________________________________________________4
case  4 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan4 = 0;
  			delay4 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan4.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan4.byte[i]);
	 		}
			break;
//_____________________________________________________________________________________4

//________________________________________________________________5
/*
case  5 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan5 = 0;
  			delay5 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan5.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan5.byte[i]);
	 		}
			break;
//_____________________________________________________________________________________5
 */
//________________________________________________________________6
case  6 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan6 = 0;
  			delay6 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan6.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan6.byte[i]);
	 		}
			break;
			
//_____________________________________________________________________________________4

#endif // PRM_PCH_SIX_LINES
default : 
		   add_char_TCP_buff(TYPE_RUN_BAD);
  			break;
	 }
}


extern "C" void  ParseCommand9(char *IPBuff)
{
 breakflag =1; 

   add_char_TCP_buff(TYPE_RUN_9);
   add_char_TCP_buff(IPBuff[1]);

	 long i;
	switch(IPBuff[1])
	{
case  1 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus1.byte[i]);
				embUpDownStatus1.byte[i] = 0l;
	 		}
 			break;
		   /*
case  2 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus2.byte[i]);
				embUpDownStatus2.byte[i] = 0l;
	 		}
			break;
				 */
#ifdef PRM_PCH_THREE_LINES
	  /*
case  3 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus3.byte[i]);
				embUpDownStatus3.byte[i] = 0l;
	 		}
			break;
			*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//___________________________________________________________________4
case  4 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus4.byte[i]);
				embUpDownStatus4.byte[i] = 0l;
	 		}
			break;
//____________________________________________________________________4
//___________________________________________________________________5
/*
case  5 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus5.byte[i]);
				embUpDownStatus5.byte[i] = 0l;
	 		}
			break;
//____________________________________________________________________5
*/
//___________________________________________________________________6
case  6 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus6.byte[i]);
				embUpDownStatus6.byte[i] = 0l;
	 		}
			break;
			
//____________________________________________________________________6

#endif //PRM_PCH_SIX_LINES
default :   break;
	 }
}



#define TYPE_RUN_10	(0xf8)


extern "C" void  ParseCommand10(char *IPBuff)
{
 breakflag =1; 
 //  printfp("10");
   add_char_TCP_buff(TYPE_RUN_10);
   add_char_TCP_buff(IPBuff[1]);

	 long i;
	switch(IPBuff[1])
	{
case  1 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		  add_char_TCP_buff(uemb5statusgeterodin1.byte[i]);
			}   	 	   
 			break;
			/*
case  2 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		  add_char_TCP_buff(uemb5statusgeterodin2.byte[i]);
	 		}
			break;
			*/
#ifdef PRM_PCH_THREE_LINES
	  /*
case  3 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		   add_char_TCP_buff(uemb5statusgeterodin3.byte[i]);

	 		}
			break;
		   */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//___________________________________________________________________4
case  4 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		  add_char_TCP_buff(uemb5statusgeterodin4.byte[i]);
	 		}
			break;
//____________________________________________________________________4
//___________________________________________________________________5
/*
case  5 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		 add_char_TCP_buff(uemb5statusgeterodin5.byte[i]);

	 		}
			break;
//____________________________________________________________________5

*/
//___________________________________________________________________6
case  6 : 
		 	for(i = 0; i <  12; i++)
	 	 	{
	   		 add_char_TCP_buff(uemb5statusgeterodin6.byte[i]);

	 		}
			break;
			
//____________________________________________________________________6

#endif //PRM_PCH_SIX_LINES
default :   break;
	 }
}




#define CODE_33 (0x21)

extern "C" void  ParseCommand33(char *IPBuff)
{
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(CODE_33);
   test_shift_mode = IPBuff[1];
   unEmb2TypeVer.emb2TypeVer.signature_software[14] = test_shift_mode;
}


extern "C" void  ParseCommand11(char *IPBuff)
{
//printfp("\n\r11");
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
	 //	   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
	 //	   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];

// if(GetTestMode() == 0x50)
// {
//  printf("\n\r %02X", IPBuff[2]);
// }

		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;

   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	//   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
 //	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
   //		   SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);	 //need change
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
	 //	   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
 unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
	//   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
						*/
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
 unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
					*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
   //emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
  // emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
		 //	KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
   //		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
	//	    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________
	  /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
 	     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________
 */
//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		   //  emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
  // emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   	  //		KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
	 //		KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
	//	    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
			
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

 //  add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
   add_char_TCP_buff(ATT_RPU_CODE);


}





//_______________________________________________________________________
//#ifdef PROG_PRM_PCH_L_61
//_____________________________________________________________________

extern "C" void  SetAtt1_12(unsigned char val)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_1.SetBody(1, val);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
  /*
extern "C" void  SetAtt2_12(unsigned char val)
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_2.SetBody(1, val);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
*/
	/*
extern "C" void  SetAtt3_12(unsigned char val)
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_3.SetBody(1, val);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
	*/
extern "C" void  SetAtt4_12(unsigned char val)
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_4.SetBody(1, val);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
/*
extern "C" void  SetAtt5_12(unsigned char val)
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_5.SetBody(1, val);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
*/
extern "C" void  SetAtt6_12(unsigned char val)
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_6.SetBody(1, val);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}
	  
extern "C" void  SetAtt1_13(unsigned char val)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_1.SetBody(1, val);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
 /*
extern "C" void  SetAtt2_13(unsigned char val)
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_2.SetBody(1, val);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
*/
 /*
extern "C" void  SetAtt3_13(unsigned char val)
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_3.SetBody(1, val);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
   */
extern "C" void  SetAtt4_13(unsigned char val)
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_4.SetBody(1, val);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
/*
extern "C" void  SetAtt5_13(unsigned char val)
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_5.SetBody(1, val);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
*/
extern "C" void  SetAtt6_13(unsigned char val)
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_6.SetBody(1, val);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

  


extern "C" void  ParseCommand12(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetAtt1_12( IPBuff[2]);
	 //	   unEmb2TypeVer.emb2TypeVer.signature_software[0] = IPBuff[2];
 		   break;
		   /*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		    SetAtt2_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[8] = IPBuff[2];
	  		break;
				 */
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
		    SetAtt3_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[4] = IPBuff[2];
			break;
		   */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		    SetAtt4_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[1] = IPBuff[2];

			break;
	  /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
		    SetAtt5_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[9] = IPBuff[2];



			break;
	 */
case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		    SetAtt6_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[5] = IPBuff[2];
			break;
			  
#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}

extern "C" void  ParseCommand13(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetAtt1_13( IPBuff[2]);
	//	   unEmb2TypeVer.emb2TypeVer.signature_software[2] = IPBuff[2];
 		   break;
		   /*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		    SetAtt2_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[10] = IPBuff[2];
	  		break;
				*/
#ifdef PRM_PCH_THREE_LINES
	   /*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
		    SetAtt3_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[6] = IPBuff[2];
			break;
			*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		    SetAtt4_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[3] = IPBuff[2];

			break;
		   /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
		    SetAtt5_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[11] = IPBuff[2];



			break;
			  */
case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		    SetAtt6_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[7] = IPBuff[2];
			break;
				  
#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


extern "C" void  ParseCommand14(char *IPBuff)
{

//printfp("\n\r14");
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
//		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
//		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
//		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r %02X", IPBuff[2]);
// }
		   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;

//091025   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT1_ADDR_RPU); //need change
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT2_ADDR_RPU);
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT3_ADDR_RPU);
 //		   SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_software[12]);	 //need change
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
 //		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
 //		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
    	   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
  //		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
  //	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
  //	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
				*/
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
 //  emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
  //		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
  //		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
	      unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
//		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
//	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
//	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
			   */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 //		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
 //  emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //  emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];

   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   //			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
  //			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
  //		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
	  //	    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________
		 /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
 //	     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
//   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
//   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];

 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   	//		KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
	//		KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
	//	KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________
	*/
//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
  //		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
 //  emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //  emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   //			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
   //			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
   //		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
	//	    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
			
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

 //  add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
   add_char_TCP_buff(ATT_RPU5_CODE);


}


//_____________________________________________________________________







unsigned char WriteStatus1,WriteStatus2,WriteStatus3,WriteStatus4,WriteStatus5,WriteStatus6;
unsigned char ReadStatus1[3], ReadStatus2[3], ReadStatus3[3], ReadStatus4[3], ReadStatus5[3], ReadStatus6[3];
unsigned char ReadAtt1[3], ReadAtt2[3], ReadAtt3[3], ReadAtt4[3], ReadAtt5[3], ReadAtt6[3]; 

extern "C" void  GetAtt1(void)
{
  ReadAtt1[0] = 0;
  ReadAtt1[1] = 0;
  ReadAtt1[2] = 0;


				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
  /*
extern "C" void  GetAtt2(void)
{
  ReadAtt2[0] = 0;
  ReadAtt2[1] = 0;
  ReadAtt2[2] = 0;


				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
*/
   /*
extern "C" void  GetAtt3(void)
{
  ReadAtt3[0] = 0;
  ReadAtt3[1] = 0;
  ReadAtt3[2] = 0;


				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
	*/
extern "C" void  GetAtt4(void)
{
  ReadAtt4[0] = 0;
  ReadAtt4[1] = 0;
  ReadAtt4[2] = 0;


				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
/*
extern "C" void  GetAtt5(void)
{
  ReadAtt5[0] = 0;
  ReadAtt5[1] = 0;
  ReadAtt5[2] = 0;


				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

*/


extern "C" void  GetAtt6(void)
{
  ReadAtt6[0] = 0;
  ReadAtt6[1] = 0;
  ReadAtt6[2] = 0;


				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

		
extern "C" void  GetFlash1(char *pAddrData)
{
#ifdef TEST_PUPM2
 printfp("___GetFlash1"); 
#endif

  ReadStatus1[0] = 0;
  ReadStatus1[1] = 0;
  ReadStatus1[2] = 0;


				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
 /*
extern "C" void  GetFlash2(char *pAddrData)
{
  ReadStatus2[0] = 0;
  ReadStatus2[1] = 0;
  ReadStatus2[2] = 0;

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
*/
	 /*
extern "C" void  GetFlash3(char *pAddrData)
{
  ReadStatus3[0] = 0;
  ReadStatus3[1] = 0;
  ReadStatus3[2] = 0;

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_3.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
*/
extern "C" void  GetFlash4(char *pAddrData)
{
  ReadStatus4[0] = 0;
  ReadStatus4[1] = 0;
  ReadStatus4[2] = 0;

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_4.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
/*
extern "C" void  GetFlash5(char *pAddrData)
{
  ReadStatus5[0] = 0;
  ReadStatus5[1] = 0;
  ReadStatus5[2] = 0;

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_5.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

*/
extern "C" void  GetFlash6(char *pAddrData)
{
  ReadStatus6[0] = 0;
  ReadStatus6[1] = 0;
  ReadStatus6[2] = 0;

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_6.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


  


extern "C" void  SetFlash1(char *pAddrData)
{
//printfp("SetFlash1");	 
  WriteStatus1 = 0;

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FLASH_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}
 /*
extern "C" void  SetFlash2(char *pAddrData)
{
WriteStatus2 = 0;

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(FLASH_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
*/
   /*
extern "C" void  SetFlash3(char *pAddrData)
{
WriteStatus3 = 0;

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(FLASH_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_3.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
   */
extern "C" void  SetFlash4(char *pAddrData)
{
WriteStatus4 = 0;

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(FLASH_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_4.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
 /*
extern "C" void  SetFlash5(char *pAddrData)
{
 WriteStatus5 = 0;
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(FLASH_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_5.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
  */
extern "C" void  SetFlash6(char *pAddrData)
{
  WriteStatus6 = 0;
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(FLASH_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_6.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

 



extern "C" void  ParseCommand30(char *IPBuff)
{

// breakflag =1; 
// return; //120424

//#ifdef TEST_PRM
//printfp("ParseCommand30");	  
//#endif

 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetFlash1(&IPBuff[2]);	 //
 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 SetFlash2(&IPBuff[2]);	 //

		   			break;
						 */
#ifdef PRM_PCH_THREE_LINES
		 /*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  SetFlash3(&IPBuff[2]);	 //

			break;
			 */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  SetFlash4(&IPBuff[2]);	 //

			break;
		/*

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 SetFlash5(&IPBuff[2]);	 //

 
			break;

		*/

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  SetFlash6(&IPBuff[2]);	 //

			break;
			
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


extern "C" void  ParseCommand31(char *IPBuff)
{

//breakflag =1; 
// return; //120424


//#ifdef TEST_PRM
//printf("%s","ParseCommand31");	  
//#endif

 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   GetFlash1(&IPBuff[2]);	 //
 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 GetFlash2(&IPBuff[2]);	 //

		   			break;
						   */
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  GetFlash3(&IPBuff[2]);	 //

			break;
			*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  GetFlash4(&IPBuff[2]);	 //

			break;
	  /*

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 GetFlash5(&IPBuff[2]);	 //

 
			break;

	 */

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  GetFlash6(&IPBuff[2]);	 //

			break;
			  

//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}

extern "C" void  ParseCommand32(char *IPBuff)
{
 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   GetAtt1();	 //
 			break;
			 /*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 GetAtt2();	 //

		   			break;
						  */
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  GetAtt3();	 //

			break;
		 */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  GetAtt4();	 //

			break;

		/*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 GetAtt5();	 //

 
			break;

		*/

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  GetAtt6();	 //

			break;
			   

//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


//#endif// PROG_PRM_PCH_L_61
//_______________________________________________________________________

extern "C" unsigned char Roulette1(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
//printfpd("\n\rroulette1 code: %d \n\r" , requestMod);
#endif// PRM_PCH_DEBUG

 if(start1){ delay1 = ROULETTE_DELAY;}
 switch(requestMod++)
// switch(requestMod)
 {
   case 0: GetCode1(); break;
   case 1: GetCode1(); break; //GetLockLevel1(); break;
   case 2: GetCode1(); break; //GetTemp1(); break;
   case 3: GetCode1(); break; //Get48_1(); break;
   case 4: GetCode1(); break; //Get24_1(); break;
   case 5: GetCode1(); break; //Get7_1(); break;
   case 6: GetCode1(); break;//Get5_1(); break;
   case 7: GetCode1(); break; //Get5M_1(); break;
   case 9: if(!setf1) { SetFreq1(); setf1 = 1;break; } 	return 0;
   case 8: if(!setatt1) { SetAtt1(); setatt1 = 1;break;} return 0;
#ifndef PROG_PRM_PCH_C
    default :  requestMod = 0; return 0;	  //to have cycle requests
#else 
   default :  	if(start1)
				{
   	  //			tmp = inportb(POWER_PORT);
				ClearMod();
		   		outportb(POWER_PORT,  0);  
		   		requestMod = 11;
				start1 = 0;
				delay1 = NO_SCAN_DELAY;
	//			delay2 = time1 + START_TIMEOUT;
				}
				else
				{
	   	  	 requestMod = 11;
				}
				return 0;
#endif
 }

// requestMod++;
 return 1;
}	
	   /*
extern "C" unsigned char Roulette2(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette2 code: %d" , requestTransit);
#endif// PRM_PCH_DEBUG
if(start2){ delay2 = ROULETTE_DELAY;}
   switch(requestTransit++)
 {
   case 0: GetCode2();	break;
   case 1: GetCode2();	break; //GetLockLevel2(); break;
   case 2: GetCode2();	break; //GetTemp2(); break;
   case 3: GetCode2();	break; //Get48_2(); break;
   case 4: GetCode2();	break; //Get24_2(); break;
   case 5: GetCode2();	break; //Get7_2();break;
   case 6: GetCode2();	break; //Get5_2(); break;
   case 7: GetCode2();	break; //Get5M_2(); break;
   case 9: if(!setf2) {SetFreq2(); setf2 = 1; break;} 	 return 0;
   case 8: if(!setatt2) {SetAtt2(); setatt2 = 1;  break;}    return 0;
#ifndef PROG_PRM_PCH_C

   default :  requestTransit = 0; return 0;	  //to have cycle
#else 
   default :  	if(start2)
				{
   		//		tmp = inportb(POWER_PORT);
#ifdef PROG_PRM_PCH_S
				ClearMod();
#endif
 			    outportb(POWER_PORT, (CH3_MASK));  
				requestTransit = 11;
				start2 = 0;
				delay2 = NO_SCAN_DELAY;
   //				delay3 = time1 + START_TIMEOUT;
				}
				else
				{
 				 requestTransit = 11;
				}
				return 0;
#endif
 }
  return 1;
}	
	   */
extern "C" void MakeNextStepScan1()
{
 SetFreq1();
 //____________________________________________________________________________
 //	printf("\n\rstepnum = %d  stepfreq = 0x%X freq1 = 0x%lX" ,emb5ScanFreq1.emb5scanfreq.numOfStep, emb5ScanFreq1.emb5scanfreq.step, emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
 //	printf("\n\r0x%lX", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________

 if(emb5ScanFreq1.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ += emb5ScanFreq1.emb5scanfreq.step;
   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
   curval1++;
 }
 else
 {
   modescan1 = 0; //stop scan channel1  //this was be lost!!!!
   delay1 = NO_SCAN_DELAY;
 }
}
   /*
extern "C" void MakeNextStepScan2()
{
 SetFreq2();
 if(emb5ScanFreq2.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ += emb5ScanFreq2.emb5scanfreq.step;
   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
   curval2++;
 }
 else
 {
 modescan2 = 0; //start scan channel2
 delay2 = NO_SCAN_DELAY;
 }
}
	  */
#ifdef PROG_PRM_PCH_C

extern "C" void AlarmPmOn(void)
{
//printf("\n\r1");
 unsigned char data;
 data =  inportb(LED_PORT);
#ifdef PROG_PRM_PCH_S
 outportb(LED_PORT, (data & ALARM_INPUT));
#else
 outportb(LED_PORT, (data & ALARM_PM));
#endif


}



extern "C" void AlarmPmOff(void)
{
//printf("\n\r2");

 unsigned char data;
 data =  inportb(LED_PORT);
 #ifdef PROG_PRM_PCH_S
 outportb(LED_PORT, (data | NO_ALARM_INPUT));
 #else
 outportb(LED_PORT, (data | NO_ALARM_PM));
#endif
}

#ifdef PROG_PRM_PCH_S

extern "C" void AlarmPmOn2(void)
{
//printf("\n\r3");

 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_POWER));
}



extern "C" void AlarmPmOff2(void)
{
//printf("\n\r4");

 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_POWER));
}


#endif // PROG_PRM_PCH_S


extern "C" void CheckAlarmsPm(void)
{
 #ifndef PROG_PRM_PCH_S
 switch(inportb(POWER_PORT) & 0xF)
 {
  case 1:  if(countMod < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 2:  if(countTransit < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 4:  if(countPower < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  default: AlarmPmOff(); 
 }

#else // PROG_PRM_PCH_S
 //printf("\n\r %d %d %d %d %d %d", fl1,fl2, fl3,fl4,fl5,fl6);
#ifndef  PROG_PRM_PCH_N
    switch(inportb(POWER_PORT) & 0xF)
 {
  case 1:  if(fl1) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
			 /*
  case 2:  if(fl2) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 4:  if(fl3) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
				  */
  default: AlarmPmOff(); 
 }



  switch(inportb(POWER_PORT2) & 0xF)
 {
  case 1:  if(fl4) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
			  /*
  case 2:  if(fl5) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
  case 4:  if(fl6) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
		   */
//091113  default: AlarmPmOff(); 
  default: AlarmPmOff2();  //091113
 }
#else // PROG_PRM_PCH_N
   
#endif 	// PROG_PRM_PCH_N
#endif //	PROG_PRM_PCH_S
}


   /*
extern "C" void PrintMessages()
{
 switch (message)
 {
  case 1 : printf("\n\rpower on channel 1");  break;
  case 2 : printf("\n\rpower on channel 2");  break;
  case 3 : printf("\n\rpower on channel 3");  break;
  default : break;

 }
 if(message)  printf("\n\r m = %d" , message);
 message = 0;
}
  */



extern "C" void SetPower(unsigned char channel)
{
// message = channel;
switch(channel)
{
 case 1:  outportb(POWER_PORT, CH_PW_MASK);  break;
// case 2:  outportb(POWER_PORT, CH2_MASK);  break;
// case 3:  outportb(POWER_PORT, CH3_MASK);  break;
#ifdef PROG_PRM_PCH_S
 case 4:  outportb(POWER_PORT2, CH_PW_MASK);  break;
// case 5:  outportb(POWER_PORT2, CH5_MASK);  break;
// case 6:  outportb(POWER_PORT2, CH6_MASK);  break;
 case 6:  outportb(POWER_PORT3, CH_PW_MASK);  break;		//enover mask

#endif //PROG_PRM_PCH_S
 default : break;
}
}
#endif 	PROG_PRM_PCH_C

extern "C" void AlarmsOn1(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_MASK1));
}

extern "C" void AlarmsOff1(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_MASK1));
}
 /*
extern "C" void AlarmsOn2(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_MASK2));
}

extern "C" void AlarmsOff2(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_MASK2));
}
   */

#ifdef PRM_PCH_THREE_LINES
	/*
extern "C" void AlarmsOn3(void)
{
 unsigned char data;
 data =  inportb(LED_PORT3);
 outportb(LED_PORT3, (data & ALARM_MASK3));
}

extern "C" void AlarmsOff3(void)
{
 unsigned char data;
 data =  inportb(LED_PORT3);
 outportb(LED_PORT3, (data | NO_ALARM_MASK3));
}

extern "C" void ParseUD_3()	 //need make!
{
if(modescan3)
 {
 if(curval3 >= 0)
 {
   emb5StatusFrequScan3.emb5statusfrequscan.level[curval3] = ConvVal( (((unsigned short)embMsgUD_3.Body(2)&0x0F) << 8) + 	embMsgUD_3.Body(1));
 }
 else
 {
  }
  return;
 }
 if(start3) //100401		
 unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = 1; //have power on 3
 switch(embMsgUD_3.Body(0))
 {
  case 0:  if(start3)
   {unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = embMsgUD_3.Body(1) & DEVICE_TYPE_MASK; 
  		   Band3 = embMsgUD_3.Body(1);}	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever3.emb5statusreciever.status =  embMsgUD_3.Body(2) >> 4;
			emb5StatusReciever3.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_3.Body(2)&0x0F)  << 8) + 	embMsgUD_3.Body(1));
 		   	emb5StatusReciever3.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_3.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState3.emb5rpustate.temp =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.temp_min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.temp_max =  embMsgUD_3.Body(3);
  case 23:	emb5RPUState3.emb5rpustate.u48 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u48min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u48max =  embMsgUD_3.Body(3);
  case 24:	emb5RPUState3.emb5rpustate.u24 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u24min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u24max =  embMsgUD_3.Body(3);
  case 25:	emb5RPUState3.emb5rpustate.u7 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u7min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u7max =  embMsgUD_3.Body(3);
  case 26:	emb5RPUState3.emb5rpustate.u5 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u5min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u5max =  embMsgUD_3.Body(3);
  case 27:	emb5RPUState3.emb5rpustate.u_5 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u_5min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u_5max =  embMsgUD_3.Body(3);
//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[4] =  embMsgUD_3.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[6] =  embMsgUD_3.Body(1);	break;
 case 30:	WriteStatus3 = embMsgUD_3.Body(1); break;
 case 31:	ReadStatus3[0] = embMsgUD_3.Body(1); 
			ReadStatus3[1] = embMsgUD_3.Body(2); 
			ReadStatus3[2] = embMsgUD_3.Body(3); break;
  case 32:	ReadAtt3[0] = embMsgUD_3.Body(1); 
			ReadAtt3[1] = embMsgUD_3.Body(2); 
			ReadAtt3[2] = embMsgUD_3.Body(3); break;


//#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan3()
{
 SetFreq3();
 if(emb5ScanFreq3.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ += emb5ScanFreq3.emb5scanfreq.step;
   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
   curval3++;
 }
 else
 {
 modescan3 = 0; //start scan channel2
 delay3 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette3(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette3 code: %d" , requestPower);
#endif// PRM_PCH_DEBUG
if(start3){ delay3 = ROULETTE_DELAY;}
   switch(requestPower++)
 {
   case 0: GetCode3();	break;
   case 1: GetCode3();	break; //GetLockLevel3();    		break;
   case 2: GetCode3();	break; //GetTemp3(); break;
   case 3: GetCode3();	break; //Get48_3(); break;
   case 4: GetCode3();	break; //Get24_3(); break;
   case 5: GetCode3();	break; //Get7_3();break;
   case 6: GetCode3();	break; //Get5_3(); break;
   case 7: GetCode3();	break; //Get5M_3(); break;
   case 9: if(!setf3) {SetFreq3(); setf3 = 1; break;} 	 return 0;
   case 8: if(!setatt3) {SetAtt3(); setatt3 = 1;  break;}    return 0;
#ifndef PROG_PRM_PCH_C
   default :  requestPower = 0; return 0;	  //to have cycle
#else  // PROG_PRM_PCH_C
   default :  	if(start3)
				{
#ifdef PROG_PRM_PCH_S
				ClearMod();
#endif
   			    outportb(POWER_PORT, 0);  
				requestPower = 11;
				delay3 = NO_SCAN_DELAY;
				start3 = 0;
				}
				else
				{
					requestPower = 11;
				}
				return 0;
#endif	// PROG_PRM_PCH_C
 }

  return 1;
}

extern "C" void  SetFreq3()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ,Band3);

unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin3.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin3.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin3.emb5statusgeterodin.get2 = *get2;



 if((b2_keep & 0xf) != (b[2] & 0xf)) 
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_3.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  SetAtt3()
{

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_3.SetBody(1, emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  GetCode3()
{
 			embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  GetLockLevel3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  GetTemp3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  Get48_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get24_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  Get7_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get5_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get5M_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
	  */
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//____________________________________________________________________________>>_4
extern "C" void ParseUD_4()	 //need make!
{

if(modescan4)
 {
 if(curval4 >= 0)
 {
   emb5StatusFrequScan4.emb5statusfrequscan.level[curval4] = ConvVal( (((unsigned short)embMsgUD_4.Body(2)&0x0F) << 8) + 	embMsgUD_4.Body(1));
 }
 else
 {
  }
  return;
 }
// if(start4) //100401		
 unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = 1; //have power on 4
 switch(embMsgUD_4.Body(0))
 {
  case 0: // if(start4)
   {unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = embMsgUD_4.Body(1) &  PUPM2_TYPE_CONV_MASK; 
	 pupm2.embpupm2.type   =   unEmb2TypeVer.emb2TypeVer.signature_hardware[1];
  		  Band4 = embMsgUD_4.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever4.emb5statusreciever.status =  embMsgUD_4.Body(2) >> 4;
			emb5StatusReciever4.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_4.Body(2)&0x0F)  << 8) + 	embMsgUD_4.Body(1));
 		   	emb5StatusReciever4.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_4.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState4.emb5rpustate.temp =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.temp_min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.temp_max =  embMsgUD_4.Body(3);
  case 23:	emb5RPUState4.emb5rpustate.u48 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u48min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u48max =  embMsgUD_4.Body(3);
  case 24:	emb5RPUState4.emb5rpustate.u24 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u24min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u24max =  embMsgUD_4.Body(3);
  case 25:	emb5RPUState4.emb5rpustate.u7 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u7min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u7max =  embMsgUD_4.Body(3);
  case 26:	emb5RPUState4.emb5rpustate.u5 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u5min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u5max =  embMsgUD_4.Body(3);
  case 27:	emb5RPUState4.emb5rpustate.u_5 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u_5min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u_5max =  embMsgUD_4.Body(3);
//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[1] =  embMsgUD_4.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[3] =  embMsgUD_4.Body(1);	break;

  case 30:	WriteStatus4 = embMsgUD_4.Body(1); break;
  case 31:	ReadStatus4[0] = embMsgUD_4.Body(1); 
			ReadStatus4[1] = embMsgUD_4.Body(2); 
			ReadStatus4[2] = embMsgUD_4.Body(3); break;
  case 32:	ReadAtt4[0] = embMsgUD_4.Body(1); 
			ReadAtt4[1] = embMsgUD_4.Body(2); 
			ReadAtt4[2] = embMsgUD_4.Body(3); break;

//#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan4()
{
 SetFreq4();
 if(emb5ScanFreq4.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ += emb5ScanFreq4.emb5scanfreq.step;
   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
   curval4++;
 }
 else
 {
 modescan4 = 0; //start scan channel2
 delay4 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette4(void)
{
//unsigned char tmp;

#ifdef PRM_PCH_DEBUG
//printfpd("\n\rroulette4 code: %d " , requestTransit4);
//printfpd("start4: %d \n\r" , start4);

#endif// PRM_PCH_DEBUG
if(start4){ delay4 = ROULETTE_DELAY;}
   switch(requestTransit4++)
 {
   case 0:  GetCode4();	break;
   case 1:  GetCode4(); break; //GetLockLevel4();	     		break;
   case 2:  GetCode4(); break; //GetTemp4(); break;
   case 3:  GetCode4(); break; //Get48_4(); break;
   case 4:  GetCode4(); break; //Get24_4(); break;
   case 5:  GetCode4(); break; //Get7_4();break;
   case 6:  GetCode4(); break; //Get5_4(); break;
   case 7:  GetCode4(); break; //Get5M_4(); break;
   case 9: if(!setf4) {SetFreq4(); setf4 = 1; break;} 	 return 0;
   case 8: if(!setatt4) {SetAtt4(); setatt4 = 1;  break;}    return 0;
   default :  	if(start4)
				{
#ifdef PROG_PRM_PCH_S
				ClearTransit();
#endif
   		   		outportb(POWER_PORT2,0);  
				requestTransit4 = 11;
	   			start4 = 0;
				delay4 = NO_SCAN_DELAY;
	   		  //	delay6 = time1 + START_TIMEOUT;
//printfpd("\n\rroulette4 code: %d " , requestTransit4);
//printfpd("start4: %d \n\r" , start4);

				}
				else
				{
					requestTransit4 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq4()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula1L(emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ,Band4);

#ifdef PRM_USE_ATT_C12 
b[3] = emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt;
#endif


unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin4.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin4.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin4.emb5statusgeterodin.get2 = *get2;



 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_4.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  SetAtt4()
{

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_4.SetBody(1, emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  GetCode4()
{
 			embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  GetLockLevel4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  GetTemp4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  Get48_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get24_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  Get7_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get5_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get5M_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


//____________________________________________________________________________<<_4

//____________________________________________________________________________>>_5
 /*

extern "C" void ParseUD_5()	 //need make!
{

if(modescan5)
 {
 if(curval5 >= 0)
 {
   emb5StatusFrequScan5.emb5statusfrequscan.level[curval5] = ConvVal( (((unsigned short)embMsgUD_5.Body(2)&0x0F) << 8) + 	embMsgUD_5.Body(1));
 }
 else
 {
  }
  return;
 }		


 if(start5) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[11] = 1; //have power on 5
 switch(embMsgUD_5.Body(0))
 {
  case 0:  if(start5)
   { unEmb2TypeVer.emb2TypeVer.signature_hardware[9] = embMsgUD_5.Body(1) & DEVICE_TYPE_MASK; 
  		   Band5 = embMsgUD_5.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever5.emb5statusreciever.status =  embMsgUD_5.Body(2) >> 4;
			emb5StatusReciever5.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_5.Body(2)&0x0F)  << 8) + 	embMsgUD_5.Body(1));
 		   	emb5StatusReciever5.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_5.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState5.emb5rpustate.temp =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.temp_min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.temp_max =  embMsgUD_5.Body(3);
  case 23:	emb5RPUState5.emb5rpustate.u48 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u48min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u48max =  embMsgUD_5.Body(3);
  case 24:	emb5RPUState5.emb5rpustate.u24 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u24min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u24max =  embMsgUD_5.Body(3);
  case 25:	emb5RPUState5.emb5rpustate.u7 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u7min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u7max =  embMsgUD_5.Body(3);
  case 26:	emb5RPUState5.emb5rpustate.u5 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u5min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u5max =  embMsgUD_5.Body(3);
  case 27:	emb5RPUState5.emb5rpustate.u_5 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u_5min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u_5max =  embMsgUD_5.Body(3);
//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[9] =  embMsgUD_5.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[11] =  embMsgUD_5.Body(1);	break;

 case 30:	WriteStatus5 = embMsgUD_5.Body(1); break;
 case 31:	ReadStatus5[0] = embMsgUD_5.Body(1); 
			ReadStatus5[1] = embMsgUD_5.Body(2); 
			ReadStatus5[2] = embMsgUD_5.Body(3); break;
  case 32:	ReadAtt5[0] = embMsgUD_5.Body(1); 
			ReadAtt5[1] = embMsgUD_5.Body(2); 
			ReadAtt5[2] = embMsgUD_5.Body(3); break;


//#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan5()
{
 SetFreq5();
 if(emb5ScanFreq5.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ += emb5ScanFreq5.emb5scanfreq.step;
   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
   curval5++;
 }
 else
 {
 modescan5 = 0; //start scan channel2
 delay5 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette5(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette5 code: %d" , requestTransit5);
#endif// PRM_PCH_DEBUG
  if(start5){ delay5 = ROULETTE_DELAY;}
   switch(requestTransit5++)
 {
   case 0: GetCode5();	break;
   case 1: GetCode5();	break; //GetLockLevel5();	break;
   case 2: GetCode5();	break; //GetTemp5(); break;
   case 3: GetCode5();	break; //Get48_5(); break;
   case 4: GetCode5();	break; //Get24_5(); break;
   case 5: GetCode5();	break; //Get7_5();break;
   case 6: GetCode5();	break; //Get5_5(); break;
   case 7: GetCode5();	break; //Get5M_5(); break;
   case 9: if(!setf5) {SetFreq5(); setf5 = 1; break;} 	 return 0;
   case 8: if(!setatt5) {SetAtt5(); setatt5 = 1;  break;}    return 0;
   default :  	if(start5)
				{
#ifdef PROG_PRM_PCH_S
				ClearTransit();
#endif
   			 	outportb(POWER_PORT2, CH6_MASK);  
				requestTransit5 = 11;
				start5 = 0;
				delay5 = NO_SCAN_DELAY;
				delay6 = time1 + START_TIMEOUT;
				}
				else
				{
					requestTransit5 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq5()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ,Band5);

unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin5.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin5.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin5.emb5statusgeterodin.get2 = *get2;


 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_5.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  SetAtt5()
{

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_5.SetBody(1, emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  GetCode5()
{
 			embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  GetLockLevel5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  GetTemp5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  Get48_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get24_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  Get7_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get5_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get5M_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


//____________________________________________________________________________<<_5
	*/
//____________________________________________________________________________>>_6


extern "C" void ParseUD_6()	 //need make!
{

if(modescan6)
 {
 if(curval6 >= 0)
 {
   emb5StatusFrequScan6.emb5statusfrequscan.level[curval6] = ConvVal( (((unsigned short)embMsgUD_6.Body(2)&0x0F) << 8) + 	embMsgUD_6.Body(1));
 }
 else
 {
  }
  return;
 }		


 if(start6) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = 1; //have power on 6
 switch(embMsgUD_6.Body(0))
 {
  case 0: if(start6)
 // { unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = embMsgUD_6.Body(1) & DEVICE_TYPE_MASK; 
  {unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = embMsgUD_6.Body(1) &  PUPM2_TYPE_CONV_MASK;
  pupm3.embpupm2.type   =   unEmb2TypeVer.emb2TypeVer.signature_hardware[5];


  		  Band6 = embMsgUD_6.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever6.emb5statusreciever.status =  embMsgUD_6.Body(2) >> 4;
			emb5StatusReciever6.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_6.Body(2)&0x0F)  << 8) + 	embMsgUD_6.Body(1));
 		   	emb5StatusReciever6.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_6.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState6.emb5rpustate.temp =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.temp_min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.temp_max =  embMsgUD_6.Body(3);
  case 23:	emb5RPUState6.emb5rpustate.u48 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u48min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u48max =  embMsgUD_6.Body(3);
  case 24:	emb5RPUState6.emb5rpustate.u24 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u24min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u24max =  embMsgUD_6.Body(3);
  case 25:	emb5RPUState6.emb5rpustate.u7 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u7min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u7max =  embMsgUD_6.Body(3);
  case 26:	emb5RPUState6.emb5rpustate.u5 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u5min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u5max =  embMsgUD_6.Body(3);
  case 27:	emb5RPUState6.emb5rpustate.u_5 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u_5min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u_5max =  embMsgUD_6.Body(3);
//#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[5] =  embMsgUD_6.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[7] =  embMsgUD_6.Body(1);	break;

  case 30:	WriteStatus6 = embMsgUD_6.Body(1); break;
  case 31:	ReadStatus6[0] = embMsgUD_6.Body(1); 
			ReadStatus6[1] = embMsgUD_6.Body(2); 
			ReadStatus6[2] = embMsgUD_6.Body(3); break;
  case 32:	ReadAtt6[0] = embMsgUD_6.Body(1); 
			ReadAtt6[1] = embMsgUD_6.Body(2); 
			ReadAtt6[2] = embMsgUD_6.Body(3); break;

//#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan6()
{
 SetFreq6();
 if(emb5ScanFreq6.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ += emb5ScanFreq6.emb5scanfreq.step;
   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
   curval6++;
 }
 else
 {
 modescan6 = 0; //start scan channel2
 delay6 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette6(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printfpd("\n\rroulette6 code: %d \n\r" , requestTransit6);
#endif// PRM_PCH_DEBUG
  if(start6){ delay6 = ROULETTE_DELAY;}
   switch(requestTransit6++)
 {
   case 0: GetCode6();	break;
   case 1: GetCode6();	break;//GetLockLevel6();    		break;
   case 2: GetCode6();	break;//GetTemp6(); break;
   case 3: GetCode6();	break;//Get48_6(); break;
   case 4: GetCode6();	break;//Get24_6(); break;
   case 5: GetCode6();	break;//Get7_6();break;
   case 6: GetCode6();	break;//Get5_6(); break;
   case 7: GetCode6(); 	break;//Get5M_6(); break;
   case 9: if(!setf6) {SetFreq6(); setf6 = 1; break;} 	 return 0;
   case 8: if(!setatt6) {SetAtt6(); setatt6 = 1;  break;}    return 0;
   default :  	if(start6)
				{
#ifdef PROG_PRM_PCH_S
			//	ClearTransit();
			ClearPower();
#endif
   			    outportb(POWER_PORT3, 0);  
				requestTransit6 = 11;
				delay6 = NO_SCAN_DELAY;
				start6 = 0;
				}
				else
				{
					requestTransit6 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq6()
{
static unsigned char b2_keep = 0;

//unsigned char * b = Formula9(emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ,Band6);
unsigned char * b = Formula1L(emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ,Band6);

 
unsigned long *get1 = (unsigned long*)&b[16]; 
unsigned long *get2 = (unsigned long*)&b[20]; 
uemb5statusgeterodin6.emb5statusgeterodin.frequ	= 10l * emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
uemb5statusgeterodin6.emb5statusgeterodin.get1 = *get1;
uemb5statusgeterodin6.emb5statusgeterodin.get2 = *get2;
 
 
 
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_6.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}
extern "C" void  SetAtt6()
{

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_6.SetBody(1, emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  GetCode6()
{
 			embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  GetLockLevel6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  GetTemp6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  Get48_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get24_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  Get7_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get5_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get5M_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

//____________________________________________________________________________<<_6
#endif //PRM_PCH_SIX_LINES

#ifdef 	PROG_PRM_PCH_L


extern "C" unsigned long GetAttRPU(unsigned char num)
{
switch(num)
{
case 1:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 2:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 3:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 4:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];
case 5:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];
case 6:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];


default :  return 0;
}
}


extern "C" void RestoreFreq(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
		   break;
		   /*
case 2:	   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
		   break;
		   */
		/*
case 3:	   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
		   break;
		   */
case 4:    emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
		   break;
		   /*
case 5:	   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
		   break;
case 6:	   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
		   break;
				 */

default :  break;
}
}

extern "C" void RestoreAtt(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:     emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  val;
   	   //		emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 	   		break;
			/*
case 2:	    emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
 	   		break;
			*/
		   /*
case 3:	    emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
 	   		break;
				*/
case 4:     emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt =  val;
   	   //		emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 	   		break;
			/*
case 5:	    emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 6:	    emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
 	   		break;
				*/
default :  break;
}
}

extern "C" void RestoreAttRPU(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:   	unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
		    emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  val>>1;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	   //		SetAttRPU1();


 	   		break;
			/*
case 2:	    emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	   //		SetAttRPU2();
			unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
 	   		break;
			*/
			  /*
case 3:	    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	  //		SetAttRPU3();
			unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
 	   		break;
			*/
case 4:     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  val>>1;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	   //		SetAttRPU1();
		   unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;

 	   		break;
			/*
case 5:	    emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	   //		SetAttRPU2();
			unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;
 	   		break;
case 6:	    emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	  //		SetAttRPU3();
			unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;
 	   		break;
				*/
default :  break;
}
}


extern "C" unsigned long GetFreq(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//case 2:    return emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
//case 3:    return emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
case 4:    return emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
//case 5:    return emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
//case 6:    return emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;



default :  return 0;
}
}

extern "C" unsigned long GetAtt(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;
//case 2:    return emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;
//case 3:    return emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;
case 4:    return emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;
//case 5:    return emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;
//case 6:    return emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;



default :  return 0;
}
}


extern "C" void SetNeedWriteDevId(void)
{
//printf("\n\rSetWriteDevId");
  NeedWriteID = 1;
#ifdef PRM_L_KEEP_FREQ
DelayWriteTime = time1;
#endif

}

extern "C" void ClearNeedWriteDevId(void)
{
  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{

#ifdef PRM_L_KEEP_FREQ

  if(DelayWriteTime > time1)
  {

     DelayWriteTime = time1;
  }

  if((time1 - DelayWriteTime) < DELAY_TIME_TO_WRITE)
  {
   return 0;
   }
  #endif
 // if(NeedWriteID) printf("\n\rWriteDevId"); //t


  return NeedWriteID;
}

extern "C" void MakeKeepTest(void)
{
   // printf("\n\r freq1 = %lX att1 = %lX", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);
  //  printf("\n\r freq2 = %lX att2 = %lX", emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt);
 //   printf("\n\r freq3 = %lX att3 = %lX", emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt);
    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = 0x12345671;
    emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = 0x12345672;
   // emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ  = 0x12345673;
  //  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt  = 0x12345674;
 //   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ  = 0x12345675;
 //   emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt   = 0x12345676;
	SetNeedWriteDevId();
}




#endif // PROG_PRM_PCH_L


#ifdef PROG_PRM_PCH_N
unsigned char SetFreqN(unsigned short freq)
{
 emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = freq;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ); //
//____________________________________________________________________________
//	printf("\n\r freq1 = %ld" , emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FORMULA_LEN); //em
			    for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , b[i]);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();

//_________________________________________
   breakflag = 0;
   timerun = time1;
  while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

return breakflag;
}

unsigned char SetAttN(unsigned char att)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
 return breakflag;
}

unsigned char GetLevN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.signalLevel;
}

unsigned char GetAttN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.stepAtt;
}

unsigned short GetFreqN(void)
{
  return  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
}

unsigned short GetLockN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.lock;
}

unsigned char GetAlarmN(void)
{
 if(fl1)
 return 0;
 else return 1;
}

void TransN(unsigned char send)
{
  embRS485.Trans(send);
}




#endif	 //PROG_PRM_PCH_N

extern "C" unsigned char device_found(unsigned char channel)
{
 switch(channel)
 {
  case 1 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])	 return 1; 
  case 2 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])	 return 1;
  case 3 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])	 return 1;
  case 4 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])	 return 1;
  case 5 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])	 return 1;
  case 6 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])	 return 1;
  default: return 0;
 }
}
   /*
extern "C" void print_signature(void)
{
  //printf("\n\r");
  for(i=0; i<16; i++)
	{
  //	  printf(" %02X",	unEmb2TypeVer.emb2TypeVer.signature_hardware[i]);
	}
}

  */


extern "C" unsigned char CheckPUPM2CRC(unsigned char pos)
{
 unsigned char crc = 0;

 for(i = 0;	i < (pos); i++)
{
  crc += BufferCommand[i];
 // printf("i : %d  body[i] %0x%02X", i, body[i]);
}
// crc += 1;
// if(GetTestMode() == 0x50)
//{
 	      //	printf("_%02X", byte);	  //test
#ifdef PRINT_DEBUG_CRC
		   crc_glob = crc;
		   body_glob = body[i];
	   	 //	printfpd(" %02X", crc);
	   	 //	printfpd("<-> %02X",  body[i]);
#endif

//}

#ifdef TEST_PRINT_SPI 
 printfpd("\n\rcrc = 0x%02X", crc);
 printfpd("\n\rbody[i] = 0x%02X", BufferCommand[i]);
#endif

 if(crc  == BufferCommand[i])
  {
   //	  	if(GetTestMode() == 0x50)
   //	  		{
 	//     	printf("_%02X", byte);	  //test
   	//  		printf("\n\rOk! = 0x%02X", crc);
	// 		}

  return 1; //temporary
  }

 else
  {
  	if(GetTestMode() == 0x50)
  			{
 	      //	printf("_%02X", byte);	  //test
  	  //		 printf("\n\rBad! crs = 0x%02X i : %d body = 0x%02X", crc,i, body[i]);
  			}
  return 0;
  }



}
 unsigned char firstaddr;

extern "C" unsigned char OperateCommandPuPm2(unsigned char * pData)
{
static unsigned char Havefirstaddr;
//unsigned char Havetwoaddr;
//unsigned char firstaddr;
 
unsigned  char ret;
 ret = 0; 
unsigned char rch;// = * pData; 

#ifdef TEST_PRINT_SPI 
  printfpd(" ,[%X] ", * pData); //110914
 // printfpd("<c:%d>", current_command_counter);

#endif


switch(* pData)
{
case 0xFE:       if(!modeFE) {modeFE = 1;}
				 else{ //embMsgPUPM2_Init();
				    modeFE = 0;
              		current_command_state = RECEIVE_COMMAND;
              		current_command_data_counter = 0;
              		current_command_counter = 1;
					Havefirstaddr = 0;
	 //				Havetwoaddr = 0;
 					CommandDataLength[0] = 6;  //dummy command
       				CommandDataLength[1] = 6;
       				CommandDataLength[2] = 20; //celling in receive
       				CommandDataLength[3] = 6; //

#ifdef TEST_PRINT_SPI     
               printfp("\n\r> start ");
             //  printfpd(" ,%X ", 0xFE); 
//               printfpd("<c:%d>", current_command_counter);
#endif      
			  		}
				 return ret;
case 0xFC:       if(!modeFC) {modeFC = 1;}
				 else{
				   modeFC = 0;

//________________________________________
//hier need add parse command 0x44
       if (current_command_state == RUN_COMMAND)
	      {
       			    if(current_command_type == 2)
			    {
			        CommandDataLength[current_command_type] = current_command_counter - 5;

//______________________________________________
 if(CheckPUPM2CRC(current_command_counter))
   {

#ifdef TEST_PRINT_SPI   
    printfp("(_CRC Ok)");    
#endif
#ifdef PRINT_DEBUG_CRC
	 printfpd("calc crc: %02X", crc_glob);
	 printfpd("<->packet crc:  %02X\n\r",  body_glob);
#endif
     SetRunCommandPUPM2(CODE_NORMA); //ok //hier only set to run - it is interrupt

   }
   else
   {
      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(_CRC Bad)");
#endif   
	  SetRunCommandPUPM2(CODE_BAD_CRC);
   }  //crc
//_____________________________________________


			    }
		  }
//________________________________________

				 current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;	
#ifdef TEST_PRINT_SPI     
               printfp("\n\r> stop ");
            //   printfpd(" ,%X ", 0xAA); 
             //  printfpd("<c:%d>", current_command_counter);
               
#endif      
         	}
                 return ret;   //added
case    0:       if(modeFE) {modeFE = 0;  rch = 0xFE; break; /*add data 0xFE*/   }
				 else
				 if(modeFC) {modeFC = 0;  rch = 0xFC; break; /*add data 0xFC*/        }
				
default:		 rch = * pData;
                 break;
}

  current_command_counter++;

#ifdef TEST_PRINT_SPI     
           //    printfp("\n\r> start ");
             //  printfpd(" ,%X ", 0xFE); 
               printfpd("<c:%d>", current_command_counter);
			   printfpd("[dc:%d]", current_command_data_counter);

#endif     

  if(current_command_state != WAITING_COMMAND)
	 {
	 BufferCommand[current_command_counter]	= rch;
// embMsgPUPM2_Add(rch);
     }

 if((current_command_counter == COMMAND_POS) &&  (current_command_state == RECEIVE_COMMAND))
  {

//#ifdef TEST_PRINT_SPI 
//   printfpd("(type:%02X)", rch);
//#endif
     if(rch == COP1)	     current_command_type =  1; 
	 else if(rch == COP2)	 current_command_type =  2; 
	 else if(rch == COP3)	 current_command_type =  3; 
     else{ /* Body */
     current_command_state = WAITING_COMMAND;
     current_command_type = NO_COMMAND_SSC2;
	// return ret; 

   } /* Endbody */
#ifdef TEST_PRINT_SPI 
   printfpd("(type:%02X)", current_command_type);
#endif

    return ret;
  } //counter
 else if((current_command_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
     if((unsigned char)rch == rs485_addr)
     {

#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(addr ok:%d)", rch);
#endif

      current_command_state = RUN_COMMAND;
       ret = 1;
      } 
        else
        {
#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(addr bad:%d)", rch);
#endif


      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
	  return ret; 

      }
  } 
 else  if (current_command_state == RUN_COMMAND)
  {
   if((current_command_counter == CommandDataLength[current_command_type]))
  {

   current_command_crc =  rch;   //120720  ? ? need?
if(current_command_type != 2)
 {
   if(CheckPUPM2CRC(current_command_counter))
   {

#ifdef TEST_PRINT_SPI   
    printfp("(CRC Ok)");    
#endif
#ifdef PRINT_DEBUG_CRC
	 printfpd("calc crc: %02X", crc_glob);
	 printfpd("<->packet crc:  %02X\n\r",  body_glob);
#endif
     SetRunCommandPUPM2(CODE_NORMA); //ok //hier only set to run - it is interrupt

   }
   else
   {
      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(CRC Bad)");
#endif   
	  SetRunCommandPUPM2(CODE_BAD_CRC);
   }  //crc
  }	   //type not 2
 } //counter == datalength
 else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  {

#ifdef TEST_PRINT_SPI 
   printfpd("(CDL:%X)", CommandDataLength[current_command_type]);
    printfpd("(ccc:%X)", current_command_counter);
#endif

      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(finish)");
#endif   



  }	  //> dstslength
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
            &&  (current_command_state == RUN_COMMAND))
  { 
      
   //	  if((current_command_type == 1)	|| (Havefirstaddr && Havetwoaddr))
	  if((current_command_type == 1)	|| (Havefirstaddr) ||  (current_command_type == 3) )
	  {
        current_command_data[current_command_data_counter++] = rch;
#ifdef TEST_PRINT_SPI 
   printfp("fill");
#endif

	  }
	  else if(!Havefirstaddr)
	  {
		 firstaddr = rch; Havefirstaddr = 1;
 //		 current_command_data[current_command_data_counter++] = rch; //for command type 1
#ifdef TEST_PRINT_SPI 
   printfpd("(firstaddr:%X)", rch);
#endif


	  }
	   /*
	  else
	  {
		 Havetwoaddr = 1;
#ifdef TEST_PRINT_SPI 
   printfpd("(twoaddr:%X)", rch);
#endif

		 current_command_data[current_command_data_counter++] = rch;
		 if((rch >= firstaddr) && ((rch - firstaddr)< MAX_DATA_SIZE1))
		 {
		    if(current_command_type == 2)    CommandDataLength[current_command_type] = (rch - firstaddr) + 7;
//for 3 request is const		    if(current_command_type == 3)    CommandDataLength[current_command_type] = (rch - firstaddr) + 6;

#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(length:%d)", CommandDataLength[current_command_type]);
#endif
		 }
	   
		 else
		 { 
#ifdef TEST_PRINT_SPI      
    printfp("(no format)");
#endif  

		    current_command_state = WAITING_COMMAND;
    		current_command_counter = 0;
			SetRunCommandPUPM2(CODE_NO_FORMAT);
		 }
	  }	//twoaddr
	 */

   }//< datalength
 } //120713
 return ret; 
}

//______________________________________
/*
extern "C" unsigned char OperateCommandPuPm2(unsigned char * pData)
{
unsigned char Havefirstaddr;
unsigned char Havetwoaddr;
unsigned char firstaddr;
 
unsigned  char ret;
 ret = 0; 
unsigned char rch;// = * pData; 

#ifdef TEST_PRINT_SPI 
  printfpd(" ,%X ", * pData); //110914
 // printfpd("<c:%d>", current_command_counter);

#endif


switch(* pData)
{
case 0xFE:       if(!modeFE) {modeFE = 1;}
				 else{ //embMsgPUPM2_Init();
				    modeFE = 0;
              		current_command_state = RECEIVE_COMMAND;
              		current_command_data_counter = 0;
              		current_command_counter = 1;
					Havefirstaddr = 0;
					Havetwoaddr = 0;
 					CommandDataLength[0] = 6;  //dummy command
       				CommandDataLength[1] = 6;
       				CommandDataLength[2] = 7; //celling in receive
       				CommandDataLength[3] = 6; //

//#ifdef TEST_PRINT_SPI     
           //    printfp("\n\r> start ");
             //  printfpd(" ,%X ", 0xFE); 
//               printfpd("<c:%d>", current_command_counter);
//#endif      
			  		}
				 return ret;
case 0xFC:       if(!modeFC) {modeFC = 1;}
				 else{
				   modeFC = 0;
				  current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;	
 #ifdef TEST_PRINT_SPI     
               printfp("\n\r> stop ");
            //   printfpd(" ,%X ", 0xAA); 
             //  printfpd("<c:%d>", current_command_counter);
               
#endif      
                  	}
                 return ret;   //added
case    0:       if(modeFE) {modeFE = 0;  rch = 0xFE; break;    }
				 else
				 if(modeFC) {modeFC = 0;  rch = 0xFC; break;        }
				
default:		 rch = * pData;
                 break;
}

  current_command_counter++;

#ifdef TEST_PRINT_SPI     
           //    printfp("\n\r> start ");
             //  printfpd(" ,%X ", 0xFE); 
               printfpd("<c:%d>", current_command_counter);
#endif     

  if(current_command_state != WAITING_COMMAND)
	 {
	 BufferCommand[current_command_counter]	= rch;
// embMsgPUPM2_Add(rch);
     }

 if((current_command_counter == COMMAND_POS) &&  (current_command_state == RECEIVE_COMMAND))
  {

//#ifdef TEST_PRINT_SPI 
//   printfpd("(type:%02X)", rch);
//#endif
     if(rch == COP1)	     current_command_type =  1; 
	 else if(rch == COP2)	 current_command_type =  2; 
	 else if(rch == COP3)	 current_command_type =  3; 
     else{ 
     current_command_state = WAITING_COMMAND;
     current_command_type = NO_COMMAND_SSC2;
	// return ret; 

   } 
   #ifdef TEST_PRINT_SPI 
   printfpd("(type:%02X)", current_command_type);
#endif

    return ret;
  } //counter
 else if((current_command_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
     if((unsigned char)rch == rs485_addr)
     {

#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(addr ok:%d)", rch);
#endif

      current_command_state = RUN_COMMAND;
       ret = 1;
      } 
        else
        {
#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(addr bad:%d)", rch);
#endif


      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
	  return ret; 

      }
  } 
 else  if (current_command_state == RUN_COMMAND)
  {
   if((current_command_counter == CommandDataLength[current_command_type]))
  {
   current_command_crc =  rch;   //120720

   if(CheckPUPM2CRC(current_command_counter))
   {

#ifdef TEST_PRINT_SPI   
    printfp("(CRC Ok)");    
#endif
#ifdef PRINT_DEBUG_CRC
	 printfpd("calc crc: %02X", crc_glob);
	 printfpd("<->packet crc:  %02X\n\r",  body_glob);
#endif
     SetRunCommandPUPM2(CODE_NORMA); //ok //hier only set to run - it is interrupt

   }
   else
   {
      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(CRC Bad)");
#endif   
	  SetRunCommandPUPM2(CODE_BAD_CRC);
   }  //crc
 } //counter == datalength
 else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  {

#ifdef TEST_PRINT_SPI 
   printfpd("(CDL:%X)", CommandDataLength[current_command_type]);
    printfpd("(ccc:%X)", current_command_counter);
#endif

      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(finish)");
#endif   



  }	  //> dstslength
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
            &&  (current_command_state == RUN_COMMAND))
  { 
      
	  if((current_command_type == 1)	|| (Havefirstaddr && Havetwoaddr))
	  {
        current_command_data[current_command_data_counter++] = rch;
	  }
	  else if(!Havefirstaddr)
	  {
		 firstaddr = rch; Havefirstaddr = 1;
		 current_command_data[current_command_data_counter++] = rch;
#ifdef TEST_PRINT_SPI 
   printfpd("(firstaddr:%X)", rch);
#endif


	  }
	  else
	  {
		 Havetwoaddr = 1;
#ifdef TEST_PRINT_SPI 
   printfpd("(twoaddr:%X)", rch);
#endif

		 current_command_data[current_command_data_counter++] = rch;
		 if((rch >= firstaddr) && ((rch - firstaddr)< MAX_DATA_SIZE1))
		 {
		    if(current_command_type == 2)    CommandDataLength[current_command_type] = (rch - firstaddr) + 7;
//for 3 request is const		    if(current_command_type == 3)    CommandDataLength[current_command_type] = (rch - firstaddr) + 6;

#ifdef TEST_PRINT_SPI 
   printfpd("\n\r(length:%d)", CommandDataLength[current_command_type]);
#endif
		 }
		 else
		 { 
#ifdef TEST_PRINT_SPI      
    printfp("(no format)");
#endif  

		    current_command_state = WAITING_COMMAND;
    		current_command_counter = 0;
			SetRunCommandPUPM2(CODE_NO_FORMAT);
		 }
	  }	//twoaddr
   }//< datalength
 } //120713
 return ret; 
}


*/
//______________________________________


#ifdef TEST_PARSING_COMMANDS
extern "C" void TestParsing()
{
static unsigned char flag;
unsigned long i = 0;	//!!!!!!	131212 OOOOPs!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//unsigned char Data[] = {0x55, 0xAA, 0xff, 1, 0, 1};	   //command 0
// unsigned char Data[] = {0x55, 0xAA, 0xff, 3, 2, 0x01, 0x02, 9};
// unsigned char Data[] = { 0xAA, 0xff, 3, 2, 0x01, 0x15, 0x1B};
 //unsigned char Data[] = { 0xAA, 0xff, 3, 2, 0x01, 0x5A,03, 0xB0};  //coding 0xaa = with=  5a 03
// unsigned char Data[] = { 0xAA, 0xff, 1, 0, 0x2};
//unsigned char Data[] = {0xAA, 0xff, 1, 4, 5};	   //command 4
unsigned char vol;
unsigned char vol1;
unsigned char vol2;

//unsigned char Data[] = {0xFE,0xFE,0x43,0,0,3,0x46,0xFC,0xFC};	vol = 9; //command 43
//unsigned char Data[] = {0xFE,0xFE,0x44,0,0,0,3,0x47,0xFC,0xFC};	vol = 10; //command 44  1 byte
//unsigned char Data[] = {0xFE,0xFE,0x44,0,0,1,3,4,0x4C,0xFC,0xFC};	vol = 11; //command 44  2 byte
//unsigned char Data[] = {0xFE,0xFE,0x48,0,0,0,0x48,0xFC,0xFC};	vol = 9; //command 48  1 byte
//unsigned char Data[] = {0xFE,0xFE,0x48,0,0,1,0x49,0xFC,0xFC};	vol = 9; //command 48  2 byte
//unsigned char Data[] = {0xFE,0xFE,0x44,02,0,01,02,0x49,0xFC,0xFC};	vol = 10; //command 44  2 byte
//unsigned char Data[] = {0xFE,0xFE,0x44,02,0x10,01,02,00,0x59,0xFC,0xFC};	vol = 11; //command 44  3 byte
//unsigned char Data[] = {0xFE,0xFE,0x43,2,0,3,0x48,0xFC,0xFC};	vol = 9; //command 43  1 byte
//unsigned char Data[] = {0xFE,0xFE,0x48,2,0,3,0x4D,0xFC,0xFC};	vol = 9; //command 48 read 4 bytes
//unsigned char Data[] = {0xFE,0xFE,0x48,2,0,6,0x50,0xFC,0xFC};	vol = 9; //command 48 read 7 bytes
//131211unsigned char Data[] = {0xFE,0xFE,0x48,2,0,0x18,0x62,0xFC,0xFC};	vol = 9; //command 48 read 0x19 bytes

//unsigned char Data[] = {0xFE,0xFE,0x44,0,0,1,3,4,0x4C,0xFC,0xFC};	vol = 11; //command 44  2 byte

//41400
//unsigned char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC};	  vol = 9;
//unsigned char Data1[] = {0xFE,0xFE,0x43,02,0x03,0xB8,0x0,0xFC,0xFC};	vol1 = 9; //command 44
//unsigned char Data1[] = {0xFE,0xFE,0x48,02,0x00,0x04,0x4e,0xFC,0xFC};	vol1 = 9; //command 48

//unsigned char Data[] =  {0xFE,0xFE,0x44,02,0x02,0xA1,0xB8,0xA1,0xFC,0xFC};	  vol = 10;
//cyckl  unsigned char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC,0xFE,0xFE,0x43,02,0x03,0xB8,0x0,0xFC,0xFC};	  vol = 18;
//do not get someunsigned char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC,0xFE,0xFE,0x43,02,0x03,0xB9,0x0,0xFC,0xFC};	  vol = 18; //try b9
//окunsigned char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC,0xFE,0xFE};	  vol = 11; //try b9
char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC,0xFE,0xFE,0x43,02,0x03,0xB8,0x0};	  vol = 16; //try b9
//not cyckle char Data[] =  {0xFE,0xFE,0x43,02,0x02,0xA1,0xE8,0xFC,0xFC,0xFE,0xFE,0x43,02,0x03,0xB8};	  vol = 15; //try b9



 //for(i = 0; i < 8; i++)
// for(i = 0; i < 8; i++)
// for(i = 0; i < 6; i++)

#ifdef TEST_PRINT_SPI
	printfpd("\n\r__________________________%d", flag);
#endif


for(i = 0; i < vol; i++)  //global do not set in zero hier
 {
   OperateCommandPuPm2(&Data[i]);
// //  printfp("+");
  	printfpd("{%d}", i);
	printfpd("<%d>", prm_counter);
 }

  /*
switch (flag)
{
case 0 :
 flag = 1;
 for(i = 0; i < vol; i++)
 {
   OperateCommandPuPm2(&Data[i]);
 }
 break;

default :
 flag = 0;
 for(i = 0; i < vol1; i++)
 {
   OperateCommandPuPm2(&Data1[i]);
 }
 break;

}
 */




}

#endif



extern "C" void  SetFreqPUPM2(unsigned char sel)
{

#ifdef TEST_PRINT_SPI
printfp("\n\rSetFreqPUPM2");
#endif

 	switch(sel)
	{
case  1 : 
       	   modescan1 = 0;

 countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  (pupm1.embpupm2.freq3 << 24) + (pupm1.embpupm2.freq2 << 16) +  (pupm1.embpupm2.freq1 << 8)  + pupm1.embpupm2.freq0; 
		   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
		   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
		   SetFreq1();
			// Stephany19++;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
		/*
case  2 : 
		   modescan2 = 0;
		  countMod2 = 0;
	      delay2 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ , FREQ2_ADDR);
		   emb5StatusReciever2.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
		   SetFreq2();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
					 */
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
		  modescan3 = 0;
		  countMod3 = 0;
		  delay3 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ , FREQ3_ADDR);
		   emb5StatusReciever3.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
		   SetFreq3();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L
			 break;
			 */
#endif //PRM_PCH_THREE_LINES
#ifdef PRM_PCH_SIX_LINES
//____________________________________________________________________
case  4 : 
		  modescan4 = 0;
		  countTransit4 = 0;
		  delay4 = NO_SCAN_DELAY;

		   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ =  (pupm2.embpupm2.freq3 << 24) + (pupm2.embpupm2.freq2 << 16) +  (pupm2.embpupm2.freq1 << 8)  + pupm2.embpupm2.freq0; 
 		   KeepParam(emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ , FREQ4_ADDR);
		   emb5StatusReciever4.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
		   SetFreq4();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
//____________________________________________________________________
//____________________________________________________________________
/*
case  5 : 

		  modescan5 = 0;
		  countTransit5 = 0;
		  delay5 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ =  (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ , FREQ5_ADDR);
		   emb5StatusReciever5.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
		   SetFreq5();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
//____________________________________________________________________
			*/
//____________________________________________________________________
case  6 : 
		  modescan6 = 0;
		  countTransit6 = 0;
		  delay6 = NO_SCAN_DELAY;
	 	  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ =  (pupm2.embpupm2.freq3 << 24) + (pupm2.embpupm2.freq2 << 16) +  (pupm2.embpupm2.freq1 << 8)  + pupm2.embpupm2.freq0; // (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2]; 
 		   KeepParam(emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ , FREQ6_ADDR);
		   emb5StatusReciever6.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
		   SetFreq6();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			 break;
			 
//____________________________________________________________________


#endif //PRM_PCH_SIX_LINES


default :    
  break;
	}

}

extern "C" void  SetAttPUPM2(unsigned char sel)
{
 //printfpd("SetAttPUPM2 %d", sel);
 	switch(sel)
	{
case  1 : 
		 		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = (pupm1.embpupm2.att << 3); 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);
		   SetAtt1();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
			/*
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	  //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt , ATT2_ADDR);		  
		    SetAtt2();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
				*/
#ifdef PRM_PCH_THREE_LINES
/*
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	//		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt , ATT3_ADDR);		  
		    SetAtt3();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
				*/
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt = (pupm2.embpupm2.att << 3); 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt , ATT4_ADDR);		  
		    SetAtt4();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________
		   /*
case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
			emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
	 //		emb5StatusReciever5.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt , ATT5_ADDR);		  
		    SetAtt5();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________
		 */
//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		  //	emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt = MakeAtt(IPBuff[2]); 
			emb5StatusReciever6.emb5statusreciever.stepAtt = (pupm2.embpupm2.att << 3); //=  emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt , ATT6_ADDR);		  
		    SetAtt6();
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
			
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

}







