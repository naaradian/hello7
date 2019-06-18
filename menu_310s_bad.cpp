//menu_310s.cpp


  LogoItem.Init(&theAnyStrings.cLogoLd[0], 
  //	&theAnyStrings.cConfig[0],
	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //t   NULL, NULL, NULL, &ConfigItem,
//#ifndef PROG_PU_MSAT
   &LogoItem, &LogoItem,&LogoItem, &ConfigItem,			  //system
 //  &ConfigItem, &ConfigItem,&ConfigItem, &ConfigItem,
//#else
//    &LogoItem, &LogoItem,&LogoItem, &SatSystemItem,
//#endif

//#ifndef PROG_PU_MSAT
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

//#else
  //	&SatLock, &SatXilBlock, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
// 	&SatLock, &SatXilBlock, &SatTestModeI, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
   //	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);	//t
//#endif
//___________________________________________
//#ifndef PROG_PU_MSAT
  ConfigItem.Init(&theAnyStrings.cLogoLd[0], 	 //system
 //  ConfigItem.Init(&theAnyStrings.cConfig[0], 
//#else
 // ConfigItem.Init(&theAnyStrings.cLogoLd1[0],
//#endif
  	&theAnyStrings.cConfig[0],					  //system
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//#ifndef PROG_PU_MSAT
 //   &ConfigItem, &ConfigItem, &LogoItem, &TestItem,
 //   &ConfigItem, &ConfigItem, &LogoItem, &ConfigItem,	//t
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

//#else
	  &SatSystemItem, &SatIndicationItem, &LogoItem, &TestItem,
//	  NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

//#endif
   
//___________________________________________
 IPItem.Init(&theAnyStrings.cIPAddrU[0], 
  	&theAnyStrings.cIPAddrL[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
  // &IdItem, &AddressRS485Item, &ConfigItem, NULL,
#ifdef CLOCK_ENABLED
#ifndef USE_HTTP
  &TimeItem, &AddressRS485Item, &ConfigItem, NULL,
#else
  &TimeItem, &WebPasswordItem, &ConfigItem, NULL,
#endif
#else
   &XilinxItem, &AddressRS485Item, &ConfigItem, NULL,
#endif
  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
//___________________________________________
//___________________________________________
 AddressRS485Item.Init(&theAnyStrings.cAddrRS485[0], 
  	&theAnyStrings.cEmpty[0],
  	1,
 //   &IPItem, &MACItem, &ConfigItem, NULL,
#ifndef USE_HTTP
//140203   &TestItem, &IdItem, &ConfigItem, NULL,
    &IPItem, &IdItem, &ConfigItem, NULL,
#else
 //140203   &WebPasswordItem, &TestItem, &ConfigItem, NULL,
    &WebPasswordItem, &IdItem, &ConfigItem, NULL,
#endif
  	NULL, NULL, NULL, NULL, NULL,  &UARTAddress,   NULL,  NULL,  NULL, NULL, NULL);
//___________________________________________
//___________________________________________
//140203 IdItem.Init(&theAnyStrings.cId[0], 
 IdItem.Init(&theAnyStrings.cIdInd[0], 
 // 	&theAnyStrings.cVer[0],
  &theAnyStrings.cEmpty[0],


  	1,
 //140203   &TestItem, &IPItem, &ConfigItem, NULL,
 #ifndef PROG_PU_MSAT

    &AddressRS485Item, &TestItem, &ConfigItem, NULL, 
#else
	 &AddressRS485Item, &SatALevItem, &ConfigItem, NULL,
#endif

 //140203 	NULL, NULL, NULL, NULL, NULL,  &DevId,   &DevYear,  &DevVer1,  &DevVer2, NULL, NULL);
  	NULL, NULL, NULL, NULL, NULL,  &DevId,    NULL,   NULL,   NULL, NULL, NULL);
//___________________________________________

#ifdef PROG_PU_MSAT
SatALevItem.Init(&theAnyStrings.cSatALev[0], 
  	&theAnyStrings.cEmpty[0],
  	1,
    &IdItem, &SatACodeItem, &ConfigItem, NULL,	  //130415
  	&SatALev,NULL, NULL, NULL, NULL, NULL,  NULL, NULL,  NULL, NULL, NULL);

SatACodeItem.Init(&theAnyStrings.cSatACode[0], 
  	&theAnyStrings.cEmpty[0],
  	1,
    &SatALevItem, &SatADemoItem, &ConfigItem, NULL,	  //130415
  	NULL,NULL, NULL, NULL, NULL, &SatACode,  NULL, NULL,  NULL, NULL, NULL);

SatADemoItem.Init(&theAnyStrings.cSatADemo[0], 
  	&theAnyStrings.cEmpty[0],
  	1,
    &SatACodeItem, &TestItem, &ConfigItem, NULL,	  //130415
  	&SatADemo,NULL, NULL, NULL, NULL, &SatACnt,  NULL, NULL,  NULL, NULL, NULL);




#endif


//___________________________________________
 TestItem.Init(&theAnyStrings.cTestMode[0], 
  	&theAnyStrings.cPOK[0],
  	1,
  //  &XilinxItem, &IdItem, &ConfigItem, NULL,
#ifndef PROG_PU_MSAT
 //140203   &AddressRS485Item, &XilinxItem, &ConfigItem, NULL,
    &IdItem, &XilinxItem, &ConfigItem, NULL,
#else
 //140203   &AddressRS485Item, &SatSet3Item, &ConfigItem, NULL,	  //130415
 //140204   &IdItem, &SatSet3Item, &ConfigItem, NULL,	  //130415
 //140227   &SatADemoItem, &SatSet3Item, &ConfigItem, NULL,	  //130415
    &SatADemoItem, &XilinxItem, &ConfigItem, NULL,	  //140227
#endif

  	NULL, NULL, NULL, NULL, NULL,  &POK, &TestMode,  NULL,  NULL, NULL, NULL);
//___________________________________________
 //___________________________________________
 MACItem.Init(&theAnyStrings.cMACAddress[0], 
  	&theAnyStrings.cMACData[0],
  	1,
//#ifndef PROG_PU_MSAT
    &AddressRS485Item, &XilinxItem, &ConfigItem, NULL,
//#else
//    &AddressRS485Item, &SatSet0Item, &ConfigItem, NULL,
//#endif

  	NULL, NULL, NULL, NULL, NULL, &MAC0, &MAC1,  NULL,  NULL, NULL, NULL);
//___________________________________________
//___________________________________________









 XilinxItem.Init(&theAnyStrings.cXilinxFile[0], 
  	&theAnyStrings.cEmpty[0],
	1,
#ifndef PROG_PU_MSAT
 //   &MACItem, &TestItem, &ConfigItem, NULL,

#ifdef CLOCK_ENABLED
  &TestItem, &DateItem, &ConfigItem, NULL,
#else
    &TestItem, &IPItem, &ConfigItem, NULL,
#endif  
#else
//    &SatPCItem, &TestItem, &ConfigItem, NULL,

#ifdef CLOCK_ENABLED
 //140227   &SatSet3Item, &DateItem, &ConfigItem, NULL,
  &TestItem, &DateItem, &ConfigItem, NULL, //140227
#else
//140227    &SatSet3Item, &IPItem, &ConfigItem, NULL,
  &TestItem, &IPItem, &ConfigItem, NULL,	  //140227
#endif  
   
#endif
   NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, &XilFileData, NULL);

#ifdef USE_HTTP

 WebPasswordItem.Init(&theAnyStrings.cWebPassword[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &IPItem, &AddressRS485Item, &ConfigItem, NULL,
    NULL, NULL, NULL, NULL, NULL, &WebPassword, NULL,  NULL,  NULL, NULL, NULL);
									  

#endif





//#ifdef PROG_PU_MSAT
#ifdef CLOCK_ENABLED
   
 DateItem.Init(&theAnyStrings.cDate[0], 
  	&theAnyStrings.cDated[0],
	1,
    &XilinxItem, &TimeItem, &ConfigItem, NULL,
    NULL, NULL, NULL, NULL, NULL, &TimeData4, &TimeData5,  &TimeData6,  NULL, NULL, NULL);
 //   NULL, NULL, NULL, NULL, NULL, &TimeData6,&TimeData5, NULL, NULL, NULL, NULL);

 TimeItem.Init(&theAnyStrings.cTime[0], 
  	&theAnyStrings.cTimed[0],
	1,
    &DateItem, &IPItem, &ConfigItem, NULL,
    NULL, NULL, NULL, NULL, NULL, &TimeData3, &TimeData2, &TimeData1,  NULL, NULL, NULL);
  //    NULL, NULL, NULL, NULL, NULL, NULL, NULL, &TimeData1,  NULL, NULL, NULL);
   
#endif
//#endif // PROG_PU_MSAT

//#endif  

	

SatTestModeItem.Init(&theAnyStrings.cSatTestMode[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //130412   &SatSet8Item, &SatPCItem, &SatSystemItem, NULL,
//1304161    &SatSet8Item, &SatTimingItem, &SatSystemItem, NULL,	 //130412
//130423    &SatDFItem, &SatTimingItem, &SatSystemItem, NULL,	 //1304161
    &SatSet5Item, &SatTimingItem, &SatSystemItem, NULL,	 //1304161
  	&SatTestMode, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

//_____________________________________________ nou used from 130412
SatPCItem.Init(&theAnyStrings.cSatPC[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatTestModeItem, &SatTimingItem, &SatSystemItem, NULL,
  	&SatPC, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
//_______________________________________________

SatTimingItem.Init(&theAnyStrings.cSatTiming[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //   &SatPCItem, &SatSet0Item, &SatSystemItem, NULL,
//130412    &SatPCItem, &SatSoundItem, &SatSystemItem, NULL,

     &SatTestModeItem,  &SatSet3Item,  &SatSystemItem, NULL,	//140227


//#ifndef RECEIVE_MOD_LOCK
//    &SatTestModeItem, &SatSoundItem, &SatSystemItem, NULL,	//130412

//#else
//   &SatTestModeItem, &SatExtLockItem, &SatSystemItem, NULL,	//130412
//#endif


  	&SatTiming, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
//______________________________________
#ifdef RECEIVE_MOD_LOCK
	 	 
SatExtLockItem.Init(&theAnyStrings.cSatExtLock[0], 
  	&theAnyStrings.cEmpty[0],
	1,
// 140227   &SatTimingItem, &SatExtLockPItem, &SatSystemItem, NULL,	//130412
    &SatSet3Item, &SatExtLockPItem, &SatSystemItem, NULL,	//130412
  	&SatExtLock, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
	
	 
SatExtLockPItem.Init(&theAnyStrings.cSatExtLockP[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &SatExtLockItem, &SatSoundItem, &SatSystemItem, NULL,	//130412
  	&SatExtLockP, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
	  

#endif
//_______________________________________
SatSoundItem.Init(&theAnyStrings.cSatSound[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130423    &SatTimingItem, &SatFactoryItem, &SatSystemItem, NULL,
#ifndef RECEIVE_MOD_LOCK
 //   &SatTimingItem, &SatTFItem, &SatSystemItem, NULL,
  //140227  &SatTimingItem, &SatLowPItem, &SatSystemItem, NULL,	
    &SatSet3Item, &SatLowPItem, &SatSystemItem, NULL,	 
  #else
 //	&SatExtLockPItem, &SatTFItem, &SatSystemItem, NULL,
	&SatExtLockPItem, &SatLowPItem, &SatSystemItem, NULL,
#endif

  	&SatSound, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

//_________________________________________________________
SatLowPItem.Init(&theAnyStrings.cSatLowP[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &SatSoundItem, &SatTFItem, &SatSystemItem, NULL,	//130412
  	&SatLowP, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);



//_______________________________________________________________130423 do not used
   /*
SatFactoryItem.Init(&theAnyStrings.cSatFactory[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//    &SatSoundItem, &SatSet0Item, &SatSystemItem, NULL,
//130416    &SatSoundItem, &SatDFItem, &SatSystemItem, NULL,
    &SatSoundItem, &SatTFItem, &SatSystemItem, NULL,   //130416
  	&SatFactory, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
   */
//___________________________________________________________________130423 do not used
  /*
SatDFItem.Init(&theAnyStrings.cSatDF[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatFactoryItem, &SatTFItem, &SatSystemItem, NULL,
  	&SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
	*/
//___________________________________________________________________
SatTFItem.Init(&theAnyStrings.cSatTF[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130416    &SatDFItem, &SatSet0Item, &SatSystemItem, NULL,
//130423    &SatFactoryItem, &SatRateItem, &SatSystemItem, NULL,  //130416
 //   &SatSoundItem, &SatRateItem, &SatSystemItem, NULL,  //130416
    &SatLowPItem, &SatRateItem, &SatSystemItem, NULL,  //130416
 //t 	&SatTF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
  	&SatTF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);	//t
//___________________________________________________________________
SatRateItem.Init(&theAnyStrings.cSatRate[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130416    &SatDFItem, &SatSet0Item, &SatSystemItem, NULL,
//    &SatTFItem, &SatSet0Item, &SatSystemItem, NULL,  //130416
    &SatTFItem, &CusDetItem, &SatSystemItem, NULL,  //130416
 //t 	&SatTF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
  	NULL, NULL, NULL, NULL, NULL,  &SatRate, NULL, NULL,  NULL,  NULL, NULL);	//t
//___________________________________________________________________

CusDetItem.Init(&theAnyStrings.cSatSystem[0], 
  	&theAnyStrings.cCusDet[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130416    &SatDFItem, &SatSet0Item, &SatSystemItem, NULL,
//130423    &SatRateItem, &SatSet0Item, &SatSystemItem, &SatSet6Item,  //130416
    &SatRateItem, &SatSet1Item, &SatSystemItem, &SatSet6Item,  //130416
 //t 	&SatTF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
  	NULL, NULL, NULL, NULL, NULL,  NULL, NULL, NULL,  NULL,  NULL, NULL);	//t
//___________________________________________________________________




//______________________________________

SatGet0Item.Init(&theAnyStrings.cSatGet0[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatSearchItem, &SatGet1Item, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet0, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet1Item.Init(&theAnyStrings.cSatGet1[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //   &SatGet0Item, &SatGet2Item, &SatIndicationItem, NULL,
    &SatSearchItem, &SatGet2Item, &SatIndicationItem, NULL,
 //   &SatGet0Item, &SatGet2Item, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet1, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet2Item.Init(&theAnyStrings.cSatGet2[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet1Item, &SatGet3Item, &SatIndicationItem, NULL,
 //   &SatGet1Item, &SatInputItem, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet2, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet3Item.Init(&theAnyStrings.cSatGet3[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //   &SatGet2Item, &SatGet4Item, &SatIndicationItem, NULL,
    &SatGet2Item, &SatInputItem, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet3, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet4Item.Init(&theAnyStrings.cSatGet4[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet3Item, &SatGet5Item, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet4, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet5Item.Init(&theAnyStrings.cSatGet5[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet4Item, &SatGet6Item, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet1, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet6Item.Init(&theAnyStrings.cSatGet6[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet5Item, &SatGet7Item, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet6, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatGet7Item.Init(&theAnyStrings.cSatGet7[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet6Item, &SatInputItem, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet7, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);



SatInputItem.Init(&theAnyStrings.cSatInput[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //   &SatGet7Item, &SatLockItem,&SatIndicationItem, NULL,
//	    &SatGet1Item, &SatSearchItem,&SatIndicationItem, NULL,
	    &SatGet3Item, &SatSearchItem,&SatIndicationItem, NULL,
  	&SatInput, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatLockItem.Init(&theAnyStrings.cSatLock[0], 		//temporari not visible
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatInputItem, &SatSearchItem, &SatIndicationItem, NULL,
  	&SatLock, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatSearchItem.Init(&theAnyStrings.cSatSearch[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //   &SatLockItem, &XilinxItem,&SatIndicationItem, NULL,
 //   &SatLockItem, &SatGet0Item,&SatIndicationItem, NULL,
 //   &SatInputItem, &SatGet0Item,&SatIndicationItem, NULL,
    &SatInputItem, &SatGet1Item,&SatIndicationItem, NULL,
  	&SatSearch, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


SatIndicationItem.Init(&theAnyStrings.cLogoLd1[0], 
  	&theAnyStrings.cSatIndication[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//    &ConfigItem, &SatSystemItem, &LogoItem, &SatGet0Item,
#ifndef YOURNAL
    &ConfigItem, &SatSystemItem, &LogoItem, &SatGet1Item,
#else
    &ConfigItem, &SatLogItem, &LogoItem, &SatGet1Item,
#endif
    NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);



SatSystemItem.Init(&theAnyStrings.cLogoLd1[0], 	   //configuration
  	&theAnyStrings.cSatSystem[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
#ifndef YOURNAL
//130423    &SatIndicationItem, &ConfigItem, &LogoItem, &SatSet0Item,
    &SatIndicationItem, &ConfigItem, &LogoItem, &SatSet1Item,
#else
//130423    &SatLogItem, &ConfigItem, &LogoItem, &SatSet0Item,
//t0709    &SatLogItem, &ConfigItem, &LogoItem, &SatSet1Item,
    &SatLogItem, &ConfigItem, &LogoItem, NULL,
#endif
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


#ifdef YOURNAL

SatLogItem.Init(&theAnyStrings.cLogoLd1[0], 
  	&theAnyStrings.cSatLog[0],
 	1,
    &SatIndicationItem, &SatSystemItem, &LogoItem, &SatLogViewItem,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SatLogViewItem.Init(&theAnyStrings.cEmpty[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &LogClearItem, &LogClearItem,&SatLogItem, NULL,
  	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  &LogStr0, &LogStr1);

LogClearItem.Init(&theAnyStrings.cLogClear[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &SatLogViewItem, &SatLogViewItem,&SatLogItem, NULL,
  	&LogClear, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,   NULL,  NULL);
#endif



#endif

