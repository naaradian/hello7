//#include "pvg610_api.h"

extern "C" void InitStructs()
{

dev1.md100se.rezerved1 = 2;// modem 2 core


dev1.md100se.ConfigFile = ConfigFile.Value;
dev1.md100se.ModEth = ModEth.Value;
dev1.md100se.MOutLev0 = ((unsigned)MOutLev.Value*10 )  & 0xff;
dev1.md100se.MOutLev1 = ((unsigned)(MOutLev.Value*10) >> 8) & 0xff;
//dev1.md100se.MOutLev1 = ((signed)MOutLev1.Value )  & 0xff;



dev1.md100se.MTFreq0 = (unsigned)MTFreq.Value *10000l;
dev1.md100se.MTFreq1 = (unsigned)MTFreq.Value *10000l >> 8;
dev1.md100se.MTFreq2 = (unsigned)MTFreq.Value *10000l >> 16;
dev1.md100se.MTFreq3 = (unsigned)MTFreq.Value *10000l >> 24;

dev1.md100se.MRFreq0 = (unsigned)MRFreq.Value *10000l;
dev1.md100se.MRFreq1 = (unsigned)MRFreq.Value *10000l >> 8;
dev1.md100se.MRFreq2 = (unsigned)MRFreq.Value *10000l >> 16;
dev1.md100se.MRFreq3 = (unsigned)MRFreq.Value *10000l >> 24;
			   //ok
dev1.md100se.MDemod = MDemod.Value;
dev1.md100se.MEthMode = MEthMode.Value;
dev1.md100se.MEthPause = MEthPause.Value;
dev1.md100se.MEthctl = MEthctl.Value;

dev1.md100se.MEthMaxF0 = MEthMaxF.Value;
dev1.md100se.MEthMaxF1 = (unsigned)MEthMaxF.Value >> 8;

dev1.md100se.MEthVlanP  = MEthVlanP.Value;	  

dev1.md100se.MTEbN00 = (unsigned)MTEbN0.Value * 10l;
dev1.md100se.MTEbN01 = ((unsigned)MTEbN0.Value * 10l) << 8;

dev1.md100se.MTBER0 = (unsigned)MTBER.Value * 10l;
dev1.md100se.MTBER1 = ((unsigned)MTBER.Value * 10l) << 8;;
dev1.md100se.MTBERE =  MTBERE.Value;
			
dev1.md100se.MIfLoop =  MIfLoop.Value;

dev1.md100se.MUnModul =  MUnModul.Value;


dev1.md100se.MACMM =  MACMM.Value;


	  



}




extern "C" void FillFirmwareFileData(void)
{
 char * pData;
 int i;

  unsigned int source_addr;

	source_addr = (unsigned int)XilFileDataAddressD2;
 read_dataflash (source_addr,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);

// for(i = 0; i < TBUFF1_VALUE; i++)
 for(i = 0; i < DISP_LEN; i++)
 {
 FirmFileData.Value[i] = *pData++;
 }
} 

extern "C" void CheckParameters()
{

// unsigned char ret = 1;
 // UsedMenu.DrawMessage("     Check Parameters    ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //dev1.md100se.ConfigFile = ConfigFile.Value;   //t

  if(ConfigFile.Value > MAX_NUM_CFG)
{
 
 //UsedMenu.DrawMessage("ConfigFile Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
   ConfigFile.Value = 0;
   ConfigFile.ChangingValue = 0;
}


  if(ConfigFile1.Value > MAX_NUM_CFG)
{
 
// UsedMenu.DrawMessage("ConfigFile1 Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
   ConfigFile1.Value = 0;
   ConfigFile1.ChangingValue = 0;
}



if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
 {

// UsedMenu.DrawMessage("SatSound Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);


 SatSound.Value = MIN_SATSOUND;
 SatSound.ChangingValue = MIN_SATSOUND;
 }




  if((LoadVariants.Value < MIN_LOADVARIANTS) || (LoadVariants.Value > MAX_LOADVARIANTS))
{
 
 //UsedMenu.DrawMessage("LoadVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
   LoadVariants.Value = 0;
   LoadVariants.ChangingValue = 0;
}

  if((SaveVariants.Value < MIN_SAVEVARIANTS) || (SaveVariants.Value > MAX_SAVEVARIANTS))
{
 //UsedMenu.DrawMessage("SaveVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
 
   SaveVariants.Value = MIN_SAVEVARIANTS;
   SaveVariants.ChangingValue = MIN_SAVEVARIANTS;
}

#ifdef PRINT_ETH

 //  printfpd(" MEthMode: 0x%02X ",MEthMode.Value);

#endif

  if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{

 //UsedMenu.DrawMessage("Ethernet Mode Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MEthMode.Value = MIN_METHMODE;
 MEthMode.ChangingValue = MEthMode.Value; 
}




  if((MRfOut.Value < MIN_MRFOUT) || (MRfOut.Value > MAX_MRFOUT))
{

// UsedMenu.DrawMessage("1:RfOut  On/Off Is Wrong",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MRfOut.Value = MIN_MRFOUT;
 MRfOut.ChangingValue = MRfOut.Value; 
}


 // printfpdv(" MOut: % 5.3f",MOutLev.Value);
 //  printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
// printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



  if((MOutLev.Value < (float64)MIN_MOUTLEV) || (MOutLev.Value > (float64)MAX_MOUTLEV))
{
// UsedMenu.DrawMessage(" OutLev  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev.Value = MIN_MOUTLEV;
 MOutLev.ChangingValue = MOutLev.Value; 
}
  /* 
  if((MOutLev1.Value < (float64)MIN_MOUTLEV1) || (MOutLev1.Value > (float64)MAX_MOUTLEV1))
{
 UsedMenu.DrawMessage(" OutLev1  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev1.Value = MIN_MOUTLEV1;
 MOutLev1.ChangingValue = MOutLev1.Value; 
}
   	
  if((MOutLev2.Value < (float64)MIN_MOUTLEV2) || (MOutLev2.Value > (float64)MAX_MOUTLEV2))
{
 UsedMenu.DrawMessage(" OutLev2  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev2.Value = MIN_MOUTLEV2;
 MOutLev2.ChangingValue = MOutLev2.Value; 
}

 */


  if((MOutLevO.Value < (float64)MIN_MOUTLEVO) || (MOutLevO.Value > (float64)MAX_MOUTLEVO))
{
 //UsedMenu.DrawMessage("OutLevOffs    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevO.Value = (unsigned)MAX_MOUTLEVO >> 1;
 MOutLevO.ChangingValue = MOutLevO.Value; 
}


 if((MOutLevOS.Value < (float64)MIN_MOUTLEVOS) || (MOutLevOS.Value > (float64)MAX_MOUTLEVOS))
{
 // UsedMenu.DrawMessage("  OutLevOSign  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevOS.Value = (unsigned)MAX_MOUTLEVOS;
 MOutLevOS.ChangingValue = MOutLevOS.Value; 
}

 if((MKOUT.Value < (float64)MIN_MKOUT) || (MKOUT.Value > (float64)MAX_MKOUT))
{
//  UsedMenu.DrawMessage("  MKOUT  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKOUT.Value = (unsigned)MAX_MKOUT >> 1;
 MKOUT.ChangingValue = MKOUT.Value; 
}

 if((MKOUT1.Value < (float64)MIN_MKOUT1) || (MKOUT1.Value > (float64)MAX_MKOUT1))
{
  //UsedMenu.DrawMessage("  MKOUT1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKOUT1.Value = (unsigned)MAX_MKOUT1;
 MKOUT1.ChangingValue = MKOUT1.Value; 
}

 if((MKIN1.Value < (float64)MIN_MKIN1) || (MKIN1.Value > (float64)MAX_MKIN1))
{
 // UsedMenu.DrawMessage("  MKIN1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN1.Value = (unsigned)MAX_MKIN1;
 MKIN1.ChangingValue = MKIN1.Value; 
}

 if((MKIN1.Value < (float64)MIN_MKIN1) || (MKIN1.Value > (float64)MAX_MKIN1))
{
 // UsedMenu.DrawMessage("  MKIN1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN1.Value = (unsigned)MAX_MKIN1;
 MKIN1.ChangingValue = MKIN1.Value; 
}

 if((MKIN2.Value < (float64)MIN_MKIN2) || (MKIN2.Value > (float64)MAX_MKIN2))
{
 // UsedMenu.DrawMessage("  MKIN2  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN2.Value = (unsigned)MAX_MKIN2;
 MKIN2.ChangingValue = MKIN2.Value; 
}

 if((MKIN3.Value < (float64)MIN_MKIN3) || (MKIN3.Value > (float64)MAX_MKIN3))
{
 // UsedMenu.DrawMessage("  MKIN3  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN3.Value = (unsigned)MAX_MKIN3;
 MKIN3.ChangingValue = MKIN3.Value; 
}






  
if((MTDRate.Value < MIN_MTDRATE) || (MTDRate.Value > MAX_MTDRATE))
{
// UsedMenu.DrawMessage("1TDRate  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}
  /*

if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
 UsedMenu.DrawMessage(" RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);

 printfpdv("\n\r 1 wrong RDRate: % 5.3f",MRDRate.Value);	//is zero

  Ring(1,1,5,2);

// printfpdv("\n\r RDRate: % 5.3f",MRDRate.Value);	//is zero
 // printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
 //printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



 MRDRate.Value = MAX_MRDRATE;
 MRDRate.ChangingValue = MRDRate.Value; 
}
   */

 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 

  if((MTFreq.Value < MIN_MTFREQ) || (MTFreq.Value > MAX_MTFREQ))
{
 // UsedMenu.DrawMessage("1 TFreq    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 //UsedMenu.DrawMessage(" RFreq     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 //UsedMenu.DrawMessage(" TModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTModul.Value = MIN_MTMODUL;
 MTModul.ChangingValue = MTModul.Value;
}
  /*
 if((MRateE.Value < MIN_MRATEE) || (MRateE.Value > MAX_MRATEE))
{
 UsedMenu.DrawMessage(" MRateE    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRateE.Value = MIN_MRATEE;
 MRateE.ChangingValue = MRateE.Value;
}
   */


 if((MRModul.Value < MIN_MRMODUL) || (MRModul.Value > MAX_MRMODUL))
{
 //UsedMenu.DrawMessage(" RModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
//	 UsedMenu.DrawMessage(" TCdType Is Wrong    ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
 //	UsedMenu.DrawMessage(" RCdType Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

		 MRCdType.Value = MIN_MRCDTYPE;
		 MRCdType.ChangingValue = MRCdType.Value;
  	}
	  
    if((MTMode.Value < MIN_MTMODE) || (MTMode.Value > MAX_MTMODE))
	{
 //   UsedMenu.DrawMessage(" TMode   Is Wrong        ",&theAnyStrings.cEmpty[0]);
 	 Ring(1,1,5,2);
	 	MTMode.Value = MIN_MTMODE;
 		MTMode.ChangingValue = MTMode.Value;
	}

    if((MRMode.Value < MIN_MRMODE) || (MRMode.Value > MAX_MRMODE))
	{
  //	 UsedMenu.DrawMessage(" RMode   Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
 	MRMode.Value = MIN_MRMODE;
 		MRMode.ChangingValue = MRMode.Value;
	}

    if((MRCntl.Value < MIN_MRCNTL) || (MRCntl.Value > MAX_MRCNTL))
	{
  //	  printfp("\n\r set default mrnctl");

  //  UsedMenu.DrawMessage(" RCntl    Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
	 	MRCntl.Value = MIN_MRCNTL;
 		MRCntl.ChangingValue = MRCntl.Value;
	}

 // 	printfpd("\n\r mrnctl : %d", MRCntl.Value);


 //MRModul.Value = 0;
 //MRModul.ChangingValue = MRModul.Value;
    if((MTCode.Value < MIN_MTCODE) || (MTCode.Value > MAX_MTCODE))
	{
  //	 UsedMenu.DrawMessage(" TCode     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
	MTCode.Value = MIN_MTCODE;
 		MTCode.ChangingValue = MTCode.Value;
   }




    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
 // UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
// UsedMenu.DrawMessage("1 Demod On/Off  Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}

 if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{											 
 // UsedMenu.DrawMessage(" EthMode   Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthMode.Value = 0;
 MEthMode.ChangingValue = MEthMode.Value;
 }

 if((MEthPause.Value < MIN_METHPAUSE) || (MEthPause.Value > MAX_METHPAUSE))
{
 // UsedMenu.DrawMessage(" EthPause   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthPause.Value = 0;
 MEthPause.ChangingValue = MEthPause.Value;
}

 MEthModeI.Value = 0;
 MEthModeI.ChangingValue = MEthModeI.Value;

 if((MEthMaxF.Value < MIN_METHMAXF) || (MEthMaxF.Value > MAX_METHMAXF))
{
 // UsedMenu.DrawMessage(" EthMaxF    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 
 MEthMaxF.Value = MAX_METHMAXF;
 MEthMaxF.ChangingValue = MEthMaxF.Value;
}

 if((MEthVlanP.Value < MIN_METHVLANP) || (MEthVlanP.Value > MAX_METHVLANP))
{

 // UsedMenu.DrawMessage(" EthVlanP    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MEthVlanP.Value = MIN_METHVLANP;
 MEthVlanP.ChangingValue = MEthVlanP.Value;
}


MEbN0.Value = 10.1;

 if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
// UsedMenu.DrawMessage(" TEbN0    Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTEbN0.Value = MIN_MTEBN0;
MTEbN0.ChangingValue = MTEbN0.Value;
}


MBER.Value = (float)0.0;
MBERE.Value = MIN_MTBERE;	//e-10
MBERE.ChangingValue = MTBERE.Value;


 if((MTBER.Value < MIN_MTBER) || (MTBER.Value > MAX_MTBER))
{
 //UsedMenu.DrawMessage(" TBER      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value < MIN_MTBERE) || (MTBERE.Value > MAX_MTBERE))
{
 //UsedMenu.DrawMessage(" TBERE     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBERE.Value = MIN_MTBERE;	//e-10
MTBERE.ChangingValue = MTBERE.Value;
}


#ifdef RACM

 if((RACMOnOff.Value < MIN_RACM) || (RACMOnOff.Value > MAX_RACM))
{
 //UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOnOff.Value = MIN_RACM;	//e-10
RACMOnOff.ChangingValue = MIN_RACM;
}

 if((RACMOnOffT.Value < MIN_RACM) || (RACMOnOffT.Value > MAX_RACM))
{
 //UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOnOffT.Value = MIN_RACM;	//e-10
RACMOnOffT.ChangingValue = MIN_RACM;
}

 if((RACMOffset.Value < MIN_RACMOffset) || (RACMOffset.Value > MAX_RACMOffset))
{
 //UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOffset.Value = 0;	//e-10
RACMOffset.ChangingValue = 0;
}




//ratimelock



 if((ratimelock.Value < MIN_ratimelock) || (ratimelock.Value > MAX_ratimelock))
{
// UsedMenu.DrawMessage(" ratimelock     Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
ratimelock.Value = MIN_ratimelock;	//e-10
ratimelock.ChangingValue = MIN_ratimelock;
}


 if((ratimemode.Value < MIN_ratimemode) || (ratimemode.Value > MAX_ratimemode))
{
// UsedMenu.DrawMessage(" ratimemode     Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
ratimemode.Value = MIN_ratimemode;	//e-10
ratimemode.ChangingValue = MIN_ratimemode;
}

 if((ratimemse.Value < MIN_ratimemse) || (ratimemse.Value > MAX_ratimemse))
{
// UsedMenu.DrawMessage(" ratimemse     Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
ratimemse.Value = MIN_ratimemse;	//e-10
ratimemse.ChangingValue = MIN_ratimemse;
}

 if((ratimestep.Value < MIN_ratimestep) || (ratimestep.Value > MAX_ratimestep))
{
// UsedMenu.DrawMessage(" ratimestep     Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);
ratimestep.Value = MIN_ratimestep;	//e-10
ratimestep.ChangingValue = MIN_ratimestep;
}
  
for(unsigned iu = 0; iu < 16; iu++)
 {


 if((uebn[iu].Value < MIN_uebn) || (uebn[iu].Value > MAX_uebn))
{
// UsedMenu.DrawMessage(" umse   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
uebn[iu].Value = MAX_uebn_DEFAULT;	//e-10
uebn[iu].ChangingValue = uebn[iu].Value;
}

 if((debn[iu].Value < MIN_uebn) || (debn[iu].Value > MAX_uebn))
{
// UsedMenu.DrawMessage(" dmse   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
debn[iu].Value = MIN_uebn_DEFAULT;	//e-10
debn[iu].ChangingValue = debn[iu].Value;
}


 if((enamode[iu].Value < MIN_enamode) || (enamode[iu].Value > MAX_enamode))
{
// UsedMenu.DrawMessage(" enamode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
enamode[iu].Value = MAX_enamode;	//e-10
enamode[iu].ChangingValue = MAX_enamode;
}

 if((numode[iu].Value < MIN_numode) || (numode[iu].Value > MAX_numode))
{
// UsedMenu.DrawMessage(" numode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
numode[iu].Value = iu+1;  if(numode[iu].Value > MAX_numode)    numode[iu].Value = MAX_numode;
numode[iu].ChangingValue = numode[iu].Value;
}

 if((ndmode[iu].Value < MIN_numode) || (ndmode[iu].Value > MAX_numode))
{
// UsedMenu.DrawMessage(" ndmode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
if(iu) ndmode[iu].Value = iu-1;  else  ndmode[iu].Value  = MIN_numode; 
ndmode[iu].ChangingValue = ndmode[iu].Value;
}


   



}




//MDataV enamode[16];
//MDataV numode[16];
//MDataV ndmode[16];





#endif //RACM


MBERE.Value = MIN_MTBERE;	//e-10
MBERE.ChangingValue = MTBERE.Value;



MAGC.Value = 0;
MAGC.ChangingValue = MAGC.Value;

MSweep.Value = 0;
MSweep.ChangingValue = MSweep.Value;

MEthSend.Value = 0l;
MEthSendU.Value = 0l;

MEthRcvD.Value = 0l;

MEthReceived.Value = 0l;
MEthTransmit.Value = 0l;

MEthReceivedCRC.Value = 0l;


 if((MEthctl.Value < MIN_METHCTL) || (MEthctl.Value > MAX_METHCTL))
{
 // UsedMenu.DrawMessage(" Ethctl     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthctl.Value = MIN_METHCTL;
 MEthctl.ChangingValue = MEthctl.Value;
}

 if((MIfLoop.Value < MIN_MIFLOOP) || (MIfLoop.Value > MAX_MIFLOOP))
{ 
 // UsedMenu.DrawMessage(" IfLoop    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MIfLoop.Value = MIN_MIFLOOP;
 MIfLoop.ChangingValue = MIfLoop.Value;
}


 if((MUnModul.Value < MIN_MUNMODUL) || (MUnModul.Value > MAX_MUNMODUL))
{
// UsedMenu.DrawMessage(" UnModul    Is Wrong     ",&theAnyStrings.cEmpty[0]); 
  Ring(1,1,5,2);
 MUnModul.Value = MIN_MUNMODUL;
 MUnModul.ChangingValue = MUnModul.Value;
}

  if(acm_status)
{
 if((MACMM.Value < MIN_MACMM) || (MACMM.Value > (MAX_MACMM - 1)))
{
// printfpd("\n\r acm : %d", MACMM.Value);

// ret = 0;
//  UsedMenu.DrawMessage(" ACM Mode    Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);
 MACMM.Value = 1;	   //acm on
MACMM.ChangingValue = MACMM.Value;
}
}
else if((MACMM.Value != MAX_MACMM))
{
 // printfpd("\n\r __acm : %d", MACMM.Value);

 //ret = 0;
 // UsedMenu.DrawMessage(" ACM Mode    Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);
MACMM.Value = MAX_MACMM;
MACMM.ChangingValue = MACMM.Value;


}

 
}

extern "C" unsigned char CheckWEBData()
{


 unsigned char ret = 1;
 // UsedMenu.DrawMessage("     Check Parameters    ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //dev1.md100se.ConfigFile = ConfigFile.Value;   //t

if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
 {

 UsedMenu.DrawMessage("SatSound Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);


 SatSound.Value = MIN_SATSOUND;
 SatSound.ChangingValue = MIN_SATSOUND;
 }


  if((LoadVariants.Value < MIN_LOADVARIANTS) || (LoadVariants.Value > MAX_LOADVARIANTS))
{
  ret = 0;

 UsedMenu.DrawMessage("LoadVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
   LoadVariants.Value = 0;
   LoadVariants.ChangingValue = 0;
}

  if((SaveVariants.Value < MIN_SAVEVARIANTS) || (SaveVariants.Value > MAX_SAVEVARIANTS))
{
 ret = 0;
 UsedMenu.DrawMessage("SaveVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
 
   SaveVariants.Value = MIN_SAVEVARIANTS;
   SaveVariants.ChangingValue = MIN_SAVEVARIANTS;
}


  if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{

 ret = 0;
 UsedMenu.DrawMessage("Ethernet Mode Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MEthMode.Value = MIN_METHMODE;
 MEthMode.ChangingValue = MEthMode.Value; 
}


  if((MRfOut.Value < MIN_MRFOUT) || (MRfOut.Value > MAX_MRFOUT))
{

 ret = 0;
 UsedMenu.DrawMessage("2:RfOut  On/Off Is Wrong",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MRfOut.Value = MIN_MRFOUT;
 MRfOut.ChangingValue = MRfOut.Value; 
}


 // printfpdv(" MOut: % 5.3f",MOutLev.Value);
 //  printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
// printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



  if((MOutLev.Value < (float64)MIN_MOUTLEV) || (MOutLev.Value > (float64)MAX_MOUTLEV))
{
 ret = 0;
 UsedMenu.DrawMessage(" OutLev  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev.Value = MIN_MOUTLEV;
 MOutLev.ChangingValue = MOutLev.Value; 
}
  /* 
  if((MOutLev1.Value < (float64)MIN_MOUTLEV1) || (MOutLev1.Value > (float64)MAX_MOUTLEV1))
{
 UsedMenu.DrawMessage(" OutLev1  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev1.Value = MIN_MOUTLEV1;
 MOutLev1.ChangingValue = MOutLev1.Value; 
}
   	
  if((MOutLev2.Value < (float64)MIN_MOUTLEV2) || (MOutLev2.Value > (float64)MAX_MOUTLEV2))
{
 UsedMenu.DrawMessage(" OutLev2  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev2.Value = MIN_MOUTLEV2;
 MOutLev2.ChangingValue = MOutLev2.Value; 
}

 */


  if((MOutLevO.Value < (float64)MIN_MOUTLEVO) || (MOutLevO.Value > (float64)MAX_MOUTLEVO))
{
 ret = 0;
 UsedMenu.DrawMessage("OutLevOffs    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevO.Value = 0;
 MOutLevO.ChangingValue = MOutLevO.Value; 
}


 if((MOutLevOS.Value < (float64)MIN_MOUTLEVOS) || (MOutLevOS.Value > (float64)MAX_MOUTLEVOS))
{
 ret = 0;
  UsedMenu.DrawMessage("  OutLevOSign  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevOS.Value = 0;
 MOutLevOS.ChangingValue = MOutLevOS.Value; 
}

 if((MKOUT.Value < (float64)MIN_MKOUT) || (MKOUT.Value > (float64)MAX_MKOUT))
{
 ret = 0;
  UsedMenu.DrawMessage("  MKOUT  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKOUT.Value = 0;
 MKOUT.ChangingValue = MKOUT.Value; 
}

 if((MKOUT1.Value < (float64)MIN_MKOUT1) || (MKOUT1.Value > (float64)MAX_MKOUT1))
{
  UsedMenu.DrawMessage("  MKOUT1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKOUT1.Value = (unsigned)MAX_MKOUT1;
 MKOUT1.ChangingValue = MKOUT1.Value; 
}

 if((MKIN1.Value < (float64)MIN_MKIN1) || (MKIN1.Value > (float64)MAX_MKIN1))
{
  UsedMenu.DrawMessage("  MKIN1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN1.Value = (unsigned)MAX_MKIN1;
 MKIN1.ChangingValue = MKIN1.Value; 
}

 if((MKIN1.Value < (float64)MIN_MKIN1) || (MKIN1.Value > (float64)MAX_MKIN1))
{
  UsedMenu.DrawMessage("  MKIN1  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN1.Value = (unsigned)MAX_MKIN1;
 MKIN1.ChangingValue = MKIN1.Value; 
}

 if((MKIN2.Value < (float64)MIN_MKIN2) || (MKIN2.Value > (float64)MAX_MKIN2))
{
  UsedMenu.DrawMessage("  MKIN2  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN2.Value = (unsigned)MAX_MKIN2;
 MKIN2.ChangingValue = MKIN2.Value; 
}

 if((MKIN3.Value < (float64)MIN_MKIN3) || (MKIN3.Value > (float64)MAX_MKIN3))
{
  UsedMenu.DrawMessage("  MKIN3  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKIN3.Value = (unsigned)MAX_MKIN3;
 MKIN3.ChangingValue = MKIN3.Value; 
}





  
if((MTDRate.Value < MIN_MTDRATE) || (MTDRate.Value > MAX_MTDRATE))
{
 ret = 0;
 UsedMenu.DrawMessage("2 TDRate  Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}


if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
 ret = 0;
 UsedMenu.DrawMessage("RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  printfpdv("\n\r2 wrong RDRate: % 5.3f",MRDRate.Value);	//is zero

  Ring(1,1,5,2);

// printfpdv("\n\r RDRate: % 5.3f",MRDRate.Value);	//is zero
 // printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
 //printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



 MRDRate.Value = MAX_MRDRATE;
 MRDRate.ChangingValue = MRDRate.Value; 
}
 

 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 

  if((MTFreq.Value < MIN_MTFREQ) || (MTFreq.Value > MAX_MTFREQ))
{
 ret = 0;
  UsedMenu.DrawMessage("2 TFreq    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 ret = 0;
 UsedMenu.DrawMessage(" RFreq     Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 ret = 0;
 UsedMenu.DrawMessage(" TModul    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTModul.Value = MIN_MTMODUL;
 MTModul.ChangingValue = MTModul.Value;
}
  /*
 if((MRateE.Value < MIN_MRATEE) || (MRateE.Value > MAX_MRATEE))
{
 UsedMenu.DrawMessage(" MRateE    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRateE.Value = MIN_MRATEE;
 MRateE.ChangingValue = MRateE.Value;
}
   */


 if((MRModul.Value < MIN_MRMODUL) || (MRModul.Value > MAX_MRMODUL))
{
 ret = 0;
 UsedMenu.DrawMessage(" RModul    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
 ret = 0;
	 UsedMenu.DrawMessage(" TCdType Is Wrong   ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
 ret = 0;
 	UsedMenu.DrawMessage(" RCdType Is Wrong      ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

		 MRCdType.Value = MIN_MRCDTYPE;
		 MRCdType.ChangingValue = MRCdType.Value;
  	}
	  
    if((MTMode.Value < MIN_MTMODE) || (MTMode.Value > MAX_MTMODE))
	{
 ret = 0;
    UsedMenu.DrawMessage(" TMode   Is Wrong        ",&theAnyStrings.cEmpty[0]);
 	 Ring(1,1,5,2);
	 	MTMode.Value = MIN_MTMODE;
 		MTMode.ChangingValue = MTMode.Value;
	}

    if((MRMode.Value < MIN_MRMODE) || (MRMode.Value > MAX_MRMODE))
	{
 ret = 0;
	 UsedMenu.DrawMessage(" RMode   Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
 	MRMode.Value = MIN_MRMODE;
 		MRMode.ChangingValue = MRMode.Value;
	}

    if((MRCntl.Value < MIN_MRCNTL) || (MRCntl.Value > MAX_MRCNTL))
	{
 ret = 0;
  //	  printfp("\n\r set default mrnctl");

    UsedMenu.DrawMessage(" RCntl    Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
	 	MRCntl.Value = MIN_MRCNTL;
 		MRCntl.ChangingValue = MRCntl.Value;
	}

  //	printfpd("\n\r mrnctl : %d", MRCntl.Value);


 //MRModul.Value = 0;
 //MRModul.ChangingValue = MRModul.Value;
    if((MTCode.Value < MIN_MTCODE) || (MTCode.Value > MAX_MTCODE))
	{
 ret = 0;
 	 UsedMenu.DrawMessage(" TCode     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
	MTCode.Value = MIN_MTCODE;
 		MTCode.ChangingValue = MTCode.Value;
   }




    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
 ret = 0;
  UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 ret = 0;
 UsedMenu.DrawMessage("2 Demod On/Off  Is Wrong",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}

 if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{	
 ret = 0;										 
  UsedMenu.DrawMessage(" EthMode   Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthMode.Value = 0;
 MEthMode.ChangingValue = MEthMode.Value;
 }

 if((MEthPause.Value < MIN_METHPAUSE) || (MEthPause.Value > MAX_METHPAUSE))
{
 ret = 0;
  UsedMenu.DrawMessage(" EthPause   Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthPause.Value = 0;
 MEthPause.ChangingValue = MEthPause.Value;
}

 MEthModeI.Value = 0;
 MEthModeI.ChangingValue = MEthModeI.Value;

 if((MEthMaxF.Value < MIN_METHMAXF) || (MEthMaxF.Value > MAX_METHMAXF))
{
 ret = 0;
  UsedMenu.DrawMessage(" EthMaxF    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 
 MEthMaxF.Value = MIN_METHMAXF;
 MEthMaxF.ChangingValue = MEthMaxF.Value;
}

 if((MEthVlanP.Value < MIN_METHVLANP) || (MEthVlanP.Value > MAX_METHVLANP))
{
 ret = 0;

  UsedMenu.DrawMessage(" EthVlanP    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MEthVlanP.Value = MIN_METHVLANP;
 MEthVlanP.ChangingValue = MEthVlanP.Value;
}


MEbN0.Value = 10.1;

 if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
 ret = 0;
 UsedMenu.DrawMessage(" TEbN0    Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTEbN0.Value = MIN_MTEBN0;
MTEbN0.ChangingValue = MTEbN0.Value;
}


MBER.Value = (float)0.0;
MBERE.Value = MIN_MTBERE;	//e-10
MBERE.ChangingValue = MTBERE.Value;


 if((MTBER.Value < MIN_MTBER) || (MTBER.Value > MAX_MTBER))
{
 ret = 0;
 UsedMenu.DrawMessage(" TBER      Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value < MIN_MTBERE) || (MTBERE.Value > MAX_MTBERE))
{
 ret = 0;
 UsedMenu.DrawMessage(" TBERE     Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBERE.Value = MIN_MTBERE;	//e-10
MTBERE.ChangingValue = MTBERE.Value;
}



 if((MEthctl.Value < MIN_METHCTL) || (MEthctl.Value > MAX_METHCTL))
{
 ret = 0;
  UsedMenu.DrawMessage(" Ethctl     Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthctl.Value = MIN_METHCTL;
 MEthctl.ChangingValue = MEthctl.Value;
}

 if((MIfLoop.Value < MIN_MIFLOOP) || (MIfLoop.Value > MAX_MIFLOOP))
{
 ret = 0;
  UsedMenu.DrawMessage(" IfLoop    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MIfLoop.Value = MIN_MIFLOOP;
 MIfLoop.ChangingValue = MIfLoop.Value;
}


 if((MUnModul.Value < MIN_MUNMODUL) || (MUnModul.Value > MAX_MUNMODUL))
{
 ret = 0;
 UsedMenu.DrawMessage(" UnModul    Is Wrong  ",&theAnyStrings.cEmpty[0]); 
  Ring(1,1,5,2);
 MUnModul.Value = MIN_MUNMODUL;
 MUnModul.ChangingValue = MUnModul.Value;
}

 if(acm_status)
{
 if((MACMM.Value < MIN_MACMM) || (MACMM.Value > (MAX_MACMM - 1)))
{
// printfpd("\n\r acm : %d", MACMM.Value);

 ret = 0;
  UsedMenu.DrawMessage(" ACM Mode    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
// MACMM.Value = MIN_MACMM;
 //MACMM.ChangingValue = MACMM.Value;
}
}
else if((MACMM.Value != MAX_MACMM))
{
 // printfpd("\n\r __acm : %d", MACMM.Value);

 ret = 0;
  UsedMenu.DrawMessage(" ACM Mode    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 //MACMM.Value = MAX_MACMM;
 //MACMM.ChangingValue = MACMM.Value;


}

#ifdef RACM

 if((RACMOnOff.Value < MIN_RACM) || (RACMOnOff.Value > MAX_RACM))
{
 UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOnOff.Value = MIN_RACM;	//e-10
RACMOnOff.ChangingValue = MIN_RACM;
}

if((RACMOnOffT.Value < MIN_RACM) || (RACMOnOffT.Value > MAX_RACM))
{
 //UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOnOffT.Value = MIN_RACM;	//e-10
RACMOnOffT.ChangingValue = MIN_RACM;
}

 if((RACMOffset.Value < MIN_RACMOffset) || (RACMOffset.Value > MAX_RACMOffset))
{
 //UsedMenu.DrawMessage(" RACMOnOff     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
RACMOffset.Value = 0;	//e-10
RACMOffset.ChangingValue = 0;
}


/*

 if((ratimelock.Value < MIN_ratimelock) || (ratimelock.Value > MAX_ratimelock))
{
 UsedMenu.DrawMessage(" ratimelock     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
ratimelock.Value = MIN_ratimelock;	//e-10
ratimelock.ChangingValue = MIN_ratimelock;
}


 if((ratimemode.Value < MIN_ratimemode) || (ratimemode.Value > MAX_ratimemode))
{
 UsedMenu.DrawMessage(" ratimemode     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
ratimemode.Value = MIN_ratimemode;	//e-10
ratimemode.ChangingValue = MIN_ratimemode;
}

 if((ratimemse.Value < MIN_ratimemse) || (ratimemse.Value > MAX_ratimemse))
{
 UsedMenu.DrawMessage(" ratimemse     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
ratimemse.Value = MIN_ratimemse;	//e-10
ratimemse.ChangingValue = MIN_ratimemse;
}

 if((ratimestep.Value < MIN_ratimestep) || (ratimestep.Value > MAX_ratimestep))
{
 UsedMenu.DrawMessage(" ratimestep     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
ratimestep.Value = MIN_ratimestep;	//e-10
ratimestep.ChangingValue = MIN_ratimestep;
}

for(unsigned iu = 0; iu < 16; iu++)
 {


 if((uebn[iu].Value < MIN_uebn) || (uebn[iu].Value > MAX_uebn))
{
 UsedMenu.DrawMessage(" umse   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
uebn[iu].Value = MAX_uebn_DEFAULT;	//e-10
uebn[iu].ChangingValue = uebn[iu].Value;
}

 if((debn[iu].Value < MIN_uebn) || (debn[iu].Value > MAX_uebn))
{
 UsedMenu.DrawMessage(" dmse   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
debn[iu].Value = MIN_uebn_DEFAULT;	//e-10
debn[iu].ChangingValue = debn[iu].Value;
}


 if((enamode[iu].Value < MIN_enamode) || (enamode[iu].Value > MAX_enamode))
{
 UsedMenu.DrawMessage(" enamode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
enamode[iu].Value = MAX_enamode;	//e-10
enamode[iu].ChangingValue = MAX_enamode;
}

 if((numode[iu].Value < MIN_numode) || (numode[iu].Value > MAX_numode))
{
 UsedMenu.DrawMessage(" numode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
numode[iu].Value = iu+1;  if(numode[iu].Value > MAX_numode)    numode[iu].Value = MAX_numode;
numode[iu].ChangingValue = numode[iu].Value;
}

 if((ndmode[iu].Value < MIN_numode) || (ndmode[iu].Value > MAX_numode))
{
 UsedMenu.DrawMessage(" ndmode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
if(iu) ndmode[iu].Value = iu-1;  else  ndmode[iu].Value  = MIN_numode; 
ndmode[iu].ChangingValue = ndmode[iu].Value;
}






}
	 */
//MDataV enamode[16];
//MDataV numode[16];
//MDataV ndmode[16];




#endif //RACM







 return ret;

}







//______________________________________________
extern "C" void CheckParametersTx()
{

 // UsedMenu.DrawMessage("     Check Parameters    ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //dev1.md100se.ConfigFile = ConfigFile.Value;   //t

//ok return; //150224


 if((MRateE.Value < MIN_MRATEE) || (MRateE.Value > MAX_MRATEE))
{
 UsedMenu.DrawMessage(" MRateE    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRateE.Value = MIN_MRATEE;
 MRateE.ChangingValue = MRateE.Value;
}
 //ok return; //150224


	/*
 if((MRateED.Value < MIN_MRATEE) || (MRateED.Value > MAX_MRATEE))
{
 UsedMenu.DrawMessage(" MRateED    Is Wrong     ",&theAnyStrings.cEmpty[0]);

   printfpdv("\n\r5  wrong MRateED: % 5.3f",MRateED.Value);	//is zero

  Ring(1,1,5,2);

 MRateED.Value = MIN_MRATEE;
 MRateED.ChangingValue = MRateED.Value;
}

	*/

  if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{

 UsedMenu.DrawMessage("Ethernet Mode Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MEthMode.Value = MIN_METHMODE;
 MEthMode.ChangingValue = MEthMode.Value; 
}


  if((MRfOut.Value < MIN_MRFOUT) || (MRfOut.Value > MAX_MRFOUT))
{

 UsedMenu.DrawMessage("3:RfOut  On/Off Is Wrong",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MRfOut.Value = MIN_MRFOUT;
 MRfOut.ChangingValue = MRfOut.Value; 
}


 // printfpdv(" MOut: % 5.3f",MOutLev.Value);
 //  printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
// printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



  if((MOutLev.Value < (float64)MIN_MOUTLEV) || (MOutLev.Value > (float64)MAX_MOUTLEV))
{
 UsedMenu.DrawMessage(" OutLev  Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev.Value = MIN_MOUTLEV;
 MOutLev.ChangingValue = MOutLev.Value; 
}
 /*

  if((MOutLev1.Value < (float64)MIN_MOUTLEV1) || (MOutLev1.Value > (float64)MAX_MOUTLEV1))
{
 UsedMenu.DrawMessage(" OutLev1  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev1.Value = MIN_MOUTLEV1;
 MOutLev1.ChangingValue = MOutLev1.Value; 
}

  if((MOutLev2.Value < (float64)MIN_MOUTLEV2) || (MOutLev2.Value > (float64)MAX_MOUTLEV2))
{
 UsedMenu.DrawMessage(" OutLev2  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLev2.Value = MIN_MOUTLEV2;
 MOutLev2.ChangingValue = MOutLev2.Value; 
}

  */


  if((MOutLevO.Value < (float64)MIN_MOUTLEVO) || (MOutLevO.Value > (float64)MAX_MOUTLEVO))
{
 UsedMenu.DrawMessage("OutLevOffs    Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevO.Value = 0;
 MOutLevO.ChangingValue = MOutLevO.Value; 
}


 if((MOutLevOS.Value < (float64)MIN_MOUTLEVOS) || (MOutLevOS.Value > (float64)MAX_MOUTLEVOS))
{
  UsedMenu.DrawMessage("OutLevOSign  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevOS.Value = 0;
 MOutLevOS.ChangingValue = MOutLevOS.Value; 
}

  
if((MTDRate.Value < MIN_MTDRATE) || (MTDRate.Value > MAX_MTDRATE))
{
 UsedMenu.DrawMessage("3TDRate  Is Wrong    ",&theAnyStrings.cEmpty[0]);

// printfpdv("\n\r4  wrong TDRate: % 5.3f",MTDRate.Value);	//is zero

  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}


 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 

  if((MTFreq.Value < MIN_MTFREQ) || (MTFreq.Value > MAX_MTFREQ))
{
  UsedMenu.DrawMessage("3 TFreq    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }

  

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 UsedMenu.DrawMessage(" TModul    Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTModul.Value = MIN_MTMODUL;
 MTModul.ChangingValue = MTModul.Value;
}

  


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
	 UsedMenu.DrawMessage(" TCdType Is Wrong  ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}

    if((MTMode.Value < MIN_MTMODE) || (MTMode.Value > MAX_MTMODE))
	{
    UsedMenu.DrawMessage(" TMode   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  //	printfp("\n\r  TMode   Is Wrong" );
 	 Ring(1,1,5,2);
	 	MTMode.Value = MIN_MTMODE;
 		MTMode.ChangingValue = MTMode.Value;
	}


  //	printfpd("\n\r mrnctl : %d", MRCntl.Value);





    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
  UsedMenu.DrawMessage(" RCode      Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }


   //return; //150224



  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 UsedMenu.DrawMessage("3 Demod On/Off Is Wrong",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}



 
}

extern "C" void CheckParametersRx()
{

 // UsedMenu.DrawMessage("     Check Parameters    ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //dev1.md100se.ConfigFile = ConfigFile.Value;   //t

if((MRateED.Value < MIN_MRATEE) || (MRateED.Value > MAX_MRATEE))
{
// UsedMenu.DrawMessage(" MRateED    Is Wrong     ",&theAnyStrings.cEmpty[0]);

  // printfpdv("\n\r5  wrong MRateED: % 5.3f",MRateED.Value);	//is zero

 // Ring(1,1,5,2);

 MRateED.Value = MIN_MRATEE;
 MRateED.ChangingValue = MRateED.Value;
}



if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
// UsedMenu.DrawMessage(" RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //printfpdv("\n\r3  wrong RDRate: % 5.3f",MRDRate.Value);	//is zero
 // printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
 //printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



 MRDRate.Value = MAX_MRDRATE;
 MRDRate.ChangingValue = MRDRate.Value; 
}
 

 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 //UsedMenu.DrawMessage(" RFreq     Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   


 if((MRModul.Value < MIN_MRMODUL) || (MRModul.Value > MAX_MRMODUL))
{
// UsedMenu.DrawMessage(" RModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
  //	UsedMenu.DrawMessage(" RCdType Is Wrong       ",&theAnyStrings.cEmpty[0]);
   //	Ring(1,1,5,2);

		 MRCdType.Value = MIN_MRCDTYPE;
		 MRCdType.ChangingValue = MRCdType.Value;
  	}

    if((MRMode.Value < MIN_MRMODE) || (MRMode.Value > MAX_MRMODE))
	{
   //	 UsedMenu.DrawMessage(" RMode   Is Wrong       ",&theAnyStrings.cEmpty[0]);
  //	Ring(1,1,5,2);
 	MRMode.Value = MIN_MRMODE;
 		MRMode.ChangingValue = MRMode.Value;
	}

 

 //MRModul.Value = 0;




    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
//  UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 //UsedMenu.DrawMessage(" Demod On/Off  Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}



  if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
// UsedMenu.DrawMessage(" TEbN0    Is Wrong       ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
MTEbN0.Value = MIN_MTEBN0;
MTEbN0.ChangingValue = MTEbN0.Value;
}


 if((MTBER.Value < MIN_MTBER) || (MTBER.Value > MAX_MTBER))
{
// UsedMenu.DrawMessage(" TBER      Is Wrong     ",&theAnyStrings.cEmpty[0]);
//  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value < MIN_MTBERE) || (MTBERE.Value > MAX_MTBERE))
{
// UsedMenu.DrawMessage(" TBERE     Is Wrong     ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);
MTBERE.Value = MIN_MTBERE;	//e-10
MTBERE.ChangingValue = MTBERE.Value;
}

 
}



//_____________________________________________





extern "C" void ResetPult(void)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);

   pio_ptr->SODR = MASK_BIT_20;
   delay_mcs(10);
   pio_ptr->CODR = MASK_BIT_20;
   delay_mcs(10);
   pio_ptr->SODR = MASK_BIT_20;

}





extern "C" void InvertBitOrdering(void)
{
  printfp(">>>>InvertBitOrdering");

// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
// char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];
 unsigned char ByteBuff;
 unsigned char ByteBuff1;

#ifndef	PROG_DMU6

  for(unsigned i = 0; i < XilSizeToDownloadD; i++)	 //need header only
#else
    for(unsigned i = 0; i <XilSizeToDownloadD_DMU6; i++)	 //need header only

#endif
 //  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
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

extern "C" char WriteDataIFModule(unsigned long addr_dest, unsigned char * pBuf, unsigned long size)
{

#ifdef WIFM
return;
#endif
 /*
 
 unsigned char tmp = inportb(CON_IFSAT140_ADDR);
 if(!(tmp & IFBLOK_MASK))
 {
  return;
 }

*/

 char ret = 0;
 outportb(ADR_IFSAT140,MEM);
 delay_mcs(50);
 outportb(ADR_IFSAT140,MEM);
//  outportb(ADR_IFSAT140,MEM);
// delay_mcs(50);

 ret = write_dataflashx (addr_dest,  (unsigned int)(pBuf),  size);
return ret;
}

extern "C" int ReadDataIFModule(unsigned long addr_dest,  char * pBuf, unsigned long size)
{

#ifdef WIFM
return;
#endif
   /*
unsigned char tmp = inportb(CON_IFSAT140_ADDR);
 if(!(tmp & IFBLOK_MASK))
 {
  return;
 }
 */

 outportb(ADR_IFSAT140,MEM);
  delay_mcs(50);
  outportb(ADR_IFSAT140,MEM);

//outportb(ADR_IFSAT140,MEM);
 // delay_mcs(50);
return  read_dataflashx (addr_dest, size, pBuf);
 // read_dataflashx (addr_dest, size, pBuf);
//  read_dataflashx (addr_dest, size, pBuf);


}



extern "C" void TestWriteIFModule()
{

char Buf[IFModuleDataSize];
char Buf1[50];

outportb(ADR_IFSAT140,MEM);
  delay_mcs(50);
  outportb(ADR_IFSAT140,MEM);



Buf[0] = 'O';
Buf[1] = 'K';
Buf[2] = '!';
Buf[3] = 0;
Buf[4] = 0;
Buf[5] = 0;
Buf[6] = 0;


 /*
for(unsigned j = 0; j < IFModuleDataSize; j++)
{
Buf[j] =j + 0x30;
}
 */

Buf1[0] = 'W';
Buf1[1] = 'R';
Buf1[2] = 'O';
Buf1[3] = 'N';
Buf1[4] = 'G';
Buf1[5] = '!';
Buf1[6] = 0;

AT91F_DataflashInitx();  //for test
delay_mcs(50);
 WriteDataIFModule(0 + CFG_DATAFLASH_LOGIC_ADDR_CS1X, Buf, 7);

// WriteDataIFModule((unsigned long)(IFCONF_ADDRESS), Buf,  (unsigned)IFModuleDataSize);

//return; //t1411107
delay_mcs(50);

// ReadDataIFModule((unsigned long)(IFCONF_ADDRESS),  (char *)&TFTP_Buffer1[0],  (unsigned)IFModuleDataSize);

ReadDataIFModule(0 + CFG_DATAFLASH_LOGIC_ADDR_CS1X, Buf1, 7);

printfp("\n\rBuf of ifmodule:");
printfp(Buf1);

//for(unsigned i = 0; i < IFModuleDataSize; i++)
/*
for(unsigned i = 0; i < 10; i++)
	{
	if(!(i%16))	  printfp("\n\r>");

  	printfpd(" %c", TFTP_Buffer1[i]);
	IFmoduleData.Value[i]  = TFTP_Buffer1[i]; 
	}
	 printfp("\n\r");

  */


}
  



extern "C" void InitIFModule()
{

unsigned char * pData;
static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//


 /*
unsigned char tmp = inportb(CON_IFSAT140_ADDR);
 if(!(tmp & IFBLOK_MASK))
 {
  return;
 }
 */

//___________________________________________________________________________reset 

     CON_IFSAT140 &= (~_IFNRST);   //inverse operation : reset on
	 outportb(CON_IFSAT140_ADDR,CON_IFSAT140);
	 delay_mcs(200);
     CON_IFSAT140 |= _IFNRST;   //inverse operation	 : reset off
	 outportb(CON_IFSAT140_ADDR,CON_IFSAT140);
     delay_mcs(200);

//____________________________________________________________________________filtrs
//0X30000036:0x0000000a; -- filtr TX
    outportb(ADR_IFSAT140,TXFILTR);

//0X30000037:0x00000078;
    outportb(ADRFWR, 0x78);
 	delay_mcs(5);
//wait 5mks


//0X30000036:0x0000000e; -- filtr RX
    outportb(ADR_IFSAT140,RXFILTR);

//0X30000037:0x0000007c;
	outportb(ADRFWR, 0x7C);
	delay_mcs(5);
//wait 5mks
//_______________________________________________________________________________dacs
//0X30000036:0x0000000c; -- DAC
	outportb(ADR_IFSAT140, TXPOWLEV);
//0X3000003A:0x00000045;
	outportb(DACL, 0x45);
//0X3000003B:0x00000006;
   outportb(DACH, 0x6);
   delay_mcs(5);
//________________________________________________________________________________tx dds

	
 outportb(ADR_IFSAT140,TXIFSYNT);	//tx

//00 00 99
pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x99;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);
   
//60 13 00 00 00 80;
pData = DataDDS;
*pData++ = 0x60;   *pData++ = 0x13;	 *pData++ = 0; *pData++ = 0; *pData++ = 0; *pData++ = 0x80;
WriteReadSpiBm(48 , 6,  DataDDS, DataDDS);


//00 20 17;
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x20;	 *pData++ = 0x17;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);


//00 21 00;
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x21;	 *pData++ = 0;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);


//00 22 04
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x22;	 *pData++ = 0x04;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//61 AB 23 d7 0a 3d 70 A3;
pData = DataDDS;
*pData++ = 0x61;   *pData++ = 0xab;	 *pData++ = 0x23;	 	*pData++ = 0xd7; 	*pData++ = 0x0a;
*pData++ = 0x3d;    *pData++ = 0x70;	 *pData++ = 0xa3;


WriteReadSpiBm(48 , 8,  DataDDS, DataDDS);


//64 10 00 00 10 00 01 FF 00 00

pData = DataDDS;
*pData++ = 0x64;   *pData++ = 0x10;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0x10;
*pData++ = 0;       *pData++ = 1;	 *pData++ = 0xff;	*pData++ = 0; 		*pData++ = 0;

WriteReadSpiBm(48 , 10,  DataDDS, DataDDS);




//64 08 00 00 00 00 00 00 00 00 00;

pData = DataDDS;
*pData++ = 0x64;   *pData++ = 0x08;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;       *pData++ = 0;	 *pData++ = 0;		*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;


WriteReadSpiBm(48 , 11,  DataDDS, DataDDS);

//04 0B 28;

pData = DataDDS;
*pData++ = 0x04;   *pData++ = 0x0B;	 *pData++ = 0x28;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//04 0C 00;

pData = DataDDS;
*pData++ = 0x04;   *pData++ = 0x0C;	 *pData++ = 0;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//65 09 00 00 00 00 00 00 00 00;

pData = DataDDS;
*pData++ = 0x65;   *pData++ = 0x09;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;       *pData++ = 0;	 *pData++ = 0;		*pData++ = 0; 		*pData++ = 0;

WriteReadSpiBm(48 , 10,  DataDDS, DataDDS);


//00 05 01;

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x05;	 *pData++ = 0x01;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//_________________________________________________________________________rx dds

outportb(ADR_IFSAT140,RXIFSYNT);	//tx

//00 00 99
pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x99;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//60 13 00 00 00 80;
pData = DataDDS;
*pData++ = 0x60;   *pData++ = 0x13;	 *pData++ = 0; *pData++ = 0; *pData++ = 0; *pData++ = 0x80;
WriteReadSpiBm(48 , 6,  DataDDS, DataDDS);


//00 20 17;
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x20;	 *pData++ = 0x17;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);


//00 21 00;
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x21;	 *pData++ = 0;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);


//00 22 04
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x22;	 *pData++ = 0x04;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//61 AB 23 d7 0a 3d 70 A3;
pData = DataDDS;
*pData++ = 0x61;   *pData++ = 0xab;	 *pData++ = 0x23;	 	*pData++ = 0xd7; 	*pData++ = 0x0a;
*pData++ = 0x3d;    *pData++ = 0x70;	 *pData++ = 0xa3;


WriteReadSpiBm(48 , 8,  DataDDS, DataDDS);


//64 10 00 00 10 00 01 FF 00 00

pData = DataDDS;
*pData++ = 0x64;   *pData++ = 0x10;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0x10;
*pData++ = 0;       *pData++ = 1;	 *pData++ = 0xff;	*pData++ = 0; 		*pData++ = 0;

WriteReadSpiBm(48 , 10,  DataDDS, DataDDS);




//64 08 00 00 00 00 00 00 00 00 00;

pData = DataDDS;
*pData++ = 0x64;   *pData++ = 0x08;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;       *pData++ = 0;	 *pData++ = 0;		*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;


WriteReadSpiBm(48 , 11,  DataDDS, DataDDS);

//04 0B 28;

pData = DataDDS;
*pData++ = 0x04;   *pData++ = 0x0B;	 *pData++ = 0x28;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//04 0C 00;

pData = DataDDS;
*pData++ = 0x04;   *pData++ = 0x0C;	 *pData++ = 0;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

//65 09 00 00 00 00 00 00 00 00;

pData = DataDDS;
*pData++ = 0x65;   *pData++ = 0x09;	 *pData++ = 0;	 	*pData++ = 0; 		*pData++ = 0;
*pData++ = 0;       *pData++ = 0;	 *pData++ = 0;		*pData++ = 0; 		*pData++ = 0;

WriteReadSpiBm(48 , 10,  DataDDS, DataDDS);


//00 05 01;

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x05;	 *pData++ = 0x01;
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);
  
//_________________________________________________________________________rxdds




}



extern "C" void SetMIfLoop()
{

 // delay_mcs(1000000l);

 if(MIfLoop.Value)
 {
//  delay_mcs(100000l);
	
 GetLoopi(0);
 //delay_mcs(100000l);

 //SetLoopi(0, PVG610_LOOPBACK_MODEM_E,0, 1,0);
 //delay_mcs(100000l);

SetLoopi(0, PVG610_LOOPBACK_MODEM_E,0, 1,0);
// delay_mcs(1000000l);
 GetLoopi(0);
 //GetLoopi(0);
 //GetLoopi(0);
 //GetLoopi(0);
 //GetLoopi(0);

//SetLoopi(0, PVG610_LOOPBACK_NONE_E,0, 1,0);
//delay_mcs(100000l);
 //GetLoopi(0);
// GetLoopi(0);
// GetLoopi(0);
// GetLoopi(0);
 //GetLoopi(0);
// delay_mcs(100000l);
//PVG610_API_ModemAcquireStart(0,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);
SetLoopi(0, PVG610_LOOPBACK_MODEM_E,0, 1,0);
 // delay_mcs(100000l);
 GetLoopi(0);
 //GetLoopi(0);
 ////GetLoopi(0);
 //GetLoopi(0);
 //GetLoopi(0);


 //ScanErrors();
//PVG610_API_ModemAcquireStart(0,0,  PVG610_ACQUIRE_MODE_AUTO_E, PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E);

// delay_mcs(100000l);
// SetLoopi(0, PVG610_LOOPBACK_NONE_E,0, 1,0);
 //delay_mcs(100000l);
 //GetLoopi(0);
 //delay_mcs(100000l);
 // GetLoopi(0);
 //delay_mcs(100000l);

 //SetLoopi(0, PVG610_LOOPBACK_MODEM_E,0, 1,0);



// delay_mcs(100000l);
// GetLoopi(0);
// delay_mcs(100000l);
// GetLoopi(0);



  dev1.md100se.MIfLoop = 1;
 }
 else
 {

 //   CON_IFSAT140 &= (~IFLOOPON);


  dev1.md100se.MIfLoop = 0;
	//  delay_mcs(10000l);

 //  GetLoopi(0);
  //	  delay_mcs(10000l);

 // SetLoopi(0, PVG610_LOOPBACK_NONE_E,0, 1,0);
  // delay_mcs(10000l);

 //  GetLoopi(0);
  //   GetLoopi(0);
	//   delay_mcs(10000l);

  // GetLoopi(0);
  //	  delay_mcs(10000l);

  SetLoopi(0, PVG610_LOOPBACK_NONE_E,0, 1,0);
  // delay_mcs(10000l);

  GetLoopi(0);
   //  GetLoopi(0);




 }

// outportb(CON_IFSAT140_ADDR,CON_IFSAT140);
}



extern "C" void  SetMUnModul()
{
 if(MUnModul.Value)
 {
// SetModuli(0, PVG610_TRANSMITTER_MODE_ONETONE_E, 0, 0);
 SetModuli(0, PVG610_TRANSMITTER_MODE_MUTE_E,0,0);
 dev1.md100se.MUnModul =1;
 }
 else
 {
 SetModuli(0, PVG610_TRANSMITTER_MODE_NORMAL_E, 0, 0);
 dev1.md100se.MUnModul =0;
 }
}


extern "C" void SetLoadVariants()
{

GetCurConfigFromFile(LoadVariants.Value); 

}


extern "C" void SetSaveVariants()
{

PutCurConfigToFile(SaveVariants.Value);
ReadRAnyConfigs();

}

extern "C" void SetMRfOut()
{

// if(MRfOut.Value)
//if(MRfOut.Value &&(!Ld0) && (!Ld1) && (dev_status &	MASK_BIT_0) && (dev_status &	MASK_BIT_1))
if(MRfOut.Value &&(!Ld0) && (!Ld1) )
 {
// printfp("\n\r Output Is On");

 CON_IFSAT140 |= IFTXON;

 dev1.md100se.MRfOut =1;
 }
 else
 {
// printfp("\n\r Output Is Off");

  CON_IFSAT140 &= (~IFTXON);
 dev1.md100se.MRfOut =0;
 }
  outportb(CON_IFSAT140_ADDR,CON_IFSAT140);

UsedExp.State.Reg2.bit.MACMM = 1;
if(MIfLoop.Value) {UsedExp.State.Reg2.bit.MIfLoop = 1; }	   //to get on if loop if if stored
if(MUnModul.Value) {UsedExp.State.Reg2.bit.MUnModul = 1; }	
UsedExp.State.Reg2.bit.Some = 1;

}

extern "C" void SetMRfOutOff()
{

 CON_IFSAT140 &= (~IFTXON);
 dev1.md100se.MRfOut =0;
 outportb(CON_IFSAT140_ADDR,CON_IFSAT140);
}



  /*

extern "C" void SetMOutLevRem()		  //not need
{

//printfp("\n\rSetMOutLev");

MOutLev.Value =  ((dev1.md100se.MOutLev1 << 8)	+ dev1.md100se.MOutLev0) *(-1) / 10;
MOutLev.ChangingValue = MOutLev.Value;
}
 */

//#define POWER_START	  (3400)
//#define POWER_K		  (6329)

extern "C" void SetMOutLev1()
{
  
 //MOutLev.Value = (float64)MOutLev1.Value +	(float64)MOutLev2.Value/(float64)10;
 //MOutLev.ChangingValue = MOutLev.Value;
 //SetMOutLev();
  SetMOutLev2();

}

extern "C" void SetMOutLev2()
{
// printfp("\n\rSetMOutLev2");

//printfpdv("\n\rbefore start __MOut1: % 5.3f",MOutLev1.Value);
//printfpdv(" MOut2: % 5.3f",MOutLev2.Value);
//printfpdv(" MOut: % 5.3f",MOutLev.Value);


// MOutLev.Value = (float64)MOutLev1.Value +	(float64)MOutLev2.Value/(float64)10;
//  MOutLev.ChangingValue = MOutLev.Value;

//printfpdv("\n\r start __MOut1: % 5.3f",MOutLev1.Value);
//printfpdv(" MOut2: % 5.3f",MOutLev2.Value);
//printfpdv(" MOut: % 5.3f",MOutLev.Value);


 SetMOutLev();
}

extern "C" void SetMKout()
{
 SetMOutLev();
}

extern "C" void SetMKout1()
{
 SetMOutLev();
}

extern "C" void SetMKin1()
{
// SetMOutLev();
//SetMKin1();
}

extern "C" void SetMKin2()
{
// SetMOutLev();
SetMKin1();
}

extern "C" void SetMKin3()
{
// SetMOutLev();
SetMKin1();
}



extern "C" void SetMRateE()
{

dev1.md100se.MRateE0 = (unsigned char)MRateE.Value;
dev1.md100se.MRateE1 = (unsigned char)MRateE.Value>>8;
dev1.md100se.MRateE2 = (unsigned char)MRateE.Value>>16;
dev1.md100se.MRateE3 = (unsigned char)MRateE.Value>>24;

}

extern "C" void SetMRateED()
{

dev1.md100se.MRateED0 = (unsigned char)MRateED.Value;
dev1.md100se.MRateED1 = (unsigned char)MRateED.Value>>8;
dev1.md100se.MRateED2 = (unsigned char)MRateED.Value>>16;
dev1.md100se.MRateED3 = (unsigned char)MRateED.Value>>24;

}




extern "C" void SetMOutLev()
{

//printfp("\n\rSetMOutLev");

//MOutLev.Value =  ((dev1.md100se.MOutLev1 << 8)	+ dev1.md100se.MOutLev0) *(-1) / 10;
//MOutLev.ChangingValue = MOutLev.Value;

//signed long tmp =  ((MOutLev.Value *  (-100)   +  MOutLevOS.Value * MOutLevO.Value *  (-100)   + POWER_START) * POWER_K) / 1000;

//signed long tmp =  ((443  + MOutLev.Value *  (-10) +   MOutLevOS.Value * MOutLevO.Value *  (-10)   ) * 676) / 100;
//signed long tmp =  ((443  + MOutLev.Value *  (-10) +   MOutLevOS.Value * MOutLevO.Value *  (-10)   ) * MKOUT.Value) / 100;
//signed long tmp =  (signed long)(((MOutLevO.Value - MOutLev.Value) * MKOUT.Value) / (float64)10);

signed long sign = 	MOutLevOS.Value ? -1 : 1;

//signed long tmp =
// (signed long)(((sign * MOutLevO.Value * MOutLev.Value * MOutLev.Value)/(float)10) 
//  -	(signed long)(MKOUT.Value * MOutLev.Value)	+ (signed long)(MKOUT1.Value * 10));

signed long tmp =
 (signed long)(((sign * MOutLevO.Value * MOutLev.Value * MOutLev.Value)/(float)10) 
  -	(signed long)(MKOUT.Value * MOutLev.Value)	+ (signed long)(MKOUT1.Value * 10));


//printfpd("\n\rMOutLev code : 0x%x ", tmp);



//printfpd("\n\rMOutLev code : 0x%x ", tmp);
//printfpd("\n\MOutLevO.Value *10 : %d ", MOutLevO.Value * 10);
//printfpd("\n\rMKOUT.Value : %d ", MKOUT.Value);

//_______________________________________________________________________________dacs
//0X30000036:0x0000000c; -- DAC
	outportb(ADR_IFSAT140, TXPOWLEV);
//0X3000003A:0x00000045;
	outportb(DACL, tmp);
//0X3000003B:0x00000006;
   outportb(DACH, tmp>>8);
   delay_mcs(5);
//________________________________________________________________________________tx dds

//printfpdv("\n\r before MOut1: % 5.3f",MOutLev1.Value);
//printfpdv(" MOut2: % 5.3f",MOutLev2.Value);
//printfpdv(" MOut: % 5.3f",MOutLev.Value);


   		   
MOutLev1.Value =   (unsigned)MOutLev.Value;
MOutLev1.ChangingValue = MOutLev1.Value;
   
MOutLev2.Value =   ((unsigned)(MOutLev.Value * 10) % 10);
MOutLev2.ChangingValue = MOutLev2.Value;
  
//printfpdv("\n\r after MOut1: % 5.3f",MOutLev1.Value);
//printfpdv(" MOut2: % 5.3f",MOutLev2.Value);
//printfpdv(" MOut: % 5.3f",MOutLev.Value);
		  

dev1.md100se.MOutLev0 = ((unsigned)MOutLev.Value * 10) & 0xff;
dev1.md100se.MOutLev1 = ((unsigned)(MOutLev.Value *10) >> 8) & 0xff;

//printfpd("\n\r ol0:%x", dev1.md100se.MOutLev0);
//printfpd("\n\r ol1:%x", dev1.md100se.MOutLev1);
	   

}
#define  MODUL_LEN	(6)
#define  TMODE_LEN	(23)
#define  CDTYPE_LEN (4)


extern "C" void FillMTModulV()
{

char *pMT = &theAnyStrings.cMTModeV[2];
char *pMd;
unsigned long i, j;
float mtcode;


for(i = 0; i < 16; i++)
{

  if(modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].mode <	MAX_MTMODUL)
  {
   //	printfpd("\n\r %d: ", i);
   //	printfp(pMT);


   pMd = &theAnyStrings.cMTModulV[modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].mode * MODUL_LEN];
   for(j = 0; j < MODUL_LEN; j++)
   {
	 *pMT++ = *pMd++;
   }
	*pMT++ = ' ';
   pMd = &theAnyStrings.cMTCdTypeV[modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].code_type * CDTYPE_LEN];
  
    for(j = 0; j < CDTYPE_LEN; j++)
   {
	 *pMT++ = *pMd++;
   }

   *pMT++ = ' ';


  mtcode =   (float64)((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].coderate0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].coderate1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].coderate2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[i].coderate3 << 24) ) / (float64)1000; 	

  	sprintf(pMT, "%.3f", mtcode);
 //	 printfpdv("\n\r %.3f ", mtcode);

   pMT += TMODE_LEN - MODUL_LEN - CDTYPE_LEN - 2;



  }
  else
  {
   pMT += TMODE_LEN;
  }


}



}
//set  params of modulator
extern "C" void SetParamsFromCfg()
{


 unsigned char quantity; 


  

// printfp("\n\r Setparamsfromcfg");
//  MTCode.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate0 +
//				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate1 << 8)) / 1000; 	
   
 quantity =  (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.numMode;

// printfpd("\n\r quantity = %d", quantity);
  
 if((quantity < MIN_QUANTITY) || (quantity > MAX_QUANTITY))
 {
  quantity =  (unsigned char)MAX_QUANTITY;
 }

if(MTMode.Value >  quantity)
{
 MTMode.Value = 0;
 MTMode.ChangingValue = MTMode.Value;
}
 MTMode.Quantity = quantity;

//ok  return; //150224
	
	
  FillMTModulV();

//ok  return; //150224

  MTDRate.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / 1000000; 	

 		 
  MTDRate.ChangingValue = MTDRate.Value;
   
 MAlfaM.Value = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.alfa /1000.0;
 MAlfaM.ChangingValue = MAlfaM.Value;

  // printfpdv("\n\rMAlfaM 1: % 5.3f",MAlfaD.Value);	//
  

//float ttt = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.alfa/1000.0;


//ok   return; //150224


//  SetMTDRate();




 //printfpdv("\n\rbefore from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero

 

//  SetMRDRate();

 //   printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0);
  //  printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1);
  //  printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2);
  //  printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3);
  //  printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero

   acm_status = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.acm_status;
  //  acm_status = 1; //for test

//wrong return; //150224

//ok	 return; //150224

 
 SetParamsTxFromCfg(MTMode.Value);

 //ok return; //150224


//  SetMRCdType();
		 
   CheckParameters();

     ratesymbol_far = MTDRate.Value;
  power_rate = 	MTDRate.Value;

   SetMRfOutOff();
 //  SetMTCode();
  // SetMRCode();
  // SetMTModul();
 //  SetMRModul();
   SetMTDRate();


//141128   SetMRDRate();
 //  SetMTCdType();
  // SetMRCdType();
 //  SetMACMM();	 //in final
  // SetMRfOut();   //last	//need close before changing  	   in final

//ok return; //150224


SetMEthPause1();
SetMEthctl1();
SetMEthMaxF();
SetMEthVlanP1();

InitEthStat();


}

//set params for demodulator
//extern "C" void SetParamsFromCfg1(unsigned char variant1)
extern "C" void SetParamsFromCfg1(unsigned long variant1)
{


 unsigned char quantity; 

// unsigned long blockSize; 


// unsigned long quantity; 

 printfp("\n\r Setparamsfromcfg");

//  MTCode.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate0 +
//				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate1 << 8)) / 1000; 	
   
 quantity =  (unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.numMode;

// printfpd("\n\r quantity = %d", quantity);

 // blockSize = (((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[16].blockSize0	) << 8);

//  DFE.Value[0] = 'O';
//  DFE.Value[1] = 'n';
//  DFE.Value[2] = '\0';
 // DFE.Value[3] = '\0';

//printfp("\n\r DFE : ");


//printfp(DFE.Value);


  
 if((quantity < MIN_QUANTITY) || (quantity > MAX_QUANTITY))
 {
  quantity =  (unsigned char)MAX_QUANTITY;
 }

    MRDRate.Value =  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / 1000000; 	


 
 MAlfaD.Value = modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.alfa /1000.0;
 MAlfaD.ChangingValue = MAlfaD.Value;
 	
  //  printfpdv("\n\rMAlfaD 1: % 5.3f",MAlfaD.Value);	//
	
 	
 		 
  MRDRate.ChangingValue = MRDRate.Value;
//  SetMTDRate();




 //printfpdv("\n\rbefore from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero


 // MRDRate.Value = MTDRate.Value; 
 // MRDRate.ChangingValue = MRDRate.Value;
//  SetMRDRate();

 //   printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0);
  //  printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1);
  //  printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2);
  //  printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3);
  //  printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero

   acm_status1 = modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.acm_status;
  //  acm_status = 1; //for test


 SetParamsRxFromCfg(MRMode.Value);
// SetParamsTxFromCfg(MTMode.Value);

//printfp("\n\r tp1 ");


//  SetMRCdType();
		 
   CheckParameters();
 //printfp("\n\r tp2 ");

  //   ratesymbol_far = MTDRate.Value;
  //   power_rate = 	MTDRate.Value;

 //  SetMRfOutOff();
 //  SetMTCode();
  // SetMRCode();
  // SetMTModul();
 //  SetMRModul();
 //  SetMTDRate();
   SetMRDRate();
 // printfp("\n\r tp3 ");

 //  SetMTCdType();
  // SetMRCdType();
 //  SetMACMM();	 //in final
  // SetMRfOut();   //last	//need close before changing  	   in final


}



extern "C" void SetParamsTxFromCfg(unsigned char p)
{
 // return;

 //printfpd("\n\r SetparamsTxfromcfg %d", p);

 
//  printfp("\n\r SetparamsTxfromcfg");

// printfpd("\n\r coderate0 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0);
 //printfpd("  coderate1 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1);


//  MTCode.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0 +
 //				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1 << 8)) / 1000; 	
 // MTCode.ChangingValue = MTCode.Value; 
//printfpd("  MTCode = %d", MTCode.Value);


 // SetMTCode();

// printfpd("\n\r mode = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].mode);
unsigned long rateEth = 
 ((unsigned long)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth0)+
 ((unsigned long)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth1 <<8)+
 ((unsigned long)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth2 <<16)+
 ((unsigned long)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth3 <<24);

 MRateE.Value =	rateEth / 1000;
 MRateE.ChangingValue = MRateE.Value;
 
  power_modul = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].mode;  
	  
 MAlfaM.Value = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.alfa /1000.0;
 MAlfaM.ChangingValue = MAlfaM.Value;

// printfpdv("\n\rMAlfaM 2: % 5.3f",MAlfaD.Value);	//

   
  MTModul.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].mode;
  MTModul.ChangingValue = MTModul.Value;
//  printfpd("tx  modul = %d", MTModul.Value);

 // SetMTModul();

  MTDRate.Value =  (float64)((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / (float64)1000000; 	
 
 
  MTDRate.ChangingValue = MTDRate.Value;
//  SetMTDRate();
  //  printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0);
  //  printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1);
  //  printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2);
  //  printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3);

 // printfpd("  MTDRate = %d", MTDRate.Value);

	  
  MTCdType.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].code_type;
  MTCdType.ChangingValue = MTCdType.Value;
 // SetMTCdType();
 //   printfpd("\n\r code_type: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].code_type);

//   printfpd(" MTCdType = %d", MTCdType.Value);

  MTCode.Value =   (float64)((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate3 << 24) ) / (float64)1000; 	


 //  printfpd("\n\coderate0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0);
 //  printfpd("  coderate1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1);
 //  printfpd("  coderate2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate2);
 //  printfpd("  coderate3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate3);
  
 //   printfpdv("\n\r MTCode.Value: %6.3f", MTCode.Value);



  MTCode.ChangingValue = MTCode.Value;

// printfpd("\n\r extTypeRate0 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].extTypeRate0);
// printfpd(" extTypeRate1 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].extTypeRate1);
// printfpd(" extTypeRate2 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].extTypeRate2);
// printfpd(" extTypeRate3 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].extTypeRate3);




// printfpd("\n\r blockSize0 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].blockSize0);
// printfpd(" blockSize1 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].blockSize1);


//  SetMTCode();
// printfpd("\n\r coderate0 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0);
// printfpd("  coderate1 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1);
// printfpd("  coderate2 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate2);
// printfpd("  coderate3 = 0x%x", (unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate3);


 //  printfpd("\n\r MTCode = %d", MTCode.Value);



  //ok  return; //150224


   CheckParametersTx();

 //ok   return; //150224


   SetMTCode();
   SetMTDRate();
   SetMTModul();
   SetMTCdType();
   SetMTCode();
   SetMRateE();

 //	return; //150224


 //   SetMRfOut();

// if(!hot_restart)
//  {
//  SetGEth(0, (unsigned)MRateE.Value);
//  }

  

}
  
extern "C" void SetTxMode(unsigned char p)
{
  MTModeI.Value = p;
}

extern "C" char* GetDFE()
{
 return DFE.Value;
// return "on ";
}

 
extern "C" void SetParamsRxFromCfg(unsigned char p)
{
// return;
//printfp("\n\r SetparamsRxfromcfg");

unsigned long variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;

//in symmetrical mode config file are identiacl! - do not need use variant



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//unsigned char variant1 =  GetNumConfigFile(1) & CONFIG_FILE_MASK;

  

	 

   dev1.md100se.MRMode =  p;
  // printfpd("rx  MRMode = %d", p);


  unsigned long blockSize = (((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].blockSize0	) << 8) +
							(unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].blockSize0	 ;

  if(blockSize)
  {
  DFE.Value[0] = 'O';
  DFE.Value[1] = 'n';
  DFE.Value[2] = '\0';
  DFE.Value[3] = '\0';
  }
  else
  {
  DFE.Value[0] = 'O';
  DFE.Value[1] = 'f';
  DFE.Value[2] = 'f';
  DFE.Value[3] = '\0';

  }

//printfp("\n\r DFE : ");
//printfp(DFE.Value);

unsigned long rateEth = 
 ((unsigned long)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth0)+
 ((unsigned long)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth1 <<8)+
 ((unsigned long)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth2 <<16)+
 ((unsigned long)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].rateEth3 <<24);

 MRateED.Value =	rateEth / 1000;
 MRateED.ChangingValue = MRateED.Value;


 
  MRCode.Value =   (float64)((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0 +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1 << 8) +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].coderate2 << 16)	+
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].coderate3 << 24) ) / (float64)1000; 	
  MRCode.ChangingValue = MRCode.Value;
 // SetMRCode();
 //  printfpdv("MRCode: %f",MRCode.Value );
  //  printfpd("\n\rMRCode*1000: %d",(unsigned long)(MRCode.Value * 1000) );




  MRModul.Value =  modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].mode;
  MRModul.ChangingValue = MRModul.Value;

 //printfpd("rx  MRModul = %d", MRModul.Value);

 // SetMRModul();

 //  printfpd("\n\r variant1: %d", variant1 );


 // printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol0);
  //printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol1);
 // printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol2);
 // printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol3);
  //  printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero



  MRDRate.Value =  (float64)((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / (float64)1000000; 	
   
   
  // 	 printfpdv("\n\r from cfg : RDRate: % 5.3f",MRDRate.Value);	//


  MRDRate.ChangingValue = MRDRate.Value;
//  SetMRDRate();
	   
 MAlfaD.Value = modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.alfa /1000.0;
 MAlfaD.ChangingValue = MAlfaD.Value;
	
   // printfpdv("\n\rMAlfaD 2: % 5.3f",MAlfaD.Value);	//

	  

  MRCdType.Value =  modemp[0].configfilefext1[variant1].ConfigTxtData.emb4md15504cfg.mode15504[p].code_type;
  MRCdType.ChangingValue = MRCdType.Value;
 // SetMRCdType();
//  SetMTDRate();

    CheckParametersRx();

//printfp("\n\r SetparamsRxfromcfg 1");
	SetMRCode();

//printfp("\n\r SetparamsRxfromcfg 2");
   SetMRModul();

//printfp("\n\r SetparamsRxfromcfg 3");
    SetMRDRate();

//printfp("\n\r SetparamsRxfromcfg 4");
	 SetMRCdType();
//printfp("\n\r SetparamsRxfromcfg 5");
	  SetMRateED();

//printfp("\n\r SetparamsRxfromcfg 6");

	 
  
}





//>>>>>>>>>>>>>>>>>>>>>>>>
extern "C" void SetMTCode()
{

 //MTCode.Value = 0;// modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.coderate0;
// unsigned char coderate1;


dev1.md100se.MTCode0 = (unsigned)(MTCode.Value * 1000);
dev1.md100se.MTCode1 =  (unsigned)(MTCode.Value * 1000) >> 8;
 
   
}

extern "C" void SetMTModul()
{
  dev1.md100se.MTModul =  MTModul.Value;
}

extern "C" void SetMTCdType()
{
  dev1.md100se.MTCdType =  MTCdType.Value;
}

extern "C" void SetMRCdType()
{
  dev1.md100se.MRCdType =  MRCdType.Value;
}
	
extern "C" void SetMTMode()	  //called from pult
{
 //printfpd("\n\r SetMTMode() %d", MTMode.Value);

 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
 //SetACMMask(0,  (1 << MTMode.Value));
 //  MTModeI.Value = MTMode.Value;

  dev1.md100se.MTMode =  MTMode.Value;
	  
  SetParamsTxFromCfg(MTMode.Value);
  // SetParamsRxFromCfg(MTMode.Value);   //for check
	

//141121 MRMode.Value =  MTMode.Value;
 //141121MRMode.ChangingValue = MRMode.Value;
 //dev1.md100se.MRMode =  MRMode.Value;
  //SetParamsRxFromCfg(MRMode.Value);
 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
  SetMACMM();	 //to send commands

 //  SetMRfOut();

}


extern "C" void SetMTModeA()   //called from SetMACMM()	when acm - off
{
 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
 //SetACMMask(0,  (1 << MTMode.Value));
 //   printfp("\n\r SetMTModeA()");

  dev1.md100se.MTMode =  MTMode.Value;
	  
  SetParamsTxFromCfg(MTMode.Value);
  // SetParamsRxFromCfg(MTMode.Value);   //for check
	

//141121 MRMode.Value =  MTMode.Value;
//141121 MRMode.ChangingValue = MRMode.Value;
 //dev1.md100se.MRMode =  MRMode.Value;
  //SetParamsRxFromCfg(MRMode.Value);
 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));

}


extern "C" void SetMRMode()
{
 //	 printfp("\n\r SetMRMode()");
// PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MRMode.Value));

  dev1.md100se.MRMode =  MRMode.Value;
   SetParamsRxFromCfg(MRMode.Value);


// MTMode.Value =  MTMode.Value;
// MTMode.ChangingValue = MTMode.Value;
// dev1.md100se.MTMode =  MTMode.Value;
 // SetParamsTxFromCfg(MTMode.Value);



}

extern "C" void SetMRCntl()
{

// PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MRMode.Value));

  if(MRCntl.Value)	//remote only
  {
   	MRfOut.Changable 	= 0;		//on / off
	MOutLev.Changable 	= 0;
	MOutLev1.Changable 	= 0;
	MOutLev2.Changable 	= 0;

	MTFreq.Changable 	= 0;
	MRFreq.Changable 	= 0;
	if(!acm_status)
	{
	MTMode.Changable = 0;
  //	MRMode.Changable = 0;
	}
	else
	{
	  if(!MACMM.Value)
 		  {
	 		MTMode.Changable = 0;
  		  }
	}

	MDemod.Changable 	= 0;
	MEthMode.Changable 	= 0;
	MEthPause.Changable = 0;
	MEthctl.Changable 	= 0;
	MEthMaxF.Changable 	= 0;
	MEthVlanP.Changable = 0;
	MIfLoop.Changable 	= 0;
	MUnModul.Changable 	= 0;
	 if(acm_status)
	MACMM.Changable 	= 0;
  }
  else
  {
   	MRfOut.Changable    = 1;		//on / off
	MOutLev.Changable   = 1;
	MOutLev1.Changable 	= 1;
	MTFreq.Changable    = 1;
	MRFreq.Changable    = 1;
if(!acm_status)
	{
	MTMode.Changable    = 1;
 //	MRMode.Changable    = 0;	 //olwais
	}
else
	{
	  if(!MACMM.Value)
 		  {
	 		MTMode.Changable = 1;
  		  }
	}


	MDemod.Changable    = 1;
	MEthMode.Changable  = 1;
	MEthPause.Changable = 1;
	MEthctl.Changable   = 1;
	MEthMaxF.Changable  = 1;
	MEthVlanP.Changable = 1;
	MIfLoop.Changable   = 1;
	MUnModul.Changable  = 1;
	 if(acm_status)
	MACMM.Changable     = 1;
  }



  dev1.md100se.MRCntl =  MRCntl.Value;


// MTMode.Value =  MTMode.Value;
// MTMode.ChangingValue = MTMode.Value;
// dev1.md100se.MTMode =  MTMode.Value;
 // SetParamsTxFromCfg(MTMode.Value);



}


 
extern "C" void   SetViewModesFromCfg(unsigned char txAcmProfile ,unsigned char rxAcmProfile)
{
  //  printfp("\n\rSetViewModesFromCfg");
 //  MTModeI.Value =  txAcmProfile;
#ifdef RACM
  if(previons_mode != rxAcmProfile)
  {
 //  timechangemode = time1;
	previons_mode = rxAcmProfile;
  }
#endif

  if(UsedMenu.MenuState.DataP0Changing == 0)
  {
  //	MTMode.Value =  txAcmProfile;
  //	MTMode.ChangingValue = MTMode.Value;
  //	dev1.md100se.MTMode =  MTMode.Value;

    MRMode.Value =  rxAcmProfile;
    MRMode.ChangingValue = MRMode.Value;
    dev1.md100se.MRMode =  MRMode.Value;
  }
}


 extern "C" void LoadFiltrT(unsigned long F)
{
 unsigned char tmp;

 // unsigned char koef = (((F * 10l) + 5l)* 6 )/100l ;
//  koef <<= 3;

 unsigned char koef = (((F * 6l) + 9l))/10l ;

//printfpd("\n\r f : %d", F);
//printfpd("  filtr :%d", koef);
//printfpd("  filtr hex :%x", koef);


  koef <<= 3;

//printfpd("  filtr hex <<3 :%x", koef);


  outportb(ADRFWR,koef);

  tmp =   inportb(ADRFWR);
//  printfpd("  37 addr :%x", tmp);




  delay_mcs(5);

   outportb(ADRFWR+1,0xff);

 delay_mcs(20);

    tmp =   inportb(ADRFWR+1);
 //  printfpd("  38 addr :%x", tmp);

    delay_mcs(5);


}

extern "C" void LoadFiltrR(unsigned long F)
{
  unsigned char koef = (((F * 10l) + 5l)* 6)/100l;
  koef <<= 3;

	koef |= 4;

//printfpd("\n\r filtr : 0x%x", koef);

  outportb(ADRFWR,koef);
  delay_mcs(5);
}



extern "C" void SetMTDRate()
{

  outportb(ADR_IFSAT140,TXFILTR);

  LoadFiltrT((unsigned long)MTDRate.Value);


dev1.md100se.MTDRate0 = (unsigned)(MTDRate.Value * 10000);
dev1.md100se.MTDRate1 = (unsigned)(MTDRate.Value * 10000) >> 8;
dev1.md100se.MTDRate2 = (unsigned)(MTDRate.Value * 10000) >> 16;
dev1.md100se.MTDRate3 = (unsigned)(MTDRate.Value * 10000) >> 24;
}

extern "C" void SetMRCode()
{

dev1.md100se.MRCode0 = (unsigned)(MRCode.Value * 1000);
dev1.md100se.MRCode1 =  (unsigned)(MRCode.Value * 1000) >> 8;

}

extern "C" void SetMRModul()
{
  dev1.md100se.MRModul =  MRModul.Value;
}

extern "C" void SetMRDRate()
{

 outportb(ADR_IFSAT140,RXFILTR);

  LoadFiltrR((unsigned long)MRDRate.Value);



dev1.md100se.MRDRate0 = (unsigned)(MRDRate.Value * 10000);
dev1.md100se.MRDRate1 = (unsigned)(MRDRate.Value * 10000) >> 8;
dev1.md100se.MRDRate2 = (unsigned)(MRDRate.Value * 10000) >> 16;
dev1.md100se.MRDRate3 = (unsigned)(MRDRate.Value * 10000) >> 24;


}

typedef	unsigned long long __int64;


unsigned char * FormulaMD100SE(unsigned long f)	 //f in 100 hz
{
	static unsigned char c[16];
////////////// DDS /////////////////
//141024	double Fbase_dds = 700000000.0;
	double Fbase_dds = 10000000.0;	 //1ghz / 100


	double df;
	double Fdds;



////////////////////////////////////
//141024	Fdds = f<<1;
	Fdds = f<<1; //141024
	df = Fdds/Fbase_dds;
	__int64 u64base =  (__int64)(2814749l);
	u64base *= (__int64)(100000000l);
	u64base += (__int64) (76710656l);
	__int64 u64result = u64base*df;
	unsigned long low = u64result&0xFFFFFFFF;
	unsigned long high = (u64result>>32)&0xFFFFFFFF;
	c[0] = (high>>8)&0xFF;
	c[1] = high&0xFF;
	c[2] = (low>>24)&0xFF;
	c[3] = (low>>16)&0xFF;
	c[4] = (low>>8)&0xFF;
	c[5] = low&0xFF;

 return c;
}

//extern "C" unsigned char WriteReadSpiBm(unsigned char deviceindex, unsigned long length_of_data,
 //unsigned char * BufferData, unsigned char * ReadBuffer);




extern "C" void LoadDDs(unsigned long freq)
{

//printfpd("\n\r f2 = %d", freq);

unsigned char * pData;
static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//





unsigned char * b = FormulaMD100SE(freq);

DataDDS[0] = 0x61;
DataDDS[1] = 0xAB;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[2] = *b++;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[3] = *b++;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[4] = *b++;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[5] = *b++;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[6] = *b++;
//printfpd("\n\r b> 0x%x", *b);
DataDDS[7] = *b;

//t 141024 SendToDDS(SENDED_DDS_FREQ_LEN,  (unsigned long)&DataDDS[0]);
WriteReadSpiBm(48 , 8,  DataDDS, DataDDS);

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
//t 141024 SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x20;	 *pData =0;
//t 141024 SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x20;	 *pData =0x17;	  // vco 1 GHz
//t 141024 SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
WriteReadSpiBm(48 , 3,  DataDDS, DataDDS);



}



extern "C" unsigned short GetTempSat()
{
unsigned short ret = 0;

 unsigned long temp;
   outportb(ADR_IFSAT140,TEMPER);
  WriteReadSpiBm(48 , 2,  (unsigned char *)&ret,  (unsigned char *)&ret);

//printfpd("\n\r ret = 0x%X", ret);

// return (ret >> 5);
 return (ret & 0xff);
}



extern "C" void SetMTFreq()
{

//MRFreq.Value =  ((dev1.md100se.MRFreq3 << 24)	+ (dev1.md100se.MRFreq2 << 16) 
//					+ (dev1.md100se.MRFreq1 << 8) +  dev1.md100se.MRFreq0) / 10000l;

//printfpdv("\n\rF: %6.3f",MTFreq.Value);
//printfpdv(" CV :  %6.3f",MTFreq.ChangingValue);

unsigned long tmp =  MTFreq.Value *  10000l;

 outportb(ADR_IFSAT140,TXIFSYNT);

 LoadDDs(tmp);

dev1.md100se.MTFreq0 =  tmp & 0xff;
dev1.md100se.MTFreq1 = (tmp >> 8) & 0xff;
dev1.md100se.MTFreq2 = (tmp >> 16) & 0xff;
dev1.md100se.MTFreq3 = (tmp >> 24) & 0xff;

}


extern "C" void SetMRFreq()
{

unsigned long tmp =  MRFreq.Value *  10000l;

 outportb(ADR_IFSAT140,RXIFSYNT);

 LoadDDs(tmp);

dev1.md100se.MRFreq0 =  tmp & 0xff;
dev1.md100se.MRFreq1 = (tmp >> 8) & 0xff;
dev1.md100se.MRFreq2 = (tmp >> 16) & 0xff;
dev1.md100se.MRFreq3 = (tmp >> 24) & 0xff;


}



extern "C" void SetMDemod()
{

if(MDemod.Value)
 {
 dev1.md100se.MDemod =1;
 }
 else
 {
 dev1.md100se.MDemod =0;
 }
}

extern "C" void SetMEthModeI(unsigned char state)
{
 MEthModeI.Value = state;
  MEthModeI.ChangingValue = MEthModeI.Value;

}


extern "C" void SetMEthMode()
{
// printfp("\n\rSetMEthMode");

#ifdef PRINT_ETH
 printfp("\n\rSetMEthMode()");
 
 printfpd(" %X",  (unsigned char)MEthMode.Value);

#endif

dev1.md100se.MEthMode = (unsigned char)MEthMode.Value;

/*
auton = mode_eth & ETH_AUTO;
if(mode_eth & ETH_10) {speed = 0; interf = 0;}
if(mode_eth & ETH_100) {speed = 1; interf = 0;}
if(mode_eth & ETH_1000) {speed = 2; interf = 1;}
//duplex = mode_eth &  ETH_DUPL;
if(mode_eth & ETH_DUPL) {duplex = 1;}
*/

//strcpy(cMEthModeV,"Auto10h 10f 100h100f1000");
 unsigned long mod = 0l;

 switch((unsigned char)MEthMode.Value)
 {
 case 0 :  mod |= ETH_AUTO;	 				 break;
 case 1 :  mod |= ETH_10;	 				 break;
 case 2 :  mod |= ETH_10;	mod |= ETH_DUPL; break;
 case 3 :  mod |= ETH_100;	 				 break;
 case 4 :  mod |= ETH_100;	mod |= ETH_DUPL; break;
 case 5 :  mod |= ETH_1000;	mod |= ETH_DUPL; break;
 default : mod |= ETH_AUTO;   
 }

 #ifdef PRINT_ETH
  printfp("\n\rSetMEthMode()");
printfpd(" ethmode : %d", (unsigned char)MEthMode.Value);

 printfpd("  mod : 0x%x", mod);
#endif


 SetModEth(mod);
 StartEth(1);
}

extern "C" void SetMEthPause()
{
#ifdef PRINT_ETH
 printfp("\n\r SetMEthPause()");
 
 printfpd(" %X",  (unsigned char)MEthPause.Value);

#endif

  // PVG610_API_EthernetPauseSet(0,0,	(unsigned char)MEthPause.Value);
   dev1.md100se.MEthPause = (unsigned char)MEthPause.Value;
}

extern "C" void SetMEthPause1()
{

#ifdef PRINT_ETH
 printfp("\n\r SetMEthPause1()");
 
 printfpd(" %X",  (unsigned char)MEthPause.Value);

#endif



   PVG610_API_EthernetPauseSet(0,0,	(unsigned char)MEthPause.Value);
   PVG610_API_EthernetPauseSet(1,0,	(unsigned char)MEthPause.Value);


   dev1.md100se.MEthPause = (unsigned char)MEthPause.Value;
}


extern "C" void SetMEthctl()
{
#ifdef PRINT_ETH
 printfp("\n\r SetMEthctl()");
 
 printfpd(" %X",  (unsigned char)MEthctl.Value);

#endif

 //PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthctl.Value);

//PVG610_API_EthernetInBandControlSet(0,0, (unsigned char)MEthctl.Value);
  dev1.md100se.MEthctl = (unsigned char)MEthctl.Value;
}

extern "C" void SetMEthctl1()
{
 //PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthctl.Value);
#ifdef PRINT_ETH
 printfp("\n\r SetMEthctl1()");
 
 printfpd(" %X",  (unsigned char)MEthctl.Value);

#endif


PVG610_API_EthernetInBandControlSet(0,0, (unsigned char)MEthctl.Value);
PVG610_API_EthernetInBandControlSet(1,0, (unsigned char)MEthctl.Value);

  dev1.md100se.MEthctl = (unsigned char)MEthctl.Value;
}

extern "C" unsigned short GetMEthMaxF()
{
   return (unsigned short)MEthMaxF.Value;
}

extern "C" void SetMEthMaxF()
{
//printfp("\n\r SetMEthMax ");
#ifdef PRINT_ETH
 printfp("\n\r SetMEthMaxF()");
 
 printfpd(" %X",  (unsigned char)MEthMaxF.Value);

#endif


unsigned long tmp =  MEthMaxF.Value;
//printfpd("mf : %d", (UINT16)MEthMaxF.Value);

PVG610_API_EthernetLargeFrameSet (0,0,(UINT16)MEthMaxF.Value);
PVG610_API_EthernetLargeFrameSet (1,0,(UINT16)MEthMaxF.Value);



dev1.md100se.MEthMaxF0 =  tmp & 0xff;
dev1.md100se.MEthMaxF1 = (tmp >> 8) & 0xff;
//dev1.md100se.MEthMaxF2 = (tmp >> 16) & 0xff;
//dev1.md100se.MEthMaxF3 = (tmp >> 24) & 0xff;
}

extern "C" void SetMEthVlanP()
{
// PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthVlanP.Value);
 dev1.md100se.MEthVlanP = (unsigned char)MEthVlanP.Value;

} 

extern "C" void SetMEthVlanP1()
{
#ifdef PRINT_ETH
 printfp("\n\r SetMEthVlanP1()");
 
 printfpd(" %X",  (unsigned char)MEthVlanP.Value);

#endif


 PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthVlanP.Value);
 PVG610_API_EthernetVlanSet(1,0, (unsigned char)MEthVlanP.Value);

 dev1.md100se.MEthVlanP = (unsigned char)MEthVlanP.Value;

} 

//#include "iostream"
//#include <cstdio>
//#include <cmath>
 
//using std::printf;
 
//#define PRECISION 1e-4
#define PRECISION 1e-5
 
//exp(x) = 1 - x + (x^2)/2!-(x^3)/3!....+(-1)^n*(x^n)/n!+.....
 
double my_exp( const double x )
{
    double dVal, dTemp;
    int nStep = 1;
    for( dVal = 1.0, dTemp = 1.0; fabs(dTemp) >= PRECISION ; ++nStep )
    {
        dTemp *= -x/nStep;
        dVal += dTemp;
    }
    return dVal;
}
 
extern "C" void check_exp()
{
   double d_xstart = 0.0, d_xend = 10.0, dX = 0.1;
 //  printf( "%12s\t%12s\n", "x", "exp^(-x)" );
   for( double x = d_xstart; x<=d_xend;x+=dX ){
  //   printf( "%12.5f\t%12.5f\n", x, my_exp(x) );
     printfpdv( "%12.5f",x );
	    printfpdv( " %12.5f\r\n",  my_exp(x) );
   }
 
  // std::system("pause >> null");
}


extern "C" float64 my_log(double x)
{

//natur log :

      double sum = 0;
  //      double x = 8; // ???? ???????? ????????
 
        if ( x >= 0 && x <= 2)
        {
                x -= 1;
 
            //    for ( int i = 1; i < 5000; i += 2 )
			    for ( int i = 1; i < 200; i += 2 )
                {
                        sum += (double)(pow(x,i)/(double)i - (double)pow(x,(i+1))/(double)(i+1));
                }
 
           //     ShowMessage(sum);
	   //	   printfpdv("( s1 : %8.4f)", sum);
        }
        else if ( x > 2 )
        {
                x = (x /(float64) (x - 1));
 
             //   for ( int i = 1; i < 1000; i ++ )
			    for ( int i = 1; i < 200; i ++ )
                {
                        sum += (double)1.0 /(double) ( i*pow(x,i) );
                }
 
               // ShowMessage(sum);
		   //	     printfpdv("( s2 : %8.4f)", sum);

        }
        else
        {
               // ShowMessage("??????? ???????????? ????????");
	 //	  	 printfpd("(my_log :Argument is wrong ):%f", x);
        }

   return sum / (float64)2.302585 ;

}



float my_pow(const float x, const float y)
{
    if(y == 0.0) return 1.0;
    if(y==1.0) return x;
    if(x <= 0.0) return 0.0;

 //	printfpdv("\n\r my_log(x) :%8.4f", my_log(x));
  // printfpdv("\n\r my_log(x)*y:%8.4f", my_log(x)*y);
 //   printfpdv("\n\r my_exp:%8.4f",my_exp(my_log(x) * y));
  //	printfpdv("\n\rargs_my_pow :%8.4f", 2.303 * my_log(x) * y);
//	printfpdv(" x :%8.4f", x);
  //	printfpdv(" y :%8.4f", y);



  //	  x *= -1.0;

    return my_exp(2.303 * my_log(x) * y);	 //lnx = 2.303 * logx
 //   return  my_log(x);	//test //lnx = 2.303 * logx
}




extern "C" void SetMTEbN0()
{
//MTEbN0.Value =  ((dev1.md100se.MTEbN01 << 8)	+ dev1.md100se.MTEbN00) / 10l;

unsigned long tmp =  MTEbN0.Value * 10l;

dev1.md100se.MTEbN00 = tmp & 0xff;
dev1.md100se.MTEbN01 = (tmp >> 8) & 0xff;

}

extern "C" void SetMTBER()
{
//MTBER.Value =  ((dev1.md100se.MTBER1 << 8)	+ dev1.md100se.MTBER0) / 10l;

unsigned long tmp =  MTBER.Value * 10l;

dev1.md100se.MTBER0 = tmp & 0xff;
dev1.md100se.MTBER1 = (tmp >> 8) & 0xff;



} 


extern "C" void SetMSweep(signed long sweep)
{
//MTBER.Value =  ((dev1.md100se.MTBER1 << 8)	+ dev1.md100se.MTBER0) / 10l;

//unsigned long tmp =  MTBER.Value * 10l;

//dev1.md100se.MTBER0 = tmp & 0xff;
//dev1.md100se.MTBER1 = (tmp >> 8) & 0xff;


//printfpd("\n\r sweep : %d", sweep);
  	 
MSweep.Value = (float64)sweep / (float64)1000;
MSweep.ChangingValue = MSweep.Value;

//printfpdv(" msweep : %4.1f", MSweep.Value);


dev1.md100se.MSweep0 = sweep 		 & 0xff;
dev1.md100se.MSweep1 = (sweep >> 8)  & 0xff;
dev1.md100se.MSweep2 = (sweep >> 16) & 0xff;
dev1.md100se.MSweep3 = (sweep >> 24) & 0xff;
}

extern "C" double GetMAGC(void);


extern "C" void SetMAGC(signed short agc)
{

float agc1 = agc;

//printfpd("\n\ragc : %d", agc1);

//printfpd("\n\ragc1 : %d", 0.4167 * agc1 * agc1 * agc1);
//printfpd("\n\ragc2 : %d", 5.5357 * agc1 * agc1);


//MAGC.Value = (float64)agc;

//MAGC.Value = (0.000006 * agc1 * agc1) - ( 0.0428 * agc1) + 29.068;
//141208 MAGC.Value = (-0.00001 * agc1 * agc1) - ( 0.0107 * agc1) + 6.1718;

//MAGC.Value = (-0.00001 * agc1 * agc1) - ( 0.0107 * agc1) + 6.1718;

MAGC.Value =
 (float64)(( MKIN1.Value * agc1 * agc1) / (float64)10000000) 
//  -	(float64)(MKIN2.Value * agc1 / (float64)1000) + (float64)(MKIN3.Value / (float64)100);
  -	(float64)(MKIN2.Value * agc1 / (float64)10000) + (float64)(MKIN3.Value / (float64)1000);



dev1.md100se.MAGC0 = (unsigned)MAGC.Value 		 & 0xff;
dev1.md100se.MAGC1 = ((unsigned)MAGC.Value >> 8)  & 0xff;


if(MAGC.Value < -45)
{
//printfp("\n\r set MAGIC_VAL1");
MAGC.Value =  (unsigned long)MAGIC_VAL1;

/*
 printfpdv("\n\rset agc %f",GetMAGC() );
  printfpdv("\n\rset real agc_f %f",(float64)MAGC.Value );
   printfpdv("\n\rset real agc_x %x",(unsigned long)MAGC.Value );


        printfpd("\n\r set agc %x",(unsigned long)GetMAGC() );
		  printfpd("\n\r set agc %d",(unsigned long)GetMAGC() );
		    printfpd("\n\r MAGIC_VAL1_x %x",(unsigned long)MAGIC_VAL1 );
			   printfpd("\n\r MAGIC_VAL1_d %d",(unsigned long)MAGIC_VAL1 );

		 */

}

//printfpd("\n\MAGC.Value : %d", (signed short)MAGC.Value);

MAGC.ChangingValue = MAGC.Value;

// printfpdv("\n\r%15.8f",(float64 )MAGC.ChangingValue );


//dev1.md100se.MAGC0 = agc 		 & 0xff;
//dev1.md100se.MAGC1 = (agc >> 8)  & 0xff;
}


extern "C" void checklog(void)
{
  /*
printfpdv("\n\r log 0.01 %8.4f", log(0.01));
printfpdv("\n\r  log 0.1 %8.4f", log(0.1));
printfpdv("\n\r  log 0.2 %8.4f", log(0.2));
printfpdv("\n\r  log 0.5 %8.4f", log(0.5));
printfpdv("\n\r log 1 %8.4f", log(1));
printfpdv("\n\r  log 10 %8.4f", log(10));
printfpdv("\n\r  log 100 %8.4f", log(100));
   */
   /*
printfpdv("\n\r mlog 0.0001 %8.4f", my_log(0.0001));
printfpdv("\n\r mlog 0.001 %8.4f", my_log(0.001));
printfpdv("\n\r mlog 0.01 %8.4f", my_log(0.01));
printfpdv("\n\r  mlog 0.1 %8.4f", my_log(0.1));
printfpdv("\n\r  mlog 0.2 %8.4f", my_log(0.2));
printfpdv("\n\r  mlog 0.5 %8.4f", my_log(0.5));
printfpdv("\n\r mlog 1 %8.4f", my_log(1));
printfpdv("\n\r  mlog 10 %8.4f", my_log(10));
printfpdv("\n\r  mlog 100 %8.4f", my_log(100));
printfpdv("\n\r  mlog 1000 %8.4f", my_log(1000));
printfpdv("\n\r  mlog 10000 %8.4f", my_log(10000));
printfpdv("\n\r  mlog 100000 %8.4f", my_log(100000));
printfpdv("\n\r  mlog 1000000 %8.4f\n\r", my_log(1000000));

  */

}
 /*

extern "C" double my_pow(double x, double y)
{

  double qz;
  long qi;
//  begin
  double Result=1;
   qi=long(y);
   qz=x;
   
  // repeat
  do
  {
    // if qi mod 2=1 then Result:=Result*qz;
	if(qi%2)
	{  Result*= qz;	
   		printfpdv(" r %8.4f ", Result);
	  }
     qz+=qz;
     qi=qi>>1;
  }
   while(qi);
  // until qi=0;
   

  do
  {
//   repeat
     x=sqrt(x);

     y=(long)(y)*2;

     if (y>=1) Result *=x;
	 printfpdv("\n\r _r %8.4f ", Result);

  //
  }
   while(x != (double)1);

  // until x=1
   
   return Result;

}
	 */
//#include "powf.c"
   
extern "C" void SetMEbN_old(signed short ebn)
{
//printfp("\r 
ebn *= -1;

double j;
//double t1,t2,t3,t4,t5,t6;

//float t1,t2,t3,t4,t5,t6;
            
//printfpd("\r\nSetMEbN ebn: %d \n\r", ebn);	 //-450

//float64  tmp = 10 * ( log((10^(ebn/10))  - 1) -  log(MRCode.Value)) ; //temp
//float64  tmp = 10 * ( my_log((10^(ebn/10))  - 1) -  my_log(MRCode.Value)) ; //temp
//150209 float64  tmp = 10 * ( my_log(pow(10,((float64)ebn/100.0))  - 1) -  my_log(MRCode.Value)) ; //temp

//float64  tmp1 = 10 * ( (float64)ebn/100.0 -  my_log(MRCode.Value)) ; //temp

//float64  tmp = 10 * ((float64)log((double)pow(10,(ebn/100))  - 1) -  (float64)log((double)MRCode.Value)) ; //temp

float64  tmp = 10 * ((float64)my_log((double)my_pow(10,(ebn/(-100.0)))  - 1) -  (float64)my_log((double)MRCode.Value)) ; //temp

	/*
printfpdv("\n\r log01 %8.4f", (float64)log((double)0.1));
printfpdv("\n\r log1 %8.4f", log(1));
printfpdv("\n\r log10 %8.4f", log(10));
printfpdv("\n\r log100 %8.4f", log(100));
printfpdv("\n\r log1000 %8.4f", log(1000));
printfpdv("\n\r log10000 %8.4f", log(10000));
	 */
//printfpdv("\n\r log01 %8.4f", (float64)log((double)0.1));
//printfpd("\n\r log %d", (unsigned)log(10));
//printfpd("\n\r log10 %d", (unsigned)log10(10));
//printfpd("\n\r logf %d", (unsigned)logf(10));
  /*
printfpdv("\n\r log01 %8.4f", my_log(0.1));
printfpdv("\n\r log10 %8.4f", my_log(10));
printfpdv("\n\r log100 %8.4f", my_log(100));
printfpdv("\n\r log1000 %8.4f", my_log(1000));
printfpdv("\n\r log10000 %8.4f", my_log(10000));
 */

  
   /*
t1 =  (double)ebn/(double)-100.0;

printfpdv("\n\r ebn/100 :%8.4f", t1);	 //2,78



t2 = my_pow(10,t1);	
//t2 = my_pow(10,(double)2.99);	
//t2=exp(2.78);

printfpdv("\n\r pow ebn :%8.4f \n\r", t2);



t2 = my_pow(10,(double)-2.76);	

printfpdv("\n\r pow fix :%8.4f \n\r", t2);
*/
//t2=exp(2.78);
	/*
printfpdv("\n\r pow :%8.4f", t2);

t2 = my_pow(10,(double)0.99);	
//t2=exp(2.78);

printfpdv("\n\r pow :%8.4f", t2);


 */


/*
 printfpdv(" r1 %8.4f ", t2);

//printfpd("\n\r pow :%d", (unsigned)t2);

  
t2 = my_pow(10,3);	   //ok

printfpdv("\n\r pow1 :%8.4f", t2);
printfpd("\n\r pow1 :%d", (unsigned)t2);

//okt2 = pow((double)10.0,(double)3.0);	   //ok
t2 = my_pow((double)10.0,(double)31);	//
printfpdv("\n\r pow2 :%f", t2);
//printfpd("\n\r pow2 :%d", (unsigned)t2);


  */

/* 
t3 =  my_log(t2);
	
printfpdv("\n\r my_log(1pow:%8.4f", t3);	

//printfpdv("\n\r MRCode.Value:%8.4f", MRCode.Value);	  //0,7

t4 =  my_log(MRCode.Value);

printfpdv(" my_log(MRCode.Value):%8.4f", t4);	  //0,7

//printfpdv(" log2:%8.4f", (float)my_log((float)MRCode.Value));

t5 = 10 * (t3 - t4);

printfpdv(" t5:%8.4f", t5);

*/	
//printfpdv("\n\r tmp:%8.4f ", tmp);
//printfpdv("  tmp1:%8.4f ", tmp1);
 /*

 switch((unsigned)MRModul.Value)
{
 case 0 :  MEbN0.Value = (float64)(tmp - 3.0); break;  //QPSK
 case 1 :  MEbN0.Value = (float64)(tmp - 4.8); break;  //QPSK
 case 2 :  MEbN0.Value = (float64)(tmp - 4.8); break;  //QPSK
 case 3 :  MEbN0.Value = (float64)(tmp - 6.0); break;  //QPSK
 case 4 :  MEbN0.Value = (float64)(tmp - 6.0); break;  //QPSK
 case 5 :  MEbN0.Value = (float64)(tmp - 7.0); break;  //QPSK
 case 6 :  MEbN0.Value = (float64)(tmp - 7.8); break;  //QPSK
 default :  MEbN0.Value = (float64)(tmp - 3.0); break;  //QPSK
}

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
//		 Ring(1,1,5,4);
	//		printfp("\n\r ring! \n\r");
		 }
 		}

 */



  // ebn *= -1;

 switch((unsigned)MRModul.Value)
{
 case 0 :  MEbN0.Value = (float64)(tmp - 3.0)/(float64)1.0; break;  //QPSK
 case 1 :  MEbN0.Value = (float64)(tmp - 4.8)/(float64)1.0; break;  //QPSK
 case 2 :  MEbN0.Value = (float64)(tmp - 4.8)/(float64)1.0; break;  //QPSK
 case 3 :  MEbN0.Value = (float64)(tmp - 6.0)/(float64)1.0; break;  //QPSK
 case 4 :  MEbN0.Value = (float64)(tmp - 6.0)/(float64)1.0; break;  //QPSK
 case 5 :  MEbN0.Value = (float64)(tmp - 7.0)/(float64)1.0; break;  //QPSK
 case 6 :  MEbN0.Value = (float64)(tmp - 7.8)/(float64)1.0; break;  //QPSK
 default : MEbN0.Value = (float64)(tmp - 3.0)/(float64)1.0; break;  //QPSK
}
  
//MEbN0.ChangingValue = MEbN0.Value; 

 //  printfpdv("\n\r old MEbN0: %8.4f", MEbN0.Value);

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
		 Ring(1,1,5,4);
	//		printfp("\n\r ring! \n\r");
		 }
 		}



dev1.md100se.MEbN00 = (unsigned)(MEbN0.Value *10) 		 & 0xff;
dev1.md100se.MEbN01 = ((unsigned)(MEbN0.Value *10) >> 8)  & 0xff;
}

extern "C" void SetMEbN_2(signed short ebn)
{

//SetMEbN_old( ebn);

//printfp("\r 
ebn *= -1;

double j;
//double t1,t2,t3,t4,t5,t6;

//float t1,t2,t3,t4,t5,t6;
            
//printfpd("\n\rSetMEbN ebn: %d ", ebn);	 //-450
  if(ebn > 210)
{
   MEbN0.Value = (float64)21.0;
}
 else
{

float64  tmp = (float64)((ebn/10.0 * 1.14)  - 2.9);// -  (float64)my_log((double)MRCode.Value)) ; //temp


//printfpdv("\n\r ebn/10.0 * 1.14)  - 2.9 :%8.4f ", tmp);	 //2,78

//printfpdv("\n\r MRateED :%8.4f ", MRateED.Value ) ;
//printfpdv(" MRDRate:%8.4f ", MRDRate.Value ) ;

//printfpdv(" no log :%8.4f ", ((MRateED.Value + 20)/(MRDRate.Value *1000)));	 //2,78


//printfpdv(" \n\r my_log:%8.4f \n\r", 10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000)));	 //2,78


	
 switch((unsigned)MRModul.Value)
{
  
 case 0 :  MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000))); break;  //QPSK
 case 1 :  
 case 2 :  MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000))); break;  //8PSK  //QPSK
 case 3 :  
 case 4 :  MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000))); break;  //16PSK  //QPSK
 case 5 :  MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000))); break;  //32PSK  //QPSK  //QPSK
 case 6 :  MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000))); break;  //64PSK  //QPSK
   
 default : MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/ (MRDRate.Value * 1000))); break;  //QPSK  

}
  	
//MEbN0.ChangingValue = MEbN0.Value; 

//   printfpdv("new MEbN0: %8.4f", MEbN0.Value);



}  //< 210

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
		 Ring(1,1,5,4);
	//		printfp("\n\r ring! \n\r");
		 }
 		}



dev1.md100se.MEbN00 = (unsigned)(MEbN0.Value *10) 		 & 0xff;
dev1.md100se.MEbN01 = ((unsigned)(MEbN0.Value *10) >> 8)  & 0xff;
}

extern float64   MEbN0_snmp;

extern "C" void SetMEbN(signed short ebn)
{

//SetMEbN_old( ebn);

//printfp("\r 
#ifdef RACM
gmse = ebn / (-10.0);

//#ifdef RACM
MSEI.Value = gmse;
MSEI.ChangingValue = MSEI.Value;

#endif

//  MSEI.Value = 35.5;
// printfpdv("\n\rMSEI %f",MSEI.Value );


ebn *= -1;

double j;
//double t1,t2,t3,t4,t5,t6;

//float t1,t2,t3,t4,t5,t6;
            
//printfpd("\n\rSetMEbN ebn: %d ", ebn);	 //-450

float64  tmp;

float64 d, s, p;


 switch((unsigned)MRModul.Value)
{
  
 case 0 : // MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000)));
 		 if(ebn < 110)
		{
   			d = 1.34;	 s= -5.37;
		}
 		else
		{
		  d = 1.04;	 s= -2.02;
		}
  
  break;  //QPSK
 case 1 :  
 case 2 : 
 // MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000)));
  		 if(ebn < 140)
		{
   			d = 1.51;	 s= -8.16;
		}
 		else
		{
		  d = 0.59;	 s= 5.27;
		}

   break;  //8PSK  //QPSK
 case 3 :  
 case 4 :
    //16PSK  //QPSK
 case 5 : 
    //32PSK  //QPSK  //QPSK
 case 6 :
    if(ebn < 140)
		{
   			d = 1.68;	 s= -10.86;
		}
 		else
		{
		  d = 0.76;	 s= 2.41;
		}
   break;  //64PSK  //QPSK
   
 default : 
 
 //MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/ (MRDRate.Value * 1000)));
	  if(ebn < 110)
		{
   			d = 1.34;	 s= -5.37;
		}
 		else
		{
		  d = 1.04;	 s= -2.02;
		}



  break;  //QPSK  

}

	 tmp = (float64)((ebn/10.0 * d) + s);

 MEbN0.Value = (float64)(tmp -  10 *  my_log((MRateED.Value + 20)/(MRDRate.Value *1000)));
 MEbN0_snmp = MEbN0.Value;
 if(!LOCK)
 {
  MEbN0.Value = (unsigned)MAGIC_VAL;
  MEbN0_snmp = 0;
 }
 

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
		 Ring(1,1,5,4);
	//		printfp("\n\r ring! \n\r");
		 }
 		}



dev1.md100se.MEbN00 = (unsigned)(MEbN0.Value *10) 		 & 0xff;
dev1.md100se.MEbN01 = ((unsigned)(MEbN0.Value *10) >> 8)  & 0xff;
}





//extern float64   MEbN0_snmp;


extern "C" double GetMEbN0(void)
{
 // return (double)MEbN0.Value;
  return (double)MEbN0_snmp;
}


extern float64 blocks, uncblocks;
extern float64 blocks6, uncblocks6;
extern float64 blocks7, uncblocks7;
extern float64 blocks8, uncblocks8;
extern float64 blocks9, uncblocks9;
extern float64 blocks10, uncblocks10;
extern float64 blocks11, uncblocks11;




#define ERR_RESET (6)
//#define FRAME_SIZE (100)
#define FRAME_SIZE (40)
#define FRAME_TO_BYTES (250)

extern "C" void SetMBER(unsigned long alldata, unsigned long data)
{


#ifdef START_PRINT
/*
printfp("\n\r SetMBER");
printfpd("\n\r blocks: %d ", blocks); printfpd(" uncblocks : %d ", uncblocks);  
printfpd("\n\r blocks6: %d ", blocks6); printfpd(" uncblocks6 : %d ", uncblocks6);  
printfpd("\n\r blocks7: %d ", blocks7); printfpd(" uncblocks7 : %d ", uncblocks7);  
printfpd("\n\r blocks8: %d ", blocks8); printfpd(" uncblocks8 : %d ", uncblocks8);  
printfpd("\n\r blocks9: %d ", blocks9); printfpd(" uncblocks9 : %d ", uncblocks9);  
printfpd("\n\r blocks10: %d ", blocks10); printfpd(" uncblocks10 : %d ", uncblocks10);  
printfpd("\n\r blocks11: %d ", blocks11); printfpd(" uncblocks11 : %d ", uncblocks11);  



printfpd(" all: %d ", alldata);
printfpd(" err : %d ", data);
 	 */
#endif


unsigned uber;
static unsigned char oldlock;
static unsigned char conterr;
float64 uncblocksm, blocksm;



  //data = 0xffffl; //for test 

 
 //errf += err;
// dataf += data;

 float64 tber = 0.0;

 alldata *= FRAME_SIZE;


alldata *= (unsigned long)FRAME_TO_BYTES;
data *= (unsigned long)FRAME_TO_BYTES; //to view as byte rat not frame rate 





//if(!modemp[0].acquireStatus)   //not in lock
//if(!LOCK)
if(!LOCK) 
{
 //  data	= 0xFFFFFFFFl; //all errors
 #ifndef FEC_BER
   data	= 0x7FFFFFFFl; //all errors
#else
  // data	= 1;
#endif
    uncblocks = (float64)1l;   blocks =  (float64)2l;	   //1/2 errors
    uncblocks6 = (float64)1l;   blocks6 =  (float64)2l;	   //1/2 errors
    uncblocks7 = (float64)1l;   blocks7 =  (float64)2l;	   //1/2 errors
    uncblocks8 = (float64)1l;   blocks8 =  (float64)2l;	   //1/2 errors
    uncblocks9 = (float64)1l;   blocks9 =  (float64)2l;	   //1/2 errors
    uncblocks10 = (float64)1l;   blocks10 =  (float64)2l;	   //1/2 errors
    uncblocks11 = (float64)1l;   blocks11 =  (float64)2l;	   //1/2 errors





	 conterr = 0;	//continual errors
   //	 oldlock = 0;
  //	 return;
}



	/*

if((conterr	> ERR_RESET) && (data))	  //restart measuing from non - zero errors
{
 //  data	= 0xFFFFFFFFl; //all errors
    uncblocks = (float64)data; blocks =  (float64)alldata;
    uncblocks6 = (float64)data; blocks6 =  (float64)alldata;
    uncblocks7 = (float64)data; blocks7 =  (float64)alldata;
    uncblocks8 = (float64)data; blocks8 =  (float64)alldata;
    uncblocks9 = (float64)data; blocks9 =  (float64)alldata;
    uncblocks10 = (float64)data; blocks10 =  (float64)alldata;
    uncblocks11 = (float64)data; blocks11 =  (float64)alldata;


	 conterr = 0;	//continual errors
   //	 oldlock = 0;
	 return;
}

  */
  if((blocks /  (float64)10000000) >  (float64)10000000)	  //not more at 10^14 use
 {
  blocks /=  (float64)10;  uncblocks /=  (float64)10;
 }
 
 if((blocks6 /  (float64)1) >  (float64)1000000)	  //not more at 10^6 use
 {
  blocks6 /=  (float64)10;  uncblocks6 /=  (float64)10;
 }

 if((blocks7 /  (float64)10) >  (float64)1000000)	  //not more at 10^7 use
 {
  blocks7 /=  (float64)10;  uncblocks7 /=  (float64)10;
 }

 if((blocks8 /  (float64)100) >  (float64)1000000)	  //not more at 10^8 use
 {
  blocks8 /=  (float64)10;  uncblocks8 /=  (float64)10;
 }

 if((blocks9 /  (float64)1000) >  (float64)1000000)	  //not more at 10^9 use
 {
  blocks9 /=  (float64)10;  uncblocks9 /=  (float64)10;
 }

 if((blocks10 /  (float64)10000) >  (float64)1000000)	  //not more at 10^10 use
 {
  blocks10 /=  (float64)10;  uncblocks10 /=  (float64)10;
 }

 if((blocks11 /  (float64)100000) >  (float64)1000000)	  //not more at 10^11 use
 {
  blocks11 /=  (float64)10;  uncblocks11 /=  (float64)10;
 }





 if(data)
{
   conterr++;	//continuous errors
}
else
{
   conterr = 0;
}



#ifndef FEC_BER
 if(data)
#else

if(oldlock)   //have clean data
{
//blocks += alldata; uncblocks = uncblocks + (float64)data;
blocks +=   alldata; uncblocks += (float64)data;
blocks6 +=  alldata; uncblocks6 += (float64)data;
blocks7 +=  alldata; uncblocks7 += (float64)data;
blocks8 +=  alldata; uncblocks8 += (float64)data;
blocks9 +=  alldata; uncblocks9 += (float64)data;
blocks10 += alldata; uncblocks10 += (float64)data;
blocks11 += alldata; uncblocks11 += (float64)data;

}


//if      (uncblocks6 > 1) {uncblocksm = uncblocks6; blocksm = blocks6; }  //do not use
//else if (uncblocks7 > 1) {uncblocksm = uncblocks7; blocksm = blocks7;}

//if (uncblocks7 > 1) {uncblocksm = uncblocks7; blocksm = blocks7;}
//if (uncblocks8 > 1) {uncblocksm = uncblocks8; blocksm = blocks8;}
if (uncblocks9 > 1) {uncblocksm = uncblocks9; blocksm = blocks9;}
else if (uncblocks10 > 1) {uncblocksm = uncblocks10; blocksm = blocks10;}
else if (uncblocks11 > 1) {uncblocksm = uncblocks11; blocksm = blocks11;}
else {uncblocksm = uncblocks; blocksm = blocks;}




 if(uncblocks && blocks)
#endif
 {
 #ifndef FEC_BER

 tber = (float64)data/(float64)0xFFFFFFFF;
 #else
 

  // tber = (float64)data/(float64)alldata;
 //  tber = (float64)uncblocks/(float64)blocks;
   tber = (float64)uncblocksm/(float64)blocksm;

 #endif



 }

#ifdef START_PRINT
//printfpdv("\n\r tber : %fl", tber);
#endif

//ok
  
 //float64 tber = ber;
 unsigned char stepber = 0;

//  printfpdv("\n\r%15.8f",(float64 )tber );

 


 if(tber > 0)
 {
 	while(tber  < 1) 
 	{
   tber *= 10;
   stepber++;
 	}
 }
 else
 {
   stepber = 0;
   tber = 0;
 }


   
//MBER.Value = ber;
//MEbN0.ChangingValue = MEbN0.Value; 

uber = (unsigned)(tber * 10); 

MBER.Value = tber;
MBERE.Value =  (double)stepber;	//do not used
MBERE.ChangingValue = MBERE.Value;
//printfpdv("\n\r mbere : %.2f", MBERE.Value );
//printfpdv("  mtbere : %.1f", MTBERE.Value );

//ok return;

float d =  my_pow(10, (-1* MBERE.Value));

//printfpdv("  mbere : %.1f", MBERE.Value );

float dt = my_pow(10, (-1* MTBERE.Value));	 //hier mtbere is too big!


//wrong return;

float b;
		if(d)
		{
      		b =  MBER.Value  / d;
	    }
		else
		{
		b = 0;
		}


float bt;
	  if(dt)
		{
	   bt  = 	MTBER.Value / dt;
	   }
	   else
	   {
	   bt = 0;
	   }
//printfpdv("\n\r b : %e", b );
//printfpdv(" bt : %e", bt );



if(SatSound.Value)
 		{

	  //	printfpdv("\n\rpow> %e ",pow(10, (-1* MTBERE.Value)));
	  //	 if(MBER.Value / my_pow(10, ( MBERE.Value))  > (MTBER.Value / my_pow(10, (MTBERE.Value))))
		  if(b > bt)
		 {
	 	     Ring(1,1,5,4);
		//	printfp("\n\r ber ring! \n\r");
		 }
		 else
		 {
		//   printfp(" no ber ring! \n\r");

		 }
 		}





dev1.md100se.MBER0 = uber 		 & 0xff;
dev1.md100se.MBER1 = (uber >> 8)  & 0xff;
	
MBERE.Value =  (double)stepber;	//do not used
MBERE.ChangingValue = MBERE.Value;

dev1.md100se.MBERE = stepber; 

oldlock =  LOCK;


//printfpdv("\n\r%15.8f",(float64 )MBER.Value );

//printfpd("\n\r step ber : %d", stepber);
   
}

extern "C" double GetMBER(void)
{
return (double)MBER.Value;
}

extern "C" double GetMBERE(void)
{
return (double)MBERE.Value;
}

extern "C" double GetMAGC(void)
{
return (double)MAGC.Value;
}

extern "C" double GetMSweep(void)
{
return (double)MSweep.Value;
}

extern "C" char* GetTModul(void)
{
  MTModul.MakeResultStrV();
  return MTModul.pResultStr;
}

extern "C" double GetTCode(void)
{
return (double)MTCode.Value;
}

extern "C" double GetTSymb(void)
{
return (double)MTDRate.Value;
}

extern "C" char* GetRModul(void)
{
  MRModul.MakeResultStrV();
//  return MTModul.pResultStr;
  return MRModul.pResultStr;
}
  /*
extern "C" char* GetDFE(void)
{
  DFE.MakeResultStrS();
 // return MTModul.pResultStr;
 // return DFE.pResultStr;
}

 */
extern "C" double GetRCode(void)
{
return (double)MRCode.Value;
}

extern "C" double GetRSymb(void)
{
return (double)MRDRate.Value;
}

extern "C" char* GetEthMode(void)
{
  MEthModeI.MakeResultStrV();
  return MEthModeI.pResultStr;
}
 
extern "C" double GetMEthSend(void)
{
//  printfpdv("\n\r%15.8f",(float64 )MEthSend.Value );

return (double)MEthSend.Value;
}
  

extern "C" long GetMEthSendS(void)
{
 // printfpd("\n\rget tramsmit :%ld",(long )MEthTransmit.Value );

return (long)MEthTransmit.Value;
}
  

extern "C" long GetMEthReceivedS(void)
{
return (long)MEthReceived.Value;
}
 
extern "C" long GetMEthSendUS(void)
{
return (long)MEthSendU.Value;

}

extern "C" long GetMEthReceivedCRCS(void)
{
return (long)MEthReceivedCRC.Value;
}
 /*
extern "C" long GetMEthSendS(void)
{
 // printfpd("\n\r%ld",(long )MEthSend.Value );

return (long)MEthSend.Value;
}
*/
   

extern "C"double GetMEthReceived(void)
{
return (double)MEthReceived.Value;
}

extern "C" double GetMEthSendU(void)
{
return (double)MEthSendU.Value;
}

extern "C" double GetMEthReceivedCRC(void)
{
return (double)MEthReceivedCRC.Value;
}
 














/*
extern "C" void SetMBER(unsigned long notused, unsigned long ber)
{

 unsigned char cnt = 0;
 unsigned long tmp = 1;
 double tmp1;


 

   
//MBER.Value = (double)ber  / (double)tmp1;


	  

MBER.Value = 5.6; //ber  / 0xffffffff;
	 
tmp1 = 	MBER.Value;


 if(tmp1)
 {
 while(tmp1 < 1)
 {
  tmp1 *= 10;
  cnt ++;
 // tmp1 *= 10;
 }
 }
 else
 {
  tmp1 = 1;
  cnt = 0;
 }
  


//MEbN0.ChangingValue = MEbN0.Value; 
	  
unsigned uber = (unsigned)(tmp1 * 10);   //to  in 0,1
dev1.md100se.MBER0 = uber 		 & 0xff;
dev1.md100se.MBER1 = (uber >> 8)  & 0xff;
	 
MBERE.Value =  10;//cnt;	// not need
MBERE.ChangingValue = MBERE.Value;


dev1.md100se.MBERE = cnt; 
   	 
}
   */

extern PVG610_NET_ETH_PM_STRUCT Pma;

extern "C" void InitEthStat(void) //, unsigned long highs)
{
//printfp("\n\r  InitEthStat");
 
  MEthSend.Value = 0;
  MEthSendU.Value = 0;
  MEthReceived.Value = 0;
  MEthTransmit.Value = 0l;

  MEthReceivedCRC.Value = 0;
  MEthRcvD.Value = 0l;


Pma.rx.truncatedFrames = 0;
Pma.rx.longEvents = 0;
Pma.rx.vlanTagsDetected = 0;
Pma.rx.unsopprtedOpcodes = 0;
Pma.rx.pauseFrames = 0;
Pma.rx.controlFrames = 0;
Pma.rx.dribbleNibbles = 0;
Pma.rx.broadcasts = 0;
Pma.rx.multicasts = 0;
Pma.rx.dones = 0;
Pma.rx.outOfRangeErrors = 0;
Pma.rx.lengthCheckErrors = 0;
Pma.rx.crcErrors = 0;
Pma.rx.codeErrors = 0;
Pma.rx.falseCarrierErrors = 0;
Pma.rx.rxDvEvent = 0;
Pma.rx.previosPacketDropped = 0;
Pma.rx.byteCounterLow = 0;
Pma.rx.byteCounterHigh = 0;
			   
Pma.tx.vlanTags = 0;
Pma.tx.backpressuresEvents = 0;
Pma.tx.pauseFrames = 0;
Pma.tx.controlFrames = 0;
Pma.tx.wireByteCounterLow = 0;
Pma.tx.wireByteCounterHigh = 0;
Pma.tx.underruns = 0;
Pma.tx.giants = 0;
Pma.tx.lateCollisions = 0;
Pma.tx.maxCollisions = 0;
Pma.tx.excessiveDefers = 0;
Pma.tx.nonExcessiveDefers = 0;
Pma.tx.broadcasts = 0;
Pma.tx.multicasts = 0;
Pma.tx.dones = 0;
Pma.tx.reserved = 0;
Pma.tx.lengthCheckErrors = 0;
Pma.tx.crcErrors = 0;
Pma.tx.collisions = 0;
Pma.tx.byteCounterLow = 0;
Pma.tx.byteCounterHigh = 0;

Pma.gfp.fcsErrors = 0;
Pma.gfp.checErrors = 0;
Pma.gfp.droppedFrames = 0;
Pma.gfp.frameDelineationLosses = 0;

Pma.qos.rxQ1Frames = 0;
Pma.qos.rxQ1DroppedFrames = 0;
Pma.qos.rxQ2Frames = 0;
Pma.qos.rxQ2DroppedFrams = 0;
Pma.qos.txFrames = 0;
Pma.qos.txDroppedFrames = 0;

}




extern "C" void SetMEthSend(unsigned long lows) //, unsigned long highs)
{
 // ethsend += (double)lows;//  + ((double)highs *(2 ^ 32));
	 
  dev1.md100se.MEthSend0 = lows;
  dev1.md100se.MEthSend1 = lows >> 8;
  dev1.md100se.MEthSend2 = lows >> 16;
  dev1.md100se.MEthSend3 = lows >> 24;

 // dev1.md100se.MEthSendH0 = highs;
 // dev1.md100se.MEthSendH1 = highs >> 8;
 // dev1.md100se.MEthSendH2 = highs >> 16;
 // dev1.md100se.MEthSendH3 = highs >> 24;

//  MEthSend.Value = lows;
  MEthSend.Value += lows;
	  

}


extern "C" void SetMEthSendU(unsigned long lows) //, unsigned long highs)
{
  //ethsendu += (double)lows;//  + ((double)highs *(2 ^ 32));
	 
  dev1.md100se.MEthSendU0 = lows;
  dev1.md100se.MEthSendU1 = lows >> 8;
  dev1.md100se.MEthSendU2 = lows >> 16;
  dev1.md100se.MEthSendU3 = lows >> 24;

 // dev1.md100se.MEthSendH0 = highs;
 // dev1.md100se.MEthSendH1 = highs >> 8;
 // dev1.md100se.MEthSendH2 = highs >> 16;
 // dev1.md100se.MEthSendH3 = highs >> 24;

 // MEthSendU.Value = lows;
  MEthSendU.Value += lows;
	  

}

extern "C" void SetMEthRcvD(unsigned long lows)
{
  //ethsendu += (double)lows;//  + ((double)highs *(2 ^ 32));
	 
 // dev1.md100se.MEthSendU0 = lows;
//  dev1.md100se.MEthSendU1 = lows >> 8;
//  dev1.md100se.MEthSendU2 = lows >> 16;
 // dev1.md100se.MEthSendU3 = lows >> 24;

 // dev1.md100se.MEthSendH0 = highs;
 // dev1.md100se.MEthSendH1 = highs >> 8;
 // dev1.md100se.MEthSendH2 = highs >> 16;
 // dev1.md100se.MEthSendH3 = highs >> 24;

 // MEthRcvD.Value = lows;
  MEthRcvD.Value += lows;
	  

}



extern "C" void SetMEthReceived(unsigned long lowr)//, unsigned long highr)
{
 //ethreceived += (double)lowr;//  + ((double)highr *(2 ^ 32));
//printfpd("\n\r SetMEthReceived: %d", lowr);

	 
   dev1.md100se.MEthReceived0  = lowr;
   dev1.md100se.MEthReceived1  = lowr >> 8;
   dev1.md100se.MEthReceived2  = lowr >> 16;
   dev1.md100se.MEthReceived3  = lowr >> 24;


//   dev1.md100se.MEthReceivedH0  = highr;
//   dev1.md100se.MEthReceivedH1  = highr >> 8;
//   dev1.md100se.MEthReceivedH2  = highr >> 16;
//   dev1.md100se.MEthReceivedH3  = highr >> 24;
  
 // MEthReceived.Value = lowr;
  MEthReceived.Value += lowr;
   
}

extern "C" void SetMEthTransmit(unsigned long lowr)//, unsigned long highr)
{

//printfpd("\n\r SetMEthTransmit : %d", lowr);
 //ethreceived += (double)lowr;//  + ((double)highr *(2 ^ 32));
 
//   dev1.md100se.MEthReceivedH0  = highr;
//   dev1.md100se.MEthReceivedH1  = highr >> 8;
//   dev1.md100se.MEthReceivedH2  = highr >> 16;
//   dev1.md100se.MEthReceivedH3  = highr >> 24;
  
 // MEthTransmit.Value = lowr;
  MEthTransmit.Value += lowr;
   
}


extern "C" void SetMEthReceivedCRC(unsigned long lowr)//, unsigned long highr)
{
 //ethreceived += (double)lowr;//  + ((double)highr *(2 ^ 32));
	 
   dev1.md100se.MEthReceivedCRC0  = lowr;
   dev1.md100se.MEthReceivedCRC1  = lowr >> 8;
   dev1.md100se.MEthReceivedCRC2  = lowr >> 16;
   dev1.md100se.MEthReceivedCRC3  = lowr >> 24;


//   dev1.md100se.MEthReceivedH0  = highr;
//   dev1.md100se.MEthReceivedH1  = highr >> 8;
//   dev1.md100se.MEthReceivedH2  = highr >> 16;
//   dev1.md100se.MEthReceivedH3  = highr >> 24;
  
//  MEthReceivedCRC.Value = lowr;
  MEthReceivedCRC.Value += lowr;
   
}

 


  

extern "C" void SetMTBERE()
{



  dev1.md100se.MTBERE = MTBERE.Value;
}


extern "C" long GetMACMMSNMP()
{
 return (long)MACMM.ChangingValue;

}

extern "C" void SetMACMMSNMP(long val)
{

if(!acm_status)	return;

if(val < 2)
{
 MACMM.Value = val;
 SetMACMM();
}

}

extern float64 MEbN0_UP, MEbN0_DOWN;


#define  USED_MODES	(16)

typedef struct{
 float64  MEbN0_UP;
 float64  MEbN0_DOWN;
 unsigned long next_up;
 unsigned long next_down;
 unsigned long isenabled;
} acm_mode;
  
 
typedef struct{
 acm_mode	amode[USED_MODES];
}  acm_mode_pull;

 
acm_mode_pull amp;

 
 #ifdef RACM

extern "C" void ACM_MODE_PULL_init()
{
unsigned long i;

 for(i = 0; i < USED_MODES; i++)
 {
   amp.amode[i].MEbN0_UP = MEbN0_UP_DEFAULT; 	//temporary
   amp.amode[i].MEbN0_DOWN = MEbN0_DOWN_DEFAULT; //temporary
   if(i < USED_MODES - 1) { amp.amode[i].next_up =  i + 1;} else { amp.amode[i].next_up = USED_MODES - 1;}
   if(i) {amp.amode[i].next_down =  i - 1;} else {  amp.amode[i].next_down = 0;}
   amp.amode[i].isenabled =	1;
 }

}

//#ifdef RACM

extern "C" void ACM_DEFAULT_init()
{
unsigned long i;


RACMOnOffT.Value = 0;
RACMOnOffT.ChangingValue = 0;

RACMOnOff.Value = 0;
RACMOnOff.ChangingValue = 0;

RACMOffset.Value = 0;
RACMOffset.ChangingValue = 0;



ratimelock.Value = MIN_ratimelock;
ratimelock.ChangingValue = MIN_ratimelock;

ratimemode.Value = MIN_ratimemode;
ratimemode.ChangingValue = MIN_ratimemode;

ratimemse.Value = MIN_ratimemse;
ratimemse.ChangingValue = MIN_ratimemse;

ratimestep.Value = MIN_ratimestep;
ratimestep.ChangingValue = MIN_ratimestep;

	  /*
		
 for(i = 0; i < USED_MODES; i++)
 {
    enamode[i].Value = 1;
	enamode[i].ChangingValue = 1;


    if(i < USED_MODES - 1) 
     {
     numode[i].Value = i + 1; 
     numode[i].ChangingValue =  numode[i].Value;
     }
    else
	{
    	 numode[i].Value = i;
		  numode[i].ChangingValue =  numode[i].Value;
	}

	if(i)	
	{
	 ndmode[i].Value = i - 1;
	  ndmode[i].ChangingValue =  ndmode[i].Value;

	} 
	   else	
	   {
	    ndmode[i].Value = i;
		 ndmode[i].ChangingValue =  ndmode[i].Value;

	   }

 }
	  */
   enamode[0].Value = 1;     enamode[0].ChangingValue = 1;
   enamode[1].Value = 1;     enamode[1].ChangingValue = 1;
   enamode[2].Value = 1;     enamode[2].ChangingValue = 1;
   enamode[3].Value = 1;     enamode[3].ChangingValue = 1;
   enamode[4].Value = 1;     enamode[4].ChangingValue = 1;
   enamode[5].Value = 1;     enamode[5].ChangingValue = 1;
   enamode[6].Value = 1;     enamode[6].ChangingValue = 1;
   enamode[7].Value = 0;     enamode[7].ChangingValue = 0;
   enamode[8].Value = 1;     enamode[8].ChangingValue = 1;
   enamode[9].Value = 1;     enamode[9].ChangingValue = 1;
   enamode[10].Value = 1;     enamode[10].ChangingValue = 1;
   enamode[11].Value = 1;     enamode[11].ChangingValue = 1;
   enamode[12].Value = 0;     enamode[12].ChangingValue = 0;
   enamode[13].Value = 0;     enamode[13].ChangingValue = 0;
   enamode[14].Value = 0;     enamode[14].ChangingValue = 0;
   enamode[15].Value = 0;     enamode[15].ChangingValue = 0;

   ndmode[0].Value =  0;	  ndmode[0].ChangingValue =  ndmode[0].Value;
   ndmode[1].Value =  0;	  ndmode[1].ChangingValue =  ndmode[1].Value;
   ndmode[2].Value =  1;	  ndmode[2].ChangingValue =  ndmode[2].Value;
   ndmode[3].Value =  2;	  ndmode[3].ChangingValue =  ndmode[3].Value;
   ndmode[4].Value =  3;	  ndmode[4].ChangingValue =  ndmode[4].Value;
   ndmode[5].Value =  4;	  ndmode[5].ChangingValue =  ndmode[5].Value;
   ndmode[6].Value =  5;	  ndmode[6].ChangingValue =  ndmode[6].Value;
   ndmode[7].Value =  6;	  ndmode[7].ChangingValue =  ndmode[7].Value;
   ndmode[8].Value =  6;	  ndmode[8].ChangingValue =  ndmode[8].Value;
   ndmode[9].Value =  8;	  ndmode[9].ChangingValue =  ndmode[9].Value;
   ndmode[10].Value =  9;	  ndmode[10].ChangingValue = ndmode[10].Value;
   ndmode[11].Value =  10;	  ndmode[11].ChangingValue = ndmode[11].Value;
   ndmode[12].Value =  11;	  ndmode[12].ChangingValue = ndmode[12].Value;
   ndmode[13].Value =  12;	  ndmode[13].ChangingValue = ndmode[13].Value;
   ndmode[14].Value =  13;	  ndmode[14].ChangingValue = ndmode[14].Value;
   ndmode[15].Value =  14;	  ndmode[15].ChangingValue = ndmode[15].Value;

   numode[0].Value =  1;	  numode[0].ChangingValue =  numode[0].Value;
   numode[1].Value =  2;	  numode[1].ChangingValue =  numode[1].Value;
   numode[2].Value =  3;	  numode[2].ChangingValue =  numode[2].Value;
   numode[3].Value =  4;	  numode[3].ChangingValue =  numode[3].Value;
   numode[4].Value =  5;	  numode[4].ChangingValue =  numode[4].Value;
   numode[5].Value =  6;	  numode[5].ChangingValue =  numode[5].Value;
   numode[6].Value =  8;	  numode[6].ChangingValue =  numode[6].Value;
   numode[7].Value =  8;	  numode[7].ChangingValue =  numode[7].Value;
   numode[8].Value =  9;	  numode[8].ChangingValue =  numode[8].Value;
   numode[9].Value =  10;	  numode[9].ChangingValue =  numode[9].Value;
   numode[10].Value =  11;	  numode[10].ChangingValue = numode[10].Value;
   numode[11].Value =  12;	  numode[11].ChangingValue = numode[11].Value;
   numode[12].Value =  13;	  numode[12].ChangingValue = numode[12].Value;
   numode[13].Value =  14;	  numode[13].ChangingValue = numode[13].Value;
   numode[14].Value =  15;	  numode[14].ChangingValue = numode[14].Value;
   numode[15].Value =  15;	  numode[15].ChangingValue = numode[15].Value;





    debn[0].ChangingValue = 7.1;	    uebn[0].ChangingValue = 9.4;
    debn[1].ChangingValue = 9.2;	    uebn[1].ChangingValue = 10.2;
    debn[2].ChangingValue = 10.0;	    uebn[2].ChangingValue = 11.0;
    debn[3].ChangingValue = 10.8;	    uebn[3].ChangingValue = 11.8;
    debn[4].ChangingValue = 11.6;	    uebn[4].ChangingValue = 12.6;
    debn[5].ChangingValue = 12.4;	    uebn[5].ChangingValue = 13.3;
    debn[6].ChangingValue = 13.1;	    uebn[6].ChangingValue = 13.8;
    debn[7].ChangingValue = 40.0;	    uebn[7].ChangingValue = 2.0;
    debn[8].ChangingValue = 13.6;	    uebn[8].ChangingValue = 14.0;
    debn[9].ChangingValue = 14.2;	    uebn[9].ChangingValue = 14.8;
    debn[10].ChangingValue = 14.6;	    uebn[10].ChangingValue = 15.2;
    debn[11].ChangingValue = 15.0;	    uebn[11].ChangingValue = 25.0;
    debn[12].ChangingValue = 26.5;	    uebn[12].ChangingValue = 27.0;
    debn[13].ChangingValue = 27.5;	    uebn[13].ChangingValue = 28.0;
    debn[14].ChangingValue = 28.5;	    uebn[14].ChangingValue = 29.0;
    debn[15].ChangingValue = 29.5;	    uebn[15].ChangingValue = 30.0;

    debn[0].Value = debn[0].ChangingValue;	    uebn[0].Value = uebn[0].ChangingValue;
    debn[1].Value = debn[1].ChangingValue;	    uebn[1].Value = uebn[1].ChangingValue;
    debn[2].Value = debn[2].ChangingValue;	    uebn[2].Value = uebn[2].ChangingValue;
    debn[3].Value = debn[3].ChangingValue;	    uebn[3].Value = uebn[3].ChangingValue;
    debn[4].Value = debn[4].ChangingValue;	    uebn[4].Value = uebn[4].ChangingValue;
    debn[5].Value = debn[5].ChangingValue;	    uebn[5].Value = uebn[5].ChangingValue;
    debn[6].Value = debn[6].ChangingValue;	    uebn[6].Value = uebn[6].ChangingValue;
    debn[7].Value = debn[7].ChangingValue;	    uebn[7].Value = uebn[7].ChangingValue;
    debn[8].Value = debn[8].ChangingValue;	    uebn[8].Value = uebn[8].ChangingValue;
    debn[9].Value = debn[9].ChangingValue;	    uebn[9].Value = uebn[9].ChangingValue;
    debn[10].Value = debn[10].ChangingValue;	uebn[10].Value = uebn[10].ChangingValue;
    debn[11].Value = debn[11].ChangingValue;	uebn[11].Value = uebn[11].ChangingValue;
    debn[12].Value = debn[12].ChangingValue;	uebn[12].Value = uebn[12].ChangingValue;
    debn[13].Value = debn[13].ChangingValue;	uebn[13].Value = uebn[13].ChangingValue;
    debn[14].Value = debn[14].ChangingValue;	uebn[14].Value = uebn[14].ChangingValue;
    debn[15].Value = debn[15].ChangingValue;	uebn[15].Value = uebn[15].ChangingValue;

		SetNeedWriteDevId();
		
}

unsigned short Get_ratimestep(void)
{ 
 return (unsigned short)ratimestep.Value;
}



#define TIME_LOCK_DELAY	(1000)
#define TIME_CHANGE_MODE_DELAY	 (10)
#define TIME_KEEP_MSE_DELAY (5)
#define TIME_STEP_ACM (2000)


#define MAX_MSE (100)


extern "C" void R_ACM_Receive_side()
{
 //static unsigned char racm_old;
//  float msetu, msetd;
char Buf[3];

  //hier check ebn and make sended "racm"
    MEbN0_UP  = MEbN0_UP_DEFAULT;		  //for test
	MEbN0_DOWN	 = 	MEbN0_DOWN_DEFAULT;	  //for test
	unsigned i =  GetMRMode();

if(!((unsigned char)RACMOnOff.Value)) return; //use mdemod as racm on / off



unsigned long   variant =  GetNumConfigFilet(0) & CONFIG_FILE_MASK;
unsigned long   variant1 =  GetNumConfigFilet(1) & CONFIG_FILE_MASK;	

if(variant != variant1) 
{
  ReadErrors3(0);
}
else
{
  ReadErrors2(0);
}



  static unsigned timemsecur;
  static unsigned msenum;
   static float mse[MAX_MSE];
   float mse_int;
   static unsigned	 msenum_max;


  if(timemsecur > time1) 
  {
      timemsecur = time1;

  }

 if(timelock > time1) 
  {
      timelock = time1;

  }

 if(timechangemode > time1) 
  {
      timechangemode = time1;

  }

 if(timekeepMSE > time1) 
  {
     timekeepMSE = time1;

  }






  if(time1 - timemsecur > ratimemse.Value)
  {
      timemsecur = time1;
	  msenum_max = 	msenum;
	 msenum = 0;
  }
  else
  {
  	if(msenum < MAX_MSE - 1) msenum++;
   //	else  msenum = 0;
  }

	   mse[msenum]	=  gmse;


	mse_int = 0;
 // for(unsigned in = 0; in <= msenum; in++)

  if(msenum_max)
  {

  for(unsigned in = 0; in < msenum_max; in++)
  {
   mse_int += mse[in];
  //  printfpdv("\n\r mse[in] : % 4.1f ",   mse[in]);

   //  printfpdv(" mse_intsum : % 4.1f ",   mse_int);

  }

 //  mse_int /= (float)(msenum + 1); 
   mse_int /= (float)(msenum_max); 
   }
   else
   {
	mse_int =  mse[msenum];	
   }


 // if(!((unsigned char)RACMOnOff.Value)) return; //use mdemod as racm on / off

   if(!LOCK)   // hier do not send some!!!!! 
   {
  //	 if(i)
  //	 {
  //	 racm = 0;
  // 	 SendStatus();
  //	 }
   return;
  //	  mse_int = 0; 
   }
  // if( time1 - timelock < TIME_LOCK_DELAY)  return;

  if(( time1 - timelock < ratimelock.Value) ||

//   if( time1 - timechangemode < TIME_CHANGE_MODE_DELAY)  return; 
    ( time1 - timechangemode < ratimemode.Value) || 

   // if( time1 - timekeepMSE < TIME_KEEP_MSE_DELAY)  return;
    ( time1 - timekeepMSE < ratimemse.Value)) 
	{
       racm = i;	  //do not change some
       SendStatus();
    //   timechangemode = time1;		
       return;
	}

//  if((MEbN0.Value > MEbN0_UP) && (racm < MAX_MTMODE))
//  {
//   	 racm++;
//  }

//printfpd("\n\r i = %2d ", i);
//  printfpdv("\n\r mse : % 4.1f ",   gmse);
 //  printfpdv(" mse_int : % 4.1f ",   mse_int);
  //   printfpd(" mse_num_max : %d ",  msenum_max);

//printfpdv(" % 4.1f ",MEbN0.Value);
//printfpdv(" u % 4.1f ",amp.amode[i].MEbN0_UP);
//printfpdv(" d % 4.1f ",amp.amode[i].MEbN0_DOWN);
//printfpd(" e %2d ", amp.amode[ amp.amode[i].next_up].isenabled);



/*
MDataC ratimelock;
MDataC ratimemode;
MDataC ratimemse;
MDataC ratimestep;


MDataC uebn[16];
MDataC debn[16];
MDataV enamode[16];
MDataV numode[16];
MDataV ndmode[16];
*/

  // printfpdv("\n\r mse : % 4.1f ",   gmse);

//  if((gmse > uebn[i].Value) 
//    if((mse_int	 > uebn[i].Value) 
	  
 //   msetu = uebn[i].Value + RACMOffset.Value;
 //	msetd = debn[i].Value  + RACMOffset.Value; 

//    printfpd("\n\r i = %2d ", i);
//	printfpdv(" msetu : % 4.1f ",   msetu);
//	printfpdv(" msetd : % 4.1f ",   msetd);

	 

    if((mse_int	 > (uebn[i].Value + RACMOffset.Value)) 
  && (numode[i].Value != i)
  && (enamode[(unsigned)numode[i].Value].Value == 1))
  {
   	 racm = numode[i].Value;

//#define	EV_ACM_T_UP			 	 (17)
//#define	EV_ACM_T_D 			 	 (18)
//#define	EV_ACM_R_UP			 	 (19)
//#define	EV_ACM_R_D 			 	 (20)

   if( racm_old	!= racm)
   {
   sprintf(Buf, "%02d",racm);
   Add_Event(EV_ACM_R_UP, 2, Buf);
   racm_old  = racm;
      timechangemode = time1;		
  }


//hier can send mailbox
// printfpdv("\n\r mse : % 4.1f ",   gmse);
// if(GetTestMode() == 0x50)
 // {
//printfpd("\n\r i = %2d ", i);

// printfpdv("up with % 4.1f ",uebn[i].Value);
//	  printfpdv(" mse : % 4.1f ",   gmse);
 //	   printfpd("numode = %2d ", numode[i].Value);
 //	}
  //	 SendStatus();
  }
//  else 	if((gmse < debn[i].Value) 
  else 	if((mse_int < (debn[i].Value  + RACMOffset.Value)) 
  && (ndmode[i].Value != i)
  && (enamode[(unsigned)ndmode[i].Value].Value == 1))
 //  if((MEbN0.Value < amp.amode[i].MEbN0_DOWN) && (amp.amode[i].next_down != i) &&
   // 			( amp.amode[ amp.amode[i].next_down].isenabled ==	1))

  {

 // if(GetTestMode() == 0x50)
 // {
 // printfpd("\n\r i = %2d ", i);
//  printfpdv("down with % 4.1f ",debn[i].Value);
 //  printfpdv(" mse : % 4.1f ",   gmse);
  //	   printfpd("ndmode = %2d ", ndmode[i].Value);
 // }

   	 racm = ndmode[i].Value;

  if( racm_old	!= racm)
   {
   sprintf(Buf, "%02d",racm);
   Add_Event(EV_ACM_R_D, 2, Buf);
   racm_old  = racm;
  }



//hier can send mailbox
   //  SendStatus();

  }

	  SendStatus();		//olwais


  /*
   if((MEbN0.Value > amp.amode[i].MEbN0_UP) && (amp.amode[i].next_up != i) &&
    			( amp.amode[ amp.amode[i].next_up].isenabled ==	1))
  {
   	 racm = amp.amode[i].next_up;

//hier can send mailbox
  	 SendStatus();
  }


// if((MEbN0.Value < MEbN0_DOWN) && (racm > MIN_MTMODE))
//  {
//   	 racm--;
//  }

  else  if((MEbN0.Value < amp.amode[i].MEbN0_DOWN) && (amp.amode[i].next_down != i) &&
    			( amp.amode[ amp.amode[i].next_down].isenabled ==	1))
  {
   	 racm = amp.amode[i].next_down;

//hier can send mailbox
     SendStatus();

  }

*/




}

#define MAX_LOST_MAILBOXES	  (10)

extern "C" void R_ACM_Transmit_side()
{
 // static unsigned char 
 //printfpd("\n\r racm_far = %2d ", racm_far);
// printfpd(" MTMode.Value = %2d ", MTMode.Value);
 //printfpd(" flag_racm_far = %2d ", flag_racm_far);
 // printfpd(" MTMode.Quantity = %2d ",MTMode.Quantity);	//12

/*	t
 if(((unsigned char)MTMode.Value != racm_far)   &&
       ((racm_far >= MIN_MTMODE) && (racm_far <= MAX_MTMODE))  &&
       		 flag_racm_far	  )

*/

//static unsigned lost_mailboxes;

  //	printfpd("\n\r l m : %d", lost_mailboxes);

  char Buf[3];

   unsigned max_lost;

  // if(!((unsigned char)RACMOnOffT.Value)) return; //use mdemod as racm on / off

   				   if(Get_ratimestep())	  //to not divide to zero
				   {
			 //		printfpd(" timestep_far : %d ", timestep_far);
			 //	   printfpd(" Get_ratimestep : %d ", Get_ratimestep());

					if(flag_racm_fart)
					{
   			     	max_lost = timestep_far *  MAX_LOST_MAILBOXES	/  Get_ratimestep();
		  //need manu times use!			  flag_racm_fart = 0;
					}
					else
					{
					 max_lost =  MAX_LOST_MAILBOXES << 1;
					}
				   
				   }
				   else
				   {
					  max_lost =  MAX_LOST_MAILBOXES << 1;	
				   }

//printfpd(" max_lost : %d", max_lost);


    if(! ReceiveStatus())
    {

  //   if(lost_mailboxes <=  MAX_LOST_MAILBOXES + 1)lost_mailboxes ++;
     if(lost_mailboxes <=  max_lost + 1) 
     {
     lost_mailboxes ++;

    //  if((lost_mailboxes > MAX_LOST_MAILBOXES) && GetMTMode())
	  }
	  else if(GetMTMode() && (unsigned char)RACMOnOffT.Value)
	  {
		MTMode.Value = 0;
	    MTMode.ChangingValue = MTMode.Value;
        SetMTMode();
		lost_mailboxes = 0;
        flag_racm_fart = 0;
	  }
    
    return;
	}
 //	else
 //	{
	  lost_mailboxes = 0;

 //	}



 if(((unsigned char)MTMode.Value != racm_far)   &&
       ((racm_far >= MIN_MTMODE) && (racm_far < MTMode.Quantity))  &&
       		 flag_racm_far	  )


// if(1)	//t
 {

    //printfp("\n\r try set some .................");
	  flag_racm_far = 0;
	  sprintf(Buf, "%02d",racm_far);

    if(racm_far > MTMode.Value)
	{
   //   sprintf(Buf, "%02d",racm_far);
     Add_Event(EV_ACM_T_UP, 2, Buf);
	}
	else
	{
     Add_Event(EV_ACM_T_D, 2, Buf);
	}


	MTMode.Value = racm_far;
	MTMode.ChangingValue = MTMode.Value;
    SetMTMode();




 }

}



extern "C" void R_ACM()
{
 static unsigned long timescan;

// if(!((unsigned char)RACMOnOff.Value)) return; //use mdemod as racm on / off

 if(timescan > time1)	timescan = time1;

// if((time1 - timescan) > STATE_SCAN_PERIOD)	 //algoritm period
// if((time1 - timescan) > TIME_STEP_ACM)	 //algoritm period
 if((time1 - timescan) > ratimestep.Value)	 //algoritm period
 {
   R_ACM_Receive_side();
   R_ACM_Transmit_side();
   timescan = time1;
 }

}

 #endif

extern "C" void SetMACMM()
{

//do not operate acm in second provingent - olwais enable


//return;

// printfp("\n\r SetMACMM");
delay_mcs(100000);

 if(!acm_status)
 {
// MACMM.Value = 2;
 MACMM.ChangingValue = 2;
 MACMM.Changable 	 = 0;
 MTMode.Changable 	 = 1;
 MRMode.Changable 	 = 0;	 //olwais auto
 MACMMI.Value =	 0;
 MACMMI.ChangingValue = 0;
 

//printfp("\n\r ModemAcmSwitch");
//printfpd(" %d", 0);
//printfpd(" : %d",MTMode.Value);
//printfpd("i %d", 1);

    SetMTModeA();
  //t  PVG610_API_ModemAcmEngineEnable(0,0,1,0);

//okdelay_mcs(1000000);
//delay_mcs(100000);
//baddelay_mcs(10000);
//okdelay_mcs(50000);
    PVG610_API_ModemAcmEngineEnable(0,0,1,0);	 //disable acm tx switch
 //   PVG610_API_ModemAcmEngineEnable(0,0,0,0);
//delay_mcs(1000000);
//  PVG610_API_ModemAcmEngineEnable(0,0,1,1);
  PVG610_API_ModemAcmSwitch(0, 0,(unsigned char)MTMode.Value, 1);
  //	PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));


 }
 else
 {
  MACMM.ChangingValue = MACMM.Value;
  MACMM.Quantity = 2;
  MACMM.Changable = 1;

   if(MACMM.Value)	 //acm on
   {
   //  PVG610_API_ModemAcmEngineEnable(0,0,1,1);
    MACMMI.Value =	 1;//0;
    MACMMI.ChangingValue = 1;//0;


	 PVG610_API_ModemAcmEngineEnable(0,0,1,1);

	PVG610_API_ModemAcmProfileEnable( 0, 0,  0xff);	//enable all profiles
	 MTMode.Changable = 0;
 //	 MRMode.Changable = 1;


   }
   else	   //acm off
   {
//      PVG610_API_ModemAcmEngineEnable(0,0,0,0);
	// PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
	  SetMTModeA();
	   PVG610_API_ModemAcmEngineEnable(0,0,1,0);
	  PVG610_API_ModemAcmSwitch(0, 0,(unsigned)MTMode.Value, 1);

	 MTMode.Changable = 1;
 //	 MRMode.Changable = 0;

	  MACMMI.Value =	0;
 MACMMI.ChangingValue = 0;

   }


 }

dev1.md100se.MACMM = MACMM.Value;

}





extern "C" void FillClassesM()
{


// unsigned char tmp;


//ConfigFile.Value = dev1.md100se.ConfigFile;
//ConfigFile.ChangingValue = ConfigFile.Value;


  
//ModForSS.Value = dev1.md100se.ModForSS;
//ModForSS.ChangingValue = ModForSS.Value;


ModEth.Value = dev1.md100se.ModEth;
ModEth.ChangingValue =	ModEth.Value;

//LoadVariants.Value = dev1.md100se.LoadVariants;
//LoadVariants.ChangingValue = LoadVariants.Value;

/*
unsigned char 	ModEth;
unsigned char 	NamesConfigFiles;
unsigned char 	LoadVariants;



unsigned char 	LoadVariantsSet;
unsigned char   SaveVariants;
unsigned char   SaveVariantsSet;
*/
// CurReadedAnyCofig; //number of readed anyconfig to set this variable - filled readanyconfig for reading

MRfOut.Value = dev1.md100se.MRfOut;
MRfOut.ChangingValue = MRfOut.Value;
 	  
MOutLev.Value = (float64)((dev1.md100se.MOutLev1 << 8)	+ dev1.md100se.MOutLev0) *(1) /  (float64)10;
MOutLev.ChangingValue = MOutLev.Value;
  
//MOutLev1.Value = dev1.md100se.MOutLev1; //((dev1.md100se.MOutLev1 << 8)	+ dev1.md100se.MOutLev0) *(1) / 10;
//MOutLev1.ChangingValue = MOutLev1.Value;

//unsigned char  MOutLev0;


//__10

//unsigned char  MOutLev1;




/*

unsigned char MTDRate0;
unsigned char MTDRate1;
unsigned char MTDRate2;
unsigned char MTDRate3;

//__15

unsigned char MRDRate0;
unsigned char MRDRate1;
unsigned char MRDRate2;
unsigned char MRDRate3;
*/

//MTFreq.Value =  ((dev1.md100se.MTFreq3 << 24)	+ (dev1.md100se.MTFreq2 << 16 << 16			+ (dev1.md100se.MTFreq1 << 8) +  dev1.md100se.MTFreq0) / 10000l;

MTFreq.Value =   (float64)((dev1.md100se.MTFreq3 << 24)	+ (dev1.md100se.MTFreq2 << 16) 
					+ (dev1.md100se.MTFreq1 << 8) +  dev1.md100se.MTFreq0) /  (float64)10000l;

MTFreq.ChangingValue = MTFreq.Value;
/*
unsigned char MTFreq0;
unsigned char MTFreq1;
unsigned char MTFreq2;
unsigned char MTFreq3;

*/

//__23

MRFreq.Value =   (float64)((dev1.md100se.MRFreq3 << 24)	+ (dev1.md100se.MRFreq2 << 16) 
					+ (dev1.md100se.MRFreq1 << 8) +  dev1.md100se.MRFreq0) / (float64) 10000l;

 
MRFreq.ChangingValue = MRFreq.Value;
 
 
 /*
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
 */


MDemod.Value = dev1.md100se.MDemod;
MDemod.ChangingValue = MDemod.Value;
//unsigned char MDemod;

printfpd("\n\r Fill: MEthMode %02X", MEthMode.Value);


MEthMode.Value = dev1.md100se.MEthMode;

MEthMode.ChangingValue =MEthMode.Value;

printfpd("\n\r Fill: MEthMode1 %02X", MEthMode.Value);

//
//unsigned char MEthMode;


//__35

MEthPause.Value = dev1.md100se.MEthPause;

MEthPause.ChangingValue =MEthPause.Value;


//unsigned char MEthPause;

MEthctl.Value = dev1.md100se.MEthctl;
MEthctl.ChangingValue =MEthctl.Value;


//unsigned char MEthctl;

MEthMaxF.Value = (dev1.md100se. MEthMaxF1 << 8)	+ dev1.md100se.MEthMaxF0;
MEthMaxF.ChangingValue = MEthMaxF.Value;

//unsigned char MEthMaxF0;
//unsigned char MEthMaxF1;


MEthVlanP.Value = dev1.md100se.MEthVlanP;
MEthVlanP.ChangingValue = MEthVlanP.Value;

/*
unsigned char MEthVlanP;

//__40

unsigned char MEbN00;
unsigned char MEbN01;
unsigned char MEbN02;
unsigned char MEbN03;
*/
//MDataI MTEbN0;


MTEbN0.Value =   (float64)((dev1.md100se.MTEbN01 << 8)	+ dev1.md100se.MTEbN00) /  (float64)10l;
MTEbN0.ChangingValue = MTEbN0.Value;
/*
unsigned char MTEbN00;
unsigned char MTEbN01;

unsigned char MTEbN02;
unsigned char MTEbN03;

unsigned char MBER0;
unsigned char MBER1;
unsigned char MBER2;
unsigned char MBER3;

//_-52

 */

MTBER.Value =  (float64) ((dev1.md100se.MTBER1 << 8)	+ dev1.md100se.MTBER0) /  (float64)10l;
MTBER.ChangingValue = MTBER.Value; 

/*
unsigned char MTBER0;
unsigned char MTBER1;
unsigned char MTBER2;
unsigned char MTBER3;

*/



MTBERE.Value =  dev1.md100se.MTBERE;
MTBERE.ChangingValue = MTBERE.Value;

//unsigned char MTBERE;



//unsigned char MAGC0;	 //input level
//unsigned char MAGC1;
//unsigned char MAGC2;
//unsigned char MAGC3;
   /*
unsigned char MSweep0;
unsigned char MSweep1;
unsigned char MSweep2;
unsigned char MSweep3;
 */
//__65


/*
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
*/

MIfLoop.Value =  dev1.md100se.MIfLoop;
MIfLoop.ChangingValue = MIfLoop.Value;


MUnModul.Value =  dev1.md100se.MUnModul;
MUnModul.ChangingValue = MUnModul.Value;

MACMM.Value =  dev1.md100se.MACMM;
MACMM.ChangingValue = MACMM.Value;

 /*
unsigned char MIfLoop;
unsigned char MUnModul;

unsigned char MACMM;

 */


  CheckParameters();
  UsedExp.State.Reg2.bit.MAll = 1;	  //load all
//  UsedExp.State.Reg2.bit.LogClear = 1; //clear if need


}


extern "C" unsigned char  GetIFLoop()
{
return (unsigned char)MIfLoop.Value;
}

extern "C" unsigned char GetUnModul()
{
return (unsigned char)MUnModul.Value;
}

extern "C" unsigned char GetMRCntl()
{
return (unsigned char)MRCntl.Value;
}





extern "C" void StartLoadAllM()
{
SetMRfOutOff();
//150112StartEthTimed(0); //ModEth
SetMIfLoop();
SetMUnModul();
SetMOutLev();
SetMTFreq();
SetMRFreq();
SetMDemod();
SetMEthMode();

//SetMEthPause();
//SetMEthctl();
//SetMEthMaxF();
SetMEthVlanP();
SetMTEbN0();
SetMTBER();
SetMTBERE();

SetMTFreq();
SetMRFreq();

//SetMACMM();

//SetMRfOut();   //last


//okprintfpd("\n\rSatADemo1 %x", SatADemo.Value);
 /*
SetTrFrequency();
SetRcvFrequency();
SetTrBound(); 
SetRcvBound();
SetFreqProc();
SetSysDelay();
SetOutLevel();
SetAverDistance(); //debug bytes
SetSatTestMode();
SetSatPC();
SetSatTiming();
SetSatSound();
SetSatLowP();
SetSatALev();
//SetSatACode();
//this clear satalev SetSatADemo();
 */

//ok printfpd("\n\rSatADemo 2 %x", SatADemo.Value);


}
 /*
extern "C" void WriteIFmoduleData()
{
//printfp("\n\r WriteIFmoduleData");

}

*/

extern "C" void  SetSatSound()
{
// unsigned char RGstw = 0;
 //printfp(" SetSatSound");
}



extern "C" void ReadIFmoduleData()	 //read data
{ 

outportb(ADR_IFSAT140,MEM);
  delay_mcs(50);
  outportb(ADR_IFSAT140,MEM);


char *pEnd;
//printfp("\n\r ReadIFmoduleData : ");

 //sprintf(IFmoduleData.Value, "%s", "IF Module Data:12 34 56 78");
  AT91F_DataflashInitx();

  char * pBuff;
  int ret = 0;
 
	pBuff = (char *) &TFTP_Buffer1[0];// + num * OneConfSize);


//141119    read_dataflash ((unsigned int)AddressIFModuleData, (unsigned)IFModuleDataSize, (char *)&TFTP_Buffer1[0]);

//extern "C" void ReadDataIFModule(unsigned long addr_dest,  char * pBuf, unsigned long size)
   	 ret = ReadDataIFModule((unsigned long)(IFCONF_ADDRESS),  (char *)&TFTP_Buffer1[0],  (unsigned)IFModuleDataSize);
	 // fill currend config to file
   //	 printfpd("\n\rret> %d \n\r", ret);
	for(unsigned i = 0; i < IFModuleDataSize; i++)
	{
  //	if(!(i%16))	  printfp("\n\r>");

 //  	printfpd(" %c", *pBuff);
	IFmoduleData.Value[i]  = *pBuff++; 
	}
 //	 printfp("\n\r");

 if(ret)	//if have if module
 {
MOutLevO.Value = (float)my_strtod(&IFmoduleData.Value[5], &pEnd) / (float)100;
MOutLevO.ChangingValue =  MOutLevO.Value;

MKOUT.Value =  my_strtod(&IFmoduleData.Value[10], &pEnd)/ (float)10;
MKOUT.ChangingValue = MKOUT.Value;

MKOUT1.Value =  my_strtod(&IFmoduleData.Value[15], &pEnd);
MKOUT1.ChangingValue = MKOUT1.Value;

MKIN1.Value =  my_strtod(&IFmoduleData.Value[20], &pEnd);
MKIN1.ChangingValue = MKIN1.Value;

MKIN2.Value =  my_strtod(&IFmoduleData.Value[25], &pEnd);
MKIN2.ChangingValue = MKIN2.Value;

MKIN3.Value =  my_strtod(&IFmoduleData.Value[30], &pEnd);
MKIN3.ChangingValue = MKIN3.Value;

MOutLevOS.Value =  my_strtod(&IFmoduleData.Value[35], &pEnd);
MOutLevOS.ChangingValue = MOutLevOS.Value;

//printfpd("\n\r MOutLevOS.Value %d", MOutLevOS.Value);
//printfpd(" IFmoduleData.Value 0x%X", IFmoduleData.Value[35]);







}
}  

/*
extern "C" void RestoreParamsFromIFModule()	 //read data
{


}

*/
extern "C" void KeepParamsInIFModule()	 //read data
{

//printfp("\n\r  KeepParamsInIFModule : ");

char Buf[4];
//printfpd("\n\r>%c",IFmoduleData.Value[0]);
sprintf(&IFmoduleData.Value[0], "%s","IFM");
//printfpd("\n\r>%c",IFmoduleData.Value[1]);
//printfpd("\n\r>%c",IFmoduleData.Value[2]);

IFmoduleData.Value[3] = '\n';
IFmoduleData.Value[4] = '\r';


//printfpd("\n\r>%c",IFmoduleData.Value[3]);
//printfpd("\n\r>%c",IFmoduleData.Value[4]);



//printfpd("\n\r>%c",IFmoduleData.Value[5]);
//printfpd("\n\r>%c",IFmoduleData.Value[6]);
//printfpd("\n\r>%c",IFmoduleData.Value[7]);
//printfpd("\n\r>%c",IFmoduleData.Value[8]);
//printfpd("\n\r>%03d",(signed int)(MOutLevO.Value * 10.0));
sprintf(&IFmoduleData.Value[5], "%03d", (signed int)(MOutLevO.ChangingValue * 100.0));
//printfpd("\n\r>%c",IFmoduleData.Value[11]);
//printfpd("\n\r>%c",IFmoduleData.Value[12]);
//printfpd("\n\r>%c",IFmoduleData.Value[13]);
IFmoduleData.Value[8] = '\n';
IFmoduleData.Value[9] = '\r';

//printfpd("\n\r>%03d",(signed int)MKOUT.Value);

sprintf(&IFmoduleData.Value[10], "%03d", (signed int)(MKOUT.ChangingValue* 10.0));
IFmoduleData.Value[13] = '\n';
IFmoduleData.Value[14] = '\r';

sprintf(&IFmoduleData.Value[15], "%03d", (signed int)MKOUT1.ChangingValue);
IFmoduleData.Value[18] = '\n';
IFmoduleData.Value[19] = '\r';

//sprintf(&IFmoduleData.Value[20], "%03d", (signed int)MKIN1.ChangingValue);
sprintf(&IFmoduleData.Value[20], "%04d", (signed int)MKIN1.ChangingValue);
//IFmoduleData.Value[23] = '\n';
//IFmoduleData.Value[24] = '\r';
IFmoduleData.Value[24] = '\n';

sprintf(&IFmoduleData.Value[25], "%04d", (signed int)MKIN2.ChangingValue);
//IFmoduleData.Value[28] = '\n';
IFmoduleData.Value[29] = '\r';
//sprintf(&IFmoduleData.Value[30], "%03d", (signed int)MKIN3.ChangingValue);
sprintf(&IFmoduleData.Value[30], "%04d", (signed int)MKIN3.ChangingValue);
//IFmoduleData.Value[33] = '\n';
//IFmoduleData.Value[34] = '\r';

IFmoduleData.Value[34] = '\n';

sprintf(&IFmoduleData.Value[35], "%d", MOutLevOS.ChangingValue);
IFmoduleData.Value[36] = '\n';
IFmoduleData.Value[37] = '\r';


  //	printfpd("\n\r MOutLevOS cv:  %d",MOutLevOS.ChangingValue);
  //	printfpd("v :  %d",MOutLevOS.Value);


/*
for(unsigned i = 0; i < 37; i++)
	{
	if(!(i%16))	  printfp("\n\r>");

 	printfpd(" %c",IFmoduleData.Value[i]);
 	}

printfpd("\n\rmkin1  %d", MKIN1.ChangingValue);
  */
WriteDataIFModule((unsigned long)(IFCONF_ADDRESS), &IFmoduleData.Value[0],  (unsigned)IFModuleDataSize);


//
}



extern "C" void ReadIFmoduleHeader()	 //read data
{
//printfp("\n\r ReadIFmoduleHeader : ");

 //sprintf(IFmoduleData.Value, "%s", "IF Module Data:12 34 56 78");


  char * pBuff;
 
	pBuff = (char *) &TFTP_Buffer1[0];// + num * OneConfSize);


 //   read_dataflash (((unsigned int)AddressIFModuleData -  (unsigned int)0x40)  , (unsigned)IFModuleDataSize, (char *)&TFTP_Buffer1[0]);
    read_dataflash (((unsigned int)(IFCONF_ADDRESS) -  (unsigned int)0x40)  , (unsigned)IFModuleDataSize, (char *)&TFTP_Buffer1[0]);


	 // fill currend config to file
  //	for(unsigned i = 0; i < IFModuleDataSize; i++)
	for(unsigned i = 0; i < 23; i++)
	{
	 if(!(*pBuff)) *pBuff = ' ';
  //	printfpd(" %c", *pBuff);
	IFmoduleHeader.Value[i]  = *pBuff++; 
	}
   IFmoduleHeader.Value[23]	 = '\0';
}


extern "C" void UpdateDataVal()
{
//141126 #ifndef WIFM	

 UsedExp.State.Reg2.bit.Draw = 1;

// #ifndef WIFM	

 UsedExp.State.Reg2.bit.Some = 1;
 //#endif
}

extern "C" void  SetHbandAndPauseOff()
{
  MEthctl.Value = 0;
  MEthctl.ChangingValue =	 MEthctl.Value;

  MEthPause.Value =  0;
  MEthPause.ChangingValue	= 0;
}

extern "C" char*  GetLogStr0()
{
 return (LogStr0.Value);
}

extern "C" char*  GetLogStr1()
{
 return (LogStr1.Value);
}


extern "C" long GetMOutLev()
{
 return (long)(MOutLev.Value *(-10.0));
}

extern "C" long GetSerial()
{
 return (long)DevId.Value;
}



extern "C"void SetMOutLevSNMP(long val)
{
 MOutLev.Value  = (float64)val/(-10.0);
 MOutLev.ChangingValue  = MOutLev.Value;
 SetMOutLev();
}

extern "C" long SetMTFreqSNMP(long val)
{
  MTFreq.Value =  (float64)val / (float64)1000000.0;
  MTFreq.ChangingValue = MTFreq.Value;
  SetMTFreq();
}


extern "C" long GetMTFreq()
{
   return (long)(MTFreq.Value *(1000000.0));

}

extern "C" long  GetMTMode()
{
 return (long)MTMode.Value;
}

extern "C" long SetMTModeSNMP(long val)
{

printfpd("SetMTModeSNMP %d", val);

 MTMode.Value = (unsigned char)val;
 MTMode.ChangingValue = MTMode.Value;
  SetMTMode();
}

extern "C" long  GetMCONFIG()
{
 return (long)ConfigFile.Value;
}

extern "C" long SetMCONFIGSNMP(long val)
{

unsigned char flag = 0;
//unsigned char tmpval;
unsigned long tmpval;

   tmpval = ConfigFile.Value;


printfpd("\n\rSetMCONFIGSNMP %d", val);

 //ConfigFile.Value = (unsigned char)val;
 ConfigFile.Value = (unsigned long)val;
 ConfigFile.ChangingValue = ConfigFile.Value;

 for(unsigned i = 0; i < NamesConfigFiles.Quantity; i++)
  {
   //	if( (unsigned char)ConfigFile.Value == ReallyNumCfg[i])
	if( (unsigned long)ConfigFile.Value == ReallyNumCfg[i])
	 {
	 flag = 1;
	 break;	 //real number of config file
	 }

  }

   if(!flag)
   {
     ConfigFile.Value = tmpval; //ReallyNumCfg[NamesConfigFiles.ChangingValue];
	 ConfigFile.ChangingValue = ConfigFile.Value;
	 printfpd("\n\rwrong config number! %d", val);

     return;
   }



 UsedExp.State.Reg2.bit.FillCFV0 = 1;
 UsedExp.State.Reg2.bit.WriteId = 1;
 UsedExp.State.Reg2.bit.Some = 1;

//  SetMTMode();
}


extern "C" long SetMRFreqSNMP(long val)
{
  MRFreq.Value =  (float64)val / (float64)1000000.0;
  MRFreq.ChangingValue = MRFreq.Value;
  SetMRFreq();
}


extern "C" long GetMRFreq()
{
   return (long)(MRFreq.Value *(1000000.0));

}

extern "C" long  GetMRMode()
{
 return (long)MRMode.Value;
}

extern "C" long SetMRModeSNMP(long val)
{

printfpd("SetMRModeSNMP %d", val);

 MRMode.Value = (unsigned char)val;
 MRMode.ChangingValue = MRMode.Value;
  SetMRMode();
}

extern "C" long  GetDCONFIG()
{
 return (long)ConfigFile1.Value;
}

extern "C" long SetDCONFIGSNMP(long val)
{

unsigned char flag = 0;
//unsigned char tmpval;
unsigned long tmpval;

   tmpval = ConfigFile1.Value;

printfpd("\n\rSetDCONFIGSNMP %d", val);

 ConfigFile1.Value = (unsigned long)val;
 ConfigFile1.ChangingValue = ConfigFile1.Value;
//printfpd("cf %d", (unsigned)ConfigFile1.Value);

 for(unsigned i = 0; i < NamesConfigFiles1.Quantity; i++)
  {
  //	if( (unsigned char)ConfigFile1.Value == ReallyNumCfg[i])
	if( (unsigned long)ConfigFile1.Value == ReallyNumCfg[i])
	 {
	 flag = 1;
	 break;	 //real number of config file
	 }

  }

   if(!flag)
   {
     ConfigFile1.Value = tmpval; //ReallyNumCfg[NamesConfigFiles.ChangingValue];
	   ConfigFile1.ChangingValue = ConfigFile1.Value;
	   printfpd("\n\rwrong config number! %d", val);

     return;
   }

  NamesConfigFiles1.Value = i;				//number of variants in menu
  NamesConfigFiles1.ChangingValue = i;
  UsedExp.State.Reg2.bit.NamesConfigFiles = 1;

  
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 




 UsedExp.State.Reg2.bit.FillCFV1 = 1;
 UsedExp.State.Reg2.bit.WriteId = 1;
 UsedExp.State.Reg2.bit.Some = 1;

//  SetMTMode();
}
 
extern "C" float GetBERE()
{
return (float)MBERE.Value;
}

extern "C" float GetBER()
{
return (float)MBER.Value;
}

extern "C" long GetNMSE()
{
return (long)NMSE;
}

extern "C" long GetLOCK()
{
return (long)LOCK; //temp
}

extern "C" void	  SetIfLoopSNMP(long val)		  //rx freq
{
MIfLoop.Value = val;
MIfLoop.ChangingValue = val;

SetMIfLoop();

UsedExp.State.Reg2.bit.MIfLoop = 1;
UsedExp.State.Reg2.bit.Some = 1;
UsedExp.State.Reg2.bit.WriteId = 1;
}

extern "C" void	  SetMUnModulSNMP(long val)		  //rx freq
{

MUnModul.Value = val;
MUnModul.ChangingValue = val;

 SetMUnModul();

UsedExp.State.Reg2.bit.MUnModul = 1;
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;

}

extern "C" void	  SetMRfOutSNMP(unsigned char val)		  //tx freq
{
MRfOut.Value = val;
MRfOut.ChangingValue = val;

UsedExp.State.Reg2.bit.MRfOut = 1;
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
 SetMRfOut();


/*
WebPassword.Value = val;
WebPassword.ChangingValue = val;
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
*/

//printfpd("\n\r par039 : %d", val);
}

#ifdef RACM

extern  "C"  long Get_MODULATOR_ACM_REQ(void)
{

 return RACMOnOffT.Value + 1;
}

extern  "C" void  Set_MODULATOR_ACM_REQ(long val)
{
printfpd("\n\r Set_MODULATOR_ACM_REQ: %d", val);

  RACMOnOffT.Value = val - 1;
   RACMOnOffT.ChangingValue = RACMOnOffT.Value;
}

extern  "C" long Get_DEMODULATOR_ACM_MODE(void)
{
  return RACMOnOff.Value + 1;
}

extern "C"  void  Set_DEMODULATOR_ACM_MODE(long val)
{

printfpd("\n\r Set_DEMODULATOR_ACM_MODE: %d", val);
   RACMOnOff.Value = val - 1;
   RACMOnOff.ChangingValue = RACMOnOff.Value;


}


extern  "C"  long Get_DEMODULATOR_ACM_OFFSET(void)
{


 return (long)(RACMOffset.Value * 10.0);
}

extern  "C"  void  Set_DEMODULATOR_ACM_OFFSET(long val)
{
   RACMOffset.Value = (float)val / 10.0;
   RACMOffset.ChangingValue = RACMOffset.Value;

}

extern  "C" long Get_DEMODULATOR_ACM_MSEI(long num )
{
  return (long)(uebn[num].Value * 10.0);
}

extern  "C" void  Set_DEMODULATOR_ACM_MSEI(long num , long val)
{
 uebn[num].Value =  (float)val / 10.0;
 uebn[num].ChangingValue = uebn[num].Value;
}

extern  "C" long Get_DEMODULATOR_ACM_MSED(long num )
{
  return (long)(debn[num].Value * 10.0);

}

extern  "C" void  Set_DEMODULATOR_ACM_MSED(long num , long val)
{
 debn[num].Value =  (float)val / 10.0;
 debn[num].ChangingValue = debn[num].Value;
}


 // enamode[15].Value = 0;     enamode[15].ChangingValue = 0;

 //  ndmode[0].Value =  0;	  ndmode[0].ChangingValue =  ndmode[0].Value;



extern  "C" long Get_DEMODULATOR_ACM_INC(long num)
{
 return (long)numode[num].Value;
}
extern  "C"  void  Set_DEMODULATOR_ACM_INC(long num, long val)
{
 numode[num].Value =  (float)val ;
 numode[num].ChangingValue = numode[num].Value;
}

extern  "C" long Get_DEMODULATOR_ACM_DEC(long num)
{
  return (long)ndmode[num].Value;

}
extern "C"  void  Set_DEMODULATOR_ACM_DEC(long num, long val)
{
  ndmode[num].Value =  (float)val ;
 ndmode[num].ChangingValue = ndmode[num].Value;


}

extern "C"  long Get_DEMODULATOR_ACM_EN(long num)
{
  return (long)enamode[num].Value + 1;

}
extern  "C" void  Set_DEMODULATOR_ACM_EN(long num , long val)
{
  enamode[num].Value =  (float)(val - 1) ;
 enamode[num].ChangingValue = enamode[num].Value;



}

//________________________________


extern "C"  long Get_DEMODULATOR_ACM_TLOCK(void)
{
  return (long)ratimelock.Value;
}

extern  "C" void Set_DEMODULATOR_ACM_TLOCK(long val)
{
ratimelock.Value = val;
ratimelock.ChangingValue =  ratimelock.Value;

}

extern  "C" long Get_DEMODULATOR_ACM_TMODE(void)
{
  return (long)ratimemode.Value;
}

extern  "C" void Set_DEMODULATOR_ACM_TMODE(long val)
{
ratimemode.Value = val;
ratimemode.ChangingValue =  ratimemode.Value;


}

extern "C"  long Get_DEMODULATOR_ACM_TMSE(void)
{
  return (long)ratimemse.Value;
}

extern "C"  void Set_DEMODULATOR_ACM_TMSE(long val)
{
   ratimemse.Value = (float)val;
   ratimemse.ChangingValue =  ratimemse.Value;  
}


extern "C"  long Get_DEMODULATOR_ACM_TSTEP(void)
{
  return (long)ratimestep.Value;
;
}

extern  "C" void Set_DEMODULATOR_ACM_TSTEP(long val)
{
   ratimestep.Value = (float)val;
   ratimestep.ChangingValue =  ratimestep.Value;  
}


//_______________________________


#endif






 
