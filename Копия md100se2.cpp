//#define LEN_MD100SE	   (77)
#define LEN_MD100SE	   (94)


struct MD100SE
{

unsigned char 	ConfigFile;
unsigned char 	ConfigFile1;  //new

//unsigned char 	ModForSS;
unsigned char 	ModEth;	 //not MEthMode
//unsigned char 	NamesConfigFiles;
//unsigned char 	LoadVariants;
//unsigned char 	LoadVariantsSet;
//unsigned char   SaveVariants;
//unsigned char   SaveVariantsSet;
// CurReadedAnyCofig; //number of readed anyconfig to set this variable - filled readanyconfig for reading

unsigned char   MRfOut;		//on / off


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

unsigned char MTCdType;
unsigned char MRCdType;

unsigned char MTMode;
unsigned char MRMode;



 
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
//unsigned char MEbN02;
//unsigned char MEbN03;

//MDataI MTEbN0;
unsigned char MTEbN00;
unsigned char MTEbN01;
//unsigned char MTEbN02;
//unsigned char MTEbN03;

unsigned char MBER0;
unsigned char MBER1;
//unsigned char MBER2;
//unsigned char MBER3;

unsigned char MBERE;


//_-52

//MDataI MTBER;
unsigned char MTBER0;
unsigned char MTBER1;
//unsigned char MTBER2;
//unsigned char MTBER3;

unsigned char MTBERE;


/*
MDataI MAGC;
MDataI MSweep;
*/

unsigned char MAGC0;
unsigned char MAGC1;
//unsigned char MAGC2;
//unsigned char MAGC3;

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

//unsigned char MEthSendH0;
//unsigned char MEthSendH1;
//unsigned char MEthSendH2;
//unsigned char MEthSendH3;

unsigned char MEthSendU0;
unsigned char MEthSendU1;
unsigned char MEthSendU2;
unsigned char MEthSendU3;



//__70

unsigned char MEthReceived0;
unsigned char MEthReceived1;
unsigned char MEthReceived2;
unsigned char MEthReceived3;


unsigned char MEthReceivedCRC0;
unsigned char MEthReceivedCRC1;
unsigned char MEthReceivedCRC2;
unsigned char MEthReceivedCRC3;


//unsigned char MEthReceivedH0;
//unsigned char MEthReceivedH1;
//unsigned char MEthReceivedH2;
//unsigned char MEthReceivedH3;


unsigned char MIfLoop;
unsigned char MUnModul;

unsigned char MACMM;

unsigned char MRCntl;

unsigned char MRateE0;
unsigned char MRateE1;
unsigned char MRateE2;
unsigned char MRateE3;

unsigned char MRateED0;
unsigned char MRateED1;
unsigned char MRateED2;
unsigned char MRateED3;



unsigned char rezerved1;
unsigned char rezerved2;
unsigned char rezerved3;
unsigned char rezerved4;
unsigned char rezerved5;
unsigned char rezerved6;
unsigned char rezerved7;
unsigned char rezerved8;



 };

union UMD100SE
{
   MD100SE md100se;
   unsigned char byte[LEN_MD100SE];
};

extern UMD100SE dev1;

//_________________________________________________

struct Mode100SE
{
/*
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
  */

	unsigned char mode;		  //15

//___________________________________________________________________________line

	unsigned char interf; // 16 2 high - num STM1, another - num E1
 //	unsigned long rateEth;	 
 unsigned char rateEth0;	//17
 unsigned char rateEth1;   //18
 unsigned char rateEth2;   //19
 unsigned char rateEth3;   //20

  //	unsigned long extTypeRate; //21 22 23|||| 24  3 high - type, another - rate
   unsigned char	extTypeRate0;
   unsigned char	extTypeRate1;
   unsigned char	extTypeRate2;
   unsigned char	extTypeRate3;



  //	unsigned short blockSize;	//25  26
  unsigned char blockSize0;
   unsigned char blockSize1;


	unsigned char coderate0;   //27
	unsigned char coderate1;	//28
	unsigned char coderate2;	//29
	unsigned char coderate3;   //30


	unsigned char code_type; //type_code; 31

//_____________________________________________
 //	unsigned char code_rate;
////
  //	unsigned long portrate;
	 unsigned char portrate0;
 unsigned char portrate1;
 unsigned char portrate2;
 unsigned char portrate3;

	unsigned char port_mode;
////
	unsigned char mparam1;
	unsigned char mparam2;
	unsigned char mparam3;
	unsigned char mparam4;
	unsigned char mparam5;



};

struct Emb4100SECfg
{
 /*

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
	*/

  //	unsigned short fileNum;
	unsigned char conf_number;		//0
   unsigned char conf_number1;		//1

	unsigned char numMode;		   //2
	unsigned char numProvCode; //3 // 1 lowest num Provogent, next - ldpc(1)/rs(0)
 //	unsigned long rateSimbol;
////
 unsigned char rateSymbol0;		 //4
 unsigned char rateSymbol1;		//5
 unsigned char rateSymbol2;		 //6
 unsigned char rateSymbol3;		 //7

	unsigned char acm_status;	  //8
	unsigned char alfa;			 //9
	unsigned char param1;
	unsigned char param2;
	unsigned char param3;
	unsigned char param4;
	unsigned char param5;	   //14



Mode100SE 	mode15504[16];


};




union  uConfigTxtData100
{
//  TxtPrm txtprm;
  Emb4100SECfg  emb4md15504cfg;
  unsigned char Data[TXT_REAL_LEN_100];	   //need check
};

struct ConfigFileText100
{
  unsigned long LengthTxt;//
  unsigned char Header[FULL_HEADER_SIZE];	
//  unsigned char ConfigTxtData[TXT_REAL_LEN];
  uConfigTxtData100  ConfigTxtData;
};





 
	 /*
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


extern ModemP modemp[MODEM_QUANTITY << 1];

