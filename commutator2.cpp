//#ifndef __TINY__
//#define __TINY__
//#endif
#include "start.h"
#include "hello7.h"
#include "embisr.h"
//#include <UstirKCC1.cpp>
#include <UstirKCC2.cpp>





#ifdef PROG_PU_M_V
 unsigned char cur_req_quantity;
#endif

/* port

	  

#ifndef __TINY__
#define __TINY__
#endif
#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
#define IncEmbRS232
//#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
//#define IncEmbSerialACT155
#define IncEmbSerialPU_M
////////////////////////////////////////////
#include "longtoa.cas"
#include "Ltoa1.c"
#include "stdlib.h"
//#include "command.h"
#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"


void ResetWatchDog()
{
	outport(wdtcon,0xAAAA);
	outport(wdtcon,0x5555);
	outportb(0x6FB,0x55);
};
 */

  unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;
 unsigned long cnt_rcv;


struct sendcash
{
	unsigned long cnum;
	unsigned long as;
	unsigned long ai;
	unsigned long ar;
	unsigned char isRS485;
};

class buffcash
{
 public:
   sendcash buffc[CASHE_SIZE];	
//   char compare(unsigned long , unsigned long , unsigned long , unsigned long );
   unsigned char compare(unsigned long , unsigned long , unsigned long , unsigned long , unsigned long);
   void add(unsigned long , unsigned long , unsigned long , unsigned long, unsigned char );
   void init(void);
   unsigned long cashp;
};
   /*
#ifdef ETH_TRANZIT
buffcash buff_cashe;
#endif //ETH_TRANZIT
	  */

//!!!!! need init!!!!!
buffcash buff_cashe_modem;
buffcash buff_cashe_tranzit;
buffcash buff_cashe_up1;
buffcash buff_cashe_up2;

 /*
#ifdef PLUS_TR3
buffcash buff_cashe_n1;
buffcash buff_cashe_n2;
buffcash buff_cashe_n3;
#endif //PLUS_TR3
   */






//buffcash buff_cashe_request;

void buffcash::init(void)
{
cashp = 0;
for(long i = 0; i < CASHE_SIZE; i++)
{
 //buff_cashe.buffc[i].cnum = 0;
 buffc[i].cnum = 0;
 buffc[i].as = 0;
 buffc[i].ai = 0;
 buffc[i].ar = 0;
 buffc[i].isRS485 = 0;
}
}


//char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc)
unsigned char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc, unsigned long isrs485)
{

#ifdef CASHE_OFF
return 0; //test
#endif

//char ret = 0;
//  printf("== %02X %04X %04X ==", numloc, asloc,  ailoc);
for(long i = 0; i < CASHE_SIZE; i++)
{

/*
 if(!((buff_cashe.buffc[i].cnum != num) &&
  (buff_cashe.buffc[i].as != as) &&
   (buff_cashe.buffc[i].ai != ai))) { return 1;}
	 */
   if(buffc[i].cnum == numloc)
   {
//    printf(" -3- ");

   if(buffc[i].as == asloc)
   {
//    printf(" -2-");

   if(buffc[i].ai == ailoc)
    {
	// if(buff_cashe.buffc[i].ar == arloc)
  	 if((buffc[i].ar == arloc)	|| 	(!(buffc[i].isRS485)))
  //	 if(buffc[i].ar == arloc)  //need see only if isrs485
    {
	 if(buffc[i].isRS485 == isrs485)
    {



//	#ifdef ETH_DEBUG_ENABLED
//   	  printEthStringAdd(1,7);
//	   printEthStringAdd(1,i);
//	    printEthStringAdd(1,numloc);
// 		printEthStringAdd(1,asloc);
// 		printEthStringAdd(1,ailoc);
 //	   printEthStringAdd(1,buffc[i].cnum);

 		
	

  //	#endif


//    printf(" -1-");
     return 1;}
	}
	}
	}
	}
}
  // printf("== %02X %04X %04X ==", numloc, asloc,  ailoc);
//   printf(" -0-");
//#ifdef ETH_DEBUG_ENABLED
//   	  printEthStringAdd(1,8);
//#endif
 return 0;
}
void buffcash::add(unsigned long num, unsigned long as, unsigned long ai, unsigned long ar, unsigned char isRS485)
{
//return; //t

//for(long i = (CASHE_SIZE - 1) ; i > 0; i--)
//{
// buffc[i].cnum = buffc[i-1].cnum;
// buffc[i].as = buffc[i-1].as;
// buffc[i].ai = buffc[i-1].ai;
// buffc[i].ar = buffc[i-1].ar;
// buffc[i].isRS485 = buffc[i-1].isRS485;

//}
 buffc[cashp].cnum = num;
 buffc[cashp].as = as;
 buffc[cashp].ai = ai;
 buffc[cashp].ar = ar;
 buffc[cashp].isRS485 = isRS485;

cashp++;
if(cashp >= CASHE_SIZE)	 cashp = 0;

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
/*
union u2uc
{
  unsigned u;
	unsigned char uc[2];
};
*/
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

struct EmbMsg485
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];

	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned short CRC() {	return body[body[1]+2]+1; }
	unsigned char Body(int i) { return body[i+2]; }

	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }

	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 64-counter; }
	int short IsEnd();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsg485::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++) body[i]=0;
}

unsigned short EmbMsg485::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsg485::IsEnd()
{
  if(counter>2)
  if(counter==Length()+3)
			return 1;
	return 0;
} 

unsigned short EmbMsg485::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned short EmbMsg485::CalcCRC()
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

// 	unsigned CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }
struct MsgStatus
{
	unsigned readyToSend : 1;
	unsigned isRS232 : 1;
	unsigned isRS485 : 1;
	unsigned reserved : 5;
};

union UnMsgStatus
{
	MsgStatus msgStatus;
	unsigned char byte;
};

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

unsigned EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
		return 1;
	}
	else
	  return 0;
}

int EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int EmbMsg::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned EmbMsg::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

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
*/
/////////////////////

struct AMsg
{
  unsigned char body[STR_UST_LEN];
};

struct AMsgBuffer
{
    unsigned BuffSize;
    unsigned Head;
    unsigned Tail;
    AMsg Buff[16];
    public:
    void Init();
    void Add(AMsg&);
    void Get(AMsg&);
    unsigned Used();
    unsigned Free();
};

void AMsgBuffer::Init()
{
  BuffSize = 16;
  Head = 0;
  Tail = 0;
}

void AMsgBuffer::Add(AMsg &msg)
{
	for(int i=0; i< STR_UST_LEN; i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize) Head = 0;
}

void AMsgBuffer::Get(AMsg &msg)
{
  if(++Tail < BuffSize) 
	{
		for(int i=0; i<STR_UST_LEN; i++) msg.body[i] = Buff[Tail-1].body[i];
	}
	else
	{
		Tail = 0;
		for(int i=0; i<STR_UST_LEN; i++) msg.body[i] = Buff[BuffSize-1].body[i];
	}
}

unsigned AMsgBuffer::Used()
{
  int n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
}

unsigned AMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}



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
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }
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
 /*
unsigned short EmbMsg::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}
 */
unsigned short EmbMsg::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
  //	if(typeOfProtocol==2)
   //	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();
 #ifdef DEBUG_LOOP_PRINT

			printfpd("\n\rc= %02X", c);	
			printfpd("b= %02X\n\r", b);	
 #endif
			if(b==c) return 1;
			else return 0;
		}
//	}
    return 1;
}

unsigned short EmbMsg::CalcCRC()
{
  int i;
	unsigned c=0;
 //	if(typeOfProtocol==2)
  //	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			body[Length()+11]=(c>>8)&0xFF;
			body[Length()+12]=c&0xFF;
			return c;
		}
		else return 0;
  //	}
  //	else return 0;
} 


 /*
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

union UnEmb2TypeVer
{
	Emb2TypeVer emb2TypeVer;
	unsigned char byte[44];
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
	unsigned char reserv1;	 //my					// 1 //2
	unsigned char reserv2;	 //my						 //3
	unsigned long ulBlock;				// 6
	unsigned long ulErrOut;				// 10
	unsigned long ulErrAfterRS1;	// 14
	unsigned long ulErrAfterRS2;	// 18
	unsigned long ulErrBeforeRS1;	// 22
	unsigned long ulErrBeforeRS2;	// 26
	unsigned char state[16];			// 42
};

union UnStatePUM
{
	StatePUM statePUM;
	unsigned char byte[42];
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
//________________________________________________________new
/*
#ifdef PROG_PU_M_MUX

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

#endif //PROG_PU_M_MUX
	   */
//________________________________________________________________<< new
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

#ifdef RS485_MSG_BUFF

	   EmbMsgBuffer tBuffRS485;
	   unsigned long time_lastsend_rs485;
	   unsigned char flag_wait_rs485;
#endif



//___________________________________________________________________need init!!!
unsigned long time1=0,time2=0,time3=0,time4=0,time5=60;
unsigned char flagADUC1=0, flagADUC2=0;

//______________________________________________________________added of  me
 UL2UC ul2uc;
 UI2UC ui2uc;
 unsigned short temp_crc;
// unsigned char * addrRAM;
 unsigned long shift;
 unsigned long len;

//____________________________________________________________<< added of me

void Callback0()
{
  time1++;
  time2++;
  time3++;
  time4++;
  time5++;
///////////  Первая ВНЧ  ////////////
/*	if(inportb(0x10)!=0xFF) 
		if(inportb(0x10)&0x10) 
			flagADUC1++;
///////////  Вторая ВНЧ  ////////////
	if(inportb(0xC0)!=0xFF) 
		if(inportb(0xC0)&0x10) 
			flagADUC2++;*/
/////////////////////////////////////
}

//--------------------------------------------------
	EmbTimerCallback embTimerCallback0;

//110725	EmbMsgBuffer rBuffEmbMsg; //temporary
	
	EmbMsgBuffer rBuffEmbMsgWest;
	EmbMsgBuffer rBuffEmbMsgEast;
	EmbMsgBuffer rBuffEmbMsgNorth;
	EmbMsgBuffer rBuffEmbMsgSouth;	
	
	EmbMsgBuffer rBuffEmbMsg232;
	EmbMsg embMsgA;	

		
	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;

	EmbMsg embMsg;
	EmbMsg embMsgWest;
	EmbMsg embMsgEast;

 /*
#ifdef PLUS_TR3

EmbMsgBuffer tBuffEmbMsgN1;
EmbMsg embMsgN1;
unsigned char markerN1=0,  ready_n1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char  old_ready_n1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char delete_msgN1=0, recieveN1=0;
unsigned char n1Byte; 
unsigned long time3BlankN1=0;

EmbMsgBuffer tBuffEmbMsgN2;
EmbMsg embMsgN2;
unsigned char markerN2=0,  ready_n2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char  old_ready_n2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char delete_msgN2=0, recieveN2=0;
unsigned char n2Byte; 
unsigned long time3BlankN2=0;

EmbMsgBuffer tBuffEmbMsgN3;
EmbMsg embMsgN3;
unsigned char markerN3=0,  ready_n3=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char  old_ready_n3=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char delete_msgN3=0, recieveN3=0;
unsigned char n3Byte; 
unsigned long time3BlankN3=0;



#endif //	PLUS_TR3
   */

//_________________________________________north_south
//need init!!!!!!!!!!!!!!!!


EmbMsgBuffer tBuffEmbMsgNorth;
EmbMsg embMsgNorth;
unsigned char markerNorth=0,  ready_up1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char  old_ready_up1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char delete_msgNorth=0, recieveNorth=0;
unsigned char northByte; 
unsigned long time3BlankUp1=0;

 

EmbMsgBuffer tBuffEmbMsgSouth;
EmbMsg embMsgSouth;
unsigned char markerSouth=0,  ready_up2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char  old_ready_up2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
unsigned char delete_msgSouth=0, recieveSouth=0;
unsigned char southByte;
unsigned long time3BlankUp2=0;

//_________________________________________


	EmbMsg embMsgAns;
//	EmbMsg embMsgTemp;

	EmbMsg485 embMsg485_1;
	EmbMsg485 embMsg485_2;
	EmbMsg485 embMsg485Request_1;
	EmbMsg485 embMsg485Request_2;

//	EmbMsgCover embMsgCoverRequest;
	EmbMsg *embMsgRequest;

	EmbRS232 embRS232;
	EmbRS485 embRS485;
	

#ifndef CHANGE_USART12
    EmbMsg embMsg485;	 //added 090406
#else
   EmbMsg485  embMsg485;
#endif


	EmbMsg embMsg232;	 //added 090406
	EmbMsg embMsg232E;	 //added 090406
	EmbMsg embMsg485E;	  //added 090406

    EmbSerialPU_M embSerialACT155;
//-------------------------------------------------

	unsigned short aI, aS, aR;	  //added 090406

	unsigned char mode5A232E = 0;   //added 090406
	unsigned char mode5A485E = 0;	 //added 090406
	unsigned char mode5A485 = 0;    //added 090406




		
//	EmbSerialACT155 embSerialACT155;
  
	UL2UC ul2uc;
	UI2UC ui2uc;

	unsigned char  * addrRAM;

//	unsigned shift;
 //	unsigned len;
 //	unsigned temp_crc;

	char ch;
	long f_len;

//___________________________________________________________________need init!!!!
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
	unsigned countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];

	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1, tst_ppu1; 
	unsigned char err_ppu2, tst_ppu2; 
	unsigned char byte, westByte, eastByte; 
	unsigned char mode5A=0, mode5AWest=0, mode5AUp1=0, mode5AUp2=0, mode5AEast=0; 
	unsigned char mode5AAnt;
	unsigned char cycle=0;
	unsigned char i232=0, iTrans=0, iMod=0;
	unsigned char ans1=0, ans2=0, addr485=0;

	UnStateBMD155 unStateBMD155;
	UnEmb2TypeVer unEmb2TypeVer; 
	UnEmb2NetStat unEmb2NetStat;
	UnStateRRL unStateRRL;
	UnStatePUM unStatePUM;

#ifdef PROG_PU_M_MUX
 	UnEmb2Mux34 unEmb2Mux34;
#endif // PROG_PU_M_MUX


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
	unsigned char  *bt;

//west = mod
//ost = trans
//north = pum1
//south = pum2




//__________________________________________________
void ProtocolFromUD1ACT155()
{

	while(embSerialACT155.UsedUD1())
	{
   //			ResetWatchDog();
//			if(++ic>16) return;
			northByte = embSerialACT155.GetUD1();
			switch(northByte)
			{
			case 0x55: 
				time3BlankUp1 = time1; ready_up1=1; recieveNorth=0; embMsgNorth.Init(); break; 			
			case 0xAA: recieveNorth = 1; ready_up1=1; time3BlankUp1 = time1; embMsgNorth.Init();	break; 			
			case 0xA5: markerNorth  = 1; ready_up1=1; time3BlankUp1 = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AUp1=1; ready_up1=1; break;
			default:
				if(markerNorth==1)	markerNorth=2; 
				if(recieveNorth==1)
				{
					if(mode5AUp1) { embMsgNorth.Add(Modify5A(northByte)); mode5AUp1=0;	}
					else embMsgNorth.Add(northByte);
				}
			}

		if(embMsgNorth.IsEnd())
#ifdef CHECK_CRC   
  if(embMsgNorth.ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
		{
   	 //	 printEthLongHex(1);
  //		recv_buff_cnt1++;
  	      if(buff_cashe_up1.compare((unsigned long)embMsgNorth.body[1], (unsigned long)embMsgNorth.AddrS(), (unsigned long)embMsgNorth.AddrI(), (unsigned long)embMsgNorth.AddrR(), (unsigned long)embMsgNorth.IsRS485()) != 1)
   		   	{
		  	 buff_cashe_up1.add(embMsgNorth.body[1], embMsgNorth.AddrS(), embMsgNorth.AddrI(), embMsgNorth.AddrR(), (unsigned long)embMsgNorth.IsRS485());
#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
        if( embMsgNorth.AddrI() == 0x7766) {  printfp("_north_");}
#endif



				if((embMsgNorth.AddrS()!=SelfID())&&(embMsgNorth.AddrI()!=SelfID()))
				{

					  tBuffEmbMsgSouth.Add(embMsgNorth);
					  tBuffEmbMsgWest.Add(embMsgNorth);
					  tBuffEmbMsgEast.Add(embMsgNorth);

				   /*

						// передаем побайтно дальше принимаем пакет
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgNorth.FullSize(); i++) 
					{
						switch(embMsgNorth.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgNorth.body[i]);
						}
					}
					embSerialACT155.AddTransitM(0x55);
//_______________
// hier need add another two direction

				embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgNorth.FullSize(); i++) 
				{

					switch(embMsgNorth.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgNorth.body[i]);
					}
				}
				 embSerialACT155.AddModM(0x55);

					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgNorth.FullSize(); i++) 
					{
						switch(embMsgNorth.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgNorth.body[i]);
						}
					}
				   embSerialACT155.AddUD2M(0x55);	

						 */

//______________
				}
					
				if(embMsgNorth.AddrS()==SelfID())
				{
					embMsgNorth.SetDir(3);
					rBuffEmbMsgNorth.Add(embMsgNorth);
		 //			embMsgNorth.Init();
				}
		   //		embMsgNorth.Init(); //101210
		   //		recieveNorth = 0;
		   } //cashe
  	 	    embMsgNorth.Init(); //101210
	 		 recieveNorth = 0;
 		}	//is end



	} //while

//		if(!recieveWest)
  //		{
			if(tBuffEmbMsgNorth.Used())
			{
	  //	  send_buff_cnt++;

				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgNorth.Get(embMsgA);

//______________
			embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgA.body[i]);
						}
					}
		  embSerialACT155.AddUD1M(0x55);	

//______________
 /*
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
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransit(0x55);
//__________________________________________
//hier need add two direction
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


					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgA.body[i]);
						}
					}


	  */
//__________________________________________

	 //		}
   //		}
	}
}


void ProtocolFromUD2ACT155()
{
	while(embSerialACT155.UsedUD2())
	{
   //			ResetWatchDog();
//			if(++ic>16) return;
			southByte = embSerialACT155.GetUD2();
			switch(southByte)
			{
			case 0x55: 
				time3BlankUp2 = time1; ready_up2=1; recieveSouth=0; embMsgSouth.Init(); break; 			
			case 0xAA: recieveSouth = 1; ready_up2=1; time3BlankUp2 = time1; embMsgSouth.Init();	break; 			
			case 0xA5: markerSouth  = 1; ready_up2=1; time3BlankUp2 = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AUp2=1; ready_up2=1; break;
			default:
				if(markerSouth==1)	markerSouth=2; 
				if(recieveSouth==1)
				{
					if(mode5AUp2) { embMsgSouth.Add(Modify5A(southByte)); mode5AUp2=0;	}
					else embMsgSouth.Add(southByte);
				}
			}

		if(embMsgSouth.IsEnd())
#ifdef CHECK_CRC   
  if(embMsgSouth.ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
		{
   	//	 printEthLongHex(2);
   //		 recv_buff_cnt2++;
  	      if(buff_cashe_up2.compare((unsigned long)embMsgSouth.body[1], (unsigned long)embMsgSouth.AddrS(), (unsigned long)embMsgSouth.AddrI(), (unsigned long)embMsgSouth.AddrR(), (unsigned long)embMsgSouth.IsRS485()) != 1)
   		   	{
		  	 buff_cashe_up2.add(embMsgSouth.body[1], embMsgSouth.AddrS(), embMsgSouth.AddrI(), embMsgSouth.AddrR(), (unsigned long)embMsgSouth.IsRS485());

#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
        if( embMsgSouth.AddrI() == 0x7766) {  printfp("_south_");}
#endif


				if((embMsgSouth.AddrS()!=SelfID())&&(embMsgSouth.AddrI()!=SelfID()))
				{

					  tBuffEmbMsgNorth.Add(embMsgSouth);
					  tBuffEmbMsgWest.Add(embMsgSouth);
					  tBuffEmbMsgEast.Add(embMsgSouth);


				/*

						// передаем побайтно дальше принимаем пакет
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgSouth.FullSize(); i++) 
					{
						switch(embMsgSouth.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgSouth.body[i]);
						}
					}
					embSerialACT155.AddTransitM(0x55);	
//_______________
// hier need add another two direction

				embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgSouth.FullSize(); i++) 
				{

					switch(embMsgSouth.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgSouth.body[i]);
					}
				}
			   embSerialACT155.AddModM(0x55);

					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgSouth.FullSize(); i++) 
					{
						switch(embMsgSouth.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgSouth.body[i]);
						}
					}
				 embSerialACT155.AddUD1M(0x55);	
					*/

//______________
				}
					
				if(embMsgSouth.AddrS()==SelfID())
				{
					embMsgSouth.SetDir(4);
					rBuffEmbMsgSouth.Add(embMsgSouth);
		   //			embMsgSouth.Init();
				}
		 //		embMsgSouth.Init(); //101210
		//		recieveSouth = 0;
		   } //cashe
   	 embMsgSouth.Init(); //101210
    recieveSouth = 0;

	 }	//IsEnd
   }

//		if(!recieveWest)
  //		{
			if(tBuffEmbMsgSouth.Used())
			{
	 //		send_buff_cnt++;
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgSouth.Get(embMsgA);

			embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgA.body[i]);
						}
					}

		   embSerialACT155.AddUD2M(0x55);	
	  /*
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
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransit(0x55);
//__________________________________________
//hier need add two direction
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


					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgA.body[i]);
						}
					}

				   */

//__________________________________________

   //			}
  //		}
	}
}




//__________________________________________________


unsigned long pkt_cnt;

void ProtocolFromModACT155()
{

   if(embSerialACT155.UsedMod())
   {
	while(embSerialACT155.UsedMod())
	{
   //			ResetWatchDog();
//			if(++ic>16) return;
			westByte = embSerialACT155.GetMod();
//#ifdef  DEBUG_TRANZIT 
	 if(GetTestMode() == 0x50)
	  printfpd(" %02X", westByte);
//#endif

			switch(westByte)
			{
			case 0x55: 
				time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgWest.Init(); break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgWest.Init(); cnt_rcv++; pkt_cnt = 0;	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
					if(mode5AWest) { embMsgWest.Add(Modify5A(westByte)); mode5AWest=0;	}
					else embMsgWest.Add(westByte);
					pkt_cnt++;
	  #ifdef  DEBUG_TRANZIT 
					if(pkt_cnt == 1)
					printfpd("(%02X)", westByte);

					if(pkt_cnt == 2)
					printfpd("(%02X)", westByte);

	  #endif			 

				}
			}

			if(embMsgWest.IsEnd())
			{
#ifdef CHECK_CRC   
  if(embMsgWest.ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
			{
// printEthLongHex(3);
	//		 recv_buff_cnt3++;
		 if(1)
  	     //151006  if(buff_cashe_modem.compare((unsigned long)embMsgWest.body[1], (unsigned long)embMsgWest.AddrS(), (unsigned long)embMsgWest.AddrI(), (unsigned long)embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485()) != 1)
   		   	{
		//151006  	 buff_cashe_modem.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485());

#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
      //  if( embMsgWest.AddrI() == 0x7766) {  printfpd("_west_ %d", tmc);}
	    if( embMsgWest.AddrI() == 0x7766) {  printfp(" _west_\n\r ");}

#endif

	  //	  if( embMsgWest.AddrI() == 0x7766) {  printfpd("\n\rr> %d ", cnt_rcv);} 



		 		if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
	   //			if(0)  //t151006
				{
					  
					  tBuffEmbMsgNorth.Add(embMsgWest);
					  tBuffEmbMsgSouth.Add(embMsgWest);
					  tBuffEmbMsgEast.Add(embMsgWest);
					  


					   /*
						// передаем побайтно дальше принимаем пакет
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
						default: embSerialACT155.AddTransit(embMsgWest.body[i]);
						}
					}
					embSerialACT155.AddTransitM(0x55);
//_______________________________add two direction

					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgWest.FullSize(); i++) 
					{
						switch(embMsgWest.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgWest.body[i]);
						}
					}
					embSerialACT155.AddUD1M(0x55);

					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgWest.FullSize(); i++) 
					{
						switch(embMsgWest.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgWest.body[i]);
						}
					}
				  embSerialACT155.AddUD2M(0x55);	
					   */
//_______________________________add_two direction
			 
				}
					
				if(embMsgWest.AddrS()==SelfID())
				{

//_____________________________________
#ifdef KSS_PRINT_LOG
      modem_ans_cnt1++;
      printfpd("\n\n\r> %d \n",modem_ans_cnt1);//ok
#endif
//_________________________________________
					embMsgWest.SetDir(1);
					rBuffEmbMsgWest.Add(embMsgWest);
#ifdef FIND_CONF_ERR
		printfp("\n\r5");
      
   for(i=0; i< embMsgWest.FullSize(); i++) 
						{
						  printfpd(".%0X",	embMsgWest.body[i]);
					   }
   
    printfp("\n\r");  
      
#endif  
			  //		embMsgWest.Init();
				}
		   //		embMsgWest.Init(); //101210
			//	recieveWest = 0;
			}	 //cashe
		     embMsgWest.Init(); //101210
		  	 recieveWest = 0;

		  } //crc
		  else
		  {

#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
      //  if( embMsgWest.AddrI() == 0x7766) {  printfp("crc_wrong _west_ ");}
	     printfp("crc_wrong _west_ ");
#endif
		    embMsgWest.Init(); //101210
		  	 recieveWest = 0;


		  }

		     embMsgWest.Init(); //151006
		  	 recieveWest = 0;


		  }	 //IsEnd

		 }	  //while
		 } //if
		 else
		 {
	  //	 printfp(".");
		 }

	//	return;  //151006 

//		if(!recieveWest)
  //		{
			if(tBuffEmbMsgWest.Used())
			{
		//	send_buff_cnt++;
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgWest.Get(embMsgA);

//#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
      //  if( embMsgWest.AddrI() == 0x7766) {  printfpd("_west_ %d", tmc);}
   //	    if( embMsgA.AddrR() == 0x7766) {  printfpd("\n\r s : %d ", countSend);}
	   
//#endif


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
				    embSerialACT155.AddModM(0x55);
				countSend++;


/*
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
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransit(0x55);

//_______________________________add two direction

					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgA.body[i]);
						}
					}


					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgA.body[i]);
						}
					}

*/
//_______________________________add_two direction

  //			}
  //		}
	}
}

void ProtocolFromTransitACT155()
{
	while(embSerialACT155.UsedTransit())
	{
 //		ResetWatchDog();
//		if(++ic>16) return;
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
#ifdef CHECK_CRC   
  if(embMsgEast.ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
		{
//printEthLongHex(4);
 //recv_buff_cnt4++;

  	      if(buff_cashe_tranzit.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
   		   	{
		  	 buff_cashe_tranzit.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485());

	
 #ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
        if( embMsgEast.AddrI() == 0x7766) {  printfp("_east_");}
#endif
	
	
	
			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{

			          tBuffEmbMsgSouth.Add(embMsgEast);
			  		  tBuffEmbMsgWest.Add(embMsgEast);
			  		  tBuffEmbMsgNorth.Add(embMsgEast);

				  /*

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
				embSerialACT155.AddModM(0x55);	
				countSend++;

//_______________________________add two direction

					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgEast.FullSize(); i++) 
					{
						switch(embMsgEast.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgEast.body[i]);
						}
					}
				   embSerialACT155.AddUD1M(0x55);	

					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgEast.FullSize(); i++) 
					{
						switch(embMsgEast.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgEast.body[i]);
						}
					}
				  embSerialACT155.AddUD2M(0x55);
					   */
//_______________________________add_two direction

			}
			
			if(embMsgEast.AddrS()==SelfID())
			{
		  //	    printEthLongHex(5);
				embMsgEast.SetDir(2);
				rBuffEmbMsgEast.Add(embMsgEast);
		//		embMsgEast.Init();
			}
	   //	  embMsgEast.Init(); //101210
	   //	 recieveEast = 0;  //101210
		 }	 // cashe
	 	 embMsgEast.Init(); //101210
	 	 recieveEast = 0;
		 } //crc
	   	}  //isend

   }   //while
 //}
	   	//		if(!recieveEast)
  //		{
	  //	   printEthLongHex(9);

			if(tBuffEmbMsgEast.Used())
			{
		//	send_buff_cnt++;
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
	//   printEthLongHex(9);
//___________________________________________
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
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransitM(0x55);


//___________________________________________

	 /*			
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
	  //				ResetWatchDog();
				}
				embSerialACT155.AddMod(0x55);
//_______________________________add two direction

					embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgA.body[i]);
						}
					}


					embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgA.body[i]);
						}
					}
					*/
//_______________________________add_two direction

   //			}	//cashe
  //		} //is end
	}//tbuff
}


void Check2InitTransitMod()
{

	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
		// Если произошло изменение ready_transit или ready_mod из "0" в "1"
		// то time3Marker = 0; под пакет 2355 байта и скорость 64К*8/11=46545
	/* not need
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
	   */

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
//______________________________________
//hier need add two direction




//______________________________________
//		if(!recieveEast)
	  //	{
				if(!embSerialACT155.UsedSendUD1()) 
				{	
					if(tBuffEmbMsgNorth.Used())
					{
			  //		send_buff_cnt++;
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgNorth.Get(embMsgA);
					
						embSerialACT155.AddUD1(0x55);
						embSerialACT155.AddUD1(0xAA);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
							case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
							case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
							case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
							default: embSerialACT155.AddUD1(embMsgA.body[i]);
							}
			   //				ResetWatchDog();
						}
						embSerialACT155.AddUD1M(0x55);
					}
				}
	 //	}

			if(!embSerialACT155.UsedSendUD2()) 
				{	
					if(tBuffEmbMsgSouth.Used())
					{
				 //	send_buff_cnt++;
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgSouth.Get(embMsgA);
					
						embSerialACT155.AddUD2(0x55);
						embSerialACT155.AddUD2(0xAA);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
							case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
							case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
							case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
							default: embSerialACT155.AddUD2(embMsgA.body[i]);
							}
			   //				ResetWatchDog();
						}
						embSerialACT155.AddUD2M(0x55);
					}
				}


	if(!embSerialACT155.UsedSendMod()) 
				{	
					if(tBuffEmbMsgEast.Used())
					{
				//	send_buff_cnt++;
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);

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
				 //		ResetWatchDog();
					}
					embSerialACT155.AddTransitM(0x55);

		   /*			
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
			   //				ResetWatchDog();
						}
						embSerialACT155.AddMod(0x55);

*/
					}
				}



//		if(!recieveWest)
	 //	{
			if(!embSerialACT155.UsedSendTransit()) 
			{	
				if(tBuffEmbMsgWest.Used())
				{
		   //		send_buff_cnt++;
					EmbMsg embMsgA;
					embMsgA.Init();
					tBuffEmbMsgWest.Get(embMsgA);

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
			   //				ResetWatchDog();
						}
						embSerialACT155.AddModM(0x55);


/*
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
				 //		ResetWatchDog();
					}
					embSerialACT155.AddTransit(0x55);
					*/
				}
			}
	 //	}

}


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
// AKTIV
unsigned char	a22[] =	{ 0x02 };  // AKTIV mode -- разговорное состояние
unsigned char	a221[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a222[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x11, 0x04); // off hook
// PAUSE
unsigned char	a26[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a261[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a262[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x11, 0x04); // off hook
// PAUSE 2
unsigned char	a263[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a264[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a265[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x11, 0x00); // off hook
// RING
unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- выдача звонка
unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x11, 0x00); // оn hook
// WAIT
unsigned char	a28[] =	{ 0x07 }; // power dnv mode -- ожидание поднятия трубки
//outportb(0x11, 0x00); // on hook
unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 

void InitTLF()
{
	int i;

// сброс кодека
	for(i=0; i<15; i++) outportb(0x11, 0x08); 
	outportb(0x11, 0x00);
	for(i=0; i<10000; i++);

	outportb(0x10, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x0F, ab1[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab1); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x0F, ab2[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab2); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x0F, ab3[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab3); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x0F, ab4[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab4); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x0F, ab5[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab5); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x0F, ab6[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab6); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x0F, ab7[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab7); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x0F, ab8[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab8); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x0F, ab9[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab9); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x0F, ab10[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab10); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x0F, ab11[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab11); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x0F, ab12[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab12); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x0F, ab13[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab13); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x0F, ab14[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab14); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x0F, ab15[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab15); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x0F, ab16[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab16); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x0F, ab17[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab17); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x0F, ab18[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab18); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x0F, ab19[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab19); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x0F, ab20[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab20); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x0F, ab21[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab21); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab22); i++) outportb(0x0F, ab22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab23); i++) outportb(0x0F, ab23[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab23); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab24); i++) outportb(0x0F, ab24[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab24); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab25); i++) outportb(0x0F, ab25[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab25); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab26); i++) outportb(0x0F, ab26[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab26); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab27); i++) outportb(0x0F, ab27[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab27); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab28); i++) outportb(0x0F, ab28[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab28); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab29); i++) outportb(0x0F, ab29[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab29); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab30); i++) outportb(0x0F, ab30[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab30); i++);
}

void Ring()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x0F, a272[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a272); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x0F, a271[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a271); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x0F, a27[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a27); i++);
  outportb(0x11, 0x00); // оn hook
}
void Active()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x0F, a221[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x0F, a222[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a222); i++);
	outportb(0x11, 0x04); // off hook
}
void Pause()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x0F, a26[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a26); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a261); i++) outportb(0x0F, a261[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a261); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a262); i++) outportb(0x0F, a262[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a262); i++);
	outportb(0x11, 0x04); // off hook
}
void Pause2()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a263); i++) outportb(0x0F, a263[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a263); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a264); i++) outportb(0x0F, a264[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a264); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a265); i++) outportb(0x0F, a265[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a265); i++);
	outportb(0x11, 0x00); // off hook
}

void Wait()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x0F, a221[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x0F, a222[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a222); i++);
//	outportb(0x10, 0x02); for(i=0; i<sizeof(a28); i++) outportb(0x0F, a28[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a28); i++);
	outportb(0x11, 0x00); // on hook
}

void Read()
{
// Пример  передачи/приема по SPI
// outportb(0x10, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x0F, ab1[i]); outportb(0x10, 0x01);
// while((inportb(0x10) & 0x01)!=0);
// чтение принятых байтов  по адресу  0x50F принимается столько же байт сколько и  передается
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(aa); i++) outportb(0x0F, aa[i]); outportb(0x10, 0x01); inportb(0x10); for(i=0; i<200*sizeof(aa); i++);
	for(i=0; i<7; i++) aaa[i] = inportb(0x0F);
	
}



void SaveFile()
{
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>						ul2uc.uc[0] = embMsg.Body(0);
	ul2uc.uc[0] = embMsgRequest->Body(0);
	ul2uc.uc[1] = embMsgRequest->Body(1);
	ul2uc.uc[2] = embMsgRequest->Body(2);
	ul2uc.uc[3] = embMsgRequest->Body(3);
  //	addrRAM = (unsigned char far *)ul2uc.ul;
//t	addrRAM = (unsigned char *)ul2uc.ul;
   	addrRAM = (unsigned char *)(NVRAM_BASE);

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

	if(ui2uc.ui==temp_crc) for(i=0; i<len; i++) *(addrRAM+i+shift)= embMsgRequest->Body(i+8);
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
}


#define PARAMETERS_DISPLACEMENT  (0x1000)
#define PARAMETERS_DISPLACEMENT1 (0x1100)


extern "C" void SavePortsFromNVRAM()
{
	unsigned char  *bt;
 	bt = (unsigned char *)(NVRAM_BASE);

	outportb(0x01 ,*(bt + PARAMETERS_DISPLACEMENT + 0x1));
	outportb(0x02 ,*(bt + PARAMETERS_DISPLACEMENT + 0x2));
	outportb(0x03 ,*(bt + PARAMETERS_DISPLACEMENT + 0x3));

	outportb(0x12 ,*(bt + PARAMETERS_DISPLACEMENT + 0x12));
	outportb(0x13 ,*(bt + PARAMETERS_DISPLACEMENT + 0x13));
	outportb(0x14 ,*(bt + PARAMETERS_DISPLACEMENT + 0x14));
	outportb(0x15 ,*(bt + PARAMETERS_DISPLACEMENT + 0x15));

	outportb(0x20 ,*(bt + PARAMETERS_DISPLACEMENT + 0x20));
	outportb(0x21 ,*(bt + PARAMETERS_DISPLACEMENT + 0x21));
	outportb(0x22 ,*(bt + PARAMETERS_DISPLACEMENT + 0x22));
	outportb(0x23 ,*(bt + PARAMETERS_DISPLACEMENT + 0x23));
	outportb(0x24 ,*(bt + PARAMETERS_DISPLACEMENT + 0x24));
	outportb(0x25 ,*(bt + PARAMETERS_DISPLACEMENT + 0x25));
	/*
#ifdef PROG_PU_M_MUX
	 outportb3(0x37 ,*(bt + PARAMETERS_DISPLACEMENT1 + 0x37));
	 for(long i = 0; i < 0x10; i++)
	 {
	  outportb3((0x90 + i) ,*(bt + PARAMETERS_DISPLACEMENT1 + 0x90 + i));
	 }
#endif //PROG_PU_M_MUX
  */
}

extern "C" void SaveParameterToNVRAM(unsigned long current_port, unsigned char parameter)
{
  unsigned char  *bt;
  bt = (unsigned char *)(NVRAM_BASE);
//110912  if((current_port >= 0x501) && (current_port <= 0x525))
  if((current_port >= 0x1) && (current_port <= 0x25))
  {
 //  printEthLongHex(parameter);
//110912	*(bt + PARAMETERS_DISPLACEMENT + (current_port - 0x500)) = parameter;
	*(bt + PARAMETERS_DISPLACEMENT + (current_port)) = parameter;
  }
}

							  


void WritePort()
{
	if((embMsgRequest->Body(1)&0xC0)==0x80)
	{
		embMsg485Request_1.Init();
		embMsg485Request_1.SetAddr(0);//0x01);
		embMsg485Request_1.SetLength(4);//4
		embMsg485Request_1.SetBody(0,0x07);
		embMsg485Request_1.SetBody(1,embMsgRequest->Body(0));
		embMsg485Request_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
		embMsg485Request_1.SetBody(3,embMsgRequest->Body(4));
		embMsg485Request_1.CalcCRC();
		embMsg485Request_1.SetReadyToSend();
	}
	else
	{
		if((embMsgRequest->Body(1)&0xC0)==0xC0)
		{
			embMsg485Request_2.Init();
			embMsg485Request_2.SetAddr(0);//0x02);
			embMsg485Request_2.SetLength(4);//4
			embMsg485Request_2.SetBody(0,0x07);
			embMsg485Request_2.SetBody(1,embMsgRequest->Body(0));
			embMsg485Request_2.SetBody(2,embMsgRequest->Body(1)&0x3F);
			embMsg485Request_2.SetBody(3,embMsgRequest->Body(4));
			embMsg485Request_2.CalcCRC();
			embMsg485Request_2.SetReadyToSend();
		}
		else
		{
			outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
			SaveParameterToNVRAM(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8) , embMsgRequest->Body(4));
			embMsgAns.SetType(0x0A);
			embMsgAns.SetBody(0,embMsgRequest->Body(0));
			embMsgAns.SetBody(1,embMsgRequest->Body(1));
			embMsgAns.SetBody(2,0);
			embMsgAns.SetBody(3,8);
			embMsgAns.SetBody(4,embMsgRequest->Body(4));
			embMsgAns.SetLength(5);
		}
	}
}

void ReadPort()
{

  //	 printEthLongHex(embMsgRequest->Body(1));
 //	embMsgRequest->Body(0)
 //	if((embMsg.Body(1)&0xC0)==0x80)
	if((embMsgRequest->Body(1)&0xC0)==0x80)
	{

  //	printEthLongHex(0x80);

		embMsg485Request_1.Init();
		embMsg485Request_1.SetAddr(0);//0x01);
		embMsg485Request_1.SetLength(3); //3
		embMsg485Request_1.SetBody(0,0x08);
		embMsg485Request_1.SetBody(1,embMsgRequest->Body(0));
		embMsg485Request_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
		embMsg485Request_1.CalcCRC();
		embMsg485Request_1.SetReadyToSend();
	}
	else
	{
		if((embMsgRequest->Body(1)&0xC0)==0xC0)
		{
			embMsg485Request_2.Init();
			embMsg485Request_2.SetAddr(0);//0x02);
			embMsg485Request_2.SetLength(3);//3
			embMsg485Request_2.SetBody(0,0x08);
			embMsg485Request_2.SetBody(1,embMsgRequest->Body(0));
			embMsg485Request_2.SetBody(2,embMsgRequest->Body(1)&0x3F);
			embMsg485Request_2.CalcCRC();
			embMsg485Request_2.SetReadyToSend();
		}
		else
		{
			inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
			embMsgAns.SetType(0x0B);
			embMsgAns.SetBody(0,embMsgRequest->Body(0));
			embMsgAns.SetBody(1,embMsgRequest->Body(1));
			embMsgAns.SetBody(2,0);
			embMsgAns.SetBody(3,8);
			embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
			embMsgAns.SetLength(5);
		}
	}
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//void main()

int rrr=0;
unsigned countUD1=0;
unsigned countUD2=0;

unsigned long ErrResSNMP;
unsigned char start_count;

/*
#ifdef USE_USART2
EmbRS232 embRS232S;
EmbMsg embMsg232S;
unsigned char mode5AS;
#endif // USE_USART2
 */

#ifdef USE_USART2
struct StateDev
{
   unsigned char byte[DEV_INFO_SIZE];
};

StateDev statedev[DEVCONFIG_QUANTITY];
EmbRS232 embRS232S;

#ifndef CHANGE_USART12
EmbMsg485 embMsg232S;
#else
EmbMsg embMsg232S;
#endif


unsigned char mode5AS;
unsigned long time1old232S;
EmbMsg485 embMsg485RequestS;
unsigned char cur_ans_pointer;
unsigned char cur_rem_pointer;

unsigned char devans[DEVCONFIG_QUANTITY];
unsigned char devstate[DEVCONFIG_QUANTITY];
unsigned char ss;
unsigned char cur_req_pointer;
unsigned char cur_req_addr;

#endif // USE_USART2





//extern "C" void Init_COMMUTATOR(void)
unsigned long time1old485;
unsigned long keep_ans;
unsigned long keep_is485;
unsigned long keep_addri;
unsigned long keep_addrs; 
unsigned long keep_addrr;   
unsigned long keep_flagrequest; 
	 
unsigned long usart0_request_cnt; 
unsigned long usart0_ans_cnt; 
unsigned long usart0_ans1_cnt; 
unsigned long usart0_ans11_cnt;
unsigned long usart0_s_req_ant;
 /*
unsigned long send_buff_cnt;
unsigned long recv_buff_cnt1;
unsigned long recv_buff_cnt2;
unsigned long recv_buff_cnt3;
unsigned long recv_buff_cnt4;
 */

		 
#ifdef KSS_PRINT_LOG

unsigned long modem_req_cnt;





unsigned long modem_ans_cnt1;
unsigned long modem_ans_cnt2;
unsigned long modem_ans_cnt3;
unsigned long modem_ans_cnt4;

unsigned long ups_req_cnt;
unsigned long ups_ans_cnt;


#endif

#define NORMA_LED (0x4)
#define LED_PORT  (0x4)

extern "C" void SetLEDs(unsigned char byte)
{
 outportb(LED_PORT, byte);
}

AMsgBuffer amsgbuffer;
AMsg amsgr, amsgt;
unsigned pamsgr;
unsigned char used_TCP;

#ifdef DEBUG_TRANZIT
unsigned long mreqr,mreqt,mansr, manst;
#endif

unsigned char hot_restart;

unsigned char NeedWriteID;

//unsigned long cnt_rcv;

extern "C" void Init_PU_M(void)
{
tmc = 0;
cnt_rcv = 0;

NeedWriteID = 0; //130917

#ifdef FIND_KSS_ERR
return;
#endif


#ifdef DEBUG_TRANZIT
 mreqr = mreqt = mansr = manst = 0;
#endif

 used_TCP = 0;
 amsgbuffer.Init();

 keep_ans = 0;
 keep_is485 = 0;
 keep_addri = 0;
 keep_addrs = 0; 
 keep_addrr = 0;   
 keep_flagrequest = 0; 
 
 usart0_request_cnt = 0;
 usart0_ans_cnt = 0;
 usart0_ans1_cnt = 0;
 usart0_ans11_cnt = 0;
  usart0_s_req_ant = 0;
	
  /*
send_buff_cnt = 0;
recv_buff_cnt1 = 0;
recv_buff_cnt2 = 0;
recv_buff_cnt3 = 0;
recv_buff_cnt4 = 0;
   */

#ifdef KSS_PRINT_LOG

modem_req_cnt = 0;
modem_ans_cnt1 = 0;
modem_ans_cnt2 = 0;
modem_ans_cnt3 = 0;
modem_ans_cnt4 = 0;

#endif 




time1old485 = 0;
 flag_ust_recv = 0;
/*
 numa[0] = '0';
 numa[1] = '0';
 numa[2] = '0';
 numb[0] = '0';
 numb[1] = '0';
 numb[2] = '0';
 numc[0] = '0';
 numc[1] = '0';
 numc[2] = '0';
 */

//_________________________________________north_south
//need init!!!!!!!!!!!!!!!!


 tBuffEmbMsgNorth.Init();
 embMsgNorth.Init();
 markerNorth=0;  ready_up1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 old_ready_up1=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 delete_msgNorth=0; recieveNorth=0;
 northByte = 0; 
 time3BlankUp1 = 0;

 

 tBuffEmbMsgSouth.Init();
 embMsgSouth.Init();
 markerSouth=0;  ready_up2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 old_ready_up2=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 delete_msgSouth=0; recieveSouth=0;
 southByte = 0;
 time3BlankUp2 = 0;

rBuffEmbMsgWest.Init();
rBuffEmbMsgEast.Init();
rBuffEmbMsgNorth.Init();
rBuffEmbMsgSouth.Init();

rBuffEmbMsg232.Init();



//_________________________________________






buff_cashe_modem.init();
 buff_cashe_tranzit.init();
// buff_cashe_request.init();
 buff_cashe_up1.init();
 buff_cashe_up2.init();



#ifdef RS485_MSG_BUFF
	   tBuffRS485.Init();
	   time_lastsend_rs485 = 0;
	   flag_wait_rs485 = 0;
#endif //RS485_MSG_BUFF

	/*
#ifdef USE_RS125
 parse_status = 0l;
 rs125_send_timer = 0l;
for(im = 0; im < PERIOD_OF_KEEP; im++)
{
 oct_res_sub[im] = 0;
 oct_tr_sub[im] = 0;
 oct_res_ser[im] = 0;
 oct_tr_ser[im] = 0;
 }

// cnt_oct_res_sub = 0;
// cnt_oct_tr_sub = 0;
// cnt_oct_res_ser = 0;
// cnt_oct_tr_ser = 0;
#endif //
  */

ErrResSNMP = 0l;
start_count = 0;
//_______________________________________________
 mode5A232E = 0;
 mode5A485E = 0;
 mode5A485 = 0;
//________________________________________________
 flagRequest=0;
 serr=0xFF;
 crc_temp=0;
 i=0;
 time1old=0;
 time2old=0;
 request1=0;
 request2=0;
 time3Marker=0;
 time3BlankTransit=0;
 time3BlankMod=0;
 flag_start_power = 0;
 markerWest=0;
 markerEast=0;
 ready_transit=0;
 ready_mod=0;
 dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 old_ready_transit=0;
 old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
 delete_msgWest=0;
 delete_msgEast=0;
 recieveWest=0;
 recieveEast=0;
 countSend=0;
 countRecv=0;
 time3highID=0;
 mode5A=0;
 mode5AWest=0;
 mode5AUp1=0;
 mode5AAnt=0;
 mode5AUp2=0;
 mode5AEast=0; 
 cycle=0;
 i232=0;
 iTrans=0;
 iMod=0;
 ans1=0;
 ans2=0;
 addr485=0;

 tlf_counter=0;
 tlf_state=0;
 presto = 0;
 ring_counter = 0;
 presto_time =0;
 wait_time =0;
 presto_ring =0;


//________________________________________________

AsciiInit();
EmbInit();	 //embrs232 embrs485
//_________________________________________________
  
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
   ab20[0] = 0x45;ab20[1] =0x98;ab20[2] =0x00;ab20[3] =0x00;ab20[4] =0x00;ab20[5] =0x00;ab20[6] =0x00;ab20[7] =0x00;ab20[8] =0x00;ab20[9] =0x00;  // Rese20[8] =0x00;ab20[9] =0x00;  // Rese30;ab21[2] =0xBE;ab21[3] =0x04;ab21[4] =0xB0;ab21[5] =0x27; // AX-Filter -строка 29
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
//outportb(0x11;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE
   a26[0] =	0x02; // RING pause MODE -- генерация КПВ
   a261[0] = 0x44;a261[1] =0x1c;a261[2] =0xAA; // LMCR1
   a262[0] = 0x44;a262[1] =0x1A;a262[2] =0x05; // dscr
//outportb(0x11;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE 2
   a263[0] = 0x02; // RING pause MODE -- генерация КПВ
   a264[0] = 0x44;a264[1] =0x1c;a264[2] =0xAA; // LMCR1
   a265[0] = 0x44;a265[1] =0x1A;a265[2] =0x05; // dscr
//outportb(0x11;ab6[0] = 0x00);ab6[0] = // off hook
// RING
   a272[0] = 0x05; // RING burst MODE -- выдача звонка
   a271[0] = 0x44;a271[1] =0x1c;a271[2] =0x22;  // LMCR1
   a27[0] =	 0x44;a27[1] =0x1A;a27[2] =0x00; // dscr
//outportb(0x11;ab6[0] = 0x00);ab6[0] = // оn hook
// WAIT
   a28[0] = 0x07; // power dnv mode -- ожидание поднятия трубки
//outportb(0x11;ab6[0] = 0x00);ab6[0] = // on hook
   aa[0] =  0xC4;aa[1] =0x07;aa[2] =0xFF;aa[3] =0x00;aa[4] =0x00;aa[5] =0x00;aa[6] =0x00; 
//_____________________________________________




//__________________________________________________<< init _tlf

//void InitMain()
//{

	unEmb2NetStat.emb2NetStat.allPacketRecv=0;	// +
	unEmb2NetStat.emb2NetStat.genMarker=0;			// +
	unEmb2NetStat.emb2NetStat.highID=0;         // +
	unEmb2NetStat.emb2NetStat.requestMarker=0;  // +
	unEmb2NetStat.emb2NetStat.selfPacketRecv=0; // +
	unEmb2NetStat.emb2NetStat.selfPacketSend=0; // +

	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=0;
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;

	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;  //add suppourt protocol	rs232 from ethernet protocol 888
  //	unEmb2TypeVer.emb2TypeVer.type       = 0x0010;
	unEmb2TypeVer.emb2TypeVer.type       = 0x0404;
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();

	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}

  /*
	unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = inportb(0x01);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = inportb(0x02);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x14);
 */

		SavePortsFromNVRAM();

//___________________________________________________________________________
		unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = inportb(0x01);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = inportb(0x02);
//		unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x14);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x03);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = inportb(0x12);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = inportb(0x13);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = inportb(0x14);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = inportb(0x15);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = 0;//inportb(0x07); // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[8] = 0;//inportb(0x08); // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[9] = 0; // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[10] = inportb(0x20);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[11] = inportb(0x21);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = inportb(0x22);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = inportb(0x23);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[14] = inportb(0x24);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[15] = inportb(0x25);
//_____________________________________________________________________________


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
//}

//__________________________________________________





 //port!!!!!	outport(0xFFA4, 0x0077);
//	outportb(0x6FF,inportb(0x6FF)|0x10);
//port	unsigned countUD1=0;
//port	unsigned countUD2=0;

 countUD1=0;	//port
 countUD2=0;   //port

///////  Канал транзит  ///////
///////////////////////////////

	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
 //	rBuffEmbMsg.Init();
 //	embMsgTemp.Init();
	embSerialACT155.Init();

//--------------------------------------------------  >> add  init
 //not need init	EmbTimerCallback embTimerCallback0;

//ok 	EmbMsgBuffer rBuffEmbMsg;	
//ok	EmbMsgBuffer tBuffEmbMsgWest;
//ok	EmbMsgBuffer tBuffEmbMsgEast;
//ok    EmbSerialPU_M embSerialACT155;


	 embMsg.Init();
     embMsgWest.Init();
	 embMsgEast.Init();
	 embMsgAns.Init();
 //	EmbMsg embMsgTemp;
     embMsg485.Init();	 //added 090406
	 embMsg232.Init();	 //added 090406
	 embMsg232E.Init();	 //added 090406
	 embMsg485E.Init();	  //added 090406


	embMsg485_1.Init();
    embMsg485_2.Init();
    embMsg485Request_1.Init();
	embMsg485Request_2.Init();

//ok in embinit	EmbRS232 embRS232;
//ok in embinit EmbRS485 embRS485;
	
  
 //-------------------------------------------------	<< add




  //	ResetWatchDog();
//	embIndicator.Init();
//	embSerialACT155.Init();
  

//090406 this maked in embinit	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

///////////////////////////////////////////////////////////////////////////////
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
//////////////////////
	InitTLF();
//	Ring();
	for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
	tlf_counter=0;


	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}
//// Загрузка телефонного кодека ////
	for(i=0; i<9; i++) powerInFar[i]=0;

   //port	int rrr=0;
	rrr=0; //port

///////  Включаем канал транзит 0x95 - 0x00  ///////
///////  "конец" 0x95 - 0x01
////////////////////////////////////////////////
   //	Enable(); // Разрешаем все прерывания
	send1[0]=12;
	send2[0]=12;

   
	time3Marker = time3;

	unStateRRL.stateRRL.ver = 0x01;
	unStateRRL.stateRRL.state = 0x01;

	Wait();
//	Ring();
//	Pause();
	presto_time = time1;


 //port 	InitMain();
// 526-527	Счётчик ошибок после комбинатора	16 бит
// 528-52A	Счётчик ошибок, исправленных РС в 1 стволе	24 бит
// 52B-52D	Счётчик ошибок, исправленных РС в 2 стволе	24 бит
// 52E-52F	Счётчик ошибок не исправленных РС в 1 стволе	16 бит
// 530-531	Счётчик ошибок не исправленных РС в 2 стволе	16 бит
// 532-533	Счётчик числа принятых пакетов	16 бит
	count_no_correct_result = (unsigned)inportb(0x26) + ((unsigned)inportb(0x27)<<8);	
	count_block = (unsigned)inportb(0x32) + ((unsigned)inportb(0x33)<<8);
	count_notRS1 = (unsigned)inportb(0x2E) + ((unsigned)inportb(0x2F)<<8);
	count_notRS2 = (unsigned)inportb(0x30) + ((unsigned)inportb(0x31)<<8); 
	count_no_correct_block1 = (unsigned)inportb(0x28) + ((unsigned)inportb(0x29)<<8) + ((unsigned)inportb(0x2A)<<16);
	count_no_correct_block2 = (unsigned)inportb(0x2B) + ((unsigned)inportb(0x2C)<<8) + ((unsigned)inportb(0x2D)<<16);

	unStatePUM.statePUM.ver = 0x01;
	unStatePUM.statePUM.reserv = 0x20;

// Порт 0х501 Тип Бит		
//1	"0" - с MUX;  "1" - нет MUX	Наличие мультиплексора
//2		
//3		
//4		
//5	"1" - 2М, "2" - 4М, "3" - 8М, "4" - 17М, "5" - 34М	Скорость потока
//6		
//7		
//8	


#ifdef USE_USART2
 ss=0;
cur_req_pointer = 0;

 mode5AS = 0;
 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 31, AT91RM9200_PIO_PERIPHERAL_B, 0); 
//#ifdef FIND_KSS_ERR
//return;
//#endif
#ifndef MAKET_PLATA	
 Set_Usart2_To_RS485();
#endif

 time1old232S = 0l;
 embMsg485RequestS.Init();
for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
  devans[in] = 0;
  devstate[in] = 0;
   for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
  }


#endif // USE_USART2

if(MirrorTest()) {SetLEDs(NORMA_LED);}
else {SetLEDs(0);}

} //add this


//extern "C" void COMMUTATOR(void)


#define	USTIR_SEND_TIMEOUT (100)
 /*
extern "C" void CallUstir()
{
static unsigned long send_timer;

if (send_timer > time1)
{
  send_timer =  time1;
}

  if ((time1 - send_timer) > USTIR_SEND_TIMEOUT)
{
  send_timer =  time1;
#ifdef TEST_PRINT_USTIR
 printfp("\n\r Ustir");
#endif

  Ustir();	  //hier is operated antenna
}

}
	*/

//#define PERIOD_REQ_ANTENNA	45
#define PERIOD_REQ_ANTENNA	50

extern "C" void CallUstir2()
{
static unsigned long timepasing;
if(timepasing > time1 )	 timepasing = time1;

if((time1 - timepasing) > PERIOD_REQ_ANTENNA)
{
 timepasing = time1;
 /*
if(send_command)
	{
        usart0_s_req_ant++;
        printfpd("\n\n\rs_req_ant> %d \n",usart0_s_req_ant);//ok

   //	printEthLongHex(command_str[0])
   //		StrToPdcTu1(0,command_str); // послать полученную по команде 0x53 поледовательность to USART1 
	  if((command_str[0] + 1) < STR_UST_LEN)
	   for(unsigned i = 1; i < command_str[0] + 1; i++)
	   {
	   ToPdcTu1(command_str[i]);
	   }
	  
	  send_command=0;
	}

*/
  if(amsgbuffer.Used())
  {
  	amsgbuffer.Get(amsgt);

  //23	 usart0_s_req_ant++;
   //23  printfpd("\n\n\rsend_to_ant> %d \n",usart0_s_req_ant);//ok
        keep_is485 = amsgt.body[0];
        keep_addri = (amsgt.body[1] <<8) + amsgt.body[2];
        keep_addrs = (amsgt.body[3] <<8) + amsgt.body[4];
        keep_addrr = (amsgt.body[5] <<8) + amsgt.body[6];  

		keep_flagrequest = amsgt.body[7];
   //	  if((amsgt.body[0] + 1) < STR_UST_LEN)
	  if((amsgt.body[8] + 1) < STR_UST_LEN)
		{
    //23    printfp("\n\n\r ans : ");

   //	   for(unsigned i = 1; i < command_str[0] + 1; i++)
	   for(unsigned i = 9; i < amsgt.body[8] + 9; i++)
	   {
	   ToPdcTu1(amsgt.body[i]);
   //23	      printfpd(" %02X", amsgt.body[i]);

	   }
	   keep_ans = 2; //first answer is request
	   }
  }


}


}


#define PERIOD_TEST_PARSING (500l)

extern "C" void PU_M(void)
	{


#ifdef FIND_KSS_ERR
return;
#endif

//tmc = 0;

	long err_tmp_now = 0l;
	static long err_tmp_prev1 = 0l;
	static long err_tmp_prev3 = 0l;
    static long err_tmp_prev4 = 0l;

//#ifdef TEST_PARSING_COMMANDS
static unsigned long timepasing;
static unsigned char count1;


#ifndef TEMPORARY_DO_NOT_STOP_RECEIVE

 
static unsigned char maskcnt;

if(maskcnt)
{
//MaskReceive();
embSerialACT155.ChangeReceive1();
maskcnt = 0;
}
else
{
//UnMaskReceive();
embSerialACT155.ChangeReceive2();
maskcnt = 1;
}

#endif



 /* 
count1++;
if(!(count1%1000))
{
 printfpd("\n\r%d", time1);
//  printfp(".");
//  printfp1("*");

}
   */
if(timepasing > time1 )	 timepasing = time1;

if((time1 - timepasing) > PERIOD_TEST_PARSING)
{
 timepasing = time1;
   //   embRS232S.Trans2(count1++);
   //	embRS232S.Trans2('1');
   //	embRS232S.Trans2('2');
   //  TestParsing();
 //   ToPdcTu1('1');
 //	 ToPdcTu1('2');


}

//#endif
 if(GetNeedWriteDevId())
   {
	   //	   printf("\n\r Write!!"); //t
			 WriteDevId();
			 ClearNeedWriteDevId();
   }


//120730 CallUstir();

		 CallUstir2();	 //for commutator2

		unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = inportb(0x01);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = inportb(0x02);
//		unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x14);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = inportb(0x03);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = inportb(0x12);

		unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = inportb(0x13);

		unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = inportb(0x14);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = inportb(0x15);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = 0;//inportb(0x07); // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[8] = 0;//inportb(0x08); // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[9] = 0; // reserv
		unEmb2TypeVer.emb2TypeVer.signature_hardware[10] = inportb(0x20);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[11] = inportb(0x21);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = inportb(0x22);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = inportb(0x23);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[14] = inportb(0x24);
		unEmb2TypeVer.emb2TypeVer.signature_hardware[15] = inportb(0x25);
		
//_____________________________________________________________________________
			

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
	
//}

		if(time1 - wait_time >= 40) 
		{
			wait_time = time1;
			Read();
		if(aaa[3]&0x40) 
		{
			if(tlf_state) 
			{
				Active();
				tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0;
			}
			tlf_state = 0;
		}
		else 
		{
			if(!tlf_state)
			{
				Wait();
				tlf_state=1;
			}
			if((aaa[3]&0x80)&&(aaa[5]&0x80))
			{
//	unsigned char tlf_number[4];
//	unsigned char tlf_counter=0;
//					Ring();
				switch(aaa[5]&0xFC)
				{
					case 196: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 1; break;
					case 200: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 2; break;
					case 204: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 3; break;
					case 208: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 4; break;
					case 212: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 5; break;
					case 216: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 6; break;
					case 220: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 7; break;
					case 224: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 8; break;
					case 228: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 9; break;
					case 232: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 0; break;
					case 236: tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0; break;
					default: tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0; break;
				}

			unStateBMD155.stateBMD155.loopPI = tlf_number[0];
			unStateBMD155.stateBMD155.demPI = (unsigned)tlf_number[1]*10+(unsigned)tlf_number[0];
			unStateBMD155.stateBMD155.statePI = tlf_number[1];

			unsigned char * nbase = (unsigned char *)(NVRAM_BASE);


				if(tlf_counter>=2) 
				{
//		if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == unEmb2TypeVer.emb2TypeVer.signature_software[1]) // = self_tlf_number
			if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == (*(nbase + 1))) // = self_tlf_number
					{
						presto = 1;
						presto_time = 0;
						presto_ring = 0;
						ring_counter = 0;
					}
					else
					{
						if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == 99) 
						{
							presto = 2;
							presto_time = 0;
							presto_ring = 0;
							ring_counter = 0;
						}
					}
					for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
					tlf_counter=0;
				}
			}

			if(presto)
			{
				if((!presto_ring)&&(time1-presto_time>2000))
				{
					presto_ring = 1;
					presto_time = time1;
					ring_counter++;
					if(ring_counter>7) 
					{
						presto=0;
						presto_ring = 0;
						presto_time = 0;
						Wait();
					}
				}
				else
				{
					if(time1-presto_time<1400) 
					{
						Ring();
					}
					else 
					{
						presto_ring = 0;
						if(presto==1) Pause();
						else Pause2();
					}
				}
			}
		}

		}
		rrr++;		
	 //	ResetWatchDog();

	//	unsigned eee;


//////////////////////////////////////////////////
		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;

old_ready_up1=ready_up1;
old_ready_up2=ready_up2;
//////////////////////////////////////////////////
 
//#ifdef FULL_TEST_TRANZIT
//if(GetTestMode() != 2)
//{
//#endif
  		Check2InitTransitMod();	
			
		ProtocolFromModACT155();
		 
		ProtocolFromTransitACT155();

		ProtocolFromUD1ACT155();
		ProtocolFromUD2ACT155();
		 
  
//////////////////////////////////////////////////
		i232=0;


 
// #include checkremotemod.inc
 #include checkremotecommut.c



// #include answermod.inc
// #include answerpum.inc
 #include answercommut.c
   	 
#ifdef USE_USART2
#ifndef CHANGE_USART12
 Remote_PRM_PCHS();
#else
 Remote_PRM_PCHF();
#endif
#endif
   	 
	}
//}

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

//_____________________________________________________________________________
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




void StartTestTlf()
{
// unsigned char j, aa_loc, aa1, aa2, aa3, code;
 unsigned int i;//,z,  merc, zerc,up0erc,up1erc, w;
 

  //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
 //	Enable(); // Разрешаем все прерывания
// сброс кодека
for(i=0; i<15; i++) outportb(0x11, 0x08);
outportb(0x11, 0x00);
t2ms(1);

//ScreenSetBuffer();
//ScreenAddString("test TLF----e");
//ScreenIntSent();
 //printf("\n\r test TLF----e\n\r");

//while(1)
//{
//outportb(0x10, 0x02); for(i=0; i<sizeof(an); i++) outportb(0x0F, an[i]); outportb(0x10, 0x01); while((inportb(0x10) & 0x01)!=0);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
//}

   // INIT кодека
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x0F, ab1[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x0F, ab2[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x0F, ab3[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x0F, ab4[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x0F, ab5[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x0F, ab6[i]); outportb(0x10, 0x01); //for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x0F, ab7[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x0F, ab8[i]); outportb(0x10, 0x01); //for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x0F, ab9[i]); outportb(0x10, 0x01); //for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x0F, ab10[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x0F, ab11[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x0F, ab12[i]); outportb(0x10, 0x01); //for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x0F, ab13[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x0F, ab14[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x0F, ab15[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x0F, ab16[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x0F, ab17[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x0F, ab18[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x0F, ab19[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x0F, ab20[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);

outportb(0x10, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x0F, ab21[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);


	outportb(0x10, 0x02); for(i=0; i<sizeof(a14); i++) outportb(0x0F, a14[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a15); i++) outportb(0x0F, a15[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a16); i++) outportb(0x0F, a16[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a17); i++) outportb(0x0F, a17[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a18); i++) outportb(0x0F, a18[i]); outportb(0x10, 0x01); //for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a19); i++) outportb(0x0F, a19[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a20); i++) outportb(0x0F, a20[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a21); i++) outportb(0x0F, a21[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);

outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
outportb(0x10, 0x02); for(i=0; i<sizeof(a23); i++) outportb(0x0F, a23[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);


outportb(0x11, 0x04); // 0);


outportb(0x11, 0x04); // r(i=0; i<sizeof(a26); i++) outportb(0x0F, a26[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);




//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

	
/*
	outportb(0x10, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x0F, a27[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x0F, a271[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x0F, a272[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
*/

//t2ms(1000);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);




}
//while(1)
void TestTlf()
	{

  unsigned char  aa_loc, aa1, aa2, aa3, code;
  unsigned int i;

t2ms(2);

// прием символа  режим звонка

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
         
	
outportb(0x10, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x0F, ac[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
 
 while((inportb(0x10) & 0x01)!=0);

aa_loc = inportb(0x0f);
aa_loc=inportb(0x0f);
aa_loc=inportb(0x0f);
aa1=inportb(0x0f);
aa2=inportb(0x0f);
aa3=inportb(0x0f);
aa_loc =inportb(0x0f);

//if ((aa3 & 0x80)!=0)
//if ((aa1 & 0x40)!=0)
 //{ 
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

#ifndef USART0_TRY_PDC_1T
printf("\r %d %d %d %d %d = %c \r\n", aa1, aa2, aa3, aa_loc, aa_loc, code);
#else
printfp("\r");
printfpd("%d",aa1);
printfpd("%d",aa2);
printfpd("%d",aa3);
printfpd("%d",aa_loc);
printfp(" = ");
printfpd("%c",code);
printfp("\r\n");
OperateBuffers_usart0t();

#endif

}
//tt2ms(100);
t2ms(10);

// }

	//}

	//ScreenAddString(" exit to monitor");
	//ScreenIntSent();
//  asm { db 0fah, 0eah ,00h, 0ah, 00h, 27h ;}  // -- exit to monitor

}

extern "C" void test_PU37_start()
{
 unsigned char  n, i;

 //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
//	Enable(); // Разрешаем все прерывания

	// BUS TEST 
	 
	outportb(0x00, i);
	if (i != ( inportb(0x00)) ) 
			{
   //		   		ScreenAddString("BUS test  err");
#ifndef USART0_TRY_PDC_1T
			  printf("\n\rBUS test  err");
#else
		     printfp("\n\rBUS test  err");
#endif


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
   n=inportb(0x07);
   n=inportb(0x0B);
   n=inportb(0x0d);
   n=inportb(0x09);
  }

   outport(0x506,0x55); // разрешаем прерывания на прием
// outport(0x506,0xff);
}
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//while(1)


 unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1;     
  unsigned int   merc, zerc,up0erc,up1erc;
  unsigned char rup0, rup0o,  rup1, rup1o;
//  unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;


void test_PU37_interrupt_ovner()
{

 //unsigned int tmp =  (unsigned int)INT0_FLAG;
   //t      while (IntFlag & tmp)
   //     if(IntFlag & tmp)
   //	 if(1)
	 //	{
	   //	  IntFlag &=  ~tmp;
		//n=inportb(0x05); // опрос флагов прерываний


   //		if
       char cnt = 16;
	 //	while (((inportb(0x05) &  0x10) != 0) && cnt)  // RX up0
		while (((inportb(0x05) &  0x10) != 0) && cnt)  // RX up0
				{
				 	rup0=inportb(0x0b);
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
		while(((inportb(0x05) &  0x40) != 0) && cnt) // RX up1
				{
				 	rup1=inportb(0x0d);
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
  //	bstate =  inportb(0x05);

		cnt = 16; //t16;
		while (((inportb(0x05) &  0x01) != 0) && cnt)  // RX MODEM
				{
				 	rm=inportb(0x07);
					rmc++;
		  	 //  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{		
							 //		tchar =   inportb(0x08);
							   //		tchar =   inportb(0x08);	
									if (merc <0xfffe) merc++;
							  //	    printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
							  //	    printf("MOD : rmo: %X  rm: %X   \n\r", rmo, rm);
									//508
									
							}
					rm++;
					rmo=rm;
					cnt--;
				}

	  //	if 
	    cnt = 16; //t16;
		while(((inportb(0x05) &  0x04) != 0) && cnt)  // RX TRANZIT
				{
				 rtz=inportb(0x09);
					rtzc++;
					if (rtzo!=rtz)
							{
									if (zerc <0xfffe) 	zerc++;
								  //	 printf("TRNZ : rtzo: %d  rtz: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
							  //		 printf("TRNZ : rtzo: %d  rtz: %d   \n\r", rtzo, rtz);

							}
				rtz++;
				rtzo=rtz;
				cnt--;
				}

	    my_int_enable_irq0();

}

void test_PU37()
{
	 /*
 static unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1,   i;     
 static unsigned int   merc, zerc,up0erc,up1erc;
 static unsigned char rup0, rup0o,  rup1, rup1o;
 static unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;

	*/
  static unsigned char    i;

 static unsigned int PeriodCounter = 0l;

static unsigned char maskcnt;

if(maskcnt)
{
//MaskReceive();
embSerialACT155.ChangeReceive1();
maskcnt = 0;
}
else
{
//UnMaskReceive();
embSerialACT155.ChangeReceive2();
maskcnt = 1;
}

// unsigned char tchar;
// unsigned char bstate;
// unsigned long cnt;
// for (i=0; i<20; i++)
//	{
//   n=inportb(0x07);
//   n=inportb(0x0B);
//   n=inportb(0x0d);
//   n=inportb(0x09);
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
 if(PeriodCounter > TEST_PERIOD)

//if(PeriodCounter > 10000l) //t
//#else
//if(1)
//#endif// FULL_TEST_TRANZIT
  {

//OperateBuffers_usart0t();
 PeriodCounter = 0l;
	 // TX UP0
//for (i=0; i<10; i++)
	 //	{

//modem transmit 508 : bit5
//transit transmit50a : bit5
//up0 : transmit50c : bit5
//up1 : transmit 50e
 

	 // 	bstate =  inportb(0x0c);

		//  printf("bstate up0:  %d  \n\r", bstate);


			   // while((inportb(0x05) & 0x20) == 0) {}
				  //	  if(inportb(0x05) & 0x20)
				 //	    if(inportb(0x0c) & 0x20)

		   //			  {
	//	   #ifndef FULL_TEST_TRANZIT
			 
  	 if(embSerialACT155.UsedSendUD1() < 5) 
			     {

				embSerialACT155.AddUD1(tup0++);
			    embSerialACT155.AddUD1(tup0++);
			    embSerialACT155.AddUD1(tup0++);
				embSerialACT155.AddUD1(tup0++);
				embSerialACT155.AddUD1M(tup0++);


			   //		   outportb(0x0B, tup0++);
						 		 tup0c += 5;   
	 //		#endif								   
								 }
						//	else
						//	{
						//	printfp("ud1-");
						//	} 
			   
		 





	  //	}

// TIMER MODE
	 // TX UP1
//for (i=0; i<2; i++)
//{
			  //	 while((inportb(0x05) & 0x80) == 0) {}
//bstate =  inportb(0x0e);

   //		  printf("bstate up1 :  %d  \n\r", bstate);

	//					if (inportb(0x0e) & 0x20)
   //						{
 //  #ifndef FULL_TEST_TRANZIT
 
  		if(embSerialACT155.UsedSendUD2() < 5)
			     {
			   //ok		   embSerialACT155.UsedUD1();
			   	  		 embSerialACT155.AddUD2(tup1++);
						  embSerialACT155.AddUD2(tup1++);
						   embSerialACT155.AddUD2(tup1++);
						    embSerialACT155.AddUD2(tup1++);
							 embSerialACT155.AddUD2M(tup1++);

   					 //t	 outportb(0x0D, tup1++);
   				   		 tup1c+=5;
//#endif
   					  	 }
						//	else
						//	{
						//	printfp("ud2-");
						//	} 

						 
//}
	 // TX MODEM
//for (i=0; i<8; i++)
//{
 				   //		 while((inportb(0x05) & 0x02) == 0) {}
  // bstate =  inportb(0x08);
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x08) & 0x20)
					//	 {

//#ifdef FULL_TEST_TRANZIT
		   if(embSerialACT155.UsedSendMod() < 5)
		  // 	if(!embSerialACT155.UsedSendMod()) 
				  {
		  		   embSerialACT155.AddMod(tm++);
				      embSerialACT155.AddMod(tm++);
					     embSerialACT155.AddMod(tm++);
						    embSerialACT155.AddMod(tm++);
							   embSerialACT155.AddModM(tm++);

		  		   tmc += 5;
		  		  }
				 //	else
					  //		{
					  //		printfp("m-");
					  //		} 

//#else

			//t	  outportb(0x07, tm++);
			   //	  tmc++;
//#endif

					  //	 }
//}
	  // TX TRANZIT
//for (i=0; i<8; i++)
//{
  				   //		while((inportb(0x05) & 0x08) == 0) {}
   // bstate =  inportb(0x0a);
		   //		 printf("bstate trz :  %d  \n\r", bstate);

			//			if (inportb(0x0a) & 0x20)
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
  					embSerialACT155.AddTransitM(ttz++);
	   		 //  	   ttzc++;
			  ttzc += 5;
  
			    }
				//	else
					   //		{
					   //		printfp("t-");
					   //		} 

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

					  //	 outportb(0x09,  ttz++); 
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
		//n=inportb(0x05); // опрос флагов прерываний


   //		if
        cnt = 16;
		while (((inportb(0x05) &  0x10) != 0) && cnt)  // RX up0
				{
				 	rup0=inportb(0x0b);
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
		while(((inportb(0x05) &  0x40) != 0) && cnt) // RX up1
				{
				 	rup1=inportb(0x0d);
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
  //	bstate =  inportb(0x05);

		cnt = 16;
		while (((inportb(0x05) &  0x01) != 0) && cnt)  // RX MODEM
				{
				 	rm=inportb(0x07);
					rmc++;
		  	 //  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{		
									tchar =   inportb(0x08);
									tchar =   inportb(0x08);	
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
		while(((inportb(0x05) &  0x04) != 0) && cnt)  // RX TRANZIT
				{
				 rtz=inportb(0x09);
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
							 //		tchar =   inportb(0x08);
							   //		tchar =   inportb(0x08);	
									if (merc <0xfffe) merc++;
								 //   printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
									//508
									
							}
					rm++;
						rmo=rm;

}

  
  //	if(irq.bit.IRQ_RX_trans)// m_RBuffTransit.Add(inportb(0x09)); 
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


   //	if(irq.bit.IRQ_RX_UD1)// m_RBuffUD1.Add(inportb(0x0B)); 
			   

   //	if(irq.bit.IRQ_RX_UD2)//	 m_RBuffUD2.Add(inportb(0x0D)); 	   //090413
   
	if( embSerialACT155.m_RBuffUD1.Used())
	{
				 rup0=embSerialACT155.m_RBuffUD1.Get();
				   rup0c++;
					if (rup0o!=rup0)
							{
									if (up0erc <0xfffe) 	up0erc++;
							}
				rup0++;
				rup0o=rup0;
		 //	cnt--;
	}

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


			   
//___________________________________________________________________________





			

	if (tup0c>=10000)
		{

	  //		ScreenAddString("Send UP1 --");
	  //		ScreenAddInt(tup1c);
	  //		ScreenAddString(" RX--");
	  //		ScreenAddInt(rup1c);
	  //		ScreenAddString(" ERR--");
	  //		ScreenAddInt(up1erc);
	  //		ScreenIntSent();
#ifndef USART0_TRY_PDC_1T
  	  printf("Send UP1 -- %d  RX-- %d  ERR-- %d\n\r", tup0c, rup0c, up0erc);
#else
  printfp("\n\rSend Channel 3 --"); 
  printfpd("%d",tup0c);
  printfp(" RX--"); 
  printfpd("%d",rup0c);
  printfp(" ERR--"); 
  printfpd("%d",up0erc);
OperateBuffers_usart0t();

#endif

			tup0c=0;rup0c=0; up0erc=0;

			}

	if (tup1c>=10000)
		{

	  //		ScreenAddString("Send UP1 --");
	  //		ScreenAddInt(tup1c);
	  //		ScreenAddString(" RX--");
	  //		ScreenAddInt(rup1c);
	  //		ScreenAddString(" ERR--");
	  //		ScreenAddInt(up1erc);
	  //		ScreenIntSent();
#ifndef USART0_TRY_PDC_1T
  	  printf("Send UP21 -- %d  RX-- %d  ERR-- %d\n\r", tup1c, rup1c, up1erc);
#else
  printfp("\n\rSend Channel 4 --"); 
  printfpd("%d",tup1c);
  printfp(" RX--"); 
  printfpd("%d",rup1c);
  printfp(" ERR--"); 
  printfpd("%d",up1erc);
OperateBuffers_usart0t();

#endif

			tup1c=0;rup1c=0; up1erc=0;

			}



	if (ttzc>=10000)
		{

	   //		ScreenAddString("Send TrZ --");
	   //		ScreenAddInt(ttzc);
	   //		ScreenAddString(" RX--");
	   //		ScreenAddInt(rtzc);
	   //		ScreenAddString(" ERR--");				  
	   //		ScreenAddInt(zerc);
	   //		ScreenIntSent();
   	//   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);

#ifndef USART0_TRY_PDC_1T
    printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);
#else
  printfp("\n\rSend Channel 2 --"); 
  printfpd("%d",ttzc);
  printfp(" RX--"); 
  printfpd("%d",rtzc);
  printfp(" ERR--"); 
  printfpd("%d",zerc);
OperateBuffers_usart0t();

#endif

	 //  printf("count = %d \n\r",count1);

			ttzc=0;rtzc=0; zerc=0;
			}
	
   //	if (tmc>20000)
	if (tmc>=10000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
   //	   printf("Send MOD -- %d  RX-- %d  ERR-- %d\n\r", tmc, rmc, merc);

#ifndef USART0_TRY_PDC_1T
     printf("Send MOD -- %d  RX-- %d  ERR-- %d\n\r", tmc, rmc, merc);
#else
  printfp("\n\rSend Channel 1 --"); 
  printfpd("%d",tmc);
  printfp(" RX--"); 
  printfpd("%d",rmc);
  printfp(" ERR--"); 
  printfpd("%d",merc);
OperateBuffers_usart0t();
#endif


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




//#ifdef PROG_BMD155
extern  "C" unsigned long TypeVer(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.type;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.softVer;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long CtrlNumberS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlYear;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlNumber;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long CtrlVerS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer1;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long BlockS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulBlock;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long ErrOutS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrOut;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long ErrAfterRS1S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrAfterRS1;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long ErrAfterRS2S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrAfterRS2;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long ErrBeforeRS1S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrBeforeRS1;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long ErrBeforeRS2S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrBeforeRS2;
//ret <<=16;
//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long StateModemS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.state[4];
ret <<= 24;
ret =  unStatePUM.statePUM.state[2];
ret <<= 8;

//ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 129; //t
return ret;
}
/*
extern  "C" unsigned long LoopS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.state[5];
return ret;
}
*/
//extern unsigned long Stephany19;
/*
extern  "C" void SetLoopS(unsigned long val)
{
 unStatePUM.statePUM.state[5] = (unsigned char)val;
  Stephany19 = val;
}
 */
/*
extern  "C" unsigned long TlfNumberS(void)
{
static unsigned long ret;
ret =  unEmb2TypeVer.emb2TypeVer.signature_software[1];
return ret;
}
*/
//extern  "C" void SetTlfNumberS(unsigned long *val)
/*
extern  "C" void SetTlfNumberS(signed long val)
{
 unEmb2TypeVer.emb2TypeVer.signature_software[1] = (unsigned char)val;
 unsigned char* bt = (unsigned char *)(NVRAM_BASE);
 *(bt+1) = (unsigned char)val;
  Stephany19 = val;
}
*/
//extern  "C" unsigned long SetLoopO(uchar_ptr data_ptr, uint_32 * data_len)
 /*
extern  "C" void SetLoopO(unsigned char* data_ptr, unsigned long* data_len)
{
  if(!(* data_len))
  {
	 * data_ptr =  unStatePUM.statePUM.state[5];
  }
  else
  {
	  unStatePUM.statePUM.state[5] =  * data_ptr;
  }

}
 */
extern  "C" void SetTlffumberO(unsigned char* data_ptr, unsigned long* data_len)
{
  unsigned char* bt = (unsigned char *)(NVRAM_BASE);
  unEmb2TypeVer.emb2TypeVer.signature_software[1] = (unsigned char)*data_ptr;
  *(bt+1) =   (unsigned char)*data_ptr;
  //Stephany19 = (unsigned char)*data_ptr;
}


//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)

extern  "C" void SetBERO(unsigned char* data_ptr, unsigned long* data_len)
{
}


//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
extern  "C" unsigned char * GetTlfNumberO(unsigned long* data_len)
{
 unsigned char* bt = (unsigned char *)(NVRAM_BASE);
 *data_len = 1;
 return (bt+1);
}





extern  "C" void SetLoopO(unsigned char* data_ptr, unsigned long* data_len)
{
  unStatePUM.statePUM.state[5] = (unsigned char)*data_ptr;
 // Stephany19 = (unsigned char)*data_ptr;
}


//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
extern  "C" unsigned char * GetLoopO(unsigned long* data_len)
{
  *data_len = 1;
  return &unStatePUM.statePUM.state[5];
}

extern  "C" unsigned long BitErrOut(void)
{
	return ErrResSNMP;
}
extern  "C" unsigned long bReset(void)
{
	return 0x55;
}


extern "C" void SetBLoopNear(unsigned long varval)
{
   	if(varval) {outportb(0x25, unStatePUM.statePUM.state[5] | 0x4);}
	else {outportb(0x25, unStatePUM.statePUM.state[5] & 0xfb);}
}

extern "C" void SetBLoopFar(unsigned long varval)
{
	if(varval) {outportb(0x25, unStatePUM.statePUM.state[5] | 0x8);}
	else {outportb(0x25, unStatePUM.statePUM.state[5] & 0xf7);}
}

extern "C" void SetBAlarmLaser(unsigned long varval)
{
   if(varval) {outportb(0x25, unStatePUM.statePUM.state[4] | 0x8);}
	else {outportb(0x25, unStatePUM.statePUM.state[4] & 0xf7);}

}







extern  "C" unsigned long bSignal1(void)
{
	 //  522 : 1  1/0  unlock /lock
	 if(unStatePUM.statePUM.state[2] & 2) return 0l;
	 else return 1l;
}
extern  "C" unsigned long bSignal2(void)
{
  if(unStatePUM.statePUM.state[2] & 0x8) return 0l;
	 else return 1l;

}
extern  "C" unsigned long bOpticModule(void)
{
   if(unStatePUM.statePUM.state[4] & 0x4) return 0l;
	 else return 1l;

}
extern  "C" unsigned long bFrame(void)
{
   if(unStatePUM.statePUM.state[4] & 0x1) return 0l;
	 else return 1l;
}
extern  "C" unsigned long InputSignal(void)
{
	if(unStatePUM.statePUM.state[4] & 0x1) return 0l;
	 else return 1l;

}
extern  "C" unsigned long bLoopNear(void)
{
	if(unStatePUM.statePUM.state[5] & 0x4) return 1l;
	 else return 0l;

}
extern  "C" unsigned long bLoopFar(void)
{
	if(unStatePUM.statePUM.state[5] & 0x8) return 1l;
	 else return 0l;
}
extern  "C" unsigned long bAlarmLaser(void)
{
 //	if(unStatePUM.statePUM.state[4] & 0x8) return 0l;
 //	 else return 1l;
  	if(unStatePUM.statePUM.state[4] & 0x8) return 1l;
 	 else return 0l;


}





// unsigned char *TLFNumberData;
/*
extern "C" unsigned char *TLFNumberData2(void)
{
 static unsigned char Buffer[] = "Test"; 
 return	Buffer;
}
*/


/*
extern "C" void embMsgWestE_Init(void)
{
 embMsgWestE.Init();
}


extern "C" void embMsgWestE_Add(char * pc)
{
 embMsgWestE.Add((unsigned char)* pc);
  
}
*/

//extern "C" void printEmb(void)
//{
// for(i=0; i< 10; i++) 
//		   	 {
		//   	 	printEthLongHex(embMsgWestE.body[i]);
 //		   	 }
//}

//___________________________________________________________________________________
char TestRing()
{
unsigned char  aa_loc, aa1, aa2, aa3;//, code;
unsigned int i;
  	t2ms(2);
  	outportb(0x10, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x0F, ac[i]); outportb(0x10, 0x01);// for(i=0; i<100; i++);
  	while((inportb(0x10) & 0x01)!=0);
	aa_loc = inportb(0x0f);
	aa_loc=inportb(0x0f);
	aa_loc=inportb(0x0f);
	aa1=inportb(0x0f);
	aa2=inportb(0x0f);
	aa3=inportb(0x0f);
	aa_loc =inportb(0x0f);
#ifndef USART0_TRY_PDC_1T
	printf("\r aa1=0x%X aa2=0x%X aa3=0x%X aa_loc=0x%X \r\n", aa1, aa2, aa3, aa_loc);
#else
	printfp("\r aa1=0x");
	printfpd("%X ", aa1);
    printfp(" aa2=0x");
	printfpd("%X", aa2);
    printfp(" aa3=0x");
	printfpd("%X", aa3);
    printfp(" aa_loc=0x");
	printfpd("%X", aa_loc);
	OperateBuffers_usart0t();
#endif


  	if (aa1 & 0x48)
	{
	return 1;
	}
	t2ms(10);
	return 0;
}

void StartRing()
{
 Ring();
}
//__________________________________________________________________________________


#ifdef PROG_PU_M_MUX_TEST
extern "C" void CompareRegs(void)
{
unsigned char nvram, xil;
unsigned char  *bt;
 	bt = (unsigned char *)(NVRAM_BASE);
   	 for(long i = 0; i < 0x10; i++)
	 {
	  xil = inportb3(0x90 + i); 
	  nvram = *(bt + PARAMETERS_DISPLACEMENT1 + 0x90 + i);
	  	if(xil != nvram)
	  	{
		 printf("\n\r i = 0x%02X xil = 0x%02X nvram = 0x%02X \n\r", i , xil , nvram);
	  	}
		else
		{
		 printf("\r i = 0x%02X xil = 0x%02X nvram = 0x%02X", i , xil , nvram);
		}
	 }
}

#endif //PROG_PU_M_MUX_TEST

//unsigned char NeedWriteID;

extern "C" void SetNeedWriteDevId(void)
{

  NeedWriteID = 1;
}


extern "C" void ClearNeedWriteDevId(void)
{

  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{
//static unsigned long DelayWriteTime;



  return NeedWriteID;
}




extern "C" void SetTestConfig()
{

                  Setudevconfig(0,1);		//1 device
				  Setudevconfig(1,0);		//rezerv
				  Setudevconfig(2,2);		//addr = 1 101117	   type = 2

				  Setudevconfig(3,1);		//upc type = 2 101117	addr = 1


                  SetNeedWriteDevId();
 


}


void TestParser(void)
{
numa[0] = '5';
numa[1] = '1';
numa[2] = '2';



 //T 512 00 0000 0000 0100 00 C8 1C
for(long i = 0; i < 10; i++)
{

RecvUstir('T'); 
RecvUstir(' '); 
RecvUstir(' '); 
RecvUstir('5'); 
RecvUstir('1'); 
RecvUstir('2'); 
RecvUstir(' '); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir(' '); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir(' '); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir(' '); 
RecvUstir('0'); 
RecvUstir('1'); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir(' '); 
RecvUstir('0'); 
RecvUstir('0'); 
RecvUstir(' '); 
RecvUstir('C'); 
RecvUstir('8'); 
RecvUstir(' '); 
RecvUstir('1'); 
RecvUstir('C'); 

RecvUstir(0xd); 




}

}


//__________________________________________________usart2
#ifdef USE_USART2
#ifndef CHANGE_USART12
/*
extern "C" void Remote_PRM_PCHS(void)
{
//______________________________________EDIK
while(embRS232S.UsedReceive())
  {
  	byte = embRS232S.Receive();
	if(GetTestMode() == 0x50)
      				{
                		printfp("-");
               			printfpd("%02X",byte);
      				}        
    switch(byte)
	 {
	 	case 0xAA: embMsg232S.Init(); stemp++; break; // Пакет
	 	case 0x5A: mode5AS=1; break;
	 	default:
	 	if(mode5AS) 
			{
				embMsg232S.Add(Modify5A(byte));
				mode5AS=0;
			}
	     	else embMsg232S.Add(byte);
			}
		 if(embMsg232S.IsEnd())
			{
                
           if((embMsg232S.Addr() > DEVCONFIG_QUANTITY) || (!embMsg232S.Addr())) break;
            if(GetTestMode() == 0x50)
				{ 
     					printfp("\n\r");
				}     
           cur_ans_pointer = GetDevPointer(embMsg232S.Addr());
        if(cur_ans_pointer != BAD_POINTER)
            {
           		devans[embMsg232S.Addr() - 1] = 0;
             	devstate[embMsg232S.Addr() - 1] = 1; 
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[embMsg232S.Addr() - 1].byte[i] = embMsg232S.Body(i);  //addr from 1 to 16
       			if(GetTestMode() == 0x50)
      				{
                		printfp("_");
               			printfpd("%X",embMsg232S.body[i]);
      				}               
             }	//for
           }  //if ! bad pointer
		}	//Is end
} //while
 
         if(time1-time1old232S > PUMV485_REQUEST_DELAY) //t
		{
		 //	send41++;
			if(embMsg485RequestS.IsReadyToSend())
			{
 				time1old232S = time1;

   	
			   embRS232S.Trans2(0xFF);
				embRS232S.Trans2(0xAA);
				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
					case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
					case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
					case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
					default: embRS232S.Trans2(embMsg485RequestS.body[i]);
					}
				}
		   	    embMsg485RequestS.Init();
			   }  //is ready
			else
			{
				time1old232S = time1;
				ss++;
  //          SendTraceRequest();
            cur_req_quantity = GetDevQuantity();
            if(cur_req_quantity)   //not zero
            {
               if(cur_req_pointer >= cur_req_quantity) //pointer get from zero and quantity used from one
               {
                 cur_req_pointer = 0;
               }
            cur_req_addr = GetDevAddr(cur_req_pointer);
            if((cur_req_addr <= DEVCONFIG_QUANTITY) && cur_req_addr)    
            {
            devans[cur_req_addr - 1]++;   //addresses 1...16 devans 0 ... 15
               
            embMsg485RequestS.Init();
      //t      embMsg485Request.SetAddr(cur_req_addr);
            embMsg485RequestS.SetAddr(1);    //t
				embMsg485RequestS.SetLength(1);
				embMsg485RequestS.SetBody(0,0x00);
				embMsg485RequestS.CalcCRC();
            
		        embRS232S.Trans2(0xFF);
				embRS232S.Trans2(0xAA);
			        if(GetTestMode() == 0x50)
					{           
             			printfp("\n\r");
 					}    
     
  				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
					case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
					case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
					case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
					default: embRS232S.Trans2(embMsg485RequestS.body[i]);
       						if(GetTestMode() == 0x50)
							{
                				printfp(".");
               					printfpd("%X", embMsg485RequestS.body[i]);
							}               
					}
				}
            
               } //correct addr
			embMsg485RequestS.Init();
            cur_req_pointer++;
            } 	//cur_req_quantity
		}	//not ready
}	 //time
      
////////////////////////////////////////////////
	 //	if(ans1>=200)
    
  for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
   if(devans[in] > MAX_NOT_ANSWERS_Q)
   {
      devstate[in] = 0;
     for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
   }         
  }

    
   /////////////////////////////////////////////////	UPP



//______________________________________EDIK
											 
}
		*/
//#ifdef CHANGE_USART12
#else

extern "C" void SendAnswerAsu(EmbMsg485* MsgHave)
{
  

if(keep_ans == 2)
{
//23 printfp("\n\n\r keep ans is 2 ");

 keep_ans = 1;
 return;
}
   
EmbMsg embMsgAns;  //make local
  embMsgAns.Init();
  embMsgAns.SetTOM(0x21);
  if(keep_is485) 
  {
   if( (keep_flagrequest == 3)   ||  (keep_flagrequest == 4)) //rdn
  	{
   		embMsgAns.SetRS485();
	}
  }
		embMsgAns.SetAddrI(keep_addri);
		embMsgAns.SetAddrS(keep_addrs);
		embMsgAns.SetAddrR(keep_addrr);
   /*
		embMsgAns.SetType(0x54);
		embMsgAns.SetLength(MsgHave->Length());
		for(i=0; i<MsgHave->Length(); i++) 
		{
		embMsgAns.SetBody(i,MsgHave->Body(i));
		}
	*/
		embMsgAns.SetType(0x53);
		embMsgAns.SetBody(0,2);	//command 53/2
	  //	embMsgAns.SetLength(MsgHave->Length()+1);
//121016		embMsgAns.SetLength(MsgHave->Length()+3); //add addr and crc
embMsgAns.SetLength(MsgHave->Length()+5);//121016 //add addr and crc
embMsgAns.SetBody(1,0xAA);	//add
embMsgAns.SetBody(2,MsgHave->Addr());	//add
embMsgAns.SetBody(3,MsgHave->Length());	//add

//121016			embMsgAns.SetBody(1,MsgHave->Addr());	//add
//121016			if(MsgHave->Length() < 253)
		if(MsgHave->Length() < 251)
  //23		 printfp("\n\n\r ans : ");

		for(i=0; i<MsgHave->Length(); i++) 
		{
	  //	embMsgAns.SetBody(i+1,MsgHave->Body(i));
//121016		embMsgAns.SetBody(i+2,MsgHave->Body(i));
		embMsgAns.SetBody(i+4,MsgHave->Body(i));
		  //  printfpd("\n\n\r ");
   //23	 	    printfpd(" %02X", MsgHave->Body(i));


		}
//121016			embMsgAns.SetBody(i+2,MsgHave->CRC());	//add
	embMsgAns.SetBody(i+4,MsgHave->CRC());	//add

//____________________________________________>>SEND
			embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(keep_flagrequest == 1) 
					{

        //23       usart0_ans11_cnt++;
         //23      printfpd("\n\n\receive from ant> %d \n",usart0_ans11_cnt);//ok

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
			 //			embRS232.EmptyReceive();
		 //need move to run  command				embMsg232.Init(); //090122
		 //23				keep_flagrequest = 0;
					}	//  == 1
			   //	 for(long it = 0; it< 50; it++)	//t
            
//#ifndef  RS485_DISABLED
            
	  		if(keep_flagrequest == 3) 
					{
			  //		RS485_receive_disable();
#ifdef RS485_MSG_BUFF
                         
                           	tBuffRS485.Add(embMsgAns);  //120621

#else
//need make!!!!

#endif
							//120621		embRS485.EmptyReceive();

				   //		 printf(".55");
			//	  RS485_receive_enable();
   	  //		 embMsg232S.Init();	//090122
		  //t		 printf(".");
		   //23		keep_flagrequest = 0;

			 	}	   // ==3
//#endif 
 			if(keep_flagrequest == 21) 
				{
				 //		tBuffEmbMsgEast.Add(embMsgAns);
				 //		tBuffEmbMsgWest.Add(embMsgAns);
                  
            embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgAns.FullSize(); i++) 
				{

					switch(embMsgAns.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgAns.body[i]);
					}
				}
			  embSerialACT155.AddModM(0x55);
                  
		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(keep_flagrequest == 22) 
				{
 		embSerialACT155.AddTransit(0x55);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgAns.FullSize(); i++) 
				{
					switch(embMsgAns.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgAns.body[i]);
					}
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransitM(0x55);
 		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(keep_flagrequest == 23) 
				{
				//		tBuffEmbMsgNorth.Add(embMsgAns);    //???? why do not work
                  
                  
	            embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgAns.FullSize(); i++) 
					{
						switch(embMsgAns.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgAns.body[i]);
						}
					}
		  embSerialACT155.AddUD1M(0x55);	
                  
                  
                  
			  //			tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(keep_flagrequest == 24) 
				{
				  //		tBuffEmbMsgSouth.Add(embMsgAns);     ///???
                  
               embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgAns.FullSize(); i++) 
					{
						switch(embMsgAns.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgAns.body[i]);
						}
					}

		   embSerialACT155.AddUD2M(0x55);	                  
			  //			tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2

	//121123			keep_flagrequest = 0;

		 //		embMsgRequest = NULL;
 //			}  //have flagrequest not zero
//____________________________________________<<SEND

}
//#define  REQUEST_DELAY (1)

extern "C" void Remote_PRM_PCHF(void)
{

//__________________________________tr
//#ifndef USART1_TRY_PDC
//   		if((time1-time1old485 > PUMV485_REQUEST_DELAY) && is_usart1_enabled() ) //t
//#else
       //  if(time1-time1old485 > PUMV485_REQUEST_DELAY) //t
	 /* 
	     if(time1-time1old485 > REQUEST_DELAY) //t
//#endif         
  // 	if((((time1-time1old) > 30) && is_usart1_enabled()) ||  ((time1-time1old) > 500))
	   //		if(0) //for test
	   //	if(time1-time1old > 60)   // 10
	   //	if(time1-time1old>50) // 10
	{
	//		send41++;
		//	printf(" %d", time1);
		//ok	 printEthLongHex(1);
			if(embMsg485Request_1.IsReadyToSend())
			{
		//	   printEthLongHex(2);

				time1old485 = time1;

   //     usart0_s_req_ant++;
  //      printfpd("\n\n\rs_req_ant> %d \n",usart0_s_req_ant);//ok

				*/
				 /*
				embRS485.TransS(0xFF);
				embRS485.TransS(0xAA);
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.TransS(0x5A); embRS485.TransS(0x00); break;
					case 0x55: embRS485.TransS(0x5A); embRS485.TransS(0x01); break;
					case 0xA5: embRS485.TransS(0x5A); embRS485.TransS(0x02); break;
					case 0xAA: embRS485.TransS(0x5A); embRS485.TransS(0x03); break;
					default: embRS485.TransS(embMsg485Request.body[i]);
					}
				}
		   	   embRS485.TransSGO();
			   	*/
				/*
			   embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485Request_1.Length()+3; i++)  //hier length - correct?
				{
					switch(embMsg485Request_1.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485Request_1.body[i]);
					}
				}
				 

		   	    embMsg485Request_1.Init();
			   }  //is ready


		} //time

//__________________________________tr
		 */


//______________________________________EDIK
while(embRS485.UsedReceive())
  {
  	byte = embRS485.Receive();
			 
if(GetTestMode() == 0x50)
      				{
           	 		printfpd("_%02X_",byte);
//				  ToPdcTu0
      				} 
      				
//_________________________________________________________________________
  switch(byte)
			{
				case 0xAA: embMsg485_1.Init(); stemp++; break; // Пакет
				case 0x5A: mode5AAnt=1; break;
				default:
					if(mode5AAnt) 
					{
						embMsg485_1.Add(Modify5A(byte));
						mode5AAnt=0;
					}
					else embMsg485_1.Add(byte);
			}
		if(embMsg485_1.IsEnd())
			{	
			if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r485_1_Ant>");
		 	}
				
				countUD1=0;

				for(i=0; i<32; i++)
				{
				
				   //120918		unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485_1.Body(i);
					  //		unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485_1.body[i];  //120918


			if(GetTestMode() == 0x50)
			{
			   printfp("-");
			//    printfpd("%X", embMsg485_1.Body(i));
						    printfpd("%X",embMsg485_1.body[i]);


		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }

				}
		  //120828		for(i=0; i<16; i++)
		  //120828		{
		  //120828				unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsg485_1.Body(i);
		  //120828		}


//_______________________________hier need write message to ans and send it
		   SendAnswerAsu(&embMsg485_1);



//______________________________

			  embMsg485_1.Init();
			}	//IsEnd()
//		}



//__________________________________________________________________________      				  
      				    
 //120828   RecvUstir(byte); 

    /*    
	if(GetTestMode() == 0x50)
      				{
                		printfp("-");
               			printfpd("%02X",byte);
      				}        
    switch(byte)
	 {
	 	case 0xAA: embMsg485.Init(); stemp++; break; // Пакет
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
			{
                
           if((embMsg485.Addr() > DEVCONFIG_QUANTITY) || (!embMsg485.Addr())) break;
            if(GetTestMode() == 0x50)
				{ 
     					printfp("\n\r");
				}     
           cur_ans_pointer = GetDevPointer(embMsg485.Addr());
        if(cur_ans_pointer != BAD_POINTER)
            {
           		devans[embMsg485.Addr() - 1] = 0;
             	devstate[embMsg485.Addr() - 1] = 1; 
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[embMsg485.Addr() - 1].byte[i] = embMsg485.Body(i);  //addr from 1 to 16
       			if(GetTestMode() == 0x50)
      				{
                		printfp("_");
               			printfpd("%X",embMsg485.body[i]);
      				}               
             }	//for
           }  //if ! bad pointer
		}	//Is end
} //while
 
         if(time1-time1old232S > PUMV485_REQUEST_DELAY) //t
		{
		 //	send41++;
			if(embMsg485RequestS.IsReadyToSend())
			{
 				time1old232S = time1;

   	
			   embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485RequestS.body[i]);
					}
				}
		   	    embMsg485RequestS.Init();
			   }  //is ready
			else
			{
				time1old232S = time1;
				ss++;
  //          SendTraceRequest();
            cur_req_quantity = GetDevQuantity();
            if(cur_req_quantity)   //not zero
            {
               if(cur_req_pointer >= cur_req_quantity) //pointer get from zero and quantity used from one
               {
                 cur_req_pointer = 0;
               }
            cur_req_addr = GetDevAddr(cur_req_pointer);
            if((cur_req_addr <= DEVCONFIG_QUANTITY) && cur_req_addr)    
            {
            devans[cur_req_addr - 1]++;   //addresses 1...16 devans 0 ... 15
               
            embMsg485RequestS.Init();
      //t      embMsg485Request.SetAddr(cur_rcur_rdr);
            embMsg485RequestS.SetAddr(1);    //t
				embMsg485RequestS.SetLength(1);
				embMsg485RequestS.SetBody(0,0x00);
				embMsg485RequestS.CalcCRC();
            
		        embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
			        if(GetTestMode() == 0x50)
					{           
             			printfp("\n\r");
 					}    
     
  				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485RequestS.body[i]);
       						if(GetTestMode() == 0x50)
							{
                				printfp(".");
               					printfpd("%X", embMsg485RequestS.body[i]);
							}               
					}
				}
            
               } //correct addr
			embMsg485RequestS.Init();
            cur_req_pointer++;
            } 	//cur_req_quantity
		}	//not ready
}	 //time
      
////////////////////////////////////////////////
	 //	if(ans1>=200)
    
  for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
   if(devans[in] > MAX_NOT_ANSWERS_Q)
   {
      devstate[in] = 0;
     for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
   }    
   
   */     
  }		//while

    
   /////////////////////////////////////////////////	UPP



//______________________________________EDIK
	   										 
}


#endif // CHANGE_USART02




//__________________________________________________usart2
#endif

#ifdef TEST_PARSING_COMMANDS
extern "C" void TestParsing()
{
//  printfp("\n\rTP");
//unsigned char Data[] = {0x55, 0xAA, 0xff, 1, 0, 1};	   //command 0
// unsigned char Data[] = {0x55, 0xAA, 0xff, 3, 2, 0x01, 0x02, 9};
// unsigned char Data[] = { 0xAA, 0xff, 3, 2, 0x01, 0x15, 0x1B};
 //unsigned char Data[] = { 0xAA, 0xff, 3, 2, 0x01, 0x5A,03, 0xB0};  //coding 0xaa = with=  5a 03
// unsigned char Data[] = { 0xAA, 0xff, 1, 0, 0x2};
 unsigned char Data[] = {0x55, 0xAA, 0xff, 3, 2, 0x01, 0x15, 0x1B};
 //for(i = 0; i < 8; i++)
// for(i = 0; i < 8; i++)
// for(i = 0; i < 6; i++)
// {
// OperateCommand(&Data[i]);
//ReadDatau1(unsigned char * pData, unsigned long cnt_data)
// }
 ReadDatau1(&Data[0], 8);
}

#endif


extern "C" void checklossmem()
{
 /*
printfpd("\n\r irq0 :%d",embSerialACT155.count);
   printfpd("add_to 4_buff: %d ",usart0_ans1_cnt);//ok
   printfpd("send_buff: %d ",send_buff_cnt);
  printfpd("\n\rrecv_buff_cnt1: %d ", recv_buff_cnt1);
  printfpd("recv_buff_cnt2: %d ", recv_buff_cnt2);
  printfpd("recv_buff_cnt3: %d ", recv_buff_cnt3);
  printfpd("recv_buff_cnt4: %d ", recv_buff_cnt4);
	   */
}