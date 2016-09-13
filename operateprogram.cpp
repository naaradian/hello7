//file operateprogramm.cpp

extern "C" unsigned long GetNoise0()
{

// return 12345l;
 return modemp[0].normalizedMseTenths;
}

extern "C" unsigned long GetLock0()
{
// return (modemp[0].acquireStatus ? '1' : '0');
  return ((unStatePUM.statePUM.state[2] & CHANNEL1_LOCK_BIT)	? '0' : '1');

}


extern "C" unsigned long GetNoise1()
{
 return modemp[1].normalizedMseTenths;
 //return 9876l;
}

extern "C" unsigned long GetLock1()
{
// return (modemp[1].acquireStatus ? '1' : '0');
 return ((unStatePUM.statePUM.state[2] & CHANNEL2_LOCK_BIT)	? '0' : '1');
}



extern "C" signed short  GetinternalAgc(unsigned i)
{
return  modemp[i].internalAgc;
}

extern "C" unsigned short  GetexternalAgcRegister(unsigned i)
{
return  modemp[i].externalAgcRegister;
}





 /*
struct OperateProgramm
{
unsigned long noise0;
unsigned long noise1;
unsigned char loop0set;
unsigned char loop0get;
unsigned char loop1set;
unsigned char loop1get;
unsigned char unmod0set;
unsigned char unmod0get;
unsigned char unmod1set;
unsigned char unmod1get;
};


//OperateProgramm OperProg; //need init
unsigned char flagloop0, flagloop1, flagunmod0, flagunmod1;  //need init

extern "C" void ParseOperProg( )
{
 OperateProgramm * pOperProg;
 pOperProg = (OperateProgramm *)OperateProg.Value;


 pOperProg->noise0 = GetNoise0();
 pOperProg->noise1 = GetNoise1();
 if(pOperProg->loop0set) {}
 pOperProg->loop0get = flagloop0;
 if(pOperProg->loop1set) {}
 pOperProg->loop1get = flagloop1;
 if(pOperProg->unmod0set){}
 pOperProg->unmod0get = flagunmod0;
 if(pOperProg->unmod1set){}
 pOperProg->unmod1get = flagunmod1;
}
*/
  /*
extern "C" unsigned char* GetOperProg()
{
 return  (unsigned char*)&OperProg;
}
 */