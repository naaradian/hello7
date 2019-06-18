#ifndef __TINY__
#define __TINY__
#endif
#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
#define IncEmbRS232
#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
#define IncEmbIndicator
#define IncEmbSerialACT8
////////////////////////////////////////////
#include "longtoa.cas"
#include "Ltoa1.c"
#include "stdlib.h"
#include "command.h"
#include "embisr.cpp"
#include "basic'.h"
#include "basic'.cpp"

const BIT_IN_FRAME = 31522;
const NUM_OF_CHAN = 4;

int ACT_type=1; // 1 = двухствольный   0 = одноствольный

void Enable() { asm { sti } }
void Disable() { asm { cli } }

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
	unsigned i[2];
};

/// 186 specific
// this returns 32 bit value from 16bit*16bit
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
// returns 64 bit value of result
// *(result) - lower unsigned long
// *(result+1) - upper unsigned long
// unsigned long*
// result - lower unsigned long
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

// this returns 48 bit value
// unsigned int*
// this returns lower long of 48 bit structure
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

char *Probability2(unsigned long err, char *str, unsigned long time)
{
	unsigned t_err,t_time,tt,up,pp;
	int pow=1;
	if(err!=0)
	{
		while(time>100) { time = uldiv(time,10); pow++; if(pow==32) break; }
		time = ulmuli(time,BIT_IN_FRAME/100);
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
	unsigned t_err,t_time,tt,up,pp;
	int pow=3;
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
		  com_psp = com_psp - com_psp_last_read;
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

char *add_str(char *target, char *source)
{
	int j=0,i=0; 
	while(target[i]) i++;
	while(source[j]) target[i+j]=source[j++];
	return target;
}
	EmbNMI2 embNMI2;
	EmbTreeACT embTree;
	EmbRS232 embRS232;
	EmbRS485 embRS485;
	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////
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
  if((s>=0)&&(s<=9)) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 0;
}

unsigned long time1=0,time2=0,time3=0,timeRing=0,timeRing2=60;

void Callback0()
{
  time1++;
  time2++;
  time3++;
	timeRing++;
	timeRing2++;
}

EmbTimerCallback embTimerCallback0;

const PT_NULL    = 0;
const PT_ERR1    = 1;
const PT_ERR2    = 2;
const PT_ERR_PSP = 3;
const PT_CTRL    = 4;
const PT_RING    = 5;
const PT_SOUND   = 6;
const PT_ADDR    = 7;
const PT_POINT   = 8;

static char statusStr[25];

struct EmbChanACT
{
	unsigned signal		 : 1;
	unsigned hdb			 : 1;
	unsigned ais			 : 1;
	unsigned reserv1	 : 1;
	unsigned type_sign : 2;
	unsigned mode_sign : 1;
	unsigned reserv2   : 1;
};

union UnChanACT
{
	unsigned char byte;
	EmbChanACT chan;
};

struct EmbStateACT
{
	unsigned seach1		: 1;
	unsigned seach2		: 1;
	unsigned error1		: 1;
	unsigned error2		: 1;
	unsigned alarm		: 1;
	unsigned ring			: 1;
	unsigned ais1     : 1;
	unsigned ais2     : 1;
};

union UnStateACT
{
	unsigned char byte;
	EmbStateACT state;
};

struct EmbStateRes
{
	unsigned receive	   : 1;
	unsigned reserv_mode : 1;
	unsigned reserv_type : 1;
	unsigned res1		     : 5;
};

union UnStateRes
{
	unsigned char byte;
	EmbStateRes state;
};

void SaveStateACT34()
{
	int i;
	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80000000;
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x500+i);
}

void RestoreStateACT34()
{
	unsigned i, j, com;
	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80000000;
	for(i=0; i<24; i++) outportb(0x500+i,*(ctrl+i));
	outportb(0x500,(*ctrl)&0x7F);
}

struct EmbStateResNew
{
	unsigned receive_lc	    : 2;
	unsigned reserv_type_lc : 1;
	unsigned res1		        : 1;
	unsigned receive_rm	    : 2;
	unsigned reserv_type_rm : 1;
	unsigned res2		        : 1;
};

union UnStateResNew
{
	unsigned char byte;
	EmbStateResNew state;
};

struct EmbActAlarm
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
	unsigned iden1 : 4; 
	unsigned iden2 : 4; 
};

union UnActIden
{
	unsigned char byte;
	EmbActIden chan;
};


struct EmbActAlarmState
{
	unsigned input_lc1 : 2; 
	unsigned input_lc2 : 2; 
	unsigned dev_type	 : 1; 
	unsigned remote		 : 1; 
	unsigned alarm_lc  : 1; 
	unsigned alarm_rm  : 1; 
};

union UnACTAlarmState //0x502
{
	unsigned char byte;
	EmbActAlarmState chan;
};

struct EmbChanACTNew
{
	unsigned local		 : 2;
	unsigned remote		 : 2;
	unsigned input		 : 2;
	unsigned mode_sign : 1;
	unsigned reserv    : 1;
};

union UnChanACTNew
{
	unsigned char byte;
	EmbChanACTNew chan;
};

struct EmbE3ACTNew
{
	unsigned Input1		  : 2;
	unsigned Input2		  : 2;
	unsigned dev_type	  : 1;
	unsigned inf_remote : 1;
	unsigned lc_alarm   : 1;
	unsigned rm_alarm   : 1;
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
	if(ACT_type) str[4]='2';

	us.byte = inportb(0x502);

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
		byte = inportb(0x504);
		if(byte&0x02) str[6]='*';
		else str[2]='*';
		ur.byte = inportb(0x504);
		switch(ur.state.receive_lc)
		{
		  case 0: str[3]='='; break;
		  case 1: str[3]='>'; break;
		  case 2: str[3]='='; break;
		  case 3: str[3]='<'; break;
		}
	}
	for(i=0; i<NUM_OF_CHAN; i++)
	{
		u.byte = inportb(0x508+i);
		switch(u.chan.input)
		{
			case 0:
				switch(u.chan.local)
				{
					case 0: str[9+i*4] = '+'; break;
					case 1: str[9+i*4] = 'с'; break;
					case 2: str[9+i*4] = 'о'; break;
					case 3: str[9+i*4] = '-'; break;
					default: str[9+i*4] = '?'; break;
				}		
				break;
			case 1: str[9+i*4] = 'п'; break;
			case 2: str[9+i*4] = '0'; break;
			case 3: str[9+i*4] = '1'; break;
		}			
	}
	unsigned char cc = inportb(0x505)&0x07;
	if(cc) str[5+cc*4] = 'ш'; //5
	str[24]=0; 	
	return str; 	
}

unsigned long counterErrPSP=0;

int state;

const ST_NORMA	= 0;
const ST_LOOP		= 1;
const ST_ERROR1	= 2;
const ST_ERROR2	= 3;
const ST_SEARCH	= 4;
const ST_FAULT	= 5;
const ST_ALARM	= 6;

int UpdateState()
{
  unsigned char byte;
	char flag = 0;
	char i;
	UnChanACT u;
	UnStateACT us;
  UnACTAlarmState uas;
	uas.byte = inportb(0x502);

	state = ST_NORMA;

	for(i=0; i<NUM_OF_CHAN; i++)
	{
		if((inportb(0x508+i)&0x03)!=0x03) flag = 1;
	}
	if(!flag) state = ST_LOOP;

	switch(uas.chan.input_lc1)
	{
		case 1: state = ST_ERROR1; break;
		case 2: state = ST_ERROR1; break;
		case 3: state = ST_ERROR1; break;
	}
  if(ACT_type)
	{
		switch(uas.chan.input_lc2)
		{
  		case 1: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
  		case 2: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
  		case 3: if((inportb(0x504)&0x04)) state = ST_ERROR1; break;
		}
	}
	UnActIden uai;
	unsigned char self_id = inportb(0x500)&0x0F;
	uai.byte = inportb(0x501);
	if(self_id)
	{
		if((uas.chan.input_lc1==0)||(uas.chan.input_lc1==1)) 
			if(uai.chan.iden1) 
				if(uai.chan.iden1!=self_id) state = ST_FAULT;
		if((uas.chan.input_lc2==0)||(uas.chan.input_lc2==1))
			if(uai.chan.iden2) 
				if(uai.chan.iden2!=self_id) state = ST_FAULT;
	}
	if(uas.chan.alarm_lc) state = ST_ALARM;

	return state;
}

int sndRing=0;
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
	if(!sndAlarm)
	{
		if(!sndLock) embIndicator.SoundAlarm();
	  sndAlarm=1;
	}
}

void MakeRing()
{
	if(!sndRing) 
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

int	ringOn=0;
int ringBliker=0;

int IsRing()
{
	ringBliker++;
	if(inportb(0x500)&0x40)
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
		unsigned char port500 = inportb(0x500);
		outportb(0x500,0x0F&port500);
		ringOn=0;
	}
}

char* sec2time(unsigned long t, char* str)
{
	char ch[12];
	str[0]=0;
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

void main()
{
/////  Plug&Play /////
  ACT_type = inportb(0x500)&0x20; 	
//////////////////////
	char ch;
	long f_len;
	unsigned r=0;
	unsigned long i=0,j=0;
	unsigned pt_key=0;

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
	embTimerCallback0.interval = 1000; 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
  char flagDir485=0; // 1 - 232, 2 - Emb

//////////////////////

	EmbTreePoint* embTP;
	WORD PointNum,DeviceNum;
	embIndicator.Init();

	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
	embRS485.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

	char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
	embTree.SetCfg(dpd,16384); // Инициализируем дерево меню и команд управления

  EmbSerialACT8Receive embReceive;
	embReceive.Init();
  EmbSerialACT8Send embSend;
	embSend.Init();
//	EmbIsrINT1 embIsrINT1;
//	embIsrINT1.Init();
/*  EmbSerialACT8Control embControl;
  embControl.Init();*/
/////////////  Инициализация последних байтов цикла обмена с АЦТ //////////////
	for(i=24; i<32; i++) outportb(0x500+i,0);
///////////////////////////////////////////////////////////////////////////////
	embNMI2.Init();
///////////////////////////////////////////////////////////////////////////////
	Enable(); // Разрешаем все прерывания
///////////////////////////////////////////////////////////////////////////////
	unsigned r1;
	unsigned k=0,b=0,key=0;

  EmbCommand embCommand1;
  embCommand1.Init();
  EmbCommand embCommand2;
  embCommand2.Init();
  EmbCommand embCommand3;
  embCommand3.Init();
//// Восстанавливаем состояние регистров АЦТ34 ////
  RestoreStateACT34();
///////////////////////////////////////////////////

	unsigned long p=0;
	char str[25];
	char s1[64];
	char s2[128];
	char sk[64];
	char chk;
	EmbTreePoint *current;
	EmbTreePoint *parent;
	for(i=0; i<25; i++) str[i]=0;
///////////////////////////////

	embTree.Down();
	current = embTree.Current();	
	parent = current->Parent();
	CreateASCIIZ(dpd+embTree.Company(),str);
	add_str(str,"  ");
	CreateASCIIZ(dpd+embTree.City(),s2);
	add_str(str,s2);
	ConvertToWin1251(str);
  embIndicator.SetStr0(str);
	for(i=0; i<25; i++) str[i]=0;
	CreateASCIIZ(dpd+embTree.Name(),str);
	add_str(str,"   ");
	CreateASCIIZ(dpd+embTree.Version(),s1);
	add_str(str,s1);
	add_str(str," ");
	CreateASCIIZ(dpd+embTree.Date(),s2);
	add_str(str,s2);
	ConvertToWin1251(str);
	embIndicator.SetStr1(str);

  embIndicator.Cursor(0,0x81);

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
/////////  DEBUG SECTION  //////////
	int tempDeb = 0;
	char chDeb[32];
////////////////////////////////////
  embTree.ClearErr1(); 
  embTree.ClearErr2(); 

	while(1)
	{
		ResetWatchDog();
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
//			if(embRS232.UsedReceive()>COM_BUFFER_SIZE-48) { embRS232.EmptyReceive(); embCommand2.Empty(); }
			if(embCommand2.Add(embRS232.Receive())==2)
			{
				if(embCommand2.GetType()=='@')
				{
					if((embCommand2.GetAddr()==0xFF)&&(embCommand2.GetPoint()==0xFF))
					{
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
					}
					else
					{
						if((embCommand2.GetAddr()==0)&&(embCommand2.GetPoint()==0))
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
							embTree.CommandDecoder();
							embTree.GetAnswer(a);
							i=0;
              while(a[i]) embRS485.Trans(a[i++]);
							embCommand3.Empty();
							for(i=0; i<128; i++) a[i]=0;
						}
          }
        }
				else
				{
          char *b=embCommand3.GetStr();
					i=0;
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
//////////////////////////////////////
//////////////////////////////////////
///////////  Индикатор  //////////////
//////////////////////////////////////
//////////////////////////////////////

//////////  Счетчик ПСП  /////////////
		
		if(psp_flag_counter)//(inportb(0x506)&0x20)) 
		{

			psp_flag_counter1++;
	    if(psp_flag_counter1>500)
			{
				psp_flag_counter=0;				
				psp_flag_counter1=0;
			  outportb(0x506,0x00+psp_number);
			}
		}
		else
		{
			psp_flag_counter2++;
	    if(psp_flag_counter2>500)
			{
				psp_flag_counter=1;
				psp_flag_counter2=0;
				unsigned c_psp,c_err1,c_err2;
				c_psp=inport(0x518);
				c_err1=inport(0x51A);
				c_err2=inport(0x51C);
				counterErrPSP+=c_psp;
				embTree.err1+=c_err1;
				embTree.err2+=c_err2;
				embTree.com_err1+=c_err1;
				embTree.com_err2+=c_err2;
				embTree.com_psp+=c_psp;
				outportb(0x506,0x20+psp_number);
			}
		}
//////////////////////////////////////
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
							outportb(0x506,0x40+psp_number);
							outportb(0x506,0x00+psp_number);
							embTree.ClearErr1(); 
							time1=1;
						break;
						case PT_ERR2:	
							outportb(0x506,0x40+psp_number);
							outportb(0x506,0x00+psp_number);
							embTree.ClearErr2(); 
							time2=1;
						break;
						case PT_ERR_PSP:	
							outportb(0x506,0x20+psp_number);
//							outportb(0x506,0x00+psp_number);
							counterErrPSP=0; 
							time3=1;
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
							port500=inportb(0x500);
							outportb(0x500,0x80|(port500&0x0F));
						break;
						case PT_CTRL:
							if(!ctrl_flag) 
							{
								ctrl_flag=1;
								embIndicator.Cursor(2,0xD7);
								ctrl_counter = embTree.GetParameterNum();
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
									  if(ctrl_counter) MakeSoundLock(); // 1-выкл  0-вкл
										else MakeSoundUnLock(); 
									}
								}
							}
						break;
					}
					SaveStateACT34();
					break;																		 
				case 0x34: // Left
					if(psp_flag)
					{
						psp_number--;
						if(psp_number<0) psp_number=NUM_OF_CHAN;
						counterErrPSP=0;
						time3=1;
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
						if(psp_number>NUM_OF_CHAN) psp_number=0;
						counterErrPSP=0;
						time3=1;
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
					break;                   
 				case 0x38: // Right + Left
						timeRing=0;
						ringOn=1;
						port500=inportb(0x500);
						outportb(0x500,0x80|(port500&0x0F));
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
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
						}
					}			
				}
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
					
						if(embTree.LexCmp(current->Name(),"ОшибкиE2_N1"))
						{
							pt_key = PT_ERR1;
						}
						else 
						{
							if(embTree.LexCmp(current->Name(),"ОшибкиE2_N2"))
							{
								pt_key = PT_ERR2;
							}
							else
							{
								if(embTree.LexCmp(current->Name(),"ОшПСП_Е1"))
								{
									pt_key = PT_ERR_PSP;
									if(!psp_flag) psp_number = inportb(0x506)&0x1F;
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
			ConvertToWin1251(s2);
			embIndicator.SetStr1(s2);

//	    embIndicator.SetLtDiod(0,4);
			key=0;
		}
		r++;
		if(r>4000)
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
					ConvertToWin1251(s1);
					embIndicator.SetStr0(s1);

			    CreateASCIIZ(dpd+current->Name(),s2);
	
					if(!current->Child()) 
					{
						add_str(s2," : ");
						////
						EmbParameter *par = current->Parameter();

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
							if(embTree.LexCmp(current->Name(),"ОшибкиE2_N1"))
							{
								embTree.ViewParameter(str);
								for(i=0; i<24; i++) sk[i]=0;
                if(err_mode==0)
                {
                  if(embTree.Err1()==1) add_str(s2, "<");
                  Probability2(embTree.Err1(), sk, time1);
                }
                if(err_mode==1)	sec2time(time1, sk); 
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
								if(embTree.LexCmp(current->Name(),"ОшибкиE2_N2"))
								{
									embTree.ViewParameter(str);
									for(i=0; i<24; i++) sk[i]=0;
                  if(ACT_type)
                  {
                    if(err_mode==0)
                    {
                      if(embTree.Err2()==1) add_str(s2, "<");
                      Probability2(embTree.Err2(), sk, time2);
                    }
                    if(err_mode==1)	sec2time(time2, sk); 
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
										if(!psp_flag) psp_number = inportb(0x506)&0x1F;
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
                        ProbabilityPSP(counterErrPSP, sk, time3);
										if(psp_mode==1)	sec2time(time3, sk); 
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
											unsigned char self_id = inportb(0x500)&0x0F;
											uai.byte = inportb(0x501);
											uas.byte = inportb(0x502);
											ua.byte = inportb(0x503);
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
                      if(ACT_type)
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
                      if(ACT_type)
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
					ConvertToWin1251(s2);
					embIndicator.SetStr1(s2);
				}
////
			}
		}
//////////////////////////////////////////
	}
}
