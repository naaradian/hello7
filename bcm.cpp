#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include <mqx.h>
#include <bsp.h>
//t#include "PVG610_API.h"
#include "defs610.h"  //t
#include "bcm_uw_API.h" //t
#include "menu1.h"
#include "Temperature.cpp"
//#include "pvg710.cpp"
#pragma BSS(".buff_2")
extern uchar TFTP_Buffer1[TFTP_BUFFER_SIZE1];
#pragma BSS()
#ifdef E1_16
extern "C" void InitgBcmUwDcVarsNames(void);
extern "C" void InitgBcmUwDcVarsTypes(void);
extern "C" void InitgBcmUwDcVarsDefaultValues(void);
extern "C" void InitgBcmUwDcVarsPositions(void);
unsigned char e1_quantity;
unsigned long password_state;
unsigned long page_number;
unsigned long start_event;



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
	UnEmb2Mux34 unEmb2Mux34;
#endif
unsigned long cnt_mod;
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
	UnEmb2TypeVer unEmb2TypeVer; 
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
void t2ms(unsigned long d)
{
 delay_mcs(d * 2000l);
}
unsigned char NeedWriteID;
extern "C" void SetNeedWriteDevId(void)
{
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


//unsigned long GetProt(unsigned char provnum)
//{
// if(provnum < (MODEM_QUANTITY<<1)) return  uProt[provnum].protword;
// else return 99; 
//}
void SetProt(unsigned char provnum, unsigned long value)
{
  if(provnum < (MODEM_QUANTITY<<1)) uProt[provnum].protword = value;
}

//#define ID_CORR	 (1) //to do not use 0 as Phy ID - this value - ignored
unsigned long NeedParseFalgs;

extern "C" unsigned char SetProtLatency(BYTE deviceIndex, BYTE scIndex, BYTE usecTenths) {
unsigned char ret;
ret =  BCM_UW_API_NetFixedLatencySet(deviceIndex, scIndex, usecTenths);
printfp1("\n\r SetProtLatency");
printfpd1(" %d ", ret);
return ret;
}

extern "C" unsigned char SetProtRxForse(BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_MODE_ENUM protectionMode) {
unsigned char ret;
ret =  BCM_UW_API_ProtectionRxForceSet(deviceIndex, scIndex, protectionMode);
printfp1("\n\r SetProtRxForse");
printfpd1(" %d ", ret);
return ret;
}
extern "C" unsigned char SetProtId(BYTE deviceIndex, BYTE scIndex, BYTE txPhyId, BYTE rxPhyId) {
unsigned char ret;
ret = BCM_UW_API_ProtectionTxRxPhyIdSet(deviceIndex, scIndex, txPhyId,  rxPhyId);
printfp1("\n\r SetProtId");
printfpd1(" %d ", ret);
return ret;
}

extern "C" unsigned char SetProtIdEx(BYTE deviceIndex, BYTE scIndex, BYTE txPhyId, BYTE rxPhyId, BYTE protectionTxPhyId) {
unsigned char ret;
ret = BCM_UW_API_ProtectionTxRxPhyIdExSet(deviceIndex, scIndex, txPhyId,  rxPhyId, protectionTxPhyId);
printfp1("\n\r SetProtIdEx");
printfpd1(" %d ", ret);
return ret;
}


extern "C" unsigned char SetProtMode(BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_MODE_ENUM protectionMode, BCM_UW_PROTECTION_SYS_MODE_ENUM protectionSysMode) {
unsigned char ret;
ret = BCM_UW_API_ProtectionModeSet(deviceIndex, scIndex, protectionMode, protectionSysMode);
printfp1("\n\r SetProtMode");
printfpd1(" %d ", ret);
return ret;
}
 /*
extern "C" unsigned char GetProtStatus(BYTE deviceIndex, BYTE scIndex) {
//typedef enum {
//    BCM_UW_PROTECTION_RX_UNLOCK_E                   = 0,
//    BCM_UW_PROTECTION_RX_LOCK_E                     = 1,
//    BCM_UW_PROTECTION_RX_TR_W_E                     = 2,
//    BCM_UW_PROTECTION_RX_TR_P_E                     = 3
//} BCM_UW_PROTECTION_RX_STATE_ENUM;
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                protectionRxState;                          // see BCM_UW_PROTECTION_RX_STATE_ENUM
//    BYTE                rxPhyId;                                    //
//    BYTE                protectionRxStateExt;                       // see BCM_UW_PROTECTION_RX_STATE_ENUM
//    BYTE                protectionMode;                             // mode: 0 = none, 1 = Working, 2 = Protection
//} __PACK__ BCM_UW_PROTECTION_STATUS_STRUCT;

BCM_UW_PROTECTION_STATUS_STRUCT Ps;
unsigned char ret;
ret = BCM_UW_API_ProtectionStatusGet(deviceIndex,scIndex, &Ps);
printfp1("\n\r GetProtStatus");
printfpd1(" sc: %d ",scIndex);
printfpd1("ret: %d ", ret);
printfpd1("St: %d ", Ps.protectionRxState);
printfpd1("PhyId: %d ", Ps.rxPhyId);
printfpd1("PrStExt: %d ", Ps.protectionRxStateExt);
printfpd1("PrMode: %d ", Ps.protectionMode);
return ret;
}

 */

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
};
union uErrSN15503Work
{
   ErrSN15503Work errsn15303work;
   unsigned char byte[uerrsn15503work_SIZE];
};


#define TXT_REAL_LEN   (MAX_SIZE_TEXT_FILE - FULL_HEADER_SIZE - 4)
#define TXT_CUR_REAL_LEN   (104)
struct ModeTrunk
{
 unsigned char onpd		: 1;
 unsigned char lock_pm	: 1;
 unsigned char lock_pd	: 1;	  //low bit
};
union uModeTrunk
{
 ModeTrunk modetrunk;
 unsigned char byte;
};
uModeTrunk trunk1, trunk2;
unsigned char power1, power2;  
unsigned char crcud;
struct Mode15504
{
 unsigned char mode;
 unsigned char interf;
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
unsigned char rateSymbol0;
unsigned char rateSymbol1;
unsigned char rateSymbol2;
unsigned char rateSymbol3;
Mode15504 mode15504[8];
};
union  uConfigTxtData
{
  Emb4Md15504Cfg  emb4md15504cfg;
  unsigned char Data[TXT_REAL_LEN];
};
struct ConfigFileText
{
  unsigned long LengthTxt;//
  unsigned char Header[FULL_HEADER_SIZE];	
  uConfigTxtData  ConfigTxtData;
};
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
BYTE ProtectionRxState;
BYTE rxPhyId;
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
ConfigFileText configfilefext;
ConfigFileText configfilefext1[MAX_NUM_CFG]; //need fill at setting config file
UINT16  netE1Alarms[E1_LINES_QUANTITY];
INT16   internalAgc;            // in dB, normal range [-5 to 40]
UINT16  externalAgcRegister;    // Directly reflects PVG register
};
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
 unsigned char ModemP::Init()
{
	unsigned j;
 for(unsigned i = 0; i < 16; i++)
 {
 modulation[i] = 0;
 acmNumOfSymbols[i] = 0;
 gpiPayloadSizeInBytes[i] = 0;
 }
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
 ProtectionRxState = 0;
 rxPhyId = 0;
 absoluteMseTenths = 0;
 normalizedMseTenths = 0;
 radialMseTenths = 0;
 counterSlip = 0;	//this is 
 acmRxProfilesHistory = 0;
 acmTxProfilesHistory = 0;
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
	for(j=0; j<sizeof(ConfigFileText); j++)
		configfilefext1[i].ConfigTxtData.Data[j]=0;
/////////////////////////////////////
 return 0;
}
unsigned char ModemP::CheckIsOnStm1()
{
return 1;
}
void ModemP::SSC2(unsigned char variant)
{
//printfpd1("\n\rSSC2:%d ", variant);
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;
if(variant >= MAX_CFG_FILE_VARIANT)
{
  variant = MAX_CFG_FILE_VARIANT - 1;
}
unsigned long config_delta;
unsigned long length;
config_delta = CONFIG_FILE_PROVINGENT_STEP;
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + ((unsigned)variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
delay_mcs(DELAY_READ);
length = *pBuffer++;
length  += (*pBuffer++) << 8;
length += (*pBuffer++) << 16;
length += (*pBuffer++) << 24;
//printfpd1(" l:%d ", length);
if(length > TXT_REAL_LEN)	 length = 0l;   //120514
if(length < FULL_HEADER_SIZE)	length = FULL_HEADER_SIZE + 1;
configfilefext1[variant].LengthTxt =  length - FULL_HEADER_SIZE;
unsigned long itxt = 0l;
	for(unsigned long its = FULL_HEADER_SIZE + 4l; its < (length + 4l); its++)
	{
   		configfilefext1[variant].ConfigTxtData.Data[itxt++] = TFTP_Buffer[its];
	}
}
void ModemP::SSC1(unsigned char variant)
{
//printfp1("\n\rSSC1");
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;
}
unsigned long config_delta;
unsigned long length;
config_delta = CONFIG_FILE_PROVINGENT_STEP;
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
length = *pBuffer++;
length  += (*pBuffer++) << 8;
length += (*pBuffer++) << 16;
length += (*pBuffer++) << 24;
//printfpd1(" l:%d ", length);

if(length > TXT_REAL_LEN)	 length = 0;
if(length < FULL_HEADER_SIZE)	length = FULL_HEADER_SIZE + 1;
configfilefext.LengthTxt =  length - FULL_HEADER_SIZE;
unsigned long itxt = 0;
for(unsigned long its = FULL_HEADER_SIZE + 4; its < (length + 4); its++)
{
   configfilefext.ConfigTxtData.Data[itxt++] = TFTP_Buffer[its];
}
}

/*
void SetGEth(unsigned char im, unsigned long eth)
{
 unsigned char reg;
 reg = inportb(BLOCK_SWEEP1*(im + 1) + ETH_PORT);
 if(eth <= RATE_100M) {reg |= GETH_BIT;}
 else { reg &= ~(GETH_BIT);}
 outportb((BLOCK_SWEEP1*(im + 1) + ETH_PORT), reg);
}
*/

/*
#define FILTER_DATA_LENGTH (2)	
#define ADDR_TX	(0x19)
#define ADDR_RX	(0x24)



void SetBand(unsigned char im, unsigned long rate)
{
unsigned char Buffer[FILTER_DATA_LENGTH];
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
Buffer[0] =  ADDR_RX;
     if(rate < 16000000)  Buffer[1] = 0x6;
else if(rate < 30000000)  Buffer[1] = 0x2; 
else  				   Buffer[1] = 0x0; 
 WriteSpiBm(im + 45, FILTER_DATA_LENGTH, Buffer);
}
*/
uLevelSN15503	 ulevelsn15503;
uErrSN15503Work	 uerrsn15503work;
unsigned char staterezerv;
ModemP modemp[MODEM_QUANTITY << 1];
#define  DESTROY_SIZE (40000)
extern "C" int write_dataflash (unsigned long , unsigned int , unsigned int );

extern "C" void ConfigFileDestroy(unsigned long variant)
{
sprintf(TFTP_Buffer, "%s", "hello");
unsigned int AddressSrc =  (unsigned int)&TFTP_Buffer[0];
write_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 8 - 0x60 + (variant * CONFIG_FILE_VARIANTS_STEP)),
 (unsigned int)&TFTP_Buffer[0], DESTROY_SIZE);
printfpd1("\n\r destroy : %d", variant);
}
unsigned long ratesymbol_far;
extern "C" void DCFileLoadm1(unsigned long variant, unsigned char index)
{
BYTE *pBuffer;
BYTE *pBuffer_agc;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned char tmp;
timer_config = 0;
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;
}
UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT32 config_delta;
unsigned long ir;
#ifdef MAKET_PLATA
for(unsigned i=0; i<MAX_NUM_CFG; i++)
modemp[0].SSC2(i);
#endif 
if(1)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
#ifndef MAKET_PLATA 
 if(1)
#else
 if(1)
#endif
 {
if(variant != NUM_CALIBR_FILE)
{
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
}
config_delta = CONFIG_FILE_PROVINGENT_STEP;
AT91F_DataflashInit();
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 0x60 + (MAX_CFG_FILE_SIZE << 1) + (variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;
 GetVersionAPI();
BCM_UW_DEVCONF_STATUS_STRUCT DevConf;
unsigned char ret;
ret = BCM_UW_API_DeviceConfigure(0,pBuffer, len, &DevConf);
 #ifdef START_PRINT
 printfp1("\n\r DCFileFromHostLoad  variant:"); 
 printfpd1("%d:",variant);
 printfp1("  conf_delta: ");//%d", config_delta);
 printfpd1("%d", config_delta);
  printfp1(" len :");
 printfpd1("%d ", len);
#endif
		}
  }
 curvar = 0xff+1;
}
}


extern "C" void AGCFileLoadm1(unsigned long variant, unsigned char index)
{
BYTE *pBuffer;
BYTE *pBuffer_agc;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned char tmp;
timer_config = 0;
#ifdef YOURNAL
//Add_Event(EV_CONFIG, 1, (char*)&variant);
#endif
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;
}
UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT32 config_delta;
unsigned long ir;
#ifdef MAKET_PLATA
for(unsigned i=0; i<MAX_NUM_CFG; i++)
modemp[0].SSC2(i);
#endif 
if(1)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
#ifndef MAKET_PLATA 
 if(1)
#else
 if(1)
#endif
 {
if(variant != NUM_CALIBR_FILE)
{
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
}
modemp[im].SSC1(variant);

config_delta = CONFIG_FILE_PROVINGENT_STEP;
AT91F_DataflashInit();
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 0x60 + (MAX_CFG_FILE_SIZE << 1) + (variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;
 GetVersionAPI();
BCM_UW_DEVCONF_STATUS_STRUCT DevConf;
unsigned char ret;
   AGC_load(0 ,pBuffer);
//______________________
#ifdef START_PRINT
 printfp1("\n\r AGCFileFromHostLoad  variant:"); 
 printfpd1("%d:",variant);
 printfp1("  conf_delta: ");//%d", config_delta);
 printfpd1("%d", config_delta);
  printfp1(" len :");
 printfpd1("%d", len);
#endif
		}
  }
 curvar = 0xff+1;
}
}
extern "C" void ConfigFileLoadm2(unsigned long variant, unsigned char index)
{
BYTE *pBuffer;
BYTE *pBuffer_agc;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned char tmp;
timer_config = 0;
#ifdef YOURNAL
Add_Event(EV_CONFIG, 1, (char*)&variant);
#endif
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;

}
UINT32 len;// = (unsigned int)ProvSizeToDownloadDCfgFile;
UINT32 config_delta;
unsigned long ir;
#ifdef MAKET_PLATA
for(unsigned i=0; i<MAX_NUM_CFG; i++)
modemp[0].SSC2(i);
#endif 
if(1)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
#ifndef MAKET_PLATA 
 if(1)
#else
 if(1)
#endif
 {
if(variant != NUM_CALIBR_FILE)
{
variant =  GetNumConfigFile(im) & CONFIG_FILE_MASK;
}
modemp[im].SSC1(variant);
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
config_delta = CONFIG_FILE_PROVINGENT_STEP;
AT91F_DataflashInit();
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS - 4 + ((MAX_CFG_FILE_SIZE - 0x60) * index) +
							(variant * CONFIG_FILE_VARIANTS_STEP)),
							 (unsigned int)CONFIG_FILE_VARIANTS_STEP, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
len = *pBuffer++;
len += (*pBuffer++) << 8;
len += (*pBuffer++) << 16;
len += (*pBuffer++) << 24;
 printfpd1("\n\rcfg%d\n\r",len);
 printfp("\n\r");
for(int its =0l; its < 64l; its++)
{
 if(!(its% 16)) printfp("\n\r");
  printfpd1(" %02X", *(pBuffer+its));
}
 GetVersionAPI();
//BCM_UW_API_ConfigFileFromHostLoad(0, index, pBuffer, len); // in by
if(!hot_restart)
  {
BCM_UW_API_ConfigFileFromHostLoad(0, index, pBuffer, len); // in by
// tmp = 	PVG610_API_ConfigFileFromHostLoad(ir, 0, pBuffer, len);
 // SetGEth(ir, rateEth);
//#ifndef NO_LOAD_BANDS
//  SetBand(ir, rateSymbol);
//#endif
//   SetBand(im+1, rateSymbol); //for 1 provingent


//#ifndef USART0_TRY_PDC_1T	
// printf("\n\r PVG610_API_ConfigFileFromHostLoad  var: % d conf_del: %d num : %d ",variant, config_delta, ir);
 //printf("\n\r...%d len %d",tmp, len);
//#else
#ifdef START_PRINT
 printfp1("\n\r ConfigFileFromHostLoad  variant:"); 
 printfpd1("%d:",variant);
 printfp1("  conf_delta: ");//%d", config_delta);
 printfpd1("%d", config_delta);
 printfpd1("  num : %d ", ir);
 printfp1(" len :");
 printfpd1("%d", len);
// printfpd("...%d", tmp);
#endif
		}
  }
 curvar = 0xff+1;
}
}
}
#define  BCMSizeToDownload (36 + (1024 * 16))

extern "C" void EthFirmwareLoadm(unsigned char sc)
{
unsigned long ret;
int ix; 
BYTE *pBuffer;
if(hot_restart)
  {
  return;
 }

UINT32 len = (unsigned int)ETH_FIRMWARE_SIZE; //30584; //BCMSizeToDownload;	 //  ProvSizeToDownloadD
	pBuffer=(unsigned char*)(&TFTP_Buffer[600000]);
/*
   	printfp1("\n\r Start Load Eth Firmware first 90 :");
   	for (ix=0; ix < 90; ix++)
	 //   for (ix= BCMSizeToDownload - 90;  ix <   BCMSizeToDownload + 24 ; ix++)
        {
            if(!ix %16) { 
          printfp1("\n\r");
          OperateBuffers_usart1t();
          }
        //    memcpy((BYTE*)&tmp, (BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
            printfpd1(" %X",  (*(pBuffer+ix))); 
      }
		
   	printfp1("\n\r last 90 :");
   	for (ix=30584 - 90; ix < 30584; ix++)
	 //   for (ix= BCMSizeToDownload - 90;  ix <   BCMSizeToDownload + 24 ; ix++)
        {
            if(!ix %16) { 
          printfp1("\n\r");
          OperateBuffers_usart1t();
          }
        //    memcpy((BYTE*)&tmp, (BYTE*)(pBuf+ix*sizeof(UINT32)), sizeof(UINT32));
            printfpd1(" %X",  (*(pBuffer+ix))); 
      }
	  */
//  printfp1(" start firmware eth: ");
  unsigned long ir;
wd_reset();
ret =  BCM_UW_API_EthPortFwLoad(0, sc, pBuffer, len);
printfpd1("\n\r EthFw %d", sc);
//printfpd1(" %d", ir);
printfpd1("eth fin %d", ret);
 return; //t
}

extern "C" void  EthPortInitialize(unsigned char index) {
BCM_UW_ETH_PORT_INITIALIZE_STRUCT EInit;
  EInit.laneMapRx[0] = 0;
  EInit.laneMapRx[1] = 1;
  EInit.laneMapRx[2] = 2;
  EInit.laneMapRx[3] = 3;	  
  
  EInit.laneMapTx[0] = 0;
  EInit.laneMapTx[1] = 1;
  EInit.laneMapTx[2] = 2;
  EInit.laneMapTx[3] = 3;
  
//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortInitialize(BYTE deviceIndex, BYTE scIndex, BCM_UW_ETH_PORT_INITIALIZE_STRUCT *pInit)
BCM_UW_API_EthPortInitialize(0, index, &EInit);
}
extern "C" void FirmwareLoadm(unsigned char flagm)
{
unsigned long ret;
if(hot_restart)
  {
  return;
 }
int ix; 
BYTE *pBuffer;
UINT32 len = (unsigned int)BCMSizeToDownload;	 //  ProvSizeToDownloadD
pBuffer=(unsigned char*)(&TFTP_Buffer1[0]);
/*  
   printfp1("\n\r 4Start Load Firmware first 90 :");
   
      for (ix=0; ix < 90; ix++)
	 //   for (ix= BCMSizeToDownload - 90;  ix <   BCMSizeToDownload + 24 ; ix++)
        {
            if(!ix %16) { 
          printfp1("\n\r");
          OperateBuffers_usart1t();
          }
            printfpd1(" %X",  (*(pBuffer+ix))); 
      }
  printfp1("\n\r start send: \n\r");
*/
unsigned long ir;
if(1)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
wd_reset();
 ir = im << 1;
  ret  = BCM_UW_API_FirmwareFromHostBoot(ir, pBuffer, len, BCM_UW_DEVICE_RESET_CPU_E);  	  //may be need use first byte in my variant
 printfpd1("\n\r\Firm finish %d", ret);
 return; //t
}}
}

extern "C" unsigned char PlaModeSet(unsigned char deviceIndex, unsigned char scIndex, unsigned char mode) {
unsigned char ret; 
ret =  BCM_UW_API_PlaModeSet(deviceIndex, scIndex, mode);
printfpd1("\n\r PLA:%d", ret);
//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaModeSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_MODE_ENUM mode)
// return BCM_UW_API_PlaModeSet(deviceIndex, scIndex, mode);
return ret;
}

 extern "C" unsigned char CheckEthMode(unsigned char test)
{
 unsigned char ret = 1;
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

extern "C" unsigned char PlaStatusGet(unsigned char deviceIndex) {
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                plaMode;
//    BYTE                rxState;
//    BYTE                txState;
//    BOOLEAN             plaAISCondition;
//    BOOLEAN             cableDown;                                  // N/A 650
//} __PACK__ BCM_UW_PLA_STATUS_STRUCT;

BCM_UW_PLA_STATUS_STRUCT plaStatus;
unsigned char ret;
ret =  BCM_UW_API_PlaStatusGet(deviceIndex, 0,&plaStatus);
printfpd1("\n\rPLA Mode %d ", plaStatus.plaMode);
printfpd1("rx %d ", plaStatus.rxState);
printfpd1("tx %d ", plaStatus.txState);
printfpd1("AIS %d ", plaStatus.plaAISCondition);
printfpd1("CD %d ", plaStatus.cableDown);
return ret;
}

//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_COUNTERS_STRUCT *plaCounters)

extern "C" unsigned char PlaCountersGet(unsigned char deviceIndex) {
//typedef __PACK_PREFIX__ struct
//{
//    UINT32              splitterMasterPacketsLow;
//    UINT32              splitterMasterPacketsHigh;
//    UINT32              splitterSlavePacketsLow;
//    UINT32              splitterSlavePacketsHigh;
//    UINT32              combinerMasterPacketsLow;
//    UINT32              combinerMasterPacketsHigh;
//    UINT32              combinerSlavePacketsLow;
//    UINT32              combinerSlavePacketsHigh;
//    UINT32              fcsMasterErrorOnAirLow;
//    UINT32              fcsMasterErrorOnAirHigh;
//    UINT32              fcsSlaveErrorOnAirLow;
//    UINT32              fcsSlaveErrorOnAirHigh;
//} __PACK__ BCM_UW_PLA_COUNTERS_STRUCT;

BCM_UW_PLA_COUNTERS_STRUCT plaCounters;
unsigned char ret;
ret =  BCM_UW_API_PlaCountersGet(deviceIndex, 0,&plaCounters);
printfp1("\n\rPLA Cnt ");
printfpd1("%d ", plaCounters.splitterSlavePacketsLow);
printfpd1("%d ", plaCounters.splitterSlavePacketsHigh);
printfpd1("err:%d ", plaCounters.fcsSlaveErrorOnAirLow);
return ret;
}


extern "C" void SetEthMode(unsigned char mode)
{
  SetModEth(mode);
}

#define  DEFAULT_MODE  (ETH_AUTO)//(0x1)   //auto
void StartModems(unsigned char flagm)	//20s
{
}
  
 unsigned long 	timer_restart;
#define  TIME_WAIT_RESTART (5000)	 //121004
void HotStartConfigFile(unsigned char flagm)
{
 timer_restart = time1 + TIME_WAIT_RESTART;
 if(timer_restart < time1)
 {	 time1 = 0l;
 timer_restart = (unsigned long)TIME_WAIT_RESTART;
 }
}
void Check_restart()
{
if((timer_restart < time1) && (timer_restart))
{
timer_restart = 0;
dev_restart();
}
}
#define REZERV_PROV (0)
#define SET_MODEM_PERIOD  (50) //? need ???


struct StateRRL
{
	unsigned char ver;	
	unsigned char state;  // ��� 0: "0" - ���������� ����� � ���1, "1" - ����� ��� 1: "0" - ���������� ����� � ���2, 
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
   char compare(unsigned long , unsigned long , unsigned long , unsigned long , unsigned long);
   void add(unsigned long , unsigned long , unsigned long , unsigned long, unsigned char );
   void init(void);
};
buffcash buff_cashe_modem;
buffcash buff_cashe_tranzit;
buffcash buff_cashe_request;
void buffcash::init(void)
{
for(long i = 0; i < CASHE_SIZE; i++)
{
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
struct TOM // [TR�00MEK]
{
	unsigned char K : 1; // K - ������� ��������� ������ ���������, ��������������� � "1" ��� ��������� ������ ���������;
	unsigned char E : 1; // E - ��� ������ � CRC, ��������������� � "1" ���� �� �������� CRC;
	unsigned char M : 1; // M - ��� ��������, ��������������� � "1" ��� ������� ������ "��������� ��������";
	unsigned char reserved : 2;
	unsigned char C : 1; // R - ������� ��������� �� RS-485 (��� ������ �������)
	unsigned char R : 1; // C - ��������������� � "1" ���� ��� ������ ���������� ������������� � �������.
	unsigned char T : 1; // T - ��� �������; 
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
	void SetDir(unsigned char d) { dir= d; } // dir = 1 ������ � West, dir=2 ������ � East
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
 #ifdef DEBUG_LOOP_PRINT
			printfpd("\n\rc= %02X", c);	
			printfpd("b= %02X\n\r", b);	
 #endif
			if(b==c) return 1;
			else return 0;
		}
    return 1;
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
  if(n == (BuffSize - 1))  {
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
#include "embmsg485.cpp"
#define   EmbMsg485Buffer_Size (16)
struct EmbMsg485Buffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
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
   return n;
   }
  else
  {	 
  if(n == (BuffSize - 1))  {
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
struct StateBMD155
{
	unsigned char state;  // ��� 0: "0" - ���������� ����� � ���1, "1" - �����
									// ��� 1: "0" - ���������� ����� � ���2, "1" - �����
									// ��� 1: "0" - ���������� ����� ��, "1" - �����
	unsigned char state2;  // ��������� ����� �����������
	unsigned char ppu1_bytes[16];
	unsigned char ppu2_bytes[16];														// 34
	unsigned long count_no_correct_block1;									// 42
	unsigned long count_no_correct_block2;									// 46
	unsigned long count_no_correct_result;									// 50
	unsigned long count_notRS1;															// 54
	unsigned long count_notRS2;															// 58
	unsigned long count_block;															// 62
	unsigned char mod; // ��������� ����� �����������       // 63
	unsigned char dem1; // ��������� ����� �����������      // 64
	unsigned char dem2; // ��������� ����� �����������      // 65
	unsigned char state_dem1; // ��������� ����� �����������// 66
	unsigned char state_dem2; // ��������� ����� �����������// 67
	unsigned char statePI; // ��������� ����� �����������		// 68	
	unsigned char loopPI; // ��������� �������							// 69
	unsigned char demPI; // ��������� �������������					// 70
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
	EmbTimer embTimer;
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
#ifndef ETH_TRANZIT
EmbMsg embMsg232E;
#endif // ETH_TRANZIT
 EmbMsg embMsg485E;
 EmbMsg embMsgWest[MODEM_QUANTITY]; //101224 many channells to keep messages
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
	EmbMsg *embMsgRequest;
	EmbRS232 embRS232;
	EmbRS485 embRS485;
    UnStateRRL unStateRRL;
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
    unsigned char * bt;
	unsigned short addr1;
	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
	unsigned char mode5A=0, mode5AWest[MODEM_QUANTITY], mode5AEast=0;
   	unsigned char mode5AUp1, mode5AUp2; 
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;
	unsigned char modeA5West[MODEM_QUANTITY];
	TRBuffer<char,ACT_BUFFER_SIZE> embMsgWestR[MODEM_QUANTITY];
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
	UnStateBMD155 unStateBMD155p[MODEM_QUANTITY];
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
#define PERIOD_MIN_MAX 	(2)
#define   NO_LOCK_LEVEL (-100)
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
	  if(flag_min_max >= PERIOD_MIN_MAX)
	  {
	    flag_min_max = 0;
	   outportb((BLOCK_SWEEP1*(i + 1) + FAR_LED_PORT), req);
	  }
	 farinplev1 = NO_LOCK_LEVEL;
	 farinplev2 = NO_LOCK_LEVEL;
  }
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
			case 0xA5: recieveWest[i] = 1; modeA5West[i]=1; markerWest[i]  = 1; ready_mod[i]=1; time3BlankMod[i] = /*time3Marker[i] =*/ time1; break; // �������� ����� ���!
			case 0x5A: mode5AWest[i]=1; ready_mod[i]=1; break;
			default:
				if(markerWest[i]==1)	markerWest[i]=2; 
				if(recieveWest[i]==1)
				{
				 if(modeA5West[i]) { embMsgWestR[i].Add(westByte); modeA5West[i]=0;	
//				  ParseRequestsRezervResponsesi(i);
				 }
					else if(mode5AWest[i]) { embMsgWest[i].Add(Modify5A(westByte)); mode5AWest[i]=0;	}
				  //	else if(modeA5West) { embMsgWestR.Add(westByte); modeA5West=0;	}
					else embMsgWest[i].Add(westByte);
				}
			}
if(embMsgWest[i].IsEnd())
   {
   recieveWest[i] = 0;
#ifdef CHECK_CRC   
  if(embMsgWest[i].ChkCRC()) //120608	  //091111
#else  
	if(1)
#endif   
	{						   //091111
 cnt_mod++;
#ifdef SEND_STATUS
 if(embMsgWest[i].AddrS() == DEFAULT_ADDR)
 {
   flag_min_max = 0;// ??? 170118
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
#endif
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
   outportb((BLOCK_SWEEP1*(i + 1) + FAR_LED_PORT), req);
  embMsgWest[i].Init();	 //121204
   return 0;
 }
#endif //send status
   	if((embMsgWest[i].AddrS()!=SelfID())&&(embMsgWest[i].AddrI()!=SelfID()))
	{
			 if(ForwardingEnabled())
   		   	{
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
				  #ifdef DEBUG_TRANZIT
					  if(i == 1) printfpd(" w : %02X ", embMsgA.body[i])	;
				#endif
					}
				}
				    embSerialACT155.AddTransitM(0x55);
			}
		}  //is end
 return 0;
}
char ProtocolFromTransitACT155()
{
	int ic=0;
	unsigned char chn;
	while(embSerialACT155.UsedTransit())
	{
		eastByte = embSerialACT155.GetTransit();
	   switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init();//tInitEastE(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init();//t InitEastE(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit /*= time3Marker*/ = time1;  break; // �������� ����� ���!
					// ���� � ������� ���� ����� �� ��������, �� �������� ���
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
			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{
		   if(ForwardingEnabled())
   		   	{
             chn = 	0;//GetChannelToSend();		
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
//		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
                chn = 	0;//GetChannelToSend();	
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
				}
				embSerialACT155.AddModM(0x55, chn);
			}
		  		}  //(1)
	return 0;
}
#define TRANZIT_SEND_PERIOD (4500) //9 modems - *9
void Check2InitTransitMod()
{
unsigned char chn;
	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
// ���� ��������� ��������� ready_transit ��� ready_mod �� "0" � "1"
// �� time3Marker = 0; ��� ����� 2355 ����� � �������� 64�*8/11=46545
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
					if(tBuffEmbMsgEast.Used())
		{
	   
	  chn =  0;//	GetChannelToSend();
	  if(chn == NO_MODEM)
	  {
	   return;
	   }
	   else
	   {
  //	   printfpd("\n\rich : %d", chn);
	   } 	
				if(!embSerialACT155.UsedSendMod(chn)) 
				{	
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);
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
    #ifdef DEBUG_TRANZIT
					  if(i == 1) printfpd(" w1 : %02X ", embMsgA.body[i])	;
	#endif
						}
					}
					embSerialACT155.AddTransitM(0x55);
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
unsigned char	ab4[] =	{ 0x45,0x28,0x43,0x8a,0xBc,0x27,0x88,0x00,0x00,0x00 }; // AR-Filter - ������ 20
unsigned char	ab5[] =	{ 0x45,0x48,0x96,0x38,0x29,0x96,0xC9,0x2B,0x8B,0x00 }; /// LPR-Filter       
unsigned char	ab6[] =	{0x45,0x20,0x08,0x90,0x3F,0xBC,0x75,0x28,0x72,0x07}; // FRX-Filter       
unsigned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x85,0x50,0xc0,0x1a}; // AX-Filter -������ 20
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
unsigned char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xC0,0x04}; // AX-Filter -������ 29
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
unsigned char	a22[] =	{ 0x02 };  // AKTIV mode -- ����������� ���������
unsigned char	a221[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a222[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE
unsigned char	a26[] =	{ 0x02 }; // RING pause MODE -- ��������� ���
unsigned char	a261[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a262[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE 2
unsigned char	a263[] =	{ 0x02 }; // RING pause MODE -- ��������� ���
unsigned char	a264[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a265[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x00); // off hook
// RING
unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- ������ ������
unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x00); // �n hook
// WAIT
unsigned char	a28[] =	{ 0x07 }; // power dnv mode -- �������� �������� ������
//outportb(0x511, 0x00); // on hook
unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 
void InitTLF()
{
	int i;
// ����� ������
	for(i=0; i<15; i++) outportb(0x11, 0x08); 
	outportb(0x11, 0x00);
	for(i=0; i<10000; i++);

	outportb(0x10, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x0F, ab1[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab1); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x0F, ab2[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab2); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x0F, ab3[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab3); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x0F, ab4[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab4); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x0F, ab5[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab5); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x0F, ab6[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab6); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x0F, ab7[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab7); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x0F, ab8[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab8); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x0F, ab9[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab9); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x0F, ab10[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab10); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x0F, ab11[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab11); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x0F, ab12[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab12); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x0F, ab13[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab13); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x0F, ab14[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab14); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x0F, ab15[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab15); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x0F, ab16[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab16); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x0F, ab17[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab17); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x0F, ab18[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab18); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x0F, ab19[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab19); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x0F, ab20[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab20); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x0F, ab21[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab21); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab22); i++) outportb(0x0F, ab22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab23); i++) outportb(0x0F, ab23[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab23); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab24); i++) outportb(0x0F, ab24[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab24); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab25); i++) outportb(0x0F, ab25[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab25); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab26); i++) outportb(0x0F, ab26[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab26); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab27); i++) outportb(0x0F, ab27[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab27); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab28); i++) outportb(0x0F, ab28[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab28); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab29); i++) outportb(0x0F, ab29[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab29); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(ab30); i++) outportb(0x0F, ab30[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(ab30); i++);
}
void Ring()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x0F, a272[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a272); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x0F, a271[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a271); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x0F, a27[i]);   outportb(0x10, 0x01);   for(i=0; i<200*sizeof(a27); i++);
  outportb(0x11, 0x00); // �n hook
}
void Active()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x0F, a221[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x0F, a222[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a222); i++);
	outportb(0x11, 0x04); // off hook
}
void Pause()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x0F, a26[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a26); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a261); i++) outportb(0x0F, a261[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a261); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a262); i++) outportb(0x0F, a262[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a262); i++);
	outportb(0x11, 0x04); // off hook
}
void Pause2()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a263); i++) outportb(0x0F, a263[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a263); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a264); i++) outportb(0x0F, a264[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a264); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a265); i++) outportb(0x0F, a265[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a265); i++);
	outportb(0x11, 0x00); // off hook
}
void Wait()
{
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x0F, a22[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x0F, a221[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x10, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x0F, a222[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a222); i++);
//	outportb(0x10, 0x02); for(i=0; i<sizeof(a28); i++) outportb(0x0F, a28[i]); outportb(0x10, 0x01); for(i=0; i<200*sizeof(a28); i++);
	outportb(0x11, 0x00); // on hook
}
void Read()
{
// ������  ��������/������ �� SPI
// outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01);
// while((inportb(0x510) & 0x01)!=0);
// ������ �������� ������  �� ������  0x50F ����������� ������� �� ���� ������� �  ����������
	int i;
	outportb(0x10, 0x02); for(i=0; i<sizeof(aa); i++) outportb(0x0F, aa[i]); outportb(0x10, 0x01); inportb(0x10); for(i=0; i<200*sizeof(aa); i++);
	for(i=0; i<7; i++) aaa[i] = inportb(0x0F);
}
union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};
union UI2UC
{
	unsigned long ui;
	unsigned char uc[4];
};

unsigned char IsEthTransitMode(void)
{
 if (read_nvram_char(ETH_TRANZIT_ON_ADDRESS) ==	 ETH_TRANZIT_ON_VALUE) return 1;
 else return 0;
}
unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;
UL2UC ul2uc;
UI2UC ui2uc;
unsigned long sendboxes;
unsigned long receivedboxes;
unsigned long error_timer;
unsigned char current_channel;
unsigned long used_modems;
long err_tmp_prev1 = 0l;
long err_tmp_prev3 = 0l;
long err_tmp_prev4 = 0l;

extern "C" void Init_structs()
{
 for(long ic = 0; ic < (MODEM_QUANTITY); ic++)
  {
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
//StatRez statrez[MODEM_QUANTITY];
unsigned long protection_mode;
unsigned long norma_status[MODEM_QUANTITY << 1];
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
unsigned char used_TCP;
unsigned long ver_api;
unsigned char send_keeper1, send_keeper2;
unsigned char  hot_restart;
unsigned long syntez_error_counter;
unsigned long pvg710_error_counter;
unsigned long flagproti;
char RBUFU2[RBUFU2_SIZE];
int  RBufu2pos;
unsigned char flag_read;
				  

#ifdef PROG_MD310_SAT
unsigned long SetACMCounter;
#endif

extern "C"   void SetUsart2BaudRate(unsigned long);

//okconst char CTchar[20000] ={0};	//for test
//const char CTchar[80000] ={0};	//for test

extern "C" void Init_BMDN(void)
{
  long mirror_wd = 10;
  printfp1("\n\r init bcm \n\r");   //try debug in uart1
  SetUsart2BaudRate(115200l);
  RBufu2pos = 0;
  cnt_mod = 0;
  unEmb2Mux34.emb2Mux34.numE1 = 16;
  for(i=0; i<unEmb2Mux34.emb2Mux34.numE1; i++)
	{
		unEmb2Mux34.emb2Mux34.ctrl_e1[i] = 0;
		unEmb2Mux34.emb2Mux34.state_e1[i] = 0;
	}
  while(!MirrorTest())
  {
    mirror_wd--;
	delay_mcs(1000);
	if(! mirror_wd) break;
  }
 flagproti  = 1;
 syntez_error_counter = 0;
 pvg710_error_counter = 0;
 hot_restart = 0;
 txusart = rxusart = 0;
 send_keeper1 = send_keeper2 = 1;
 //ver_api = GetVersionAPI();
 used_TCP = 0;
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
OldStatus = 0x0F;
timer_restart = 0l;
cur_err = 0;
flag_trunk = 0;
currenttrunk = 0;
trunk1.byte = 0;
trunk2.byte = 0;
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
flagModForSS  = GetModForSS() +  (GetModForSS1() << 1);
unStateRRL.stateRRL.ver = 0x01;
unStateRRL.stateRRL.state = 0x01;
countUD1=0;
countUD2=0;
mode5AUp1 = 0;
mode5AUp2 = 0; 
oldflag = 0xff;
oldflag_710 = 0xff;
oldflag_ud1 = 0xff;
oldflag_ud2 = 0xff;
oldflag_prv = 0xff;
oldflag_prv1 = 0xff;
dev_status = 0x0;
acmmask0 = 0;
ans_correct = 0;
ans_correctr = 0;
ans_no_correct = 0;
ans_no_correctr = 0;
time_start_prt = 0;
time_rcv_req_to_get = 0;
time_end_prt = 0;
for(unsigned long im= 0; im < (MODEM_QUANTITY<<1); im++)
{
 norma_status[im] = ALARM_QUANTITY + 1; //0;
}
NeedWriteID = 0;
protection_mode = MODE_1_PLUS_1;
currentgetrezerv = NO_MODEM;
currenthaverezerv = NO_MODEM;
currentrezerv = NO_MODEM;  //this make error
RestartTestE = 0;
RestartTest = 0;
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
  embMsgWestR[i].Init();
 reqcounter[i] = 0;
 rescounter[i] = 0;
 }
    cycle=0;
	ttbb=0;
	mtbb=0;
	count_tr=0;
	count_md=0;
	err_tr=0;
	err_md=0;
	rrr=0;
//#ifdef PROG_BMDN6	//131227
//#ifndef PROG_BMDN6M
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
   ab4[0] =	0x45;ab4[1] =0x28;ab4[2] =0x43;ab4[3] =0x8a;ab4[4] =0xBc;ab4[5] =0x27;ab4[6] =0x88;ab4[7] =0x00;ab4[8] =0x00;ab4[9] =0x00; // AR-Filter - ������ 20
   ab5[0] = 0x45;ab5[1] =0x48;ab5[2] =0x96;ab5[3] =0x38;ab5[4] =0x29;ab5[5] =0x96;ab5[6] =0xC9;ab5[7] =0x2B;ab5[8] =0x8B;ab5[9] =0x00; /// LPR-Filter       
   ab6[0] =	0x45;ab6[1] =0x20;ab6[2] =0x08;ab6[3] =0x90;ab6[4] =0x3F;ab6[5] =0xBC;ab6[6] =0x75;ab6[7] =0x28;ab6[8] =0x72;ab6[9] =0x07; // FRX-Filter       
   ab7[0] =	0x45;ab7[1] =0x30;ab7[2] =0xBE;ab7[3] =0x04;ab7[4] =0xB0;ab7[5] =0x27;ab7[6] =0x85;ab7[7] =0x50;ab7[8] =0xc0;ab7[9] =0x1a; // AX-Filter -������ 20
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
   ab20[0] = 0x45;ab20[1] =0x98;ab20[2] =0x00;ab20[3] =0x00;ab20[4] =0x00;ab20[5] =0x00;ab20[6] =0x00;ab20[7] =0x00;ab20[8] =0x00;ab20[9] =0x00;  // Rese20[8] =0x00;ab20[9] =0x00;  // Rese30;ab21[2] =0xBE;ab21[3] =0x04;ab21[4] =0xB0;ab21[5] =0x27; // AX-Filter -������ 29
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
   a22[0] =	 0x02;  // AKTIV mode -- ����������� ���������
   a221[0] = 0x44;a221[1] =0x1c;a221[2] =0x22; // LMCR1
   a222[0] = 0x44;a222[1] =0x1A;a222[2] =0x00; // dscr
//outportb(0x511;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE
   a26[0] =	0x02; // RING pause MODE -- ��������� ���
   a261[0] = 0x44;a261[1] =0x1c;a261[2] =0xAA; // LMCR1
   a262[0] = 0x44;a262[1] =0x1A;a262[2] =0x05; // dscr
//outportb(0x511;ab6[0] = 0x04);ab6[0] = // off hook
// PAUSE 2
   a263[0] = 0x02; // RING pause MODE -- ��������� ���
   a264[0] = 0x44;a264[1] =0x1c;a264[2] =0xAA; // LMCR1
   a265[0] = 0x44;a265[1] =0x1A;a265[2] =0x05; // dscr
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // off hook
// RING
   a272[0] = 0x05; // RING burst MODE -- ������ ������
   a271[0] = 0x44;a271[1] =0x1c;a271[2] =0x22;  // LMCR1
   a27[0] =	 0x44;a27[1] =0x1A;a27[2] =0x00; // dscr
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // �n hook
// WAIT
   a28[0] = 0x07; // power dnv mode -- �������� �������� ������
//outportb(0x511;ab6[0] = 0x00);ab6[0] = // on hook
   aa[0] =  0xC4;aa[1] =0x07;aa[2] =0xFF;aa[3] =0x00;aa[4] =0x00;aa[5] =0x00;aa[6] =0x00; 
//#endif
//#endif
	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
	tBuffEmbMsg485Request_1.Init();
	tBuffEmbMsg485Request_2.Init();
	rBuffEmbMsg.Init();
    tBuffRS485.Init();
    time_lastsend_rs485 = 0;
    flag_wait_rs485 = 0;
	embSerialACT155.Init();	//120608   //hier hangt!!!!
	embTimer.Init(10); // *0,1 ms ���� ���������� ���������� �� �������
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // ����� ������� 1 ��� �� N ������������ �������
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
 	InitTLF();
	for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
	tlf_counter=0;
	for(i=0; i<MODEM_QUANTITY<<1; i++)
	{
   		modemp[i].alarm = 0;
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
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
	unEmb2TypeVer.emb2TypeVer.type       = 0x0115;
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
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = read_xil_char(1);
			unEmb2TypeVer.emb2TypeVer.signature_hardware[14] = read_xil_char(2);
			unEmb2TypeVer.emb2TypeVer.signature_hardware[15] =  read_nvram_char(RESTARTS_NVRAM_ADDRESS);
	write_nvram_char(RESTARTS_NVRAM_ADDRESS, (unEmb2TypeVer.emb2TypeVer.signature_hardware[15] + 1));
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
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+ETH_TRANZIT_ON_ADDRESS); 
	Wait();
	presto_time = time1;
    embMsg232.Init();
    embMsg232E.Init();
    embMsg485E.Init();
    embMsgEast.Init();
    embMsgAns.Init();
    embMsgRequest = NULL;
    InitOperProg();
#ifdef USE_HTTP
    Init_web_prm();
#endif

if(!MirrorTest()) {
  printfp1("\n\r MirrorTest Wrong\n\r");
#ifndef MAKET_PLATA
   return;
#endif
}
unsigned long ir;
#ifndef BMDN_CONNECT_USART
InitSpiCS2B();
for(im= 0; im < MODEM_QUANTITY; im++)
{
ir = im << 1;
 BCM_UW_API_ComConfigure(ir, BCM_UW_COM_MEDIA_SPI_E, BCM_UW_COM_MEDIA_SPI_E, FREQ_SYNT);
}
//#endif //MANY_MODEMS
#else
for(im= 0; im < MODEM_QUANTITY; im++)
{
ir = im << 1;
BCM_UW_API_ComConfigure(ir, BCM_UW_COM_MEDIA_UART_E, BCM_UW_COM_MEDIA_UART_E, FREQ_SYNT);
}
#endif
SetUsart0BaudRate(38400l);
staterezerv = 0;
used_modems = 0;
unsigned short mod_mask = 1;
unsigned char typemodem;
InitgBcmUwDcVarsNames();
InitgBcmUwDcVarsTypes();
InitgBcmUwDcVarsDefaultValues();
InitgBcmUwDcVarsPositions();
read_dataflash ((unsigned int)XilFileDataAddressD_BCM,  (unsigned int)FIRMWARE_SIZE + 100, (char *)(&TFTP_Buffer1[0])); //firm ware full file
read_dataflash ((unsigned int)XilFileDataAddressD_BCM1, (unsigned int)ETH_FIRMWARE_SIZE + 100, (char *)(&TFTP_Buffer[600000]));	//t
flag_read = 0;
   ver_api = GetVersionAPI();
//if(ver_api == (unsigned long)CURRENT_VER_API)
 if(ver_api != (unsigned long)BAD_VALUE_ANS)	
{
//temporary  hot_restart = 1;
printfp1("\n\r Hot Restart!");
  hot_restart = 0; //1; temporary
 //temporary ? return;	  //if make this lock do not loss
}
else {
printfp1("\n\r Cold Restart!");
  hot_restart = 0;
}
//printfp1("\n\rfinish  init bcm \n\r");
//treturn;

for(im= 0; im < MODEM_QUANTITY; im++)
{
 //Modem[im].Init();
//#ifndef MAKET_PLATA
  typemodem = 1; // ModemIsUsed(im);

 if(typemodem)
//#else
 //if(1)
//#endif
 {
   used_modems |= mod_mask;
   SetModemStruct(im,typemodem);
//   SetModemXILNPL1m(im);	 //120316
 if(!hot_restart)
  {
 //  CommonResetOn(im);
 //  delay_mcs(1000l);
 //  ResetSyntOff(im);
 //  CommonResetOff(im);
  } // hot_restart
 }
  mod_mask <<= 1;
}	//for im


//#endif
// if(!hot_restart)
//  {
//    delay_mcs(SYNT_SET_DELAY);	  //1 c ?
//  }

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
// StartModems(MODEM_QUANTITY);
 wd_reset();
}
else
{
// printfp("\n\r... mode 0x8e");
}
 EnablePhone();
 SetCurrentTrunk(1); //get on trunk
 hot_restart = 0; // to be loading all in work

printfp1("\n\rfinish  init bcm \n\r");
}



#define SCAN_PERIOD (10000) //10c
#define READ_ERRORS_PERIOD (3000) //1c

extern "C" void UpdateErrors(unsigned char mod)
{
 unsigned char deviceindex = mod << 1;
if((modemp[deviceindex].configfilefext.ConfigTxtData.emb4md15504cfg.numProvCode & MASK_BIT_1))
{
  unStateBMD155p[mod].stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
  unStatePUM.statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
//			������� ����� �������� �������	16 ���
  unStateBMD155p[mod].stateBMD155.count_block 			  =	 modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_block 			  =	 modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulBlock 					 	  +=  modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUM.statePUM.ulBlock 					 	  +=  modemp[deviceindex].fecBlockCounter;// Fc.protectionRxBytesFromProtection;
//			������� ������ �� ������������ �� � 1 ������
  unStateBMD155p[mod].stateBMD155.count_notRS1 			  =	 modemp[deviceindex].fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS1 			  =	 modemp[deviceindex].fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
//			������� ������, ������������ �� � 1 ������
  unStateBMD155p[mod].stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
   unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
//			������� ������ �� ������������ �� � 2 ������
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
  unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].fecUncorrectedBlockCounter;
//			������� ������, ������������ �� � 2 ������
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].fecUncorrectedBlockCounter;
  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].fecUncorrectedBlockCounter;
}
else //rs
{
  unStateBMD155p[mod].stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_no_correct_result =   modemp[deviceindex].protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
  unStatePUM.statePUM.ulErrOut 					 	+= modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorBytytounter;;
//			������� ����� �������� �������	16 ���
  unStateBMD155p[mod].stateBMD155.count_block 			  =	 modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStateBMD155.stateBMD155.count_block 			  =	 modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUMp[mod].statePUM.ulBlock 					 	  +=  modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
  unStatePUM.statePUM.ulBlock 					 	  +=  modemp[deviceindex].rsByteCounter;//fecBlockCounter;// Fc.protectionRxBytesFromProtection;
//			������� ������ �� ������������ �� � 1 ������
  unStateBMD155p[mod].stateBMD155.count_notRS1 			  =	 modemp[deviceindex].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS1 			  =	 modemp[deviceindex].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrAfterRS1 				  +=	 modemp[deviceindex].protectionUncorrectedBytes;
//			������� ������, ������������ �� � 1 ������
  unStateBMD155p[mod].stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block1 	=	 modemp[deviceindex].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
  unStatePUM.statePUM.ulErrBeforeRS1 				  	+=   modemp[deviceindex].protectionUncorrectedBytes;
//			������� ������ �� ������������ �� � 2 ������
  unStateBMD155p[mod].stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStateBMD155.stateBMD155.count_notRS2 			  =	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStatePUMp[mod].statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;
  unStatePUM.statePUM.ulErrAfterRS2 				  +=	 modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
//			������� ������, ������������ �� � 2 ������
  unStateBMD155p[mod].stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStateBMD155.stateBMD155.count_no_correct_block2 	=	 modemp[deviceindex+1].protectionUncorrectedBytes;// Fc.rsErrorByteCounter;
  unStatePUMp[mod].statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
  unStatePUM.statePUM.ulErrBeforeRS2 				  	+=   modemp[deviceindex+1].rsErrorByteCounter;//fecUncorrectedBlockCounter;
 }
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
}

extern "C" void ReadErrorsm(unsigned char mod, unsigned char scindex) {
BCM_UW_MODEM_FEC_COUNTERS_STRUCT Fc;
BCM_UW_MODEM_STATUS_STRUCT Ms;
BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT Ac;
BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT ERc;
unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = dev_status;
BCM_UW_ERROR_MSG_ENUM ans;
static unsigned long counter;
unsigned char deviceindex = mod + scindex;//190409 << 1;
ans = BCM_UW_API_EthPortRxCountersGet(mod,scindex, 0, &ERc);
printfp1("\n\r EthPortRxCountersGet ");
printfpd1("a-> %d ", ans);
printfpd1("m %d ", mod);
printfpd1("s %d ", scindex);
printfpd1(" %d", ERc.rxMulticastPacketsHi);
printfpd1(" %d", ERc.rxMulticastPacketsLo);
//if(ans) return;

 if(ans)	 //hier bad answers
 {
 norma_status[deviceindex]++;// |= ALARM_ANS; 
// check_norma_status++;
 if(norma_status[deviceindex] > (ALARM_QUANTITY + 1))  //bad answer
{
	norma_status[deviceindex]--;   //to not get to maximum and next step to zero
	if(!modemp[deviceindex].alarm)
	{
	modemp[deviceindex].alarm = 1;
#ifdef YOURNAL
  	Add_Event(EV_ALARM, 1, (char*)&deviceindex);
#endif
	}
}
if(GetTestMode() == 0x5A)
{
counter++;
if(counter > 5000)
{ 
 counter = 0;	 //to can print enover modem
//#ifdef START_PRINT
 printfp1("\n\rAlarm ans :");
 printfpd1("%d", ans);
 printfpd1("dev %d",deviceindex);
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
#ifdef YOURNAL
  	Add_Event(EV_NO_ALARM, 1, (char*)&deviceindex);
#endif
	}
 }
ans = BCM_UW_API_ModemStatusGet(mod,scindex, &Ms);
//printfp1("\n\r StatusGet ");
//printfpd1(" (%d)", deviceindex);
//printfpd1("-> %d", ans);

//printfpd1(" %d", ans);
//printfpd1("rasc:%d" , Ms.acquireStatus);	   
//printfpd1("\n\rcar:%d" , Ms.carrierOffset);
 if(ans)	 //hier bad answers
 {
 norma_status[deviceindex]++;// |= ALARM_ANS; 
// check_norma_status++;
 if(norma_status[deviceindex] > (ALARM_QUANTITY + 1))  //bad answer
{
	norma_status[deviceindex]--;   //to not get to maximum and next step to zero
	if(!modemp[deviceindex].alarm)
	{
	modemp[deviceindex].alarm = 1;
#ifdef YOURNAL
  	Add_Event(EV_ALARM, 1, (char*)&deviceindex);
#endif
	}
}
if(GetTestMode() == 0x5A)
{
counter++;
if(counter > 5000)
{ 
 counter = 0;	 //to can print enover modem
//#ifdef START_PRINT
 printfp1("\n\rAlarm ans :");
 printfpd1("%d", ans);
 printfpd1("dev %d",deviceindex);
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
#ifdef YOURNAL
  	Add_Event(EV_NO_ALARM, 1, (char*)&deviceindex);
#endif
	}
 }

if(ans) return;
 modemp[deviceindex].acquireStatus =   Ms.acquireStatus;
// printfpd1("\n\r1: %d", Ms.acquireStatus);
//     FillLock(mod,Ms.acquireStatus);
     FillLock(deviceindex,Ms.acquireStatus);
     modemp[deviceindex].internalAgc = Ms.internalAgc;            // in dB, normal range [-5 to 40]
     modemp[deviceindex].externalAgcRegister = Ms.externalAgcRegister;    // Directly reflects PVG register
//  modemp[deviceindex].acmEngineEnabled =   Ms.acmEngineEnabled;
 modemp[deviceindex].acmEngineEnabled =   Ms.acmEngineRxSensorsEnabled;
//    BOOLEAN             acmEngineRxSensorsEnabled;                  // ACM engine Rx enable\disable
//    BOOLEAN             acmEngineTxSwitchEnabled;                   // ACM engine Tx enable\disable
 //  if(Ms.acmEngineEnabled)
   if(Ms.acmEngineRxSensorsEnabled)
   {
	 modemp[deviceindex].txAcmProfile =   Ms.txAcmProfile;
     modemp[deviceindex].rxAcmProfile =   Ms.rxAcmProfile;
   }
   else
   {
	 modemp[deviceindex].txAcmProfile =   ACM_MODES;
     modemp[deviceindex].rxAcmProfile =   ACM_MODES;
   }
 /* 110823
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
 */
 unStatePUM.statePUM.state[7] = Ms.normalizedMseTenths;//2
 unStatePUM.statePUM.state[8] = Ms.normalizedMseTenths >> 8;//2
modemp[deviceindex].counterSlip =   Ms.lastAcquireError;
modemp[deviceindex].absoluteMseTenths =   Ms.absoluteMseTenths;
modemp[deviceindex].normalizedMseTenths =   Ms.normalizedMseTenths;
modemp[deviceindex].radialMseTenths =   Ms.radialMseTenths;
ulevelsn15503.levelsn15503.absoluteMse[mod] = Ms.absoluteMseTenths;
ulevelsn15503.levelsn15503.normalizedMse[mod] = Ms.normalizedMseTenths;
ulevelsn15503.levelsn15503.radialMse[mod] = Ms.radialMseTenths;

//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcquireCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT *pAc)
ans = BCM_UW_API_ModemAcquireCountersGet(mod,scindex, &Ac);
//printfp1("\n\r AcquireCountersGet ");
//printfpd1(" %d", ans);
//printfpd1("\n\rasc:%d" , Ms.acquireStatus);	   
//printfpd1("\n\rcar:%d" , Ms.carrierOffset);
if(ans) return;
//#ifdef USART0_TRY_PDC_1T
//  printfpd("\n\raf%ld", time1);
//#endif

uerrsn15503work.errsn15303work.counterSlip[mod] +=   Ac.numLolEvents;

//if(!(Ac.numLolEvents)) //110823
if(!scindex) {
 if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) ) //121016
//121016if(Ms.acquireStatus) //110922 maked temporary without counters
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL1_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL1_LOCK_BIT;//2
}
} else { //scindex  
if( (!(Ac.numLolEvents)) && (Ms.acquireStatus) )
{
 unStatePUM.statePUM.state[2] &= ~(CHANNEL2_LOCK_BIT);//2
}
else
{
 unStatePUM.statePUM.state[2] |= CHANNEL2_LOCK_BIT;//2
}
}
//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemFecCountersGet(BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_FEC_COUNTERS_STRUCT *pFc)
ans = BCM_UW_API_ModemFecCountersGet(mod, scindex, &Fc);
//printfp1("\n\r FecCountersGet ");
//printfpd1(" %d", ans);
if(ans) return;
// #ifdef USART0_TRY_PDC_1T
//  printfpd("\n\rff%ld", time1);
//#endif

//    printf("\n\rread mod : %d errors:%ld", (mod << 1), );
/*
typedef __PACK_PREFIX__ struct
{
    UINT32              fecLdpcBlockCounter;                        // cumulative, clear on read
    UINT32              fecLdpcUncorrectedBlockCounter;             // cumulative, clear on read
    UINT32              fecRsBlockCounter;                          // cumulative, clear on read
    UINT32              fecRsUncorrectedBlockCounter;               // cumulative, clear on read
    UINT32              ldpcAvgIterations;                          // in 1/32768 iterations units
    UINT32              rxBytesFromProtection;
    UINT32              rxErrBytesFromProtection;
    UINT32              rxBytesFromWorking;
    UINT32              rxErrBytesFromWorking;
    UINT32              rxOutputTotalBytes;
    UINT32              rxOutputTotalErrBytes;
    UINT32              rsAvgErrBytes;
} __PACK__ BCM_UW_MODEM_FEC_COUNTERS_STRUCT;

*/
  modemp[deviceindex].fecBlockCounter +=   Fc.fecLdpcBlockCounter; //Fc.fecBlockCounter;
  modemp[deviceindex].fecUncorrectedBlockCounter +=  Fc.fecLdpcUncorrectedBlockCounter;// Fc.fecUncorrectedBlockCounter;
  modemp[deviceindex].rsByteCounter =  Fc.fecRsBlockCounter;// ? Fc.rsByteCounter;
  modemp[deviceindex].rsErrorByteCounter = Fc.fecRsUncorrectedBlockCounter;// // Fc.rsErrorByteCounter;
  modemp[deviceindex].ldpcAvgIterations =   Fc.ldpcAvgIterations;
  modemp[deviceindex].protectionRxBytesFromProtection =  Fc.rxBytesFromProtection;// Fc.protectionRxBytesFromProtection;
  modemp[deviceindex].protectionUncorrectedBytes =  Fc.rxErrBytesFromProtection;// Fc.protectionUncorrectedBytes;
//  KoefErrors[deviceindex] =	 (double)Fc.protectionRxBytesFromProtection / (double)Fc.rsByteCounter;

if(GetTestMode() == 0x5A)
{
//#ifndef USART0_TRY_PDC_1T
// printf("\r\nmod : %d Status : %d prot:%ld ans : %X", (deviceindex), modemp[deviceindex].acquireStatus, modemp[deviceindex].protectionRxBytesFromProtection, ans);
//#else
 printfp1("\n\rmod : ");
 printfpd1("%d",(deviceindex));
 printfp1("\n\r Status : ");
 printfpd1("%d", modemp[deviceindex].acquireStatus);
 printfp1("\n\r ldpcDecoderStress");
 printfpd1("%ld" , Ms.ldpcDecoderStress);
 printfp1("\n\rfecUncorrectedBlockCounter: ");
 printfpd1("%ld", modemp[deviceindex].fecUncorrectedBlockCounter);
 printfp1("\n\rfecBlockCounter: ");
 printfpd1("%ld", modemp[deviceindex].fecBlockCounter);
 printfp1("\n\rrsErrorByteCounter: ");
 printfpd1("%ld", modemp[deviceindex].rsErrorByteCounter);
 printfp1("\n\rldpcAvgIterations: ");
 printfpd1("%ld", modemp[deviceindex].ldpcAvgIterations);
 printfp1("\n\r  protectionRxBytesFromProtection: ");
 printfpd1("%ld", modemp[deviceindex].protectionRxBytesFromProtection);
 printfp1("\n\rprotectionUncorrectedBytes: ");
 printfpd1("%ld", modemp[deviceindex].protectionUncorrectedBytes);
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


 uerrsn15503work.errsn15303work.fecBlockCounter[mod] +=   Fc.fecLdpcBlockCounter;// Fc.fecBlockCounter;;
 uerrsn15503work.errsn15303work.fecUncorrectedBlock[mod] +=  Fc.fecLdpcUncorrectedBlockCounter;//   Fc.fecUncorrectedBlockCounter;
 UpdateErrors(mod);
}
#ifndef  CHECK_LOSS_MEM
#define QUICK_READ_ERRORS_PERIOD  (2)
#else
#define QUICK_READ_ERRORS_PERIOD  (0)
#endif
#define	DISABLING_TIME	(10)
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

/*
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
*/
/*
extern "C" void DevAcmConfigurationGet(unsigned char deviceindex, unsigned char scIndex)
{
unsigned char ret;

// printfp("\n\rPVG610_API_AcmConfigurationGet");
// printfpd("d: %d", deviceindex);

BCM_UW_ACM_CONFIGURATION_STRUCT Cs;
//#ifndef HIDE_OLD
// ret = BCM_UW_API_AcmConfigurationGet(deviceindex,0, &Cs);
 ret = BCM_UW_API_AcmConfigurationGet( deviceindex,  scIndex, &Cs);

//#endif


 modemp[deviceindex].modulation[0] = Cs.modulation[0];	//can be make aarays
 modemp[deviceindex].modulation[1] = Cs.modulation[1];	//can be make aarays
 modemp[deviceindex].modulation[2] = Cs.modulation[2];	//can be make aarays
 modemp[deviceindex].modulation[3] = Cs.modulation[3];	//can be make aarays
 modemp[deviceindex].modulation[4] = Cs.modulation[4];	//can be make aarays
 modemp[deviceindex].modulation[5] = Cs.modulation[5];	//can be make aarays
 modemp[deviceindex].modulation[6] = Cs.modulation[6];	//can be make aarays
 modemp[deviceindex].modulation[7] = Cs.modulation[7];	//can be make aarays
 modemp[deviceindex].modulation[8] = Cs.modulation[8];	//can be make aarays
 modemp[deviceindex].modulation[9] = Cs.modulation[9];	//can be make aarays
 modemp[deviceindex].modulation[10] = Cs.modulation[10];	//can be make aarays
 modemp[deviceindex].modulation[11] = Cs.modulation[11];	//can be make aarays
 modemp[deviceindex].modulation[12] = Cs.modulation[12];	//can be make aarays
 modemp[deviceindex].modulation[13] = Cs.modulation[13];	//can be make aarays
 modemp[deviceindex].modulation[14] = Cs.modulation[14];	//can be make aarays
 modemp[deviceindex].modulation[15] = Cs.modulation[15];	//can be make aarays

 modemp[deviceindex].acmNumOfSymbols[0] = Cs.acmNumOfSymbols[0];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[1] = Cs.acmNumOfSymbols[1];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[2] = Cs.acmNumOfSymbols[2];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[3] = Cs.acmNumOfSymbols[3];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[4] = Cs.acmNumOfSymbols[4];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[5] = Cs.acmNumOfSymbols[5];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[6] = Cs.acmNumOfSymbols[6];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[7] = Cs.acmNumOfSymbols[7];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[8] = Cs.acmNumOfSymbols[8];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[9] = Cs.acmNumOfSymbols[9];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[10] = Cs.acmNumOfSymbols[10];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[11] = Cs.acmNumOfSymbols[11];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[12] = Cs.acmNumOfSymbols[12];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[13] = Cs.acmNumOfSymbols[13];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[14] = Cs.acmNumOfSymbols[14];	//can be make aarays
 modemp[deviceindex].acmNumOfSymbols[15] = Cs.acmNumOfSymbols[15];	//can be make aarays

 modemp[deviceindex].gpiPayloadSizeInBytes[0] = Cs.gpiPayloadSizeInBytes[0];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[1] = Cs.gpiPayloadSizeInBytes[1];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[2] = Cs.gpiPayloadSizeInBytes[2];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[3] = Cs.gpiPayloadSizeInBytes[3];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[4] = Cs.gpiPayloadSizeInBytes[4];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[5] = Cs.gpiPayloadSizeInBytes[5];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[6] = Cs.gpiPayloadSizeInBytes[6];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[7] = Cs.gpiPayloadSizeInBytes[7];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[8] = Cs.gpiPayloadSizeInBytes[8];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[9] = Cs.gpiPayloadSizeInBytes[9];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[10] = Cs.gpiPayloadSizeInBytes[10];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[11] = Cs.gpiPayloadSizeInBytes[11];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[12] = Cs.gpiPayloadSizeInBytes[12];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[13] = Cs.gpiPayloadSizeInBytes[13];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[14] = Cs.gpiPayloadSizeInBytes[14];	//can be make aarays
 modemp[deviceindex].gpiPayloadSizeInBytes[15] = Cs.gpiPayloadSizeInBytes[15];	//can be make aarays
}
*/
extern "C" unsigned char CheckCurrentTrunk()
{
 unsigned char ret = 1;

 if(!currenttrunk)
 {
   if((countUD1 > ALARM_LEVEL_UD) || (!trunk1.modetrunk.lock_pm) //|| (!trunk1.modetrunk.lock_pd) 
   			|| (!trunk1.modetrunk.onpd) || (power1 <= (unsigned char)POWER_ALARM))
			{
				cur_err++;
   			}
			else
			{
				cur_err = 0;
			}
 }
 else
 {
   if((countUD2 > ALARM_LEVEL_UD) || (!trunk2.modetrunk.lock_pm)//|| (!trunk2.modetrunk.lock_pd) 
   			|| (!trunk2.modetrunk.onpd) || (power2 <= (unsigned char)POWER_ALARM))
			{
				cur_err++;
   			}
			else
			{
				cur_err = 0;
			}
 }
 if(cur_err >= (unsigned char)50)
   {
 	ret = 0;
   }
 return ret;
}
extern "C" unsigned char CheckNotCurrentTrunk()
{
 unsigned char ret = 1;
 if(currenttrunk)
 {
   if( (trunk1.modetrunk.onpd) )
			{
			    ret = 0;
   			}
 }
 else
 {
   if((trunk2.modetrunk.onpd) )
			{
			    ret = 0;
   			}
 }
 return ret;
}
extern "C" unsigned char HaveEnoverTrunks()
{
 unsigned char ret = 1;
 if(currenttrunk) //check for enover trunk
 {
   if((oldflag_ud1) || (!trunk1.modetrunk.lock_pm) //|| (!trunk1.modetrunk.lock_pd) 
   			)// || (power1 < POWER_TRESHOLD))
			{
			    ret = 0;
   			}
 }
 else
 {
   if((oldflag_ud2) || (!trunk2.modetrunk.lock_pm) //|| (!trunk2.modetrunk.lock_pd) 
   		   )   //	|| (power2 < POWER_TRESHOLD))
			{
			    ret = 0;
   			}
 }
 return ret;
}
extern "C" void SetCurrentTrunk(unsigned char st)
{
if(!currenttrunk)
 {
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
			  //	embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
		 //		embMsg485Request_2.SetReadyToSend();
		    tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
}
}
extern "C" void SetNotCurrentTrunk(unsigned char st)
{
if(currenttrunk)
 {
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
			//	embMsg485Request_1.SetReadyToSend();
				 tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
			 //	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
}
}
extern "C" void SetTrunk(unsigned char trunk, unsigned char st)
{
if(!trunk)
 {
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
		   //		embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
			 //	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
}
}

extern "C" void ChangeCurrentTrunk()
{
 SetCurrentTrunk(0); //get off
 if(!currenttrunk) {currenttrunk = 1;}
 else { currenttrunk = 0;  }
 SetCurrentTrunk(1);  //get on
 cur_err = 0;	//clear errors!!!!
}
extern "C" void OperateTrunks()
{
#ifdef TWO_TRUNKS
  if(GetModForSS())
 {
	SetModForSS(0);
 }
  return;
#endif
  if(GetModForSS())	  //one trunk
  {
   	if(!CheckCurrentTrunk())
 	{
 		if(HaveEnoverTrunks()) 
  			{
  				ChangeCurrentTrunk();
  			}
 	} //current trunk - wrong!!!!
 		  if(HaveEnoverTrunks() &&  (currenttrunk))		 //priority of zero trunk
 	   		{
  				ChangeCurrentTrunk();
  			}
  	if(!CheckNotCurrentTrunk())
 	{
  		SetNotCurrentTrunk(0);	 //send any command
 	}
  } 
    else   //use two trunks
  {
     if( (!trunk1.modetrunk.onpd) )
			{
			    SetTrunk(0, 1);
   			}
     if( (!trunk2.modetrunk.onpd) )
			{
			    SetTrunk(1, 1);
   			}
  }
}
#define M_1_0  (1)
#define M_1_1  (2)
#define M_0_0  (0)
#define CLEAR_M  (0xf0)
#define MAX_MOD (9)
#define NO_TYPE (0)
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
#define RESET_DELAY (1000)
extern "C" void StartNewConfigFile(unsigned char im)
{
    HotStartConfigFile(im);
}
extern "C" unsigned long  GetVersionAPI(void)
{
unsigned long retval;
BCM_UW_MODEM_VERSION_STRUCT	ver;
 retval = BCM_UW_API_VersionGet(0, &ver);	 
   printfpd1("\n\rv :%d", ver.majorVersion);
   printfpd1(".%d",ver.minorVersion);
   printfpd1(".%d",ver.buildVersion);
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
extern "C" void ModemAcmProfileMaskGet(unsigned char deviceindex, unsigned char scIndex)
{
UINT16 profilesMask;
unsigned char ret;
ret =   BCM_UW_API_ModemAcmProfileMaskGet(deviceindex, scIndex,	&profilesMask);
modemp[deviceindex].profilesMask = 	profilesMask;
}
extern "C" void ModemAcmEngineEnable(unsigned char deviceindex, unsigned char enableRx, unsigned char enableTx)
{
unsigned char ret;
//printfp("\n\r ModemAcmEngineEnable");
//printfpd(" %d", deviceindex);
//printfpd("r %d", enableRx);
//printfpd("r %d", enableTx);
 ret = BCM_UW_API_ModemAcmEngineEnable( deviceindex, 0,	enableRx, enableTx);
}
extern "C" void ModemAcmSwitch(unsigned char deviceindex, unsigned char acmProfile, unsigned char isLocal)
{
unsigned char ret;
//printfp("\n\r ModemAcmSwitch");
//printfpd(" %d", deviceindex);
//printfpd("a %d", acmProfile);
//printfpd("i %d", isLocal);
 ret =  BCM_UW_API_ModemAcmSwitch(deviceindex, 0, acmProfile, isLocal);
}


extern "C" void ModemAcmThresholdSet(unsigned char deviceindex, unsigned char scIndex, unsigned char engineTable, unsigned char profile, unsigned short mseTenthsVal, unsigned char ldpcMantissaTenths,  unsigned char ldpcExponent,  unsigned char criteria, unsigned char nextProfile)
 {
//UINT16 profilesMask;
unsigned char ret;

//printfp("\n\r ModemAcmThresholdSet");
//printfpd(" %d", deviceindex);
//printfpd("a %d", acmProfile);
//printfpd("i %d", isLocal);
 BCM_UW_API_ModemAcmThresholdSet(deviceindex, scIndex, engineTable,	profile, mseTenthsVal, ldpcMantissaTenths, ldpcExponent,  criteria,	  nextProfile);
}
extern "C" void ModemAcmProfileEnable(unsigned char deviceindex, unsigned char scIndex, unsigned short profilesMask)
{
unsigned char ret;
//printfp("\n\r ModemAcmProfileEnable");
//printfpd(" %d", deviceindex);
//printfpd("p %X", profilesMask);
//printfpd("r %d", enableTx);
 ret = BCM_UW_API_ModemAcmProfileEnable(  deviceindex , scIndex,  profilesMask);
}
#define  LED_CH		(7)
#define  LED_A		(8)
#define	 AWAR_BIT	(0x2)
#define	 NORMA_BIT	(0x1)
#define	 NORMA_BIT1	(0x4)
#define	 NORMA_UD1_BIT (0x10) //1 and 2 changed!!!!
#define	 NORMA_UD2_BIT (0x20)

unsigned char oldflag; //need init
unsigned char oldflag_710; 
unsigned char oldflag_ud1; //need init
unsigned char oldflag_ud2; //need init
unsigned char oldflag_prv;
unsigned char oldflag_prv1;
unsigned char dev_status;

extern "C" void OperateLeds3()
{
unsigned char flag = 0;
unsigned char flag_prv = 0;
unsigned char flag_prv1 = 0;
unsigned char flag_710 = 0;
unsigned char flag_ud1 = 0;
unsigned char flag_ud2 = 0;
unsigned char LedsReg = 0;// = mod_mask;
unsigned char LedsReg1 = 0;// = mod_mask;

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
 for(unsigned is = 0; is < 2 ; is++)
{
if(norma_status[is] > ALARM_QUANTITY)  //bad answer
{
 flag = 1;
}
}
 unsigned char stat710 = 0;//inportb(BLOCK_SWEEP1 + STATUS710_PORT);
 unsigned char statsynt = 0;//inportb(BLOCK_SWEEP1 + STATUSSYNT_PORT);
if(stat710 == 0xff)
{
 stat710 = 0; //without xilinx readed 0xff
}
 if((stat710 & MASK_BIT_0) && (norma_status[0] < ALARM_QUANTITY)) { LedsReg1 |= MASK_BIT_0; flag_prv = 0;} 
 else {LedsReg1 &= ~(MASK_BIT_0); flag_prv = 1;}
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 if((stat710 & MASK_BIT_1) && (norma_status[1] < ALARM_QUANTITY)) { LedsReg1 |= MASK_BIT_1;	flag_prv1 = 0;}
 else {LedsReg1 &= ~(MASK_BIT_1); flag_prv1 = 1;}
//#else
// LedsReg1 &= ~(MASK_BIT_1); flag_prv1 = 1; //new
//#endif
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 if((oldflag_prv != flag_prv) || (oldflag_prv1 != flag_prv1))
 {
 oldflag_prv = flag_prv;
  oldflag_prv1 = flag_prv1;

 outportb((BLOCK_SWEEP1 + MOD_LED_ADDR2), LedsReg1);
 }
//#else
//
//if((oldflag_prv != flag_prv) )
// {
// oldflag_prv = flag_prv;
// outportb((BLOCK_SWEEP1 + MOD_LED_ADDR2), LedsReg1);
// }
//#endif
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
 if((stat710 & MASK_BIT_0) && (stat710 & MASK_BIT_1) && (!flag) && (statsynt & MASK_BIT_0))
  {  LedsReg |= NORMA_BIT1; flag_710 = 0;} 		 //common norma
 else {LedsReg &= ~(NORMA_BIT1); flag_710 = 1;}
//#else
// if((stat710 & MASK_BIT_0) && (!flag) && (statsynt & MASK_BIT_0))
//  {  LedsReg |= NORMA_BIT1; flag_710 = 0;} 		 //common norma
// else {LedsReg &= ~(NORMA_BIT1); flag_710 = 1;}
//#endif
// #ifndef LOAD_ONE_PROVINGENT_ON_PLATA
if((oldflag != flag) ||	(oldflag_ud1 != flag_ud1) || (oldflag_ud2 != flag_ud2) || (oldflag_710 != flag_710))
{
//printfpd("\n\r flag : %d", flag);
//printfpd(" flag_ud1 : %d", flag_ud1);
//printfpd(" flag_ud2 : %d", flag_ud2);
//printfpd(" flag_710 : %d", flag_710);
//printfpd(" statsynt : %d", statsynt);
 oldflag = flag;
 oldflag_ud1 = flag_ud1;
 oldflag_ud2 = flag_ud2;
 oldflag_710 = flag_710;
  outportb(MOD_LED_ADDR1, LedsReg);	   //common norma
}
//#else

//if((oldflag != flag) ||	(oldflag_ud1 != flag_ud1) || (oldflag_ud2 != flag_ud2) || (oldflag_710 != flag_710))
//{

// oldflag = flag;
// oldflag_ud1 = flag_ud1;
// oldflag_ud2 = flag_ud2;
// oldflag_710 = flag_710;
//  outportb(MOD_LED_ADDR1, LedsReg);	   //common norma
//}

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
//printfp1("_ch1 ok ");
 dev_status |= 	MASK_BIT_1;
}
else
{
//#else
//printfp1("_ch1 wrong ");
 dev_status &= ~(MASK_BIT_1);
 unStatePUM.statePUM.state[2] |= CHANNEL2_LOCK_BIT;//2	 get off lock
//#endif
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
}
//#endif
//_________________________________________________________________hier restart after 1 min!!!
//if(norma_status[0] > ALARM_QUANTITY1)
//#ifndef PROG_MD310_SAT
if((norma_status[0] > ALARM_QUANTITY1)	||
   (syntez_error_counter > ALARM_QUANTITY2) ||
   	(pvg710_error_counter > ALARM_QUANTITY2))
{
//printfp("|");
// dev_status |= 	MASK_BIT_0;
//140409 if(GetTestMode() != 0xCC)
if( (GetTestMode() != 0xCC)	 && (ComparePOK(0x1000l)))	//140409
 {
  printfpd1("\n\r norma_status : %d", norma_status[0]);
   printfpd1("\n\r syntez : %d", syntez_error_counter);
	 printfpd1("\n\r pvg710 : %d", pvg710_error_counter);
	  printfp1("\n\r restart...");
	  OperateBuffers_usart1t();
  dev_restart();
 }
}
//#endif

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
if(stat710 & MASK_BIT_0)
{
 dev_status |= 	MASK_BIT_2;
 pvg710_error_counter = 0;
}
else
{
 dev_status &= ~(MASK_BIT_2);
 pvg710_error_counter++;
}
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
if(stat710 & MASK_BIT_1)
{
 dev_status |= 	MASK_BIT_3;
}
else
{
//#else
 dev_status &= ~(MASK_BIT_3);
//#endif
//#ifndef LOAD_ONE_PROVINGENT_ON_PLATA
}
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
}
#define  MAX_TIME_WITHOUT_LOCK (30000l) //30 sec
#define  MAX_TIMES_TRY_GET_LOCK	(6)
extern "C" void PeriodicControl()
{
 static unsigned long timescan;
 if(timescan > time1)	timescan = time1;
#ifdef SEND_STATUS
static unsigned long timescan1;
if(timescan1 > time1)	timescan1 = time1;
if((time1 - timescan1) > SEND_STATUS_PERIOD)
 {
   SendStatus();
  timescan1 = time1;
 }
#endif
 if((time1 - timescan) > STATE_SCAN_PERIOD)
 {
   ParseOperProg();
	if(GetTestMode() == 0x5A) 
 	{
    printfpd("\n\r bad %d", ans_no_correct );
	printfpd(" badr %d", ans_no_correctr );
	printfpd(" ok %d", ans_correct );
	printfpd(" okr %d", ans_correctr );
	}
  timescan = time1;
  OperateLeds3();
   }
}

void WriteSpiB(unsigned long length_of_data, unsigned char * BufferData)
{
unsigned long do_not_hangt = 0xfffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return;
write_xil_char(ADDR_STATUS, RESET_BIT);
lentmp = length_of_data;
BufferDataTmp =  BufferData;
while(lentmp--)
{
 write_xil_char(ADDR_DATA, * BufferDataTmp++);
}
write_xil_char(ADDR_STATUS, GO_BIT);

while(do_not_hangt--)
{
 if(!(read_xil_char(ADDR_STATUS) & GO_BIT))
 {
 break;
 }
}
}

unsigned char * ReadSpiB(unsigned long length_of_data)
{
unsigned long do_not_hangt = 0xfff;
unsigned long lentmp;
unsigned char * BufferDataTmp;
static unsigned char ReadBuffer[MAX_SP_LEN];
 if((length_of_data > MAX_SP_LEN) || (!length_of_data))
 {
  return ReadBuffer;
 }
write_xil_char(ADDR_STATUS, RESET_BIT);
lentmp = length_of_data;
while(lentmp--)
{
 write_xil_char(ADDR_DATA, 0x7e);
}
write_xil_char(ADDR_STATUS, GO_BIT);
while(do_not_hangt--)
{
 if(!(read_xil_char(ADDR_STATUS) & GO_BIT)) break;
}
lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(ADDR_DATA);
BufferDataTmp++;
}
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

#ifdef O_POWER
extern "C" void  DisableOperatePower(unsigned char trunk)
{
if(!GetModForSS1()) return;

if(trunk == 1)
 {
	 			embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
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
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
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
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
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
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,14);
			    embMsg485Request_2.SetBody(1,52);
				embMsg485Request_2.CalcCRC();
		  //		embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
 }
}
#define MIN_POWER ((3 + 85) <<1)
#define DELTA_POWER 60	//this is delta code
extern "C" unsigned char GetMinPower()
{
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
	 	if(unStateRRL.stateRRL.ppu1_bytes[1]  > GetMaxPower())
		  {
			   if(pdpower1 > 1)
			   {
		        pdpower1 -= 1;
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
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
   		if(unStateRRL.stateRRL.ppu2_bytes[1]  > GetMaxPower())
		  {
	 if(pdpower2 > 1)
			 {

		  pdpower2 -= 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
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
if(!GetModForSS1()) return;
if(trunk == 1)
 {
	try_counter1++;
	if(try_counter1 > MAX_TRY)
	{
	  flag_enable_operate_power1 = 1;	//need try enabling operate power
	  try_counter1 = 0;
	  return;
	}
	 	if(unStateRRL.stateRRL.ppu1_bytes[1]  < GetMaxPower())
		  {
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
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
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
   		if(unStateRRL.stateRRL.ppu2_bytes[1]  < GetMaxPower())
		  {
			    if(pdpower2 < 254)
			   {
		        pdpower2 += 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
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
if(trunk == 1)
 {
	try_counter1++;
	if(try_counter1 > MAX_TRY)
	{
	  flag_enable_operate_power1 = 1;	//need try enabling operate power
	  try_counter1 = 0;
	  return;
	}
		if(unStateRRL.stateRRL.ppu1_bytes[1] > GetMinPower()) 
		  {
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
				embMsg485Request_1.SetAddr(0);// ��� 1 //addr485);
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
		if(unStateRRL.stateRRL.ppu2_bytes[1]> GetMinPower()) 
		  {
			 if(pdpower2 > 1)
			   {
		  		pdpower2 -= 1;
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// ��� 1 //addr485);
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
  if(!GetModForSS1()) return;
   cur_min_level =  GetMinLevel();
static unsigned long timescan1;
 if(timescan1 > time1)	timescan1 = time1;

if((time1 - timescan1) > SEND_STATUS_PERIOD)
 {
  timescan1 = time1;
  if(unStateRRL.stateRRL.ppu1_bytes[1]  > GetMaxPower())
  {
  NormalizePower(1);
  return;
  }
  if((unsigned long)farinplev1 == (unsigned long)NO_LOCK_LEVEL ) 
  { 
  IncrementPower(1);// printEthLongHex(0x77);
  }
  else
  {
  if(((float)farinplev1) <= ((float)cur_min_level - (float)DELTA_INP_LEVEL)) 
  {
  IncrementPower(1);
  return;
  }
  if((float)(farinplev1) >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))
  {
#ifdef DEBUG_POWER
   printfp("\n\r3 decrement\n\r");
   printfpd(" cur_min_level: %d", cur_min_level);
   printfpd(" farinplev1: %d", farinplev1);
#endif
  DecrementPower(1);
  return;
  } 
 #ifdef DEBUG_POWER
   printfp("60: no change");
   printfpd(" cur_min_level : %d", cur_min_level);
   printfpd(" farinplevel: %d", farinplev1);
#endif
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
  if((float)farinplev2 >= ((float)cur_min_level + (float)DELTA_INP_LEVEL))
   {
   DecrementPower(2); 
   return;
   }
  }
  }
}
#endif
extern "C" void BMDN()
 {
// return;
 char ret;
  Check_restart();

   if(GetNeedWriteDevId())
		   {
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }
static unsigned long periodcnt;
periodcnt++;
 if(periodcnt > 40000)
{
  periodcnt = 0;
if(flag_read == 5){
   PeriodicControl();
   ReadErrorsm(0,0); 
   ReadErrorsm(0,1); 
#ifdef USE_PLA
   PlaStatusGet(0);
   PlaCountersGet(0);
#endif
   HcStatisticsGet();
 flag_read = 5;
 periodcnt = 35000;
}
if(flag_read == 4){
  flag_read = 5;
  periodcnt = 38000;
  return;
}
if(flag_read == 3){
//t    FirmwareLoadm(0);
	wd_reset();
    DCFileLoadm1(0, 0);
    AGCFileLoadm1(0, 0);
	wd_reset();
    ConfigFileLoadm2(0, 0);
	wd_reset();
    ConfigFileLoadm2(0, 1);
	wd_reset();
#ifdef USE_PLA
//    printfp1("\n\r pla mode set0");
//    BCM_UW_API_PlaModeSet(0, 0, BCM_UW_PLA_MODE_SINGLE_E);
    PlaModeSet(0, 0, BCM_UW_PLA_MODE_MASTER_E);  //hier using pla
//	PlaModeSet(0, 0, BCM_UW_PLA_MODE_SLAVE_E);
//	PlaModeSet(0, 1, BCM_UW_PLA_MODE_SLAVE_E);

#endif
  	EthFirmwareLoadm(0); 
	EthFirmwareLoadm(1); 
	EthPortInitialize(0);
	EthPortInitialize(1);
    EthPortConfigure(0);
    EthPortConfigure(1);
 	EthPortClkSet(0);
 	EthPortClkSet(1);

 /*	  if need protection no PLA master
    SetProtIdEx(0, 0, 3, 4, 5);
    SetProtIdEx(0, 1,3, 4, 5);
	SetProtLatency(0, 0, 25);
    SetProtMode(0, 0, BCM_UW_PROTECTION_MODE_WORKING_E,    BCM_UW_PROTECTION_SYS_MODE_INTERNAL_E);
    SetProtMode(0, 1, BCM_UW_PROTECTION_MODE_PROTECTION_E, BCM_UW_PROTECTION_SYS_MODE_INTERNAL_E);
*/

//    SetProtRxForse(0, 0, BCM_UW_PROTECTION_MODE_WORKING_E);
//    SetProtRxForse(0, 1, BCM_UW_PROTECTION_MODE_PROTECTION_E);

 ret = SetHeaderCompression();
 printfp("\n\r SetHeaderCompression :");
 printfpd(" %d" , ret);
 BCM_UW_API_TxRxOperationStart(0,0);
 BCM_UW_API_TxRxOperationStart(0,1);                   
 flag_read = 4;
 periodcnt = 30000;
 return;
}
if(flag_read == 2){
  flag_read =  3;
  periodcnt = 30000;
  return;
}

if(flag_read == 1){
  flag_read = 2;
  periodcnt = 40000;
  return;
 }
if(!flag_read){
  flag_read = 1;
  periodcnt = 40000;
  return;
 }
} 
  if(time1 < wait_time)
  {
   wait_time = time1;
  }
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
  				if((!presto_ring)&&(time1-presto_time > 2000))
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
#include "updown.cpp"
		old_ready_transit=ready_transit;
for(i =0; i < MODEM_QUANTITY;i++)
{
		old_ready_mod[i]=ready_mod[i];
}

 	ProtocolFromModACT155();
 	ProtocolFromTransitACT155();
	Check2InitTransitMod();
#include bmdn4_rem.c //100110
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
#ifdef IncEmbSerialMD34AVT
  embSerialACT155.IsrXX();
#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
#ifdef IRQ_LIMITED
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
#endif
   my_int_enable_irq0();

#ifdef IRQ_LIMITED
 }
#endif

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
 unsigned int i;//,z,  merc, zerc,up0erc,up1erc, w;
// ����� ������
for(i=0; i<15; i++) outportb(0x11, 0x08);
outportb(0x11, 0x00);
t2ms(1);
   // INIT ������
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
}

void TestTlf()
	{
  unsigned char  aa_loc, aa1, aa2, aa3, code;
  unsigned int i;
  t2ms(2);
  outportb(0x10, 0x02); for(i=0; i<sizeof(ac); i++) outportb(0x0F, ac[i]); outportb(0x10, 0x01); for(i=0; i<1000; i++);
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
if ((aa1&0x80)&&(aa3&0x80))
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
t2ms(10);
}

extern "C" void test_PU37_start()
{
 unsigned char  n, i;
	outportb(0x00, i);
	if (i != ( inportb(0x00)) ) 
			{
#ifndef USART0_TRY_PDC_1T
			  printf("\n\rBUS test  err");
#endif
	}
for (i=0; i<20; i++)
	{
   n=inportb(0x07);
   n=inportb(0x0B);
   n=inportb(0x0d);
   n=inportb(0x09);
  }
   outport(0x06,0x55); // ��������� ���������� �� �����
}
 unsigned char  rm[MODEM_QUANTITY], rmo[MODEM_QUANTITY], rtz,rtzo, tm[MODEM_QUANTITY], ttz, tup0, tup1;     
 unsigned int   merc[MODEM_QUANTITY], zerc,up0erc,up1erc;
 unsigned char rup0, rup0o,  rup1, rup1o;
 unsigned long rmc[MODEM_QUANTITY], tmc[MODEM_QUANTITY], rtzc,  ttzc, tup0c, rup0c, tup1c, rup1c;
 unsigned long PeriodCounter;

void test_PU37()
{
  static unsigned char    i;
#ifdef IRQ_LIMITED 
 if(time_irq < time1)
 { /* Body */
  time_irq =   time1 + LIMIT_IRQ_PERIOD;
#ifndef WITHOUT_INTERRUPTS
     my_int_enable_irq0(); 
   InterruptWatchDog = 0;
#endif //WITHOUT_INTERRUPTS   
}
#endif  //IRQ_LIMITED 
   		i++;
 PeriodCounter++;
if(PeriodCounter >10l)
  {
static unsigned char maskcnt;
if(maskcnt)
{
embSerialACT155.ChangeReceive1();
maskcnt = 0;
}
else
{
embSerialACT155.ChangeReceive2();
maskcnt = 1;
}
 PeriodCounter = 0l;
 if((embSerialACT155.UsedSendUD1(0) < 5)) 
			     {
				embSerialACT155.AddUD1(tup0++, 0);
			    embSerialACT155.AddUD1(tup0++, 0);
			    embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.AddUD1(tup0++, 0);
				embSerialACT155.SetMaskTransUD1(0);
				tup0c += 5;   
				 } 
 	if((embSerialACT155.UsedSendUD2(0) < 5)) 
			     {
				embSerialACT155.AddUD2(tup1++, 0);
			    embSerialACT155.AddUD2(tup1++, 0);
			    embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.AddUD2(tup1++, 0);
				embSerialACT155.SetMaskTransUD2(0);
				tup1c += 5;   
				 } 
  for(long itr = 0; itr< MODEM_QUANTITY;itr++)
  {
     if(embSerialACT155.UsedSendMod(itr) < 5)
				  {
		   embSerialACT155.AddMod(tm[itr]++, itr );
				      embSerialACT155.AddMod(tm[itr]++, itr);
					     embSerialACT155.AddMod(tm[itr]++, itr);
						    embSerialACT155.AddMod(tm[itr]++, itr);
							   embSerialACT155.AddModM(tm[itr]++, itr);
		  		   tmc[itr] += 5;
				   }
   }
		   	  if(!embSerialACT155.UsedSendTransit()) 
			     {
			   	   embSerialACT155.AddTransitM(ttz++);
	   		  	   ttzc++;
 			    }
} //PeriodCounter

  for(i = 0; i< MODEM_QUANTITY;i++)
  {
 
  if( embSerialACT155.m_RBuffMod[i].Used()) 
	{
	rm[i]=embSerialACT155.m_RBuffMod[i].Get();
					rmc[i]++;
 				if (rmo[i]!=rm[i])
							{		
 								if (merc[i] <0xfffe) merc[i]++;
 						}
					rm[i]++;
					rmo[i]=rm[i];
  }
}
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
for(long ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tup0c>10000)
		{
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send UP1 -- %d  RX-- %d  ERR-- %d\n\r",ip, tup0c, rup0c, up0erc);
#else
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
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send UP2 -- %d  RX-- %d  ERR-- %d\n\r",ip, tup1c, rup1c, up1erc);
#else
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
			ttzc=0;rtzc=0; zerc=0;
			}
for(ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tmc[ip]>10000)
		{
#ifndef USART0_TRY_PDC_1T
     printf("Mod:%d  Send MOD -- %d  RX-- %d  ERR-- %d\n\r",ip, tmc[ip], rmc[ip], merc[ip]);
#else
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
}
#define  SEND_CHAR_T (0xC3)
unsigned char irq_byte, irqm_byte;
void test_PU37_transit()
{
  static unsigned long periodtimer;
  static unsigned char    i;
  static unsigned char bstate, bstateold;
  i++;
 PeriodCounter++;
 if(PeriodCounter >30l)
  {
 PeriodCounter = 0l;
if((time1 - periodtimer) > 100)
{
periodtimer = time1;
 bstate =  inportb(PROV_TANZIT_STATUS);
  outportb(PROV_TANZIT_STATUS, 0);
 printfp("\n\r s:");
 printfpd(" %02X",bstate);
 bstateold = bstate;
 printfpd(" %02X",irq_byte);
 printfpd(" %02X",irqm_byte);
 }
		  	  if(embSerialACT155.UsedSendTransit() < 5)
			     {
			   	   embSerialACT155.AddTransit(ttz++);
			 	     embSerialACT155.AddTransit(ttz++);
  			  		embSerialACT155.AddTransit(ttz++);
  			 		embSerialACT155.AddTransit(ttz++);
  			 		embSerialACT155.AddTransitM(ttz++);
		  	  ttzc += 5;
			    }
} //PeriodCounter
  for(i = 0; i< MODEM_QUANTITY;i++)
  {
  if( embSerialACT155.m_RBuffMod[i].Used()) 
	{
	rm[i]=embSerialACT155.m_RBuffMod[i].Get();
					rmc[i]++;
					if (rmo[i]!=rm[i])
							{		
									if (merc[i] <0xfffe) merc[i]++;
							}
					rm[i]++;
					rmo[i]=rm[i];
  }
}
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
	if (ttzc>20000)
		{
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
			ttzc=0;rtzc=0; zerc=0;
			}
for(long ip = 0; ip < MODEM_QUANTITY; ip++)
{
	if (tmc[ip]>20000)
		{
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
}
extern  "C" unsigned long TypeVer(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.type;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.softVer;
return ret;
}
extern  "C" unsigned long CtrlNumberS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlYear;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlNumber;
return ret;
}
extern  "C" unsigned long CtrlVerS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer1;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
return ret;
}
extern  "C" unsigned long BlockS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulBlock;
return ret;
}
extern  "C" unsigned long ErrOutS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrOut;
return ret;
}
extern  "C" unsigned long ErrAfterRS1S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrAfterRS1;
return ret;
}
extern  "C" unsigned long ErrAfterRS2S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrAfterRS2;
return ret;
}

extern  "C" unsigned long ErrBeforeRS1S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrBeforeRS1;
return ret;
}

extern  "C" unsigned long ErrBeforeRS2S(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.ulErrBeforeRS2;
return ret;
}

extern  "C" unsigned long StateModemS(void)
{
static unsigned long ret;
ret =  unStatePUM.statePUM.state[4];
ret <<= 24;
ret =  unStatePUM.statePUM.state[2];
ret <<= 8;
return ret;
}
extern  "C" void SetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
{
  unsigned char* bt = (unsigned char *)(NVRAM_BASE);
  unEmb2TypeVer.emb2TypeVer.signature_software[1] = (unsigned char)*data_ptr;
  *(bt+1) =   (unsigned char)*data_ptr;
}
extern  "C" unsigned char * GetBERO(unsigned long* data_len)
{
 static unsigned char BufBER[50];
  float BER;
  if(timeres)
  {
  	if(ErrResSNMP)
  	{
	BER = (float)(ErrResSNMP)/((float)(timeres) * (float)(155520l)); //time in ms
    BufBER[0] = ' ';
  	}
	else
	{
	  BER = (float)(1l)/((float)(timeres) * (float)(155520l))  ;   //time in ms
	 BufBER[0] = '<';
 	}
  }
  else
  {
   BufBER[0] = ' ';
     BER = 0l;
  }
 sprintf((char *)&BufBER[1],"%.1E", BER);
 *data_len = 8;
 return ((unsigned char *)&BufBER[0]);
}
extern  "C" void SetBERO(unsigned char* data_ptr, unsigned long* data_len)
{
}
extern  "C" unsigned char * GetTlfNumberO(unsigned long* data_len)
{
 unsigned char* bt = (unsigned char *)(NVRAM_BASE);
 *data_len = 1;
 return (bt+1);
}
extern  "C" void SetLoopO(unsigned char* data_ptr, unsigned long* data_len)
{
  unStatePUM.statePUM.state[5] = (unsigned char)*data_ptr;
}
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
  	if(unStatePUM.statePUM.state[4] & 0x8) return 1l;
 	 else return 0l;
}
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
#define MAX_RECEIVE (4)	
unsigned long count_send, count_res, count_res_ok, count_res_bad;
#define SEND_TIMEOUT (2)

/*
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
#ifndef HIDE_OLD
 result = PVG610_API_MailboxMessageReceive(0,0, &Mbx);
#endif
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
while ((result != 0x12) && wd_cnt--)
{
//printf("\n\r result_hier = %d")
#ifndef HIDE_OLD
 result = PVG610_API_MailboxMessageReceive(0,0, &Mbx);
#endif
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
*/

extern "C" unsigned char WriteReadSpiBm(unsigned char deviceindex, unsigned long length_of_data,
 unsigned char * BufferData, unsigned char * ReadBuffer)
{
unsigned char ret = 0;
unsigned long do_not_hangt = 0xfffl; //101221
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
unsigned long form_addr,form_addrs ,form_addre, form_addrf, form_addrd;
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
 default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
}
if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;
write_xil_char(addr_send, SEND_ALL);	//hier hangt!!!!!
write_xil_char(addr_type , type_channel);
write_xil_char(addr_status, RESET_BIT);
lentmp = length_of_data;
BufferDataTmp =  BufferData;
while(lentmp--)
{
 write_xil_char(addr_data, * BufferDataTmp++);
}
write_xil_char(addr_status, GO_BIT);
while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
   ret = 1;
   break;
 }
}
lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
 BufferDataTmp++;
}
 return ret;
}
#ifdef PROG_BMDN2
extern "C" unsigned char WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
{
unsigned long do_not_hangt = 0xfffl; //101221
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
unsigned long form_addr,form_addrs ,form_addre, form_addrf, form_addrd;
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
if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;
write_xil_char(addr_send, SEND_ALL);
write_xil_char(addr_type , type_channel);
write_xil_char(addr_status, RESET_BIT);
lentmp = length_of_data;
BufferDataTmp =  BufferData;
while(lentmp--)
{
 write_xil_char(addr_data, * BufferDataTmp++);
}
write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 return 1;
 }
}
 return 0;
}
#endif //PROG_BMDN2
unsigned char * ReadSpiBm(unsigned char deviceindex, unsigned long length_of_data)
{
static unsigned char ReadBuffer[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffl;
unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
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
if(!length_of_data) return NULL;
if(length_of_data > MAX_SP_LEN) length_of_data = MAX_SP_LEN;
write_xil_char(addr_send, SEND_ALL);
write_xil_char(addr_type , type_channel);
write_xil_char(addr_status, RESET_BIT);
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
lentmp = length_of_data;
BufferDataTmp =  ReadBuffer;
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);

BufferDataTmp++;
}
write_xil_char(addr_type , 0);
return 	ReadBuffer;
}
extern "C" unsigned char SetLoopRxTx(unsigned char deviceIndex,  unsigned char  rfRxIdx, unsigned char isLoopbackOn)
{
//typedef enum {
//    BCM_UW_WB_RX_0_E                      = 0,
//    BCM_UW_WB_RX_1_E                      = 1,
//    BCM_UW_WB_RX_2_E                      = 2,
//    BCM_UW_WB_RX_3_E                      = 3,
//    BCM_UW_WB_RX_ADPD0_E                  = 4,
//    BCM_UW_WB_RX_ADPD1_E                  = 5,
//    BCM_UW_WB_RX_ENV0_E                   = 7,
//    BCM_UW_WB_RX_ENV1_E                   = 8,
//} BCM_UW_WB_RX_NAME_ENUM;
unsigned char ret;
ret = BCM_UW_API_RF_RxTxLoopbackSet(0, rfRxIdx, isLoopbackOn); //deviseindex for one maxlinear is olwais zero
printfpd1("\n\rLoopRxTx:%d ", ret);		//error 34
return ret;
}

extern "C" unsigned char SetLoopi(unsigned char dev, unsigned char loop,unsigned long milli, unsigned char nearend, unsigned char trib)
{
// PVG610_LOOPBACK_STRUCT lbs;
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                loopbackType;                               // see BCM_UW_LOOPBACK_TYPE_ENUM
//    UINT32              durationMilli;                              // 0 = not limited
//    BOOLEAN             nearEnd;                                    // N/A 650
//    BYTE                tributary;                                  // N/A 650
//} __PACK__ BCM_UW_LOOPBACK_STRUCT;
 BCM_UW_LOOPBACK_STRUCT lbs;
 unsigned char ret;
 lbs.loopbackType = loop; //PVG610_LOOPBACK_MODEM_E;
 lbs.durationMilli = milli>>24; //0;
 lbs.durationMilli = milli>>16; //0;
 lbs.durationMilli = milli>>8; //0;
 lbs.durationMilli = milli; //0;
 lbs.nearEnd = nearend;
 lbs.tributary = trib; //0;	 //	 //modem loopback
//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_LoopbackSet(BYTE deviceIndex, BCM_UW_LOOPBACK_STRUCT *lb)
// ret = BCM_UW_API_LoopbackSet( dev, &lbs);
 ret = BCM_UW_API_LoopbackSet( 0, &lbs);   //deviceindex for one maxlinear olwais zero
 printfpd1("\n\rSetLoopi:%d", loop);
 return ret;
}
#define DEFAULT_POWER	(-5)		
extern "C" unsigned char SetModuli(unsigned char dev, unsigned char transmitterMode,unsigned long toneFreqKhz, unsigned long sweepTimeMilli)
{
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                transmitterMode;                            // see BCM_UW_WB_TRANSMITTER_MODE_ENUM
//    INT32               toneFreqKhz;                                //
//    BOOLEAN             useExplicitPower;                           // False - use implicit power, same as current mask power
//    INT16               transmitPowerDbTenths;                      // manual gain
//} __PACK__ BCM_UW_WB_TRANSMITTER_MODE_STRUCT;
//typedef enum {
//    BCM_UW_WB_TRANSMITTER_MODE_NORMAL_E,
//    BCM_UW_WB_TRANSMITTER_MODE_ONETONE_E,
//    BCM_UW_WB_TRANSMITTER_MODE_TWOTONE_E,
//    BCM_UW_WB_TRANSMITTER_MODE_MUTE_E
//} BCM_UW_WB_TRANSMITTER_MODE_ENUM;
//typedef enum {
//    BCM_UW_WB_TX_0_E,
//    BCM_UW_WB_TX_1_E,
//    BCM_UW_WB_TX_XC_0_E,
//    BCM_UW_WB_TX_XC_1_E,
//} BCM_UW_WB_TX_NAME_ENUM;

 BCM_UW_WB_TX_NAME_ENUM wbTxIndex =  dev;
 BCM_UW_WB_TRANSMITTER_MODE_STRUCT lbs;
 unsigned char ret;
    lbs.transmitterMode = transmitterMode;  // see PVG610_TRANSMITTER_MODE_ENUM
    lbs.toneFreqKhz = toneFreqKhz;       	// relevant for one-tone, two-tone and tone-sweep
	lbs.useExplicitPower =  0;       	//????
	lbs.transmitPowerDbTenths = DEFAULT_POWER;		//?????
     ret = BCM_UW_API_WbTransmitterModeSet(0, wbTxIndex, &lbs);	//deviceindex olwas zero now

// printf("\n\r Set Loop : %d result : %d", loop, ret);
// printf("\n\r loop : %d milli : %d nearend : %d", loop, ret, nearend);
//	  PVG610_API_TransmitterModeSet(BYTE                           deviceIndex,
//                                                    BYTE                           modemIndex,
//                                                    PVG610_TRANSMITTER_MODE_STRUCT *tx)
	 printfpd1("\n\rSeModuli_0 :%d", ret);
     wbTxIndex =  BCM_UW_WB_TX_1_E;
     ret = BCM_UW_API_WbTransmitterModeSet(dev, wbTxIndex, &lbs);
	 printfpd1("\n\rSeModuli_1 :%d", ret);
 return ret;
}
/*
extern "C" void CommonResetOff(unsigned char deviceindex)
{
  unsigned long offset;
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
*/
extern "C" void EnablePhone(void)
{
	write_xil_char(SERV_CH, EN_SERV);
}
extern "C" unsigned char GetStmPhyReg(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  return read_xil_char( offset + STM_PHY_ADDR);
}

extern "C" void SetStmFarLoop(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  write_xil_char( offset + STM_PHY_ADDR, read_xil_char( offset + STM_PHY_ADDR) | FAR_LOOP);
}

extern "C" void ClearStmFarLoop(unsigned char deviceindex)
{
 unsigned char val;
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  val =  read_xil_char( offset + STM_PHY_ADDR) & (~(FAR_LOOP));
  write_xil_char( offset + STM_PHY_ADDR, val);
}
extern "C" void SetStmNearLoop(unsigned char deviceindex)
{
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  write_xil_char( offset + STM_PHY_ADDR, read_xil_char( offset + STM_PHY_ADDR) | NEAR_LOOP);
}
extern "C" void ClearStmNearLoop(unsigned char deviceindex)
{
 unsigned char val;
  unsigned long offset;
  offset = BLOCK_SWEEP1 * ((deviceindex)+1);
  val =  read_xil_char( offset + STM_PHY_ADDR) & (~(NEAR_LOOP));
  write_xil_char( offset + STM_PHY_ADDR, val);
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
#define MODE_1_PLUS_0 (0)
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
extern "C" void GetTxtFile(unsigned long variant) //, unsigned char flagm)
{
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;
if(variant >= MAX_CFG_FILE_VARIANT)
{
 variant = MAX_CFG_FILE_VARIANT - 1;
}
unsigned long config_delta;
unsigned long length;
 config_delta = CONFIG_FILE_PROVINGENT_STEP;
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
length = *pBuffer++;
length  += (*pBuffer++) << 8;
length += (*pBuffer++) << 16;
length += (*pBuffer++) << 24;
if(length > TXT_REAL_LEN)	 length = 0;
printfpd1("\n\r %lx", length);
printfp1("\n\r");
for(unsigned long its =0l; its < (length + 4); its++)
{
  printfpd1(" %c", TFTP_Buffer[its]);
}
}
unsigned char ScanTxtFilesNum[MAX_CFG_FILE_VARIANT];
unsigned long SavedTxtFilesVal;
extern "C" void ScanTxtFiles(void) //, unsigned char flagm)
{
BYTE *pBuffer;
unsigned long curvar = 0xff+1; //more as maximum var
unsigned long tmp;
unsigned char variant = 0;
unsigned char flag;
for(long is = 0; is<MAX_CFG_FILE_VARIANT;is++)
{
  ScanTxtFilesNum[is] = 0;
}
 SavedTxtFilesVal = 0;
unsigned long config_delta;
config_delta = CONFIG_FILE_PROVINGENT_STEP;
for(variant = 0; variant < MAX_CFG_FILE_VARIANT; variant++)
{
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE ),
							 (unsigned int)MAX_SIZE_TEXT_FILE, (char *)(&TFTP_Buffer[0]));
pBuffer=(unsigned char*)(&TFTP_Buffer[0]);
tmp =  (unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(config_delta << 1) - MAX_SIZE_TEXT_FILE -  FULL_HEADER_SIZE );
flag = 0;
 for(long i = 4; i < 16l; i++)
  {
   if(TFTP_Buffer[i] != 0)
   {
     flag = 1;
   }
  }
 if(!flag)
 for(i = 32l; i < 91l; i++)
  {
    if(TFTP_Buffer[i] == ':')  //if sawed time 15:30
	{
    ScanTxtFilesNum[variant] = 1;
    SavedTxtFilesVal++; 
	 break;
	}
  }
}// for variant
}
extern "C" void printcurtxt()
{
   printfpd1("\n\r%d",modemp[0].configfilefext.LengthTxt);
   printfp1("\n\r");
   for(long i=0; i < modemp[0].configfilefext.LengthTxt; i++)
    {
        printfpd1(" %02X", modemp[0].configfilefext.ConfigTxtData.Data[i]);
    }
}
 extern "C" void SetACMMask(unsigned char deviceindex, unsigned char scIndex, unsigned char mask)
 {
  unsigned char ret;
//#ifndef HIDE_OLD
//  ret = PVG610_API_ModemAcmProfileEnable(  deviceindex, 0, mask);
//#else
  ret = BCM_UW_API_ModemAcmProfileEnable( deviceindex, scIndex,  mask);
//#endif
 }
#define ETH_COMMAND_PORT (0x7f)
#define ETH_STATE_PORT   (0x7E)
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
		   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
		}
		else
		{
			if((embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)) != 0x525)
			{
			outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
			}
			else
			{
			  if(embMsgRequest->Body(4) == 4)	   //local loop
			  {
		        ClearStmFarLoop(0);
			    SetStmNearLoop(0);
			  }
			  else if(embMsgRequest->Body(4) == 8)	   //far loop
			  {
 			    ClearStmNearLoop(0);
				SetStmFarLoop(0);
			  }
			  else	   //no loop
			  {
			  ClearStmFarLoop(0);
              ClearStmNearLoop(0);
		   	  }
			}
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
	if((embMsgRequest->Body(1)&0xC0)==0x80)
	{
		embMsg485Request_1.Init();
		embMsg485Request_1.SetAddr(0);//0x01);
		embMsg485Request_1.SetLength(3); //3
		embMsg485Request_1.SetBody(0,0x08);
		embMsg485Request_1.SetBody(1,embMsgRequest->Body(0));
		embMsg485Request_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
		embMsg485Request_1.CalcCRC();
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
#define  ZERO_REG (0)
#define  ZERO_REG_MOD (0x20)
#define  RELE_REG (0x12)
#define  INPUT_REG (0x13)
void ReleTest()
{
 unsigned char receive1;
 static unsigned char test_char1;//, test_char1o;
 outportb(RELE_REG,test_char1);
 test_char1 <<= 1;
 if(!test_char1) test_char1 = 1;
 receive1 = inportb(INPUT_REG);
 printfpd("\n\r %02X",receive1);
 OperateBuffers_usart0t();
 wd_reset();
}
void BusTest()
{
 unsigned char receive1;
 static unsigned char test_char1, test_char1o;
 test_char1o = test_char1;
 outportb(ZERO_REG,test_char1++);
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
	wd_reset();
}
void BusTestFar()
{
 unsigned char receive1;
 static unsigned char test_char1, test_char1o;
 test_char1o = test_char1;
 outportb(ZERO_REG_MOD,test_char1++);
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
	wd_reset();
}
extern "C" void LoadReg_5C3F_2(unsigned char deviceIndex)
{
}

/*
void PrintConfigs(void)
{
  unsigned long itxt = 0l;
  for(unsigned variant = 0; variant < 15; variant++)
  {
   itxt = 0l;
   printfp1("\n\r_________file number:");
   printfpd1(" %d \n\r", variant);
   for(unsigned long its = FULL_HEADER_SIZE + 4l; its < (TXT_REAL_LEN + 4l); its++)
	{
       if(!(itxt%16))printfpd1 ("\n\r %X>", itxt);
	   printfpd1(" %02X", modemp[0].configfilefext1[variant].ConfigTxtData.Data[itxt++]);
	}
	OperateBuffers_usart1t();
	wd_reset();
  }
}
*/
#ifdef SEND_STATUS
void SendStatus()
{
EmbMsg StatusMsg;
if(GetTestMode() != 1) return; //to not crash tests
StatusMsg.Init();
StatusMsg.SetAddrI(SelfID());	//sender
StatusMsg.SetAddrS(DEFAULT_ADDR);	//receiver
StatusMsg.SetAddrR(0x2222);	//receiver
StatusMsg.SetType(0xEE);
StatusMsg.SetLength(12);
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
StatusMsg.SetCycle(8);
StatusMsg.CalcCRC();
tBuffEmbMsgEast.Add(StatusMsg);	  //
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

/*
extern "C" unsigned char  ProtectionStatusGet(void)
{
//PVG610_PROTECTION_STATUS_STRUCT pPs;
//unsigned char ret;
//#ifndef HIDE_OLD
//ret = PVG610_API_ProtectionStatusGet (0, 0, &pPs);
//#endif
//if((!ret) && (!pPs.protectionRxState))
//{
//return 	pPs.rxPhyId;
//}
//else
//{
 return 99;
//}
}
*/

extern "C" void bcm_usart2_rbuff_add(unsigned char data) {
  printfpd1("_%X", data);  //t
  if(RBufu2pos >= RBUFU2_SIZE) RBufu2pos = 0;
  RBUFU2[RBufu2pos++] = data;
}
void bcm_transmit_usart2(char *Buff, int len) {
unsigned long tmp = *(unsigned long*)Buff;
printfpd1("\n\rt%x>", tmp);
		 while(len--) {
		 printfpd1(" %x", *Buff);
         ToPdcTu2(*Buff++);
		 }
         OperateBuffers_usart2t(); //120426 to have delay betveen impulses
}
void bcm_transmit_usart2L(char *Buff, int len) {
unsigned long *Word	 = (unsigned long *)Buff;
char tmp;
printfp1("\n\rt>");
		 while(len-=4) {
		   ToPdcTu2(*Word);
		   ToPdcTu2(*Word>>8);
  	       ToPdcTu2(*Word>>16);
  	       ToPdcTu2(*Word>>24);
		   Word++;
		   wd_reset();
		 }
         OperateBuffers_usart2t(); 
}
unsigned char  DeviceConfigure(void) {
BCM_UW_DEVCONF_STATUS_STRUCT DevConf;
unsigned char ret;
BYTE *pBuffer;
UINT32    len;
len = DC_SIZE; //23200; //23197;
pBuffer=(unsigned char*)(&TFTP_Buffer1[500000]);
ret = BCM_UW_API_DeviceConfigure(0,pBuffer, len, &DevConf);
return ret;
}
unsigned char DeviceConfigurationResultGet(void) {
unsigned char ret;
BCM_UW_DEVCONF_STATUS_STRUCT DevConf;
printfp1("\n\rDeviceConfigurationResultGet ");
ret = BCM_UW_API_DeviceConfigurationResultGet(0, &DevConf);
printfpd1("return  %d ", ret);
printfpd1("\n\r S>%d", DevConf.pllSysIsErr);
printfpd1(" C>%d", DevConf.pllCpuIsErr);
printfpd1(" E>%d", DevConf.pllEdbIsErr);
printfpd1(" D>%d", DevConf.pllDdsIsErr);
printfpd1(" A>%d", DevConf.pllAuxIsErr);
printfpd1(" v>%d", DevConf. versionMismatchErr);
return ret;
}
unsigned char DeviceConfStart(void) {
 BCM_UW_DEVCONF_STATUS_STRUCT DevConfRetStruct;
 return BCM_UW_API_DeviceConfigurationStart(0, &DevConfRetStruct);
}
unsigned char ParameterModify(char *paramName,signed long paramValue) {
return BCM_UW_API_DeviceConfigurationParameterModify(0, paramName, paramValue);
}
unsigned char  EthPortConfigure(unsigned char index) {
 BCM_UW_ETH_PORT_CONFIGURE_STRUCT ecfg;
/* 
typedef __PACK_PREFIX__ struct
{
    UINT32              cmdSelect;                                  // see BCM_UW_ETH_PORT_SET_SELECT_ENUM
    UINT32              portIf;                                     // see BCM_UW_ETH_PORT_IF_ENUM
    BYTE                speed;                                      // see BCM_UW_ETH_PORT_SPEED_ENUM
    BYTE                portEnable;                                 // see BCM_UW_ETH_PORT_STATE_ENUM
    BOOLEAN             autoNegotiationEnable;                      // boolean
    BYTE                crcProcessingMode;                          // see BCM_UW_ETH_PORT_CRC_MODE_ENUM
    BYTE                fcPauseBehavior;                            // see BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_ENUM
    UINT16              fcPauseTimer;                               // value
    UINT16              fcPauseRefreshRate;                         // value
    BYTE                txMacAddr[6];                               // value
    UINT16              maxFrameSize;                               // value
    UINT16              minFrameSize;                               // value
    UINT16              jumboFrameSize;                             // value
    UINT16              pauseThresholdHigh;                         // value
    UINT16              pauseThresholdLow;                          // value
    BYTE                txAvgIPG;                                   // value
    BOOLEAN             rxMinIPGEnable;                             // value
    BYTE                txPreambleLength;                           // boolean
    BYTE                loopbackType;                               // see BCM_UW_ETH_PORT_LOOPBACK_TYPE_ENUM
    UINT32              controlDiscardMask;                         // value
    BYTE                pauseAbilityMode;                           // see BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM
    BYTE                autonegAbilityMode;                         // see BCM_UW_ETH_PORT_AN_ABILITY_MODE_ENUM
    BYTE                vlanTagEnableMode;                          // see BCM_UW_ETH_PORT_VLAN_TAG_MODE
    UINT16              outerVlanTpid;                              // value
    UINT16              innerVlanTpid;                              // value
} __PACK__ BCM_UW_ETH_PORT_CONFIGURE_STRUCT;

*/
//typedef __PACK_PREFIX__ struct
//{
//	UINT32 cmdSelect = portif_En | (speed_En<<1) | (portEnable_En<<2) | (crcProcessingMode_En<<4) | (fcPauseBehavior_En<<5) | (minFrameSize_En<<10)
	UINT32 cmdSelect = 1 | (1<<1) | (1<<2) | (1<<4) | (1<<5) | (1<<10);

   		ecfg.cmdSelect 			   	= cmdSelect;//BCM_UW_ETH_PORT_SET_PORT_INTERFACE_E;  // see BCM_UW_ETH_PORT_SET_SELECT_ENUM
   		ecfg.portIf    				= 0;// BCM_UW_ETH_PORT_IF_SGMII_E;//BCM_UW_ETH_PORT_IF_1000X_E;  // see BCM_UW_ETH_PORT_IF_ENUM
        ecfg.speed 					= 0; //BCM_UW_ETH_PORT_1000MBPS_E;  // see BCM_UW_ETH_PORT_SPEED_ENUM
        ecfg.portEnable	            = 1;//BCM_UW_ETH_PORT_ENABLE_E;    // see BCM_UW_ETH_PORT_STATE_ENUM
        ecfg.autoNegotiationEnable	= 0; //TRUE;    // boolean
        ecfg.crcProcessingMode		= 1;//BCM_UW_ETH_PORT_STRIP_AND_APPEND_CRC_E; //0;//BCM_UW_ETH_PORT_KEEP_CRC_E;  // see BCM_UW_ETH_PORT_CRC_MODE_ENUM
        ecfg.fcPauseBehavior 		= 0;//BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_EN_TX_DIS_E; // see BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_ENUM
        ecfg.fcPauseTimer		    = 0;//100;   // value
        ecfg.fcPauseRefreshRate		= 0;//100;   // value
        ecfg.txMacAddr[0]			= 0;//1;    // value
        ecfg.txMacAddr[1]			= 0;//2;    // value
        ecfg.txMacAddr[2]			= 0;//3;    // value
        ecfg.txMacAddr[3]			= 0;//4;    // value
        ecfg.txMacAddr[4]			= 0;//5;    // value
        ecfg.txMacAddr[5]			= 0;//8;    // value
        ecfg.maxFrameSize			= 1518;   // value
        ecfg.minFrameSize			= 17;    // value
        ecfg.jumboFrameSize			= 1518; // value
        ecfg.pauseThresholdHigh		= 0;//10000; // value
        ecfg.pauseThresholdLow		= 0;//200;   // value
        ecfg.txAvgIPG				= 8;//100;   // value
        ecfg.rxMinIPGEnable			= 0;//TRUE;  // value
        ecfg.txPreambleLength		= 8;//64;    // boolean
        ecfg.loopbackType			= 0;//BCM_UW_ETH_PORT_LOOPBACK_NONE_E; // see BCM_UW_ETH_PORT_LOOPBACK_TYPE_ENUM
        ecfg.controlDiscardMask		= 0;//0xffffffff;  // value
        ecfg.pauseAbilityMode		= 0;//BCM_UW_ETH_PORT_PAUSE_ADV_NO_PAUSE_E;  // see BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM
        ecfg.autonegAbilityMode		= 0;//BCM_UW_ETH_PORT_AN_ABL_CL37_E;  // see BCM_UW_ETH_PORT_AN_ABILITY_MODE_ENUM
        ecfg.vlanTagEnableMode		= 0;//BCM_UW_ETH_PORT_OUTER_INNER_VLAN_TAG_ENABLE_E; // see BCM_UW_ETH_PORT_VLAN_TAG_MODE
        ecfg.outerVlanTpid			= 0;//1;  // value
        ecfg.innerVlanTpid			= 0;//2; // value
  BCM_UW_API_EthPortConfigure(0, index, 0, &ecfg);
   		ecfg.portIf    				= 1;// BCM_UW_ETH_PORT_IF_SGMII_E;//BCM_UW_ETH_PORT_IF_1000X_E;  // see BCM_UW_ETH_PORT_IF_ENUM
        ecfg.speed 					= 1; //BCM_UW_ETH_PORT_1000MBPS_E;  // see BCM_UW_ETH_PORT_SPEED_ENUM
  BCM_UW_API_EthPortConfigure(0, index, 1, &ecfg);
   		ecfg.portIf    				= 0;// BCM_UW_ETH_PORT_IF_SGMII_E;//BCM_UW_ETH_PORT_IF_1000X_E;  // see BCM_UW_ETH_PORT_IF_ENUM
        ecfg.speed 					= 0; //BCM_UW_ETH_PORT_1000MBPS_E;  // see BCM_UW_ETH_PORT_SPEED_ENUM
  BCM_UW_API_EthPortConfigure(0, index, 2, &ecfg);
   		ecfg.portIf    				= 1;// BCM_UW_ETH_PORT_IF_SGMII_E;//BCM_UW_ETH_PORT_IF_1000X_E;  // see BCM_UW_ETH_PORT_IF_ENUM
        ecfg.speed 					= 1; //BCM_UW_ETH_PORT_1000MBPS_E;  // see BCM_UW_ETH_PORT_SPEED_ENUM
  BCM_UW_API_EthPortConfigure(0, index, 3, &ecfg);
return  1;
}
unsigned char EthPortClkSet(unsigned char index) {
return BCM_UW_API_EthPortClkSet(index,  BCM_UW_ETH_CLK_SRC_SGMII_0_E,  BCM_UW_ETH_CLK_SRC_SGMII_2_E);
}
unsigned char variable_value_get(char * variableName,  char * pBuffer ) {
   char    *elementEnd;
   char    *pos;
   char * pEnd;
 char    *pDcFilePos = pBuffer;
 unsigned char ret;
  pos =  strstr( pDcFilePos, variableName);
    // element found
    if (pos != NULL)
    {
        // set element position after element declaration
        pos += strlen(variableName);
        pos = strchr(pos,'\"');
        // start of element found
        if (pos != NULL)
        {
            // point to first char of element
            pos += 1;
            // search for end of element
 	        pos = strchr(pos,'\"');
            // element end found
          if(pos != NULL)
          {
           pos += 1;
		   ret =  strtol(pos, &pEnd, 10);
          }
			
        }
    }
return ret;
}
unsigned char Chan_Adc(unsigned char deviceIndex,unsigned char chanIdx, char * pBuffer) {
unsigned char ret = 99;
switch(chanIdx) {
case 0:	 ret =  variable_value_get("wb_rx_0_adc" 	  ,pBuffer);   	break;
case 1:	 ret =  variable_value_get("wb_rx_1_adc" 	  ,pBuffer);   	break;
case 2:	 ret =  variable_value_get("wb_rx_2_adc" 	  ,pBuffer);   	break;
case 3:	 ret =  variable_value_get("wb_rx_3_adc" 	  ,pBuffer);   	break;
case 4:	 ret =  variable_value_get("wb_rx_adpd_0_adc" ,pBuffer);	break;
case 5:	 ret =  variable_value_get("wb_rx_adpd_1_adc" ,pBuffer);	break;
case 6:	 ret =  variable_value_get("wb_rx_env_0_adc"  ,pBuffer);	break;
case 7:	 ret =  variable_value_get("wb_rx_env_1_adc"  ,pBuffer);	break;
default : break;
}
return ret;
}
unsigned char ADC_mode(unsigned char deviceIndex,unsigned char index, char * pBuffer) {
unsigned char ret = 99;
switch(index) {
case 0:	 ret =  variable_value_get("adc0_mode" ,pBuffer); break;
case 1:	 ret =  variable_value_get("adc1_mode" ,pBuffer); break;
case 2:	 ret =  variable_value_get("adc2_mode" ,pBuffer); break;
case 3:	 ret =  variable_value_get("adc3_mode" ,pBuffer); break;
case 4:	 ret =  variable_value_get("adc4_mode" ,pBuffer); break;
case 5:	 ret =  variable_value_get("adc5_mode" ,pBuffer); break;
default : break;
}
return ret;
}
char  RX_IF_dBtoDac[0x800]; 
void InitRX_IF_dBtoDac(void) {
char  RX_IF_dBtoDac1[] = {32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,32,70,176,74,32,78,32,81,192,83,16,86,64,88,64,90,32,92,240,93,176,95,96,97,32,99,176,100,80,102,224,103,144,105,32,107,192,108,112,110,32,112,224,113,208,115,160,117,128,119,112,121,128,123,144,125,192,127,16,2 ,80,4 ,192,6 ,80,9 ,240,11,160,14,80,17,48,20,0 ,23,208,25,192,28,192,31,128,34,0 ,36,48,37,32,38,32,39,0 ,40,16,41,144,42,0 ,45,0 ,51,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,0 ,56,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,16,68,192,72,64,76,80,79,224,81,80,84,112,86,96,88,96,90,48,92,240,93,176,95,96,97,240,98,160,100,64,102,208,103,96,105,16,107,160,108,96,110,16,112,208,113,160,115,128,117,112,119,112,121,128,123,144,125,224,127,32,2 ,144,4 ,16,7 ,144,9 ,48,12,224,14,160,17,128,20,96,23,112,26,112,29,128,32,192,35,208,38,0 ,41,112,42,96,43,64,44,16,45,208,45,208,46,64,48,48,50,208,55,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,217,58,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
for(int ii = 0; ii <= 0x7FF ; ii++) {
  RX_IF_dBtoDac[ii] =   RX_IF_dBtoDac1[ii];
}
}
char  RX_IQ_dBtoDac[0x800]; 
void InitRX_IQ_dBtoDac(void) {
char  RX_IQ_dBtoDac1[] = {22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,22,80,159,82,228,84,251,86,238,88,202,90,145,92,75,94,243,95,144,97,37,99,183,100,75,102,224,103,121,105,19,107,178,108,84,110,254,111,173,113,110,115,59,117,28,119,11,121,21,123,49,125,97,127,158,1 ,249,3 ,103,6 ,237,8 ,131,11,41,14,218,16,163,19,125,22,105,25,98,28,11,31,127,33,81,35,183,36,211,37,190,38,181,39,181,40,103,42,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,143,44,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,48,76,232,78,160,81,232,83,48,86,36,88,24,90,220,91,160,93,88,95,16,97,160,98,48,100,200,101,96,103,240,104,128,106,36,108,200,109,56,111,168,112,164,114,160,116,64,118,224,119,48,122,128,124,184,126,240,0 ,80,3 ,176,5 ,80,8 ,240,10,176,13,112,16,104,19,96,22,120,25,144,28,176,31,208,34,104,36,0 ,38,224,38,192,39,144,40,96,41,120,42,144,43,120,45,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,96,47,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
for(int ii = 0; ii <= 0x7FF ; ii++) {
  RX_IQ_dBtoDac[ii] =   RX_IQ_dBtoDac1[ii];
}
}
char RX_IF_policy_table[0x3C8];
void InitRX_IF_policy_table(void) {
char RX_IF_policy_table1[] = {76,221,76,221,76,221,76,221,76,221,76,221,76,221,76,221,76,221,76,222,76,224,76,226,76,228,76,230,76,232,76,234,76,236,76,238,76,240,76,242,76,244,76,246,76,248,76,250,76,252,76,254,76,0 ,76,2 ,76,4 ,76,6 ,76,8 ,76,10,76,12,76,14,76,16,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,76,18,179,3 ,179,5 ,179,7 ,179,9 ,179,11,179,13,179,15,179,17,179,19,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,179,20,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
for(int ii = 0; ii <= 0x3C7; ii++) {
  RX_IF_policy_table[ii] =   RX_IF_policy_table1[ii];
}
}
char RX_IQ_policy_table[0x3C8];
void InitRX_IQ_policy_table(void) {
char RX_IQ_policy_table1[] = {102,231,102,231,102,231,102,231,102,231,102,231,102,233,102,235,102,237,102,239,102,241,102,243,102,245,102,247,102,249,102,251,102,253,102,255,102,1 ,102,3 ,102,5 ,102,7 ,102,9 ,102,11,102,13,102,15,102,17,102,19,102,21,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,102,23,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,6 ,153,8 ,153,10,153,12,153,14,153,16,153,18,153,20,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,153,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
for(int ii = 0; ii <= 0x3C7; ii++) {
  RX_IQ_policy_table[ii] =   RX_IQ_policy_table1[ii];
}
}
extern "C" void AGC_load(unsigned char deviceIndex, char * pBuffer) {
unsigned ii;
unsigned char 		AdcConnectedToChanEd7 = Chan_Adc(deviceIndex, 6 ,pBuffer);
unsigned char 		AdcConnectedToChanEd8 = Chan_Adc(deviceIndex, 7 ,pBuffer);
signed short		mainSetPointDbTenth = -110;// # -11db
signed short		innerSetPointDbTenth = -110;
signed short	   	peakValueDbTenth = -25; // # -2.5dB
unsigned short 		X1;
unsigned char adcIndex; 
printfp1("\n\r AGC_Load");
unsigned long eheap;
unsigned long eheap1;
InitRX_IF_dBtoDac();
InitRX_IQ_dBtoDac();
InitRX_IF_policy_table();
InitRX_IQ_policy_table();
   	for(ii = 0; ii <= 5; ii++) {
			X1 = ADC_mode(deviceIndex,ii ,pBuffer);
		   if ((AdcConnectedToChanEd7 != ii) && (AdcConnectedToChanEd8 != ii))	{
				if (X1 == 1 || X1 == 5)   {		//: #IQ
				adcIndex = ii*3 + 0;
    				BCM_UW_API_WbRxAgcGainDistributionTableSet( deviceIndex, adcIndex, (BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT *)  &RX_IQ_policy_table);
				    BCM_UW_API_WbRxAgcDbToDacTableSet(deviceIndex, adcIndex, (BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *) &RX_IQ_dBtoDac);
 					BCM_UW_API_WbRxAgcSetPointAndPeakSet(deviceIndex, adcIndex, mainSetPointDbTenth, innerSetPointDbTenth, peakValueDbTenth);
		  }
         		if ((X1 == 2) || (X1 == 3) || (X1 == 4)) { //: # mode IF I rail	or independent 		
					adcIndex = ii*3 + 1;
    				BCM_UW_API_WbRxAgcGainDistributionTableSet( deviceIndex, adcIndex, (BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT *)  &RX_IF_policy_table);
				    BCM_UW_API_WbRxAgcDbToDacTableSet(deviceIndex, adcIndex, (BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *) &RX_IF_dBtoDac);
 					BCM_UW_API_WbRxAgcSetPointAndPeakSet(deviceIndex, adcIndex, mainSetPointDbTenth, innerSetPointDbTenth, peakValueDbTenth);
				 }
				if ((X1 == 6) || (X1 == 3) || (X1 == 4 )) { //  : # mode IF Q rail or independent	
					adcIndex = ii*3 + 2;
     				BCM_UW_API_WbRxAgcGainDistributionTableSet( deviceIndex, adcIndex, (BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT *)  &RX_IF_policy_table);
				    BCM_UW_API_WbRxAgcDbToDacTableSet(deviceIndex, adcIndex, (BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *) &RX_IF_dBtoDac);
 					BCM_UW_API_WbRxAgcSetPointAndPeakSet(deviceIndex, adcIndex, mainSetPointDbTenth, innerSetPointDbTenth, peakValueDbTenth);
	 	  		 }		
		  }	 //ed7 and ed8
	   } // for	
}
unsigned char TxRxStatusGet(unsigned char scIndex) {
 BCM_UW_TXRXOP_STATUS_STRUCT TxRxOpStruct;
BCM_UW_API_TxRxOperationStatusGet(0,  scIndex, &TxRxOpStruct);
printfpd1(" %d ", TxRxOpStruct.txReady);
}

unsigned char SetHeaderCompression(void) {
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                mask[13];                                   // 13 bytes of mask
//} __PACK__ BCM_UW_HC_MASK_STRUCT;

unsigned char ret;
UINT16 packetType = 0;  //index for the parser translation table 10 bits

//tBYTE engine1MaskIndex = 0; //index for engine1
//tBYTE engine2MaskIndex = 0; //index for engine2
BYTE engine1MaskIndex = 1; //index for engine1
BYTE engine2MaskIndex = 1; //index for engine2

UINT16 lenThreshold = 512;
UINT16 alternateType = 1;	 //alternate type?
unsigned char engine = BCM_UW_HC_ENGINE_1_E;

//ok ? BYTE maskIndex = 0; //index of mask table
BYTE maskIndex = 1; //index of mask table

BCM_UW_HC_MASK_STRUCT smask1 = {0xff,0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0, 0};
BCM_UW_HC_MASK_STRUCT smask2 = {0,0, 0, 0, 0, 0, 0xff, 0, 0, 0, 0, 0, 0};
BCM_UW_HC_MASK_STRUCT smask3 = {0xff,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
BCM_UW_HC_MASK_STRUCT smask4 = {0,0xff, 0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//wrong resultsBCM_UW_HC_MASK_STRUCT smask5 = {0xff,0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//BCM_UW_HC_MASK_STRUCT smask6 = {0,0xff, 0, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0};

BCM_UW_HC_LEARNING_AGEING_STRUCT HCLa;

//typedef __PACK_PREFIX__ struct
//{
//    BYTE                engine;
//    BOOLEAN             adaptiveThreshEnable;                       // One bit selector, fixed threshold for learning [0] or adaptive threshold learning mechanism [1] - task enable
//    UINT32              fixedBwThreshBps;                           // This field is relevant only if adaptiveThreshEnable is false. It sets the bandwidth in bps. Range is 100bps-10Mbps
//    BYTE                dynamicLearningTableTargetPercent;          // The desired percents up to 100%, used by the adaptive learning task
//    UINT32              minDynamicBwThreshBps;                      // The minimum BW threshold used by the adaptive learning task, Range is 100bps-10Mbps
//    BYTE                threshUpdateStepPercent;                    // How many percents increase or decrease in every step used by the adaptive learning task, Range 1-50%
//    UINT32              threshUpdatePeriodMsec;                     // Period in milliseconds between threshold update by the adaptive learning task, Range [100mSec-100Sec]
//    UINT32              measurementPeriodMsec;                      // Period in millisecond between 2 measurements used by the adaptive learning task, Range [30msec-1Sec]
//} __PACK__ BCM_UW_HC_LEARNING_AGEING_STRUCT;

HCLa.engine = 1;
HCLa.adaptiveThreshEnable = 1;
HCLa.fixedBwThreshBps = 1024;                           // This field is relevant only if adaptiveThreshEnable is false. It sets the bandwidth in bps. Range is 100bps-10Mbps
HCLa.dynamicLearningTableTargetPercent = 90;          // The desired percents up to 100%, used by the adaptive learning task
HCLa.minDynamicBwThreshBps = 1024;                      // The minimum BW threshold used by the adaptive learning task, Range is 100bps-10Mbps
HCLa.threshUpdateStepPercent = 10;                    // How many percents increase or decrease in every step used by the adaptive learning task, Range 1-50%
HCLa.threshUpdatePeriodMsec = 300;                     // Period in milliseconds between threshold update by the adaptive learning task, Range [100mSec-100Sec]
HCLa.measurementPeriodMsec = 50;                      // Period in millisecond between 2 measurements used by the adaptive learning task, Range [30msec-1Sec]

BCM_UW_HC_DB_REFRESH_STRUCT HcDbRefresh;

//typedef __PACK_PREFIX__ struct
//{
//    BOOLEAN             periodicEnable;                             // Running mode of the DB refresh task (0=one shot, 1= periodic).
//    UINT32              frequencyMsec;                              // Set how often the task DB refresh task will start a new iteration. Note: affect only in periodic mode
//    UINT16              rateEntries;                                // Set how many entries will be refreshed per compression window. Valid numbers are between 1-1024
//} __PACK__ BCM_UW_HC_DB_REFRESH_STRUCT;

 HcDbRefresh.periodicEnable = 1;
 HcDbRefresh.frequencyMsec = 6000;  
 HcDbRefresh.rateEntries = 256;    

//printfpd1("\n\rm0:%02x ", smask1.mask[0]);
//printfpd1("\n\rm12:%02x ", smask1.mask[12]);

// ret = BCM_UW_API_HcEngineEnable(0, 1);

 ret =  BCM_UW_API_HcExEngineEnable(0, 0, 1);

 if(ret) return ret;

 ret =  BCM_UW_API_HcExEngineEnable(0, 1, 1);

//need set two channels ret =  BCM_UW_API_HcMaskSet(0, engine,  maskIndex, &smask1);
// ret =  BCM_UW_API_HcMaskSet(0, engine,  maskIndex, &smask3);
// without this do not compressed !!!!

  for(maskIndex = 0; maskIndex <= 69; maskIndex++) {
// for(maskIndex = 1; maskIndex <= 69; maskIndex++) {

 ret = BCM_UW_API_HcExMaskSet(0, 0, engine, maskIndex, &smask1);
// ret = BCM_UW_API_HcExMaskSet(0, 0, engine, maskIndex, &smask4);

 printfpd1("ret=%d ", ret);

 if(ret) return ret;

 ret = BCM_UW_API_HcExMaskSet(0, 1, engine, maskIndex, &smask1);
// ret = BCM_UW_API_HcExMaskSet(0, 1, engine, maskIndex, &smask4);

 if(ret) return ret;
 printfpd1("ret=%d ", ret);

 engine = BCM_UW_HC_ENGINE_2_E;
//maskIndex = 1;

//ok ret =  BCM_UW_API_HcMaskSet(0, engine,  maskIndex, &smask2);  //setup engine2
//need set two channels ret =  BCM_UW_API_HcMaskSet(0, engine,  maskIndex, &smask4);  //setup engine2
 //wrong ret =  BCM_UW_API_HcMaskSet(0, engine,  maskIndex, &smask5);  //setup engine2

 ret = BCM_UW_API_HcExMaskSet(0, 0, engine, maskIndex, &smask4);
 printfpd1("ret=%d ", ret);

 if(ret) return ret;

 ret = BCM_UW_API_HcExMaskSet(0, 1, engine, maskIndex, &smask4);
 printfpd1("ret=%d ", ret);

 if(ret) return ret;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<this enough
// if(ret) return ret;

//need load two channels ret = BCM_UW_API_HcTypeSet(0, packetType, engine1MaskIndex,  engine2MaskIndex, lenThreshold, alternateType);

//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExTypeSet(BYTE deviceIndex, BYTE scIndex, UINT16 packetType, BYTE engine1MaskIndex, BYTE engine2MaskIndex, UINT16 lenThreshold, UINT16 alternateType)

//========================================need <<<<<

 for(packetType = 1; packetType <= 63; packetType++) {

 ret =  BCM_UW_API_HcExTypeSet(0, 0,  packetType,  engine1MaskIndex,  engine2MaskIndex, lenThreshold, alternateType);
 printfpd1("ret=%d ", ret);
 if(ret) return ret;

 ret =  BCM_UW_API_HcExTypeSet(0, 1,  packetType,  engine1MaskIndex,  engine2MaskIndex, lenThreshold, alternateType);
 printfpd1("ret=%d ", ret);
 if(ret) return ret;
 }

// ret =  BCM_UW_API_HcLearningAndAgeingConfigure(0, &HCLa);
 ret =  BCM_UW_API_HcExLearningAndAgeingConfigure(0, 0, &HCLa);

 if(ret) return ret;

 ret =  BCM_UW_API_HcExLearningAndAgeingConfigure(0, 1, &HCLa);

 if(ret) return ret;

 HCLa.engine = 2;
// ret =  BCM_UW_API_HcLearningAndAgeingConfigure(0, &HCLa);

 ret =  BCM_UW_API_HcExLearningAndAgeingConfigure(0, 0, &HCLa);

 if(ret) return ret;

 ret =  BCM_UW_API_HcExLearningAndAgeingConfigure(0, 1, &HCLa);

 if(ret) return ret;
 
// ret = BCM_UW_API_HcDBRefreshConfigure(0, &HcDbRefresh);
 ret = BCM_UW_API_HcExDBRefreshConfigure(0, 0, &HcDbRefresh);

 if(ret) return ret;

 ret = BCM_UW_API_HcExDBRefreshConfigure(0, 1, &HcDbRefresh);

 if(ret) return ret;

//__________________________________hier use parser classifier!!!!
//typedef __PACK_PREFIX__ struct
//{
//    BYTE                index;
//    UINT16              mask;
//    UINT16              value1;
//} __PACK__ BCM_UW_HC_PARSER_CLASSIFIER_STRUCT;

BCM_UW_HC_PARSER_CLASSIFIER_STRUCT ParserClassifier;

ParserClassifier.index =  1;//		1...31   65...95
ParserClassifier.mask = 0xffff;
ParserClassifier.value1 = 0x8100;

//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcParserClassifierSet(BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_PARSER_CLASSIFIER_STRUCT *pParserClassifier)
ret =  BCM_UW_API_HcParserClassifierSet(0, 0, &ParserClassifier);	 //hier make user defined parser index it can be used in parsertypeset
 printfpd1("ret=%d ", ret);
 if(ret) return ret;

ret =  BCM_UW_API_HcParserClassifierSet(0, 0, &ParserClassifier);	 //hier make user defined parser index it can be used in parsertypeset
 printfpd1("ret=%d ", ret);
 if(ret) return ret;

// ret =  BCM_UW_API_HcDBFlush(0, 0);

BCM_UW_HC_PARSER_TYPE_STRUCT ParserType;

//typedef __PACK_PREFIX__ struct
//{
//    BYTE                packetType;                                 // type value for this API
//    BYTE                fieldOffset[7];                             // array
//    BYTE                classifierIndex[7];                         // array - each point to one of the "Classifiers" defined by the other parser API
//    BOOLEAN             headerIs1588;                               // 1588 bit
//    BYTE                classifierIndexSelect;                      // one of the 7 "classifierIndex" defined in this API (6=disable)
//    UINT16              value2;                                     // relevant to the "classifierIndexSelect"
//} __PACK__ BCM_UW_HC_PARSER_TYPE_STRUCT;

 BYTE fieldOffset[] 		   = {0,0,0,0,0,0,0,0};
 BYTE classifierIndex[] 	   = {31,7,6,5,4,3,2,1};   //32...51 are pre-configurable and do not must be setted

  ParserType.packetType 		   = 1;  //test
  memcpy(ParserType.fieldOffset, fieldOffset, 7);
  memcpy(ParserType.classifierIndex,classifierIndex, 7);
  ParserType.headerIs1588		   = 0;	  //not recommended set 1
  ParserType.classifierIndexSelect = 0;	 //hier select one of  classifierindex 0...6  from array
  ParserType.value2				   = 0;

 ret = BCM_UW_API_HcParserTypeSet(0, 0, &ParserType);

 if(ret) return ret;

 ret = BCM_UW_API_HcParserTypeSet(0, 1, &ParserType);

 if(ret) return ret;

 ret = BCM_UW_API_HcExDBFlush(0, 0, 1);

 if(ret) return ret;

 ret = BCM_UW_API_HcExDBFlush(0, 1, 1);

 if(ret) return ret;

// ret =  BCM_UW_API_HcEngineEnable(0, 1);
 ret =  BCM_UW_API_HcExEngineEnable(0, 0, 1);

 if(ret) return ret;

 ret =  BCM_UW_API_HcExEngineEnable(0, 1, 1);

 printfpd1("\n\rHC %d", ret);

return ret;
}
unsigned char HcStatisticsGet(void) {
BCM_UW_HC_STATISTIC_STRUCT HcStatistics;
unsigned char ret;
//typedef __PACK_PREFIX__ struct
//{
//    UINT16              numCompressedFlowsEngine1;                  // Number of compressed flows for engine 1
//    UINT16              numCompressedFlowsEngine2;                  // Number of compressed flows for engine 2
//    BYTE                netCompressionPercent;                      // Average compression gain - Net
//    BYTE                grossCompressionPercent;                    // Average compression gain - Gross
//    UINT32              currentBwThreshEngine1;                     // Current bandwidth threshold for engine 1
//    UINT32              currentBwThreshEngine2;                     // Current bandwidth threshold for engine 2
//    UINT16              unCleanCompressedFlowsEngine1;              // Number of compressed flows after QFLUSH for engine 1
//    UINT16              unCleanCompressedFlowsEngine2;              // Number of compressed flows after QFLUSH for engine 2
//} __PACK__ BCM_UW_HC_STATISTIC_STRUCT;
//BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcStatisticsGet(BYTE deviceIndex, BCM_UW_HC_STATISTIC_STRUCT *pHcStatistics)
ret = BCM_UW_API_HcStatisticsGet(0, &HcStatistics);
printfpd1("\n\r Compr1:%d",HcStatistics.numCompressedFlowsEngine1);
printfpd1(" Compr2:%d",HcStatistics.numCompressedFlowsEngine2);
printfpd1(" NetPr:%d",HcStatistics.netCompressionPercent);
printfpd1(" GrossPr:%d",HcStatistics.grossCompressionPercent);
//printfpd1("\n\r CBTrE1:%d",HcStatistics.currentBwThreshEngine1);
//printfpd1(" CBTrE2:%d",HcStatistics.currentBwThreshEngine2);
//printfpd1(" CFlofs1:%d",HcStatistics.unCleanCompressedFlowsEngine1);
//printfpd1(" CFlofs2:%d",HcStatistics.unCleanCompressedFlowsEngine2);
return ret;
}