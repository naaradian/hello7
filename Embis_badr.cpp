//port #include <dos.h>

//#include <stdio.h>
//#include  "hello7.h"   //test uncomment
#include "embisr.h"
//#include  "hello7.h"
#include  "menu1.h"
#include  "hello7.h"   //test uncomment


extern MDataC TestMode;

//#include "amd_pcb.h"

//____________>>>port

// unsigned char Point;  //port
// unsigned char Addr;   //port
#ifdef IncEmbRS232
extern "C"  EmbRS232 embRS232;
#endif

#ifdef USE_USART2
extern "C"  EmbRS232 embRS232S;
#endif


//#ifdef PROG_PRM_PCH_N_1
//extern "C" void embRS232N_rcvbuf_Add(unsigned char);
//#endif 	PROG_PRM_PCH_N_1



#ifdef IncEmbRS485

extern "C" EmbRS485 embRS485;

#endif

#ifdef IncEmbIndicator
extern "C" EmbIndicator embIndicator;
void ToIBuf(unsigned char data);
extern "C" void PultDelay(void);


#endif

#define SIZETX0MF  (1000)
extern char TBuff0mf[SIZETX0MF];
extern char *  pTBuff0mf;
extern unsigned long TBuff0mf_cnt;
extern char* pxilinx;
extern char* pxilinx3;
//extern uint_32 Stephany15;

TRBuffer<char,ACT_BUFFER_SIZE> TrzBuff232;
TRBuffer<char,ACT_BUFFER_SIZE> TrzBuff485;
   /*
#ifdef PROG_PRM_PCH_SPI
#define SSC_BUFFER_SIZE (200)

TRBuffer<char,ACT_BUFFER_SIZE> SSC2Buff;

extern "C" void  SSC2Buff_Init(void)
{
  SSC2Buff.Init();
}

extern "C" void  SSC2Buff_Add(unsigned char ach)
{
  SSC2Buff.Add(ach);
}

extern "C"  unsigned char  SSC2Buff_IsUsed(void)
{
 return SSC2Buff.Used();
}

extern "C"  unsigned char  SSC2Buff_Get(void)
{
 return SSC2Buff.Get();
}


#endif
	 */



//TRBuffer<char,ACT_BUFFER_SIZE> RDN_BufferR; //up to 100 packets keep
EmbRS232 dirRS232;

#ifdef ETH_TRANZIT

EmbRS232 trnzRS232;

#endif // ETH_TRANZIT
	 


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :TrzBuff_Init
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/
extern "C" void TrzBuffs_Init(void)	// 
 {
  TrzBuff232.Init();
  TrzBuff485.Init();
 // RDN_BufferR.Init();
 }



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :TrzBuff_Send
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void TrzBuffs_Send(void)	// called frequency = 1 ms
 {

 char Buff[2000];
 unsigned long len, cnt;
 unsigned char tmp;
 len = 0;
 cnt = 2;
 /*t  
  if(TrzBuff232.Used())
   {
	 tmp = 	TrzBuff232.Get();
	 printf("\n\r232> = %c ", tmp);
	 Transmit1c(tmp);
 //	 fputc(tmp, fusart1_ptr); 
   }
   */
//_______________________________________________RDN eth
 if(TrzBuff232.Used())	
 {
   while(TrzBuff232.Used())
   {
	 tmp = 	TrzBuff232.Get();
  //  printf("\n\r232> = %c ", tmp);
#ifndef USART0_TRY_PDC_1T	
	  printf("-%c", tmp);
#else
#ifndef PROG_COMMUTATOR1
	  printfp("-");
	  printfpd("%c", tmp);
#else
	 // ToPdcTu0(tmp);
#endif
#endif


 	  Transmit1c(tmp);
 //	  fputc(tmp, fusart1_ptr);
  	  Buff[cnt++] = tmp;
   }
	 Buff[0] = (char)(cnt >> 8);
	 Buff[1] = (char)(cnt);
     char dest[6];
     dest[0] = 0xff;  dest[1] = 0xff; 	dest[2] = 0xff;
     dest[3] = 0xff;  dest[4] = 0xff; 	dest[5] = 0xff;
     RDN_Start_Transmit(Buff, dest);
  }

//_______________________________________________RDN eth


    if(TrzBuff485.Used())
   {
	tmp = 	TrzBuff485.Get();
 //RDN eth	printf("\n\r485> = %c ", tmp);
 #ifndef USART0_TRY_PDC_1T	
	  printf("_%c", tmp);
#else

#ifndef PROG_COMMUTATOR1
	  printfp("_");
	  printfpd("%c", tmp);
#else
 //	  ToPdcTu0(tmp);
#endif
#endif


 //	printf("_%c", tmp);	  //RDN eth

 //	printf("Stephany15 = %ld)", Stephany15); 

	 Transmit00c(tmp);
  //	fputc(tmp, fusart0_ptr); 
   }

 }



#ifdef IncEmbRS232

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :TrzBuf232_rcvbuf_Add
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void TrzBuff232_Add(unsigned char SetOpChar)	// called frequency = 1 ms
 {
   TrzBuff232.Add(SetOpChar);
 }

#endif // IncEmbRS232

#ifdef IncEmbRS485

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :TrzBuf232_rcvbuf_Add
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void TrzBuff485_Add(unsigned char SetOpChar)	// called frequency = 1 ms
 {
   TrzBuff485.Add(SetOpChar);
 }

#endif // IncEmbRS485


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :embRS232_rcvbuf_Add
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void embRS232_rcvbuf_Add(unsigned char SetOpChar)	// called frequency = 1 ms
 {
 // printf("\n\r BuffSize :%d", embRS232.rcvbuf.BuffSize);


   embRS232.rcvbuf.Add(SetOpChar);

//#ifdef PROG_PRM_PCH_N_1
//      embRS232N_rcvbuf_Add(SetOpChar);
 // embMsg232N.rcvbuf.Add(SetOpChar);
//#endif //PROG_PRM_PCH_N_1



 }

#ifdef USE_USART2
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :embRS232S_rcvbuf_Add
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void embRS232S_rcvbuf_Add(unsigned char SetOpChar)	// called frequency = 1 ms
 {
 // printf("\n\r BuffSize :%d", embRS232.rcvbuf.BuffSize);


   embRS232S.rcvbuf.Add(SetOpChar);

//#ifdef PROG_PRM_PCH_N_1
//      embRS232N_rcvbuf_Add(SetOpChar);
 // embMsg232N.rcvbuf.Add(SetOpChar);
//#endif //PROG_PRM_PCH_N_1



 }
#endif





 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :embRS485_rcvbuf_Add
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

extern "C" void embRS485_rcvbuf_Add(unsigned char SetOpChar)	// called frequency = 1 ms
 {
//#ifdef PROG_BMD35
 // if((t_set == 1) && (b_set != SetOpChar))
//#endif //PROG_BMD35
   embRS485.rcvbuf.Add(SetOpChar);
//#ifdef PROG_BMD35
//  t_set = 0;
 // b_set = 0;
//#endif //PROG_BMD35


 }


 
extern "C" void outport(unsigned int a1, unsigned char a2)	  //in autodetect so use xilinx
{
//   write_xil_char(((uint_32)(a1)), (char) a2);
   char* port;
   if(a1 < XILINX_SIZE)
   {
   port = pxilinx + (a1);
   *port = a2;
   }
} //




extern "C" void outportb(unsigned int a1, unsigned char a2)
{
 //  write_xil_char(((uint_32)(a1)), (char) a2);
     char* port;
  if(a1 < XILINX_SIZE)
  {
   port = pxilinx + (a1);
   *port = a2;
  }
} //

extern "C" void outportb3(unsigned int a1, unsigned char a2)
{
 //  write_xil_char(((uint_32)(a1)), (char) a2);
     char* port;
  if(a1 < XILINX_SIZE)
  {
   port = pxilinx3 + (a1);
   *port = a2;
  }
} //

	  
extern "C" unsigned char inportb(unsigned int a1)
{
   char* port;
 if(a1 < XILINX_SIZE)
   {
   port = pxilinx + (a1);
   }
  //   return read_xil_char((uint_32)(a1));
	return *port;
}

extern "C" unsigned char inportb3(unsigned int a1)
{
   char* port;
 if(a1 < XILINX_SIZE)
   {
   port = pxilinx3 + (a1);
   }
  //   return read_xil_char((uint_32)(a1));
	return *port;
}


extern "C" unsigned short  inport(unsigned int a1)
{
   unsigned short ret = 0;
   char* port;
 if(a1 < XILINX_SIZE)
   {
   port = pxilinx + (a1);
   port--;
   ret = (unsigned short)*port;
   ret <<= 8; 
   port++;
   ret += (unsigned short)*port;
   }
  //   return read_xil_char((uint_32)(a1));
	return ret;
}

extern "C" unsigned short  inportx(unsigned int a1)
{
   unsigned short ret;
   unsigned short ret1;

   char* port;
 if(a1 < ((unsigned long)(XILINX_SIZE) +1l))
   {
   port = pxilinx + (a1);
   ret = (unsigned short)*port;
   port++;
   ret1 = (unsigned short)*port;
   ret1 <<= 8;
   ret += ret1;
   }
   else
   {return 0x99;}
  //   return read_xil_char((uint_32)(a1));
	return ret;
}



   /* ====================port 
unsigned char EmbGetPoint() { return *((unsigned char far*)0x80001FF0); }
unsigned char EmbGetAddr() { return *((unsigned char far*)0x80001FF1); }
void EmbSetPoint(unsigned char b) { *((unsigned char far*)0x80001FF0) = b; }
void EmbSetAddr(unsigned char b) { *((unsigned char far*)0x80001FF1) = b; }
port=======================*/
unsigned char EmbGetPoint() { return read_nvram_char(0x1FF0);}

void EmbSetPoint(unsigned char b) {
#ifdef PROG_DTVM
  SetPoint1(b);
#else
#ifdef PROG_KTVM
  SetPoint1(b);
#else 
write_nvram_char(0x1FF0 ,b);
#endif //PROG_KTVM
#endif //PROG_DTVM
 
 }

//unsigned char EmbGetAddr() {return read_nvram_char(0x1FF1);}
unsigned char EmbGetAddr() {return read_nvram_char(0x1FF8);}   //to can use MDataC
unsigned char EmbGetProt() {return (read_nvram_char(0x2000) & 1);}   //to can use MDataC
unsigned char EmbGetSound() {return ((read_nvram_char(0x2000) & 2)>> 1);}   //to can use MDataC

unsigned char EmbGetSign()
{
 if(read_nvram_char(INIT_SIGN_ADDRESS) == INIT_SIGN_VALUE)
 {return 1;}
 else
 {return 0;}
}

void EmbSetSign()
{
 write_nvram_char(INIT_SIGN_ADDRESS, (unsigned char)(INIT_SIGN_VALUE));
}





unsigned char EmbGetTestLock()
{
 if((read_nvram_char(TEST_DISABLE_ADDRESS1) == TEST_DISABLE_VALUE1) &&
	 (read_nvram_char(TEST_DISABLE_ADDRESS2) == TEST_DISABLE_VALUE2))
 {return 1;}
 else
 {return 0;}
}

void EmbSetTestLock()
{
 write_nvram_char(TEST_DISABLE_ADDRESS1, (unsigned char)(TEST_DISABLE_VALUE1));
 write_nvram_char(TEST_DISABLE_ADDRESS1, (unsigned char)(TEST_DISABLE_VALUE2));
}




void EmbInitNVRAM()
{
 if(!EmbGetSign())
 {
   SetNVRAMToData(0);
   EmbSetSign();
 }
}





//void EmbSetAddr(unsigned char b) { write_nvram_char(0x1FF1 ,b);}
void EmbSetAddr(unsigned char b) {
#ifdef PROG_DTVM
 SetAddr1(b);
#else
#ifdef PROG_KTVM
 SetAddr1(b);
#else
 write_nvram_char(0x1FF8 ,b);
#endif //PROG_KTVM  
#endif //PROG_DTVM 
 } //to can use MDataC

void EmbSetProt(unsigned char b)
 {
 unsigned char tmp = read_nvram_char(0x2000);
 write_nvram_char(0x2000 ,((tmp & 0xfe) | (b & 0x1)));
 } //to can use MDataC

void EmbSetSound(unsigned char b)
 {
 unsigned char tmp = read_nvram_char(0x2000);
 write_nvram_char(0x2000 ,((tmp & 0xfd) | ((b & 0x1) << 1)));
 } //to can use MDataC



//____________<<<port


////////////////////////////////////////////////////////////////
/* port
static int nint[17] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
static EmbIsr *comarray[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
static sss=0;
static ttt=0;
port  */
//======================>>>port
static int nint[17];
static EmbIsr *comarray[17];
static sss;
static ttt;
//======================<<<port
extern "C" void EmbInit(void) //========================port need call this to init global variables
{
 for(int i = 0; i < 17; i++)
 {
  nint[i] = 0;
  comarray[i] = 0;
 }
  sss = 0;
  ttt = 0;
  embRS232.Init(38400);	//rate not hier

#ifdef USE_USART2
    embRS232S.Init(38400);
#endif


  dirRS232.Init(38400);	//rate not hier
#ifdef ETH_TRANZIT

  trnzRS232.Init(38400);

#endif // ETH_TRANZIT


  embRS485.Init(38400);	//rate not hier

//t  embIndicator.Init();
}


/* ====================================port
#define isr(n,isrn)						\
static void isrn(...)					\
{															\
  asm { pusha; }							\
  if(comarray[n]!=NULL)				\
  {														\
    comarray[n]->IsrXX();			\
	}														\
	asm { popa; pop bp; iret; }	\
}

isr(1,isr1)
isr(2,isr2)
isr(3,isr3)
isr(4,isr4)
isr(5,isr5)
isr(6,isr6)
isr(7,isr7)
isr(8,isr8)
isr(9,isr9)
isr(10,isr10)
isr(11,isr11)
isr(12,isr12)
isr(13,isr13)
isr(14,isr14)
isr(15,isr15)
isr(16,isr16)
  
static void (* isr_tab [17]) (...) =
  { NULL,isr1,isr2,isr3,isr4,isr5,isr6,isr7,isr8,isr9,isr10,isr11,isr12,isr13,isr14,isr15,isr16 };
port=================================================== */
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/*======port

void SetVect(int num, int irq, void (*isr)(...))
{
	nint[num]=irq;
	unsigned long *vect_ptr;
	vect_ptr = (unsigned long*)(irq*4);
	*vect_ptr = (unsigned long)isr;
}
================port*/
/* ==============port

int EmbIsr::num=0;
void EmbIsr::InitIRQ(int irq)
{
	num++;
  SetVect(num, irq, isr_tab[num]);
  comarray[num] = this;
}
=========================port */

////////////////////////////  RSCOM  ////////////////////////////
void EmbCOM::IsrXX()
{
}

int EmbCOM::Init(unsigned /*rate*/)//Init(int comN,unsigned rate,char par)
{
 //rcvbuf.Init();	   //my
 //trsbuf.Init();		//my



	return 0;
}

unsigned char EmbCOM::Receive()
{
	return rcvbuf.Get();
}

unsigned char EmbCOM::ReceiveE()
{
	return rcvbufE.Get();
}

//==========================>>>port
void EmbCOM::Trans( unsigned char b)
{
//port hier need add send b to com
}
void EmbCOM::TransInit()
{
//port hier need add init
}


//==========================<<<port


////////////////////////////  RS232  ////////////////////////////
#ifdef IncEmbRS232

void EmbRS232::IsrXX()
{
 
 /*port
	unsigned char ch; //port ,c;
//port  asm { cli } 
	ch = (unsigned char)(inport(s1cnt+sStatus));	// Чтение статуса канала 1 
	if( ch & 0x10 )					// Прерывание по приему
	{
		rcvbuf.Add((unsigned char)(inport(s1cnt+sReceive)));
	}
	if( ch & 0x20 )								// Прерывание по передаче
	{
		if(trsbuf.Used())						// Если есть чего на передачу
		{
//			outport(s1cnt,sMode);
			outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
			outport(s1cnt+sTransmit,(unsigned int)(trsbuf.Get())); // Если есть чего, то пишем в порт
		}
		else
		{
//			outport(s1cnt,sMode);
			outport(s1cnt,sMode|sRxen|sRxie|sTxen);
			state = 0;
		}
	}
	outport(0xff22,0x0014);	  //============port  : what is it ?????????????					
//port  asm { sti } 
 port  */
}

#ifdef USE_USART2
void EmbRS232::Trans2(unsigned char ch)
{
 //	printfpd(":%02X", ch);
   Transmit2c(ch); //port
};
#endif


void EmbRS232::Trans(unsigned char ch)
{
//port  asm { cli } 
   Transmit0c(ch); //port
 /*
  if(TBuff0mf_cnt == (unsigned long)(SIZETX0MF))
  {
    pTBuff0mf =  &TBuff0mf[0];
	TBuff0mf_cnt = 0;
  }
    *pTBuff0mf++ = ch;
	TBuff0mf_cnt++;
   	 */
/*port	
	trsbuf.Add(ch);
	if(!state)
	{
//		outport(s1cnt,sMode);
		outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
		state = 1;
	}
port	*/	
	//port  asm { sti } 
};

//void EmbRS232::TransInit()
//{
/*port
	if(!state)
	{
//		outport(s1cnt,sMode);
		outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
		if(trsbuf.Used()) outport(s1cnt+sTransmit,(unsigned int)(trsbuf.Get())); // Если есть чего, то пишем в порт
		else outport(s1cnt+sTransmit,0x00FF); // Если нет ничего то пишем всякую лабуду

//		inportb(s1cnt+sReceive);
		state = 1;
	}
 port	*/
//};

int EmbRS232::Init(unsigned rate)//Init(int comN,unsigned rate,char par)
{

  rcvbufE.Init();	 //NEW make to not restart


 rcvbuf.Init();
 trsbuf.Init();

   cur_tbuffE = 3; //new 2 - type of interface
  tbuffE[0]	  = 0;
  tbuffE[1]	  = 0;
  tbuffE[2]	  = ETH_232;
	  for(long t = 0; t < 6; t++)	 //hostmac
 {
  // printf(".%02X", pData++);
 //dirRS232.rcvbufE.Add((unsigned char)*src++);  //t
//  src++;
  //  dirRS232.rcvbufE.Add((unsigned char)*pData++);
	HostMAC[t] =  0;

  //    pData++;
 }

	return 0;
}

void EmbRS232::TransE(unsigned char ch)
{
   if(cur_tbuffE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
	cur_tbuffE = 3;
   }
   tbuffE[cur_tbuffE++] = ch;
};

void EmbRS232::TransEC(unsigned char ch)
{
//#ifndef TRY_FIND_ERR
   Transmit0c(ch);
//#endif // TRY_FIND_ERR

   if(cur_tbuffE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
 	cur_tbuffE = 3;

   }
   tbuffE[cur_tbuffE++] = ch;
};

void EmbRS232::Trans_RDN(unsigned int dest)
{
  //__________________________________
  //hier need call transmit to ethernet;
  static char netdest[6];
  netdest[0] = RDN_MAC0;
  netdest[1] = RDN_MAC1;
  netdest[2] = RDN_MAC2;
  netdest[3] = (char)(dest >> 16);
  netdest[4] = (char)(dest >> 8);
  netdest[5] = (char)dest;

  tbuffE[0] = 	(char)cur_tbuffE >> 8;
  tbuffE[1] = 	(char)cur_tbuffE; // 
  tbuffE[2] = 	ETH_232;

//t  RDN_Start_Transmit();
  RDN_Start_Transmit(tbuffE, netdest);
  //__________________________________
 // cur_tbuffE = 2;
    cur_tbuffE = 3;	 //new

}

void EmbRS232::Trans_RDN_Full(char* dest)
{
  //__________________________________
  //hier need call transmit to ethernet;
  static char netdest[6];
  
  netdest[0] = *dest++;
  netdest[1] = *dest++;
  netdest[2] = *dest++;
  netdest[3] = *dest++;
  netdest[4] = *dest++;
  netdest[5] = *dest;

  if((!netdest[0]) && (!netdest[1]) && 
       (!netdest[2]) && (!netdest[3]) && (!netdest[4]) &&(!netdest[5]))
   {
   	return; //not have connect with PC
   }
  tbuffE[0] = 	(char)cur_tbuffE >> 8;
  tbuffE[1] = 	(char)cur_tbuffE; // 
  tbuffE[2] = 	ETH_DIR;

//t  RDN_Start_Transmit();
//090629 #ifndef RS232E_ENABLE
  RDN_Start_Transmit(tbuffE, netdest);
//090629 #endif // RS232E_ENABLE


  //__________________________________
 // cur_tbuffE = 2;
    cur_tbuffE = 3;	 //new

}


void EmbRS232::Trans_RDN_Brdcst()
{
  //__________________________________
  //hier need call transmit to ethernet;
  static char netdest[6];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;
  tbuffE[0] = 	(char)cur_tbuffE >> 8;
  tbuffE[1] = 	(char)cur_tbuffE; // 
  tbuffE[2] = 	ETH_232;
//t  RDN_Start_Transmit();
  RDN_Start_Transmit(tbuffE, netdest);
  //__________________________________
 // cur_tbuffE = 2;
    cur_tbuffE = 3;	 //new

}




#endif
///////////////////////////   T i m e r   /////////////////////////////
#ifdef IncEmbTimer

void EmbTimer::IsrXX()
{
//port	asm{ sti }

	ttt++;
 if(embTimerCallback0) 
	{ 
		embTimerCallback0->count++; 
		if(embTimerCallback0->count>=embTimerCallback0->interval) 
		{ 
			embTimerCallback0->count = 0; 
			(*embTimerCallback0->callback)(); 
		}
	}

	if(embTimerCallback1) 
	{ 
		embTimerCallback1->count++; 
		if(embTimerCallback1->count>=embTimerCallback1->interval) 
		{ 
			embTimerCallback1->count = 0; 
			(*embTimerCallback1->callback)(); 
		}
	}
	if(embTimerCallback2) 
	{ 
		embTimerCallback2->count++; 
		if(embTimerCallback2->count>=embTimerCallback2->interval) 
		{ 
			embTimerCallback2->count = 0; 
			(*embTimerCallback2->callback)(); 
		}
	}
	if(embTimerCallback3) 
	{ 
		embTimerCallback3->count++; 
		if(embTimerCallback3->count>=embTimerCallback3->interval) 
		{ 
			embTimerCallback3->count = 0; 
			(*embTimerCallback3->callback)(); 
		}
	}
	if(embTimerCallback4) 
	{ 
		embTimerCallback4->count++; 
		if(embTimerCallback4->count>=embTimerCallback4->interval) 
		{ 
			embTimerCallback4->count = 0; 
			(*embTimerCallback4->callback)(); 
		}
	}


  /* port
    outport(t2con,0x2001);
	outport(0xff22,0x0008);	
  port	*/					
}

int EmbTimer::Init(int ms)//Init(int comN,unsigned rate,char par)
{
 // port 	unsigned c;
	embTimerCallback0 = 0;
	embTimerCallback1 = 0;
	embTimerCallback2 = 0;
	embTimerCallback3 = 0;
	embTimerCallback4 = 0;
///
/*port
	outport(t0con,0x4000);
	outport(t1con,0x4000);

  outport(t2con,0x6001);
	outport(t2cnt,0x0000);
///
	outport(t2cmpa,800*ms); 
	outport(t2con,0xe001);

//port	EmbIsr::InitIRQ(0x13);
	c=inport(imask);
	outport(imask,c&0xfffe);
///
	outport(tcucon,0x0000);
///
port */
	return 0;
}

void EmbTimer::SetCallBack0(EmbTimerCallback *e) { embTimerCallback0 = e; }
void EmbTimer::SetCallBack1(EmbTimerCallback *e) { embTimerCallback1 = e; }
void EmbTimer::SetCallBack2(EmbTimerCallback *e) { embTimerCallback2 = e; }
void EmbTimer::SetCallBack3(EmbTimerCallback *e) { embTimerCallback3 = e; }
void EmbTimer::SetCallBack4(EmbTimerCallback *e) { embTimerCallback4 = e; }

#endif
///////////////////////////////////////////////////////////////////////
//////////////////////////       N M I      ///////////////////////////
///////////////////////////////////////////////////////////////////////
//portint EmbNMI2::Init()
// {
//port   EmbIsr::InitIRQ(0x02);
 //port  return 0; }
//portvoid EmbNMI2::IsrXX() 
//{  
/* ===============port
	outport(wdtcon,0xAAAA);
	outport(wdtcon,0x5555);
	asm { db 0FAh, 0EAh, 00h, 00h, 0FFh, 0FFh }
====================port*/
//}

#ifdef IncNMI
   /*
int EmbNMI0::Init() { EmbIsr::InitIRQ(0x00); return 0; }
void EmbNMI0::IsrXX() {  }
int EmbNMI1::Init() { EmbIsr::InitIRQ(0x01); return 0; }
void EmbNMI1::IsrXX() {  }
int EmbNMI3::Init() { EmbIsr::InitIRQ(0x03); return 0; }
void EmbNMI3::IsrXX() {  }
int EmbNMI4::Init() { EmbIsr::InitIRQ(0x04); return 0; }
void EmbNMI4::IsrXX() {  }
int EmbNMI5::Init() { EmbIsr::InitIRQ(0x05); return 0; }
void EmbNMI5::IsrXX() {  }
int EmbNMI6::Init() { EmbIsr::InitIRQ(0x06); return 0; }
void EmbNMI6::IsrXX() {  }
int EmbNMI5::Init() { EmbIsr::InitIRQ(0x07); return 0; }
void EmbNMI5::IsrXX() {  }
int EmbNMI6::Init() { EmbIsr::InitIRQ(0x08); return 0; }
void EmbNMI6::IsrXX() { }
	 */
#endif
///////////////////////////////////////////////////////////////////////
////////////                  Indicator                  //////////////
///////////////////////////////////////////////////////////////////////
#ifdef IncEmbIndicator

int EmbIndicator::Init()
{
//port	unsigned long i;
//port	unsigned char c;
 //port	EmbIsr::InitIRQ(INDICATOR_IRQ);	// Устанавливаем вектор обработчика прерываний	
    m_RBuff.Init();
	m_TBuff.Init();
 //portbyf	r_state = 0;
#ifndef PULT_USART	
	outportb(INDICATOR_CTRL,0x48);	// Сброс
//  port for(i=0; i<20000; i++);
	delay_mcs(1000l); //port	  
	outportb(INDICATOR_CTRL,0x32);
//	for(i=0; i<20000; i++);
	delay_mcs(40000l);

//port	m_RBuff.Init();
//port	m_TBuff.Init();

//port	r_state = 0;

 /* port
	outport(i2con,0x0017);    
	c=inport(imask);              // Маска перываний - чтение ()
	outport(imask,c&0xffbf);			// Ввод маски прерываний ()
 */
//	outport(pacs,0x0079);
//	outport(mpcs,0x81bf);

	eic.byte = 0; //inportb(INDICATOR_CTRL);
	eic.bit.dirCTS = 0;
	eic.bit.IRQ_receive = 1;
	eic.bit.IRQ_trans = 0;
	eic.bit.receive = 1;
	eic.bit.trans = 1;
	outportb(INDICATOR_CTRL,eic.byte);
#else // PULT_USART
 /* //this maked in my pult init
 for(long i = 0; i < 26; i++)
 {
  Transmit3c(0x55); //reset
  PultDelay();
 }
  */
#endif
	return 0;	
}

void EmbIndicator::Cursor(char mode,unsigned char addr)
{
#ifndef PULT_USART	
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('C');
		m_TBuff.Add(addr);
		m_TBuff.Add(mode);
    }
#else
	    ToIBuf('U');
		ToIBuf('C');
		ToIBuf(addr);
		ToIBuf(mode);
#endif

 CopyCur2Remote(addr + (mode * 200));	 //make for all devices !!


}
void EmbIndicator::Reset()
{
#ifndef PULT_USART	
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
  }
#else  //	 PULT_USART
for(long i = 0; i < 26; i++)
 {
  Transmit3c(0x55); //reset
  PultDelay();
 }
#endif
}
void EmbIndicator::SetStr0(char *str) 
{
/*
	if(m_TBuff.Free())
	{
		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		m_TBuff.Add('U');
		m_TBuff.Add('I');
		m_TBuff.Add(0x80);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) m_TBuff.Add(s[i]);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
    }
*/

 //_____________________________________port

// printEthString(str, 27);	  //t
 //	printEthByteHex(*str);

		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		ToIBuf('U');
		ToIBuf('I');
	    ToIBuf(0x80);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) 
		ToIBuf(s[i]);
//___________________________________________port



}
void EmbIndicator::SetStr1(char *str) 
{
/* port
	if(m_TBuff.Free())
	{
		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		m_TBuff.Add('U');
		m_TBuff.Add('I');
		m_TBuff.Add(0xC0);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) 
		m_TBuff.Add(s[i]);

		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
  */

//_____________________________________port

 //printEthString(str, 27);
 //	printEthByteHex(*str);

		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		ToIBuf('U');
		ToIBuf('I');
	    ToIBuf(0xC0);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) 
		ToIBuf(s[i]);
//___________________________________________port
}
void EmbIndicator::SetLtDiod(char mode,char number) 
{
// return; //for test
 //port	EmbIndCtrl eic;
#ifndef PULT_USART
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('L');
		m_TBuff.Add((mode<<4)+number);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);

	    }
#else
	   ToIBuf('U');
	   ToIBuf('L');
	   ToIBuf((mode<<4)+number);
#endif
	CopyLed2Remote((mode << 4) + number);

}
void EmbIndicator::Sound0(char frequ)
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x00);
		m_TBuff.Add(frequ);		
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
	    ToIBuf('U');
		ToIBuf('S');
		ToIBuf(0x00);
		ToIBuf(frequ);

#endif
}

void EmbIndicator::SoundAlarm()
{

#ifndef PULT_USART
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x24);
		m_TBuff.Add(0x0A);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x07);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x04);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x02);
		m_TBuff.Add(0x01);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }

#else //  PULT_USART
   		ToIBuf('U');
		ToIBuf('S');
		ToIBuf(0x24);
		ToIBuf(0x0A);
		ToIBuf(0x01);
		ToIBuf(0x07);
		ToIBuf(0x01);
		ToIBuf(0x04);
		ToIBuf(0x01);
		ToIBuf(0x02);
		ToIBuf(0x01);
#endif //	 PULT_USART
}

void EmbIndicator::SoundRing()
{
#ifndef PULT_USART
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x22);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x02);
		m_TBuff.Add(0x01);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  	}
#else //  PULT_USART
	  	ToIBuf('U');
		ToIBuf('S');
		ToIBuf(0x22);
		ToIBuf(0x01);
		ToIBuf(0x01);
		ToIBuf(0x02);
		ToIBuf(0x01);
#endif //  PULT_USART
}

void EmbIndicator::Sound1(char mode,EmbSound s1) 
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
		ToIBuf('U');
		ToIBuf('S');
		ToIBuf((mode<<4)+0x01);
		ToIBuf(s1.frequ);
		ToIBuf((s1.pause<<4)+s1.sound);
#endif
}
void EmbIndicator::Sound2(char mode,EmbSound s1,EmbSound s2) 
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
	    ToIBuf('U');
		ToIBuf('S');
		ToIBuf((mode<<4)+0x01);
		ToIBuf(s1.frequ);
		ToIBuf((s1.pause<<4)+s1.sound);
		ToIBuf(s2.frequ);
		ToIBuf((s2.pause<<4)+s2.sound);

#endif
}
void EmbIndicator::Sound3(char mode,EmbSound s1,EmbSound s2,EmbSound s3) 
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		m_TBuff.Add(s3.frequ);
		m_TBuff.Add((s3.pause<<4)+s3.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
		ToIBuf('U');
		ToIBuf('S');
		ToIBuf((mode<<4)+0x01);
		ToIBuf(s1.frequ);
		ToIBuf((s1.pause<<4)+s1.sound);
		ToIBuf(s2.frequ);
		ToIBuf((s2.pause<<4)+s2.sound);
		ToIBuf(s3.frequ);
		ToIBuf((s3.pause<<4)+s3.sound);

#endif
}
void EmbIndicator::Sound4(char mode,EmbSound s1,EmbSound s2,EmbSound s3,EmbSound s4) 
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		m_TBuff.Add(s3.frequ);
		m_TBuff.Add((s3.pause<<4)+s3.sound);
		m_TBuff.Add(s4.frequ);
		m_TBuff.Add((s4.pause<<4)+s4.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
	 	ToIBuf('U');
		ToIBuf('S');
		ToIBuf((mode<<4)+0x01);
		ToIBuf(s1.frequ);
		ToIBuf((s1.pause<<4)+s1.sound);
		ToIBuf(s2.frequ);
		ToIBuf((s2.pause<<4)+s2.sound);
		ToIBuf(s3.frequ);
		ToIBuf((s3.pause<<4)+s3.sound);
		ToIBuf(s4.frequ);
		ToIBuf((s4.pause<<4)+s4.sound);
#endif
}

void EmbIndicator::Receipt()
{
#ifndef PULT_USART

	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('N');
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
#else
		ToIBuf('U');
		ToIBuf('N');
#endif
}

void EmbIndicator::IsrXX()
{
#ifndef PULT_USART
//	sss = m_TBuff.Used();
//port	asm{ sti }
	EmbIndCtrl eic;
   
	eic.byte = inportb(INDICATOR_CTRL);	// Чтение статуса канала 1 
   
	if(eic.bit.IRQ_receive)								// Прерывание по приему
	{
		char ch = inportb(INDICATOR_DATA);
		//if(ch=='U') r_state=1;
		//else
		{
			m_RBuff.Add(ch); 
			//r_state = 0; 
		}
	}
	if(eic.bit.IRQ_trans) 							// Прерывание по передаче
//	if(eic.byte&0x01)								// Прерывание по передаче
	{
	  if(m_TBuff.Used()) 
		{
	 		outportb(INDICATOR_DATA,m_TBuff.Get());
		}
		else 
		{
			eic.byte = 0; //inportb(INDICATOR_CTRL);
			eic.bit.dirCTS = 0;
			eic.bit.IRQ_receive = 1;
			eic.bit.IRQ_trans = 0;
			eic.bit.receive = 1;
			eic.bit.trans = 1;
			outportb(INDICATOR_CTRL,eic.byte);
		}
	}
#endif //pult_usart	
//port	outport(0xff22,0x000e);						
}
#endif
////////////////////////////  RS485  ////////////////////////////
#ifdef IncEmbRS485

void EmbRS485::IsrXX()
{
//port	asm{ sti }
/* port
  Emb485Bit eic;
	eic.byte = inportb(RS485_CTRL);	// Чтение статуса канала 1 

	if(eic.bit.IRQ_receive)								// Прерывание по приему
	{
		char ch = inportb(RS485_DATA);
		rcvbuf.Add(ch); 
	}
	if(inport(piodat0)&0x0400)//eic.bit.IRQ_trans)								// Прерывание по передаче
	  if(trsbuf.Used()) 
		{
			outportb(RS485_DATA,trsbuf.Get());
		}
		else 
		{
			eic.byte = 0; //inportb(INDICATOR_CTRL);
			eic.bit.IRQ_receive = 1;
			eic.bit.IRQ_trans = 0;
			eic.bit.receive = 1;
			eic.bit.trans = 0;
			outportb(RS485_CTRL,eic.byte);
      outport(piodat0,inport(piodat0)&0xFBFF);    
		}
	outport(0xff22,0x0010);		
 port	*/				
}

void EmbRS485::Trans(unsigned char ch)
{
//port  asm{ cli }
 //to make snmp  Transmit1c(ch);  //port
//#ifdef PROG_BMD35
// t_set = 1;
 //b_set = ch;
//#endif //PROG_BMD35
 //  return; //100110 
   Transmit485c(ch);
/*port
	trsbuf.Add(ch);
  Emb485Bit eic;
	eic.byte = 0; //inportb(INDICATOR_CTRL);
	eic.bit.IRQ_receive = 0;
	eic.bit.IRQ_trans = 1;
	eic.bit.receive = 0;
	eic.bit.trans = 1;
	outportb(RS485_CTRL,eic.byte);
  outport(piodat0,inport(piodat0)|0x400); 
 port  */  
//port  asm{ sti }
 //  if(cur_tbuffE >= RDN_BUFFER_SIZE)
 //  {
 //	cur_tbuffE = 2;
 //  }
 //  tbuffE[cur_tbuffE++] = ch;
};

void EmbRS485::TransE(unsigned char ch)
{
// return; //100110 
   if(cur_tbuffE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
	cur_tbuffE = 3;
   }
   tbuffE[cur_tbuffE++] = ch;
};

void EmbRS485::TransS(unsigned char ch)
{
if(!curbuff)
{
   if(cur_tbuffS1 >= RDN_BUFFER_SIZE)
   {
 	cur_tbuffS1 = 0;
   }
   tbuffS1[cur_tbuffS1++] = ch;
}
else
{
   if(cur_tbuffS2 >= RDN_BUFFER_SIZE)
   {
 	cur_tbuffS2 = 0;
   }
   tbuffS2[cur_tbuffS2++] = ch;
}
};

void EmbRS485::TransSGO(void)
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
if(!curbuff)
{
  usart1_ptr->PDC.TPR = (unsigned long)tbuffS1;
  usart1_ptr->PDC.TCR = cur_tbuffS1;
  cur_tbuffS1 = 0;
  curbuff = 1;
}
else
{
  usart1_ptr->PDC.TPR = (unsigned long)tbuffS2;
  usart1_ptr->PDC.TCR = cur_tbuffS2;
  cur_tbuffS2 = 0;
  curbuff = 0;
}
   usart1_ptr->PDC.TNPR = 0;
   usart1_ptr->PDC.TNCR = 0;
   /* Interrupt when transmission is completed */
 //t  usart1_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   /* Enable PDC Transmitter */
   usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;
};





void EmbRS485::TransEC(unsigned char ch)
{
 //return; //100110 
   Transmit485c(ch);
   if(cur_tbuffE >= RDN_BUFFER_SIZE)
   {
 //t	cur_tbuffE = 2;
 	cur_tbuffE = 3;

   }
   tbuffE[cur_tbuffE++] = ch;
};



int EmbRS485::Init(unsigned rate)//Init(int comN,unsigned rate,char par)
{

  rcvbuf.Init();
  rcvbufE.Init();

  trsbuf.Init();
//  cur_tbuffE = 2;
  cur_tbuffE = 3; //new 2 - type of interface
  tbuffE[0]	  = 0;
  tbuffE[1]	  = 0;
  tbuffE[2]	  = ETH_485;

curbuff = 0;
cur_tbuffS1 = 0;
cur_tbuffS2	= 0;
	return 0;
}


void EmbRS485::Trans_RDN(unsigned int dest)
{
//printf("\n\r Used");
  //__________________________________
  //hier need call transmit to ethernet;
  static char netdest[6];
//  my_int_disable();	 //t1020
  netdest[0] = RDN_MAC0;
  netdest[1] = RDN_MAC1;
  netdest[2] = RDN_MAC2;
  netdest[3] = (char)(dest >> 16);
  netdest[4] = (char)(dest >> 8);
  netdest[5] = (char)dest;
  tbuffE[0]  = (char)cur_tbuffE >> 8;
  tbuffE[1]  = (char)cur_tbuffE; // 
  tbuffE[2]  = ETH_485;
//t  RDN_Start_Transmit();
  RDN_Start_Transmit(tbuffE, netdest);

  //__________________________________
 // cur_tbuffE = 2;
   cur_tbuffE = 3;	 //new
//   my_int_enable();	 //t1020

}

//void EmbRS485::Rcv_RDN()
//{
//  while(RDN_BufferR.Used())
//	{
//	  embRS485.rcvbuf.Add((unsigned char)RDN_BufferR.Get());
//    }
//}

#endif 
////////////////////////////////////////////////////////////////////
////////////             Real Time Clock              //////////////
////////////////////////////////////////////////////////////////////
#ifdef ETH_DEBUG_ENABLED
#define DEBUG_BUFFERS_SIZE  (500)

void printEthStringAdd(char set, char Data)
{
static char tPrint[DEBUG_BUFFERS_SIZE];
//static char * ptPrint;
static unsigned long len;
char bData[5];

	if(set == 0)
	{
	len = 0;
//	ptPrint = tPrint;
	}
	else if(set == 2)
	{
// 	 printEthString(tPrint, len);
 	 printEthString(tPrint, len+3);	//t
//	 printEthLongHex(len);//t	 78 have!
	

	}
	else if(set == 1)
	{
 //	printEthLongHex(Data);//t	 78 have!
	 sprintf(bData , " %02X", Data);
	 for(long i = 0; i < 3; i++)
	 {
	 tPrint[len++] = bData[i];
	 if(len>=DEBUG_BUFFERS_SIZE) len = 0;
	 }
	} 
} 


void printEthString(char * tbuffprint, unsigned long len)
{
 char netdest[6];
 char tbuffEth[1000];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;
  tbuffEth[0]  = (char)len >> 8;
  tbuffEth[1]  = (char)len; // 
  tbuffEth[2]  = ETH_DBG;
  for(unsigned long i = 3 ; i < (3 + len); i++)
 // for(unsigned long i = 3 ; i < (6 + len); i++)
  {
	tbuffEth[i] = * tbuffprint++;
  }
//t  RDN_Start_Transmit();
  RDN_Start_Transmit(tbuffEth, netdest);
}

void printEthLongHex(unsigned long data)
{
 static char netdest[6];
 char tbuffEth[200];
 char  Buffer[10];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;
  tbuffEth[0]  = 0;
  tbuffEth[1]  = 13; // len
  tbuffEth[2]  = ETH_DBG;
   sprintf(Buffer, "0x%08X", data);
  for(long i = 0; i < 10; i++)
   {
	tbuffEth[i + 3] = Buffer[i];
   }
  RDN_Start_Transmit(tbuffEth, netdest);
}

void printEthByteHex(unsigned char data)
{
 static char netdest[6];
 char tbuffEth[200];
 char  Buffer[10];
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;
  tbuffEth[0]  = 0;
  tbuffEth[1]  = 5; // len
  tbuffEth[2]  = ETH_DBG;
  sprintf(Buffer, "%02X", data);
  for(long i = 0; i < 10; i++)
   {
	 tbuffEth[i + 3] = Buffer[i];
   }
  RDN_Start_Transmit(tbuffEth, netdest);
}


#endif // ETH_DEBUG_ENABLED



void EmbRTClock::Init()
{

}        

void EmbRTClock::StartClock()
{

}

void EmbRTClock::SetTimeDate(RTUnion */*r*/)
{

}

void EmbRTClock::GetTimeDate(RTUnion */*r*/)
{

}

char *EmbRTClock::GetTimeDateStr(char *str)
{
 /* ====================port
	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
port=============================*/
//char_ptr ctrl; //===============port
// need later init ctrl to clocks
   write_nvram_char(0x7FF8, 0x40); //bit d6 to "1"	 - stop changing reading registers
   str[0] = (read_nvram_char(0x7FFF >> 4) & 0x0f) + '0';	 //year
   str[1] = (read_nvram_char(0x7FFF     ) & 0x0f) + '0';
   str[2] =	 '/';
   str[3] = (read_nvram_char(0x7FFE >> 4) & 0x0f) + '0';	 //month
   str[4] = (read_nvram_char(0x7FFE     ) & 0x0f) + '0';
   str[5] =	 '/';
   str[6] = (read_nvram_char(0x7FFD >> 4) & 0x0f) + '0';	 //date
   str[7] = (read_nvram_char(0x7FFD     ) & 0x0f) + '0';
   str[8] =	 ' ';
   str[9] =  (read_nvram_char(0x7FFC >> 4) & 0x0f) + '0';	 //hour
   str[10] = (read_nvram_char(0x7FFC     ) & 0x0f) + '0';
   str[11] = ':';
   str[12] = (read_nvram_char(0x7FFB >> 4) & 0x0f) + '0';	 //min
   str[13] = (read_nvram_char(0x7FFB     ) & 0x0f) + '0';
   str[14] = ':';
   str[15] = (read_nvram_char(0x7FFA >> 4) & 0x0f) + '0';	 //sec
   str[16] = (read_nvram_char(0x7FFA     ) & 0x0f) + '0';
   str[17] = 0;
   write_nvram_char(0x7FF8, 0x0); //bit d6 to "0"
 /*===========================port


	*ctrl = 0x40;

	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.year>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.year&0x0F)+'0';
  str[2]='/';
  str[3]=((ru->rt_time.mon>>4)&0x01)+'0';
  str[4]=(ru->rt_time.mon&0x0F)+'0';
  str[5]='/';
  str[6]=((ru->rt_time.date>>4)&0x03)+'0';
  str[7]=(ru->rt_time.date&0x0F)+'0';
  str[8]=' ';
  str[9]=((ru->rt_time.hour>>4)&0x0F)+'0';
  str[10]=(ru->rt_time.hour&0x0F)+'0';
  str[11]=':';
  str[12]=((ru->rt_time.min>>4)&0x0F)+'0';
  str[13]=(ru->rt_time.min&0x0F)+'0';
  str[14]=':';
  str[15]=((ru->rt_time.sec>>4)&0x0F)+'0';
  str[16]=(ru->rt_time.sec&0x0F)+'0';
  str[17]=0;
=====================port  */
//	*ctrl = 0x00;
	return str;	 //later need make clocks
}

char *EmbRTClock::GetTimeStr(char *str)
{
   write_nvram_char(0x7FF8, 0x40); //bit d6 to "1"	 - stop changing reading registers
   str[0] = (read_nvram_char(0x7FFC >> 4) & 0x0f) + '0';	 //hour
   str[1] = (read_nvram_char(0x7FFC     ) & 0x0f) + '0';
   str[2] = ':';
   str[3] = (read_nvram_char(0x7FFB >> 4) & 0x0f) + '0';	 //min
   str[4] = (read_nvram_char(0x7FFB     ) & 0x0f) + '0';
   str[5] = ':';
   str[6] = (read_nvram_char(0x7FFA >> 4) & 0x0f) + '0';	 //sec
   str[7] = (read_nvram_char(0x7FFA     ) & 0x0f) + '0';
   str[8] = 0;
   write_nvram_char(0x7FF8, 0x0); //bit d6 to "0"

 /*===========================port
	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
	*ctrl = 0x40;
	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.hour>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.hour&0x0F)+'0';
  str[2]=':';
  str[3]=((ru->rt_time.min>>4)&0x0F)+'0';
  str[4]=(ru->rt_time.min&0x0F)+'0';
  str[5]=':';
  str[6]=((ru->rt_time.sec>>4)&0x0F)+'0';
  str[7]=(ru->rt_time.sec&0x0F)+'0';
  str[8]=0;
	*ctrl = 0x00;
  port=======================*/ 
	return str;	 //make clocks later
}

char *EmbRTClock::GetDateStr(char *str)
{
    write_nvram_char(0x7FF8, 0x40); //bit d6 to "1"	 - stop changing reading registers
   str[0] = (read_nvram_char(0x7FFF >> 4) & 0x0f) + '0';	 //year
   str[1] = (read_nvram_char(0x7FFF     ) & 0x0f) + '0';
   str[2] =	 '/';
   str[3] = (read_nvram_char(0x7FFE >> 4) & 0x0f) + '0';	 //month
   str[4] = (read_nvram_char(0x7FFE     ) & 0x0f) + '0';
   str[5] =	 '/';
   str[6] = (read_nvram_char(0x7FFD >> 4) & 0x0f) + '0';	 //date
   str[7] = (read_nvram_char(0x7FFD     ) & 0x0f) + '0';
   str[8] = 0;
   write_nvram_char(0x7FF8, 0x0); //bit d6 to "0"




  /*===========================port
	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
	*ctrl = 0x40;
	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.year>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.year&0x0F)+'0';
  str[2]='/';
  str[3]=((ru->rt_time.mon>>4)&0x01)+'0';
  str[4]=(ru->rt_time.mon&0x0F)+'0';
  str[5]='/';
  str[6]=((ru->rt_time.date>>4)&0x03)+'0';
  str[7]=(ru->rt_time.date&0x0F)+'0';
  str[8]=0;
	*ctrl = 0x00;
	port======================*/
	return str; //make date later
}
///////////////////////////////////////////////////////////////////////
////////////                Used Interrupts              //////////////
///////////////////////////////////////////////////////////////////////
/* port 
unsigned long irq0=0;
unsigned long irq1=0;
unsigned long irq4=0;
unsigned long err0=0;
unsigned long err1=0;
unsigned long err4=0;
unsigned char signal=0;

void EmbIsrINT0::Init() 
{ 
 //port	EmbIsr::InitIRQ(0x0C); 
	outport(i0con,0x0010);    // 0-регистр управления (разрешения) прерываниями
	unsigned c=inport(imask); // Маска перываний - чтение ()
	outport(imask,c&0xffef);	// Ввод маски прерываний ()
}
void EmbIsrINT0::EOI() { outport(0xff22,0x000C); }
void EmbIsrINT0::IsrXX() 
{
	EOI();
}
*/
void EmbIsrINT1::Init() 
{ 
 //port	EmbIsr::InitIRQ(0x0D); 
 //	outport(i1con,0x0015);        // управления (разрешения) прерываниями
 //	unsigned c=inport(imask);     // Маска перываний - чтение ()
 //	outport(imask,c&0xffdf);			// Ввод маски прерываний ()
}
void EmbIsrINT1::EOI() {
// outport(0xff22,0x000D);
  }
void EmbIsrINT1::IsrXX() 
{
 // EOI();
}

#ifdef IncEmbSerialACT155

void EmbSerialACT155::IsrXX() 
{
//fot test _______________________________________________________
 // static char cnt;
 // cnt++;
 // outportb(0x5A7,cnt);
//for test________________________________________________________
	UnEmbSerialACT155Status status;
	UnEmbSerialACT155IRQ irq,mask;
	   //a8  aa - status
	   //a7, a9 - many times   receiver 

       // 
	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x5A5);	//int
	mask.byte = inportb(0x5A6);	//mask

//#ifdef TEST_PUM
//  printfpd("\n\r 4: %02x", status.byte);
//   printfpd(" 5: %02x", irq.byte);
//    printfpd(" 6: %02x", mask.byte);
//	OperateBuffers_usart1t();

//#endif
	if(irq.bit.IRQ_TX_mod)
	if(m_TBuffMod.Used()) 
	{

	 outportb(0x5A7,m_TBuffMod.Get());
	 if(!m_TBuffMod.Used())  mask.bit.IRQ_TX_mod=0;
	}
    else
     mask.bit.IRQ_TX_mod=0;

	if(irq.bit.IRQ_TX_trans)
	 if(m_TBuffTransit.Used()) 
	 { 
	 outportb(0x5A9,m_TBuffTransit.Get());
	 	if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0;
	 	 }
	 	 else mask.bit.IRQ_TX_trans=0;

	if(irq.bit.IRQ_TX_power)
	 if(m_TBuffPower.Used())
	  { 
	  outportb(0x5AB,m_TBuffPower.Get());
	  	if(!m_TBuffPower.Used()) mask.bit.IRQ_TX_power=0;
	  	 } 
	  	else 
	  	mask.bit.IRQ_TX_power=0;

   	if(irq.bit.IRQ_RX_mod)		m_RBuffMod.Add(inportb(0x5A7)); 
 	if(irq.bit.IRQ_RX_trans) 	m_RBuffTransit.Add(inportb(0x5A9)); 
	if(irq.bit.IRQ_RX_power)    m_RBuffPower.Add(inportb(0x5AB)); 

	outportb(0x5A6,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
	count++;
 //	EmbIsrINT1::EOI();
}


void EmbSerialACT155::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	m_RBuffPower.Init(); 
	m_TBuffPower.Init(); 
	UnEmbSerialACT155IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
//	mask.bit.IRQ_RX_power=1;
	outportb(0x5A6,mask.byte);
} 


void EmbSerialACT155::AddMod(unsigned char byte)
{ 

//return; //for test
my_int_disable_irq0();
 // 	count--; //for test
 	m_TBuffMod.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x5A6,mask.byte);
my_int_enable_irq0();
}
void EmbSerialACT155::AddTransit(unsigned char byte)
{ 
 my_int_disable_irq0();
	m_TBuffTransit.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x5A6,mask.byte);
my_int_enable_irq0();
}
void EmbSerialACT155::AddPower(unsigned char byte)
{ 
my_int_disable_irq0();
	m_TBuffPower.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x5A6,mask.byte);
 my_int_enable_irq0();
}

#endif

#ifdef IncEmbSerialSPI


#define SPI_BUFFER_SIZE (16)
extern "C" unsigned char OperateCommand(unsigned char *);


void EmbSerialSPI::IsrXX() 
{
//fot test _______________________________________________________
 // static char cnt;
 // cnt++;
 // outportb(0x5A7,cnt);
//for test________________________________________________________
	UnEmbSerialSPIStatus irq; //status;
	UnEmbSerialSPIIRQ mask;
	unsigned char Data;
	unsigned char cnt = SPI_BUFFER_SIZE;

	   //a8  aa - status
	   //a7, a9 - many times   receiver 

       // 
//	status.byte = inportb(STATUS_SPI_XIL);
	irq.byte  	= inportb(STATUS_SPI_XIL);	//int
	mask.byte 	= inportb(MASK_SPI_XIL);	//mask

//#ifdef TEST_PUM
//  printfpd("\n\r 4: %02x", status.byte);
//   printfpd(" 5: %02x", irq.byte);
//    printfpd(" 6: %02x", mask.byte);
//	OperateBuffers_usart1t();

//#endif
	if(irq.bit.IRQ_TX_mod)
	if(m_TBuffMod.Used()) 
	{

 //	 outportb(0x5A7,m_TBuffMod.Get());
	 outportb(DATA_SPI_XIL,m_TBuffMod.Get());

	 if(!m_TBuffMod.Used())  mask.bit.IRQ_TX_mod=0;
	}
    else
     mask.bit.IRQ_TX_mod=0;
 /*
	if(irq.bit.IRQ_TX_trans)
	 if(m_TBuffTransit.Used()) 
	 { 
	 outportb(0x5A9,m_TBuffTransit.Get());
	 	if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0;
	 	 }
	 	 else mask.bit.IRQ_TX_trans=0;

	if(irq.bit.IRQ_TX_power)
	 if(m_TBuffPower.Used())
	  { 
	  outportb(0x5AB,m_TBuffPower.Get());
	  	if(!m_TBuffPower.Used()) mask.bit.IRQ_TX_power=0;
	  	 } 
	  	else 
	  	mask.bit.IRQ_TX_power=0;
		*/
   	if(irq.bit.IRQ_RX_mod)
   	while(irq.bit.IRQ_RX_mod)
	{
 //  		Data = inportb(0x5A7);
 
   	   Data = inportb(DATA_SPI_XIL);
   	   OperateCommand(&Data);//	m_RBuffMod.Add(inportb(0x5A7)); 
 	   irq.byte  	= inportb(STATUS_SPI_XIL);
 	   cnt--;
	   
 	   if(!cnt) break;
	}
  //	if(irq.bit.IRQ_RX_trans) 	m_RBuffTransit.Add(inportb(0x5A9)); 
  //	if(irq.bit.IRQ_RX_power)    m_RBuffPower.Add(inportb(0x5AB)); 

//	outportb(0x5A6,mask.byte);
	outportb(MASK_SPI_XIL,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
	count++;
 //	EmbIsrINT1::EOI();
}


void EmbSerialSPI::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init();
	 /*
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	m_RBuffPower.Init(); 
	m_TBuffPower.Init(); 
	*/
	UnEmbSerialSPIIRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
 //	mask.bit.IRQ_RX_trans=1;
//	mask.bit.IRQ_RX_power=1;
  //	outportb(0x5A6,mask.byte);
	outportb(MASK_SPI_XIL,mask.byte);

	UnEmbSerialSPIOperate	 operate;
	operate.byte = 0;
   	operate.bit.Rx_reset = 1;
  	operate.bit.Tx_reset = 1;
	operate.bit.bit_order = 1;
	outportb(OPERATE_SPI_XIL,operate.byte);
   operate.bit.Rx_reset = 0;
  	operate.bit.Tx_reset = 0;
	outportb(OPERATE_SPI_XIL,operate.byte);


} 


void EmbSerialSPI::AddMod(unsigned char byte)
{ 

//return; //for test
my_int_disable_irq0();
 // 	count--; //for test
 	m_TBuffMod.Add(byte); 	
	UnEmbSerialSPIIRQ mask;
 //	mask.byte = inportb(0x5A6);
	mask.byte = inportb(MASK_SPI_XIL);
	mask.bit.IRQ_TX_mod = 1;
  //	outportb(0x5A6,mask.byte);
	outportb(MASK_SPI_XIL,mask.byte);
my_int_enable_irq0();
}
/*
void EmbSerialSPI::AddTransit(unsigned char byte)
{ 
 my_int_disable_irq0();
	m_TBuffTransit.Add(byte); 	
	UnEmbSerialSPIIRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x5A6,mask.byte);
my_int_enable_irq0();
}
void EmbSerialSPI::AddPower(unsigned char byte)
{ 
my_int_disable_irq0();
	m_TBuffPower.Add(byte); 	
	UnEmbSerialSPIIRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x5A6,mask.byte);
 my_int_enable_irq0();
}
	*/
#endif





/*
void EmbIsrINT2::Init() { 
//port EmbIsr::InitIRQ(0x0E);
 }
void EmbIsrINT2::EOI() { outport(0xff22,0x000E); }
void EmbIsrINT2::IsrXX() {}
void EmbIsrINT3::Init() 
{ 
//port	EmbIsr::InitIRQ(0x0F); 
	outport(i3con,0x0015);        // управления (разрешения) прерываниями
	unsigned c=inport(imask);     // Маска перываний - чтение ()
	outport(imask,c&0xff7f);			// Ввод маски прерываний ()
}
void EmbIsrINT3::EOI() { outport(0xff22,0x000F); }
void EmbIsrINT3::IsrXX() {}
void EmbIsrINT4::Init() 
{ 
 //port	EmbIsr::InitIRQ(0x10); 
	outport(i4con,0x0015);        // управления (разрешения) прерываниями
	unsigned c=inport(imask);     // Маска перываний - чтение ()
	outport(imask,c&0xfeff);			// Ввод маски прерываний ()
}
void EmbIsrINT4::EOI() 
{ 
	outport(0xff22,0x0010); 
}
void EmbIsrINT4::IsrXX() 
{
	EOI();
}
port */
#ifdef IncEmbSerialACT8

void EmbSerialACT8Receive::IsrXX()
{
	m_RBuff.Add(inportb(0x602)); 
//port  EOI();
}

void EmbSerialACT8Receive::ReceiveInit()
{
//port  EmbIsrINT0::Init();
}

void EmbSerialACT8Send::IsrXX()
{
  if(m_TBuff.Used()) outportb(0x602,m_TBuff.Get());
	else 
	{
//port   	outport(i1con,0x0018);        // управления (разрешения) прерываниями
//		unsigned c=inport(imask);
//		outport(imask,c|0x0020);
	}
//port	EmbIsrINT1::EOI();
}

void EmbSerialACT8Send::Init() 
{ 
 //port	EmbIsrINT1::Init(); 
	m_TBuff.Init();
} 

void EmbSerialACT8Send::Add(unsigned char byte) 
{ 
	m_TBuff.Add(byte); 
 //port	outport(i1con,0x0015);        // управления (разрешения) прерываниями
}

void EmbSerialACT8Send::TransInit() 
{ 
 //port	outport(i1con,0x0015);        // управления (разрешения) прерываниями
}

void EmbSerialACT8Control::IsrXX()
{
  busy = 0;
//port	EOI();
}

#endif

#ifdef IncEmbSerialMD34

void EmbSerialMD34::IsrXX() 
{
//	UnEmbSerialMD34Status status;
	UnEmbSerialMD34IRQ irq,mask;
//	asm { cli } 

	irq.byte  = inportb(0x515);
	mask.byte = inportb(0x516);
//	status.byte = inportb(0x514);
	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x517)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x519)); 

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x517,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x519,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;
	outportb(0x516,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
//	count++;
	EmbIsrINT3::EOI();
//	asm { sti } 
}


void EmbSerialMD34::Init() 
{ 
	count=0;
	EmbIsrINT3::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	UnEmbSerialMD34IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	outportb(0x516,mask.byte);
} 

void EmbSerialMD34::AddMod(unsigned char byte)
{ 
//my_int_disable_irq0();
	m_TBuffMod.Add(byte); 	
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x516);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x516,mask.byte);
//my_int_enable_irq0();
}
void EmbSerialMD34::AddTransit(unsigned char byte)
{	
//my_int_disable_irq0();
	m_TBuffTransit.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x516);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x516,mask.byte);
//my_int_enable_irq0();
}

#endif

#ifdef IncEmbSerialMD2

void EmbSerialMD2::IsrXX() 
{
//	UnEmbSerialMD2Status status;
	UnEmbSerialMD2IRQ irq,mask;

//	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x5A5);
	mask.byte = inportb(0x5A6);

	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x5A7)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x5A9)); 

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x5A7,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x5A9,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;

	outportb(0x5A6,mask.byte);

	count++;
  //	EmbIsrINT1::EOI();
}


void EmbSerialMD2::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	outportb(0x5A6,mask.byte);
} 

void EmbSerialMD2::AddMod(unsigned char byte)
{ 
//	asm { cli }
//my_int_disable_irq0();
	m_TBuffMod.Add(byte); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x5A6,mask.byte);
//	asm { sti }
}
void EmbSerialMD2::AddTransit(unsigned char byte)
{ 
//	asm { cli }
//my_int_disable_irq0();
	m_TBuffTransit.Add(byte); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x5A6,mask.byte);
//my_int_enable_irq0();
//	asm { sti }
}

#endif

#ifdef IncEmbSerialPU_M
extern unsigned long tmc, ttzc;
void EmbSerialPU_M::IsrXX() 
{
 //		asm { cli } 
//	UnEmbSerialPU_MStatus status;
	UnEmbSerialPU_MIRQ irq,mask;
	   
//	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x505);
	mask.byte = inportb(0x506);
//#ifdef TEST_PUM
//  printfpd("\n\r 4: %02x", status.byte);
//   printfpd("\n\r 5: %02x", irq.byte);
//    printfpd(" 6: %02x", mask.byte);
//	OperateBuffers_usart1t();

//#endif



	if(irq.bit.IRQ_TX_mod) 
	if(m_TBuffMod.Used())
	 { 
	 outportb(0x507,m_TBuffMod.Get());
//	  tmc++;
	 if(!m_TBuffMod.Used()) 
	   mask.bit.IRQ_TX_mod=0; 
	 }
	  else mask.bit.IRQ_TX_mod=0;
	//  else mask.bit.IRQ_TX_mod=1;

	if(irq.bit.IRQ_TX_trans)
	 if(m_TBuffTransit.Used()) 
	 { 
	 outportb(0x509,m_TBuffTransit.Get());
  //	 ttzc++;
	 	if(!m_TBuffTransit.Used()) 
	 	mask.bit.IRQ_TX_trans=0; 
	 } 
	 	else mask.bit.IRQ_TX_trans=0;

	if(irq.bit.IRQ_TX_UD1)
	 if(m_TBuffUD1.Used())
	  { 
	  outportb(0x50B,m_TBuffUD1.Get());
	  	if(!m_TBuffUD1.Used())
	  	 mask.bit.IRQ_TX_UD1=0;
	   }
	  	   else mask.bit.IRQ_TX_UD1=0;

if(irq.bit.IRQ_TX_UD2)
	 if(m_TBuffUD2.Used())
	  { 
	  outportb(0x50D,m_TBuffUD2.Get());
	  	if(!m_TBuffUD2.Used())
	  	 mask.bit.IRQ_TX_UD2=0;
	   }
	  	   else mask.bit.IRQ_TX_UD2=0;







//	if(irq.bit.IRQ_TX_UD2) if(m_TBuffUD2.Used()) { outportb(0x50D,m_TBuffUD2.Get());	if(!m_TBuffUD2.Used()) mask.bit.IRQ_TX_UD2=0; } else mask.bit.IRQ_TX_UD2=0;

	if(irq.bit.IRQ_RX_mod)
	{
	 m_RBuffMod.Add(inportb(0x507)); 
   //	  inportb(0x507);//110304	test
	  }
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x509)); 
	if(irq.bit.IRQ_RX_UD1) m_RBuffUD1.Add(inportb(0x50B)); 
	if(irq.bit.IRQ_RX_UD2) m_RBuffUD2.Add(inportb(0x50D)); 	   //090413

	outportb(0x506,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
	count++;
 //my	EmbIsrINT1::EOI();
// EmbIsrINT0::EOI();
//	asm { sti } 
}


void EmbSerialPU_M::Init() 
{ 
  //	asm { cli } 
	count=0;
	Empty(); 
	EmbIsrINT1::Init(); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	mask.bit.IRQ_RX_UD1=1;
	mask.bit.IRQ_RX_UD2=1;
  	outportb(0x506,mask.byte);

  //	count=0;
  //	EmbIsrINT1::Init(); 
//	m_RBuffMod.Init(); 
//	m_TBuffMod.Init(); 
//	m_RBuffTransit.Init(); 
 //	m_TBuffTransit.Init(); 
   //	m_RBuffPower.Init(); 
  //	m_TBuffPower.Init(); 
  //	UnEmbSerialACT155IRQ mask;
 //	mask.byte = 0;//inportb(0x5A6);
  //	mask.bit.IRQ_RX_mod=1;
  //	mask.bit.IRQ_RX_trans=1;
//	mask.bit.IRQ_RX_power=1;
   //	outportb(0x5A6,mask.byte);


  //	asm { sti } 
} 


void EmbSerialPU_M::AddMod(unsigned char byte)
{ 
//printfpd("M:%d", byte);
//#ifdef TEST_PUM
//  printfpd("\n\r 4: %02x", status.byte);
 //  printfpd("\n\r add m: %02x", byte);
 // 	OperateBuffers_usart1t();

//#endif

//my_int_disable_irq0();
	m_TBuffMod.Add(byte); 	
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();
}
void EmbSerialPU_M::AddTransit(unsigned char byte)
{ 
//#ifdef TEST_PUM
//  printfpd("\n\r 4: %02x", status.byte);
//   printfpd("\n\r add m: %02x", byte);
 //  	OperateBuffers_usart1t();

//#endif

//printfpd("T:%d", byte);
//my_int_disable_irq0();
	m_TBuffTransit.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();
}

void EmbSerialPU_M::AddUD1(unsigned char byte)
{
//printfpd("1:%d", byte); 
//my_int_disable_irq0();
	m_TBuffUD1.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_UD1 = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();
}

void EmbSerialPU_M::AddUD2(unsigned char byte)
{ 
//printfpd("2:%d", byte);
//my_int_disable_irq0();
	m_TBuffUD2.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_UD2 = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();
}

#endif

#ifdef IncEmbSerialMD34AVT

void EmbSerialMD34AVT::IsrXX() 
{
//	UnEmbSerialMD34Status status;
	UnEmbSerialMD34IRQ irq,mask;
//	asm { cli } 
	irq.byte  = inportb(0x505);
	mask.byte = inportb(0x506);

//	status.byte = inportb(0x514);
	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x507)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x509)); 
	#ifdef PROG_BMD34PS
	if(irq.bit.IRQ_RX_power) m_RBuffPower.Add(inportb(0x50B)); 
	#endif //PROG_BMD34PS
	#ifdef PROG_BMD155PS
	if(irq.bit.IRQ_RX_power) m_RBuffPower.Add(inportb(0x50B)); 
	#endif //PROG_BMD155PS
	#ifdef PROG_PRM_PCH
	if(irq.bit.IRQ_RX_power) m_RBuffPower.Add(inportb(0x50B)); 
	#endif //PROG_PRM_PCH



	if(irq.bit.IRQ_TX_mod)
	 if(m_TBuffMod.Used())
	  { 
	 outportb(0x507,m_TBuffMod.Get());
	 if(!m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0;
	   }
	 else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans)
	if(m_TBuffTransit.Used())
	 { 
	 outportb(0x509,m_TBuffTransit.Get());
	  if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0;
	   }
	    else mask.bit.IRQ_TX_trans=0;
  
	#ifdef PROG_BMD34PS
		if(irq.bit.IRQ_TX_power)
	 if(m_TBuffPower.Used())
	  {
	  outportb(0x50B,m_TBuffPower.Get());
	 if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_power=0;
	  }
	   else mask.bit.IRQ_TX_power=0;
	#endif //PROG_BMD34PS
	#ifdef PROG_BMD155PS
		if(irq.bit.IRQ_TX_power)
	 if(m_TBuffPower.Used())
	  {
	   outportb(0x50B,m_TBuffPower.Get());
	 if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_power=0;
	  }
	   else mask.bit.IRQ_TX_power=0;
	#endif //PROG_BMD155PS
	 #ifdef PROG_PRM_PCH
		if(irq.bit.IRQ_TX_power)
	 if(m_TBuffPower.Used())
	  {
	   outportb(0x50B,m_TBuffPower.Get());
	 if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_power=0;
	  }
	   else mask.bit.IRQ_TX_power=0;
	#endif //PROG_BMD155PS





  outportb(0x506,mask.byte);

////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
//	count++;
   //	EmbIsrINT1::EOI();
//	asm { sti } 
}


void EmbSerialMD34AVT::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	UnEmbSerialMD34IRQ mask;
	mask.byte = 0;//inportb(0x5A6);

#ifdef PROG_BMD34PS
	m_RBuffPower.Init(); 
	m_TBuffPower.Init();
	mask.bit.IRQ_RX_power=1;

#endif //PROG_BMD34PS
#ifdef PROG_BMD155PS
	m_RBuffPower.Init(); 
	m_TBuffPower.Init();
	mask.bit.IRQ_RX_power=1;

#endif //PROG_BMD155PS

#ifdef PROG_PRM_PCH
	m_RBuffPower.Init(); 
	m_TBuffPower.Init();
	mask.bit.IRQ_RX_power=1;

#endif //PROG_PRM_PCH



   	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	outportb(0x506,mask.byte);
} 

void EmbSerialMD34AVT::AddMod(unsigned char byte)
{ 
//my_int_disable_irq0();
	m_TBuffMod.Add(byte); 	
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();

}
void EmbSerialMD34AVT::AddTransit(unsigned char byte)
{
//my_int_disable_irq0();
	
	m_TBuffTransit.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x506,mask.byte);
//my_int_enable_irq0();
}

#ifdef PROG_BMD34PS

void EmbSerialMD34AVT::AddPower(unsigned char byte)
{	
	m_TBuffPower.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x506,mask.byte);
}

#endif //PROG_BMD34PS
#ifdef PROG_BMD155PS

void EmbSerialMD34AVT::AddPower(unsigned char byte)
{	
	m_TBuffPower.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x506,mask.byte);
}

#endif //PROG_BMD155PS

#ifdef PROG_PRM_PCH

void EmbSerialMD34AVT::AddPower(unsigned char byte)
{	
	m_TBuffPower.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x506,mask.byte);
}

#endif //PROG_PRM_PCH


//___________________________________________________________________________PROV

#ifdef PROG_BMDN2

extern unsigned char irq_byte, irqm_byte;

void EmbSerialMD34AVTProv::IsrXX() 
{
//   static unsigned long isrxx_counter;

//isrxx_counter++;
//	UnEmbSerialMD34Status status;
  //	unsigned char status_transit;
 	UnEmbSerialMD34IRQProv irq;//,mask;
 	UnEmbSerialMD34IRQProvMod irqm;//,maskm;
	unsigned char byte;
    unsigned long i = 0;

//LedOn();
//	asm { cli } 
  //	irq.byte  = inportb(PROV_IRQ_ADDR);
  //	irq.byte  = inportb(PROV_IRQ_ADDR);

 //not need!! 	mask.byte = inportb(PROV_MASK_ADDR);
 //not need!!	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
//    if(irq.byte)
//	{
 //	 i++;
 //	 i--;
//	}
  //	irqm.byte = inportb((i+1)*STEP_ADDR + PROV_IRQ_ADDR_MOD);
   //	irqm.byte = inportb((i+1)*STEP_ADDR + PROV_IRQ_ADDR_MOD);
//status_transit = inportb(PROV_TANZIT_STATUS);
// outportb(PROV_TANZIT_STATUS, 0);
//status_transit = inportb(PROV_TANZIT_STATUS);

  irq.byte  = inportb(PROV_IRQ_ADDR);
//    irq_byte = irq.byte;
 //	 i++;
  //	 i--;


//   unsigned long i = 0;
//printfp("\n\r");
//printfpd(" %ld",isrxx_counter);

	 //	if(GetTestMode() == 0x50)
	  //		{

	  //		    printfp("i");
	  //		 }

if(irq.bit.IRQ_TX_trans)
	{
	if(m_TBuffTransit.Used())
	 { 
	    txtrans++;
		outportb(PROV_DATA_TANZIT,m_TBuffTransit.Get());
	  if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0;
	   }
	else mask.bit.IRQ_TX_trans=0;
	}

if(irq.bit.IRQ_RX_trans)
	{
	rxtrans++;
 	byte = 	inportb(PROV_DATA_TANZIT);
 //	 m_RBuffTransit.Add(inportb(PROV_DATA_TANZIT)); 
	m_RBuffTransit.Add(byte); 
	 }



 //	status_transit = inportb(PROV_TANZIT_STATUS);  //for property working
  	if(irq.bit.IRQ_mod)
	{
	  irqm.byte = inportb((i+1)*STEP_ADDR + PROV_IRQ_ADDR_MOD);
  //	  irqm_byte = irqm.byte; 
   

	//	for(long i = 0; i < MODEM_QUANTITY; i++)
	//	{
   //		 if(ModemIsUsed(i))	 //110208
	//	 {	   //110208
	//	   maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	 //	   irqm.byte = inportb((i+1)*STEP_ADDR + PROV_IRQ_ADDR_MOD);

			if(irqm.bit.IRQ_RX_mod)
			{
			rxmod++;
			 byte = inportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_MOD);
 
//#ifdef USART0_TRY_PDC_1T
//   printfp("\n\rIsrXX - receive");
//   printfp("byte:");
//   printfpd(" %X", byte);
//   printfp(" i:");
//   printfpd(" %d",i);
//   printfp(" time1:");
//   printfpd(" %ld", time1);
//#endif
  
		 //	  m_RBuffMod[i].Add(inportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_MOD));
			  m_RBuffMod[i].Add(byte);
			}
#ifdef PROG_BMDN4

	if(irqm.bit.IRQ_RX_UD1)
			{
			 byte = inportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_UD1);
			  m_RBuffUD1[i].Add(byte);
	  //				if(GetTestMode() == 0x50)
	  //		{

	  //		    printfp("r");
	  //		 }
			}

	if(irqm.bit.IRQ_RX_UD2)
			{
			 byte = inportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_UD2);
			  m_RBuffUD2[i].Add(byte);
			}

#endif
//____________________________________________
			if(irqm.bit.IRQ_TX_mod)
			{
	 		if(m_TBuffMod[i].Used())
	  		{ 
			  txmod++;
		      byte = m_TBuffMod[i].Get(); 
		   
	    		outportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_MOD,byte);

 				if(!m_TBuffMod[i].Used()) maskm.bit.IRQ_TX_mod=0;  //where it is init?????
  //()) maskm.bit.IRQ_TX_mod=0;  //where it is init?????
  //HANNELS_RATE_LIMIT)) maskm.bit.IRQ_TX_mod=0;  //where it is init?????
	  		}
	 		else maskm.bit.IRQ_TX_mod=0;
			}
//____________________________________________________________________________  
//____________________________________________
#ifdef PROG_BMDN4

			if(irqm.bit.IRQ_TX_UD1)
			{
 	 		if(m_TBuffUD1[i].Used())
	  		{ 
		      byte = m_TBuffUD1[i].Get(); 
		 //	if(GetTestMode() == 0x50)
		  //	{
		  //	     printfpd("-%02x", byte);
		  //	}


	    		outportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_UD1,byte);

   				if(!m_TBuffUD1[i].Used()) maskm.bit.IRQ_TX_UD1=0;  //where it is init?????
  	//			if((!m_TBuffUD1[i].Used()) || (transit_bytes_counter > CHANNELS_RATE_LIMIT))  maskm.bit.IRQ_TX_UD1=0;  //where it is init?????
	  		}
	 		else maskm.bit.IRQ_TX_UD1=0;
			 }

		  if(irqm.bit.IRQ_TX_UD2)
			{
			if(m_TBuffUD2[i].Used())
	  		{ 
		      byte = m_TBuffUD2[i].Get(); 

	    		outportb((i+1)*STEP_ADDR + PROV_DDC_DATA_ADDR_UD2,byte);

				if(!m_TBuffUD2[i].Used()) maskm.bit.IRQ_TX_UD2=0;  //where it is init?????
	  		}
	 		else maskm.bit.IRQ_TX_UD2=0;
			}
#endif

 // }   //110208
//____________________________________________________________________________  
  
 outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
 }

 outportb(PROV_MASK_ADDR,mask.byte);
}


void EmbSerialMD34AVTProv::Init() 
{ 
  //	UnEmbSerialMD34IRQProv mask;
  //	UnEmbSerialMD34IRQProvMod maskm;
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_trans=1;
	mask.bit.IRQ_mod=1;
	unsigned long i = 0;

	outportb(PROV_MASK_ADDR,mask.byte);	//hier need add writing mask to every modem

  //  for(long i = 0; i < MODEM_QUANTITY; i++)
  //	{
		Initi(i);

		/*
		maskm.byte = 0;
		m_RBuffMod[i].Init(); 
		m_TBuffMod[i].Init(); 
   		maskm.bit.IRQ_RX_mod=1;
		outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
		*/
   //	}

 //	UnEmbSerialMD34IRQ mask; //need change type and add for modem
 //	mask.byte = 0;//inportb(0x5A6);
//   	mask.bit.IRQ_RX_mod=1;
 //	mask.bit.IRQ_RX_trans=1;
 //	outportb(0x506,mask.byte);	//hier need add writing mask to every modem
} 

void EmbSerialMD34AVTProv::Initi(unsigned char i) 
{ 
//ok return;

 //	UnEmbSerialMD34IRQProv mask;
  //	UnEmbSerialMD34IRQProvMod maskm;
	count=0;
 //	unsigned long i = 0;
/*
#ifdef USART0_TRY_PDC_1T
   printfp("\n\r Initi");
   printfp(" i:");
   printfpd(" %d",i);
   printfp(" time1:");
   printfpd(" %ld", time1);
#endif
*/

  //	EmbIsrINT1::Init(); 
  //	m_RBuffTransit.Init(); 
  //	m_TBuffTransit.Init(); 
  //	mask.byte = 0;//inportb(0x5A6);
 //	mask.bit.IRQ_RX_trans=1;
 //	mask.bit.IRQ_mod=1;

 //	outportb(PROV_MASK_ADDR,mask.byte);	//hier need add writing mask to every modem

 //   for(long i = 0; i < MODEM_QUANTITY; i++)
  //	{
		maskm.byte = 0;
		m_RBuffMod[i].Init(); 
		m_TBuffMod[i].Init(); 
   		maskm.bit.IRQ_RX_mod=1;

// ok return;
#ifdef PROG_BMDN4
		m_RBuffUD1[i].Init();
		m_TBuffUD1[i].Init();
		m_RBuffUD2[i].Init();
		m_TBuffUD2[i].Init();
	    maskm.bit.IRQ_RX_UD1=1;
	    maskm.bit.IRQ_RX_UD2=1;

#endif
//ok return;
		outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);	  //hier hangt
  //	}

 //	UnEmbSerialMD34IRQ mask; //need change type and add for modem
 //	mask.byte = 0;//inportb(0x5A6);
//   	mask.bit.IRQ_RX_mod=1;
 //	mask.bit.IRQ_RX_trans=1;
 //	outportb(0x506,mask.byte);	//hier need add writing mask to every modem
} 


void EmbSerialMD34AVTProv::AddMod(unsigned char byte, unsigned long i)
{ 
	if(i >= MODEM_QUANTITY) return;
	modem_bytes_counter++;
    m_TBuffMod[i].Add(byte); 	
	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_mod = 1;
	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
//my_int_enable_irq0();

}

void EmbSerialMD34AVTProv::AddModM(unsigned char byte, unsigned long i)
{ 
	if(i >= MODEM_QUANTITY) return;
	modem_bytes_counter++;
    m_TBuffMod[i].Add(byte); 	
	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_mod = 1;
	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
//my_int_enable_irq0();

}





void EmbSerialMD34AVTProv::AddTransit(unsigned char byte)
{
//my_int_disable_irq0();
    transit_bytes_counter++;
	m_TBuffTransit.Add(byte);  
 //	UnEmbSerialMD34IRQProv mask;
  	mask.byte = inportb(PROV_MASK_ADDR);
  	mask.bit.IRQ_TX_trans = 1;
  	outportb(PROV_MASK_ADDR,mask.byte);
//my_int_enable_irq0();
}

void EmbSerialMD34AVTProv::AddTransitM(unsigned char byte)
{
//my_int_disable_irq0();
    transit_bytes_counter++;
	m_TBuffTransit.Add(byte);  
 //	UnEmbSerialMD34IRQProv mask;
	mask.byte = inportb(PROV_MASK_ADDR);
	D34IRQProv mask;
	mask.byte = inportb(PROV_MASK_ADDR);
	byte);
//my_int_enable_irq0();
}


#ifdef PROG_BMDN4
 
void EmbSerialMD34AVTProv::AddUD1(unsigned char byte, unsigned long i)
{
	m_TBuffUD1[i].Add(byte); 
	UnEmbSerialMD34IRQProvMod maskm;
	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_UD1 = 1;
  	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
}

void EmbSerialMD34AVTProv::AddUD1M(unsigned char byte, unsigned long i)
{
	m_TBuffUD1[i].Add(byte); 
	UnEmbSerialMD34IRQProvMod maskm;
	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_UD1 = 1;
  	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
}


void EmbSerialMD34AVTProv::AddUD2(unsigned char byte, unsigned long i)
{ 
	m_TBuffUD2[i].Add(byte); 
	UnEmbSerialMD34IRQProvMod maskm;
 	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_UD2 = 1;
  	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
}

void EmbSerialMD34AVTProv::AddUD2M(unsigned char byte, unsigned long i)
{ 
	m_TBuffUD2[i].Add(byte); 
	UnEmbSerialMD34IRQProvMod maskm;
 	maskm.byte = inportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD);
	maskm.bit.IRQ_TX_UD2 = 1;
  	outportb((i+1)*STEP_ADDR + PROV_MASK_ADDR_MOD,maskm.byte);
	mask.bit.IRQ_mod = 1;
	outportb(PROV_MASK_ADDR,mask.byte);
}

   
#endif


#endif //#ifdef PROG_BMDN2


//___________________________________________________________________________PROV

#endif// IncEmbSerialMD34AVT

#ifndef PROG_MF20
#ifndef PROG_TUTS

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
  int n = Head - Tail;
//  signed short int n = Head - Tail;	//t

 //printf(" h:%d t:%d ",Head, Tail);

  if( n >= 0 ) return (unsigned)n;
  else return (unsigned)(n+BuffSize);
}

template<class T,int Size> unsigned TRBuffer<T,Size>::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}

#endif // no PROG_TUTS
#endif // no PROG_MF20
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RDN_Receive
* Returned Value   : none
* Comments         :
*    	add packet to buffer
*END*----------------------------------------------------------------------*/

//extern "C" void RDN_receive(char * pData, char * src) 

//extern	EmbMsg embMsgWestE;
extern "C" void embMsgWestE_Init(void);

extern "C" void embMsgWestE_Add( char *);


extern "C" void RDN_receive(char * pData) 
{
// return; //for test 091210

 // pRDN_BufferR = RDN_BufferR;
 unsigned long len;
 char type; //new 0 - 485; 1 - 232
 //printf("\n\r>");
 //t my_int_disable();

// _int_disable();	//t090807

  len = (unsigned long)*pData++;
 len <<= 8;
 len +=  (unsigned long)*pData++;
 type =  *pData++; //new
// printf("\n\r %X", type);
	 if(len >=  RDN_BUFFER_SIZE) 
	 {
	 len = 	RDN_BUFFER_SIZE;
	 }
 //t for(long i = 0; i < RDN_BUFFER_SIZE; i++)	//now all packet
  if(type == ETH_485)
  {
 //  send485_enabled = 1;

 //  printEthLongHex(0x1234);
 for(long i = 0; i < len; i++)	//now all packet
   {
 	//  embRS485.rcvbuf.Add((unsigned char)RDN_BufferR.Get());
   //	   RDN_BufferR.Add(*pData++);
//t1103      RDN_BufferR.Add(*pData);	//temporery
//______________________________________________test
/* 120831 this not need now
 if(TestMode.Value == 4)
 {
  TrzBuff485.Add((char)*pData);
 }
 */
//_______________________________________________test
 	  embRS485.rcvbufE.Add((unsigned char)*pData++);

  }
 }
 else  if(type == ETH_232) //02
 {

	  for(long t = 0; t < 6; t++)	 //hostmac
 {
 	embRS232.HostMAC[t] =  *pData++;
 //	embRS232.HostMAC[t] =  0xff; //	t1226
 //	 *pData++;	  //t1226
 }
 
    for(long i = 0; i < len; i++)	//now all packet
  {
 //______________________________________________test
  if(TestMode.Value == 4)
   {
     TrzBuff232.Add((char)*pData);
   }
//_______________________________________________test
 	  embRS232.rcvbufE.Add((unsigned char)*pData++);
  }
 }
 else  if(type == ETH_DIR)
 {
	  for(long t = 0; t < 6; t++)	 //hostmac
 {
  // printf(".%02X", pData++);
 //dirRS232.rcvbufE.Add((unsigned char)*src++);  //t
//  src++;
  //  dirRS232.rcvbufE.Add((unsigned char)*pData++);
	dirRS232.HostMAC[t] =  *pData++;

  //    pData++;

	
 }




    for(long i = 0; i < len; i++)	//now all packet
  {
 //______________________________________________test
  if(TestMode.Value == 4)
   {
     TrzBuff232.Add((char)*pData);
   }
//_______________________________________________test
   	  dirRS232.rcvbufE.Add((unsigned char)*pData++);   //if comment all ok
	  //  dirRS232.rcvbufE.Add((unsigned char)0x55);	  //t
  }
 }
#ifdef ETH_TRANZIT
  else  if(type == ETH_TRZ)
  {
 //  printEthLongHex(0x1234);
  //	InitEthTranzitMsg();
//	embMsgWestE_Init();
 for(long i = 0; i < len; i++)	//now all packet
   {
  // 		embMsgWestE_Add(pData);
  // 		AddEthTranzit(pData++);
    trnzRS232.rcvbufE.Add((unsigned char)*pData++);
   }
//  AddEthTranzitBuffers();
   }
#endif // ETH_TRANZIT

 // _int_enable();  //t090807
 //t  my_int_enable();
}




/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RDN_BufferR_Init
* Returned Value   : none
* Comments         :
*    
*END*----------------------------------------------------------------------*/

//extern "C" void RDN_BufferR_Init(void)	// 
// {
//  RDN_BufferR.Init();
// }
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :UseDirRS232
* Returned Value   : none
* Comments         : Parse buffer of direct 232 from ethernet
*    
*END*----------------------------------------------------------------------*/
void UseDirRS232()
{
char byte;

 while(dirRS232.UsedReceiveE())
 {
 	byte = dirRS232.ReceiveE();
 //	printf("%c", byte);
 //	printf(".%02X", byte);
	dir_eth_232( byte);
 }
}
#ifdef ETH_TRANZIT
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :UseTrnzRS232
* Returned Value   : none
* Comments         : Parse buffer of direct 232 from ethernet
*    
*END*----------------------------------------------------------------------*/
void UseTranzRS232()
{
char byte;

 while(trnzRS232.UsedReceiveE())
 {
 	byte = trnzRS232.ReceiveE();
 //	printf("%c", byte);
 //	printf(".%02X", byte);
 //	dir_eth_232( byte);
//<<<<<<<<<<<<<<<<<<<<<hier need add parse and answer to requests
//____________________________________________________________--
 }
}
#endif //ETH_TRANZIT


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :TransmitE
* Returned Value   :none
* Comments         :
*    transmit data for usart0 
*END*----------------------------------------------------------------------*/
 
void TransmitE()
{
			pTBuff3 = &TBuff3[0];
	  //		printfp(pTBuff3); //for test
			do
			{
		 //	SendChar(pTBuff);
    //     fputc(*pTBuff0, fusart0_ptr); 
		    dirRS232.TransE(*pTBuff3);
			}
			while(*pTBuff3++);
		  //	dirRS232.Trans_RDN_Brdcst();
		 //	dirRS232.Trans_RDN(COMP_DEF_MAC_END);
		   dirRS232.Trans_RDN_Full(dirRS232.COMP_DEF_MAC_END);
		   dirRS232.Trans_RDN_Full(dirRS232.= &TBuff0[0];  //set pointer to start of buffer!
}

#ifdef PULT_USART
//TRBuffer<unsigned char,ACT_BUFFER_SIZE> KeyBuffer;

char KBuff[KEY_BUFFER_SIZE];
char *pKBuff;

void AddKeyBuffer(unsigned char c)
{
unsigned long tmp2 = (unsigned long) pKBuff;
unsigned long tmp3 = (unsigned long) KBuff;
  if((tmp2 - tmp3) <= KEY_BUFFER_SIZE)
	 {
	  *pKBuff++ = c;
 	 }
	 else
	 {
	  InitKeyBuffer();
      *pKBuff++ = c;
	 }


//  KeyBuffer.Add(c);

}

void InitKeyBuffer()
{		         							  
 // KeyBuffer.Init();
  pKBuff = KBuff;
}

unsigned char GetKeyBuffer()
{
char tmp;
unsigned long tmp2 = (unsigned long) pKBuff;
unsigned long tmp3 = (unsigned long) KBuff;

 if(tmp2 > tmp3)
	 {
      pKBuff--;
 	  tmp = *pKBuff;
//	  printEthLongHex(tmp);
	  return tmp;
	 }

 /*
  if(KeyBuffer.Used())
  {
  //   printEthLongHex(9);
	 tmp = 	KeyBuffer.Get();
  // 	 printEthLongHex(tmp);
   //    return  KeyBuffer.Get();
     return  tmp;
  }
  */
   
  return 0;
}


#endif //PULT_USART


//void ParseMsg(EmbMsg * cur_msg)


	

#ifdef ETH_TRANZIT

  char tbuffWestE[RDN_BUFFER_SIZE];
	          unsigned long cur_WestE;
			  char tbuffEastE[RDN_BUFFER_SIZE];
	          unsigned long cur_EastE;
			   char tbuffAnsE[RDN_BUFFER_SIZE];
	          unsigned long cur_AnsE;




char old_embMsgWest_number;
char old_embMsgEast_number;
unsigned long old_embMsgWest_addrs;
unsigned long old_embMsgWest_addri;
unsigned long old_embMsgEast_addrs;
unsigned long old_embMsgEast_addri;


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
 #ifdef ALL_ADDR
// printf("a>%ld ",counter_msend++ );
 #endif //ALL_ADDR
  RDN_Start_Transmit(tbuffAnsE, netdest);

//_____________090518  RDN_Start_Transmit(tbuffAnsE, netdest);

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

extern  EmbRS232 trnzRS232;
//unsigned long cnt_req, cnt_ans, cnt_esn, cnt_erc; //, EthSendTimer; //, EthAnsTimer;
//unsigned long  EthSendTimer;
unsigned long  EthReceiveTimer;
unsigned long  EthReceiveDelay;
unsigned char ethByte;
unsigned char  mode5AWestE, mode5AEastE, recieveWestE, recieveEastE;




 

#endif // ETH_TRANZIT





