//#ifndef __TINY__
//#define __TINY__
//#endif
//#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    //// = act34.cpp
////////////////////////////////////////////
//#define IncEmbRS232
//#define IncEmbRS485
//#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
//#define IncEmbSerialACT8
////////////////////////////////////////////
//#include "longtoa.cas"
//#include "Ltoa1.c"
//#include "stdlib.h"
//#include "command.h"
//#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"

#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include "basic.h"
#include "command.h"

/*
const ST_NORMA	= 0;
const ST_LOOP		= 1;
const ST_ERROR1	= 2;
const ST_ERROR2	= 3;
const ST_SEARCH	= 4;
const ST_FAULT	= 5;
const ST_ALARM	= 6;
*/
#define ST_NORMA	(0)
#define ST_LOOP		(1)
#define ST_ERROR1	(2)
#define ST_ERROR2	(3)
#define ST_SEARCH	(4)
#define ST_FAULT	(5)
#define ST_ALARM	(6)


//const BIT_IN_FRAME = 24846;
#define  BIT_IN_FRAME (24846)
//const NUM_OF_CHAN = 16;
#define NUM_OF_CHAN  (16)

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
 */

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




//static char statusStr[25];

int sndRing=0;
int sndAlarm=0;
int sndLock=0;
int	ringOn=0;
int ringBliker=0;


unsigned long counterErrPSP=0l;
unsigned long time1=0l,time2=0l,time3=0l,timeRing=0l,timeRing2=60l;
unsigned long time1p=0l,time2p=0l,time3p=0l;

int state;

unsigned char debug_byte = 0;
unsigned debug_word = 0;

int ACT_type=1;

//void Enable() { asm { sti } }
//void Disable() { asm { cli } }
//_________________________________________________________________________________
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

struct Command
{
	unsigned char chan;
	unsigned char command;
	unsigned char par;
	unsigned char done;
};

//#pragma BSS("-Hpcc")

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
EmbTimerCallback embTimerCallback0;

   //	EmbMsgBuffer rBuffEmbMsg;	
  //tranzit not need	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;

#ifdef MPC35_MOD_CHANNEL	

#ifdef ETH_TRANZIT
EmbMsgBuffer rBuffEmbMsgE;
#endif //ETH_TRANZIT
EmbMsgBuffer rBuffEmbMsgEast;
EmbMsgBuffer rBuffEmbMsgWest;
#else  // MPC35_MOD_CHANNEL
EmbMsgBuffer rBuffEmbMsg;
#endif // MPC35_MOD_CHANNEL	





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
	unsigned short  HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
 //	char s1[25],s2[25];
 //	unsigned char far* bt;
	unsigned char * bt;
	unsigned short  addr1;

	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
	unsigned char mode5A=0, mode5AWest=0, mode5AEast=0; 
	unsigned char mode5A485 =0, mode5A232E=0, mode5A485E=0;
	unsigned char cycle=0;

	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned short err_tr=0;
	unsigned short err_md=0;

	UnEmb2TypeVer unEmb2TypeVer; 
	UnStatePUM unStatePUM;
	UnEmb2Mux34 unEmb2Mux34;
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



//_________________________________________________________________________________



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
/*
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

unsigned long mul (unsigned int a, unsigned int b)
	{
	return (a*b);
	}

 unsigned long ulmul (unsigned long a, unsigned long b)
	{
	return (a*b);  
	}

unsigned long ulmuli(unsigned long l, unsigned int i)
{
 return (l*i);
}

unsigned long uldiv(unsigned long dividend, unsigned long divider)
{
 return (dividend / divider);
}



char *Probability2(unsigned long err, char *str, unsigned long time)
{
   //	unsigned t_err,t_time,tt,up,pp;
	unsigned tt,up,pp;
	int pow=2;
 	time /= (unsigned long)(TIME_CORRECTOR);
	if(!time) time = 1l;

	if(err!=0)
	{
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		time = ulmuli(time,(BIT_IN_FRAME / 100));
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
  //	unsigned t_err,t_time,tt,up,pp;
	unsigned tt,up,pp;
	int pow=3;
   	time /= (unsigned long)(TIME_CORRECTOR);
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
 /*
class EmbTreeACT : public EmbTree
{
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
    unsigned Inport(int port);// { return inport(port); }
   unsigned char Inportb(int port);// { return inportb(port); }
//    void Outport(int port,unsigned value) { outport(port,value); }
    void Outportb(int port, unsigned char value); //{ outportb(port,value); }
};

int psp_number=0;

void EmbTreeACT::Outportb(int port, unsigned char value)
{
	if(port==0x506)
  {
		if(value&0x20)
		{
		  com_err1=0;
		  com_err2=0;
      com_psp = com_psp - com_psp_last_read; //inport(0x518);
		}
    psp_number = value&0x1F;
  }
	outportb(port,value);
}

unsigned EmbTreeACT::Inport(int port)
{
  if(port==0x518)
	{
		if(com_psp>0xFFFF) return 0xFFFF;
		else return 1234;//com_psp;
	}
  if(port==0x51A)
	{
		if(com_err1>0xFFFF) return 0xFFFF;
		else return 1234;//com_err1;
	}
  if(port==0x51C)
	{
		if(com_err2>0xFFFF) return 0xFFFF;
		else return 2345;//com_err2;
	}
	return 5;
	return inport(port);	
}

unsigned char EmbTreeACT::Inportb(int port)
{
  if(port==0x518)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF00;
	}
  if(port==0x519)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF;
	}
  if(port==0x51A)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF;
	}
  if(port==0x51B)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF00;
	}
  if(port==0x51C)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF;
	}
  if(port==0x51D)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF00;
	}
	return inportb(port);	
}

 */
/*
unsigned char EmbTreeACT::Inportb(int port) 
{ 
	unsigned data;
	if(port==0x51A) 
	{
		data = inportb(port); 
		err1 += data;
		return data;
	}
	if(port==0x51B) 
	{
		data = inportb(port); 
		err1 += data<<8;
		outportb(0x506,0x40+psp_number);
		outportb(0x506,0x00+psp_number);
		return data;
	}
	if(port==0x51C) 
	{
		data = inportb(port); 
		err2 += data;
		return data;
	}
	if(port==0x51D) 
	{
		data = inportb(port); 
		err2 += data<<8;
		outportb(0x506,0x80+psp_number);
		outportb(0x506,0x00+psp_number);
		return data;
	}
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
 //	EmbNMI2 embNMI2;

 //	EmbTreeACT embTree;
	EmbTree embTree;

	EmbRS232 embRS232;
	EmbRS485 embRS485;
	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////
/*
void Init()
{
	outport(syscon,0x4500);
	outport(pacs,0x007C);
	outport(mpcs,0x81BF);
}
*/
/*
void LowTiming()
{
	outport(syscon,0x8501);
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


void Delay(unsigned long ms01)
{
  unsigned long i,j;
  for(i=0; i<100; i++)
    for(j=0; j<100; j++);
} 


struct EmbChanACT
{
	unsigned char signal		 : 1;
	unsigned char hdb			 : 1;
	unsigned char ais			 : 1;
	unsigned char reserv1	 : 1;
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

void SaveStateACT34()
{
  int i;
	unsigned char  *ctrl;
//	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);
  //	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x500+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x540+i);

//________________________________add
  *(ctrl+85) = inportb(0x55E);
  //*(ctrl+85) = Inportb(0);
//________________________________add

}

void RestoreStateACT34()
{
  //	unsigned i, j, com;
	unsigned i;
	unsigned char  *ctrl;
 //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

 //	for(i=0; i<24; i++) outportb(0x500+i,*(ctrl+i));
	for(i=0; i<24; i++) outportb(0x540+i,*(ctrl+i));
 //	outportb(0x500,(*ctrl)&0x7F);
	outportb(0x540,(*ctrl)&0x7F);
 //________________________________add
  outportb(0x55E,*(ctrl+85));
//  Outportb(0,*(ctrl+85));	//t
//________________________________add


}
  
struct EmbStateResNew
{
	unsigned char  receive_lc	    : 2;
	unsigned char  reserv_type_lc : 1;
	unsigned char  res1		        : 1;
	unsigned char  receive_rm	    : 2;
	unsigned char  reserv_type_rm : 1;
	unsigned char  res2		        : 1;
};

union UnStateResNew
{
	unsigned char byte;
	EmbStateResNew state;
};

char *UpdateStatusBar(char *str)
{
	int i;
	UnChanACT u;
	UnStateACT us;
	unsigned char byte;
	for(i=0; i<24; i++) str[i] = ' ';
	str[0]='1';
	if(ACT_type) str[4]='2';

  //	us.byte = inportb(0x501);
	us.byte = inportb(0x541);

	if(us.state.seach1) str[1]='+';
	if(us.state.seach2) str[5]='+';
	if(!us.state.error1) str[1]='е';
	if(!us.state.error2) str[5]='е';
	if(!us.state.seach1) str[1]='-';
	if(!us.state.seach2) str[5]='-';
	if(!us.state.ais1) str[1]='a';
	if(!us.state.ais2) str[5]='a';

  //	byte = inportb(0x504);
	byte = inportb(0x544);
	if(byte&0x01) str[2]='*';
	else str[6]='*';

  //	byte = inportb(0x504);
	byte = inportb(0x544);
	if(byte&0x02) str[3]='=';
	else 
	{
		if(byte&0x01) str[3]='>';
		else str[3]='<';
	}

	for(i=0; i<16; i++)
	{
	  //	u.byte = inportb(0x508+i);
		u.byte = inportb(0x548+i);
		if(u.chan.type_sign==0)
		{
				if(u.chan.signal)
				{
					str[8+i] = '+';
					if(!u.chan.hdb) str[8+i] = 'e';
				  if(!u.chan.ais) str[8+i] = 'a';
				}
				else str[8+i] = '-';
		}
		if(u.chan.type_sign==1) str[8+i] = 'п';
		if(u.chan.type_sign==2) str[8+i] = 'о';
		if(u.chan.type_sign==3) str[8+i] = '1';
	}
  //	unsigned char cc = inportb(0x505);
	unsigned char cc = inportb(0x545);
	if(cc) str[7+cc*2] = 'ш';
	str[24]=0; 	
	return str; 	
}

struct EmbActAlarm
{
	unsigned char  fap_pd_lc : 1; 
	unsigned char  fap_pm_lc : 1; 
	unsigned char  fap_pd_rm : 1; 
	unsigned char  fap_pm_rm : 1; 
	unsigned char  input_rm1 : 2; 
	unsigned char  input_rm2 : 2; 
};

union UnACTAlarm
{
	unsigned char byte;
	EmbActAlarm chan;
};

struct EmbActIden
{
	unsigned char  iden1 : 4; 
	unsigned char  iden2 : 4; 
};

union UnActIden
{
	unsigned char byte;
	EmbActIden chan;
};


struct EmbActAlarmState
{
	unsigned char  input_lc1 : 2; 
	unsigned char  input_lc2 : 2; 
	unsigned char  dev_type	 : 1; 
	unsigned char  remote		 : 1; 
	unsigned char  alarm_lc  : 1; 
	unsigned char  alarm_rm  : 1; 
};

union UnACTAlarmState //0x502
{
	unsigned char byte;
	EmbActAlarmState chan;
};

struct EmbChanACTNew
{
	unsigned char  local		 : 2;
	unsigned char  remote		 : 2;
	unsigned char  input		 : 2;
	unsigned char  mode_sign : 1;
	unsigned char  reserv    : 1;
};

union UnChanACTNew
{
	unsigned char byte;
	EmbChanACTNew chan;
};

struct EmbE3ACTNew
{
	unsigned char  Input1		  : 2;
	unsigned char  Input2		  : 2;
	unsigned char  dev_type	  : 1;
	unsigned char  inf_remote : 1;
	unsigned char  lc_alarm   : 1;
	unsigned char  rm_alarm   : 1;
};

union UnE3ACTNew
{
	unsigned char byte;
	EmbE3ACTNew chan;
};

char *UpdateStatusBarNew(char *str)
{
	int i;
	UnChanACTNew u;
	UnE3ACTNew us;
	UnStateResNew ur;
	unsigned char byte;
	for(i=0; i<24; i++) str[i] = ' ';
	str[0]='1';
//	str[4]='2';

   //	us.byte = inportb(0x502);
	us.byte = inportb(0x542);

   	switch(us.chan.Input1)
  //	switch(inportb(0x042) & 0x3)
	{
		case 0: str[1]='+'; break;
		case 1: str[1]='e'; break;
		case 2: str[1]='-'; break;
		case 3: str[1]='a'; break;
	}
  if(0) ///ACT_type)
	{
		switch(us.chan.Input2)
		{
  		case 0: str[5]='+'; break;
  		case 1: str[5]='e'; break;
  		case 2: str[5]='-'; break;
  		case 3: str[5]='a'; break;
		}
   //		byte = inportb(0x504);
		byte = inportb(0x544);
		if(byte&0x02) str[6]='*';
		else str[2]='*';
	 //	ur.byte = inportb(0x504);
		ur.byte = inportb(0x544);
		switch(ur.state.receive_lc)
		{
		  case 0: str[3]='='; break;
		  case 1: str[3]='>'; break;
		  case 2: str[3]='='; break;
		  case 3: str[3]='<'; break;
		}
	}
	for(i=0; i<16; i++)
	{
  //		u.byte = inportb(0x508+i);
		u.byte = inportb(0x548+i);
		switch(u.chan.input)
		{
			case 0:
				switch(u.chan.local)
				{
					case 0: str[8+i] = '+'; break;
					case 1: str[8+i] = 'с'; break;
					case 2: str[8+i] = 'о'; break;
					case 3: str[8+i] = '-'; break;
					default: str[8+i] = '?'; break;
				}		
				break;
			case 1: str[8+i] = 'п'; break;
			case 2: str[8+i] = '0'; break;
			case 3: str[8+i] = '1'; break;
		}			
	}
//  unsigned char cc = (inportb(0x505)&0x1F);
  unsigned char cc = (inportb(0x545)&0x1F);
  if(cc) str[7+cc] = 'ш';
	str[24]=0; 	
//// DEBUG ////
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
 // unsigned char byte;
	char flag = 0;
	char i;
  //	UnChanACT u;
  //	UnStateACT us;
  UnACTAlarmState uas;
 //	uas.byte = inportb(0x502);
	uas.byte = inportb(0x542);

	state = ST_NORMA;

	for(i=0; i<NUM_OF_CHAN; i++)
	{
  //		if((inportb(0x508+i)&0x03)!=0x03) flag = 1;
		if((inportb(0x548+i)&0x03)!=0x03) flag = 1;
	}
	if(!flag) state = ST_LOOP;

	switch(uas.chan.input_lc1)
	{
		case 1: state = ST_ERROR1; break;
		case 2: state = ST_ERROR1; break;
		case 3: state = ST_ERROR1; break;
	}
  if(0)///ACT_type)
	{
		switch(uas.chan.input_lc2)
		{
   //		case 1: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
		case 1: if((inportb(0x544)&0x04)) state = ST_ERROR1; break;
  	  //	case 2: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
		case 2: if((inportb(0x544)&0x04)) state = ST_ERROR1; break;
  	//	case 3: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
		case 3: if((inportb(0x544)&0x04)) state = ST_ERROR1; break;
		}
	}
	UnActIden uai;
 //	unsigned char self_id = inportb(0x500)&0x0F;
	unsigned char self_id = inportb(0x540)&0x0F;
 //	uai.byte = inportb(0x501);
	uai.byte = inportb(0x541);
	if(self_id)
	{
		if((uas.chan.input_lc1==0)||(uas.chan.input_lc1==1)) 
			if(uai.chan.iden1) 
				if(uai.chan.iden1!=self_id) state = ST_FAULT;
		if((uas.chan.input_lc2==0)||(uas.chan.input_lc2==1))
			if(uai.chan.iden2) 
				if(uai.chan.iden2!=self_id) state = ST_FAULT;
	}

 //	if(!uas.chan.alarm_lc) state = ST_ALARM;
	if(uas.chan.alarm_lc) state = ST_ALARM;
	return state;
}


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
	if(!sndAlarm)
	{
		if(!sndLock) embIndicator.SoundAlarm();
	  sndAlarm=1;
	}
}

void MakeRing()
{
 	if(!sndRing) 
 //	if((!sndRing) && (!sndLock)) //my

	{
		embIndicator.SoundRing();
		sndRing=1;
	}
}

void NoMakeRing()
{
//	if(!sndAlarm)
 		if(sndRing)
  //	if((!sndRing) && (!sndLock)) //my

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


void IsRing()
{
	ringBliker++;
  //	if(inportb(0x500)&0x40)
	if(inportb(0x540)&0x40)
	{
    timeRing2=0;
    UnACTAlarmState uas;
  //	uas.byte = inportb(0x502);
	uas.byte = inportb(0x542);
  	if(uas.chan.alarm_lc)
    {
      MakeRing();
		  if(ringBliker%2) embIndicator.SetLtDiod(1,4);
		  else embIndicator.SetLtDiod(0,4);
    }
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
  //		unsigned char port500 = inportb(0x500);
		unsigned char port500 = inportb(0x540);
	 //	outportb(0x500,0x0F&port500);
		outportb(0x540,0x0F&port500);
		ringOn=0;
	}
}

char* sec2time(unsigned long t, char* str)
{
	char ch[12];
	str[0]=0;
	t /= 1000l; //my
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




//________________________________________
  EmbSerialMD34AVT embSerialACT155;	  //090302 to add channel
//_________________________________________________
 	char ch;
	long f_len;
	unsigned r=0;
 	unsigned long j=0;
	unsigned pt_key=0;
	unsigned r1;
	unsigned k=0,b=0,key=0;	 
  EmbCommand embCommand1;
  EmbCommand embCommand2;
  EmbCommand embCommand3;
   char flagDir485=0; // 1 - 232, 2 - Emb
 char dpdfile[DPD_SIZE];
 char *dpd;
  EmbSerialACT8Receive embReceive;
  EmbSerialACT8Send embSend;
   unsigned long p=0;
	char str[25];
	char s1[64];
	char s2[128];
	char sk[64];
	char chk;
	EmbTreePoint *current;
	EmbTreePoint *parent;

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
	unsigned char dev_addr=0, dev_point=0;
	int addr_flag=0;
	int point_flag=0;
	unsigned char port500=0;
  long delay=0;
/////////  DEBUG SECTION  //////////
	int tempDeb = 0;
	char chDeb[32];
	int psp_number=0;
	char dpd_state;

extern "C" void Init_MPC34(void)
{
//__________________________________________________________
 time1=0;time2=0;time3=0;
 //flagADUC1=0; flagADUC2=0;
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





//__________________________________________________________




//	outportb(0x6FF,inportb(0x6FF)|0x10);


///////  Канал транзит  ///////
//	time5=0;
//	outportb(0x5B7, 0x94);
///////////////////////////////
  //	 AsciiInit();
 //tranzit not need   tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();

//	rBuffEmbMsg.Init();
#ifdef   MPC35_MOD_CHANNEL
#ifdef ETH_TRANZIT
    rBuffEmbMsgE.Init();
#endif //ETH_TRANZIT
	rBuffEmbMsgEast.Init();
	rBuffEmbMsgWest.Init();
#else	MPC35_MOD_CHANNEL
	rBuffEmbMsg.Init();
#endif //MPC35_MOD_CHANNEL




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

	int rrr=0;

	unEmb2TypeVer.emb2TypeVer.type       = 0x0200;
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;// 888 <-> 232
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = 0;//SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = 0;//SelfVer2();
	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}

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


}



extern "C" void InitSound(void)
{	
 if(EmbGetSound()) MakeSoundLock();
 else   MakeSoundUnLock();
}


//_________________________________________________
 unsigned char is_send;



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


	 		EmbMsg embMsgEthTransitW;
			EmbMsg embMsgEthTransitE;
		 	EmbMsg embMsgWestE;	 //1223
 			EmbMsgBuffer tBuffEmbMsgEthAll;
			EmbMsgBuffer tBuffEmbMsgEthAll1;


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

#ifdef CASHE_OFF
return 0; //test
#endif

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



extern "C" void Init_MPC35()
{
 is_send = 0;
 // printEthLongHex('1');

//_________________________
EmbInitNVRAM(); //081208
//_________________________

  Init_MPC34();

//_________________________________________________
embSerialACT155.Init(); //090302 to add channel


//_________________________________________________
     r=0;
	 i=0;j=0;
	 pt_key=0;
	 k=0;b=0;key=0;
	 flagDir485=0; // 1 - 232, 2 - Emb
	  p=0;

    ttt=0;last_err=0;
	start_flag=1;
	ctrl_flag=0;
	ctrl_counter=0;
	no_blink=1; color=1;
	old_color=1;
	old_state=0;
	err_mode=0;
	err_flag=0;
	psp_mode=0;
	psp_flag=0;
	psp_flag_counter=0;psp_flag_counter1=0;psp_flag_counter2=0;
	dev_addr=0; dev_point=0;
	addr_flag=0;
	point_flag=0;
	port500=0;
    delay=0l;
/////////  DEBUG SECTION  //////////
	tempDeb = 0;


 sndRing=0;
 sndAlarm=0;
 sndLock=0;
	ringOn=0;
 ringBliker=0;


 counterErrPSP=0;
 time1=0;time2=0;time3=0;timeRing=0;timeRing2=60;
 time1p=0;time2p=0;time3p=0;
 debug_byte = 0;
 debug_word = 0;
 ACT_type=1;

// psp_number=0;
 psp_number=1;


//_________________________________________________


/////  Plug&Play /////
 // ACT_type = inportb(0x500)&0x20; 
  ACT_type = inportb(0x540)&0x20; 		
//////////////////////
	/*
	char ch;
	long f_len;
	unsigned r=0;
	unsigned long i=0,j=0;
	unsigned pt_key=0;
	 */
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
	
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
//port	embTimerCallback0.interval = 1000; 
	embTimerCallback0.interval = 1; //port 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
//////////////////////

 //	EmbTreePoint* embTP;
 //	WORD PointNum,DeviceNum;
 //	embIndicator.Init();

 //	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
 //	embRS485.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

 //	char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
//________________________________________________________________________
//  printEthLongHex('1');
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

//________________________________________________________________________


//ok 	printEthLongHex('2');

   dpd_state =	embTree.SetCfg(dpd,16384); // Инициализируем дерево меню и команд управления
   if(!dpd_state) return;
//ok	 printEthLongHex('3');

  //EmbSerialACT8Receive embReceive;
	embReceive.Init();
 // EmbSerialACT8Send embSend;
	embSend.Init();
//	EmbIsrINT1 embIsrINT1;
//	embIsrINT1.Init();
/*  EmbSerialACT8Control embControl;
  embControl.Init();*/
/////////////  Инициализация последних байтов цикла обмена с АЦТ //////////////
  //	for(i=24; i<32; i++) outportb(0x500+i,0);
	for(i=24; i<32; i++) outportb(0x540+i,0);
///////////////////////////////////////////////////////////////////////////////
  //	embNMI2.Init();
///////////////////////////////////////////////////////////////////////////////
   //	Enable(); // Разрешаем все прерывания
///////////////////////////////////////////////////////////////////////////////
 /*
	unsigned r1;
	unsigned k=0,b=0,key=0;
*/
 // EmbCommand embCommand1;
  embCommand1.Init();
 // EmbCommand embCommand2;
  embCommand2.Init();
 // EmbCommand embCommand3;
  embCommand3.Init();
 // char flagDir485=0; // 1 - 232, 2 - Emb

//// Восстанавливаем состояние регистров АЦТ34 ////
  RestoreStateACT34();

  unsigned char *ctrl;
	ctrl = (unsigned char *)(NVRAM_BASE);//0x80000000;
 // if((*ctrl)&0x10) sndLock=1; // 1-выкл  0-вкл
  if(EmbGetSound())sndLock=1; //port // 1-выкл  0-вкл
	else sndLock=0; 

   ///////////////////////////////////////////////////
	/*
	unsigned long p=0;
	char str[25];
	char s1[64];
	char s2[128];
	char sk[64];
	char chk;
	EmbTreePoint *current;
	EmbTreePoint *parent;
	*/

	for(i=0; i<25; i++) str[i]=0;
///////////////////////////////
  //ok printEthLongHex('4');

	embTree.Down();

 //ok printEthLongHex('6');
	current = embTree.Current();	
	parent = current->Parent();
 //ok	printEthLongHex('8');
	CreateASCIIZ(dpd+embTree.Company(),str);
//	printEthLongHex('7');

	add_str(str,"  ");
	CreateASCIIZ(dpd+embTree.City(),s2);
	add_str(str,s2);
	CopyInd0ToRemote(str);	 //my
	ConvertToWin1251(str);
  embIndicator.SetStr0(str);
	for(i=0; i<25; i++) str[i]=0;
 //ok	printEthLongHex('9');
	CreateASCIIZ(dpd+embTree.Name(),str);
 //  printEthLongHex('1');

	add_str(str," ");
	CreateASCIIZ(dpd+embTree.Version(),s1);
 //ok	printEthLongHex('3');
	add_str(str,s1);
  //bad  printEthLongHex('4');

	add_str(str," ");

	CreateASCIIZ(dpd+embTree.Date(),s2);
	add_str(str,s2);
   // printEthLongHex('2');
	CopyInd1ToRemote(str);	  //my
	ConvertToWin1251(str);
	embIndicator.SetStr1(str);

  embIndicator.Cursor(0,0x81);
// printEthLongHex('0');


  /*
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
	unsigned char dev_addr=0, dev_point=0;
	int addr_flag=0;
	int point_flag=0;
	unsigned char port500=0;
  long delay=0;
/////////  DEBUG SECTION  //////////
	int tempDeb = 0;
	char chDeb[32];
////////////////////////////////////
*/
  embTree.ClearErr1(); 
  embTree.ClearErr2(); 
  InitSound();
  // printEthLongHex('5');
  SetProtokol(EmbGetProt()); //init parameter to start right protokol
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


}

#ifdef MPC35_MOD_CHANNEL

#ifdef ETH_TRANZIT
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





		   
		//	  EmbMsg embMsgEthWest;	 //eth - > transitwest
		 //	  EmbMsg embMsgEthEast;	 //eth -> transiteast
   	 //		  EmbMsgBuffer tBuffEmbMsgEthWest;
	 //		  EmbMsgBuffer tBuffEmbMsgEthEast;
	   		 

 //			  EmbMsg embMsgEastE;
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
/* tranzit not need
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
						default: embSerialACT155.AddTransit(embMsgWest.body[i]);						
					   }
			         }
			 }
				   embSerialACT155.AddTransit(0x55);

*/

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
//090304 #ifdef ETH_TRANZIT	
					rBuffEmbMsgWest.Add(embMsgWest);
//090304 #else  //ETH_TRANZIT
//090304 				    rBuffEmbMsg.Add(embMsgWest);
//090304#endif	//ETH_TRANZIT
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
				embMsgWest.Init(); //101210
				recieveWest = 0;
#ifdef ETH_TRANZIT
			    InitWestE();	 //clear!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif //  ETH_TRANZIT
			}


//		if(!recieveWest)
		{

/* tranzit not need
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
			*/

//hier need init to clear!!!!!
	  //	  InitWestE();	 //clear!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}  //is end
	}	  //while



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

			 /* treanzit not need

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

				  */

			}
  		}
 	}




#ifdef ETH_TRANZIT

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
/* tranzit not need
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
	   */

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
#endif //Eth_Tranzit

#endif // MPC35_MOD_CHANNEL




void MPC34()
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


	//	ResetWatchDog();
/////////  Плата интерфейсов  ///////////
//	unsigned short temp1, temp2;

  /* for bmd35
	unEmb2Mux34.emb2Mux34.numE1 = 16;
	unEmb2Mux34.emb2Mux34.e3 = inportb(0x522);
	unEmb2Mux34.emb2Mux34.err_e3 = (unsigned short)inportb(0x526) + ((unsigned short)inportb(0x527)<<8);
	unEmb2Mux34.emb2Mux34.reserv[0] = inportb(0x524);
 //	 unEmb2Mux34.emb2Mux34.reserv[0] = 0x70; //t
   //	unEmb2Mux34.emb2Mux34.reserv[1] = 0x5;
	unEmb2Mux34.emb2Mux34.softVer = 1;
	unEmb2Mux34.emb2Mux34.type = 1;
	for(i=0; i<16; i++)
	{
		unEmb2Mux34.emb2Mux34.ctrl_e1[i] = inportb(0x590+i);
		unEmb2Mux34.emb2Mux34.state_e1[i] = inportb(0x580+i);
	}
  for bmd35	*/

	/*
	unsigned long tmpread =  (unsigned long)(inportb(0x52A)<<16);
				   tmpread += 	(unsigned long)(inportb(0x529)<<8);
					  tmpread += 	(unsigned long)inportb(0x528);
					  */
	//______________________________
	/*
	unsigned char ver;						// 1
	unsigned char reserv; 				// 2
	unsigned long ulBlock;				// 6
	unsigned long ulErrOut;				// 10
	unsigned long ulErrAfterRS1;	// 14
	unsigned long ulErrAfterRS2;	// 18
	unsigned long ulErrBeforeRS1;	// 22
	unsigned long ulErrBeforeRS2;	// 26
	  */
	//______________________________
	 /*
	 unStatePUM.statePUM.ver = 0x12;
	 unStatePUM.statePUM.reserv = 0x34;
	  unStatePUM.statePUM.reserv1 = 0x56;
	   unStatePUM.statePUM.reserv2 = 0x78;
	 unStatePUM.statePUM.ulBlock = 0x44444444;
   //	  unStatePUM.statePUM.ulBlock1 = 0x9ABCl;

	 unStatePUM.statePUM.ulErrOut = 0x33333333l;
	 unStatePUM.statePUM.ulErrBeforeRS1 = 0x87654321l;
	 unStatePUM.statePUM.ulErrBeforeRS2 = 0x12345678l;
	 unStatePUM.statePUM.ulErrAfterRS1 = 0x11111111l;
	 unStatePUM.statePUM.ulErrAfterRS2 = 0x22222222l;
	   */
	   /* bmd35
   	unStatePUM.statePUM.ulErrBeforeRS1 = (unsigned long)inportb(0x528) + ((unsigned long )inportb(0x529)<<8) + ((unsigned long)inportb(0x52A)<<16);
 //	unEmb2Mux34.emb2Mux34.reserv[0] = unStatePUM.statePUM.state[7] = inportb(0x537);
	unEmb2Mux34.emb2Mux34.reserv[1] = unStatePUM.statePUM.state[7] = inportb(0x537);
	 */

 //0323 	if(!(GetRemoteMode() & 1l))
	if(GetRemoteMode() & 1l)
	{
#include "remotemux.inc"

#ifdef MPC35_MOD_CHANNEL
#ifdef ETH_TRANZIT
   if(EthReceiveTimer > EthReceiveDelay) //t
  {
  	   	ProtocolToEth();
  }
#endif // ETH_TRANZIT
	ProtocolFromModACT155();
//only modem channel!	ProtocolFromTransitACT155();
	Check2InitTransitMod();
#ifdef ETH_TRANZIT
    ProtocolFromEthTransit();
#endif // ETH_TRANZIT
#endif //MPC35_MOD_CHANNEL


	}
}



extern "C" void MPC35()
{
 // char test;
  MPC34();

 //0323 if(GetRemoteMode() & 1l)
 if(!(GetRemoteMode() & 1l))
{
/*	090302

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
	//ok	 printEthLongHex(0x100);

//			if(embRS232.UsedReceive()>COM_BUFFER_SIZE-48) { embRS232.EmptyReceive(); embCommand2.Empty(); }
			if(embCommand2.Add(embRS232.Receive())==2)
			{
	   //		 printEthLongHex(0x101);

				if(embCommand2.GetType()=='@')
				{
		 //		 printEthLongHex(0x102);

					if((embCommand2.GetAddr()==0xFF)&&(embCommand2.GetPoint()==0xFF))
					{
		   //no			 printEthLongHex(0x103);

						char *b=embCommand2.GetStr();
						i=0;
            flagDir485=1; // RS-232
						while(b[i])
            {
              embSend.Add(b[i]);
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
					//	test = 1;
					}
					else
					{
						if((embCommand2.GetAddr()==0)&&(embCommand2.GetPoint()==0))
						{
			 //no			 printEthLongHex(0x104);
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
					  //		test = 2;
						}
						else
						{
							if((embCommand2.GetAddr()==EmbGetAddr())&&(embCommand2.GetPoint()==EmbGetPoint()))
							{
						//ok		 printEthLongHex(0x105);
				  //>>>>>>>>>>>>>>>>>>>>hier
								embTree.SetRequest(embCommand2.GetStr());
							//	 printEthString(embTree.request, 128);
								embTree.CommandDecoder();

								embTree.GetAnswer(a);

 						//		printEthString(a, 100);

								i=0;
								while(a[i]) embRS232.Trans(a[i++]);
								embCommand2.Empty();
								for(i=0; i<128; i++) a[i]=0;
						  //		test = 3;
							}
							else
							{
                if(embCommand2.GetPoint()==EmbGetPoint())
                {
                  flagDir485=1; // RS-232
                  char *b=embCommand2.GetStr();
                  i=0;
                  while(b[i]) embRS485.Trans(b[i++]);
								  embCommand2.Empty();
                }
                else
                {
                  char *b=embCommand2.GetStr();
                  i=0;
                  while(b[i]) embSend.Add(b[i++]);
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
						while(b[i]) embSend.Add(b[i++]);
						embCommand2.Empty();
					}
					else
					{
						embCommand2.Empty();
					}
				}
			}
		}
		if(embReceive.Used())
		{
			if(embCommand1.Add(embReceive.Get())==2)
			{
				if(embCommand1.GetType()=='@')
				{
					if((embCommand1.GetAddr()==0xFF)&&(embCommand1.GetPoint()==0xFF))
					{
						char *b=embCommand1.GetStr();
						i=0;
            flagDir485=2; // EMB
						while(b[i])
            {
              embRS232.Trans(b[i]);
              embRS485.Trans(b[i]);
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
						while(c[i]) embSend.Add(c[i++]);
						embCommand1.Empty();
						for(i=0; i<128; i++) c[i]=0;
					}
					else
					{
						if((embCommand1.GetAddr()==EmbGetAddr())&&(embCommand1.GetPoint()==EmbGetPoint()))
						{
							embTree.SetRequest(embCommand1.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(c);
							i=0;
							while(c[i]) embSend.Add(c[i++]);
							embCommand1.Empty();
							for(i=0; i<128; i++) c[i]=0;
						}
            else
            {
              if(embCommand1.GetPoint()==EmbGetPoint())
              {
                flagDir485=2; // EMB
                char *b=embCommand1.GetStr();
                i=0;
                while(b[i]) embRS485.Trans(b[i++]);
                embCommand1.Empty();
              }
              else
              {
                char *b=embCommand1.GetStr();
                i=0;
                while(b[i]) embRS232.Trans(b[i++]);
                embCommand1.Empty();
              }
            }
					}
				}
				else
				{
					if(embCommand1.GetType()=='&')
					{
						char *b=embCommand1.GetStr();
						i=0;
						while(b[i]) embRS232.Trans(b[i++]);
						embCommand1.Empty();
					}
					else
					{
						embCommand1.Empty();
					}
				}
			}
// printEthLongHex(test);

		}

////// 485
    if(embRS485.UsedReceive())
		{
//			if(embRS232.UsedReceive()>COM_BUFFER_SIZE-48) { embRS232.EmptyReceive(); embCommand2.Empty(); }
			if(embCommand3.Add(embRS485.Receive())==2)
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
            int ib=0;
						a[1] = HexChar(EmbGetPoint()>>4);
						a[2] = HexChar(EmbGetPoint()&0x0F);
						a[3] = HexChar(EmbGetAddr()>>4);
						a[4] = HexChar(EmbGetAddr()&0x0F);
            while(a[i]) embRS485.Trans(a[i++]); 
            embCommand3.Empty();
						for(i=0; i<128; i++) a[i]=0;				
          }
          else
          {
						if((embCommand3.GetAddr()==EmbGetAddr())&&(embCommand3.GetPoint()==EmbGetPoint()))
						{
              for(i=0; i<128; i++) a[i]=0;
							embTree.SetRequest(embCommand3.GetStr());
					   //		printf(">");
							embTree.CommandDecoder();
							embTree.GetAnswer(a);
							i=0;
              int ib=0;
              while(a[i]) embRS485.Trans(a[i++]);
							embCommand3.Empty();
							for(i=0; i<128; i++) a[i]=0;
						}
          }
        }
				else
				{
	 //_____________________________________________________________
		  if( (embCommand3.GetType()=='&')	&&	 (embCommand3.GetAddr()==EmbGetAddr()) && (embCommand3.GetPoint()==EmbGetPoint()) )
		  {
		 //	printf("!");
		  flagDir485=0;		//0227
		  embCommand3.Empty();	 //0227

		  }



          char *b=embCommand3.GetStr();
					i=0;

		   //witch this work property			printf("%d", flagDir485);

          switch(flagDir485)
          {
            case 1: while(b[i]) embRS232.Trans(b[i++]); break;
            case 2: while(b[i]) embSend.Add(b[i++]); break;
            default: embCommand3.Empty();
          }
          flagDir485=0;
		  embCommand3.Empty();
        }
	}
}

090302   */
//_____________________________________________________________________________090302 >>>>
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
	  		if(embCommand2.Add(embRS232.Receive()) == 2)
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
  //090302		  embSerialACT155.AddTransit(b[i]); //t
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
		 //		    embSerialACT155.AddMod(b[i]);  //t
				    embSerialACT155.AddMod(b[i]);  //t
	   //090302	  			embSerialACT155.AddTransit(b[i++]); //t
					i++;
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
		  	  //090302			 embSerialACT155.AddTransit(b[i++]); //t
							i++;
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
	 //	printf("\n\r 2");
   //t   if(embCommand1.Add(embReceive.Get())==2)
     //	tmp_dbg1 = 	 embSerialACT155.GetMod();
	 //	tmp_dbg2 = 	 embCommand1.Add(tmp_dbg1);
	 //	printf(".%c", (unsigned char)tmp_dbg1);

   	   if(embCommand1.Add( embSerialACT155.GetMod())==2)
   	//   if(tmp_dbg2==2)
		  {
		if(embCommand1.GetType()=='@')
		   {
              debug_word++;
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
	 //090302		  embSerialACT155.AddTransit(b[i]);

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
						if((embCommand1.GetAddr()==EmbGetAddr())&&(embCommand1.GetPoint()==EmbGetPoint()))
						{
							embTree.SetRequest(embCommand1.GetStr());
							embTree.CommandDecoder();
							embTree.GetAnswer(c);
							i=0;
							while(c[i]) //embSend.Add(c[i++]);  //to modem
							 embSerialACT155.AddMod(c[i++]);  //t
							embCommand1.Empty();
              for(i=0; i<128; i++) c[i]=0;
						}
            else
            {
              if(embCommand1.GetPoint()==EmbGetPoint())
              {
                flagDir485=2; // EMB
                char *b=embCommand1.GetStr();
                i=0;
				 is_send = 1; //my

                while(b[i]) embRS485.Trans(b[i++]);
                embCommand1.Empty();
              }
              else
              {
                char *b=embCommand1.GetStr();
                i=0;
                while(b[i])// embRS232.Trans(b[i++]);	// & transit
				{
				   embRS232.Trans(b[i]);		  //t
	  //090302			   embSerialACT155.AddTransit(b[i++]); //t
					 i++;
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
						char *b=embCommand1.GetStr();
						i=0;
						while(b[i])// embRS232.Trans(b[i++]);	// transit
						{
						   embRS232.Trans(b[i]);
			 //090302		  	   embSerialACT155.AddTransit(b[i++]); //t
							i++;

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
 /* 090302
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

 090302 */
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
	  //090302	  			embSerialACT155.AddTransit(b[i++]); //t
					 i++;	
					}
               break;
            default: embCommand3.Empty();
          }
		           flagDir485=0;
					embCommand3.Empty();				
        }
		} //
			}
		}



//_____________________________________________________________________________090302 <<<<



} //remotemode




//////////////////////////////////////
//////////////////////////////////////
///////////  Индикатор  //////////////
//////////////////////////////////////
//////////////////////////////////////

//////////  Счетчик ПСП  /////////////
		
	   	if(!psp_flag_counter)//(inportb(0x506)&0x20)) 
		{
			psp_flag_counter2++;
	    if(psp_flag_counter2 > DELAY_PSP)
			{
				psp_flag_counter=1;
				psp_flag_counter2=0;
				unsigned c_psp,c_err1,c_err2;
		  //		c_psp=inport(0x518);
			   outport(0x558, 0xff);
			  //	delay_mcs(1000l);
			//	c_psp=inportx(0x558) & 0xff;
				c_psp=inportx(0x558);
			  //	delay_mcs(1000l);

			  //	 c_psp+=inportx(0x558);
			   //	 delay_mcs(100l);

			 //	outport(0x558, 0xff);
			//	c_err1=inport(0x51A);
			   outport(0x55A, 0xff);

			   			 //	delay_mcs(100);
			   //	c_err1=inportx(0x55A) & 0xff;
				c_err1=inportx(0x55A);
			  

				 outport(0x55C, 0xff);
			 //	c_err2=inport(0x51C);
						 //	delay_mcs(100);
			  //	c_err2=inportx(0x55C) & 0xff;
				c_err2=inportx(0x55C);
				  


				counterErrPSP += c_psp;

			//	if(c_psp)printEthLongHex(c_psp);

				embTree.err1+=c_err1;
				embTree.err2+=c_err2;
				embTree.com_err1+=c_err1;
				embTree.com_err2+=c_err2;
				embTree.com_psp+=c_psp;
			 //	outportb(0x506,0x20+psp_number);
		  //t1203		outportb(0x546,0x20+psp_number);
			}
		}
		else
  //		if(psp_flag_counter)//(inportb(0x506)&0x20)) 
		{

			psp_flag_counter1++;
	    if(psp_flag_counter1 > DELAY_PSP)
			{
				psp_flag_counter=0;				
				psp_flag_counter1=0;
		  //	  outportb(0x506,0x00+psp_number);
		  	  outportb(0x546,0x00+psp_number);
			}
		}


//////////////////////////////////////

		if(!dpd_state) return;

		if(embIndicator.Used()) 
		{
			chk=embIndicator.Get();
			if(('0'<chk)&&(chk<='9')) { key = chk; }
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
						 //	outportb(0x506,0x40+psp_number);
						 //	outportb(0x506,0x00+psp_number);
							outportb(0x546,0x40+psp_number);
							outportb(0x546,0x00+psp_number);
							embTree.ClearErr1(); 
							time1p=1;
						break;
						case PT_ERR2:	
						//	outportb(0x506,0x40+psp_number);
						//	outportb(0x506,0x00+psp_number);
							outportb(0x546,0x40+psp_number);
							outportb(0x546,0x00+psp_number);
							embTree.ClearErr2(); 
							time2p=1;
						break;
						case PT_ERR_PSP:	
						  //	outportb(0x506,0x20+psp_number);
							outportb(0x546,0x20+psp_number);
//							outportb(0x506,0x00+psp_number);
							counterErrPSP=0; 
							time3p=1;
						break;
						case PT_RING:	
							NoMakeRing();
						break;
					}
					ctrl_counter=0;
					SaveStateACT34();
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
					SaveStateACT34();
					break;
				case 0x33: 	// Enter	
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
								embIndicator.Cursor(0,0xD7);
							}
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
								outportb(0x506,psp_number);
								embIndicator.Cursor(0,0xD7);
							}
						break;
						case PT_RING:	
							timeRing=0;
							ringOn=1;
						 //	port500=inportb(0x500);
							port500=inportb(0x540);
						//	outportb(0x500,0x80|(port500&0x0F));
							outportb(0x540,0x80|(port500&0x0F));
						break;
						case PT_CTRL:
							if(!ctrl_flag) 
							{
								ctrl_flag=1;
								embIndicator.Cursor(2,0xD7);
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

							 //	ctrl_counter = embTree.GetParameterNum();
							}
							else 
							{
								pt_key = PT_NULL;
								ctrl_flag=0;
								embIndicator.Cursor(0,0xD7);
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
							}
						break;
					}
    //082911      Delay(100000);
					SaveStateACT34();
					break;																		 
				case 0x34: // Left
					if(psp_flag)
					{
						psp_number--;
					//	if(psp_number<0) psp_number=NUM_OF_CHAN;
						if(psp_number<1) psp_number=NUM_OF_CHAN;
						counterErrPSP=0;
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
					SaveStateACT34();
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
					SaveStateACT34();
					break;										  
				case 0x36: // Righ
					if(psp_flag)
					{
						psp_number++;
				   //		if(psp_number>NUM_OF_CHAN) psp_number=0;
						if(psp_number>NUM_OF_CHAN) psp_number=1;
						counterErrPSP=0;
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
					SaveStateACT34();
					break;                   
				case 0x37: // Esc + Enter
//          Enable();
//          asm { db 0eah, 00, 0ah, 00, 27h }
					break;                   
				case 0x38: // Right + Left
						timeRing=0;
						ringOn=1;
					 //	port500=inportb(0x500);
						port500=inportb(0x540);
					 //	outportb(0x500,0x80|(port500&0x0F));
						outportb(0x540,0x80|(port500&0x0F));
					break;                   
				case 0x39: // Up + Down
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
					  //		BYTE i;
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
//____________________________________________________________________
	  if(embTree.LexCmp(current->Name(),"Версия"))
    				{
			   			FillProgVersion1(&s2[8] , 8);

					  }
	  				else if(embTree.LexCmp(current->Name(),"ПЛИС"))
					  {
				  		 FillXilinxVersion1(&s2[6] , 6);
				  	  }



//____________________________________________________________________


					
//_______________________________________________________________________________

				else
				{
					EmbParameter *par = current->Parameter();
					if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
					{
						if(!ctrl_flag) ctrl_counter = embTree.GetParameterNum();
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
					
						if(embTree.LexCmp(current->Name(),"ОшибкиE3"))
						{
							pt_key = PT_ERR1;
						}
						else 
						{
							if(embTree.LexCmp(current->Name(),"ОшибкиE3_N2"))
							{
								pt_key = PT_ERR2;
							}
							else
							{
								if(embTree.LexCmp(current->Name(),"ОшПСП_Е1"))
								{
									pt_key = PT_ERR_PSP;
							   //		if(!psp_flag) psp_number = inportb(0x506)&0x1F;
									if(!psp_flag) psp_number = inportb(0x546)&0x1F;
									char chp[12];
									itoa(psp_number,chp,10);
									s2[9]='N';
									s2[10]=0;
									add_str(s2,chp);
									add_str(s2,":");
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
	//	if(r>4000)
		if(r > DELAY_MENU)
		{
			r=0;
			p++;
			old_color = color;
			old_state=state;
/////////////  Тестирование звонка  /////////////////////
	   		IsRing();
/////////////////////////////////////////////////////////
			switch(UpdateState())
			{
				case ST_NORMA:  no_blink=1; color=3; break;
				case ST_LOOP:   no_blink=0; color=3; break;
				case ST_ERROR1: no_blink=1; color=2; break;
				case ST_ERROR2: no_blink=1; color=2; break;
				case ST_SEARCH: no_blink=1; color=2; break;
				case ST_FAULT:  no_blink=0; color=1; break;
				case ST_ALARM:  no_blink=1; color=1; break;
				default: no_blink=1; color=3; break; 
			}
		 	if(state==ST_ALARM) MakeAlarm(); 
			else NoMakeAlarm();

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
								if(!ctrl_flag) ctrl_counter = embTree.GetParameterNum();
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
							if(embTree.LexCmp(current->Name(),"ОшибкиE3"))
							{
								embTree.ViewParameter(str);
								for(i=0; i<24; i++) sk[i]=0;
								if(err_mode==0)
								{
									if(embTree.Err1()==1) add_str(s2, "<");
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
								if(embTree.LexCmp(current->Name(),"ОшибкиE3_N2"))
								{
									embTree.ViewParameter(str);
									for(i=0; i<24; i++) sk[i]=0;
                  if(0)///ACT_type)
                  {
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
								}
								else
								{
									if(embTree.LexCmp(current->Name(),"ОшПСП_Е1"))
									{
										pt_key = PT_ERR_PSP;
								  //		if(!psp_flag) psp_number = inportb(0x506)&0x1F;
										if(!psp_flag) psp_number = inportb(0x546)&0x1F;
										char chp[12];
										itoa(psp_number,chp,10);
										s2[9]='N';
										s2[10]=0;
										add_str(s2,chp);
										add_str(s2,":");
										for(i=0; i<24; i++) sk[i]=0;
										if(psp_mode==0) 
                      if(counterErrPSP==0)
                      {
                        add_str(s2, "<");
                        ProbabilityPSP(1, sk, time3);
                      }
                      else
                        ProbabilityPSP(counterErrPSP, sk, time3p);
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
										 //	unsigned char self_id = inportb(0x500)&0x0F;
											unsigned char self_id = inportb(0x540)&0x0F;
										//	uai.byte = inportb(0x501);
											uai.byte = inportb(0x541);
										 //	uas.byte = inportb(0x502);
											uas.byte = inportb(0x542);
										 //	ua.byte = inportb(0x503);
											ua.byte = inportb(0x543);
											int norma_flag = 1;
											if(ua.chan.fap_pd_lc) { add_str(s2,"ФАПЧ_ПД(м)  "); norma_flag = 0; }
											if(ua.chan.fap_pm_lc) { add_str(s2,"ФАПЧ_ПМ(м)  "); norma_flag = 0; }
											if(ua.chan.fap_pd_rm) { add_str(s2,"ФАПЧ_ПД(у)  "); norma_flag = 0; }
											if(ua.chan.fap_pm_rm) { add_str(s2,"ФАПЧ_ПМ(у)  "); norma_flag = 0; }

											if(uas.chan.input_lc1==3) { add_str(s2,"СИАС1(м) "); norma_flag = 0; }
											else
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
                      if(0)///ACT_type)
                      {
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
                      if(0)///ACT_type)
                      {
                        if(ua.chan.input_rm2==3) { add_str(s2,"СИАС2(у) "); norma_flag = 0; }
                        else
                        {
                          if(ua.chan.input_rm2==2) { add_str(s2,"Поиск2(у) "); norma_flag = 0; }
                          else
                          {
                            if(ua.chan.input_rm2==1) { add_str(s2,"Ошибки2(у) "); norma_flag = 0; }
                          }
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
extern "C" void time_notify_core(void)	// called frequency = 1 ms
 {
 //hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;
 } 
//_______________________________________________________________________
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
	if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq0();
 }

}

//_____________________________________________________________________________




//_________________________________________________________________________

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


void test_PU37_1()
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
if(PeriodCounter > (TEST_PERIOD * 4))
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

				   	   outportb(0x50B, tup0++);
				   //	   outportb(0x50B, 0xE7);
								 tup0c++;     
							//	 } 
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
   					  	 outportb(0x50D, tup1++);
					  //	    outportb(0x50D, 0xE7);
   						 tup1c++;
   //						 }
//}
	 // TX MODEM
//for (i=0; i<8; i++)
//{
 				   //		 while((inportb(0x505) & 0x02) == 0) {}
  // bstate =  inportb(0x508);
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x508) & 0x20)
					//	 {
					   	 outportb(0x507, tm++);
					   //   outportb(0x507, 0xE7);
						 tmc++;
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
				   		 outportb(0x509,  ttz++); 
					//	    outportb(0x509, 0xE7);
						ttzc++;
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
					r(0x50d);
					r (rup1o!=rup1)
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



