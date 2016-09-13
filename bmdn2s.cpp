
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



double KoefErrors[MODEM_QUANTITY << 1];


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


void ResetWatchDog()
{

};

#define SIZE_KEEP_15MIN_STAT  (4*24)	//1 day
#define SEC15MIN (60 * 15)
#define TIME_OF_15_MIN	  ((SEC15MIN) * BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) //

class StatRez
{
public:
 unsigned long Stat15minArc[SIZE_KEEP_15MIN_STAT];
 unsigned long Current15MinCounter;
 void Init(void);
 unsigned long timeto15min;
 void UpdateStat(unsigned char);
 void Update15Min(void);
 unsigned long PointerToCur15Min;
 unsigned long GetCounter(unsigned long);
 unsigned long GetCurrentCounter(void);
};

void StatRez::Init(void)
{
 for (long i = 0; i < SIZE_KEEP_15MIN_STAT; i++)
 {
  Stat15minArc[i] = 0;
 }
  Current15MinCounter = 0;
  timeto15min = 0;
  PointerToCur15Min = 0;
}

void StatRez::UpdateStat(unsigned char used)
{
 if(used) Current15MinCounter++;
 timeto15min++;
 if(timeto15min >= TIME_OF_15_MIN)
 {
  timeto15min = 0;
  Update15Min();
 }
}

void StatRez::Update15Min()
{
  Stat15minArc[PointerToCur15Min] = Current15MinCounter;
  Current15MinCounter = 0;
  PointerToCur15Min++;

  if(PointerToCur15Min>= SIZE_KEEP_15MIN_STAT)
  {
	PointerToCur15Min = 0;
  }
}
// nomber = 0  - current finished 15 min


unsigned long StatRez::GetCounter(unsigned long number)
{
 if(number >= SIZE_KEEP_15MIN_STAT)
 {
	return 0xFFFFFFFF;
 }

  if(number <= PointerToCur15Min) {return Stat15minArc[PointerToCur15Min - number];}
  else {return Stat15minArc[PointerToCur15Min +  (SIZE_KEEP_15MIN_STAT -  number)];}
}

unsigned long StatRez::GetCurrentCounter()
{
   return Current15MinCounter;
}











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



class ModemP
{
public :
 unsigned char ConfigNumber;
 unsigned long Mode;
 unsigned char isrezerv;
 unsigned char usednow;
 unsigned char LoadProg(void);
 unsigned char LoadConfig(void);
 unsigned long CurrentErrors;
 unsigned char Init();
UINT32 fecBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 fecUncorrectedBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 rsByteCounter; // cumulative, clear on read
UINT32 rsErrorByteCounter; // cumulative, clear on read
UINT16 ldpcAvgIterations; // in 1/256 iterations units
BYTE viterbiNormalRate;
BYTE reserved;
UINT32 protectionRxBytesFromProtection; // Current bytes received from the protection // replacing erroneous bytes from the working device
UINT32 protectionUncorrectedBytes;
BYTE acquireStatus;
//_______________________________

UINT16 absoluteMseTenths;
UINT16 normalizedMseTenths;
UINT16 radialMseTenths;
UINT16 counterSlip;	//this is 



//printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
//printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
//printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);

};

 unsigned char ModemP::Init()
{

 return 0;
}

 double CheckErrors(unsigned char im)
{
//im - channel
// CurrentErrors = 0;



 return KoefErrors[im];
// return 0;
}





uLevelSN15503	 ulevelsn15503;
uErrSN15503Work	 uerrsn15503work;


unsigned char staterezerv;

ModemP modemp[MODEM_QUANTITY << 1];


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
   printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
   printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);

   /*
printf("\n\r lastAcquireError : %02X" , Ms.lastAcquireError);
printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);
printf("\n\r internalAgc : %d" , Ms.internalAgc);
printf("\n\r externalAgcRegister : %X" , Ms.externalAgcRegister);
printf("\n\r carrierOffset : %d" , Ms.carrierOffset);
printf("\n\r rxSymbolRate : %d" , Ms.rxSymbolRate);
printf("\n\r txSymbolRate : %d" , Ms.txSymbolRate);
printf("\n\r ldpcDecoderStress : %X" , Ms.ldpcDecoderStress);
printf("\n\r txAcmProfile : %02X" , Ms.txAcmProfile);
printf("\n\r rxAcmProfile : %02X" , Ms.rxAcmProfile);
printf("\n\r acmEngineEnabled : %d" , Ms.acmEngineEnabled);
printf("\n\r debugIndications : %02X" , Ms.debugIndications);
*/

   ir++;
   printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
   printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
 }
 }
 }
 else
 {
  ir = flagm << 1;
   printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
   printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
   ir++;
   printf("\n\r ModemStatusGetm : %d", ir);
   PVG610_API_ModemStatusGet(ir, 0, &Ms);
   printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);

 }
}



extern "C" void ConfigFileRunm(unsigned char flagm)
{
unsigned long ir;

if(flagm == MODEM_QUANTITY)
{

 for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
 {
  if(ModemIsUsed(im))
 {
  ir = im << 1;
  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
  printf("...%d", PVG610_API_ConfigFileRun (ir,0));
  ir++;
  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
   printf("...%d",PVG610_API_ConfigFileRun (ir,0));
 }
}
}
else
{
  ir = flagm << 1;
  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
  printf("...%d", PVG610_API_ConfigFileRun (ir,0));
  ir++;
  printf("\n\r PVG610_API_ConfigFileRun  %d", ir);
   printf("...%d",PVG610_API_ConfigFileRun (ir,0));

}
}

extern "C" void ConfigFileLoadm(unsigned long variant, unsigned char flagm)
{
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_STATUS_STRUCT *pMs;
pMs = &Ms;
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;
}

UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT32 config_delta;
unsigned long ir;

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
 //____________________________________________________________
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;

// printf("\n\r curvar = %d", curvar);
if(variant != curvar)
{
// printf("\n\r ..read flash !!!!");
//101223 len = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));

//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
//101006read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP)),
//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
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
config_delta += (*pBuffer++) << 18;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  config_delta = CONFIG_FILE_PROVINGENT_STEP;
printf("\n\r config_delta lcf : %d", config_delta);	  

//_________________________________________________101221


read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + (variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________101221




//_____________________________________________________________
//______________________________________________101006
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 18;
len += (*pBuffer++) << 24;
//_____________________________________________________________



 ir = im << 1;
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  var: % d conf_del: %d num : %d ",variant, config_delta, ir);
 printf("\n\r...%d len %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);

//_______________________________________________________________
 //pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
 pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
// for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP; dr++)
// {
//   pBuffer++;
// }

// for(long dr = 0; dr < 2; dr++)
//101018 for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP - 0x60; dr++)	//<<<<<<<to hier need config_step
for(long dr = 0; dr < config_delta - 0x60; dr++)	//<<<<<<<to hier need config_step
// for(long dr = 0; dr < (CONFIG_FILE_PROVINGENT_STEP - 0x60 - 4l); dr++)   //101006
 {
   pBuffer++;
 }

//______________________________________________101006
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 18;
len += (*pBuffer++) << 24;
//_____________________________________________________________


//_______________________________________________________________
//_______________________________________________________________

//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
  /*
for(unsigned long its =0l; its < 64l; its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", *pBuffer);
   pBuffer++;
}
 */

/*
for(unsigned long its =0l; its < 48l; its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

for(its =0x1720l; its < (0x1720+48l); its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

for(its = 0; its < ProvSizeToDownloadDCfgFile; its++)
{
  if(TFTP_Buffer[its] != TFTP_Buffer[its + CONFIG_FILE_PROVINGENT_STEP])
 printf("\n\r its: %d", its);
 }

*/


//_____________________________________________________________


 ir++;
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d  len: %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);
   curvar = variant;

 }
 // curvar = variant;
}	//for
}	//if
else
{
 //____________________________________________________________
variant =  GetNumConfigFile(flagm) & CONFIG_FILE_MASK;

//101223 len = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//101006read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP)),
//________________________________________________
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
config_delta += (*pBuffer++) << 18;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  config_delta = CONFIG_FILE_PROVINGENT_STEP;
printf("\n\r config_delta lcf : %d", config_delta);	  
//_________________________________________________


read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + (variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________

/*
for(unsigned long its =0l; its < 48l; its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

for(its =(7301 - 48); its < (7301); its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

 */

//______________________________________________101006
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 18;
len += (*pBuffer++) << 24;
//_____________________________________________________________



//______________________________________________________________



ir = flagm << 1;
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d len : %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);

//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//101018  for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP - 0x60; dr++)
 for(long dr = 0; dr < config_delta - 0x60; dr++)
 {
   pBuffer++;
 }

//______________________________________________101006
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 18;
len += (*pBuffer++) << 24;
//_____________________________________________________________


//_______________________________________________________________
/*
printf("\n\r>");

 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);


for(unsigned long its =0l; its < 100l; its++)
{
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
}

 */
//_____________________________________________________________


 ir++;
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d len : %d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len), len);



}
 curvar = 0xff+1;
}


//_________________________________________________________________________

extern "C" void ConfigDataLoadm(unsigned long variant, unsigned char flagm)
{
  printf("\n\r ConfigDataLoadm");
//PVG610_MODEM_STATUS_STRUCT	Ms;
//PVG610_MODEM_STATUS_STRUCT *pMs;
//pMs = &Ms;
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long file_size_readed;

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;
}

//UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
//unsigned long ir;

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
 //____________________________________________________________
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
//variant = 0; //for test!
// printf("\n\r curvar = %d", curvar);
if(variant != curvar)
{
// printf("\n\r ..read flash !!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;

//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP)),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
//__________________________________________________________________________________
//hier need read file size

read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));

//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
printf("\n\r file size  : %X", *pBuffer);
file_size_readed = *pBuffer++;
printf(" %X", *pBuffer);
file_size_readed  += (*pBuffer++) << 8;
printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 18;
printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 24;
printf("\n\r file_size_readed : %d", file_size_readed);
//_____________________________________________________________

 if((file_size_readed < MIN_CFG_FILE_SIZE) || (file_size_readed > MAX_CFG_FILE_SIZE)) file_size_readed = FILE_SIZE;

printf("\n\r file_size_readed : %d", file_size_readed);




//__________________________________________________________________________________





 read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS  -  FULL_HEADER_SIZE - FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) +
//101018  (FILE_SIZE - NUMBER_OFFSET)),
	 (file_size_readed - NUMBER_OFFSET)),
							 (unsigned int)NUMBER_OFFSET, (char *)(&TFTP_Buffer[0]));

}
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________


// ir = im << 1;
 /*
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  variant: % d  %d ",variant, ir);
 printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
*/
//_______________________________________________________________
 //pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//Buffer=(unsigned char*)(&TFTP_Buffer[0]);

  modemp[im].Mode =   (TFTP_Buffer[0] << 24) +
  						 (TFTP_Buffer[1] << 16) +
  						   (TFTP_Buffer[2] << 8) +
   								   TFTP_Buffer[3]; 
 printf("\n\r variant : %02X", variant);
  printf("\n\r mode : 0x%08X", modemp[im].Mode);



// for(long dr = 0; dr < NUMBER_OFFSET; dr++)
// {
 //  pBuffer++;
//      printf("\n\r %02X", TFTP_Buffer[dr]);

// }

// for(long dr = 0; dr < 2; dr++)
// for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP - 0x60; dr++)
// {
//   pBuffer++;
// }

//_______________________________________________________________
//_______________________________________________________________

//printf("\n\r>");

// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
//  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
// printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);
/*
for(unsigned long its =0l; its < 64l; its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", *pBuffer);
   pBuffer++;
}

 */
/*
for(unsigned long its =0l; its < 48l; its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

for(its =0x1720l; its < (0x1720+48l); its++)
{
 if(!(its% 16)) printf("\n\r");
  printf(" %02X", TFTP_Buffer[its]);
}

for(its = 0; its < ProvSizeToDownloadDCfgFile; its++)
{
  if(TFTP_Buffer[its] != TFTP_Buffer[its + CONFIG_FILE_PROVINGENT_STEP])
 printf("\n\r its: %d", its);
 }

*/


//_____________________________________________________________


// ir++;
 /*
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));

 */
   curvar = variant;

 }
 // curvar = variant;
}	//for
}	//if
else  //flagm == MODEM_QUANTITY
{

variant =  GetNumConfigFile(flagm) & CONFIG_FILE_MASK;

 //____________________________________________________________
//__________________________________________________________________________________
//hier need read file size

//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));



read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)), //101006
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));




//}

pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//______________________________________________101006
//printf("\n\r step : %X", *pBuffer);
file_size_readed = *pBuffer++;
//printf(" %X", *pBuffer);
file_size_readed  += (*pBuffer++) << 8;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 18;
//printf(" %X", *pBuffer);
file_size_readed += (*pBuffer++) << 24;
//printf("\n\r file_size_readed : %d", file_size_readed);
//_____________________________________________________________

 if((file_size_readed < MIN_CFG_FILE_SIZE) || (file_size_readed > MAX_CFG_FILE_SIZE)) file_size_readed = FILE_SIZE;

printf("\n\r variant : %d file_size_readed1 : %d", variant, file_size_readed);




//__________________________________________________________________________________



//variant =  GetNumConfigFile(flagm) & CONFIG_FILE_MASK;

//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP)),
//							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
//read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS + (variant * CONFIG_FILE_VARIANTS_STEP) + 
//101018 (FILE_SIZE - NUMBER_OFFSET)),
// (file_size_readed - NUMBER_OFFSET)),
//							 (unsigned int)NUMBER_OFFSET, (char *)(&TFTP_Buffer[0]));


 read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS  -  FULL_HEADER_SIZE - FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) +
//101018  (FILE_SIZE - NUMBER_OFFSET)),
	 (file_size_readed - NUMBER_OFFSET)),
							 (unsigned int)NUMBER_OFFSET, (char *)(&TFTP_Buffer[0]));


//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
//_____________________________________________________________

 modemp[flagm].Mode =   (TFTP_Buffer[0] << 24) +
  						 (TFTP_Buffer[1] << 16) +
  						   (TFTP_Buffer[2] << 8) +
   								   TFTP_Buffer[3]; 
 printf("\n\r variant : %02X", variant);
  printf("\n\r mode : 0x%08X", modemp[flagm].Mode);


//ir = flagm << 1;
  /*
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 */
//_______________________________________________________________
// pBuffer=(unsigned char*)(&TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP]);
//pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
// for(long dr = 0; dr < CONFIG_FILE_PROVINGENT_STEP - 0x60; dr++)
// {
//   pBuffer++;
// }

//_______________________________________________________________
/*
printf("\n\r>");

 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);


for(unsigned long its =0l; its < 100l; its++)
{
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
}

 */
//_____________________________________________________________


// ir++;
 /*
 printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
 printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 */


}
 curvar = 0xff+1;
}




//_________________________________________________________________________


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
 /*
printf("\n\r");
for(long t = 0; t < 18; t++)
{
printf(" %02X",TFTP_Buffer[t]);
}
printf("\n\r end of rawdata :");

for(t = 8180; t < (8180+ 64); t++)
{
printf("_%02X",TFTP_Buffer[t]);
}
*/


//PVG610_API_FirmwareFromHostBoot(0, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
unsigned long ir;
if(flagm == MODEM_QUANTITY)
{

for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
wd_reset();
 if(ModemIsUsed(im))
 {
 ir = im << 1;
 printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
 printf("... %d", ret);	//temporary
 ir++;
 printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
 printf("... %d", ret);
 } //if

} //for
}//if
else
{
ir = flagm << 1;
 printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret  = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);  
 printf("... %d", ret);	//temporary
 ir++;
 printf("\n\r PVG610_API_FirmwareFromHostBoot  %d", ir);
 ret = PVG610_API_FirmwareFromHostBoot(ir, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
 printf("... %d", ret);
}
}



void StartModems(unsigned char flagm)
{
// char ret;
//delay_mcs(5000000l); //for test !!!!!!
printf("\n\r Start Modems");

//for(long im = 0; im < 50; im++)
//{
ConfigDataLoadm(GetNumConfigFile(flagm),flagm);
//printf("\n\n\n\n\n\n\n\n\r_____________________%d", im);
FirmwareLoadm(flagm);
//wd_reset();
//}
ConfigFileLoadm(GetNumConfigFile(flagm), flagm);
ConfigFileRunm(flagm);
//it is now early ModemStatusGetm(flagm);  //old data
//ModemStatusGetm(flagm);


//delay_mcs(5000l);  //for test
//____________________________________________________________test
// if(!(SetLoop(PVG610_LOOPBACK_MODEM_E ,0 , 1 , 0)))
// {
// printf("\n\r Second try setting loop : %d", ret);
// ret =  SetLoop(PVG610_LOOPBACK_MODEM_E ,0 , 1 , 0);
// printf("\n\r Second try setting loop : %d", ret);

 //}
 
 
// ;		  //temporary
}
/*
#define	 REQUEST_QUANTITY (6)

void SendRequest(unsigned char im)
{
if(im > MODEM_QUANTITY) return;
for(long i = 0; i < REQUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5);
  embSerialACT155.AddMod(im);
}

}
*/




void SetModemToRezerv(unsigned char im)
{
if(GetPriority(im) == REZERV_PRIORITY) return;
if(GetPriority(im) == TEHNOLOGY_PRIORITY) return;
if(GetPriority(current_rezerv) <= GetPriority(im))
 {
 SendRequest(im);
 current_rezerv = im;
 }


}

void GetModemFromRezerv(unsigned char im)
{


}


#define ERRORS_THRESHOLD	(10)
#define NOISES_THRESHOLD	(10)


#define DELAY_IN_REZERV		(10)
/*

void OperateRezerv(void)
{
//
//state0 : rezerv do not used
//state1 : modem on rezerv timeout good do not have
//state2 : modem on rezerv timeout good have

double max_errors = 0;
double modem_errors = 0;
static unsigned long imax;
static unsigned long TimerStayRezerv;
unsigned long im;

switch(staterezerv)
 {
 case 0:   //rezerv do not used

  			for(im= 0; im < ((MODEM_QUANTITY << 1) - 1); im++)
  //			for(im= 0; im < MODEM_QUANTITY; im++)
			{
 					modem_errors = CheckErrors(im);
  					if(modem_errors > max_errors)
  					{
   						max_errors = modem_errors;
   						imax = im;
  					}
			}

			if(max_errors > (double)ERRORS_THRESHOLD)
			{
			   SetModemToRezerv(imax);	//hier imax is deviceindex!!!
			   TimerStayRezerv = timer;
			   staterezerv = 1;
			}
			
 				break;


 case 1:  //modem on rezerv timeout do not have
		   
		   modem_errors = CheckErrors(imax);

		   if(modem_errors > ERRORS_THRESHOLD)
			{
			   TimerStayRezerv = timer;
			}
			
 		   if ((timer > TimerStayRezerv) && ((timer - TimerStayRezerv) > DELAY_IN_REZERV))
 		   {
		     GetModemFromRezerv(imax);
		   staterezerv = 0;	 //can get from rezerv
 		   } 
 
   			break;
 default : break;
   }	  //case
}


 */


void OperateRezerv1(void)
{
unsigned long im;
  	   	for(im= 0; im < MODEM_QUANTITY; im++)
	   	{
			if( CheckNoises(im) > GetThreshold(im))
			{
			 SetModemToRezerv(im);	//hier imax is deviceindex!!!
 			}
	   	}
   
}


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
  //	if(typeOfProtocol==2)
   //	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
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

//____________________________________________________________________________232e
#ifndef ETH_TRANZIT
EmbMsg embMsg232E;
#endif // ETH_TRANZIT
//____________________________________________________________________________232e
 EmbMsg embMsg485E;
 EmbMsg embMsgWest;

//#ifdef ETH_TRANZIT

 EmbMsg embMsgEthTransitW;
 EmbMsg embMsgEthTransitE;
 EmbMsg embMsgWestE;	 //1223
 EmbMsgBuffer tBuffEmbMsgEthAll;
 EmbMsgBuffer tBuffEmbMsgEthAll1;


 //			  EmbMsg embMsgEastE;
//#endif // ETH_TRANZIT

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

 //	EmbSerialMD34AVT embSerialACT155;
	EmbSerialMD34AVTProv embSerialACT155;

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
//	unsigned char mode5A232E = 0;
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;

//________________________________________________________
	unsigned char modeA5West;
	TRBuffer<char,ACT_BUFFER_SIZE> embMsgWestR;
//________________________________________________________




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


#ifdef ETH_TRANZIT

  
extern  EmbRS232 trnzRS232;

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
			 	   	
//090515				if(embMsgEthTransitW.AddrS()==SelfID())

#ifndef ALL_ADDR			
	 	 	if(embMsgEthTransitW.AddrS()==SelfID())
#else
			if(1)	  //t 090427
#endif //ALL_ADDR


				{
			   
					embMsgEthTransitW.SetDir(1);
					rBuffEmbMsgE.Add(embMsgEthTransitW);
			   //	 	printf("t");
					embMsgEthTransitW.Init();
				}
		  //this is error!!!!!		recieveWest = 0;
			  //	
			}  //isend
				 
//__________________________>>

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
			case 0xA5:  modeA5West=1; markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
				 if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
					else if(mode5AWest) { embMsgWest.Add(Modify5A(westByte)); mode5AWest=0;	}
				  //	else if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
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
					 if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
					else if(mode5AWest) { embMsgWest.Add(Modify5A(westByte));/*AddCharWestE(Modify5A(westByte));*/mode5AWest=0;	}
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
	 tBuffEmbMsgEthAll.Add(embMsgWest);	  //t0129
//090709	  tBuffEmbMsgEthAll1.Add(embMsgWest);	  //t0129

  //t0129 	 SendWestTransitToEth();
 	 buff_cashe.add(embMsgWest.body[1], embMsgWest.AddrS(), embMsgWest.AddrI(), embMsgWest.AddrR(), embMsgWest.IsRS485());
  //	 EthSendTimer =	(( ETH_SEND_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
 //	 return 1;
   }
   else
   {
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

					embMsgWest.Init();
				}
				  embMsgWest.Init(); //101210
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
			} //selfid
			
			embMsgEast.Init(); //101210

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
unsnsned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x85,0x50,0xc0,0x1a}; // AX-Filter -строка 20
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
	outportb(0x510, 0x02); for(i=0; i<sizeof(f(a2); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a221); i++);
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

extern "C" void CommutateModForSS()
{
//hier will be write to xilinx


}


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
 unsigned char reqcounter;
  unsigned char rescounter;


 unsigned char currentgetrezerv;
 unsigned char currenthaverezerv;

StatRez statrez[MODEM_QUANTITY];
unsigned char current_rezerv;

extern "C" void Init_BMDN(void)
{

current_rezerv = 0xff; //do not stay any on rezerv 
reqcounter = 0;
rescounter = 0;

currentgetrezerv = 0;
currenthaverezerv = 0;
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


//  mode5A232E = 0; //1021
  mode5A485E = 0;  //1021
  mode5A485  = 0;  //1021


//________________________________________________________
    modeA5West=0;
	embMsgWestR.Init();
//________________________________________________________



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
   ab10[0] = 0x45;ab10[1] =0x08;ab10[2] =0x80;ab10[3] =0x00;ab10[4] =0x80;ab10[5] =0x00;ab10[6] =0x67;ab10[7] =0x35;ab10[8] =0x5A;ab10[9] =0x01; // / THilter part 2 
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


#ifdef RS485_MSG_BUFF
	   tBuffRS485.Init();
	   time_lastsend_rs485 = 0;
	   flag_wait_rs485 = 0;
#endif //RS485_MSG_BUFF


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
 //	InitTLF();
//	Ring();
	for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
	tlf_counter=0;


	for(i=0; i<MODEM_QUANTITY<<1; i++)
//101212	for(i=0; i<16; i++)
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
	unEmb2TypeVer.emb2TypeVer.type       = 0x0109;
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
	unEmb2TypeVer.emb2TypeVer.signature_software[14] = *(bt+1414);   //	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15);
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+ETH_TRANZIT_ON_ADDRESS); 
 

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
//____________________________________________provingent
//PVG610_API_Open();
//#define ADDR_ADDR 0x4
//#define SPI_ADDR  0x8
#define SYSTEM_CLOCK_IN_HZ (6000000);

//if( GetTestMode() != 0x8e)
//{
write_xil_char(ADDR_ADDR, SPI_ADDR); //init in xilinx address for spi 
/*
#ifndef BMDN_CONNECT_USART
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, 200000000l);
#else
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, 200000000l);
#endif
*/
unsigned long ir;
#ifndef BMDN_CONNECT_USART

#ifndef MANY_MODEMS
PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);
#else  //MANY_MODEMS
for(unsigned long im= 0; im < MODEM_QUANTITY; im++)
{
KoefErrors[im] = 0;
ir = im << 1;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);
ir++;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_SPI_E, FREQ_SYNT);

}
#endif //MANY_MODEMS


#else

//PVG610_API_ComConfigure(0, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);
for(unsigned long im= 0; im < MODEM_QUANTITY; im++)
{
ir = im << 1;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);
ir++;
PVG610_API_ComConfigure(ir, PVG610_COM_MEDIA_UART_E, FREQ_SYNT);

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
PVG610_API_ComTimeoutSet(0, 3); //100519
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

for(im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
#ifndef MAKET_PLATA
  typemodem =  ModemIsUsed(im);
 if(typemodem)
#else
 if(1)
#endif
 {
   used_modems |= mod_mask;
   SetModemStruct(im,typemodem);

if( GetTestMode() != 0x8e) //do not restart rtcs only
{
 printf("\n\r Test Mode : 0x%X Init : %d", GetTestMode(), im);
   CommonResetOn(im);
   ResetSyntOff(im);
 //  LoadSyntm(im);
   LoadSyntmf(GetNumConfigFile(im),im); //100728
   CommonResetOff(im);
   statrez[im].Init();
}
else
{
   printf("\n\r Do Not Init : %d", im);

}


 }
  mod_mask <<= 1;
}


//}	 //	GetTestMode() != 0x8e
//else
//{
// FillUsedModems();
//}

printf("\n\r ....Delay mcs: %d", SYNT_SET_DELAY );
delay_mcs(SYNT_SET_DELAY);

//LoadSynt();
CommutateModForSS(); //empty now
Init_structs();
if( GetTestMode() != 0x8e) //do not restart rtcs only
{

   StartModems(MODEM_QUANTITY);
}

printf("\n\r ....end of init");
}

#define SCAN_PERIOD (1000) //1c
#define READ_ERRORS_PERIOD (1000) //1c

extern "C" void UpdateErrors(unsigned char mod)
{
 unsigned char deviceindex = mod << 1;
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
  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;

//_________________________________________________________________________________________________
//			Счётчик ошибок не исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex].rsErrorByteCounter;
			
//			Счётчик ошибок, исправленных РС в 2 стволе
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].protectionRxBytesFromProtection;// Fc.rsErrorByteCounter;


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
  KoefErrors[deviceindex] =	 0;

//_____________________________________________________
ulevelsn15503.levelsn15503.absoluteMse[mod] = 0;
ulevelsn15503.levelsn15503.normalizedMse[mod] = 0;
ulevelsn15503.levelsn15503.radialMse[mod] = 0;

uerrsn15503work.errsn15303work.counterSlip[mod] =   0;
uerrsn15503work.errsn15303work.fecBlockCounter[mod] = 0;
uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] = 0;
//_________________________________________________________


//_____________________________________________________

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
  KoefErrors[deviceindex1] =	 0;



}

extern "C" void FillLock(unsigned char mod, unsigned char status)
{

 if(status)
 {
 switch(mod)
 {
  case 0 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_0; break;
  case 1 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_1; break;
  case 2 : uerrsn15503work.errsn15303work.lock1 |=  MASK_BIT_2_2; eak;
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

extern "C" void ReadErrors(unsigned char mod)
{
PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;
PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
//PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);


 unsigned char deviceindex = mod << 1;
 unsigned char deviceindex1 = (mod << 1) + 1;

//  printf("\n\rread errors:%d", mod);
 //  PVG610_API_ModemFecCountersGet(current_channel, 0, &Fc);
 PVG610_API_ModemStatusGet((deviceindex), 0, &Ms);
 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
 modemp[deviceindex].acquireStatus =   Ms.acquireStatus;
  FillLock(mod,Ms.acquireStatus);

 if(Ms.acquireStatus)
 {

//___________________________________________________________
modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;

//_________________________________
/*
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

#define uerrsn15503work_SIZE	  (58)	 //sum of bytes Errsn15503work

struct ErrSN15503Work
{
  unsigned long fecBlockCounter[9];//
  unsigned long fecUncorrectedBlock[9];	
  unsigned short counterSlip[9];
  unsigned char reserv[4];
};

union uErrSN15503Work
{
   ErrSN15503Work errsn15303work;
   unsigned char byte[uerrsn15503work_SIZE];
};


*/

//_________________________________


 /*
modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;
 */
ulevelsn15503.levelsn15503.absoluteMse[mod] = Ms.absoluteMseTenths;
ulevelsn15503.levelsn15503.normalizedMse[mod] = Ms.normalizedMseTenths;
ulevelsn15503.levelsn15503.radialMse[mod] = Ms.radialMseTenths;

//uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ms.lastAcquireError;


//___________________________________________________________

PVG610_API_ModemAcquireCountersGet((deviceindex), 0, &Ac);
uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;



 PVG610_API_ModemFecCountersGet((deviceindex), 0, &Fc);
//    printf("\n\rread mod : %d errors:%ld", (mod << 1), );

/*
UINT32 fecBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 fecUncorrectedBlockCounter; // cumulative, clear on read (RS or LDPC)
UINT32 rsByteCounter; // cumulative, clear on read
UINT32 rsErrorByteCounter; // cumulative, clear on read
*/
  modemp[deviceindex].fecBlockCounter +=   Fc.fecBlockCounter;
  modemp[deviceindex].fecUncorrectedBlockCounter +=   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;

  KoefErrors[deviceindex] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;



  printf("\rmod : %d Status : %d Bytes:%ld", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection);
//  printf("\n\r fecBlockCounter:%ld",   modemp[deviceindex].fecBlockCounter);
//  printf("\n\r fecUncorrectedBlockCounter:%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
//  printf("\n\r rsByteCounter:%ld",  modemp[deviceindex].rsByteCounter);
//  printf("\n\r rsErrorByteCounter:%ld",  modemp[deviceindex].rsErrorByteCounter);
//  printf("\n\r ldpcAvgIterations:%ld",  modemp[deviceindex].ldpcAvgIterations);
//  printf("\n\r protectionUncorrectedBytes:%ld",   modemp[deviceindex].protectionUncorrectedBytes);


   uerrsn15503work.errsn15303work.fecBlockCounter[mod] +=   Fc.fecBlockCounter;;
   uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] +=   Fc.fecUncorrectedBlockCounter;




  }
  else
  {
  printf("\rmod : %d  Status : %d ", (deviceindex), modemp[deviceindex].acquireStatus);
 //___________________________________________________________
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

//___________________________________________________________

ulevelsn15503.levelsn15503.absoluteMse[mod] = 0;
ulevelsn15503.levelsn15503.normalizedMse[mod] = 0;
ulevelsn15503.levelsn15503.radialMse[mod] = 0;

//   uerrsn15503work.errsn15303work.counterSlip[mod] =   0;
//   uerrsn15503work.errsn15303work.fecBlockCounter[mod] = 0;
//   uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] = 0;


  }

  // UpdateErrors(deviceindex);


 PVG610_API_ModemStatusGet((deviceindex1), 0, &Ms);
 //  printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
   modemp[deviceindex1].acquireStatus =   Ms.acquireStatus;
 
  if(Ms.acquireStatus)
 {

//___________________________________________________________
modemp[deviceindex1].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex1].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex1].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex1].radialMseTenths =   Ms.radialMseTenths;


//___________________________________________________________


   PVG610_API_ModemFecCountersGet(deviceindex1, 0, &Fc);

  modemp[deviceindex1].fecBlockCounter =   Fc.fecBlockCounter;
  modemp[deviceindex1].fecUncorrectedBlockCounter =   Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex1].rsByteCounter =   Fc.rsByteCounter;
  modemp[deviceindex1].rsErrorByteCounter =   Fc.rsErrorByteCounter;
  modemp[deviceindex1].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex1].protectionRxBytesFromProtection =   Fc.protectionRxBytesFromProtection;
  modemp[deviceindex1].protectionUncorrectedBytes =   Fc.protectionUncorrectedBytes;

  KoefErrors[deviceindex1] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;

  printf("mod :  %d  Status : %d errors:%ld", (deviceindex1), modemp[deviceindex1].acquireStatus, modemp[devivicedex1].protectionRxBytesFromProtection);
  }
  else
  {
  printf("mod :  %d  acquireStatus : %d ", (deviceindex1), modemp[deviceindex1].acquireStatus);
 //___________________________________________________________
  modemp[deviceindex1].counterSlip =   0;
  modemp[deviceindex1].absoluteMseTenths =   0;
  modemp[deviceindex1].normalizedMseTenths =   0;
  modemp[deviceindex1].radialMseTenths =   0;



  modemp[deviceindex1].fecBlockCounter =  0;
  modemp[deviceindex1].fecUncorrectedBlockCounter =  0;
  modemp[deviceindex1].rsByteCounter =  0;
  modemp[deviceindex1].rsErrorByteCounter = 0;
  modemp[deviceindex1].ldpcAvgIterations =  0;
  modemp[deviceindex1].protectionRxBytesFromProtection =  0;
  modemp[deviceindex1].protectionUncorrectedBytes =   0;

//___________________________________________________________

  }


/*
	  		    unStateBMD155.stateBMD155.count_no_correct_result =  Fc.protectionUncorrectedBytes;
  				unStatePUM.statePUM.ulErrOut 					 +=  Fc.protectionUncorrectedBytes;

				unStateBMD155.stateBMD155.count_block 			  =	 Fc.protectionRxBytesFromProtection;
				unStatePUM.statePUM.ulBlock 					 +=  Fc.protectionRxBytesFromProtection;

				unStateBMD155.stateBMD155.count_notRS1 			  =	 Fc.fecUncorrectedBlockCounter;
 				unStatePUM.statePUM.ulErrAfterRS1 				 +=	 Fc.fecUncorrectedBlockCounter;

 				unStateBMD155.stateBMD155.count_no_correct_block1 =	 Fc.rsErrorByteCounter;
				unStatePUM.statePUM.ulErrBeforeRS1 				  =   Fc.rsErrorByteCounter;

 */



  UpdateErrors(mod);
}

extern "C" void ScanErrors(void)
{
static unsigned long timescan;
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
 //printf("\n\rread errors: %d", curmod);



  switch(curmod)
  {
	case 0 :   if(!(used_modems & MASK_BIT_0)){ClearStats(curmod);curmod++;} else{ ReadErrors(curmod); curmod++; break;}
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
 default: break;
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
    CommonResetOn(im);
	delay_mcs(RESET_DELAY);
    ResetSyntOff(im);
 //  LoadSyntm(im);
    LoadSyntmf(GetNumConfigFile(im),im);
    CommonResetOff(im);
 	StartModems(im);
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
 //printf(".");
for(long im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
 typemodem =  ModemIsUsed(im);
 if(typemodem)	//1c
 {
   if(!(used_modems & mod_mask))
   {
  /* temporary 101021
   SetModemStruct(im,typemodem);
   ResetSyntOff(im);
 //  LoadSyntm(im);
   LoadSyntmf(GetNumConfigFile(im),im);

   CommonResetOff(im);
   StartModems(im);
   */
RestartTest++;
   used_modems |= mod_mask;


   }
 }
 else
 {
	used_modems &= ~(mod_mask);
     SetModemStruct(im,typemodem);
 }
  mod_mask <<= 1;
} //for
}



}



extern "C" void StartModem()
{
FirmwareLoad();
ConfigFileLoad();
ConfigFileRun();
ModemStatusGet();  //old data
ModemStatusGet();


}

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




extern "C" void  GetVersionAPI(void)
{
unsigned char retval;
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

// PVG610_API_ModemStatusGet(0, 0, pMs);
// PVG610_API_VersionGet(1, &ver);
//  PVG610_API_ConfigFileRun(0, 0);
//  PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
 // PVG610_API_FirmwareFromHostBoot(0, pBuffer, len, PVG610_DEVICE_RESET_CPU_E);
//   retval = PVG610_API_VersionGet(2, &ver);
// retval = PVG610_API_DeviceReset(0,PVG610_DEVICE_RESET_ALL_E); //t
// printEthLongHex(retval);
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


extern "C" void FlashFirmwareLoad()
{
//PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareReload(BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex);
 PVG610_API_FlashFirmwarareRoad(0, 0);
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
  /*
BYTE ReadBuffer[ProvSizeToDownloadDCfgFile];

extern "C" void ConfigFileGet()
{

//BYTE ReadBuffer[ProvSizeToDownloadDCfgFile];
printf("\n\r ConfigFileGet");

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


printf("\n\r .....0");

//return;

printf("\n\r start len = %d", len);
//ok  return;
 PVG610_API_ConfigFileFromEmbeddedGet(0, 0, &ReadBuffer[0], len, &readlen);

 printf("\n\r readlen = %d", readlen);
 for(ir = 0; ir < ProvSizeToDownloadDCfgFile; ir++)
 {
  if(!(ir%16))
  printf("\n\r");
  printf(" %02X", ReadBuffer[ir]);
 }



 printf("\n\r .....finish");
// printEthStringAdd(2,0);


}

   */

extern "C" void ConfigFileRun()
{
//printf("\n\r ConfigFileRun");
//printf("\n\r .....0");
  PVG610_API_ConfigFileRun (0,0);
// printf("\n\r .....finish");
}

extern "C" void ModemStatusGet()
{
printf("\n\r ModemStatusGet");
PVG610_MODEM_STATUS_STRUCT	Ms;
   PVG610_API_ModemStatusGet(0, 0, &Ms);
printf("...ok");
   /*
printf("\n\r acquireStatus : %02X" , Ms.acquireStatus);
printf("\n\r lastAcquireError : %02X" , Ms.lastAcquireError);
printf("\n\r absoluteMseTenths : %d" , Ms.absoluteMseTenths);
printf("\n\r normalizedMseTenths : %d" , Ms.normalizedMseTenths);
printf("\n\r radialMseTenths : %d" , Ms.radialMseTenths);
printf("\n\r internalAgc : %d" , Ms.internalAgc);
printf("\n\r externalAgcRegister : %X" , Ms.externalAgcRegister);
printf("\n\r carrierOffset : %d" , Ms.carrierOffset);
printf("\n\r rxSymbolRate : %d" , Ms.rxSymbolRate);
printf("\n\r txSymbolRate : %d" , Ms.txSymbolRate);
printf("\n\r ldpcDecoderStress : %X" , Ms.ldpcDecoderStress);
printf("\n\r txAcmProfile : %02X" , Ms.txAcmProfile);
printf("\n\r rxAcmProfile : %02X" , Ms.rxAcmProfile);
printf("\n\r acmEngineEnabled : %d" , Ms.acmEngineEnabled);
printf("\n\r debugIndications : %02X" , Ms.debugIndications);
 */

  /*
 BYTE                acquireStatus;          // PVG610_ACQUIRE_STATUS_ENUM: locked, failed, in progress
    BYTE                lastAcquireError;       // PVG610_ACQUIRE_ERR_ENUM
    INT16               absoluteMseTenths;      // in 0.1 dB steps
    INT16               normalizedMseTenths;    // in 0.1 dB steps
    INT16               radialMseTenths;        // in 0.1 dB steps
    INT16               internalAgc;            // in dB, normal range [-5 to 40]
    UINT16              externalAgcRegister;    // Directly reflects PVG register
    INT32               carrierOffset;          // in Hz, normal range [-1e6 to 1e6]
    UINT32              rxSymbolRate;           // in Baud, up to 50e6
    UINT32              txSymbolRate;           // in Baud, up to 50e6
    UINT32              ldpcDecoderStress;      // fraction in range [0,1]
    BYTE                txAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
    BYTE                rxAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
    BOOLEAN             acmEngineEnabled;       // enabled/disabled
    BYTE                debugIndications;       /

  */
}

extern "C" void ModemAcquireCountersGet()
{
//printf("\n\r ModemAcquireCountersGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
PVG610_API_ModemAcquireCountersGet(0, 0, &Ac);
/*
UINT32 lolTimeMsec; // cumulative, clear on read
UINT32 numLolEvents; // cumulative, clear on read
UINT32 numAcquireTrials; // cumulative, clear on read
UINT32 lastLockTimeSymbols; // in Usec
UINT32 lastLockTimeBits; // in Usec
UINT32 lastLockTimeService; // in Usec
UINT32 lastAcquireTimeUsec; // in Usec
UINT32 lastTotalAcquireTimeUsec; // in Usec
*/
/*
 printf("\n\r lolTimeMsec : %ld" , Ac.lolTimeMsec);
 printf("\n\r numLolEvents : %ld" , Ac.numLolEvents);
 printf("\n\r numAcquireTrials : %ld" , Ac.numAcquireTrials);
 printf("\n\r lastLockTimeSymbols : %ld" , Ac.lastLockTimeSymbols);
 printf("\n\r lastLockTimeBits : %ld" , Ac.lastLockTimeBits);
 printf("\n\r lastLockTimeService : %ld" , Ac.lastLockTimeService);
 printf("\n\r lastAcquireTimeUsec : %ld" , Ac.lastAcquireTimeUsec);
 printf("\n\r lastTotalAcquireTimeUsec : %ld" , Ac.lastTotalAcquireTimeUsec);
 */
}

#define MAX_MAILBOX   (32)

extern "C" unsigned char ModemMailboxMessageSend(unsigned short msgLen, unsigned char * pData)
{
// printf("\n\r ModemMailboxMessageSend");
 if(msgLen > MAX_MAILBOX) return;
 PVG610_MAILBOX_MESSAGE_STRUCT Mbx;
 BYTE result;
 Mbx.msgLen = msgLen;
  for(long i = 0; i < msgsgLe i++)
  {
   Mbx.message[i] = *pData++;
  }
  result = PVG610_API_MailboxMessageSend(0,0, &Mbx);
//  printf(" result: : %X", result);
  return (unsigned char)result;
}

extern "C" unsigned char * ModemMailboxMessageReceive(void)
{
// printf("\n\r ModemMailboxMessageReceive");
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
// printf(" return : %X", result);

if(result)
 {
 // printf(" error : %X", result);

 	return NULL;
 }


printf("\n\r Mbx.msgLen = %d  \n\r",Mbx.msgLen);

// if (Mbx.msgLen <=  MAX_MAILBOX)
// {
 // for(long i = 0; i < Mbx.msgLen; i++)
  for(long i = 0; i < MAX_MAILBOX; i++)
  {
   printf(" %02X", Mbx.message[i]);
  }
 // printf("\n\r");

 // for(i = 0; i < MAX_MAILBOX; i++)
 // {
 //  printf(" %c", Mbx.message[i]);
 // }


// }

 return (unsigned char *) &Mbx;
}





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
 printf("\n\r fecBlockCounter : %ld", Fc.fecBlockCounter);
 printf("\n\r fecUncorrectedBlockCounter : %ld", Fc.fecUncorrectedBlockCounter);
 printf("\n\r rsByteCounter : %ld", Fc.rsByteCounter);
 printf("\n\r rsErrorByteCounter : %ld", Fc.rsErrorByteCounter);
 printf("\n\r ldpcAvgIterations : %d", Fc.ldpcAvgIterations);
 printf("\n\r viterbiNormalRate : %02X", Fc.viterbiNormalRate);
 printf("\n\r protectionRxBytesFromProtection : %ld", Fc.protectionRxBytesFromProtection);
 printf("\n\r protectionUncorrectedBytes : %ld", Fc.protectionUncorrectedBytes);
 */
// printf("\n\r protectionUncorrectedBytes : %ld", Fc.protectionUncorrectedBytes);

}




extern "C" void ModemAcmCountersGet()
{
//printf("\n\r ModemAcmCountersGet");
//PVG610_MODEM_STATUS_STRUCT	Ms;
PVG610_ACM_COUNTERS_STRUCT Mc;
   PVG610_API_AcmCountersGet(0, 0, &Mc);

   /*
    UINT16               acmRxProfilesHistory;
    UINT16               acmTxProfilesHistory;
  */
 /*
printf("\n\r acmRxProfilesHistory : %X" , Mc.acmRxProfilesHistory);
printf("\n\r acmTxProfilesHistory : %X" , Mc.acmTxProfilesHistory);
  */
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

//extern "C" unsigned char pvg610FwSendAndJump(PVG610_DATABASE_STRUCT *, BYTE*);

extern "C" void LoadToLdr(void)
{
//unsigned char retval;
//PVG610_MODEM_VERSION_STRUCT verer;/ retval = PVG610_API_VersionGet(0, &ver);

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


unsigned char * ExChangeSpi(unsigned long length_of_data, unsigned char * BufferData)
{
unsigned long do_not_hangt = 0xfffffff;

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
 printf("\n\r reading error!");
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
 printf("TryGetRezerv : %d", chn);
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
extern "C" void BMDN()
 {
 // char Buf[] = {1,2,3,4,5,6,7,8,9};
#ifdef EMPTY_LOOP
//___________________________________________test

//static unsigned long periodcnt;
// periodcnt++;
// if(periodcnt > 1000)
//{
//  periodcnt = 0;
// ConfigDataLoadm(0, MODEM_QUANTITY);
//} 

//___________________________________________test
  return;
#endif

//___________________________________________test
 /*
static unsigned long periodcnt;
 periodcnt++;
 if(periodcnt > 10000)
{
 printf(" RestE: %d Rest: %d",RestartTestE,RestartTest);

  periodcnt = 0;
// ConfigDataLoadm(0, MODEM_QUANTITY);
} 
  	*/
//___________________________________________test




//  Buf[0] = 0x55;
//  Buf[8] = 0xAA;

//   long err_tmp_now = 0l;

//PVG610_MODEM_FEC_COUNTERS_STRUCT Fc;

 ScanModems();	 //find and load modems
 ScanErrors();	 //read errors on roulette prinzip
 OperateRezerv1(); //compare noises to treshholds and set modems to rezerv
 ParseRequestsRezervResponses();
//test100601  TestMailBoxes();

//101223 return; 

//__________________________________________________________________
//bt = (unsigned char *)(NVRAM_BASE);
   /* 101008
	unEmb2TypeVer.emb2TypeVer.signature_software[0] = *bt;
	unEmb2TypeVer.emb2TypeVer.signature_software[1] = *(bt+1);
	unEmb2TypeVer.emb2TypeVer.signature_software[2] = *(bt+2);
	unEmb2TypeVer.emb2TypeVer.signature_software[3] = *(bt+3);
	unEmb2TypeVer.emb2TypeVer.signature_software[4[4] *(bt+4);
	unEmb2TypeVer.emb2TypeVer.signature_software[5] = *(bt+5);
	unEmb2TypeVer.emb2TypeVer.signature_software[6] = *(bt+6);
	unEmb2TypeVer.emb2TypeVer.signature_software[7] = *(bt+7);
	unEmb2TypeVer.emb2TypeVer.signature_software[8] = *(bt+8);
	*/
   /*
	unEmb2TypeVer.emb2TypeVer.signature_software[9]  = *(bt+9);
	unEmb2TypeVer.emb2TypeVer.signature_software[10] = *(bt+10);
	unEmb2TypeVer.emb2TypeVer.signature_software[11] = *(bt+11);
	unEmb2TypeVer.emb2TypeVer.signature_software[12] = *(bt+12);
	unEmb2TypeVer.emb2TypeVer.signature_software[13] = *(bt+13);
	unEmb2TypeVer.emb2TypeVer.signature_software[14] = *(bt+14);
 //	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15); 
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+ETH_TRANZIT_ON_ADDRESS); 


 if(!start_count)
 {start_count = 1;}
 else
 {
	ErrResSNMP += unStateBMD155.stateBMD155.count_no_correct_result;
 }


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
 //	unsigned char bblt;
	unBmdState.byte = inportb(0x522);
 
	unLtDiod.byte=0;
	unLtDiod.ltDiod.alarmIn1 = unBmdState.bmdState.alarmSync1;//unBmdState.bmdState.alarmIn1;
	unLtDiod.ltDiod.alarmIn2 = unBmdState.bmdState.alarmSync2;//unBmdState.bmdState.alarmIn2;
	unLtDiod.ltDiod.alarmSync1 = unBmdState.bmdState.alarmSync1;
	unLtDiod.ltDiod.alarmSync2 = unBmdState.bmdState.alarmSync2;
   

	outportb(0x536,unLtDiod.byte); 


		unStateBMD155.stateBMD155.statePI=0;
/////////////////////////////////////////
		unStateBMD155.stateBMD155.mod=0;
		unStateBMD155.stateBMD155.dem1=0;
		unStateBMD155.stateBMD155.dem2=0;
		unStateBMD155.stateBMD155.state_dem1=0;
		unStateBMD155.stateBMD155.state_dem2=0;
//////////////////////////////////////////////////
*/

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

return; //101223
 
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
//if will be to be maked  	   	ProtocolToEth();
	 //	}
  }
}
#endif // ETH_TRANZIT
   //	   if(!EthAnsTimer)	ProtocolToEth();
//#ifdef ETH_TRANZIT
   //t	   if(!EthSendTimer)
   //	   if(EthReceiveTimer > ETH_RECEIVE_TIMER)

//#endif // ETH_TRANZIT
	 //  	if(	
   	   	ProtocolFromModACT155();
	 //  	ProtocolFromModACT155Prov();
	 //  	) return;//t0122   //this get to lost

//#ifdef ETH_TRANZIT
  //t	   if(!EthSendTimer) 
//#endif // ETH_TRANZIT	   
	   	ProtocolFromTransitACT155();

		Check2InitTransitMod();

//#ifdef ETH_TRANZIT
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

//#endif //ETH_TRANZIT

//#ifndef PROG_ACT155N

#include bmdn1_rem.c //100110

#ifdef ETH_TRANZIT
if(IsEthTransitMode())
{
ProtocolFromEthTransit();
}
#endif //ETH_TRANZIT



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
   	TimerCrCouer1 ++;
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


  signed char  aa_loc, aa1, aa2, aa3, code;
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

printf("\r %d %d %d %d %d = %c \r\n", aa1, aa2, aa3, aa_loc, aa_loc, code);

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
								    printf("MOD : rmo: %X  rm: %X   \n\r", rmo, rm);
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
									 printf("TRNZ : rtzo: %d  rtz: %d   \n\r", rtzo, rtz);

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
 
} //PeriodCounter
 
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
//t if(PeriodCounter >10l)
if(PeriodCounter >15l)	 //t  ok
 //badif(1)
 {
 PeriodCounter = 0l;
	 // TX UP0
//for (i=0; i<10; i++)
  //		{

//modem transmit 508 : bit5
//transit transmit50a : bit5
//up0 : transmit50c : bit5
//up1 : transmit 50e
 

	 // 	bstate =  inportb(0x50c);

		//  printf("bstate up0:  %d  \n\r", bstate);


			   // while((inportb(0x505) & 0x20) == 0) {}
				 // 	  if(inportb(0x505) & 0x20)
				  //	    if(inportb(0x50c) & 0x20)
				  //	if(PeriodCounter == 11l)
					  {
					   outportb(0x50B, tup0++);
								 tup0c++;     
					  } 
   //		}

// TIMER MODE
	 // TX UP1
//for (i=0; i<2; i++)
//{
			  //	 while((inportb(0x505) & 0x80) == 0) {}
//bstate =  inportb(0x50e);

   //		  printf("bstate up1 :  %d  \n\r", bstate);
//);
					if (inportb(0x50e) & 0x20)
	//  if(PeriodCounter == 12l)

  						{
   						 outportb(0x50D, tup1++);
   						 tup1c++;
  						 }
//}
	 // TX MODEM
//for (i=0; i<8; i++)
//{
 				   //		 while((inportb(0x505) & 0x02) == 0) {}
  // bstate =  inportb(0x508);
	   //		 printf("bstate md :  %d  \n\r", bstate);

				//		 if	 (inportb(0x508) & 0x20)
		  //		  if(PeriodCounter == 13l)
						 {
						 outportb(0x507, tm++);
						 tmc++;
						 }
//}
	  // TX TRANZIT
//for (i=0; i<8; i++)
//{
  				   //		while((inportb(0x505) & 0x08) == 0) {}
   // bstate =  inportb(0x50a);
		   //		 printf("bstate trz :  %d  \n\r", bstate);

			//			if (inportb(0x50a) & 0x20)
		   //	  if(PeriodCx50a) & 0x20)
		   //	  if(PeriodCportb(0x509,  ttz++); 
		 //  {
						 outportb(0x509,  ttz++); 
						ttzc++;
					//	PeriodCounter = 0l; //t13
				//		}
//}

} //PeriodCounter
//--------------------------------------------------------------
  /*
//	if (0x80 & inportb(0xff2e)) // при появлении прерывания INT3

   //	while (0x20 & inportb(0xff2e)) // при появлении прерывания INT1
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
		  	   
		   //		  printf("MOD : rmo: %d  rm: %d  \n\r", rmo, rm);
					if (rmo!=rm)
							{			
									if (merc <0xfffe) merc++;
							}
					rm++;
					rmo=rm;
					cnt--;
				}
		 //	   printf("<<<<<<<<<<<<<<<<<<<<<  \ \n\);
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
 	   printf("Send MOD -- %d  RX-- %d  ERR-- %d\n\r", tmc,rmc, merc);

			tmc=0;rmc=0; merc=0;
		}
	

//outport(wdtcon,0x5555);
//outport(wdtcon,0xaaaa);
 //     wd_reset();	

 //	  my_int_enable_irq0();
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


//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long*ong*a_len)
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
   	ifif(vval) {outportb(0x525, unStatePUM.statePUM.state[5] | 0x4);}
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

//#define MAX_RECEIVE (3)
//t #define MAX_RECEIVE (4)	   3e-4
#define MAX_RECEIVE (4)	

unsigned long count_send, count_res, count_res_ok, count_res_bad;


#define SEND_TIMEOUT (2)
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
char Buff[32] = "Hello!";
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
   printf("\n\r cur_res = %d , wait_res = %d", cur_res, wait_res);
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
   printf("\n\r cur_res = %d , wait_res = %d", cur_res, wait_res);
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
 if(!(sendboxes % 100))
 {
//100528  printf("\n\rs: %d:  r%d", sendboxes, receivedboxes);
//100528  printf("ok: %d bad: %d", count_res_ok,count_res_bad);

 }

 //  pio_ptr1->CODR = tg; //(1<<pin);

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
unsigned long do_not_hangt = 0xffffl; //101221
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr,form_addrs ,form_addre;
unsigned char readtmp;

form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);
form_addre = BLOCK_SWEEP1 * ((deviceindex- TEST_OFFSET)+1);


switch(deviceindex)
{
 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_A; break;
 case 1: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	form_m_ad + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr  + SPI_ADR; addr_send =  form_addr  + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
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
 case 35: addr_status =     form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type =   form_addr + SPI_ADR; addr_send =   form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_D;   break;  //rom for xilinx
 case 36: 
 case 37: 
 case 38: 
 case 39: 
 case 40: 
 case 41: 
 case 42: 
 case 43:
 case 44: addr_status =     form_addre + ADDR_STATUS1; addr_data = form_addre +  SPI_PORT_ADDR; addr_type =   form_addre + SPI_ADR; addr_send =   form_addre + SPI_SEND_ADDR;type_channel = CHANNEL_E;   break; //test channells



 default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
}

//if(deviceindex == 43)
//{
//  printf("\n\r addr status = %X data = %X",addr_status, * BufferData);

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

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 //  break;
//if(deviceindex == 43)
//{
//  printf("\n\r do_not_hangt : 0x%X", do_not_hangt);
//}

 return 1;
 }
}

//if(deviceindex == 43)
//{
//  printf("\n\r ________do_not_hangt : 0x%X", do_not_hangt);
//}
//write_xil_char(addr_type , 0);
//delay_mcs(1000);
 return 0;
}



#else //
#ifndef N_MOD

extern "C" unsigned char WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{

unsigned long do_not_hangt = 0xfffffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block



switch(deviceindex)
{
 case 0: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 1: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEWEEP (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16:
 case 17:
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23: addr_status = 	BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_ADR; addr_send =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_C; break; //printf(" %d", addr_status); break;
//______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
 case 24: 
 case 25: 
 case 26: 
 case 27: 
 case 28: 
 case 29: 
 case 30: 
 case 31: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_D; break;



 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
}



if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return;

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
write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
  // break;
  return 1;
 }
}
//printf("\n\r do_not_hangt : 0x%X", do_not_hangt);

//write_xil_char(addr_type , 0);
//delay_mcs(1000);
return 0;
}

#else  //N_MOD
extern "C" unsigned char WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{

unsigned long do_not_hangt = 0xfffffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block



switch(deviceindex)
{
 case 0: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 1: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	BLOCK_SWEEP + (((deviciceiex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 17: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = 	BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET) << 4) + SPI_ADR; addr_send =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_C; break;
//______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ flash :
 case 27: 
 case 28: 
 case 29: 
 case 30: 
 case 31: 
 case 32: 
 case 33: 
 case 34:
 case 35: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_D;   break;



 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
}



if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return;

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
write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 //  break;
 return 1;
 }
}
//printf("\n\r do_not_hangt : 0x%X", do_not_hangt);

//write_xil_char(addr_type , 0);
//delay_mcs(1000);
 return 0;
}






#endif //N_MOD
#endif //PROG_BMDN2




/*

void WriteSpiBm1(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{
//tunsigned long do_not_hangt = 0xfffl;
unsigned long do_not_hangt = 0xfffl;

unsigned long lentmp;
unsigned char * BufferDataTmp;
//static unsigned char ReadBuffer[MAX_SP_LEN];

//printEthStringAdd(1,0x88);
//printEthStringAdd(1,length_of_data);


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
//#ifdef PRINT_SPI_DATA
//printEthStringAdd(1,RearrangeByte(* BufferDataTmp));
//if(print_flag)
//printEthStringAdd(1,* BufferDataTmp);
//#endif

//t100422 printf(" %02X", * Buff(" %02X", * Buf write_xil_char(ADDR_DATA, * BufferDataTmp++);
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

}
*/


#ifdef PROG_BMDN2

unsigned char * ReadSpiBm(unsigned char deviceindex, unsigned long length_of_data)
{
static unsigned char ReadBuffer[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr,form_addrs ;

form_addr = BLOCK_SWEEP1 * ((deviceindex>>1)+1);
form_addrs = BLOCK_SWEEP1 * ((deviceindex- SYNT_OFFSET)+1);


switch(deviceindex)
{
 case 0:  addr_status = form_addr + ADDR_STATUS1; addr_data = formrm_ar +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
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
 case 13: addr_status = form_addr + ADDR_STATUS1;  addr_data = form_addr +  SPI_PORT_ADDR; addr_type =  form_addr + SPI_ADR; addr_send = form_addr + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
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

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
// printf(" %02X",* BufferDataTmp);
BufferDataTmp++;
}

//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}




#else // PROG_BMDN2

#ifndef N_MOD
unsigned char * ReadSpiBm(unsigned char deviceindex, unsigned long length_of_data)
{
 /*
unsigned long do_not_hangt = 0xfff;

unsigned long lentmp;
unsigned char * BufferDataTmp;
static unsigned char ReadBuffer[MAX_SP_LEN];

unsigned long addr_status, addr_data;
switch(deviceindex)
{
 case 0: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 1: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 2: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 3: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 4: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 5: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 6: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 7: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 8: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 default: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
}


 if((length_of_data > MAX_SP_LEN) || (!length_of_data))
 {
  return ReadBuffer;
 }

write_xil_char(addr_status, RESET_BIT);
*/
//____________________________________________________________________________________________
static unsigned char ReadBuffer[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block


switch(deviceindex)
{
 case 0: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 1: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR;R; ar_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1)+1)<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)+1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16:
 case 17:
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23: addr_status = 	BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_ADR; addr_send =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET + 1) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_C;break;

 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
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

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
// printf(" %02X",* BufferDataTmp);
BufferDataTmp++;
}

//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}
#else //N_MOD
unsigned char * ReadSpiBm(unsigned char deviceindex, unsigned long length_of_data)
{
 /*
unsigned long do_not_hangt = 0xfff;

unsigned long lentmp;
unsigned char * BufferDataTmp;
static unsigned char ReadBuffer[MAX_SP_LEN];

unsigned long addr_status, addr_data;
switch(deviceindex)
{
 case 0: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 1: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 2: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 3: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 4: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 5: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 6: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 7: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 case 8: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
 default: addr_status = 	ADDR_STATUS; addr_data =  ADDR_DATA; break;
}


 if((length_of_data > MAX_SP_LEN) || (!length_of_data))
 {
  return ReadBuffer;
 }

write_xil_char(addr_status, RESET_BIT);
*/
//____________________________________________________________________________________________
static unsigned char ReadBuffer[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block


switch(deviceindex)
{
 case 0: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 1: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 2: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 3: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindexex>>)<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 4: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 5: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 6: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 7: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 8: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 9: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 10: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 11: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 12: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 13: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 14: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 15: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 16: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_A; break;
 case 17: addr_status = 	BLOCK_SWEEP + (((deviceindex>>1))<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + (((deviceindex>>1))<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + (((deviceindex>>1))<<4) + SPI_ADR; addr_send =  BLOCK_SWEEP + (((deviceindex>>1)) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_B; break;
 case 18:
 case 19:
 case 20:
 case 21:
 case 22:
 case 23:
 case 24:
 case 25:
 case 26: addr_status = 	BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET)<<4) + ADDR_STATUS1; addr_data = BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET)<<4) +  SPI_PORT_ADDR; addr_type =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET) << 4) + SPI_ADR; addr_send =  BLOCK_SWEEP + ((deviceindex - SYNT_OFFSET) << 4) + SPI_SEND_ADDR;type_channel = CHANNEL_C;break;

 default: addr_status = 	ADDR_STATUS1; addr_data =  SPI_PORT_ADDR; addr_type =  SPI_ADR; type_channel = CHANNEL_C;break;
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

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
// printf(" %02X",* BufferDataTmp);
BufferDataTmp++;
}

//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}


#endif //N_MOD
#endif // no PROG_BMDN2

unsigned char * ReadSpiBm1(unsigned char deviceindex,unsigned long length_of_data)
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
 printf("\n\r reading error!");
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

//wh
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


extern "C" unsigned char SetLoop(unsigned char loop,unsigned long milli, unsigned char nearend, unsigned char trib)
{
 PVG610_LOOPBACK_STRUCT lbs;
 unsigned char ret;

 lbs.s.lobackType = loop; //PVG610_LOOPBACK_MODEM_E;
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

#ifdef PROG_BMDN2


extern "C" void ResetSyntOff(unsigned char deviceindex)
{
 printf("\n\r ResetSyntOff %d", deviceindex);
  unsigned long offset;


   offset = BLOCK_SWEEP1 * ((deviceindex)+1);

 //101212  offset =  (deviceindex) << 4;


//   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), SYNT_NO_RESET);
   write_xil_char((offset  + RESET_ADDR), SYNT_NO_RESET);
}

extern "C" void CommonResetOff(unsigned char deviceindex)
{
 printf("\n\r CommonResetOff %d", deviceindex);
  unsigned long offset;
//   offset =  (deviceindex) << 4;

 //   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_NO_RESET);
	  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
	write_xil_char(( offset + RESET_ADDR), COMMON_NO_RESET);

}

extern "C" void CommonResetOn(unsigned char deviceindex)
{
 printf("\n\r CommonResetOn %d", deviceindex);
  unsigned long offset;
 //  offset =  (deviceindex) << 4;
  //  write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_RESET);
	  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
	write_xil_char(( offset + RESET_ADDR), COMMON_RESET);



}




extern "C" unsigned char ModemIsUsed(unsigned char deviceindex)
{
// printf("\n\r ModemIsUsed");
#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
 if(deviceindex == 7) return 1; //for maket
#endif //MAKET_PLATA

   unsigned long offset;
//   printf("\n\r %d -> ",deviceindex);
//   deviceindex >>= 1;
//   printf(" %d ",deviceindex);
 //  offset =  (deviceindex) << 4;
     offset = BLOCK_SWEEP1 * ((deviceindex)+1);

 //  if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE)
   if(read_xil_char(offset + TYPE_ADDR) == MODEM_TYPE)
   {
 	printf("\n\r type 1C return 1");
    return 1;
	}
 //  else if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE1)
   else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE1)
   {
 	printf("\n\r type 1E return 2");
    return 2;
	}
   else if(read_xil_char( offset + TYPE_ADDR) == MODEM_TYPE2)
   {
 	printf("\n\r type 1D return 3");
    return 3;
	}

   else
   {
 //  printf("\n\r offset %x return 0", offset);
    return 0; 
   }
}
//n 0; 
//   }
//}


#else // no PROG_BMDN2
#ifndef N_MOD

extern "C" void ResetSyntOff(unsigned char deviceindex)
{
// printf("\n\r ResetSyntOff");
  unsigned long offset;
   offset =  (deviceindex + 1) << 4;
   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), SYNT_NO_RESET);
}

extern "C" void CommonResetOff(unsigned char deviceindex)
{
// printf("\n\r CommonResetOff");
  unsigned long offset;
   offset =  (deviceindex + 1) << 4;
    write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_NO_RESET);
}

extern "C" void CommonResetOn(unsigned char deviceindex)
{
// printf("\n\r CommonResetOff");
  unsigned long offset;
   offset =  (deviceindex + 1) << 4;
    write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_RESET);
}




extern "C" unsigned char ModemIsUsed(unsigned char deviceindex)
{
// printf("\n\r ModemIsUsed");
#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
 if(deviceindex == 7) return 1; //for maket
#endif //MAKET_PLATA

   unsigned long offset;
//   printf("\n\r %d -> ",deviceindex);
//   deviceindex >>= 1;
//   printf(" %d ",deviceindex);
   offset =  (deviceindex + 1) << 4;
   if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE)
   {
 //	printf("\n\r return 1");
    return 1;
	}
   else if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE1)
   {
 //	printf("\n\r return 1");
    return 2;
	}

   else
   {
 //  printf("\n\r return 0");
    return 0; 
   }
}
//n 0; 
//   }
//}

#else //N_MOD


extern "C" void ResetSyntOff(unsigned char deviceindex)
{
 printf("\n\r ResetSyntOff %d", deviceindex);
  unsigned long offset;
   offset =  (deviceindex) << 4;
   write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), SYNT_NO_RESET);
}

extern "C" void CommonResetOff(unsigned char deviceindex)
{
 printf("\n\r CommonResetOff %d", deviceindex);
  unsigned long offset;
   offset =  (deviceindex) << 4;
    write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_NO_RESET);
}

extern "C" void CommonResetOn(unsigned char deviceindex)
{
 printf("\n\r CommonResetOn %d", deviceindex);
  unsigned long offset;
   offset =  (deviceindex) << 4;
    write_xil_char((BLOCK_SWEEP + offset + RESET_ADDR), COMMON_RESET);
}




extern "C" unsigned char ModemIsUsed(unsigned char deviceindex)
{
// printf("\n\r ModemIsUsed");
#ifdef MAKET_PLATA
 //to nt hangt  if(deviceindex == 7) return 1; //for maket
 if(deviceindex == 7) return 1; //for maket
#endif //MAKET_PLATA

   unsigned long offset;
//   printf("\n\r %d -> ",deviceindex);
//   deviceindex >>= 1;
//   printf(" %d ",deviceindex);
   offset =  (deviceindex) << 4;
   if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE)
   {
 //	printf("\n\r return 1");
    return 1;
	}
   else if(read_xil_char(BLOCK_SWEEP + offset + TYPE_ADDR) == MODEM_TYPE1)
   {
 //	printf("\n\r return 1");
    return 2;
	}

   else
   {
 //  printf("\n\r return 0");
    return 0; 
   }
}
//n 0; 
//   }
//}


#endif	//   N_MOD
#endif // PROG_BMDN2




void LoadSyntm(unsigned char deviceindex)
//extern "C" void LoadSynt(void)
{
 printf("\n\r LoadSyntm : %d", deviceindex);
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
	WriteSpiBm(deviceindex,dlen,n, d
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
 
  printf("\n\r> ");
  for(long r = 0; r < buff_fill_counter; r++)
  {
   printf(" %02X", d[r]);
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
unsigned long curvar = 0xff+1; //more as maximum var

if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = 0;
}

UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
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
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
 //printf("curvar = %d",curvar);
if(variant != curvar)
{
// printf("read flash!!!");
//len = (unsigned int)ProvSizeToDownloadDCfgFile;
//__________________________________________________hier need read config_step
//unsigned long config_step;

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
config_delta += (*pBuffer++) << 18;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  config_delta = CONFIG_FILE_PROVINGENT_STEP;
printf("\n\r config_delta : %d", config_delta);	  
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
 printf("\n\r Load Synt_  %d", ir);
 //printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));
 LoadSyntDatam(im, p pBuer);
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
variant =  GetNumConfigFile(deviceindex) & CONFIG_FILE_MASK;

//__________________________________________________hier need read config_step
//unsigned long config_step;

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
config_delta += (*pBuffer++) << 18;
//printf(" %X", *pBuffer);
config_delta += (*pBuffer++) << 24;
//_____________________________________________________________
 //need use config_step for celling synt_data_offset

if((!config_delta) ||  (config_delta > MAX_CONFIG_DELTA))  config_delta = CONFIG_FILE_PROVINGENT_STEP;
printf("\n\r config_delta : %d", config_delta);	  
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
 printf("\n\r Load Synt__  %d", ir);

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
printf("\n\r>");

 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP ]);
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 1]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 2]);
 printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + 3]);


for(unsigned long its =0l; its < 100l; its++)
{
  printf(" %02X", TFTP_Buffer[CONFIG_FILE_PROVINGENT_STEP + its]);
}

 */
//_____________________________________________________________


// ir++;
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  %d", ir);
// printf("...%d",PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len));



}	 //else	 <--- need check is used
//}





//_____________________________________________________________________________________




 /*


 printf("\n\r LoadSyntm : %d", deviceindex);
//WriteSpiB(unsigned long length_of_data, unsigned char * BufferData)
unsigned char d[6];
unsigned long dlen;
deviceindex += SYNT_OFFSET;

//_________________________________________________________________
	d[0] = 0x20; d[1] = 0x15; d[2] = 0; d[3] = 0x0f; dlen = 4;
	WriteSpiBm(deviceindex,dlen, d);
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



   */

  curvar = 0xff+1;
 delay_mcs(SYNT_SET_DELAY);
}

#define	 REQUEST_QUANTITY (6)

void SendRequest(unsigned char im)
{
if(im > MODEM_QUANTITY) return;
for(long i = 0; i i < QUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5);
  embSerialACT155.AddMod(im);
}

}

#define	 RESPONSE_QUANTITY (6)
#define  FLAG_RESPONSE (0x80)

extern "C" void SendResponse(unsigned char im)
{
if(im > MODEM_QUANTITY) return;
for(long i = 0; i < REQUEST_QUANTITY; i++)
{
  embSerialACT155.AddMod(0xA5);
  embSerialACT155.AddMod(im | FLAG_RESPONSE);
}

}

extern "C" void CommutateGettedRezerv(unsigned char chn)
{

}



extern "C" void TryGetRezerv(unsigned char chn)
{
 printf("TryGetRezerv : %d", chn);
 if(currentgetrezerv == chn)  return;

 CommutateGettedRezerv(chn);
 SendResponse(chn);

}

extern "C" void CommutateHaveRezerv(unsigned char chn)
{

}


extern "C" void ValidateHaveRezerv(unsigned char chn)
{
 printf("ValidateHaveRezerv : %d", chn);
 if(currenthaverezerv == chn)  return;
 CommutateHaveRezerv(chn);
}


#define  ENABLED_REQUESTS_QUANTITY (3)
#define  ENABLED_RESPONSES_QUANTITY (3)


extern "C" void ParseRequestsRezervResponses()
{
 static unsigned char tmp;
 static unsigned char response;

 unsigned char sym;
// static unsigned char reqcounter;
 if(embMsgWestR.Used())
 {
 while(embMsgWestR.Used())
 {
  sym = embMsgWestR.Get();
  if(!(sym & FLAG_RESPONSE))
  {
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
  //	 embMsgWestR.Free();
  }
  } //flag_response
  else
  {
	//hier parse responseansvers
	 if(response == sym)
  {
   rescounter++;
  }
  else
  {
   response = sym;
   rescounter = 0;
  }

  if(rescounter >= ENABLED_RESPONSES_QUANTITY)
  {
	 ValidateHaveRezerv(response);
	 rescounter = 0;
  //	 embMsgWestR.Free();
  }



  }

 }
 }
}

#define LOCK_OK (1)
#define BAD_NOISES (0xffffffff) //????


extern "C" unsigned long CheckNoises(unsigned char im)
{
//im - channel
// CurrentErrors = 0;
  im <<= 1; //use numbers of provingents divided by 2!!!!!
  if(modemp[im].acquireStatus == LOCK_OK) {  return modemp[im].normalizedMseTenths; }
  else {return (BAD_NOISES);}
// return 0;
}



