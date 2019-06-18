
//MDataV	BUC24V;
//MDataV	BUC10M;
//MDataV	LNB15V;
//MDataV	LNB10M;









//SatSystemItem.Init(&theAnyStrings.cLogoLd[0], 	  //configuration
//  	&theAnyStrings.cSatSystem[0],
// 	1,
//    &SaveLoadItem, &ConfigItem, &LogoItem, &ModulatorItem,//&SatSet1Item,
//  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

  

 


ExtDevItem.Init(&theAnyStrings.cLogoLd1[0], 	  //configuration
 // 	&theAnyStrings.cSatSystem[0],
  	&theAnyStrings.cExtDev[0],
 //	&theAnyStrings.cLogoLd[0],
 	1,
    &SatIndicationItem, &SatLogItem,&LogoItem, &BucItem,//&SatSet1Item,
 //   &ConfigItem, &SatIndicationItem, &LogoItem, NULL,//&SatSet1Item,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

 
BucItem.Init(&theAnyStrings.cExtDev[0], 	  //configuration
  	&theAnyStrings.cBuc[0],
 	1,
    &LnbItem, &LnbItem, &ExtDevItem, &Buc24VItem,//&SatSet1Item,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


Buc24VItem.Init(&theAnyStrings.cBuc[0], 	  //configuration
  	&theAnyStrings.cBuc24[0],
 	1,
    &Buc10MItem, &Buc10MItem, &BucItem, NULL,//&SatSet1Item,
//  	 &SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
	 &BUC24, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


Buc10MItem.Init(&theAnyStrings.cBuc[0], 	  //configuration
  	&theAnyStrings.cBuc10[0],
 	1,
    &Buc24VItem, &Buc24VItem, &BucItem, NULL,//&SatSet1Item,
 	 &BUC10, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
 //	  &SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


LnbItem.Init(&theAnyStrings.cExtDev[0], 	  //configuration
  	&theAnyStrings.cLnb[0],
 	1,
    &BucItem, &BucItem, &ExtDevItem, &Lnb15VItem,//&SatSet1Item,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


Lnb15VItem.Init(&theAnyStrings.cLnb[0], 	  //configuration
   	&theAnyStrings.cLnb15[0],
 	1,
    &Lnb10MItem, &Lnb10MItem, &LnbItem, NULL,//&SatSet1Item,
  	 &LNB15, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
//	 &SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


Lnb10MItem.Init(&theAnyStrings.cLnb[0], 	  //configuration
   	&theAnyStrings.cLnb10[0],
 	1,
    &Lnb15VItem, &Lnb15VItem, &LnbItem, NULL,//&SatSet1Item,
  	 &LNB10, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
//    &SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

  
  
// extern "C" Item::Init(char* l0, char* l1, 
//		char v,Item* SetLeft,
// Item* SetRight, Item* SetUp, Item* SetDown,
// MDataV * SetpDataP0, MDataV * SetpDataP1, MDataV * SetpDataP2,
// MDataI* SetpDataI0, MDataI* SetpDataI1,
// MDataC* SetpDataC0,MDataC* SetpDataC1, MDataC* SetpDataC2,MDataC* SetpDataC3,
//  MDataS* SetpDataS0, MDataS* SetpDataS1)
