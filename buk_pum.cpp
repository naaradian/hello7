//#ifndef __TINY__
//#define __TINY__
//#endif
#include "start.h"
#include "hello7.h"
#include "embisr.h"

////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
//t#define IncEmbRS232
//t#define IncEmbRS485
//t#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
//t#define IncEmbSerialACT155
//t#define IncEmbSerialPU_M
////////////////////////////////////////////
//#include "longtoa.cas"
//#include "Ltoa1.c"
//#include "stdlib.h"
//#include "command.h"
//#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"


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
//port

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


void ResetWatchDog()
{
   //	 wd_reset();
};

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
/*
unsigned SelfID() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000A; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
}

unsigned SelfYear() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF0008; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}

unsigned SelfVer1() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000C; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}

unsigned SelfVer2() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000E; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}
*/

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
// 	unsigned CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }

struct EmbMsgUD
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];

	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
   //was error 	unsigned CRC() {	return body[body[1]+2]+1; }
	unsigned short CRC() {	return body[body[1]+2]+1; }
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
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsgUD::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++) body[i]=0;
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
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned short EmbMsgUD::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
		body[Length()+2]=c+1;
		return c+1;
	}
	else return 0;
} 
//_________________________________________________CRC
/*
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
*/
/*
struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned counter;
	unsigned char body[270];
// Start/8	TOM/8	Cycle/8	AddrI/16	AddrS/16	Type/8	Length/16	 BODY/ Length	CRC/16	Blank/8
	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned AddrR()	{	return body[10] + (body[9]<<8);	 }		// 2
	void SetAddrI(unsigned word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;	}

	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}

	unsigned char Type()	{ return body[6]; }		// 1
	unsigned Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned FullSize(); 			// 2
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
	unsigned CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }


	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

	void Init();
	unsigned Add(unsigned char byte);
	unsigned Used() { return counter; }
	unsigned IsFree() { return 270-counter; }
	int IsEnd();
	int IsEndOfHeader();
	unsigned ChkCRC();
	unsigned CalcCRC();
	unsigned ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
//	unsigned char IsRS485() { return readyToSend.msgStatus.isRS485; } 
//	void SetRS485(unsigned char i) { readyToSend.msgStatus.isRS485=i; } 
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }

	void SetDir(unsigned char d) { dir= d; } // dir = 1 пришел с West, dir=2 прищел с East

	void Copy(EmbMsg m);
};
*/
/*
struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[270];
// Start/8	TOM/8	Cycle/8	AddrI/16	AddrS/16	Type/8	Length/16	 BODY/ Length	CRC/16	Blank/8
	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned short AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned short AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);	 }		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;	}

	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}


	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
	unsigned short CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned char Body(int  i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }


	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

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
//	unsigned char IsRS485() { return readyToSend.msgStatus.isRS485; } 
//	void SetRS485(unsigned char i) { readyToSend.msgStatus.isRS485=i; } 
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
	dir=0;
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend.byte=0;
}

unsigned short EmbMsg::FullSize() 
{	
	if(Length()<=256) return Length() + 11;	 
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
			if(counter==Length()+11)
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
	if(CRC()==ReCalcCRC()) return 1;
	else return 0;
}

unsigned short EmbMsg::CalcCRC()
{
  unsigned i;
	unsigned short c=0;
	if(Length()<=256) 
	{
		for(i=0; i<Length()+11; i++) c += body[i];
		body[Length()+9]=(c>>8)&0xFF;
		body[Length()+10]=c&0xFF;
		return c;
	}
	else return 0;
} 

unsigned short EmbMsg::ReCalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<=256) 
	{
		for(i=0; i<Length()+9; i++) c += body[i];
		return c;
	}
	else return 0;
}
 */

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

struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[270];
// Start/8	TOM/8	Cycle/8	AddrI/16	AddrS/16	Type/8	Length/16	 BODY/ Length	CRC/16	Blank/8
	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned short AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned short AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);	 }		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;	}

	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}


	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
	unsigned short CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }


	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

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
//	unsigned char IsRS485() { return readyToSend.msgStatus.isRS485; } 
//	void SetRS485(unsigned char i) { readyToSend.msgStatus.isRS485=i; } 
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
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned short EmbMsg::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<=256) 
	{
		for(i=0; i<Length()+11; i++) c += body[i];
		body[Length()+11]=(c>>8)&0xFF;
		body[Length()+12]=c&0xFF;
		return c;
	}
	else return 0;
} 

/////////////////////
struct EmbMsgBuffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
    EmbMsg Buff[16];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned short Used();
    unsigned short Free();
};

void EmbMsgBuffer::Init()
{
  BuffSize = 16;
  Head = 0;
  Tail = 0;
}

void EmbMsgBuffer::Add(EmbMsg &msg)
{
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize) Head = 0;
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
  int short n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
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
	unsigned char dem1; // Состояние платы интерфейсов      // 64
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
	unsigned char ver;						// 1
	unsigned char reserv; 				// 2
	unsigned char reserv1;	 //my					// 1
	unsigned char reserv2;	 //my
	unsigned long ulBlock;				// 6	 +2
	unsigned long ulErrOut;				// 10	 +2
	unsigned long ulErrAfterRS1;	// 14		 +2
	unsigned long ulErrAfterRS2;	// 18	    +2
	unsigned long ulErrBeforeRS1;	// 22	   +2
	unsigned long ulErrBeforeRS2;	// 26	   +2
	unsigned char state[16];			// 42	 +2
};


//#pragma BSS()

union UnStatePUM
{
	StatePUM statePUM;
 //t	unsigned char byte[42];
 unsigned char byte[44];
};

struct StateRRL
{
	unsigned char ver;	
	unsigned char state;  // Бит 0: "0" - остутсвтие связи с ППУ1, "1" - норма Бит 1: "0" - остутсвтие связи с ППУ2, 
	unsigned char ppu1_bytes[32];
	unsigned char ppu2_bytes[32];														// 34
};

union UnStateRRL
{
	StateRRL stateRRL;
	unsigned char byte[66];
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
/////////////////////

//	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0,time2=0,time3=0,time4=0,time5=60;
unsigned char flagADUC1=0, flagADUC2=0;

void Callback0()
{
  time1++;
  time2++;
  time3++;
  time4++;
  time5++;
///////////  Первая ВНЧ  ////////////
/*	if(inportb(0x510)!=0xFF) 
		if(inportb(0x510)&0x10) 
			flagADUC1++;
///////////  Вторая ВНЧ  ////////////
	if(inportb(0x5C0)!=0xFF) 
		if(inportb(0x5C0)&0x10) 
			flagADUC2++;*/
/////////////////////////////////////
}

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
 UL2UC ul2uc;
 UI2UC ui2uc;
 unsigned short temp_crc;
// unsigned char * addrRAM;
 unsigned long shift;
 unsigned long len;


 
 	EmbTimerCallback embTimerCallback0;
/*
void SendPower(unsigned char trunk, unsigned char power)
{

};
*/
	EmbMsgBuffer rBuffEmbMsg;	
	
	EmbMsg *embMsgRequest;

	EmbMsg embMsg232;
	EmbMsg embMsg485;
//____________________________________________________________________________RDN
	EmbMsg embMsg485E;
//____________________________________________________________________________RDN
//____________________________________________________________________________232e
EmbMsg embMsg232E;
//____________________________________________________________________________232e


	EmbMsg embMsg;
	EmbMsg embMsgAns;
	EmbMsg embMsgTemp;
	EmbMsgUD embMsgUD_1;
	EmbMsgUD embMsgUD_2;
	EmbMsgUD embMsgUDRequest_1;
	EmbMsgUD embMsgUDRequest_2;
//	EmbMsgCover embMsgCoverRequest;
	

	EmbRS232 embRS232;	

  	EmbRS485 embRS485;	

	EmbSerialACT155 embSerialACT155;

	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned char powerInFar[9];
	unsigned char flag_start_power = 0, powerInBuff[4];
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];

	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1, tst_ppu1; 
	unsigned char err_ppu2, tst_ppu2; 
	unsigned char byte, westByte, eastByte; 
	unsigned char mode5A=0, mode5AWest=0, mode5AEast=0; 
 	unsigned char mode5A485 = 0, mode5A232E = 0, mode5A485E = 0;



	unsigned char cycle=0;
	unsigned char i232=0, iTrans=0, iMod=0;
	unsigned char ans1=0, ans2=0, addrUD=0;
	unsigned short aI, aS, aR;	
	unsigned short led;

	UnStateBMD155 unStateBMD155;
	UnEmb2TypeVer unEmb2TypeVer; 
	UnEmb2NetStat unEmb2NetStat;
	UnStateRRL unStateRRL;
	UnStatePUM unStatePUM;

	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;
	long count_notRS1;
	long count_notRS2;
	long err_tmp;

	unsigned char tlf_number[6];
	unsigned char tlf_counter=0;
	unsigned char tlf_state=0;
	unsigned char presto = 0;
	unsigned char ring_counter = 0;
	unsigned long presto_time =0;
	unsigned long wait_time =0;
	unsigned long presto_ring =0;

	unsigned short addr1;
  //	unsigned char far *bt;
	unsigned char  *bt;
//_new
	unsigned short countMod=0;
	unsigned short countTransit=0;
 unsigned char lt=0xFF;
	long j=0;
  //t	unsigned short delay = 10;	  //my
	unsigned short delay = 10;  //my
	unsigned short incr = 0;
	int rrr=0;


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//void main()
extern "C"  void Init_BUKC(void)
{

//_______________________________________________________________
 EmbInit(); //my
 AsciiInit();
//_______________________________________________________________
 time1=0; time2=0; time3=0; time4=0; time5=60;
 flagADUC1=0; flagADUC2=0;
 flagRequest=0;
 serr=0xFF; crc_temp=0;
 i=0;
 time1old=0; time2old=0;
 request1=0; request2=0;
 time3Marker=0; time3BlankTransit=0; time3BlankMod=0;
 flag_start_power = 0; 
 markerWest=0; markerEast=0; ready_transit=0; ready_mod=0; dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 delete_msgWest=0; delete_msgEast=0; recieveWest=0; recieveEast=0;
 countSend=0; countRecv=0;
 time3highID=0;
 mode5A=0; mode5AWest=0; mode5AEast=0; 
 mode5A485=0; mode5A232E=0; mode5A485E=0;
 cycle=0;
 i232=0; iTrans=0; iMod=0;
 ans1=0; ans2=0; addrUD=0;
 tlf_counter=0;
 tlf_state=0;
 presto = 0;
 ring_counter = 0;
 presto_time =0;
 wait_time =0;
 presto_ring =0;
 countMod=0;
 countTransit=0;
 lt=0xFF;
 j=0;
 //t delay = 10;
//091228  delay = 10;
  delay = 30;  //091228

 incr = 0;
 rrr=0;
 led = 0xff;

//_______________________________________________________________



//	outportb(0x6FF,inportb(0x6FF)|0x10);
//	unsigned short countMod=0;
//	unsigned short countTransit=0;

///////  Канал транзит  ///////
///////////////////////////////
	rBuffEmbMsg.Init();

   //	ResetWatchDog();
	embSerialACT155.Init();

  //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
  //	embRS485.Init(384);		// Инициализация RS485 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
//////////////////////
	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}

	for(i=0; i<32; i++)
	{
		unStateRRL.stateRRL.ppu1_bytes[i] = 0;
		unStateRRL.stateRRL.ppu2_bytes[i] = 0;
	}
//// Загрузка телефонного кодека ////
	for(i=0; i<9; i++) powerInFar[i]=0;

 //	int rrr=0;
#ifdef PROG_BUKC
	unEmb2TypeVer.emb2TypeVer.type       = 0x0504;	 //buk
#else
   unEmb2TypeVer.emb2TypeVer.type       = 0x0011;	//pum

#endif

 //	unEmb2TypeVer.emb2TypeVer.softVer    = 0x0234; //232 <-> ethernet 888
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER; //
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();
	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}


	unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = inportb(0x5A1);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = inportb(0x5A2);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x5A4);

  //	bt = (unsigned char far*)0x80000000;
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


///////  Включаем канал транзит 0x95 - 0x00  ///////
///////  "конец" 0x95 - 0x01
////////////////////////////////////////////////
//	Enable(); // Разрешаем все прерывания
	send1[0]=12;
	send2[0]=12;

	embMsgTemp.Init();

	time3Marker = time3;

	unStateRRL.stateRRL.ver = 0x01;
//	unStateRRL.stateRRL.state = 0x01;

	unStatePUM.statePUM.ver = 0x01;
	unStatePUM.statePUM.reserv = 0x20;
  //	unsigned char lt=0xFF;
  //	long j=0;
  //	unsigned delay = 10;
  //	unsigned incr = 0;
  outportb(0xae, 0xff);
}
//  while(1)
/*
extern "C" void SetLed(char p,char l)
{
  if(p == 1){ led &= (~l);}else{ led |= l;}
  outportb(0xae,led);
}
   */



extern "C" void BUKC(void)
	{
////
		unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = inportb(0x501);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = inportb(0x502);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x514);
//		bt = (unsigned char far*)0x80000000;
		 bt = (unsigned char *)(NVRAM_BASE);

		unEmb2TypeVer.emb2TypeVer.signature_software[0] = *bt;
		unEmb2TypeVer.emb2TypeVer.signature_software[1] = *(bt+1); // tlf - номер
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

		rrr++;		
	//	ResetWatchDog();

  //		unsigned short eee;

		while(embSerialACT155.UsedMod())
		{
 //		printf("\n\r UsedMod");
	  //		led &= 0xf7
      //      outportb(0xae,led);
  //			SetLed(1,0x8);
			byte = embSerialACT155.GetMod();
	  //		 printf(".%0X", byte);
			switch(byte)
			{
				case 0xAA: embMsgUD_1.Init(); stemp++; /*lt=lt&0xFE; outportb(0x5AE,lt);*/ break; // Пакет
				case 0x5A: mode5AWest=1; break;
				case 0x55: break;
				default:
					if(mode5AWest) 
					{
						embMsgUD_1.Add(Modify5A(byte));
						mode5AWest=0;
					}
					else embMsgUD_1.Add(byte);
			}
			if(embMsgUD_1.IsEnd())
			{		
				/*lt=lt|0x01; outportb(0x5AE,lt);*/
				countMod=0;
if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r<");
		 	}
				for(i=0; i<32; i++)
				{
					{
						ans1=0;
						unStateRRL.stateRRL.ppu1_bytes[i] = embMsgUD_1.Body(i);
if(GetTestMode() == 0x50)
			{
			   printfp("_");
			    printfpd("%X", embMsgUD_1.Body(i));

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }
					}
				}
				for(i=0; i<16; i++)
				{
					{
						ans1=0;
						unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsgUD_1.Body(i);
					}
				}
//			unStateRRL.stateRRL.ppu1_bytes[13] = embSerialACT155.count;
//			unStateBMD155.stateBMD155.ppu1_bytes[13] = embSerialACT155.count;
	   //			SetLed(0,0x8);
				break;
			}
	 //		SetLed(0,0x8);
		}


		if((time1-time1old) > delay) // 10
		{
		 //  SetLed(1,0x10);
			time1old = time1;
			countMod++;
	 //		printf("\n\r time1");
		
	  
			if(embMsgUDRequest_1.IsReadyToSend())
			{
	  //		  SetLed(1,0x10);
	  // 		printf("\n\r IsReadyToSend 1");
		 //		printEthStringAdd(0,0);
				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
		//		  	  printf("\n\r_FF_AA");
if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
		 	}


				for(i=0; i<embMsgUDRequest_1.Length()+5; i++) 
				{
		//		  	  printf("_%02X",embMsgUDRequest_1.body[i]);
		   //			printEthStringAdd(1,embMsgUDRequest_1.body[i]);

					switch(embMsgUDRequest_1.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgUDRequest_1.body[i]);
			if(GetTestMode() == 0x50)
			{
			    printfp(".");
			    printfpd("%X", embMsgUDRequest_1.body[i]);
		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }

					}
				}
				embMsgUDRequest_1.Init();

			//		printEthStringAdd(2,0);

		   //		  SetLed(0,0x10);
			}
			else
			{
		 //	SetLed(1,0x20);

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);// был 1 //addrUD);
				embMsgUDRequest_1.SetLength(1);
				embMsgUDRequest_1.SetBody(0,0x00);
				embMsgUDRequest_1.CalcCRC();
if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
		 	}

				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
			  //	  printf("\n\r.FF.AA");
				for(i=0; i<embMsgUDRequest_1.Length()+3; i++) 
				{
			//  	  printf(".%02X",embMsgUDRequest_1.body[i]);

					switch(embMsgUDRequest_1.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default:
					
					 embSerialACT155.AddMod(embMsgUDRequest_1.body[i]);
					if(GetTestMode() == 0x50)
			{
		 	   	    printfp(".");
			    printfpd("%X", embMsgUDRequest_1.body[i]);

		 	}

				   }
					
				}
				embMsgUDRequest_1.Init();
  		   //		SetLed(0,0x20);

			}
		}

		if(countMod>5) 
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu1_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu1_bytes[i] = 0;
			}
//			unStateRRL.stateRRL.state = 0x00;
		}
////////////////////////////////////////////////
		while(embSerialACT155.UsedTransit())
		{
			byte = embSerialACT155.GetTransit();
		//	 printf(".%0X", byte);

			switch(byte)
			{
				case 0xAA: embMsgUD_2.Init(); stemp++; /*lt=lt&0xFD; outportb(0x5AE,lt);*/ break; // Пакет
				case 0x5A: mode5AEast=1; break;
				default:
					if(mode5AEast) 
					{
						embMsgUD_2.Add(Modify5A(byte));
						mode5AEast=0;
					}
					else embMsgUD_2.Add(byte);
			}
			if(embMsgUD_2.IsEnd())
			{		
				/*lt=lt|0x02;	outportb(0x5AE,lt);*/
				countTransit=0;
		 //		printf("\n\r222>>>");
				for(i=0; i<32; i++)
				{
					{
						ans1=0;
						unStateRRL.stateRRL.ppu2_bytes[i] = embMsgUD_2.Body(i);
		 //				printf(".%0X",embMsgUD_2.Body(i));

					}
				}
				for(i=0; i<16; i++)
				{
					{
						ans1=0;
						unStateBMD155.stateBMD155.ppu2_bytes[i] = embMsgUD_2.Body(i);
					   
					}
				}
//				unStateRRL.stateRRL.ppu2_bytes[13] = embSerialACT155.count;
//				unStateBMD155.stateBMD155.ppu2_bytes[13] = embSerialACT155.count;
				break;
			}
		}

		if((time1-time2old)>delay) // 10
		{
//			incr++;
//			if(incr*delay>1000)
//			{
//				incr=0;
//				delay++; 
//				if(delay>100) delay = 5;
//			}
			time2old = time1;
			countTransit++;
			if(embMsgUDRequest_2.IsReadyToSend())
			{
	   	//	printf("\n\r IsReadyToSend 2");

				embSerialACT155.AddTransit(0xFF);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgUDRequest_2.Length()+5; i++) 
				{
					switch(embMsgUDRequest_2.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_2.body[i]);
					}
				}
				embMsgUDRequest_2.Init();
			}
			else
			{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);// был 1 //addrUD);
				embMsgUDRequest_2.SetLength(1);
				embMsgUDRequest_2.SetBody(0,0x00);
				embMsgUDRequest_2.CalcCRC();

				embSerialACT155.AddTransit(0xFF);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgUDRequest_2.Length()+3; i++) 
				{
					switch(embMsgUDRequest_2.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_2.body[i]);
					}
				}
				embMsgUDRequest_2.Init();
			}
		}

		if(countTransit>5) 
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu2_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu2_bytes[i] = 0;
			}
			unStateRRL.stateRRL.state = 0x00;

		}
//////////////////////////////////////////////////
		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;
//////////////////////////////////////////////////
//////////////////////////////////////////////////
		i232=0;
   
		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
		 //		printf("\n\r.55");
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; 
		   	 //	  printf("\n\r.5A");

			break;
			default:
		  // 	  printf(".%02X",byte);

				if(mode5A) 
				{
					embMsg232.Add(Modify5A(byte));
					mode5A=0;
				}
				else embMsg232.Add(byte);
			}
			if(embMsg232.IsEnd()) 
				break;
//			if(++i232>10) break;
		}

		if(!embMsg232.IsEnd())
		{

			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
////////////////////////////////////////////////
//			embRS232.Trans(HexChar((byte>>4)&0x0F));	
//			embRS232.Trans(HexChar(byte&0x0F));	
//			embRS232.Trans('.');
////////////////////////////////////////////////
				switch(byte)
				{
				case 0x55: 
					embMsg485.Init();
					break; 
				case 0xAA: embMsg485.Init();// printf("\n\r++++");
			//	printfp("\n\r");
				 break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485=1; // printf("\n\r++++");
				break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else
					 {
					 embMsg485.Add(byte);
				 // 	 printfpd(" %02X", byte);
					 }
				}
				// 	printf("_%X", byte);  //with this work


				if(embMsg485.IsEnd()) 
			  				break;
			}
//_____________________________________________________________________RDN
if(!embMsg485.IsEnd())
		{
      while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
////////////////////////////////////////////////
//			embRS232.Trans(HexChar((byte>>4)&0x0F));	
//			embRS232.Trans(HexChar(byte&0x0F));	
//			embRS232.Trans('.');
////////////////////////////////////////////////
				switch(byte)
				{
				case 0x55: 
					embMsg485E.Init(); //	 printf("\n\r0x55.AA");
					break; 
				case 0xAA: embMsg485E.Init(); // printf("\n\r0xAA.");
				 break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485E=1;
				 break;
				default:
					if(mode5A485E) 
					{
						embMsg485E.Add(Modify5A(byte));
						mode5A485E=0;
					}
					else embMsg485E.Add(byte);
				//   printf(".0x%02X", byte);
				}
				 if(embMsg485E.IsEnd())

			  				break;
			}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	}  //	!embMsg485.IsEnd


		}

 
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
   
if(embMsg485E.IsEnd()) 
				{
				//	if(embMsg485E.AddrI() != SelfID())
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
					// ->>	// Ioaao a RS-232
							aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();

							 
							embMsg485E.SetAddrI(aR);
							embMsg485E.SetAddrS(aI);
							embMsg485E.SetAddrR(aS);
							
						  					   //		printfp("\n\r44444444444444444444444444444");

							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg485E.FullSize(); i++) 
							{
								switch(embMsg485E.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485E.body[i]);
								}
							}
							embRS232.Trans(0x55);
					 //		embRS232.Trans_RDN(COMP_DEF_MAC_END);
							//  embRS232.Trans_RDN_Full(embRS232.HostMAC);	
					}
					
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
						if(embMsg485E.AddrS()==SelfID())
						{
							if(!(embMsg485E.TOM()&0x01))
							{
								flagRequest=4;
								embMsg485E.SetRS485();
								embMsgRequest = &embMsg485E;
							}
						}
					}
				}

	 else //10.24
				if(embMsg485.IsEnd()) 
				{
			  
					if(embMsg485.AddrI() != SelfID())
					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
				   //	   printfp("\n\r3333333333333333333333333333333");
					   

					  	// ->>	// Ioaao a RS-232
							aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aR);
							embMsg485.SetAddrS(aI);
							embMsg485.SetAddrR(aS);
							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg485.FullSize(); i++) 
							{
								switch(embMsg485.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485.body[i]);
								}
							}
							embRS232.Trans(0x55);
						//	embRS232.Trans_RDN(COMP_DEF_MAC_END);
						  //	embRS232.Trans_RDN_Full(embRS232.HostMAC);
						}
			  
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{
							if(!(embMsg485.TOM()&0x01))
							{
								flagRequest=3;
								embMsg485.SetRS485();
								embMsgRequest = &embMsg485;
							}
						}
					}
				  //	 embMsg485.Init();
				  //	 flagRequest = 0;

				}
			  else //1024


			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
	  
 	   

			if(flagRequest)//embMsgRequest->IsEnd())
			{
				if(embMsgRequest->IsRS485())
				{
				  //	if(flagRequest!=3)
					//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 					{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
						  //	embMsgRequest->SetAddrI(aS);
						  //	embMsgRequest->SetAddrS(aR);
						  //	embMsgRequest->SetAddrR(aI);
							embMsgRequest->SetAddrI(aR);
						    embMsgRequest->SetAddrS(aI);
						    embMsgRequest->SetAddrR(aS);


				   //			RS485_disable_RX_interrupt();

							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					//			 printf(".AA");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					//		   printf(".%0X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransEC(0x5A); embRS485.TransEC(0x00); break;
								case 0x55: embRS485.TransEC(0x5A); embRS485.TransEC(0x01); break;
								case 0xA5: embRS485.TransEC(0x5A); embRS485.TransEC(0x02); break;
								case 0xAA: embRS485.TransEC(0x5A); embRS485.TransEC(0x03); break;
								default: embRS485.TransEC(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransEC(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
//____________________________________________________________________________________RDN  <<
			 			  	flagRequest = 0;
					}
				}

				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485())
					{
    //   printf("\n\rbefore : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
						embMsgAns.SetRS485();
						aI = embMsgRequest->AddrI();
						aS = embMsgRequest->AddrS();
						aR = embMsgRequest->AddrR();

						embMsgAns.SetAddrI(aS);
						embMsgAns.SetAddrS(aI);
						embMsgAns.SetAddrR(aR);
	//	printf("\n\rafter : I = %X S = %X R = %X", embMsgAns.AddrI(),embMsgAns.AddrS(), embMsgAns.AddrR());
					}
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
						
					switch(embMsgRequest->Type())
					{

					case 0x01: // запрос типа
				  //		printf("\n\r 0x01");

						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

//______________________________________________________________________________________________						
					case 0x02 :
						   embMsgAns.SetType(0x02);
						   embMsgAns.SetLength(embMsgRequest->Body(2) + 3);
						   embMsgAns.SetBody(0,embMsgRequest->Body(0));	//#	number 1 Byte
						   embMsgAns.SetBody(1,embMsgRequest->Body(1));	//#	number 2 Byte
						   embMsgAns.SetBody(2,embMsgRequest->Body(2));	// celling

						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							write_xil_char( ( (embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i), embMsgRequest->Body(3 + i));
						   }


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							 embMsgAns.SetBody(3 + i ,read_xil_char((embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i));
						   }
							//need make GetPort
					    break;
					   	   				
//______________________________________________________________________________PS
//090403 #ifndef PROG_BMD35

			 
					case 0x05: // Загрузка файла (запись в устройство) 
 			   	 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);


				  		ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);

						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

				  		shift = ui2uc.ui;

		 				ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				 		len = ui2uc.ui;
						temp_crc=0;

			 			for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);

		   				ui2uc.uc[0] = embMsgRequest->Body(len+8);
		   				ui2uc.uc[1] = embMsgRequest->Body(len+9);
		   				ui2uc.uc[2] = 0;  //1107
						ui2uc.uc[3] = 0;  //1107

						if(ui2uc.ui==temp_crc)
						{ //crc

						if(ul2uc.uc[3] == 0x80) //port : if try use nvram
						{
	  			 		 for(i=0; i<len; i++)
				  		   {
		  			    			write_nvram_char(i + shift, embMsgRequest->Body(i+8));
				  		   }
						 }
						 else  //enover memory
						 {
					  //   shift +=  (unsigned long)(embMsgRequest->Body(0)) << 16;	 //add to address 
					       wd_reset();
						   shift +=  ul2uc.ul;	 //add to address 
						   for(i=0; i<len; i++)
				  		   {
					 //   	write_buffer_char( embMsgRequest->Body(i+8), NO_START_WRITE_BUFFER);
						   	write_buffer_char1( embMsgRequest->Body(i+8), i+ shift);
						   }
					
						 }
				  	 
					 	} //crc
					
						embMsgAns.SetType(0x05);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);		
				 
				 	break;
				 				
//___________________________________________________________________________________
					case 0x38:	 //all commands
						embMsgAns.SetType(0x38);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);
						if(
							(embMsgRequest->Body(0) == 0x42) &&
							(embMsgRequest->Body(1) == 0x31) &&
							(embMsgRequest->Body(2) == 0x58) &&
							(embMsgRequest->Body(3) == 0x76) &&
							(embMsgRequest->Body(4) == 0x9C) &&
							(embMsgRequest->Body(5) == 0xBA) 
						   )
						   {
						   	switch(embMsgRequest->Body(6))
							{
					  		 case 0:   break; // write_buffer_char( 0, START_WRITE_BUFFER);	break;
							 case 1:   ProgWrite(); break;
							 case 2:   XilWrite(); break;
							 case 3:   DPDWrite(); break;
							 case 4 :  set_test_mode(0x27);	  dev_restart(); 	break;
							 case 5 :  dev_restart(); 	break;
							 case 6 :  write_nvram_char(RESTARTS_NVRAM_ADDRESS,0);
							 case 7 :  m_load_xilinx3((char)XILINXPG, 1);

					  	 	}							   
						   }
						   break;
		  
//___________________________________________________________________________________



					case 0x07: /// Генерим запрос маркера во все направления
				  //	printf("\n\r 0x07");

						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Запрос состояния
				  //	printf("\n\r>>");

						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++)
						{
					 	embMsgAns.SetBody(i,unStateBMD155.byte[i]);
					 //	embMsgAns.SetBody(i,(30 + (i%20)));
				  //	  	printf (".%02X",unStateBMD155.byte[i]);
						}
				//		printf("\n\r>>");

						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
						unStateBMD155.stateBMD155.demPI=0;
						unStateBMD155.stateBMD155.loopPI=0;
						unStateBMD155.stateBMD155.statePI=0;
						break;
					case 0x09:
				  //	printf("\n\r 0x09");
						 if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
					 //		     printf(">>");

						//	printf("\n\r Body(0)==1");
								embMsgUDRequest_1.Init();
								embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
								embMsgUDRequest_1.SetLength(2);
								embMsgUDRequest_1.SetBody(0,embMsgRequest->Body(1));
								embMsgUDRequest_1.SetBody(1,embMsgRequest->Body(2));
								embMsgUDRequest_1.CalcCRC();
								embMsgUDRequest_1.SetReadyToSend();
						//		printf(".%02X",embMsgUDRequest_1.IsReadyToSend());
							  //	printf(".%02X",embMsgUDRequest_1.Body(0));
							  //  printf(".%02X\n\r",embMsgUDRequest_1.Body(1));
						  //      printf("\n\r>>>>>>i: %d",  embSerialACT155.count);

							}
							if(embMsgRequest->Body(0)==2)
							{
					   //			printf("\n\r Body(0)==2");

								embMsgUDRequest_2.Init();
								embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
								embMsgUDRequest_2.SetLength(2);
								embMsgUDRequest_2.SetBody(0,embMsgRequest->Body(1));
								embMsgUDRequest_2.SetBody(1,embMsgRequest->Body(2));
								embMsgUDRequest_2.CalcCRC();
								embMsgUDRequest_2.SetReadyToSend();
							}

						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
			//			printf("\n\r----> 0x0A");

						//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(4);//4
							embMsgUDRequest_1.SetBody(0,0x07);
							embMsgUDRequest_1.SetBody(1,embMsgRequest->Body(0));
							embMsgUDRequest_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
							embMsgUDRequest_1.SetBody(3,embMsgRequest->Body(4));
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
						}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x02);
							embMsgUDRequest_2.SetLength(4);//4
							embMsgUDRequest_2.SetBody(0,0x07);
							embMsgUDRequest_2.SetBody(1,embMsgRequest->Body(0));
							embMsgUDRequest_2.SetBody(2,embMsgRequest->Body(1)&0x3F);
							embMsgUDRequest_2.SetBody(3,embMsgRequest->Body(4));
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
						}
						break;
					case 0x0B:
			  //	   	printf("\n\r----> 0x0B");
						//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(3); //3
							embMsgUDRequest_1.SetBody(0,0x08);
							embMsgUDRequest_1.SetBody(1,embMsgRequest->Body(0));
							embMsgUDRequest_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
						//	printf("\n\r>>");
						  //	printf(".%02X",embMsgRequest->Body(0));
							//printf(".%02X\n\r",embMsgRequest->Body(1));


						}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x02);
							embMsgUDRequest_2.SetLength(3);//3
							embMsgUDRequest_2.SetBody(0,0x08);
							embMsgUDRequest_2.SetBody(1,embMsgRequest->Body(0));
							embMsgUDRequest_2.SetBody(2,embMsgRequest->Body(1)&0x3F);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
						}
						break;
					case 0x10:
				   //	printf("\n\r 0x10");
							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
							for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
						break;
					case 0x13:
				   //	 printf("\n\r 0x13");

							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
					   //		bt = (unsigned char far*)0x80000000;
							 bt = (unsigned char *)(NVRAM_BASE);


							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x15:
				   //	 printf("\n\r 0x15");

						break;
					}
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(flagRequest == 1) 
					{

			//	printfp("\n\r11111111111111111111111111111111");
						embRS232.Trans(0x55);
						embRS232.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
							case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
							case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
							case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
							case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
							default: embRS232.Trans(embMsgAns.body[i]);
							}
						}
						embRS232.Trans(0x55);
						 embMsg232.Init();
						flagRequest = 0;
					}

					
					if(flagRequest == 3) 
					{
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
				//	 	printf("\n\r485> AA");
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
				  //	 	 printf(".%0X",	embMsgAns.body[i]);
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgAns.body[i]);
							}
						}
						embRS485.Trans(0x55);
						 embMsg485.Init();
						flagRequest = 0;
					}
//_________________________________________________________________________________RDN
				if(flagRequest == 4) 
			   	{ 
			  //		RS485_receive_disable();

			   embRS485.TransE(0x55);
					//	 printf("\n\r>>>>embMsgRequest->AddrS() = %X", embMsgRequest->AddrS());	 //3310
					//	 printf("\n\r>>>>embMsgRequest->AddrI() = %X", embMsgRequest->AddrI());	 //	3309
					//	 printf("\n\r>>>>embMsgRequest->AddrR() = %X", embMsgRequest->AddrR());	 //enower

					//	 printf("\n\reth>55");

						embRS485.TransE(0xAA);
					//	 printf(".AA");	 //work 485

						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
					 //	  printf(".%0X",	embMsgAns.body[i]);	//work 485

							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgAns.body[i]);
							}
						}
						embRS485.TransE(0x55);
				//		 printf(".55");
			//	  RS485_receive_enable();
				  embRS485.Trans_RDN(embMsgAns.AddrS());
			//		 	embRS485.EmptyReceive();	//my: from testing mf20	//remaked 20.02.2008
						 embMsg485E.Init();
						flagRequest = 0;
					}	// ==4
 //________________________________________________________________________________________RDN

				}
				else
				{
						if(flagRequest == 1) 
					{
						embMsg232.Init();  //???need
					}
				  						if(flagRequest == 3) 
					{
						embMsg485.Init();  //???need
					}
						if(flagRequest == 4) 
					{
						embMsg485E.Init();  //???need
					}

			 	}
				flagRequest = 0;
				embMsgRequest = NULL;
			}
			
	}
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
// hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;

//_________________________________________
//    TimerISR();
//_________________________________________


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
//#ifdef PROG_BUKC
//my_int_enable_irq0();
//#endif //PROG_BUKC

  embSerialACT155.IsrXX();
  IntFlag |= INT0_FLAG;

#endif // IncEmbSerialMD34AVT

#ifdef IncEmbSerialACT155
     embSerialACT155.IsrXX();
#endif // IncEmbSerialACT155
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq0();
 }

}

//extern unsigned long Stephany19; 
extern  "C" unsigned long TypeVer(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.type;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.softVer;
//ret = 8;//t
//Stephany19 = ret;	  //t
return ret;
}

extern  "C" unsigned long CtrlNumberS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlYear;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlNumber;
//ret = 9;   //t
//Stephany19 = ret;	 //t
return ret;
}

extern  "C" unsigned long CtrlVerS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer1;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 10;//t
//Stephany19 = ret;  //t
return ret;
}

extern  "C" unsigned char * GetStateRRL1O(unsigned long* data_len)
{
// unsigned long i;
 *data_len = 32l;
 // *data_len = 3l;
 //for(i = 0; i < 32; i++)
// {
 //  unStateRRL.stateRRL.ppu1_bytes[i] = (unsigned char)(i * 11); //t
 //}
 return &unStateRRL.stateRRL.ppu1_bytes[0];
// return "Ok!";
}

extern  "C" unsigned char * GetStateRRL2O(unsigned long* data_len)
{
// unsigned long i;
 *data_len = 32l;
 // *data_len = 3l;
//for(i = 0; i < 32; i++)
// {
//  unStateRRL.stateRRL.ppu2_bytes[i] = (unsigned char)(i * 11); //t
// }
 return &unStateRRL.stateRRL.ppu2_bytes[0];
// return "Ok!";
}
#define ADDRPIPE1	 1
#define ADDRPIPE2	 2

extern  "C" void SetRRLCmdO(unsigned char* data_ptr, unsigned long* data_len)
{
// Stephany19 = 0l;
 unsigned long length;
 length = *data_len;
 while(length--)
 { 
 //Stephany19 <<= 8;
 //Stephany19	 +=  * data_ptr;
 	embRS232_rcvbuf_Add((unsigned char)(* data_ptr++));
 }

 /*
 // unStatePUM.statePUM.state[5] = (unsigned char)*data_ptr;
 EmbMsgUD embMsgUDRequest_1;
 EmbMsgUD embMsgUDRequest_2;

  unsigned char pipe;
  unsigned char commandrrl;
  unsigned char length;
 // unsigned char datarrl1, datarrl2;
  unsigned char datarrl[10];
  pipe = *data_ptr++;
  commandrrl = *data_ptr++;
//  datarrl1 =  *data_ptr++;
//  datarrl2 =  *data_ptr;
//_______________________________________________________________________
 		 if(pipe == ADDRPIPE1)
		 {
	            embMsgUDRequest_1.Init();
		   //		embMsgUDRequest_1.SetAddr(0);// был 1 //addrUD);
		   //   	embMsgUDRequest_1.SetLength(1);
		   //		embMsgUDRequest_1.SetBody(0,0x00);

				embMsgUDRequest_1.SetAddr(ADDRPIPE1);// был 1 //addrUD);
				embMsgUDRequest_1.SetLength(3);
				embMsgUDRequest_1.SetBody(0,commandrrl);
				embMsgUDRequest_1.SetBody(1,datarrl1);
				embMsgUDRequest_1.SetBody(2,datarrl2);


				embMsgUDRequest_1.CalcCRC();

				embSerialACT155.AddMod(0xFF);
				embSerialACT155.AddMod(0xAA);
			  //	  printf("\n\r.FF.AA");
				for(i=0; i<embMsgUDRequest_1.Length()+3; i++) 
				{
			//  	  printf(".%02X",embMsgUDRequest_1.body[i]);

					switch(embMsgUDRequest_1.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgUDRequest_1.body[i]);
					}
				}
		  }
		 if(pipe == ADDRPIPE2)
		 {
		 	embMsgUDRequest_2.Init();
	   //	 	embMsgUDRequest_2.SetAddr(0);// был 1 //addrUD);
	   //	 	embMsgUDRequest_2.SetLength(1);
	   //	 	embMsgUDRequest_2.SetBody(0,0x00);
	   //	 	embMsgUDRequest_2.CalcCRC();
	   			embMsgUDRequest_2.SetAddr(ADDRPIPE2);// был 1 //addrUD);
				embMsgUDRequest_2.SetLength(3);
				embMsgUDRequest_2.SetBody(0,commandrrl);
				embMsgUDRequest_2.SetBody(1,datarrl1);
				embMsgUDRequest_2.SetBody(2,datarrl2);

		 	embSerialACT155.AddTransit(0xFF);
		 	embSerialACT155.AddTransit(0xAA);
		 	for(i=0; i<embMsgUDRequest_2.Length()+3; i++) 
				{
					switch(embMsgUDRequest_2.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgUDRequest_2.body[i]);
					}
				}
			  //	embMsgUDRequest_2.Init();

		 }

//_______________________________________________________________________
   */

 // Stephany19 = (pipe<<24) + (commandrrl<<16)+ (datarrl1<<8) +  datarrl2;
}

//_________________________________________________________________+

extern  "C" unsigned char *GetSTRPD1(unsigned long* data_len)
{
  static unsigned char BufLevel[50];
  float LEV;
 // LEV =  (unStateRRL.stateRRL.ppu1_bytes[1] >> 1) - 85;
    LEV =  unStateRRL.stateRRL.ppu1_bytes[1];
    LEV *= (float)0.5;
    LEV -= (float)85.0;




//t  sprintf((char *)&BufLevel[1],"%.1E дБм", LEV);
 //t sprintf((char *)&BufLevel[0],"%.1E дБм", LEV);
  sprintf((char *)&BufLevel[0],"%5.1f дБм", LEV);
//  *data_len = 12;
//t *data_len = 12;
 *data_len = 9;
 return ((unsigned char *)&BufLevel[0]);
 
}
extern  "C" unsigned char *GetSTRPM1(unsigned long*  data_len)
{
 static unsigned char BufLevel[50];
  float LEV;
 // LEV =  (unStateRRL.stateRRL.ppu1_bytes[3] >> 1) - 85;

 	LEV =  unStateRRL.stateRRL.ppu1_bytes[3];
    LEV *= (float)0.5;
    LEV -= (float)85.0;

  sprintf((char *)&BufLevel[0],"%5.1f дБм", LEV);
  *data_len = 9;
 return ((unsigned char *)&BufLevel[0]);

}
extern  "C" unsigned char *GetSTRPD2(unsigned long* data_len)
{
static unsigned char BufLevel[50];
  float LEV;
 // LEV =  (unStateRRL.stateRRL.ppu2_bytes[1] >> 1) - 85;

    LEV =  unStateRRL.stateRRL.ppu2_bytes[1];
    LEV *= (float)0.5;
    LEV -= (float)85.0;

  sprintf((char *)&BufLevel[0],"%5.1f дБм", LEV);
  *data_len = 9;
 return ((unsigned char *)&BufLevel[0]);

}
extern  "C" unsigned char *GetSTRPM2(unsigned long* data_len)
{
static unsigned char BufLevel[50];
  float LEV;
//  LEV =  (unStateRRL.stateRRL.ppu2_bytes[1] >> 1) - 85;

 	LEV =  unStateRRL.stateRRL.ppu2_bytes[3];
    LEV *= (float)0.5;
    LEV -= (float)85.0;

  sprintf((char *)&BufLevel[0],"%5.1f дБм", LEV);
  *data_len = 9;
 return ((unsigned char *)&BufLevel[0]);

}

extern "C" unsigned long GetCTRLPD1(void)
{
  return unStateRRL.stateRRL.ppu1_bytes[2];

}

extern "C" unsigned long GetCTRLPD2(void)
{
  return unStateRRL.stateRRL.ppu2_bytes[2];
}

extern "C" unsigned long GetFPD1(void)
{
  return unStateRRL.stateRRL.ppu1_bytes[4];
}
extern "C" unsigned long GetFPD2(void)
{
  return unStateRRL.stateRRL.ppu2_bytes[4];
}
extern "C" unsigned long GetFPM1(void)
{
  return unStateRRL.stateRRL.ppu1_bytes[5];

}
extern "C" unsigned long GetFPM2(void)
{
  return unStateRRL.stateRRL.ppu2_bytes[5];
}
extern "C" unsigned long GetLitera1(void)
{
  return unStateRRL.stateRRL.ppu1_bytes[0x14];
}
extern "C" unsigned long GetLitera2(void)
{
   return unStateRRL.stateRRL.ppu2_bytes[0x14];
}
extern "C" unsigned long GetDiap1(void)
{
   return unStateRRL.stateRRL.ppu1_bytes[0x15];
}
extern "C" unsigned long GetDiap2(void)
{
   return unStateRRL.stateRRL.ppu2_bytes[0x15];
}

extern "C" unsigned long GetConnect1(void)
{
  if(countMod>5) return 0l;
  return 1l;
}

extern "C" unsigned long GetConnect2(void)
{
  if(countTransit>5) return 0l;
  return 1l;

}

extern unsigned long Stephany19;

extern "C" void  SetCtrlPD1(unsigned long set)
{
//  Stephany19 = set;
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;

							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,2);
							embMsgUDRequest_1.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetCtrlPD1P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

//  Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,2);
							embMsgUDRequest_1.SetBody(1,(unsigned char)set);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetCtrlPD2P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

//  Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,2);
							embMsgUDRequest_2.SetBody(1,(unsigned char)set);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}



extern "C" void  SetCtrlPD2(unsigned long set)
{
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;
	  					    embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,2);
							embMsgUDRequest_2.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}


extern "C" void  SetFPD1P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

 // Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,4);
							embMsgUDRequest_1.SetBody(1,(unsigned char)set);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
}



extern "C" void  SetFPD1(unsigned long set)
{
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;

							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,4);
							embMsgUDRequest_1.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();


}

extern "C" void  SetFPD2P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

//  Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,4);
							embMsgUDRequest_2.SetBody(1,(unsigned char)set);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}




extern "C" void  SetFPD2(unsigned long set)
{
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;
  						   embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,4);
							embMsgUDRequest_2.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();

}

extern "C" void  SetFPM1P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

 // Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,5);
							embMsgUDRequest_1.SetBody(1,(unsigned char)set);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
}



extern "C" void  SetFPM1(unsigned long set)
{ 
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;					   		embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,5);
							embMsgUDRequest_1.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();

}

extern "C" void  SetFPM2P(unsigned char * pdata, unsigned long lenh)
{
 unsigned long set;

// set = len;
// set <<= 8;
 if(lenh)
 {
 lenh--;
 set = *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata++;
 }

 if(lenh)
 {
 lenh--;
 set <<= 8;
 set += *pdata;
 }

 // set &= 0xFFFFFFl;
 // set += lenh << 24;

//  Stephany19 = set;
//  unsigned long tmp = set & 0x100l;
//  tmp >>= 1;
//  tmp += set & 0x7fl;

							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,5);
							embMsgUDRequest_2.SetBody(1,(unsigned char)set);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}



extern "C" void  SetFPM2(unsigned long set)
{
  unsigned long tmp = set & 0x100l;
  tmp >>= 1;
  tmp += set & 0x7fl;

						    embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,5);
							embMsgUDRequest_2.SetBody(1,(unsigned char)tmp);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();


}


extern "C" void  SetPWEN1P(unsigned char * pdata, uint_32 lenh)
{

 							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,14);
							embMsgUDRequest_1.SetBody(1,52);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();


}

extern "C" void  SetPWEN2P(unsigned char * pdata, uint_32 lenh)
{
							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,14);
							embMsgUDRequest_2.SetBody(1,52);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}


extern "C" void  SetFRQEN1P(unsigned char * pdata, uint_32 lenh)
{
							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,14);
							embMsgUDRequest_1.SetBody(1,208);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetFRQEN2P(unsigned char * pdata, uint_32 lenh)
{	 
							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,14);
							embMsgUDRequest_2.SetBody(1,208);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  SetDSBL1P(unsigned char * pdata, uint_32 lenh)
{
							embMsgUDRequest_1.Init();
							embMsgUDRequest_1.SetAddr(0);//0x01);
							embMsgUDRequest_1.SetLength(2); //3
							embMsgUDRequest_1.SetBody(0,14);
							embMsgUDRequest_1.SetBody(1,195);
							embMsgUDRequest_1.CalcCRC();
							embMsgUDRequest_1.SetReadyToSend();


}
extern "C" void  SetDSBL2P(unsigned char * pdata, uint_32 lenh)
{

							embMsgUDRequest_2.Init();
							embMsgUDRequest_2.SetAddr(0);//0x01);
							embMsgUDRequest_2.SetLength(2); //3
							embMsgUDRequest_2.SetBody(0,14);
							embMsgUDRequest_2.SetBody(1,195);
							embMsgUDRequest_2.CalcCRC();
							embMsgUDRequest_2.SetReadyToSend();
}



