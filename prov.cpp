//#ifndef __TINY__
//#define __TINY__
//#endif
//#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include "basic.h"
#include "command.h"
//#include <dataflash.h>
#include "PVG610_API.h"

extern "C" int read_dataflash (unsigned long , unsigned long , char *);

#pragma BSS(".buff_sect")
extern uchar TFTP_Buffer[TFTP_BUFFER_SIZE];
#pragma BSS()






 /*
#define IncEmbRS232
#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
#define IncEmbIndicator
#define IncEmbSerialACT8
*/

////////////////////////////////////////////
//#include "longtoa.cas"
//#include "Ltoa1.c"
//#include "stdlib.h"
//#include "command.h"
//#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"



//___________________________________________________________________________________
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
unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 

//___________________________________________________________________________________

unsigned char debug_byte=0;
unsigned debug_word=0;
short int ACT_type = 1;
int psp_number=0;	
unsigned long time1=0,time2=0,time3=0,timeRing=0,timeRing2=60;	
unsigned long time1p=0,time2p=0,time3p=0;			  //need init!
int	ringOn=0;				  //need init
int ringBliker=0;
unsigned long counterErrPSP=0;			//need init
int state;
char statusStr[25];
char dpd_state;



#define PT_NULL     (0)
#define PT_ERR1     (1)
#define PT_ERR2     (2)
#define PT_ERR_PSP  (3)
#define PT_CTRL     (4)
#define PT_RING     (5)
#define PT_SOUND    (6)
#define PT_ADDR     (7)
#define PT_POINT    (8)
#define PT_CALIBR   (9)
#define PT_PROT		(10)
#define PT_VER		(11)


#define ST_NORMA	(0)
#define ST_LOOP		(1)
#define ST_ERROR1	(2)
#define ST_ERROR2	(3)
#define ST_SEARCH	(4)
#define ST_FAULT	(5)
#define ST_ALARM	(6)
				   




/*
const ST_NORMA	= 0;
const ST_LOOP		= 1;
const ST_ERROR1	= 2;
const ST_ERROR2	= 3;
const ST_SEARCH	= 4;
const ST_FAULT	= 5;
const ST_ALARM	= 6;
*/






//port const BIT_IN_FRAME = 22000;
#define BIT_IN_FRAME  (22000) //port

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
//   char compare(unsigned long , unsigned long , unsigned long , unsigned long );
   char compare(unsigned long , unsigned long , unsigned long , unsigned long , unsigned long);
   void add(unsigned long , unsigned long , unsigned long , unsigned long );
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
}
}


//char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc)
char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc, unsigned long isrs485)
{
 //return 0; //test

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
	 if((buffc[i].ar == arloc)	|| 	(!isrs485))
    {

//    printf(" -1-");
     return 1;}
	}
	}
	}
}
  // printf("== %02X %04X %04X ==", numloc, asloc,  ailoc);
//   printf(" -0-");
 return 0;
}
void buffcash::add(unsigned long num, unsigned long as, unsigned long ai, unsigned long ar)
{
//return; //t

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


//_________________________________________________________________________________
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
//________________________________________________________ 
/////////////////////
struct EmbMsgBuffer
{
    unsigned  short BuffSize;
    unsigned  short Head;
    unsigned  short Tail;
//    EmbMsg Buff[16];
  EmbMsg Buff[160];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned  short Used();
    unsigned  short Free();
};

void EmbMsgBuffer::Init()
{
//  BuffSize = 16;
  BuffSize = 160;
  Head = 0;
  Tail = 0;
}

void EmbMsgBuffer::Add(EmbMsg &msg)
{
  //my_int_disable_usart0();
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize) Head = 0;
 // my_int_enable_usart0();

}

void EmbMsgBuffer::Get(EmbMsg &msg)
{
//t  if(++Tail < BuffSize) 
   Tail++;
    if(Tail == BuffSize)
	{
		Tail = 0;
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[BuffSize-1].body[i];
	}
   else 
   	{
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[Tail-1].body[i];
	}
}

unsigned  short EmbMsgBuffer::Used()
{
  int n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
}

unsigned  short EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}
struct Emb2TypeVer
{
//	unsigned type;
//	unsigned softVer;
//	unsigned ctrlNumber;
//	unsigned ctrlYear;
//	unsigned ctrlVer1;
//	unsigned ctrlVer2;
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
//EmbMsgBuffer rBuffEmbMsg;

#ifdef ETH_TRANZIT	

EmbMsgBuffer rBuffEmbMsgE;
EmbMsgBuffer rBuffEmbMsgEast;
EmbMsgBuffer rBuffEmbMsgWest;
#else  // ETH_TRANZIT
EmbMsgBuffer rBuffEmbMsg;
#endif // ETH_TRANZIT	
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

	EmbMsg embMsgEast;
	EmbMsg embMsgAns;
	EmbMsg embMsgTemp;

//	EmbMsgCover embMsgCoverRequest;

	EmbMsg *embMsgRequest;

//	EmbRS232 embRS232;	
//	EmbRS485 embRS485;

	EmbSerialMD34AVT embSerialACT155;

	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
  	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
 //	char s1[25],s2[25];
//port	unsigned char far* bt;
	unsigned char * bt;		 //??? need "far"
	unsigned  short addr1;

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
	unsigned  short err_tr=0;
	unsigned  short err_md=0;

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

  	int i232;
	unsigned  short aI, aS, aR;
//_________________________________________my
  unsigned long delay_transit;
//_________________________________________

  

//_________________________________________________________________________________



//void Enable() { asm { sti } }
//void Disable() { asm { cli } }

char * ultoa (unsigned long data, char * target, unsigned char format)
{
 sprintf(target, "%ld", data);
 return target;
}

char *  itoa (unsigned int data, char * target, unsigned char format)
{
 sprintf(target, "%d", data);
 return target;
}


union l2i
{
  unsigned long ul;
  unsigned short u[2];
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

// 186 specific
// this returns 32 bit value from 16bit*16bit
unsigned long mul (unsigned int a, unsigned int b)
	{
	return (a*b);
	}


 /* port
unsigned long mul (unsigned int a, unsigned int b)
	{
	unsigned long res;
	unsigned int *pt;
	pt=(unsigned int*)(&res);
	asm { push ax	;
				push dx	; }
	_AX=a; _DX=b;
	asm { mul dx ; }
	*pt=_AX;         // lower int returns in ax
	*(pt+1)=_DX;     // upper int returns in dx
	asm { pop dx	;
				pop	ax	; }
	return res;
	}

*/
// returns 64 bit value of result
// *(result) - lower unsigned long
// *(result+1) - upper unsigned long
// unsigned long*
// result - lower unsigned long

 unsigned long ulmul (unsigned long a, unsigned long b)
	{
	return (a*b);  
	}


/*

unsigned long ulmul (unsigned long a, unsigned long b)
	{
	unsigned int *pti;
	unsigned int mul1[2],mul2[2]; // mnojimoe i mnojitel
	unsigned long rspll,rsplh,rsphl,rsphh; //promejutochnye resultaty
	unsigned int rri[4];  //16 bit parts of result
	unsigned int carry;
	// lower byte
	pti=(unsigned int*)(&a); mul1[0]=*pti; mul1[1]=*(pti+1);
	pti=(unsigned int*)(&b); mul2[0]=*pti; mul2[1]=*(pti+1);
	rspll=mul(mul1[0],mul2[0]);
	rsplh=mul(mul1[0],mul2[1]);
	rsphl=mul(mul1[1],mul2[0]);
	rsphh=mul(mul1[1],mul2[1]);
	pti=(unsigned int*)(&rspll);
	rri[0]=*pti;  // lower int
//second int= rspll_upper+rsplh_lower+rsphl_lower
// carry in third int
	rri[1]=*(pti+1);
	pti=(unsigned int*)(&rsplh);
	asm { clc; }
	rri[1]=rri[1]+*pti;
	carry=_FLAGS&0x1;
	rri[2]=carry;
	pti=(unsigned int*)(&rsphl);
	asm { clc; }
	rri[1]=rri[1]+*pti;
	carry=_FLAGS&0x1;
	rri[2]=rri[2]+carry;
//third int = rsplh_upper+rsphl_upper+rsphh_lower+carry
	pti=(unsigned int*)(&rsplh);
	asm { clc; }
	rri[2]=rri[2]+*(pti+1);
	carry=_FLAGS&0x1;
	rri[3]=carry;
	pti=(unsigned int*)(&rsphl);
	asm { clc; }
	rri[2]=rri[2]+*(pti+1);
	carry=_FLAGS&0x1;
	rri[3]=rri[3]+carry;
	pti=(unsigned int*)(&rsphh);
	asm { clc; }
	rri[2]=rri[2]+*pti;
	carry=_FLAGS&0x1;
	rri[3]=rri[3]+carry;
// fourth int=rsphh+carry
	pti=(unsigned int*)(&rsphh);
	rri[3]=rri[3]+*(pti+1);
// prepare results
	unsigned long result[2];
	pti=(unsigned int*)(&result[0]);
	*pti=rri[0]; pti=pti+1;
	*pti=rri[1]; pti=pti+1;
	*pti=rri[2]; pti=pti+1;
	*pti=rri[3];
	unsigned long* pl; pl=&result[0];
	return result[0];
	// in pl - lower unsigned long of result in pl+1 - upper one
 }
	  */
// this returns 48 bit value
// unsigned int*
// this returns lower long of 48 bit structure
unsigned long ulmuli(unsigned long l, unsigned int i)
{
 return (l*i);
}

/*
unsigned long ulmuli(unsigned long l, unsigned int i)
{
	unsigned int* pti; 
	unsigned int iv; iv=i;
	pti=(unsigned int*)(&l);
	unsigned long rspl,rsph;
	unsigned int rri[3];
	rspl=mul(*pti,iv);
	pti=pti+1;
	rsph=mul(*pti,iv);
	pti=(unsigned int*)(&rspl);
	rri[0]=*pti;
	rri[1]=*(pti+1);
	pti=(unsigned int*)(&rsph);
	asm { clc; }
	rri[1]=rri[1]+*pti;
	rri[2]=_FLAGS&0x1;
	rri[2]=rri[2]+*(pti+1);
//	pti=&rri[0];
	unsigned long result;
	pti=(unsigned int*)(&result);
	*pti=rri[0];
	*(pti+1)=rri[1];
	return result;
	}
*/

unsigned long uldiv(unsigned long dividend, unsigned long divider)
{
 return (dividend / divider);
}
/*
unsigned long uldiv(unsigned long dividend, unsigned long divider)
{
	unsigned *ptrm,*ptdd;
	unsigned char shifts;
	unsigned long dd,dr,rm;
	dd=dividend; dr=divider;

	if((divider!=0)&&(dividend>=divider))
	{                          //divider!=0
		ptdd=(unsigned *)&dd;
		ptrm=(unsigned *)&rm;
		rm=0;

		shifts=32;
		unsigned int flag1,flag2;
// main loop

		do
		{
			if(*ptdd&0x8000) flag1=1;
			else flag1=0;

			*ptdd=(*ptdd<<1)&0xfffe;
			if(*(ptdd+1)&0x8000) flag2=1;
			else flag2=0;
			*(ptdd+1)=(*(ptdd+1)<<1)|flag1;
			if(*ptrm&0x8000) flag1=1;
			else flag1=0;
			*ptrm=(*ptrm<<1)|flag2;
			*(ptrm+1)=(*(ptrm+1)<<1)|flag1;

			if(rm>=dr)  { rm=rm-dr; *ptdd=*ptdd+1; }

			shifts--;
		}
		while (shifts>0);
	}
	else
	{
		if (divider==0) { dd=0xffffffff; rm=0xffffffff; } // divider==0
		else { dd=0; rm=0; }
	}
// prepare results
	unsigned long rs[2];
	unsigned long *ptrs;
	ptrs=&rs[0];
	rs[0]=dd;
	rs[1]=rm;
	return dd;
}
		   */
char *Probability2(unsigned long err, char *str, unsigned long time)
{
  //	unsigned t_err,t_time,tt,up,pp;
	unsigned tt,up,pp;
	int   pow=-1;
	time /=(unsigned long)(TIME_CORRECTOR);
	if(!time) time = 1l;
	if(err!=0)
	{
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		time = ulmuli(time,BIT_IN_FRAME);///100);
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		tt = uldiv(err,time);
		if(tt<10)
		{
			while(tt<10)
			{
				err = ulmuli(err,10);
				pow++;
				tt = uldiv(err,time);
				if(pow==0) break;
			}
		}
		else
		{
			if(tt>=100)
			{
				while(tt>=100)
				{
					err = uldiv(err,10);
					pow--;
					tt = uldiv(err,time);
					if(pow==0) break;
				}
			}
		}
	}
	else
	{
		pow=0;
		tt=0;
	}
//	t1=te/tt;
	up=(tt%100)/10;
	pp=tt%10;

	str[0]='0'+up;
	str[1]='.';
	str[2]='0'+pp;
	str[3]=' ';
	str[4]='E';
	str[5]='-';
	str[6]='0'+pow/10;
	str[7]='0'+pow%10;
	str[8]=0;
	return str;
}

char *ProbabilityPSP(unsigned long err, char *str, unsigned long time)
{
   //t	unsigned t_err,t_time,tt,up,pp;
	unsigned tt,up,pp;
	int pow=3;
	time /=(unsigned long)(TIME_CORRECTOR);
	if(!time) time = 1l;
	if(err!=0)
	{
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		time = ulmuli(time,205);
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		tt = uldiv(err,time);
		if(tt<10)
		{
			while(tt<10)
			{
				err = ulmuli(err,10);
				pow++;
				tt = uldiv(err,time);
				if(pow==0) break;
			}
		}
		else
		{
			if(tt>=100)
			{
				while(tt>=100)
				{
					err = uldiv(err,10);
					pow--;
					tt = uldiv(err,time);
					if(pow==0) break;
				}
			}
		}
	}
	else
	{
		pow=0;
		tt=0;
	}
//	t1=te/tt;
	up=(tt%100)/10;
	pp=tt%10;

	str[0]='0'+up;
	str[1]='.';
	str[2]='0'+pp;
	str[3]=' ';
	str[4]='E';
	str[5]='-';
	str[6]='0'+pow/10;
	str[7]='0'+pow%10;
	str[8]=0;
	return str;
}

void Delay(unsigned long ms01)
{
  unsigned long i,j;
  for(i=0; i<100; i++)
    for(j=0; j<100; j++);
}
/*
class EmbTreeACT : public EmbTree
{
    unsigned char rate[3];
    unsigned char rate1[3];
    unsigned char rate2[3];
    unsigned char rate3[3];

	public:
		unsigned long com_err1;
		unsigned long com_err2;
		unsigned long com_psp;
    unsigned long com_psp_last_read;
	  unsigned long err1;
	  unsigned long err2;
		void ClearErr1() { err1 = 1; }
		void ClearErr2() { err2 = 1; }
		unsigned long Err1() { return err1; }
		unsigned long Err2() { return err2; }
    unsigned short Inport(int short  port);// { return inport(port); }
   unsigned char Inportb(int short port);// { return inportb(port); }
//    void Outport(int port,unsigned value) { outport(port,value); }
    void Outportb(int short port, unsigned char value); //{ outportb(port,value); }
    void Out(int short  port, unsigned char value);
    void Init2();
    void SaveStateACT34();
    void RestoreStateACT34();
};

void EmbTreeACT::Init2()
{
  int i=0; 
  for(i=0; i<3; i++) rate[i]=rate1[i]=rate2[i]=rate[3]=0;
}
  */
int FindFree8k(int istart, unsigned char *r)
{
  int i;
  for(i=istart; i<24; i++)
  {
    if(i<8) 
    {
      if(!((r[0]>>i)&0x01)) return i;
    }
    if((i>=8)&&(i<16)) 
    {
      if(!((r[1]>>(i-8))&0x01)) return i;
    }
    if((i>=16)&&(i<24)) 
    {
      if(!((r[2]>>(i-16))&0x01)) return i;
    }
  }
  return 0xFF;
}

int SetBusy8k(int i, unsigned char *r)
{
  if(i<8) 
    if(!(r[0]>>i))
    {
      r[0]|=(0x01<<i);
      return 1;
    }
    else 
      return 0;
  if((i>=8)&&(i<16)) 
    if(!(r[1]>>(i-8)))
    {
      r[1]|=(0x01<<(i-8));
      return 1;
    }
    else 
    {
      return 0;
    }
  if((i>=16)&&(i<24)) 
    if(!(r[2]>>(i-16)))
    {
      r[2]|=(0x01<<(i-16));
      return 1;
    }
    else 
      return 0;
}



void save_e14_reg(int l_base, int h_base, int window, unsigned addr, unsigned char value)
{
  outportb(l_base,addr&0xFF);
  outportb(h_base,(addr>>8)&0xFF);
  outportb(window,value);
}

unsigned char load_e14_reg(int l_base, int h_base, int window, unsigned addr)
{
  outportb(l_base,addr&0xFF);
  outportb(h_base,(addr>>8)&0xFF);
  return inportb(window);
}
/*
void EmbTreeACT::Outportb(int port, unsigned char value)
{
	unsigned char  *ctrl;
   //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

  if(port==0x646)
  {
		if(value&0x20)
		{
		  com_err1=0;
		  com_err2=0;
		  com_psp = com_psp - com_psp_last_read;
		}
    psp_number = value&0x1F;
  }

  if(port==0x649) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    *(ctrl+64)=value;
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    *(ctrl+65)=value;
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    *(ctrl+66)=value;
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    *(ctrl+67)=value;
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    *(ctrl+68)=value;
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
  {
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    *(ctrl+69)=value;
    Out(0x64E,*(ctrl+69));
  }
  if(port==0x64F) Out(port,value);
  if(port==0x650) Out(port,value);
  if(port==0x651) Out(port,value);
  if(port==0x652) Out(port,value);

  outportb(port,value);
}

void EmbTreeACT::Out(int port, unsigned char value)
{
  int i=0, n=0, true_value=0, num8k=0, temp_b=0;
 unsigned char  *ctrl;
  	ctrl = (unsigned char *)(NVRAM_BASE + 0x100);
 //	unsigned char far *ctrl;
 //	ctrl = (unsigned char far*)0x80000100;

  if(port==0x649) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
    switch(value)
    {
      case 0: true_value=0; num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate1);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate1[i];  
        ctrl[i]=rate[i];
        ctrl[i+3]=rate1[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x010,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x020,rate1[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x021,rate1[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x022,rate1[2]); // коммутатор
    }
    else
    {
      for(i=0; i<3; i++)
      {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
      }
    }
	}
  if(port==0x64A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x008,true_value); // Тип	
  }
  if(port==0x64B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF) 
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate2);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate2[i];  
        ctrl[i]=rate[i];
        ctrl[i+6]=rate2[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x110,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x120,rate2[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x121,rate2[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x122,rate2[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
      }
	}
  if(port==0x64C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x108,true_value); // Тип
  }
  if(port==0x64D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate3[i]; // сбросили предыдущую установку общей
      rate3[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {  
        SetBusy8k(n, rate);
        SetBusy8k(n, rate3);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate3[i];  
        ctrl[i]=rate[i];
        ctrl[i+9]=rate3[i];
      }
      save_e14_reg(0x510,0x511,0x51F,0x010,true_value); // Скорость
      save_e14_reg(0x510,0x511,0x51F,0x020,rate3[0]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x021,rate3[1]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x022,rate3[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
        rate[i]^=rate3[i]; // сбросили предыдущую установку общей
        rate3[i]=0;        // скорости занятой этим каналом/
      }
	}
  if(port==0x64E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x510,0x511,0x51F,0x008,true_value); // Тип
  }
  if(port==0x64F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
    outportb(0x507,0x94); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
	}
  if(port==0x650) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
    outportb(0x507,0x84); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	}
  if(port==0x651) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[50,0]
	{
    outportb(0x507,0x95); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
	}
  if(port==0x652) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
    outportb(0x507,0x85); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	}
}

unsigned EmbTreeACT::Inport(int port)
{
  if(port==0x618)
	{
		if(com_psp>0xFFFF) return 0xFFFF;
		else return 1234;//com_psp;
	}
  if(port==0x61A)
	{
		if(com_err1>0xFFFF) return 0xFFFF;
		else return 1234;//com_err1;
	}
  if(port==0x61C)
	{
		if(com_err2>0xFFFF) return 0xFFFF;
		else return 2345;//com_err2;
	}
	return 5;
	return inport(port);	
}

unsigned char EmbTreeACT::Inportb(int port)
{
  int i=0;
  unsigned char true_value=0;
  if(port==0x658)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF00;
	}
  if(port==0x659)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF;
	}
  if(port==0x65A)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF;
	}
  if(port==0x65B)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF00;
	}
  if(port==0x65C)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF;
	}
  if(port==0x65D)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF00;
	}
/////
  if(port==0x649) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
    switch(load_e14_reg(0x520,0x521,0x52F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;
	}
  if(port==0x64A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
    switch(load_e14_reg(0x520,0x521,0x52F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
	}
  if(port==0x64B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
    switch(load_e14_reg(0x520,0x521,0x52F,0x110))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
  }
  if(port==0x64C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
    switch(load_e14_reg(0x520,0x521,0x52F,0x108))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
  }
  if(port==0x64D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
    switch(load_e14_reg(0x510,0x511,0x51F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
  }
  if(port==0x64E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
    switch(load_e14_reg(0x510,0x511,0x51F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
  }
  if(port==0x64F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x01;
    if(true_value) return 1; 
    else return 0;
	}
  if(port==0x650) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
    outportb(0x507,0xA0); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	}
  if(port==0x651) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[336,0]
	{
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x02;
    if(true_value) return 1; 
    else return 0;
	}
  if(port==0x652) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
    outportb(0x507,0xA1); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	}
/////
	  return inportb(port);	
}
  */
char *add_str(char *target, char *source)
{
	int j=0,i=0; 
	while(target[i]) i++;
	while(source[j]) target[i+j]=source[j++];
	return target;
}
 //port	EmbNMI2 embNMI2;

 //port	EmbTreeACT embTree;
 EmbTree embTree;



	EmbRS232 embRS232;
	EmbRS485 embRS485;
	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////
/* port
void LowTiming()
{
 port	outport(syscon,0x8501);
}

void SetWatchDog()
{
	outport(wdtcon,0x3333);
	outport(wdtcon,0xCCCC);
	outport(wdtcon,0xC080);
}

void DisableWatchDog()
{
	outport(wdtcon,0x3333);
	outport(wdtcon,0xCCCC);
	outport(wdtcon,0x0000);
}

void ResetWatchDog()
{
	outport(wdtcon,0xAAAA);
	outport(wdtcon,0x5555);
}
  */

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
void AsciiInit()   //need call this in init
{
//0
for(int i = 0; i <= 13; i++)
{
 ascii[i] = 0x20;
}
ascii[14] = 0xD5;  ascii[15] = 0xDA; 

//16
ascii[16] = 0x20;	 ascii[17] = 0x20;	 ascii[18] = 0x32;
for(i = 19; i <= 32; i++)
{
 ascii[i] = 0x20;
}
for(i = 33; i <= 62; i++)
{
 ascii[i] = (i);
}
 ascii[63] = 0x20;

for(i = 64; i <= 91; i++)
{
 ascii[i] = (i);
}
ascii[92] = 0x20;	 ascii[93] = 0x5d;	 ascii[94] = 0x5e;	 ascii[95] = 0x20;
//96
for(i = 96; i <= 127; i++)
{
 ascii[i] = (i);
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

ascii[167] = 0xfd;
//ascii[167] = 0xfe; //test


 ascii[168] = 0xa2;

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
ascii[196] = 0xe0;	ascii[197] = 0x45;	 ascii[198] = 0xa3;	 ascii[199] = 0xa4;//0xc4;
ascii[200] = 0xa5;  ascii[201] = 0xa6;	 ascii[202] = 0x4b;	 ascii[203] = 0xa7;//t 0xa7;
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
  if((s<=9)) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 0;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Callback0()
{
  time1++;
  time2++;
  time3++;
   time1p++;
  time2p++;
  time3p++;

	timeRing++;
	timeRing2++;
}

EmbTimerCallback embTimerCallback0;



/*
const PT_NULL    = 0;
const PT_ERR1    = 1;
const PT_ERR2    = 2;
const PT_ERR_PSP = 3;
const PT_CTRL    = 4;
const PT_RING    = 5;
const PT_SOUND   = 6;
const PT_ADDR    = 7;
const PT_POINT   = 8;
const PT_CALIBR  = 9;
*/


struct EmbChanACT
{
	unsigned char signal	   : 1;
	unsigned char hdb	   : 1;
	unsigned char ais	   : 1;
	unsigned char reserv1   : 1;
	unsigned char type_sign : 2;
	unsigned char mode_sign : 1;
	unsigned char reserv2   : 1;
};

union UnChanACT
{
	unsigned char byte;
	EmbChanACT chan;
};

struct EmbStateACT
{
	unsigned char seach1		: 1;
	unsigned char seach2		: 1;
	unsigned char error1		: 1;
	unsigned char error2		: 1;
	unsigned char alarm		: 1;
	unsigned char ring			: 1;
	unsigned char ais1     : 1;
	unsigned char ais2     : 1;
};

union UnStateACT
{
	unsigned char byte;
	EmbStateACT state;
};

struct EmbStateRes
{
	unsigned char receive	   : 1;
	unsigned char reserv_mode : 1;
	unsigned char reserv_type : 1;
	unsigned char res1		     : 5;
};

union UnStateRes
{
	unsigned char byte;
	EmbStateRes state;
};
 /*
void EmbTreeACT::SaveStateACT34()
{
	int i;
	unsigned char far *ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
  *(ctrl+64) = Inportb(0x649);
  *(ctrl+65) = Inportb(0x64A);
  *(ctrl+66) = Inportb(0x64B);
  *(ctrl+67) = Inportb(0x64C);
  *(ctrl+68) = Inportb(0x64D);
  *(ctrl+69) = Inportb(0x64E);
  *(ctrl+70) = Inportb(0x64F);
  *(ctrl+71) = Inportb(0x650);
  *(ctrl+72) = Inportb(0x651);
  *(ctrl+73) = Inportb(0x652);
}

void EmbTreeACT::RestoreStateACT34()
{
	unsigned i, j, com;
	unsigned char far *ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) outportb(0x640+i,*(ctrl+i));
	outportb(0x640,(*ctrl)&0x7F);
  Outportb(0x649,*(ctrl+64));
  Outportb(0x64A,*(ctrl+65));
  Outportb(0x64B,*(ctrl+66));
  Outportb(0x64C,*(ctrl+67));
  Outportb(0x64D,*(ctrl+68));
  Outportb(0x64E,*(ctrl+69));
  Outportb(0x64F,*(ctrl+70));
  Outportb(0x650,*(ctrl+71));
  Outportb(0x651,*(ctrl+72));
  Outportb(0x652,*(ctrl+73));
}
  */
struct EmbStateResNew // 0x504
{
	unsigned char receive_lc	    : 2;
	unsigned char  reserv_type_lc : 1;
	unsigned char res1		        : 1;
	unsigned char receive_rm	    : 2;
	unsigned char reserv_type_rm : 1;
	unsigned char res2		        : 1;
};

union UnStateResNew
{
	unsigned char byte;
	EmbStateResNew state;
};

char *UpdateStatusBar(char *str)
{
	int i;
 //	UnChanACT u;
	UnStateACT us;
	unsigned char byte;
	for(i=0; i<24; i++) str[i] = ' ';
	str[0]='1';
	str[4]='2';

	us.byte = inportb(0x641);

	if(us.state.seach1) str[1]='+';
	if(us.state.seach2) str[5]='+';
	if(!us.state.error1) str[1]='е';
	if(!us.state.error2) str[5]='е';
	if(!us.state.seach1) str[1]='-';
	if(!us.state.seach2) str[5]='-';
	if(!us.state.ais1) str[1]='a';
	if(!us.state.ais2) str[5]='a';

	byte = inportb(0x644);
	if(byte&0x01) str[2]='*';
	else str[6]='*';

	byte = inportb(0x644);
	if(byte&0x02) str[3]='=';
	else 
	{
		if(byte&0x01) str[3]='>';
		else str[3]='<';
	}

	str[24]=0; 	

	return str; 	
}

struct EmbActAlarm // 0x503
{
	unsigned fap_pd_lc : 1; 
	unsigned fap_pm_lc : 1; 
	unsigned fap_pd_rm : 1; 
	unsigned fap_pm_rm : 1; 
	unsigned input_rm1 : 2; 
	unsigned input_rm2 : 2; 
};

union UnACTAlarm
{
	unsigned char byte;
	EmbActAlarm chan;
};

struct EmbActIden
{
	unsigned char  iden1 : 4; 
	unsigned char iden2 : 4; 
};

union UnActIden
{
	unsigned char byte;
	EmbActIden chan;
};


struct EmbActAlarmState  // 0x642
{
	unsigned char input_lc1 : 2; 
	unsigned char input_lc2 : 2; 
	unsigned char dev_type	 : 1; 
	unsigned char remote		 : 1; 
	unsigned char alarm_lc  : 1; 
	unsigned char alarm_rm  : 1; 
};

union UnACTAlarmState //0x642
{
	unsigned char byte;
	EmbActAlarmState chan;
};

struct EmbChanACTNew
{
	unsigned char local		 : 2;
	unsigned char remote		 : 2;
	unsigned char input		 : 2;
	unsigned char mode_sign : 1;
	unsigned char reserv    : 1;
};

union UnChanACTNew
{
	unsigned char byte;
	EmbChanACTNew chan;
};

struct EmbE3ACTNew
{
	unsigned char Input1		  : 2;
	unsigned char Input2		  : 2;
	unsigned char dev_type	  : 1;
	unsigned char inf_remote : 1;
	unsigned char lc_alarm   : 1;
	unsigned char rm_alarm   : 1;
};

union UnE3ACTNew
{
	unsigned char byte;
	EmbE3ACTNew chan;
};

struct EmbE3User
{
	unsigned char lc		  : 2;
	unsigned char rm		  : 2;
	unsigned char reserv : 4;
};

union UnE3User
{
	unsigned char byte;
	EmbE3User chan;
};

char *UpdateStatusBarNew(char *str)
{
	int i;
  //	UnChanACTNew u;
	UnE3ACTNew us;
	UnStateResNew ur;
	unsigned char byte;
	for(i=0; i<24; i++) str[i] = ' ';
	str[0]='1';
	str[4]='2';

	us.byte = inportb(0x642);

	switch(us.chan.Input1)
	{
		case 0: str[1]='+'; break;
		case 1: str[1]='e'; break;
		case 2: str[1]='-'; break;
		case 3: str[1]='a'; break;
	}
  if(ACT_type)
	{
		switch(us.chan.Input2)
		{
  		case 0: str[5]='+'; break;
  		case 1: str[5]='e'; break;
  		case 2: str[5]='-'; break;
  		case 3: str[5]='a'; break;
		}
		byte = inportb(0x644);
		str[6]=' ';
		if(byte&0x02) str[6]='*';
		else str[2]='*';
	
		ur.byte = inportb(0x644);
		switch(ur.state.receive_lc)
		{
		  case 0: str[3]='='; break;
		  case 1: str[3]='>'; break;
		  case 2: str[3]='='; break;
		  case 3: str[3]='<'; break;
		}
	}
	str[7]=' ';
	str[8]='E';
	str[9]='3';
	str[10]='м';
	str[11]='[';
	str[13]=']';
	UnE3User ue3;
	ue3.byte=inportb(0x648);
	switch(ue3.chan.lc)
	{
		case 0: str[12] = '+'; break;
		case 1: str[12] = 'с'; break;
		case 2: str[12] = 'о'; break;
		case 3: str[12] = '-'; break;
	}
	str[15]=' ';
	str[16]=' ';
	str[17]=' ';
	str[18]='E';
	str[19]='3';
	str[20]='у';
	str[21]='[';
	str[23]=']';
	switch(ue3.chan.rm)
	{
		case 0: str[22] = '+'; break;
		case 1: str[22] = 'с'; break;
		case 2: str[22] = 'о'; break;
		case 3: str[22] = '-'; break;
	}

	str[24]=0; 	
////  DEBUG
/*  
	str[0] = HexChar(debug_byte>>4);
	str[1] = HexChar(debug_byte&0x0F);
	str[3] = HexChar((debug_word>>12)&0x0F);
	str[4] = HexChar((debug_word>>8)&0x0F);
	str[5] = HexChar((debug_word>>4)&0x0F);
	str[6] = HexChar(debug_word&0x0F);
*/
////
  return str; 	
}


int UpdateState()
{
  unsigned char byte;
	char flag = 0;
	char i;
  //	UnChanACT u;
 //	UnStateACT us;
  UnACTAlarmState uas;
	uas.byte = inportb(0x642);

	state = ST_NORMA;

	for(i=0; i<16; i++)
	{
		if((inportb(0x648+i)&0x03)!=0x03) flag = 1;
	}
	if(!flag) state = ST_LOOP;

	switch(uas.chan.input_lc1)
	{
		case 1: state = ST_ERROR1; break;
		case 2: state = ST_ERROR1; break;
		case 3: state = ST_ERROR1; break;
	}
  if(ACT_type)	//hier "1"
	{
		byte = inportb(0x644);
		if(byte&0x02)
		{

		  switch(uas.chan.input_lc2)
			{
				case 1: state = ST_ERROR1; break;
				case 2: state = ST_ERROR1; break;
				case 3: state = ST_ERROR1; break;
			}
		}
	}
	UnActIden uai;
	unsigned char self_id = inportb(0x640)&0x0F;
	uai.byte = inportb(0x641);
  //	if(!uas.chan.input_lc1)
	  
	if(!uas.chan.input_lc1)
	{
		if(self_id)
		{
			if(uai.chan.iden1) if(uai.chan.iden1!=self_id) state = ST_FAULT;
			if(uai.chan.iden2) if(uai.chan.iden2!=self_id) state = ST_FAULT;
		}
	}
	if(!uas.chan.input_lc2)
	{
		if(self_id)
		{
			if(uai.chan.iden1) if(uai.chan.iden1!=self_id) state = ST_FAULT;
			if(uai.chan.iden2) if(uai.chan.iden2!=self_id) state = ST_FAULT;
		}
	}
	 
	if(uas.chan.alarm_lc) state = ST_ALARM;

	return state;
}

int sndRing=0;		  //need init!!!
int sndAlarm=0;
int sndLock=0;

void MakeSoundLock()
{
	sndLock=1;
	embIndicator.Sound0(0x00);
	sndAlarm=0;
}

void MakeSoundUnLock()
{
	sndLock=0;
	sndAlarm=0;
}

void MakeAlarm()
{
//return; //t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(!sndAlarm)
	{
	  if(!sndLock) embIndicator.SoundAlarm();
	  sndAlarm=1;
	}
}

void MakeRing()
{
//return; //t
 //	if(!sndRing) 
  	if((!sndRing) && (!sndLock)) //my
	{
		embIndicator.SoundRing();
		sndRing=1;
	}
}

void NoMakeRing()
{
//	if(!sndAlarm)
		if(sndRing)
		{
			embIndicator.Sound0(0x00);
			sndRing=0;
			sndAlarm=0;
		}
}

void NoMakeAlarm()
{
	if(sndAlarm)
	{		
		embIndicator.Sound0(0x00);
		sndAlarm=0;
		sndRing=0;
	}
}


//int IsRing()

void IsRing(void)
{
	ringBliker++;
  	if((inportb(0x640)&0x40))
  //	if(1)		//t
	{
		timeRing2=0;
    	MakeRing();
		if(ringBliker%2) embIndicator.SetLtDiod(1,4);
		else embIndicator.SetLtDiod(0,4);
	}
	else 
	{
		NoMakeRing();
		if(timeRing2<20)
		{
		  if(ringBliker%2) embIndicator.SetLtDiod(1,4);
		  else embIndicator.SetLtDiod(0,4);
		}
		if(timeRing2==20)	embIndicator.SetLtDiod(0,4);
		if(timeRing2>20) timeRing2=60;
	}
  if(ringOn&&(timeRing>=5))
	{
		unsigned char port500 = inportb(0x640);
		outportb(0x640,0x0F&port500);
		ringOn=0;
	}
}

char* sec2time(unsigned long t, char* str)
{
	char ch[12];
	str[0]=0;
	t /= 1000l;	 //my
	unsigned long h = uldiv(t,3600);
	unsigned long m = ((unsigned)t/60)%60;
	unsigned long s = (unsigned)t%60;
	if(h<10) add_str(str,"0");
  add_str(str,ultoa(h,ch,10));
	add_str(str,":");
	if(m<10) add_str(str,"0");
  add_str(str,ultoa(m,ch,10));
	add_str(str,":");
	if(s<10) add_str(str,"0");
  add_str(str,ultoa(s,ch,10));
	return str;
}

void SetAddrAKM(unsigned char addr)
{
  unsigned i;
  // Первый канал уровень ПД
  outportb(0x507,0x80); 
 	for(i=0; i<20000; i++);
  outportb(0x507,0x80);
 	for(i=0; i<20000; i++);
  outportb(0x507,0x98);
 	for(i=0; i<20000; i++);
  outportb(0x507,addr);
 	for(i=0; i<20000; i++);
}

//void main()

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



    char ch;
	long f_len;
	unsigned r=0;
	unsigned long j=0;
	unsigned pt_key=0;
	char a[128];
	char c[128];
	unsigned long ttt=0,last_err=0;;
	char start_flag=1;
	int ctrl_flag;
	int cursor_flag;	 //my

	int ctrl_counter=0;
	int no_blink=1, color=1;
	int old_color=1;
	int old_state=0;
	int err_mode=0;
	int err_flag=0;
	int psp_mode=0;
	int psp_flag=0;
	int psp_flag_counter=0,psp_flag_counter1=0,psp_flag_counter2=0;
	int calib_flag_start=0,calib_flag_end=0;
  int flagDir485;
	unsigned char dev_addr=0, dev_point=0;
	unsigned char dev_prot=0;
	int addr_flag=0;
	int point_flag=0;
	unsigned char port500=0;
/////////  DEBUG SECTION  //////////
	int tempDeb = 0;
	char chDeb[32];






 char dpdfile[DPD_SIZE];
 char  *dpd; 

 unsigned long p=0;
	char str[25];
	char s1[64];
	char s2[128];
	char sk[64];
	char chk;
	EmbTreePoint *current;
	EmbTreePoint *parent;


unsigned r1;
	unsigned k=0,b=0,key=0;

 EmbCommand embCommand1;
 EmbCommand embCommand2;
 EmbCommand embCommand3;
 EmbCommand embCommand4;

 EmbSerialACT8Send embSend;
 EmbSerialACT8Receive embReceive;  // EmbSerialACT8Receive
 char init_display;		   
//____________________________________________________________________________
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


//==================================================================================
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
			AddCharWestE(westByte);
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
 
				if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
				{
						// передаем побайтно дальше принимаем пакет

		   if(buff_cashe_tranzit.compare((unsigned long)embMsgWest.body[1], (unsigned long)embMsgWest.AddrS(), (unsigned long)embMsgWest.AddrI(), (unsigned long)embMsgWest.AddrR(), (unsigned long)embMsgWest.IsRS485()) != 1)
   		 //  	if(1)
   		   	{
		 	 buff_cashe_tranzit.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR());

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
  /* 
 if(
 !((embMsgWest.body[1] == old_embMsgWest_number) &&
  (embMsgWest.AddrS()== old_embMsgWest_addrs) &&
   (embMsgWest.AddrI()== old_embMsgWest_addri))
   )
   {
  //  printf("w+");
 	   SendWestTransitToEth();
	   old_embMsgWest_number = embMsgWest.body[1];
	   old_embMsgWest_addrs =  embMsgWest.AddrS();
	   old_embMsgWest_addri = embMsgWest.AddrI();
   }
   */
   
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
	  tBuffEmbMsgEthAll1.Add(embMsgWest);	  //t0129

  //t0129 	 SendWestTransitToEth();
 	 buff_cashe.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR());
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
					
				if(embMsgWest.AddrS()==SelfID())
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
				recieveWest = 0;
#ifdef ETH_TRANZIT
			    InitWestE();	 //clear!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif //  ETH_TRANZIT
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
		AddCharEastE(eastByte); //t
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



			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{

   if(buff_cashe_modem.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
 //  			 if(1)
   		   	{
   			 buff_cashe_modem.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR());
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
/*
if(embMsgEast.body[1] != old_embMsgEast_number)
   {
				SendEastTransitToEth();
				old_embMsgEast_number = embMsgEast.body[1];
   }
	*/
 /*
if(
 !((embMsgEast.body[1] == old_embMsgWest_number) &&
  (embMsgEast.AddrS()== old_embMsgWest_addrs) &&
   (embMsgEast.AddrI()== old_embMsgWest_addri))
   )
   {
  //  printf("e+");
 	   SendEastTransitToEth();
	   old_embMsgWest_number = embMsgEast.body[1];
	   old_embMsgWest_addrs =  embMsgEast.AddrS();
	   old_embMsgWest_addri = embMsgEast.AddrI();
   }
   */

  
  if(buff_cashe.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
   {
    tBuffEmbMsgEthAll.Add(embMsgEast);	  //t0129
	 tBuffEmbMsgEthAll1.Add(embMsgEast);	  //t0129


  //t0129 	 SendEastTransitToEth();
  	 buff_cashe.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR());
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
			
			if(embMsgEast.AddrS()==SelfID())
			{
		   //		printf("\n\r CRC : %X CalcCRC : %X" , embMsgEast.CRC(), embMsgEast.CalcCRC());
				embMsgEast.SetDir(2);
#ifdef ETH_TRANZIT
				rBuffEmbMsgEast.Add(embMsgEast);
#else //ETH_TRANZIT
				    rBuffEmbMsg.Add(embMsgWest);
#endif //ETH_TRANZIT

				embMsgEast.Init();
			}
#ifdef ETH_TRANZIT
		InitEastE();  //clear!!!!
#endif // ETH_TRANZIT
		}	 //is end


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
#ifdef ETH_TRANZIT
/*
	if(tBuffEmbMsgEthEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEthEast.Get(embMsgA);
				
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

	   */
 #endif //ETH_TRANZIT


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


//==================================================================================

 
//____________________________________________________________________________




   	
 


////////////////////////////////////
void InitTLF()
{
	int i;

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
}

void Ring()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a272[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a272); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a271); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a27); i++);
  outportb(0x511, 0x00); // оn hook
}
void Active()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a222); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x50F, a26[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a261); i++) outportb(0x50F, a261[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a261); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a262); i++) outportb(0x50F, a262[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a262); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause2()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a263); i++) outportb(0x50F, a263[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a263); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a264); i++) outportb(0x50F, a264[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a264); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a265); i++) outportb(0x50F, a265[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a265); i++);
	outportb(0x511, 0x00); // off hook
}

void Wait()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a222); i++);
//	outportb(0x510, 0x02); for(i=0; i<sizeof(a28); i++) outportb(0x50F, a28[i]); outportb(0x510, 0x01); for(i=0; i<TLF_DELAY*sizeof(a28); i++);
	outportb(0x511, 0x00); // on hook
}

void Read()
{
// Пример  передачи/приема по SPI
// outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01);
// while((inportb(0x510) & 0x01)!=0);
// чтение принятых байтов  по адресу  0x50F принимается столько же байт сколько и  передается
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(aa); i++) outportb(0x50F, aa[i]); outportb(0x510, 0x01); inportb(0x510); for(i=0; i<20*sizeof(aa); i++);
	for(i=0; i<7; i++) aaa[i] = inportb(0x50F);
	
}



//================================================================================================
#ifdef ETH_TRANZIT

extern  EmbRS232 trnzRS232;

void ProtocolToEth()
{	  
 static char used_buffer = 0;
 //tif(tBuffEmbMsgEthAll.Used())
if(!used_buffer)
{
 used_buffer = 1;

    while(tBuffEmbMsgEthAll.Used())	//t
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEthAll.Get(embMsgA);

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
		  	 buff_cashe_tranzit.add(embMsgEthTransitW.body[1], embMsgEthTransitW.AddrS(), embMsgEthTransitW.AddrI(), embMsgEthTransitW.AddrR());
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
		  	 buff_cashe_modem.add(embMsgEthTransitW.body[1], embMsgEthTransitW.AddrS(), embMsgEthTransitW.AddrI(), embMsgEthTransitW.AddrR());
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
			 	   	
				if(embMsgEthTransitW.AddrS()==SelfID())
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

//================================================================================================




extern "C" void Init_BMD34(void)
{

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



delay_transit = 0;
 EmbInit(); //my
 AsciiInit();
 time1=0;
 time2=0;
 time3=0;
 time1p=0;
 time2p=0;
 time3p=0;

 //time4=0;
 //time5=60;
 //flagADUC1=0;
 //flagADUC2=0;

 //________________________________________
	flagRequest=0;
   stemp = 0; //? my
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
 
   HighID=0;
   countSend=0;
   countRecv=0;
   time3highID=0;

  	mode5A=0;
	mode5AWest=0;
	mode5AEast=0; 
	mode5A485=0;
	mode5A232E=0;
	mode5A485E=0; 




	cycle=0;

	ttbb=0;
	mtbb=0;
	count_tr=0;
	count_md=0;
	err_tr=0;
	err_md=0;

 //________________________________________
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
  
	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();

 //	rBuffEmbMsg.Init();
#ifdef ETH_TRANZIT
    rBuffEmbMsgE.Init();
	rBuffEmbMsgEast.Init();
	rBuffEmbMsgWest.Init();
#else
	rBuffEmbMsg.Init();
#endif //ETH_TRANZIT


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

	int rrr=0;

	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=0;
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;
     unEmb2TypeVer.emb2TypeVer.type       = 0x0504;   //? - after make



  	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;	  //added ethernet support 232
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
  	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();	 //it was so
 	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();
 //  	unEmb2TypeVer.emb2TypeVer.ctrlVer1   =  read_xil_char(1);  //my
 //	unEmb2TypeVer.emb2TypeVer.ctrlVer1  =   read_xil_char(2);  //my
  //	my_printf ( read_xil_char(1));
  //	my_printf ( read_xil_char(2));

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

	embMsgTemp.Init();

	Wait();
//	Ring();
	presto_time = time1;
 //>>>>>>>>>>>>>>>>>>>>>>>>>Upper this need move to init


}



extern "C" void BMD34()
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


//	outportb(0x6FF,inportb(0x6FF)|0x10);
//______________________________________________________________test
//embSerialACT155.AddTransit(0x5A);

/*
static unsigned char tch = 0;
embSerialACT155.AddMod(tch);
tch++;
*/
/*  
unsigned char  rch;

if(embSerialACT155.UsedMod())
 {
  while(embSerialACT155.UsedMod())
  {
  rch = embSerialACT155.GetMod();
  printf("%c", rch);
  }

 }
 else
  {
 //  printf("\r Buffer Empty...");
  }
 */  	 
//______________________________________________________________test

///////  Канал транзит  ///////
//	time5=0;
//	outportb(0x5B7, 0x94);
///////////////////////////////
  //	while(1)
 // if(1)	//to get to another main loop
 //	{

 //		ResetWatchDog();
/////////  Плата интерфейсов  ///////////
//	unsigned temp1, temp2;
// 526-527	Счётчик ошибок после комбинатора	16 бит
// 528-52A	Счётчик ошибок, исправленных РС в 1 стволе	24 бит
// 52B-52D	Счётчик ошибок, исправленных РС в 2 стволе	24 бит
// 52E-52F	Счётчик ошибок не исправленных РС в 1 стволе	16 бит
// 530-531	Счётчик ошибок не исправленных РС в 2 стволе	16 бит
// 532-533	Счётчик числа принятых пакетов	16 бит
   /* temporary
	err_tmp = (unsigned long )inportb(0x526) + ((unsigned long )inportb(0x527)<<8);
	if(err_tmp>=count_no_correct_result) unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result;
	else unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result + 0x10000;
	count_no_correct_result = err_tmp;
	unStatePUM.statePUM.ulErrOut = err_tmp;
//	if(err_tmp>=count_no_correct_result) count_no_correct_result = err_tmp - count_no_correct_result;
//	else count_no_correct_result = count_no_correct_result - err_tmp;

	err_tmp = (unsigned long )inportb(0x532) + ((unsigned long )inportb(0x533)<<8);
	if(err_tmp>=count_block) unStateBMD155.stateBMD155.count_block = err_tmp - count_block;
	else unStateBMD155.stateBMD155.count_block = err_tmp - count_block + 0x10000;
	count_block = err_tmp;
	unStatePUM.statePUM.ulBlock = err_tmp;
//	if(err_tmp>=count_block) count_block = err_tmp - count_block;
//	else count_block = count_block - err_tmp;

	err_tmp = (unsigned long)inportb(0x52E) + ((unsigned long )inportb(0x52F)<<8);
	if(err_tmp>=count_notRS1)	unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1;
	else unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1 + 0x10000;
	count_notRS1 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS1 = err_tmp;
//	if(err_tmp>=count_notRS1)  count_notRS1= err_tmp - count_notRS1;
//	else count_notRS1 = count_notRS1 - err_tmp;

	err_tmp = (unsigned long )inportb(0x530) + ((unsigned long )inportb(0x531)<<8); 
	if(err_tmp>=count_notRS2) unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2;//count_notRS2;
	else unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2 + 0x10000;
	count_notRS2 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS2 = err_tmp;
//	if(err_tmp>=count_notRS2) count_notRS2 = err_tmp - count_notRS2;
//	else count_notRS2 = count_notRS2 - err_tmp;

	err_tmp = (unsigned long )inportb(0x528) + ((unsigned long )inportb(0x529)<<8) + ((unsigned long)inportb(0x52A)<<16);
	if(err_tmp>=count_no_correct_block1) unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1;
	else unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1 + 0x1000000;
	count_no_correct_block1 = err_tmp;
	unStatePUM.statePUM.ulErrBeforeRS1 = err_tmp;
//	if(err_tmp>=count_no_correct_block1) count_no_correct_block1 = err_tmp - count_no_correct_block1;
//	else count_no_correct_block1 = count_no_correct_block1 - err_tmp;

	err_tmp = (unsigned long )inportb(0x52B) + ((unsigned long )inportb(0x52C)<<8) + ((unsigned long)inportb(0x52D)<<16);
	if(err_tmp>=count_no_correct_block2) unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2;
	else unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2 + 0x1000000;
	count_no_correct_block2 = err_tmp; 
	unStatePUM.statePUM.ulErrBeforeRS2 = err_tmp;
//	if(err_tmp>=count_no_correct_block2) count_no_correct_block2 = err_tmp - count_no_correct_block2;
//	else count_no_correct_block2 = count_no_correct_block2 - err_tmp;
#ifndef PROG_BMD2  //bmd34
	unStatePUM.statePUM.state[0] = inportb(0x520);
	unStatePUM.statePUM.state[1] = inportb(0x521);
	unStatePUM.statePUM.state[2] = inportb(0x522);
	unStatePUM.statePUM.state[3] = inportb(0x523);
	unStatePUM.statePUM.state[4] = inportb(0x524);
	unStatePUM.statePUM.state[5] = inportb(0x525);
#else	//bmd2
 	unStatePUM.statePUM.state[0] =  ((inportb(0x522) & 0x2)<<2) + ((inportb(0x524) & 0x3)<< 6);
	unStatePUM.statePUM.state[1] = inportb(0x525) & 0x6;
  	unStatePUM.statePUM.state[2] = inportb(0x522);
	unStatePUM.statePUM.state[3] = inportb(0x523);
	unStatePUM.statePUM.state[4] = inportb(0x524);
	unStatePUM.statePUM.state[5] = inportb(0x525);
#endif

	//0 - 24
	//1 -22
   temporary */


	unStatePUM.statePUM.state[6] = 0;
	unStatePUM.statePUM.state[7] = 0;
	unStatePUM.statePUM.state[8] = 0;
	unStatePUM.statePUM.state[9] = 0;
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
//////////////////////////////////////////////////
	if(time1 - wait_time >=40) 
	{
  //	  printf("\n\r %ld", time1); //t

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
			unStateBMD155.stateBMD155.demPI = (unsigned short )tlf_number[1]*10+(unsigned  short )tlf_number[0];
			unStateBMD155.stateBMD155.statePI = tlf_number[1];

			//	if(tlf_counter>=2) 
   //0323			if(!(GetRemoteMode() & 1l))
			 if(GetRemoteMode() & 1l)
			{
				if(tlf_counter >= TLF_NUMBER_DIGITS_NEW) 
				{
		 //			if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == unEmb2TypeVer.emb2TypeVer.signature_software[1])
//010226					if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == EmbGetAddr())
					if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == EmbGetPoint()) //010226
					 // = self_tlf_number
					{
						presto = 1;
						presto_time = 0;
						presto_ring = 0;
						ring_counter = 0;
					}
					else
					{
						if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == 99) 
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
			else	  //!GetRemoteMode
			{
			if(tlf_counter >= TLF_NUMBER_DIGITS_OLD) 
				{
		 //			if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == unEmb2TypeVer.emb2TypeVer.signature_software[1])
//010226					if(((unsigned  short )tlf_number[1]*10+(unsigned  short )tlf_number[0]) == EmbGetAddr())
					if(((unsigned  short )tlf_number[2]*100+
					  (unsigned  short )tlf_number[1]*10+
					(unsigned  short )tlf_number[0])
					 == EmbGetPoint()) //010226
					 // = self_tlf_number
					{
						presto = 1;
						presto_time = 0;
						presto_ring = 0;
						ring_counter = 0;
					}
					else
					{
					   if(((unsigned  short )tlf_number[2]*100+
					  (unsigned  short )tlf_number[1]*10+
					(unsigned  short )tlf_number[0])
						 == 777) 
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
//////////////////////////////////////////////////
		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;
//////////////////////////////////////////////////
 //if(delay_transit < 2l)
   //		 {
	 //	  delay_transit++;
	   //	  return;
	   //	 }

  //t 		ProtocolFromModACT155();
  //t      ProtocolFromTransitACT155();
	 //	if((delay_transit) && (delay_transit - time1)) > 200l)
  //	 if(delay_transit > 200l)
 //bad  if(delay_transit > 50l)
  //    if(delay_transit > 50l)
	//	{
	   //	delay_transit = 0l;
//t 	Check2InitTransitMod();
	  //	}
  //		else
	//	{
  //		delay_transit++;
//		}
//////////////////////////////////////////////////
// 0323 if(!(GetRemoteMode() & 1l))
 if(GetRemoteMode() & 1l)
{
#ifdef ETH_TRANZIT
   if(EthReceiveTimer > EthReceiveDelay) //t
  {
   	ProtocolToEth();
  }
#endif // ETH_TRANZIT


#include checkremotemod.inc
#include answermod.inc

 	ProtocolFromModACT155();	 //090302
    ProtocolFromTransitACT155();	//090302

#ifdef ETH_TRANZIT
	ProtocolFromEthTransit();
#endif // ETH_TRANZIT

}
  //t	ProtocolFromModACT155();
 //t   ProtocolFromTransitACT155();
  	Check2InitTransitMod();
 // my_int_disable_irq0();
}

////////////////////////////////////
//}

 //unsigned char * ctrl;//t

extern "C" void InitSound(void)
{	
 if(EmbGetSound()) MakeSoundLock();
 else   MakeSoundUnLock();
}




extern "C" void LoadProvProg()
{
//hier be load programm file	
//  unsigned int cnt;
  char* CurrentDataPointer;
 // unsigned int ProvSizeToDownload    = ProvSizeToDownloadD; //0x1ffff;
  read_dataflash ((unsigned int)ProvDataAddressD, (unsigned int)ProvSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  CurrentDataPointer = (char *)((uint_32)(&TFTP_Buffer[0]));  
  //________________________
//hier add loading
//____________________________________________________
//init to doc pwg610_swg_J.pdf page 17.
//PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType);
PVG610_API_FirmwareFromHostBoot(0, (&TFTP_Buffer[0]), (UINT32 )ProvSizeToDownloadD,(PVG610_DEVICE_RESET_TYPE_ENUM) 0);	 // PVG610_DEVICE_RESET_ALL_E

//____________________________________________________



 //_________________________
}

extern "C" void LoadProvCfg()
{
//hier be load configuration file	
//hier be load programm file	
//  unsigned int cnt;
  char* CurrentDataPointer;
  //unsigned int ProvSizeToDownload    = ProvSizeToDownloadDCfg; //0x1ffff;
  read_dataflash ((unsigned int)ProvDataAddressDCfg, (unsigned int)ProvSizeToDownloadDCfg, (BYTE *)(&TFTP_Buffer[0]));
  CurrentDataPointer = (char *)((uint_32)(&TFTP_Buffer[0]));  
  //________________________
//hier add loading
//PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromHostLoad (BYTE                deviceIndex,
//                                    BYTE       modemIndex,
//                                    BYTE       *pBuffer,
//                                    UINT16     len) // in bytes
 PVG610_API_ConfigFileFromHostLoad (0,	0, (BYTE *)(&TFTP_Buffer[0]),(unsigned int)ProvSizeToDownloadDCfg); //in bytes
//_________________________
}



extern "C" void LoadProv()
{
//hier be load programm and configuration file	
  LoadProvProg();
  LoadProvCfg();
}

//unsigned char t_set, b_set;
unsigned char is_send;

extern "C" void Init_PROV()
{

 LoadProv(); //hier load programm and config for prov

	
 // t_set = 0;
 // b_set = 0;
  is_send = 0;
  init_display = 0;
  ttt=0;
  last_err=0;
  start_flag=1;
  ctrl_flag=0;
  cursor_flag = 0; //my
  ctrl_counter=0;
  no_blink=1; color=1;
  old_color=1;
  old_state=0;
	err_mode=0;
	err_flag=0;
	psp_mode=0;
	psp_flag=0;
	psp_flag_counter=0;psp_flag_counter1=0;psp_flag_counter2=0;
	calib_flag_start=0;calib_flag_end=0;
   //flagDir485;
	dev_addr=0; dev_point=0;
	dev_prot = 0;
	addr_flag=0;
	point_flag=0;
	port500=0;
/////////  DEBUG SECTION  //////////
	tempDeb = 0;

//________________________________________
//_________________________________________from main
 
//________________________________________________________________my_init
 sndRing=0;		  //need init!!!
 sndAlarm=0;
 sndLock=1;
 debug_byte=0;
 debug_word=0;
 ACT_type = 1;
 psp_number=0;	
 time1=0;
 time2=0;
 time3=0;
 timeRing=0;
 timeRing2=60;		  //need init!
 ringOn=0;				  //need init
 ringBliker=0;
 counterErrPSP=0;			//need init
// state;
//________________________________
  r=0;
  i=0;j=0;
  pt_key=0;



//_________________________
EmbInitNVRAM(); //081208
//_________________________
/// 
  unsigned char dbg = inportb(0x6FF);
  outport(0x6FF,dbg|0x10);
///
   /*to global

	char ch;
	long f_len;
	unsigned r=0;
	unsigned long i=0,j=0;
	unsigned pt_key=0;
	*/


/////  Plug&Play /////
//my : xilinx not get right   ACT_type = inportb(0x640)&0x20; 	
	outportb(0x646,0x40);
///////////////////////   Сброс ТЛФ блоков   //////////////////////////

  unsigned char tmp = inportb(INDICATOR_CTRL);
/*	outportb(INDICATOR_CTRL,tmp&0x80);		// Сброс
	for(i=0; i<100000; i++);
	outportb(INDICATOR_CTRL,tmp&0x00);
	for(i=0; i<100000; i++);
*/
//  InitAKM();
  SetAddrAKM(EmbGetPoint());

///////////////////////////////////////////////////////////////////////
//////////////////////
//	Init();
//	LowTiming();
//	ResetWatchDog();
//	SetWatchDog();
//  DisableWatchDog();
//	while(1);
//////////////////////
///  biTime1.Init();
///  biTime2.Init();
///  biTime3.Init();
//________________________________________________ from ktvm
	

//________________________________________________



	
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
  //port	embTimerCallback0.interval = 1000; 
	embTimerCallback0.interval = 1; //port 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
//////////////////////

  //	EmbTreePoint* embTP;
  //	WORD PointNum,DeviceNum;
  //t	WORD DeviceNum;

  InitFreePtr();
  AsciiInit();
  EmbInit();
  embIndicator.Init();
  //delay_mcs(1000l);
  embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
  embRS485.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

  //port 	char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
	ReadDPD(dpdfile);  //port
 //	dpd = (char *)0x10000000; // Адрес необходимо уточнить
	dpd = dpdfile;	//port


 //  printEthLongHex('0');

 // embTree.SetCfg(dpd,16384); // Инициализируем дерево меню и команд управления
 dpd_state =  embTree.SetCfg(dpd,16384);
 if(!dpd_state) return;	
//  printEthLongHex('1');
  embTree.Init2();
//   printEthLongHex('2');

 //to global  EmbSerialACT8Receive embReceive;  // EmbSerialACT8Receive
	embReceive.Init();
 //to global  EmbSerialACT8Send embSend;
	embSend.Init();
///////////////////////////////////////////////////////////////////////////////
 //port	embNMI2.Init();
/////////////  Инициализация последних байтов цикла обмена с АЦТ //////////////
	for(i=24; i<32; i++) outportb(0x640+i,0);
///////////////////////////////////////////////////////////////////////////////
//port 	Enable(); // Разрешаем все прерывания
///////////////////////////////////////////////////////////////////////////////
	 /*
	unsigned r1;
	unsigned k=0,b=0,key=0;
	  */

	k=0; b=0; key=0;
 // EmbCommand embCommand1;
  embCommand1.Init();
 // EmbCommand embCommand2;
  embCommand2.Init();
//  EmbCommand embCommand3;
  embCommand3.Init();

  embCommand4.Init();

//// Восстанавливаем состояние регистров АЦТ34 ////
  embTree.RestoreStateACT34();
  unsigned char *ctrl;
 //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

//port  if((*ctrl)&0x10) 
  
  	if(EmbGetSound())sndLock=1; //port // 1-выкл  0-вкл
	else sndLock=0; 
///////////////////////////////////////////////////
   /* to global
	unsigned long p=0;
	char str[25];
	char s1[64];
	char s2[128];
	char sk[64];
	char chk;
	EmbTreePoint *current;
	EmbTreePoint *parent;
	*/
	 p=0;	  //init


	for(i=0; i<25; i++) str[i]=0;
///////////////////////////////

	embTree.Down();
	current = embTree.Current();	
	parent = current->Parent();
	CreateASCIIZ(dpd+embTree.Company(),str);
	add_str(str,"  ");
	CreateASCIIZ(dpd+embTree.City(),s2);
	add_str(str,s2);
	CopyInd0ToRemote(str);	 //my
 //ok	printEthString(str, 28);   //t
	ConvertToWin1251(str);
    embIndicator.SetStr0(str);
	for(i=0; i<25; i++) str[i]=0;
	CreateASCIIZ(dpd+embTree.Name(),str);
	add_str(str,"     ");
	CreateASCIIZ(dpd+embTree.Version(),s1);
	add_str(str,s1);
	add_str(str," ");
	CreateASCIIZ(dpd+embTree.Date(),s2);
	add_str(str,s2);
	CopyInd1ToRemote(str);	  //my
 //	printEthString(str, 28);
	ConvertToWin1251(str);
	embIndicator.SetStr1(str);

  embIndicator.Cursor(0,0x81);
   /*
    to global 
	char a[128];
	char c[128];
	unsigned long ttt=0,last_err=0;;
	char start_flag=1;
	int ctrl_flag=0;
	int ctrl_counter=0;
	int no_blink=1, color=1;
	int old_color=1;
	int old_state=0;
	int err_mode=0;
	int err_flag=0;
	int psp_mode=0;
	int psp_flag=0;
	int psp_flag_counter=0,psp_flag_counter1=0,psp_flag_counter2=0;
	int calib_flag_start=0,calib_flag_end=0;
  int flagDir485;
	unsigned char dev_addr=0, dev_point=0;
	int addr_flag=0;
	int point_flag=0;
	unsigned char port500=0;
/////////  DEBUG SECTION  //////////
	int tempDeb = 0;
	char chDeb[32];

*/

Init_BMD34();
InitSound();
//!!!!! whu!!!!! outportb(0x65E, 0xff); //081125 new : init ethernet
 SetProtokol(EmbGetProt()); //init parameter to start right protokol

	embTree.ClearErr1(); //090804				 
	embTree.ClearErr2(); //090804
//____________________________________________________
//init to doc pwg610_swg_J.pdf page 17.
//PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType);
//PVG610_API_FirmwareFromHostBoot(0, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType);

//____________________________________________________
}

#define INTERVAL (20)
#define MAX_VAL  (256)
 

extern "C" unsigned long Noise(unsigned long ret)
{

static unsigned long len_count;
if(len_count++ > (my_rand() % INTERVAL))
{
 len_count = 0l;
 return (my_rand() % MAX_VAL);
}

return ret;
}


extern "C" void  PROV()
{
// unsigned long tmp_dbg1, tmp_dbg2;

  BMD34();
 // unsigned char tmp;
  
//0323  if(GetRemoteMode() & 1l)
if(!(GetRemoteMode() & 1l))
{

   //		ResetWatchDog();
 	  if(embRS232.UsedTrans()>32) embRS232.TransInit(); 
//		if(embSend.Used()) embSend.TransInit(); 
//		if(!embReceive.Used()) embReceive.ReceiveInit(); 
//////////////////////////   L O O P   /////////////////////////////
//		if(embRS232.UsedReceive()) embSend.Add(embRS232.Receive()); //
//		if(embReceive.Used()) embRS232.Trans(embReceive.Get());     //
////////////////////////////////////////////////////////////////////
////////////////////////   C Y C L E   /////////////////////////////
//		  if(embReceive.Used()) embSend.Add(embReceive.Get());      //
////////////////////////////////////////////////////////////////////
		if(embRS232.UsedReceive())
		{
	   //	   tmp =  embRS232.Receive();	   //t
		 //	 embSerialACT155.AddMod(tmp);  //t
		 //	 embSerialACT155.AddTransit(tmp); //t

			   //			if(embRS232.UsedReceive()>COM_BUFFER_SIZE-48) { embRS232.EmptyReceive(); embCommand2.Empty(); }
	  		if(embCommand2.Add(embRS232.Receive())==2)
		//	if(embCommand2.Add(tmp)==2)	  //t
			{
		 //	printf("\n\r 1");
				if(embCommand2.GetType()=='@')
				{
					if((embCommand2.GetAddr()==0xFF)&&(embCommand2.GetPoint()==0xFF))
					{
						char *b=embCommand2.GetStr();
						i=0;
            			flagDir485=1; // RS-232
						 is_send = 1; //my

						while(b[i])
            {

           //t   embSend.Add(b[i]);
		  embSerialACT155.AddMod(b[i]);  //t
		  embSerialACT155.AddTransit(b[i]); //t
		//	  printf("\n\r>1");
              embRS485.Trans(b[i]);
              i++;
            }
            embTree.SetRequest(embCommand2.GetStr());
						embTree.CommandDecoder();
						embTree.GetAnswer(a);
						i=0;
						a[1] = HexChar(EmbGetPoint()>>4);
						a[2] = HexChar(EmbGetPoint()&0x0F);
						a[3] = HexChar(EmbGetAddr()>>4);
						a[4] = HexChar(EmbGetAddr()&0x0F);
            			while(a[i]) embRS232.Trans(a[i++]);
						embCommand2.Empty();
						for(i=0; i<128; i++) a[i]=0;
					}
				  else
						{
							if((embCommand2.GetAddr()==EmbGetAddr())&&(embCommand2.GetPoint()==EmbGetPoint()))
						{
							embTree.SetRequest(embCommand2.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(a);
							i=0;
							a[1] = HexChar(EmbGetPoint()>>4);
							a[2] = HexChar(EmbGetPoint()&0x0F);
							a[3] = HexChar(EmbGetAddr()>>4);
							a[4] = HexChar(EmbGetAddr()&0x0F);
							while(a[i]) embRS232.Trans(a[i++]);
							embCommand2.Empty();
							for(i=0; i<128; i++) a[i]=0;
						}
						else
						{
							if((embCommand2.GetAddr()==EmbGetAddr())&&(embCommand2.GetPoint()==EmbGetPoint()))
							{
								embTree.SetRequest(embCommand2.GetStr());
								embTree.CommandDecoder();
								embTree.GetAnswer(a);
								i=0;
								while(a[i]) embRS232.Trans(a[i++]);
								embCommand2.Empty();
								for(i=0; i<128; i++) a[i]=0;
							}
							else
							{
                if(embCommand2.GetPoint()==EmbGetPoint())
                {
                  flagDir485=1; // RS-232
                  char *b=embCommand2.GetStr();
                  i=0;
				   is_send = 1; //my

                  while(b[i]) embRS485.Trans(b[i++]);
								  embCommand2.Empty();
                }
                else
                {
                  char *b=embCommand2.GetStr();
                  i=0;
                  while(b[i])//t embSend.Add(b[i++]);
				  {
				    embSerialACT155.AddMod(b[i]);  //t
		  			embSerialACT155.AddTransit(b[i++]); //t
				  }

                  embCommand2.Empty();
                }
							}
						}
					}
				}
				else
				{
					if(embCommand2.GetType()=='&')
					{
						char *b=embCommand2.GetStr();
						i=0;
						while(b[i])//t embSend.Add(b[i++]);
						{
						 embSerialACT155.AddMod(b[i]);  //t
		  				 embSerialACT155.AddTransit(b[i++]); //t
						 }
						embCommand2.Empty();
					}
					else
					{
						embCommand2.Empty();
					}
				}
			}
		}
 //t   if(embReceive.Used())	  //from modem
  	if(embSerialACT155.UsedMod())	   //maked "while"
	  //t
		{
	//	delay_mcs(1000l);
	//ok 	printf("\n\r 2");	  //t
 //ok		 printEthLongHex(0x1); //ok
   //t   if(embCommand1.Add(embReceive.Get())==2)
  //   	tmp_dbg1 = 	 embSerialACT155.GetMod();
 //		tmp_dbg1 = Noise(tmp_dbg1);
//   	 	tmp_dbg2 = 	 embCommand1.Add(tmp_dbg1);
   //	 	printf(".%c", (unsigned char)tmp_dbg1);

   	   if(embCommand1.Add( embSerialACT155.GetMod())==2)
   	//   if(tmp_dbg2==2)
		  {
		if(embCommand1.GetType()=='@')
		   {
              debug_word++;

	  //		printf("\n\r addr : %X  point : %X", EmbGetAddr(),EmbGetPoint());
	  //	    printEthLongHex(0x2);
          if((embCommand1.GetAddr()==0xFF)&&(embCommand1.GetPoint()==0xFF))
			{
			  char *b=embCommand1.GetStr();
			  i=0;
             flagDir485=2; // EMB
			 is_send = 1; //my
		      while(b[i])
            {
              embRS232.Trans(b[i]);
              embRS485.Trans(b[i]);
			  embSerialACT155.AddTransit(b[i]);

              i++;
            }
						embTree.SetRequest(embCommand1.GetStr());
						embTree.CommandDecoder();
						embTree.GetAnswer(c);
						i=0;
						c[1] = HexChar(EmbGetPoint()>>4);
						c[2] = HexChar(EmbGetPoint()&0x0F);
						c[3] = HexChar(EmbGetAddr()>>4);
						c[4] = HexChar(EmbGetAddr()&0x0F);
            flagDir485=2; // RS-232
						while(c[i]) //t  embSend.Add(c[i++]);	//to modem & rs232 & transit
						 {
						//   printf("_%c", c[i]);
					//	   delay_mcs(500l);
						   	 embSerialACT155.AddMod(c[i++]);  //t  - uncomment!!!
		 				 //	 embSerialACT155.AddTransit(c[i]); //t
						 //	 embRS232.Trans(c[i++]);
  						 }

						embCommand1.Empty();
            		debug_byte++;
						for(i=0; i<128; i++) c[i]=0;
					}
					else
					{
				   //		printf("\n\r Caddr : %X  Cpoint : %X", embCommand1.GetAddr(),embCommand1.GetPoint());
						if((embCommand1.GetAddr()==EmbGetAddr())&&(embCommand1.GetPoint()==EmbGetPoint()))
						{
					 //		printf("1");
							embTree.SetRequest(embCommand1.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(c);
							i=0;
					   //		printf("\n\r");
							while(c[i]) //embSend.Add(c[i++]);  //to modem
							{
					  // 	 	printf("%c", c[i]);
							 embSerialACT155.AddMod(c[i++]);  //t
							}
					   //		 printf("\n\r");

							embCommand1.Empty();
              for(i=0; i<128; i++) c[i]=0;
						}
            else
            {
	  //no		    printEthLongHex(0x3);

              if(embCommand1.GetPoint()==EmbGetPoint())
              {
			 //	printf("\n\r 21");
		 //	 printEthLongHex(0x21);
                flagDir485=2; // EMB
                char *b=embCommand1.GetStr();
                i=0;
				 is_send = 1; //my
			//		printf("\n\r");

                while(b[i])
				{
            //     printf("%c", b[i]);
                 embRS485.Trans(b[i++]);
			    }
                embCommand1.Empty();
              }
              else
              {
                char *b=embCommand1.GetStr();
                i=0;
                while(b[i])// embRS232.Trans(b[i++]);	// & transit
				{
				   embRS232.Trans(b[i]);		  //t
				   embSerialACT155.AddTransit(b[i++]); //t

				}

                embCommand1.Empty();
              }
            }
					}
				}
				else
				{
					if(embCommand1.GetType()=='&')
					{

			//	  	 printEthLongHex(0x4);

						char *b=embCommand1.GetStr();
						i=0;
						while(b[i])// embRS232.Trans(b[i++]);	// transit
						{
						   embRS232.Trans(b[i]);
					  	   embSerialACT155.AddTransit(b[i++]); //t

						}
						embCommand1.Empty();
                    }
					else
					{
						embCommand1.Empty();
					}
				}
			}
		}

//===============================================================================	add
    if(embSerialACT155.UsedTransit())
		{
	// 	printf("\n\r 3");
   //		tmp_dbg1 = 	 embSerialACT155.GetTransit();
	//	tmp_dbg2 = 	 embCommand4.Add(tmp_dbg1);
	//	 printf("\n\r >%c   -> %X  ", tmp_dbg1,tmp_dbg2);

   //t   if(embCommand4.Add(embReceive.Get())==2)
   	     if(embCommand4.Add(embSerialACT155.GetTransit())==2)
     //		if(tmp_dbg2 == 2) //t
			{

				if(embCommand4.GetType()=='@')
				{
		  //		 printf("\n\r 31");
          debug_word++;
          if((embCommand4.GetAddr()==0xFF)&&(embCommand4.GetPoint()==0xFF))
					{
					 //	 printf("\n\r 32");
			  			char *b=embCommand4.GetStr();
						i=0;
						 is_send = 1; //my

            flagDir485=2; // EMB
						while(b[i])
            {
		   //ok	  printf("\n\r . %c", b[i] );

              embRS232.Trans(b[i]);
              embRS485.Trans(b[i]);
			  embSerialACT155.AddMod(b[i]);

              i++;
            }
						embTree.SetRequest(embCommand4.GetStr());
						embTree.CommandDecoder();
						embTree.GetAnswer(c);
						i=0;
						c[1] = HexChar(EmbGetPoint()>>4);
						c[2] = HexChar(EmbGetPoint()&0x0F);
						c[3] = HexChar(EmbGetAddr()>>4);
						c[4] = HexChar(EmbGetAddr()&0x0F);
            flagDir485=2; // RS-232
						while(c[i]) //t  embSend.Add(c[i++]);	//to modem & rs232 & transit
						 {
						   //	 embSerialACT155.AddMod(c[i]);  //t
		 					 embSerialACT155.AddTransit(c[i++]); //t
						  //	 embRS232.Trans(c[i++]);
  						 }

						embCommand4.Empty();
            debug_byte++;
						for(i=0; i<128; i++) c[i]=0;
					}
					else
					{
						if((embCommand4.GetAddr()==EmbGetAddr())&&(embCommand4.GetPoint()==EmbGetPoint()))
						{
							embTree.SetRequest(embCommand4.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(c);
							i=0;
							while(c[i]) //embSend.Add(c[i++]);  //to modem
							 embSerialACT155.AddTransit(c[i++]);  //t
							embCommand4.Empty();
              for(i=0; i<128; i++) c[i]=0;
						}
            else
            {
              if(embCommand4.GetPoint()==EmbGetPoint())
              {
                flagDir485=2; // EMB
                char *b=embCommand4.GetStr();
                i=0;
				 is_send = 1; //my

                while(b[i]) embRS485.Trans(b[i++]);
                embCommand4.Empty();
              }
              else
              {
                char *b=embCommand4.GetStr();
                i=0;
                while(b[i])// embRS232.Trans(b[i++]);	// & modem
				{
				   embRS232.Trans(b[i]);		  //t
				   embSerialACT155.AddMod(b[i++]); //t

				}

                embCommand4.Empty();
              }
            }
					}
				}
				else
				{
					if(embCommand4.GetType()=='&')
					{
						char *b=embCommand4.GetStr();
						i=0;
						while(b[i])// embRS232.Trans(b[i++]);	// modem
						{
						   embRS232.Trans(b[i]);
						   embSerialACT155.AddMod(b[i++]); //t

						}
						embCommand4.Empty();
          }
					else
					{
						embCommand4.Empty();
					}
				}
			}
		}


//===============================================================================  add




////// 485
    if(embRS485.UsedReceive())
		{
//			if(embRS232.UsedReceive()>COM_BUFFER_SIZE-48) { embRS232.EmptyReceive(); embCommand2.Empty(); }
	//  	tmp_dbg1 = 	 embRS485.Receive();
	// 	tmp_dbg2 = 	 embCommand3.Add(tmp_dbg1);
   //	 	printf(".%c", (unsigned char)tmp_dbg1);

	  //  	if(tmp_dbg2==2)
		 if(embCommand3.Add(embRS485.Receive())==2)
			{

		 	if (is_send)
		 	{
		 	//  embCommand3.Empty();
			  embCommand3.Init();
		  //	  printf("^^^");
		 	  is_send = 0;
			//  break;
		 	}
		 	else
		 {
        if(embCommand3.GetType()=='@')
				{
          flagDir485=0;
          if((embCommand3.GetAddr()==0xFF)&&(embCommand3.GetPoint()==0xFF))
		  {
						for(i=0; i<128; i++) a[i]=0;				
						embTree.SetRequest(embCommand3.GetStr());
						embTree.CommandDecoder();
            embTree.GetAnswer(a);
						i=0;
						a[1] = HexChar(EmbGetPoint()>>4);
						a[2] = HexChar(EmbGetPoint()&0x0F);
						a[3] = HexChar(EmbGetAddr()>>4);
						a[4] = HexChar(EmbGetAddr()&0x0F);
			 is_send = 1; //my

            while(a[i])
            {
		//	printf("\n\r %c", a[i]);
             embRS485.Trans(a[i++]); 
			 }
            embCommand3.Empty();
						for(i=0; i<128; i++) a[i]=0;				
          }
          else
          {
		 
						if((embCommand3.GetAddr()==EmbGetAddr())&&(embCommand3.GetPoint()==EmbGetPoint()))
						{
              for(i=0; i<128; i++) a[i]=0;
							embTree.SetRequest(embCommand3.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(a);
							i=0;
							 is_send = 1; //my

              while(a[i]) embRS485.Trans(a[i++]);
							embCommand3.Empty();
							for(i=0; i<128; i++) a[i]=0;
						}
          }
        }
	   	else
		 {
	 //  	  printf(">%d",flagDir485 );
	    //  if (flagDir485 != 1)	flagDir485 = 2;

          char *b=embCommand3.GetStr();
					i=0;
		  //	   printf("\n\r:");

          switch(flagDir485)
          {
            case 1: while(b[i]) embRS232.Trans(b[i++]); break;
            case 2: while(b[i])
           //  embSend.Add(b[i++]);
		  			 {
			  	 //	printf("_%c %d", b[i], i);
			  		embSerialACT155.AddMod(b[i]);  //t
		  			embSerialACT155.AddTransit(b[i++]); //t
					}
               break;
            default: embCommand3.Empty();
          }
		  		  /*
		   while(b[i])
           		 {
			  //		printf("\n\r %c", b[i]);
			        embRS232.Trans(b[i]);
			  		embSerialACT155.AddMod(b[i]);  //t
		  			embSerialACT155.AddTransit(b[i++]); //t
				}
				*/
          flagDir485=0;
					embCommand3.Empty();				
        }
		} //
			}
		}
} //remotemode
//////////////////////////////////////
//////////////////////////////////////
///////////  Индикатор  //////////////
//////////////////////////////////////
//////////////////////////////////////

//////////  Счетчик ПСП  /////////////

if(!dpd_state) return;
		
if(psp_flag_counter)
	{

			psp_flag_counter1++;
	    if(psp_flag_counter1> DELAY_PSP)//500)
			{
				psp_flag_counter=0;				
				psp_flag_counter1=0;
				int fl=psp_number;
				if(calib_flag_start) fl+=0x40;
				if(calib_flag_end) fl+=0x80;
			  outportb(0x646,0x00+fl);
			}
		}
		else
		{
			psp_flag_counter2++;
	    if(psp_flag_counter2>DELAY_PSP)//500)
			{
  			if(calib_flag_start) calib_flag_start=0;
	  		if(calib_flag_end) calib_flag_end=0;
				psp_flag_counter=1;
				psp_flag_counter2=0;
				unsigned c_psp,c_err1,c_err2;
			  //	outport(0x658,0xff);
		  //t		c_psp=inport(0x658) & 0xff;
				c_psp=inportx(0x658);	//t

		   //		c_err1=inport(0x65C);//t(0x65A);
		   //		c_err2=inport(0x65A);//t(0x65C);
		   //		outport(0x65A,0xff);
		   //t		c_err1=inport(0x65A) & 0xff ;
				c_err1=inportx(0x65A); //t

			  //	outport(0x65C,0xff);
			 //t	c_err2=inport(0x65C) & 0xff;
				c_err2=inportx(0x65C);	//t



				counterErrPSP+=c_psp;
				embTree.err1+=c_err1;
				embTree.err2+=c_err2;
				embTree.com_err1+=c_err1;
				embTree.com_err2+=c_err2;
				embTree.com_psp+=c_psp;
				outportb(0x646,0x20+psp_number);
			//	outportb(0x646,0x20);	//my
			}
		}
//////////////////////////////////////
	  //	 printEthLongHex('1');
  //	 printEthLongHex('1');

		if(embIndicator.Used()) 
		{
			chk=embIndicator.Get();
	   //	   printEthLongHex(chk); //t
			if(('0'<chk)&&(chk<='6')) { key = chk; }
		}
		if(key)
		{
			start_flag=0;
			embIndicator.Receipt();
			current = embTree.Current();	
			if(current) parent = current->Parent();
			switch(key)
			{
				case 0x31: // Esc 
					switch(pt_key)
					{
						case PT_ERR1:	
							outportb(0x646,0x40+psp_number);
							outportb(0x646,0x00+psp_number);
							embTree.ClearErr1(); 
							time1p=1;
						break;
						case PT_ERR2:	
							outportb(0x646,0x40+psp_number);
							outportb(0x646,0x00+psp_number);
							embTree.ClearErr2(); 
							time2p=1;
						break;
						case PT_ERR_PSP:	
							outportb(0x646,0x20+psp_number);
//							outportb(0x646,0x00+psp_number);
							counterErrPSP=0; 
							time3p=1;
						break;
						case PT_CALIBR:	
							outportb(0x646,0x80);
							calib_flag_end=1;
						break;				
						case PT_RING:	
							NoMakeRing();
						break;
					}
					ctrl_counter=0;
					embTree.SaveStateACT34();
					break;																		  
				case 0x32: // Up 
					if(ctrl_flag||err_flag||psp_flag||addr_flag||point_flag)
					{
						if(ctrl_flag) 
						{
							embIndicator.Cursor(2,0xD7);
							EmbParameter *par = current->Parameter();
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							ctrl_counter++;
							if(ctrl_counter>=embSet->NumItem()) ctrl_counter=0;
						}
						if(err_flag)
						{
						  embIndicator.Cursor(2,0xD7);
							err_mode++;
							if(err_mode>2) err_mode=0;
						}
						if(psp_flag)
						{
							embIndicator.Cursor(2,0xD7);
							psp_mode++;
							if(psp_mode>2) psp_mode=0;
						}
						if(addr_flag)
						{
							embIndicator.Cursor(2,0xD7);
							dev_addr++;
						}
						if(point_flag)
						{
							embIndicator.Cursor(2,0xD7);
							dev_point++;
						}
					}
					else
					{
						ctrl_counter=0;
						if(parent->Parent()) embTree.Up();   
					}
			  //		  printEthLongHex(ctrl_counter);	 0 or 1
					embTree.SaveStateACT34();
					break;
				case 0x33: 	// Enter
				 //  printEthLongHex(pt_key);	
					switch(pt_key)
					{
						case PT_ADDR:	
							if(!addr_flag) 
							{
								addr_flag=1;
								embIndicator.Cursor(2,0xD7);
							}
							else 
							{
								pt_key = PT_NULL;
								addr_flag=0;
								EmbSetAddr(dev_addr);
								embIndicator.Cursor(0,0xD7);
							}
							embTree.SaveStateACT34();
						break;
						case PT_POINT:	
							if(!point_flag) 
							{
								point_flag=1;
								embIndicator.Cursor(2,0xD7);
							}
							else 
							{
								pt_key = PT_NULL;
								point_flag=0;
								EmbSetPoint(dev_point);
                				SetAddrAKM(dev_point);
								embIndicator.Cursor(0,0xD7);
							}
							embTree.SaveStateACT34();
						break;
						case PT_ERR1:	
							if(!err_flag) 
							{
								err_flag=1;
								embIndicator.Cursor(2,0xD7);
							}
							else 
							{
								pt_key = PT_NULL;
								err_flag=0;
								embIndicator.Cursor(0,0xD7);
							}
							embTree.SaveStateACT34();
						break;
						case PT_ERR2:	
							if(!err_flag) 
							{
								err_flag=1;
								embIndicator.Cursor(2,0xD7);
							}
							else 
							{
								pt_key = PT_NULL;
								err_flag=0;
								embIndicator.Cursor(0,0xD7);
							}
							embTree.SaveStateACT34();
						break;
						case PT_ERR_PSP:	
							if(!psp_flag) 
							{
								psp_flag=1;
								embIndicator.Cursor(2,0xD7);
							}
							else 
							{
								pt_key = PT_NULL;
								psp_flag=0;
								embIndicator.Cursor(0,0xD7);
							}
							embTree.SaveStateACT34();
						break;
						case PT_RING:	
							timeRing=0;
							ringOn=1;
							port500=inportb(0x640);
							outportb(0x640,0x80|(port500&0x0F));
							embTree.SaveStateACT34();
						break;
						case PT_CALIBR:	
							outportb(0x646,0x40);
							calib_flag_start=1;
							embTree.SaveStateACT34();
						break;						
						case PT_CTRL:  //sound hier!
					 		if(!ctrl_flag) 
							{
						 //		ks=1; //t
								ctrl_flag=1;
						   		embIndicator.Cursor(2,0xD7);	 //blink on	
						   		  if(embTree.LexCmp(current->Name(),"Протокол"))
									{
									  ctrl_counter = EmbGetProt();// 1-выкл  0-вкл
   									}
								   else	 if(embTree.LexCmp(current->Name(),"звук"))
									{
									  ctrl_counter = EmbGetSound();// 1-выкл  0-вкл
   									}

								  else
								  {
							   	 	ctrl_counter = embTree.GetParameterNum();
								 }
						   	 //;
						   	 //x(ctrl_counter);		 //olvais 1
							}
							else 
							{
							
								pt_key    =  PT_NULL;
						  	 	ctrl_flag =  0; //cursor should be blink!
						  		embIndicator.Cursor(0,0xD7);   //blink off
					  						  

								EmbParameter *par = current->Parameter();
								if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
								if(par->Type()-12<embTree.CountSets())
								{
									char str_par[32];
									EmbSet *embSet = embTree.GetSets(par->Type()-12);
									CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
									embTree.SetParameter(str_par);
									if(embTree.LexCmp(current->Name(),"звук"))
									{
									  if(ctrl_counter){ MakeSoundLock(); EmbSetSound(1);} // 1-выкл  0-вкл
										else {  MakeSoundUnLock(); 
										EmbSetSound(0);}
									}
									  if(embTree.LexCmp(current->Name(),"Протокол"))
									{
									  if(ctrl_counter) {SetProtokol(1);}// 1-выкл  0-вкл
										else{ SetProtokol(0); }
									}


								}
								

//_________________________________________________________________________t
/*
							//	rs=1; ks=0;
								embIndicator.Cursor(0,0xd7);
								EmbParameter *par = current->Parameter();
								if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
									if(par->Type()-12<embTree.CountSets())
									{
										char str_par[32];
										EmbSet *embSet = embTree.GetSets(par->Type()-12);
										CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
										embTree.SetParameter(str_par);
										ctrl_flag=0;
									}
								*/
//_________________________________________________________________________t

						 	}  //ctrl_flag
  			//t		for(long n=0; n<10000; n++);
						embTree.SaveStateACT34();
						break;
					}
          //t			Delay(100000);
					embTree.SaveStateACT34();
					break;																		 
				case 0x34: // Left
					if(psp_flag)
					{
						time3p=1;
					}
					else
					{

						ctrl_flag = 0;
						err_flag = 0;
						addr_flag = 0;
						point_flag = 0;
						embIndicator.Cursor(0,0xD7);
						embTree.Left(); 
					}
					embTree.SaveStateACT34();
					break;                     
				case 0x35: // Down
					if(ctrl_flag||err_flag||psp_flag||addr_flag||point_flag)
					{
						if(ctrl_flag)
						{
							embIndicator.Cursor(2,0xD7);
							EmbParameter *par = current->Parameter();
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							ctrl_counter--;
							if(ctrl_counter<0) ctrl_counter=embSet->NumItem()-1;
						}
						if(err_flag)
						{
							embIndicator.Cursor(2,0xD7);
							err_mode--;
							if(err_mode<0) err_mode=2;
						}
						if(psp_flag)
						{
							embIndicator.Cursor(2,0xD7);
							psp_mode--;
							if(psp_mode<0) psp_mode=2;
						}
						if(addr_flag)
						{
							embIndicator.Cursor(2,0xD7);
							dev_addr--;
						}
						if(point_flag)
						{
							embIndicator.Cursor(2,0xD7);
							dev_point--;
						}
					}
					else
					{
						ctrl_counter=0;
						embTree.Down();
					}
					embTree.SaveStateACT34();
					break;										  
				case 0x36: // Righ
					if(psp_flag)
					{
						time3p=1;
					}
					else
					{
						ctrl_flag = 0;
						err_flag = 0;
						addr_flag = 0;
						point_flag = 0;
						embIndicator.Cursor(0,0xD7);
						embTree.Right(); 
					}
					embTree.SaveStateACT34();
					break;                   
			}
			current = embTree.Current();	
			if(current) parent = current->Parent();
			for(i=0; i<25; i++) s1[i]  = 0;
			for(i=0; i<25; i++) s2[i]  = 0;
			for(i=0; i<25; i++) str[i] = 0;
//////////  Старая верхняя строка  //////////////////
/*
      if(!parent->Parent()) 
			{
				CreateASCIIZ(dpd+embTree.Name(),s1);
//				CreateASCIIZ(dpd+embTree.Version(),str);
//				add_str(s1,"  ");
//				add_str(s1,str);
			}
			else CreateASCIIZ(dpd+parent->Name(),s1);
*/
//////////////////////////////////////////////////////
			UpdateStatusBarNew(s1);
			CopyInd0ToRemote(s1);
			ConvertToWin1251(s1);
			embIndicator.SetStr0(s1);
			CreateASCIIZ(dpd+current->Name(),s2);
			pt_key = PT_NULL;
			if(!current->Child()) 
			{
				add_str(s2," : ");
///////////////////////   Управление  /////////////////////
//				if(current->Name())
				if(embTree.LexCmp(current->Name(),"Служебная_связь"))
				{
					pt_key = PT_RING;
					EmbParameter *par = current->Parameter();
					if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
					{
						if(par->Type()-12<embTree.CountSets())
						{
					//t		BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
						}
					}			
				}
//_______________________________________________________________________________
				 
				  else if(embTree.LexCmp(current->Name(),"Протокол"))
					  {
					  EmbParameter *par = current->Parameter();
				   //		pt_key = PT_PROG;
						if(!ctrl_flag) ctrl_counter =  EmbGetProt();
				//		printEthLongHex(ctrl_counter);
						pt_key  =  PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					  }

					   else if(embTree.LexCmp(current->Name(),"звук"))
					  {
					  EmbParameter *par = current->Parameter();
				   //		pt_key = PT_PROG;
						if(!ctrl_flag) ctrl_counter =  EmbGetSound();
				//		printEthLongHex(ctrl_counter);
						pt_key  =  PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					  }
   //____________________________________________________________________________
  					 else if(embTree.LexCmp(current->Name(),"Версия"))
					  {
				  		 FillProgVersion1(&s2[8] , 8);
				  	  }
					  else if(embTree.LexCmp(current->Name(),"ПЛИС"))
					  {
				  		 FillXilinxVersion1(&s2[6] , 6);
				  	  }

  //____________________________________________________________________________

					
//_______________________________________________________________________________

				else
				{
				 	EmbParameter *par = current->Parameter();
					if((par->accessType.access==2)||(par->accessType.access==3))
					{
						if(!ctrl_flag) ctrl_counter = embTree.GetParameterNum();
				 	  //	printEthLongHex(ctrl_counter);
						pt_key =	PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					}
					else
					{
					///////////////////////////////////////////////////////////
					
						if(embTree.LexCmp(current->Name(),"Ошибки35_N1"))
						{
							pt_key = PT_ERR1;
						}
						else 
						{
							if(embTree.LexCmp(current->Name(),"Ошибки35_N2"))
							{
								pt_key = PT_ERR2;
							}
							else
							{
								if(embTree.LexCmp(current->Name(),"ОшибкиПСП"))
								{
									pt_key = PT_ERR_PSP;
								}
								else
								{
                  if(embTree.LexCmp(current->Name(),"ФАПЧ_ПД"))
                  {
                    for(i=0; i<24; i++) s2[i]=0;
                    s2[0]='?';
                  }
                  else
                  {
                    if(embTree.LexCmp(current->Name(),"Адр_Станции_Сист"))
                    {
                      pt_key = PT_POINT;
                      if(!point_flag) dev_point = EmbGetPoint();
                      char ch_p[8];
                      itoa(dev_point,ch_p,10); 
                      add_str(s2,ch_p);
                    }
                    else
                    {
                      if(embTree.LexCmp(current->Name(),"Адр_Устр_Сист"))
                      {
                        pt_key = PT_ADDR;
                        if(!addr_flag) dev_addr = EmbGetAddr();
                        char ch_p[8];
                        itoa(dev_addr,ch_p,10);
                        add_str(s2,ch_p);
                      }
                      else
                      {
                        add_str(s2,embTree.ViewParameter(str));
                      }
                    }
									}
								}
							}
						}
					}
				}
			}	
			else
			{
				char c_add[4];
				c_add[0]=' ';
				c_add[1]=0x0F;
				c_add[2]=' ';
				c_add[3]=0;
					
				add_str(s2,c_add);
				//				add_str(s2," + ");
				if(embTree.IsChildAlarm()) add_str(s2,"(!)");
			}
			CopyInd1ToRemote(s2);
			ConvertToWin1251(s2);
			embIndicator.SetStr1(s2);

//	    embIndicator.SetLtDiod(0,4);
			key=0;
		}
		r++;
  //		if(r>4000)
		if(r> DELAY_MENU)  //my
		{
			r=0;
			p++;
			old_color = color;
			old_state=state;
/////////////  Тестирование звонка  /////////////////////
	 	  	IsRing();
/////////////////////////////////////////////////////////

//int tmpu = 0;
//t tmpu =	UpdateState();
//printf("\n\r> %X", tmpu);

			switch(UpdateState())
//			switch(tmpu)
			{
				case ST_NORMA:  no_blink=1; color=3; break;	  //lcd "norma"
				case ST_LOOP:   no_blink=0; color=3; break;
				case ST_ERROR1: no_blink=1; color=2; break;	   //lcd "oshibki"
				case ST_ERROR2: no_blink=1; color=2; break;
				case ST_SEARCH: no_blink=1; color=2; break;
				case ST_FAULT:  no_blink=0; color=1; break;		//lcd "AWARIYA"
				case ST_ALARM:  no_blink=1; color=1; break;
				default: no_blink=1; color=3; break; 
			}
//#ifndef DEBUG_ALARM
  			if(state==ST_ALARM) MakeAlarm(); 
  			else NoMakeAlarm();
//#endif		
			if(p%2) 
			{
			   
				if(old_color!=color) 
				{
					embIndicator.SetLtDiod(0,old_color);
					old_color = color;
				}
				embIndicator.SetLtDiod(1,color);
					
			}
			else
			{
			  
				if(old_color!=color) 
				{
					embIndicator.SetLtDiod(0,old_color);
					old_color = color;
				}
				embIndicator.SetLtDiod(no_blink,color);
				
////
				if(!start_flag)
				{
					current = embTree.Current();	
					if(current) parent = current->Parent();
					for(i=0; i<25; i++) s1[i]  = 0;
					for(i=0; i<25; i++) s2[i]  = 0;
					for(i=0; i<25; i++) str[i] = 0;
///////////////////////////////////////////////////////
/*
					if(!parent->Parent()) 
					{
						CreateASCIIZ(dpd+embTree.Name(),s1);
					}
					else CreateASCIIZ(dpd+parent->Name(),s1);
*/
///////////////////////////////////////////////////////
					UpdateStatusBarNew(s1);
					CopyInd0ToRemote(s1);
					ConvertToWin1251(s1);
					embIndicator.SetStr0(s1);

			    CreateASCIIZ(dpd+current->Name(),s2);
	
					if(!current->Child()) 
					{
						add_str(s2," : ");
						////
						EmbParameter *par = current->Parameter();
//_____________________________________________________________________________
//t  if(embTree.LexCmp(current->Name(),"Протокол"))
  if(embTree.LexCmp(current->Name(),"Протокол"))
    {
					  EmbParameter *par = current->Parameter();
				   //		pt_key = PT_PROG;
						if(!ctrl_flag) ctrl_counter =  EmbGetProt();
				 //		printEthLongHex(ctrl_counter);
						pt_key  =  PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					  }
					  else

  					if(embTree.LexCmp(current->Name(),"звук"))
    				{
					  EmbParameter *par = current->Parameter();
				   //		pt_key = PT_PROG;
						if(!ctrl_flag) ctrl_counter =  EmbGetSound();
				 //		printEthLongHex(ctrl_counter);
						pt_key  =  PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					  }

//____________________________________________________________________
	  if(embTree.LexCmp(current->Name(),"Версия"))
    				{
			  					 /*
					   //	 int fl1=0;
							for(i=0; i<24; i++)
							{
							   //	if(!s2[i]) fl1=1;
							   //	if(fl1) s2[i]=' ';
							   if(!s2[i])  s2[i]=' ';
							}

						 s2[22] = '?';
						 s2[23] = 0x7E;
						 s2[24] = 0;
						 */
 					FillProgVersion1(&s2[8] , 8);

					  }
	  				else if(embTree.LexCmp(current->Name(),"ПЛИС"))
					  {
				  		 FillXilinxVersion1(&s2[6] , 6);
				  	  }



//____________________________________________________________________
					  else

//_____________________________________________________________________________


						if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
						{
							if(par->Type()-12<embTree.CountSets())
							{
								BYTE i;
								char str_par[32];
						  		if(!ctrl_flag)
								{
						  		ctrl_counter = embTree.GetParameterNum();
						//		if(1) 						//		if(1) mbTree.GetParameterNum();
						 //	 	printEthLongHex(ctrl_counter);		//!!!!!!!!!!!!!	 0!
								}
								EmbSet *embSet = embTree.GetSets(par->Type()-12);
								CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
								add_str(s2, str_par);
								int fl1=0;
								for(i=0; i<24; i++)
								{
									if(!s2[i]) fl1=1;
									if(fl1) s2[i]=' ';
								}
							  s2[23] = 0x7E;
							  s2[24] = 0;
							}
						}
						else
						{
							if(embTree.LexCmp(current->Name(),"Ошибки35_N1"))
							{
								embTree.ViewParameter(str);
								for(i=0; i<24; i++) sk[i]=0;

							//	printEthLongHex(err_mode);	//t

								if(err_mode==0)
								{
									if(embTree.Err1()==1)
									 {
									 add_str(s2, "<"); 
								 //	  printEthLongHex(0x6);
									 }



									Probability2(embTree.Err1(), sk, time1p);
								}
								if(err_mode==1)	sec2time(time1p, sk); 
								if(err_mode==2)
								{
									if(embTree.Err1()!=0) ultoa(embTree.Err1()-1, sk, 10);
									else ultoa(0, sk, 10);
								}
								add_str(s2, sk);
								int fl1=0;
								for(i=0; i<24; i++)
								{
									if(!s2[i]) fl1=1;
									if(fl1) s2[i]=' ';
								}
								s2[23] = 0x7E;
								s2[24] = 0;
							}
							else
							{
								if(embTree.LexCmp(current->Name(),"Ошибки35_N2"))
								{
									embTree.ViewParameter(str);
									for(i=0; i<24; i++) sk[i]=0;
									if(err_mode==0)
									{
										if(embTree.Err2()==1) add_str(s2, "<");
										Probability2(embTree.Err2(), sk, time2p);
									}
									if(err_mode==1)	sec2time(time2p, sk); 
									if(err_mode==2)
									{
										if(embTree.Err2()!=0) ultoa(embTree.Err2()-1, sk, 10);
										else ultoa(0, sk, 10);
									}
									add_str(s2, sk);
									int fl1=0;
									for(i=0; i<24; i++)
									{
										if(!s2[i]) fl1=1;
										if(fl1) s2[i]=' ';
									}
									s2[23] = 0x7E;
									s2[24] = 0;
								}
								else
								{
									if(embTree.LexCmp(current->Name(),"ОшибкиПСП"))
									{
										pt_key = PT_ERR_PSP;
										for(i=0; i<24; i++) sk[i]=0;
										if(psp_mode==0) ProbabilityPSP(counterErrPSP, sk, time2);
										if(psp_mode==1)	sec2time(time3p, sk); 
										if(psp_mode==2)
										{
											if(counterErrPSP!=0) ultoa(counterErrPSP, sk, 10);
											else ultoa(0, sk, 10);
										}
										add_str(s2, sk);
										int fl1=0;
										for(i=0; i<24; i++)
										{
											if(!s2[i]) fl1=1;
											if(fl1) s2[i]=' ';
										}
										s2[23] = 0x7E;
										s2[24] = 0;
									}
									else
									{
											if(embTree.LexCmp(current->Name(),"ФАПЧ_ПД"))
											{
												for(i=0; i<128; i++) s2[i]=0;
												UnACTAlarm ua;
												UnACTAlarmState uas;
												UnActIden uai;
												unsigned char self_id = inportb(0x640)&0x0F;
												uai.byte = inportb(0x641);
												uas.byte = inportb(0x642);
												ua.byte = inportb(0x643);
												int norma_flag = 1;
												if(ua.chan.fap_pd_lc) { add_str(s2,"ФАПЧ_ПД(м)  "); norma_flag = 0; }
												if(ua.chan.fap_pm_lc) { add_str(s2,"ФАПЧ_ПМ(м)  "); norma_flag = 0; }
												if(ua.chan.fap_pd_rm) { add_str(s2,"ФАПЧ_ПД(у)  "); norma_flag = 0; }
												if(ua.chan.fap_pm_rm) { add_str(s2,"ФАПЧ_ПМ(у)  "); norma_flag = 0; }
												
												if(uas.chan.input_lc1==3) { add_str(s2,"СИАС1(м) "); norma_flag = 0; }
   												{
													if(uas.chan.input_lc1==2) { add_str(s2,"Поиск1(м) "); norma_flag = 0; }
													else
													{
														if(uas.chan.input_lc1==1) { add_str(s2,"Ошибки1(м) "); norma_flag = 0; }
														if(self_id!=0)
														{
															if(uai.chan.iden1)
																if(uai.chan.iden1!=self_id) 
																{ 
																	add_str(s2,"Пм1 : Чужой "); 
																	char ch_t[8];
																	itoa(self_id,ch_t,10);
																	add_str(s2,ch_t);
																	add_str(s2," ");
																	itoa(uai.chan.iden1,ch_t,10);
																	add_str(s2,ch_t);
																	add_str(s2,"  ");
																	norma_flag = 0; 
																}
														}
													}
												}
												if(uas.chan.input_lc2==3) { add_str(s2,"СИАС2(м) "); norma_flag = 0; }
												else
												{
													if(uas.chan.input_lc2==2) { add_str(s2,"Поиск2(м) "); norma_flag = 0; }
													else
													{ 
														if(uas.chan.input_lc2==1) { add_str(s2,"Ошибки2(м) "); norma_flag = 0; }
														if(self_id!=0)
														{
															if(uai.chan.iden2)
																if(uai.chan.iden2!=self_id) 
																{ 
																	add_str(s2,"Пм2 : Чужой "); 
																	char ch_t[8];
																	itoa(self_id,ch_t,10);
																	add_str(s2,ch_t);
																	add_str(s2," ");
																	itoa(uai.chan.iden2,ch_t,10);
																	add_str(s2,ch_t);
																	add_str(s2,"  ");
																	norma_flag = 0; 
																}
														}
													}
												}
												if(ua.chan.input_rm1==3) { add_str(s2,"СИАС1(у) "); norma_flag = 0; }
												else
												{
													if(ua.chan.input_rm1==2) { add_str(s2,"Поиск1(у) "); norma_flag = 0; }
													else
													{
														if(ua.chan.input_rm1==1) { add_str(s2,"Ошибки1(у) "); norma_flag = 0; }
													}
												}
												if(ua.chan.input_rm2==3) { add_str(s2,"СИАС2(у) "); norma_flag = 0; }
												else
												{
													if(ua.chan.input_rm2==2) { add_str(s2,"Поиск2(у) "); norma_flag = 0; }
													else
													{
														if(ua.chan.input_rm2==1) { add_str(s2,"Ошибки2(у) "); norma_flag = 0; }
													}
												}
												if(norma_flag) add_str(s2,"Неисправностей нет");
												s2[24]=0;
											}
											else
											{
												if(embTree.LexCmp(current->Name(),"Адр_Станции_Сист"))
												{
													pt_key = PT_POINT;
													if(!point_flag) dev_point = EmbGetPoint();
													char ch_p[8];
													itoa(dev_point,ch_p,10); 
													add_str(s2,ch_p);
												}
												else
												{
													if(embTree.LexCmp(current->Name(),"Адр_Устр_Сист"))
													{
														pt_key = PT_ADDR;
														if(!addr_flag) dev_addr = EmbGetAddr();
														char ch_p[8];
														itoa(dev_addr,ch_p,10);
														add_str(s2,ch_p);
													}
													else
													{
														add_str(s2,embTree.ViewParameter(str));
													}
												}
											}
									}
								}
							}
						}
						//					}
					}
					else
					{
						char c_add[4];
						c_add[0]=' ';
						c_add[1]=0x0F;
						c_add[2]=' ';
						c_add[3]=0;

						add_str(s2,c_add);
						if(embTree.IsChildAlarm()) add_str(s2,"(!)");
					}
					CopyInd1ToRemote(s2);
					ConvertToWin1251(s2);
					embIndicator.SetStr1(s2);
				}
////
			}
		}
//////////////////////////////////////////

	}
//not need}


 unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1;     
  unsigned int   merc, zerc,up0erc,up1erc;
  unsigned char rup0, rup0o,  rup1, rup1o;
  unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;


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
 //outport(0x506,0xff);
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
				/*
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

				  */





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
   /*
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
			   */

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





	  /*
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
			*/
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




void test_PU37_interrupt_ovner()
{

 //unsigned int tmp =  (unsigned int)INT0_FLAG;
   //t      while (IntFlag & tmp)
   //     if(IntFlag & tmp)
   //	 if(1)
	 //	{
	   //	  IntFlag &=  ~tmp;
		//n=inportb(0x505); // опрос флагов прерываний


//__________________________________________test
//for(int i = 0; i < 32; i++)
//for(int i = 0; i < 32; i++)		 //50 mcs

//for(int i = 0; i < 64; i++)		 //115 mcs
//for(int i = 0; i < 128; i++)		 //
/*
for(int i = 0; i < 512; i++)		 //
{
   inportb(0x506);
}
*/    
//__________________________________________test	


   //		if
       char cnt = 16;
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
							 //		tchar =   inportb(0x508);
							   //		tchar =   inportb(0x508);	
									if (merc <0xfffe) merc++;
								 //   printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
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

	    my_int_enable_irq0();

}


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

printf("\r %d %d %d %d code = %c \r\n", aa1, aa2, aa3, aa_loc,  code);

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
	printf("\r aa1=0x%X aa2=0x%X aa3=0x%X aa_loc=0x%X \r\n", aa1, aa2, aa3, aa_loc);
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

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : -----------------------------------------------------
*/////////////////////////////////////////////////////////////////////////// 

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
 // if(GetTestMode() != 7l)
 // {
    embSerialACT155.IsrXX();
 // }
#endif // IncEmbSerialMD34AVT

 IntFlag |= INT0_FLAG;
//t my_int_enable_irq0();
 //090506	if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 //{
 //  InterruptWatchDog++;
   my_int_enable_irq0();
// }

}

//_____________________________________________________________________________


