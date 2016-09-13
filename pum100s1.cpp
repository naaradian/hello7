
struct PUM100S1
{
 unsigned char SatSet0r0;	//processing freq
 unsigned char SatSet0r1;	//processing freq
 unsigned char SatSet0r2;	//processing freq
 unsigned char SatSet0r3;	//processing freq

 unsigned char SatSet1r0;   //system delay
 unsigned char SatSet1r1;   //system delay
 unsigned char SatSet1r2;   //system delay
 unsigned char SatSet1r3;   //system delay

 unsigned char SatSet2r0;   //output level
 unsigned char SatSet3r0;
 unsigned char SatSet3r1; //debug keys
 unsigned char SatSet4r0;
 unsigned char SatSet4r1; 
 unsigned char SatSet4r2;  //transmit frequency
 unsigned char SatSet5r0;
 unsigned char SatSet5r1; 
 unsigned char SatSet5r2;  //receive frequency
 unsigned char SatSet6r0;  //transmit bound
 unsigned char SatSet7r0;  //receive bound
 unsigned char SatSet8r0;  
 unsigned char SatSet8r1;  //processing offset
 unsigned char SatTestModer0;  //sattestmode
 unsigned char SatPCr0;        //debug mode
 unsigned char SatTimingr0;  //timing
 unsigned char SatSoundr0;  //timing        ____25


//___________________________________________________140902
//MDataV	SatExtLock;
   unsigned char  SatExtLockr0;
//MDataV	SatExtLockP;
   unsigned char  SatExtLockPr0;
//#endif
//MDataV	SatLowP;
   unsigned char  SatLowPr0;
//MDataV	SatALev;
   unsigned char  SatALevr0;
//MDataC	SatACode;
//MDataV	SatADemo;
   unsigned char  SatADemor0;
//MDataC	SatACnt;
   unsigned char  SatACntr0;
   unsigned char  SatACntr1;
   unsigned char  SatACntr2;
   unsigned char  SatACntr3;
//#ifdef YOURNAL
//MDataS	LogStr0;
//MDataS	LogStr1;
//MDataV	LogClear;
   unsigned char  LogClearr0;
//#endif
//#ifdef USE_HTTP
//MDataC	WebPassword;
   unsigned char  WebPasswordr0;
   unsigned char  WebPasswordr1;
   unsigned char  WebPasswordr2;
   unsigned char  WebPasswordr3;
//___________________________________________________ +14 bytes


 unsigned char SatGet1r0;  //freq offset  
 unsigned char SatGet1r1;  //freq offset  
 unsigned char SatGet1r2;  //freq offset  
 unsigned char SatGet1r3;  //freq offset  
     
 unsigned char SatGet2r0;  //channel delay    
 unsigned char SatGet2r1;  //channel delay    
 unsigned char SatGet2r2;  //channel delay    
 unsigned char SatGet2r3;  //channel delay   




 unsigned char SatGet3r0;  //if balance       
 unsigned char SatInputr0;  //if down link     
 unsigned char SatLockr0;  //lock             
 unsigned char SatSearchr0;  //if up link	 ____37=>	 51
 };

union UPUM100S1
{
   PUM100S1 pum100s1;
   unsigned char byte[LEN_PUM100S1];
};
 

extern UPUM100S1 dev1;
