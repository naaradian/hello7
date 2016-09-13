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


extern "C" void StartSaveCommut(void);
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
//unsigned SelfID() 
//{ 
 //	unsigned far *ctrl = (unsigned far*)0xFFFF000A; 
 //	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
//   return 1; //t
// return 0;
//}

//unsigned SelfYear() 
//{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF0008; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);
// return 2;   //t
//}

//unsigned SelfVer1() 
//{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF000C; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
//  return 3;	 //
//}

//unsigned SelfVer2() 
//{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF000E; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);
//  return 4;   //
//}

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

//_______________________________________________________>> from bmd_34
/*
struct TOM // [TRС00MEK]
{
	int K : 1; // K - признак получения пакета адресатом, устанавливается в "1" при получении пакета адресатом;
	int E : 1; // E - бит ошибки в CRC, устанавливается в "1" если не сходится CRC;
	int M : 1; // M - бит монитора, устанавливаемый в "1" при проходе кадром "активного монитора";
	int reserved : 2;
	int C : 1; // R - признак сообщение из RS-485 (был запрос маркера)
	int R : 1; // C - устанавливается в "1" если это запрос компьютера подключенного к станции.
	int T : 1; // T - бит маркера; 
//	TOM() { reserved=0; T=R=C=M=E=K=0; }
};

union UnTOM
{
	unsigned char byte;
	TOM tom;
};

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
  //	unsigned char Body(int i) { if(IsRS485()) body[i+11]; else return body[i+9]; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
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
//_______________________________________________________<< from bmd_34 

//______>>commented  to use from bmd_34 
/*
class EmbMsg
{
public:	
	unsigned char readyToSend;
	unsigned counter;
	unsigned char body[270];

	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned short AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned short  AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short  Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short  FullSize() {	return Length() + 11;	 }			// 2
	unsigned  short CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
	unsigned char Body(int i) { return body[i+9]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetAddrI(unsigned short  word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}
	void SetBody(int i, unsigned char byte) { body[i+9]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

	void Init();
	unsigned  short Add(unsigned char byte);
	unsigned  short Used() { return counter; }
	unsigned  short IsFree() { return 270-counter; }
	int IsEnd();
	unsigned  short ChkCRC();
	unsigned  short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend=i; }

	void Copy(EmbMsg m);
};
 */
//_________________<<  to use from bmd_34
/*
void EmbMsg::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 
*/
/*
void EmbMsg::Init()
{
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend=0;
}
 */
//_____________________________>> from bmd_34
/*
void EmbMsg::Init()
{
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
}

unsigned EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 11;	 
	else return counter;
}

//______________________________<< from bmd_34

//unsigned  short EmbMsg::Add(unsigned char byte)  
unsigned  EmbMsg::Add(unsigned char byte){
  if(counter < 270)
 	{
		body[counter] = byte;
		counter++;
		return 1;
  	}
  	else
  	  return 0;
}

int EmbMsg::IsEnd()
{
  if(counter>10)
		if(counter==Length()+11)
			return 1;
	return 0;
}

//unsigned  short EmbMsg::ChkCRC()
unsigned EmbMsg::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}
  */
//unsigned  short EmbMsg::CalcCRC()
/*
unsigned EmbMsg::CalcCRC()
{
  int i;
	unsigned  short c=0;
	if(Length()<=256) 
	{
		for(i=9; i<Length()+11; i++) c += body[i];
		return c;
	}
	else return 0;
} 
  */
/*
//______________________________________>> from bmd_34
unsigned EmbMsg::CalcCRC()
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
//________________________________________<< from bmd_34

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

class MF20TimerBufferTLF
{
 //t   TRBuffer<unsigned char,32l> slot_tlf_buf[16];
	 TRBuffer<unsigned int,32l> slot_tlf_buf[16];

    unsigned char answer[16];
  public:
    void Init();
    void Deal();
    unsigned short Outb(unsigned char slot,unsigned char byte);
    unsigned short Out2b(unsigned char slot,unsigned char byte1,unsigned char byte2);
    unsigned char Answer(unsigned char slot) { return answer[slot]; }
};

void MF20TimerBufferTLF::Init()
{
  int i;
  for(i = 0; i < (int)NUM_OF_SLOT; i++) 
  {
  slot_tlf_buf[i].Init();
  }
}

unsigned short MF20TimerBufferTLF::Out2b(unsigned char slot,unsigned char byte1,unsigned char byte2)
{
  if(slot<16)
  { 
 // my_printf(slot); 
   slot_tlf_buf[slot].Add(byte1);
  //  my_printf(byte1);
   slot_tlf_buf[slot].Add(byte2);
  //    my_printf(byte2);
   }
  return  0; //t slot_tlf_buf[slot].Used();
}

unsigned short MF20TimerBufferTLF::Outb(unsigned char slot,unsigned char byte)
{
  if(slot<16) slot_tlf_buf[slot].Add(byte);
   return slot_tlf_buf[slot].Used();
}

void MF20TimerBufferTLF::Deal()
{
  int i;
  for(i=0; i<NUM_OF_SLOT; i++) 
  {
    if(mf20cfg->cardInSlot[i]!=0xFF)
 //t	 if(read_nvram_char(HEADER + i) != 0xff) //port	   32 - header
    {
      if(!(inportb(0x504+i*16)&0x40))
        if(slot_tlf_buf[i].Used())
        {
	//	delay_mcs(500l);
          outportb(0x507+i*16,slot_tlf_buf[i].Get());
          answer[i] = inportb(0x507+i*16);
        }
    }
  }
}

MF20TimerBufferTLF mf20TimerBufferTLF;
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
void save_e14_reg(int l_base, int h_base, int window, unsigned addr, unsigned char value)
{
  outportb(l_base,addr&0xFF);
	if(inportb(l_base)!=addr&0xFF) outportb(l_base,addr&0xFF);
	if(inportb(l_base)!=addr&0xFF) outportb(l_base,addr&0xFF);
  outportb(h_base,(addr>>8)&0xFF);
	if(inportb(h_base)!=(addr>>8)&0xFF) outportb(h_base,(addr>>8)&0xFF);
	if(inportb(h_base)!=(addr>>8)&0xFF) outportb(h_base,(addr>>8)&0xFF);
  outportb(window,value);
	if(inportb(window)!=value) outportb(window,value);
	if(inportb(window)!=value) outportb(window,value);
	}

unsigned char load_e14_reg(int l_base, int h_base, int window, unsigned addr)
{
  outportb(l_base,addr&0xFF);
	if(inportb(l_base)!=addr&0xFF) outportb(l_base,addr&0xFF);
	if(inportb(l_base)!=addr&0xFF) outportb(l_base,addr&0xFF);
  outportb(h_base,(addr>>8)&0xFF);
	if(inportb(h_base)!=(addr>>8)&0xFF) outportb(h_base,(addr>>8)&0xFF);
	if(inportb(h_base)!=(addr>>8)&0xFF) outportb(h_base,(addr>>8)&0xFF);
  return inportb(window);
}
void Init_E14(unsigned char slot, unsigned chan) // нумерация каналов с 0
{
  int l_base = 0x500+slot*16;
  int h_base = 0x501+slot*16;
  int window = 0x50F+slot*16;
  save_e14_reg(l_base,h_base,window,0x009+chan,0x00);
}

	EmbRS232 embRS232;


 	EmbMsg embMsg;	  //new
	EmbMsg embMsg232E;
	EmbMsg embMsgAns; //new
  //  
//_____________________________________________>>from bmd_34 
    EmbMsg embMsg485;
	EmbMsg embMsg485E;

	unsigned aI, aS, aR;
//	int i232;
  //	int i485;		//my
    unsigned char flagRequest; //=0;
	EmbMsg *embMsgRequest;
	EmbMsgBuffer rBuffEmbMsg;
	unsigned addr1;	
	unsigned char * bt;	
//_____________________________________________<<from bmd_34

	EmbRS485 embRS485;
//1024	EmbIndicator embIndicator;
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


void Monitor()
{
//  asm { cli };
//  asm { db 0xEA };
//  asm { db 0x00 };
//  asm { db 0x00 };
//  asm { db 0xFF };
//  asm { db 0xFF };

//  asm { db 0x00 };
//  asm { db 0x0A };
//  asm { db 0x00 };
//  asm { db 0x27 };

//  asm { db 0x00 };
//  asm { dw 0x0000, 0xFFFF };
//  asm { dw 0x0A00, 0x2700 };
}

void SetBlockTLF_OT(unsigned slot, unsigned char  *data)
{
// data[64]
// 0 - тип блока ТЛФ/ОЦК
unsigned long cnt;

	unsigned temp_b=0;
	int addr_ock = 0x508+slot*16;
	if(data[0]) temp_b=0x0F;
	else temp_b=0;
	outportb(addr_ock, temp_b);

//my t0129	if(inportb(addr_ock)!=temp_b) outportb(addr_ock, temp_b);
//my t0129	if(inportb(addr_ock)!=temp_b) outportb(addr_ock, temp_b);
//_____________________________________________
//delay_mcs(2000l); 
  for(cnt = 0; cnt < 1000; cnt++)
  {
	if(inportb(addr_ock) == temp_b) break;
  }  
  outportb(addr_ock, temp_b);
 // if(cnt == 1000) printf("\n\r Error SetBlockTLF_OT \n\r");
 // printf("\n\r slot: %02d cnt:0x%03lX\n\r",slot, cnt);
//_______________________________________________
////
//	outportb(addr_ock, 0x0F);
//	if(inportb(addr_ock)!=0x0F) outportb(addr_ock, 0x0F);
//	if(inportb(addr_ock)!=0x0F) outportb(addr_ock, 0x0F);
////
 //   delay_mcs(200); 
	mf20TimerBufferTLF.Out2b(slot,0x80,0x80); // сброс разборщика комманд
 //  delay_mcs(200); 

// 1...4 - типы линий 2-х/4-х проводка
	mf20TimerBufferTLF.Out2b(slot,0x98, (data[1]<<4)&0x30); 
 //	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x99, (data[2]<<4)&0x30); 
 //	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x9A, (data[3]<<4)&0x30); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x9B, (data[4]<<4)&0x30); 
//	delay_mcs(200);
// 5...8 - уровни Вх
	mf20TimerBufferTLF.Out2b(slot,0x84, data[9]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x85, data[10]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x86, data[11]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x87, data[12]); 
// 	delay_mcs(200);
// 9..12 - уровни Вых
	mf20TimerBufferTLF.Out2b(slot,0x88, data[5]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x89, data[6]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x8A, data[7]); 
// 	delay_mcs(200);
	mf20TimerBufferTLF.Out2b(slot,0x8B, data[8]);
//	delay_mcs(500); 
}
 /*
void SetBlockTLF_OT_1(unsigned slot, uint_32  data)		 //port
{
// data[64]
// 0 - тип блока ТЛФ/ОЦК
	unsigned temp_b=0;
	int addr_ock = 0x508+slot*16;
	unsigned char byte2;
  //port	if(data[0]) temp_b=0x0F;
  byte2 =  read_nvram_char(data);
	if(byte2) temp_b = 0x0F;
	else temp_b=0;
	outportb(addr_ock, temp_b);
	if(inportb(addr_ock)!=temp_b) outportb(addr_ock, temp_b);
	if(inportb(addr_ock)!=temp_b) outportb(addr_ock, temp_b);
////
//	outportb(addr_ock, 0x0F);
//	if(inportb(addr_ock)!=0x0F) outportb(addr_ock, 0x0F);
//	if(inportb(addr_ock)!=0x0F) outportb(addr_ock, 0x0F);
////
//    return; //t1123
	mf20TimerBufferTLF.Out2b(slot,0x80,0x80); // сброс разборщика комманд
// 1...4 - типы линий 2-х/4-х проводка
//ok return; //t1123
	byte2 =  (unsigned char)read_nvram_char(data + 1l);
  	mf20TimerBufferTLF.Out2b(slot,0x98, (byte2<<4)&0x30);
	byte2 = (unsigned char)read_nvram_char(data + 2l); 
 	mf20TimerBufferTLF.Out2b(slot,0x99, (byte2<<4)&0x30); 
	byte2 =  (unsigned char)read_nvram_char(data + 3l);
	mf20TimerBufferTLF.Out2b(slot,0x9A, (byte2<<4)&0x30); 
	byte2 = (unsigned char)read_nvram_char(data + 4l);
 	mf20TimerBufferTLF.Out2b(slot,0x9B, (byte2<<4)&0x30); 
 //	my_printf(0x33);
//  return; //bad //t1123
 
// 5...8 - уровни Вх

	mf20TimerBufferTLF.Out2b(slot,0x84,read_nvram_char(data + 9l)); 
	mf20TimerBufferTLF.Out2b(slot,0x85,read_nvram_char(data + 10l)); 
	mf20TimerBufferTLF.Out2b(slot,0x86,read_nvram_char(data + 11l)); 
	mf20TimerBufferTLF.Out2b(slot,0x87,read_nvram_char(data + 12l)); 
// 9..12 - уровни Вых
	mf20TimerBufferTLF.Out2b(slot,0x88,read_nvram_char(data + 5l)); 
	mf20TimerBufferTLF.Out2b(slot,0x89,read_nvram_char(data + 6l)); 
	mf20TimerBufferTLF.Out2b(slot,0x8A,read_nvram_char(data + 7l)); 
	mf20TimerBufferTLF.Out2b(slot,0x8B,read_nvram_char(data + 8l)); 
}
  */
struct E1con
{
	unsigned trans_tx : 1;
	unsigned unfram_tx : 1;
	unsigned cas_tx : 1;
	unsigned crc4_tx : 1;
	unsigned reserv : 1;
	unsigned unfram_rx : 1;
	unsigned cas_rx : 1;
	unsigned crc4_rx : 1;
};

union UnE1con
{
	unsigned char b;
	E1con e;
};

unsigned char CreateE1CtrlByte(unsigned char data_tx, unsigned char data_rx, unsigned char nb)
{
	UnE1con u;
	switch(data_tx)
	{
		case 0: u.e.unfram_tx=0; u.e.cas_tx=1; u.e.crc4_tx=0; break; 
		case 1: u.e.unfram_tx=0; u.e.cas_tx=1; u.e.crc4_tx=1; break; 
		case 2: u.e.unfram_tx=0; u.e.cas_tx=0; u.e.crc4_tx=0; break; 
		case 3: u.e.unfram_tx=0; u.e.cas_tx=0; u.e.crc4_tx=1; break; 
		case 4: u.e.unfram_tx=1; u.e.cas_tx=0; u.e.crc4_tx=0; break; 
		default: u.e.unfram_tx=1; u.e.cas_tx=0; u.e.crc4_tx=0; break; 
	}
	switch(data_rx)
	{
		case 0: u.e.unfram_rx=0; u.e.cas_rx=1; u.e.crc4_rx=0; break; 
		case 1: u.e.unfram_rx=0; u.e.cas_rx=1; u.e.crc4_rx=1; break; 
		case 2: u.e.unfram_rx=0; u.e.cas_rx=0; u.e.crc4_rx=0; break; 
		case 3: u.e.unfram_rx=0; u.e.cas_rx=0; u.e.crc4_rx=1; break; 
		case 4: u.e.unfram_rx=1; u.e.cas_rx=0; u.e.crc4_rx=0; break; 
		default: u.e.unfram_rx=1; u.e.cas_rx=0; u.e.crc4_rx=0; break; 
	}
	u.e.trans_tx = nb;
	return u.b;
}

struct ETHcon
{
	unsigned mode_auto : 1;
	unsigned full_dupl : 1;
	unsigned rate : 1;
	unsigned bridge : 1;
	unsigned flow_ctrl : 1;
	unsigned ba_method : 1;
	unsigned age : 1;
	unsigned filtr : 1;
};

union UnETHcon
{
	unsigned char b;
	ETHcon e;
};

unsigned char CreateSyncSourceByte(unsigned char main, unsigned char resr)
{
	unsigned char temp = 0;
	switch(main)
	{
		case 1: temp|=0x80; break;
		case 2: temp|=0xA0; break;
		case 3: temp|=0xC0; break;
		case 4: temp|=0xE0; break;
	}
	switch(resr)
	{
		case 1: temp|=0x10; break;
		case 2: temp|=0x14; break;
		case 3: temp|=0x18; break;
		case 4: temp|=0x1C; break;
	}
	temp|=0x03;
	return temp; 
}



void SetBlockE14ET(unsigned slot, unsigned char *data)
{
	unsigned char b_temp;
  int l_base = 0x500+slot*16;
  int h_base = 0x501+slot*16;
  int window = 0x50F+slot*16;
	save_e14_reg(l_base,h_base,window,0x220,0x01);
	save_e14_reg(l_base,h_base,window,0x240,0x0C);
	save_e14_reg(l_base,h_base,window,0x201,0x18);
	save_e14_reg(l_base,h_base,window,0x203,0x01);
	save_e14_reg(l_base,h_base,window,0x21A,0x09);
	save_e14_reg(l_base,h_base,window,0x240,0x04);
// data[64]
// 0 - режим канала передачи Е1-1
// 1 - режим канала приема   Е1-1  
//	b_temp= load_e14_reg(l_base,h_base,window,0x308);	
	save_e14_reg(l_base,h_base,window,0x308,CreateE1CtrlByte(data[0], data[1], 1));
// 2 - режим канала передачи Е1-2
// 3 - режим канала приема   Е1-2	
	save_e14_reg(l_base,h_base,window,0x309,CreateE1CtrlByte(data[2], data[3], 1));
// 4 - режим канала передачи Е1-3
// 5 - режим канала приема   Е1-3
	save_e14_reg(l_base,h_base,window,0x30A,CreateE1CtrlByte(data[4], data[5], 1));
// 6 - режим канала передачи Е1-4
// 7 - режим канала приема   Е1-4
	save_e14_reg(l_base,h_base,window,0x30B,CreateE1CtrlByte(data[6], data[7], 1));
// 8 - линия передачи EtherNet
	save_e14_reg(l_base,h_base,window,0x330,data[8]);
// 9 - линия приема EtherNet
	save_e14_reg(l_base,h_base,window,0x334,data[9]);
// 10 - режим порта EtherNet "Режим EtherNet"
// 11 - режим порта EtherNet "Дуплекс"
// 12 - режим порта EtherNet "Скорость"
// 13 - режим порта EtherNet "Режим моста"
// 14 - режим порта EtherNet "Режим управления потоком"
// 15 - режим порта EtherNet "Пропускная способность"
// 16 - режим порта EtherNet "Скорость странения данных"
// 17 - режим порта EtherNet "Фильтрация данных"
	UnETHcon u;
	u.e.mode_auto = data[10];
	u.e.full_dupl = data[11];
	u.e.rate			= data[12];
	u.e.bridge		= data[13];
	u.e.flow_ctrl = data[14];
	u.e.ba_method = data[15];
	u.e.age				= data[16];
	u.e.filtr			= data[17];
	save_e14_reg(l_base,h_base,window,0x352,u.b);
	switch(data[18])
	{
		case 0: save_e14_reg(l_base,h_base,window,0x351,0x00); break;
		case 1: save_e14_reg(l_base,h_base,window,0x351,0x10); break;
		case 2: save_e14_reg(l_base,h_base,window,0x351,0x11); break;
		case 3: save_e14_reg(l_base,h_base,window,0x351,0x12); break;
		case 4: save_e14_reg(l_base,h_base,window,0x351,0x13); break;
	}

	outportb(0x507+slot*16,CreateSyncSourceByte(data[19], data[20]));
	if(inportb(0x507+slot*16)!=CreateSyncSourceByte(data[19], data[20]))
	{
		outportb(0x507+slot*16,CreateSyncSourceByte(data[19], data[20]));
		if(inportb(0x507+slot*16)!=CreateSyncSourceByte(data[19], data[20]))
		{
			outportb(0x507+slot*16,CreateSyncSourceByte(data[19], data[20]));
		 //	printf("\n\r Error SetBlockE14ET\n\r");
		}
	}
	
	switch(data[21])
	{
		case 0: b_temp=0x06; break;
		case 1: b_temp=0x04; break;
		case 2: b_temp=0x05; break;
	}
	outportb(0x508+slot*16,b_temp);
	if(inportb(0x508+slot*16)!=b_temp)
	{
		outportb(0x508+slot*16,b_temp);
		if(inportb(0x508+slot*16)!=b_temp)
		{
			outportb(0x508+slot*16,b_temp);
		}
	}
// 32...63 - позиции EtherNet на линии 
}
 /*
 void SetBlockE14ET_1(unsigned slot, uint_32 data)
{
   
	unsigned char b_temp;
  int l_base = 0x500+slot*16;
  int h_base = 0x501+slot*16;
  int window = 0x50F+slot*16;
   
  	save_e14_reg(l_base,h_base,window,0x220,0x01);
	save_e14_reg(l_base,h_base,window,0x240,0x0C);
	save_e14_reg(l_base,h_base,window,0x201,0x18);
	save_e14_reg(l_base,h_base,window,0x203,0x01);
	save_e14_reg(l_base,h_base,window,0x21A,0x09);
	save_e14_reg(l_base,h_base,window,0x240,0x04);
 
// data[64]
// 0 - режим канала передачи Е1-1
// 1 - режим канала приема   Е1-1  
//	b_temp= load_e14_reg(l_base,h_base,window,0x308);	
	save_e14_reg(l_base,h_base,window,0x308,CreateE1CtrlByte(read_nvram_char(data), read_nvram_char(data + 1), 1));
// 2 - режим канала передачи Е1-2
// 3 - режим канала приема   Е1-2	
	save_e14_reg(l_base,h_base,window,0x309,CreateE1CtrlByte(read_nvram_char(data + 2), read_nvram_char(data + 3), 1));
// 4 - режим канала передачи Е1-3
// 5 - режим канала приема   Е1-3
	save_e14_reg(l_base,h_base,window,0x30A,CreateE1CtrlByte(read_nvram_char(data + 4), read_nvram_char(data + 5), 1));
// 6 - режим канала передачи Е1-4
// 7 - режим канала приема   Е1-4
	save_e14_reg(l_base,h_base,window,0x30B,CreateE1CtrlByte(read_nvram_char(data + 6), read_nvram_char(data + 7), 1));
// 8 - линия передачи EtherNet
	save_e14_reg(l_base,h_base,window,0x330,read_nvram_char(data + 8));
// 9 - линия приема EtherNet
	save_e14_reg(l_base,h_base,window,0x334,read_nvram_char(data + 9));
// 10 - режим порта EtherNet "Режим EtherNet"
// 11 - режим порта EtherNet "Дуплекс"
// 12 - режим порта EtherNet "Скорость"
// 13 - режим порта EtherNet "Режим моста"
// 14 - режим порта EtherNet "Режим управления потоком"
// 15 - режим порта EtherNet "Пропускная способность"
// 16 - режим порта EtherNet "Скорость странения данных"
// 17 - режим порта EtherNet "Фильтрация данных"
	UnETHcon u;
	u.e.mode_auto = read_nvram_char(data + 10);
	u.e.full_dupl = read_nvram_char(data + 11);
	u.e.rate			= read_nvram_char(data + 12);
	u.e.bridge		= read_nvram_char(data + 13);
	u.e.flow_ctrl = read_nvram_char(data + 14);
	u.e.ba_method = read_nvram_char(data + 15);
	u.e.age				= read_nvram_char(data + 16);
	u.e.filtr			= read_nvram_char(data + 17);
	save_e14_reg(l_base,h_base,window,0x352,u.b);
	switch(read_nvram_char(data + 18))
	{
		case 0: save_e14_reg(l_base,h_base,window,0x351,0x00); break;
		case 1: save_e14_reg(l_base,h_base,window,0x351,0x10); break;
		case 2: save_e14_reg(l_base,h_base,window,0x351,0x11); break;
		case 3: save_e14_reg(l_base,h_base,window,0x351,0x12); break;
		case 4: save_e14_reg(l_base,h_base,window,0x351,0x13); break;
	}

	outportb(0x507+slot*16,CreateSyncSourceByte(read_nvram_char(data + 19), read_nvram_char(data + 20)));
	if(inportb(0x507+slot*16)!=CreateSyncSourceByte(read_nvram_char(data + 19), read_nvram_char(data + 20)))
	{
		outportb(0x507+slot*16,CreateSyncSourceByte(read_nvram_char(data + 19), read_nvram_char(data + 20)));
		if(inportb(0x507+slot*16)!=CreateSyncSourceByte(read_nvram_char(data + 19), read_nvram_char(data + 20)))
		{
			outportb(0x507+slot*16,CreateSyncSourceByte(read_nvram_char(data + 19), read_nvram_char(data + 20)));
		}
	}
	
	switch(read_nvram_char(data + 21))
	{
		case 0: b_temp=0x06; break;
		case 1: b_temp=0x04; break;
		case 2: b_temp=0x05; break;
	}
	outportb(0x508+slot*16,b_temp);
	if(inportb(0x508+slot*16)!=b_temp)
	{
		outportb(0x508+slot*16,b_temp);
		if(inportb(0x508+slot*16)!=b_temp)
		{
			outportb(0x508+slot*16,b_temp);
		}
	}
  
// 32...63 - позиции EtherNet на линии 
}

  */
  


void CfgCard()
{
	int i=0;
//	int j = 0; //t
//	for(j = 0; j < 6; j++)//t
//	{	 //t
  	for(i=0; i<NUM_OF_SLOT; i++)
	{
 //		switch(mf20cfg->cardInSlot[i]) // типы плат
 		 switch(read_nvram_char(HEADER + i)) //	port 32 - header
		{
			case 0x11: 
	 		SetBlockTLF_OT(i, mf20cfg->cardData+i*64);
	  //	    my_printf(0x11);
 	 //	SetBlockTLF_OT_1(i, (HEADER + CARDINSLOT + CARDE1 + (i * 64)));	 // hier hangt!!!!
				break;
			case 0x12: 
	  //	    my_printf(0x12);

   		 	SetBlockE14ET(i, mf20cfg->cardData+i*64);
 	  //	 SetBlockE14ET_1(i, (HEADER + CARDINSLOT + CARDE1 + (i * 64)));  //	
 		 	break;
			default : 
			break;
		}
	}
//} //t
//	my_printf(0x44);//not print	
}

void SaveCommut()
{
	int i=0, j=0;
   //t	int l_base;
	   short int l_base = 0;
   //t int h_base;
	short int h_base = 0;
  //t  int window;
	short int window = 0;

	for(j=0; j<16; j++)
	{
  	if((mf20cfg->cardE1[j*2]<0x10)&&(mf20cfg->cardE1[j*2+1]<0x10))
   //		 my_printf(j);
	 //	 my_printf(mf20cfg->cardE1[j*2]);
	   //	 my_printf(mf20cfg->cardE1[j*2+1]);
  //	  	 if( (read_nvram_char(HEADER + CARDINSLOT + (j * 2)) < 0x10) && 
  	//  	 			(read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) < 0x10) )
  		{
			l_base = 0x500 + mf20cfg->cardE1[j*2]*16;
		 //	my_printf((l_base>>8)&0xff);
		 //	my_printf(l_base & 0xff);
		//t	l_base = 0x500 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
		 //	my_printf((l_base>>8)&0xff);
		//	my_printf(l_base & 0xff);

	  	    h_base = 0x501 +  mf20cfg->cardE1[j*2]*16;
	  //		my_printf((h_base>>8)&0xff);
	   //		my_printf(h_base & 0xff);

	  //t	   h_base = 0x501 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
		 //	 my_printf((h_base>>8)&0xff);
		//	my_printf(h_base & 0xff);

  			 window = 0x50F +	 mf20cfg->cardE1[j*2]*16;
	   //t	   	window = 0x50F + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
	   //		  my_printf((window>>8)&0xff);
	   //		my_printf(window & 0xff);


	   	save_e14_reg(l_base, h_base, window, 0x300+mf20cfg->cardE1[j*2+1], 0);
   	 //  		save_e14_reg(l_base, h_base, window,
	 //	  					 0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0);
  
			for(i=0; i<128; i++) // типы плат
			{
		   	 	if(mf20cfg->connectData[j*128+i]<=0x20)
		   //		 if(read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ) <= 0x20)
	 			{
			 		save_e14_reg(l_base, h_base, window,
			  	  	 mf20cfg->cardE1[j*2+1]*128 + i, 
			  //	 	read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) * 128 + i,
			   	  	mf20cfg->connectData[j*128+i] );
			   //	    read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ));
 				}
			}
			save_e14_reg(l_base, h_base, window, 
		    	0x300+mf20cfg->cardE1[j*2+1], 0x80);
		//    0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0x80);
		}
	}		
}
/*
void SaveCommut1()
{
	int i=0, j=0;
	int l_base;
    int h_base;
    int window;
	for(j=0; j<16; j++)
	{
  //	if((mf20cfg->cardE1[j*2]<0x10)&&(mf20cfg->cardE1[j*2+1]<0x10))
  		 if( (read_nvram_char(HEADER + CARDINSLOT + (j * 2)) < 0x10) && 
  		 			(read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) < 0x10) )
  		{
		//	l_base = 0x500 + mf20cfg->cardE1[j*2]*16;
			l_base = 0x500 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
		//	h_base = 0x501 +  mf20cfg->cardE1[j*2]*16;

			h_base = 0x501 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
		//	 window = 0x50F +	 mf20cfg->cardE1[j*2]*16;

			window = 0x50F + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;

	 	//	save_e14_reg(l_base, h_base, window, 0x300+mf20cfg->cardE1[j*2+1], 0);
   			save_e14_reg(l_base, h_base, window,
	 						 0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0);
  
		 //	for(i=0; i<128; i++) // типы плат
			for(i=0; i<TYPES_OF_BLOCKS; i++) // типы плат

			{
			// 	if(mf20cfg->connectData[j*128+i]<=0x20)
				 if(read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ) <= 0x20)
	 			{
					save_e14_reg(l_base, h_base, window,
				  //	 mf20cfg->cardE1[j*2+1]*128 + i, 
				 	read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) * 128 + i,
				 // 	mf20cfg->connectData[j*128+i] );
				    read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ));
 				}
			}
			save_e14_reg(l_base, h_base, window, 
		  //  	0x300+mf20cfg->cardE1[j*2+1], 0x80);
		    0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0x80);
		}
	}		
}
  */
extern "C" void SaveCommut2(unsigned char slot)
{
	int i=0, j=0;
	int l_base;
    int h_base;
    int window;
//	for(j=0; j<16; j++)
//	{
	//   Ring(1,1,5,1);
 //	my_printf(0x22); //t
	j = slot;
  	if((mf20cfg->cardE1[j*2]<0x10)&&(mf20cfg->cardE1[j*2+1]<0x10))
  //t		 if( (read_nvram_char(HEADER + CARDINSLOT + (j * 2)) < 0x10) && 
  //t		 			(read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) < 0x10) )
  		{
			l_base = 0x500 + mf20cfg->cardE1[j*2]*16;
		//t	l_base = 0x500 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
			h_base = 0x501 +  mf20cfg->cardE1[j*2]*16;

		//t	h_base = 0x501 + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
			 window = 0x50F +	 mf20cfg->cardE1[j*2]*16;

		//t	window = 0x50F + read_nvram_char(HEADER + CARDINSLOT + (j * 2)) * 16;
//ok
	 		save_e14_reg(l_base, h_base, window, 0x300+mf20cfg->cardE1[j*2+1], 0);
   		//t	save_e14_reg(l_base, h_base, window,
	 	   //t					 0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0);
  
		 	for(i=0; i<128; i++) // типы плат
		//	for(i=0; i < TYPES_OF_BLOCKS; i++) // типы плат

			{
			 	if(mf20cfg->connectData[j*128+i]<=0x20)
			//t	 if(read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ) <= 0x20)
	 			{
		  			save_e14_reg(l_base, h_base, window,
				  	 mf20cfg->cardE1[j*2+1]*128 + i, 
	//t			 	read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1) * 128 + i,
				  	mf20cfg->connectData[j*128+i] );
 //t				    read_nvram_char(HEADER + CARDINSLOT + CARDDATA + CARDE1 + (j * 128) + i ));
 				}
			}
			save_e14_reg(l_base, h_base, window, 
		    	0x300+mf20cfg->cardE1[j*2+1], 0x80);
	//t	    0x300 + read_nvram_char(HEADER + CARDINSLOT + (j * 2) + 1), 0x80);
		}
//	}		
}

/////////////////////
/*
struct Emb2TypeVer
{
	unsigned type;
	unsigned softVer;
	unsigned ctrlNumber;
	unsigned ctrlYear;
	unsigned ctrlVer1;
	unsigned ctrlVer2;
	unsigned char signature_hardware[16];
	unsigned char signature_software[16];
};
 */
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

void Autodetect(UnEmb2TypeVer &u)
{
    unsigned int i=0;
	int l_base;
  unsigned int a=0;
//   unsigned char test;
  for (i=0; i<16; i++)
  {
		l_base = 0x500+i*16;
		outportb(l_base,0x55);
   //		write_xil_char(0x520, 0x55);  //t
   //		test = 	inportb(l_base);	  //t
  //		test = 	read_xil_char(0x520);  //t
 //		my_printf(test);			  //t
		if(inportb(l_base)==0x55) 
		{
 //port			u.emb2TypeVer.signature_hardware[i] = inportb(0x502+i*16);
			u.emb2TypeVer.signature_hardware[i] = inportb(0x502+i*16) & 0x7f;   //port
			u.emb2TypeVer.signature_software[i] = inportb(0x503+i*16);
  	   //		my_printf(u.emb2TypeVer.signature_hardware[i]);	    //t
	   	}
		else
		{
			u.emb2TypeVer.signature_hardware[i] = 0;
			u.emb2TypeVer.signature_software[i] = 0;
		}
  }
}

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
 unsigned char mode5A485;
 unsigned char mode5A232E;
 unsigned char mode5A485E;


//void main()
extern "C" void mf20_init()
{

 mode5A     = 0;
 mode5A485  = 0;
 mode5A232E = 0;
 mode5A485E = 0;

//  _SS=0x1000;
//	char ch;
//	long f_len;
	unsigned i=0;//, j=0;
      //	UnEmb2TypeVer unEmb2TypeVer;
//_______________________________>> from bmd_34
   flagRequest=0;
   rBuffEmbMsg.Init();

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

	mf20TimerBufferTLF.Init();

	for(i=0; i<16; i++)
	{
	  unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
	  unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
}

 extern "C" mf20_detect()
{
	Autodetect(unEmb2TypeVer);
	unEmb2TypeVer.emb2TypeVer.type       = 0x0201;
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();
//////////////////////
//	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
//char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
///////////////////////////////////////////////////////////////////////////////
  //	embNMI2.Init();
///////////////////////////////////////////////////////////////////////////////
 //	Enable(); // Разрешаем все прерывания
///////////////////////////////////////////////////////////////////////////////
//  	for(;;)
//  	{
	CfgCard();
   	SaveCommut();
// 	}
 //  StartSaveCommut();
//////////////////////////////////////////////////
}

extern "C" void mf20()
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
  //	unsigned long tmp;
static unsigned char test = 0;
//_______________________________________________temporary
/*
 while(RDN_BufferR.Used())
		{
    	   byte = RDN_BufferR.Get();
		   printf(".%02X", byte);
		 }
*/
//_______________________________________________temporary




//_________________________>> from bmd_34
//i232=0;
//i485 = 0; //my
//_________________________<< from bmd_34

//unsigned test3 = 0;
 //		ResetWatchDog();
	 //	my_printf(0x14);
        mf20TimerBufferTLF.Deal();		//_____________________t
 	 //	my_printf(0x12); //t1109
   		while(embRS232.UsedReceive())
 //  if(0)	//test24
	//  my_printf((unsigned char)(embRS232.rcvbuf.Tail & 0xff));
	//  my_printf((unsigned char)(embRS232.rcvbuf.Head & 0xff));



	//	if(embRS232.UsedReceive())	//t
		{
	 //t	break; //test24
  //		if(embRS232.UsedReceive() > test3)
 //		{
  //		test3 = embRS232.UsedReceive();
	 //	my_printf((unsigned char)((test3 >> 8) & 0xff));
	//    my_printf((unsigned char)((test3) & 0xff));
   //		 }
	  //			  my_printf((unsigned char)(embRS232.rcvbuf.Tail & 0xff));
	  //	   my_printf((unsigned char)(embRS232.rcvbuf.Head & 0xff));

			byte = embRS232.Receive();

		 //t	embRS232.rcvbuf.BuffSize = ACT_BUFFER_SIZE;

   //			printf("\n\r BuffSize :%d", embRS232.rcvbuf.BuffSize);
		  //	break; //t1109
	  //	  printf("_____________232:");

	  // 		my_printf(byte); //t1109
	   //		  my_printf((unsigned char)(embRS232.rcvbuf.Tail & 0xff));
	   //	   my_printf((unsigned char)(embRS232.rcvbuf.Head & 0xff));
	 //	     return; //t1109
	  	 //	 my_printf(byte); //t
			switch(byte)
			{
			case 0x55: 
				embMsg.Init();
			 //	my_printf(byte);
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg.Init(); 
	   //		 MessageChar(1,1,1);
		   //	   Ring(1,1,5,1);

			
			break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; 
		 //	  MessageChar(1,2,2);

			break;
			default:
				if(mode5A) 
				{
			  //	    Ring(1,1,5,1);
			  //	     MessageChar(1,1,3);

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
	//		if(++i232> 10) break;
		}	 //while

 //t	if(!embMsg232.IsEnd())
 		if(!embMsg.IsEnd()) // t
		{
//_______________________________________________________________232e
		while(embRS232.UsedReceiveE())
		{
 			byte = embRS232.ReceiveE();
	  	switch(byte)
			{
			case 0x55: 
				embMsg232E.Init();
 			   	embRS232.TransE(0x55);
  //			   	embRS232.Trans_RDN(embMsgRequest->AddrS());		  //????????????????? neew keep before address of computer!!!
 //			embRS232.Trans_RDN(COMP_DEF_MAC_END);	 //temporary zero mac: 001111000000
				embRS232.Trans_RDN_Full(embRS232.HostMAC);	
				break; 
			case 0xAA: embMsg232E.Init(); 
  			
			break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
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
//_______________________________________________________________232e

			while(embRS485.UsedReceive())
			{
		  //ok 	my_printf(0x22);	 //t
				byte = embRS485.Receive();
			   //		printf("_____________485:");
		  	   //		my_printf(byte);	//t

				switch(byte)
				{
				case 0x55: embMsg485.Init(); break; 
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
 }  //	!embMsg.IsEnd
//______________________________________________________________________232e

		}


//___________________________________________________________<<< from bmd_34

  /*  to use bmd_34

			if(embMsg.IsEnd())
			{
	  //	   	    my_printf(embMsg.Type());
				switch(embMsg.Type())
				{
				  	case 0x01: // запрос типа
				   //	  Ring(1,1,5,1);
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;
					case 0x05: // Загрузка файла (запись в устройство) 
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>	
				//   	   if(test != 74)
				//   	   {
				//   	   test = 74;
	   			 	   	ul2uc.uc[0] = embMsg.Body(0);
				  		ul2uc.uc[1] = embMsg.Body(1);
				  		ul2uc.uc[2] = embMsg.Body(2);
				   		ul2uc.uc[3] = embMsg.Body(3);
				  //t		addrRAM = (unsigned char *)ul2uc.ul;
				  //		addrRAM = (unsigned char *)0x21000000; //t
					//wb ao		   if(test != 74)
				   	//   {
				   //	   test = 74;

						ui2uc.uc[0] = embMsg.Body(4);
						ui2uc.uc[1] = embMsg.Body(5);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				  // wbad aok	    if(test != 74)
				   	//   {
				   	  // test = 74;
						shift = ui2uc.ui;
		   //wb ao			   }
						ui2uc.uc[0] = embMsg.Body(6);
						ui2uc.uc[1] = embMsg.Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				 		len = ui2uc.ui;
				//  }
				   //	 	   shift = 0; //ab wo
				  //			len = 128;  //t
				  //	 } //test


			 			temp_crc=0;

			 			for(i=0; i<len; i++) temp_crc += embMsg.Body(i+8);

		   				ui2uc.uc[0] = embMsg.Body(len+8);
		   				ui2uc.uc[1] = embMsg.Body(len+9);
		   				ui2uc.uc[2] = 0;  //1107
						ui2uc.uc[3] = 0;  //1107



						if(ui2uc.ui==temp_crc)
			   			{
					//	if(ul2uc.uc[3] == 0x80) //port : if try use nvram
					//	{
	  			 		 for(i=0; i<len; i++)
				  		   {
		  			   //   *(addrRAM+i+shift)= embMsg.Body(i+8);
		   	  	   			write_nvram_char(i + shift, embMsg.Body(i+8));
				  		   }
					//	 }
					//	 else  //enover memory
					//	 {
					//	     Ring(1,1,5,4);
					//	 }
				  		}
				 	 //  }//test
 						/// формируем ответ ///
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
						embMsgAns.SetType(0x05);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsg.Body(0));
						embMsgAns.SetBody(1,embMsg.Body(1));
						embMsgAns.SetBody(2,embMsg.Body(2));
						embMsgAns.SetBody(3,embMsg.Body(3));
						embMsgAns.SetBody(4,embMsg.Body(4));
						embMsgAns.SetBody(5,embMsg.Body(5));
						embMsgAns.SetBody(6,embMsg.Body(6));
						embMsgAns.SetBody(7,embMsg.Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);		
				 
				 	break;
					case 0x06:	//Выгрузка файла (чтение из устройства)
//	Запрос: <Адрес в памяти/32><смещение/16><N длина фрагмента/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
						/// формируем ответ ///
	   					ul2uc.uc[0] = embMsg.Body(0);
					  	ul2uc.uc[1] = embMsg.Body(1);
					  	ul2uc.uc[2] = embMsg.Body(2);
					   	ul2uc.uc[3] = embMsg.Body(3);
				   //	 	MessageChar(1,1,ul2uc.uc[3]);
					 //	MessageChar(10,1,ul2uc.uc[2]);
					// 	MessageChar(14,1,ul2uc.uc[1]);
					// 	MessageChar(18,1,ul2uc.uc[0]);
					 //	tmp = (ul2uc.uc[3] << 24) + (ul2uc.uc[2] << 16)	+  (ul2uc.uc[1] << 8) + ul2uc.uc[0];
					 //	MessageLong(1,2,tmp);
				  //		addrRAM = (unsigned char *)0x21000000;   //t
				 //t		addrRAM = (unsigned char *)ul2uc.ul;
						ui2uc.uc[0] = embMsg.Body(4);
						ui2uc.uc[1] = embMsg.Body(5);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

						shift = ui2uc.ui;
						ui2uc.uc[0] = embMsg.Body(6);
						ui2uc.uc[1] = embMsg.Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
   						len = ui2uc.ui;
						temp_crc=0;
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());						
						embMsgAns.SetType(0x06);
						embMsgAns.SetLength(len+10);
//_________________ok
				 		embMsgAns.SetBody(0,embMsg.Body(0));
						embMsgAns.SetBody(1,embMsg.Body(1));
						embMsgAns.SetBody(2,embMsg.Body(2));
						embMsgAns.SetBody(3,embMsg.Body(3));
						embMsgAns.SetBody(4,embMsg.Body(4));
						embMsgAns.SetBody(5,embMsg.Body(5));
						embMsgAns.SetBody(6,embMsg.Body(6));
						embMsgAns.SetBody(7,embMsg.Body(7));
						if(ul2uc.uc[3] == 0x80) //port : if try read nvram
						{
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
				case 0x0C:
					embMsgAns.SetTOM(0x20);
					embMsgAns.SetAddrI(SelfID());
					embMsgAns.SetAddrS(SelfID());
					embMsgAns.SetType(0x0C);
					embMsgAns.SetLength(0);
///
  		 			CfgCard();
		 		//t	SaveCommut();
			  //t		SaveCommut1();	  //t
				    StartSaveCommut();
  					embMsg.Init();
					break;
				case 0x09:
					break;
				case 0x0A:
//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
					break;
				case 0x0B:
//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
					break;
				}	// type
		  //	   MessageChar(1,1,5);
		    	embMsgAns.SetCycle(cycle++);
				embMsgAns.CalcCRC();
				embRS232.Trans(0x55);
				embRS232.Trans(0xAA);
				for(i=0; i < embMsgAns.FullSize(); i++) 
				{
					switch(embMsgAns.body[i])
					{
					case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
					case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
					case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
					case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
					default:   embRS232.Trans(embMsgAns.body[i]);
					}
				}
				embRS232.Trans(0x55);
			//	Transmit0mf();
		 //  		my_printf(0x15);
				embMsgAns.Init();
			} //IsEnd
			
  		}  //loop while UsedReceive
 to use bmd_34 */

	//	  my_printf(0x16);
 //________________________________________________________>>from bmd_34

///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////

	  //		if(embMsg232.IsEnd())//&&embMsg.ChkCRC())

 if(embMsg485E.IsEnd()) 
				{
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
				   		// ->>	// Ioaao a RS-232
							aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();
							embMsg485E.SetAddrI(aR);
							embMsg485E.SetAddrS(aI);
							embMsg485E.SetAddrR(aS);
							embRS232.TransEC(0x55);
							embRS232.TransEC(0xAA);
							for(i=0; i<embMsg485E.FullSize(); i++) 
							{
								switch(embMsg485E.body[i])
								{
								case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
								case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
								case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
								case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
								default: embRS232.TransEC(embMsg485E.body[i]);
								}
							}
							embRS232.TransEC(0x55);
						 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);	
							embRS232.Trans_RDN_Full(embRS232.HostMAC);	
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
			 //					tBuffEmbMsgEast.Add(embMsg485E);
			 //					tBuffEmbMsgWest.Add(embMsg485E);
			 //					unEmb2NetStat.emb2NetStat.selfPacketSend++;	
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
//_______________________________________________________________________
//hier betveen msg can receive from ethernet with disabling - no data will be added to end of buffer
//_______________________________________________________________________

					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
					 // ->>	// Ioaao a RS-232
												aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aR);
							embMsg485.SetAddrS(aI);
							embMsg485.SetAddrR(aS);
							embRS232.TransEC(0x55);
							embRS232.TransEC(0xAA);
						 //	printf("\n\r>");
							for(i=0; i<embMsg485.FullSize(); i++) 
							{
							
						//	 printf(".%02X",embMsg485.body[i]);
								switch(embMsg485.body[i])
								{
								case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
								case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
								case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
								case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
								default: embRS232.TransEC(embMsg485.body[i]);
								}
							}
							embRS232.TransEC(0x55);
						 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
							embRS232.Trans_RDN_Full(embRS232.HostMAC);		
					}
					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{

						// ->>	// Транзитом ответ в линию
							if(embMsg485.TOM()&0x01)
							{
								aI = embMsg485.AddrI();
								aS = embMsg485.AddrS();
								aR = embMsg485.AddrR();
								embMsg485.SetAddrI(aS);
								embMsg485.SetAddrS(aR);
								embMsg485.SetAddrR(aI);
		//for mf20 not need	   	tBuffEmbMsgEast.Add(embMsg485);
		//for mf20 not need	   	tBuffEmbMsgWest.Add(embMsg485);
		//for mf20 not need	   	unEmb2NetStat.emb2NetStat.selfPacketSend++;							
							}
							else
							{
								// ->>	// Получили запрос из RS-485
								flagRequest=3;
								embMsg485.SetRS485();
								embMsgRequest = &embMsg485;
						   //		printf("flagrequest = 3");
						//no		my_printf(0x23);
							} //TOM
						}	//R==S
					
					}	  //IsEnd
	   //	if(++i485>10) break; //t my

				}
	else //1024

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
			     else if(embMsg232E.IsEnd())//&&embMsg.ChkCRC())
  			{
				{
			  //	  embMsgRequest = &embMsg;
			  		embMsgRequest = &embMsg232E;
					flagRequest=5;	//new
				//	my_printf(0x20);   //t
				}
			}
//________________________________________________________________________232e	

			else
			{
				if(rBuffEmbMsg.Used())
				{

					EmbMsg embMsgA;
					embMsgA.Init();	 //30

					rBuffEmbMsg.Get(embMsgA);
			  					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//или равен 0000 или FFFF
							{
							 			
								embRS232.TransEC(0x55);
								embRS232.TransEC(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
						  //30		printf(".%02X", embMsgA.body[i]);
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
									case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
									case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
									case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
									default: embRS232.TransEC(embMsgA.body[i]);
									}
								}
								embRS232.TransEC(0x55);
							  //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
								embRS232.Trans_RDN_Full(embRS232.HostMAC);		
								flagRequest = 0;
							}
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
		   	 //	my_printf(0x21);   //t

				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
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
				   /*
				   //	 if(flagRequest && (flagRequest!=3))  //my
		 				{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

						  //		my_printf(0x21); //test
							
							embRS485.Trans(0x55);
							embRS485.Trans(0xAA);
							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgRequest->body[i]);
								}
							}
							embRS485.Trans(0x55);
						//t	embRS485.Trans_RDN(0xFFFF);
							embRS485.Trans_RDN(embMsgRequest->AddrS());
						 //no	 my_printf(0x24);
						 */
							flagRequest = 0;
						}
						else
						{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
					   //t		embMsgAns.SetAddrI(aR);
						//t	embMsgAns.SetAddrS(aI);
						//t	embMsgAns.SetAddrR(aS);

					 //  	aI = embMsgRequest->AddrI();
					 //	aS = embMsgRequest->AddrS();
					 //	aR = embMsgRequest->AddrR();

					 	embMsgAns.SetAddrI(aS);	 //t
					 	embMsgAns.SetAddrS(aI);	 //t
					 	embMsgAns.SetAddrR(aR);	 //t

					 //		 my_printf(0x25);
						}
					}
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}

					switch(embMsgRequest->Type())
					{

//____________________________________________>> here are commands for bmd_34
/*
					case 0x01: // запрос типа
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;
					case 0x07: /// Генерим запрос маркера во все направления
		 //				if(ready_transit) old_ready_transit=0;
		 //				if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Запрос состояния
						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
				//		for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155.byte[i]);
				//		unStateBMD155.stateBMD155.count_block=0;
				//		unStateBMD155.stateBMD155.count_no_correct_block1=0;
				//		unStateBMD155.stateBMD155.count_no_correct_block2=0;
				//		unStateBMD155.stateBMD155.count_no_correct_result=0;
				//		unStateBMD155.stateBMD155.count_notRS1=0;
				//		unStateBMD155.stateBMD155.count_notRS2=0;
				//		unStateBMD155.stateBMD155.demPI=0;
				//		unStateBMD155.stateBMD155.loopPI=0;
				//		unStateBMD155.stateBMD155.statePI=0;
						break;
					case 0x09:
						if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
				 //				send1[0]=embMsgRequest->Body(1);
				 //				send1[1]=embMsgRequest->Body(2);
							}
							if(embMsgRequest->Body(0)==2)
							{
				//				send2[0]=embMsgRequest->Body(1);
				//				send2[1]=embMsgRequest->Body(2);
							}
						}
						else
						{
							switch(embMsgRequest->Body(1))
							{
							case 0x11: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFD)|0x02);
								else outportb(0x583,inportb(0x583)&0xFD);
								break;
							case 0x12: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFE)|0x01);
								else outportb(0x583,inportb(0x583)&0xFE);
								break;
							}
						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(3);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
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
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
						case 0x0D:
							embMsgAns.SetType(0x0D);
							embMsgAns.SetLength(34);
					//		for(i=0; i<34; i++) embMsgAns.SetBody(i,unEmb2NetStat.byte[i]);
					//		unEmb2NetStat.emb2NetStat.markerTime = 0;
					//		unEmb2NetStat.emb2NetStat.buffModPm = 0;
					//		unEmb2NetStat.emb2NetStat.buffTransPm = 0;
					//		unEmb2NetStat.emb2NetStat.buffModPd = 0;
					//		unEmb2NetStat.emb2NetStat.buffTransPd = 0;
					//		unEmb2NetStat.emb2NetStat.buff232Pm = 0;
					//		unEmb2NetStat.emb2NetStat.buff232Pd = 0;
				   //			unEmb2NetStat.emb2NetStat.ready_transit=0;
				   //			unEmb2NetStat.emb2NetStat.ready_mod=1;
						break;
					case 0x13:
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);

   //							bt = (unsigned char far*)0x80000000;
							   bt = (unsigned char *)(NVRAM_BASE);

							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x14: // Запрос состояния
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
		  //					for(i=0; i<42; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
						break;
					case 0x15:
						break;
					}
		   */
//______________________________upper are commands for bmd_34
//______________________________________________>> commands for mf_20
				  	case 0x01: // запрос типа
				//	printf("\n\r01>"); 
//__________________________________________________________________________________
 //	  Ring(1,1,5,1);
				   //t		embMsgAns.SetTOM(0x20);
				  // 		embMsgAns.SetAddrI(SelfID());  //t
				  //  	embMsgAns.SetAddrS(SelfID());  //t
				  if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}			
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
					case 0x05: // Загрузка файла (запись в устройство) 
//printEthLongHex(0x5);
 			   	 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);


				  		ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);

						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

				  		shift = ui2uc.ui;
//printEthLongHex(shift);

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

// printEthLongHex(ul2uc.ul);

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
//printEthLongHex(shift);
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



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//__________________________________________________________________________________
  /*
				   //	  Ring(1,1,5,1);
				   //		embMsgAns.SetTOM(0x20);
				   //t		embMsgAns.SetAddrI(SelfID());
				   //t		embMsgAns.SetAddrS(SelfID());
					//	embMsgAns.SetType(0x01);
				   //		embMsgAns.SetLength(44);
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
					//	break;


					case 0x35:	 //start write to ram buffer
				 //	 printEthByteHex(0x35);	  //t
						write_buffer_char( 0, START_WRITE_BUFFER);
						if(flagRequest == 1) 
						{
					  	embMsgAns.SetTOM(0x20);
			  			embMsgAns.SetAddrI(SelfID());
			  			embMsgAns.SetAddrS(SelfID());
						}
						embMsgAns.SetType(0x35);
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

					case 0x05: // Загрузка файла (запись в устройство) 
 			   //		printEthByteHex(0x05);
			  //		printf("\n\r05> flagRequest = %02X", flagRequest);
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>	
				//   	   if(test != 74)
				//   	   {
				//   	   test = 74;
	   			 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);
				  //t		addrRAM = (unsigned char *)ul2uc.ul;
				  //		addrRAM = (unsigned char *)0x21000000; //t
					//wb ao		   if(test != 74)
				   	//   {
				   //	   test = 74;

						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				  // wbad aok	    if(test != 74)
				   	//   {
				   	  // test = 74;
						shift = ui2uc.ui;
		   //wb ao			   }
						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				 		len = ui2uc.ui;
				//  }
				   //	 	   shift = 0; //ab wo
				  //			len = 128;  //t
				  //	 } //test


			 			temp_crc=0;

			 			for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);

		   				ui2uc.uc[0] = embMsgRequest->Body(len+8);
		   				ui2uc.uc[1] = embMsgRequest->Body(len+9);
		   				ui2uc.uc[2] = 0;  //1107
						ui2uc.uc[3] = 0;  //1107



					//off	if(ui2uc.ui==temp_crc)
			   		 //	{
						if(ul2uc.uc[3] == 0x80) //port : if try use nvram
						{
	  			 		 for(i=0; i<len; i++)
				  		   {
		  			   //   *(addrRAM+i+shift)= embMsgRequest->Body(i+8);
		   	  	   			write_nvram_char(i + shift, embMsgRequest->Body(i+8));
				  		   }
						 }
						 else  //enover memory
						 {
					 //	 printEthByteHex(0x51);
//#ifdef USE_PULT
			  //			     Ring(1,1,5,4);
//#endif //USE_PULT
			  //				write_buffer_char( embMsgRequest->Body(i+8), START_WRITE_BUFFER);
				 //		   printEthLongHex(len);
						  for(i=0; i<len; i++)
				  		   {
				  		   	tmp =write_buffer_char( embMsgRequest->Body(i+8), NO_START_WRITE_BUFFER);
						   }
					//	    printEthLongHex(tmp);
						 }
				  	 //t	} //crc
				 	 //  }//test
 						/// формируем ответ ///
						if(flagRequest == 1) 
					{

			  			embMsgAns.SetTOM(0x20);
			  			embMsgAns.SetAddrI(SelfID());
			  			embMsgAns.SetAddrS(SelfID());
					}
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
					case 0x36:	 //check control sum and write to flash
				 //	 printEthLongHex(0x112);

 				 //	printEthByteHex(0x36);
					  //	write_buffer_char( embMsgRequest->Body(i+8), START_WRITE_BUFFER);
					  switch((embMsgRequest->Body(0)))
					  {
					   case 1:   ProgWrite(); break;
					   case 2:   XilWrite(); break;
					   default : break;
				      }

						if(flagRequest == 1) 
						{
					  	embMsgAns.SetTOM(0x20);
			  			embMsgAns.SetAddrI(SelfID());
			  			embMsgAns.SetAddrS(SelfID());
						}
						embMsgAns.SetType(0x36);
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

 					case 0x37:	 //check control sum and write to flash
				 //	 printEthLongHex(0x112);

 				 //	printEthByteHex(0x36);
					  //	write_buffer_char( embMsgRequest->Body(i+8), START_WRITE_BUFFER);
					    XilWrite();
						if(flagRequest == 1) 
						{
					  	embMsgAns.SetTOM(0x20);
			  			embMsgAns.SetAddrI(SelfID());
			  			embMsgAns.SetAddrS(SelfID());
						}
						embMsgAns.SetType(0x37);
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
		case 0x38:	 //restart
				 //	 printEthLongHex(0x112);

 				 //	printEthByteHex(0x36);
					  //	write_buffer_char( embMsgRequest->Body(i+8), START_WRITE_BUFFER);
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
						dev_restart(); //answer do not get	
					break;

					case 0x39:	 //test mode
				 //	 printEthLongHex(0x112);

 				 //	printEthByteHex(0x36);
					  //	write_buffer_char( embMsgRequest->Body(i+8), START_WRITE_BUFFER);
					  						if(flagRequest == 1) 
						{
					  	embMsgAns.SetTOM(0x20);
			  			embMsgAns.SetAddrI(SelfID());
			  			embMsgAns.SetAddrS(SelfID());
						}
						embMsgAns.SetType(0x39);
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
						set_test_mode((unsigned long)embMsgRequest->Body(0)); //answer do not get	
					break;


	  */

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
					mf20_init();
					Autodetect(unEmb2TypeVer);
					CfgCard();
					SaveCommut();
//____________________________________________________
  		 		 //	CfgCard();
		 	   //		SaveCommut();
			  //t		SaveCommut1();	  //t
			  	 //   StartSaveCommut();
  					embMsg.Init();
					break;
				case 0x09:
					break;
				case 0x0A:
//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
					break;
				case 0x0B:
//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
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
		  //	   MessageChar(1,1,5);


 //________________for using from bmd_34
	   /*
		    	embMsgAns.SetCycle(cycle++);
				embMsgAns.CalcCRC();
				embRS232.Trans(0x55);
				embRS232.Trans(0xAA);
				for(i=0; i < embMsgAns.FullSize(); i++) 
				{
					switch(embMsgAns.body[i])
					{
					case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
					case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
					case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
					case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
					default:   embRS232.Trans(embMsgAns.body[i]);
					}
				}
				embRS232.Trans(0x55);
			//	Transmit0mf();
		 //  		my_printf(0x15);
				embMsgAns.Init();
				*/
 //____________________________comment for using bmd_34
//______________________________________________<< commands for mf_20

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
					 	flagRequest = 0;
					}
//___________________________________________________________________________________232e
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
					 //	embRS232.EmptyReceiveE();	
					  	embMsgAns.Init(); //my as in mf_20 previons
					 	flagRequest = 0;
					}
//______________________________________________________________________________________232e


					if(flagRequest == 3) 
					{

			 //	  	 my_printf(0x26);	//t
   //					  printf("\n\r>");
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
	   //						printf(".%02X",embMsgAns.body[i]);
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
				//t		embRS485.Trans_RDN(0xFFFF); //send to ethernet
			//	printf("\n\r Used 2");

			   //			embRS485.Trans_RDN(embMsgAns.AddrS()); //send to ethernet
			  //t		embRS485.Init(38400); //t my
						embRS485.EmptyReceive();
			   //		embMsg485.Init(); // t my
						flagRequest = 0;
					}
//_________________________________________________________________________________RDN
			 
				if(flagRequest == 4) 
			   	{ 
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

			 			  embRS485.Trans_RDN(embMsgAns.AddrS());
							embRS485.EmptyReceiveE();

								flagRequest = 0;
					}	// ==3
					
 //________________________________________________________________________________________RDN

				}
				else
				{
					if(flagRequest == 1) 
					{
//						if((ready_transit)||(ready_mod))
						{
//							tBuffEmbMsgEast.Add(embMsg232);
//							tBuffEmbMsgWest.Add(embMsg232);
//							unEmb2NetStat.emb2NetStat.selfPacketSend++;
						}
					}
					else
		   //				embMsg232.Init();
				embMsg.Init();
 				}
		
				if(flagRequest == 2) 
				{
					// поставить в буффер на передачу в сеть в соответствии с dir
//					if((ready_transit)||(ready_mod))
					{
//						tBuffEmbMsgEast.Add(embMsgAns);
//						tBuffEmbMsgWest.Add(embMsgAns);
//						unEmb2NetStat.emb2NetStat.selfPacketSend++;
					}
				}
				flagRequest = 0;
				embMsgRequest = NULL;
}

//t } //try close loop while hier


//_________________________________________________________<<from bmd_34




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


//____________________________TESTS_____________________________________
#if TESTS_ENABLED
void wr_cosv(unsigned char slot, unsigned int short  addr,unsigned char data)
{ 
  outportb(0x500|((unsigned char) (slot*16 & 0xf0))|0x01, (unsigned char) (addr>>8 ));   // base H adr
  outportb(0x500|((unsigned char) (slot*16 & 0xf0))|0x00,(unsigned char) addr);           // base L adr
  outportb(0x500|(slot*16 & 0xf0)|0x0f,data);                       // read from window
} 

unsigned char SLOTE = 0x00;

unsigned char sch1_e1[128] = 
{
0,0,   //rx0
8,4,   //rx1
8,5,   //rx2
8,6,   //rx3
8,7,   //rx4
8,8,   //rx5
8,9,   //rx6
8,10,   //rx7
8,11,   //rx8
8,12,   //rx9
8,13,   //rx10
8,14,   //rx11
8,15,   //rx12
8,16,   //rx13
8,17,   //rx14
8,18,   //rx15
0,0,   //rx16
8,19,   //rx17
8,20,   //rx18
8,21,   //rx19
8,22,   //rx20
8,23,   //rx21
8,24,   //rx22
8,25,   //rx23
8,26,   //rx24
8,27,   //rx25
8,28,   //rx26
8,29,   //rx27
8,30,   //rx28
8,31,   //rx29
9,0,   //rx30
9,1,   //rx31
0,0,   //tx0
4,4,   //tx1
4,5,   //tx2
4,6,   //tx3
4,7,   //tx4
4,8,   //tx5
4,9,   //tx6
4,10,   //tx7
4,11,   //tx8
4,12,   //tx9
4,13,   //tx10
4,14,   //tx11
4,15,   //tx12
4,16,   //tx13
4,17,   //tx14
4,18,   //tx15
0,0,   //tx16
4,19,   //tx17
4,20,   //tx18
4,21,   //tx19
4,22,   //tx20
4,23,   //tx21
4,24,   //tx22
4,25,   //tx23
4,26,   //tx24
4,27,   //tx25
4,28,   //tx26
4,29,   //tx27
4,30,   //tx28
4,31,   //tx29
5,0,   //tx30
5,1,   //tx31
};

unsigned char sch2_e1[128] = 
{
0,0,   //rx0
9,2,   //rx1
9,3,   //rx2
9,4,   //rx3
9,5,   //rx4
9,6,   //rx5
9,7,   //rx6
9,8,   //rx7
9,9,   //rx8
9,10,   //rx9
9,11,   //rx10
9,12,   //rx11
9,13,   //rx12
9,14,   //rx13
9,15,   //rx14
9,16,   //rx15
9,0,   //rx16
9,17,   //rx17
9,18,   //rx18
9,19,   //rx19
9,20,   //rx20
9,21,   //rx21
9,22,   //rx22
9,23,   //rx23
9,24,   //rx24
9,25,   //rx25
9,26,   //rx26
9,27,   //rx27
9,28,   //rx28
9,29,   //rx29
9,30,   //rx30
9,31,   //rx31
0,0,   //tx0
5,2,   //tx1
5,3,   //tx2
5,4,   //tx3
5,5,   //tx4
5,6,   //tx5
5,7,   //tx6
5,8,   //tx7
5,9,   //tx8
5,10,   //tx9
5,11,   //tx10
5,12,   //tx11
5,13,   //tx12
5,14,   //tx13
5,15,   //tx14
5,16,   //tx15
0,0,   //tx16
5,17,   //tx17
5,18,   //tx18
5,19,   //tx19
5,20,   //tx20
5,21,   //tx21
5,22,   //tx22
5,23,   //tx23
5,24,   //tx24
5,25,   //tx25
5,26,   //tx26
5,27,   //tx27
5,28,   //tx28
5,29,   //tx29
5,30,   //tx30
5,31,   //tx31
};

unsigned char sch3_e1[128] = 
{

28,0,   //tx0
28,1,   //tx1
28,2,   //tx2
28,3,   //tx3
28,4,   //tx4
28,5,   //tx5
28,6,   //tx6
28,7,   //tx7
28,8,   //tx8
28,9,   //tx9
28,10,   //tx10
28,11,   //tx11
28,12,   //tx12
28,13,   //tx13
28,14,   //tx14
28,15,   //tx15
28,16,   //tx16
28,17,   //tx17
28,18,   //tx18
28,19,   //tx19
28,20,   //tx20
28,21,   //tx21
28,22,   //tx22
28,23,   //tx23
28,24,   //tx24
28,25,   //tx25
28,26,   //tx26
28,27,   //tx27
28,28,   //tx28
28,29,   //tx29
28,30,   //tx30
28,31,   //tx31

28,0,   //tx0
28,1,   //tx1
28,2,   //tx2
28,3,   //tx3
28,4,   //tx4
28,5,   //tx5
28,6,   //tx6
28,7,   //tx7
28,8,   //tx8
28,9,   //tx9
28,10,   //tx10
28,11,   //tx11
28,12,   //tx12
28,13,   //tx13
28,14,   //tx14
28,15,   //tx15
28,16,   //tx16
28,17,   //tx17
28,18,   //tx18
28,19,   //tx19
28,20,   //tx20
28,21,   //tx21
28,22,   //tx22
28,23,   //tx23
28,24,   //tx24
28,25,   //tx25
28,26,   //tx26
28,27,   //tx27
28,28,   //tx28
28,29,   //tx29
28,30,   //tx30
28,31,   //tx31

};

void Init_Test_Data()
{
 SLOTE = 0x00;
 //______________________________________sch1
 sch1_e1[0]  = 0;  sch1_e1[1]  = 0;
 sch1_e1[2]  = 8;  sch1_e1[3]  = 4;
 sch1_e1[4]  = 8;  sch1_e1[5]  = 5;
 sch1_e1[6]  = 8;  sch1_e1[7]  = 6;
 sch1_e1[8]  = 8;  sch1_e1[9]  = 7;
 sch1_e1[10] = 8;  sch1_e1[11] = 8;
 sch1_e1[12] = 8;  sch1_e1[13] = 9;
 sch1_e1[14] = 8;  sch1_e1[15] = 10;
 sch1_e1[16] = 8;  sch1_e1[17] = 11;
 sch1_e1[18] = 8;  sch1_e1[19] = 12;
 sch1_e1[20] = 8;  sch1_e1[21] = 13;
 sch1_e1[22] = 8;  sch1_e1[23] = 14;
 sch1_e1[24] = 8;  sch1_e1[25] = 15;
 sch1_e1[26] = 8;  sch1_e1[27] = 16;
 sch1_e1[28] = 8;  sch1_e1[29] = 17;
 sch1_e1[30] = 8;  sch1_e1[31] = 18;
 sch1_e1[32] = 0;  sch1_e1[33] = 0;
 sch1_e1[34] = 8;  sch1_e1[35] = 19;
 sch1_e1[36] = 8;  sch1_e1[37] = 20;
 sch1_e1[38] = 8;  sch1_e1[39] = 21;
 sch1_e1[40] = 8;  sch1_e1[41] = 22;
 sch1_e1[42] = 8;  sch1_e1[43] = 23;
 sch1_e1[44] = 8;  sch1_e1[45] = 24;
 sch1_e1[46] = 8;  sch1_e1[47] = 25;
 sch1_e1[48] = 8;  sch1_e1[49] = 26;
 sch1_e1[50] = 8;  sch1_e1[51] = 27;
 sch1_e1[52] = 8;  sch1_e1[53] = 28;
 sch1_e1[54] = 8;  sch1_e1[55] = 29;
 sch1_e1[56] = 8;  sch1_e1[57] = 30;
 sch1_e1[58] = 8;  sch1_e1[59] = 31;
 sch1_e1[60] = 9;  sch1_e1[61] = 0;
 sch1_e1[62] = 9;  sch1_e1[63] = 1;
 sch1_e1[64] = 0;  sch1_e1[65] = 0;
 sch1_e1[66] = 4;  sch1_e1[67]  = 4;
 sch1_e1[68] = 4;  sch1_e1[69]  = 5;
 sch1_e1[70] = 4;  sch1_e1[71]  = 6;
 sch1_e1[72] = 4;  sch1_e1[73]  = 7;
 sch1_e1[74] = 4;  sch1_e1[75] = 8;
 sch1_e1[76] = 4;  sch1_e1[77] = 9;
 sch1_e1[78] = 4;  sch1_e1[79] = 10;
 sch1_e1[80] = 4;  sch1_e1[81] = 11;
 sch1_e1[82] = 4;  sch1_e1[83] = 12;
 sch1_e1[84] = 4;  sch1_e1[85] = 13;
 sch1_e1[86] = 4;  sch1_e1[87] = 14;
 sch1_e1[88] = 4;  sch1_e1[89] = 15;
 sch1_e1[90] = 4;  sch1_e1[91] = 16;
 sch1_e1[92] = 4;  sch1_e1[93] = 17;
 sch1_e1[94] = 4;  sch1_e1[95] = 18;
 sch1_e1[96] = 4;  sch1_e1[97] = 0;
 sch1_e1[98] = 4;  sch1_e1[99] = 19;
 sch1_e1[100] = 4;  sch1_e1[101] = 20;
 sch1_e1[102] = 4;  sch1_e1[103] = 21;
 sch1_e1[104] = 4;  sch1_e1[105] = 22;
 sch1_e1[106] = 4;  sch1_e1[107] = 23;
 sch1_e1[108] = 4;  sch1_e1[109] = 24;
 sch1_e1[110] = 4;  sch1_e1[111] = 25;
 sch1_e1[112] = 4;  sch1_e1[113] = 26;
 sch1_e1[114] = 4;  sch1_e1[115] = 27;
 sch1_e1[116] = 4;  sch1_e1[117] = 28;
 sch1_e1[118] = 4;  sch1_e1[119] = 29;
 sch1_e1[120] = 4;  sch1_e1[121] = 30;
 sch1_e1[122] = 4;  sch1_e1[123] = 31;
 sch1_e1[124] = 5;  sch1_e1[125] = 0;
 sch1_e1[126] = 5;  sch1_e1[127] = 1;
//______________________________________
//______________________________________sch2
 sch2_e1[0]  = 0;  sch2_e1[1]  = 0;
 sch2_e1[2]  = 9;  sch2_e1[3]  = 2;
 sch2_e1[4]  = 9;  sch2_e1[5]  = 3;
 sch2_e1[6]  = 9;  sch2_e1[7]  = 4;
 sch2_e1[8]  = 9;  sch2_e1[9]  = 5;
 sch2_e1[10] = 9;  sch2_e1[11] = 6;
 sch2_e1[12] = 9;  sch2_e1[13] = 7;
 sch2_e1[14] = 9;  sch2_e1[15] = 8;
 sch2_e1[16] = 9;  sch2_e1[17] = 9;
 sch2_e1[18] = 9;  sch2_e1[19] = 10;
 sch2_e1[20] = 9;  sch2_e1[21] = 11;
 sch2_e1[22] = 9;  sch2_e1[23] = 12;
 sch2_e1[24] = 9;  sch2_e1[25] = 13;
 sch2_e1[26] = 9;  sch2_e1[27] = 14;
 sch2_e1[28] = 9;  sch2_e1[29] = 15;
 sch2_e1[30] = 9;  sch2_e1[31] = 16;
 sch2_e1[32] = 9;  sch2_e1[33] = 0;
 sch2_e1[34] = 9;  sch2_e1[35] = 17;
 sch2_e1[36] = 9;  sch2_e1[37] = 18;
 sch2_e1[38] = 9;  sch2_e1[39] = 19;
 sch2_e1[40] = 9;  sch2_e1[41] = 20;
 sch2_e1[42] = 9;  sch2_e1[43] = 21;
 sch2_e1[44] = 9;  sch2_e1[45] = 22;
 sch2_e1[46] = 9;  sch2_e1[47] = 23;
 sch2_e1[48] = 9;  sch2_e1[49] = 24;
 sch2_e1[50] = 9;  sch2_e1[51] = 25;
 sch2_e1[52] = 9;  sch2_e1[53] = 26;
 sch2_e1[54] = 9;  sch2_e1[55] = 27;
 sch2_e1[56] = 9;  sch2_e1[57] = 28;
 sch2_e1[58] = 9;  sch2_e1[59] = 29;
 sch2_e1[60] = 9;  sch2_e1[61] = 30;
 sch2_e1[62] = 9;  sch2_e1[63] = 31;
 sch2_e1[64] = 0;  sch2_e1[65] = 0;
 sch2_e1[66] = 5;  sch2_e1[67]   = 2;
 sch2_e1[68] = 5;  sch2_e1[69]   = 3;
 sch2_e1[70] = 5;  sch2_e1[71]   = 4;
 sch2_e1[72] = 5;  sch2_e1[73]   = 5;
 sch2_e1[74] = 5;  sch2_e1[75]   = 6;
 sch2_e1[76] = 5;  sch2_e1[77]   = 7;
 sch2_e1[78] = 5;  sch2_e1[79]   = 8;
 sch2_e1[80] = 5;  sch2_e1[81]   = 9;
 sch2_e1[82] = 5;  sch2_e1[83]   = 10;
 sch2_e1[84] = 5;  sch2_e1[85]   = 11;
 sch2_e1[86] = 5;  sch2_e1[87]   = 12;
 sch2_e1[88] = 5;  sch2_e1[89]   = 13;
 sch2_e1[90] = 5;  sch2_e1[91]   = 14;
 sch2_e1[92] = 5;  sch2_e1[93]   = 15;
 sch2_e1[94] = 5;  sch2_e1[95]   = 16;
 sch2_e1[96] = 5;  sch2_e1[97]   = 0;
 sch2_e1[98]  = 5;  sch2_e1[99]  = 17;
 sch2_e1[100] = 5;  sch2_e1[101] = 18;
 sch2_e1[102] = 5;  sch2_e1[103] = 19;
 sch2_e1[104] = 5;  sch2_e1[105] = 20;
 sch2_e1[106] = 5;  sch2_e1[107] = 21;
 sch2_e1[108] = 5;  sch2_e1[109] = 22;
 sch2_e1[110] = 5;  sch2_e1[111] = 23;
 sch2_e1[112] = 5;  sch2_e1[113] = 24;
 sch2_e1[114] = 5;  sch2_e1[115] = 25;
 sch2_e1[116] = 5;  sch2_e1[117] = 26;
 sch2_e1[118] = 5;  sch2_e1[119] = 27;
 sch2_e1[120] = 5;  sch2_e1[121] = 28;
 sch2_e1[122] = 5;  sch2_e1[123] = 29;
 sch2_e1[124] = 5;  sch2_e1[125] = 30;
 sch2_e1[126] = 5;  sch2_e1[127] = 31;
//______________________________________
//______________________________________sch3
 sch3_e1[0]  = 28;  sch3_e1[1]  = 0;
 sch3_e1[2]  = 28;  sch3_e1[3]  = 1;
 sch3_e1[4]  = 28;  sch3_e1[5]  = 2;
 sch3_e1[6]  = 28;  sch3_e1[7]  = 3;
 sch3_e1[8]  = 28;  sch3_e1[9]  = 4;
 sch3_e1[10] = 28;  sch3_e1[11] = 5;
 sch3_e1[12] = 28;  sch3_e1[13] = 6;
 sch3_e1[14] = 28;  sch3_e1[15] = 7;
 sch3_e1[16] = 28;  sch3_e1[17] = 8;
 sch3_e1[18] = 28;  sch3_e1[19] = 9;
 sch3_e1[20] = 28;  sch3_e1[21] = 10;
 sch3_e1[22] = 28;  sch3_e1[23] = 11;
 sch3_e1[24] = 28;  sch3_e1[25] = 12;
 sch3_e1[26] = 28;  sch3_e1[27] = 13;
 sch3_e1[28] = 28;  sch3_e1[29] = 14;
 sch3_e1[30] = 28;  sch3_e1[31] = 15;
 sch3_e1[32] = 28;  sch3_e1[33] = 16;
 sch3_e1[34] = 28;  sch3_e1[35] = 17;
 sch3_e1[36] = 28;  sch3_e1[37] = 18;
 sch3_e1[38] = 28;  sch3_e1[39] = 19;
 sch3_e1[40] = 28;  sch3_e1[41] = 20;
 sch3_e1[42] = 28;  sch3_e1[43] = 21;
 sch3_e1[44] = 28;  sch3_e1[45] = 22;
 sch3_e1[46] = 28;  sch3_e1[47] = 23;
 sch3_e1[48] = 28;  sch3_e1[49] = 24;
 sch3_e1[50] = 28;  sch3_e1[51] = 25;
 sch3_e1[52] = 28;  sch3_e1[53] = 26;
 sch3_e1[54] = 28;  sch3_e1[55] = 27;
 sch3_e1[56] = 28;  sch3_e1[57] = 28;
 sch3_e1[58] = 28;  sch3_e1[59] = 29;
 sch3_e1[60] = 28;  sch3_e1[61] = 30;
 sch3_e1[62] = 28;  sch3_e1[63] = 31;
 sch3_e1[64] = 28;  sch3_e1[65] = 0;
 sch3_e1[66] = 28;  sch3_e1[67] = 1;
 sch3_e1[68] = 28;  sch3_e1[69] = 2;
 sch3_e1[70] = 28;  sch3_e1[71] = 3;
 sch3_e1[72] = 28;  sch3_e1[73] = 4;
 sch3_e1[74] = 28;  sch3_e1[75] = 5;
 sch3_e1[76] = 28;  sch3_e1[77] = 6;
 sch3_e1[78] = 28;  sch3_e1[79] = 7;
 sch3_e1[80] = 28;  sch3_e1[81] = 8;
 sch3_e1[82] = 28;  sch3_e1[83] = 9;
 sch3_e1[84] = 28;  sch3_e1[85] = 10;
 sch3_e1[86] = 28;  sch3_e1[87] = 11;
 sch3_e1[88] = 28;  sch3_e1[89] = 12;
 sch3_e1[90] = 28;  sch3_e1[91] = 13;
 sch3_e1[92] = 28;  sch3_e1[93] = 14;
 sch3_e1[94] = 28;  sch3_e1[95] = 15;
 sch3_e1[96] = 28;  sch3_e1[97] = 16;
 sch3_e1[98] = 28;  sch3_e1[99] = 17;
 sch3_e1[100] = 28;  sch3_e1[101] = 18;
 sch3_e1[102] = 28;  sch3_e1[103] = 19;
 sch3_e1[104] = 28;  sch3_e1[105] = 20;
 sch3_e1[106] = 28;  sch3_e1[107] = 21;
 sch3_e1[108] = 28;  sch3_e1[109] = 22;
 sch3_e1[110] = 28;  sch3_e1[111] = 23;
 sch3_e1[112] = 28;  sch3_e1[113] = 24;
 sch3_e1[114] = 28;  sch3_e1[115] = 25;
 sch3_e1[116] = 28;  sch3_e1[117] = 26;
 sch3_e1[118] = 28;  sch3_e1[119] = 27;
 sch3_e1[120] = 28;  sch3_e1[121] = 28;
 sch3_e1[122] = 28;  sch3_e1[123] = 29;
 sch3_e1[124] = 28;  sch3_e1[125] = 30;
 sch3_e1[126] = 28;  sch3_e1[127] = 31;
//________________________________________________
}
 
extern "C" void test_TELO()
{
Init_Test_Data();
unsigned char j, n, m, i;     
unsigned int  w;
printf("\n\r          Start the test of MF20\n\n\r");
printf("\n\r Short loop external shorting stub  \" T E L O \"\n\r");
//    embRS232.Init(384);             // Инициализация RS232 на скорость 38400 кбит/с
//      Enable();                       // Разрешаем все прерывания
// TIMMING MODE
outportb(0x507, 0x01);   // master internal
//0x91;  // master ext interface 0  1001 0001
outportb(0x508,0x04);  // off  zero   offauto
//wr_cosv(SLOTE, 9, 0x00); // status
// ini LIU 
//wr_cosv(SLOTE, 0x0220, 0x01); // 
wr_cosv(SLOTE, 0x0240, 0x0c); // 
wr_cosv(SLOTE, 0x0201, 0x18); // 
wr_cosv(SLOTE, 0x0203, 0x01); //    
wr_cosv(SLOTE, 0x021a, 0x09); // 
wr_cosv(SLOTE, 0x0240, 0x04); // 

// ini ETHERNET
wr_cosv(SLOTE, 0x0352, 0x00); // 
wr_cosv(SLOTE, 0x0351, 0x13); // 

// load E1 mode

wr_cosv(SLOTE, 0x0308, 0x00); // 
wr_cosv(SLOTE, 0x0309, 0x00); // 
wr_cosv(SLOTE, 0x030a, 0x00); // 
wr_cosv(SLOTE, 0x030b, 0x00); //  
 //ok
// load cshedule
// ch1
i=0;
for( w=0; w<0x080; )
		{
			wr_cosv(SLOTE, w, sch1_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch1_e1[i]);
	w++;
	i++;
	
		}
// ch2
i=0;
w=0x080;
for( w=0x080; w<0x100; )
		{
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
	 
		}
// ch3
i=0;
for( w=0x100; w<0x180;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
//ch4
i=0;
for( w=0x180; w<0x200;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
  //ok
// SL4 presence test 
m=0;

for( w=0x010; w<0x100; w=w+0x010 )
	{
    j=0;
	for (n=0;n<0xFF;n++)
			{
			outportb(0x500|w, i); 
			if ( inportb(0x500|w)!=i)  j=j| 0x01; 
			i++;
			outportb(0x508|w, i); 
			if (inportb(0x508|w)!=i)  j=j| 0x02; 
			i++;
			outportb(0x509|w, i); 
			if (inportb(0x509|w)!=i)  j=j| 0x04; 
			i++;
			outportb(0x50a|w, i); 
			if (inportb(0x50a|w)!=i)   j=j| 0x08; 
			i++;
			if (inportb( 0x502|w)!=0x11) j=j| 0x10 ; // identifictor triscend
			if (inportb( 0x505|w)!=0x02) j=j| 0x20 ;// identifictor xilinx
			
			}  //for
  //	ScreenAddByte(j);
   printf("%02X ", j);
  //	ScreenAddChar(' ');
	if ((m++ & 0x03) ==0x03)
	{
  //	 ScreenAddChar('_');ScreenAddChar('_');
	  printf("__");
	 }		//if
	}	//for w
   //	}//to test
 //ok
//ScreenSent();
printf("\n\r");


// ini SL4

i=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
		// ini  ock 
			outportb(0x508|w, 0x0f);   // ock
			outportb(0x509|w, 0x00);   // 0 выкл шлейф
			//outportb(0x509|w, 0x0f);   // 0F ближн шлейф
			outportb(0x50a|w, 0x0F);    //  0Fкороткая петля  FF -длинная петля
	} 
 //ok	  
 n=0;
 //t	while(n<60) // 3 min
	while(n<30) // 1,5 min
	{
		n++;
 
		m=0;
			for( w=0x010; w<0x100; w=w+0x010 )
				{
		  //		printf("\n\r");
//					ScreenAddByte(inportb( 0x50c|w));
				 printf("%02X", inportb( 0x50c|w)) ;
			   //	  ScreenAddByte(inportb( 0x50b|w));
			    printf("%02X ", inportb( 0x50c|w)) ;

			  //	  ScreenAddChar(' ');
			   if ((m++ & 0x03) ==0x03)
			   {
			   printf("__");
			//    ScreenAddChar('_');
			//   ScreenAddChar('_');
				}	//if
				}  //while
		  //	ScreenSent();
		  printf("\n\r");

			//  t2ms (3000);
			delay_mcs(600000l);
			 wd_reset();

	}

//ScreenAddString("end TELO");
//ScreenSent();
printf("\n\r End the test TELO");
printf("\n\r For property work device will be restarted...");

 //	asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor
 }


//_______________________________________________________________Test TLLO

// PROGRAMM for test load PK2 and E14 module
// PCM30 E12
extern "C" void test_TLLO()
{
Init_Test_Data();
unsigned char j, n, m, i;     
unsigned int  w, z;
printf("\n\r          Start the test of MF20\n\n\r");
printf("\n\r Test load PK2 and E14 module  \" T L L O \"\n\r");

                         
     //    embRS232.Init(384);             // Инициализация RS232 на скорость 38400 кбит/с
     //      Enable();                       // Разрешаем все прерывания

     // TIMMING MODE

outportb(0x507, 0x01);   // master internal

 //0x91;  // master ext interface 0  1001 0001
 outportb(0x508,0x04);  // off  zero   offauto

 //wr_cosv(SLOTE, 9, 0x00); // status

 // ini LIU 
//wr_cosv(SLOTE, 0x0220, 0x01); // 
wr_cosv(SLOTE, 0x0240, 0x0c); // 
wr_cosv(SLOTE, 0x0201, 0x18); // 
wr_cosv(SLOTE, 0x0203, 0x01); //    
wr_cosv(SLOTE, 0x021a, 0x09); // 
wr_cosv(SLOTE, 0x0240, 0x04); // 

// ini ETHERNET
wr_cosv(SLOTE, 0x0352, 0x00); // 
wr_cosv(SLOTE, 0x0351, 0x13); // 

// load E1 mode

wr_cosv(SLOTE, 0x0308, 0x00); // 
wr_cosv(SLOTE, 0x0309, 0x00); // 
wr_cosv(SLOTE, 0x030a, 0x00); // 
wr_cosv(SLOTE, 0x030b, 0x00); //  


// load cshedule
// ch1
i=0;
for( w=0; w<0x080; )
		{
			wr_cosv(SLOTE, w, sch1_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch1_e1[i]);
	w++;
	i++;
	
		}
// ch2
i=0;
w=0x080;
for( w=0x080; w<0x100; )
		{
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
	 
		}
// ch3
i=0;
for( w=0x100; w<0x180;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
//ch4
i=0;
for( w=0x180; w<0x200;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}

// SL4 presence test 
m=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
    j=0;
	for (n=0;n<0xFF;n++)
			{
			outportb(0x500|w, i); 
			if ( inportb(0x500|w)!=i)  j=j| 0x01; 
			i++;
			outportb(0x508|w, i); 
			if (inportb(0x508|w)!=i)  j=j| 0x02; 
			i++;
			outportb(0x509|w, i); 
			if (inportb(0x509|w)!=i)  j=j| 0x04; 
			i++;
			outportb(0x50a|w, i); 
			if (inportb(0x50a|w)!=i)   j=j| 0x08; 
			i++;
			if (inportb( 0x502|w)!=0x11) j=j| 0x10 ; // identifictor triscend
			if (inportb( 0x505|w)!=0x02) j=j| 0x20 ;// identifictor xilinx
			
			}
//	ScreenAddByte(j);
//	ScreenAddChar(' ');
	 printf("%02X ", j);

	if ((m++ & 0x03) ==0x03)
	{ 
   //	ScreenAddChar('_');ScreenAddChar('_');
	  printf("__");
	}		
	}

//ScreenSent();
printf("\n\r");

// ini SL4

i=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
outportb(0x508|w, 0xff);  
outportb(0x507|w, 0x80);  
	for( z=0; z<0x01fff; z++);
outportb(0x507| w, 0x80);  
	for( z=0; z<0x01fff; z++);

			for (j=0; j<4; j++)
			{
					outportb(0x507| w, 0x98 | j );  // 4 - wire
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 0x10);  
			   for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x84 | j );  // level out +4
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 45);  //
					for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x88 | j );  // level input  -13
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 39);  //
					for( z=0; z<0x01fff; z++);
			
			 } 
		// ini  ock 
			outportb(0x508|w, 0x0f);   // ock
			//outportb(0x509|w, 0x00);   // 0 выкл шлейф
			outportb(0x509|w, 0x0f);   // 0F ближн шлейф
			outportb(0x50a|w, 0xFF);    //  0Fкороткая петля  FF -длинная петля
	}   
  //	while(1)
n=0;
 //t	while(n<60) // 3 min
	while(n < 20) // 0,5 min

	{
	n++;
	// timer 2 time delay , time in ms 
		 m=0;
			for( w=0x010; w<0x100; w=w+0x010 )
				{
			   //		ScreenAddByte(inportb( 0x50c|w));
				   printf("%02X", inportb( 0x50c|w)) ;
			 //ScreenAddByte(inportb( 0x50b|w));
				   printf("%02X ", inportb( 0x50d|w)) ;

			//	  ScreenAddChar(' ');
			   if ((m++ & 0x03) ==0x03)
			   { 
		  //	   ScreenAddChar('_');ScreenAddChar('_');
			   	printf("__");
			   }
				}
		//	ScreenSent();
		printf("\n\r");

			//  t2ms (3000);
			 delay_mcs(600000l);
			 wd_reset();

	}
  //	asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor
  printf("\n\r End the test TLLO");
printf("\n\r For property work device will be restarted...");

}
//_______________________________________________________________Test TLLO
//_______________________________________________________________BUS Test
extern "C" void test_BUS()
{
 unsigned char j, n, m, i, c;     
 unsigned int w;

//ScreenSetBuffer();
//ScreenAddString("тест обмена по шине по адресу 0");
//ScreenSent();
  printf("\n\r Start MF20 BUS Test\n\r");

//  presence test 
c=0;
 //t	while(n<60) // 3 min
	while(c < 20) // 0,5 min
	{
	c++;
	m=0;
	for( w=0x00; w<0x100; w=w+0x010 )
		{
	    j=0;
		for (i=0;i<0xFF;i++)
				{
				outportb(0x500|w, i); 
				if ( inportb(0x500|w)!=i)  j=j| 0x01; 
				}

//		ScreenAddByte(j);
//		ScreenAddChar(' ');
		printf("%02X ",j);
		if ((m++ & 0x03) ==0x03)
		{
	   //	 ScreenAddChar('_');ScreenAddChar('_');}		
	     printf("__");
		 }
		}
//	ScreenSent();
    printf("\n\r");

	for (n=0;n<255;n++)
		{
		for( w=0x00; w<0x100; w=w+0x010 )
				{
				for (i=0;i<0xFF;i++)
						{
						outportb(0x500|w, i); 
						if ( inportb(0x500|w)!=i)  j=j| 0x01; 
						}
			  }
		}
   //delay_mcs(600000l);
   wd_reset();

	
	}
printf("\n\r End the test BUS");
printf("\n\r For property work device will be restarted...");
}
//_______________________________________________________________BUS Test
//________________________________________________________________test w2o0in0
 
extern "C" void test_w2o0in0()
{
   unsigned char j, n, m, i;     
   unsigned int z, w;

//ScreenSetBuffer();
//ScreenAddString("2 wire -0 out -0 input  W2O0in0");
//ScreenSent();

  printf("\n\r Start MF20 Test w2o0in0\n\r");


                        
     //    embRS232.Init(384);             // Инициализация RS232 на скорость 38400 кбит/с
     //      Enable();                       // Разрешаем все прерывания

     // TIMMING MODE

outportb(0x507, 0x01);   // master internal

 //0x91;  // master ext interface 0  1001 0001
 outportb(0x508,0x04);  // off  zero   offauto

 //wr_cosv(SLOTE, 9, 0x00); // status

 // ini LIU 
//wr_cosv(SLOTE, 0x0220, 0x01); // 
wr_cosv(SLOTE, 0x0240, 0x0c); // 
wr_cosv(SLOTE, 0x0201, 0x18); // 
wr_cosv(SLOTE, 0x0203, 0x01); //    
wr_cosv(SLOTE, 0x021a, 0x09); // 
wr_cosv(SLOTE, 0x0240, 0x04); // 

// ini ETHERNET
wr_cosv(SLOTE, 0x0352, 0x00); // 
wr_cosv(SLOTE, 0x0351, 0x13); // 

// load E1 mode

wr_cosv(SLOTE, 0x0308, 0x00); // 
wr_cosv(SLOTE, 0x0309, 0x00); // 
wr_cosv(SLOTE, 0x030a, 0x00); // 
wr_cosv(SLOTE, 0x030b, 0x00); //  


// load cshedule
// ch1
i=0;
for( w=0; w<0x080; )
		{
			wr_cosv(SLOTE, w, sch1_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch1_e1[i]);
	w++;
	i++;
	
		}
// ch2
i=0;
w=0x080;
for( w=0x080; w<0x100; )
		{
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
	 
		}
// ch3
i=0;
for( w=0x100; w<0x180;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
//ch4
i=0;
for( w=0x180; w<0x200;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}

// SL4 presence test 
m=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
    j=0;
	for (n=0;n<0xFF;n++)
			{
			outportb(0x500|w, i); 
			if ( inportb(0x500|w)!=i)  j=j| 0x01; 
			i++;
			outportb(0x508|w, i); 
			if (inportb(0x508|w)!=i)  j=j| 0x02; 
			i++;
			outportb(0x509|w, i); 
			if (inportb(0x509|w)!=i)  j=j| 0x04; 
			i++;
			outportb(0x50a|w, i); 
			if (inportb(0x50a|w)!=i)   j=j| 0x08; 
			i++;
			if (inportb( 0x502|w)!=0x11) j=j| 0x10 ; // identifictor triscend
			if (inportb( 0x505|w)!=0x02) j=j| 0x20 ;// identifictor xilinx
			
			}
	 printf("%02X ", j);
  //	ScreenAddByte(j);
  //	ScreenAddChar(' ');
	if ((m++ & 0x03) ==0x03){ 
   //	ScreenAddChar('_');ScreenAddChar('_');
	printf("__");
	}		
	}

//ScreenSent();
printf("\n\r");


// ini SL4

i=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{


outportb(0x507|w, 0x80);  
	for( z=0; z<0x01fff; z++);
outportb(0x507| w, 0x80);  
	for( z=0; z<0x01fff; z++);

			for (j=0; j<4; j++)
			{
					outportb(0x507| w, 0x98 | j );  //2 - wire
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 0x00); // 0x10-4 wire
			   for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x84 | j );  // level out 0
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 37);  //45-- +4
					for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x88 | j );  // level input  0
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 12);  //
					for( z=0; z<0x01fff; z++);
			
			 } 

		// ini  ock 
	outportb(0x508|w, 0x00);   // ock
	//		outportb(0x509|w, 0x00);   // 0 выкл шлейф
			//outportb(0x509|w, 0x0f);   // 0F ближн шлейф
		//	outportb(0x50a|w, 0x0F);    //  0Fкороткая петля  FF -длинная петля
	}   

n=30;
while(n > 0) // 0.5 min
 {
  n--;
  delay_mcs(600000l);
   printf(">%2d\r", n);
  wd_reset();
 }
//ScreenAddString("end W2O0in0");
//ScreenSent();
printf("\n\r End Test w2o0in0");
printf("\n\r For property work device will be restarted...");


   //	asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor
}
//________________________________________________________________test w2o0in0
//________________________________________________________________test w4o13in13
 
extern "C" void test_w4o13in13()
{
 unsigned char j, n, m, i;     
 unsigned int z, w;
	  printf("\n\r Start MF20 Test w4o13in13\n\r");

//ScreenSetBuffer();
//ScreenAddString("4 wire -13 out -13 input  W4O13in13");
//ScreenSent();

                        
     //    embRS232.Init(384);             // Инициализация RS232 на скорость 38400 кбит/с
     //      Enable();                       // Разрешаем все прерывания

     // TIMMING MODE

outportb(0x507, 0x01);   // master internal

 //0x91;  // master ext interface 0  1001 0001
 outportb(0x508,0x04);  // off  zero   offauto

 //wr_cosv(SLOTE, 9, 0x00); // status

 // ini LIU 
//wr_cosv(SLOTE, 0x0220, 0x01); // 
wr_cosv(SLOTE, 0x0240, 0x0c); // 
wr_cosv(SLOTE, 0x0201, 0x18); // 
wr_cosv(SLOTE, 0x0203, 0x01); //    
wr_cosv(SLOTE, 0x021a, 0x09); // 
wr_cosv(SLOTE, 0x0240, 0x04); // 

// ini ETHERNET
wr_cosv(SLOTE, 0x0352, 0x00); // 
wr_cosv(SLOTE, 0x0351, 0x13); // 

// load E1 mode

wr_cosv(SLOTE, 0x0308, 0x00); // 
wr_cosv(SLOTE, 0x0309, 0x00); // 
wr_cosv(SLOTE, 0x030a, 0x00); // 
wr_cosv(SLOTE, 0x030b, 0x00); //  


// load cshedule
// ch1
i=0;
for( w=0; w<0x080; )
		{
			wr_cosv(SLOTE, w, sch1_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch1_e1[i]);
	w++;
	i++;
	
		}
// ch2
i=0;
w=0x080;
for( w=0x080; w<0x100; )
		{
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
	 
		}
// ch3
i=0;
for( w=0x100; w<0x180;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
//ch4
i=0;
for( w=0x180; w<0x200;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}

// SL4 presence test 
m=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
    j=0;
	for (n=0;n<0xFF;n++)
			{
			outportb(0x500|w, i); 
			if ( inportb(0x500|w)!=i)  j=j| 0x01; 
			i++;
			outportb(0x508|w, i); 
			if (inportb(0x508|w)!=i)  j=j| 0x02; 
			i++;
			outportb(0x509|w, i); 
			if (inportb(0x509|w)!=i)  j=j| 0x04; 
			i++;
			outportb(0x50a|w, i); 
			if (inportb(0x50a|w)!=i)   j=j| 0x08; 
			i++;
			if (inportb( 0x502|w)!=0x11) j=j| 0x10 ; // identifictor triscend
			if (inportb( 0x505|w)!=0x02) j=j| 0x20 ;// identifictor xilinx
			
			}
  printf("%02X ", j);
  //	ScreenAddByte(j);
  //	ScreenAddChar(' ');
	if ((m++ & 0x03) ==0x03){ 
   //	ScreenAddChar('_');ScreenAddChar('_');
	printf("__");
	}		
			
	}

//ScreenSent();
printf("\n\r");


// ini SL4

i=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{


outportb(0x507|w, 0x80);  
	for( z=0; z<0x01fff; z++);
outportb(0x507| w, 0x80);  
	for( z=0; z<0x01fff; z++);

			for (j=0; j<4; j++)
			{
					outportb(0x507| w, 0x98 | j );  // 4 - wire
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 0x10);  
			   for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x84 | j );  // level out -13
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 11);  //45-- +4
					for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x88 | j );  // level input  -13
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 39);  //
					for( z=0; z<0x01fff; z++);
			
			 } 

		// ini  ock 
	outportb(0x508|w, 0x00);   // ock
	//		outportb(0x509|w, 0x00);   // 0 выкл шлейф
			//outportb(0x509|w, 0x0f);   // 0F ближн шлейф
		//	outportb(0x50a|w, 0x0F);    //  0Fкороткая петля  FF -длинная петля
	}   
n=30;
while(n > 0) // 0.5 min
 {
  n--;
  delay_mcs(600000l);
   printf(">%2d\r", n);
  wd_reset();
 }
//ScreenAddString("end W4o13in13");
//ScreenSent();
printf("\n\r End Test w4o13in13");
printf("\n\r For property work device will be restarted...");
}
//________________________________________________________________test w4o13in13
//________________________________________________________________test w4o4in13
 
 extern "C" void test_w4o4in13()
{
  unsigned char j, n, m, i;     
  unsigned int z, w;
  printf("\n\r Start MF20 Test w4o13in13\n\r");

//ScreenSetBuffer();
//ScreenAddString("4 wire +4 out -13 input  W4O4in13");
//ScreenSent();

                        
     //    embRS232.Init(384);             // Инициализация RS232 на скорость 38400 кбит/с
     //      Enable();                       // Разрешаем все прерывания

     // TIMMING MODE

outportb(0x507, 0x01);   // master internal

 //0x91;  // master ext interface 0  1001 0001
 outportb(0x508,0x04);  // off  zero   offauto

 //wr_cosv(SLOTE, 9, 0x00); // status

 // ini LIU 
//wr_cosv(SLOTE, 0x0220, 0x01); // 
wr_cosv(SLOTE, 0x0240, 0x0c); // 
wr_cosv(SLOTE, 0x0201, 0x18); // 
wr_cosv(SLOTE, 0x0203, 0x01); //    
wr_cosv(SLOTE, 0x021a, 0x09); // 
wr_cosv(SLOTE, 0x0240, 0x04); // 

// ini ETHERNET
wr_cosv(SLOTE, 0x0352, 0x00); // 
wr_cosv(SLOTE, 0x0351, 0x13); // 

// load E1 mode

wr_cosv(SLOTE, 0x0308, 0x00); // 
wr_cosv(SLOTE, 0x0309, 0x00); // 
wr_cosv(SLOTE, 0x030a, 0x00); // 
wr_cosv(SLOTE, 0x030b, 0x00); //  


// load cshedule
// ch1
i=0;
for( w=0; w<0x080; )
		{
			wr_cosv(SLOTE, w, sch1_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch1_e1[i]);
	w++;
	i++;
	
		}
// ch2
i=0;
w=0x080;
for( w=0x080; w<0x100; )
		{
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch2_e1[i]);
	 w++;
	i++;
	 
		}
// ch3
i=0;
for( w=0x100; w<0x180;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}
//ch4
i=0;
for( w=0x180; w<0x200;)
		{
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
			wr_cosv(SLOTE, w, sch3_e1[i]);
	 w++;
	i++;
	
		}

// SL4 presence test 
m=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{
    j=0;
	for (n=0;n<0xFF;n++)
			{
			outportb(0x500|w, i); 
			if ( inportb(0x500|w)!=i)  j=j| 0x01; 
			i++;
			outportb(0x508|w, i); 
			if (inportb(0x508|w)!=i)  j=j| 0x02; 
			i++;
			outportb(0x509|w, i); 
			if (inportb(0x509|w)!=i)  j=j| 0x04; 
			i++;
			outportb(0x50a|w, i); 
			if (inportb(0x50a|w)!=i)   j=j| 0x08; 
			i++;
			if (inportb( 0x502|w)!=0x11) j=j| 0x10 ; // identifictor triscend
			if (inportb( 0x505|w)!=0x02) j=j| 0x20 ;// identifictor xilinx
			
			}
	 printf("%02X ", j);
  //	ScreenAddByte(j);
  //	ScreenAddChar(' ');
	if ((m++ & 0x03) ==0x03){ 
   //	ScreenAddChar('_');ScreenAddChar('_');
	printf("__");
	}					
	}

//ScreenSent();
  printf("\n\r");

// ini SL4

i=0;
for( w=0x010; w<0x100; w=w+0x010 )
	{


outportb(0x507|w, 0x80);  
	for( z=0; z<0x01fff; z++);
outportb(0x507| w, 0x80);  
	for( z=0; z<0x01fff; z++);

			for (j=0; j<4; j++)
			{
					outportb(0x507| w, 0x98 | j );  // 4 - wire
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 0x10);  
			   for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x84 | j );  // level out +4
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 45);  //
					for( z=0; z<0x01fff; z++);
			
					outportb(0x507| w, 0x88 | j );  // level input  -13
					for( z=0; z<0x01fff; z++);
					outportb(0x507| w, 39);  //
					for( z=0; z<0x01fff; z++);
			
			 } 

		// ini  ock 
	outportb(0x508|w, 0x00);   // ock
	//		outportb(0x509|w, 0x00);   // 0 выкл шлейф
			//outportb(0x509|w, 0x0f);   // 0F ближн шлейф
		//	outportb(0x50a|w, 0x0F);    //  0Fкороткая петля  FF -длинная петля
	}   

n=30;
while(n > 0) // 0.5 min
 {
  n--;
  delay_mcs(600000l);
   printf(">%2d\r", n);
  wd_reset();
 }
//ScreenAddString("end W4o13in13");
//ScreenSent();
printf("\n\r End Test w4o4in13");
printf("\n\r For property work device will be restarted...");
}
//________________________________________________________________test w4o4in13

#endif //TESTS_ENABLED

//added 130516 for compiling!!!!!!!!!!!!!!!!!
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
 //	  Stephany19++; 
     embSerialACT155.IsrXX();
 IntFlag |= INT0_FLAG;
#endif // IncEmbSerialACT155

// if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
// {
//   InterruptWatchDog++;
   my_int_enable_irq0();
// }

}
