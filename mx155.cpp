#include "start.h"
#include "hello7.h"
#include "embisr.h"

//#ifndef __TINY__
//#define __TINY__
//#endif
//#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
//#define IncEmbRS232
//#define IncEmbRS485
//#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
//#define IncEmbSerialMD34AVT
////////////////////////////////////////////
//#include "longtoa.cas"
//#include "Ltoa1.c"
//#include "stdlib.h"
//#include "command.h"
//#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"
//#define OEDBASE  0x90000000

//void Enable() { asm { sti } }
//void Disable() { asm { cli } }

//void OutOED(unsigned addr, unsigned w) {	unsigned far *p = (unsigned far*)(OEDBASE+addr*2); *p = w; }
//unsigned InOED(unsigned addr) {	unsigned far *p = (unsigned far*)(OEDBASE+addr*2); return *p; }

//void ResetWatchDog()
//{
//	outport(wdtcon,0xAAAA);
//	outport(wdtcon,0x5555);
//	outportb(0x6FB,0x55);
//};

void OutOED(unsigned short addr, unsigned short w)
 {	
 // unsigned far *p = (unsigned far*)(OEDBASE+addr*2);
  unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));
//  delay_mcs(100);
  *p = w & 0xFFFF;
//  delay_mcs(100);
 }
unsigned short InOED(unsigned short addr)
 {
// unsigned far *p = (unsigned far*)(OEDBASE+addr*2);

 unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));
// delay_mcs(100);

  return *p; 
 }

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
 //	outport(wdtcon,0xAAAA);
 //	outport(wdtcon,0x5555);
 //	outportb(0x6FB,0x55);
  delay_mcs(100); //t
};



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
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CRC
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
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CRC
*/
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CRC
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






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CRC

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
  int n = Head - Tail;
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

struct Emb2Mux34
{
	unsigned char type;
	unsigned char softVer;
	unsigned char numE1;
	unsigned char e3;
	unsigned short err_e3;
	unsigned char reserv[2];
	unsigned char state_e1[16];
	unsigned char ctrl_e1[16];
};

union UnEmb2Mux34
{
	Emb2Mux34 emb2Mux34;
	unsigned char byte[40];
};

struct Emb2Mux155
{
	unsigned char type;
	unsigned char softVer;
	unsigned char stm[2];
	unsigned short stm_err[2];
	unsigned char tug3number;
	unsigned char state_e1[21];
	unsigned char ctrl_e1[21];
	unsigned char reserv[15];
};

union UnEmb2Mux155
{
	Emb2Mux155 emb2Mux155;
	unsigned char byte[64];
};

/*struct MF20CFG
{
	char header[32];
	unsigned char cardInSlot[16];
	unsigned char cardE1[32];
	unsigned char cardData[1024];
	unsigned char connectData[2048];
	unsigned char modeSync;
	unsigned char mainModeSync;
	unsigned char mainSourceSync;
	unsigned char resrModeSync;
	unsigned char resrSourceSync;
	unsigned char reserv[935];
	unsigned long crc;
};*/

struct EmbSTM1Item
{
	unsigned short tug12		: 2;
	unsigned short tug2		: 3;
	unsigned short tug3		: 2;	
	unsigned short type		: 2; // 3-VC3, 2-VC2, 1-VC12, 0-Off
	unsigned short isv		: 1; // On/Off
	unsigned short numv		: 6; // контеннация 0-Off 1..63 номера сборных контейнеров
};

struct EmbSTM1
{
  EmbSTM1Item item[63]; // 126 байт
  unsigned short state; // 128 байт
};

union UnSTM1
{
	EmbSTM1 embSTM1; // 126 байт
	unsigned char u[128]; // 128 байт
};

struct M155CFG
{
	char header[32];
	unsigned short cardInSlot[8];
	unsigned char sync[16];
	unsigned short modeSync[4];
	unsigned short linePage0[18]; // 36// Для высокуровневой коммутации коммутации 
	unsigned short linePage1[18]; // Для высокуровневой коммутации коммутации 
	unsigned short connectData[2304]; 
	unsigned char cardData[2048]; // по 256 байт
	unsigned char reserv[1404];
	unsigned long crc;
}; // 8192 байта - 4096 слов

union UnM155CFG
{
	M155CFG cfg;
	unsigned char uc[8192];
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

void SaveCommut()
{
	int i=0, j=0;
	for(j=0; j<21; j++)
	{

	}		
}

unsigned long time1=0,time2=0,time3=0,time4=0,time5=60;
unsigned char flagADUC1=0, flagADUC2=0;

void Callback0()
{
  time1++;
  time2++;
  time3++;
	time4++;
	time5++;
}

	EmbTimerCallback embTimerCallback0;

	EmbMsgBuffer rBuffEmbMsg;	
	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;

	EmbMsg embMsg232;
	EmbMsg embMsg485;
//____________________________________________________________________________RDN
	EmbMsg embMsg485E;
//____________________________________________________________________________RDN
//____________________________________________________________________________232e
	EmbMsg embMsg232E;
//____________________________________________________________________________232e


	EmbMsg embMsgWest;
	EmbMsg embMsgEast;
	EmbMsg embMsgAns;
	EmbMsg embMsgTemp;
//	EmbMsgCover embMsgCoverRequest;
	EmbMsg *embMsgRequest;

	EmbRS232 embRS232;	
	EmbRS485 embRS485;

	UL2UC ul2uc;
	UI2UC ui2uc;

	unsigned char *addrRAM;
//	unsigned short shift;
   unsigned long shift;


	unsigned short len;
	unsigned short temp_crc;
//////////////////////////////
	EmbMsg embMsg; /// ?????????
//////////////////////////////
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
    unsigned char mode5A485=0, mode5A232E=0, mode5A485E=0;
	unsigned char cycle=0;

	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned err_tr=0;
	unsigned err_md=0;

	UnEmb2TypeVer unEmb2TypeVer; 
	UnEmb2Mux155 unEmb2Mux155;
	UnEmb2NetStat unEmb2NetStat;

	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;
	long count_notRS1;
	long count_notRS2;
	long err_tmp;

   //	int short i232;
	unsigned short aI, aS, aR;

	UnSTM1 unSTM1;
	int rrr=0;
	 unsigned short	stateSTM1a;// = InOED(0x1307)&0x0005; 
	 unsigned short	stateSTM1b; //= InOED(0x1420)&0x0008; 
	 unsigned short	stateSTM2a; //= InOED(0x1B07)&0x0005;
	 unsigned short	stateSTM2b; //= InOED(0x1C20)&0x0008; 
	 unsigned long 	err1STM1; //= (InOED(0x1303)<<16)+InOED(0x1302); 
	 unsigned long 	err2STM1; //= (InOED(0x1381)<<16)+InOED(0x1382);
	 unsigned long 	err1STM2; //= (InOED(0x1B03)<<16)+InOED(0x1B02); 
	 unsigned long 	err2STM2; //= (InOED(0x1B81)<<16)+InOED(0x1B82);





void OutSPI(unsigned char spiaddr, unsigned char addr, unsigned char data)
{
	outportb(0x513, 0x02); // reset SPI
	outportb(0x514, spiaddr); 
	outportb(0x512, 0x7F&addr); // write
	outportb(0x512, data); 
	outportb(0x513, 0x01); // go
	for(int i=0; i<1000; i++);
}

unsigned char InSPI(unsigned char spiaddr, unsigned char addr)
{
	outportb(0x513, 0x02); // reset SPI
	outportb(0x514, spiaddr); 
	outportb(0x512, 0x80|addr); // read
	outportb(0x512, 0x00); 
	outportb(0x513, 0x01); // go
	for(int i=0; i<1000; i++);
	inportb(0x512);
	return inportb(0x512);
}

struct EmbMapperAddr
{
	unsigned short addr				: 7;
	unsigned short num_e1			: 5;
	unsigned short fix0x04		: 4;
};

union UnMapperAddr
{
	unsigned short us;
	EmbMapperAddr embMapperAddr;
};

struct EmbMapperTU
{
	unsigned short tug12			: 2;
	unsigned short tug2				: 3;
	unsigned short tug3				: 2;
	unsigned short fix0x00		: 9;
};

union UnMapperTU
{
	unsigned short us;
	EmbMapperTU embMapperTU;
};

void UpdateStateE1()
{
  //	UnMapperAddr uma;
	int i=0, j=0;
	unsigned char byte;
	for(i=0; i<21; i++) unEmb2Mux155.emb2Mux155.state_e1[i] = 0;
//	uma.embMapperAddr.addr = 0x08;
//	uma.embMapperAddr.fix0x04 = 0x04;
//	for(i=0; i<21; i++)
//	{
//		uma.embMapperAddr.num_e1=i+1;
//		unEmb2Mux155.emb2Mux155.ctrl_e1[i] = 	InOED(uma.us);
//	}
	byte = InSPI(0x08,0x64); // AIS по первому LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[0] |= 1; // AIS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[1] |= 1; // AIS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[2] |= 1; // AIS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[3] |= 1; // AIS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[4] |= 1; // AIS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[5] |= 1; // AIS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[6] |= 1; // AIS
	byte = InSPI(0x09,0x64); // AIS по второму LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[7] |= 1; // AIS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[8] |= 1; // AIS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[9] |= 1; // AIS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[10] |= 1; // AIS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[11] |= 1; // AIS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[12] |= 1; // AIS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[13] |= 1; // AIS
	byte = InSPI(0x0A,0x64); // AIS по третьему LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[14] |= 1; // AIS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[15] |= 1; // AIS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[16] |= 1; // AIS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[17] |= 1; // AIS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[18] |= 1; // AIS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[19] |= 1; // AIS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[20] |= 1; // AIS

	byte = InSPI(0x08,0x10); // AIS по первому LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[0] |= 2; // LOS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[1] |= 2; // LOS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[2] |= 2; // LOS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[3] |= 2; // LOS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[4] |= 2; // LOS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[5] |= 2; // LOS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[6] |= 2; // LOS
	byte = InSPI(0x09,0x10); // AIS по второму LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[7] |= 2; // LOS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[8] |= 2; // LOS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[9] |= 2; // LOS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[10] |= 2; // LOS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[11] |= 2; // LOS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[12] |= 2; // LOS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[13] |= 2; // LOS
	byte = InSPI(0x0A,0x10); // AIS по третьему LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[14] |= 2; // LOS
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[15] |= 2; // LOS
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[16] |= 2; // LOS
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[17] |= 2; // LOS
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[18] |= 2; // LOS
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[19] |= 2; // LOS
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[20] |= 2; // LOS

	byte = InSPI(0x08,0x48); // AIS по первому LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[0] |= 4; // DRV
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[1] |= 4; // DRV
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[2] |= 4; // DRV
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[3] |= 4; // DRV
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[4] |= 4; // DRV
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[5] |= 4; // DRV
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[6] |= 4; // DRV
	byte = InSPI(0x09,0x48); // AIS по второму LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[7] |= 4; // DRV
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[8] |= 4; // DRV
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[9] |= 4; // DRV
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[10] |= 4; // DRV
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[11] |= 4; // DRV
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[12] |= 4; // DRV
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[13] |= 4; // DRV
	byte = InSPI(0x0A,0x48); // AIS по третьему LIU
	if(byte&0x80) unEmb2Mux155.emb2Mux155.state_e1[14] |= 4; // DRV
	if(byte&0x40) unEmb2Mux155.emb2Mux155.state_e1[15] |= 4; // DRV
	if(byte&0x20) unEmb2Mux155.emb2Mux155.state_e1[16] |= 4; // DRV
	if(byte&0x10) unEmb2Mux155.emb2Mux155.state_e1[17] |= 4; // DRV
	if(byte&0x08) unEmb2Mux155.emb2Mux155.state_e1[18] |= 4; // DRV
	if(byte&0x04) unEmb2Mux155.emb2Mux155.state_e1[19] |= 4; // DRV
	if(byte&0x02) unEmb2Mux155.emb2Mux155.state_e1[20] |= 4; // DRV

	unEmb2Mux155.emb2Mux155.stm[0] = inportb(0x518);
	unEmb2Mux155.emb2Mux155.stm[1] = inportb(0x519);

  unEmb2Mux155.emb2Mux155.stm_err[0]=0;
  unEmb2Mux155.emb2Mux155.stm_err[1]=0;
/*
/// Дописать!!!
		outportb(0x513,0x02); 
		outportb(0x514,0x09); // номер LIU 09, 0A, 0B
// View
		outportb(0x512,0x80|0x64); // AIS
		outportb(0x512,0x80|0x10); // LOS
		outportb(0x512,0x80|0x48); // DRV
// Ctrl
		outportb(0x512,0x80|0x40); // Near Lopp
		outportb(0x512,0x80|0x20); // Far Loop
		outportb(0x512,0x80|0x60); // AIS Out
		outportb(0x512,0x80|0x24); // DRV Off

		outportb(0x513,0x02); 
*/
}

struct EmbTUGAddr
{
	unsigned short fix0x01		: 1;
	unsigned short tu12				: 2;
	unsigned short tug2				: 3;
	unsigned short tug3				: 2;
	unsigned short numAB			: 4; // 1 - канал А, 5 - канал В
	unsigned short fix0x03		: 4;
};

union UnTUGAddr
{
	unsigned short us;
	EmbTUGAddr embTUGAddr;
};

void UpdateSTM1Map()
{
	UnTUGAddr uta;
	int j=0,i=0,k=0,m=0;
	uta.embTUGAddr.fix0x01=0x01;
	uta.embTUGAddr.fix0x03=0x03;
	uta.embTUGAddr.numAB = 1; // Пока только канал А
	for(i=0; i<3; i++)
	{
		for(j=0; j<7; j++)
		{
			for(k=0; k<3; k++)
			{
				uta.embTUGAddr.tug3 = unSTM1.embSTM1.item[m].tug3 = i;
				uta.embTUGAddr.tug2 = unSTM1.embSTM1.item[m].tug2 = j;
				uta.embTUGAddr.tu12 = unSTM1.embSTM1.item[m].tug12 = k;

				unSTM1.embSTM1.item[m].isv = 1; 
				unSTM1.embSTM1.item[m].type = 1;
				
				unSTM1.embSTM1.item[m].numv = InOED(uta.us);	
				m++;
			}
		}
	}
}


void InitMux155()
{
	unsigned long delay;
	unsigned i;
	// Инициализация ретаймера
	outportb(0x515, 0x0D); // Вкл ретаймер
	outportb(0x51A, 0x01); // Вкл оптику А
	outportb(0x51B, 0x01); // Вкл оптику В

	OutSPI(0x0B, 0x1F, 0x02);
	OutSPI(0x0B, 0x1E, 0x05);
	OutSPI(0x0B, 0x23, 0x07);
	
	outportb(0x51F, 0x08); // REF 0 0x00 - внутренний генератор
	outportb(0x520, 0x09); // REF 1 0x09 - внутренний генератор
	outportb(0x521, 0x0D); // REF 2 0x0D - внутренний генератор

	delay = time1 + 3;	while(delay<time1) ResetWatchDog();

	// Конфигурация LIU
	/// !!! Переделываем !!!
	OutSPI(0x08, 0x28, 0xFF);
	OutSPI(0x09, 0x28, 0xFF);
	OutSPI(0x0A, 0x28, 0xFF);
	for(i=0; i<5; i++);
	// Jatt Tx, auto AIS if LOS
	OutSPI(0x08, 0x78, 0x82);
	OutSPI(0x09, 0x78, 0x82);
	OutSPI(0x0A, 0x78, 0x82);
	// off ch8
	OutSPI(0x08, 0x24, 0x01);
	OutSPI(0x09, 0x24, 0x01);
	OutSPI(0x0A, 0x24, 0x01);

	// Конфигурация OED 	
	// Reset OED
	OutOED(0x0001, 0x001B);	delay = time1 + 10;	while(delay<time1) ResetWatchDog(); // 0x00FF
	OutOED(0x0001, 0x0000);
	// Reset CDR
	OutOED(0x0006, 0x0080); delay = time1 + 10;	while(delay<time1) ResetWatchDog();
	OutOED(0x0006, 0x0781);
	// Инициализация STM1 mode - MCR reg
	OutOED(0x0002, 0x0018); // en h12h4, 19mhz
	// Инициализация CDR CLK
	OutOED(0x0007, 0x1E0C); delay = time1 + 10;	while(delay<time1) ResetWatchDog();
	OutOED(0x0007, 0x1808); // 0x1808 = 155pclk, 0x1E08 = 155pclk loop

	OutOED(0x1001, 0x0000); // 0x0000 = POH loop - off, 0x00FF = POH loop - on
	OutOED(0x1020, 0x0002); // SOHCTL - SOH - интерфейс
	// RSOH
	// Descrambler on, no AIS if MS-TIM, one err in byte
	OutOED(0x1300, 0x0004); // 0x0000 = Descrambler A on, 0x0001 = Descrambler A off
	OutOED(0x1B00, 0x0004); // 0x0000 = Descrambler B on, 0x0001 = Descrambler B off
	// RRSTMC -- TIM J0 config p.124
	OutOED(0x1301, 0x0005); // 
	OutOED(0x1B01, 0x0005); // 
	// TRSCTL p. 128 on Scrambler, no MSAIS insert, 16byte J0 from buffer, Z0 = 55 
	OutOED(0x1340, 0x0080); // 0x0000 = Scrambler A on, 0x0001 = Scrambler A off
	OutOED(0x1B40, 0x0080); // 0x0000 = Scrambler B on, 0x0001 = Scrambler B off
	// TRSd1d2 p.129
	OutOED(0x1342, 0x7E7E); 
	OutOED(0x1B42, 0x7E7E); 
	// TRSd3 p.129
	OutOED(0x1343, 0x007E); 
	OutOED(0x1B43, 0x007E); 
	// TSTOH p.129
	OutOED(0x1345, 0x0000); 
	OutOED(0x1B45, 0x0000); 
	// DEG EXC 10 ms
	OutOED(0x1385, 0x000A); 
	OutOED(0x1B85, 0x000A); 
	OutOED(0x1386, 0x0000); 
	OutOED(0x1B86, 0x0000); 
	// EXC removal 10 ms
	OutOED(0x1387, 0x000A); 
	OutOED(0x1B87, 0x000A); 
	OutOED(0x1388, 0x0000); 
	OutOED(0x1B88, 0x0000); 
ResetWatchDog();
	// EXCdt removal 10 ms
	OutOED(0x1389, 0x003C); 
	OutOED(0x1B89, 0x003C); 
	// excct
	OutOED(0x138A, 0x000F); 
	OutOED(0x1B8A, 0x000F); 
	// DEGAPDL 1s
	OutOED(0x138B, 0x03E8); 
	OutOED(0x1B8B, 0x03E8); 
	// DEGAPDH 1s
	OutOED(0x138C, 0x0000); 
	OutOED(0x1B8C, 0x0000); 
	// DEGAPRL 1s
	OutOED(0x138D, 0x03E8); 
	OutOED(0x1B8D, 0x03E8); 
	// DEGAPRH 1s
	OutOED(0x138E, 0x0000); 
	OutOED(0x1B8E, 0x0000); 
	// DEDT 1500 OF 8000 IN 1S
	OutOED(0x138F, 0x05DC); 
	OutOED(0x1B8F, 0x05DC); 
	// DEDT 150 OF 8000 IN 1S
	OutOED(0x1390, 0x0096); 
	OutOED(0x1B90, 0x0096); 
	// RMSCTL EXC DEG enable, word mode, ms-ais ms-rdi 5 frame p.131
	OutOED(0x1380, 0x006E); 
	OutOED(0x1B80, 0x006E); 
	// RAPC off ms protection switch p.139
	OutOED(0x139C, 0x0000); 
	OutOED(0x1B9C, 0x0000); 
ResetWatchDog();
	// TMSS1 reg
	OutOED(0x13C9, 0x0000); 
	OutOED(0x1BC9, 0x0000); 
	// TMSCTL auto rei, auto rdi, S1 from reg p.141
	OutOED(0x13C0, 0x00E0); 
	OutOED(0x1BC0, 0x00E0); 
	// TMSRDI rdi set if LOF, LOS, MS-AIS p.143
	OutOED(0x13C1, 0x000E); 
	OutOED(0x1BC1, 0x000E); 
	// TRS d4d5
	OutOED(0x13C4, 0x7E7E); 
	OutOED(0x1BC4, 0x7E7E); 
	// TRS d6d7
	OutOED(0x13C5, 0x7E7E); 
	OutOED(0x1BC5, 0x7E7E); 
	// TRS d8d9
	OutOED(0x13C6, 0x7E7E); 
	OutOED(0x1BC6, 0x7E7E); 
	// TRS d10d11
	OutOED(0x13C7, 0x007E); 
	OutOED(0x1BC7, 0x007E); 
	// TRS d12
	OutOED(0x1348, 0x007E); 
	OutOED(0x1B48, 0x007E); 
// reg PP config VC4
	// RPCTL p.146 BIPword
	OutOED(0x1400, 0x002a);
	OutOED(0x1C00, 0x002a);
	// RAIS p.147 AIS if LOP, not AIS if EXC DEG PSLM PTIM
	OutOED(0x1401, 0x0081);
	OutOED(0x1C01, 0x0081);
	// RPTMC p.150 J1 TIM - 16, not AIS if EXC DEG PSLM PTIM 
	OutOED(0x140B, 0x0004);
	OutOED(0x1C0B, 0x0004);
ResetWatchDog();	
	// RPEC2 p.151 c1 = c2
	OutOED(0x140D, 0x0002);
	OutOED(0x1C0D, 0x0002);
	// TPRDI p.151 E RDI - en RDI if LOF, LOS, LOP, MSAIS
	OutOED(0x1411, 0x003F);
	OutOED(0x1C11, 0x003F);
	// RPGCTL p.152 en AU AIS if FIFO over-under-flow
	OutOED(0x1412, 0x0001);
	OutOED(0x1C12, 0x0001);
	// TPCTL p.158 VC poh tx ctrl
	OutOED(0x1480, 0xF770);
	OutOED(0x1C80, 0xF770);
	// TPC2 p.160 C2 TUG struct
	OutOED(0x1482, 0x0002);
	OutOED(0x1C82, 0x0002);
	// TPF2 p.160 
	OutOED(0x1484, 0x0000);
	OutOED(0x1C84, 0x0000);
	// TPF3K3 p.160 
	OutOED(0x1485, 0x0000);
	OutOED(0x1C85, 0x0000);

//	OutOED(0x139C, 0x0010);  // Включение резервирования
ResetWatchDog();
// PP - config TUG
	// RESET TUG3 proc stupprst p.166
	OutOED(0x3100, 0x0007); 
	OutOED(0x3200, 0x0007); 
	OutOED(0x3300, 0x0007); 
	OutOED(0x3400, 0x0007); 
	OutOED(0x3500, 0x0007); 
	OutOED(0x3600, 0x0007); 
	OutOED(0x3700, 0x0007);
	OutOED(0x3800, 0x0007);
ResetWatchDog();
	OutOED(0x3100, 0x0000); 
	OutOED(0x3200, 0x0000); 
	OutOED(0x3300, 0x0000); 
	OutOED(0x3400, 0x0000); 
	OutOED(0x3500, 0x0000); 
	OutOED(0x3600, 0x0000); 
	OutOED(0x3700, 0x0000);
	OutOED(0x3800, 0x0000);
ResetWatchDog();
// STUPPMCR p.167 all TUG3-TUG2, no bypass, no AIS
	// Направление А
	OutOED(0x3101, 0x0020); // первый STM-1
	OutOED(0x3201, 0x0020); // второй STM-1 не исп
	OutOED(0x3301, 0x0020); // третий STM-1 не исп
	OutOED(0x3401, 0x0020); // четвертый STM-1 не исп
	// Направление В
	OutOED(0x3501, 0x0020); // первый STM-1
	OutOED(0x3601, 0x0020); // второй STM-1 не исп
	OutOED(0x3701, 0x0020);	// третий STM-1 не исп
	OutOED(0x3801, 0x0020); // четвертый STM-1 не исп
/// Синхронизация внутренняя по умолчанию
	outportb(0x515, 0x00); 
	outportb(0x515, 0x05); 
	outportb(0x515, 0x0D); // D
	OutSPI(0x0B, 0x1F, 0x02);
	outportb(0x51F, 0x00); 
	outportb(0x520, 0x00); 
	outportb(0x521, 0x00); 
/*// БЫЛО !!!
	OutOED(0x1401, 0x0000); // RAIS
	OutOED(0x140D, 0x0002); // RPEC2
	OutOED(0x1480, 0x4170); // TPCTL
	OutOED(0x1482, 0x0002); // TPC2

	OutOED(0x1C00, 0x0000);
	OutOED(0x1C01, 0x0000); // RAIS
	OutOED(0x1C0D, 0x0002); // RPEC2
	OutOED(0x1C80, 0x4170); // TPCTL
	OutOED(0x1C82, 0x0002); // TPC2
// Конфигурация OED PP для STM4
	// Направление А
	// Если бит 8 в "1", то поток STM1 проходит на сквозь без разбивки и изменений "by pass"
	OutOED(0x3101, 0x0020); // TU12 - 0 STM1 (для TU12 последние 3 бита в "0" по одному на каждый трибутарный поток)
	OutOED(0x3201, 0x0027); // TUG3 - 1 STM1 (для TU3 последние 3 бита в "1" по одному на каждый трибутарный поток)
	OutOED(0x3301, 0x0027); // TUG3 - 2 STM1 
	OutOED(0x3401, 0x0027); // TUG3 - 3 STM1 
	// Направление В
	OutOED(0x3501, 0x0020); // TU12 - 0 STM1 (для TU12 последние 3 бита в "0" по одному на каждый трибутарный поток)
	OutOED(0x3601, 0x0027); // TUG3 - 1 STM1 (для TU3 последние 3 бита в "1" по одному на каждый трибутарный поток)
	OutOED(0x3701, 0x0027); // TUG3 - 2 STM1 
	OutOED(0x3801, 0x0027); // TUG3 - 3 STM1 
*/
}

struct EmbCommutatorAdrr
{
  unsigned short fix0x07		: 4;
  unsigned short dist_line	: 5;
  unsigned short page				: 1;
  unsigned short num_e1			: 6;
};

struct EmbCommutatorData
{
  unsigned short source_line: 5;
  unsigned short source_e1	: 6;
  unsigned short idle				: 1;
  unsigned short fix0x00		: 4;
};

struct EmbMapperData
{
	unsigned short tug12_a		: 2;
	unsigned short tug2_a			: 3;
	unsigned short tug3_a			: 2;
	unsigned short fix0x00_a	: 1;
	unsigned short tug12_b		: 2;
	unsigned short tug2_b			: 3;
	unsigned short tug3_b			: 2;
	unsigned short fix0x00_b	: 1;
};

void UpdateMapper()
{
	unsigned long delay;
	unsigned i, j, k=0;
	UnMapperAddr uma;
	UnMapperTU umt;
/// Сброс и установка неизвестно каких счетчиков
	OutOED(0x4000, 0x0FFF);
	OutOED(0x4001, 0x0FFF); 
	delay = time1 + 3;	while(delay<time1) ResetWatchDog();
	OutOED(0x4000, 0x0000);
	OutOED(0x4001, 0x0000);
	// set err tresholds 40 ms p. 177-180
	OutOED(0x4002, 0x0050);
	// 10-3, half of 80 subrframes
	OutOED(0x4003, 0x0028);
	// 40 ms
	OutOED(0x4004, 0x0050);
	// 10-4
	OutOED(0x4005, 0x0008);
	// 4 sec
	OutOED(0x4006, 0x1F40);
	OutOED(0x4007, 0x0000);
	// 1 in 100 of 8000 suprframes
	OutOED(0x4008, 0x0050);
	// 4 sec
	OutOED(0x4009, 0x1F40);
	OutOED(0x400A, 0x0000);
	// 1 in 100 of 8000 suprframes
	OutOED(0x400B, 0x0008);	delay = time1 + 3;	while(delay<time1) ResetWatchDog();

	umt.embMapperTU.fix0x00=0x00;
	umt.embMapperTU.tug3=1;

	uma.embMapperAddr.fix0x04 = 0x04;
	uma.embMapperAddr.addr=0x00;
	uma.embMapperAddr.num_e1=0;
// КОнфигурация маппера
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			umt.embMapperTU.tug2=i+1;
			umt.embMapperTU.tug12=j+1;
			uma.embMapperAddr.num_e1++;
			OutOED(uma.us, umt.us*256 + umt.us);
			ResetWatchDog();
		}
	}

	for(i=0; i<21; i++)
	{
		uma.embMapperAddr.num_e1 = i + 1;
		uma.embMapperAddr.addr=0x01; OutOED(uma.us, 0x00C1); // CCR p.183 loop & AIS
		uma.embMapperAddr.addr=0x02; OutOED(uma.us, 0x0001); // PPSCR SNCP force master
		uma.embMapperAddr.addr=0x04; OutOED(uma.us, 0x0000); // REVCFG retimm off 512 fifo p.186
		uma.embMapperAddr.addr=0x40; OutOED(uma.us, 0x0003); // TANCFGA POH tx cfg E1 auto RDI if AIS LOP p.195
		uma.embMapperAddr.addr=0x41; OutOED(uma.us, 0x0003); // TANCFGB
		uma.embMapperAddr.addr=0x42; OutOED(uma.us, 0x0004); // path label 010 asinc E1 tv5k4lina
		uma.embMapperAddr.addr=0x44; OutOED(uma.us, 0x0004); // path label 010 asinc E1 tv5k4linb
		uma.embMapperAddr.addr=0x60; OutOED(uma.us, 0x0042); // PRBSCFG analis on, PRBS, 127, 0.25
		ResetWatchDog();
	}

	OutOED(0x6000, 0x0003); for(i=0; i<200; i++);
	// HLXCR 0-17 P.201
	OutOED(0x6002, 0x0000); // line 0 LOW order
	OutOED(0x6003, 0x0060); // line 1 idle
	OutOED(0x6004, 0x0060); // line 2 idle
	OutOED(0x6005, 0x0060); // line 3 idle
	OutOED(0x6006, 0x0000); // line 4 LOW order // Было 4
	OutOED(0x6007, 0x0060); // line 5 idle
	OutOED(0x6008, 0x0060); // line 6 idle
	OutOED(0x6009, 0x0060); // line 7 idle
	OutOED(0x600A, 0x0060); // line 8 idle
	OutOED(0x600B, 0x0060); // line 9 idle
	OutOED(0x600C, 0x0060); // line 10 idle
	OutOED(0x600D, 0x0060); // line 11 idle
	OutOED(0x600E, 0x0060); // line 12 idle
	OutOED(0x600F, 0x0060); // line 13 idle
	OutOED(0x6010, 0x0060); // line 14 idle
	OutOED(0x6011, 0x0060); // line 15 idle
	OutOED(0x6012, 0x0000); // line 16 LOW order
	OutOED(0x6013, 0x0000); // line 17 LOW order
	// ctrl mem init IDLE code
	OutOED(0x6000, 0x0001); for(i=0; i<200; i++);
	OutOED(0x6042, 0x0000); // line 0 LOW order
	OutOED(0x6043, 0x0060); // line 1 idle
	OutOED(0x6044, 0x0060); // line 2 idle
	OutOED(0x6045, 0x0060); // line 3 idle
	OutOED(0x6046, 0x0000); // line 4 LOW order // Было 4
	OutOED(0x6047, 0x0060); // line 5 idle
	OutOED(0x6048, 0x0060); // line 6 idle
	OutOED(0x6049, 0x0060); // line 7 idle
	OutOED(0x604A, 0x0060); // line 8 idle
	OutOED(0x604B, 0x0060); // line 9 idle
	OutOED(0x604C, 0x0060); // line 10 idle
	OutOED(0x604D, 0x0060); // line 11 idle
	OutOED(0x604E, 0x0060); // line 12 idle
	OutOED(0x604F, 0x0060); // line 13 idle
	OutOED(0x6050, 0x0060); // line 14 idle
	OutOED(0x6051, 0x0060); // line 15 idle
	OutOED(0x6052, 0x0000); // line 16 LOW order
	OutOED(0x6053, 0x0000); // line 17 LOW order

	ResetWatchDog();
	OutOED(0x6000, 0x0003); for(i=0; i<200; i++);// Set page 1
	for(i=0; i<18; i++)
	{
		for(j=0; j<64; j++)
		{
			OutOED(0x7000+128*i+j, 0x0820);
			ResetWatchDog();
		}
	}
	OutOED(0x7000, 0x0000);
	OutOED(0x7200, 0x0004);
	OutOED(0x6000, 0x0001); for(i=0; i<200; i++); // Set page 0

	for(i=0; i<18; i++)
	{
		for(j=0; j<64; j++)
		{
			OutOED(0x7040+128*i+j, 0x0820);
			ResetWatchDog();
		}
	}
	OutOED(0x7040, 0x0000);
	OutOED(0x7240, 0x0004);
	OutOED(0x6000, 0x0003); for(i=0; i<200; i++);// Set page 1
}
//_________________________________________add1
/*
void SetHLX()
{
 //printf("\n\r SetHLX");

  //	unsigned long delay;
  //	unsigned short pos;
	unsigned i;//, j;
  //	UnMapperAddr uma;
	// ctrl mem line 0 c линии 16
	ResetWatchDog();
	UnM155CFG *unM155CFG = (UnM155CFG *)NVRAM_BASE;

	OutOED(0x6000, 0x0003); for(i=0; i<200; i++);// Set page 1
	
	if(unM155CFG->cfg.sync[0]==0)
	{
		outportb(0x515, 0x00); 
		outportb(0x515, 0x05); 
		outportb(0x515, 0x0D); 
		outportb(0x51E, 1);
		OutSPI(0x0B, 0x1F, 0x02);
		outportb(0x51F, 0x00);
		outportb(0x520, 0x00);
		outportb(0x521, 0x00);
	}
	else
	{

		outportb(0x515, 0x00); 
		outportb(0x515, 0x07); 
		outportb(0x515, 0x0F); 
		outportb(0x51E, 1);
		
		OutSPI(0x0B, 0x1F, 0x03);
	
		switch(unM155CFG->cfg.sync[0])
		{
		case 0:	outportb(0x51F, 0x00); break;
		case 1:	outportb(0x51F, 0x08); break;
		case 2:	outportb(0x51F, 0x09); break;
		case 3:	outportb(0x51F, 0x0A); break;
		case 4:	outportb(0x51F, 0x0D); break;
		}
		switch(unM155CFG->cfg.sync[1])
		{
		case 0:	outportb(0x520, 0x00); break;
		case 1:	outportb(0x520, 0x08); break;
		case 2:	outportb(0x520, 0x09); break;
		case 3:	outportb(0x520, 0x0A); break;
		case 4:	outportb(0x520, 0x0D); break;
		}
		
		switch(unM155CFG->cfg.sync[2])
		{
		case 0:	outportb(0x521, 0x00); break;
		case 1:	outportb(0x521, 0x08); break;
		case 2:	outportb(0x521, 0x09); break;
		case 3:	outportb(0x521, 0x0A); break;
		case 4:	outportb(0x521, 0x0D); break;
		}
	}

	for(i=0; i<2304; i++)
	{
		OutOED(0x7000+i, unM155CFG->cfg.connectData[i]);
		//delay_mcs(1); //t
 //		printf(".%04X", unM155CFG->cfg.connectData[i]);
	}

	OutOED(0x7000, 0x0000); // POH VC4 = 0
	OutOED(0x7200, 0x0004);
	OutOED(0x7800, 0x0000);
	OutOED(0x7880, 0x0004);

	if(InOED(0x6001)&0x0001) OutOED(0x6000, 0x0001); // страница 0
	else OutOED(0x6000, 0x0003); // страница 1
}
*/
//__________________________________________________________________add1
void SetHLX()
{
   //	unsigned long delay;
  //	unsigned short pos;
	unsigned i; //, j;
	UnMapperAddr uma;
	UnMapperTU umt;
	// ctrl mem line 0 c линии 16
  //	ResetWatchDog();
 //	UnM155CFG  *unM155CFG = (UnM155CFG *)0x80000000;
   UnM155CFG  *unM155CFG = (UnM155CFG *)NVRAM_BASE;

	OutOED(0x6000, 0x0003); for(i=0; i<200; i++);// Set page 1
	
	if(unM155CFG->cfg.sync[0]==0)
	{
		outportb(0x515, 0x00); 
		outportb(0x515, 0x05); 
		outportb(0x515, 0x0D); 
		outportb(0x51E, 1);
		OutSPI(0x0B, 0x1F, 0x02);
		outportb(0x51F, 0x00);
		outportb(0x520, 0x00);
		outportb(0x521, 0x00);
	}
	else
	{

		outportb(0x515, 0x00); 
		outportb(0x515, 0x07); 
		outportb(0x515, 0x0F); 
		outportb(0x51E, 1);
		
		OutSPI(0x0B, 0x1F, 0x03);
	
		switch(unM155CFG->cfg.sync[0])
		{
		case 0:	outportb(0x51F, 0x00); break;
		case 1:	outportb(0x51F, 0x08); break;
		case 2:	outportb(0x51F, 0x09); break;
		case 3:	outportb(0x51F, 0x0A); break;
		case 4:	outportb(0x51F, 0x0D); break;
		}
		switch(unM155CFG->cfg.sync[1])
		{
		case 0:	outportb(0x520, 0x00); break;
		case 1:	outportb(0x520, 0x08); break;
		case 2:	outportb(0x520, 0x09); break;
		case 3:	outportb(0x520, 0x0A); break;
		case 4:	outportb(0x520, 0x0D); break;
		}
		
		switch(unM155CFG->cfg.sync[2])
		{
		case 0:	outportb(0x521, 0x00); break;
		case 1:	outportb(0x521, 0x08); break;
		case 2:	outportb(0x521, 0x09); break;
		case 3:	outportb(0x521, 0x0A); break;
		case 4:	outportb(0x521, 0x0D); break;
		}
	}

	for(i=0; i<2304; i++)
	{
		OutOED(0x7000+i, unM155CFG->cfg.connectData[i]);
	}

	umt.embMapperTU.fix0x00=0x00;
	umt.embMapperTU.tug3=1;

	uma.embMapperAddr.fix0x04 = 0x04;
	uma.embMapperAddr.addr=0x00;
	uma.embMapperAddr.num_e1=0;
// КОнфигурация маппера
	for(i=0; i<21; i++)
	{
		uma.embMapperAddr.num_e1 = i + 1;
		uma.embMapperAddr.addr=0x02; OutOED(uma.us, unM155CFG->cfg.cardData[i*24]); // PPSCR SNCP force master
	}


	OutOED(0x7000, 0x0000); // POH VC4 = 0
	OutOED(0x7200, 0x0004);
	OutOED(0x7800, 0x0000);
	OutOED(0x7880, 0x0004);

	if(InOED(0x6001)&0x0001) OutOED(0x6000, 0x0001); // страница 0
	else OutOED(0x6000, 0x0003); // страница 1
}


void SwitchMapper()
{
  //	unsigned long delay;
	unsigned short pos;
	unsigned i, j;
 //	UnMapperAddr uma;
	// ctrl mem line 0 c линии 16
	OutOED(0x7000, 0x0000); // POH VC4 = 0
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 1; // 1 = tug3
//			OutOED(0x7000+pos, 0x0820);
			OutOED(0x7000+pos, 32 * pos + 16);
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 2; // 2 = tug3
//			OutOED(0x7000+pos, 32 * (pos-1) + 16); // IDLE
			OutOED(0x7000+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 3; // 3 = tug3
			OutOED(0x7000+pos, 0x0820); // IDLE
		}
	}
	// ctrl mem line 4 
	OutOED(0x7200, 0x0004); // POH VC4 = 4
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 1; // 1 = tug3
//			OutOED(0x7200+pos,0x0820 );
			OutOED(0x7200+pos, 32 * pos + 16);
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 2; // 2 = tug3
//			OutOED(0x7200+pos, 32 * (pos-1) + 17); // IDLE
			OutOED(0x7200+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 3; // 3 = tug3
			OutOED(0x7200+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	// ctrl mem line 16 
	OutOED(0x7800, 0x0000); // POH VC4 = 0
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 1; // 1 = tug3
//			OutOED(0x7800+pos, 32 * (pos+1) );
			OutOED(0x7800+pos, 32 * pos );
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 2; // 2 = tug3
			OutOED(0x7800+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 3; // 3 = tug3
			OutOED(0x7800+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	// ctrl mem line 17 
	OutOED(0x7880, 0x0004); // POH VC4 = 4
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 1; // 1 = tug3
//			OutOED(0x7880+pos, 32 * (pos+1) + 4);
			OutOED(0x7880+pos, 32 * pos);
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 2; // 2 = tug3
			OutOED(0x7880+pos, 0x0820); // IDLE
		}
	}
	ResetWatchDog();
	for(i=0; i<7; i++)
	{
		for(j=0; j<3; j++)
		{
			pos = 21 * j + 3 * i + 3; // 3 = tug3
			OutOED(0x7880+pos, 0x0820); // IDLE
		}
	}
	OutOED(0x6000, 0x0001); for(i=0; i<200; i++);
}
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////

//void main()
//{

extern "C" void Init_MPC155(void)
{
//???????????????????  CSE3 - need init!!!!!!!!!!!!!!!!!!!!!!!!!!!! need view shematics
//_______________________________________________________________
 EmbInit(); //my
 AsciiInit();
 time1=0;time2=0;time3=0;time4=0;time5=60;
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
 HighID=0; countSend=0; countRecv=0;
 time3highID=0;
 mode5A=0; mode5AWest=0; mode5AEast=0; 
 mode5A485=0; mode5A232E=0; mode5A485E=0; 
 cycle=0;
 ttbb=0;
 mtbb=0;
 count_tr=0;
 count_md=0;
 err_tr=0;
 err_md=0;
 rrr=0;

 stateSTM1a = 0; 
 stateSTM1b = 0; 
 stateSTM2a = 0;
 stateSTM2b = 0; 
 err1STM1 = 0; 
 err2STM1 = 0;
 err1STM2 = 0; 
 err2STM2 = 0;
 
//_______________________________________________________________
	rBuffEmbMsg.Init();

 //	ResetWatchDog();

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
	}

	for(i=0; i<9; i++) powerInFar[i]=0;

  //	int rrr=0;

	unEmb2TypeVer.emb2TypeVer.type       = 0x0506;
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER; //232 <-> 888
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = 0;//SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = 0;//SelfVer2();
	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
   unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = read_xil_char(1);
   unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = read_xil_char(2);

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
//	while(time5<12); // 10 ms
//	outportb(0x5B7, 0x00);
////////////////////////////////////////////////


 //	Enable(); // Разрешаем все прерывания
   if(CheckDoneShort())
   {
	InitMux155(); ResetWatchDog();
	UpdateMapper(); ResetWatchDog();
	SwitchMapper(); ResetWatchDog();
	SetHLX(); 
   //	ResetWatchDog();
   }


	embMsgTemp.Init();
	outportb(0x51E, 0);

//	for(i=0; i<2000; i++) ResetWatchDog();

  }
//while(1)
//	{

	 extern "C" void MPC155(void)
{

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

  // static unsigned long keepshift, trysend;

  //		rrr++;
//		if(!(rrr%200)) outportb(0x51E, !(inportb(0x51E)));
  //		ResetWatchDog();
/*
	unsigned du=0;

	du = InOED(0x7001);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = (du>>8)&0xFF;
	unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = du&0xFF;
	du = InOED(0x7041);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = (du>>8)&0xFF;
	unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = du&0xFF;
	du = InOED(0x7201);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = (du>>8)&0xFF;
	unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = du&0xFF;
	du = InOED(0x7241);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = (du>>8)&0xFF;
	unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = du&0xFF;
*/
 //_________________________________________add1
 if(time1old-time1>1000)
	{
		time1old=time1;
		stateSTM1a = InOED(0x1307)&0x0005; 
		stateSTM1b = InOED(0x1420)&0x0008; 
		stateSTM2a = InOED(0x1B07)&0x0005;
		stateSTM2b = InOED(0x1C20)&0x0008; 
		err1STM1 = (InOED(0x1303)<<16)+InOED(0x1302); 
		err2STM1 = (InOED(0x1381)<<16)+InOED(0x1382);
		err1STM2 = (InOED(0x1B03)<<16)+InOED(0x1B02); 
		err2STM2 = (InOED(0x1B81)<<16)+InOED(0x1B82);

		unEmb2Mux155.emb2Mux155.stm_err[0]+=err1STM1;
		unEmb2Mux155.emb2Mux155.stm_err[1]+=err1STM2;

		unsigned char b1 = 0; 
		unsigned char b2 = 0; 

		if(stateSTM1a||stateSTM1b) b1=b1|0x01;
		if(stateSTM2a||stateSTM2b) b2=b2|0x01;

		if(err1STM1||err2STM1) b1=b1|0x02;
		if(err1STM2||err2STM2) b2=b2|0x02;

		outportb(0x51C,b1);
		outportb(0x51D,b2);
	}

 //_________________________________________add1


	rrr++;
	if((rrr > 1000))
		{
			rrr = 0;	
			outportb(0x51E, !(inportb(0x51E)));
			/*
			testreg = InOED(0x0002);
			printf("\r 0x2: %X", testreg);
			testreg = InOED(0x0003);
			printf("\r 0x3: %X", testreg);
			testreg = InOED(0x0006);
			printf("\r 0x6: %X", testreg);
			testreg = InOED(0x0007);
			printf("\r 0x7: %X", testreg);
			testreg = InOED(0x0009);
			printf("\r 0x9: %X", testreg);
			*/
		  //	OutOED(0x1001, 0x0f);



		}



/////////  Плата интерфейсов  ///////////
 //	unsigned temp1, temp2;

/*
	unEmb2Mux34.emb2Mux34.numE1 = 16;
	unEmb2Mux34.emb2Mux34.e3 = inportb(0x522);
	unEmb2Mux34.emb2Mux34.err_e3 = (unsigned)inportb(0x526) + ((unsigned)inportb(0x527)<<8);
	unEmb2Mux34.emb2Mux34.reserv[0] = inportb(0x524);
	unEmb2Mux34.emb2Mux34.softVer = 1;
	unEmb2Mux34.emb2Mux34.type = 1;
	for(i=0; i<16; i++)
	{
		unEmb2Mux34.emb2Mux34.ctrl_e1[i] = inportb(0x590+i);
		unEmb2Mux34.emb2Mux34.state_e1[i] = inportb(0x580+i);
	}
*/
//////////////////////////////////////////////////
 //		i232=0;

		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; break;
			default:
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
//_______________________________________________________________232e
/*
		while(embRS232.UsedReceiveE())
		{
 			byte = embRS232.ReceiveE();
	  	switch(byte)
			{
			case 0x55: 
				embMsg232E.Init();
 			   	embRS232.TransE(0x55);
  //			   	embRS232.Trans_RDN(embMsgRequest->AddrS());		  //????????????????? neew keep before address of computer!!!
		   //		embRS232.Trans_RDN(COMP_DEF_MAC_END);	 //temporary zero mac: 001111000000
				  embRS232.Trans_RDN_Full(embRS232.HostMAC);	
				break; 
			case 0xAA: embMsg232E.Init(); 
  			
			break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A232E=1; 
			    	break;
			default:
				if(mode5A232E) 
				{
   					embMsg232E.Add(Modify5A(byte));
					mode5A232E=0;
				}
				else 
				{
    	            embMsg232E.Add(byte);
				}
			}  // switch byte
		  
			if(embMsg232E.IsEnd()) 
				break;
		  //	if(++i232> 10) break;
		}	 //while
 if(!embMsg232E.IsEnd()) // t
 {
 */
//_______________________________________________________________232e

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
				case 0xAA: embMsg485.Init(); break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);
				}
				if(embMsg485.IsEnd())
			  				break;

			}
//_____________________________________________________________________RDN
if(!embMsg485.IsEnd())
		{
			while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
			   	switch(byte)
				{
				case 0x55: embMsg485E.Init();//  printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485E.Init(); // printf("\n\r++++");
				break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485E=1; break;
				default:
					if(mode5A485E) 
					{
						embMsg485E.Add(Modify5A(byte));
						mode5A485E=0;
					}
					else embMsg485E.Add(byte);

				}
			 //	  	printf(".%X", byte);
			  if(embMsg485E.IsEnd())
							break;
			} //embrs485 usedReceive
	}  //	!embMsg485.IsEnd
//_____________________________________________________________________RDN
//______________________________________________________________________232e
// }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

		}
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
  if(embMsg485E.IsEnd()) 
				{
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
						// ->>	// Ответ в RS-232
							aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();
							embMsg485E.SetAddrI(aR);
							embMsg485E.SetAddrS(aI);
							embMsg485E.SetAddrR(aS);
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
						 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//							  embRS232.Trans_RDN_Full(embRS232.HostMAC);		
					}
					
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
						if(embMsg485E.AddrS()==SelfID())
						{

						// ->>	// Транзитом ответ в линию
							if(embMsg485E.TOM() & 0x01)
							{
								aI = embMsg485E.AddrI();
								aS = embMsg485E.AddrS();
								aR = embMsg485E.AddrR();
								embMsg485E.SetAddrI(aS);
								embMsg485E.SetAddrS(aR);
								embMsg485E.SetAddrR(aI);
								tBuffEmbMsgEast.Add(embMsg485E);
								tBuffEmbMsgWest.Add(embMsg485E);
								unEmb2NetStat.emb2NetStat.selfPacketSend++;	
						 //		embMsg485.Init(); //my						
							}
							else
							{
								// ->>	// Получили запрос из Ethernet
	  //!!!!!!!!!							flagRequest=3;
								flagRequest=4;
								embMsg485E.SetRS485();
								embMsgRequest = &embMsg485E;
							}
						}  //s != self
					}	//r != S

				}  //embrs485E.isend

	else //1024

 if(embMsg485.IsEnd()) 
				{
				    if(embMsg485.AddrI() != SelfID())
					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
						// ->>	// Ответ в RS-232
							aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aS);
							embMsg485.SetAddrS(aR);
							embMsg485.SetAddrR(aI);
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
								default: embRS232.TransEC(embMsg485.body[i]);
								}
							}
							embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);

					 //		embRS232.Trans_RDN_Full(embRS232.HostMAC);
						  //	embRS485.Trans_RDN(embMsgRequest->AddrS());

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
				}

			else //1024

			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
//________________________________________________________________________232e			
		 /*
		     else if(embMsg232E.IsEnd())//&&embMsg.ChkCRC())
  			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg232E;
					flagRequest=5;	//new
				//	my_printf(0x20);   //t
				}
			}
			*/
//________________________________________________________________________232e	

			else
			{
				if(rBuffEmbMsg.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					rBuffEmbMsg.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x60)
						{
							if(embMsgA.AddrS()==SelfID())//или равен 0000 или FFFF
							{
							 			
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}
								embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//							   embRS232.Trans_RDN_Full(embRS232.HostMAC);		
								flagRequest = 0;							}
						}
					}
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=2;
								embMsgRequest = &embMsgA;
							}
						}
					}
				}
			}

			if(flagRequest)//embMsgRequest->IsEnd())
			{
				if(embMsgRequest->IsRS485())
				{
				//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
						//	embMsgRequest->SetAddrS(aR);
						 //	embMsgRequest->SetAddrR(aI);
							embMsgAns.SetAddrS(aI);
						    embMsgAns.SetAddrR(aR);


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
						embMsgAns.SetRS485();
						aI = embMsgRequest->AddrI();
						aS = embMsgRequest->AddrS();
						aR = embMsgRequest->AddrR();
						embMsgAns.SetAddrI(aS);
						embMsgAns.SetAddrS(aI);
						embMsgAns.SetAddrR(aR);
					}
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
					switch(embMsgRequest->Type())
					{
					case 0x01: // запрос типа
			  //		printf("\n\r command 01");
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

/* this was before svcpack

					case 0x05: // Загрузка файла (запись в устройство) 
			  //			printf("\n\r command 05");
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>						ul2uc.uc[0] = embMsg.Body(0);
						ul2uc.uc[0] = embMsgRequest->Body(0);
						ul2uc.uc[1] = embMsgRequest->Body(1);
						ul2uc.uc[2] = embMsgRequest->Body(2);
						ul2uc.uc[3] = embMsgRequest->Body(3);

				   //t		addrRAM = (unsigned char *)ul2uc.ul;
						addrRAM = (unsigned char *)NVRAM_BASE;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						ui2uc.uc[2] = 0;
						ui2uc.uc[3] = 0;

						shift = ui2uc.ui;
						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;
						ui2uc.uc[3] = 0;

						len = ui2uc.ui;
						temp_crc=0;
						for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);
						ui2uc.uc[0] = embMsgRequest->Body(len+8);
						ui2uc.uc[1] = embMsgRequest->Body(len+9);
						ui2uc.uc[2] = 0;
						ui2uc.uc[3] = 0;

						if(ui2uc.ui==temp_crc)
						 {
			   //			 printf("\n\n\rCRC -OK!!!!!");

						  for(i=0; i<len; i++)
							{
						     *(addrRAM + i + shift) = embMsgRequest->Body(i+8);
							}
						 }
						/// формируем ответ ///
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

*/
//==================================================================================
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


//==================================================================================



					case 0x06:	//Выгрузка файла (чтение из устройства)
		 //				printf("\n\r command 06");
//	Запрос: <Адрес в памяти/32><смещение/16><N длина фрагмента/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
						/// формируем ответ ///
						ul2uc.uc[0] = embMsgRequest->Body(0);
						ul2uc.uc[1] = embMsgRequest->Body(1);
						ul2uc.uc[2] = embMsgRequest->Body(2);
						ul2uc.uc[3] = embMsgRequest->Body(3);
				   //		addrRAM = (unsigned char *)ul2uc.ul;
						addrRAM = (unsigned char *)NVRAM_BASE;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						ui2uc.uc[2] =  0;
						ui2uc.uc[3] =  0;
						shift = ui2uc.ui;
//______________________________________________________________t
		   //				if (keepshift ==  shift)
		   //				{trysend ++; if(trysend > 2l) { trysend = 0l;return;}}
		   //				keepshift = shift;
//___________________________________________________________________

						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;
						ui2uc.uc[3] = 0;

						len = ui2uc.ui;
						temp_crc=0;
						embMsgAns.SetType(0x06);
						embMsgAns.SetLength(len+10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));

						for(i=0; i<len; i++)
						{
							temp_crc += *(addrRAM+i+shift);
							embMsgAns.SetBody(i+8,*(addrRAM+i+shift));
						}
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(len+8,ui2uc.uc[0]);
						embMsgAns.SetBody(len+9,ui2uc.uc[1]);
						break;
//////
					case 0x07: /// Генерим запрос маркера во все направления
			//			printf("\n\r command 07");
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x0A:
			//			printf("\n\r command 0A");
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
			 //			printf("\n\r command 0B");
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0C:
			   //			printf("\n\r command 0C");
							embMsgAns.SetTOM(0x20);
							embMsgAns.SetAddrI(SelfID());
							embMsgAns.SetAddrS(SelfID());
							embMsgAns.SetType(0x0C);
							embMsgAns.SetLength(0);
							SetHLX();
///
//					CfgCard();
//					SaveCommut();
///
							embMsg.Init();
						break;
					case 0x0D:
				//		printf("\n\r command 0D");
							embMsgAns.SetType(0x0D);
							embMsgAns.SetLength(34);
							for(i=0; i<34; i++) embMsgAns.SetBody(i,unEmb2NetStat.byte[i]);
							unEmb2NetStat.emb2NetStat.markerTime = 0;
							unEmb2NetStat.emb2NetStat.buffModPm = 0;
							unEmb2NetStat.emb2NetStat.buffTransPm = 0;
							unEmb2NetStat.emb2NetStat.buffModPd = 0;
							unEmb2NetStat.emb2NetStat.buffTransPd = 0;
							unEmb2NetStat.emb2NetStat.buff232Pm = 0;
							unEmb2NetStat.emb2NetStat.buff232Pd = 0;
							unEmb2NetStat.emb2NetStat.ready_transit=0;
							unEmb2NetStat.emb2NetStat.ready_mod=1;
						break;
					case 0x13:
			   //			printf("\n\r command 13");
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
							bt = (unsigned char *)NVRAM_BASE;
							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x14: // Запрос состояния
			 //			printf("\n\r command 14");
							UpdateStateE1();
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(64);
							for(i=0; i<64; i++) embMsgAns.SetBody(i,unEmb2Mux155.byte[i]);
						break;
					case 0x15: // Запрос состояния
			 //			printf("\n\r command 15");
							UpdateSTM1Map();
							embMsgAns.SetType(0x15);
							embMsgAns.SetLength(128);
							for(i=0; i<128; i++) embMsgAns.SetBody(i,unSTM1.u[i]);
						break;
					case 0x22: //change ip address
							embMsgAns.SetType(0x22);
							if(embMsgRequest->Body(0))// set
							{
							   SetIPRem(
							   (embMsgRequest->Body(1) << 24) +
							   (embMsgRequest->Body(2) << 16) +
							   (embMsgRequest->Body(3) << 8) +
							   	embMsgRequest->Body(4)
				 			   );
							}
						   						   
							embMsgAns.SetLength(5);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 	
							embMsgAns.SetBody(1, (GetIPRem() >> 24) & 0xff);
							embMsgAns.SetBody(2, (GetIPRem() >> 16) & 0xff);
							embMsgAns.SetBody(3, (GetIPRem() >> 8) & 0xff);
							embMsgAns.SetBody(4, GetIPRem() & 0xff);
   							break;

					}
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(flagRequest == 1) 
					{
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

						flagRequest = 0;
						embMsgRequest = NULL;
					}
//___________________________________________________________________________________232e
				/*
					if(flagRequest == 5) 
					{
						embRS232.TransE(0x55);
						embRS232.TransE(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS232.TransE(0x5A); embRS232.TransE(0x00); break;
								case 0x55: embRS232.TransE(0x5A); embRS232.TransE(0x01); break;
								case 0xA5: embRS232.TransE(0x5A); embRS232.TransE(0x02); break;
								case 0xAA: embRS232.TransE(0x5A); embRS232.TransE(0x03); break;
								default: embRS232.TransE(embMsgAns.body[i]);
							}
						}
						embRS232.TransE(0x55);
					 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
						  embRS232.Trans_RDN_Full(embRS232.HostMAC);		
					  	embMsgAns.Init(); //my as in mf_20 previons
					 	flagRequest = 0;
					}
					*/
//______________________________________________________________________________________232e
					if(flagRequest == 3) 
					{
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
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
						embRS485.EmptyReceive();
						flagRequest = 0;
						embMsgRequest = NULL;
					}
//_________________________________________________________________________________RDN
				if(flagRequest == 4) 
			   	{ 
			  //		RS485_receive_disable();

			   embRS485.TransE(0x55);
					//	 printf("\n\r>>>>embMsgRequest->AddrS() = %X", embMsgRequest->AddrS());	 //3310
					//	 printf("\n\r>>>>embMsgRequest->AddrI() = %X", embMsgRequest->AddrI());	 //	3309
					//	 printf("\n\r>>>>embMsgRequest->AddrR() = %X", embMsgRequest->AddrR());	 //enower

					//	 printf("\n\r>>>>55");

						embRS485.TransE(0xAA);
					//	 printf(".AA");

						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
					//	  printf(".%0X",	embMsgAns.body[i]);

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
					 	embRS485.EmptyReceiveE();	//my: from testing mf20	//remaked 20.02.2008

						flagRequest = 0;
					}	// ==3
//________________________________________________________________________________________RDN

					flagRequest = 0;
					embMsgRequest = NULL;
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

		   //			embMsg232.Init();		//????
//______________________________________________________________________________________232e

			  //		embMsg232E.Init();		//???? 
//______________________________________________________________________________________232e
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
 //hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;
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
//__________________________________________________________________________
extern "C" void WriteMPC(unsigned long addr, unsigned short m)
{
  //	unsigned char *p;
  //	p = (unsigned char *)addr;//0x80001FF8;
  unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));
	*p=m;
}
// запись слова 16 бит 
extern "C" void WriteWMPC(unsigned long addr, unsigned int  m)
{
//	unsigned   *p;
 //	p = (unsigned int *)addr;//0x80001FF8;
//	p = (pointer)addr;//0x80001FF8;
//	*p=m;
 //  return; //t
 unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));
	  *p = m;
//  *dev_ptr = setdata;

//      uint_32 * dev_ptr;   
  //	  dev_ptr = (uint_32 *)addr; 
	//  *dev_ptr = m;

}
// чтение слова 16 бит
extern "C" unsigned  ReadWMPC(unsigned long addr)
{
//	unsigned  *p;
  //	p = (unsigned int*)addr;//0x80001FF8;
  unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));

	return *p;
}

extern "C" unsigned int  ReadMPC(unsigned long addr)
{
unsigned int ret;
  //	unsigned char  *p;
  //	p = (unsigned char*)addr;//0x80001FF8;
  unsigned short *p = (unsigned short *)((uint_32)OEDBASE + (uint_32)(addr << 1));
	ret = 	*p;
	return ret;
}




/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : Test_MPC155(void)
* Returned Value   : none
* Comments         :
*    Test for MPC155
*END*----------------------------------------------------------------------*/
extern "C" void Start_Test_MPC155()
{
char t;
//ScreenSetBuffer();
//ScreenAddString("test MPC155--SPI & OED--");

//ScreenAddString("начало тестового опроса");
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
// вкл RDY 
//outport(0xffa6,0x81fb); //mmcs
//outport(0xffa8,0xa0bb); //mpcs
printf("\n\r -1");
outportb(0x515,0x0f);   // вкл ретимер

outportb(0x51A,0x01);   // вкл opto
outportb(0x51B,0x01);   // вкл opto
//t2ms(3);
delay_mcs(3000);



//ScreenIntSent();
 printf("\n\r -2");

// reset chip
 WriteWMPC(0x02, 0x00ff);
//WriteWMPC(0x30000002, 0x00ff);	 //t

printf("\n\r -2a");

//t2ms(10);
delay_mcs(10000);
WriteWMPC(0x02, 0x0000);
//reset cdr
WriteWMPC(0x0c, 0x0780);
delay_mcs(10000);
//t2ms(10);
WriteWMPC(0x0c, 0x0781);
// ini chip stm1 mode
WriteWMPC(0x04, 0x0018);

// ini cdr selekt clk
WriteWMPC(0x0e, 0x1e0c);
delay_mcs(10000);
//t2ms(10);
WriteWMPC(0x0e, 0x1e08); // 155pclk LOOP

// ini tf codec
outportb(0x511,0x08); //reset
delay_mcs(1000);
//t2ms(1);
outportb(0x511,0x0);

printf("\n\r -3\n\r");



//liu
//rst on
outportb(0x514,0x08); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0xff);
outportb(0x513,0x01);//go

while( inportb(0x513)) 
{
t = inportb(0x513);
printf( "\r -> %02X", t);
}
 printf("\n\r -4");

//rst on
outportb(0x514,0x09); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0xff);
outportb(0x513,0x01);//go
while( inportb(0x513)){}

//rst on
outportb(0x514,0x0a); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0xff);
outportb(0x513,0x01);//go
while( inportb(0x513)){}
delay_mcs(10000);
//t2ms(10);

//liu
// rst off
outportb(0x514,0x08); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0x00);
outportb(0x513,0x01);//go
while( inportb(0x513)) {}

 printf("\n\r -5");


// rst off
outportb(0x514,0x09); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0x00);
outportb(0x513,0x01);//go
while( inportb(0x513)){}


// rst off
outportb(0x514,0x0a); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x28);
outportb(0x512,0x00);
outportb(0x513,0x01);//go
while( inportb(0x513)){}


 printf("\n\r -6");


//liu
// 
outportb(0x514,0x08); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x40);
outportb(0x512,0xa2);
outportb(0x513,0x01);//go
while( inportb(0x513)) {}

printf("\n\r -7");

// g
//outportb(0x514,0x08); // adr
//outportb(0x513,0x02); // rst
//outportb(0x512,0x78);
//outportb(0x512,0x82);
//outportb(0x513,0x01);//go
//while( inportb(0x513)) {}


// rst off
outportb(0x514,0x09); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x40);
outportb(0x512,0xa3);
outportb(0x513,0x01);//go
while( inportb(0x513)){}

// rst off
outportb(0x514,0x0a); // adr
outportb(0x513,0x02); // rst
outportb(0x512,0x40);
outportb(0x512,0xa4);
outportb(0x513,0x01);//go
while( inportb(0x513)){}
printf("\n\r -8");


outportb(0x514,0x0b); // adr


//wr data 35  tf codec
outportb(0x510,0x02); //
outportb(0x50f,0x44); //
outportb(0x50f,0x05);
outportb(0x50f,0x35);
outportb(0x510,0x01);//go
while( inportb(0x510)){
//t = inportb(0x510);
//printf( "\r -> %02X", t);

}

 printf("\n\r -9");


}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : Test_MPC155(void)
* Returned Value   : none
* Comments         :
*    Test for MPC155
*END*----------------------------------------------------------------------*/
extern "C" void Test_MPC155()
{
 //unsigned int i, w;
 unsigned short int z;//, z1;
 //unsigned short int z2, z3;
 //unsigned char t;
//  printf("\n\r -10");


//z1= ReadMPC(0x01);

//ScreenAddByte(z);
  //	printf("\n\r -11");
printf("\n\r------------------------------------------------------------");

 z= ReadMPC(0x00);
//ScreenAddByte(z1);
//ScreenAddString("-- ID OED==6104");
//ScreenIntSent();
printf("\n\r %0X-- ID OED==461", z);

//liu
// get id
outportb(0x514,0x08); // adr
outportb(0x513,0x02); // rst
//delay_mcs(1000);

//outportb(0x514,0x08); // adr
//delay_mcs(1000);

//toutportb(0x512,0x80|0x78);   //outportb(0x512,0xc0);
//outportb(0x512,0x80); //t 
outportb(0x512,0xc0);

//delay_mcs(1000);

outportb(0x512,0x00);
//delay_mcs(1000);

outportb(0x513,0x01);//go
//delay_mcs(1000);

while( inportb(0x513)) {
//t = inportb(0x513);
//printf( "\r -> %02X", t);



}

z=inportb(0x512);
//ScreenAddByte(z);
z=inportb(0x512);

//z2=inportb(0x512);
//ScreenAddByte(z);

//z3=inportb(0x512);

//ScreenAddByte(z);
//ScreenAddString("- spi LIU1==A2");
//ScreenIntSent();
printf("\n\r %02X -- spi LIU1==A2", z);
//printf("\n\r %02X.%02X -- spi LIU1==A2", z2, z3);

// get id
outportb(0x514,0x09); // adr
outportb(0x513,0x02); // rst

//outportb(0x514,0x09); // adr
//outportb(0x512,0x80|0x10); //
outportb(0x512,0xc0);
outportb(0x512,0x00);
outportb(0x513,0x01);//go
while( inportb(0x513)){}

z=inportb(0x512);
z=inportb(0x512);
//ScreenAddByte(z);
//ScreenAddString("- spi LIU2==A3");
//ScreenIntSent();
printf("\n\r %02X -- spi LIU2==A3", z);

// get id
outportb(0x514,0x0a); // adr
outportb(0x513,0x02); // rst
//outportb(0x514,0x0a); // adr
//outportb(0x512,0x80|0x10); //
outportb(0x512,0xc0);
outportb(0x512,0x00);
outportb(0x513,0x01);//go
while( inportb(0x513)){}
delay_mcs(1000);
//t2ms(1);
z=inportb(0x512);
z=inportb(0x512);
//ScreenAddByte(z);
//ScreenAddString("- spi LIU3==A4");
//ScreenIntSent();
printf("\n\r %02X -- spi LIU3==A4", z);

// retimer
// get ID
outportb(0x513,0x02); // rst
outportb(0x514,0x0b); // adr
outportb(0x512,0x80);
outportb(0x512,0x00);
outportb(0x513,0x01);//go

while( inportb(0x513)){}
delay_mcs(1000);
//t2ms(1);
z=inportb(0x512);
z=inportb(0x512);
//ScreenAddByte(z);

//ScreenAddString("- spi RETIM==A7");
//ScreenIntSent();
printf("\n\r %02X -- spi RETIM==A7", z);

//}


// rd data 35  tf codec
outportb(0x510,0x02); // rst
outportb(0x50f,0xc4); // rst
outportb(0x50f,0x05);
outportb(0x50f,0xff);
outportb(0x50f,0x00);
outportb(0x510,0x01);//go
while( inportb(0x510)){}

z=inportb(0x50f);
z=inportb(0x50f);
z=inportb(0x50f);
z=inportb(0x50f);
//ScreenAddByte(z);
//ScreenAddString("- spi TLF==35----------------------");
//ScreenIntSent();
printf("\n\r %02X - spi TLF==35-----", z);



//delay_mcs(1000);
//t2ms(1);



// period 280 mks


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//for (w=0; w<0xf0; w++);

//outportb(0x51e, !(inportb(0x51e))); //BLINK


delay_mcs(100000);
//t2ms(500);


}
//______________________________________________________________________________________
#define a14 ab22  
#define a15 ab23
#define a16 ab24  
#define a17 ab25
#define a18 ab26  
#define a19 ab27

#define a20 ab29  
#define a21 ab28
#define a23 ab30
#define ac   aa


void t2ms(unsigned long d)
{
 delay_mcs(d * 2000l);
}

void StartTestTlfMX155()
{
//___________________________________________________________________________
unsigned char	ab1[] =	{ 0x45,0x60,0xBF,0x25,0x52,0x2A,0x64,0x3F,0x89,0x00};   // IM-Filter part 1 
unsigned char	ab2[] =	{ 0x45,0x68,0x53,0x02,0x49,0x8A,0x07,0xF6,0x04,0x00};   // IM-Filter part 2 
unsigned char	ab3[] =	{ 0x45,0x18,0x08,0xB0,0xC5,0x42,0x3E,0xFB,0x72,0x07 };  // FRR-Filter    
unsigned char	ab4[] =	{ 0x45,0x28,0x43,0x8a,0xBc,0x27,0x88,0x00,0x00,0x00 }; // AR-Filter - строка 20
unsigned char	ab5[] =	{ 0x45,0x48,0x96,0x38,0x29,0x96,0xC9,0x2B,0x8B,0x00 }; /// LPR-Filter       
unsigned char	ab6[] =	{0x45,0x20,0x08,0x90,0x3F,0xBC,0x75,0x28,0x72,0x07}; // FRX-Filter       
unsigned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x85,0x50,0xc0,0x1a}; // AX-Filter -строка 20
unsigned char	ab8[] =	{ 0x45,0x50,0x96,0x38,0x29,0xF5,0xFA,0x2B,0x8B,0x00}; // LPX-Filter       
unsigned char	ab9[] =	{ 0x45,0x00,0x30,0x9B,0x88,0x80,0x00,0xC8,0x32,0x80}; // TH-Filter part 1 
unsigned char	ab10[] =	{ 0x45,0x08,0x80,0x00,0x80,0x00,0x67,0x35,0x5A,0x01 }; // TH-Filter part 2 
unsigned char	ab11[] =	{ 0x45,0x10,0x22,0xAD,0xB2,0x2A,0x24,0xDC,0x88,0x00};  // TH-Filter part 3 
unsigned char	ab12[] =	{ 0x45,0x80,0xF9,0x29,0x9B,0x2A,0x1A,0x22,0xC1,0x32}; // DC-Parameter     
unsigned char	ab13[] =	{ 0x45,0x70,0x32,0x3B,0x1B,0xC0,0xC3,0xB2,0xAC,0x02}; // Ringing          
unsigned char	ab14[] =	{ 0x45,0x90,0x3E,0xE5,0x2E,0xBA,0x81,0x2A,0xBA,0x8A }; // LP-Filters       
unsigned char	ab15[] =	{ 0x45,0x88,0x7B,0x01,0x2C,0x7B,0xB3,0x47,0x7B,0x01}; // Hook Levels      
unsigned char	ab16[] =	{ 0x45,0x78,0x00,0xC0,0x6D,0x7A,0xB3,0x48,0x08,0x00}; // Ramp Generator   
unsigned char	ab17[] =	{ 0x45,0x58,0x4A,0x41,0x34,0xDB,0x0E,0xA2,0x2A,0x00}; // TTX 
unsigned char	ab18[] =	{0x45,0x38,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG1              
unsigned char	ab19[] =	{0x45,0x40,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG2              
unsigned char	ab20[] =	{ 0x45,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};  // Reserved
unsigned char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27}; // AX-Filter -строка 29
unsigned char	ab22[] =	{ 0x46, 0x30, 0x07,0x10,0x79,0x11,0x02,0xFB,0x60,0x00,0x00,0x00 }; //DTMF POP
unsigned char	ab23[] =	{ 0x46,0x4A,0x00 };
unsigned char	ab24[] =	{0x44, 0x21, 0x00, 0x16, 0x06, 0x00, 0x00,  0x16, 0x06, 0x00 }; //pcmr,pcmx- line A
unsigned char	ab25[] =	{ 0x44, 0x1A, 0x00 }; // DSCR
unsigned char	ab26[] =	{ 0x44, 0x2B, 0x04 }; //TSTR3
unsigned char	ab27[] =	{ 0x44, 0x15, 0x01, 0x20, 0x07, 0x00, 0x03 };// bcr1-5
unsigned char	ab28[] =	{ 0x44,0x06,0x80 };  //XCR
unsigned char	ab29[] =	{ 0x44,0x1c,0x00 };  //LMCR1
unsigned char	ab30[] =	{0x4c, 0x21, 0x80, 0x96, 0x86, 0x80, 0x80,  0x96, 0x86, 0x80 }; //pcmr,pcmx- line B
//unsigned char	a14[] =	{ 0x46, 0x30, 0x07,0x10,0x79,0x11,0x02,0xFB,0x60,0x00,0x00,0x00 }; //DTMF POP
//unsigned char	a15[] =	{ 0x46,0x4A,0x00 };
//unsigned char	a16[] =	{0x44, 0x21, 0x00, 0x16, 0x06, 0x00, 0x00,  0x16, 0x06, 0x00 }; //pcmr,pcmx- line A
//unsigned char	a23[] =	{0x4c, 0x21, 0x80, 0x96, 0x86, 0x80, 0x80,  0x96, 0x86, 0x80 }; //pcmr,pcmx- line B
//unsigned char	a16[] =	{0x44, 0x21, 0x16, 0x16, 0x06, 0x00, 0x16,  0x016, 0x06, 0x00 }; //pcmr,pcmx
//unsigned char	a17[] =	{ 0x44, 0x1A, 0x00 }; // DSCR
//unsigned char	a18[] =	{ 0x44, 0x2B, 0x04 }; //TSTR3
//unsigned char	a19[] =	{ 0x44, 0x15, 0x01, 0x20, 0x07, 0x00, 0x03 };// bcr1-5
//unsigned char	a21[] =	{ 0x44,0x06,0x80 };  //XCR
//unsigned char	a20[] =	{ 0x44,0x1c,0x22 };  //LMCR1
//unsigned char	a24[] =	{ 0x44,0x11,0xbf };  //mack

//unsigned char	ac[] =	{ 0xC4,0x07,0xff,0x00,0x00,0x00,0x00 };  // request intreg
//unsigned char	ac1[] =	{ 0xC4,0x09,0xff,0x00, 0x00}; //0x00,0x00 };  // request intreg

// AKTIV
unsigned char	a22[] =	{ 0x02 };  // AKTIV mode -- разговорное состояние
unsigned char	a221[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a222[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE
unsigned char	a26[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a261[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a262[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE 2
unsigned char	a263[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a264[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a265[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x00); // off hook
// RING
unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- выдача звонка
unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x00); // оn hook
// WAIT
unsigned char	a28[] =	{ 0x07 }; // power dnv mode -- ожидание поднятия трубки
//outportb(0x511, 0x00); // on hook
//unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 



//____________________________________________________________________________
   ab1[0] =	0x45;ab1[1] =0x60;ab1[2] =0xBF;ab1[3] =0x25;ab1[4] =0x52;ab1[5] =0x2A;ab1[6] =0x64;ab1[7] =0x3F;ab1[8] =0x89;ab1[9] =0x00;   // IM-Filter part 1 
   ab2[0] = 0x45;ab2[1] =0x68;ab2[2] =0x53;ab2[3] =0x02;ab2[4] =0x49;ab2[5] =0x8A;ab2[6] =0x07;ab2[7] =0xF6;ab2[8] =0x04;ab2[9] =0x00;   // IM-Filter part 2 
   ab3[0] =	0x45;ab3[1] =0x18;ab3[2] =0x08;ab3[3] =0xB0;ab3[4] =0xC5;ab3[5] =0x42;ab3[6] =0x3E;ab3[7] =0xFB;ab3[8] =0x72;ab3[9] =0x07;  // FRR-Filter    
   ab4[0] =	0x45;ab4[1] =0x28;ab4[2] =0x43;ab4[3] =0x8a;ab4[4] =0xBc;ab4[5] =0x27;ab4[6] =0x88;ab4[7] =0x00;ab4[8] =0x00;ab4[9] =0x00; // AR-Filter - строка 20
   ab5[0] = 0x45;ab5[1] =0x48;ab5[2] =0x96;ab5[3] =0x38;ab5[4] =0x29;ab5[5] =0x96;ab5[6] =0xC9;ab5[7] =0x2B;ab5[8] =0x8B;ab5[9] =0x00; /// LPR-Filter       
   ab6[0] =	0x45;ab6[1] =0x20;ab6[2] =0x08;ab6[3] =0x90;ab6[4] =0x3F;ab6[5] =0xBC;ab6[6] =0x75;ab6[7] =0x28;ab6[8] =0x72;ab6[9] =0x07; // FRX-Filter       
   ab7[0] =	0x45;ab7[1] =0x30;ab7[2] =0xBE;ab7[3] =0x04;ab7[4] =0xB0;ab7[5] =0x27;ab7[6] =0x85;ab7[7] =0x50;ab7[8] =0xc0;ab7[9] =0x1a; // AX-Filter -строка 20
   ab8[0] =	0x45;ab8[1] =0x50;ab8[2] =0x96;ab8[3] =0x38;ab8[4] =0x29;ab8[5] =0xF5;ab8[6] =0xFA;ab8[7] =0x2B;ab8[8] =0x8B;ab8[9] =0x00; // LPX-Filter       
   ab9[0] =	0x45;ab9[1] =0x00;ab9[2] =0x30;ab9[3] =0x9B;ab9[4] =0x88;ab9[5] =0x80;ab9[6] =0x00;ab9[7] =0xC8;ab9[8] =0x32;ab9[9] =0x80; // TH-Filter part 1 
   ab10[0] = 0x45;ab10[1] =0x08;ab10[2] =0x80;ab10[3] =0x00;ab10[4] =0x80;ab10[5] =0x00;ab10[6] =0x67;ab10[7] =0x35;ab10[8] =0x5A;ab10[9] =0x01; // TH-Filter part 2 
   ab11[0] = 0x45;ab11[1] =0x10;ab11[2] =0x22;ab11[3] =0xAD;ab11[4] =0xB2;ab11[5] =0x2A;ab11[6] =0x24;ab11[7] =0xDC;ab11[8] =0x88;ab11[9] =0x00;  // TH-Filter part 3 
   ab12[0] = 0x45;ab12[1] =0x80;ab12[2] =0xF9;ab12[3] =0x29;ab12[4] =0x9B;ab12[5] =0x2A;ab12[6] =0x1A;ab12[7] =0x22;ab12[8] =0xC1;ab12[9] =0x32; // DC-Parameter     
   ab13[0] = 0x45;ab13[1] =0x70;ab13[2] =0x32;ab13[3] =0x3B;ab13[4] =0x1B;ab13[5] =0xC0;ab13[6] =0xC3;ab13[7] =0xB2;ab13[8] =0xAC;ab13[9] =0x02; // Ringing          
   ab14[0] = 0x45;ab14[1] =0x90;ab14[2] =0x3E;ab14[3] =0xE5;ab14[4] =0x2E;ab14[5] =0xBA;ab14[6] =0x81;ab14[7] =0x2A;ab14[8] =0xBA;ab14[9] =0x8A ; // LP-Filters       
   ab15[0] = 0x45;ab15[1] =0x88;ab15[2] =0x7B;ab15[3] =0x01;ab15[4] =0x2C;ab15[5] =0x7B;ab15[6] =0xB3;ab15[7] =0x47;ab15[8] =0x7B;ab15[9] =0x01; // Hook Levels      
   ab16[0] = 0x45;ab16[1] =0x78;ab16[2] =0x00;ab16[3] =0xC0;ab16[4] =0x6D;ab16[5] =0x7A;ab16[6] =0xB3;ab16[7] =0x48;ab16[8] =0x08;ab16[9] =0x00; // Ramp Generator   
   ab17[0] = 0x45;ab17[1] =0x58;ab17[2] =0x4A;ab17[3] =0x41;ab17[4] =0x34;ab17[5] =0xDB;ab17[6] =0x0E;ab17[7] =0xA2;ab17[8] =0x2A;ab17[9] =0x00; // TTX 
   ab18[0] = 0x45;ab18[1] =0x38;ab18[2] =0x33;ab18[3] =0x49;ab18[4] =0x22;ab18[5] =0x65;ab18[6] =0xBB;ab18[7] =0x00;ab18[8] =0x00;ab18[9] =0x00; // TG1              
   ab19[0] = 0x45;ab19[1] =0x40;ab19[2] =0x33;ab19[3] =0x49;ab19[4] =0x22;ab19[5] =0x65;ab19[6] =0xBB;ab19[7] =0x00;ab19[8] =0x00;ab19[9] =0x00; // TG2              
   ab20[0] = 0x45;ab20[1] =0x98;ab20[2] =0x00;ab20[3] =0x00;ab20[4] =0x00;ab20[5] =0x00;ab20[6] =0x00;ab20[7] =0x00;ab20[8] =0x00;ab20[9] =0x00;  // Reserved
   ab21[0] = 0x45;ab21[1] =0x30;ab21[2] =0xBE;ab21[3] =0x04;ab21[4] =0xB0;ab21[5] =0x27; // AX-Filter -строка 29
   ab22[0] = 0x46;ab22[1] =0x30;ab22[2] =0x07;ab22[3] =0x10;ab22[4] =0x79;ab22[5] =0x11;ab22[6] =0x02;ab22[7] =0xFB;ab22[8] =0x60;ab22[9] =0x00;ab22[10] =0x00;ab22[11] =0x00 ; //DTMF POP
   ab23[0] = 0x46;ab23[1] =0x4A;ab23[2] =0x00 ;
   ab24[0] = 0x44;ab24[1] =0x21;ab24[2] =0x00;ab24[3] = 0x16;ab24[4] = 0x06;ab24[5] = 0x00;ab24[6] = 0x00;ab24[7] =  0x16;ab24[8] = 0x06;ab24[9] = 0x00 ; //pcmr;ab24[0] =pcmx- line A
   ab25[0] = 0x44;ab25[1] =0x1A;ab25[2] =0x00 ; // DSCR
   ab26[0] = 0x44;ab26[1] =0x2B;ab26[2] =0x04 ; //TSTR3
   ab27[0] = 0x44;ab27[1] =0x15;ab27[2] =0x01;ab27[3] = 0x20;ab27[4] = 0x07;ab27[5] = 0x00;ab27[6] = 0x03;// bcr1-5
   ab28[0] = 0x44;ab28[1] =0x06;ab28[2] =0x80;  //XCR
   ab29[0] = 0x44;ab29[1] =0x1c;ab29[2] =0x00; //LMCR1
   ab30[0] = 0x4c;ab30[1] =0x21;ab30[2] =0x80;ab30[3] = 0x96;ab30[4] = 0x86;ab30[5] = 0x80;ab30[6] = 0x80;ab30[7] =  0x96;ab30[8] = 0x86;ab30[9] = 0x80; //pcmr;ab6[0] =pcmx- line B
// AKTIV	
   a22[0] =	 0x02;  // AKTIV mode -- разговорное состояние
   a221[0] = 0x44;a221[1] =0x1c;a221[2] =0x22; // LMCR1
   a222[0] = 0x44;a222[1] =0x1A;a222[2] =0x00; // dscr
//outportb(0x511;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE
   a26[0] =	0x02; // RING pause MODE -- генерация КПВ
   a261[0] = 0x44;a261[1] =0x1c;a261[2] =0xAA; // LMCR1
   a262[0] = 0x44;a262[1] =0x1A;a262[2] =0x05; // dscr
//outportb(0x511;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE 2
   a263[0] = 0x02; // RING pause MODE -- генерация КПВ
   a264[0] = 0x44;a264[1] =0x1c;a264[2] =0xAA; // LMCR1
   a265[0] = 0x44;a265[1] =0x1A;a265[2] =0x05; // dscr
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // off hook
// RING
   a272[0] = 0x05; // RING burst MODE -- выдача звонка
   a271[0] = 0x44;a271[1] =0x1c;a271[2] =0x22;  // LMCR1
   a27[0] =	 0x44;a27[1] =0x1A;a27[2] =0x00; // dscr
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // оn hook
// WAIT
   a28[0] = 0x07; // power dnv mode -- ожидание поднятия трубки
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // on hook
   aa[0] =  0xC4;aa[1] =0x07;aa[2] =0xFF;aa[3] =0x00;aa[4] =0x00;aa[5] =0x00;aa[6] =0x00; 

//_________________________________________from main


//___________________________________________________________________________

// unsigned char j, aa_loc, aa1, aa2, aa3, code;
 unsigned int i;//,z,  merc, zerc,up0erc,up1erc, w;
//_____________________________________________
//void InitTLF()
//{
//	int i;

// сброс кодека
	for(i=0; i<15; i++) outportb(0x511, 0x08); 
	outportb(0x511, 0x00);
	for(i=0; i<10000; i++);

	outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab1); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x50F, ab2[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab2); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x50F, ab3[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab3); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x50F, ab4[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab4); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x50F, ab5[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab5); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x50F, ab6[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab6); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x50F, ab7[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab7); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x50F, ab8[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab8); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x50F, ab9[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab9); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x50F, ab10[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab10); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x50F, ab11[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab11); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x50F, ab12[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab12); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x50F, ab13[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab13); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x50F, ab14[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab14); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x50F, ab15[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab15); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x50F, ab16[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab16); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x50F, ab17[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab17); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x50F, ab18[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab18); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x50F, ab19[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab19); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x50F, ab20[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab20); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x50F, ab21[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab21); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab22); i++) outportb(0x50F, ab22[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab23); i++) outportb(0x50F, ab23[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab23); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab24); i++) outportb(0x50F, ab24[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab24); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab25); i++) outportb(0x50F, ab25[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab25); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab26); i++) outportb(0x50F, ab26[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab27); i++) outportb(0x50F, ab27[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab27); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab28); i++) outportb(0x50F, ab28[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab28); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab29); i++) outportb(0x50F, ab29[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab29); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab30); i++) outportb(0x50F, ab30[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(ab30); i++);
//}


//_____________________________________________ 


  //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
 //	Enable(); // Разрешаем все прерывания
// сброс кодека
for(i=0; i<15; i++) outportb(0x511, 0x08);
outportb(0x511, 0x00);
t2ms(1);

//ScreenSetBuffer();
//ScreenAddString("test TLF----e");
//ScreenIntSent();
 //printf("\n\r test TLF----e\n\r");

//while(1)
//{
//outportb(0x510, 0x02); for(i=0; i<sizeof(an); i++) outportb(0x50F, an[i]); outportb(0x510, 0x01); while((inportb(0x510) & 0x01)!=0);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//}

   // INIT кодека
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x50F, ab2[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x50F, ab3[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x50F, ab4[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x50F, ab5[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x50F, ab6[i]); outportb(0x510, 0x01); //for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x50F, ab7[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x50F, ab8[i]); outportb(0x510, 0x01); //for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
t2ms(1);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x50F, ab9[i]); outportb(0x510, 0x01); //for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x50F, ab10[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x50F, ab11[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x50F, ab12[i]); outportb(0x510, 0x01); //for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x50F, ab13[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x50F, ab14[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x50F, ab15[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x50F, ab16[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x50F, ab17[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x50F, ab18[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x50F, ab19[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x50F, ab20[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);

outportb(0x510, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x50F, ab21[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);


	outportb(0x510, 0x02); for(i=0; i<sizeof(a14); i++) outportb(0x50F, a14[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a15); i++) outportb(0x50F, a15[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a16); i++) outportb(0x50F, a16[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a17); i++) outportb(0x50F, a17[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a18); i++) outportb(0x50F, a18[i]); outportb(0x510, 0x01); //for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a19); i++) outportb(0x50F, a19[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a20); i++) outportb(0x50F, a20[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a21); i++) outportb(0x50F, a21[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);

outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
outportb(0x510, 0x02); for(i=0; i<sizeof(a23); i++) outportb(0x50F, a23[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);


outportb(0x511, 0x04); // off hook
outportb(0x510, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x50F, a26[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);




//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

	
/*
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x50F, a272[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
*/

//t2ms(1000);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//______________________________________________________________added for MPC
// SLUG KANAL

//WriteW2(0x1020,0x0102); // rising
 
outportb(0x509,0x8c); // DDC in D4 ch A
outportb(0x50a,0x8c); // DDC in D4 ch b
outportb(0x507,0x96); //  TLF in E2 ch A
outportb(0x508,0x96); //  TLF in E2 ch b
WriteWMPC(0x1345,0x0020);
WriteWMPC(0x1b45,0x0020);
   
//oed  WriteW2(0x1345,0x0020); // D4
//oed  WriteW2(0x1b45,0x0020); //  D4
//_______________________________________________________________
}
//while(1)
void TestTlfMX155()
	{

  unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 
  aa[0] =  0xC4; aa[1] =0x07;aa[2] =0xFF;aa[3] =0x00;aa[4] =0x00;aa[5] =0x00;aa[6] =0x00; 

  unsigned char  aa_loc, aa1, aa2, aa3, code;
  unsigned int i;

//____________________________________________________________________________




t2ms(2);

// прием символа  режим звонка

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
         
	
//t outportb(0x510, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x50F, ac[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
 outportb(0x510, 0x02);
 for(i=0; i<sizeof(aa); i++) 
 outportb(0x50F, aa[i]);
 outportb(0x510, 0x01);// for(i=0; i<100; i++);
//printf("\n\r"); 

 while((inportb(0x510) & 0x01)!=0)
 {
// printf("\r>0x%02X", inportb(0x510));
 }
//  printf("\r>Ok", inportb(0x510));

aa_loc = inportb(0x50f);
aa_loc=inportb(0x50f);
aa_loc=inportb(0x50f);
aa1=inportb(0x50f);
aa2=inportb(0x50f);
aa3=inportb(0x50f);
aa_loc =inportb(0x50f);

//if ((aa3 & 0x80)!=0)
//if ((aa1 & 0x40)!=0)
 //{ 

printf("\r aa1 = 0x%02X aa2 = 0x%02X aa3 = 0x%02X", aa1, aa2, aa3);

if ((aa1&0x80)&&(aa3&0x80))
//if(1)
{
switch ( (aa3 & 0xfc)>>2 )
{
	case  (48+1) :  code='1'; break;
	case  (48+2) :  code='2'; break;
	case  (48+3) :  code='3'; break;
	case  (48+4) :  code='4'; break;
	case  (48+5) :  code='5'; break;
	case  (48+6) :  code='6'; break;
	case  (48+7) :  code='7'; break;
	case  (48+8) :  code='8'; break;
	case  (48+9) :  code='9'; break;
	case  (48+10) :  code='0'; break;
	case  (48+11) :  code='*'; break;
	case  (48+12) :  code='#'; break;
	case  (48+13) :  code='A'; break;
	case  (48+14) :  code='B'; break;
	case  (48+15) :  code='C'; break;
	default:  	code='?';
}

//ScreenAddByte( aa1); // intreg1
//ScreenAddByte( aa2); // intreg2
//ScreenAddByte( aa3); // intreg3
//ScreenAddByte( aa); // intreg4
//ScreenAddByte( aa); // intreg4
//ScreenAddChar('=');// CR
//ScreenAddChar(code);// CR
//ScreenAddChar(13);// CR
//ScreenIntSent();

printf("\r %d %d %d %d %d = %c \r\n", aa1, aa2, aa3, aa_loc, aa_loc, code);

}
//tt2ms(100);
t2ms(10);

// }

	//}

	//ScreenAddString(" exit to monitor");
	//ScreenIntSent();
//  asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor

}

//___________________________________________________________________________________
char TestRing()
{
 unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 
  aa[0] =  0xC4; aa[1] =0x07;aa[2] =0xFF;aa[3] =0x00;aa[4] =0x00;aa[5] =0x00;aa[6] =0x00; 


unsigned char  aa_loc, aa1, aa2, aa3;//, code;
unsigned int i;
  	t2ms(2);
  	outportb(0x510, 0x02); 
  	for(i=0; i < sizeof(aa); i++) outportb(0x50F, aa[i]);
  	outportb(0x510, 0x01);// for(i=0; i<100; i++);
  	while((inportb(0x510) & 0x01)!=0);
	aa_loc = inportb(0x50f);
	aa_loc=inportb(0x50f);
	aa_loc=inportb(0x50f);
	aa1=inportb(0x50f);
	aa2=inportb(0x50f);
	aa3=inportb(0x50f);
	aa_loc =inportb(0x50f);
	printf("\r aa1=0x%X aa2=0x%X aa3=0x%X aa_loc=0x%X \r\n", aa1, aa2, aa3, aa_loc);
  	if (aa1 & 0x48)
	{
	return 1;
	}
	t2ms(10);
	return 0;
}

void RingM()
{
unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- выдача звонка
unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr

	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a272[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a272); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a271); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a27); i++);
  	outportb(0x511, 0x00); // оn hook
}


void StartRing()
{
 RingM();
}
//__________________________________________________________________________________



extern "C" void test_PU37_startMX155()
{
 unsigned char  n, i;

 //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
//	Enable(); // Разрешаем все прерывания

	// BUS TEST 
	 
	outportb(0x500, i);
	if (i != ( inportb(0x500)) ) 
			{
   //		   		ScreenAddString("BUS test  err");
			  printf("\n\rBUS test  err");

		  //	ScreenIntSent();
	}
	 
	   
//ScreenSetBuffer();
//ScreenAddString("test PU37   4 DDC каналов timer mode----");
//ScreenIntSent();
//t printf("\rtest PU37   4 DDC channels timer mode----\r");

   // INIT DDC  -- очистка

for (i=0; i<20; i++)
//for (i=0; i<200; i++)
	{
   n=inportb(0x507);
   n=inportb(0x50B);
   n=inportb(0x50d);
   n=inportb(0x509);
  }

   outport(0x506,0x55); // разрешаем прерывания на прием

//______________________________________________________________added for MPC
// SLUG KANAL

//WriteW2(0x1020,0x0102); // rising
outportb(0x509,0x8c); // DDC in D4 ch A
outportb(0x50a,0x8c); // DDC in D4 ch b
outportb(0x507,0x96); //  TLF in E2 ch A
outportb(0x508,0x96); //  TLF in E2 ch b
WriteWMPC(0x1345,0x0020);
WriteWMPC(0x1b45,0x0020);
//oed  WriteW2(0x1345,0x0020); // D4
//oed  WriteW2(0x1b45,0x0020); //  D4
//_______________________________________________________________




 //outport(0x506,0xff);
}
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//while(1)
#ifdef IncEmbSerialMD34AVT
void test_PU37()
{
	 /*
 static unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1,   i;     
 static unsigned int   merc, zerc,up0erc,up1erc;
 static unsigned char rup0, rup0o,  rup1, rup1o;
 static unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;

	*/
  static unsigned char    i;

 static int PeriodCounter = 0l;
// unsigned char tchar;
// unsigned char bstate;
// unsigned long cnt;
// for (i=0; i<20; i++)
//	{
//   n=inportb(0x507);
//   n=inportb(0x50B);
//   n=inportb(0x50d);
//   n=inportb(0x509);
//  }


 //  outport(0x506,0x55); //t разрешаем прерывания на прием


//t2ms(3);
//t delay_mcs(1l); //work 
//  delay_mcs(50l); 
//for (bt=0; bt<0x02ff; bt++) {} // задержка
   		i++;
// DDC  rx- tx test----------------------------------------------------
// timer mode TX---------------------------------------
 PeriodCounter++;
// if(PeriodCounter > 100000l)
//ok if(PeriodCounter > 10000l)
 //ok  if(PeriodCounter > 1000l)
//ok  if(PeriodCounter > 10l)
//t if(PeriodCounter >5l)
//#ifndef FULL_TEST_TRANZIT
//090512 if(PeriodCounter > TEST_PERIOD)
 if(PeriodCounter > TEST_PERIOD * 4)	 //090512

//if(PeriodCounter > 10000l) //t
//#else
//if(1)
//#endif// FULL_TEST_TRANZIT
  {
 PeriodCounter = 0l;
	 // TX UP0
//for (i=0; i<10; i++)
	 //	{

//modem transmit 508 : bit5
//transit transmit50a : bit5
//up0 : transmit50c : bit5
//up1 : transmit 50e
 

	 // 	bstate =  inportb(0x50c);

		//  printf("bstate up0:  %d  \n\r", bstate);


			   // while((inportb(0x505) & 0x20) == 0) {}
				  //	  if(inportb(0x505) & 0x20)
				 //	    if(inportb(0x50c) & 0x20)

		   //			  {
	//	   #ifndef FULL_TEST_TRANZIT
			 /*
  	 if(embSerialACT155.UsedSendUD1() < 5) 
			     {

				embSerialACT155.AddUD1(tup0++);
			    embSerialACT155.AddUD1(tup0++);
			    embSerialACT155.AddUD1(tup0++);
				embSerialACT155.AddUD1(tup0++);
				embSerialACT155.AddUD1(tup0++);


			   //		   outportb(0x50B, tup0++);
						 		 tup0c += 5;   
	 //		#endif								   
								 } 
			   */
#ifdef PROG_BMD155PS				
		   if(embSerialACT155.UsedSendPower() < 5) 
			     {

				embSerialACT155.AddPower(tup0++);
			    embSerialACT155.AddPower(tup0++);
			    embSerialACT155.AddPower(tup0++);
				embSerialACT155.AddPower(tup0++);
				embSerialACT155.AddPower(tup0++);


			   //		   outportb(0x50B, tup0++);
						 		 tup0c += 5;   
	 //		#endif								   
								 } 
#endif // PROG_BMD155PS

				 





	  //	}

// TIMER MODE
	 // TX UP1
//for (i=0; i<2; i++)
//{
			  //	 while((inportb(0x505) & 0x80) == 0) {}
//bstate =  inportb(0x50e);

   //		  printf("bstate up1 :  %d  \n\r", bstate);

	//					if (inportb(0x50e) & 0x20)
   //						{
 //  #ifndef FULL_TEST_TRANZIT
 /*
  		if(embSerialACT155.UsedSendUD2() < 5)
			     {
			   //ok		   embSerialACT155.UsedUD1();
			   	  		 embSerialACT155.AddUD2(tup1++);
						  embSerialACT155.AddUD2(tup1++);
						   embSerialACT155.AddUD2(tup1++);
						    embSerialACT155.AddUD2(tup1++);
							 embSerialACT155.AddUD2(tup1++);

   					 //t	 outportb(0x50D, tup1++);
   				   		 tup1c+=5;
//#endif
   					  	 }
						 */
//}
	 // TX MODEM
//for (i=0; i<8; i++)
//{
 				   //		 while((inportb(0x505) & 0x02) == 0) {}
  // bstate =  inportb(0x508);
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x508) & 0x20)
					//	 {

//#ifdef FULL_TEST_TRANZIT
		   if(embSerialACT155.UsedSendMod() < 5)
		  // 	if(!embSerialACT155.UsedSendMod()) 
				  {
		  		   embSerialACT155.AddMod(tm++);
				      embSerialACT155.AddMod(tm++);
					     embSerialACT155.AddMod(tm++);
						    embSerialACT155.AddMod(tm++);
							   embSerialACT155.AddMod(tm++);

		  		   tmc += 5;
		  		  }
//#else

			//t	  outportb(0x507, tm++);
			   //	  tmc++;
//#endif

					  //	 }
//}
	  // TX TRANZIT
//for (i=0; i<8; i++)
//{
  				   //		while((inportb(0x505) & 0x08) == 0) {}
   // bstate =  inportb(0x50a);
		   //		 printf("bstate trz :  %d  \n\r", bstate);

			//			if (inportb(0x50a) & 0x20)
					//	{
//#ifdef FULL_TEST_TRANZIT
			  //	  while
		  	  if(embSerialACT155.UsedSendTransit() < 5)
		   //	  if(!embSerialACT155.UsedSendTransit()) 
			     {
			   	   embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
				     embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  					embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  					embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
  					embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
			  ttzc += 5;
  
			    }
  			//	if(embSerialACT155.UsedSendTransit() < 2)
		   //	  if(!embSerialACT155.UsedSendTransit()) 
			//     {
			//   	   embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
			//    }
			//	  if(embSerialACT155.UsedSendTransit() < 1)
		   //	  if(!embSerialACT155.UsedSendTransit()) 
			//     {
			//   	   embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
			//    }
			  



//#else

					  //	 outportb(0x509,  ttz++); 
				  //		ttzc++;
//#endif
				   //		}
//}

} //PeriodCounter
//--------------------------------------------------------------

//	if (0x80 & inportb(0xff2e)) // при появлении прерывания INT3

   //	while (0x20 & inportb(0xff2e)) // при появлении прерывания INT1
 /*
   unsigned int tmp =  (unsigned int)INT0_FLAG;
   //t      while (IntFlag & tmp)
        if(IntFlag & tmp)
   //	 if(1)
		{
		  IntFlag &=  ~tmp;
		//n=inportb(0x505); // опрос флагов прерываний


   //		if
        cnt = 16;
		while (((inportb(0x505) &  0x10) != 0) && cnt)  // RX up0
				{
				 	rup0=inportb(0x50b);
					rup0c++;
					if (rup0o!=rup0)
							{			
									if (up0erc <0xfffe) up0erc++;
							}
					rup0++;
					rup0o=rup0;
					cnt--;
				}

	 //	if 
	   cnt = 16;
		while(((inportb(0x505) &  0x40) != 0) && cnt) // RX up1
				{
				 	rup1=inportb(0x50d);
					rup1c++;
					if (rup1o!=rup1)
							{			
									if (up1erc <0xfffe) up1erc++;
							}
					rup1++;
					rup1o=rup1;
					cnt--;
				}

	//	if
  //	bstate =  inportb(0x505);

		cnt = 16;
		while (((inportb(0x505) &  0x01) != 0) && cnt)  // RX MODEM
				{
				 	rm=inportb(0x507);
					rmc++;
		  	 //  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{		
									tchar =   inportb(0x508);
									tchar =   inportb(0x508);	
									if (merc <0xfffe) merc++;
								    printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
									//508
									
							}
					rm++;
					rmo=rm;
					cnt--;
				}

	  //	if 
	    cnt = 16;
		while(((inportb(0x505) &  0x04) != 0) && cnt)  // RX TRANZIT
				{
				 rtz=inportb(0x509);
					rtzc++;
					if (rtzo!=rtz)
							{
									if (zerc <0xfffe) 	zerc++;
							}
				rtz++;
				rtzo=rtz;
				cnt--;
				}
		

	//	} 

*/

//___________________________________________________________________________
 
	if( embSerialACT155.m_RBuffMod.Used()) 
	{
	rm=embSerialACT155.m_RBuffMod.Get();
					rmc++;
		  	 //  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{		
							 //		tchar =   inportb(0x508);
							   //		tchar =   inportb(0x508);	
									if (merc <0xfffe) merc++;
								 //   printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
									//508
									
							}
					rm++;
					rmo=rm;

}

  
  //	if(irq.bit.IRQ_RX_trans)// m_RBuffTransit.Add(inportb(0x509)); 
   if( embSerialACT155.m_RBuffTransit.Used()) 
 {	
  rtz=embSerialACT155.m_RBuffTransit.Get();
					rtzc++;
					if (rtzo!=rtz)
							{
									if (zerc <0xfffe) 	zerc++;
							}
				rtz++;
				rtzo=rtz;
}


   //	if(irq.bit.IRQ_RX_UD1)// m_RBuffUD1.Add(inportb(0x50B)); 
#ifdef PROG_BMD155PS   
	if( embSerialACT155.m_RBuffPower.Used())
	{
				 	rup0=embSerialACT155.m_RBuffPower.Get();
					rup0c++;
					if (rup0o!=rup0)
							{			
									if (up0erc <0xfffe) up0erc++;
							}
					rup0++;
					rup0o=rup0;
				  //	cnt--;
				}
#endif //  PROG_BMD155PS
			   

   //	if(irq.bit.IRQ_RX_UD2)//	 m_RBuffUD2.Add(inportb(0x50D)); 	   //090413
   /*
	if( embSerialACT155.m_RBuffUD2.Used())
	{
				 rup1=embSerialACT155.m_RBuffUD2.Get();
				   rup1c++;
					if (rup1o!=rup1)
							{
									if (up1erc <0xfffe) 	up1erc++;
							}
				rup1++;
				rup1o=rup1;
		 //	cnt--;
	}

	 */

			   
//___________________________________________________________________________





#ifdef PROG_BMD155PS	  
	if (tup0c > 20000)
		{

	 //		ScreenAddString("Send UP0 --");
	//		ScreenAddInt(tup0c);
	 //		ScreenAddString(" RX--");
	//		ScreenAddInt(rup0c);
	//		ScreenAddString(" ERR--");
   //			ScreenAddInt(up0erc);
   //			ScreenIntSent();
 //  printf("\n\rSend UP0 -- %d  RX-- %d  ERR-- %d\n\r", tup0c, rup0c, up0erc);
   printf("\n\rSend Power -- %d  RX-- %d  ERR-- %d\n\r", tup0c, rup0c, up0erc);
			tup0c=0;rup0c=0; up0erc=0;
			}
#endif //PROG_BMD155PS
			
/*
	if (tup1c>20000)
		{

	  //		ScreenAddString("Send UP1 --");
	  //		ScreenAddInt(tup1c);
	  //		ScreenAddString(" RX--");
	  //		ScreenAddInt(rup1c);
	  //		ScreenAddString(" ERR--");
	  //		ScreenAddInt(up1erc);
	  //		ScreenIntSent();
  	  printf("Send UP1 -- %d  RX-- %d  ERR-- %d\n\r", tup1c, rup1c, up1erc);

			tup1c=0;rup1c=0; up1erc=0;

			}
*/

	if (ttzc>20000)
		{

	   //		ScreenAddString("Send TrZ --");
	   //		ScreenAddInt(ttzc);
	   //		ScreenAddString(" RX--");
	   //		ScreenAddInt(rtzc);
	   //		ScreenAddString(" ERR--");				  
	   //		ScreenAddInt(zerc);
	   //		ScreenIntSent();
   	   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);
	 //  printf("count = %d \n\r",count1);

			ttzc=0;rtzc=0; zerc=0;
			}
	
	if (tmc>20000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
 	   printf("Send MOD -- %d  RX-- %d  ERR-- %d\n\r", tmc, rmc, merc);

			tmc=0;rmc=0; merc=0;
		}
	

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 //     wd_reset();	

	//  my_int_enable_irq0();
   //	  }
 //	  else
 //	  {
 //	  printf("\n wait interrupt...\n\r");
 //	  }
//}

	//ScreenAddString(" exit to monitor");
	//ScreenIntSent();
//  asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor
}

#endif // IncEmbSerialMD34AVT

void test_PU37MX155()
{
 static unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1,   i;     
 static unsigned int   merc, zerc,up0erc,up1erc;
 static unsigned char rup0, rup0o,  rup1, rup1o;
 static unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;
 static int PeriodCounter = 0l;
// unsigned char bstate;
 unsigned long cnt;
// for (i=0; i<20; i++)
//	{
//   n=inportb(0x507);
//   n=inportb(0x50B);
//   n=inportb(0x50d);
//   n=inportb(0x509);
//  }


 //  outport(0x506,0x55); //t разрешаем прерывания на прием


//t2ms(3);
//t delay_mcs(1l); //work 
//  delay_mcs(50l); 
//for (bt=0; bt<0x02ff; bt++) {} // задержка
   		i++;
// DDC  rx- tx test----------------------------------------------------
// timer mode TX---------------------------------------
 PeriodCounter++;
// if(PeriodCounter > 100000l)
//ok if(PeriodCounter > 10000l)
 //ok  if(PeriodCounter > 1000l)
//ok  if(PeriodCounter > 10l)
//t if(PeriodCounter >5l)
if(PeriodCounter >10l)

 //badif(1)
 {
 PeriodCounter = 0l;
	 // TX UP0
//for (i=0; i<10; i++)
		{

//modem transmit 508 : bit5
//transit transmit50a : bit5
//up0 : transmit50c : bit5
//up1 : transmit 50e
 

	 // 	bstate =  inportb(0x50c);

		//  printf("bstate up0:  %d  \n\r", bstate);


			   // while((inportb(0x505) & 0x20) == 0) {}
				  //	  if(inportb(0x505) & 0x20)
				 //	    if(inportb(0x50c) & 0x20)

					  {
					   outportb(0x50B, tup0++);
								 tup0c++;     
								 } 
		}

// TIMER MODE
	 // TX UP1
//for (i=0; i<2; i++)
{
			  //	 while((inportb(0x505) & 0x80) == 0) {}
//bstate =  inportb(0x50e);

   //		  printf("bstate up1 :  %d  \n\r", bstate);

	//					if (inportb(0x50e) & 0x20)
   //						{
   						 outportb(0x50D, tup1++);
   						 tup1c++;
   //						 }
}
	 // TX MODEM
//for (i=0; i<8; i++)
{
 				   //		 while((inportb(0x505) & 0x02) == 0) {}
  // bstate =  inportb(0x508);
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x508) & 0x20)
						 {
						 outportb(0x507, tm++);
						 tmc++;
						 }
}
	  // TX TRANZIT
//for (i=0; i<8; i++)
{
  				   //		while((inportb(0x505) & 0x08) == 0) {}
   // bstate =  inportb(0x50a);
		   //		 printf("bstate trz :  %d  \n\r", bstate);

			//			if (inportb(0x50a) & 0x20)
						{
						 outportb(0x509,  ttz++); 
						ttzc++;
						}
}

} //PeriodCounter
//--------------------------------------------------------------

//	if (0x80 & inportb(0xff2e)) // при появлении прерывания INT3

   //	while (0x20 & inportb(0xff2e)) // при появлении прерывания INT1
   unsigned int tmp =  (unsigned int)INT0_FLAG;
   //t      while (IntFlag & tmp)
        if(IntFlag & tmp)
   //	 if(1)
		{
		  IntFlag &=  ~tmp;
		//n=inportb(0x505); // опрос флагов прерываний


   //		if
        cnt = 16;
		while (((inportb(0x505) &  0x10) != 0) && cnt)  // RX up0
				{
				 	rup0=inportb(0x50b);
					rup0c++;
					if (rup0o!=rup0)
							{			
									if (up0erc <0xfffe) up0erc++;
							}
					rup0++;
					rup0o=rup0;
					cnt--;
				}

	 //	if 
	   cnt = 16;
		while(((inportb(0x505) &  0x40) != 0) && cnt) // RX up1
				{
				 	rup1=inportb(0x50d);
					rup1c++;
					if (rup1o!=rup1)
							{			
									if (up1erc <0xfffe) up1erc++;
							}
					rup1++;
					rup1o=rup1;
					cnt--;
				}

	//	if
  //	bstate =  inportb(0x505);
		cnt = 16;
		while (((inportb(0x505) &  0x01) != 0) && cnt)  // RX MODEM
				{
				 	rm=inportb(0x507);
					rmc++;
		  //	   printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{			
									if (merc <0xfffe) merc++;
							}
					rm++;
					rmo=rm;
					cnt--;
				}

	  //	if 
	    cnt = 16;
		while(((inportb(0x505) &  0x04) != 0) && cnt)  // RX TRANZIT
				{

				 rtz=inportb(0x509);
					rtzc++;
					if (rtzo!=rtz)
							{
									if (zerc <0xfffe) 	zerc++;
							}
				rtz++;
				rtzo=rtz;
				cnt--;
				}
		

	//	} 

	if (tup0c > 20000)
		{

	 //		ScreenAddString("Send UP0 --");
	//		ScreenAddInt(tup0c);
	 //		ScreenAddString(" RX--");
	//		ScreenAddInt(rup0c);
	//		ScreenAddString(" ERR--");
   //			ScreenAddInt(up0erc);
   //			ScreenIntSent();
   printf("\n\rSend UP0 -- %d  RX-- %d  ERR-- %d\n\r", tup0c, rup0c, up0erc);
			tup0c=0;rup0c=0; up0erc=0;
			}

	if (tup1c>20000)
		{

	  //		ScreenAddString("Send UP1 --");
	  //		ScreenAddInt(tup1c);
	  //		ScreenAddString(" RX--");
	  //		ScreenAddInt(rup1c);
	  //		ScreenAddString(" ERR--");
	  //		ScreenAddInt(up1erc);
	  //		ScreenIntSent();
  	  printf("Send UP1 -- %d  RX-- %d  ERR-- %d\n\r", tup1c, rup1c, up1erc);

			tup1c=0;rup1c=0; up1erc=0;

			}

	if (ttzc>20000)
		{

	   //		ScreenAddString("Send TrZ --");
	   //		ScreenAddInt(ttzc);
	   //		ScreenAddString(" RX--");
	   //		ScreenAddInt(rtzc);
	   //		ScreenAddString(" ERR--");				  
	   //		ScreenAddInt(zerc);
	   //		ScreenIntSent();
   	   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);

			ttzc=0;rtzc=0; zerc=0;
			}
	
	if (tmc>20000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
 	   printf("Send MOD -- %d  RX-- %d  ERR-- %d\n\r", tmc,rmc, merc);

			tmc=0;rmc=0; merc=0;
		}
	

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 //     wd_reset();	

	  my_int_enable_irq0();	   //???? can
	  }
 //	  else
 //	  {
 //	  printf("\n wait interrupt...\n\r");
 //	  }
//}

	//ScreenAddString(" exit to monitor");
	//ScreenIntSent();
//  asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor
}
#define ReadW2 	ReadMPC

#define WriteW2   WriteMPC
#define WriteW   WriteMPC

 unsigned char  WriteSPI (unsigned char spiadr, unsigned char addr, unsigned char data)
{
	 unsigned char q; 
     outportb(0x513,0x02); // rst SPI
	 outportb(0x514,spiadr); // set adr SPI  liu   08,09, 0A,  zl- 0B
	 outportb(0x512,0x7f &  addr   ); // comand WR
	 outportb(0x512,data);
	 outportb(0x513,0x01); //go 
	// delay 10 mks!!
	q=0;
	// while( ( inportb(0x513) || q)< 20 ){  q++;  }
	// if ( q<20)   { q=0;} // bad
	//           else {q=1;}

 t2ms(10);
	return q;
}

 unsigned char  ReadSPi (unsigned char spiadr, unsigned char addr)
{
	 unsigned char q; 
     outportb(0x513,0x02); // rst SPI
	 outportb(0x514,spiadr); // set adr SPI  liu   09, 0A, 0B
	 outportb(0x512, 0x80 | addr   ); // comand RD
	 outportb(0x512,0x00);
	 outportb(0x513,0x01); //go 
	// delay 10 mks!!
	//q=0;
	// while(  inportb(0x513) || q< 20 ){  q++;  } 
	// if ( q<20)   { q=0;} // bad
	//           else {q=1;}
  t2ms(10);
      q= inportb(0x512);
	return inportb(0x512);
}


void runtimeind(unsigned char q)
{
 unsigned int   a;
  unsigned char   alarm_a, alarm_b, ERR_a, ERR_b;

	alarm_a=0; alarm_b=0;
	a=ReadW2(0x0009);
	// захват по тактам
	if  ((a & 0x0001) == 0)  alarm_a=1;
	if  ((a & 0x0002) == 0)  alarm_b=1;
	// синхронизация RSOH
	if ((ReadW2(0x1307) & 0x0005) !=0) alarm_a=1;
	if ((ReadW2(0x1b07) & 0x0005) !=0) alarm_b=1;
	// синхронизация указателей HO-POH   LOP
	if (( ReadW2(0x1420) & 0x0008) !=0) alarm_a=1;
	if ((ReadW2(0x1c20) & 0x0008) !=0) alarm_b=1;
	
	
	ERR_a=0; ERR_b=0;
     if (!alarm_a)
	     {
			// RSOH err BIP8
			if ( ReadW2(0x1302) !=0)  ERR_a=1;
			if ( ReadW2(0x1303)  !=0)  ERR_a=1;
		     if ( ReadW2(0x1381) !=0)  ERR_a=1;
			if ( ReadW2(0x1382) !=0)  ERR_a=1;
	     }
 if (!alarm_b)
	     {
	
		if ( ReadW2(0x1b02) !=0)  ERR_b=1;
		if ( ReadW2(0x1b03) !=0)  ERR_b=1;
		// MSOH err BIP24
		if ( ReadW2(0x1b81) !=0)  ERR_b=1;
		if ( ReadW2(0x1b82) !=0)  ERR_b=1;
		}
	outportb(0x51C, ERR_a*2+alarm_a);
	outportb(0x51D, ERR_b*2+alarm_b);
	
	outportb(0x51e, !(inportb(0x51e)));

   //t  _______________________________________________ b=RXkey();

// ОТОБРАЖЕНИЕ СОСТОЯНИЯ СИСТ ТАКТИРОВАНИЯ
  
	if ( q==0 ) 
		{

	printf("DPLL- %02X   ref- %02X %02X refSEL- %02X", ReadSPi(0x0b, 0x03), ReadSPi(0x0b, 0x05), ReadSPi(0x0b, 0x06), ReadSPi(0x0b, 0x20));
	 //   ScreenAddString("DPLL- ");
	 //	ScreenAddByte(ReadSPi(0x0b, 0x03)); //dpll1 - INT
			//ScreenAddByte(ReadSPi(0x0b, 0x28)); // DPLL1- REAL TIME
	 //    ScreenAddString(" ref- ");
			//ScreenAddByte(ReadSPi(0x0b, 0x02)); //REF FAIL 
	 //		ScreenAddByte(ReadSPi(0x0b, 0x05)); // REF FAIL LOCK REF1(7-4)    , REF0(3-0)
	 //		ScreenAddByte(ReadSPi(0x0b, 0x06)); // REF FAIL LOCK REF3(7-4)    , REF2(3-0)
	 //    ScreenAddString(" refSEL- ");
	 //    	ScreenAddByte(ReadSPi(0x0b, 0x20)); // REFSEL
         // ScreenAddString("TLF KEY = ");
	       // ScreenAddChar(RXkey());// CR
	//     ScreenAddChar(13);// CR
  //	ScreenIntSent();
  
	    }

	}



struct MappADDR
{

 unsigned P : 7; // adres regs
   unsigned C : 5;
   unsigned B : 3;
 unsigned L : 1;
};
union UMappADDR
{
  unsigned  u;
  MappADDR t;
};

struct MappTU
{
   unsigned tu12 :2;
   unsigned tug2 :3;
   unsigned tug3 :2;
   unsigned L : 9;
   
};
union UMappTU
{
  unsigned  int u;
  MappTU t;
};

struct HLXTU
{
   unsigned tug3 :2;
   unsigned tug2 :3;
   unsigned tu12 :2; 
   unsigned L : 9;
};
union UHLXTU
{
  unsigned  int u;
  HLXTU t;
};


 void Start_TestMX155(void)
{
  
  unsigned int i, j,wdata, wadr, pos, z;
 //unsigned int  t_spi_z=0;
  unsigned char b,  Q, ntug3, ntug2, ntug12;
  // unsigned char rup0, rup0o,  rup1, rup1o;
  //unsigned long r;


 UMappADDR MappCh;
 MappCh.t.L=0;

 UMappTU MappSlt;
 MappSlt.t.L=0;

 
  //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
 //	Enable(); // Разрешаем все прерывания

//RETIMER INI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
outportb(0x515,0x0d);   // вкл ретимер
WriteSPI ( 0x0B, 0x1f, 0x02);  // SET  FREE rUN MODE
t2ms(1);
WriteSPI ( 0x0B, 0x1E, 0x05);  // SET REVERT MODE
t2ms(1);
WriteSPI ( 0x0B, 0x23, 0x07);  // SET REVERT MODE for 0,1,2-ch
t2ms(1);

// ini timming source
   outportb(0x51F,0x08);  //REF 0 - stm-0
   outportb(0x520,0x09);   // REF1 - stm-1
   outportb(0x521,0x0d);   // REF2 - ext 2048


 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
// вкл RDY 
//outport(0xffa6,0x81fb); //mmcs
//outport(0xffa8,0xa0bb); //mpcs

// hardware test

//WriteW(0x90000001)
// chip detect
//z= Read(0x90000000);
//ScreenAddByte(z);
//z= Read(0x90000001);
//ScreenAddByte(z);
//t2ms(3);

//ScreenIntSent();
z= ReadMPC(0x00);
//ScreenAddByte(z1);
//ScreenAddString("-- ID OED==6104");
//ScreenIntSent();
printf("\n\r %0X-- ID OED==461", z);

t2ms(100);

WriteW(0x000c, 0x0780);

i=ReadW2(0x06);
//ScreenAddInt(i);

WriteW(0x000c, 0x0000);

WriteW2(0x06, 0x0781);
i=ReadW2(0x06);
//ScreenAddInt(i);
//ScreenIntSent();
printf("\n\r %0X 0x06 : -- 781\n\r", i);
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

// initialisation======================================================



//конфиг LIU

// soft reset LIU  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
WriteSPI ( 0x08, 0x28, 0xff);
t2ms(1);
WriteSPI ( 0x09, 0x28, 0xff);
t2ms(1);
WriteSPI ( 0x0a, 0x28, 0xff);

t2ms(1); // >1 mks

// Jatt TX, auto AIS if LOS
WriteSPI ( 0x09, 0x78, 0x82);
t2ms(1);
WriteSPI ( 0x0a, 0x78, 0x82);
t2ms(1);
WriteSPI ( 0x08, 0x78, 0x82);
t2ms(1);

// off ch №8
WriteSPI ( 0x09, 0x24, 0x01);
t2ms(1);
WriteSPI ( 0x0a, 0x24, 0x01);
t2ms(1);
WriteSPI ( 0x08, 0x24, 0x01);
t2ms(1);


//ScreenAddString("test MX155--ini-spi "); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//ScreenIntSent();
printf("\n\rtest MX155--ini-spi\n\r ");
t2ms(100);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//====================================================================
// OED config
// INT not use

// reset chip   CHIPRST
WriteW2(0x01, 0x001b); //!!
t2ms(10);
WriteW2(0x01, 0x0000);
//reset cdr
WriteW2(0x06, 0x0080);
t2ms(10);
WriteW2(0x06, 0x0781);

// ini chip stm1 mode - MCR reg
WriteW2(0x02, 0x0018); // en h12h4 , 19mhz

// ini cdr selekt clk
WriteW2(0x07, 0x1e0c);
t2ms(10);
WriteW2(0x07, 0x1808); // 155pclk 

// SOP==============================================
//SOPPLE
WriteW2(0x1001, 0x00); // POHloop -off

//SOHCTL - SOH интерфейс
WriteW2(0x1020, 0x0002); // 

//==========================================================
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//RSOH
// on descramler, no ais if MS-TIM, one err in BYTE
WriteW2(0x1300, 0x0004); 
WriteW2(0x1b00, 0x0004); 
//p.123

//RRSTMC -- TIM J0  konfig
// 16byte TIM,   sync,   3 ,  first byte
WriteW2(0x1301, 0x0005); 
WriteW2(0x1b01, 0x0005); 
// p.124

//TSOH
//TRSCTL
// p.128
// on scramler , no MSAIS insert, 16byte J0 from buferr, Z0=55
WriteW2(0x1340, 0x0080); 
WriteW2(0x1b40, 0x0080); 

//TRSd1d2
// p.129
WriteW2(0x1342, 0x7e7e); 
WriteW2(0x1b42, 0x7e7e); 

//TRSd3
// p.129
WriteW2(0x1343, 0x007e); 
WriteW2(0x1b43, 0x007e); 


//TSTOH_EN
// all data from regs
// p.130
WriteW2(0x1345, 0x00); 
WriteW2(0x1b45, 0x00); 

// здесь инициализация рег DEG EXC
// EXC период 10мс
WriteW2(0x1385, 0x000a); 
WriteW2(0x1b85, 0x000a); 
WriteW2(0x1386, 0x0000); 
WriteW2(0x1b86, 0x0000); 

// EXC removal  период 10мс
WriteW2(0x1387, 0x000a); 
WriteW2(0x1b87, 0x000a); 
WriteW2(0x1388, 0x0000); 
WriteW2(0x1b88, 0x0000); 

// EXCdt removal  период 10мс
WriteW2(0x1389, 0x003c); 
WriteW2(0x1b89, 0x003c); 
// excct
WriteW2(0x138a, 0x000f); 
WriteW2(0x1b8a, 0x000f); 

//DEGAPDL   1S
WriteW2(0x138B, 0x03E8); 
WriteW2(0x1b8B, 0x03E8); 
//DEGAPDH   1S
WriteW2(0x138C, 0x00); 
WriteW2(0x1b8C, 0x00); 

//DEGAPRL   1S
WriteW2(0x138D, 0x03E8); 
WriteW2(0x1b8D, 0x03E8); 
//DEGAPRH   1S
WriteW2(0x138E, 0x00); 
WriteW2(0x1b8E, 0x00); 

//DEDT   1500 OF 8000 IN 1S
WriteW2(0x138F, 0x05DC); 
WriteW2(0x1b8F, 0x05DC); 

//DECT   150 OF 8000 IN 1S
WriteW2(0x1390, 0x0096); 
WriteW2(0x1b90, 0x0096); 

//RMSCTL
// EXC DEG enable, word mode, ms-ais ms-rdi 5 frame, 
// p.131
WriteW2(0x1380, 0x006E); 
WriteW2(0x1b80, 0x006E); 

//RAPC
// off   ms protection switch
// p.139
WriteW2(0x139c, 0x00); 
WriteW2(0x1B9c, 0x00);  

//TMSS1   
//  S1  reg 
// 
WriteW2(0x13c9, 0x00); 
WriteW2(0x1Bc9, 0x00);  

//TMS CTL   
// auto rei, auto rdi, S1 from reg 
// p.141
WriteW2(0x13c0, 0x00e0); 
WriteW2(0x1Bc0, 0x00e0);  


//TMS RDI
// rdi set if LOF, LOS,  MS-AIS
// p.143
WriteW2(0x13c1, 0x000e); 
WriteW2(0x1Bc1, 0x000e);  

//TRSd4d5
// p
WriteW2(0x13c4, 0x7e7e); 
WriteW2(0x1bc4, 0x7e7e); 

//TRSd6d7
// p
WriteW2(0x13c5, 0x7e7e); 
WriteW2(0x1bc5, 0x7e7e); 

//TRSd8d9
// p
WriteW2(0x13c6, 0x7e7e); 
WriteW2(0x1bc6, 0x7e7e); 

//TRSd10d11
// p
WriteW2(0x13c7, 0x007e); 
WriteW2(0x1bc7, 0x007e); 


//TRSd12
// p.
WriteW2(0x1348, 0x007e); 
WriteW2(0x1b48, 0x007e); 


//ScreenAddString("test MPC155--ini-soh "); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//ScreenIntSent();
printf("\n\rtest MPC155--ini-soh ");
t2ms(100);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//================================================
// reg PP  конфиг VC4

//RPCTL
// p.146
// BIPword 
WriteW2(0x1400, 0x002a); 
WriteW2(0x1c00, 0x002a); 

//RAIS
// p.147
// AIS if LOP, AIS
// not AIS if EXC DEG  PSLM  PTIM
WriteW2(0x1401, 0x0081); 
WriteW2(0x1c01, 0x0081); 

//RPTMC
// p.150
// J1 TIM - 16, 
// not AIS if EXC DEG  PSLM  PTIM
WriteW2(0x140b, 0x0004); 
WriteW2(0x1c0b, 0x0004); 

//RPEC2
// p.151
// expected  C2 = 02, 
WriteW2(0x140D, 0x0002); 
WriteW2(0x1c0D, 0x0002); 

//TPRDI
// p.151
// E RDI- en
// RDI  if  LOF, LOS, LOP, MSAIS
WriteW2(0x1411, 0x003f); 
WriteW2(0x1c11, 0x003f); 


//RPGCTL
// p.152
// en AU AIS if FIFO over- under- flow
WriteW2(0x1412, 0x0001); 
WriteW2(0x1c12, 0x0001); 

//TPCTL
// p.158
//VC poh tx control
WriteW2(0x1480, 0xf770); 
WriteW2(0x1c80, 0xf770); 

//TPC2
// p.160
//C2 - TUG strukture
WriteW2(0x1482, 0x0002); 
WriteW2(0x1c82, 0x0002); 

//TPf2
// p.160
WriteW2(0x1484, 0x000); 
WriteW2(0x1c84, 0x000); 

//TPf3k3
// p.160
WriteW2(0x1485, 0x000); 
WriteW2(0x1c85, 0x000); 

//=================================================
//== PP -konfig TUG

// RESET TUG3 proc
//stupprst
// p.166
WriteW2(0x3100, 0x0007); 
WriteW2(0x3200, 0x0007); 
WriteW2(0x3300, 0x0007); 
WriteW2(0x3400, 0x0007); 
WriteW2(0x3500, 0x0007); 
WriteW2(0x3600, 0x0007); 
WriteW2(0x3700, 0x0007); 
WriteW2(0x3800, 0x0007); 

WriteW2(0x3100, 0x0000); 
WriteW2(0x3200, 0x0000); 
WriteW2(0x3300, 0x0000); 
WriteW2(0x3400, 0x0000); 
WriteW2(0x3500, 0x0000); 
WriteW2(0x3600, 0x0000); 
WriteW2(0x3700, 0x0000); 
WriteW2(0x3800, 0x0000); 


//STUPPMCR
// p.167
// all TUG3-TUG2 , no bypass, no ais
WriteW2(0x3101, 0x0020); 
WriteW2(0x3201, 0x0020); 
WriteW2(0x3301, 0x0020); 
WriteW2(0x3401, 0x0020); 
WriteW2(0x3501, 0x0020); 
WriteW2(0x3601, 0x0020); 
WriteW2(0x3701, 0x0020); 
WriteW2(0x3801, 0x0020); 

 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);


//ScreenAddString("test MPC155--ini-soh "); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//ScreenIntSent();
printf("\n\rtest MPC155--ini-soh ");
t2ms(100);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 

//=================================================
//== MAPPER -konfig 21e1

// Config OED Mapper 
// reset E1
WriteW2(0x4000,0xfff);
WriteW2(0x4001,0xfff);
t2ms(3);
WriteW2(0x4000,0x00);
WriteW2(0x4001,0x00);

// set err tresholds
// p.177-180
// 40 ms
WriteW2(0x4002,0x0050); //excap 
// 10-3  , half of 80 suprframe
WriteW2(0x4003,0x0028);
// 40 ms
WriteW2(0x4004,0x0050);
// 10-4    one in ten 
WriteW2(0x4005,0x0008);
// 4 sec
WriteW2(0x4006,0x1f40);
//
WriteW2(0x4007,0x0000);
// 1 in 100 of 8000 suprframe
WriteW2(0x4008,0x0050);
// 4 sec
WriteW2(0x4009,0x1f40);
//
WriteW2(0x400a,0x0000);
// 1 in 1000 of 8000 suprframe
WriteW2(0x400b,0x0008);

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

// расписание слотов для 21 потока
// прямое распределение каналов Е1 для линий 16 и 17
t2ms(3);
 MappCh.t.B = 4;
 MappCh.t.P=0x00; // TUTSCFG
 MappCh.t.C=0x01; 
 Q=1;
 MappSlt.t.tug3=1;
  for (i=1; i<8;  i++)
      for (j=1; j<4; j++)
           {
               MappSlt.t.tug2=i; MappSlt.t.tu12=j;
               WriteW2(MappCh.u, MappSlt.u*256+MappSlt.u); 
             Q++;
                MappCh.t.C=Q;
             }

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

// CCR p.183
// шлейфы и AIS По Е1
MappCh.t.P=0x01; // CCR
for (Q=1; Q<22; Q++)
 {
    MappCh.t.C = Q;
    WriteW2(MappCh.u, 0x00c1);  
}
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 // PPSCR
// SNCP
//// force master
MappCh.t.P=0x02; // PPSCR
for (Q=1; Q<22; Q++)
 {
    MappCh.t.C = Q;
    WriteW2(MappCh.u, 0x001);   // force master
}

 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//REVCFG 
// retimm off, 512 fifo
// p186
MappCh.t.P=0x04;
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0000);  
 }


// TANCFGA
//p195
// POH tx config E1 - auto RDI if AIS LOP
// auto ERDI en
MappCh.t.P=0x40;
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0003);  
 }
// TANCFGB
MappCh.t.P=0x41;
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0003);  
}

// установка path label 010 -асинхр  е1
MappCh.t.P=0x42; // tv5k4lina
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0004);  
 }
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
MappCh.t.P=0x44; // tv5k4linb
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0004);  
}

//  PRBSCFG
// prbs analis on, PRBS, 127, 0.25
MappCh.t.P=0x60;
for (Q=1; Q<22; Q++)
 {
  MappCh.t.C = Q;
  WriteW2(MappCh.u, 0x0042);  
 }
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//=============================================================

// Config OED HLX(p199)
 WriteW2(0x6000,0x03); // set page 1

//здесь нужна задержка на переключение мин 125 мкс
t2ms(2);
//cross
// HLXCR0-17
// 
// p201
WriteW2(0x6002, 0x0000);  //line-0  LOW order
WriteW2(0x6003, 0x0060);  //line-1  idle
WriteW2(0x6004, 0x0060);  //line-2  idle
WriteW2(0x6005, 0x0060);   //line-3  idle
WriteW2(0x6006, 0x000);  //line-4    LOW order

WriteW2(0x6007, 0x0060);   //line-5 
WriteW2(0x6008, 0x0060);   //line-6 
WriteW2(0x6009,0x0060);   //line-7 
WriteW2(0x600a, 0x0060);   //line-8 
WriteW2(0x600b, 0x0060);   //line-9 
WriteW2(0x600c,0x0060);   //line-10 
WriteW2(0x600d, 0x0060);   //line-11 
WriteW2(0x600e, 0x0060);  //line-12 
WriteW2(0x600f, 0x0060);   //line-13 
WriteW2(0x6010, 0x0060);  //line-14 
WriteW2(0x6011, 0x0060);   //line-15 

WriteW2(0x6012, 0x0000);  //line-16  LOW order
WriteW2(0x6013, 0x0000);  //line-17 LOW order

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//  control mem
// 28672+№MEM*128+PAGE*64+СТРОКА =28672+0+0+СТРОКА=0x7000+...
//28672+16*128+0+СТРОКА=30720+..=0x7800+...
// инициализация IDLE кодом

  WriteW2(0x6000,0x03); // set page 1
t2ms(2);
// fill IDLE  MEM page 0
 for (j=0; j<18; j++)
   for (i=0; i<64; i++)
  {  WriteW2(0x7000+128*j+i,0x820);}
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

  WriteW2(0x6000,0x01); // set page 0
t2ms(2);
// fill IDLE  MEM page 1
 for (j=0; j<18; j++)
   for (i=0; i<64; i++)
  {  WriteW2(0x7040+128*j+i,0x820);}

  WriteW2(0x6000,0x03); // set page 1
t2ms(2);
 
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//===========================================================
// INI opto
outportb(0x51A,0x01);   // вкл opto
outportb(0x51B,0x01);   // вкл opto
//=======================================================



// подключение маппера к STM потокам 



// control mem line 0 - берем данныес линии 16
   WriteW2(0x7000,0x000); // POH VC-4 =4
ntug3=1;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++) 
  { 
   pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
   wdata = 32*pos + 16; // 0- loop    16 - from mapper
   wadr=0x7000+pos;
   WriteW2(wadr,wdata);
 }
}

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
ntug3=2;

for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
 {
  pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
  wdata = 0x820; //idle code
  wadr=0x7000+pos;
  WriteW2(wadr,wdata);
}


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
}

ntug3=3;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	 {
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	  wadr=0x7000+pos;
	  wdata = 0x820; // idle code
	  WriteW2(wadr,wdata);
	}
}
//-----------------------------------------------

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
// control mem line 4


   WriteW2(0x7200,0x0004); // POH VC-4 =0
ntug3=1;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	  {
	  pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7200+pos;
	  wdata = 32*pos + 16;  // 17- loop    0 - from mapper
	  WriteW2(wadr,wdata);
	}
}


ntug3=2;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	{ 
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7200+pos;
	  wdata = 0x820; //idle code
	  WriteW2(wadr,wdata);
	}
}


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
ntug3=3;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	 {
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	  wadr=0x7200+pos;
	  wdata = 0x820; // idle code
	  WriteW2(wadr,wdata);
	}
}



// control mem line 16


   WriteW2(0x7800,0x0000); // POH VC-4 =4
ntug3=1;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	  {
	  pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7800+pos;
	  wdata = 32*pos + 0;  // 16- loop    0 - from mapper
	  WriteW2(wadr,wdata);
	}
}


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
ntug3=2;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	{ 
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7800+pos;
	  wdata = 0x820; //idle code
	  WriteW2(wadr,wdata);
	}
}

ntug3=3;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	 {
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	  wadr=0x7800+pos;
	  wdata = 0x820; // idle code
	  WriteW2(wadr,wdata);
	}
}


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
// control mem line 17


   WriteW2(0x7880,0x0004); // POH VC-4 =0
ntug3=1;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	  {
	  pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7880+pos;
	  wdata = 32*pos + 0;  // 16- loop    0 - from stm
	  WriteW2(wadr,wdata);
	}
}

ntug3=2;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	{ 
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	   wadr=0x7880+pos;
	  wdata = 0x820; //idle code
	  WriteW2(wadr,wdata);
	}
}

ntug3=3;
for (ntug2=1; ntug2<8; ntug2++)
{
  for(ntug12=1;ntug12<4; ntug12++)
	 {
	 pos=21*(ntug12-1) + 3*(ntug2 -1) + ntug3;
	  wadr=0x7880+pos;
	  wdata = 0x820; // idle code
	  WriteW2(wadr,wdata);
	}
}


//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

  WriteW2(0x6000,0x01); // set page 0


 WriteW2(0x139c,0x0010); // MSPP


// SLUG KANAL

//WriteW2(0x1020,0x0102); // rising
outportb(0x509,0x8c); // DDC in D4 ch A
outportb(0x50a,0x8c); // DDC in D4 ch b
outportb(0x507,0x96); //  TLF in E2 ch A
outportb(0x508,0x96); //  TLF in E2 ch b


  WriteW2(0x1345,0x0020); // D4
  WriteW2(0x1b45,0x0020); //  D4

// timming---------------------------------------------------------------------------------------------------------
outportb(0x515,0x0d);   // вкл ретимер
  
WriteSPI ( 0x0B, 0x1f, 0x02);  // SET  FREE rUN MODE
t2ms(1);

// ini timming source===================================================================
 outportb(0x51F,0x08);  //REF 0 - stm-0
outportb(0x520,0x09);   // REF1 - stm-1
 outportb(0x521,0x0d);   // REF2 - ext 2048

// outportb(0x51F,0x0a);  //e1 1
 // outportb(0x520,0x0b);   //e1  8
 // outportb(0x521,0x0c);   // e1 15

// ScreenAddString(" rd- ");
//		ScreenAddByte(ReadSPi(0x0b, 0x1e)); //REF FAIL 
//		ScreenAddByte(ReadSPi(0x0b, 0x1f)); // REF FAIL LOCK REF1(7-4)    , REF0(3-0)
//		ScreenAddByte(ReadSPi(0x0b, 0x23)); // REF FAIL LOCK REF3(7-4)    , REF2(3-0)
//     ScreenAddString(" refSEL- ");
//     	ScreenAddByte(ReadSPi(0x0b, 0x24)); // REFSEL
//	ScreenAddByte(ReadSPi(0x0b, 0x25)); // REFSEL
//     ScreenAddChar(13);// CR
//ScreenIntSent();

printf("\n\r rd- %02X. %02X. %02X refSEL- %02X. %02X\n\r", ReadSPi(0x0b, 0x1e), ReadSPi(0x0b, 0x1f), ReadSPi(0x0b, 0x23), ReadSPi(0x0b, 0x24), ReadSPi(0x0b, 0x25));
t2ms(200);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h};  // -- exit to monitor
//wrconfig_io(0x80000000, 0x51f);
//wrconfig_io(0x80000000, 0x520);
//wrconfig_io(0x80000000, 0x521);

//*********************************************************************************************************************************

//t     __________________________________________________________INIDUSLIC();
//utport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
t2ms(100);
// b=RXkey();
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h};  // -- exit to monitor


//ScreenAddString("внутренний генератор  ");
//	 ScreenAddChar(13);// CR
//	 ScreenIntSent();

printf("internal generator  \n\r");

while( embRS232.UsedReceive()==0)
	{
      	 runtimeind(b);
           t2ms(200);
           if(b++==10 ) b=0;
	 }

for(b=0; b<255; b++)
{
if( embRS232.UsedReceive() !=0) z=embRS232.Receive();
}

outportb(0x515,0x0f);   // вкл ретимер auto  MODE
WriteSPI ( 0x0B, 0x1f, 0x03);  // SET auto  MODE
t2ms(1);

printf("\n\r change source       f ref   stm1-0   stm1-1   ext2048");
//ScreenAddString("смена опоры       f ref   stm1-0   stm1-1   ext2048  ");
//	 ScreenAddChar(13);// CR
 //	 ScreenIntSent();
while( embRS232.UsedReceive()==0)
	{
      	 runtimeind(b);
      t2ms(200);
        if(b++==10 ) b=0;
	 }

for(b=0; b<255; b++)
{
if( embRS232.UsedReceive() !=0) z=embRS232.Receive();
}

printf("\n\r change source    f ref   E1 №№  1 , 8, 15 ");
//ScreenAddString("смена опоры    f ref   E1 №№  1 , 8, 15 ");
//	 ScreenAddChar(13);// CR
//	 ScreenIntSent();
 outportb(0x51F,0x0a);  //e1 1
 outportb(0x520,0x0b);   //e1  8
 outportb(0x521,0x0c);   // e1 15

while( embRS232.UsedReceive()==0)
	{
     
	 runtimeind(b);
      t2ms(200);
      
      if(b++==10 ) b=0;

    }


outportb(0x515,0x0d);   // вкл ретимер FREE rUN MODE

WriteSPI ( 0x0B, 0x1f, 0x02);  // SET  FREE rUN MODE
t2ms(1);

printf("\n\r change source  - internal generator    \n\r exit to monitor\n\r ");

//ScreenAddString("смена опоры  - внутр генератор     ");


 //ScreenAddString(" exit to monitor");
  //   ScreenAddChar(13);// CR
   //  ScreenIntSent();



t2ms(200);
 // asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h};  // -- exit to monitor
}




