


//#include "menu1.h"

#include "start.h"
#include "hello7.h"
#include "embisr.h"
//#include "stdlib.h"

//_____________________
#include <mqx.h>
#include <bsp.h>
//______________________________________
#include "PVG610_API.h"

//______________________________________
#include "menu1.h"

#include "Temperature.cpp"
#include "pvg710.cpp"
//#include "md100se.cpp"
#include "md100se2.cpp"

 /*
#define LEN_MD100SE	   (77)


struct MD100SE
{

unsigned char 	ConfigFile;
unsigned char 	ModForSS;
unsigned char 	ModEth;
unsigned char 	NamesConfigFiles;
unsigned char 	LoadVariants;
unsigned char 	LoadVariantsSet;
unsigned char   SaveVariants;
unsigned char   SaveVariantsSet;
// CurReadedAnyCofig; //number of readed anyconfig to set this variable - filled readanyconfig for reading

unsigned char   MRfOut;
unsigned char  MOutLev0;


//__10

unsigned char  MOutLev1;

unsigned char MTDRate0;
unsigned char MTDRate1;
unsigned char MTDRate2;
unsigned char MTDRate3;

//__15

unsigned char MRDRate0;
unsigned char MRDRate1;
unsigned char MRDRate2;
unsigned char MRDRate3;


unsigned char MTFreq0;
unsigned char MTFreq1;
unsigned char MTFreq2;
unsigned char MTFreq3;

//__23

unsigned char MRFreq0;
unsigned char MRFreq1;
unsigned char MRFreq2;
unsigned char MRFreq3;


unsigned char MTModul;
unsigned char MRModul;
 
unsigned char MTCode0;
unsigned char MTCode1;

//__31
unsigned char MRCode0;
unsigned char MRCode1;

unsigned char MDemod;

unsigned char MEthMode;


//__35

unsigned char MEthPause;
unsigned char MEthctl;

unsigned char MEthMaxF0;
unsigned char MEthMaxF1;
unsigned char MEthVlanP;

//__40

unsigned char MEbN00;
unsigned char MEbN01;
unsigned char MEbN02;
unsigned char MEbN03;

//MDataI MTEbN0;
unsigned char MTEbN00;
unsigned char MTEbN01;
unsigned char MTEbN02;
unsigned char MTEbN03;

unsigned char MBER0;
unsigned char MBER1;
unsigned char MBER2;
unsigned char MBER3;

//_-52

//MDataI MTBER;
unsigned char MTBER0;
unsigned char MTBER1;
unsigned char MTBER2;
unsigned char MTBER3;

unsigned char MTBERE;



unsigned char MAGC0;
unsigned char MAGC1;
unsigned char MAGC2;
unsigned char MAGC3;

unsigned char MSweep0;
unsigned char MSweep1;
unsigned char MSweep2;
unsigned char MSweep3;

//__65

unsigned char MEthModeI;	  //indikation

unsigned char MEthSend0;
unsigned char MEthSend1;
unsigned char MEthSend2;
unsigned char MEthSend3;

//__70

unsigned char MEthReceived0;
unsigned char MEthReceived1;
unsigned char MEthReceived2;
unsigned char MEthReceived3;

unsigned char MIfLoop;
unsigned char MUnModul;

unsigned char MACMM;
 };

union UMD100SE
{
   MD100SE md100se;
   unsigned char byte[LEN_MD100SE];
};

  */
UMD100SE dev1;





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



//double KoefErrors[MODEM_QUANTITY << 1];


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

void t2ms(unsigned long d)
{
 delay_mcs(d * 2000l);
}
unsigned char NeedWriteID;
extern "C" void SetNeedWriteDevId(void)
{
//printf("\n\rSetWriteDevId");

  NeedWriteID = 1;

#ifdef PRM_L_KEEP_FREQ
DelayWriteTime = time1;
#endif

}

extern "C" void ClearNeedWriteDevId(void)
{
  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{

#ifdef PRM_L_KEEP_FREQ

  if(DelayWriteTime > time1)
  {

     DelayWriteTime = time1;
  }

  if((time1 - DelayWriteTime) < DELAY_TIME_TO_WRITE)
  {
   return 0;
   }
  #endif
 // if(NeedWriteID) printf("\n\rWriteDevId"); //t


  return NeedWriteID;
}




struct Protection{
	unsigned long   ProtTx     :2;      	   // 
    unsigned long   PhyIDTx    :5;      	   //  7
    unsigned long   CopyAcm    :1;      	   //  8
	unsigned long   ProtRx     :2;      	   //  10
    unsigned long   PhyIDRx    :5;      	   //  15
    unsigned long   ProtRxf    :2;      	   //  17
	unsigned long   SustemPrEn :1;      	   //  18
	unsigned long   flagchtx   :1;     		   //need load tx
	unsigned long   flagchrx   :1;   		  //need load rx
	unsigned long   flagchrxf  :1;     		   //need load rx forse
	unsigned long   reserved   :11;     


};

union uProtection{
   Protection 		protection;
   unsigned long 	protword;
};


uProtection uProt[MODEM_QUANTITY<<1];

unsigned long GetProt(unsigned char provnum)
{
 if(provnum < (MODEM_QUANTITY<<1)) return  uProt[provnum].protword;
 else return 99; 
}

void SetProt(unsigned char provnum, unsigned long value)
{
  if(provnum < (MODEM_QUANTITY<<1)) uProt[provnum].protword = value;
}




#define ID_CORR	 (1) //to do not use 0 as Phy ID - this value - ignored
//#define ID_CORR	 (0) //to do not use 0 as Phy ID - this value - ignored

unsigned long NeedParseFalgs;

void StartProtection()	 //maked from test mode 0xA3 to write to flash all protection  parameters to zero
{

  for(long i = 0; i < (MODEM_QUANTITY<<1); i++)
  {
//  uProt[i].protword = 0;  //
  uProt[i].protword = 1;  // TX - working
  }
  SetNeedWriteDevId(); //after this need make manually restart

}


extern "C" void SetNeedInitAllProt(void)
{
 unsigned long fl = 1l; 
 //__________________________init	
    for(unsigned i = 0l; i < (MODEM_QUANTITY<<1); i++)	
	{
	 uProt[i].protword = 0;
	 SetProtObj(i, uProt[i].protword);
	}
//___________________________init	


#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  for(i = 0; i < (MODEM_QUANTITY<<1); i++)	//
#else
  for(i = 0; i < (MODEM_QUANTITY<<1); i+=2l)	//
#endif
  {
  uProt[i].protection.flagchtx = 1;  //set all flags to load all
  uProt[i].protection.flagchrx = 1;
  uProt[i].protection.flagchrxf = 0;
  uProt[i].protection.PhyIDTx  = i; //i;	  //test
  uProt[i].protection.PhyIDRx  = i; //test

  uProt[i].protection.CopyAcm = 1; //t 110511
// uProt[i].protection.CopyAcm = 0; //130226


  if(protection_mode == MODE_N_PLUS_1)
  {
  if(i != (currentrezerv<<1) )
   {
	 uProt[i].protection.ProtRx = 1;
	 uProt[i].protection.ProtTx = 1;
   }
   else
   {
    uProt[i].protection.ProtRx = 2;
	uProt[i].protection.ProtTx = 2;

   }
  }
  else if(protection_mode == MODE_1_PLUS_1)
  {
   if(!(i % 2))
   {
	 uProt[i].protection.ProtRx = 1;	  //working
	 uProt[i].protection.ProtTx = 1;
   }
   else
   {
	 uProt[i].protection.ProtRx = 2;	   //protection
	 uProt[i].protection.ProtTx = 2;
   }
  }
	SetProtObj(i, uProt[i].protword);
	NeedParseFalgs |= fl;
   	fl <<= 1;
  }
//  printf("\n\r NeedParseflags : %X", NeedParseFalgs);
}

extern "C" void SetNeedInitAllProti(unsigned char mod)
{
//printfp("\n\r SetNeedInitAllProti");
//printfpd(" %d", mod);

 unsigned long fl = 1l; 
 unsigned char i;
//#ifndef PROG_BMDN4	  //120202
 i = mod << 1;
//#else

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  for(i = mod << 1; i <= ((mod << 1) + 1); i++)	//temporary all load   
#else
  for(i = mod << 1; i <= ((mod << 1)); i+=2)	//temporary all load   
#endif
  {
//#endif
  uProt[i].protection.flagchtx = 1;  //set all flags to load all
  uProt[i].protection.flagchrx = 1;
  uProt[i].protection.flagchrxf = 0;
  uProt[i].protection.PhyIDTx  = mod << 1;
  uProt[i].protection.PhyIDRx  = mod << 1;
  uProt[i].protection.CopyAcm = 1; //t 110511



  if(protection_mode == MODE_N_PLUS_1)
  {
  if(i != (currentrezerv<<1) )
   {
	 uProt[i].protection.ProtRx = 1;
	 uProt[i].protection.ProtTx = 1;
   }
  }	   //120202
  else if(protection_mode == MODE_1_PLUS_1)
  {
   	//  printfp("\n\r1+1");

   if(!((i+2) % 2))
   {
  // printfpd("\n\r 0 %d",i);

	 uProt[i].protection.ProtRx = 1;
	 uProt[i].protection.ProtTx = 1;
   }
   else
   {
  //   printfpd("\n\r 1 %d ", i);

	 uProt[i].protection.ProtRx = 2;
	 uProt[i].protection.ProtTx = 2;
   }
  }	  //else
 // }
   
    SetProtObj(i, uProt[i].protword);
	fl <<= i;
	NeedParseFalgs |= fl;


  }	//for

}

extern "C" void SetNeedInitAllProti2only(unsigned char mod)
{
//printfp("\n\r SetNeedInitAllProti");
//printfpd(" %d", mod);

 unsigned long fl = 1l; 
 unsigned char i;
//#ifndef PROG_BMDN4	  //120202
 i = mod << 1;
//#else

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  for(i = (mod << 1)+1; i <= ((mod << 1) + 1); i++)	//temporary all load   
#else
  for(i = mod << 1; i <= ((mod << 1)); i+=2)	//temporary all load   
#endif
  {
//#endif
  uProt[i].protection.flagchtx = 1;  //set all flags to load all
  uProt[i].protection.flagchrx = 1;
  uProt[i].protection.flagchrxf = 0;
  uProt[i].protection.PhyIDTx  = mod << 1;
  uProt[i].protection.PhyIDRx  = mod << 1;
  uProt[i].protection.CopyAcm = 1; //t 110511



  if(protection_mode == MODE_N_PLUS_1)
  {
  if(i != (currentrezerv<<1) )
   {
	 uProt[i].protection.ProtRx = 1;
	 uProt[i].protection.ProtTx = 1;
   }
  }	   //120202
  else if(protection_mode == MODE_1_PLUS_1)
  {
   	//  printfp("\n\r1+1");

   if(!((i+2) % 2))
   {
  // printfpd("\n\r 0 %d",i);

	 uProt[i].protection.ProtRx = 1;
	 uProt[i].protection.ProtTx = 1;
   }
   else
   {
  //   printfpd("\n\r 1 %d ", i);

	 uProt[i].protection.ProtRx = 2;
	 uProt[i].protection.ProtTx = 2;
   }
  }	  //else
 // }
   
    SetProtObj(i, uProt[i].protword);
	fl <<= i;
	NeedParseFalgs |= fl;


  }	//for

}





void SetParseFlags(unsigned char provnum)
{

//printfp("\n\r SetParseFlags");
//printfpd(" %d", provnum);
 unsigned long tmp = 1l;

  if(provnum >= (MODEM_QUANTITY<<1)) return; 
   NeedParseFalgs |= (tmp << provnum);
}

void CheckParseFlags()
{
//printfp("\n\r CheckParseFlags");
//printfpd(": %X", NeedParseFalgs);
 unsigned long fl = 1l; 
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  for(long i = 0; i < (MODEM_QUANTITY<<1); i++)
  {
	if(NeedParseFalgs & fl)
	{
  	  ParseFlags(i);
	  NeedParseFalgs &= ~fl;
	}

	fl <<= 1;
  }
#else

for(long i = 0; i < (MODEM_QUANTITY); i++)
  {
	if(NeedParseFalgs & fl)
	{
  	  ParseFlags(i<<1);
	  NeedParseFalgs &= ~fl;
	}

	fl <<= 1;
  }


#endif


}

unsigned char ParseFlags(unsigned char provnum)
{
unsigned char ret = 99;
unsigned char mod =  provnum >> 1;
//unsigned char nr = 0;

 if(provnum >= (MODEM_QUANTITY<<1)) return 99; 
   if(uProt[provnum].protection.flagchtx)
   {

//  printfp(" tx");
  // nr = 1;
	  uProt[provnum].protection.flagchtx = 0;
    if(ModemIsUsed(mod))  
 {
  //nr = 1;
//  printf("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X", provnum,uProt[provnum].protection.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm);     
     ret =  PVG610_API_ProtectionTxModeSet (provnum,
                                                      0,  //modem - not used
                                                      uProt[provnum].protection.ProtTx,
                                                      uProt[provnum].protection.PhyIDTx + ID_CORR,
													  uProt[provnum].protection.CopyAcm);
 }
   }

  if(uProt[provnum].protection.flagchrx)
   {
	  uProt[provnum].protection.flagchrx = 0;
  //	     printf("\n\r	flagchrx mod :%d" , mod);

	 if(ModemIsUsed(mod))
	 {
   //	  nr = 1; 
     ret =  PVG610_API_ProtectionRxModeSet(provnum,
                                            0,  //modem - not used
                                                      uProt[provnum].protection.ProtRx,
                                                      uProt[provnum].protection.PhyIDRx + ID_CORR);
	  }
   }

 if(uProt[provnum].protection.flagchrxf)
   {
	  uProt[provnum].protection.flagchrxf = 0;
   if(ModemIsUsed(mod)) 
	   {
        ret =  PVG610_API_ProtectionRxForceSet(provnum,
                                            0,  //modem - not used
                                            uProt[provnum].protection.ProtRxf);
	 }
   }
 return ret;
}

//__________________________________________________________pr

unsigned char ProtectionOff(unsigned char provnum)
{

//printfp("\n\r ProtectionOff");
//printfpd(" %d", provnum);
//printfpd(" %X",uProt[provnum].protword);


unsigned char ret = 99;
unsigned char mod =  provnum >> 1;
 if(provnum >= (MODEM_QUANTITY<<1)) return 99; 

    if(ModemIsUsed(mod))  
 {
     ret =  PVG610_API_ProtectionTxModeSet (provnum,
                                                      0,  //modem - not used
                                                      0,//uProt[provnum].protection.ProtTx,
                                                      uProt[provnum].protection.PhyIDTx + ID_CORR,
							
													  uProt[provnum].protection.CopyAcm);
#ifndef USART0_TRY_PDC_1T	
 if(GetTestMode() == 0x5A)
 {	
 // printfp("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X...%d", 0.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm, ret);     
 }
#endif
 }
	  uProt[provnum].protection.flagchrx = 0;
	 if(ModemIsUsed(mod))
	 {
     ret =  PVG610_API_ProtectionRxModeSet(provnum,
                                            0,  //modem - not used
                                                      0,
                                                      uProt[provnum].protection.PhyIDRx + ID_CORR);
#ifndef USART0_TRY_PDC_1T 
 if(GetTestMode() == 0x5A)
 {	
  //   printfp("\n\r PVG610_API_ProtectionRxModeSet %d %X %X ...%d", 0, uProt[provnum].protection.PhyIDRx + ID_CORR,   ret);     
 }
#endif
	  }
 return ret;
}

unsigned char ProtectionOnWorking(unsigned char provnum)
{

//printfp("\n\r ProtectionOn");
//printfpd(" %d", provnum);
//printfpd(" %X",uProt[provnum].protword);


unsigned char ret = 99;
unsigned char mod =  provnum >> 1;
//unsigned char nr = 0;

 if(provnum >= (MODEM_QUANTITY<<1)) return 99; 

    if(ModemIsUsed(mod))  
 {
     ret =  PVG610_API_ProtectionTxModeSet (provnum,
                                                      0,  //modem - not used
                                                      1,//uProt[provnum].protection.ProtTx,
                                                      uProt[provnum].protection.PhyIDTx + ID_CORR,
													  uProt[provnum].protection.CopyAcm);
#ifndef USART0_TRY_PDC_1T	
 if(GetTestMode() == 0x5A)
 {	
 // printf("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X...%d", 1.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm, ret);     
 }
#endif
 }
	  uProt[provnum].protection.flagchrx = 0;
  //	     printf("\n\r	flagchrx mod :%d" , mod);

	 if(ModemIsUsed(mod))
	 {
      ret =  PVG610_API_ProtectionRxModeSet(provnum,
                                            0,  //modem - not used
                                                      1,
                                                      uProt[provnum].protection.PhyIDRx + ID_CORR);
#ifndef USART0_TRY_PDC_1T 
  if(GetTestMode() == 0x5A)
 {	
  //   printf("\n\r PVG610_API_ProtectionRxModeSet %d %X %X ...%d", 1, uProt[provnum].protection.PhyIDRx + ID_CORR,   ret);     
 }
#endif
	  }
 return ret;
}

unsigned char ProtectionOnProtection(unsigned char provnum)
{

//printfp("\n\r ProtectionOn");
//printfpd(" %d", provnum);
//printfpd(" %X",uProt[provnum].protword);


unsigned char ret = 99;
unsigned char mod =  provnum >> 1;
 if(provnum >= (MODEM_QUANTITY<<1)) return 99; 

    if(ModemIsUsed(mod))  
 {
  //nr = 1;
//  printf("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X", provnum,uProt[provnum].protection.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm);     
     ret =  PVG610_API_ProtectionTxModeSet (provnum,
                                                      0,  //modem - not used
                                                      2,//uProt[provnum].protection.ProtTx,
                                                      uProt[provnum].protection.PhyIDTx + ID_CORR,
													  uProt[provnum].protection.CopyAcm);
#ifndef USART0_TRY_PDC_1T	
  if(GetTestMode() == 0x5A)
 {	
 // printf("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X...%d", 2.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm, ret);     
 }
#endif
 }

	  uProt[provnum].protection.flagchrx = 0;
  //	     printf("\n\r	flagchrx mod :%d" , mod);

	 if(ModemIsUsed(mod))
	 {
   //	  nr = 1; 
     ret =  PVG610_API_ProtectionRxModeSet(provnum,
                                            0,  //modem - not used
                                                      2,
                                                      uProt[provnum].protection.PhyIDRx + ID_CORR);
#ifndef USART0_TRY_PDC_1T 
  if(GetTestMode() == 0x5A)
 {	
     printf("\n\r PVG610_API_ProtectionRxModeSet %d %X %X ...%d", 2, uProt[provnum].protection.PhyIDRx + ID_CORR,   ret);     
 }
#endif
	  }
 return ret;
}

void ProtectionOn(unsigned char provnum)
{
 if(!(provnum %2))
 {
	ProtectionOnWorking(provnum);
 }
 else
 {
   ProtectionOnProtection(provnum);
 }
}

void ChProt(unsigned char deviceindex, unsigned char prot)
{
  if(prot)
  {
   ProtectionOn(deviceindex);
  }
  else
  {
   ProtectionOff(deviceindex);

  }

}

//__________________________________________________________pr

#define ulevelsn15503_SIZE	  (58)	//summ of bytes LevelSN15503

struct LevelSN15503
{
unsigned short absoluteMse[9];
unsigned short normalizedMse[9];
unsigned short radialMse[9];
unsigned char reserv[4];
};

union uLevelSN15503
{
  LevelSN15503 levelsn15503;
  unsigned char byte[ulevelsn15503_SIZE];
};

#define uerrsn15503work_SIZE	  (94)	 //sum of bytes Errsn15503work

struct ErrSN15503Work
{
  unsigned long fecBlockCounter[9];//
  unsigned long fecUncorrectedBlock[9];	
  unsigned short counterSlip[9];
  unsigned char reserv[2];
  unsigned char lock1;
  unsigned char lock2;
 // unsigned char reserv[2];
};

union uErrSN15503Work
{
   ErrSN15503Work errsn15303work;
   unsigned char byte[uerrsn15503work_SIZE];
};

//#define TXT_REAL_LEN   (MAX_SIZE_TEXT_FILE - FULL_HEADER_SIZE - 4)
//#define TXT_CUR_REAL_LEN   (104)
//#define TXT_REAL_LEN_100  (MAX_SIZE_TEXT_FILE - FULL_HEADER_SIZE - 4)

unsigned char power1, power2;  
unsigned char crcud;

 /*

struct Mode100SE
{
 unsigned char mode;
 unsigned char code_type;

 unsigned char coderate0;
 unsigned char coderate1;

 unsigned char datarate0;
 unsigned char datarate1;
 unsigned char datarate2;
 unsigned char datarate3;

 unsigned char  e1_numb;

 unsigned char rateEth0;
 unsigned char rateEth1;
 unsigned char rateEth2;
 unsigned char rateEth3;

 unsigned char portrate0;
 unsigned char portrate1;
 unsigned char portrate2;
 unsigned char portrate3;

 unsigned char port_mode;

 unsigned char berbase0;
 unsigned char berbase1;
 unsigned char berbase2;
 unsigned char berbase3;

 unsigned char mparam1;
 unsigned char mparam2;
 unsigned char mparam3;
 unsigned char mparam4;
 unsigned char mparam5;

};

struct Emb4100SECfg
{
 unsigned char conf_number;
 unsigned char numProvCode;	  //rs or ldpc
 unsigned char rateSymbol0;
 unsigned char rateSymbol1;
 unsigned char rateSymbol2;
 unsigned char rateSymbol3;
 unsigned char acm_status;
 unsigned char numb_mode;

 unsigned char alfa;

 unsigned char param1;
 unsigned char param2;
 unsigned char param3;
 unsigned char param4;
 unsigned char param5;

Mode100SE 	mode15504[16];


};

union  uConfigTxtData100
{
//  TxtPrm txtprm;
  Emb4100SECfg  emb4md15504cfg;
  unsigned char Data[TXT_REAL_LEN_100];
};

struct ConfigFileText100
{
  unsigned long LengthTxt;//
  unsigned char Header[FULL_HEADER_SIZE];	
//  unsigned char ConfigTxtData[TXT_REAL_LEN];
  uConfigTxtData100  ConfigTxtData;
};

  */



 /* 
struct Mode15504
{
 unsigned char mode;
 unsigned char interf;
//120203 unsigned long rateEth;
 unsigned char rateEth0;
 unsigned char rateEth1;
 unsigned char rateEth2;
 unsigned char rateEth3;

 unsigned long extTypeRate;
 unsigned short blockSize;
};

struct Emb4Md15504Cfg
{
unsigned short fileNum;
unsigned char numMode;
unsigned char numProvCode;
//unsigned long rateSymbol;
unsigned char rateSymbol0;
unsigned char rateSymbol1;
unsigned char rateSymbol2;
unsigned char rateSymbol3;


Mode15504 mode15504[8];
};


union  uConfigTxtData
{
//  TxtPrm txtprm;
  Emb4Md15504Cfg  emb4md15504cfg;
  unsigned char Data[TXT_REAL_LEN];
};


struct ConfigFileText
{
  unsigned long LengthTxt;//
  unsigned char Header[FULL_HEADER_SIZE];	
//  unsigned char ConfigTxtData[TXT_REAL_LEN];
  uConfigTxtData  ConfigTxtData;
};
*/
 /*

class ModemP
{
public :
 unsigned char ConfigNumber;
 unsigned long Mode;
 unsigned char isrezerv;
 unsigned char usednow;
 unsigned char alarm;
 unsigned char LoadProg(void);
 unsigned char LoadConfig(void);
 void SSC1(unsigned char);
 void SSC2(unsigned char);
 unsigned long CurrentErrors;
 unsigned long LastTimeInLock;
 unsigned char TimesTryGetLock;
 unsigned char Init();
 unsigned char CheckIsOnStm1();
UINT32 fecBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 fecUncorrectedBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 rsByteCounter; // cumulative, clear on read
UINT32 rsErrorByteCounter; // cumulative, clear on read
UINT16 ldpcAvgIterations; // in 1/256 iterations units
BYTE viterbiNormalRate;
BYTE reserved;
UINT32 protectionRxBytesFromProtection; // Current bytes received from the protection //??? replacing erroneous bytes from the working device
UINT32 protectionUncorrectedBytes;
BYTE acquireStatus;
INT32 carrierOffset;
BYTE ProtectionRxState;
BYTE rxPhyId;

//_______________________________



INT16 absoluteMseTenths;
INT16 normalizedMseTenths;
INT16 radialMseTenths;
UINT16 counterSlip;	//this is 

unsigned int       txAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
unsigned int       rxAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
BOOLEAN    acmEngineEnabled;       // enabled/disabled
UINT32	   txAcmProfilesCounter[ACM_MODES];	
UINT32	   rxAcmProfilesCounter[ACM_MODES];	
unsigned char  modulation[16];
UINT32      acmNumOfSymbols[16];
UINT32      gpiPayloadSizeInBytes[16];
UINT16 profilesMask;
UINT16 acmRxProfilesHistory;
UINT16 acmTxProfilesHistory;
//ConfigFileText configfilefext;
//ConfigFileText configfilefext1[MAX_NUM_CFG]; //need fill at setting config file
ConfigFileText100 configfilefext;
ConfigFileText100 configfilefext1[MAX_NUM_CFG]; //need fill at setting config file

UINT16      netE1Alarms[E1_LINES_QUANTITY];
INT16               internalAgc;            // in dB, normal range [-5 to 40]
UINT16              externalAgcRegister;    // Directly reflects PVG register
};
 */

//__________________________________________
unsigned char ldeviceindex;
unsigned char ldeviceindex1;
unsigned char ldeviceindex2;
unsigned char ldeviceindex3;
unsigned char ldeviceindex4;
unsigned char ldeviceindex5;
unsigned char ldeviceindex6;
unsigned char ldeviceindex7;
unsigned char ldeviceindex8;


unsigned char lprot;

unsigned char lacmprofile;
unsigned char lislocal;

unsigned char lrx;
unsigned char ltx;



unsigned short lprofile2;



unsigned char lengineTable;
unsigned char lprofile;
unsigned short lmseTenthsVal;
unsigned char lldpcMantissaTenths;
unsigned char lldpcExponent;
unsigned char lcriteria;
unsigned char lnextProfile;
//__________________________________________


 unsigned char ModemP::Init()
{
	unsigned j;
 for(unsigned i = 0; i < 16; i++)
 {
 modulation[i] = 0;
 acmNumOfSymbols[i] = 0;
 gpiPayloadSizeInBytes[i] = 0;
 }
//______________________________________
 ConfigNumber= 0;
 Mode = 0;
 isrezerv = 0;
 usednow = 0;
 alarm = 0;
 CurrentErrors = 0;
 LastTimeInLock = 0;
 TimesTryGetLock = 0;
 fecBlockCounter = 0; // cumulative, clear on read (RS or LDPC)
 fecUncorrectedBlockCounter = 0; // cumulative, clear on read (RS or LDPC)
 rsByteCounter = 0; // cumulative, clear on read
 rsErrorByteCounter = 0; // cumulative, clear on read
 ldpcAvgIterations = 0; // in 1/256 iterations units
 viterbiNormalRate = 0;
 reserved = 0;
 protectionRxBytesFromProtection = 0; // Current bytes received from the protection //??? replacing erroneous bytes from the working device
 protectionUncorrectedBytes = 0;
 acquireStatus = 0;
 carrierOffset = 0;
 ProtectionRxState = 0;
 rxPhyId = 0;
 absoluteMseTenths = 0;
 normalizedMseTenths = 0;
 radialMseTenths = 0;
 counterSlip = 0;	//this is 
 acmRxProfilesHistory = 0;
 acmTxProfilesHistory = 0;

//______________________________________
 profilesMask = 0l;
 acmEngineEnabled = 0l;       // enabled/disabled
 txAcmProfile = ACM_MODES;//not real value           // see PVG610_ACM_PROFILE_ENUM
 rxAcmProfile = ACM_MODES;//not real value           // see PVG610_ACM_PROFILE_ENUM
 for(i = 0; i < ACM_MODES; i++)
 {
	   txAcmProfilesCounter[i] = 0;	
	   rxAcmProfilesCounter[i] = 0;	
 }
//////////////  MAX  ////////////////
for(i=0; i<MAX_NUM_CFG; i++)
	for(j=0; j<sizeof(ConfigFileText100); j++)
		configfilefext1[i].ConfigTxtData.Data[j]=0;
/////////////////////////////////////
 return 0;
}

unsigned char ModemP::CheckIsOnStm1()
{
// hier need make check
return 1;
}

//#define DELAY_READ	(5000l)

//void ModemP::SSC2(unsigned char variant)
void ModemP::SSC2(unsigned long variant)
{
#ifdef PRINT_PACK_CFG
   	 printfp("\n\rSSC2");
#endif

BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;

if(variant >= MAX_CFG_FILE_VARIANT)
{
// variant = 0;
  variant = 0;
}

unsigned long config_delta;
unsigned long length;
#ifndef DO_NOT_READ_CONFIG_DELTA

 delay_mcs(DELAY_READ);//delay 10 ms

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA)) 
#endif
 config_delta = CONFIG_FILE_PROVINGENT_STEP;
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	  
//#endif
delay_mcs(DELAY_READ);
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
//}
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);

tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
//printfpd("\n\r %lx", tmp);


pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
length = *pBuffer++;
//printf(" %X", *pBuffer);
length  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 24;

//if(length > TXT_REAL_LEN)	 length = TXT_REAL_LEN;
if(length > TXT_REAL_LEN)	 length = 0l;   //120514
//if(length != TXT_REAL_LEN)	 length = 0; //120514

//_____________________________________________________
if(length < FULL_HEADER_SIZE)	length = FULL_HEADER_SIZE + 1;

configfilefext1[variant].LengthTxt =  length - FULL_HEADER_SIZE;
unsigned long itxt = 0l;
#ifdef PRINT_PACK_CFG
printfp("\n\r____________\n\r");
#endif
// delay_mcs(10000l);//delay 10 ms

	for(unsigned long its = FULL_HEADER_SIZE + 4l; its < (length + 4l); its++)
	{
#ifdef PRINT_PACK_CFG
    	   if(!(its%16))printfp("\n\r");
	   printfpd(" %02X", TFTP_Buffer[its]);
#endif
   		configfilefext1[variant].ConfigTxtData.Data[itxt++] = TFTP_Buffer[its];
	}




}


//void ModemP::SSC1(unsigned char variant)
void ModemP::SSC1(unsigned long variant)
{
#ifdef PRINT_PACK_CFG
   	 printfp("\n\rSSC1");
#endif

BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;



if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;

}
unsigned long config_delta;
unsigned long length;
#ifndef DO_NOT_READ_CONFIG_DELTA

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))
#endif
  config_delta = CONFIG_FILE_PROVINGENT_STEP;
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	  
//#endif
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
//}
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
//printfpd("\n\r %lx", tmp);


pBuffer=(unsigned char*)(&TFTP_Buffer[0]);

//__________________________________101006

//printf("\n\r step : %X", *pBuffer);
length = *pBuffer++;
//printf(" %X", *pBuffer);
length  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 24;

//if(length > TXT_REAL_LEN)	 length = TXT_REAL_LEN;
if(length > TXT_REAL_LEN)	 length = 0;



//printfpd("\n\r %lx", length);

//printfp("\n\r");
//for(unsigned long its =0l; its < (length + 4); its++)
//{
//  printfpd(" %c", TFTP_Buffer[its]);
//}


//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 //  curvar = variant;
// }	  //used
// curvar = variant;
//}  //for
//}  //if

//}
 //curvar = 0xff+1;


//_____________________________________________________
if(length < FULL_HEADER_SIZE)	length = FULL_HEADER_SIZE + 1;

configfilefext.LengthTxt =  length - FULL_HEADER_SIZE;
unsigned long itxt = 0;

#ifdef PRINT_PACK_CFG
printfp("\n\r");
#endif

for(unsigned long its = FULL_HEADER_SIZE + 4; its < (length + 4); its++)
{
#ifdef PRINT_PACK_CFG
   if(!(its%16)) printfp("\n\r");
  printfpd(" %02X", TFTP_Buffer[its]);
#endif

   configfilefext.ConfigTxtData.Data[itxt++] = TFTP_Buffer[its];

  // printfpd(" %02X", TFTP_Buffer[its]);
}
}



void SetGEth(unsigned char im, unsigned long eth)
{
// printfp("\n\r SetGEth");
// printfpd(" %ld", im);
// printfpd(" %ld", eth);


 unsigned char reg;
 reg = inportb(BLOCK_SWEEP1*(im + 1) + ETH_PORT);
 if(eth <= RATE_100M) {reg |= GETH_BIT;}
 else { reg &= ~(GETH_BIT);}
 outportb((BLOCK_SWEEP1*(im + 1) + ETH_PORT), reg);

}

#define FILTER_DATA_LENGTH (2)	
#define ADDR_TX	(0x19)
#define ADDR_RX	(0x24)


#ifdef PROG_MD310_SAT

void OperateACM(void)
{

 return; // 141125


 //printfp("\n\rOperateACM ");

  for(unsigned long i = 0x1100l; i <= 0x1115l; i++)
    {
   //	   printfpd(" %d", i);
		if(ComparePOK(i))
    	{
	  // 	 printfp(" run");
	   //	   printfpd(" %x", i);

		  PVG610_API_ModemAcmEngineEnable(0,0,1,0);

  		  PVG610_API_ModemAcmSwitch(0,0, (i- 0x1100l), 1);
  
    	}
   }

  if(ComparePOK(0x1200l))
  {
 //  printfp(" run");
   //		   printfpd(" %x", i);

	  PVG610_API_ModemAcmEngineEnable(0,0,1,1);

  }
}

#endif






   /*

void SetBand(unsigned char im, unsigned long rate)
{


return; //temporary

//extern "C" unsigned char WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
#ifdef PROG_MD310_SAT	
//printfp("\n\r SetBand");
#endif




unsigned char Buffer[FILTER_DATA_LENGTH];
//unsigned char Code;
//delay_mcs(10000l);

//______________for test

// return;

//_______________for test
Buffer[0] =  ADDR_TX;

     if(rate < 16200000) Buffer[1] = 0xe;
else if(rate < 18400000) Buffer[1] = 0xb; 
else if(rate < 21500000) Buffer[1] = 0xa; 
else if(rate < 25900000) Buffer[1] = 0x8; 	//it need for md34e
else if(rate < 32300000) Buffer[1] = 0x6; 
else if(rate < 43100000) Buffer[1] = 0x4; 
else if(rate < 64000000) Buffer[1] = 0x2; 
else  				  Buffer[1] = 0x0; 


 WriteSpiBm(im + 45, FILTER_DATA_LENGTH, Buffer);

// printfp("\n\r SetBand tx");
// printfpd(" %ld", im);
// printfpd(" %X", Buffer[0]);
// printfpd(" %X", Buffer[1]);


Buffer[0] =  ADDR_RX;

//     if(rate < 28000000)  Buffer[1] = 0x6;
//else if(rate < 56000000)  Buffer[1] = 0x2; 
     if(rate < 16000000)  Buffer[1] = 0x6;
else if(rate < 30000000)  Buffer[1] = 0x2; 

//else if(rate < 100000) Buffer[1] = 0xa; 
else  				   Buffer[1] = 0x0; 


 WriteSpiBm(im + 45, FILTER_DATA_LENGTH, Buffer);


// printfp("\n\r SetBand rx ");
// printfpd(" %ld", im);
// printfpd(" %X", Buffer[0]);
// printfpd(" %X", Buffer[1]);

  
 reg = inportb(BLOCK_SWEEP1*(im + 1) + ETH_PORT);
 if(eth <= RATE_100M) {reg |= GETH_BIT;}
 else { reg &= ~(GETH_BIT);}
 outportb((BLOCK_SWEEP1*(im + 1) + ETH_PORT), reg);
  

//delay_mcs(10000l);
}


	 */

 uLevelSN15503	 ulevelsn15503;
uErrSN15503Work	 uerrsn15503work;

unsigned char staterezerv;

ModemP modemp[MODEM_QUANTITY << 1];
 /*
extern "C" void ModemStatusGetm(unsigned char flagm)
{
PVG610_MODEM_STATUS_STRUCT	Ms;
unsigned long ir;
if(flagm == MODEM_QUANTITY)
{
 for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
 {
  if(ModemIsUsed(im))
 {
  // printf("\n\r ModemStatusGetm : %d", im);
   ir = im << 1;
 //  printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
//printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
//printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
//printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);

   
//printf("\n\r lastAcquireError : %02X" , Ms.lastAcquireError);
//printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
//printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
//printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);
//printf("\n\r internalAgc : %d" , Ms.internalAgc);
//printf("\n\r externalAgcRegister : %X" , Ms.externalAgcRegister);
//printf("\n\r carrierOffset : %d" , Ms.carrierOffset);
//printf("\n\r rxSymbolRate : %d" , Ms.rxSymbolRate);
//printf("\n\r txSymbolRate : %d" , Ms.txSymbolRate);
//printf("\n\r ldpcDecoderStress : %X" , Ms.ldpcDecoderStress);
//printf("\n\r txAcmProfile : %02X" , Ms.txAcmProfile);
//printf("\n\r rxAcmProfile : %02X" , Ms.rxAcmProfile);
//printf("\n\r acmEngineEnabled : %d" , Ms.acmEngineEnabled);
//printf("\n\r debugIndications : %02X" , Ms.debugIndications);


   ir++;
 //  printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
 }
 }
 }
 else
 {
  ir = flagm << 1;
 //  printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
//   printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
   ir++;
//   printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);

 }
}
*/


extern "C" void ConfigFileRunm(unsigned char flagm)
{
unsigned long ir;
unsigned char tmp;

if(flagm == MODEM_QUANTITY)
{

 for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
 {
  if(ModemIsUsed(im))
 {
  ir = im << 1;
  tmp =	 PVG610_API_ConfigFileRun (ir,0);
//#ifndef USART0_TRY_PDC_1T	
//  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
//  printf("...%d",tmp);
//  printf("...%d", PVG610_API_ConfigFileRun (ir,0));
//#else
#ifdef START_PRINT
  printfp("\n\r PVG610_API_ConfigFileRun");
  printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
tmp =  PVG610_API_ModemAcquireStart(ir,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);
#ifdef START_PRINT 
  printfp("\n\r PVG610_API_ModemAcquireStart");
  printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
                                                  
PVG610_API_RegisterWrite(ir, 0, (unsigned short)SPEC_REG_ADDR, 0 , (unsigned short)SPEC_REG_VAL);



#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

  ir++;
	tmp =	 PVG610_API_ConfigFileRun (ir,0);
//#ifndef USART0_TRY_PDC_1T	
 // printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
 //  printf("...%d",tmp);
//   printf("...%d",PVG610_API_ConfigFileRun (ir,0));
//#else
#ifdef START_PRINT
  printfp("\n\r PVG610_API_ConfigFileRun");
  printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
  
tmp =  PVG610_API_ModemAcquireStart(ir,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);
#ifdef START_PRINT
 printfp("\n\r PVG610_API_ModemAcquireStart");
 printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
   
 PVG610_API_RegisterWrite(ir, 0, (unsigned short)SPEC_REG_ADDR, 0 , (unsigned short)SPEC_REG_VAL);
                                             
#endif
 }
}
}
else
{
  if(ModemIsUsed(flagm))
  {
  ir = flagm << 1;
  tmp =	 PVG610_API_ConfigFileRun (ir,0);
//#ifndef USART0_TRY_PDC_1T	
//  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
//   printf("...%d",tmp);
//  printf("...%d", PVG610_API_ConfigFileRun (ir,0));
//#else
#ifdef START_PRINT
  printfp("\n\r PVG610_API_ConfigFileRun");
  printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
  
tmp =  PVG610_API_ModemAcquireStart(ir,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);
//#ifdef START_PRINT
//  printfp("\n\r PVG610_API_ModemAcquireStart");
//  printfpd("  %d", ir);
//  printfpd("...%d",tmp);
//#endif
PVG610_API_RegisterWrite(ir, 0, (unsigned short)SPEC_REG_ADDR, 0 , (unsigned short)SPEC_REG_VAL);  
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

  ir++;
  tmp =	 PVG610_API_ConfigFileRun (ir,0);
//#ifndef USART0_TRY_PDC_1T	
 // printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
 // printf("...%d",tmp);
 //  printf("...%d",PVG610_API_ConfigFileRun (ir,0));
//#else
#ifdef START_PRINT
  printfp("\n\r PVG610_API_ConfigFileRun");
  printfpd("  %d", ir);
  printfpd("...%d",tmp);
#endif
 
tmp =  PVG610_API_ModemAcquireStart(ir,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);
//#ifdef START_PRINT
//  printfp("\n\r PVG610_API_ModemAcquireStart");
//  printfpd("  %d", ir);
//  printfpd("...%d",tmp);
//#endif

PVG610_API_RegisterWrite(ir, 0, (unsigned short)SPEC_REG_ADDR, 0 , (unsigned short)SPEC_REG_VAL);
#endif
}
}
}

#define  DESTROY_SIZE (40000)
extern "C" int write_dataflash (unsigned long , unsigned int , unsigned int );


extern "C" void ConfigFileDestroy(unsigned long variant)
{

/*
 if(1) //101230
{
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

}
*/

sprintf(TFTP_Buffer, "%s", "hello");

unsigned int AddressSrc =  (unsigned int)&TFTP_Buffer[0];

//write_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)),
write_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)),
 (unsigned int)&TFTP_Buffer[0], DESTROY_SIZE);

printfpd("\n\r destroy : %d", variant);

}



unsigned long ratesymbol_far;

extern "C" void ConfigFileLoadm(unsigned long variant, unsigned char flagm)
{
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
unsigned long curvar = 0xfff+1; //more as maximum var
unsigned long tmp;
unsigned long variant1;
char Buf[4];

timer_config = 0;
//sprintf(Buf,"%03d", variant);
//#ifdef YOURNAL
//Add_Event(EV_CONFIG, 1, (char*)&variant);
//Add_Event(EV_CONFIG, 3, (char*)&Buf);
//#endif

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 01;

}

UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT32 config_delta;
unsigned long ir;
#ifdef MAKET_PLATA
for(unsigned i=0; i<MAX_NUM_CFG; i++)
modemp[0].SSC2(i);
#endif 
if(flagm == MODEM_QUANTITY)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
//#ifndef MAKET_PLATA 
 if(ModemIsUsed(im))
//#else
// if(1)
//#endif
 {
if(!hot_restart)
  {
SetNeedInitAllProti(im); //120202
  }
 //____________________________________________________________
// printfp("1210041");
//if(variant != NUM_CALIBR_FILE)
//{
variant =  GetNumConfigFilet(im) & CONFIG_FILE_MASK;
variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	//self number is hier for second provingent 
 sprintf(Buf,"%03d", variant);

if(variant1 != variant)
{
 #ifdef YOURNAL
//Add_Event(EV_CONFIG, 1, (char*)&variant);
Add_Event(EV_CONFIG_T, 3, (char*)&Buf);
#endif

}
else
{

#ifdef YOURNAL
//Add_Event(EV_CONFIG, 1, (char*)&variant);
Add_Event(EV_CONFIG, 3, (char*)&Buf);
#endif


}

//}



modemp[im].SSC1(variant);

  /*   not need

if(!hot_restart)
  {
  SetOptics(im, 1);
  }

*/

dev1.md100se.ConfigFile = variant;

//acm_status = modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.acm_status;
//SetMACMM();

//SetMCodeO(modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.coderate);
//SetMTCode();
//SetParamsFromCfg();	   //acm only in end

/*
unsigned long rateEth = 
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].rateEth0)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].rateEth1 <<8)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].rateEth2 <<16)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].rateEth3 <<24);

unsigned long 	rateSymbol =
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1 <<8)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2 <<16)+
 ((unsigned long)modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3 <<24);

  ratesymbol_far = rateSymbol;
  power_rate = 	rateSymbol;
  power_modul = modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].mode; 
 // SetGEth(im, modemp[im].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].rateEth);
 if(!hot_restart)
  {
  SetGEth(im, rateEth);
  }


*/
//  SetBand(im, rateSymbol);
//   SetBand(im+1, rateSymbol); //for 1 provingent

//}

// printf("\n\r curvar = %d", curvar);
//101230 if(variant != curvar)

#ifndef DO_NOT_READ_CONFIG_DELTA

 if(1) //101230
{
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  
#endif
config_delta = CONFIG_FILE_PROVINGENT_STEP;

#ifdef PRINT_PACK_CFG

printfpd("\n\r config_delta lcf : %d", config_delta);	  
#endif

//okread_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + ((variant + 10) * CONFIG_FILE_VARIANTS_STEP)),
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + (variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;
//_____________________________________________________________
 ir = im << 1;
if(!hot_restart)
  {
 tmp = 	PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len);



//ok return; //150224

SetParamsFromCfg();

//ok return; //150224  wrong


 //from rfout  SetMACMM();
 //  SetMRfOut();   //last	//need close before changing  



 // SetGEth(ir, rateEth);
 /*	
 #ifndef NO_LOAD_BANDS
  SetBand(ir, rateSymbol);
#endif
*/
//   SetBand(im+1, rateSymbol); //for 1 provingent


//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  var: % d conf_del: %d num : %d ",variant, config_delta, ir);
 //printf("\n\r...%d len %d",tmp, len);
//#else


#ifdef START_PRINT
 printfp("\n\r PVG610_API_ConfigFileFromHostLoad  variant:"); 
 printfpd("%d:",variant);
 printfp("  conf_delta: ");//%d", config_delta);
 printfpd("%d", config_delta);
 printfpd("  num : %d ", ir);
 printfp(" len :");
 printfpd("%d", len);
 printfpd("...%d", tmp);
#endif

}

Ld0 = tmp;

//#ifdef PROG_MD310_SAT	
// OperateACM();

//#endif

 //____________________________________________________________


variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	//self number is hier for second provingent 
#ifdef START_PRINT

  printfpd("\n\r cfp0 = %d",variant);
  printfpd("  cfp1 = %d",variant1);
#endif

if(variant1 != variant)
{
 //printfp(" ___!=");

sprintf(Buf,"%03d", variant1);
#ifdef YOURNAL
//Add_Event(EV_CONFIG, 1, (char*)&variant1);
Add_Event(EV_CONFIG_D, 3, (char*)&Buf);
#endif



read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + (variant1 * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

 outportb(STATUS_610_ADDR,0x13);  //dualmod = 1

 SetHbandAndPauseOff();

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;



 // printfpd("  STATUS_610_ADDR = %x",inportb(STATUS_610_ADDR));

}
else
{
//printfp(" ___==");

  outportb(STATUS_610_ADDR,0x3);	//dualmod = 0


}

 
 
  /*
for(long dr = 0; dr < config_delta - 0x60; dr++)	//<<<<<<<to hier need config_step
 {
   pBuffer++;
 }
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;
  */

//________________________________________________________
//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);

  /*
for(unsigned long its =0l; its < 64l; its++)
{
// if(!(its% 16)) printf("\n\r");
//  printf(" %02X", *pBuffer);
   pBuffer++;
}
 */

#ifdef START_PRINT

for(unsigned long its =0l; its < 48l; its++)
{
 if(!(its% 16)) printfp("\n\r");
  printfpd(" %02X", TFTP_Buffer[its]);
}
#endif

/*
for(its =0x1720l; its < (0x1720+48l); its++)
{
// if(!(its% 16)) printf("\n\r");
//  printf(" %02X", TFTP_Buffer[its]);
}

for(its = 0; its < ProvSizeToDownloadDCfgFile; its++)
{
//  if(TFTP_Buffer[its] != TFTP_Buffer[its + CONFIG_FILE_PROVINGENT_STEP])
// printf("\n\r its: %d", its);
 }

 */
//_____________________________________________________________second provingent!


//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA




 ir++;
if(!hot_restart)
  {

  // pBuffer=(unsigned char*)(&TFTP_Buffer[0]);



  tmp = 	PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len);


SetParamsFromCfg1(variant1);
// SetGEth(im, rateEth);
//#ifndef NO_LOAD_BANDS
//  SetBand(ir, rateSymbol);
//#endif
//   SetBand(im+1, rateSymbol); //for 1 provingent



//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d  len: %d",tmp, len);
// printf("...%d  len: %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);
//#else
#ifdef START_PRINT
 printfp("\n\r PVG610_API_ConfigFileFromHostLoad  variant:"); 
 printfpd("%d:",variant);
// printfp("  conf_delta: ");//%d", config_delta);
// printfpd("%d", config_delta);
// printfpd("  num : %d ", ir);
// printfp(" len :");
// printfpd("%d", len);
 printfpd("...%d", tmp);
  OperateBuffers_usart0t();

// printf("\n\r...%d len %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);
#endif //start print

}
//#endif // LOAD_ONE_PROVINGENT_ON_PLATA

 

 curvar = variant;
 }
 // curvar = variant;
}	//for

Ld1 = tmp;



}	//if  flag != modem quantity
else  //for section
{

  }	  //else
 curvar = 0xfff+1;



}


extern "C" void ConfigDataLoadm(unsigned long variant, unsigned char flagm)
{
//printf("\n\r ConfigDataLoadm");
//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_MODEM_STATUS_STRUCT *pMs;
//pMs = &Ms;
BYTE *pBuffer;
unsigned long curvar = 0xfff+1; //more as maximum var
unsigned long file_size_readed;

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;

}
if(flagm == MODEM_QUANTITY)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
//#ifndef MAKET_PLATA 
 if(ModemIsUsed(im))
 {
 //____________________________________________________________
// printfp("1210043");
variant =  GetNumConfigFilet(im) & CONFIG_FILE_MASK;
//variant = 0; //for test!
// printf("\n\r curvar = %d", curvar);
//if(variant != curvar)
if(1)
{
// printf("\n\r ..read flash !!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;

//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP)),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
//__________________________________________________________________________________
//hier need read file size

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r file size  : %X", *pBuffer);
file_size_readed = *pBuffer++;
//printf(" %X", *pBuffer);
file_size_readed  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 24;
//printf("\n\r file_size_readed : %d", file_size_readed);
 if((file_size_readed < MIN_CFG_FILE_SIZE) || (file_size_readed > MAX_CFG_FILE_SIZE)) file_size_readed = FILE_SIZE;
//printf("\n\r file_size_readed : %d", file_size_readed);
 read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS  -  FULL_HEADER_SIZE - FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) +
//101018  (FILE_SIZE - NUMBER_OFFSET)),
	 (file_size_readed - NUMBER_OFFSET)),
							 (unsigned int)NUMBER_OFFSET, (char *)(&TFTP_Buffer[0]));
}
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________
// ir = im << 1;

/*
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  variant: % d  %d ",variant, ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
*/
  modemp[im].Mode =   (TFTP_Buffer[0] << 24) +
  						 (TFTP_Buffer[1] << 16) +
  						   (TFTP_Buffer[2] << 8) +
   								   TFTP_Buffer[3]; 

//printf("\n\r variant : %02X", variant);
//printf("\n\r mode : 0x%08X", modemp[im].Mode);
// for(long dr = 0; dr < NUMBER_OFFSET; dr++)
// {
 //  pBuffer++;
//   printf("\n\r %02X", TFTP_Buffer[dr]);
// }

// for(long dr = 0; dr < 2; dr++)
// for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP - 0x60; dr++)
// {
//   pBuffer++;
// }
//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
/*
for(unsigned long its =0l; its < 64l; its++)
{
// if(!(its% 16)) printf("\n\r");
//  printf(" %02X", *pBuffer);
   pBuffer++;
}

 */
/*
for(unsigned long its =0l; its < 48l; its++)
{
// if(!(its% 16)) printf("\n\r");
//  printf(" %02X", TFTP_Buffer[its]);
}

for(its =0x1720l; its < (0x1720+48l); its++)
{
// if(!(its% 16)) printf("\n\r");
//  printf(" %02X", TFTP_Buffer[its]);
}

for(its = 0; its < ProvSizeToDownloadDCfgFile; its++)
{
  if(TFTP_Buffer[its] != TFTP_Buffer[its + CONFIG_FILE_PROVINGENT_STEP])
// printf("\n\r its: %d", its);
 }

*/

// ir++;

 /*
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));

 */

   curvar = variant;

 }
}	//for
}	//if
else  //flagm == MODEM_QUANTITY
{
//printfp("1210044");
variant =  GetNumConfigFilet(flagm) & CONFIG_FILE_MASK;
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
file_size_readed = *pBuffer++;
//printf(" %X", *pBuffer);
file_size_readed  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 24;
//printf("\n\r file_size_readed : %d", file_size_readed);
//_____________________________________________________________

 if((file_size_readed < MIN_CFG_FILE_SIZE) || (file_size_readed > MAX_CFG_FILE_SIZE)) file_size_readed = FILE_SIZE;

///printf("\n\r variant : %d file_size_readed1 : %d", variant, file_size_readed);
 read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS  -  FULL_HEADER_SIZE - FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) +
//101018  (FILE_SIZE - NUMBER_OFFSET)),
	 (file_size_readed - NUMBER_OFFSET)),
							 (unsigned int)NUMBER_OFFSET, (char *)(&TFTP_Buffer[0]));
 modemp[flagm].Mode =   (TFTP_Buffer[0] << 24) +
  						 (TFTP_Buffer[1] << 16) +
  						   (TFTP_Buffer[2] << 8) +
   								   TFTP_Buffer[3]; 
  /*
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 */
/*
//printf("\n\r>");
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
for(unsigned long its =0l; its < 100l; its++)
{
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
}
 */

 /*
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 */
}
 curvar = 0xfff+1;
}

extern "C" void FirmwareLoadm(unsigned char flagm)
{
unsigned long ret;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
UINT32 len = (unsigned int)ProvSizeToDownloadD;
read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
 

#ifdef START_PRINT
				 
printfp("\n\r Firmware :");
for(long t = 0; t < 18; t++)
{
printfpd (" %02X",TFTP_Buffer[t]);
}
printfp("\n\r");

//printf("\n\r end of rawdata :");

//for(t = 8180; t < (8180+ 64); t++)
//{
//printf("_%02X",TFTP_Buffer[t]);
//}
#endif
unsigned long ir;

if(flagm == MODEM_QUANTITY)
{

for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
wd_reset();
#ifdef START_PRINT

printfpd(" FirmwareLoadm modem : %d",im); //1000118

#endif

 if(ModemIsUsed(im))
 {
// delay_mcs(DELAY_LOAD);

 ir = im << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
 Ld0 = ret;

//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
#ifdef START_PRINT
 printfp("\n\r PVG610_API_FirmwareFromHostBoot");
 printfpd(" %d", ir);
 printfpd("...%d", ret);
#endif

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

 ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
 Ld1 = ret;
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
//// printf("... %d", ret);
//#else
#ifdef START_PRINT
 printfp("\n\r PVG610_API_FirmwareFromHostBoot");
 printfpd(" %d", ir);
 printfpd("...%d", ret);
#endif
#endif // LOAD_ONE_PROVINGENT_ON_PLATA
 } //if
} //for
}//if
else
{
ir = flagm << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 //printf("... %d", ret);
//#else
#ifdef START_PRINT
 printfp("\n\r PVG610_API_FirmwareFromHostBoot");
 printfpd(" %d", ir);
 printfpd("...%d", ret);
#endif

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
#ifdef START_PRINT
 printfp("\n\r PVG610_API_FirmwareFromHostBoot");
 printfpd(" %d", ir);
 printfpd("...%d", ret);
#endif

#endif // LOAD_ONE_PROVINGENT_ON_PLATA

}
}

extern "C" unsigned char CheckEthMode(unsigned char test)
{
 unsigned char ret = 1;
 //unsigned char test = GetModEth() & 0xf;
 switch(test)
 {
  case 1:   ret = 1; break;
  case 2:   ret = 2; break;
  case 4:   ret = 4; break;
  case 8:   ret = 8; break;
  default : ret = 0; break;
 }
 return ret;
}

extern "C" void SetEthMode(unsigned char mode)
{
//hier need make table going from modeth - bits 
//to methmode 0 ....5

 #ifdef PRINT_ETH

  printfpd("SetEthMode : %02X", mode);
 #endif

  SetModEth(mode);
}

#define  DEFAULT_MODE  (ETH_AUTO)//(0x1)   //auto
//#define  DEFAULT_MODE  (ETH_100 | ETH_DUPL)   //0x4 100 Mb //fo test
//#define  DEFAULT_MODE  (ETH_10 | ETH_DUPL) 
//#define  DEFAULT_MODE  (ETH_100) 
//#define  DEFAULT_MODE  (ETH_10) 

extern "C" void StartEth10p(void)
{
 // printfp("10p");

SetEthMode(ETH_10);

 delay_mcs(100000l);
EthStatusSet1(0, 0, 0,	   //10 mB
				  0, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 0,	   //10 mB
				  0, 0,
				  0,  0,
				  1,  0);


delay_mcs(100000l);
EthStatusSet1(0, 0, 0,	   //10 mB
				  0, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 0,	   //10 mB
				  0, 0,
				  0,  0,
				  1,  0);


}

extern "C" void StartEth100p(void)
{

  #ifdef PRINT_ETH

   printfp("\n\r StartEth100p");

#endif

   SetEthMode(ETH_100);

 delay_mcs(100000l);
EthStatusSet1(0, 0, 1,	   //100 mB
				  0, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 1,	   //100 mB
				  0, 0,
				  0,  0,
				  1,  0);

delay_mcs(100000l);
EthStatusSet1(0, 0, 1,	   //100 mB
				  0, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 1,	   //100 mB
				  0, 0,
				  0,  0,
				  1,  0);



}
extern "C" void StartEth10d(void)
{
  // printfp("10d");
   SetEthMode(ETH_10 | ETH_DUPL);

 delay_mcs(100000l);
EthStatusSet1(0, 0, 0,	   //10 mB
				  1, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 0,	   //10 mB
				  1, 0,
				  0,  0,
				  1,  0);

delay_mcs(100000l);
EthStatusSet1(0, 0, 0,	   //10 mB
				  1, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 0,	   //10 mB
				  1, 0,
				  0,  0,
				  1,  0);



}

extern "C" void StartEth100d(void)
{
 //   printfp("100d");
	SetEthMode(ETH_100 | ETH_DUPL);

  delay_mcs(100000l);
EthStatusSet1(0, 0, 1,	   //100 mB
				  1, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 1,	   //100 mB
				  1, 0,
				  0,  0,
				  1,  0);

 delay_mcs(100000l);
EthStatusSet1(0, 0, 1,	   //100 mB
				  1, 0,
				  0,  0,
				  1,  0);

EthStatusSet1(1, 0, 1,	   //100 mB
				  1, 0,
				  0,  0,
				  1,  0);



}



extern "C" void StartEth(unsigned char flagm)
{
//unsigned long ret;
//unsigned long ir;
unsigned char auton;
unsigned char speed;
unsigned char duplex;
unsigned char interf;
unsigned char mode_eth;

#ifdef PRINT_ETH
	printfp("\n\r StartEth");
#endif

// unsigned char loop,
//				  unsigned char interf,



if(flagm == MODEM_QUANTITY)
{

for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
wd_reset();
//printf("%d",im); //1000118

//_______________________________now at start set for all auto mode
//121120 SetEthMode(DEFAULT_MODE);
  #ifdef PRINT_ETH
	printfpd("\n\r GetModEth %02X" , GetModEth() );
#endif



//SetEthMode(GetModEth() & 0xf);	//121120	  hier lost duplex!!!!	   
SetEthMode(GetModEth() & 0x1f);	//121120	  hier lost duplex!!!!//150122 return;	 //121120
//_______________________________

if(!CheckEthMode(GetModEth() & 0xf)) SetEthMode(DEFAULT_MODE);

#ifdef PRINT_ETH
	printfpd("\n\r GetModEth1 %02X" , GetModEth() );
#endif


 if(ModemIsUsed(im))
 {
// delay_mcs(DELAY_LOAD);

 //ir = im << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
//make now for auto
//void EthStatusSet1(0, unsigned char auton, unsigned char speed,
//				  unsigned char duplex, unsigned char loop,
//				  unsigned char interf,  unsigned char phyId,
//				  unsigned char reset,  unsigned char changephy );
 mode_eth = GetModEth();
auton = mode_eth & ETH_AUTO;
if(mode_eth & ETH_10) {speed = 0; interf = 0;}
if(mode_eth & ETH_100) {speed = 1; interf = 0;}
if(mode_eth & ETH_1000) {speed = 2; interf = 1;}
//duplex = mode_eth &  ETH_DUPL;
if(mode_eth & ETH_DUPL) {duplex = 1;}
else{duplex = 0;} 

#ifdef PRINT_ETH
 printfpd("\n\r mode_eth : %d", mode_eth);
#endif


// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);


 
if(!hot_restart)
  {

//delay_mcs(100000l);
// delay_mcs(100000l);
//  delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
 delay_mcs(100000l);
//ok delay_mcs(50000l);
// delay_mcs(25000l);
//no delay_mcs(10000l);
   	  
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
 				   1,   0 );  //reset!!!!
   //					   0,   0 );  //no reset!!!!	//t
EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
 				   1,   0 );  //reset!!!!
  
  		   
// delay_mcs(100000l);
 delay_mcs(100000l);
//ok  delay_mcs(50000l);
//no delay_mcs(25000l);
 //no delay_mcs(10000l);

	
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!
	//			   0,   0 );  //no reset!!!!


EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!
	//			   0,   0 );  //no reset!!!!

}

   		
				   
#ifdef START_PRINT
 printfp("\n\r StartEth");
 printfpd(" %d", im);
// printfpd("...%d", ret);
#endif
  /*
#ifdef PRINT_ETH
 printfp("\n\r StartEtha");
 printfpd("mode  %X", mode_eth);
 printfpd("auton  %X", auton);
  printfpd("speed  %X", speed);
   printfpd("interf  %X", interf);

// printfpd("...%d", ret);
#endif

   */


//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

// ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
//// printf("... %d", ret);
//#else
//#ifdef START_PRINT
// printfp("\n\r PVG610_API_FirmwareFromHostBoot");
// printfpd(" %d", ir);
// printfpd("...%d", ret);
//#endif
//#endif // LOAD_ONE_PROVINGENT_ON_PLATA
 } //if
} //for
}//if
else
{

//_______________________________now at start set for all auto mode
//121120 SetEthMode(DEFAULT_MODE);

SetEthMode(GetModEth() & 0xf);	//121120
return;	 //121120
//_______________________________



if(!CheckEthMode(GetModEth() & 0xf)) SetEthMode(DEFAULT_MODE);


//ir = flagm << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 //printf("... %d", ret);
//#else

#ifdef PRINT_ETH
 printfpd("\n\r mode_eth : %d", mode_eth);
#endif


 mode_eth = GetModEth();
auton = mode_eth & ETH_AUTO;
if(mode_eth & ETH_10) {speed = 0; interf = 0;}
if(mode_eth & ETH_100) {speed = 1; interf = 0;}
if(mode_eth & ETH_1000) {speed = 2; interf = 1;}
if(mode_eth & ETH_DUPL) {duplex = 1;}
else{duplex = 0;} 

if(!hot_restart)
  {
  
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!


EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!


}

 
#ifdef START_PRINT
 printfp("\n\r StartEthb");
 printfpd(" %d", flagm);
 //printfpd("...%d", ret);
#endif

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
// ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
//#ifdef START_PRINT
// printfp("\n\r PVG610_API_FirmwareFromHostBoot");
// printfpd(" %d", ir);
// printfpd("...%d", ret);
//#endif

//#endif // LOAD_ONE_PROVINGENT_ON_PLATA

}
}

//_________________________________________________________________________
extern "C" void StartEthTimed(unsigned char flagm)
{
//unsigned long ret;
//unsigned long ir;
unsigned char auton;
unsigned char speed;
unsigned char duplex;
unsigned char interf;
unsigned char mode_eth;

// unsigned char loop,
//				  unsigned char interf,



if(flagm == MODEM_QUANTITY)
{

for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
wd_reset();
//printf("%d",im); //1000118

//_______________________________now at start set for all auto mode
//ethtimed SetEthMode(DEFAULT_MODE);
//_______________________________

if(!CheckEthMode(GetModEth() & 0xf)) SetEthMode(DEFAULT_MODE);

 if(ModemIsUsed(im))
 {
// delay_mcs(DELAY_LOAD);

 //ir = im << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
//make now for auto
//void EthStatusSet1(0, unsigned char auton, unsigned char speed,
//				  unsigned char duplex, unsigned char loop,
//				  unsigned char interf,  unsigned char phyId,
//				  unsigned char reset,  unsigned char changephy );
 mode_eth = GetModEth();
auton = mode_eth & ETH_AUTO;
if(mode_eth & ETH_10) {speed = 0; interf = 0;}
if(mode_eth & ETH_100) {speed = 1; interf = 0;}
if(mode_eth & ETH_1000) {speed = 2; interf = 1;}
//duplex = mode_eth &  ETH_DUPL;
if(mode_eth & ETH_DUPL) {duplex = 1;}
else{duplex = 0;} 

#ifdef PRINT_ETH
 printfpd("\n\r mode_eth : %d", mode_eth);
#endif


// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);


//delay_mcs(100000l);
// delay_mcs(100000l);
//  delay_mcs(100000l);
// delay_mcs(100000l);
// delay_mcs(100000l);
 delay_mcs(100000l);
//ok delay_mcs(50000l);
// delay_mcs(25000l);
//no delay_mcs(10000l);


   	  
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
 				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
 				   1,   0 );  //reset!!!!

   //					   0,   0 );  //no reset!!!!	//t
  
  		   
// delay_mcs(100000l);
 delay_mcs(100000l);
//ok  delay_mcs(50000l);
//no delay_mcs(25000l);
 //no delay_mcs(10000l);

	
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

	//			   0,   0 );  //no reset!!!!
   		
				   
 #ifdef PRINT_ETH
 printfp("\n\r StartEthTimed");
 printfpd(" %d", im);
// printfpd("...%d", ret);
#endif
  /*
#ifdef PRINT_ETH
 printfp("\n\r StartEtha");
 printfpd("mode  %X", mode_eth);
 printfpd("auton  %X", auton);
  printfpd("speed  %X", speed);
   printfpd("interf  %X", interf);

// printfpd("...%d", ret);
#endif

   */


//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

// ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
//// printf("... %d", ret);
//#else
//#ifdef START_PRINT
// printfp("\n\r PVG610_API_FirmwareFromHostBoot");
// printfpd(" %d", ir);
// printfpd("...%d", ret);
//#endif
//#endif // LOAD_ONE_PROVINGENT_ON_PLATA
 } //if
} //for
}//if
else
{

#ifdef PRINT_ETH
 printfp("\n\r StartEthTimed");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif

if(!CheckEthMode(GetModEth() & 0xf)) SetEthMode(DEFAULT_MODE);


//ir = flagm << 1;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 //printf("... %d", ret);
//#else

 mode_eth = GetModEth();

#ifdef PRINT_ETH
 printfpd("\n\rmod_eth: 0x%X\n\r", mode_eth);
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif



auton = mode_eth & ETH_AUTO;
#ifdef PRINT_ETH
 if(auton )printfp("\n\r auto");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif




if(mode_eth & ETH_10) {speed = 0; interf = 0;
#ifdef PRINT_ETH
 printfp("\n\r 10");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif

}
if(mode_eth & ETH_100) {speed = 1; interf = 0;
 #ifdef PRINT_ETH
 printfp("\n\r 100");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif

}
if(mode_eth & ETH_1000) {speed = 2; interf = 1;
#ifdef PRINT_ETH
 printfp("\n\r 1000");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif


}

#ifdef PRINT_ETH
 printfpd("\n\r mode_eth : %d", mode_eth);
#endif

if(mode_eth & ETH_DUPL) {duplex = 1;

 #ifdef PRINT_ETH
 printfp("d");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif



}
else{duplex = 0;

 #ifdef PRINT_ETH
 printfp("pd");
// printfpd(" %d", im);
// printfpd("...%d", ret);
#endif


} 

  
EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!


EthStatusSet1(0,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!

EthStatusSet1(1,  auton,  speed,
				   duplex,  0,
				   interf,   0,
				   1,   0 );  //reset!!!!


  
#ifdef START_PRINT
 printfp("\n\r StartEthb");
 printfpd(" %d", flagm);
 //printfpd("...%d", ret);
#endif

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
// ir++;
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
// printf("... %d", ret);
//#else
//#ifdef START_PRINT
// printfp("\n\r PVG610_API_FirmwareFromHostBoot");
// printfpd(" %d", ir);
// printfpd("...%d", ret);
//#endif

//#endif // LOAD_ONE_PROVINGENT_ON_PLATA

}
}



//_________________________________________________________________________


//#define NUM_CALIBR_FILE		(20)

void StartModems(unsigned char flagm)	//20s
{

//return; //t


#ifndef USART0_TRY_PDC_1T
//printf("\n\r Start Modems flag : %d", flagm);
#endif
//printfp("1210045");
ConfigDataLoadm(GetNumConfigFilet(flagm-1),flagm);	//deleted error

//ok return; //t



 ScanTxtFiles(); //comment do not get some


if(!hot_restart)
  {

//ok return;

  FirmwareLoadm(flagm);		//hier hangt ?
  
//wrong!!!return;

//printfp("1210045");
  /*	 
#ifdef USE_CALIBR
ConfigFileLoadm(NUM_CALIBR_FILE, flagm);
ConfigFileRunm(flagm);
SetModemXILNPL1m(flagm);
KeepCalibrData();	
#endif

*/
   } //! hot restart
	 
//wronng return; 


ConfigFileLoadm(GetNumConfigFilet(flagm-1), flagm);	 //deleted error

// return; //150224

if(!hot_restart)
 {
ConfigFileRunm(flagm);
#ifdef USE_CALIBR
SetCalibrData();
#endif
 }
ModemAlarmEnableSetAllm(flagm);
SetModemXILNPL1m(flagm);

#ifdef OPERATE_ETH
StartEth(flagm);
#endif

   SetMRfOut();

}  

 unsigned long 	timer_restart;
//121004 #define  TIME_WAIT_RESTART (2000)
#define  TIME_WAIT_RESTART (5000)	 //121004

void HotStartConfigFile(unsigned char flagm)
{
//121004 timer_restart = TIME_WAIT_RESTART;
 timer_restart = time1 + TIME_WAIT_RESTART;
 if(timer_restart < time1)
 {	 time1 = 0l;
 timer_restart = (unsigned long)TIME_WAIT_RESTART;
 }
}

void Check_restart()
{
/*
if(timer_restart > 1l) timer_restart--;
else if(timer_restart == 1)	  dev_restart();
*/
if((timer_restart < time1) && (timer_restart))
{
timer_restart = 0;
dev_restart();
}

}

unsigned char GetChannelToSend(void)	//new
{
 return 0;
}


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



extern "C" void wr4_8(void)
{
write_xil_char(4, 0x8);
}

unsigned char Modify5A(unsigned char byte)
{
	switch(byte)
	{
		case 0x00: return 0x5A;
		case 0x01: return 0x55; 
		case 0x02: return 0xA5; 
		case 0x03: return 0xAA; 
		default: /* hier can receive    */ return 0;
	}

}




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
char buffcash::compare(unsigned long numloc, unsigned long asloc, unsigned long ailoc, unsigned long arloc, unsigned long isrs485)
{

#ifdef CASHE_OFF
return 0; //test
#endif

for(long i = 0; i < CASHE_SIZE; i++)
{
    if(buffc[i].cnum == numloc)
   {
   if(buffc[i].as == asloc)
   {

   if(buffc[i].ai == ailoc)
    {
	 if(buffc[i].ar == arloc)
    {
	 if(buffc[i].isRS485 == isrs485)
    {
     return 1;}
	}
	}
	}
	}
}
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
	  return 0;
}

int short EmbMsg::IsEnd()
{
  //120713	if(body[0])
// if(counter) printfpd("c-%d-", counter);
		if(counter>10)
		{
			if(counter==Length()+13)
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

#include "embmsg485.cpp"
//msg485______________________
#define   EmbMsg485Buffer_Size (16)
struct EmbMsg485Buffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
  //  EmbMsg Buff[32];
   // EmbMsg Buff[16];
	  EmbMsg485 Buff[EmbMsg485Buffer_Size];
  public:
    void Init();
    void Add(EmbMsg485&);
    void Get(EmbMsg485&);
    unsigned short Used();
    unsigned short Free();
};

void EmbMsg485Buffer::Init()
{
  BuffSize = EmbMsg485Buffer_Size;
  Head = 0;
  Tail = 0;
}

void EmbMsg485Buffer::Add(EmbMsg485 &msg)
{
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize)
  {
   
   Head = 0;
   }
}

void EmbMsg485Buffer::Get(EmbMsg485 &msg)
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

unsigned short EmbMsg485Buffer::Used()
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

unsigned short EmbMsg485Buffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}
/////////////////////


//msg485______________________


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

//#include "embmsg485.cpp"

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


EmbMsgBuffer rBuffEmbMsg;

		
	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;

	EmbMsg embMsg232;

//____________________________________________________________________________232e
#ifndef ETH_TRANZIT
EmbMsg embMsg232E;
#endif // ETH_TRANZIT
//____________________________________________________________________________232e
 EmbMsg embMsg485E;
 EmbMsg embMsgWest[MODEM_QUANTITY]; //101224 many channells to keep messages

//#ifdef ETH_TRANZIT

 EmbMsg embMsgEthTransitW;
 EmbMsg embMsgEthTransitE;
 EmbMsg embMsgWestE;	 //1223

 EmbMsgBuffer tBuffEmbMsgEthAll;
 EmbMsgBuffer tBuffEmbMsgEthAll1;

   
	EmbMsg485 embMsg485_1;
	EmbMsg485 embMsg485_2;

	EmbMsg485 embMsg485Request_1;
	EmbMsg485 embMsg485Request_2;

EmbMsg485Buffer tBuffEmbMsg485Request_1;
EmbMsg485Buffer tBuffEmbMsg485Request_2;


#ifdef RS485_MSG_BUFF
	   EmbMsgBuffer tBuffRS485;
	   unsigned long time_lastsend_rs485;
	   unsigned char flag_wait_rs485;
#endif

	EmbMsg embMsgEast;
	EmbMsg embMsgAns;
 //	EmbMsg embMsgTemp;
//	EmbMsgCover embMsgCoverRequest;
	EmbMsg *embMsgRequest;

	EmbRS232 embRS232;
	EmbRS485 embRS485;
#ifndef PROG_BMDN6MI   
   UnStateRRL unStateRRL;
#endif
   EmbMsg embMsg485;
	EmbSerialMD34AVTProv embSerialACT155;

	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned char request1=0, request2=0;
	unsigned long /*time3Marker[MODEM_QUANTITY],*/ time3BlankTransit=0, time3BlankMod[MODEM_QUANTITY];
	unsigned long time1test=0;
	unsigned char markerWest[MODEM_QUANTITY], markerEast=0, ready_transit=0, ready_mod[MODEM_QUANTITY], dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod[MODEM_QUANTITY]; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest[MODEM_QUANTITY], recieveEast=0;
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

	unsigned char mode5A=0, mode5AWest[MODEM_QUANTITY], mode5AEast=0;
   	unsigned char mode5AUp1, mode5AUp2; 

//	unsigned char mode5A232E = 0;
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;

//________________________________________________________
	unsigned char modeA5West[MODEM_QUANTITY];
	TRBuffer<char,ACT_BUFFER_SIZE> embMsgWestR[MODEM_QUANTITY];
//________________________________________________________

	unsigned countUD1;
	unsigned countUD2;

	unsigned char cycle=0;

	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned short err_tr=0;
	unsigned short err_md=0;

	UnStateBMD155 unStateBMD155;
 //	UnStateBMD155 unStateBMD155p[MODEM_QUANTITY<<1];
	UnStateBMD155 unStateBMD155p[MODEM_QUANTITY];
	UnEmb2TypeVer unEmb2TypeVer; 
	UnStatePUM unStatePUM;
	UnStatePUM unStatePUMp[MODEM_QUANTITY];
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

#define TIME_WAITING_FAR_END	  (STATE_SCAN_PERIOD + 1000l)
#define		FAR_ERR_TRESHOLD	  (1000l) //for example errors from 5sec
#define PERIOD_MIN_MAX 	(10)
#define   NO_LOCK_LEVEL (-100)

unsigned char racm, racm_far, flag_racm_far, flag_racm_fart, racm_old;
float64 MEbN0_UP, MEbN0_DOWN;

 /*
char ProtocolFromModACT155()
{

 
	int ic=0;
	static char test23 = 0;
	unsigned char req = 0;
	static unsigned long oldtime[MODEM_QUANTITY];

	unsigned long curerr1;
	static unsigned long curerr1_old;

	unsigned long curerr2;
	static unsigned long curerr2_old;
	static unsigned char flag_min_max;


   for(long i = 0; i < MODEM_QUANTITY; i++ )
 {
  if( oldtime[i] > time1) oldtime[i] = time1;
  if((time1 - oldtime[i]) > TIME_WAITING_FAR_END)
  {
	 oldtime[i] =  time1;

	  flag_min_max++;
	  if(flag_min_max > PERIOD_MIN_MAX)  flag_min_max = 0;

 //	 if(flag_min_max > (PERIOD_MIN_MAX >> 1))
 //	 {
 //	 flag_min_max = 0
	 farinplev1 = NO_LOCK_LEVEL;
	 farinplev2 = NO_LOCK_LEVEL;
 //	 }
 //	 else
 //	  {
//	 flag_min_max = 10
 //	 farinplev1 = 0;
 //	 farinplev2 = 0;
 //	 }


     outportb((BLOCK_SWEEP1*(i + 1) + FAR_LED_PORT), req);
  }

#ifdef DEBUG_LOOP_PRINT
	   //ok		printfp("_M");
#endif

	while(embSerialACT155.UsedMod(i))
	{
			westByte = embSerialACT155.GetMod(i);

#ifdef DEBUG_LOOP_PRINT
	 		printfpd("_%02X_", westByte);
#endif		
			switch(westByte)
			{
			case 0x55: time3BlankMod[i] = time1; ready_mod[i]=1; recieveWest[i]=0; embMsgWest[i].Init(); break; 			
			case 0xAA: recieveWest[i] = 1; ready_mod[i]=1; time3BlankMod[i] = time1; embMsgWest[i].Init();	break; 			
			case 0xA5: recieveWest[i] = 1; modeA5West[i]=1; markerWest[i]  = 1; ready_mod[i]=1; time3BlankMod[i] =  time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest[i]=1; ready_mod[i]=1; break;
			default:
				if(markerWest[i]==1)	markerWest[i]=2; 
				if(recieveWest[i]==1)
				{
				 if(modeA5West[i]) { embMsgWestR[i].Add(westByte); modeA5West[i]=0;	
				 
			   //	  ParseRequestsRezervResponses();
 				 }
					else if(mode5AWest[i]) { embMsgWest[i].Add(Modify5A(westByte)); mode5AWest[i]=0;	}
				  //	else if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
					else embMsgWest[i].Add(westByte);
				}
			}

if(embMsgWest[i].IsEnd())
   {

//ok  printEthLongHex(embMsgWest[i].AddrS());
   printfp("\n\r_1");
   recieveWest[i] = 0;
#ifdef CHECK_CRC   
  if(embMsgWest[i].ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
	{
	
    printfp("\n\r_2");
							   //091111
//ok	  printEthLongHex(embMsgWest[i].AddrS());

#ifdef SEND_STATUS	
 if(embMsgWest[i].AddrS() == DEFAULT_ADDR)
 {

//?? need check crc?
#ifdef DEBUG_LOOP_PRINT
  printfpd("\n\r %02X",embMsgWest[i].Body(0));	  //far dev_status	 
  printfpd(" %02X",embMsgWest[i].Body(1)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(2)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(3)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(4)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(5)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(6)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(7)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(8)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X\n\r",embMsgWest[i].Body(9)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd("racm : %02X\n\r",embMsgWest[i].Body(12));  //racm
#endif
 //	  CHANNEL1_LOCK_BIT
 //	  CHANNEL2_LOCK_BIT
if((embMsgWest[i].Body(13) == SIGNATURA)  && (embMsgWest[i].Body(14) >= 2))
{
 racm_far = embMsgWest[i].Body(12);
 flag_racm_far = 1;
// flag_racm_fart = 1;
}

curerr1 = (embMsgWest[i].Body(2) << 24) + (embMsgWest[i].Body(3) << 16) + 
			   (embMsgWest[i].Body(4) << 8) + embMsgWest[i].Body(5);

  if((embMsgWest[i].Body(0) & PROV0_MASK) &&
	  (embMsgWest[i].Body(0) & P710_0_MASK) &&
	  	  (!(embMsgWest[i].Body(1) & CHANNEL1_LOCK_BIT)))	 //inversion
		  {
		   if((curerr1 - curerr1_old) < FAR_ERR_TRESHOLD)
			   {
			  		req |= FAR1_GREEN;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 ok");
#endif
			   }
			   else
			   {
			   //yellow
			  		req |= FAR1_GREEN;
					req |= FAR1_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 ok + err");
#endif

			   }


		  }
		  else
		  {	
		  			 req |= FAR1_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 bad");
#endif

		  }

curerr1_old = curerr1;

curerr2 = (embMsgWest[i].Body(6) << 24) + (embMsgWest[i].Body(6) << 16) + 
			   (embMsgWest[i].Body(8) << 8) + embMsgWest[i].Body(9);

farinplev1 = -85  + (signed long)(embMsgWest[i].Body(10)>>1);
farinplev2 = -85  + (signed long)(embMsgWest[i].Body(11)>>1);

  if((embMsgWest[i].Body(0) & PROV1_MASK) &&
	  (embMsgWest[i].Body(0) & P710_1_MASK) &&
	  	  (!(embMsgWest[i].Body(1) & CHANNEL2_LOCK_BIT)))	 //inversion
		  {
	      	 if((curerr2 - curerr2_old) < FAR_ERR_TRESHOLD)
			   {
			  	req |= FAR2_GREEN;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 ok");
#endif

			  }
			  else
			     {
			  	req |= FAR2_GREEN;
				req |= FAR2_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 ok + err");
#endif

			  }
		  }
		  else
		  {
			 req |= FAR2_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 bad");
#endif

		  }
  curerr2_old = curerr2;

   oldtime[i] =  time1;
   outportb((BLOCK_SWEEP1*(i + 1) + FAR_LED_PORT), req);

  embMsgWest[i].Init();	 //121204
   return 0;
 }
#endif //send status


   	if((embMsgWest[i].AddrS()!=SelfID())&&(embMsgWest[i].AddrI()!=SelfID()))
	{
	  	// передаем побайтно дальше принимаем пакет
	//ok	   printEthLongHex(1);

	 //	   if(buff_cashe_tranzit.compare((unsigned long)embMsgWest[i].body[1], (unsigned long)embMsgWest[i].AddrS(), (unsigned long)embMsgWest[i].AddrI(), (unsigned long)embMsgWest[i].AddrR(), (unsigned long)embMsgWest[i].IsRS485()) != 1)
   	 //121211	   	if(1)
			 if(ForwardingEnabled())
   		   	{
		//	printfp("\n\r________t0");
		//	printfpd("s: %X ",embMsgWest[i].AddrS());
		//	printfpd("i: %X ",embMsgWest[i].AddrI());


		 //	 buff_cashe_tranzit.add(embMsgWest[i].body[1], embMsgWest[i].AddrS(), embMsgWest[i].AddrI(), embMsgWest[i].AddrR(), (unsigned long)embMsgWest[i].IsRS485());

					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(long ib=0; ib<embMsgWest[i].FullSize(); ib++) 
					{
						switch(embMsgWest[i].body[ib])
					   {
					 	case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgWest[i].body[ib]);						}
					   }
					 }
				   embSerialACT155.AddTransitM(0x55);

				}

 //ok  printEthLongHex(2);

#ifndef ALL_ADDR					
				if(embMsgWest[i].AddrS()==SelfID())
#else  // ALL_ADDR	
				if(1)
#endif // ALL_ADDR	
				{

					embMsgWest[i].SetDir(1);
				    rBuffEmbMsg.Add(embMsgWest[i]);
					embMsgWest[i].Init();
				}
				  embMsgWest[i].Init(); //101210
}
else   //091111
{
 embMsgWest[i].Init();	  //091111
}	 //crc

  embMsgWest[i].Init();	  //121211

} //is end





} //i
} //while

//		if(!recieveWest)
		{
			if(tBuffEmbMsgWest.Used())
			{
		//	printfp("\n\r________t1");
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
				    embSerialACT155.AddTransitM(0x55);
			}
		}  //is end
 //121209	}	  //while



 return 0;
}
	 */
char ProtocolFromTransitACT155()
{
	int ic=0;
	unsigned char chn;

	while(embSerialACT155.UsedTransit())
	{
		eastByte = embSerialACT155.GetTransit();
#ifdef ETH_TRANZIT
//t090708		AddCharEastE(eastByte); //t
#endif // ETH_TRANZIT

	   switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init();//tInitEastE(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init();//t InitEastE(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit /*= time3Marker*/ = time1;  break; // Маркеров здесь НЕТ!
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
if(embMsgEast.IsEnd())
{
  recieveEast=0; //101210
  
#ifdef CHECK_CRC  
 if(embMsgEast.ChkCRC()) //120608	  //091111
#else 
	if(1)
#endif   
	{						   //091111

			  recieveEast=0; //091111
	//ok	   printf("p0");

			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{

//   if(buff_cashe_modem.compare((unsigned long)embMsgEast.body[1], (unsigned long)embMsgEast.AddrS(), (unsigned long)embMsgEast.AddrI(), (unsigned long)embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485()) != 1)
   		   //	 if(1)
		   if(ForwardingEnabled())
   		   	{
 //  			 buff_cashe_modem.add(embMsgEast.body[1], embMsgEast.AddrS(), embMsgEast.AddrI(), embMsgEast.AddrR(), (unsigned long)embMsgEast.IsRS485());
             chn = 	GetChannelToSend();		
			
				embSerialACT155.AddMod(0x55, chn);	
				embSerialACT155.AddMod(0xAA, chn);	
				for(i=0; i<embMsgEast.FullSize(); i++) 
				{

					switch(embMsgEast.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x00, chn); break;
					case 0x55: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x01, chn); break;
					case 0xA5: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x02, chn); break;
					case 0xAA: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x03, chn); break;
					default: embSerialACT155.AddMod(embMsgEast.body[i], chn);
					}
				}
			   embSerialACT155.AddModM(0x55, chn);
			 }
			countSend++;
			}
#ifndef ALL_ADDR			
	 	 	if(embMsgEast.AddrS()==SelfID())
#else
			if(1)	  //t 090427
#endif //ALL_ADDR
			{
#ifdef DEBUG_TRANZIT
			 rxtransb++;
			 printfpd(" r: %d ", rxtransb);
#endif

		 //ok	printf("pa");
		   //		printf("\n\r CRC : %X CalcCRC : %X" , embMsgEast.CRC(), embMsgEast.CalcCRC());
				embMsgEast.SetDir(2);
				    rBuffEmbMsg.Add(embMsgEast);
				embMsgEast.Init();
			} //selfid
			
			embMsgEast.Init(); //101210
		}	 //crc
		else
		{
		  embMsgEast.Init();
		}	//crc
	     embMsgEast.Init();
} //is end

}//121209 while

#ifdef DEBUG_LOOP_PRINT

				  //		   printfp("_U1");
#endif


//		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
#ifdef DEBUG_LOOP_PRINT

				  //		   printfp("_U2");
#endif


				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
                chn =  0; //	GetChannelToSend();	

	   //			printfpd("sch:%d", chn);

				embSerialACT155.AddMod(0x55, chn);
				embSerialACT155.AddMod(0xAA, chn);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x00, chn); break;
					case 0x55: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x01, chn); break;
					case 0xA5: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x02, chn); break;
					case 0xAA: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x03, chn); break;
					default: embSerialACT155.AddMod(embMsgA.body[i], chn);
					}
   //					ResetWatchDog();
				}
				embSerialACT155.AddModM(0x55, chn);
			}

	  
		  		}  //(1)
 //121209			}	 //while
	return 0;
}

#define TRANZIT_SEND_PERIOD (4500) //9 modems - *9

void Check2InitTransitMod()
{

unsigned char chn;

	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
// Если произошло изменение ready_transit или ready_mod из "0" в "1"
// то time3Marker = 0; под пакет 2355 байта и скорость 64К*8/11=46545
  
	if((time1-time3highID)>10000) 
	{
		time3highID=time1;
	}		



 
 

	if((time1-time3highID)>10000) 
	{
		time3highID=time1;
	}		
//		if(!recieveEast)
		{
	   //	 	printf(">");
					if(tBuffEmbMsgEast.Used())
		{

	   
	  chn =  0;//	GetChannelToSend();
		/*
	  if(chn == NO_MODEM)
	  {
  #ifdef DEBUG_LOOP_PRINT

	  	printfp("return no send ");
  #endif
	   return;
	   }
	   else
	   {
  //	   printfpd("\n\rich : %d", chn);
	   } 
	   	   */
#ifdef DEBUG_LOOP_PRINT

					//	   printfp("_U");
#endif


				if(!embSerialACT155.UsedSendMod(chn)) 
				{	
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);

 //t printEthLongHex(embMsgA.AddrI());
					
						embSerialACT155.AddMod(0x55, chn);
						embSerialACT155.AddMod(0xAA, chn);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
#ifdef DEBUG_LOOP_PRINT

						   printfpd(".%02X.",embMsgA.body[i]);
#endif
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x00, chn); break;
							case 0x55: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x01, chn); break;
							case 0xA5: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x02, chn); break;
							case 0xAA: embSerialACT155.AddMod(0x5A, chn); embSerialACT155.AddMod(0x03, chn); break;
							default: embSerialACT155.AddMod(embMsgA.body[i], chn);
							}
		//					ResetWatchDog();
						}
						embSerialACT155.AddModM(0x55, chn);
#ifdef DEBUG_LOOP_PRINT

				   	     printfp("\n\r");
#endif
					}
				}
		}

//		if(!recieveWest)
		{
			if(!embSerialACT155.UsedSendTransit()) 
			{	
#ifdef ETH_TRANZIT

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
					embSerialACT155.AddTransitM(0x55);
				}
			}
  		}
 	}


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

//#ifdef ETH_TRANZIT

unsigned char IsEthTransitMode(void)
{
 if (read_nvram_char(ETH_TRANZIT_ON_ADDRESS) ==	 ETH_TRANZIT_ON_VALUE) return 1;
 else return 0;
}
//#endif //  ETH_TRANZIT


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
unsigned long sendboxes;
unsigned long receivedboxes;
unsigned long error_timer;
unsigned char current_channel;
unsigned long used_modems;
//double KoefErrors[MODEM_QUANTITY << 1];


//  long err_tmp_now = 0l;			 // need init!!!!!
	 long err_tmp_prev1 = 0l;
    long err_tmp_prev3 = 0l;
    long err_tmp_prev4 = 0l;

/*
extern "C" void CommutateModForSS()
{
//hier will be write to xilinx


}
*/

extern "C" void Init_structs()
{
// unsigned long mod, mod1;
 for(long ic = 0; ic < (MODEM_QUANTITY); ic++)
  {
//  mod = ic<<1;
//  mod1 = mod+1;
//_____________________________________________________
	for(i=0; i<16; i++)
	{
   		unStateBMD155p[ic].stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155p[ic].stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155p[ic].stateBMD155.state=0;
	}

	unStateBMD155p[ic].stateBMD155.count_block=0;
	unStateBMD155p[ic].stateBMD155.count_no_correct_block1=0;
	unStateBMD155p[ic].stateBMD155.count_no_correct_block2=0;
	unStateBMD155p[ic].stateBMD155.count_no_correct_result=0;
	unStateBMD155p[ic].stateBMD155.count_notRS1=0;
	unStateBMD155p[ic].stateBMD155.count_notRS2=0;
	unStateBMD155p[ic].stateBMD155.demPI=0;
	unStateBMD155p[ic].stateBMD155.loopPI=0;
	unStateBMD155p[ic].stateBMD155.statePI=0;
//______________________________________________________

				unStatePUMp[ic].statePUM.ulErrOut 		  = 0;
				unStatePUMp[ic].statePUM.ulBlock 		  = 0; 
  				unStatePUMp[ic].statePUM.ulErrAfterRS1 	   = 0;
				unStatePUMp[ic].statePUM.ulErrBeforeRS1    = 0;
   }
}

unsigned long RestartTestE;
unsigned long RestartTest;
unsigned char reqcounter[MODEM_QUANTITY];
unsigned char rescounter[MODEM_QUANTITY];


 unsigned char currentgetrezerv;	//current modem is on protection transmit
 unsigned char currenthaverezerv;	//current modem is on protection receive
 unsigned char currentrezerv;

#ifndef PROG_BMDN6MI
StatRez statrez[MODEM_QUANTITY];
#endif

//unsigned char current_rezerv;
unsigned long protection_mode;
unsigned long norma_status[MODEM_QUANTITY << 1];
//unsigned long check_norma_status;
//#define NO_MODEM   (0xff)f)

unsigned long time_start_prt, time_rcv_req_to_get, time_end_prt;

unsigned long ans_correct, ans_correctr,ans_no_correct, ans_no_correctr;
unsigned short acmmask0;
unsigned long timer_config;
unsigned char currenttrunk;
unsigned char cur_err;
unsigned char  flag_trunk;
unsigned char OldStatus;
signed long farinplev1;
signed long farinplev2;
unsigned char pdpower1;
unsigned char pdpower2;
unsigned char deltapdpower1;
unsigned char deltapdpower2;

unsigned char flag_enable_operate_power1;
unsigned char flag_enable_operate_power2;
unsigned char operate_power_mode;
unsigned long try_counter1;
unsigned long try_counter2;
unsigned char power_modul;
unsigned long power_rate;
unsigned char flag_command_power; 

unsigned long modem_bytes_counter;
unsigned long transit_bytes_counter;
unsigned long modem_bytes_time;
unsigned long transit_bytes_time;
unsigned long  timeChannels;


unsigned long command_counter;

unsigned long txtrans, rxtrans, txmod, rxmod;
unsigned long txtransb, rxtransb;//, txmod, rxmod;
unsigned long txusart, rxusart;

//unsigned long irq0_limit;

unsigned char used_TCP;
unsigned long ver_api;

unsigned char send_keeper1, send_keeper2;
unsigned char  hot_restart;

unsigned long syntez_error_counter;
unsigned long pvg710_error_counter;
unsigned long flagproti;

#ifdef PROG_MD310_SAT

unsigned long SetACMCounter;
#endif

#ifdef IncEmbIndicator
 EmbIndicator embIndicator;
//void ToIBuf(unsigned char data);
//extern "C" void PultDelay(void);
#endif

EmbRS232 embRS232S;
 unsigned long password_state;
 unsigned char key_enter_flag;
#ifdef USE_HTTP
unsigned long page_number;
unsigned long start_event;
#endif

   /*
extern "C" void CheckWEBData()
{

}
 */
extern "C" void CheckUsedData()	 //hier need check ConfigFile.Value
{

}


//unsigned char ReallyNumCfg[MAX_CFG_FILE_VARIANT];

//unsigned char ReallyNumCfg[MAX_NUM_CFG1];
unsigned long ReallyNumCfg[MAX_NUM_CFG1];	//160220

float errf;
float dataf;

double ethsend;
double ethreceived;
  extern "C" unsigned char EventToMenu1();

unsigned char acm_status;
unsigned char acm_status1;


unsigned char CON_IFSAT140;	//operate if block

PVG610_NET_ETH_PM_STRUCT Pma;
unsigned char Er, Et;

unsigned char Ld0, Ld1;


unsigned long timescan;

extern unsigned char use_md310_snmp;
extern unsigned char no_high_freq_char;

float64 blocks, uncblocks;
float64 blocks6, uncblocks6;
float64 blocks7, uncblocks7;
float64 blocks8, uncblocks8;
float64 blocks9, uncblocks9;
float64 blocks10, uncblocks10;
float64 blocks11, uncblocks11;
float64   MEbN0_snmp;

//unsigned char racm, racm_far;


unsigned long timelock;
unsigned long timechangemode;
unsigned long timekeepMSE;
float gmse;

 unsigned lost_mailboxes;
unsigned long  timestep_far;


extern "C" void Init_BMDN(void)
{
 timestep_far = MIN_ratimestep << 2;
lost_mailboxes = 0;
gmse = 0;
timelock = 0;
timechangemode = 0;
timekeepMSE = 0;

racm =  racm_far = 0; //RACM_DO_NOT_CHANGE;
flag_racm_far = 0;
flag_racm_fart = 0;

racm_old = 255;  //to run from first step

MEbN0_snmp = 0;
blocks = uncblocks = (float64)0l;
blocks6 = uncblocks6 = (float64)0l;
blocks7 = uncblocks7 = (float64)0l;
blocks8 = uncblocks8 = (float64)0l;
blocks9 = uncblocks9 = (float64)0l;
blocks10 = uncblocks10 = (float64)0l;
blocks11 = uncblocks11 = (float64)0l;

 // return; //150224
// no_high_freq_char= 0;
// use_md310_snmp = 0; //for do not forgot snmp only

 Ld0 = 1;
 Ld1 = 1;

 Er = 0;
 Et = 0;

  //okreturn;
CON_IFSAT140 = 0;

oldflag_ifloop = 0x99;
oldflag_unmodul = 0x99;
oldflag_mrcntl = 0x99;
oldflag_alarms = 0;


acm_status = 1;  //t
acm_status1 = 1;  //t


ethsend = 0l;
ethreceived = 0l;

errf = 0.0;
dataf = 0.0;

//Init_web_prm();

//return;
//SetUsart2BaudRate(38400l);
//CheckParameters();


#ifdef USE_HTTP
Init_web_prm();
 start_event = 1;
#endif


password_state = 0;
//password_state = 1;	 //for test

key_enter_flag = 0;

  #ifdef PROG_MD310_SAT
  SetACMCounter = 0;
 //printfp("\n\r  INIT");
#endif




 flagproti  = 1;
 syntez_error_counter = 0;
 pvg710_error_counter = 0;

 // return;
 //check_norma_status = 0;
 hot_restart = 0;
  txusart = rxusart = 0;
  send_keeper1 = send_keeper2 = 1;

  ver_api = GetVersionAPI();

used_TCP = 0;
//irq0_limit = IRQ0_LIMIT;

txtrans = rxtrans =  txmod =  rxmod = 0;

txtransb = rxtransb = 0;


timeChannels = 0;
 modem_bytes_counter = 0;
 transit_bytes_counter = 0;
  modem_bytes_time = 0;
 transit_bytes_time = 0;


command_counter = 0;
power_modul = 0;
power_rate = 0;
flag_command_power = 0;
farinplev1 = -85;
farinplev2 = -85;

pdpower1 = 140;
pdpower2 = 140;
deltapdpower1 = 1;
deltapdpower2 = 1;
flag_enable_operate_power1 = 1;
flag_enable_operate_power2 = 1;
operate_power_mode = 1;
try_counter1 = 0;
try_counter2 = 0;

//#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
// if(deviceindex == 0) return 1; //for test
// if(deviceindex == 0) return 1; //for test
 //  return;
//#endif //MAKET_PLATA

 OldStatus = 0x0F;
//hier fall return; //t
timer_restart = 0l;
 cur_err = 0;
 flag_trunk = 0;
 currenttrunk = 0;
#ifndef PROG_BMDN6MI
 trunk1.byte = 0;
 trunk2.byte = 0;
#endif
 power1 = 0;
 power2 = 0;

 flagloop0 = 0;
 flagloop1 = 0;
 flagunmod0 = 0;
 flagunmod1 = 0; 
 flagbbloop0 = 0;
 flagbbloop1 = 0;
 flagifloop0 = 0;
 flagifloop1 = 0;
 timer_oper_prog = 0;
// flagModForSS  = (GetModForSS() & MASK_BIT_0) ? 1 : 0;

//some for computer indikating
#ifndef PROG_MD310
#ifndef PROG_BMDN6MI
 flagModForSS  = GetModForSS() +  (GetModForSS1() << 1);
#else // PROG_BMDN6M
  flagModForSS  = 0 +  (GetModForSS1() << 1);
#endif	// PROG_BMDN6M

#else
 flagModForSS  = 0 +  (GetModForSS1() << 1);
#endif

#ifdef O_POWER

 if(!GetModForSS1())
{
  ClearBufferState((unsigned long)OPERATE_POWER_ON);
  DisableOperatePower(0);
  DisableOperatePower(1);
}
 else
{
  SetBufferState((unsigned long)OPERATE_POWER_ON);
  EnableOperatePower(0);
  EnableOperatePower(1);
}

#endif

 //ok2return;
#ifndef PROG_BMDN6MI
unStateRRL.stateRRL.ver = 0x01;
unStateRRL.stateRRL.state = 0x01;
#endif

countUD1=0;
countUD2=0;

mode5AUp1 = 0;
mode5AUp2 = 0; 

oldflag = 0xff;
//oldflag_710 = 0xff;
//oldflag_ud1 = 0xff;
//oldflag_ud2 = 0xff;
oldflag_prv = 0xff;
oldflag_prv1 = 0xff;
dev_status = 0x0;
acmmask0 = 0;
ans_correct = 0;
ans_correctr = 0;

ans_no_correct = 0;
ans_no_correctr = 0;

#ifdef PRINT_START
//printfp("\n\r Init_BMDN");
#endif
 time_start_prt = 0;
time_rcv_req_to_get = 0;
time_end_prt = 0;

//ok 120608 return;

for(unsigned long im= 0; im < (MODEM_QUANTITY<<1); im++)
{
 norma_status[im] = 0; //ALARM_QUANTITY + 1; //0;
}
NeedWriteID = 0;

 /*
tmp =  GetPriorityZero();

if(tmp != NO_MODEM)
{
   protection_mode = MODE_N_PLUS_1;
   currentrezerv = tmp;
}
else
{
  protection_mode = MODE_NO_PROT;
  currentrezerv = NO_MODEM;
}

*/

   protection_mode = MODE_1_PLUS_1;
//  protection_mode = MODE_N_PLUS_1;
//protection_mode = MODE_NO_PROT; //for sergey
//current_rezerv = 0xff; //do not stay any on rezerv 

// = 0;
//rescounter = 0;

currentgetrezerv = NO_MODEM;
currenthaverezerv = NO_MODEM;
//tcurrentrezerv = ZERO_MODEM; //now use zero modem for rezerv
#ifndef PROG_BMDN4
currentrezerv = FOUR_MODEM;
#else
currentrezerv = NO_MODEM;  //this make error
#endif

RestartTestE = 0;
RestartTest = 0;
// err_tmp_now = 0l;			 // need init!!!!!
 err_tmp_prev1 = 0l;
 err_tmp_prev3 = 0l;
 err_tmp_prev4 = 0l;


 current_channel = 0;
 error_timer = 0;
 sendboxes = 0;
 receivedboxes = 0;
 count_send = 0;
 count_res = 0;
 count_res_ok = 0;
 count_res_bad = 0;

AsciiInit();
EmbInit(); //my


//ok 120608 return;

  time1=0;
  flagRequest=0;
  serr=0xFF; crc_temp=0;
  i=0;
  time1old=0; time2old=0;
  request1=0; request2=0;
 // time3Marker=0; 
  time3BlankTransit=0;// time3BlankMod=0;
  time1test=0;
  /*markerWest=0;*/ markerEast=0; ready_transit=0; /*ready_mod=0; */ dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0;/* old_ready_mod=0;*/ // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgWest=0; delete_msgEast=0; /*recieveWest=0;*/ recieveEast=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0;/* mode5AWest=0; */ mode5AEast=0; 

 for(long i = 0; i < MODEM_QUANTITY; i++)
 {
   recieveWest[i]=0;
   ready_mod[i]=0;
   modeA5West[i]=0;
   markerWest[i]=0;
   time3BlankMod[i]=0;
   mode5AWest[i]=0;
   old_ready_mod[i]=0;
  // time3Marker[i]=0;
  embMsgWestR[i].Init();
  // time3Marker[i]=0;
 // embMsgWestR[i].Init();
 reqcounter[i] = 0;
 rescounter[i] = 0;
 }
 //___________________________________________
 //   modeA5West=0;
 // 	embMsgWestR.Init();
//________________________________________________________



  cycle=0;

	ttbb=0;
	mtbb=0;
	count_tr=0;
	count_md=0;
	err_tr=0;
	err_md=0;
     
	rrr=0;
//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

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
#endif
#endif
//	outportb(0x6FF,inportb(0x6FF)|0x10);


///////  Канал транзит  ///////
//	time5=0;
//	outportb(0x5B7, 0x94);
///////////////////////////////

//ok120608  return;

	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
	tBuffEmbMsg485Request_1.Init();
	tBuffEmbMsg485Request_2.Init();
#ifdef ETH_TRANZIT
    rBuffEmbMsgE.Init();
	rBuffEmbMsgEast.Init();
	rBuffEmbMsgWest.Init();
#else
	rBuffEmbMsg.Init();
#endif //ETH_TRANZIT


#ifdef RS485_MSG_BUFF
	   tBuffRS485.Init();
	   time_lastsend_rs485 = 0;
	   flag_wait_rs485 = 0;
#endif //RS485_MSG_BUFF

//ok120608 return;
// return;
 //	ResetWatchDog();
// return;
 //   mod_en = ModemIsUsed(0);
//____________________________h i e r e n a b l i n g i  n t e r r u p t s  i n x i l i n x !!  
	embSerialACT155.Init();	//120608   //hier hangt!!!!
   
//bad 120608 return;   
//ok2  return;
 //in EmbInit()	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
 //in EmbInit()	embRS485.Init(384);		// Инициализация RS485 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
	   
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
	   
//bad 120608 return;

//////////////////////
//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

 	InitTLF();
//	Ring();
	for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
	tlf_counter=0;
#endif
#endif

	for(i=0; i<MODEM_QUANTITY<<1; i++)
//101212	for(i=0; i<16; i++)
	{
 //maked in function init		modemp[deviceindex].TimesTryGetLock = 0;
   		modemp[i].alarm = 0;
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
 //this is error - not testet from usedmod() : will brocken buffer!		embSerialACT155.GetMod();
// this is error - not testted	frorousedtransit : will brocken buffer!	embSerialACT155.GetTransit();
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
	unEmb2TypeVer.emb2TypeVer.type       = 0x0116;
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

	for(i=0; i < ulevelsn15503_SIZE; i++)
	{
	  ulevelsn15503.byte[i] = 0;
	}

	for(i=0; i < uerrsn15503work_SIZE; i++)
	{
	  uerrsn15503work.byte[i] = 0;
	}

//101008	unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = read_xil_char(1);
//101008	unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = read_xil_char(2);
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = read_xil_char(1);
			unEmb2TypeVer.emb2TypeVer.signature_hardware[14] = read_xil_char(2);

	unEmb2TypeVer.emb2TypeVer.signature_hardware[15] =  read_nvram_char(RESTARTS_NVRAM_ADDRESS);
	write_nvram_char(RESTARTS_NVRAM_ADDRESS, (unEmb2TypeVer.emb2TypeVer.signature_hardware[15] + 1));
  //	bt = (unsigned char far*)0x80000000;
//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI


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
#endif
#endif 

 //	embMsgTemp.Init();

//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

	Wait();
//	Ring();

	presto_time = time1;
#endif
#endif
//______________________________Init All EmbMsgObjekts

   embMsg232.Init();
//#ifndef ETH_TRANZIT
   embMsg232E.Init();
//#endif // ETH_TRANZIT
   embMsg485E.Init();


	embMsgEast.Init();
	embMsgAns.Init();
 //	embMsgTemp.Init();
//	EmbMsgCover embMsgCoverRequest;
	embMsgRequest = NULL;
//____________________________________________provingent
//PVG610_API_Open();
//#define ADDR_ADDR 0x4
//#define SPI_ADDR  0x8
//#define SYSTEM_CLOCK_IN_HZ (6000000);

//if( GetTestMode() != 0x8e)
//{
//111213 write_xil_char(ADDR_ADDR, SPI_ADDR); //init in xilinx address for spi 

#ifndef BMDN_CONNECT_USART
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, 200000000l);
#else
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, 200000000l);
#endif

//bad return;
InitOperProg();

//bad 120608 return;
FillMenu(); //temporary keep hier fill items for indikator; need set it to property point
SetItemConfig();
ReadRAnyConfigs();

//return; //t
FillFirmwareFileData();

//ok return; //t




InitStructs();

//ok return;

//StartLoadAllM(); //temporary hieer; need in end

//okreturn; 

EventToMenu1();

//wrong  return;

ReadIFmoduleHeader();

#ifndef WIFM
ReadIFmoduleData();
#endif

InitIFModule();
StartLoadAllM(); //temporary hieer; need in end

  //ok  return; //150224

//wrong return;
//160614 ACM_MODE_PULL_init();

 if(!MirrorTest())	return;	   //it is NOT hot restart - this maked to do not hangt without modem plata

 //========================================================================================

unsigned long ir;


#ifndef BMDN_CONNECT_USART

#ifndef MANY_MODEMS
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);
#else  //MANY_MODEMS
for(im= 0; im < MODEM_QUANTITY; im++)
{
//KoefErrors[im] = 0;


ir = im << 1;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);
//PVG610_API_ComTimeoutSet(ir, 3); //110413

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
ir++;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);
//PVG610_API_ComTimeoutSet(ir, 3); //110413
 
#endif
}
#endif //MANY_MODEMS


#else

//PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);
for(im= 0; im < MODEM_QUANTITY; im++)
{
ir = im << 1;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);
//PVG610_API_ComTimeoutSet(ir, 3); //110413

#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
ir++;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);
//PVG610_API_ComTimeoutSet(ir, 3); //110413
#endif
}


#endif

	 



//#ifndef MAKET_PLATA
//  SetUsart0BaudRate(115200l);
//#else
  SetUsart0BaudRate(38400l);
//#endif //MAKET_PLATA



//PVG610_API_ComTimeoutSet(0, 100);   //100 ms timeout ????
//100605 PVG610_API_ComTimeoutSet(0, 1000);   //100 ms timeout ????
//okPVG610_API_ComTimeoutSet(0, 5);  //100506 //100 ms timeout ????	  0,4%
//PVG610_API_ComTimeoutSet(0, 2);  //100506 //100 ms timeout ????	10%
//PVG610_API_ComTimeoutSet(0, 8);	 //0,2%
//PVG610_API_ComTimeoutSet(0, 4);	  //0,2%
//PVG610_API_ComTimeoutSet(0, 3);	  //1%
//t 100519 PVG610_API_ComTimeoutSet(0, 5);
//110413 PVG610_API_ComTimeoutSet(0, 3); //100519
//} //testmode != 0x8e


//____________________________________________provingent

 /*
FirmwareLoad();
ConfigFileLoad();
ConfigFileRun();
ModemStatusGet();  //old data
ModemStatusGet();
 */

//____________________________________________________________
staterezerv = 0;




//for(unsigned long im= 0; im < MODEM_QUANTITY; im++)
//{
// Modem[im].Init();
//}
//___________________________________________________________
used_modems = 0;
unsigned short mod_mask = 1;
unsigned char typemodem;

//if( GetTestMode() != 0x8e)
//{

//bad 120608 return; //t

 ver_api = GetVersionAPI();

//if(ver_api == (unsigned long)CURRENT_VER_API)
//{
// hot_restart = 1;
 // return;	  //if make this lock do not loss
//}

 if(ver_api != (unsigned long)BAD_VALUE_ANS)	
{
 hot_restart = 1;
 // return;	  //if make this lock do not loss
}


for(im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
//#ifndef MAKET_PLATA
  typemodem =  ModemIsUsed(im);

 if(typemodem)
//#else
 //if(1)
//#endif
 {
   used_modems |= mod_mask;
   SetModemStruct(im,typemodem);


//if( GetTestMode() != 0x8e) //do not restart rtcs only
//if(1)
//{
// printfp("\n\r Test Mode != 0x8e"); //;%X Init : %d", GetTestMode(), im);

//120316 SetModemXILNPL1m(MODEM_QUANTITY);	 //110215

 SetModemXILNPL1m(im);	 //120316

/* t  ok
 if(hot_restart)
  {
  return;
  }
 */


 if(!hot_restart)
  {
   CommonResetOn(im);
   delay_mcs(1000l);
   ResetSyntOff(im);
 //	 delay_mcs(20000l);

 //  LoadSyntm(im);
//printfp("1210046");

   LoadSyntmf(GetNumConfigFilet(im),im); //100728

   CommonResetOff(im);
#ifndef PROG_BMDN6MI
   statrez[im].Init();
#endif

//#ifndef DO_NOT_LOAD_PROVINGENTS_PROTECTION
    SetNeedInitAllProti(im);	 //120202
//#endif
  } // hot_restart

 }
  mod_mask <<= 1;

}	//for im


//#endif
 if(!hot_restart)
  {
    delay_mcs(SYNT_SET_DELAY);	  //1 c ?
  }

Init_structs();
/*
for(im=0; im<MAX_NUM_CFG; im++)
{
modemp[0].SSC2(im);
}
  */
for(im=0; im<MAX_NUM_CFG; im++)
{
modemp[0].SSC2(im);
}


//ok 111216 return; 
//_________________________________________________________>>>>>>hier
if( GetTestMode() != 0x8e) //do not restart rtcs only
{

//delay_mcs(10000);

if(!hot_restart)
  {
 wd_reset();
 /* 140916
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
PVG710_Init(0);	  //for test
PVG710_Init(1);	  //for test
#else
PVG710_Init(0);
#endif
*/
   wd_reset();
   }
//#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
// if(deviceindex == 0) return 1; //for test
// if(deviceindex == 0) return 1; //for test
//   return;
//#endif //MAKET_PLATA
//#ifndef MAKET_PLATA
// if(!hot_restart)

/* t ok
 if(hot_restart)
  {
  return;
  }
*/

//  {

 //ok return; //150224

 StartModems(MODEM_QUANTITY);

 FillMenu();
//wrong return; //150224


// }
/*
 if(hot_restart)
  {
  return;
  }
 */

//#endif
 wd_reset();

  //for hot rezerv need use flag ModemAlarmEnableSetAllm();

#ifndef DO_NOT_LOAD_PROVINGENTS_PROTECTION

#ifndef PROG_BMDN4
SetPriorityZero(currentrezerv);
#endif

#ifndef PROG_BMDN4
SetStartRezerv(); //at start do not have lock in rezerv modem and need set its transmit for send to any modem
#endif
 //bad!!!!return;
//bad!!! return;
//_________________________________________________________<<<<<<<<hier
if(!hot_restart)
  {
CheckParseFlags(); //110214
}
#endif //DO_NOT_LOAD_PROVINGENTS_PROTECTION


}
else
{
// printfp("\n\r... mode 0x8e");
}

//ok1 return;
//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

EnablePhone();

#endif
#endif

#ifndef PROG_BMDN6MI
SetCurrentTrunk(1); //get on trunk
#endif
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r ....end of init");
//#else
//printfp("\n\r ....end of init");
//#endif
//130228  FillAllConfigFileVersion();
 // FillAllConfigFileVersion();

//#ifdef PROG_MD310_SAT
// OperateACM();
//#endif

//#ifdef USE_HTTP
//page_number = 0;
// Init_web_prm();
//#endif



 hot_restart = 0; // to be loading all in work
}

//#define SCAN_PERIOD (1000) //1c
#define SCAN_PERIOD (10000) //10c
//#define READ_ERRORS_PERIOD (1000) //1c
//150616#define READ_ERRORS_PERIOD (3000) //1c
//t150703 #define READ_ERRORS_PERIOD (1000) //1c  ok - start
//#define READ_ERRORS_PERIOD (250) //1c
//#define READ_ERRORS_PERIOD (75) //1c
//160318#define READ_ERRORS_PERIOD (333) //1c
#define READ_ERRORS_PERIOD (222) //c




extern "C" void UpdateErrors(unsigned char mod)
{
 unsigned char deviceindex = mod << 1;

/*
//			Счётчик ошибок после комбинатора	16 бит
  unStateBMD155p[mod].stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUMp[mod].statePUM.ulErrOut 					 	+=  modemp[deviceindex].protectionUncorrectedBytes;

//			Счётчик числа принятых пакетов	16 бит
  unStateBMD155p[mod].stateBMD155.count_block 			  =	 modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulBlock 					 	  +=  modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;

//			Счётчик ошибок не исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS1 			  =	 modemp[deviceindex].rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].rsErrorByteCounter;
			
//			Счётчик ошибок, исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionRxBytesFromProtection;// Fc.rsErrorBytytounter;

//_________________________________________________________________________________________________
//			Счётчик ошибок не исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex].rsErrorByteCounter;
			
//			Счётчик ошибок, исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;
	*/

//			Счётчик ошибок после комбинатора	16 бит
//printfpd("\n\r %d",(modemp[deviceindex].configfilefext.ConfigTxtData.emb4md15504cfg.numProvCode & MASK_BIT_1));
//2 - ldpc; 0 - rs
 
 
if((modemp[deviceindex].configfilefext.ConfigTxtData.emb4md15504cfg.numProvCode & MASK_BIT_1))
{
 
 
  unStateBMD155p[mod].stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
//110825  unStatePUMp[mod].statePUM.ulErrOut 					 	+=  modemp[deviceindex].protectionRxBytesFromProtection;
//110825  unStatePUM.statePUM.ulErrOut 					 	+=  modemp[deviceindex].protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
  unStatePUM.statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;




//			Счётчик числа принятых пакетов	16 бит
  unStateBMD155p[mod].stateBMD155.count_block 			  =	 modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_block 			  =	 modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulBlock 					 	  +=  modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUM.statePUM.ulBlock 					 	  +=  modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;


//			Счётчик ошибок не исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS1 			  =	 modemp[deviceindex].fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS1 			  =	 modemp[deviceindex].fecUncorrectedBlockCounter;
//  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].fecUncorrectedBlockCounter;
//  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;


			
//			Счётчик ошибок, исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;
//  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].rsErrorByteCounter;
   unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;


//_________________________________________________________________________________________________
//			Счётчик ошибок не исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
    unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].fecUncorrectedBlockCounter;

			
//			Счётчик ошибок, исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].fecUncorrectedBlockCounter;
}
else //rs
{

  unStateBMD155p[mod].stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
//110825  unStatePUMp[mod].statePUM.ulErrOut 					 	+=  modemp[deviceindex].protectionRxBytesFromProtection;
//110825  unStatePUM.statePUM.ulErrOut 					 	+=  modemp[deviceindex].protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
  unStatePUM.statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;




//			Счётчик числа принятых пакетов	16 бит
  unStateBMD155p[mod].stateBMD155.count_block 			  =	 modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_block 			  =	 modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulBlock 					 	  +=  modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUM.statePUM.ulBlock 					 	  +=  modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;


//			Счётчик ошибок не исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS1 			  =	 modemp[deviceindex].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS1 			  =	 modemp[deviceindex].rsErrorByteCounter;//fecUncorrectedBlockCounter;
//  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].fecUncorrectedBlockCounter;
//  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;


			
//			Счётчик ошибок, исправленных РС в 1 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;
//  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].rsErrorByteCounter;
   unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;


//_________________________________________________________________________________________________
//			Счётчик ошибок не исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
    unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;

			
//			Счётчик ошибок, исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
//  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;




}

   //	KoefErrors[mod] = 
}

extern "C" void ClearStats(unsigned char mod)
{
 unsigned char deviceindex = mod << 1;
 unsigned char deviceindex1 = (mod << 1) + 1;

modemp[deviceindex].acquireStatus =  0;
modemp[deviceindex].counterSlip =  0;
modemp[deviceindex].absoluteMseTenths =   0;
modemp[deviceindex].normalizedMseTenths =  0;
modemp[deviceindex].radialMseTenths =  0;



  modemp[deviceindex].fecBlockCounter =  0;
  modemp[deviceindex].fecUncorrectedBlockCounter =  0;
  modemp[deviceindex].rsByteCounter =  0;
  modemp[deviceindex].rsErrorByteCounter =  0;
  modemp[deviceindex].ldpcAvgIterations =  0;
  modemp[deviceindex].protectionRxBytesFromProtection =  0;
  modemp[deviceindex].protectionUncorrectedBytes =  0;
//  KoefErrors[deviceindex] =	 0;

//_____________________________________________________
ulevelsn15503.levelsn15503.absoluteMse[mod] = 0;
ulevelsn15503.levelsn15503.normalizedMse[mod] = 0;
ulevelsn15503.levelsn15503.radialMse[mod] = 0;

uerrsn15503work.errsn15303work.counterSlip[mod] =   0;
uerrsn15503work.errsn15303work.fecBlockCounter[mod] = 0;
uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] = 0;

modemp[deviceindex1].acquireStatus =  0;
modemp[deviceindex1].counterSlip =  0;
modemp[deviceindex1].absoluteMseTenths =   0;
modemp[deviceindex1].normalizedMseTenths =  0;
modemp[deviceindex1].radialMseTenths =  0;

  modemp[deviceindex1].fecBlockCounter =  0;
  modemp[deviceindex1].fecUncorrectedBlockCounter =  0;
  modemp[deviceindex1].rsByteCounter =  0;
  modemp[deviceindex1].rsErrorByteCounter =  0;
  modemp[deviceindex1].ldpcAvgIterations =  0;
  modemp[deviceindex1].protectionRxBytesFromProtection =  0;
  modemp[deviceindex1].protectionUncorrectedBytes =  0;
//  KoefErrors[deviceindex1] =	 0;



}

extern "C" void FillLock(unsigned char mod, unsigned char status)
{

 if(status)
 {
 switch(mod)
 {
  case 0 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_0; break;
  case 1 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_1; break;
  case 2 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_2; break;
  case 3 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_3; break;
  case 4 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_4; break;
  case 5 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_5; break;
  case 6 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_6; break;
  case 7 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_7; break;
  case 8 : uerrsn15503work.errsn15303work.lock2 |=  MASK_BIT_0; break;
  default : break;
 }
 }
 else
 {
 switch(mod)
 {
  case 0 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_0; break;
  case 1 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_1; break;
  case 2 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_2; break;
  case 3 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_3; break;
  case 4 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_4; break;
  case 5 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_5; break;
  case 6 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_6; break;
  case 7 : uerrsn15503work.errsn15303work.lock1 &=  ~MASK_BIT_7; break;
  case 8 : uerrsn15503work.errsn15303work.lock2 &=  ~MASK_BIT_0; break;
  default : break;
 }


 }

// printf("\n\r FillLock 1 : %X 2 :%X",uerrsn15503work.errsn15303work.lock1,  uerrsn15503work.errsn15303work.lock2);

}
signed long NMSE;
unsigned char LOCK;


//need use it for correctly set lock events and timers for change mode

unsigned char g_previons_status;
unsigned char g_previons_status1;

unsigned char previons_mode;
unsigned char previons_mode1;



extern "C" void ReadErrors1(unsigned char mod)
{
//  printfp("\n\rReadErrors1 ");


char Buf[3];



PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_NET_E1_ALARMS_STRUCT  Stat[E1_LINES_QUANTITY];

PVG610_NET_ETH_PM_STRUCT Pm;
UINT16 OneSecondPeriodCounter;

UINT64 tmp64;
//printfpd("\n\r tmprtr = %d ", GetTempSat());


//PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
unsigned char ans, ans1;


unsigned long   variant =  GetNumConfigFilet(0) & CONFIG_FILE_MASK;
unsigned long   variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	



	unStatePUM.statePUM.state[4] = GetStmPhyReg(mod);//inportb(0x524);
	if(unStatePUM.statePUM.state[4] & FAR_LOOP)
	{
	  unStatePUM.statePUM.state[5] |= OLD_FAR_LOOP;
	}
	else
	{
	   unStatePUM.statePUM.state[5] &= ~(OLD_FAR_LOOP);
	}

	if(unStatePUM.statePUM.state[4] & NEAR_LOOP)
	{
	  unStatePUM.statePUM.state[5] |= OLD_NEAR_LOOP;
	}
	else
	{
	   unStatePUM.statePUM.state[5] &= ~(OLD_NEAR_LOOP);
	}
  	unStatePUM.statePUM.state[6] = GetEthReg(mod);
#ifndef PROG_MD310
#ifndef PROG_BMDN6MI

//___________________________________________________
 unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = GetRele();
 unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = GetInputs();
//___________________________________________________
#endif
#endif

 unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = dev_status;


 unsigned char deviceindex = mod << 1;
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 unsigned char deviceindex1 = (mod << 1) + 1;
//#endif

//  printf("\n\rread errors:%d", mod);
 //  PVG610_API_ModemFecCountersGet(current_channel, 0, &Fc);
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rss%ld", time1);
//#endif
//___________________________________________________
	 /*
 ans = PVG610_API_NetE1AlarmsGet(deviceindex,0, 0x1fffffl, &Stat[0]);
if(ans) return;

for(i = 0; i < E1_LINES_QUANTITY; i++)
{
 modemp[deviceindex].netE1Alarms[i] = Stat[i].netE1Alarms;
}

 //printfp("\n\rReadErrors 1");
	*/

//____________________________________________________

 ans = PVG610_API_ModemStatusGet((deviceindex), 0, &Ms);
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rsf%ld", time1);
//#endif
 if(ans) 
 {
  norma_status[deviceindex]++;
 return;
 }
 else
  {
   norma_status[deviceindex] = 0;
  }

   //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
  
 modemp[deviceindex].acquireStatus =   Ms.acquireStatus;
//  printfpd("\n\r1: %d", Ms.acquireStatus);
  FillLock(mod,Ms.acquireStatus);
  
modemp[deviceindex].carrierOffset =    Ms.carrierOffset;
if(variant == variant1)
 {
SetMSweep(Ms.carrierOffset);

if(g_previons_status != modemp[deviceindex].acquireStatus)
//if(1)
 {
   //hier can set need write event to yournal  

  //   previons_status =	 modemp[deviceindex].acquireStatus;

   sprintf(Buf, "%02d",deviceindex);

   if(modemp[deviceindex].acquireStatus)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 2, Buf); //for test	   it work for variant ==  variant1 only
	 timelock = time1;
	 timekeepMSE = time1;
#endif
   }
   else
   {
#ifdef YOURNAL
	 Add_Event(EV_UNLOCK, 2, Buf); //for test
#endif
   }
 }
g_previons_status =	 modemp[deviceindex].acquireStatus;

 }
//printfpd("\n\r carrierOffset : %d" , Ms.carrierOffset);



     modemp[deviceindex].internalAgc = Ms.internalAgc;            // in dB, normal range [-5 to 40]
  // 	 SetMAGC(Ms.internalAgc);

   
     modemp[deviceindex].externalAgcRegister = Ms.externalAgcRegister;    // Directly reflects PVG register

  if(variant == variant1)
 {
	  SetMAGC(Ms.externalAgcRegister);
 }
 //______________110919
 
  modemp[deviceindex].acmEngineEnabled =   Ms.acmEngineEnabled;

//printfpd("\n\r Ms.acmEngineEnabled : %d", Ms.acmEngineEnabled);

 //  if(Ms.acmEngineEnabled)
   if(1)
   {
 
	 modemp[deviceindex].txAcmProfile =   Ms.txAcmProfile;
	 SetTxMode(Ms.txAcmProfile);
// 	 SetParamsTxFromCfg(Ms.txAcmProfile);

 //  if(modemp[deviceindex].rxAcmProfile != Ms.rxAcmProfile)
   if(1)
   {
     modemp[deviceindex].rxAcmProfile =   Ms.rxAcmProfile;	
  	 if(variant == variant1)
  	 {
   	 SetParamsRxFromCfg(Ms.rxAcmProfile);
	 SetViewModesFromCfg(Ms.txAcmProfile ,Ms.rxAcmProfile);
  	 }
   }
// MRMode.Value =  Ms.rxAcmProfile;
// MRMode.ChangingValue = MRMode.Value;
// dev1.md100se.MRMode =  MRMode.Value;

	   
   }
   else
   {
	 modemp[deviceindex].txAcmProfile =   ACM_MODES;
     modemp[deviceindex].rxAcmProfile =   ACM_MODES;
   }
	 
 //____________________110919

 //  printfp("\n\rReadErrors 2");


//if(1) //110823
// {
 /* 110823
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
 */
 unStatePUM.statePUM.state[7] = Ms.normalizedMseTenths;//2
 unStatePUM.statePUM.state[8] = Ms.normalizedMseTenths >> 8;//2
   
//___________________________________________________________
modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;

ulevelsn15503.levelsn15503.absoluteMse[mod] = Ms.absoluteMseTenths;
ulevelsn15503.levelsn15503.normalizedMse[mod] = Ms.normalizedMseTenths;
ulevelsn15503.levelsn15503.radialMse[mod] = Ms.radialMseTenths;


if(variant == variant1)
 {
 NMSE =  Ms.normalizedMseTenths;
  LOCK =  Ms.acquireStatus;

SetMEbN(Ms.normalizedMseTenths);
 
#ifndef FEC_BER
SetMBER(0, Ms.ldpcDecoderStress);
#endif
 }

// printfp("\n\rReadErrors 3");


 ans = PVG610_API_ModemAcquireCountersGet((deviceindex), 0, &Ac);
 if(ans) return;
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\raf%ld", time1);
//#endif

uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;

//if(!(Ac.numLolEvents)) //110823
//if(variant == variant1)
// {

 if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) ) //121016
//121016if(Ms.acquireStatus) //110922 maked temporary without counters
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL1_LOCK_BIT;//2
}

//}

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rfs%ld", time1);
//#endif

 ans = PVG610_API_ModemFecCountersGet((deviceindex), 0, &Fc);

if(ans) return;
// #ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rff%ld", time1);
//#endif

//    printf("\n\rread mod : %d errors:%ld", (mod << 1), );

  modemp[deviceindex].fecBlockCounter +=   Fc.fecBlockCounter;
  modemp[deviceindex].fecUncorrectedBlockCounter +=   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;


#ifdef FEC_BER
if(variant == variant1)
 {

SetMBER(Fc.fecBlockCounter, Fc.fecUncorrectedBlockCounter);
//SetMBER(Fc.fecUncorrectedBlockCounter, Fc.fecBlockCounter);
}
#endif // FEC_BER




//  KoefErrors[deviceindex] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;

if(GetTestMode() == 0x5A)
{
//#ifndef USART0_TRY_PDC_1T
// printf("\r\nmod : %d Status : %d prot:%ld ans : %X", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection, ans);
//#else
 printfp("\n\rmod : ");
 printfpd("%d",(deviceindex));
 printfp("\n\r Status : ");
 printfpd("%d", modemp[deviceindex].acquireStatus);
 printfp("\n\r ldpcDecoderStress");
 printfpd("%ld" , Ms.ldpcDecoderStress);
 printfp("\n\rfecUncorrectedBlockCounter: ");
 printfpd("%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
 printfp("\n\rfecBlockCounter: ");
 printfpd("%ld", modemp[deviceindex].fecBlockCounter);
 printfp("\n\rrsErrorByteCounter: ");
 printfpd("%ld", modemp[deviceindex].rsErrorByteCounter);
 printfp("\n\rldpcAvgIterations: ");
 printfpd("%ld", modemp[deviceindex].ldpcAvgIterations);
 printfp("\n\r  protectionRxBytesFromProtection: ");
 printfpd("%ld", modemp[deviceindex].protectionRxBytesFromProtection);
 printfp("\n\rprotectionUncorrectedBytes: ");
 printfpd("%ld", modemp[deviceindex].protectionUncorrectedBytes);

}
// printfp("  absoluteMseTenths: ");
// printfpd("%ld", modemp[deviceindex].absoluteMseTenths);
// printfp("  normalizedMseTenths: ");
// printfpd("%ld", modemp[deviceindex].normalizedMseTenths);
// printfp("  radialMseTenths: ");
// printfpd("%ld", modemp[deviceindex].radialMseTenths);

// printfp(" ans :");
// printfpd(" %X", ans);  
//#endif
//  printf("\n\r fecBlockCounter:%ld",   modemp[deviceindex].fecBlockCounter);
//  printf("\n\r fecUncorrectedBlockCounter:%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
//  printf("\n\r rsByteCounter:%ld",  modemp[deviceindex].rsByteCounter);
//  printf("\n\r rsErrorByteCounter:%ld",  modemp[deviceindex].rsErrorByteCounter);
//  printf("\n\r ldpcAvgIterations:%ld",  modemp[deviceindex].ldpcAvgIterations);
//  printf("\n\r protectionUncorrectedBytes:%ld",   modemp[deviceindex].protectionUncorrectedBytes);


   uerrsn15503work.errsn15303work.fecBlockCounter[mod] +=   Fc.fecBlockCounter;;
   uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] +=   Fc.fecUncorrectedBlockCounter;




 // }
  // UpdateErrors(deviceindex);


//_____________________________for test
//delay_mcs(50000l);
//delay_mcs(50000l);


//______________________________for test
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rs%ld", time1);
//#endif


#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

 ans1 = PVG610_API_ModemStatusGet((deviceindex1), 0, &Ms);
// if(ans1) return;
  if(ans1) 
 {
  norma_status[deviceindex1]++;
 return;
 }
 else
  {
   norma_status[deviceindex1] = 0;
  }





if(variant != variant1)
 {
  NMSE =  Ms.normalizedMseTenths;
  LOCK =  Ms.acquireStatus;

	SetMSweep(Ms.carrierOffset);
	SetMAGC(Ms.externalAgcRegister);
	SetMEbN(Ms.normalizedMseTenths);
#ifndef FEC_BER
	SetMBER(0, Ms.ldpcDecoderStress);
#endif
 }




 //#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rf%ld", time1);
//#endif

 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);

   modemp[deviceindex1].acquireStatus =   Ms.acquireStatus;

 modemp[deviceindex1].acmEngineEnabled =   Ms.acmEngineEnabled;

 //  if(Ms.acmEngineEnabled)
 //  printfp("\n\rReadErrors1_10 ");

  if(1)
   {
  //	 modemp[deviceindex1].txAcmProfile =   Ms.txAcmProfile;
 //    modemp[deviceindex1].rxAcmProfile =   Ms.rxAcmProfile;

  if(1)
   {
     modemp[deviceindex1].rxAcmProfile =   Ms.rxAcmProfile;	

	 if(variant != variant1)
	 {
   	 SetParamsRxFromCfg(Ms.rxAcmProfile);				 //need use cfg for proving 1
	 SetViewModesFromCfg(Ms.txAcmProfile ,Ms.rxAcmProfile);

if(g_previons_status1 != modemp[deviceindex1].acquireStatus)
//if(1)
 {
   //hier can set need write event to yournal  

  //   previons_status =	 modemp[deviceindex].acquireStatus;

   sprintf(Buf, "%02d",deviceindex);

   if(modemp[deviceindex1].acquireStatus)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 2, Buf); //for test	   it work for variant ==  variant1 only
	 timelock = time1;
	  timekeepMSE = time1;

#endif
   }
   else
   {
#ifdef YOURNAL
	 Add_Event(EV_UNLOCK, 2, Buf); //for test
#endif
   }
 }
  g_previons_status1 =	 modemp[deviceindex].acquireStatus;

	 }
	}

   }
   else
   {
	 modemp[deviceindex1].txAcmProfile =   ACM_MODES;
     modemp[deviceindex1].rxAcmProfile =   ACM_MODES;
   }
	 
  // }


     modemp[deviceindex1].internalAgc = Ms.internalAgc;            // in dB, normal range [-5 to 40]
     modemp[deviceindex1].externalAgcRegister = Ms.externalAgcRegister;    // Directly reflects PVG register

 
//110823  if(Ms.acquireStatus)
if(1) //110823
 {
  unStatePUM.statePUM.state[9] = Ms.normalizedMseTenths;//2
  unStatePUM.statePUM.state[10] = Ms.normalizedMseTenths >> 8;//2
   //___________________________________________________________
modemp[deviceindex1].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex1].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex1].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex1].radialMseTenths =   Ms.radialMseTenths;


//___________________________________________________________

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rcs%ld", time1);
//#endif
//___________________________________
ans1 = PVG610_API_ModemAcquireCountersGet((deviceindex1), 0, &Ac);
 if(ans1) return;
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\raf%ld", time1);
//#endif

//uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;

//if(!(Ac.numLolEvents)) //110823

if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) )
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL2_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL2_LOCK_BIT;//2
}
 






//printEthLongHex(unStatePUM.statePUM.state[2] + ((Ms.acquireStatus)<<8) + (Ac.numLolEvents<<16));


//__________________________________



ans1 =   PVG610_API_ModemFecCountersGet(deviceindex1, 0, &Fc);
   if(ans1) return;

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rcf%ld", time1);
//#endif

  modemp[deviceindex1].fecBlockCounter =   Fc.fecBlockCounter;
  modemp[deviceindex1].fecUncorrectedBlockCounter =   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex1].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex1].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex1].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex1].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex1].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;


#ifdef FEC_BER
if(variant != variant1)
 {

SetMBER(Fc.fecBlockCounter, Fc.fecUncorrectedBlockCounter);
//SetMBER(Fc.fecUncorrectedBlockCounter, Fc.fecBlockCounter);
}
#endif // FEC_BER


//  KoefErrors[deviceindex1] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;
//#ifndef USART0_TRY_PDC_1T
//  printf("\n\rmod :  %d  Status : %d prot:%ld ans1 : %X", (deviceindex1), modemp[deviceindex1].acquireStatus, modemp[deviceindex1].protectionRxBytesFromProtection, ans1);
//#else
// printfp("\n\rmod : ");
// printfpd("%d",(deviceindex1));
// printfp(" Status : ");
// printfpd("%d", modemp[deviceindex1].acquireStatus);
// printfp("  prot: ");
// printfpd("%ld", modemp[deviceindex1].protectionRxBytesFromProtection);
// printfp("  absoluteMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].absoluteMseTenths);
// printfp("  normalizedMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].normalizedMseTenths);
// printfp("  radialMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].radialMseTenths);
 
if(GetTestMode() == 0x5A)
{
//#ifndef USART0_TRY_PDC_1T
// printf("\r\nmod : %d Status : %d prot:%ld ans : %X", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection, ans);
//#else
 printfp("\n\rmod : ");
 printfpd("%d",(deviceindex1));
 printfp("\n\r Status : ");
 printfpd("%d", modemp[deviceindex1].acquireStatus);
 printfp("\n\r ldpcDecoderStress");
 printfpd("%ld" , Ms.ldpcDecoderStress);
 printfp("\n\rfecBlockCounter: ");
 printfpd("%ld", modemp[deviceindex1].fecBlockCounter);
 printfp("\n\rfecUncorrectedBlockCounter: ");
 printfpd("%ld", modemp[deviceindex1].fecUncorrectedBlockCounter);
 printfp("\n\rrsErrorByteCounter: ");
 printfpd("%ld", modemp[deviceindex1].rsErrorByteCounter);
 printfp("\n\rldpcAvgIterations: ");
 printfpd("%ld", modemp[deviceindex1].ldpcAvgIterations);
 printfp("\n\r  protectionRxBytesFromProtection: ");
 printfpd("%ld", modemp[deviceindex1].protectionRxBytesFromProtection);
 printfp("\n\rprotectionUncorrectedBytes: ");
 printfpd("%ld", modemp[deviceindex1].protectionUncorrectedBytes);

}
 
// printfp(" ans1 :");
// printfpd(" %X", ans1);  
//#endif
  }
 


#endif // LOAD_ONE_PROVINGENT_ON_PLATA
 //  UpdateErrors(mod);
}


//============================================================
extern "C" void ReadErrors2(unsigned char mod)
{
 // printfp("\n\rReadErrors2 ");

//unsigned char previons_status;
//unsigned char previons_status1;
char Buf[3];


PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_NET_E1_ALARMS_STRUCT  Stat[E1_LINES_QUANTITY];

PVG610_NET_ETH_PM_STRUCT Pm;
UINT16 OneSecondPeriodCounter;

UINT64 tmp64;
//printfpd("\n\r tmprtr = %d ", GetTempSat());


//PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
unsigned char ans, ans1;

 /*
//unsigned char   variant =  GetNumConfigFile(0) & CONFIG_FILE_MASK;
//unsigned char   variant1 =  GetNumConfigFile(1) & CONFIG_FILE_MASK;	
 */

unsigned long   variant =  GetNumConfigFilet(0) & CONFIG_FILE_MASK;
unsigned long   variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	



	unStatePUM.statePUM.state[4] = GetStmPhyReg(mod);//inportb(0x524);
	if(unStatePUM.statePUM.state[4] & FAR_LOOP)
	{
	  unStatePUM.statePUM.state[5] |= OLD_FAR_LOOP;
	}
	else
	{
	   unStatePUM.statePUM.state[5] &= ~(OLD_FAR_LOOP);
	}

	if(unStatePUM.statePUM.state[4] & NEAR_LOOP)
	{
	  unStatePUM.statePUM.state[5] |= OLD_NEAR_LOOP;
	}
	else
	{
	   unStatePUM.statePUM.state[5] &= ~(OLD_NEAR_LOOP);
	}
  	unStatePUM.statePUM.state[6] = GetEthReg(mod);
#ifndef PROG_MD310
#ifndef PROG_BMDN6MI

//___________________________________________________
 unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = GetRele();
 unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = GetInputs();
//___________________________________________________
#endif
#endif

 unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = dev_status;


 unsigned char deviceindex = mod << 1;
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 unsigned char deviceindex1 = (mod << 1) + 1;
//#endif

//  printf("\n\rread errors:%d", mod);
 //  PVG610_API_ModemFecCountersGet(current_channel, 0, &Fc);
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rss%ld", time1);
//#endif
//___________________________________________________
	 /*
 ans = PVG610_API_NetE1AlarmsGet(deviceindex,0, 0x1fffffl, &Stat[0]);
if(ans) return;

for(i = 0; i < E1_LINES_QUANTITY; i++)
{
 modemp[deviceindex].netE1Alarms[i] = Stat[i].netE1Alarms;
}

 //printfp("\n\rReadErrors 1");
	*/

//____________________________________________________

 ans = PVG610_API_ModemStatusGet((deviceindex), 0, &Ms);
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rsf%ld", time1);
//#endif
 if(ans) 
 {
  norma_status[deviceindex]++;
 return;
 }
 else
  {
   norma_status[deviceindex] = 0;
  }

   //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus); 
  



    modemp[deviceindex].acquireStatus =   Ms.acquireStatus;
//  printfpd("\n\r1: %d", Ms.acquireStatus);
  FillLock(mod,Ms.acquireStatus);
  
modemp[deviceindex].carrierOffset =    Ms.carrierOffset;
if(variant == variant1)
 {
SetMSweep(Ms.carrierOffset);

if(g_previons_status != modemp[deviceindex].acquireStatus)
//if(1)
 {
   //hier can set need write event to yournal  

  //   previons_status =	 modemp[deviceindex].acquireStatus;

   sprintf(Buf, "%02d",deviceindex);

   if(modemp[deviceindex].acquireStatus)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 2, Buf); //for test	   it work for variant ==  variant1 only
	 timelock = time1;
	  timekeepMSE = time1;

#endif
   }
   else
   {
#ifdef YOURNAL
	 Add_Event(EV_UNLOCK, 2, Buf); //for test
#endif
   }
 }
   g_previons_status =	 modemp[deviceindex].acquireStatus;

 }
//printfpd("\n\r carrierOffset : %d" , Ms.carrierOffset);



     modemp[deviceindex].internalAgc = Ms.internalAgc;            // in dB, normal range [-5 to 40]
  // 	 SetMAGC(Ms.internalAgc);

   
     modemp[deviceindex].externalAgcRegister = Ms.externalAgcRegister;    // Directly reflects PVG register

  if(variant == variant1)
 {
	  SetMAGC(Ms.externalAgcRegister);
 }
 //______________110919
 
  modemp[deviceindex].acmEngineEnabled =   Ms.acmEngineEnabled;

//printfpd("\n\r Ms.acmEngineEnabled : %d", Ms.acmEngineEnabled);

 //  if(Ms.acmEngineEnabled)
   if(1)
   {
 
	 modemp[deviceindex].txAcmProfile =   Ms.txAcmProfile;
	 SetTxMode(Ms.txAcmProfile);
// 	 SetParamsTxFromCfg(Ms.txAcmProfile);

 //  if(modemp[deviceindex].rxAcmProfile != Ms.rxAcmProfile)
   if(1)
   {
     modemp[deviceindex].rxAcmProfile =   Ms.rxAcmProfile;	
  	 if(variant == variant1)
  	 {
   	 SetParamsRxFromCfg(Ms.rxAcmProfile);
	 SetViewModesFromCfg(Ms.txAcmProfile ,Ms.rxAcmProfile);
  	 }
   }
// MRMode.Value =  Ms.rxAcmProfile;
// MRMode.ChangingValue = MRMode.Value;
// dev1.md100se.MRMode =  MRMode.Value;

	   
   }
   else
   {
	 modemp[deviceindex].txAcmProfile =   ACM_MODES;
     modemp[deviceindex].rxAcmProfile =   ACM_MODES;
   }
	 
 //____________________110919

 //  printfp("\n\rReadErrors 2");


//if(1) //110823
// {
 /* 110823
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
 */
 unStatePUM.statePUM.state[7] = Ms.normalizedMseTenths;//2
 unStatePUM.statePUM.state[8] = Ms.normalizedMseTenths >> 8;//2
   
//___________________________________________________________
modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;

ulevelsn15503.levelsn15503.absoluteMse[mod] = Ms.absoluteMseTenths;
ulevelsn15503.levelsn15503.normalizedMse[mod] = Ms.normalizedMseTenths;
ulevelsn15503.levelsn15503.radialMse[mod] = Ms.radialMseTenths;


if(variant == variant1)
 {
 NMSE =  Ms.normalizedMseTenths;
  LOCK =  Ms.acquireStatus;
 
SetMEbN(Ms.normalizedMseTenths);   //ok
#ifndef FEC_BER
SetMBER(0, Ms.ldpcDecoderStress);
#endif
 }

// printfp("\n\rReadErrors 3");


 ans = PVG610_API_ModemAcquireCountersGet((deviceindex), 0, &Ac);
 if(ans) return;
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\raf%ld", time1);
//#endif

uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;

//if(!(Ac.numLolEvents)) //110823
//if(variant == variant1)
// {

 if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) ) //121016
//121016if(Ms.acquireStatus) //110922 maked temporary without counters
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL1_LOCK_BIT;//2
}

//}

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rfs%ld", time1);
//#endif

 ans = PVG610_API_ModemFecCountersGet((deviceindex), 0, &Fc);

if(ans) return;
// #ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rff%ld", time1);
//#endif

//    printf("\n\rread mod : %d errors:%ld", (mod << 1), );

  modemp[deviceindex].fecBlockCounter +=   Fc.fecBlockCounter;
  modemp[deviceindex].fecUncorrectedBlockCounter +=   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;



//SetMBER(Fc.fecUncorrectedBlockCounter, Fc.fecBlockCounter);
#ifdef FEC_BER
if(variant == variant1)
 {

SetMBER(Fc.fecBlockCounter, Fc.fecUncorrectedBlockCounter);
//SetMBER(Fc.fecUncorrectedBlockCounter, Fc.fecBlockCounter);
}
#endif // FEC_BER




//  KoefErrors[deviceindex] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;

if(GetTestMode() == 0x5A)
{
//#ifndef USART0_TRY_PDC_1T
// printf("\r\nmod : %d Status : %d prot:%ld ans : %X", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection, ans);
//#else
 printfp("\n\rmod : ");
 printfpd("%d",(deviceindex));
 printfp("\n\r Status : ");
 printfpd("%d", modemp[deviceindex].acquireStatus);
 printfp("\n\r ldpcDecoderStress");
 printfpd("%ld" , Ms.ldpcDecoderStress);
 printfp("\n\rfecUncorrectedBlockCounter: ");
 printfpd("%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
 printfp("\n\rfecBlockCounter: ");
 printfpd("%ld", modemp[deviceindex].fecBlockCounter);
 printfp("\n\rrsErrorByteCounter: ");
 printfpd("%ld", modemp[deviceindex].rsErrorByteCounter);
 printfp("\n\rldpcAvgIterations: ");
 printfpd("%ld", modemp[deviceindex].ldpcAvgIterations);
 printfp("\n\r  protectionRxBytesFromProtection: ");
 printfpd("%ld", modemp[deviceindex].protectionRxBytesFromProtection);
 printfp("\n\rprotectionUncorrectedBytes: ");
 printfpd("%ld", modemp[deviceindex].protectionUncorrectedBytes);

}
// printfp("  absoluteMseTenths: ");
// printfpd("%ld", modemp[deviceindex].absoluteMseTenths);
// printfp("  normalizedMseTenths: ");
// printfpd("%ld", modemp[deviceindex].normalizedMseTenths);
// printfp("  radialMseTenths: ");
// printfpd("%ld", modemp[deviceindex].radialMseTenths);

// printfp(" ans :");
// printfpd(" %X", ans);  
//#endif
//  printf("\n\r fecBlockCounter:%ld",   modemp[deviceindex].fecBlockCounter);
//  printf("\n\r fecUncorrectedBlockCounter:%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
//  printf("\n\r rsByteCounter:%ld",  modemp[deviceindex].rsByteCounter);
//  printf("\n\r rsErrorByteCounter:%ld",  modemp[deviceindex].rsErrorByteCounter);
//  printf("\n\r ldpcAvgIterations:%ld",  modemp[deviceindex].ldpcAvgIterations);
//  printf("\n\r protectionUncorrectedBytes:%ld",   modemp[deviceindex].protectionUncorrectedBytes);


   uerrsn15503work.errsn15303work.fecBlockCounter[mod] +=   Fc.fecBlockCounter;;
   uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] +=   Fc.fecUncorrectedBlockCounter;




 // }
  // UpdateErrors(deviceindex);


//_____________________________for test
//delay_mcs(50000l);
//delay_mcs(50000l);


//______________________________for test
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rs%ld", time1);
//#endif


return;


 //  UpdateErrors(mod);
}


extern "C" void ReadErrors3(unsigned char mod)
{
//  printfp("\n\rReadErrors3 ");

char Buf[3];


PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_NET_E1_ALARMS_STRUCT  Stat[E1_LINES_QUANTITY];

PVG610_NET_ETH_PM_STRUCT Pm;
UINT16 OneSecondPeriodCounter;

UINT64 tmp64;
//printfpd("\n\r tmprtr = %d ", GetTempSat());


//PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
unsigned char ans, ans1;

  /*
//unsigned char   variant =  GetNumConfigFile(0) & CONFIG_FILE_MASK;
//unsigned char   variant1 =  GetNumConfigFile(1) & CONFIG_FILE_MASK;	
 */

unsigned long   variant =  GetNumConfigFilet(0) & CONFIG_FILE_MASK;
unsigned long   variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	


  

 unsigned char deviceindex = mod << 1;
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 unsigned char deviceindex1 = (mod << 1) + 1;
//#endif

//  printf("\n\rread errors:%d", mod);
 //  PVG610_API_ModemFecCountersGet(current_channel, 0, &Fc);
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rss%ld", time1);
//#endif
//___________________________________________________
	 /*
 ans = PVG610_API_NetE1AlarmsGet(deviceindex,0, 0x1fffffl, &Stat[0]);
if(ans) return;

for(i = 0; i < E1_LINES_QUANTITY; i++)
{
 modemp[deviceindex].netE1Alarms[i] = Stat[i].netE1Alarms;
}

 //printfp("\n\rReadErrors 1");
	*/

//____________________________________________________



#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

 ans1 = PVG610_API_ModemStatusGet((deviceindex1), 0, &Ms);
// if(ans1) return;
  if(ans1) 
 {
  norma_status[deviceindex1]++;
 return;
 }
 else
  {
   norma_status[deviceindex1] = 0;
  }





if(variant != variant1)
 {
  NMSE =  Ms.normalizedMseTenths;
  LOCK =  Ms.acquireStatus;

	SetMSweep(Ms.carrierOffset);
	SetMAGC(Ms.externalAgcRegister);
	SetMEbN(Ms.normalizedMseTenths);
#ifndef FEC_BER
 	SetMBER(0, Ms.ldpcDecoderStress);
#endif
 }




 //#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rf%ld", time1);
//#endif

 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);

   modemp[deviceindex1].acquireStatus =   Ms.acquireStatus;

 modemp[deviceindex1].acmEngineEnabled =   Ms.acmEngineEnabled;

 //  if(Ms.acmEngineEnabled)
 //  printfp("\n\rReadErrors1_10 ");

  if(1)
   {
  //	 modemp[deviceindex1].txAcmProfile =   Ms.txAcmProfile;
 //    modemp[deviceindex1].rxAcmProfile =   Ms.rxAcmProfile;

  if(1)
   {
     modemp[deviceindex1].rxAcmProfile =   Ms.rxAcmProfile;	

	 if(variant != variant1)
	 {
   	 SetParamsRxFromCfg(Ms.rxAcmProfile);				 //need use cfg for proving 1
	 SetViewModesFromCfg(Ms.txAcmProfile ,Ms.rxAcmProfile);

if(g_previons_status1 != modemp[deviceindex1].acquireStatus)
//if(1)
 {
   //hier can set need write event to yournal  

  //   previons_status =	 modemp[deviceindex].acquireStatus;

   sprintf(Buf, "%02d",deviceindex);

   if(modemp[deviceindex1].acquireStatus)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 2, Buf); //for test	   it work for variant ==  variant1 only
	 timelock = time1;
	  timekeepMSE = time1;

#endif
   }
   else
   {
#ifdef YOURNAL
	 Add_Event(EV_UNLOCK, 2, Buf); //for test
#endif
   }
 }
g_previons_status1 =	 modemp[deviceindex].acquireStatus;

	 }
	}

   }
   else
   {
	 modemp[deviceindex1].txAcmProfile =   ACM_MODES;
     modemp[deviceindex1].rxAcmProfile =   ACM_MODES;
   }
	 
  // }


     modemp[deviceindex1].internalAgc = Ms.internalAgc;            // in dB, normal range [-5 to 40]
     modemp[deviceindex1].externalAgcRegister = Ms.externalAgcRegister;    // Directly reflects PVG register

 
//110823  if(Ms.acquireStatus)
if(1) //110823
 {
  unStatePUM.statePUM.state[9] = Ms.normalizedMseTenths;//2
  unStatePUM.statePUM.state[10] = Ms.normalizedMseTenths >> 8;//2
   //___________________________________________________________
modemp[deviceindex1].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex1].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex1].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex1].radialMseTenths =   Ms.radialMseTenths;


//___________________________________________________________

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rcs%ld", time1);
//#endif
//___________________________________
ans1 = PVG610_API_ModemAcquireCountersGet((deviceindex1), 0, &Ac);
 if(ans1) return;
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\raf%ld", time1);
//#endif

//uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;

//if(!(Ac.numLolEvents)) //110823

if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) )
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL2_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL2_LOCK_BIT;//2
}
 






//printEthLongHex(unStatePUM.statePUM.state[2] + ((Ms.acquireStatus)<<8) + (Ac.numLolEvents<<16));


//__________________________________



ans1 =   PVG610_API_ModemFecCountersGet(deviceindex1, 0, &Fc);
   if(ans1) return;

//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rcf%ld", time1);
//#endif

  modemp[deviceindex1].fecBlockCounter =   Fc.fecBlockCounter;
  modemp[deviceindex1].fecUncorrectedBlockCounter =   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex1].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex1].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex1].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex1].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex1].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;

#ifdef FEC_BER
if(variant != variant1)
 {

SetMBER(Fc.fecBlockCounter, Fc.fecUncorrectedBlockCounter);
//SetMBER(Fc.fecUncorrectedBlockCounter, Fc.fecBlockCounter);
}
#endif // FEC_BER


//  KoefErrors[deviceindex1] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;
//#ifndef USART0_TRY_PDC_1T
//  printf("\n\rmod :  %d  Status : %d prot:%ld ans1 : %X", (deviceindex1), modemp[deviceindex1].acquireStatus, modemp[deviceindex1].protectionRxBytesFromProtection, ans1);
//#else
// printfp("\n\rmod : ");
// printfpd("%d",(deviceindex1));
// printfp(" Status : ");
// printfpd("%d", modemp[deviceindex1].acquireStatus);
// printfp("  prot: ");
// printfpd("%ld", modemp[deviceindex1].protectionRxBytesFromProtection);
// printfp("  absoluteMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].absoluteMseTenths);
// printfp("  normalizedMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].normalizedMseTenths);
// printfp("  radialMseTenths: ");
// printfpd("%ld", modemp[deviceindex1].radialMseTenths);
 
if(GetTestMode() == 0x5A)
{
//#ifndef USART0_TRY_PDC_1T
// printf("\r\nmod : %d Status : %d prot:%ld ans : %X", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection, ans);
//#else
 printfp("\n\rmod : ");
 printfpd("%d",(deviceindex1));
 printfp("\n\r Status : ");
 printfpd("%d", modemp[deviceindex1].acquireStatus);
 printfp("\n\r ldpcDecoderStress");
 printfpd("%ld" , Ms.ldpcDecoderStress);
 printfp("\n\rfecBlockCounter: ");
 printfpd("%ld", modemp[deviceindex1].fecBlockCounter);
 printfp("\n\rfecUncorrectedBlockCounter: ");
 printfpd("%ld", modemp[deviceindex1].fecUncorrectedBlockCounter);
 printfp("\n\rrsErrorByteCounter: ");
 printfpd("%ld", modemp[deviceindex1].rsErrorByteCounter);
 printfp("\n\rldpcAvgIterations: ");
 printfpd("%ld", modemp[deviceindex1].ldpcAvgIterations);
 printfp("\n\r  protectionRxBytesFromProtection: ");
 printfpd("%ld", modemp[deviceindex1].protectionRxBytesFromProtection);
 printfp("\n\rprotectionUncorrectedBytes: ");
 printfpd("%ld", modemp[deviceindex1].protectionUncorrectedBytes);

}
 
// printfp(" ans1 :");
// printfpd(" %X", ans1);  
//#endif
  }
 


#endif // LOAD_ONE_PROVINGENT_ON_PLATA
 //  UpdateErrors(mod);
}






//=============================================================

extern "C" void ReadErrors(unsigned char mod)
{
 // printfp("\n\rReadErrors ");



PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_NET_E1_ALARMS_STRUCT  Stat[E1_LINES_QUANTITY];

PVG610_NET_ETH_PM_STRUCT Pm;
UINT16 OneSecondPeriodCounter;

UINT64 tmp64;
//printfpd("\n\r tmprtr = %d ", GetTempSat());


//PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
unsigned char ans, ans1;

 unsigned char deviceindex = mod << 1;
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 unsigned char deviceindex1 = (mod << 1) + 1;



unsigned long   variant =  GetNumConfigFilet(0) & CONFIG_FILE_MASK;
unsigned long   variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	



//printfp("\n\rReadErrors 4");


   ans1 = PVG610_API_NetEthPmGet(0, 0, &Pm, &OneSecondPeriodCounter);

  if(ans1)
  {
 // printfpd("\n\r return : ans1: %d", ans1);
  return;
  }
  
// if(variant == variant1)
  // if(0)
// {
 // ans1 = PVG610_API_NetEthPmGet((deviceindex1), 0, &Pm, &OneSecondPeriodCounter);
 // if(!ans1)
 // { 
 //  SetMEthReceived(Pm.rx.dones);
 //  SetMEthReceivedCRC(Pm.rx.crcErrors);

Pma.rx.truncatedFrames += Pm.rx.truncatedFrames;
Pma.rx.longEvents += Pm.rx.longEvents;
Pma.rx.vlanTagsDetected += Pm.rx.vlanTagsDetected;
Pma.rx.unsopprtedOpcodes += Pm.rx.unsopprtedOpcodes;
Pma.rx.pauseFrames += Pm.rx.pauseFrames;
Pma.rx.controlFrames += Pm.rx.controlFrames;
Pma.rx.dribbleNibbles += Pm.rx.dribbleNibbles;
Pma.rx.broadcasts += Pm.rx.broadcasts;
Pma.rx.multicasts += Pm.rx.multicasts;
Pma.rx.dones += Pm.rx.dones;
Pma.rx.outOfRangeErrors += Pm.rx.outOfRangeErrors;
Pma.rx.lengthCheckErrors += Pm.rx.lengthCheckErrors;
Pma.rx.crcErrors += Pm.rx.crcErrors;
Pma.rx.codeErrors += Pm.rx.codeErrors;
Pma.rx.falseCarrierErrors += Pm.rx.falseCarrierErrors;
Pma.rx.rxDvEvent += Pm.rx.rxDvEvent;
Pma.rx.previosPacketDropped += Pm.rx.previosPacketDropped;

tmp64 = (Pma.rx.byteCounterHigh << 32) + Pma.rx.byteCounterLow + (Pm.rx.byteCounterHigh << 32) + Pm.rx.byteCounterLow;

Pma.rx.byteCounterLow = (UINT32)tmp64;
Pma.rx.byteCounterHigh = (UINT32)(tmp64 >> 32);

//Pma.gfp.fcsErrors += Pm.gfp.fcsErrors;
//Pma.gfp.checErrors += Pm.gfp.checErrors;
//Pma.gfp.droppedFrames += Pm.gfp.droppedFrames;
//Pma.gfp.frameDelineationLosses += Pm.gfp.frameDelineationLosses;

Pma.qos.rxQ1Frames += Pm.qos.rxQ1Frames;
Pma.qos.rxQ1DroppedFrames += Pm.qos.rxQ1DroppedFrames;
Pma.qos.rxQ2Frames += Pm.qos.rxQ2Frames;
Pma.qos.rxQ2DroppedFrams += Pm.qos.rxQ2DroppedFrams;
//Pma.qos.txFrames += Pm.qos.txFrames;
//Pma.qos.txDroppedFrames += Pm.qos.txDroppedFrames;



//Pma.rx.byteCounterLow = Pm.rx.byteCounterLow;
//Pma.rx.byteCounterHigh = Pm.rx.byteCounterHigh;

if((UINT16)GetMEthMaxF()  <= 1514)
{

if(
   Pm.rx.truncatedFrames |
   Pm.rx.outOfRangeErrors |
   Pm.rx.lengthCheckErrors |
   Pm.rx.longEvents |
   Pm.rx.crcErrors |
   Pm.rx.codeErrors |
   Pm.rx.falseCarrierErrors |
   Pm.rx.rxDvEvent |
   Pm.rx.previosPacketDropped |





   Pm.qos.rxQ1DroppedFrames |
   Pm.qos.rxQ2DroppedFrams
)
{
   Et = 1;
}
}
else
{

if(
   Pm.rx.truncatedFrames |
 //  Pm.rx.outOfRangeErrors |
   Pm.rx.lengthCheckErrors |
   Pm.rx.longEvents |
   Pm.rx.crcErrors |
   Pm.rx.codeErrors |
   Pm.rx.falseCarrierErrors |
   Pm.rx.rxDvEvent |
   Pm.rx.previosPacketDropped |





   Pm.qos.rxQ1DroppedFrames |
   Pm.qos.rxQ2DroppedFrams
)
{
   Et = 1;
}



}


			   
 // }
// }
  
	
// ans = PVG610_API_NetEthPmGet((deviceindex), 0, &Pm, &OneSecondPeriodCounter);

// if(ans) return;

//SetMEthSend(Pm.tx.wireByteCounterLow, Pm.tx.wireByteCounterHigh);
//SetMEthSend(Pm.tx.dones); 

//SetMEthSendU(Pm.tx.underruns);
if(variant == variant1)
{			   
Pma.tx.vlanTags += Pm.tx.vlanTags;
Pma.tx.backpressuresEvents += Pm.tx.backpressuresEvents;
Pma.tx.pauseFrames += Pm.tx.pauseFrames;
Pma.tx.controlFrames += Pm.tx.controlFrames;
Pma.tx.wireByteCounterLow = Pm.tx.wireByteCounterLow;
Pma.tx.wireByteCounterHigh = Pm.tx.wireByteCounterHigh;
Pma.tx.underruns += Pm.tx.underruns;
Pma.tx.giants += Pm.tx.giants;
Pma.tx.lateCollisions += Pm.tx.lateCollisions;
Pma.tx.maxCollisions += Pm.tx.maxCollisions;
Pma.tx.excessiveDefers += Pm.tx.excessiveDefers;
Pma.tx.nonExcessiveDefers += Pm.tx.nonExcessiveDefers;
Pma.tx.broadcasts += Pm.tx.broadcasts;
Pma.tx.multicasts += Pm.tx.multicasts;
Pma.tx.dones += Pm.tx.dones;
Pma.tx.reserved += Pm.tx.reserved;
Pma.tx.lengthCheckErrors += Pm.tx.lengthCheckErrors;
Pma.tx.crcErrors += Pm.tx.crcErrors;
Pma.tx.collisions += Pm.tx.collisions;

tmp64 = (Pma.tx.byteCounterHigh << 32) + Pma.tx.byteCounterLow + (Pm.tx.byteCounterHigh << 32) + Pm.tx.byteCounterLow;

Pma.tx.byteCounterLow = (UINT32)tmp64;
Pma.tx.byteCounterHigh = (UINT32)(tmp64 >> 32);


Pma.gfp.fcsErrors += Pm.gfp.fcsErrors;
Pma.gfp.checErrors += Pm.gfp.checErrors;
Pma.gfp.droppedFrames += Pm.gfp.droppedFrames;
Pma.gfp.frameDelineationLosses += Pm.gfp.frameDelineationLosses;

//Pma.qos.rxQ1Frames += Pm.qos.rxQ1Frames;
//Pma.qos.rxQ1DroppedFrames += Pm.qos.rxQ1DroppedFrames;
//Pma.qos.rxQ2Frames += Pm.qos.rxQ2Frames;
//Pma.qos.rxQ2DroppedFrams += Pm.qos.rxQ2DroppedFrams;
Pma.qos.txFrames += Pm.qos.txFrames;
Pma.qos.txDroppedFrames += Pm.qos.txDroppedFrames;


//Pma.tx.byteCounterLow = Pm.tx.byteCounterLow;
//Pma.tx.byteCounterHigh = Pm.tx.byteCounterHigh;





if(
   Pm.tx.underruns |
   Pm.tx.giants	|
   Pm.tx.lateCollisions |
   Pm.tx.maxCollisions |
   Pm.qos.txDroppedFrames |
   Pm.tx.lengthCheckErrors |
   Pm.tx.crcErrors |
   Pm.gfp.fcsErrors |
   Pm.gfp.checErrors |
   Pm.gfp.droppedFrames |
   Pm.gfp.frameDelineationLosses

)
{
   Er = 1;
}

}
//ans = PVG610_API_NetEthPmGet((deviceindex), 0, &Pm, &OneSecondPeriodCounter);

// if(ans) return;

 // printfp("\n\rReadErrors half");


//printfp("\n\rReadErrors 5");


//SetMEthReceived(Pm.rx.byteCounterLow,Pm.rx.byteCounterHigh);
 if(variant != variant1)
//if(1)
 {

ans = PVG610_API_NetEthPmGet(1, 0, &Pm, &OneSecondPeriodCounter);

  if(ans)
  {
 // printfpd("\n\r return : ans: %d", ans);
  return;
  }


  // SetMEthReceived(Pm.rx.dones);
 //  SetMEthReceivedCRC(Pm.rx.crcErrors);

Pma.tx.vlanTags += Pm.tx.vlanTags;
Pma.tx.backpressuresEvents += Pm.tx.backpressuresEvents;
Pma.tx.pauseFrames += Pm.tx.pauseFrames;
Pma.tx.controlFrames += Pm.tx.controlFrames;
Pma.tx.wireByteCounterLow = Pm.tx.wireByteCounterLow;
Pma.tx.wireByteCounterHigh = Pm.tx.wireByteCounterHigh;
Pma.tx.underruns += Pm.tx.underruns;
Pma.tx.giants += Pm.tx.giants;
Pma.tx.lateCollisions += Pm.tx.lateCollisions;
Pma.tx.maxCollisions += Pm.tx.maxCollisions;
Pma.tx.excessiveDefers += Pm.tx.excessiveDefers;
Pma.tx.nonExcessiveDefers += Pm.tx.nonExcessiveDefers;
Pma.tx.broadcasts += Pm.tx.broadcasts;
Pma.tx.multicasts += Pm.tx.multicasts;
Pma.tx.dones += Pm.tx.dones;
Pma.tx.reserved += Pm.tx.reserved;
Pma.tx.lengthCheckErrors += Pm.tx.lengthCheckErrors;
Pma.tx.crcErrors += Pm.tx.crcErrors;
Pma.tx.collisions += Pm.tx.collisions;

tmp64 = (Pma.tx.byteCounterHigh << 32) + Pma.tx.byteCounterLow + (Pm.tx.byteCounterHigh << 32) + Pm.tx.byteCounterLow;

Pma.tx.byteCounterLow = (UINT32)tmp64;
Pma.tx.byteCounterHigh = (UINT32)(tmp64 >> 32);


Pma.gfp.fcsErrors += Pm.gfp.fcsErrors;
Pma.gfp.checErrors += Pm.gfp.checErrors;
Pma.gfp.droppedFrames += Pm.gfp.droppedFrames;
Pma.gfp.frameDelineationLosses += Pm.gfp.frameDelineationLosses;

//Pma.qos.rxQ1Frames += Pm.qos.rxQ1Frames;
//Pma.qos.rxQ1DroppedFrames += Pm.qos.rxQ1DroppedFrames;
//Pma.qos.rxQ2Frames += Pm.qos.rxQ2Frames;
//Pma.qos.rxQ2DroppedFrams += Pm.qos.rxQ2DroppedFrams;
Pma.qos.txFrames += Pm.qos.txFrames;
Pma.qos.txDroppedFrames += Pm.qos.txDroppedFrames;


//Pma.tx.byteCounterLow = Pm.tx.byteCounterLow;
//Pma.tx.byteCounterHigh = Pm.tx.byteCounterHigh;



if(
   Pm.tx.underruns |
   Pm.tx.giants	|
   Pm.tx.lateCollisions |
   Pm.tx.maxCollisions |
   Pm.qos.txDroppedFrames |
   Pm.tx.lengthCheckErrors |
   Pm.tx.crcErrors |
   Pm.gfp.fcsErrors |
   Pm.gfp.checErrors |
   Pm.gfp.droppedFrames |
   Pm.gfp.frameDelineationLosses 

)
{
   Er = 1;
}

 }
//in asymmetric mode receive need use from provingent1
 /*

 SetMEthReceived(Pma.rx.dones);
 SetMEthTransmit(Pma.tx.dones);
 SetMEthReceivedCRC(Pma.rx.crcErrors);
 SetMEthSend(Pma.qos.rxQ1Frames + Pma.qos.rxQ2Frames);
 SetMEthSendU(Pma.qos.rxQ1DroppedFrames + Pma.qos.rxQ2DroppedFrams); 
 SetMEthRcvD(Pma.gfp.frameDelineationLosses);
  */

 SetMEthReceived(Pm.rx.dones);
 SetMEthTransmit(Pm.tx.dones);
 SetMEthReceivedCRC(Pm.rx.crcErrors);
 SetMEthSend(Pm.qos.rxQ1Frames + Pm.qos.rxQ2Frames);
 SetMEthSendU(Pm.qos.rxQ1DroppedFrames + Pm.qos.rxQ2DroppedFrams); 
 SetMEthRcvD(Pm.gfp.frameDelineationLosses);




 // UpdateErrors(mod);

// printfp("\n\rReadErrors finish");

}
//________________________________________________________quick

//#define QUICK_READ_ERRORS_PERIOD  (1000)
//#define QUICK_READ_ERRORS_PERIOD  (1)
#ifndef  CHECK_LOSS_MEM
#define QUICK_READ_ERRORS_PERIOD  (2)
//#define QUICK_READ_ERRORS_PERIOD  (100)
#else
#define QUICK_READ_ERRORS_PERIOD  (0)

#endif



#define	DISABLING_TIME	(10)

//_________________________________________________________quick

extern "C" unsigned char ReadingEnabled(unsigned char enabling)
{
 static unsigned long timer;

 if(!enabling) 
 {
 timer = time1;
 return 1;
 }
 else
 {
  if(timer > time1) timer = time1;
  if((time1 - timer) > DISABLING_TIME) 
  {
	return 1;
  }
  else return 0;
 }


  



}

#define UPDATE_ACM_COUNTERS_PERIOD	(2)

extern "C" void UpdateACMCounters(void)
{

static unsigned long timescan; 

 if((time1 - timescan) >= UPDATE_ACM_COUNTERS_PERIOD)
{

timescan = time1;

for(unsigned long i = 0; i < MODEM_QUANTITY; i++)
{
 if(modemp[i].txAcmProfile < ACM_MODES)
 {
 modemp[i].txAcmProfilesCounter[modemp[i].txAcmProfile]++;
 }

 if(modemp[i].rxAcmProfile < ACM_MODES)
 {
 modemp[i].rxAcmProfilesCounter[modemp[i].rxAcmProfile]++;
 }
}
}
}



//___________________________________________________D
extern "C" void ReadStateEasyD(void)
{
//do not get somereturn; //t 141104

char Buf[3];
//PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
// PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
// PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
unsigned char previons_status;
//unsigned char previons_mode;


unsigned char ans;//, ans1;
unsigned long flagmask = 1;
//unsigned char mod;
static unsigned long timescan;
unsigned long time1keep;

 unsigned char curreadmod = 0;
//static unsigned char cursendmod = 0;

static unsigned char deviceindex;
static unsigned long counter;
//float division;
unsigned char do_not_hangt = MODEM_QUANTITY<<1;
//  curreadmod++;
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
deviceindex++;
#else
deviceindex+=2;
#endif



// if(curreadmod >= MODEM_QUANTITY) curreadmod = 0;
 if(deviceindex >= (MODEM_QUANTITY << 1) ) deviceindex = 0;
if(timescan > time1) timescan = time1;

//if((time1 - timescan) > QUICK_READ_ERRORS_PERIOD)
if((time1 - timescan) >= QUICK_READ_ERRORS_PERIOD)
{
counter++;
timescan = time1;
 time1keep = time1;	 //to measure
if(ModemIsUsed(deviceindex>>1))  //hier cyckling
 {

//  if(curreadmod >= MODEM_QUANTITY) curreadmod = 0;
 if(deviceindex >= (MODEM_QUANTITY << 1) ) deviceindex = 0;
   do_not_hangt --;
 // if(!do_not_hangt)	break;
  if(!do_not_hangt)
 {
 //printfp("do_not");  
  	return;
 }
 }
 ans = PVG610_API_ModemStatusGet((deviceindex), 0, &Ms);
// check_norma_status++;
 //  printfpd("\n\r ns : %d", norma_status[deviceindex]);

 if(ans)	 //hier bad answers
 {
 norma_status[deviceindex]++;// |= ALARM_ANS; 
// check_norma_status++;
//  printfpd("\n\r _ns : %d", norma_status[deviceindex]);
 if(norma_status[deviceindex] > (ALARM_QUANTITY + 1))  //bad answer
{
   	norma_status[deviceindex]--;   //to not get to maximum and next step to zero
	if(!modemp[deviceindex].alarm)
	{
	modemp[deviceindex].alarm = 1;
#ifdef YOURNAL
  //	Add_Event(EV_ALARM, 1, (char*)&deviceindex);
  Add_Event(EV_PVG610_ALARM, 1, (char*)&deviceindex);
  oldflag_alarms = 1;

#endif
	}
}


if(GetTestMode() == 0x5A)
{

if(!(counter %5000))
{ 
 counter += 1;	 //to can print enover modem
//#ifdef START_PRINT
 printfp("\n\rAlarm ans :");
 printfpd("%d", ans);
 printfpd("dev %d",deviceindex);
//#endif
}

}


 ans_no_correct++;
 return; //110518
 }
 else
 {
// check_norma_status++;
  ans_correct++;
 norma_status[deviceindex] = 0;

  if(modemp[deviceindex].alarm)
	{
	modemp[deviceindex].alarm = 0;
//#ifdef YOURNAL
 // 	Add_Event(EV_NO_ALARM, 1, (char*)&deviceindex);
//#endif
	}

 }
  previons_status =	 modemp[deviceindex].acquireStatus;
  modemp[deviceindex].acquireStatus =   Ms.acquireStatus;
  modemp[deviceindex].acmEngineEnabled =   Ms.acmEngineEnabled;

   if(Ms.acmEngineEnabled)
   {
	 modemp[deviceindex].txAcmProfile =   Ms.txAcmProfile;
     modemp[deviceindex].rxAcmProfile =   Ms.rxAcmProfile;
   }
   else
   {
	 modemp[deviceindex].txAcmProfile =   ACM_MODES;
     modemp[deviceindex].rxAcmProfile =   ACM_MODES;
   }

 if(previons_status != modemp[deviceindex].acquireStatus)
//if(1)
 {
   //hier can set need write event to yournal  

  //   previons_status =	 modemp[deviceindex].acquireStatus;

   sprintf(Buf, "%02d",deviceindex);

   if(modemp[deviceindex].acquireStatus)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 2, Buf); //for test	   it work for variant ==  variant1 only
	 timelock = time1;
	  timekeepMSE = time1;

#endif
   }
   else
   {
#ifdef YOURNAL
	 Add_Event(EV_UNLOCK, 2, Buf); //for test
#endif
   }
 }
//  printfpd("\n\r3: %d", Ms.acquireStatus);

  FillLock(curreadmod,Ms.acquireStatus);
 if(Ms.acquireStatus)
 {

modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;

ulevelsn15503.levelsn15503.absoluteMse[curreadmod] = Ms.absoluteMseTenths;
ulevelsn15503.levelsn15503.normalizedMse[curreadmod] = Ms.normalizedMseTenths;
ulevelsn15503.levelsn15503.radialMse[curreadmod] = Ms.radialMseTenths;

//uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ms.lastAcquireError;
if(GetTestMode() == 0x5A)
{

if(!(counter %5000))
{ 
 counter += 1;	 //to can print enover modem
 printfp("\n\rprov : ");
 printfpd("%2d",(deviceindex));
 printfp(" Status Of Lock: ");
 printfpd("%d", modemp[deviceindex].acquireStatus);
 //printfp("  prot: ");
 //printfpd("%ld", modemp[deviceindex].protectionRxBytesFromProtection);
 printfp("  absMse: ");
 printfpd("%4ld", modemp[deviceindex].absoluteMseTenths);

 printfp("  normalizedMseTenths: ");
 printfpd("%ld", modemp[deviceindex].normalizedMseTenths);

 printfp("  acmEngineEnabled: ");
 printfpd("%ld", modemp[deviceindex].acmEngineEnabled);

 printfp("  Ms.txAcmProfile: ");
 printfpd("%ld", modemp[deviceindex].txAcmProfile);

 printfp("  Ms.rxAcmProfile: ");
 printfpd("%ld", modemp[deviceindex].rxAcmProfile);

 }  
//#endif
}  
  }
  else	//is not in lock
  {
if(GetTestMode() == 0x5A)
{
if(!(counter %5000))
{  
 counter += 1;	//to print enover modem
 printfp("\n\rprov : ");
 printfpd("%2d",(deviceindex));
 printfp(" Status: ");
 printfpd("%d", modemp[deviceindex].acquireStatus);
 printfp("  absMse: ");

 printfp("  normalizedMseTenths: ");
 printfpd("%ld", modemp[deviceindex].normalizedMseTenths);

 printfp("  acmEngineEnabled: ");
 printfpd("%ld", modemp[deviceindex].acmEngineEnabled);

 printfp("  Ms.txAcmProfile: ");
 printfpd("%ld", modemp[deviceindex].txAcmProfile);

 printfp("  Ms.rxAcmProfile: ");
 printfpd("%ld", modemp[deviceindex].rxAcmProfile);

 printfpd("%4ld", modemp[deviceindex].absoluteMseTenths);
}	 
//#endif 
}
 

modemp[deviceindex].counterSlip =   0;
modemp[deviceindex].absoluteMseTenths =   0;
modemp[deviceindex].normalizedMseTenths =   0;
modemp[deviceindex].radialMseTenths =   0;

  modemp[deviceindex].fecBlockCounter =  0;
  modemp[deviceindex].fecUncorrectedBlockCounter =  0;
  modemp[deviceindex].rsByteCounter =  0;
  modemp[deviceindex].rsErrorByteCounter = 0;
  modemp[deviceindex].ldpcAvgIterations =  0;
  modemp[deviceindex].protectionRxBytesFromProtection =  0;
  modemp[deviceindex].protectionUncorrectedBytes =   0;

ulevelsn15503.levelsn15503.absoluteMse[curreadmod] = 0;
ulevelsn15503.levelsn15503.normalizedMse[curreadmod] = 0;
ulevelsn15503.levelsn15503.radialMse[curreadmod] = 0;

}	  //not in lock

 }//timescan
}


//___________________________________________________D

//____________________________________________________________________easy
//____________________________________________________________________currentrezerv
//____________________________________________________________________currentrezerv




//__________________________________________________________________________________________

//__________________________________________________________________________________________



extern "C" void ScanErrors1(void)
{
//static unsigned long timescan;
unsigned char mod_mask = 1;
static unsigned char curmod;
if(curmod >= MODEM_QUANTITY) curmod = 0;
//static unsigned long countert;
//countert++;
//if(!(countert % 5000))
//{
// printf("$");
//}


if(timescan > time1) timescan = time1;

if((time1 - timescan) > READ_ERRORS_PERIOD)
{
timescan = time1;

//OperateTrunks();



//t timer_config += READ_ERRORS_PERIOD / 1000l;
 timer_config += 1; //t
#ifdef TEST_TIME_CONFIG
 SetThreshold(8, timer_config);  //for test only!!!!!!!!!!!!!!!
#endif

//printfpd("\n\rscan errors: %d", curmod);



  switch(curmod)
  {
	case 0 :   if(!(used_modems & MASK_BIT_0)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod);/* ReadErrors1(curmod); */curmod++; break;}
	case 1 :   if(!(used_modems & MASK_BIT_1)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 2 :   if(!(used_modems & MASK_BIT_2)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 3 :   if(!(used_modems & MASK_BIT_3)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 4 :   if(!(used_modems & MASK_BIT_4)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 5 :   if(!(used_modems & MASK_BIT_5)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 6 :   if(!(used_modems & MASK_BIT_6)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 7 :   if(!(used_modems & MASK_BIT_7)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
	case 8 :   if(!(used_modems & MASK_BIT_8)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}

	default : curmod = 0; 
  }

 
}

}

extern "C" void ScanErrors(void)
{
//static unsigned long timescan;
unsigned char mod_mask = 1;
static unsigned char curmod;
//if(curmod >= MODEM_QUANTITY) curmod = 0;
//static unsigned long countert;
//countert++;
//if(!(countert % 5000))
//{
// printf("$");
//}


if(timescan > time1) timescan = time1;

if((time1 - timescan) > READ_ERRORS_PERIOD)
{
timescan = time1;

//OperateTrunks();



timer_config += READ_ERRORS_PERIOD / 1000l;

#ifdef TEST_TIME_CONFIG
 SetThreshold(8, timer_config);  //for test only!!!!!!!!!!!!!!!
#endif

// printfpd("\n\rscsn errors: %d", curmod);



  switch(curmod)
  {
	case 0 :     ReadErrors(0);/* ReadErrors1(curmod); */curmod++; break;	
	case 1 :     ReadErrors2(0);  /*ReadErrors3(0);*/ /* ReadErrors1(curmod); */curmod++; break;
   	case 2 :   /*  ReadErrors2(0); */ReadErrors3(0);curmod = 0; break;

	default : curmod = 0; 
  }

 
}

}


#define M_1_0  (1)
#define M_1_1  (2)
#define M_0_0  (0)
#define CLEAR_M  (0xf0)
#define MAX_MOD (9)
#define NO_TYPE (0)

#ifndef N_MOD
extern "C" void SetModemStruct(unsigned char im, unsigned char typemodem)
{
  if(im > MAX_MOD) return; //

  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] &= CLEAR_M;
  unEmb2TypeVer.emb2TypeVer.signature_software[im + 1] = NO_TYPE;

switch(typemodem)
 {
//not need  case 0 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] |= M_0_0;  break;
 case 1 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] |= M_1_0; 
 		   unEmb2TypeVer.emb2TypeVer.signature_software[im + 1] =	GetNumConfigFile(im);
  break;
 case 2 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] |= M_1_1; 
 		   unEmb2TypeVer.emb2TypeVer.signature_software[im + 1] =	GetNumConfigFile(im);
  break;
 default:  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] |=  M_0_0;; 
 		   unEmb2TypeVer.emb2TypeVer.signature_software[im + 1] =	NO_TYPE(im);

 
 
 break;
 }
}

#else	//N_MOD

extern "C" void SetModemStruct(unsigned char im, unsigned char typemodem)
{
  if(im > MAX_MOD) return; //

  unEmb2TypeVer.emb2TypeVer.signature_hardware[im] &= CLEAR_M;
  unEmb2TypeVer.emb2TypeVer.signature_software[im] = NO_TYPE;

switch(typemodem)
 {
//not need  case 0 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im + 1] |= M_0_0;  break;
 case 1 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im] |= M_1_0; 
 		   unEmb2TypeVer.emb2TypeVer.signature_software[im] =	GetNumConfigFile(im);
  break;
 case 2 :  unEmb2TypeVer.emb2TypeVer.signature_hardware[im] |= M_1_1; 
 		   unEmb2TypeVer.emb2TypeVer.signature_software[im] =	GetNumConfigFile(im);
  break;
 default: break;
 }
}


#endif	  //N_MOD

#define RESET_DELAY (1000)

extern "C" void StartNewConfigFile(unsigned char im)
{
char typemodem;
 typemodem =  ModemIsUsed(im);
 if(typemodem)	//1c
 {
//  SetModemStruct(im,typemodem);
/* 	 //to add HotStartConfigFile
    CommonResetOn(im);
	delay_mcs(RESET_DELAY);
    ResetSyntOff(im);
 //  LoadSyntm(im);
 //   LoadSyntmf(GetNumConfigFile(im),im);
    CommonResetOff(im);
 	StartModems(im);
	*/
    HotStartConfigFile(im);
//   used_modems |= mod_mask;
//ConfigFileLoadm(GetNumConfigFile(im), im);
//ConfigFileRunm(im);


 }
 else
 {
//	used_modems &= ~(mod_mask);
//     SetModemStruct(im,typemodem);
 }


}



extern "C" void ScanModems(void)
{
static unsigned long timescan;
unsigned short mod_mask = 1;
static unsigned long countert;
countert++;
char typemodem;
//if(!(countert % 5000))
//{
// printf("$");
//}


if(timescan > time1) timescan = time1;

if((time1 - timescan) > SCAN_PERIOD)
{
timescan = time1;
// printf("\n\r scan ");
for(long im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
 //printf("%d", im);
 typemodem =  ModemIsUsed(im);
 if(typemodem)	//1c
 {
 //  printf("_%d", im);
   if(!(used_modems & mod_mask))
   {
//   printf("+%d", im);
  
//hot get on

   SetModemStruct(im,typemodem);
   ResetSyntOff(im);
 //  LoadSyntm(im);
//printfp("1210047");
   LoadSyntmf(GetNumConfigFilet(im),im);

   CommonResetOff(im);
   StartModems(im);
   

//\

//#ifdef USART0_TRY_PDC_1T
// printfp("\n\rStart Initi");
//#endif

#ifndef PROG_BMDN4
   if(currentgetrezerv == NO_MODEM)
	 {
  	//	 currentgetrezerv == im;
  		 SetStartRezerv();
	 }
#endif

  embSerialACT155.Initi(im);
  SetModemStruct(im,typemodem);


//#ifdef USART0_TRY_PDC_1T
 // printfp("\n\rEnd Initi");

//#endif

  CommonResetOn(im);
  delay_mcs(1000l); //????????????? need
  ResetSyntOff(im);
 //	 delay_mcs(20000l);

 //  LoadSyntm(im);
 //printfp("1210048");
   LoadSyntmf(GetNumConfigFilet(im),im); //100728
   CommonResetOff(im);
#ifndef PROG_BMDN6MI
   statrez[im].Init();
#endif
   StartModems(im);
   SetNeedInitAllProti(im);
//   if(currentgetrezerv == NO_MODEM)
//	 {
//  		 currentgetrezerv == im;
//  		 SetStartRezerv();
//	 }

//\
   RestartTest++;
   used_modems |= mod_mask;
 
  
   }


 }
 else
 {
  // printf("-%d", im);
    if((used_modems & mod_mask))
   {

	used_modems &= ~(mod_mask);
    SetModemStruct(im,typemodem);

	if(currenthaverezerv == im)
	{
	  currenthaverezerv = NO_MODEM;
	}
	  if(currentgetrezerv == im)
	 {
       currentgetrezerv = NO_MODEM;	 //need set to reserv from loading state
	   SetStartRezerv();
	 }
	}

 }
  mod_mask <<= 1;
} //for
}



}

 /*
#ifndef PROG_BMDN6MI
extern "C" void StartModem()
{
FirmwareLoad();
ConfigFileLoad();
ConfigFileRun();
ModemStatusGet();  //old data
ModemStatusGet();


}
#endif
  */
extern "C" void ComConfigure(unsigned char var)
{
switch(var)
{
case 0:   PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, 200000000l); break;
case 1:   PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, 200000000l); break;
//case 1:   PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, 100000000l); break;

default :	 PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, 200000000l); break;

}


}




extern "C" unsigned long  GetVersionAPI(void)
{
unsigned long retval;
PVG610_MODEM_VERSION_STRUCT ver;
//printEthStringAdd(0,0);
 retval = PVG610_API_VersionGet(0, &ver);
//printEthStringAdd(2,0);
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
BYTE BuffTmp[100];
pBuffer = &BuffTmp[0];
UINT32 len = 100;

/*
typedef __PACK_PREFIX__ struct
{
    BYTE                majorVersion;
    BYTE                minorVersion;
    BYTE                buildVersion;
    BYTE                reserved[4];
} __PACK__ PVG610_MODEM_VERSION_STRUCT;
*/

// PVG610_API_ModemStatusGet(0, 0, pMs);
// PVG610_API_VersionGet(1, &ver);
//  PVG610_API_ConfigFileRun(0, 0);
//  PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
 // PVG610_API_FirmwareFromHostBoot(0, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//   retval = PVG610_API_VersionGet(2, &ver);
// retval = PVG610_API_DeviceReset(0,PVG610_DEVICE_RESET_ALL_E); //t
// printEthLongHex(retval);
if(!retval)
{
 retval = (ver.majorVersion << 16) + (ver.minorVersion << 8) + ver.buildVersion;
}
else
{
 retval = BAD_VALUE_ANS;
}
 return retval;
}

/*
#define MAX_SP_LEN (256)
#define ADDR_STATUS	(0x3)
#define GO_BIT (0x1)
#define RESET_BIT  (0x2)
#define ADDR_DATA  (0x2)
*/

unsigned char  RearrangeByte(unsigned char inpByte)
{
unsigned char mask = 0x80;
unsigned char outbyte = 0;
while(mask)
 {
   outbyte >>= 1;
  if(inpByte & mask)
  {
   outbyte += 0x80;
  }
   mask >>= 1;


 }
return outbyte;

}
 
#ifndef PROG_BMDN6MI
extern "C" void FlashFirmwareLoad()
{
//PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareReload(BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex);
 PVG610_API_FlashFirmwareReload(0, 0);
}


extern "C" void FirmwareLoad()
{

//printf("\n\r FirmwareLoad");
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT ver;
// retval = PVG610_API_VersionGet(0, &ver);

PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
//BYTE BuffTmp[100];
//pBuffer = &BuffTmp[0];
//UINT32 len = 100;

 // unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff; 

// unsigned int XilSizeToDownload    = XilSizeToDownloadD2; //0x1ffff; 


//#ifndef TEST_BMDN
UINT32 len = (unsigned int)ProvSizeToDownloadD;
//#else
//UINT32 len = (unsigned int)ProvSizeToDownloadD1;
//#endif
//_______________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;
//printf("\n\r len = %d", len);
//___________________________________________________________________________
  read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)len, (char *)(&TFTP_Buffer[0]));


//UINT32 len = (unsigned int)ProvSizeToDownloadD;
//_____________________________________________________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
 // read_dataflash ((unsigned int)(ProvDataAddressD + HEADER_SIZE), (unsigned int)ProvSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(XilDataAddressD), (unsigned int)XilSizeToDownload, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
//  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);




//_____________________________________________________________________
//for(long its = 0x0; its < 0x100; its++)
//{
//if(!(its% 0xf)) printf("\n\r");
// printf(" %02X ",TFTP_Buffer[its]);
//}




// PVG610_API_ModemStatusGet(0, 0, pMs);
// PVG610_API_VersionGet(1, &ver);
//  PVG610_API_ConfigFileRun(0, 0);
//  PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
// printEthStringAdd(0,0);
//  _int_disable();

//printf("\n\r .....0");
 PVG610_API_FirmwareFromHostBoot(0, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
//  _int_enable();
//printf("\n\r .....finish");

 //  printEthStringAdd(2,0);

//   retval = PVG610_API_VersionGet(2, &ver);
// retval = PVG610_API_DeviceReset(0,PVG610_DEVICE_RESET_ALL_E); //t
// printEthLongHex(retval);




}




extern "C" void ConfigFileLoad()
{
//printf("\n\r ConfigFileLoad");
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
UINT32 len; //101223 = (unsigned int)ProvSizeToDownloadDCfgFile;
read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
// printEthStringAdd(0,0);


//printf("\n\r .....0");

//printf("\n\r start len = %d", len);
 PVG610_API_ConfigFileFromHostLoad(0, 0, pBuffer, len);
//printf("\n\r .....finish");

  // printEthStringAdd(2,0);
}

#endif
  /*
BYTE ReadBuffer[ProvSizeToDownloadDCfgFile];

extern "C" void ConfigFileGet()
{

//BYTE ReadBuffer[ProvSizeToDownloadDCfgFile];
//printf("\n\r ConfigFileGet");

//BYTE ReadBuffer[ProvSizeToDownloadDCfgFile];

//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_MODEM_STATUS_STRUCT *pMs;
//pMs = &Ms;
//BYTE *pBuffer;
UINT32 len = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT16 readlen = 0;
//ok return;

for(long ir = 0; ir < ProvSizeToDownloadDCfgFile; ir++)
 {
  ReadBuffer[ir] = 0;
 }

//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//pBuffer=(unsigned char*)(&ReadBuffer[0]);
// printEthStringAdd(0,0);


//printf("\n\r .....0");

//return;

//printf("\n\r start len = %d", len);
//ok  return;
 PVG610_API_ConfigFileFromEmbeddedGet(0, 0, &ReadBuffer[0], len, &readlen);

// printf("\n\r readlen = %d", readlen);
 for(ir = 0; ir < ProvSizeToDownloadDCfgFile; ir++)
 {
  if(!(ir%16))
 // printf("\n\r");
 // printf(" %02X", ReadBuffer[ir]);
 }



// printf("\n\r .....finish");
// printEthStringAdd(2,0);


}

   	*/

#ifndef PROG_BMDN6MI
extern "C" void ConfigFileRun()
{
//printf("\n\r ConfigFileRun");
//printf("\n\r .....0");
  PVG610_API_ConfigFileRun (0,0);
// printf("\n\r .....finish");
}
#endif
  
#ifndef PROG_BMDN6MI
extern "C" void ModemStatusGet()
{
#ifndef USART0_TRY_PDC_1T
printf("\n\r ModemStatusGet");
#endif
PVG610_MODEM_STATUS_STRUCT	Ms;
   PVG610_API_ModemStatusGet(0, 0, &Ms);
#ifndef USART0_TRY_PDC_1T
printf("...ok");
#endif
   
//printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
//printf("\n\r lastAcquireError : %02X" , Ms.lastAcquireError);
//printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
//printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
//printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);
//printf("\n\r internalAgc : %d" , Ms.internalAgc);
//printf("\n\r externalAgcRegister : %X" , Ms.externalAgcRegister);
//printf("\n\r carrierOffset : %d" , Ms.carrierOffset);
//printf("\n\r rxSymbolRate : %d" , Ms.rxSymbolRate);
//printf("\n\r txSymbolRate : %d" , Ms.txSymbolRate);
//printf("\n\r ldpcDecoderStress : %X" , Ms.ldpcDecoderStress);
//printf("\n\r txAcmProfile : %02X" , Ms.txAcmProfile);
//printf("\n\r rxAcmProfile : %02X" , Ms.rxAcmProfile);
//printf("\n\r acmEngineEnabled : %d" , Ms.acmEngineEnabled);
//printf("\n\r debugIndications : %02X" , Ms.debugIndications);
 

}

#endif
 
#ifndef PROG_BMDN6MI
extern "C" void ModemAcquireCountersGet()
{
//printf("\n\r ModemAcquireCountersGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);

// printf("\n\r lolTimeMsec : %ld" , Ac.lolTimeMsec);
// printf("\n\r numLolEvents : %ld" , Ac.numLolEvents);
// printf("\n\r numAcquireTrials : %ld" , Ac.numAcquireTrials);
// printf("\n\r lastLockTimeSymbols : %ld" , Ac.lastLockTimeSymbols);
// printf("\n\r lastLockTimeBits : %ld" , Ac.lastLockTimeBits);
// printf("\n\r lastLockTimeService : %ld" , Ac.lastLockTimeService);
// printf("\n\r lastAcquireTimeUsec : %ld" , Ac.lastAcquireTimeUsec);
// printf("\n\r lastTotalAcquireTimeUsec : %ld" , Ac.lastTotalAcquireTimeUsec);
 
}
#endif
	
#define MAX_MAILBOX   (32)
//#ifndef PROG_BMDN6MI
extern "C" unsigned char ModemMailboxMessageSend(unsigned short msgLen, unsigned char * pData)
{
// printfp("\n\r ModemMailboxMessageSend");
 if(msgLen > MAX_MAILBOX) return 0;
 PVG610_MAILBOX_MESSAGE_STRUCT Mbx;
 BYTE result;
 Mbx.msgLen = msgLen;
  for(long i = 0; i < msgLen; i++)
  {
   Mbx.message[i] = *pData++;
  }
  result = PVG610_API_MailboxMessageSend(0,0, &Mbx);
 // printfpd(" result: : %X", result);
  return (unsigned char)result;
}

extern "C" unsigned char * ModemMailboxMessageReceive(void)
{
 //printfp("\n\r ModemMailboxMessageReceive");
  BYTE result;
 //if(msgLen > MAX_MAILBOX) return;

 static PVG610_MAILBOX_MESSAGE_STRUCT Mbx;
// Mbx.msgLen = msgLen;
//  for(long i = 0; i < msgLen; i++)
//  {
//   Mbx.message[i] = *pData++;
//  }
 result = PVG610_API_MailboxMessageReceive(0,0, &Mbx);
// if(result)
 //{
// }

//____________________________________
// printfpd(" return : %X", result);

if(result)
 {
 // printf(" error : %X", result);

 	return NULL;
 }

//#ifndef USART0_TRY_PDC_1T
//printfpd("\n\r Mbx.msgLen = %d  \n\r",Mbx.msgLen);
//#endif
// if (Mbx.msgLen <=  MAX_MAILBOX)
// {
 // for(long i = 0; i < Mbx.msgLen; i++)
  for(long i = 0; i < MAX_MAILBOX; i++)
  {
//#ifndef USART0_TRY_PDC_1T
 //  printfpd(" %02X", Mbx.message[i]);
//#endif
  }
 // printfp("\n\r");

 // for(i = 0; i < MAX_MAILBOX; i++)
 // {
 //  printf(" %c", Mbx.message[i]);
 // }


// }

 return (unsigned char *) &Mbx;
}

//#endif
   

extern "C" void ModemFecCountersGet()
{
//printf("\n\r ModemFecCountersGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_API_ModemFecCountersGet(0, 0, &Fc);
/*
typedef struct {
UINT32 fecBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 fecUncorrectedBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 rsByteCounter; // cumulative, clear on read
UINT32 rsErrorByteCounter; // cumulative, clear on read
UINT16 ldpcAvgIterations; // in 1/256 iterations units
BYTE viterbiNormalRate;
BYTE resereser
UINT32 protectionRxBytesFromProtection; // Current bytes received from the protection // replacing erroneous bytes from the working device
UINT32 outputUncorrectedBytes;
} PVG610_MODEM_FEC_COUNTERS_STRUCT;
*/
  /*
// printf("\n\r fecBlockCounter : %ld", Fc.fecBlockCounter);
// printf("\n\r fecUncorrectedBlockCounter : %ld", Fc.fecUncorrectedBlockCounter);
// printf("\n\r rsByteCounter : %ld", Fc.rsByteCounter);
// printf("\n\r rsErrorByteCounter : %ld", Fc.rsErrorByteCounter);
// printf("\n\r ldpcAvgIterations : %d", Fc.ldpcAvgIterations);
// printf("\n\r viterbiNormalRate : %02X", Fc.viterbiNormalRate);
// printf("\n\r protectionRxBytesFromProtection : %ld", Fc.protectionRxBytesFromProtection);
// printf("\n\r protectionUncorrectedBytes : %ld", Fc.protectionUncorrectedBytes);
 */
// printf("\n\r protectionUncorrectedBytes : %ld", Fc.protectionUncorrectedBytes);

}




extern "C" void ModemAcmCountersGet(unsigned char deviceindex)
{
unsigned char ret;

//printfp("\n\r ModemAcmCountersGet");
//printfpd(" %d...", deviceindex);

//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ACM_COUNTERS_STRUCT Mc;
   ret = PVG610_API_AcmCountersGet(deviceindex, 0, &Mc);

   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("%d" , ret); 
//printfpd(" r %X" , Mc.acmRxProfilesHistory);
//printfpd(" t %X" , Mc.acmTxProfilesHistory);

modemp[deviceindex].acmRxProfilesHistory = Mc.acmRxProfilesHistory;
modemp[deviceindex].acmTxProfilesHistory = Mc.acmTxProfilesHistory;




  
}

extern "C" void ModemAcmProfileMaskGet(unsigned char deviceindex)
{
UINT16 profilesMask;
unsigned char ret;

//printfp("\n\r ModemAcmProfileMaskGet");
//printfpd(" %d", deviceindex);
//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_ACM_COUNTERS_STRUCT Mc;
 ret =  PVG610_API_ModemAcmProfileMaskGet(deviceindex, 0,  &profilesMask);
	modemp[deviceindex].profilesMask = 	profilesMask;
   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("...%d" , ret); 
//printfp(" Mask : 0x");
//printfpd("%X" , profilesMask);
  
}


extern "C" void ModemAcmEngineEnable(unsigned char deviceindex, unsigned char enableRx, unsigned char enableTx)
{
//UINT16 profilesMask;
unsigned char ret;

//printfp("\n\r ModemAcmEngineEnable");
//printfpd(" %d", deviceindex);
//printfpd("r %d", enableRx);
//printfpd("r %d", enableTx);

//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_ACM_COUNTERS_STRUCT Mc;
 ret = PVG610_API_ModemAcmEngineEnable( deviceindex, 0,	enableRx, enableTx);

   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("...%d" , ret); 
//printfp(" Mask : 0x");
//printfpd("%X" , profilesMask);
  
}

extern "C" void ModemAcmSwitch(unsigned char deviceindex, unsigned char acmProfile, unsigned char isLocal)
{
//UINT16 profilesMask;
unsigned char ret;

printfp("\n\r ModemAcmSwitch");
printfpd(" %d", deviceindex);
printfpd("a %d", acmProfile);
printfpd("i %d", isLocal);

//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_ACM_COUNTERS_STRUCT Mc;
 ret =  PVG610_API_ModemAcmSwitch(deviceindex, 0, acmProfile, isLocal);

   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("...%d" , ret); 
//printfp(" Mask : 0x");
//printfpd("%X" , profilesMask);
  
}


extern "C" void ModemAcmThresholdSet(unsigned char deviceindex, unsigned char engineTable, unsigned char profile, unsigned short mseTenthsVal, unsigned char ldpcMantissaTenths,  unsigned char ldpcExponent,  unsigned char criteria, unsigned char nextProfile)
 {
//UINT16 profilesMask;
unsigned char ret;

//printfp("\n\r ModemAcmThresholdSet");
//printfpd(" %d", deviceindex);
//printfpd("a %d", acmProfile);
//printfpd("i %d", isLocal);

//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_ACM_COUNTERS_STRUCT Mc;
 ret =  PVG610_API_ModemAcmThresholdSet(deviceindex,0, engineTable, profile, mseTenthsVal,  ldpcMantissaTenths, ldpcExponent, criteria, nextProfile);

   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("...%d" , ret); 
//printfp(" Mask : 0x");
//printfpd("%X" , profilesMask);
  
}



extern "C" void ModemAcmProfileEnable(unsigned char deviceindex, unsigned short profilesMask)
{
//UINT16 profilesMask;
unsigned char ret;

//printfp("\n\r ModemAcmProfileEnable");
//printfpd(" %d", deviceindex);
//printfpd("p %X", profilesMask);
//printfpd("r %d", enableTx);

//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_ACM_COUNTERS_STRUCT Mc;
 ret = PVG610_API_ModemAcmProfileEnable( deviceindex, 0,  profilesMask);


   
 //   UINT16               acmRxProfilesHistory;
  //  UINT16               acmTxProfilesHistory;
  
//printfpd("...%d" , ret); 
//printfp(" Mask : 0x");
//printfpd("%X" , profilesMask);
  
}




/*
extern "C" void ModemAcmCountersGet()
{
printf("\n\r ModemAcmCountersGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ACM_COUNTERS_STRUCT Mc;
   PVG610_API_AcmCountersGet(0, 0, &Mc);

 printf("\n\r acmRxProfilesHistory : %X" , Mc.acmRxProfilesHistory);
printf("\n\r acmTxProfilesHistory : %X" , Mc.acmTxProfilesHistory);
}

 */

extern "C" void ModemAlarmEnableGet()
{
//printf("\n\r ModemAlarmEnableGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ALARMS_STRUCT Ac;
PVG610_API_AlarmEnableGet(0, &Ac);
//printf("\n\r alarms : %X" , Ac.alarms);

}

extern "C" void ModemAlarmEnableSet()
{
//printf("\n\r ModemAlarmEnableSet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ALARMS_STRUCT Ac;
  Ac.alarms = 0xFFFFFFFF;
PVG610_API_AlarmEnableSet(0, &Ac);
//printf("\n\r alarms : %X" , Ac.alarms);

}

extern "C" void ModemAlarmEnableGetm(unsigned char deviceindex)
{
unsigned char ret;
//printf("\n\r ModemAlarmEnableGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ALARMS_STRUCT Ac;
ret = PVG610_API_AlarmEnableGet(deviceindex, &Ac);
//printf("\n\r alarms : %X" , Ac.alarms);
//#ifdef USART0_TRY_PDC_1T
//   printfp("\n\r ModemAlarmEnableGet...");
//   printfpd("dev %d", deviceindex);
//   printfpd("...%d", ret);
 //    printfpd("alarms : %lX", Ac.alarms);
//#else
//   printf("\n\r ModemAlarmEnableGet...");
//   printf("dev %d", deviceindex);
//   printf("...%d", ret);
//    printf("alarms : %lX", Ac.alarms);
//#endif

}

//need make flag and all loadings
extern "C" void ModemAlarmEnableSetm(unsigned char deviceindex)
{
unsigned char ret;

//printf("\n\r ModemAlarmEnableSet");

//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ALARMS_STRUCT Ac;
  Ac.alarms = 0xFFFFFFFF;
ret = PVG610_API_AlarmEnableSet(deviceindex, &Ac);
//printf("\n\r alarms : %X" , Ac.alarms);
//#ifdef USART0_TRY_PDC_1T
//   printfp("\n\r ModemAlarmEnableSet...");
//   printfpd("%d", deviceindex);
//   printfpd("...%d", ret);
//#else
//   printf("\n\r ModemAlarmEnableSet...");
//   printf("%d", deviceindex);
//   printf("...%d", ret);

//#endif


}

extern "C" void ModemAlarmStatusGetm(unsigned char deviceindex)
{
unsigned char ret;
//printf("\n\r ModemAlarmEnableSet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ALARMS_STRUCT Ac;
 // Ac.alarms = 0xFFFFFFFF;
ret = PVG610_API_AlarmStatusGet(deviceindex, &Ac);
//printf("\n\r alarms : %X" , Ac.alarms);
//#ifdef USART0_TRY_PDC_1T
//   printfp("\n\r ModemAlarmStatusGet");
//   printfpd(" %d", deviceindex);
//   printfpd("...%d", ret);
//   printfpd(" alarms : %lX", Ac.alarms);

//#else
//   printf("\n\r ModemAlarmStatusGet...");
//   printf("dev %d", deviceindex);
//   printf("...%d", ret);
//    printf(" alarms : %lX", Ac.alarms);
//#endif
}

#define  LED_CH		  (7)
#define  LED_A		  (8)
#define	 AWAR_BIT	  (0x2)
#define	 NORMA_BIT	  (0x1)
#define	 NORMA_BIT1	  (0x4)
#define	 TESTMOD_BIT  (0x2)
#define	 REMOTE_BIT	  (0x4)
#define	 STOR_AL_BIT  (0x1)


//#define	 NORMA_UD1_BIT (0x10) //1 and 2 changed!!!!
//#define	 NORMA_UD2_BIT (0x20)

unsigned char oldflag; //need init
unsigned char oldflag2; //need init

//unsigned char oldflag_710; 
//unsigned char oldflag_ud1; //need init
//unsigned char oldflag_ud2; //need init
unsigned char oldflag_prv;
unsigned char oldflag_prv1;
unsigned char dev_status;
unsigned char oldflag_ifloop;
unsigned char oldflag_unmodul;
unsigned char oldflag_mrcntl;
unsigned char oldflag_alarms;




 extern "C" void OperateLeds3()
{

//printfp("\n\r OperateLeds3");
//static unsigned char blink;
unsigned char flag = 0;
unsigned char flag_prv = 0;
unsigned char flag2 = 0;

unsigned char flag_prv1 = 0;


//unsigned char flag_710 = 0;
//unsigned char flag_ud1 = 0;
//unsigned char flag_ud2 = 0;

unsigned char LedsReg  = 0;// = mod_mask;
unsigned char LedsReg1 = 0;// = mod_mask;
unsigned char LedsReg2 = 0;

unsigned char tmp;
//unsigned long syntez_error_counter;
//unsigned long pvg710_error_counter;



tmp = 0; 
if(Et) tmp |= MASK_BIT_0;
if(Er) tmp |= MASK_BIT_1;

Er = 0;
Et = 0;
 outportb(MOD_LED_ADDR3, tmp);




 /*

if(countUD1 < ALARM_LEVEL_UD) 
 {
   LedsReg |= NORMA_UD1_BIT;
    dev_status |= 	MASK_BIT_4;
   flag_ud1 = 0; 
 }
 else
 {
   LedsReg &= ~(NORMA_UD1_BIT);
    dev_status &= ~(MASK_BIT_4);
   flag_ud1 = 1;
 }

// printfpd(" c:%d ", countUD2);

if(countUD2 < ALARM_LEVEL_UD) 
 {
   LedsReg |= NORMA_UD2_BIT;
   dev_status |= 	MASK_BIT_5;
   flag_ud2 = 0; 
 }
 else
 {
   LedsReg &= ~(NORMA_UD2_BIT);
   dev_status &= ~(MASK_BIT_5);
   flag_ud2 = 1;
 }
// printfpd(" L:%02X ", LedsReg);

  */

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 for(unsigned is = 0; is < 2 ; is++)
//#else
// for(unsigned is = 0; is < 1 ; is++)
//#endif
{
if(norma_status[is] > ALARM_QUANTITY)  //bad answer
{
 flag = 1;
}
}

//_______________________________________________________________
// unsigned char stat710 = inportb(BLOCK_SWEEP1 + STATUS710_PORT);
 unsigned char statsynt = inportb(BLOCK_SWEEP1 + STATUSSYNT_PORT);

//if(stat710 == 0xff)
//{
// stat710 = 0; //without xilinx readed 0xff
//}

 if(norma_status[0] < ALARM_QUANTITY) { LedsReg1 |= MASK_BIT_0; flag_prv = 0;} 
 else {LedsReg1 &= ~(MASK_BIT_0); flag_prv = 1;}

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 if( (norma_status[1] < ALARM_QUANTITY)) { LedsReg1 |= MASK_BIT_1;	flag_prv1 = 0;}
 else {LedsReg1 &= ~(MASK_BIT_1); flag_prv1 = 1;}
//#else
 //LedsReg1 &= ~(MASK_BIT_1); //flag_prv1 = 1; //for jacke_mod
//#endif


///#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 if((oldflag_prv != flag_prv) || (oldflag_prv1 != flag_prv1))
 {
 oldflag_prv = flag_prv;
  oldflag_prv1 = flag_prv1;

tmp =  inportb(BLOCK_SWEEP1 + MOD_LED_ADDR2) & MASK_STATUS;

 outportb((BLOCK_SWEEP1 + MOD_LED_ADDR2), tmp | LedsReg1);
 }
//#else

//if((oldflag_prv != flag_prv) )
// {
// oldflag_prv = flag_prv;
// outportb((BLOCK_SWEEP1 + MOD_LED_ADDR2), LedsReg1);
// }
//#endif

//_______________________________________________________________



//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA

// if((stat710 & MASK_BIT_0) && (stat710 & MASK_BIT_1) && (!flag) && (statsynt & MASK_BIT_0))
//  {  LedsReg |= NORMA_BIT1; flag_710 = 0;} 		 //common norma
// else {LedsReg &= ~(NORMA_BIT1); flag_710 = 1;}

//#else

 if((!flag) && (statsynt & MASK_BIT_0))
  {  LedsReg |= NORMA_BIT1;} 		 //common norma
 else {LedsReg &= ~(NORMA_BIT1);}
//#endif
   
// #ifndef LOAD_ONE_PROVINGENT_ON_PLATA
//if((oldflag != flag) ||	(oldflag_ud1 != flag_ud1) || (oldflag_ud2 != flag_ud2) || (oldflag_710 != flag_710))
//{
// oldflag = flag;
// oldflag_ud1 = flag_ud1;
// oldflag_ud2 = flag_ud2;
// oldflag_710 = flag_710;
//  outportb(MOD_LED_ADDR1, LedsReg);	   //common norma
//}
//#else




if((oldflag != flag))
{

 oldflag = flag;
// oldflag_ud1 = flag_ud1;
// oldflag_ud2 = flag_ud2;
 //oldflag_710 = flag_710;
  outportb(MOD_LED_ADDR1, LedsReg);	   //common norma
}

   /*
if(oldflag_mrcntl != GetMRCntl())
{
 oldflag_mrcntl = GetMRCntl();

 if(oldflag_mrcntl)
 {
    LedsReg2 |= REMOTE_BIT;
 }
 else
 {
   LedsReg2 &= (~REMOTE_BIT);
 }




   outportb(LED_FA, LedsReg2);
}

*/

if((oldflag_unmodul != GetUnModul()) || (oldflag_ifloop != GetIFLoop())
		||  (oldflag_mrcntl != GetMRCntl())	 ||  (oldflag_alarms  == 1)	  
		 ||  (oldflag_alarms  == 2)	) 
{
 oldflag_unmodul = GetUnModul();
 oldflag_ifloop = GetIFLoop();
  oldflag_mrcntl = GetMRCntl();


 if(oldflag_unmodul || oldflag_ifloop)
 {
    LedsReg2 |= TESTMOD_BIT;
 }
 else
 {
   LedsReg2 &= (~TESTMOD_BIT);
 }

 if(oldflag_mrcntl)
 {
    LedsReg2 |= REMOTE_BIT;
 }
 else
 {
   LedsReg2 &= (~REMOTE_BIT);
 }

 if(oldflag_alarms  == 1)
 {
   LedsReg2 |= STOR_AL_BIT;
   oldflag_alarms = 0;
 //  outportb(LED_FA, LedsReg2);
 }
 else if(oldflag_alarms == 2)
 {
   LedsReg2 &= (~STOR_AL_BIT);
   oldflag_alarms = 0;
 //  outportb(LED_FA, LedsReg2);
 }

   outportb(LED_FA, LedsReg2);
}

 /*
 if(oldflag_alarms  == 1)
 {
   LedsReg2 |= STOR_AL_BIT;
   oldflag_alarms = 0;
   outportb(LED_FA, LedsReg2);
 }
 else if(oldflag_alarms == 2)
 {
   LedsReg2 &= (~STOR_AL_BIT);
   oldflag_alarms = 0;
   outportb(LED_FA, LedsReg2);
 }
 */


 /*

if((oldflag2 != flag2))
{

 oldflag2 = flag2;
// oldflag_ud1 = flag_ud1;
// oldflag_ud2 = flag_ud2;
 //oldflag_710 = flag_710;
  outportb(LED_FA, LedsReg2);	   //common norma
}
 */

//#endif
//_____________________________________

if(norma_status[0] < ALARM_QUANTITY)
{
//printfp("|");
 dev_status |= 	MASK_BIT_0;
}
else
{
//printfp("&");
 dev_status &= ~(MASK_BIT_0);
  unStatePUM.statePUM.state[2] |= CHANNEL1_LOCK_BIT;//2	   get off lock

}
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
if(norma_status[1] < ALARM_QUANTITY)
{
 dev_status |= 	MASK_BIT_1;
}
else
{
//#else
 dev_status &= ~(MASK_BIT_1);	//to compatilibity
 unStatePUM.statePUM.state[2] |= CHANNEL2_LOCK_BIT;//2	 get off lock

//#endif

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
}
//#endif

//_________________________________________________________________hier restart after 1 min!!!
//if(norma_status[0] > ALARM_QUANTITY1)
#ifndef PROG_MD310_SAT
if((norma_status[0] > ALARM_QUANTITY1)	||
   (syntez_error_counter > ALARM_QUANTITY2)
   
  //  || 	(pvg710_error_counter > ALARM_QUANTITY2))
{
//printfp("|");
// dev_status |= 	MASK_BIT_0;
//140409 if(GetTestMode() != 0xCC)
if( (GetTestMode() != 0xCC)	 && (ComparePOK(0x1000l)))	//140409
 {
  printfpd("\n\r norma_status : %d", norma_status[0]);
   printfpd("\n\r syntez : %d", syntez_error_counter);
   //	 printfpd("\n\r pvg710 : %d", pvg710_error_counter);
	  printfp("\n\r restart...");
	  OperateBuffers_usart0t();
  dev_restart();
 }
}
#endif

//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
/* maked restart only for first provingent
if(norma_status[1] > ALARM_QUANTITY1)
{
// dev_status |= 	MASK_BIT_1;
if(GetTestMode() != 0xCC)
  dev_restart();
}
*/
//#endif


//_________________________________________________________________

 
//if(stat710 & MASK_BIT_0)
//{
//printfp("\n\r-1");
// dev_status |= 	MASK_BIT_2;
// pvg710_error_counter = 0;
//  pvg710_error_counter++;	 //t
//}
//else
//{

 dev_status &= ~(MASK_BIT_2);	//compatibility
// pvg710_error_counter++;
//}


//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
//if(stat710 & MASK_BIT_1)
//{
// dev_status |= 	MASK_BIT_3;
//}
//else
//{
//#else
 dev_status &= ~(MASK_BIT_3);	 //compatibility
//#endif



//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
//}
//#endif
if(statsynt & MASK_BIT_0)
{
 dev_status |= 	MASK_BIT_6;		//ok
 syntez_error_counter = 0;
//  syntez_error_counter ++;//for test only
}
else
{
 dev_status &= ~(MASK_BIT_6);
 syntez_error_counter ++;
}

if(GetModForSS())// & MASK_BIT_0)
{
 dev_status |= 	MASK_BIT_7;
}
else
{
 dev_status &= ~(MASK_BIT_7);
}



 //  printfpd("\n\r%02X",LedsReg);
}



#define  MAX_TIME_WITHOUT_LOCK (30000l) //30 sec
#define  MAX_TIMES_TRY_GET_LOCK	(6)


extern "C" void  CheckLockS(void)		//maked only for wariant - one provingent on plata
{
 unsigned char deviceindex;

  for(unsigned i = 0; i < MODEM_QUANTITY; i++)
  {
   if(ModemIsUsed(i))
   {
	deviceindex = i << 1;
 //120213  if(modemp[deviceindex].acquireStatus == LOCK_OK)
   if((modemp[deviceindex].acquireStatus == LOCK_OK)	 ||
	  (modemp[deviceindex+1].acquireStatus == LOCK_OK))
   {
    modemp[deviceindex].LastTimeInLock = time1;
 //110909 this maked only at start	modemp[deviceindex].TimesTryGetLock = 0;
   }
   else
   {
 //   if((time1 - modemp[deviceindex].LastTimeInLock)	> MAX_TIME_WITHOUT_LOCK)
    if(((time1 - modemp[deviceindex].LastTimeInLock)	> MAX_TIME_WITHOUT_LOCK)   &&
	  (modemp[deviceindex].TimesTryGetLock < MAX_TIMES_TRY_GET_LOCK))

	 {
	   modemp[deviceindex].TimesTryGetLock ++;
	   modemp[deviceindex].LastTimeInLock = time1;
	   ConfigFileRunm(i);
	//   SetNeedInitAllProti(i);
	 }
	}
   }
  }
}

//#define STATE_SCAN_PERIOD (5000)
//#define STATE_SCAN_PERIOD (200)	 //t

extern "C" void PeriodicControl()
{
 static unsigned long timescan;

 if(timescan > time1)	timescan = time1;
#ifdef SEND_STATUS
static unsigned long timescan1;

 if(timescan1 > time1)	timescan1 = time1;
//if((time1 - timescan1) > SEND_STATUS_PERIOD)
 //{
  //160315 SendStatus();
 //  ReceiveStatus();
//  timescan1 = time1;
// }


#endif

 if((time1 - timescan) > STATE_SCAN_PERIOD)
 {
#ifdef DEBUG_COUNTERS
 printfpd("\n\r:comm %d", command_counter);
#endif

//printEthLongHex(command_counter);
  ParseOperProg();
 // SendStatus();

#ifdef OPERATE_ETH
//not need  EthStatusGet();
  EthStatusGetXil();
#endif

#ifndef PROG_BMDN4

 if((protection_mode == MODE_N_PLUS_1) && (ModemIsUsed(currentrezerv)))

  if(GetRxPhyId(currenthaverezerv << 1) == 0) //rezerving not validity
  {
//hier need make getting rezerv more times
  //	SetModemToRezerv(currenthaverezerv);
	  SendRequest(currenthaverezerv, GetChannelToSend());

  }

#endif

  

 
#ifdef USART0_TRY_PDC_1T
#ifndef	PROG_BMDN4
 	if(GetTestMode() == 0x5A) 
 	{
 //  printfp("\n\r PeriodicControl");
   printfp("\n\r curhaverez:");
   printfpd(" %d", currenthaverezerv);
   printfp(" curgetrez:");
   printfpd(" %d", currentgetrezerv);
   printfp(" currez:");
   printfpd(" %d", currentrezerv);
 //  printfp("\n\r t_start_p:");
 //  printfpd("%ld", time_start_prt);
 //  printfp(" t_rcv_req:");
  // printfpd(" %ld", time_rcv_req_to_get);
 //  printfp(" t_end_p:");
//   printfpd(" %ld", time_end_prt);
   printfp(" t_all:");
   printfpd(" %ld", (time_end_prt - time_start_prt));
   }

#endif

if(ans_correct)
 {
 // division =  ans_no_correct;
//  division /= (float)ans_correct;
  //printfp("\n\r ans_no_correct / ans_correct :");
 // printfpd("%.10f", division );
	if(GetTestMode() == 0x5A) 
 	{

    printfpd("\n\r bad %d", ans_no_correct );
	 printfpd(" badr %d", ans_no_correctr );
	printfpd(" ok %d", ans_correct );
	printfpd(" okr %d", ans_correctr );
	}
 }
 else
 {
	if(GetTestMode() == 0x5A) 
 	{

     printfp("\n\r ans_no_correct ");
   }
 
 }

#endif
  

  timescan = time1;
 
//#ifndef PROG_BMDN4

// if(protection_mode == MODE_N_PLUS_1)
// {
//   ReadStateRezerv();
// }
//#endif
   OperateLeds3();
   }
}


extern "C" void ModemAlarmEnableSetAllm(unsigned char flag)
{
unsigned char typemodem;
if(flag == MODEM_QUANTITY)
{
for(long im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
 //printf("%d", im);
 typemodem =  ModemIsUsed(im);
 if(typemodem)	//1c
 {
  ModemAlarmEnableSetm(im << 1);
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  ModemAlarmEnableSetm((im << 1) + 1);
#endif
 }

}
}
else
{
  ModemAlarmEnableSetm(flag << 1);
#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
  ModemAlarmEnableSetm((flag << 1) + 1);
#endif
}

}
 /*
extern "C" void ModemAlarmSetAllm(void)
{
unsigned char typemodem;

for(long im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
 //printf("%d", im);
 typemodem =  ModemIsUsed(im);
 if(typemodem)	//1c
 {
   ModemAlarmEnableSetm(im << 1);
   ModemAlarmEnableSetm((im << 1) + 1);
 }

}
}
 */

 /*
extern "C" void FirmwareReLoad()
{
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT ver;
// retval = PVG610_API_VersionGet(0, &ver);

PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
//BYTE BuffTmp[100];
//pBuffer = &BuffTmp[0];
//UINT32 len = 100;

  unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff; 



UINT32 len = (unsigned int)ProvSizeToDownloadD;
//_____________________________________________________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(ProvDataAddressD + HEADER_SIZE), (unsigned int)ProvSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(XilDataAddressD), (unsigned int)XilSizeToDownload, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
//  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);

 PVG610_API_FirmwareFromHostReload(0, pBuffer, len);
}

extern "C" void FirmwareBurn()
{
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT ver;
// retval = PVG610_API_VersionGet(0, &ver);

PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
//BYTE BuffTmp[100];
//pBuffer = &BuffTmp[0];
//UINT32 len = 100;

  unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff; 



UINT32 len = (unsigned int)ProvSizeToDownloadD;
//_____________________________________________________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(ProvDataAddressD + HEADER_SIZE), (unsigned int)ProvSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(XilDataAddressD), (unsigned int)XilSizeToDownload, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
//  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
 PVG610_API_FlashFirmwareBurn(0, 0, pBuffer, len); // PVG610_FIRMWARE_INDEX_ENUM try 0 
 }

extern "C" void DirectLoad(void)
{
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT ver;
// retval = PVG610_API_VersionGet(0, &ver);

PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
//BYTE BuffTmp[100];
//pBuffer = &BuffTmp[0];
//UINT32 len = 100;

  unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff; 



UINT32 len = (unsigned int)ProvSizeToDownloadD1;
//_______________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(ProvDataAddressD + HEADER_SIZE), (unsigned int)ProvSizeToDownloadD1, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(XilDataAddressD), (unsigned int)XilSizeToDownload, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
//  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________________

for(i = 0;  i < ProvSizeToDownloadD1; i++)
{


 Transmit0c((unsigned char) (*pBuffer++));
}

for(i = 0;  i < PROVEND; i++)
{
 Transmit0c((unsigned char) (0));
}

}
	 */
		  /*
extern "C" void LoadToLdr(void)
{
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT ver;
// retval = PVG610_API_VersionGet(0, &ver);

PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
//BYTE BuffTmp[100];
//pBuffer = &BuffTmp[0];
//UINT32 len = 100;

  unsigned int XilSizeToDownload    = XilSizeToDownloadD2; //0x1ffff; 



UINT32 len = (unsigned int)ProvSizeToDownloadD;
//_______________________________
//  unsigned char* ptr;
// unsigned char lo,hi;
//  register int i;

//___________________________________________________________________________
  read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(ProvDataAddressD + HEADER_SIZE), (unsigned int)ProvSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
//  read_dataflash ((unsigned int)(XilDataAddressD), (unsigned int)XilSizeToDownload, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
//  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________________



 SendAndJump(pBuffer);

}

  */
unsigned char * ExChangeSpi(unsigned long length_of_data, unsigned char * BufferData)
{
unsigned long do_not_hangt = 0xfff;

unsigned long lentmp;
unsigned char * BufferDataTmp;
static unsigned char ReadBuffer[MAX_SP_LEN];

//printEthStringAdd(1,0x88);
//printEthStringAdd(1,length_of_data);


 if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return ReadBuffer;

write_xil_char(ADDR_STATUS, RESET_BIT);

lentmp = length_of_data;
BufferDataTmp =  BufferData;
#ifdef PRINT_SPI_DATA
// printEthStringAdd(0,0);

//printEthStringAdd(1,0x88);
#endif
while(lentmp--)
{
#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,RearrangeByte(* BufferDataTmp));
//printEthStringAdd(1,* BufferDataTmp);
#endif

 write_xil_char(ADDR_DATA, * BufferDataTmp++);
 //write_xil_char(ADDR_DATA, RearrangeByte(* BufferDataTmp++));//t


}
write_xil_char(ADDR_STATUS, GO_BIT);

while(do_not_hangt--)
{
 if(!(read_xil_char(ADDR_STATUS) & GO_BIT)) break;
}
#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,0x99);
//printEthStringAdd(1,do_not_hangt>>16);
//printEthStringAdd(1,do_not_hangt>>8);
//printEthStringAdd(1,do_not_hangt);
//printEthStringAdd(1,0x99);
#endif



lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(ADDR_DATA);
#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,*BufferDataTmp);
#endif

BufferDataTmp++;

}
#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,0x77);
//printEthStringAdd(2,0);
#endif


return 	ReadBuffer;
}


void WriteSpiB(unsigned long length_of_data, unsigned char * BufferData)
{
//tunsigned long do_not_hangt = 0xfffl;
unsigned long do_not_hangt = 0xfffl;

unsigned long lentmp;
unsigned char * BufferDataTmp;


 if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return;

write_xil_char(ADDR_STATUS, RESET_BIT);

lentmp = length_of_data;
BufferDataTmp =  BufferData;
//#ifdef PRINT_SPI_DATA
// printEthStringAdd(0,0);

// printEthStringAdd(1,0x88);
//#endif
while(lentmp--)
{

 write_xil_char(ADDR_DATA, * BufferDataTmp++);
 //write_xil_char(ADDR_DATA, RearrangeByte(* BufferDataTmp++));//t


}
write_xil_char(ADDR_STATUS, GO_BIT);

while(do_not_hangt--)
{
 if(!(read_xil_char(ADDR_STATUS) & GO_BIT))
 {
// printf("  %X", do_not_hangt); 
 break;
 }
}

//delay_mcs(1000l); //t

//#ifdef PRINT_SPI_DATA
// printEthStringAdd(2,0);
//#endif

/*
#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,0x99);
//printEthStringAdd(1,do_not_hangt>>16);
//printEthStringAdd(1,do_not_hangt>>8);
//printEthStringAdd(1,do_not_hangt);
//printEthStringAdd(1,0x99);
#endif



lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(ADDR_DATA);
#ifdef PRINT_SPI_DATA
printEthStringAdd(1,*BufferDataTmp);
#endif

BufferDataTmp++;

}
#ifdef PRINT_SPI_DATA
printEthStringAdd(1,0x77);
printEthStringAdd(2,0);
#endif


return 	ReadBuffer;
*/
}

unsigned char * ReadSpiB(unsigned long length_of_data)
{
//unsigned long do_not_hangt = 0xff;
unsigned long do_not_hangt = 0xfff;

unsigned long lentmp;
unsigned char * BufferDataTmp;
static unsigned char ReadBuffer[MAX_SP_LEN];

//printEthStringAdd(1,0x88);
//printEthStringAdd(1,length_of_data);


 if((length_of_data > MAX_SP_LEN) || (!length_of_data))
 {

// printf("\n\r reading error!");
  return ReadBuffer;
 }

write_xil_char(ADDR_STATUS, RESET_BIT);

lentmp = length_of_data;
//BufferDataTmp =  BufferData;
//#ifdef PRINT_SPI_DATA

//if(print_flag)
//{
 //printEthStringAdd(0,0);

 //printEthStringAdd(1,0x33);
// }
//#endif
while(lentmp--)
{
//#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,RearrangeByte(* BufferDataTmp));
//printEthStringAdd(1,* BufferDataTmp);
//#endif

 write_xil_char(ADDR_DATA, 0x7e);
 //write_xil_char(ADDR_DATA, RearrangeByte(* BufferDataTmp++));//t


}

write_xil_char(ADDR_STATUS, GO_BIT);



while(do_not_hangt--)
{
 if(!(read_xil_char(ADDR_STATUS) & GO_BIT)) break;
}



//#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,0x99);
//printEthStringAdd(1,do_not_hangt>>16);
//printEthStringAdd(1,do_not_hangt>>8);
//printEthStringAdd(1,do_not_hangt);
//printEthStringAdd(1,0x99);
//#endif

//delay_mcs(500l); //t100507

lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(ADDR_DATA);
#ifdef PRINT_SPI_DATA
if(print_flag)
{
//printEthStringAdd(1,*BufferDataTmp);
}
#endif

BufferDataTmp++;

}
//#ifdef PRINT_SPI_DATA
//if(print_flag)
//{
//printEthStringAdd(1,0x77);
//printEthStringAdd(2,0);
//}
//#endif


return 	ReadBuffer;
}



extern "C" unsigned char GetUsart0Data(unsigned char *pBuff)
{
if(embRS232.UsedReceive())
 {
  *pBuff = embRS232.Receive();
//  printf("\n\r > %02X",*pBuff);
  return 1;
 }
return 0;
}
   /*
extern "C" void TryGetRezerv(unsigned char chn)
{
// printf("TryGetRezerv : %d", chn);
 if(currentgetrezerv == chn)  return;


}

#define  ENABLED_REQUESTS_QUANTITY (3)

extern "C" void ParseRequestsRezerv()
{
 static unsigned char tmp;
 unsigned char sym;
// static unsigned char reqcounter;
 if(embMsgWestR.Used())
 {
 while(embMsgWestR.Used())
 {
  sym = embMsgWestR.Get();
  if(tmp == sym)
  {
   reqcounter++;
  }
  else
  {
   tmp = sym;
   reqcounter = 0;
  }

  if(reqcounter >= ENABLED_REQUESTS_QUANTITY)
  {
	 TryGetRezerv(tmp);
	 reqcounter = 0;
	 embMsgWestR.Free();
  }

 }
 }
}
 */
#ifdef O_POWER

extern "C" void  DisableOperatePower(unsigned char trunk)
{
if(!GetModForSS1()) return;

if(trunk == 1)
 {
	 			embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,14);
			    embMsg485Request_1.SetBody(1,195);
				embMsg485Request_1.CalcCRC();
			 //	embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);

 }
 else
 {
 				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,14);
			    embMsg485Request_2.SetBody(1,195);
				embMsg485Request_2.CalcCRC();
			  //	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
 }

}


extern "C" void  EnableOperatePower(unsigned char trunk)
{
if(!GetModForSS1()) return;

if(trunk == 1)
 {
	 			embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,14);
			    embMsg485Request_1.SetBody(1,52);
				embMsg485Request_1.CalcCRC();
	  //			embMsg485Request_1.SetReadyToSend();
                tBuffEmbMsg485Request_1.Add(embMsg485Request_1);

 }
 else
 {
 				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,14);
			    embMsg485Request_2.SetBody(1,52);
				embMsg485Request_2.CalcCRC();
		  //		embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
 }

}

//#define MAX_POWER 0xff
#define MIN_POWER ((3 + 85) <<1)

#define DELTA_POWER 60	//this is delta code

extern "C" unsigned char GetMinPower()
{
 // return 192;	 //(0 + 85) <<1
 // return 100;	 //(0 + 85) <<1
// return 0;
// return 160;	 //(0 + 85) <<1
 return MIN_POWER;
}

extern "C" unsigned char GetMaxPower()
{

  signed short ret;

  if(power_rate < 5000000)
  {
  	switch(power_modul)
  	{
	 case 0 :  ret = 33;  break;//qpsk
	 case 1 :  ret = 31;  break;//8psk
	 case 2 :  ret = 31;  break;//8afpk
	 case 3 :  ret = 29;  break;//16qam
	 case 4 :  ret = 29;  break;//16apsk
	 case 5 :  ret = 27;  break;//32qam
	 case 6 :  ret = 27;  break;//32apsk
	 case 7 :  ret = 27;  break;//32apsk-s
	 case 8 :  ret = 25;  break;//64qam
 	 case 9 :  ret = 23;  break;//128qam
   //	 case 9 :  ret = 27;  break;//128qam
	 case 10 :  ret = 21; break;//256qam
	 default : 	 ret = 21; break;
   	}
  }
  else if(power_rate < 35000000)
  {
  	switch(power_modul)
  	{
	 case 0 :  ret = 33;  break;//qpsk
	 case 1 :  ret = 31;  break;//8psk
	 case 2 :  ret = 31;  break;//8afpk
	 case 3 :  ret = 29;  break;//16qam
	 case 4 :  ret = 29;  break;//16apsk
	 case 5 :  ret = 27;  break;//32qam
	 case 6 :  ret = 27;  break;//32apsk
	 case 7 :  ret = 27;  break;//32apsk-s
	 case 8 :  ret = 25;  break;//64qam
 	 case 9 :  ret = 23;  break;//128qam
  //	 case 9 :  ret = 27;  break;//128qam
	 case 10 :  ret = 21; break;//256qam
	 default : 	 ret = 21; break;
   	}
  }
  else
  {
  	switch(power_modul)
  	{
	 case 0 :  ret = 33;  break;//qpsk
	 case 1 :  ret = 31;  break;//8psk
	 case 2 :  ret = 31;  break;//8afpk
	 case 3 :  ret = 29;  break;//16qam
	 case 4 :  ret = 29;  break;//16apsk
	 case 5 :  ret = 27;  break;//32qam
	 case 6 :  ret = 27;  break;//32apsk
	 case 7 :  ret = 27;  break;//32apsk-s
	 case 8 :  ret = 25;  break;//64qam
 	 case 9 :  ret = 23;  break;//128qam
//	 case 9 :  ret = 27;  break;//128qam
	 case 10 :  ret = 21; break;//256qam
	 default : 	 ret = 21; break;
   	}
  }

 return (unsigned char)((ret + 85) << 1);
}

#define MAX_TRY (30)


extern "C" void  NormalizePower(unsigned char trunk)
{
 if(!GetModForSS1()) return;

if(trunk == 1)
 {

 


 // printEthLongHex(1);
 //	 printEthLongHex(unStateRRL.stateRRL.ppu1_bytes[1]);

	   //	if(pdpower1 < (GetMaxPower() - DELTA_POWER)) 
	 	if(unStateRRL.stateRRL.ppu1_bytes[1]  > GetMaxPower())
	//	 if(1)
		  {
   //  printEthLongHex((pdpower1<<8) + farinplev1);
 // printEthLongHex(0x88);
			   if(pdpower1 > 1)
			   {
		        pdpower1 -= 1;
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,2);
			    embMsg485Request_1.SetBody(1,pdpower1);
				embMsg485Request_1.CalcCRC();
		  //		embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
			   }
		  }

 }
 else
 {
 

 //  printEthLongHex(2);
 //  printEthLongHex(unStateRRL.stateRRL.ppu2_bytes[1]);
//   printEthLongHex(GetMaxPower());


  //	  if(pdpower2 < (GetMaxPower() - DELTA_POWER)) 
   		if(unStateRRL.stateRRL.ppu2_bytes[1]  > GetMaxPower())
	  //	  if(1)
		  {
	//   printEthLongHex(0x99);
	 if(pdpower2 > 1)
			 {

		  pdpower2 -= 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,2);
			    embMsg485Request_2.SetBody(1,pdpower2);
				embMsg485Request_2.CalcCRC();
		   //		embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
			}
		  }
 }

}


extern "C" void  IncrementPower(unsigned char trunk)
{
//printEthLongHex(4);
if(!GetModForSS1()) return;


if(trunk == 1)
 {
//printEthLongHex(4);
//#ifdef DEBUG_POWER
//   printfp("\n\r10\n\r");
//#endif


	try_counter1++;
	if(try_counter1 > MAX_TRY)
	{
	  flag_enable_operate_power1 = 1;	//need try enabling operate power
	  try_counter1 = 0;
	  return;
	}



 // printEthLongHex(1);
 //	 printEthLongHex(unStateRRL.stateRRL.ppu1_bytes[1]<<16);
   //	  printEthLongHex(GetMaxPower());

	   //	if(pdpower1 < (GetMaxPower() - DELTA_POWER)) 
	 	if(unStateRRL.stateRRL.ppu1_bytes[1]  < GetMaxPower())
	//	 if(1)
		  {
	 // 	  printEthLongHex(6);
   //  printEthLongHex((pdpower1<<8) + farinplev1);
 // printEthLongHex(0x88);
 #ifdef DEBUG_POWER
   printfp("\n\r11\n\r");
   printfpd(" pd: %d", pdpower1);
     printfpd(" max: %d", GetMaxPower());
	   printfpd(" ppu1: %d", unStateRRL.stateRRL.ppu1_bytes[1]);



#endif

		    if(pdpower1 < 254)
			   {

		  pdpower1 += 1;
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,2);
			    embMsg485Request_1.SetBody(1,pdpower1);
				embMsg485Request_1.CalcCRC();
		   //		embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
				}
		  }
		  else
		  {
  #ifdef DEBUG_POWER
   printfp("\n\r12\n\r");
   printfpd(" pd: %d", pdpower1);
     printfpd(" max: %d", GetMaxPower());
	   printfpd(" ppu1: %d", unStateRRL.stateRRL.ppu1_bytes[1]);

#endif



		  }



 }
 else
 {
	 try_counter2++;
	if(try_counter2 > MAX_TRY)
	{
	  flag_enable_operate_power2 = 1;	//need try enabling operate power
	  try_counter2 = 0;
	  return;
	}



 //  printEthLongHex(2);
 //  printEthLongHex(unStateRRL.stateRRL.ppu2_bytes[1]);
//   printEthLongHex(GetMaxPower());


  //	  if(pdpower2 < (GetMaxPower() - DELTA_POWER)) 
   		if(unStateRRL.stateRRL.ppu2_bytes[1]  < GetMaxPower())
	  //	  if(1)
		  {
	//   printEthLongHex(0x99);
			    if(pdpower2 < 254)
			   {
		        pdpower2 += 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,2);
			    embMsg485Request_2.SetBody(1,pdpower2);
				embMsg485Request_2.CalcCRC();
			//	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
				}
		  }
 }

}

extern "C" void  DecrementPower(unsigned char trunk)
{
if(!GetModForSS1()) return;


 // printEthLongHex(5);
if(trunk == 1)
 {
 // printEthLongHex(5);
	try_counter1++;
	if(try_counter1 > MAX_TRY)
	{
	  flag_enable_operate_power1 = 1;	//need try enabling operate power
	  try_counter1 = 0;
	  return;
	}



//   printEthLongHex(3);

	//	if(pdpower1 > (MIN_POWER + DELTA_POWER)) 
   //	 printEthLongHex(unStateRRL.stateRRL.ppu1_bytes[1]<<16);
   //	  printEthLongHex(GetMaxPower() - DELTA_POWER);

  //	   	if(unStateRRL.stateRRL.ppu1_bytes[1]  > (GetMaxPower() - DELTA_POWER))
  //   		if(1)
			if(unStateRRL.stateRRL.ppu1_bytes[1] > GetMinPower()) 
		  {
	//   	  printEthLongHex(7);
  	//	   printEthLongHex((pdpower1<<8) + farinplev1);
#ifdef DEBUG_POWER
   printfp("\n\r50\n\r");
   printfpd(" pd: %d", pdpower1);
   printfpd(" staterrl: %d", unStateRRL.stateRRL.ppu1_bytes[1]);
   printfpd(" min power: %d", GetMinPower());

#endif

		    if(pdpower1 > 1)
			   {
		       
		  pdpower1 -= 1;
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,2);
			    embMsg485Request_1.SetBody(1,pdpower1);
				embMsg485Request_1.CalcCRC();
		   //		embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
			  }
		  }
		 else
		 {
#ifdef DEBUG_POWER
   printfp("\n\r51\n\r");
   printfpd(" pd: %d", pdpower1);
#endif

		 }


 }
 else
 {
  try_counter2++;
	if(try_counter2 > MAX_TRY)
	{
	  flag_enable_operate_power2 = 1;	//need try enabling operate power
	  try_counter2 = 0;
	  return;
	}

 //  printEthLongHex(4);

  //	  if(pdpower2 > (MIN_POWER + DELTA_POWER)) 
	//   	if(unStateRRL.stateRRL.ppu2_bytes[1]  > (GetMaxPower() - DELTA_POWER))
  //		  if(1)
		if(unStateRRL.stateRRL.ppu2_bytes[1]> GetMinPower()) 
		  {

 //  printEthLongHex(0x55);
			 if(pdpower2 > 1)
			   {
		 
		  pdpower2 -= 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,2);
			    embMsg485Request_2.SetBody(1,pdpower2);
				embMsg485Request_2.CalcCRC();
			//	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
				}
		  }
 }


}

#define	 PM_MIN_LEVEL -49;
#define	 PM_MAX_LEVEL -47;

extern "C" signed long GetMinLevel(void)
{
  signed long ret;

  if(power_rate < 5000000)
  {
  	switch(power_modul)
  	{
	 case 0 :  ret =-74;  break;//qpsk
	 case 1 :  ret =-71;  break;//8psk
	 case 2 :  ret =-71;  break;//8afpk
	 case 3 :  ret =-63;  break;//16qam
	 case 4 :  ret =-63;  break;//16apsk
	 case 5 :  ret =-63;  break;//32qam
	 case 6 :  ret =-63;  break;//32apsk
	 case 7 :  ret =-63;  break;//32apsk-s
	 case 8 :  ret =-63;  break;//64qam
	 case 9 :  ret =-63;  break;//128qam
	 case 10 :  ret =-61; break;//256qam
	 default : 	 ret =-59; break;
   	}
  }
  else if(power_rate < 35000000)
  {
  	switch(power_modul)
  	{
	 case 0 :  ret =-68;  break;//qpsk
	 case 1 :  ret =-64;  break;//8psk
	 case 2 :  ret =-64;  break;//8afpk
	 case 3 :  ret =-61;  break;//16qam
	 case 4 :  ret =-61;  break;//16apsk
	 case 5 :  ret =-58;  break;//32qam
	 case 6 :  ret =-58;  break;//32apsk
	 case 7 :  ret =-58;  break;//32apsk-s
	 case 8 :  ret =-55;  break;//64qam
	 case 9 :  ret =-52;  break;//128qam
	 case 10 :  ret =-49; break;//256qam
	 default : 	 ret =-49; break;
   	}
  }
  else
  {
  	switch(power_modul)
  	{
	 case 0 :  ret =-65;  break;//qpsk
	 case 1 :  ret =-61;  break;//8psk
	 case 2 :  ret =-61;  break;//8afpk
	 case 3 :  ret =-58;  break;//16qam
	 case 4 :  ret =-58;  break;//16apsk
	 case 5 :  ret =-55;  break;//32qam
	 case 6 :  ret =-55;  break;//32apsk
	 case 7 :  ret =-55;  break;//32apsk-s
	 case 8 :  ret =-52;  break;//64qam
 	 case 9 :  ret =-49;  break;//128qam
   //	 case 9 :  ret =-47;  break;//128qam
	 case 10 :  ret =-46; break;//256qam
	 default : 	 ret =-46; break;
   	}
  }

  return ret;//PM_MIN_LEVEL;
}


#define DELTA_INP_LEVEL	  1


extern "C" void  OperatePower1(void)
{
signed long cur_min_level;// =  GetMinLevel();

//#ifdef DEBUG_POWER
//   printfp("40 ");
//#endif


  if(!GetModForSS1()) return;

//#ifdef DEBUG_POWER
//   printfp(" 41");
//#endif

   cur_min_level =  GetMinLevel();

static unsigned long timescan1;

 if(timescan1 > time1)	timescan1 = time1;

if((time1 - timescan1) > SEND_STATUS_PERIOD)
 {

#ifdef DEBUG_POWER
   printfp("42 ");
#endif


  timescan1 = time1;
 //   printEthLongHex(9);

 //  printEthLongHex((farinplev1 << 24) +  cur_min_level);
  if(unStateRRL.stateRRL.ppu1_bytes[1]  > GetMaxPower())
  {
 // printEthLongHex(3);
  NormalizePower(1);
#ifdef DEBUG_POWER
   printfp("\n\r2\n\r");
#endif

  return;
  }
//hier are true both operations!!!!!!!
//   printEthLongHex(farinplev1);
 //  printEthLongHex(cur_min_level);

  if((unsigned long)farinplev1 == (unsigned long)NO_LOCK_LEVEL ) 
  { 
  IncrementPower(1);// printEthLongHex(0x77);
#ifdef DEBUG_POWER
   printfp("\n\r1\n\r");
#endif
  }
  else
  {

 #ifdef DEBUG_POWER
   printfp("\n\r30\n\r");
#endif


 //   printEthLongHex(0x33);
  if(((float)farinplev1) <= ((float)cur_min_level - (float)DELTA_INP_LEVEL)) 
  {
 #ifdef DEBUG_POWER
   printfp("\n\r31 - incremert\n\r");
    printfpd(" cur_min_level: %d", cur_min_level);
   printfpd(" farinplev1: %d", farinplev1);

#endif
  
  IncrementPower(1);
  return;
//  printEthLongHex(0x34);
  }
//  if((farinplev1) > (cur_min_level + (signed long)DELTA_INP_LEVEL)){
//  else
//  {
  if((float)(farinplev1) >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))
  {
//  printEthLongHex(0x35); 
#ifdef DEBUG_POWER
   printfp("\n\r3 decrement\n\r");
   printfpd(" cur_min_level: %d", cur_min_level);
   printfpd(" farinplev1: %d", farinplev1);
#endif

  DecrementPower(1);
  return;
  } 
//  else
//  {
 #ifdef DEBUG_POWER
   printfp("60: no change");
   printfpd(" cur_min_level : %d", cur_min_level);
   printfpd(" farinplevel: %d", farinplev1);

#endif

//  }
 // }
 /*
  if((unsigned)(farinplev1*(-1)) < (unsigned)(cur_min_level)*(-1)) {IncrementPower(1);   }
  if((unsigned)(farinplev1*(-1)) > (unsigned)((-1)*(cur_min_level + (signed long)DELTA_INP_LEVEL))){ DecrementPower(1); }
  */
//  else if(farinplev1 > (cur_min_level + DELTA_INP_LEVEL)){ DecrementPower(1); }
  /*
   else if (!flag_enable_operate_power1)
  {
	DisableOperatePower(1);
	flag_enable_operate_power1 =1;
	try_counter1 = 0;
  }
  	*/
	}
 }
}

extern "C" void  OperatePower2(void)
{
signed long cur_min_level;// =  GetMinLevel();
  if(!GetModForSS1()) return;
  cur_min_level =  GetMinLevel();
static unsigned long timescan1;

 if(timescan1 > time1)	timescan1 = time1;

if((time1 - timescan1) > SEND_STATUS_PERIOD)
 {
  timescan1 = time1;

 //  printEthLongHex((farinplev1 << 24) + (farinplev2<<16) + cur_min_level);
   if(unStateRRL.stateRRL.ppu2_bytes[1]  > GetMaxPower())
  {
  NormalizePower(2);
  return;
  }
   if((unsigned long)farinplev2 == (unsigned long)NO_LOCK_LEVEL ) 
  { 
  IncrementPower(2);// printEthLongHex(0x77);
  return;
  }
  else
  {

  if((float)farinplev2 <= ((float)cur_min_level - (float)DELTA_INP_LEVEL)) 
  {
   IncrementPower(2);
   return;
  }
 // if(farinplev2 > cur_min_level + (signed long)DELTA_INP_LEVEL) DecrementPower(2);
  if((float)farinplev2 >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))
   {
   DecrementPower(2); 
   return;
   }
  }
   	  /*
  else if (!flag_enable_operate_power2)
  {
	DisableOperatePower(2);
	flag_enable_operate_power2 = 1;
	try_counter2 = 0;
  }
	 */
  }

 timescan = time1;

}



#endif



extern "C" void BMDN()
 {

// return; //150224

//#ifndef TEMPORARY_DO_NOT_STOP_RECEIVE

 
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

//#endif

 UpdateDataVal();  //to redraw menu for monitoring
  

//irq0_limit = IRQ0_LIMIT;
//UnMaskIrq0();
// my_int_enable_irq0();

//#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
// if(deviceindex == 0) return 1; //for test
// if(deviceindex == 0) return 1; //for test
 //  return;
//#endif //MAKET_PLATA

//  return;
  Check_restart();

#ifdef O_POWER
signed short cur_min_level =  GetMinLevel();


if((modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode == 1) && GetModForSS1())	//one modulation
{

if(flag_enable_operate_power1)
{
  if(((float)farinplev1 <= ((float)cur_min_level - (float)DELTA_INP_LEVEL)) || ((float)farinplev1 >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))) 
  {
   EnableOperatePower(1);
   flag_enable_operate_power1 = 0;
   try_counter1 = 0;
  //  printEthLongHex(1);

#ifdef DEBUG_POWER
   printfp("\n\r22\n\r");
 //  printfpd(" -> %d",modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode);
#endif

  }
  else
  {
#ifdef DEBUG_POWER
   printfp("\n\r20\n\r");
 //  printfpd(" -> %d",modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode);
#endif
  
  
  }


}
else
{
  OperatePower1();
  //printEthLongHex(2);
//  #ifdef DEBUG_POWER
//   printfp("\n\r21\n\r");
 //  printfpd(" -> %d",modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode);
//#endif


}

if(flag_enable_operate_power2)
{
  if(((float)farinplev2 <= ((float)cur_min_level - (float)DELTA_INP_LEVEL)) || ((float)farinplev2 >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))) 
  {
  EnableOperatePower(2);
  flag_enable_operate_power2 = 0;
  try_counter2 = 0;
  }
}
else
{
  OperatePower2();
}
}
else
{
#ifdef DEBUG_POWER
   printfp("\n\r4\n\r");
   printfpd(" -> %d",modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode);
#endif

}

#endif

//__________________________________________________________________
//131227#ifndef PROG_MD310
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

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
#endif
#endif

   if(GetNeedWriteDevId())
		   {
	 //  	 printf("\n\r Write!!");
	 //t
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }




#ifdef SEND_MOD_LOCK
static unsigned long periodcnt1;
 periodcnt1++;

if (periodcnt1 > 20)
{
 periodcnt1 = 0;
  if(uerrsn15503work.errsn15303work.lock1 &  MASK_BIT_0)
  {
//hier send to 485 0x71
   ToPdcTu1(LOCK_CHAR);
  }
  else
  {
   ToPdcTu1(UNLOCK_CHAR);

//send some enover
  }
}

#endif

//okreturn; //t

#ifdef PROG_MD310_SAT
 
 

if(SetACMCounter == (unsigned long)LOAD_ACM_DELAY)
{
 OperateACM();
  SetACMCounter++;

}
else
{
 if(SetACMCounter < (unsigned long)LOAD_ACM_DELAY)
  {
  SetACMCounter++;
  }
}
#endif	


//ok return; //t141103


static unsigned long periodcnt;
 periodcnt++;
 if(periodcnt > 1000)
// if(periodcnt > 300)
{

  if((counter_restart_web_prog < time1) &&  flag_restart_web_prog) 
  {
  flag_restart_web_prog = 0;
  dev_restart1();
  }


  periodcnt = 0;
  CheckParseFlags();
  if(flagproti) 
  {
  flagproti++;
  }
  if(flagproti > 1)
  {
//  printfp("\n\r____set");
 // SetNeedInitAllProti(0);
  SetNeedInitAllProti2only(0);	
  flagproti = 0;
  }

 // printfpd("\n\r check: %d",check_norma_status);
// printfpd("\n\r check: %d",pvg710_error_counter);

// ConfigDataLoadm(0, MODEM_QUANTITY);
} 

//#ifdef CHECK_LOSS_MEM
 
//_int_disable();		 //this get stopping in loop!!!!
//my_int_disable_irq0();
//for(unsigned long i = 0; i < 1; i++)	//+
//{
//_int_disable();
//for(unsigned long j = 0; j <= i; j++)
//{

//ReadStateEasyD(); 	//+
//}
//ReadStateEasyD();
//ReadStateEasyD();
//_int_enable();
//embSerialACT155.AddTransitM(0x55);	
//embSerialACT155.AddModM(0x55,0);	
//OperateBuffers_usart0t(); 
//}
//_int_enable(); 		//+
//my_int_enable_irq0();
	  
//#endif

//okreturn; //t141104

 if(ReadingEnabled(1))
 {
//#ifndef PROG_BMDN4
//  ReadStateEasy();  //110131
//#else
//160316 for test  ReadStateEasyD();  //110131  older bmdn4
//#endif


 }

//okreturn;	  //t141104

  ScanErrors();	//110725 //read errors on roulette prinzip
//badreturn; //141104

//#ifndef PROG_BMDN4
// if(protection_mode == MODE_N_PLUS_1)
// if((protection_mode == MODE_N_PLUS_1) && (ModemIsUsed(currentrezerv)))
// {
//  OperateRezerv1(); //compare noises to treshholds and set modems to rezerv
//t110214  ParseRequestsRezervResponses();
// }
//#endif
//bad!!!!return;

//not return; //t141104

  PeriodicControl();	//110131

  UpdateACMCounters();

//131227#ifndef PROG_MD310
/*
#ifdef PROG_BMDN6	//131227
#ifndef PROG_BMDN6MI

//_____________________________PHONE

	if((time1 - wait_time) >=40) 
	{
		wait_time = time1;
		Read();
		
		if(aaa[3]&0x40) 
		{
 // if(GetTestMode() == 0x50)
  //{
  // printfp("\n\r aaa[3] =");
  // printfpd(" %02X",aaa[3]);
  //}
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

//printfp("\n\r presto");
//printfpd(" %02X",presto_ring);
//printfpd(" %02X",ring_counter);
//printfpd(" %ld",presto_time);
//printfpd(" %ld",time1);


  				if((!presto_ring)&&(time1-presto_time > 2000))
	  //			if((!presto_ring)&&(time1-presto_time > 4000))
				{
//printfp("\n\r !presto_ring");
//printfpd(" %02X",presto_ring);
//printfpd(" %02X",ring_counter);

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
					if(time1-presto_time < 1400) 
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

//__________________________________________________PHONE
#endif
#endif
	*/
	/*
#ifndef PROG_BMDN6MI

#include "updown.cpp"
#endif

		old_ready_transit=ready_transit;
for(i =0; i < MODEM_QUANTITY;i++)
{
		old_ready_mod[i]=ready_mod[i];
}

 	ProtocolFromModACT155();
 	ProtocolFromTransitACT155();

*/
//160614   	R_ACM(); //ioperateradian acm



//if((timeChannels < time1) || (timeChannels > (time1 + CHANNELLS_TIME_STEP)))
//{
//  timeChannels = time1 + CHANNELLS_TIME_STEP;

//   	   	ProtocolFromModACT155();
// 	   	ProtocolFromTransitACT155();
 //		Check2InitTransitMod();
//		 #include bmdn4_rem.c //100110
//}
//#include bmdn4_rem.c //100110


//ok return; //t141031

#include md310s2_rem.c //100110


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

     timer++;

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
//wd_reset(); //121115
//printfp("_I0");
#ifdef IncEmbSerialMD34AVT

//hrstutauua
//printfp("_I");
  embSerialACT155.IsrXX();
#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
 //t my_int_enable_irq0();
#ifdef IRQ_LIMITED
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 //if(1)
 {
   InterruptWatchDog++;
#endif
   my_int_enable_irq0();
  //  _int_enable();

#ifdef IRQ_LIMITED
 }
#endif

}

//_____________________________________________________________________________
#ifndef PROG_BMDN6MI

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
for(i=0; i<15; i++) outportb(0x11, 0x08);
outportb(0x11, 0x00);
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
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x0F, ab1[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x0F, ab2[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x0F, ab3[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x0F, ab4[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x0F, ab5[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x0F, ab6[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x0F, ab7[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x0F, ab8[i]); outportb(0x10, 0x01);for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
t2ms(1);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x0F, ab9[i]); outportb(0x10, 0x01);for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x0F, ab10[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x0F, ab11[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x0F, ab12[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x0F, ab13[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x0F, ab14[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x0F, ab15[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x0F, ab16[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x0F, ab17[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x0F, ab18[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x0F, ab19[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x0F, ab20[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);

outportb(0x10, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x0F, ab21[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);


	outportb(0x10, 0x02); for(i=0; i<sizeof(a14); i++) outportb(0x0F, a14[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a15); i++) outportb(0x0F, a15[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a16); i++) outportb(0x0F, a16[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a17); i++) outportb(0x0F, a17[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a18); i++) outportb(0x0F, a18[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a19); i++) outportb(0x0F, a19[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a20); i++) outportb(0x0F, a20[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a21); i++) outportb(0x0F, a21[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);

outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);
outportb(0x10, 0x02); for(i=0; i<sizeof(a23); i++) outportb(0x0F, a23[i]); outportb(0x10, 0x01); for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);


outportb(0x11, 0x04); // 0);


outportb(0x11, 0x04); // r(i=0; i<sizeof(a26); i++) outportb(0x0F, a26[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x10) & 0x01)!=0);




//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

	
/*
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01);// f f(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01);// for(i=0; i<100; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outport00; i++);
while((inportb(0x510) & 0x01)!=0);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outport
//t2ms(1000);
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

   */


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
         
	
outportb(0x10, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x0F, ac[i]); outportb(0x10, 0x01); for(i=0; i<1000; i++);
 
// while((inportb(0x10) & 0x01)!=0);
 while((inportb(0x10) & 0x01)!=0)
 {
  printfpd(" %X", inportb(0x10));
  OperateBuffers_usart0t();
 }

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

//printfp("\r\n");
//printfpd(" 1:%02X",aa1);
//printfpd(" 2:%02X",aa2);
//printfpd(" 3:%02X",aa3);


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

// printf("\r %d %d %d %d %d = %c \r\n", aa1, aa2, aa3, aa_loc, aa_loc, code);
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

#endif // no PROG_BMDN6M

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

   outport(0x06,0x55); // разрешаем прерывания на прием
// outport(0x506,0xff);
}
//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);

//while(1)



 unsigned char  rm[MODEM_QUANTITY], rmo[MODEM_QUANTITY], rtz,rtzo, tm[MODEM_QUANTITY], ttz, tup0, tup1;     
  unsigned int   merc[MODEM_QUANTITY], zerc,up0erc,up1erc;
  unsigned char rup0, rup0o,  rup1, rup1o;
  unsigned long rmc[MODEM_QUANTITY], tmc[MODEM_QUANTITY], rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;
 unsigned long PeriodCounter;

void test_PU37()
{
  /*	
 static unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1,   i;     
 static unsigned int   merc, zerc,up0erc,up1erc;
 static unsigned char rup0, rup0o,  rup1, rup1o;
 static unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;
  */
	
  static unsigned char    i;


#ifdef IRQ_LIMITED 
 if(time_irq < time1)
 { /* Body */

  time_irq =   time1 + LIMIT_IRQ_PERIOD;
  /*
  printEthLongHex(InterruptWatchDog);
    InterruptWatchDog = 0;   //for test
     */
//#ifndef PROG_TUTS   
    //  printEthLongHex(InterruptWatchDog);

 //if(InterruptWatchDog == INTERRUPT_WAIT)
// if(InterruptWatchDog >= INTERRUPT_WAIT)    //100813
// { 
#ifndef WITHOUT_INTERRUPTS
//100813 error!!!   EnableInterrupts();

 // printEthLongHex(InterruptWatchDog);
 //  printfpd(">>%d <<", InterruptWatchDog);
//_______________________________________________100813_
//   if (IntFlag)
 //  {  
     my_int_enable_irq0(); 
 //  IntFlag = 0; 
 //  }
   InterruptWatchDog = 0;

//________________________________________________100813
#endif //WITHOUT_INTERRUPTS   
 //  SetBufferState((unsigned long)INTERRUPT_OVERFLOW);
// }
// else
// {
//   InterruptWatchDog = 0;
// }
//#endif //no PROG_TUTS  
}

#endif  //IRQ_LIMITED 


// static int PeriodCounter = 0l;
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
//  if(PeriodCounter > 1000l)
//if(PeriodCounter >5l)
if(PeriodCounter >10l)

//if(PeriodCounter >50l)

//#ifndef FULL_TEST_TRANZIT
// if(PeriodCounter > TEST_PERIOD)

//if(PeriodCounter > 10000l) //t
//#else
//if(1)	//110822
//#endif// FULL_TEST_TRANZIT
  {

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



//printf(".");
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
//  for(i = 0; i< MODEM_QUANTITY;i++)
 // {
  	 if((embSerialACT155.UsedSendUD1(0) < 5)) 
			     {
				embSerialACT155.AddUD1(tup0++, 0);
			    embSerialACT155.AddUD1(tup0++, 0);
			    embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.SetMaskTransUD1(0);

			   //		   outportb(0x50B, tup0++);
				tup0c += 5;   
	 //		#endif								   
				 } 
			   

 	if((embSerialACT155.UsedSendUD2(0) < 5)) 
			     {
				embSerialACT155.AddUD2(tup1++, 0);
			    embSerialACT155.AddUD2(tup1++, 0);
			    embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.SetMaskTransUD2(0);

			   //		   outportb(0x50B, tup0++);
				tup1c += 5;   
	 //		#endif								   
				 } 
			   
				 





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

 					//	 {

//#ifdef FULL_TEST_TRANZIT
  
  for(long itr = 0; itr< MODEM_QUANTITY;itr++)
  {
     if(embSerialACT155.UsedSendMod(itr) < 5)
		  // 	if(!embSerialACT155.UsedSendMod()) 
				  {

		   embSerialACT155.AddMod(tm[itr]++, itr );
				      embSerialACT155.AddMod(tm[itr]++, itr);
					     embSerialACT155.AddMod(tm[itr]++, itr);
						    embSerialACT155.AddMod(tm[itr]++, itr);
							   embSerialACT155.AddModM(tm[itr]++, itr);
					
		  		   tmc[itr] += 5;
				   }
		  		  
   }

	

			  //	  while
		  	//  if(embSerialACT155.UsedSendTransit() < 5)

//			   if (inportb(0x8) & 0x20)
		   	  if(!embSerialACT155.UsedSendTransit()) 
			     {
			   	   embSerialACT155.AddTransitM(ttz++);
				 // if(ttz == 0xff) 
			   //ok	  ttz &= 0x20;
				//ok  ttz &= 0x60;
			  //ok	  ttz &= 0xE0;
			  //ok	  ttz &= 0xF0;
			  //ok	  ttz &= 0xF8;
			  //ok	  ttz &= 0xFC;
			   //	  ttz &= 0xFE;
			  //	  ttz |= 0x01;
			  //bad	  ttz &= 0xFF;
	   		 //  	   ttzc++;
		   //		     embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  			 //		embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  			   //		embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
  				 //	embSerialACT155.AddTransit(ttz++);
	   		  	   ttzc++;
			 // ttzc += 5;
  	   //		 printf("\n\r ttzc : %d", ttzc);
			    }
 
} //PeriodCounter

  for(i = 0; i< MODEM_QUANTITY;i++)
  {
 
  if( embSerialACT155.m_RBuffMod[i].Used()) 
	{
	rm[i]=embSerialACT155.m_RBuffMod[i].Get();
					rmc[i]++;
		  	 //  printf("MOD : rmo %d  rm: %d  \n\r", rmo, rm);

					if (rmo[i]!=rm[i])
							{		
							 //		tchar =   inportb(0x508);
							   //		tchar =   inportb(0x508);	
									if (merc[i] <0xfffe) merc[i]++;
								 //   printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
									//508
									
							}
					rm[i]++;
					rmo[i]=rm[i];

  }
}
  
  //	if(irq.bit.IRQ_RX_trans)// m_RBuffTransit.Add(inportb(0x509)); 
   if( embSerialACT155.m_RBuffTransit.Used()) 
 {	
  rtz=embSerialACT155.m_RBuffTransit.Get();
					rtzc++;
					if (rtzo!=rtz)
							{
						//		printfp("\n\r waiting :");
						 //		printfpd(" %02X",rtzo);
						 //	    printfp("have :");
						 //		printfpd(" %02X",rtz);

									if (zerc <0xfffe) 	zerc++;
							}
				rtz++;
			   //	if(rtz == 0xFF)
			  //ok	 rtz &= 0x20;
			  //ok	 rtz &= 0x60;
			  //ok	 rtz &= 0xE0;
			  //ok 	 rtz &= 0xF0;
			  //ok 	 rtz &= 0xF8;
			 //ok  	 rtz &= 0xFC;
			//   	 rtz &= 0xFE;
			//	  rtz |= 0x01;
			 //  	 rtz &= 0xFF;

				rtzo=rtz;
}


   //	if(irq.bit.IRQ_RX_UD1)// m_RBuffUD1.Add(inportb(0x50B)); 
			   

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

for(long ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tup0c>10000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
// 	   printf("Mod:%d Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send UP1 -- %d  RX-- %d  ERR-- %d\n\r",ip, tup0c, rup0c, up0erc);
#else
 // printfp("\n\rMOD --"); 
//  printfpd("%d",ip);
  printfp("\n\rSend UP1 --"); 
  printfpd("%d",tup0c);
  printfp(" RX--"); 
  printfpd("%d",rup0c);
  printfp(" ERR--"); 
  printfpd("%d",up0erc);
OperateBuffers_usart0t();
#endif

			tup0c=0; rup0c=0; up0erc=0;
		}
	
 }

for(ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tup1c>10000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
// 	   printf("Mod:%d Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send UP2 -- %d  RX-- %d  ERR-- %d\n\r",ip, tup1c, rup1c, up1erc);
#else
//  printfp("\n\rMOD --"); 
//  printfpd("%d",ip);
  printfp("\n\rSend UP2 --"); 
  printfpd("%d",tup1c);
  printfp(" RX--"); 
  printfpd("%d",rup1c);
  printfp(" ERR--"); 
  printfpd("%d",up1erc);
OperateBuffers_usart0t();
#endif

			tup1c=0; rup1c=0; up1erc=0;
		}
	
 }






	if (ttzc>10000)
		{

	   //		ScreenAddString("Send TrZ --");
	   //		ScreenAddInt(ttzc);
	   //		ScreenAddString(" RX--");
	   //		ScreenAddInt(rtzc);
	   //		ScreenAddString(" ERR--");				  
	   //		ScreenAddInt(zerc);
	   //		ScreenIntSent();
//   	   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);
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
	

for(ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tmc[ip]>10000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
// 	   printf("Mod:%d Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#else
//  printfp("\n\rMOD --"); 
 // printfpd("%d",ip);
  printfp("\n\rSend MOD --"); 
  printfpd("%d",tmc[ip]);
  printfp(" RX--"); 
  printfpd("%d",rmc[ip]);
  printfp(" ERR--"); 
  printfpd("%d",merc[ip]);
OperateBuffers_usart0t();
#endif

			tmc[ip]=0;rmc[ip]=0; merc[ip]=0;
		}
	
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
//#define  SEND_CHAR_T (0x55)
//#define  SEND_CHAR_T (0xAA)
#define  SEND_CHAR_T (0xC3)

unsigned char irq_byte, irqm_byte;

void test_PU37_transit()
{

   static unsigned long periodtimer;

	 /*
 static unsigned char  rm, rmo, rtz,rtzo, tm, ttz, tup0, tup1,   i;     
 static unsigned int   merc, zerc,up0erc,up1erc;
 static unsigned char rup0, rup0o,  rup1, rup1o;
 static unsigned long rmc, tmc, rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;

	*/
  static unsigned char    i;

// static int PeriodCounter = 0l;
// unsigned char tchar;
 static unsigned char bstate, bstateold;
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
//  if(PeriodCounter > 1000l)
//if(PeriodCounter >5l)
//if(PeriodCounter >10l)
if(PeriodCounter >30l)

//#ifndef FULL_TEST_TRANZIT
// if(PeriodCounter > TEST_PERIOD)

//if(PeriodCounter > 10000l) //t
//#else
//if(1)	//110822
//#endif// FULL_TEST_TRANZIT
  {

//printf(".");
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
 
 //bstate =  inportb();
 

if((time1 - periodtimer) > 100)
{
periodtimer = time1;
 bstate =  inportb(PROV_TANZIT_STATUS);
  outportb(PROV_TANZIT_STATUS, 0);
 printfp("\n\r s:");
 printfpd(" %02X",bstate);
 bstateold = bstate;
// irq_byte, irqm_byte;
 printfpd(" %02X",irq_byte);
 printfpd(" %02X",irqm_byte);
 }
    
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x508) & 0x20)
					//	 {

//#ifdef FULL_TEST_TRANZIT

 					//	 {

//#ifdef FULL_TEST_TRANZIT
   /* only transit
  for(long itr = 0; itr< MODEM_QUANTITY;itr++)
  {
     if(embSerialACT155.UsedSendMod(itr) < 5)
		  // 	if(!embSerialACT155.UsedSendMod()) 
				  {

		   embSerialACT155.AddMod(tm[itr]++, itr );
				      embSerialACT155.AddMod(tm[itr]++, itr);
					     embSerialACT155.AddMod(tm[itr]++, itr);
						    embSerialACT155.AddMod(tm[itr]++, itr);
							   embSerialACT155.AddMod(tm[itr]++, itr);
					
		  		   tmc[itr] += 5;
				   }
		  		  
   }
	*/
			  //	  while
		  	  if(embSerialACT155.UsedSendTransit() < 5)
		   //	  if(!embSerialACT155.UsedSendTransit()) 
			     {
			   	  /*	
				  embSerialACT155.AddTransit(SEND_CHAR_T);
			  embSerialACT155.AddTransit(SEND_CHAR_T);
			  embSerialACT155.AddTransit(SEND_CHAR_T);
			  embSerialACT155.AddTransit(SEND_CHAR_T);
			  embSerialACT155.AddTransit(SEND_CHAR_T);
			  	  	*/
				   
			   	   embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
			 	     embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  			  		embSerialACT155.AddTransit(ttz++);
	   		//   	   ttzc++;
  			 		embSerialACT155.AddTransit(ttz++);
	   		 //  	   ttzc++;
  			 		embSerialACT155.AddTransitM(ttz++);
					   
	   	  //	   	   ttzc++;
		  	  ttzc += 5;
  	   //		 printf("\n\r ttzc : %d", ttzc);
			    }
 
} //PeriodCounter

  for(i = 0; i< MODEM_QUANTITY;i++)
  {
 
  if( embSerialACT155.m_RBuffMod[i].Used()) 
	{
	rm[i]=embSerialACT155.m_RBuffMod[i].Get();
					rmc[i]++;
		  	 //  printf("MOD : rmo %d  rm: %d  \n\r", rmo, rm);

					if (rmo[i]!=rm[i])
							{		
							 //		tchar =   inportb(0x508);
							   //		tchar =   inportb(0x508);	
									if (merc[i] <0xfffe) merc[i]++;
								 //   printf("MOD : rmo: %d  rm: %d  tchar: 0x%02x \n\r", rmo, rm, tchar);
									//508
									
							}
					rm[i]++;
					rmo[i]=rm[i];

  }
}
  
  //	if(irq.bit.IRQ_RX_trans)// m_RBuffTransit.Add(inportb(0x509)); 
   if( embSerialACT155.m_RBuffTransit.Used()) 
 {	
  rtz=embSerialACT155.m_RBuffTransit.Get();
					rtzc++;
			   	  	if (rtzo!=rtz)
				 	 	 //		if (rtz!=SEND_CHAR_T)
							{
							/*
								printfp("\n\r waiting :");
								printfpd(" %02X",rtzo);
							    printfp("have :");
								printfpd(" %02X",rtz);
								   */
									if (zerc <0xfffe) 	zerc++;
							}
				rtz++;
				rtzo=rtz;
}


   //	if(irq.bit.IRQ_RX_UD1)// m_RBuffUD1.Add(inportb(0x50B)); 
			   

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
//   	   printf("Send TrZ -- %d  RX-- %d  ERR-- %d\n\r", ttzc, rtzc, zerc);
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
	

for(long ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tmc[ip]>20000)
		{

		 //	ScreenAddString("Send MOD --");
		 //	ScreenAddInt(tmc);
		 //	ScreenAddString(" RX--");
		 //	ScreenAddInt(rmc);
		 //	ScreenAddString(" ERR--");
		 //	ScreenAddInt(merc);
		 //	ScreenIntSent();
// 	   printf("Mod:%d Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#else
  printfp("\n\rMOD --"); 
  printfpd("%d",ip);
  printfp("\n\rSend MOD --"); 
  printfpd("%d",tmc[ip]);
  printfp(" RX--"); 
  printfpd("%d",rmc[ip]);
  printfp(" ERR--"); 
  printfpd("%d",merc[ip]);
OperateBuffers_usart0t();
#endif

			tmc[ip]=0;rmc[ip]=0; merc[ip]=0;
		}
	
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

//printfpd("\n\r TypeVer 0x%x", ret);
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
extern  "C" void SetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
{
  unsigned char* bt = (unsigned char *)(NVRAM_BASE);
  unEmb2TypeVer.emb2TypeVer.signature_software[1] = (unsigned char)*data_ptr;
  *(bt+1) =   (unsigned char)*data_ptr;
  //Stephany19 = (unsigned char)*data_ptr;
}


extern  "C" unsigned char *GetETHMODE(unsigned long* data_len)
{
 static unsigned char BufBER[50];

// double BER = (double)(timeres) * (double)(155520000l) / (double)(ErrResSNMP);
// sprintf(BufBER,"%LE4", BER);
 // double BER = (double)123/(double)454;
 // float BER = (float)123/(float)454;

 // float BER= 1.2e-7;	 //for test

 // unsigned BER1 = GetBER();//*pow(10,GetBERE());
 // unsigned BER2 = GetBERE();
  sprintf((char *)&BufBER[0],"%s", GetEthMode());

  // printfp("\n\rGetETHMODE :");
  // printfp(BufBER);

/*
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

*/
//t sprintf((char *)&BufBER[0],"%.1E", BER);
  *data_len = 8;
// return ((unsigned char *)&BufBER[0]);
 return (BufBER);
}
  
extern "C" char* GetTModulSNMP(unsigned long* data_len)
{
   *data_len = 8;
   return GetTModul();
}

extern "C" char* GetRModulSNMP(unsigned long* data_len)
{
   *data_len = 8;
   return GetRModul();
}


extern "C" char* GetDFESNMP(unsigned long* data_len)
{
   *data_len = 4;
   return GetDFE();
}


extern "C" long GetTSymbSNMP()
{
    return (long)(GetTSymb()* 1000000.0);

}

extern "C" long GetRSymbSNMP()
{
    return (long)(GetRSymb()* 1000000.0);

}

  
extern "C" long GetRCodeSNMP()
{
 return (long)(GetRCode()* 1000.0);
}

extern "C" long GetTCodeSNMP()
{
 return (long)(GetTCode()* 1000.0);
}

extern "C"  long Get_IFLOOP(void)
{
  return dev1.md100se.MIfLoop + 1;
}
extern "C"  void Set_IFLOOP(long val)
{
val -= 1;

   if((val != 0) && (val != 1)) return;

	  SetIfLoopSNMP(val);	
}

extern "C"  long Get_UNMODUL(void)
{
    return dev1.md100se.MUnModul + 1;
}

extern "C"  void Set_UNMODUL(long val )
{
val -= 1;

   if((val != 0) && (val != 1)) return;

    SetMUnModulSNMP(val);


}




//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long*ong*a_len)
extern  "C" unsigned char * GetBERO(unsigned long* data_len)
{
 static unsigned char BufBER[50];

// double BER = (double)(timeres) * (double)(155520000l) / (double)(ErrResSNMP);
// sprintf(BufBER,"%LE4", BER);
 // double BER = (double)123/(double)454;
 // float BER = (float)123/(float)454;

  float BER= 1.2e-7;	 //for test

  unsigned BER1 = GetBER();//*pow(10,GetBERE());
  unsigned BER2 = GetBERE();
  sprintf((char *)&BufBER[0],"%02dE-%02d", BER1,BER2);
  // printfp("\n\rGetBERO :");
  // printfp(BufBER);

/*
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

*/
//t sprintf((char *)&BufBER[0],"%.1E", BER);
  *data_len = 8;
// return ((unsigned char *)&BufBER[0]);
 return (BufBER);
}

extern "C"   unsigned long  GetEBN0(void )
{
// printfpd("\n\rGetEBN0 %d",GetMEbN0()* 10.0);

  if(GetMEbN0()> 0)
  {
 //	printfp("\n\r >0");
return (unsigned long) (GetMEbN0() * 10.0);
}
else
{
 //	printfp("\n\r <=0");

 return 0;
}

}

extern "C" long Get_MODULATOR_MODE(void)
{
	return dev1.md100se.MRfOut + 1;

}

extern "C" void Set_MODULATOR_MODE(long val)
{
	val -= 1;

   if((val != 0) && (val != 1)) return;

   SetMRfOutSNMP((unsigned char) val);
}

extern "C" long  Get_POWER(void )
{
	return GetMOutLev();

}

extern "C" long  Get_SERIAL(void )
{
  	return GetSerial();
//	return 1;

}


extern "C" void  Set_POWER(long val)
{

// printfpd("\n\r set power : %d", val);
   SetMOutLevSNMP(val);

}

extern  "C" long  Get_FreqM(void )
{
 return GetMTFreq();
}
extern "C"  void  Set_FreqM(long val)
{

//printfpd("\n\r Set_FreqM: %d", val);

  SetMTFreqSNMP(val);

}

extern "C"  long  Get_MODULATOR_TMODE(void )
{
 return  (long)GetMTMode();
;

}
extern "C"  void  Set_MODULATOR_TMODE(long val)
{
  printfpd("\n\r  Set_MODULATOR_TMODE: %d", val);


  SetMTModeSNMP(val);

}

extern "C"  long  Get_MODULATOR_CONFIG(void )
{
 return  (long)GetMCONFIG();
}
extern "C"  void  Set_MODULATOR_CONFIG(long val)
{
  printfpd("\n\r  Set_MODULATOR_CONFIG: %d", val);
  SetMCONFIGSNMP(val);
}


extern  "C" long  Get_FreqD(void )
{
 return GetMRFreq();
}


extern "C"  long  Get_ACM(void )
{
 return GetMACMMSNMP();

}
extern "C"  void  Set_ACM(long val)
{
//printfpd("\n\r Set_ACM: %d", val);
  SetMACMMSNMP(val);
}
   /*
extern  "C"  long Get_MODULATOR_ACM_REQ(void)
{
 return 0;
}
extern  "C" void  Set_MODULATOR_ACM_REQ(long)
{

}

extern  "C" long Get_DEMODULATOR_ACM_MODE(void)
{
 return 0;
}
extern "C"  void  Set_DEMODULATOR_ACM_MODE(long)
{

}


extern  "C"  long Get_DEMODULATOR_ACM_OFFSET(void)
{
 return 0;
}

extern  "C"  void  Set_DEMODULATOR_ACM_OFFSET(long)
{

}


 */




extern "C"  void  Set_FreqD(long val)
{
//printfpd("\n\r Set_FreqM: %d", val);
  SetMRFreqSNMP(val);
}

extern "C"  long  Get_DEMODULATOR_TMODE(void )
{
 return  (long)GetMRMode();
}

extern "C"  void  Set_DEMODULATOR_TMODE(long val)
{
  printfpd("\n\r  Set_DEMODULATOR_TMODE: %d", val);
  SetMRModeSNMP(val);
}

extern "C"  long  Get_DEMODULATOR_CONFIG(void )
{
 return  (long)GetDCONFIG();
}

extern "C"  void  Set_DEMODULATOR_CONFIG(long val)
{
  printfpd("\n\r  Set_DEMODULATOR_CONFIG: %d", val);
  SetDCONFIGSNMP(val);
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





//___________________________________________________________________________________
#ifndef PROG_BMDN6MI
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
 //	printf("\r aa1=0x%X aa2=0x%X aa3=0x%X aa_loc=0x%X \r\n", aa1, aa2, aa3, aa_loc);
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

#endif //no PROG_BMDN6M

//#define MAX_RECEIVE (3)
//t #define MAX_RECEIVE (4)	   3e-4
#define MAX_RECEIVE (4)	

unsigned long count_send, count_res, count_res_ok, count_res_bad;


#define SEND_TIMEOUT (2)

#ifndef PROG_BMDN6MI
extern "C" void TestMailBoxes()
{
  AT91RM9200_PIO_REG_STRUCT_PTR pio_ptr1;
 // static char led;
  uint_32         tg = 1<<13;

//static unsigned char send_res;
unsigned char result;
unsigned char wd_cnt;
static PVG610_MAILBOX_MESSAGE_STRUCT Mbx;
result = 0;
wd_cnt =  MAX_RECEIVE;
unsigned char Buff[32] = "Hello!";
static unsigned long cur_res;
static unsigned long wait_res;
static unsigned long test_timeout = 0;



 pio_ptr1 = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;


 //  pio_ptr1->SODR = tg; //(1<<pin);


//if(!send_res)
//{
//send_res = 1;
 
while ((result != 0x12) && wd_cnt--)
{
//printf("\n\r result_hier = %d")
 result = PVG610_API_MailboxMessageReceive(0,0, &Mbx);
 //printf("...result receive= 0x%X", result);
 if(!result) 
 {
  cur_res =  (Mbx.message[0] << 24) + (Mbx.message[1] << 16) + (Mbx.message[2] << 8) + Mbx.message[3];
  if(wait_res != cur_res)
  {
#ifndef USART0_TRY_PDC_1T
   printf("\n\r cur_res = %d , wait_res = %d", cur_res, wait_res);
#endif
   wait_res = cur_res;
   count_res_bad++;
  }
  else
  {
   count_res_ok++;
  }
   wait_res++;
   receivedboxes++;
 }
}
/*
result = ModemMailboxMessageSend(32 , &Buff[0]);
 // printf("...result send = 0x%X", result);

  // printf("...result send = 0x%X", result);

 if(!result)
 {
   sendboxes++;
 }

*/

while ((result != 0x12) && wd_cnt--)
{
//printf("\n\r result_hier = %d")
 result = PVG610_API_MailboxMessageReceive(0,0, &Mbx);
 //printf("...result receive= 0x%X", result);
 if(!result) 
 {
  cur_res =  (Mbx.message[0] << 24) + (Mbx.message[1] << 16) + (Mbx.message[2] << 8) + Mbx.message[3];
  if(wait_res != cur_res)
  {
#ifndef USART0_TRY_PDC_1T
   printf("\n\r cur_res = %d , wait_res = %d", cur_res, wait_res);
#endif
   wait_res = cur_res;
   count_res_bad++;
  }
  else
  {
   count_res_ok++;
  }
   wait_res++;
   receivedboxes++;
 }
}


//}
//else
//{
//send_res = 0;
//if(cur_res ==  (count_send - 1))
if(0)
{
 Buff[0] = count_send>>24;
Buff[1] = count_send>>16;
Buff[2] = count_send>>8;
Buff[3] = count_send;


result = ModemMailboxMessageSend(32 , &Buff[0]);
 // printf("...result send = 0x%X", result);


  // printf("...result send = 0x%X", result);

 if(!result)
 {
   count_send++;
   sendboxes++;
 }



}
else if((timer - test_timeout) > SEND_TIMEOUT) 
{

//printf("\n\r timeout! send : %d res : %d", count_send, cur_res);
Buff[0] = count_send>>24;
Buff[1] = count_send>>16;
Buff[2] = count_send>>8;
Buff[3] = count_send;


result = ModemMailboxMessageSend(32 , &Buff[0]);
 // printf("...result send = 0x%X", result);


  // printf("...result send = 0x%X", result);

 if(!result)
 {
   count_send++;
   sendboxes++;
 }
 test_timeout = timer;
}



//}
//____________________________________________________


//____________________________________________________




//}

 
//if(ModemMailboxMessageReceive() != NULL)
//{
//receivedboxes++;
//}
// if(!(sendboxes % 100))
// {
//100528  printf("\n\rs: %d:  r%d", sendboxes, receivedboxes);
//100528  printf("ok: %d bad: %d", count_res_ok,count_res_bad);

// }

 //  pio_ptr1->CODR = tg; //(1<<pin);

} 

#endif

extern "C" unsigned char WriteReadSpiBm(unsigned char deviceindex, unsigned long length_of_data,
 unsigned char * BufferData, unsigned char * ReadBuffer)
{
 unsigned char ret = 0;
//unsigned long do_not_hangt = 0xfffffl;
unsigned long do_not_hangt = 0xfffl; //101221
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr,form_addrs ,form_addre, form_addrf, form_addrd;
//unsigned char readtmp;



form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);
form_addre = BLOCK_SWEEP1 * ((deviceindex- TEST_OFFSET)+1);
form_addrf = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrd = BLOCK_SWEEP1 * ((deviceindex- XIL_FLASH_OFFSET)+1);



switch(deviceindex)
{
 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_A; break;
 case 1: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status =   form_addr + ADDR_STATUS1; addr_data =form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status =    form_addr + ADDR_STATUS1; addr_data =form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16: addr_status =   form_addr + ADDR_STATUS1; addr_data = form_addr+  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 17: addr_status =   form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = 	form_addrs + ADDR_STATUS1; addr_data = form_addrs +  SPI_PORT_ADDR; addr_type =  form_addrs + SPI_ADR; addr_send = form_addrs + SPI_SEND_ADDR;type_channel = CHANNEL_C; break;
//______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ flash :
 case 27: 
 case 28: 
 case 29: 
 case 30: 
 case 31: 
 case 32: 
 case 33: 
 case 34:
 case 35: addr_status =     form_addrd + ADDR_STATUS1; addr_data = form_addrd +  SPI_PORT_ADDR; addr_type =   form_addrd + SPI_ADR; addr_send =   form_addrd + SPI_SEND_ADDR;type_channel = CHANNEL_D;   break;  //rom for xilinx
 case 36: 
 case 37: 
 case 38: 
 case 39: 
 case 40: 
 case 41: 
 case 42: 
 case 43:
 case 44: addr_status =     form_addre + ADDR_STATUS1; addr_data = form_addre +  SPI_PORT_ADDR; addr_type =   form_addre + SPI_ADR; addr_send =   form_addre + SPI_SEND_ADDR;type_channel = CHANNEL_E;   break; //test channells
 case 45: addr_status =     form_addrf + ADDR_STATUS1; addr_data = form_addrf +  SPI_PORT_ADDR; addr_type =   form_addrf + SPI_ADR; addr_send =   form_addrf + SPI_SEND_ADDR;type_channel = CHANNEL_C;   break; //test channells
 case 46: addr_status =     form_addrf + ADDR_STATUS1; addr_data = form_addrf +  SPI_PORT_ADDR; addr_type =   form_addrf + SPI_ADR; addr_send =   form_addrf + SPI_SEND_ADDR;type_channel = CHANNEL_D;   break; //test channells
 case 47: addr_status =     form_addrf + ADDR_STATUS1; addr_data = form_addrf +  SPI_PORT_ADDR; addr_type =   form_addrf + SPI_ADR; addr_send =   form_addrf + SPI_SEND_ADDR;type_channel = CHANNEL_710A;   break; //
 case 48: addr_status =     0x29; addr_data = 0x28; addr_type =  0x2A;  addr_send =   0x2B; type_channel = 0x0C;   break; //hier is IF plata  for md100se
 


 default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
}

//if(deviceindex == 43)
//{
//  printf("\n\r addr status = %X data = %X",addr_status, * BufferData);

//}

 //ok return 0; //t121003

if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;


//printfpd("\n\r as: %d", addr_send);		 //43 = 0x2b
//ok return 0; 
write_xil_char(addr_send, SEND_ALL);	//hier hangt!!!!!
//delay_mcs(1000);
//printf("\n\rwrite  deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

//no return 0; //t121003


write_xil_char(addr_type , type_channel);
//delay_mcs(1000);
//printfpd("\n\r %02X", addr_type);
//printfpd("  %02X", type_channel);


write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);
//printfpd("\n\r %02X", addr_status);
//printfpd("  %02X", RESET_BIT);


lentmp = length_of_data;
BufferDataTmp =  BufferData;

//no return; //t121023

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
//printfpd("\n\r %02X", addr_data);
// printfpd("  %02X",* BufferDataTmp);
 write_xil_char(addr_data, * BufferDataTmp++);
 
// delay_mcs(1000);
 

}
//__________________________________
/*
if(deviceindex == 43)
{

lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 readtmp = 	read_xil_char(addr_data);
 if (readtmp != * BufferDataTmp) printf("\n\r Error1 data : %X buff : %X",readtmp,* BufferDataTmp); 
  BufferDataTmp++;
   readtmp = 	read_xil_char(addr_data);
 if (readtmp != * BufferDataTmp) printf("\n\r Error2 data : %X buff : %X",readtmp,* BufferDataTmp); 

 //if (read_xil_char(addr_data) != * BufferDataTmp)printf("\n\r Errror2");
// delay_mcs(1000);
}
  
//_______________

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

write_xil_char(0x108, 0x55);
write_xil_char(0x108, 0x91);
  readtmp = 	read_xil_char(0x108);
if (readtmp != 0x55) printf("\n\r Err1 data : %X buf : 0x55",readtmp); 
  readtmp = 	read_xil_char(0x108);
if (readtmp != 0x91) printf("\n\r Err2 data : %X buf : 0x91",readtmp); 


write_xil_char(addr_status, RESET_BIT);


lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 write_xil_char(addr_data, * BufferDataTmp++);

// delay_mcs(1000);
 

}

}
 */
//___________________________________


write_xil_char(addr_status, GO_BIT);
//printfpd("\n\r %02X", addr_status);
// printfpd("  %02X", GO_BIT);

//delay_mcs(1000);
// if(deviceindex == 48)
 //printfp("\n\r");
while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
   ret = 1;
   break;
//if(deviceindex == 43)
//{
//  printf("\n\r do_not_hangt : 0x%X", do_not_hangt);
//}
// printfp(" ok!");
// return 1;
 }
  else
  {
 // if(deviceindex == 48)
 // printfpd("\r do_not_hangt : 0x%X", do_not_hangt);
 }



}
 //  if(deviceindex == 48)
  // printfp("\n\r");

lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;


//no return; //t121003 

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
// printfpd("\n\r %02X", addr_data);
// printfpd("  %02X",* BufferDataTmp);

// printf(" %02X",* BufferDataTmp);
 BufferDataTmp++;
}


//if(deviceindex == 43)
//{
//  printf("\n\r ________do_not_hangt : 0x%X", do_not_hangt);
//}
//write_xil_char(addr_type , 0);
//delay_mcs(1000);
//printfp(" bad!");

 return ret;
}





//__________________________________________________________________________________
#ifdef PROG_BMDN2
/*
extern "C" void WriteSpiTest(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{
     WriteSpiBm((deviceindex + TEST_OFFSET), length_of_data, BufferData);
}

extern "C" void WriteSpiTest1()
{
// printf("\n\r WriteSpiTest1");

   char BM[]= {0xA5,0x1};
   WriteSpiTest(7,2,BM); //7- number of modem  0...8
}
*/

extern "C" unsigned char WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{

//unsigned long do_not_hangt = 0xfffffl;
unsigned long do_not_hangt = 0xfffl; //101221
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr,form_addrs ,form_addre, form_addrf, form_addrd;
//unsigned char readtmp;

form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);
form_addre = BLOCK_SWEEP1 * ((deviceindex- TEST_OFFSET)+1);
form_addrf = BLOCK_SWEEP1 * (((deviceindex- FILTER_OFFSET)>>1)+1);
form_addrd = BLOCK_SWEEP1 * ((deviceindex- XIL_FLASH_OFFSET)+1);



switch(deviceindex)
{
 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_A; break;
 case 1: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status =   form_addr + ADDR_STATUS1; addr_data =form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status =    form_addr + ADDR_STATUS1; addr_data =form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status =    form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16: addr_status =   form_addr + ADDR_STATUS1; addr_data = form_addr+  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 17: addr_status =   form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = 	form_addrs + ADDR_STATUS1; addr_data = form_addrs +  SPI_PORT_ADDR; addr_type =  form_addrs + SPI_ADR; addr_send = form_addrs + SPI_SEND_ADDR;type_channel = CHANNEL_C; break;
//______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ flash :
 case 27: 
 case 28: 
 case 29: 
 case 30: 
 case 31: 
 case 32: 
 case 33: 
 case 34:
 case 35: addr_status =     form_addrd + ADDR_STATUS1; addr_data = form_addrd +  SPI_PORT_ADDR; addr_type =   form_addrd + SPI_ADR; addr_send =   form_addrd + SPI_SEND_ADDR;type_channel = CHANNEL_D;   break;  //rom for xilinx
 case 36: 
 case 37: 
 case 38: 
 case 39: 
 case 40: 
 case 41: 
 case 42: 
 case 43:
 case 44: addr_status =     form_addre + ADDR_STATUS1; addr_data = form_addre +  SPI_PORT_ADDR; addr_type =   form_addre + SPI_ADR; addr_send =   form_addre + SPI_SEND_ADDR;type_channel = CHANNEL_E;   break; //test channells
 case 45: addr_status =     form_addrf + ADDR_STATUS1; addr_data = form_addrf +  SPI_PORT_ADDR; addr_type =   form_addrf + SPI_ADR; addr_send =   form_addrf + SPI_SEND_ADDR;type_channel = CHANNEL_710A;   break; //test channells
 case 46: addr_status =     form_addrf + ADDR_STATUS1; addr_data = form_addrf +  SPI_PORT_ADDR; addr_type =   form_addrf + SPI_ADR; addr_send =   form_addrf + SPI_SEND_ADDR;type_channel = CHANNEL_710B;   break; //test channells



 default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
}

//if(deviceindex == 46)
//{
//  printfpd("\n\r addr status = %X ",addr_status);
//  printfpd(" data = %X",  BufferData[0]);
//   printfpd(" data = %X",  BufferData[1]);
//   printfpd(" type channel = %X ",type_channel);

//}



if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;

write_xil_char(addr_send, SEND_ALL);
//delay_mcs(1000);
//printf("\n\rwrite  deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

write_xil_char(addr_type , type_channel);
//delay_mcs(1000);

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 write_xil_char(addr_data, * BufferDataTmp++);

// delay_mcs(1000);
 

}
//__________________________________
/*
if(deviceindex == 43)
{

lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 readtmp = 	read_xil_char(addr_data);
 if (readtmp != * BufferDataTmp) printf("\n\r Error1 data : %X buff : %X",readtmp,* BufferDataTmp); 
  BufferDataTmp++;
   readtmp = 	read_xil_char(addr_data);
 if (readtmp != * BufferDataTmp) printf("\n\r Error2 data : %X buff : %X",readtmp,* BufferDataTmp); 

 //if (read_xil_char(addr_data) != * BufferDataTmp)printf("\n\r Errror2");
// delay_mcs(1000);
}
  
//_______________

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

write_xil_char(0x108, 0x55);
write_xil_char(0x108, 0x91);
  readtmp = 	read_xil_char(0x108);
if (readtmp != 0x55) printf("\n\r Err1 data : %X buf : 0x55",readtmp); 
  readtmp = 	read_xil_char(0x108);
if (readtmp != 0x91) printf("\n\r Err2 data : %X buf : 0x91",readtmp); 


write_xil_char(addr_status, RESET_BIT);


lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 write_xil_char(addr_data, * BufferDataTmp++);

// delay_mcs(1000);
 

}

}
 */
//___________________________________


write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

//printfp("\n\r");

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 //  break;
//if(deviceindex == 43)
//{
//  printf("\n\r do_not_hangt : 0x%X", do_not_hangt);
//}
// printfp(" ok!");
 return 1;
 }
 else
 {
 //if()
//  printfpd("\r do_not_hangt : 0x%X", do_not_hangt);

  }
}
// printfp("\n\r");


//if(deviceindex == 43)
//{
//  printf("\n\r ________do_not_hangt : 0x%X", do_not_hangt);
//}
//write_xil_char(addr_type , 0);
//delay_mcs(1000);
//printfp(" bad!");

 return 0;
}



//#else //
#endif //PROG_BMDN2





//#ifdef PROG_BMDN2

unsigned char * ReadSpiBm(unsigned char deviceindex, unsigned long length_of_data)
{
static unsigned char ReadBuffer[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffl;
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block


unsigned long form_addr,form_addrs ;

form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);



switch(deviceindex)
{
 case 0:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 1:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9:  addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 17: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = 	form_addrs + ADDR_STATUS1; addr_data = form_addrs +  SPI_PORT_ADDR; addr_type = form_addrs + SPI_ADR; addr_send =  form_addrs + SPI_SEND_ADDR;type_channel = CHANNEL_C; break;

 default: addr_status = 0; addr_data = 0; addr_type = 0; type_channel = 0; break;
}



//if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return NULL;

if(!length_of_data) return NULL;

if(length_of_data > MAX_SP_LEN) length_of_data = MAX_SP_LEN;


write_xil_char(addr_send, SEND_ALL);
//delay_mcs(1000);
//printf("\n\rread : deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

write_xil_char(addr_type , type_channel);
//delay_mcs(1000);

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);



//_____________________________________________________________________________________________





lentmp = length_of_data;

while(lentmp--)
{
 write_xil_char(addr_data, 0x7e);
}

write_xil_char(addr_status, GO_BIT);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT)) break;
}

//printf(" %X - %X", do_not_hangt, read_xil_char(addr_status));

lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;

#ifdef START_PRINT
//if(!deviceindex)
// printfp("\n\rans>");
#endif


while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);

#ifdef START_PRINT
//if(!deviceindex)
// printfpd(" %02X",* BufferDataTmp);
#endif
BufferDataTmp++;
}

//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}


//#endif

extern "C" unsigned char SetLoop(unsigned char loop,unsigned long milli, unsigned char nearend, unsigned char trib)
{
 PVG610_LOOPBACK_STRUCT lbs;
 unsigned char ret;

 lbs.loopbackType = loop; //PVG610_LOOPBACK_MODEM_E;
 lbs.durationMilli0 = milli>>24; //0;
 lbs.durationMilli0 = milli>>16; //0;
 lbs.durationMilli0 = milli>>8; //0;
 lbs.durationMilli0 = milli; //0;
 lbs.nearEnd = nearend;
 lbs.tributary = trib; //0;	 //	 //modem loopback

 ret = PVG610_API_LoopbackSet(15,0, &lbs);
// printf("\n\r Set Loop : %d result : %d", loop, ret);
// printf("\n\r loop : %d milli : %d nearend : %d", loop, ret, nearend);


 return ret;
}

extern "C" unsigned char SetLoopi(unsigned char dev, unsigned char loop,unsigned long milli, unsigned char nearend, unsigned char trib)
{
 PVG610_LOOPBACK_STRUCT lbs;
 unsigned char ret;

 lbs.loopbackType = loop; //PVG610_LOOPBACK_MODEM_E;
 lbs.durationMilli0 = milli>>24; //0;
 lbs.durationMilli0 = milli>>16; //0;
 lbs.durationMilli0 = milli>>8; //0;
 lbs.durationMilli0 = milli; //0;
 lbs.nearEnd = nearend;
 lbs.tributary = trib; //0;	 //	 //modem loopback

 ret = PVG610_API_LoopbackSet(dev,0, &lbs);
// printfpd("\n\r Set Loop : %d ", loop);		
//  printfpd("milli: %d ", milli);
 // printfpd("nearend: %d ", nearend);
  // printfpd("trib: %d ",trib);
  delay_mcs(100000l);


 // printf("\n\r loop : %d milli : %d nearend : %d", loop, ret, nearend);


 return ret;
}  

extern "C" unsigned char GetLoopi(unsigned char dev)
{
 unsigned char ret;
//PVG610_ERROR_MSG_ENUM PVG610_API_LoopbackGet(BYTE deviceIndex,
//                BYTE modemIndex, PVG610_LOOPBACK_TYPE_ENUM *loopbackValue,
  //               BOOLEAN *loopbackNearEnd, UINT32 *tributaryMask)

PVG610_LOOPBACK_TYPE_ENUM loopbackValue;
BOOLEAN loopbackNearEnd;
UINT32 tributaryMask;


 ret = PVG610_API_LoopbackGet(dev,0, &loopbackValue, &loopbackNearEnd, &tributaryMask);
// printfpd("\n\r Get Loop : %d ", (unsigned long)loopbackValue);		
 // printfpd("milli: %d ", milli);
 // printfpd("nearend: %d ", nearend);
 //  printfpd("trib: %d ",trib);
 delay_mcs(100000l);



 // printf("\n\r loop : %d milli : %d nearend : %d", loop, ret, nearend);


 return ret;
}

extern "C" unsigned char SetModuli(unsigned char dev, unsigned char transmitterMode,unsigned long toneFreqKhz, unsigned long sweepTimeMilli)
{
 PVG610_TRANSMITTER_MODE_STRUCT lbs;
 unsigned char ret;

    lbs.transmitterMode = transmitterMode;    // see PVG610_TRANSMITTER_MODE_ENUM
    lbs.toneFreqKhz = toneFreqKhz;        // relevant for one-tone, two-tone and tone-sweep
    lbs.sweepTimeMilli = sweepTimeMilli;     // relevant for tone-sweep only. Steps are in 1 msec units.

  ret = PVG610_API_TransmitterModeSet(dev,0, &lbs);
// printf("\n\r Set Loop : %d result : %d", loop, ret);
// printf("\n\r loop : %d milli : %d nearend : %d", loop, ret, nearend);
//	  PVG610_API_TransmitterModeSet(BYTE                           deviceIndex,
//                                                    BYTE                           modemIndex,
//                                                    PVG610_TRANSMITTER_MODE_STRUCT *tx)


 return ret;
}



//#ifdef PROG_BMDN2


extern "C" void ResetSyntOff(unsigned char deviceindex)
{
//it ok printf("\n\r ResetSyntOff %d", deviceindex);
//okprintf("12345678");
//ok printf("1234");
// printf("12");
//110118  printf("123");	 //ok
// printf("\n\r.............................................");
// printf("\n\r.............................................");
// printf("\n\r.............................................");
// printf("\n\r.............................................");
// printf("\n\r.............................................");
// printf("\n\r.............................................");
// printf("\n\r.............................................");


 //delay_mcs(50); //+12 - ok - not alweis!!!!

// printf("1");
// delay_mcs(1000000l); //+12 - ok
// delay_mcs(1000000l); //+12 - ok
//delay_mcs(1000000l); //+12 - ok
//delay_mcs(1000000l); //+12 - ok
//delay_mcs(1000l); //+12 - ok

//bad  delay_mcs(50);
 // delay_mcs(50000l);
 //  delay_mcs(50000l);
 //   delay_mcs(50000l);
 //	 delay_mcs(50000l);
 //	  delay_mcs(50000l);
 //	   delay_mcs(50000l);
  unsigned long offset;

 // delay_mcs(100000l);
   offset = BLOCK_SWEEP1 * ((deviceindex)+1);

 //101212  offset =  (deviceindex) << 4;


//   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), SYNT_NO_RESET);
   write_xil_char((offset  + RESET_ADDR), SYNT_NO_RESET);
}

extern "C" void ResetSyntOnly(unsigned char deviceindex)
{
#ifndef USART0_TRY_PDC_1T
// printf("\n\r ResetSyntOffOnly %d", deviceindex);
#endif
  unsigned long offset;

 //   delay_mcs(100000l);
   offset = BLOCK_SWEEP1 * ((deviceindex)+1);

 //101212  offset =  (deviceindex) << 4;


//   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), SYNT_NO_RESET);
   write_xil_char((offset  + RESET_ADDR), SYNT_RESET_ONLY);
}


extern "C" void CommonResetOff(unsigned char deviceindex)
{
//ok printf("\n\r CommonResetOff %d", deviceindex);
//delay_mcs(100000l);

  unsigned long offset;
//   offset =  (deviceindex) << 4;

 //   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_NO_RESET);
	  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
	write_xil_char(( offset + RESET_ADDR), COMMON_NO_RESET);

}

extern "C" void CommonResetOn(unsigned char deviceindex)
{
//ok printf("\n\r CommonResetOn %d", deviceindex);
// delay_mcs(100000l);

  unsigned long offset;
 //  offset =  (deviceindex) << 4;
  //  write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_RESET);
	  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
	write_xil_char(( offset + RESET_ADDR), COMMON_RESET);



}
#ifndef PROG_BMDN6MI

extern "C" void EnablePhone(void)
{
	write_xil_char(SERV_CH, EN_SERV);
}
#endif

extern "C" unsigned char GetStmPhyReg(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  return read_xil_char( offset + STM_PHY_ADDR);
}

extern "C" unsigned char GetEthReg(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  return read_xil_char( offset + ETH_ADDR);
}

extern "C" unsigned char GetRele(void)
{
  return read_xil_char( RELE_ADDR);
}

extern "C" unsigned char GetInputs(void)
{
  return read_xil_char( INPUTS_ADDR);
}



extern "C" unsigned char GetServReg(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  return read_xil_char( offset + SERV_ADDR);
}


extern "C" void SetOptics(unsigned char deviceindex, unsigned char value)
{
  unsigned long offset;
  unsigned char ret;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  ret = read_xil_char( offset + STM_PHY_ADDR);
  if(value)
  {
   if(ret & OPTIC_MASK) {return; }
   else {ret |= OPTIC_MASK; write_xil_char(( offset + STM_PHY_ADDR), ret); }
  }
  else 
  {
   if(!(ret & OPTIC_MASK)) {return; }
   else {ret &= ~(OPTIC_MASK); write_xil_char(( offset + STM_PHY_ADDR), ret);}
  }
}



//#define TYPE_RSERV_MODE  (0xE)
//#define  MODE_N_PLUS_1_REZ_ON	(0x70)
//#define  MODE_N_PLUS_1_WORK_OFF	(0x40)

extern "C" void SetModemXILRsrvMode(unsigned char deviceindex, unsigned char mode)
{

#ifdef USART0_TRY_PDC_1T
// 	printfp("\n\rSetModemXILRsrvMode");// type 1D return 3 : %d offset : %X\n\r", deviceindex, offset);
// 	printfpd(" %d", deviceindex);
//	printfpd("mode %X", mode);

 //   OperateBuffers_usart0t();
#endif

#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
  return; //for maket
#endif //MAKET_PLATA
   //	unsigned char mode;
   unsigned long offset;

//  if(deviceindex == NO_MODEM) return;
  if(deviceindex > (unsigned char)MODEM_QUANTITY) return;

//  if(deviceindex == currentrezerv) mode = MODE_N_PLUS_1_REZ_ON;
 // else mode = MODE_N_PLUS_1_WORK_OFF;

   offset =  BLOCK_SWEEP1 * ((deviceindex)+1);;
   write_xil_char(offset + TYPE_RSERV_MODE, mode);

} 

#define MODE_1_PLUS_0 (0)
//#define MODE_1_PLUS_1 (2)


extern "C" void SetModemXILNPL1m(unsigned char flag)
{
 unsigned char mod;

// printf("\n\r ModemIsUsed");
#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
  return; //for maket
#endif //MAKET_PLATA

//unsigned char mode;

//  if(deviceindex == currentrezerv) mode = MODE_N_PLUS_1_REZ_ON;
 // else mode = MODE_N_PLUS_1_WORK_OFF;

 
	if(flag == MODEM_QUANTITY)
	{

#ifndef PROG_BMDN4
 SetModemXILRsrvMode(currentrezerv, (MODE_N_PLUS_1_REZ_ON | MODE_N_PLUS_1_RSV_ON));  //before enover
#endif 
 
 
 for(mod = 0; mod < MODEM_QUANTITY; mod++ )
	  {
#ifndef PROG_BMDN4

		    if(mod != currentrezerv)// mode = MODE_N_PLUS_1_REZ_ON;
//  			else mode = MODE_N_PLUS_1_WORK_OFF;
	  //	 SetModemXILRsrvMode(mod, MODE_N_PLUS_1_WORK_OFF);
   if(protection_mode == MODE_N_PLUS_1)
 {
  if(mod != currentgetrezerv)
  {
  SetModemXILRsrvMode(mod, MODE_N_PLUS_1_WORK_OFF);
  }
  else
  {
  SetModemXILRsrvMode(mod, MODE_N_PLUS_1_WORK_ON);
  }
   }
   else
   {
   SetModemXILRsrvMode(mod, MODE_1_PLUS_0);

   }
#else
    SetModemXILRsrvMode(mod, MODE_1_PLUS_1);
#endif

} //for


	} //flag
	else
	{
  #ifndef PROG_BMDN4

  if(protection_mode == MODE_N_PLUS_1)
 {

	 if(flag == currentrezerv)
	 {
	  mode = (MODE_N_PLUS_1_REZ_ON | MODE_N_PLUS_1_RSV_ON);
	   SetModemXILRsrvMode(flag, mode);
	  }
  	 else
//110211  	  mode = MODE_N_PLUS_1_WORK_OFF;
{
 if(flag != currentgetrezerv)
  {
  SetModemXILRsrvMode(flag, MODE_N_PLUS_1_WORK_OFF);
  }
  else
  {
  SetModemXILRsrvMode(flag, MODE_N_PLUS_1_WORK_ON);
  }
}
}else
{
    SetModemXILRsrvMode(flag, MODE_1_PLUS_0);


}


	   //	  SetModemXILRsrvMode(flag, mode);


#else
    SetModemXILRsrvMode(flag, MODE_1_PLUS_1);
#endif
	}	 //flag
} 


extern "C" unsigned char ModemIsUsed(unsigned char deviceindex)
{

 //return 0; //t
// printf("\n\r ModemIsUsed");
if(GetTestMode() == 0x5A)
{
//if(deviceindex == 4)
//{
// printfp(" MIU");
// printfpd(" %d", deviceindex);
//  printfpd(" %X", BLOCK_SWEEP1 * ((deviceindex)+1));
//   printfpd(" %X", read_xil_char(TYPE_ADDR + BLOCK_SWEEP1 * ((deviceindex)+1) ));
// }

 }

#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
 if(deviceindex == 0) return 1; //for test
// if(deviceindex == 0) return 1; //for test
  //	return 0;
#endif //MAKET_PLATA
  if(deviceindex >= MODEM_QUANTITY) return 0; //

 // if(deviceindex == 4) return 0; //for test 110111

   unsigned long offset;
//   printf("%d -> ",deviceindex);
//   deviceindex >>= 1;
//   printf(" %d ",deviceindex);
 //  offset =  (deviceindex) << 4;
     offset = BLOCK_SWEEP1 * ((deviceindex)+1);
 //	printf("%d -> %X",deviceindex, offset);
 //  if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE)
   if(read_xil_char(offset + TYPE_ADDR) == MODEM_TYPE)
   {
// 	printf("\n\r type 1C return 1\n\r");
 //  if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
 // printfpd(" %d", deviceindex);

// 	printfp(" return 1");
// }
 
    return 1;
	}
 //  else if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE1)
   else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE1)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 2;
	}

  else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE3)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 4;
	}

  else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE4)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 5;
	}
	  else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE5)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 6;
	}
  else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE6)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 7;
	}

  else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE7)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 8;
	}
 else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE8)
   {
// 	printf("\n\r type 1E return 2\n\r");
//   if(GetTestMode() == 0x5A)
//{
 // printfp("\n\r ModemIsUsed");
//  printfpd(" %d", deviceindex);
 //	printfp(" return 2");
 //}
 
    return 9;
	}


   else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE2)
   {
    write_xil_char( offset + TYPE_ECHO, TEST_SYMBOL);

    if(read_xil_char( offset + TYPE_ECHO) == TEST_SYMBOL) 
	{
#ifndef USART0_TRY_PDC_1T
 //	printf("\n\r type 1D return 3 : %d offset : %X\n\r", deviceindex, offset);
 //   OperateBuffers_usart0t();
#else
//   delay_mcs(50000l);	  //for test
//   delay_mcs(50000l);	  //for test
//   delay_mcs(50000l);	  //for test

  //	printfp("\n\r type 1D return 3 : ");
 //	printfpd("%d", deviceindex);
#endif
//   if(GetTestMode() == 0x5A)
//{
// printfp("\n\r ModemIsUsed");
 // printfpd(" %d", deviceindex);
// 	printfp(" return 3");
// }
 
	 return 3;
	}




	else
	{
#ifndef USART0_TRY_PDC_1T
 //	 printf("\n\r type 1D echo bad return 0 : %d offset : %X\n\r", deviceindex, offset);
#endif
//   if(GetTestMode() == 0x5A)
//{
  //	printfp(" return 0");
 //}
 
	  return 0;

	}
 	}

   else
   {
  // printf(":0\n\r");
//   if(GetTestMode() == 0x5A)
//{
 //	printfp(" return 0");
// }
 

    return 0; 
   }
}
//n 0; 
//   }
//}


//#endif // PROG_BMDN2




void LoadSyntm(unsigned char deviceindex)
//extern "C" void LoadSynt(void)
{
// printf("\n\r LoadSyntm : %d", deviceindex);
//WriteSpiB(unsigned long length_of_data, unsigned char * BufferData)
unsigned char d[6];
unsigned long dlen;
deviceindex += SYNT_OFFSET;

//_________________________________________________________________
	d[0] = 0x20; d[1] = 0x15; d[2] = 0; d[3] = 0x0f; dlen = 4;
	if(!(WriteSpiBm(deviceindex,dlen, d))) return;	   //101015 return added to not hangt if loss device
//_________________________________________________________________
	d[0] = 0; d[1] = 0x17; d[2] = 0x9c; dlen = 3;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0; d[1] = 0x10; d[2] = 0x7c; dlen = 3;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x40; d[1] = 0x13; d[2] = 0; d[3] = 0; d[4] = 0x01; dlen = 5;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0; d[1] = 0x16; d[2] = 0x04; dlen = 3;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0; d[1] = 0x1c; d[2] = 0x26; dlen = 3;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x20; d[1] = 0xf1; d[2] = 0x08; d[3] = 0x08; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x20; d[1] = 0xf5; d[2] = 0x08; d[3] = 0x08; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
//	d[0] = 0x61; d[1] = 0x43; d[2] = 0; d[3] = 0; d[4] = 0; d[5] = 0; dlen = 6;
//	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x21; d[1] = 0x41; d[2] = 0; d[3] = 0; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x21; d[1] = 0x43; d[2] = 0; d[3] = 0; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
#ifdef SYNT_100_MHZ
	d[0] = 0x41; d[1] = 0x92; d[2] = 0; d[3] = 0x11; d[4] = 0; dlen = 5;
#else
	d[0] = 0x41; d[1] = 0x92; d[2] = 0; d[3] = 0; d[4] = 0; dlen = 5;
#endif
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
#ifdef SYNT_100_MHZ
	d[0] = 0x41; d[1] = 0x98; d[2] = 0; d[3] = 0x11; d[4] = 0; dlen = 5;
#else
	d[0] = 0x41; d[1] = 0x98; d[2] = 0; d[3] = 0; d[4] = 0; dlen = 5;
#endif


	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
#ifdef SYNT_100_MHZ
	d[0] = 0x01; d[1] = 0x99; d[2] = 0x11;  dlen = 3;
#else
	d[0] = 0x01; d[1] = 0x99; d[2] = 0;  dlen = 3;
#endif
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x21; d[1] = 0x9D; d[2] = 0; d[3] = 0x20; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
#ifdef SYNT_100_MHZ
	d[0] = 0x01; d[1] = 0x9E; d[2] = 0x11;  dlen = 3;
#else
	d[0] = 0x01; d[1] = 0x9E; d[2] = 0;  dlen = 3;
#endif

	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x21; d[1] = 0xa2; d[2] = 0; d[3] = 0x20; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x21; d[1] = 0xe1; d[2] = 0x02; d[3] = 0x04; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________
	d[0] = 0x02; d[1] = 0x32; d[2] = 0x01; dlen = 3;
	WriteSpiBm(deviceindex,dlen, d);
//_________________________________________________________________

//______________________________________________________________ syntlodn


//______________________________________________________________





 
}
//#define  MAX_SENDS_VAL (3)
//#define  MAX_SENDS_VAL (21)	 //19
#define  MAX_SENDS_VAL (64)	 //19

#define  BUFF_SYNT_SIZE (6)
#define MAX_DIGIT_SIZE (2)

unsigned char ConvertASCII(unsigned char val)
{
 // printf(" _%02X", val);
 unsigned long ret;
 if(val <= 0x39) {ret = val - 0x30; //printf("-%X", ret);
 }
 else if(val <= 0x46)
 { ret = 10 + val - 0x41;//ABCDEF printf("+%X", ret);
 }
 else if((val == 0xD1) ||(val == 0xf1))
 { ret = 12;//rashe  С c
 }
  else if(val <= 0x66)
 { ret = 10 + val - 0x61;//abcdef printf("+%X", ret);
 }
   else if(val <= 0xC5)
 { ret = 10 + val - 0xc0;//rashe ABE
 }
   else if(val <= 0xE5)
 { ret = 10 + val - 0xE0;//rash abe
 }
	else
	{ret = 0;}



 return (unsigned char)ret;
}


extern "C" void  LoadSyntDatam(unsigned char deviceindex, unsigned char * pBuffer)
{
  unsigned char dlen;
  unsigned char d[BUFF_SYNT_SIZE];
  unsigned long sends_counter = 0;
  unsigned long buff_fill_counter, digits_counter;
 // unsigned char * pBuffTmp;
  dlen = 0;
  unsigned char cur_val;
  unsigned char tmpchar;
  unsigned char flag = 0;
 // printf("\n\r deviceindex : %d", deviceindex);

  while((*pBuffer != 0x2e)  &&  (sends_counter++ < MAX_SENDS_VAL))
  {
  buff_fill_counter = 0;
//  printf("sends : %d",sends_counter);
 // pBuffTmp = pBuffer;
 // while((*pBuffer != 0xD)  &&  (buff_fill_counter < BUFF_SYNT_SIZE))
 //if(*pBuffer == 0x20)	{printf("_");
   		//		pBuffer++; }

  while(buff_fill_counter < BUFF_SYNT_SIZE)
  {
   digits_counter = 0;
   cur_val = 0;
   while((*pBuffer != 0x20) && (*pBuffer != 0xD) && (*pBuffer != 0xA) &&  (digits_counter < MAX_DIGIT_SIZE))
 //  while((*pBuffer != 0x20) &&  (digits_counter < MAX_DIGIT_SIZE))
  	   {
	   flag = 1;
		 cur_val <<= 4;
		 tmpchar = ConvertASCII(*pBuffer++);
	 //	 printf(".%02X", tmpchar);
		 cur_val += tmpchar; //ConvertASCII(*pBuffer++);
		 digits_counter++;
	   }
//   *pBuffer--;	   
 //	pBuffer++;
 //	d[buff_fill_counter] = cur_val;
// 	buff_fill_counter++;
  //t100726	printf("> %d :  %d : %X",buff_fill_counter,digits_counter, d[buff_fill_counter] ); //!!!!!!!!!!!
 //		buff_fill_counter++;
//if(*pBuffer == 0xD)	{printf("D");
  //						 break;}
 	if(*pBuffer == 0xA)	{//printf("A");
 						 break;}
 //	if(*pBuffer == 0x20)	{printf("_");
   //						 break;}

  //	if(*pBuffer == 0x2e)	{//printf(".");
   //						 break;}
  //	pBuffer++;
 //	printf("\n\r buff_fill_counter %d cur_val %02X", buff_fill_counter,cur_val);
  if(flag)
  {
//  printf("_%d_",flag);
	d[buff_fill_counter] = cur_val;
	buff_fill_counter++;

	flag = 0;
  }




if(*pBuffer == 0x2e)	{//printf(".");
 						 break;}


 //	buff_fill_counter++;
if(*pBuffer == 0xD)	{//printf("D");
 						 break;}
				   //		 pBuffer++;
	 *pBuffer++;
  }
#ifndef USART0_TRY_PDC_1T 
//  printf("\n\r> ");
#endif
  for(long r = 0; r < buff_fill_counter; r++)
  {
#ifndef USART0_TRY_PDC_1T
//   printf(" %02X", d[r]);
#endif
  }
   if(buff_fill_counter)
	{
//	WriteSpiBm(deviceindex,dlen, d);
//   printf("dev : %d count : %d",(deviceindex+SYNT_OFFSET), buff_fill_counter); 


    WriteSpiBm((deviceindex + SYNT_OFFSET),buff_fill_counter, d);
 //	printf(" finish");

	}
	if(*pBuffer == 0x2e)	{//printf(".");
 						 break;}

	pBuffer++; //com 0xD
  if(*pBuffer == 0x2e)	{//printf(".");
 						 break;}

	pBuffer++; //com 0xA
	if(*pBuffer == 0x2e)	{//printf(".");
 						 break;}


  }
  //	pBuffer++;
   
}

void LoadSyntmf(unsigned long variant, unsigned char deviceindex)
//extern "C" void LoadSynt(void)
{
//_____________________________________________________________________________________
//extern "C" void ConfigFileLoadm(unsigned long variant, unsigned char flagm)
//{
//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_MODEM_STATUS_STRUCT *pMs;
//pMs = &Ms;
BYTE *pBuffer;
unsigned long curvar = 0xfff+1; //more as maximum var

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;

}

//UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
 //							 (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
unsigned long ir;
unsigned long config_delta;


if(deviceindex == MODEM_QUANTITY)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
 if(ModemIsUsed(im))
 {
 //____________________________________________________________
// printfp("1210049");
variant =  GetNumConfigFilet(im) & CONFIG_FILE_MASK;
 //printf("curvar = %d",curvar);
//if(variant != curvar)
if(1)
{
// printf("read flash!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//__________________________________________________hier need read config_step
//unsigned long config_step;
#ifndef DO_NOT_READ_CONFIG_DELTA

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))
#endif
  config_delta = CONFIG_FILE_PROVINGENT_STEP;
#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	  
#endif
//__________________________________________________config_step



//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));

//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1)),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
							 (unsigned int)SYNT_FILE_SIZE, (char *)(&TFTP_Buffer[0]));
}
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________


// ir = im << 1;
 ir = im;
//#ifndef USART0_TRY_PDC_1T
// printf("\n\r Load Synt_  %d", ir);
//#else
#ifdef START_PRINT
  printfpd("\n\r Load Synt :  %d", ir);

  for(unsigned j = 0; j < 48; j++)
  {
  printfpd(" %02X ", TFTP_Buffer[j]);
  if(!(j%16)) printfp("\n\r");
  }


#endif
//#endif
 //printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 LoadSyntDatam(im, pBuffer);
//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//_______________________________________________________________
//_______________________________________________________________

//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);


//for(unsigned long its =0l; its < 100l; its++)
//{
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
//}


//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
   curvar = variant;
 }	  //used
// curvar = variant;
}  //for
}  //if
else
{
 //____________________________________________________________
// printfp("121004A");
variant =  GetNumConfigFilet(deviceindex) & CONFIG_FILE_MASK;

//__________________________________________________hier need read config_step
//unsigned long config_step;
#ifndef DO_NOT_READ_CONFIG_DELTA

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  
#endif
config_delta = CONFIG_FILE_PROVINGENT_STEP;
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	 
//#endif 
//__________________________________________________config_step





//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP)+
//101018 SYNT_DATA_OFFSET),
						(config_delta << 1)),
 //							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
				 (unsigned int)SYNT_FILE_SIZE, (char *)(&TFTP_Buffer[0]));

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________



 ir = deviceindex;// << 1;
//#ifndef USART0_TRY_PDC_1T
 //printf("\n\r Load Synt__  %d", ir);
//#else
#ifdef PRINT_START
  printfp("\n\r Load Synt_:");
  printfpd(" %d", ir);

 for(unsigned j = 0; j < 64; j++)
  {
  printfpd(" %02X ", TFTP_Buffer[j]);
  if(!(j%16)) printfp("\n\r");
  }



#endif
//#endif

// printf("\n\r");
// for(long i = 0; i < 10; i++)
// for(long i = 0; i < 48; i++)
// {
// if(!(i%16)){printf("\n\r");}
//  printf(" %02X", pBuffer[i]);
// }
   LoadSyntDatam(deviceindex, pBuffer);

// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));

//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//_______________________________________________________________
/*
//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);


for(unsigned long its =0l; its < 100l; its++)
{
 // printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
}

 */
//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));



}	 //else	 <--- need check is used
//}






  curvar = 0xff+1;
// delay_mcs(SYNT_SET_DELAY);
}



//#define	 REQUEST_QUANTITY (5)
#define	 REQUEST_QUANTITY (3)

void SendRequest(unsigned char im, unsigned char channel)
{
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
{

printfp("\n\rSendRequest ");
printfpd("for %d", im);
printfpd(" channel %d", channel);
}
#endif

 
if(channel > MODEM_QUANTITY) 
{
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
{
 printfp(" this now  do not have channel ... return");
}
#endif

return;
}


for(long i = 0; i < REQUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5,channel);
  embSerialACT155.AddModM(im, channel);
if(GetTestMode() == 0x5A)
 {
  printfpd(" %d", im);
 }
}

}

//#define	 RESPONSE_QUANTITY (5)
#define	 RESPONSE_QUANTITY (3)
#define  FLAG_RESPONSE (0x80)

extern "C" void SendResponse(unsigned char im)
{

#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
 {

 printfp(" SendResponse");
 printfpd(": %d",im);
 }
#endif

 unsigned char chn = GetChannelToSend();
if(im > MODEM_QUANTITY) return;
for(long i = 0; i < REQUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5, chn);
  embSerialACT155.AddModM(im | FLAG_RESPONSE, chn);
}

}

extern "C" void SendCurState()
{

#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
 {
   printfp(" SendCurState");
 //printfpd(": %d",im);
 }
#endif
// unsigned char chn = GetChannelToSend();
 unsigned char chn = 0;

// if(im > MODEM_QUANTITY) return;

 for(long i = 0; i < REQUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5, chn);
  embSerialACT155.AddMod(FLAG_RESPONSE, chn);
//need add alarm reg and lock req
  embSerialACT155.AddMod(dev_status, chn);	//for test temporary
  embSerialACT155.AddModM(uerrsn15503work.errsn15303work.lock1, chn);
}

}


#define NO_ACM (0)

extern "C" void CommutateGettedRezerv(unsigned char chn)
{

unsigned char ret;
unsigned char provnum = chn << 1;
unsigned char provnumcurrent = currentgetrezerv << 1;

 
 /* 110201
 if(ModemIsUsed(currentgetrezerv))
 ret =  PVG610_API_ProtectionTxModeSet(provnumcurrent,
                                            0,  //modem - not used
                                                      PVG610_PROTECTION_MODE_NONE_E,
                                                      currentgetrezerv + ID_CORR, NO_ACM);


  if(ret)
  {
 //  currentgetrezerv = NO_MODEM;
//hier need set flag to repair this modem
  }
//  else
//  {
//  return;
//  }
*/

//get off current get rezerv
  if(currenthaverezerv != currentgetrezerv)
  {
  SetModemXILRsrvMode(currentgetrezerv, MODE_N_PLUS_1_WORK_OFF);
  }
  else
  {
  SetModemXILRsrvMode(currentgetrezerv, (MODE_N_PLUS_1_WORK_OFF | MODE_N_PLUS_1_RSV_ON));
  }
 
  currentgetrezerv = NO_MODEM;

 //________________________________________________________________ need move  after receive cvit
//current modem to working protection mode
//   SetModemXILRsrvMode(chn, MODE_N_PLUS_1_WORK_ON);

  /* 110201
 if(ModemIsUsed(chn))
 ret =  PVG610_API_ProtectionTxModeSet(provnum,
                                            0,  //modem - not used
                                                      PVG610_PROTECTION_MODE_WORKING_E,
                                                      chn + ID_CORR, NO_ACM);
 if (ret)// return;
 {
 //hier need set flag to repair this modem
 }
   */
if(currenthaverezerv != chn)
  {
  SetModemXILRsrvMode(chn, MODE_N_PLUS_1_WORK_ON);
  }
else
 {
   SetModemXILRsrvMode(chn, (MODE_N_PLUS_1_WORK_ON |  MODE_N_PLUS_1_RSV_ON));
 }
//_____________________________________________________________________need move after receive cvit
 //110513 /* 110201
//rezerved modem (zero) to protected protection mode ?? - can it make at start?
 if(ModemIsUsed(currentrezerv))
 ret =  PVG610_API_ProtectionTxModeSet((currentrezerv << 1),
                                            0,  //modem - not used
                                                      PVG610_PROTECTION_MODE_PROTECTION_E,
                                                      chn + ID_CORR, NO_ACM);
   if (ret)// return;
   {
  //hier need set flag to repair this modem
   }
 //110513	 */
   currentgetrezerv = chn;
}


extern "C" unsigned char SetRezervTransmit(void)
{

 unsigned char provnum = currentrezerv << 1;
 unsigned char ret;
 ret =  PVG610_API_ProtectionTxModeSet (provnum,
                                                      0,  //modem - not used
                                                      uProt[provnum].protection.ProtTx,
                                                      uProt[provnum].protection.PhyIDTx + ID_CORR,
													  uProt[provnum].protection.CopyAcm);
#ifndef USART0_TRY_PDC_1T	
  printf("\n\r PVG610_API_ProtectionTxModeSet %d %X %X %X...%d", provnum,uProt[provnum].protection.ProtTx, uProt[provnum].protection.PhyIDTx + ID_CORR,  uProt[provnum].protection.CopyAcm, ret);     
#endif
 return ret;
}


extern "C" void TryGetRezerv(unsigned char chn)
{
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
 {
 printfp("\n\rTryGetRezerv");
 printfpd(": %d",chn);
 printfpd("t: %d",time1);
 }

#endif
 SendResponse(chn);
 SetRezervTransmit(); //110426
  
if(currentgetrezerv == chn) 
 {
#ifdef USART0_TRY_PDC_1T
 if(GetTestMode() == 0x5A)
 {
 printfp(" currentgetrezerv == chn");
 printfp("make next time");
 }
#endif
 
//110513 return;
 }
 

time_rcv_req_to_get = time1;
//#ifndef USART0_TRY_PDC_1T
// printf("TryGetRezerv : %d", chn);
//#endif

#ifdef USART0_TRY_PDC_1T
// printfp("\n\rTryGetRezerv");
// printfpd(": %d",chn);
// printfpd("t_g: %d",time_rcv_req_to_get);
#endif
//  SendResponse(chn);
  
   
 CommutateGettedRezerv(chn);
// SendResponse(chn);
 //tSetRezervTransmit(); //110426
}

extern "C" void SetStartRezerv()
{


unsigned short mod_mask = 1;
static unsigned long countert;


countert++;
char typemodem;// = 0;

 if(protection_mode !=  MODE_N_PLUS_1) return;


//if(!(countert % 5000))
//{
// printf("$");
//}


//if(timescan > time1) timescan = time1;

//if(1)
//{
//timescan = time1;
// printf("\n\r scan ");

//if(flag == MODEM_QUANTITY)
//{
for(long im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
 //printf("%d", im);
 typemodem =  ModemIsUsed(im);
 if(im != currentrezerv)
 if(typemodem)	//1c
 {
 //  printf("_%d", im);
 //  if(!(used_modems & mod_mask))
 //  {
  //  RestartTest++;
  // used_modems |= mod_mask;
 //  }
 SetModemXILRsrvMode(im, MODE_N_PLUS_1_WORK_ON); // | MODE_N_PLUS_1_RSV_OFF);
 currentgetrezerv = im;
   break;
 }
// else
// {
  // printf("-%d", im);

  //	used_modems &= ~(mod_mask);
 //    SetModemStruct(im,typemodem);
// }
  mod_mask <<= 1;
} //for
//}


}

extern "C" void CommutateHaveRezerv(unsigned char chn)
{
 unsigned char ret = 1;
 unsigned char provnum = chn << 1;

#ifndef USART0_TRY_PDC_1T
 
#else
if(GetTestMode() == 0x5A)
{
 printfp("\n\rCommutateHaveRezerv");
}
#endif


//if(ModemIsUsed(REZERV_PROV>>1))

//? need reloading current rezerv to new ch id ????
  /* do not reload provingents - all in working mode - it will be maked in xilinxes commutate bad data to not protected now provingents
  */

//without this do not reserv
if(ModemIsUsed(currentrezerv))
 ret =  PVG610_API_ProtectionRxModeSet((currentrezerv << 1),
                                            0,  //modem - not used
                                                      PVG610_PROTECTION_MODE_PROTECTION_E,
                                                      chn + ID_CORR);
/*
 if(ret) return;



  //________________________________________________________________ need move  after receive cvit
//set modem to working protection mode
//SetModemXILRsrvMode(provnum, MODE_N_PLUS_1_WORK_ON);



if(ModemIsUsed(chn))
 ret =  PVG610_API_ProtectionRxModeSet(provnum,
                                            0,  //modem - not used
                                                      PVG610_PROTECTION_MODE_WORKING_E,
                                                      chn + ID_CORR);
//_____________________________________________________________________need move after receive cvit
  if(ret) return;
	*/
  currenthaverezerv = chn;

if(currentgetrezerv != currenthaverezerv)
  {
	SetModemXILRsrvMode(currenthaverezerv, MODE_N_PLUS_1_WORK_OFF | MODE_N_PLUS_1_RSV_ON);
  }
  else
  {
	SetModemXILRsrvMode(currenthaverezerv, MODE_N_PLUS_1_WORK_ON | MODE_N_PLUS_1_RSV_ON);
  }
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
{
printfp("\n\rcurrenthaverezerv: ");
printfpd("%d", currenthaverezerv);
}

//printfpd("to %d", im);
#endif

}


extern "C" void ValidateHaveRezerv(unsigned char chn)
{

//110513 if(currenthaverezerv == chn)  return;

 time_end_prt = time1;

#ifndef USART0_TRY_PDC_1T
 //printf("ValidateHaveRezerv : %d", chn);
#else
if(GetTestMode() == 0x5A)
{

 printfp("\n\rValidateHaveRezerv");
 printfpd(" t_end %d :", time_end_prt);
}
#endif
 //if(currenthaverezerv == chn)  return;
 CommutateHaveRezerv(chn);
}


#define  ENABLED_REQUESTS_QUANTITY (3)
//#define  ENABLED_RESPONSES_QUANTITY (3)
#define  ENABLED_RESPONSES_QUANTITY (2)

#ifndef PROG_BMDN6MI

extern "C" void ParseRequestsRezervResponses()
{
 static unsigned char tmp;
 static unsigned char response;

 unsigned char sym;
// static unsigned char reqcounter;
 for(long i = 0; i < MODEM_QUANTITY; i++)
 {
 if(embMsgWestR[i].Used())
 {
#ifdef USART0_TRY_PDC_1T
 printfp("\n\rParseRequestsRezervResponses");
// printfpd(" %d :", i);
#endif


 while(embMsgWestR[i].Used())
 {
  sym = embMsgWestR[i].Get();

#ifdef USART0_TRY_PDC_1T
// printfp("ParseRequestsRezervResponses");
// printfpd(" 0x%02X", sym);
#endif

  if(!(sym & FLAG_RESPONSE))
  {
  if(tmp == sym)
  {
   reqcounter[i]++;
  }
  else
  {
   tmp = sym;
   reqcounter[i] = 0;
  }

  if(reqcounter[i] >= ENABLED_REQUESTS_QUANTITY)
  {
	 TryGetRezerv(tmp);
	 reqcounter[i] = 0;
  //	 embMsgWestR.Free();
  }
  } //flag_response
  else
  {
	//hier parse responseansvers
   if(response == sym)
  {
   rescounter[i]++;
  }
  else
  {
   response = sym;
   rescounter[i] = 0;
  }

  if(rescounter[i] >= ENABLED_RESPONSES_QUANTITY)
  {
	 ValidateHaveRezerv(response & (~(FLAG_RESPONSE)));
	 rescounter[i] = 0;
  //	 embMsgWestR.Free();
   }//if 
  }	 //flag_response
  }	//while-Used
 } //if-used
 } //for i
}

extern "C" void ParseRequestsRezervResponsesi(unsigned char i)
{
 static unsigned char tmp;
 static unsigned char response;

 unsigned char sym;
// static unsigned char reqcounter;
// for(long i = 0; i < MODEM_QUANTITY; i++)
// {

  if(i >= MODEM_QUANTITY) return;

 if(embMsgWestR[i].Used())
 {
#ifdef USART0_TRY_PDC_1T
// printfp("\n\rParseRequestsRezervResponsesi");
// printfpd(" %d :", i);
#endif


 while(embMsgWestR[i].Used())
 {
  sym = embMsgWestR[i].Get();

#ifdef USART0_TRY_PDC_1T
// printfp("ParseRequestsRezervResponses");
// printfpd(" 0x%02X", sym);
#endif
// if(!(sym & FLAG_CUR_STATE))
// {
  if(!(sym & FLAG_RESPONSE))
  {
  if(tmp == sym)
  {
   reqcounter[i]++;
  }
  else
  {
   tmp = sym;
   reqcounter[i] = 0;
  }
 // }
 // else
 // {
   //hier keep received far state; self state not receive?
   //or need send self address
   //need have statemashine

//  }

  if(reqcounter[i] >= ENABLED_REQUESTS_QUANTITY)
  {
	 TryGetRezerv(tmp);
	 reqcounter[i] = 0;
  //	 embMsgWestR.Free();
  }
  } //flag_response
  else
  {
	//hier parse responseansvers
   if(response == sym)
  {

#ifdef USART0_TRY_PDC_1T
// printfp("ParseRequestsRezervResponses");
// printfpd("rescnt 0x%02X", rescounter[i]);
#endif

   rescounter[i]++;
  }
  else
  {

   response = sym;
   rescounter[i] = 0;
  }

  if(rescounter[i] >= ENABLED_RESPONSES_QUANTITY)
  {

#ifdef USART0_TRY_PDC_1T
// printfp("ParseRequestsRezervResponses");
// printfp("> ENABLED_RESPONSES_QUANTITY ");
#endif

	 ValidateHaveRezerv(response & (~(FLAG_RESPONSE)));
	 rescounter[i] = 0;
  //	 embMsgWestR.Free();
   }//if 
  }	 //flag_response
  }	//while-Used
 } //if-used
// } //for i
}

#endif

/*
#define LOCK_OK (1)
//#define BAD_NOISES (0xffffffff) //????
#define BAD_NOISES (0) //????
#define GOOD_NOISES (-1000) //????
 */

#ifndef PROG_BMDN6MI

extern "C" signed short CheckNoises(unsigned char im)
{
//im - channel
// CurrentErrors = 0;
#ifdef TEST_CHANGE_REZERV
static unsigned long  timecheck;
#endif

  if(im == NO_MODEM) return (GOOD_NOISES); // to not disable changing protection at start 

#ifndef TEST_CHANGE_REZERV
  im <<= 1; //use numbers of provingents divided by 2!!!!!
  if(modemp[im].acquireStatus == LOCK_OK) {  return modemp[im].normalizedMseTenths; }
  else {return (BAD_NOISES);}
#else
  im <<= 1; //use numbers of provingents divided by 2!!!!!
  if(modemp[im].acquireStatus == LOCK_OK) { 
  if(((time1 - timecheck) > CHANGE_PERIOD) && (GetTestMode() == 0x50))
  {
   	 timecheck = time1;
	 return (BAD_NOISES);
  }
  else
  {
  return modemp[im].normalizedMseTenths; }
  }
  else {return (BAD_NOISES);}
#endif

// return 0;
}

#endif


// PVG610_API_ProtectionStatusGet (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_STATUS_STRUCT *pPs)
#define DUMMY	(0)
//_____________________________________________________________________________D
#ifndef PROG_BMDN6MI
extern "C" void GetRxPhyIdD()
{
 static unsigned char deviceindex;
  deviceindex += 2;
  if(deviceindex >= (MODEM_QUANTITY << 1)) deviceindex = 0;
  PVG610_PROTECTION_STATUS_STRUCT pPs;
  unsigned char ret;
  if(ModemIsUsed(deviceindex >> 1))
  {
  ret = PVG610_API_ProtectionStatusGet(deviceindex, DUMMY, &pPs);
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
{
 printfp("\n\rProtectionStatusGet ");
 printfpd(" %d", deviceindex);
 printfp(" protectionRxState =");
 printfpd(" %d", pPs.protectionRxState);
 printfp(" rxPhyId =");
 printfpd(" %d", pPs.rxPhyId);
 printfp(" ret =");
 printfpd(" %d", ret);
}
#endif


 // return pPs.rxPhyId;
// return pPs.protectionRxState;
 modemp[deviceindex].ProtectionRxState = pPs.protectionRxState;
 }
 else
 {
// return 0;
 }
}

//_____________________________________________________________________________D


extern "C" unsigned short GetRxPhyId(unsigned char deviceindex)
{
  PVG610_PROTECTION_STATUS_STRUCT pPs;
  unsigned char ret;
  if(ModemIsUsed(deviceindex >> 1))
  {
  ret = PVG610_API_ProtectionStatusGet(deviceindex, DUMMY, &pPs);
#ifdef USART0_TRY_PDC_1T
if(GetTestMode() == 0x5A)
{
 printfp("\n\rProtectionStatusGet ");
 printfpd(" %d", deviceindex);
 printfp(" protectionRxState =");
 printfpd(" %d", pPs.protectionRxState);
 printfp(" rxPhyId =");
 printfpd(" %d", pPs.rxPhyId);
 printfp(" ret =");
 printfpd(" %d", ret);
}
#endif

 modemp[deviceindex].ProtectionRxState = pPs.protectionRxState;
 modemp[deviceindex].rxPhyId = pPs.rxPhyId;

 // return pPs.rxPhyId;
 return pPs.protectionRxState;
 }
 else
 {
 return 0;
 }
}

#endif

#ifndef PROG_BMDN6MI

extern "C" unsigned long GetProvData(unsigned long addr)
{
 unsigned long ret = 0;

switch(addr)
{
   case 0 : ret  = modemp[0].acquireStatus;	break;
   case 1 : ret  = modemp[1].acquireStatus; break;//modemp[1].acquireStatus;
   case 2 : ret  = modemp[0].absoluteMseTenths; break;//modemp[0].absoluteMseTenths;
   case 3 : ret  = modemp[1].absoluteMseTenths; break;//modemp[1].absoluteMseTenths;
   case 4 : UsedExp.State.Reg2.bit.ProtSt0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1;
   			ret  = modemp[0].ProtectionRxState; break;//modemp[0].ProtectionRxState;
   case 5 :	UsedExp.State.Reg2.bit.ProtSt1 = 1;	 UsedExp.State.Reg2.bit.Some  = 1;
   			ret  = modemp[1].ProtectionRxState; break;//modemp[1].ProtectionRxState;
   case 6 : ret  = modemp[0].txAcmProfile; break;//modemp[1].ProtectionRxState;
   case 7 : ret  = modemp[0].rxAcmProfile; break;//modemp[1].ProtectionRxState;
   case 8 : ret  = modemp[0].acmEngineEnabled; break;
   case 9   : ret  = modemp[1].txAcmProfile; break;//modemp[1].ProtectionRxState;
   case 0xA : ret  = modemp[1].rxAcmProfile; break;//modemp[1].ProtectionRxState;
   case 0xB : ret  = modemp[1].acmEngineEnabled; break;
 
   case 0x10 : ret  = modemp[0].txAcmProfilesCounter[0]; break;//modemp[1].ProtectionRxState;
   case 0x11 : ret  = modemp[0].txAcmProfilesCounter[1]; break;//modemp[1].ProtectionRxState;
   case 0x12 : ret  = modemp[0].txAcmProfilesCounter[2]; break;//modemp[1].ProtectionRxState;
   case 0x13 : ret  = modemp[0].txAcmProfilesCounter[3]; break;//modemp[1].ProtectionRxState;
   case 0x14 : ret  = modemp[0].txAcmProfilesCounter[4]; break;//modemp[1].ProtectionRxState;
   case 0x15 : ret  = modemp[0].txAcmProfilesCounter[5]; break;//modemp[1].ProtectionRxState;
   case 0x16 : ret  = modemp[0].txAcmProfilesCounter[6]; break;//modemp[1].ProtectionRxState;
   case 0x17 : ret  = modemp[0].txAcmProfilesCounter[7]; break;//modemp[1].ProtectionRxState;
   case 0x18 : ret  = modemp[0].txAcmProfilesCounter[8]; break;//modemp[1].ProtectionRxState;
   case 0x19 : ret  = modemp[0].txAcmProfilesCounter[9]; break;//modemp[1].ProtectionRxState;
   case 0x1A : ret  = modemp[0].txAcmProfilesCounter[10]; break;//modemp[1].ProtectionRxState;
   case 0x1B : ret  = modemp[0].txAcmProfilesCounter[11]; break;//modemp[1].ProtectionRxState;
   case 0x1C : ret  = modemp[0].txAcmProfilesCounter[12]; break;//modemp[1].ProtectionRxState;
   case 0x1D : ret  = modemp[0].txAcmProfilesCounter[13]; break;//modemp[1].ProtectionRxState;
   case 0x1E : ret  = modemp[0].txAcmProfilesCounter[14]; break;//modemp[1].ProtectionRxState;
   case 0x1F : ret  = modemp[0].txAcmProfilesCounter[15]; break;//modemp[1].ProtectionRxState;
 
   case 0x20 : ret  = modemp[0].rxAcmProfilesCounter[0]; break;//modemp[1].ProtectionRxState;
   case 0x21 : ret  = modemp[0].rxAcmProfilesCounter[1]; break;//modemp[1].ProtectionRxState;
   case 0x22 : ret  = modemp[0].rxAcmProfilesCounter[2]; break;//modemp[1].ProtectionRxState;
   case 0x23 : ret  = modemp[0].rxAcmProfilesCounter[3]; break;//modemp[1].ProtectionRxState;
   case 0x24 : ret  = modemp[0].rxAcmProfilesCounter[4]; break;//modemp[1].ProtectionRxState;
   case 0x25 : ret  = modemp[0].rxAcmProfilesCounter[5]; break;//modemp[1].ProtectionRxState;
   case 0x26 : ret  = modemp[0].rxAcmProfilesCounter[6]; break;//modemp[1].ProtectionRxState;
   case 0x27 : ret  = modemp[0].rxAcmProfilesCounter[7]; break;//modemp[1].ProtectionRxState;
   case 0x28 : ret  = modemp[0].rxAcmProfilesCounter[8]; break;//modemp[1].ProtectionRxState;
   case 0x29 : ret  = modemp[0].rxAcmProfilesCounter[9]; break;//modemp[1].ProtectionRxState;
   case 0x2A : ret  = modemp[0].rxAcmProfilesCounter[10]; break;//modemp[1].ProtectionRxState;
   case 0x2B : ret  = modemp[0].rxAcmProfilesCounter[11]; break;//modemp[1].ProtectionRxState;
   case 0x2C : ret  = modemp[0].rxAcmProfilesCounter[12]; break;//modemp[1].ProtectionRxState;
   case 0x2D : ret  = modemp[0].rxAcmProfilesCounter[13]; break;//modemp[1].ProtectionRxState;
   case 0x2E : ret  = modemp[0].rxAcmProfilesCounter[14]; break;//modemp[1].ProtectionRxState;
   case 0x2F : ret  = modemp[0].rxAcmProfilesCounter[15]; break;//modemp[1].ProtectionRxState;

   case 0x30 : ret  = modemp[1].txAcmProfilesCounter[0]; break;//modemp[1].ProtectionRxState;
   case 0x31 : ret  = modemp[1].txAcmProfilesCounter[1]; break;//modemp[1].ProtectionRxState;
   case 0x32 : ret  = modemp[1].txAcmProfilesCounter[2]; break;//modemp[1].ProtectionRxState;
   case 0x33 : ret  = modemp[1].txAcmProfilesCounter[3]; break;//modemp[1].ProtectionRxState;
   case 0x34 : ret  = modemp[1].txAcmProfilesCounter[4]; break;//modemp[1].ProtectionRxState;
   case 0x35 : ret  = modemp[1].txAcmProfilesCounter[5]; break;//modemp[1].ProtectionRxState;
   case 0x36 : ret  = modemp[1].txAcmProfilesCounter[6]; break;//modemp[1].ProtectionRxState;
   case 0x37 : ret  = modemp[1].txAcmProfilesCounter[7]; break;//modemp[1].ProtectionRxState;
   case 0x38 : ret  = modemp[1].txAcmProfilesCounter[8]; break;//modemp[1].ProtectionRxState;
   case 0x39 : ret  = modemp[1].txAcmProfilesCounter[9]; break;//modemp[1].ProtectionRxState;
   case 0x3A : ret  = modemp[1].txAcmProfilesCounter[10]; break;//modemp[1].ProtectionRxState;
   case 0x3B : ret  = modemp[1].txAcmProfilesCounter[11]; break;//modemp[1].ProtectionRxState;
   case 0x3C : ret  = modemp[1].txAcmProfilesCounter[12]; break;//modemp[1].ProtectionRxState;
   case 0x3D : ret  = modemp[1].txAcmProfilesCounter[13]; break;//modemp[1].ProtectionRxState;
   case 0x3E : ret  = modemp[1].txAcmProfilesCounter[14]; break;//modemp[1].ProtectionRxState;
   case 0x3F : ret  = modemp[1].txAcmProfilesCounter[15]; break;//modemp[1].ProtectionRxState;
 
   case 0x40 : ret  = modemp[1].rxAcmProfilesCounter[0]; break;//modemp[1].ProtectionRxState;
   case 0x41 : ret  = modemp[1].rxAcmProfilesCounter[1]; break;//modemp[1].ProtectionRxState;
   case 0x42 : ret  = modemp[1].rxAcmProfilesCounter[2]; break;//modemp[1].ProtectionRxState;
   case 0x43 : ret  = modemp[1].rxAcmProfilesCounter[3]; break;//modemp[1].ProtectionRxState;
   case 0x44 : ret  = modemp[1].rxAcmProfilesCounter[4]; break;//modemp[1].ProtectionRxState;
   case 0x45 : ret  = modemp[1].rxAcmProfilesCounter[5]; break;//modemp[1].ProtectionRxState;
   case 0x46 : ret  = modemp[1].rxAcmProfilesCounter[6]; break;//modemp[1].ProtectionRxState;
   case 0x47 : ret  = modemp[1].rxAcmProfilesCounter[7]; break;//modemp[1].ProtectionRxState;
   case 0x48 : ret  = modemp[1].rxAcmProfilesCounter[8]; break;//modemp[1].ProtectionRxState;
   case 0x49 : ret  = modemp[1].rxAcmProfilesCounter[9]; break;//modemp[1].ProtectionRxState;
   case 0x4A : ret  = modemp[1].rxAcmProfilesCounter[10]; break;//modemp[1].ProtectionRxState;
   case 0x4B : ret  = modemp[1].rxAcmProfilesCounter[11]; break;//modemp[1].ProtectionRxState;
   case 0x4C : ret  = modemp[1].rxAcmProfilesCounter[12]; break;//modemp[1].ProtectionRxState;
   case 0x4D : ret  = modemp[1].rxAcmProfilesCounter[13]; break;//modemp[1].ProtectionRxState;
   case 0x4E : ret  = modemp[1].rxAcmProfilesCounter[14]; break;//modemp[1].ProtectionRxState;
   case 0x4F : ret  = modemp[1].rxAcmProfilesCounter[15]; break;//modemp[1].ProtectionRxState;


   case 0x50 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[0] ; break;//modemp[1].ProtectionRxState;
   case 0x51 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[1] ; break;//modemp[1].ProtectionRxState;
   case 0x52 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[2] ; break;//modemp[1].ProtectionRxState;
   case 0x53 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[3] ; break;//modemp[1].ProtectionRxState;
   case 0x54 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[4] ; break;//modemp[1].ProtectionRxState;
   case 0x55 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[5] ; break;//modemp[1].ProtectionRxState;
   case 0x56 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[6] ; break;//modemp[1].ProtectionRxState;
   case 0x57 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[7] ; break;//modemp[1].ProtectionRxState;
   case 0x58 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[8] ; break;//modemp[1].ProtectionRxState;
   case 0x59 : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[9] ; break;//modemp[1].ProtectionRxState;
   case 0x5A : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[10] ; break;//modemp[1].ProtectionRxState;
   case 0x5B : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[11] ; break;//modemp[1].ProtectionRxState;
   case 0x5C : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[12] ; break;//modemp[1].ProtectionRxState;
   case 0x5D : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[13] ; break;//modemp[1].ProtectionRxState;
   case 0x5E : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[14] ; break;//modemp[1].ProtectionRxState;
   case 0x5F : 	UsedExp.State.Reg2.bit.RAConf0 = 1;	 UsedExp.State.Reg2.bit.Some  = 1; //some load
			    ret  = modemp[0].modulation[15] ; break;//modemp[1].ProtectionRxState;

   case 0x60 :	UsedExp.State.Reg2.bit.AcmCnt0 = 1;	   break;

   case 0x61 :	UsedExp.State.Reg2.bit.AcmCnt1 = 1;	   break;

   case 0x62 :	UsedExp.State.Reg2.bit.MaskGet0 = 1;   break;

   case 0x63 :	UsedExp.State.Reg2.bit.MaskGet1 = 1;   break;

   case 0x64 :	UsedExp.State.Reg2.bit.AcmEn0 = 1;	   break;

   case 0x65 :	UsedExp.State.Reg2.bit.AcmEn1 = 1;	   break;

   case 0x66 :	UsedExp.State.Reg2.bit.AcmPrEn0 = 1;	   break;

   case 0x67 :	UsedExp.State.Reg2.bit.AcmPrEn1 = 1;	   break;

   case 0x68 :	UsedExp.State.Reg2.bit.AcmSw0 = 1;	   break;

   case 0x69 :	UsedExp.State.Reg2.bit.AcmSw1 = 1;	   break;

   case 0x6A :	UsedExp.State.Reg2.bit.AcmTr0 = 1;	   break;

   case 0x6B :	UsedExp.State.Reg2.bit.AcmTr1 = 1;	   break;


}
 return ret;
}

#endif

#ifndef PROG_BMDN6MI


extern "C" void GetTxtFile(unsigned long variant) //, unsigned char flagm)
{
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;



if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;

}

//UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
 //							 (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//unsigned long ir;
unsigned long config_delta;
unsigned long length;

//if(deviceindex == MODEM_QUANTITY)
//{
//for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
//{
// if(ModemIsUsed(im))
// {
 //____________________________________________________________
//variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
 //printf("curvar = %d",curvar);
//if(variant != curvar)
//{
// printf("read flash!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//__________________________________________________hier need read config_step
//unsigned long config_step;
#ifndef DO_NOT_READ_CONFIG_DELTA

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA)) 
#endif
 config_delta = CONFIG_FILE_PROVINGENT_STEP;
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	  
//#endif
//__________________________________________________config_step



//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));

//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
//}
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________


// ir = im << 1;
// ir = im;
//#ifndef USART0_TRY_PDC_1T
// printf("\n\r Load Synt_  %d", ir);
//#else
//#ifdef PRINT_START
//  printfpd("\n\r Load Synt :  %d", ir);
//#endif
//#endif
 //printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
// LoadSyntDatam(im, pBuffer);
//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//_______________________________________________________________
//_______________________________________________________________

//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
//printfpd("\n\r %lx", tmp);


pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
length = *pBuffer++;
//printf(" %X", *pBuffer);
length  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 24;

//if(length > TXT_REAL_LEN)	 length = TXT_REAL_LEN;
if(length > TXT_REAL_LEN)	 length = 0;

//printfpd("\n\r %lx", length);

//printfp("\n\r");
for(unsigned long its =0l; its < (length + 4); its++)
{
//  printfpd(" %c", TFTP_Buffer[its]);
}


//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 //  curvar = variant;
// }	  //used
// curvar = variant;
//}  //for
//}  //if

//}
 //curvar = 0xff+1;
}

#endif

unsigned char ScanTxtFilesNum[MAX_CFG_FILE_VARIANT];
unsigned long SavedTxtFilesVal;
//__________________________________________________________
extern "C" void ScanTxtFiles(void) //, unsigned char flagm)
{
//printfp("\n\r ScanTxtFiles");

BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;
//unsigned char variant = 0;
unsigned long variant = 0;

unsigned char flag;

for(long is = 0; is<MAX_CFG_FILE_VARIANT;is++)
{
  ScanTxtFilesNum[is] = 0;
}
 SavedTxtFilesVal = 0;
 /*
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;
}
*/
//UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
 //							 (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//unsigned long ir;
unsigned long config_delta;
//unsigned long length;

//if(deviceindex == MODEM_QUANTITY)
//{
//for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
//{
// if(ModemIsUsed(im))
// {
 //____________________________________________________________
//variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
 //printf("curvar = %d",curvar);
//if(variant != curvar)
//{
// printf("read flash!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//__________________________________________________hier need read config_step
//unsigned long config_step;
#ifndef DO_NOT_READ_CONFIG_DELTA

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
config_delta = *pBuffer++;
//printf(" %X", *pBuffer);
config_delta  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA)) 
#endif
 config_delta = CONFIG_FILE_PROVINGENT_STEP;
//#ifndef USART0_TRY_PDC_1T
//printf("\n\r config_delta : %d", config_delta);	  
//#endif
//__________________________________________________config_step

for(variant = 0; variant < MAX_CFG_FILE_VARIANT; variant++)
//for(variant = 0; variant < 5; variant++)	 //test
{

//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));

//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
//}
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________


// ir = im << 1;
// ir = im;
//#ifndef USART0_TRY_PDC_1T
// printf("\n\r Load Synt_  %d", ir);
//#else
//#ifdef PRINT_START
//  printfpd("\n\r Load Synt :  %d", ir);
//#endif
//#endif
 //printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
// LoadSyntDatam(im, pBuffer);
//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//_______________________________________________________________
//_______________________________________________________________

//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
 //101018							SYNT_DATA_OFFSET),
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
//printfpd("\n\r %lx", tmp);


//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
flag = 0;
 for(long i = 4; i < 16l; i++)
  {
  // printfpd(" %i:", i);
  // printfpd("%d", TFTP_Buffer[i]);

   if(TFTP_Buffer[i] != 0)
   {
     flag = 1;
  //	  printfp("set flag");
   }
  }

 if(!flag)
 for(i = 32l; i < 91l; i++)
  {
 //  printfpd("%c", TFTP_Buffer[i]);
    if(TFTP_Buffer[i] == ':')  //if sawed time 15:30
	{
    ScanTxtFilesNum[variant] = 1;
    SavedTxtFilesVal++; 
 //   	 printfpd("\n\r i = %d", i);  //for test
  //		  printfpd("\n\r v = %d", variant);
	 break;
	}
 //	 printf("\n\r XilFileData.Value[%d]= %c", i, XilFileData.Value[i]);  //for test

  }
  /*
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
length = *pBuffer++;
//printf(" %X", *pBuffer);
length  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 16;
//printf(" %X", *pBuffer);
length += (*pBuffer++) << 24;

if(length > TXT_REAL_LEN)	 length = TXT_REAL_LEN;

printfpd("\n\r %lx", length);

printfp("\n\r");
for(unsigned long its =0l; its < (length + 4); its++)
{
  printfpd(" %c", TFTP_Buffer[its]);
}
	*/
}// for variant
//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 //  curvar = variant;
// }	  //used
// curvar = variant;
//}  //for
//}  //if

//}
 //curvar = 0xff+1;

//printfpd("S> %d", SavedTxtFilesVal);
//for(is = 0; is<MAX_CFG_FILE_VARIANT;is++)
//{
//  if(ScanTxtFilesNum[is])
//  {
//   printfpd(">> %d", is);
//  }
//}


}
//__________________________________________________________
/*

extern "C" void printcurtxt()
{
	
   printfpd("\n\r%d",modemp[0].configfilefext.LengthTxt);
   printfp("\n\r");
     for(long i=0; i < modemp[0].configfilefext.LengthTxt; i++)
    {
        printfpd(" %02X", modemp[0].configfilefext.ConfigTxtData.Data[i]);
    }
	

}
*/

 extern "C" void SetACMMask(unsigned char deviceindex, unsigned char mask)
 {
  unsigned char ret;
  ret = PVG610_API_ModemAcmProfileEnable(  deviceindex, 0, mask);
//if ret != 0 - alarm

 }


#define ETH_COMMAND_PORT (0x7f)
#define ETH_STATE_PORT   (0x7E)
/*
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
   //		embMsg485Request_1.SetReadyToSend();
		   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
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
		//	embMsg485Request_2.SetReadyToSend();
		   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
		}
	 		else
		{
			outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
	  //		SaveParameterToNVRAM(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8) , embMsgRequest->Body(4));
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
	//	embMsg485Request_1.SetReadyToSend();
		   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
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
		  //	embMsg485Request_2.SetReadyToSend();
			   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
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

 */




#define  ZERO_REG (0)
#define  ZERO_REG_MOD (0x20)
#define  RELE_REG (0x12)
#define  INPUT_REG (0x13)


#ifndef PROG_BMDN6MI

void ReleTest()
{
 unsigned char receive1;
 static unsigned char test_char1;//, test_char1o;
  /*
 unsigned char receive2;
 static unsigned char test_char2, test_char2o;
   */
 //test_char1o = test_char1;
 outportb(RELE_REG,test_char1);
  test_char1 <<= 1;
  if(!test_char1) test_char1 = 1;
   /*
 test_char2 =  ~(test_char1);
  
 test_char2o = test_char2;
 outportb(ZERO_REG_MOD,test_char2++);
   */
 receive1 = inportb(INPUT_REG);

// if(test_char1o != receive1)
// {
// printfp("\n\rloc error wait");
// printfpd(" %02X",test_char1o);
// printfp( "have");
 printfpd("\n\r %02X",receive1);
  OperateBuffers_usart0t();

// }


  /*
 receive2 = inportb(ZERO_REG_MOD);

 if(test_char2o != receive2)
 {
 printfp("\n\r error2 wait");
 printfpd(" %02X",test_char2o);
 printfp( "have");
 printfpd(" %02X",receive2);
 }
	*/

 wd_reset();
}

void BusTest()
{
 unsigned char receive1;
 static unsigned char test_char1, test_char1o;
  /*
 unsigned char receive2;
 static unsigned char test_char2, test_char2o;
   */
 test_char1o = test_char1;
 outportb(ZERO_REG,test_char1++);
   /*
 test_char2 =  ~(test_char1);
  
 test_char2o = test_char2;
 outportb(ZERO_REG_MOD,test_char2++);
   */
 receive1 = inportb(ZERO_REG);

 if(test_char1o != receive1)
 {
 printfp("\n\rloc error wait");
 printfpd(" %02X",test_char1o);
 printfp( "have");
 printfpd(" %02X",receive1);
  OperateBuffers_usart0t();

 }
 else
 {	
 printfp("\rTest 8...Ok");
 OperateBuffers_usart0t();

 }

 // OperateBuffers_usart0t();

  /*
 receive2 = inportb(ZERO_REG_MOD);

 if(test_char2o != receive2)
 {
 printfp("\n\r error2 wait");
 printfpd(" %02X",test_char2o);
 printfp( "have");
 printfpd(" %02X",receive2);
 }
	*/
	wd_reset();

}


void BusTestFar()
{
 unsigned char receive1;
 static unsigned char test_char1, test_char1o;
  /*
 unsigned char receive2;
 static unsigned char test_char2, test_char2o;
   */
 test_char1o = test_char1;
 outportb(ZERO_REG_MOD,test_char1++);
   /*
 test_char2 =  ~(test_char1);
  
 test_char2o = test_char2;
 outportb(ZERO_REG_MOD,test_char2++);
   */
 receive1 = inportb(ZERO_REG_MOD);

 if(test_char1o != receive1)
 {
 printfp("\n\r mod error wait");
 printfpd(" %02X",test_char1o);
 printfp( "have");
 printfpd(" %02X",receive1);
  OperateBuffers_usart0t();
 }
 else
 {	
 printfp("\rTest 9...Ok");
 OperateBuffers_usart0t();

 }
// OperateBuffers_usart0t();
  /*
 receive2 = inportb(ZERO_REG_MOD);

 if(test_char2o != receive2)
 {
 printfp("\n\r error2 wait");
 printfpd(" %02X",test_char2o);
 printfp( "have");
 printfpd(" %02X",receive2);
 }
	*/
	wd_reset();

}




extern "C" void LoadReg_5C3F_2(unsigned char deviceIndex)
{
/*
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterWrite(BYTE               deviceIndex,
                                               BYTE               modemIndex,
                                               UINT16             offset,
                                               BOOLEAN            xpicSlave,
                                               UINT16             val)
*/


}

#endif

void PrintConfigs(void)
{
  unsigned long itxt = 0l;
 // for(unsigned variant = 0; variant < MAX_NUM_CFG; variant++)
  for(unsigned variant = 0; variant < 15; variant++)
  {
   itxt = 0l;
   printfp("\n\r_________file number:");
   printfpd(" %d \n\r", variant);
   for(unsigned long its = FULL_HEADER_SIZE + 4l; its < (TXT_REAL_LEN + 4l); its++)
	{
       if(!(itxt%16))printfpd ("\n\r %X>", itxt);
	   printfpd(" %02X", modemp[0].configfilefext1[variant].ConfigTxtData.Data[itxt++]);
	}
	OperateBuffers_usart0t();
	wd_reset();
  }
}


//#define STATUS_ETH_PORT (0x1D)
#define E1000 (0x4)
extern unsigned char OldStatus;

void EthStatusGetXil1()
{
// static unsigned char laststate;
 // static unsigned char OldStatus;

  unsigned char Status = inportb(BLOCK_SWEEP1 + STATUS_ETH_PORT);

//  unEmb2TypeVer.emb2TypeVer.signature_hardware[5] =	Status;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = (GetModEth() & ETH_AUTO) +((Status & 0x1f) << 1) + (GetModForSS1() << 7); //

#ifdef PRINT_ETH
printfpd("\n\rxil: %02X",Status);
printfpd(" sign_hw5: %02X",unEmb2TypeVer.emb2TypeVer.signature_hardware[5]);

#endif

if(GetModEth() & ETH_AUTO)
{
 if(Status != OldStatus)
 {
	if(!(Status & E1000))
	{
//delay_mcs(100000l);

	EthStatusSet1(0, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  //			  0,  0);
				  1,  0);

EthStatusSet1(1, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  //			  0,  0);
				  1,  0);




delay_mcs(500000l);
EthStatusSet1(0, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  			  0,  0);


EthStatusSet1(1, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  			  0,  0);

			 //	  1,  0);

	#ifdef PRINT_ETH
printfp("\n\rset 100M");
#endif

	}
	else
	{
//delay_mcs(100000l);

	EthStatusSet1(0, 1, 2,	  //1G
				  1, 0,
				  1,  0,
	//			  0,  0);
					  1,  0);

EthStatusSet1(1, 1, 2,	  //1G
				  1, 0,
				  1,  0,
	//			  0,  0);
					  1,  0);

delay_mcs(500000l);

EthStatusSet1(0, 1, 2,	  //1G
				  1, 0,
				  1,  0,
				  0,  0);

EthStatusSet1(1, 1, 2,	  //1G
				  1, 0,
				  1,  0,
				  0,  0);

			  //		  1,  0);  //reset


#ifdef PRINT_ETH
printfp("\n\rset 1G");
#endif


	}
    OldStatus = Status;

 }
}
else
	{
#ifdef PRINT_ETH
printfp("\n\r mode no auto ");
printfpd("mode_eth: %02X",GetModEth());
#endif

 //	}



 }
 /*
else
	{
#ifdef PRINT_ETH
printfp("\n\r mode no auto ");
printfpd("mode_eth: %02X",GetModeEth());
#endif

	}
 */





}

void EthStatusGetXil()
{
// static unsigned char laststate;
 // static unsigned char OldStatus;

unsigned char dev = 0;
unsigned char auton = 1;
unsigned char speed;
unsigned char duplex;
unsigned char loop = 0;
unsigned char interf;
unsigned char phyId = 0;
unsigned char reset = 1;
unsigned char changephy = 0;



  unsigned char Status = inportb(BLOCK_SWEEP1 + STATUS_ETH_PORT);

switch (Status & 0x1f)
{
  case 1: speed = 0;  duplex = 0; interf = 0; SetMEthModeI(0); break; //10h
  case 2: speed = 1;  duplex = 0; interf = 0; SetMEthModeI(1); break; //100h
  case 4: speed = 2;  duplex = 0; interf = 1; SetMEthModeI(2); break; //1000h
  case 9: speed = 0;  duplex = 1; interf = 0; SetMEthModeI(3); break; //10f	
  case 10: speed = 1; duplex = 1; interf = 0; SetMEthModeI(4); break; //100f	
  case 12: speed = 2; duplex = 1; interf = 1; SetMEthModeI(5); break; //1000f	
  case 20: speed = 2; duplex = 0; interf = 1; SetMEthModeI(6); break; //1000lxh	
  case 28: speed = 2; duplex = 1; interf = 1; SetMEthModeI(7); break; //1000lxf	
  default : speed = 2; duplex = 1; interf = 1; SetMEthModeI(8); break;       //no link
}



 // auton =	 GetModEth() & ETH_AUTO;
//hier need check and load


//  unEmb2TypeVer.emb2TypeVer.signature_hardware[5] =	Status;
  unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = (GetModEth() & ETH_AUTO) +((Status & 0x1f) << 1) + (GetModForSS1() << 7); //

#ifdef PRINT_ETH
printfpd("\n\rxil: %02X",Status);
printfpd(" sign_hw5: %02X",unEmb2TypeVer.emb2TypeVer.signature_hardware[5]);

#endif

if(GetModEth() & ETH_AUTO)
{
 //150703 if(Status != OldStatus)
 if((Status != OldStatus)  && (Status & 0x1f)) //150703
 {

#ifdef PRINT_ETH
printfp("\n\r change eth mode to: \n\r ");
printfpd(" speed: %d ",speed);
printfpd(" duplex: %d ",duplex);
printfpd(" interf: %d ",interf);

#endif



EthStatusSet1( dev, auton, speed, duplex, loop,	interf, phyId, reset, changephy);
EthStatusSet1( 1, auton, speed, duplex, loop,	interf, phyId, reset, changephy);

delay_mcs(500000l);
reset = 0;
EthStatusSet1( dev, auton, speed, duplex, loop,	interf, phyId, reset, changephy);
EthStatusSet1( 1, auton, speed, duplex, loop,	interf, phyId, reset, changephy);







   /*



	if(!(Status & E1000))
	{
//delay_mcs(100000l);

	EthStatusSet1(0, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  //			  0,  0);
				  1,  0);
delay_mcs(500000l);
EthStatusSet1(0, 1, 1,	   //100 mB
				  1, 0,
				  0,  0,
	  			  0,  0);
			 //	  1,  0);

	#ifdef PRINT_ETH
printfp("\n\rset 100M");
#endif

	}
	else
	{
//delay_mcs(100000l);

	EthStatusSet1(0, 1, 2,	  //1G
				  1, 0,
				  1,  0,
	//			  0,  0);
					  1,  0);
delay_mcs(500000l);

EthStatusSet1(0, 1, 2,	  //1G
				  1, 0,
				  1,  0,
				  0,  0);
			  //		  1,  0);  //reset


#ifdef PRINT_ETH
printfp("\n\rset 1G");
#endif


	}


	 */



    OldStatus = Status;

 }
}
else
	{
#ifdef PRINT_ETH
printfp("\n\r mode no auto ");
printfpd("mode_eth: %02X",GetModEth());
#endif

    }

}




void EthStatusGet()
{
 PVG610_NET_ETH_STATUS_STRUCT   pEs;
 PVG610_API_NetEthStatusGet(0, 0, &pEs);
   /*
 typedef struct {
BYTE autoNegotiation; // 0 - disabled, 1- enabled
BYTE speed; // 0 - 10Mbps, 1 - 100Mbps, 2 - 1000Mbps
BYTE duplex; // 0 - half duplex, 1- full duplex
BYTE loopback; // 0 - normal operation, 1- loopback enabled
BYTE interfaceMode; // 0 - MII 10/100Mbps, 1- GMII 1000Mbps
BYTE phyId; // phyId
BYTE reset; // 0 - disabled, 1- enabled
BYTE changePhyId; // 0 - use phyId from configuration file, 1 - change to user's phy id
} PVG610_NET_ETH_STATUS_STRUCT;
*/
  /*
#ifdef PRINT_ETH
printfpd("\n\ra %02X",pEs.autoNegotiation);
printfpd("\n\rs %02X",pEs.speed);
printfpd("\n\rd %02X",pEs.duplex);
printfpd("\n\rl %02X",pEs.loopback);
printfpd("\n\ri %02X",pEs.interfaceMode);
printfpd("\n\rp %02X",pEs.phyId);
printfpd("\n\rr %02X",pEs.reset);
printfpd("\n\rc %02X",pEs.changePhyId);
#endif
 */
}

void EthStatusSet()
{
 PVG610_NET_ETH_STATUS_STRUCT   pEs;
pEs.autoNegotiation = 0;
pEs.speed = 2;	 //1g 
pEs.duplex = 1;
pEs.loopback = 0;
pEs.interfaceMode = 1; // 1g
pEs.phyId = 0;
pEs.reset = 0;
pEs.changePhyId = 0;


  PVG610_API_NetEthParamsSet(0, 0, &pEs);
}

void EthStatusSet1(unsigned char dev, unsigned char auton, unsigned char speed,
				  unsigned char duplex, unsigned char loop,
				  unsigned char interf,  unsigned char phyId,
				  unsigned char reset,  unsigned char changephy )
{
 PVG610_NET_ETH_STATUS_STRUCT   pEs;
pEs.autoNegotiation = auton;
pEs.speed = speed;	 //1g 
pEs.duplex =duplex;
pEs.loopback = loop;
pEs.interfaceMode = interf; // 1g
pEs.phyId = phyId;
pEs.reset = reset;
pEs.changePhyId = changephy;

#ifdef PRINT_ETH
 printfpd("\n\r VG610_API_NetEthParamsSet dev  %d", dev);
 printfpd("speed : %d", speed);
  printfpd("duplex : %d", duplex);


#endif


  PVG610_API_NetEthParamsSet(dev, 0, &pEs);
}





#ifdef SEND_STATUS
//#define	 DEFAULT_ADDR	(0xBEEF)

extern unsigned char racm, racm_far, flag_racm_far;
extern float64 MEbN0_UP, MEbN0_DOWN;


//void ReceiveStatus()
unsigned long ReceiveStatus()
{
  MEbN0_UP  = MEbN0_UP_DEFAULT;
  MEbN0_DOWN	 = 	MEbN0_DOWN_DEFAULT;
  unsigned long ret = 0;

	int ic=0;
	int i = 0;
	static char test23 = 0;
	unsigned char req = 0;
	static unsigned long oldtime[MODEM_QUANTITY];

	unsigned long curerr1;
	static unsigned long curerr1_old;

	unsigned long curerr2;
	static unsigned long curerr2_old;
	static unsigned char flag_min_max;




 unsigned char * pMbx;
 unsigned long len;
 unsigned char ver_prot;
 unsigned char signatura;
 



 pMbx = ModemMailboxMessageReceive();


 if(pMbx != NULL)
 {
 ret = 1;
   len = *pMbx++;
 //  len <<= 8;
    pMbx++;

  //	printfpd("\n\r message len : %d " , len);
//mailbox will be parsed hier  

   signatura = 	*(pMbx + (unsigned long)22);   //13	
   ver_prot  = 	*(pMbx + (unsigned long)23);   //14	

     flag_racm_far = 1;
   racm_far = 	*(pMbx + (unsigned long)21);	 //body 12

 if(ver_prot >= 3)
 {
   timestep_far =	 (*(pMbx + (unsigned long)24) << 8) +  *(pMbx + (unsigned long)25);
   flag_racm_fart = 1;

 }


 //if(GetTestMode() == 0x50)
  // {
//   printfpd("\n\r received racm_far : %d " , racm_far);
//   printfpd("signatura : 0x%02X " , signatura);
//	 printfpd("ver_prot : %d " , ver_prot);
//	 printfpd("timestep_far : %d " , timestep_far);
// }


	/*
//____________________________________________________
 recieveWest[i] = 1; ready_mod[i]=1; time3BlankMod[i] = time1; embMsgWest[i].Init();		

   //	while(embSerialACT155.UsedMod(i))
   while(len--)
	{
		//	westByte = embSerialACT155.GetMod(i);
			westByte = *pMbx++;

#ifdef DEBUG_LOOP_PRINT
	 		printfpd("_%02X_", westByte);
#endif		
			switch(westByte)
			{
			case 0x55: time3BlankMod[i] = time1; ready_mod[i]=1; recieveWest[i]=0; embMsgWest[i].Init(); break; 			
			case 0xAA: recieveWest[i] = 1; ready_mod[i]=1; time3BlankMod[i] = time1; embMsgWest[i].Init();	break; 			
			case 0xA5: recieveWest[i] = 1; modeA5West[i]=1; markerWest[i]  = 1; ready_mod[i]=1; time3BlankMod[i] = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest[i]=1; ready_mod[i]=1; break;
			default:
				if(markerWest[i]==1)	markerWest[i]=2; 
				if(recieveWest[i]==1)
				{
				 if(modeA5West[i]) { embMsgWestR[i].Add(westByte); modeA5West[i]=0;	
				 
				 }
					else if(mode5AWest[i]) { embMsgWest[i].Add(Modify5A(westByte)); mode5AWest[i]=0;	}
				  //	else if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
					else embMsgWest[i].Add(westByte);
				}
			}

if(embMsgWest[i].IsEnd())
   {
	 printf("\n\r ...Isend \n\r");
//ok  printEthLongHex(embMsgWest[i].AddrS());

   recieveWest[i] = 0;
#ifdef CHECK_CRC   
  if(embMsgWest[i].ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
	{						   //091111
//ok	  printEthLongHex(embMsgWest[i].AddrS());

#ifdef SEND_STATUS	
 if(embMsgWest[i].AddrS() == DEFAULT_ADDR)
 {

//?? need check crc?
#ifdef DEBUG_LOOP_PRINT
  printfpd("\n\r %02X",embMsgWest[i].Body(0));	  //far dev_status	 
  printfpd(" %02X",embMsgWest[i].Body(1)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(2)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(3)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(4)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(5)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(6)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(7)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X",embMsgWest[i].Body(8)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd(" %02X\n\r",embMsgWest[i].Body(9)); 	 //far lock 	unStatePUM.statePUM.state[2]
  printfpd("racm : %02X\n\r",embMsgWest[i].Body(12));  //racm
#endif
 //	  CHANNEL1_LOCK_BIT
 //	  CHANNEL2_LOCK_BIT
if((embMsgWest[i].Body(13) == SIGNATURA)  && (embMsgWest[i].Body(14) >= 2))
{
 racm_far = embMsgWest[i].Body(12);
 flag_racm_far = 1;
}

curerr1 = (embMsgWest[i].Body(2) << 24) + (embMsgWest[i].Body(3) << 16) + 
			   (embMsgWest[i].Body(4) << 8) + embMsgWest[i].Body(5);

  if((embMsgWest[i].Body(0) & PROV0_MASK) &&
	  (embMsgWest[i].Body(0) & P710_0_MASK) &&
	  	  (!(embMsgWest[i].Body(1) & CHANNEL1_LOCK_BIT)))	 //inversion
		  {
		   if((curerr1 - curerr1_old) < FAR_ERR_TRESHOLD)
			   {
			  		req |= FAR1_GREEN;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 ok");
#endif
			   }
			   else
			   {
			   //yellow
			  		req |= FAR1_GREEN;
					req |= FAR1_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 ok + err");
#endif

			   }


		  }
		  else
		  {	
		  			 req |= FAR1_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch1 bad");
#endif

		  }

curerr1_old = curerr1;

curerr2 = (embMsgWest[i].Body(6) << 24) + (embMsgWest[i].Body(6) << 16) + 
			   (embMsgWest[i].Body(8) << 8) + embMsgWest[i].Body(9);

farinplev1 = -85  + (signed long)(embMsgWest[i].Body(10)>>1);
farinplev2 = -85  + (signed long)(embMsgWest[i].Body(11)>>1);

  if((embMsgWest[i].Body(0) & PROV1_MASK) &&
	  (embMsgWest[i].Body(0) & P710_1_MASK) &&
	  	  (!(embMsgWest[i].Body(1) & CHANNEL2_LOCK_BIT)))	 //inversion
		  {
	      	 if((curerr2 - curerr2_old) < FAR_ERR_TRESHOLD)
			   {
			  	req |= FAR2_GREEN;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 ok");
#endif

			  }
			  else
			     {
			  	req |= FAR2_GREEN;
				req |= FAR2_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 ok + err");
#endif

			  }
		  }
		  else
		  {
			 req |= FAR2_RED;
#ifdef DEBUG_LOOP_PRINT
 printfp("ch2 bad");
#endif

		  }
  curerr2_old = curerr2;

   oldtime[i] =  time1;
   outportb((BLOCK_SWEEP1*(i + 1) + FAR_LED_PORT), req);

  embMsgWest[i].Init();	 //121204
 //  return 0;
 }
#endif //send status

   } 	//is end

 } //crc

 }	//while
//____________________________________________________

   */


 }	//pmbx


  return ret;

}

void SendStatus()
{
//static unsigned char  cyclest;
EmbMsg StatusMsg;

if(GetTestMode() != 1) return; //to not crash tests

 StatusMsg.Init();
StatusMsg.SetAddrI(SelfID());	//sender
StatusMsg.SetAddrS(DEFAULT_ADDR);	//receiver
StatusMsg.SetAddrR(0x2222);	//receiver

StatusMsg.SetType(0xEE);
//StatusMsg.SetLength(2);
//121024StatusMsg.SetLength(10);
//160310StatusMsg.SetLength(12);
//StatusMsg.SetLength(15); //160310 add racm
StatusMsg.SetLength(17); //160310 add ratimestep

StatusMsg.SetBody(0,dev_status);
StatusMsg.SetBody(1,unStatePUM.statePUM.state[2]);
StatusMsg.SetBody(2,modemp[0].fecUncorrectedBlockCounter >> 24);
StatusMsg.SetBody(3,modemp[0].fecUncorrectedBlockCounter >> 16);
StatusMsg.SetBody(4,modemp[0].fecUncorrectedBlockCounter >>  8);
StatusMsg.SetBody(5,modemp[0].fecUncorrectedBlockCounter 	  );
StatusMsg.SetBody(6,modemp[1].fecUncorrectedBlockCounter >> 24);
StatusMsg.SetBody(7,modemp[1].fecUncorrectedBlockCounter >> 16);
StatusMsg.SetBody(8,modemp[1].fecUncorrectedBlockCounter >>  8);
StatusMsg.SetBody(9,modemp[1].fecUncorrectedBlockCounter 	 );
StatusMsg.SetBody(10,unStateBMD155.stateBMD155.ppu1_bytes[3] );
StatusMsg.SetBody(11,unStateBMD155.stateBMD155.ppu2_bytes[3] );
StatusMsg.SetBody(12, racm); //send radian acm info
StatusMsg.SetBody(13, SIGNATURA);
StatusMsg.SetBody(14, RROT_VER);
//StatusMsg.SetBody(15,Get_ratimestep()>>8);
//StatusMsg.SetBody(16,Get_ratimestep());




//StatusMsg.SetCycle(cyclest++);
StatusMsg.SetCycle(8);
StatusMsg.CalcCRC();

//  extern "C" unsigned char ModemMailboxMessageSend(unsigned short msgLen, unsigned char * pData)


//160311 DO NOT WORKING INTERRUPTS!!! tBuffEmbMsgEast.Add(StatusMsg);	  //
ModemMailboxMessageSend(32, (unsigned char *)&StatusMsg.body[0]);

#ifdef DEBUG_LOOP_PRINT
// printfp(" send ");
#endif
}

#endif



#include "operateprogram.cpp"



#ifdef USE_CALIBR

#include "calibr.cpp"

#endif


#ifdef CHECK_LOSS_MEM
 extern uint_32 Stephany11;
 extern uint_32 Stephany0;
 extern uint_32 Stephany1;
 extern uint_32 Stephany2;
 extern uint_32 Stephany3;
 extern  unsigned long ipe_test_counter;
extern unsigned long tcp_ip_debug_cnt;
extern  unsigned long  ul_pointer_bd;
extern  unsigned long  enet_recv_point;

extern "C" void checklossmem()
{
wd_reset();
int *p;
unsigned long * pTransmitStatusRegister;
 pTransmitStatusRegister = 	(unsigned long *)(0xfffbc014);

unsigned long free_size;

unsigned char status_modem =  inportb(STEP_ADDR + PROV_MODEM_STATUS);
//unsigned char irqm_modem   = inportb(STEP_ADDR + PROV_IRQ_ADDR_MOD);
unsigned char maskm_modem = inportb(STEP_ADDR + PROV_MASK_ADDR_MOD);


p = malloc(50*sizeof(int));
	 free_size =  (0x21E00000);
	  free_size -= (unsigned long)p;
//printfpd("\n\rp>0x%X ", (unsigned long)p);
//printfpd(" e>0x%X ", (unsigned long)TFTP_BUFFER_ADDRESS);
//printfpd("free ram>0x%lX ", free_size);
printfpd("\n\r irq0s>%ld ",Stephany11);
printfpd("\n\r enet_isr>%ld ",Stephany0);
printfpd(" enet_trnsm>%ld ",Stephany1);
printfpd(" enet_rcv>%ld ",Stephany2);
printfpd(" enet_rx_buff_not_av>%ld ",Stephany3);
printfpd(" \n\rmodem_bytes_counter>%ld ",modem_bytes_counter);
printfpd(" transit_bytes_counter>%ld ",transit_bytes_counter);
printfpd("\n\r txtrans>%ld ",txtrans);
printfpd(" rxtrans>%ld ",rxtrans);
printfpd(" txmod>%ld ",txmod);
printfpd(" rxmod>%ld ",rxmod);

printfpd(" \n\rtrans_status>0x%lX ",*pTransmitStatusRegister);
printfpd(" tcp_ip_debug_cnt>%ld ",tcp_ip_debug_cnt);
printfpd(" ipe_test_counter>%ld ",ipe_test_counter);
printfpd("\n\r ul_pointer_bd>%ld ",ul_pointer_bd);
printfpd("enet_recv_point>%ld ",enet_recv_point);
//printfpd("stat mod>0x%02X",status_modem);
//printfpd("stat mod>0x%02X", status_modem);
//printfpd("maskm mod>0x%02X", maskm_modem);


//unsigned long * pEMAC;
 /*
pEMAC = (unsigned long *)0xFFFBC000l;
printfpd("\n\rCTL 0x%08X", *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC004l;
printfpd(" CFG 0x%08X",    *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC008l;
printfpd(" SR 0x%08X",    *(pEMAC));



pEMAC = (unsigned long *)0xFFFBC00Cl;
printfpd("\n\rTAR 0x%08X", *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC010l;
printfpd(" TCR 0x%08X",    *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC018l;
printfpd(" RBQP 0x%08X",    *(pEMAC));
//pEMAC = (unsigned long *)0xFFFBC020l;
//printfpd(" RS 0x%08X",    *(pEMAC));
 */

 /*
pEMAC = (unsigned long *)0xFFFBC000l;
printfpd("\n\rCR 0x%08X", *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC004l;
printfpd(" CFGR 0x%08X",    *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC008l;
printfpd(" SR 0x%08X",    *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC00Cl;
printfpd(" TAR 0x%08X",    *(pEMAC));

pEMAC = (unsigned long *)0xFFFBC010l;
printfpd("\n\rTCR 0x%08X",*(pEMAC));
pEMAC = (unsigned long *)0xFFFBC014l;
printfpd(" TSR 0x%08X",   *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC018l;
printfpd(" RBQP 0x%08X",  *(pEMAC));
pEMAC = (unsigned long *)0xFFFBC120l;
printfpd(" RSR 0x%08X",   *(pEMAC));
//printfpd("\n\rCR 0x%08X",  *(pEMAC + 0x120));
pEMAC = (unsigned long *)0xFFFBC124l;
printfpd("\n\rISR 0x%08X",  *(pEMAC));

pEMAC = (unsigned long *)0xFFFBC130l;
printfpd("\n\rIMR 0x%08X",  *(pEMAC));

 */

printfpd(" time1>0x%ld\n\r", time1);


free(p);
}
#endif

extern "C" void MaskIrq0()
{
embSerialACT155.MaskAll();
}

extern "C" void UnMaskIrq0()
{
embSerialACT155.UnMaskAll();
}

extern "C" void MaskReceive()
{
embSerialACT155.MaskReceive();
}

extern "C" void UnMaskReceive()
{
embSerialACT155.UnMaskReceive();
}

extern "C" unsigned char ForwardingEnabled()
{
unsigned char status = inportb(PROV_STATUS_TRANZIT_ADDR);
if((status & (unsigned char)(DIS_R)) || (status & (unsigned char)(DIS_R)))
{
 return 0;
}
 return 1;
}
