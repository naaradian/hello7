  /*
#define __TINY__
#ifndef __TINY__
#define __TINY__
#endif

#include <stdarg.h>
#include <stdio.h>

#include <dos.h>

//#define IncEmbRS232
#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbSerialACT8
#define IncEmbIndicator

#include "start.h"
#include "longtoa.cas"
#include "Ltoa1.c"
#include "command.h"
#include "embisr.cpp"
 port  */
//_____________________________________________port
#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include "fio.h"
#include "command.h"
#include "cs24regs.h" //port
#include "basic.h"
#include "load11.h"
#include "ktvm2000.h"
#include "sound.h"
//+ projekt files:
//ktvm200.cpp
//load11.cpp
//sound.cpp
//api16.cpp





//_____________________________________________port
//port #include "basic'.h"
//port #include "basic'.cpp"



/*
class EmbTreeTVM : public EmbTree
{
	unsigned lastport;
	public:
    unsigned Inport(int port);// { return inport(port); }
	unsigned char Inportb(int port);// { return inportb(port); }
  void Outportb(int port, unsigned char value); //{ outportb(port,value); }
};
 */
EmbIndicator embIndicator;
EmbRS485 embRS485;
EmbRS232 embRS232;	  //port
//port EmbTreeTVM  embTree;
EmbTree  embTree;  //port

EmbTimer embTimer;
EmbTimerCallback embTimerCallback0;
//this need init
/* port
const unsigned char video_on  =   0x0001; // Наличие входного видеосигнала
const unsigned char start_err =   0x0002; // Ошибка инициализации кодера
const unsigned char Fifo_full =   0x0040; // Ошибка инициализации кодера

const unsigned char stuff_err =   0x0004; // Ошибка  кодера
const unsigned char VLD_off   =   0x0008; // Ошибка  кодера
const unsigned char video_int =   0x0010; // Прерывание по видеосигналу
const unsigned char start_ok  =   0x0020; // Старт кодера
 */
 //port

//_______________NEED INIT THIS!!!!!!!!!!!!!!!!!!!!



unsigned char en_sts =    0;
short int cvbs_cnt=0;
char dpd_state;

//port void Enable() { asm { sti } }
//port void Disable() { asm { cli } }

void Callback0()
{
//	if(cvbs_cnt>5) en_sts &= ~start_ok;
	if(en_sts & video_on) cvbs_cnt=0; else cvbs_cnt++;
//>>>>added from mf20
 //	time1++;
 //   time2++;
 //   time3++;
//<<<<added from mf20

}
//>>>>added from mf20
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
//<<<<added from mf20

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
 //port  if((s>=0)&&(s<=9)) return s + '0';
  if((s<=9)) return s + '0';	  //port
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
  return 0;
}
 /* port
void restart()
{
	int i;
	outportb(0x6FF,0x00);
	outportb(0x601,0x80);
	for(i=0; i<1000; i++){
		outport(0xffe6,0xaaaa);		   //for outport hier long value ? need make this
		outport(0xffe6,0x5555);		   //this is reset_wd();?
		//outportb(0x6FA,0x00);
	}
	outportb(0x601,0x00);
	unsigned x = inport(piodat0);
	outport(piodat0, x | 0x0001);
//asm { db 0fah, 0eah, 0b3h,07h,00h,27h; } //версия БУ 137
 //port	asm { db 0fah, 0eah, 0b7h,07h,00h,27h; } //версия БУ 138

}

  */
//port #include "cs24regs.h"
// port #include ".cpp"
//port #include "load11.cpp"
//#include "pts11.cpp"

char *utoa(int v, char *s)
{
  int  r,w;
  int  i,j;
  int  rs;

  if(v<0){
    *s++='-';
    w=v*(-1);
  }
  else w=v;
  rs=0;
  j=10000;
  for(i=5;i;i--){
    r=(w-rs)/j;
    rs+=(r*j);
    if(rs)*s++=r+48;
    j/=10;
  }
  return s;
}


union wword{
	unsigned char c[2];
 //port 	unsigned int i;
	unsigned short int i;  //port
};


char *utoh(unsigned w,char* s)
{
  char c;
  wword r;

  r.i=w;
  c=r.c[1];
  if(((c&0xf0)>>4)>9) *s++=((c&0xf0)>>4)+87;
    else s[0]=((c&0xf0)>>4)+48;
  if((c&0x0f)>9) *s++=(c&0x0f)+87;
    else *s++=(c&0x0f)+48;
  c=r.c[0];
  if(((c&0xf0)>>4)>9) *s++=((c&0xf0)>>4)+87;
    else *s++=((c&0xf0)>>4)+48;
  if((c&0x0f)>9) *s++=(c&0x0f)+87;
    else *s++=(c&0x0f)+48;
	
  return s;
}


//void main()
 EmbCommand embCommand2;
 EmbCommand embCommand3;
 char a[128];
 char c[128];
 char dpdfile[DPD_SIZE];
 char  *dpd;  // = (char far *)0x10000000; // Адрес необходимо уточнить

//port void Encoder_Set(char *, EmbCommand , EmbCommand , EmbTreeTVM , char *);
// port extern "C" void Encoder_Set(char *, EmbCommand , EmbCommand , EmbTreeTVM , char *);
//extern "C" void Encoder_Set(char *, EmbCommand , EmbCommand , char *);
//extern "C" void Encoder_Set(char *, EmbCommand , EmbCommand);
//extern "C" void Encoder_Set(char *);   // , EmbCommand , EmbCommand);
extern "C" void Encoder_Set(void);   // , EmbCommand , EmbCommand);


extern "C" void  _arm920t_dcache_disable(void);	//t090416
extern "C" void  _arm920t_icache_disable(void);	//t090416


#ifdef KTVM_PROT2
extern "C" void  init_remote_prot2();
#endif //KTVM_PROT2



extern "C" void ktvm_init1()  //this was first version
{

  _arm920t_dcache_disable();	//t090416
  _arm920t_icache_disable();	//t090416


//_________________________
EmbInitNVRAM(); //090226
//_________________________


 // unsigned r=0;
//  unsigned long i=0,j=0;
 InitFreePtr();


//  char ch;
 // long f_len;
  
 //___________________________________
 en_sts = 0;
 cvbs_cnt = 0;

  AsciiInit();
  EmbInit();
  embIndicator.Init();  // Инициализация Индикатора
///////////////////////////////////////////////////////////////////////////////
  
	embTimer.Init(40); // *0.1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 150; 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

/////////////////////////////////  MAX  ///////////////////////////////////////
//	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
 //not hier	embRS485.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

  //port 	char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
    ReadDPD(dpdfile);
 //	dpd = (char *)0x10000000; // Адрес необходимо уточнить
	dpd = dpdfile;
  //ok
  //t	embTree.SetCfg(dpd,2048); // Инициализируем дерево меню и команд управления
 //t	embTree.SetCfg(dpd,40000); //t // Инициализируем дерево меню и команд управления
	dpd_state =  embTree.SetCfg(dpd,40000);

#ifdef KTVM_PROT2
   SetProtokol(EmbGetProt()); //init parameter to start right protokol
   init_remote_prot2();
#endif //KTVM_PROT2  

	 if(!dpd_state) return;


 //0x20143b3c	printEthLongHex((unsigned long)embTree.Current());
//ok
///////////////////////////////////////////////////////////////////////////////	
//	Enable();
	embIndicator.SetLtDiod(0,1);
	embIndicator.SetLtDiod(0,2);
	embIndicator.SetLtDiod(1,3);
	embIndicator.SetLtDiod(0,4);
/////////////////////////////////  MAX  ///////////////////////////////////////
//port	char a[128];
//port	char c[128];

 //port 	int flagDir485=0;
//port   EmbCommand embCommand2;
  embCommand2.Init();
//port  EmbCommand embCommand3;
  embCommand3.Init();
/////////////////////////////////  MAX  ///////////////////////////////////////

	Init_sound();

  //  printEthLongHex((unsigned long)current);
 //0x20143b3c  printEthLongHex((unsigned long)embTree.Current());
  		
 //port 	Encoder_Set(a,embCommand2,embCommand3,embTree,dpd);
 //  printEthLongHex((unsigned long)(dpd));
  //t	Encoder_Set(a,embCommand2,embCommand3,dpd);
 //	Encoder_Set(a,embCommand2,embCommand3);
  //	Encoder_Set(a); //,embCommand2,embCommand3);
	Encoder_Set(); //,embCommand2,embCommand3);	



   

   //port  for(;;);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< add from sergey
void portb(char p,char c)
{
	char * pPLL;
//	pPLL = (char *) (0x30000000)+p; 
	pPLL = (char *) ((0x30000000)+ p); 	 //my make common addr
	*pPLL=c;
//	printf("TESTn\r");
}


void SetPll()
{
/*
 //	printf("init pll\n\r");
         outportb(0xe2,0x72);
         outportb(0xe2,0x04);
         outportb(0xe1,0xff);
         outportb(0xf0,0x00);
 //	printf("init pll\n\r");
         outportb(0xe2,0x96);
         outportb(0xe2,0x0c);
         outportb(0xe1,0xff);
         outportb(0xf0,0x00);
*/
	outportb(0xe2,0x96);		delay_mcs(1l);
	outportb(0xe2,0x0c);		delay_mcs(1l);
	outportb(0xe1,0xff);	    delay_mcs(1l);
    outportb(0xe1,0x00);		delay_mcs(10l);
	outportb(0xe2,0x72);		delay_mcs(1l);
	outportb(0xe2,0x04);	   	delay_mcs(1l);
	outportb(0xe1,0xff);	    delay_mcs(1l);
    outportb(0xe1,0x00);		delay_mcs(1l);

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< add from sergey




extern "C" void ktvm_init()	  //this is changing variant using from sergey programm 
{
//printf("\n\r ... void ktvm_init");

//090604  _arm920t_dcache_disable();	//t090416
//090604  _arm920t_icache_disable();	//t090416


//_________________________
EmbInitNVRAM(); //090226
//_________________________


 // unsigned r=0;
//  unsigned long i=0,j=0;
 InitFreePtr();


//  char ch;
 // long f_len;
  
 //___________________________________
 en_sts = 0;
 cvbs_cnt = 0;

  AsciiInit();
  EmbInit();
  embIndicator.Init();  // Инициализация Индикатора
///////////////////////////////////////////////////////////////////////////////
  
	embTimer.Init(40); // *0.1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 150; 
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

/////////////////////////////////  MAX  ///////////////////////////////////////
//	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
 //not hier	embRS485.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с

  //port 	char far *dpd = (char far *)0x10000000; // Адрес необходимо уточнить
    ReadDPD(dpdfile);
 //	dpd = (char *)0x10000000; // Адрес необходимо уточнить
	dpd = dpdfile;
  //ok
  //t	embTree.SetCfg(dpd,2048); // Инициализируем дерево меню и команд управления
 //t	embTree.SetCfg(dpd,40000); //t // Инициализируем дерево меню и команд управления

//printf("\n\r ... start SetCfg");
	dpd_state =  embTree.SetCfg(dpd,40000);

//printf("\n\r ... finish SetCfg");

 //	dpd_state = 0; //t

#ifdef KTVM_PROT2
   SetProtokol(EmbGetProt()); //init parameter to start right protokol
   init_remote_prot2();
#endif //KTVM_PROT2    


	 if(!dpd_state) return;
//printf("\n\r dpd_state not zero");

 //0x20143b3c	printEthLongHex((unsigned long)embTree.Current());
//ok
///////////////////////////////////////////////////////////////////////////////	
//	Enable();
	embIndicator.SetLtDiod(0,1);
	embIndicator.SetLtDiod(0,2);
	embIndicator.SetLtDiod(1,3);
	embIndicator.SetLtDiod(0,4);
/////////////////////////////////  MAX  ///////////////////////////////////////
//port	char a[128];
//port	char c[128];

 //port 	int flagDir485=0;
//port   EmbCommand embCommand2;
  embCommand2.Init();
//port  EmbCommand embCommand3;
  embCommand3.Init();
/////////////////////////////////  MAX  ///////////////////////////////////////
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  It Was
/* 090504 to make changes
	Init_sound();

  //  printEthLongHex((unsigned long)current);
 //0x20143b3c  printEthLongHex((unsigned long)embTree.Current());
  		
 //port 	Encoder_Set(a,embCommand2,embCommand3,embTree,dpd);
 //  printEthLongHex((unsigned long)(dpd));
  //t	Encoder_Set(a,embCommand2,embCommand3,dpd);
 //	Encoder_Set(a,embCommand2,embCommand3);
  //	Encoder_Set(a); //,embCommand2,embCommand3);
	Encoder_Set(); //,embCommand2,embCommand3);	
 090504	*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 It Was
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>to hier add from sergey


/* move to start_ktvm
	 outportb(0x13,0x08);	// new

 outportb(0xe2,0x96);	// new
 delay_mcs(1);
  outportb(0xe2,0x0c);	// new
  delay_mcs(1);


   outportb(0xe1,0xff);	// new
    delay_mcs(1);

    outportb(0xe1,0x00);	// new
	 delay_mcs(1);




 outportb(0xe2,0x72);	// new
  delay_mcs(1);

  outportb(0xe2,0x04);	// new
   delay_mcs(1);



   outportb(0xe1,0xff);	// new
    delay_mcs(1);

    outportb(0xe1,0x00);	// new
	 delay_mcs(1);



	LoadCoder(1);  //this is calling i2c with parameter1

	
	SetPll();

 	printf("init test3\n\r");
	outportb(0x14,0xc0);	// ??? need
    outportb(0x15,0x08);	// ??? need

 //t	portb(0xe1,0x0);  //?? need 
	outportb(0xe1,0x0);  //?? need //090603 

	printf("init test4\n\r");

*/
//will moved to Encoder_Set !	start();
 //printf("\n\r ...Start ... Encoder_Set");
	Encoder_Set(); //is add from me		- imitate void start



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<to hier add from sergey



 
 // printf("\n\r ..finish ... ktvm_init");
   //port  for(;;);
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : none
* Cid)
* Returned Value   : none
* Ce is used to port embisr to be called from timer isr
*END*----------------------------------------------------------------------*/

extern "C" void time_notify_core(void)	// called frequency = 1 ms
 {
 // hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;
 } 


#ifdef KTVM_PROT2

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
 unsigned short aI, aS, aR;
 unsigned char mode5A=0, mode5AWest=0, mode5AEast=0; 
 unsigned char mode5A485 =0, mode5A232E=0, mode5A485E=0;
 unsigned char flagRequest=0;
 unsigned char * bt;
 unsigned short  addr1;
 unsigned char cycle=0;

int short i232;
unsigned char byte;
extern unsigned long i;


EmbMsg embMsgA;
EmbMsg embMsgAns;
EmbMsg embMsg232;
EmbMsg embMsg485;
EmbMsg embMsg485E;
EmbMsg embMsg232E;
EmbMsg *embMsgRequest;

UnEmb2TypeVer unEmb2TypeVer; //need init!

extern "C" void init_remote_prot2(void)
{
  printf("\n\r init_remote_prot2");
 temp_crc = 0 ;
 shift = 0;
 len = 0;
 aI = 0; aS = 0; aR = 0;
 mode5A=0; mode5AWest=0; mode5AEast=0; 
 mode5A485 =0; mode5A232E=0; mode5A485E=0;
 flagRequest=0;
 bt =  (unsigned char *)NVRAM_BASE;
 addr1 = 0;
 cycle=0;
 i232 = 0;
 byte = 0;
 i = 0;

 embMsgA.Init();
 embMsgAns.Init();
 embMsg232.Init();
 embMsg485.Init();
 embMsg485E.Init();
 embMsg232E.Init();

    unEmb2TypeVer.emb2TypeVer.type       = 0x1000;
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





}



extern "C" void remote_prot2(void)
{
//printEthLongHex(0x12);
 #include "remoteend.inc"
}
#endif // KTVM_PROT2



