//#include "pvg610_api.h"

extern "C" void InitStructs()
{

dev1.md100se.rezerved1 = 1;// modem 1 core

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

if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
 {

 UsedMenu.DrawMessage("SatSound Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);


 SatSound.Value = MIN_SATSOUND;
 SatSound.ChangingValue = MIN_SATSOUND;
 }



  if((LoadVariants.Value < MIN_LOADVARIANTS) || (LoadVariants.Value > MAX_LOADVARIANTS))
{
 
 UsedMenu.DrawMessage("LoadVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
   LoadVariants.Value = 0;
   LoadVariants.ChangingValue = 0;
}

  if((SaveVariants.Value < MIN_SAVEVARIANTS) || (SaveVariants.Value > MAX_SAVEVARIANTS))
{
 UsedMenu.DrawMessage("SaveVariants Is Wrong    ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 
 
   SaveVariants.Value = MIN_SAVEVARIANTS;
   SaveVariants.ChangingValue = MIN_SAVEVARIANTS;
}


  if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{

 UsedMenu.DrawMessage("Ethernet Mode Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MEthMode.Value = MIN_METHMODE;
 MEthMode.ChangingValue = MEthMode.Value; 
}


  if((MRfOut.Value < MIN_MRFOUT) || (MRfOut.Value > MAX_MRFOUT))
{

 UsedMenu.DrawMessage("RfOut  On/Off Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MRfOut.Value = MIN_MRFOUT;
 MRfOut.ChangingValue = MRfOut.Value; 
}


 // printfpdv(" MOut: % 5.3f",MOutLev.Value);
 //  printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
// printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



  if((MOutLev.Value < (float64)MIN_MOUTLEV) || (MOutLev.Value > (float64)MAX_MOUTLEV))
{
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
 UsedMenu.DrawMessage("OutLevOffs    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevO.Value = (unsigned)MAX_MOUTLEVO >> 1;
 MOutLevO.ChangingValue = MOutLevO.Value; 
}


 if((MOutLevOS.Value < (float64)MIN_MOUTLEVOS) || (MOutLevOS.Value > (float64)MAX_MOUTLEVOS))
{
  UsedMenu.DrawMessage("  OutLevOSign  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevOS.Value = (unsigned)MAX_MOUTLEVOS;
 MOutLevOS.ChangingValue = MOutLevOS.Value; 
}

 if((MKOUT.Value < (float64)MIN_MKOUT) || (MKOUT.Value > (float64)MAX_MKOUT))
{
  UsedMenu.DrawMessage("  MKOUT  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MKOUT.Value = (unsigned)MAX_MKOUT >> 1;
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
 UsedMenu.DrawMessage(" TDRate  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}


if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
 UsedMenu.DrawMessage(" RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);
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
  UsedMenu.DrawMessage(" TFreq    Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 UsedMenu.DrawMessage(" RFreq     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 UsedMenu.DrawMessage(" TModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
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
 UsedMenu.DrawMessage(" RModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
	 UsedMenu.DrawMessage(" TCdType Is Wrong    ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
 	UsedMenu.DrawMessage(" RCdType Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

		 MRCdType.Value = MIN_MRCDTYPE;
		 MRCdType.ChangingValue = MRCdType.Value;
  	}
	  
    if((MTMode.Value < MIN_MTMODE) || (MTMode.Value > MAX_MTMODE))
	{
    UsedMenu.DrawMessage(" TMode   Is Wrong        ",&theAnyStrings.cEmpty[0]);
 	 Ring(1,1,5,2);
	 	MTMode.Value = MIN_MTMODE;
 		MTMode.ChangingValue = MTMode.Value;
	}

    if((MRMode.Value < MIN_MRMODE) || (MRMode.Value > MAX_MRMODE))
	{
	 UsedMenu.DrawMessage(" RMode   Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
 	MRMode.Value = MIN_MRMODE;
 		MRMode.ChangingValue = MRMode.Value;
	}

    if((MRCntl.Value < MIN_MRCNTL) || (MRCntl.Value > MAX_MRCNTL))
	{
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
 	 UsedMenu.DrawMessage(" TCode     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
	MTCode.Value = MIN_MTCODE;
 		MTCode.ChangingValue = MTCode.Value;
   }




    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
  UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 UsedMenu.DrawMessage(" Demod On/Off  Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}

 if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{											 
  UsedMenu.DrawMessage(" EthMode   Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthMode.Value = 0;
 MEthMode.ChangingValue = MEthMode.Value;
 }

 if((MEthPause.Value < MIN_METHPAUSE) || (MEthPause.Value > MAX_METHPAUSE))
{
  UsedMenu.DrawMessage(" EthPause   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthPause.Value = 0;
 MEthPause.ChangingValue = MEthPause.Value;
}

 MEthModeI.Value = 0;
 MEthModeI.ChangingValue = MEthModeI.Value;

 if((MEthMaxF.Value < MIN_METHMAXF) || (MEthMaxF.Value > MAX_METHMAXF))
{
  UsedMenu.DrawMessage(" EthMaxF    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 
 MEthMaxF.Value = MAX_METHMAXF;
 MEthMaxF.ChangingValue = MEthMaxF.Value;
}

 if((MEthVlanP.Value < MIN_METHVLANP) || (MEthVlanP.Value > MAX_METHVLANP))
{

  UsedMenu.DrawMessage(" EthVlanP    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MEthVlanP.Value = MIN_METHVLANP;
 MEthVlanP.ChangingValue = MEthVlanP.Value;
}


MEbN0.Value = 10.1;

 if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
 UsedMenu.DrawMessage(" TEbN0    Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTEbN0.Value = MIN_MTEBN0;
MTEbN0.ChangingValue = MTEbN0.Value;
}


MBER.Value = (float)0.0;
MBERE.Value = MIN_MTBERE;	//e-10
MBERE.ChangingValue = MTBERE.Value;


 if((MTBER.Value < MIN_MTBER) || (MTBER.Value > MAX_MTBER))
{
 UsedMenu.DrawMessage(" TBER      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value <  (float)MIN_MTBERE) || (MTBERE.Value >  (float)MAX_MTBERE))
{
 UsedMenu.DrawMessage(" TBERE     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBERE.Value =  (float)MIN_MTBERE;	//e-10
MTBERE.ChangingValue = MTBERE.Value;
}

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
  UsedMenu.DrawMessage(" Ethctl     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthctl.Value = MIN_METHCTL;
 MEthctl.ChangingValue = MEthctl.Value;
}

 if((MIfLoop.Value < MIN_MIFLOOP) || (MIfLoop.Value > MAX_MIFLOOP))
{
  UsedMenu.DrawMessage(" IfLoop    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MIfLoop.Value = MIN_MIFLOOP;
 MIfLoop.ChangingValue = MIfLoop.Value;
}


 if((MUnModul.Value < MIN_MUNMODUL) || (MUnModul.Value > MAX_MUNMODUL))
{
 UsedMenu.DrawMessage(" UnModul    Is Wrong     ",&theAnyStrings.cEmpty[0]); 
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
 UsedMenu.DrawMessage("RfOut  On/Off Is Wrong  ",&theAnyStrings.cEmpty[0]);
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
 UsedMenu.DrawMessage(" TDRate  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}


if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
 ret = 0;
 UsedMenu.DrawMessage(" RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);
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
  UsedMenu.DrawMessage(" TFreq    Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 ret = 0;
 UsedMenu.DrawMessage(" RFreq     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 ret = 0;
 UsedMenu.DrawMessage(" TModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
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
 UsedMenu.DrawMessage(" RModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
 ret = 0;
	 UsedMenu.DrawMessage(" TCdType Is Wrong    ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
 ret = 0;
 	UsedMenu.DrawMessage(" RCdType Is Wrong       ",&theAnyStrings.cEmpty[0]);
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
 UsedMenu.DrawMessage(" Demod On/Off  Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}

 if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{	
 ret = 0;										 
  UsedMenu.DrawMessage(" EthMode   Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthMode.Value = 0;
 MEthMode.ChangingValue = MEthMode.Value;
 }

 if((MEthPause.Value < MIN_METHPAUSE) || (MEthPause.Value > MAX_METHPAUSE))
{
 ret = 0;
  UsedMenu.DrawMessage(" EthPause   Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthPause.Value = 0;
 MEthPause.ChangingValue = MEthPause.Value;
}

 MEthModeI.Value = 0;
 MEthModeI.ChangingValue = MEthModeI.Value;

 if((MEthMaxF.Value < MIN_METHMAXF) || (MEthMaxF.Value > MAX_METHMAXF))
{
 ret = 0;
  UsedMenu.DrawMessage(" EthMaxF    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 
 MEthMaxF.Value = MIN_METHMAXF;
 MEthMaxF.ChangingValue = MEthMaxF.Value;
}

 if((MEthVlanP.Value < MIN_METHVLANP) || (MEthVlanP.Value > MAX_METHVLANP))
{
 ret = 0;

  UsedMenu.DrawMessage(" EthVlanP    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MEthVlanP.Value = MIN_METHVLANP;
 MEthVlanP.ChangingValue = MEthVlanP.Value;
}


MEbN0.Value = 10.1;

 if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
 ret = 0;
 UsedMenu.DrawMessage(" TEbN0    Is Wrong       ",&theAnyStrings.cEmpty[0]);
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
 UsedMenu.DrawMessage(" TBER      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value <  (float)MIN_MTBERE) || (MTBERE.Value >  (float)MAX_MTBERE))
{
 ret = 0;
 UsedMenu.DrawMessage(" TBERE     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBERE.Value =  (float)MIN_MTBERE;	//e-10
MTBERE.ChangingValue = MTBERE.Value;
}



 if((MEthctl.Value < MIN_METHCTL) || (MEthctl.Value > MAX_METHCTL))
{
 ret = 0;
  UsedMenu.DrawMessage(" Ethctl     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MEthctl.Value = MIN_METHCTL;
 MEthctl.ChangingValue = MEthctl.Value;
}

 if((MIfLoop.Value < MIN_MIFLOOP) || (MIfLoop.Value > MAX_MIFLOOP))
{
 ret = 0;
  UsedMenu.DrawMessage(" IfLoop    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MIfLoop.Value = MIN_MIFLOOP;
 MIfLoop.ChangingValue = MIfLoop.Value;
}


 if((MUnModul.Value < MIN_MUNMODUL) || (MUnModul.Value > MAX_MUNMODUL))
{
 ret = 0;
 UsedMenu.DrawMessage(" UnModul    Is Wrong     ",&theAnyStrings.cEmpty[0]); 
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
  UsedMenu.DrawMessage(" ACM Mode    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
// MACMM.Value = MIN_MACMM;
 //MACMM.ChangingValue = MACMM.Value;
}
}
else if((MACMM.Value != MAX_MACMM))
{
 // printfpd("\n\r __acm : %d", MACMM.Value);

 ret = 0;
  UsedMenu.DrawMessage(" ACM Mode    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 //MACMM.Value = MAX_MACMM;
 //MACMM.ChangingValue = MACMM.Value;


}






 return ret;

}







//______________________________________________
extern "C" void CheckParametersTx()
{

 // UsedMenu.DrawMessage("     Check Parameters    ",&theAnyStrings.cEmpty[0]);
 // Ring(1,1,5,2);

 //dev1.md100se.ConfigFile = ConfigFile.Value;   //t

 if((MRateE.Value < MIN_MRATEE) || (MRateE.Value > MAX_MRATEE))
{
 UsedMenu.DrawMessage(" MRateE    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRateE.Value = MIN_MRATEE;
 MRateE.ChangingValue = MRateE.Value;
}


  if((MEthMode.Value < MIN_METHMODE) || (MEthMode.Value > MAX_METHMODE))
{

 UsedMenu.DrawMessage("Ethernet Mode Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MEthMode.Value = MIN_METHMODE;
 MEthMode.ChangingValue = MEthMode.Value; 
}


  if((MRfOut.Value < MIN_MRFOUT) || (MRfOut.Value > MAX_MRFOUT))
{

 UsedMenu.DrawMessage("RfOut  On/Off Is Wrong  ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MRfOut.Value = MIN_MRFOUT;
 MRfOut.ChangingValue = MRfOut.Value; 
}


 // printfpdv(" MOut: % 5.3f",MOutLev.Value);
 //  printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
// printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



  if((MOutLev.Value < (float64)MIN_MOUTLEV) || (MOutLev.Value > (float64)MAX_MOUTLEV))
{
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
 UsedMenu.DrawMessage("OutLevOffs    Is Wrong   ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevO.Value = 0;
 MOutLevO.ChangingValue = MOutLevO.Value; 
}


 if((MOutLevOS.Value < (float64)MIN_MOUTLEVOS) || (MOutLevOS.Value > (float64)MAX_MOUTLEVOS))
{
  UsedMenu.DrawMessage("  OutLevOSign  Is Wrong ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

//printfp("\n\r wrong MOutLev ");
 MOutLevOS.Value = 0;
 MOutLevOS.ChangingValue = MOutLevOS.Value; 
}

  
if((MTDRate.Value < MIN_MTDRATE) || (MTDRate.Value > MAX_MTDRATE))
{
 UsedMenu.DrawMessage(" TDRate  Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTDRate.Value = MAX_MTDRATE;
 MTDRate.ChangingValue = MTDRate.Value; 
}


 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 

  if((MTFreq.Value < MIN_MTFREQ) || (MTFreq.Value > MAX_MTFREQ))
{
  UsedMenu.DrawMessage(" TFreq    Is Wrong      ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTFreq.Value = MIN_MTFREQ;
 MTFreq.ChangingValue = MTFreq.Value; 
 }

  

 if((MTModul.Value < MIN_MTMODUL) || (MTModul.Value > MAX_MTMODUL))
{
 UsedMenu.DrawMessage(" TModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MTModul.Value = MIN_MTMODUL;
 MTModul.ChangingValue = MTModul.Value;
}

  


    if((MTCdType.Value < MIN_MTCDTYPE) || (MTCdType.Value > MAX_MTCDTYPE))
	{
	 UsedMenu.DrawMessage(" TCdType Is Wrong    ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

	 	MTCdType.Value = MIN_MTCDTYPE;
 		MTCdType.ChangingValue = MTCdType.Value;
	}

    if((MTMode.Value < MIN_MTMODE) || (MTMode.Value > MAX_MTMODE))
	{
    UsedMenu.DrawMessage(" TMode   Is Wrong        ",&theAnyStrings.cEmpty[0]);
 	 Ring(1,1,5,2);
	 	MTMode.Value = MIN_MTMODE;
 		MTMode.ChangingValue = MTMode.Value;
	}


  //	printfpd("\n\r mrnctl : %d", MRCntl.Value);





    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
  UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 UsedMenu.DrawMessage(" Demod On/Off  Is Wrong     ",&theAnyStrings.cEmpty[0]);
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


if((MRDRate.Value < MIN_MRDRATE) || (MRDRate.Value > MAX_MRDRATE))
{
 UsedMenu.DrawMessage(" RDRate    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 //printfpdv("\n\r RDRate: % 5.3f",MRDRate.Value);	//is zero
 // printfpdv(" minMOut: % 5.3f",(float64)MIN_MOUTLEV);
 //printfpdv(" maxMOut: % 5.3f",(float64)MAX_MOUTLEV);



 MRDRate.Value = MAX_MRDRATE;
 MRDRate.ChangingValue = MRDRate.Value; 
}
 

 //MRDRate.Value = 98.0002;
 //MRDRate.ChangingValue = MRDRate.Value; 


  if((MRFreq.Value < MIN_MRFREQ) || (MRFreq.Value > MAX_MRFREQ))
{
 UsedMenu.DrawMessage(" RFreq     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRFreq.Value = MAX_MRFREQ;
 MRFreq.ChangingValue = MRFreq.Value; 
}
   


 if((MRModul.Value < MIN_MRMODUL) || (MRModul.Value > MAX_MRMODUL))
{
 UsedMenu.DrawMessage(" RModul    Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);

 MRModul.Value = MIN_MRMODUL;
 MRModul.ChangingValue = MRModul.Value;
}
   


    if((MRCdType.Value < MIN_MRCDTYPE) || (MRCdType.Value > MAX_MRCDTYPE))
	{
 	UsedMenu.DrawMessage(" RCdType Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);

		 MRCdType.Value = MIN_MRCDTYPE;
		 MRCdType.ChangingValue = MRCdType.Value;
  	}

    if((MRMode.Value < MIN_MRMODE) || (MRMode.Value > MAX_MRMODE))
	{
	 UsedMenu.DrawMessage(" RMode   Is Wrong       ",&theAnyStrings.cEmpty[0]);
  	Ring(1,1,5,2);
 	MRMode.Value = MIN_MRMODE;
 		MRMode.ChangingValue = MRMode.Value;
	}

 

 //MRModul.Value = 0;




    if((MRCode.Value < MIN_MRCODE) || (MRCode.Value > MAX_MRCODE))
	{
  UsedMenu.DrawMessage(" RCode      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
		MRCode.Value = MIN_MRCODE;
 		MRCode.ChangingValue = MRCode.Value;
   }





  if((MDemod.Value < MIN_MDEMOD) || (MDemod.Value > MAX_MDEMOD))
{
 UsedMenu.DrawMessage(" Demod On/Off  Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
 MDemod.Value = 0;
 MDemod.ChangingValue = MDemod.Value;
}



  if((MTEbN0.Value < MIN_MTEBN0) || (MTEbN0.Value > MAX_MTEBN0))
{
 UsedMenu.DrawMessage(" TEbN0    Is Wrong       ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTEbN0.Value = MIN_MTEBN0;
MTEbN0.ChangingValue = MTEbN0.Value;
}


 if((MTBER.Value < MIN_MTBER) || (MTBER.Value > MAX_MTBER))
{
 UsedMenu.DrawMessage(" TBER      Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBER.Value = (float)MIN_MTBER;	//e-8
MTBER.ChangingValue = MTBER.Value;
}

 if((MTBERE.Value <  (float)MIN_MTBERE) || (MTBERE.Value >  (float)MAX_MTBERE))
{
 UsedMenu.DrawMessage(" TBERE     Is Wrong     ",&theAnyStrings.cEmpty[0]);
  Ring(1,1,5,2);
MTBERE.Value =  (float)MIN_MTBERE;	//e-10
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
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
// char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];
 unsigned char ByteBuff;
 unsigned char ByteBuff1;

  for(unsigned i = 0; i < XilSizeToDownloadD; i++)	 //need header only
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
 delay_mcs(10000);
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
char Buf1[4];

outportb(ADR_IFSAT140,MEM);
  delay_mcs(50);
  outportb(ADR_IFSAT140,MEM);



Buf[0] = '1';
Buf[1] = '2';
Buf[2] = '3';
Buf[3] = 0;


 /*
for(unsigned j = 0; j < IFModuleDataSize; j++)
{
Buf[j] =j + 0x30;
}
 */

Buf1[0] = '9';
Buf1[1] = '8';
Buf1[2] = '7';
Buf1[3] = 0;

 AT91F_DataflashInitx();  //for test
delay_mcs(50);
 WriteDataIFModule(0 + CFG_DATAFLASH_LOGIC_ADDR_CS1X, Buf, 4);

// WriteDataIFModule((unsigned long)(IFCONF_ADDRESS), Buf,  (unsigned)IFModuleDataSize);

//return; //t1411107
delay_mcs(50);

// ReadDataIFModule((unsigned long)(IFCONF_ADDRESS),  (char *)&TFTP_Buffer1[0],  (unsigned)IFModuleDataSize);

ReadDataIFModule(0 + CFG_DATAFLASH_LOGIC_ADDR_CS1X, Buf1, 4);

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
	 delay_mcs(100);
     CON_IFSAT140 |= _IFNRST;   //inverse operation	 : reset off
	 outportb(CON_IFSAT140_ADDR,CON_IFSAT140);

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

 if(MRfOut.Value)
 {
 CON_IFSAT140 |= IFTXON;

 dev1.md100se.MRfOut =1;
 }
 else
 {
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



extern "C" void SetMOutLev()
{

//printfp("\n\rSetMOutLev");

//MOutLev.Value =  ((dev1.md100se.MOutLev1 << 8)	+ dev1.md100se.MOutLev0) *(-1) / 10;
//MOutLev.ChangingValue = MOutLev.Value;

//signed long tmp =  ((MOutLev.Value *  (-100)   +  MOutLevOS.Value * MOutLevO.Value *  (-100)   + POWER_START) * POWER_K) / 1000;

//signed long tmp =  ((443  + MOutLev.Value *  (-10) +   MOutLevOS.Value * MOutLevO.Value *  (-10)   ) * 676) / 100;
//signed long tmp =  ((443  + MOutLev.Value *  (-10) +   MOutLevOS.Value * MOutLevO.Value *  (-10)   ) * MKOUT.Value) / 100;
//141208 signed long tmp =  (signed long)(((MOutLevO.Value - MOutLev.Value) * MKOUT.Value) / (float64)10);
signed long sign = 	MOutLevOS.Value ? -1 : 1;

signed long tmp =
 (signed long)(((sign * MOutLevO.Value * MOutLev.Value * MOutLev.Value)/(float)10) 
  -	(signed long)(MKOUT.Value * MOutLev.Value)	+ (signed long)(MKOUT1.Value * 10));

//printfpd("\n\rMOutLev code : 0x%x ", tmp);
//printfpd(" MOutLevO.Value *10 : %d ", MOutLevO.Value * 10);
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
extern "C" void FillMTModulV()
{

char *pMT = &theAnyStrings.cMTModeV[2];
char *pMd;
unsigned long i, j;

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
   pMT += 2;
  }
  else
  {
   pMT += 8;
  }


}



}

extern "C" void SetParamsFromCfg()
{
 unsigned char quantity; 

// printfp("\n\r Setparamsfromcfg");
//  MTCode.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate0 +
//				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate1 << 8)) / 1000; 	
 /*
  MTCode.Value =   ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].coderate3 << 24) ) / 1000; 	

	  
  //_________ok
  MTCode.ChangingValue = MTCode.Value; 
 
 
 
 // SetMTCode();
  MRCode.Value =  MTCode.Value;
  MRCode.ChangingValue = MRCode.Value;
 // SetMRCode();
		

//ok
  MTModul.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].mode;
// printfpd("\n\r modul = %d", MTModul.Value);

  MTModul.ChangingValue = MTModul.Value;
 // SetMTModul();

  MRModul.Value = MTModul.Value; 
  MRModul.ChangingValue = MRModul.Value;
 // SetMRModul();
	 */
  
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

	
	
  FillMTModulV();


  MTDRate.Value =  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / 1000000; 	

 		 
  MTDRate.ChangingValue = MTDRate.Value;
//  SetMTDRate();




 //printfpdv("\n\rbefore from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero


  MRDRate.Value = MTDRate.Value; 
  MRDRate.ChangingValue = MRDRate.Value;
//  SetMRDRate();

 //   printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0);
  //  printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1);
  //  printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2);
  //  printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3);
  //  printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero

	/*  
  MTCdType.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].code_type;
  MTCdType.ChangingValue = MTCdType.Value;
 // SetMTCdType();

  MRCdType.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[0].code_type;
  MRCdType.ChangingValue = MRCdType.Value;
	*/
  acm_status = modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.acm_status;
  //  acm_status = 1; //for test


 SetParamsRxFromCfg(MTMode.Value);
 SetParamsTxFromCfg(MTMode.Value);



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
   SetMRDRate();
 //  SetMTCdType();
  // SetMRCdType();
 //  SetMACMM();	 //in final
  // SetMRfOut();   //last	//need close before changing  	   in final

SetMEthPause1();
SetMEthctl1();
SetMEthMaxF();
SetMEthVlanP1();
   
InitEthStat();




}

extern "C" void SetParamsTxFromCfg(unsigned char p)
{
 //printfp("\n\r SetparamsTxfromcfg");

 
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





   CheckParametersTx();

   SetMTCode();
   SetMTDRate();
   SetMTModul();
   SetMTCdType();
   SetMTCode();
   SetMRateE();

// if(!hot_restart)
//  {
//  SetGEth(0, (unsigned)MRateE.Value);
//  }
		  
//SetMEthPause1();
//SetMEthctl1();
//SetMEthMaxF();
//SetMEthVlanP1();
   
//InitEthStat();

  
}

extern "C" void SetParamsRxFromCfg(unsigned char p)
{

//printfp("\n\r SetparamsRxfromcfg");
   dev1.md100se.MRMode =  p;

 
  MRCode.Value =   (float64)((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].coderate3 << 24) ) / (float64)1000; 	
  MRCode.ChangingValue = MRCode.Value;
 // SetMRCode();


  MRModul.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].mode;
  MRModul.ChangingValue = MRModul.Value;
 // SetMRModul();

  // printfpd("rx  modul = %d", MRModul.Value);


 // printfpd("\n\ratesymb0: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0);
 // printfpd("  ratesymb1: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1);
 // printfpd("  ratesymb2: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2);
 // printfpd("  ratesymb3: 0x%X",(unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3);
  //  printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//is zero



  MRDRate.Value =  (float64)((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol0 +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol1 << 8) +
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol2 << 16)	+
				  ((unsigned)modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.rateSymbol3 << 24) ) / (float64)1000000; 	
   //	 printfpdv("\n\rafter from cfg : RDRate: % 5.3f",MRDRate.Value);	//


  MRDRate.ChangingValue = MRDRate.Value;
//  SetMRDRate();
	  

  MRCdType.Value =  modemp[0].configfilefext.ConfigTxtData.emb4md15504cfg.mode15504[p].code_type;
  MRCdType.ChangingValue = MRCdType.Value;
 // SetMRCdType();
//  SetMTDRate();

    CheckParametersRx();
	SetMRCode();
   SetMRModul();
    SetMRDRate();
	 SetMRCdType();

  
}






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
// printfp("\n\r SetMTMode()");

 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
 //SetACMMask(0,  (1 << MTMode.Value));


  dev1.md100se.MTMode =  MTMode.Value;
	  
  SetParamsTxFromCfg(MTMode.Value);
  // SetParamsRxFromCfg(MTMode.Value);   //for check
	

//141121 MRMode.Value =  MTMode.Value;
 //141121MRMode.ChangingValue = MRMode.Value;
 //dev1.md100se.MRMode =  MRMode.Value;
  //SetParamsRxFromCfg(MRMode.Value);
 //PVG610_API_ModemAcmProfileEnable( 0, 0,  (1 << (unsigned)MTMode.Value));
  SetMACMM();	 //to send commands

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
#ifdef PRINT_ETH
 printfp("\n\rSetMEthMode()");
 
 printfpd(" %X",  (unsigned char)MEthMode.Value);

#endif


// printfp("\n\rSetMEthMode");
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
 case 5 :  mod |= ETH_1000;	    			 break;
 default : mod |= ETH_AUTO;   
 }

 #ifdef PRINT_ETH
  printfp("\n\rSetMEthMode()");
printfpd(" ethmode : %d", (unsigned char)MEthMode.Valu);

 printfpd("  mod : %d", mod);
#endif




 SetModEth(mod);
 StartEth(1);
}

extern "C" void SetMEthPause()
{
  // PVG610_API_EthernetPauseSet(0,0,	(unsigned char)MEthPause.Value);
   dev1.md100se.MEthPause = (unsigned char)MEthPause.Value;
}

extern "C" void SetMEthPause1()
{

//printfp("\n\r SetMEthPause1 \n\r");

   PVG610_API_EthernetPauseSet(0,0,	(unsigned char)MEthPause.Value);
   dev1.md100se.MEthPause = (unsigned char)MEthPause.Value;
}


extern "C" void SetMEthctl()
{
 //PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthctl.Value);

//PVG610_API_EthernetInBandControlSet(0,0, (unsigned char)MEthctl.Value);
  dev1.md100se.MEthctl = (unsigned char)MEthctl.Value;
}

extern "C" void SetMEthctl1()
{
 //PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthctl.Value);

PVG610_API_EthernetInBandControlSet(0,0, (unsigned char)MEthctl.Value);
  dev1.md100se.MEthctl = (unsigned char)MEthctl.Value;
}

extern "C" unsigned short GetMEthMaxF()
{
   return (unsigned short)MEthMaxF.Value;
}


extern "C" void SetMEthMaxF()
{

unsigned long tmp =  MEthMaxF.Value;


PVG610_API_EthernetLargeFrameSet (0,0,(UINT16)MEthMaxF.Value);
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
 PVG610_API_EthernetVlanSet(0,0, (unsigned char)MEthVlanP.Value);
 dev1.md100se.MEthVlanP = (unsigned char)MEthVlanP.Value;

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



extern "C" void SetMAGC(signed short agc)
{

float agc1 = agc;

//printfpd("\n\ragc : %d", agc1);

//printfpd("\n\ragc1 : %d", 0.4167 * agc1 * agc1 * agc1);
//printfpd("\n\ragc2 : %d", 5.5357 * agc1 * agc1);


//MAGC.Value = (float64)agc;

//MAGC.Value = (0.000006 * agc1 * agc1) - ( 0.0428 * agc1) + 29.068;
//141208 MAGC.Value = (-0.00001 * agc1 * agc1) - ( 0.0107 * agc1) + 6.1718;
	  
MAGC.Value =
 (float64)(( MKIN1.Value * agc1 * agc1) / (float64)1000000) 
  -	(float64)(MKIN2.Value * agc1 / (float64)1000) + (float64)(MKIN3.Value / (float64)100);
	 /*
	printfpdv("\n\ragc1: %8.3f", agc1);
	printfpdv(" MKIN1: %8.3f",MKIN1.Value);
	printfpdv(" MKIN2: %8.3f",MKIN2.Value);
	printfpdv(" MKIN3: %8.3f",MKIN3.Value);
	printfpdv("\n\rinp: %8.3f",MAGC.Value);

	*/

dev1.md100se.MAGC0 = (unsigned)MAGC.Value 		 & 0xff;
dev1.md100se.MAGC1 = ((unsigned)MAGC.Value >> 8)  & 0xff;


if(MAGC.Value < -45)
{
MAGC.Value =  (unsigned)MAGIC_VAL1;
}

//printfpd("\n\MAGC.Value : %d", (signed short)MAGC.Value);

MAGC.ChangingValue = MAGC.Value;

// printfpdv("\n\r%15.8f",(float64 )MAGC.ChangingValue );


//dev1.md100se.MAGC0 = agc 		 & 0xff;
//dev1.md100se.MAGC1 = (agc >> 8)  & 0xff;
}


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
		 	 printfpd("(my_log :Argument is wrong ):%f", x);
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

  //	  x *= -1.0;

    return my_exp(2.303 * my_log(x) * y);	 //lnx = 2.303 * logx
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



}

   
extern "C" void SetMEbN(signed short ebn)
{
//printfp("\r\n SetMEbN"); 
//double ebn1 = -0.01 * ebn;
ebn *= -1;

            
//printfpdv("\rebn1: %8.4f ", ebn1);	 //-450

//float64  tmp = 10 * ( log((10^(ebn/10))  - 1) -  log(MRCode.Value)) ; //temp
//float64  tmp = 10 * ( my_log((10^(ebn/10))  - 1) -  my_log(MRCode.Value)) ; //temp
//float64  tmp = 10 * ( my_log((pow((double)10,ebn1))  - 1) -  my_log(MRCode.Value)) ; //temp
//float64  tmp = 10 * (ebn1 -  my_log(MRCode.Value)) ; //temp

//float64  tmp = 10 * ( my_log(pow(10,(ebn/100))  - 1) -  my_log(MRCode.Value)) ; //temp

float64  tmp = 10 * ((float64)my_log((double)my_pow(10,(ebn/(-100.0)))  - 1) -  (float64)my_log((double)MRCode.Value)) ; //temp

//printfpdv(" log1:%8.4f", my_log((pow((double)10,ebn1))  - 1));
//printfpdv(" pow:%8.4f", pow((double)10,ebn1));

//printfpdv(" log3:%8.4f", my_log(pow((double)10,ebn1)));


//printfpdv(" MRCode.Value:%8.4f", MRCode.Value);	  //0,7
//printfpdv(" log2:%8.4f", (float)my_log((float)MRCode.Value));


//printfpdv("tmp:%8.4f", tmp);
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
 default :  MEbN0.Value = (float64)(tmp - 3.0)/(float64)1.0; break;  //QPSK
}
  
//MEbN0.ChangingValue = MEbN0.Value; 

 //  printfpdv(" MEbN0: %8.4f", MEbN0.Value);

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
		 Ring(1,1,5,4);
	  //		printfp("\n\r ebn0 ring! \n\r");
		 }
 		}



dev1.md100se.MEbN00 = (unsigned)(MEbN0.Value *10) 		 & 0xff;
dev1.md100se.MEbN01 = ((unsigned)(MEbN0.Value *10) >> 8)  & 0xff;
}


#ifndef FEC_BER
extern "C" void SetMBER(unsigned long notused, unsigned long data)
#else
extern "C" void SetMBER(unsigned long alldata, unsigned long data)
#endif

{

unsigned uber;


//data = 0xffffl; //for test 

 
 //errf += err;
// dataf += data;

 float64 tber = 0.0;


if(!modemp[0].acquireStatus)   //not in lock
{
  // data	= 0xFFFFFFFFl; //all errors
   data	= 0x7FFFFFFFl; //all errors
}

 if(data)
 {
#ifndef FEC_BER
 tber = (float64)data/(float64)0xFFFFFFFF;
#else
 tber = (float64)data/(float64)alldata;
#endif
 }

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
// else
// {
//   stepber = 99;
// }


   
//MBER.Value = ber;
//MEbN0.ChangingValue = MEbN0.Value; 

uber = (unsigned)(tber * 10); 

MBER.Value = tber;


if(SatSound.Value)
 		{

	  //	printfpdv("\n\rpow> %e ",pow(10, (-1* MTBERE.Value)));
		 if(MBER.Value > (MTBER.Value * pow(10, (-1* MTBERE.Value))))
		 {
	 //temp	 Ring(1,1,5,4);
	//		printfp("\n\r ber ring! \n\r");
		 }
 		}


dev1.md100se.MBER0 = uber 		 & 0xff;
dev1.md100se.MBER1 = (uber >> 8)  & 0xff;
	
MBERE.Value =  (double)stepber;	//do not used
MBERE.ChangingValue = MBERE.Value;

dev1.md100se.MBERE = stepber; 

//printfpdv("\n\r%15.8f",(float64 )MBER.Value );

//printfpd("\n\r step ber : %d", stepber);
   
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
 
  MEthSend.Value = 0;
  MEthSendU.Value = 0;
  MEthReceived.Value = 0;
  MEthTransmit.Value = 0l;

  MEthReceivedCRC.Value = 0;
  MEthRcvD.Value = 0l;


//  return; //t
		 
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

// return;
			   
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

  MEthSend.Value = lows;
	  

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

  MEthSendU.Value = lows;
	  

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

  MEthRcvD.Value = lows;
	  

}



extern "C" void SetMEthReceived(unsigned long lowr)//, unsigned long highr)
{
 //ethreceived += (double)lowr;//  + ((double)highr *(2 ^ 32));
	 
   dev1.md100se.MEthReceived0  = lowr;
   dev1.md100se.MEthReceived1  = lowr >> 8;
   dev1.md100se.MEthReceived2  = lowr >> 16;
   dev1.md100se.MEthReceived3  = lowr >> 24;


//   dev1.md100se.MEthReceivedH0  = highr;
//   dev1.md100se.MEthReceivedH1  = highr >> 8;
//   dev1.md100se.MEthReceivedH2  = highr >> 16;
//   dev1.md100se.MEthReceivedH3  = highr >> 24;
  
  MEthReceived.Value = lowr;
   
}

extern "C" void SetMEthTransmit(unsigned long lowr)//, unsigned long highr)
{
 //ethreceived += (double)lowr;//  + ((double)highr *(2 ^ 32));
 
//   dev1.md100se.MEthReceivedH0  = highr;
//   dev1.md100se.MEthReceivedH1  = highr >> 8;
//   dev1.md100se.MEthReceivedH2  = highr >> 16;
//   dev1.md100se.MEthReceivedH3  = highr >> 24;
  
  MEthTransmit.Value = lowr;
   
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
  
  MEthReceivedCRC.Value = lowr;
   
}

 


  

extern "C" void SetMTBERE()
{



  dev1.md100se.MTBERE = MTBERE.Value;
}



extern "C" void SetMACMM()
{
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
// MACMMI.Value =	 1;//0;
// MACMMI.ChangingValue = 1;//0;

   //	  printfp(" set ones \n\r");


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
    PVG610_API_ModemAcmEngineEnable(0,0,1,0);
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

	 MACMMI.Value =	 1;
     MACMMI.ChangingValue = 1;



   //  PVG610_API_ModemAcmEngineEnable(0,0,1,1);

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
	MACMMI.Value =	 0;
    MACMMI.ChangingValue = 0;


   }


 }

dev1.md100se.MACMM = MACMM.Value;

}





extern "C" void FillClassesM()
{
 return; //t150224

 unsigned char tmp;


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


MEthMode.Value = dev1.md100se.MEthMode;

MEthMode.ChangingValue =MEthMode.Value;
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
StartEthTimed(0); //ModEth
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
//SetMEthVlanP();
SetMTEbN0();
SetMTBER();
SetMTBERE();
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

 // 	printfpd(" %c", *pBuff);
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

sprintf(&IFmoduleData.Value[20], "%03d", (signed int)MKIN1.ChangingValue);
IFmoduleData.Value[23] = '\n';
IFmoduleData.Value[24] = '\r';

sprintf(&IFmoduleData.Value[25], "%03d", (signed int)MKIN2.ChangingValue);
IFmoduleData.Value[28] = '\n';
IFmoduleData.Value[29] = '\r';
sprintf(&IFmoduleData.Value[30], "%03d", (signed int)MKIN3.ChangingValue);
IFmoduleData.Value[33] = '\n';
IFmoduleData.Value[34] = '\r';

sprintf(&IFmoduleData.Value[35], "%d", MOutLevOS.ChangingValue);
IFmoduleData.Value[36] = '\n';
IFmoduleData.Value[37] = '\r';


  //	printfpd("\n\r MOutLevOS cv:  %d",MOutLevOS.ChangingValue);
  //	printfpd("v :  %d",MOutLevOS.Value);



//for(unsigned i = 0; i < 37; i++)
  //	{
 //	if(!(i%16))	  printfp("\n\r>");

  //	printfpd(" %c",IFmoduleData.Value[i]);
   //	}


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

extern "C" double GetMEbN0(void)
{
return (double)MEbN0.Value;
}


extern "C" double GetMBERE(void)
{
return (double)MBERE.Value;
}

extern "C" double GetMBER(void)
{
return (double)MBER.Value;

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
  return MTModul.pResultStr;
}

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
return (double)MEthSend.Value;
}

extern "C" double GetMEthReceived(void)
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


extern "C" char*  GetLogStr0()
{
 return (LogStr0.Value);
}

extern "C" char*  GetLogStr1()
{
 return (LogStr1.Value);
}

extern "C" uchar GetMIfLoop()
{
   return (uchar)(MIfLoop.Value);

}
