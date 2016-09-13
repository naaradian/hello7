//file prm_pch_n_1.cpp
#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include <mqx.h>
#include <bsp.h>
//____________________________________________________
#include <log.h>
#include <klog.h>
#include <rtcs.h>
#include <enet.h>
#include "hello7.h"
#include "io_prv.h"


//____________________________________________________


#include "spi_pol.h"
#include "spi_polpv.h"
#include <dataflash.h>
#include "psp_prv.h"

 //led2 - rs485
 //led3 - kirill
 //led1 -power on

//#define CORR_MASK (0x7F) 

#define LED2TIMER  (10)
#define LED3TIMER  (10)
unsigned long led2timer;
unsigned long led3timer;

#define LEN_DATA_DDS (3)
#define SPI_WAIT	  (1)
#define SPI_NO_WAIT	  (0)

extern "C" void LoadDDSN2()
{
unsigned char * pData;
static unsigned char DataDDS[LEN_DATA_DDS];//

// 0,  0, 0x88
//  00;  01H, 00H  
//  00;  02H, 02H  
//  00;  03H, 19H  
//  00;  04H, 00H  
//  00;  05H, 00H  


//0,  0, 0x88

pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x88;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  01H, 00H 

pData = DataDDS;
*pData++ = 0;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  02H, 02H    

pData = DataDDS;
*pData++ = 0;   *pData++ = 2;	 *pData = 2;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);


//  00;  03H, 19H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 3;	 *pData = 0x19;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00;  04H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00;  05H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  10H,0D0H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x10;	 *pData = 0xD0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  12H, 00H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x12;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
 
//  00H,  13H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x13;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  20H, 12H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x12;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  22H, 04H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x22;	 *pData = 4;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  04H, 00H 
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  01H,  05H, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  06H, 01H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 6;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0A6H, 63H         ;;;189,22 MHZ      
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA6;	 *pData = 0x63;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                  
//  01H, 0A7H, 0CBH              ;;     
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA7;	 *pData = 0xCB;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                        
//  01H, 0A8H, 3CH    
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA8;	 *pData = 0x3C;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                          
//  01H, 0A9H, 03H  
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA9;	 *pData = 3;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                            
//  01H, 0AAH, 34H   
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAA;	 *pData = 0x34;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                           
//  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAB;	 *pData = 0x45;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ACH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAC;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ADH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAD;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  00H, 05H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 0;	 *pData = 5;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  01H, 00H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0BH,0FFH  

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xB;	 *pData = 0xFF;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0CH, 01H 

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xC;	 *pData = 3;  //max I
//*pData++ = 4;   *pData++ = 0xC;	 *pData = 1;  //max I
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

  
   
//  04H,  0EH, 10H 
  
pData = DataDDS;
*pData++ = 4;   *pData++ = 0xE;	 *pData = 0x10;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  00H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 0;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  01H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  02H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 2;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  03H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 3;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  04H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  05H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  06H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 6;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  07H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 7;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  08H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 8;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  09H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 9;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);




//test ok *pData++ = 0x55;   *pData++ = 0xAA;	 *pData = 0x99;

// = 
//{
/*
  0,  0, 0x88
  00;  01H, 00H  
  00;  02H, 02H  
  00;  03H, 19H  
  00;  04H, 00H  
  00;  05H, 00H  
  00H,  10H,0D0H  
  00H,  12H, 00H  
  00H,  13H, 00H  
  00H,  20H, 12H  
  00H,  22H, 04H  
  01H,  04H, 00H  
  01H,  05H, 00H  
  01H,  06H, 01H  
  01H, 0A6H, 63H         ;;;189,22 MHZ                                      
  01H, 0A7H, 0CBH              ;;                                           
  01H, 0A8H, 3CH                                                            
  01H, 0A9H, 03H                                                            
  01H, 0AAH, 34H                                                            
  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 
  00H,  05H, 01H  
  01H, 0ACH, 00H  
  01H, 0ADH, 00H  
  02H,  00H, 05H  
  02H,  01H, 00H  
  04H,  0BH,0FFH  
  04H,  0CH, 01H  
  04H,  0EH, 10H  
  05H,  00H, 00H  
  05H,  01H, 00H  
  05H,  02H, 00H  
  05H,  03H, 00H  
  05H,  04H, 00H  
  05H,  05H, 00H  
  05H,  06H, 00H  
  05H,  07H, 00H  
  05H,  08H, 00H  
  05H,  09H, 00H  
  00H,  05H, 01H  
  */
//};


//test okSendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
}


extern "C" void SetLed2(unsigned char flag)
{
//   printf("\n\rled2 %d  t: %d", flag, led2timer);
//need init	 as io pin in int - funktion!!!!!!!!!!!!!!!!!!!!!
 // static unsigned long led2timer = 0;
//   printf("\n\rled2 %d  t: %d", flag, led2timer);

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   
  if(flag)
  {
 //  if(!led2timer)
   {
      pio_ptr->CODR = MASK_BIT_14; //get off
 	  led2timer = LED2TIMER;
   }
  }
  else
  {
//   if(led2timer == 1)
//  {
      pio_ptr->SODR = MASK_BIT_14;
	  led2timer = 0;
//   }
 //  else
 // {
    if(led2timer)
 	  {
 	  led2timer--;
 	  }
 //  }


  }
   
}

extern "C" void SetLed3(unsigned char flag)
{

//need init	 as io pin in int - funktion!!!!!!!!!!!!!!!!!!!!!

//  static unsigned long led3timer = 0;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   
  if(flag)
  {
   if(!led3timer)
   {
      pio_ptr->CODR = MASK_BIT_15;
 	  led3timer = LED3TIMER;
   }
  }
  else
  {
   if(led3timer == 1)
   {
      pio_ptr->SODR = MASK_BIT_15;
   	  led3timer = 0;
   }
   else
   {
    if(led3timer)
 	{
 	led3timer--;
 	}
   }
 }

}




struct BitField
{
 unsigned b0 : 1;
 unsigned b1 : 1;
 unsigned b2 : 1;
 unsigned b3 : 1;
 unsigned b4 : 1;
 unsigned b5 : 1;
 unsigned b6 : 1;
 unsigned b7 : 1;
};

union UnBitField
{
  BitField bits;
  unsigned char uc;
};

unsigned char EzhinSbazhin(unsigned char u1)
{
	UnBitField ubf1, ubf2;

	ubf1.uc = u1;
	ubf2.bits.b0 = ubf1.bits.b1;
	ubf2.bits.b1 = ubf1.bits.b0;
	ubf2.bits.b2 = ubf1.bits.b3;
	ubf2.bits.b3 = ubf1.bits.b2;
	ubf2.bits.b4 = ubf1.bits.b5;
	ubf2.bits.b5 = ubf1.bits.b4;
	ubf2.bits.b6 = ubf1.bits.b7;
	ubf2.bits.b7 = ubf1.bits.b6;
	return ubf2.uc;
}

extern "C" unsigned char MakeAtt(unsigned char inpval)
{
  unsigned char outval;

  if(inpval>=60) outval = 0xFF;
  if(inpval>=30) outval = 0x0F+(((inpval-30)/2)<<4);
  if(inpval<30) outval = (inpval)/2;

  return EzhinSbazhin(outval);
}


extern "C" void  KeepParam(unsigned long dataparam , unsigned long addrparam)
{
 unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;		  
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
}

struct Emb5StatusReciever
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned char type; // Диапазон РПУ 1..3
	unsigned char status; // см. ниже описание <status>
	unsigned char stepAtt; // Шаг аттенюатора
	unsigned long frequ; // Число соответствующие частоте приема с шагом 100КГц
	unsigned short signalLevel; // уровень сигнала на входе РПУ в dbm
   	unsigned char genStatus; // Состояние статуса генерации 
				  // (0 -выкл, 1- вкл, 2- одиночный запрос)
	unsigned char lock;
	unsigned char stepAtt2; // Шаг аттенюатора2
	unsigned char stepAtt3; // Шаг аттенюатора3

}; // 12 байт

union UnEmb5StatusReciever
{
	Emb5StatusReciever emb5statusreciever; 	 // Код канала РПУ (1..2)	
   //	unsigned char byte[11];
   //	unsigned char byte[12];
	unsigned char byte[14];
};



struct Emb5CommandRecieverSetFrequ
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned long frequ;  // Число соответствующие частоте приема 
				// в количестве шагов сетки 100КГц
  //	unsigned char lock;
};

union UnEmb5CommandRecieverSetFrequ
{
	Emb5CommandRecieverSetFrequ emb5commandrecieversetfrequ;
 	unsigned char byte[5];
 //	unsigned char byte[6]; //added lock
};

	


struct Emb5CommandRecieverSetAtt
{
	unsigned char number; 	 // Код канала РПУ (1..2)	
	unsigned char stepAtt; // установить шаг аттенюатора 
				 //(число шагов уточняется в процессе разработки))
	unsigned char stepAtt2; // Шаг аттенюатора2
	unsigned char stepAtt3; // Шаг аттенюатора3

};

union UnEmb5CommandRecieverSetAtt
{
	Emb5CommandRecieverSetAtt emb5commandrecieversetatt; 	 // Код канала РПУ (1..2)	
 //	unsigned char byte[2];
	unsigned char byte[4];
};



UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ1;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ2;

UnEmb5StatusReciever emb5StatusReciever1;
UnEmb5StatusReciever emb5StatusReciever2;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt1;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt2;

//________________________________________________________________________
struct Emb5CommandRPUSetAtt
{
 	unsigned char number; 	 // Код канала РПУ (1..2)	
	unsigned char stepAtt; // установить шаг аттенюатора 
				 //(число шагов уточняется в процессе разработки))
};

union UnEmb5CommandRPUSetAtt
{
	Emb5CommandRPUSetAtt emb5commandrpusetatt; 	 // 	
	unsigned char byte[2];
};


UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt1;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt2;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt3;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt4;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt5;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt6;


//_______________________________________________________________________________


extern int ecount2;
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
union u2uc
{
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
//___________________________________________________________________________________
struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[270];
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
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }
	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }
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
  int i;
	unsigned c=0, b=0;
 		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
}

unsigned short EmbMsg::CalcCRC()
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

//___________________________________________________________________________________
#ifdef PROG_PRM_PCH_N

#define MAX_LEN	(270)

struct EmbMsgN
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[ MAX_LEN];
	unsigned char STARTN()		{   return body[0]; 			}
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
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }
	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return  MAX_LEN-counter; }
	int short IsEnd();
	int short IsEndOfHeader();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned short ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }
	void SetDir(unsigned char d) { dir= d; } // dir = 1 пришел с West, dir=2 прищел с East
	void Copy(EmbMsg m);
//__________________________________________________________________
	unsigned char ParseN(void);
	void SendAns(void);
	void SetCommandN(unsigned long);
	void RunCommandN1(void);
	void RunCommandN2(unsigned short);
	void RunCommandN3(unsigned char);
	void RunCommandN4(void);
	void RunCommandN5(unsigned char);
	void RunCommandN6(unsigned char);
	void RunCommandN7(unsigned char);
	void RunCommandN8(unsigned char);
	void RunCommandN80(unsigned short, unsigned short,unsigned short,unsigned short,unsigned short);

//	void SetStartAns(void);
//	void SetStopAns(void);
	unsigned long GetAnsLen(void){return current_posa;}
	unsigned char GetAns(unsigned long pos){return ans[pos];}
    void AddToAns(unsigned char);
	void AddToAnsDirect(unsigned char);

	unsigned char ChkCRCN(unsigned long);
//	void SetFreqN(unsigned short);
//	void SetAttN(unsigned char);

	unsigned long current_posr;
	unsigned long current_posw;
	unsigned char parsed_now;
	unsigned char ans[MAX_LEN];
	unsigned long current_posa; //answer
	unsigned char alarm;
 //	unsigned char lock;
//	unsigned char flagatt;
//	unsigned short curFreq;
//	unsigned char curAtt;
//	unsigned char curLev;

//___________________________________________________________________
};
//___________________________________________

#define START_COMMAND	(0xAA)
#define STOP_COMMAND	(0x55)
#define MY_ADDRESS		(0x01) //make in future
#define BRD_ADDRESS		(0xFF) //addr for all
#define MASK_REQUEST	(0x80)
#define	COMM1_LEN		(2)
#define	COMM2_LEN		(2)
#define	COMM3_LEN		(2)
#define	COMM4_LEN		(7)
#define	COMM5_LEN		(2)
#define	COMM6_LEN		(2)
#define	COMM7_LEN		(2)
#define	COMM8_LEN		(2)
#define	COMM80_LEN		(2)

extern "C" void SetFreqN(void);
extern "C" void SetFreqN80(unsigned char, unsigned char,unsigned char,unsigned char,unsigned char);

extern "C" void SetAttN(void);
extern "C" void SetAtt7N(void);
extern "C" void SetAtt8N(void);



unsigned char GetLevN(void);
unsigned char GetAttN(void);
unsigned char GetAtt2N(void);
unsigned char GetAtt3N(void);

unsigned short GetFreqN(void);
unsigned short GetLockN(void);
unsigned char GetAlarmN(void);
extern "C" unsigned char GetAddrN(void);
extern "C" void SetAddrN(unsigned char);


void TransN(unsigned char);

void EmbMsgN::AddToAnsDirect(unsigned char data)
{
//if(GetTestMode() == 0x50)
//{
  //	printf("\n\rans+> %02X", data);
//}

   ans[current_posa++] = data;
}


void EmbMsgN::AddToAns(unsigned char data)
{

//if(GetTestMode() == 0x50)
//{
//	printf("\n\rans+> %02X", data);
//}

 				if(current_posa < (MAX_LEN - 1))
				switch(data)
				{
								case 0x5A:  ans[current_posa++] =0x5A;  ans[current_posa++] =0x00; break;
								case 0x55: ans[current_posa++] =0x5A;  ans[current_posa++] =0x01; break;
								case 0xA5: ans[current_posa++] =0x5A;  ans[current_posa++] =0x02; break;
								case 0xAA: ans[current_posa++] =0x5A;  ans[current_posa++] =0x03; break;
								default: ans[current_posa++] = data;
				}
}


unsigned char EmbMsgN::ChkCRCN(unsigned long pos)
{
 unsigned char crc = 0;
 unsigned long i;

 for(i = pos;	i < (pos + body[pos + 1] + 2); i++)
{
  crc += body[i];
 // printf("i : %d  body[i] %0x%02X", i, body[i]);
}
 crc += 1;
// if(GetTestMode() == 0x50)
//{
 	      //	printf("_%02X", byte);	  //test
//			printf("crc = 0x%02X", crc);
//}

 //printf("crc = 0x%02X", crc);
 if(crc  == body[i])
  {
   //	  	if(GetTestMode() == 0x50)
   //	  		{
 	//     	printf("_%02X", byte);	  //test
   	//  		printf("\n\rOk! = 0x%02X", crc);
	// 		}

  return 1; //temporary
  }

 else
  {
  	if(GetTestMode() == 0x50)
  			{
 	      //	printf("_%02X", byte);	  //test
  			 printf("\n\rBad! crs = 0x%02X i : %d body = 0x%02X", crc,i, body[i]);
  			}
  return 0;
  }
}


#define COMMANDN1 (1)
#define COMMANDN2 (2)
#define COMMANDN3 (3)
#define COMMANDN4 (4)
#define COMMANDN5 (5)
#define COMMANDN6 (6)
#define COMMANDN7 (7)
#define COMMANDN8 (8)
#define COMMANDN80 (0x80)




#define START_ANS (0xAA)

void EmbMsgN::RunCommandN1(void)
{
// if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN1");
//}
unsigned char curcrc = 0; 

//AddToAns(MY_ADDRESS);
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += MY_ADDRESS;
AddToAns(COMM1_LEN);
curcrc += COMM1_LEN;
AddToAns(COMMANDN1);
curcrc += COMMANDN1;
AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN2(unsigned short freq)
{
static long cnt = 0l;
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN2");
//}
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM2_LEN);
curcrc += COMM2_LEN;
AddToAns(COMMANDN2);
curcrc += COMMANDN2;
#ifdef	 TEST_PRM_PCH_N_2
	printf("\n\r oldfreq = %d freq = %d",emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ,freq);
#endif //TEST_PRM_PCH_N_2

//______________________________________________________
	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
//091202	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
#ifdef PRM_N_KEEP_FREQ
 		   SetNeedWriteDevId();
#endif     // PRM_N_KEEP_FREQ
//______________________________________________________




SetFreqN();
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }
//	  delay1 = ZERO_DELAY;	//to send immediatly
	while((time1-timerun) < (unsigned long)RUN_TIME)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }


AddToAns(GetLockN());
curcrc += GetLockN();
AddToAns(curcrc+1);
}

#define RUN_OK (1)

void EmbMsgN::RunCommandN80(unsigned short b0,unsigned short b1,unsigned short b2,unsigned short b3,unsigned short b4)
{
static long cnt = 0l;
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN2");
//}
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM80_LEN);
curcrc += COMM80_LEN;
AddToAns(COMMANDN80);
curcrc += COMMANDN80;
//______________________________________________________
 //	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
//091202	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
//	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
//#ifdef	   PROG_PRM_PCH_L
// 		   SetNeedWriteDevId();
//#endif     // PROG_PRM_PCH_L
//______________________________________________________

SetFreqN80(b0, b1, b2, b3, b4);
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }
//	  delay1 = ZERO_DELAY;	//to send immediatly
	while((time1-timerun) < (unsigned long)RUN_TIME)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }


AddToAns(RUN_OK);
curcrc += RUN_OK;
AddToAns(curcrc+1);
}

//_________________________________________________________
/*
void RunCommandN2(unsigned short freq)
{
static long cnt = 0l;
//printf("\n\rRunCommandN2");
unsigned char curcrc = 0; 

//______________________________________________________
	   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  freq; 
	   KeepParam(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ , FREQ1_ADDR);
	   emb5StatusReciever1.emb5statusreciever.frequ = emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
//t	   SetFreq1();
			// Stephany19++;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L
//______________________________________________________

SetFreqN();
//_________________________________________
   breakflag = 0;
   timerun = time1;
// if(GetTestMode() == 0x50)
// {
// printf("\n\r...start time1 = %d, run_time = %d cnt = %d", time1,(unsigned long)RUN_TIME, cnt);
// }

	while((time1-timerun) < (unsigned long)RUN_TIME)
	{
	  cnt++;
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
 //if(GetTestMode() == 0x50)
// {
//  printf("\n\r...stop time1 = %d cnt = %d", time1, cnt);
// }
}

*/



//_________________________________________________________




void EmbMsgN::RunCommandN3(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM3_LEN);
curcrc += COMM3_LEN;
AddToAns(COMMANDN3);
curcrc += COMMANDN3;
//________________________________________
	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; //MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");
//printfpd(" %X", att);
//_______________________________________
 SetAttN();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}

//___________________________________________________________________100330
void EmbMsgN::RunCommandN7(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM7_LEN);
curcrc += COMM7_LEN;
AddToAns(COMMANDN7);
curcrc += COMMANDN7;
//________________________________________
	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2 = att; //MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

// printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>n7");
//printfpd(" %X", att);
//_______________________________________
 SetAtt7N();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN8(unsigned char att)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN3");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM8_LEN);
curcrc += COMM8_LEN;
AddToAns(COMMANDN8);
curcrc += COMMANDN8;
//________________________________________
	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3 = att;//MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   //091202		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N8");
//printfpd(" %X", att);
//_______________________________________
 SetAtt8N();
// delay1 = ZERO_DELAY;	//to send immediatly
//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns((unsigned char)breakflag);
curcrc += (unsigned char)breakflag;
AddToAns(curcrc+1);
}


//___________________________________________________________________100330




/* 100330

void EmbMsgN::RunCommandN4()
{

//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN4");
//}

unsigned short curLev = GetLevN();
unsigned char curAtt = GetAttN();
unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(COMMANDN4);
curcrc += COMMANDN4;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xff);  
curcrc += curFreq& 0xff;

AddToAns(curAtt);
curcrc += curAtt;
AddToAns(curLev);
curcrc += curLev;
//______________________________________
AddToAns(Rej);
curcrc += Rej;

AddToAns(Filtr);
curcrc += Filtr;
//_______________________________________


AddToAns(curcrc+1);
}

 */

void EmbMsgN::RunCommandN4()	 //100330
{

//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN4");
//}

unsigned short curLev = GetLevN();
unsigned char curAtt =  GetAttN();
unsigned char curAtt2 = GetAtt2N();
unsigned char curAtt3 = GetAtt3N();

//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");
//printfpd(" %X", curAtt);
//printfpd(" %X", curAtt2);
//printfpd(" %X", curAtt3);
//printfp("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>N4");


unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(COMMANDN4);
curcrc += COMMANDN4;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xff);  
curcrc += curFreq& 0xff;

AddToAns(curAtt);
curcrc += curAtt;
//AddToAns(curLev);
//curcrc += curLev;
//______________________________________
//AddToAns(Rej);	 //?
//curcrc += Rej;	 //?

AddToAns(Filtr);
curcrc += Filtr;
//_______________________________________
AddToAns(curAtt2);
curcrc += curAtt2;
AddToAns(curAtt3);
curcrc += curAtt3;


//_______________________________________
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN5(unsigned char rej)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN5");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM5_LEN);
curcrc += COMM5_LEN;
AddToAns(COMMANDN5);
curcrc += COMMANDN5;
//________________________________________
 //	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 //		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

 Rej = rej; //set global rejektor
//_______________________________________
// SetAttN();
 SetFreqN();
// delay1 = ZERO_DELAY;	//to send immediatly

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);

}

void EmbMsgN::RunCommandN6(unsigned char filtr)
{
//if(GetTestMode() == 0x50)
//{
//printf("\n\rRunCommandN6");
//}

unsigned char curcrc = 0; 
//unsigned char flag;
AddToAnsDirect(START_ANS);
AddToAns(GetAddrN());
curcrc += GetAddrN();
AddToAns(COMM6_LEN);
curcrc += COMM6_LEN;
AddToAns(COMMANDN6);
curcrc += COMMANDN6;
//________________________________________
 //	 	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = MakeAtt(att); 
	//091201	   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = att; 
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 //		   KeepParam(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt , ATT1_ADDR);

 Filtr = filtr; //set global filtr
//_______________________________________
// SetAttN();
 SetFreqN();
// delay1 = ZERO_DELAY;	//to send immediatly

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);

}






void EmbMsgN::SetCommandN(unsigned long pos)
{
 switch(body[pos++])
 {
  case 1	: RunCommandN1(); break;
  case 2	: RunCommandN2((body[pos] << 8) + body[pos +1]); break;
  case 3	: RunCommandN3(body[pos]); break;
  case 4	: RunCommandN4(); break;
  case 5	: RunCommandN5(body[pos]); break;
  case 6	: RunCommandN6(body[pos]); break;
  case 7	: RunCommandN7(body[pos]); break;
  case 8	: RunCommandN8(body[pos]); break;
  case 0x80	: RunCommandN80(body[pos],body[pos+1],body[pos+2],body[pos+3],body[pos+4]); break;

  default 	: break;
 }
}

unsigned char EmbMsgN::ParseN(void)
{
parsed_now = 1;
unsigned long current_posr = 0;
unsigned long len;
unsigned char flag = 0;
//printf("\n\r 1");
// TransN('1');
//printf("\n\r>%d  - %d ",current_posr, current_posw);
 while(current_posr < current_posw)
 {
 // current_posr++;
 //printf(" %02X", body[current_posr++]);
// if(GetTestMode() == 0x50)
//{
// printf("\n\r 1");
//}
 //	if(0)
// TransN(body[current_posr]);
   if(body[current_posr++] ==  START_COMMAND)
   {
//if(GetTestMode() == 0x50)
//{
//printf(" 2");
//}
//TransN('2');

	len = body[current_posr + 1];
	if(body[current_posr] & MASK_REQUEST)
	{
//if(GetTestMode() == 0x50)
//{
//  printf(" 3");
//}
//TransN('3');
     if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
     {
// if(GetTestMode() == 0x50)
//{
//printf(" 4");
//}
//TransN('4');
 	   if(ChkCRCN(current_posr))	  //now in current_posr is addr
 //	   if(1)
	   {
 //		printf("C");
//TransN('5');
	     flag = 1;
   //	     SetStartAns();
         SetCommandN(current_posr + 2);
	   }   //crc
     }	  //address
	 else	//address
	 {
//printf(" addr = 0x%02X" , body[current_posr]); //for debug
	 }
	} //Mask_request
	 else	//address
	 {
 //     printf("m"); //for debug
	 }

	  current_posr += len + 2;
	  if(current_posr > MAX_LEN) break;
   }  //start
 }	//while
 //if(flag)
 //{
 // SetStopAns();
//  SendAns();
// }
 // Init();
parsed_now = 0;  
 return flag;	 
} 
//____________________________________


void EmbMsgN::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsgN::Init()
{
	counter=0;
//t  for(int i=0; i<MAX_LEN; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
//___________________________________________
 current_posr = 0;
 current_posw = 0;
 parsed_now = 0;
 current_posa = 0;
//t for(i=0; i<MAX_LEN; i++) ans[i]=0;
// alarm = 0;
// lock = 0;
// flagatt = 0;
}

unsigned short EmbMsgN::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned short EmbMsgN::Add(unsigned char byte)
{
//_______________________________________
//t  if(parsed_now) return 0;
//_______________________________________ 
  if(counter<MAX_LEN)
	{
//________________________________
		current_posw++;
//________________________________
		body[counter++]=byte;
		return 1;
	}
	else
	    return 0;
}

int short EmbMsgN::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsgN::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned short EmbMsgN::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
 		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
}

unsigned short EmbMsgN::CalcCRC()
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
 
#endif // PROG_PRM_PCH_N 
/////////////////////
#define   EmbMsgBuffer_Size (32)
struct EmbMsgBuffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
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
    return n;
   }
  else
  {	 
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
	unsigned char dem1; // Сососяние платы интерфейсов      // 64
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
//EmbMsgBuffer rBuffEmbMsg;
//EmbMsgBuffer tBuffEmbMsgWest;
//EmbMsgBuffer tBuffEmbMsgEast;
EmbMsg embMsg232;
EmbMsg embMsg232E;
EmbMsg embMsgWest;
EmbMsg embMsgEast;
EmbMsg embMsgAns;
EmbMsg embMsgTemp;
EmbMsg *embMsgRequest;
EmbRS232 embRS232;

#ifdef USE_USART2
EmbRS232 embRS232S;
EmbMsg embMsg232S;
unsigned char mode5AS;
#endif // USE_USART2

EmbRS485 embRS485;
EmbMsg embMsg485E;
//EmbSerialMD34AVT embSerialACT155;

#ifdef PROG_PRM_PCH_N
EmbMsgN embMsg485;	//091113
EmbMsgN embMsg232N;
#endif
 
	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned long timerun;
	unsigned char breakflag;

#ifdef PRM_PCH_DEBUG1
	unsigned long time1start=0, time1finish=0;
#endif //PRM_PCH_DEBUG1

	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned long time1test=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];
    unsigned char * bt;
	unsigned short addr1;
	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
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
	unsigned char   setf1, setatt1, setf2, setatt2, modescan1, modescan2;
	signed long curval1, curval2;

	unsigned char use_standard_protocol;
	unsigned long standard_protocol_timer;


//extern "C" void embRS232N_rcvbuf_Add(unsigned char SetOpChar)	// called frequency = 1 ms
// {
 // printf("\n\r BuffSize :%d", embRS232.rcvbuf.BuffSize);
//   embRS232N.rcvbuf.Add(SetOpChar);
// }




unsigned long ErrResSNMP;
unsigned long timeres;
unsigned char start_count;
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
unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;
UL2UC ul2uc;
UI2UC ui2uc;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
struct EmbMsgUD
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];
	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned short CRC() {	return body[body[1]+2]; }
	unsigned char Body(int i) { return body[i+2]; }
	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 64-counter; }
	int  short IsEnd();
	unsigned short ChkCRC();
	unsigned short TestCRC();
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsgUD::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++) body[i]=0;
}

unsigned short EmbMsgUD::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsgUD::IsEnd()
{
  if(counter>2)
		if(counter==Length()+3)
			return 1;
	return 0;
} 

unsigned short EmbMsgUD::ChkCRC()
{
  //	printf("\n\r CRC(): %02X , TestCRC : %02X", CRC(),TestCRC());	 //for test
	if(CRC()==TestCRC()) return 1;
	else 
	return 0;
}

unsigned short EmbMsgUD::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
	 	body[Length()+2]=c+1;
	return (unsigned char)(c+1);
	}
	else return 0;
} 

unsigned short EmbMsgUD::TestCRC()
{
  int i;
	unsigned char c=0;
	if(body[1]<64) 
	{
		for(i=0; i<body[1]; i++) c += body[i+2];
	 	return (unsigned char)(c+1);
	}
	else return 0;
}

*/
//>>>>>>>>>>>added types



struct Emb5CommandRecieverSetSendStatus
{
	unsigned char number; 		// Код канала РПУ (1..2)
	unsigned char getGenStatus; 	// 0 – выключение генерации сообщения статуса, 
					// 1 – включение генерации сообщения статуса, 
					// 2 – однократный запрос статуса
};

union UnEmb5CommandRecieverSetSendStatus
{
	Emb5CommandReReeverSetSendStatus emb5commandrecieversetsendstatus; 	 // Код канала РПУ (1..2)	
	unsigned char byte[2];
};


struct Emb5GetRPUState
{
	unsigned char number; 	 // Код канала РПУ (1..2)	
};

union UnEmb5GetRPUState
{
	Emb5GetRPUState emb5getrpustate; 	 // Код канала РПУ (1..2)	
	unsigned char byte[1];
};


struct Emb5Acknowledge
{
	unsigned char number; 		// Код канала РПУ (1..2)
	unsigned char AcknowledgeType; // код подтверждаемой команды (см. таблицу 2.2)
}; // 1 байт


union UnEmb5Acknowledge
{
	Emb5Acknowledge emb5acknowledge; 	 // Код канала РПУ (1..2)	
	unsigned char byte[2];
};


struct Emb5Exception
{
	unsigned char number; 		// Код канала РПУ (1..2)
   	unsigned short ExceptionCode; // код ошибки: 0 – сбой при выполнении команды;
//	unsigned char rezerved;
          // 1 – авария устройства
};

union UnEmb5Exception
{
	Emb5Exception emb5exception; 	 // Код канала РПУ (1..2)	
	unsigned char byte[3];
};



struct Emb5ScanFreq
{
 unsigned char number;
 unsigned long frequStart;	   //? long after short - wil be work?
 unsigned short step;
 unsigned short numOfStep; //2...500
};

union UnEmb5ScanFreq
{
	Emb5ScanFreq emb5scanfreq; 	 // 	
	unsigned char byte[9];
};


struct Emb5StatusFrequScan
{
unsigned char number;
unsigned long frequStart;
unsigned short step;
unsigned short numOfStep;
unsigned char att;
unsigned short level[501];
};

union UnEmb5StatusFrequScan
{
	Emb5StatusFrequScan emb5statusfrequscan; 	 // Код канала РПУ (1..2)	
	unsigned char byte[1016];
};

struct EmbUpDownStatus
{
 //unsigned long number;
 unsigned long sendup;
 unsigned long received;
 unsigned long crc_ok;
 unsigned long crc_bad;
};

union UnEmbUpDownStatus
{
	EmbUpDownStatus embupdownstatus; 	 // Код канала РПУ (1..2)	
	unsigned char byte[20];
};

//status
//{
//	бит 0 — захват есть(1)/нет(0) синтезатора (частота установилась)
//	бит 1 — резерв;
//	бит 2 — резерв;
//	бит 3 — резерв;
//	бит 4 — резерв;
//	бит 5 — резерв;
//	бит 6 — резерв;
//	бит 7 — резерв;
//}

//struct Emb2TypeVer
//{
//	unsigned short type;       // Тип устройства ПРМ-ПЧ (в классификации ЗАО «Радиан»
//	unsigned short softVer;    // Версия ПО ПРМ-ПЧ
//	unsigned short ctrlNumber; // Это идентификатор устройства
//	unsigned short ctrlYear;   // Служебная информация ЗАР «Радиан»
//	unsigned short ctrlVer1;   // Служебная информация ЗАР «Радиан»
//	unsigned short ctrlVer2;   // Служебная информация ЗАР «Радиан»
//	unsigned char signature_hardware[16]; // Параметры «софта», если потребуются
//	unsigned char signature_software[16]; // Конфигурация «железа»  описана ниже
//}; // 44 байта


//signature_hardware[0] = диапазон модуля на входе 1;
//signature_hardware[1] = тип фильтра на входе 1;
//signature_hardware[2] = питание на входе 1;
//signature_hardware[3] = Версия ПО РПУ;
//signature_hardware[4] = диапазон модуля на входе 3;
//signature_hardware[5] = тип фильтра на входе 3;
//signature_hardware[6] = питание на входе 3;
//signature_hardware[7]  = резерв;
//signature_hardware[8] = диапазон модуля на входе 2;
//signature_hardware[9] =  тип фильтра на входе 2;
//signature_hardware[10] =  питание на входе 2;
//signature_hardware[11] =  Версия ПО РПУ;
//signature_hardware[12] = резерв;
//signature_hardware[13] = резерв;
//signature_hardware[14] = резерв;
//signature_hardware[15] = резерв;

struct Emb5RPUState
{
	unsigned char number; // Код канала РПУ (1..2)
	unsigned char type; // Диапазон РПУ 1..3
	unsigned char u48; // уровень напряжения питания +48В текущий
	unsigned char u48min; // уровень напр. +48В минимальный за период с прошлого опроса
	unsigned char u48max; // уровень напр. +48В максимальный за период с прошлого опроса
	unsigned char u24; // уровень напряжения питания +24В текущий
	unsigned char u24min; // уровень напр. +24В минимальный за период с прошлого опроса
	unsigned char u24max; // уровень напр. +24В максимальный за период с прошлого опроса
	unsigned char u7; // уровень напряжения питания +7В текущий
	unsigned char u7min; // уровень напр. +7В минимальный за период с прошлого опроса
	unsigned char u7max; // уровень напр. +7В максимальный за период с прошлого опроса
	unsigned char u5; // уровень напряжения питания +5В текущий
	unsigned char u5min; // уровень напр. +5В минимальный за период с прошлого опроса
	unsigned char u5max; // уровень напр. +5В максимальный за период с прошлого опроса
	unsigned char u_5; // уровень напряжения питания -5В текущий
	unsigned char u_5min; // уровень напр. -5В минимальный за период с прошлого опроса
	unsigned char u_5max; // уровень напр. -5В максимальный за период с прошлого опроса	
	unsigned char temp; // уровень температуры текущий
	unsigned char temp_min; // уровень температуры минимальный за период с прошлого опроса
	unsigned char temp_max; // уровень температуры максимальный за период с прошлого опроса
}; // 20 байт


union UnEmb5RPUState
{
	Emb5RPUState emb5rpustate; 	 // Код канала РПУ (1..2)	
	unsigned char byte[20];
};
//<<<<<<<<<<<added types

UnEmbUpDownStatus 	embUpDownStatus1;
UnEmbUpDownStatus 	embUpDownStatus2;

//UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ1;
//UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ2;


UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus1;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus2;

UnEmb5GetRPUState emb5GetRPUState1;
UnEmb5GetRPUState emb5GetRPUState2;

UnEmb5Acknowledge	emb5Acknowledge1;
UnEmb5Acknowledge	emb5Acknowledge2;

UnEmb5Exception emb5Exception1;
UnEmb5Exception emb5Exception2;


UnEmb5RPUState emb5RPUState1;
UnEmb5RPUState emb5RPUState2;

UnEmb5ScanFreq	 emb5ScanFreq1;
UnEmb5ScanFreq	 emb5ScanFreq2;

UnEmb5StatusFrequScan  emb5StatusFrequScan1;
UnEmb5StatusFrequScan  emb5StatusFrequScan2;
/*
EmbMsgUD embMsgUD_1;
EmbMsgUD embMsgUD_2;
EmbMsgUD embMsgUDRequest_1;
EmbMsgUD embMsgUDRequest_2;
 */
unsigned ans1=0, ans2=0;
unsigned short delay1; //, delay2;  //my

unsigned short countMod;
unsigned short countTransit;

unsigned short requestMod=0;
unsigned short requestTransit=0;

#ifdef PRM_PCH_THREE_LINES

UnEmbUpDownStatus 	embUpDownStatus3;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ3;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt3;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus3;
UnEmb5GetRPUState emb5GetRPUState3;
UnEmb5Acknowledge	emb5Acknowledge3;
UnEmb5Exception emb5Exception3;
UnEmb5StatusReciever emb5StatusReciever3;
UnEmb5RPUState emb5RPUState3;
UnEmb5ScanFreq	 emb5ScanFreq3;
UnEmb5StatusFrequScan  emb5StatusFrequScan3;
/*
EmbMsgUD embMsgUD_3;
EmbMsgUD embMsgUDRequest_3;

*/
unsigned ans3=0;
unsigned short delay3;  //my
unsigned short countPower=0;
unsigned short requestPower=0;
unsigned char   setf3, setatt3, modescan3;
unsigned char  ready_power, old_ready_power; 
unsigned long  time3old;
signed long curval3;
unsigned char request3;
unsigned char markerPower;
unsigned long time3BlankPower;
unsigned char delete_msgPower;
unsigned char recievePower;
unsigned char mode5APower;
EmbMsgBuffer tBuffEmbMsgPower;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
unsigned short countTransit4,  countTransit5, countTransit6;
unsigned short requestTransit4,requestTransit5, requestTransit6;
unsigned short fl1,fl2,fl3,fl4,fl5,fl6;

 unsigned char start4, start5,start6;


//___________________________
unsigned char mode5AWest2;
unsigned short countMod2=0;
unsigned char mode5AWest3;
unsigned short countMod3=0;

//___________________________




UnEmbUpDownStatus 	embUpDownStatus4;
UnEmbUpDownStatus 	embUpDownStatus5;
UnEmbUpDownStatus 	embUpDownStatus6;

UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ4;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ5;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ6;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt4;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt5;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt6;

UnEmb5CommandRecieierSetSendStatus emb5CommandRecieverSetSendStatus4;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus5;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus6;

UnEmb5GetRPUState emb5GetRPUState4;
UnEmb5GetRPUState emb5GetRPUState5;
UnEmb5GetRPUState emb5GetRPUState6;

UnEmb5Acknowledge	emb5Acknowledge4;
UnEmb5Acknowledge	emb5Acknowledge5;
UnEmb5Acknowledge	emb5Acknowledge6;


UnEmb5Exception emb5Exception4;
UnEmb5Exception emb5Exception5;
UnEmb5Exception emb5Exception6;

UnEmb5StatusReciever emb5StatusReciever4;
UnEmb5StatusReciever emb5StatusReciever5;
UnEmb5StatusReciever emb5StatusReciever6;

UnEmb5RPUState emb5RPUState4;
UnEmb5RPUState emb5RPUState5;
UnEmb5RPUState emb5RPUState6;

UnEmb5ScanFreq	 emb5ScanFreq4;
UnEmb5ScanFreq	 emb5ScanFreq5;
UnEmb5ScanFreq	 emb5ScanFreq6;

UnEmb5StatusFrequScan  emb5StatusFrequScan4;
UnEmb5StatusFrequScan  emb5StatusFrequScan5;
UnEmb5StatusFrequScan  emb5StatusFrequScan6;
 /*
EmbMsgUD embMsgUD_4;
EmbMsgUD embMsgUD_5;
EmbMsgUD embMsgUD_6;

EmbMsgUD embMsgUDRequest_4;
EmbMsgUD embMsgUDRequest_5;
EmbMsgUD embMsgUDRequest_6;
*/

unsigned ans4=0;
unsigned ans5=0;
unsigned ans6=0;

unsigned short delay4;  //my
unsigned short delay5; 
unsigned short delay6; 


unsigned short countPower4=0;
unsigned short countPower5=0;
unsigned short countPower6=0;

unsigned short requestPower4=0;
unsigned short requestPower5=0;
unsigned short requestPower6=0;

unsigned char   setf4, setatt4, modescan4;
unsigned char   setf5, setatt5, modescan5;
unsigned char   setf6, setatt6, modescan6;

unsigned char  ready_power4, old_ready_power4; 
unsigned char  ready_power5, old_ready_power5;
unsigned char  ready_power6, old_ready_power6;

unsigned long  time4old;
unsigned long  time5old;
unsigned long  time6old;

signed long curval4;
signed long curval5;
signed long curval6;
#endif //PRM_PCH_SIX_LINES

#ifdef PROG_PRM_PCH_L
unsigned char NeedWriteID;
#endif //PROG_PRM_PCH_L

extern "C" signed short ConvVal(unsigned short val)
{
 /*
float fval = (float)val;
// fval *= 0.0221; 
// fval -= 98.2;
 fval *= 0.0227; 
 fval -= 91.649;
return (signed short)fval;
 */
//signed short fval = val * 0.0227 - 91.649;
//signed char fval = (val & 0xFFF) * 0.0227 - 91.649;

signed char fval = (double)(val & 0xFFF) * 0.0236 - 94.183;
//if(GetTestMode() == 0x50)
//{
//printf("\n\r ConvVal val = 0x%X  fval = 0x%X", val, fval);
//}
return 	fval;
//return 	val & 0x0fff;
}

extern "C" unsigned char MakeAttBack(unsigned char inpval1)
{
/*
  unsigned char outval;
  unsigned char ht;
  unsigned char lt;
  
  lt = inpval & 0xf;
  ht = (inpval & 0xf0) >> 4;
  

  if(lt) {outval = ((lt << 1) + 30);}
  else 	 {outval = ht << 1;}*/

//  outval = ht << 1;
	unsigned char inpval = EzhinSbazhin(inpval1);

	  return (inpval&0x0F)*2 + ((inpval&0xF0)>>4)*2;

//  return outval;
}
#ifdef PRM_N_KEEP_FREQ
unsigned long DelayWriteTime;
#endif
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
extern "C" void Init_PRM_PCH(void)
{


#ifdef USE_USART2
 mode5AS = 0;
#endif // USE_USART2

//ok  return; //100617
//flag_pdc0 = 0;
//flag_pdc1 = 0;
 //  embMsg485.Init();   //091113
DelayWriteTime = 0;
use_standard_protocol = 1;
standard_protocol_timer = 1;
#ifndef PROG_PRM_PCH_N_2
Init_SSC1();
#endif


#ifdef DISABLE_ETHERNET
Init_IOs();
#endif //DISABLE_ETHERNET

led2timer  = 0;
led3timer  = 0;
SetLed2(1);
SetLed3(1);
#ifdef PROG_PRM_PCH_N
    SetUsart1BaudRate(921600l);
#endif //PROG_PRM_PCH_L


//ok return; //100617


#ifdef PROG_PRM_PCH_L
 NeedWriteID = 0;
#endif //PROG_PRM_PCH_L


//char any;
/*
 embMsgUD_1.Init();
 embMsgUD_2.Init();
 embMsgUDRequest_1.Init();
 embMsgUDRequest_2.Init();
*/
#ifdef PRM_PCH_THREE_LINES
  /*
 embMsgUD_3.Init();
 embMsgUDRequest_3.Init();
 */
 setf3 = 0;
 setatt3 = 1; //0911090;
 ready_power=0;
 old_ready_power=0; 
 modescan3 = 0;
 curval3	= 0;
// for(i=0; i<16; i++)
//	{
//	 embUpDownStatus3.byte[i] = 0;
//	 any = inportb(0x507);	 //clear
//	 any = inportb(0x509);
//	 any = inportb(0x50B);


  //	}
  time3old=0;
  request3=0;
  time3BlankPower=0; 
  markerPower=0; ready_power=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgPower=0;  recievePower=0; 
  mode5APower=0;  
  tBuffEmbMsgPower.Init();
  request3=0;
  delay3 = NO_SCAN_DELAY;
  countPower=0;
  requestPower=0;
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
countTransit4 = 0; countTransit5 = 0; countTransit6 = 0;
//fl1=fl2=fl3=fl4=fl5=fl6=fl6=0; 
fl1=fl2=fl3=fl4=fl5=fl6=fl6=1;	//no alarm

requestTransit4 = 0; requestTransit5 = 0; requestTransit6 = 0;
 start4 = 1;
 start5 = 1;
 start6 = 1;
//_______________________________
 mode5AWest2=0; 
 countMod2=0;
 mode5AWest3 = 0;
 countMod3=0;
//_______________________________
 /*
 embMsgUD_4.Init();
 embMsgUD_5.Init();
 embMsgUD_6.Init();
 embMsgUDRequest_4.Init();
 embMsgUDRequest_5.Init();
 embMsgUDRequest_6.Init();
  */
 setf4 = 0;
 setf5 = 0;
 setf6 = 0;
 setatt4 = 1; //0911090;
 setatt5 = 1; //0911090;
 setatt6 = 1; //0911090;
 ready_power4=0;
 ready_power5=0;
 ready_power6=0;
 old_ready_power4=0; 
 old_ready_power5=0; 
 old_ready_power6=0; 
 modescan4 = 0;
 modescan5 = 0;
 modescan6 = 0;
 curval4	= 0;
 curval5	= 0;
 curval6	= 0;
 for(i=0; i<16; i++)
	{
	 embUpDownStatus4.byte[i] = 0;
 	 embUpDownStatus5.byte[i] = 0;
 	 embUpDownStatus6.byte[i] = 0;
 	}
  time4old=0;
  time5old=0;
  time6old=0;
  delay4 = NO_SCAN_DELAY;
  delay5 = NO_SCAN_DELAY;
  delay6 = NO_SCAN_DELAY;
#endif // PRM_PCH_SIX_LINES

#ifndef	PROG_PRM_PCH_L
//091202 RestoreParameters();
#endif //PROG_PRM_PCH_L

 setf1 = 0;
 setatt1 = 1; //0911090;
 setf2 = 0;
 setatt2 = 1; //0911090;
 modescan1 = 0;
 modescan2 = 0;
 curval1	= 0;
 curval2	= 0;
 for(i=0; i<16; i++)
	{
		embUpDownStatus1.byte[i] = 0;
		embUpDownStatus2.byte[i] = 0;
	}
ans1=0; ans2=0;
delay1 = NO_SCAN_DELAY;
//delay2 = NO_SCAN_DELAY;
countMod=0;
countTransit=0;
//requestMod=0;
requestMod=11; //not need roulette at start



requestTransit=0;
cntflag6 = 0;
ErrResSNMP = 0l;
timeres = 0l;
start_count = 0;
send41 = 0l; send42 =0l; received1 =0l; received2 =0l; good1 =0l; good2 =0l; bad1 =0l; bad2 =0l;
AsciiInit();
EmbInit(); //my
  time1=0;
  flagRequest=0;
  serr=0xFF; crc_temp=0;
  i=0;
  time1old=0; time2old=0;
  timerun=0;
  breakflag = 0;
   request1=0; request2=0;
  time3Marker=0; time3BlankTransit=0; time3BlankMod=0;
  time1test=0;
  markerWest=0; markerEast=0; ready_transit=0; ready_mod=0; dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgWest=0; delete_msgEast=0; recieveWest=0; recieveEast=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0; mode5AWest=0; mode5AEast=0; 
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
 //	tBuffEmbMsgWest.Init();
//	tBuffEmbMsgEast.Init();
//	rBuffEmbMsg.Init();
// 	embSerialACT155.Init();
    embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}
	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=2=
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;
 	unEmb2TypeVer.emb2TypeVer.type       = 0x0900;
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
 	embMsgTemp.Init();
// 	outportb(4,0xff); // get all leds off
#ifdef PROG_PRM_PCH_C
//    outportb(POWER_PORT, CH1_MASK);// | CH2_MASK  | CH3_MASK)); //get on  channel 1
 	delay1 = START_TIMEOUT;
#endif //PROG_PRM_PCH_C

#ifdef PROG_PRM_PCH_S

//#ifndef PROG_PRM_PCH_L
 //   outportb(POWER_PORT2, CH4_MASK);// | CH2_MASK  | CH3_MASK)); //get on  channel 1
 	delay4 = START_TIMEOUT;
//	while(embSerialACT155.UsedTransit())
//		{
//   			byte = embSerialACT155.GetTransit();
//		} 
//091113	AlarmPmOn2();


//#endif //PROG_PRM_PCH_L

//while(embSerialACT155.UsedMod())
//		{
//   			byte = embSerialACT155.GetMod();
//		} 

//091113	AlarmPmOn();
#endif //PROG_PRM_PCH_C
  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = 0; 
  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2 = 0;
  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3 = 0;
//ok  return; //100617
  SetAttN();

  SetAtt7N();

  SetAtt8N();
#ifndef	 TEST_PRM_PCH_N_2
  LoadDDSN2();
  SetFreqN();
#endif
  
#ifndef PRM_N_KEEP_FREQ
   
//___________________---for quck start  - need remove!!
  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ  = 2000; Filtr = 1;
 // SetFreqN();
//_____________________________
#else // PRM_N_KEEP_FREQ
#ifndef	 TEST_PRM_PCH_N_2

ClearNeedWriteDevId();
#endif 
 	NeedWriteID = 0;
#endif

//t100625 SetFreqN();


}

extern "C" void ClearMod()
{
//while(embSerialACT155.UsedMod())
//		{
//   			 embSerialACT155.GetMod();
//		} 
}

extern "C" void ClearTransit()
{
//while(embSerialACT155.UsedTransit())
//		{
//   		   embSerialACT155.GetTransit();
//		} 
}





#ifdef PROG_PRM_PCH_C
 /*
extern "C" void CheckPower()
{
unsigned char tmppp;
   	 tmppp =  inportb(LED_PORT);
	if(!(inportb(POWER_PORT) & ALL_CH_POWER_ON))
	{
     tmppp &= ALARM_POWER;
	 }
	else
	{
     tmppp |= NO_ALARM_POWER;
	}

   if(!(inportb(POWER_PORT) & ( CH1_MASK + CH2_MASK + CH3_MASK)))
   {
  	  tmppp |= NO_ALARM_INPUT + NO_ALARM_PM;
    }
 	 outportb(LED_PORT, tmppp);
}
 */
#endif

extern "C" void PRM_PCH()
 {
#ifdef TEST_USART2
static long cntt;
static unsigned char schar;
cntt++;
//schar++;
if(!(cntt % 50))
{
schar++;
 embRS232S.Trans2(schar);
 //printfpd(" %02X",schar);
    //for test
}
#endif
//return; //100617
  
  standard_protocol_timer += 1l;
 // if((!(standard_protocol_timer % 10000)) && (!use_standard_protocol))
 // {
 //  printf("\n\r timer = , %d", (standard_protocol_timer / 10000));
 //  standard_protocol_timer += 10l;

 // }

  if((standard_protocol_timer > TIME_FOR_STANDART_PROTOKOL) && (use_standard_protocol == 1))
  {
//   printf("\n\r ...timer is ready");
   use_standard_protocol = 0;
   SetUsart0BaudRate(115200l);
#ifdef	 TEST_PRM_PCH_N_2
  LoadDDSN2();
  SetFreqN();
#endif

  }
   
//______________________________________________________________________________________>>_1

/*
cntt++;
if(!(cntt%1000))
{
 LoadDDSN2(); //for test
  }
*/
  
//////////////////////////////////////////////////

#ifdef PRM_N_KEEP_FREQ
   		   if(GetNeedWriteDevId())
		   {
#ifdef	 TEST_PRM_PCH_N_2
		 	printf("\n\r Write!");

#endif
			 WriteDevId();

#ifdef	 TEST_PRM_PCH_N_2
//			printf("\n\r Write end!");

#endif



			 ClearNeedWriteDevId();
		   }
#endif // PRM_N_KEEP_FREQ

//#ifdef	 TEST_PRM_PCH_N_2
//if(!(time1 % 5000l))
//{
// printf("\n\r time1 = %d  DelayWriteTime = %d", time1, DelayWriteTime);
//}

//#endif

 
}

#ifdef PROG_PRM_PCH_N





extern "C" void Remote_PRM_PCH(void)
{
// #include checkremoteprm_pch.inc
//file: checkremoteprm_pch.cpp


//////////////////////////////////////////////////
	 //	i232=0;

		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
		 //	printf(" %02X", byte);

 if(use_standard_protocol)
 {
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
				embRS232.Trans(0x55);//ans();
				break; 
			case 0xAA: embMsg232.Init(); break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
			case 0x5A: mode5A=1; break;
			default:
				if(mode5A) 
				{
					embMsg232.Add(Modify5A(byte));
					mode5A=0;
				}
				else embMsg232.Add(byte);
			}
			if(embMsg232.IsEnd()) 
				break;
 //090519			if(++i232>10) break;
			}
else
			{

   	switch(byte)
				{
				case 0x55:
		   	  //	 embMsg485.ParseN();
				 
				if(embMsg232N.ParseN())
				{
//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\rans>");	  //test
//}
		  //		if(!flag_pdc0)
		  //		{
  		 //		flag_pdc0 = 1;

#ifdef USART0_TRY_PDC_1T
				time_pdc_u0t = timer;	  //this make delay to answer to can finish set syntezers
#endif

		 //		}

				  embRS232.Trans(0x55);

					for(long i = 0; i < embMsg232N.GetAnsLen(); i++)
					{
						  embRS232.Trans(embMsg232N.GetAns(i));
 					}
				  embRS232.Trans(0x55);
				} 
				  
				embMsg232N.Init();
			 
				break; 
		 //many commands in one 0x55 		case 0xAA: embMsg485.Init(); break;  
				case 0x5A: mode5A=1; break;
				default:
					if(mode5A) 
					{
						embMsg232N.Add(Modify5A(byte));
						mode5A=0;
					}
					else embMsg232N.Add(byte);
				}
			}
		}


  

//#ifdef PROG_PRM_PCH_N

		if(!embMsg232.IsEnd())
//		if(1) //temporary
		{
   	 //	printf("1");

//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\r485>");	  //test
//}



#ifdef DIRECT_RS485
 			while(embRS485.UsedReceive())
#else
			while(embSerialACT155.UsedTransit())
#endif
			{


#ifdef DIRECT_RS485
			 	byte = embRS485.Receive();
#else
				byte = embSerialACT155.GetTransit();
#endif


//if(GetTestMode() == 0x50)		 //print byte
//{
//   	      	printf(" %02X", byte);	  //test  ok
		 //	printf(" %c", byte);	  //test  ok
//}
//__________________________________test
//			embRS485.Trans(byte);
//__________________________________test

			   	switch(byte)
				{
				case 0x55:
		   	  //	 embMsg485.ParseN();
				 
				if(embMsg485.ParseN())
				{
//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\rans>");	  //test
//}
		  //		if(!flag_pdc1)
		  //		{
  		  //		flag_pdc1 = 1;
				time_pdc_u1t = timer;	//100420
		  //		}
#ifdef DIRECT_RS485
				  embRS485.Trans(0x55);
#else
				  embSerialACT155.AddTransit(0x55);
#endif
					/  embSerialACT155.AddTransit(0xAA);
					for(long i = 0; i < embMsg485.GetAnsLen(); i++)
					{
			 //	  	  embRS485.Trans(embMsg485.GetAns(i));
			 //		  embRS485.Trans(embMsg485.GetAns(i));
#ifdef DIRECT_RS485
					  embRS485.Trans(embMsg485.GetAns(i));
#else
					  embSerialACT155.AddTransit(embMsg485.GetAns(i));
#endif


//if(GetTestMode() == 0x50)
//{
//   	     	printf("+%02X", embMsg485.GetAns(i));	  //test
//}
					}
#ifdef DIRECT_RS485
				  embRS485.Trans(0x55);
#else
				  embSerialACT155.AddTransit(0x55);
#endif

				} 
				  
				embMsg485.Init();
			 
				break; 
		 //many commands in one 0x55 		case 0xAA: embMsg485.Init(); break;  
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);

				}


			   //	  	printf(".%X", byte);
			} //embrs485 usedReceive

}  //!embrs232.isend

//#endif PROG_PRM_PCH_N

// #include answerprm_pch.inc
// file: answerprm_pch.cpp
///////////////////////////////
///   answer  ///
///////////////////////////////

  			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
			   //	{
				  embMsgRequest = &embMsg232;
				//	flagRequest=1;
			  //	}
		   //	}
		  //	if(flagRequest) //embMsgRequest->IsEnd())
		//	{

// if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
 //			 if(1)
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
			  		embMsgAns.SetAddrI(SelfID());
					embMsgAns.SetAddrS(embMsgRequest->AddrI());					
			 	    switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
//printEthLongHex(0x01);
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
				   		break;
//______________________________________________________________________________________________						
					case 0x02 :
				//	printEthLongHex(0x02);

						   embMsgAns.SetType(0x02);
						   embMsgAns.SetLength(embMsgRequest->Body(2) + 3);
						   embMsgAns.SetBody(0,embMsgRequest->Body(0));	//#	number 1 Byte
						   embMsgAns.SetBody(1,embMsgRequest->Body(1));	//#	number 2 Byte
						   embMsgAns.SetBody(2,embMsgRequest->Body(2));	// 
						   embMsgAns.SetBody(3,embMsgRequest->Body(3));	// celling
						   embMsgAns.SetBody(4,embMsgRequest->Body(4));	// celling


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							write_xil_char( ( (embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i), embMsgRequest->Body(3 + i));
						   }


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							 embMsgAns.SetBody(3 + i ,read_xil_char((embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i));
						   }
							//need make GetPort
					    break;
					   	   				
//______________________________________________________________________________PS
			 
					case 0x05: // Загрузка файла (запись в устройство) 
			   //		printEthLongHex(0x05);
			    use_standard_protocol = 2;//to do not set

 			   	 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);


				  		ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);

						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

				  		shift = ui2uc.ui;

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
				//	printEthLongHex(0x38);

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
 					case 0x08: // Запрос состояния
				  //	printf("\n\r>>");

						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++)
						{
					 	embMsgAns.SetBody(i,unStateBMD155.byte[i]);
					 //	embMsgAns.SetBody(i,(30 + (i%20)));
				  //	  	printf (".%02X",unStanStaD155.byte[i]);
						}
				//		printf("\n\r>>");

						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
						unStateBMD155.stateBMD155.demPI=0;
						unStateBMD155.stateBMD155.loopPI=0;
						unStateBMD155.stateBMD155.statePI=0;
						break;
					case 0x09:
				  //	printf("\n\r 0x09");
						 if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
	  							}
							if(embMsgRequest->Body(0)==2)
							{
  							}

						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
			//			printf("\n\r----> 0x0A");

						//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
	 				}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
	  						}
						break;
					case 0x0B:
			  //	   	printf("\n\r----> 0x0B");
						//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
	   
						}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
		 
						}
						break;
					case 0x10:
				   //	printf("\n\r 0x10");
							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
						 //	for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
						break;
					case 0x13:
				   //	 printf("\n\r 0x13");

							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
					   //		bt = (unsigned char far*)0x80000000;
							 bt = (unsigned char *)(NVRAM_BASE);


							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< from bukc

				   case 0x22:
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

   					case 0x23:
							embMsgAns.SetType(0x23);
							if(embMsgRequest->Body(0))// set
							{
							   SetAddrN( embMsgRequest->Body(1));
							}
						   						   
							embMsgAns.SetLength(2);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 	
						   	embMsgAns.SetBody(1, GetAddrN() & 0xff);
   							break;
//________________________________________________________________________PS

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();
//#ifdef TEST_USART2_REMOTE
	   //	printfp("\n\r... ans");
//	   printfp2("\n\r ans:");
//#endif


			  //		if(flagRequest == 1) 
					{
						embRS232.Trans(0x55);
						embRS232.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
//#ifdef TEST_USART2_REMOTE
	   //	printfp("\n\r... ans");
//	   printfpd2(" %02X",embMsgAns.body[i]);
//#endif

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
						embMsg232.Init(); //090122
						flagRequest = 0;
					}	//  == 1
				}
				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

}

//__________________________________________________usart2
#ifdef USE_USART2

extern "C" void Remote_PRM_PCHS(void)
{
//////////////////////////////////////////////////
//char cntbuff = 0;

		while(embRS232S.UsedReceive())
		{
			byte = embRS232S.Receive();
  //			cntbuff++;
//#ifdef TEST_USART2
   //		 	printfpd(" %02X", byte);
//#endif //TEST_USART2

//#ifdef TEST_USART2_REMOTE
//		printfpd(" %02X", byte);
//#endif

// if(use_standard_protocol)
 //{
			switch(byte)
			{
			case 0x55: 
				embMsg232S.Init();
			  //	embRS232S.Trans(0x55);//ans();
				break; 
			case 0xAA: embMsg232S.Init(); break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
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
				break;
  //		if(cntbuff>100) break;
 //			}

/*
else
			{

   	switch(byte)
				{
				case 0x55:
		   	  //	 embMsg485.ParseN();
				 
				if(embMsg232N.ParseN())
				{
//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\rans>");	  //test
//}
		  //		if(!flag_pdc0)
		  //		{
  		 //		flag_pdc0 = 1;

#ifdef USART0_TRY_PDC_1T
				time_pdc_u0t = timer;	  //this make delay to answer to can finish set syntezers
#endif

		 //		}

				  embRS232.Trans(0x55);

					for(long i = 0; i < embMsg232N.GetAnsLen(); i++)
					{
						  embRS232.Trans(embMsg232N.GetAns(i));
 					}
				  embRS232.Trans(0x55);
				} 
				  
				embMsg232N.Init();
			 
				break; 
		 //many commands in one 0x55 		case 0xAA: embMsg485.Init(); break;  
				case 0x5A: mode5A=1; break;
				default:
					if(mode5A) 
					{
						embMsg232N.Add(Modify5A(byte));
						mode5A=0;
					}
					else embMsg232N.Add(byte);
				}
			}

*/
		}	 //while


  

//#ifdef PROG_PRM_PCH_N
 /*
		if(!embMsg232.IsEnd())
//		if(1) //temporary
		{
   	 //	printf("1");

//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\r485>");	  //test
//}



#ifdef DIRECT_RS485
 			while(embRS485.UsedReceive())
#else
			while(embSerialACT155.UsedTransit())
#endif
			{


#ifdef DIRECT_RS485
			 	byte = embRS485.Receive();
#else
				byte = embSerialACT155.GetTransit();
#endif


//if(GetTestMode() == 0x50)		 //print byte
//{
//   	      	printf(" %02X", byte);	  //test  ok
		 //	printf(" %c", byte);	  //test  ok
//}
//__________________________________test
//			embRS485.Trans(byte);
//__________________________________test

			   	switch(byte)
				{
				case 0x55:
		   	  //	 embMsg485.ParseN();
				 
				if(embMsg485.ParseN())
				{
//if(GetTestMode() == 0x50)
//{
//   	     	printf("\n\rans>");	  //test
//}
		  //		if(!flag_pdc1)
		  //		{
  		  //		flag_pdc1 = 1;
				time_pdc_u1t = timer;	//100420
		  //		}
#ifdef DIRECT_RS485
				  embRS485.Trans(0x55);
#else
				  embSerialACT155.AddTransit(0x55);
#endif
				//  embSerialACT155.AddTransit(0xAA);
					for(long i = 0; i < embMsg485.GetAnsLen(); i++)
					{
			 //	  	  embRS485.Trans(embMsg485.GetAns(i));
			 //		  embRS485.Trans(embMsg485.GetAns(i));
#ifdef DIRECT_RS485
					  embRS485.Trans(embMsg485.GetAns(i));
#else
					  embSerialACT155.AddTransit(embMsg485.GetAns(i));
#endif


//if(GetTestMode() == 0x50)
//{
//   	     	printf("+%02X", embMsg485.GetAns(i));	  //test
//}
					}
#ifdef DIRECT_RS485
				  embRS485.Trans(0x55);
#else
				  embSerialACT155.AddTransit(0x55);
#endif

				} 
				  
				embMsg485.Init();
			 
				break; 
		 //many commands in one 0x55 		case 0xAA: embMsg485.Init(); break;  
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);

				}


			   //	  	printf(".%X", byte);
			} //embrs485 usedReceive

}  //!embrs232.isend
  */
//#endif PROG_PRM_PCH_N

// #include answerprm_pch.inc
// file: answerprm_pch.cpp
///////////////////////////////
///   answer  ///
/////////////////////////////////
  			if(embMsg232S.IsEnd())//&&embMsg.ChkCRC())
			{

  embMsgRequest = &embMsg232S;

//#ifdef TEST_USART2_REMOTE
//	   printfp("\n\rend ");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif

			   //	{
	//			  embMsgRequest = &embMsg232S;
				//	flagRequest=1;
			  //	}
		   //	}
		  //	if(flagRequest) //embMsgRequest->IsEnd())
		//	{

// if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
 			 if(1)
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
			  		embMsgAns.SetAddrI(SelfID());
					embMsgAns.SetAddrS(embMsgRequest->AddrI());
//#ifdef TEST_USART2_REMOTE
//		printfp("\n\rend");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif
										
			 	    switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
//printEthLongHex(0x01);
//#ifdef TEST_USART2_REMOTE
//		printfp("\n\01");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif

						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
				   		break;
//______________________________________________________________________________________________						
					case 0x02 :
				//	printEthLongHex(0x02);
//#ifdef TEST_USART2_REMOTE
//		printfp("\n\r command 2");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif


						   embMsgAns.SetType(0x02);
						   embMsgAns.SetLength(embMsgRequest->Body(2) + 3);
						   embMsgAns.SetBody(0,embMsgRequest->Body(0));	//#	number 1 Byte
						   embMsgAns.SetBody(1,embMsgRequest->Body(1));	//#	number 2 Byte
						   embMsgAns.SetBody(2,embMsgRequest->Body(2));	// 
						   embMsgAns.SetBody(3,embMsgRequest->Body(3));	// celling
						   embMsgAns.SetBody(4,embMsgRequest->Body(4));	// celling


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							write_xil_char( ( (embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i), embMsgRequest->Body(3 + i));
						   }


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							 embMsgAns.SetBody(3 + i ,read_xil_char((embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i));
						   }
							//need make GetPort
					    break;
					   	   				
//______________________________________________________________________________PS
			 
					case 0x05: // Загрузка файла (запись в устройство) 
//#ifdef TEST_USART2_REMOTE
//		printfp("\n\r command 5");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif

			   //		printEthLongHex(0x05);
			    use_standard_protocol = 2;//to do not set

 			   	 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);


				  		ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);

						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

				  		shift = ui2uc.ui;

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

						if(ui2uc.ui==temp_crc)
						{ //crc

		//110228				if(ul2uc.uc[3] == 0x80) //port : if try use nvram
						if(0) //port : if try use nvram
						{
	  			 		 for(i=0; i<len; i++)
				  		   {
		  		 //	    			write_nvram_char(i + shift, embMsgRequest->Body(i+8));
				  		   }
						 }
						 else  //enover memory
						 {
					  //   shift +=  (unsigned long)(embMsgRequest->Body(0)) << 16;	 //add to address 
						    wd_reset();
						   shift +=  ul2uc.ul;	 //add to address 
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfpd(" %lX",shift);
//#endif
   
				  		   for(i=0; i<len; i++)
				  		   {
					 //   	write_buffer_char( embMsgRequest->Body(i+8), NO_START_WRITE_BUFFER);
			 			   	write_buffer_char2( embMsgRequest->Body(i+8), i+ shift);
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
				//	printEthLongHex(0x38);
//#ifdef TEST_USART2_REMOTE
//	printfp("\n\r command 38");
//	   printfpd("%02X",embMsgRequest->Type());
//#endif


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
 					case 0x08: // Запрос состояния
				  //	printf("\n\r>>");

						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++)
						{
					 	embMsgAns.SetBody(i,unStateBMD155.byte[i]);
					 //	embMsgAns.SetBody(i,(30 + (i%20)));
				  //	  	printf (".%02X",unStanStaD155.byte[i]);
						}
				//		printf("\n\r>>");

						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
						unStateBMD155.stateBMD155.demPI=0;
						unStateBMD155.stateBMD155.loopPI=0;
						unStateBMD155.stateBMD155.statePI=0;
						break;
					case 0x09:
				  //	printf("\n\r 0x09");
						 if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
	  							}
							if(embMsgRequest->Body(0)==2)
							{
  							}

						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
			//			printf("\n\r----> 0x0A");

						//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						ififembMsgRequest->Body(1)&0xC0)==0x80)
						{
	 				}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
	  						}
						break;
					case 0x0B:
			  //	   	printf("\n\r----> 0x0B");
						//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
						if((embMsgRequest->Body(1)&0xC0)==0x80)
						{
	   
						}
						if((embMsgRequest->Body(1)&0xC0)==0xC0)
						{
		 
						}
						break;
					case 0x10:
				   //	printf("\n\r 0x10");
							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
						 //	for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
						break;
					case 0x13:
				   //	 printf("\n\r 0x13");

							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
					   //		bt = (unsigned char far*)0x80000000;
							 bt = (unsigned char *)(NVRAM_BASE);


							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< from bukc

				   case 0x22:
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

   					case 0x23:
							embMsgAns.SetType(0x23);
							if(embMsgRequest->Body(0))// set
							{
							   SetAddrN( embMsgRequest->Body(1));
							}
						   						   
							embMsgAns.SetLength(2);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 	
						   	embMsgAns.SetBody(1, GetAddrN() & 0xff);
   							break;
//________________________________________________________________________PS
					default :
							embMsgAns.SetLength(0);
							embMsgAns.SetType(0x99);	
					
					 break;

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();
//#ifdef TEST_USART2_REMOTE
//		printfp("\n\rans:");
//	   embRS232S.Trans(0x31);
//	   embRS232S.Trans(0x32);
//	   embRS232S.Trans(0x33);
//	   embRS232S.Trans(0x34);
//	   embRS232S.Trans(0x35);
//	   embRS232S.Trans(0x31);

//	      printfpd(" %02X",embMsgAns.Type());

//      printfpd(" %d:",embMsgAns.FullSize());
//#endif

			  //		if(flagRequest == 1) 
					{
						embRS232S.Trans2(0x55);
						embRS232S.Trans2(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfpd(" %02X",embMsgAns.Type());
//#endif

							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
								case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
								case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
								case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
								default: embRS232S.Trans2(embMsgAns.body[i]);
							}
						}
						embRS232S.Trans2(0x55);
			 //			embRS232.EmptyReceive();
						embMsg232S.Init(); //090122
				   //		embRS232S.Init(38400); //110228 for test
						flagRequest = 0;
					}	//  == 1
				}
				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

}


//__________________________________________________usart2
#endif



#endif //PROG_PRM_PCH_N





//}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : none
* Comments         :
*    This routine is used to port embisr to be called from timer isr
*END*----------------------------------------------------------------------*/

extern "C" void time_notify_core(void)	// called frequency = 0,1 ms
 {
 //hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
// static unsigned long counter = 0;
//  	if(counter >= COUNTER_FOR_CORE)
// 	{ 
    embTimer.IsrXX();
//t    TimerCounter ++;
//t   	TimerCounter1 ++;
// 	timeres++; 
//	counter = 1;
#ifdef USART1_TRY_PDC
	timer++;
#endif //USART1_TRY_PDC
 //	}
 //	else
 // 	{
 // 	counter++;
 // 	}
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
//#ifdef IncEmbSerialMD34AVT
//  embSerialACT155.IsrXX();
//#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
   my_int_enable_irq0();
//__________________________________________
//hier can add start send command
//__________________________________________

}
//#ifdef PROG_BMD155

//__________________________________________________________________________________
struct EmbHittite
{
	unsigned bit0: 1;
	unsigned bit1: 1;
	unsigned bit2: 1;
	unsigned bit3: 1;
	unsigned bit4: 1;
	unsigned bit5: 1;
	unsigned bit6: 1;
	unsigned bit7: 1;
};

union UnEmbHittite
{
	EmbHittite eh;
	unsigned char b;
};

typedef	unsigned long long __int64;

//___________________________________________________________________________
unsigned char *Formula5nov(unsigned short f_in, unsigned char a_filtrPCh)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
  //	unsigned long f_sint;
  //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];

	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;

//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<1360)) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
//if((f_in>=20)&&(f_in<150)) ucFiltrVCh=0x38;
//if((f_in>=150)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=20)&&(f_in<170)) ucFiltrVCh=0xF8;
		if((f_in>=170)&&(f_in<260)) ucFiltrVCh=0xDC;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0xEA;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0xCE;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0xF1;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0xD5;	
		if((f_in>=960)&&(f_in<1180)) ucFiltrVCh=0xE3;		
		if((f_in>=1180)&&(f_in<1360)) ucFiltrVCh=0xC7;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0xF8;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0xEA;	
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0xDC;		
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0xF1;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0xCE;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0xA3;	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x25;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x67;

		// b[0] = ucKeyVCh + ucFiltrVCh;  
		 b[0] = ucFiltrVCh;  // bit 7 - PA25, bit 6 - PA20

		switch(a_filtrPCh) 
		{
			case e 00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}
		b[1] = 	b[1] + ucKeyVCh; // ucKeyVCh на PA16 и PA5
   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
		double Fdds0 =     195000000.0;//188000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
	 //	double Fdds_fl;
	 //	unsigned char M;
		unsigned char A;

		if((f_in>=20)&&(f_in<206))		Fdds0 = 238000000.0;
		if((f_in>=206)&&(f_in<251))		Fdds0 = 228000000.0;	
		if((f_in>=251)&&(f_in<400))		Fdds0 = 210000000.0;
		if((f_in>=400)&&(f_in<463))		Fdds0 = 250000000.0;
		if((f_in>=463)&&(f_in<550))		Fdds0 = 211000000.0;
		if((f_in>=550)&&(f_in<720))		Fdds0 = 240000000.0;	
		if((f_in>=720)&&(f_in<850))		Fdds0 = 214000000.0;		
		if((f_in>=850)&&(f_in<970))		Fdds0 = 245000000.0;
		if((f_in>=970)&&(f_in<1075))	Fdds0 = 217000000.0;
		if((f_in>=1075)&&(f_in<1230)) Fdds0 = 243700000.0;	
		if((f_in>=1230)&&(f_in<1300)) Fdds0 = 220000000.0;		
		if((f_in>=1300)&&(f_in<1360)) Fdds0 = 242000000.0;
		if((f_in>=1360)&&(f_in<1700)) Fdds0 = 212000000.0;		
		if((f_in>=1700)&&(f_in<3000)) Fdds0 = 220000000.0;

////////////////////////////////////
	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))  
		{
			f_tm = f_in + 1850;  // новомар 01/03/11 1850 
														// фсб 01/03/11 1840 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
			
		}
		else
		{
			f_tm = f_in + 550; // новомар 01/03/11 550
														// фсб 01/03/11 540 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
 return b;

}



//___________________________________________________________________________

/*
unsigned char * Formula4nov(unsigned short f_in, unsigned char a_filtrPCh)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
	unsigned long f_sint;
	unsigned long r03;
	unsigned long r04;
	static unsigned char b[16];

	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;

//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<1360)) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
//if((f_in>=20)&&(f_in<150)) ucFiltrVCh=0x38;
//if((f_in>=150)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=20)&&(f_in<170)) ucFiltrVCh=0xF8;
		if((f_in>=170)&&(f_in<260)) ucFiltrVCh=0xDC;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0xEA;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0xCE;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0xF1;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0xD5;	
		if((f_in>=960)&&(f_in<1180)) ucFiltrVCh=0xE3;		
		if((f_in>=1180)&&(f_in<1360)) ucFiltrVCh=0xC7;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0xF8;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0xEA;	
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0xDC;		
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0xF1;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0xCE;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0xA3;	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x25;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x67;

		// b[0] = ucKeyVCh + ucFiltrVCh;  
		 b[0] = ucFiltrVCh;  // bit 7 - PA25, bit 6 - PA20

		switch(a_filtrPCh) 
		{
			case 0x00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}
		b[1] = 	b[1] + ucKeyVCh; // ucKeyVCh на PA16 и PA5
   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
		double Fdds0 =     195000000.0;//188000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
		double Fdds_fl;
		unsigned char M;
		unsigned char A;
////////////////////////////////////
	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))  
		{
			Fdds0 =     211000000.0;
			f_tm = f_in + 1850;  // новомар 01/03/11 1850 
														// фсб 01/03/11 1840 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
			
		}
		else
		{
			f_tm = f_in + 550; // новомар 01/03/11 550
														// фсб 01/03/11 540 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
 return b;

}
*/
/*
unsigned char * Formula3nov(unsigned short f_in, unsigned char a_filtrPCh)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
	unsigned long f_sint;
	unsigned long r03;
	unsigned long r04;
	static unsigned char b[16];

	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;



		switch(a_filtrPCh) 
		{
			case 0x00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}
		b[1] = 	b[1] + ucKeyVCh; // ucKeyVCh на PA16 и PA5
   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
		double Fdds0 =     188000000.0;//190000000.0;
		double Fbase_ddsds 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
		double Fdds_fl;
		unsigned char M;
		unsigned char A;
////////////////////////////////////
	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))  
		{
			f_tm = f_in + 1850;  // новомар 01/03/11 1850 
														// фсб 01/03/11 1840 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
			
		}
		else
		{
			f_tm = f_in + 550; // новомар 01/03/11 550
														// фсб 01/03/11 540 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
	return b;
}

  */

//void CPrm485Dlg::Formula3nov(unsigned short f_in, unsigned char a_filtrPCh)

unsigned char * Formula3nov(unsigned short f_in, unsigned char a_filtrPCh)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
 //	unsigned long f_sint;
 //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];

 //	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;
   /*
//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<1360)) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
//if((f_in>=20)&&(f_in<150)) ucFiltrVCh=0x38;
//if((f_in>=150)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=20)&&(f_in<170)) ucFiltrVCh=0xF8;  //0x38;
		if((f_in>=170)&&(f_in<260)) ucFiltrVCh=0xDC; //0x1C;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0xEA; //0x2A;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0xCE; //0x0E;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0xF1; //0x31;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0xD5; //0x15; 	
	   //11027	if((f_in>=960)&&(f_in<1140)) ucFiltrVCh=0xE5; //0x23;	
	   	if((f_in>=960)&&(f_in<1140)) ucFiltrVCh=0xE3; //0x23; 110427			
		if((f_in>=1140)&&(f_in<1360)) ucFiltrVCh=0xC7; //0x07;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0xF8;  //0x38;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0xDC; //0x1C;
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0xEA; //0x2A;			
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0xCE; //0x0E;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0xF1; //0x31;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0x63;  //0x23; 	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x15;  //0x15;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x87;  //0x07;

			*/
//____________________________
//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<1360)) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
//if((f_in>=20)&&(f_in<150)) ucFiltrVCh=0x38;
//if((f_in>=150)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=20)&&(f_in<170)) ucFiltrVCh=0xF8;
		if((f_in>=170)&&(f_in<260)) ucFiltrVCh=0xDC;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0xEA;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0xCE;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0xF1;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0xD5;	
		if((f_in>=960)&&(f_in<1140)) ucFiltrVCh=0xE3;		
		if((f_in>=1140)&&(f_in<1360)) ucFiltrVCh=0xC7;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0xF8;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0xEA;	
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0xDC;		
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0xF1;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0xCE;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0xA3;	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x25;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x67;

		// b[0] = ucKeyVCh + ucFiltrVCh;  
	 //	 b[0] = ucFiltrVCh;  // bit 7 - PA25, bit 6 - PA20



//__________________

		// b[0] = ucKeyVCh + ucFiltrVCh;  
		 b[0] = ucFiltrVCh;  // bit 7 - PA25, bit 6 - PA20

		switch(a_filtrPCh) 
		{
			case 0x00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}
		b[1] = 	b[1] + ucKeyVCh; // ucKeyVCh на PA16 и PA5
   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
		double Fdds0 =     188000000.0;//190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
	 //	double Fdds_fl;
	 //	unsigned char M;
		unsigned char A;
////////////////////////////////////
	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))  
		{
			f_tm = f_in + 1850;  // новомар 01/03/11 1850 
														// фсб 01/03/11 1840 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A - 1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
			
		}
		else
		{
			f_tm = f_in + 550; // новомар 01/03/11 550
														// фсб 01/03/11 540 
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
	return b;
}


//void CPrm485Dlg::Formula2(unsigned short f_in, unsigned char a_filtrPCh)
unsigned char *Formula2(unsigned short f_in, unsigned char a_filtrPCh)

{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
 //	unsigned long f_sint;
  //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];

//	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;

//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<13636) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
		if((f_in>=20)&&(f_in<170)) ucFiltrVCh=0x38;
		if((f_in>=170)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0x2A;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0x0E;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0x31;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0x15;	
		if((f_in>=960)&&(f_in<1180)) ucFiltrVCh=0x23;		
		if((f_in>=1180)&&(f_in<1360)) ucFiltrVCh=0x07;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0x38;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0x2A;	
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0x1C;		
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0x31;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0x0E;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0x23;	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x15;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x07;

		b[0] = ucKeyVCh + ucFiltrVCh;  

		switch(a_filtrPCh) 
		{
			case 0x00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}

   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
		double Fdds0 =     188000000.0;//190000000.0;
   		double Fbase_dds = 700000000.0;
	//	double Fbase_dds = 100000000.0;		 //t100625
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
	  //	double Fdds_fl;
	 //	unsigned char M;
		unsigned char A;

////////////////////////////////////


	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))  
		{
			f_tm = f_in + 1900;
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
 //			__int64 u64base = 281474976710656;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
			
		}
		else
		{
			f_tm = f_in + 550;
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
			/// DDS
			df = Fdds/Fbase_dds;
   //			__int64 u64base = 281474976710656;
			__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
return b;
}

//_______________________________________________________________________
/*
unsigned char *Formula1(unsigned short f_in, unsigned char a_filtrPCh)
{

//	unsigned long f_in=f*10;
	unsigned long f_tm;
	unsigned long f_sint;
	unsigned long r03;
	unsigned long r04;
	static unsigned char b[12];
////////////// DDS /////////////////

//		unsigned char M;
//		unsigned char N;
//		unsigned char S;

////////////////////////////////////
	double dk = 2.980232239;
	double temp_dbl;

		unsigned char ucKeyVCh;
   //		unsigned char ucReject;
  //		unsigned char ucFiltrPCh;
		unsigned char ucFiltrVCh;

//  Диапазон 20-1360/1360-3000 Конт 38-37, РА5-РА4
		if((f_in>=20)&&(f_in<1360)) ucKeyVCh=0x80;
		if((f_in>=1360)&&(f_in<=3000)) ucKeyVCh=0x40;			
//  Фильтры  Конт 27-32, РА15-РА10
		if((f_in>=20)&&(f_in<150)) ucFiltrVCh=0x38;
		if((f_in>=150)&&(f_in<260)) ucFiltrVCh=0x1C;	
		if((f_in>=260)&&(f_in<360)) ucFiltrVCh=0x2A;		
		if((f_in>=360)&&(f_in<560)) ucFiltrVCh=0x0E;
		if((f_in>=560)&&(f_in<760)) ucFiltrVCh=0x31;
		if((f_in>=760)&&(f_in<960)) ucFiltrVCh=0x15;	
		if((f_in>=960)&&(f_in<1140)) ucFiltrVCh=0x23;		
		if((f_in>=1140)&&(f_in<1360)) ucFiltrVCh=0x07;

		if((f_in>=1360)&&(f_in<1560)) ucFiltrVCh=0x38;
		if((f_in>=1560)&&(f_in<1760)) ucFiltrVCh=0x2A;	
		if((f_in>=1760)&&(f_in<1960)) ucFiltrVCh=0x1C;		
		if((f_in>=1960)&&(f_in<2160)) ucFiltrVCh=0x31;
		if((f_in>=2160)&&(f_in<2360)) ucFiltrVCh=0x0E;
		if((f_in>=2360)&&(f_in<2560)) ucFiltrVCh=0x23;	
		if((f_in>=2560)&&(f_in<2760)) ucFiltrVCh=0x15;	
		if((f_in>=2760)&&(f_in<=3000)) ucFiltrVCh=0x07;

		b[0] = ucKeyVCh + ucFiltrVCh;  

		switch(a_filtrPCh) 
		{
			case 0x00: b[1] = 0x08; break; // 140/70 MHz
			case 0x01: b[1] = 0x06; break; // 150/2 MHz
			case 0x02: b[1] = 0x0D; break; // 150/8 MHz
			case 0x03: b[1] = 0x03; break; // 150/80 MHz
		}

   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);

	if((f_in>=20)&&(f_in<=3000))
	{
		if((f_in>=20)&&(f_in<1360))
		{
			f_tm = f_in + 1900;//550000;
			double Ftemp = f_tm * 1000000.0;

			f_sint = f_tm;			
			r03=f_sint/50;
			temp_dbl=f_sint%50;
			r04=(unsigned)(temp_dbl*335550.2); 
			

			b[2] = 0x80;
			b[3] = r03;
			b[4] = r04&0xFF;
			b[5] = (r04>>8)&0xFF;
			b[6] = (r04>>16)&0xFF;

		}
		else
		{
			f_tm = f_in + 550;//550000;
			double Ftemp = f_tm * 1000000.0;

			f_sint = f_tm;			
			r03=f_sint/50;
			temp_dbl=f_sint%50;
			r04=(unsigned)(temp_dbl*335550.2); 
			
			b[2] = 0x80;
			b[3] = r03;
			b[4] = r04&0xFF;
			b[5] = (r04>>8)&0xFF;
			b[6] = (r04>>16)&0xFF;
		}
	}

 return b;
}

 */


//_______________________________________________________________________




#ifdef PROG_PRM_PCH_C
 #ifdef PROG_PRM_PCH_S
 
#endif // PROG_PRM_PCH_S


extern "C" void PrintMessages()
{
 switch (message)
 {
  case 1 : printf("\n\rpower on channel 1");  break;
  case 2 : printf("\n\rpower on channel 2");  break;
  case 3 : printf("\n\rpower on channel 3");  break;
  default : break;

 }
 if(message)  printf("\n\r m = %d" , message);
 message = 0;
}




extern "C" void SetPower(unsigned char channel)
{
// message = channel;
switch(channel)
{
 case 1:  outportb(POWER_PORT, CH1_MASK);  break;
 case 2:  outportb(POWER_PORT, CH2_MASK);  break;
 case 3:  outportb(POWER_PORT, CH3_MASK);  break;
#ifdef PROG_PRM_PCH_S
 case 4:  outportb(POWER_PORT2, CH4_MASK);  break;
 case 5:  outportb(POWER_PORT2, CH5_MASK);  break;
 case 6:  outportb(POWER_PORT2, CH6_MASK);  break;
#endif //PROG_PRM_PCH_S
 default : break;
}
}

#endif 	PROG_PRM_PCH_C



#ifdef 	PROG_PRM_PCH_L

extern "C" void RestoreAttRPU(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:     emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  val;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val;
	   //		SetAttRPU1();


 	   		break;
case 2:	    emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  val;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val;
	   //		SetAttRPU2();

 	   		break;
case 3:	    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  val;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val;
	  //		SetAttRPU3();

 	   		break;
case 4:     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  val;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val;
	   //		SetAttRPU1();


 	   		break;
case 5:	    emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  val;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val;
	   //		SetAttRPU2();

 	   		break;
case 6:	    emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  val;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val;
	  //		SetAttRPU3();

 	   		break;

default : : reak;
}
}


extern "C" void RestoreFreq(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
		   break;
case 2:	   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
		   break;
case 3:	   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
		   break;
default :  break;
}
}

extern "C" void RestoreAtt(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:     emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  val;
   	   //		emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 2:	    emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 3:	    emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
 	   		break;
default :  break;
}
}

extern "C" unsigned long GetFreq(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
case 2:    return emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
case 3:    return emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
default :  return 0;
}
}

extern "C" unsigned long GetAtt(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;
case 2:    return emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;
case 3:    return emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;
default :  return 0;
}
}

extern "C" unsigned long GetAttRPU(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
case 2:    return emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt;
case 3:    return emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt;
case 4:    return emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt;
case 5:    return emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt;
case 6:    return emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt;


default :  return 0;
}
}


extern "C" void SetNeedWriteDevId(void)
{
#ifdef	 TEST_PRM_PCH_N_2
printf("SetNeedWriteDevId");

#endif

  NeedWriteID = 1;
}

extern "C" void ClearNeedWriteDevId(void)
{
#ifdef	 TEST_PRM_PCH_N_2
//printf("ClearNeedWriteDevId");

#endif

  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{
//static unsigned long DelayWriteTime;

#ifdef PRM_N_KEEP_FREQ

  if(DelayWriteTime > time1)
  {

     DelayWriteTime = time1;
  }

  if((time1 - DelayWriteTime) < DELAY_TIME_TO_WRITE)
  {
   return 0;
   }
  #endif



  return NeedWriteID;
}

extern "C" void MakeKeepTest(void)
{
    printf("\n\r freq1 = %lX att1 = %lX", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);
    printf("\n\r freq2 = %lX att2 = %lX", emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt);
    printf("\n\r freq3 = %lX att3 = %lX", emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt);
    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = 0x12345671;
    emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = 0x12345672;
    emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ  = 0x12345673;
    emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt  = 0x12345674;
    emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ  = 0x12345675;
    emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt   = 0x12345676;
	SetNeedWriteDevId();
}




#endif // PROG_PRM_PCH_L




void SetSynt(unsigned char * b)
{
AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
unsigned long mask;

piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//mask = 	MASK_BIT_4 | MASK_BIT_5 | MASK_BIT_10 |	MASK_BIT_11
mask = 	MASK_BIT_3 | MASK_BIT_6 | MASK_BIT_7 |	MASK_BIT_8		 
 			| MASK_BIT_10;  

piob_ptr->CODR = mask; 

mask = 0;

//mask =  MASK_BIT_6 | MASK_BIT_7 | MASK_BIT_8 | MASK_BIT_9; 

//pioa_ptr->SODR = mask; 

mask = 0;

if(*b & MASK_BIT_0) mask |= MASK_BIT_3;
if(*b & MASK_BIT_1) mask |= MASK_BIT_6;
if(*b & MASK_BIT_2) mask |= MASK_BIT_7;
if(*b & MASK_BIT_3) mask |= MASK_BIT_8;
if(*b & MASK_BIT_4) mask |= MASK_BIT_10;

piob_ptr->SODR = mask;
}



#ifdef PROG_PRM_PCH_N

void SetUpr(unsigned char * b)
{
AT91RM9200_PIO_REG_STRUCT_PTR  pioa_ptr;
unsigned long mask;

pioa_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;

//mask = 	MASK_BIT_4 | MASK_BIT_5 | MASK_BIT_10 |	MASK_BIT_11
/*
mask = 	MASK_BIT_16 | MASK_BIT_5 | MASK_BIT_10 |	MASK_BIT_11		 //4 -> 16
 			| MASK_BIT_12 | MASK_BIT_13 | MASK_BIT_14 | MASK_BIT_15;  

*/

mask = 	 MASK_BIT_10 |	MASK_BIT_11	 | MASK_BIT_12 | MASK_BIT_13 | MASK_BIT_14 | MASK_BIT_15 | MASK_BIT_20 | MASK_BIT_24;  



pioa_ptr->CODR = mask; 

mask = 0;

//mask =  MASK_BIT_6 | MASK_BIT_7 | MASK_BIT_8 | MASK_BIT_9; 
mask =  MASK_BIT_6 | MASK_BIT_7 | MASK_BIT_8 | MASK_BIT_9 | MASK_BIT_16 | MASK_BIT_5; 

pioa_ptr->SODR = mask; 

mask = 0;

if(*b & MASK_BIT_0) mask |= MASK_BIT_15;
if(*b & MASK_BIT_1) mask |= MASK_BIT_14;
if(*b & MASK_BIT_2) mask |= MASK_BIT_13;
if(*b & MASK_BIT_3) mask |= MASK_BIT_12;
if(*b & MASK_BIT_4) mask |= MASK_BIT_11;
if(*b & MASK_BIT_5) mask |= MASK_BIT_10;
if(*b & MASK_BIT_6) mask |= MASK_BIT_20;//MASK_BIT_5;	   //20
//if(*b & MASK_BIT_7) mask |= MASK_BIT_4;  //4->16
if(*b & MASK_BIT_7) mask |= MASK_BIT_24;//MASK_BIT_16;	 //25

pioa_ptr->SODR = mask;
//_______________________________________________
mask = 0;
b++;
if(*b & MASK_BIT_0) mask |= MASK_BIT_9;
if(*b & MASK_BIT_1) mask |= MASK_BIT_8;
if(*b & MASK_BIT_2) mask |= MASK_BIT_7;
if(*b & MASK_BIT_3) mask |= MASK_BIT_6;
if(*b & MASK_BIT_6) mask |= MASK_BIT_16;
if(*b & MASK_BIT_7) mask |= MASK_BIT_5;
//______________________________________________

pioa_ptr->CODR = mask;
}






void SetFreqN()
{

unsigned char * pData;
static unsigned char DataDDS[LEN_DATA_DDS];//

#ifdef PRM_N_KEEP_FREQ
DelayWriteTime = time1;
#endif
//printf("\n\r SetFreqN");
//unsigned char * b = Formula0(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ ,Rej,Filtr);
//unsigned char * b = Formula1(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ ,Filtr);
//unsigned char * b = Formula2(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ ,Filtr);
//unsigned char * b = Formula3nov(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ ,Filtr);
unsigned char * b = Formula5nov(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ ,Filtr);
//					Formula3nov
			   /* prm_pch_N_1!!!!

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FORMULA_LEN); //em
			    for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , b[i]);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
				*/



		  SetUpr(b); //att


     //     for(long i = 0; i < START_LEN; i ++)
	   //		{
			  b++;
			  b++;
		  SetSynt(b); //prm_pch_n_2 : synt	   //was only b

#ifdef	 TEST_PRM_PCH_N_2
		   printf("\n\r Synt : 0x%02X", *b );
		   	  
#endif

________________________________________ Set command and address
// #ifndef	 TEST_PRM_PCH_N_2


				b--;
				*b++ = 0x61;
				*b = 0xAB; //position to synt
				b--;   //st to 0x61
// #endif
//________________________________________



//________________________________________

//#ifdef	 TEST_PRM_PCH_N_2

//unsigned char * pData;
//static unsigned char DataDDS[LEN_DATA_DDS];//
/*
pData = DataDDS;
// *pData++ = 1;   *pData++ = 0xAB;	 *pData = 0x45; b++;  b++;
*pData++ = 1;   *pData++ = 0xAB;	 *pData =  b++;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAA;	 *pData = *b++;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA9;	 *pData = *b++;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA8;	 *pData = *b++;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA7;	 *pData = *b++;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA6;	 *pData = *b;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
 */

//#else





		  SendToDDS(SENDED_DDS_FREQ_LEN, (unsigned long)b);

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);


//#endif


	 	 //	}


	 //  		printf("\n\r");
	  //		printf(" %02X", *b);

/*
//prm_pch_n_2 - not need!!

			for(i = 0; i < MESSAGE_LEN; i ++)
			{
	  //	 	printf(" %02X", *b);
	  	 	  SSC1_BUFFER[i] = *b++;
	  	 	  //		  SSC1_BUFFER[i] = 0xA0 + i+1;		 //t
			}
			need_to_sended =  MESSAGE_LEN;

   		OperateSynt(0);
   */

}


void SetFreqN80(unsigned char b0, unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4)
{
 
 	  SSC1_BUFFER[0] = b0;
      SSC1_BUFFER[1] = b1;
	  SSC1_BUFFER[2] = b2;
	  SSC1_BUFFER[3] = b3;
	  SSC1_BUFFER[4] = b4;
		   
			need_to_sended =  MESSAGE_LEN;
			OperateSynt(0);
}


void SetAttN()	  //now it is att1
{
		   /*  prm_pch_1

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
		   */

 unsigned long maskb = 0l;
 AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
  piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 maskb =  MASK_BIT_12 | MASK_BIT_13 | MASK_BIT_14 | MASK_BIT_15;
 piob_ptr->SODR = maskb;

maskb = 0;

if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt	& MASK_BIT_0) maskb |= MASK_BIT_12;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt	& MASK_BIT_1) maskb |= MASK_BIT_13;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt	& MASK_BIT_2) maskb |= MASK_BIT_14;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt	& MASK_BIT_3) maskb |= MASK_BIT_15;
piob_ptr->CODR = maskb;
 
}

void SetAtt7N()
{
		   /*  prm_pch_1

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
		   */

 unsigned long maskb = 0l;
 AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
  piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 maskb =  MASK_BIT_16 | MASK_BIT_17 | MASK_BIT_18 | MASK_BIT_19 | MASK_BIT_22;
 piob_ptr->SODR = maskb;

maskb = 0;

if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2	& MASK_BIT_0) maskb |= MASK_BIT_16;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2	& MASK_BIT_1) maskb |= MASK_BIT_17;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2	& MASK_BIT_2) maskb |= MASK_BIT_18;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2	& MASK_BIT_3) maskb |= MASK_BIT_19;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2	& MASK_BIT_4) maskb |= MASK_BIT_22;

piob_ptr->CODR = maskb;
}

void SetAtt8N()
{
		   /*  prm_pch_1

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
		   */

 unsigned long maska = 0l;
 AT91RM9200_PIO_REG_STRUCT_PTR  pioa_ptr;
  pioa_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;

//110303 maska =  MASK_BIT_24 | MASK_BIT_27 | MASK_BIT_28 | MASK_BIT_29 ;
 maska =  MASK_BIT_25 | MASK_BIT_27 | MASK_BIT_28 | MASK_BIT_29 ;
 pioa_ptr->SODR = maska;

maska = 0;

// 110303 if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3	& MASK_BIT_0) maska |= MASK_BIT_24;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3	& MASK_BIT_0) maska |= MASK_BIT_25;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3	& MASK_BIT_1) maska |= MASK_BIT_27;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3	& MASK_BIT_2) maska |= MASK_BIT_28;
if(emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3	& MASK_BIT_3) maska |= MASK_BIT_29;


pioa_ptr->CODR = maska;
}









unsigned char GetLevN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.signalLevel;
}

unsigned char GetAttN(void)
{
//  return  emb5StatusReciever1.emb5statusreciever.stepAtt;
		  
  return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;
}

unsigned char GetAtt2N(void)
{
//  return  emb5StatusReciever1.emb5statusreciever.stepAtt2;

  return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt2;
}

unsigned char GetAtt3N(void)
{
//  return  emb5StatusReciever1.emb5statusreciever.stepAtt3;

  return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt3;
}








unsigned short GetFreqN(void)
{
  return  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
}

unsigned short GetLockN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.lock;
}

unsigned char GetAlarmN(void)
{
 if(fl1)
 return 0;
 else return 1;
}

void TransN(unsigned char send)
{
  embRS485.Trans(send);
}




#endif	 //PROG_PRM_PCH_N

unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1;     
  unsigned int   merc, zerc,up0erc,up1erc;
  unsigned char rup0, rup0o,  rup1, rup1o;
  unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;


void test_PU37()
{
 }
/*
extern "C" void  RestoreParameters()
{

   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ1_ADDR);
   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ2_ADDR);
   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT1_ADDR);
//091104   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT2_ADDR);
//091104   emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT1_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.e.e5commandrpusetatt.stepAtt;
  //	 SetAttRPU1();
   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT2_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU2();


#ifdef PRM_PCH_THREE_LINES
   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ3_ADDR);
   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT3_ADDR);
//091104   emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT3_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
 //	 SetAttRPU3();


#endif //PRM_PCH_THREE_LINES


#ifdef PRM_PCH_SIX_LINES
//_______________________________________________________________________________________________
   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ4_ADDR);
   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT4_ADDR);
   emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT4_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt;
   //	 SetAttRPU4();

   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ5_ADDR);
   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT5_ADDR);
   emb5StatusReciever5.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT5_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU5();


   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ6_ADDR);
   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT6_ADDR);
   emb5StatusReciever6.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT6_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU6();

//_______________________________________________________________________________________________
#endif //PRM_PCH_SIX_LINES






}

*/
 






