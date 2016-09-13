
#include "start.h"
//#include "hello7.h"
#include "embisr.h"
//#include "stdlib.h"

//_____________________
#include <mqx.h>
#include <bsp.h>
#include "hello7.h"



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

//void Enable() { asm { sti } }
//void Disable() { asm { cli } }

//void ResetWatchDog()
//{
//	outport(wdtcon,0xAAAA);
//	outport(wdtcon,0x5555);
//	outportb(0x6FB,0x55);
//};

//union u2uc
//{
//  unsigned short u;
//	unsigned char uc[2];
//};

//unsigned char HexChar(unsigned char s)
//{
//  if(s<=9) return s + '0';
//  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
//	return 'x';
//}

//void ConvertToWin1251(char *str)
//{
//	int i=0;
//	unsigned char ch;
//  while(str[i])
//	{
//		ch=str[i];
//		str[i]=ascii[ch];
//		i++;
//		if(i>=24)
//		{
//			str[i]=0; 
//			return;
//		}
//	}
//}
//unsigned long pcnt;
//char PBuff[3];
//extern pointer fusart0_ptr;
//long li;
extern int ecount2;

//unsigned long cnt_req, cnt_ans, cnt_esn, cnt_erc, cnt_loop;//, EthSendTimer; //, EthAnsTimer;

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

//void Enable() { 
//asm { sti } 
//}
//void Disable(){ 
//asm { cli }
/// }

void t2ms(unsigned long d)
{
 delay_mcs(d * 2000l);
}


void ResetWatchDog()
{
//	outport(wdtcon,0xAAAA);
//	outport(wdtcon,0x5555);
//	outportb(0x6FB,0x55);
//  wd_reset();
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


union u2uc
{
//p  unsigned u;
//unsigned u;
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

/*
struct MsgStatus
{
	unsigned short readyToSend : 1;
	unsigned short isRS232 : 1;
	unsigned short isRS485 : 1;
	unsigned short reserved : 5;
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
	int IsEnd();
	int IsEndOfHeader();
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
	if(Length()<256) return Length() + 11;	 
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

int EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+11)
				return 1;
	return 0;
}

int EmbMsg::IsEndOfHeader()
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
   char compare(unsigned long , unsigned long , unsigned long , unsigned long , unsigned long);
   void add(unsigned long , unsigned long , unsigned long , unsigned long, unsigned char );
   void init(void);
};

#ifdef ETH_TRANZIT
buffcash buff_cashe;
#endif //ETH_TRANZIT
buffcash buff_cashe_modem;
buffcash buff_cashe_tranzit;
buffcash buff_cashe_request;

void buffcash::init(void)
{

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
char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc, unsigned long isrs485)
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
  //	 if((buffc[i].ar == arloc)	|| 	(!isrs485))
	 if(buffc[i].ar == arloc)
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

for(long i = (CASHE_SIZE - 1) ; i > 0; i--)
{
 buffc[i].cnum = buffc[i-1].cnum;
 buffc[i].as = buffc[i-1].as;
 buffc[i].ai = buffc[i-1].ai;
 buffc[i].ar = buffc[i-1].ar;
 buffc[i].isRS485 = buffc[i-1].isRS485;

}
 buffc[0].cnum = num;
 buffc[0].as = as;
 buffc[0].ai = ai;
 buffc[0].ar = ar;
 buffc[0].isRS485 = isRS485;

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
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
  //t	unsigned short CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
//??????????????????????? calccrc used 11 and 12

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
	{
	  Init();
	  return 0;
	}
}

int short EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
//091214			if(counter==Length()+13)
			if(counter>=Length()+13)
//			if(counter==Length()+14)  //091217
	  //t		if(counter > Length()+13)  //091217
	  {
		 //		printEthLongHex(counter);

				return 1;
	  }
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

unsigned short EmbMsg::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
  //	if(typeOfProtocol==2)
   //	{
 //  printEthStringAdd(0,0);
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++)
			{
			 c += body[i];
	   //		printEthStringAdd(1,body[i]);
			}
	  //		printEthStringAdd(1,body[Length()+11]);
	  //		printEthStringAdd(1,body[Length()+12]);
	  //		printEthStringAdd(2,0);
			b = CRC();
	 //		printEthLongHex(b * 0x10000 + c);
			if(b==c) return 1;
			else return 0;
		}
//	}
   //	else return 0;
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
 
 
/////////////////////
//#define   EmbMsgBuffer_Size (16)
#define   EmbMsgBuffer_Size (32)
struct EmbMsgBuffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
  //  EmbMsg Buff[32];
   // EmbMsg Buff[16];
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
 //  printEthLongHex(Head);
   return n;
   }
  else
  {	 
  if(n == (BuffSize - 1))  {
#ifdef	ETH_DEBUG_ENABLED	
 //  printEthLongHex(0x99);
#endif	//ETH_DEBUG_ENABLED
   	 }
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

#ifdef PROG_ACT155N

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

void InitClocks(void)
{
   WriteSPI(0x0b, 0x2a, 0x80);
   WriteSPI(0x0b, 0x36, 0xC1);
   WriteSPI(0x0b, 0x2b, 0x05);
   WriteSPI(0x0b, 0x2c, 0x00);

}

void CheckClocks(void)
{
   char rd;
     rd =  ReadSPi(0x0b, 0x2a);
  // if (ReadSPi(0x0b, 0x36) != 0xc1)
 // printf("\n\r rd =%02X", rd);
   if (rd != 0x80)
   {
		
		SetBufferState((unsigned long)NO_CLOCK);
   }
  rd =  ReadSPi(0x0b, 0x36);
  // if (ReadSPi(0x0b, 0x36) != 0xc1)
 // printf("\n\r rd =%02X", rd);
   if (rd != 0xc1)
   {
		
		SetBufferState((unsigned long)NO_CLOCK);
   }



}


class EmbMsg485
{
public:	
	unsigned char readyToSend;
	unsigned counter;
	unsigned char body[64];

	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned CRC() {	return body[body[1]+2]+1; }
	unsigned char Body(int i) { return body[i+2]; }

	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }

	void Init();
	unsigned Add(unsigned char byte);
	unsigned Used() { return counter; }
	unsigned IsFree() { return 64-counter; }
	int IsEnd();
	unsigned ChkCRC();
	unsigned CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsg485::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++) body[i]=0;
}

unsigned EmbMsg485::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int EmbMsg485::IsEnd()
{
  if(counter>2)
	 	if(counter==Length()+3)
	 //	if(counter==Length() + 13)
			return 1;
	return 0;
} 

unsigned EmbMsg485::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned EmbMsg485::CalcCRC()
{
  int i;
	unsigned c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
		body[Length()+2]=c+1;
		return c+1;
	}
	else return 0;
} 



#endif //PROG_ACT155N


/////////////////////

//	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0;
unsigned long cntflag6;


void Callback0()
{
  time1++;
}

	EmbTimerCallback embTimerCallback0;

 //	EmbMsgBuffer rBuffEmbMsgEast;
 //	EmbMsgBuffer rBuffEmbMsgWest;


#ifdef ETH_TRANZIT	

EmbMsgBuffer rBuffEmbMsgE;
EmbMsgBuffer rBuffEmbMsgEast;
EmbMsgBuffer rBuffEmbMsgWest;
#else  // ETH_TRANZIT
EmbMsgBuffer rBuffEmbMsg;
#endif // ETH_TRANZIT	
		
	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;

 //	EmbMsgBuffer tBuffEmbMsgWest485;
 //	EmbMsgBuffer tBuffEmbMsgEast485;





	EmbMsg embMsg232;

  
//____________________________________________________________________________RDN
   //____________________________________________________________________________RDN

//____________________________________________________________________________232e
#ifndef ETH_TRANZIT
EmbMsg embMsg232E;
#endif // ETH_TRANZIT
//____________________________________________________________________________232e
 EmbMsg embMsg485E;


	EmbMsg embMsgWest;

#ifdef ETH_TRANZIT
	 		EmbMsg embMsgEthTransitW;
			EmbMsg embMsgEthTransitE;
		 	  EmbMsg embMsgWestE;	 //1223
			 /* 0304
			  char tbuffWestE[RDN_BUFFER_SIZE];
	          unsigned long cur_WestE;
			  char tbuffEastE[RDN_BUFFER_SIZE];
	          unsigned long cur_EastE;
			   char tbuffAnsE[RDN_BUFFER_SIZE];
	          unsigned long cur_AnsE;
		0304	 */
		//	  EmbMsg embMsgEthWest;	 //eth - > transitwest
		 //	  EmbMsg embMsgEthEast;	 //eth -> transiteast
   	 //		  EmbMsgBuffer tBuffEmbMsgEthWest;
	 //		  EmbMsgBuffer tBuffEmbMsgEthEast;
	   		  EmbMsgBuffer tBuffEmbMsgEthAll;
			    EmbMsgBuffer tBuffEmbMsgEthAll1;


 //			  EmbMsg embMsgEastE;
#endif // ETH_TRANZIT

#ifdef RS485_MSG_BUFF
	   EmbMsgBuffer tBuffRS485;
	   unsigned long time_lastsend_rs485;
	   unsigned char flag_wait_rs485;
#endif



	EmbMsg embMsgEast;
	EmbMsg embMsgAns;
	EmbMsg embMsgTemp;
//	EmbMsgCover embMsgCoverRequest;
	EmbMsg *embMsgRequest;

	EmbRS232 embRS232;
	EmbRS485 embRS485;
   

#ifndef PROG_ACT155N		
   	EmbMsg embMsg485;
#else //PROG_ACT155N
    EmbMsg485 embMsg485;
	EmbMsg485 embMsg485Request;
  	unsigned ans1=0, ans2=0;
	unsigned char addr485=1;
	unsigned char ss=0;
	UnStateRRL unStateRRL;

#endif //PROG_ACT155N

	EmbSerialMD34AVT embSerialACT155;

	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned long time1test=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];

 //	unsigned char far* bt;
    unsigned char * bt;

	unsigned short addr1;

	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
#ifdef ETH_TRANZIT
//0304	unsigned char ethByte;
//0304	unsigned char  mode5AWestE, mode5AEastE, recieveWestE, recieveEastE;
#endif //  ETH_TRANZIT

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

/*
unsigned EmbMsg485::CalcCRC()
{
  int i;
	unsigned c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
		body[Length()+2]=c+1;
		return c+1;
	}
	else return 0;
} 
 */

 //extern "C" void printEthString(char * , unsigned long ); 
// void ParseMsg(unsigned char * data_ppu,unsigned long ans1, unsigned long ans2)
 //void ParseMsg(unsigned char * data_ppu)
  /*
 void ParseMsg(unsigned char * cur_char) 
{
 EmbMsg * cur_msg;
 unsigned char check1 = 0; 
 unsigned char check2 = 0; 
// unsigned char * tmp;
 unsigned char * tmp1;
 unsigned char PR_STR[250];
 unsigned char CHAR_BUFF[2];
 static unsigned char keep_cycle;

 unsigned char * tmp2;

 cur_msg = (EmbMsg *)cur_char;
 unsigned long length;
   unsigned long realcrc;


 //if(!(good1 % 100))
// {
//  printf("\n\rsend = %ld  received =%ld  good =%ld  bad =%ld ",send41 , received1,  good1 ,  bad1 );
// }


 //if((*tmp) != (check2 + 1)) 

 
 //printEthLongHex(cur_msg->CRC() | 0x10000000);
 //printEthLongHex(cur_msg->Length() | 0x20000000);
 //printEthLongHex(cur_msg->CalcCRC() | 0x30000000);
 //printEthLongHex(cur_msg->CRC() | 0x40000000);
 realcrc = cur_msg->CRC();
 // if( realcrc != cur_msg->CalcCRC())
  if( cur_msg->Cycle() != (unsigned char)(keep_cycle + 1))
 {
 //printEthLongHex(realcrc | 0x10000000);
 //printEthLongHex(cur_msg->Length() | 0x20000000);
 //printEthLongHex(cur_msg->CalcCRC() | 0x30000000);
   printEthLongHex(cur_msg->Cycle() | 0x40000000);
 //bad checksum2
 // printEthString("Bad 2\r\n", 10);
 // bad1++;
  length = 	cur_msg->FullSize();
  if( length > 80) 	 length = 80;

  tmp1 = &cur_msg->body[0];
  tmp2 = &PR_STR[0];
  for(long j = 0; j < length; j++)
//  for(long j = 0; j < 46; j++)
  {
	sprintf((char*)CHAR_BUFF, "%02X" , *tmp1++);
	*tmp2++ =  CHAR_BUFF[0];
	*tmp2++ =  CHAR_BUFF[1];
	*tmp2++ =  ' ';
  }
 //	*tmp2++ =  '\n ';
 //	*tmp2++ =  '\r ';
 //   *tmp2++ =  '+';
    *tmp2++ =  0;

  printEthString(PR_STR, 250);
// printf("\n\rsend = %ld  received =%ld  good =%ld  bad =%ld ",send41 , received1,  good1 ,  bad1 );
// printf("\n\r>%s",PR_STR);

   // printf("ans1 = %ld ans2 = %ld \n\r>%s",ans1 ,ans2 ,PR_STR);
 }
 else
 {
 //good1++;
   //good checksum2
 //  printf("...Ок: ans1 = %ld ans2 = %ld \n\r",ans1 ,ans2 );
 }

   keep_cycle = cur_msg->Cycle();
   
}
  */

 /*
void ParsePPU(unsigned char * data_ppu,unsigned long ans1, unsigned long ans2)
{
 unsigned char check1 = 0; 
 unsigned char check2 = 0; 
 unsigned char * tmp;
 unsigned char * tmp1;
 unsigned char PR_STR[100];
 unsigned char CHAR_BUFF[2];

 unsigned char * tmp2;

 tmp = data_ppu;
 for (long i = 0l; i < 15l; i++)
 {
  check1 += *tmp;
  check2 += *tmp++;
 }
 if((*tmp) != (check1 + 1))
 {
 //bad checksum1
 }
 else
 {
   //good checksum1
 }

 for (i = 0l; i < 16l; i++)
 {
  check2 += *tmp++;
 }

if(!(good1 % 100))
 {
  printf("\n\rsend = %ld  received =%ld  good =%ld  bad =%ld ",send41 , received1,  good1 ,  bad1 );
 }

 if((*tmp) != (check2 + 1)) 
 {
 //bad checksum2
 // printEthString("Bad 2\r\n", 10);
  bad1++;
  tmp1 = data_ppu;
  tmp2 = &PR_STR[0];
  for(long j = 0; j < 32; j++)
  {
	sprintf((char*)CHAR_BUFF, "%02X" , *tmp1++);
	*tmp2++ =  CHAR_BUFF[0];
	*tmp2++ =  CHAR_BUFF[1];
	*tmp2++ =  ' ';
  }
	*tmp2++ =  ' ';
    *tmp2++ =  '+';
    *tmp2++ =  0;

 // printEthString(PR_STR, 100);
 printf("\n\rsend = %ld  received =%ld  good =%ld  bad =%ld ",send41 , received1,  good1 ,  bad1 );
 printf("\n\r>%s",PR_STR);

   // printf("ans1 = %ld ans2 = %ld \n\r>%s",ans1 ,ans2 ,PR_STR);
 }
 else
 {
 good1++;
   //good checksum2
 //  printf("...Ок: ans1 = %ld ans2 = %ld \n\r",ans1 ,ans2 );
 }



}
 
	*/

#ifdef ETH_TRANZIT
	/* 0304
char old_embMsgWest_number;
char old_embMsgEast_number;
unsigned long old_embMsgWest_addrs;
unsigned long old_embMsgWest_addri;
unsigned long old_embMsgEast_addrs;
unsigned long old_embMsgEast_addri;
   */

//extern "C" void InitEthTranzitMsg(void)
//{
 //  embMsgEthWest.Init();
 //  embMsgEthEast.Init();
//}

//extern "C" void	AddEthTranzit(char * pData)
//{
//  embMsgEthWest.Add((unsigned char)*pData);
//  embMsgEthEast.Add((unsigned char)*pData);
//}

//extern "C" void	AddEthTranzitBuffers(void)
//{
// tBuffEmbMsgEthWest.Add(embMsgEthWest);
// tBuffEmbMsgEthEast.Add(embMsgEthWest);
// tBuffEmbMsgEast.Add(embMsgEthWest);   //<<<<<<<<<<<<<<<<<<<<<<
// tBuffEmbMsgWest.Add(embMsgEthWest);
//}

 /* 0304 

extern "C" void	InitWestE(void)
{
  tbuffWestE[0] = 0;
  tbuffWestE[1] = 0;
  tbuffWestE[2] = ETH_TRZ;
  cur_WestE = 3;
//  embMsgEthWest.Init();
//  tBuffEmbMsgEthWest.Init();
}

extern "C" void	InitEastE(void)
{
  tbuffEastE[0] = 0;
  tbuffEastE[1] = 0;
  tbuffEastE[2] = ETH_TRZ;
  cur_EastE = 3;
  //embMsgEthEast.Init();
 // tBuffEmbMsgEthEast.Init();
}



extern "C" void	InitAnsE(void)
{
  tbuffAnsE[0] = 0;
  tbuffAnsE[1] = 0;
  tbuffAnsE[2] = ETH_TRZ;
  cur_AnsE = 3;
}

extern "C" void	AddCharAnsE(unsigned char c)
{
    if(cur_AnsE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
 	cur_AnsE = 3;

   }
   tbuffAnsE[cur_AnsE++] = c;

}

extern "C" void	SendAnsTransitToEth()
{

  static char netdest[6];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;

  tbuffAnsE[0] = 	(char)(cur_AnsE >> 8);
  tbuffAnsE[1] = 	(char)cur_AnsE; // 
  tbuffAnsE[2] = 	ETH_TRZ;

//t  RDN_Start_Transmit();
 //printf("_%ld", EthReceiveTimer);
  RDN_Start_Transmit(tbuffAnsE, netdest);
  RDN_Start_Transmit(tbuffAnsE, netdest);

 //  RDN_Start_Transmit(tbuffWestE, netdest); //t0122
  //__________________________________
 // cur_tbuffE = 2;
 //t090118 cur_EastE = 3;	 //new
 //t090118 cur_AnsE = 3;	 //t090118!!!!!!!!!!!!!!!!!!!!!!    it maked in initanse
 // delay_mcs(10000l);
//  delay_mcs(10000l);
 // delay_mcs(10000l);
 // delay_mcs(10000l);
 // delay_mcs(10000l);
}






extern "C" void	AddCharWestE(unsigned char c)
{
    if(cur_WestE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
 	cur_WestE = 3;

   }
   tbuffWestE[cur_WestE++] = c;

}

extern "C" void	AddCharEastE(unsigned char c)
{
    if(cur_EastE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
 	cur_EastE = 3;

   }
   tbuffEastE[cur_EastE++] = c;

}



extern "C" void	SendWestTransitToEth()	  //from modem channel
{
  static char netdest[6];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;

  tbuffWestE[0] = 	(char)(cur_WestE >> 8);
  tbuffWestE[1] = 	(char)cur_WestE; // 
  tbuffWestE[2] = 	ETH_TRZ;

//t  RDN_Start_Transmit();
 // printf(" %ld", EthReceiveTimer);

  RDN_Start_Transmit(tbuffWestE, netdest);
 //  delay_mcs(10000l);
 // delay_mcs(10000l);
 // delay_mcs(10000l);
 // delay_mcs(10000l);
 // delay_mcs(10000l);


  //__________________________________
 // cur_tbuffE = 2;
//t  cur_WestE = 3;	 //new
}

extern "C" void	SendEastTransitToEth()
{
  static char netdest[6];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;

  tbuffEastE[0] = 	(char)(cur_EastE >> 8);
  tbuffEastE[1] = 	(char)cur_EastE; // 
  tbuffEastE[2] = 	ETH_TRZ;

//t  RDN_Start_Transmit();
 // printf(".%ld", EthReceiveTimer);
  RDN_Start_Transmit(tbuffEastE, netdest);
  //__________________________________
 // cur_tbuffE = 2;
  cur_EastE = 3;	 //new
}

 0304 */

extern  EmbRS232 trnzRS232;

//unsigned long cnt_req, cnt_ans, cnt_esn, cnt_erc, cnt_loop;//, EthSendTimer; //, EthAnsTimer;

//unsigned long  EthSendTimer;
//0304 unsigned long  EthReceiveTimer;
//0304 unsigned long  EthReceiveDelay;



void ProtocolToEth()
{	  
 static char used_buffer = 0;
 //tif(tBuffEmbMsgEthAll.Used())
//090709 if(!used_buffer)
//cnt_loop++;
if(1)	//090709
{
 used_buffer = 1;

 //090713   while(tBuffEmbMsgEthAll.Used())	//t
	 if(tBuffEmbMsgEthAll.Used())	//090713
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEthAll.Get(embMsgA);

			 //	 printf(" %X", embMsgA.AddrR());	//t

   					//  		 printf("\n\r>");
					//  		for(i=0; i<embMsgA.FullSize(); i++) 
					 // 		{
					 // 	   	 printf(".%02X", embMsgA.body[i]);
					  //		}

				 //	if(embMsgA.AddrI()==SelfID())
				   //			{
	 				 //  		 cnt_ans++;
					 //		 printf("\n\r cnt_loop : %d cnt_ans :%d ",cnt_loop, cnt_ans);

	 					 //	printf("\n\r rec : %d send :%d ",cnt_erc, cnt_ans);	   //if remove this have lost packets!

					 	  	//  printf(" p8");
					   //		}
			 				InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsgA.FullSize(); i++) 
						{
				 			switch(embMsgA.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsgA.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
			   //		 for(long isend = 0; isend < 100; isend++) //test090708
						 SendAnsTransitToEth();


				 //	 EthSendTimer =	(( ETH_SEND_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
				   //		 return 1;
			}
}
else
{
used_buffer = 0;

  while(tBuffEmbMsgEthAll1.Used())	//t
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEthAll1.Get(embMsgA);

   					  //		 printf("\n\r>");
					  //		for(i=0; i<embMsgA.FullSize(); i++) 
					  //		{
					  //	   	 printf(".%02X", embMsgA.body[i]);
					  //		}

				 //	if(embMsgA.AddrI()==SelfID())
				   //			{
	 				   //		 cnt_ans++;
	 					 //	printf("\n\r rec : %d send :%d ",cnt_erc, cnt_ans);	   //if remove this have lost packets!

					 	  	//  printf(" p8");
					   //		}
			 				InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsgA.FullSize(); i++) 
						{
				 			switch(embMsgA.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsgA.body[i]); 
							}
						}

						 AddCharAnsE(0x55);

			  //	  		  for(long isend = 0; isend < 100; isend++) //test090708
						 SendAnsTransitToEth();
			  //	 	 EthSendTimer =	(( ETH_SEND_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
				   //		 return 1;
			}

 }

 EthReceiveDelay = ETH_RECEIVE_TIMER + (my_rand() % ETH_RECEIVE_TIMER);
  EthReceiveTimer = 0l;

  //	return 0;
}


void ProtocolFromEthTransit()
//char ProtocolFromEthTransit()
{
	int ic=0;
	static char test23 = 0;
	while(trnzRS232.UsedReceiveE())
	{
//			ResetWatchDog();
//			if(++ic>16) return;
			ethByte = trnzRS232.ReceiveE();
	   //		AddCharWestE(westByte);
   //	   printf(" %02X",ethByte );


			switch(ethByte)
			{

		/*
			case 0x55: time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgEthTransitW.Init(); break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgEthTransitW.Init();	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWestE=1; ready_mod=1; break;
		 */
			case 0x55: recieveWestE = 0;    embMsgEthTransitW.Init(); break; 			
			case 0xAA: recieveWestE = 1;   embMsgEthTransitW.Init();	break; 			
			case 0xA5:   break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWestE = 1;  break;


			default:
			   //	if(markerWest==1)	markerWest=2; 
				if(recieveWestE==1)
				{
					if(mode5AWestE) { embMsgEthTransitW.Add(Modify5A(ethByte)); mode5AWestE=0;	}
					else embMsgEthTransitW.Add(ethByte);
				}
			}




			if(embMsgEthTransitW.IsEnd())
			{

		// 	 EthReceiveTimer = 0l;
 
		if((embMsgEthTransitW.AddrS()!=SelfID())&&(embMsgEthTransitW.AddrI()!=SelfID()))
		{
						// передаем побайтно дальше принимаем пакет
	   //		if(buff_cashe_tranzit.compare((ет
	   		if(buff_cashe_tranzit.compare((unsigned long)embMsgEthTransitW.body[1],(unsigned long)embMsgEthTransitW.AddrS(), (unsigned long)embMsgEthTransitW.AddrI(), (unsigned long)embMsgEthTransitW.AddrR(), (unsigned long)embMsgEthTransitW.IsRS485()) != 1)
   	   //	  	if(1)
   		   	{
		  	 buff_cashe_tranzit.add(embMsgEthTransitW.body[1], embMsgEthTransitW.AddrS(), embMsgEthTransitW.AddrI(), embMsgEthTransitW.AddrR(),  (unsigned long)embMsgEthTransitW.IsRS485());
//---------------------------------------------------------------				   
 //				   tBuffEmbMsgWest.Add(embMsgEthTransitW);
 //				   tBuffEmbMsgEast.Add(embMsgEthTransitW);
//---------------------------------------------------------------
 
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgEthTransitW.FullSize(); i++) 
					{
						switch(embMsgEthTransitW.body[i])
						{
					 	case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgEthTransitW.body[i]);						
						}
					}	
				    embSerialACT155.AddTransit(0x55);
			}	//cashe 
		   		  // embSerialACT155.AddTransit(0x55);


  	if(buff_cashe_modem.compare((unsigned long)embMsgEthTransitW.body[1], (unsigned long)embMsgEthTransitW.AddrS(), (unsigned long)embMsgEthTransitW.AddrI(), (unsigned long)embMsgEthTransitW.AddrR(), (unsigned long)embMsgEthTransitW.IsRS485()) != 1)
   		   	{
		  	 buff_cashe_modem.add(embMsgEthTransitW.body[1], embMsgEthTransitW.AddrS(), embMsgEthTransitW.AddrI(), embMsgEthTransitW.AddrR(), (unsigned long)embMsgEthTransitW.IsRS485());
			  /*
			  if(!(embMsgEthTransitE.ChkCRC()))
		  	  {
		  	   printEthLongHex(0);
		 	  }
		  	  else
		   	  {
			   printEthLongHex(1);
		      }
				  */
				embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgEthTransitW.FullSize(); i++) 
				{

					switch(embMsgEthTransitW.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgEthTransitW.body[i]);
					}
				}
				embSerialACT155.AddMod(0x55);
				countSend++;


			   } //cashe

			} //s, I
		   //		   printf(" %04X addrs:",embMsgEthTransitW.AddrS());
		   //		    printf(" %04X selfid:",SelfID());
			 	   	
//090515				if(embMsgEthTransitW.AddrS()==SelfID())

#ifndef ALL_ADDR			
	 	 	if(embMsgEthTransitW.AddrS()==SelfID())
#else
			if(1)	  //t 090427
#endif //ALL_ADDR


				{
				 //  printf("\n\r ->");
  			   //	  	 cnt_erc++;
  		       //		printf("erc:%d ",cnt_erc);

 				  //		    printf("\n\r>");
				   //			for(i=0; i<embMsgEthTransitW.FullSize(); i++) 
				  //			{
				  //		   	 printf(".%02X", embMsgEthTransitW.body[i]);
				  //			}





					embMsgEthTransitW.SetDir(1);
					rBuffEmbMsgE.Add(embMsgEthTransitW);
			   //	 	printf("t");
					embMsgEthTransitW.Init();
				}
		  //this is error!!!!!		recieveWest = 0;
			  //	
			}  //isend
				 
//__________________________>>

	/*
		switch(ethByte)
		{

			 
				case 0x55: recieveEastE=0; embMsgEthTransitE.Init();   break; 			
				case 0xAA: recieveEastE=1;  embMsgEthTransitE.Init(); break; 			
				case 0xA5: 	  break; // Маркеров здесь НЕТ!
					// Если в буффере есть пакет на передачу, то передаем его
				case 0x5A: mode5AEastE=1; break;


				default:
				  		if(recieveEastE==1)
					{
						if(mode5AEastE) { embMsgEthTransitE.Add(Modify5A(ethByte)); mode5AEastE=0;	}
						else embMsgEthTransitE.Add(ethByte); 
					}
		}


		if(embMsgEthTransitE.IsEnd())
		{



			if((embMsgEthTransitE.AddrS()!=SelfID())&&(embMsgEthTransitE.AddrI()!=SelfID()))
			{
		 // 	if(1)
		  	if(buff_cashe_modem.compare((unsigned long)embMsgEthTransitE.body[1], (unsigned long)embMsgEthTransitE.AddrS(), (unsigned long)embMsgEthTransitE.AddrI(), (unsigned long)embMsgEthTransitE.AddrR(), (unsigned long)embMsgEthTransitE.IsRS485()) != 1)
   		   	{
		  	 buff_cashe_modem.add(embMsgEthTransitE.body[1], embMsgEthTransitE.AddrS(), embMsgEthTransitE.AddrI(), embMsgEthTransitE.AddrR());
		 				embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgEthTransitE.FullSize(); i++) 
				{

					switch(embMsgEthTransitE.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgEthTransitE.body[i]);
					}
				}
				embSerialACT155.AddMod(0x55);
				countSend++;

			  }
			}
			
	//not need two times make this	
		  
			if(embMsgEthTransitE.AddrS()==SelfID())
			{
			   

   				embMsgEthTransitE.SetDir(2);
	 			rBuffEmbMsg.Add(embMsgEthTransitE);
	 			embMsgEthTransitE.Init();
			//	return 1;

	 		}
	  		 
	  //  return ; //to not send more! in this time! next burst will be send later!
		}
	  */
//__________________________>>
  } //while
//  return 0;
}
 

#endif // ETH_TRANZIT




char ProtocolFromModACT155()
{
	int ic=0;
	static char test23 = 0;
	while(embSerialACT155.UsedMod())
	{
   //			ResetWatchDog();
//			if(++ic>16) return;
			westByte = embSerialACT155.GetMod();
#ifdef ETH_TRANZIT
//t090708			AddCharWestE(westByte);
#endif // ETH_TRANZIT

#ifndef ETH_TRANZIT
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
#else
switch(westByte)
			{
			case 0x55: 	time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgWest.Init();/* InitWestE();*/ break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgWest.Init();/* InitWestE();  */	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
					if(mode5AWest) { embMsgWest.Add(Modify5A(westByte));/*AddCharWestE(Modify5A(westByte));*/mode5AWest=0;	}
			  		else {embMsgWest.Add(westByte);/*	 AddCharWestE(westByte);*/}
			  //		else {embMsgWest.Add(westByte);	 AddCharWestE(test23++);}	//ok
				}
			}


#endif




if(embMsgWest.IsEnd())
   {
   recieveWest = 0;
  if(embMsgWest.ChkCRC())	  //091111
	{						   //091111
   	if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
	{
	  	// передаем побайтно дальше принимаем пакет

		   if(buff_cashe_tranzit.compare((unsigned long)embMsgWest.body[1], (unsigned long)embMsgWest.AddrS(), (unsigned long)embMsgWest.AddrI(), (unsigned long)embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485()) != 1)
   		 //  	if(1)
   		   	{
		 	 buff_cashe_tranzit.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485());

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

#ifdef ETH_TRANZIT
    
   if(embMsgWest.AddrS()!=SelfID())	//t
    {		  //t
   if(buff_cashe.compare((unsigned long)embMsgWest.body[1], (unsigned long)embMsgWest.AddrS(), (unsigned long)embMsgWest.AddrI(), (unsigned long)embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485()) != 1)
 // if(1) //t
   {
 //	 if( embMsgWest.AddrS() == 0x4347)//!=SelfID()
  //	 if( 1)//!=SelfID()
 //	 {
 //	   cnt_esn++;
 //	   printf("se:%d", cnt_esn);
	 
  //	 }
	  //   printf("as:%X", embMsgWest.AddrS());

	 tBuffEmbMsgEthAll.Add(embMsgWest);	  //t0129
//090709	  tBuffEmbMsgEthAll1.Add(embMsgWest);	  //t0129

  //t0129 	 SendWestTransitToEth();
 	 buff_cashe.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR(), embMsgWest.IsRS485());
  //	 EthSendTimer =	(( ETH_SEND_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
 //	 return 1;
   }
   else
   {
 //  printf("wn:%02xwas:%04xwai:%04x ==" , embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI());
 //  printf("on:%02xoas:% 04xoai:%04x" , old_embMsgWest_number, old_embMsgWest_addrs, old_embMsgWest_addri);
   }
 } //t
   
	   	   //	    SendWestTransitToEth();
	  //t			InitWestE();
#endif // ETH_TRANZIT
				}
#ifndef ALL_ADDR					
				if(embMsgWest.AddrS()==SelfID())
#else  // ALL_ADDR	
				if(1)
#endif // ALL_ADDR	
				{

					embMsgWest.SetDir(1);
#ifdef ETH_TRANZIT	
					rBuffEmbMsgWest.Add(embMsgWest);
#else  //ETH_TRANZIT
				    rBuffEmbMsg.Add(embMsgWest);
#endif	//ETH_TRANZIT
//_________________________________________________________________________
	 //		 printf("\n\r");
	 //					for(i=0; i<embMsgWest.FullSize(); i++) 
	 //					{
	 //				   printf(".%0X",	embMsgWest.body[i]);
  	 //				}
	 //		printf("\n\rCRC : %X CalcCRC : % X", embMsgWest.CRC(), embMsgWest.CalcCRC());
//_________________________________________________________________________




					embMsgWest.Init();
				}
					embMsgWest.Init();	 //101210
  //091111				recieveWest = 0;
#ifdef ETH_TRANZIT
//t090708			    InitWestE();	 //clear!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif //  ETH_TRANZIT
}
else   //091111
{
 embMsgWest.Init();	  //091111
}	 //crc
} //is end


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
  //					ResetWatchDog();
				}
				    embSerialACT155.AddTransit(0x55);
			}

//hier need init to clear!!!!!
	  //	  InitWestE();	 //clear!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}  //is end
	}	  //while



 return 0;
}

char ProtocolFromTransitACT155()
{
	int ic=0;

	while(embSerialACT155.UsedTransit())
	{
 //		ResetWatchDog();
//		if(++ic>16) return;
		eastByte = embSerialACT155.GetTransit();
#ifdef ETH_TRANZIT
//t090708		AddCharEastE(eastByte); //t
#endif // ETH_TRANZIT

#ifndef ETH_TRANZIT
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
#else // ETH_TRANZIT
	   switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init();//tInitEastE(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init();//t InitEastE(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit = time3Marker = time1;  break; // Маркеров здесь НЕТ!
					// Если в буффере есть пакет на передачу, то передаем его
				case 0x5A: mode5AEast=1; ready_transit=1; break;
				default:
					if(markerEast==1)	markerEast=2; 
					if(recieveEast==1)
					{
						if(mode5AEast) { embMsgEast.Add(Modify5A(eastByte));/*AddCharEastE(Modify5A(eastByte));*/  mode5AEast=0;	}
						else {embMsgEast.Add(eastByte); /* AddCharEastE(eastByte); */}
					}
		}
#endif //	ETH_TRANZIT


if(embMsgEast.IsEnd())
{
recieveEast=0; //101210
	if(embMsgEast.ChkCRC())	  //091111
	{						   //091111

			  recieveEast=0; //091111
	//ok	   printf("p0");

			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{

   if(buff_cashe_modem.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
 //  			 if(1)
   		   	{
   			 buff_cashe_modem.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485());
			 /*	 
				if(!(embMsgEast.ChkCRC()))
		  	  {
		  	   printEthLongHex(0);
		 	  }
		  	  else
		   	  {
			   printEthLongHex(1);
		      }
			 */ 



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
#ifdef ETH_TRANZIT

  
  if(buff_cashe.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
   {
    tBuffEmbMsgEthAll.Add(embMsgEast);	  //t0129
 //090709	 tBuffEmbMsgEthAll1.Add(embMsgEast);	  //t0129


  //t0129 	 SendEastTransitToEth();
  	 buff_cashe.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485());
 //	  EthSendTimer =	(( ETH_SEND_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
  // 	 return 1;
   }
   
   else{
//     printf("en:%02x eas:%04x eai:%04x==" , embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI());
 //  printf("eon:%02x eos:%04x eoi:%04x" , old_embMsgWest_number, old_embMsgWest_addrs, old_embMsgWest_addri);
   }
   
		  // 	    SendEastTransitToEth();
		 //t		InitEastE();	//t
#endif // ETH_TRANZIT
				countSend++;
			}
#ifndef ALL_ADDR			
	 	 	if(embMsgEast.AddrS()==SelfID())
#else
			if(1)	  //t 090427
#endif //ALL_ADDR
			{
		 //ok	printf("pa");
		   //		printf("\n\r CRC : %X CalcCRC : %X" , embMsgEast.CRC(), embMsgEast.CalcCRC());
				embMsgEast.SetDir(2);
#ifdef ETH_TRANZIT
				rBuffEmbMsgEast.Add(embMsgEast);
		  //ok		printf("pb");

#else //ETH_TRANZIT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! hier have error!!!!!!
				    rBuffEmbMsg.Add(embMsgEast);
		 //			printf("pc");

#endif //ETH_TRANZIT

				embMsgEast.Init();
			}
			embMsgEast.Init();	 //101210
#ifdef ETH_TRANZIT
//t090708		InitEastE();  //clear!!!!
#endif // ETH_TRANZIT
		}	 //crc
		else
		{
		  embMsgEast.Init();
		}	//crc
} //is end

//		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
				   /*	 
				 if(!(embMsgA.ChkCRC()))
		  	  {
		  	   printEthLongHex(0);
		 	  }
		  	  else
		   	  {
			   printEthLongHex(1);
		      }
				
		   		  */	 


				
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
   //					ResetWatchDog();
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

//____
 //		if(unEmb2NetStat.emb2NetStat.buffModPm<embSerialACT155.UsedMod()) unEmb2NetStat.emb2NetStat.buffModPm = embSerialACT155.UsedMod();
 //		if(unEmb2NetStat.emb2NetStat.buffTransPm<embSerialACT155.UsedTransit()) unEmb2NetStat.emb2NetStat.buffTransPm = embSerialACT155.UsedTransit();
 //		if(unEmb2NetStat.emb2NetStat.buffModPd<embSerialACT155.UsedSendMod()) unEmb2NetStat.emb2NetStat.buffModPd = embSerialACT155.UsedSendMod();
 //		if(unEmb2NetStat.emb2NetStat.buffTransPd<embSerialACT155.UsedSendTransit()) unEmb2NetStat.emb2NetStat.buffTransPd = embSerialACT155.UsedSendTransit();
 //		if(unEmb2NetStat.emb2NetStat.buff232Pm<embRS232.UsedReceive()) unEmb2NetStat.emb2NetStat.buff232Pm = embRS232.UsedReceive();
 //		if(unEmb2NetStat.emb2NetStat.buff232Pd<embRS232.UsedTrans()) unEmb2NetStat.emb2NetStat.buff232Pd = embRS232.UsedTrans();



//____


//		if(!recieveEast)
		{
	   //	 	printf(">");	
				if(!embSerialACT155.UsedSendMod()) 
				{	
	   //			 	  printf("-");


					if(tBuffEmbMsgEast.Used())
					{
		//			 printf("\r\n<<<<"); 

						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);

  			   	 /*
			   if(!(embMsgA.ChkCRC()))
		  	  {
		  	   printEthLongHex(0);
		 	  }
		  	  else
		   	  {
			   printEthLongHex(1);
		      }
			  		*/
				

					
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
		//					ResetWatchDog();
						}
						embSerialACT155.AddMod(0x55);
					}
				}
		}

//		if(!recieveWest)
		{
			if(!embSerialACT155.UsedSendTransit()) 
			{	
#ifdef ETH_TRANZIT
/*
 if(tBuffEmbMsgEthWest.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEthWest.Get(embMsgA);
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
  //					ResetWatchDog();
				}
				    embSerialACT155.AddTransit(0x55);
			}
			*/
#endif //ETH_TRANZIT



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


	unsigned char tlf_number[6];
	unsigned char tlf_counter=0;
	unsigned char tlf_state=0;
	unsigned char presto = 0;
	unsigned char ring_counter = 0;
	unsigned long presto_time =0;
	unsigned long wait_time =0;
	unsigned long presto_ring =0;

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
unsigned char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xC0,0x04}; // AX-Filter -строка 29
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
unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 

void InitTLF()
{
	int i;

// сброс кодека
	for(i=0; i<15; i++) outportb(0x511, 0x08); 
	outportb(0x511, 0x00);
	for(i=0; i<10000; i++);

	outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab1); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x50F, ab2[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab2); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x50F, ab3[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab3); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x50F, ab4[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab4); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x50F, ab5[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab5); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x50F, ab6[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab6); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x50F, ab7[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab7); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x50F, ab8[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab8); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x50F, ab9[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab9); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x50F, ab10[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab10); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x50F, ab11[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab11); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x50F, ab12[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab12); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x50F, ab13[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab13); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x50F, ab14[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab14); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x50F, ab15[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab15); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x50F, ab16[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab16); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x50F, ab17[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab17); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x50F, ab18[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab18); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x50F, ab19[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab19); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x50F, ab20[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab20); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x50F, ab21[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab21); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab22); i++) outportb(0x50F, ab22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab23); i++) outportb(0x50F, ab23[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab23); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab24); i++) outportb(0x50F, ab24[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab24); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab25); i++) outportb(0x50F, ab25[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab25); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab26); i++) outportb(0x50F, ab26[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab27); i++) outportb(0x50F, ab27[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab27); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab28); i++) outportb(0x50F, ab28[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab28); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab29); i++) outportb(0x50F, ab29[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab29); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab30); i++) outportb(0x50F, ab30[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab30); i++);
}

void Ring()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a272[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a272); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a271); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a27); i++);
  outportb(0x511, 0x00); // оn hook
}
void Active()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a222); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x50F, a26[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a261); i++) outportb(0x50F, a261[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a261); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a262); i++) outportb(0x50F, a262[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a262); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause2()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a263); i++) outportb(0x50F, a263[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a263); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a264); i++) outportb(0x50F, a264[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a264); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a265); i++) outportb(0x50F, a265[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a265); i++);
	outportb(0x511, 0x00); // off hook
}

void Wait()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a222); i++);
//	outportb(0x510, 0x02); for(i=0; i<sizeof(a28); i++) outportb(0x50F, a28[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a28); i++);
	outportb(0x511, 0x00); // on hook
}

void Read()
{
// Пример  передачи/приема по SPI
// outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01);
// while((inportb(0x510) & 0x01)!=0);
// чтение принятых байтов  по адресу  0x50F принимается столько же байт сколько и  передается
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(aa); i++) outportb(0x50F, aa[i]); outportb(0x510, 0x01); inportb(0x510); for(i=0; i<200*sizeof(aa); i++);
	for(i=0; i<7; i++) aaa[i] = inportb(0x50F);
	
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




//__________________________________________________
#ifdef PROG_BMD155PS

struct Emb4AvtFrequMode
{
	unsigned char type;
	unsigned char reserv;
  //	unsigned char reserv1;		//my
 //	unsigned char reserv2;		//my
	unsigned short ctrlBUK;
	unsigned char numOfFrequ[2];
	unsigned char frequ[160];
};

union UnEmb4AvtFrequMode
{
	Emb4AvtFrequMode emb4AvtFrequMode;
  	unsigned char byte[166];
 //	unsigned char byte[168];  //my
};
/////////////////////
struct Emb2PSMode
{
	unsigned char fpd1;
	unsigned char fpm1;
	unsigned char fpd2;
	unsigned char fpm2;
};


union UnEmb2PSMode
{
	Emb2PSMode emb2PSMode;
	unsigned char byte[4];
};
  /*
union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
	unsigned char uc[2];
};

	 */
EmbMsg embMsgRandMode;
unsigned char powerMes[16];
unsigned char frequSelfPd[2];
unsigned char frequSelfPm[2];

UnEmb4AvtFrequMode  * unEmb4AvtFrequMode;
UnEmb2PSMode  unEmb2PSMode;

	unsigned ctrlRandMode;
	unsigned char randMasterMode;
	unsigned char	frequRandPd;
	unsigned char	frequRandPm;
	unsigned char powerByte;
	unsigned char counterPower;

unsigned char recievePower=0;		 //need init!
unsigned char mode5APower=0; 		 //need init!
unsigned long timeRand=0;			 //need init!
unsigned char trunk = 0;			 //need init!	
EmbMsgBuffer tBuffEmbMsg485;		//need init!	

unsigned long time485=0;			//need init!
/*
unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;

UL2UC ul2uc;
UI2UC ui2uc;
*/


void SendPower(unsigned char t, unsigned char frequ1, unsigned char frequ2)
{
// <Blank><Trunk[1...8]><P_Input><CRC>
 //	unsigned char crc;
	unsigned char powerstr[16];
	if(t) 
	{
		unEmb2PSMode.emb2PSMode.fpd2 = frequ1;
		unEmb2PSMode.emb2PSMode.fpm2 = frequ2;
	}
	else
	{
		unEmb2PSMode.emb2PSMode.fpd1 = frequ1;
		unEmb2PSMode.emb2PSMode.fpm1 = frequ2;
	}

	embSerialACT155.AddPower(0xAA); // Start
	powerstr[0] = (SelfID()>>8)&0xFF; // SelfCtrlHigh
	powerstr[1] = SelfID()&0xFF; // SelfCtrlLow
	powerstr[2] = 0x01; // Mode 1-Random 0-Const
	powerstr[3] = t; // Trunk
	powerstr[4] = frequ1; // Fpd
	powerstr[5] = frequ2; // Fpm
	for(i=0; i<6; i++)
	{
		switch(powerstr[i]) // Pвх
		{
			case 0x5A: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x00); break;
			case 0x55: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x01); break;
			case 0xA5: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x02); break;
			case 0xAA: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x03); break;
			default: embSerialACT155.AddPower(powerstr[i]);
		}
	}
	embSerialACT155.AddPower(0x55); // End
}



void CheckPower()
{
	unsigned char t;// ,k;
	while(embSerialACT155.UsedPower())
	{
		ResetWatchDog();
//		if(++ic>16) return;
		powerByte = embSerialACT155.GetPower();
		if(counterPower>15) counterPower=0;
		switch(powerByte)
		{
				case 0x55: 
					if(counterPower>=6)
					{
						ctrlRandMode = (powerMes[0]<<8)+powerMes[1];
						if(ctrlRandMode>SelfID()) randMasterMode = 0;
						else randMasterMode = 1;
//						embRS232.Trans((unsigned char)'S');
						if(powerMes[2])
						{
							t = powerMes[3];
							if(t<2)
							{
//								embRS232.Trans((unsigned char)'a');
								//							if(frequRandPd[t] != powerMes[3]) 
								{
									// Включаем возможность изменения частоты
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,14);	        		
									embMsgRandMode.SetBody(2,208);				
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
									
									//								frequRandPd[t] = powerMes[3];
									// Посылаем команду на перестройку частоты Пд
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
									embMsgRandMode.SetBody(2,powerMes[5]);			
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
								}
								//							if(frequRandPm[t] != powerMes[4]) 
								{
									//								frequRandPm[t] = powerMes[4];
									// Посылаем команду на перестройку частоты Пм
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
									embMsgRandMode.SetBody(2,powerMes[4]);			
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
								}
							}
						}
					}
					else
					{
//						frequRandPd[t] = 0xFF;
//						frequRandPm[t] = 0xFF;
					}
					counterPower = 0;
					// конец пакета - разбираем пакет
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: recievePower=1; counterPower=0;
					// начало пакета 
					break; 			
				case 0xA5: 	 break; // Маркеров здесь НЕТ!
				case 0x5A: mode5APower=1; break;
				default:
					if(recievePower==1)
					{
						if(mode5APower) { powerMes[counterPower++]=Modify5A(powerByte); mode5APower=0;	}
						else powerMes[counterPower++]= powerByte;
					}
		}
	}
}

unsigned long input1p,input2p,input1err, input2err;


void RandFrequ()
{
	unsigned rand = my_rand();//;//my  = inport(0xFF60);
	unsigned char randfrequ;
//	unsigned char input1 = inportb(0x522)&0x02;
//	unsigned char input2 = (inportb(0x522)>>2)&0x02;
//	unsigned char input1rm = (inportb(0x522)>>4)&0x02;
//	unsigned char input2rm = (inportb(0x522)>>6)&0x02;

	/*	 090126
	unsigned char input1 = inportb(0x523)&0x01;
	unsigned char input2 = (inportb(0x523)>>1)&0x01;
	unsigned char input1rm = (inportb(0x523)>>2)&0x01;
	unsigned char input2rm = (inportb(0x523)>>3)&0x01;
  */
	unsigned char readall =  inportb(0x522);
    unsigned char read1 = (readall&0x2);
  	unsigned char read2 = (readall&0x8);

   	
    unsigned char input1;// = (inportb(0x522)&0x2);
	unsigned char input2;// = (inportb(0x522)&0x8);

if(!read1)  input1p++; else { input1p = 0; }//input1n++;
if(!read2) input2p++; else {input2p = 0; }  //input2n++;

if(input1p == (COUNTER_LOCK >> 1))	 input1err = unStatePUM.statePUM.ulErrAfterRS1;
if(input2p == (COUNTER_LOCK >> 1))	 input2err = unStatePUM.statePUM.ulErrAfterRS2;

	
	
/*
	unsigned char input1 = !(inportb(0x522)&0x8);
	unsigned char input2 = !(inportb(0x522)&0x2);
   */
	unsigned char input1rm = input1;
	unsigned char input2rm = input2;


	if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1)
	{
  
	//  	if(readall && (readall != 2) && (readall != 8))
	//	{
	//	 printEthLongHex(readall);
	//	}


   //	   	if(time1-timeRand>2000)
	   	if(time1-timeRand > TIME_CHECK_LOCK)
	 //	if(time1-timeRand>5000)	//5s
	//	if(time1-timeRand>10000)	//5s
		{
	  //t	  printEthLongHex(inportb(0x522));

    if((input1p > COUNTER_LOCK) && (unStatePUM.statePUM.ulErrAfterRS1 == input1err))  input1 = 0;	else  input1 = 1;
 	if((input2p > COUNTER_LOCK)  && (unStatePUM.statePUM.ulErrAfterRS2 == input2err)) input2 = 0;	else  input2 = 1;
   	input1rm = input1;
   	input2rm = input2;
   //		printEthLongHex(input1err);
   //		printEthLongHex(unStatePUM.statePUM.ulErrAfterRS1);

  //		printEthLongHex(input2err);
  //		printEthLongHex(unStatePUM.statePUM.ulErrAfterRS2);

	input1p  = 0;
	input2p  = 0;
    input1err = unStatePUM.statePUM.ulErrAfterRS1;
	input2err  = unStatePUM.statePUM.ulErrAfterRS2;


		timeRand = time1;
//		embRS232.Trans((unsigned char)'.');
		if((!input1)&&(!input2)&&(!input1rm)&&(!input2rm))	 //all lock
		{
  //		printEthLongHex(0x100);
//			embRS232.Trans((unsigned char)'t');
//			embRS232.Trans(HexChar((inportb(0x522)>>4)&0x0F));	
//			embRS232.Trans(HexChar(inportb(0x522)&0x0F));	
//			embRS232.Trans('.');

			if(randMasterMode)
			{
	  //		printEthLongHex(0x15);

//					embRS232.Trans((unsigned char)'R');
					// Генерим в датчике случайных чисел номер частотной пары
				  //my	rand = inport(0xFF60);
			   //		rand = TimerCounter;
					rand = my_rand();

			   //		printEthLongHex(1);
					randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
				//	printEthLongHex(randfrequ);	//0
					frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
					frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
					// unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK;
					// Передаем на другую сторону
	   //			  	printEthString(" ", 4);
		//		  	printEthByteHex(randfrequ);
				   //	printEthByteHex(rand);

			   	// 	printEthByteHex(frequSelfPd[trunk]);
			   	 //	printEthByteHex(frequSelfPm[trunk]);
			   //		printEthLongHex(trunk);
					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
					// Включаем возможность изменения частоты
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();				
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,14);	        		
					embMsgRandMode.SetBody(2,208);				
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пд
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
					embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пм
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
					embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// устанавливаем время ожидания незахвата
					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
					if(trunk) trunk=0;
					else trunk=1;
			}  //mastermode
		}  //lock all
		else
		{
			if(input1&&input2)	//not lock local
			{
//	  		  printEthLongHex(0x12);

//				embRS232.Trans((unsigned char)'N');
				// Генерим в датчике случайных чисел номер частотной пары
		   //my		rand = inport(0xFF60);
		   //		rand = time1;
			//	rand = Stephany5;
		   //		rand = *(unsigned long *)(REAL_TIME);
				rand = my_rand();
			 //	printEthLongHex(rand);	//5F60
			   //	printEthLongHex(TimerCounter);
				randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
		  //	   printEthLongHex(randfrequ);
				frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
				frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
				// Передаем на другую сторону
				SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
			 //	   printEthLongHex(frequSelfPd[trunk]);
				// Включаем возможность изменения частоты
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();				
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,14);	        		
				embMsgRandMode.SetBody(2,208);				
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// Посылаем команду на перестройку частоты Пд
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
				embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// Посылаем команду на перестройку частоты Пм
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
				embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// устанавливаем время ожидания незахвата
				if(trunk) trunk=0;
				else trunk=1;
			}
			else   //have any lock local
			{
	  //		printEthLongHex(0x13);

//				embRS232.Trans((unsigned char)'E');
//				embRS232.Trans(HexChar((inportb(0x522)>>4)&0x0F));	
//				embRS232.Trans(HexChar(inportb(0x522)&0x0F));	
//				embRS232.Trans('.');	
				if(randMasterMode)
				{
		//  	 	  printEthLongHex(0x14);

					trunk = 2; 
						  
					if(input1||input1rm) trunk=0;

					if(input2||input2rm) trunk=1;
					 

				 //	if(!input1 || (!input1rm)) trunk=0;
				 //	if(!input2 || (!input2rm)) trunk=1;



					if(trunk==2) 
					{
//						embRS232.Trans((unsigned char)'e');
						return;
					}
				// Передаем на другую сторону
//					if((frequSelfPd[trunk]==0xFF)||(frequSelfPm[trunk]==0xFF))
					{
//						embRS232.Trans((unsigned char)'+');
					 //my	rand = inport(0xFF60);
					//	rand = TimerCounter;
						rand = my_rand();
			   //	   		printEthLongHex(trunk + 6);	//5F60

						randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
						frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
						frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
					}

//					embRS232.Trans((unsigned char)'0'+trunk);

					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]); // ИЗ ПАМЯТИ!!!
					// Включаем возможность изменения частоты
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();				
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,14);	        		
					embMsgRandMode.SetBody(2,208);				
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пд
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
					embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пм
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
					embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
				} //any lock local 
			}
		}
		}
	}
}

void UpdatePUNInfo()
{
	unStatePUM.statePUM.state[0]  = inportb(0x520);
	unStatePUM.statePUM.state[1]  = inportb(0x521);
	unStatePUM.statePUM.state[2]  = inportb(0x522);
	unStatePUM.statePUM.state[3]  = inportb(0x523);
	unStatePUM.statePUM.state[4]  = inportb(0x524);
	unStatePUM.statePUM.state[5]  = inportb(0x525);
 //081129 	unStatePUM.statePUM.state[6]  = 0;
	unStatePUM.statePUM.state[6] = inportb(0x536);	 //added from BMD155() 081129
	unStatePUM.statePUM.state[7]  = 0;
	unStatePUM.statePUM.state[8]  = 0;
	unStatePUM.statePUM.state[9]  = 0;
	unStatePUM.statePUM.state[10] = 0;
	unStatePUM.statePUM.state[11] = 0;
	unStatePUM.statePUM.state[12] = 0;
	unStatePUM.statePUM.state[13] = 0;
	unStatePUM.statePUM.state[14] = 0;
	unStatePUM.statePUM.state[15] = 0;

		unStateBMD155.stateBMD155.statePI=0;
/////////////////////////////////////////
		unStateBMD155.stateBMD155.mod=0;
		unStateBMD155.stateBMD155.dem1=0;
		unStateBMD155.stateBMD155.dem2=0;
		unStateBMD155.stateBMD155.state_dem1=0;
		unStateBMD155.stateBMD155.state_dem2=0;
}
#endif //PROG_BMD155PS



#ifdef ETH_TRANZIT

unsigned char IsEthTransitMode(void)
{
 if (read_nvram_char(ETH_TRANZIT_ON_ADDRESS) ==	 ETH_TRANZIT_ON_VALUE) return 1;
 else return 0;
}
#endif //  ETH_TRANZIT


unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;

UL2UC ul2uc;
UI2UC ui2uc;





//__________________________________________________


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//void main()

// unsigned char *TLFNumberData;
// extern unsigned char BuffTlf[5];
extern "C" void Init_BMD155(void)
{
#ifdef PROG_ACT155
 wd_reset_enabled = 1;
#endif //PROG_ACT155




cntflag6 = 0;
ErrResSNMP = 0l;
timeres = 0l;
start_count = 0;


#ifdef PROG_BMD155PS
input1p = 0;
input2p = 0;
input1err = 0;
input2err = 0;


//unsigned long  FREQ_BASE;


	trunk = 0;
 	for(i=0; i<2; i++)
	{
		frequSelfPd[i] = 0xFF;
		frequSelfPm[i] = 0xFF;
	}
//   unEmb4AvtFrequMode = (UnEmb4AvtFrequMode far*)0x80001000;
    unEmb4AvtFrequMode = (UnEmb4AvtFrequMode *)(FREQ_BASE);

	unEmb2PSMode.emb2PSMode.fpd1 = 0;
	unEmb2PSMode.emb2PSMode.fpm1 = 0;
	unEmb2PSMode.emb2PSMode.fpd2 = 0;
	unEmb2PSMode.emb2PSMode.fpm2 = 0;

tBuffEmbMsg485.Init();

	ctrlRandMode=0;
	randMasterMode=1;
	frequRandPd=0xFF;
	frequRandPm=0xFF;

 	recievePower=0;		 
 	mode5APower=0; 		 
	timeRand=0;			 
	trunk = 0;	
	time485 = 0;		 


#endif //PROG_BMD155PS





 buff_cashe_modem.init();
 buff_cashe_tranzit.init();
 buff_cashe_request.init();


 
//
 send41 = 0l; send42 =0l; received1 =0l; received2 =0l; good1 =0l; good2 =0l; bad1 =0l; bad2 =0l;
//_____________________________________________
AsciiInit();
EmbInit(); //my
#ifdef PROG_ACT155N
 ans1=0; 
 ans2=0;
 embMsg485Request.Init();
 addr485=1;
 ss=0;
 for(i=0; i<32; i++)
	{
		unStateRRL.stateRRL.ppu1_bytes[i] = 0;
		unStateRRL.stateRRL.ppu2_bytes[i] = 0;
	}
 unStateRRL.stateRRL.ver = 0x01;

  InitClocks();
#endif //PROG_ACT155N

/* 
 cnt_req = 0;
 cnt_ans = 0;
 cnt_esn = 0;
 cnt_erc = 0;
 cnt_loop = 0;
 */ 
 //EthAnsTimer = 0;

  time1=0;
  flagRequest=0;
  serr=0xFF; crc_temp=0;
  i=0;
  time1old=0; time2old=0;
  request1=0; request2=0;
  time3Marker=0; time3BlankTransit=0; time3BlankMod=0;
  time1test=0;
  markerWest=0; markerEast=0; ready_transit=0; ready_mod=0; dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgWest=0; delete_msgEast=0; recieveWest=0; recieveEast=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0; mode5AWest=0; mode5AEast=0; 



#ifdef ETH_TRANZIT
 InitWestE();
 InitEastE();
 InitAnsE();
 buff_cashe.init();
//#endif //ETH_TRANZIT

//#ifdef ETH_TRANZIT


 // EthSendTimer = 0;
 EthReceiveTimer = 0;
  mode5AWestE=0; mode5AEastE=0;
  tBuffEmbMsgEthAll.Init();
   tBuffEmbMsgEthAll1.Init();


 // EthReceiveDelay = ETH_RECEIVE_TIMER + (SelfID() % 200);
   EthReceiveDelay = ETH_RECEIVE_TIMER + (my_rand() % ETH_RECEIVE_TIMER);

#endif //ETH_TRANSIT

#ifdef RS485_MSG_BUFF
	   tBuffRS485.Init();
	   time_lastsend_rs485 = 0;
	   flag_wait_rs485 = 0;
#endif //RS485_MSG_BUFF



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

   tlf_counter=0;
   tlf_state=0;
   presto = 0;
   ring_counter = 0;
   presto_time =0;
   wait_time =0;
   presto_ring =0;

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
//_____________________________________________



//	outportb(0x6FF,inportb(0x6FF)|0x10);


///////  Канал транзит  ///////
//	time5=0;
//	outportb(0x5B7, 0x94);
///////////////////////////////

	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
#ifdef ETH_TRANZIT
    rBuffEmbMsgE.Init();
	rBuffEmbMsgEast.Init();
	rBuffEmbMsgWest.Init();
#else
	rBuffEmbMsg.Init();
#endif //ETH_TRANZIT

 //	ResetWatchDog();

	embSerialACT155.Init();
 //in EmbInit()	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
 //in EmbInit()	embRS485.Init(384);		// Инициализация RS485 на скорость 38400 кбит/с
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
 //this is error - not testet from usedmod() : will brocken buffer!		embSerialACT155.GetMod();
// this is error - not testted	from usedtransit : will brocken buffer!	embSerialACT155.GetTransit();
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
 #ifdef PROG_ACT155
	unEmb2TypeVer.emb2TypeVer.type       = 0x0105;
 #else //PROG_ACT155
 #ifdef PROG_ACT155N
	unEmb2TypeVer.emb2TypeVer.type       = 0x0108;
 #else	 //	PROG_ACT155N
	unEmb2TypeVer.emb2TypeVer.type       = 0x0505;
#endif	 //	PROG_ACT155N

 #endif	 //	PROG_ACT155
 	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;  //add suppourt protocol	rs232 from ethernet protocol 888
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();	//was 0
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();	//was 0
	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
	unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = read_xil_char(1);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = read_xil_char(2);
	unEmb2TypeVer.emb2TypeVer.signature_hardware[15] =  read_nvram_char(RESTARTS_NVRAM_ADDRESS);
	write_nvram_char(RESTARTS_NVRAM_ADDRESS, (unEmb2TypeVer.emb2TypeVer.signature_hardware[15] + 1));
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
   //	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15);
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+ETH_TRANZIT_ON_ADDRESS); 
 




//TLFNumberData = (bt+1);
//BuffTlf[0] = *(bt+1);
//BuffTlf[1] = 0;//'1';
//BuffTlf[2] = 0;
//BuffTlf[3] = 0;//** '2';
//BuffTlf[4] = 0;//'3';


///////  Включаем канал транзит 0x95 - 0x00  ///////
///////  "конец" 0x95 - 0x01
//	while(time5<12); // 10 ms
//	outportb(0x5B7, 0x00);
////////////////////////////////////////////////
 //	Enable(); // Разрешаем все прерывания

	embMsgTemp.Init();

	Wait();
//	Ring();
	presto_time = time1;

//______________________________Init All EmbMsgObjekts

   embMsg232.Init();
#ifndef ETH_TRANZIT
   embMsg232E.Init();
#endif // ETH_TRANZIT
   embMsg485E.Init();

#ifdef ETH_TRANZIT
 		embMsgEthTransitW.Init();
		embMsgEthTransitE.Init();
 	    embMsgWestE.Init();	 //1223
#endif // ETH_TRANZIT

	embMsgEast.Init();
	embMsgAns.Init();
	embMsgTemp.Init();
//	EmbMsgCover embMsgCoverRequest;
	embMsgRequest = NULL;
}
//	while(1)

extern "C" void BMD155()
 {
//__________________________________________________________________
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
 //	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15); 
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+ETH_TRANZIT_ON_ADDRESS); 

//___________________________________________________________________






 //	static long err_timer = 0l;
	long err_tmp_now = 0l;
	static long err_tmp_prev1 = 0l;
	static long err_tmp_prev3 = 0l;
    static long err_tmp_prev4 = 0l;

#ifdef PROG_BMD155PS

 if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1) { RandFrequ(); // printEthLongHex(0x21);
  }
 UpdatePUNInfo();
 if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1) { CheckPower(); //printEthLongHex(0x22); 
 }

 if(tBuffEmbMsg485.Used()&&(time1-time485>100))
		{
		  //  printEthLongHex(0x23);
			time485 = time1;
			EmbMsg msg285temp;
			tBuffEmbMsg485.Get(msg285temp);
			embRS485.Trans(0x55);
			embRS485.Trans(0xAA);
		//12	  printEthLongHex(msg285temp.FullSize());

			for(i=0; i<msg285temp.FullSize(); i++) 
			{
				switch(msg285temp.body[i])
				{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(msg285temp.body[i]);
				}
			}
			embRS485.Trans(0x55);
		}


#endif //PROG_BMD155PS


  //	static long err_tmp_prev5 = 0l;
  //	static long err_tmp_prev6 = 0l;

 


 //		ResetWatchDog();
/////////  Плата интерфейсов  ///////////
//	unsigned temp1, temp2;
// 526-527	Счётчик ошибок после комбинатора	16 бит
// 528-52A	Счётчик ошибок, исправленных РС в 1 стволе	24 бит
// 52B-52D	Счётчик ошибок, исправленных РС в 2 стволе	24 бит
// 52E-52F	Счётчик ошибок не исправленных РС в 1 стволе	16 бит
// 530-531	Счётчик ошибок не исправленных РС в 2 стволе	16 бит
// 532-533	Счётчик числа принятых пакетов	16 бит
 // if(err_timer++ > 1000l)
// if(1)
   //	 {
 //	 err_timer = 0l;
   //	err_tmp = (unsigned short)inportb(0x526) + ((unsigned short)inportb(0x527)<<8);
   err_tmp = (unsigned short)inportb(0x526) + ((unsigned short)inportb(0x527)<<8);
   err_tmp_now =   err_tmp -  err_tmp_prev1;
   err_tmp_prev1 = err_tmp;
   if(err_tmp >= count_no_correct_result) 
	unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result;
	else
 //t	unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result + 0x10000;
	unStateBMD155.stateBMD155.count_no_correct_result = (err_tmp  + 0x10000 ) - count_no_correct_result ;
  //	err_tmp = 0; //test
	count_no_correct_result = err_tmp;
	unStatePUM.statePUM.ulErrOut = err_tmp;
 //t	ErrResSNMP += err_tmp;
 if(!start_count)
 {start_count = 1;}
 else
 {
	ErrResSNMP += unStateBMD155.stateBMD155.count_no_correct_result;
 }
//	if(err_tmp>=count_no_correct_result) count_no_correct_result = err_tmp - count_no_correct_result;
//	else count_no_correct_result = count_no_correct_result - err_tmp;
  //	 printf("\n\r1: %X",err_tmp);

	err_tmp = (unsigned short)inportb(0x532) + ((unsigned short)inportb(0x533)<<8);
   	if
	(err_tmp>=count_block) unStateBMD155.stateBMD155.count_block = err_tmp - count_block;
	else 
//t	unStateBMD155.stateBMD155.count_block = err_tmp - count_block + 0x10000;
	unStateBMD155.stateBMD155.count_block = (err_tmp + 0x10000 ) - count_block ;
	count_block = err_tmp;
	unStatePUM.statePUM.ulBlock = err_tmp;
//	if(err_tmp>=count_block) count_block = err_tmp - count_block;
//	else count_block = count_block - err_tmp;
  //	 printf("\n\r2: %X",err_tmp);

	err_tmp = (unsigned short)inportb(0x52E) + ((unsigned short)inportb(0x52F)<<8);
	err_tmp_now =   err_tmp -  err_tmp_prev3;
    err_tmp_prev3 = err_tmp;
 	if
	(err_tmp >= count_notRS1)	unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1;
	else
//t	 unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1 + 0x10000;
	 unStateBMD155.stateBMD155.count_notRS1 = (err_tmp + 0x10000) - count_notRS1 ;
	count_notRS1 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS1 = err_tmp;
//	if(err_tmp>=count_notRS1)  count_notRS1= err_tmp - count_notRS1;
//	else count_notRS1 = count_notRS1 - err_tmp;
   //	 printf("\n\r3: %X",err_tmp);

	err_tmp = (unsigned short)inportb(0x530) + ((unsigned short)inportb(0x531)<<8); 
	err_tmp_now =   err_tmp -  err_tmp_prev4;
    err_tmp_prev4 = err_tmp;
 	if	(err_tmp>=count_notRS2)
 	 unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2;//count_notRS2;
	else 
  //t	unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2 + 0x10000;
	unStateBMD155.stateBMD155.count_notRS2 = (err_tmp + 0x10000) - count_notRS2 ;
  //	err_tmp = 0; //test
	count_notRS2 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS2 = err_tmp;
//	if(err_tmp>=count_notRS2) count_notRS2 = err_tmp - count_notRS2;
//	else count_notRS2 = count_notRS2 - err_tmp;
   //	  printf("\n\r4: %X",err_tmp);

	err_tmp = (unsigned short)inportb(0x528) + ((unsigned short)inportb(0x529)<<8) + ((unsigned long)inportb(0x52A)<<16);
//	err_tmp =   err_tmp_now -  err_tmp_prev5;
 //   err_tmp_prev5 = err_tmp_now;

	if(err_tmp>=count_no_correct_block1)
	 unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1;
	else 
//t	unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1 + 0x1000000;	 
	unStateBMD155.stateBMD155.count_no_correct_block1 = (err_tmp + 0x1000000) - count_no_correct_block1 ;
	count_no_correct_block1 = err_tmp;
	unStatePUM.statePUM.ulErrBeforeRS1 = err_tmp;
//	if(err_tmp>=count_no_correct_block1) count_no_correct_block1 = err_tmp - count_no_correct_block1;
//	else count_no_correct_block1 = count_no_correct_block1 - err_tmp;
  //	  printf("\n\r5: %X",err_tmp);

	err_tmp = (unsigned short)inportb(0x52B) + ((unsigned short)inportb(0x52C)<<8) + ((unsigned long)inportb(0x52D)<<16);
//	err_tmp =   err_tmp_now -  err_tmp_prev6;
//    err_tmp_prev6 = err_tmp_now;

	if(err_tmp	>= count_no_correct_block2)
	 unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2;
	else
 //t	 unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2 + 0x1000000;
	unStateBMD155.stateBMD155.count_no_correct_block2 = (err_tmp + 0x1000000) - count_no_correct_block2 ;
  //	   err_tmp = 0; //test
	count_no_correct_block2 = err_tmp; 
	unStatePUM.statePUM.ulErrBeforeRS2 = err_tmp;
 //	  printf("\n\r6: %X",err_tmp);
 //	  printf("\n\r");
//	if(err_tmp>=count_no_correct_block2) count_no_correct_block2 = err_tmp - count_no_correct_block2;
//	else count_no_correct_block2 = count_no_correct_block2 - err_tmp;
//___________________________________________________________
static long printcounter;
printcounter++;

if((GetTestMode() == 0x50) &&  (!(printcounter % 500)))
{
 	printf(	"\n\r> i1:%d o1:%d i2:%d o2:%d out:%d ", unStatePUM.statePUM.ulErrBeforeRS1, 	
 				unStatePUM.statePUM.ulErrAfterRS1,
 		  		   unStatePUM.statePUM.ulErrBeforeRS2,
				    unStatePUM.statePUM.ulErrAfterRS2,
		   unStatePUM.statePUM.ulErrOut );
}
//____________________________________________________________

#ifndef PROG_BMD155PS	//it is readed now in funktion UpdatePUNInfo();

	unStatePUM.statePUM.state[0] = inportb(0x520);
	unStatePUM.statePUM.state[1] = inportb(0x521);
	unStatePUM.statePUM.state[2] = inportb(0x522);
	unStatePUM.statePUM.state[3] = inportb(0x523);
	unStatePUM.statePUM.state[4] = inportb(0x524);
	unStatePUM.statePUM.state[5] = inportb(0x525);
	unStatePUM.statePUM.state[6] = inportb(0x536);
	unStatePUM.statePUM.state[7] = 0;
	unStatePUM.statePUM.state[8] = 0;
	unStatePUM.statePUM.state[9] = 0;
	unStatePUM.statePUM.state[10] = 0;
	unStatePUM.statePUM.state[11] = 0;
	unStatePUM.statePUM.state[12] = 0;
	unStatePUM.statePUM.state[13] = 0;
	unStatePUM.statePUM.state[14] = 0;
	unStatePUM.statePUM.state[15] = 0;
#endif // no  PROG_BMD155PS
  //	}
/////////////////////////////////////////
 //	unsigned char bblt;
	unBmdState.byte = inportb(0x522);

  //	if(unBmdState.byte & 0x8)
  //	{	printEthLongHex(0x888); }

	unLtDiod.byte=0;
	unLtDiod.ltDiod.alarmIn1 = unBmdState.bmdState.alarmSync1;//unBmdState.bmdState.alarmIn1;
	unLtDiod.ltDiod.alarmIn2 = unBmdState.bmdState.alarmSync2;//unBmdState.bmdState.alarmIn2;
	unLtDiod.ltDiod.alarmSync1 = unBmdState.bmdState.alarmSync1;
	unLtDiod.ltDiod.alarmSync2 = unBmdState.bmdState.alarmSync2;

  //	static unsigned char toprint;

 //	 if(toprint !=  unLtDiod.byte)
  //	{
  //	 printEthLongHex(unLtDiod.byte);
  //	}

  //	 toprint = unLtDiod.byte;

   

	outportb(0x536,unLtDiod.byte); 


		unStateBMD155.stateBMD155.statePI=0;
/////////////////////////////////////////
		unStateBMD155.stateBMD155.mod=0;
		unStateBMD155.stateBMD155.dem1=0;
		unStateBMD155.stateBMD155.dem2=0;
		unStateBMD155.stateBMD155.state_dem1=0;
		unStateBMD155.stateBMD155.state_dem2=0;
//////////////////////////////////////////////////
	if((time1 - wait_time) >=40) 
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
	   //				if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == unEmb2TypeVer.emb2TypeVer.signature_software[1]) // = self_tlf_number
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
				}	 //counter > 2
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
			} //presto
		}	 //((aaa[3]&0x80)&&(aaa[5]&0x80))

	}	 //((time1 - wait_time) >=40)
////////(time1 - wait_time) >=40)
///////////////
		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;
//////////////////////////////////////////////////


 
#ifdef ETH_TRANZIT
 // ProtocolFromEthTransit();
 // if(EthReceiveTimer > ETH_RECEIVE_TIMER) //t
 // if(EthReceiveTimer > ETH_RECEIVE_TIMER + (SelfID() % 200)) //t
if(IsEthTransitMode())
{
#ifndef ALL_ADDR
  if(EthReceiveTimer > EthReceiveDelay) //t
#else
   if(1)
#endif
  {
   	 //t  if(!EthSendTimer)
	 //  {
  	   	ProtocolToEth();
	 //	}
  }
}
#endif // ETH_TRANZIT
   //	   if(!EthAnsTimer)	ProtocolToEth();
#ifdef ETH_TRANZIT
   //t	   if(!EthSendTimer)
   //	   if(EthReceiveTimer > ETH_RECEIVE_TIMER)

#endif // ETH_TRANZIT
	 //  	if(	
 	   	ProtocolFromModACT155();
	 //  	) return;//t0122   //this get to lost

#ifdef ETH_TRANZIT
  //t	   if(!EthSendTimer) 
#endif // ETH_TRANZIT	   
	   	ProtocolFromTransitACT155();

		Check2InitTransitMod();

#ifdef ETH_TRANZIT
 //if(!EthSendTimer) 

      //   ProtocolFromEthTransit();

 //if(!EthSendTimer)
 // ProtocolToEth();
//if(embMsgWestE.IsEnd())
  //			{
		   //	  	printEthLongHex(embMsgWestE.body[5]);
			   //	embMsgWestE.Init();

			 //  	if(embMsgWestE.AddrS()==SelfID())
			 //	{
			 //   printEthLongHex(2);
			 //		embMsgWestE.SetDir(1);
			 //		rBuffEmbMsg.Add(embMsgWestE);
			  //		embMsgWestE.Init();
			   //	}
		   //	 }	 
		   //	 if(embMsgWestE.body[5] == 0x67)
		   //	 {
		   //	 for(i=0; i< 10; i++) 
		   //	 {
		   //	 	printEthLongHex(embMsgWestE.body[i]);
		   //	 }
		   //	 }
							   
//if(embMsgWestE.Used())

#endif //ETH_TRANZIT

//////////////////////////////////////////////////
#ifndef PROG_ACT155N

/*	  100110
#include checkremotemod.inc
#include answermod.inc
   */
#include mod_rem.inc //100110
#ifdef ETH_TRANZIT
if(IsEthTransitMode())
{
ProtocolFromEthTransit();
}
#endif //ETH_TRANZIT



//#include act_rem_test.c //090707
//#include remote_act_15501.inc

#else //PROG_ACT155N
#include act_rem.c //090707

//my_int_enable();
#ifdef ETH_TRANZIT
if(IsEthTransitMode())
{
ProtocolFromEthTransit();
}

#endif //ETH_TRANZIT

#endif //PROG_ACT155N


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
   	TimerCounter1 ++;
#ifdef ETH_TRANZIT
 //	if(EthSendTimer) EthSendTimer--;
	EthReceiveTimer++; 
#endif // ETH_TRANZIT


 //	if(EthAnsTimer) EthAnsTimer--; 
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
 //t my_int_enable_irq0();
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq0();
 }

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



void StartTestTlf()
{
// unsigned char j, aa_loc, aa1, aa2, aa3, code;
 unsigned int i;//,z,  merc, zerc,up0erc,up1erc, w;
 

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


outportb(0x511, 0x04); // 0);


outportb(0x511, 0x04); // r(i=0; i<sizeof(a26); i++) outportb(0x50F, a26[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
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
         
	
outportb(0x510, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x50F, ac[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
 
 while((inportb(0x510) & 0x01)!=0);

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
	 
	outportb(0x500, i);
	if (i != ( inportb(0x500)) ) 
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
   n=inportb(0x507);
   n=inportb(0x50B);
   n=inportb(0x50d);
   n=inportb(0x509);
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
  unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;


void test_PU37_interrupt_ovner()
{

 //unsigned int tmp =  (unsigned int)INT0_FLAG;
   //t      while (IntFlag & tmp)
   //     if(IntFlag & tmp)
   //	 if(1)
	 //	{
	   //	  IntFlag &=  ~tmp;
		//n=inportb(0x505); // опрос флагов прерываний


   //		if
       char cnt = 16;
	 //	while (((inportb(0x505) &  0x10) != 0) && cnt)  // RX up0
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

		cnt = 16; //t16;
		while (((inportb(0x505) &  0x01) != 0) && cnt)  // RX MODEM
				{
				 	rm=inportb(0x507);
					rmc++;
		  	 //  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);

					if (rmo!=rm)
							{		
							 //		tchar =   inportb(0x508);
							   //		tchar =   inportb(0x508);	
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
		while(((inportb(0x505) &  0x04) != 0) && cnt)  // RX TRANZIT
				{
				 rtz=inportb(0x509);
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
 if(PeriodCounter > TEST_PERIOD)

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
#ifndef USART0_TRY_PDC_1T
   printf("\n\rSend Power -- %d  RX-- %d  ERR-- %d\n\r", tup0c, rup0c, up0erc);
#else
  printfp("\n\rSend Power --"); 
  printfpd("%d",tup0c);
  printfp(" RX--"); 
  printfpd("%d",rup0c);
  printfp(" ERR--"); 
  printfpd("%d",up0erc);
  OperateBuffers_usart0t();

#endif
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
   	//   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);

#ifndef USART0_TRY_PDC_1T
    printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);
#else
  printfp("\n\rSend TrZ --"); 
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
	
	if (tmc>20000)
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
  printfp("\n\rSend MOD --"); 
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
extern  "C" void SetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
{
  unsigned char* bt = (unsigned char *)(NVRAM_BASE);
  unEmb2TypeVer.emb2TypeVer.signature_software[1] = (unsigned char)*data_ptr;
  *(bt+1) =   (unsigned char)*data_ptr;
  //Stephany19 = (unsigned char)*data_ptr;
}


//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
extern  "C" unsigned char * GetBERO(unsigned long* data_len)
{
 static unsigned char BufBER[50];

// double BER = (double)(timeres) * (double)(155520000l) / (double)(ErrResSNMP);
// sprintf(BufBER,"%LE4", BER);
 // double BER = (double)123/(double)454;
 // float BER = (float)123/(float)454;

  float BER;
  if(timeres)
  {
  	if(ErrResSNMP)
  	{
//  	BER = (float)(ErrResSNMP)/((float)(timeres) * (float)(155520000l))  ;
	BER = (float)(ErrResSNMP)/((float)(timeres) * (float)(155520l)); //time in ms

	 BufBER[0] = ' ';
		
  	}
	else
	{
 //	 BER = (float)(1l)/((float)(timeres) * (float)(155520000l))  ;
	  BER = (float)(1l)/((float)(timeres) * (float)(155520l))  ;   //time in ms
  //	  BER = (float)(1l)/((float)(timeres) * (float)(1l))  ;
	 BufBER[0] = '<';
 	}
  }
  else
  {
   BufBER[0] = ' ';
     BER = 0l;
  }
 // long BER = 123.;
 //sprintf(&BufBER[0],"%E", BER);
 //tsprintf((char *)&BufBER[0],"%.3E", BER);
 sprintf((char *)&BufBER[1],"%.1E", BER);
 //*data_len = 10;
 //t*data_len = 9;
 *data_len = 8;
 return ((unsigned char *)&BufBER[0]);
}

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
extern  "C" unsigned long ttReset(void)
{
	return (timeres / 1000l);
}
extern  "C" unsigned long bReset(void)
{
	return 0x55;
}

extern "C" void SetBResetS(unsigned long varval)
{
   ErrResSNMP = 0l;
   timeres = 0l;
   start_count = 0l;
}

extern "C" void SetBLoopNear(unsigned long varval)
{
   	if(varval) {outportb(0x525, unStatePUM.statePUM.state[5] | 0x4);}
	else {outportb(0x525, unStatePUM.statePUM.state[5] & 0xfb);}
}

extern "C" void SetBLoopFar(unsigned long varval)
{
	if(varval) {outportb(0x525, unStatePUM.statePUM.state[5] | 0x8);}
	else {outportb(0x525, unStatePUM.statePUM.state[5] & 0xf7);}
}

extern "C" void SetBAlarmLaser(unsigned long varval)
{
   if(varval) {outportb(0x525, unStatePUM.statePUM.state[4] | 0x8);}
	else {outportb(0x525, unStatePUM.statePUM.state[4] & 0xf7);}

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
  	outportb(0x510, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x50F, ac[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
  	while((inportb(0x510) & 0x01)!=0);
	aa_loc = inportb(0x50f);
	aa_loc=inportb(0x50f);
	aa_loc=inportb(0x50f);
	aa1=inportb(0x50f);
	aa2=inportb(0x50f);
	aa3=inportb(0x50f);
	aa_loc =inportb(0x50f);
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

