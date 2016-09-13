#ifndef MENU_H
#define MENU_H
//#include "DSP281x_Device.h"
//#include "remote.h"
#include <mqx.h>
#include <bsp.h>

#include <armth.h>

#include <fio.h>
#include <fio_prv.h>
#include <io.h>
#include <io_prv.h>

#include <string.h>
#include <stdlib.h> //for strtod
#include <at91rm9200.h>
#include <rtcs.h>
#include  <hello7.h>

#ifdef __cplusplus
extern "C" {
#endif
//extern int t2; //to test
//void InitMenu(void);
//void ErrorMessage(void);
#define Uint16  unsigned int
#define int16   int
#define float64 double
#define float32 double
#define Uint32  unsigned long
#define int32   long
#define PKU_ADDR	(0x600) /* sweep in xilinx */
#define	PultTBufferSize (64)
#include <cat91rm9200.h>
#define TBUFF1_VALUE (200)
//#define TBUFF1_VALUE (300)


//#define TBUFF2_VALUE (1500)		//max eth packet
#define TBUFF2_VALUE (1400)		//max eth packet


//#define TBUFF1_VALUE (300)

extern char RBuff[ACT_BUFFER_SIZE1];
extern char *  pRBuff;
extern char TBuff[ACT_BUFFER_SIZE1];
extern char *  pTBuff;
extern char IdCommand;
extern char step;

extern char IdCommand0;
extern char IdCommand3;
extern char IdCommandS;

extern char *  pTBuff0;
extern char *  pTBuff3;

extern _rtcs_if_handle  ihandle0;
extern _rtcs_if_handle  ihandle1;

extern uint_32 OldIP;

#ifdef HAVE_GATEWAY
extern uint_32 OldNetwork;
extern uint_32 OldNetMask;
#endif



extern void dev_restart(void);

 extern void hello(uint_32);
struct State_BITS {           // bits   description
    Uint16   Zumm:1;      	  // 0      Zummer is on  
    Uint16   WTBuff1:1;      	  // 0      now written WTBuff1 
    Uint16	 Sync:1;			//is in sync
    Uint16	 UCDE:1;			//uart can disable ethernet 1- can
    Uint16	 All0s:1;
    Uint16	 LossCell:1;		//current loss is celled
    Uint16	 Start:1;			//celling on
    Uint16	 Frozen:1;			//"frozen" display
    Uint16	 CsSpi:1;			//started work widch spi 
    Uint16	 Mf20SnmpOn:1;			//Mf20Snmp
    Uint16	 Init:1;		//initialize not ended
    Uint16	 ProgMode:1;		//0: Programmer Mode off
	Uint16	 Restart:1;		   //have command of restart from remote
	Uint16	 EthOff:1;		   //have command of restart from remote
	Uint16	 EthBad:1;		   //have command of restart from remote
    Uint16   Mf20Ready:1;         // 15:10   reserved
};
union  State_REG1 {
   Uint16             all;
   struct State_BITS  bit;
};
struct Update_BITS {           // bits   description
	Uint32   Some    :1;      	   // need Some update
    Uint32   XILR0   :1;      	   // need update xilinx reg0 
    Uint32	 FU      :1;		   // need load file
    Uint32	 SSC     :1;		   // start save commut
    Uint32	 LED	 :1;		   // need load LED
    Uint32   LJ  	 :1;		    	//need load and jump	
    Uint32   XILR1   :1;      	   // need update xilinx reg1  
    Uint32   ParseE  :1;      	   // need parse eth direct 
    Uint32   Boot    :1;   		   // need run bootloader
    Uint32   DcrBoot :1;		   //need decrement counter to boot (need for loader)
    Uint32   Draw	 :1;		   //need draw menu
	Uint32   IP	 	 :1;		   //need change IP
	Uint32   NIRQ 	 :1;		   //need run embirq
	Uint32   Parse0	 :1;		   //need parse usart0
	Uint32   Parse3	 :1;		   //need parse usart3
	Uint32   Parse1	 :1;		   //need parse usart1
	Uint32   ChTM	 :1;           //need change Test Mode
#ifdef PROG_TUTS
	Uint32   SetOutp :1;           //need set outputs
#endif //PROG_TUTS
#ifdef HAVE_GATEWAY
	Uint32   Network :1;  
	Uint32   NetMask :1;  
#endif

#ifdef PROG_BMDN4
	Uint32   OperProg :1;  
#endif

#ifdef PROG_PU_M710
	Uint32   OperProg :1;  
#endif



#ifdef PROG_PU_MSAT
	Uint32   SatSet0 :1;  
	Uint32   SatSet1 :1;  
	Uint32   SatSet2 :1;  
	Uint32   SatSet3 :1;  
	Uint32   SatSet4 :1;  
	Uint32   SatSet5 :1;  
	Uint32   SatSet6 :1;  
	Uint32   SatSet7 :1;  
	Uint32   SatSet8 :1;

	Uint32   SatTestMode :1;  
	Uint32   SatPC :1;  
	Uint32   SatTiming :1;
	Uint32   SatAll :1;
	Uint32   SatSound :1;
	Uint32   SatFactory :1;
	Uint32   SatDF :1;
	Uint32   SatTF :1;
	Uint32   SatRate :1;
	Uint32   SatTimer :1;
#ifdef RECEIVE_MOD_LOCK

	Uint32   SatExtLock :1;
	Uint32   SatExtLockP :1;
#endif
	Uint32   SatLowP :1;
	Uint32   SatALev :1;
	Uint32   SatACode :1;
	Uint32   SatADemo :1;
	Uint32   SatACnt :1;






#endif
#ifdef USE_HTTP
   Uint32   WebPassword :1;

#endif

#ifdef YOURNAL
   Uint32   LogClear :1;
#endif




#ifdef PROG_DTVM
	Uint32   InitCS24 :1;           //init CS24
#endif //PROG_DTVM

 Uint32		WriteId : 1;		   //write ID

#ifdef PROG_BMDN
    Uint32   ACMMask0 :1;           //update using config file 
	Uint32   FillCFV0 :1;           //update using config file
	Uint32   FillCFV1 :1;           //update using config file
	Uint32   FillCFV2 :1;           //update using config file
	Uint32   FillCFV3 :1;           //update using config file
	Uint32   FillCFV4 :1;           //update using config file
	Uint32   FillCFV5 :1;           //update using config file
	Uint32   FillCFV6 :1;           //update using config file
	Uint32   FillCFV7 :1;           //update using config file
	Uint32   FillCFV8 :1;           //update using config file
	Uint32   ModEth :1;

#endif //PROG_BMDN

#ifdef   STEND_SPI
	Uint32   SendBuf :1;           //send buffer tospi
#endif

#ifdef PROG_BMDN3
	Uint32   RAConf0  :1;           //update using config file
	Uint32   RAConf1  :1;           //update using config file
	Uint32   ProtSt0  :1;           //update using config file
	Uint32   ProtSt1  :1;           //update using config file

	Uint32   AcmCnt0  :1;           //update using config file
	Uint32   AcmCnt1  :1;           //update using config file
	Uint32   AcmCntR  :1;           //update using config file



    Uint32   MaskGet0 :1;           //update using config file
	Uint32   MaskGet1 :1;           //update using config file
	Uint32   MaskGetR :1;           //update using config file

    Uint32   AcmEn0   :1;           //update using config file
	Uint32   AcmEn1   :1;           //update using config file
	Uint32   AcmEnR   :1;           //update using config file

    Uint32   AcmPrEn0 :1;           //update using config file
	Uint32   AcmPrEn1 :1;           //update using config file
   	Uint32   AcmSw0	  :1;
   	Uint32   AcmSw1	  :1;
   	Uint32   AcmSwR	  :1;
  	Uint32   AcmTr0	  :1;
  	Uint32   AcmTr1	  :1;
  	Uint32   AcmTrR	  :1;
  	Uint32   RAConfR  :1;
	Uint32   AcmPrEnR :1;
	Uint32   ChPr   :1;
	Uint32   ProtSt   :1;


#endif //PROG_BMDN3

#ifdef PROG_BMDN4
	Uint32   RAConf0  :1;           //update using config file
	Uint32   RAConf1  :1;           //update using config file
	Uint32   ProtSt0  :1;           //update using config file
	Uint32   ProtSt1  :1;           //update using config file

	Uint32   AcmCnt0  :1;           //update using config file
	Uint32   AcmCnt1  :1;           //update using config file
	Uint32   AcmCntR  :1;           //update using config file



    Uint32   MaskGet0 :1;           //update using config file
	Uint32   MaskGet1 :1;           //update using config file
	Uint32   MaskGetR :1;           //update using config file

    Uint32   AcmEn0   :1;           //update using config file
	Uint32   AcmEn1   :1;           //update using config file
	Uint32   AcmEnR   :1;           //update using config file

    Uint32   AcmPrEn0 :1;           //update using config file
	Uint32   AcmPrEn1 :1;           //update using config file
   	Uint32   AcmSw0	  :1;
   	Uint32   AcmSw1	  :1;
   	Uint32   AcmSwR	  :1;
  	Uint32   AcmTr0	  :1;
  	Uint32   AcmTr1	  :1;
  	Uint32   AcmTrR	  :1;
  	Uint32   RAConfR  :1;
	Uint32   AcmPrEnR :1;
	Uint32   ChPr   :1;
	Uint32   ProtSt   :1;


#endif //PROG_BMDN4


#ifdef PROG_MD310_SATI
Uint32   SatSound :1;
Uint32  MAll :1;
Uint32  NamesConfigFiles :1;
Uint32  LoadVariants :1;
Uint32  SaveVariants :1;
Uint32  AnyConfig :1;	 //working anyconfig
Uint32  RAnyConfig :1;	//for reading to pc only
Uint32  CurReadedAnyCofig :1; //number of readed anyconfig to set this variable - filled readanyconfig for reading
Uint32  RAnyConfig1 :1;
Uint32  RAnyConfig2 :1;
Uint32  RAnyConfig3 :1;
Uint32  MRfOut :1;
Uint32  MOutLev :1;
Uint32  MOutLev1 :1;
Uint32  MOutLev2 :1;
Uint32  MKout :1;
//Uint32  MRateE :1;

Uint32  MKout1 :1;
Uint32  MKin1 :1;
Uint32  MKin2 :1;
Uint32  MKin3 :1;





Uint32  MOutLevO :1;
Uint32  MOutLevOS :1;
Uint32  MTDRate :1;
Uint32  MRDRate :1;
Uint32  MTFreq :1;
Uint32  MRFreq :1;
Uint32  MTModul :1;
Uint32  MRModul :1;
Uint32  MTCdType :1;
Uint32  MRCdType :1;
Uint32  MTMode :1;
Uint32  MRMode :1;
Uint32  MRCntl :1;


Uint32  MTCode :1;
Uint32  MRCode :1;
Uint32  MDemod :1;
Uint32  MEthMode :1;
Uint32  MEthPause :1;
Uint32  MEthctl :1;
Uint32  MEthMaxF :1;
Uint32  MEthVlanP :1;
Uint32  MEbN0 :1;
Uint32  MTEbN0 :1;
Uint32  MBER :1;
Uint32  MTBER :1;
Uint32  MTBERE :1;
Uint32   MAGC :1;
Uint32  MSweep :1;
Uint32  MEthModeI :1;	  //indikation
Uint32  MEthSend :1;
Uint32  MEthReceived :1;
Uint32  MEthReceivedCRC :1;
Uint32  MEthSendU :1;
Uint32  MIfLoop :1;
Uint32  MUnModul :1;
Uint32  MACMM :1;
Uint32  IFmoduleData :1;

#endif




#ifdef 	PROG_PRM_PCH_DEM
	Uint32   lxil0 :	1;           //load xil1 to file 1 
	Uint32   lxil1 :	1;           //load xil1 to file 2
	Uint32   lxil2 :	1;           //load xil2 and xil3 to file 3
#endif //PROG_PRM_PCH_DEM

};
union  Update_REG1 {
   Uint32             all;
   struct Update_BITS  bit;
};
struct State_REGS {
    union State_REG1  Reg1;    // 
    union Update_REG1 Reg2;
};


 
 class ExDt
{
	public:
	State_REGS State;
	void LoadDevises(void);
	void LoadDDS();
	void SetRs449(unsigned char);
	void LoadDs2174();
	void LoadXILR0();
	void LoadXILR1();
 //	void LoadXILR2();
	void GetData();
	void Set();
	void SetStatus(unsigned char);
	void LoadLED();
	void CheckLosses();
  //	void ClearVE();
	void Zummer(unsigned char);
	Uint32 KeyRingInterval;
	Uint32 KeyCounter;// = 3l;

  //	ExDt();
  Init();
};


extern ExDt UsedExp;

class CntFunc
{
	public:
	Uint16  Control(Uint16, float64);
	void	Operate(Uint16);
	void	OperateInRead(Uint16);
	void	Remote(Uint16, char*, char );
	CntFunc();
};


 class MData
{
	public:
	MData();
	char * pFormat;	
	char   XPos;
	char   YPos;
   //	char   ResultStr[17];
    char   ResultStr[25];
	char *  pResultStr;
	CntFunc * pControl;	
	Uint16   OprNum;	
	char * pRemote;
	char * pRemFormat;
	char   RemChars;
	char   RemNum;
	Uint16   CntNum;	
//	MData();
};




class AnyStrings
{
	public:

 //	char cLogoLd[17];
 	char cLogoLd[26];
	char cLogoLd1[26];
 //	char cConfig[17];
   char cConfig[26];
   char cVersion[26];
   char cIPAddrU[26];
   char cIPAddrL[26];
#ifdef HAVE_GATEWAY
   char cNetMask[26];
   char cNetMaskL[26];
   char cNetwork[26];
#endif


   char cAddrRS485[26];
   char cId[26];
   char cVer[26];
   char cTestMode[26];
   char cPOK[26];
   char cMACAddress[26];
   char cXilinxFile[26];
   char cFirmware[26];
   char cIFmodule[26]; 
#ifdef CLOCK_ENABLED
   char cDate[26];
   char cTime[26];
#endif

#ifdef	PROG_MD310_SATI
//________________________________________

char cSClear[26];

  char cSatSound[26];

  char cSatSoundV[7];
  char cRemSatSound[3];


  char cSatIndication[26];
  char cMonEBN[26];
  char cMonTREBN[26];
  char cMonBER[26];
  char cMonTRBER[26];
  char cMonAGC[26];
  char cMonSweep[26];

  char cSatIndicationE[26];
  char cEthMode[26];
  char cEthStat[26];
  char cEthSend[26];
  char cEthReceive[26];
  char cEthTransmit[26];


  char cEthSendU[26];
  char cEthReceiveCRC[26];
  char cEthRcvD[26];




//_______________________________

  char cModTest[26];
  char cModIFLoop[26];
  char cModUnmodul[26];



//________________________________________
  char cSatSystem[26];
  char cSatLog[26];
  char cModulator[26];
//_____________________________________________
  char cRfOutput[26];
  char cTxOutLevel[26];
  char cTxOutLevelO[26];
  char cTxOutLevelK[26];



  char cTxModul[26];
   char cTxModulI[26];

  char cTxCodeRate[26];
  char cTxDataRate[26];
  char cTxFreq[26];



//____________________________________________

  char cDemodulator[26];

 char cTxMode[26];
 char cRxMode[26];


  char cRxModul[26];
  char cRxModulI[26];

  char cRxCodeRate[26];
  char cRxDataRate[26];
  char cRxFreq[26];
  char cRxOnOff[26];
 //  char cTxDataRate[26];



//___________________________________________
  char cCommon[26];
 // char cModTest[26];

//_______________________________________________
  char cModInterface[26];
  char cInterfaceMode[26];
  char cInterfacePause[26];
  char cInterfaceInBand[26];
  char cInterfaceMaxFrame[26];
  char cInterfaceVLANP[26];

   char cInterfaceRate[26];
#ifdef PROG_MD310_SATI2	
   char cInterfaceRateD[26];
#endif

  char cSaveLoad[26];
  char cSave[26];
  char cLoad[26];



//_______________________________________________

  char cModConfigFile[26];

#ifdef PROG_MD310_SATI2	
	char cMdConfigFile[26];
	char cDmConfigFile[26];
#endif



  char cNamesConfigFilesV[NAMES_LEN * MAX_NUM_CFG+ 1];
  char cParamsConfigFilesV[PARAMS_LEN * MAX_NUM_CFG+ 1]; 


 char cLoadVariantsV[11*7 + 1];
 char cRemLoadVariants[3];

 char cSaveVariantsV[10*2 + 1];
 char cRemSaveVariants[3];
 char cAnyConfig[3];
 char cRAnyConfig[3];
 char cRAnyConfig1[3];
 char cRAnyConfig2[3];
 char cRAnyConfig3[3];
 char cRAnyConfig4[3];
 char cRAnyConfig5[3];
 char cRAnyConfig6[3];
 char cRAnyConfig7[3];
 char cRAnyConfig8[3];
 char cRAnyConfig9[3];
 char cRemFirmFileData[3];
 char cRemIFmoduleData[3];
 char cRemIFmoduleHeader[3];
 char cRemDFE[3];
#ifdef RACM

  char cRemRACMOnOff[3];
  char cRemRACMOnOffT[3];
   char cRemRACMOffset[3];



  char cRemratimelock[3];
  char cRemratimemode[3];
  char cRemratimemse[3];
  char cRemratimestep[3];
  char cRemuebn[16][5];
  char cRemdebn[16][5];
  char cRemenamode[16][5];
  char cenamodeV[7];
   char cRemACMI[7];

  char cRemnumode[16][5];
   char cRemndmode[16][5];

  char cRemMSEI[3];
  char cnumodeV[31];




   char catl[26];
    char catl1[26];

 char catm[26];
 char caen[16][26];
 char caeb[26];

#endif




 char cCurReadedAnyCofigV[11];
 char cRemCurReadedAnyCofig[3];

//____________________________________________________________
 char cMRfOutV[7];
 char cRemMRfOut[3];
 char cRemMOutLev[3];
 char cRemMOutLev1[3];
 char cRemMOutLev2[3];
 char cRemMKout[3];
 char cRemMKout1[3];
 char cRemMKin1[3];
 char cRemMKin2[3];
 char cRemMKin3[3];

  char cRemMRateE[3];



 char cRemMOutLevO[3];
 char cRemMOutLevOS[3];



 char cRemMTDRate[3];
 char cRemMRDRate[3];
 char cRemMTFreq[3];
 char cRemMRFreq[3];


#ifndef PROG_ODU1
char cMTModulV[43];
#else
char cMTModulV[67];
#endif


char cMRModulV[43];

char cMTCdTypeV[9];
char cMRCdTypeV[9];

//char cMTModeV[16];
//char cMTModeV[16 * (2 + 6)];
char cMTModeV[16 * 23];



char cMRModeV[16];
//char cMRModeV[16 * (2 + 5)];



char cMRCntlV[25];
char cMRCntl[26];

char cMOutLevOSV[3];



//char cMTCodeV[7];
//char cMRCodeV[7];
char cMDemodV[7];
char cRemMTModul[3];
char cRemMRModul[3];

char cRemMTCdType[3];
char cRemMRCdType[3];

char cRemMTMode[3];
char cRemMRMode[3];

char cRemMRCntl[3];




char cRemMTCode[3];
char cRemMRCode[3];
char cRemMDemod[3];
char cMEthModeV[25];
char cMEthPauseV[7];
char cMEthctlV[7];
char cRemMEthMode[3];
char cRemMEthPause[3];
char cRemMEthctl[3];
char cRemMEthMaxF[3];
char cRemMEthVlanP[3];

char cRemMEbN0[3];
char cRemMTEbN0[3];
char cRemMBER[3];
char cRemMTBER[3];
char cRemMTBERE[3];
char cRemMBERE[3];

char cRemMAGC[3];
char cRemMSweep[3];
char cRemMEthSend[3];
char cRemMEthReceived[3];

char cRemMEthReceivedCRC[3];
char cRemMEthSendU[3];


char cMEthModeIV[64];
char cMIfLoopV[7];
char cMUnModulV[7];
char cRemMEthModeI[3];
char cRemMIfLoop[3];
char cRemMUnModul[3];


char cMACMMV[10];
//char cMACMMVI[7];
char cMACMMVI[26];
char cMSEI[26];


char cRemMACMM[3];
char cMACMM[26];
char cMACMMRes[26];




#endif


#ifdef PROG_PU_MSAT
   char cSatSystem[26];
   char cSatIndication[26];
   char cSatLog[26];
   char cSatSet0[26];
   char cSatSet1[26];
   char cSatSet2[26];
   char cSatSet3[26];
   char cSatSet4[26];
   char cSatSet5[26];
   char cSatSet6[26];
   char cSatSet7[26];
   char cSatSet8[26];
   char cSatGet0[26];
   char cSatGet1[26];
   char cSatGet2[26];
   char cSatGet3[26];
   char cSatGet4[26];
   char cSatGet5[26];
   char cSatGet6[26];
   char cSatGet7[26];

#endif

#ifdef PROG_PU_MSAT1
   char cSatGet8[26];
#endif

   char cMACData[26];



   char cGetCom[17];
  //	char cEmpty[17];
	char cEmpty[26];
	char cTimed[26];
	char cDated[26];
	char cMinus[26];
	char cCommands[16];
	char cInsBers[41];
	char cInType[37];
//	char cPatType[51];
//	char cPatType[61];
//	char cPatType[81];
//	char cPatType[91];
	char cPatType[101];
	char cCommandF[4];
	char cCommandP[4];
	char cPhase[13];
	char cRemPolRt[4];
	char cRemPolRd[4];
	char cRemPolSd[4];
	char cRemPolTt[4];
	char cRemBits[4];
	char cRemParity[4];
	char cRemVCC18[4];
	char cRemInType[4];
	char cRemPatType[4];
	char cRemSynce[4];
	char cRemLoop[4];
	char c2X[5];
	char c1X[4];
	char cmes0[26];
	char cmes1[26];	
	char cVolume[6];
	char cVCC18[6];
	char cBits[17];
	char cBer[17];
	char cErr[17];
	char cLoss[17];
	char cClocks[17];
	char cTest[17];
	char cInterface[17];
	char cMonitoring[17];
	char cMonitoringVCC18[17];
	char cmInType[17];
	char cmPatType[17];
	char cmTiming[17];
	char cmSynce[17];
	char cmRemote[17];
	char cRemote[17];
	char cLoop[17];
	char cmAutoSynce[17];
	char cOffOn[7];

#ifdef PROG_DTVM

	char cRateData[7];
	char cRemRateData[3];
	char cVideoData[16];
	char cRemVideoData[3];
	char cTestSignalData[26];
	char cRemTestSignalData[3];
	char cSoundData[9];
	char cRemSoundData[3];
	char cRemStateData[3];
	char cRemErrData[3];
	char cRemPointData[3];
    char cRemAddrData[3];
#endif //PROG_DTVM


#ifdef PROG_KTVM
	char cRateData[7];
	char cRemRateData[3];
	char cVideoData[10];
	char cRemVideoData[3];
	char cTestSignalData[26];
	char cRemTestSignalData[3];
	char cSoundData[9];
	char cRemSoundData[3];
	char cRemStateData[3];
	char cRemPointData[3];
    char cRemAddrData[3];
#endif //PROG_KTVM

#ifdef IncEmbIndicator
	char cRemKeyData[3];
	char cRemIndData0[3];
	char cRemIndData1[3];
 	char cRemCurData[3];
	char cRemLedData[3];
#endif //IncEmbIndicator

	char cTiming[13];
	char cRt[17];
	char cRd[17];
	char cSd[17];	
	char cTt[17];
	char cTrClocks[17];
	char cInsBer[17];
	char cHz[17];
//	char cFclk[5];
	char cFclk[6];
	char cRem[5];
	char cFclkf[7];
	char cRemTiming[4];
	char cRemVol[3];
	char cRemErr[3];
	char cRemBer[3];
	char cRemLoss[3];
	char cRemCom[3];
	char cDevDat[3]; //N1
	char cRemIns[4];
	char cRemClk[3];
#ifdef PROG_TUTS
	char cTSInp[3];
	char cTSInpTrg[3];
	char cTSOut[3];
#endif //PROG_TUTS

#ifdef PROG_BMD35
	char cRemoteMode[3];
#endif //PROG_BMD35

#ifdef PROG_PROV
	char cRemoteMode[3];
#endif //PROG_BMD35


#ifdef PROG_MPC35
	char cRemoteMode[3];
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	char cRemoteMode[3];
#endif //KTVM_PROT2



   char cLockMode[3];

#ifdef TRAP_ENABLED
    char cTrapTimer[3];
	char cTrapIp[3];
#endif //TRAP_ENABLED

#ifdef CLOCK_ENABLED
	char cTimeData1[3];
	char cTimeData2[3];
	char cTimeData3[3];
	char cTimeData4[3];
	char cTimeData5[3];
	char cTimeData6[3];
#endif //CLOCK_ENABLED

#ifdef YOURNAL
   char cCRecord[3];
#endif // YOURNAL

#ifdef PROG_BMDN
   char cConfigFile[3];
   char cConfigFile1[3];
   char cConfigFile2[3];
   char cConfigFile3[3];
   char cConfigFile4[3];
   char cConfigFile5[3];
   char cConfigFile6[3];
   char cConfigFile7[3];
   char cConfigFile8[3];
   char cConfigFile9[3];
   char cConfigFile10[3];
   char cConfigFile11[3];
   char cConfigFile12[3];
   char cConfigFile13[3];
   char cConfigFile14[3];
   char cConfigFile15[3];
   char cModForSS[3];
   char cModEth[3];

   char	cPriority0[3];
   char	cPriority1[3];
   char	cPriority2[3];
   char	cPriority3[3];
   char	cPriority4[3];
   char	cPriority5[3];
   char	cPriority6[3];
   char	cPriority7[3];
   char	cPriority8[3];

   char	cThreshold0[3];
   char	cThreshold1[3];
   char	cThreshold2[3];
   char	cThreshold3[3];
   char	cThreshold4[3];
   char	cThreshold5[3];
   char	cThreshold6[3];
   char	cThreshold7[3];
   char	cThreshold8[3];

   char	cProtect0[3];
   char	cProtect1[3];
   char	cProtect2[3];
   char	cProtect3[3];
   char	cProtect4[3];
   char	cProtect5[3];
   char	cProtect6[3];
   char	cProtect7[3];
   char	cProtect8[3];
   char	cProtect9[3];
   char	cProtect10[3];
   char	cProtect11[3];
   char	cProtect12[3];
   char	cProtect13[3];
   char	cProtect14[3];
   char	cProtect15[3];
   char	cProtect16[3];
   char	cProtect17[3];

#endif // PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
 char	cSymbolRate[3];
 char	cFreqPCh[3];
 char	cModulSK[3];
#endif //PROG_PRM_PCH_DEM





	char cRemRem[4];
	char cRazd[2];
	char c1d[4];
	char c87[3];	
  	char cNEO[4];
	char c2d[4]; 
	char c02d[5]; 
    char c3d[4]; 
  	char cPoint[2];
  //	char c8d[4];	
	char c8d[5];
	char c74f[6];	
	char c84f[6];	
	
	char cd[3];	
	char cK0[3];	
	char cK1[3];
//	char c10s[5];	
	char cs[5];
	char c4X[5];
	char c06X[5];
 	char c4d[5];
	char c4dd[4];
	char c6d[4];
	char cRemSpi[3];
	char cRemSpiCs[3];
	char cRemLEDData[3];
	char cRemIP[3];


#ifdef HAVE_GATEWAY
	char cRemNetwork[3];
	char cRemNetMask[3];
	char cRemNetMask0[3];
	char cRemNetMask1[3];
	char cRemNetMask2[3];
	char cRemNetMask3[3];
	char cRemNetwork0[3];
	char cRemNetwork1[3];
	char cRemNetwork2[3];
	char cRemNetwork3[3];



#endif
	char cRemIP0[3];
	char cRemUARTAddr[3];
	char cRemId[3];
	char cIdInd[26];

	char cRemYear[3];
	char cRemVer[3];
	char cRemVer2[3];

	char cRemTestMode[3];
 	char cRemPOK[3];
	char cRemMAC0[3];
	char cRemMAC1[3];
	char cRemMf20Data[3];
	char cRemMf20DataR[3];
 	char cRemSBuffersState[3];
	char cRemTBuffer1[3];
	char cRemTBuffer2[3];
	char cRemXilFileData[3];
	char cRemXilFileData2[3];
	char cRemXilFileData3[3];

#ifdef PROG_PRM_PCH_DEM_XIL
	char cRemXilFileData4[3];
#endif // PROG_PRM_PCH_DEM_XIL


	char cFileUpdate[3];
	char cProgVersion[3];
#ifdef  PROG_BMDN
	char cConfigFileVersion[3];
	char cAllConfigFileVersion[3];
	char cAllConfigFileVersion1[3];
	char cAllConfigFileVersion2[3];
	char cAllConfigFileVersion3[3];
 	char cAllConfigFileVersion4[3];
	char cAllConfigFileVersion5[3];



	char cRemXilFileDatax0[3];
	char cRemXilFileDatax1[3];
	char cRemXilFileDatax2[3];
	char cRemXilFileDatax3[3];
	char cRemXilFileDatax4[3];
	char cRemXilFileDatax5[3];
	char cRemXilFileDatax6[3];
	char cRemXilFileDatax7[3];
	char cRemXilFileDatax8[3];
	char cRemXilFileDatax9[3];
	char cRemXilFileDatax10[3];
	char cRemXilFileDatax11[3];
	char cRemXilFileDatax12[3];
	char cRemXilFileDatax13[3];
	char cRemXilFileDatax14[3];
	char cRemXilFileDatax15[3];

#endif

#ifdef PROG_BMDN4
  char cRemOperateProg[3];
#endif

#ifdef PROG_PU_M710
  char cRemOperateProg[3];
#endif


#ifdef PROG_PU_MSAT
	  char cRemSatSet0[3];
	  char cRemSatSet1[3];
	  char cRemSatSet2[3];
	  char cRemSatSet3[3];
	  char cRemSatSet4[3];
	  char cRemSatSet5[3];
	  char cRemSatSet6[3];
	  char cRemSatSet7[3];
  	  char cRemSatSet8[3];

	  char cRemSatGet0[3];
	  char cRemSatGet1[3];
	  char cRemSatGet2[3];
	  char cRemSatGet3[3];
	  char cRemSatGet4[3];
	  char cRemSatGet5[3];
	  char cRemSatGet6[3];
	  char cRemSatGet7[3];

#ifdef PROG_PU_MSAT1
	  char cRemSatGet8[3];
#endif

   	  char cRemSatTestMode[3];
      char cRemSatTiming[3];
	  char cRemSatSound[3];
	  char cRemSatFactory[3];
      char cRemSatDF[3];
	  char cRemSatTF[3];
	
	  char cRemSatPC[3];
   	  char cSatTestMode[26];
   	  char cSatTiming[26];

	  char cSatSound[26];
	  char cSatFactory[26];
      char cSatDF[26];
      char cSatTF[26];
	  char cSatRate[26];
	  char cSatTimer[26];

#ifdef RECEIVE_MOD_LOCK
	    char cSatExtLock[26];
		char cSatExtLockP[26];
		char cRemSatExtLock[3];
	    char cRemSatExtLockP[3];
  		char cSatExtLockV[7];
	  	char cSatExtLockPV[3];
#endif
	  char cSatLowP[26];
	  char cRemSatLowP[3];
	  char cSatLowPV[7];

	  char cSatACode[26];
	  char cRemSatACode[3];

  	 char cRemSatACnt[3];


	
	  
  	  char cSatADemo[26];
	  char cRemSatADemo[3];
	  char cSatADemoV[25];

      char cSatALev[26];
	  char cRemSatALev[3];
	  char cSatALevV[25];


	  char cCusDet[26];




	  char cSatPC[26];
	  char cSatTestModeV[7];
  //	  char cSatTestModeIV[7];
#ifndef LINE_LOCK
		  char cSatTestModeIV[9];
#else
		   char cSatTestModeIV[49];
#endif

	  char cSatTimingV[13];

	 char cSatSoundV[7];
	 char cSatFactoryV[7];

      char cSatDFV[40];
	  char cSatTFV[241];//[65];

 


	  char cSatPCV[7];

   	  char cRemSatInput[3];
	  char cRemSatLock[3];
	  char cRemSatSearch[3];
	   char cRemSatXilBlock[3];


  	  char cSatInput[26];
	  char cSatLock[26];
	  char cSatSearch[26];

 	  char cSatInputV[19];
	  char cSatLockV[13];
	  char cSatSearchV[7];
	  char cSatXilBlockV[3];
 	  char cRemSatRate[3];
	  char cRemSatTimer[3];

#endif

#ifdef USE_HTTP
	  char cRemWebPassword[3];
	  char cWebPassword[26];
#endif

#ifdef PROG_PU_M_V_A
	  char cRemAttData[3];
#endif


#ifdef YOURNAL
  char cRemLogStr0[3];
  char cRemLogStr1[3];
  char cRemLogClear[3];
  char cLogClearV[7];
  char cLogClear[26];
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
	char cRemDecFileData[3];
#endif

#ifdef USE_SOCKETSD
char cRemIPAddressUDP[8];
#endif


	char c514c[6];
	char c256c[6];
	char c200c[6];
	char c1400c[7];

 	char c100c[6];
	char cRemIP1[3];
	char cRemIP2[3];
	char cRemIP3[3];
	char c08X[5];
	char c64X[5];
	char c30c[5];
	char cRestart[2];
	char c9d[5];
	char c5d[5];

	char c63f[6];
	char c52f[6];

	char c41f[6];
	char c42f[6];

	char c21f[6];
	char c61f[6];


	char c71e[6];
    char c31f[6];
    char c32f[6];

    char c031f[7];


 //	AnyStrings(); 
	Init();
};

class AnyTest
{
	public:
 	unsigned int var1;
   	unsigned int AnyFunc(unsigned int);
    AnyTest(unsigned int);
};

class MDataC : public MData
{	
	public:
	char   Changable;
 //	volatile char*  StorageAddr;	
	Uint32  StorageAddr;	
	float64 Value;
	float64 ChangingValue;
	float64 Delta(char);
	char CharsInOne;
	void   MakeResultStrC();
	void   DrawMDataC();
	char   RunRemoteC(char*, char);
	char   RunRemoteCS(char*, char);
	char   RunRemoteC0(char*, char);
    char   RunRemoteC3(char*, char);
	float64 MaxValue;
	float64 MinValue;
	unsigned char MinMaxEnabled;


	void   RunWebC(float64);
 //   void   WriteStorageC(volatile char*, float64);
   void   WriteStorageC(Uint32, float64);
//   	float64 *  ReadStorageC(volatile char*);
  	float64 *  ReadStorageC(Uint32);
 	char * pMes0;
	char * pMes1;	
	char	DgAftPnt;
	char	HexOrDec;
	char LastDigit(void);
	char CurXPos;
	signed char Sign; 



	~MDataC(){}
	MDataC(){};

  //	MDataC(char *, char, char, char,volatile char*,
  //   char,
//	CntFunc *, Uint16, Uint16,
//	char*, char*,
//	char, char,float64, char*, char*, char, char
//	);
   Init(char *, char, char, char,
 //changing in storage  volatile char*,
   Uint32, //new : sweep in storage
     char,
	CntFunc *, Uint16, Uint16,
	char*, char*,
	char, char,float64, char*, char*, char, char
	, signed char  //Sign
	 ,float64
	 ,float64
	 ,unsigned char
	);

};


class MDataSB : public MData
{	
	public:
//	char   Changable;
 //	volatile char*  StorageAddr;	
//	Uint32  StorageAddr;	
 //t 	char Value[30];
 //t	char Value[30];
  //	char Value[514];
  char Value[TBUFF2_VALUE];
	Uint16 len;
//	char ChangingValue[30];
//	float64 Delta(char);
	char CharsInOne;
//	void   MakeResultStrSB();
//	void   DrawMDataSB();
//	char   RunRemoteSB(char*);
//	char   RunRemoteSBS(char*);
//	char   RunRemoteSB0(char*);
    char   RunRemoteSB3(char*);
//	void   ModifyUp(unsigned long);
//	void   ModifyDown(unsigned long);

 //	void   FillValue(void);


//	void   RunWebS(float64);
 //   void   WriteStorageC(volatile char*, float64);
//   void   WriteStorageS(Uint32, float64);
//   	float64 *  ReadStorageC(volatile char*);
//  	float64 *  ReadStorageS(Uint32);
// 	char * pMes0;
//	char * pMes1;	
//	char	DgAftPnt;
//	char	HexOrDec;
//	char LastDigit(void);
//	char CurXPos;
	~MDataSB(){}
  //	MDataC(char *, char, char, char,volatile char*,
  //   char,
//	CntFunc *, Uint16, Uint16,
//	char*, char*,
//	char, char,float64, char*, char*, char, char
//	);
 unsigned long RemChars1;
MDataSB(){};

  
  Init(char *,// pSetFormat, 
                        char,// SetXPos,
                         char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                         char,// SetCharsInOne,
                         CntFunc * ,//SetpControl,
                        Uint16,// SetCntNum,
                        Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                       char*,// SetpRemote,
                     char *,// SetpRemFormat, 
                     unsigned long,// SetRemChars,
                        char// SetRemNum  ,
                        ,Uint16 //len                   
                         );



};



class MDataS : public MData
{	
	public:
//	char   Changable;
 //	volatile char*  StorageAddr;	
//	Uint32  StorageAddr;	
 //t 	char Value[30];
 //t	char Value[30];
  //	char Value[514];
  char Value[TBUFF1_VALUE];
	Uint16 len;
//	char ChangingValue[30];
//	float64 Delta(char);
	char CharsInOne;
	void   MakeResultStrS();
	void   DrawMDataS();
	char   RunRemoteS(char*);
	char   RunRemoteSS(char*);
	char   RunRemoteS0(char*);
    char   RunRemoteS3(char*);
	void   ModifyUp(unsigned long);
	void   ModifyDown(unsigned long);

 //	void   FillValue(void);


//	void   RunWebS(float64);
 //   void   WriteStorageC(volatile char*, float64);
//   void   WriteStorageS(Uint32, float64);
//   	float64 *  ReadStorageC(volatile char*);
//  	float64 *  ReadStorageS(Uint32);
// 	char * pMes0;
//	char * pMes1;	
//	char	DgAftPnt;
//	char	HexOrDec;
//	char LastDigit(void);
//	char CurXPos;
	~MDataS(){}
  //	MDataC(char *, char, char, char,volatile char*,
  //   char,
//	CntFunc *, Uint16, Uint16,
//	char*, char*,
//	char, char,float64, char*, char*, char, char
//	);
MDataS(){};

  
  Init(char *,// pSetFormat, 
                        char,// SetXPos,
                         char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                         char,// SetCharsInOne,
                         CntFunc * ,//SetpControl,
                        Uint16,// SetCntNum,
                        Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                       char*,// SetpRemote,
                     char *,// SetpRemFormat, 
                     char,// SetRemChars,
                        char// SetRemNum  ,
                        ,Uint16 //len                   
                         );



};

class MDataI : public MData
{
	public:
	float64	Value;
	void   MakeResultStrI();	
	void   DrawMDataI();
	char   RunRemoteI(char*);
	char   RunRemoteIS(char*);
	char   RunRemoteI0(char*);
	char   RunRemoteI3(char*);


 //	~MDataI{}
 //	MDataI(char*, char, char, CntFunc *, 
 //	Uint16, char*, char*, char, char, char);
	Init(char*, char, char, CntFunc *, 
	Uint16, char*, char*, char, char, char);

};

/*

class MDataV : public MData
{	
	public:
	char   Changable;
 //	volatile char*  StorageAddr;
 	Uint32  StorageAddr;		
	char * pVariants;
	char Value;
	char Quantity;
	char ChangingValue;
	char CharsInOne;
	void   MakeResultStrV();
	void   DrawMDataV();
	char   RunRemoteV(char*);
	char   RunRemoteVS(char*);
	char   RunRemoteV0(char*);
 	char   RunRemoteV3(char*);

	char * pMes0;
	char * pMes1;	
//	CntFunc * pControl;
//	Uint16   CntNum;	
//	char * pRemoteV;
//	Uint16   OprNum;
	 MDataV(){};
	~MDataV(){};
//	MDataV(char *, char, char, char, Uint16, char*, char, char);
//	MDataV(char *, char, char, char,volatile char*, char*, char, char, char);
	void WriteStorageV(Uint32 , volatile char* );
	char* ReadStorageV(Uint32);
	unsigned char blinkrate;
	unsigned char curblink;

	Init(char *, char, char, char,
  //	volatile char*, 
    Uint32,
	char*, char, char, char,
	CntFunc *, Uint16, Uint16,
	char*, char*, char*, char*, char, char
	,unsigned char
	);
};
*/

class MDataV : public MData
{	
	public:
	char   Changable;
 //	volatile char*  StorageAddr;
 	Uint32  StorageAddr;		
	char * pVariants;
	unsigned long Value;
	unsigned long Quantity;
	unsigned long ChangingValue;
	char CharsInOne;
	void   MakeResultStrV();
	void   DrawMDataV();
	char   RunRemoteV(char*);
	char   RunRemoteVS(char*);
	char   RunRemoteV0(char*);
 	char   RunRemoteV3(char*);

	char * pMes0;
	char * pMes1;	
//	CntFunc * pControl;
//	Uint16   CntNum;	
//	char * pRemoteV;
//	Uint16   OprNum;
	 MDataV(){};
	~MDataV(){};
//	MDataV(char *, char, char, char, Uint16, char*, char, char);
//	MDataV(char *, char, char, char,volatile char*, char*, char, char, char);
	void WriteStorageV(Uint32 , volatile unsigned long* );
	unsigned long* ReadStorageV(Uint32);
	unsigned char blinkrate;
	unsigned char curblink;

	Init(char *, char, char, char,
  //	volatile char*, 
    Uint32,
	char*,  unsigned long, char, unsigned long,
	CntFunc *, Uint16, Uint16,
	char*, char*, char*, char*, char, char
	,unsigned char
	);
};


class Item
{
	public:
	char * line0;
	char * line1;
	char visibled;	
	Item *  pItemLeft;
	Item *  pItemRight;
	Item *  pItemUp;
	Item *  pItemDown;
	MDataV *  pDataP0; //
	MDataV *  pDataP1; // 
	MDataV *  pDataP2;
	MDataI *  pDataI0;	
	MDataI *  pDataI1;	
	MDataC *  pDataC0;
 	MDataC *  pDataC1;
 	MDataC *  pDataC2;
 	MDataC *  pDataC3;
 	MDataS *  pDataS0;
	MDataS *  pDataS1;
   	void DrawItem();
	void SetCursor();
	Init(char* , char* , char, Item*, Item*, Item*,
	Item*, MDataV*, MDataV*, MDataV*, 
	MDataI*, MDataI*,
	MDataC*, MDataC*,MDataC*,MDataC*
	,MDataS*,MDataS*
	);
};  

class Menu
{
	public:
	void DrawMessage(char *, char *);
	Item * CurrentItem;
	struct MenuStateType{
	unsigned DataChanging: 1;
	unsigned DataP0Changing: 1;
	unsigned DataP1Changing: 1;
	unsigned DataP2Changing: 1;
	unsigned DataC0Changing: 1;
    unsigned DataC1Changing: 1;
    unsigned DataC2Changing: 1;
    unsigned DataC3Changing: 1;
	} MenuState;	
	Uint32 RedrawPeriod;
	void Draw(void);
 //	void ServiceKey(void);
   	void ServiceKey(unsigned char);	
	void OperateLeft(void);
	void OperateRight(void);
	void OperateUp(void);
	void OperateDown(void);
	void OperateEnter(void);
	void OperateEsc(void);
	void StartChanging(void);
	void StopChanging (void);
	void SetChange(Uint16);
	Init(Item*, Uint32);
};

 class Pult
{
   public:
   void Init();
   void InitDevise();
   void SendDataChar(unsigned char);
   void SendControlChar(unsigned char);
   void gotoxy(Uint16, Uint16);
   void ReplaceChar(unsigned char);
   unsigned char GetDataChar();
   unsigned char GetControlChar();
   void OperateLed(unsigned char, unsigned char);
   unsigned char GetKey(void);

   struct ControlWr {           // bits   description
   unsigned char TI			:1;      	  // 
   unsigned char RI			:1;      	  // 
   unsigned char Nu1		:1;      	  // 
   unsigned char SyncFifo	:1;      	  // 
   unsigned char TEn		:1;      	  // 
   unsigned char REn		:1;      	  // 
   unsigned char ResPku		:1;      	 
   unsigned char ResDrav	:1;      	  // 
   };
   // ControlWr		PultContrWr;

 union  PULTCWR {
   unsigned char             all;
   struct ControlWr			 bit;
};
	 PULTCWR		PultCWr;
   
   struct ControlRd {           // bits   description
   unsigned char TI			:1;      	  // 
   unsigned char RI			:1;      	  // 
   unsigned char Ferr		:1;      	  // 
   unsigned char SyncFifo	:1;      	  // 
   unsigned char TEn		:1;      	  // 
   unsigned char REn		:1;      	  // 
   unsigned char ResPku		:1;      	  // 
   unsigned char ResDrav	:1;      	  // 
   };
 //   	  // 
  // };
 //trRd;
   union  PULTCRD {
   unsigned char             all;
   struct ControlRd			 bit;
};
	 PULTCRD		PultCRd;

  struct STATE {           // bits   description
   unsigned char KeyPr			:1;      	  // 1 : key is pressed 
   unsigned char CBlink			:1;      	  // 1 : cursor blink
   unsigned char Nu2			:1;      	  // 
   unsigned char Nu3			:1;      	  // 
   unsigned char Nu4			:1;      	  // 
   unsigned char Nu5			:1;      	  // 
   unsigned char Nu6			:1;      	  // 
   unsigned char Nu7			:1;      	  // 
   };

 	volatile STATE State;
 	unsigned char Key;
	unsigned char CurAddr;
//	unsigned char SendChar;
	unsigned char TBuffer[PultTBufferSize]; //buffer to keep data transmitted to indikator
	unsigned char* pTBuffer; //pointer to transmit buffer
	unsigned char TBufferCnt;
};




#ifdef __cplusplus

}
  
#endif /* extern "C" */     

extern MDataC	TestMode;
#endif // MENU_H