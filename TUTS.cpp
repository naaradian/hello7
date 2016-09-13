//#ifndef __TINY__
//#define __TINY__
//#endif
#include "start.h"
#include "hello7.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
#define IncEmbRS232
//#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
//#define IncEmbSerialMF20
////////////////////////////////////////////
//#include "longtoa.cas"
//#include "Ltoa1.c"
//#include "stdlib.h"
//#include "command.h"
//#include "embisr.cpp"
#include "embisr.h"
//#include "basic'.h"
//#include "basic'.cpp"
//#include "mul_div.cpp"
//it need init!!!!!!!!!!!!!
//#include <string.h>
//#include <stdlib.h> //for strtod
//#include "mqx_inc.h"
#include "fio.h"
//#include "pcb.h"
//#include "message.h"
//#include "serial.h"
//#define SIZETX0MF  (1000)
#define TYPES_OF_BLOCKS (32)
#define HEADER (32)
#define CARDINSLOT (16)
#define CARDE1 (32)
#define CARDDATA (1024)


//extern  int ecount2;



//_______________________________________________________________
struct sendcash
{
	unsigned long cnum;
	unsigned long as;
	unsigned long ai;
	unsigned long ar;
};

class buffcash
{
 public:
   sendcash buffc[CASHE_SIZE];	
   char compare(unsigned long , unsigned long , unsigned long , unsigned long , unsigned long);
   void add(unsigned long , unsigned long , unsigned long , unsigned long );
   void init(void);
};

void buffcash::init(void)
{

for(long i = 0; i < CASHE_SIZE; i++)
{
 buffc[i].cnum = 0;
 buffc[i].as = 0;
 buffc[i].ai = 0;
 buffc[i].ar = 0;
}
}

char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc, unsigned long isrs485)
{

#ifdef CASHE_OFF
return 0; //test
#endif


for(long i = 0; i < CASHE_SIZE; i++)
{
    if(buffc[i].cnum == numloc)
   {
   if(buffc[i].as == asloc)
   {
   if(buffc[i].ai == ailoc)
    {
	 if((buffc[i].ar == arloc)	|| 	(!isrs485))
    {
     return 1;}
	}
	}
	}
}
 return 0;
}
void buffcash::add(unsigned long num, unsigned long as, unsigned long ai, unsigned long ar)
{
for(long i = (CASHE_SIZE - 1) ; i > 0; i--)
{
 buffc[i].cnum = buffc[i-1].cnum;
 buffc[i].as = buffc[i-1].as;
 buffc[i].ai = buffc[i-1].ai;
 buffc[i].ar = buffc[i-1].ar;

}
 buffc[0].cnum = num;
 buffc[0].as = as;
 buffc[0].ai = ai;
 buffc[0].ar = ar;
}

//buffcash buff_cashe_request;
//_______________________________________________________________




template<class T,int Size>  void TRBuffer<T,Size>::Init()
{
   BuffSize = Size;	 //have variable  sizes of buffer!!!!!!!
   Head = 0l;
   Tail = 0l;
}

template<class T,int Size>  void TRBuffer<T,Size>::Add(T elem)
{
//   Buff[Head++] = elem;
//   if(Head > BuffSize)
//   {
//    Head = 0l;
//   }

  Buff[Head] = elem;
  Head++;
  if(Head == BuffSize) Head = 0;
}

template<class T,int Size> T TRBuffer<T,Size>::Get()
{
  
//t  if(++Tail < BuffSize) return Buff[Tail-1];
  Tail++;	 //t
    if(Tail == BuffSize)
   {
	 Tail = 0l;  //test!!!!!!!!!!!!!!!!!!!
     return Buff[BuffSize-1];
   }
 //t Tail = 0l;
  else
  {
   return Buff[Tail-1];	  //t
  }
}

template<class T,int Size>  unsigned TRBuffer<T,Size>::Used()
{
//t  int n = Head - Tail;
  signed short int n = Head - Tail;	//t
  if( n >= 0 ) return (unsigned)n;
  else return (unsigned)(n+BuffSize);
}

template<class T,int Size> unsigned TRBuffer<T,Size>::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}








 struct MF20CFG
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
};

//unsigned char debug_byte=0;
//unsigned debug_word=0;
////  СТРУКТУРА ЭНЕРГОНЕЗАВИСИМОГО ОЗУ  ////
// Объем энергонезависимого ОЗУ = 32К
//to port unsigned char  *ptrENVram = (unsigned char *)0x80001000;
//to port MF20CFG *mf20cfg = (MF20CFG *)0x80000000;
//unsigned char  *ptrENVram = (unsigned char *)0x10001000;  //to port
MF20CFG *mf20cfg;//to init!!!! = (MF20CFG *)0x10000000; //to port ???	cs0	 //need INIT!!!!!!!	 in any startup functions!!!

////  СТРУКТУРА файла конфигурации  ////
///////////////////////////
//  0x00000000 - 0x0000001F - Header [16 bytes]
// "MF20[Имя конфигурации:12][дата создания:6][время создания:8]00"
///////////////////////////
//  0x00000020 - 0x0000002F - типы плат [16 bytes]
///////////////////////////
//  0x00000030 - 0x0000004F - распределение потоков Е1 по платам Е14 и Е12 [32 bytes] = 20h
///////////////////////////
//struct EmbCardMf20_E1
//{
//  unsigned char slot;  
//  unsigned char numE1; 
//};
///////////////////////////
//  0x00000050 - 0x0000044F - место хранения "зеркала" 64-ти портов 16-ти плат MF20 [1024]
///////////////////////////
//  0x00000450 - 0x00000C49 - 16 структур коммутатора объединяющих значения 128*16 [линия/позиция] [2048]
///////////////////////////
// После изменения любой позиции перестраивать всю матрицу коммутации
//////////////////////////////////////////////////////
// Параметры синхронизации
// 0x00000С50 - 0x00000С58
//unsigned char mainModeSync = (unsigned char far*)0x00000С50; 
//unsigned char mainNumSync = (unsigned char far*)0x00000С51; 
//unsigned char mainSourceSync = (unsigned char far*)0x00000С52; 
//unsigned char resrNumSync = (unsigned char far*)0x00000С53; 
//unsigned char resrSourceSync = (unsigned char far*)0x00000С54; 
// 0х0000FFFC - 0x0000FFFF - CRC [4 байта]
// Окончание распределения энергонезависимой памяти //
//////////////////////////////////////////////////////
// port const NUM_OF_SLOT = 16;
#define  NUM_OF_SLOT  16


//extern "C" void StartSaveCommut(void);
extern unsigned char CurSlot;	
extern char TBuff0mf[SIZETX0MF];
extern char *  pTBuff0mf;
extern unsigned long TBuff0mf_cnt;
extern "C" void Transmit0mf();
extern "C" void my_printf(unsigned char);
extern "C" unsigned SelfVer1(void); 
extern "C" unsigned SelfVer2(void); 
extern "C" unsigned SelfYear(void); 
extern "C" unsigned SelfID(void); 
extern uint_32 TimerCounter;
extern "C" void MessageChar(unsigned char , unsigned char , unsigned char);
extern "C" void MessageLong(unsigned char , unsigned char , unsigned char);
extern "C" void Ring(unsigned char , unsigned char , unsigned char,  unsigned char );

unsigned char ascii[]={
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
unsigned char Modify5A(unsigned char byte)
{
	switch(byte)
	{
		case 0x00: return 0x5A;
		case 0x01: return 0x55; 
		case 0x02: return 0xA5; 
		case 0x03: return 0xAA; 
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
 //	unsigned short CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }


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
	unsigned char typeOfProtocol;
};

void EmbMsg::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

//void EmbMsg::Init(unsigned char p)
void EmbMsg::Init(void)
{
//	typeOfProtocol=p; 
	typeOfProtocol=2; 

	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
  //	readyToSend=0;
}

unsigned short EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsg::IsEnd()
{
	if(typeOfProtocol==2)
	{
		if(body[0]) if(counter>10) if(counter==Length()+13)	return 1;
	}
	if(typeOfProtocol==1) if(body[counter]=='!') return 1;

	return 0;
}

unsigned short EmbMsg::ChkCRC()
{
  int i;
	unsigned short c=0, b=0;
	if(typeOfProtocol==2)
	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
	}
	else return 0;
}

unsigned short EmbMsg::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(typeOfProtocol==2)
	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			body[Length()+11]=(c>>8)&0xFF;
			body[Length()+12]=c&0xFF;
			return c;
		}
		else return 0;
	}
	else return 0;
} 

unsigned short EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}


 /*
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
   */
/////////////////////
struct EmbMsgBuffer
{
    unsigned BuffSize;
    unsigned Head;
    unsigned Tail;
    EmbMsg Buff[16];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned Used();
    unsigned Free();
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

unsigned EmbMsgBuffer::Used()
{
  int n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
}

unsigned EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}



void Enable()
{
// asm { sti }
}
void Disable()
{
// asm { cli }
}

union l2i
{
  unsigned long ul;
	unsigned u[2];
};

union l4c
{
  unsigned long ul;
	unsigned char uc[4];
};

union UL_UI
{
  unsigned long l;
  unsigned short i[2];
};

EmbTimerCallback embTimerCallback0;

unsigned long time1=0,time2=0,time3=0,timeRing=0,timeRing2=60;

void Callback0()
{
  time1++;
  time2++;
  time3++;
}

// п п определения установки слотов и их типов
// 
// результат-заполнение 2 массивов : type_slot[16] , slot_stand[16]

//коды команд от CP  (7-2 биты)
#define RX_LEVEL       0x84
#define TX_LEVEL       0x88     //0x88
#define SET            0x80
#define ECHO_COMP      0x8C
#define RD_STATUS      0x90  

//адреса регистров перифирии
#define INTFLL         0x04      //регистр флагов событий
#define MAILBOX        0x07      //порт обмена с TF каналами
#define IDENTL         0x02      //идентиф номер блока-TYPE 
#define MIRROR         0x00

#define HIGH_ADR_BASE  0x01      //старший байт адресной базы
#define LOW_ADR_BASE   0x00      //младший байт адресной базы
#define BASE_ADR_PORT  0x0500    //базовый адрес внешних портов 
/* port
unsigned char Delay_Break=0;

void Delay(unsigned ms)
{
  Delay_Break=0;
  unsigned long tmp_timer=0;
  tmp_timer = time1;
  while(time1-tmp_timer<ms)
    if(Delay_Break)
    {
      Delay_Break=0;
      break;
    }
}
 */
////////////////  E12 - E14  /////////////////
	EmbMsg *embMsgRequest;
//	EmbMsgBuffer rBuffEmbMsg;
	EmbRS232 embRS232;
 	EmbMsg embMsg;	  //new
	EmbMsg embMsg232E;
	EmbMsg embMsgAns; //new
    EmbMsg embMsg485;
	EmbMsg embMsg485E;

	unsigned aI, aS, aR;
 //	int i232;
  //	int i485;		//my
    unsigned char flagRequest; //=0;
 	unsigned addr1;	
	unsigned char * bt;	
//_____________________________________________<<from bmd_34

	EmbRS485 embRS485;
 //t1024	EmbIndicator embIndicator;
////////////////////////
//port	EmbNMI2 embNMI2;
	EmbTimer embTimer;
////////////////////////


void Restore()
{
  unsigned i;
  for(i=0; i<NUM_OF_SLOT; i++)
  {
		

  }
}


////////////////////////////////////
//   Запись в виртуальные порты   //
////////////////////////////////



char *add_str(char *target, char *source)
{
	int j=0,i=0; 
	while(target[i]) i++;
	while(source[j]) target[i+j]=source[j++];
	return target;
}

void SetWatchDog()
{
//	outport(wdtcon,0x3333);
//	outport(wdtcon,0xCCCC);
//	outport(wdtcon,0xC080);
}

void DisableWatchDog()
{
//	outport(wdtcon,0x3333);
//	outport(wdtcon,0xCCCC);
//	outport(wdtcon,0x0000);
}

void ResetWatchDog()
{
//	outport(wdtcon,0xAAAA);
//	outport(wdtcon,0x5555);
//	unsigned x = inport(piodat0);
//	outport(piodat0,x^0x1000);
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

unsigned char HexChar(unsigned char s)
{
  if(s<=9) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 0;
}

unsigned pt_key=0;
unsigned char sync_slot=0;
unsigned long counterErrPSP=0;

int state;


unsigned char PT_NULL    = 0;
unsigned char PT_ERR1    = 1;
unsigned char PT_ERR2    = 2;
unsigned char PT_ERR_PSP = 3;
unsigned char PT_CTRL    = 4;
unsigned char PT_RING    = 5;
unsigned char PT_SOUND   = 6;
unsigned char PT_ADDR    = 7;
unsigned char PT_POINT   = 8;
unsigned char PT_TYPECARD= 9;
unsigned char PT_TYPECARDCHANGE = 10;
unsigned char PT_NUM_E1 = 11;
unsigned char PT_NUM_E1_CHANGE = 12;


unsigned char ST_NORMA	= 0;
unsigned char ST_LOOP	= 1;
unsigned char ST_ERROR1	= 2;
unsigned char ST_ERROR2	= 3;
unsigned char ST_SEARCH	= 4;
unsigned char ST_FAULT	= 5;
unsigned char ST_ALARM	= 6;

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


union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
 //port 	unsigned char uc[2];
  unsigned char uc[4];  //port

};

   UnEmb2TypeVer unEmb2TypeVer;  //new
   UL2UC ul2uc;
   UI2UC ui2uc;
   unsigned char mode5A; 
   unsigned char mode5A232E;
   unsigned char mode5A485;
   unsigned char mode5A485E;

//void main()
extern "C" void TUTS_init()
{
	unsigned i=0;//, j=0;
	mode5A=0;
    mode5A232E=0;
    mode5A485=0;
    mode5A485E=0;

 //_______________________________>> from bmd_34
   flagRequest=0;

 //  rBuffEmbMsg.Init();
 //  buff_cashe_request.init(); //cashe

 //_______________________________<< from bmd_34
  //	EmbMsg embMsg;
  //	EmbMsg embMsgAns;
 // have as global 	EmbRS232 embRS232;
    mf20cfg = (MF20CFG *)0x10000000; //init pointer to NVRAM
	time1=0,time2=0,time3=0,timeRing=0,timeRing2=60;   
	pt_key=0;
	sync_slot=0;
    counterErrPSP=0;
	PT_NULL    = 0;
 	PT_ERR1    = 1;
 	PT_ERR2    = 2;
	PT_ERR_PSP = 3;
 	PT_CTRL    = 4;
 	PT_RING    = 5;
 	PT_SOUND   = 6;
 	PT_ADDR    = 7;
 	PT_POINT   = 8;
 	PT_TYPECARD= 9;
 	PT_TYPECARDCHANGE = 10;
 	PT_NUM_E1 = 11;
 	PT_NUM_E1_CHANGE = 12;
 	ST_NORMA	= 0;
 	ST_LOOP	= 1;
 	ST_ERROR1	= 2;
 	ST_ERROR2	= 3;
 	ST_SEARCH	= 4;
 	ST_FAULT	= 5;
 	ST_ALARM	= 6;

  sprintf(ser_num,"%s","%000000000000000000.");
	pTBuff0mf = &TBuff0mf[0];
	TBuff0mf_cnt = 0;
	AsciiInit();
	EmbInit();
 //	embRS232.Init(384);
 //	embRS485.Init(384);
	
	embTimer.Init(100); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

 //	mf20TimerBufferTLF.Init();

	for(i=0; i<16; i++)
	{
	  unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
 	  unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
 //	  unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = i; //for test
	}
  //for TUTS
	unEmb2TypeVer.emb2TypeVer.type       = 0x0402;
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();
 //tuts
	TUTS_IO_Init();

  unEmb2TypeVer.emb2TypeVer.signature_hardware[15] =  read_nvram_char(RESTARTS_NVRAM_ADDRESS);
 write_nvram_char(RESTARTS_NVRAM_ADDRESS, (unEmb2TypeVer.emb2TypeVer.signature_hardware[15] + 1));

 }
//signature hardvare
//3-0 : current inputs state
//7-4 : triggered inputs state
//8: outputs state
extern "C" void SetHardvareOuts(unsigned char set)
{
   unEmb2TypeVer.emb2TypeVer.signature_hardware[8] = set;
}

extern "C" void SetHardvareInps(unsigned long curval)
{
  unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = (char)curval;
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = (char)curval;	
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = (char)curval;    
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = (char)curval;
}

extern "C" void SetHardvareTrInps(unsigned long curval)
{
  unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = (char)curval;
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = (char)curval;	
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = (char)curval;    
  curval >>= 8;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = (char)curval;
}


 
extern "C" void TUTS()
//	while(1)
	{
 //	static char cnt06;

static unsigned char byte; 
static unsigned short i=0;//, j=0;
//static unsigned char mode5A=0; 



  //	unsigned char  *addrRAM;
//static unsigned short shift;
static unsigned long shift;
static  unsigned short len;
static  unsigned short temp_crc;
static  unsigned char cycle;
unsigned long tmp;
static unsigned char test = 0;
//_________________________>> from bmd_34
//i232=0;
//_________________________<< from bmd_34
   		while(embRS232.UsedReceive())
 		{
	//	printf("1");

  			byte = embRS232.Receive();
  			switch(byte)
			{
			case 0x55: 
				embMsg.Init();
			 //	my_printf(byte);
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg.Init(); 
				break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; 
		 //	  MessageChar(1,2,2);

			break;
			default:
				if(mode5A) 
				{
	   				embMsg.Add(Modify5A(byte));
					mode5A=0;
				}
				else 
				{
    		 //	   MessageChar(1,1,4);
  	               embMsg.Add(byte);
				}
			}  // switch byte
		  
//___________________________________________________________>>> from bmd_34
			if(embMsg.IsEnd()) 
				break;
  //			if(++i232> 10) break;
		}	 //while
  		if(!embMsg.IsEnd()) // t
		{
//_______________________________________________________________232e
//	   if(!embMsg232E.IsEnd()) // t
	   if(1)
 {
//_______________________________________________________________232e

			while(embRS485.UsedReceive())
			{
			  //	printfpd(" %02X", byte);
	  //		printf("3");

		  //ok 	my_printf(0x22);	 //t
				byte = embRS485.Receive();
		   //		printfpd(" %02X", byte);

			   //		printf("_____________485:");
		  	   //		my_printf(byte);	//t
			//	  printf(" %02X",byte);
				switch(byte)
				{
				case 0x55: embMsg485.Init();  break; 
				case 0xAA: embMsg485.Init(); 
			 //	 printfp("\n\r ");
				 break; // Пакет
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
//if(!embMsg485E.IsEnd())	  //t091225
		{
			while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
			 //	printfpd(" %02X", byte);
			   	switch(byte)
				{
				case 0x55: embMsg485E.Init();//  printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485E.Init(); 
				//printfp("\n\r "); // printf("\n\r++++");
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
			  {	//   printf("\n\r", byte);
				   			 //	return; //t	091225
			      				break;}
			} //embrs485 usedReceive
	}  //	!embMsg485.IsEnd
 }  //	!embMsg.IsEnd
}
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
   if(embMsg485E.IsEnd()) 
				{
				  
				//need check!	else //my 090503

					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
			   	 //	  printf("2");
			 //   	 static int ecount2 = 0;
  	 	   	 // 		printf("\n\r> %ld",++ecount2);

				   //		if(embMsg485E.AddrS()==SelfID())
					//	{
				   	 //	  printf("3");
   	 		   //		static int ecount3 = 0;
  	 	   	 //		printf(" - %ld",++ecount3);	


						// ->>	// Транзитом ответ в линию
						   				 //  		  printf("5");

								// ->>	// Получили запрос из Ethernet
	  //!!!!!!!!!							flagRequest=3;
							//	printf(" s4");
	//  	 static int ecount1 = 0l;
   //	   	 printf("\n\r>P %d",++ecount1);	   //ttttttt

							    	if(embMsg485E.ChkCRC() && ((embMsg485E.AddrS()==SelfID()) || (embMsg485E.AddrS()== 0) ) )
									{
//  	    static int ecount1 = 0l;
//	   	 printf("\n\r>P %d",++ecount1);	   //ttttttt



										flagRequest=4;
										embMsg485E.SetRS485();
										embMsgRequest = &embMsg485E;
									}
									else
									{
									   flagRequest=0;
									   embMsg485E.Init();
									}
		
					  //	}  //s != self
					}	//r != S
					else
					{
					  flagRequest=0;
					  embMsg485E.Init();
					}

				}  //embrs485E.isend
 		 else //10.24
 			if(embMsg485.IsEnd()) 
				{

// static int ecount3 = 0l;
  //				  	 printf("\n\r>485 %d",++ecount3);	   //ttttttt

//_______________________________________________________________________
//hier betveen msg can receive from ethernet with disabling - no data will be added to end of buffer
//_______________________________________________________________________

				  					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
					   
						// ->>	// Транзитом ответ в линию
						  								// ->>	// Получили запрос из RS-485
									if(embMsg485.ChkCRC() && ((embMsg485.AddrS()==SelfID()) || (embMsg485.AddrS()== 0) ) )
								//	if(embMsg485.ChkCRC() && (embMsg485.AddrS()==SelfID()) )
						 			{
									   	flagRequest=3;
										embMsg485.SetRS485();
										embMsgRequest = &embMsg485;
									}
									else
									{
									   flagRequest=0;
									   embMsg485.Init();

									}

					}	  //
					else
					{
					  flagRequest=0;
					  embMsg485.Init();
					}

					
	 			}

	  else //10.24
	  //		if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
	  if(embMsg.IsEnd())//&&embMsg.ChkCRC())

			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg;
					flagRequest=1;
				//	my_printf(0x20);   //t
				}
			}
//________________________________________________________________________232e			
//________________________________________________________________________232e	
 					   



			if(flagRequest)//embMsgRequest->IsEnd())
			{
	   //		printf("\n\r %d",flagRequest);
		
		   	 //	my_printf(0x21);   //t
				if(embMsgRequest->AddrI() != SelfID())  //110405  do not receive self answers
				{
				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
 //090706		 	  	   if(embMsgRequest->ChkCRC()) //090121	 NEED Recomment!
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//hier can use cache!!!!
//#ifndef ANSWER_OLWAIS
//090706					 if(buff_cashe_request.compare((unsigned long)embMsgRequest->body[1], (unsigned long)embMsgRequest->AddrS(), (unsigned long)embMsgRequest->AddrI(), (unsigned long)embMsgRequest->AddrR(), (unsigned long)embMsgRequest->IsRS485()) != 1)
//#else  //ANSWER_OLWAIS
   			//   	  	 if(1)	//crc checked up
//#endif //ANSWER_OLWAIS
   			   		{
//#ifndef ANSWER_OLWAIS
//   	   	 	  	  	buff_cashe_request.add(embMsgRequest->body[1], embMsgRequest->AddrS(), embMsgRequest->AddrI(), embMsgRequest->AddrR());
//#endif //ANSWER_OLWAIS
 
 //t090205				{
				 
			  //_______________________________________________________________
	   //		   if(!(embMsgRequest->ChkCRC()))
	   //		   {
	   //				 printf("\n\r crc is not correct! :");
	   //				for(long ip=0; ip<embMsgRequest->FullSize(); ip++) 
	   //	 			 {
	   //	   			   printf(".%0X",	embMsgRequest->body[ip]);
	   //		 		 }
	   //		   }
		 //	  printf("\n\r  Len : %X  11: %X 12 : %X", embMsgRequest->Length(), embMsgRequest->body[embMsgRequest->Length()+11],  embMsgRequest->body[embMsgRequest->Length()+12]);

		   //	 	  printf("\n\r CRC: %X ChkCRC: %X CalcRC : %X", embMsgRequest->CRC(), embMsgRequest->ChkCRC(),embMsgRequest->CalcCRC());
		


				  //_______________________________________________________________


					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
				   	// 	my_printf(0x23); //t
					  
				   //	 	if(flagRequest!=3)
						//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

				   //			RS485_disable_RX_interrupt();

							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					 //			 printf(".AA");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					  //30		   printf(".%02X",	embMsgRequest->body[i]);
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
						//	printf("\n\r Used 3");

						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
					 //	  }
					//    }
//____________________________________________________________________________________RDN  <<
  							flagRequest = 0;
						}	   //!= 3 != 4
						else
						{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
					 		embMsgAns.SetAddrI(aS);	 //t
					 		embMsgAns.SetAddrS(aI);	 //t
					 		embMsgAns.SetAddrR(aR);	 //t
	 					} //3 or 4
					}  //485
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}	//not 485

					switch(embMsgRequest->Type())
					{
					//	printf(" f:%d", flagRequest); //t


				  	case 0x01: // запрос типа
		   //ok		 	printf("\r\n 01 flag:%d", flagRequest); //t
 				  if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}			
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
					//	break;
						Reset_Triggered(0xFFFFFFFFl);
						break;
//______________________________________________________________________________________________						
					case 0x02 :

					if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}		
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
					if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}		
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
					if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}		
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


					case 0x06:	//Выгрузка файла (чтение из устройства)
			   	//	printf("\n\r06>");
//	Запрос: <Адрес в памяти/32><смещение/16><N длина фрагмента/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
						/// формируем ответ ///
	   					ul2uc.uc[0] = embMsgRequest->Body(0);
					  	ul2uc.uc[1] = embMsgRequest->Body(1);
					  	ul2uc.uc[2] = embMsgRequest->Body(2);
					   	ul2uc.uc[3] = embMsgRequest->Body(3);
				   //	 	MessageChar(1,1,ul2uc.uc[3]);
					 //	MessageChar(10,1,ul2uc.uc[2]);
					// 	MessageChar(14,1,ul2uc.uc[1]);
					// 	MessageChar(18,1,ul2uc.uc[0]);
					 //	tmp = (ul2uc.uc[3] << 24) + (ul2uc.uc[2] << 16)	+  (ul2uc.uc[1] << 8) + ul2uc.uc[0];
					 //	MessageLong(1,2,tmp);
				  //		addrRAM = (unsigned char *)0x21000000;   //t
				 //t		addrRAM = (unsigned char *)ul2uc.ul;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

						shift = ui2uc.ui;
						 //	printf("\n\r06>%X", ui2uc.ui);

						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
   						len = ui2uc.ui;
						temp_crc=0;
					if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}						
						embMsgAns.SetType(0x06);
						embMsgAns.SetLength(len+10);
//_________________ok
				 		embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
				//		if(ul2uc.uc[3] == 0x80) //port : if try read nvram		
						if(1) //t for avt
						{
				//		 cnt06++;
			    //  	  printf("\n\r06>shift : 0x%X,   len = 0x%X, cnt06 = %X",shift, len, cnt06);
				 		for(i=0; i<len; i++)
						{
		 		  //t		temp_crc += *(addrRAM+i+shift);
		 		  //t		embMsgAns.SetBody(i+8,*(addrRAM+i+shift));
		   				   temp_crc +=   read_nvram_char(i + shift);
		  				   embMsgAns.SetBody(i+8, read_nvram_char(i + shift));
						}
						}  //try read nvram
						else //sdram?
						{
						 for(i=0; i<len; i++)
						{
		 		   //t		temp_crc += *(addrRAM+i+shift);
		 		  //t		embMsgAns.SetBody(i+8,*(addrRAM+i+shift));
				 		   Ring(1,1,5,4);
						   temp_crc += 0;	 //temporary
						   embMsgAns.SetBody(i+8,0); //temporary
						}
					  	}	   
						ui2uc.ui=temp_crc;
				  		embMsgAns.SetBody(len+8,ui2uc.uc[0]);
				  		embMsgAns.SetBody(len+9,ui2uc.uc[1]); 
						break;	
//________________________________________________________________>> from buk
					case 0x0A:
					  	//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
	
		   			   if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
						  Set_Outputs(embMsgRequest->Body(4));
						}
						 if(flagRequest == 1) 
							{
							embMsgAns.SetTOM(0x20);
							embMsgAns.SetAddrI(SelfID());
							embMsgAns.SetAddrS(SelfID());
							}			
							embMsgAns.SetType(0x0A);
							embMsgAns.SetLength(5);
					   		embMsgAns.SetBody(0, embMsgRequest->Body(0));
							embMsgAns.SetBody(1, embMsgRequest->Body(1));
							embMsgAns.SetBody(2, embMsgRequest->Body(2));
							embMsgAns.SetBody(3, embMsgRequest->Body(3));
							embMsgAns.SetBody(4, embMsgRequest->Body(4));
							break;
				 case 0x0B:
			   			//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
						 tmp = Outputs_Monitoring();
						 if(flagRequest == 1) 
							{
							embMsgAns.SetTOM(0x20);
							embMsgAns.SetAddrI(SelfID());
							embMsgAns.SetAddrS(SelfID());
							}			
							embMsgAns.SetType(0x0B);
							embMsgAns.SetLength(4);
					   		embMsgAns.SetBody(0, embMsgRequest->Body(0));
							embMsgAns.SetBody(1, embMsgRequest->Body(1));
							embMsgAns.SetBody(2, embMsgRequest->Body(2));
							embMsgAns.SetBody(3, (char)tmp);
						}
						   break;
  //____________________________________________________________<<from buk							
				case 0x0C:
			 //	printf("\n\r0C>");
					if(flagRequest == 1) 
					{
					embMsgAns.SetTOM(0x20);
					embMsgAns.SetAddrI(SelfID());
					embMsgAns.SetAddrS(SelfID());
					}
					embMsgAns.SetType(0x0C);
					embMsgAns.SetLength(0);
///
//____________________________________________________
		  	   //		TUTS_init();
	 			//	embMsg.Init();
					break;
				case 0x0E:	  //read inputs
					tmp = Inputs_Monitoring(0xFFFFFFFFl);
				  //	Reset_Triggered(0xFFFFFFFFl);
					   if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}			
						embMsgAns.SetType(0x0E);
						embMsgAns.SetLength(4);
					   					   
   						embMsgAns.SetBody(0,(tmp >> 24));
					    embMsgAns.SetBody(1,(tmp >> 16));
						embMsgAns.SetBody(2,(tmp >> 8));
						embMsgAns.SetBody(3,tmp );
   				   	 break;
			   	case 0xF:	  //set outputs
					   	Set_Outputs(embMsgRequest->Body(0));
				     break;
				case 0x10:	  //
					  tmp = Inputs_Triggered_Monitoring();
					  if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}			
						embMsgAns.SetType(0x0E);
						embMsgAns.SetLength(4);
					   					   
   						embMsgAns.SetBody(0,(tmp >> 24));
					    embMsgAns.SetBody(1,(tmp >> 16));
						embMsgAns.SetBody(2,(tmp >> 8));
						embMsgAns.SetBody(3,tmp );
   				   	 break;

		   case 0x22:
					  if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}			
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

		  default : break;


				}	// type
				  //	printf(" f:%d", flagRequest);
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
					  	embMsgAns.Init(); //my as in mf_20 previons
						embMsg.Init();
					 	flagRequest = 0;
					}


					if(flagRequest == 3) 
					{

			 //	  	 my_printf(0x26);	//t
   			  	 //	  printf("\n\r>");
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
	  					//	printf(".%02X",embMsgAns.body[i]);
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
			   		 //   embMsg485.Init(); // t my
	 			 	embMsg485.Init();	//090121
						flagRequest = 0;
					}
//_________________________________________________________________________________RDN
			 
				if(flagRequest == 4) 
			   	{ 
		   //		  static int ecount = 0l;
		   //		  	printf("\n\r>L %d",++ecount);	   //ttttttt
		   //			printf("\n\rTR>time1 : %d S :%X R:%X I :%X N:%X >",time1,embMsgAns.AddrS(),embMsgAns.AddrR(),embMsgAns.AddrI(),embMsgAns.body[1]); //090427
		  
						   embRS485.TransE(0x55);
		  					embRS485.TransE(0xAA);
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
				   //		printf("\n\r Used 1");
					 _int_disable();
			 			  embRS485.Trans_RDN(embMsgAns.AddrS());
					 _int_enable();

			 
						  embRS485.EmptyReceiveE();
				  	 	  embMsg485E.Init();	//090121

								flagRequest = 0;
					}	// ==4
					
 //________________________________________________________________________________________RDN

				}	  //request for self addr  and not from self addr
				else  //not for self addr
				{
					if(flagRequest == 1) 
					{
					  embMsg.Init();
					}
					if(flagRequest == 3) 
					{
					  embMsg485.Init();
					}
					 if(flagRequest == 4) 
					{
					  embMsg485E.Init();
					}
				}  //not self addr	and not from self addr
			   }
			   else	 //addr i == self addr
			   {
					if(flagRequest == 1) 
					{
					  embMsg.Init();
					}
					if(flagRequest == 3) 
					{
					  embMsg485.Init();
					}
					 if(flagRequest == 4) 
					{
					  embMsg485E.Init();
					}
			   }
			  	flagRequest = 0;
				embMsgRequest = NULL;
      }	//flagrequest not zero
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
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{
//#ifdef IncEmbSerialMD34AVT
//#ifdef PROG_BUKC
//my_int_enable_irq0();
//#endif //PROG_BUKC
//  embSerialACT155.IsrXX();
  IntFlag |= INT0_FLAG;
//#endif // IncEmbSerialMD34AVT

//#ifdef IncEmbSerialACT155
 //	  Stephany19++; 
//     embSerialACT155.IsrXX();
// IntFlag |= INT0_FLAG;
//#endif // IncEmbSerialACT155

// if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
// {
//   InterruptWatchDog++;
   my_int_enable_irq0();
// }

}
