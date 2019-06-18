//file : work1.cpp
#include <menu1.h>
#include <hello7.h>	//t uncomment!!!
#include <embisr.h>

//#include <hello7.h>  //is in menu1.h
#include <command.h>
#include <string.h>
#include <phy_dm9161.h>
#include <math.h>
//#include <dataflash.h>
//hangt #include <stdlib.h>
//____________________________

#include <mqx.h>
#include <bsp.h>
#include <log.h>
#include <klog.h>
#include <rtcs.h>
#include <charq.h>

#include <serinprv.h>

#ifdef PROG_BMDN
#include "PVG610_API.h"
//#include "dataflash.h"

#endif //PROG_BMDN 
//________________________101220
#include "mqx_inc.h"
#include "message.h"
#include "msg_prv.h"
//________________________101220
//_____________________________

//#include <stdio.h>
//#include <stdarg.h>
//#include <conio.h>

//t16 #define SERIAL_ETH_OFF_TIMEOUT_MS  10 /* 10ms eth getted of if receive command to serial*/
//#define    IBUFFSIZE (400)
//#define NVRAM_BASE      			(pointer)(0x10000000) /* cs0 */
//#define XILINX_SIZE      			(0x02000000) /* 32Mb x 8 */
#define CFG_DATAFLASH_LOGIC_ADDR_CS1	0xE0000000
//#define CFG_DATAFLASH_LOGIC_ADDR_CS2	0xE0000000	   //TEMPORARY
#define CFG_DATAFLASH_LOGIC_ADDR_CS2	0xF0000000	   //TEMPORARY

#define IBUFFSIZE (4000)		//to remote operating
//#define    ID_ADDRESS (0xC083FBDF)
#define MF20_SLOTS (16)
//#define XilFileDataAddressD        (0xC07C9B20)
//#define XilAddressToDownloadD  (0x20f00000)    //in low 16M
 
// };

//    Enter = 0,
//    Left,
//    Right,
//    Up,
//    Down,
//    Esc,
//    Update,
//    None
//extern "C" boolean RDN_transmit( IP_IF_PTR , char* , char * );
//extern _rtcs_if_handle  ihandle0;
extern "C" int AT91F_DataflashInitx (void);

extern "C" uint_32 GetNetwork();
extern "C" uint_32 GetNetMask();


extern uint_32 speed;
extern "C" void usart0_connecting (char);

extern "C" void Init_BMD155(void);
extern "C" char CheckDone(void);
extern "C" void m_load_xilinx1 (char);
extern "C" void my_printf(unsigned char);
//extern "C" void my_printfc( char *);

extern "C" void MessageChar(unsigned char , unsigned char , unsigned char);
extern "C" void mf20_int_232(unsigned char);
extern "C" void mf20_init(void);
extern "C" void ktvm_init(void);
extern "C" void mf20_detect(void);
extern "C" void m_uart_monitor(void);
extern "C" int write_dataflash (unsigned long , unsigned int , unsigned int );
extern "C" int check_dataflash (unsigned long );

extern "C" int write_dataflash1 (unsigned long , unsigned int , unsigned int );

#ifdef XIL_FLASH
extern "C" int write_dataflashx (unsigned long , unsigned int , unsigned int );
extern "C" int read_dataflashx (unsigned long addr, unsigned long size, char *result);

extern "C" void CheckOperateFlashx(void);
#endif

extern "C" int read_dataflash (unsigned long , unsigned long , char *);
extern "C" void Parse0(void);
extern "C" void Parse1(void);
extern "C" void Parse3(void);			  
extern "C" void FillXilFileData(char);
extern "C" void FillProgVersion(void);
#ifdef  PROG_BMDN
extern "C" void FillConfigFileVersion(void);
extern "C" void FillXilFileDatax(char);
extern "C" int read_dataflashx (unsigned long , unsigned long , char *);
#endif //PROG_BMDN

extern "C" void PultDelay(void);
extern pointer fn_ptr;
extern pointer fx_ptr;
extern pointer fk_ptr;
extern "C" void ParseBuffer(char *,  char);
extern "C" void ParseBuffer0(char *,  char);
extern "C" void ParseBuffer3(char *,  char);
extern "C" void ParseBufferS(char *,  char);
extern "C" void cprintf(char* , char* );
//extern "C" int cprintf2(char* , char* );
extern "C" void ticket_on(void);
extern "C" void usart_command_eth_on(void);
extern "C" void usart_select (char);
//__________________________________________________________________


extern uint_32 TimerStartMF20;
extern pointer fusart0_ptr;
extern pointer fusart1_ptr;
extern pointer fusart3_ptr;
extern pointer fusart2_ptr;


extern char IdCommand0;
extern uint_32 CommandSize0;
extern uint_32 BufferSize0;
extern char step0;
extern char RBuff0[ACT_BUFFER_SIZE1];
extern char *  pRBuff0;
extern char TBuff0[ACT_BUFFER_SIZE1];
extern char *  pTBuff0;

extern long pTBuff0_cnt;
extern long pRBuff0_cnt;

extern long pTBuff3_cnt;
extern long pRBuff3_cnt;


//usart1 buffers and variables
extern char IdCommand;
extern uint_32 CommandSize;
extern uint_32 BufferSize;
extern char step;
//extern char RBuff[ACT_BUFFER_SIZE];
extern char *  pRBuff;
//extern char TBuff[ACT_BUFFER_SIZE];
extern char *  pTBuff;
//usart3 buffers and variables
extern char IdCommand3;
extern uint_32 CommandSize3;
extern uint_32 BufferSize3;
extern char step3;
extern char RBuff3[ACT_BUFFER_SIZE1];
extern char *  pRBuff3;
extern char TBuff3[ACT_BUFFER_SIZE1];
extern char *  pTBuff3;
//snmp buffers and variables
extern char IdCommandS;
extern uint_32 CommandSizeS;
extern uint_32 BufferSizeS;
extern char TBuffS[ACT_BUFFER_SIZE1];
extern char *  pTBuffS;
extern "C" void Transmit(void);
extern "C" void Transmit0(void);
extern "C" void Transmit3(void);
extern "C" void  my_int_disable(void);
extern "C" void wd_deinit(void);
//extern uint_32 Stephany15;

//#ifdef PROG_MF20
//extern "C" void embRS232_rcvbuf_Add(unsigned char);
//extern "C" void SaveCommut2(unsigned char);
//#endif
#define    Enter   0
#define    Left    1
#define    Right   2
#define    Up 	   3
#define    Down    4
#define    Esc 	   5
#define    Update  6
#define    None	   7

// #define ETH_SERIAL_OFF_TIMEOUT_MS  200	  // 172 -171
// #define SERIAL_ETH_OFF_TIMEOUT_MS  2 


//__________________________________________________________________

//extern uint_32 BufferSize;
//extern uint_32 BufferSizeS;

//extern char RBuff[128];
//extern char *  pRBuff;
//extern char TBuff[128];
//extern char TBuffS[128];

//extern char *  pTBuff;
//extern char *  pTBuff0;
//extern char *  pTBuffS;
//extern char *  pTBuff3;

//extern "C" void ReplacePC();
extern "C" void ReplacePC(char *);
extern "C" void wd_reset(void);
extern "C" write_xil_long(uint_32, uint_32);
extern "C" void      _psp_set_cpsr(uint_32);         
//extern "C" void      _psp_set_spsr(uint_32); 
extern "C" uint_32   _psp_get_cpsr(void);
extern uint_32 Stephany9;
extern "C" void write_xil_char(uint_32, char);
extern "C" char read_xil_char(uint_32);
extern "C" void delay_mcs (unsigned long);
extern "C" void DeviseData (uchar_ptr, uint_32 *);
extern uint_32 TimerEthOff;
extern uint_32 TimerCounter;
extern uint_32 TimerCounter1;
extern uint_32 DoneWaitCounter;
extern pointer fh_ptr;
//#define ZeroStorage		   (0)
#define ZeroStorage		   (0xFFFFFFFF)
#define SweepToPort		   (0x7000)
//#define ClkNumberStorage   (0x2 + SweepToPort)  //8 Bytes
//#define ClkNumberStorage   (0)  //8 Bytes
//#define CommandDataStorage (0xA + SweepToPort) //1 Byte
//#define CommandDataStorage (0) //1 Byte
//#define IPAddressStorage   (0xB + SweepToPort) //8 Bytes
#define IPAddressStorage   (ZeroStorage) //to keep in flach
#define IPAddress3Storage  (ZeroStorage)//(0x13 + SweepToPort) //8 Bytes
#define IPAddress2Storage  (ZeroStorage)//(0x1B + SweepToPort) //8 Bytes
#define IPAddress1Storage  (ZeroStorage)//(0x23 + SweepToPort) //8 Bytes
#define IPAddress0Storage  (ZeroStorage)//(0x3B + SweepToPort) //8 Bytes
//#define UARTAddressStorage (0x43 + SweepToPort) //8 Bytes
#define UARTAddressStorage (ZeroStorage) //8 Bytes
//#define TestModeStorage    (0x5B + SweepToPort) //8 Bytes
#define TestModeStorage    (ZeroStorage) //

#define NVRAM_SIZE      			(0x00008000) /*  32KB x 8  */

#define RestartDataStorage (ZeroStorage) //not saved
#define REDRAWPERIOD  (500)

#ifdef PROG_DTVM
#define MDATAC_LOW_BYTE	  		(7)
//#define RateDataStorage   		(0) //this address is now used!!!
#define RateDataStorage   		(0x14) //this address is now used!!!
#define VideoDataStorage  		(1)
#define TestSignalDataStorage 	(2)
#define SoundDataStorage  		(3)
#define StateDataStorage  		(4)
#define ErrDataStorage    		(0xC)
#define PointDataStorage  		(0x1FF0)
#define PointDataStorageC 		(PointDataStorage - MDATAC_LOW_BYTE) // - 7  to low byte is written to high address
#define AddrDataStorage  		(0x1FF8)
#define AddrDataStorageC 		(AddrDataStorage - MDATAC_LOW_BYTE) // - 7  to low byte is written to high address
#endif //PROG_DTVM

#ifdef PROG_KTVM
#define MDATAC_LOW_BYTE	  		(7)
//#define RateDataStorage   		(0) //this address is now used!!!
#define RateDataStorage   		(0x14) //this address is now used!!!
#define VideoDataStorage  		(1)
#define TestSignalDataStorage 	(2)	 //hier stopkadr
#define SoundDataStorage  		(3)
#define StateDataStorage  		(4)
#define PointDataStorage  		(0x1FF0)
#define PointDataStorageC 		(PointDataStorage - MDATAC_LOW_BYTE) // - 7  to low byte is written to high address
#define AddrDataStorage  		(0x1FF8)
#define AddrDataStorageC 		(AddrDataStorage - MDATAC_LOW_BYTE) // - 7  to low byte is written to high address

#endif //PROG_KTVM

#ifdef IncEmbIndicator

#define KeyDataStorage  		(ZeroStorage)
#define CurDataStorage  		(ZeroStorage)
#define LedDataStorage  		(ZeroStorage)

#endif //IncEmbIndicator

#ifdef CLOCK_ENABLED
#define TimeData1Storage  		(ZeroStorage)
#define TimeData2Storage  		(ZeroStorage)
#endif //CLOCK_ENABLED




//char cStr[124]; //for display - for ewer symbol of 24 plus four symbols U O 1 addr + \0
//char *pcStr; //will be init as pointer to  cStr
//char cStr2[124]; //for display - for ewer symbol of 24 plus four symbols U O 1 addr + \0
//char *pcStr2; //will be init as pointer to  cStr
//char cStr3[4]; //for display keys ticket
//char *pcStr3; //will be init as pointer to  cStr
//char cStr4[28]; //for display - for ewer symbol of 24 plus four symbols U O 1 addr + \0
//char *pcStr4; //will be init as pointer to  cStr
//char cStr5[28]; //for display - for ewer symbol of 24 plus four symbols U O 1 addr + \0
//char *pcStr5; //will be init as pointer to  cStr
//char cStr6[8]; //for display - for ewer symbol of 24 plus four symbols U O 1 addr + \0
//char *pcStr6; //will be init as pointer to  cStr
char IBuff[IBUFFSIZE]; //buffer for pult
uint_32 uwIBuff;
uint_32 urIBuff;
uint_32 CntIBuff; //counter for buffer
unsigned char CurSlot;
uint_32 RedrawCounter;
uint_32 RedrawCounter1;  //without this do not work adding RedrawCounter
//uchar_ptr   OID_ptr;
//unsigned char OID[32];
#ifdef IncEmbRS232
extern  EmbRS232 embRS232;
#endif


#ifdef IncEmbRS485
extern EmbRS485 embRS485;
#endif

#ifdef IncEmbIndicator
extern  EmbIndicator embIndicator;
#endif





#pragma BSS(".buff_sect")
uchar TFTP_Buffer[TFTP_BUFFER_SIZE];
#pragma BSS()

//#pragma BSS(".buff_sect")
//uchar TFTP_BufferTest[TFTP_BUFFER_SIZE];
//#pragma BSS()



#pragma BSS(".buff_2")
uchar TFTP_Buffer1[TFTP_BUFFER_SIZE1];
#pragma BSS()


//char RDN_BufferT[RDN_BUFFER_SIZE];
//char * pRDN_BufferT;
//char * pRDN_BufferR;
//char enetdest[6];
//char *pntdst;


//unsigned char debug_byte=0;
//unsigned debug_word=0;
////  —“–” “”–¿ ›Õ≈–√ŒÕ≈«¿¬»—»ÃŒ√Œ Œ«”  ////
// Œ·˙ÂÏ ˝ÌÂ„ÓÌÂÁ‡‚ËÒËÏÓ„Ó Œ«” = 32 
//to port unsigned char  *ptrENVram = (unsigned char *)0x80001000;
//to port MF20CFG *mf20cfg = (MF20CFG *)0x80000000;
//unsigned char  *ptrENVram = (unsigned char *)0x10001000;  //to port
//to






uint_32 PultInts;

CntFunc theCntFunc;
AnyTest exemplar(0);  //this constructor do not work - need init specially!
AnyStrings theAnyStrings;
//MDataC  ClkNumber;
MDataC	IPAddress;
#ifdef HAVE_GATEWAY
MDataC	Network;
MDataC	Network0;
MDataC	Network1;
MDataC	Network2;
MDataC	Network3;


MDataC	NetMask;

MDataC	NetMask0;
MDataC	NetMask1;
MDataC	NetMask2;
MDataC	NetMask3;


#endif
MDataS	DevData;
MDataC	IPAddress3;
MDataC	IPAddress2;
MDataC	IPAddress1;
MDataC	IPAddress0;
MDataC	UARTAddress;
MDataC  DevId;
MDataC  DevYear;
MDataC	DevVer1;
MDataC	DevVer2;
MDataC	TestMode;
MDataC	POK;
MDataC	Mf20Data;
MDataC	Mf20DataR;
MDataC	SBuffersState;
MDataS	TBuffer1;
MDataS	TBuffer2;
MDataC  MAC0;
MDataC  MAC1;
MDataS	XilFileData;

#ifdef PROG_MD310_SATI
MDataS	FirmFileData;
#endif



MDataS  FileUpdate;
MDataS  ProgVersion;
#ifndef PROG_BMDN6MI
MDataS	XilFileData2;
MDataS	XilFileData3;
//MDataS	XilFileData4;
#endif
#ifdef PROG_DMU6
MDataS	XilFileData2;
#endif


#ifdef PROG_TUTS
MDataC  TSInp;
MDataC  TSInpTrg;
MDataC  TSOut;
#endif //PROG_TUTS

#ifdef KTVM_PROT2
MDataC  RemoteMode;
#endif //PROG_KTVM_PROT2

#ifdef PROG_BMD35
MDataC  RemoteMode;
#endif //PROG_BMD35

#ifdef PROG_PROV
MDataC  RemoteMode;
#endif //PROG_PROV


#ifdef PROG_MPC35
MDataC  RemoteMode;
#endif //PROG_MPC35

#ifdef TRAP_ENABLED
MDataC  TrapTimer;
MDataC  TrapIp;
#endif //TRAP_ENABLED

MDataC  LockMode;

#ifdef PROG_DTVM
MDataV  RateData;
MDataV  VideoData;
MDataV	TestSignalData;
MDataV	SoundData;
MDataC	StateData;
MDataC	ErrData;
MDataC	PointData;
MDataC	AddrData;

#endif //PROG_DTVM

#ifdef PROG_KTVM
MDataV  RateData;
MDataV  VideoData;
MDataV	TestSignalData;
MDataV	SoundData;
MDataC	StateData;
//MDataC	ErrData;
MDataC	PointData;
MDataC	AddrData;
#endif //PROG_KTVM

#ifdef IncEmbIndicator
MDataC	KeyData;
MDataS  IndData0;
MDataS  IndData1;
MDataC	CurData;
MDataC	LedData;
#endif

#ifdef CLOCK_ENABLED
MDataC	TimeData1;
MDataC	TimeData2;
MDataC	TimeData3;
MDataC	TimeData4;
MDataC	TimeData5;
MDataC	TimeData6;
#endif //  CLOCK_ENABLED

#ifdef YOURNAL
MDataS	CRecord;
#endif //YOURNAL

#ifdef PROG_BMDN
MDataC	ConfigFile;
//#ifndef PROG_BMDN6MI
MDataC	ConfigFile1;

#ifndef PROG_BMDN6MI

MDataC	ConfigFile2;
MDataC	ConfigFile3;
MDataC	ConfigFile4;
MDataC	ConfigFile5;
MDataC	ConfigFile6;
MDataC	ConfigFile7;
MDataC	ConfigFile8;
MDataC	ConfigFile9;
MDataC	ConfigFile10;
MDataC	ConfigFile11;
MDataC	ConfigFile12;
MDataC	ConfigFile13;
MDataC	ConfigFile14;
MDataC	ConfigFile15;
#endif //PROG_BMDN6MI
MDataS  ConfigFileVersion;
MDataC	ModForSS;


MDataS  XilFileDatax0;
#ifndef PROG_BMDN6MI
MDataS  XilFileDatax1;
MDataS  XilFileDatax2;
MDataS  XilFileDatax3;
MDataS  XilFileDatax4;
MDataS  XilFileDatax5;
MDataS  XilFileDatax6;
MDataS  XilFileDatax7;
MDataS  XilFileDatax8;
MDataS  XilFileDatax9;
MDataS  XilFileDatax10;
MDataS  XilFileDatax11;
MDataS  XilFileDatax12;
MDataS  XilFileDatax13;
MDataS  XilFileDatax14;
MDataS  XilFileDatax15;
#endif PROG_BMDN6MI

MDataC	Priority0;
#ifndef PROG_BMDN6MI

MDataC	Priority1;
MDataC	Priority2;
MDataC	Priority3;
MDataC	Priority4;
MDataC	Priority5;
MDataC	Priority6;
MDataC	Priority7;
MDataC	Priority8;
#endif


MDataC	Threshold0;
#ifndef PROG_BMDN6MI
MDataC	Threshold1;
MDataC	Threshold2;
MDataC	Threshold3;
MDataC	Threshold4;
MDataC	Threshold5;
MDataC	Threshold6;
MDataC	Threshold7;
MDataC	Threshold8;
#endif

MDataC	Protect0;
#ifndef PROG_BMDN6MI
MDataC	Protect1;
MDataC	Protect2;
MDataC	Protect3;
MDataC	Protect4;
MDataC	Protect5;
MDataC	Protect6;
MDataC	Protect7;
MDataC	Protect8;
MDataC	Protect9;
MDataC	Protect10;
MDataC	Protect11;
MDataC	Protect12;
MDataC	Protect13;
MDataC	Protect14;
MDataC	Protect15;
MDataC	Protect16;
MDataC	Protect17;
#endif

MDataS OperateProg;

MDataS  AllConfigFileVersion;
MDataS  AllConfigFileVersion1;
MDataS  AllConfigFileVersion2;
MDataS  AllConfigFileVersion3;

MDataSB	AllConfigFileVersion4;
MDataSB	AllConfigFileVersion5;


MDataC	ModEth;
#endif //PROG_BMDN

#ifdef PROG_PU_M710
MDataS OperateProg;
#endif

#ifdef PROG_PRM_PCH_DEM
MDataC	SymbolRate;
MDataC	FreqPCh;
MDataC	ModulSK;
#endif //PROG_PRM_PCH_DEM

#ifdef	PROG_PRM_PCH_DEM_XIL
MDataS	XilFileData4;
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU3
MDataC	SymbolRate2;
MDataC	FreqPCh2;
MDataC	ModulSK2;
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4

MDataC	SymbolRate2;
MDataC	FreqPCh2;
MDataC	ModulSK2;


MDataC	SymbolRate3;
MDataC	FreqPCh3;
MDataC	ModulSK3;

MDataC	SymbolRate4;
MDataC	FreqPCh4;
MDataC	ModulSK4;

MDataS	DecFileData;

#ifndef PROG_VNV

#include "dmu4_work1.cpp"

#endif

#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PU_MSAT	 
MDataC	SatSet0;  //LMIN
MDataC	SatSet1;  //LMAX
MDataC	SatSet2;  //OUT LEVEL
MDataC	SatSet3;
MDataC	SatSet4;
MDataC	SatSet5;
MDataC	SatSet6;
MDataC	SatSet7;
MDataC	SatSet8;

MDataI  SatGet0;
MDataI  SatGet1;
MDataI  SatGet2;
MDataI  SatGet3; // balance
MDataI  SatGet4;
MDataI  SatGet5;
MDataI  SatGet6;
MDataI  SatGet7;

#ifdef PROG_PU_MSAT1
MDataI  SatGet8;
#endif

MDataV  SatTestMode;
MDataV	SatPC;

MDataV	SatInput;
MDataV	SatLock;

MDataV	SatSearch;
MDataV	SatXilBlock;

MDataV  SatTiming;
MDataV  SatTestModeI; //only for indikating test mode + master/slave mode

MDataV	SatSound;
MDataV	SatFactory;	   //13.04.19

MDataC	WebPassword;

MDataV	SatDF;
MDataV	SatTF;

MDataC	SatRate;

MDataC	SatTimer;


//MDataS	LogStr0;
//MDataS	LogStr1;

MDataV	SatExtLock;
MDataV	SatExtLockP;
#endif
MDataV	SatLowP;
MDataV	SatALev;

MDataC	SatACode;

MDataV	SatADemo;

MDataC	SatACnt;


#ifdef YOURNAL
MDataS	LogStr0;
MDataS	LogStr1;
MDataV	LogClear;
#endif

#ifdef USE_HTTP
MDataC	WebPassword;
#endif

#ifdef PROG_PU_M_V_A
MDataC	AttData;
#endif

#ifdef USE_SOCKETSD
 MDataC	IPAddressUDP;
#endif



#ifdef PROG_PU_MSAT5
MDataV	BUC24;
MDataV	BUC10;
MDataV	LNB15;
MDataV	LNB10;
#endif




Pult UsedPult;
ExDt UsedExp;

//MDataI  VolNumber;
//MDataV  CommandData;

//#ifdef PROG_PU_MSAT5
 /*
MDataV	BUC24V;
MDataV	BUC10M;
MDataV	LNB15V;
MDataV	LNB10M;
 */
//#include pu_msta5_items.cpp

//#endif	




#ifdef PROG_PU_MSAT	 

Item  SatSet0Item;
Item  SatSet1Item;
Item  SatSet2Item;
Item  SatSet3Item;
Item  SatSet4Item;
Item  SatSet5Item;
Item  SatSet6Item;
Item  SatSet7Item;
Item  SatSet8Item;

Item  SatGet0Item;
Item  SatGet1Item;
Item  SatGet2Item;
Item  SatGet3Item;
Item  SatGet4Item;
Item  SatGet5Item;
Item  SatGet6Item;
Item  SatGet7Item;

Item SatTestModeItem;
Item SatPCItem;

Item SatInputItem;
Item SatLockItem;
Item SatSearchItem;


Item SatSystemItem;
Item SatIndicationItem;

Item  ModemItem;
Item  SatTimingItem;

Item  SatSoundItem;
Item  SatFactoryItem;

Item  SatDFItem;
Item  SatTFItem;

Item  SatRateItem;
Item  SatTimerItem;

Item  CusDetItem;


Item  SatLogItem;
Item  SatLogViewItem;

#ifdef RECEIVE_MOD_LOCK
Item  SatExtLockItem;
Item  SatExtLockPItem;

#endif
Item  SatLowPItem;
Item  SatALevItem;

Item  SatACodeItem;
Item  SatADemoItem;


#endif

#ifdef YOURNAL
Item  LogClearItem;
#endif



Item  LogoItem;
Item  ConfigItem;
Item  IPItem;
Item  AddressRS485Item;	
Item  IdItem;
Item  TestItem;
Item  MACItem;
Item  XilinxItem;

#ifdef HAVE_GATEWAY
Item  NetMaskItem;
Item  NetworkItem;

#endif

#ifdef PROG_PU_MSAT5

Item  ExtDevItem;
Item  BucItem;
Item  Buc24VItem;
Item  Buc10MItem;
Item  LnbItem;
Item  Lnb15VItem;
Item  Lnb10MItem;

#endif


#ifdef CLOCK_ENABLED
Item  DateItem;
Item  TimeItem;
#endif

#ifdef USE_HTTP
Item  WebPasswordItem;
#endif

//#ifndef PROG_VNV

#ifdef PROG_MD310_SATI

#ifndef PROG_MD310_SATI2
   
#include "md100se.cpp"
#include md310s_items.cpp
#else
	 
#include "md100se2.cpp"
#include md310s2_items.cpp

#endif

#endif

//#endif //PROG_VNV

Menu UsedMenu;
MDataV  RestartData;


#ifdef	PROG_VNV1
#ifndef STM2UDP
#include "vnv_work1.cpp"
#else
#include "stm2udp_work1.cpp"
#endif
#endif




 struct JUMPBUFF
{
	char data[500000];
};
JUMPBUFF *jumpbuff;

#ifdef PROG_PU_M_V


struct DevInfo
{
//101117  unsigned char DevAddr;
  unsigned char DevType;
  unsigned char DevAddr; //101117

};
struct DevConfig
{
 unsigned char DevQuantity;
 unsigned char reserved;
 DevInfo devinfo[DEVCONFIG_QUANTITY];
};

union uDevConfig
{
  DevConfig devconfig;
  unsigned char byte[(DEVCONFIG_QUANTITY << 1) + 2];
};

uDevConfig udevconfig;

extern "C" void Setudevconfig(unsigned char num, unsigned char val)
{
 if(num < ((DEVCONFIG_QUANTITY << 1) + 2))
 {
  udevconfig.byte[num] = val;
 }
}

extern "C" unsigned char Getudevconfig(unsigned char num)
{
 if(num < (DEVCONFIG_QUANTITY << 1) + 2)
 {
 return	udevconfig.byte[num];
 }
 else
 {
  return 0;
 }
}


extern "C" unsigned char GetDevQuantity()
{
// embMsg485Request.Init();
 if(udevconfig.devconfig.DevQuantity <= DEVCONFIG_QUANTITY)
 {
 return	 udevconfig.devconfig.DevQuantity;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevAddr(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevAddr;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevType(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevType;
 }
 else
 {
 return 0;
 }
}


extern "C" unsigned char GetDevPointer(unsigned char addr)
{

 for(long iid = 0; iid < cur_req_quantity; iid++)
 {
	   /*
        printfp("\n\r+");
               printfpd("%X",iid);
			     printfp(" s:");
               printfpd("%X",udevconfig.devconfig.devinfo[iid].DevAddr);
     printfp(" a:");
               printfpd("%X", addr);
		*/
  if(udevconfig.devconfig.devinfo[iid].DevAddr == addr)
  {
  /*
   	  printfp("\n\r)");
               printfpd("%X",iid);
		 */
    return iid;
  }
 }
 /*
	  printfp("\n\r&");
               printfpd("%X",iid);
			   */
 return BAD_POINTER;
}



#endif // PROG_PU_M_V

#ifdef PROG_PU_M_V_A

unsigned long GetAttData(void)
{
   return (unsigned long)AttData.Value;
}

void SetAttData(unsigned long val)
{
   #ifdef TEST_PUMVA
	printfpd("\n\rval:%02X", val);
   #endif

  AttData.Value = val;
   AttData.ChangingValue = val;
}


#ifndef PROG_ODU4


unsigned char IO_Pin97_Read(void)
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   return (pio_ptr->PDSR & (1 << 15)) ? 1 : 0; 
// return 0; //temporary test
}

unsigned char IO_Pin91_Read(void)
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   return (pio_ptr->PDSR & (1 << 11)) ? 1 : 0; 
// return 0; //temporary test
}


void SetPin96ToZero(void)
{
        AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->CODR = 1<<14; //
		piob_ptr->SODR = 1<<9; // pin89 invert pin96

}

void SetPin96ToOne(void)
{
 		AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->SODR = 1<<14; // one
		piob_ptr->CODR = 1<<9; // pin89 invert pin96

}

void IOs_Init(void)
{

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 0);	 //pin91 in

   if(!IO_Pin91_Read())
   {
	pd_pm = 0;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//140507 pin 89 output
 // init pins 96 as output and 97 as input 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// pin 96 output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//pin97	 as input
//___________________________________________________________________________ 

 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 0);	 //pin91 in
//___________________________________________________________________________

	  SetPin96ToZero();
	}
	else
	{
	pd_pm = 1;
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 104 out
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 101 out
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 99 out
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 97 out
 
 	  SetAtt((unsigned char)GetAttData());

//___________________make pin 96 olwais zero_
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);   // pin 96 output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//140507 pin 89 output

   SetPin96ToZero();
//___________________

 	}



 //  SetPin96ToZero();
 //  SetAtt((unsigned char)GetAttData());
}



#else


unsigned char IO_Pin71_Read(void)
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
   return (pio_ptr->PDSR & (1 << 25)) ? 1 : 0; 
// return 0; //temporary test
}


void SetPin100ToZero(void)
{
        AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->CODR = 1<<18; //
		piob_ptr->SODR = 1<<19; // pin101  invert pin100

}

void SetPin100ToOne(void)
{
 		AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->SODR = 1<<18; // one
		piob_ptr->CODR = 1<<19; //  pin101  invert pin100


}


void IOs_Init(void)
{

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A,25, AT91RM9200_PIO_PERIPHERAL_IO, 0);	 //pin71 in
    _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);  // pin 100 output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); 	//pin101 as output


   if(!IO_Pin71_Read())
   {
	pd_pm = 0;

 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//140507 pin 89 output
 // init pins 96 as output and 97 as input 
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// pin 100 output
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//pin 101 output
//___________________________________________________________________________ 

 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 0);	 //pin91 in
//___________________________________________________________________________

	//  SetPin96ToZero();
	}
	else
	{
	pd_pm = 1;
 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 104 out
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 101 out
 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 99 out
 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //pin 97 out
 
 	//  SetAtt((unsigned char)GetAttData());

//___________________make pin 96 olwais zero_
  //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);   // pin 96 output
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//140507 pin 89 output

 //  SetPin96ToZero();
//___________________

 	}



 //  SetPin96ToZero();
 //  SetAtt((unsigned char)GetAttData());
}


#endif


void SetAtt(unsigned char data)
{
 		AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

		if(data & MASK_BIT_3)
		{
		 piob_ptr->CODR = 1<<22;
		}
		else
		{
         piob_ptr->SODR = 1<<22; // one
		}

       if(data & MASK_BIT_2)
		{
		 piob_ptr->CODR = 1<<19;
		}
		else
		{
         piob_ptr->SODR = 1<<19; // one
		}

		if(data & MASK_BIT_1)
		{
		 piob_ptr->CODR = 1<<17;
		}
		else
		{
         piob_ptr->SODR = 1<<17; // one
		}

		if(data & MASK_BIT_0)
		{
		 piob_ptr->CODR = 1<<15;
		}
		else
		{
         piob_ptr->SODR = 1<<15; // one
		}
}










struct DevInfo
{
//101117  unsigned char DevAddr;
  unsigned char DevType;
  unsigned char DevAddr; //101117

};
struct DevConfig
{
 unsigned char DevQuantity;
 unsigned char reserved;
 DevInfo devinfo[DEVCONFIG_QUANTITY];
};

union uDevConfig
{
  DevConfig devconfig;
  unsigned char byte[(DEVCONFIG_QUANTITY << 1) + 2];
};

uDevConfig udevconfig;

extern "C" void Setudevconfig(unsigned char num, unsigned char val)
{
 if(num < ((DEVCONFIG_QUANTITY << 1) + 2))
 {
  udevconfig.byte[num] = val;
 }
}

extern "C" unsigned char Getudevconfig(unsigned char num)
{
 if(num < (DEVCONFIG_QUANTITY << 1) + 2)
 {
 return	udevconfig.byte[num];
 }
 else
 {
  return 0;
 }
}


extern "C" unsigned char GetDevQuantity()
{
// embMsg485Request.Init();
 if(udevconfig.devconfig.DevQuantity <= DEVCONFIG_QUANTITY)
 {
 return	 udevconfig.devconfig.DevQuantity;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevAddr(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevAddr;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevType(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevType;
 }
 else
 {
 return 0;
 }
}


extern "C" unsigned char GetDevPointer(unsigned char addr)
{

 for(long iid = 0; iid < cur_req_quantity; iid++)
 {
	   /*
        printfp("\n\r+");
               printfpd("%X",iid);
			     printfp(" s:");
               printfpd("%X",udevconfig.devconfig.devinfo[iid].DevAddr);
     printfp(" a:");
               printfpd("%X", addr);
		*/
  if(udevconfig.devconfig.devinfo[iid].DevAddr == addr)
  {
  /*
   	  printfp("\n\r)");
               printfpd("%X",iid);
		 */
    return iid;
  }
 }
 /*
	  printfp("\n\r&");
               printfpd("%X",iid);
			   */
 return BAD_POINTER;
}



#endif // PROG_PU_M_V_A


#ifdef PROG_UPS


struct DevInfo
{
//101117  unsigned char DevAddr;
  unsigned char DevType;
  unsigned char DevAddr; //101117

};
struct DevConfig
{
 unsigned char DevQuantity;
 unsigned char reserved;
 DevInfo devinfo[DEVCONFIG_QUANTITY];
};

union uDevConfig
{
  DevConfig devconfig;
  unsigned char byte[(DEVCONFIG_QUANTITY << 1) + 2];
};

uDevConfig udevconfig;

extern "C" void Setudevconfig(unsigned char num, unsigned char val)
{
 if(num < ((DEVCONFIG_QUANTITY << 1) + 2))
 {
  udevconfig.byte[num] = val;
 }
}

extern "C" unsigned char Getudevconfig(unsigned char num)
{
 if(num < (DEVCONFIG_QUANTITY << 1) + 2)
 {
 return	udevconfig.byte[num];
 }
 else
 {
  return 0;
 }
}


extern "C" unsigned char GetDevQuantity()
{
// embMsg485Request.Init();
 if(udevconfig.devconfig.DevQuantity <= DEVCONFIG_QUANTITY)
 {
 return	 udevconfig.devconfig.DevQuantity;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevAddr(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevAddr;
 }
 else
 {
 return 0;
 }
}

extern "C" unsigned char GetDevType(unsigned char pointer)
{
 if(pointer < DEVCONFIG_QUANTITY)
 {
 return  udevconfig.devconfig.devinfo[pointer].DevType;
 }
 else
 {
 return 0;
 }
}


extern "C" unsigned char GetDevPointer(unsigned char addr)
{

 for(long iid = 0; iid < cur_req_quantity; iid++)
 {
	   /*
        printfp("\n\r+");
               printfpd("%X",iid);
			     printfp(" s:");
               printfpd("%X",udevconfig.devconfig.devinfo[iid].DevAddr);
     printfp(" a:");
               printfpd("%X", addr);
		*/
  if(udevconfig.devconfig.devinfo[iid].DevAddr == addr)
  {
  /*
   	  printfp("\n\r)");
               printfpd("%X",iid);
		 */
    return iid;
  }
 }
 /*
	  printfp("\n\r&");
               printfpd("%X",iid);
			   */
 return BAD_POINTER;
}



#endif // PROG_UPS


//#define PROG_PU_M_MUX //101115 for test

#ifdef USART0_TRY_PDC_1T
extern "C" void printfp(char* Buff)
{

 //if(!start_main_loop) return;
  while(*Buff)
  {
   ToPdcTu0(* Buff++);

//  fputc(* Buff++, fusart0_ptr); 
  }
}

extern "C" void printfpd(char* format, unsigned long data)
{
//if(!start_main_loop) return;

 char Buff[100];
 sprintf(Buff, format, data);
 Buff[99] = 0;
 printfp(Buff);

 }

//extern "C" void printfpdv(char* format, float64 data)
extern "C" void printfpdv(char* format, float data)
{
//if(!start_main_loop) return;

 char Buff[100];
 sprintf(Buff, format, data);
 Buff[99] = 0;
 printfp(Buff);

 }


#endif

#ifdef USART2_TRY_PDC_1T
extern "C" void printfp2(char* Buff)
{
//if(!start_main_loop) return;

  while(*Buff)
  {
   ToPdcTu2(* Buff++);

//  fputc(* Buff++, fusart0_ptr); 
  }
}

extern "C" void printfpd2(char* format, unsigned long data)
{
//if(!start_main_loop) return;

 char Buff[15];
 char* pBuff;
 pBuff = &Buff[0];
 sprintf(Buff, format, data);
 Buff[14] = 0;

 for(unsigned i = 0; i < 15; i++)
 {
	 if(Buff[i] == 0) break;
     ToPdcTu2(Buff[i]);
 }


// printfp(Buff);

 }

#endif

#ifdef USART1_TRY_PDC_1T
extern "C" void printfp1(char* Buff)
{
//if(!start_main_loop) return;

  while(*Buff)
  {
   ToPdcTu1(* Buff++);

//  fputc(* Buff++, fusart0_ptr); 
  }
}

extern "C" void printfpd1(char* format, unsigned long data)
{
//if(!start_main_loop) return;

 char Buff[15];
 char* pBuff;
 pBuff = &Buff[0];
 sprintf(Buff, format, data);
 Buff[14] = 0;

 for(unsigned i = 0; i < 15; i++)
 {
	 if(Buff[i] == 0) break;
     ToPdcTu1(Buff[i]);
 }


// printfp(Buff);

 }

#endif







#ifdef USE_QUOTE_SERVER

/*FUNCTION*-------------------------------------------------------------
*
* Function Name    : ECHOSRV_init
* Returned Value   : error code
* Comments  :  Start the port 7 echo server.
*
*END*-----------------------------------------------------------------*/
void QUOTE_server_task(pointer, pointer); //declare

//uint_32 QUOTE_SRV_init
extern "C" uint_32  QUOTE_SRV_init
   (
      char_ptr name,
      uint_32  priority,
      uint_32  stacksize
   )
{ /* Body */
//   return RTCS_task_create(name, priority, stacksize, ECHOSRV_task, NULL);
   return RTCS_task_create(name, priority, stacksize, QUOTE_server_task, NULL);
} /* Endbody */


#define BUFF_SIZE (64)

/*TASK*-----------------------------------------------------------------
*
* Function Name  : QUOTE_server
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/

extern "C" void QUOTE_server_task
(
//100202    uint_32 temp
      pointer dummy,	   //100202
      pointer creator	   //100202
)
{
   sockaddr_in    laddr, raddr;
  // ip_mreq        gaddr;
   uint_32        sock, listensock;
   int_32         length;
   uint_32        index;
   uint_32        error;
   uint_16        rlen;
//_________________________________________
  char                 buff[BUFF_SIZE];
//  int_32               numbytes;
//_________________________________________

   uint_32        optval, optlen;
  // int_32         length;

//______________________________________________________________
/*
char_ptr Quotes[] =
{
 "Anyone who has never made a mistake has never tried anything new.",
 "The only way to discover the limits of the possible, "
 "\nis to go beyond them into the impossible.",
 "Good is the enemy of best",
 "Repetition teaches the Donkey",
 "Check the task stack sizes!",
 "Give a man a fish and he can eat for a day.  "
 "Teach a man to fish and he can eat for a lifetime.",
 "Expect the best, prepare for the worst",
 "Man who sitteth on upturned tack shall surely rise",
 "Don't use an axe to remove a fly from a friend's forehead",
 "Einmal ist keinmal",
 "Carpe diem",
 "The art of navigation is knowing where you are not",
 "Success is 99 percent failure",
 "Brevity is the soul of wit",
 "Neither a borrower, nor a lender be",
 "Get thee to a nunnery",
 "Something is rotten in the state of Denmark",
 "There are more things in heaven and earth, Horatio "
 "than are dreamt of in your philosophy.",
 "Though this be madness, yet there is method in't",
 "This above all: to thine own self be true"
 "\nAnd it must follow, as the night the day,"
 "\nThou canst not then be false to any man.",
 "What's in a name? that which we call a rose"
 "\nBy any other name would smell as sweet.",
 "From 2001: Open the pod bay doors, Hal.",
 "Apollo 13: Houston, we have a problem.",
 "Back to the Future: Where we're going we don't need roads.",
 "Forest Gump: Life is like a box of chocolates.",
 "Star Wars: May the Force be with you.",
 "Star Trek: Live long and prosper. Engage!",
 "Peter Pan: Second star on the right, straight on 'til morning.",
 "Terminator 2: Hasta la vista, baby.",
 "The Wizard of Oz: Toto, I have a feeling we're not in Kansas anymore.",
 "Dr. McCoy: Damn it Jim, I'm a doctor, not an engineer!",
 "Winston Churchill:"
 "\nHe has all of the virtues I dislike and none of the vices I admire.",
 "Einstein: Everything should be made as simple as possible, but not simpler.",
 "Whether you think you can or think you can't -- you are right.",
 "Traffic is very heavy at the moment, so if you are thinking of leaving, "
 "you'd better set off a few minutes earlier.",
 "Yogi Berra: Always go to other people's funerals, "
 "otherwise they won't come to yours.",
 NULL          //  End of quotes marker 
};
*/
//______________________________________________________________



   /* Quote server services port 17 */
   laddr.sin_family      = AF_INET;
   laddr.sin_port        = 17;
   laddr.sin_addr.s_addr = INADDR_ANY;

   /* Bind to UDP port */
   sock = socket(PF_INET, SOCK_DGRAM, 0);
   if (sock == RTCS_HANDLE_ERROR) {
    //  printf("\nCreate datagram socket failed");
      _task_block();
   } /* Endif */
   error = bind(sock, &laddr, sizeof(laddr));
   if (error != RTCS_OK) {
  //    printf("\nDatagram bind failed - 0x%lx", error);
      _task_block();
   } /* Endif */
/* 100202
#ifdef ENET_DEVICE
   gaddr.imr_multiaddr.s_addr = 0xE0000100;   //   224.0.1.0 
   gaddr.imr_interface.s_addr = enet_ipaddr;
   error = setsockopt(sock, SOL_IGMP, RTCS_SO_IGMP_ADD_MEMBERSHIP, &gaddr, sizeof(gaddr));
   if (error != RTCS_OK) {
 //     printf("\nAdd membership failed on ENET - 0x%lx", error);
   } 
#endif

#ifdef PPP_DEVICE
   gaddr.imr_multiaddr.s_addr = 0xE0000100;  //    224.0.1.0 
   gaddr.imr_interface.s_addr = PPP_LOCADDR;
   error = setsockopt(sock, SOL_IGMP, RTCS_SO_IGMP_ADD_MEMBERSHIP, &gaddr, sizeof(gaddr));
   if (error != RTCS_OK) {
   //   printf("\nAdd membership failed on PPP - 0x%lx", error);
   } 
#endif
 */
   /* Listen on TCP port */
   sock = socket(PF_INET, SOCK_STREAM, 0);
   if (sock == RTCS_HANDLE_ERROR) {
   //   printf("\nCreate stream socket failed");
      _task_block();
   } /* Endif */
   error = bind(sock, &laddr, sizeof(laddr));
   if (error != RTCS_OK) {
   //   printf("\nStream bind failed - 0x%lx", error);
      _task_block();
   } /* Endif */
   error = listen(sock, 0);
   if (error != RTCS_OK) {
  //    printf("\nListen failed - 0x%lx", error);
      _task_block();
   } /* Endif */
   listensock = sock;

  // printf("\n\nQuote Server active on port 17\n");

   index = 0;

  /*
   for (;;) {

      sock = RTCS_selectall(0);

      if (sock == listensock) {

   //       Connection requested; accept it 
         rlen = sizeof(raddr);
         sock = accept(listensock, &raddr, &rlen);
         if (sock == RTCS_HANDLE_ERROR) {
     //       printf("\nAccept failed, error 0x%lx",
               RTCS_geterror(listensock);
            continue;
         } 
     //    printf("\nConnection from %ld.%ld.%ld.%ld, port %d",
     //       (raddr.sin_addr.s_addr >> 24) & 0xFF,
      //      (raddr.sin_addr.s_addr >> 16) & 0xFF,
       //     (raddr.sin_addr.s_addr >>  8) & 0xFF,
        //     raddr.sin_addr.s_addr        & 0xFF,
         //    raddr.sin_port);

      //   send(sock, Quotes[index], strlen(Quotes[index]) + 1, 0);
   //	     send(sock, "Hi", strlen("Hi") + 1, 0);
  //100204       _time_delay(1000);
  //100204       shutdown(sock, FLAG_CLOSE_TX);
//____________________________________________________________________

       numbytes = recv(sock, buff, sizeof(buff), 0);
         if (numbytes == RTCS_ERROR) {
  //          printf("recv error: 0x%lx\n", RTCS_geterror(sock));
            continue;
         } 
		 else
		 {
		   send(sock, buff, numbytes, 0);
		 }

//     buff[numbytes] = '\0';
//     printf("%s\n", buff);
//____________________________________________________________________
      } 
      else
      {

       //   Datagram socket received data 
         _mem_zero(&raddr, sizeof(raddr));
         rlen = sizeof(raddr);
         length = recvfrom(sock, NULL, 0, 0, &raddr, &rlen);

         if (length == RTCS_ERROR)
        {
    //      printf("\nError %lx receiving from %ld.%ld.%ld.%ld,%d",
    //      RTCS_geterror(sock),
    //      (raddr.sin_addr.s_addr >> 24) & 0xFF,
    //      (raddr.sin_addr.s_addr >> 16) & 0xFF,
    //      (raddr.sin_addr.s_addr >>  8) & 0xFF,
    //      raddr.sin_addr.s_addr        & 0xFF,
    //      raddr.sin_port);
          	continue;
         } 

      //    Success on receive 
    //     printf("\nDatagram from %ld.%ld.%ld.%ld,%d",
  //          (raddr.sin_addr.s_addr >> 24) & 0xFF,
   //         (raddr.sin_addr.s_addr >> 16) & 0xFF,
   //         (raddr.sin_addr.s_addr >>  8) & 0xFF,
   //          raddr.sin_addr.s_addr        & 0xFF,
   //          raddr.sin_port);

    //      Send a quote back 
   //      sendto(sock, Quotes[index], strlen(Quotes[index]) + 1, 0, &raddr, rlen);
		       sendto(sock, "Hi", strlen("Hi") + 1, 0, &raddr, rlen);
      }//  Endif 

  //    ++index;
  //    if (Quotes[index] == NULL) {
  //       index = 0;
  //    } 

   } 
	 */
//______________________________________________________________________________________
  for (;;) {

      sock = RTCS_selectall(0);

      if (sock == listensock) {

         /* Connection requested; accept it */
         rlen = sizeof(raddr);
         accept(listensock, &raddr, &rlen);

      } else {

         /* Get the socket type */
         getsockopt(sock, SOL_SOCKET, RTCS_SO_TYPE, (char_ptr)&optval, &optlen);

         if (optval == SOCK_STREAM) {

            length = recv(sock, buff, BUFF_SIZE, 0);
            if (length == RTCS_ERROR) {
               shutdown(sock, FLAG_CLOSE_TX);
            } else {

         //      send(sock, buff, length, 0);
			  rpac_counter++;

            } /* Endif */

         } else { /* optval == SOCK_DGRAM */

            rlen = sizeof(raddr);
            length = recvfrom(sock, buff, BUFF_SIZE, 0, &raddr, &rlen);
     //       sendto(sock, buff, length, 0, &raddr, rlen);
			 rpac_counter++;
         } /* Endif */

      } /* Endif */

   } /* Endfor */
//_______________________________________________________________________________________





} /* Endbody */


#endif //USE_QUOTE_SERVER



#ifdef USE_TCPIP_CLIENT
//#define BEFFC_SIZE (1500) 
#define BEFFC_SIZE (3000) 

unsigned char q_client_state;

/*TASK*-----------------------------------------------------------------
*
* Function Name  : QUOTE_client
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/

extern "C" void QUOTE_client
(
    uint_32 temp
)
{ /* Body */
  static  sockaddr_in          laddr, raddr;
  static  char                 buff[BEFFC_SIZE];
//100202   char                 host[64];
//100202   HOSTENT_STRUCT_PTR   host_ptr;
  static  uint_32              socket_stream, socket_dgram;
   int_32               numbytes;
   uint_32              error;
   uint_32              choice;
   uint_16              rlen;
 if(!q_client_state)
 {
   //	 for(long i = 0; i < BEFFC_SIZE - 1; i++)
  //	 {
   //	   buff[i] = 0x47;
  //	 }
	   buff[BEFFC_SIZE - 1]	= '\0';

 //  printf("\n\rRTCS Quote of the Day Client\n");
 //
//100202   while (TRUE) {
      /* let user choose the local address  */

//khglkh
      laddr.sin_family      = AF_INET;
      laddr.sin_port        = 0;
      laddr.sin_addr.s_addr = 0;

      /* Get the IP address for the server */
  //    printf("\n\rHost: ");
//100202      scanf("%s\n", host);
//100202      host_ptr = gethostbyname(host);
//      if (host_ptr == NULL) {
//         printf("\nUnable to resolve ip address for host: %s\n", host);
//100202         continue;
//      } /* Endif */

      /* Remote address, QOTD uses port 17 */
      raddr.sin_family      = AF_INET;
      raddr.sin_port        = 17;
//100202      raddr.sin_addr.s_addr = *((_ip_address _PTR_)host_ptr->h_addr_list[0]);
//unsigned long ip_addr_clt = 0x9b9b9b76;
 raddr.sin_addr.s_addr = 0x9b9b9bE6;//230
// raddr.sin_addr.s_addr = 0x9b9b9b76;//118*((_ip_address _PTR_)host_ptr->h_addr_list[0]);
// 	  raddr.sin_addr.s_addr = 0x9b9b9bE9;//233 *((_ip_address _PTR_)host_ptr->h_addr_list[0]);
 //100202     _mem_free(host_ptr);
      rlen = sizeof(raddr);

   //   printf("\n1) Stream Socket\n2) Datagram Socket\nChoice: ");
  //    scanf("%d\n", &choice);

#ifndef USE_UDP
	  choice = 1; //100202
#else
	  choice = 2; //100202
#endif

      if (choice == 1) {



         /* User wants a stream connection */
         socket_stream = socket(PF_INET, SOCK_STREAM, 0);
         /* Start SPR P122-0295-01 */
         if (socket_stream == RTCS_SOCKET_ERROR) {
         /* End SPR P122-0295-01 */
 //           printf("Error creating socket\n");
            _task_block();
         } /* Endif */

         error = bind(socket_stream, &laddr, sizeof(laddr));
         if (error != RTCS_OK) {
 //           printf("Bind failed\n");
            _task_block();
         } /* Endif */

         /* Connect using TCP */
 //        printf("Connecting to server: 0x%08x\n", raddr.sin_addr.s_addr);

         error = connect(socket_stream, &raddr, rlen);
         if (error != RTCS_OK) {
 //100202           printf("Unable to connect to host: %s\n", host);
//            printf("Unable to connect to host\n");
            error = shutdown(socket_stream, FLAG_ABORT_CONNECTION);
 //100202           continue;
         } /* Endif */
		 else
		 {
//		 printf("...Connected");
		 q_client_state = 1;
		 }

//          Get the quote and display it 
/* temporary
       numbytes = recv(socket_stream, buff, sizeof(buff), 0);
         if (numbytes == RTCS_ERROR) {
 //           printf("recv error: 0x%lx\n", RTCS_geterror(socket_stream));
  //100202          continue;
         } 
         buff[numbytes] = '\0';
     //    printf("%s\n", buff);
		   */
       //   shutdown 
//100303         error = shutdown(socket_stream, FLAG_CLOSE_TX);

//         if (error != RTCS_OK) {
//            printf("\nClose connection failed, 0x%lx", error);
//         } else {
//            printf("\nConnection closed");
//         } /* Endif */

      } else {
         /* User wants a datagram socket */
         socket_dgram = socket(PF_INET, SOCK_DGRAM, 0);
         /* Start SPR P122-0295-01 */
         if (socket_dgram == RTCS_SOCKET_ERROR) {
         /* End SPR P122-0295-01 */
       //     printf("Error creating socket\n");
  //100204          _task_block();
         } /* Endif */

         error = bind(socket_dgram, &laddr, sizeof(laddr));
         if (error != RTCS_OK) {
      //      printf("Bind failed\n");
  //100204          _task_block();
         } /* Endif */
		 else
		 {
		  q_client_state = 1;
		 }

         /* Connect using UDP */
    //     printf("Retrieving quote from: 0x%08x\n", raddr.sin_addr.s_addr );

         /* Inform the server we want a quote (send with no data) */
//100204         numbytes = sendto(socket_dgram, buff, 0, 0, &raddr, rlen);
//100204         if (numbytes == RTCS_ERROR) {
//       printf("sendto error: 0x%lx\n", RTCS_geterror(socket_dgram));
//100202          continue;
//100204         } /* Endif */

         /* Get the quote and display it */
//100204         numbytes = recvfrom(socket_dgram, buff, sizeof(buff), 0, &raddr, &rlen);
//100204         if (numbytes == RTCS_ERROR) {
    //        printf("recvfrom error: 0x%lx\n", RTCS_geterror(socket_dgram));
 //10202           continue;
//100204         } /* Endif */
    //     buff[numbytes] = '\0';
   //      printf("%s\n", buff);

         /* shutdown */
//100204         error = shutdown(socket_dgram, 0);
         if (error != RTCS_OK) {
      //      printf("\nClose connection failed, 0x%lx", error);
         } else {
        //    printf("\nConnection closed");
         } /* Endif */

      } /* Endif */
}
else if(q_client_state == 1)
{
   if (choice == 1)
   {
// send(sock, Quotes[index], strlen(Quotes[index]) + 1, 0);
 send(socket_stream, "Hello", strlen("Hello") + 1, 0);
   //      _time_delay(1000);
  //       shutdown(sock, FLAG_CLOSE_TX);
  }
  else
  {
//   numbytes = sendto(socket_dgram, buff, 0, 0, &raddr, rlen);  //ok
//  numbytes = sendto(socket_dgram, buff, 100, 0, &raddr,rlen);
//ok  numbytes = sendto(socket_dgram, buff, 1500, 0, &raddr,rlen);
   buff[0] = q_client_counter >> 24;	  
    buff[1] = q_client_counter >> 16;
	 buff[2] = q_client_counter >> 8;
	  buff[3] = q_client_counter;
  numbytes = sendto(socket_dgram, buff, 1460, 0, &raddr,rlen);	  //have 1502
 //   numbytes = sendto(socket_dgram, buff, (BEFFC_SIZE - 90), 0, &raddr,rlen);

 //error = sendto(sock, packet, pkt_len, 0,
   //               &TFTP_config.SADDR, sizeof(TFTP_config.SADDR));

  
  }


}



//100202   } /* Endwhile */

} /* Endbody */



#endif // USE_TCPIP_CLIENT




//#ifdef ETH_CAN_RESTART



extern  uint_32  rtcs_result;
extern  _enet_handle    enet_handle0;    //100201
extern  _enet_address   enet_local0; //this is mac!!!!!!!   //100201
extern "C" void Enet_is_not_init();
extern "C" uint_32 GetIP();
extern char_ptr taskname;
extern "C" void    _bsp_enet_init(AT91RM9200_EMAC_REG_STRUCT_PTR);


extern "C" void Restart_Eth4(void)
{
// printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth4\n\n\n\n\n\n\n\n\n\n\n\n\\");
AT91RM9200_EMAC_REG_STRUCT_PTR emac_ptr;
 emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
 _bsp_enet_init(emac_ptr);


}

extern "C" void Set_enet_local0(uchar *);
extern unsigned long tcpip_id;
extern unsigned long snmp_id;
extern unsigned long rdn_id;
extern unsigned long rdnt_id;
extern unsigned long tftp_id;
#ifndef DISABLE_ETHERNET
#ifdef TRY_UNBLOCK


//#ifndef DISABLE_ETHERNET

extern "C" void Restart_Eth5(void)
{
#ifndef USART0_TRY_PDC_1T
  printf("\n\r >>>>>>>>>>>>>>>>R E S T A R T>>>>>>>>>>>>>>>>>>>>>>>>");
#endif
 //  printf("\n\rihandle0 0: 0x%X",(unsigned long)(ihandle0));
  Set_enet_local0((uchar*)&enet_local0[0]);
//#ifndef PROG_PRM_PCH_N  
//    Initialize RTCS 
//#ifndef PROG_PRM_PCH_N   
//#ifndef  DISABLE_ETHERNET
// rtcs_result = RTCS_create();   //1a
// rtcs_result = RTCS_create1();   //1a
//________________________________________________101215
// RTCS_if_unbind(ihandle0, GetIP());	//hangt	 101215
// RTCS_if_remove(ihandle0); 			//hangt  101215
 //101216t  _mem_free(ihandle0);	 //ok


_msg_cleanup(_task_get_td(tcpip_id)); //hier need have td for tcpip
_msg_cleanup(_task_get_td(rdnt_id));
_msg_cleanup(_task_get_td(rdn_id));
_msg_cleanup(_task_get_td(snmp_id));

//_________________________________________________101215

_task_destroy(tcpip_id); //
_task_destroy(rdnt_id);   //
_task_destroy(rdn_id);   //
_task_destroy(snmp_id);
//101216_task_destroy(tftp_id);   //
//__________________________________________________________
//RTCS_part_destroy(RTCS_data_ptr->RTCS_socket_partition);

//__________________________________________________________

// printf("\n\rihandle0 1: 0x%X",(unsigned long)(ihandle0));
 rtcs_result = RTCS_create2();   //1a
//  printf("\n\rihandle0 2: 0x%X",(unsigned long)(ihandle0));
//ok  
//  Install RTCS Applications 
#ifndef USE_TCPIP_CLIENT
#ifndef USE_QUOTE_SERVER

#ifdef USE_TFTPSRV 
//101216 rtcs_result = TFTPSRV_init("TFTP Server", 7L, 2000L);   //2a  //t 
#endif // USE_TFTPSRV
#ifdef USE_SNMP 
 rtcs_result = SNMP_init("SNMP Agent", 7L, 2000L); //3a

  MIB1213_init(); //4a //my

#endif //USE_SNMP  
  
  
#endif
#endif 

  
//ok
//#ifndef PROG_PRM_PCH_N    
//t  rtcs_result = ENET_initialize(0, enet_local0, 0x00000000, &enet_handle0);// with this get off))) //1b
//  rtcs_result = ENET_initialize3(0, enet_local0, 0x00000000, &enet_handle0); //1b
   rtcs_result = ENET_initialize4(0, enet_local0, 0x00000000, &enet_handle0); //1b

 // printf("\n\rihandle0 3: 0x%X",(unsigned long)(ihandle0));

//ok return; //101206
//ok  
//  if (rtcs_result != ENET_OK) //?? olweis ok?
  //  {
 //     Enet_is_not_init();
 //   } 
    
//#endif  // PROG_PRM_PCH_N 
 // printf("\n\r > enet_handle0 : 0x%X",(unsigned long)(enet_handle0));
  
//hier hangt!!!!

// after this uncomment - ok

//return;
   /*
 //  printf("\n\r");
  // printf("enet_handle0 %X", (unsigned long) (enet_handle0));
  // printf("&ihandle0 %X", (unsigned long) (&ihandle0));
 //  printf("ihandle0 %X", (unsigned long) (ihandle0));
	*/
   
//101220   rtcs_result = RTCS_if_add(enet_handle0, RTCS_IF_ENET, &ihandle0);  //2b
 //   rtcs_result = RTCS_if_add(enet_handle0, RTCS_IF_ENET, &ihandle1);  //2b
   rtcs_result = RTCS_if_add1(enet_handle0, RTCS_IF_ENET, &ihandle0);  //101215
   //hier print now rtcs_get_data!!!!!!
 //  printf("\n\r > rtcs data : 0x%X",(unsigned long)(rtcs_result));
 //   printf("\n\r > get data : 0x%X",(unsigned long)(RTCS_get_data()));
   
//bad - if use only test mode do not hangt and mac fork without tcpip!!!! after prinf - hangt return;   
   	 
	 
 //  rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0f, 0x00000000);
//     rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0e, 0x00000000);
 rtcs_result = RTCS_if_bind(ihandle0, GetIP(), 0xFFFFFF00);   //3b
//t    rtcs_result = RTCS_if_bind1(ihandle0, GetIP(), 0x00000000);   //3b
    
//    printf("\n\r > rtcs data1 : 0x%X",(unsigned long)(rtcs_result));
   	 
    
   OldIP = GetIP();  
     
 //  Add Gateways 
 //  rtcs_result = RTCS_gate_add(0x9b9b9b01, 0x00000000, 0x00000000);
//   if (rtcs_result != RTCS_OK)
 //     {
      //     while(1);
      //     State |= 0x40l;
 ///     } 
    //    aic_ptr->ICCR = 0xff;
       
    //      _int_enable();
    
    
    
#ifdef TCPIP_CONNECT
 

#ifndef USE_TCPIP_CLIENT
#ifndef USE_QUOTE_SERVER
  buffer_rad_T_len = 0l;
  buffer_rad_T_lenU = 0l;
//100226 not need   rtcs_result = ECHOSRV_init   (taskname = "Echo server",   7, 1500);
//t  rtcs_result = RDNSRV_init   (taskname = "Radian server",   7, 1500);    //port 155

  rtcs_result = RDNSRV_init   (taskname = "Radian server",   7, BUFFER_SIZE_T); //100525 - 2000    //port 155/port 155s_result = RDNSRVT_init   (taskname = "Radian transmit",   7, 1500); //now setted my ip address 155.155.115.114
  rtcs_result = RDNSRVT_init   (taskname = "Radian transmit",   7, BUFFER_SIZE_T); //101125

#endif //USE_QUOTE_SERVER
#endif// USE_TCPIP_CLIENT



#endif //TCPIP_CONNECT  



}

#endif	 //try unblock



extern "C" void Restart_Eth3(void)
{


//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth3\n\n\n\n\n\n\n\n\n\n\n\n\\");
/*
 rtcs_result = ENET_initialize(0, enet_local0, 0x00000000, &enet_handle0); //1b
 
if (rtcs_result != ENET_OK) //?? olweis ok?
{
   Enet_is_not_init();
} 
*/
rtcs_result = RTCS_if_add(enet_handle0, RTCS_IF_ENET, &ihandle0);  //2b
 //  rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0f, 0x00000000);
//     rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0e, 0x00000000);
rtcs_result = RTCS_if_bind(ihandle0, GetIP(), 0xFFFFFF00);   //3b
OldIP = GetIP();   
//}

#ifdef TCPIP_CONNECT
  buffer_rad_T_len = (unsigned long)0l;
// rtcs_result = ECHOSRV_init   (taskname = "Echo server",   7, 1500);
// rtcs_result = RDNSRV_init   (taskname = "Radian server",   7, 1500);
 rtcs_result = RDNSRV_init   (taskname = "Radian server",   7, BUFFER_SIZE_T);
//  rtcs_result = RDNSRVT_init   (taskname = "Radian transmit",   7, 1500); //now setted my ip address 155.155.115.114
#endif //TCPIP_CONNECT  
 
#ifdef USE_SOCKETS
// Set up the UDP port (Quote server services port 17): 
laddr.sin_family = AF_INET;
//090216 laddr.sin_port = 17;
laddr.sin_port = TCP_PORT;
laddr.sin_addr.s_addr = INADDR_ANY;
sock = socket(PF_INET, SOCK_STREAM, 0);
if (sock == RTCS_SOCKET_ERROR) {
//printf("\nFailed to create the stream socket.");
_task_block();
}
// Bind the stream socket to a TCP port: 
error = bind(sock, &laddr, sizeof(laddr));
if (error != RTCS_OK) {
//printf("\nFailed to bind the stream socket - 0x%lx", error);
_task_block();
}
// Set up the stream socket to listen on the TCP port: 
error = listen(sock, 0);
if (error != RTCS_OK) {
//printf("\nlisten() failed - 0x%lx", error);
_task_block();
}
listensock = sock;
#endif // USE_SOCKETS
  
usart_command_eth_on();
}



extern "C" void Restart_Eth2(void)
{
  AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = 
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;

// printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth2\n\n\n\n\n\n\n\n\n\n\n\n\\");

//______________________________________   
  for(unsigned long cnt = 0l; cnt < 32l; cnt++){ 
     aic_ptr->EOICR = 0xFF; 
     } 
//___________________________________________
}

extern "C" void Set_enet_local0(uchar *);

extern "C" void Restart_Eth1(void)
{
//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth1\n\n\n\n\n\n\n\n\n\n\n\n\\");

AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;  

for(long cnt = 0l; cnt < 32l; cnt++){ 
     aic_ptr->EOICR = 0xFF; 
    } 
 	 Set_enet_local0((uchar*)&enet_local0[0]);
_int_enable();
  	RTCS_create(); 



//______________________________________________________________________
#ifndef USE_TCPIP_CLIENT
#ifndef USE_QUOTE_SERVER

#ifdef USE_TFTPSRV 
// rtcs_result = TFTPSRV_init("TFTP Server", 7L, 2000L);   //2a  //t 
#endif // USE_TFTPSRV
#ifdef USE_SNMP 
// rtcs_result = SNMP_init("SNMP Agent", 7L, 2000L); //3a		//not hangt but do not work
//  MIB1213_init(); //4a //my
#endif //USE_SNMP  
  
  
#endif
#endif   
/*  
//#ifndef PROG_PRM_PCH_N    
  rtcs_result = ENET_initialize(0, enet_local0, 0x00000000, &enet_handle0); //1b
  
  if (rtcs_result != ENET_OK) //?? olweis ok?
    {
      Enet_is_not_init();
    } 
    
//#endif  // PROG_PRM_PCH_N 
   rtcs_result = RTCS_if_add(enet_handle0, RTCS_IF_ENET, &ihandle0);  //2b
 //  rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0f, 0x00000000);
//     rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0e, 0x00000000);
    rtcs_result = RTCS_if_bind(ihandle0, GetIP(), 0x00000000);   //3b
   OldIP = GetIP();    
 */  
//______________________________________________________________________




 /*
#ifndef USE_TCPIP_CLIENT
#ifndef USE_QUOTE_SERVER

#ifdef USE_TFTPSRV 
 rtcs_result = TFTPSRV_init("TFTP Server", 7L, 2000L);   //2a  //t 
#endif // USE_TFTPSRV
#ifdef USE_SNMP 
 rtcs_result = SNMP_init("SNMP Agent", 7L, 2000L); //3a
  MIB1213_init(); //4a //my
#endif //USE_SNMP  
  
  
#endif
#endif 

*/  

}

//#endif //t	 

extern "C" void Check_MAC_BNA(void)
{
//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth\n\n\n\n\n\n\n\n\n\n\n\n\\");
  //	fgufxu

  AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
  emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
	if(emac_ptr->RSR & AT91RM9200_EMAC_RSR_RXBUF_NOT_AVAILABLE)
	{
	emac_ptr->CR &= ~0x00000004; 
	emac_ptr->CR |= 0x00000004;
	}
}


extern "C" void Restart_Eth(void)
{
//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\r Restart_Eth\n\n\n\n\n\n\n\n\n\n\n\n\\");

  AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
  emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
	emac_ptr->CR &= ~0x00000004; 
	emac_ptr->CR |= 0x00000004;


rtcs_result = RTCS_create();   //1a

 /*
rtcs_result = TFTPSRV_init("TFTP Server", 7L, 2000L);   //2a  //t 

rtcs_result = SNMP_init("SNMP Agent", 7L, 2000L); //3a

MIB1213_init(); //4a //my

*/
rtcs_result = ENET_initialize(0, enet_local0, 0x00000000, &enet_handle0); //1b

if (rtcs_result != ENET_OK) //?? olweis ok?
{
   Enet_is_not_init();
} 
rtcs_result = RTCS_if_add(enet_handle0, RTCS_IF_ENET, &ihandle0);  //2b
 //  rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0f, 0x00000000);
//     rtcs_result = RTCS_if_bind(ihandle0, 0x9b9b9b0e, 0x00000000);
rtcs_result = RTCS_if_bind(ihandle0, GetIP(), 0xFFFFFF00);   //3b
OldIP = GetIP();   
//}
 /*
#ifdef TCPIP_CONNECT
  buffer_rad_T_len = (unsigned long)0l;
 rtcs_result = ECHOSRV_init   (taskname = "Echo server",   7, 1500);
 rtcs_result = RDNSRV_init   (taskname = "Radian server",   7, 1500);
//  rtcs_result = RDNSRVT_init   (taskname = "Radian transmit",   7, 1500); //now setted my ip address 155.155.115.114
#endif //TCPIP_CONNECT  

#ifdef USE_SOCKETS
// Set up the UDP port (Quote server services port 17): 
laddr.sin_family = AF_INET;
//090216 laddr.sin_port = 17;
laddr.sin_port = TCP_PORT;
laddr.sin_addr.s_addr = INADDR_ANY;
sock = socket(PF_INET, SOCK_STREAM, 0);
if (sock == RTCS_SOCKET_ERROR) {
//printf("\nFailed to create the stream socket.");
_task_block();
}
// Bind the stream socket to a TCP port: 
error = bind(sock, &laddr, sizeof(laddr));
if (error != RTCS_OK) {
//printf("\nFailed to bind the stream socket - 0x%lx", error);
_task_block();
}
// Set up the stream socket to listen on the TCP port: 
error = listen(sock, 0);
if (error != RTCS_OK) {
//printf("\nlisten() failed - 0x%lx", error);
_task_block();
}
listensock = sock;
#endif // USE_SOCKETS

//usart_command_eth_on();

*/
}
 
//#endif // ETH_CAN_RESTART

#endif


extern "C" uint_32 _bsp_enet_get_speed(void);

extern "C" boolean _mii_read_reg (AT91RM9200_EMAC_REG_STRUCT_PTR, uint_32, uint_32, uint_16 _PTR_ );
extern "C" boolean _mii_write_reg (AT91RM9200_EMAC_REG_STRUCT_PTR, uint_32, uint_32, uint_16 _PTR_ );


extern uint_32 Stephany14;
extern "C" void my_int_disable_irq0(void);
extern "C" void  emb_use_irq0(void);
extern uint_32 Stephany11;
//extern unsigned int IntFlag;





//extern "C" void RDN_Init(void) 
//{
// pRDN_BufferT = RDN_BufferT;
 
// RDN_BufferR_Init();	
// pRDN_BufferR = RDN_BufferR;
//pntdst =  enetdest;
//_______________________t
/*
    enetdest[0] = 0x00;
    enetdest[1] = 0x11;
    enetdest[2] = 0x11;
    enetdest[3] = 0x00;
    enetdest[4] = 0x34;
    enetdest[5] = 0x56;
	 */
/*
	enetdest[0] = 0xff;
    enetdest[1] = 0xff;
    enetdest[2] = 0xff;
    enetdest[3] = 0xff;
    enetdest[4] = 0xff;
    enetdest[5] = 0xff;
*/
//
/*
  enetdest[0] = 0x00;
  enetdest[1] = 0x11;
  enetdest[2] = 0x11;
  enetdest[3] = 0x00;
  enetdest[4] = 0x12;
  enetdest[5] = 0x34;
 */


   /*
	for(long i= 0; i < RDN_BUFFER_SIZE; i++)
	{ RDN_BufferT[i]	 = (char)i;}   //temporary
	  RDN_BufferT[0] = 0x1;	   //len temporary
	  RDN_BufferT[1] = 0x02;
	  */
	  //len =0x102 (258 dec)
//_______________________t

//}

extern "C" unsigned char Hex2Char(char s)
{
  if((s>='0')&&(s<='9')) return s - '0';
  if((s>='a')&&(s<='f')) return s - 'a' + 10;
  if((s>='A')&&(s<='F')) return s - 'A' + 10;
	return 0;
}

#ifdef CLOCK_ENABLED

#define CLOCK_OPERATE_ADDR (0x7FF8)
#define CLOCK_SECOND_ADDR  (0x7FF9)
#define CLOCK_MINUTES_ADDR (0x7FFA)
#define CLOCK_HOURS_ADDR   (0x7FFB)
#define CLOCK_DAY_ADDR     (0x7FFC)
#define CLOCK_DATE_ADDR    (0x7FFD)
#define CLOCK_MONTH_ADDR   (0x7FFE)
#define CLOCK_YEAR_ADDR    (0x7FFF)

#define CLOCK_STOP_BIT  (0x80)
#define CLOCK_READ_BIT  (0x40)
#define CLOCK_WRITE_BIT (0x80)
#define CLOCK_TEST_BIT  (0x40)


#define	LOW_HALF_MASK  (0x0f)
#define	HIGH_HALF_MASK (0xf0)
#define	HIGH_SEC_MASK (0x70)


extern "C" void ClearTestBit(void)
{
 unsigned char rd = read_nvram_char(CLOCK_DAY_ADDR);
 rd &= ~(CLOCK_TEST_BIT); //set to zero
 write_nvram_char(CLOCK_DAY_ADDR, rd);
}


extern "C" void ClockStartUpdate(void)
{
 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);
 rd &= ~(CLOCK_READ_BIT); //set to zero
 write_nvram_char(CLOCK_OPERATE_ADDR, rd);
}

extern "C" void ClockStopUpdate(void)
{
 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);
 rd |= (unsigned char)(CLOCK_READ_BIT); //set to one
 write_nvram_char(CLOCK_OPERATE_ADDR, rd);
}

extern "C" void ClockStartWrite(void)
{
 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);
 rd |= (unsigned char)(CLOCK_WRITE_BIT); //set to one
 write_nvram_char(CLOCK_OPERATE_ADDR, rd);
}

extern "C" void ClockStopWrite(void)
{
 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);   
 rd &= ~(CLOCK_WRITE_BIT); //set to zero
 write_nvram_char(CLOCK_OPERATE_ADDR, rd);
}



extern "C" void ClockStart(void)
{
//printfp("\n\r ClockStart");
 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);
 rd &= ~(CLOCK_STOP_BIT); //set to zero
 write_nvram_char(CLOCK_SECOND_ADDR, rd);
 ClearTestBit();
 ClockStopWrite();	//wr bit to zero
 ClockStartUpdate();  //rd bit to zero

#ifdef YOURNAL
  Init_Yournal();  //temporary ?
#endif
}

extern "C" void ClockStop(void)
{
//printfp("\n\r ClockStop");

 unsigned char rd = read_nvram_char(CLOCK_OPERATE_ADDR);
 rd |= (unsigned char)(CLOCK_STOP_BIT); //set to zero
 write_nvram_char(CLOCK_OPERATE_ADDR, rd);
}
//_________________________________________________sec
extern "C" unsigned char ClockReadSec(void)
{
//printfp("\n\r ClockReadSec");

   unsigned char secl, sech, sec;
   ClockStopUpdate();
   sec = read_nvram_char(CLOCK_SECOND_ADDR);
   ClockStartUpdate();
   secl = sec & LOW_HALF_MASK;
   sech = ((sec & HIGH_SEC_MASK) >> 4) * 10;
   return(secl + sech);
}

extern "C" void ClockWriteSec(unsigned char sec)
{
//printfp("\n\r ClockWriteSec"); 
  unsigned char secl, sech;
   ClockStartWrite();
   secl = sec % 10;
   sech = sec / 10;
   sec = (sech << 4) + secl;
 //  printf(" Set : %d ", sec);
   write_nvram_char(CLOCK_SECOND_ADDR, sec);
   ClockStopWrite();
}

#ifdef PROG_BACO	

extern "C" unsigned long ClockReadmSec(void)
{
//printfp("\n\r ClockReadSec");
  unsigned long msec = glob_cnt;
  return msec;
}


#endif


//__________________________________________________sec

//_________________________________________________min
extern "C" unsigned char ClockReadMin(void)
{
   unsigned char dl, dh, d;
   ClockStopUpdate();
   d = read_nvram_char(CLOCK_MINUTES_ADDR);
   ClockStartUpdate();
   dl = d & LOW_HALF_MASK;
   dh = ((d & HIGH_HALF_MASK) >> 4) * 10;
   return(dl + dh);
}

extern "C" void ClockWriteMin(unsigned char d)
{
   unsigned char dl, dh;
   ClockStartWrite();
   dl = d % 10;
   dh = d / 10;
   d = (dh << 4) + dl;
 //  printf(" Set : %d ", sec);
   write_nvram_char(CLOCK_MINUTES_ADDR, d);
   ClockStopWrite();
}

//__________________________________________________min

//_________________________________________________Hours
extern "C" unsigned char ClockReadHours(void)
{
   unsigned char dl, dh, d;
   ClockStopUpdate();
   d = read_nvram_char(CLOCK_HOURS_ADDR);
//    printfpd("\n\rread keep hour : 0x%X ",  d);
   ClockStartUpdate();
   dl = d & LOW_HALF_MASK;
   dh = ((d & HIGH_HALF_MASK) >> 4) * 10;
   return(dl + dh);
}

extern "C" void ClockWriteHours(unsigned char d)
{
   unsigned char dl, dh;
   ClockStartWrite();
   dl = d % 10;
   dh = d / 10;
   d = (dh << 4) + dl;
 //  printf(" Set : %d ", sec);
//   printfpd("\n\rtry keep hour : 0x%X ",  d);
   write_nvram_char(CLOCK_HOURS_ADDR, d);
 //  printfpd("read after keep hour : 0x%X ",  read_nvram_char(CLOCK_HOURS_ADDR));
   ClockStopWrite();
}

//__________________________________________________Hours


//_________________________________________________Date
extern "C" unsigned char ClockReadDate(void)
{
   unsigned char dl, dh, d;
   ClockStopUpdate();
   d = read_nvram_char(CLOCK_DATE_ADDR);
   ClockStartUpdate();
   dl = d & LOW_HALF_MASK;
   dh = ((d & HIGH_HALF_MASK) >> 4) * 10;
   return(dl + dh);
}

extern "C" void ClockWriteDate(unsigned char d)
{
   unsigned char dl, dh;
   ClockStartWrite();
   dl = d % 10;
   dh = d / 10;
   d = (dh << 4) + dl;
 //  printf(" Set : %d ", sec);
   write_nvram_char(CLOCK_DATE_ADDR, d);
   ClockStopWrite();
}

//__________________________________________________Date

//_________________________________________________Month
extern "C" unsigned char ClockReadMonth(void)
{
   unsigned char dl, dh, d;
   ClockStopUpdate();
   d = read_nvram_char(CLOCK_MONTH_ADDR);
   ClockStartUpdate();
   dl = d & LOW_HALF_MASK;
   dh = ((d & HIGH_HALF_MASK) >> 4) * 10;
   return(dl + dh);
}

extern "C" void ClockWriteMonth(unsigned char d)
{
   unsigned char dl, dh;
   ClockStartWrite();
   dl = d % 10;
   dh = d / 10;
   d = (dh << 4) + dl;
 //  printf(" Set : %d ", sec);
   write_nvram_char(CLOCK_MONTH_ADDR, d);
   ClockStopWrite();
}

//__________________________________________________Month

//_________________________________________________Year
extern "C" unsigned char ClockReadYear(void)
{
   unsigned char dl, dh, d;
   ClockStopUpdate();
   d = read_nvram_char(CLOCK_YEAR_ADDR);
  // printfpd("\n\rread keep year : 0x%X ",  d);
   ClockStartUpdate();
   dl = d & LOW_HALF_MASK;
   dh = ((d & HIGH_HALF_MASK) >> 4) * 10;
   return(dl + dh);
}

extern "C" void ClockWriteYear(unsigned char d)
{
   unsigned char dl, dh;
   ClockStartWrite();
   dl = d % 10;
   dh = d / 10;
   d = (dh << 4) + dl;
 //  printf(" Set : %d ", sec);
 // printfpd("\n\rtry keep year : 0x%X ",  d);

   write_nvram_char(CLOCK_YEAR_ADDR, d);
  // printfpd("read after keep year : 0x%X ",  read_nvram_char(CLOCK_YEAR_ADDR));

   ClockStopWrite();
}

//__________________________________________________Year




extern "C" void UpdateClock(void)
{
if(UsedMenu.MenuState.DataC0Changing) return;	  //121008
if(UsedMenu.MenuState.DataC1Changing) return;	  //121008
if(UsedMenu.MenuState.DataC2Changing) return;	  //121008
if(UsedMenu.MenuState.DataC3Changing) return;	  //121008

   TimeData1.Value = (float64)ClockReadSec();
   TimeData1.ChangingValue =	TimeData1.Value;

   TimeData2.Value = (float64)ClockReadMin();
   TimeData2.ChangingValue =	TimeData2.Value;

   TimeData3.Value = (float64)ClockReadHours();
   TimeData3.ChangingValue =	TimeData3.Value;

	TimeData4.Value = (float64)ClockReadDate();
    TimeData4.ChangingValue = TimeData4.Value;

	TimeData5.Value = (float64)ClockReadMonth();
	 TimeData5.ChangingValue = TimeData5.Value;

	TimeData6.Value = (float64)ClockReadYear();
	 TimeData6.ChangingValue = TimeData6.Value;

//	printf(" %d",(unsigned char)TimeData1.Value);

//printfpd("\n\r clk:%d", (unsigned long)TimeData1.Value);
//printfpd(" d:%d", (unsigned long)TimeData4.Value);
//printfpd(" m:%d", (unsigned long)TimeData5.Value);
//printfpd(" y:%d", (unsigned long)TimeData6.Value);

}



#endif // CLOCK_ENABLED




#ifdef YOURNAL


extern "C" void ClearYournal()
{

#ifdef DEB_LOG

printfp("\n\r Clear Yournal");
#endif


 for(unsigned long addr = YOURNAL_HEADER_ADDRESS; addr	<= YOURNAL_LAST_ADDRESS; addr++)
  {
	write_nvram_char(addr, 0);
  }

sprintf(LogStr0.Value, "%s","   Yournal Is Cleared   ");  
sprintf(LogStr1.Value, "%s","                        ");  
yournal_init = 1; //to have zero start number

}

extern "C" void GetRecord()
{
unsigned long addr;
char * stopstring;
unsigned char cht;

 addr = strtol(CRecord.Value, &stopstring,16);

//#ifdef PRINT_YOURNAL
//   printfpd("\n\r addr : 0x%lX", addr);
//#endif
 //printf("\n\r addr : 0x%lX", addr);
// printEthLongHex(addr);
 //CRecord.Value[0] = '5';
 if(addr < NVRAM_SIZE)
 {
   // CRecord.Value[0]  = '5';
 for(long i = 0; i < RECORD_SIZE; i++)
 {
   cht =  read_nvram_char(addr++);
 //  if(!cht) cht = 1;
   CRecord.Value[i] = cht;
 //   CRecord.Value[i]  = '8';
  //  CRecord.Value[i]  = 0;
 }
 }
 else
 {
   CRecord.Value[0] = 0x99;
 }
  CRecord.Value[RECORD_SIZE] ='\0';
}

extern "C" unsigned long GetRecAddr(unsigned long number)
{
unsigned long last;
//char * stopstring;
//unsigned long number;

last = 0l;
last += read_nvram_char(YOURNAL_HEADER_ADDRESS);
last <<= 8;
last += read_nvram_char(YOURNAL_HEADER_ADDRESS + 1);
last <<= 8;
last += read_nvram_char(YOURNAL_HEADER_ADDRESS + 2);
last <<= 8;
last += read_nvram_char(YOURNAL_HEADER_ADDRESS + 3);
 /*
number =  strtol(CRecord.Value, &stopstring,16);

if(number > (RECORDS_MAX_QUANTITY - 1)) number = 0; 
   */

	 for(unsigned long i = 0; i	< number; i++)
  {
    last -= RECORD_SIZE ;
 	if(last < YOURNAL_START_ADDRESS)
	{
	  last = YOURNAL_START_ADDRESS + ((RECORDS_MAX_QUANTITY - 1) * RECORD_SIZE);
	}
  }


return last;
}

extern "C" void GetRecord1(unsigned long num)
{
unsigned long addr;
//char * stopstring;
unsigned char cht;
unsigned long i;
//unsigned long num;
 

//num =  strtol(CRecord.Value, &stopstring,16);

if(num <= (RECORDS_MAX_QUANTITY - 1))  
 {
 addr = GetRecAddr(num);
// printfpd("\n\r rec addr : 0x%lX \n\r>", addr);
// printEthLongHex(addr);
 //CRecord.Value[0] = '5';
#ifdef PRINT_YOURNAL
 //  printfpd("\n\r addr : 0x%lX", addr);
	 printEthLongHex(addr);
#endif

 
 if(addr < NVRAM_SIZE)
 {
   // CRecord.Value[0]  = '5';
 		for(i = 0; i < RECORD_SIZE; i++)
 		{
   			cht =  read_nvram_char(addr++);
//12   if(!cht) cht = ' ';	 //for test
 //		printfpd(" %c", cht);
   			CRecord.Value[i] = cht;
 //   CRecord.Value[i]  = '8';
  //  CRecord.Value[i]  = 0;
 		}
 }
 else
 {
  for( i = 0; i < RECORD_SIZE; i++)
 		{
   			CRecord.Value[i] = 0;
 		}
 }
 

 }
 else
 {

for( i = 0; i < RECORD_SIZE; i++)
 		{
   			CRecord.Value[i] = 0;
 		}
 }

 


  CRecord.Value[RECORD_SIZE] ='\0';
}


struct RECORD
{
 unsigned char ev_type1;
 unsigned char ev_type2;
 unsigned char sec;
 unsigned char min;
 unsigned char hour;
 unsigned char day;
 unsigned char month;
 unsigned char year;
};


struct RECORD1
{
 unsigned short id;
 unsigned long time_t;
 unsigned char type;
 unsigned char body[59];
};

extern "C" unsigned long GetEventAddr()
{
 unsigned long rec_addr;
 unsigned char tmp;
 rec_addr = 0l;
 tmp = read_nvram_char(YOURNAL_HEADER_ADDRESS);
 rec_addr += (unsigned long)(tmp);
 rec_addr <<= 8;
 tmp = read_nvram_char(YOURNAL_HEADER_ADDRESS + 1);
 rec_addr += (unsigned long)(tmp);
 rec_addr <<= 8;
 tmp = read_nvram_char(YOURNAL_HEADER_ADDRESS + 2);
 rec_addr += (unsigned long)(tmp);
 rec_addr <<= 8;
 tmp = read_nvram_char(YOURNAL_HEADER_ADDRESS + 3);
 rec_addr += (unsigned long)(tmp);

 if(rec_addr > (unsigned long)YOURNAL_LAST_ADDRESS)
 {
   rec_addr =  (unsigned long)YOURNAL_START_ADDRESS;
 }

 if(rec_addr < (unsigned long)YOURNAL_START_ADDRESS)
 {
   rec_addr =  (unsigned long)YOURNAL_START_ADDRESS;
 }
  
if( (rec_addr - (unsigned long)YOURNAL_START_ADDRESS) % (unsigned long)RECORD_SIZE)
{
    rec_addr =  (unsigned long)YOURNAL_START_ADDRESS;
}
  
 return (rec_addr);
}


extern "C" unsigned short GetEvId(unsigned long ev_addr)
{
unsigned short id;
unsigned long prev_ev_addr;
 prev_ev_addr = GetPrevionsEvAddr(ev_addr);

 if(yournal_init)
 {
 yournal_init = 0;
 id = 0;
 write_nvram_char(prev_ev_addr, 0xFF);
 write_nvram_char(prev_ev_addr + 1, 0xFF);
 }
 else
 {
 // prev_ev_addr = GetPrevionsEvAddr(ev_addr);
  id = read_nvram_char(prev_ev_addr);
  id <<= 8;
  id += read_nvram_char(prev_ev_addr + 1) + 1;
//id = 0;	 //need read nvram; + need make init
// printf("\n\r %lX : %d",ev_addr, id );
 }
return id;
}


DATE_STRUCT date;
TIME_STRUCT time;





extern "C" void WriteEvent(unsigned short event, unsigned long ev_addr, unsigned char data_size, char * data_values)
{
unsigned short ev_id;
unsigned char crc = 0;
//unsigned char ev_number;


 ev_id = GetEvId(ev_addr); //temporary

 //RECORD Record;
 //Record.ev_type1 = (unsigned char)(event >> 8);
 //Record.ev_type2 = (unsigned char)(event);
 //Record.sec =  ClockReadSec();
//_________________________________________________________
//DATE_STRUCT date;
//TIME_STRUCT time;

/*
date.YEAR = 1999;
date.MONTH = 2;
date.DAY = 8;
date.HOUR = 10;
date.SECOND = 0;
date.MILLISEC = 0;
*/

date.YEAR   = ClockReadYear() + 2000;
date.MONTH  = ClockReadMonth();
date.DAY    = ClockReadDate();
date.HOUR   = ClockReadHours();
date.MINUTE = ClockReadMin();
date.SECOND = ClockReadSec();
date.MILLISEC = 0;

 /*
date.YEAR =  2000;
date.MONTH =  1;
date.DAY = 1;
date.HOUR = 1;
date.SECOND = 22; //ClockReadSec();
date.MILLISEC = 0;
  */

//if (
_time_from_date(&date, &time);
//)
//The time is since 0:00:00.00, January 1, 1970.
//_time_to_date( &time,&date );
//_________________________________________________________
//1 byte - number
//4 byte - time
//1 byte - type
//(64 - 6 = 58) : rezerved 



 /*
 write_nvram_char(ev_addr++, (unsigned char)(event >> 8));
 write_nvram_char(ev_addr++, (unsigned char)(event));
 write_nvram_char(ev_addr++, ClockReadSec());
 write_nvram_char(ev_addr++, ClockReadMin());
 write_nvram_char(ev_addr++, ClockReadHours());
 write_nvram_char(ev_addr++, ClockReadDate());
 write_nvram_char(ev_addr++, ClockReadMonth());
 write_nvram_char(ev_addr++, ClockReadYear());
 */

//printf("\n\r>%d :  %ld",date.SECOND, time.SECONDS);
//else
//printf("\n\r error!");
 /*
printfpd("\n\r>%d ",time.SECONDS);
printfpd("e : %d ",ev_id);
 */

write_nvram_char(ev_addr++, (unsigned char)(ev_id >> 8));
crc+= (unsigned char)(ev_id >> 8);
write_nvram_char(ev_addr++, (unsigned char)(ev_id));
crc+= (unsigned char)(ev_id);

//write_nvram_char(ev_addr++, (unsigned char)(event));
write_nvram_char(ev_addr++, (unsigned char)(time.SECONDS >> 24 ));
crc+= (unsigned char)(time.SECONDS >> 24 );

write_nvram_char(ev_addr++, (unsigned char)(time.SECONDS >> 16 ));
crc+= (unsigned char)(time.SECONDS >> 16 );
write_nvram_char(ev_addr++, (unsigned char)(time.SECONDS >> 8 ));
crc+= (unsigned char)(time.SECONDS >> 8 );
write_nvram_char(ev_addr++, (unsigned char)(time.SECONDS  ));
crc+= (unsigned char)(time.SECONDS);
write_nvram_char(ev_addr++, (unsigned char)(event));
crc+= (unsigned char)(event);


if(data_size > ENABLED_DATA_SIZE)
{
 data_size = ENABLED_DATA_SIZE;
}

 write_nvram_char(ev_addr++, (unsigned char)(data_size));
// if(data_size)
 crc+= (unsigned char)(data_size);
// else
//  crc+= ' ';   //0 replaced to ' '

 //printfp("\n\rw :");
for (long i = 0; i < data_size; i++)
{
//can correct use only symbol values!!!!!!!!!!!!!!!!!!!

 write_nvram_char(ev_addr++, (unsigned char)(*data_values));
 crc+= (unsigned char)(*data_values);

 //  printfpd("( %02X)", crc);

 data_values++;
}
//______________________________________________________add zeros


for (i = data_size; i < ENABLED_DATA_SIZE; i++)
{
 write_nvram_char(ev_addr++, (unsigned char)(' '));
 crc+=' ';
}
//______________________________________________________
 //  printfpd("\n\rcrc+1  %d:", (crc + 1));

  write_nvram_char(ev_addr, (unsigned char)(crc + 1));
}


extern "C" unsigned char CheckEventCRC(unsigned char * pEvent)
{
unsigned char ret = 0;
unsigned char crc = 0;
// printfp("\n\r");
 for (long i = 0; i < (RECORD_SIZE-1); i++)
{
// printfpd(" %02X", *pEvent);
 crc+= (unsigned char)(*pEvent++);
// printfpd("( %02X)", crc);
}
 crc+=1;
//  printfpd("\n\r %02X", crc);
 // printfpd("- %02X", *pEvent);

 if(crc == *pEvent)
 {
  ret = 1;
 }
 return ret;
}



extern "C" void UpdateEvAddr(unsigned long next_ev_addr)
{
//printfp("\n\r UpdateEvAddr");
 next_ev_addr += (unsigned long)RECORD_SIZE;
 //if(next_ev_addr > (unsigned long)YOURNAL_END_ADDRESS)
 if(next_ev_addr > (unsigned long)YOURNAL_LAST_ADDRESS)
 {
   next_ev_addr =  (unsigned long)YOURNAL_START_ADDRESS;
 }
 write_nvram_char((unsigned long)YOURNAL_HEADER_ADDRESS, (unsigned char)(next_ev_addr >> 24));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 1), (unsigned char)(next_ev_addr >> 16));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 2), (unsigned char)(next_ev_addr >> 8));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 3), (unsigned char)(next_ev_addr));
}





extern "C" unsigned long GetPrevionsEvAddr(unsigned long ev_addr)
{
unsigned long prev_ev_addr;

 prev_ev_addr = ev_addr - (unsigned long)RECORD_SIZE;

 //if(next_ev_addr > (unsigned long)YOURNAL_END_ADDRESS)
 if(prev_ev_addr < (unsigned long)YOURNAL_START_ADDRESS)
 {
   prev_ev_addr =  (unsigned long)YOURNAL_LAST_ADDRESS;
 }
 return  prev_ev_addr;
}






 /*
extern "C" unsigned long SetBackEvAddr(unsigned long next_ev_addr)
{
 next_ev_addr -= (unsigned long)RECORD_SIZE;
 if(next_ev_addr < (unsigned long)YOURNAL_START_ADDRESS)
 {
   next_ev_addr =  YOURNAL_START_ADDRESS + ((RECORDS_MAX_QUANTITY - 1) * RECORD_SIZE);
 }
 write_nvram_char((unsigned long)YOURNAL_HEADER_ADDRESS, (unsigned char)(next_ev_addr >> 24));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 1), (unsigned char)(next_ev_addr >> 16));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 2), (unsigned char)(next_ev_addr >> 8));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 3), (unsigned char)(next_ev_addr));
 return	  next_ev_addr;
}
  */

extern "C" unsigned char EventToMenu1();

extern "C" void Add_Event(unsigned short event, unsigned char data_size, char * data_values)
{
//1 power on
//2 power off
 unsigned long ev_addr;	 
// unsigned long ev_addr1;

//oldflag_alarms = 2; //clear stored alarms 

 ev_addr = GetEventAddr();



//printfp("\n\r Add event  ev :");
//printfpd(" %X", event);
//printfp("  ev_addr: ");
//printfpd(" %X", ev_addr);


 

//if((event == 1l) || (event == 8l))// to not delete previons writing last power off
if(event == 1l)// to not delete previons writing last power off
 {
 	UpdateEvAddr(ev_addr); // //if > max - make loop!

//printfp("\n\rUpdate1");
 //	UpdateEvAddr(ev_addr);
  ev_addr = GetEventAddr();
 }




//  ev_addr = GetEventAddr();
  /*
 if(prev_event == 2l) //
 {
  ev_addr =	SetBackEvAddr(ev_addr1); //if > max - make loop!
 }
 else
 {
  ev_addr = ev_addr1;
 }
  */

 WriteEvent((unsigned short)event, (unsigned long)ev_addr, (unsigned char)data_size, data_values);
 //printf("\n\r %ld -> %lX", event, ev_addr);

//EventToMenu1(); //init strings to can view it if go to log


if(event != 2l) //
 {
 	UpdateEvAddr(ev_addr); //if > max - make loop!

//printfp("\n\rUpdate2");

 }
 prev_event = event;
}

extern "C" void Init_Yournal(void)
{
 unsigned long next_ev_addr;
 next_ev_addr =  (unsigned long)YOURNAL_START_ADDRESS;
 yournal_init = 1;
 //return;

 write_nvram_char((unsigned long)YOURNAL_HEADER_ADDRESS, (unsigned char)(next_ev_addr >> 24));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 1), (unsigned char)(next_ev_addr >> 16));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 2), (unsigned char)(next_ev_addr >> 8));
 write_nvram_char((unsigned long)(YOURNAL_HEADER_ADDRESS + 3), (unsigned char)(next_ev_addr));
//  return;
 for(unsigned long i = (YOURNAL_START_ADDRESS ); i <=  (YOURNAL_END_ADDRESS); i++)
 {
 	write_nvram_char(i, 0);
 }
}






#endif //  YOURNAL



#ifdef KTVM_PROT2
extern "C" unsigned long GetRemoteMode(void)
{
 	return (unsigned long)RemoteMode.Value;
}


extern "C" void SetProtokol(unsigned char c)
{
	unsigned long tmp =  RemoteMode.Value;
	if(c)
	{
	tmp |= 1l;
	EmbSetProt(1);
	}
	else
	{
	tmp &= 0xFFFFFFFEl;
	EmbSetProt(0);
	}
	RemoteMode.Value = tmp;
	RemoteMode.ChangingValue = tmp;
}

#endif //KTVM_PROT2




#ifdef PROG_BMD35

extern "C" unsigned long GetRemoteMode(void)
{
 	return (unsigned long)RemoteMode.Value;
}

extern "C" void SetProtokol(unsigned char c)
{
	unsigned long tmp =  RemoteMode.Value;
	if(c)
	{
	tmp |= 1l;
	EmbSetProt(1);
	outportb(4,1);
	}
	else
	{
	tmp &= 0xFFFFFFFEl;
	EmbSetProt(0);
	outportb(4,0);

	}
	RemoteMode.Value = tmp;
	RemoteMode.ChangingValue = tmp;
}



 extern "C" void ReadDPD(char * addr)
{
  read_dataflash ((unsigned int)DPD_ADDRESS,(unsigned int)DPD_SIZE, (char *)(addr));
}
#endif //PROG_BMD35

#ifdef PROG_PROV

extern "C" unsigned long GetRemoteMode(void)
{
 	return (unsigned long)RemoteMode.Value;
}

extern "C" void SetProtokol(unsigned char c)
{
	unsigned long tmp =  RemoteMode.Value;
	if(c)
	{
	tmp |= 1l;
	EmbSetProt(1);
	}
	else
	{
	tmp &= 0xFFFFFFFEl;
	EmbSetProt(0);
	}
	RemoteMode.Value = tmp;
	RemoteMode.ChangingValue = tmp;
}



 extern "C" void ReadDPD(char * addr)
{
  read_dataflash ((unsigned int)DPD_ADDRESS,(unsigned int)DPD_SIZE, (char *)(addr));
}
#endif //PROG_PROV



#ifdef PROG_MPC35

extern "C" unsigned long GetRemoteMode(void)
{
 	return (unsigned long)RemoteMode.Value;
}

extern "C" void SetProtokol(unsigned char c)
{
	unsigned long tmp =  RemoteMode.Value;
	if(c)
	{
	tmp |= 1l;
	EmbSetProt(1);
	}
	else
	{
	tmp &= 0xFFFFFFFEl;
	EmbSetProt(0);
	}
	RemoteMode.Value = tmp;
	RemoteMode.ChangingValue = tmp;
}



 extern "C" void ReadDPD(char * addr)
{
  read_dataflash ((unsigned int)DPD_ADDRESS,(unsigned int)DPD_SIZE, (char *)(addr));
}
#endif //PROG_MPC35




#ifdef PROGRAMM_PULT
//#define PULT_PROG_ADDRESS (0xC0400000)
//#define PULT_PROG_ADDRESS (0xC00A2000)
#define PULT_PROG_ADDRESS  (0xC0200000)
#define PULT_PROG_LENGTH   (0x3000)
//#define PULT_PROG_LENGTH   (0x500)
#define SERIAL_PROG_ENABLE (0xAC530000)
#define PULT_CHIP_ERASE    (0xAC800000)
#define WRITE_PULT_FLASH_COMMAND (0x40)
#define READ_PULT_FLASH_COMMAND (0x20)





#ifdef PROG_KTVM
 extern "C" void ReadDPD(char * addr)
{
  read_dataflash ((unsigned int)DPD_ADDRESS,(unsigned int)DPD_SIZE, (char *)(addr));
}


extern "C" void SetRate(unsigned char val)
{
//printf("Set Rate : 0x%X", val);

 if(RateData.pControl->Control(RateData.CntNum, val))
			 {
			 RateData.ChangingValue =  val;
			 RateData.Value =  val;
			 RateData.WriteStorageV(RateData.StorageAddr, &RateData.Value);
   		   //	 RateData.pControl->Operate(RateData.OprNum);
		   	 }
}

extern "C" unsigned char GetRate(void)
{
  return (unsigned char)RateData.Value; 
}
//_________________________________
extern "C" void SetVideo(unsigned char val)
{
 if(VideoData.pControl->Control(VideoData.CntNum, val))
			 {
			 VideoData.ChangingValue =  val;
			 VideoData.Value =  val;
			 VideoData.WriteStorageV(VideoData.StorageAddr, &VideoData.Value);
   		//t090604   	 VideoData.pControl->Operate(VideoData.OprNum);
		  // 	 UsedExp.State.Reg2.bit.InitCS24 = 1;
		  //	 UsedExp.State.Reg2.bit.Some = 1;
		   	 }

 LoadCoder(val);


}

extern "C" unsigned char GetVideo(void)
{
  return (unsigned char)VideoData.Value; 
}
//__________________________________

extern "C" void SetTestSignal1(unsigned char val)
{
 if(TestSignalData.pControl->Control(TestSignalData.CntNum, val))
			 {
			 TestSignalData.ChangingValue =  val;
			 TestSignalData.Value =  val;
			 TestSignalData.WriteStorageV(TestSignalData.StorageAddr, &TestSignalData.Value);
   		   //t090608	 TestSignalData.pControl->Operate(VideoData.OprNum);
		   //	 UsedExp.State.Reg2.bit.InitCS24 = 1;
		   //	 UsedExp.State.Reg2.bit.Some = 1;
		   	 }
}

extern "C" unsigned char GetTestSignal(void)
{
  return (unsigned char)TestSignalData.Value; 
}
//__________________________________

extern "C" void SetSound1(unsigned char val)
{
 if(SoundData.pControl->Control(SoundData.CntNum, val))
			 {
			 SoundData.ChangingValue =  val;
			 SoundData.Value =  val;
			 SoundData.WriteStorageV(SoundData.StorageAddr, &SoundData.Value);
   		  // 	 SoundData.pControl->Operate(SoundData.OprNum);
		   	 }
}

extern "C" unsigned char GetSound(void)
{
  return (unsigned char)SoundData.Value; 
}
//__________________________________
extern "C" void SetState1(unsigned long val)
{
 if(StateData.pControl->Control(StateData.CntNum, val))
			 {
			 StateData.ChangingValue =  val;
			 StateData.Value =  val;
			 StateData.WriteStorageC(StateData.StorageAddr, StateData.Value);
   	   //	   	 StateData.pControl->Operate(StateData.OprNum);
		   	 }
}

extern "C" unsigned char GetState(void)
{
  return (unsigned char)StateData.Value; 
}
//__________________________________
extern "C" void SetPoint1(unsigned long val)
{
 if(PointData.pControl->Control(PointData.CntNum, val))
			 {
			 PointData.ChangingValue =  val;
			 PointData.Value =  val;
			 PointData.WriteStorageC(PointData.StorageAddr, PointData.Value);
   	  //	   	 PointData.pControl->Operate(PointData.OprNum);
		   	 }
}

extern "C" unsigned char GetPoint(void)
{
  return (unsigned char)PointData.Value; 
}

extern "C" void SetPoint1O(unsigned char* data_ptr, unsigned long* data_len)
{
 unsigned long val;
 unsigned long length;
 length = *data_len;
 val = 0l;
 while(length--)
 {
   val <<= 8;	
   val += *data_ptr++;
 }

 if(PointData.pControl->Control(PointData.CntNum, val))
			 {
			 PointData.ChangingValue =  val;
			 PointData.Value =  val;
			 PointData.WriteStorageC(PointData.StorageAddr, PointData.Value);
   		//   	 PointData.pControl->Operate(PointData.OprNum);
		   	 }
}

extern "C" unsigned char * GetPointO(unsigned long* data_len)
{
  *data_len = 1;
  static unsigned char ret;
  ret =  (unsigned char)PointData.Value;
  return &ret; 
}




/*
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
*/





//__________________________________
extern "C" void SetAddr1(unsigned long val)
{
 if(AddrData.pControl->Control(AddrData.CntNum, val))
			 {
			 AddrData.ChangingValue =  val;
			 AddrData.Value =  val;
			 AddrData.WriteStorageC(AddrData.StorageAddr, AddrData.Value);
   		 //  	 AddrData.pControl->Operate(AddrData.OprNum);
		   	 }
}

extern "C" void SetAddr1O(unsigned char* data_ptr, unsigned long* data_len)

{
 unsigned long val;
 unsigned long length;
 length = *data_len;
 val = 0l;
 while(length--)
 {
   val <<= 8;	
   val += *data_ptr++;
 }

 if(AddrData.pControl->Control(AddrData.CntNum, val))
			 {
			 AddrData.ChangingValue =  val;
			 AddrData.Value =  val;
			 AddrData.WriteStorageC(AddrData.StorageAddr, AddrData.Value);
   		  // 	 AddrData.pControl->Operate(AddrData.OprNum);
		   	 }
}



extern "C" unsigned char GetAddr(void)
{
  return (unsigned char)AddrData.Value; 
}

extern "C" unsigned char * GetAddrO(unsigned long* data_len)
{
  *data_len = 1;
  static unsigned char ret;
  ret =  (unsigned char)AddrData.Value;
  return &ret; 
}


//__________________________________

#endif //PROG_KTVM

#ifdef PROG_DTVM

extern "C" unsigned char * GetAddrO(unsigned long* data_len)
{
  *data_len = 1;
  static unsigned char ret;
  ret =  (unsigned char)AddrData.Value;
  return &ret; 
}


extern "C" void SetAddr1O(unsigned char* data_ptr, unsigned long* data_len)

{
 unsigned long val;
 unsigned long length;
 length = *data_len;
 val = 0l;
 while(length--)
 {
   val <<= 8;	
   val += *data_ptr++;
 }

 if(AddrData.pControl->Control(AddrData.CntNum, val))
			 {
			 AddrData.ChangingValue =  val;
			 AddrData.Value =  val;
			 AddrData.WriteStorageC(AddrData.StorageAddr, AddrData.Value);
   		//   	 AddrData.pControl->Operate(AddrData.OprNum);
		   	 }
}


extern "C" unsigned char * GetPointO(unsigned long* data_len)
{
  *data_len = 1;
  static unsigned char ret;
  ret =  (unsigned char)PointData.Value;
  return &ret; 
}

extern "C" void SetPoint1O(unsigned char* data_ptr, unsigned long* data_len)
{
 unsigned long val;
 unsigned long length;
 length = *data_len;
 val = 0l;
 while(length--)
 {
   val <<= 8;	
   val += *data_ptr++;
 }

 if(PointData.pControl->Control(PointData.CntNum, val))
			 {
			 PointData.ChangingValue =  val;
			 PointData.Value =  val;
			 PointData.WriteStorageC(PointData.StorageAddr, PointData.Value);
   		   //	 PointData.pControl->Operate(PointData.OprNum);
		   	 }
}




 extern "C" void ReadDPD(char * addr)
{
  read_dataflash ((unsigned int)DPD_ADDRESS,(unsigned int)DPD_SIZE, (char *)(addr));
}

extern "C" void SetRate(unsigned char val)
{
 if(RateData.pControl->Control(RateData.CntNum, val))
			 {
			 RateData.ChangingValue =  val;
			 RateData.Value =  val;
			 RateData.WriteStorageV(RateData.StorageAddr, &RateData.Value);
   		 //	 RateData.pControl->Operate(RateData.OprNum);
		   	 }
}

extern "C" unsigned char GetRate(void)
{
  return (unsigned char)RateData.Value; 
}
//_________________________________
extern "C" void SetVideo(unsigned char val)
{
 if(VideoData.pControl->Control(VideoData.CntNum, val))
			 {
			 VideoData.ChangingValue =  val;
			 VideoData.Value =  val;
			 VideoData.WriteStorageV(VideoData.StorageAddr, &VideoData.Value);
   		   //	 VideoData.pControl->Operate(VideoData.OprNum);
		   //	 UsedExp.State.Reg2.bit.InitCS24 = 1;
		   //	 UsedExp.State.Reg2.bit.Some = 1;
		   	 }
}

extern "C" unsigned char GetVideo(void)
{
  return (unsigned char)VideoData.Value; 
}
//__________________________________

extern "C" void SetTestSignal1(unsigned char val)
{
 if(TestSignalData.pControl->Control(TestSignalData.CntNum, val))
			 {
			 TestSignalData.ChangingValue =  val;
			 TestSignalData.Value =  val;
			 TestSignalData.WriteStorageV(TestSignalData.StorageAddr, &TestSignalData.Value);
   		   //	 VideoData.pControl->Operate(VideoData.OprNum);
		   //	 UsedExp.State.Reg2.bit.InitCS24 = 1;
		   //	 UsedExp.State.Reg2.bit.Some = 1;
		   	 }
}

extern "C" unsigned char GetTestSignal(void)
{
  return (unsigned char)TestSignalData.Value; 
}
//__________________________________

extern "C" void SetSound1(unsigned char val)
{
 if(SoundData.pControl->Control(SoundData.CntNum, val))
			 {
			 SoundData.ChangingValue =  val;
			 SoundData.Value =  val;
			 SoundData.WriteStorageV(SoundData.StorageAddr, &SoundData.Value);
   		   	// SoundData.pControl->Operate(SoundData.OprNum);
		   	 }
}

extern "C" unsigned char GetSound(void)
{
  return (unsigned char)SoundData.Value; 
}
//__________________________________
extern "C" void SetState1(unsigned long val)
{
 if(StateData.pControl->Control(StateData.CntNum, val))
			 {
			 StateData.ChangingValue =  val;
			 StateData.Value =  val;
			 StateData.WriteStorageC(StateData.StorageAddr, StateData.Value);
   		  // 	 StateData.pControl->Operate(StateData.OprNum);
		   	 }
}

extern "C" unsigned char GetState(void)
{
  return (unsigned char)StateData.Value; 
}
//__________________________________
extern "C" void SetErr1(unsigned long val)
{
 if(ErrData.pControl->Control(ErrData.CntNum, val))
			 {
			 ErrData.ChangingValue =  val;
			 ErrData.Value =  val;
			 ErrData.WriteStorageC(ErrData.StorageAddr, ErrData.Value);
   		 //  	 ErrData.pControl->Operate(ErrData.OprNum);
		   	 }
}

extern "C" unsigned char GetErr(void)
{
  return (unsigned char)ErrData.Value; 
}
//__________________________________
extern "C" void SetPoint1(unsigned long val)
{
 if(PointData.pControl->Control(PointData.CntNum, val))
			 {
			 PointData.ChangingValue =  val;
			 PointData.Value =  val;
			 PointData.WriteStorageC(PointData.StorageAddr, PointData.Value);
   		  // 	 PointData.pControl->Operate(PointData.OprNum);
		   	 }
}

extern "C" unsigned char GetPoint(void)
{
  return (unsigned char)PointData.Value; 
}
//__________________________________
extern "C" void SetAddr1(unsigned long val)
{
 if(AddrData.pControl->Control(AddrData.CntNum, val))
			 {
			 AddrData.ChangingValue =  val;
			 AddrData.Value =  val;
			 AddrData.WriteStorageC(AddrData.StorageAddr, AddrData.Value);
   	   //	   	 AddrData.pControl->Operate(AddrData.OprNum);
		   	 }
}

extern "C" unsigned char GetAddr(void)
{
  return (unsigned char)AddrData.Value; 
}

//__________________________________



#endif //PROG_DTVM



void EmbCommand::Init() 
{ 
	m_state=m_index=0; 
	for(int i=0; i<MAX_SIZE_MES; i++) m_str[i]=0; 
}

int EmbCommand::Add(char ch)
{
  if(m_index<MAX_SIZE_MES)
	{
		switch(m_state)
		{
		  case 0: 
				if((ch!='@')&&(ch!='&')) Init();
				else
				{
					m_state = 1;
					m_str[m_index++] = ch;
					if(ch=='!') m_state = 2;
				}
				break;
			case 1:
				if((ch=='@')||(ch=='&')) Init();
				else 
				{
					m_str[m_index++] = ch;
					if(ch=='!') m_state = 2;
				}
				break;
			case 2: 
				Init();
				break;
		}
	}
//_________________________________________________my
	else
	{
  //	 printEthLongHex(0x5);
	 Init();
	}
//_________________________________________________my
	return m_state;
}

unsigned char EmbCommand::GetAddr()
{
  unsigned char i=0;
	if(m_state==2)
	{
    i=Hex2Char(m_str[3]);
		i<<=4;
		i+=Hex2Char(m_str[4]);
	}
	return i;
}

unsigned char EmbCommand::GetPoint()
{
  unsigned char i=0;
	if(m_state==2)
	{
    i=Hex2Char(m_str[1]);
		i<<=4;
		i+=Hex2Char(m_str[2]);
	}
	return i;
}




/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SendZero
* Returned Value   : none
* Comments         :
*    This function send zero
*
*END*----------------------------------------------------------------------*/

void  SendZeroP()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
#ifndef PROG_PU_MSAT

  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 // pio_ptr->CODR = 2; //clock to zero 
  pio_ptr->CODR = MASK_BIT_14; //data to zero;
  pio_ptr->SODR = MASK_BIT_13; //clock to one
  delay_mcs(10l);     
  pio_ptr->CODR = MASK_BIT_13; //clock to zero;
  delay_mcs(10l); 

#else

   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 // pio_ptr->CODR = 2; //clock to zero 
//  pio_ptr->CODR = MASK_BIT_23; //data to zero;
  pio_ptr->CODR = MASK_BIT_22; //data to zero;
  pio_ptr->SODR = MASK_BIT_21; //clock to one
  delay_mcs(10l);     
  pio_ptr->CODR = MASK_BIT_21; //clock to zero;
  delay_mcs(10l); 


#endif
}

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SendOne
* Returned Value   : none
* Comments         :
*    This function send one
*
*END*----------------------------------------------------------------------*/

void  SendOneP()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

#ifndef PROG_PU_MSAT

  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->CODR = 2;
  pio_ptr->SODR = MASK_BIT_14; //data to one;
  pio_ptr->SODR = MASK_BIT_13; //clock to one
  delay_mcs(10l);  
//  delay_mcs(4l);
  pio_ptr->CODR = MASK_BIT_13; //clock to zero;
 delay_mcs(10l);

#else

 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
//  pio_ptr->CODR = 2;
//  pio_ptr->SODR = MASK_BIT_23; //data to one;
  pio_ptr->SODR = MASK_BIT_22; //data to one;
  pio_ptr->SODR = MASK_BIT_21; //clock to one
  delay_mcs(10l);  
//  delay_mcs(4l);
  pio_ptr->CODR = MASK_BIT_21; //clock to zero;
 delay_mcs(10l);
#endif
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SendByteSerial
* Returned Value   : none
* Comments         :
*    This function send byte
*
*END*----------------------------------------------------------------------*/

void  SendByteSerialP(unsigned int SendByte)
{
 unsigned int  i, mask;
 //   mask = 0x01;
    mask = 0x80;
 //  i = 0;
    for(i = 0; i <  8; i++)
  {   
      if(SendByte & mask)
      {SendOneP();}
      else
      {SendZeroP();}   
      mask >>= 1;  
   //   mask <<= 1;  

  } 
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SendSerial
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx through io functions
*
*END*----------------------------------------------------------------------*/

void  SendSerialP(unsigned int SendWord)
{
unsigned int  i;//,j;
 //  i = 0; 
//   static unsigned char test = 0;
 //  for(i = 0; i <  4; i++)
   for(i = 4; i >  0; i--)
  {  
 //   j = i << 3; 
 //   SendWord >>= j;
  //    if(test != (SendWord & 0xff))
  //    { 
  //     printf("\n\r test =0x%X   SendWord  =0x%8X", test, SendWord);
    //   test = SendWord & 0xff;
   //    } 
      SendByteSerialP(SendWord >> (8*(i-1))); 
   //   SendWord >>= 8;
    //  test ++;
  } 
}


extern "C" void	Init_prog_pult_pins()
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0); //get off transmitter usart3 for maket
//pb13 - clk output
//pb14 - mosi output
//pb15 - miso input
//pc11 - reset output

#ifndef PROG_PU_MSAT
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output 
#else
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 23, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output 
#endif




}

extern "C" void	Get_off_prog_pult_pins()
{
//pb13 - clk output
//pb14 - mosi output
//pb15 - miso input
//pc11 - reset output

#ifndef PROG_PU_MSAT
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_B, 0);  //get on transmitter usart3 
#else
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 22, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 0);		// input
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);		// output 
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_B, 0);  //get on transmitter usart3 
#endif

}


extern "C" void SetRST()
{
 //hier need set rst pin to "High"  and wait up to 64 sytem clocks before next operation
 //in pult maked inversion
#ifndef PROG_PU_MSAT

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
  pio_ptrc = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
 // pio_ptrc->SODR = MASK_BIT_11;
  pio_ptrc->CODR = MASK_BIT_11;		// in pult maked inversion
#else
AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
  pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 // pio_ptrc->SODR = MASK_BIT_11;
  pio_ptra->CODR = MASK_BIT_20;		// in pult maked inversion


#endif
  delay_mcs(1000l); //need wait of 64 system cyckles
}

extern "C" void ClearRST()
{
 //hier need set rst pin to "High"  and wait up to 64 sytem clocks before next operation
#ifndef PROG_PU_MSAT

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
  pio_ptrc = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
 // pio_ptrc->CODR = MASK_BIT_11;
  pio_ptrc->SODR = MASK_BIT_11;	  //in pult maked inversion
#else
AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
  pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 // pio_ptrc->SODR = MASK_BIT_11;
  pio_ptra->SODR = MASK_BIT_20;		// in pult maked inversion


#endif

}

extern "C" void EnableSerialProg()
{
 SendSerialP((unsigned int) SERIAL_PROG_ENABLE);
}

extern "C" void EraseMemory()
{
 SendSerialP((unsigned int) PULT_CHIP_ERASE);
}

extern "C" void WriteData()
{

//ok printfp("\n\rWrite_pult_flash");
//ok return;

 // unsigned long WriteWord;
//  unsigned long ReadWord;
  unsigned long i;
  unsigned char j;
  unsigned char * RAMAddr;
  unsigned long FlashAddr;
 // unsigned char tmp;

//  RAMAddr = (unsigned char *)TFTP_BUFFER_ADDRESS;
  RAMAddr = (unsigned char *)&TFTP_Buffer[0];
  FlashAddr = 0l;
  j = 50;
#ifdef ETH_DEBUG_ENABLED
printEthString("\r\nStart...", 13); //+3
delay_mcs(100000);


#endif //	 ETH_DEBUG_ENABLED

  for(i = 0; i < (unsigned long)PULT_PROG_LENGTH;i++)
 // for(i = 0; i < (unsigned long)0x100000;i++)
  {
	SendByteSerialP(WRITE_PULT_FLASH_COMMAND);
  	SendByteSerialP(FlashAddr>>8);
  	SendByteSerialP(FlashAddr++);
 // 	tmp =  *RAMAddr;
  	SendByteSerialP(*RAMAddr++);
 //printfp("\n\rWrite_Data1");
// return;



  //	 SendByteSerialP(0);
  //	 SendByteSerialP(0);
  //	 SendByteSerialP(0x99);
 // 	SendByteSerialP((unsigned char)i);
  //	SendByteSerialP((unsigned char)(i+3) );
   //ok	delay_mcs(4000l); //4 ms
  //ok delay_mcs(2000l);
 //ok  delay_mcs(1000l);
 //bad  delay_mcs(500l);
//ok  delay_mcs(750l);
 //	printEthByteHex(tmp);
 //	delay_mcs(1500l);
	delay_mcs(4000l);
  //t	delay_mcs(100l); //4 ms
	if(!(i % (PULT_PROG_LENGTH / 50)))
	{
// 	 printf("\n\r%05ld", i);
#ifdef ETH_DEBUG_ENABLED
 	// printEthByteHex((unsigned char)((i *100l) / PULT_PROG_LENGTH ));
   //	 printEthByteHex(j--);
	  printEthLongHex(j--);

#endif //ETH_DEBUG_ENABLED
	 wd_reset();
  //	  printfp("\n\rWrite_Data3");
     printfpd(" %d", j);
     OperateBuffers_usart0t();
	
// if(i == 100l)
//t return;


	}
//  printfp("\n\rWrite_Data2");
// if(i == 100l)
// return;


  } //i
//  delay_mcs(1500l);

//  printEthByteHex(0);
//  printEthByteHex(0);
//  printEthByteHex(0);
//  printEthByteHex(0);
//  delay_mcs(1500l);


}

extern "C" unsigned char  ReceiveByteSerialP()
{
 //unsigned long state_port_B;
 unsigned char data;
#ifndef PROG_PU_MSAT
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 data = 0;
  for (unsigned long i = 0; i < 8; i++)
   {
    //  delay_mcs(10);
      pio_ptr->SODR = MASK_BIT_13; //clock to one
	  delay_mcs(100);
      pio_ptr->CODR = MASK_BIT_13; //clock to zero;
	  delay_mcs(100);
	  data <<= 1;
      if(pio_ptr->PDSR & MASK_BIT_15){data += 1;  }
   }
#else
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 data = 0;
  for (unsigned long i = 0; i < 8; i++)
   {
    //  delay_mcs(10);
      pio_ptr->SODR = MASK_BIT_21; //clock to one
	  delay_mcs(100);
      pio_ptr->CODR = MASK_BIT_21; //clock to zero;
	  delay_mcs(100);
	  data <<= 1;
      if(pio_ptr->PDSR & MASK_BIT_23){data += 1;  }
   }


#endif


  return data;
}

extern "C" char CompareData()
{
 // unsigned long WriteWord;
//  unsigned long ReadWord;
  unsigned long i;
  unsigned char * RAMAddr;
  unsigned long FlashAddr;
  unsigned char j;
  RAMAddr = (unsigned char *)TFTP_BUFFER_ADDRESS;
  FlashAddr = 0l;
  j = 50;
  unsigned char tmp, tmp1;
  unsigned char ret;
  ret = 1;
 // for(i = 0; i < (unsigned long)PULT_PROG_LENGTH;i++)
   for(i = 0; i < (unsigned long)PULT_PROG_LENGTH;i++)
 // for(i = 0; i < (unsigned long)0x100000;i++)
  {
	SendByteSerialP(READ_PULT_FLASH_COMMAND);
  	SendByteSerialP(FlashAddr>>8);
  	SendByteSerialP(FlashAddr++);
  //	SendByteSerialP(0);
 // 	SendByteSerialP(0);
    delay_mcs(100);
   	tmp =  ReceiveByteSerialP();
  //	 printEthByteHex(tmp);

	tmp1 = *RAMAddr++;

	if(!(i % (PULT_PROG_LENGTH / 50)))
	{
// 	 printf("\n\r%05ld", i);
#ifdef ETH_DEBUG_ENABLED
 	// printEthByteHex((unsigned char)((i *100l) / PULT_PROG_LENGTH ));
	 printEthByteHex(j--);

   printfpd(" %d", j);
   OperateBuffers_usart0t();

#endif //ETH_DEBUG_ENABLED
	 wd_reset();
	}

   //	 if(ReceiveByteSerialP() != *RAMAddr++)	 
  //	 if(ReceiveByteSerialP() != *RAMAddr++)
  	 if(tmp != tmp1)
   //	 if(tmp != i)
  //	 if(1)
   	 {
   //	   printEthByteHex(tmp);
   //	   delay_mcs(300);
 //	   printEthByteHex(tmp1);
// #ifdef ETH_DEBUG_ENABLED
 //  printEthString("Ok", 10);
//   printEthByteHex(1);
 //    printEthString("\r\nCompare Not Ok\r\n", 21);
//#endif //ETH_DEBUG_ENABLED

 	  return 0;
  //	  ret = 0; 
	 }
  //	delay_mcs(10l); //
  } //i
//  return 1;
//#ifdef ETH_DEBUG_ENABLED
//printEthString("Not Ok", 10);

 // printEthString("\r\nCompare Ok\r\n", 17); //+3

//#endif //	 ETH_DEBUG_ENABLED

 return ret;
}

extern "C" void Write_pult_flash()
{

//ok printfp("Write_pult_flash");
//ok return;

 unsigned char tst;
 SetRST();
 delay_mcs(10000);
 EnableSerialProg();
// delay_mcs(100);
 EraseMemory();
 delay_mcs(10000);
 WriteData();
// printfp("Write_pult_flash1");
// return;


 delay_mcs(10000);
 #ifdef ETH_DEBUG_ENABLED
printEthString("...Compare\r\n", 15); //+3
 
#endif //	 ETH_DEBUG_ENABLED
  tst = CompareData();
// if(!CompareData())
 if(tst)
 {				 
 //Message to bad comparing
 // printf("\n\r Programm Pult Flash Comparing not Ok");
#ifdef ETH_DEBUG_ENABLED
delay_mcs(100000);
  printEthString("Compare Ok\r\n", 15); //+3

 printfp("Compare Ok\r\n");

#endif //	 ETH_DEBUG_ENABLED

 }
 else
 {
//  printf("\n\r Programm Pult Flash Ok");
#ifdef ETH_DEBUG_ENABLED
 delay_mcs(100000);
       printEthString("Compare Not Ok\r\n", 19);
	    printfp("Compare Not Ok\r\n");

#endif //ETH_DEBUG_ENABLED
 }
  ClearRST();
  Get_off_prog_pult_pins();
  delay_mcs(50000);
#ifdef ETH_DEBUG_ENABLED
printEthString("...Finish\r\n", 14); //+3
 // printEthLongHex(0);
#endif //	 ETH_DEBUG_ENABLED

}

extern "C" void ProgrammPult()
{
  read_dataflash ((unsigned int)(PULT_PROG_ADDRESS),(unsigned int)PULT_PROG_LENGTH, (char *)(&TFTP_Buffer[0]));
  Init_prog_pult_pins();
  Write_pult_flash();
}

extern "C" void ProgrammPultTFTP()
{
// printfp("ProgrammPultTFTP");
// return;

 // read_dataflash ((unsigned int)(PULT_PROG_ADDRESS),(unsigned int)PULT_PROG_LENGTH, (char *)(&TFTP_Buffer[0]));
  Init_prog_pult_pins();



  Write_pult_flash();
}


#define  READ_SGN_COMMAND  (0x28)
#define  FIRST_SGN_ADDR (0x30)
#define  TWO_SGN_ADDR (0x31)
#define  EMPTY_BYTE	  (0)

extern "C" void ReadSGN()
{
 unsigned char tmp, tmp1;
 tmp1 = 0x55;
  SetRST();
//  for(long i = 0; i < 100000; i++)
//  {
  EnableSerialProg();
 // wd_reset();
//  delay_mcs(2000l);
 // }

  for(long i = 0; i < 1000; i++)
  {
  SendByteSerialP(READ_SGN_COMMAND);
  SendByteSerialP(EMPTY_BYTE);
  //SendByteSerialP(FIRST_SGN_ADDR);
  SendByteSerialP(TWO_SGN_ADDR);
   delay_mcs(100);
  tmp =  ReceiveByteSerialP();
  if(tmp != tmp1)
  {
  printEthByteHex(tmp);
  tmp1 = tmp;
  }
    delay_mcs(1000);
  }
  ClearRST();
}

extern "C" void ReadAtmelSGN()
{
  Init_prog_pult_pins();
  ReadSGN();
}


#endif //PROGRAMM_PULT

#ifdef PROG_TUTS

extern "C" void Set_Triggered(unsigned long curval, unsigned long oldval)	   //after reading from remote
{
  unsigned long tmp = 1l;
  unsigned long tmp1 = (unsigned long)TSInpTrg.Value;
  for(long i = 0l; i <32l; i++)
  {
	if((oldval & tmp) != (curval & tmp))
	{
	  tmp1 |= tmp;
  	}
	tmp <<= 1;
  }	
   TSInpTrg.Value = (float64)tmp1;
   TSInpTrg.ChangingValue = TSInpTrg.Value;
   SetHardvareTrInps(tmp1);
}



extern "C" void Reset_Triggered(unsigned long mask)	   //after reading from remote
{
  unsigned long tmp = (unsigned long)TSInpTrg.Value;
  tmp &= ~mask;
 // tmp = 0l; //t
  TSInpTrg.Value = (float64)tmp;
  TSInpTrg.ChangingValue = TSInpTrg.Value ;
 // printf("\n\r reset");//t
  //TSInpTrg.Value = 0l;	   //t
  //TSInpTrg.ChangingValue = 0l ;	  //t

}

struct LONG_BITS_DET
{
unsigned long Bit_0 : 1;
unsigned long Bit_1 : 1;
unsigned long Bit_2 : 1;
unsigned long Bit_3 : 1;
unsigned long Bit_4 : 1;
unsigned long Bit_5 : 1;
unsigned long Bit_6 : 1;
unsigned long Bit_7 : 1;
unsigned long Bit_8 : 1;
unsigned long Bit_9 : 1;
unsigned long Bit_10 : 1;
unsigned long Bit_11 : 1;
unsigned long Bit_12 : 1;
unsigned long Bit_13 : 1;
unsigned long Bit_14 : 1;
unsigned long Bit_15 : 1;
unsigned long Bit_16 : 1;
unsigned long Bit_17 : 1;
unsigned long Bit_18 : 1;
unsigned long Bit_19 : 1;
unsigned long Bit_20 : 1;
unsigned long Bit_21 : 1;
unsigned long Bit_22 : 1;
unsigned long Bit_23 : 1;
unsigned long Bit_24 : 1;
unsigned long Bit_25 : 1;
unsigned long Bit_26 : 1;
unsigned long Bit_27 : 1;
unsigned long Bit_28 : 1;
unsigned long Bit_29 : 1;
unsigned long Bit_30 : 1;
unsigned long Bit_31 : 1;
};

union  LONG_BITS
{
 unsigned long	all;
 LONG_BITS_DET bit;
};

extern "C" unsigned long TUTS_Input_Read(void)
{
 LONG_BITS ret;						   
 unsigned long state_port_B;
 unsigned long state_port_A;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrb;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
 pio_ptrb = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 state_port_B = pio_ptrb->PDSR;
 state_port_A = pio_ptra->PDSR;

  /*
 ret.bit.Bit_0  = (state_port_B & MASK_BIT_0)  ? 1:0;
 ret.bit.Bit_1  = (state_port_A & MASK_BIT_29) ? 1:0;
 ret.bit.Bit_2  = (state_port_A & MASK_BIT_28) ? 1:0;
 ret.bit.Bit_3  = (state_port_A & MASK_BIT_27) ? 1:0;

 ret.bit.Bit_4  = (state_port_B & MASK_BIT_4)  ? 1:0;
 ret.bit.Bit_5  = (state_port_B & MASK_BIT_3)  ? 1:0;
 ret.bit.Bit_6  = (state_port_B & MASK_BIT_2)  ? 1:0;
 ret.bit.Bit_7  = (state_port_B & MASK_BIT_1)  ? 1:0;

 ret.bit.Bit_8  = (state_port_B & MASK_BIT_8)  ? 1:0;
 ret.bit.Bit_9  = (state_port_B & MASK_BIT_7)  ? 1:0;
 ret.bit.Bit_10 = (state_port_B & MASK_BIT_6)  ? 1:0;
 ret.bit.Bit_11 = (state_port_B & MASK_BIT_5)  ? 1:0;

 ret.bit.Bit_12 = (state_port_B & MASK_BIT_12) ? 1:0;
 ret.bit.Bit_13 = (state_port_B & MASK_BIT_11) ? 1:0;
 ret.bit.Bit_14 = (state_port_B & MASK_BIT_10) ? 1:0;
 ret.bit.Bit_15 = (state_port_B & MASK_BIT_9)  ? 1:0;

 ret.bit.Bit_16 = (state_port_B & MASK_BIT_16) ? 1:0;
 ret.bit.Bit_17 = (state_port_B & MASK_BIT_15) ? 1:0;
 ret.bit.Bit_18 = (state_port_B & MASK_BIT_14) ? 1:0;
 ret.bit.Bit_19 = (state_port_B & MASK_BIT_13) ? 1:0;

 ret.bit.Bit_20 = (state_port_B & MASK_BIT_22) ? 1:0;
 ret.bit.Bit_21 = (state_port_B & MASK_BIT_19) ? 1:0;
 ret.bit.Bit_22 = (state_port_B & MASK_BIT_18) ? 1:0;
 ret.bit.Bit_23 = (state_port_B & MASK_BIT_17) ? 1:0;

 ret.bit.Bit_24 = (state_port_A & MASK_BIT_22) ? 1:0;
 ret.bit.Bit_25 = (state_port_A & MASK_BIT_21) ? 1:0;
 ret.bit.Bit_26 = (state_port_A & MASK_BIT_20) ? 1:0;
 ret.bit.Bit_27 = (state_port_A & MASK_BIT_19) ? 1:0;

 ret.bit.Bit_28 = (state_port_A & MASK_BIT_26) ? 1:0;
 ret.bit.Bit_29 = (state_port_A & MASK_BIT_25) ? 1:0;
 ret.bit.Bit_30 = (state_port_A & MASK_BIT_24) ? 1:0;
 ret.bit.Bit_31 = (state_port_A & MASK_BIT_23) ? 1:0;
		*/
// is in hardvare :

  ret.bit.Bit_0 = (state_port_A & MASK_BIT_19) ? 1:0;
  ret.bit.Bit_1 = (state_port_A & MASK_BIT_20) ? 1:0;
  ret.bit.Bit_2 = (state_port_A & MASK_BIT_21) ? 1:0;
  ret.bit.Bit_3 = (state_port_A & MASK_BIT_22) ? 1:0;

  ret.bit.Bit_4 = (state_port_A & MASK_BIT_23) ? 1:0;
  ret.bit.Bit_5 = (state_port_A & MASK_BIT_24) ? 1:0;
  ret.bit.Bit_6 = (state_port_A & MASK_BIT_25) ? 1:0; 
  ret.bit.Bit_7 = (state_port_A & MASK_BIT_26) ? 1:0;

  ret.bit.Bit_8  = (state_port_A & MASK_BIT_27) ? 1:0;
  ret.bit.Bit_9  = (state_port_A & MASK_BIT_28) ? 1:0;
  ret.bit.Bit_10  = (state_port_A & MASK_BIT_29) ? 1:0;
  ret.bit.Bit_11  = (state_port_B & MASK_BIT_0)  ? 1:0;

  ret.bit.Bit_12  = (state_port_B & MASK_BIT_1)  ? 1:0;
  ret.bit.Bit_13  = (state_port_B & MASK_BIT_2)  ? 1:0;
  ret.bit.Bit_14  = (state_port_B & MASK_BIT_3)  ? 1:0;
  ret.bit.Bit_15  = (state_port_B & MASK_BIT_4)  ? 1:0;

  ret.bit.Bit_16 = (state_port_B & MASK_BIT_5)  ? 1:0;
  ret.bit.Bit_17 = (state_port_B & MASK_BIT_6)  ? 1:0;
  ret.bit.Bit_18 = (state_port_B & MASK_BIT_7)  ? 1:0;
  ret.bit.Bit_19 = (state_port_B & MASK_BIT_8)  ? 1:0;
 
  ret.bit.Bit_20 = (state_port_B & MASK_BIT_9) ? 1:0;
  ret.bit.Bit_21 = (state_port_B & MASK_BIT_10) ? 1:0;
  ret.bit.Bit_22 = (state_port_B & MASK_BIT_11) ? 1:0;
  ret.bit.Bit_23 = (state_port_B & MASK_BIT_12)  ? 1:0;
 
  ret.bit.Bit_24 = (state_port_B & MASK_BIT_13) ? 1:0;
  ret.bit.Bit_25 = (state_port_B & MASK_BIT_14) ? 1:0;
  ret.bit.Bit_26 = (state_port_B & MASK_BIT_15) ? 1:0;
  ret.bit.Bit_27 = (state_port_B & MASK_BIT_16) ? 1:0;

 ret.bit.Bit_28 = (state_port_B & MASK_BIT_17) ? 1:0;
 ret.bit.Bit_29 = (state_port_B & MASK_BIT_18) ? 1:0;
 ret.bit.Bit_30 = (state_port_B & MASK_BIT_19) ? 1:0;
 ret.bit.Bit_31 = (state_port_B & MASK_BIT_22) ? 1:0;


   /*
  ret.bit.Bit_4 = (state_port_A & MASK_BIT_23) ? 1:0;
  ret.bit.Bit_5 = (state_port_A & MASK_BIT_24) ? 1:0;
  ret.bit.Bit_6 = (state_port_A & MASK_BIT_25) ? 1:0;
  ret.bit.Bit_7 = (state_port_A & MASK_BIT_26) ? 1:0;

  ret.bit.Bit_8  = (state_port_A & MASK_BIT_27) ? 1:0;
  ret.bit.Bit_9  = (state_port_A & MASK_BIT_28) ? 1:0;
  ret.bit.Bit_10  = (state_port_A & MASK_BIT_29) ? 1:0;
  ret.bit.Bit_11  = (state_port_B & MASK_BIT_0)  ? 1:0;

  ret.bit.Bit_12  = (state_port_B & MASK_BIT_1)  ? 1:0;
  ret.bit.Bit_13  = (state_port_B & MASK_BIT_2)  ? 1:0;
  ret.bit.Bit_14  = (state_port_B & MASK_BIT_3)  ? 1:0;
  ret.bit.Bit_15  = (state_port_B & MASK_BIT_4)  ? 1:0;
 
  ret.bit.Bit_16  = (state_port_B & MASK_BIT_8)  ? 1:0;
  ret.bit.Bit_17  = (state_port_B & MASK_BIT_7)  ? 1:0;
  ret.bit.Bit_18  = (state_port_B & MASK_BIT_6)  ? 1:0;
  ret.bit.Bit_19  = (state_port_B & MASK_BIT_5)  ? 1:0;

  ret.bit.Bit_20  = (state_port_A & MASK_BIT_27) ? 1:0;
  ret.bit.Bit_21  = (state_port_A & MASK_BIT_28) ? 1:0;
  ret.bit.Bit_22  = (state_port_A & MASK_BIT_29) ? 1:0;
  ret.bit.Bit_23  = (state_port_B & MASK_BIT_0)  ? 1:0;

  ret.bit.Bit_24 = (state_port_A & MASK_BIT_23) ? 1:0;
  ret.bit.Bit_25 = (state_port_A & MASK_BIT_24) ? 1:0;
  ret.bit.Bit_26 = (state_port_A & MASK_BIT_25) ? 1:0;
  ret.bit.Bit_27 = (state_port_A & MASK_BIT_26) ? 1:0;
 
  ret.bit.Bit_28 = (state_port_A & MASK_BIT_19) ? 1:0;
  ret.bit.Bit_29 = (state_port_A & MASK_BIT_20) ? 1:0;
  ret.bit.Bit_30 = (state_port_A & MASK_BIT_21) ? 1:0;
  ret.bit.Bit_31 = (state_port_A & MASK_BIT_22) ? 1:0;

  */
 //>>>>>>>>>>>>>>>>>>>>>>>>> need make all
//_____________________________________for test!!!!
/*

static long tst_counter;
#define DELAY_10S (10000l)

   if(tst_counter > 2 * DELAY_10S)
   {
	tst_counter =0;
   }
   else if(tst_counter >  DELAY_10S)
   {
   tst_counter++;
	ret.all = 0xffffffffl;
   }
   else
   {
	tst_counter++;
	ret.all =0l;
    }

*/
//_____________________________________for test!!!!



	SetHardvareInps(ret.all);
 return ret.all;
}

extern "C" void TUTS_Output_Set(unsigned char set)
{
// if(InitFinish) printf(" Set: %X", set);	 //for debug

 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
 pio_ptrc = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
 LONG_BITS lset;
 LONG_BITS lclear;
 lclear.all = 0l;
 lset.all = 0l;

 lset.bit.Bit_11 = (set & MASK_BIT_0) ?  1 : 0;
 lset.bit.Bit_12 = (set & MASK_BIT_1) ?  1 : 0;
 lset.bit.Bit_15 = (set & MASK_BIT_2) ?  1 : 0;
 lset.bit.Bit_14 = (set & MASK_BIT_3) ?  1 : 0;
 lset.bit.Bit_0  = (set & MASK_BIT_4) ?  1 : 0;
 lset.bit.Bit_1  = (set & MASK_BIT_5) ?  1 : 0;
 lset.bit.Bit_3  = (set & MASK_BIT_6) ?  1 : 0;
 lset.bit.Bit_2  = (set & MASK_BIT_7) ?  1 : 0;

 lclear.bit.Bit_11 = (set & MASK_BIT_0) ?  0 : 1;
 lclear.bit.Bit_12 = (set & MASK_BIT_1) ?  0 : 1;
 lclear.bit.Bit_15 = (set & MASK_BIT_2) ?  0 : 1;
 lclear.bit.Bit_14 = (set & MASK_BIT_3) ?  0 : 1;
 lclear.bit.Bit_0  = (set & MASK_BIT_4) ?  0 : 1;
 lclear.bit.Bit_1  = (set & MASK_BIT_5) ?  0 : 1;
 lclear.bit.Bit_3  = (set & MASK_BIT_6) ?  0 : 1;
 lclear.bit.Bit_2  = (set & MASK_BIT_7) ?  0 : 1;

 pio_ptrc->SODR = lset.all;
 pio_ptrc->CODR = lclear.all;
 //unsigned char test =  (unsigned char)lset.all;
//  printf("\n\r lset = 0x%d", test);
 //printf("\n\r lclear = 0x%lX", lclear.all);

 SetHardvareOuts(set);//indicate outputs state in hardvare struct

}

extern "C" void TUTS_IO_Init(void)
{
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0,  AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI0	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI1	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI2	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 27, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI3	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI4	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI5	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI6	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI7	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI8	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI9	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI10	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI11	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI12       input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI13	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI14	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI15	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI16	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI17	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI18	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI19	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI20	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI21	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI22	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI23	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 22, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI24	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI25	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI26	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 19, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI27	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 26, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI28       input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 25, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI29	   input  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI30	   input
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 23, AT91RM9200_PIO_PERIPHERAL_IO, 0);		//DI31	   input

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11,  AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO0	   output
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO1	   output  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO2	   output
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO3	   output
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO4	   output
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO5	   output  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO6	   output
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);		//DO7	   output

	TUTS_Output_Set((unsigned char) TSOut.Value);
	TSInp.Value = TUTS_Input_Read();
	TSInp.ChangingValue =  TSInp.Value;
	TSInpTrg.Value = 0l;
	TSInpTrg.ChangingValue = 0l;
	SetHardvareTrInps(0);

}

extern "C" void Inputs_Scan(void)
{
	unsigned long tmp =  TUTS_Input_Read();
	if(tmp != TSInp.Value )
	{
	Set_Triggered(tmp, TSInp.Value);
	TSInp.Value = tmp;//TUTS_Input_Read();
	TSInp.ChangingValue = tmp;//TUTS_Input_Read();
  	}
 //	return (unsigned long)TSInp.Value;
}

// extern "C" unsigned long Inputs_Monitoring(void)
 extern "C" unsigned long Inputs_Monitoring(unsigned long mask)
{
//	Reset_Triggered(0xFFFFFFFFl);
	Reset_Triggered(mask);
   	return (unsigned long)TSInp.Value;
}


extern "C" unsigned long Inputs_Triggered_Monitoring(void)
{
   	return (unsigned long)TSInpTrg.Value;
}


extern "C" char Outputs_Monitoring(void)
{
 	return (char)TSOut.Value;
}


 extern "C" void Set_Outputs(unsigned char set)
{
   //	if(InitFinish) printf(" Set_0: %X", set);

	TSOut.Value = (uint_64)set;
	TSOut.ChangingValue = TSOut.Value;
	TUTS_Output_Set((unsigned char) TSOut.Value);
	WriteDevId(); 
}

//__________________________________
//extern  "C" void SetLoopO(unsigned char* data_ptr, unsigned long* data_len)
//{
//  unStatePUM.statePUM.state[5] = (unsigned char)*data_ptr;
 // Stephany19 = (unsigned char)*data_ptr;
//}


//extern "C" void Set_Outputs_BitO(unsigned char mask, unsigned char set)
extern "C" void Set_Outputs_BitO(unsigned char  mask, unsigned char* data_ptr, unsigned char  move)
{

	unsigned char set;
	set = *	data_ptr;
	set <<= move;
 	LONG_BITS outps;
 	outps.all = (unsigned long)TSOut.Value;
 	if(mask & MASK_BIT_0) { outps.bit.Bit_0 = (set & MASK_BIT_0) ?  1 : 0;}
 	if(mask & MASK_BIT_1) { outps.bit.Bit_1 = (set & MASK_BIT_1) ?  1 : 0;} // MASK_BIT_0 - check first bit in set value in all variants!
	if(mask & MASK_BIT_2) { outps.bit.Bit_2 = (set & MASK_BIT_2) ?  1 : 0;}
	if(mask & MASK_BIT_3) { outps.bit.Bit_3 = (set & MASK_BIT_3) ?  1 : 0;}
	if(mask & MASK_BIT_4) { outps.bit.Bit_4 = (set & MASK_BIT_4) ?  1 : 0;}
	if(mask & MASK_BIT_5) { outps.bit.Bit_5 = (set & MASK_BIT_5) ?  1 : 0;}
	if(mask & MASK_BIT_6) { outps.bit.Bit_6 = (set & MASK_BIT_6) ?  1 : 0;}
	if(mask & MASK_BIT_7) { outps.bit.Bit_7 = (set & MASK_BIT_7) ?  1 : 0;}
	TSOut.Value = (uint_64)outps.all;
	TSOut.ChangingValue = TSOut.Value;
	UsedExp.State.Reg2.bit.SetOutp = 1;
	UsedExp.State.Reg2.bit.Some = 1;
  //hier need set bits to make all in main loop to needupddate
  //to main loop	TUTS_Output_Set((unsigned char) TSOut.Value);
  //to main loop 	WriteDevId(); 
   //	TSInpTrg.Value++; //TO TEST
   //	 TSInpTrg.ChangingValue++;
//	return (unsigned char)TSOut.Value;
}

//extern  "C" unsigned char * GetTlfNumberO(unsigned char* data_ptr, unsigned long* data_len)
//extern  "C" unsigned char * GetLoopO(unsigned long* data_len)
//{
//  *data_len = 1;
//  return &unStatePUM.statePUM.state[5];
//}

//extern "C" unsigned char Get_Outputs_Bit)(unsigned char mask, unsigned char set)
extern "C" unsigned char * Get_Outputs_BitO(unsigned long* data_len, unsigned long mask, unsigned char mov)
{
 static unsigned char ret;
	*data_len = 1;

   //	LONG_BITS outps;
  //	outps.all = (unsigned long)TSOut.Value;
  //	if(mask & MASK_BIT_0) { outps.bit.Bit_0 = (set & MASK_BIT_0) ?  1 : 0;}
  //	if(mask & MASK_BIT_1) { outps.bit.Bit_1 = (set & MASK_BIT_1) ?  1 : 0;}
  //	if(mask & MASK_BIT_2) { outps.bit.Bit_2 = (set & MASK_BIT_2) ?  1 : 0;}
  //	if(mask & MASK_BIT_3) { outps.bit.Bit_3 = (set & MASK_BIT_3) ?  1 : 0;}
  //	if(mask & MASK_BIT_4) { outps.bit.Bit_4 = (set & MASK_BIT_4) ?  1 : 0;}
  //	if(mask & MASK_BIT_5) { outps.bit.Bit_5 = (set & MASK_BIT_5) ?  1 : 0;}
  //	if(mask & MASK_BIT_6) { outps.bit.Bit_6 = (set & MASK_BIT_6) ?  1 : 0;}
  //	if(mask & MASK_BIT_7) { outps.bit.Bit_7 = (set & MASK_BIT_7) ?  1 : 0;}
  //	TSOut.Value = (uint_64)outps.all;
  //	TSOut.ChangingValue = TSOut.Value;
  //	UsedExp.State.Reg2.bit.SetOutp = 1;
  //	UsedExp.State.Reg2.bit.Some = 1;
  //hier need set bits to make all in main loop to needupddate
  //to main loop	TUTS_Output_Set((unsigned char) TSOut.Value);
  //to main loop 	WriteDevId(); 
   //	TSInpTrg.Value++; //TO TEST
   //	 TSInpTrg.ChangingValue++;
  
   ret =  ((unsigned char)TSOut.Value) & (unsigned char)mask;
   ret >>= mov;
  //	return (unsigned char)TSOut.Value;
	  return &ret;
}


//___________________________________________________________



extern "C" unsigned char Set_Outputs_Bit(unsigned char mask, unsigned char set)
{
 	LONG_BITS outps;
 	outps.all = (unsigned long)TSOut.Value;
 	if(mask & MASK_BIT_0) { outps.bit.Bit_0 = (set & MASK_BIT_0) ?  1 : 0;}
 	if(mask & MASK_BIT_1) { outps.bit.Bit_1 = (set & MASK_BIT_1) ?  1 : 0;}
	if(mask & MASK_BIT_2) { outps.bit.Bit_2 = (set & MASK_BIT_2) ?  1 : 0;}
	if(mask & MASK_BIT_3) { outps.bit.Bit_3 = (set & MASK_BIT_3) ?  1 : 0;}
	if(mask & MASK_BIT_4) { outps.bit.Bit_4 = (set & MASK_BIT_4) ?  1 : 0;}
	if(mask & MASK_BIT_5) { outps.bit.Bit_5 = (set & MASK_BIT_5) ?  1 : 0;}
	if(mask & MASK_BIT_6) { outps.bit.Bit_6 = (set & MASK_BIT_6) ?  1 : 0;}
	if(mask & MASK_BIT_7) { outps.bit.Bit_7 = (set & MASK_BIT_7) ?  1 : 0;}
	TSOut.Value = (uint_64)outps.all;
	TSOut.ChangingValue = TSOut.Value;
	UsedExp.State.Reg2.bit.SetOutp = 1;
	UsedExp.State.Reg2.bit.Some = 1;
  //hier need set bits to make all in main loop to needupddate
  //to main loop	TUTS_Output_Set((unsigned char) TSOut.Value);
  //to main loop 	WriteDevId(); 
   //	TSInpTrg.Value++; //TO TEST
   //	 TSInpTrg.ChangingValue++;
	return (unsigned char)TSOut.Value;
}


#endif //PROG_TUTS


extern "C" char TestCheckSum()
{
//#define START_LENGTH   (20)
#define START_LENGTH   (0xf00)	  //hier function _arm920t_read_id_reg - it is not used
#define LENGTH_LENGTH  (4)
#define CHECKSUM_LENGTH	 (4)
 char * pData;
 int i;
 unsigned int filesize;
 unsigned int checksum;
 unsigned int controlchecksum;
 filesize = 0l;
 read_dataflash ((unsigned int)(PROG_ADDRESS + START_LENGTH),(unsigned int)LENGTH_LENGTH, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
 for(i = 0; i < LENGTH_LENGTH; i++)
 {
   filesize <<= 8;
   filesize	+= *pData++;
 }
 //if(filesize > MAX_PROG_LENGTH)
 if((filesize > MAX_PROG_LENGTH) ||  (filesize <= CHECKSUM_LENGTH))

 {
	 return 0;
 }
 //printf("\n\r filesize = %d", filesize);

  read_dataflash ((unsigned int)(PROG_ADDRESS),(unsigned int)filesize, (char *)(&TFTP_Buffer[0]));
  checksum = 0;
  controlchecksum = 0;
  pData =  (char *)(&TFTP_Buffer[0]);
  for(i = 0; i < (filesize - CHECKSUM_LENGTH); i++)
 {
    checksum += *pData++;
 }
  controlchecksum += *pData++;
  controlchecksum <<= 8; 
  controlchecksum += *pData++;
  controlchecksum <<= 8; 
  controlchecksum += *pData++;
  controlchecksum <<= 8; 
  controlchecksum += *pData;
  

  if(checksum != controlchecksum)
  {
 // printf("\r\n checksum = %X", checksum);
 // printf("\r\n controlchecksum = %X", controlchecksum);
    return 0;
  }
  return 1;	
}

extern "C" char ProgWrite()
{
//#define START_LENGTH   (20)
#define START_LENGTH   (0xf00)	  //hier function _arm920t_read_id_reg - it is not used
#define LENGTH_LENGTH  (4)
#define CHECKSUM_LENGTH	 (4)
 char * pData;
 int i;
 unsigned int filesize;
 unsigned int checksum;
 unsigned int controlchecksum;
 // printEthLongHex(0x111);
 //_________________________________________
 // char  Buffer[20];
 // char  Buffer1[10];
  //_________________________________________

// read_dataflash ((unsigned int)(PROG_ADDRESS + START_LENGTH),(unsigned int)LENGTH_LENGTH, (char *)(&TFTP_Buffer[0]));
 filesize = 0l;
 pData =  (char *)(&TFTP_Buffer[0] + START_LENGTH);

//it is last!  write_nvram_char(0x1 ,1);

 for(i = 0; i < LENGTH_LENGTH; i++)
 {
    filesize <<= 8;
   filesize	+= *pData++;
  //   filesize += (*pData++) << (8 * i);
 }

 //  printEthLongHex(filesize);

 if((filesize > MAX_PROG_LENGTH) ||  (filesize <= (CHECKSUM_LENGTH + 1)))
 {
 // printEthLongHex((0x1l<<24) + filesize);
  //	write_nvram_char(0x0 ,filesize & 0xf);
  //	write_nvram_char(0x1 ,(filesize >> 8 )& 0xf);
  //	write_nvram_char(0x2 ,(filesize >> 16 )& 0xf);
  //	write_nvram_char(0x3 ,(filesize >> 24 )& 0xf);


	 return 0;
 }
 //    write_nvram_char(0x1 ,2);

//ok return 0; //t
 //printf("\n\r filesize = %d", filesize);

 // read_dataflash ((unsigned int)(PROG_ADDRESS),(unsigned int)filesize, (char *)(&TFTP_Buffer[0]));
  checksum = 0l;
  controlchecksum = 0l;
  pData =  (char *)(&TFTP_Buffer[0]);
//ok  printEthLongHex((unsigned long)pData);
  for(i = 0; i < (filesize - CHECKSUM_LENGTH); i++)
 {
    checksum += *pData++;
 }
 //ok printEthLongHex(checksum);

  controlchecksum += *pData++;
 controlchecksum <<= 8; 
 controlchecksum += *pData++;
//  controlchecksum += (*pData++ << 8);
  controlchecksum <<= 8; 
  controlchecksum += *pData++;
//  controlchecksum += (*pData++ << 16);
  controlchecksum <<= 8; 
//  controlchecksum += (*pData << 24);
controlchecksum += *pData;

//  printEthLongHex(controlchecksum);
 //	  write_nvram_char(0x1 ,3);
//  printfpd("ch %X", checksum);
//  printfpd("co %X", controlchecksum);

  if(checksum != controlchecksum)
  {
//    printfp("DO NOT WRITE");
 //  printEthLongHex((0x2l << 24) + controlchecksum);
 //  delay_mcs(1000l);
 //  printEthLongHex(checksum);
  //	 write_nvram_char(0 ,0x1);
 //   write_nvram_char(0x1 ,4);

    return 0;
  }
 //  write_nvram_char(0 ,0x5);

  //______________________________________________________________
  /*
   sprintf(Buffer, "0x%08X", checksum);
   sprintf(Buffer1, "0x%08X", controlchecksum);
   for (i = 0; i <10; i++)
   {
   Buffer[i+10] = Buffer1[i];
   }
   // printEthString(Buffer, 27);
	*/
  //______________________________________________________________
 //  printEthLongHex(0x3l);	  //t
  //write_dataflash ((unsigned long)&TFTP_Buffer[0], PROG_ADDRESS, (filesize + 4l));
//  return 0; //test
 // write_dataflash ( PROG_TEST_ADDRESS,(unsigned long)&TFTP_Buffer[0], (filesize + 4l));
 //  printfp("WRITE");
  write_dataflash ( PROG_ADDRESS,(unsigned long)&TFTP_Buffer[0], (filesize + 4l));
  return 1;	
}


extern "C" char XilWrite()
{
#define START_SIZE	(0x20)
  write_dataflash ( (XilFileDataAddressD - START_SIZE),(unsigned long)&TFTP_Buffer[0], (XilSizeToDownloadD + 4l));
  return 1;	
}



extern "C" char DPDWrite()
{
  write_dataflash ( (DPD_ADDRESS),(unsigned long)&TFTP_Buffer[0], (DPD_SIZE));
  return 1;	
}




extern "C" void  pRBuff0_init()
{
   pRBuff0_cnt = 0l;
   pRBuff0 = &RBuff0[0];
}

extern "C" void  pRBuff3_init()
{
   pRBuff3_cnt = 0l;
   pRBuff3 = &RBuff3[0];
}



extern "C" void  pRBuff0_control(unsigned long len)
{
 if((pRBuff0_cnt + len) >= ACT_BUFFER_SIZE1)
 {
    pRBuff0_init();
  }
 else
 {
    pRBuff0_cnt += len;
 }
}

extern "C" void  pRBuff3_control(unsigned long len)
{
 if((pRBuff3_cnt + len) >= ACT_BUFFER_SIZE1)
 {
    pRBuff3_init();
  }
 else
 {
    pRBuff3_cnt += len;
 }
}


extern "C" void  pTBuff0_init(void)
{
   pTBuff0_cnt = 0l;
   pTBuff0 = &TBuff0[0];
}

extern "C" void  pTBuff3_init(void)
{
   pTBuff3_cnt = 0l;
   pTBuff3 = &TBuff3[0];
}


extern "C" void  pTBuff0_control(unsigned long len)
{
 if((pTBuff0_cnt + len) >= ACT_BUFFER_SIZE1)
 {
 pTBuff0_init();
 }
 else
 {
  pTBuff0_cnt += len;
 }
}

extern "C" void  pTBuff3_control(unsigned long len)
{
 if((pTBuff3_cnt + len) >= ACT_BUFFER_SIZE1)
 {
 pTBuff3_init();
 }
 else
 {
  pTBuff3_cnt += len;
 }
}



extern "C" void BlinkLED(long time, long times)		//time - ms; times 
{
      AT91RM9200_PIO_REG_STRUCT_PTR pio_ptr1;
      pio_ptr1 = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
	  for (long n = 0; n < times; n++)
	 {
	  pio_ptr1->CODR = (1 << 13); //(1<<pin);
	  for(long t = 0; t < 1000l; t++ )
	  {
	    delay_mcs(time);
	  }
	  pio_ptr1->SODR = (1 << 13); //(1<<pin);
	  for(t = 0; t < 1000l; t++ )
	  {
	    delay_mcs(time);
	  }
	 }
}





extern "C" void EnableInterrupts()
{


#ifdef USE_PULT
//#ifndef PULT_USART
 /*
#ifdef MAKET_PLATA
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
   				 	 //     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
					 //t	       AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
                //          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }
#endif // MAKET_PLATA  
  */                                       
//#endif //no PULT_USART                                       
#endif //USE_PULT


 #ifdef PROG_BMD34
#ifndef PROG_PU_M710_MUX

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
#endif                                       
#endif //PROG_BMD34 

#ifdef PROG_BMD35
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_BMD35 

#ifdef PROG_PROV
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_PROV 



#ifdef PROG_MPC35
	  
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                 //  		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_MPC35 





#ifdef PROG_KTVM
 
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                   //       AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_KTVM 

#ifdef PROG_DTVM
 
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                   //       AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 

        _at91rm9200_int_enable(AT91RM9200_IRQ1_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                   //       AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }            

#endif //PROG_DTVM 

 

#ifdef PROG_MPC155

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                  			 		      AT91RM9200_AIC_SMR_PRIO_MIN );  	   //t
                   		   		//t	      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_MPC155  

#ifdef PROG_MPC4E

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                  			 		      AT91RM9200_AIC_SMR_PRIO_MIN );  	   //t
                   		   		//t	      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_MPC4E  



#ifdef PROG_BMD155
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   			    //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
			    //        AT91RM9200_AIC_SMR_SRCTYPE_LLS, //high level sensitive   //t

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                			      AT91RM9200_AIC_SMR_PRIO_MIN );  	//100302
//100302                   	  	 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_BMD155 

#ifdef PROG_COMMUTATOR
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   			    //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
			    //        AT91RM9200_AIC_SMR_SRCTYPE_LLS, //high level sensitive   //t

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                			      AT91RM9200_AIC_SMR_PRIO_MIN );  	//100302
//100302                   	  	 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                       
#endif //PROG_BMD155 

#ifdef PROG_BMDN
 //   if(CheckDone())
    if(MirrorTest())
     { 
//	 printfp("\n\r test ok");
  //	 printfpd("\n\r>%d", ret);
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
/*130212   			    //     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
#ifndef PROG_MD310
                        AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
			    //      AT91RM9200_AIC_SMR_SRCTYPE_LLS, //high level sensitive   //t
#else
*/
                     AT91RM9200_AIC_SMR_SRCTYPE_LLS, //new low level sensitive
//					    AT91RM9200_AIC_SMR_SRCTYPE_HLS, //old high level sensitive

 //		              AT91RM9200_AIC_SMR_SRCTYPE_NET, //121221e
//130212 #endif
                		AT91RM9200_AIC_SMR_PRIO_MIN );  
            //    		AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }
     else
     {
 //	  printfp("\n\r test bad");

     }                                       
                                       
#endif //PROG_BMDN 


 

#ifdef PROG_BUKC

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                //   		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                     
#endif //PROG_BUKC 


#ifdef PROG_PRM_PCH

#ifndef PROG_PRM_PCH_SPI
#ifndef PROG_PRM_PCH_N_1
//  091113   if(CheckDone())
//     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
 //    }                                       
#endif //PROG_PRM_PCH_N_1   

#else // PROG_PRM_PCH_SPI
//  091113   if(CheckDone())
//     { 
/*
 if(MirrorTest())
     { 

        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	      AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                        //  AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                     //    AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   	  				      AT91RM9200_AIC_SMR_PRIO_MIN );  
                   		 //			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }  
     */                                     
#endif //PROG_PRM_PCH_SPI   



                                  
#endif //PROG_PRM_PCH 


#ifdef PROG_PRM_PCH_SPI_XIL
 if(MirrorTest())
     { 

	_at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	    //  AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                        //  AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   	  				      AT91RM9200_AIC_SMR_PRIO_MIN );  
									//      AT91RM9200_AIC_SMR_PRIO_MAX );  
     }

#endif


#ifdef PROG_PRM_PCH_DEM
//  091113   if(CheckDone())
//     { 
   //     _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
     //                     AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
               //    					      AT91RM9200_AIC_SMR_PRIO_MIN );  
       //            		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
 //    }                                       
#endif //PROG_PRM_PCH 




#ifdef PROG_PU_M
#ifndef PROG_PU_M710_MUX
#ifndef	PROG_VNV1



//     if(CheckDone())
//ppp
	 if(MirrorTest())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
               //           AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
#ifndef PROG_PU_M710

                        AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
			    //      AT91RM9200_AIC_SMR_SRCTYPE_LLS, //high level sensitive   //t
#else
                      AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
#endif


                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }     
#endif                                       
#endif                                     
#endif //PROG_PU_M 

#ifdef PROG_PU_M_V

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                     
#endif //PROG_PU_M_V 

#ifdef PROG_PU_M_V_A

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                     
#endif //PROG_PU_M_V_A 



#ifdef PROG_UPS
	 /*
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
        */                             
#endif //PROG_UPS 


#ifdef PROG_PU_M100

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                 //  		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                     
#endif //PROG_PU_M100 

#ifdef PROG_PU_MSAT

     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                 //  		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                     
#endif //PROG_PU_M100 






#ifdef PROG_PU_M_MUX
#ifndef PROG_PU_M710_MUX
#ifndef	PROG_VNV1

  // ppp
  //   if(CheckDone())
  	 if(MirrorTest())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     } 
#endif                                           
#endif                                     
#endif //PROG_PU_M_MUX 









 

#ifdef PROG_BUKU
  	
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
                                    
#endif //PROG_BUKU 

#ifdef PROG_PUM
#ifndef PROG_PU_M710_MUX
#ifndef	PROG_VNV1


//rrr
  //    if(CheckDone())
	   if(MirrorTest())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                  // 		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     } 
#endif                                           
#endif                                     
#endif //PROG_PUM  


 
#ifdef PROG_MPC34
 /* not need interrupt
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	 //t     AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                          AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive

                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
               //    					      AT91RM9200_AIC_SMR_PRIO_MIN );  
                   		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
 */                                      
#endif //PROG_MPC34  

 #ifdef PROG_BACO
   /*	
     if(CheckDone())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
   				 	   //   AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
                       //  AT91RM9200_AIC_SMR_SRCTYPE_HLS, //high level sensitive
							AT91RM9200_AIC_SMR_SRCTYPE_NET,  
                //         AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
               //    		 			      AT91RM9200_AIC_SMR_PRIO_MAX ); 
     }                                       
   */                                    
#endif //PROG_BMD34 

                                     
                                        
//   Enable fiq Interrupt at AIC level  
//t   _at91rm9200_int_enable(AT91RM9200_FIQ_VECTOR, FIQ, 
//t   					      AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
//t   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
//  printf("...point1  \n\r");                     
   
   
//t  m_spi_init();
//1e

 //  for(;;)
 //1f
//  m_load_xilinx_IO(); 
//for(;;)

#ifdef PROG_PU_M710_MUX


	 if(MirrorTest())
     { 
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
                      AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
     }                                       
                                     
#endif 

#ifdef	PROG_VNV1

 if(MirrorTest())
     { 
	 printfp("\n\r Interrupts Enabled");
        _at91rm9200_int_enable(AT91RM9200_IRQ0_VECTOR, IRQ, 
                      AT91RM9200_AIC_SMR_SRCTYPE_LLS, //low level sensitive
                   					      AT91RM9200_AIC_SMR_PRIO_MIN );  
     } 
     else
     {
	    printfp("\n\r Interrupts Disabled");

     }                                      
                          



#endif

 //___________________________________

}

  

extern "C" void Test_Xilinx(void)
{
 uint_32 i, counter;
 unsigned char keep1, keep2;
 unsigned char * pN;
 unsigned char * pN1;
 pN =  (unsigned char *)(XILINX_BASE);
 pN1 =  (unsigned char *)(XILINX_BASE);
 pN1++;
 unsigned char fail = 0;
 counter = 0;
#ifndef USART0_TRY_PDC_1T 
 printf("\n\r> Test of Xilinx");
 #endif
 for(i = 0; i < (((uint_32)XILINX_SIZE) - 1); i++)
 {
   keep1 = *pN;
   *pN = 0x55;
   keep2 = *pN1;
   *pN1 = 0xAA;
   if(*pN != 0x55) 
   {
   counter++;
   fail = 1;
    if(counter < 10)
	{
#ifndef USART0_TRY_PDC_1T
   printf("\r\n> Error: address:  %lX need : 0x55  read : %X", pN, *pN);
#endif
}
   }
  if(*pN1 != 0xAA) 
   {
   counter++;
    fail = 1;
	 if(counter < 10)
	 {
#ifndef USART0_TRY_PDC_1T
     printf("\r\n> Error: address:  %lX need : 0xAA  read : %X", pN1, *pN1);
#endif
}
   }
   *pN++ = keep1;
   *pN1++ = keep2;
  }

 pN =  (unsigned char *)(XILINX_BASE);
 pN1 =  (unsigned char *)(XILINX_BASE);
 pN1++;


for(i = 0; i < (((uint_32)XILINX_SIZE) - 1); i++)
 {
   keep1 = *pN;
   *pN = 0xAA;
   keep2 = *pN1;
   *pN1 = 0x55;
   if(*pN != 0xAA) 
   {
   counter++;
   fail = 1;
    if(counter < 10)
	{
#ifndef USART0_TRY_PDC_1T
     printf("\r\n> Error: address:  %lX need : 0xAA  read : %X", pN, *pN);
#endif
}
   }
  if(*pN1 != 0x55) 
   {
   counter++;
    fail = 1;
	 if(counter < 10)
	 {
#ifndef USART0_TRY_PDC_1T
     printf("\r\n> Error: address:  %lX need : 0x55  read : %X", pN1, *pN1);
#endif
}
   }
   *pN++ = keep1;
   *pN1++ = keep2;
  }
 if(!fail)
	{
#ifndef USART0_TRY_PDC_1T
	  printf("\r\n Test Ok!");
#endif
	}
	else
	{
#ifndef USART0_TRY_PDC_1T
	 printf("\r\n Test Failed!");
     printf("\r\n Errors : %ld", counter);
#endif
	}
}
   

extern "C" char Test_NVRAM(void)
{
 uint_32 i, counter;
 unsigned char keep1, keep2;
 unsigned char * pN;
 unsigned char * pN1;
 pN =  (unsigned char *)(NVRAM_BASE);
 pN1 =  (unsigned char *)(NVRAM_BASE);
 pN1++;
 unsigned char fail = 1;
 counter = 0;
 
// printf("\n\r> Test of NVRAM");
 for(i = 0; i < (((uint_32)NVRAM_SIZE - CLOCK_REGISTERS)); i++)
 {
   keep1 = *pN;
   *pN = 0x55;
   keep2 = *pN1;
   *pN1 = 0xAA;
   if(*pN != 0x55) 
   {
   counter++;
   fail = 0;
   // if(counter < 10)
  // printf("\r\n> Error: address:  %lX need : 0x55  read : %X", pN, *pN);
   }
  if(*pN1 != 0xAA) 
   {
   counter++;
    fail = 0;
   //	 if(counter < 10)
 //    printf("\r\n> Error: address:  %lX need : 0xAA  read : %X", pN1, *pN1);
   }
   *pN++ = keep1;
   *pN1++ = keep2;
  }
  /*
 pN =  (unsigned char *)(NVRAM_BASE);
 pN1 =  (unsigned char *)(NVRAM_BASE);
 pN1++;


for(i = 0; i < (((uint_32)NVRAM_SIZE - CLOCK_REGISTERS)); i++)
 {
   keep1 = *pN;
   *pN = 0xAA;
   keep2 = *pN1;
   *pN1 = 0x55;
   if(*pN != 0xAA) 
   {
   counter++;
   fail = 1;
   // if(counter < 10)
   //  printf("\r\n> Error: address:  %lX need : 0xAA  read : %X", pN, *pN);
   }
  if(*pN1 != 0x55) 
   {
   counter++;
    fail = 1;
	// if(counter < 10)
    // printf("\r\n> Error: address:  %lX need : 0x55  read : %X", pN1, *pN1);
   }
   *pN++ = keep1;
   *pN1++ = keep2;
  }
	   */
  //	if(!fail)
  //	{
 //	  printf("\r\n Test Ok!");
  //	  return 1;
  //	}
 //	else
   //	{
  //	 printf("\r\n Test Failed!");
  //   printf("\r\n Errors : %ld", counter);
	//}
   //	return 0;
   return fail;
}


//int count1;

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _irq0_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 IRQ0 ISR handler.
*
*END*----------------------------------------------------------------------*/

extern "C" void _irq0_isr
   (
         pointer dummy
   )
{ 
//#ifndef PROG_BMDN
         my_int_disable_irq0();
//#else
//		 _int_disable(); //121120
//#endif

  
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = 
                                     (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;

/*
   #ifdef IncEmbSerialMD34AVT
   if(TestMode.Value != 2l)
    { emb_use_irq0(); }
	else {
	#ifdef PROG_BMD34
 //	 test_PU37_interrupt_ovner();
	  emb_use_irq0();
	#endif //  PROG_BMD34

    #ifdef PROG_BMD35
 // test_PU37_interrupt_ovner();
	    emb_use_irq0();  //090605
	#endif //  PROG_BMD35

   #ifdef PROG_PROV
  //090605 test_PU37_interrupt_ovner();
	    emb_use_irq0();  //090605
	#endif //  PROG_PROV


    #ifdef PROG_MPC35
 //	 test_PU37_interrupt_ovner();
	  emb_use_irq0();  //090605

	#endif //  PROG_MPC35

 	#ifdef PROG_MPC155
 //	 test_PU37_interrupt_ovner();
	  emb_use_irq0();  //090605
	#endif //  PROG_MPC155

 	#ifdef PROG_MPC4E
 //	 test_PU37_interrupt_ovner();
	  emb_use_irq0();  //090605
	#endif //  PROG_MPC4E





#ifdef PROG_BMD155
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_BMD155

#ifdef PROG_PRM_PCH_N
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_BMD155


#ifdef PROG_BMDN
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_BMDN


#ifdef PROG_PRM_PCH
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH

#ifdef PROG_PRM_PCH_DEM
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH


#ifdef PROG_PU_M_MUX
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH

#ifdef PROG_PU_M
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH

#ifdef PROG_PU_M_V
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH



#ifdef PROG_PU_M100
//	 test_PU37_interrupt_ovner();
	   emb_use_irq0();  //090605
#endif //  PROG_PRM_PCH






	IntFlag |= INT0_FLAG;
	}

   #endif //IncEmbSerialMD34AVT
	*/
//#ifdef IncEmbSerialACT155
   //t	 emb_use_irq0();
//__________________________________________
// if(TestMode.Value != 2l)
//    {

     emb_use_irq0(); 
//    }
//	else
//	 {
// #ifdef PROG_PU_M	 	
//	  test_PU37_interrupt_ovner();
//#endif // PROG_PU_M		  	

// #ifdef PROG_PU_M_MUX	 	
//	  test_PU37_interrupt_ovner();
//#endif // PROG_PU_M_MUX		

//	  }
	//__________________________________________
 //  #endif  // IncEmbSerialACT155
	 /*
   #ifdef PROG_KTVM
	 emb_use_irq0();
   #endif  // PROG_KTVM

   #ifdef PROG_DTVM
	 emb_use_irq0();	  //? may be enover on irq 0
   #endif  // PROG_DTVM

	   */

   _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
    Stephany11++;
  //	count1++;
    /* End of Interrupt */
	aic_ptr->EOICR = 0xFF; 
}

/*
extern "C" void TestMF20(void)
{
 

 //printf("\rTest MF20 %4ld\n\r", Stephany14);
 static char tb;
 unsigned char slw[16], slr[16];
 int slot = 0;
 int i;
 if(Stephany14 == 0)
 {
	tb = 0;
 }

 for(i = 0; i <16; i++)
 {
 //slw[i] = 0x55;
 //slw[i] = i;
 slw[i] = i + tb;
 outportb(0x500+i*16,slw[i]);
 }
 // printf("\r");
  for(i = 2; i <= 8; i+=2)
 {
  slr[i] = inportb(0x500+i*16);
  if( slr[i] != slw[i])	printf("\n\rError!\n\r");
 // printf("%1X:%02X ",i, slr[i]);
 }
//  printf("\r");

 tb++;
 Stephany14++; 
}
*/

extern "C" void SetBufferState(unsigned long tmp)
{
 uint_32 tmp1 =  (uint_32)SBuffersState.Value;
 tmp1 |= tmp;
 SBuffersState.Value = (float64)tmp1;
}

extern "C" void ClearBufferState(unsigned long tmp)
{
// return; //t
 uint_32 tmp1 =  (uint_32)SBuffersState.Value;
// printf("\n\r Start : tmp1 = %X", tmp1);
// printf("\n\r~tmp  = %X", ~tmp);
 tmp1 &= ~tmp;
// printf("\n\rtmp1 = %X", tmp1);

 SBuffersState.Value = (float64)tmp1;
}

extern "C" boolean CompareBufferState(unsigned long tmp)
{
 uint_32 tmp1 =  (uint_32)SBuffersState.Value;
 if(tmp1 & tmp) return TRUE;
 else return FALSE;
}



extern "C" char CheckNWait(void)
{
  char ret = 0;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 6, AT91RM9200_PIO_PERIPHERAL_IO, 0);
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x40)	 ret = 1;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 6, AT91RM9200_PIO_PERIPHERAL_A, 1);

  return ret;
}

extern "C" char CheckDoneShort(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;



 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//to hello.c _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0); //110222    //line done
 
 // delay_mcs(10000l); //delay to have current level

// return 0; //for test 110222


 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK);
  }
  return ret;
}

extern "C" char CheckDoneShort2(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x10l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK2);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK2);
  }
  return ret;
}

extern "C" char CheckDoneShort3(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK3);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK3);
  }
  return ret;
}

extern "C" char CheckDoneShort4(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK4);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK4);
  }
  return ret;
}





extern "C" char CheckDone(void)
{
 char ret = 0;
 if(TestMode.Value == 0x27) return	1; //not need reload xilinx
  if(TestMode.Value == 0x8e) return	1; //not need reload xilinx

 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t22
// my_printf((unsigned char)status); //t22

 uint_32 tmp = (uint_32)DONE_OK;
 uint_32 tmp1 =  (uint_32)SBuffersState.Value;
 if(status & 0x20)
 {
  DoneWaitCounter = 0l;
  tmp1 |= tmp;
  ret = 1;
 }
 else
 {
    tmp1 &= ~tmp;
  if(DoneWaitCounter > DONE_DELAY)
  {
#ifndef WITHOUT_XILINX 
  m_load_xilinx3((char)XILINXPG, 1);
#endif

  DoneWaitCounter = 0l;
  #ifdef PROG_BMD34
  Init_BMD34();
  #endif //PROG_BMD34  

 #ifdef PROG_BMD35
  Init_BMD35();
  #endif //PROG_BMD35  

 #ifdef PROG_PROV
  Init_PROV();
  #endif //PROG_BMD35 

#ifdef PROG_MPC35
  Init_MPC35();
#endif //PROG_MPC35 


 #ifdef PROG_KTVM
 ktvm_init();  //init remote buffers of MF20
  #endif //PROG_KTVM  

 #ifdef PROG_DTVM
   dtvm_init();  //init remote buffers of MF20
  #endif //PROG_DTVM  



  #ifdef PROG_MPC155
  if(CheckDoneShort())
  {
  Init_MPC155();
  }
  #endif //PROG_MPC155  

  #ifdef PROG_MPC4E
 // if(CheckDoneShort())
 // {
  Init_MPC4E();
//  }
  #endif //PROG_MPC4E  






  #ifdef PROG_BUKC
  Init_BUKC();
  #endif //PROG_BUKC  

 #ifdef PROG_PRM_PCH
#ifndef	 PROG_PRM_PCH_SPI_ETH_UART
  Init_PRM_PCH();
#endif
  #endif //PROG_PRM_PCH  

  #ifdef PROG_PU_M
  Init_PU_M();
  #endif //PROG_PU_M 
  
  #ifdef PROG_PU_M_V
  Init_PU_M();
  #endif //PROG_PU_M  

  #ifdef PROG_PU_M_V_A
  Init_PU_M();
  #endif //PROG_PU_M  


  #ifdef PROG_UPS
  Init_UPS();
  #endif //PROG_UPS  

   

  #ifdef PROG_PU_M100
  Init_PU_M();
  #endif //PROG_PU_M100  

  #ifdef PROG_PU_MSAT
  Init_PU_M();
  #endif //PROG_PU_M100  



 #ifdef PROG_PU_M_MUX
  Init_PU_M();
  #endif //PROG_PU_M_MUX  




  #ifdef PROG_BUKU
   Init_BUKC();
  #endif //PROG_BUKU  

   #ifdef PROG_PUM
  Init_BUKC();
  #endif //PROG_PUM  




  #ifdef PROG_BMD155
  Init_BMD155();
  #endif //PROG_BMD155 
  
  #ifdef PROG_COMMUTATOR
  Init_COMMUTATOR();
  #endif //PROG_BMD155 
  
  
   

  #ifdef PROG_BMDN
  Init_BMDN();
  #endif //PROG_BMDN



  #ifdef PROG_MPC34
  Init_MPC34();
  #endif //PROG_MPC34 

  #ifdef PROG_MF20  
  #ifndef PROG_BACO
  mf20_init();  //init remote buffers of MF20
  #else
  baco_init(); 
  #endif
  #endif //PROG_MF20  

  #ifdef PROG_TUTS  
  TUTS_init();  //init remote buffers of MF20
  #endif //PROG_TUTS  



  }
  else
  {
   DoneWaitCounter++;
  }


  }
 SBuffersState.Value = (float64)tmp1;
#ifdef TDONE
printfpd("\n\r checkdone : %d", ret);
#endif

 return ret;
}

 extern "C" void RestartAutoNeg(void)
{
  AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
   uint_16 		status;
  uint_16 		status1;

   
   emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;

    if(_mii_read_reg(emac_ptr, BSP_PHY_ADDR, 0, &status) != TRUE) //0 - PHY_DM9161_BASIC_MODE_CONTROL_REG
   {
    //   printf("\n\r Can't Read Status");
	   return;
   }
 //  else 
 //  {
 //   printf("\n\r BMCR: %X", status);
 
  // }
  //	 printf("\n\rWrite Status");
 //  status1 = status | 0x1200;   //restart autoneg	   3100 - default
 //  status1 = status | 0x8000;   //softvare restart 
   status1 = status | 0x9200;   //softvare restart 
   if(_mii_write_reg(emac_ptr, BSP_PHY_ADDR, 0, &status1) != TRUE)
   {
 //	   printf("\n\r not Can't Write Status");
   }



//	status1 =  0x3300;
//    status1 =  0xB300;
//   _mii_write_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_BASIC_MODE_CONTROL_REG, &status1);


 //	 _mii_read_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_BASIC_MODE_CONTROL_REG, &status);
 //	  printf("\n\r BMCR: %X", status);
 //	 _mii_read_reg(emac_ptr, BSP_PHY_ADDR,  PHY_DM9161_BASIC_MODE_STATUS_REG, &status);
 //	 printf("\n\r BMSR: %X", status);		   //786d - ok 7849 - bad

  //	 if( status & 0x8) //able to perform autoneg	 
  //	 {
  //  status1 =  0x3300;
  // _mii_write_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_BASIC_MODE_CONTROL_REG, &status1);
  //   }


	  

}

#define   PHY_DM9161_BMCR  (0)
#define   STATE_10M		   (0)

extern "C" void SetLink10(void)
{

 AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
//   uint_16 		status;
   
   emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;

//   if(_mii_read_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_CONFIG_STATUS_REG, &status) != TRUE)
//   {
 // printf("\n\r not Can Read Status");
//   return 99;
//   }

//boolean
 _mii_write_reg
   (
      /* [IN] pointer to EMAC registers */
      /*AT91RM9200_EMAC_REG_STRUCT_PTR */ emac_ptr,

      /* [IN] Addess of the PHY to be written */
    /*  uint_32       phy*/   BSP_PHY_ADDR,
      
      /* [IN] Register to write to */
     /* uint_32       reg*/ PHY_DM9161_BMCR,
      
      /* [IN] address to the value to be written */
     /* uint_16 _PTR_ data	 */	 STATE_10M
   );




}


extern "C" int CheckLink(void)
{
 // AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
 //  uint_16 		status;
 //  emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
//   if(_mii_write_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_CONFIG_STATUS_REG, &status) != TRUE)
  AT91RM9200_EMAC_REG_STRUCT_PTR     emac_ptr;
   uint_16 		status;
   
   emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;

   if(_mii_read_reg(emac_ptr, BSP_PHY_ADDR, PHY_DM9161_CONFIG_STATUS_REG, &status) != TRUE)
   {
 // printf("\n\r not Can Read Status");
   return 99;
   }
   else if(!(status & PHY_DM9161_CONFIG_STATUS_AN_SUCCESS))
   {
    return 0;
   }
   else if((status & (PHY_DM9161_CONFIG_STATUS_100FDX | PHY_DM9161_CONFIG_STATUS_100HDX)))
   {
	 return 100;
   }
   else
   {
   return 10;
   }

    
}



extern "C" void Support_Ethernet_10MBit(void)
{
//  uint_32 speed;
  uint_32 status32;
  AT91RM9200_EMAC_REG_STRUCT_PTR emac_ptr;
  emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
  status32	= (emac_ptr->CFG);
 // if(!CheckLink())
 // {
//  }
//   RestartAutoNeg(); //t
   speed = CheckLink();//_bsp_enet_get_speed();	//previons
 //  printf("\n\r speed: %d \n\r", speed);
   if(!speed)//not have link	 speed  = 0
   {
// 	printf("\n\r Not Have link!, speed = %d \n\r", speed);
 	SetBufferState((unsigned long)NO_LINK);
	autoneg_counter++;
	if(autoneg_counter > RESTART_LINK_DELAY)
	{
	autoneg_counter = 0;
	RestartAutoNeg();

	}
 //	RestartAutoNeg();
   }
   else
   {
   ClearBufferState((unsigned long)NO_LINK);
   }


   if((speed == 10l) && (status32 & AT91RM9200_EMAC_CFG_SPEED_100))
  {
  autoneg_counter = 0;
 //  my_printf((unsigned char)speed);
 //  my_printf((unsigned char)(status32 >> 8));
 //  my_printf((unsigned char)(status32));

   status32 &= ~AT91RM9200_EMAC_CFG_SPEED_100;
   emac_ptr->CFG =  status32;
 //  ClearBufferState((unsigned long)NO_LINK);
   }
   else	 if((speed == 100l) && (!(status32 & AT91RM9200_EMAC_CFG_SPEED_100)))
   {
   autoneg_counter = 0;
 //  my_printf((unsigned char)speed);
 //  my_printf((unsigned char)(status32 >> 8));
 //  my_printf((unsigned char)(status32));
   status32 |= AT91RM9200_EMAC_CFG_SPEED_100;
   emac_ptr->CFG =  status32;
//   ClearBufferState((unsigned long)NO_LINK);
   }

   else if(speed == 0l)//not have link	 speed  = 0
   {
 //	printf("\n\r Not Have link!, speed = %d \n\r", speed);
 	SetBufferState((unsigned long)NO_LINK);
 //	RestartAutoNeg();
   }
// PrintStatus();
}


#ifndef PROG_BUKU
#ifndef PROG_TUTS
#ifndef PROG_MF20
#ifndef PROG_BMD34
#ifndef PROG_BMD35
#ifndef PROG_MPC35
#ifndef PROG_PROV

#ifndef PROG_MPC34
#ifndef PROG_BMD155
#ifndef PROG_COMMUTATOR
#ifndef PROG_BMDN
#ifndef PROG_BUKC
#ifndef PROG_PRM_PCH
#ifndef PROG_PRM_PCH_DEM

#ifndef PROG_UPS
#ifndef PROG_PU_M_V
#ifndef PROG_PU_M_V_A
#ifndef PROG_PU_M
#ifndef PROG_PU_M100
#ifndef PROG_PU_M_MUX
#ifndef PROG_PUM
#ifndef PROG_MPC155
#ifndef PROG_MPC4E
#ifndef PROG_KTVM   
#ifndef PROG_DTVM 
#ifndef PROG_PU_MSAT

extern "C" void time_notify_core() //my
{
  //hier dummu	it was inenover .cpp
}
#endif
#endif //no PROG_DTVM
#endif //no PROG_KTVM
#endif // PROG_MPC4E
#endif  //no PROG_MPC155
#endif  //no PROG_PU_M
#endif  //no PROG_PU_M_V
#endif  //no PROG_PU_M_V_A

#endif  //no PROG_UPS


#endif  //no PROG_PU_M100
#endif  //no PROG_PU_M_MUX
#endif  //no PROG_BUKC
#endif //no PROG_PRM_PCH
#endif //no PROG_PRM_PCH_DEM

#endif  //no PROG_PUM
#endif  //no PROG_BMDN
#endif  //no PROG_BMD155
#endif  //no PROG_BMD155

#endif  //no PROG_MPC34
#endif  //no PROG_BMD35
#endif  //no PROG_PROV

#endif  //no PROG_MPC35
#endif  //no PROG_BMD34
#endif //no PROG_MF20
#endif //no PROG_TUTS
#endif //no PROG_BUKU

extern "C" void Jump(void *);
//extern "C" TestJump(void)
//{
//char c = 0;
//for(;;)
//my_printf(c++);
//}

/*
extern "C" void LoadAndJump()
{

  jumpbuff = (JUMPBUFF *)(0x21100000); //start at 17M 
  void * testaddr = (void *)0x20000f20;
  usart_command_eth_on();
//RTCS_exec_TFTP_BIN((_ip_address)0x9B9B9B9D,"prog_test.bin", (uchar_ptr)jumpbuff, (uchar_ptr)jumpbuff);
  RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"prog_test.bin", (uchar_ptr)&TFTP_Buffer[0]);
usart_select(0); //debug uart on
my_int_disable();
wd_deinit();
 Jump(&TFTP_Buffer[0]);
}
 */

#define START_SWEEP (0x60)
#define STEP_TO_COMPARE (9000000)


extern "C" unsigned char CompareBuffers(unsigned long size, unsigned cnt)
{
unsigned char ret = 0;

for(unsigned i = 0; i < 10; i++)
 {
	printfpd("\n\r %X : ", TFTP_Buffer[i+ 0x60  + (STEP_TO_COMPARE * cnt)]);
	printfpd("---  %X : ", TFTP_Buffer1[i]);
}

 for( i = 0; i < size; i++)
 {
   //	printfpd("\n\r %X : ", TFTP_Buffer[i+ 0x60  + (STEP_TO_COMPARE * cnt)]);
   //	printfpd("---  %X : ", TFTP_Buffer1[i]);



 if(TFTP_Buffer[i+ 0x60  + (STEP_TO_COMPARE * cnt)] != 	TFTP_Buffer1[i])
  {
   printfpd("\n\r %d : ", i+ 0x60  + (STEP_TO_COMPARE * cnt));
   printfpd(" %d  ", TFTP_Buffer[i+ 0x60  + (STEP_TO_COMPARE * cnt)]);
   printfpd("!=  %d  ", TFTP_Buffer1[i]);
   ret = 1;
    return ret;
  }
 }
 return ret;
}

#define STEP_TO_COMPARE (9000000)

extern "C" void CompareToFile(unsigned long CompareVolume)
{
int err;
 unsigned cnt = 0; 
 unsigned char flag = 0;
 printfp("\n\rCompare start....");
 while(CompareVolume)
 {
 wd_reset();

 if(flag) break;

 if(CompareVolume > XilSizeToDownloadD)
 {
 CompareVolume -= STEP_TO_COMPARE;
 err = read_dataflash ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS1 + (STEP_TO_COMPARE * cnt),
//  (unsigned int)XilSizeToDownloadD, (uchar_ptr)&TFTP_Buffer1[0]);
  (unsigned int)TFTP_BUFFER_SIZE1, (uchar_ptr)&TFTP_Buffer1[0]);

  if(err !=	1)
  {

 printfp("\n\rwrong read_dataflash....");
 }

 flag = CompareBuffers(STEP_TO_COMPARE, cnt);
 cnt++;

 }
 else
 {

  err = read_dataflash ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS1 + (CompareVolume * cnt), (unsigned int)XilSizeToDownloadD, (uchar_ptr)&TFTP_Buffer1[0]);

    if(err !=	1)
  {

 printfp("\n\rwrong read_dataflash1....");
 }
 for(unsigned i = 0; i < 90; i++)
 {
  //	printfpd("\n\r %X : ", TFTP_Buffer[i+ 0x60]);
  if(!(i%16)) printfp("\n\r");
	printfpd(" %02X ", TFTP_Buffer1[i]);
}

 flag = CompareBuffers(CompareVolume, cnt);
 CompareVolume = 0;
 }
 }
  
  if(!flag)
 printfp("\n\r....Compare ok!");

//  TestWriteFlash5(); //temporary

}

extern "C" void CompareToFilecs2(unsigned long CompareVolume)
{
 unsigned cnt = 0; 
 unsigned char flag = 0;
 printfp("\n\rCompare start....");
 while(CompareVolume)
 {
 wd_reset();

 if(flag) break;

 if(CompareVolume > XilSizeToDownloadD)
 {
 CompareVolume -= STEP_TO_COMPARE;
 read_dataflash ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS2 + (STEP_TO_COMPARE * cnt), (unsigned int)XilSizeToDownloadD, (uchar_ptr)&TFTP_Buffer1[0]);
 printfp("\n\rread_dataflash2....");

 flag = CompareBuffers(STEP_TO_COMPARE, cnt);
 cnt++;

 }
 else
 {

 read_dataflash ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS2 + (CompareVolume * cnt), (unsigned int)XilSizeToDownloadD, (uchar_ptr)&TFTP_Buffer1[0]);

   printfp("\n\rread_dataflash2....");

 for(unsigned i = 0; i < 100; i++)
 {
  //	printfpd("\n\r %X : ", TFTP_Buffer[i+ 0x60]);
  if(!(i%16)) printfp("\n\r");
	printfpd(" %02X ", TFTP_Buffer1[i]);
}

 flag = CompareBuffers(CompareVolume, cnt);
 CompareVolume = 0;
 }
 }
  
  if(!flag)
 printfp("\n\r....Compare ok!");

//  TestWriteFlash5(); //temporary

}


#ifdef XIL_FLASH

extern "C" unsigned char CompareBuffersx(unsigned long size, unsigned cnt)
{
unsigned char ret = 0;
   printfp("\n\rCompareBuffersx size=");
   printfpd("%d  \n\r", size);
   

/*
 printfp("\n\r TFTP_Buffer1: \n\r");


for(unsigned long i = 0; i < size; i++)
 {
  //	printfpd("\n\r %X  ", TFTP_Buffer[i  + (STEP_TO_COMPARE * cnt)]);
  if(!i%16) printfp("\n\r1>");

	printfpd(" %02X  ", TFTP_Buffer1[i]);

} 
  printfp("\n\r TFTP_Buffer: \n\r");
for( i = 0 + 96; i < size + 96; i++)
 {
  //	printfpd("\n\r %X  ", TFTP_Buffer[i  + (STEP_TO_COMPARE * cnt)]);
  if(!i%16) printfp("\n\r0>");

	printfpd(" %02X  ", TFTP_Buffer[i]);

}
   
	 */


 for(unsigned i = 0; i < size; i++)
 {
   //	printfpd("\n\r %X : ", TFTP_Buffer[i+ 0x60  + (STEP_TO_COMPARE * cnt)]);
   //	printfpd("---  %X : ", TFTP_Buffer1[i]);



 if(TFTP_Buffer[i  + (STEP_TO_COMPARE * cnt) + 96] != 	TFTP_Buffer1[i])
  {
   printfpd("\n\r %d : ", i  + (STEP_TO_COMPARE * cnt));
   printfpd(" %d  ", TFTP_Buffer[i + 96 + (STEP_TO_COMPARE * cnt)]);
   printfpd("!=  %d  ", TFTP_Buffer1[i]);
   ret = 1;
    return ret;
  }



 }
 return ret;
}


//#define STEP_TO_COMPAREX (20000)

extern "C" void CompareToFilex(unsigned long CompareVolume)
{
 unsigned cnt = 0; 
 unsigned char flag = 0;
 printfp("\n\rCompare start....");
 OperateBuffers_usart0t();

 while(CompareVolume)
 {
 wd_reset();

 if(flag) break;

 if(CompareVolume > STEP_TO_COMPARE)
 {
 CompareVolume -= STEP_TO_COMPARE;
 read_dataflashx((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X+VER_OFFSET + (STEP_TO_COMPARE * cnt), (unsigned int)STEP_TO_COMPARE, (uchar_ptr)&TFTP_Buffer1[0]);
 flag = CompareBuffersx(STEP_TO_COMPARE, cnt);
 cnt++;

 }
 else
 {
  printfp("\n\rstart read flashx...");

 read_dataflashx ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X+VER_OFFSET + (CompareVolume * cnt), (unsigned int)CompareVolume, (uchar_ptr)&TFTP_Buffer1[0]);
 printfp("\n\rfinish read flashx...");

 flag = CompareBuffersx(CompareVolume, cnt);
 CompareVolume = 0;
 }
 }

if(!flag)
{
 printfp("\n\r....Compare ok!");
 }
 else
 {
   printfp("\n\r....Compare wrong!");
 }


}




#endif

#ifdef PROG_DMU6

extern "C" void TestWriteFlash5(void)
{

 printfpd("\n\rTestWriteFlash5 size : %d", XilSizeToDownloadD);
 printfpd("addr : 0x%08X", XilSizeToDownloadD);

// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];

// unsigned long j = 0;
//  for(j = 0; j < END_ADDR; j += TEST_DATA_SIZE)
 // for(j = 0; j < TEST_DATA_SIZE; j += TEST_DATA_SIZE)
//  {
  for(unsigned i = 0; i < XilSizeToDownloadD; i++)
  {
   TFTP_Buffer[i]  = 0x99;
  }

   for( i = 0; i < 16; i++)
//   for( i = 0; i < 10000; i++)
  {
   ToPdcTu0('.');
	//   delay_mcs(10);
	   OperateBuffers_usart0t();

     }


  //t	  write_da  //t	  write_daAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);

  //	  read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1 + (unsigned long)END_ADDR - TEST_DATA_SIZE , TEST_DATA_SIZE, &TestR[0]);
   read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, XilSizeToDownloadD, &TFTP_Buffer[0]);

   delay_mcs(100000);

 //  for( i = 0; i < XilSizeToDownloadD; i++)
//   for( i = 0; i < 10000; i++)
   // for( i = 0; i < 20000; i++)
    for( i = 0; i < 200; i++)
  {
   if(!(i % 256))
    {    OperateBuffers_usart0t();  wd_reset();
 //  delay_mcs(1000000);
   delay_mcs(100000);
  //  wd_reset();

   }


 //  printfpd("\n\r %X >", (i + j));
  // printfpd("X", TFTP_Buffer[i]);
//   OperateBuffers_usart0t();
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
 ToPdcTu0(TFTP_Buffer[i]);

  }
//   OperateBuffers_usart0t();
//   delay_mcs(10000);
 //  wd_reset();

// ToPdcTu0(TFTP_Buffer[i]);
  for( i = 0; i < 16; i++)
//   for( i = 0; i < 10000; i++)
  {
   ToPdcTu0('.');
	//   delay_mcs(10);
	   OperateBuffers_usart0t();

     }


 // }
// ToPdcTu0(TFTP_Buffer[i]);
 printfp("\n\n\n\r F I N I S H \n\n\n\r");

}



extern "C" void CopyBuffers(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
 char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];

  for(unsigned i = 0; i < 90; i++)	 //need header only
 //  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
   *pBuff1++ = *pBuff++; // TFTP_Buffer1[i]  =  TFTP_Buffer[i];

 //  if(!(i % 16))
//   printfpd("\n\r %X >", i);
//   printfpd(" %02X", TFTP_Buffer[i]);

  }

  	//  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);
 	/*
    read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, TEST_DATA_SIZE, &TestR[0]);
   for( i = 0; i < TEST_DATA_SIZE; i++)
  {
  if(!(i % 16))
   printfpd("\n\r %X >", i);
   printfpd(" %02X", TestR[i]);
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
  }
   */
}

#endif

#define  TEST_DATA_SIZE		(1024)

extern "C" void InvertBitOrdering(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
// char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];
 unsigned char ByteBuff;
 unsigned char ByteBuff1;

//  for(unsigned i = 0; i < XilSizeToDownloadD_VNV; i++)	 //need header only
  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
   ByteBuff = *pBuff; // TFTP_Buffer1[i]  =  TFTP_Buffer[i];
   ByteBuff1 = 0;
   if(ByteBuff & MASK_BIT_0)  (ByteBuff1 |= MASK_BIT_7);
   if(ByteBuff & MASK_BIT_1)  (ByteBuff1 |= MASK_BIT_6);
   if(ByteBuff & MASK_BIT_2)  (ByteBuff1 |= MASK_BIT_5);
   if(ByteBuff & MASK_BIT_3)  (ByteBuff1 |= MASK_BIT_4);
   if(ByteBuff & MASK_BIT_4)  (ByteBuff1 |= MASK_BIT_3);
   if(ByteBuff & MASK_BIT_5)  (ByteBuff1 |= MASK_BIT_2);
   if(ByteBuff & MASK_BIT_6)  (ByteBuff1 |= MASK_BIT_1);
   if(ByteBuff & MASK_BIT_7)  (ByteBuff1 |= MASK_BIT_0);
   *pBuff++ = ByteBuff1;
  
 //  if(!(i % 16))
//   printfpd("\n\r %X >", i);
//   printfpd(" %02X", TFTP_Buffer[i]);

  }

  	//  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);
 	/*
    read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, TEST_DATA_SIZE, &TestR[0]);
   for( i = 0; i < TEST_DATA_SIZE; i++)
  {
  if(!(i % 16))
   printfpd("\n\r %X >", i);
   printfpd(" %02X", TestR[i]);
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
  }
   */
}






  /*
#ifdef PACK_CFG

extern "C" void PackCfg()
{

}

#endif
  */
#ifdef	PROG_VNV1
//#ifndef STM2UDP
//#include operatefile_vnv.cpp
//#else
//#include operatefile_stm2udp.cpp
//#endif
#else

extern "C" void OperateFile()
{
 printfp1("\n\r Operate File");
 OperateBuffers_usart1t();
 AT91F_DataflashInit ();
//_________________________for tftp loader
 _ip_address server;
  char_ptr filename;
//_________________________for flash writer
  unsigned long addr_dest, operation;
  unsigned int addr_src;
  unsigned int size;
  unsigned int size1;

  signed char errorw = 1;
  unsigned i;

#ifdef PACK_CFG
unsigned short num_cfg_file;
unsigned char config_flag = 0; 
#endif
  char bufstop[] = "1234567890";
  char * stopstring;
  uint_32 keep;
  stopstring = &bufstop[0];
  #define BUFFNAMESIZE (50)
  #define ENABLED_BUFFNAMESIZE (8)

  char BuffName[BUFFNAMESIZE]; 
  #define BUFFSIZESIZE (9)
  char BuffSize[BUFFSIZESIZE];
   uint_32 cnt, getpoint, error;
  #define IPADDRSIZE (9)
  getpoint = 0; 
  server = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);
  getpoint = (uint_32)IPADDRSIZE;
  for(cnt = 0; cnt < (BUFFNAMESIZE - 1); cnt++)
  {
	 if(FileUpdate.Value[cnt + getpoint] == '-') break;
	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
	  else {BuffName[cnt] =  FileUpdate.Value[cnt + getpoint];}
  }
  if(cnt > (ENABLED_BUFFNAMESIZE + 2)) //have symbols "-" 
  {
	  return; //tftp do not work witch long names
  }

  BuffName[cnt] =  '\0';
  filename = &BuffName[0];
  getpoint += (cnt + 1); 
  for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
  }
    BuffSize[cnt] =  '\0';
    size =  strtoll(&BuffSize[0], &stopstring,10);

//#ifdef PROG_BCM
    size = BIG_PROG_SIZE;
   printfp1("\n\r..............set prog size = BIG_PROG_SIZE; !!!!");
//#endif


  if(size > TFTP_BUFFER_SIZE)  return;
 
  getpoint += (cnt + 1);
   for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
  }
    BuffSize[cnt] =  '\0';
   addr_dest =  strtoll(&BuffSize[0], &stopstring,16);

//   #ifdef PACK_CFG
//   printfpd1("\n\rad:0x%08X", addr_dest);
//  #endif
   getpoint += (BUFFSIZESIZE);
   operation = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);
   addr_src = (unsigned int)&TFTP_Buffer[0];
   //need get off watch dog.
 //   RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"hello7.bin", (uchar_ptr)&TFTP_Buffer[0]);
   usart_command_eth_on();
   UsedExp.State.Reg1.bit.UCDE = 0; //usart not can now disable ethernet
   keep = (uint_32)SBuffersState.Value;
   keep |= (uint_32)TFTP_PROCEED;
   keep &= ~((uint_32)FILE_WRITE_OK);
   SBuffersState.Value = (float64)keep;
   error = RTCS_load_TFTP_BIN(server,filename, (uchar_ptr)&TFTP_Buffer[0]);
   UsedExp.State.Reg1.bit.UCDE = 1; //now usart can disable ethernet
   if(error)
  {
  	 keep &= ~((uint_32)TFTP_PROCEED);
     SBuffersState.Value = (float64)keep;
	 printfp1("\n\r ...Error of TFTP load");
   	 OperateBuffers_usart1t();
     return; //to not write bad loading
   }
  	wd_reset();
	if(operation == 1l)	  //write file
	{
 printfpd1("\n\rad 0x%x", addr_dest);
 printfpd1("\n\rx1 0x%x", XilFileDataAddressD - 0x20);
 printfpd1("\n\rx2 0x%x", XilFileDataAddressD2 - 0x20);





 OperateBuffers_usart1t();

//#ifndef PROG_MD310_SATI	  //for config files is need bigger address!!!
	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//#endif
    
   


//#ifdef PROG_BCM
if(addr_dest == (XilFileDataAddressD - 0x20))
		{
   printfp1("\n\r hier write xilinx1(firmw) 0xC0100060:");
 	     errorw = (signed char)write_dataflash (XilFileDataAddressD_BCM - 0x60, (unsigned int)&TFTP_Buffer[0],  FIRMWARE_SIZE+0x60); //90 : without header
	printfpd1( " %d ", errorw);	
		 delay_mcs(100);
		FillXilFileData(0);
		 return;
		}

if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{
   printfp1("\n\r hier write xilinx2(eth_firmw) 0xC0192060:");
 	     errorw = (signed char)write_dataflash (XilFileDataAddressD_BCM1 - 0x60, (unsigned int)&TFTP_Buffer[0],  ETH_FIRMWARE_SIZE+0x60); //90 : without header
	printfpd1( " %d ", errorw);	
		 delay_mcs(100);
		FillXilFileData(1);
		 return;
		}
//#endif


  
 if(addr_dest == ((unsigned long)PROG_ADDRESS - (unsigned long)HEADER_SIZE))
		{
		  printfp1("\n\r..............set size = BIG_PROG_SIZE; !!!!");

	   //	 size = 600000l; //big programm size	was 524k
		 size = BIG_PROG_SIZE; //big programm size	was 524k
		}
	
 
	 
 
#ifndef MAKET_PLATA	
	 if(errorw == (signed char)1)
#else
	 if(1)
#endif
	 {

printfp1("\n\r ..hier write");
      write_dataflash (addr_dest, addr_src,  size);
	 }
	 else
	 {
	  printfp("\n\r Error writing file!!!!!");
	 }

 //#ifdef PROG_PU_MSAT
//}
//#endif

// #ifdef CF_PRINT
 #ifdef TEST_HANGING  
 printfp("\n\r ...writing is  finished");
 OperateBuffers_usart0t();
 #endif
 //printfp("\n\r4");
  	   delay_mcs(100);

  #ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
	else if(operation == 2l)   //run file
	{
	  usart_select(0); //debug uart on
	  my_int_disable();
	  wd_deinit();
	  _arm920t_dcache_disable();
	  _arm920t_icache_disable();

 	  Jump(&TFTP_Buffer[0]);
	}
	else if(operation == 3l)   //programm pult
	{
#ifdef PROGRAMM_PULT
	 ProgrammPultTFTP();
#endif //PROGRAMM_PULT 
	}
else if(operation == 4l)   //programm pult
	{
#ifdef LOAD_EXT_MODEM
	 unsigned char * src =  (uchar_ptr)&TFTP_Buffer[0];
	 unsigned char * dst =  (uchar_ptr)NVRAM_BASE;
	 for(cnt = 0; cnt < DATA_SIZE_EXTMODEM; cnt++)
	 {
	  * dst++ = *src++;
	 } 
	 LoadExtModem();
#endif // LOAD_EXT_MODEM
	}
else if(operation == 5l)   //programm flash through xilinx
	{
#ifdef XIL_FLASH
  //	      write_dataflashx (addr_dest, addr_src,  size);
//___________________________________________________________________
// if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");

AT91F_DataflashInitx();  

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start write xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif
  //now write all to have header in far flash   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);
//121018   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0],  size);
 
//printfp("\n\r");
 for(unsigned long i = 0; i < 0x60; i++)
 {
  TFTP_Buffer1[i] =	TFTP_Buffer[i];
//  printfpd(" %02X",TFTP_Buffer[i]);
 } 
// */
//  	 delay_mcs(100000l);

#ifdef PROG_ODU1
 //	printfp("\n\r InvertBitOrdering()... ");

   InvertBitOrdering();	 //bit order need inverted.
	size = ODU_XIL_SIZE; //236000;
#endif

#ifdef PROG_MD310E16
	printfp("\n\r InvertBitOrdering()... ");
   InvertBitOrdering();	 //bit order need inverted.
   size = ODU_XIL_SIZE; //236000;
#endif




	printfp("\n\r write_dataflashx()... ");

 errorw = write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);	//121018 - write only xilinx data(try use zero address for xilinx loading) 
//keep header in main flash 
 //  write_dataflash ((unsigned int)XilFileDataAddressD3, (unsigned int)&TFTP_Buffer[0],  0x60);
  	delay_mcs(10000l);

printfpd("\n\r errorw = %d ", errorw);


 #ifdef PROG_ODU1
  if(errorw == 1) //bit order need inverted.
#endif

 write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  // wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);

 printfp("\n\r finish... ");

  
	/*
  for(i = 1; i < 0x61; i++)
 {
  TFTP_Buffer1[i] =	i;
  printfpd(" %02X",TFTP_Buffer[i]);
 } 
	 */
  		/*
     write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  //	  wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
	 */
	//  wd_reset();
  //	   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
  //	   {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
  //	   }
 //	FillDatat(0); //for test

 //	FillXilFileDatax(MODEM_QUANTITY);
	FillXilFileDatax(0);
  //	  wd_reset();

	// FillProgVersion();

//#ifdef PROG_BMDN
//	FillConfigFileVersion();
//#endif // PROG_BMDN


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;


#ifdef DEBUG_WRITE_XIL
  printfp("\n\r finish write xil flash\n\r");
#endif


//___________________________________________________________________


	  //in addr _dest - need make address of conkretycal xilinx
#endif
	}
	else if(operation == 6l)	  //compare file
	{
//printf("\n\r2a");

//120710	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI

 //  AT91F_DataflashInitx();  //t


#ifndef PROG_DMU6
#ifdef XIL_FLASH

 AT91F_DataflashInitx();  //t

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start compare xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif

 if(addr_dest < CFG_DATAFLASH_LOGIC_ADDR_CS1X)
 {

#ifdef DEBUG_WRITE_XIL
  printfpd("\n\r addr < CFG_DATAFLASH_LOGIC_ADDR_CS1X : %d \n\r" , size);
  OperateBuffers_usart0t();

#endif

 //  return; //to test

 //t  CompareToFilex(size);
#ifndef PROG_MD310
#ifndef PROG_KAZAH
  InvertBitOrdering();		//t new 
#endif
#endif


#ifdef PROG_ODU1
  	  CompareToFilex(ODU_XIL_SIZE);	//t


#else
	    CompareToFilex(1000);

#endif
   //ok	  CompareToFilex(1000);	//t
 //  CompareToFilex(10000);


 }
#endif

//#endif
#ifdef PROG_PU_MSAT
if(addr_dest == (XilFileDataAddressD - 0x20))
		{
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	   size = 90; // header only
  		 addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }

#endif
#endif
	  /*
#ifdef PROG_DMU6
if(addr_dest == (XilFileDataAddressD - 0x20))
		{
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	   size = 90; // header only
  		 addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }

#endif
	*/
//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif
 //    write_dataflash (addr_dest, addr_src,  size);
//#ifdef PROG_PU_MSAT
//}
//#endif
  //	  wd_reset();
//printf("\n\r4");
  	   delay_mcs(100);
#ifdef PROG_PU_MSAT

		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{
//write to second flash local addr = 0;
//___________________________________________try write from second try
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	   CompareToFile(size1);

	
	    wd_reset();
   //ok		  TestWriteFlash2();
		}
#endif


#ifdef PROG_DMU6
		printfpd("\n\r compare file dmu addr_dest : 0x%08X", addr_dest );
		printfpd(" size1 : 0x%08X", size1 );

	//	printfpd(" XilFileDataAddressD - 0x20: 0x%08X", XilFileDataAddressD - 0x20);


		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

   //		if(addr_dest == (XilFileDataAddressD - 0x20))
		if(addr_dest ==0)
		{
//write to second flash local addr = 0;
//___________________________________________try write from second try
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 	 //	delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	//t   CompareToFile(size1);
	   pio_ptrb->CODR = 1<<0; //get down line prog for xilinx
	    AT91F_DataflashInit();
  	CompareToFile(200);		  //t
//  CompareToFile(1000);	
		// CompareToFile(size1);

	     pio_ptrb->SODR = 1<<0;
	
	    wd_reset();
   //ok		  TestWriteFlash2();
		}

	 //	 printfp ("\n\r check need compare cs2");

			if(addr_dest == 0x10000000)
		{
		printfp ("\n\r need compare cs2");
	   CompareToFilecs2(size1);
	    wd_reset();
   //ok		  TestWriteFlash2();
		}


#endif

	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN

#ifndef PROG_VNV

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif
#endif

	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
else if(operation == 7l)   //programm if module
	{
#ifdef XIL_FLASH
  //	      write_dataflashx (addr_dest, addr_src,  size);
//___________________________________________________________________
// if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");

//#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start write if module flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
//#endif
  //now write all to have header in far flash   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);
//121018   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0],  size);
 
//printfp("\n\r");
 for(unsigned long i = 0; i < 0x60; i++)
 {
  TFTP_Buffer1[i] =	TFTP_Buffer[i];
//  printfpd(" %02X",TFTP_Buffer[i]);
 } 
// */
//  	 delay_mcs(100000l);

 //write_dataflash ((unsigned int)HEADER_IF_MODULE_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  // wd_reset();
//printf("\n\r4");
 // 	 delay_mcs(100000l);
 delay_mcs(50); 
 errorw = 0; 
// errorw = write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);	//121018 - write only xilinx data(try use zero address for xilinx loading) 

// AT91F_DataflashInitx();  //
// delay_mcs(50);
//WriteDataIFModule(0 + CFG_DATAFLASH_LOGIC_ADDR_CS1X, Buf, 4);
#ifdef PROG_MD310_SATI
 errorw = WriteDataIFModule(addr_dest, &TFTP_Buffer[0], size);
#endif
   /*
  printfp("\n\rif module data : \n\r");
 for(unsigned ii = 0; ii < size; ii++)
 {
 printfpd("%c", TFTP_Buffer[ii]);
 if(!ii%16) printfp("\n\r");
 }
	*/


//keep header in main flash 
 //  write_dataflash ((unsigned int)XilFileDataAddressD3, (unsigned int)&TFTP_Buffer[0],  0x60);
 // 	delay_mcs(10000l);
   delay_mcs(50);

   if(errorw == (signed char)1)
	 {
	    printfp("\n\r finish write if module flash.....OK");
   //		delay_mcs(50);
#ifdef PROG_MD310_SATI

		ReadIFmoduleData();// update

#endif
	   delay_mcs(50);

 write_dataflash ((unsigned int)HEADER_IF_MODULE_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);

	}
	else
	{

	      printfp("\n\r finish write if module flash.....WRONG");


	}

	/*
  for(i = 1; i < 0x61; i++)
 {
  TFTP_Buffer1[i] =	i;
  printfpd(" %02X",TFTP_Buffer[i]);
 } 
	 */
  		/*
     write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  //	  wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
	 */
	//  wd_reset();
  //	   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
  //	   {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
  //	   }
 //	FillDatat(0); //for test

 //	FillXilFileDatax(MODEM_QUANTITY);
 //t141118	FillXilFileDatax(0);
  //	  wd_reset();

	// FillProgVersion();

//#ifdef PROG_BMDN
//	FillConfigFileVersion();
//#endif // PROG_BMDN


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;

   //	  printfp("\n\r finish write if module flash");



//___________________________________________________________________


	  //in addr _dest - need make address of conkretycal xilinx
#endif
	}
if(operation == 8l)	  //fast write file
	{
//printfp("\n\r2a");
 #ifdef CF_PRINT
 printfpd("\n\r addr dest : 0x%x", addr_dest);
 OperateBuffers_usart0t();
 #endif

#ifndef PROG_MD310_SATI	  //for config files is need bigger address!!!
	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
#endif


//printfp("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t
//#endif
#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	

if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rInvertBitOrdering ");
      OperateBuffers_usart0t();

#endif      
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	  size = 90; // header only
  	  addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }
#endif
#endif
 /*
#ifdef PROG_DMU6
#ifndef MAKET_PLATA	

if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rInvertBitOrdering ");
      OperateBuffers_usart0t();

#endif      
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	  size = 90; // header only
  	  addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }
#endif
#endif
 */

#ifdef PROG_MF20
if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{
 	     errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
		 return;
		}
#endif

//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif

   //  printfp("\n\r..............change address ?????");

#ifdef PROG_MD310_SATI
	 //	 InvertBitOrdering();//for test

// printfpd("\n\r addr_dest :%x", addr_dest);
//#ifndef PROG_DMU6	
	  if(addr_dest == (XilFileDataAddressD - 0x20))
		{
	  //	  printfp("\n\r..............change address !!!!");
// #ifndef PROG_DMU6	

		 addr_dest = XilFileDataAddressD7 - 0x20;
#ifndef PROG_DMU6	

	   return; //do not use xilinx! and do not write to config files
#else
 // if(!SetSelectorToProv())
   if(SetSelectorToProv() != CODE_WRONG)

  {
	 printfp("\\Do not have Provingent plata... return");
  	   return;
   }
#endif
		}

if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{
	  //	  printfp("\n\r..............change address !!!!");
// #ifndef PROG_DMU6
	
		 addr_dest = XilFileDataAddressD7A - 0x20;

  #ifndef PROG_DMU6	
     return; //do not use xilinx! and do not write to config files


#else
  //if(!SetSelectorToDMU())
   if(SetSelectorToDMU() != CODE_WRONG)

  {
	 printfp("\\Do not have Provingent plata... return");
  	   return;
   }


	//   return; //do not use xilinx! and do not write to config files
#endif
		}

//#endif

// printfpd("\n\r dest :%x", addr_dest);
// printfpd("\n\r size :%x", size);


		 else if(addr_dest == ((unsigned long)PROG_ADDRESS - (unsigned long)HEADER_SIZE))
		{
	//	  printfp("\n\r..............change size !!!!");

	   //	 size = 600000l; //big programm size	was 524k
		 size = BIG_PROG_SIZE; //big programm size	was 524k
		}
		 /*
	    else if(addr_dest >= ((unsigned long)CONFIG_FILES_ADDRESS_OLD - (unsigned long)HEADER_SIZE - (unsigned long)HEADER_SIZE))
		{
		//set to another flash
		 addr_dest += 0x20000000; //0xc00000000 ->  0xe0000000
		 addr_dest -= 0x00220000;

		printfp("\n\r..............change address for config !!!!");
		printfpd("\n\r new addr dest : 0x%x", addr_dest);


		}

		  */

   #ifdef PACK_CFG

   //   else if(addr_dest >= ((unsigned long)CONFIG_FILES_ADDRESS_OLD - (unsigned long)HEADER_SIZE - (unsigned long)HEADER_SIZE))
      else if(addr_dest >= (unsigned long)START_ADDR_CFG_FILE)
		{
		//set to another flash
	  //	 addr_dest += 0x20000000; //0xc00000000 ->  0xe0000000
	  //	 addr_dest -= 0x00220000;
		 num_cfg_file = (addr_dest - START_ADDR_CFG_FILE) / OLD_CONFIG_FILE_VARIANTS_STEP;
	
		printfpd("\n\r old addr dest : 0x%x", addr_dest);
		printfpd(" num_cfg_file : %d", num_cfg_file);

	//	PackConfig(); // convert config file from 40 to 19 K

		 addr_dest =  START_ADDR_CFG_FILE + (num_cfg_file * CONFIG_FILE_VARIANTS_STEP);

		printfp("\n\r..............change address for config !!!!");
		printfpd("\n\r new addr dest : 0x%x", addr_dest);

		 for(i = 0; i < 6000; i ++)
		 {
			TFTP_Buffer[SYNT_DATA_OFFSET + i] = TFTP_Buffer[OLD_FILE_SIZE - 6000 + i];
		 }



 	    write_dataflash (addr_dest, addr_src, FILE_SIZE);

   //     write_dataflash (addr_dest + SYNT_DATA_OFFSET + 1, addr_src + OLD_FILE_SIZE - 6000 + 1,  6000); //write last 6k of file

		config_flag = 1; 
		}




   #endif  // PACK_CFG


#endif


#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	
		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

#endif   



//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<12; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
            StartLoadAll();
		    wd_reset();
   //ok		  TestWriteFlash2();
		}
	 delay_mcs(2000000);

#endif
#endif

#ifdef PROG_DMU6
#ifndef MAKET_PLATA	
		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD7 - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

#endif   



//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
  #ifndef PROG_VNV

            StartLoadAllM();
  #endif

		    wd_reset();
   //ok		  TestWriteFlash2();
		}

		if(addr_dest == (XilFileDataAddressD7A - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

#endif   



//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS2, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
  #ifndef PROG_VNV

            StartLoadAllM();
  #endif
		    wd_reset();
   //ok		  TestWriteFlash2();
		}



	 delay_mcs(2000000);

#endif
#endif







	   /* this maked in operation == 5
#ifdef PROG_BMDN

		wd_reset();
 	 //	delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest < (CFG_DATAFLASH_LOGIC_ADDR_CS1X))
		{

//#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

//#endif   
//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflashx (CFG_DATAFLASH_LOGIC_ADDR_CS0X + VER_OFFSET, (unsigned int)&TFTP_Buffer[0x60],  size); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);

	    wd_reset();
   //ok		  TestWriteFlash2();

	   errorw = 0; // do not need write this in base flash
		}


#endif
	 */


 //151021	delay_mcs(2000000);

 #ifdef PACK_CFG
if(!config_flag)
{  

 #endif

	 if(errorw == (signed char)1)
	 {
  //	 printfp("\n\r write name");

     write_dataflash (addr_dest, addr_src,  size);

	 }

 #ifdef PACK_CFG
}
#endif

//#ifdef PROG_PU_MSAT
//}
//#endif

 #ifdef CF_PRINT
 printfp("\n\r ...writing is  finished");
 OperateBuffers_usart0t();
 #endif



  //	  wd_reset();
//printfp("\n\r4");
  	   delay_mcs(100);


	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN


#ifndef PROG_VNV

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif
#endif

	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
	}
}

#endif

extern "C" char IsXilWrited(void)
{
  char ret = 0;
  for(long i = 5l; i < 100l; i++)
  {
    if(XilFileData.Value[i] == ':')  //if sawed time 15:30
	{
     ret = 1; 
//	 printf("\n\r i = %d", i);  //for test
	 break;
	}
 //	 printf("\n\r XilFileData.Value[%d]= %c", i, XilFileData.Value[i]);  //for test

  }
  return ret;
}


extern "C" void FillXilFileData(char pg)
{
 char * pData;
 int i;
 unsigned int source_addr;
 source_addr = (unsigned int)XilFileDataAddressD_BCM - 0x40;
 read_dataflash (source_addr,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
// for(i = 0; i < TBUFF1_VALUE; i++)
 for(i = 0; i < DISP_LEN; i++)
 {
// #ifndef PROG_TUTS
 XilFileData.Value[i] = *pData++;
// #endif
 }
 read_dataflash ((unsigned int)XilFileDataAddressD_BCM1 - 0x40,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
 XilFileData2.Value[i] = *pData++;
 }
}

extern "C" void FillXilFileData2(char pg)
{
 char * pData;
 int i;

  unsigned int source_addr;


#ifdef PROG_VNV1
	source_addr = (unsigned int)XilFileDataAddressD7;
#endif


// unsigned int XilDataAddress = XilFileDataAddressD; //
//t unsigned int XilAddressToDownload = XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
// unsigned int XilAddressToDownload = (unsigned int)(&TFTP_Buffer[0]);// 0x21000000; //upper 16Mx32 +1
// unsigned int XilSizeToDownload = TBUFF1_VALUE; //0x1ffff;
//t read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//140704 read_dataflash ((unsigned int)XilFileDataAddressD,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 read_dataflash (source_addr,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
// for(i = 0; i < TBUFF1_VALUE; i++)
 #ifndef PROG_MD310 
 #ifndef PROG_TUTS
 for(i = 0; i < DISP_LEN; i++)
 {
// #ifndef PROG_TUTS
 XilFileData.Value[i] = *pData++;
// #endif
 }
 #endif
 #endif

 #ifdef PROG_TUTS
 strcpy(XilFileData.Value,"Not Used");
 #endif

//#ifndef PROG_MD310_SAT
 #ifdef PROG_MD310
//#endif
#ifndef PROG_MD310_SAT

 strcpy(XilFileData.Value,"Not Used");
#endif
//#ifndef PROG_MD310_SAT
 #endif
//#endif



#ifdef PROG_VNV1
 read_dataflash ((unsigned int)XilFileDataAddressD7,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
 XilFileData.Value[i] = *pData++;
 }


  read_dataflash ((unsigned int)XilFileDataAddressD7A,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
 XilFileData2.Value[i] = *pData++;
 }

#endif





//}
}





#ifdef XIL_FLASH


extern "C" void FillData(char deviceindex)
{
 char * pData;
 int i;
 char* pDataX;

#ifdef DEBUG_WRITE_XIL
    printfpd("\n\rdev:%d", deviceindex);
#endif


 switch(deviceindex)
 {
 case 0: pDataX =  XilFileDatax0.Value;	  break;

#ifndef PROG_BMDN6MI
 case 1: pDataX =  XilFileDatax1.Value;	  break;
 case 2: pDataX =  XilFileDatax2.Value;	  break;
 case 3: pDataX =  XilFileDatax3.Value;	  break;
 case 4: pDataX =  XilFileDatax4.Value;	  break;
 case 5: pDataX =  XilFileDatax5.Value;	  break;
 case 6: pDataX =  XilFileDatax6.Value;	  break;
 case 7: pDataX =  XilFileDatax7.Value;	  break;
 case 8: pDataX =  XilFileDatax8.Value;	  break;
 case 9: pDataX =  XilFileDatax9.Value;	  break;
 case 10: pDataX =  XilFileDatax10.Value;	  break;
 case 11: pDataX =  XilFileDatax11.Value;	  break;
 case 12: pDataX =  XilFileDatax12.Value;	  break;
 case 13: pDataX =  XilFileDatax13.Value;	  break;
 case 14: pDataX =  XilFileDatax14.Value;	  break;
 case 15: pDataX =  XilFileDatax15.Value;	  break;
#endif
 default: pDataX =  XilFileDatax0.Value;	  
 }
 //need add later xilinx second variant offset
 //read_dataflashx ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X + XIL_OFFSET +(XIL_ADDR_STEP * deviceindex),(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
//121018 read_dataflashx ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X + VER_OFFSET +(XIL_ADDR_STEP * deviceindex),(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));

 read_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));	 //maked only for one plata modem
 pData =  (char *)(&TFTP_Buffer[0]);
#ifdef DEBUG_WRITE_XIL
  printfp("\n\r");
#endif 
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
  if(!(*pData)) *pData = ' ';

#ifdef DEBUG_WRITE_XIL
    printfpd("%c", *pData);
#endif
// if(!(*pData)) *pData = ' ';
XilFileDatax0.Value[i] = *pData++;
 // *pDataX++ = *pData++;
 }
#ifdef DEBUG_WRITE_XIL
  printfp("\n\r>");
  printfp(XilFileDatax0.Value);
   printfp("<\n\r");
  pDataX =  XilFileDatax0.Value;
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
   printfpd("%c", *pDataX++);

 }


#endif 


}

extern "C" void FillDatat(char deviceindex)
{
 char * pData;
 int i;
 char* pDataX;

//#ifdef DEBUG_WRITE_XIL
    printfpd("\n\rdev:%d", deviceindex);
//#endif


 switch(deviceindex)
 {
 case 0: pDataX =  XilFileDatax0.Value;	  break;
#ifndef PROG_BMDN6MI
 case 1: pDataX =  XilFileDatax1.Value;	  break;
 case 2: pDataX =  XilFileDatax2.Value;	  break;
 case 3: pDataX =  XilFileDatax3.Value;	  break;
 case 4: pDataX =  XilFileDatax4.Value;	  break;
 case 5: pDataX =  XilFileDatax5.Value;	  break;
 case 6: pDataX =  XilFileDatax6.Value;	  break;
 case 7: pDataX =  XilFileDatax7.Value;	  break;
 case 8: pDataX =  XilFileDatax8.Value;	  break;
 case 9: pDataX =  XilFileDatax9.Value;	  break;
 case 10: pDataX =  XilFileDatax10.Value;	  break;
 case 11: pDataX =  XilFileDatax11.Value;	  break;
 case 12: pDataX =  XilFileDatax12.Value;	  break;
 case 13: pDataX =  XilFileDatax13.Value;	  break;
 case 14: pDataX =  XilFileDatax14.Value;	  break;
 case 15: pDataX =  XilFileDatax15.Value;	  break;
#endif
 default: pDataX =  XilFileDatax0.Value;	  
 }
 //need add later xilinx second variant offset
 //read_dataflashx ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X + XIL_OFFSET +(XIL_ADDR_STEP * deviceindex),(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
//121018 read_dataflashx ((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X + VER_OFFSET +(XIL_ADDR_STEP * deviceindex),(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));

 read_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));	 //maked only for one plata modem
 pData =  (char *)(&TFTP_Buffer[0]);
//#ifdef DEBUG_WRITE_XIL
  printfp("\n\r");
//#endif 
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
  // printfpd()

  if(!(*pData)) *pData = ' ';

//#ifdef DEBUG_WRITE_XIL
    printfpd(" %02X", *pData);
//#endif
// if(!(*pData)) *pData = ' ';
XilFileDatax0.Value[i] = *pData++;
 // *pDataX++ = *pData++;
 }
//#ifdef DEBUG_WRITE_XIL
  printfp("\n\r>");
  printfp(XilFileDatax0.Value);
   printfp("<\n\r");
  pDataX =  XilFileDatax0.Value;
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
   printfpd("%c", *pDataX++);

 }


//#endif 


}



extern "C" void FillXilFileDatax(char modem)
{
//unsigned long ir;

if(modem == MODEM_QUANTITY)
{
for(unsigned long im = 0; im < MODEM_QUANTITY; im++)
{
// if(ModemIsUsed(im))
// {

// ir = im << 1;
  FillData(im);
//  ir += 1;
// FillData(ir);

// }	  //used

}  //for
}  //if
else
{
// if(ModemIsUsed(modem)) //can test xilinx?
// {
// ir = modem << 1;
 FillData(modem);
//  ir += 1;
// FillData(ir);
// }	  //used
}	 //else	 <--- need check is used

}



#endif

extern "C" void FillProgVersion()
{
 char * pData;
 uint_32 cnt;
 cnt = 0;
 pData = &theAnyStrings.cLogoLd[0];
 unsigned long do_not_hangt =  TBUFF1_VALUE;
// while(* pData)
 while((* pData) && (do_not_hangt--))
 {
 ProgVersion.Value[cnt++] =  * pData++;
 }
 pData = &theAnyStrings.cVersion[0];
 while(* pData)
 {
 ProgVersion.Value[cnt++] =  * pData++;
 }
  ProgVersion.Value[cnt] = '\0';
 }

#ifdef PROG_BMDN

#define NUMBER_MODEM (0)

extern "C" void SetPriorityZero(unsigned char mod)
{
switch(mod)
{
 case 0 : Priority0.Value = 0; break;

#ifndef PROG_BMDN6MI
 case 1 : Priority1.Value = 0; break;
 case 2 : Priority2.Value = 0; break;
 case 3 : Priority3.Value = 0; break;
 case 4 : Priority4.Value = 0; break;
 case 5 : Priority5.Value = 0; break;
 case 6 : Priority6.Value = 0; break;
 case 7 : Priority7.Value = 0; break;
//___________________________________________________________8 modems
 case 8 : Priority8.Value = 0;  break;
 //__________________________________________________________9 modems
#endif

 case NO_MODEM :  break;

 default :  break;
 }
//now do not keep this value in memory????

}

extern "C" char ConfigFileIsWrited(void)
{
  char ret = 0;
//  printfp1("\n\r");
  for(long i = 3l; i < 50l; i++)
  {
//130227    if(TFTP_Buffer[i] == ':')  //if sawed time 15:30
	 if(i == 3) {
//	   printfp1("\n\r");
      }
//	 printfpd1(" %c ", TFTP_Buffer[i]); 
	 
    if(TFTP_Buffer[i] == '.')  //if sawed '.'
 //    if(((TFTP_Buffer[i] == '.') && (TFTP_Buffer[i+1] == 'f')) || ((TFTP_Buffer[i] == '.') && (TFTP_Buffer[i+1] == 'm')))
	{
     ret = 1; 
   //	 printfpd1(" %c ", TFTP_Buffer[i]);  //for test
//	  printfpd1("\n\r i = %d ", i); 
//     printfp1(" Is Writed ");
	 break;
	}
 //	 printf("\n\r XilFileData.Value[%d]= %c", i, XilFileData.Value[i]);  //for test
	
  }

//  printfpd1("ret =%d ", ret);
  return ret;
}
#define ERASED_SIZE	(256)
extern "C" void EraseAllConfigFiles1()
{
unsigned long len = 	 (unsigned long )(CONFIG_FILE_VARIANTS_STEP  * MAX_CFG_FILE_VARIANT);
printfp1("\n\r Start EraseAllConfigFiles1()");
OperateBuffers_usart0t();

 printfpd1("\n\r Start fill : %d", len );
OperateBuffers_usart0t();

for(unsigned i = 0; i < len; i++)
{
  TFTP_Buffer[i] = 0x88;
}
 wd_reset();
 printfpd1("\n\r Start write() : %d", len );
OperateBuffers_usart1t();
  write_dataflash ((unsigned int)CONFIG_FILES_ADDRESS , (unsigned int)&TFTP_Buffer[0], len );
 wd_reset();
   AllConfigFileVersion.Value[0]  = '\0';
   AllConfigFileVersion1.Value[0] = '\0';
   AllConfigFileVersion2.Value[0] = '\0';
   AllConfigFileVersion3.Value[0] = '\0';
printfp1("\n\r Finish EraseAllConfigFiles1()");
}
extern "C" void EraseAllConfigFiles()
{
printfp1("\n\r Start EraseAllConfigFiles()");
OperateBuffers_usart1t();
 char * pData;
 uint_32 cnt = 0;
 unsigned cnt1 = 0;
 unsigned cnt2 = 0;
 unsigned cnt3 = 0;
unsigned long len;
unsigned long variant;// =  GetNumConfigFile(NUMBER_MODEM) & CONFIG_FILE_MASK;
len = (unsigned int)FULL_HEADER_SIZE;

for(unsigned i = 0; i < ERASED_SIZE; i++)
{
  TFTP_Buffer1[i] = 0x88;
}
for(variant = 0; variant < MAX_CFG_FILE_VARIANT; variant++)
{
//if(ConfigFileIsWrited())
if(1)
{
  wd_reset();
 for( i = 0; i < ERASED_SIZE; i++)
{
  TFTP_Buffer1[i] = 0x0;
}
  write_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS +  XILINXBEFORESIZE -  FULL_HEADER_SIZE -  FULL_HEADER_SIZE  + (variant * CONFIG_FILE_VARIANTS_STEP)), (unsigned int)&TFTP_Buffer1[0],ERASED_SIZE);
for( i = 0; i < ERASED_SIZE; i++)
{
  TFTP_Buffer1[i] = 0x0;
}
    delay_mcs(5000);
 write_dataflash  ((unsigned int)(CONFIG_FILES_ADDRESS -  FULL_HEADER_SIZE + (variant * CONFIG_FILE_VARIANTS_STEP) + 
							(CONFIG_FILE_PROVINGENT_STEP << 1) - MAX_SIZE_TEXT_FILE  -  FULL_HEADER_SIZE  - 1),  (unsigned int)&TFTP_Buffer1[0],ERASED_SIZE);
  delay_mcs(5000);
  printfpd(" %d ", variant);
}
}//for
 // AllConfigFileVersion.Value[cnt] = '\0';
   AllConfigFileVersion.Value[0]  = '\0';
   AllConfigFileVersion1.Value[0] = '\0';
   AllConfigFileVersion2.Value[0] = '\0';
   AllConfigFileVersion3.Value[0] = '\0';

printfp1("\n\r Finish EraseAllConfigFiles()");
}
#define FILE_NAME_SIZE (6)
extern "C" void FillAllConfigFileVersion()
{
 char * pData;
 uint_32 cnt = 0;
 uint_32 cnt2 = 0;
 uint_32 cnt3 = 0;
 uint_32 cnt4 = 0;
 uint_32 cnt5 = 0;
 uint_32 cnt6 = 0;
 unsigned cnt1 = 0;
   AllConfigFileVersion.Value[0]  = '\0';
   AllConfigFileVersion1.Value[0] = '\0';
   AllConfigFileVersion2.Value[0] = '\0';
   AllConfigFileVersion3.Value[0] = '\0';
   AllConfigFileVersion4.Value[0] = '\0';
   AllConfigFileVersion5.Value[0] = '\0';
unsigned long len;
read_dataflash ((unsigned int)(XilFileDataAddressD_BCM - FULL_HEADER_SIZE), (unsigned int)FULL_HEADER_SIZE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
if(ConfigFileIsWrited())  //check have '.' in name
{
 for(cnt1 = 5; cnt1 < 35+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion.Value[cnt++] =  * pData;
 pData++;
 if(*pData == '.')  cnt1 = 35 - 5;
 }	 //for	 cnt1
 AllConfigFileVersion.Value[cnt++] = ' ';
  AllConfigFileVersion.Value[cnt++] = '\n';
    AllConfigFileVersion.Value[cnt++] = '\r';
}
read_dataflash ((unsigned int)(XilFileDataAddressD_BCM1 - FULL_HEADER_SIZE), (unsigned int)FULL_HEADER_SIZE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
if(ConfigFileIsWrited())  //check have '.' in name
{
 for(cnt1 = 5; cnt1 < 35+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion.Value[cnt++] =  * pData;
 pData++;
 if(*pData == '.')  cnt1 = 35 - 5;

 }	 //for	 cnt1
 AllConfigFileVersion.Value[cnt++] = ' ';
  AllConfigFileVersion.Value[cnt++] = '\n';
    AllConfigFileVersion.Value[cnt++] = '\r';
}
unsigned long variant;// =  GetNumConfigFile(NUMBER_MODEM) & CONFIG_FILE_MASK;

len = (unsigned int)FULL_HEADER_SIZE;
for(variant = 0; variant < MAX_CFG_FILE_VARIANT; variant++)
{
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS +  XILINXBEFORESIZE -  FULL_HEADER_SIZE -  FULL_HEADER_SIZE  + (variant * CONFIG_FILE_VARIANTS_STEP) //+ 
						 ),
							 (unsigned int)len, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
if(ConfigFileIsWrited())
{
if(cnt < (TBUFF1_VALUE - FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion.Value[cnt++] =  * pData;
  pData++;
 if(*pData == '.')  cnt1 = FILE_NAME_SIZE+12;
 }	 //for	 cnt1
 AllConfigFileVersion.Value[cnt++] = ' ';
 }	//cnt if
else
{
if(cnt2 < (TBUFF1_VALUE- FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion1.Value[cnt2++] =  * pData;
  pData++;
 if(*pData == '.')  cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
 AllConfigFileVersion1.Value[cnt2++] = ' ';
}  //if cnt2
else  if(cnt3 < (TBUFF1_VALUE- FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion2.Value[cnt3++] =  * pData;
  pData++;
 if(*pData == '.') cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
 AllConfigFileVersion2.Value[cnt3++] = ' ';
}  //if cnt3
else if(cnt4 < (TBUFF1_VALUE- FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion3.Value[cnt4++] =  * pData;
  pData++;

 if(*pData == '.')  cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
 AllConfigFileVersion3.Value[cnt4++] = ' ';
}  //if cnt4
else if(cnt5 < (TBUFF2_VALUE- FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion4.Value[cnt5++] =  * pData;
  pData++;

 if(*pData == '.')  cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
 AllConfigFileVersion4.Value[cnt5++] = ' ';
}  //if cnt5
else if(cnt6 < (TBUFF2_VALUE- FILE_NAME_SIZE - 5))
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
 AllConfigFileVersion5.Value[cnt6++] =  * pData;
  pData++;
 if(*pData == '.')  cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
 AllConfigFileVersion5.Value[cnt6++] = ' ';
}  //if cnt6
else
{
 for(cnt1 = 5; cnt1 < FILE_NAME_SIZE+12; cnt1++)
 {
if(* pData)
  pData++;

 if(*pData == '.')  cnt1 = FILE_NAME_SIZE + 12;
 }	 //for cnt1
}
}//if cnt..else
}// is writed
}  //for
   AllConfigFileVersion.Value[cnt]   = '\0';
   AllConfigFileVersion1.Value[cnt2] = '\0';
   AllConfigFileVersion2.Value[cnt3] = '\0';
   AllConfigFileVersion3.Value[cnt4] = '\0';
   AllConfigFileVersion4.Value[cnt5] = '\0';
   AllConfigFileVersion5.Value[cnt6] = '\0';
}




extern "C" void FillConfigFileVersion()
{

//printfp("\n\r FillConfigFileVersion() start...");
//OperateBuffers_usart0t();
 
 char * pData;
 uint_32 cnt;
 cnt = 0;

//return; //t

//read_dataflash ((unsigned int)XilFileDataAddressD2,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 
//______________________________________________________
//MAX_CFG_FILE_VARIANT

//unsigned char variant =  GetNumConfigFile(NUMBER_MODEM) & CONFIG_FILE_MASK;
unsigned long variant = 0;
 variant =  GetNumConfigFile(NUMBER_MODEM) & CONFIG_FILE_MASK;

// printfpd("variant :%d) ", variant);
// OperateBuffers_usart0t();


//variant = 1; //for test!!!!!!!!!!!!!!!!!!!!!!

 //printf("curvar = %d",curvar);
unsigned long len = (unsigned int)TBUFF1_VALUE;
//read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)len, (char *)(&TFTP_Buffer[0]));
//printfpd("\n\rlen :%d) ", len);
//printfpd("\n\raddr :0x%08X) ", (unsigned int)(CONFIG_FILES_ADDRESS +  XILINXBEFORESIZE -  FULL_HEADER_SIZE -  FULL_HEADER_SIZE  + (variant * CONFIG_FILE_VARIANTS_STEP)));


// OperateBuffers_usart0t();



//read_dataflash ((unsigned int)(XilDataAddressD3 + (variant * CONFIG_FILE_VARIANTS_STEP)),
read_dataflash ((unsigned int)(CONFIG_FILES_ADDRESS +  XILINXBEFORESIZE -  FULL_HEADER_SIZE -  FULL_HEADER_SIZE  + (variant * CONFIG_FILE_VARIANTS_STEP) //+ 
						 //	SYNT_DATA_OFFSET
						 ),
							 (unsigned int)len, (char *)(&TFTP_Buffer[0]));

 
 pData =  (char *)(&TFTP_Buffer[0]);

 while((* pData) && (cnt < (TBUFF1_VALUE - 1)))
 {
// printfpd("%d ", cnt);
// printfpd("(%c) ", *pData);
// OperateBuffers_usart0t();

 ConfigFileVersion.Value[cnt++] =  * pData++;
 }
  ConfigFileVersion.Value[cnt] = '\0';
  
//printfp("\n\r FillConfigFileVersion() finish");
//OperateBuffers_usart0t();
 }

#endif //PROG_BMDN

 
 extern "C" void FillProgVersion1(char * out_str , long len)
{
 char * pData;
 uint_32 cnt;
// cnt = 0;
 cnt = DISP_LEN - len ; // 
 pData = &theAnyStrings.cVersion[0];

 while(* pData)
 {
  cnt--;
  if (!cnt)  break;
 *out_str++ =  *pData++;
  }
  *out_str = '\0';
}

#ifdef PROG_DTVM




 extern "C" unsigned long  GetStateSynce()
{
 unsigned char StateSynce;
 unsigned char StateRS;
 unsigned char State;

 StateSynce = inportb((unsigned long )STATE_REGISTER);

  if( GetMode())	  //4E1
  {
     if((StateSynce & MASK_BIT_4) &&
 	 (StateSynce & MASK_BIT_5) &&
	 (StateSynce & MASK_BIT_6) &&
	 (StateSynce & MASK_BIT_7))
	 State=0x40; 
  	 else  State=0x00;
  }
  else		 //3E1
  {
     if((StateSynce & MASK_BIT_4) &&
 	 (StateSynce & MASK_BIT_5) &&
	 (StateSynce & MASK_BIT_6) 
	 )
	 State=0x40; 
  	 else  State=0x00;
  }
  if(StateRS &  0x10) State|=0x10;
  return (unsigned long)State;
}


 extern "C" void FillSynceVersion1(char * out_str , long len)
{
// char * pData;
// uint_32 cnt;
// cnt = 0;

 unsigned char StateSynce;
  /*

StateSynce = read_xil_char((unsigned long )STATE_REGISTER);
 
// printf("\n\r > 0x%X",StateSynce );


unsigned char * pxil;
pxil = (unsigned char *)0x300000E3; 




StateSynce = *pxil;
 
// printf("\n\r > 0x%X",StateSynce );
   */

 

 StateSynce = inportb((unsigned long )STATE_REGISTER);
 
 //printf("\n\r > 0x%X",StateSynce );

  if(StateSynce & MASK_BIT_4) *out_str++ = '+'; else  *out_str++ =  '-';
  *out_str++ =  ' ';
 if(StateSynce & MASK_BIT_5) *out_str++ =  '+'; else  *out_str++ =  '-';
   *out_str++ =  ' ';
 if(StateSynce & MASK_BIT_6) *out_str++ =  '+'; else  *out_str++ =  '-';
   *out_str++ =  ' ';

 if( GetMode())	  //4E1
 {

 if(StateSynce & MASK_BIT_7) *out_str++ =  '+'; else  *out_str++ =  '-';
    *out_str++ =  ' ';
  if((StateSynce & MASK_BIT_0) &&
 	 (StateSynce & MASK_BIT_1) &&
	 (StateSynce & MASK_BIT_2) &&
	 (StateSynce & MASK_BIT_3))
	  {*out_str++ =  '¬';  }
  else 	  {*out_str++ =  'Õ'; }
 }
 else		 //3E1
 {
    *out_str++ =  '-';
    *out_str++ =  ' ';

  if(
     (StateSynce & MASK_BIT_0) &&
 	 (StateSynce & MASK_BIT_1) &&
	 (StateSynce & MASK_BIT_2) 
	)
	{*out_str++ =  '¬'; }
  	else
  	{*out_str++ =  'Õ'; }


 }




    *out_str = '\0';
 }





extern "C" void FillSynceVersion2()
{
 unsigned char StateSynce;
 unsigned char StateRS;
 
  StateSynce = inportb((unsigned long )STATE_REGISTER);
  StateRS = inportb((unsigned long ) Tx34);

  if( GetMode())	  //4E1
  {
	  if((StateSynce & MASK_BIT_0) &&
	 	 (StateSynce & MASK_BIT_1) &&
		 (StateSynce & MASK_BIT_2) &&
		 (StateSynce & MASK_BIT_3))
		  { Ret_code |= E14norma; }
	  else 	  { Ret_code &= ~(E14norma); }
  }
  else		 //3E1
  {
   
	  if(
	     (StateSynce & MASK_BIT_0) &&
	 	 (StateSynce & MASK_BIT_1) &&
		 (StateSynce & MASK_BIT_2) 
		)
		{ Ret_code |= E14norma;}
	  	else
	  	{ Ret_code &= ~(E14norma);}
 
  }
  if(StateRS &  0x10){  Ret_code |= RS_synck;  }else{ Ret_code &= ~RS_synck;}
}

 extern "C" void FillSound(char * out_str , long len)
{
// char * pData;
// uint_32 cnt;
// cnt = 0;

 unsigned char StateSynce;
  /*

StateSynce = read_xil_char((unsigned long )SOUND_STATE_REGISTER);
 
// printf("\n\r > 0x%X",StateSynce );


unsigned char * pxil;
pxil = (unsigned char *)0x300000E3; 




StateSynce = *pxil;
 
// printf("\n\r > 0x%X",StateSynce );
   */

 

 StateSynce = inportb((unsigned long )SOUND_STATE_REGISTER);
 
 //printf("\n\r > 0x%X",StateSynce );
  *out_str++ = ' ';
  if(StateSynce & MASK_BIT_6) *out_str++ = '+'; else  *out_str++ =  '-';
  *out_str++ =  ' ';
  if(StateSynce & MASK_BIT_4) *out_str++ =  '+'; else  *out_str++ =  '-';
  *out_str = '\0';
 }





#endif //PROG_DTVM 


#ifdef PROG_PU_MSAT
 extern "C" void FillRadianVersion()
{
 char * pfillstr;
 char * pData;
 uint_32 cnt;
 char MakedName[5];
 for(unsigned i =0; i++; i<5)
 {
  MakedName[i] = '+';
 }
 // MakedName[2] = '\.';



// cnt = 0;
// cnt = DISP_LEN - len ; // 
 pData = &XilFileData.Value[0];
 pfillstr = &theAnyStrings.cVersion[0];
 pfillstr += 13;
 
 

 cnt = 40;
// cnt = DISP_LEN - 7;
 while(* pData)
 {
  cnt--;
  if (!cnt)  break;
//  if(* pData == '_')
//  {
//   *pData = '.';
//  }
//  else
  
  if(* pData++ == '.') break;
 // if(* pData == '_') *pData = '.';

 //pData++;
 }
//---------------------------
 i = 5;
 pData--;
  pData--;

 while((cnt < 40)  && i)
 {
 // printfpd(" %c",* pData);
 //  *pfillstr++  =  * pData;

  if(* pData == '_')
  {
   *pData = '.';
  }



  MakedName[i-1] = * pData--;
  //if(!i) break;
  i--;
  cnt++;
 }
 //  MakedName[2] = '\.';
 //	printfp("____");

 for(i=0; i<5; i++)
 {
 // printfpd(" %d: ",i);
 // printfpd("%c",MakedName[i]);
  if(MakedName[i])
  *pfillstr++  = MakedName[i];
 }
// *pfillstr = '\0';
// printfp("++++");


//------------------------------
  /*
  pData -= 6;	  //hier can be crash


if(*pData != '0')
{
  *pfillstr++ = *pData++;
//  cnt--;
} 
else
{
 // *pfillstr++ = ' ';
 pData++;
}
*pfillstr++ = *pData++;
//cnt--;

pData++;
*pfillstr++ = '.';
//cnt--;

*pfillstr++ = *pData++;
//cnt--;

*pfillstr++ = *pData++;
//cnt--;
	*/

//printfp(theAnyStrings.cVersion);
}
#endif //PROG_PU_MSAT

 extern "C" void FillXilinxVersion1(char * out_str , long len)
{
 char * pData;
 uint_32 cnt;
// cnt = 0;
 cnt = DISP_LEN - len ; // 
 pData = &XilFileData.Value[0];

// cnt = 40;
 cnt = DISP_LEN;
 while(* pData)
 {
  cnt--;
  if (!cnt)  break;
  if(* pData++ == '.') break;
  }
  pData++;
  pData++;
  pData++;

 if(DISP_LEN > len)
 {
 cnt = DISP_LEN - len ;
 }
 while(* pData)
 {
  cnt--;
  if (!cnt)  break;
 *out_str++ =  *pData++;
  }
  *out_str = '\0';
 }







extern "C" void MakeIPAddresses(void)
{
 IPAddress3.Value 		  = 	((uint_32)IPAddress.Value >> 24)	& 0xff;
 IPAddress3.ChangingValue = 	((uint_32)IPAddress.Value >> 24)	& 0xff;
 IPAddress2.Value 		  = 	((uint_32)IPAddress.Value >> 16)	& 0xff;
 IPAddress2.ChangingValue = 	((uint_32)IPAddress.Value >> 16)	& 0xff;
 IPAddress1.Value 		  = 	((uint_32)IPAddress.Value >> 8)	& 0xff;
 IPAddress1.ChangingValue = 	((uint_32)IPAddress.Value >> 8)	& 0xff;
 IPAddress0.Value 		  = 	((uint_32)IPAddress.Value)	& 0xff;
 IPAddress0.ChangingValue = 	((uint_32)IPAddress.Value)	& 0xff;
}



extern "C" uint_32 SetIp(char_ptr pBuf)
{
 uint_32 IpAddress;
 uint_32 sg;
 char Buf[4];
 char bufstop[] = "1234567890";
 char * stopstring;
 stopstring = &bufstop[0];
//_____________________________________
 for(int i = 0; i < 3; i++)
 {
   Buf[i] = 0;
 }
  for(i = 0; i < 3; i++)
 {
   Buf[i] = *pBuf++;
   if(((*pBuf) < '0') || ((*pBuf) > '9')) break;
 }
  Buf[3] = 0;
 sg = strtoll(&Buf[0], &stopstring, 10);

 IpAddress = sg << 24;
 pBuf++;
 //_______________________________________
 for(i = 0; i < 3; i++)
 {
   Buf[i] = 0;
 }
  for(i = 0; i < 3; i++)
 {
   Buf[i] = *pBuf++;
   if(((*pBuf) < '0') || ((*pBuf) > '9')) break;
 }
  Buf[3] = 0;
 sg = strtoll(&Buf[0], &stopstring, 10);
//ok sg = 0x55; //t
 IpAddress += sg << 16;
  pBuf++;
 //_______________________________________
   for(i = 0; i < 3; i++)
 {
   Buf[i] = 0;
 }
  for(i = 0; i < 3; i++)
 {
   Buf[i] = *pBuf++;
   if(((*pBuf) < '0') || ((*pBuf) > '9')) break;
 }
  Buf[3] = 0;
 sg = strtoll(&Buf[0], &stopstring, 10);
//ok sg = 0x55; //t
 IpAddress += sg << 8;
  pBuf++;
 //_______________________________________
   for(i = 0; i < 3; i++)
 {
   Buf[i] = 0;
 }
  for(i = 0; i < 3; i++)
 {
   Buf[i] = *pBuf++;
   if(((*pBuf) < '0') || ((*pBuf) > '9')) break;
 }
  Buf[3] = 0;
 sg = strtoll(&Buf[0], &stopstring, 10);
//ok sg = 0x55; //t
 IpAddress += sg;
 //_______________________________________
 IPAddress.Value = 	 IpAddress;
 IPAddress.ChangingValue = 	 IpAddress;
 IPAddress.WriteStorageC((IPAddressStorage), (IpAddress));
 WriteDevId();
 IPAddress.pControl->Operate(IPAddress.OprNum);
//  IpAddress = 234; //t
 return IpAddress;
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : CRCs0()
* Returned Value   : none
* Comments         :
*    Cyclic read cs0
*END*----------------------------------------------------------------------*/
extern "C" void CRCs0 (void )
{
   long rch;
   long addr = 0;
   for(long i = 0x500; i > 0; i-- )
         { /* Body */
           _io_fseek (fn_ptr ,addr ,IO_SEEK_SET );
            rch =  fgetc(fn_ptr);
#ifndef USART0_TRY_PDC_1T
               printf("> cs0 readed char: %#02x   wait: %04d address: 0x%04x \r",rch, i, addr); 
#endif          
               addr++;
               if(addr == (long)(NVRAM_SIZE)) addr = 0;
         } /* Endbody */
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : CWCs0()
* Returned Value   : none
* Comments         :
*    Cyclic write cs0
*END*----------------------------------------------------------------------*/
extern "C" void CWCs0 (void )
{
  long addr = 0;
  for(long i = 0x500; i > 0; i-- )
         { /* Body */
           _io_fseek (fn_ptr , addr ,IO_SEEK_SET );
           fputc((char)(i & 0xff), fn_ptr);      //      rch = 0x23; //t
#ifndef USART0_TRY_PDC_1T
           printf("> cs0 writed char: 0x%02x   wait: %04d address: 0x%04x  \r",(i & 0xff), i, addr); 
#endif
           addr++;
           if(addr == (long)(NVRAM_SIZE)) addr = 0;
          } /* Endbody */
 }

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : CRCs2()
* Returned Value   : none
* Comments         :
*    Cyclic read cs2
*END*----------------------------------------------------------------------*/
extern "C" void CRCs2 (void )
{

   long rch;
   long addr = 0;
   for(long i = 0x500; i > 0; i-- )
         { /* Body */
           _io_fseek (fx_ptr ,addr ,IO_SEEK_SET );
            rch =  fgetc(fx_ptr);
#ifndef USART0_TRY_PDC_1T
               printf("> cs2 readed char: %#02x   wait: %04d address: 0x%04x \r",rch, i, addr); 
#endif  
               addr++;
               if(addr == (long)(XILINX_SIZE)) addr = 0;
         } /* Endbody */
 }
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : CWCs2()
* Returned Value   : none
* Comments         :
*    Cyclic read cs2
*END*----------------------------------------------------------------------*/
extern "C" void CWCs2 (void )
{
  long addr = 0;
  for(long i = 0x500; i > 0; i-- )
         { /* Body */
           _io_fseek (fx_ptr , addr ,IO_SEEK_SET );
           fputc((char)(i & 0xff), fx_ptr);      //      rch = 0x23; //t
           printf("> cs2 writed char: 0x%02x   wait: %04d address: 0x%04x  \r",(i & 0xff), i, addr); 
           addr++;
           if(addr == (long)(XILINX_SIZE)) addr = 0;
          } /* Endbody */

 }
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SetDate()
* Returned Value   : none
* Comments         :
*    Set date in timekeeper
*END*----------------------------------------------------------------------*/
extern "C" void SetDate (void )
{
     const int BufSize = 8;
     long wd = 1000000l;
     char Buf[BufSize];
     int status;
     _mqx_int rch = 0;
     status = 1;
#ifndef USART0_TRY_PDC_1T
     printf("\n\rSet Date: yy/mm/dd >");
#endif
     fflush (fh_ptr);
    for(int i = 0; i < BufSize; i++)
   { /* Body */
 //     fflush (fh_ptr);

     while ( (!(_io_fstatus(fh_ptr))) && (wd))
     { wd--; if(!wd){ i = BufSize - 1; status = 0;}}  
      rch = fgetc(fh_ptr);
      Buf[i] = rch;
      wd = 1000000l;
  } /* Endbody */
   if(status){ /* Body */
#ifndef USART0_TRY_PDC_1T
      printf("\n\r>Date : ");
#endif
     for(i = 0; i < BufSize; i++)
   {
#ifndef USART0_TRY_PDC_1T
       printf("%c ", (Buf[i] & 0xff));
#endif
  //     printf("\'%d\' ", (Buf[i]));
   }
#ifndef USART0_TRY_PDC_1T
      printf("                 \n\r>");
#endif
    write_nvram_char(0x1FF8, 0x80); //bit d7 to "1"	 - can write registers
    write_nvram_char(0x7fff,( ( (Buf[0] - '0') << 4) | (Buf[1] - '0') ) );
    write_nvram_char(0x7ffe,( ( (Buf[3] - '0') << 4) | (Buf[4] - '0') ) );
    write_nvram_char(0x7ffd,( ( (Buf[6] - '0') << 4) | (Buf[7] - '0') ) );
    write_nvram_char(0x1FF8, 0x00); //bit d7 to "0"	 - set date to counters
  } /* Endbody status */
   else{ /* Body */
#ifndef USART0_TRY_PDC_1T
     printf("\n\r>...Timeout\n\r> ");
#endif
 } /* Endbody */
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SetTime()
* Returned Value   : none
* Comments         :
*    Set time in timekeeper
*END*----------------------------------------------------------------------*/
extern "C" void SetTime (void )
{
     const int BufSize = 8;
     long wd = 1000000l;
     char Buf[BufSize];
     int status;
     _mqx_int rch = 0;
     status = 1;
#ifndef USART0_TRY_PDC_1T
     printf("\n\rSet Time: hh/mm/ss >");
#endif
     fflush (fh_ptr);
    for(int i = 0; i < BufSize; i++)
   { /* Body */
 //     fflush (fh_ptr);

     while ( (!(_io_fstatus(fh_ptr))) && (wd))
     { wd--; if(!wd){ i = BufSize - 1; status = 0;}}  
      rch = fgetc(fh_ptr);
      Buf[i] = rch;
      wd = 1000000l;
      } /* Endbody */
   if(status){ /* Body */
      printf("\n\r>Time : ");
     for(i = 0; i < BufSize; i++)
   {
#ifndef USART0_TRY_PDC_1T
       printf("%c ", (Buf[i] & 0xff));
#endif
  //     printf("\'%d\' ", (Buf[i]));
   }
#ifndef USART0_TRY_PDC_1T
    printf("                 \n\r>");
#endif
    write_nvram_char(0x1FF8, 0x80); //bit d7 to "1"	 - can write registers
    write_nvram_char(0x7ffb,( ( (Buf[0] - '0') << 4) | (Buf[1] - '0') ) );
    write_nvram_char(0x7ffa,( ( (Buf[3] - '0') << 4) | (Buf[4] - '0') ) );
    write_nvram_char(0x7ff9,( ( (Buf[6] - '0') << 4) | (Buf[7] - '0') ) );
    write_nvram_char(0x1FF8, 0x00); //bit d7 to "0"	 - set date to counters
  } /* Endbody status */
   else{ /* Body */
#ifndef USART0_TRY_PDC_1T
     printf("\n\r>...Timeout\n\r> ");
#endif
 } /* Endbody */
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : ExchangeData()
* Returned Value   : none
* Comments         :
*    Exchange Data with Devise
*END*----------------------------------------------------------------------*/
extern "C" void ExchangeData (void )
{
     const int BufSize = 23;
     long wd = 6000000l;
     char Buf[BufSize];
     uint_32 data_len;
     int status;
     _mqx_int rch = 0;
     status = 1;
#ifndef USART0_TRY_PDC_1T

     printf("\n\r>Exchange Data With Devise\n\r>to write : address(hex):data(hex) (f.e.0x20000000:0x12345678)\n\r");
     printf(">to read : address(hex) (f.e.0x20000000) \n\r>");
#endif
     fflush (fh_ptr);
     for(int i = 0; i < (BufSize - 1); i++)
      {Buf[i] = 0; }
     for(i = 0; i < (BufSize - 2); i++)
      { /* Body */
 //     fflush (fh_ptr);
      while ( (!(_io_fstatus(fh_ptr))) && (wd))
     { wd--; if(!wd){ i = BufSize - 2; status = 0;}}  
      rch = fgetc(fh_ptr);
      Buf[i] = rch;
      wd = 6000000l;
      if((i == 10) && ((rch & 0xff) != ':')) break;
      } /* Endbody */
   if(status){ /* Body */
#ifndef USART0_TRY_PDC_1T
      printf("\n\r> command:");
#endif
     for(i = 0; i < BufSize - 2; i++)
   {
     if((i == 10) && ((Buf[i] & 0xff) != ':')) break;
#ifndef USART0_TRY_PDC_1T
       printf("%c ", (Buf[i] & 0xff));
#endif
  //     printf("\'%d\' ", (Buf[i]));
   }
#ifndef USART0_TRY_PDC_1T

    printf("                 \n\r> operate:");
#endif
    //hier add DeviseData()
    Buf[(BufSize-1)] = 0; //
    DeviseData((uchar_ptr)&Buf[0], &data_len);
    for(i = 0; i < (BufSize); i++)
   {
#ifndef USART0_TRY_PDC_1T
       printf("%c ", (Buf[i] & 0xff));
#endif
  //     printf("\'%d\' ", (Buf[i]));
   }
#ifndef USART0_TRY_PDC_1T
     printf("\n\r> ");
#endif
 /*   write_nvram_char(0x1FF8, 0x80); //bit d7 to "1"	 - can write registers
    write_nvram_char(0x7ffb,( ( (Buf[0] - '0') << 4) | (Buf[1] - '0') ) );
    write_nvram_char(0x7ffa,( ( (Buf[3] - '0') << 4) | (Buf[4] - '0') ) );
    write_nvram_char(0x7ff9,( ( (Buf[6] - '0') << 4) | (Buf[7] - '0') ) );
    write_nvram_char(0x1FF8, 0x00); //bit d7 to "0"	 - set date to counters      */
  } /* Endbody status */
   else{ /* Body */
#ifndef USART0_TRY_PDC_1T
     printf("\n\r>...Timeout\n\r> ");
#endif
 } /* Endbody */
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SetIpAddress()
* Returned Value   : none
* Comments         :
*    Set IP address to devise
*END*----------------------------------------------------------------------*/
extern "C" void SetIpAddress (void )
{
     const int BufSize = 16;
     long wd = 6000000l;
     char Buf[BufSize];
 //    uint_32 data_len;
     int status;
     uint_32 IpAddress;
     int pointcnt;
     pointcnt = 0; 
     _mqx_int rch = 0;
     status = 1;
#ifndef USART0_TRY_PDC_1T
     printf("\n\r>Set IP Address (f.e 155.155.155.15)\n\r>");
#endif
     fflush (fh_ptr);
     for(int i = 0; i < (BufSize - 1); i++)
      {Buf[i] = 0; }
     for(i = 0; i < (BufSize - 1); i++)
      { /* Body */
 //     fflush (fh_ptr);
      while ( (!(_io_fstatus(fh_ptr))) && (wd))
     { wd--; if(!wd){ i = BufSize - 1; status = 0;}}  
      rch = fgetc(fh_ptr);
      Buf[i] = rch;
      wd = 6000000l;
      if((rch < '0') || (rch > '9')) pointcnt++;
      if(pointcnt == 4) break;
   //   if((i == 10) && ((rch & 0xff) != ':')) break;
      } /* Endbody */
   if(status){ /* Body */
#ifndef USART0_TRY_PDC_1T
      printf("\n\r>Set IP Address: ");
#endif
     for(i = 0; i < BufSize - 1; i++)
   {
  //   if((i == 10) && ((Buf[i] & 0xff) != ':')) break;
#ifndef USART0_TRY_PDC_1T
       printf("%c ", (Buf[i] & 0xff));
#endif
  //     printf("\'%d\' ", (Buf[i]));
   }
  //  printf("                 \n\r> operate:");
    //hier add DeviseData()
    Buf[(BufSize-1)] = 0; //
    IpAddress = SetIp((char_ptr)&Buf[0]);
    MakeIPAddresses();
#ifndef USART0_TRY_PDC_1T
    printf("\n\r>0x%08x", IpAddress);
#endif
 //   DeviseData((uchar_ptr)&Buf[0], &data_len);
 //hier call setip, writened  in .cpp file - to work with classes
 //   for(i = 0; i < (BufSize); i++)
 //  {
 //      printf("%c ", (Buf[i] & 0xff));
  //     printf("\'%d\' ", (Buf[i]));
 //  }
#ifndef USART0_TRY_PDC_1T
     printf("\n\r> ");
#endif
 /*   write_nvram_char(0x1FF8, 0x80); //bit d7 to "1"	 - can write registers
    write_nvram_char(0x7ffb,( ( (Buf[0] - '0') << 4) | (Buf[1] - '0') ) );
    write_nvram_char(0x7ffa,( ( (Buf[3] - '0') << 4) | (Buf[4] - '0') ) );
    write_nvram_char(0x7ff9,( ( (Buf[6] - '0') << 4) | (Buf[7] - '0') ) );
    write_nvram_char(0x1FF8, 0x00); //bit d7 to "0"	 - set date to counters      */
  } /* Endbody status */
   else{ /* Body */
#ifndef USART0_TRY_PDC_1T
     printf("\n\r>...Timeout\n\r> ");
#endif
 } /* Endbody */
}
 
//tvoid m_uart_init(void)



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_uart_init  m_uart_monitor
* Returned Value   : none
* Comments         :
*    This function init debug uart
*
*END*----------------------------------------------------------------------*/

extern "C"  void m_uart_monitor(void)
{ 
  
   uint_32 cnt, mode, cnt1, timeout_b_ping, timeout_a_ping;
  _mqx_int rch;
  timeout_b_ping =  150000;
  timeout_a_ping =  600000;
    //debug uart maked globally in init_bsp
   /*
    pointer fh_ptr;
   _bsp_atevbrm9200_uart_init.DEVICE =  UART_DBUG;
   _bsp_atevbrm9200_uart_init.QUEUE_SIZE =  1024;
   _bsp_atevbrm9200_uart_init.BAUD_RATE =  555200;
   _bsp_atevbrm9200_uart_init.BITS_PER_CHARACTER =  8;
   _bsp_atevbrm9200_uart_init.PARITY =  IO_SERIAL_NO_PARITY;
   _bsp_atevbrm9200_uart_init.STOP_BITS =  IO_SERIAL_1_STOP_BIT;
   _bsp_atevbrm9200_uart_init.WORD_SIZE =  IO_SERIAL_WORD_SIZE_8;
   _bsp_atevbrm9200_uart_init.VECTOR =  AT91RM9200_SYS_DBUG_VECTOR;
   _bsp_atevbrm9200_uart_init.CLOCK_SPEED =  BSP_MASTER_CLOCK;
   _bsp_atevbrm9200_uart_init.QUEUE_SIZE =  IRQ;
  _at91rm9200_dbug_uart_serial_polled_install( "uart:", &_bsp_atevbrm9200_uart_init, 
  _bsp_atevbrm9200_uart_init.QUEUE_SIZE); 
    fh_ptr = (pointer)_io_fopen1("uart:", IO_SERIAL_RAW_IO);    //hier is returned FILE_PTR
    */
   if (fh_ptr == NULL) {
  //   printf("cannot open file: uart\n");
 //     _mqx_exit(0);
   } else {
       
      _io_set_handle(IO_STDOUT, fh_ptr);      //ok
      fflush (fh_ptr);
    //    for(;;) printf("1");     

#ifndef USART0_TRY_PDC_1T
      printf("\n\r__________R A D I A N___________\r");
      printf("\n\nRadian SNMP Controller v_071206:\n\n\r");    //?
      printf("IP Address  : %3ld.%3ld.%3ld.%3ld \n\r", (uint_32)IPAddress3.Value, (uint_32)IPAddress2.Value, (uint_32)IPAddress1.Value, (uint_32)IPAddress0.Value);
      printf("MAC Address : %06lX%06lX\n\r", (uint_32)MAC0.Value, (uint_32)MAC1.Value);
	  printf("UART Address: %02X\n\r", (uint_32)UARTAddress.Value);
      printf("Devise ID   : %04lX\n\r", (uint_32)DevId.Value);
	  printf("Devise Year : %4ld\n\r", (uint_32)DevYear.Value);
  	  printf("Devise Ver1 : %04lX\n\r", (uint_32)DevVer1.Value);
  	  printf("Devise Ver2 : %04lX\n\r", (uint_32)DevVer2.Value);
	  printf("Test Mode   : %04lX\n\r", (uint_32)TestMode.Value);
	  printf("POK         : %04lX\n\r", (uint_32)POK.Value);


      printf("\n\r0: Cyclic read  cs0.\n\r");    //?
      printf("1: Cyclic write cs0.\n\r");    //?
      printf("2: Cyclic read  cs2.\n\r");    //?
      printf("3: Cyclic write cs2.\n\r");    //?
      printf("4: Set Date.\n\r");    //?
      printf("5: Set Time.\n\r");    //?
      printf("6: Exchange Data With Devise \n\r");    //?
      printf("7: Set IP Address.\n\r");    //?
 /*     printf("8: Read byte from any address.\n\r");    //?
      printf("9: Set Default settings.\n\r");    //?     */
      printf("r: Restart.\n\r");                           
      printf("s: Start main programm.\n\r");    //?
      printf(">");    //? 
#endif
           cnt =   timeout_b_ping;    //short wathdog without ping
           cnt1 = timeout_a_ping;    //long watchdog after ping
           mode = 1;
            fflush (fh_ptr);
            for(;;){ /* Body */
         //     while(!(_io_fstatus(fh_ptr)));
              rch = fgetc(fh_ptr);
           //t   fflush (fh_ptr);
              if(mode){ /* Body */
                     cnt -= 1;
                     if(!(cnt % 30000)){ /* Body */
#ifndef USART0_TRY_PDC_1T

                                   printf("          \r");
                     printf(">Hit any key to stop autoboot : %2d\r",(cnt /30000)); 
#endif                  
                     fflush (fh_ptr);
                          } /* Endbody */
                if(!cnt)  { /* Body */
#ifndef USART0_TRY_PDC_1T
                     printf(" ...Start...                       ");   
#endif
                     return; 
               } /* Endbody */
             } /* Endbody */
              else{ /* Body */  //mode = 0
                      cnt1 -= 1;    
                 if(!cnt1) { /* Body */
#ifndef USART0_TRY_PDC_1T
                      printf(" End of test mode...Start...       ");   
#endif
                      return;
                  } /* Endbody */
               } /* Endbody */  //mode   
#ifndef USART0_TRY_PDC_1T
         
      switch( rch){ 
       case '0' :    printf(" %c ...Cyclic read  cs0.               \r>", rch); mode = 0;  cnt1 = timeout_a_ping; CRCs0();        break;   //?
       case '1' :    printf(" %c ...Cyclic write cs0.               \r>", rch); mode = 0;  cnt1 = timeout_a_ping; CWCs0();        break;   //?
       case '2' :    printf(" %c ...Cyclic read  cs2.               \r>", rch); mode = 0;  cnt1 = timeout_a_ping; CRCs2();        break;   //?
       case '3' :    printf(" %c ...Cyclic write cs2.               \r>", rch); mode = 0;  cnt1 = timeout_a_ping; CWCs2();        break;   //?
       case '4' :    printf(" %c ...Set Date.                       \r>", rch); mode = 0;  cnt1 = timeout_a_ping; SetDate();      break;   //?
       case '5' :    printf(" %c ...Set Time.                       \r>", rch); mode = 0;  cnt1 = timeout_a_ping; SetTime();      break;   //?
       case '6' :    printf(" %c ...Exchange Data Witch Devise.     \r>", rch); mode = 0;  cnt1 = (timeout_a_ping * 5l); ExchangeData(); break;   //?
       case '7' :    printf(" %c ...Set IP Address.                 \r>", rch); mode = 0;  cnt1 = timeout_a_ping; SetIpAddress(); break;   //?
       case '8' :    printf(" %c ...Read byte from any address.     \r>", rch); mode = 0;  cnt1 = timeout_a_ping;                 break;   //?
       case '9' :    printf(" %c ...Set Default settings.           \r>", rch); mode = 0;  cnt1 = timeout_a_ping;                 break;   //? 
       case 'r' :    printf(" %c ...Restart...                         ", rch);
                     //try through watch dog?
               //      _int_disable();
               //      _mqx(MQX_init_struct);
                 //    _mqx_exit(0); // jump(0x100000);//jump(0x20000f20);   //?
                   //  jump(0x20000000l);
                   dev_restart(); break;
       case 's' :    printf(" %c ...Start...                           ", rch);  return;  //?
       default  :    ;//printf(" ...Start...\n\r");                    return; // printf("\r> %d", cnt);  
                   }
#endif

              fflush (fh_ptr);
     }  //for
   }
} 



extern "C" unsigned char TestAddrChar(unsigned char tch, unsigned char move)
{
 unsigned char ret;
 unsigned char tstch;
 tstch = Hex2Char(tch);
 if(( tstch == (((unsigned char)UARTAddress.Value >> move) & 0xf)) || (tstch == 0xf) || (tstch == 0xF))
 { ret = 1; }
 else {ret = 0;}
 return	ret;
}

  /*
extern "C" void NVRAM_TEST(void)
{
  char *pNVRAM = NVRAM_BASE;
  *pNVRAM++ = 1;
   *pNVRAM++ = 2;
    *pNVRAM++ = 3;
	 *pNVRAM++ = 4;
	   *pNVRAM++ = 5;
	    *pNVRAM++ = 6;
}

 */

extern "C" void Set_enet_local0(uchar* p_enet_local0)
{
 *p_enet_local0++ = (uchar)((int)MAC0.Value >> 16);
 *p_enet_local0++ = (uchar)((int)MAC0.Value >> 8);
 *p_enet_local0++ = (uchar)((int)MAC0.Value);
 *p_enet_local0++ = (uchar)((int)MAC1.Value >> 16);
 *p_enet_local0++ = (uchar)((int)MAC1.Value >> 8);
 *p_enet_local0   = (uchar)((int)MAC1.Value);
}


extern "C" void SendBuffToMf(char * pBuf)
{
  while(*pBuf)
  {

   embRS232_rcvbuf_Add((unsigned char)(* pBuf++)); 

  // MessageChar(1,1,*pBuf);
  }
}

//extern "C" void printd(unsigned char tch)
//{
//        fputc(tch, fh_ptr); 
//}



 
extern "C" void Transmit0c(unsigned char tch)
{
  static unsigned char counter;		 //temporary
  if(UsedExp.State.Reg1.bit.Mf20SnmpOn == 0)
  {
#ifndef TEST_TWO485

#ifndef TRY_FIND_ERR

//#ifndef CHECK_LOSS_MEM
#ifdef 	PROG_BMDN6
if(!used_TCP)
{
#endif
#ifdef 	PROG_COMMUTATOR1
if(!used_TCP)
{
#endif

#ifdef PROG_PU_M710
if(!used_TCP)
{
#endif


   //      fputc(tch, fusart0_ptr); 
#ifndef USART0_TRY_PDC_1T
         fputc(tch, fusart0_ptr); 
#else

#ifndef PROG_BACO
#ifndef PROG_ODU1
         ToPdcTu0(tch);
#endif //PROG_ODU2
#endif
#endif 
#ifdef PROG_PU_M710
}
#endif

#ifdef 	PROG_COMMUTATOR1
}
#endif //PROG_COMMUTATOR1

#ifdef 	PROG_BMDN6
}
#endif //PROG_BMDN6
//#else

//  ToPdcTu0(tch); //t


//#endif //CHECK_LOSS_MEM 

#endif //TRY_FIND_ERR

#endif //TEST_TWO485          


#ifdef  TCPIP_CONNECT
#ifndef PROG_PRM_PCH

	 	if(buffer_rad_T_len >= (BUFFER_SIZE_T)) 
//	if(buffer_rad_T_len >= 100)    //t091221
		{
	 		buffer_rad_T_len = 0;
//			buffer_rad_T_len = BUFFER_SIZE_T - 2;	//091221t
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;
#ifdef TRY_FIND_ERR
//printfpd(" %d", buffer_rad_T_len);
//printfpd(" %c", tch);
#endif



	 //t	printf(" %d", buffer_rad_T_len);

#endif //PROG_PRM_PCH
#endif // TCPIP_CONNECT
  }
  else
  {
   	   _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  	    counter++;		//
	    Mf20DataR.Value = tch + (counter << 8); //temporary

// if(UsedExp.State.Reg1.bit.WTBuff1)
// {
	   if(TBuffer1.len == ((Uint16)TBUFF1_VALUE - 1) & 0xffff) 
		{
   		 TBuffer1.len = 3;  //thirty byte to burst counter
 //		 my_printf(0x77);
  		}
	  	TBuffer1.Value[TBuffer1.len & 0xffff] = tch;
	//   	TBuffer1.len += 1;	 
		TBuffer1.len ++;
	   	TBuffer1.Value[0] = TBuffer1.len & 0xff;
		TBuffer1.Value[1] = (TBuffer1.len >> 8) | 0x80; //this bit need later delete
//  }
//  else
 // {
 //	   if(TBuffer2.len == ((Uint16)TBUFF1_VALUE - 1) & 0xffff) 
 //		{
 // 		 TBuffer2.len = 3;  //thirty byte to burst counter
 //		 my_printf(0x77);
 // 		}
 //	  	TBuffer2.Value[TBuffer2.len & 0xffff] = tch;
 //	   	TBuffer2.len += 1;
 //	   	TBuffer2.Value[0] = TBuffer2.len & 0xff;
 //		TBuffer2.Value[1] = (TBuffer2.len >> 8) | 0x80; //this bit need later delete
 // }
   	  _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  	  				      BSP_ENET_INTERRUPT_PRIORITY);
 }
}
 extern "C" void RS485_receive_disable()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_DISABLE;
}

 extern "C" void RS485_receive_enable()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE;
}

 extern "C" void RS485_receive_reset()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_RESET;
}

 extern "C" void RS485_disable_RX_interrupt()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
  usart1_ptr->IDR = AT91RM9200_DBGU_IDR_RX_READY_INT_DISABLE;
}

extern "C" void RS485_enable_RX_interrupt()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
  usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
  usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;
}

extern "C" void _at91rm9200_usart1_int_putc
   (
      /* [IN] the address of the device specific information */
      IO_SERIAL_INT_DEVICE_STRUCT_PTR int_io_dev_ptr,

      /* [IN] the character to write out now */
      char                       c
   );

extern "C" void Transmit485c(unsigned char tch)
{
  //static unsigned char counter;		 //temporary
  //FILE_DEVICE_STRUCT_PTR fd_ptr;
  //IO_SERIAL_INT_DEVICE_STRUCT_PTR int_io_dev_ptr;
  //IO_DEVICE_STRUCT_PTR            io_dev_ptr;
  //	 return; //to test
 // AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr; //091118

   if(UsedExp.State.Reg1.bit.Mf20SnmpOn == 0)
  {
 //	 usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;

   //	  usart1_ptr->IDR = AT91RM9200_DBGU_IDR_RX_READY_INT_DISABLE;	 //091118

  //	  fputc(tch, fusart1_ptr);   //maked as rs485
#ifndef USART1_TRY_PDC_1T
         fputc(tch, fusart1_ptr); 
#else
         ToPdcTu1(tch);

#endif      

   //	  usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;	  //091118


	//	   _io_serial_int_write(fusart1_ptr, &tch, 1); //t
	//		fd_ptr = (FILE_DEVICE_STRUCT_PTR)fusart1_ptr;
	  //	    io_dev_ptr     = fd_ptr->DEV_PTR;
   		//	int_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;
		 //	 int_io_dev_ptr->OUTPUT_ENABLED = TRUE;
      	//	(*int_io_dev_ptr->DEV_PUTC)(int_io_dev_ptr, tch);
	  	//   _io_serial_int_putc_internal(int_io_dev_ptr, tch);
		// _at91rm9200_usart1_int_putc(int_io_dev_ptr, tch);
//   usart1_ptr->PDC.TPR = (uint_32)io_info_ptr->TX_BUFF_PTR;
 //t	usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
 //t	usart1_ptr->PDC.TPR = (unsigned long)&tch;
 //  usart1_ptr->PDC.TCR = count;
 //t  usart1_ptr->PDC.TCR = 1;
 //t  usart1_ptr->PDC.TNPR = 0;
 //t  usart1_ptr->PDC.TNCR = 0;

   /* Interrupt when transmission is completed */
 //t  usart1_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
 //t  usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;
 //my

   }
  else
  {
   	   _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  	 //   counter++;		//
   //	    Mf20DataR.Value = tch + (counter << 8); //temporary

// if(UsedExp.State.Reg1.bit.WTBuff1)
// {
	   if(TBuffer2.len == ((Uint16)TBUFF1_VALUE - 1) & 0xffff) 
		{
   		 TBuffer2.len = 3;  //thirty byte to burst counter
		 my_printf(0x77);
  		}
	  	TBuffer2.Value[TBuffer2.len & 0xffff] = tch;
	//   	TBuffer1.len += 1;	 
		TBuffer2.len ++;
	   	TBuffer2.Value[0] = TBuffer2.len & 0xff;
		TBuffer2.Value[1] = (TBuffer2.len >> 8) | 0x80; //this bit need later delete
//  }
//  else
 // {
 //	   if(TBuffer2.len == ((Uint16)TBUFF1_VALUE - 1) & 0xffff) 
 //		{
 // 		 TBuffer2.len = 3;  //thirty byte to burst counter
 //		 my_printf(0x77);
 // 		}
 //	  	TBuffer2.Value[TBuffer2.len & 0xffff] = tch;
 //	   	TBuffer2.len += 1;
 //	   	TBuffer2.Value[0] = TBuffer2.len & 0xff;
 //		TBuffer2.Value[1] = (TBuffer2.len >> 8) | 0x80; //this bit need later delete
 // }
   	  _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  	  				      BSP_ENET_INTERRUPT_PRIORITY);
 }
}






extern "C" void StartSaveCommut()
{
  UsedExp.State.Reg2.bit.SSC = 1;
  UsedExp.State.Reg2.bit.Some = 1;
  CurSlot = 0;
}



extern "C" void my_printf(unsigned char ch1)
{
#ifndef USART0_TRY_PDC_1T
 printf("\n\r %02X ", ch1);
#endif
}

//extern "C" void my_printfc( char *ch1)
//{
// printf("\n\r %s ", ch1);
//}

extern "C" void SetNVRAMToData(unsigned char data)
{
 unsigned char * pRam;
 pRam = (unsigned char *)(NVRAM_BASE);
 for(long i = 0; i <((long)(NVRAM_SIZE) - (long)(CLOCK_REGISTERS)); i++)
 {
  *pRam++ = data;
 }

}

extern "C" void SetSlowClock()
{
  AT91RM9200_PMC_REG_STRUCT_PTR  pmc_ptr;
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR) AT91RM9200_PMC_BASE;
   pmc_ptr->MCKR = 0; //slow clocks
  pmc_ptr->SCDR = 0xff; //disable all clocks

}

extern "C" void ChangeTestMode()
{

 printfpd :("\n\rChangeTestMode() 0x%x \n\r",TestMode.Value );
        OperateBuffers_usart0t();

#if TESTS_ENABLED

  Uint32 tm;

char Buff[32];

for(long b = 0; b < 32; b++)
{
Buff[b] = b;
}






  uint_32 sel =  (uint_32)TestMode.Value;
 //t if(sel )
//130917  if(sel)
  if(sel != 0x1l)
  {
	TestMode.Value = 1l;
	TestMode.ChangingValue = TestMode.Value;
	WriteDevId();
  }

  //	switch((uint_32)TestMode.Value)
	switch(sel)
	{
    	   //		   break;
      case 0l:
      			/* 130917
        DevId.Changable 	 = 1;  //test mode	 
	 		   	DevYear.Changable = 1;	
 	 		   	DevVer1.Changable = 1;	
 	 		   	DevVer2.Changable = 1;
			   	MAC0.Changable = 1;
			   	MAC1.Changable = 1;
 	   		   	m_uart_monitor();
  				//_________________________________________________________to not bloking in tests
 				_io_set_handle(IO_STDOUT, fusart0_ptr);  //t1109
  				usart_select(1); //debug uart off usart0 - on
				//_________________________________________________________to not bloking in tests
				  */

 	   		   	 break;
      case 1l:
       			break;
      			// TestMode.WriteStorageC((uint_32)TestModeStorage, 0);
      		 //  LoadAndJump();
			  //  UsedExp.State.Reg2.bit.LJ = 1;
			  //  UsedExp.State.Reg2.bit.Some = 1;
	  case 2l: // printf("\n\r\test");
			  //	wd_deinit();
  //				TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
				TestMode.Value = 2l;	 //set back to 2 // TO WORK TESTS
				TestMode.ChangingValue = TestMode.Value;

			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
#ifndef USART0_TRY_PDC_1T
   printf("\n\rTest Transit is started.\n\r");
#else
   printfp("\n\rTest Transit is started.\n\r");
#endif

				#ifdef PROG_PU_M
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
		   	   	 delay_mcs(1);
			  // 	 delay_mcs(10);
				 test_PU37();
			  	 wd_reset();
			  	}
				
//				printf("\n\rTest Transit is finished.\r\r");
				Init_PU_M();
			 //	#endif // FULL_TEST_TRANZIT
				#endif //	PROG_PU_M
				   /*
				#ifdef PROG_PU_M_V


			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
//#ifdef USART0_TRY_PDC_1T
//  OperateBuffers_usart0t();
//#endif

			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_PU_M();
			 //	#endif // FULL_TEST_TRANZIT



				#endif //	PROG_PU_M

				*/
			
			
			
				#ifdef PROG_UPS
		  		#endif //	PROG_UPS



			#ifdef PROG_PU_M100
			  	for(tm = 0l; tm <     3000000l; tm ++)
			  	{
#ifdef USART0_TRY_PDC_1T
  OperateBuffers_usart0t();
#endif

			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_PU_M();
			 //	#endif // FULL_TEST_TRANZIT
				#endif //	PROG_PU_M100

		#ifdef PROG_PU_MSAT
			  	for(tm = 0l; tm <     3000000l; tm ++)
			  	{
#ifdef USART0_TRY_PDC_1T
  OperateBuffers_usart0t();
#endif

			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_PU_M();
			 //	#endif // FULL_TEST_TRANZIT
				#endif //	PROG_PU_M100





				#ifdef PROG_BMD34
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
	//			printf("\n\rTest Transit is finished.\r\r");
				Init_BMD34();
				#endif //	PROG_BMD34

				#ifdef PROG_BMD35
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
	  //		    printf("\n\rTest Transit is started.\n\r");
	        	test_PU37_start(); //t101101
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
		//		printf("\n\rTest Transit is finished.\r\r");
				Init_BMD35();
				#endif //	PROG_BMD35

				#ifdef PROG_PROV
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
//090506	        	test_PU37_start();
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_PROV();
				#endif //	PROG_PROV



				#ifdef PROG_MPC35
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	      //  	test_PU37_start();
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_MPC35();
				#endif //	PROG_MPC35

#ifdef PROG_PRM_PCH_N
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 //	  	for(tm = 0l; tm < 2000000l; tm ++)
				for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			//   	Init_BMD155();
#endif //	PROG_BMD155



             

  				#ifdef PROG_BMD155
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		  	  	for(tm = 0l; tm < 2000000l; tm ++)
		 // 		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_BMD155();
				#endif //	PROG_BMD155
		 /*
	#ifdef PROG_COMMUTATOR
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		  	  	for(tm = 0l; tm < 2000000l; tm ++)
		 // 		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_COMMUTATOR();
				#endif //	PROG_BMD155
			   */

  				#ifdef PROG_BMDN
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		  	  	for(tm = 0l; tm < 800000l; tm ++)
		  //		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
		  //		 if(!(tm%100000)) printf("\n\r...%ld  counter : %ld", ((100000l - tm)/100000), InterruptWatchDog);

			  	 wd_reset();
			  	}
  		  //		printf("\n\n\n\rTest Transit is finished.\r\r");
	  //11011		   	Init_BMDN();
				#endif //	PROG_BMDN






				#ifdef PROG_PRM_PCH
				 /*
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 //	  	for(tm = 0l; tm < 2000000l; tm ++)
				for(tm = 0l; tm < 200000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PRM_PCH();
				  */
				#endif //	PROG_PRM_PCH

				#ifdef PROG_PU_M
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 	  	for(tm = 0l; tm < 2000000l; tm ++)
		  //		for(tm = 0l; tm < 200000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
			   //				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PU_M();
				#endif //	PROG_PU_M

				#ifdef PROG_PU_M_V
#ifndef PROG_COMMUTATOR1
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 	  	for(tm = 0l; tm < 2000000l; tm ++)
			//	for(tm = 0l; tm < 200000l; tm ++)
			  	{
			 //	  printfpd(" %ld", tm);
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PU_M();

#else
			//   OperateBuffers_usart0t();
		   //	  	for(tm = 0l; tm < 10000l; tm ++)
			//  	for(tm = 0l; tm < 10l; tm ++)
				for(tm = 0l; tm < 200000l; tm ++)
			  	{
			   	 delay_mcs(1);
		    //     printfpd(" %ld", tm);
		  		 test_PU37();
			  	 wd_reset();
			  	   OperateBuffers_usart0t();

			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PU_M();



#endif

				#endif //	PROG_PU_M_V


#ifdef PROG_PU_M_V_A
#ifndef PROG_COMMUTATOR1
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 	  	for(tm = 0l; tm < 2000000l; tm ++)
			//	for(tm = 0l; tm < 200000l; tm ++)
			  	{
			 //	  printfpd(" %ld", tm);
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PU_M();

#endif

				#endif //	PROG_PU_M_V_A



				#ifdef PROG_UPS
  				#endif //	PROG_UPS


				 /*

				#ifdef PROG_PU_M100
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 //	  	for(tm = 0l; tm < 2000000l; tm ++)
				for(tm = 0l; tm < 50000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
			   	Init_PU_M();
				#endif //	PROG_PU_M


					  */


				#ifdef PROG_PU_M_MUX
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		 	  	for(tm = 0l; tm < 2000000l; tm ++)
		 //		for(tm = 0l; tm < 200000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
			   //				printf("\n\rTest Transit is finished.\r\r");
			  // 	Init_PU_M();
				#endif //	PROG_PU_M_MUX




				#ifdef PROG_MPC155
		//	    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		  //	  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	  //      	test_PU37_startMX155();
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
		 //		 test_PU37MX155();

#ifdef IncEmbSerialMD34AVT
				 test_PU37();
#endif // IncEmbSerialMD34AVT

			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_MPC155();
				#endif //	PROG_MPC155

				#ifdef PROG_MPC4E
		//	    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		  //	  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	  //      	test_PU37_startMX155();
			  	for(tm = 0l; tm < 2000000l; tm ++)
			  	{
			   	 delay_mcs(1);
		 //		 test_PU37MX155();

#ifdef IncEmbSerialMD34AVT
				 test_PU37();
#endif // IncEmbSerialMD34AVT

			  	 wd_reset();
			  	}
//				printf("\n\rTest Transit is finished.\r\r");
				Init_MPC4E();
				#endif //	PROG_MPC4E


#ifndef USART0_TRY_PDC_1T
   printf("\n\rTest Transit is finished.\n\r");
#else
   printfp("\n\rTest Transit is finished.\n\r");
#endif





 //#ifndef FULL_TEST_TRANZIT
				TestMode.Value = 1l;	//set back testmode
				TestMode.ChangingValue = TestMode.Value;
//#endif //FULL_TEST_TRANZIT
				 break;

	 case 3l:

#ifndef USART0_TRY_PDC_1T
   printf("\n\rTest Tlf is started.\n\r");
   printf("\n\r...Start Ring Test\n\r");

#else
   printfp("\n\rTest Tlf is started.\n\r");
   printfp("\n\r...Start Ring Test\n\r");
   OperateBuffers_usart0t();
#endif
 //ok	break; //t 101007


	//			TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;

  				#ifdef PROG_PU_M
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test PU_M\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 800l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				#endif //	PROG_PU_M

  				#ifdef PROG_PU_M_V
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test PUM_V\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 500l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				#endif //	PROG_PU_M

		#ifdef PROG_PU_M_V_A
		   printfp("\n\r... Tone Test Not Used\n\r");

		/*
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test PUM_V\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 500l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				*/
				#endif //	PROG_PU_M_V_A


 				#ifdef PROG_UPS
				/*
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 200l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_UPS();
				*/
				#endif //	PROG_UPS


				#ifdef PROG_PU_M100
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
	        	StartTestTlf();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				#endif //	PROG_PU_M100


				#ifdef PROG_PU_MSAT
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
	        	StartTestTlf();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				#endif //	PROG_PU_M100



				#ifdef PROG_PU_M_MUX
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}

#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PU_M();
				#endif //	PROG_PU_M_MUX





			    #ifdef PROG_BMD34
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
 #ifndef USART0_TRY_PDC_1T
  		 printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_BMD34();
				#endif //	PROG_BMD34


			    #ifdef PROG_BMD35
   //		 		printf("\n\rTest Tlf is started.\n\r");

//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
// #ifndef USART0_TRY_PDC_1T
//  		 printf("\n\r...Start Ring Test\n\r");  
//#else
//   		printfp("\n\r...Start Ring Test\n\r");
//#endif

			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
 #ifndef USART0_TRY_PDC_1T
  		 printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif


//________________________________________________________________________
 			  	StartTestTlf();

				for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}



				 /*
				for(tm = 0l; tm < 200l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestRing();
			  	 wd_reset();
			  	}
				  */
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_BMD35();
				#endif //	PROG_BMD35

	    #ifdef PROG_PROV
//		 		printf("\n\rTest Tlf is started.\n\r");

//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
 #ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
//________________________________________________________________________
 			  	StartTestTlf();

				for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}



				 /*
				for(tm = 0l; tm < 200l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestRing();
			  	 wd_reset();
			  	}
				  */
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_PROV();
				#endif //	PROG_PROV



 		        #ifdef PROG_BMD155
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_BMD155();
				#endif //	PROG_BMD155

     #ifdef PROG_COMMUTATOR
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test of Commutator\n\r");
#endif
//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 800l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_COMMUTATOR();
				#endif //	PROG_BMD155



	        #ifdef PROG_BMDN
			#ifndef PROG_BMDN6MI
			 //		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
 //				printf("\n\r...Start Ring Test\n\r");
			    StartTestTlf();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif
//________________________________________________________________________

	        	StartTestTlf();
			  	for(tm = 0l; tm < 500l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlf();
			  	 wd_reset();
			  	}
 //				printf("\n\rTest Tlf is finished.\r\r");
  //110111				Init_BMDN();
  #endif // PROG_BMDN6M

				#endif //	PROG_BMDN

			  




      			#ifdef PROG_MPC155
 //		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
		 //	    StartTestTlf();
				StartTestTlfMX155();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlfMX155();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlfMX155();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_MPC155();
				#endif //	PROG_MPC155

    			#ifdef PROG_MPC4E
//		 		printf("\n\rTest Tlf is started.\n\r");
//________________________________________________________________________
//				printf("\n\r...Start Ring Test\n\r");
		 //	    StartTestTlf();
				StartTestTlfMPC4E();
				StartRing();
 			  	for(tm = 0l; tm < 100l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 if (TestRing()) 
				 {
		  	  	 break;
				 }
			  	 wd_reset();
			  	}
		//		printf("\n\r...Start Tone Test\n\r");
#ifndef USART0_TRY_PDC_1T
  		printf("\n\r...Start Tone Test\n\r");  
#else
   		printfp("\n\r...Start Tone Test\n\r");
#endif

//________________________________________________________________________

	        	StartTestTlfMPC4E();
			  	for(tm = 0l; tm < 400l; tm ++)
			  	{
			   	 delay_mcs(1);
			  	 TestTlfMPC4E();
			  	 wd_reset();
			  	}
//				printf("\n\rTest Tlf is finished.\r\r");
				Init_MPC4E();
				#endif //	PROG_MPC4E


#ifndef USART0_TRY_PDC_1T
   printf("\n\rTest Tlf is finished..\n\r");   

#else
   printfp("\n\rTest Tlf is finished..\n\r");
#endif



	 			break;
	 case 4l:	//transit 232-485
	  //		   TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
#ifndef USART0_TRY_PDC_1T	
	  			printf("\n\rTest RS485 is started.\n\r");
#else
			    printfp("\n\rTest RS485 is started.\n\r");

#endif


				TestMode.Value = 4l;	 //set back to 4
				TestMode.ChangingValue = TestMode.Value;
			//	TestMode4Counter = TESTMODE4_START;
		  //		 printf("\n\r ...case4");
			   TrzBuffs_Init(); //need init buffers
			   break;

 case 0x104l:	//transit 232-485
	  //		   TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
#ifndef USART0_TRY_PDC_1T	
	  			printf("\n\rTest RS485_USART2 is started.\n\r");
#else
			    printfp("\n\rTest RS485_USART2 is started.\n\r");

#endif


				TestMode.Value = 0x104l;	 //set back to 4
				TestMode.ChangingValue = TestMode.Value;
			//	TestMode4Counter = TESTMODE4_START;
		  //		 printf("\n\r ...case4");
			   TrzBuffs_Init(); //need init buffers
			   break;

 	 case 5l:	//
        //	   TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			   if(!Test_NVRAM())//not correct checksum
   				{
   					SetBufferState((unsigned long)NO_NVRAM);
   				}
			   //			   Test_NVRAM();
			   break;
	 case 6l:	//
         //	   TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		 //not need	   Test_Xilinx();
	#ifdef PROG_BMDN
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
//			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
		  	  	for(tm = 0l; tm < 200000l; tm ++)
		  //		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
				 test_PU37_transit();
		  //		 if(!(tm%100000)) printf("\n\r...%ld  counter : %ld", ((100000l - tm)/100000), InterruptWatchDog);

			  	 wd_reset();
			  	}
  		  //		printf("\n\n\n\rTest Transit is finished.\r\r");
	  //11011		   	Init_BMDN();
				#endif //	PROG_BMDN

			//	TestMode.Value = 6l;	 //set back to 4
			 //	TestMode.ChangingValue = TestMode.Value;


			   break;
	 case 7l:	//work programm off
       //	       TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	   //		   my_int_disable_irq0();	//for test
			    TestMode.Value = 7l;	 //set back to 7
				TestMode.ChangingValue = TestMode.Value;

			   break;
	 case 8l:	//
	      //     TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		//	   my_int_enable_irq0();	//for test
			//   Ring(1,1,5,4);

			#ifdef PROG_BMDN
			printfp("\n\r");
			  	for(tm = 0l; tm < 10000l; tm ++)
		  //		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
			#ifndef PROG_BMDN6MI

			BusTest();
			#endif
			}
				 printfp("\n\r...Finish.");

			#endif
			   break;
     case 9l:	//
	 #ifdef PROG_MF20

		   //	     TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
				#endif

		#ifdef PROG_BMDN4
		printfp("\n\r");

			  	for(tm = 0l; tm < 10000l; tm ++)
		  //		for(tm = 0l; tm < 100000l; tm ++)
			  	{
			   	 delay_mcs(1);
			 #ifndef PROG_BMDN6MI

			BusTestFar();
			#endif
			}
				 printfp("\n\r...Finish.");

			#endif
			   break;

	         #ifdef PROG_MPC155
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest MPC155 is started.\n\r");
	         //	test_PU37_start();
			    Start_Test_MPC155();
		  	  	for(tm = 0l; tm < 10l; tm ++)
		   //	  	for(;;)	   //t
			  	{
			   	 delay_mcs(1);
				 Test_MPC155();
			 //	 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest MPC155 is finished.\r\r");
				Init_MPC155();
				#endif //	PROG_MPC155

	         #ifdef PROG_MPC4E
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest MPC155 is started.\n\r");
	         //	test_PU37_start();
			    Start_Test_MPC4E();
		  	  	for(tm = 0l; tm < 10l; tm ++)
		   //	  	for(;;)	   //t
			  	{
			   	 delay_mcs(1);
				 Test_MPC4E();
			 //	 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest MPC155 is finished.\r\r");
				Init_MPC4E();
				#endif //	PROG_MPC4E

			   break;
		case 0xAl:
		   //		TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			#ifdef PROG_MF20

		   //	     TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
				#endif

		#ifdef PROG_BMDN4
			  	for(tm = 0l; tm < 100l; tm ++)
		  //		for(tm = 0l; tm < 100000l; tm ++)
			{
		   	delay_mcs(100000);
#ifndef PROG_BMDN6MI

			ReleTest();
#endif
			}
			 printfp("\n\r...Finish.");

			#endif

	 		   	#ifdef PROG_MPC155
		 		printf("\n\rTest MX155 is started.\n\r");
	        	Start_TestMX155();
			  //	for(tm = 0l; tm < 200l; tm ++)
			  //	{
			  // 	 delay_mcs(1);
			  //	 TestTlfMX155();
			  //	 wd_reset();
			  //	}
				printf("\n\rTest MX155 is finished.\r\r");
				Init_MPC155();
				#endif //	PROG_MPC155
 	 			break;
		case 0xBl:
			 //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
				#ifdef PROG_MF20
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			// 	#ifdef PROG_MF20
				test_TELO();
		  		dev_restart();
	   			#endif //	PROG_MF20
			
		   //		#ifdef PROG_BMDN6
			   	dev_restart1();	  //hot restart
	   	  //		#endif //PROG_BMDN6	

				break;
	   	case 0xCl:
			  //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 	#ifdef PROG_MF20
				test_TLLO();
		  	   	dev_restart();
	   			#endif //	PROG_MF20
				break;
	   	case 0xDl:
			  //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 	#ifdef PROG_MF20
				test_BUS();
		  	   	dev_restart();
	   			#endif //	PROG_MF20
				break;
    	case 0xEl:
			 //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 	#ifdef PROG_MF20
				test_w2o0in0();
		  	   	dev_restart();
	   			#endif //	PROG_MF20
				break;
		case 0xFl:
			 //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 	#ifdef PROG_MF20
				test_w4o13in13();
		  	   	dev_restart();
	   			#endif //	PROG_MF20
				break;
		case 0x10l:
			 //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 	#ifdef PROG_MF20
				test_w4o4in13();
		  	   	dev_restart();
	   			#endif //	PROG_MF20
				break;

		case 0x11l:
			  	#ifdef PROGRAMM_PULT
				ProgrammPult();
	  			#endif // PROGRAMM_PULT
				break;
		case 0x12l:
			  	#ifdef PROGRAMM_PULT
			    ReadAtmelSGN();
	  			#endif // PROGRAMM_PULT
				break;
	   case 0x20:
	       		TestMode.Value = 0x20l;	 //set back to 0x20
				TestMode.ChangingValue = TestMode.Value;

				#ifdef PROG_DTVM
				start_key = 0;
				#endif

				#ifdef PROG_KTVM
				start_key = 0;
				#endif
				break;
	   case 0x21:
				dev_restart2();

			   /*
				 printfp("\n\n\start pause...\n\r");	
				 OperateBuffers_usart0t();
			 //	 _int_disable();
				  for(tm = 0; tm <10000000; tm++)
				  {
				   wd_reset();
				  if(!(tm%1000l)){ printfpd("\r-> %d", tm/1000);	 OperateBuffers_usart0t();}
				  }
			     printfp("\n\n\r...finish");	
				 OperateBuffers_usart0t();
 				*/
		 //		UsedExp.State.Reg1.bit.UCDE = 0; //usart not can now disable ethernet
				break;
	   case 0x22:
		  //		UsedExp.State.Reg1.bit.UCDE = 1; //usart  can now disable ethernet
   #ifdef PROG_ODU4
				 SetPin100ToOne();
#endif

			    TestMode.Value = 0x22l;	 //set back to 22
				TestMode.ChangingValue = TestMode.Value;

				break;
	   case 0x23 :
				SetNVRAMToData(0);
				break;
	   case 0x24 :
				SetNVRAMToData(0xFF);
				break;
 	   case 0x25l: // printf("\n\r\test");
			  //	wd_deinit();
  //				TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
				TestMode.Value = 2l;	 //set back to 2 // TO WORK TESTS
				TestMode.ChangingValue = TestMode.Value;

			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
				#ifdef PROG_BMD34
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	     //   	test_PU37_start();
			 // 	for(tm = 0l; tm < 2000000l; tm ++)
		  		for(tm = 0l; tm < 200000l; tm ++)	
		  		{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest Transit is finished.\r\r");
				Init_BMD34();
				#endif //	PROG_BMD34

				#ifdef PROG_BMD35
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	      //  	test_PU37_start();
		 	 // 	for(tm = 0l; tm < 200000000l; tm ++)
			  	for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
					for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}



				printf("\n\rTest Transit is finished.\r\r");
				Init_BMD35();
				#endif //	PROG_BMD35

			#ifdef PROG_PROV
//			    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
  //			  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	      //  	test_PU37_start();
		 	 // 	for(tm = 0l; tm < 200000000l; tm ++)
			  	for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
					for(tm = 0l; tm < 200000l; tm ++)
		   //		for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}



				printf("\n\rTest Transit is finished.\r\r");
				Init_PROV();
				#endif //	PROG_PROV



             

  				#ifdef PROG_BMD155
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       // 	test_PU37_start();
			  	for(tm = 0l; tm < 200000l; tm ++)
			 // 	for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest Transit is finished.\r\r");
		  	   	Init_BMD155();
				#endif //	PROG_BMD155

				#ifdef PROG_COMMUTATOR
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       // 	test_PU37_start();
			  	for(tm = 0l; tm < 200000l; tm ++)
			 // 	for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest Transit is finished.\r\r");
		  	   	Init_COMMUTATOR();
				#endif //	PROG_BMD155


		#ifdef PROG_BMDN
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       // 	test_PU37_start();
			  	for(tm = 0l; tm < 200000l; tm ++)
			 // 	for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
	//			printf("\n\rTest Transit is finished.\r\r");
	//110111	  	   	Init_BMDN();
				#endif //	PROG_BMD155






				#ifdef PROG_PRM_PCH
					 /*
	//		    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
	  //		  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       // 	test_PU37_start();
			  	for(tm = 0l; tm < 200000l; tm ++)
			 // 	for(;;)
			  	{
			   	 delay_mcs(1);
				 test_PU37();
			  	 wd_reset();
			  	}
				printf("\n\rTest Transit is finished.\r\r");
		  	   	Init_PRM_PCH();
					*/
				#endif //	PROG_PRM_PCH

				#ifdef PROG_MPC155
		//	    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		  //	  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       //	test_PU37_startMX155();
			  	for(tm = 0l; tm < 2000000l; tm ++)	  
			//  for(;;)
			   	{
			   	 delay_mcs(1);
			  //	 test_PU37MX155();
#ifdef IncEmbSerialMD34AVT
				 test_PU37();
#endif // IncEmbSerialMD34AVT
			  	 wd_reset();
			  	}
		   		printf("\n\rTest Transit is finished.\r\r");
		   		Init_MPC155();
				#endif //	PROG_MPC155

#ifdef PROG_MPC4E
		//	    TestMode.WriteStorageC((uint_32)TestModeStorage, 1);
		  //	  	UsedExp.State.Reg1.bit.Mf20SnmpOn = 0;
			 //	my_int_disable();
			 //	my_int_enable_irq0();
			    printf("\n\rTest Transit is started.\n\r");
	       //	test_PU37_startMX155();
			  	for(tm = 0l; tm < 2000000l; tm ++)	  
			//  for(;;)
			   	{
			   	 delay_mcs(1);
			  //	 test_PU37MX155();
#ifdef IncEmbSerialMD34AVT
				 test_PU37();
#endif // IncEmbSerialMD34AVT
			  	 wd_reset();
			  	}
		   		printf("\n\rTest Transit is finished.\r\r");
		   		Init_MPC4E();
				#endif //	PROG_MPC4E

				TestMode.Value = 1l;	//set back testmode
				TestMode.ChangingValue = TestMode.Value;
				break;

	case 0x26l :

#ifdef LOAD_EXT_MODEM
			 //	for(tm  = 0; tm < 10000; tm++)
			  //	{
	   			LoadExtModem();
			//	 wd_reset();
			// 	}

#endif //LOAD_EXT_MODEM
				break;
case 0x27l: 
				TestMode.Value = 0x27l;	 //set back to 27 // to reload programm without reload xilinx
				TestMode.ChangingValue = TestMode.Value;
				WriteDevId(); //to be so after restart!!!!!
				break;

case 0x28l:		TestMode.Value = 0x28l;
				TestMode.ChangingValue = TestMode.Value;
				break; //echo on rs232

case 0x29l:	
				PrintDevId();
				#ifdef PROG_KTVM
				 SetPLLKTVM();
				#endif // PROG_KTVM
				#ifdef PROG_MD310
				StartEth(1);
				#endif

   				break; //

case 0x30l:	
			  #ifdef	 PROG_PRM_PCH_SPI_NOXIL_ETH
				TestReadDDS();
		      #endif
				#ifdef PROG_KTVM
				LoadCoder(1);
				#endif // PROG_KTVM
				#ifdef PROG_PU_MSAT
				FillRadianVersion();
				#endif
				#ifdef PROG_MD310
				StartEth10p();
				#endif
   				break; //
case 0x31l:	
			    #ifdef	 PROG_PRM_PCH_SPI_NOXIL_ETH
					PrintAFR();
				#endif

				#ifdef PROG_KTVM
				LoadCoder(2);
				#endif // PROG_KTVM
				#ifdef PROG_MD310
				StartEth10d();
				#endif

   				break; //


case 0x32l:	  /*
 for(tm = 0; tm <= 1000; tm++)
  				{ 
      				m_load_xilinx3((char)XILINXPG, 1);
					wd_reset();
		 		}
				*/
#ifdef PROG_PU_MSAT5
#ifndef	PROG_VNV1

for(tm=0;tm<10000;tm++){
			   LoadIFMdt();

				wd_reset();
				OperateBuffers_usart0t();

				}

#endif
#endif



                #ifdef	 PROG_PRM_PCH_SPI_NOXIL_ETH
				WriteAFRTest();
				#endif


				#ifdef PROG_MD310
			//	printfp()
				StartEth100p();
				#endif

				break;

case 0x33l:    
				#ifdef PROG_DTVM
						TestWrite();   break;
				#endif //PROG_DTVM
				#ifdef PROG_MD310
				StartEth100d();
				#endif

#ifdef PROG_PU_MSAT5
for(tm=0;tm<10000;tm++){
				SetTrFrequency();
				wd_reset();
				OperateBuffers_usart0t();

				}
#endif


case 0x34l:  
		   //	   for(tm = 0; tm <= 1000; tm++)
  			 //	{ 
			 		_int_disable();
      				m_load_xilinx3((char)XILINXPG, 1);
					wd_reset();

			  //		delay_mcs(5000000);
					_int_enable();
		 	 //	}
				  break;
  				 /*
				#ifdef PROG_DTVM
						   //	set_audio(1,1);
							SetE14();
				   			  break;
				#endif //PROG_DTVM
				*/
case 0x35l:    
				#ifdef PROG_DTVM

  for(tm=0;tm<8;tm++){
    outportb(0xf0,tm+0x08);
 //	  delay_mcs(1l); 
 //   printf("\n\r i = %d f0 = 0x%X",tm ,inportb(0xf0 ));	
   //	  printf(" ff = 0x%X",inportb(0xff ));	
	  }	
	  		#endif //PROG_DTVM
				 
				#ifdef USE_P710
		//	for(;;)
	   ////		{
	 //		PVG710_Init(0);	  //for test
	  //		PVG710_Init(1);	  //for test
	  //		wd_reset();

	 // 		}
			#endif

#ifdef PROG_PU_MSAT5
  for(tm=0;tm<10000;tm++){

			SetRcvFrequency();
			wd_reset();
			OperateBuffers_usart0t();

				}

#endif

				  

	    break;
			   
case 0x36l:  
	 //	  #ifdef PROG_PU_M_MUX 
	  //	  for(;;)
		//  {
				m_load_xilinx3((char)XILINXPG, 1); 
		 //	   delay_mcs(100000l);
		 //	  wd_reset();
		  //		}
	  //	 #endif
								  	break;
						#ifdef USE_P710
		  //	for(;;)
	  //		{
	  //		PVG710_Init(0);	  //for test
	  //		PVG710_Init(1);	  //for test
		 //	wd_reset();

	  	  //	}
			#endif

case 0x37l: 
		/*
 
#ifdef TEST_BUS
	    TestBus();
#endif

			 for(long ff=0; ff < 10000; ff++)
		 {
	    pio_ptrb->SODR = 1<<0; // TEMPORARY get down line prog for xilinx


	    pio_ptrb->CODR = 1<<0; //  get down line prog (B0) for xilinx
		}
	 //	  pio_ptrb->SODR = 1<<0;

		delay_mcs(1000);
#endif
        errorw =   (signed char)
		*/
    #ifndef PROG_VNV

  #ifdef PROG_DMU6
		     SetSelector(CNL1);	  //try use cs1


		printfp("\n\r Test 37 : \n\r");
		 for(tm = 10; tm > 0; tm--)
		{

    //    check_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1); //90 : without header
	 //	AT91F_DataflashInit1();
	 //	GetTempDmu();
		   printfpd(" > tm : %d ", tm);
		   printfpd(" > GetTempDmu() : %d ", GetTempDmu());
	   //	   printfpd(" > cnt_prm : %d \r", cnt_prm);

		    wd_reset();
		  	OperateBuffers_usart0t();
		}

 #endif
 #endif
      break;
case 0x38l: 
		  #ifdef PROG_VNV1
		//   pio_ptrb->CODR = 1<<0; //temporary!!! set to zero

		 TestWriteFlash6();
		     break;

		  #endif

case 0x39l: 
		  #ifdef PROG_VNV1
		//   pio_ptrb->CODR = 1<<0; //temporary!!! set to zero

		 TestWriteFlash7();
		     break;

		  #endif
 
 case 0x40l:   //use for read enivorment

	 		 read_dataflash (0xc0030000,73728, (char *)(&TFTP_Buffer[0]));
	         printfp1("\n\rFinich reading dataflash...\n\r");
	  		 for(tm = 0; tm < 15;tm ++) {
	  			printfpd1(" %d",TFTP_Buffer[tm]);
	   		 }
             OperateBuffers_usart1t();
			 break;


				  
case 0x41l:   //use for read enivorment

	 		 read_dataflash (0xc0030000,73728, (char *)(&TFTP_Buffer[0]));
	         printfp1("\n\rFinich reading dataflash...\n\r");
             OperateBuffers_usart1t();
			 break;

  /*

 	   for(tm = 0; tm <= 50; tm++)
  			 	{ 
			 		_int_disable();
      				m_load_xilinx3((char)XILINXPG, 1);
					wd_reset();

			   //		delay_mcs(50000);
					_int_enable();
		 	 	}
*/
				 
#ifdef PROG_MD310_SATI2

case 0x42l:    
		   //		#ifdef
//		 errorw = (signed char)read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
			   printfp("\n\rStart reading dataflash ");
			     printfpd(" address : 0x%08X \n\r", CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE);
   #ifndef MAKET_PLATA
			    outportb(MOD_LED_ADDR1, 8);
	#endif
			    OperateBuffers_usart0t();
				wd_reset();

		 //		 read_dataflash (CONFIG_FILES_ADDRESS,(unsigned int)TFTP_BUFFER_SIZE, (char *)(&TFTP_Buffer[0]));
			  //	 read_dataflash (CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE,(unsigned int)TFTP_BUFFER_SIZE, (char *)(&TFTP_Buffer[0]));
		   		 read_dataflash (CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE,(unsigned int)TFTP_BUFFER_SIZE>>1, (char *)(&TFTP_Buffer[0]));
		      printfp("\n\rHalf Finich reading dataflash...\n\r");
				wd_reset();
				    OperateBuffers_usart0t();

		 		 read_dataflash (CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE + ((unsigned int)TFTP_BUFFER_SIZE>>1),(unsigned int)TFTP_BUFFER_SIZE>>1, (char *)(&TFTP_Buffer[0] + ((unsigned int)TFTP_BUFFER_SIZE>>1)));
			   printfp("\n\rFinich reading dataflash...\n\r");

			      OperateBuffers_usart0t();


		 break;
 			//	#endif //PROG_DTVM
case 0x43l:    
			//	#ifdef PROG_DTVM
			  printfp("\n\rStart writing dataflash...\n\r");
			   OperateBuffers_usart0t();
			     outportb(MOD_LED_ADDR1, 8);


	 //	        write_dataflash (CONFIG_FILES_ADDRESS, (unsigned int)&TFTP_Buffer[0], (unsigned int)TFTP_BUFFER_SIZE); //90 : without header
		        write_dataflash (CONFIG_FILES_ADDRESS  - HEADER_SIZE - HEADER_SIZE, (unsigned int)&TFTP_Buffer[0], (unsigned int)TFTP_BUFFER_SIZE); //90 : without header
			  printfp("\n\rFinish writing dataflash...\n\r");

		 break;
 			 //	#endif //PROG_DTVM
#endif



case 0x44l:    
				#ifdef XIL_FLASH
				  		   printfp("\n\rStart reading dataflashx ");

			   AT91F_DataflashInitx();  //t


//			     printfpd(" address : 0x%08X \n\r", CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE);
   #ifndef MAKET_PLATA
			    outportb(MOD_LED_ADDR1, 8);
	#endif
			    OperateBuffers_usart0t();
				wd_reset();

		 //		 read_dataflash (CONFIG_FILES_ADDRESS,(unsigned int)TFTP_BUFFER_SIZE, (char *)(&TFTP_Buffer[0]));
			  //	 read_dataflash (CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE,(unsigned int)TFTP_BUFFER_SIZE, (char *)(&TFTP_Buffer[0]));
		   	 //	 read_dataflash (CONFIG_FILES_ADDRESS - HEADER_SIZE - HEADER_SIZE,(unsigned int)TFTP_BUFFER_SIZE>>1, (char *)(&TFTP_Buffer[0]));
		  	  read_dataflashx((unsigned int)CFG_DATAFLASH_LOGIC_ADDR_CS0X, 235858, (uchar_ptr)&TFTP_Buffer[0]);
 
		      printfp("\n\rHalf Finich reading dataflash...\n\r");
				wd_reset();
				    OperateBuffers_usart0t();

		   

		 break;
 				#endif 



case 0x45l:  
  
#ifdef PROG_VNV1

	  for(tm=0;tm<1000000;tm++) 
  	  {
  		 wd_reset();
		 delay_mcs(200000l);
	     ReadE1IDs();
		 OperateBuffers_usart0t();
	  }
	  break;
#endif //PROG_DTVM


case 0x46l:  
  
#ifdef PROG_VNV1

	  for(tm=0;tm<1000000;tm++) 
  	  {
  		 wd_reset();
	     InitTLF();
		 OperateBuffers_usart0t();
	  }
	  break;
#endif //PROG_DTVM




/*
case 0x46l:    
				#ifdef PROG_DTVM
				  tstep6();
				  break;
 				#endif //PROG_DTVM
case 0x47l:    
				#ifdef PROG_DTVM
				  tstep7();
				  break;
 				#endif //PROG_DTVM

case 0x48l:    
				#ifdef PROG_DTVM
				  tstep8();
				  break;
 				#endif //PROG_DTVM

case 0x51l:    
				#ifdef PROG_DTVM
				  tstep51();
				  break;
 				#endif //PROG_DTVM

case 0x52l:    
				#ifdef PROG_DTVM
				  tstep52();
				  break;
 				#endif //PROG_DTVM


   */




case 0x50l:		TestMode.Value = 0x50l;
				TestMode.ChangingValue = TestMode.Value;

		 //	 #ifdef PROG_PRM_PCH_N
		 //		RunCommandN2(100);
		 //	 #endif // PROG_PRM_PCH_N




				break; //test print on bmd155  and on PRM_PCH

case 0x51l:		
#ifdef PROG_KTVM
	 			LoadSome();

#endif // PROG_KTVM

#ifdef PROG_MD310
		//		PrintConfigs();
		AT91F_DataflashInitx();
#endif //PROG_BMDN

				break; //

case 0x52l:
#ifdef CLOCK_ENABLED
		   ClockStart();
#endif // CLOCK_ENABLED
				break; //
case 0x53l:
#ifdef CLOCK_ENABLED
		   ClockStop();
#endif // CLOCK_ENABLED
				break; //

case 0x54l:
#ifdef Yournal
		   Yournal_Init();
#endif // CLOCK_ENABLED
				break; //

case 0x55l:			   SetUsart1BaudRate(921600l); break;
case 0x56l:			   SetUsart1BaudRate(38400l); break;
case 0x57l:	  	for(tm=0;tm<1000;tm++) 
				  {
	   //				fputc('1', fusart1_ptr);
		//			fputc('1',fusart0_ptr);
				  } 



break;
case 0x58l:			   SetUsart1BaudRate(115200l); break;
case 0x59l:
		   //		  #ifdef 	PROG_PRM_PCH_L
		   //		  MakeKeepTest(); //PrintCurrentValues()SetTestValuesAndWrite();		
		   //		  #endif //PROG_PRM_PCH_L
				 break;
case 0x5Al:		TestMode.Value = 0x5Al;
				TestMode.ChangingValue = TestMode.Value;
				break; //test print on bmd155  and on PRM_PCH

case 0x5Bl:
	 		#ifdef USE_CALIBR
			 PrintCalibrData();
			   //	RunCommandN2(100);
			 #endif // PROG_PRM_PCH_N

				break;

case 0x5Cl:

			 #ifdef USE_CALIBR
			 KeepCalibrData();
			 PrintCalibrData();
			   //	RunCommandN2(100);
			 #endif // PROG_PRM_PCH_N


	 	  // 	#ifdef USART0_TRY_PDC
   		  //			PrintTestBuf(); 
		  //	#endif //USART0_TRY_PDC
				break;

case 0x5Dl:		TestMode.Value = 0x5Dl;
				TestMode.ChangingValue = TestMode.Value;
				break; //test print on bmd155  and on PRM_PCH

case 0x5El:
#ifdef TDONE

	 CheckDone();
#endif
#ifdef USE_TCPIP_CLIENT
				QUOTE_client(0);
#endif //USE_TCPIP_CLIENT
				break;

case 0x5Fl:
#ifdef PROG_ODU1

SetEthPhyParams();

//#ifndef PROG_BMDN6MI
//				FirmwareLoad();
//#endif
#endif //PROG_BMDN
				break;

case 0x60l:
  #ifndef PROG_VNV

#ifdef PROG_BMDN
			 tm =GetVersionAPI();
			 printfpd("\n\rhot ver: %d\n\r", tm);
			 printfpd("\n\rstart ver: %d\n\r",ver_api);


#endif //PROG_BMDN
#endif
				break;

case 0x61l:
#ifdef PROG_BMDN
		 //		FlashFirmwareLoad();
#ifdef XIL_FLASH
//	for(tm=0;tm<100000;tm++) 
  //				  {
 //	AT91F_DataflashInitx();
 //	wd_reset();
 // CheckOperateFlashx();

 //	}
   	   CheckOperateFlashx();
#endif
#endif //PROG_BMDN
				break;

case 0x62l:
#ifdef PROG_BMDN
		 //		FirmwareReLoad();
				EraseAllConfigFiles();

#endif //PROG_BMDN
				break;

case 0x63l:
#ifdef PROG_BMDN
				FillAllConfigFileVersion();
//				FirmwareBurn();	   //ok
#endif //PROG_BMDN
				break;

case 0x64l:
																			
//#ifdef ETH_CAN_RESTART
  #ifndef PROG_VNV

#ifdef PROG_DMU6
LoadDDSs_Start();
// LoadDDS_Symb_Start();
 //Restart_Eth();

#endif
#endif
// TestMode.Value = 0x64l;
// TestMode.ChangingValue = TestMode.Value;

//#endif // ETH_CAN_RESTART
 break;

case 0x65:
#ifndef DISABLE_ETHERNET

//#ifdef ETH_CAN_RESTART
 //Restart_Eth1();

#endif
//TestMode.Value = 0x65l;
//				TestMode.ChangingValue = TestMode.Value;

//#endif // ETH_CAN_RESTART
			  break;

case 0x66l:
#ifdef PROG_BMDN
			  //	DirectLoad();	//ok

	   //			FirmwareLoad();
	//   PVG710_Init(0);	  //for test
	//	PVG710_Init(1);	  //for test


#endif //PROG_BMDN
				break;

case 0x67l:
#ifdef PROG_PRM_PCH_N_1
 printf("\n\r set baud rate 38400");
 use_standard_protocol = 2; //to use standart protocol but not set 115200 to timer
				SetUsart0BaudRate(38400l);
#endif //
				break;

case 0x68:
 #ifndef DISABLE_ETHERNET

//#ifdef ETH_CAN_RESTART
// Restart_Eth2();
//TestMode.Value = 0x68l;
//				TestMode.ChangingValue = TestMode.Value;
 #endif
//#endif // ETH_CAN_RESTART
			  break;

case 0x69:

//#ifdef ETH_CAN_RESTART
//TestMode.Value = 0x69l;
//				TestMode.ChangingValue = TestMode.Value;
 #ifndef DISABLE_ETHERNET

// Restart_Eth3();

#endif
//#endif // ETH_CAN_RESTART
			  break;

case 0x70:

//#ifdef ETH_CAN_RESTART
//TestMode.Value = 0x70l;
//				TestMode.ChangingValue = TestMode.Value;
#ifndef DISABLE_ETHERNET

#ifdef TRY_UNBLOCK
// Restart_Eth5();
#endif //

#endif
//#endif // ETH_CAN_RESTART


			  break;

case 0x71l:
	   /*
#ifdef PROG_BMDN
 			DirectLoad();	//load loader
 		    LoadToLdr();	//ok
	   //			FirmwareLoad();
#endif //PROG_BMDN
		*/
				break;

case 0x72l:
		 /*
#ifdef PROG_PRM_PCH_N_1
		   SetLed2(0);	//load loader
 //t		LoadToLdr();	//ok
	   //			FirmwareLoad();
#endif //PROG_BMDN
#ifdef PROG_PRM_PCH_SPI_XIL
		   SetLed2(0);	//load loader
		    SetLed3(0);	
 //t		LoadToLdr();	//ok
	   //			FirmwareLoad();
#endif //PROG_BMDN
			*/

#ifdef 	PROG_MD310_SATI
// FillMenu();
#endif


				break;

case 0x73l:
	 /*
#ifdef PROG_PRM_PCH_SPI_XIL
		   SetLed2(1);	//load loader
		    SetLed3(1);	
 //t		LoadToLdr();	//ok
	   //			FirmwareLoad();
#endif //PROG_BMDN
*/
				break;


case 0x74l:
RestartAutoNeg();
break;

case 0x75l:
	 /*
#ifdef PROG_BMDN
// 			DirectLoad();	//load loader
 		    LoadToLdr();	//ok
	   //			FirmwareLoad();
#endif //PROG_BMDN
	*/

	 //	printfpd("%c",RAnyConfig1.Value[i]);

 #ifdef 	PROG_MD310_SATI

		   ReadRAnyConfigs();
 #endif

				break;
case 0x76l:			   SetUsart0BaudRate(38400l); break;

case 0x77l:
#ifdef PROG_BMDN
   //		ComConfigure(0);
#endif //PROG_BMDN
				break;

case 0x78l:
#ifdef PROG_BMDN
   //		 ComConfigure(1);
#endif //PROG_BMDN
				break;

case 0x79l:
#ifdef PROG_BMDN
     //     EthStatusSet();
	   //	  ConfigFileLoad();	   //ok
#endif //PROG_BMDN
				break;

case 0x7Al:
#ifdef PROG_BMDN
	  //	  SetLoop(PVG610_LOOPBACK_MODEM_E ,0 , 1 , 0);	   //ok
#endif //PROG_BMDN
				break;
case 0x7Bl:
#ifdef PROG_BMDN
	   //	  SetLoop(PVG610_LOOPBACK_NONE_E ,0 , 1 , 0);	   //ok
#endif //PROG_BMDN
				break;
case 0x7Cl:
#ifdef PROG_BMDN
	   //	  SetLoop(PVG610_LOOPBACK_MODEM_E ,0 , 0, 0);	   //ok
#endif //PROG_BMDN
				break;
case 0x7Dl:
#ifdef PROG_BMDN
	   //	  SetLoop(PVG610_LOOPBACK_NONE_E ,0 , 0, 0);	   //ok
#endif //PROG_BMDN
				break;
case 0x7El:
#ifdef PROG_BMDN
	  //	  SetLoop(PVG610_LOOPBACK_INTERFACE_E ,0 , 1, 0);	   //ok
#endif //PROG_BMDN
				break;
case 0x7Fl:
#ifdef PROG_BMDN
	  // 	  SetLoop(PVG610_LOOPBACK_NONE_E ,0 , 1, 0);	   //ok
#endif //PROG_BMDN
				break;





case 0x80l:
#ifdef PROG_BMDN
 //		  ConfigFileGet();	   //ok
#endif //PROG_BMDN
				break;

case 0x81l:
#ifdef PROG_BMDN
#ifndef PROG_BMDN6MI
		 // ConfigFileRun();	   //ok
#endif
#endif //PROG_BMDN
				break;

case 0x82l:
#ifdef PROG_BMDN
#ifndef PROG_BMDN6MI
		//  ModemStatusGet();	   //ok
#endif
#endif //PROG_BMDN
				break;

case 0x83l:
#ifdef PROG_BMDN
	//	  ModemAcmCountersGet();	   //ok
#endif //PROG_BMDN
				break;

case 0x84l:
#ifdef PROG_BMDN
#ifndef PROG_BMDN6MI
	   //	  ModemAcquireCountersGet();	   //ok
#endif
#endif //PROG_BMDN
				break;
case 0x85l:				   
#ifdef PROG_BMDN
  //        ModemFecCountersGet();
#endif //PROG_BMDN
				break;
case 0x86l:
				break;

case 0x87l:
#ifdef PROG_BMDN
#ifndef PROG_BMDN6MI

//ModemMailboxMessageReceive();
#endif
#endif //PROG_BMDN
				break;

case 0x88l:
#ifdef PROG_BMDN
//ModemAlarmEnableGet();
#endif //PROG_BMDN
				break;

case 0x89l:
#ifdef PROG_BMDN
//ModemAlarmEnableSet();
//ModemAlarmEnableSetAllm(4);
//ModemAlarmEnableSetAllm(8);
//ConfigFileRunm(MODEM_QUANTITY);
 // protection_mode = MODE_N_PLUS_1;
//  SetNeedInitAllProt(); 
#endif //PROG_BMDN
				break;
case 0x8Al:
#ifdef PROG_BMDN
			 //	StartModems(MODEM_QUANTITY);
		//		protection_mode = MODE_NO_PROT;
		 //		SetNeedInitAllProt(); 
#endif //PROG_BMDN


				break;

case 0x8Bl:
//#ifdef PROG_BMDN
//		  ModemStatusGetm(MODEM_QUANTITY);	   //ok
//#endif //PROG_BMDN
				break;

case 0x8Cl:
#ifdef PROG_BMDN
	  //	  LoadSyntmf(0,0);	   //ok
	  
	//  ResetSyntOnly(2);
	//  delay_mcs(10000);
	//  ResetSyntOff(2);
	//  LoadSyntmf(0, 0);
	  
 //  ModemAlarmStatusGetAllm();
      
#endif //PROG_BMDN

//ENET_tx_underrun();

				break;

case 0x8Dl:
#ifdef TRY_UNBLOCK
  _task_restart(tcpip_id, NULL, TRUE);
#endif
			break;

case 0x8El:		TestMode.Value = 0x8El;		//restart only rtcs
				TestMode.ChangingValue = TestMode.Value;  
				 WriteDevId();
				break;

case 0x8Fl:
#ifdef PROG_PU_M_V	
  	   SetTestConfig();
#endif

#ifdef PROG_PU_M_V_A	
  	   SetTestConfig();
#endif




#ifdef PROG_UPS	
  	   SetTestConfig();
#endif


#ifdef PROG_BACO
TestChecksum();
#endif


	 break;
case 0x90l:

#ifdef PROG_PU_M_V
 for(tm = 0; tm < ((DEVCONFIG_QUANTITY << 1) + 2); tm++) //test
		  {
		  printfpd(" %02X", Getudevconfig(tm));
          }

break;
#endif

#ifdef PROG_PU_M_V_A
 for(tm = 0; tm < ((DEVCONFIG_QUANTITY << 1) + 2); tm++) //test
		  {
		  printfpd(" %02X", Getudevconfig(tm));
          }

break;
#endif // PROG_PU_M_V_A



#ifdef PROG_PRM_PCH_DEM	

 #endif

	 break;

case 0x91l:
/*
#ifdef PROG_PRM_PCH_DEM	
	      for(tm = 0; tm < 100000; tm++) //test
		  {
 LoadFreqPCh(GetFreqPCh());
 wd_reset();
 }

 #endif
 */
		AT91F_DataflashInit();
	 break;

case 0x92l:
#ifdef PROG_PU_M_V
  for(tm=0; tm<((DEVCONFIG_QUANTITY << 1) + 2); tm++)
{
   if(!(tm % 8))	printfp("\n\r");
   printfpd("_%X",udevconfig.byte[tm]);
}
#endif

#ifdef PROG_PU_M_V_A
  for(tm=0; tm<((DEVCONFIG_QUANTITY << 1) + 2); tm++)
{
   if(!(tm % 8))	printfp("\n\r");
   printfpd("_%X",udevconfig.byte[tm]);
}
#endif //PROG_PU_M_V_A



#ifdef PROG_UPS
  for(tm=0; tm<((DEVCONFIG_QUANTITY << 1) + 2); tm++)
{
   if(!(tm % 8))	printfp("\n\r");
   printfpd("_%X",udevconfig.byte[tm]);
}
#endif





 break;

case 0x93l:
#ifdef PROG_PRM_PCH_DEM
 m_load_xilinx4(1,0); //load xilinx1 to f1
#endif
 break;

case 0x94l:
#ifdef PROG_PRM_PCH_DEM
 m_load_xilinx4(2,0); //load xilinx1 to f2
#endif
 break;

case 0x95l:
#ifdef PROG_PRM_PCH_DEM
 m_load_xilinx5(3,0); //load xilinx3,4 to f3
#endif
 break;

case 0x96l:
#ifdef PROG_PU_M_V
#ifdef COUNT_BUFF_ERR
  printfp("\n\r");
  printfpd("1:%ld",GetCounter1());
  printfpd("2:%ld",GetCounter2());

#endif //
#endif //

#ifdef PROG_PU_M_V_A
#ifdef COUNT_BUFF_ERR
  printfp("\n\r");
  printfpd("1:%ld",GetCounter1());
  printfpd("2:%ld",GetCounter2());

#endif //
#endif //




case 0xA4l:
#ifdef PROG_PU_M710

printfpd("\n\rm : %d", MirrorTest());
printfpd("x : %d",IsXilWrited());
#endif

break;


case 0xA7l:
	TestMode.Value = 0x8El;		//restart only rtcs
	TestMode.ChangingValue = TestMode.Value;  
   	 WriteDevId(); //to keep 0x8e after restart
	dev_restart();//	
				break;


case 0xA8l:
#ifdef HAVE_GATEWAY
#ifdef USART0_TRY_PDC_1T	
 printfpd("\n\rn> %X",GetNetwork());
 printfpd("\n\rm> %X",GetNetMask());
#endif
#endif
				break;

case 0xA9l:
#ifdef PROG_UPS
  Set_Usart2_To_RS485();
#endif
				break;

 case 0xAAl:
   TestMode.Value = 0xAAl;		//restart only rtcs
	TestMode.ChangingValue = TestMode.Value;  
   	 WriteDevId(); //to keep 0x8e after restart
			 break;

 case 0xABl:
#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU3
SetSelector(CNL1);
 m_load_xilinx5(3,0); //load xil 3,4 to file 3
 m_load_xilinx4(1,0);

SetSelector(CNL2);
 m_load_xilinx5(3,0); //load xil 3,4 to file 3
 m_load_xilinx4(1,0);

#endif

				break;
#ifndef PROG_VNV

case 0xAC :
#ifdef PROG_BMDN3
 GetTxtFile(4);
	   break;
#endif

case 0xAD :
#ifdef PROG_BMDN3
 ScanTxtFiles();
	   break;
#endif

#endif //no vnv 

case 0xAE :
#ifdef PROG_BMDN3
   printcurtxt();

 	   break;
#endif

case 0xAF :
#ifdef PROG_BMDN3
//   printcurtxt();
	 InitSetConfigFile(4);

 	   break;
#endif

case 0xB0 :
#ifdef PROG_COMMUTATOR
//   printcurtxt();
	 printfp("\n\r CheckDone()");
	 printfpd(" %02X", CheckDone());

 	   break;
#endif

case 0xB1 :
//#ifdef PROG_COMMUTATOR
//   printcurtxt();
//	 printfp("\n\r CheckDone()");
//	 printfpd(" %02X", CheckDone());
	EnableInterrupts();
 	   break;
//#endif	 


case 0xB2 :
#ifdef PROG_COMMUTATOR1
//   printcurtxt();
//	 printfp("\n\r CheckDone()");
//	 printfpd(" %02X", CheckDone());
   TestParser();
    	   break;
#endif	 

case 0xB3 :
	   SetSlowClock();
 		 break;


case 0xBA :

  my_rx_usart0_int(0xAA);
  my_rx_usart0_int(0xff);
  my_rx_usart0_int(4);
  my_rx_usart0_int(0x20);
  my_rx_usart0_int(2);
  my_rx_usart0_int(1);
  my_rx_usart0_int(2);
  my_rx_usart0_int(0x29);
  my_rx_usart0_int(0x55);
  break;

case 0xBB :

  my_rx_usart0_int(0xAA);
  my_rx_usart0_int(0xff);
  my_rx_usart0_int(5);
  my_rx_usart0_int(0x20);
  my_rx_usart0_int(0);
  my_rx_usart0_int(0);
  my_rx_usart0_int(1);  //
  my_rx_usart0_int(0x35);  //'5'
  my_rx_usart0_int(0x5b);
  my_rx_usart0_int(0x55);
  break;

case 0xBC :

  my_rx_usart0_int(0xAA);
  my_rx_usart0_int(0xff);
  my_rx_usart0_int(4);
  my_rx_usart0_int(0x21);
  my_rx_usart0_int(0);
  my_rx_usart0_int(0);
  my_rx_usart0_int(1);
  my_rx_usart0_int(0x26);
  my_rx_usart0_int(0x55);
  break;

case 0xBE :

  my_rx_usart0_int(0xAA);
  my_rx_usart0_int(0xff);
  my_rx_usart0_int(12);
  my_rx_usart0_int(0x20);
  my_rx_usart0_int(0);
  my_rx_usart0_int(0);
  my_rx_usart0_int(8);  //
  my_rx_usart0_int(0x35);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x30);  //'5'
  my_rx_usart0_int(0x34);  //'5'
  my_rx_usart0_int(0xBD);
  my_rx_usart0_int(0x55);
  break;

case 0xBF :

  my_rx_usart0_int(0xAA);
  my_rx_usart0_int(0xff);
  my_rx_usart0_int(4);
  my_rx_usart0_int(0x21);
  my_rx_usart0_int(0);
  my_rx_usart0_int(0);
  my_rx_usart0_int(8);
  my_rx_usart0_int(0x2D);
  my_rx_usart0_int(0x55);
  break;


case 0xC2l:

#ifdef 	PROG_MD310
    SetBand(0, ratesymbol_far);

//  SetTrunk(0, 1);
#endif

break;

case 0xC3l:

#ifdef 	PROG_MD310

    SetBand(1, ratesymbol_far);
 

//  SetTrunk(0, 0);
#endif

break;

case 0xC4l:

#ifdef 	PROG_MD310

  for(tm=0; tm<2000000; tm++)
{
//  LoadReg(0,25,0);
//  LoadReg(1,25,0);
    SetBand(1, ratesymbol_far);
  wd_reset();
}

#endif

break;

case 0xC5l:

#ifdef 	PROG_PRM_PCH_SPI
 // TestPortB0();
#endif

break;

case 0xC6l:

#ifdef 	PROG_COMMUTATOR1

#ifndef USART0_TRY_PDC_1T	
	  			printf("\n\rTest is started.\n\r");
#else
			    printfp("\n\rTest is started.\n\r");

#endif


				TestMode.Value = 0xC6l;	 //set back to 4
				TestMode.ChangingValue = TestMode.Value;

 // TestPortB0();
#endif

break;


case 0xC7l:

#ifdef 	YOURNAL

	   //		    printfp("\n\rTest is started.\n\r");
	   PrintYournal();
#endif

break;


case 0xC8l:
#ifdef XIL_FLASH
FillDatat(0);
#endif

case 0xC9l:
#ifdef PROG_MD310
ConfigFileDestroy(0);
#endif
break;

case 0xCAl:
printfpd("\n\r wr : %d", writeid_counter);
//printfpd("\n\r h : %02X",unEmb2TypeVer.emb2TypeVer.signature_hardware[i]);
#ifdef RACM
#ifndef PROG_KAZAH
#ifndef PROG_MD310

ACM_DEFAULT_init();
#endif
#endif
#endif


break;

case 0xCCl:
 printfp("\n\r Setted Test Mode 0xCCwr");
 TestMode.Value = 0xccl;	 //set back to 0xcc
 TestMode.ChangingValue = TestMode.Value;
break;

case 0xCdl:

ReadDevId(1);

break;


case 0xCEl:		TestMode.Value = 0xCEl;		//restart only rtcs
				TestMode.ChangingValue = TestMode.Value;  
				break;

#ifdef HAVE_GATEWAY
case 0xCFl: CheckNetMask((unsigned long)NetMask.Value);

		   break;
#endif


case 0xD0l:	  // ReadDevId(0);	  break;
 		  		ReadDevId_utest(0);  break;



case 0xD1l:

	   //break;
#ifdef PROG_BACO
  LoadBaco(7);

#endif

		 break;




case 0xD5l:

#ifdef PROG_BACO


  ubx_device_init();

#endif
 break;



case 0x100l:		TestMode.Value = 0x100l;		//restart only rtcs
				TestMode.ChangingValue = TestMode.Value;  break;


 


   		default:
	     	 //	TestMode.WriteStorageC((uint_32)TestModeStorage, 1);

 	      	   DevId.Changable 	 = 0;	
 	 		   DevYear.Changable = 0;	
 	 		   DevVer1.Changable = 0;	
 	 		   DevVer2.Changable = 0;
 	 		   MAC0.Changable = 0;
			   MAC1.Changable = 0;	
   	 break;
	}

#else  //TESTS_ENABLED
	 TestMode.Value = 1l;	
	 TestMode.ChangingValue = 1l;	
#endif //TESTS_ENABLED
}

extern "C" unsigned SelfID() 
{ 
 //	unsigned far *ctrl = (unsigned far*)0xFFFF000A; 
 //	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
   return (unsigned)DevId.Value; //t
// return 0;
}

extern "C" unsigned SelfYear() 
{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF0008; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);
 return (unsigned)DevYear.Value;   //t
}

extern "C" unsigned SelfVer1() 
{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF000C; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
  return (unsigned)DevVer1.Value;	 //
}

extern "C" unsigned SelfVer2() 
{ 
//	unsigned far *ctrl = (unsigned far*)0xFFFF000E; 
//	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);
  return (unsigned)DevVer2.Value;   //
}






extern "C" char ComparePOK(unsigned long value)
{

 //  printfpd(" %d", (unsigned long)POK.Value);

 if((unsigned long)POK.Value == value)
  {

  return 1;
  }

 else return 0;
}

extern "C" void WritePOK(unsigned long set)
{
 POK.Value = (float64)(set);
 POK.ChangingValue =  POK.Value;
 WriteDevId();
}

 /*
extern "C" void ClearNvram(void)
{
uint_32 i;
   for(i = 0; i  < (NVRAM_SIZE - 10); i++)
   {
   write_nvram_char(i, 0);
   }

}
	*/
unsigned char Char2Hex(char s)
{
  if(s > 9) return ((s + 'A') - 10);
  else return (s + '0');
  return 0;
}

extern "C" void Enet_is_not_init()
{
//hier can set anu values to can restart devise
 //  _io_set_handle(IO_STDOUT, fh_ptr);
 //	fflush (fh_ptr);
 //   printf(fh_ptr, "\n\r...Warning : ENET is NOT property init.");
	UsedExp.State.Reg1.bit.EthBad = 1; //eth is bad
	UsedExp.State.Reg1.bit.Restart = 1; //go to restart after load
	UsedExp.State.Reg2.bit.Some = 1; //need make somthing witch this
}


void ToIBuf(unsigned char data)
{
#ifndef PULT_USART
  IBuff[uwIBuff++] = data;
  if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
  CntIBuff++;
#else // PULT_USART
	PultDelay();
 //	 printEthLongHex(2);
    Transmit3c(data);
#endif //PULT_USART
}

extern "C" void Ring(unsigned char M, unsigned char N, unsigned char F, unsigned char T)	  //  *100ms
{

//do not get somereturn; //for test

		PultDelay();
	 	ToIBuf('U');
		PultDelay();
		ToIBuf('S');
		PultDelay();
		ToIBuf((M << 4) + N);
		PultDelay();
		ToIBuf(F);
		PultDelay();
		ToIBuf(T);
		PultDelay();
#ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif

}


extern "C" void  m_Test_PKU(void)
{
 //t  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR); 

  UsedPult.InitDevise();
 // uint_32 i;
 //  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR);   //t

 //t UsedPult.gotoxy(1,1);
 //t cprintf("%s", "........................");
 //t UsedPult.gotoxy(1,2);
 //t cprintf2("%s", "........................");


 /*
  UsedPult.ReplaceChar('R');
  UsedPult.ReplaceChar('A');
  UsedPult.ReplaceChar('D');
  UsedPult.ReplaceChar('I');
  UsedPult.ReplaceChar('A');
  UsedPult.ReplaceChar('N');
  UsedPult.gotoxy(3,2);
  UsedPult.ReplaceChar('S');
  UsedPult.ReplaceChar('N');
  UsedPult.ReplaceChar('M');
  UsedPult.ReplaceChar('P');
  UsedPult.ReplaceChar(' ');
  UsedPult.ReplaceChar('C');
  UsedPult.ReplaceChar('o');
  UsedPult.ReplaceChar('n');
  UsedPult.ReplaceChar('t');
  UsedPult.ReplaceChar('r');
  UsedPult.ReplaceChar('o');
  UsedPult.ReplaceChar('l');
  UsedPult.ReplaceChar('l');
  UsedPult.ReplaceChar('e');
  UsedPult.ReplaceChar('r');
  */
 //  Ring(1,1,5,4);
  UsedPult.OperateLed(5,1);
  UsedPult.OperateLed(5,2);
  UsedPult.OperateLed(5,3);
  UsedPult.OperateLed(5,4);
//  Ring(1,1,5,4);
  for(long i = 0; i < 1000; i++)
  {
  delay_mcs(1000l);
  }
     Ring(1,1,5,4);
 // UsedPult.OperateLed(0,1);
 // UsedPult.OperateLed(0,2);
 // UsedPult.OperateLed(1,3);
 // UsedPult.OperateLed(0,4);
 //   Ring(1,1,5,4);
 //   _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
 //         				      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
  //               	  				      AT91RM9200_AIC_SMR_PRIO_MIN );  
  }

extern "C" void  m_Load_Xil_Reg(void)
{
 // unsigned int rchar;//, mask, i;
 /*
   rchar = read_xil_char(0x6fa);
//  printf("\n\r start rchar = 0x%x", (rchar & 0xff));
   mask = 0x1;

//_________________________________________________________
  for(i = 0; i < 8; i++)
  {
      write_xil_char(0x6f8, mask); //use uart pku from xilinx
 //  delay_mcs(20l);
   rchar = read_xil_char(0x6fa);
//   printf("\n\r mask = 0x%x  rchar = 0x%x",mask, (rchar & 0xff));
   mask <<= 1;
   }
 mask = 0x1;

//_________________________________________________________
  for(i = 0; i < 8; i++)
  {
      write_xil_char(0x6f9, mask); //use uart pku from xilinx
  // delay_mcs(20l);
   rchar = read_xil_char(0x6fa);
 //  printf("\n\r mask = 0x%x  rchar = 0x%x",mask, (rchar & 0xff));
   mask <<= 1;
   }
  */
//_________________________________________________________
#ifndef PULT_USART
   write_xil_char(0x6f8, 0x42); //use uart pku from xilinx and reset pku
//   rchar = read_xil_char(0x6fa);
//   printf("\n\r rchar = 0x%x", (rchar & 0xff));
   delay_mcs(200l); 
//
   write_xil_char(0x6f9, 0x40); //clear reset 	 ??? right??? may 
//   rchar = read_xil_char(0x6fa);
//   printf("\n\rrchar = 0x%x", (rchar & 0xff));
#else //  PULT_USART
 write_xil_char(0x6f8, 0x40); //not use uart pku from xilinx and reset pku
//   rchar = read_xil_char(0x6fa);
//   printf("\n\r rchar = 0x%x", (rchar & 0xff));
   delay_mcs(200l); 
//
 //  write_xil_char(0x6f9, 0x40); //clear reset 
   write_xil_char(0x6f9, 0x42); //clear reset and default bit 1 was setted

#endif //PULT_USART

}

#include "work1_menu.cpp" 


extern "C" void _setcursortype(Uint16 t)
 {
//temporary  ins_disp(t == 1 ? 0xF : 0xC); //t == 1 : on blinking cursor 
// printfpd(" %d ", t);
// printfpd(" %d ", UsedPult.CurAddr);
 
//  printfpd(" %d", (UsedPult.CurAddr + (t)*200));
#ifdef IncEmbIndicator

CopyCur2Remote(UsedPult.CurAddr + (t)*200);	
#endif
  if(t)
  {
  UsedPult.State.CBlink = 1; //cursor blink
  }
  else
  {
  UsedPult.State.CBlink = 0; //cursor is not blink
  }
 }

//#endif

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :GetIp
* Returned Value   : none
* Comments         :
*   return ip address
*
*END*----------------------------------------------------------------------*/
extern "C" uint_32 GetIP()
{
 return (uint_32)IPAddress.Value;
}


#ifdef HAVE_GATEWAY

extern "C" uint_32 GetNetwork()
{
 return (uint_32)Network.Value;
}

extern "C" uint_32 GetNetMask()
{


 return (uint_32)NetMask.Value;
// return (uint_32)DEFAULT_MASK;
}
#endif


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _irq2_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 IRQ2 ISR handler - this will be interrupt of kbd.
*
*END*----------------------------------------------------------------------*/

extern "C" void _irq2_isr
   (
         pointer dummy
   )
{  
my_int_disable_irq2();
   
 //  _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
 //  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR);
/*to use embisr
   UsedPult.PultCRd.all = UsedPult.GetControlChar();
   if(UsedPult.PultCRd.bit.RI)
   {	
   UsedPult.Key = UsedPult.GetDataChar();
   UsedPult.State.KeyPr = 1; //key is pressed
   }
   else	   //transmit
   {
	if(UsedPult.TBufferCnt)
	{
	 write_xil_char((uint_32)(PKU_ADDR), (char)(*UsedPult.pTBuffer));
	 UsedPult.pTBuffer--;
	 UsedPult.TBufferCnt--;
  	}
	else
	{
      UsedPult.PultCWr.bit.TI = 0;	 //not request transmit interrupt
      UsedPult.SendControlChar(UsedPult.PultCWr.all);
	}
    }
to use emb isr */
  // embIndicator.IsrXX(); //to use embisr
 //  _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
 
//  printf("\n\r.IRQ2.");
//____________________________________________________>>BEFORE
 	PultInts++;
 	UsedExp.State.Reg2.bit.NIRQ = 1;
 	UsedExp.State.Reg2.bit.Some = 1;
 //____________________________________________________<<BEFORE
//_____________________________________________________>>AFTER
/*
 UsedPult.PultCRd.all = UsedPult.GetControlChar();

	if(!UsedPult.PultCRd.bit.RI)
  //transmit
   {
	 if(CntIBuff)
	 {
 		  write_xil_char((uint_32)(PKU_ADDR),IBuff[urIBuff++]);
		  if(urIBuff >= IBUFFSIZE) {urIBuff = 0;}
		  CntIBuff--;
	 }
    
	 else
	 {
	   UsedPult.PultCWr.bit.TI = 0;	   //get off transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
	 }
   }
   else //	if(UsedPult.PultCRd.bit.RI)	   //ignore keys if make transmit
   {	
    UsedPult.Key = UsedPult.GetDataChar();
  //  write_xil_char((uint_32)(PKU_ADDR), (char)(0x55));	//t
    ticket_on();
    UsedPult.State.KeyPr = 1; //key is pressed
    }
	*/
 //_____________________________________________________<<AFTER


 /*
  UsedPult.PultCRd.all = UsedPult.GetControlChar();
   if(UsedPult.PultCRd.bit.RI)
   {	
   UsedPult.Key = UsedPult.GetDataChar();
   UsedPult.State.KeyPr = 1; //key is pressed
    }
   else	   if(UsedPult.PultCRd.bit.TI)
  //transmit
   {
	 if(*pcStr)
	 {
	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr));
	   pcStr++;
  	 }
     else if(*pcStr2)
	 {
	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr2));
	   pcStr2++;
  	 }
	 else
	 {
	   UsedPult.PultCWr.bit.TI = 0;	   //get off transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
     }
	}
*/
//____________________________________________________



    Stephany9++;
  //	 _psp_set_cpsr(_psp_get_cpsr() & (~PSP_PSR_CTRL_DIS_IRQ));
 // my_int_enable_irq2();
}



//============================================================================

//============================================================================

// volatile struct Expert_STORAGE ExpertStorage;
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :clkNumber
* Returned Value   : none
* Comments         :
*    This routine is used to operate widch snmp 
*END*----------------------------------------------------------------------*/

extern "C" void clkNumber (uchar_ptr data_ptr, uint_32 * data_len)
{
  //	ParseBuffer((char *)data_ptr,  ';');
	ParseBufferS((char *)data_ptr,  ';');
   /*t
   *pTBuff = '\0'; 
        	ReplacePC(&TBuff[0]);
 			pTBuff--;
  			pTBuff--;
		  	pTBuff--;
  			pTBuff--;
   			*pTBuff = '\0'; //	
		pTBuff = &TBuff[0]; //get back pointer
 	* data_len = 0;
     for(int i = 0; i < BufferSize; i++)
     {
      * data_ptr++ = TBuff[i];
  	  * data_ptr = i; //to test
 	  data_len++;
	  if(TBuff[i] == '\0') break;
      }
		*/
  *pTBuffS = '\0'; 
        	ReplacePC(&TBuffS[0]);
 			pTBuffS--;
  			pTBuffS--;
		  	pTBuffS--;
  			pTBuffS--;
   			*pTBuffS = '\0'; //	
		pTBuffS = &TBuffS[0]; //get back pointer
 	* data_len = 0;
     for(int i = 0; i < BufferSizeS; i++)
     {
      * data_ptr++ = TBuffS[i];
  	  * data_ptr = i; //to test
 	  data_len++;
	  if(TBuffS[i] == '\0') break;
      }

}

extern "C" void Mf20RBuff (uchar_ptr data_ptr, uint_32 * data_len)
{
   uint_32 len;

 // _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  //prepare transmit buffers for answer

  TBuffer1.len = 3;
  TBuffer1.Value[0] = 3;
  TBuffer1.Value[1] = 0x80;
//  TBuffer2.len = 3;
//  TBuffer2.Value[0] = 3;
//  TBuffer2.Value[1] = 0x80;


  len = *data_len;
  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; //use snmp operating to mf20 - not need get answers to com port
  if (len > 512) len = 512;
  while(len--)
  {
      embRS232_rcvbuf_Add((unsigned char)(* data_ptr++)); 
  }

 //init buffers for answer
  //	 _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   //					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
   	 // 				      BSP_ENET_INTERRUPT_PRIORITY);


}


extern "C" void Mf20TBuff (uchar_ptr data_ptr, uint_32 * data_len)
{
  Uint16 i;
  static unsigned char counter = 0;
   _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  counter++;
  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; //use snmp operating to mf20 - not need get answers to com port
  //  *data_ptr++ =  TBuffer1.Value[0];
  //  *data_ptr++ =  TBuffer1.Value[1];
 // if(UsedExp.State.Reg1.bit.WTBuff1)
 // {
 //  UsedExp.State.Reg1.bit.WTBuff1 = 0;
   TBuffer1.Value[2] = counter;
  
    for(i = 0; i < TBuffer1.len; i++)	 //t!!!!
  {
   *data_ptr++ = TBuffer1.Value[i];
  }
  TBuffer1.len = 3;
  TBuffer1.Value[0] = 3;
  TBuffer1.Value[1] = 0x80;
//  }
//  else
//  {
//   UsedExp.State.Reg1.bit.WTBuff1 = 1;
//   TBuffer2.Value[2] = counter;
//     for(i = 0; i < TBuffer2.len; i++)	 //t!!!!
//  {
//   *data_ptr++ = TBuffer2.Value[i];
//  }
//  TBuffer2.len = 3;
//  TBuffer2.Value[0] = 3;
//  TBuffer2.Value[1] = 0x80;


 // }
//  my_printf(0x88);
   	  _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  	  				      BSP_ENET_INTERRUPT_PRIORITY);

}


 extern "C" void RBuffRS485 (uchar_ptr data_ptr, uint_32 * data_len)
{
   uint_32 len;
 // _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  //prepare transmit buffers for answer
 /*	 485 need it buffers
  TBuffer1.len = 3;
  TBuffer1.Value[0] = 3;
  TBuffer1.Value[1] = 0x80;
  */
  TBuffer2.len = 3;
  TBuffer2.Value[0] = 3;
  TBuffer2.Value[1] = 0x80;
   
  len = *data_len;
  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; //use snmp operating to mf20 - not need get answers to com port
  if (len > 512) len = 512;
  while(len--)
  {
      embRS485_rcvbuf_Add((unsigned char)(* data_ptr++)); 
  }
}



extern "C" void TBuffRS485 (uchar_ptr data_ptr, uint_32 * data_len)
{
  Uint16 i;
  static unsigned char counter = 0;
   _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR); 
  counter++;
  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; //use snmp operating to mf20 - not need get answers to com port
  //  *data_ptr++ =  TBuffer1.Value[0];
  //  *data_ptr++ =  TBuffer1.Value[1];
 // if(UsedExp.State.Reg1.bit.WTBuff1)
 // {
 //  UsedExp.State.Reg1.bit.WTBuff1 = 0;
   TBuffer2.Value[2] = counter;
  
    for(i = 0; i < TBuffer2.len; i++)	 //t!!!!
  {
   *data_ptr++ = TBuffer2.Value[i];
  }
  TBuffer2.len = 3;
  TBuffer2.Value[0] = 3;
  TBuffer2.Value[1] = 0x80;
//  }
//  else
//  {
//   UsedExp.State.Reg1.bit.WTBuff1 = 1;
//   TBuffer2.Value[2] = counter;
//     for(i = 0; i < TBuffer2.len; i++)	 //t!!!!
//  {
//   *data_ptr++ = TBuffer2.Value[i];
//  }
//  TBuffer2.len = 3;
//  TBuffer2.Value[0] = 3;
//  TBuffer2.Value[1] = 0x80;


 // }
//  my_printf(0x88);
   	  _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  	  				      BSP_ENET_INTERRUPT_PRIORITY);

}





//________________________________________________________________________________________
 

//extern "C" Uint16 GetKey()
//{
/*	   temporary
	Uint16 Ping;
		Ping = ExpertRegs.KBDData & 0x3f;
 		if(Ping != 0x3f) //any key pressed
 		{
 		 if(!UsedExp.State.Reg1.bit.KeyPing)
 		 { 
 		 	UsedExp.State.Reg1.bit.KeyPing = 1;
 			if(Ping == 0x0f) //preseed together esc and enter
 			{
 			UsedExp.State.Reg2.bit.DcrBoot = 0; //if turn on widch esc and enter - not need boot - run in loader
 			}
 		UsedExp.Zummer(1);
    	UsedExp.State.Reg1.bit.Frozen  = 0; //unfrozen display
  			switch(Ping)
	 		{
	 		case 0x2f: return Esc;
	 		case 0x1f: return Enter;
	 		case 0x37: return Up;
	 		case 0x3b: return Down;
	 		case 0x3d: return Left;
 			case 0x3e: return Right;
  			default:   return None;
  			}
  		 } //!keyPing
  		return None;
 		}
 		else //not pinget keys
 		{
 			UsedExp.State.Reg1.bit.KeyPing = 0; //key get off
 			return None;
 		}
	*/
// return None;  //temporary
//}

//extern "C" void ins_disp(char i)
//{
 //	MDelay(1000l);
 //	ExpertRegs.DINS = i;
 //	MDelay(1000l);
// }

extern "C" int fill_disp(const char *s)
 {
    register const char *sptr;
    sptr = s;
    while(*sptr)
     {
// 		MDelay(1000l);
//     	ExpertRegs.DDRAM = *sptr;
//    	MDelay(1000l);
	  UsedPult.ReplaceChar(*sptr);	
        sptr++;
     }
    return sptr - s;
 }



extern "C" void gotoxy(Uint16 x, Uint16 y)
 {
// ins_disp(0x38);//to not get off display to future need use ready signal
 if((!y) || (y > 2))  { y = 1;}
 if((!x) || (x > 24)) { x = 1;}
// ins_disp((char)((x-1) | (y == 2 ? 0xC0 : 0x80)));
 UsedPult.gotoxy(x , y);
 }

//extern "C" int cprintf(char const near *form, ...)
extern "C" void MessageChar(unsigned char x, unsigned char y, unsigned char Data)
{
 char Buff[3];
 sprintf(Buff,"%02X",Data);
// char Buff[] = "%s";
 gotoxy(x,y);
//UsedExp.State.Reg1.bit.Frozen  = 0;  //unfrozen display

 //cprintf("%s", theAnyStrings.cEmpty);
 cprintf("%s", Buff);
// UsedExp.State.Reg1.bit.Frozen  = 1;  //frozen display
}

extern "C" void MessageLong(unsigned char x, unsigned char y, unsigned long Data)
{
 char Buff[9];
 sprintf(Buff,"%X",Data >> 16);
// char Buff[] = "%s";
 gotoxy(x,y);
//UsedExp.State.Reg1.bit.Frozen  = 0;  //unfrozen display

// cprintf("%s", theAnyStrings.cEmpty);
 cprintf("%s", Buff);
sprintf(Buff,"%X",(Data & 0xffff));
// char Buff[] = "%s";
 gotoxy((x+4),y);
//UsedExp.State.Reg1.bit.Frozen  = 0;  //unfrozen display

// cprintf("%s", theAnyStrings.cEmpty);
 cprintf("%s", Buff);
// UsedExp.State.Reg1.bit.Frozen  = 1;  //frozen display
}
#ifdef IncEmbIndicator
extern "C" void ToRemPult(unsigned long addr, char Data)
 {
   /*
	 IndData0.Value[cnt++] =  * pData;
	 IndData0.Value[cnt++] =  * pData;
	   */

  if(addr < 0xc0)
   {
    if(addr - 0x80 < 0x40) //any size
	{
   //	  if(addr - 0x80)
	   IndData0.Value[addr - 0x80] = Data;
   //	   printfpd("[%d]", addr);
   //	   printfpd(".%c", Data);
	}
   }
   else
   {
      if(addr - 0xc0 < 0x40) //any size
	{
   //	  if(addr - 0xc0)
	   IndData1.Value[addr - 0xc0] = Data;
   //    printfpd("{%d}", addr);
   //	   printfpd("_%c", Data);

	}


   }

 }
#endif  
 extern "C" void cprintf(char* Format, char* Argument)
 {
 // int iRet;
  char wcStr[25];	  //local array
  char *pwcStr;// = &wcStr[0]; 
  pwcStr = &wcStr[0]; 
 	if(!UsedExp.State.Reg1.bit.Frozen)
 //  if((!UsedExp.State.Reg1.bit.Frozen)  && (!(*pcStr)))	  // if not frozen and previons cycle is finished
 //	if(1)			   //temporary not frozen
 	{
 //   static char cStr[21];
 //to global  static char cStr[25];
   
 //   va_list arglist;
 //   va_start(arglist, form);
 //   iRet = vsprintf(cStr, form, arglist);
	    sprintf(wcStr, Format, Argument);

	

  //		printfp("1");

 //t		pcStr = &cStr[0];  //start printing pointer	to fill of commands
		while(*pwcStr)
		{
 //		  IBuff[uwIBuff++]
 /*
		IBuff[uwIBuff++] ='U';
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff++;
 		IBuff[uwIBuff++] ='O';
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff++;
		IBuff[uwIBuff++] = 1;
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff++;
		IBuff[uwIBuff++] =  UsedPult.CurAddr++;
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff++;
		IBuff[uwIBuff++] =   *pwcStr++;
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff++;
		*/
 //__________________________________________________
		ToIBuf('U');
		ToIBuf('O');
		ToIBuf(1);
#ifdef REMOTE_PULT
		ToRemPult(UsedPult.CurAddr, *pwcStr);
#endif //REMOTE_PULT


		ToIBuf(UsedPult.CurAddr++);
	  //	printfpd("(%d)",UsedPult.CurAddr);
   //		printfpd("(%c)",*pwcStr); //t
		ToIBuf(*pwcStr++);
//t		  *pcStr++ = 'U';
//t		  *pcStr++ = 'O';
//t		  *pcStr++ = 1;
//t		  *pcStr++ = UsedPult.CurAddr++; 
 //t		  *pcStr++ = *pwcStr++;
		}
 //t	   *pcStr = '\0';
 //t	   pcStr = &cStr[0];  //set printing pointer to get on display

 //get on transmit interrupt
//_____________________________________________________
 #ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif
 //	    State.Reg2.bit.NIRQ = 0;
 //	    State.Reg2.bit.Some = 0;


//_____________________________________________________
//t 1022    fill_disp(cStr);
//    va_end(arglist);
    }
  //  return iRet;
 }


 extern "C" void  cprintf4(char* Format, char* Argument)
 {
   char wcStr[25];	  //local array
  char *pwcStr;// = &wcStr[0]; 
    pwcStr = &wcStr[0]; 
   
    if(!UsedExp.State.Reg1.bit.Frozen)	  
 	{
       sprintf(wcStr, Format, Argument);
 //t	   pcStr4 = &cStr4[0];  //start printing pointer	to fill of commands

 //t	   *pcStr4++ = 'U';
  /*	    IBuff[uwIBuff++] = 'U';
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
        IBuff[uwIBuff++] = 'I';
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
  		IBuff[uwIBuff++] = 0x80;
		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
		CntIBuff += 3;	 */
//______________________________________________
		 ToIBuf('U');
		 ToIBuf('I');
		 ToIBuf(0x80);
#ifdef REMOTE_PULT

		UsedPult.CurAddr = 0x80;
#endif //REMOTE_PULT


  //t	   *pcStr4++ = 'I';
 //	   *pcStr4++ = 0x80;
	   while(*pwcStr)
		{

#ifdef REMOTE_PULT

		ToRemPult(UsedPult.CurAddr++, *pwcStr);
#endif //REMOTE_PULT

 //t	   	  *pcStr4++ = *pwcStr++;
 // 		IBuff[uwIBuff++] = *pwcStr++;
   //		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
	 //	CntIBuff++;
	   ToIBuf(*pwcStr++);

  		}
   //t	      *pcStr4 = '\0';
  //t	   pcStr4 = &cStr4[0];  //set printing pointer to get on display
     #ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif
    }
    return;
 }
 
 extern "C" void  cprintf5(char* Format, char* Argument)
 {
  char wcStr[25];	  //local array
  char *pwcStr;// = &wcStr[0]; 
  pwcStr = &wcStr[0]; 
    if(!UsedExp.State.Reg1.bit.Frozen)	  
 	{
       sprintf(wcStr, Format, Argument);
 	   ToIBuf('U');
	   ToIBuf('I');
	   ToIBuf(0xC0);
#ifdef REMOTE_PULT

		UsedPult.CurAddr = 0xC0;
#endif //REMOTE_PULT

 	   while(*pwcStr)
		{
#ifdef REMOTE_PULT
		ToRemPult(UsedPult.CurAddr++, *pwcStr);
   //		printfpd("(%d)",UsedPult.CurAddr);

#endif //REMOTE_PULT

 		  ToIBuf(*pwcStr++);
  		}
#ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif
    }
 }
 

  /*
 
  extern "C" void  cprintf5(char* Format, char* Argument)
 {
   char wcStr[25];	  //local array
  char *pwcStr;// = &wcStr[0]; 
    pwcStr = &wcStr[0]; 
   
    if((!UsedExp.State.Reg1.bit.Frozen)  && (!(*pcStr5)))	  
 	{
       sprintf(wcStr, Format, Argument);
 	   pcStr5 = &cStr5[0];  //start printing pointer	to fill of commands
	   *pcStr5++ = 'U';
	   *pcStr5++ = 'I';
	   *pcStr5++ = 0xC0;  //second line
	   while(*pwcStr)
		{
	   	  *pcStr5++ = *pwcStr++;
		}
	      *pcStr5 = '\0';
	   pcStr5 = &cStr5[0];  //set printing pointer to get on display
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
    }
    return;
 }
  
	*/

extern "C" void ticket_on(void)
{
/*
  pcStr3 = &cStr3[0];
  UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
  UsedPult.SendControlChar(UsedPult.PultCWr.all);
   */
 //  		IBuff[uwIBuff++] = 'U';
 //		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
 //       IBuff[uwIBuff++] = 'N';
//		if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
//        CntIBuff += 2;
// printEthLongHex(6);
        ToIBuf('U');
	    ToIBuf('N');
#ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif
 }




extern "C" MDataC::Init(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        char SetChangable, 
                     //   volatile char* SetStorageAddr,
						   Uint32 SetStorageAddr,
                         char SetCharsInOne,
                         CntFunc * SetpControl,
                        Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                        char *SetpMes0, char *SetpMes1,
                         char SetDgAftPnt,
                        char SetHexOrDec//,
                      ,float64 SetValue, char* SetpRemote
                     ,char * SetpRemFormat, char SetRemChars
                        ,char SetRemNum
                       , signed char SetSign   
                       ,float64 SetMinValue  
                        ,float64 SetMaxValue,
                        unsigned char SetMinMaxEnabled                  
                         )
{
 float64* pSetValue; 
 pSetValue = &SetValue;
 pFormat = pSetFormat;
 XPos = SetXPos;
 CurXPos = SetXPos; 
 YPos = SetYPos;
 Changable = SetChangable;
 StorageAddr = SetStorageAddr;
 Value = 0l;
 ChangingValue = 0l;
// if(GetKey() != Enter)//temporary Esc, need Enter
 if(StorageAddr != ZeroStorage)
 {
  if(1)//t( UsedPult.Key	!= Enter)
 {
//???? may be *psetvalue?  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?

  	pSetValue = ReadStorageC(SetStorageAddr);
 }
  Value += *pSetValue;//t
//t Value = SetValue; //to test temporary without storage
  ChangingValue += *pSetValue;
 //tChangingValue = SetValue; //to test temporary without storage

//need control 
 if(!(theCntFunc.Control(SetCntNum, Value))) //bad value in storage
 {
 	 pSetValue = &SetValue;
 	 Value = 0l;
 	 ChangingValue = 0l;
 	 Value += *pSetValue;//t
	 ChangingValue += *pSetValue;
  	 WriteStorageC(SetStorageAddr,Value);
 }
 } //storageaddr
 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 pMes0 = SetpMes0;
 pMes1 = SetpMes1;
 DgAftPnt = SetDgAftPnt;
 HexOrDec = SetHexOrDec;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars; 
 RemNum = SetRemNum;
 Sign = SetSign;
 MinValue = SetMinValue;  
 MaxValue = SetMaxValue;
 MinMaxEnabled = SetMinMaxEnabled;    
}

extern "C" void MDataC::RunWebC(float64 Val)
{
	if(Val)	{
	 if(theCntFunc.Control(CntNum, Val))
	 {	 	ChangingValue = Val;
		Value = Val;
		WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(OprNum);
	 	 UsedExp.State.Reg2.bit.Draw = 1;
		 UsedExp.State.Reg2.bit.Some = 1;
 //	 	UsedMenu.Draw();//!!!! hier is redraw menu!
	 }
	 else
	 {
  //		UsedMenu.DrawMessage(pMes0,pMes1);
 	 }
	}
}


//extern "C" float64 * MDataC::ReadStorageC(volatile char * pRAddr)
 extern "C" float64 * MDataC::ReadStorageC(Uint32 Addr)
{	
static float64 RVal = 0;	 //need static : return pointer to this!
//   float64 RVal = 0;
   unsigned long lsb; 
   unsigned long msb;
   float64 *pret;
   pret = & RVal;
   if(Addr != ZeroStorage)
   {
   _io_fseek (fn_ptr , Addr ,IO_SEEK_SET );
  //  _io_fseek (fn_ptr ,2,IO_SEEK_SET );
  
   msb =  fgetc(fn_ptr);
   msb <<= 8;
   msb += fgetc(fn_ptr);
   msb <<= 8;
   msb += fgetc(fn_ptr);
   msb <<= 8;
   msb += fgetc(fn_ptr);

   lsb =  fgetc(fn_ptr);
   lsb <<= 8;
   lsb += fgetc(fn_ptr);
   lsb <<= 8;
   lsb += fgetc(fn_ptr);
   lsb <<= 8;
   lsb += fgetc(fn_ptr);
   RVal = (msb * 0xffffffffl) + lsb;
   }
   	  
/*
	pret = & RVal;
	msb = (*pRAddr & 0xff);
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);	
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);
	pRAddr++;
	msb <<= 8;
	msb += (*pRAddr & 0xff);
	pRAddr++;	
//	ret += RVal;
	lsb = (*pRAddr & 0xff);
	pRAddr++;
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);
	pRAddr++;	
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);
	pRAddr++;
	lsb <<= 8;
	lsb += (*pRAddr & 0xff);	
	RVal = (msb * 0xffffffffl) + lsb;	
	*/

	return pret;
}

//extern "C" void MDataC::WriteStorageC(volatile char * pWAddr, float64 ftmp)
extern "C" void MDataC::WriteStorageC(Uint32 Addr, float64 ftmp)
{
 	unsigned long lsb = ftmp;
    unsigned long msb = ftmp / 0xffffffffl;
 //t	if(Addr)
	if(Addr != ZeroStorage)
	{
    _io_fseek (fn_ptr , Addr ,IO_SEEK_SET );
    fputc(((msb) >> 24), fn_ptr);
    fputc(((msb) >> 16), fn_ptr);
    fputc(((msb) >> 8),  fn_ptr);
	fputc(((msb)     ),  fn_ptr);
	fputc(((lsb) >> 24), fn_ptr);
    fputc(((lsb) >> 16), fn_ptr);
    fputc(((lsb) >> 8),  fn_ptr);
	fputc(((lsb)     ),  fn_ptr);
	}
/*
		*pWAddr = ((msb) >> 24); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((msb) >> 16); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((msb) >> 8); //go next 2 bytes
		*pWAddr++;
		*pWAddr = msb;
		*pWAddr++;
		*pWAddr = ((lsb) >> 24); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((lsb) >> 16); //go next 2 bytes
		*pWAddr++;
		*pWAddr = ((lsb) >> 8); //go next 2 bytes
		*pWAddr++;
		*pWAddr = lsb;
		*/
}

extern "C" char MDataC::RunRemoteC(char * pCommand, char SysS)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff++;
		}


//		Uint32 tmp = Value;
//		sprintf(pTBuff, pRemFormat, tmp);
		if(DgAftPnt)
		sprintf(pTBuff, pRemFormat, Value);
		else
		sprintf(pTBuff, pRemFormat, (Uint32)Value);

		for(i = RemChars; i > 0; i--)
		{
		pTBuff++;
		}
		 pControl->OperateInRead(OprNum);
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
			 tmpl = (float64)strtoll(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
			 ChangingValue =  tmpl;
			 Value =  tmpl;
			 WriteStorageC(StorageAddr,Value);
			// printf("\n\r...operate");
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
   	  // UsedMenu.DrawMessage(pMes0,pMes1);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff++;
		}
		}
		strcpy(pTBuff++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataC::RunRemoteCS(char * pCommand, char SysS)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuffS, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuffS++;
		}
   //		Uint32 tmp = Value;
   //		sprintf(pTBuffS, pRemFormat, tmp);

	    if(DgAftPnt)
		sprintf(pTBuffS, pRemFormat, Value);
		else
		sprintf(pTBuffS, pRemFormat, (Uint32)Value);

		for(i = RemChars; i > 0; i--)
		{
		pTBuffS++;
		}	
		pControl->OperateInRead(OprNum);
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
					tmpl = (float64)strtoll(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
			 ChangingValue =  tmpl;
			 Value =  tmpl;
			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //
			 {
   	//	 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuffS, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuffS++;
		}
		}
		strcpy(pTBuffS++, theAnyStrings.cRazd);	
	}
	return ret;
}



extern "C" char MDataC::RunRemoteC0(char * pCommand, char SysS)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;

	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;

		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		pTBuff0_control(strlen(pRemote));
		strcpy(pTBuff0, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff0++;
		}
	//	Uint32 tmp = Value;
	 	pTBuff0_control(RemChars);

	    if(DgAftPnt)
		sprintf(pTBuff0, pRemFormat, Value);
		else
		sprintf(pTBuff0, pRemFormat, (Uint32)Value);

 //		sprintf(pTBuff0, pRemFormat, tmp);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff0++;
		}	
		pControl->OperateInRead(OprNum);
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
	//	 	printf("\n\r...pCommand = %s", pCommand);
			 tmpl = (float64)strtoll(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
			 ChangingValue =  tmpl;
			 Value =  tmpl;
			 WriteStorageC(StorageAddr,Value);
	//	 	  printf("\n\r...operate");
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
   	 //	 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
			
  		pControl->Remote(RemNum, pCommand, CntNum);	
        pTBuff0_control(strlen(theAnyStrings.cK0));
		strcpy(pTBuff0, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff0++;
		}
		}
        pTBuff0_control(strlen(theAnyStrings.cK0));
		strcpy(pTBuff0++, theAnyStrings.cRazd);	
	}
return ret;
}

extern "C" char MDataC::RunRemoteC3(char * pCommand, char SysS)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
//printfp1("_RRC3");
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
//("_RRC3");
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff3++;
		}
  //		Uint32 tmp = Value;
   //		sprintf(pTBuff3, pRemFormat, tmp);

	    if(DgAftPnt)
		sprintf(pTBuff3, pRemFormat, Value);
		else
		sprintf(pTBuff3, pRemFormat, (Uint32)Value);

		for(i = RemChars; i > 0; i--)
		{
		pTBuff3++;
		}
		pControl->OperateInRead(OprNum);
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
			 tmpl = (float64)strtoll(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
			 ChangingValue =  tmpl;
			 Value =  tmpl;
   //			 printfpd1("_%d",tmpl);
			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
   	   //	 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff3++;
		}
		}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
	}
	return ret;
}




extern "C" void MDataC::MakeResultStrC()
{
int32 tmp;
	
	if(!DgAftPnt) //not have point
	{
	 tmp = ChangingValue;	
//   if(start_main_loop)
//   {
//printfpd( " %07d" , tmp);	  //mbere
//  }

	 	sprintf(pResultStr, pFormat, tmp);
	}
	else
	{
  //  printfpdv("\n\r++cv:%7.3f", ChangingValue);		   //df
 // 	 printfpdv("\n\r %15.8f\n\r",(float64 )ChangingValue );


   //	 tmp = ChangingValue;
	sprintf(pResultStr, pFormat, ChangingValue);

 //	 printfp(pResultStr);
	}

if((unsigned)ChangingValue == (unsigned)MAGIC_VAL1)
	{
	 strcpy(pResultStr   ," <-45");
  //	 printfp("\n\r MAGIC_VAL1");
	}





}

extern "C" void MDataC::DrawMDataC()
{	
#ifdef USE_PULT
 //  printfp("DrawMDataC");
 //  printfpd(":%d ", (unsigned long)ChangingValue);

static float64 KeepValue;

 if((unsigned)ChangingValue != (unsigned)MAGIC_VAL1)
  {

    if(!(theCntFunc.Control(CntNum, ChangingValue)))
	{
   //	printfp("1");
	 if(!MinMaxEnabled)
	  {
   //		printfp("2");

  	  ChangingValue = 0;
	  }
	 else
	  {
   //		printfp("3");

	     if(ChangingValue < MinValue)
		 {
	       ChangingValue = MinValue;
   	//	printfp("4");

		 }
		 if(ChangingValue > MaxValue)
		 {
		   ChangingValue = MaxValue;
   //			printfp("5");

		 }
		 KeepValue = ChangingValue;
	  }
	}
	else
	{
  //		printfp("6");
	  KeepValue = ChangingValue;
	}

  }

	MakeResultStrC();
 	gotoxy(XPos, YPos);
	cprintf(theAnyStrings.cs, pResultStr);
//printfp(">");
//printfp(pResultStr);   //t
//printfp("<");

//printfp(pResultStr);   //t
#endif	//USE_PULT
}




extern "C" char MDataC::LastDigit()
{
//printfpd("\n\r c:%d", CharsInOne);
 //  printfpd("\n\r x:%d", CurXPos);
	
	char ret;
	ret = CharsInOne;
	ret += XPos;
	ret -= CurXPos;
//120418	ret--;
	if(!(DgAftPnt)) ret--;	//120418
	return ret;
}

#define KEEP_DIGGTS	(3)

extern "C" float64 MDataC::Delta(char Key)
{	
	float64 RetValue;
 //	float32 CurDig; //value of  digit on cursor
 //	float32 tmpDig;	
	int16 i;
	int16 Weight; //what positon from right border of Value?
 //t	Weight = (int16)(this->CharsInOne); 
	Weight = (int16)(CharsInOne); 
 //t	Weight = Weight + (int16)(this->XPos);
	Weight = Weight + (int16)(XPos);
	Weight = Weight - 1;
 //t	Weight = Weight - (int16)(this->CurXPos);
	Weight = Weight - (int16)(CurXPos);
 //if after point - need waight +=1	 - one xpos used for point
	if(DgAftPnt)
	if(CurXPos > ((XPos + CharsInOne) - DgAftPnt))	{
	 Weight++;
 //	 printfp("______________");
 //    printfpd("CX:%d", CurXPos);
    }

	RetValue = (float64)1;

	if(!(HexOrDec)) //Decimal
	{
		for(i = Weight; i > 0; i--)
		{
		RetValue *= (float64)10;
  		}
	}
	else //HexDecimal
	{
		for(i = Weight; i > 0; i--)
		{
		RetValue *= (float64)16;
		}	
	}

//printfpd("%6.3f", (float64)RetValue);

	if(DgAftPnt) //only for decimal
	{
		for(i = DgAftPnt; i > 0; i--) //
		{
		RetValue /= (float64)10;
		}	
	}
//printfpd("%6.3f", RetValue);

//from hier i loss digits after point
	
	int32 iRet = (int32)(RetValue * (1000));

//printfpd("\n\r iRet:%d", iRet);

	int32 iChVal = (int32)(ChangingValue * (1000));
	int32 iCurDig;
	int32 iCurDig1;
	int32 iCurDig2;
	 
	if(iRet)
	iCurDig = iChVal / iRet;

	iCurDig1 = iCurDig;	
		if(HexOrDec == 0)//decimal
		{

		iCurDig = iCurDig / 10l;
		iCurDig = iCurDig * 10l;
		iCurDig2 = iCurDig1 - iCurDig;
		
			if(Key == Up)
			{
				if (iCurDig2 == 9) 
		 		{
		 	//	RetValue *= (-9);
			//	RetValue *= (-9)*Sign;
		 		}
		 	}
		 	else //Down
		 	{
				if (iCurDig2 == 0) 
		 		{
		   //		RetValue *= (-9)*Sign;
		 		}		 	
		 	}	
		}
		else //hexdecimal
		{
	 //t	iCurDig = iCurDig / 0xfl;
	//t	iCurDig = iCurDig * 0xfl;
	   	iCurDig = iCurDig / 0x10l;
		iCurDig = iCurDig * 0x10l;

		iCurDig2 = iCurDig1 - iCurDig;	
			if(Key == Up)
			{		
				if (iCurDig2 == 0xf) 
		 		{
		 		RetValue *= (-0xf)*Sign;
		 		}	
		 	}
		 	else //Key == Down
		 	{
				if (iCurDig2 == 0) 
		 		{
		 		RetValue *= (-0xf)*Sign;
		 		}			 	
		 	}	
		}  

//RetValue /= (10^KEEP_DIGGTS);

//printfpd("\n\rr:%6.3f", RetValue);
//printfpd("\n\r>%d", RetValue);

	return RetValue;
}





 extern "C" MData::MData()
{
 
}

 
//extern "C" AnyStrings::AnyStrings()


extern "C" void CntFunc::Remote(Uint16 sel, char *pDCmd, char RCntNum)
{
	switch(sel)
	{
	case 1:  break;
	default: break;
	}
}

extern "C" void CntFunc::OperateInRead(Uint16 sel)
{
  	switch(sel)
	{
#ifdef PROG_TUTS
    case 30:  //inputs
				  Reset_Triggered(0xFFFFFFFFl);
    			break;
#endif PROG_TUTS

 	default:	break;
	}
}




extern "C" CntFunc::CntFunc()
{
}


extern "C" AnyTest::AnyTest(unsigned int setvar1)
{
 var1 = setvar1;
}

extern "C" unsigned int AnyTest::AnyFunc(unsigned int param)
{
  var1 += param;
  return var1;	
}

extern "C" unsigned int UseClass()
{
 exemplar.AnyFunc(5);
 return exemplar.var1;
}



extern "C" char MDataI::RunRemoteI(char * pCommand)
{
   char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		char *ptr;
		char *tmp;
		tmp =  pTBuff;
	  //	IdCommand = 1; //right command
	   ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff++;
		}
	//	UsedRemote.pTBuff++;//t
	//	UsedRemote.pTBuff++;//t
		ptr = (char *)memchr(pRemFormat, 'f', strlen(pRemFormat));
		if(!ptr)
		sprintf(pTBuff, pRemFormat, (Uint32)Value);
		else
		sprintf(pTBuff, pRemFormat, Value);

	//	UsedRemote.pTBuff++;
		for(i = RemChars; i > 0; i--)
		{
		pTBuff++;
		}	
			
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}	
		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff++;
		}
	}
		strcpy(pTBuff++, theAnyStrings.cRazd);	
}
	//r
	return ret;
}

extern "C" char MDataI::RunRemoteIS(char * pCommand)
{
   char ret = 0;
	char *ptr;

	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		char *tmp;
		tmp =  pTBuffS;
	  //	IdCommand = 1; //right command
	   ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuffS, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuffS++;
		}
	//	UsedRemote.pTBuff++;//t
	//	UsedRemote.pTBuff++;//t
  //120419	    Uint32 tmp1 = Value;
//120419		sprintf(pTBuffS, pRemFormat, tmp1);

        ptr = (char *)memchr(pRemFormat, 'f', strlen(pRemFormat));
		if(!ptr)
		sprintf(pTBuffS, pRemFormat, (Uint32)Value);
		else
		sprintf(pTBuffS, pRemFormat, Value);

	//	UsedRemote.pTBuff++;
		for(i = RemChars; i > 0; i--)
		{
		pTBuffS++;
		}	
			
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}	
		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuffS, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuffS++;
		}
	}
		strcpy(pTBuffS++, theAnyStrings.cRazd);	
}
	//r
	return ret;
}



extern "C" char MDataI::RunRemoteI0(char * pCommand)
{
   char ret = 0;
   char *ptr;

	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
   //		char *tmp;
	 //	tmp =  pTBuff0;
	  //	IdCommand = 1; //right command
	   ret = 1;
	    
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		 pTBuff0_control(strlen(pRemote));
		strcpy(pTBuff0, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff0++;
		}
	//	UsedRemote.pTBuff++;//t
	//	UsedRemote.pTBuff++;//t

//120419	    Uint32 tmp1 = Value;
    	pTBuff0_control(RemChars);
        ptr = (char *)memchr(pRemFormat, 'f', strlen(pRemFormat));
	
		if(!ptr)
		sprintf(pTBuff0, pRemFormat, (Uint32)Value);
		else
		sprintf(pTBuff0, pRemFormat, (float)Value);


   //120419		sprintf(pTBuff0, pRemFormat, tmp1);
	//	UsedRemote.pTBuff++;
		for(i = RemChars; i > 0; i--)
		{
		pTBuff0++;
		}	
			
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}	
		pControl->Remote(RemNum, pCommand, CntNum);	
	   	pTBuff0_control(strlen(theAnyStrings.cK0));

		strcpy(pTBuff0, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;

		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff0++;
		}
	}
	pTBuff0_control(2l);

		strcpy(pTBuff0++, theAnyStrings.cRazd);	
}
	//r
	return ret;
}

extern "C" char MDataI::RunRemoteI3(char * pCommand)
{
   char ret = 0;
   char *ptr;

	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
		char *tmp;
		tmp =  pTBuff3;
	  //	IdCommand = 1; //right command
	   ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff3++;
		}
	//	UsedRemote.pTBuff++;//t
	//	UsedRemote.pTBuff++;//t
//120419	    Uint32 tmp1 = Value;
//120419		sprintf(pTBuff3, pRemFormat, tmp1);

		ptr = (char *)memchr(pRemFormat, 'f', strlen(pRemFormat));
		if(!ptr)
		sprintf(pTBuff3, pRemFormat, (Uint32)Value);
		else
		sprintf(pTBuff3, pRemFormat, Value);


	//	UsedRemote.pTBuff++;
		for(i = RemChars; i > 0; i--)
		{
		pTBuff3++;
		}	
			
//		UsedRemote.pTBuff += RemChars;
//		strcpy(UsedRemote.pTBuff++, theAnyStrings.cRazd); //add;
//		 		tmp = 1;
		}
		else //command
		{
	//			tmp = 2;
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}	
		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
//		UsedRemote.pTBuff++;
	//			tmp = 2;
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff3++;
		}
	}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
}
	//r
	return ret;
}


 // extern "C" MDataI::MDataI(char * pSetFormat, 
  extern "C" MDataI::Init(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        CntFunc * SetpControl,
                        Uint16 SetOprNum,
                        char *SetpRemote
                        ,char * SetpRemFormat, char SetRemChars
                        ,char SetRemNum, char SetCntNum
                        )
{
	pResultStr = &ResultStr[0]; //set to start
	pFormat = pSetFormat;
	XPos = SetXPos;
 	YPos = SetYPos;
 	pControl = SetpControl;
  	OprNum = SetOprNum; 
  	Value = 0;	
  	pRemote = SetpRemote;
 	pRemFormat = SetpRemFormat;
 	RemChars = SetRemChars; 
 	RemNum = SetRemNum; 
 	CntNum = SetCntNum;	
}
   
extern "C" void MDataI::MakeResultStrI()
{
	char *ptr, *ptr1;
	ptr = (char *)memchr(pFormat, 'f', strlen(pFormat));
	ptr1 = (char *)memchr(pFormat, 'e', strlen(pFormat));

    if((!ptr) && (!ptr1))
    {	
	sprintf(pResultStr, pFormat, (unsigned long)Value);
	}
	else
	{
	sprintf(pResultStr, pFormat, Value);
//	printfp("\n\rFind f");
	}

if((unsigned)Value == (unsigned)MAGIC_VAL)
	{
	 strcpy(pResultStr   ,"N/A");
	}




 // 	sprintf(pResultStr,"%d", 123); //t
  

 //   printfp("\n\r >");

// printfp("\n\r r>>");

//   printfpd(pFormat, Value);
//   printfp(" >>");
//	   printfpd("%d", Value);
//	    printfp(" >>");

//	  printfp(pFormat);
//	    printfp(" >>");

//    printfp(pResultStr);

// printfpd("%x", (unsigned long)&ResultStr[0]);
   

}

extern "C" void MDataI::DrawMDataI()
{
 #ifdef USE_PULT
	MakeResultStrI();
 	gotoxy(XPos, YPos);
    cprintf(theAnyStrings.cs, pResultStr);
#endif	//USE_PULT
}
//______________________________________________________>>> MdataV
/*
extern "C" char MDataV::RunRemoteV(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff++;
		}
		sprintf(pTBuff, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
		 if(pControl->Control(CntNum, tmpd))
	   //  if(tmpd < Quantity)
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 			  UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuff, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff++;
		}
		}
		strcpy(pTBuff++, theAnyStrings.cRazd);	
	}
  //	 printEthString(TBuff, 20);  //t  HIER LOOPS PRINT!!!!!!!
	return ret;
}

extern "C" char MDataV::RunRemoteVS(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuffS, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuffS++;
		}
		sprintf(pTBuffS, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuffS++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
//		   if(tmpd < Quantity)
		    if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
   //		UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuffS, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuffS++;
		}
		}
		strcpy(pTBuffS++, theAnyStrings.cRazd);	
	}
	return ret;
}


extern "C" char MDataV::RunRemoteV0(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
	 
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
        pTBuff0_control(strlen(pRemote));
		strcpy(pTBuff0, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff0++;
		}
        pTBuff0_control(RemChars);
		sprintf(pTBuff0, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff0++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
//		   if(tmpd < Quantity)
		    if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 	 //	UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
	    pTBuff0_control(strlen(theAnyStrings.cK0));
 		strcpy(pTBuff0, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff0++;
		}
		}
	    pTBuff0_control(strlen(theAnyStrings.cRazd));
		strcpy(pTBuff0++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataV::RunRemoteV3(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff3++;
		}
		sprintf(pTBuff3, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff3++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
		//   if(tmpd < Quantity)
		 if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 	    //    	UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff3++;
		}
		}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
	}
	return ret;
}


extern "C" void MDataV::MakeResultStrV()
{
//static unsigned char blink;
// blink++;
 	
char * pWorkPointer;
  //	pWorkPointer = pVariants; //begin from string of variants
int16 CharCnt;
int16 tmp;
	tmp = (int16)ChangingValue;
	tmp *= (int16)CharsInOne;
 //   printfp("\n\r");
 //	printfpd (" %d", blinkrate);


if(curblink >= blinkrate)
//if(blinkrate > 1)
{
   pWorkPointer = pVariants; 	
	for(CharCnt = 0; CharCnt < tmp; CharCnt++)
	{ pWorkPointer++;}
   strncpy(pResultStr, pWorkPointer, CharsInOne);
  curblink = 0;
//  printfp(pResultStr);
  // printfp("0");

}
else
{
  if (CharsInOne == 1)
  strncpy(pResultStr, " ", 1);
//120717  strncpy(pResultStr, "     ", 5);
  if (CharsInOne == 2)
  strncpy(pResultStr, "  ", 2);

  if (CharsInOne == 3)
  strncpy(pResultStr, "   ", 3);


  curblink++;
 //   printfp("++");

}
 //  printfp(pResultStr);

}

extern "C" void MDataV::DrawMDataV()
{
#ifdef USE_PULT
	
	MakeResultStrV();
 	gotoxy(XPos, YPos);
 	cprintf(theAnyStrings.cs, pResultStr);
#endif	//USE_PULT
}
extern "C" MDataV::Init(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        char SetChangable, 
//                        Uint16 SetStorageAddr,
//                        volatile char* SetStorageAddr,
						Uint32 SetStorageAddr,
                        char* pSetVariants, char SetValue,
                        char SetCharsInOne, char SetQuantity,
                        CntFunc * SetpControl, Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                        char *SetpMes0, char *SetpMes1, char* SetpRemote
                        ,char * SetpRemFormat, char SetRemChars 
                        ,char SetRemNum, unsigned char Setblinkrate
                        )
{
// pItemActive = pSetItem;	
 pFormat = pSetFormat;
 XPos = SetXPos;
 YPos = SetYPos;
 Changable = SetChangable;
 StorageAddr = SetStorageAddr;
 pVariants = pSetVariants;
 char *pSetValue;
// pSetValue = &SetValue;
 Value = 0;
 ChangingValue = 0;
// if(GetKey() != Enter)//temporary Esc, need Enter
 if(StorageAddr != ZeroStorage)
  {
  if(1)//( UsedPult.Key	!= Enter)
 {
  pSetValue = ReadStorageV(SetStorageAddr);
 }
 Value += (*pSetValue);
 ChangingValue += (*pSetValue);
 if(Value >= SetQuantity) //bad storage
 {
  Value = 0;
  ChangingValue = 0;
  pSetValue = &SetValue;
  Value += (*pSetValue);
  ChangingValue += (*pSetValue);
  WriteStorageV(SetStorageAddr, (volatile char*)Value);
 }
 }	//StorageAddr
 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 Quantity = SetQuantity;
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 pMes0 = SetpMes0;
 pMes1 = SetpMes1;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars;
 RemNum = SetRemNum;
 blinkrate = Setblinkrate;
}

//extern "C" void MDataV::WriteStorageV(volatile char * pWAddr, volatile char* WVal)
 extern "C" void MDataV::WriteStorageV(Uint32 Addr, volatile char* WVal)
{	
//temporary *pWAddr = (*WVal) & 0xff;
 //  if(Addr)
   if(Addr != ZeroStorage)
   {
    _io_fseek (fn_ptr, Addr, IO_SEEK_SET);
    fputc(*WVal, fn_ptr);
   }
}

//extern "C"  char* MDataV::ReadStorageV(volatile char * pRAddr)
extern "C"  char* MDataV::ReadStorageV(Uint32 Addr)
{	
static char RVal;  //need static : return pointer to this!
char* pRVal;

	  pRVal = &RVal;
    if(Addr != ZeroStorage)
    {
      _io_fseek(fn_ptr, Addr, IO_SEEK_SET);
      RVal =  fgetc(fn_ptr);
	}
   return pRVal;
}
  */
//________________________________________________<<< MDataV
//______________________________________________________>>> MdataVL
extern "C" char MDataV::RunRemoteV(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff++;
		}
		sprintf(pTBuff, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
		 if(pControl->Control(CntNum, tmpd))
	   //  if(tmpd < Quantity)
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 			  UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuff, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff++;
		}
		}
		strcpy(pTBuff++, theAnyStrings.cRazd);	
	}
  //	 printEthString(TBuff, 20);  //t  HIER LOOPS PRINT!!!!!!!
	return ret;
}

extern "C" char MDataV::RunRemoteVS(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuffS, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuffS++;
		}
		sprintf(pTBuffS, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuffS++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
//		   if(tmpd < Quantity)
		    if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
   //		UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuffS, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuffS++;
		}
		}
		strcpy(pTBuffS++, theAnyStrings.cRazd);	
	}
	return ret;
}


extern "C" char MDataV::RunRemoteV0(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
	 
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
        pTBuff0_control(strlen(pRemote));
		strcpy(pTBuff0, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff0++;
		}
        pTBuff0_control(RemChars);
		sprintf(pTBuff0, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff0++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
//		   if(tmpd < Quantity)
		    if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 	 //	UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
	    pTBuff0_control(strlen(theAnyStrings.cK0));
 		strcpy(pTBuff0, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff0++;
		}
		}
	    pTBuff0_control(strlen(theAnyStrings.cRazd));
		strcpy(pTBuff0++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataV::RunRemoteV3(char * pCommand)
{
unsigned long tmpd;
char * end;
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
	{
	  //	IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pTBuff3++;
		}
		sprintf(pTBuff3, pRemFormat, Value);
		for(i = RemChars; i > 0; i--)
		{
		pTBuff3++;
		}		
		}
		else //command
		{
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
		tmpd = strtol(pCommand, &end, 16);
		//   if(tmpd < Quantity)
		 if(pControl->Control(CntNum, tmpd))
			{
			ChangingValue =  tmpd;
			Value =  tmpd;
			WriteStorageV(StorageAddr,(&Value));
			pControl->Operate(OprNum);
			UsedExp.State.Reg2.bit.Draw = 1;
			UsedExp.State.Reg2.bit.Some = 1;
			}
			else
			{
 	    //    	UsedMenu.DrawMessage(pMes0, pMes1);
			}
		pControl->Remote(RemNum, pCommand, CntNum);		//check and set data from command 
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
			pTBuff3++;
		}
		}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
	}
	return ret;
}


extern "C" void MDataV::MakeResultStrV()
{
//static unsigned char blink;
// blink++;
 	
char * pWorkPointer;
  //	pWorkPointer = pVariants; //begin from string of variants
int16 CharCnt;
int16 tmp;
	tmp = (int16)ChangingValue;
	tmp *= (int16)CharsInOne;
 //   printfp("\n\r");
 //	printfpd (" %d", blinkrate);


if(curblink >= blinkrate)
//if(blinkrate > 1)
{
   pWorkPointer = pVariants; 	
	for(CharCnt = 0; CharCnt < tmp; CharCnt++)
	{ pWorkPointer++;}
   strncpy(pResultStr, pWorkPointer, CharsInOne);
  curblink = 0;
//  printfp(pResultStr);
  // printfp("0");

}
else
{
  if (CharsInOne == 1)
  strncpy(pResultStr, " ", 1);
//120717  strncpy(pResultStr, "     ", 5);
  if (CharsInOne == 2)
  strncpy(pResultStr, "  ", 2);

  if (CharsInOne == 3)
  strncpy(pResultStr, "   ", 3);


  curblink++;
 //   printfp("++");

}
 //  printfp(pResultStr);

}

extern "C" void MDataV::DrawMDataV()
{
#ifdef USE_PULT
	
	MakeResultStrV();
 	gotoxy(XPos, YPos);
 	cprintf(theAnyStrings.cs, pResultStr);
#endif	//USE_PULT
}

extern "C" MDataV::Init(char * pSetFormat, 
                        char SetXPos, char SetYPos,
                        char SetChangable, 
//                        Uint16 SetStorageAddr,
//                        volatile char* SetStorageAddr,
						Uint32 SetStorageAddr,
                        char * pSetVariants, unsigned long SetValue,
                        char SetCharsInOne, unsigned long SetQuantity,
                        CntFunc * SetpControl, Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                        char *SetpMes0, char *SetpMes1, char* SetpRemote
                        ,char * SetpRemFormat, char SetRemChars 
                        ,char SetRemNum, unsigned char Setblinkrate
                        )
{
// pItemActive = pSetItem;	
 pFormat = pSetFormat;
 XPos = SetXPos;
 YPos = SetYPos;
 Changable = SetChangable;
 StorageAddr = SetStorageAddr;
 pVariants = pSetVariants;
 unsigned long *pSetValue;
// pSetValue = &SetValue;
 Value = 0;
 ChangingValue = 0;
// if(GetKey() != Enter)//temporary Esc, need Enter
 if(StorageAddr != ZeroStorage)
  {
  if(1)//( UsedPult.Key	!= Enter)
 {
  pSetValue = ReadStorageV(SetStorageAddr);
 }
 Value += (*pSetValue);
 ChangingValue += (*pSetValue);
 if(Value >= SetQuantity) //bad storage
 {
  Value = 0;
  ChangingValue = 0;
  pSetValue = &SetValue;
  Value += (*pSetValue);
  ChangingValue += (*pSetValue);
  WriteStorageV(SetStorageAddr, (volatile unsigned long*)Value);
 }
 }	//StorageAddr
 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 Quantity = SetQuantity;
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 pMes0 = SetpMes0;
 pMes1 = SetpMes1;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars;
 RemNum = SetRemNum;
 blinkrate = Setblinkrate;
}

//extern "C" void MDataV::WriteStorageV(volatile char * pWAddr, volatile char* WVal)
 extern "C" void MDataV::WriteStorageV(Uint32 Addr, volatile unsigned long* WVal)
{	
//temporary *pWAddr = (*WVal) & 0xff;
 //  if(Addr)
   if(Addr != ZeroStorage)
   {
    _io_fseek (fn_ptr, Addr, IO_SEEK_SET);
    fputc(*WVal, fn_ptr);
   }
}

//extern "C"  char* MDataV::ReadStorageV(volatile char * pRAddr)
//extern "C"  char* MDataV::ReadStorageV(Uint32 Addr)
extern "C"  unsigned long* MDataV::ReadStorageV(Uint32 Addr)
{	
//static char RVal;  //need static : return pointer to this!
static unsigned long RVal;  //need static : return pointer to this!
//char* pRVal;
unsigned long* pRVal;

	  pRVal = &RVal;
    if(Addr != ZeroStorage)
    {
      _io_fseek(fn_ptr, Addr, IO_SEEK_SET);
      RVal =  fgetc(fn_ptr);
	}
   return pRVal;
}

//________________________________________________<<< MDataVL


//________________________________________________>>> Item

extern "C" void Item::SetCursor()
	{

 		if (UsedMenu.MenuState.DataC0Changing)
		{
			gotoxy(pDataC0->CurXPos,pDataC0->YPos);
		}
		else if (UsedMenu.MenuState.DataC1Changing)
		{
			gotoxy(pDataC1->CurXPos,pDataC1->YPos);
		}
		else if (UsedMenu.MenuState.DataC2Changing)
		{
			gotoxy(pDataC2->CurXPos,pDataC2->YPos);
		}
		else if (UsedMenu.MenuState.DataC3Changing)
		{
			gotoxy(pDataC3->CurXPos,pDataC3->YPos);
		}
 		else if(UsedMenu.MenuState.DataP0Changing)
		{
			gotoxy(pDataP0->XPos,pDataP0->YPos);
		}
		else if(UsedMenu.MenuState.DataP1Changing)
		{
			gotoxy(pDataP1->XPos,pDataP1->YPos);	
		}
		else if(UsedMenu.MenuState.DataP2Changing)
		{
			gotoxy(pDataP2->XPos,pDataP2->YPos);	
		}
 	}

extern "C" void Item::DrawItem()
	{
//	printfp("3");

	#ifdef USE_PULT
 //  return; //to test
  	gotoxy(1, 1);	//to get off cursor
 //t	cprintf("%s", line0);
	cprintf4("%s", line0);
 //	gotoxy(1, 2);
//	cprintf2("%s", line1);
	cprintf5("%s", line1);
	if(pDataI0){ pDataI0->DrawMDataI(); gotoxy(pDataI0->XPos, pDataI0->YPos);}
	if(pDataI1){ pDataI1->DrawMDataI(); gotoxy(pDataI1->XPos, pDataI0->YPos);}
	if(pDataP0){ pDataP0->DrawMDataV(); gotoxy(pDataP0->XPos, pDataP0->YPos);}
	if(pDataP1){ pDataP1->DrawMDataV(); gotoxy(pDataP1->XPos, pDataP1->YPos);}
	if(pDataP2){ pDataP2->DrawMDataV(); gotoxy(pDataP2->XPos, pDataP2->YPos);} //go to p0 to start from p0 data
	if(pDataC0){ pDataC0->DrawMDataC(); gotoxy(pDataC0->XPos, pDataC0->YPos);}
    if(pDataC1){ pDataC1->DrawMDataC(); gotoxy(pDataC1->XPos, pDataC1->YPos);}
    if(pDataC2){ pDataC2->DrawMDataC(); gotoxy(pDataC2->XPos, pDataC2->YPos);}
 	if(pDataC3){ pDataC3->DrawMDataC(); gotoxy(pDataC3->XPos, pDataC3->YPos);}
	if(pDataS0){ pDataS0->DrawMDataS(); gotoxy(pDataS0->XPos, pDataS0->YPos);}
	if(pDataS1){ pDataS1->DrawMDataS(); gotoxy(pDataS1->XPos, pDataS1->YPos);}

 //		cprintf5("%s", line1); //t140226
 	SetCursor(); //correctly set cursor
#endif	//USE_PULT
	}

extern "C" Item::Init(char* l0, char* l1, 
		char v,Item* SetLeft,
 Item* SetRight, Item* SetUp, Item* SetDown,
 MDataV * SetpDataP0, MDataV * SetpDataP1, MDataV * SetpDataP2,
 MDataI* SetpDataI0, MDataI* SetpDataI1,
 MDataC* SetpDataC0,MDataC* SetpDataC1, MDataC* SetpDataC2,MDataC* SetpDataC3,
  MDataS* SetpDataS0, MDataS* SetpDataS1)
 {
	line0 = l0;
	line1 = l1;
	visibled = v;	
	pItemLeft = SetLeft;
	pItemRight = SetRight;
	pItemUp = SetUp;
	pItemDown = SetDown;
	pDataP0 = SetpDataP0;
	pDataP1 = SetpDataP1;	
	pDataP2 = SetpDataP2;	
	pDataI0 = SetpDataI0;
	pDataI1 = SetpDataI1;
	pDataC0 = SetpDataC0;
	pDataC1 = SetpDataC1;
    pDataC2 = SetpDataC2;
    pDataC3 = SetpDataC3;
	pDataS0 = SetpDataS0;
	pDataS1 = SetpDataS1;
}	

//________________________________________________<<< Item
//________________________________________________>>>Menu
extern "C" void Menu::StartChanging()
{
//t	CurrentItem->DrawItem(); //to get off messages
	if(CurrentItem->pDataP0)
	{
	if(CurrentItem->pDataP0->Changable)
	 {
	 gotoxy(CurrentItem->pDataP0->XPos,CurrentItem->pDataP0->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP0Changing = 1;
	 return;
	 }
	}

	if(CurrentItem->pDataP1)
	{
	if(CurrentItem->pDataP1->Changable)
	 {
	 gotoxy(CurrentItem->pDataP1->XPos,CurrentItem->pDataP1->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP1Changing = 1;
	 return;
	 }
	}

	if(CurrentItem->pDataP2)
	{
	if(CurrentItem->pDataP2->Changable)
	 {
	 gotoxy(CurrentItem->pDataP2->XPos,CurrentItem->pDataP2->YPos);
	 _setcursortype(1); //blink on
 	 MenuState.DataChanging = 1;	 
 	 MenuState.DataP2Changing = 1;
	 return;
	 }
	}

	if(CurrentItem->pDataC0)
	{
	 if(CurrentItem->pDataC0->Changable)
	 {
	 gotoxy(CurrentItem->pDataC0->XPos,CurrentItem->pDataC0->YPos);
	 _setcursortype(1); //blink on
 	  MenuState.DataChanging = 1;	 
 	  MenuState.DataC0Changing = 1;
	  return;
	 }
	}	

	if(CurrentItem->pDataC1)
	{
	 if(CurrentItem->pDataC1->Changable)
	 {
	 gotoxy(CurrentItem->pDataC1->XPos,CurrentItem->pDataC1->YPos);
	 _setcursortype(1); //blink on
 	  MenuState.DataChanging = 1;	 
 	  MenuState.DataC1Changing = 1;
	  return;
	 }
	}	

	if(CurrentItem->pDataC2)
	{
	 if(CurrentItem->pDataC2->Changable)
	 {
	 gotoxy(CurrentItem->pDataC2->XPos,CurrentItem->pDataC2->YPos);
	 _setcursortype(1); //blink on
 	  MenuState.DataChanging = 1;	 
 	  MenuState.DataC2Changing = 1;
	  return;
	 }
	}	
	
	if(CurrentItem->pDataC3)
	{
	 if(CurrentItem->pDataC3->Changable)
	 {
	 gotoxy(CurrentItem->pDataC3->XPos,CurrentItem->pDataC3->YPos);
	 _setcursortype(1); //blink on
 	  MenuState.DataChanging = 1;	 
 	  MenuState.DataC3Changing = 1;
	  return;
	 }
	}	
}

extern "C" void Menu::StopChanging()
{
//need keep data value to ROM
//need load parameters to registers
	if(CurrentItem->pDataP0)
	{
	 if(CurrentItem->pDataP0->pControl->
	 Control(CurrentItem->pDataP0->CntNum, 
	 CurrentItem->pDataP0->ChangingValue))
	 {
 //	 printfp("\n\r  po cv : %d",  (unsigned)CurrentItem->pDataP0->ChangingValue);
	 CurrentItem->pDataP0->Value = CurrentItem->pDataP0->ChangingValue;
//	 WriteStorageV(CurrentItem->pDataP0->StorageAddr, (volatile char*)&CurrentItem->pDataP0->Value);
 //	 CurrentItem->pDataP0->WriteStorageV(CurrentItem->pDataP0->StorageAddr, (volatile char*)&CurrentItem->pDataP0->Value);
	 CurrentItem->pDataP0->WriteStorageV(CurrentItem->pDataP0->StorageAddr, (volatile unsigned long*)&CurrentItem->pDataP0->Value);
	 CurrentItem->pDataP0->pControl->Operate(CurrentItem->pDataP0->OprNum);
	 }
	 else
	 {
  	 CurrentItem->pDataP0->ChangingValue = CurrentItem->pDataP0->Value;
 //	 DrawMessage(CurrentItem->pDataP0->pMes0, 
 //				CurrentItem->pDataP0->pMes1);
	 }
	}

	if(CurrentItem->pDataP1)
	{
	 if(CurrentItem->pDataP1->pControl->
	 Control(CurrentItem->pDataP1->CntNum,
	 CurrentItem->pDataP1->ChangingValue))
	 {
	 CurrentItem->pDataP1->Value = CurrentItem->pDataP1->ChangingValue;
//	 WriteStorageV(CurrentItem->pDataP1->StorageAddr, (volatile char*)&CurrentItem->pDataP1->Value);
 //	 CurrentItem->pDataP1->WriteStorageV(CurrentItem->pDataP1->StorageAddr, (volatile char*)&CurrentItem->pDataP1->Value);
	 CurrentItem->pDataP1->WriteStorageV(CurrentItem->pDataP1->StorageAddr, (volatile unsigned long*)&CurrentItem->pDataP1->Value);
	 CurrentItem->pDataP1->pControl->Operate(CurrentItem->pDataP1->OprNum);	 
	 }
	 else
	 {
		CurrentItem->pDataP1->ChangingValue = CurrentItem->pDataP1->Value;
  //		DrawMessage(CurrentItem->pDataP1->pMes0, 
  //				CurrentItem->pDataP1->pMes1);
	 }
	}	

	if(CurrentItem->pDataP2)
	{
	 if(CurrentItem->pDataP2->pControl->
	 Control(CurrentItem->pDataP2->CntNum,
	 CurrentItem->pDataP2->ChangingValue))
	 {
	 CurrentItem->pDataP2->Value = CurrentItem->pDataP2->ChangingValue;
//	 WriteStorageV(CurrentItem->pDataP2->StorageAddr, (volatile char*)&CurrentItem->pDataP2->Value);
//	 CurrentItem->pDataP2->WriteStorageV(CurrentItem->pDataP2->StorageAddr, (volatile char*)&CurrentItem->pDataP2->Value);
	 CurrentItem->pDataP2->WriteStorageV(CurrentItem->pDataP2->StorageAddr, (volatile unsigned long*)&CurrentItem->pDataP2->Value);
	 CurrentItem->pDataP2->pControl->Operate(CurrentItem->pDataP2->OprNum);	 
	 }
	 else
	 {
		CurrentItem->pDataP2->ChangingValue = CurrentItem->pDataP2->Value;
	//	DrawMessage(CurrentItem->pDataP2->pMes0, 
	//			CurrentItem->pDataP2->pMes1);
	 }
	}
		
	if(CurrentItem->pDataC0)
	{
	 if(CurrentItem->pDataC0->pControl->
	 Control(CurrentItem->pDataC0->CntNum,
	 CurrentItem->pDataC0->ChangingValue))
	 {
	 CurrentItem->pDataC0->Value = 
	 CurrentItem->pDataC0->ChangingValue;
//	 WriteStorageC(CurrentItem->pDataC0->StorageAddr, CurrentItem->pDataC0->Value);
	 CurrentItem->pDataC0->WriteStorageC(CurrentItem->pDataC0->StorageAddr, CurrentItem->pDataC0->Value);
	 CurrentItem->pDataC0->pControl->Operate(CurrentItem->pDataC0->OprNum);	 
	 }
	 else
	 {
  		CurrentItem->pDataC0->ChangingValue = CurrentItem->pDataC0->Value;
 //		DrawMessage(CurrentItem->pDataC0->pMes0, 
  // 			CurrentItem->pDataC0->pMes1);
	//		CurrentItem->pDataC0->pMes0);	//t

	 }
	}
//__________________________________________________________
	if(CurrentItem->pDataC1)
	{
	 if(CurrentItem->pDataC1->pControl->
	 Control(CurrentItem->pDataC1->CntNum,
	 CurrentItem->pDataC1->ChangingValue))
	 {
	 CurrentItem->pDataC1->Value = 
	 CurrentItem->pDataC1->ChangingValue;
//	 WriteStorageC(CurrentItem->pDataC1->StorageAddr, CurrentItem->pDataC1->Value);
	 CurrentItem->pDataC1->WriteStorageC(CurrentItem->pDataC1->StorageAddr, CurrentItem->pDataC1->Value);
	 CurrentItem->pDataC1->pControl->Operate(CurrentItem->pDataC1->OprNum);	 
	 }
	 else
	 {
   		CurrentItem->pDataC1->ChangingValue = CurrentItem->pDataC1->Value;
  //		DrawMessage(CurrentItem->pDataC1->pMes0, 
   //				CurrentItem->pDataC1->pMes1);
	 }
	}
//___________________
   if(CurrentItem->pDataC2)
	{
	 if(CurrentItem->pDataC2->pControl->
	 Control(CurrentItem->pDataC2->CntNum,
	 CurrentItem->pDataC2->ChangingValue))
	 {
	 CurrentItem->pDataC2->Value = 
	 CurrentItem->pDataC2->ChangingValue;
//	 WriteStorageC(CurrentItem->pDataC2->StorageAddr, CurrentItem->pDataC2->Value);
	 CurrentItem->pDataC2->WriteStorageC(CurrentItem->pDataC2->StorageAddr, CurrentItem->pDataC2->Value);
	 CurrentItem->pDataC2->pControl->Operate(CurrentItem->pDataC2->OprNum);	 
	 }
	 else
	 {
		CurrentItem->pDataC2->ChangingValue = CurrentItem->pDataC2->Value;
//		DrawMessage(CurrentItem->pDataC2->pMes0, 
//				CurrentItem->pDataC2->pMes1);
	 }
	}
//___________________
  if(CurrentItem->pDataC3)
	{
	 if(CurrentItem->pDataC3->pControl->
	 Control(CurrentItem->pDataC3->CntNum,
	 CurrentItem->pDataC3->ChangingValue))
	 {
	 CurrentItem->pDataC3->Value = 
	 CurrentItem->pDataC3->ChangingValue;
//	 WriteStorageC(CurrentItem->pDataC3->StorageAddr, CurrentItem->pDataC3->Value);
	 CurrentItem->pDataC3->WriteStorageC(CurrentItem->pDataC3->StorageAddr, CurrentItem->pDataC3->Value);
	 CurrentItem->pDataC3->pControl->Operate(CurrentItem->pDataC3->OprNum);	 
	 }
	 else
	 {
 		CurrentItem->pDataC3->ChangingValue = CurrentItem->pDataC3->Value;
 //		DrawMessage(CurrentItem->pDataC3->pMes0, 
 //				CurrentItem->pDataC3->pMes1);
	 }
	}
 		
	_setcursortype(0); //blink off
	MenuState.DataChanging = 0;	
	MenuState.DataP0Changing = 0;
	MenuState.DataP1Changing = 0;
	MenuState.DataP2Changing = 0;
	MenuState.DataC0Changing = 0;
	MenuState.DataC1Changing = 0;
	MenuState.DataC2Changing = 0;
	MenuState.DataC3Changing = 0;
}



extern "C" void Menu::DrawMessage(char * mline0, char * mline1)
{
#ifdef USE_PULT

	UsedExp.State.Reg1.bit.Frozen = 0; //unfrozen display
//	gotoxy(1, 1);
 //t	cprintf("%s", theAnyStrings.cEmpty);
 //   cprintf4("%s", theAnyStrings.cEmpty);

//	gotoxy(1, 2);
 //	cprintf2("%s", theAnyStrings.cEmpty);
//	cprintf5("%s", theAnyStrings.cEmpty);
//	gotoxy(1, 1);
 //t	cprintf("%s", mline0);
    cprintf4("%s", mline0);
    cprintf5("%s", mline1);

//	gotoxy(1, 2);
 //	cprintf2("%s", mline1);
//	cprintf5("%s", mline1);
 //t	cprintf5("%s", mline1);
//     cprintf4("%s", mline0);

	UsedExp.State.Reg1.bit.Frozen = 1; //frozen display
#endif	//USE_PULT
}
extern "C" Menu::Init(Item * SetItem, Uint32 SetRedrawPeriod)
{
 CurrentItem = SetItem;
 MenuState.DataChanging = 0; //not changing now
 MenuState.DataP0Changing = 0; //not changing now
 MenuState.DataP1Changing = 0; //not changing now
 MenuState.DataP2Changing = 0; //not changing now
 MenuState.DataC0Changing = 0; //not changing now
 MenuState.DataC1Changing = 0; //not changing now
 MenuState.DataC2Changing = 0; //not changing now
 MenuState.DataC3Changing = 0; //not changing now
 RedrawPeriod = SetRedrawPeriod;
}	

extern "C" void Menu::Draw()
{
#ifdef USE_PULT

 // this->CurrentItem->DrawItem();//
#ifdef PROG_KTVM
 if(TestMode.Value == 0x20)
#endif //PROG_KTVM
#ifdef PROG_DTVM
 if(TestMode.Value == 0x20)
#endif //PROG_DTVM
#ifdef PROG_BMD35
 if(TestMode.Value == 0x20)
#endif //PROG_BMD35

#ifdef PROG_MPC35
 if(TestMode.Value == 0x20)
#endif //PROG_MPC35


  CurrentItem->DrawItem();//
#endif	//USE_PULT
}

extern "C" void Menu::SetChange(Uint16 SelChange)
{
	switch(SelChange)
	{
		case 0 :	 gotoxy(CurrentItem->pDataP0->XPos,CurrentItem->pDataP0->YPos);
			 		 MenuState.DataP0Changing = 1;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 0;
					 break;
	 	case 1 :	 gotoxy(CurrentItem->pDataP1->XPos,CurrentItem->pDataP1->YPos);
	 	 			 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 1;
 	 				 MenuState.DataP2Changing = 0;
 	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 0;
 	 				 break;
 	 	case 2 :	 gotoxy(CurrentItem->pDataP2->XPos,CurrentItem->pDataP2->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 1;
	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 0;
	 				 break;
 	 	case 3 :	 gotoxy(CurrentItem->pDataC0->XPos,CurrentItem->pDataC0->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 1;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 0;
	 				 CurrentItem->pDataC0->CurXPos = CurrentItem->pDataC0->XPos;
	 				 break;	 
	   case 4 :	     gotoxy(CurrentItem->pDataC1->XPos,CurrentItem->pDataC1->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 1;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 0;
	 				 CurrentItem->pDataC1->CurXPos = CurrentItem->pDataC1->XPos;
	 				 break;	 
 	   case 5 :	     gotoxy(CurrentItem->pDataC2->XPos,CurrentItem->pDataC2->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 1;	
					 MenuState.DataC3Changing = 0;
	 				 CurrentItem->pDataC2->CurXPos = CurrentItem->pDataC2->XPos;
	 				 break;	 
   	   case 6 :	     gotoxy(CurrentItem->pDataC3->XPos,CurrentItem->pDataC3->YPos);
 	 				 MenuState.DataP0Changing = 0;
	 				 MenuState.DataP1Changing = 0;
	 				 MenuState.DataP2Changing = 0;
	 				 MenuState.DataC0Changing = 0;
					 MenuState.DataC1Changing = 0;
					 MenuState.DataC2Changing = 0;	
					 MenuState.DataC3Changing = 1;
	 				 CurrentItem->pDataC3->CurXPos = CurrentItem->pDataC3->XPos;
	 				 break;	 
   	 				 				 
		default:	 break;				 

	}
}

extern "C" void Menu::OperateRight()
{
		if(MenuState.DataChanging == 0) //have data, it are not changing now
		{		
				 /*
				do {this->CurrentItem = this->CurrentItem->pItemRight;}
				  while(!(this->CurrentItem->visibled));
				 */
				 if(CurrentItem->pItemRight != NULL)
				 {
				   CurrentItem = CurrentItem->pItemRight;
				 }
			  
		 		Draw(); 		  
		}
		else //data is changing
		{
			if(MenuState.DataP0Changing == 1)//now changed DataP0
			{
				if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
					 {
	 				 	 SetChange(1);
	 				 }
				else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
				 	 {
	 				 	 SetChange(2);
	 				 }		
				else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
				 	 {
	 				 	 SetChange(3);
	 				 }	
	 			 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }	
	 			  else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
  				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		
	 	
	 	
			}
			else if(MenuState.DataP1Changing == 1)//now changed DataP1
			{
				 if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
				 	 {
	 				 	 SetChange(2);
	 				 }		
				else if((CurrentItem->pDataC0) &&
						(CurrentItem->pDataC0->Changable))
					 {
	 					 SetChange(3);
	 				 }
					 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }	
	 			  else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
  				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		
				 else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
	 				 }
			}//p1
			else if(MenuState.DataP2Changing == 1)//now changed DataP1
			{
				if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 					 SetChange(3);
					 }
					 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }	
	 			  else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
  				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		

				 else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
							(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
			}//p2
			else if(MenuState.DataC0Changing == 1)//now changed DataC0
			{

//printfpd("\n\rL> %d",CurrentItem->pDataC0->LastDigit());

			 if(!(CurrentItem->pDataC0->LastDigit())) //cursor on last digit
				{
				   if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }	
	 			  else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
  				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		
			  
				 else if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
				else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
				 	 {
	 	 				 SetChange(2);
	 				 }		
				else
					{
						 SetChange(3); //go first digit
					}
				} //lastdigit() != 0
  
			else //need to get to next digit
				{
				//change next digit
				CurrentItem->pDataC0->CurXPos++;
//printfpd("\n\r1> %d",CurrentItem->pDataC0->CurXPos);

				if(CurrentItem->pDataC0->DgAftPnt)
				{
					if(CurrentItem->pDataC0->CurXPos ==
					(CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne -
					CurrentItem->pDataC0->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{

//printfp("\n\r++");
					CurrentItem->pDataC0->CurXPos++;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC0->CurXPos, CurrentItem->pDataC0->YPos);
				}
			}//c0
			//_____________________________________________________________________________C1
	else if(MenuState.DataC1Changing == 1)//now changed DataC1
			{
			 if(!(CurrentItem->pDataC1->LastDigit())) //cursor on last digit
				{
				   if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
  				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		
			  
				 else if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
				else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
				 	 {
	 	 				 SetChange(2);
	 				 }
	 			else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
				 	 {
	 				 	 SetChange(3);
	 				 }	
 		
				else
					{
						 SetChange(4); //go first digit
					}
				} //lastdigit() != 0
				else //need to get to next digit
				{
				//change next digit
				CurrentItem->pDataC1->CurXPos++;
				if(CurrentItem->pDataC1->DgAftPnt)
				{
					if(CurrentItem->pDataC1->CurXPos ==
					(CurrentItem->pDataC1->XPos +
					CurrentItem->pDataC1->CharsInOne -
					CurrentItem->pDataC1->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC1->CurXPos++;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC1->CurXPos, CurrentItem->pDataC1->YPos);
				}
			}//c0
  // need add c2 and c3






  //_____________________________________________________________________________C1
 //_____________________________________________________________________________C2
	else if(MenuState.DataC2Changing == 1)//now changed DataC2
			{
			 if(!(CurrentItem->pDataC2->LastDigit())) //cursor on last digit
				{
				  
  				  if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(6);
	 				 }		
			  
				 else if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
				else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
				 	 {
	 	 				 SetChange(2);
	 				 }
	 			else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
				 	 {
	 				 	 SetChange(3);
	 				 }	
 				else   if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }		
				else
					{
						 SetChange(5); //go first digit
					}
				} //lastdigit() != 0
				else //need to get to next digit
				{
				//change next digit
				CurrentItem->pDataC2->CurXPos++;
				if(CurrentItem->pDataC2->DgAftPnt)
				{
					if(CurrentItem->pDataC2->CurXPos ==
					(CurrentItem->pDataC2->XPos +
					CurrentItem->pDataC2->CharsInOne -
					CurrentItem->pDataC2->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC2->CurXPos++;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC2->CurXPos, CurrentItem->pDataC2->YPos);
				}
			}//c2
   
  //_____________________________________________________________________________C2
  //_____________________________________________________________________________C3
	else if(MenuState.DataC3Changing == 1)//now changed DataC3
			{
			 if(!(CurrentItem->pDataC3->LastDigit())) //cursor on last digit
				{
				  
  				  if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
					 {
	 					 SetChange(0);
					 }
				 else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	 {
	 	 				 SetChange(1);
	 				 }		
				else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
				 	 {
	 	 				 SetChange(2);
	 				 }
	 			else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
				 	 {
	 				 	 SetChange(3);
	 				 }	
 				else   if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
				 	 {
	 				 	 SetChange(4);
	 				 }	
	 			else  if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
				 	 {
	 				 	 SetChange(5);
	 				 }		
			  	else
					{
						 SetChange(6); //go first digit
					}
				} //lastdigit() != 0
				else //need to get to next digit
				{
				//change next digit
				CurrentItem->pDataC3->CurXPos++;
				if(CurrentItem->pDataC3->DgAftPnt)
				{
					if(CurrentItem->pDataC3->CurXPos ==
					(CurrentItem->pDataC3->XPos +
					CurrentItem->pDataC3->CharsInOne -
					CurrentItem->pDataC3->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC3->CurXPos++;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC3->CurXPos, CurrentItem->pDataC3->YPos);
				}
			}//c3
   
  //_____________________________________________________________________________C3
		}
//	 Draw(); 
}

extern "C" void Menu::OperateLeft()
{

		if(MenuState.DataChanging == 0) //have data, it are not changing now
		{	
		/*	
				do {this->CurrentItem = this->CurrentItem->pItemLeft;}
				  while(!(this->CurrentItem->visibled));
		   */
				 if(CurrentItem->pItemLeft != NULL)
				 {
				   CurrentItem = CurrentItem->pItemLeft;
				 }
				 Draw(); //after Draw() cursor in last position
		}
		else //data is changing
		{
			if(MenuState.DataP0Changing == 1)//now changed DataP0
			{
				  if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				  else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
				 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
				 else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			   	 else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
					 {
	 				 	 SetChange(2);
	 				 }
				else if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
				 	 {
	 				 	 SetChange(1);
	 				 }		
			}
			else if(MenuState.DataP1Changing == 1)//now changed DataP1
			{
				 if((CurrentItem->pDataP0) &&
					(CurrentItem->pDataP0->Changable))
				 	 {
	 				 	 SetChange(0);
	 				 }
	 			 else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				 else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
				 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
	 			else if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
				else if((CurrentItem->pDataP2) &&
					(CurrentItem->pDataP2->Changable))
					 {
	 					 SetChange(2);
	 				 }
			}//p1
			else if(MenuState.DataP2Changing == 1)//now changed DataP2
			{
				 
				 if((CurrentItem->pDataP1) &&
					(CurrentItem->pDataP1->Changable))
					 {
	 					 SetChange(1);
					 }
				 else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	 {
	 	 				 SetChange(0);
	 				 }
	 			  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				 else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
				 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
	 			 else if((CurrentItem->pDataC0) &&
						(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			}//p2
//________________________________________________________________________c0
			else if(MenuState.DataC0Changing == 1)//now changed DataC0
			{

				 if(CurrentItem->pDataC0->CurXPos ==
				 	CurrentItem->pDataC0->XPos)
				 { //go to next data or to lastdigit
					if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
					{
	 				 	 SetChange(2);
	 				 
					}
					else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	{
	 				 	 SetChange(1);
	 				}
					else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	{
	 				 	 SetChange(0);
	 				}
	 				  else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				 else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
				 else if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
				  else //go last digit
					{
					CurrentItem->pDataC0->CurXPos =
					CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne - 1;

					if(CurrentItem->pDataC0->DgAftPnt)	 //120418
					CurrentItem->pDataC0->CurXPos++;


					gotoxy(CurrentItem->pDataC0->CurXPos,
							CurrentItem->pDataC0->YPos);
					}
				 }//first digit
			 	else //not first digit
			 	{ // go to previons digit
				CurrentItem->pDataC0->CurXPos--;
//printfpd("\n\r2> %d",CurrentItem->pDataC0->CurXPos);

				if(CurrentItem->pDataC0->DgAftPnt)
				{
					if(CurrentItem->pDataC0->CurXPos ==
					(CurrentItem->pDataC0->XPos +
					CurrentItem->pDataC0->CharsInOne -
					CurrentItem->pDataC0->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
//printfp("--");
					CurrentItem->pDataC0->CurXPos--;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC0->CurXPos, 
					CurrentItem->pDataC0->YPos);
			 } //not first digit
		   } //changing DataC0
//____________________________________________________________________________________c0		   
//____________________________________________________________________________________c1
			else if(MenuState.DataC1Changing == 1)//now changed DataC1
			{

				 if(CurrentItem->pDataC1->CurXPos ==
				 	CurrentItem->pDataC1->XPos)
				 { //go to next data or to lastdigit
					 if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			   		else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
					{
	 				 	 SetChange(2);
	 				 
					}
					else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	{
	 				 	 SetChange(1);
	 				}
					else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	{
	 				 	 SetChange(0);
	 				}
					 else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				    else if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
			       	else //go last digit
					{
					CurrentItem->pDataC1->CurXPos =
					CurrentItem->pDataC1->XPos +
					CurrentItem->pDataC1->CharsInOne - 1;

					if(CurrentItem->pDataC1->DgAftPnt)	 //120418
					CurrentItem->pDataC1->CurXPos++;

					gotoxy(CurrentItem->pDataC1->CurXPos,
							CurrentItem->pDataC1->YPos);
					}
				 }//first digit
			 	else //not first digit
			 	{ // go to previons digit
				CurrentItem->pDataC1->CurXPos--;
				if(CurrentItem->pDataC1->DgAftPnt)
				{
					if(CurrentItem->pDataC1->CurXPos ==
					(CurrentItem->pDataC1->XPos +
					CurrentItem->pDataC1->CharsInOne -
					CurrentItem->pDataC1->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC1->CurXPos--;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC1->CurXPos, 
					CurrentItem->pDataC1->YPos);
			 } //not first digit
		   } //changing DataC1
//____________________________________________________________________________________c1				   
//____________________________________________________________________________________c2
			else if(MenuState.DataC2Changing == 1)//now changed DataC2
			{

				 if(CurrentItem->pDataC2->CurXPos ==
				 	CurrentItem->pDataC2->XPos)
				 { //go to next data or to lastdigit
				     if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
					else  if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			   		else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
					{
	 				 	 SetChange(2);
	 				 
					}
					else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	{
	 				 	 SetChange(1);
	 				}
					else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	{
	 				 	 SetChange(0);
	 				}
					 else if((CurrentItem->pDataC3) &&
					(CurrentItem->pDataC3->Changable))
					 {
	 				 	 SetChange(6);
	 				 }
				      	else //go last digit
					{
					CurrentItem->pDataC2->CurXPos =
					CurrentItem->pDataC2->XPos +
					CurrentItem->pDataC2->CharsInOne - 1;

					if(CurrentItem->pDataC2->DgAftPnt)	 //120418
					CurrentItem->pDataC2->CurXPos++;

					gotoxy(CurrentItem->pDataC2->CurXPos,
							CurrentItem->pDataC2->YPos);
					}
				 }//first digit
			 	else //not first digit
			 	{ // go to previons digit
				CurrentItem->pDataC2->CurXPos--;
				if(CurrentItem->pDataC2->DgAftPnt)
				{
					if(CurrentItem->pDataC2->CurXPos ==
					(CurrentItem->pDataC2->XPos +
					CurrentItem->pDataC2->CharsInOne -
					CurrentItem->pDataC2->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC2->CurXPos--;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC2->CurXPos, 
					CurrentItem->pDataC2->YPos);
			 } //not first digit
		   } //changing DataC1
//____________________________________________________________________________________c2				   
//____________________________________________________________________________________c3
			else if(MenuState.DataC3Changing == 1)//now changed DataC3
			{

				 if(CurrentItem->pDataC3->CurXPos ==
				 	CurrentItem->pDataC3->XPos)
				 { //go to next data or to lastdigit
					if((CurrentItem->pDataC2) &&
					(CurrentItem->pDataC2->Changable))
					 {
	 				 	 SetChange(5);
	 				 }
			  	    else  if((CurrentItem->pDataC1) &&
					(CurrentItem->pDataC1->Changable))
					 {
	 				 	 SetChange(4);
	 				 }
					else  if((CurrentItem->pDataC0) &&
					(CurrentItem->pDataC0->Changable))
					 {
	 				 	 SetChange(3);
	 				 }
			   		else if((CurrentItem->pDataP2) &&
						(CurrentItem->pDataP2->Changable))
					{
	 				 	 SetChange(2);
	 				 
					}
					else if((CurrentItem->pDataP1) &&
						(CurrentItem->pDataP1->Changable))
				 	{
	 				 	 SetChange(1);
	 				}
					else if((CurrentItem->pDataP0) &&
						(CurrentItem->pDataP0->Changable))
				 	{
	 				 	 SetChange(0);
	 				}
				   	else //go last digit
					{
					CurrentItem->pDataC3->CurXPos =
					CurrentItem->pDataC3->XPos +
					CurrentItem->pDataC3->CharsInOne - 1;
					gotoxy(CurrentItem->pDataC3->CurXPos,
							CurrentItem->pDataC3->YPos);
					}
				 }//first digit
			 	else //not first digit
			 	{ // go to previons digit
				CurrentItem->pDataC3->CurXPos--;
				if(CurrentItem->pDataC3->DgAftPnt)
				{
					if(CurrentItem->pDataC3->CurXPos ==
					(CurrentItem->pDataC3->XPos +
					CurrentItem->pDataC3->CharsInOne -
					CurrentItem->pDataC3->DgAftPnt)) //cursor is setted to point in value SXXX.X
					{
					CurrentItem->pDataC3->CurXPos--;//move cursor to next digit
					}
				}
				gotoxy(CurrentItem->pDataC3->CurXPos, 
					CurrentItem->pDataC3->YPos);
			 } //not first digit
		   } //changing DataC1
//____________________________________________________________________________________c3				   
	} //data is changing
//		 Draw(); //after Draw() cursor in last position
//		 gotoxy(CurrentItem->pDataC0->CurXPos, 
//				CurrentItem->pDataC0->YPos);
}
	   /*
extern "C" void Menu::OperateEnter()
{
	if(((CurrentItem->pDataP0 == NULL)  || (!CurrentItem->pDataP0->Changable)) && 
	   ((CurrentItem->pDataP1 == NULL)  || (!CurrentItem->pDataP1->Changable)) &&
	   ((CurrentItem->pDataP2 == NULL)  || (!CurrentItem->pDataP2->Changable)) &&
	   ((CurrentItem->pDataC0 == NULL)  || (!CurrentItem->pDataC0->Changable)) &&
       ((CurrentItem->pDataC1 == NULL)  || (!CurrentItem->pDataC1->Changable)) &&
       ((CurrentItem->pDataC2 == NULL)  || (!CurrentItem->pDataC2->Changable))

	   )//not have data
	{ 
	   printfp("Down");
		this->CurrentItem = this->CurrentItem->pItemDown;
	    if(!(this->CurrentItem->visibled))
		  {
			  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
			  while(!(this->CurrentItem->visibled));
		  }
	}
	else if(MenuState.DataChanging == 0) //have data, it are not changing now
	{
	   printfp("hier1");

	StartChanging();
	//need set cursor to first data and blink cursor
	}
	else //  MenuState.DataChanging = 1
	{
	   printfp("hier2");

	StopChanging();
	//need blink off 
	}
	Draw();
}

		*/
extern "C" void Menu::OperateEnter()
{

//printfp("\n\rOperateEnter");
//return; //t  

if(((CurrentItem->pDataP0 == NULL)  || (!CurrentItem->pDataP0->Changable)) && 
	   ((CurrentItem->pDataP1 == NULL)  || (!CurrentItem->pDataP1->Changable)) &&
	   ((CurrentItem->pDataP2 == NULL)  || (!CurrentItem->pDataP2->Changable)) &&
	   ((CurrentItem->pDataC0 == NULL)  || (!CurrentItem->pDataC0->Changable)) &&
       ((CurrentItem->pDataC1 == NULL)  || (!CurrentItem->pDataC1->Changable)) &&
       ((CurrentItem->pDataC2 == NULL)  || (!CurrentItem->pDataC2->Changable)) &&
       ((CurrentItem->pDataC3 == NULL)  || (!CurrentItem->pDataC3->Changable))

 	   )//not have data
	{ 
   /*  t1019
		this->CurrentItem = this->CurrentItem->pItemDown;
	    if(!(this->CurrentItem->visibled))
		  {
			  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
			  while(!(this->CurrentItem->visibled));
		  }
	*/
	   if(CurrentItem->pItemDown != NULL)	//t
	   {										  //t
	     CurrentItem = CurrentItem->pItemDown;	  //t
   /* temporary
	   	 if(!(this->CurrentItem->visibled))
		  {
			  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
			  while(!(this->CurrentItem->visibled));
		  }
	  */
	  
	   	    Draw();
	   }		  //t
  	  
 	}
	else if(MenuState.DataChanging == 0) //have data, it are not changing now
	{
	StartChanging();
	//need set cursor to first data and blink cursor
  // 	 Draw();
  	  CurrentItem->SetCursor();
	}
	else //  MenuState.DataChanging = 1
	{
	StopChanging();
 //	 Draw();
 // CurrentItem->SetCursor();	//this not make gotoxy(); data is now not changing!
	 gotoxy(1, 1);
	//need blink off 
	}
 //	Draw();
}

extern "C" void Menu::OperateEsc()
{
	if(MenuState.DataChanging == 0) //not have data or it are not changing now
	{
		   /*
				  this->CurrentItem = this->CurrentItem->pItemUp;
				  if(!(this->CurrentItem->visibled))
				  {
				  do {this->CurrentItem = this->CurrentItem->pItemLeft;}
				  while(!(this->CurrentItem->visibled));
				  }
			   */
		//	   visibled - later
		   if(CurrentItem->pItemUp != NULL)
		   {
			 CurrentItem = CurrentItem->pItemUp;
		   }


	}
	else//data are changing now
	{
		if(CurrentItem->pDataP0)
		{
	 	CurrentItem->pDataP0->ChangingValue = 
	 	CurrentItem->pDataP0->Value;
		}
		if(CurrentItem->pDataP1)
		{
	 	CurrentItem->pDataP1->ChangingValue = 
	 	CurrentItem->pDataP1->Value;
		}
		if(CurrentItem->pDataP2)
		{
	 	CurrentItem->pDataP2->ChangingValue = 
	 	CurrentItem->pDataP2->Value;
		}
		if(CurrentItem->pDataC0)
		{
	 	CurrentItem->pDataC0->ChangingValue = 
	 	CurrentItem->pDataC0->Value;
		}
		if(CurrentItem->pDataC1)
		{
	 	CurrentItem->pDataC1->ChangingValue = 
	 	CurrentItem->pDataC1->Value;
		}
		if(CurrentItem->pDataC2)
		{
	 	CurrentItem->pDataC2->ChangingValue = 
	 	CurrentItem->pDataC2->Value;
		}
		if(CurrentItem->pDataC3)
		{
	 	CurrentItem->pDataC3->ChangingValue = 
	 	CurrentItem->pDataC3->Value;
		}
 
	}		
	_setcursortype(0); //blink off
	MenuState.DataChanging = 0;	
	MenuState.DataP0Changing = 0;
	MenuState.DataP1Changing = 0;
	MenuState.DataP2Changing = 0;
	MenuState.DataC0Changing = 0;
 	MenuState.DataC1Changing = 0;
	MenuState.DataC2Changing = 0; 
	MenuState.DataC3Changing = 0;				  
  	Draw(); 
}

extern "C" void Menu::OperateUp()
{
	if(MenuState.DataChanging == 1) //have data, it are changing now
	{	
		if(MenuState.DataP0Changing == 1)//now changed DataP0
		{
			if((CurrentItem->pDataP0->ChangingValue + 1) ==
			CurrentItem->pDataP0->Quantity)
			{
			CurrentItem->pDataP0->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP0->ChangingValue++;
			}
		   CurrentItem->pDataP0->DrawMDataV();
		}
		else if(MenuState.DataP1Changing == 1)//now changed DataP1
		{
			if((CurrentItem->pDataP1->ChangingValue + 1) ==
			CurrentItem->pDataP1->Quantity)
			{
			CurrentItem->pDataP1->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP1->ChangingValue++;
			}
		    CurrentItem->pDataP1->DrawMDataV();

		}
		else if(MenuState.DataP2Changing == 1)//now changed DataP2
		{
			if((CurrentItem->pDataP2->ChangingValue + 1) ==
			CurrentItem->pDataP2->Quantity)
			{
			CurrentItem->pDataP2->ChangingValue = 0;
			}
			else
			{
			CurrentItem->pDataP2->ChangingValue++;
			}
		    CurrentItem->pDataP2->DrawMDataV();
  		}	
		else if(MenuState.DataC0Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC0->ChangingValue =
			CurrentItem->pDataC0->ChangingValue +
			CurrentItem->pDataC0->Delta(Up)*
			CurrentItem->pDataC0->Sign;
			CurrentItem->pDataC0->DrawMDataC(); //t
		}
 		else if(MenuState.DataC1Changing == 1)//now changed DataC1
		{	
			CurrentItem->pDataC1->ChangingValue =
			CurrentItem->pDataC1->ChangingValue +
			CurrentItem->pDataC1->Delta(Up)*
			CurrentItem->pDataC1->Sign;
		  	CurrentItem->pDataC1->DrawMDataC(); //t

		}
	   else if(MenuState.DataC2Changing == 1)//now changed DataC2
		{	
			CurrentItem->pDataC2->ChangingValue =
			CurrentItem->pDataC2->ChangingValue +
			CurrentItem->pDataC2->Delta(Up)*
			CurrentItem->pDataC2->Sign;
			CurrentItem->pDataC2->DrawMDataC();
		}
  		else if(MenuState.DataC3Changing == 1)//now changed DataC3
		{	
			CurrentItem->pDataC3->ChangingValue =
			CurrentItem->pDataC3->ChangingValue +
			CurrentItem->pDataC3->Delta(Up)*
			CurrentItem->pDataC3->Sign;
			CurrentItem->pDataC3->DrawMDataC();

		}
 
	}
	else //no Datachangind
	{
		if(CurrentItem->pDataS0 != NULL)
		{
		  CurrentItem->pDataS0->ModifyUp(CurrentItem->pDataS0->CntNum);
		}
		if(CurrentItem->pDataS1 != NULL)
		{
		  CurrentItem->pDataS1->ModifyUp(CurrentItem->pDataS1->CntNum);
		}
	}

 //t Draw();
  CurrentItem->SetCursor(); 
}

extern "C" void Menu::OperateDown()
{
	if(MenuState.DataChanging == 1) //have data, it are changing now
	{	
		if(MenuState.DataP0Changing == 1)//now changed DataP0
		{
			if(CurrentItem->pDataP0->ChangingValue == 0)
			{
			CurrentItem->pDataP0->ChangingValue = 
				(CurrentItem->pDataP0->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP0->ChangingValue--;
			}
		  CurrentItem->pDataP0->DrawMDataV();
		}
		else if(MenuState.DataP1Changing == 1)//now changed DataP1
		{
			if(CurrentItem->pDataP1->ChangingValue == 0)
			{
			CurrentItem->pDataP1->ChangingValue = 
				(CurrentItem->pDataP1->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP1->ChangingValue--;
			}
	    CurrentItem->pDataP1->DrawMDataV();
  		}
		else if(MenuState.DataP2Changing == 1)//now changed DataP2
		{
			if(CurrentItem->pDataP2->ChangingValue == 0)
			{
			CurrentItem->pDataP2->ChangingValue = 
				(CurrentItem->pDataP2->Quantity - 1);
			}
			else
			{
			CurrentItem->pDataP2->ChangingValue--;
			}
		  CurrentItem->pDataP2->DrawMDataV();
		}
		else if(MenuState.DataC0Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC0->ChangingValue =
			CurrentItem->pDataC0->ChangingValue -
			CurrentItem->pDataC0->Delta(Down)*
			CurrentItem->pDataC0->Sign;
			CurrentItem->pDataC0->DrawMDataC();

		}
		else if(MenuState.DataC1Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC1->ChangingValue =
			CurrentItem->pDataC1->ChangingValue -
			CurrentItem->pDataC1->Delta(Down)*
			CurrentItem->pDataC1->Sign;
			CurrentItem->pDataC1->DrawMDataC();
		}
		else if(MenuState.DataC2Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC2->ChangingValue =
			CurrentItem->pDataC2->ChangingValue -
			CurrentItem->pDataC2->Delta(Down)*
			CurrentItem->pDataC2->Sign;
			CurrentItem->pDataC2->DrawMDataC();
		}
     	else if(MenuState.DataC3Changing == 1)//now changed DataC0
		{	
			CurrentItem->pDataC3->ChangingValue =
			CurrentItem->pDataC3->ChangingValue -
			CurrentItem->pDataC3->Delta(Down)*
			CurrentItem->pDataC3->Sign;
			CurrentItem->pDataC3->DrawMDataC();
		}

	}
	else //no Datachangind
	{
		if(CurrentItem->pDataS0 != NULL)
		{
		  CurrentItem->pDataS0->ModifyDown(CurrentItem->pDataS0->CntNum);
		}
		if(CurrentItem->pDataS1 != NULL)
		{
		  CurrentItem->pDataS1->ModifyDown(CurrentItem->pDataS1->CntNum);
		}
	}
	
  //Draw(); 
   CurrentItem->SetCursor();
}

extern "C" void Menu::ServiceKey(unsigned char Key)
{

//not return; //t	
 //	switch(GetKey())
	switch(Key)
	{
	case None :   break;
	case Left :   OperateLeft();break;
	case Right:   OperateRight(); break;
	case Up   :   OperateUp(); break;
	case Down :	  OperateDown();break;	
	case Enter:  
#ifdef LOCK_ENABLED
//120911   SetBufferState((unsigned long)LOCK_MODE1);
//   ClearBufferState((unsigned long)LOCK_MODE2);
//   LockMode.Value = 1;
//   LockMode.ChangingValue = 1;
#ifdef PROG_PU_MSAT
   key_enter_flag = 1;
#endif

#ifdef PROG_MD310_SATI
   key_enter_flag = 1;

// printfp("\n\r key_enter_flag = 1");
#endif



#endif  	
	
	
				  OperateEnter(); break;
	case Esc  :   OperateEsc(); break;
	default	  :	  break;		
	}
	
}	

//________________________________________________<<<Menu
//________________________________________________>>>Pult

extern "C" void Pult::SendDataChar(unsigned char SChar)
{
/*
  while(State.T){} //wait  previons transmit finished
  PultCWr.bit.TI = 0;	  //enable transmit interrupt
  SendControlChar(PultCWr.all);
  SendChar = SChar;
  State.T = 1; //going transmit
*/
//_______________________________ // hier need disable irq2
//t _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR);  

 //t	if(TBufferCnt < (PultTBufferSize))
  //t	{
 //t	 *pTBuffer++ = SChar;
  //t	  TBufferCnt++;
  //t	  PultCWr.bit.TI = 1;	 //request transmit interrupt
  //t    SendControlChar(PultCWr.all);
#ifndef PULT_USART
	  write_xil_char(((uint_32)(PKU_ADDR)), (char) SChar);
#else	// PULT_USART
	  PultDelay();
  	  Transmit3c(SChar);
#endif	 //PULT_USART
 //t	}
 //t	else
  //t	{
//message to buffer overflow
 //t	}
//t _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
   	  //				      AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
  //t      				      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
  //t 					      AT91RM9200_AIC_SMR_PRIO_MIN );  

//________________________________

//  write_xil_char((uint_32)(PKU_ADDR), (char) SendChar);	 
//  PultCWr.bit.TI = 1;
//  SendControlChar(PultCWr.all);
  }

extern "C" void Pult::SendControlChar(unsigned char SendControl)
{
  write_xil_char(((uint_32)(PKU_ADDR) + 1), (char) SendControl);
}


extern "C" unsigned char Pult::GetDataChar()
{
// unsigned char GetData;
// GetData = (unsigned char)read_xil_char(PKU_ADDR);
#ifndef PULT_USART
 return (unsigned char)read_xil_char(PKU_ADDR);	
#else
 return GetKeyBuffer();
#endif
}

extern "C" unsigned char Pult::GetControlChar()
{
// unsigned char GetData;
// GetData = (unsigned char)read_xil_char(PKU_ADDR);
 return (unsigned char)read_xil_char((PKU_ADDR) + 1);	
}

 extern "C" void Pult::Init()	  //init this class
{
  PultCWr.all = 0;
  State.KeyPr = 0; //key not pressed
  State.CBlink = 0;
//  State.T = 0; //not coing transmit
  Key = None;
  CurAddr = 0x80; //first position in first line
  pTBuffer = &TBuffer[0];
  TBufferCnt = 0; //zero bytes in buffer
//  pcStr = &cStr[0];
//  pcStr2 = &cStr2[0];
//  pcStr3 = &cStr3[3]; //to zero
 // pcStr4 = &cStr4[0]; //to zero
//  pcStr5 = &cStr5[0]; //to zero
//  pcStr6 = &cStr6[4]; //to zero

//  cStr[0] = 0;
//  cStr2[0] = 0;
//  strcpy(cStr3, "UN");
 // strcpy(cStr6, "UCX0");

 // cStr4[0] = 0;
 // cStr5[0] = 0;

 uwIBuff = 0;
 urIBuff = 0;
 CntIBuff = 0;
 
 PultInts = 0;
}

extern "C" void PultDelay()
{
//t   delay_mcs(1000l);
   //t1201	   delay_mcs(100l);
  //ok delay_mcs(60l);	   //t1201
 //bad  delay_mcs(30l);
  //bad	delay_mcs(45l);
 // delay_mcs(50l);
  delay_mcs(60l);
}


extern "C" void Pult::gotoxy(Uint16 x, Uint16 y)
{
 unsigned char  type;
 //   PultCWr.bit.TI = 1;	   //enable transmit interrupt
 //  SendControlChar(PultCWr.all);
//  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR);
  //_____________________________________
#ifndef PULT_USART
	IBuff[uwIBuff++] = 'U';
	if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
	CntIBuff++;
	IBuff[uwIBuff++] = 'C';
	if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
	CntIBuff++;
	CurAddr = ((y == 2 ? 0xC0 : 0x80)) + (x - 1);
	IBuff[uwIBuff++] = CurAddr;
	if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
	CntIBuff++;
    type = (State.CBlink ? 2 : 0);  //2 - blink 0 - not blink	
 	IBuff[uwIBuff++] = type;
	if (uwIBuff >= IBUFFSIZE) {uwIBuff = 0;}
	CntIBuff++;
#else //  PULT_USART

 	  PultDelay();
	  Transmit3c('U');
	  PultDelay();
	  Transmit3c('C');
	  PultDelay();
	  CurAddr = ((y == 2 ? 0xC0 : 0x80)) + (x - 1);
	  Transmit3c(CurAddr);
	  PultDelay();
	  type = (State.CBlink ? 2 : 0);  //2 - blink 0 - not blink	
	  Transmit3c(type);
#endif	// PULT_USART

  //_____________________________________	
  /*
    PultDelay();
   SendDataChar('U');
   PultDelay();
   SendDataChar('C');
   PultDelay();
   CurAddr = ((y == 2 ? 0xC0 : 0x80)) + (x - 1);
   SendDataChar(CurAddr);
   PultDelay();
   type = (State.CBlink ? 2 : 0);  //2 - blink 0 - not blink	
   SendDataChar(type);
   PultDelay();
	*/
  // PultCWr.bit.TI = 0;	   //disable transmit interrupt
 //  SendControlChar(PultCWr.all);	
//   PultDelay();
  //	  _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
         // 			       AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
                 //	         AT91RM9200_AIC_SMR_PRIO_MIN );  
			

}

extern "C" void Pult::ReplaceChar(unsigned char RepChar)
{
 // _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR);
 
   SendDataChar('U');
   PultDelay();
   SendDataChar('U');
   PultDelay();
   SendDataChar('O');
    PultDelay();
   SendDataChar(1);	  //one symbol
    PultDelay();
   SendDataChar(CurAddr++);	//move cursor to next symbol
     PultDelay();
   SendDataChar(RepChar);
     PultDelay();
 //  _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
 //         			       AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
  //              	         AT91RM9200_AIC_SMR_PRIO_MIN );  
}

extern "C" void Pult::OperateLed(unsigned char Operation, unsigned char Led)
{	    
		PultDelay();
	    ToIBuf('U');
		PultDelay();
		ToIBuf('L');
		PultDelay();
		ToIBuf(((Operation << 4) + Led));
		PultDelay();
#ifndef PULT_USART
       UsedPult.PultCWr.bit.TI = 1;	   //get on transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
#endif

}

extern "C" unsigned char Pult::GetKey()
 {
	   if(UsedExp.State.Reg1.bit.Frozen)
	  {
	   UsedExp.State.Reg1.bit.Frozen  = 0; //unfrozen display
	   State.KeyPr = 0; //this key is readed to menu
	   UsedExp.State.Reg2.bit.Draw  = 1;
	   UsedExp.State.Reg2.bit.Some  = 1;
 	   return None;
	  }


     State.KeyPr = 0; //this key is readed to menu
	 UsedExp.State.Reg1.bit.Frozen  = 0; //unfrozen display
	 


 	switch(Key)
	{
	   case 0x31 :   return	Esc; 
	   case 0x32 :   return Up;
	   case 0x33 :   return Enter;
	 //  case 33 : return 0; //enter

	   case 0x34 :   return Left;
	   case 0x35 :   return Down;
	   case 0x36 :   return Right;
	   default : return None;
	}
  }

 extern "C" void Pult::InitDevise()
{
#ifndef PULT_USART
//  PultCWr.all = 0;	  //maked in init class
  PultCWr.bit.ResPku = 1;  //reset pult
  PultCWr.bit.SyncFifo = 1;
  SendControlChar(PultCWr.all);	
  delay_mcs(1000l);	  //delay 1 ms
  PultCWr.bit.ResPku = 0;
  PultCWr.bit.SyncFifo = 0;
  SendControlChar(PultCWr.all);	
  PultCWr.bit.TEn = 1;	   //enable transmit
  PultCWr.bit.REn = 1;	   //enable receive
  SendControlChar(PultCWr.all);	
  delay_mcs(40000l);  //delay 40 ms
//  PultCWr.bit.TI = 1;	   //enable transmit interrupt
  PultCWr.bit.TI = 0;	   //enable transmit interrupt
  PultCWr.bit.RI = 1;	   //enable receive interrupt
  SendControlChar(PultCWr.all);	
  SendDataChar(0x55);
#else // PULT_USART
 InitKeyBuffer();
 for(long i = 0; i < 26; i++)
 {
  Transmit3c(0x55); //reset
  PultDelay();
 }
#endif // PULT_USART
}
//_____________________________________________________
extern "C" void MDataS::MakeResultStrS()
{	
  //	sprintf(pResultStr, pFormat, Value);
    char Buff[25];
  //	char* pBuff;
  //	pBuff = &Buff[0]; 
  	strcpy(&Buff[0], &Value[0]);
  //		strcpy(pResultStr, &Value[0]);

  	Buff[24] = 0;
  	sprintf(pResultStr,"%s", Buff);
  //	ResultStr[22] = 0;
}



#ifdef YOURNAL


extern "C" unsigned char EventToMenu1() 	  //without draw
{
//char Buff[25];
	static str0cnt;
//t	sprintf(LogStr0.Value,"%d", str0cnt);
#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

//printfpd("\n\rview_counter : %d ", view_counter);

#endif
	GetRecord1(view_counter);	 //temporary only for zero event  
	if(!(CheckEventCRC((unsigned char*) CRecord.Value))) 
	{

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfp("\n\rcrc of event is wrong ");

#endif

     	 return 0;
	}

 unsigned short	ev_number = (unsigned short)(CRecord.Value[0] << 8)
 + (unsigned short)CRecord.Value[1];

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

//printfpd("\n\r ev_number %d", ev_number);

#endif


 unsigned short	 event = (unsigned short)CRecord.Value[6];


#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

//printfpd("\n\r event %d", event);

#endif

//____________________________________________
  time.SECONDS = (unsigned short)CRecord.Value[2];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[3];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[4];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[5];
  time.MILLISECONDS = 0;
  _time_to_date(&time, &date);

//sprintf(LogStr0.Value, "%2d %3d %02d:%02d:%02d %02d/%02d/%02ld ",view_counter,  ev_number,date.HOUR,date.MINUTE,date.SECOND, date.DAY, date.MONTH, (date.YEAR%100) );
sprintf(LogStr0.Value, "%4d %02d:%02d:%02d %02d/%02d/%02ld ", ev_number,date.HOUR,date.MINUTE,date.SECOND, date.DAY, date.MONTH, (date.YEAR%100) );

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

//printfp(LogStr0.Value);

#endif

//LogStr0.DrawMDataS();

switch(event)
{
case 0: sprintf(LogStr1.Value, "%s","Current Time");  break;
case 1: sprintf(LogStr1.Value, "%s","Power On    ");  break;
case 2: sprintf(LogStr1.Value, "%s","Power Off   ");  break;
case 3: sprintf(LogStr1.Value, "%s","Command     ");  break;
case 4: sprintf(LogStr1.Value, "%s","Lock        ");  break;
case 5: sprintf(LogStr1.Value, "%s","Lock Off    ");  break;
case 6: sprintf(LogStr1.Value, "%s","Alarm       ");  break;
case 7: sprintf(LogStr1.Value, "%s","Alarm Off   ");  break;
case 8: sprintf(LogStr1.Value, "%s","Load  Config");  break;
case 9: sprintf(LogStr1.Value, 	"%s","Keep State  ");  break;
case 10: sprintf(LogStr1.Value, "%s","Change Config");  break;
case 11: sprintf(LogStr1.Value, "%s","My Command Config");  break;
case 12: sprintf(LogStr1.Value, "%s","Uplink Available");  break;
case 13: sprintf(LogStr1.Value, "%s","Uplink Lost");  break;
case 14: sprintf(LogStr1.Value, "%s","Downlink Available");  break;
case 15: sprintf(LogStr1.Value, "%s","Downlink Lost");  break;


default :sprintf(LogStr1.Value, "%7d     ",event);  break;	
}
//LogStr1.DrawMDataS();

 /*
#define	EV_COMMAND_CONFIG		 (10)
#define	EV_MY_COMMAND_CONFIG	 (11)
#define	EV_UPLINK_AVAILABLE		 (12)
#define	EV_UPLINK_LOST			 (13)
#define	EV_DOWNLINK_AVAILABLE	 (14)
#define	EV_DOWNLINK_LOST		 (15)
 */

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif
//printfp("\n\r<str0______________________________________str1>\n\r");
//printfp(LogStr1.Value);

#endif


//____________________________________________


  // view_counter++;
 //  str0cnt++;
 return 1;
}


extern "C" unsigned char EventToMenu() 
{
//char Buff[25];
	static str0cnt;
#ifdef PROG_MD310_SATI
oldflag_alarms = 2;
#endif
//t	sprintf(LogStr0.Value,"%d", str0cnt);
#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfpd("\n\rview_counter : %d ", view_counter);

#endif
	GetRecord1(view_counter);	 //temporary only for zero event  
	if(!(CheckEventCRC((unsigned char*) CRecord.Value))) 
	{

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfp("\n\rcrc of event is wrong ");

#endif

     	 return 0;
	}

 unsigned short	ev_number = (unsigned short)(CRecord.Value[0] << 8)
 + (unsigned short)CRecord.Value[1];

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfpd("\n\r ev_number %d", ev_number);

#endif


 unsigned short	 event = (unsigned short)CRecord.Value[6];


#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfpd("\n\r event %d", event);

#endif

//____________________________________________
  time.SECONDS = (unsigned short)CRecord.Value[2];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[3];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[4];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[5];
  time.MILLISECONDS = 0;
  _time_to_date(&time, &date);

//sprintf(LogStr0.Value, "%2d %3d %02d:%02d:%02d %02d/%02d/%02ld ",view_counter,  ev_number,date.HOUR,date.MINUTE,date.SECOND, date.DAY, date.MONTH, (date.YEAR%100) );
sprintf(LogStr0.Value, "%4d %02d:%02d:%02d %02d/%02d/%02ld ", ev_number,date.HOUR,date.MINUTE,date.SECOND, date.DAY, date.MONTH, (date.YEAR%100) );

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif

printfp(LogStr0.Value);

#endif

LogStr0.DrawMDataS();

switch(event)
{
case 0: sprintf(LogStr1.Value, "%s","Current Time            ");  break;
case 1: sprintf(LogStr1.Value, "%s","Power On                ");  break;
case 2: sprintf(LogStr1.Value, "%s","Power Off               ");  break;
case 3: sprintf(LogStr1.Value, "%s","Command                 ");  break;
case 4: sprintf(LogStr1.Value, "%s","Lock                    ");  break;
case 5: sprintf(LogStr1.Value, "%s","Lock Off                ");  break;
case 6: sprintf(LogStr1.Value, "%s","Alarm                   ");  break;
case 7: sprintf(LogStr1.Value, "%s","Alarm Off               ");  break;
//case 8: sprintf(LogStr1.Value, "%s","Load  Config            ");  break;
case 8: sprintf(LogStr1.Value, "%s%c%c%c","Load  Configs T & R  ", CRecord.Value[8],CRecord.Value[9],CRecord.Value[10]); break;

case 9: sprintf(LogStr1.Value, 	"%s","Keep State             ");  break;
case 10: sprintf(LogStr1.Value, "%s","Change Config          ");  break;
case 11: sprintf(LogStr1.Value, "%s","My Command Config      ");  break;
case 12: sprintf(LogStr1.Value, "%s","Uplink Available       ");  break;
case 13: sprintf(LogStr1.Value, "%s","Uplink Lost            ");  break;
case 14: sprintf(LogStr1.Value, "%s","Downlink Available     ");  break;
case 15: sprintf(LogStr1.Value, "%s","Downlink Lost          ");  break;
case 16: sprintf(LogStr1.Value, "%s",    "PVG610 Alarm           ");  break;
case 17: sprintf(LogStr1.Value, "%s%c%c","ACM T UP             ", CRecord.Value[8],CRecord.Value[9]);  break;
case 18: sprintf(LogStr1.Value, "%s%c%c","ACM T DOWN           ", CRecord.Value[8],CRecord.Value[9]);  break;
case 19: sprintf(LogStr1.Value, "%s%c%c","ACM R UP             ", CRecord.Value[8],CRecord.Value[9]);  break;
case 20: sprintf(LogStr1.Value, "%s%c%c","ACM R DOWN           ", CRecord.Value[8],CRecord.Value[9]);  break;
case 21: sprintf(LogStr1.Value, "%s%c%c%c","Load  Config  R      ", CRecord.Value[8],CRecord.Value[9],CRecord.Value[10]); break;
case 22: sprintf(LogStr1.Value, "%s%c%c%c","Load  Config  T      ", CRecord.Value[8],CRecord.Value[9],CRecord.Value[10]); break;



//#define	EV_ACM_T_UP			 	 (17)
//#define	EV_ACM_T_D 			 	 (18)
//#define	EV_ACM_R_UP			 	 (19)
//#define	EV_ACM_R_D 			 	 (20)


default :sprintf(LogStr1.Value, "%7d     ",event);  break;	
}
LogStr1.DrawMDataS();

 /*
#define	EV_COMMAND_CONFIG		 (10)
#define	EV_MY_COMMAND_CONFIG	 (11)
#define	EV_UPLINK_AVAILABLE		 (12)
#define	EV_UPLINK_LOST			 (13)
#define	EV_DOWNLINK_AVAILABLE	 (14)
#define	EV_DOWNLINK_LOST		 (15)
 */

#ifdef DEB_LOG
//printfp("\n\rModifyStr0Down %d");
//#endif
printfp("\n\r<str0______________________________________str1>\n\r");
printfp(LogStr1.Value);

#endif


//____________________________________________


  // view_counter++;
 //  str0cnt++;
 return 1;
}


extern "C" void PrintYournal()
{

for(unsigned long i = 1; i < RECORDS_MAX_QUANTITY; i++)
{
  view_counter = i;
  if(EventToMenu())
  {
  printfp("\n\r");
  printfp(LogStr0.Value);
  printfp(LogStr1.Value);
  }
  else
  {
 // break;
  }
}
  view_counter = 1;
}







extern "C" void ModifyStr0Up() 
{
//char Buff[25];

#ifdef DEB_LOG
printfp("\n\rModifyStr0Up %d");
#endif


	static str0cnt;
	/*
//t	sprintf(LogStr0.Value,"%d", str0cnt);
	GetRecord1(view_counter);	 //temporary only for zero event  
 unsigned short	ev_number = (unsigned short)(CRecord.Value[0] << 8)
 + (unsigned short)CRecord.Value[1];
 unsigned short	 event = (unsigned short)CRecord.Value[6];
//____________________________________________
  time.SECONDS = (unsigned short)CRecord.Value[2];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[3];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[4];
  time.SECONDS <<= 8;
  time.SECONDS += (unsigned short)CRecord.Value[5];
  time.MILLISECONDS = 0;
  _time_to_date(&time, &date);

sprintf(LogStr0.Value, "%02d %3d %02d:%02d:%02d %02d/%02d/%02ld ",(0),  ev_number,date.HOUR,date.MINUTE,date.SECOND, date.DAY, date.MONTH, (date.YEAR%100) );

switch(event)
{
case 0: sprintf(LogStr1.Value, "%s","Current Time");  break;
case 1: sprintf(LogStr1.Value, "%s","Power On    ");  break;
case 2: sprintf(LogStr1.Value, "%s","Power Off   ");  break;
case 3: sprintf(LogStr1.Value, "%s","Command     ");  break;
case 4: sprintf(LogStr1.Value, "%s","Lock        ");  break;
case 5: sprintf(LogStr1.Value, "%s","Lock Off    ");  break;
case 6: sprintf(LogStr1.Value, "%s","Alarm       ");  break;
case 7: sprintf(LogStr1.Value, "%s","Alarm Off   ");  break;
case 8: sprintf(LogStr1.Value, "%s","Load  Config");  break;
case 9: sprintf(LogStr1.Value, 	"%s","Keep State  ");  break;
case 10: sprintf(LogStr1.Value, "%s","Change Config");  break;
case 11: sprintf(LogStr1.Value, "%s","My Command Config");  break;
case 12: sprintf(LogStr1.Value, "%s","Uplink Available");  break;
case 13: sprintf(LogStr1.Value, "%s","Uplink Lost");  break;
case 14: sprintf(LogStr1.Value, "%s","Downlink Available");  break;
case 15: sprintf(LogStr1.Value, "%s","Downlink Lost");  break;


default :sprintf(LogStr1.Value, "%7d     ",event);  break;	
}
*/
 /*
#define	EV_COMMAND_CONFIG		 (10)
#define	EV_MY_COMMAND_CONFIG	 (11)
#define	EV_UPLINK_AVAILABLE		 (12)
#define	EV_UPLINK_LOST			 (13)
#define	EV_DOWNLINK_AVAILABLE	 (14)
#define	EV_DOWNLINK_LOST		 (15)
 */

//____________________________________________

 if(view_counter > 1) view_counter--;


 if(!EventToMenu())
 {

 if(view_counter < RECORDS_MAX_QUANTITY) view_counter++;
 }
 // EventToMenu();

//   if(view_counter < RECORDS_MAX_QUANTITY) view_counter++;

// if(view_counter > 1) view_counter--;

 //  str0cnt++;
}

extern "C" void ModifyStr1Up() 
{
//static str1cnt;
 //	sprintf(LogStr1.Value,"%d", str1cnt);

  // str1cnt++;
}




#endif//


extern "C" void MDataS::ModifyUp(unsigned long num) 
{
#ifdef DEB_LOG
printfpd("\n\rModifyUp %d", num);
#endif
	
  //	sprintf(pResultStr, pFormat, Value);
    char Buff[25];
  //	char* pBuff;
  //	pBuff = &Buff[0]; 

 switch(num)
 {
  case 0:
  	strcpy(&Buff[0], &Value[0]);
  //		strcpy(pResultStr, &Value[0]);

  	Buff[24] = 0;
  	sprintf(pResultStr,"%s", Buff);
  //	ResultStr[22] = 0;
	break;
   case 1:    break;
   case 167:
#ifdef YOURNAL
	ModifyStr0Up();
#endif//
  
       break;
   case 168:   
#ifdef YOURNAL
	ModifyStr1Up();
#endif//
  
    break;




   default : break;
 }


}


extern "C" void ModifyStr0Down() 
{
#ifdef DEB_LOG
printfp("\n\rModifyStr0Down %d");
#endif



 // if(view_counter) view_counter--;
#ifdef YOURNAL
 //  if(view_counter < RECORDS_MAX_QUANTITY) view_counter++;
//#endif
 //  EventToMenu();

if(view_counter < RECORDS_MAX_QUANTITY) view_counter++;

    if(!EventToMenu())
  {
    if(view_counter > 1) view_counter--;
  }
#endif
  
 
}
extern "C" void ModifyStr1Down() 
{


}



extern "C" void MDataS::ModifyDown(unsigned long num) 
{

#ifdef DEB_LOG
printfpd("\n\rModifyDown %d", num);
#endif
	
  //	sprintf(pResultStr, pFormat, Value);
    char Buff[25];
  //	char* pBuff;
  //	pBuff = &Buff[0]; 

 switch(num)
 {
  case 0:
  	strcpy(&Buff[0], &Value[0]);
  //		strcpy(pResultStr, &Value[0]);

  	Buff[24] = 0;
  	sprintf(pResultStr,"%s", Buff);
  //	ResultStr[22] = 0;
	break;
   case 1:    break;
   case 167:
#ifdef YOURNAL
	ModifyStr0Down();
#endif//
  
       break;
   case 168:   
#ifdef YOURNAL
	ModifyStr1Down();
#endif//
  
    break;




   default : break;
 }


}




extern "C" void MDataS::DrawMDataS()
{

#ifdef DEB_LOG
printfp("\n\rDrawMDataS");
#endif
	
#ifdef USE_PULT

 	MakeResultStrS();
 	gotoxy(XPos, YPos);
  	cprintf(theAnyStrings.cs, pResultStr);
 // cprintf("%22s", Value);
#endif	//USE_PULT
}


//________________________________________________<<<Pult
//________________________________________________>>>MDataS
/*
extern "C" void MDataS::FillValue(void)
{
 // printf("\n\r FillValue");
switch(CntNum) //use hier cnt num as control
{
#ifdef YOURNAL
//printf("\n\r record");

   case 56 : GetRecord(); break;
#endif // YOURNAL


	default: break;
}

}

*/

extern "C" char MDataS::RunRemoteS(char * pCommand)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuff, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff++;
		}
  //		Uint32 tmp = Value;
 //		sprintf(pTBuff, pRemFormat, tmp);

//1		sprintf(pTBuff, pRemFormat, &Value[0]);
//1		for(i = RemChars; i > 0; i--)
//1		{
//1	        	pTBuff++;
//1		}
   //			FillValue();
			for(i = 0; i< RemChars; i++)
			{
  //	        	*pTBuff++ = Value[i];
			if(CntNum)
			{
  	  		 if(Value[i])
			 {
			  *pTBuff++ = Value[i];
			 }
			 else
			 {
		   	  break;
			 }
			}
			else
			{
			 //   Transmit();		  //t
			//    fputc(Value[i], fusart1_ptr); 	 //t

			  *pTBuff++ = Value[i];
			}
   
 			}

		
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
   //					tmpl = (float64)strtoll(pCommand, &end, SysS);
			 tmpl = (float64)strcspn(pCommand, ":");
			 if(pControl->Control(CntNum, tmpl))
			 {
//hier write from remote to value
  //--->			 ChangingValue =  tmpl;
  //	    sprintf(&Value[0], pRemFormat, pTBuff);
   //	    sprintf(&ChangingValue[0], pRemFormat, pTBuff);
		 for(i = 0; i < RemChars; i++)
			{
	       //  ChangingValue[i] = *pCommand;
      		 Value[i] = *pCommand++;
   			}
   //--->			 Value =  tmpl;
  //			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //bad command
			 {
   		 	 //     	 UsedMenu.DrawMessage("Error","In Address");
			    Ring(1,1,5,2);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff++;
		}
		}
		strcpy(pTBuff++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataS::RunRemoteS0(char * pCommand)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
	   	pTBuff0_control(strlen(pRemote));

		strcpy(pTBuff0, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff0++;
		}
  //		Uint32 tmp = Value;
 //		sprintf(pTBuff, pRemFormat, tmp);
	//	sprintf(pTBuff0, pRemFormat, &Value[0]);	//hier can get off if in pTBuff nothave  zero!
 	//	for(i = RemChars; i > 0; i--)
	//	{
	//	pTBuff0++;
	//	}
		pTBuff0_control(RemChars);
	   if(!CntNum)
			{
		  	 *pTBuff0 = '\0';  //test
		   	    Transmit0();   //test
		    }	

		for(i = 0; i< RemChars; i++)
			{
	  //		  *pTBuff0++ = Value[i];
	 	 if(CntNum)
			{
			 if(Value[i])
			 {
			  *pTBuff0++ = Value[i];
			 }
			 else
			 {
		   	  break;
			  }
			}
			else
			{
		 //  	 *pTBuff0 = '\0';
		  // 	    Transmit0();		  //t
		 //  	    fputc(Value[i], fusart0_ptr); 	 //t
		  // 	    fputc(Value[i], fusart0_ptr); 	 //t
		   /*	   121017
 #ifndef USART0_TRY_PDC_1T
         fputc(Value[i], fusart0_ptr); 
#else
         ToPdcTu0(Value[i]);

#endif   

		  */

			 //	  fputc('7', fusart0_ptr); 

		  	 *pTBuff0++ = Value[i];	 //121017
			}

	
		   
		   } //for...
				
		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   		tmpl = (float64)strcspn(pCommand, ":");
   //					tmpl = (float64)strtoll(pCommand, &end, SysS);

			 if(pControl->Control(CntNum, tmpl))
			 {
//hier write from remote to value
  //--->			 ChangingValue =  tmpl;
       //    printfp("\n\rcontrol ok");
	   for(i = 0; i < RemChars; i++)
			{
	     //  ChangingValue[i] = *pCommand;
      		 Value[i] = *pCommand++;
   			}


  //--->			 Value =  tmpl;
  //			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //bad command
			 {
			//   	 UsedMenu.DrawMessage("Error","In Address");
					  Ring(1,1,5,2);
  // 		 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);
  		pTBuff0_control(strlen(theAnyStrings.cK0));
		
		strcpy(pTBuff0, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff0++;
		}
		}
		pTBuff0_control(strlen(theAnyStrings.cRazd));

		strcpy(pTBuff0++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataS::RunRemoteS3(char * pCommand)
{

//printfp("RunRemoteS3"); //8times
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
  //		  printfp("request");

		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff3++;
		}
  //		Uint32 tmp = Value;
 //		sprintf(pTBuff, pRemFormat, tmp);
	//	sprintf(pTBuff0, pRemFormat, &Value[0]);	//hier can get off if in pTBuff nothave  zero!
 	//	for(i = RemChars; i > 0; i--)
	//	{
	//	pTBuff0++;
	//	}

	//	  printfpd("_%d", RemChars);

//_________________________________

		for(i = 0; i< RemChars; i++)
			{
	  //		   printfp("RemChars");

	     //  	*pTBuff3++ = Value[i];
	  //	   printfpd(" %d ", Value[i]);

		  if(CntNum)
		   {
		
				 if(Value[i])
			 {
			  *pTBuff3++ = Value[i];
		   //	  printfpd("%c", Value[i]);
		//		 printfp("add");

			 }
			 else
			 {
	   //		    printfp("break");
	   //		    printfpd("%d", i);

	   		  break;
			 }

			}
			else
			{
	   //		 printfp("no cntnum");
			   *pTBuff3++ = Value[i];
			}
	   
			}
 		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
   //					tmpl = (float64)strtoll(pCommand, &end, SysS);
			 tmpl = (float64)strcspn(pCommand, ":");
			 if(pControl->Control(CntNum, tmpl))
			 {
//hier write from remote to value
  //--->			 ChangingValue =  tmpl;
	   for(i = 0; i < RemChars; i++)
			{
	        //  ChangingValue[i] = *pCommand;
      		 Value[i] = *pCommand++;
   			}
   //--->			 Value =  tmpl;
  //			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
  // 		 UsedMenu.DrawMessage(pMes0,pMes1);
 //			  UsedMenu.DrawMessage("Error","In Address");
			   Ring(1,1,5,2);
  			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff3++;
		}
		}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" char MDataS::RunRemoteSS(char * pCommand)
{
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
		strcpy(pTBuffS, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuffS++;
		}
  //		Uint32 tmp = Value;
 //		sprintf(pTBuff, pRemFormat, tmp);
 //		sprintf(pTBuffS, pRemFormat, &Value[0]);	//hier can get off if in pTBuff nothave  zero!
// 		for(i = RemChars; i > 0; i--)
//		{
//		pTBuffS++;
//		}
		for(i = 0; i< RemChars; i++)
			{
	     //   	*pTBuffS++ = Value[i];
		  if(CntNum)
			{
			  if(Value[i])
			 {
			  *pTBuffS++ = Value[i];
			 }
			 else
			 {
			  break;
			 }
		    }
			else
			{
			   *pTBuffS++ = Value[i];
			}
			 
 			}
	//t071211	  len = 2; // 2; //fill buffer from 3-element (first two are len + 0x8000)
	//t071211	  Value[0] = 2; //only len have correct
	//t071211	  Value[1] = 0x80;
	//t071211	  Value[2] = '\0'; //to not get old values to answer
 		}
	   		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
   //					tmpl = (float64)strtoll(pCommand, &end, SysS);
			 if(pControl->Control(CntNum, tmpl))
			 {
//hier write from remote to value
  //--->			 ChangingValue =  tmpl;
        //   len = 0;
			 	    for(i = 0; i < RemChars; i++)
			{
	        //  ChangingValue[i] = *pCommand;
      		 Value[i] = *pCommand++;
		   //	 len ++;
   			}
			    len =	 RemChars;

  //--->			 Value =  tmpl;
  //			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
  // 		 UsedMenu.DrawMessage(pMes0,pMes1);
			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuffS, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuffS++;
		}
		}
		strcpy(pTBuffS++, theAnyStrings.cRazd);	
	}
	return ret;
}


extern "C" MDataS::Init(char * pSetFormat, 
                        char SetXPos,
                         char SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                         char SetCharsInOne,
                         CntFunc * SetpControl,
                        Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                       char* SetpRemote
                     ,char * SetpRemFormat, 
                     char SetRemChars
                        ,char SetRemNum 
                        ,Uint16 Setlen                    
                         )
{
 //float64* pSetValue; 
 //pSetValue = &SetValue;
 pFormat = pSetFormat;
 XPos = SetXPos;
 //CurXPos = SetXPos; 
 YPos = SetYPos;
 len = Setlen;
// Changable = SetChangable;
// StorageAddr = SetStorageAddr;
// Value = 0l;
// ChangingValue = 0l;
// if(GetKey() != Enter)//temporary Esc, need Enter
 // if( UsedPult.Key	!= Enter)
// {
//???? may be *psetvalue?  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?

 // 	pSetValue = ReadStorageC(SetStorageAddr);
// }
//  Value += *pSetValue;//t
// Value = SetValue; //to test temporary without storage
 // ChangingValue += *pSetValue;
 //ChangingValue = SetValue; //to test temporary without storage

//need control 
 //if(!(theCntFunc.Control(SetCntNum, Value))) //bad value in storage
// {
 //	 pSetValue = &SetValue;
 //	 Value = 0l;
// 	 ChangingValue = 0l;
 //	 Value += *pSetValue;//t
 //	 ChangingValue += *pSetValue;
//  	 WriteStorageC(SetStorageAddr,Value);
 //}
 for(int i = 0; i < SetRemChars; i++)
 {
 Value[i] = 0;
 //ChangingValue[i] = 0;
 }

 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 //pMes0 = SetpMes0;
 //pMes1 = SetpMes1;
 //DgAftPnt = SetDgAftPnt;
 //HexOrDec = SetHexOrDec;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;
 RemChars = SetRemChars; 
 RemNum = SetRemNum;
}


//________________________________________________<<<MDataS

extern "C" char MDataSB::RunRemoteSB3(char * pCommand)
{

//printfp("RunRemoteS3"); //8times
float64 tmpl;
char Buf[32];
char * end;
end = &Buf[0];
char ret = 0;
	if(strstr(pCommand, pRemote) == pCommand) // command or request
  //	if(1) // for test
		{
   //		UsedRemote.IdCommand = 1; //right command
	//    IdCommand = 1; //right command
	    ret = 1;
		if(strlen(pCommand) == strlen(pRemote)) //request
		{
  //		  printfp("request");

		strcpy(pTBuff3, pRemote); //add to  transmit buffer command
		for(int16 i = strlen(pRemote); i > 0; i--)
		{
	//	UsedRemote.pTBuff++;
		pTBuff3++;
		}
  //		Uint32 tmp = Value;
 //		sprintf(pTBuff, pRemFormat, tmp);
	//	sprintf(pTBuff0, pRemFormat, &Value[0]);	//hier can get off if in pTBuff nothave  zero!
 	//	for(i = RemChars; i > 0; i--)
	//	{
	//	pTBuff0++;
	//	}

	 //	  printfpd("\n\r RemChars1 %d", RemChars1);

//_________________________________

		for(i = 0; i< RemChars1; i++)
			{
	  //		   printfp("RemChars");

	     //  	*pTBuff3++ = Value[i];
	  //	   printfpd(" %d ", Value[i]);

		  if(CntNum)
		   {
		
				 if(Value[i])
			 {
			  *pTBuff3++ = Value[i];
		 //  	  printfpd("%c", Value[i]);
		//		 printfp("add");

			 }
			 else
			 {
	   	  //	    printfp("break ");
	   	  //	    printfpd("%d", i);

	   		  break;
			 }

			}
			else
			{
	   		 printfp("\n\r no cntnum");
			   *pTBuff3++ = Value[i];
			}
	   
			}
 		}
		else //command
		{
  		for(int16 i = strlen(pRemote); i > 0; i--)
		{
		pCommand++; //to get only  content of command
		}
   //		tmpl = (float64)strtol(pCommand, &end, SysS);
   //					tmpl = (float64)strtoll(pCommand, &end, SysS);
			 tmpl = (float64)strcspn(pCommand, ":");
			 if(pControl->Control(CntNum, tmpl))
			 {
//hier write from remote to value
  //--->			 ChangingValue =  tmpl;
	   for(i = 0; i < RemChars; i++)
			{
	        //  ChangingValue[i] = *pCommand;
      		 Value[i] = *pCommand++;
   			}
   //--->			 Value =  tmpl;
  //			 WriteStorageC(StorageAddr,Value);
			 pControl->Operate(OprNum);
			 UsedExp.State.Reg2.bit.Draw = 1;
			 UsedExp.State.Reg2.bit.Some = 1;
			 }
			 else //command
			 {
  // 		 UsedMenu.DrawMessage(pMes0,pMes1);
 //			  UsedMenu.DrawMessage("Error","In Address");
			   Ring(1,1,5,2);
  			 }
  		pControl->Remote(RemNum, pCommand, CntNum);		
		strcpy(pTBuff3, theAnyStrings.cK0); //add"K0"
		for(i = strlen(theAnyStrings.cK0); i > 0; i--)
		{
		pTBuff3++;
		}
		}
		strcpy(pTBuff3++, theAnyStrings.cRazd);	
	}
	return ret;
}

extern "C" MDataSB::Init(char * pSetFormat, 
                        char SetXPos,
                         char SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                         char SetCharsInOne,
                         CntFunc * SetpControl,
                        Uint16 SetCntNum,
                        Uint16 SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                       char* SetpRemote
                     ,char * SetpRemFormat, 
                 //    char SetRemChars
				     unsigned long SetRemChars1
                        ,char SetRemNum 
                        ,Uint16 Setlen                    
                         )
{
 //float64* pSetValue; 
 //pSetValue = &SetValue;
 pFormat = pSetFormat;
 XPos = SetXPos;
 //CurXPos = SetXPos; 
 YPos = SetYPos;
 len = Setlen;
// Changable = SetChangable;
// StorageAddr = SetStorageAddr;
// Value = 0l;
// ChangingValue = 0l;
// if(GetKey() != Enter)//temporary Esc, need Enter
 // if( UsedPult.Key	!= Enter)
// {
//???? may be *psetvalue?  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!?

 // 	pSetValue = ReadStorageC(SetStorageAddr);
// }
//  Value += *pSetValue;//t
// Value = SetValue; //to test temporary without storage
 // ChangingValue += *pSetValue;
 //ChangingValue = SetValue; //to test temporary without storage

//need control 
 //if(!(theCntFunc.Control(SetCntNum, Value))) //bad value in storage
// {
 //	 pSetValue = &SetValue;
 //	 Value = 0l;
// 	 ChangingValue = 0l;
 //	 Value += *pSetValue;//t
 //	 ChangingValue += *pSetValue;
//  	 WriteStorageC(SetStorageAddr,Value);
 //}
 for(int i = 0; i < SetRemChars1; i++)
 {
 Value[i] = 0;
 //ChangingValue[i] = 0;
 }

 CharsInOne = SetCharsInOne; //quantity of visible symbols
 pResultStr = &ResultStr[0];
 do{pResultStr++; CharsInOne--;} while(CharsInOne);
 *pResultStr = '\0';	//write zero to end ResultStr - one non -visible symbol	
 CharsInOne = SetCharsInOne; //init
 pResultStr = &ResultStr[0]; //set to start
 pControl = SetpControl;
 CntNum = SetCntNum;
 OprNum = SetOprNum;
 //pMes0 = SetpMes0;
 //pMes1 = SetpMes1;
 //DgAftPnt = SetDgAftPnt;
 //HexOrDec = SetHexOrDec;
 pRemote = SetpRemote;
 pRemFormat = SetpRemFormat;

 //RemChars = SetRemChars; 	 //this is char max value = 255
 RemChars1 = SetRemChars1; 	  //maked as unsigned long
 RemNum = SetRemNum;
}



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : dev _restart
* Returned Value   : none
* Comments         :
*    This function make restart of devise
*
*END*----------------------------------------------------------------------*/

extern "C" void dev_restart ( void )
{
 // return; //for test


  AT91RM9200_ST_REG_STRUCT_PTR st_ptr;
#ifndef PROG_VNV
#ifdef PROG_BMDN6
  CommonResetOn(0);
#endif
#endif

#ifdef PROG_MD310_SATI
 outportb(MOD_LED_ADDR1,0);	
#endif


  st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
 //st_ptr->WDMR = 0x10001l; //bit rst en - enable internal reset and counter = 1
 //t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 1; // 1 - counter
    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xff; // 0xff - counter
    st_ptr->CR = AT91RM9200_ST_CR_WATCHDOG_RESTART;	//load this value to counter
 //t UsedExp.State.Reg1.bit.Restart = 1; //Restart Mode on.
  for(;;);
}

extern "C" void dev_restart2 ( void )
{
 // return; //for test


  AT91RM9200_ST_REG_STRUCT_PTR st_ptr;



  st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
 //st_ptr->WDMR = 0x10001l; //bit rst en - enable internal reset and counter = 1
 //t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 1; // 1 - counter
    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xff; // 0xff - counter
    st_ptr->CR = AT91RM9200_ST_CR_WATCHDOG_RESTART;	//load this value to counter
 //t UsedExp.State.Reg1.bit.Restart = 1; //Restart Mode on.
  for(;;);
}



//________________________________________________<<<MDataS
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : dev _restart1
* Returned Value   : none
* Comments         :
*    This function make restart of devise  hot restart bmdn6
*
*END*----------------------------------------------------------------------*/

extern "C" void dev_restart1 ( void )
{
 // return; //for test


  AT91RM9200_ST_REG_STRUCT_PTR st_ptr;

//#ifdef PROG_BMDN6
//  CommonResetOn(0);
//#endif


  st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
 //st_ptr->WDMR = 0x10001l; //bit rst en - enable internal reset and counter = 1
 //t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 1; // 1 - counter
    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xff; // 0xff - counter
    st_ptr->CR = AT91RM9200_ST_CR_WATCHDOG_RESTART;	//load this value to counter
 //t UsedExp.State.Reg1.bit.Restart = 1; //Restart Mode on.
  for(;;);
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : set_test_mode
* Returned Value   : none
* Comments         :
*    This function set_test_mode
*
*END*----------------------------------------------------------------------*/

extern "C" void set_test_mode ( unsigned long set_val)
{
   TestMode.Value =  set_val;
   TestMode.ChangingValue = TestMode.Value;
}

//______________________________________________________________________________
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ParseBufferS
* Returned Value   : none
* Comments         :
*    This routine is used to parse buffer of snmp 
*END*----------------------------------------------------------------------*/
 
 void ParseBufferS(char *pStart,  char razd)
{
	char * pPrev;
   char * pNext;

   pPrev = pStart;
   pNext = pStart;
 //	p = strtok(pStart, &razd);
    for(int i = 0; i < BufferSize; i++)
    { /* Body */
     if((*pNext & 0xff) == '\0')
     { 
         //   if(pNext > pPrev)
         //   { 
               RunCommandS(pPrev);
         //   } 
        break;
     } 
      //   if((*pNext & 0xff)  ==';')
          if(((*pNext & 0xff)  == razd)	|| 	((*pNext & 0xff)  == '.'))
     {
      *pNext = '\0';
      RunCommandS(pPrev);
      pPrev = pNext;
       pPrev++; //to first symbol of next command
     }
      pNext++;
   } /* Endbody */
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : usart1_command_off
* Returned Value   : none
* Comments         :
*    This routine is used to disable interrupt of ethernet
*
*END*----------------------------------------------------------------------*/

extern "C" void usart_command_eth_on()
{

//return ; //t

    AT91RM9200_EMAC_REG_STRUCT_PTR emac_ptr;
   emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;
   
  //  _at91rm9200_peripheral_clock_enable(AT91RM9200_EMAC_PID);
   
      /* Enable Tx, Rx & Management port */
   emac_ptr->CR |= AT91RM9200_EMAC_CR_RX_ENABLE;// |
  // 					AT91RM9200_EMAC_CR_TX_ENABLE);

     

   
       /* clear any pending interrpts */
   /* Just a read access will clear pending interrupts */
 //  emac_ptr->ISR;
  
   
                        
      /* Unmask transmit/receive interrupts */
//   emac_ptr->IER = AT91RM9200_EMAC_IER_RECEIVE_COMPLETED_INT_ENABLE |
 // 				   AT91RM9200_EMAC_IER_TRANSMIT_COMPLETE_INT_ENABLE |
  //               AT91RM9200_EMAC_IER_RXBUF_NOT_AVAILABLE_INT_ENABLE;
   
    
        /* Enable EMAC Interrupt at AIC level  */
   _at91rm9200_int_enable(AT91RM9200_EMAC_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
   					      BSP_ENET_INTERRUPT_PRIORITY);
       UsedExp.State.Reg1.bit.EthOff = 0;                    
// my_int_enable_irq0(); //t100113              
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : usart_command_eth_off
* Returned Value   : none
* Comments         :
*    This routine is used to disable interrupt of ethernet
*
*END*----------------------------------------------------------------------*/

extern "C" void usart_command_eth_off()
{
    AT91RM9200_EMAC_REG_STRUCT_PTR emac_ptr;
 //  return; //________________________________________to test   
   if(UsedExp.State.Reg1.bit.UCDE) //if uart cajndn disable ethernet
 {
   emac_ptr = (AT91RM9200_EMAC_REG_STRUCT_PTR) AT91RM9200_EMAC_BASE;


       /* Disable EMAC  Rx */
   emac_ptr->CR = 0x0;	   //t18
   emac_ptr->CR |= 	AT91RM9200_EMAC_CR_TX_ENABLE | AT91RM9200_EMAC_CR_MGMT_PORT_ENABLE;  //t18

   /* wait untill the deinitialization cycle completes */
    while (!(emac_ptr->CR & AT91RM9200_EMAC_CR_TX_ENABLE)) {	  } /* Endwhile */	//t18

    _at91rm9200_int_disable(AT91RM9200_EMAC_VECTOR);  //to not loss command symbols disable enet AIS level
 	TimerCounter = 0; 
    TimerEthOff = TimerCounter + ((SERIAL_ETH_OFF_TIMEOUT_MS) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l)); //10ms from to next serial command eth maked off
    UsedExp.State.Reg1.bit.EthOff = 1;
 //  emac_ptr->IDR = 0xFFFFFFFF;
   
   // _at91rm9200_peripheral_clock_disable(AT91RM9200_EMAC_PID);
//  hier need set timer to get enet on if serial not finish command 

//my_int_disable_irq0(); //t100113
	} //ucde
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : eth_command_usart_off
* Returned Value   : none
* Comments         :
*    This routine is used to disable interrupt of ethernet
*
*END*----------------------------------------------------------------------*/

extern "C" void eth_command_usart1_off()
{
//100824	TimerCounter1 = 0;
//100824    TimerUSART1Off = TimerCounter1 + ((ETH_SERIAL_OFF_TIMEOUT_MS) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l)); //10ms from to next serial command eth maked off
  
  	   TimerUSART1Off = TimerCounter1;	   //100824
  
  //	printf("\n\r%ld",TimerUSART1Off);
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : is_usart enabled
* Returned Value   : none
* Comments         :
*    This routine is used to disable interrupt of ethernet
*
*END*----------------------------------------------------------------------*/

extern "C" unsigned char is_usart1_enabled()
{

/*	  100824
    if(TimerUSART1Off > TimerCounter1)
//   if(TimerUSART1Off < TimerCounter1)
	{
	 return 0;
	}
	else
	{
	 TimerUSART1Off = 0;
	 return 1;
	}
*/
//_________________________________---100824
	   if(TimerCounter1 < TimerUSART1Off)  // if TimerCounter1 is overflov
	   {
		 TimerUSART1Off = TimerCounter1;
	   }



    if(TimerCounter1 > (TimerUSART1Off + ETH_SER_OFF_TIMEOUT_ALL))
//   if(TimerUSART1Off < TimerCounter1)
	{
 //	TimerUSART1Off =  TimerCounter1;
	 return 1;
	}
	else
	{
	 return 0;
	}
//_________________________________________100824


}



//________________________________________________________________________________________
//extern "C" void UsedMenu_Draw(void)
//{
//	UsedMenu.Draw();
//}  
//_______________________________________________________________________________________

extern "C" void Parse1(void)
{
		
          ParseBuffer(pRBuff, ';');
				*pTBuff = '\0'; //	
 	    	ReplacePC(&TBuff[0]);
			pTBuff--;
         *pTBuff++ = '.'; 
			*pTBuff = '\0'; //					
 			Transmit();
			pTBuff = &TBuff[0];
			pRBuff = &RBuff[0];
			step = 0;
}

#ifdef USART1_TRY_PDC

extern "C" void ReadDatau1(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
unsigned char  SetChar;  

if(GetTestMode() != PIPE_MODE)
{ 
while(cnt_data--)
{
  //ok 	printfpd("(%02X)", * pData);

   SetChar =  * pData++;
 
  embRS485.rcvbuf.Add((unsigned char)(SetChar));
   if(TestMode.Value == 4)
   {
  //    Stephany15++;
      TrzBuff485_Add((unsigned char) SetChar);
   }
}
}
else
{
while(cnt_data--)
{
#ifdef USART0_TRY_PDC_1T

   ToPdcTu0(* pData++);

#endif


}

}
//#endif 

}

#endif // USART1_TRY_PDC

#ifdef USART2_TRY_PDC

extern "C" void ReadDatau2(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
unsigned char  SetChar;   
//printfp("\n\rRead :");
while(cnt_data--)
{
   
   SetChar =  * pData++;

//#ifdef USE_USART2
  //  my_rx_usart2_int( * pData++);

#ifndef PULT_USART2
#ifndef PROG_BMDN
  	embRS232S_rcvbuf_Add(SetChar);
#else
	bcm_usart2_rbuff_add(SetChar);
#endif

#else

//__________________________________


 #ifndef PROG_PU_MSAT

#ifdef 	PROG_MD310_SATI
			 if(1)
				{
#else

	 		   if(TestMode.Value == 0x20)
				{
#endif



#else
				 if(1)
				{

#endif	//pu_msat

  //	  printfpd("_%02X", *pData);
	  AddKeyBuffer(SetChar);
	  }
	  else
	  {
#ifdef IncEmbIndicator
	  embIndicator.m_RBuff.Add(SetChar);
#endif //IncEmbIndicator
	  }
//__________________________________
	
#endif	//pult
//#endif
//  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//120229
 //   printfp("step1");

   if(GetTestMode() == 0x104)
   {
  //    Stephany15++;
  //    TrzBuff485_Add(* pData++);
   // printfp(" step2");

#ifdef  USART0_TRY_PDC_1T    
   //  TrzBuff232_Add((unsigned char) SetOpChar);
  //  printfp(" step3");

	   ToPdcTu0(SetChar);
 //	   printfpd("%c",SetChar);
#endif

   }

}
//#endif 

}

#endif // USART2_TRY_PDC





//_________________________________________________________________
#ifdef USART0_TRY_PDC_1

extern "C" void ReadDatau0(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
//unsigned char  SetChar;   
if(GetTestMode() != PIPE_MODE)
{
while(cnt_data--)
{
 //  SetChar =  * pData++;
//  my_rx_usart0_int(SetChar);	//all maked in this  ethernet not disabled to pragma
  my_rx_usart0_int( * pData++);
//  embRS232.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff232_Add((unsigned char) SetChar);
//   }
}
}
else
{
  while(cnt_data--)
 {
#ifdef USART1_TRY_PDC_1T

   ToPdcTu1(* pData++);

#endif
 }
}

//#endif 

}

#endif // USART0_TRY_PDC_1

#ifdef USART0_TRY_PDC_1T

extern "C" void ReadDatau0t(unsigned char * pData, unsigned long cnt_data)
{
/*
//#ifdef IncEmbRS485 
unsigned char  SetChar;   
while(cnt_data--)
{
   
   SetChar =  * pData++;
  my_rx_usart0_int(SetChar);	//all maked in this  ethernet not disabled to pragma

//  embRS232.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff232_Add((unsigned char) SetChar);
//   }
}
//#endif 
 */
}

#endif // USART0_TRY_PDC_1





//_________________________________________________________________



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_rx_usart1_int
* Returned Value   : none
* Comments         :
*    This routine is used to service interrupt of rx usart1
*
*END*----------------------------------------------------------------------*/

extern "C" void my_rx_usart1_int( char SetOpChar)
 {
 //_______________________________________________________
  char OpChar = SetOpChar & 0xff;
//#ifndef PROG_ACT155N
//#ifndef PROG_PRM_PCH_N

#ifdef PROG_PRM_PCH_N_1
SetLed2(1);
#endif // PROG_PRM_PCH_1


#ifndef ETH_NOT_STOPPED
#ifndef RS485_NOT_DISABLE_ETHERNET
//#ifndef PROG_PRM_PCH_N
  usart_command_eth_off(); //t
 //  usart_command_eth_off(); //t
 //   usart_command_eth_off(); //t
 //	 usart_command_eth_off(); //t
//#endif 
#endif //RS485_NOT_DISABLE_ETHERNET
#endif // ETH_NOT_STOPPED

#ifdef PROG_PRM_PCH_N
//delay_mcs(10l);
#endif //PROG_PRM_PCH_N


//#endif // PROG_PRM_PCH_N

//#endif //PROG_ACT155N
  UsedExp.State.Reg1.bit.Mf20SnmpOn = 0; //for answer mf20 will use usart - if previons was using snmp

#ifdef IncEmbRS485 
 
  embRS485.rcvbuf.Add((unsigned char)(SetOpChar));
   if(TestMode.Value == 4)
   {
  //    Stephany15++;
      TrzBuff485_Add((unsigned char) SetOpChar);
   }
#endif 

//130918 #ifdef DISABLE_MY_PROTOKOL_ON_RS_485
return;
//130918 #endif //DISABLE_MY_PROTOKOL_ON_RS_485

  
 	if (step == 0) //need wait '#'
	{
		if(OpChar == '#') 
		{
		CommandSize = 0; //start command
		step = 1;
		pRBuff = &RBuff[0];
    	
		}
	}
	else if (step == 1) // need wait property address
	{
 //t		if(OpChar == '0') //temporary first digit of address
 //		 if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value >> 4) & 0xf))
		if(TestAddrChar(OpChar, 4))
		{
			step = 2;
		}
		else //bad addr
		{
			pRBuff = &RBuff[0];
			step = 0;
		}
	}
	else if (step == 2) // need wait property address
	{
  //t		if(OpChar == '0') //temporary second digit of address
 //	   if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value) & 0xf))
		if(TestAddrChar(OpChar, 0))
		{
//        usart_command_eth_off(); //hier need disable ethernet
   		step = 3;
			pTBuff = &TBuff[0];
			*pTBuff++ = '%';
   //		*pTBuff0++ = '0';//temporary first digit of address
		   *pTBuff++ =Char2Hex(((unsigned char)UARTAddress.Value >> 4) & 0xf);
		 //	*pTBuff0++ = '0';//temporary second digit of address
		   *pTBuff++ =Char2Hex(((unsigned char)UARTAddress.Value) & 0xf);
      }
		else //bad addr
		{
			pRBuff = &RBuff[0];
			step = 0;
		}
	}	
	else if (step == 3) // write and finished command
	{
  		if(OpChar == '.') //wait end command  
		{
 			*pRBuff = '\0'; //to finish string in buffer
			pRBuff = &RBuff[0];
		    UsedExp.State.Reg2.bit.Parse1 = 1; //t
	  		 UsedExp.State.Reg2.bit.Some = 1;	//t
           //t      usart1_command_eth_on();  //heer are enabled commands of ethernet
		}
		else if(OpChar == '#') //wait  start new command if previons command is lost
		{
			pRBuff = &RBuff[0];
			*pRBuff++ = OpChar;
			step = 1;
 //t         usart1_command_eth_on();
		}
		else //write command to buffer
		{
			CommandSize++;
      // 		if(CommandSize < BufferSize)
			if(CommandSize < MAX_COMMAND_SIZE)
			{
			*pRBuff++ = OpChar;
			}
			else
			{
			pRBuff = &RBuff[0];
			step = 0;			
			}
		}		
	}

//#ifdef DISABLE_MY_PROTOKOL_ON_RS_485
//return;
//#endif //DISABLE_MY_PROTOKOL_ON_RS_485

 
 
 //_______________________________________________________
 }


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : polled_scan_usart1
* Returned Value   : none
* Comments         :
*    This routine is used to scan data for usart1
*
*END*----------------------------------------------------------------------*/

extern "C" void polled_scan_usart1( void)
 {
 unsigned char rch;
	    while(_io_fstatus(fusart1_ptr))
		{
              rch = fgetc( fusart1_ptr );
	  //		  printf(" %02X",rch);
		 //t	  my_rx_usart1_int(fgetc( fusart1_ptr ));
   embRS485.rcvbuf.Add((unsigned char)(rch));
   if(TestMode.Value == 4)
   {
  //    Stephany15++;
      TrzBuff485_Add((unsigned char) rch);
   }


		}

 }



extern "C" void Parse0(void)
{
    //    	*pRBuff0 = '\0'; //to finish string in buffer
	//		pRBuff0 = &RBuff0[0];
//			ParseBuffer(pRBuff, theAnyStrings.cRazd);
          ParseBuffer0(pRBuff0, ';');
		//hier need get off all points from string (1.<- this points222e11)
	//t		pTBuff--;
	//t		strcpy(pTBuff++, theAnyStrings.cPoint); 
		// 	my_int_enable_usart0();

		 	*pTBuff0 = '\0'; //	
 	    	ReplacePC(&TBuff0[0]);   //
			pTBuff0--;
 //new			pTBuff0--;
 //			strcpy(pTBuff++, theAnyStrings.cPoint); 
  //			strcpy(pTBuff++, '.'); 

         *pTBuff0++ = '.'; 
			*pTBuff0 = '\0'; //					
 			Transmit0();
			pTBuff0_init();
			pRBuff0_init();
		 //	pTBuff0 = &TBuff0[0];
		 //	pRBuff0 = &RBuff0[0];
			step0 = 0;
}

extern "C" void ParseE(void)
{
    ParseBuffer3(pRBuff3, ';');
	*pTBuff3 = '\0'; //	
   	ReplacePC(&TBuff3[0]);   //
	pTBuff3--;
    *pTBuff3++ = '.'; 
 	*pTBuff3 = '\0'; //	
	TransmitE();
	pTBuff3_init();
	pRBuff3_init();
		 //	pTBuff0 = &TBuff0[0];
		 //	pRBuff0 = &RBuff0[0];
	step3 = 0;
}


extern unsigned char errors;

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_rx_usart0_int
* Returned Value   : none
* Comments         :
*    This routine is used to service interrupt of rx usart0
*
*END*----------------------------------------------------------------------*/

extern "C" void my_rx_usart0_int( char SetOpChar)
 {
#ifdef USART0_TRY_PDC
//counter_int++;
#endif //  USART0_TRY_PDC
//______________________________________________________________________
#ifdef TEMPORARY_MAKE_FULL_ETH
	 static unsigned char vchar;
 //	 unsigned char errors;
	unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
 // *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = 0;//unsigned char(dataparam & 0xff);
   if((unsigned char)SetOpChar != vchar)
   {
		errors++;
       *(bt + NVRAM_DEBUG_STORAGE) = errors;
	//   *(bt + NVRAM_DEBUG_STORAGE) = 0x43;
       vchar = SetOpChar;		
   }
	else
	{

	//   *(bt + NVRAM_DEBUG_STORAGE) = 0x12;
	}

   vchar++;

 //     fputc(SetOpChar, fusart0_ptr);
 #ifndef USART0_TRY_PDC_1T
         fputc(SetOpChar, fusart0_ptr); 
#else
         ToPdcTu0(SetOpChar);

#endif 

	 return;
#endif //	 TEMPORARY_MAKE_FULL_ETH

//_______________________________________________

#ifdef PROG_PRM_PCH_N_1
SetLed2(1);
#endif // PROG_PRM_PCH_1


// LedOff();
// _int_disable(); //090326 
  //ok	return; //for test

//  return; //t1109
#ifndef USART0_TRY_PDC_1
#ifndef TEMPORARY_MAKE_FULL_ETH
#ifndef ETH_NOT_STOPPED
#ifndef PROG_ACT155N	//090708
#ifndef RS232_NOT_DISABLE_ETHERNET
#ifndef PROG_MF20
   if(is_servicepack)
#endif //PROG_MF20
   {
   usart_command_eth_off();
   }
#endif //RS232_NOT_DISABLE_ETHERNET
#endif // PROG_ACT155N
#endif //ETH_NOT_STOPPED
#endif 	//TEMPORARY_MAKE_FULL_ETH
#endif //USART0_TRY_PDC_1


 // 	 if(!(UsedExp.State.Reg1.bit.Restart)) 
//  	 {
 // 	 wd_reset();
 //	 }

 //  _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ);
//  _int_disable();
 //	static char step = 0;
  //	static int16 CommandSize = 0;
  // int16 RBuffSize = 128; //it aet to 128 in constructor
  //	int16 TBuffSize = 128; //it aet to 128 in constructor	
//________________test
 //  printf(" %c", SetOpChar);   
//_______________test   
   
//	char OpChar = ReadChar();
   char OpChar = SetOpChar & 0xff;  
//#ifdef IncEmbRS232  

//090325  usart_command_eth_off(); //t

 //  mf20_int_232(OpChar); //t1106
   //	my_printf(0x15); 
   UsedExp.State.Reg1.bit.Mf20SnmpOn = 0; //for answer mf20 will use usart
 //#ifndef TEMPORARY_MAKE_FULL_ETH  //for test

#ifdef 	PROG_BMDN6
used_TCP = 0;
#endif
#ifdef 	PROG_COMMUTATOR1
used_TCP = 0;
#endif
#ifdef PROG_PU_M710
used_TCP = 0;
#endif


    embRS232_rcvbuf_Add((unsigned char)(SetOpChar));
// #endif // TEMPORARY_MAKE_FULL_ETH



  // return; 	   //for test


   if(TestMode.Value == 4)
   {
     TrzBuff232_Add((unsigned char) SetOpChar);
   }

  if(TestMode.Value == 0x104)
   {
#ifdef  USART2_TRY_PDC    
   //  TrzBuff232_Add((unsigned char) SetOpChar);
	   ToPdcTu2((unsigned char) SetOpChar);
#endif

   }


  if(TestMode.Value == 0x28) //echo
   {
     fputc(SetOpChar, fusart0_ptr);
   //	 return;
   }



// return; //to test
//#endif
 //  Test = SetOpChar & 0xff;     //___________________test 
   //	ResetWD();
	if (step0 == 0) //need wait '#'
	{
//		ResetWD();
		if(OpChar == '#') 
		{
		CommandSize0 = 0; //start command
		step0 = 1;
		pRBuff0 = &RBuff0[0];
    	
		}
	}
	else if (step0 == 1) // need wait property address
	{
		//need make address class
 //		if(OpChar == '0') //temporary first digit of address
  //	if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value >> 4) & 0xf))
		if(TestAddrChar(OpChar, 4))
 		{
			step0 = 2;
		}
		else //bad addr
		{
			pRBuff0 = &RBuff0[0];
			step0 = 0;
		}
	}
	else if (step0 == 2) // need wait property address
	{
		//need make address class
//		if(OpChar == '0') //temporary second digit of address
//		if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value) & 0xf))
		 if(TestAddrChar(OpChar, 0))

		{
    //t     usart_command_eth_off(); //hier need disable ethernet
 			step0 = 3;
			pTBuff0_init();		 //?? need
	   //	pTBuff0 = &TBuff0[0];
	   		pTBuff0_control(1l);
			*pTBuff0++ = '%';
	 //		*pTBuff0++ = '0';//temporary first digit of address
	    	pTBuff0_control(1l);
		    *pTBuff0++ =Char2Hex(((unsigned char)UARTAddress.Value >> 4) & 0xf);
		 //	*pTBuff0++ = '0';//temporary second digit of address
		    pTBuff0_control(1l);

		   *pTBuff0++ =Char2Hex(((unsigned char)UARTAddress.Value) & 0xf);

		}
		else //bad addr
		{
		pRBuff0_init();
	  //		pRBuff0 = &RBuff0[0];
			step0 = 0;
		}
	}	
	else if (step0 == 3) // write and finished command
	{
		//need make address class
		if(OpChar == '.') //wait end command  
		{
      //  *pRBuff++ = ';'; //to test

			*pRBuff0 = '\0'; //to finish string in buffer
	 		pRBuff0 = &RBuff0[0]; //it maked for parse!
   	 //my_int_disable_usart0();
   //usart0_connecting(0); //disconnect

     UsedExp.State.Reg2.bit.Parse0 = 1; //t
     UsedExp.State.Reg2.bit.Some = 1;	//t
//t       Parse0(); //new - make in future bit of need run parse0 
/*
        ParseBuffer0(pRBuff0, ';');
 		*pTBuff0 = '\0'; //	
 	    ReplacePC(&TBuff0[0]);   //
		pTBuff0--;
        *pTBuff0++ = '.'; 
		*pTBuff0 = '\0'; //					
 		Transmit0();
		pTBuff0 = &TBuff0[0];
		pRBuff0 = &RBuff0[0];
		step0 = 0;
  */
		}
		else if(OpChar == '#') //wait  start new command if previons command is lost
		{
			pRBuff0 = &RBuff0[0];
			pRBuff0_control(1l);
			*pRBuff0++ = OpChar;
			step0 = 1;
		}
		else //write command to buffer
		{
			CommandSize0++;
  //			if(CommandSize < RBuffSize)
     //		if(CommandSize0 < BufferSize0)
			if(CommandSize0 < MAX_COMMAND_SIZE)
			{
			pRBuff0_control(1l);
			*pRBuff0++ = OpChar;
			}
			else
			{
		   //	pRBuff0 = &RBuff0[0];
			pRBuff0_init();
			step0 = 0;			
			}
		}		
	}
//   Test = step;

  // 	 _int_enable(); //090326
   //my_int_enable_usart0();
  //  LedOn();

}


extern "C" void polled_scan_usart0( void)
 {
 unsigned char rch;
	  //  while(_io_fstatus(fusart0_ptr))
	  for(long i= 0; i < 100; i++)
	  {
	    if(_io_fstatus(fusart0_ptr))
		{
              rch = fgetc( fusart0_ptr );
	  	  //	  printf(" %02X",rch);
		 //	  my_rx_usart0_int(fgetc( fusart0_ptr ));
		  my_rx_usart0_int(rch);
	  //	   Stephany19 = i;
  
		}
		else
		{
		return;
		}
	  }

 }



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : dir_eth_232
* Returned Value   : none
* Comments         :
*    This routine is used to service interrupt of rx usart0
*
*END*----------------------------------------------------------------------*/

extern "C" void dir_eth_232( char SetOpChar)
 {
	char OpChar = SetOpChar & 0xff;  
 	if (step3 == 0) //need wait '#'
	{
		if(OpChar == '#') 
		{
	//	printfp1("_st ");
		 CommandSize3 = 0; //start command
		 step3 = 1;
		 pRBuff3 = &RBuff3[0];
    	
		}
	}
	else if (step3 == 1) // need wait property address
	{
 		if(TestAddrChar(OpChar, 4))
 		{
			step3 = 2;
		}
		else //bad addr
		{
			pRBuff3 = &RBuff3[0];
			step3 = 0;
		}
	}
	else if (step3 == 2) // need wait property address
	{
		 if(TestAddrChar(OpChar, 0))
		{
   			step3 = 3;
			pTBuff3_init();		 //?? need
	   //	pTBuff0 = &TBuff0[0];
	   		pTBuff3_control(1l);
			*pTBuff3++ = '%';
	 //		*pTBuff0++ = '0';//temporary first digit of address
	    	pTBuff3_control(1l);
		    *pTBuff3++ =Char2Hex(((unsigned char)UARTAddress.Value >> 4) & 0xf);
		 //	*pTBuff0++ = '0';//temporary second digit of address
		    pTBuff3_control(1l);

		   *pTBuff3++ =Char2Hex(((unsigned char)UARTAddress.Value) & 0xf);

		}
		else //bad addr
		{
		pRBuff3_init();
  			step3 = 0;
		}
	}	
	else if (step3 == 3) // write and finished command
	{
//	printfp1("_fin ");
		//need make address class
		if(OpChar == '.') //wait end command  
		{
      //  *pRBuff++ = ';'; //to test
  //	  printfp1("_fin ");
			*pRBuff3 = '\0'; //to finish string in buffer
	 		pRBuff3 = &RBuff3[0]; //it maked for parse!
  
   //  UsedExp.State.Reg2.bit.ParseE = 1; //t
   //  UsedExp.State.Reg2.bit.Some = 1;	//t
	 ParseE();
	}
		else if(OpChar == '#') //wait  start new command if previons command is lost
		{
			pRBuff3 = &RBuff3[0];
			pRBuff3_control(1l);
			*pRBuff3++ = OpChar;
			step3 = 1;
		}
		else //write command to buffer
		{
			CommandSize3++;
  //			if(CommandSize < RBuffSize)
   //  		if(CommandSize3 < BufferSize3)
			if(CommandSize3 < MAX_COMMAND_SIZE)
			{
			pRBuff3_control(1l);
			*pRBuff3++ = OpChar;
			}
			else
			{
		   //	pRBuff0 = &RBuff0[0];
			pRBuff3_init();
			step3 = 0;			
			}
		}		
	}
}



 extern "C" void Parse3(void)
{

		    ParseBuffer3(pRBuff3, ';');
		//hier need get off all points from string (1.<- this points222e11)
	//t		pTBuff--;
	//t		strcpy(pTBuff++, theAnyStrings.cPoint); 
			*pTBuff3 = '\0'; //	
 	    	ReplacePC(&TBuff3[0]);   //
			pTBuff3--;
 //new			pTBuff3--;
 //			strcpy(pTBuff++, theAnyStrings.cPoint); 
  //			strcpy(pTBuff++, '.'); 
         *pTBuff3++ = '.'; 
			*pTBuff3 = '\0'; //					
 			Transmit3();
			pTBuff3 = &TBuff3[0];
			pRBuff3 = &RBuff3[0];
			step3 = 0;
 }

//#ifdef USE_USART2

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_rx_usart2_int
* Returned Value   : none
* Comments         :
*    This routine is used to service interrupt of rx usart2
*
*END*----------------------------------------------------------------------*/

extern "C" void my_rx_usart2_int( char SetOpChar)
 {

//  	char OpChar = SetOpChar & 0xff; 
//  		embRS232S_rcvbuf_Add(OpChar); 

//#ifdef TEST_USART2_REMOTE
//printfpd(":%02X", OpChar);
//#endif
 }

//#endif // USE_USART2



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_rx_usart3_int
* Returned Value   : none
* Comments         :
*    This routine is used to service interrupt of rx usart3
*
*END*----------------------------------------------------------------------*/

extern "C" void my_rx_usart3_int( char SetOpChar)
 {

#ifndef PULT_USART

   return; //130918

 //	static char step = 0;
  //	static int16 CommandSize = 0;
  // int16 RBuffSize = 128; //it aet to 128 in constructor
  //	int16 TBuffSize = 128; //it aet to 128 in constructor	
//________________test
 //  printf(" %c", SetOpChar);   
//_______________test   
   
//	char OpChar = ReadChar();
	char OpChar = SetOpChar & 0xff;  
 //  Test = SetOpChar & 0xff;     //___________________test 
   //	ResetWD();
	if (step3 == 0) //need wait '#'
	{
//		ResetWD();
		if(OpChar == '#') 
		{
		CommandSize3 = 0; //start command
		step3 = 1;
		pRBuff3 = &RBuff3[0];
    	
		}
	}
	else if (step3 == 1) // need wait property address
	{
		//need make address class
	//	if(OpChar == '0') //temporary first digit of address
 //	if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value >> 4) & 0xf))
		if(TestAddrChar(OpChar, 4))
	    {
			step3 = 2;
		}
		else //bad addr
		{
			pRBuff3 = &RBuff3[0];
			step3 = 0;
		}
	}
	else if (step3 == 2) // need wait property address
	{
		//need make address class
   //		if(Hex2Char(OpChar) == (((unsigned char)UARTAddress.Value) & 0xf))
		if(TestAddrChar(OpChar, 0))
  //		if(OpChar == '0') //temporary second digit of address
		{
         usart_command_eth_off(); //hier need disable ethernet
 			step3 = 3;
			pTBuff3 = &TBuff3[0];
			*pTBuff3++ = '%';
  //		*pTBuff0++ = '0';//temporary first digit of address
		   *pTBuff3++ =Char2Hex(((unsigned char)UARTAddress.Value >> 4) & 0xf);
		 //	*pTBuff0++ = '0';//temporary second digit of address
		   *pTBuff3++ =Char2Hex(((unsigned char)UARTAddress.Value) & 0xf);
		}
		else //bad addr
		{
			pRBuff3 = &RBuff3[0];
			step3 = 0;
		}
	}	
	else if (step3 == 3) // write and finished command
	{
		//need make address class
		if(OpChar == '.') //wait end command  
		{
      //  *pRBuff++ = ';'; //to test

			*pRBuff3 = '\0'; //to finish string in buffer
			pRBuff3 = &RBuff3[0];
		    UsedExp.State.Reg2.bit.Parse3 = 1; //t
	   		UsedExp.State.Reg2.bit.Some = 1;	//t
   /*

//			ParseBuffer(pRBuff, theAnyStrings.cRazd);
          ParseBuffer3(pRBuff3, ';');
		//hier need get off all points from string (1.<- this points222e11)
	//t		pTBuff--;
	//t		strcpy(pTBuff++, theAnyStrings.cPoint); 
			*pTBuff3 = '\0'; //	
 	    	ReplacePC(&TBuff3[0]);   //
			pTBuff3--;
 //new			pTBuff3--;
 //			strcpy(pTBuff++, theAnyStrings.cPoint); 
  //			strcpy(pTBuff++, '.'); 
         *pTBuff3++ = '.'; 
			*pTBuff3 = '\0'; //					
 			Transmit3();
			pTBuff3 = &TBuff3[0];
			pRBuff3 = &RBuff3[0];
			step3 = 0;
*/
		}
		else if(OpChar == '#') //wait  start new command if previons command is lost
		{
			pRBuff3 = &RBuff3[0];
			*pRBuff3++ = OpChar;
			step3 = 1;
		}
		else //write command to buffer
		{
			CommandSize3++;
  //			if(CommandSize < RBuffSize)
     	 //	if(CommandSize3 < BufferSize3)
			if(CommandSize3 < MAX_COMMAND_SIZE)
			{
			*pRBuff3++ = OpChar;
			}
			else
			{
			pRBuff3 = &RBuff3[0];
			step3 = 0;			
			}
		}		
	}
//   Test = step;
#else
#ifndef PULT_USART2
#ifndef PROG_PU_MSAT
	 		   if(TestMode.Value == 0x20)
				{
#else
				 if(1)
				{

#endif
	  AddKeyBuffer(SetOpChar);
	  }
	  else
	  {
#ifdef IncEmbIndicator
	  embIndicator.m_RBuff.Add(SetOpChar);
#endif //IncEmbIndicator
	   
	  }
#endif //PULT_USART2
#endif
}
#ifdef PROG_MF20



extern "C" void TryDetectMF20()
{
 //unsigned int i;
// static long wait;
 //int l_base;
 /* 
    for (i=2; i<=8; i+=2)	 //mchs : 4 blocks
  {
		l_base = 0x500 + i*16;
		outportb(l_base,0x55);
	   	if(inportb(l_base)!=0x55) 
		{
		wait = 0l;
		return;
   		}
  }
  */ 
  //   for (i=2; i<=2; i+=2)	 //mchs : 4 blocks
  //{
  //		l_base = 0x500 + i*16;
  //		outportb(l_base,0x55);
  //	   	if(inportb(l_base)!=0x55) 
  //		{
  //		TimerStartMF20 = 0l;
  //		return;
  // 		}

 // }

	/*
    for (i=0; i<16; i++)	 //mchs : 4 blocks
  {
		l_base = 0x500 + i*16;
		outportb(l_base,0x55);
	   	if(inportb(l_base) == 0x55) 
		{
		break;
	    }
  }
  if(i == 16)
  {
  wait = 0l;
  return;
  }
  */
  if(!(TimerStartMF20 % 1000l))
  printfpd (" %05ld",TimerStartMF20);
  TimerStartMF20++;
//  if(TimerStartMF20 > 300l)	//ok
  if(TimerStartMF20 > START_TIMEOUT)	//ok
//  if(wait > 100000l)	//ok1
 //if(wait == 750l)
  // if(wait == 500l)	 //bad
//  if(wait == 50l)  //ok	
//    if(wait == 25l)	 //ok
 //   if(wait == 10l)		//bad
  {
		 UsedExp.State.Reg1.bit.Mf20Ready = 1;
   //		 mf20_init(); -> init is before; now only detect types of blocks
   //		 printf("\n\r....Init MF20");
		 mf20_detect();
  }
} 
#endif //prog_MF20



//_______________________________________________________________________________________


extern "C" void Devise(void)
 { /* Body */


//#ifndef PROG_ACT155
   if(!(UsedExp.State.Reg1.bit.Restart))  wd_reset();
//#else
//   if((!(UsedExp.State.Reg1.bit.Restart)) && (wd_reset_enabled == 1))
//   {
//     wd_reset_enabled = 0;
//	 wd_reset();
//   }
//#endif

//	if(LockMode.Value != 2)
	if(((unsigned)LockMode.Value == (unsigned)3)	&& ComparePOK(0x1000l))  //only key5 get off
	{
	  lock_counter++;
	  if(lock_counter > ENABLED_UNLOCK_TIME)
	  {
	     ClearBufferState((unsigned long)LOCK_MODE1);
		 ClearBufferState((unsigned long)LOCK_MODE3);
	     SetBufferState((unsigned long)LOCK_MODE2);
		 lock_counter = 0;
		 LockMode.Value = 2;

	  } 

	}

#ifdef USE_PULT
#ifdef PULT_USART
 char tmp; 
#endif //PULT_USART
#endif//USE_PULT
 if(TestMode.Value != 7l)
 // if(0) //test 090807
 {
    
#ifdef PROG_BMDN  
 //my_int_disable();
      BMDN();
// my_int_enable();
#endif //PROG_BMDN  
 }
	

//  unsigned char test;
        
    //   testclass =  UseClass();
    //   printf("\r testclass =   %d",testclass);
         
  //     VolNumber.Value = 123456; //to test
   	  
	//  printf("\r\n>>> %X", UsedExp.State.Reg1.all);	  //t
  
     
 //	   for(int i = 0; i < 2; i ++)
	  //  for(int i = 0; i < 3; i ++)
   	   //  {
  	   	 if(UsedExp.State.Reg2.bit.Some)
  	 	 {
  	 	 UsedExp.LoadDevises();
  	 	 }
	//  	 else
	//   	 {
	//  	 break;
	//  	 }
	//    }

#ifndef PROG_PRM_PCH_N

#ifndef  DISABLE_ETHERNET
#ifndef	 PROG_PRM_PCH_SPI_XIL

	 if(UsedExp.State.Reg1.bit.EthOff)
      { if(TimerEthOff < TimerCounter) 
				{  usart_command_eth_on();}
	  }

#endif

#endif // DISABLE_ETHERNET

#endif // PROG_PRM_PCH_N

	  //t else if(UsedPult.State.KeyPr)
#ifdef USE_PULT
#ifdef PULT_USART
    tmp =  UsedPult.GetDataChar();
//		printf("\n\r>%02X", tmp);
  //	printfpd(" %02X", tmp);

	if(tmp)
	{
//printfp("\n\r___________________________________________X");
//printfpd("\n\r %02X", tmp);
 //no  return; //t
  	UsedPult.Key = tmp;
  //this is in ticket_on()	Transmit3c('U');
 //	Transmit3c(tmp);
  //printEthLongHex(8);
    ticket_on();	  //???
    UsedPult.State.KeyPr = 1; //key is pressed  ?? need?
    UsedMenu.ServiceKey(UsedPult.GetKey());
	}
#else  //PULT_USART
	  if(UsedPult.State.KeyPr)
	   {
	  // printfp("\n\rKeyPr");
	       UsedMenu.ServiceKey(UsedPult.GetKey());
  	   }
	   else
	   {
		 UsedPult.GetDataChar(); //to clear not - waiting interrupts
	   }
#endif //PULT_USART
#endif //USE_PULT
   
   //     *pTBuff = '!';
   //    fputc(*pTBuff, fusart1_ptr); 
 //ok  printf("Test\n\r");
 //  for (int i = 0; i < 128; i++)
 //	{
// 	 printf(" %d \n\r" ,Test);
 //	}
 //   printf("\n\r");
#ifdef PROG_MF20
   if(!UsedExp.State.Reg1.bit.Mf20Ready)
   {
     TryDetectMF20();
   }
#endif// PROG_MF20  

#ifdef IncEmbRS485
#ifdef IncEmbRS232
 if(TestMode.Value == 4)
 {
  TrzBuffs_Send();
 }
   /*
 if(TestMode.Value == 0x104)
 {
  TrzBuffs_Send();
 }
	*/

#endif// IncEmbRS232
#endif //IncEmbRS485

#ifndef TEMPORARY_MAKE_FULL_ETH
  //to property test only eth interrupts from Jack_E
  UseDirRS232();  //comment this do not change somthing

#endif // TEMPORARY_MAKE_FULL_ETH
  // polled_scan_usart1(); //t 1020
//   polled_scan_usart0(); //t090424
//#endif //PROG_DTVM 


}

#ifdef IncEmbIndicator

extern "C" void CopyInd0ToRemote(char* pData)
{
 uint_32 cnt;
 cnt = 0;
 while(* pData)
 {
 IndData0.Value[cnt++] =  * pData++;
 if(cnt > (TBUFF1_VALUE - 1)) 
 {
  IndData0.Value[cnt] =  '\0';
  return;
  }

 }
  IndData0.Value[cnt] =  '\0';
}

extern "C" void CopyInd1ToRemote(char* pData)
{
 uint_32 cnt;
 cnt = 0;
 while(* pData)
 {
 IndData1.Value[cnt++] =  * pData++;
 if(cnt > (TBUFF1_VALUE - 1)) 
 {
  IndData1.Value[cnt] =  '\0';
  return;
  }

 }
 IndData1.Value[cnt] =  '\0';

}

extern "C" void CopyCur2Remote(int val)
{
// printfpd(" %d ", val);
  CurData.Value =  val;
}

extern "C" void CopyLed2Remote(int val)
{
 unsigned char mode,number;
 unsigned long tmp, tmp1;
 mode   = val >> 4;
 number = val & 0xf;
// printf("number = %d, mode = %d", number, mode);   //t

 tmp = LedData.Value;
 tmp1 =     0xf 	 << (number << 2);
 tmp &= (~tmp1);
 tmp |= (mode & 0xf) << (number << 2);
 LedData.Value =  tmp;
 //LedData.Value =  0x12345678; //t
}



#endif //IncEmbIndicator 
 /*
unsigned short SelfVer1() 
{ 
 return (unsigned short)DevVer1.Value;
}

unsigned short SelfVer2() 
{ 
 return (unsigned short)DevVer2.Value;
}
 */

#ifdef TRAP_ENABLED

extern "C" void TRAP_Start_Transmit( char * , char * , long );

#define HEADER_LENGTH   (0x45)
#define SERVICES 	    (0)
#define TOTAL_LENGTH1   (0)
#define TOTAL_LENGTH2   (0x5B)
#define IDENTIFICATION1 (0x68)
#define IDENTIFICATION2 (0x44)
#define FLAGS1 (0)
#define FLAGS2 (0)
#define TIMETOLIVE (0x80)
#define PROTUDP    (0x11)
#define HEADERCHS1 (0xb1) 
#define HEADERCHS2 (0x20) 
#define SIP0 (155)
#define SIP1 (155)
#define SIP2 (155)
#define SIP3 (225)
#define DIP0 (155)
#define DIP1 (155)
#define DIP2 (155)
#define DIP3 (157)
#define SRCPORT1 (0x47)
#define SRCPORT2 (0x55)
#define DSTPORT1 (0)
#define DSTPORT2 (0xa2)
#define	LEN1 (0)
#define	LEN2 (0x47)
#define	CHECK1 (0xa7)
#define	CHECK2 (0x3b)
#define	SNMP1 (0x30)
#define	SNMP2 (0x3d)
#define	SNMPV1 (2)
#define	SNMPV2 (1)
#define	SNMPV3 (0)
#define	SNMPCM1 (04)
#define	SNMPCM2 (06)
#define	SNMPS1 ('p')
#define	SNMPS2 ('u')
#define	SNMPS3 ('b')
#define	SNMPS4 ('l')
#define	SNMPS5 ('i')
#define	SNMPS6 ('c')
#define	PDUTYPE1 (0xa4)
#define	PDUTYPE2 (0x30)

#define	ENTERPRISE1  (0x06)
#define	ENTERPRISE2  (0x08)
#define	ENTERPRISE3  (0x2b)
#define	ENTERPRISE4  (0x06)
#define	ENTERPRISE5  (0x01)
#define	ENTERPRISE6  (0x06)
#define	ENTERPRISE7  (0x03)
#define	ENTERPRISE8  (0x01)
#define	ENTERPRISE9  (0x01)
#define	ENTERPRISE10 (0x05)

#define	AGADDRESS1 (0x40)
#define	AGADDRESS2 (0x04)
#define	AGADDRESS3 (155)
#define	AGADDRESS4 (155)
#define	AGADDRESS5 (155)
#define	AGADDRESS6 (225)

#define	TRAPTYPE1 (2)	 
#define	TRAPTYPE2 (1)
#define	TRAPTYPE3 (0)

#define	STRAPTYPE1 (2)	 
#define	STRAPTYPE2 (1)
#define	STRAPTYPE3 (0)

#define	TIMESTAMP1 (0x43)	 
#define	TIMESTAMP2 (0x04)	
#define	TIMESTAMP3 (0x1)	
#define	TIMESTAMP4 (0xab)	
#define	TIMESTAMP5 (0x17)	
#define	TIMESTAMP6 (0x15)	


#define OID1  (0x30)
#define OID2  (0x12)
#define OID3  (0x30)
#define OID4  (0x10)
#define OID5  (0x06)
#define OID6  (0x0b)
#define OID7  (0x2b)
#define OID8  (0x06)
#define OID9  (0x01)
#define OID10 (0x04)
#define OID11 (0x01)
#define OID12 (0x81)
#define OID13 (0xf2)
#define OID14 (0x61)
#define OID15 (0x04)
#define OID16 (0x16)
#define OID17 (0x00)

#define VAL1 (0x41)
#define VAL2 (0x01)
#define VAL3 (0x01)

//#define TCP_HEADER_SIZE      20 
//#define IP_HEADER_SIZE       20                  // w/o options




// Ethernet network layer definitions
#define ETH_DA_OFS           0                   // Destination MAC address (48 Bit)
#define ETH_SA_OFS           6                   // Source MAC address (48 Bit)
#define ETH_TYPE_OFS         12                  // Type field (16 Bit)
#define ETH_DATA_OFS         14                  // Frame Data
#define ETH_HEADER_SIZE      14

#define FRAME_ARP            0x0806              // frame types (stored in Type/Length field)
#define FRAME_IP             0x0800

// IPv4 layer definitions
#define IP_VER_IHL_TOS_OFS   ETH_DATA_OFS + 0    // Version, Header Length, Type of Service
#define IP_TOTAL_LENGTH_OFS  ETH_DATA_OFS + 2    // IP Frame's Total Length
#define IP_IDENT_OFS         ETH_DATA_OFS + 4    // Identifying Value
#define IP_FLAGS_FRAG_OFS    ETH_DATA_OFS + 6    // Flags and Fragment Offset
#define IP_TTL_PROT_OFS      ETH_DATA_OFS + 8    // Frame's Time to Live, Protocol
#define IP_HEAD_CHKSUM_OFS   ETH_DATA_OFS + 10   // IP Frame's Header Checksum
#define IP_SOURCE_OFS        ETH_DATA_OFS + 12   // Source Address (32 Bit)
#define IP_DESTINATION_OFS   ETH_DATA_OFS + 16   // Destination Address (32 Bit)
#define IP_DATA_OFS          ETH_DATA_OFS + 20   // Frame Data (if no options)
#define IP_HEADER_SIZE       20                  // w/o options

#define IP_VER_IHL           0x4500              // IPv4, Header Length = 5x32 bit
#define IP_TOS_D             0x0010              // TOS low delay
#define IP_TOS_T             0x0008              // TOS high throughput
#define IP_TOS_R             0x0004              // TOS high reliability

#define IP_FLAG_DONTFRAG     0x4000              // don't fragment IP frame
#define IP_FLAG_MOREFRAG     0x2000              // more fragments available
#define IP_FRAGOFS_MASK      0x1FFF              // indicates where this fragment belongs

#define PROT_ICMP            1                   // Internet Control Message Protocol
#define PROT_TCP             6                   // Transmission Control Protocol
#define PROT_UDP             17                  // User Datagram Protocol

// ARP definitions
#define ARP_HARDW_OFS        ETH_DATA_OFS + 0    // Hardware address type
#define ARP_PROT_OFS         ETH_DATA_OFS + 2    // Protocol
#define ARP_HLEN_PLEN_OFS    ETH_DATA_OFS + 4    // byte length of each hardw. / prot. address
#define ARP_OPCODE_OFS       ETH_DATA_OFS + 6    // Opcode
#define ARP_SENDER_HA_OFS    ETH_DATA_OFS + 8    // Hardw. address of sender of this packet
#define ARP_SENDER_IP_OFS    ETH_DATA_OFS + 14   // IP address of sender
#define ARP_TARGET_HA_OFS    ETH_DATA_OFS + 18   // Hardw. address of target of this packet
#define ARP_TARGET_IP_OFS    ETH_DATA_OFS + 24   // IP address of target
#define ARP_FRAME_SIZE       28

#define HARDW_ETH10          1                   // hardware-type 10Mbps Ethernet
#define IP_HLEN_PLEN         0x0604              // MAC = 6 byte long, IP = 4 byte long
#define OP_ARP_REQUEST       1                   // operations for ARP-frames
#define OP_ARP_ANSWER        2

// ICMP definitions
#define ICMP_TYPE_CODE_OFS   IP_DATA_OFS + 0     // type of message
#define ICMP_CHKSUM_OFS      IP_DATA_OFS + 2     // checksum of ICMP-message (16 bit)
#define ICMP_DATA_OFS        IP_DATA_OFS + 4
#define ICMP_HEADER_SIZE     4

#define ICMP_ECHO            8                   // message is an echo request
#define ICMP_ECHO_REPLY      0                   // message is an echo reply

// TCP layer definitions
#define TCP_SRCPORT_OFS      IP_DATA_OFS + 0     // Source Port (16 bit)
#define TCP_DESTPORT_OFS     IP_DATA_OFS + 2     // Destination Port (16 bit)
#define TCP_SEQNR_OFS        IP_DATA_OFS + 4     // Sequence Number (32 bit)
#define TCP_ACKNR_OFS        IP_DATA_OFS + 8     // Acknowledge Number (32 bit)
#define TCP_DATA_CODE_OFS    IP_DATA_OFS + 12    // Data Offset and Control Bits (16 bit)
#define TCP_WINDOW_OFS       IP_DATA_OFS + 14    // Window Size (16 bit)
#define TCP_CHKSUM_OFS       IP_DATA_OFS + 16    // CheKSUM_OFS       IP_DATA_OFS + 16    // CheOFS       IP_DATA_OFS + 18    // Urgent Pointer (16 bit)
#define TCP_DATA_OFS         IP_DATA_OFS + 20    // Frame Data (if no options)
#define TCP_HEADER_SIZE      20                  // size w/o options

#define DATA_OFS_MASK        0xF000              // number of 32 bit words in the TCP Header

#define TCP_CODE_FIN         0x0001
#define TCP_CODE_SYN         0x0002
#define TCP_CODE_RST         0x0004
#define TCP_CODE_PSH         0x0008
#define TCP_CODE_ACK         0x0010
#define TCP_CODE_URG         0x0020

#define TCP_OPT_MSS          0x0204              // Type 2, Option Length 4 (Max. Segment Size)
#define TCP_OPT_MSS_SIZE     4

// define some TCP standard-ports, useful for testing...
#define TCP_PORT_ECHO        7                   // echo
#define TCP_PORT_DISCARD     9                   // discard
#define TCP_PORT_DAYTIME     13                  // daytime
#define TCP_PORT_QOTD        17                  // quote of the day
#define TCP_PORT_CHARGEN     19                  // character generator
#define TCP_PORT_HTTP        80            
extern "C" unsigned int CalcChecksum(void *, unsigned int , unsigned char);

#define SWAPB(Word)                 ((unsigned int)((Word) << 8) | ((Word) >> 8))


/*
**************************************************************************
Function: udp_sum_calc()
Description: Calculate UDP checksum
***************************************************************************
*/
typedef unsigned short u16;
typedef unsigned long u32;

//u16 udp_sum_calc(u16 len_udp, u16 src_addr[],u16 dest_addr[], BOOL padding, u16 buff[])
extern "C" u16 udp_sum_calc(u16 len_udp, unsigned char * src_addr,unsigned char * dest_addr, char padding, unsigned char * ubuff)
{
u16 prot_udp=17;
u16 padd=0;
u16 word16;
u32 sum;
u16 i;	
	
	// Find out if the length of data is even or odd number. If odd,
	// add a padding byte = 0 at the end of packet
  //	if (padding&1==1)
	
		if ((padding&1==1)&& (len_udp&1==1) )
	{
		padd=1;
		ubuff[len_udp]=0;
	}
	
	//initialize sum to zero
	sum=0;
	
	// make 16 bit words out of every two adjacent 8 bit words and 
	// calculate the sum of all 16 vit words
	for (i=0;i<len_udp+padd;i=i+2){
		word16 =(((u16)ubuff[i]<<8)&0xFF00)+((u16)ubuff[i+1]&0xFF);
		sum = sum + (unsigned long)word16;
	}	
	// add the UDP pseudo header which contains the IP source and destinationn addresses
	for (i=0;i<4;i=i+2){
		word16 =(((u16)src_addr[i]<<8)&0xFF00)+((u16)src_addr[i+1]&0xFF);
		sum=sum+word16;	
	}
	for (i=0;i<4;i=i+2){
		word16 =(((u16)dest_addr[i]<<8)&0xFF00)+((u16)dest_addr[i+1]&0xFF);
		sum=sum+word16; 	
	}
	// the protocol number and the length of the UDP packet
	sum = sum + prot_udp + len_udp;

	// keep only the last 16 bits of the 32 bit calculated sum and add the carries
    	while (sum>>16)
		sum = (sum & 0xFFFF)+(sum >> 16);
		
	// Take the one's complement of sum
	sum = ~sum;

return ((u16) sum);
}


/*
**************************************************************************
Function: ip_sum_calc
Description: Calculate the 16 bit IP sum.
***************************************************************************
*/
//typedef unsigned short u16;
//typedef unsigned long u32;

//u16 ip_sum_calc(u16 len_ip_header, u16 buff[])
extern "C" u16 ip_sum_calc(u16 len_ip_header,unsigned char buff[])
{

u16 word16;
u32 sum=0;
u16 i;
    
	// make 16 bit words out of every two adjacent 8 bit words in the packet
	// and add them up
	for (i=0;i<len_ip_header;i=i+2){
		word16 =(((u16)buff[i]<<8)&0xFF00)+((u16)buff[i+1]&0xFF);
		sum = sum + (u32) word16;	
	}
	
	// take only 16 bits out of the 32 bit sum and add up the carries
	while (sum>>16)
	  sum = (sum & 0xFFFF)+(sum >> 16);

	// one's complement the result
	sum = ~sum;
	
return ((u16) sum);
}




extern "C" void	SendTrap(unsigned char num)
{

  static char tbuffT[200];
  static char netdest[6];
  unsigned int header_check;
  unsigned int udp_check;

  
  netdest[0] = 0xff;
  netdest[1] = 0xff;
  netdest[2] = 0xff;
  netdest[3] = 0xff;
  netdest[4] = 0xff;
  netdest[5] = 0xff;

  tbuffT[0] = 	HEADER_LENGTH;
  tbuffT[1] = 	SERVICES;
  tbuffT[2] = 	TOTAL_LENGTH1;  
  tbuffT[3] = 	TOTAL_LENGTH2;
  tbuffT[4] = 	IDENTIFICATION1;  
  tbuffT[5] = 	IDENTIFICATION2;
  tbuffT[6] = 	FLAGS1;  
  tbuffT[7] = 	FLAGS2;
  tbuffT[8] = 	TIMETOLIVE;
  tbuffT[9] = 	PROTUDP;
//  header_check = CalcChecksum(&tbuffT, TCP_HEADER_SIZE, 0);
 // header_check = CalcChecksum(&tbuffT, TCP_HEADER_SIZE, 1);	 
//  header_check = CalcChecksum(&tbuffT, 10, 0); // tbuffT[10] = 	HEADERCHS1;
//  tbuffT[11] = 	HEADERCHS2;
  tbuffT[10] = 	0; //header_check >> 8;
  tbuffT[11] = 	0; //(unsigned char)header_check;
  tbuffT[12] = 	SIP0;
  tbuffT[13] = 	SIP1;
  tbuffT[14] = 	SIP2;
  tbuffT[15] = 	SIP3;
  tbuffT[16] = 	DIP0;
  tbuffT[17] = 	DIP1;
  tbuffT[18] = 	DIP2;
  tbuffT[19] = 	DIP3;
  tbuffT[20] = 	SRCPORT1;
  tbuffT[21] = 	SRCPORT2;
  tbuffT[22] = 	DSTPORT1;
  tbuffT[23] = 	DSTPORT2;
  tbuffT[24] = 	LEN1;
  tbuffT[25] = 	LEN2;
  tbuffT[26] = 	0;
  tbuffT[27] = 	0;


 // tbuffT[26] = 	CHECK1;
//  tbuffT[27] = 	CHECK2;

  tbuffT[28] = 	SNMP1;
  tbuffT[29] = 	SNMP2;
  tbuffT[30] = 	SNMPV1;
  tbuffT[31] = 	SNMPV2;
  tbuffT[32] = 	SNMPV3;
  tbuffT[33] = 	SNMPCM1;
  tbuffT[34] = 	SNMPCM2;
  tbuffT[35] =	SNMPS1; 
  tbuffT[36] =	SNMPS2; 
  tbuffT[37] =	SNMPS3; 
  tbuffT[38] =	SNMPS4; 
  tbuffT[39] =	SNMPS5; 
  tbuffT[40] =	SNMPS6; 
  tbuffT[41] =	PDUTYPE1; 
  tbuffT[42] =	PDUTYPE2; 

  tbuffT[43] =	ENTERPRISE1;
  tbuffT[44] =	ENTERPRISE2;
  tbuffT[45] =	ENTERPRISE3;
  tbuffT[46] =	ENTERPRISE4;
  tbuffT[47] =	ENTERPRISE5;
  tbuffT[48] =	ENTERPRISE6;
  tbuffT[49] =	ENTERPRISE7;
  tbuffT[50] =	ENTERPRISE8;
  tbuffT[51] =	ENTERPRISE9;
  tbuffT[52] =	ENTERPRISE10;

  tbuffT[53] =	AGADDRESS1;
  tbuffT[54] =	AGADDRESS2;
  tbuffT[55] =	AGADDRESS3;
  tbuffT[56] =	AGADDRESS4;
  tbuffT[57] =	AGADDRESS5;
  tbuffT[58] =	AGADDRESS6;

  tbuffT[59] =	TRAPTYPE1;
  tbuffT[60] =	TRAPTYPE2;
  tbuffT[61] =	TRAPTYPE3;

  tbuffT[62] =	STRAPTYPE1;
  tbuffT[63] =	STRAPTYPE2;
  tbuffT[64] =	STRAPTYPE3;

  tbuffT[65] =	TIMESTAMP1;
  tbuffT[66] =	TIMESTAMP2;
  tbuffT[67] =	TIMESTAMP3;
  tbuffT[68] =	TIMESTAMP4;
  tbuffT[69] =	TIMESTAMP5;
  tbuffT[70] =	TIMESTAMP6;

 tbuffT[71] =	OID1;
 tbuffT[72] =	OID2;
 tbuffT[73] =	OID3;
 tbuffT[74] =	OID4;
 tbuffT[75] =	OID5;
 tbuffT[76] =	OID6;
 tbuffT[77] =	OID7;
 tbuffT[78] =	OID8;
 tbuffT[79] =	OID9;
 tbuffT[80] =	OID10;
 tbuffT[81] =	OID11;
 tbuffT[82] =	OID12;
 tbuffT[83] =	OID13;
 tbuffT[84] =	OID14;
 tbuffT[85] =	OID15;
 tbuffT[86] =	OID16;
 tbuffT[87] =	OID17;


 tbuffT[88] =	VAL1;
 tbuffT[89] =	VAL2;
 tbuffT[90] =	VAL3;



// header_check = CalcChecksum(&tbuffT, (TCP_HEADER_SIZE >> 1), 0); // tbuffT[10] = 	HEADERCHS1;
 
//  u16 * buff = (u16 *)&tbuffT[0];
 // char * buff;
 // buff = &tbuffT;
 header_check = ip_sum_calc(TCP_HEADER_SIZE, tbuffT);
// header_check = ip_sum_calc((TCP_HEADER_SIZE >> 1),buff);
 tbuffT[10] = 	header_check >> 8;
 tbuffT[11] = 	(unsigned char)header_check;

// udp_check =  udp_sum_calc(u16 len_udp, u16 src_addr[],u16 dest_addr[], BOOL padding, u16 buff[])
 
 u16 len_udp = (LEN1 << 8) + LEN2;
 udp_check =  udp_sum_calc( len_udp, &tbuffT[12],&tbuffT[16], 1, &tbuffT[20]);


  tbuffT[26] = 	udp_check >> 8;
#ifndef BAD_CHECKSUM
  tbuffT[27] = 	(unsigned char)udp_check;
#else
  tbuffT[27] = 	(unsigned char)(udp_check + 1);
#endif



  TRAP_Start_Transmit(tbuffT, netdest, 91);
}


unsigned int __swap_bytes(unsigned int swb)
{
	unsigned int tmp = swb & 0xff;
	swb >>= 8;
	swb |= tmp << 8; 
	
//test
return swb;
}
/*
const unsigned int MyIP[] =                      // "MYIP1.MYIP2.MYIP3.MYIP4"
{
  MYIP_1 + (unsigned int)(MYIP_2 << 8),
  MYIP_3 + (unsigned int)(MYIP_4 << 8)
};
*/

unsigned int CalcChecksum(void *Start, unsigned int Count, unsigned char IsTCP)
{
   unsigned long Sum = 0l;
 // unsigned char *pStart = Start;
  unsigned char *pStart = Start;
  unsigned char MyIP[] =                      // "MYIP1.MYIP2.MYIP3.MYIP4"
{
  SIP0 + (unsigned int)(SIP1 << 8),
  SIP2 + (unsigned int)(SIP3 << 8)
};

unsigned int RemoteIP[] =                      // "MYIP1.MYIP2.MYIP3.MYIP4"
{
  DIP0 + (unsigned int)(DIP1 << 8),
  DIP2 + (unsigned int)(DIP3 << 8)
};



   
  if (IsTCP)
  {                                              // if we've a TCP frame...
    Sum += MyIP[0];                              // ...include TCP pseudo-header
    Sum += MyIP[1];
    Sum += RemoteIP[0];
    Sum += RemoteIP[1];
    Sum += __swap_bytes(Count);                  // TCP header length plus data length
 //   Sum += SWAPB(PROT_TCP);//6 - i make
    Sum +=  __swap_bytes(PROT_TCP);//6 - i make
//	Sum += SWAPB(6);// 6 - standart  
	}
	
 //test
  while (Count> 1)                              // sum words
  {                            
    Sum += *pStart++;
    Count -= 2;
  //  Sum += (*(unsigned char *)pStart++) & 0xff;
  //	 Count -= 1;
  }

  if (Count)                                     // add left-over byte, if any
 //   Sum += *(unsigned char *)pStart;
    Sum += (*(unsigned char *)pStart) & 0xff; //my
  
  while (Sum >> 16)                              // fold 32-bit sum to 16 bits
    Sum = (Sum & 0xFFFF) + (Sum >> 16);
  
  return ~Sum;
}


#endif // TRAP_ENABLED

/*
**  rand() -- generate 2**31-2 random numbers
**
**  public domain by Ray Gardner
**  (Contributed to MetaWare by: Tom Evans, Tennyson Technology.)
** 
**  based on "Random Number Generators: Good Ones Are Hard to Find",
**  S.K. Park and K.W. Miller, Communications of the ACM 31:10 (Oct 1988),
**  and "Two Fast Implementations of the 'Minimal Standard' Random
**  Number Generator", David G. Carta, Comm. ACM 33, 1 (Jan 1990), p. 87-88
**
**  linear congruential generator f(z) = 16807 z mod (2 ** 31 - 1)
**
**  uses L. Schrage's method to avoid overflow problems
*/

#define a 16807         /* multiplier */
#define m 2147483647L   /* 2**31 - 1 */
#define q 127773L       /* m div a */
#define r 2836          /* m mod a */


static int randomnum = 1;

int my_rand(void) {                   /* return next random long */
    unsigned int lo, hi;
	if(!randomnum) randomnum = 1;
    lo = a * (long)(randomnum & 0xFFFF);
    hi = a * (long)((unsigned long)randomnum >> 16);
    lo += (hi & 0x7FFF) << 16;
    if (lo > m) {
        lo &= m;
        ++lo;
        }
    lo += hi >> 15;
    if (lo > m) {
        lo &= m;
        ++lo;
        }
    randomnum = (long) lo;

    return randomnum;
    }

#ifdef LOAD_EXT_MODEM
//A1 - MOSI (data)
//A2 - sclk
//A3 - cs0
//
//#define  DATA_SIZE_EXTMODEM (39)

extern "C" void  LoadByteExt(unsigned char * pbyte)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
  pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 
  unsigned char mask = 0x80;
  for (long i = 0; i < 8; i++ )
  {
  delay_mcs(10l);
   pio_ptra->CODR = MASK_BIT_2;	//clock to zero
  if(*pbyte & mask) //bit is 1
   {
	pio_ptra->SODR = MASK_BIT_1;	  //data to 1
   }
   else
   {
	pio_ptra->CODR = MASK_BIT_1;	  //data to 1
   }
   delay_mcs(10l);
    pio_ptra->SODR = MASK_BIT_2;	//clock to one
    mask >>= 1;
  }
     pio_ptra->CODR = MASK_BIT_2;	//clock to zero
}



extern "C" void  LoadTwoBytes(unsigned char * b1, unsigned char * b2)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
  pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
 // pio_ptrc->SODR = MASK_BIT_11;
  pio_ptra->SODR = MASK_BIT_3;		// in pult maked inversion
  pio_ptra->CODR = MASK_BIT_2;	//clock to zero
  delay_mcs(100l); //need wait of 64 system cyckles
  pio_ptra->CODR = MASK_BIT_3;		// in pult maked inversion
  LoadByteExt(b1);
  LoadByteExt(b2);
 // delay_mcs(10000l); //need wait of 64 system cyckles
  pio_ptra->SODR = MASK_BIT_3;		// in pult maked inversion
  delay_mcs(100l); //need wait of 64 system cyckles
}



extern "C" void	 LoadDataExtModem(void)
{
 unsigned char  * pDataExtModem;
 pDataExtModem =  (unsigned char *)(NVRAM_BASE);
 unsigned char t1 = 0x55;
 unsigned char t2 = 0x0f;

 for(long i = 0; i < DATA_SIZE_EXTMODEM; i++ )
 {
  LoadTwoBytes((unsigned char *)&i , pDataExtModem++);
 //  LoadTwoBytes((unsigned char *)&t1 ,(unsigned char *)&t2);
 }
}




extern "C" void	 LoadExtModem(void)
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   LoadDataExtModem();
}

#endif // LOAD_EXT_MODEM

extern "C" unsigned long GetTestMode(void)
{
return (unsigned long)TestMode.Value;
}

extern "C" void SetTestMode(unsigned long set)
{
  TestMode.Value = set;
  TestMode.ChangingValue = TestMode.Value;
}

#ifdef PROG_PRM_PCH

extern "C" void add_char_TCP_buff(unsigned char tch)
{
      if(buffer_rad_T_len >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_len = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;

}


//ChkFrq(&IPBuff[0]

#ifdef PROG_PRM_PCH_L_61
#ifndef	 PROG_PRM_PCH_SPI_ETH_UART
#ifndef	 PROG_PUPM3_1


extern "C" unsigned char GetType(char *);
extern "C" unsigned long GetFrq(char *);


extern "C" unsigned char ChkFrq(char *IPBuff)
{ 
  unsigned char ret = 0;
  unsigned char type = GetType(IPBuff);
  unsigned long frg = GetFrq(IPBuff);
//  unsigned long frg = 700000l;	//t



  switch (type)
  {
    case 0 :	if((frg >= 177000) && (frg <= 265000)) ret = 1;	break;
    case 1 :	if((frg >= 265000) && (frg <= 401000)) ret = 1;		break;
    case 2 :	if((frg >= 26000)  && (frg <= 177000)) ret = 1;		break;
    case 3 :	if((frg >= 401000) && (frg <= 600000)) ret = 1;		break;
    case 0x80 :	if((frg >= 70000)   && (frg <= 177000)) ret = 1;	break;	  //step in 1 MHz
    case 0x81 :	if((frg >= 177000)  && (frg <= 265000)) ret = 1;	break;	  //step in 1 MHz
    case 0x82 :	if((frg >= 265000)  && (frg <= 400000)) ret = 1;	break;	  //step in 1 MHz
    case 0x83 :	if((frg >= 400000)  && (frg <= 600000)) ret = 1;	break;	  //step in 1 MHz
    case 0xC0 :	if((frg >= 233000)  && (frg <= 294000)) ret = 1;	break;	  //step in 1 MHz
    case 0xC1 :	if((frg >= 380000)  && (frg <= 491000)) ret = 1;	break;	  //step in 1 MHz
    case 0xC7 :	if((frg >= 590000)  && (frg <= 710000)) ret = 1;	break;	  //step in 1 MHz
    case 0xCB :	if((frg >= 720000)  && (frg <= 900000)) ret = 1;	break;	  //step in 1 MHz
    case 0xCF :	if((frg >= 900000)  && (frg <= 1100000)) ret = 1;	break;	  //step in 1 MHz
  }


#ifdef MAKET_PLATA

 printfpd("\n\r type: 0x%02X", type);
  printfpd(" frg: %d", frg);
   printfpd(" ret: %d", ret);

   ret = 1;

   printfpd(" ret for debug : %d", ret);



#endif


 #ifdef	 PROG_PRM_PCH_SPI_NOXIL_ETH 

 ret = 1; // no check freq temporary

 #endif

 return ret;
}


#endif
#endif
#endif

extern "C" void ParseTCP(char *IPBuff, unsigned long len)
{ 
//static int cnt;
//cnt++;
//printfpd(" %d ", cnt);   //t
//return;	  //t


#ifndef  PROG_PRM_PCH_SPI
#ifndef  PROG_PRM_PCH_N
   // timerun = time1;
	breakflag = 0;
	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending

  //	message = 1;


//printf("\n\r ParseTCP");

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test
#ifdef PROG_PRM_PCH_C
#ifndef	MAKET_PLATA
#ifdef PROG_PRM_PCH_S

#ifndef PROG_PUPM2
//#ifndef PROG_PUPM3_1
//150414 if(start1 | start2 | start3 | start4 | start5 | start6)
if(0) //150414
#else
#ifndef PROG_PUPM3_1
 if(start1  | start4)

#else
 // if(start1  | start4 | start6)
  if(0)
//endif
#endif


#endif

#else  // PROG_PRM_PCH_S
  if(start1 | start2 | start3)
#endif // PROG_PRM_PCH_S
 {
	 /*
  	switch(IPBuff[0])
	{
		case 1: add_char_TCP_buff(TYPE_AUTO);       break;
		case 2: add_char_TCP_buff(TYPE_RUN_OK);     break;
		case 3: add_char_TCP_buff(TYPE_RUN_OK);	    break;
		case 4:	add_char_TCP_buff(TYPE_STATUS);     break;
		case 6:	add_char_TCP_buff(CODE_RPU_STATE);  break;
		case 7:	add_char_TCP_buff(TYPE_RUN_OK);     break;
		case 8:	add_char_TCP_buff(REQUEST_SCAN);    break;
		case 9:	add_char_TCP_buff(TYPE_RUN_9);  	break;
		case 0xA:  add_char_TCP_buff(TYPE_RUN_9);   break;
		default :  add_char_TCP_buff(TYPE_AUTO);

	}
	  */


	 //	 add_char_TCP_buff(TYPE_AUTO);
	 	 for(long i = 0; i < 45; i++)
	 	 {
	   	 //	add_char_TCP_buff(unEmb2TypeVer.byte[i]);
		 	add_char_TCP_buff('?');
	 	 } 
 	 return;
}


		SetPower(IPBuff[1]);
#endif		
#endif //PROG_PRM_PCH_C

	//   SetPower(IPBuff[1]);//t
	// 	printfp("parse");


#ifdef MAKET_PLATA

 printfpd("\n\r Parse TCP commmand: 0x%02X",IPBuff[0]);
 printfpd(" 0x%02X",IPBuff[1]);
 printfpd(" 0x%02X",IPBuff[2]);
 printfpd(" 0x%02X",IPBuff[3]);
 printfpd(" 0x%02X",IPBuff[4]);
 printfpd(" 0x%02X",IPBuff[5]);
 

#endif

    switch(IPBuff[0])
	{
		case 1:   ParseCommand1();        break;
		case 2:	
#ifndef PROG_PUPM3_1

		  		 if(!ChkFrq(&IPBuff[0])) chkflag = 0;
				  else { chkflag = 1;	ParseCommand2(IPBuff); 	}
#else
				  ParseCommand2(IPBuff); 
#endif				  
				  	
		 								  break;
	
		case 3:	 
#ifndef PROG_PUPM3_1
	
		  if(IPBuff[2] > MAX_ATT3) chkflagatt = 0;
				  else { chkflagatt = 1;	ParseCommand3(IPBuff); 	}	

#else
		 			 ParseCommand3(IPBuff);				
#endif		 							
		 							
		 								  break;

	
	
 //		case 3:	  ParseCommand3(IPBuff);  break;
		case 4:	  ParseCommand4(IPBuff);  break;
		case 6:	  ParseCommand6(IPBuff);  break;
		case 7:	  ParseCommand7(IPBuff);  break;
		case 8:	  ParseCommand8(IPBuff);  break;
		case 9:	  ParseCommand9(IPBuff);  break;
		case 10:  ParseCommand10(IPBuff);  break;

//161031		case 0xB: ParseCommand11(IPBuff); break;
		case 0xB:
#ifndef PROG_PUPM3_1
	
			   if(IPBuff[2] > MAX_ATTB) chkflagattb = 0;
				  else { chkflagattb = 1;	ParseCommand11(IPBuff); 	}	

#else
			ParseCommand11(IPBuff); 	
#endif
		 								  break;


//t #ifdef PROG_PRM_PCH_L_61
		case 0xC: ParseCommand12(IPBuff); break;
		case 0xD: ParseCommand13(IPBuff); break;
		case 0xE: ParseCommand14(IPBuff); break;
#ifndef PROG_PUPM2
		case 0xF: ParseCommand15(IPBuff); break;
#endif
		case 0x1E: ParseCommand30(IPBuff); break;

		case 0x1F: ParseCommand31(IPBuff);break;
		case 0x20: ParseCommand32(IPBuff); break;
		case 0x21: ParseCommand33(IPBuff); break;
	//	case 0x22: ParseCommand34(IPBuff); break;

//t #endif // PROG_PRM_PCH_L_61



		default : break;
	}

  //	 return; //for test!!!!!!!!!!!!!!!!!!!!

 //	 return; //for test
#ifndef PROG_PUPM2
//130319 	if(GetTestMode() == 0x50)  return;
#endif

	if(GetTestMode() == 0x5A)  return;
	if(GetTestMode() == 0x5D)  return;
#ifdef TEST_RECEIVE
	return;
#endif // TEST_RECEIVE


    timerun = time1;
  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
	 
	while((time1-timerun) < timewait)
	{
 //	  if(breakflag) break;
 	  if((breakflag) && (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  if((breakflag) || (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  message++; 
 	  PRM_PCH();
	}
	 
	 if((unsigned char)IPBuff[0] == (unsigned char)2)	//freq
	 {
	  /*
	  timerun = time1;
  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
	 
	while((time1-timerun) < 20)		//add delay 2 ms
	{
  	  PRM_PCH();
	}
	*/	
	
	   //	 if(!ChkFrq(&IPBuff[0])) breakflag = 0;  //161021
#ifndef PROG_PUPM3_1
   	   if(chkflag)
#else
	   if(1)
#endif
  	   {
	   	   if(breakflag)
		   {
			   add_char_TCP_buff(TYPE_RUN_OK);
			   add_char_TCP_buff(IPBuff[1]);
	 	       add_char_TCP_buff(FREQ_CODE);


		   }
		   else
		   {
	  	      SetFreqToZero(IPBuff[1]);
	          SetStatToZero(IPBuff[1]);
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))	 //at start
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
   
		   }
      
      }	  //chkflag
	  else
	  {

 			 add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			//  if(device_found(IPBuff[1]))
			//  {
	 	      add_char_TCP_buff(LOST_CODE);	   //wrong command
		 //	  }
		   //	  else
		  //	  {
			 // add_char_TCP_buff(ALARM_CODE);
		 //	  }



      }
      
      
      
      	   	
	  //	   add_char_TCP_buff(IPBuff[1]);
	  //	   add_char_TCP_buff(FREQ_CODE);
	  return;
	 }

 	if((unsigned char)IPBuff[0] == (unsigned char)3)	//att
	 {
#ifndef PROG_PUPM3_1
	    if(chkflagatt)
#else
	    if(1)
#endif
  	   {

	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(ATT_CODE);
		   }
		   else
		   {
		      SetFreqToZero(IPBuff[1]);
	          SetStatToZero(IPBuff[1]);
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }
    }	  //chkflagatt
	  else
	  {

 			 add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			//  if(device_found(IPBuff[1]))
			//  {
	 	      add_char_TCP_buff(LOST_CODE);	   //wrong command
		 //	  }
		   //	  else
		  //	  {
			 // add_char_TCP_buff(ALARM_CODE);
		 //	  }



      }
		   	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }

#ifdef PROG_PRM_PCH_L_61

	if((unsigned char)IPBuff[0] == (unsigned char)11)	//attb
	 {
#ifndef PROG_PUPM3_1
	    if(chkflagattb)
#else
		if(1)
#endif
  	   {

	//   if(breakflag)
	  //	   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(ATT_RPU_CODE);
		//   }
	    }	  //chkflagattb
	  else
	  {

 			 add_char_TCP_buff(TYPE_RUN_BAD);
			 add_char_TCP_buff(IPBuff[1]);
			//  if(device_found(IPBuff[1]))
			//  {
	 	      add_char_TCP_buff(LOST_CODE);	   //wrong command
		 //	  }
	  
      }
		   	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }






if((unsigned char)IPBuff[0] == (unsigned char)COMMAND_12)	//att
	 {
	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(COMMAND_12);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }

if((unsigned char)IPBuff[0] == (unsigned char)COMMAND_13)	//att
	 {
	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(COMMAND_13);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }




if((unsigned char)IPBuff[0] == (unsigned char)WRITE_FLASH_COMMAND)	//write flash
	 {

/*
#ifdef TEST_L_61
	 breakflag = 1;
	  WriteStatus1 = 1;
#endif // TEST_L_61
 */
   WriteStatus1 = 1; //now olwais 1


	   if(breakflag)
		   {

 if(GetTestMode() == 0x50)
			{
			//	printfp("\n\rbreakflag - ok");
			 //	printfpd("\n\r %d", IPBuff[1]);
		  
			}

			  switch(IPBuff[1])
			  {
				  case 1:  if(WriteStatus1)
				   			{

         if(GetTestMode() == 0x50)
			{
			//	printfp("WriteStatus1 - ok");
		  
			}

			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{

				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
		   		 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 2:  if(WriteStatus2)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
			 	 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 3:  if(WriteStatus3)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				   				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 4:  if(WriteStatus4)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 	  			add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 5:  if(WriteStatus5)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 6:  if(WriteStatus6)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  		 			add_char_TCP_buff(IPBuff[1]);
				 	 			add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;



				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				  				add_char_TCP_buff(LOST_CODE);		  //can be changed
       //     if(GetTestMode() == 0x50)
		//	{
		//		printfp("some not ok");
		  
		//	}


			  }
		 //	  add_char_TCP_buff(WRITE_FLASH_COMMAND);

		   }
		   else
		   {
		//   printfp("\n\rbreakflag - bad");

			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);

 return;
	 }


if((unsigned char)IPBuff[0] == (unsigned char)READ_FLASH_COMMAND)	//write flash
	 {
	/*
#ifdef TEST_L_61
	 breakflag = 1;
	 ReadStatus1[0] = 1;
     ReadStatus1[1] = 2;
	 ReadStatus1[2] = 3;
#endif // TEST_L_61
		*/
#ifdef TEST_PUPM2

     printfpd("[%02X,", ReadStatus1[0]);
	 printfpd("%02X,", ReadStatus1[1]);
     printfpd("%02X]", ReadStatus1[2]);
#endif

	   if(breakflag)
		   {
#ifdef TEST_PUPM2
	 	   printfp("\n\rbreakflag - ok");
#endif
			  switch(IPBuff[1])
			  {
				  case 1:  	  //	 printfp("\n\r read");
				  				add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus1[0]);
								add_char_TCP_buff(ReadStatus1[1]);
								add_char_TCP_buff(ReadStatus1[2]);
				   	 			break;
				  case 2:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				 //	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus2[0]);
								add_char_TCP_buff(ReadStatus2[1]);
								add_char_TCP_buff(ReadStatus2[2]);
				   	 			break;
				  case 3:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus3[0]);
								add_char_TCP_buff(ReadStatus3[1]);
								add_char_TCP_buff(ReadStatus3[2]);
				   	 			break;
				  case 4:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus4[0]);
								add_char_TCP_buff(ReadStatus4[1]);
								add_char_TCP_buff(ReadStatus4[2]);
				   	 			break;
				  case 5:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus5[0]);
								add_char_TCP_buff(ReadStatus5[1]);
								add_char_TCP_buff(ReadStatus5[2]);
				   	 			break;
				  case 6:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus6[0]);
								add_char_TCP_buff(ReadStatus6[1]);
								add_char_TCP_buff(ReadStatus6[2]);
				   	 			break;
				 
				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed


			  }
		  //	  add_char_TCP_buff(READ_FLASH_COMMAND);

		   }
		   else
		   {
#ifdef TEST_PUPM2
		    printfp("\n\rbreakflag - bad");
#endif
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
 return;

	 }

if((unsigned char)IPBuff[0] == (unsigned char)READ_ATT_COMMAND)	//read att
	 {
   /*
#ifdef TEST_L_61
	 breakflag = 1;
	 ReadAtt1[0] = 1;
     ReadAtt1[1] = 2;
	 ReadAtt1[2] = 3;
#endif // TEST_L_61
	   */
	   if(breakflag)
		   {
			  switch(IPBuff[1])
			  {
				  case 1:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			  //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt1[0]);
								add_char_TCP_buff(ReadAtt1[1]);
								add_char_TCP_buff(ReadAtt1[2]);
				   	 			break;
				  case 2:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			  //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt2[0]);
								add_char_TCP_buff(ReadAtt2[1]);
								add_char_TCP_buff(ReadAtt2[2]);
				   	 			break;
				  case 3:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt3[0]);
								add_char_TCP_buff(ReadAtt3[1]);
								add_char_TCP_buff(ReadAtt3[2]);
				   	 			break;
				  case 4:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt4[0]);
								add_char_TCP_buff(ReadAtt4[1]);
								add_char_TCP_buff(ReadAtt4[2]);
				   	 			break;
				  case 5:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt5[0]);
								add_char_TCP_buff(ReadAtt5[1]);
								add_char_TCP_buff(ReadAtt5[2]);
				   	 			break;
				  case 6:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt6[0]);
								add_char_TCP_buff(ReadAtt6[1]);
								add_char_TCP_buff(ReadAtt6[2]);
				   	 			break;
				 
				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed


			  }
		 //	  add_char_TCP_buff(READ_FLASH_COMMAND);

		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
 return;

	 }


#endif	//prm_pch_c

   
#endif //no PROG_PRM_PCH_N

#else // PROG_PRM_PCH_SPI
//___________________________________________________________________PRM_PCH_SPI>>>
	breakflag = 0;
	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending


#ifdef PROG_PD3
 //  printfp("\n\r Command :");
 //   printfp( IPBuff);
  //	#include "pd3_eth.cpp"
//  Parse_PD3(char *IPBuff, unsigned long len);
	  Parse_PD3(IPBuff,  len);
	  return;
#endif


#ifdef PROG_PRM_PCH_SPI_XIL_ETH
#include "prm300_eth.cpp"
#endif

  //	message = 1;


//printfp("\n\r ParseTCP");

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test


#ifdef STEND_SPI
 //t	 SetSendToSSC(IPBuff, len);	 //need only write to buff
#endif //STEND_SPI
	   /*
    switch(IPBuff[0])
	{
		case 1:   ParseCommand1();        break;
		case 2:	  ParseCommand2(IPBuff);  break;
		case 3:	  ParseCommand3(IPBuff);  break;
		case 4:	  ParseCommand4(IPBuff);  break;
		case 6:	  ParseCommand6(IPBuff);  break;
		case 7:	  ParseCommand7(IPBuff);  break;
		case 8:	  ParseCommand8(IPBuff);  break;
		case 9:	  ParseCommand9(IPBuff);  break;
		case 0xB: ParseCommand11(IPBuff); break;
#ifdef PROG_PRM_PCH_L_61
		case 0xC: ParseCommand12(IPBuff); break;
		case 0xD: ParseCommand13(IPBuff); break;
		case 0xE: ParseCommand14(IPBuff); break;
		case 0x1E: ParseCommand30(IPBuff); break;
		case 0x1F: ParseCommand31(IPBuff); break;
		case 0x20: ParseCommand32(IPBuff); break;
		case 0x21: ParseCommand33(IPBuff); break;

#endif // PROG_PRM_PCH_L_61



		default : break;
	}
			*/
  //	 return; //for test!!!!!!!!!!!!!!!!!!!!

 //	 return; //for test

 	if(GetTestMode() == 0x50)  return;
	if(GetTestMode() == 0x5A)  return;
	if(GetTestMode() == 0x5D)  return;
//#ifdef TEST_RECEIVE
  //	return;
//#endif // TEST_RECEIVE


 //   timerun = time1;
  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
//#ifdef STEND_SPI
//SendSSCBuff(); //need hier	111107
	/*						  //need send oxff and receive old answer or need send command and dann oxff wrom computer!
MakeSendToSSC(IPBuff, len);
#ifndef BACK_TO_SSC
 OperateBuffers_SPI1_stend();
#else
 OperateBuffers_SSC1();
#endif
   */
#ifdef PROG_PRM_PCH_SPI_STEND
MakeSendToSSC(IPBuff, len);
#endif
   timerun = time1;

while((time1-timerun) < (TIME_WAIT_SPI>>1))
	{ }

#ifndef BACK_TO_SSC
#ifdef PROG_PRM_PCH_SPI_STEND
 OperateBuffers_SPI1_stend();
#endif
#else
 OperateBuffers_SSC1();
#endif
#ifdef PROG_PRM_PCH_SPI_STEND

  flag_add_tcp = 1;
#endif

#ifdef PROG_PRM_PCH_SPI_STEND
MakeSendToSSC(IPBuff, len);	 //two times to get ans
#endif

//MakeSendToSSC(IPBuff, len);
     timerun = time1;

//#endif	 
	while((time1-timerun) < (TIME_WAIT_SPI>>1))
	{
 //	  if(breakflag) break;
  //	  if(breakflag)  break;
  //	  if((breakflag) || (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  message++; 
  //t 	  PRM_PCH(); //120120
   //	  test_receive_data_SSC1();
 //  } //t
#ifdef PROG_PRM_PCH_SPI_STEND

#ifndef BACK_TO_SSC
 OperateBuffers_SPI1_stend();
#else
 OperateBuffers_SSC1();
#endif

#endif
 }
	 
//add_char_TCP_buff(1);
//add_char_TCP_buff(2);
//add_char_TCP_buff(3);
//add_char_TCP_buff(4);

// printfp("...finish");
#ifdef PROG_PRM_PCH_SPI_STEND	 
 flag_add_tcp = 0;
#endif

 return;   //temporary ?
	 
	 if((unsigned char)IPBuff[0] == (unsigned char)2)	//freq
	 {
 

	   if(breakflag)
		   {
			   add_char_TCP_buff(TYPE_RUN_OK);
			   add_char_TCP_buff(IPBuff[1]);
	 	       add_char_TCP_buff(FREQ_CODE);


		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }


		   }	
	  //	   add_char_TCP_buff(IPBuff[1]);
	  //	   add_char_TCP_buff(FREQ_CODE);
	  return;
	 }

 	if((unsigned char)IPBuff[0] == (unsigned char)3)	//att
	 {
	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(ATT_CODE);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }

#ifdef PROG_PRM_PCH_L_61

if((unsigned char)IPBuff[0] == (unsigned char)COMMAND_12)	//att
	 {
	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(COMMAND_12);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }

if((unsigned char)IPBuff[0] == (unsigned char)COMMAND_13)	//att
	 {
	   if(breakflag)
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
			  add_char_TCP_buff(IPBuff[1]);
	 	      add_char_TCP_buff(COMMAND_13);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
  return;
	 }




if((unsigned char)IPBuff[0] == (unsigned char)WRITE_FLASH_COMMAND)	//write flash
	 {
#ifdef TEST_L_61
	 breakflag = 1;
	  WriteStatus1 = 1;
#endif // TEST_L_61


	   if(breakflag)
		   {
			  switch(IPBuff[1])
			  {
				  case 1:  if(WriteStatus1)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
		   		 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 2:  if(WriteStatus2)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
			 	 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 3:  if(WriteStatus3)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				   				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 4:  if(WriteStatus4)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 	  			add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 5:  if(WriteStatus5)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;
				  case 6:  if(WriteStatus6)
				   			{
			 	 				add_char_TCP_buff(TYPE_RUN_OK);
			  					add_char_TCP_buff(IPBuff[1]);
			  					add_char_TCP_buff(WRITE_FLASH_COMMAND);
				   			}
				   			else
				   			{
				    			add_char_TCP_buff(TYPE_RUN_BAD);
			  		 			add_char_TCP_buff(IPBuff[1]);
				 	 			add_char_TCP_buff(LOST_CODE);		  //can be changed
				   			}
							 break;



				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				  				add_char_TCP_buff(LOST_CODE);		  //can be changed


			  }
		 //	  add_char_TCP_buff(WRITE_FLASH_COMMAND);

		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);

 return;
	 }


if((unsigned char)IPBuff[0] == (unsigned char)READ_FLASH_COMMAND)	//write flash
	 {
	 /*
#ifdef TEST_L_61
	 breakflag = 1;
	 ReadStatus1[0] = 1;
     ReadStatus1[1] = 2;
	 ReadStatus1[2] = 3;
#endif // TEST_L_61
	   */
	 /*
#ifdef TEST_PUPM2

     printfpd(":%02X,", ReadStatus1[0]);
	 printfpd("%02X,", ReadStatus1[1]);
     printfpd("%02X:", ReadStatus1[2]);
#endif
		*/



	   if(breakflag)
		   {
			  switch(IPBuff[1])
			  {
				  case 1:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus1[0]);
								add_char_TCP_buff(ReadStatus1[1]);
								add_char_TCP_buff(ReadStatus1[2]);
				   	 			break;
				  case 2:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				 //	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus2[0]);
								add_char_TCP_buff(ReadStatus2[1]);
								add_char_TCP_buff(ReadStatus2[2]);
				   	 			break;
				  case 3:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus3[0]);
								add_char_TCP_buff(ReadStatus3[1]);
								add_char_TCP_buff(ReadStatus3[2]);
				   	 			break;
				  case 4:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus4[0]);
								add_char_TCP_buff(ReadStatus4[1]);
								add_char_TCP_buff(ReadStatus4[2]);
				   	 			break;
				  case 5:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus5[0]);
								add_char_TCP_buff(ReadStatus5[1]);
								add_char_TCP_buff(ReadStatus5[2]);
				   	 			break;
				  case 6:  		add_char_TCP_buff(TYPE_RUN_31);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_FLASH_COMMAND);
			  					add_char_TCP_buff(ReadStatus6[0]);
								add_char_TCP_buff(ReadStatus6[1]);
								add_char_TCP_buff(ReadStatus6[2]);
				   	 			break;
				 
				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed


			  }
		  //	  add_char_TCP_buff(READ_FLASH_COMMAND);

		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
 return;

	 }

if((unsigned char)IPBuff[0] == (unsigned char)READ_ATT_COMMAND)	//read att
	 {

#ifdef TEST_L_61
	 breakflag = 1;
	 ReadAtt1[0] = 1;
     ReadAtt1[1] = 2;
	 ReadAtt1[2] = 3;
#endif // TEST_L_61

	   if(breakflag)
		   {
			  switch(IPBuff[1])
			  {
				  case 1:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			  //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt1[0]);
								add_char_TCP_buff(ReadAtt1[1]);
								add_char_TCP_buff(ReadAtt1[2]);
				   	 			break;
				  case 2:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			  //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt2[0]);
								add_char_TCP_buff(ReadAtt2[1]);
								add_char_TCP_buff(ReadAtt2[2]);
				   	 			break;
				  case 3:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt3[0]);
								add_char_TCP_buff(ReadAtt3[1]);
								add_char_TCP_buff(ReadAtt3[2]);
				   	 			break;
				  case 4:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt4[0]);
								add_char_TCP_buff(ReadAtt4[1]);
								add_char_TCP_buff(ReadAtt4[2]);
				   	 			break;
				  case 5:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  				//	add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt5[0]);
								add_char_TCP_buff(ReadAtt5[1]);
								add_char_TCP_buff(ReadAtt5[2]);
				   	 			break;
				  case 6:  		add_char_TCP_buff(TYPE_RUN_32);
			  					add_char_TCP_buff(IPBuff[1]);
			  			   //		add_char_TCP_buff(READ_ATT_COMMAND);
			  					add_char_TCP_buff(ReadAtt6[0]);
								add_char_TCP_buff(ReadAtt6[1]);
								add_char_TCP_buff(ReadAtt6[2]);
				   	 			break;
				 
				 default:		add_char_TCP_buff(TYPE_RUN_BAD);
			  					add_char_TCP_buff(IPBuff[1]);
				 				add_char_TCP_buff(LOST_CODE);		  //can be changed


			  }
		 //	  add_char_TCP_buff(READ_FLASH_COMMAND);

		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
			  add_char_TCP_buff(IPBuff[1]);
			  if(device_found(IPBuff[1]))
			  {
	 	      add_char_TCP_buff(LOST_CODE);
			  }
			  else
			  {
			  add_char_TCP_buff(ALARM_CODE);
			  }
		   }	
 //		   add_char_TCP_buff(IPBuff[1]);
 //	 	   add_char_TCP_buff(ATT_CODE);
 return;

	 }


#endif	//prm_pch_c

   

#endif

}



#endif //PROG_PRM_PCH
//___________________________________________________________________PRM_PCH_SPI<<<<

#ifdef PD_DS

//#include <lfilterbaco.cpp>

extern "C" void add_char_TCP_buff(unsigned char tch)
{
      if(buffer_rad_T_len >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_len = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;

}

extern "C" void ParseTCPPD(char *IPBuff, unsigned long len)
{ 

//#ifndef  PROG_PRM_PCH_N
   // timerun = time1;
 //	breakflag = 0;
 //	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending

  //	message = 1;


//printf("\n\r ParseTCP");

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test

	//   SetPower(IPBuff[1]);//t

    switch(IPBuff[0] + (IPBuff[1] << 8))
	{
	
		case 1:   ParseCommand1();        break;
		case 2:	  ParseCommand2(IPBuff);  break;

	/*
		case 3:	  ParseCommand3(IPBuff);  break;
		case 4:	  ParseCommand4(IPBuff);  break;
		case 5:	  ParseCommand5(IPBuff);  break;
		case 6:	  ParseCommand6(IPBuff);  break;
		case 7:	  ParseCommand7(IPBuff);  break;
		case 8:	  ParseCommand8(IPBuff);  break;
		case 9:	  ParseCommand9(IPBuff);  break;
		case 10:  ParseCommand10(IPBuff);  break;
	*/
		default : break;
	}

}

#endif

#ifdef PROG_STM2UDP

extern "C" void add_char_TCP_buff(unsigned char tch)
{
      if(buffer_rad_T_len >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_len = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;

}

extern "C" void ParseTCPSTM2UDP(char *IPBuff, signed long len)
{ 
 int i = 0;
//#ifndef  PROG_PRM_PCH_N
   // timerun = time1;
 //	breakflag = 0;
 //	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending

  //	message = 1;


 // printfpd("%d",IPBuff[0] );

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test

	//   SetPower(IPBuff[1]);//t

	while(len > 0) {
			printfpd("\n\rbuffer_rad_T_len: %d",buffer_rad_T_len);
			printfpd(" len : %d", len);
    switch(IPBuff[i])
	{
		case 0x01:    ParseCommand1();         len -= 1;  i += 1; break;
		case 0xA0:	len -= 8;  if(len < 0) break;  ParseCommandA0(IPBuff+i);  i += 8; break;
		case 0xA1:	len -= 6;  if(len < 0) break;  ParseCommandA1(IPBuff+i);  i += 6; break;
		case 0xA2:	len -= 6;  if(len < 0) break;  ParseCommandA2(IPBuff+i);  i += 6; break;
		case 0xA3:	len -= 4;  if(len < 0) break;  ParseCommandA3(IPBuff+i);  i += 4; break;
		case 0xA4:	len -= 2;  if(len < 0) break;  ParseCommandA4(IPBuff+i);  i += 2; break;
		case 0xA5:	len -= 4;  if(len < 0) break;  ParseCommandA5(IPBuff+i);  i += 4; break;
		case 0xA6:	len -= 1;  if(len < 0) break;  ParseCommandA6(IPBuff+i);  i += 1; break;
		case 0xA7:	len -= 2;  if(len < 0) break;  ParseCommandA7(IPBuff+i);  i += 2; break;
		default :   len = 0;   break;
	}
  }
}


#endif



#ifdef PROG_BACO

#include <lfilterbaco.cpp>

extern "C" void add_char_TCP_buff(unsigned char tch)
{
      if(buffer_rad_T_len >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_len = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;

}

extern "C" void ParseTCPBACO(char *IPBuff, unsigned long len)
{ 

//#ifndef  PROG_PRM_PCH_N
   // timerun = time1;
 //	breakflag = 0;
 //	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending

  //	message = 1;


//printf("\n\r ParseTCP");

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test

	//   SetPower(IPBuff[1]);//t

    switch(IPBuff[0] + (IPBuff[1] << 8))
	{
		case 1:   ParseCommand1();        break;
		case 2:	  ParseCommand2(IPBuff);  break;
		case 3:	  ParseCommand3(IPBuff);  break;
		case 4:	  ParseCommand4(IPBuff);  break;
		case 5:	  ParseCommand5(IPBuff);  break;
		case 6:	  ParseCommand6(IPBuff);  break;
		case 7:	  ParseCommand7(IPBuff);  break;
		case 8:	  ParseCommand8(IPBuff);  break;
		case 9:	  ParseCommand9(IPBuff);  break;
		case 10:  ParseCommand10(IPBuff);  break;

		default : break;
	}

}

#endif


//___________________________________________________________________DEM
#ifdef PROG_PRM_PCH_DEM

extern "C" void add_char_TCP_buff(unsigned char tch)
{
      if(buffer_rad_T_len >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_len = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_T[buffer_rad_T_len++] = tch;

}

extern "C" void ParseTCPDem(char *IPBuff, unsigned long len)
{ 

//#ifndef  PROG_PRM_PCH_N
   // timerun = time1;
	breakflag = 0;
	timewait =	RUN_TIME;

	buffer_rad_T_len = 0;  //100127 may be not olwais work from	ip sending

  //	message = 1;

  if(GetTestMode() == 0x50)
{
printfpd("\n\r ParseTCP : %d", IPBuff[0]);
}

//_______________________________________________________echo for test
//	  while(len--)
//   {
//      add_char_TCP_buff((unsigned char)(*IPBuff++));
//   }
//________________________________________________________echo for test

	//   SetPower(IPBuff[1]);//t
#ifndef PROG_VNV
    switch(IPBuff[0])
	{
		case 1:   ParseCommand1();        break;
		case 2:	  ParseCommand2(IPBuff);  break;
		case 3:	  ParseCommand3(IPBuff);  break;
		case 4:	  ParseCommand4(IPBuff);  break;
#ifdef  PROG_PRM_PCH_DEM_XIL_CHN
		case 5:	  ParseCommand5(IPBuff);  break;
#endif

#ifdef  PROG_PRM_PCH_DEM_XIL_CHN_DMU4
		case 6:	  ParseCommand6(IPBuff);  break; //test
		case 7:	  ParseCommand7(IPBuff);  break; //decoder
		case 8:	  ParseCommand8(IPBuff);  break; //write ram
		case 9:	  ParseCommand9(IPBuff);  break; //ramtoflash and xilinx
#endif

#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU5  //prm_pch_dem_chn_dmu5.cpp
		case 0x10:	  ParseCommand10(IPBuff);  break; //this is 0x10 = 16(dec)
#endif


		default : break;
	}

  //	 return; //for test!!!!!!!!!!!!!!!!!!!!

 //	 return; //for test

 	if(GetTestMode() == 0x50)  return;
	if(GetTestMode() == 0x5A)  return;
	if(GetTestMode() == 0x5D)  return;
#ifdef TEST_RECEIVE
	return;
#endif // TEST_RECEIVE


    timerun = time1;
  //t	timewait =	RUN_TIME;
 //	 timewait =	LONG_RUN_TIME;
	 
	while((time1-timerun) < timewait)
	{
 //	  if(breakflag) break;
 	  if((breakflag) && (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  if((breakflag) || (timewait != (unsigned long)LONG_RUN_TIME)) break;
  //	  message++; 
 	  PRM_PCH();
	}

#endif //PROG_VNV
 }



#endif //PROG_PRM_PCH_DEM



//___________________________________________________________________

#define MY_SETTED_MAXIMUM	 (100)

extern "C" void ToBufferIP(char *IPBuff, unsigned long len)
{
// _int_disable();	


 rnms_was_used = 1;
#ifndef PROG_STM2UDP
#ifndef PD_DS
#ifndef PROG_BACO
#ifndef PROG_PRM_PCH
#ifndef PROG_PRM_PCH_DEM




//hier may be error!!!!
if(!len) return; //091111
//091218 if (len  > ACT_BUFFER_SIZE) return; //091111

if (len  > (BUFFER_SIZE_T - 1))
{
 len = BUFFER_SIZE_T - 1; //091218
 return; //091111
}

   /*
if (len  > (MY_SETTED_MAXIMUM))
{
 len = MY_SETTED_MAXIMUM; //091218
 return; //091111
}
  */

#ifdef ETH_DEBUG_485E
                        
     printfpd("\n\rans %d> ", time1);                    
     printfpd(" %d ", len);                         
     OperateBuffers_usart0t();
#endif     

//#ifdef TRY_FIND_ERR
//printfpd(">%d", len);
//printf("!!!"); // 100811 FOR HANGING
//delay_mcs(5000);
//delay_mcs(10000);
//delay_mcs(20000);
//delay_mcs(40000);  //after this make restart but not hangt!!!
//  WriteDevId(); // 100811 FOR HANGING

//#endif

//100811 _int_disable();	//100115


#ifdef 	PROG_BMDN6
used_TCP = 1;
#endif

#ifdef 	PROG_COMMUTATOR1
used_TCP = 1;
#endif
#ifdef PROG_PU_M710
used_TCP = 1;
#endif
//hier ethernet going to embrs232

   while(len--)
   {
 //   printf(" %02X", *IPBuff)
    embRS232_rcvbuf_Add((unsigned char)(*IPBuff++));  //101111
//101111	 my_rx_usart0_int((unsigned char)(*IPBuff++)); //101022

   }
// _int_enable(); //100115   NOT CAN ENABLE INTERRUPTS!!!
#endif
#endif
#endif
#endif //PD_DS
#endif

#ifndef PROG_STM2UDP

#ifdef PROG_PRM_PCH
   ParseTCP( IPBuff, len);
#endif

#ifdef PROG_PRM_PCH_DEM
   ParseTCPDem( IPBuff, len);
#endif

#ifdef PROG_BACO
  ParseTCPBACO( IPBuff, len);
#endif


#ifdef PD_DS
    ParseTCPPD( IPBuff, len);
#endif
#else
	 ParseTCPSTM2UDP( IPBuff, len);
#endif

}

 /*

extern "C" void add_char_TCP_buffU(unsigned char tch)
{
      if(buffer_rad_T_lenU >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_lenU = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}
	 	buffer_rad_TU[buffer_rad_T_lenU++] = tch;

}

#define MAX_LEN_SIZE	(50)
extern "C" void MakeLineAns(char* Start, unsigned long len)
{
  if(!len) return;
  if(len > MAX_LEN_SIZE) len = 	MAX_LEN_SIZE;
 //  while(*Start)
     while(len--)
   {
	add_char_TCP_buffU(*Start++);
   }
	add_char_TCP_buffU(0x0D);
	add_char_TCP_buffU(0x0A);
}


#define LINEBUFF_SIZE (50)
extern "C" void MakeAnsUdp()
{
   char LineBuff[LINEBUFF_SIZE];
   sprintf(LineBuff, "TYPE=%s","RX");
   MakeLineAns(LineBuff,7);
   sprintf(LineBuff, "DEV=%s","AGRPU40e");
   MakeLineAns(LineBuff,12);
   sprintf(LineBuff, "RF=%s","2700_40100");
   MakeLineAns(LineBuff,13);
   sprintf(LineBuff, "IF=%d",70);
   MakeLineAns(LineBuff,5);
   sprintf(LineBuff, "IFBW=%d",40);
   MakeLineAns(LineBuff,7);
   sprintf(LineBuff, "ATT1=%s","0_30");
   MakeLineAns(LineBuff,9);
   sprintf(LineBuff, "ATT1STEP=%d",2);
   MakeLineAns(LineBuff,10);
   sprintf(LineBuff, "ATT2=%s","0_30");
   MakeLineAns(LineBuff,9);
   sprintf(LineBuff, "ATT2STEP=%d",2);
   MakeLineAns(LineBuff,10);
   sprintf(LineBuff, "HV=%f2.1",1.0);
   MakeLineAns(LineBuff,6);
  // sprintf(LineBuff, "CV=%f3.2",((float)SOFT_VER / (float)0x100));
 //  sprintf(LineBuff, "CV=%f3.2",3.61);
   sprintf(LineBuff, "CV=%2X.%2X", ((unsigned)SOFT_VER >> 8),((unsigned)SOFT_VER & 0xff) );


   MakeLineAns(LineBuff,8);
   sprintf(LineBuff, "FV=%f2.1", 9.0);
   MakeLineAns(LineBuff,6);
   sprintf(LineBuff, "SN=%l4d",SelfID());
   MakeLineAns(LineBuff,10);
}
 */
//______________________________________________________________


extern "C" void combine_TCP_buff(void *p, unsigned short **sz)
//extern "C" void combine_TCP_buff(void *p, unsigned long *sz)
{
	char *tcp_buff = (char*)p;
	*sz = (unsigned short*)p;
	tcp_buff[2] = 0x83;
	sprintf(
		&tcp_buff[3],
		"TYPE=RX\r\n"
		"DEV=AGRPU40e\r\n"
		"RF=2700_40100\r\n"
		"IF=%d\r\n"
		"IFBW=%d\r\n"
		"ATT1=0_30\r\n"
		"ATT1STEP=%d\r\n"
		"ATT2=0_30\r\n"
		"ATT2STEP=%d\r\n"
		"HV=%2.1f\r\n"
		"CV=%02X.%02X\r\n"
		"FV=%2.1f\r\n"
		"SN=%014d",
		70,
		40,
		2,
		2,
		1.0,
		((unsigned)SOFT_VER >> 8), ((unsigned)SOFT_VER & 0xff),
		9.0,
		SelfID()
	);
	**sz = 2+1+strlen(&tcp_buff[3]);
//	*sz = 2+1+strlen(&tcp_buff[3]);
}

extern "C" void MakeAnsUdp()
{
 //	char tcp_buff[180]; // ÛÍ‡Á‡ÚÂÎ¸ Ì‡ ·ÛÙÂ ‰Îˇ ÓÚÔ‡‚ÍË
    	unsigned short *tcp_sz; // ÛÍ‡Á‡ÚÂÎ¸ Ì‡ ÍÓÎ-‚Ó ·‡ÈÚ ‰Îˇ ÓÚÔ‡‚ÍË
	//	combine_TCP_buff(tcp_buff, &tcp_sz);

		combine_TCP_buff(buffer_rad_TU, &tcp_sz);
		buffer_rad_T_lenU =  (unsigned long)*tcp_sz;

		if(buffer_rad_T_lenU >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_lenU = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}

}



//______________________________________________________________


extern "C" void ToBufferIPU(char *IPBuffU, unsigned long len)
{

if(!len) return; //091111

if (len  > (BUFFER_SIZE_T - 1))
{
 len = BUFFER_SIZE_T - 1; //091218
 return; //091111
}

//hier can parse data and make answer in buffer 
//char buffer_rad_TU[BUFFER_SIZE];
//unsigned long  buffer_rad_T_lenU;

  // while(len--)
  // {
 //   printf(" %02X", *IPBuff)
//need use enover buffer    embRS232_rcvbuf_Add((unsigned char)(*IPBuffU++));  //101111
//101111	 my_rx_usart0_int((unsigned char)(*IPBuff++)); //101022

 //  }
	/*
	add_char_TCP_buffU('T');   //this is buffer fur answer
	add_char_TCP_buffU('E');
	add_char_TCP_buffU('S');
	add_char_TCP_buffU('T');
	*/
   MakeAnsUdp();

}






#ifdef BMD155_ETH

extern "C" void	 InitXilBmdEth()
{
   outportb((unsigned long)(XILINX_CONFIG_ADDRESS1), read_nvram_char((uint_32) (NVRAM_CONFIG_ADDRESS1)));
   outportb((unsigned long)(XILINX_CONFIG_ADDRESS2), read_nvram_char((uint_32) (NVRAM_CONFIG_ADDRESS2)));

}

#endif // BMD155_ETH 

extern "C" void SetIPRem(unsigned long NewIP)
{

				IPAddress.Value = NewIP;
				IPAddress.ChangingValue = NewIP;	

				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.Some  = 1; //some load
			  //	WriteDevId();
			   UsedExp.State.Reg2.bit.WriteId = 1;

				MakeIPAddresses();
}

extern "C"unsigned long GetIPRem(void)
{
  return (unsigned long)IPAddress.Value;
}

#ifdef USE_SOCKETSD
extern "C" void SetIPRemUDP(unsigned long NewIP)
{

				IPAddressUDP.Value = NewIP;
				IPAddressUDP.ChangingValue = NewIP;	

			  //	UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.Some  = 1; //some load
			  UsedExp.State.Reg2.bit.WriteId = 1;
			  //	MakeIPAddresses();
}

extern "C"unsigned long GetIPRemUDP(void)
{
  return (unsigned long)IPAddressUDP.Value;
}




#endif

#ifdef HAVE_GATEWAY
extern "C" void SetNetworkRem(unsigned long NewNetwork)
{

				Network.Value = NewNetwork;
				Network.ChangingValue = NewNetwork;	

				UsedExp.State.Reg2.bit.Network = 1; //changeIP
				UsedExp.State.Reg2.bit.Some  = 1; //some load
				WriteDevId();
}

extern "C"unsigned long GetNetworkRem(void)
{
  return (unsigned long)Network.Value;
}

extern "C" void SetNetMaskRem(unsigned long NewNetMask)
{

				NetMask.Value = NewNetMask;
				NetMask.ChangingValue = NewNetMask;	

				UsedExp.State.Reg2.bit.NetMask = 1; //changeIP
				UsedExp.State.Reg2.bit.Some  = 1; //some load
				WriteDevId();
}

extern "C"unsigned long GetNetMaskRem(void)
{
  return (unsigned long)NetMask.Value;
 // return (unsigned long)DEFAULT_MASK;
}
#else

extern "C" void SetNetworkRem(unsigned long NewNetwork)
{

}

extern "C"unsigned long GetNetworkRem(void)
{
  return 0;
}

extern "C" void SetNetMaskRem(unsigned long NewNetMask)
{
}

extern "C"unsigned long GetNetMaskRem(void)
{
  return 0;
}





#endif 



extern "C" void LedOn()
{
#define PIN_ADDR (1 << 13)
 AT91RM9200_PIO_REG_STRUCT_PTR pio_ptr1;

   pio_ptr1 = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   pio_ptr1->SODR = PIN_ADDR;
}

extern "C" void LedOff()
{
#define PIN_ADDR (1 << 13)
 AT91RM9200_PIO_REG_STRUCT_PTR pio_ptr1;

   pio_ptr1 = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   pio_ptr1->CODR = PIN_ADDR;
}

#ifdef	 PROG_KTVM
#define  KTVM_PLL_ADDR1 (0x300000E2)
#define  KTVM_PLL_ADDR2 (0x300000E1)
#define  I2C_WRITE_COMMAND (0xB8)
#define  I2C_READ_COMMAND (0xB9)

#define  DELAY_I2C (2l)

extern "C" void SetPLLKTVM()
{
unsigned char * pPLL;
//______________________________________________
 pPLL = (unsigned char *)(KTVM_PLL_ADDR1);
 *pPLL = 0x96;
 delay_mcs(2l);
 *pPLL = 0xC;
 delay_mcs(2l);
 pPLL = (unsigned char *)(KTVM_PLL_ADDR2);
  *pPLL = 0xFF;
 delay_mcs(2l);
 *pPLL = 0x0;
 delay_mcs(2l);
//______________________________________
pPLL = (unsigned char *)(KTVM_PLL_ADDR1);
 *pPLL = 0x72;
 delay_mcs(2l);
 *pPLL = 0x04;
 delay_mcs(2l);
 pPLL = (unsigned char *)(KTVM_PLL_ADDR2);
  *pPLL = 0xFF;
 delay_mcs(2l);
 *pPLL = 0x0;
 delay_mcs(2l);
}




extern "C" void   MakeStartCondition()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->MDER = MASK_BIT_8 ;	//enable on data line multidrive!
  pio_ptr->SODR = MASK_BIT_8 ;	//data to one!
  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  pio_ptr->CODR = MASK_BIT_8 ;	//data to zero!
  delay_mcs(DELAY_I2C);
//_______________________________________________
  pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
  delay_mcs(DELAY_I2C);
}

extern "C" void   MakeStopCondition()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->CODR = MASK_BIT_8 ;	//data to zero!
  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  pio_ptr->SODR = MASK_BIT_8 ;	//data to one!
  delay_mcs(DELAY_I2C);
}

extern "C" void  SendI2CByte(unsigned char I2CData)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

	unsigned char mask;
	mask = 0x80;
	for(long i = 0; i <8; i++)
	{
	 if(mask & I2CData){ pio_ptr->SODR = MASK_BIT_8;}	//data to one!
	 else { pio_ptr->CODR = MASK_BIT_8;}  //data to zero!
	 delay_mcs(DELAY_I2C);
	 pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
	 delay_mcs(DELAY_I2C);
	 pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
	 delay_mcs(DELAY_I2C);
	 mask >>= 1;
	 }
}

extern "C" unsigned char ReceiveACK(void)
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   unsigned long status;
   unsigned char ret;

   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0); //sda to input
  delay_mcs(DELAY_I2C);

  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  status = pio_ptr->PDSR; //wait line init hier zero
  
  if(status & MASK_BIT_8) {ret = 0;} //no ACK
  else {ret = 1;}  //ACK ok

  pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda to output
  delay_mcs(DELAY_I2C);

 return ret;
} 




extern "C" unsigned char SendDataI2C(unsigned char Subaddr, unsigned char I2CData)
{

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl

 MakeStartCondition();
 SendI2CByte(I2C_WRITE_COMMAND);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(Subaddr);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(I2CData);
 if(!ReceiveACK()) return 0; //not have ack
 MakeStopCondition();
 return 1;
}

extern "C" unsigned char LoadCoder(unsigned char variant)
{
//  printf("\n\r LoadCoder : %d", variant);


 unsigned char ret = 1;
 unsigned long i;
 unsigned char I2C_A[18]  = {0xEE,0xEA,0xE9,0xE8,0xE0,0xEE,0x00,0x05,0x06,0x33,0x34,0x35,0x36,0x37,0x59,0x0D,0x7f,0x39};
 unsigned char I2C_D1[18] = {0x01,0xB0,0x00,0x63,0x01,0x00,0x00,0x00,0x40,0x40,0x15,0x3E,0xA1,0xfd,0x07,0xa4,0x01,0x01};
 unsigned char I2C_D2[18] = {0x01,0xB0,0x00,0x63,0x01,0x00,0x08,0x00,0x40,0x40,0x15,0x3E,0xA1,0xfd,0x07,0xa4,0x01,0x01};
 unsigned char I2C_DY[18] = {0x01,0xB0,0x00,0x63,0x01,0x00,0x40,0x40,0x40,0x40,0x15,0x3E,0xA1,0xfd,0x07,0xa4,0x01,0x01};
 switch(variant)
 {
  	case 0:	for(i = 0; i <18; i++ ) { ret &= SendDataI2C(I2C_A[i],I2C_D1[i]);} break;
	case 1: for(i = 0; i <18; i++ ) { ret &= SendDataI2C(I2C_A[i],I2C_D2[i]);} break;
	case 2: for(i = 0; i <18; i++ ) { ret &= SendDataI2C(I2C_A[i],I2C_DY[i]);} break;

	default : ret = 0; break;
 }
 return ret;
}

extern "C" void any_init()
{
	 outportb(0x40 , 0);
//	 delay_mcs(32000l);
//	 outportb(0x4f , 0x10);
//	  delay_mcs(32000l);
	 outportb(0x4f , (0x80 | 0x1e));   //25
//	  delay_mcs(32000l);
//	 outportb(0x4f , 0x50);
//	  delay_mcs(32000l);
	 outportb(0x40 , 4);
//	  delay_mcs(32000l);
//	 outportb(0x4f , 0x10);
//	  delay_mcs(32000l);
	 outportb(0x4f , (0x80 | 0x1e));
//	  delay_mcs(32000l);
//	 outportb(0x4f , 0x50);
//	  delay_mcs(32000l);
}



extern "C" unsigned char  ReceiveI2CByte()
{
 unsigned char ret = 0;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0); //sda	 maked as receiver
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl


 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//	unsigned char mask;
//	mask = 0x80;
	for(long i = 0; i < 8; i++)
	{
 //	 if(mask & I2CData){ pio_ptr->SODR = MASK_BIT_8;}	//data to one!
 //	 else { pio_ptr->CODR = MASK_BIT_8;}  //data to zero!
	  ret <<= 1;
	 delay_mcs(DELAY_I2C);
//________________________________________________________________
 //________________________________________________________________


	 pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
	 delay_mcs(DELAY_I2C);
//________________________________________________________________
  if(pio_ptr->PDSR & MASK_BIT_8) //line data
  {
   ret++; 
  }
//________________________________________________________________

	 pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
	 delay_mcs(DELAY_I2C);
//	 ret <<= 1;
	 }

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda transmitter


  return ret;
}





extern "C" unsigned char ReadDataI2C(unsigned char Subaddr)
{
 unsigned char ret;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl

 MakeStartCondition();
 SendI2CByte(I2C_WRITE_COMMAND);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(Subaddr);
 if(!ReceiveACK()) return 0; //not have ack

  MakeStartCondition();
  SendI2CByte(I2C_READ_COMMAND);
  if(!ReceiveACK()) return 0; //not have ack
  ret = ReceiveI2CByte();
  //NAK - not need - read one Byte!
  MakeStopCondition();

 return ret;
}


#endif //PROG_KTVM

#ifdef	 PROG_DTVM
#define  KTVM_PLL_ADDR1 (0x300000E2)
#define  KTVM_PLL_ADDR2 (0x300000E1)
#define  I2C_WRITE_COMMAND (0xB8)
#define  I2C_READ_COMMAND (0xB9)

#define  DELAY_I2C (2l)

extern "C" void SetPLLKTVM()
{
unsigned char * pPLL;
//______________________________________________
 pPLL = (unsigned char *)(KTVM_PLL_ADDR1);
 *pPLL = 0x96;
 delay_mcs(2l);
 *pPLL = 0xC;
 delay_mcs(2l);
 pPLL = (unsigned char *)(KTVM_PLL_ADDR2);
  *pPLL = 0xFF;
 delay_mcs(2l);
 *pPLL = 0x0;
 delay_mcs(2l);
//______________________________________
pPLL = (unsigned char *)(KTVM_PLL_ADDR1);
 *pPLL = 0x72;
 delay_mcs(2l);
 *pPLL = 0x04;
 delay_mcs(2l);
 pPLL = (unsigned char *)(KTVM_PLL_ADDR2);
  *pPLL = 0xFF;
 delay_mcs(2l);
 *pPLL = 0x0;
 delay_mcs(2l);
}




extern "C" void   MakeStartCondition()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->MDER = MASK_BIT_8 ;	//enable on data line multidrive!
  pio_ptr->SODR = MASK_BIT_8 ;	//data to one!
  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  pio_ptr->CODR = MASK_BIT_8 ;	//data to zero!
  delay_mcs(DELAY_I2C);
//_______________________________________________
  pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
  delay_mcs(DELAY_I2C);
}

extern "C" void   MakeStopCondition()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->CODR = MASK_BIT_8 ;	//data to zero!
  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  pio_ptr->SODR = MASK_BIT_8 ;	//data to one!
  delay_mcs(DELAY_I2C);
}

extern "C" void  SendI2CByte(unsigned char I2CData)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

	unsigned char mask;
	mask = 0x80;
	for(long i = 0; i <8; i++)
	{
	 if(mask & I2CData){ pio_ptr->SODR = MASK_BIT_8;}	//data to one!
	 else { pio_ptr->CODR = MASK_BIT_8;}  //data to zero!
	 delay_mcs(DELAY_I2C);
	 pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
	 delay_mcs(DELAY_I2C);
	 delay_mcs(DELAY_I2C);
	 pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
	 delay_mcs(DELAY_I2C);
	 mask >>= 1;
	 }
}

extern "C" unsigned char ReceiveACK(void)
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   unsigned long status;
   unsigned char ret;

   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0); //sda to input
  delay_mcs(DELAY_I2C);

  pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
  delay_mcs(DELAY_I2C);
  status = pio_ptr->PDSR; //wait line init hier zero
  
  if(status & MASK_BIT_8) {ret = 0;} //no ACK
  else {ret = 1;}  //ACK ok

  pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda to output
  delay_mcs(DELAY_I2C);

 return ret;
} 




extern "C" unsigned char SendDataI2C(unsigned char Subaddr, unsigned char I2CData)
{

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl

 MakeStartCondition();
 SendI2CByte(I2C_WRITE_COMMAND);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(Subaddr);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(I2CData);
 if(!ReceiveACK()) return 0; //not have ack
 MakeStopCondition();
 return 1;
}

extern "C" unsigned char LoadCoder(unsigned char variant)
{
 unsigned char ret = 1;
 unsigned long i;
 unsigned char I2C_A[18]  = {0xEE,0xEA,0xE9,0xE8,0xE0,0xEE,0x00,0x05,0x06,0x33,0x34,0x35,0x36,0x37,0x59,0x0D,0x7f,0x39};
 unsigned char I2C_D1[18] = {0x01,0xB0,0x00,0x63,0x01,0x00,0x00,0x00,0x40,0x40,0x15,0x3E,0xA1,0xfd,0x07,0xa4,0x01,0x01};
 unsigned char I2C_D2[18] = {0x01,0xB0,0x00,0x63,0x01,0x00,0x40,0x40,0x40,0x40,0x15,0x3E,0xA1,0xfd,0x07,0xa4,0x01,0x01};
 switch(variant)
 {
  	case 1:	for(i = 0; i <18; i++ ) { ret &= SendDataI2C(I2C_A[i],I2C_D1[i]);} break;
	case 2: for(i = 0; i <18; i++ ) { ret &= SendDataI2C(I2C_A[i],I2C_D2[i]);} break;
	default : ret = 0; break;
 }
 return ret;
}


extern "C" unsigned char  ReceiveI2CByte()
{
 unsigned char ret2 = 0;
 unsigned long status;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 0); //sda	 maked as receiver
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl


 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//	unsigned char mask;
//	mask = 0x80;
 delay_mcs(DELAY_I2C);
	for(long i1 = 0; i1 < 8l; i1++)
	{
 //	 if(mask & I2CData){ pio_ptr->SODR = MASK_BIT_8;}	//data to one!
 //	 else { pio_ptr->CODR = MASK_BIT_8;}  //data to zero!
 
 //	 delay_mcs(DELAY_I2C);

	 pio_ptr->SODR = MASK_BIT_9 ;	//clocks to one!
	 delay_mcs(DELAY_I2C );
//	 ret <<= 1;
  //________________________________________________________________
//  if(pio_ptr->PDSR & MASK_BIT_8) //line data
//  {
//   ret++; 
 //  ret += (1 << i); 
 // }
//________________________________________________________________
  ret2 <<= 1;
	 status =  pio_ptr->PDSR;

 //   printEthLongHex(i1);

  //________________________________________________________________
  if(status & MASK_BIT_8) //line data
  {
   ret2++; 
 //  ret += (1 << i); 
  }
 


	 pio_ptr->CODR = MASK_BIT_9 ;	//clocks to zero!
	 delay_mcs(DELAY_I2C );
 //	 ret <<= 1;
	 }

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda transmitter


  return ret2;
}





extern "C" unsigned char ReadDataI2C(unsigned char Subaddr)
{
 unsigned char ret;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1); //sda
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //scl

 MakeStartCondition();
 SendI2CByte(I2C_WRITE_COMMAND);
 if(!ReceiveACK()) return 0; //not have ack
 SendI2CByte(Subaddr);
 if(!ReceiveACK()) return 0; //not have ack

  MakeStartCondition();
  SendI2CByte(I2C_READ_COMMAND);
  if(!ReceiveACK()) return 0; //not have ack
  ret = ReceiveI2CByte();
//  ReceiveACK(); //as NAK - for test
  //NAK - not need - read one Byte!
  MakeStopCondition();

 return ret;
}

#endif //PROG_DTVM

#ifdef PROG_PRM_PCH_N

extern "C" unsigned char GetAddrN(void)
{
// return (unsigned char)UARTAddress.Value;
 return (unsigned char)1;
}

extern "C" void SetAddrN(unsigned char addr)
{
 UARTAddress.Value = (float64)addr;
 UARTAddress.ChangingValue = UARTAddress.Value;
 WriteDevId();
}

#endif //  PROG_PRM_PCH_N

#ifdef PROG_PRM_PCH_SPI

extern "C" unsigned char GetAddrN(void)
{
// return (unsigned char)UARTAddress.Value;
#ifndef USE_FULL_ADDR
#ifndef PROG_PRM_PCH_SPI_XIL   
 return (unsigned char)1;
#else
return  MY_ADDRESS_XIL;	//it is variable
#endif
#else
 return (UARTAddress.Value);
#endif
}

extern "C" void SetAddrN(unsigned char addr)
{
 UARTAddress.Value = (float64)addr;
 UARTAddress.ChangingValue = UARTAddress.Value;
 WriteDevId();
}

extern "C" unsigned char GetAddrS(void)
{
// return (unsigned char)UARTAddress.Value;
 return (unsigned char)1;
}

extern "C" void SetAddrS(unsigned char addr)
{
 UARTAddress.Value = (float64)addr;
 UARTAddress.ChangingValue = UARTAddress.Value;
 WriteDevId();
}

extern "C" void SetUSARTRem(unsigned long NewAddr)
{
				UARTAddress.Value = NewAddr;
				UARTAddress.ChangingValue = NewAddr;	
			    WriteDevId();
}

extern "C"unsigned long GetUSARTRem(void)
{
  return (unsigned long)UARTAddress.Value;
}



#endif //  PROG_PRM_PCH_SPI



#ifdef PROG_BMDN
//______________________________________________________0 bit - trunks
extern "C" void SetModForSS(unsigned long mod)
{
 unsigned long temp = ModForSS.Value;
// flagModForSS = 0xff;

  if(mod)
   {
   temp |= (mod & MASK_BIT_0);
   }
   else
   {
    temp &= ~(1l);
   }


   temp |= mod & MASK_BIT_0;


//printfpd("\n\rmod%x",mod);
// ModForSS.Value = (float64)mod;
 ModForSS.Value = (float64)(temp) ;
 ModForSS.ChangingValue = ModForSS.Value;
 SetNeedWriteDevId();//120124
//120124 WriteDevId();
}

extern "C" unsigned long GetModForSS()
{
 return ((unsigned long)ModForSS.Value & MASK_BIT_0);
}
//______________________________________________________ 1 bit - operate power
extern "C" void SetModForSS1(unsigned long mod)
{
//printfpd("\n\rmod%x",mod);
// ModForSS.Value = (float64)mod;
//flagModForSS = 0xff;
   unsigned long temp = ModForSS.Value;
   if(mod)
   {
   temp |= (mod & MASK_BIT_0)  << 1;
   }
   else
   {
    temp &= ~((1)  << 1);
   }
 //  printEthLongHex(mod);
#ifdef O_POWER

if(!mod)
{
  ClearBufferState((unsigned long)OPERATE_POWER_ON);
  if(!flag_command_power)
  {
  DisableOperatePower(0);
  DisableOperatePower(1);
  }
  else
  {
   flag_command_power = 0;
  }

}
 else
{
  SetBufferState((unsigned long)OPERATE_POWER_ON);
  EnableOperatePower(0);
  EnableOperatePower(1);
}
#endif
 ModForSS.Value = (float64)(temp) ;
 ModForSS.ChangingValue = ModForSS.Value;
 SetNeedWriteDevId();//120124
// printEthLongHex(ModForSS.Value);

//120124 WriteDevId();
}

extern "C" unsigned long GetModForSS1()
{
 return ((unsigned long)ModForSS.Value & MASK_BIT_1) >> 1;
}



extern "C" void SetModEth(unsigned long mod)
{

 #ifdef PRINT_ETH
  printfp("\n\rSetModEth()");
printfpd(" ethmode : %02x", (unsigned char)MEthMode.Value);		 //need 0...5
printfpd(" modeth : %02x", (unsigned char)ModEth.Value);	   // any values


printfpd("  mod : 0x%x", mod);
#endif


//printfpd("\n\rmod%x",mod);
 ModEth.Value = (float64)mod;
 ModEth.ChangingValue = ModEth.Value;
//write in bit SetNeedWriteDevId();//120124
//150112  UsedExp.State.Reg2.bit.ModEth = 1;
//150112   UsedExp.State.Reg2.bit.Some = 1;

//120124 WriteDevId();
#ifdef PRINT_ETH
  //printfp("\n\rSetModEth()");
//printfpd(" ethmode : %02x", (unsigned char)MEthMode.Value);		 //need 0...5
printfpd(" modeth : %02x", (unsigned char)ModEth.Value);	   // any values


 printfpd("  mod : 0x%x", mod);
#endif


}

extern "C" unsigned long GetModEth()
{
 return (unsigned long)ModEth.Value;
}



  
extern "C" unsigned long GetNumConfigFile(unsigned char flagm)
{

// return 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!100728 for test !!!!!!!

//  printfp("\n\r GetNumConfigFile start  ");
//   printfpd("flagm =%d ", flagm);
 //	OperateBuffers_usart0t();


unsigned long ret;



switch(flagm)
{
 case 0 : ret = (unsigned long)ConfigFile.Value;   break;
//#ifndef PROG_BMDN6MI
 case 1 : ret = (unsigned long)ConfigFile1.Value;  break;
#ifndef PROG_BMDN6MI

 case 2 : ret = (unsigned long)ConfigFile2.Value;	break;
 case 3 : ret = (unsigned long)ConfigFile3.Value;	break;
 case 4 : ret = (unsigned long)ConfigFile4.Value;	break;
 case 5 : ret = (unsigned long)ConfigFile5.Value;	break;
 case 6 : ret = (unsigned long)ConfigFile6.Value;	break;
 case 7 : ret = (unsigned long)ConfigFile7.Value;	 break;
//___________________________________________________________8 modems
 case 8 : ret =  (unsigned long)ConfigFile8.Value;	 break;
//___________________________________________________________9 modems
 case 9 : ret =  (unsigned long)ConfigFile9.Value;	 break;
 case 10 : ret = (unsigned long)ConfigFile10.Value;	 break;
 case 11 : ret = (unsigned long)ConfigFile11.Value;	 break;
 case 12 : ret = (unsigned long)ConfigFile12.Value;	  break;
 case 13 : ret = (unsigned long)ConfigFile13.Value;	 break;
 case 14 : ret = (unsigned long)ConfigFile14.Value;	 break;
 case 15 : ret = (unsigned long)ConfigFile15.Value;	  break;
#endif

 default : ret = 0; break; //(unsigned long)ConfigFile.Value; //tMAX_CFG_FILE_VARIANT;
 }

  //if(ret >= MAX_CFG_FILE_VARIANT) ret = MAX_CFG_FILE_VARIANT-1;// ret = 0; //t MAX_CFG_FILE_VARIANT;
  if(ret >= MAX_CFG_FILE_VARIANT) ret = 0; //t MAX_CFG_FILE_VARIANT;

 //  printfpd("\n\r GetNumConfigFile ret =%d", ret);
 //  printfpd("flagm =%d ", flagm);
 //	OperateBuffers_usart0t();
  return ret;
 //ok return ret -10; //t

}

extern "C" unsigned long GetNumConfigFilet(unsigned char flagm)
{

// return 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!100728 for test !!!!!!!

//  printfp("\n\r GetNumConfigFile start  ");
//   printfpd("flagm =%d ", flagm);
 //	OperateBuffers_usart0t();


unsigned long ret;



switch(flagm)
{
 case 0 : ret = (unsigned long)ConfigFile.Value;   break;
//#ifndef PROG_BMDN6MI
 case 1 : ret = (unsigned long)ConfigFile1.Value;  break;
#ifndef PROG_BMDN6MI

 case 2 : ret = (unsigned long)ConfigFile2.Value;	break;
 case 3 : ret = (unsigned long)ConfigFile3.Value;	break;
 case 4 : ret = (unsigned long)ConfigFile4.Value;	break;
 case 5 : ret = (unsigned long)ConfigFile5.Value;	break;
 case 6 : ret = (unsigned long)ConfigFile6.Value;	break;
 case 7 : ret = (unsigned long)ConfigFile7.Value;	 break;
//___________________________________________________________8 modems
 case 8 : ret =  (unsigned long)ConfigFile8.Value;	 break;
//___________________________________________________________9 modems
 case 9 : ret =  (unsigned long)ConfigFile9.Value;	 break;
 case 10 : ret = (unsigned long)ConfigFile10.Value;	 break;
 case 11 : ret = (unsigned long)ConfigFile11.Value;	 break;
 case 12 : ret = (unsigned long)ConfigFile12.Value;	  break;
 case 13 : ret = (unsigned long)ConfigFile13.Value;	 break;
 case 14 : ret = (unsigned long)ConfigFile14.Value;	 break;
 case 15 : ret = (unsigned long)ConfigFile15.Value;	  break;
#endif

 default : ret = 0; break; //(unsigned long)ConfigFile.Value; //tMAX_CFG_FILE_VARIANT;
 }

  //if(ret >= MAX_CFG_FILE_VARIANT) ret = MAX_CFG_FILE_VARIANT-1;// ret = 0; //t MAX_CFG_FILE_VARIANT;
  if(ret >= MAX_CFG_FILE_VARIANT) ret = 0; //t MAX_CFG_FILE_VARIANT;

 //  printfpd("\n\r GetNumConfigFile ret =%d", ret);
 //  printfpd("flagm =%d ", flagm);
 //	OperateBuffers_usart0t();
  return ret;
 // return ret -10; //t

}


extern "C" unsigned long GetPriority(unsigned char flagm)
{

// return 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!100728 for test !!!!!!!


switch(flagm)
{
 case 0 : return (unsigned long)Priority0.Value; 

#ifndef PROG_BMDN6MI

 case 1 : return (unsigned long)Priority1.Value; 

 case 2 : return (unsigned long)Priority2.Value; 

 case 3 : return (unsigned long)Priority3.Value; 

 case 4 : return (unsigned long)Priority4.Value; 

 case 5 : return (unsigned long)Priority5.Value; 

 case 6 : return (unsigned long)Priority6.Value; 

 case 7 : return (unsigned long)Priority7.Value; 

//___________________________________________________________8 modems
 case 8 : return (unsigned long)Priority8.Value; 

#endif

 //__________________________________________________________9 modems
 case NO_MODEM : return (unsigned long)MIN_PRIORITY; 


 default : return (unsigned long)MIN_PRIORITY;	

 }
}

extern "C" signed short GetThreshold(unsigned char flagm)
{

// return 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!100728 for test !!!!!!!


switch(flagm)
{
 case 0 : return (signed short)Threshold0.Value * (-1);	

#ifndef PROG_BMDN6MI

 case 1 : return (signed short)Threshold1.Value * (-1);	

 case 2 : return (signed short)Threshold2.Value * (-1);	

 case 3 : return (signed short)Threshold3.Value * (-1);	

 case 4 : return (signed short)Threshold4.Value * (-1);	  

 case 5 : return (signed short)Threshold5.Value * (-1);	  

 case 6 : return (signed short)Threshold6.Value * (-1);	   

 case 7 : return (signed short)Threshold7.Value * (-1);	   

//___________________________________________________________8 modems
 case 8 : return (signed short)Threshold8.Value * (-1);	    

 //__________________________________________________________9 modems

#endif

 default : return (signed short)MIN_THRESHOLD * (-1);	 

 }
}

extern "C" void SetThreshold(unsigned char flagm, unsigned long val)
{

// return 0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!100728 for test !!!!!!!


switch(flagm)
{
 case 0 : Threshold0.Value  = val;	  break;

#ifndef PROG_BMDN6MI

 case 1 : Threshold1.Value  = val;	   break;

 case 2 : Threshold2.Value  = val;	   break;

 case 3 : Threshold3.Value  = val;	 break;

 case 4 : Threshold4.Value  = val;  break;

 case 5 : Threshold5.Value  = val;	  break;

 case 6 : Threshold6.Value  = val;	  break;

 case 7 : Threshold7.Value  = val;	  break;

//___________________________________________________________8 modems
 case 8 : Threshold8.Value  = val;	 break;

 //__________________________________________________________9 modems
#endif

 default :  break;

 }
}



#endif //PROG_BMDN 

#ifdef PROG_PRM_PCH_N_2

typedef struct _AT91S_SPI {
	unsigned long	 SPI_CR; 	// Control Register
	unsigned long	 SPI_MR; 	// Mode Register
	unsigned long	 SPI_RDR; 	// Receive Data Register
	unsigned long	 SPI_TDR; 	// Transmit Data Register
	unsigned long	 SPI_SR; 	// Status Register
	unsigned long	 SPI_IER; 	// Interrupt Enable Register
	unsigned long	 SPI_IDR; 	// Interrupt Disable Register
	unsigned long	 SPI_IMR; 	// Interrupt Mask Register
	unsigned long	 Reserved0[4]; 	// 
	unsigned long	 SPI_CSR[4]; 	// Chip Select Register
	unsigned long	 Reserved1[48]; 	// 
	unsigned long	 SPI_RPR; 	// Receive Pointer Register
	unsigned long	 SPI_RCR; 	// Receive Counter Register
	unsigned long	 SPI_TPR; 	// Transmit Pointer Register
	unsigned long	 SPI_TCR; 	// Transmit Counter Register
	unsigned long	 SPI_RNPR; 	// Receive Next Pointer Register
	unsigned long	 SPI_RNCR; 	// Receive Next Counter Register
	unsigned long	 SPI_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 SPI_TNCR; 	// Transmit Next Counter Register
	unsigned long	 SPI_PTCR; 	// PDC Transfer Control Register
	unsigned long	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;

#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0xFFFE0000) // (SPI) Base Address
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS1 %0111 */
//#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */






unsigned int SpiWriteN2 ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1
	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;


//select needed flash:
//		test
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS1_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
 
	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->sc->ata_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
   	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}



extern "C" void SendToDDS(unsigned long len, unsigned long pData)
{

//printfp("1 SendToDDS\n\r ");
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */
 SetLed3(0); //get off led 3
//______________________________________________for test
#ifdef	 TEST_PRM_PCH_N_2
long len1 = len;
unsigned char* pPr = (unsigned char * )pData;
//printf("\n\r DDS:");
while(len1--)
{
//printf(" %02X", *pPr++);
}
#endif
//______________________________________________




 SpiWriteN2 ( len,  pData);
// SpiWriteCS2 ( len,  pData);





}
#endif //	 PROG_PRM_PCH_N_2

//_________________________________________________________________________________
#ifdef PROG_PRM_PCH_SPI

#ifdef   STEND_SPI

#define  SSC_BUFFER_SIZE (200)
#define	 MAX_REAL_LEN (SSC_BUFFER_SIZE)

// TRBuffer<unsigned char,SSC_BUFFER_SIZE> ssc_trans_buf;
unsigned char ssc_trans_buf[SSC_BUFFER_SIZE];
unsigned long  ssc_trans_buf_cur;

extern "C" void SendSSCBuff(void)
{
 unsigned char ret;

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_A, 0);	 //t

 printfp("\n\r Send Command");

printfpd(" %d ", ssc_trans_buf_cur);
for(unsigned i = 0; i < ssc_trans_buf_cur; i++)
{
 printfpd(" %02X",ssc_trans_buf[i]);

#ifndef BACK_TO_SSC
 ToPdcTspi(ssc_trans_buf[i]);
#else
 ToPdcTSSC1t(ssc_trans_buf[i]);
#endif

}
//   ret = OperateBuffers_SSC1t();
ssc_trans_buf_cur = 0;

#ifndef BACK_TO_SSC
   ret = OperateBuffers_SPIt1();  
#else
    ret = OperateBuffers_SSC1t();
#endif   
   
     printfpd("ret %d", ret);


}

extern "C" void AddBufSSC(unsigned char chccs)
{
  ssc_trans_buf[ssc_trans_buf_cur++] = chccs;
   if (ssc_trans_buf_cur >= SSC_BUFFER_SIZE) 
   {
   ssc_trans_buf_cur = 0;
   }
}

extern "C" void SetSendToSSC(unsigned char * IPBuff, unsigned long len)
{
//  ssc_trans_buf.Add(0x55);
//  ssc_trans_buf.Add(0xAA);
//  AddBufSSC(0x55);
//  AddBufSSC(0xAA);

printfp("\n\r SetSendToSSC");
printfpd(" %d", len);
 if((len) && (len < MAX_REAL_LEN))
 {
  while(len--)
  {
//   AddBufSSC(*IPBuff++);

//	switch(*IPBuff)
  //								{
	//							case 0x5A: AddBufSSC(0x5A);  AddBufSSC(0x00); break;
	  //							case 0x55: AddBufSSC(0x5A);  AddBufSSC(0x01); break;
			  //					case 0xA5: AddBufSSC(0x5A);  AddBufSSC(0x02); break;
		//						case 0xAA: AddBufSSC(0x5A);  AddBufSSC(0x03); break;
			//					default: AddBufSSC(*IPBuff);
		  //						}
		 AddBufSSC(*IPBuff);
		IPBuff++;
  }
 }
 
//  AddBufSSC(0x55);

//hier need set flag to send to spi 
	UsedExp.State.Reg2.bit.SendBuf = 1;   
	UsedExp.State.Reg2.bit.Some = 1;   
//  ssc_trans_buf.Add(0x55);
}

extern "C" void MakeSendToSSC(unsigned char * IPBuff, unsigned long len)
{
//  ssc_trans_buf.Add(0x55);
//  ssc_trans_buf.Add(0xAA);
//  AddBufSSC(0x55);
//  AddBufSSC(0xAA);

printfp("\n\r SetSendToSSC");
printfpd(" %d", len);
 if((len) && (len < MAX_REAL_LEN))
 {
  while(len--)
  {
//   AddBufSSC(*IPBuff++);

//	switch(*IPBuff)
  //								{
	//							case 0x5A: AddBufSSC(0x5A);  AddBufSSC(0x00); break;
	  //							case 0x55: AddBufSSC(0x5A);  AddBufSSC(0x01); break;
			  //					case 0xA5: AddBufSSC(0x5A);  AddBufSSC(0x02); break;
		//						case 0xAA: AddBufSSC(0x5A);  AddBufSSC(0x03); break;
			//					default: AddBufSSC(*IPBuff);
		  //						}
		 AddBufSSC(*IPBuff);
		IPBuff++;
  }
 }
 
//  AddBufSSC(0x55);

//hier need set flag to send to spi 
 //	UsedExp.State.Reg2.bit.SendBuf = 1;   
//	UsedExp.State.Reg2.bit.Some = 1;   
//  ssc_trans_buf.Add(0x55);
SendSSCBuff();
}



#endif //STEND_SPI


typedef struct _AT91S_SPI {
	unsigned long	 SPI_CR; 	// Control Register
	unsigned long	 SPI_MR; 	// Mode Register
	unsigned long	 SPI_RDR; 	// Receive Data Register
	unsigned long	 SPI_TDR; 	// Transmit Data Register
	unsigned long	 SPI_SR; 	// Status Register
	unsigned long	 SPI_IER; 	// Interrupt Enable Register
	unsigned long	 SPI_IDR; 	// Interrupt Disable Register
	unsigned long	 SPI_IMR; 	// Interrupt Mask Register
	unsigned long	 Reserved0[4]; 	// 
	unsigned long	 SPI_CSR[4]; 	// Chip Select Register
	unsigned long	 Reserved1[48]; 	// 
	unsigned long	 SPI_RPR; 	// Receive Pointer Register
	unsigned long	 SPI_RCR; 	// Receive Counter Register
	unsigned long	 SPI_TPR; 	// Transmit Pointer Register
	unsigned long	 SPI_TCR; 	// Transmit Counter Register
	unsigned long	 SPI_RNPR; 	// Receive Next Pointer Register
	unsigned long	 SPI_RNCR; 	// Receive Next Counter Register
	unsigned long	 SPI_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 SPI_TNCR; 	// Transmit Next Counter Register
	unsigned long	 SPI_PTCR; 	// PDC Transfer Control Register
	unsigned long	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;

#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0xFFFE0000) // (SPI) Base Address
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS1 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS1 %0111 */

#ifdef USE_IO_LOAD_DDS

void init_io_for_dds(void)
{

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);

AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->SODR = 1<<14; //cs to one
	    piob_ptr->SODR = 1<<15; //data to one
		 piob_ptr->SODR = 1<<16; //clk to one


}


extern "C" void ToIoDDS(unsigned char data)
{
  unsigned char mask = 0x80;
  AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
     piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;


  for(unsigned i = 0; 0< 8; i++)
  {
  piob_ptr->CODR = 1<<16; //
  if(data & mask)
  {
	 piob_ptr->SODR = 1<<15; //
  }
  else
  {
	 piob_ptr->CODR = 1<<15; //
  }
  piob_ptr->SODR = 1<<16; //
  mask >>= 1;
  }


}

unsigned int SpiWriteN2_io ( unsigned long len, unsigned long pData)
{
//use io pins : pb16-sck pb15 - data pb14 - cs  
AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
        piob_ptr->CODR = 1<<14; //cs to zero
	
 for(unsigned il = 0; il < len; il++)
 {
   ToIoDDS(*(unsigned char *)pData);
 }
	  
     piob_ptr->SODR = 1<<14; //cs to one
	 piob_ptr->SODR = 1<<15; //data to one
}

#endif

unsigned int SpiWriteN2 ( unsigned long len, unsigned long pData)
{


   	unsigned int timeout;
	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1
	static char RxBuff[32];
	unsigned char tmp;


   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;


//select needed flash:
//		test
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS1_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
 
	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

_int_disable(); //140418

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
   	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

    tmp =  AT91C_BASE_SPI->SPI_TCR;  //140611
  //0	printfpd("\n\r SPI_TCR : %d", tmp);
	while(tmp)
	{
	 tmp =  AT91C_BASE_SPI->SPI_TCR;
	}

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

    
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
  delay_mcs(50);   //140418

_int_enable(); //140418

 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}


extern "C" char SpiReadN2 ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1
	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;


//select needed flash:
//		test
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS1_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
 
	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->sc->ata_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
   	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));



   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return RxBuff[0];
}





extern "C" void SendToDDS(unsigned long len, unsigned long pData)
{
 //printfp("2 SendToDDS\n\r ");

//fjjg
//printfp("s2");
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */


//120312 SetLed3(0); //get off led 3
 	 
 

#ifndef USE_IO_LOAD_DDS
//return; //t111223

 // printfpd("\n\r_psp_get_cpsr(): %x", _psp_get_cpsr());   //0x13
//printfp("SPi");
 SpiWriteN2 ( len,  pData);
// SpiWriteCS2 ( len,  pData);
#else
// printfp("io");

 SpiWriteN2_io ( len,  pData);

#endif




}
#endif //	 PROG_PRM_PCH_SPI




//_________________________________________________________________________________



/*
extern "C" void Enable_irqs_for_task()
{
#ifdef PROG_BMD155
 my_int_enable_irq0();
#endif //PROG_BMD155

}
extern "C" void Disable_irqs_for_task()
{
#ifdef PROG_BMD155
 my_int_disable_irq0();
#endif //PROG_BMD155
}

*/ 

#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU3
extern "C" void SetSymbolRate2(unsigned long tmp)
{
 SymbolRate2.Value = tmp;
 SymbolRate2.ChangingValue = tmp;

}

extern "C" unsigned long GetSymbolRate2(void)
{
 return (unsigned long)SymbolRate2.Value;
}

extern "C" void SetFreqPCh2(unsigned long tmp)
{
 FreqPCh2.Value = tmp;
 FreqPCh2.ChangingValue = tmp;

}

extern "C" unsigned long GetFreqPCh2(void)
{
 return (unsigned long)FreqPCh2.Value;
}


extern "C" void SetModulSK2(unsigned long tmp)
{
 ModulSK2.Value = tmp;
 ModulSK2.ChangingValue = tmp;

}

extern "C" unsigned long GetModulSK2(void)
{
 return (unsigned long)ModulSK2.Value;
}

#endif

#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU4
extern "C" void SetSymbolRate2(unsigned long tmp)
{
 SymbolRate2.Value = tmp;
 SymbolRate2.ChangingValue = tmp;

}

extern "C" unsigned long GetSymbolRate2(void)
{
 return (unsigned long)SymbolRate2.Value;
}

extern "C" void SetFreqPCh2(unsigned long tmp)
{
 FreqPCh2.Value = tmp;
 FreqPCh2.ChangingValue = tmp;

}

extern "C" unsigned long GetFreqPCh2(void)
{
 return (unsigned long)FreqPCh2.Value;
}


extern "C" void SetModulSK2(unsigned long tmp)
{
 ModulSK2.Value = tmp;
 ModulSK2.ChangingValue = tmp;

}

extern "C" unsigned long GetModulSK2(void)
{
 return (unsigned long)ModulSK2.Value;
}

extern "C" void SetSymbolRate3(unsigned long tmp)
{
 SymbolRate3.Value = tmp;
 SymbolRate3.ChangingValue = tmp;

}

extern "C" unsigned long GetSymbolRate3(void)
{
 return (unsigned long)SymbolRate3.Value;
}

extern "C" void SetFreqPCh3(unsigned long tmp)
{
 FreqPCh3.Value = tmp;
 FreqPCh3.ChangingValue = tmp;

}

extern "C" unsigned long GetFreqPCh3(void)
{
 return (unsigned long)FreqPCh3.Value;
}


extern "C" void SetModulSK3(unsigned long tmp)
{
 ModulSK3.Value = tmp;
 ModulSK3.ChangingValue = tmp;

}

extern "C" unsigned long GetModulSK3(void)
{
 return (unsigned long)ModulSK3.Value;
}


extern "C" void SetSymbolRate4(unsigned long tmp)
{
 SymbolRate4.Value = tmp;
 SymbolRate4.ChangingValue = tmp;

}

extern "C" unsigned long GetSymbolRate4(void)
{
 return (unsigned long)SymbolRate4.Value;
}

extern "C" void SetFreqPCh4(unsigned long tmp)
{
 FreqPCh4.Value = tmp;
 FreqPCh4.ChangingValue = tmp;

}

extern "C" unsigned long GetFreqPCh4(void)
{
 return (unsigned long)FreqPCh4.Value;
}


extern "C" void SetModulSK4(unsigned long tmp)
{
 ModulSK4.Value = tmp;
 ModulSK4.ChangingValue = tmp;

}

extern "C" unsigned long GetModulSK4(void)
{
 return (unsigned long)ModulSK4.Value;
}


#endif


//t#ifdef PROG_PRM_PCH_DEM
#ifdef PROG_PRM_PCH_DEM
 
extern "C" void SetNeedReloadXil(unsigned char val)
{
 switch(val)
 { 
   case 0 : UsedExp.State.Reg2.bit.lxil0 = 1; break;
   case 1 : UsedExp.State.Reg2.bit.lxil1 = 1; break;
   default :  UsedExp.State.Reg2.bit.lxil0 = 1; break;
 }  
   UsedExp.State.Reg2.bit.Some = 1;

}


extern "C" void SetSymbolRate(unsigned long tmp)
{

	if(GetTestMode() == 0x50)
  	{	
       printfpd("\n\r SetSymbolRate: %ld", tmp);
  	  
 	}	

 SymbolRate.Value = tmp;
 SymbolRate.ChangingValue = tmp;

}

extern "C" unsigned long GetSymbolRate(void)
{

if(GetTestMode() == 0x50)
  	{	
       printfpd("\n\r GetSymbolRate: %ld", (unsigned long)SymbolRate.Value);
  	  
 	}	


 return (unsigned long)SymbolRate.Value;
}

extern "C" void SetFreqPCh(unsigned long tmp)
{
 
 FreqPCh.Value = tmp;

}

extern "C" unsigned long GetFreqPCh(void)
{
 return (unsigned long)FreqPCh.Value;
}


extern "C" void SetModulSK(unsigned long tmp)
{

if(GetTestMode() == 0x50)
  	{	
       printfpd("\n\r SetModulSK: %ld", tmp);
  	  
 	}	

 ModulSK.Value = tmp;
 ModulSK.ChangingValue = tmp;

}

extern "C" unsigned long GetModulSK(void)
{

if(GetTestMode() == 0x50)
  	{	
       printfpd("\n\r GetModulSK: %ld", (unsigned long)ModulSK.Value);
  	  
 	}	


 return (unsigned long)ModulSK.Value;
}



typedef struct _AT91S_SPI {
	unsigned long	 SPI_CR; 	// Control Register
	unsigned long	 SPI_MR; 	// Mode Register
	unsigned long	 SPI_RDR; 	// Receive Data Register
	unsigned long	 SPI_TDR; 	// Transmit Data Register
	unsigned long	 SPI_SR; 	// Status Register
	unsigned long	 SPI_IER; 	// Interrupt Enable Register
	unsigned long	 SPI_IDR; 	// Interrupt Disable Register
	unsigned long	 SPI_IMR; 	// Interrupt Mask Register
	unsigned long	 Reserved0[4]; 	// 
	unsigned long	 SPI_CSR[4]; 	// Chip Select Register
	unsigned long	 Reserved1[48]; 	// 
	unsigned long	 SPI_RPR; 	// / ceive Pointer Register
	unsigned long	 SPI_RCR; 	// Receive Counter Register
	unsigned long	 SPI_TPR; 	// Transmit Pointer Register
	unsigned long	 SPI_TCR; 	// Transmit CouCour Register
	unsigned long	 SPI_RNPR; 	// Receive Next Pointer Register
	unsigned long	 SPI_RNCR; 	// Receive Next Counter Register
	unsigned long	 SPI_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 SPI_TNCR; 	// Transmit Next Counter Register
	unsigned long	 SPI_PTCR; 	// PDC Transfer Control Register
	unsigned long	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;

#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0xFFFE0000) // (SPI) Base Address
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS       ((unsigned int) 0x1 <<  1) // (SPI) SPI Disable

#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS3 %0111 */




unsigned int SpiWriteCS2 ( unsigned long len, unsigned long pData)
{
// printfp("2");

   	unsigned int timeout;
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;

AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
//select needed flash:
//		test
 		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;

		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
   //			AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS3_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);



	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
 //101113  	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));
																
    delay_mcs(1000); //101113

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}


//linkdoubler

extern "C" void SendToDDS(unsigned long len, unsigned long pData)
{
  
// printfp("3 SendToDDS\n\r ");

 // hier is dmu hjgjg
//nonono
//printfp("s3");
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */
// SetLed3(0); //get off led 3
//______________________________________________for test
#ifdef	 TEST_PRM_PCH_N_2
long len1 = len;
unsigned char* pPr = (unsigned char * )pData;
//printf("\n\r DDS:");
while(len1--)
{
//printf(" %02X", *pPr++);
}
#endif
//______________________________________________




// SpiWriteN2 ( len,  pData);
 SpiWriteCS2 ( len,  pData);





}

unsigned int SpiWriteCS3 ( unsigned long len, unsigned long pData)
{
//printfp("3");
   
   	unsigned int timeout;
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;

AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
//select needed flash:
//		test
 		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;

		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
   	   	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS3_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);



	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		A/		A_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
 //101113  	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));
																
    delay_mcs(1000); //10//10				
    delay_mcs(1000); //10R = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}


extern "C" void SendToDDS3(unsigned long len, unsigned long pData)
{
//printfp("s4");
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */
// SetLed3(0); //get off led 3
//______________________________________________for test
#ifdef	 TEST_PRM_PCH_N_2
long len1 = len;
unsigned char* pPr = (unsigned char * )pData;
//printf("\n\r DDS:");
while(len1--)
{
//printf(" %02X", *pPr++);
}
#endif
//______________________________________________




// SpiWriteN2 ( len,  pData);
 SpiWriteCS3 ( len,  pData);
}





#endif //PROG_PRM_PCH_DEM





#ifdef PROG_BMDN
#ifndef PROG_VNV
void SetProtObj(unsigned char provnum, unsigned long value)
{
 if(provnum >= (MODEM_QUANTITY << 1)) return;
  switch(provnum)
  {
 case 0 :  Protect0.Value = value;	Protect0.ChangingValue = value; break;
#ifndef PROG_BMDN6MI
 case 1 :  Protect1.Value = value;	Protect1.ChangingValue = value; break;
 case 2 :  Protect2.Value = value;	Protect2.ChangingValue = value; break;
 case 3 :  Protect3.Value = value;	Protect3.ChangingValue = value; break;
 case 4 :  Protect4.Value = value;	Protect4.ChangingValue = value; break;
 case 5 :  Protect5.Value = value;	Protect5.ChangingValue = value; break;
 case 6 :  Protect6.Value = value;	Protect6.ChangingValue = value; break;
 case 7 :  Protect7.Value = value;	Protect7.ChangingValue = value; break;
 case 8 :  Protect8.Value = value;	Protect8.ChangingValue = value; break;
 case 9 :  Protect9.Value = value;	Protect9.ChangingValue = value; break;
 case 10 :  Protect10.Value = value;	Protect10.ChangingValue = value; break;
 case 11 :  Protect11.Value = value;	Protect11.ChangingValue = value; break;
 case 12 :  Protect12.Value = value;	Protect12.ChangingValue = value; break;
 case 13 :  Protect13.Value = value;	Protect13.ChangingValue = value; break;
 case 14 :  Protect14.Value = value;	Protect14.ChangingValue = value; break;
 case 15 :  Protect15.Value = value;	Protect15.ChangingValue = value; break;
 case 16 :  Protect16.Value = value;	Protect16.ChangingValue = value; break;
 case 17 :  Protect17.Value = value;	Protect17.ChangingValue = value; break;
#endif
 default : break;
  }
 
}

extern "C" unsigned char GetPriorityZero()
{

for(unsigned char mod = 0; mod < MODEM_QUANTITY; mod++)
{
// if(ModemIsUsed(mod))
// {
   if( GetPriority(mod) == ZERO_PRIORITY)
   	{
	  return mod;
	}
// }
 
}
  return NO_MODEM;
}



#endif //PROG_BMDN
#endif

#ifdef PROG_BMDN3
extern "C" void InitSetConfigFile(unsigned char variant)
{
	 ConfigFile.Value = (unsigned long)variant;
	 ConfigFile.ChangingValue  =  (unsigned long)variant;
     UsedExp.State.Reg2.bit.FillCFV0 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	 UsedExp.State.Reg2.bit.Some = 1;

}

extern "C" void InitSetACMMask(unsigned short mask)
{
	  acmmask0 = mask;
       UsedExp.State.Reg2.bit.ACMMask0 = 1;
   //	 UsedExp.State.Reg2.bit.WriteId = 1;
	 UsedExp.State.Reg2.bit.Some = 1;

}

#endif

#ifdef PROG_BMDN4
//extern "C" void InitSetConfigFile(unsigned char variant)
extern "C" void InitSetConfigFile(unsigned long variant)
{
 
	 ConfigFile.Value = (unsigned long)variant;
	 ConfigFile.ChangingValue  =  (unsigned long)variant;
     UsedExp.State.Reg2.bit.FillCFV0 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	 UsedExp.State.Reg2.bit.Some = 1;

}

extern "C" void InitSetACMMask(unsigned short mask)
{
	  acmmask0 = mask;
       UsedExp.State.Reg2.bit.ACMMask0 = 1;
   //	 UsedExp.State.Reg2.bit.WriteId = 1;
	 UsedExp.State.Reg2.bit.Some = 1;

}

#endif




extern "C" unsigned int ReadAis()
{
//  return 0;	 //for test


  AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  unsigned int imr =  aic_ptr->IMR;
  aic_ptr->IDCR = 0xFFFFFFFFl;
  return imr;
}

extern "C" unsigned int ReadAis1()
{
//  return 0;	 //for test


  AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  unsigned int imr =  aic_ptr->IMR;
  aic_ptr->IDCR = 0xFFFFFFFFl;
  return imr;
}




extern "C" WriteAis(unsigned int imr)
{
// return; //for test

 AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
 aic_ptr->IECR = imr;


}




#ifdef PROG_PRM_PCH_SPI 
#include <prm_pch_spi_real_work1.cpp>
#endif // PROG_PRM_PCH_SPI    

#include <mirror.cpp>

#ifdef PROG_PU_MSAT
#ifndef PROG_PU_MSAT1
#ifndef PROG_PU_MSAT5

#include <pu_msat_work1.cpp>
#endif
#endif

#ifdef PROG_PU_MSAT1
#include <pu_msat1_work1.cpp>
#endif

#ifdef PROG_PU_MSAT5
#include <pu_msat5_work1.cpp>
//#include <pu_msat1_work1.cpp>	//t

#endif //  PROG_PU_MSAT  
#endif
 
#ifndef PROG_VNV
#ifdef PROG_BMDN4
#include <bmdn4_work1.cpp>
#endif //  PROG_PU_MSAT  
#endif



#ifdef PROG_PU_M710
#include <pu_m710_work1.cpp>
#endif //  PROG_PU_MSAT  

#ifdef USE_HTTP

//_______________________________________________________________
extern "C" void OperateFileWebProg( _ip_address server, char_ptr filename, 
 unsigned int size, unsigned long addr_dest, unsigned long operation)
{
printfp("\n\rOperateFileWebProg");

flag_restart_web_prog = 1;
counter_restart_web_prog = time1 + WEB_PROG_RESTART_DELAY;
if(counter_restart_web_prog < time1) 
{
time1 = 0;
counter_restart_web_prog =  WEB_PROG_RESTART_DELAY;

}

//_________________________for tftp loader
// _ip_address server;
//  char_ptr filename;
//_________________________for flash writer
//  unsigned long operation;
  unsigned int addr_src;
//  unsigned int size;
  signed char errorw = 1;

#ifdef PROG_PU_MSAT
    unsigned int size1;
	   AT91RM9200_PIO_REG_STRUCT_PTR pio_ptrb;

#endif

    char bufstop[] = "1234567890";
  char * stopstring;
  uint_32 keep;
  stopstring = &bufstop[0];
  #define BUFFNAMESIZE (50)
  #define ENABLED_BUFFNAMESIZE (8)

  char BuffName[BUFFNAMESIZE]; 
  #define BUFFSIZESIZE (9)
  char BuffSize[BUFFSIZESIZE];
   uint_32 cnt, getpoint, error;
  #define IPADDRSIZE (9)

  // my_int_disable_usart0();
//  usart0_connecting (0); //disconnect

  
 //for (int i = 0; i < TFTP_BUFFER_SIZE; i++)
// {
  // TFTP_Buffer[i] = 0;
 //}
 //t server  =  (_ip_address)0x9B9B9B9D;

/*
  getpoint = 0; 
  server = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);
  getpoint = (uint_32)IPADDRSIZE;
  for(cnt = 0; cnt < (BUFFNAMESIZE - 1); cnt++)
  {
	 if(FileUpdate.Value[cnt + getpoint] == '-') break;
	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
	  else {BuffName[cnt] =  FileUpdate.Value[cnt + getpoint];}
  }
  if(cnt > (ENABLED_BUFFNAMESIZE + 2)) //have symbols "-" 
  {
 // my_printf((unsigned char)cnt);
  return; //tftp do not work witch long names
  }

  BuffName[cnt] =  '\0';
 // filename = "hello7.bin";
  filename = &BuffName[0];
  getpoint += (cnt + 1); 

  for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
	// if(FileUpdate.Value[cnt + getpoint] == '-') break;
   //	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
   //	  else {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
   //	  }
  }
    BuffSize[cnt] =  '\0';

   size =  strtoll(&BuffSize[0], &stopstring,10);
	   
#ifdef PROG_PU_MSAT
    size1 = XilSizeToDownloadD;
	 pio_ptrb =  (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

#endif

  if(size > TFTP_BUFFER_SIZE)  size = TFTP_BUFFER_SIZE;
 
  getpoint += (cnt + 1);
   for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
	// if(FileUpdate.Value[cnt + getpoint] == '-') break;
   //	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
   //	  else {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
   //	  }
  }
    BuffSize[cnt] =  '\0';

   addr_dest =  strtoll(&BuffSize[0], &stopstring,16);

   getpoint += (BUFFSIZESIZE);

   operation = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);
   */

#ifdef PROG_PU_MSAT
    size1 = XilSizeToDownloadD;
	 pio_ptrb =  (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

#endif

 
  addr_src = (unsigned int)&TFTP_Buffer[0];
   //need get off watch dog.
 //   RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"hello7.bin", (uchar_ptr)&TFTP_Buffer[0]);
  usart_command_eth_on();
    
   UsedExp.State.Reg1.bit.UCDE = 0; //usart not can now disable ethernet
   keep = (uint_32)SBuffersState.Value;
   keep |= (uint_32)TFTP_PROCEED;
    keep &= ~((uint_32)FILE_WRITE_OK);
   SBuffersState.Value = (float64)keep;

 //	 my_int_disable_irq0();


#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	
		if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rcheck flash ");
      OperateBuffers_usart0t();

#endif   
	    pio_ptrb->CODR = 1<<12; //get down line prog for xilinx
		delay_mcs(1000);

        errorw = (signed char)check_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1); //90 : without header
     if(errorw) 
     {
#ifdef TEST_HANGING      
      printfp("\n\rreturn to error flash ");
      OperateBuffers_usart0t();

#endif   

	  pio_ptrb->SODR = 1<<12; //get up line prog for xilinx

	 
     return;
	 }
		}
#endif
#endif


   
   error = RTCS_load_TFTP_BIN(server,filename, (uchar_ptr)&TFTP_Buffer[0]);
   // wd_reset();

   UsedExp.State.Reg1.bit.UCDE = 1; //now usart can disable ethernet
//ok  RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"hello7.bin", (uchar_ptr)&TFTP_Buffer[0]);	 //t
//RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,filename, (uchar_ptr)&TFTP_Buffer[0]);	 //t
//  delay_mcs(40000);

// printf("\n\r1");

  if(error)
  {
  	 keep &= ~((uint_32)TFTP_PROCEED);
     SBuffersState.Value = (float64)keep;
     return; //to not write bad loading
   }
//  printf("\n\r2");
    // if((addr_dest < 0xC0030000) ||  ((size + addr_dest) >= ID_ADDRESS)) return;
	if(operation == 1l)	  //write file
	{
//printf("\n\r2a");
	printfp("\n\r operation 1");   //ok
    printfpd(" addr_dest: 0x%X", addr_dest);
   printfpd(" size: %d", size);
   printfpd("server	: %X", server);



	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
	 //c00a6638

   printfp("\n\r addr ok");   //

//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t
//#endif
#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	

if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rInvertBitOrdering ");
      OperateBuffers_usart0t();

#endif      
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	  size = 90; // header only
  	  addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }
#endif
#endif

//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif

#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	
		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

#endif   
//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<12; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
            StartLoadAll();
		    wd_reset();
   //ok		  TestWriteFlash2();
		}

#endif
#endif
	   /* this maked in operation == 5
#ifdef PROG_BMDN

		wd_reset();
 	 //	delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest < (CFG_DATAFLASH_LOGIC_ADDR_CS1X))
		{

//#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

//#endif   
//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflashx (CFG_DATAFLASH_LOGIC_ADDR_CS0X + VER_OFFSET, (unsigned int)&TFTP_Buffer[0x60],  size); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);

	    wd_reset();
   //ok		  TestWriteFlash2();

	   errorw = 0; // do not need write this in base flash
		}


#endif
	 */


	delay_mcs(2000000);

  	printfpd("\n\r errorw :%d", errorw);

	 if(errorw == (signed char)1)
	 {
  	 printfp("\n\r write data");

     write_dataflash (addr_dest, addr_src,  size);
	 }
//#ifdef PROG_PU_MSAT
//}
//#endif



  //	  wd_reset();
//printf("\n\r4");
  	   delay_mcs(100);


	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN

#ifndef PROG_VNV

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif
#endif

	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
	else if(operation == 2l)   //run file
	{
	  usart_select(0); //debug uart on
	  my_int_disable();
	  wd_deinit();
	  _arm920t_dcache_disable();
	  _arm920t_icache_disable();

 	  Jump(&TFTP_Buffer[0]);
	}
	else if(operation == 3l)   //programm pult
	{
#ifdef PROGRAMM_PULT
	 ProgrammPultTFTP();
#endif //PROGRAMM_PULT 
	}
else if(operation == 4l)   //programm pult
	{
#ifdef LOAD_EXT_MODEM
	 unsigned char * src =  (uchar_ptr)&TFTP_Buffer[0];
	 unsigned char * dst =  (uchar_ptr)NVRAM_BASE;
	 for(cnt = 0; cnt < DATA_SIZE_EXTMODEM; cnt++)
	 {
	  * dst++ = *src++;
	 } 
	 LoadExtModem();
#endif // LOAD_EXT_MODEM
	}
else if(operation == 5l)   //programm flash through xilinx
	{
#ifdef XIL_FLASH
  //	      write_dataflashx (addr_dest, addr_src,  size);
//___________________________________________________________________
// if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start write xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif
  //now write all to have header in far flash   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);
//121018   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0],  size);
 
//printfp("\n\r");
 for(unsigned long i = 0; i < 0x60; i++)
 {
  TFTP_Buffer1[i] =	TFTP_Buffer[i];
//  printfpd(" %02X",TFTP_Buffer[i]);
 } 
// */
//  	 delay_mcs(100000l);

 write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);	//121018 - write only xilinx data(try use zero address for xilinx loading) 
//keep header in main flash 
 //  write_dataflash ((unsigned int)XilFileDataAddressD3, (unsigned int)&TFTP_Buffer[0],  0x60);
  	delay_mcs(10000l);


 write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  // wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
  
  
 //write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);	//121018 - write only xilinx data(try use zero address for xilinx loading) 
//keep header in main flash 
 //  write_dataflash ((unsigned int)XilFileDataAddressD3, (unsigned int)&TFTP_Buffer[0],  0x60);
  //	delay_mcs(10000l);
	/*
  for(i = 1; i < 0x61; i++)
 {
  TFTP_Buffer1[i] =	i;
  printfpd(" %02X",TFTP_Buffer[i]);
 } 
	 */
  		/*
     write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  //	  wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
	 */
	//  wd_reset();
  //	   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
  //	   {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
  //	   }
 //	FillDatat(0); //for test

 //	FillXilFileDatax(MODEM_QUANTITY);
	FillXilFileDatax(0);
  //	  wd_reset();

	// FillProgVersion();

//#ifdef PROG_BMDN
//	FillConfigFileVersion();
//#endif // PROG_BMDN


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;




//___________________________________________________________________


	  //in addr _dest - need make address of conkretycal xilinx
#endif
	}
 else if(operation == 6l)	  //compare file
	{
//printf("\n\r2a");

//120710	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t

#ifdef XIL_FLASH

AT91F_DataflashInitx();  //t

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start compare xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif

 if(addr_dest < CFG_DATAFLASH_LOGIC_ADDR_CS1X)
 {
#ifdef DEBUG_WRITE_XIL
  printfp("\n\r addr ok");
#endif

   InvertBitOrdering();
   CompareToFilex(size);
 }
#endif

//#endif
#ifdef PROG_PU_MSAT
if(addr_dest == (XilFileDataAddressD - 0x20))
		{
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	   size = 90; // header only
  		 addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }

#endif
//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif
 //    write_dataflash (addr_dest, addr_src,  size);
//#ifdef PROG_PU_MSAT
//}
//#endif
  //	  wd_reset();
//printf("\n\r4");
  	   delay_mcs(100);
#ifdef PROG_PU_MSAT

		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{
//write to second flash local addr = 0;
//___________________________________________try write from second try
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	   CompareToFile(size1);

	
	    wd_reset();
   //ok		  TestWriteFlash2();
		}
#endif
	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN

#ifndef PROG_VNV

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif

#endif


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
}
//_______________________________________________________________


#include "my_strtod.cpp"

#ifndef	PROG_VNV

#ifdef 	PROG_PU_MSAT

#include "web_pum_sat.cpp"

#endif //PROG_PU_MSAT

#ifdef 	PROG_MD310_SATI
#ifndef PROG_MD310_SATI2
#include "web_md310_sat.cpp"
#else
#include "web_md310s2_sat.cpp"
#endif

#endif //PROG_PU_MSAT

#endif


#endif //USE_HTTP

#ifdef PROG_BMDN 



typedef struct _AT91S_SPI {
	unsigned long	 SPI_CR; 	// Control Register
	unsigned long	 SPI_MR; 	// Mode Register
	unsigned long	 SPI_RDR; 	// Receive Data Register
	unsigned long	 SPI_TDR; 	// Transmit Data Register
	unsigned long	 SPI_SR; 	// Status Register
	unsigned long	 SPI_IER; 	// Interrupt Enable Register
	unsigned long	 SPI_IDR; 	// Interrupt Disable Register
	unsigned long	 SPI_IMR; 	// Interrupt Mask Register
	unsigned long	 Reserved0[4]; 	// 
	unsigned long	 SPI_CSR[4]; 	// Chip Select Register
	unsigned long	 Reserved1[48]; 	// 
	unsigned long	 SPI_RPR; 	// / ceive Pointer Register
	unsigned long	 SPI_RCR; 	// Receive Counter Register
	unsigned long	 SPI_TPR; 	// Transmit Pointer Register
	unsigned long	 SPI_TCR; 	// Transmit CouCour Register
	unsigned long	 SPI_RNPR; 	// Receive Next Pointer Register
	unsigned long	 SPI_RNCR; 	// Receive Next Counter Register
	unsigned long	 SPI_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 SPI_TNCR; 	// Transmit Next Counter Register
	unsigned long	 SPI_PTCR; 	// PDC Transfer Control Register
	unsigned long	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;

#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0xFFFE0000) // (SPI) Base Address
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS       ((unsigned int) 0x1 <<  1) // (SPI) SPI Disable

#define AT91C_SPI_PCS0_SERIAL_DATAFLASH		0xE     /* Chip Select 0 : NPCS0 %1110 */
#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS3 %0111 */

void SetFlashCs0(void) {
 AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;
 AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
 AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS0_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
 AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
}


void InitSpiCS2B(void) {
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  printfpd1("\n\rCSR:%X ", AT91C_BASE_SPI->SPI_CSR[2]);
}


unsigned int SpiWriteCS2B ( unsigned long len, unsigned long pTxData, unsigned long pRxData)
{
		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
 		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
  	    AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
   	    AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR = pRxData; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pTxData; //(unsigned int)pDesc->tx_cmd_pt ;
    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;
     /* arm simple, non interrupt dependent timer */
   	   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
//    	delay_mcs(10000); //101113
  		delay_mcs(5000);
//    	delay_mcs(7500); //101113
   		AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
    	AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
  		AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
 return 1;
}

 
extern "C" void BCS_IO_Init(void)
{
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0,  AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 1);  
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 0);
}

extern "C" void SetR(void) {
	AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
    pio_ptra->SODR = 1<<0; 
}

extern "C" void ClearR(void) {
	AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
    pio_ptra->CODR = 1<<0; 
}

extern "C" void SetD(void) {
	AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
    pio_ptra->SODR = 1<<28; 
}

extern "C" void ClearD(void) {
	AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
    pio_ptra->CODR = 1<<28; 
}


extern "C" unsigned char ReadS(void) {
	AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
	unsigned long status;
	unsigned char ret = 1;
    status = pio_ptra->PDSR;
    if(!(status & (1<<29))) ret = 0;
	return ret;
	}

#ifdef XIL_FLASH
//extern "C" int write_dataflashx (unsigned long , unsigned int , unsigned int );
//extern "C" int read_dataflashx (unsigned long addr, unsigned long size, char *result);
//int write_dataflashx (unsigned long addr_dest, unsigned int addr_src, unsigned int size)

//#define  SIZEX (5)
#define  SIZEX (500)
#define  SIZEXR (SIZEX)
//#define  ADEST (CFG_DATAFLASH_LOGIC_ADDR_CS0X + 0x49000)
#define  ADEST (CFG_DATAFLASH_LOGIC_ADDR_CS0X)

#define  SIZEX1 (700)
#define  SIZEXR1 (SIZEX1)
#define  ADEST1 (CFG_DATAFLASH_LOGIC_ADDR_CS0X + 0x49000 - SIZEX1)
  /*

//extern "C" void CheckOperateFlashx(void)
//{
 // printfp("\n\rCheckOperateFlashx");

// char BuffW[SIZEX1];
 //charFLASH_LOGIC_ADDR_CS0X + 0x49000)

#define  SIZEX1 (700)
#define  SIZEXR1 (SIZEX1)
#define  ADEST1 (CFG_DATAFLASH_LOGIC_ADDR_CS0X + 0x49000 - SIZEX1)


extern "C" void CheckOperateFlashx(void)
{
 // printfp("\n\rCheckOperateFlashx");

 char BuffW[SIZEX1];
 char  	BuffW[i] = i+ 0x20;
//    BuffR[i] = 0; //clear
//   	printfpd(" %02X", BuffW[i]);

//  }
//  write_dataflashx(ADEST1, (unsigned long)&BuffW[0] , SIZEX1);
  	 */
//__________________________________________________
extern "C" void CheckOperateFlashx(void)
{
 // printfp("\n\rCheckOperateFlashx");

 char BuffW[SIZEX1];
 char BuffR[SIZEXR1];
 unsigned flag = 1;
  for(unsigned i = 0; i < SIZEX; i++)
  {	
  	BuffW[i] = i;
    BuffR[i] = 0; //clear
  }
 //t write_dataflashx(ADEST, (unsigned long)&BuffW[0] , SIZEX);
 //  printfp("\n\r set : ");
	
// for( i = 0; i < SIZEX1; i++)
//  {	
//  	BuffW[i] = i+ 0x20;
//    BuffR[i] = 0; //clear
//   	printfpd(" %02X", BuffW[i]);

//  }
//  write_dataflashx(ADEST1, (unsigned long)&BuffW[0] , SIZEX1);

//__________________________________________________

  read_dataflashx (ADEST, SIZEXR, &BuffR[0]);

 // printfp("\n\r");

//   for(i = 0; i < SIZEXR; i++)
//  {	
//  	printfpd(" %02X", BuffR[i]);
//	OperateBuffers_usart0t();
//  }

  // printfp("\n\rok");

   
  // read_dataflashx (ADEST1, SIZEXR1, &BuffR[0]);

  printfp("\n\r");
   for(i = 0; i < SIZEXR; i++)
  {	
 // if(BuffR[i] != (i % 256) )
 // {	flag = 0;
 if(!(i % 16)) printfpd("\n\r %04X>", i);

  //	printfpd(" %d ", i);
	printfpd(" %02X", BuffR[i]);
  //	 break;
 //	 }
  }

// if(flag) printfp("\n\rOk");
// else	  printfp("\n\rNot Ok");


  
}
#endif
#endif





#ifdef PROG_MD310_SAT
#ifndef PROG_MD310_SATI2

#include "md310_work1.cpp"


#else
#ifndef PROG_ODU1
#include "md310s2_work1.cpp"
#else
#include "odu2_work1.cpp"
#endif

#endif





//#endif

//#else

//#include "vnv_work1.cpp"
#endif

#ifdef PROG_MD310E16

#include "md310e16_work1.cpp"

#endif



extern "C" unsigned short GetDevId(void)
{
return (unsigned short) DevId.Value;
}

#ifdef PROG_BCM
#ifdef USE_HTTP
#include "web_bcm.cpp"
#endif
#endif

