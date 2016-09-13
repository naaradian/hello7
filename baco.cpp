//#ifndef __TINY__
//#define __TINY__
//#endif
#include "start.h"
#include "hello7.h"
#include "ubx.h"


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




 struct CBACOCfg
{
	unsigned long numOfBlocks; 		//4
	unsigned short sizeOfBlocks;    //2
	unsigned short frequMain; 		//2
	unsigned short frequSampling; 	//2
	unsigned char passBand; 		//1
	unsigned char amplification; 	//1
	unsigned char typeOfBlock; 		//1
	unsigned char reserv[3]; 		//3
	unsigned char mac_self[6];		// 6 byte = 22
	unsigned char mac_dest[6];		// 6 byte = 28
	unsigned char ip_self[4];		// 4 byte = 32
	unsigned char ip_dest[4];		// 4 byte = 36
	unsigned short port_self;		// 2 byte = 38
	unsigned short port_dest;		// 2 byte = 40

};

#define BACO_SIZE (320)

union uCBACOCfg
{
	CBACOCfg cbacocfg[8];
   //	unsigned char byte[128];
	unsigned char byte[BACO_SIZE];
};


uCBACOCfg cbaco;
unsigned short start_cbaco;


extern "C" void	KeepCBaco()
{
 for(unsigned i=0; i<BACO_SIZE; i++)
 {
    write_nvram_char((BACO_OFFSET + i), cbaco.byte[i]);

  //	printfpd("\n\r k %d",  i);
  //	printfpd("  %x",  cbaco.byte[i]);

 }
}

extern "C" void	RestoreCBaco()
{

 for(unsigned i=0; i<BACO_SIZE; i++)
 {
    cbaco.byte[i] = (unsigned char)read_nvram_char(BACO_OFFSET + i);
  //	cbaco.byte[i] = i; //t
  //	printfpd("\n\r %d",  i);
 // if(!(i% 16)) printfp("\n\r");
 //	printfpd("  %x",  cbaco.byte[i]);

 }

}


//LoadBlocks()
//{
//}





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
//#define  NUM_OF_SLOT  16


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
 /*
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
*/
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

 /*

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
*/
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

  /*
struct CBACOCfg
{
	unsigned long numOfBlocks; 		//4
	unsigned short sizeOfBlocks;    //2
	unsigned short frequMain; 		//2
	unsigned short frequSampling; 	//2
	unsigned char passBand; 		//1
	unsigned char amplification; 	//1
	unsigned char typeOfBlock; 		//1
	unsigned char reserv[3]; 		//3
};

union uCBACOCfg
{
	CBACOCfg cbacocfg[8];
	unsigned char byte[128];
};


uCBACOCfg cbaco;
*/

void LoadBacoStartZero(void)
{

#ifdef Debug_Baco1
 printfp("\n\r LoadBacoStartZero ");
#endif


//printfp("\n\r LoadBacoStartZero");
 //unsigned char numbit =   1; //slots 0

 //unsigned char numslot = 0;


 int l_base;

 l_base = 0x500; // + numslot * 16;

	outportb(l_base + BACO_START_ADDR , 1);

}




void LoadBacoStart(unsigned char numslot)
{
#ifdef Debug_Baco1
 printfpd("\n\r LoadBacoStart %d ",numslot);
#endif


 //printfpd("\n\rLoadBacoStart %d", numslot );

 unsigned char numbit = 	(numslot - 1) >> 1; //slots 1,3,5,7... struct 0,1,2,3

 int l_base;
 l_base = 0x500 + numslot * 16;

	outportb(l_base + BACO_START_ADDR , start_cbaco & (1 << numbit));




}

struct BacoTime
{
	unsigned short Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Min;
	unsigned char Sec;
	unsigned char Msec100;
};

struct BacoSendCommand
{
BacoTime bacotime;
unsigned short period;
unsigned char  trysend;
unsigned char rezerv;
unsigned char n0;
unsigned char n1;
unsigned char n2;
unsigned char n3;
};

//#define SIZE_BSC   (8+2+1+1)//*(NUM_OF_SLOT>>1)
#define SIZE_BSC   (8+2+1+1+4)//*(NUM_OF_SLOT>>1)
 
union uBacoSendCommand
{
   BacoSendCommand bscd;
   unsigned char byte[SIZE_BSC];
};

uBacoSendCommand bsc[NUM_OF_SLOT>>1];

 
//#define SIZE_BSCP   (8+2+1+1)*(NUM_OF_SLOT>>1)
#define SIZE_BSCP   (8+2+1+1+4)*(NUM_OF_SLOT>>1)

typedef union uBacoSendCommandp
{
   BacoSendCommand bscd[NUM_OF_SLOT>>1];
   unsigned char byte[SIZE_BSCP];
}  *BSC;


#define PBSC (BSC)(BACO_OFFSET_BSC);


BSC pbsc = PBSC;   //this init need make in funktions!!!!

void CfgCardBacoStart()
{
//printfp("\n\r CfgCardBacoStart");
#ifdef Debug_Baco1
 printfp("\n\rCfgCardBacoStart ");
#endif

 int l_base;

unsigned ns;
unsigned char Year = ClockReadYear();
unsigned char Month = ClockReadMonth();
unsigned char Date = ClockReadDate();
unsigned char Hours = ClockReadHours();
unsigned char Min = ClockReadMin();
unsigned char Sec = ClockReadSec();




  	for(unsigned i=1; i < NUM_OF_SLOT; i+=2)	//only nechet
	{
	ns =(i-1)>>1;

  	l_base = 0x500 + i * 16;
	outportb(l_base, YEAR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Year);
	outportb(l_base, MONTH_ADDR);
	outportb(l_base + DATA_REG_ADDR , Month);
	outportb(l_base, DAY_ADDR);
	outportb(l_base + DATA_REG_ADDR , Date);
	outportb(l_base, HOUR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Hours);
	outportb(l_base, MIN_ADDR);
	outportb(l_base + DATA_REG_ADDR , Min);
	outportb(l_base, SEC_ADDR);
	outportb(l_base + DATA_REG_ADDR , Sec);

	outportb(l_base, N0_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n0);
	outportb(l_base, N1_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n1);
	outportb(l_base, N2_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n2);
	outportb(l_base, N3_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n3);

   outportb(l_base, MS100_ADDR);
   outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].bacotime.Msec100);




	 LoadBacoStart(i);
	}

   LoadBacoStartZero();  //synchro start to all in zero slot



}


void CfgCardBacoStartTimer(unsigned char i)
{
#ifdef Debug_Baco1
 printfpd("\n\rCfgCardBacoStartTimer %d ", i);
#endif

unsigned ns =(i-1)>>1;


//printfp("\n\r CfgCardBacoStart");
 int l_base;

unsigned char Year = ClockReadYear();
unsigned char Month = ClockReadMonth();
unsigned char Date = ClockReadDate();
unsigned char Hours = ClockReadHours();
unsigned char Min = ClockReadMin();
unsigned char Sec = ClockReadSec();

  	l_base = 0x500 + i * 16;
	outportb(l_base, YEAR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Year);
	outportb(l_base, MONTH_ADDR);
	outportb(l_base + DATA_REG_ADDR , Month);
	outportb(l_base, DAY_ADDR);
	outportb(l_base + DATA_REG_ADDR , Date);
	outportb(l_base, HOUR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Hours);
	outportb(l_base, MIN_ADDR);
	outportb(l_base + DATA_REG_ADDR , Min);
	outportb(l_base, SEC_ADDR);
	outportb(l_base + DATA_REG_ADDR , Sec);

	outportb(l_base, N0_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n0);
	outportb(l_base, N1_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n1);
	outportb(l_base, N2_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n2);
	outportb(l_base, N3_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n3);

   outportb(l_base, MS100_ADDR);
   outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].bacotime.Msec100);



	outportb(l_base + BACO_START_ADDR , 1);

	LoadBacoStart(i);
 //it maake later for all slots	LoadBacoStartZero();  
 
}  
  

#define SWAPB(Word)                 ((unsigned int)((Word) << 8) | ((Word) >> 8))



unsigned short CalcChecksum(unsigned len, unsigned short *pBuf)
{

unsigned long ret = 0;
 printfp("\n\r");
while(len--)
{
 printfpd("\n\r %d ",len);
 printfpd(" %X ",*pBuf);
 ret += *pBuf++;
// printfpd("\n\r %X ",*pBuf);
 printfpd(" %X ", ret);
 printfpd(" %X ", ~(ret));


}

 ret = (ret & 0xffff) + (ret >> 16);
 ret +=  (ret >> 16);


printfpd(" %X ", ~(ret));


return ~(ret);
}







#define HEADER_LEN (10) //16 bit words

extern "C" void TestChecksum()
{
 unsigned short Buffer[HEADER_LEN];
 unsigned short* pBuf =  Buffer;
 unsigned short checksum; 


		/*
 //t* pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = SWAPB(0x4500);	 //ver and header length in words
 * pBuf++  = SWAPB(0x28);	 //full length
 * pBuf++  = SWAPB(0x2503); //identif
 * pBuf++  = SWAPB(0x4000); //dont fragment
 * pBuf++  = SWAPB(0x8006); //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = SWAPB(0x9b9b);// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = SWAPB(0x9b47);// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = SWAPB(0xc35f);//ffff;
 * pBuf++  = SWAPB(0xda33);//0xffff;
	 */
		 /*
 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = 0x28;	 //full length
 * pBuf++  = 0x2503; //identif
 * pBuf++  = 0x4000;//0x4000; //dont fragment
 * pBuf++  = 0x8006; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = 0x9b9b;// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = 0x9b97;// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = 0xc35f;//ffff;
 * pBuf++  = 0xda33;//0xffff;
	   */

 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = 0x4e;	 //full length
 * pBuf++  = 0x04e5; //identif
 * pBuf++  = 0x0000;//0x4000; //dont fragment
 * pBuf++  = 0x8011; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = 0xc0a8;// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = 0x0064;// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = 0xffff;//ffff;
 * pBuf++  = 0xffff;//0xffff;
   checksum =  CalcChecksum((unsigned)HEADER_LEN, Buffer);
  // Buffer[5]	 = 	   checksum;

  printfpd("\n\rchecksum :  %X", checksum);

  Buffer[5]	 = 	   checksum;
 
    checksum =  CalcChecksum((unsigned)HEADER_LEN, Buffer);

  printfpd("\n\r test %X", checksum);




}





void LoadBaco(unsigned char numslot)
{
// unsigned short Buffer[HEADER_LEN];
// unsigned short* pBuf =  Buffer;

 unsigned char numstruct = 	(numslot - 1) >> 1; //slots 1,3,5,7... struct 0,1,2,3
 int l_base;
 l_base = 0x500 + numslot * 16;

 uint_64 sample_max;

 unsigned long sid = SelfID(); 

 unsigned packlen = cbaco.cbacocfg[numstruct].sizeOfBlocks;// 4; //256; // (1024 / 4) 1024 + 30;  //32

 unsigned udplen = (packlen * 4) + 42;

 unsigned iplen = udplen + 20; // (1024 / 4) 1024 + 30;  //32


 unsigned ipident  = 0x04e5;

 unsigned ipcrc;   //will celling

 unsigned tmp;

//unsigned char tmp0, tmp1, tmp2, tmp3;

 
 //1054 full length


 sample_max = (uint_64)cbaco.cbacocfg[numstruct].numOfBlocks ;//*   (uint_64)cbaco.cbacocfg[numstruct].sizeOfBlocks;	//32
 
  /*
 if(sample_max %  packlen)
 {
  tmp =  sample_max / packlen;
  sample_max = (tmp + 1) * packlen;
 }
  */
//printEthLongHex(cbaco.cbacocfg[numstruct].numOfBlocks);
//printEthLongHex(sample_max);
 // printfpd("\n\rsample_max : %d ",sample_max );
  /*

 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = iplen;	 //full length
 * pBuf++  = ipident; //identif
 * pBuf++  = 0x4000; //dont fragment
 * pBuf++  = 0x0206; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc
 * pBuf++  =  cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  =  cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  =  0xffff;
 * pBuf++  =  0xffff;

  ipcrc = CalcChecksum((unsigned)HEADER_LEN; Buffer);

  */




 unsigned ip11 = 0x4500;	 //ver and header length in words
 unsigned ip12 = iplen;	 //full length
 unsigned ip21 = 0x04e5; //ipident; //identif
 unsigned ip22 = 0x0000; //dont fragment
 unsigned ip31 = 0x8011; //time = 2 ip p prot tcp = 6
 unsigned ip32 = 0; //hier crc
 unsigned ip41 = ((unsigned)cbaco.cbacocfg[numstruct].ip_self[3] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_self[2];  // 0xc0a8;//
 unsigned ip42 = ((unsigned)cbaco.cbacocfg[numstruct].ip_self[1] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_self[0];	//	  0x32;//0x64
 unsigned ip51 =  ((unsigned)cbaco.cbacocfg[numstruct].ip_dest[3] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_dest[2];  // 0xc0a8;////0xffff;
 unsigned ip52 = ((unsigned)cbaco.cbacocfg[numstruct].ip_dest[1] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_dest[0];	//	  0x32;//0x64//0xffff;




 ipcrc = ip11 + ip12 + ip21 + ip22 + ip31 + ip32 + ip41 + ip42 + ip51 + ip52;



 //udplen = 0; //temporary

  ipcrc = (ipcrc & 0xffff) + (ipcrc >> 16);

  ipcrc = ~(ipcrc);



#ifdef PRINT_BACO

    printfpd("\n\r %d : \n\r",numstruct);	  

//    printfpd(" ip_self[3] : %x ",cbaco.cbacocfg[numstruct].ip_self[3] );	  
//  	printfpd("ip_self[2] : %x ",cbaco.cbacocfg[numstruct].ip_self[2] );
//  	printfpd("ip_self[1] : %x ",cbaco.cbacocfg[numstruct].ip_self[1] );
//  	printfpd("ip_self[0] : %x ",cbaco.cbacocfg[numstruct].ip_self[0] );
//    printfpd("\n\r ip_dest[3] : %x ",cbaco.cbacocfg[numstruct].ip_dest[3] );	  
//  	printfpd("ip_dest[2] : %x ",cbaco.cbacocfg[numstruct].ip_dest[2] );
//  	printfpd("ip_dest[1] : %x ",cbaco.cbacocfg[numstruct].ip_dest[1] );
//  	printfpd("ip_dest[0] : %x ",cbaco.cbacocfg[numstruct].ip_dest[0] );
//   	printfpd("\n\ripcrc : %x ",ipcrc);

#endif


	outportb(l_base + RESET_ADDR , (unsigned char)1);

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",RESET_ADDR);
	printfpd("value : 0x%x ",1);
#endif

	outportb(l_base, SAMPLEMAX_ADDR);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)sample_max);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR);
	printfpd("value : 0x%x ",(unsigned char)sample_max);
#endif


	outportb(l_base, SAMPLEMAX_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 8));
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR + 1);
	printfpd("value : 0x%x ",(unsigned char)(sample_max >> 8));
#endif

	outportb(l_base, SAMPLEMAX_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 16));
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR + 2);
	printfpd("value : 0x%x ",(unsigned char)(sample_max >> 16));
#endif

	outportb(l_base, SAMPLEMAX_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 24));
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR + 3);
	printfpd("value : 0x%x ",(unsigned char)(sample_max >> 24));
#endif

	outportb(l_base, SAMPLEMAX_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 32));
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR + 4);
	printfpd("value : 0x%x ",(unsigned char)(sample_max >> 32));
#endif

	outportb(l_base, SAMPLEMAX_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 40));
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SAMPLEMAX_ADDR + 5);
	printfpd("value : 0x%x ", (unsigned char)(sample_max >> 40));
#endif

 	outportb(l_base, SIZEBLOCKS_ADDR);
	outportb(l_base + DATA_REG_ADDR , packlen);//cbaco.cbacocfg[numstruct].sizeOfBlocks);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SIZEBLOCKS_ADDR);
	printfpd("value : 0x%x ", packlen & 0xff);
#endif

	outportb(l_base, SIZEBLOCKS_ADDR+ 1);
	outportb(l_base + DATA_REG_ADDR , packlen >> 8); //cbaco.cbacocfg[numstruct].sizeOfBlocks >>8);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SIZEBLOCKS_ADDR+ 1);
	printfpd("value : 0x%x ",packlen >> 8);
#endif


	outportb(l_base, IPLEN_ADDR);
	outportb(l_base + DATA_REG_ADDR , iplen);	 //5 bytes
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IPLEN_ADDR);
	printfpd("value : 0x%x ",iplen & 0xff);
#endif

	outportb(l_base, IPLEN_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , iplen >> 8);	 //
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", IPLEN_ADDR + 1);
	printfpd("value : 0x%x ",iplen >> 8);
#endif


	outportb(l_base, IPIDENT_ADDR);
	outportb(l_base + DATA_REG_ADDR , ipident);	 //4
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IPIDENT_ADDR);
	printfpd("value : 0x%x ",ipident & 0xff);
#endif

	outportb(l_base, IPIDENT_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , ipident >> 8);	 //4
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", IPIDENT_ADDR + 1);
	printfpd("value : 0x%x ", ipident >> 8);
#endif

	outportb(l_base, IPCRC_ADDR);
	outportb(l_base + DATA_REG_ADDR , ipcrc);	 //4
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IPCRC_ADDR);
	printfpd("value : 0x%x ", ipcrc & 0xff);
#endif

	outportb(l_base, IPCRC_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , ipcrc >> 8);	 //4

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", IPCRC_ADDR + 1);
	printfpd("value : 0x%x ", (ipcrc >> 8) & 0xff );
#endif

	outportb(l_base, UDPLEN_ADDR);
	outportb(l_base + DATA_REG_ADDR , udplen);	 //4

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDPLEN_ADDR);
	printfpd("value : 0x%x ",udplen & 0xff);
#endif

	outportb(l_base, UDPLEN_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , udplen >> 8);	 //4
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDPLEN_ADDR + 1);
	printfpd("value : 0x%x ",udplen >> 8);
#endif


	outportb(l_base, MAC_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR , 0x90); // cbaco.cbacocfg[numstruct].mac_self[0]);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", MAC_SOURCE_ADDR);
	printfpd("value : 0x%x ",0x90);
#endif


	outportb(l_base, MAC_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , 0xe2); //cbaco.cbacocfg[numstruct].mac_self[1]);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_SOURCE_ADDR + 1);
	printfpd("value : 0x%x ",0xe2);
#endif


	outportb(l_base, MAC_SOURCE_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , 0xba); //cbaco.cbacocfg[numstruct].mac_self[2]);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_SOURCE_ADDR + 2);
	printfpd("value : 0x%x ", 0xba);
#endif



	outportb(l_base, MAC_SOURCE_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , sid >> 8); //cbaco.cbacocfg[numstruct].mac_self[3]);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_SOURCE_ADDR + 3);
	printfpd("value : 0x%x ",sid >> 8);
#endif

	outportb(l_base, MAC_SOURCE_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR , sid); //cbaco.cbacocfg[numstruct].mac_self[4]);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_SOURCE_ADDR + 4);
	printfpd("value : 0x%x ",sid & 0xff);
#endif


	outportb(l_base, MAC_SOURCE_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR , numslot); //cbaco.cbacocfg[numstruct].mac_self[5]);

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_SOURCE_ADDR + 5);
	printfpd("value : 0x%x ", numslot);
#endif

	outportb(l_base, MAC_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR ,0xff); //cbaco.cbacocfg[numstruct].mac_dest[0]); //	 0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR);
	printfpd("value : 0x%x ",0xff);
#endif


	outportb(l_base, MAC_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,0xff); //cbaco.cbacocfg[numstruct].mac_dest[1]); //	 0xff); // 

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR + 1);
	printfpd("value : 0x%x ",0xff);
#endif

	outportb(l_base, MAC_DEST_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR ,0xff); //cbaco.cbacocfg[numstruct].mac_dest[2]); //	 0xff); // 
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR + 2);
	printfpd("value : 0x%x ",0xff);
#endif


	outportb(l_base, MAC_DEST_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , 0xff); //cbaco.cbacocfg[numstruct].mac_dest[3]); //  0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR + 3);
	printfpd("value : 0x%x ",0xff);
#endif


	outportb(l_base, MAC_DEST_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR , 0xff); //cbaco.cbacocfg[numstruct].mac_dest[4]); //  0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR + 4);
	printfpd("value : 0x%x ",0xff);
#endif



	outportb(l_base, MAC_DEST_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR ,0xff); //cbaco.cbacocfg[numstruct].mac_dest[5]); //	  0xff); // 

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MAC_DEST_ADDR + 5);
	printfpd("value : 0x%x ",0xff);
#endif
 


	outportb(l_base, IP_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_self[0]);   //  50);// //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_SOURCE_ADDR);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_self[0]);
#endif


	outportb(l_base, IP_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,  cbaco.cbacocfg[numstruct].ip_self[1]); //	 0);//

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", IP_SOURCE_ADDR + 1);
	printfpd("value : 0x%x ", cbaco.cbacocfg[numstruct].ip_self[1]);
#endif

	outportb(l_base, IP_SOURCE_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_self[2]);	  //168);//

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_SOURCE_ADDR + 2);
	printfpd("value : 0x%x ", cbaco.cbacocfg[numstruct].ip_self[2]);
#endif


	outportb(l_base, IP_SOURCE_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_self[3]);	 //	192);//

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_SOURCE_ADDR + 3);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_self[3]);
#endif


	outportb(l_base, IP_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_dest[0]); //	   0xff); // 

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_DEST_ADDR);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_dest[0]);
#endif


	outportb(l_base, IP_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,cbaco.cbacocfg[numstruct].ip_dest[1]); //  0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_DEST_ADDR + 1);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_dest[1]);
#endif

	outportb(l_base, IP_DEST_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_dest[2]); //	0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_DEST_ADDR + 2);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_dest[2]);
#endif

	outportb(l_base, IP_DEST_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].ip_dest[3]); //	0xff); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",IP_DEST_ADDR + 3);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].ip_dest[3]);
#endif

	outportb(l_base, UDP_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].port_self >> 8);	// 0xc3);//

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDP_SOURCE_ADDR);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].port_self >> 8);
#endif


	outportb(l_base, UDP_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,cbaco.cbacocfg[numstruct].port_self);	 //	  0x50); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDP_SOURCE_ADDR + 1);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].port_self & 0xff);
#endif

	outportb(l_base, UDP_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR, cbaco.cbacocfg[numstruct].port_dest >>8);	 //	  0xc3); //

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDP_DEST_ADDR);
	printfpd("value : 0x%x ", cbaco.cbacocfg[numstruct].port_dest >>8);
#endif


	outportb(l_base, UDP_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,cbaco.cbacocfg[numstruct].port_dest); //   0x50); //
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",UDP_DEST_ADDR + 1);
	printfpd("value : 0x%x ",cbaco.cbacocfg[numstruct].port_dest & 0xff);
#endif

	outportb(l_base, YEAR_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadYear());
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",YEAR_ADDR);
	printfpd("value : 0x%x ",ClockReadYear());
#endif



	outportb(l_base, MONTH_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadMonth());

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", MONTH_ADDR);
	printfpd("value : 0x%x ",ClockReadMonth());
#endif

	outportb(l_base, DAY_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadDate());

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",DAY_ADDR);
	printfpd("value : 0x%x ",ClockReadDate());
#endif

	outportb(l_base, HOUR_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadHours());

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",HOUR_ADDR);
	printfpd("value : 0x%x ",ClockReadHours());
#endif

	outportb(l_base, MIN_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadMin());
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",MIN_ADDR);
	printfpd("value : 0x%x ",ClockReadMin());
#endif


	outportb(l_base, SEC_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadSec());
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",SEC_ADDR);
	printfpd("value : 0x%x ",ClockReadSec());
#endif

	outportb(l_base, N0_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n0);

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",N0_ADDR);
	printfpd("value : 0x%x ",pbsc->bscd[numstruct].n0);
#endif

	outportb(l_base, N1_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n1);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",N1_ADDR);
	printfpd("value : 0x%x ", pbsc->bscd[numstruct].n1);
#endif


	outportb(l_base, N2_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n2);
#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", N2_ADDR);
	printfpd("value : 0x%x ",pbsc->bscd[numstruct].n2);
#endif

	outportb(l_base, N3_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n3);

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ",N3_ADDR);
	printfpd("value : 0x%x ", pbsc->bscd[numstruct].n3);
#endif

   outportb(l_base, MS100_ADDR);
   outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].bacotime.Msec100);

#ifdef PRINT_BACO
  	printfpd("\n\r port : 0x%x ", MS100_ADDR);
	printfpd("value : 0x%x ", pbsc->bscd[numstruct].bacotime.Msec100);
#endif


}



void CfgCardBaco()
{
  	for(unsigned i=1; i < NUM_OF_SLOT; i+=2)	//only nechet
	{
	 LoadBaco(i);
	}
}  
 /*

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

*/
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
 /*
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
 */
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





unsigned char trysec; 
unsigned char trymin;
unsigned char tryhour;  
unsigned char tryday;
unsigned char trymon;
unsigned char tryyear;

unsigned long glob_cnt;
unsigned char time_valid;



//BSC pbsc = PBSC;   //this init need make in funktions!!!!

extern "C"unsigned char	CompareStartTime(unsigned char i)
{
#ifdef Debug_Baco1
 printfpd("\n\r  	CompareStartTime %d ", i);
#endif

if(i > 7)
{
   printfpd("\n\r wrong 	CompareStartTime %d ", i);

 return 0;
}

 //return; //t

 unsigned char ret = 0;

unsigned short Year = (unsigned short)ClockReadYear() + (unsigned short)2000;
unsigned char Month;// = ClockReadMonth();
unsigned char Date; //= ClockReadDate();
unsigned char Hours;// = ClockReadHours();
unsigned char Min;// = ClockReadMin();
unsigned char Sec;// = ClockReadSec();
unsigned char mSec;// = ClockReadmSec();

//ok  return 0;
 	   /*
   if(bsc[i].bscd.bacotime.Year < Year)	return 0;
   Month = ClockReadMonth();
   if(bsc[i].bscd.bacotime.Month < Month)	return 0;
   Date = ClockReadDate();
   if(bsc[i].bscd.bacotime.Day < Date)	return 0;
   Hours = ClockReadHours();
   if(bsc[i].bscd.bacotime.Hour < Hours)	return 0;
   Min = ClockReadMin();
   if(bsc[i].bscd.bacotime.Min < Min)	return 0;
   Sec = ClockReadSec();
   if(bsc[i].bscd.bacotime.Sec < Sec)	return 0;
   mSec = ClockReadmSec();
   if(bsc[i].bscd.bacotime.Msec100 < mSec) return 0;
		   */
#ifdef Debug_Baco1
printfp(".Y.");
//  printfpd("bacotime.Year: %d vs",pbsc->bscd[i].bacotime.Year);
 //  printfpd(".Year: %d ",(unsigned)Year);
#endif

   if(pbsc->bscd[i].bacotime.Year > Year)	return 0;
   if(pbsc->bscd[i].bacotime.Year < Year)	return 1;

// return 0; //t	  wrong

#ifdef Debug_Baco1
printfp(".M.");
#endif
   Month = ClockReadMonth();
   if(pbsc->bscd[i].bacotime.Month > Month)	return 0;
    if(pbsc->bscd[i].bacotime.Month < Month)	return 1;

#ifdef Debug_Baco1
printfp(".D.");
#endif
   Date = ClockReadDate();
   if(pbsc->bscd[i].bacotime.Day > Date)	return 0;
     if(pbsc->bscd[i].bacotime.Day < Date)	return 1;

#ifdef Debug_Baco1
printfp(".H.");
#endif
   Hours = ClockReadHours();
   if(pbsc->bscd[i].bacotime.Hour > Hours)	return 0;
    if(pbsc->bscd[i].bacotime.Hour < Hours)	return 1;

#ifdef Debug_Baco1
printfp(".Min.");
#endif
   Min = ClockReadMin();
   if(pbsc->bscd[i].bacotime.Min > Min)	return 0;
    if(pbsc->bscd[i].bacotime.Min < Min)	return 1;

#ifdef Debug_Baco1
printfp(".S.");
#endif
   Sec = ClockReadSec();
   if(pbsc->bscd[i].bacotime.Sec > Sec)	return 0;
   if(pbsc->bscd[i].bacotime.Sec < Sec)	return 1;


  mSec = ClockReadmSec() / 100;

//#ifdef Debug_Baco1
//printfp(".ms.");
//printfpd(" %d vs",pbsc->bscd[i].bacotime.Msec100);
//  printfpd(" %d ",(unsigned)mSec);

//#endif
//   mSec = ClockReadmSec() / 100;
#ifndef Debug_Baco1
   if(pbsc->bscd[i].bacotime.Msec100 > mSec) return 0;
#endif

#ifdef Debug_Baco1
printfp(" ....TIME OK!\n\r");
#endif


  return 1;
}


extern "C" int days_in_month(int month, int year)
  {
      if (year < 0) return -1;
      switch (month) {
          case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                  return 31;
          case 4:case 6:case 9:case 11:
                  return 30;
          case 2:
                  return 28 + int(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
          default:
                  return -1;
      }
  }

extern "C" void SetNextTime(unsigned char i)
{

#ifdef Debug_Baco1
 printfpd("\n\r  SetNextTime %d ", i);
#endif
unsigned short tmp =   pbsc->bscd[i].period;

	pbsc->bscd[i].bacotime.Msec100  += tmp % 10; 

	if(pbsc->bscd[i].bacotime.Msec100 >= 10)
	{
	 pbsc->bscd[i].bacotime.Msec100	-= 10;
	 pbsc->bscd[i].bacotime.Sec +=1; 
	}

	tmp/= 10;	//time go to value in sec
    pbsc->bscd[i].bacotime.Sec 		+= tmp % 60;
   if(pbsc->bscd[i].bacotime.Sec >= 80)
	{
	 pbsc->bscd[i].bacotime.Sec	-= 60;
	 pbsc->bscd[i].bacotime.Min +=1; 
	}

	tmp/= 60; //go to value in minutes	
    pbsc->bscd[i].bacotime.Min      += tmp % 60;
   if(pbsc->bscd[i].bacotime.Min >= 80)
	{
	 pbsc->bscd[i].bacotime.Min	-= 60;
	 pbsc->bscd[i].bacotime.Hour +=1; 
	}

	tmp/= 60; //go to value in hours	
	pbsc->bscd[i].bacotime.Hour     += tmp % 24;

   if(pbsc->bscd[i].bacotime.Hour >= 24)
	{
	 pbsc->bscd[i].bacotime.Hour	-= 24;
	 pbsc->bscd[i].bacotime.Day +=1; 
	}

 if(pbsc->bscd[i].bacotime.Day > days_in_month( pbsc->bscd[i].bacotime.Month, pbsc->bscd[i].bacotime.Year))	//hier need check month and year
	{
	 pbsc->bscd[i].bacotime.Day	= 1;
	 pbsc->bscd[i].bacotime.Month +=1; 
	}

 if(pbsc->bscd[i].bacotime.Month >= 12)
	{
	 pbsc->bscd[i].bacotime.Month = 1;
	 pbsc->bscd[i].bacotime.Year +=1; 
	}
}


unsigned char bcs_is_init;

extern "C" void	 Check_bsc_start()
{

if(!bcs_is_init) return;


unsigned char flag_start = 0;

for (unsigned i = 0; i <  (unsigned)(NUM_OF_SLOT>>1);i++)
{
//  for(unsigned j = 0; j < (unsigned)SIZE_BSC;j++)
//  {


   /*
	if (bsc[i].bscd.trysend)
	{
	  if(CompareStartTime(i))
	  {
	     if(bsc[i].bscd.trysend < 0xff) {bsc[i].bscd.trysend--;}
		 if(bsc[i].bscd.trysend) {SetNextTime(i);}
		 start_cbaco &= (1 << i);
		 flag_start = 1;
		 CfgCardBacoStartTimer((i<<1)+1);
	  }
	}

	 */

	if (pbsc->bscd[i].trysend)
	{
	  if(CompareStartTime(i))
	//  if(0)
	  {
		
	     if(pbsc->bscd[i].trysend < 0xff) {pbsc->bscd[i].trysend--;}
		 if(pbsc->bscd[i].trysend) {SetNextTime(i);}
		 start_cbaco &= (1 << i);
		 flag_start = 1;
		 CfgCardBacoStartTimer((i<<1)+1);
		 
	  }
	}




} //for

   if(flag_start)
   {
	  LoadBacoStartZero();
   }

}

extern "C" void	 clear_bsc()
{

for (unsigned i = 0; i <  (unsigned)(SIZE_BSCP);i++)
{
	pbsc->byte[i] = 0;
} 

}




extern "C" void	 Init_bsc()
{
unsigned char * pSign = (unsigned char *)(BACO_OFFSET_SIGNATURE);
//return; //t
 /*
for (unsigned i = 0; i <  (unsigned)(NUM_OF_SLOT>>1);i++)
{
  for(unsigned j = 0; j < (unsigned)SIZE_BSC;j++)
  {
	bsc[i].byte[j] = 0;
  }
} 
*/

pbsc = PBSC; 
bcs_is_init = 1;



//printfpd("\n\r prsc: 0x%X \n\r", (unsigned long)pbsc);

//return;



#ifndef Debug_Baco1


if(* pSign != 'N')
{
printfp("\n\r Clearing all data of bsc...");
* pSign = 'N';
for (unsigned i = 0; i <  (unsigned)(SIZE_BSCP);i++)
{
	pbsc->byte[i] = 0;
}
} 

#else
 for(unsigned ns = 0; ns <  (unsigned)(NUM_OF_SLOT>>1);ns++)
 {
   pbsc->bscd[ns].bacotime.Year  	=  2015 ;
   pbsc->bscd[ns].bacotime.Month 	=  4;
   pbsc->bscd[ns].bacotime.Day		=  10;
   pbsc->bscd[ns].bacotime.Hour 	=  6;
   pbsc->bscd[ns].bacotime.Min 		=  34;
   pbsc->bscd[ns].bacotime.Sec 		=  0;
   pbsc->bscd[ns].bacotime.Msec100  =  5;
   pbsc->bscd[ns].period 			=  100 ;		 //10s
   pbsc->bscd[ns].trysend 			=  ns+1;	 //counter
   pbsc->bscd[ns].rezerv 			=  0;
 }

#endif


}
 
unsigned int_cnt;

//unsigned char bcs_is_init;

extern "C" void baco_init()
{
  bcs_is_init = 0;

  int_cnt = 0;

  time_valid = 0;
//tInit_bsc();

glob_cnt = 0;
trysec = 0; 
trymin = 0;
tryhour = 0;  
tryday = 0;
trymon = 0;
tryyear = 0;  


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
	embRS232.EmptyReceive();
	embRS485.EmptyReceive();

	
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
	}
	RestoreCBaco();
	start_cbaco = 0;

}

 extern "C" mf20_detect()
{

printfp("\n\r MF20_Detect\n\r");

	Autodetect(unEmb2TypeVer);
 	unEmb2TypeVer.emb2TypeVer.type       = 0x0905;
 //	unEmb2TypeVer.emb2TypeVer.type       = 0x0201;	 //temporary as mf20
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
 //141021	CfgCard();
 //141021  	SaveCommut();

Init_bsc();
 RestoreCBaco();
   CfgCardBaco();
   delay_mcs(50);
    LoadModeBaco(0);

	  delay_mcs(50);
    LoadFiltersBaco();
	  delay_mcs(50);

 LoadFreqBaco();   //for pimenov


   CfgCardBacoStart();
 // CfgCardBaco();
  // CfgCardBacoStart();

//  LoadFiltersBaco();


  ubx_device_init();   //9600!!!!

// 	}
 //  StartSaveCommut();
//////////////////////////////////////////////////
}

//extern "C" void mf20()
//	while(1)
extern "C" void baco()
{
 //	static char cnt06;
 static unsigned counter;
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
//141021        mf20TimerBufferTLF.Deal();		//_____________________t
 	 //	my_printf(0x12); //t1109
   
 counter++;

//if(GetTestMode() == 0x50)
//{
#ifndef Debug_Baco1
if(counter > 25)
#else
if(counter > 3000)
#endif
 {
// printfpd("\n\rhave hour : %d",   ClockReadHours()); 
//  printfpd("\n\rhavesec : %d",   ClockReadmSec()); 
  counter = 0;
 //do not use my_int_enable_irq0();
  Check_bsc_start();
 }
//} 
  
//glob_cnt++;

if(glob_cnt < 1000)	   //celling up 1000ms
{
 glob_cnt++;
} 
else
{
//printfpd("\n\r int_cnt:%d", int_cnt);
 glob_cnt = 0;
}

ubx_device_mon();

//Check_bsc_start();

  return;




   		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
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


//___________________________________________________________<<< from bmd_34

	  if(embMsg.IsEnd())//&&embMsg.ChkCRC())

			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg;
					flagRequest=1;
				//	my_printf(0x20);   //t
				}
			}
			if(flagRequest)//embMsgRequest->IsEnd())
			{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());


					switch(embMsgRequest->Type())
					{

				  	case 0x01: // запрос типа
				//	printf("\n\r01>"); 
//__________________________________________________________________________________
 //	  Ring(1,1,5,1);
				   //t		embMsgAns.SetTOM(0x20);
				  // 		embMsgAns.SetAddrI(SelfID());  //t
				  //  	embMsgAns.SetAddrS(SelfID());  //t
			   //	  if(flagRequest == 1) 
				 //	{
				 //		embMsgAns.SetTOM(0x20);
				  //		embMsgAns.SetAddrI(SelfID());
				   //		embMsgAns.SetAddrS(SelfID());
				   //	}			
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//=====================================BACO
		  	case 0x02: // write config
				//	printf("\n\r01>"); 
  					   for(i=0; i<128; i++)
					    {
					    cbaco.byte[i] = embMsgRequest->Body(0);   //
					 	}
						CfgCardBaco();
						KeepCBaco();
					  //	LoadBlocks();
						embMsgAns.SetType(0x02);
						embMsgAns.SetLength(1);
					    embMsgAns.SetBody(0,0);
						break;

		  	case 0x03: // read config
				//	printf("\n\r01>"); 
						embMsgAns.SetType(0x03);
						embMsgAns.SetLength(128);
					    for(i=0; i<128; i++)
					    {
					     embMsgAns.SetBody(i,cbaco.byte[i]);   //
					 	}
						break;


		  	case 0x04: // select channel
				//	printf("\n\r01>"); 

						start_cbaco  = embMsgRequest->Body(0) + (embMsgRequest->Body(1) << 8);
						CfgCardBacoStart();
						embMsgAns.SetType(0x04);
						embMsgAns.SetLength(2);
					    embMsgAns.SetBody(0,embMsgRequest->Body(0));
				        embMsgAns.SetBody(1,embMsgRequest->Body(1));
						break;

//=====================================BACO
				  /*
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
			 //		mf20_init();
					baco_init();
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
				   */
		  default : break;
		}	// type
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

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


 
//_______________________________________________________________Test TLLO
//_______________________________________________________________BUS Test

//added 130516 for compiling!!!!!!!!!!!!!!!!!
extern "C" void emb_use_irq0()
{
  int_cnt++;


// if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
// {
//   InterruptWatchDog++;
//   my_int_enable_irq0();
// }

}

extern "C" void  ParseCommand1()
{
  //	 add_char_TCP_buff(TYPE_AUTO);

add_char_TCP_buff(0x01);
add_char_TCP_buff(0x00);
add_char_TCP_buff(0xff);
add_char_TCP_buff(0xff);





	 for(long i = 0; i < 44; i++)
	 {
	   add_char_TCP_buff(unEmb2TypeVer.byte[i]);
	 }
   //	 breakflag =1; 
}

			  /*
	  	case 0x02: // write config
				//	printf("\n\r01>"); 
  					   for(i=0; i<128; i++)
					    {
					    cbaco.byte[i] = embMsgRequest->Body(0);   //
					 	}
						CfgCardBaco();
						KeepCBaco();
					  //	LoadBlocks();
						embMsgAns.SetType(0x02);
						embMsgAns.SetLength(1);
					    embMsgAns.SetBody(0,0);
						break;
						 
 			   */
extern "C" void  ParseCommand2(char *IPBuff)
{

	add_char_TCP_buff(0x02);
	add_char_TCP_buff(0x00);
	add_char_TCP_buff(0xff);
	add_char_TCP_buff(0xff);

  	for(unsigned i=0; i< BACO_SIZE; i++)
	    {
		    cbaco.byte[i] = IPBuff[i+4];   //
	 	}
	CfgCardBaco();
	KeepCBaco();
   add_char_TCP_buff(0x00);

	  
}

  			  /*
		  	case 0x03: // read config
				//	printf("\n\r01>"); 
						embMsgAns.SetType(0x03);
						embMsgAns.SetLength(128);
					    for(i=0; i<128; i++)
					    {
					     embMsgAns.SetBody(i,cbaco.byte[i]);   //
					 	}
						break;

							*/

extern "C" void  ParseCommand3(char *IPBuff)
{

	add_char_TCP_buff(0x03);
	add_char_TCP_buff(0x00);
	add_char_TCP_buff(0xff);
	add_char_TCP_buff(0xff);

  	for(unsigned i=0; i<BACO_SIZE; i++)
	    {
		    add_char_TCP_buff(cbaco.byte[i]);   //
	 	}
  
	  
}


  

  
			   /*
		  	case 0x04: // select channel
				//	printf("\n\r01>"); 

						start_cbaco  = embMsgRequest->Body(0) + (embMsgRequest->Body(1) << 8);
						CfgCardBacoStart();
						embMsgAns.SetType(0x04);
						embMsgAns.SetLength(2);
					    embMsgAns.SetBody(0,embMsgRequest->Body(0));
				        embMsgAns.SetBody(1,embMsgRequest->Body(1));
						break;
					   */

extern "C" void  ParseCommand4(char *IPBuff)
{
  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x04);
	add_char_TCP_buff(0x00);
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);

  	start_cbaco  = IPBuff[2] + (IPBuff[3] << 8);
	CfgCardBacoStart();
	  
 //	add_char_TCP_buff((unsigned char)start_cbaco);
 //	add_char_TCP_buff((unsigned char)start_cbaco>>8);
}

extern "C" void  ParseCommand5(char *IPBuff)
{
 unsigned long size;

  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x05);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
 size =	(IPBuff[7] << 24) +  (IPBuff[6] << 16)	+  (IPBuff[5] << 8)	+   IPBuff[4];
 size <<= 2; //size in words
 if(size > MAX_FILTER_SIZE)
 {
  printfpd("\n\rkeep size too big : %d", size);
  size =  MAX_FILTER_SIZE;
  add_char_TCP_buff(0);
  add_char_TCP_buff(0);
  add_char_TCP_buff(0);
  add_char_TCP_buff(0);
 }
 else
 {
   printfpd("\n\rkeep size is OK : %d", size);
 
 for(unsigned i=0; i < size + 4; i++)		//first 4 - size
 {
    write_nvram_char((BACO_OFFSET_FILTER + i), IPBuff[4 + i]);
 }

    add_char_TCP_buff(IPBuff[4]);
	add_char_TCP_buff(IPBuff[5]);
	add_char_TCP_buff(IPBuff[6]);
	add_char_TCP_buff(IPBuff[7]);

 }

   LoadFiltersBaco();

  delay_mcs(50);

 LoadFreqBaco();   //pimenov need 


//  	start_cbaco  = IPBuff[2] + (IPBuff[3] << 8);
//	CfgCardBacoStart();
	  
 //	add_char_TCP_buff((unsigned char)start_cbaco);
 //	add_char_TCP_buff((unsigned char)start_cbaco>>8);
}

extern "C" void  ParseCommand6(char *IPBuff)
{
 unsigned long size;

  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x06);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
  
 for(unsigned i=0; i < 4; i++)		//first 4 - size
 {
    write_nvram_char((BACO_OFFSET_FREQ + i), IPBuff[4 + i]);
 }

    add_char_TCP_buff(IPBuff[4]);
	add_char_TCP_buff(IPBuff[5]);
	add_char_TCP_buff(IPBuff[6]);
	add_char_TCP_buff(IPBuff[7]);

// }

   LoadFreqBaco();

//  	start_cbaco  = IPBuff[2] + (IPBuff[3] << 8);
//	CfgCardBacoStart();
	  
 //	add_char_TCP_buff((unsigned char)start_cbaco);
 //	add_char_TCP_buff((unsigned char)start_cbaco>>8);
}

extern "C" void  ParseCommand7(char *IPBuff)
{
 unsigned long size;

  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x07);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
  
// for(unsigned i=0; i < 4; i++)		//first 4 - size
// {
  //  write_nvram_char((BACO_OFFSET_MODE), IPBuff[4]);
// }



    add_char_TCP_buff(IPBuff[4]);

// }

   LoadModeBaco(IPBuff[4]);

//  	start_cbaco  = IPBuff[2] + (IPBuff[3] << 8);
//	CfgCardBacoStart();
	  
 //	add_char_TCP_buff((unsigned char)start_cbaco);
 //	add_char_TCP_buff((unsigned char)start_cbaco>>8);
}

extern "C" void  ParseCommand8(char *IPBuff)
{
 unsigned long size;
 unsigned ns = 0;
 unsigned char tmp = 1;
// unsigned i;

  printfpd("\n\r  ParseCommand8 0x%x ", IPBuff[2]);

	add_char_TCP_buff(0x08);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
  
// for(unsigned i=0; i < 4; i++)		//first 4 - size
// {
  //  write_nvram_char((BACO_OFFSET_MODE), IPBuff[4]);
// }

 //   add_char_TCP_buff(IPBuff[4]);
//	for (unsigned i = 0; i <  (unsigned)(NUM_OF_SLOT>>1);i++)
//{

 // ns = (IPBuff[2] - 1)>>1;
 // if(ns < (NUM_OF_SLOT>>1))

 for(ns = 0; ns < (NUM_OF_SLOT>>1); ns++ )
 {
	if(IPBuff[2] & tmp)
	{
  
  /*
  for(unsigned j = 0; j < (unsigned)SIZE_BSC;j++)
  {
	bsc[(IPBuff[2] - 1)>>1].byte[j] = IPBuff[4 + j];
  }
   */
   pbsc->bscd[ns].bacotime.Year  	=  IPBuff[4] + (IPBuff[5] << 8) ;
   pbsc->bscd[ns].bacotime.Month 	=  IPBuff[6];
   pbsc->bscd[ns].bacotime.Day		=  IPBuff[7];
   pbsc->bscd[ns].bacotime.Hour 	=  IPBuff[8];
   pbsc->bscd[ns].bacotime.Min 		=  IPBuff[9];
   pbsc->bscd[ns].bacotime.Sec 		=  IPBuff[10];
   pbsc->bscd[ns].bacotime.Msec100  =  IPBuff[11];
   pbsc->bscd[ns].period 			=  IPBuff[12] + (IPBuff[13] << 8) ;
   pbsc->bscd[ns].trysend 			=  IPBuff[14];	 //counter
   pbsc->bscd[ns].rezerv 			=  IPBuff[15];
   pbsc->bscd[ns].n0 				=  IPBuff[16];
   pbsc->bscd[ns].n1 				=  IPBuff[17];
   pbsc->bscd[ns].n2 				=  IPBuff[18];
   pbsc->bscd[ns].n3 				=  IPBuff[19];

   }  //if

//} 
 //   add_char_TCP_buff(0x00);
//  }
   tmp <<= 1;  //set to next bit

}
  /*
  else
  {

  printfpd("\n\r wrong number of slot : %d", IPBuff[2] ); 
  add_char_TCP_buff(0x01);
  }
	*/

 add_char_TCP_buff(0x00);

}

extern "C" void  ParseCommand9(char *IPBuff)
{
  printfpd("\n\r  ParseCommand9 0x%x ", IPBuff[2]);

 unsigned long size;
 unsigned ns;
  unsigned char tmp = 1;


 //  printfpd("\n\r  ParseCommand9 0x%x ", IPBuff[2]);

  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x09);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
  
// for(unsigned i=0; i < 4; i++)		//first 4 - size
// {
  //  write_nvram_char((BACO_OFFSET_MODE), IPBuff[4]);
// }
// ns = (IPBuff[2] - 1)>>1;
//  if(ns < (NUM_OF_SLOT>>1)	)
// {
    for(ns = 0; ns < (NUM_OF_SLOT>>1); ns++ )
 {
	if(IPBuff[2] & tmp)
	{




 /* 
   for(unsigned j = 0; j < (unsigned)SIZE_BSC;j++)
  {
	add_char_TCP_buff(bsc[ns].byte[j]);
  }

 */

   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Year);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Year>>8);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Month);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Day);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Hour);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Min);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Sec);
   add_char_TCP_buff(pbsc->bscd[ns].bacotime.Msec100);
   add_char_TCP_buff(pbsc->bscd[ns].period);
   add_char_TCP_buff(pbsc->bscd[ns].period >> 8);
   add_char_TCP_buff(pbsc->bscd[ns].trysend); //counter
   add_char_TCP_buff(pbsc->bscd[ns].rezerv);
   add_char_TCP_buff(pbsc->bscd[ns].n0);
   add_char_TCP_buff(pbsc->bscd[ns].n1);
   add_char_TCP_buff(pbsc->bscd[ns].n2);
   add_char_TCP_buff(pbsc->bscd[ns].n3);
 	}

    tmp <<= 1;  //set to next bit

 }

/*
  else
  {

  printfpd("\n\r wrong number of slot : %d", IPBuff[2] ); 
    add_char_TCP_buff(0x01);
  }
 	 */
}




extern "C" void  ParseCommand10(char *IPBuff)
{
 unsigned long size;
 unsigned short year;
 unsigned char ms10;

 ms10 = (ClockReadmSec()/100)  | time_valid;
 //printfpd("\n\r ms10 : %d", ms10);

    year = 2000 + ClockReadYear();

  // printfp("\n\r  ParseCommand4 ");
	add_char_TCP_buff(0x0A);
	add_char_TCP_buff(0x00);
//________________________________channel
	add_char_TCP_buff(IPBuff[2]);
	add_char_TCP_buff(IPBuff[3]);
//________________________________quantity
 
	add_char_TCP_buff(year);
	add_char_TCP_buff(year >> 8);
	add_char_TCP_buff(ClockReadMonth());
	add_char_TCP_buff(ClockReadDate());
	add_char_TCP_buff(ClockReadHours());
	add_char_TCP_buff(ClockReadMin());
	add_char_TCP_buff(ClockReadSec());
	add_char_TCP_buff(ms10);
}






