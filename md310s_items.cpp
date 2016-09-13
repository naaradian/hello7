
MDataV	NamesConfigFiles;

MDataV LoadVariants;
MDataV SaveVariants;

MDataS AnyConfig;	 //working anyconfig
MDataS RAnyConfig;	//for reading to pc only


MDataV CurReadedAnyCofig; //number of readed anyconfig to set this variable - filled readanyconfig for reading

MDataS RAnyConfig1;
MDataS RAnyConfig2;
MDataS RAnyConfig3;

MDataS RAnyConfig4;
MDataS RAnyConfig5;
MDataS RAnyConfig6;
MDataS RAnyConfig7;
MDataS RAnyConfig8;
MDataS RAnyConfig9;



//____________________________________________________________________________

MDataV MRfOut;
MDataC MOutLev;
MDataC MOutLev1;
MDataC MOutLev2;

MDataC MOutLevO;
MDataV MOutLevOS;	 //sign



MDataC MTDRate;
MDataC MRDRate;

MDataC MTFreq;
MDataC MRFreq;


MDataV MTModul;
MDataV MRModul;

/*
MDataV MTCode;
MDataV MRCode;
*/

MDataC MTCode;
MDataC MRCode;

MDataV MDemod;

MDataV MEthMode;
MDataV MEthPause;
MDataV MEthctl;
MDataC MEthMaxF;
MDataC MEthVlanP;

MDataI MEbN0;

//MDataI MTEbN0;
MDataC MTEbN0;

MDataI MBER;
MDataC MBERE;

//MDataI MTBER;
MDataC MTBER;

MDataC MTBERE;


/*
MDataI MAGC;
MDataI MSweep;
*/

MDataC MAGC;
MDataC MSweep;


MDataV MEthModeI;	  //indikation
MDataI MEthSend;	  //dones
MDataI MEthReceived;	//dones

MDataI MEthTransmit;

MDataI MEthSendU;

MDataI MEthRcvD;
MDataI MEthReceivedCRC;




MDataV MIfLoop;
MDataV MUnModul;

MDataV MACMM;

MDataS	IFmoduleData;

MDataS	IFmoduleHeader;

MDataV MTCdType;
MDataV MRCdType;

MDataV MTMode;
MDataV MRMode;

MDataV MRCntl;

MDataC MKOUT;
MDataC MRateE;

MDataC MKOUT1;
MDataC MKIN1;
MDataC MKIN2;
MDataC MKIN3;

MDataV	SatSound;

MDataV	SClear;
Item  SClearItem;










void FillConfig(unsigned char num)
{
/* it was 140930
sprintf(
		(char *)&AnyConfig.Value,
		"num = %3d\r\n"
		"IP =%8X\r\n",
		num,
		(unsigned long)IPAddress.Value
	   	);

*/

sprintf(
		(char *)&AnyConfig.Value,
		"num%3d\r\n"
	//	"IP =%8X\r\n"
		"CF%02X\r\n"
		"ME%02X\r\n"
		"Rf%02X\r\n"
		"O0%02X\r\n"
		"O1%02X\r\n"
		"t0%02X\r\n"
		"t1%02X\r\n"
		"t2%02X\r\n"
		"t3%02X\r\n"
		"r0%02X\r\n"
		"r1%02X\r\n"
		"r2%02X\r\n"
		"r3%02X\r\n"
		"dm%02X\r\n"
		"em%02X\r\n"
		"ep%02X\r\n"
		"ec%02X\r\n"
		"f0%02X\r\n"
		"f1%02X\r\n"
		"vp%02X\r\n"
		"e0%02X\r\n"
		"e1%02X\r\n"
		"b0%02X\r\n"
		"b1%02X\r\n"
		"be%02X\r\n"
		"il%02X\r\n"
		"um%02X\r\n"
		"ac%02X\r\n"
		,
		num,
	//	(unsigned long)IPAddress.Value,
		dev1.md100se.ConfigFile,
		dev1.md100se.MEthMode,
		dev1.md100se.MRfOut,
		dev1.md100se.MOutLev0,
		dev1.md100se.MOutLev1,
		dev1.md100se.MTFreq0,
		dev1.md100se.MTFreq1,
		dev1.md100se.MTFreq2,
		dev1.md100se.MTFreq3,
		dev1.md100se.MRFreq0,
		dev1.md100se.MRFreq1,
		dev1.md100se.MRFreq2,
		dev1.md100se.MRFreq3,
		dev1.md100se.MDemod,
		dev1.md100se.MEthMode,
		dev1.md100se.MEthPause,
		dev1.md100se.MEthctl,
		dev1.md100se.MEthMaxF0,
		dev1.md100se.MEthMaxF1,
		dev1.md100se.MEthVlanP,
		dev1.md100se.MTEbN00,
		dev1.md100se.MTEbN01,
		dev1.md100se.MTBER0,
		dev1.md100se.MTBER1,
		dev1.md100se.MTBERE,
		dev1.md100se.MIfLoop,
		dev1.md100se.MUnModul,
		dev1.md100se.MACMM
				);




//printfpd("\n\rstrlen():%d", strlen(AnyConfig.Value));
//printfpd("\n\r[-1]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 1]);	 //n
//printfpd("\n\r[-2]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 2]);	 //r
//printfpd("\n\r[-3]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 3]);	  //5
//printfpd("\n\r[-4]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 4]);	 //e
//printfpd("\n\r[-5]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 5]);	  //b
//printfpd("\n\r[-6]:%c", AnyConfig.Value[strlen(AnyConfig.Value) - 6]);	  //9

 //	  for(unsigned i = strlen(AnyConfig.Value); i < (OneConfSize - 2); i++)
	  for(unsigned i = strlen(AnyConfig.Value); i < (OneConfSize - 5); i++)
	  {
		AnyConfig.Value[i] = '_';

	  }
  AnyConfig.Value[OneConfSize - 5] = '3';
  AnyConfig.Value[OneConfSize - 4] = '2';
  AnyConfig.Value[OneConfSize - 3] = '1';
  AnyConfig.Value[OneConfSize - 2] = '0';
  AnyConfig.Value[OneConfSize - 1] = '\0';

//printfpd("\n\r Conf : %d", (unsigned)ConfigFile.Value);
printfp("\n\rhave to keep anuconfig>");
printfp(AnyConfig.Value);

}
//{
//hier params printed at on any format to variable anyconfig
//}

void WriteAnyConfig(unsigned char num)
{
  char * pBuff;
 //AddressAnyConfigs

	pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);


    read_dataflash ((unsigned int)AddressAnyConfigs, (unsigned)AnyConfigSize, (char *)&TFTP_Buffer1[0]);


	 // fill currend config to file
	for(unsigned i = 0; i < OneConfSize; i++)
	{
	 *pBuff++ =  AnyConfig.Value[i];
	}

   write_dataflash ((unsigned int)AddressAnyConfigs, (unsigned int)&TFTP_Buffer1[0],  (unsigned)AnyConfigSize);


}




void ReadAnyConfig(unsigned char num)
{
//

  char * pBuff;
 //AddressAnyConfigs

   if( num < MAX_LOADVARIANTS)
   {

	pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);


    read_dataflash ((unsigned int)AddressAnyConfigs, (unsigned)AnyConfigSize, (char *)&TFTP_Buffer1[0]);


	 // fill currend config to file
	for(unsigned i = 0; i < OneConfSize; i++)
	{
	AnyConfig.Value[i]  = *pBuff++;
	}
  }
  else	  //factory settings
  {

  }


}

void ReadRAnyConfigs()
{
//
   unsigned char num = 0;
  char * pBuff;
 //AddressAnyConfigs

	pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);


    read_dataflash ((unsigned int)AddressAnyConfigs, (unsigned)AnyConfigSize, (char *)&TFTP_Buffer1[0]);


	 // fill currend config to file

//printfp("\n\r1:");
	for(unsigned i = 0; i < OneConfSize; i++)
	{
	RAnyConfig.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig.Value[i]);

	}

//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r2:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig1.Value[i]  = *pBuff++;
  //	printfpd("%c",RAnyConfig1.Value[i]);
	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r3:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig2.Value[i]  = *pBuff++;
  //	printfpd("%c",RAnyConfig2.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig3.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}

//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig4.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig5.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig6.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig7.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig8.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//_____________________________________________________________
 num++;
   pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);
//printfp("\n\r4:");

   for(i = 0; i < OneConfSize; i++)
	{
	RAnyConfig9.Value[i]  = *pBuff++;
 //	printfpd("%c",RAnyConfig3.Value[i]);

	}
//____________________________________________
//factory settings : 

}


void ReadRAnyConfig(unsigned char num)
{
//

  char * pBuff;
 //AddressAnyConfigs

	pBuff = (char *) (&TFTP_Buffer1[0] + num * OneConfSize);


    read_dataflash ((unsigned int)AddressAnyConfigs, (unsigned)AnyConfigSize, (char *)&TFTP_Buffer1[0]);


	 // fill currend config to file
	for(unsigned i = 0; i < OneConfSize; i++)
	{
	RAnyConfig.Value[i]  = *pBuff++;
	}


}



//void GetOutConfig(unsigned char variant)
void GetOutConfig(unsigned long variant)
{
printfp("\n\rGetOutConfig ");

//hier params getted from  variable anyconfig
char * stopstring;
char tmp[16];
//unsigned point = 7;
unsigned point = 4;
unsigned long tmp1;
//unsigned char num;
unsigned long num;

if(variant < MAX_LOADVARIANTS)
{

tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] = AnyConfig.Value[point++];
tmp[3] = 0;

//num = strtoll(tmp);

printfp("\n\r num :");
printfp(tmp);

 num =  strtoll(&tmp[0], &stopstring,10);
 /*
point += 5;

tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] = AnyConfig.Value[point++];
tmp[3] = AnyConfig.Value[point++];
tmp[4] = AnyConfig.Value[point++];
tmp[5] = AnyConfig.Value[point++];
tmp[6] = AnyConfig.Value[point++];
tmp[7] = AnyConfig.Value[point++];
tmp[8] = 0;

printfp("\n\r ip  :");
printfp(tmp);
*/

//IPAddress.Value = strtoll(&tmp[0], &stopstring,16);
//140930 IPAddress.ChangingValue	=  IPAddress.Value;

//point += 5;
point += 3;

tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;

printfp("\n\r cfg :");
printfp(tmp);

ConfigFile.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
ConfigFile.ChangingValue	=  ConfigFile.Value;


point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;

printfp("\n\r mode eth :");
printfp(tmp);

MEthMode.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MEthMode.ChangingValue	=  MEthMode.Value;
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r rf out :");
printfp(tmp);
MRfOut.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MRfOut.ChangingValue	=  MRfOut.Value;
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r out level 0 :");
printfp(tmp);
tmp1 =  strtoll(&tmp[0], &stopstring,16);
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r out level 1:");
printfp(tmp);
MOutLev.Value =  (tmp1	+ (strtoll(&tmp[0], &stopstring,16)<<8)) *(-1) / 10;
MOutLev.ChangingValue	=  MOutLev.Value;
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r t freq0:");
printfp(tmp);
tmp1 =   strtoll(&tmp[0], &stopstring,16);

//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r t freq1:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 8); 
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r t freq2:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 16); 
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r t freq3:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 24); 
MTFreq.Value = (float64)tmp1 / (float64)10000l;
MTFreq.ChangingValue = MTFreq.Value;
//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r r freq0:");
printfp(tmp);
tmp1 =   strtoll(&tmp[0], &stopstring,16);

//________________________________________________
point += 4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r r freq1:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 8); 
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r r freq2:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 16); 
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r r freq3:");
printfp(tmp);
tmp1 +=   (strtoll(&tmp[0], &stopstring,16) << 24); 
MRFreq.Value = (float64)tmp1 / (float64)10000;
MRFreq.ChangingValue = MRFreq.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r demod :");
printfp(tmp);
MDemod.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MDemod.ChangingValue	=  MDemod.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r eth mode :");
printfp(tmp);
MEthMode.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MEthMode.ChangingValue	=  MEthMode.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r eth pause :");
printfp(tmp);
MEthPause.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MEthPause.ChangingValue	=  MEthPause.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r eth ctl :");
printfp(tmp);
MEthctl.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MEthctl.ChangingValue	=  MEthctl.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r max fr 0 :");
printfp(tmp);
tmp1 =  strtoll(&tmp[0], &stopstring,16);
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r max fr 1:");
printfp(tmp);
MEthMaxF.Value =  (tmp1	+ (strtoll(&tmp[0], &stopstring,16)<<8));
MEthMaxF.ChangingValue	=  MEthMaxF.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r vlan pr :");
printfp(tmp);
MEthVlanP.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MEthVlanP.ChangingValue	=  MEthVlanP.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r tebn 0 :");
printfp(tmp);
tmp1 =  strtoll(&tmp[0], &stopstring,16);
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r tebn 1:");
printfp(tmp);
MTEbN0.Value =  (tmp1	+ (strtoll(&tmp[0], &stopstring,16)<<8));
MTEbN0.ChangingValue	=  MTEbN0.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r tber 0 :");
printfp(tmp);
tmp1 =  strtoll(&tmp[0], &stopstring,16);
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r tber 1:");
printfp(tmp);
MTBER.Value =  (tmp1	+ (strtoll(&tmp[0], &stopstring,16)<<8));
MTBER.ChangingValue	=  MTBER.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r tber e :");
printfp(tmp);
MTBERE.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MTBERE.ChangingValue	=  MTBERE.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r if loop :");
printfp(tmp);
MIfLoop.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MIfLoop.ChangingValue	=  MIfLoop.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r unmodul :");
printfp(tmp);
MUnModul.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MUnModul.ChangingValue	=  MUnModul.Value;
//________________________________________________
point +=4;
tmp[0] = AnyConfig.Value[point++];
tmp[1] = AnyConfig.Value[point++];
tmp[2] =0;
printfp("\n\r acm :");
printfp(tmp);
MACMM.Value = strtoll(&tmp[0], &stopstring,16);  //need write id to flash!
MACMM.ChangingValue	=  MACMM.Value;
}
else   //factory settings
{
ConfigFile.Value = 0;  //need write id to flash!
ConfigFile.ChangingValue	=  ConfigFile.Value;
MEthMode.Value = MIN_METHMODE;  //need write id to flash!
MEthMode.ChangingValue	=  MEthMode.Value;
MRfOut.Value = MIN_MRFOUT;  //need write id to flash!
MRfOut.ChangingValue	=  MRfOut.Value;

MOutLev.Value =  MIN_MOUTLEV;
MOutLev.ChangingValue	=  MOutLev.Value;

MOutLevO.Value =  MIN_MOUTLEVO;
MOutLevO.ChangingValue	=  MOutLevO.Value;

MOutLevOS.Value =  MIN_MOUTLEVOS;
MOutLevOS.ChangingValue	=  MOutLevOS.Value;


MTFreq.Value = MIN_MTFREQ;
MTFreq.ChangingValue = MTFreq.Value;
//________________________________________________
MRFreq.Value = MIN_MRFREQ;
MRFreq.ChangingValue = MRFreq.Value;
//________________________________________________
MDemod.Value = MIN_MDEMOD;  //need write id to flash!
MDemod.ChangingValue	=  MDemod.Value;
//________________________________________________
MEthMode.Value = MIN_METHMODE;  //need write id to flash!
MEthMode.ChangingValue	=  MEthMode.Value;
MEthPause.Value = MIN_METHPAUSE;  //need write id to flash!
MEthPause.ChangingValue	=  MEthPause.Value;
MEthctl.Value = MIN_METHCTL;  //need write id to flash!
MEthctl.ChangingValue	=  MEthctl.Value;
MEthMaxF.Value =  MIN_METHMAXF;
MEthMaxF.ChangingValue	=  MEthMaxF.Value;
MEthVlanP.Value = MIN_METHVLANP;  //need write id to flash!
MEthVlanP.ChangingValue	=  MEthVlanP.Value;
MTEbN0.Value =  6;
MTEbN0.ChangingValue	=  MTEbN0.Value;
MTBER.Value =  1;
MTBER.ChangingValue	=  MTBER.Value;
MTBERE.Value = 5;  //need write id to flash!
MTBERE.ChangingValue	=  MTBERE.Value;
MIfLoop.Value = MIN_MIFLOOP;  //need write id to flash!
MIfLoop.ChangingValue	=  MIfLoop.Value;
MUnModul.Value = MIN_MIFLOOP;  //need write id to flash!
MUnModul.ChangingValue	=  MUnModul.Value;
MACMM.Value = MIN_MACMM;  //need write id to flash!
MACMM.ChangingValue	=  MACMM.Value;

}


//need write restore config as current config
   UsedExp.State.Reg2.bit.WriteId = 1;
   UsedExp.State.Reg2.bit.Some = 1;


}



void GetCurConfigFromFile(unsigned char num)
{
//
 ReadAnyConfig(num);//anyconfig readed from any positions of file
 GetOutConfig(num); //params getted from anyconfig

}

void PutCurConfigToFile(unsigned char num)
{
 FillConfig(num); //params writed to any config
 WriteAnyConfig(num); //anyconfig writed to  positions of file
}




Item ModConfItem;

Item RfOutItem;
Item TxOutLevItem;

//Item TxOutLevOItem;
//Item TxOutLevKItem;	  

Item TxOutLevOItem1;
Item TxOutLevKItem1;



Item TxModeItem;
Item TxModulItem;
Item TxCodeRateItem;
Item TxDataRateItem;
Item TxFreqItem;

Item TxModulItem1;	 //indication
Item TxCodeRateItem1;
Item TxDataRateItem1;



Item DeModConfItem;
Item RxModeItem;
Item RxModulItem;
Item RxCodeRateItem;
Item RxDataRateItem;
Item RxFreqItem;
Item RxOnOffItem;

Item RxModulItem1;		//indication
Item RxCodeRateItem1;
Item RxDataRateItem1;





Item TestConfItem;
Item TestIFLoopItem;

Item MonConfItem;
//Item MonEbNItem;
Item MonRAWBERItem;
Item MonCBERItem;
Item MonInpLevItem;
Item MonSweepItem;

Item SatSystemItem;



Item SatIndicationItem;
Item MonEBNItem;
Item MonTEBNItem;
Item MonBERItem;
Item MonTBERItem;
Item MonAGCItem;
Item MonSweepItem;



Item SatIndicationEItem;
Item EthModeItem;
Item EthStatItem;
Item EthSendItem;
Item EthSendUItem;
Item EthRcvDItem;

Item EthReceiveItem;
Item EthReceiveCRCItem;



Item SatLogViewItem;
Item SatLogItem;

Item ModulatorItem;
Item DemodulatorItem;
Item CommonItem;
//Item ModTestItem;

Item InterfaceItem;
Item InterfaceModeItem;
Item InterfacePauseItem;
Item InterfaceInBandItem;
Item InterfaceMaxFrameItem;
Item InterfaceVLANPItem;
Item InterfaceRateItem;



Item ConfigFileItem;

Item ModTestItem;
Item ModIFLoopItem;
Item ModUnmodulItem;

Item FirmwareItem;
Item IFmoduleItem;

Item SaveLoadItem;
Item SaveItem;
Item LoadItem;

Item MACMMItem;

Item MACMMItem;

Item MRCntlItem;

Item SatSoundItem;



