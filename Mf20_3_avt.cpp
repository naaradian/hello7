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
  
   //	EmbMsg embMsg;	  //new
	EmbMsg embMsg;	  //new
	EmbMsg embMsgAns; //new
  //  
//_____________________________________________>>from bmd_34 
    EmbMsg embMsg485;
	EmbMsg embMsg485E;

	EmbMsg embMsg232E;		  //new

	unsigned aI, aS, aR;
	int i232;
  //	int i485;		//my
    unsigned char flagRequest; //=0;
	EmbMsg *embMsgRequest;
	EmbMsgBuffer rBuffEmbMsg;
	unsigned addr1;	
	unsigned char * bt;	
//_____________________________________________<<from bmd_34

	EmbRS485 embRS485;
	EmbIndicator embIndicator;
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

//void main()
extern "C" void mf20_init()
{


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
	unEmb2TypeVer.emb2TypeVer.softVer    = 0x0233;
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
static unsigned char byte; 
static unsigned short i=0;//, j=0;
static unsigned char mode5A=0; 
  //	unsigned char  *addrRAM;
static unsigned short shift;
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
  #include "remotemf20.inc"




//_________________________>> from bmd_34
//}

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
 