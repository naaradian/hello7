//#include "api16.h"
#include "hello7.h"
#include "EMBISR.H"
#include "Basic.h"
//#include "ktvm2000.h" 
#include "command.h" 
#include "load11.h"
#include "sound.h"
#include "ktvm2000.h"
 
#define TEST_OUT
#define RC_Success 0x80
#define ReedS 0x38  // RS + interleaver
//#define ReedS 0x00

#define ENCODER
//#define AUDIO2

 DWORD MAILBOX;
extern char dpd_state;


/* port
const int MIData = 0x510;
const int MICmd  = 0x511;
const int MISts  = 0x512;
const int MIRes  = 0x513;
const int MISet  = 0x514;
const int MISlt  = 0x515;
//const int MIPll  = 0x516;
const int MIInt  = 0x517;
const int MIBuff  = 0x516;

const char MIRD = 0x00;
const char MIWR = 0x20;
const char MIRq = 0x40;
const char MICS = 0x80;

const char MIRST = 0x08;
const char MIRDY = 0x02;
const char MIROM = 0x01;
const char MILDC = 8;
const char MIRSTA = 0x10;
  */
//_____________________Need init
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>port
/*
#define MIData (0x510)
#define MICmd  (0x511)
#define MISts  (0x512)
#define MIRes  (0x513)
#define MISet  (0x514)
#define MISlt  (0x515)
//const int MIPll  = 0x516;
#define MIInt  (0x517)
#define MIBuff (0x516)

#define MIRD  (0x00)
#define MIWR  (0x20)
#define MIRq  (0x40)
#define MICS  (0x80)

#define MIRST  (0x08)
#define MIRDY  (0x02)
#define MIROM  (0x01)
#define MILDC  (8)
#define MIRSTA (0x10)
*/
 //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<port

short int pwr_test=1;
short int PTSon=0;

void SetPrint(unsigned short int m,int r)
{
/*port
  unsigned char far *p;
  unsigned int far *pt;
  unsigned char far *ts;
	*/
//>>>>>>>>>>>>>>>>>>>>>>port
  unsigned char  *p;
  unsigned short int  *pt;
  unsigned char  *ts;
//<<<<<<<<<<<<<<<<<<<<<<<port
  unsigned short int print_ptr=0;

 //port  Disable();	//need disable interrupts hier?
 /*port
	pt = (unsigned int far*)0x80000030;//0x80001FF8;
    print_ptr=*pt;

  ts = (unsigned char far*)0x80007ff8;//0x80001FF8;
  p  = (unsigned char far*)0x80000100;//0x80001FF8;
  */

 pt = (unsigned short int *)0x10000030;// can make "int" from clocks?
 print_ptr=*pt;
 ts = (unsigned char *)0x10007ff8;//
 p  = (unsigned char *)0x10000100;//

	if(print_ptr > 0x3e00) print_ptr = 0;  //? int work hier ?

  switch(r){
    case 0:    *(p+print_ptr)=0xff; break;
    case 1:    *(p+print_ptr)=0xaa; break;
    case 2:    *(p+print_ptr)=0x55; break;
    case 3:    *(p+print_ptr)=0xee; break;
    case 4:    *(p+print_ptr)=0xcc; break;
    default:   *(p+print_ptr)=0xff;
  }
  print_ptr++;
  *(p+print_ptr)=(unsigned char)((m>>8) & 0x00ff);
  print_ptr++;
  *(p+print_ptr)=(unsigned char)(m & 0x00ff);
  print_ptr++;

  *ts=0x40;

 //port  ts = (unsigned char far*)0x80007ffe;
	 ts = (unsigned char *)0x10007ffe;

	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts-=2;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
  *ts=0x0;
  
	*pt=print_ptr;
// port  Enable();
}

char *add_str(char *target, char *source)
{
	int j=0,i=0; 
	while(target[i]) i++;
	while(source[j]) target[i+j]=source[j++];
	return target;
}

unsigned char GetMode()
{
//printf("\n\r GetMode()");

 //port	unsigned char far *p;
//port	p = (unsigned char far*)0x80000000;//
  unsigned char *p;
//  p = (unsigned char *)0x10000000;//
  p = (unsigned char *)0x10000014;//
  return *p;
}

void SetMode(unsigned char m)
{
//printf("\n\r SetMode()");


//	unsigned char far *p;
//	p = (unsigned char far*)0x80000000;//0x80001FF8;
// unsigned char *p;
// p = (unsigned char *)0x10000014;//
// *p=m;
 
 SetRate(m);
}

unsigned char GetVideoIn()
{

//printf("\n\r GetVideoIn()");

//	unsigned char far *p;
//	p = (unsigned char far*)0x80000001;//0x80001FF8;
 unsigned char *p;
 p = (unsigned char *)0x10000001;//
 return *p;
}

void SetVideoIn(unsigned char m)
{
//printf("\n\r SetVideoIn()");

/*
 //	unsigned char far *p;
 //	p = (unsigned char far*)0x80000001;//0x80001FF8;
 unsigned char *p;
 p = (unsigned char *)0x10000001;//
 *p=m;
 */
 SetVideo(m);
}

unsigned char GetStopKadr()
{
//printf("\n\r GetStopKadr()");

 //	unsigned char far *p;
 //	p = (unsigned char far*)0x80000002;//0x80001FF8;
 	unsigned char *p;
 	p = (unsigned char *)0x10000002;//
	return *p;
}

void SetStopKadr(unsigned char m)
{
//printf("\n\r SetStopKadr()");
/*
  //	unsigned char far *p;
  //	p = (unsigned char far*)0x80000002;//0x80001FF8;
 	unsigned char *p;
 	p = (unsigned char *)0x10000002;//
 	*p=m;
	*/
	SetTestSignal1(m);
}

unsigned char GetSound()
{
//printf("\n\r GetSound()");
 //	unsigned char far *p;
 //	p = (unsigned char far*)0x80000003;//0x80001FF8;
 	unsigned char *p;
 	p = (unsigned char *)0x10000003;//
	return *p;
}

void SetSound(unsigned char m)
{
printf("\n\r SetSound()");
 /*
 //	unsigned char far *p;
 //	p = (unsigned char far*)0x80000003;//0x80001FF8;
	unsigned char *p;
 	p = (unsigned char *)0x10000003;//
	*p=m;
	*/
	SetSound1(m);
}



unsigned char GetStat()
{
//printf("\n\r GetStopKadr()");
 //	unsigned char far *p;
 //	p = (unsigned char far*)0x80000004;//0x80001FF8;
// unsigned char *p;
// p = (unsigned char *)0x10000004;//
// return *p;

 unsigned char  t_r_d;
 t_r_d  = inportb(0x12);
 if(t_r_d & SIGNAL_MASK) return 0; //no signal
 return 1;

}

void SetStat(unsigned char m)
{

printf("\n\r SetStat()");
/*
//	unsigned char far *p;
//	p = (unsigned char far*)0x80000004;//0x80001FF8;
 unsigned char *p;
 p = (unsigned char *)0x10000004;//
 *p=m;
 */
 SetState1(m);
}
/*
unsigned char GetError()
{
	unsigned char far *p;
	p = (unsigned char far*)0x80000005;//0x80001FF8;
	return *p;
}

void SetError(unsigned char m)
{
	unsigned char far *p;
	p = (unsigned char far*)0x80000005;//0x80001FF8;
	*p=m;
}
*/
//enum video_input { IN1=0, IN2=1, YC=2};
//enum stop_frame {OFF=0, ON=1};

//port const int MISpi  = 0x516;
//Need initialize!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//short int MISpi  = 0x516; //port
//t #define  MISpi  (0x516)
#define  MISpi  (0x16) //port

// Инициализация платы декодера ПАЛ/СЕКАМ
void spi_init()
{
  int i=0;

  while(inportb(MISts) & 0x40){ if(i>5000) return; else i++; }
    outportb(MISpi,0x0f); i=0;
  while(inportb(MISts) & 0x01){ if(i>5000) return; else i++; } 
    outportb(MISpi,0x11);
  while(inportb(MISts) & 0x01); 
    outportb(MISpi,0x01);
  while(inportb(MISts) & 0x01); 
    outportb(MISpi,0x00);
  while(inportb(MISts) & 0x01); 
  while(inportb(MISts) & 0x40); 
}

// Переключение входных сигналов
void spi_in(unsigned short in)
{
  int i=0;
  char c;
  while(inportb(MISts) & 0x40){ if(i>5000) return; else i++; }
	outportb(MISpi,0x0f); i=0;
  while(inportb(MISts) & 0x01){ if(i>5000) return; else i++; }      
	outportb(MISpi,0x80);
  while(inportb(MISts) & 0x40); 

  while(inportb(MISts) & 0x40); 
	outportb(MISpi,0x0f);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x21);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x04);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x01);
  while(inportb(MISts) & 0x01);     outportb(MISpi,in);
  c=~(0x01 + in)+1;
  while(inportb(MISts) & 0x01);     outportb(MISpi,c);
  while(inportb(MISts) & 0x01); 
  while(inportb(MISts) & 0x40); 
}

// Стоп-кадр
void spi_stop(unsigned short st)
{
  int i=0;
  char c;
  while(inportb(MISts) & 0x40){ if(i>5000) return; else i++; }
	outportb(MISpi,0x0f); i=0;
  while(inportb(MISts) & 0x01){ if(i>5000) return; else i++; }     
	outportb(MISpi,0x80);
  while(inportb(MISts) & 0x40); 

  while(inportb(MISts) & 0x40); 
	outportb(MISpi,0x0f);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x21);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x04);
  while(inportb(MISts) & 0x01);     outportb(MISpi,0x13);
  while(inportb(MISts) & 0x01);     outportb(MISpi,st);
  c=~(0x02 + st)+1;
  while(inportb(MISts) & 0x01);     outportb(MISpi,c);
  while(inportb(MISts) & 0x01); 
  while(inportb(MISts) & 0x40); 
}

 
void wd_res()
{
//	unsigned x;
//	x=inport(0xff74)^0x1000;
///	outport(0xff74,x);
 //port 	outportb(0x06fb,0xaa);
//port 	outport(0xffe6,0xaaaa);
 //port 	outport(0xffe6,0x5555);
 //it was before sergey 	wd_reset();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>from sergey
	unsigned int i,a;
	for(i=0;i<35;i++) a++;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>from sergey
}
  

//*******************************************************************
//
//                 iTVC16
//
//*******************************************************************

int ivac_mem_write(unsigned long a,unsigned long d)
{
	int i=0;
	EmbDWord Addr,Data;
	Addr.l=a; Data.l=d;
  outportb(MICmd,0x02);
	outportb(MIData,Data.c[0]);    
	outportb(MIData,Data.c[1]);    
	outportb(MIData,Data.c[2]);    
	outportb(MIData,Data.c[3]);   

	outportb(MIData,(Addr.c[2] & 0x7f)|0x40);    
	outportb(MIData,Addr.c[1]);    
	outportb(MIData,Addr.c[0]);   
  inportb(MICS);
	return 0;
}

//port unsigned long ivac_set_mem()
void ivac_set_mem() //port
{
	outportb(MICmd,0x04);
	outportb(MIData,0x04);    
}

unsigned long ivac_mem_read(unsigned long a)
{
	int i=0;
	EmbDWord Addr,Data;
	Addr.l=a; 
    outportb(MICmd,0x00);
	outportb(MIData,Addr.c[2] & 0x3f);    
	outportb(MIData,Addr.c[1]);    
	outportb(MIData,Addr.c[0]);    
    inportb(MICS);
    inportb(MICS);
	outportb(MIData,0);   
	Data.c[0]=inportb(MIData);   
	Data.c[1]=inportb(MIData);    
	Data.c[2]=inportb(MIData);    
	Data.c[3]=inportb(MIData);    
	return Data.l;
}



int ivac_reg_write(unsigned long a,unsigned long d)
{
	int i=0;
	EmbDWord Addr,Data;
	Addr.l=a; Data.l=d;
    outportb(MICmd,0x03);
	outportb(MIData,Data.c[0]);    
	outportb(MIData,Data.c[1]);    
	outportb(MIData,Data.c[2]);    
	outportb(MIData,Data.c[3]);    

	outportb(MIData,Addr.c[0]);    
	outportb(MIData,Addr.c[1]);    
	outportb(MIData,0x01);         
	while(!(inportb(MICS) & MIRDY))
	{
		i++; wd_res();
		 if(i>500)
		 {
		 //port return 1;
	 //port	  printff("Err reg wr");
 	      return 1;
	     }	 //temporary printff do not touch
	}
	return 0;
}

unsigned long ivac_reg_read(unsigned long a)
{
	int i=0;
	EmbDWord Addr,Data;
	Addr.l=a; 
    outportb(MICmd,0x01);
	outportb(MIData,Addr.c[0]);    
	outportb(MIData,Addr.c[1]);    
	outportb(MIData,0);   
    inportb(MICS);
    inportb(MICS);
	Data.c[0]=inportb(MIData);   
	Data.c[0]=inportb(MIData);   
	Data.c[1]=inportb(MIData);    
	Data.c[2]=inportb(MIData);    
	Data.c[3]=inportb(MIData);    
    inportb(MICS);
    inportb(MICS);

	return Data.l;
}

//port #include "api16.cpp"

void FWtest_crc()
{
 //port  unsigned char far *p;
//  unsigned char *p;
  unsigned char crc;
	unsigned short int i;
//	unsigned long l,lc;
	unsigned long lc;

    EmbDWord Addr;
	EmbDWord t;

	lc=0;
	crc=0;
//port  Disable();
	wd_res();
	
	for(i=0;i<0x4000;i++){
		Addr.l=i;
		t.l=ivac_mem_read(Addr.l);
		lc+=t.l;
	}
	wd_res();

	for(i=0;i<0x4000;i++){
		Addr.l=i+0x4000;
		t.l=ivac_mem_read(Addr.l);
		lc+=t.l;
	}
	wd_res();
	
	for(i=0;i<0x4000;i++){
		Addr.l=i+0x8000;
		t.l=ivac_mem_read(Addr.l);
		lc+=t.l;
	}
	wd_res();

	for(i=0;i<0x4000;i++){
		Addr.l=i+0xc000;
		t.l=ivac_mem_read(Addr.l);
		lc+=t.l;
	}
  if(lc!=0xff8f4d60){
		printff("crc error lc=%X",lc);
  }else printff("Test FW ok!");
}

//port int InitIvac()
#define DELAY_KTVM1		(100)
void InitIvac1()	 //it was before sergey
{
//	EmbDWord Data,Addr;
//port	int i;
    unsigned long i;
//	char c;
	unsigned long l,Tmp,Tmp2;
 //port	Disable();
	outportb(MIRes,0x04);
 //ok	
//	printff("STS=%x",inportb(MISts));
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
 //port	printff("load11");
	outportb(MIRes,0x07);  delay_mcs(DELAY_KTVM1);//             for(i=0;i<4500;i++) wd_res();	    // wait 52.5 ms (7.125us * N)
  //ok	
	ivac_reg_write(0x0048,0xffffffff); delay_mcs(DELAY_KTVM1); // for(i=0;i<20;i++) wd_res();	//hier fall!!!    // wait  ms (7.125us * N)
   
	Tmp =ivac_reg_read(0x900c);	delay_mcs(DELAY_KTVM1); //        for(i=0;i<25;i++) wd_res();	    // wait  ms (7.125us * N)
 //ok 
	Tmp2=ivac_reg_read(0x9020); delay_mcs(DELAY_KTVM1);//        for(i=0;i<25;i++) wd_res();	    // wait  ms (7.125us * N)
   
	outportb(MIRes,0x04); // Reset off
	delay_mcs(203000l);

 // for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
	outportb(MIRes,0x07); // Reset on
	delay_mcs(DELAY_KTVM1);

 // for(i=0;i<1450;i++) wd_res();	    // wait 10.15 ms (7.125us * N)

	ivac_reg_write(0xa064,0x00000000); delay_mcs(DELAY_KTVM1);//     for(i=0;i<25;i++) wd_res();	     // wait 176 us  (7.125us * N)
  ivac_reg_write(0x9020,(0x00000400|Tmp2)); delay_mcs(DELAY_KTVM1); // for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x900c,Tmp);      delay_mcs(DELAY_KTVM1);//       for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
	Tmp=ivac_reg_read(0x9058);
	//port  printff("reg9058=%X",Tmp);
  ivac_reg_write(0x9058,0xffffffed);delay_mcs(DELAY_KTVM1);// for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x9054,0xffffffff); delay_mcs(DELAY_KTVM1);//for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x07fc,0x0000001a);delay_mcs(DELAY_KTVM1);// for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x07f8,0x80000640);delay_mcs(DELAY_KTVM1);// for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x0700,0x00000000); delay_mcs(DELAY_KTVM1);//for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa00,0x00000000); delay_mcs(DELAY_KTVM1);//for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa04,0x00057810); delay_mcs(DELAY_KTVM1);//for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa10,0x00148500); delay_mcs(DELAY_KTVM1);//for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa18,0x00840000); 
//ok
 // for(i=0;i<1800;i++) wd_res();	    // wait 12.15 ms (7.125us * N)
  delay_mcs(DELAY_KTVM1);
	Tmp=ivac_reg_read(0xAA20);  //printff("regAA20=%X",Tmp); 
 // for(i=0;i<245;i++) wd_res();	    // wait 1.6 ms (7.125us * N)
  delay_mcs(DELAY_KTVM1);
//ok
	outportb(MIRes,0x97); // Load FW
	delay_mcs(DELAY_KTVM1);
//  for(i=0;i<25;i++) wd_res();	    // wait 1.6 ms (7.125us * N)
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>temporary comment!!!!!!!!!!!!
 // port TEMPORARY?       	while(inportb(MICmd)&0x80) wd_res();
 //	while(inportb(MICmd)&0x80) wd_res();
   for(i = 0; i < DELAY_KTVM1; i++)
   {
   wd_res();
   if(!inportb(MICmd)&0x80) break;
   }

 //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<temporary comment
//	printff("Load ok!1111");

	outportb(MIRes,0x07); // Reset on

//	FWLoad();
  delay_mcs(DELAY_KTVM1);
 // for(i=0;i<20;i++);
//	if(pwr_test){	FWtest_crc();	pwr_test=0;	}
//  	FWtest_crc();
//  printff("test ok");	
//bad 
	MAILBOX=0x044;
	ivac_reg_write(0x9054,0xffffffff);delay_mcs(135);// for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)
	Tmp=ivac_reg_read(0x9058);   //  printff("reg58=%X",Tmp);  
	delay_mcs(DELAY_KTVM1);    
  //	for(i=0;i<25;i++) wd_res();	     // wait 176 us  (7.125us * N)
  ivac_reg_write(0x9058,Tmp & 0xffffffe8);
  delay_mcs(DELAY_KTVM1);
  //	for(i=0;i<20;i++) wd_res();	     // wait 135 us  (7.125us * N)

	ivac_set_mem();
	delay_mcs(DELAY_KTVM1);
 // for(i=0;i<20;i++) wd_res();	    // wait 1.6 ms (7.125us * N)
//bad  
	l=ApiCmd_SetStreamOutputPort(); 
	 if(l)
{
//port printff("SetStreamOutputPort Error");
}

}


//extern "C" int InitIvac()	  //from sergey
extern "C" void InitIvac()	 //from me
{
//	EmbDWord Data,Addr;
	int i;
 //	char c;
	unsigned long l,Tmp,Tmp2;

//	set_audio(1,1);
	
	outportb(MIRes,0x08);
	printf("test_res\n\r");
//	while(1);
	outportb(MIRes,0x0f);               for(i=0;i<500;i++) wd_res();	    // wait 52.5 ms (7.125us * N)
	ivac_reg_write(0x0048,0xffffffff);      	for(i=0;i<1;i++) wd_res();	    // wait  ms (7.125us * N)
	Tmp =ivac_reg_read(0x900c);	        	for(i=0;i<1;i++) wd_res();	    // wait  ms (7.125us * N)
	Tmp2=ivac_reg_read(0x9020);         for(i=0;i<1;i++) wd_res();	    // wait  ms (7.125us * N)

	outportb(MIRes,0x0c); // Reset off
  for(i=0;i<2500;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
	outportb(MIRes,0x0f); // Reset on
  for(i=0;i<120;i++) wd_res();	    // wait 10.15 ms (7.125us * N)

	ivac_reg_write(0xa064,0x00000000);      for(i=0;i<1;i++) wd_res();	     // wait 176 us  (7.125us * N)
  ivac_reg_write(0x9020,(0x00000400|Tmp2)); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x900c,Tmp);             for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  Tmp=ivac_reg_read(0x9058);  printf("reg9058=%X\n\r",Tmp);
  ivac_reg_write(0x9058,0xffffffed); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x9054,0xffffffff); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x07fc,0x0000001a); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x07f8,0x80000640); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0x0700,0x00000000); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa00,0x00000000); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa04,0x00057810); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa10,0x00148500); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
  ivac_reg_write(0xaa18,0x00840000); 
 
  
;
// while(1);
 
 for(i=0;i<1800;i++) wd_res();	    // wait 12.15 ms (7.125us * N)
	Tmp=ivac_reg_read(0xAA20);  printf("regAA20=%X\n\r",Tmp); 
  for(i=0;i<245;i++) wd_res();	    // wait 1.6 ms (7.125us * N)
//_______________________________________added
  ivac_mem_write(0,0x000da7);   for(i=0;i<2;i++) wd_res();


  ivac_mem_write(1,0x66bb55aa);	  for(i=0;i<2;i++) wd_res();


 l=ivac_mem_read(0);
  printf("wait (0xda7) ->		ivac_mem_read(0)=0x%lx\n\r",l);
  
  delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);
  
  	
  l=ivac_mem_read(1);  for(i=0;i<2;i++) wd_res();

  printf("wait (0x66bb55aa)-> ivac_mem_read(1)=0x%lx\n\r",l);	

//_______________________________________added
  outportb(MIRes,0x8f); // Load FW
  for(i=0;i<2;i++) wd_res();
  	    // 

  i = 50000l;	//to not hangt

  while(inportb(MICmd)&0x80 && i) { wd_res(); i--;}

  for(i=0;i<2;i++) wd_res();
     delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);
  l=ivac_mem_read(0);	 for(i=0;i<2;i++) wd_res();
   delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);


  printf("ivac_mem_read(0)=0x%lx\n\r",l);	

  delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);
   delay_mcs(100000l);
  

  l=ivac_mem_read(1);  for(i=0;i<2;i++) wd_res();

  printf("ivac_mem_read(1)=0x%lx\n\r",l);	
  delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);
  delay_mcs(100000l);


for(i=0;i<2;i++) wd_res();

//	outportb(MIRes,0x07); // Reset on

//	FWLoad();
  for(i=0;i<20;i++);
//	FWtest();

	MAILBOX=0x044;
	ivac_reg_write(0x9054,0xffffffff); for(i=0;i<1;i++) wd_res();	     // wait 135 us  (7.125us * N)
	Tmp=ivac_reg_read(0x9058);   //  printf("reg58=%X",Tmp);      
	for(i=0;i<2;i++) wd_res();	     // wait 176 us  (7.125us * N)
        	ivac_reg_write(0x9058,Tmp & 0xffffffe8);
	for(i=0;i<2;i++) wd_res();	     // wait 135 us  (7.125us * N)
	ivac_set_mem();
	for(i=0;i<25;i++) wd_res();	    // wait 1.6 ms (7.125us * N)
	l=ApiCmd_SetStreamOutputPort();  if(l) printf("SetStreamOutputPort Error\n\r");

}


void StartCapture1(unsigned long Bitrate)  //before sergey
{

	unsigned long l;
   //	int i;
	char c;
	MAILBOX=0x044;
	l=ApiCmd_SetMiscParameters(5,0); //port  if(l) printff("SetMiscParameters1 Error");
	l=ApiCmd_SetMiscParameters(3,0); //port  if(l) printff("SetMiscParameters2 Error");
	l=ApiCmd_SetMiscParameters(8,0); //port  if(l) printff("SetMiscParameters3 Error");
	l=ApiCmd_SetMiscParameters(4,1); //port  if(l) printff("SetMiscParameters4 Error");
	l=ApiCmd_SetMiscParameters(0,3); //port  if(l) printff("SetMiscParameters5 Error");
	l=ApiCmd_SetMiscParameters(0xf,0); //port  if(l) printff("SetMiscParameters5 Error");
  l=ApiCmd_EventNotification(); //port   if(l) printff("EventNotification Error");//0xd5
  l=ApiCmd_SetVideoFrameRate();  //port  if(l) printff("SetVideoFrameRate Error");//0x8f
	l=ApiCmd_SetVideoResolution(); //port  if(l) printff("SetVideoResolution Error");//0x91
	l=ApiCmd_SetAspectRatio(2);  //port     if(l) printff("AspectRatio Error");//0x99
//	l=ApiCmd_SetVSyncLineCount();    if(l) printff("SetVSyncLineCount Error");//0xd6
  l=ApiCmd_SetStreamOutputType(0);//port if(l) printff("SetStreamOutputType Error");//0xb9
	l=ApiCmd_SetVideoBitrate(1,Bitrate,10240);  //port    if(l) printff("SetVideoBitrate Error");//20480;
  l=ApiCmd_SetGOPStructure(0x0f,0x03);   //port   if(l) printff("SetGOP Error");
	l=ApiCmd_SetInverseTelecine(0); //port  if(l) printff("InverseTelecine Error");
	l=ApiCmd_SetClosedGOP(0);    //port     if(l) printff("SetClosedGOP Error");
	l=ApiCmd_SetMPEGAudioEncodingParameters(0x0b9);//port if(l) printff("SetMPEGAudio Error");
	l=ApiCmd_Encoder_InputInit();//port  if(l) printff("Encoder_InputInit Error");
	c=inportb(MISet);
	outportb(MISet,c|0x04); // Video start
	outportb(MIRes,0x47); // Reset on
	l=ApiCommand_IndexTblParams();     //port     if(l) printff("IndexTblParams Error");
	l=ApiCmd_StartCapture(0x0,0x0);   //port      if(l) printff("StartCapture Error");
 // for(i=0;i<10;i++) wd_res();	    // wait 2.8 ms (7.125us * N)
  delay_mcs(DELAY_KTVM1);

  //port	printff("StartCapture"); 

}

extern "C" void StartCapture(unsigned long Bitrate)		//from sergey
{

	unsigned long l;
	int i;
	char c;
	MAILBOX=0x044;
	l=ApiCmd_SetMiscParameters(5,0);   if(l) printf("SetMiscParameters1 Error\n\r");
	l=ApiCmd_SetMiscParameters(3,0);   if(l) printf("SetMiscParameters2 Error\n\r");
	l=ApiCmd_SetMiscParameters(8,0); //  if(l) printf("SetMiscParameters3 Error\n\r");
	l=ApiCmd_SetMiscParameters(4,1); //  if(l) printf("SetMiscParameters4 Error\n\r");
	l=ApiCmd_SetMiscParameters(0,3); //  if(l) printf("SetMiscParameters5 Error\n\r");
	l=ApiCmd_SetMiscParameters(0xf,0); //  if(l) printf("SetMiscParameters5 Error\n\r");
  l=ApiCmd_EventNotification();   // if(l) printf("EventNotification Error\n\r");//0xd5
  l=ApiCmd_SetVideoFrameRate();   // if(l) printf("SetVideoFrameRate Error\n\r");//0x8f
	l=ApiCmd_SetVideoResolution(); //  if(l) printf("SetVideoResolution Error\n\r");//0x91
	l=ApiCmd_SetAspectRatio(2);   //    if(l) printf("AspectRatio Error\n\r");//0x99
//	l=ApiCmd_SetVSyncLineCount();    if(l) printf("SetVSyncLineCount Error\n\r");//0xd6
  l=ApiCmd_SetStreamOutputType(0);// if(l) printf("SetStreamOutputType Error\n\r");//0xb9
	l=ApiCmd_SetVideoBitrate(1,Bitrate,10240);   //   if(l) printf("SetVideoBitrate Error\n\r");//20480;
  l=ApiCmd_SetGOPStructure(0x0f,0x03); //     if(l) printf("SetGOP Error\n\r");
	l=ApiCmd_SetInverseTelecine(0); //  if(l) printf("InverseTelecine Error\n\r");
	l=ApiCmd_SetClosedGOP(0);      //   if(l) printf("SetClosedGOP Error\n\r");
	l=ApiCmd_SetMPEGAudioEncodingParameters(0x0b9);// if(l) printf("SetMPEGAudio Error\n\r");
	l=ApiCmd_Encoder_InputInit(); // if(l) printf("Encoder_InputInit Error\n\r");
	c=inportb(MISet);
	outportb(MISet,c|0x04); // Video start
	outportb(MIRes,0x4f); // Reset on
	l=ApiCommand_IndexTblParams();      //    if(l) printf("IndexTblParams Error\n\r");
	l=ApiCmd_StartCapture(0x0,0x0);         if(l) printf("StartCapture Error\n\r");
  for(i=0;i<10;i++) wd_res();	    // wait 2.8 ms (7.125us * N)
	printf("StartCapture\n\r"); 

}



void StopCapture()
{
  //	int i;
	ApiCmd_StopCapture(1,0,0);
	delay_mcs(DELAY_KTVM1);
	delay_mcs(DELAY_KTVM1);
	delay_mcs(DELAY_KTVM1);
	delay_mcs(DELAY_KTVM1);
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
	outportb(MIRes,0x04);
//  for(i=0;i<31000;i++) wd_res();	    // wait 202.5 ms (7.125us * N)
    delay_mcs(DELAY_KTVM1);

}

//port  RTime rtc;

//port EmbRTClock eRTC;

//*********************************************************
//
//    Interrupt processing
//
//*********************************************************
//port move to EmbIsr.h

class EmbIVACInt : public EmbIsr
{
 // unsigned short int	HostInt;
	public:
    void Init(); 
    void IsrXX();
};
  



void EmbIVACInt::Init()
{
 
//port	unsigned int c;
//port  EmbIsr::InitIRQ(0x0c);
	
	inportb(MIInt);
	outportb(MIInt,0x03);
//port	outport(i0con,0x0000);        // 0-регистр управления (разрешения) прерываниями
//	outport(i0con,0x0010);        // 0-регистр управления (разрешения) прерываниями
//port  c=inport(imask);              // Маска перываний - чтение 
//port  outport(imask,c&0xffef);      // Ввод маски прерываний
  
}


//need calling this add to inerrupt

void EmbIVACInt::IsrXX()
{
	unsigned char int_sts;
 //	int r,ret;

	int_sts=inportb(MIInt);
	if(int_sts & 1){// VLD off
		en_sts|=VLD_off;
	}
	if(int_sts & 2){
  	en_sts|=video_int; // Video int
		if(inportb(MISts)&0x80)	en_sts |= video_on;		
		else	en_sts &= ~video_on; 
	}
	if(int_sts & 4){// PTS
    PTSon=1;
	}
	outportb(MIInt,0x03);
 //port 	outport(0xff22,0x000c);						
}


// need calling this add to inerrupt
   EmbIVACInt Ei;
//*********************************************************
//*********************************************************
//*********************************************************
//*********************************************************
//*********************************************************
//*********************************************************
//*********************************************************
#define DELAY_KTVM	(1000)

int start_ktvm1()	  // so was before sergey changing
{
	unsigned long Bitrate;
  //t	int ret=0;
  //	int j;
 //	unsigned char sts;
	unsigned char sound;//=GetSound();
	unsigned char rate;//=GetMode();

//	if(!(inportb(MISts)&0x80))	return 0;

//	outportb(MIInt,0x0);
	sound=GetSound();//0
	rate=GetMode();//1
//ok	
	switch(rate){
		case 1: Bitrate=5000000;//0923;//9a8;
						outportb(MISet,0xc0 | ReedS);//0x0c);
						if(sound)	outportb(MISlt,12); else outportb(MISlt,8); //Slot_4E1);  Test !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						break;
		case 0: Bitrate=3500000;//0x6a0;//0x06c5;
						outportb(MISet,0xc2 | ReedS);//0xce);
						if(sound)	outportb(MISlt,14); else outportb(MISlt,9);//outportb(MISlt,Slot_3E1);
						break;
	}
	
//	printff("MISet=%x",inportb(MISet));
//	printff("MISlt=%x",inportb(MISlt));
	set_audio(rate,sound);
	delay_mcs(DELAY_KTVM);
// 	for(j=0;j<5000;j++) wd_res();
//ok  
	InitIvac();

   
 //ok
	StartCapture(Bitrate);
// ok 
	WRBUS(0,n_slot,WINDOW,(unsigned char)(PUSK_KODER));
 //port 	if(sound=1)  WRBUS(4,n_slot,WINDOW,(unsigned char)(PUSK_KODER));
	if(sound==1)  WRBUS(4,n_slot,WINDOW,(unsigned char)(PUSK_KODER));
	delay_mcs(DELAY_KTVM);
//	for(j=0;j<5000;j++) wd_res();
	WRBUS(0,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|25);
 //port 	if(sound=1)  WRBUS(4,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|25);
	if(sound==1)  WRBUS(4,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|25);

	inportb(MIInt);
	outportb(MIInt,0x03);
 //port  Enable();

	cvbs_cnt=0;
	en_sts &= ~start_err;
	en_sts|=start_ok;
	SetStat(en_sts & 3);
	wd_res();
	
	return 0;
}

int start_ktvm()
{

printf("\n\r ... int start_ktvm");

 //_______________________________________________________________________________
//moved hier

// outportb(0x13,0x08);	// new
/*
	outportb(0xe2,0x96);		delay_mcs(1l);
	outportb(0xe2,0x0c);		delay_mcs(1l);
	outportb(0xe1,0xff);	    delay_mcs(1l);
    outportb(0xe1,0x00);		delay_mcs(10l);
	outportb(0xe2,0x72);		delay_mcs(1l);
	outportb(0xe2,0x04);	   	delay_mcs(1l);
	outportb(0xe1,0xff);	    delay_mcs(1l);
    outportb(0xe1,0x00);		delay_mcs(1l);
*/

  outportb(0x13,0x08);	// 090629	   Reset TVP5160

  SetPll();

// init TVP5160 
  if(!GetVideoIn())	   //need make different for 0 and 1 
  {
	LoadCoder(0);  //this is calling i2c with parameter1
  }
  else if(GetVideoIn() == 1)	   //need make different for 0 and 1 
  {
	LoadCoder(1);  //this is calling i2c with parameter1
  }
  else
  {
    LoadCoder(2);
  }
	SetPll();

// 	printf("init test3\n\r");
//	outportb(0x14,0xc0);	// ??? need
//    outportb(0x15,0x08);	// ??? need

 //t	portb(0xe1,0x0);  //?? need 
//	outportb(0xe1,0x0);  //?? need //090603 

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>is took from sergey
	unsigned long Bitrate;
	int ret=0;
   //	int i,j;
 //	int j;
  //	unsigned char sts;
	unsigned char sound=GetSound();
	unsigned char rate=GetMode();

//	if(!(inportb(MISts)&0x80))	return 0;

	switch(rate){
		case 1: Bitrate=5000000;//0923;//9a8;
						outportb(MISet,0xc0 | ReedS);//0x0c);
						if(sound)	outportb(MISlt,12); else outportb(MISlt,8); //Slot_4E1);  Test !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						break;
		case 0: Bitrate=3500000;//0x6a0;//0x06c5;
						outportb(MISet,0xc2 | ReedS);//0xce);
						if(sound)	outportb(MISlt,14); else outportb(MISlt,9);//outportb(MISlt,Slot_3E1);
						break;
	}
	
//fromhier need check>>>>>>>>>>>>>>>>>>>>>
	set_audio(rate,sound);
//	for(j=0;j<5000;j++) wd_res();
    delay_mcs(50l);
//printf("\n\r InitIvac()");
	InitIvac();
//printf("\n\r any_init()");
//	any_init();
//	printf("\n\r StartCapture()");
	StartCapture(Bitrate);
//	WRBUS(0,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|0x1e);
//  WRBUS(4,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|0x1e);

   printf("..");
   outportb(0x40,0);
//   printf("..");
//   outportb(0x4F,0x9e);
   outportb(0x4F,0x9f);
   delay_mcs(50l);

   printf("..");
   outportb(0x40,4);
//   printf("..");
//   outportb(0x4F,0x9e);
   outportb(0x4F,0x9f);
   printf("..");
/*
	cvbs_cnt=0;
	en_sts &= ~start_err;
	en_sts|=start_ok;
	SetStat(en_sts & 3);
	wd_res();
*/	
	return 0;
}


//*********************************************************


//*********************************************************
/* port
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
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>port
//Need init	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define  PT_NULL     (0)
#define  PT_ERR1     (1)
#define  PT_ERR2     (2)
#define  PT_ERR_PSP  (3)
#define  PT_CTRL     (4)
#define  PT_RING     (5)
#define  PT_SOUND    (6)
#define  PT_ADDR     (7)
#define  PT_POINT    (8)
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<port

void UpdateStatusBarNew(char *s1)
{
	if(GetMode())	add_str(s1,"4E1");
	else add_str(s1,"3E1");
	add_str(s1," ");
	switch(GetVideoIn())
	{
	   /*t
		case 0:	add_str(s1,"Вход: 1"); break;
		case 1: add_str(s1,"Вход: 2"); break;
		case 2: add_str(s1,"Вход: Y/C"); break;
		 */
		case 0:	add_str(s1,"Вход  1"); break;
		case 1: add_str(s1,"Вход  2"); break;
		case 2: add_str(s1,"Вход  Y/C"); break;

	}
	if(!(GetStat() & 1)){
		add_str(s1," Нет сигнала");
	}
	s1[23]=0;
}
//_____________________________________________________________________port
    unsigned char dev_addr;// = EmbGetAddr();
	unsigned char dev_point;// = EmbGetPoint(); 
	unsigned char addr_flag; //=0; 
	unsigned char point_flag;//=0;
	short int counter=0;
	char start_key=0;
	short int res_count;
 //port 	unsigned char c;	   //
	unsigned char sts=0;
	int ret=0;
	unsigned short b=0,key=0,r;
	int sound,rate=1;
	int rs=0,ks=0;
	int i,j;
	EmbTreePoint *current;
	EmbTreePoint *parent;
	int short ctrl_flag;   //=0;
	int short ctrl_counter;//=0;
	unsigned short pt_key; //=0;
	char str[25];
	char s1[64];
	char s2[128];



//_____________________________________________________________________port

//void Encoder_Set(char *a, EmbCommand &embCommand2, 
//EmbCommand &embCommand3, EmbTreeTVM &embTree, char far *dpd)

//port void Encoder_Set(char *a, EmbCommand &embCommand2, EmbCommand &embCommand3, EmbTreeTVM &embTree, char  *dpd)
//port extern "C" void Encoder_Set(char *a, EmbCommand &embCommand2, EmbCommand &embCommand3, EmbTreeTVM &embTree, char  *dpd)
//extern "C" void Encoder_Set(char *a, EmbCommand &embCommand2, EmbCommand &embCommand3, char  *dpd)
//extern "C" void Encoder_Set(char *a, EmbCommand &embCommand2, EmbCommand &embCommand3)
//extern "C" void Encoder_Set(char *a)//, EmbCommand &embCommand2, EmbCommand &embCommand3)
extern "C" void Encoder_Set1()//this was before sergey changing
{
   //  printEthLongHex((unsigned long)(dpd+embTree.Company()));

	 counter=0;
	 start_key=0;
	 sts=0;
	 ret=0;
	 b=0;
	 key=0;
	 rate=1;
	 rs=0;
	 ks=0;
//ok   
 //	 printEthLongHex((unsigned long)embTree.Current);
 //0x20143B28   printEthLongHex((unsigned long)embTree.Current());
 	rate=GetMode();
	
	if(rate<0) rate=1;
	if(rate>1) rate=1;
//ok
	SetPrint(0,3);

//port	wd_res();
	if(inportb(MISts)&0x80)  en_sts |= video_on; 
 //port 	Enable();
//port	wd_res();
	Ei.Init();
//port	wd_res();
 //port   printff("ktvm20");
////////////////////////////////////////////
//ok
	start_ktvm();
//ok 
////////////////////////////////////////////
   //port		char str[25];
   //port		char s1[64];
   //port		char s2[128];
	    ctrl_flag=0;
	    ctrl_counter=0;
   //port		EmbTreePoint *current;
   //port		EmbTreePoint *parent;
	 	pt_key=0;

	for(i=0; i<25; i++) s1[i]  = 0;
	for(i=0; i<25; i++) s2[i]  = 0;
	for(i=0; i<25; i++) str[i] = 0;
  //ok

  //	current = embTree.Current(); //for test	
 //	parent = current->Parent();

 //0x20036DA9
  //0xe1a01ba1;!!!	 printEthLongHex((unsigned long)embTree.Current());

 //t	embTree.Down();
   embTree.Down();  //t

   	
	//ok
 	current = embTree.Current();	
	parent = current->Parent();
	CreateASCIIZ(dpd+embTree.Company(),str);

 //  printEthString(str, 27);  //t
//t   printEthLongHex((unsigned long)(dpd+embTree.Company()));

	add_str(str,"  ");
//ok
		CreateASCIIZ(dpd+embTree.City(),s2);
	add_str(str,s2);

 //	add_str(str,"Test 1"); //t
	CopyInd0ToRemote(str);
	ConvertToWin1251(str);
  //	CopyInd0ToRemote(str);
    embIndicator.SetStr0(str);
	for(i=0; i<25; i++) str[i]=0;
	CreateASCIIZ(dpd+embTree.Name(),str);

	add_str(str,"   ");

  //	printEthString(str, 27);  //t

	CreateASCIIZ(dpd+embTree.Version(),s1);
	add_str(str,s1);
	add_str(str,"  ");
	CreateASCIIZ(dpd+embTree.Date(),s2);
	add_str(str,s2);
  // add_str(str,"Test 2"); //t
	CopyInd1ToRemote(str);
	ConvertToWin1251(str);
//ok
//	CopyInd1ToRemote(str);
	embIndicator.SetStr1(str);
//ok 
    embIndicator.Cursor(0,0x81);
//  embIndicator.SetStr0("Debug");///Debug
	 dev_addr = EmbGetAddr();
	 dev_point = EmbGetPoint(); 
	 addr_flag=0; 
	 point_flag=0;
	 	  
}

extern "C" void Encoder_Set()//, EmbCommand &embCommand2, EmbCommand &embCommand3)
{
   //  printEthLongHex((unsigned long)(dpd+embTree.Company()));
 printf("\n\r ... void Encoder_Set");
	 counter=0;
	 start_key=0;
	 sts=0;
	 ret=0;
	 b=0;
	 key=0;
	 rate=1;
	 rs=0;
	 ks=0;
//ok   
 //	 printEthLongHex((unsigned long)embTree.Current);
 //0x20143B28   printEthLongHex((unsigned long)embTree.Current());

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>it was before sergey changing
/*
 	rate=GetMode();
	
	if(rate<0) rate=1;
	if(rate>1) rate=1;
//ok
	SetPrint(0,3);

//port	wd_res();
	if(inportb(MISts)&0x80)  en_sts |= video_on; 
 //port 	Enable();
//port	wd_res();
	Ei.Init();
*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 it was before sergey changing


//port	wd_res();
 //port   printff("ktvm20");
////////////////////////////////////////////
//ok
	start_ktvm();	//next step to start()
//ok 
////////////////////////////////////////////


   //port		char str[25];
   //port		char s1[64];
   //port		char s2[128];
	    ctrl_flag=0;
	    ctrl_counter=0;
   //port		EmbTreePoint *current;
   //port		EmbTreePoint *parent;
	 	pt_key=0;

	for(i=0; i<25; i++) s1[i]  = 0;
	for(i=0; i<25; i++) s2[i]  = 0;
	for(i=0; i<25; i++) str[i] = 0;
  //ok

  //	current = embTree.Current(); //for test	
 //	parent = current->Parent();

 //0x20036DA9
  //0xe1a01ba1;!!!	 printEthLongHex((unsigned long)embTree.Current());

 //t	embTree.Down();
   embTree.Down();  //t

   	
	//ok
 	current = embTree.Current();	
	parent = current->Parent();
	CreateASCIIZ(dpd+embTree.Company(),str);

 //  printEthString(str, 27);  //t
//t   printEthLongHex((unsigned long)(dpd+embTree.Company()));

	add_str(str,"  ");
//ok
		CreateASCIIZ(dpd+embTree.City(),s2);
	add_str(str,s2);

 //	add_str(str,"Test 1"); //t
	CopyInd0ToRemote(str);
	ConvertToWin1251(str);
  //	CopyInd0ToRemote(str);
    embIndicator.SetStr0(str);
	for(i=0; i<25; i++) str[i]=0;
	CreateASCIIZ(dpd+embTree.Name(),str);

	add_str(str,"   ");

  //	printEthString(str, 27);  //t

	CreateASCIIZ(dpd+embTree.Version(),s1);
	add_str(str,s1);
	add_str(str,"  ");
	CreateASCIIZ(dpd+embTree.Date(),s2);
	add_str(str,s2);
  // add_str(str,"Test 2"); //t
	CopyInd1ToRemote(str);
	ConvertToWin1251(str);
//ok
//	CopyInd1ToRemote(str);
	embIndicator.SetStr1(str);
//ok 
    embIndicator.Cursor(0,0x81);
//  embIndicator.SetStr0("Debug");///Debug
	 dev_addr = EmbGetAddr();
	 dev_point = EmbGetPoint(); 
	 addr_flag=0; 
	 point_flag=0;
	 	  
}


 //port	for(;;)



union word{
  unsigned char c[2];
 //port unsigned int i;
 unsigned short int i;
};



void ktvm()
{
//______________________________________
int i; //,j;
unsigned char t_r_d;

//ok return; //t
//______________________________________

#ifdef KTVM_PROT2
 if(GetRemoteMode() & 1l)
	{
//#include "remotemux.inc"
//ok   return;
 	remote_prot2();
	}
	else
	{
 //	printEthLongHex(0x34);
#endif // KTVM_PROT2

/////////////////////////////////  MAX  ///////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<uncomment 090416
/*

 	  if(embRS232.UsedTrans()>32) embRS232.TransInit(); 
		if(embRS232.UsedReceive())
		{
			if(embCommand2.Add(embRS232.Receive())==2)
			{
				if(embCommand2.GetType()=='@')
				{
					if((embCommand2.GetAddr()==0xFF)&&(embCommand2.GetPoint()==0xFF))
					{
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
						}
					}
				}
			}
		}
		*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<uncomment 090416
////// 485

//no return;

    if(embRS485.UsedReceive())
		{
			if(embCommand3.Add(embRS485.Receive())==2)
			{
        		if(embCommand3.GetType()=='@')
				{
          			if((embCommand3.GetAddr()==0xFF)&&(embCommand3.GetPoint()==0xFF))
					{
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
			}
		}
/////////////////////////////////////////////////////////////////////////////////
#ifdef KTVM_PROT2
} //GetRemotemode
#endif // KTVM_PROT2




 //port		wd_res();
  if(!dpd_state) return;

  //		return;	//t

		if(embIndicator.Used())
		{
	 //	 printEthLongHex(1);   //t	
			b=embIndicator.Get();
			if(('0'<b)&&(b<='6')) 
			{
				key=b; 
				start_key=1;
			}
		} 
////////  вставить псевдо нажатие по таймеру  ///
		counter++;

			if(!(counter%800))
				{
				  //	key=0xFF;			
//scan state
			   
			  //		printEthLongHex(t_r_d);
	

  		t_r_d = inportb(0x12);
   //		printf("\n\r>Read address 0x12 : 0x%X", t_r_d);

	  //	if(t_r_d & 0x3f == 0)						  //00	    signal ok coder error	   
	  	if((unsigned char)(t_r_d & 0xC0) == 0)						  //00	    signal ok coder error
	  		{
		//	  printf("\n\r1");

			outportb(0xE4, 0); //leds pal/secam off

			/* 090604 temporary ? 
			StopCapture();
   //	  		printff("Restart=%x",ret);
			start_ktvm();
			*/
			SetPrint(ret,2);

			embIndicator.SetLtDiod(1,1); //"Avarija"
			embIndicator.SetLtDiod(0,2); // "Oshibki"
			embIndicator.SetLtDiod(0,3); //"Norma"

	    }
		 else
		 if((unsigned char)(t_r_d & 0xC0)  == 0xC0)   //no signal	, coder ok   //1X
		 {
	   //	  printf("\n\r2");
		    outportb(0xE4, 0); //leds pal/secam off
			embIndicator.SetLtDiod(0,1); //"Avarija"
			embIndicator.SetLtDiod(1,2); // "Oshibki"
			embIndicator.SetLtDiod(0,3); //"Norma"

		 }
	 	else
		 if((unsigned char)(t_r_d & 0xC0) == 0x80)   //no signal  coder error - not set on lederror 	   //X1
		 {
	  //	  printf("\n\r3");

			 outportb(0xE4, 0); //leds pal/secam off
			embIndicator.SetLtDiod(0,1); //"Avarija"
			embIndicator.SetLtDiod(1,2); // "Oshibki"
			embIndicator.SetLtDiod(0,3); //"Norma"

		 }
		 else	// 0x40 signal ok coder ok
		 {
	  //	  printf("\n\r4");

  				  t_r_d = ReadDataI2C(0x3f);
			  //	  printf("\n\r>Read I2C : 0x%X", t_r_d);
				  if((t_r_d & 0xf) == 0x2) {outportb(0xE4, 0x2);}
				  else   if((t_r_d & 0xf) == 0x6) {outportb(0xE4, 0x1);}
				  else {outportb(0xE4, 0);}

		    embIndicator.SetLtDiod(0,1); //"Avarija"
			embIndicator.SetLtDiod(0,2); // "Oshibki"
			embIndicator.SetLtDiod(1,3); //"Norma"


		 }


/*
			if(ret!=en_sts){
			ret=en_sts;
			SetStat(ret & 0x0003);
			SetPrint(ret,1);
			if(ret & start_err)embIndicator.SetLtDiod(1,1); else embIndicator.SetLtDiod(0,1);
			if(ret & video_on){ embIndicator.SetLtDiod(0,2); 
			}else{ embIndicator.SetLtDiod(1,2); //printff("Video off");
			}
			if(ret & start_ok) embIndicator.SetLtDiod(1,3);
			else{ embIndicator.SetLtDiod(0,3); embIndicator.SetLtDiod(1,2);}
		}

   */




  	} //%800



		if(start_key)
			if(!key)
				if(!(counter%400))
				{
					key=0xFF;			
				}
/////////////////////////////////////////////////			
   		if(key)
   //		if(0)
		{
	 //t
//ok
			if(key!=0xFF)
//port changed to ticket_on	embIndicator.Receipt();
				ticket_on(); //port

   
 //ok
			current = embTree.Current();
				
			if(current) parent = current->Parent();
//ok
  
			
			switch(key)
			{
		   
  				case 0x31:// embIndicator.SetStr1("Esc");
						outportb(MIInt,0x07);
				 //		printEthLongHex(key);	
					break; // Esc  				
				case 0x32:// embIndicator.SetStr1("Up");
						if(ctrl_flag|addr_flag|point_flag)
						{
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
							else
							{
								embIndicator.Cursor(2,0xD7);
								EmbParameter *par = current->Parameter();
								EmbSet *embSet = embTree.GetSets(par->Type()-12);
								ctrl_counter++;
								if(ctrl_counter>=embSet->NumItem()) ctrl_counter=0;
							}
						}
						else
						{
							ctrl_counter=0;
							if(parent->Parent()) embTree.Up();   
						}
///					         if(ks) if(!rate) rate=1; 
				 //	  	printEthLongHex(key);	
					  break; // Up   				
				case 0x33:// embIndicator.SetStr1("Enter");
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
//______________________________________________________________________________________>> Protokol
case PT_CTRL:
							if(!ctrl_flag) 
							{
								ctrl_flag=1;
								embIndicator.Cursor(2,0xD7);
								if(embTree.LexCmp(current->Name(),"Протокол"))
									{
									  ctrl_counter = EmbGetProt();// 1-выкл  0-вкл
   									}
							 //	 else	 if(embTree.LexCmp(current->Name(),"звук"))
							   //		{
								 //	  ctrl_counter = EmbGetSound();// 1-выкл  0-вкл
   								 //	}

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
								//	if(embTree.LexCmp(current->Name(),"звук"))
								//	{
								//	   if(ctrl_counter){ MakeSoundLock(); EmbSetSound(1);} // 1-выкл  0-вкл
								//		else {  MakeSoundUnLock(); 
								//		EmbSetSound(0);}
 
								 //	}
									 if(embTree.LexCmp(current->Name(),"Протокол"))
									{
									  if(ctrl_counter) {SetProtokol(1);}// 1-выкл  0-вкл
										else{ SetProtokol(0); }
									}

								}
							}
						break;

//______________________________________________________________________________________<<Protokiol
						default:
							if(ctrl_flag)
							{
								rs=1; ks=0;
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
							}
							else
							{ 
								ks=1; 
								embIndicator.Cursor(2,0xd7);
								ctrl_flag=1;
							}
						break; // Enter
					}
			   //		printEthLongHex(key);	
					break;
				case 0x34:// embIndicator.SetStr1("Left");
					ctrl_flag = 0;
					embIndicator.Cursor(0,0xD7);
					embTree.Left(); 
			   //		printEthLongHex(key);	
					break; // Left 

				case 0x35:// embIndicator.SetStr1("Down");
				
						if(ctrl_flag|addr_flag|point_flag)
						{
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
							else
							{
				  				embIndicator.Cursor(2,0xD7);
				  				EmbParameter *par = current->Parameter();
				   				EmbSet *embSet = embTree.GetSets(par->Type()-12);
								ctrl_counter--;
			  					if(ctrl_counter<0) ctrl_counter=embSet->NumItem()-1;
							}
						}
						else
						{
							ctrl_counter=0;
				 			embTree.Down();	   //hier fall
				 //ок			printEthLongHex(0x11);
						}
//					         if(ks)if(rate) rate=0; 

		   //		printEthLongHex(key);	
				  break; // Down 				
				case 0x36:// embIndicator.SetStr1("Right");
						ctrl_flag = 0;
						embIndicator.Cursor(0,0xD7);
						embTree.Right(); 
			  //			printEthLongHex(key);	
					         break; // Right
			}


 //ok
			current = embTree.Current();	
			if(current) parent = current->Parent();
			for(i=0; i<25; i++) s1[i]  = 0;
			for(i=0; i<25; i++) s2[i]  = 0;
			for(i=0; i<25; i++) str[i] = 0;



 
 //ok ок
	   //	  printEthString(s1, 27);	//t
		  //#ifdef NODEBUG
			UpdateStatusBarNew(s1);
			CopyInd0ToRemote(s1);
   			ConvertToWin1251(s1);
  	 //		CopyInd0ToRemote(s1);
			embIndicator.SetStr0(s1);
//#endif


//ok ок


 //ok
	
			CreateASCIIZ(dpd+current->Name(),s2);
			pt_key = PT_NULL;


			if(!current->Child()) 
			{
				add_str(s2," : ");
///////////////////////   Управление  /////////////////////
//				if(current->Name())
				if(embTree.LexCmp(current->Name(),"Адр_Станции_Сист"))
				{
			   //		printEthLongHex(1);
					BYTE i;
					pt_key = PT_POINT;
					if(!point_flag) dev_point = EmbGetPoint();
					char ch_p[8];
					itoa(dev_point,ch_p,10); 
					add_str(s2,ch_p);
					int fl1=0;
					for(i=0; i<24; i++)
					{
						if(!s2[i]) fl1=1;
						if(fl1) s2[i]=' ';
					}
					s2[23] = 0x7E;
					s2[24] = 0;
				}
//___________________________________________________________________________________


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

 
//___________________________________________________________________________________

				else
				{
					if(embTree.LexCmp(current->Name(),"Адр_Устр_Сист"))
					{
				//		printEthLongHex(2);

						BYTE i;
						pt_key = PT_ADDR;
						if(!addr_flag) dev_addr = EmbGetAddr();
						char ch_p[8];
						itoa(dev_addr,ch_p,10);
						add_str(s2,ch_p);
						int fl1=0;
						for(i=0; i<24; i++)
						{
							if(!s2[i]) fl1=1;
							if(fl1) s2[i]=' ';
						}
						s2[23] = 0x7E;
						s2[24] = 0;
					}
//_____________________________________________________________
  		  else if(embTree.LexCmp(current->Name(),"Версия"))
		  {
			   FillProgVersion1(&s2[8] , 8);
		  }
//____________________________________________________________
			else
					{
				//ok	printEthLongHex(3);
						EmbParameter *par = current->Parameter();

						if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
						{
						//	printEthLongHex(0x31);

					  		if(!ctrl_flag) ctrl_counter = embTree.GetParameterNum();
						
				   //after remove virtuals - ok			 printEthLongHex(0x311);
	//after add to embtreetvm::getparameternum - ok		 printEthLongHex(0x3111);
							pt_key =	PT_CTRL;
						  //port	if(par->Type()-12 < embTree.CountSets())
							if((par->Type()-12) < embTree.CountSets()) //port
							{
						   //ok		printEthLongHex(0x32);

								BYTE i;
								char str_par[32];
						  //t		EmbSet *embSet = embTree.GetSets(par->Type()-12);
								EmbSet *embSet = (EmbSet *)embTree.GetSets(par->Type()-12);
						//ok		printEthLongHex(0x321);

//0x5b404D8			printEthLongHex((unsigned long)(dpd+embSet->SetItem(ctrl_counter)->Name()));
//						printEthLongHex((unsigned long)(dpd+embSet->SetItem(ctrl_counter)->Name()));
 //0xfffffffc						printEthLongHex((unsigned long)(par->Type() - 12));
		//	printEthLongHex((unsigned long)(par->Type() - 12));

  //0x20					   printEthLongHex(embTree.CountSets());
 //0x8							printEthLongHex((unsigned long)(par->Type()));
		  				CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par); //hier fall!!!

						//after comment all in createasciiz ok		printEthLongHex(0x322);
						//		printEthLongHex(0x3221);

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
				  //bad			printEthLongHex(0x33);


						}
					}
				}
			}
//			 printEthString(s2, 27);
  CopyInd1ToRemote(s2);	//t
  ConvertToWin1251(s2);
 //t CopyInd1ToRemote(s2);
  embIndicator.SetStr1(s2);
		 
 			key=0;
		}

//bad


//*************************************************************
/* 090604 for start

		if(ret!=en_sts){
			ret=en_sts;
			SetStat(ret & 0x0003);
			SetPrint(ret,1);
			if(ret & start_err)embIndicator.SetLtDiod(1,1); else embIndicator.SetLtDiod(0,1);
			if(ret & video_on){ embIndicator.SetLtDiod(0,2); 
			}else{ embIndicator.SetLtDiod(1,2); //printff("Video off");
			}
			if(ret & start_ok) embIndicator.SetLtDiod(1,3);
			else{ embIndicator.SetLtDiod(0,3); embIndicator.SetLtDiod(1,2);}
		}

*/
//*************************************************************

  	if(ret & VLD_off){
			StopCapture();
	  	printff("Restart=%x",ret);
			start_ktvm();
			SetPrint(ret,2);
			en_sts &= ~VLD_off;
		}

//*************************************************************
    if(PTSon){  // Test
      word w,d,g,k;
			EmbDWord r,t;
			char ptype,a,b;
			unsigned long l;

			outportb(MIBuff,17); 			ptype=inportb(MIBuff);
			outportb(MIBuff,18); 			g.c[0]=inportb(MIBuff);
			outportb(MIBuff,19); 			g.c[1]=inportb(MIBuff);
			outportb(MIBuff,20); 			k.c[0]=inportb(MIBuff);
			outportb(MIBuff,21); 			k.c[1]=inportb(MIBuff);
			outportb(MIBuff,22); 			a=inportb(MIBuff);
//			printff("Type=%x  SCR %x%x",ptype,w.i,d.i);
			outportb(MIBuff,1); 			w.c[0]=inportb(MIBuff);
			outportb(MIBuff,2); 			w.c[1]=inportb(MIBuff);
			outportb(MIBuff,3); 			d.c[0]=inportb(MIBuff);
			outportb(MIBuff,4); 			d.c[1]=inportb(MIBuff);
			outportb(MIBuff,5); 			b=inportb(MIBuff);
/*
			outportb(MIBuff,7); 			w.c[0]=inportb(MIBuff);
			outportb(MIBuff,8); 			w.c[1]=inportb(MIBuff);
			outportb(MIBuff,9); 			d.c[0]=inportb(MIBuff);
			outportb(MIBuff,10); 			d.c[1]=inportb(MIBuff);
*/
			r.c[0]=g.c[0];
			r.c[1]=g.c[1];
			r.c[2]=k.c[0];
			r.c[3]=k.c[1];
			
			t.c[0]=w.c[0];
			t.c[1]=w.c[1];
			t.c[2]=d.c[0];
			t.c[3]=d.c[1];
       
			l = r.l - t.l;
//			if((l>0x04000)||(l<0xb00))printff("Type=%x  PCR %x%x  SCR %x%x  %X",ptype, k.i, g.i, d.i, w.i, l);
			printff("Type=%x  PCR=%x%x%x  SCR=%x%x%x  %X",ptype,a,k.i,g.i,  b,d.i,w.i,r.l-t.l);
			PTSon=0;
		}
//*************************************************************
	}
//delete, not needed end }

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{
  Ei.IsrXX();
 IntFlag |= INT0_FLAG;
 //t my_int_enable_irq0();
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq0();
 }

}

extern "C" void LoadSome()
{
    WRBUS(0,n_slot,WINDOW,(unsigned char)(STOP_KODER));
  WRBUS(4,n_slot,WINDOW,(unsigned char)(STOP_KODER));

	  delay_mcs(50000l);



	 WRBUS(0,n_slot,WINDOW,(unsigned char)(PUSK_KODER));
  /*	if(sound == 1)*/  WRBUS(4,n_slot,WINDOW,(unsigned char)(PUSK_KODER));
 //	for(j=0;j<5000;j++) wd_res();
	delay_mcs(25000l);
 //	WRBUS(0,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|25);
	WRBUS(0,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|(read_nvram_char(DELAY_NVRAM_ADDRESS)));
   /*	if(sound == 1)  */WRBUS(4,n_slot,WINDOW,(unsigned char)(SET_DELAY_TIME)|(read_nvram_char(DELAY_NVRAM_ADDRESS)));
}







