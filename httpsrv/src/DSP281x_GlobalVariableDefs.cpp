


//###########################################################################
//
// FILE:	DSP281x_GlobalVariableDefs.c
//
// TITLE:	DSP281x Global Variables and Data Section Pragmas.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Added support for C++
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "Expert.h"  		    // Expert Include File
#include "DS2174.h"  		    // DS2174 Include File
#include "menu.h"  		   		// Menu Include File
#include "remote.h"  		    // Remote Include File
#include "expdata.h"  		    // Remote Include File
#include "cs8900.h"  		    // Remote Include File
//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//

#ifdef __cplusplus 
#pragma DATA_SECTION("AdcRegsFile") 
#else 
#pragma DATA_SECTION(AdcRegs,"AdcRegsFile");
#endif 
volatile struct ADC_REGS AdcRegs;


#ifdef __cplusplus 
#pragma DATA_SECTION("CpuTimer0RegsFile") 
#else 
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;


// CPU Timer 1 and Timer2 are reserved for BIOS and thus not used
//#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
//volatile struct CPUTIMER_REGS CpuTimer1Regs;
//#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
//volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaRegsFile") 
#else 
#pragma DATA_SECTION(ECanaRegs,"ECanaRegsFile");
#endif
volatile struct ECAN_REGS ECanaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMboxesFile") 
#else 
#pragma DATA_SECTION(ECanaMboxes,"ECanaMboxesFile");
#endif
volatile struct ECAN_MBOXES ECanaMboxes;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaLAMRegsFile") 
#else 
#pragma DATA_SECTION(ECanaLAMRegs,"ECanaLAMRegsFile");
#endif
volatile struct LAM_REGS ECanaLAMRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMOTSRegsFile") 
#else 
#pragma DATA_SECTION(ECanaMOTSRegs,"ECanaMOTSRegsFile");
#endif
volatile struct MOTS_REGS ECanaMOTSRegs;


//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMOTORegsFile") 
#else 
#pragma DATA_SECTION(ECanaMOTORegs,"ECanaMOTORegsFile");
#endif
volatile struct MOTO_REGS ECanaMOTORegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("EvaRegsFile") 
#else 
#pragma DATA_SECTION(EvaRegs,"EvaRegsFile");
#endif
volatile struct EVA_REGS EvaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("EvbRegsFile") 
#else 
#pragma DATA_SECTION(EvbRegs,"EvbRegsFile");
#endif
volatile struct EVB_REGS EvbRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("GpioDataRegsFile") 
#else 
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("GpioMuxRegsFile") 
#else 
#pragma DATA_SECTION(GpioMuxRegs,"GpioMuxRegsFile");
#endif
volatile struct GPIO_MUX_REGS GpioMuxRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("McbspaRegsFile") 
#else 
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct MCBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("PieCtrlRegsFile") 
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("PieVectTableFile") 
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SciaRegsFile") 
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ScibRegsFile") 
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SpiaRegsFile") 
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SysCtrlRegsFile") 
#else
#pragma DATA_SECTION(SysCtrlRegs,"SysCtrlRegsFile");
#endif
volatile struct SYS_CTRL_REGS SysCtrlRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("DevEmuRegsFile") 
#else
#pragma DATA_SECTION(DevEmuRegs,"DevEmuRegsFile");
#endif
volatile struct DEV_EMU_REGS DevEmuRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("CsmRegsFile") 
#else
#pragma DATA_SECTION(CsmRegs,"CsmRegsFile");
#endif
volatile struct CSM_REGS CsmRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("CsmPwlFile") 
#else
#pragma DATA_SECTION(CsmPwl,"CsmPwlFile");
#endif
volatile struct CSM_PWL CsmPwl;


//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("FlashRegsFile") 
#else
#pragma DATA_SECTION(FlashRegs,"FlashRegsFile");
#endif
volatile struct FLASH_REGS FlashRegs;

#if DSP28_F2812
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("XintfRegsFile") 
#else
#pragma DATA_SECTION(XintfRegs,"XintfRegsFile");
#endif
volatile struct XINTF_REGS XintfRegs;
#endif

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("XIntruptRegsFile") 
#else
#pragma DATA_SECTION(XIntruptRegs,"XIntruptRegsFile");
#endif
volatile struct XINTRUPT_REGS XIntruptRegs;
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ExpertRegsFile") 
#else
#pragma DATA_SECTION(ExpertRegs,"ExpertRegsFile");
#endif
volatile struct Expert_REGS ExpertRegs;
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("Ds2174RegsFile") 
#else
#pragma DATA_SECTION(Ds2174Regs,"Ds2174RegsFile");
#endif
volatile struct DS2174_REGS Ds2174Regs;
//------------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(AnyStrings,"MenuFile");
#endif
//Item BerItem;
AnyStrings theAnyStrings;	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(theCntFunc,"MenuFile");
#endif
//Item BerItem;
CntFunc theCntFunc;
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(LogoItem,"MenuFile");
#endif
//Item BerItem;
Item  LogoItem(&theAnyStrings.cLogoLd[0], 
	&theAnyStrings.cConfig[0],
 	1, &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
  	NULL, NULL, NULL, NULL, NULL, NULL);
// NULL, 0,
  // NULL, NULL);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(CommandItem,"MenuFile");
#endif
Item  CommandItem(&theAnyStrings.cGetCom[0], 
	&theAnyStrings.cEmpty[0],
 	1, &LogoItem, & ErrorItem, &CommandItem, &CommandItem,
 	 &CommandData, NULL, NULL, NULL, NULL, NULL);
 //&theCntFunc, 1, 
 //  &theAnyStrings.cmes0[0],   &theAnyStrings.cmes1[1]);	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ErrorItem,"MenuFile");
#endif
Item  ErrorItem(&theAnyStrings.cBits[0],
				&theAnyStrings.cErr[0],
 	1, &CommandItem, & BerItem, &ErrorItem, &ErrorItem,
 	 NULL, NULL, NULL, &VolNumber, &ErrNumber, NULL);
 //   NULL,   NULL);	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(BerItem,"MenuFile");
#endif
Item  BerItem(&theAnyStrings.cBits[0], 
			  &theAnyStrings.cBer[0],
 	1, &ErrorItem, & LossItem, &BerItem, &BerItem,
 	 NULL, NULL, NULL, &VolNumber, &BerNumber, NULL);
 //   NULL,  NULL);		
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(LossItem,"MenuFile");
#endif
Item  LossItem(&theAnyStrings.cBits[0], 
			   &theAnyStrings.cLoss[0],
 	1, &BerItem, & LogoItem, &LossItem, &LossItem,
 	 NULL, NULL, NULL, &VolNumber, &LossNumber, NULL);
 //   NULL,   NULL);		            
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfClkItem,"MenuFile");
#endif
Item  ConfClkItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cClocks[0],
 	1,  &ConfRemoteItem, &ConfPatItem, &LogoItem, &TrClkItem,
 //1,  &ConfTstItem, &ConfTstItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL);

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfTstItem,"MenuFile");
#endif
Item  ConfTstItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cTest[0],
 	1,  &ConfPatItem, &ConfInterfaceItem, &LogoItem, &InsBerItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &InsBerItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL);
//----------------------------------------
/*
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFileD") 
#else
#pragma DATA_SECTION(ConfTstItem,"MenuFileD");
#endif
Item  ConfTstItem1(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cTest[0],
// 	1,  &ConfClkItem, &ConfInterfaceItem, &LogoItem, &InsBerItem,
 	1, &ConfClkItem, &ConfClkItem, &LogoItem, &InsBerItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL);
 */
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfInterfaceItem,"MenuFile");
#endif
Item  ConfInterfaceItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cInterface[0],
 	1,  &ConfTstItem, &ConfMonitoringItem, &LogoItem, &InTypeItem,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL); 	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfMonitoringItem,"MenuFile");
#endif
Item  ConfMonitoringItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cMonitoring[0],
 	1,  &ConfInterfaceItem, &ConfSynceItem, &LogoItem, &MonitoringVCC18Item,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL);  	 
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfMonitoringItem,"MenuFile");
#endif
Item  MonitoringVCC18Item(&theAnyStrings.cMonitoring[0], 
			   &theAnyStrings.cMonitoringVCC18[0],
 	1,  &MonitoringVCC18Item, &MonitoringVCC18Item, &ConfMonitoringItem, &MonitoringVCC18Item,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, &VCC18Number, NULL, NULL);  	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfSynceItem,"MenuFile");
#endif
Item  ConfSynceItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cmSynce[0],
 	1,  &ConfMonitoringItem, &ConfRemoteItem, &LogoItem, &SynceItem,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL); 	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfRemoteItem,"MenuFile");
#endif
Item  ConfRemoteItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cRemote[0],
 	1,  &ConfSynceItem, &ConfClkItem, &LogoItem, &RemoteItem,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL); 	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RemoteItem,"MenuFile");
#endif
Item  RemoteItem(&theAnyStrings.cRemote[0], 
			   &theAnyStrings.cmRemote[0],
 	1,  &RemoteItem, &RemoteItem, &ConfRemoteItem, &RemoteItem,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &RemBits, &RemParity, NULL, NULL, NULL, &RemNumber); 	
 //----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SynceItem,"MenuFile");
#endif
Item  SynceItem(&theAnyStrings.cmSynce[0], 
			   &theAnyStrings.cmAutoSynce[0],
 	1,  &SynceItem, &SynceItem, &ConfSynceItem, &SynceItem,
 //	1,  &ConfTstItem, &ConfClkItem, &LogoItem, &ConfInterfaceItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &SynceData, NULL, NULL, NULL, NULL, NULL);  
//---------------------------------------- 	 

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfPatItem,"MenuFile");
#endif
Item  ConfPatItem(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cmPatType[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &ConfClkItem,  &ConfTstItem, &LogoItem, &PatItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL); 	
 //   NULL, NULL, NULL, NULL, NULL, NULL); 
 
//---------------------------------------- 	 

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PatItem,"MenuFile");
#endif
Item  PatItem(&theAnyStrings.cmPatType[0], 
			   &theAnyStrings.cEmpty[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &PatItem,  &PatItem, &ConfPatItem, &PatItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &PatType, NULL, NULL, NULL, NULL, NULL); 	    	    
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RtItem,"MenuFile");
#endif
Item  RtItem(&theAnyStrings.cInterface[0], 
			   &theAnyStrings.cRt[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &RdItem, &InTypeItem, &ConfInterfaceItem, &RtItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &PolRtData, NULL, NULL, NULL, NULL, NULL); 	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(TtItem,"MenuFile");
#endif
Item  TtItem(&theAnyStrings.cInterface[0], 
			   &theAnyStrings.cTt[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &InTypeItem, &SdItem, &ConfInterfaceItem, &TtItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &PolTtData, NULL, NULL, NULL, NULL, NULL); 
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RdItem,"MenuFile");
#endif
Item  RdItem(&theAnyStrings.cInterface[0], 
			   &theAnyStrings.cRd[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &SdItem, &RtItem, &ConfInterfaceItem, &RdItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &PolRdData, NULL, NULL, NULL, NULL, NULL); 	 	 
 //   NULL, NULL, NULL, NULL, NULL, NULL); 	 
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SdItem,"MenuFile");
#endif
Item  SdItem(&theAnyStrings.cInterface[0], 
			   &theAnyStrings.cSd[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &TtItem, &RdItem, &ConfInterfaceItem, &SdItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &PolSdData, NULL, NULL, NULL, NULL, NULL); 
//---------------------------------------- 	 

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(InTypeItem,"MenuFile");
#endif
Item  InTypeItem(&theAnyStrings.cmInType[0], 
			   &theAnyStrings.cEmpty[0],
// 	1, &RtItem, &RtItem, &ConfInterfaceItem, &RtItem,
 	1, &RtItem, &TtItem, &ConfInterfaceItem, &InTypeItem,
 //	1, &ConfClkItem, &ConfClkItem, &LogoItem, &TrClkItem,
 	 &InType, NULL, NULL, NULL, NULL, NULL); 	
 //   NULL, NULL, NULL, NULL, NULL, NULL); 	    
//----------------------------------------

/*
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ConfTstItem,"MenuFile");
#endif
Item  ConfTstItem1(&theAnyStrings.cConfig[0], 
			   &theAnyStrings.cTest[0],
// 	1, &ConfClkItem, &ConfClkItem, &LogoItem, &InsBerItem,
 	1, &ConfClkItem, &ConfTstItem, &LogoItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, NULL); 	 
 	 */
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(InsBerItem,"MenuFile");
#endif
Item  InsBerItem(&theAnyStrings.cTest[0], 
			   &theAnyStrings.cInsBer[0],
 	1, &LoopItem, &LoopItem, &ConfTstItem, &InsBerItem,
 	 &InsBerData, NULL, NULL, NULL, NULL, NULL);
//	 	 &CommandData, NULL, NULL, NULL, NULL, NULL);
//	 NULL, NULL, NULL, NULL, NULL, NULL);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(InsBerItem,"MenuFile");
#endif
Item  LoopItem(&theAnyStrings.cTest[0], 
			   &theAnyStrings.cLoop[0],
 	1, &InsBerItem, &InsBerItem, &ConfTstItem, &LoopItem,
 	&LoopData, NULL, NULL, NULL, NULL, NULL);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(TrClkItem,"MenuFile");
#endif
Item  TrClkItem(&theAnyStrings.cTrClocks[0], 
			   &theAnyStrings.cHz[0],
 	1, &TimingItem, &TimingItem, &ConfClkItem, &TrClkItem,
 	 NULL, NULL, NULL, NULL, NULL, &ClkNumber);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(TimingItem,"MenuFile");
#endif
Item  TimingItem(&theAnyStrings.cTrClocks[0], 
			   &theAnyStrings.cmTiming[0],
 	1, &TrClkItem, &TrClkItem, &ConfClkItem, &TimingItem,
 	 &Timing, NULL, NULL, NULL, NULL, NULL); 	 
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(CommandData,"MenuFile");
#endif
MDataV  CommandData( &theAnyStrings.cCommandF[0], 
//					4, 2, 1 ,0x2,
					4, 2, //x,y
					 1 , //changable
					 &ExpertStorage.CMD, //storage addr
					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 5, //chars in one
					  3, // quantity
					&theCntFunc, //pControl
					1, //cntnum control of value
					1, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemCom[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1d[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   1  //remnum //selector for operation if receive remote command
					);	
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(InsBerData,"MenuFile");
#endif
MDataV  InsBerData( &theAnyStrings.cCommandF[0], 
//					4, 2, 1 ,0x2,
					10, 2, //x,y
					 1 , //changable
					 &ExpertStorage.InsBer, //storage addr
					&theAnyStrings.cInsBers[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 5, //chars in one
					  8, // quantity
					&theCntFunc, //pControl
					7, //cntnum control of value
					7, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemIns[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1d[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   7  //remnum //selector for operation if receive remote command
					);						
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PolRtData,"MenuFile");
#endif
MDataV  PolRtData( &theAnyStrings.cCommandP[0], 
//					4, 2, 1 ,0x2,
					8, 2, //x,y
					 1 , //changable
					 &ExpertStorage.PolRt, //storage addr
					&theAnyStrings.cPhase[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 6, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					10, //cntnum control of value
					10, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemPolRt[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   10  //remnum //selector for operation if receive remote command
					);						
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PolTtData,"MenuFile");
#endif
MDataV  PolTtData( &theAnyStrings.cCommandP[0], 
//					4, 2, 1 ,0x2,
					8, 2, //x,y
					 1 , //changable
					 &ExpertStorage.PolTt, //storage addr
					&theAnyStrings.cPhase[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 6, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					17, //cntnum control of value
					17, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemPolTt[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   17  //remnum //selector for operation if receive remote command
					);			
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PolSdData,"MenuFile");
#endif
MDataV  PolSdData( &theAnyStrings.cCommandP[0], 
//					4, 2, 1 ,0x2,
					8, 2, //x,y
					 1 , //changable
					 &ExpertStorage.PolSd, //storage addr
					&theAnyStrings.cPhase[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 6, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					18, //cntnum control of value
					18, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemPolSd[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   18  //remnum //selector for operation if receive remote command
					);	//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PolRdData,"MenuFile");
#endif
MDataV  PolRdData( &theAnyStrings.cCommandP[0], 
//					4, 2, 1 ,0x2,
					8, 2, //x,y
					 1 , //changable
					 &ExpertStorage.PolRd, //storage addr
					&theAnyStrings.cPhase[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 6, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					16, //cntnum control of value
					16, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemPolRd[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   16  //remnum //selector for operation if receive remote command
					);			

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(InType,"MenuFile");
#endif
MDataV  InType( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					4, 2, //x,y
					 1 , //changable
					 &ExpertStorage.InType, //storage addr
					&theAnyStrings.cInType[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 9, //chars in one
					  4, // quantity
					&theCntFunc, //pControl
					11, //cntnum control of value
					11, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemInType[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   11  //remnum //selector for operation if receive remote command
					);											     	     

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(PatType,"MenuFile");
#endif
MDataV  PatType( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					4, 2, //x,y
					 1 , //changable
					 &ExpertStorage.PatType, //storage addr
					&theAnyStrings.cPatType[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 10, //chars in one
//			  5, // quantity
//	  6, // quantity
					//8, // quantity
//					9, // quantity
					10, // quantity
					&theCntFunc, //pControl
					12, //cntnum control of value
					12, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemPatType[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   12  //remnum //selector for operation if receive remote command
					);						

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(Timing,"MenuFile");
#endif
MDataV  Timing( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					9, 2, //x,y
					 1 , //changable
					 &ExpertStorage.Timing, //storage addr
					&theAnyStrings.cTiming[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 6, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					13, //cntnum control of value
					13, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemTiming[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   13  //remnum //selector for operation if receive remote command
					);	

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SynceData,"MenuFile");
#endif
MDataV  SynceData( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					13, 2, //x,y
					 1 , //changable
					 &ExpertStorage.Synce, //storage addr
					&theAnyStrings.cOffOn[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 1, //init value
					 3, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					14, //cntnum control of value
					14, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemSynce[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   14  //remnum //selector for operation if receive remote command
					);	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(LoopData,"MenuFile");
#endif
MDataV  LoopData( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					11, 2, //x,y
					 1 , //changable
					 &ExpertStorage.Loop, //storage addr
					&theAnyStrings.cOffOn[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 1, //init value
					 3, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					15, //cntnum control of value
					15, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemLoop[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   15  //remnum //selector for operation if receive remote command
					);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RemBits,"MenuFile");
#endif
MDataV  RemBits( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					12, 2, //x,y
					 1 , //changable
					 &ExpertStorage.RemBits, //storage addr
					&theAnyStrings.c87[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 1, //chars in one
					  2, // quantity
					&theCntFunc, //pControl
					20, //cntnum control of value
					20, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemBits[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   20  //remnum //selector for operation if receive remote command
					);					
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RemParity,"MenuFile");
#endif
MDataV  RemParity( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					16, 2, //x,y
					 1 , //changable
					 &ExpertStorage.RemParity, //storage addr
					&theAnyStrings.cNEO[0], //variants
//					&cInsBers[0], //variants
//					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 1, //chars in one
					  3, // quantity
					&theCntFunc, //pControl
					21, //cntnum control of value
					21, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[1]	//two line of message
					 , &theAnyStrings.cRemParity[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1X[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   21  //remnum //selector for operation if receive remote command
					);	
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ClkNumber,"MenuFile");
#endif
MDataC  ClkNumber( &theAnyStrings.cFclk[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
				   &ExpertStorage.Clk0, //storageaddr
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
					6,  //cntnum - function for control of value
					6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, decimal			  
		//		4
		,4.0000000e7,  //init value
		&theAnyStrings.cRemClk[0] //remote command
		, &theAnyStrings.c8d[0], //remote format
		 8,  //remchars 
		 6 //remnum
						);		
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(RemNumber,"MenuFile");
#endif
MDataC  RemNumber( &theAnyStrings.cRem[0],  //format
				   3, 2,  //x,y
				   1 ,		//changable
				   &ExpertStorage.Rem0, //storageaddr
//				  40000000l,
				    6,  //chars
//					 3,
					&theCntFunc, //pControl
					19,  //cntnum - function for control of value
					19, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, decimal			  
		//		4
		,1.1520000e5,  //init value
		&theAnyStrings.cRemRem[0] //remote command
		, &theAnyStrings.c8d[0], //remote format
		 8,  //remchars 
		 19 //remnum
						);								     
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SpiData,"MenuFile");
#endif
MDataC  SpiData( &theAnyStrings.c4X[0],  //format
				   1, 1,  //x,y
				   0 ,		// not changable
				   NULL, 
				  // &ExpertStorage.Clk0, //storageaddr
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
					8,  //cntnum - function for control of value
					8, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemSpi[0] //remote command
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 8 //remnum
);	
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SpiCs,"MenuFile");
#endif
MDataC  SpiCs( &theAnyStrings.c4X[0],  //format
				   1, 1,  //x,y
				   0 ,		// not changable
				   NULL, 
				  // &ExpertStorage.Clk0, //storageaddr
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
					9,  //cntnum - function for control of value
					9, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemSpiCs[0] //remote command
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 9 //remnum
);	

//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(SpiCs,"MenuFile");
#endif
MDataC  LEDData( &theAnyStrings.c4X[0],  //format
				   1, 1,  //x,y
				   0 ,		// not changable
				   NULL, 
				  // &ExpertStorage.Clk0, //storageaddr
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
					0,  //cntnum - function for control of value
					0, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemLEDData[0] //remote command
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 0 //remnum
);	
/*
( &theAnyStrings.c8X[0],  //format
				   1, 1,  //x,y
				   0 ,		//not changable
				   NULL, //not have storageaddr
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
					8,  //cntnum - function for control of value
					8, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[1], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, decimal			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemSpi[0] //remote command
		, &theAnyStrings.c8X[0], //remote format
		 8,  //remchars 
		 8 //remnum
						);		
						*/
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(VolNumber,"MenuFile");
#endif
MDataI  VolNumber(&theAnyStrings.cVolume[0], 
					7, 1, 
					&theCntFunc, 2, &theAnyStrings.cRemVol[0]
					, &theAnyStrings.cVolume[0],
					10, //remchars
				//	9,//t
					2, 2
					);					    
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(ErrNumber,"MenuFile");
#endif
MDataI  ErrNumber(&theAnyStrings.cVolume[0], 
					7, 2, 
					&theCntFunc, 3, &theAnyStrings.cRemErr[0]
					 , &theAnyStrings.cVolume[0],10, 3, 3
										  );					    
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(BerNumber,"MenuFile");
#endif
MDataI  BerNumber(&theAnyStrings.cVolume[0], 
					7, 2, 
					&theCntFunc, 4, &theAnyStrings.cRemBer[0]
					, &theAnyStrings.cVolume[0],10, 4, 4
					);					    
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(LossNumber,"MenuFile");
#endif
MDataI  LossNumber(&theAnyStrings.cVolume[0], 
					7, 2, 
					&theCntFunc, 5, &theAnyStrings.cRemLoss[0]
					, &theAnyStrings.cVolume[0],10, 5, 5
					);					    
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(VCC18Number,"MenuFile");
#endif
MDataI  VCC18Number(&theAnyStrings.cVCC18[0], //format
					11, //x
					2, //y
					&theCntFunc,
					 22, //control
					 &theAnyStrings.cRemVCC18[0]//remote
					, &theAnyStrings.cVCC18[0] //remformat
					,4 //remcars
					, 22, //remnum -not need
					 22 //cntnum
					);
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(UsedMenu,"MenuFile");
#endif
//Menu UsedMenu(&TrClkItem, 100);
//Menu UsedMenu(&CommandItem, 100); //100 - redrawPeriod - period celling for MDataI.
//Menu UsedMenu(&LogoItem, 2100000l); //100 - redrawPeriod - period celling for MDataI.
Menu UsedMenu(&ErrorItem, 
//210000l
//20000); //100 - redrawPeriod - period celling for MDataI.
//15000); //100 - redrawPeriod - period celling for MDataI.
//7000); //100 - redrawPeriod - period celling for MDataI.
//70); //to timer /128
//7); //to timer /128, /10
4); //to timer /128, /2
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(UsedRemote,"MenuFile");
#endif
Remote UsedRemote; //
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ExpertStorageFile") 
#else
#pragma DATA_SECTION(ExpertStorage,"ExpertStorageFile");
#endif
volatile struct Expert_STORAGE ExpertStorage;
//----------------------------------------

#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(UsedExp,"MenuFile");
#endif
ExDt UsedExp;
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ExpertCS8900File") 
#else
#pragma DATA_SECTION(ExCs8900,"ExpertCS8900File");
#endif
volatile struct Expert_CS8900 ExCs8900;
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ExpertCP2200File") 
#else
#pragma DATA_SECTION(CP2200regs,"ExpertCP2200File");
#endif
volatile struct Expert_CP2200 CP2200regs;
//----------------------------------------

// The following are provided to support alternate notation
// that was used in an early version of the header files 

#define ADCRegs       AdcRegs
#define CPUTimer0Regs CpuTimer0Regs
#define ECANARegs     ECanaRegs
#define ECANAMboxes   ECanaMboxes
#define EVARegs       EvaRegs
#define GPIODataRegs  GpioDataRegs
#define GPIOMuxRegs   GpioMuxRegs
#define MCBSPARegs    McbspaRegs
#define PIECtrlRegs   PieCtrlRegs
#define PIEVectTable  PieVectTable
#define SCIARegs      SciaRegs
#define SCIBRegs      ScibRegs
#define SYSCtrlRegs   SysCtrlRegs
#define DEVEmuRegs    DevEmuRegs
#define CSMRegs       CsmRegs
#define CSMPwl        CsmPwl
#define FLASHRegs     FlashRegs
#define XINTFRegs     XintfRegs
#define XINTRUPTRegs  XIntruptRegs
#define EXPERTRegs    ExpertRegs
#define DS2174Regs    Ds2174Regs
#define EXPERTStorage ExpertStorage
#define USEDMenu      UsedMenu
#define USEDRemote    UsedRemote
#define USEDExpert    UsedExpert
#define CNTFunc		  theCntFunc







