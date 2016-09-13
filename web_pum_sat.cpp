





float64  Par000;
extern "C" void	  SetPar000(float64 val)
{
if(!(password_state))
{
	return;
}

//Par000 = val;

if((unsigned)SatSet1.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet1");
 return;
}

  printfp("\n\r Change the SatSet1 - sysdelay");

Par000 = val;

SatSet1.Value = val;
SatSet1.ChangingValue = val;
CheckWEBData();
//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetSysDelay(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}



extern "C" float64  GetPar000()
{
Par000 =  SatSet1.Value;


return Par000;
}//0x87654321;}

float64  Par001;


extern "C" void	  SetPar001(float64 val)
{
if(!(password_state))
{
	return;
}

//Par001 = val;

if((unsigned)SatSet5.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet5 rcvfreq");
 return;
}

  printfp("\n\r Change the SatSet5 rcvfreq");

 Par001 = val;

SatSet5.Value = val;
SatSet5.ChangingValue = val;
CheckWEBData();
//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetRcvFrequency();
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;


}

extern "C" float64  GetPar001()
{
Par001 =  SatSet5.Value;


return Par001;
}//0x87654321;}
//_______________________________________________
float64  Par002;
extern "C" void	  SetPar002(float64 val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet4.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet4 trfreq");
 return;
}

  printfp("\n\r Change the SatSet4 trfreq");




Par002 = val;
SatSet4.Value = val;
SatSet4.ChangingValue = val;
CheckWEBData();
//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetTrFrequency(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" float64  GetPar002()
{
Par002 =  SatSet4.Value;
return Par002;
}//0x87654321;}
//___________________________________________________
float64  Par003;
extern "C" void	  SetPar003(float64 val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet7.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet7 rcv bound");
 return;
}

  printfp("\n\r Change the SatSet7 rcv bound");


Par003 = val;
SatSet7.Value = val;
SatSet7.ChangingValue = val;
CheckWEBData();
//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetRcvBound(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" float64  GetPar003()
{
Par003 =  SatSet7.Value;
return Par003;
}//0x87654321;}
//___________________________________________________
float64  Par004;
extern "C" void	  SetPar004(float64 val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet6.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet6 tr bound");
 return;
}

  printfp("\n\r Change the SatSet6 tr bound");


Par004 = val;
SatSet6.Value = val;
SatSet6.ChangingValue = val;
CheckWEBData();
//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetTrBound(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" float64  GetPar004()
{
Par004 =  SatSet6.Value;
return Par004;
}//0x87654321;}
//___________________________________________________
float64  Par005;
extern "C" void	  SetPar005(float64 val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet0.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet0 freq proc");
 return;
}

  printfp("\n\r Change the SatSet0 freq proc");


Par005 = val;
SatSet0.Value = val;
SatSet0.ChangingValue = val;
CheckWEBData();

//printfpd("\n\r5a: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" float64  GetPar005()
{
Par005 =  SatSet0.Value;
return Par005;
}//0x87654321;}
//___________________________________________________
float64  Par006;
extern "C" void	  SetPar006(float64 val)
{
if(!(password_state))
{
	return;
}

if((signed)SatSet2.Value == (signed)val * -1)
{
 printfp("\n\r Do not change the SatSet2 out level");
 return;
}

  printfp("\n\r Change the SatSet2 out level");


Par006 = val * (float)(-1);
SatSet2.Value = Par006;
SatSet2.ChangingValue = Par006;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetOutLevel();
//printfpd("\n\r5a: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" float64  GetPar006()
{
Par006 =  SatSet2.Value * (float64)(-1);
return Par006;
}//0x87654321;}

//___________________________________________________
unsigned char  Par007;
extern "C" void	  SetPar007(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatTestMode.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatTestMode");
 return;
}
 printfp("\n\r Change the SatTestMode");


Par007 = val;
SatTestMode.Value = val;
SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetSatTestMode();
//printfpd("\n\rpar7 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" unsigned char  GetPar007()
{
Par007 =  SatTestMode.Value;
return Par007;
}//0x87654321;}

unsigned long  Par008;

#define	DEFAULT_PASSWORD_ON		(98765432)
#define	DEFAULT_PASSWORD_OFF	(123)
/*
extern "C" void	  SetPar008(unsigned long val)
{
Par008 = val;

if(val == DEFAULT_PASSWORD_ON)
{
   password_state = 1;
printfp("\n\r Password on ok");
}
else if(val == DEFAULT_PASSWORD_OFF)
{
   password_state = 0;
printfp("\n\r Password off ok");
}
else
{
 printfp("\n\r Password wrong");
}
//SatTestMode.Value = val;
//SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

//CheckRestoringData();
//SetSatTestMode();
//printfpd("\n\r5a: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
//UsedExp.State.Reg2.bit.WriteId = 1;
}

*/

extern "C" void	  SetPar008(unsigned long val)
{
Par008 = val;

if(((val == DEFAULT_PASSWORD_ON) || (val == WebPassword.Value)) && (password_state == 0))
//if(1) //t 140521
{
   password_state = 1;
//printfp("\n\r Password on ok");
}
else if((val == DEFAULT_PASSWORD_OFF) || (val == WebPassword.Value))
{
   password_state = 0;
//printfp("\n\r Password off ok");
}

else
{
// printfp("\n\r Password wrong");
}





//SatTestMode.Value = val;
//SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

//CheckRestoringData();
//SetSatTestMode();
//printfpd("\n\r5a: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
//UsedExp.State.Reg2.bit.WriteId = 1;
}


extern "C" unsigned long  GetPar008()
{
//Par008 =  SatTestMode.Value;
return Par008;
}//0x87654321;}


//______________________________________________________________
unsigned char  Par00a;
extern "C" void	  SetPar00a(unsigned char val)
{

//printfp("\n\rSetPar00a");
if(!(password_state))
{
	return;
}

if((unsigned)SatTiming.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatTiming");
 return;
}
 printfp("\n\r Change the SatTiming");


Par00a = val;
SatTiming.Value = val;
SatTiming.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetSatTiming();
//printfpd("\n\rpara :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" unsigned char  GetPar00a()
{
Par00a =  SatTiming.Value;
return Par00a;
}//0x87654321;}

//___________________________________________________

#define PROGRAMM_ADDRESS  (0xC0044000)
#define HEADER_SIZE  (96)
#define PROGRAMM_SIZE (403000)
#define XILINX_SIZE (4500000)	//? pu_msat

unsigned char  Par00b;

extern unsigned long far_server;   //declared in httpd.c

extern "C" void	  SetPar00b(unsigned char val)
{

if(!(password_state))
{
	return;
}

Par00b = val;
//SatTestMode.Value = val;
//SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

//CheckWEBData();
//SetSatTestMode();
//printfpd("\n\rparb :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
//UsedExp.State.Reg2.bit.WriteId = 1;
//UsedExp.State.Reg2.bit.Some = 1;
if(val)
{
  OperateFileWebProg( far_server, "xh.bin", 
     (unsigned long)(PROGRAMM_SIZE), (unsigned long)(PROGRAMM_ADDRESS - HEADER_SIZE), 1);
}



//extern "C" void OperateFileWebProg( _ip_address server, char_ptr filename, 
// unsigned int size, unsigned long addr_dest, unsigned long operation)

}

extern "C" unsigned char  GetPar00b()
{
Par00b = 0;// SatTestMode.Value;
return Par00b;
}//0x87654321;}

unsigned char  Par00c;

extern "C" void	  SetPar00c(unsigned char val)
{
if(!(password_state))
{
	return;
}

Par00c = val;
//SatTestMode.Value = val;
//SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

//CheckWEBData();
//SetSatTestMode();
//printfpd("\n\rSetPar00c: %d",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
//UsedExp.State.Reg2.bit.WriteId = 1;
//UsedExp.State.Reg2.bit.Some = 1;
//printfpd("\n\rparc :: %ld",(unsigned long)val);
if(val)
{
  OperateFileWebProg( far_server, "xhx.bin", 
     (unsigned long)(XilSizeToDownloadD), (unsigned long)(CFG_DATAFLASH_LOGIC_ADDR_CS1), 1);
}



//extern "C" void OperateFileWebProg( _ip_address server, char_ptr filename, 
// unsigned int size, unsigned long addr_dest, unsigned long operation)

}

extern "C" unsigned char  GetPar00c()
{
Par00c = 0;// SatTestMode.Value;
return Par00c;
}//0x87654321;}


unsigned char  Par00d;

extern "C" void	  SetPar00d(unsigned char val)
{
if(!(password_state))
{
	return;
}

Par00d = val;
//SatTestMode.Value = val;
//SatTestMode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

//CheckWEBData();
//SetSatTestMode();
//printfpd("\n\rparb :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
//UsedExp.State.Reg2.bit.WriteId = 1;
//UsedExp.State.Reg2.bit.Some = 1;

//printfpd("\n\rpard :: %ld",(unsigned long)val);
if(val)
{

 // printfp("\n\rRestart!");

   dev_restart();
 // OperateFileWebProg( far_server, "xhx.bin", 
 //    (unsigned long)(XILINX_SIZE), (unsigned long)(PROGRAMM_ADDRESS - HEADER_SIZE), 1);
}



//extern "C" void OperateFileWebProg( _ip_address server, char_ptr filename, 
// unsigned int size, unsigned long addr_dest, unsigned long operation)

}

extern "C" unsigned char  GetPar00d()
{
Par00d = 0;// SatTestMode.Value;
return Par00d;
}//0x87654321;}



signed char  Par010;
extern "C" void	  SetPar010(signed char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet3.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet3 averdist");
 return;
}
 printfp("\n\r Change the SatSet3 averdist ");


Par010 = val;
SatSet3.Value = val;
SatSet3.ChangingValue = val;
//printfpdv(" 010: % 5.3f",val);

CheckWEBData();
SetAverDistance();
//printfpd("\n\rslave level : %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" signed char  GetPar010()
{
Par010 =  SatSet3.Value;
return Par010;
}//0x87654321;}


unsigned char  Par011;
extern "C" void	  SetPar011(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatExtLock.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatExtLock");
 return;
}
 printfp("\n\r Change the SatExtLock ");



Par011 = val;
SatExtLock.Value = val;
SatExtLock.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetSatExtLock();
//printfpd("\n\rpar011 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" unsigned char  GetPar011()
{
Par011 =  SatExtLock.Value;
return Par011;
}//0x87654321;}

unsigned char  Par012;
extern "C" void	  SetPar012(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatExtLockP.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatExtLockP");
 return;
}
 printfp("\n\r Change the SatExtLockP ");


Par012 = val;
SatExtLockP.Value = val;
SatExtLockP.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetSatExtLockP();
//printfpd("\n\rpar012 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" unsigned char  GetPar012()
{
Par012 =  SatExtLockP.Value;
return Par012;
}//0x87654321;}


unsigned char  Par013;
extern "C" void	  SetPar013(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSound.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSound");
 return;
}
 printfp("\n\r Change the SatSound ");


Par013 = val;
SatSound.Value = val;
SatSound.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetSatSound();
//printfpd("\n\rpar013 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}
extern "C" unsigned char  GetPar013()
{
Par013 =  SatSound.Value;
return Par013;
}//0x87654321;}




unsigned char  Par014;

extern "C" void	  SetPar014(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatTF.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatTF");
 return;
}
 printfp("\n\r Change the SatTF ");



Par014 = val;
SatTF.Value = val;
SatTF.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();
SetAverDistance();
//printfpd("\n\rpar014 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C"  char * GetPar014()
{
 SatTF.MakeResultStrV();
//Par014 =  SatTF.Value;
return SatTF.pResultStr;
}//0x87654321;}


unsigned char Par015;

extern "C" void	  SetPar015(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatLowP.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatLowP");
 return;
}
 printfp("\n\r Change the SatLowP ");


Par015 = val;
SatLowP.Value = val;
SatLowP.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetSatLowP();
//printfpd("\n\rpar015 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned char GetPar015()
{
// SatTF.MakeResultStrV();
Par015 =  SatLowP.Value;
return Par015;
}//0x87654321;}

unsigned long Par016;

extern "C" void	  SetPar016(unsigned long val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatRate.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatRate");
 return;
}
 printfp("\n\r Change the SatRate");


Par016 = val;
SatRate.Value = val;
SatRate.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);
//printfpd("\n\rpar016 :: %ld",(unsigned long)val);

CheckWEBData();

//SetSatALev(); //check enadled rate

switch(SatALev.Value)
{
 case 0: //5
 if(SatRate.Value > SATRATE_LEV0)
 {
// printfp("\n\rSetLev 0");

 SatRate.Value = SATRATE_LEV0;
 SatRate.ChangingValue = SatRate.Value;
 //SetSatRate();
 }
 break;

 case 1: //15
 if(SatRate.Value > SATRATE_LEV1)
 {
// printfp("\n\rSetSatALev1");
 SatRate.Value = SATRATE_LEV1;
 SatRate.ChangingValue = SatRate.Value;
// SetSatRate();
 }
 break;

 case 2: //50
 // SetSatRate();
 
 break;


 default : break;

}  //case


SetSatRate();
//printfpd("\n\rpar016_1 :: %ld",(unsigned long)SatRate.Value);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned long GetPar016()
{
// SatTF.MakeResultStrV();
Par016 =  SatRate.Value;
return Par016;
}//0x87654321;}


unsigned char Par019;

extern "C" void	  SetPar019(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet6.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet6 tr bound ");
 return;
}
 printfp("\n\r Change the SatSet6  tr bound ");


Par019 = val;
SatSet6.Value = val;
SatSet6.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetTrBound();
//printfpd("\n\rpar019 :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned char GetPar019()
{
// SatTF.MakeResultStrV();
Par019 =  SatSet6.Value;
return Par019;
}//0x87654321;}

unsigned char Par01a;

extern "C" void	  SetPar01a(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatDF.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatDF aver dist ");
 return;
}
 printfp("\n\r Change the SatDF  aver dist ");



Par01a = val;
SatDF.Value = val;
SatDF.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetAverDistance();
//printfpd("\n\rpar01a :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned char GetPar01a()
{
// SatTF.MakeResultStrV();
Par01a =  SatDF.Value;
return Par01a;
}//0x87654321;}

unsigned char Par01b;

extern "C" void	  SetPar01b(unsigned char val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatTimer.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatTimer ");
 return;
}
 printfp("\n\r Change the SatTimer ");




Par01b = val;
SatTimer.Value = val;
SatTimer.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetSatTimer();
//printfpd("\n\rpar01b :: %ld",(unsigned long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned char GetPar01b()
{
// SatTF.MakeResultStrV();
Par01b =  SatTimer.Value;
return Par01b;
}//0x87654321;}

extern "C" void	  SetPar01c(signed long val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatSet8.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatSet8 ");
 return;
}
 printfp("\n\r Change the SatSet8 ");



//Par01b = val;
SatSet8.Value = val;
SatSet8.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetOffset();

//printfpd("\n\rpar01c :: %ld",(signed long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" signed long GetPar01c()
{
// SatTF.MakeResultStrV();
//Par01b =  SatTimer.Value;
return (signed long)SatSet8.Value;
}//0x87654321;}

//extern "C" void	  SetPar01e(signed long val)
//{
//}

extern "C" char* GetPar01e()
{
 SatGet1.MakeResultStrI();
 return SatGet1.pResultStr;
}

extern "C" char* GetPar01f()
{
 SatGet2.MakeResultStrI();
 return SatGet2.pResultStr;
}

extern "C" char* GetPar020()
{
 SatGet3.MakeResultStrI();
 return SatGet3.pResultStr;
}

extern "C" char* GetPar021()
{
 SatInput.MakeResultStrV();
 return SatInput.pResultStr;
}

extern "C" char* GetPar022()
{
 SatSearch.MakeResultStrV();
 return SatSearch.pResultStr;
}

extern "C" void	  SetPar027(unsigned long val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatACode.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatACode ");
 return;
}
 printfp("\n\r Change the SatACode ");



//Par01b = val;
SatACode.Value = val;
SatACode.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

SetSatACode();

//printfpd("\n\rpar027 :: %8d",(signed long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" void	  SetPar028(unsigned long val)
{
if(!(password_state))
{
	return;
}

if((unsigned)SatADemo.Value == (unsigned)val)
{
 printfp("\n\r Do not change the SatADemo ");
 return;
}
 printfp("\n\r Change the SatADemo ");


//Par01b = val;
SatADemo.Value = val;
SatADemo.ChangingValue = val;
//printfpdv(" 6a: % 5.3f",val);

CheckWEBData();

if(val) 
{
SetSatADemo();
}

//printfpd("\n\rpar028 :: %d",(signed long)val);

//UsedExp.State.Reg2.bit.SatSet1 = 1;
//SetFreqProc(); 
	   //some for make
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;
}

extern "C" unsigned char GetPar028()
{
// SatTF.MakeResultStrV();

return (unsigned char)SatADemo.Value;
}//0x87654321;}

extern "C" void	  SetPar02b(unsigned long val)
{

if(!(password_state))
{
	return;
}
if(val < 1) val = 1;
start_event = val;
//printfpd("\n\r par02b : %d", start_event);
}
 
extern "C" void	  SetPar02d(unsigned long val)
{

if(!(password_state))
{
	return;
}
if(val)  ClearYournal();;


}


extern "C" void	  SetPar02e(unsigned long val)
{

if(!(password_state))
{
	return;
}

//if(val < 1) val = 1;

if((unsigned)TimeData6.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData6 ");
 return;
}
 printfp("\n\r Change the TimeData6 ");



 if((val > TIMEDATA6_MAX) || (val < TIMEDATA6_MIN)){ return;}
 	
TimeData6.Value = val;
TimeData6.ChangingValue = val;
ClockWriteYear(val);


//printfpd("\n\r par02e : %d", val);
}

extern "C" void	  SetPar02f(unsigned long val)
{

if(!(password_state))
{
	return;
}

if((unsigned)TimeData5.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData5 ");
 return;
}
 printfp("\n\r Change the TimeData5 ");


//if(val < 1) val = 1;
if((val > TIMEDATA5_MAX) || (val < TIMEDATA5_MIN)){ return;}

TimeData5.Value = val;
TimeData5.ChangingValue = val;
ClockWriteMonth(val);

//printfpd("\n\r par02f : %d", val);
}

extern "C" void	  SetPar030(unsigned long val)
{

if(!(password_state))
{
	return;
}

if((unsigned)TimeData4.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData4 ");
 return;
}
 printfp("\n\r Change the TimeData4 ");


//if(val < 1) val = 1;
if((val > TIMEDATA4_MAX) || (val < TIMEDATA4_MIN)){ return;}

TimeData4.Value = val;
TimeData4.ChangingValue = val;
ClockWriteDate(val);

//printfpd("\n\r par030 : %d", val);
}

extern "C" void	  SetPar031(unsigned long val)
{

if(!(password_state))
{
	return;
}

if((unsigned)TimeData3.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData3 ");
 return;
}
 printfp("\n\r Change the TimeData3 ");


//if(val < 1) val = 1;
if((val > TIMEDATA3_MAX) || (val < TIMEDATA3_MIN)){ return;}

TimeData3.Value = val;
TimeData3.ChangingValue = val;
ClockWriteHours(val);

//printfpd("\n\r par031 : %d", val);
}

extern "C" void	  SetPar032(unsigned long val)
{

if(!(password_state))
{
	return;
}

if((unsigned)TimeData2.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData2 ");
 return;
}
 printfp("\n\r Change the TimeData2 ");


//if(val < 1) val = 1;
if((val > TIMEDATA2_MAX) || (val < TIMEDATA2_MIN)){ return;}

TimeData2.Value = val;
TimeData2.ChangingValue = val;
ClockWriteMin(val);

//printfpd("\n\r par032 : %d", val);
}

extern "C" void	  SetPar033(unsigned long val)
{

if(!(password_state))
{
	return;
}

if((unsigned)TimeData1.Value == (unsigned)val)
{
 printfp("\n\r Do not change the TimeData1 ");
 return;
}
 printfp("\n\r Change the TimeData1 ");


//if(val < 1) val = 1;
if((val > TIMEDATA1_MAX) || (val < TIMEDATA1_MIN)){ return;}

TimeData1.Value = val;
TimeData1.ChangingValue = val;
ClockWriteSec(val);

//printfpd("\n\r par033 : %d", val);
}


unsigned long Par034;

extern "C" void	  SetPar034(unsigned long val)
{

if(!(password_state))
{
	return;
}
 Par034 = val;
//WebPassword.Value = val;
//WebPassword.ChangingValue = val;
//UsedExp.State.Reg2.bit.WriteId = 1;
//UsedExp.State.Reg2.bit.Some = 1;


//printfpd("\n\r par034 : %d", val);
}

extern "C" void	  SetPar035(unsigned long val)
{
if(!(password_state))
{
	return;
}

if(val > 255) return;

if((unsigned)IPAddress3.Value == (unsigned)val)
{
 printfp("\n\r Do not change the IPAddress3 ");
 return;
}
 printfp("\n\r Change the IPAddress3 ");


 IPAddress3.Value = val;
 IPAddress3.ChangingValue = val;




IPAddress.Value = 	((char)IPAddress3.Value << 24) + ((char)IPAddress2.Value<<16)	+
										 ((char)IPAddress1.Value<<8) + (char)IPAddress0.Value;
			  //to flash	IPAddress.WriteStorageC((IPAddressStorage), (IPAddress.Value));
				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.WriteId = 1;
				UsedExp.State.Reg2.bit.Some  = 1; //some load


}

extern "C" void	  SetPar036(unsigned long val)
{
 if(!(password_state))
{
	return;
}

if(val > 255) return;

if((unsigned)IPAddress2.Value == (unsigned)val)
{
 printfp("\n\r Do not change the IPAddress2 ");
 return;
}
 printfp("\n\r Change the IPAddress2 ");



 IPAddress2.Value = val;
 IPAddress2.ChangingValue = val;


IPAddress.Value = 	((char)IPAddress3.Value << 24) + ((char)IPAddress2.Value<<16)	+
										 ((char)IPAddress1.Value<<8) + (char)IPAddress0.Value;
			  //to flash	IPAddress.WriteStorageC((IPAddressStorage), (IPAddress.Value));
				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.WriteId = 1;
				UsedExp.State.Reg2.bit.Some  = 1; //some load

}
extern "C" void	  SetPar037(unsigned long val)
{
 if(!(password_state))
{
	return;
}

if(val > 255) return;

if((unsigned)IPAddress1.Value == (unsigned)val)
{
 printfp("\n\r Do not change the IPAddress1 ");
 return;
}
 printfp("\n\r Change the IPAddress1 ");



 IPAddress1.Value = val;
 IPAddress1.ChangingValue = val;


IPAddress.Value = 	((char)IPAddress3.Value << 24) + ((char)IPAddress2.Value<<16)	+
										 ((char)IPAddress1.Value<<8) + (char)IPAddress0.Value;
			  //to flash	IPAddress.WriteStorageC((IPAddressStorage), (IPAddress.Value));
				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.WriteId = 1;
				UsedExp.State.Reg2.bit.Some  = 1; //some load


}
extern "C" void	  SetPar038(unsigned long val)
{
 // printfp("\n\r SetPar038 ");


 if(!(password_state))
{
	return;
}

if(val > 255) return;

if((unsigned)IPAddress0.Value == (unsigned)val)
{
 printfp("\n\r Do not change theIPAddress0 ");
 return;
}
 printfp("\n\r Change the IPAddress0 ");

 // return; //for test !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

 IPAddress0.Value = val;
 IPAddress0.ChangingValue = val;


IPAddress.Value = 	((char)IPAddress3.Value << 24) + ((char)IPAddress2.Value<<16)	+
										 ((char)IPAddress1.Value<<8) + (char)IPAddress0.Value;
			  //to flash	IPAddress.WriteStorageC((IPAddressStorage), (IPAddress.Value));
				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.WriteId = 1;
				UsedExp.State.Reg2.bit.Some  = 1; //some load


}

extern "C" void	  SetPar039(unsigned long val)
{

if(!(password_state))
{
	return;
}

//printfpd("\n\r par034 : %d", Par034);
//printfpd("val : %d", val);

if(Par034 == val)
{}
else
{
//printfp("\n\r .........return!");
 return;
}

WebPassword.Value = val;
WebPassword.ChangingValue = val;
UsedExp.State.Reg2.bit.WriteId = 1;
UsedExp.State.Reg2.bit.Some = 1;

     dev1.pum100s1.WebPasswordr0 = 	(unsigned)WebPassword.Value;
	 dev1.pum100s1.WebPasswordr1 = 	(unsigned)WebPassword.Value>>8;
	 dev1.pum100s1.WebPasswordr2 = 	(unsigned)WebPassword.Value>>16;
	 dev1.pum100s1.WebPasswordr3 = 	(unsigned)WebPassword.Value>>24;


//printfpd("\n\r par039 : %d", val);
}












/*
extern "C"  char * GetPar02b()
{
 SatTF.MakeResultStrV();
//Par014 =  SatTF.Value;
return SatTF.pResultStr;
}//0x87654321;}

 

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
  break;
  }
}

  */




















//_____________________________________________________________







unsigned long  AD7Val;
extern "C" void	  SetAD7Val(unsigned long val){AD7Val = val;}
extern "C" unsigned  GetAD7Val(){return AD7Val;}//0x87654321;}

#define LENGTH_CODE (5)
#define WEB_PARAMS_QUANTITY	(0x3f)
#define WRONG_CODE (0x99999)

class Web_prm
{
public:
char code[LENGTH_CODE];
//void target(unsigned long, float);

//unsigned long CheckCode(char *);

};

void target(unsigned long num, float par)
{
switch (num)
{
case 0:  SetPar000(par); break;
case 1:  SetPar001(par); break;
case 2:  SetPar002(par); break;
case 3:  SetPar003(par); break;
case 4:  SetPar004(par); break;
case 5:  SetPar005(par); break;
case 6:  SetPar006(par); break;
case 7:  SetPar007(par); break;
case 8:  SetPar008(par); break;
case 9:                   break;
case 0xa:  SetPar00a(par); break;
case 0xb:  SetPar00b(par); break;
case 0xc:  SetPar00c(par); break;
case 0xd:  SetPar00d(par); break;
case 0x10:  SetPar010(par); break;
case 0x14:    SetPar014(par); break;	  //
case 0x16:    SetPar016(par); break;	  //
case 0x19:    SetPar019(par); break;
case 0x1a:    SetPar01a(par); break;
case 0x1b:    SetPar01b(par); break;   //unlock timer
case 0x1c:    SetPar01c(par); break;  //processing offset
case 0x27:    SetPar027(par); break;
case 0x2b:    SetPar02b(par); break;	//start event
case 0x2e:    SetPar02e(par); break;
case 0x2f:    SetPar02f(par); break;
case 0x30:    SetPar030(par); break;
case 0x31:    SetPar031(par); break;
case 0x32:    SetPar032(par); break;
case 0x33:    SetPar033(par); break;
case 0x34:    SetPar034(par); break;
case 0x35:    SetPar035(par); break;
case 0x36:    SetPar036(par); break;
case 0x37:    SetPar037(par); break;
case 0x38:    SetPar038(par); break;
case 0x39:    SetPar039(par); break;



//do not need case 0x1e:    SetPar01e(par); break;  //freq offset


//case 0x21:    SetPar021(par); break;
//case 0x22:    SetPar022(par); break;




default : break;
};

}

Web_prm web_prm[WEB_PARAMS_QUANTITY];


unsigned long CheckCode(char * buf)
{
unsigned long i;
   for(i = 0; i < WEB_PARAMS_QUANTITY; i++)
   {
   if (strncmp(buf, web_prm[i].code, (LENGTH_CODE-1)) == 0) 
   	{
   //	printfpd("< checkcode : %d >", i);
   return i;
   }
   }
  return WRONG_CODE;
}

void Init_web_prm(void)
{

strcpy(web_prm[0].code,"000=");
strcpy(web_prm[1].code,"001=");
strcpy(web_prm[2].code,"002=");
strcpy(web_prm[3].code,"003=");
strcpy(web_prm[4].code,"004=");
strcpy(web_prm[5].code,"005=");
strcpy(web_prm[6].code,"006=");
strcpy(web_prm[7].code,"007=");
strcpy(web_prm[8].code,"008=");
strcpy(web_prm[9].code,"009=");
strcpy(web_prm[10].code,"00a=");
strcpy(web_prm[11].code,"00b=");
strcpy(web_prm[12].code,"00c=");
strcpy(web_prm[13].code,"00d=");
strcpy(web_prm[14].code,"999=");	 //page config numpage = 1
strcpy(web_prm[15].code,"998=");	 //page update numpage = 5
strcpy(web_prm[16].code,"010=");	 //slave level
strcpy(web_prm[17].code,"011=");	 //external lock
strcpy(web_prm[18].code,"012=");	 //ext locck polarity
strcpy(web_prm[19].code,"013=");	 //alarm
strcpy(web_prm[20].code,"014=");	 //time frame low power
strcpy(web_prm[21].code,"015=");	  // low power
strcpy(web_prm[22].code,"016=");	   //satrate
strcpy(web_prm[23].code,"017=");	 //page index
strcpy(web_prm[24].code,"018=");	 //page custom
strcpy(web_prm[25].code,"019=");	 //analog filter
strcpy(web_prm[26].code,"01a=");	 //digital filter
strcpy(web_prm[27].code,"01b=");	 //unlock timer
strcpy(web_prm[28].code,"01c=");	  //processing offset
strcpy(web_prm[29].code,"01d=");	  //page indicationonstrcpy(web_prm[30].code,"01e=");	  //freq offset
strcpy(web_prm[31].code,"01f=");	  //channel delay
strcpy(web_prm[32].code,"020=");	  //IF-Balance
strcpy(web_prm[33].code,"021=");	  //IF down link
strcpy(web_prm[34].code,"022=");	  //IF up link
strcpy(web_prm[35].code,"023=");	   //system page
strcpy(web_prm[36].code,"024=");	   //xilinx file
strcpy(web_prm[37].code,"025=");	   //serial number
strcpy(web_prm[38].code,"026=");	   //access level 
strcpy(web_prm[39].code,"027=");	   //access code
strcpy(web_prm[40].code,"028=");	   //demo mode
strcpy(web_prm[41].code,"029=");
strcpy(web_prm[42].code,"02a=");		//log page
strcpy(web_prm[43].code,"02b=");	   //start event
strcpy(web_prm[44].code,"02c=");
strcpy(web_prm[45].code,"02d=");
strcpy(web_prm[46].code,"02e=");
strcpy(web_prm[47].code,"02f=");
strcpy(web_prm[48].code,"030=");	  //
strcpy(web_prm[49].code,"031=");	  //
strcpy(web_prm[50].code,"032=");	  //
strcpy(web_prm[51].code,"033=");	   //
strcpy(web_prm[52].code,"034=");	   //
strcpy(web_prm[53].code,"035=");	   //
strcpy(web_prm[54].code,"036=");	   // 
strcpy(web_prm[55].code,"037=");	   //
strcpy(web_prm[56].code,"038=");	   //
strcpy(web_prm[57].code,"039=");
strcpy(web_prm[58].code,"03a=");		//
strcpy(web_prm[59].code,"03b=");	   //
strcpy(web_prm[60].code,"03c=");
strcpy(web_prm[61].code,"03d=");
strcpy(web_prm[62].code,"03e=");
strcpy(web_prm[63].code,"03f=");


}


extern "C" void parse_page_index(char * buf)
{

char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;


//_______________________________________________8_	  //password
// if(!flag_have8)
 if(1)
 {
// printfp("...found 8...");
//tbuf = strchr(buf, '&');
//tif(buf) buf++;
//tif ((strncmp(buf, "008=", 4) == 0) ||  (strncmp(buf, "+08=", 4) == 0))
// ret = CheckCode(buf);
// if(ret != WRONG_CODE)
  if(1)
 {
//printfp("\n\rfound 008_2\n\r");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par8 = my_strtod(cp, &pEnd);
				  	SetPar008(par8);
				  //	target(ret,par8);
//printfpd(" 8: %ld",(unsigned long)par8);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
				}
  }
  }
//___________________________________________9		//operating enabled / disabled

//printfp(buf);

//printfp("\n\rbefore 009: ");
//printfp(buf);
//printfp("\n\r");


buf = strchr(buf, '&');
if(buf)
 buf++;


 // printfp("...found 9...");



}


extern "C" void parse_page_indication(char * buf)
{
}


extern "C" void parse_page_log(char * buf)
{

//printfp("\n\r start parse_page_log");

  char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;


//t buf = strchr(buf, '&');  //2b
//tif(buf) buf++;

//t ret = CheckCode(buf);
//t if(ret != WRONG_CODE)
 ret = 0x2b;
if(1)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }

//buf = strchr(buf, '&');  //2c
//if(buf) buf++;
//do not setted any



buf = strchr(buf, '&');  //2d
if(buf) buf++;
if (strncmp(buf, "02d=", 4) == 0)
 {
//printfp("\n\rfound 02d \n\r");
			par7 = 1;
			  SetPar02d(par7);
	 buf++;
}  
else
{
 // printfp("\n\r not found 02d");
  par7 = 0;
  SetPar02d(par7);
}

//printfp("\n\rfinish parse_page_log");
}

extern "C" void parse_page_system(char * buf)
{

char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;

//___________________________________________________
// checked before buf = strchr(buf, '&');  //24
//if(buf) buf++;		//xilinx
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //	xil
 if(buf) buf++;
 //buf = strchr(buf, '&');  //   prog
// if(buf) buf++;


//printfp("\n\r1>");
//printfp(buf);
//printfp("<1\n\r");

 buf = strchr(buf, '&');  //34	web password
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //39	web password2
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//printfp("\n\r2>");
//printfp(buf);
//printfp("<2\n\r");


 buf = strchr(buf, '&');  //35	y
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //36	y
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//printfp("\n\r>");
//printfp(buf);
//printfp("<\n\r");


 buf = strchr(buf, '&');  //37	y
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//printfp("\n\r3>");
//printfp(buf);
//printfp("<3\n\r");

 buf = strchr(buf, '&');  //38	y
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
	   //	 printfpd(" \n\r ip0 : %d", par0);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




//;;;;;;;;;;;;;;;;;;;;;;;;;
buf = strchr(buf, '&');  //25  serial number
if(buf) buf++;
//===========================================
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //2e	y
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //2f	month
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //30	d
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //31	 h
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //32	min
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 buf = strchr(buf, '&');  //33	s
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//=============================================
 buf = strchr(buf, '&');  //26	//access level
if(buf) buf++;
 buf = strchr(buf, '&');  //27
if(buf) buf++;

 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }

buf = strchr(buf, '&');

//printfp("\n\rbuf: \n\r ");
//printfp(buf);
//printfp("\n\r");

if(buf) buf++;
if (strncmp(buf, "028=", 4) == 0)
//ret = CheckCode(buf);
//if(ret != WRONG_COCO)
 {
//printfp("\n\rfound 028 \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			par7 = 1;
			  SetPar028(par7);
			//  target(ret,par7);

	 buf++;
}  
else
{
 // printfp("\n\r not found 028");
		 par7 = 0;
 //		  buf++;

//}
	   SetPar028(par7);
}

}

extern "C" void parse_page_custom(char * buf)
{

char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;

//___________________________________________________
//t buf = strchr(buf, '&');  //analog filter
//tif(buf) buf++;
//t ret = CheckCode(buf);
 ret = 0x19;
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//________________________________________________
 buf = strchr(buf, '&');  //digital filter
if(buf) buf++;
 ret = CheckCode(buf);

//printfpd("\n\r retdf :%d", ret);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
 //	  printfpd("\n\r cpdf :%c \n\r>", *cp);
 //	   printfp(cp);

    if (cp){
			par0 = my_strtod(cp, &pEnd);

		  //	if(par0)
			if((par0) && (par0 < 20) && (par0 != 10))
			{
			if(par0 > 10)  //10 do not used
			{
			par0--;
			}
			target(ret,par0 - 1);	//t140528
			}
	       }
 }
//________________________________________________
 buf = strchr(buf, '&');  //unlock timer
if(buf) buf++;
 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//________________________________________________
 buf = strchr(buf, '&');  //processing freq
if(buf) buf++;
 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
			target(ret,par0);	//t140528
	       }
 }
//________________________________________________

//printfp("\n\r before 0x1c");
//printfp(buf);

 buf = strchr(buf, '&');  //processing offset
if(buf) buf++;
 ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
    cp = strchr(buf, '=') + 1;
    if (cp){
			par0 = my_strtod(cp, &pEnd);
	// printfpd("\n\r par0 : %d", (unsigned long)par0);

			target(ret,par0);	//t140528
	       }
 }








}

  /*


extern "C" void parse_page_update(char * buf)
{
 char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;



//.....
buf++;
//__________________________________________________________________
buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "00b=", 4) == 0)	 //change programm
// ret = CheckCode(buf);
// if(ret != WRONG_CODE)


 {
//printfp("\n\rfound 00b \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			parb = 1;
		   	  SetPar00b(parb);
			//  target(ret,parb);

	buf = strchr(buf, '&');
if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 parb = 0;
 //		  buf++;

//}
	   SetPar00b(parb);
	  //  target(ret,parb);

}
//_____________________________________________________________________
//__________________________________________________________________
//buf = strchr(buf, '&');
//if(buf) buf++;
if (strncmp(buf, "00c=", 4) == 0) 	  //change xilinx
//ret = CheckCode(buf);
// if(ret != WRONG_CODE)


{
//printfp("\n\rfound 00c \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			parc = 1;
		   	  SetPar00c(parc);
		   //	    target(ret,parc);

   buf = strchr(buf, '&');
if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 parc = 0;
 //		  buf++;

//}
	   SetPar00c(parc);
	 //    target(ret,parc);

}
//_____________________________________________________________________
//__________________________________________________________________
//buf = strchr(buf, '&');
//if(buf) buf++;
if (strncmp(buf, "00d=", 4) == 0)	 //restart
//ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 {
//printfp("\n\rfound 00d \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			pard = 1;
		   	  SetPar00d(pard);
		   //	   target(ret,pard);

	 buf = strchr(buf, '&');
     if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 pard = 0;
 //		  buf++;

//}
	   SetPar00d(pard);
	 //   target(ret,pard);

}


}

*/

extern "C" void parse_page_update(char * buf)
{
 char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;
 unsigned char flag_have8 = 0;

 char *pEnd;
 char * keepbuf = buf;
buf++;
//__________________________________________________________________
buf = strchr(buf, '&');
if(buf) buf++;



if (strncmp(buf, "00d=", 4) == 0)	 //restart
 {
			pard = 1;
		   	  SetPar00d(pard);
	 buf = strchr(buf, '&');
     if(buf) buf++;

}  
else
{
		 pard = 0;
	   SetPar00d(pard);
}


}






extern "C" void httpd_set_device_params(char * buf, int* plen)
{

 char *cp;
 char *cp1;
 float par0, par1;
 float par2;
 float par3, par4, par5;
 float par6;
 unsigned char par7;
// float par8;
 double par8;
 unsigned char para;
 unsigned char parb;
 unsigned char parc;
 unsigned char pard;
 unsigned long ret;


  unsigned char flag_have8 = 0;
  unsigned char flag_have12 = 0;
  unsigned char flag_have14 = 0;
  unsigned char flag_have16 = 0;



 char *pEnd;
 char * keepbuf = buf;


/*
 unsigned len = *plen;
 while(len--)
 {

 }
 */

//printfp("\n\r");
//printfp(buf);
//printfp("\n\r");  
//t140528 if (strncmp(buf, "000=", 4) == 0)


//buf = strchr(buf, '&');
//if(buf) buf++;
ret = CheckCode(buf);

//printfpd("\n\r select page : %d", ret);

 if(ret != WRONG_CODE)
 {

  switch(ret)
  {
//  case	14:   page_number = 1;  break;	  //code 999
  case	0:   page_number = 1;  break;	  //code 0
//  case	15:   page_number = 5; parse_page_update(buf); return;	  //code 998
  case	9:   page_number = 5; parse_page_update(buf); return;	  //code 9
//  case	0x17: page_number = 0; parse_page_index(buf); return;	  //code 17
  case	0x8: page_number = 0; parse_page_index(buf); return;	  //code 17
 // case	0x18: page_number = 2; parse_page_custom(buf); return;	  //code 18
  case	0x19: page_number = 2; parse_page_custom(buf); return;	  //code 18
//  case	0x1d: page_number = 3; parse_page_indication(buf); return;	  //code 1d
  case	0x1e: page_number = 3; parse_page_indication(buf); return;	  //code 1d
//  case	0x23: page_number = 4; parse_page_system(buf); return;	  //code 1d
  case	0x24: page_number = 4; parse_page_system(buf); return;	  //code 1d
 // case	0x2a: page_number = 6; parse_page_log(buf); return;	  //code 1d
  case	0x2b: page_number = 6; parse_page_log(buf); return;	  //code 1d


  default : page_number = 0;
  }
//printfpd("\n\ret = %d ", ret);

//printfpd(" page_number %d \n\r", page_number);
           //     cp = strchr(buf, '=') + 1;
		   //	   	cp1 =	 strchr(buf, '.');
			 //  	*cp1 = 0; //temporary
            //    if (cp){
			//	printfp(cp);

                //    par0 = atof(cp);
			   //	    par0 = strtod(cp, &pEnd);
				//	par0 = my_strtod(cp, &pEnd);
				//t140528	SetPar000(par0);
			   //		target(ret,par0);	//t140528

//printfpd("\n\rd0:%d",(unsigned)par0);	//ok
//printfpdv("\n\rf0:%7.3f",(float)par0);
//printfpdv("\n\re0:%7.3lE",(unsigned)par0);

				 //	buf = cp;
			  //	}
		  //		  *cp1 = '.';
		   //		   if(cp1) cp1++;


			//	else
			  //	return;
}
//.....

//t buf = strchr(buf, '&');
//tif(buf) buf++;
//t ret = CheckCode(buf);

 if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 000");
                cp = strchr(buf, '=') + 1;
		   //	   	cp1 =	 strchr(buf, '.');
			 //  	*cp1 = 0; //temporary
                if (cp){
			//	printfp(cp);

                //    par0 = atof(cp);
			   //	    par0 = strtod(cp, &pEnd);
					par0 = my_strtod(cp, &pEnd);
				//t140528	SetPar000(par0);
					target(ret,par0);	//t140528

//printfpd("\n\rd0:%d",(unsigned)par0);	//ok
//printfpdv("\n\rf0:%7.3f",(float)par0);
//printfpdv("\n\re0:%7.3lE",(unsigned)par0);

				 //	buf = cp;
				}
		  //		  *cp1 = '.';
		   //		   if(cp1) cp1++;


			//	else
			  //	return;
}
//.....
  
buf = strchr(buf, '&');
if(buf) buf++;

//if (strncmp(buf, "001=", 4) == 0)
ret = CheckCode(buf);
 if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 001");
                cp = strchr(buf, '=') + 1;
                if (cp){
                  //  par1 = atoi(cp);
					par1 = my_strtod(cp, &pEnd);

				 //	SetPar001(par1);
					target(ret,par1);
			  //		SetAD7Val(par1);
//printfpd("\n\r 1: %d",par1);
					buf = cp;
				}
			 //	else
			 //	return;
}
//........

buf = strchr(buf, '&');
if(buf) buf++;
//if (strncmp(buf, "002=", 4) == 0)
ret = CheckCode(buf);
if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 002");
                cp = strchr(buf, '=') + 1;
                if (cp){
                //    par2 = atoi(cp);
				   par2 = my_strtod(cp, &pEnd);

				   //	SetPar002(par2);
					target(ret,par2);

//printfpd("\n\r 2: %d",par2);
					buf = cp;
				}
		   //		else
			//	return;
}  

//.................
  /*
buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "003=", 4) == 0) {
//printfp("\n\rfound 003");
                cp = strchr(buf, '=') + 1;
                if (cp){
                //    par2 = atoi(cp);
					 par3 = my_strtod(cp, &pEnd);

					SetPar003(par3);
//printfpd("\n\r 3: %d",par3);
					buf = cp;
				}
		   //		else
			//	return;
}  
   */


//.................	   ________________________analog filter
 /*

buf = strchr(buf, '&');
if(buf) buf++;
//if (strncmp(buf, "004=", 4) == 0) 
 ret = CheckCode(buf);
 if(ret != WRONG_CODE)


{
printfp("\n\rfound 004");
                cp = strchr(buf, '=') + 1;
                if (cp){
               //     par2 = atoi(cp);
					 par4 = my_strtod(cp, &pEnd);

				//	SetPar004(par4);
					target(ret,par4);

printfpd("\n\r 4: %d",par4);
					buf = cp;
				}
		   //		else
			//	return;
}  

//.................

//_____________________________________________processing freq

buf = strchr(buf, '&');
if(buf) buf++;
//if (strncmp(buf, "005=", 4) == 0)
ret = CheckCode(buf);
if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 005");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par5 = my_strtod(cp, &pEnd);
				 //	SetPar005(par5);
					target(ret,par5);
//printfpd("\n\r 5: %09ld",par5);
					buf = cp;
				}
		   //		else
			//	return;
}  
   */
//.................

//printfp("\n\rbuf: \n\r ");
//printfp(buf);
//printfp("\n\r");
//____________________________________________________________________
//
buf = strchr(buf, '&');
if(buf) buf++;
//if (strncmp(buf, "006=", 4) == 0) 
ret = CheckCode(buf);
if(ret != WRONG_CODE)
{
//printfp("\n\rfound 006");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par6 = my_strtod(cp, &pEnd);
				 //	SetPar006(par6);
					target(ret,par6);


//printfpdv(" 6: %6.3f",par6);
					buf = cp;
				}
		   //		else
			//	return;
}  

//.................

buf = strchr(buf, '&');

//printfp("\n\rbuf: \n\r ");
//printfp(buf);
//printfp("\n\r");

if(buf) buf++;
if (strncmp(buf, "007=", 4) == 0)
//ret = CheckCode(buf);
//if(ret != WRONG_COCO)
 {
//printfp("\n\rfound 007 \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			par7 = 1;
			  SetPar007(par7);
			//  target(ret,par7);

	 buf++;
}  
else
{
 // printfp("\n\r not found 007");
		 par7 = 0;
 //		  buf++;

//}
	   SetPar007(par7);
	  //   target(ret,par7);

//}
//.................
//buf = strchr(buf, '&');
//if(buf) buf++;
//if (strncmp(buf, "008=", 4) == 0) 
/*
if ((strncmp(buf, "008=", 4) == 0) ||  (strncmp(buf, "+08=", 4) == 0))

//ret = CheckCode(buf);
//if(ret != WRONG_CODE)
 if(1)
{
flag_have8 = 1;	

*/ 
//--------------------------------------------
 //_________________________________________________________a  master /slave
//printfp("\n\rbefore 00a: ");
//printfp(buf);
//printfp("\n\r");



//buf = strchr(buf, '&');


//if(buf) buf++;

//if (strncmp(buf, "00a=", 4) == 0)
if ((strncmp(buf, "00a=", 4) == 0) ||  (strncmp(buf, "+0a=", 4) == 0))

{
flag_have8 = 1;	 


// ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 //{


//printfp("\n\rfound 00a_1\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'M'){
             //       par2 = atoi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }

	  //	 printfpd(" setpar00a %d " , para);
				  	SetPar00a(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
}

//.................




//---------------------------------------------


 
/*
printfp("\n\rfound 008_1\n\r");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par8 = my_strtod(cp, &pEnd);
//printfpd(" 8a: %d",(double)par8);

			   	 	SetPar008(par8);
			   //	 	target(ret,par8);

//printfpd(" 8: %ld",(unsigned long)par8);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
				  //	buf++; //t
				}

*/
		   //		else
			//	return;
//}  
//.................

}
//_______________________________________________8_	  //password
 if(!flag_have8)
 //if(1)
 {
//--------------------------------------
//_________________________________________________________a  master /slave
//printfp("\n\rbefore 00a: ");
//printfp(buf);
//printfp("\n\r");



buf = strchr(buf, '&');


if(buf) buf++;
if (strncmp(buf, "00a=", 4) == 0)

// ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 {


//printfp("\n\rfound 00a_2\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'M'){
             //       par2 = atoi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }

	 //	 printfpd(" setpar00a %d " , para);
				  	SetPar00a(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
}
} //flag
//.................




//--------------------------------------

/*
 printfp("...found 8...");
buf = strchr(buf, '&');
if(buf) buf++;
if ((strncmp(buf, "008=", 4) == 0) ||  (strncmp(buf, "+08=", 4) == 0))
// ret = CheckCode(buf);
// if(ret != WRONG_CODE)
  if(1)
 {
printfp("\n\rfound 008_2\n\r");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par8 = my_strtod(cp, &pEnd);
				  	SetPar008(par8);
				  //	target(ret,par8);
//printfpd(" 8: %ld",(unsigned long)par8);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
				}
  }

*/
 // }
//___________________________________________9		//operating enabled / disabled

//printfp(buf);

//printfp("\n\rbefore 009: ");
//printfp(buf);
//printfp("\n\r");
/*

buf = strchr(buf, '&');
if(buf)
 buf++;


  printfp("...found 9...");

*/
 /*	
//if (strncmp(buf, "009=", 4) == 0) 
 ret = CheckCode(buf);
 if(ret != WRONG_CODE)

{
//printfp("\n\rfound 009\n\r");
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
				 //	 par8 = my_strtod(cp, &pEnd);
				 //	SetPar008(par8);
//printfpd(" 8: %ld",(unsigned long)par8);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
		}
}
  */
//_________________________________________________________a  master /slave
//printfp("\n\rbefore 00a: ");
//printfp(buf);
//printfp("\n\r");

/*

buf = strchr(buf, '&');


if(buf) buf++;
if (strncmp(buf, "00a=", 4) == 0)

// ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 {


printfp("\n\rfound 00a\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'M'){
             //       par2 = atoi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }

		 printfpd(" setpar00a %d " , para);
				  	SetPar00a(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
				}
 */
//.................


//_________________________________________________________________slave level 010_
//printfp("\n\r010:");
//printfp(buf);
//printfp("\n\r");

buf = strchr(buf, '&');
if(buf) buf++;
//if (strncmp(buf, "002=", 4) == 0)
ret = CheckCode(buf);
if(ret != WRONG_CODE)
 {
//printfpd("\n\rret :  %d", ret);
                cp = strchr(buf, '=') + 1;
                if (cp){
                //    par2 = atoi(cp);
				   par2 = my_strtod(cp, &pEnd);

				   //	SetPar002(par2);
					target(ret,par2);

//printfpd(" try set slave level: %d",par2);
					buf = cp;
				}
		   //		else
			//	return;
}  

//_________________________________________________________________010
//_________________________________________________011 external lock

//printfp("\n\rbefore 011: \n\r");
//printfp(buf);
//printfp("\n\r");



 buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "011=", 4) == 0)
//ret = CheckCode(buf);
//if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 007 \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			par7 = 1;
			  SetPar011(par7);
			//  target(ret,par7);

	 buf++;
}  
else
{
//  printfp("\n\r not found 007");
		 par7 = 0;
 //		  buf++;

//}
	   SetPar011(par7);
	  //   target(ret,par7);


//===========================================================		//normal /invert
if ((strncmp(buf, "012=", 4) == 0) ||  (strncmp(buf, "+12=", 4) == 0))

//ret = CheckCode(buf);
//if(ret != WRONG_CODE)
 if(1)
{
flag_have12 = 1;
//-----------------------------------------
//printfp("\n\rfound 012\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'N'){
             //       par2 = atoi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }

	   //	 printfpd(" setpar012_1 %d " , para);
				  	SetPar012(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;




//-----------------------------------------
}  
//===========================================================

}	 //temporary end - hier can be next param

if(!flag_have12)
{
 buf = strchr(buf, '&');
if(buf) buf++;

if ((strncmp(buf, "012=", 4) == 0) ||  (strncmp(buf, "+12=", 4) == 0))
{
//printfp("\n\rfound 012_2\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'N'){
             //       par2 = = oi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }

	   //	 printfpd(" setpar012_2 %d " , para);
				  	SetPar012(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;




//-----------------------------------------
 } 
}

//printfp("\n\rbefore 013: \n\r>");
//printfp(buf);
//printfp("<\n\r");

flag_have14 = 0;


 buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "013=", 4) == 0)
//ret = CheckCode(buf);
//if(ret != WRONG_CODE)
 {
//printfp("\n\rfound 013 \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			par7 = 1;
			  SetPar013(par7);
			//  target(ret,par7);

	 buf++;
}  
else
{
 // printfp("\n\r not found 013");
		 par7 = 0;
 //		  buf++;

//}
	   SetPar013(par7);
	  //   target(ret,par7);
//=====================================================
  
//if (strncmp(buf, "006=", 4) == 0) 


//printfp("\n\rbefore 014: \n\r");
//printfp(buf);
//printfp("\n\r");


ret = CheckCode(buf);
if(ret != WRONG_CODE)
{

flag_have14 = 1;

//printfpd("\n\rfound 014_1 %d ", ret);
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par7 = my_strtod(cp, &pEnd);
				 //	SetPar006(par6);

				// printfpd("\n\r>%c", *(buf+1));
				//  printfpd("%c", *(buf+2));
				//    printfpd("%c", *(buf+3));
 				//	 printfpd("%c", *(buf+4));

				  //   printfpd("%c<\n\r", *(buf+5));

					 if((*(buf+5) == '&') || (*(buf+6) == '&'))
					 {
					target(ret,par7);
					  }
	
   //  printfpd(" 7: %d",par7);
					buf = cp;
				}
		   //		else
			//	return;
}  
 

//=====================================================


	  
} //temporary	 only this hier  
 	
if(!flag_have14)
{

buf = strchr(buf, '&');
if(buf) buf++;
ret = CheckCode(buf);
if(ret != WRONG_CODE)
{
//printfp("\n\rfound 014_2");
//printfpd("\n\rfound 014_2 %d ", ret);

                  cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par7 = my_strtod(cp, &pEnd);
				 //	SetPar006(par6);

				// printfpd("\n\r>%c", *(buf+1));
				//  printfpd("%c", *(buf+2));
				//    printfpd("%c", *(buf+3));
 				//	 printfpd("%c", *(buf+4));

				  //   printfpd("%c<\n\r", *(buf+5));

					 if((*(buf+5) == '&') || (*(buf+6) == '&'))
					 {
					target(ret,par7);
					  }

//printfpd(" 6: %d",par6);
					buf = cp;
				}
		   //		else
			//	return;
}  

}
  
//____________________________________________________________
buf = strchr(buf, '&');

 /*
printfp("\n\r>>>>>>>>>\n\r");
printfp(buf);
 */

if(buf) buf++;
  /*
if (strncmp(buf, "015=", 4) == 0)
//ret = CheckCode(buf);
//if(ret != WRONG_CODE)
 {
printfp("\n\rfound 015 \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			par7 = 1;
			  SetPar015(par7);
			//  target(ret,par7);

	 buf++;
}  
else
{

 // printfp("\n\r not found 015");
		 par7 = 0;
 //		  buf++;

//}
	   SetPar015(par7);
   */
ret = CheckCode(buf);	// 
if(ret != WRONG_CODE)
{

//flag_have16 = 1;
//printfpd("\n\rfound 016_1 %d ", ret);
                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par6 = my_strtod(cp, &pEnd);
				 //	SetPar006(par6);
					target(ret,par6);


//printfpdv(" 6: %6.3f",par6);
					buf = cp;
				}
		   //		else
			//	return;
}  


//} //temporary hier 15 only

//if(!flag_have16)
//{

buf = strchr(buf, '&');
if(buf) buf++;
ret = CheckCode(buf);
if(ret != WRONG_CODE)
{
//printfp("\n\rfound 016_2 ");

                cp = strchr(buf, '=') + 1;
                if (cp){
             //       par2 = atoi(cp);
					 par6 = my_strtod(cp, &pEnd);
				 //	SetPar006(par6);
			//	 printfpd("par6 %d", (unsigned long)par6);
			//	  printfpd(" ret %d", (unsigned long)ret);

					target(ret,(unsigned long)par6);


//printfpdv(" 6: %6.3f",par6);
					buf = cp;
				}
		   //		else
			//	return;
//}  

}


//____________________________________________________________
 



//}






 /* 140530

//_________________________________________________________a
buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "00a=", 4) == 0)

// ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 {
//printfp("\n\rfound 00a\n\r");
                cp = strchr(buf, '=') + 1;
			 //	printfpd("->%c", *cp);
                if (*cp == 'M'){
             //       par2 = atoi(cp);
					 para = 0;//my_strtod(cp, &pEnd);
					 }
					 else
					 {
					  para = 1;
					 }
				  	SetPar00a(para);
				  //	target(ret,para);

//printfpd(" a: %ld",(unsigned long)para);
//printfpd(" last: %d",((unsigned long)par8 % 1000));

					buf = cp;
				}

//.................
//__________________________________________________________________
buf = strchr(buf, '&');
if(buf) buf++;
if (strncmp(buf, "00b=", 4) == 0)
// ret = CheckCode(buf);
// if(ret != WRONG_CODE)


 {
//printfp("\n\rfound 00b \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			parb = 1;
		   	  SetPar00b(parb);
			//  target(ret,parb);

	buf = strchr(buf, '&');
if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 parb = 0;
 //		  buf++;

//}
	   SetPar00b(parb);
	  //  target(ret,parb);

}
//_____________________________________________________________________
//__________________________________________________________________
//buf = strchr(buf, '&');
//if(buf) buf++;
if (strncmp(buf, "00c=", 4) == 0) 
//ret = CheckCode(buf);
// if(ret != WRONG_CODE)


{
//printfp("\n\rfound 00c \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			parc = 1;
		   	  SetPar00c(parc);
		   //	    target(ret,parc);

   buf = strchr(buf, '&');
if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 parc = 0;
 //		  buf++;

//}
	   SetPar00c(parc);
	 //    target(ret,parc);

}
//_____________________________________________________________________
//__________________________________________________________________
//buf = strchr(buf, '&');
//if(buf) buf++;
if (strncmp(buf, "00d=", 4) == 0)
//ret = CheckCode(buf);
// if(ret != WRONG_CODE)

 {
//printfp("\n\rfound 00d \n\r");
            //    cp = strchr(buf, '=') + 1;
            //    if (cp){
             //       par2 = atoi(cp);
				//	 par6 = my_strtod(cp, &pEnd);
				//	SetPar006(par6);
//printfpdv(" 6: %6.3f",par6);
			  //		buf = cp;

			  //	}
		   	  //	else
			//	return;
			pard = 1;
		   	  SetPar00d(pard);
		   //	   target(ret,pard);

	 buf = strchr(buf, '&');
     if(buf) buf++;

}  
else
{
//  printfp("\n\r not found 007");
		 pard = 0;
 //		  buf++;

//}
	   SetPar00d(pard);
	 //   target(ret,pard);

}
//_____________________________________________________________________

	*/

}

//------------------------------------------------------------------------------





//for example
/*
unsigned long  AD7Val;
extern "C" void	  SetAD7Val(unsigned long val){AD7Val = val;}
extern "C" unsigned  GetAD7Val(){return AD7Val;}//0x87654321;}
unsigned long  Par000;
extern "C" void	  SetPar000(unsigned long val){Par000 = val;}
extern "C" unsigned  GetPar000(){return Par000;}//0x87654321;}
 */
unsigned  GetTempVal(){return 12;}
#define TCPTxDataCount (100)
#define		TCP_TX_BUF (0x1000000l)

//static void InsertDynamicValues()
extern "C" void InsertDynamicValues(char *Key, int len)
{
 // char *Key;

// printfp("\n\r start InsertDynamicValues");
  char NewKey[32];
  int i;

  /*
printfp("\n\rInsertDynamicValues");
printfpd(" len = %d", len);
 
char * workKey = Key;

for(unsigned prc = 0; prc < len; prc++)
{
if(!(prc % 16)) printfp("\n\r");
printfpd("%c", *workKey++);
}
  */
//  unsigned char  flaga = 1;

  for (i = 0; i < 32; i++)
  {NewKey[i] = '0';}

 
  if (TCPTxDataCount < 4) return;                // there can't be any special string
 // Key = (char *)TCP_TX_BUF;
//  for (i = 0; i < TCPTxDataCount - 3; i++)
  for (i = 0; i < len; i++)
  {

 //______________________________________
 /*
 if(password_state)
{
 	if (*Key 	   == 'b')
       (*(Key + 1) == 'g')
    if (*(Key + 2) == 'c')
    if (*(Key + 3) == 'o')    
    if (*(Key + 4) == 'l')
   	if (*(Key + 5) == 'o')
  	if (*(Key + 6) == 'r')
    {
        sprintf(NewKey, "%s", "00FF00");  // insert AD converter value
        memcpy((Key+9), NewKey, 6);               // channel 7 (P6.7)
    }

//   printfp(Key);
}
	*/

 if(!(password_state))
{
 //printfp("\n\rfinish InsertDynamicValues - no password");

	return;
}


//_______________________________________


    if (*(Key - 3) == 'n')		  //name=" 
    {
    if (*(Key - 2) == 'a')		  //name=" 
    {
    if (*(Key - 1) == 'm')		  //name=" 
    {
    if (*Key == 'e')
	{
    if (*(Key + 1) == '=')
	{
    if (*(Key + 2) == '"')
	{
    if (*(Key + 3) == '0')  
    {  
    if (*(Key + 4) == '0')
	{
   //	  printfp("\n\r start InsertDynamicValues 0");
	//  return; //for test

	if (*(Key + 5) == '0')
       {
   //	   printfp("\n\r Find Sys Delay!\n\r");
        sprintf(NewKey, "%6.3f", GetPar000());  // insert AD converter value
        memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
       }

    if (*(Key + 5) == '1')
       {
       	  sprintf(NewKey, "%6d",(unsigned long)GetPar001());  // insert AD converter value
//        sprintf(NewKey, "%08d", GetAD7Val());  // insert AD converter value
        memcpy((Key+15), NewKey, 6);               // channel 7 (P6.7)
       }
	if (*(Key + 5) == '2')
       {
        sprintf(NewKey, "%6d", (unsigned long)GetPar002());  // insert AD converter value
        memcpy((Key+15), NewKey, 6);               // channel 7 (P6.7)
       }
	if (*(Key + 5) == '3')
       {
        sprintf(NewKey, "%2d", (unsigned long)GetPar003());  // insert AD converter value
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
       }
	if (*(Key + 5) == '4')
       {
        sprintf(NewKey, "%2d", (unsigned long)GetPar004());  // insert AD converter value
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
       }
    if (*(Key + 5) == '5')
       {
        sprintf(NewKey, "%9d", (unsigned long)GetPar005());  // insert AD converter value
        memcpy((Key+15), NewKey, 9);               // channel 7 (P6.7)
       }
    if (*(Key + 5) == '6')
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
       sprintf(NewKey, "% 4.1f", GetPar006());  // insert AD converter value
         memcpy((Key+15), NewKey, 5);               // channel 7 (P6.7)
       }
   if (*(Key + 5) == '7')
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
		if (GetPar007())	 //sattestmode
		{
        sprintf(NewKey, "%s", "checked");  // insert AD converter value
         memcpy((Key - 11), NewKey, 7);               // channel 7 (P6.7)

 		 }
       }
  	if (*(Key + 5) == '8')
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
   //		if (GetPar008())
	 //	{
    //     sprintf(NewKey, "%10d", (unsigned long)GetPar008());  // insert AD converter value
 //	    sprintf(NewKey, "%10d",0);  // insert AD converter value
 //       memcpy((Key+15), NewKey, 10);               // channel 7 (P6.7)
//need set wrong 		sprintf(NewKey, "%8d", (unsigned)WebPassword.Value);  
       sprintf(NewKey, "%8d", (unsigned)0);    
        memcpy((Key+15), NewKey, 8);                
   //    }

	 //	 }
       }
		if (*(Key + 5) == '9')
       {
  //	   printfp("\n\r try prin enabled...");
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
   //		if (GetPar008())
	 //	{
    //     sprintf(NewKey, "%10d", (unsigned long)GetPar008());  // insert AD converter value
  	    sprintf(NewKey, "%s"," Enabled");  // insert AD converter value
        memcpy((Key+15), NewKey, 8);               // channel 7 (P6.7)
	 //	 }
       }

  		if (*(Key + 5) == 'a')
       {
//    if(flaga)
//    {
//	   flaga = 0;
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
 		 sprintf(NewKey, "%s", "checked");
  
  
 // printfpd("f:%d",flaga);
   /*
  printfpd("\n\r>%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c",*(Key + 20));
  printfpd("%c",*(Key + 21));
  printfpd("%c",*(Key + 22));
  printfpd("%c",*(Key + 23));
  printfpd("%c",*(Key + 24));
  printfpd("%c",*(Key + 25));
  printfpd("%c",*(Key + 26));
  printfpd("%c",*(Key + 27));
  printfpd("%c",*(Key + 28));

	  
		printfp("\n\r operate para: ");
  */
		if (GetPar00a())
		{
      //  sprintf(NewKey, "%s", "checked");  // insert AD converter value

  //       printfp(" 1 \n\r");

		if(*(Key + 15) == 'S')
		         memcpy((Key + 22), NewKey, 7);               // channel 7 (P6.7)
		if(*(Key + 15) == 'M')
		         memcpy((Key + 22), "       ", 7);               // channel 7 (P6.7)

      //	 memcpy((Key + 16 + 66), "       ", 7);  

 		 }
		 else
		 {
   //		    printfp(" 0 \n\r");


	   //	  memcpy((Key + 23), "       ", 7);  
	 //	 memcpy((Key + 16 + 66), NewKey, 7); 
	 
		if(*(Key + 15) == 'M')
		         memcpy((Key + 22), NewKey, 7);               // channel 7 (P6.7)
		if(*(Key + 15) == 'S')
		         memcpy((Key + 22), "       ", 7);               // channel 7 (P6.7)
	 
	     
		 }
 /*
 printfpd("\n\r>%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c",*(Key + 20));
  printfpd("%c",*(Key + 21));
  printfpd("%c",*(Key + 22));
  printfpd("%c",*(Key + 23));
  printfpd("%c",*(Key + 24));
  printfpd("%c",*(Key + 25));
  printfpd("%c",*(Key + 26));
  printfpd("%c",*(Key + 27));
  printfpd("%c",*(Key + 28));
 */


//	 }
}	//==a
 

		  /*
         else if (*(Key + 2) == 'A')
         {
          sprintf(NewKey, "%3u", GetTempVal()); // insert AD converter value
           memcpy(Key, NewKey, 3);               // channel 10 (temp.-diode)
         }
		 */
	 } //	==0

if (*(Key + 4) == '1')
	{
	//  printfp("\n\r start InsertDynamicValues 1");
	 //    return; //for test



	if (*(Key + 5) == '0')	 //010
       {
        sprintf(NewKey, "%2d", GetPar010());  // insert AD converter value
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
       }

    if (*(Key + 5) == '1')  //011
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
		if (GetPar011())	 //satextlock
		{
        sprintf(NewKey, "%s", "checked");  // insert AD converter value
         memcpy((Key - 11), NewKey, 7);               // channel 7 (P6.7)

 		 }
       }

    if (*(Key + 5) == '2')  //012
       {
 		 sprintf(NewKey, "%s", "checked");
  
  
 // printfpd("f:%d",flaga);
   	/*
  printfpd("\n\r>%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c",*(Key + 20));
  printfpd("%c",*(Key + 21));
  printfpd("%c",*(Key + 22));
  printfpd("%c",*(Key + 23));
  printfpd("%c",*(Key + 24));
  printfpd("%c",*(Key + 25));
  printfpd("%c",*(Key + 26));
  printfpd("%c",*(Key + 27));
  printfpd("%c",*(Key + 28));

	  
		printfp("\n\r operate par012: ");
  		 */
		if (GetPar012())
		{
      //  sprintf(NewKey, "%s", "checked");  // insert AD converter value

  //       printfp(" 1 \n\r");

		if(*(Key + 15) == 'I')
		         memcpy((Key + 22), NewKey, 7);               // channel 7 (P6.7)
		if(*(Key + 15) == 'N')
		         memcpy((Key + 22), "       ", 7);               // channel 7 (P6.7)

      //	 memcpy((Key + 16 + 66), "       ", 7);  

 		 }
		 else
		 {
   //		    printfp(" 0 \n\r");


	   //	  memcpy((Key + 23), "       ", 7);  
	 //	 memcpy((Key + 16 + 66), NewKey, 7); 
	 
		if(*(Key + 15) == 'N')
		         memcpy((Key + 22), NewKey, 7);               // channel 7 (P6.7)
		if(*(Key + 15) == 'I')
		         memcpy((Key + 22), "       ", 7);               // chchnel 7 (P6.7)
	 
	     
		 }
       }
	      if (*(Key + 5) == '3')  //013 alarm
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
		if (GetPar013())	 //satsound
		{
         sprintf(NewKey, "%s", "checked");  // insert AD converter value
         memcpy((Key - 11), NewKey, 7);               // channel 7 (P6.7)
		 }
       }

	   	
		      if (*(Key + 5) == '4')  //014 time frame
			  // if (*(Key + 6) == '_')
       {
	//	 printfp("\n\r14:\n\r");
	  //	 printfp((char *)*(Key + 14));
	  /*
  printfpd("\n\r_>%c",*(Key + 0));
  printfpd("%c",*(Key + 1));
  printfpd("%c",*(Key + 2));
  printfpd("%c",*(Key + 3));
  printfpd("%c",*(Key + 4));
  printfpd("%c",*(Key + 5));
  printfpd("%c",*(Key + 6));
  printfpd("%c",*(Key + 7));
  printfpd("%c",*(Key + 8));
  printfpd("%c",*(Key + 9));
  printfpd("%c",*(Key + 10));
  printfpd("%c",*(Key + 11));
  printfpd("%c",*(Key + 12));
  printfpd("%c",*(Key + 13));
  printfpd("%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c",*(Key + 20));
  printfpd("%c",*(Key + 21));
  printfpd("%c",*(Key + 22));
  printfpd("%c",*(Key + 23));
  printfpd("%c",*(Key + 24));
  printfpd("%c",*(Key + 25));
  printfpd("%c",*(Key + 26));
  printfpd("%c",*(Key + 27));
  printfpd("%c",*(Key + 28));
  printfpd("%c",*(Key + 29));
  printfpd("%c",*(Key + 30));
  printfpd("%c",*(Key + 31));
  printfpd("%c",*(Key + 32));
  printfpd("%c",*(Key + 33));
  printfpd("%c",*(Key + 34));
  printfpd("%c",*(Key + 35));
  printfpd("%c",*(Key + 36));
  printfpd("%c",*(Key + 37));
  printfpd("%c",*(Key + 38));

 printfp("\n\r :");
 printfp(GetPar014());

  */

	      sprintf(NewKey, "%s", GetPar014());  //


          memcpy((Key+39), NewKey, 16);  
	   }

     if (*(Key + 5) == '5')  //013 satlowp
       {
//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
		if (GetPar015())	 //satlowp
		{
         sprintf(NewKey, "%s", "checked");  // insert AD converter value
         memcpy((Key - 11), NewKey, 7);               // channel 7 (P6.7)
		 }
       }

	  if (*(Key + 5) == '6')	 //016
       {

//printfpd("\n\r.......symbol rate : %5d", GetPar016());
        sprintf(NewKey, "%05d", GetPar016());  // symbol rate
        memcpy((Key+15), NewKey, 5);               // channel 7 (P6.7)
       }

 		if (*(Key + 5) == '9')	 //019
       {
        sprintf(NewKey, "%2d", GetPar019());  // analog filter
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
	   //	   SatTF.MakeResultStrV();
		 // sprintf(NewKey, "%s", SatTF.pResultStr));
        //  memcpy((Key+15), NewKey, 15);               // channel 7 (P6.7)


       }
		if (*(Key + 5) == 'a')	 //01a
       {
	   SatDF.MakeResultStrV();

   //     sprintf(NewKey, "%2d", GetPar01a());  // digital filter
   		sprintf(NewKey, "%s", SatDF.pResultStr);
        memcpy((Key+39), NewKey, 3);               // channel 7 (P6.7)
       }

		if (*(Key + 5) == 'b')	 //01b
       {
        sprintf(NewKey, "%2d", GetPar01b());  // unlock timer
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
       }

	   	if (*(Key + 5) == 'c')  	 //01c processing offset
       {
  //		printfpd("get1c: %5d", GetPar01c());

        sprintf(NewKey, "%5d", GetPar01c());  // 
        memcpy((Key+15), NewKey, 5);               // channel 7 (P6.7)
       }
 //____________________indication
   	if (*(Key + 5) == 'e')  	 //01e freq offset
       {
  //		printfpd("get1c: %5d", GetPar01c());
//        sprintf(NewKey, "%5d", GetPar01c());  // 
  //      memcpy((Key+15), NewKey, 5);               // channel 7 (P6.7)
		    sprintf(NewKey, "%s", GetPar01e());  // 
            memcpy((Key+15), NewKey, 4);  

       }

	if (*(Key + 5) == 'f')  	 //01f channel delay
       {
		    sprintf(NewKey, "%s", GetPar01f());  //
            memcpy((Key+15), NewKey, 6);  

       }

	} // ==1
if (*(Key + 4) == '2')
	{
	// printfp("\n\r start InsertDynamicValues 2 \n\r>>");
	// printfp(Key-5);
   //	 printfp("\n\r<<");

  //	  return; //for test


	if (*(Key + 5) == '0')	 //020
       {
	 //	printfp("\n\r <size 20>:");	return;

	 //	printfpd(" %d : ",sizeof(GetPar020()));

	 //  	printfp(GetPar020());
	   	
	   	sprintf(NewKey, "%3d", (signed long)SatGet3.Value);  //	iF-balance
        memcpy((Key+15), NewKey, 3);  
       }
       						    
        if (*(Key + 5) == '1')	 //021
       {
	//	printfp("\n\r <size 21>:");	return;

        sprintf(NewKey, "%s", GetPar021());  // 	iF-down link
        memcpy((Key+15), NewKey, 9);               // channel 7 (P6.7)
       }

    if (*(Key + 5) == '2')	 //021
       {
	 //		printfp("\n\r <size 22>:");	return;


        sprintf(NewKey, "%s", GetPar022());  // 	iF-up link
        memcpy((Key+15), NewKey, 9);               // channel 7 (P6.7)
       }

	  if (*(Key + 5) == '4')	 //024	 //xilinx name
       {
	  //	printfp("\n\r <size 24>:");	return;

   //     sprintf(NewKey, "%s", GetPar022());  // 	

        memcpy((Key+15), XilFileData.Value, 24);               // channel 7 (P6.7)
       }

	  if (*(Key + 5) == 'G')	 //024	 //xilinx name
       {
   //	   printfp("\n\r <size 2g>:");	return;

   //     sprintf(NewKey, "%s", GetPar022());  // 	
        memcpy((Key+15), &theAnyStrings.cVersion[0], 24);               // channel 7 (P6.7)
       }



	   if (*(Key + 5) == '5')	 //025	 //serial number
       {
	//      printfp("\n\r <size 25>:");	return;

	//   printfpd("\n\r s/n : %d", (unsigned)DevId.Value);
        sprintf(NewKey, "%5d", (unsigned)DevId.Value);  //    
        memcpy((Key+15), NewKey, 5);               // channel 7 (P6.7)
       }

	   if (*(Key + 5) == '6')	 //026	 //access level
       {
	  //    printfp("\n\r <size 26>:");	return;

        sprintf(NewKey, "%1d", (unsigned)SatALev.Value);  //    
        memcpy((Key+15), NewKey, 1);               // channel 7 (P6.7)
       }

	   if (*(Key + 5) == '7')	 //027	 //	access code
       {
	 //    printfp("\n\r <size 27>:");	return;

     //   sprintf(NewKey, "%1d", (unsigned)SatALev.Value);  //    
        memcpy((Key+15), "........", 8);               // channel 7 (P6.7)
       }

       if (*(Key + 5) == '8')  //028 demo mode
       {
	 //    printfp("\n\r <size 28>:");	return;

//        sprintf(NewKey, "% 5.3f", GetPar006());  // insert AD converter value
//         memcpy((Key+15), NewKey, 7);               // channel 7 (P6.7)
		if (GetPar028())	 //satlowp
		{
         sprintf(NewKey, "%s", "checked");  // insert AD converter value
         memcpy((Key - 11), NewKey, 7);               // channel 7 (P6.7)
		 }
       }

       if (*(Key + 5) == '9')  //028 timeout of demo mode
       {
 //	     printfp("\n\r <size 29>:");	return;

 		sprintf(NewKey, "%8d", (unsigned)SatACnt.Value);  //    
        memcpy((Key+15), NewKey, 8);               // channel 7 (P6.7)
		 
       }

       if (*(Key + 5) == 'b')  //02b start event
       {
	  //   printfp("\n\r <size 2b>:");
	  //     printfpd ("%3d:",(unsigned)start_event);		

 		sprintf(NewKey, "%3d", (unsigned)start_event);  //    
        memcpy((Key+15), NewKey, 3);               // channel 7 (P6.7)
		 
       }

	    if (*(Key + 5) == 'c')  //02c log
			  // if (*(Key + 6) == '_')
       {
   //		   printfp("\n\r <size 2c>:");	return;


	//	 printfp("\n\r14:\n\r");
	  //	 printfp((char *)*(Key + 14));
	/*  
  printfpd("\n\r_>%c",*(Key + 0));
  printfpd("%c",*(Key + 1));
  printfpd("%c",*(Key + 2));
  printfpd("%c",*(Key + 3));
  printfpd("%c",*(Key + 4));
  printfpd("%c",*(Key + 5));
  printfpd("%c",*(Key + 6));
  printfpd("%c",*(Key + 7));
  printfpd("%c",*(Key + 8));
  printfpd("%c",*(Key + 9));
  printfpd("%c",*(Key + 10));
  printfpd("%c",*(Key + 11));
  printfpd("%c",*(Key + 12));
  printfpd("%c",*(Key + 13));
  printfpd("%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c",*(Key + 20));
  printfpd("%c",*(Key + 21));
  printfpd("%c",*(Key + 22));
  printfpd("%c",*(Key + 23));
  printfpd("%c",*(Key + 24));
  printfpd("%c",*(Key + 25));
  printfpd("%c",*(Key + 26));
  printfpd("%c",*(Key + 27));
  printfpd("%c",*(Key + 28));
  printfpd("%c",*(Key + 29));
  printfpd("%c",*(Key + 30));
  printfpd("%c",*(Key + 31));
  printfpd("%c",*(Key + 32));
  printfpd("%c",*(Key + 33));
  printfpd("%c",*(Key + 34));
  printfpd("%c",*(Key + 35));
  printfpd("%c",*(Key + 36));
  printfpd("%c",*(Key + 37));
  printfpd("%c",*(Key + 38));
   */
// printfp("\n\r :");
// printfpd("\n\r start event : %d",start_event);

   Key += 39;

 // for(unsigned j = start_event; j < j + EVENTS_IN_LIST; j++ )
  for(unsigned j = start_event; j < start_event+2; j++)
 //for(unsigned j = start_event; j < start_event+3; j++ )
//ok for(unsigned j = 1; j < 3; j++ )
// for(unsigned j = 1; j < 3; j++ )
//for(unsigned j = 1; j < EVENTS_IN_LIST; j++ )
 {

 //_____________________________________________________
   /*
  printfpd("\n\r_>%c",*(Key + 0));
  printfpd("%c",*(Key + 1));
  printfpd("%c",*(Key + 2));
  printfpd("%c",*(Key + 3));
  printfpd("%c",*(Key + 4));
  printfpd("%c",*(Key + 5));
  printfpd("%c",*(Key + 6));
  printfpd("%c",*(Key + 7));
  printfpd("%c",*(Key + 8));
  printfpd("%c",*(Key + 9));
  printfpd("%c",*(Key + 10));
  printfpd("%c",*(Key + 11));
  printfpd("%c",*(Key + 12));
  printfpd("%c",*(Key + 13));
  printfpd("%c",*(Key + 14));
  printfpd("%c",*(Key + 15));
  printfpd("%c",*(Key + 16));
  printfpd("%c",*(Key + 17));
  printfpd("%c",*(Key + 18));
  printfpd("%c",*(Key + 19));
  printfpd("%c\n\r",*(Key + 20));

  */

//______________________________________________________




  view_counter = j;
  if(EventToMenu())
  {
 // printfpd("\n\r ok :%d", j);
 // printfp(LogStr0.Value);
//  printfp(LogStr1.Value);

	   sprintf(NewKey, "%s", "                        ");
  //	    sprintf(NewKey, "++%4d", j);
    memcpy((Key+25), NewKey, 24);  

       sprintf(NewKey, "%s", LogStr0.Value);  //
	//   sprintf(NewKey, "%s", ":23456789012345678901234");  //
            memcpy((Key), NewKey, 24);  
  //t1	    memcpy((Key), NewKey, 6);

       sprintf(NewKey, "%s", "                        ");
	     memcpy((Key+25), NewKey, 24);  

       sprintf(NewKey, "%s", LogStr1.Value);  //
	//   sprintf(NewKey, "%s", "_123456789_");
	   	  memcpy((Key+25), NewKey, 24);  

  }	 //if
   else
 {
   //	  printfpd("\n\r wrong : %d", j);

      break;
 }


  Key += 72;
 } //for
   view_counter = 1;


	   }	 //==c

      if (*(Key + 5) == 'e')  //02e year
       {
   //	     printfp("\n\r <size 2e>:");	return;

 		sprintf(NewKey, "%2d", (unsigned)ClockReadYear());  //    
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
		 
       }  

      if (*(Key + 5) == 'f')  //02f month
       {
	 //    printfp("\n\r <size 2f>:");	return;

 		sprintf(NewKey, "%2d", (unsigned)ClockReadMonth());  //    
        memcpy((Key+15), NewKey, 2);               // channel 7 (P6.7)
		 
       }
	}	 //==2

  if (*(Key + 4) == '3')  //03
    {
 //printfp("\n\r start InsertDynamicValues 3");
	 //  return; //for test


	 if (*(Key + 5) == '0')  //030 day
       {
 		sprintf(NewKey, "%2d", (unsigned)ClockReadDate());      
        memcpy((Key+15), NewKey, 2);                
       }
	 if (*(Key + 5) == '1')  //031 hour
       {
 		sprintf(NewKey, "%2d", (unsigned)ClockReadHours());      
        memcpy((Key+15), NewKey, 2);                
       }
	 if (*(Key + 5) == '2')  //032 minute
       {
 		sprintf(NewKey, "%2d", (unsigned)ClockReadMin());      
        memcpy((Key+15), NewKey, 2);                
       }
	 if (*(Key + 5) == '3')  //033 second
       {
 		sprintf(NewKey, "%2d", (unsigned)ClockReadSec());      
        memcpy((Key+15), NewKey, 2);                
       }

	 if (*(Key + 5) == '4')  //034 web password
       {
 		sprintf(NewKey, "%8d", (unsigned)12345678);      
        memcpy((Key+15), NewKey, 8);                
       }


	 if (*(Key + 5) == '5')  //035 ip
       {
 		sprintf(NewKey, "%3d", (unsigned)IPAddress3.Value);      
        memcpy((Key+15), NewKey, 3);                
       }

	 if (*(Key + 5) == '6')  //036 ip
       {
 		sprintf(NewKey, "%3d", (unsigned)IPAddress2.Value);      
        memcpy((Key+15), NewKey, 3);                
       }
	 if (*(Key + 5) == '7')  //037 ip
       {
 		sprintf(NewKey, "%3d", (unsigned)IPAddress1.Value);      
        memcpy((Key+15), NewKey, 3);                
       }
	 if (*(Key + 5) == '8')  //038 ip
       {
 		sprintf(NewKey, "%3d", (unsigned)IPAddress0.Value);      
        memcpy((Key+15), NewKey, 3);                
       }
     if (*(Key + 5) == '9')  //039 web password	2
       {
 		sprintf(NewKey, "%8d", (unsigned)87654321);      
        memcpy((Key+15), NewKey, 8);                
       }



    }	  //=3



	}}}}}}}



    Key++;
  }
  // printfp("\n\rfinish InsertDynamicValues");

}
//------------------------------------------------------------------------------

