//

 strcpy(cRemLoadVariants, "H0");
 strcpy(cRemSaveVariants, "H1");
 strcpy(cLoadVariantsV, "1      2      3      4      5      6      7      8      9      10     Factory");
 strcpy(cSaveVariantsV, "1 2 3 4 5 6 7 8 9 10");
 strcpy(cAnyConfig, "H2");
 strcpy(cRAnyConfig, "H3");
 strcpy(cCurReadedAnyCofigV,"0123456789A");
 strcpy(cRemCurReadedAnyCofig, "H4");
 strcpy(cRAnyConfig1, "H5");
 strcpy(cRAnyConfig2, "H6");
 strcpy(cRAnyConfig3, "H7");
 strcpy(cRemFirmFileData, "H8");

//_______________________________
 strcpy(cMRfOutV,"OffOn ");
 strcpy(cRemMRfOut, "H9"); 	
 strcpy(cRemMOutLev, "Ha");	 
 strcpy(cRemMTDRate, "Hb");	 
 strcpy(cRemMRDRate, "Hc");
 strcpy(cRemMTFreq,	"Hd");
 strcpy(cRemMRFreq,	"He");

strcpy(cRAnyConfig4, "Hf");
strcpy(cRAnyConfig5, "Hg");
strcpy(cRAnyConfig6, "Hi");
strcpy(cRAnyConfig7, "Hj");
strcpy(cRAnyConfig8, "Hk");
strcpy(cRAnyConfig9, "Hl");
 strcpy(cRemMOutLev1, "Hm");	
  strcpy(cRemMOutLev1, "Hn");	


#ifndef PROG_ODU1
strcpy(cMTModulV,"QPSK  8PSK  8APSK 16QAM 16APSK32QAM 64QAM ");
#else
strcpy(cMTModulV,"QPSK  8PSK  8APSK 16QAM 16APSK32QAM 32APSK32APSS64QAM 128QAM256QAM");
#endif
 /*
char *Emb4ACT15504::NameModulate(int i, int m,char *ch)
{
	switch(cfg[i].emb.mode15504[m].mode)
	{

		case 0: return "QPSK";  
		case 1: return "8PSK";  
		case 2: return "8APSK";  
		case 3: return "16QAM";  
		case 4: return "16APSK";  
		case 5: return "32QAM";  
		case 6: return "32APSK";  
		case 7: return "32APSK-S"; 
		case 8: return "64QAM";  
		case 9: return "128QAM";  
		case 10: return "256QAM";
			
	}
	return "????";	
}
 */




//strcpy(cMTCdTypeV,"LDPC RS ");
//strcpy(cMRCdTypeV,"LDPC RS ");

strcpy(cMTCdTypeV," RS LDPC");
strcpy(cMRCdTypeV," RS LDPC");



//strcpy(cMTModeV,"0123456789ABCDEF");
strcpy(cMTModeV,"0                      \
1                      \
2                      \
3                      \
4                      \
5                      \
6                      \
7                      \
8                      \
9                      \
A                      \
B                      \
C                      \
D                      \
E                      \
F                      ");
strcpy(cMRModeV,"0123456789ABCDEF");
strcpy(cMRCntlV,"Local+RemoteRemote Only ");
strcpy(cMRCntl,	"    Remote Control :     ");

strcpy(cMOutLevOSV,	"+-");



#ifndef PROG_ODU1
strcpy(cMRModulV,"BPSK QPSK OQPSK8PSK ");
#else
strcpy(cMRModulV,"BPSK QPSK OQPSK8PSK ");
#endif


//strcpy(cMTCodeV,"1/23/4");
//strcpy(cMRCodeV,"1/23/4");
strcpy(cMDemodV,"OffOn ");
strcpy(cMEthModeV,"Auto10h 10f 100h100f1000");
strcpy(cMEthPauseV,"OffOn ");
strcpy(cMEthctlV,"OffOn ");
//strcpy(cMEthModeIV,"1G   100  ");
strcpy(cMEthModeIV,"  10h   100h   1000h   10f   100f   1000f 1000LX 1000LX No Link");
strcpy(cMIfLoopV,"OffOn ");
strcpy(cMUnModulV,"OffOn ");

strcpy(cMACMMV,"OffOn NA ");
//strcpy(cMACMMVI,"   ACM");
 #ifdef RACM

strcpy(cMACMMVI,"   ACM Parameters       ");
strcpy(cMSEI,   "      mse:              ");

// char catl[26];
// char catm[26];
// char caen[16][26];
// char caeb[26];

strcpy(catl,    "tlock    ms tmode     ms");
strcpy(catl1,   "tlock    ms tmode     ms");


strcpy(catm,    "tmse     ms tstep     ms");


strcpy(caen[0], "0     #inc     #dec     ");
strcpy(caen[1], "1     #inc     #dec     ");
strcpy(caen[2], "2     #inc     #dec     ");
strcpy(caen[3], "3     #inc     #dec     ");
strcpy(caen[4], "4     #inc     #dec     ");
strcpy(caen[5], "5     #inc     #dec     ");
strcpy(caen[6], "6     #inc     #dec     ");
strcpy(caen[7], "7     #inc     #dec     ");
strcpy(caen[8], "8     #inc     #dec     ");
strcpy(caen[9], "9     #inc     #dec     ");
strcpy(caen[10],"10    #inc     #dec     ");
strcpy(caen[11],"11    #inc     #dec     ");
strcpy(caen[12],"12    #inc     #dec     ");
strcpy(caen[13],"13    #inc     #dec     ");
strcpy(caen[14],"14    #inc     #dec     ");
strcpy(caen[15],"15    #inc     #dec     ");

//strcpy(caeb   , "ebn0 i      ebn0 d      ");
strcpy(caeb   , "msei        msed        ");








#endif

//strcpy(cMACMM,     "    ACM Mode:           ");
strcpy(cMACMM,     "ACM Mode:    Offset:    ");
strcpy(cMACMMRes,  " ACM Mode Recovery:     ");





strcpy(cRemMTModul,	"Hf");
strcpy(cRemMRModul,	"Hg");
strcpy(cRemMTCode,	"Hh");
strcpy(cRemMRCode,	"Hi");
strcpy(cRemMDemod,	"Hj");
strcpy(cRemMEthMode,	"Hk");
strcpy(cRemMEthPause,	"Hl");
strcpy(cRemMEthctl,	"Hm");
strcpy(cRemMEthMaxF, "Hn");
strcpy(cRemMEthVlanP, "Ho");
strcpy(cRemMEbN0, "Hp");
strcpy(cRemMTEbN0, "Hq");
strcpy(cRemMBER, "Hr");
strcpy(cRemMTBER, "Hs");
strcpy(cRemMAGC, "Ht");
strcpy(cRemMSweep, "Hu");
strcpy(cRemMEthSend, "Hv");
strcpy(cRemMEthReceived, "Hw");
strcpy(cRemMEthModeI, "Hx");
strcpy(cRemMIfLoop, "Hy");
strcpy(cRemMUnModul, "Hz");

strcpy(cRemMACMM, "HA");
strcpy(cRemMTBERE, "HB");
strcpy(cRemIFmoduleData,"HC");

strcpy(cRemMEthReceivedCRC, "HD");
strcpy(cRemMEthSendU, "HE");
strcpy(cRemIFmoduleHeader,"HG");
strcpy(cRemMTCdType,	"HI");
strcpy(cRemMRCdType,	"HJ");
strcpy(cRemMTMode,	"HK");
strcpy(cRemMRMode,	"HL");
strcpy(cRemMRCntl,	"HM");
strcpy(cRemMOutLevO, "HN");	 
strcpy(cRemMOutLevO, "HO");	
strcpy(cRemMBERE, "HP");
strcpy(cRemMOutLevOS, "HQ");
strcpy(cRemDFE,"HR");

#ifdef RACM
 strcpy(cRemRACMOnOff,"HS");
 strcpy(cRemratimelock,"HT");
 strcpy(cRemratimemode,"HU");
 strcpy(cRemratimemse,"HV");
 strcpy(cRemratimestep,"HW");

 strcpy(cRemuebn[0],  "HX00");
 strcpy(cRemuebn[1],  "HX01");
 strcpy(cRemuebn[2],  "HX02");
 strcpy(cRemuebn[3],  "HX03");
 strcpy(cRemuebn[4],  "HX04");
 strcpy(cRemuebn[5],  "HX05");
 strcpy(cRemuebn[6],  "HX06");
 strcpy(cRemuebn[7],  "HX07");
 strcpy(cRemuebn[8],  "HX08");
 strcpy(cRemuebn[9],  "HX09");
 strcpy(cRemuebn[10], "HX10");
 strcpy(cRemuebn[11], "HX11");
 strcpy(cRemuebn[12], "HX12");
 strcpy(cRemuebn[13], "HX13");
 strcpy(cRemuebn[14], "HX14");
 strcpy(cRemuebn[15], "HX15");

 strcpy(cRemdebn[0],  "HY00");
 strcpy(cRemdebn[1],  "HY01");
 strcpy(cRemdebn[2],  "HY02");
 strcpy(cRemdebn[3],  "HY03");
 strcpy(cRemdebn[4],  "HY04");
 strcpy(cRemdebn[5],  "HY05");
 strcpy(cRemdebn[6],  "HY06");
 strcpy(cRemdebn[7],  "HY07");
 strcpy(cRemdebn[8],  "HY08");
 strcpy(cRemdebn[9],  "HY09");
 strcpy(cRemdebn[10], "HY10");
 strcpy(cRemdebn[11], "HY11");
 strcpy(cRemdebn[12], "HY12");
 strcpy(cRemdebn[13], "HY13");
 strcpy(cRemdebn[14], "HY14");
 strcpy(cRemdebn[15], "HY15");

 strcpy(cenamodeV,  "disen ");
 

 strcpy(cRemenamode[0],   "HZ00");
 strcpy(cRemenamode[1],   "HZ01");
 strcpy(cRemenamode[2],   "HZ02");
 strcpy(cRemenamode[3],   "HZ03");
 strcpy(cRemenamode[4],   "HZ04");
 strcpy(cRemenamode[5],   "HZ05");
 strcpy(cRemenamode[6],   "HZ06");
 strcpy(cRemenamode[7],   "HZ07");
 strcpy(cRemenamode[8],   "HZ08");
 strcpy(cRemenamode[9],   "HZ09");
 strcpy(cRemenamode[10],  "HZ10");
 strcpy(cRemenamode[11],  "HZ11");
 strcpy(cRemenamode[12],  "HZ12");
 strcpy(cRemenamode[13],  "HZ13");
 strcpy(cRemenamode[14],  "HZ14");
 strcpy(cRemenamode[15],  "HZ15");



strcpy(cnumodeV,  " 0 1 2 3 4 5 6 7 8 9101112131415");


  strcpy(cRemnumode[0],	 "LI00");
  strcpy(cRemnumode[1],	 "LI01");
  strcpy(cRemnumode[2],	 "LI02");
  strcpy(cRemnumode[3],	 "LI03");
  strcpy(cRemnumode[4],	 "LI04");
  strcpy(cRemnumode[5],	 "LI05");
  strcpy(cRemnumode[6],	 "LI06");
  strcpy(cRemnumode[7],	 "LI07");
  strcpy(cRemnumode[8],	 "LI08");
  strcpy(cRemnumode[9],	 "LI09");
  strcpy(cRemnumode[10],	 "LI10");
  strcpy(cRemnumode[11],	 "LI11");
  strcpy(cRemnumode[12],	 "LI12");
  strcpy(cRemnumode[13],	 "LI13");
  strcpy(cRemnumode[14],	 "LI14");
  strcpy(cRemnumode[15],	 "LI15");

  strcpy(cRemnumode[0],	 "LI00");
  strcpy(cRemnumode[1],	 "LI01");
  strcpy(cRemnumode[2],	 "LI02");
  strcpy(cRemnumode[3],	 "LI03");
  strcpy(cRemnumode[4],	 "LI04");
  strcpy(cRemnumode[5],	 "LI05");
  strcpy(cRemnumode[6],	 "LI06");
  strcpy(cRemnumode[7],	 "LI07");
  strcpy(cRemnumode[8],	 "LI08");
  strcpy(cRemnumode[9],	 "LI09");
  strcpy(cRemnumode[10],	 "LI10");
  strcpy(cRemnumode[11],	 "LI11");
  strcpy(cRemnumode[12],	 "LI12");
  strcpy(cRemnumode[13],	 "LI13");
  strcpy(cRemnumode[14],	 "LI14");
  strcpy(cRemnumode[15],	 "LI15");

  strcpy(cRemndmode[0],	 "LI00");
  strcpy(cRemMSEI,	 "LJ");
  strcpy(cRemRACMOnOffT,"LK");
  strcpy(cRemRACMOffset,"LM");







#endif






//hr ...hu  - used for netmask 0...3


strcpy(cRemMKout, "h1");
strcpy(cRemMKout1,"h2");
strcpy(cRemMKin1, "h3");
strcpy(cRemMKin2, "h4");
strcpy(cRemMKin3, "h5");
 strcpy(cRemSatSound, "GJ");
