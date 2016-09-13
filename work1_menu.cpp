//file: work1_menu.cpp

#ifdef PROG_PU_MSAT
#include "pum100s1.cpp"
//extern UPUM100S1 dev1;
#endif

//#ifdef 	PROG_MD310_SATI

//#include "md100se.cpp"
//extern UPUM100S1 dev1;
//#endif


 extern "C" void InitClass()
{
 exemplar.var1 = 10000;		//100 - make this value as init for example 
 theAnyStrings.Init();
 //__________________________________________________
 /*
 ClkNumber.Init( &theAnyStrings.cFclk[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ClkNumberStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				   1,//6,  //cntnum - function for control of value
				   1, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, decimal			  
		//		4
		,4.0000000e7,  //init value
		&theAnyStrings.cRemClk[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.cFclk[0], //remote format
		 8,  //remchars 
		 6 //remnum
						);
						*/
//____________________________________________________________________________________________
 IPAddress3.Init( &theAnyStrings.c3d[0],  //format
				   5, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddress3Storage, //sweep in storage - new
//				  40000000l,
				    3,  //chars
//					 3,
					&theCntFunc, //pControl
				  7,//6,  //cntnum - function for control of value
				   7, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, hex			  
		//		4
		,155,  //init value
		&theAnyStrings.cRemIP3[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 7 //remnum
				   ,1,0,255,1		);

//_________________________________________________________________________________________
//_________________________________________________________________________________________
 IPAddress2.Init( &theAnyStrings.c3d[0],  //format
				  9, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddress2Storage, //sweep in storage - new
//				  40000000l,
				    3,  //chars
//					 3,
					&theCntFunc, //pControl
				  8,//6,  //cntnum - function for control of value
				   8, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, hex			  
		//		4
		,155,  //init value
		&theAnyStrings.cRemIP2[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 8 //remnum
					 ,1	,0,255,1);

//_____________________________________
//_____________________________________
 IPAddress1.Init( &theAnyStrings.c3d[0],  //format
				  13, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddress1Storage, //sweep in storage - new
//				  40000000l,
				    3,  //chars
//					 3,
					&theCntFunc, //pControl
				  9,//6,  //cntnum - function for control of value
				   9, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, hex			  
		//		4
		,155,  //init value
		&theAnyStrings.cRemIP1[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 9 //remnum
				   ,1  ,0,255,1		);

//_____________________________________
//_____________________________________
 IPAddress0.Init( &theAnyStrings.c3d[0],  //format
				  17, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddress0Storage, //sweep in storage - new
//				  40000000l,
				    3,  //chars
//					 3,
					&theCntFunc, //pControl
				  10,//6,  //cntnum - function for control of value
				   10, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, hex			  
		//		4
		,155,  //init value
		&theAnyStrings.cRemIP0[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 10 //remnum
		 ,1,0,255,1);
//_____________________________________
//____________________________
//_____________________________________
 IPAddress.Init( &theAnyStrings.c08X[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddressStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				   2,//6,  //cntnum - function for control of value
				   2, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0x9B9B9B0F,  //init value
		&theAnyStrings.cRemIP[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 2 //remnum
					,1 ,0,255,1	);

//_________________________________________________________________________
  MakeIPAddresses(); //init right values of IPaddress0, 1,2,3 after read right value of ipaddress
//________________________________________________________________________


 UsedPult.Init();	//hier init class of pult

//______________________________________
  UsedExp.Init();							
//______________________________________ 
/*
  VolNumber.Init(&theAnyStrings.cVolume[0], 
					7, 1, 
					&theCntFunc,
				 3,	 //oprnum
					 &theAnyStrings.cRemVol[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cFclk[0], //remote command		-test
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					3, 	//remnum
					2	 //cntnum
					);	
					*/
//____________________________________________
/*
 CommandData.Init( &theAnyStrings.cCommandF[0], 
//					4, 2, 1 ,0x2,
					4, 2, //x,y
					 1 , //changable
		   //			 &ExpertStorage.CMD, //storage addr
					CommandDataStorage,
					&theAnyStrings.cCommands[0], //variants
					 0, //init value
					 5, //chars in one
					  3, // quantity
					&theCntFunc, //pControl
					4, //cntnum control of value
					4, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemCom[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1d[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   4  //remnum //selector for operation if receive remote command
					);
					*/
//___________________________________________________________________
 DevData.Init(		 &theAnyStrings.cCommandF[0],//char *,// pSetFormat, - format for makeresultsstr
                       0,// char,// SetXPos,
                       0,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      5, //  Uint16,// SetCntNum,
                      5,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cDevDat[0],//   char*,// SetpRemote,
                     &theAnyStrings.c30c[0],//  char *,// SetpRemFormat, 
                 23,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                     5//   char// SetRemNum - number of functions                      
                     ,0 //len = 0
                         );
//______________________________________________________________________
 RestartData.Init( &theAnyStrings.cs[0], 
//					4, 2, 1 ,0x2,
					4, 2, //x,y
					 1 , //changable
		   //			 &ExpertStorage.CMD, //storage addr
					RestartDataStorage,		//hier is zero - not saved
					&theAnyStrings.cOffOn[0], //variants
					 0, //init value
					 3, //chars in one on indikator
					  2, // quantity
					&theCntFunc, //pControl
					6, //cntnum control of value
					6, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					 &theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRestart[0] //pointer of prefix for remote command premote
					  , &theAnyStrings.c1d[0], //format remote
					   1, //remchars //chars in celling pole of remote command 
					   6  //remnum //selector for operation if receive remote command
					,0
					);
//_______________________________________________________________________________________________
 UARTAddress.Init( &theAnyStrings.c3d[0],  //format
				  11, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					UARTAddressStorage, //sweep in storage - new
//				  40000000l,
				    3,  //chars
//					 3,
					&theCntFunc, //pControl
				  11,//6,  //cntnum - function for control of value
				   11, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemUARTAddr[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 11 //remnum
			   ,1	   ,0,0,0		);
//_____________________________________
//_____________________________________

#ifndef PROG_PU_MSAT

 DevId.Init( &theAnyStrings.c4X[0],  //format
//DevId.Init( &theAnyStrings.c5d[0],  //140203 format
  //140203				  16, 1,  //x,y
				  11, 2,  //x,y
				   0 ,		// not changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
			    4,  //chars
		   //		    5,  //chars
//					 3,
					&theCntFunc, //pControl
				  12,//6,  //cntnum - function for control of value
				   12, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
					 //	 0, 1//, 0//,		//  0 digit after point, hex	
					 	 0, 0//, 0//,		//  0 digit after point, dec			  		  
		//		4
		,0,  //init value
		&theAnyStrings.cRemId[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 12 //remnum
			//  ,1,0,0,0);
			 , 1,	 MIN_DEVID,
			      MAX_DEVID,
			     1);

#else

//DevId.Init( &theAnyStrings.c4X[0],  //format
DevId.Init( &theAnyStrings.c5d[0],  //140203 format
  //140203				  16, 1,  //x,y
				  11, 2,  //x,y
				   0 ,		// not changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
		 //	    4,  //chars
		   		    5,  //chars
//					 3,
					&theCntFunc, //pControl
				  12,//6,  //cntnum - function for control of value
				   12, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
					 //	 0, 1//, 0//,		//  0 digit after point, hex	
					 	 0, 0//, 0//,		//  0 digit after point, dec			  		  
		//		4
		,0,  //init value
		&theAnyStrings.cRemId[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 12 //remnum
			//  ,1,0,0,0);
			 , 1,	 MIN_DEVID,
			      MAX_DEVID,
			     1);



#endif

//_____________________________________
//_____________________________________
DevYear.Init( &theAnyStrings.c4d[0],  //format
				  6, 2,  //x,y
				   1 ,		// temporary changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
				  13,//6,  //cntnum - function for control of value
				   13, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 0//, 0//,		//  0 digit after point,dec			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemYear[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4d[0], //remote format
		 4,  //remchars 
		 13 //remnum
				 ,1,0,0,0);
//_____________________________________
//_____________________________________
DevVer1.Init( &theAnyStrings.c4X[0],  //format
				  16, 2,  //x,y
				   1 ,		// temporary changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
				  14,//6,  //cntnum - function for control of value
				   14, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemVer[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 14 //remnum
			   ,1,0,0,0);
//_____________________________________
DevVer2.Init( &theAnyStrings.c4X[0],  //format
				  21, 2,  //x,y
				   1 ,		// temporary changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
				  15,//6,  //cntnum - function for control of value
				   15, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemVer2[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 15 //remnum
					,1 ,0,0,0	);
//_____________________________________
TestMode.Init( &theAnyStrings.c4X[0],  //format
				  19, 1,  //x,y
				   1 ,		//  changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					TestModeStorage, //sweep in storage - new
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
				  16,//6,  //cntnum - function for control of value
				   16, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemTestMode[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 16 //remnum
				,1,0,0,0);
//_____________________________________
POK.Init( &theAnyStrings.c4X[0],  //format
				  15, 2,  //x,y
				   1 ,		//  changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    4,  //chars
//					 3,
					&theCntFunc, //pControl
				  17,//6,  //cntnum - function for control of value
				   17, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemPOK[0] //remote command	  
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c4X[0], //remote format
		 4,  //remchars 
		 17 //remnum
				,1,0,0,0);
//_____________________________________
Mf20Data.Init( &theAnyStrings.c08X[0],  //format
				  1, 1,  //x,y
				   1 ,		//  changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				  18,//6,  //cntnum - function for control of value
				   18, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemMf20Data[0] //remote command	  
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 18 //remnum
				   ,1,0,0,0);

//_____________________________________________
Mf20DataR.Init( &theAnyStrings.c08X[0],  //format
				  1, 1,  //x,y
				   1 ,		//  changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				  19,//6,  //cntnum - function for control of value
				   19, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point,hex			  
		//		4
				,0,  //init value
			&theAnyStrings.cRemMf20DataR[0] //remote command	  
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 19 //remnum
					,1,0,0,0);
//_____________________________________________
SBuffersState.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    8,  //chars
		  			&theCntFunc, //pControl
				  20,//6,  //cntnum - function for control of value
				   20, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 1//, 0//,		//  0 digit after point,hex			  
   				,0,  //init value
			&theAnyStrings.cRemSBuffersState[0] //remote command	  
  		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 20 //remnum
 ,1,0,0,0);
//___________________________________________________________________
 TBuffer1.Init(		 &theAnyStrings.cCommandF[0],//char *,// pSetFormat, - format for makeresultsstr
                       0,// char,// SetXPos,
                       0,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      21, //  Uint16,// SetCntNum,
                      21,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemTBuffer1[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  21//   char// SetRemNum - number of functions                      
               ,3 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________________________________
 TBuffer2.Init(		 &theAnyStrings.cCommandF[0],//char *,// pSetFormat, - format for makeresultsstr
                       0,// char,// SetXPos,
                       0,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      22, //  Uint16,// SetCntNum,
                      22,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemTBuffer2[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  22//   char// SetRemNum - number of functions                      
               ,3 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________
//_____________________________________
MAC0.Init( &theAnyStrings.c06X[0],  //format
				  5, 2,  //x,y
				   1 ,		// not changable as default
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    6,  //chars
//					 3,
					&theCntFunc, //pControl
				  23,//6,  //cntnum - function for control of value
				   23, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemMAC0[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c06X[0], //remote format
		 6,  //remchars 
		 23 //remnum
			 ,1,0,0,0);
//_____________________________________
 //_____________________________________
MAC1.Init( &theAnyStrings.c06X[0],  //format
				  14, 2,  //x,y
				   1 ,		// not changable as default
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    6,  //chars
//					 3,
					&theCntFunc, //pControl
				  24,//6,  //cntnum - function for control of value
				   24, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemMAC1[0] //remote command	  (B9)
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c06X[0], //remote format
		 6,  //remchars 
		 24 //remnum
				,1,0,0,0);
//_____________________________________
//___________________________________________________________________
 XilFileData.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      25, //  Uint16,// SetCntNum,
                      25,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemXilFileData[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  25//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________________________________
 FileUpdate.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      26, //  Uint16,// SetCntNum,
                      26,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cFileUpdate[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  26//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________
//___________________________________________________________________
 ProgVersion.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      27, //  Uint16,// SetCntNum,
                      27,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cProgVersion[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  27//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________
#ifdef PROG_DMU6
 XilFileData2.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      28, //  Uint16,// SetCntNum,
                      28,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemXilFileData2[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  28//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
//_________________


#endif
#ifndef PROG_BMDN6MI
//___________________________________________________________________
 XilFileData2.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      28, //  Uint16,// SetCntNum,
                      28,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemXilFileData2[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  28//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
//___________________________________________________________________
 XilFileData3.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      29, //  Uint16,// SetCntNum,
                      29,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemXilFileData3[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  29//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

#endif
//_______________________________________________________________________
#ifdef PROG_TUTS
TSInp.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  30,//6,  //cntnum - function for control of value
				  30, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTSInp[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  30 //remnum
	   ,1 ,0,0,0	);

TSOut.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  31,//6,  //cntnum - function for control of value
				  31, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTSOut[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  31 //remnum
		,1 ,0,0,0);
TSInpTrg.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  32,//6,  //cntnum - function for control of value
				  32, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTSInpTrg[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  32 //remnum
		,1 ,0,0,0);

#endif // PROG_TUTS

#ifdef PROG_DTVM
//______________________________________________________________________
 RateData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					RateDataStorage,		//hier is zero - not saved
					&theAnyStrings.cRateData[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					33, //cntnum control of value
					33, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemRateData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					33  //remnum //selector for operation if receive remote command
					);
VideoData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					VideoDataStorage,		//hier is zero - not saved
					&theAnyStrings.cVideoData[0], //variants
					0, //init value
					5, //chars in one on indikator
					3, //how many variants 
					&theCntFunc, //pControl
					34, //cntnum control of value
					34, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemVideoData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					34  //remnum //selector for operation if receive remote command
					);
TestSignalData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					TestSignalDataStorage,		//hier is zero - not saved
					&theAnyStrings.cTestSignalData[0], //variants
					0, //init value
					4, //chars in one on indikator
					6, //how many variants 
					&theCntFunc, //pControl
					35, //cntnum control of value
					35, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemTestSignalData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					35  //remnum //selector for operation if receive remote command
					);
SoundData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					SoundDataStorage,		//hier is zero - not saved
					&theAnyStrings.cSoundData[0], //variants
					0, //init value
					5, //chars in one on indikator
					2, //how many variants 
					&theCntFunc, //pControl
					36, //cntnum control of value
					36, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSoundData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					36  //remnum //selector for operation if receive remote command
					);
StateData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    StateDataStorage, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    37, //cntnum - function for control of value
				    37, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemStateData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			37 //remnum
					 );
ErrData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    ErrDataStorage, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    38, //cntnum - function for control of value
				    38, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemErrData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			38 //remnum
					 );
PointData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    PointDataStorageC, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    39, //cntnum - function for control of value
				    39, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemPointData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			39 //remnum
					 );
AddrData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    AddrDataStorageC, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    40, //cntnum - function for control of value
				    40, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemAddrData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			40 //remnum
					 );


//_________________________________________________________________________
#endif //PROG_DTVM

#ifdef PROG_KTVM
//______________________________________________________________________
 RateData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					RateDataStorage,		//hier is zero - not saved
					&theAnyStrings.cRateData[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					33, //cntnum control of value
					33, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemRateData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					33  //remnum //selector for operation if receive remote command
					);
VideoData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					VideoDataStorage,		//hier is zero - not saved
					&theAnyStrings.cVideoData[0], //variants
					0, //init value
					3, //chars in one on indikator
					3, //how many variants 
					&theCntFunc, //pControl
					34, //cntnum control of value
					34, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemVideoData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					34  //remnum //selector for operation if receive remote command
					);
TestSignalData.Init( &theAnyStrings.cs[0], 			//hier stopkadr
					4, 2, //x,y
				    1 , //changable
					TestSignalDataStorage,		//hier is zero - not saved
					&theAnyStrings.cTestSignalData[0], //variants
					0, //init value
					4, //chars in one on indikator
					6, //how many variants 
					&theCntFunc, //pControl
					35, //cntnum control of value
					35, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemTestSignalData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					35  //remnum //selector for operation if receive remote command
					);
SoundData.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1 , //changable
					SoundDataStorage,		//hier is zero - not saved
					&theAnyStrings.cSoundData[0], //variants
					0, //init value
					5, //chars in one on indikator
					2, //how many variants 
					&theCntFunc, //pControl
					36, //cntnum control of value
					36, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSoundData[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					36  //remnum //selector for operation if receive remote command
					);
StateData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    StateDataStorage, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    37, //cntnum - function for control of value
				    37, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemStateData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			37 //remnum
					 );
PointData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    PointDataStorageC, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    39, //cntnum - function for control of value
				    39, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemPointData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			39 //remnum
					 );
AddrData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    AddrDataStorageC, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    40, //cntnum - function for control of value
				    40, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemAddrData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			40 //remnum
					 );



#endif // PROG_KTVM

#ifdef IncEmbIndicator
KeyData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    KeyDataStorage, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    41, //cntnum - function for control of value
				    41, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemKeyData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			41 //remnum
			  ,1,0,0,0 );

IndData0.Init(	   "%24s",//char *,// pSetFormat, - format for makeresultsstr
                   1,// char,// SetXPos,
                   2,//  char,// SetYPos,
                   24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                   &theCntFunc,//   CntFunc * ,//SetpControl,
                   42, //  Uint16,// SetCntNum,
                   42,//  Uint16,// SetOprNum, 
                   &theAnyStrings.cRemIndData0[0],//   char*,// SetpRemote,
           	       &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                   TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                   42//   char// SetRemNum - number of functions                      
                   ,0 //len = 2  //in first two bytes is lengtch of data
         	);

IndData1.Init(	   "%24s",//char *,// pSetFormat, - format for makeresultsstr
                   1,// char,// SetXPos,
                   2,//  char,// SetYPos,
                   24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                   &theCntFunc,//   CntFunc * ,//SetpControl,
                   43, //  Uint16,// SetCntNum,
                   43,//  Uint16,// SetOprNum, 
                   &theAnyStrings.cRemIndData1[0],//   char*,// SetpRemote,
           	       &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                   TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                   43//   char// SetRemNum - number of functions                      
                   ,0 //len = 2  //in first two bytes is lengtch of data
         	);

CurData.Init( &theAnyStrings.c3d[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    CurDataStorage, //sweep in storage - new
			        3,  //chars
				    &theCntFunc, //pControl
				    44, //cntnum - function for control of value
				    44, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 0//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemCurData[0] //remote command	  (B9)
					, &theAnyStrings.c3d[0], //remote format
		 			3,  //remchars 
		 			44 //remnum
				   ,1 ,0,0,0);
LedData.Init( &theAnyStrings.c08X[0],  //format
				    10, 2,  //x,y
				    1 ,		//changable
		 		    LedDataStorage, //sweep in storage - new
			        8,  //chars
				    &theCntFunc, //pControl
				    45, //cntnum - function for control of value
				    45, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
		   			 0, 1//, 0//,		//  0 digit after point, hex			  
				    ,0,  //init value
					&theAnyStrings.cRemLedData[0] //remote command	  (B9)
					, &theAnyStrings.c08X[0], //remote format
		 			8,  //remchars 
		 			45 //remnum
				 ,1 ,0,0,0);
#endif // IncEmbIndicator
#ifdef PROG_BMD35

RemoteMode.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  46,//6,  //cntnum - function for control of value
				  46, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemoteMode[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  46 //remnum
		);

#endif //	PROG_BMD35

#ifdef PROG_PROV

RemoteMode.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  46,//6,  //cntnum - function for control of value
				  46, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemoteMode[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  46 //remnum
		);

#endif //	PROG_PROV


#ifdef PROG_MPC35

RemoteMode.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  46,//6,  //cntnum - function for control of value
				  46, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemoteMode[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  46 //remnum
		);

#endif //	PROG_MPC35

#ifdef KTVM_PROT2

RemoteMode.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  46,//6,  //cntnum - function for control of value
				  46, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemoteMode[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  46 //remnum
		);

#endif //  KTVM_PROT2


LockMode.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  47,//6,  //cntnum - function for control of value
				  47, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cLockMode[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  47 //remnum
			,1 ,0,0,0 );


#ifdef TRAP_ENABLED

TrapTimer.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  48,//6,  //cntnum - function for control of value
				  48, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTrapTimer[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  48 //remnum
			  ,1 ,0,0,0  );

TrapIp.Init( &theAnyStrings.c08X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  49,//6,  //cntnum - function for control of value
				  49, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTrapIp[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  49 //remnum
			  ,1 ,0,0,0  );

#endif // TRAP_ENABLED

#ifdef CLOCK_ENABLED

TimeData1.Init( &theAnyStrings.c2d[0],  //format
//TimeData1.Init( &theAnyStrings.c41f[0],  //format
  				  17, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
			   //	  4,  //chars
		  		  &theCntFunc, //pControl
				  50,//6,  //cntnum - function for control of value
				  50, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   			   //	  0, 1,//, 0//,		//  0 digit after point,hex			  
				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData1[0], //remote command	  
  		 	 	  &theAnyStrings.c2d[0], //remote format
			//	  &theAnyStrings.c8d[0], //remote format
		 		  2,  //remchars 
		 		  50 //remnum
	  //		 ,1,0,0,0);
	  ,1,TIMEDATA1_MIN, TIMEDATA1_MAX, 1);

TimeData2.Init( &theAnyStrings.c2d[0],  //format
  				  12, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  51,//6,  //cntnum - function for control of value
				  51, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData2[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  51 //remnum
  //			 ,1,0,0,0);
  ,1,TIMEDATA2_MIN, TIMEDATA2_MAX, 1);


TimeData3.Init( &theAnyStrings.c2d[0],  //format
  				  7, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  52,//6,  //cntnum - function for control of value
				  52, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData3[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  52 //remnum
 //		,1 ,0,0,0);
  ,1,TIMEDATA3_MIN, TIMEDATA3_MAX, 1);


TimeData4.Init( &theAnyStrings.c2d[0],  //format
  				  7, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  53,//6,  //cntnum - function for control of value
				  53, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData4[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  53 //remnum
//		  ,1	  ,0,0,0 );
  ,1,TIMEDATA4_MIN, TIMEDATA4_MAX, 1);


TimeData5.Init( &theAnyStrings.c2d[0],  //format
  				  12, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  54,//6,  //cntnum - function for control of value
				  54, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData5[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  54 //remnum
//		   ,1 ,0,0,0);
  ,1,TIMEDATA5_MIN, TIMEDATA5_MAX, 1);


//TimeData6.Init( &theAnyStrings.c4d[0],  //format
TimeData6.Init( &theAnyStrings.c2d[0],  //format
  				  17, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  55,//6,  //cntnum - function for control of value
				  55, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cTimeData6[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  55 //remnum
//			 ,1,0,0,0);
  ,1,TIMEDATA6_MIN, TIMEDATA6_MAX, 1);
//  ,1,TIMEDATA6_MIN, TIMEDATA6_MAX, 0);


#endif // CLOCK_ENABLED

#ifdef YOURNAL
 CRecord.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      0,//hier set zero! to print full message! //  Uint16,// SetCntNum,
                      56,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cCRecord[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c64X[0],//  char *,// SetpRemFormat,
                 RECORD_SIZE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  56//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
#endif //YOURNAL

#ifdef PROG_BMDN

ConfigFile.Init( &theAnyStrings.c2d[0],  //format
  				  22, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  57,//6,  //cntnum - function for control of value
				  57, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,dec			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  57 //remnum
			   ,1,0,(MAX_NUM_CFG - 1),1);

//#ifndef PROG_BMDN6MI
ConfigFile1.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  58,//6,  //cntnum - function for control of value
				  58, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile1[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  58 //remnum
			   ,1,0,0,0);


#ifndef PROG_BMDN6MI

ConfigFile2.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  59,//6,  //cntnum - function for control of value
				  59, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile2[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  59 //remnum
			   ,1,0,0,0);
ConfigFile3.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  60,//6,  //cntnum - function for control of value
				  60, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile3[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  60 //remnum
			   ,1,0,0,0);
ConfigFile4.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  61,//6,  //cntnum - function for control of value
				  61, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile4[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  61 //remnum
			   ,1,0,0,0);
ConfigFile5.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  62,//6,  //cntnum - function for control of value
				  62, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile5[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  62 //remnum
			   ,1,0,0,0);
ConfigFile6.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  63,//6,  //cntnum - function for control of value
				  63, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile6[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  63 //remnum
			   ,1,0,0,0);
ConfigFile7.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  64,//6,  //cntnum - function for control of value
				  64, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile7[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  64 //remnum
			   ,1,0,0,0);
ConfigFile8.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  65,//6,  //cntnum - function for control of value
				  65, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile8[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  65 //remnum
			   ,1,0,0,0);
ConfigFile9.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  66,//6,  //cntnum - function for control of value
				  66, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile9[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  66 //remnum
			   ,1,0,0,0);
ConfigFile10.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  67,//6,  //cntnum - function for control of value
				  67, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile10[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  67 //remnum
			  ,1,0,0,0 );
ConfigFile11.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  68,//6,  //cntnum - function for control of value
				  68, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile11[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  68 //remnum
			   ,1,0,0,0);
ConfigFile12.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  69,//6,  //cntnum - function for control of value
				  69, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile12[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  69 //remnum
			  ,1,0,0,0 );
ConfigFile13.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  70,//6,  //cntnum - function for control of value
				  70, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile13[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  70 //remnum
			   ,1,0,0,0);
ConfigFile14.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  71,//6,  //cntnum - function for control of value
				  71, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile14[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  71 //remnum
			   ,1,0,0,0);
ConfigFile15.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  72,//6,  //cntnum - function for control of value
				  72, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cConfigFile15[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  72 //remnum
			   ,1,0,0,0);

#endif

ConfigFileVersion.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      73, //  Uint16,// SetCntNum,
                      73,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cConfigFileVersion[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  73//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


ModForSS.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  74,//6,  //cntnum - function for control of value
				  74, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cModForSS[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  74 //remnum
			   ,1,0,0,0);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 XilFileDatax0.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      75, //  Uint16,// SetCntNum,
                      75,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax0[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	75//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

#ifndef PROG_BMDN6MI

 XilFileDatax1.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      76, //  Uint16,// SetCntNum,
                      76,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax1[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	76//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax2.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      77, //  Uint16,// SetCntNum,
                      77,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax2[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	77//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax3.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      78, //  Uint16,// SetCntNum,
                      78,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax3[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	78//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax4.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      79, //  Uint16,// SetCntNum,
                      79,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax4[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	79//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax5.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      80, //  Uint16,// SetCntNum,
                      80,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax5[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	80//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax6.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      81, //  Uint16,// SetCntNum,
                      81,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax6[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	81//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax7.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      82, //  Uint16,// SetCntNum,
                      82,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax7[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	82//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax8.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      83, //  Uint16,// SetCntNum,
                      83,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax8[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	83//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax9.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      84, //  Uint16,// SetCntNum,
                      84,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax9[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	84//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax10.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      85, //  Uint16,// SetCntNum,
                      85,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax10[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	85//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax11.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      86, //  Uint16,// SetCntNum,
                      86,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax11[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	86//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax12.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      87, //  Uint16,// SetCntNum,
                      87,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax12[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	87//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax13.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      88, //  Uint16,// SetCntNum,
                      88,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax13[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	88//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax14.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      89, //  Uint16,// SetCntNum,
                      89,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRemXilFileDatax14[0],//   char*,// SetpRemote,
 			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	89//   char// SetRemNum - number of functions                      
               		,0 //len = 2  //in first two bytes is lengtch of data
         			);

 XilFileDatax15.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                       24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                       &theCntFunc,//   CntFunc * ,//SetpControl,
                       90, //  Uint16,// SetCntNum,
                       90,//  Uint16,// SetOprNum, 
                       &theAnyStrings.cRemXilFileDatax15[0],//   char*,// SetpRemote,
 			    	   &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	   TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	   90//   char// SetRemNum - number of functions                      
               		   ,0 //len = 2  //in first two bytes is lengtch of data
         			);
#endif

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Priority0.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  91,//6,  //cntnum - function for control of value
				  91, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority0[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  91 //remnum
			   ,1,0,0,0);

#ifndef PROG_BMDN6MI
Priority1.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  92,//6,  //cntnum - function for control of value
				  92, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority1[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  92 //remnum
			   ,1,0,0,0);
Priority2.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  93,//6,  //cntnum - function for control of value
				  93, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority2[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  93 //remnum
			   ,1,0,0,0);
Priority3.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  94,//6,  //cntnum - function for control of value
				  94, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority3[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  94 //remnum
			   ,1,0,0,0);
Priority4.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  95,//6,  //cntnum - function for control of value
				  95, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority4[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  95 //remnum
			   ,1,0,0,0);
Priority5.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  96,//6,  //cntnum - function for control of value
				  96, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority5[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  96 //remnum
			   ,1,0,0,0);
Priority6.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  97,//6,  //cntnum - function for control of value
				  97, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority6[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  97 //remnum
			   ,1,0,0,0);
Priority7.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  98,//6,  //cntnum - function for control of value
				  98, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority7[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  98 //remnum
			   ,1,0,0,0);
Priority8.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  99,//6,  //cntnum - function for control of value
				  99, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cPriority8[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  99 //remnum
			   ,1,0,0,0);
#endif

Threshold0.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  100,//6,  //cntnum - function for control of value
				  100, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold0[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  100 //remnum
			  ,1,0,0,0 );

#ifndef PROG_BMDN6MI
Threshold1.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  101,//6,  //cntnum - function for control of value
				  101, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold1[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  101 //remnum
			   ,1,0,0,0);
Threshold2.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  102,//6,  //cntnum - function for control of value
				  102, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold2[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  102 //remnum
			  ,1,0,0,0 );
Threshold3.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  103,//6,  //cntnum - function for control of value
				  103, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold3[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  103 //remnum
			   ,1,0,0,0);
Threshold4.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  104,//6,  //cntnum - function for control of value
				  104, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold4[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  104 //remnum
			  ,1,0,0,0 );
Threshold5.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  105,//6,  //cntnum - function for control of value
				  105, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold5[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  105 //remnum
			   ,1,0,0,0);
Threshold6.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  106,//6,  //cntnum - function for control of value
				  106, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold6[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  106 //remnum
			   ,1,0,0,0);
Threshold7.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  107,//6,  //cntnum - function for control of value
				  107, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold7[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  107 //remnum
			   ,1,0,0,0);
Threshold8.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  108,//6,  //cntnum - function for control of value
				  108, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cThreshold8[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  108 //remnum
			   ,1,0,0,0);
#endif

#endif //PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
/*
MDataC	SymbolRate;
MDataC	FreqPCh;
MDataC	ModulSK;
*/
SymbolRate.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  109,//6,  //cntnum - function for control of value
				  109, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cSymbolRate[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  109 //remnum
			     ,1,0,0,0);


FreqPCh.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  110,//6,  //cntnum - function for control of value
				  110, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cFreqPCh[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  110 //remnum
			   ,1,0,0,0);


ModulSK.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  111,//6,  //cntnum - function for control of value
				  111, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cModulSK[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  111 //remnum
			   ,1,0,0,0);

#endif

#ifdef PROG_PRM_PCH_DEM_XIL
XilFileData4.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      112, //  Uint16,// SetCntNum,
                      112,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemXilFileData4[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  112//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

#endif //PROG_PRM_PCH_DEM_XIL



#ifdef PROG_BMDN

Protect0.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  113,//6,  //cntnum - function for control of value
				  113, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect0[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  113 //remnum
			   ,1,0,0,0);

#ifndef PROG_BMDN6MI

Protect1.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  114,//6,  //cntnum - function for control of value
				  114, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect1[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  114 //remnum
			   ,1,0,0,0);

Protect2.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  115,//6,  //cntnum - function for control of value
				  115, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect2[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  115 //remnum
			   ,1,0,0,0);

Protect3.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  116,//6,  //cntnum - function for control of value
				  116, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect3[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  116 //remnum
			   ,1,0,0,0);

Protect4.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  117,//6,  //cntnum - function for control of value
				  117, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect4[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  117 //remnum
			  ,1,0,0,0 );

Protect5.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  118,//6,  //cntnum - function for control of value
				  118, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect5[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  118 //remnum
			   ,1,0,0,0);

Protect6.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  119,//6,  //cntnum - function for control of value
				  119, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect6[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  119 //remnum
			   ,1,0,0,0);

Protect7.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  120,//6,  //cntnum - function for control of value
				  120, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect7[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  120 //remnum
			  ,1,0,0,0 );

Protect8.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  121,//6,  //cntnum - function for control of value
				  121, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect8[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  121 //remnum
			   ,1,0,0,0);

Protect9.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  122,//6,  //cntnum - function for control of value
				  122, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect9[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  122 //remnum
			   ,1,0,0,0);

Protect10.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  123,//6,  //cntnum - function for control of value
				  123, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect10[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  123 //remnum
			   ,1,0,0,0);

Protect11.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  124,//6,  //cntnum - function for control of value
				  124, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect11[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  124 //remnum
			 ,1,0,0,0  );

Protect12.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  125,//6,  //cntnum - function for control of value
				  125, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect12[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  125 //remnum
			   ,1,0,0,0);

Protect13.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  126,//6,  //cntnum - function for control of value
				  126, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect13[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  126 //remnum
			   ,1,0,0,0);

Protect14.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  127,//6,  //cntnum - function for control of value
				  127, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect14[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  127 //remnum
			   ,1,0,0,0);

Protect15.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  128,//6,  //cntnum - function for control of value
				  128, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect15[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  128 //remnum
			  ,1,0,0,0 );

Protect16.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  129,//6,  //cntnum - function for control of value
				  129, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect16[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  129 //remnum
			  ,1,0,0,0 );

Protect17.Init( &theAnyStrings.c2d[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  130,//6,  //cntnum - function for control of value
				  130, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cProtect17[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  130 //remnum
			   ,1,0,0,0);
#endif
#endif //PROG_BMDN

#ifdef HAVE_GATEWAY
 Network.Init( &theAnyStrings.c08X[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				   131,//6,  //cntnum - function for control of value
				   131, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0x9B9B9B0F,  //init value
		&theAnyStrings.cRemNetwork[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 131 //remnum
					  ,1,0,0,0);

NetMask.Init( &theAnyStrings.c08X[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					ZeroStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				   132,//6,  //cntnum - function for control of value
				   132, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0xffffff00,  //init value
		&theAnyStrings.cRemNetMask[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 132 //remnum
			  ,1,0,0,0);

#endif //HAVE_GATEWAY
//_______________________________________________________________________
 
#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4

DecFileData.Init(
 					//&theAnyStrings.cCommandF[0]
 					"%24s",//char *,// pSetFormat, - format for makeresultsstr
                    1,// char,// SetXPos,
                    2,//  char,// SetYPos,
                    //   char SetChangable, 
                    //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      133, //  Uint16,// SetCntNum,
                      133,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemDecFileData[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  133//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


#endif

#ifdef PROG_BMDN4

OperateProg.Init(
 	   				 "%24s",//char *,// pSetFormat, - format for makeresultsstr
		//			 "%40s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                       24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                       &theCntFunc,//   CntFunc * ,//SetpControl,
                       134, //  Uint16,// SetCntNum,
                       134,//  Uint16,// SetOprNum, 
                       &theAnyStrings.cRemOperateProg[0],//   char*,// SetpRemote,
 			    	   &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	   TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	   134//   char// SetRemNum - number of functions                      
               		   ,0 //len = 2  //in first two bytes is lengtch of data
         			);

#endif 

#ifdef PROG_PU_M710
OperateProg.Init(
 	   				 "%24s",//char *,// pSetFormat, - format for makeresultsstr
		//			 "%40s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                       24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                       &theCntFunc,//   CntFunc * ,//SetpControl,
                       134, //  Uint16,// SetCntNum,
                       134,//  Uint16,// SetOprNum, 
                       &theAnyStrings.cRemOperateProg[0],//   char*,// SetpRemote,
 			    	   &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 	   TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  	   134//   char// SetRemNum - number of functions                      
               		   ,0 //len = 2  //in first two bytes is lengtch of data
         			);

#endif

#ifdef PROG_PU_MSAT	 //

SatSet0.Init( &theAnyStrings.c9d[0],  //format		  //min distance  // processing freq
  				  6, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  9,  //chars
		  		  &theCntFunc, //pControl
				  135,//6,  //cntnum - function for control of value
				  135, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,decimal			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet0[0], //remote command	  
  		 		  &theAnyStrings.c9d[0], //remote format
		 		  9,  //remchars 
		 		  135 //remnum
			 ,1,
			 MIN_SATSET0,
			 MAX_SATSET0,
			 1);

//SatSet1.Init( &theAnyStrings.cRem[0],  //	max distance   //system delay
SatSet1.Init( &theAnyStrings.c63f[0],  //	max distance   //system delay
  				  9, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  6,  //chars in one
		  		  &theCntFunc, //pControl
				  136,//6,  //cntnum - function for control of value
				  136, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				 // 0, 0,//, 0//,		//  0 digit after point,hex		
   				  3, 0,//, 0//,		//  3 digit after point,decimal			  	  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet1[0], //remote command	  
  		 		  &theAnyStrings.c63f[0], //remote format
		 		  7,  //remchars 
		 		  136 //remnum
		   ,1,	 MIN_SATSET1,
			 MAX_SATSET1,
			 			 1);

//SatSet2.Init( &theAnyStrings.c3d[0],  //out level  
SatSet2.Init( &theAnyStrings.c31f[0],  //out level  
				  12, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
	 //			  3,  //chars
				  3,  //chars
		  		  &theCntFunc, //pControl
				  137,//6,  //cntnum - function for control of value
				  137, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   		  //		  0, 0,//, 0//,		//  0 digit after point,hex			  
				  1, 0,//, 0//,		//  1 digit after point,decimal			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet2[0], //remote command	  
  		 //		  &theAnyStrings.c3d[0], //remote format
				  &theAnyStrings.c31f[0], //remote format
		// 		  3,  //remchars 
		 		  3,  //remchars 
		 		  137 //remnum
		  ,-1  ,	 MIN_SATSET2,
			  MAX_SATSET2,
			 1);

//SatSet3.Init( &theAnyStrings.c3d[0],  //aver distance  //debug keys
//SatSet3.Init( &theAnyStrings.c4X[0],  //aver distance  //debug keys
//130517SatSet3.Init( &theAnyStrings.c2X[0],  //aver distance  //debug keys
//140227SatSet3.Init( &theAnyStrings.c1X[0],  //aver distance  //debug keys
SatSet3.Init( &theAnyStrings.c2d[0],  //aver distance  //debug keys
  				  13, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
		   //140227		  1, //1304094, //3 //chars
				  2, //1304094, //3 //chars
		  		  &theCntFunc, //pControl
				  138,//6,  //cntnum - function for control of value
				  138, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   			   //	  0, 0,//, 0//,		//  0 digit after point,hex			  
			  //140227    0, 1,//, 0//,		//  0 digit after point,hex		
			      0, 0,//, 0//,		//  0 digit after point,dec			  	  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet3[0], //remote command	  
  		 	 //	  &theAnyStrings.c3d[0], //remote format
			   //	  &theAnyStrings.c4X[0], //remote format
				  &theAnyStrings.c1X[0], //remote format
		 		  1, //3 //remchars 
		 		  138 //remnum
			 ,1,	 MIN_SATSET3,
			 MAX_SATSET3,
			 1);


SatSet4.Init( &theAnyStrings.c6d[0],  //tr freq
  				  8, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  6,  //chars
		  		  &theCntFunc, //pControl
				  139,//6,  //cntnum - function for control of value
				  139, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet4[0], //remote command	  
  		 		  &theAnyStrings.c6d[0], //remote format
		 		  6,  //remchars 
		 		  139 //remnum
			,1,	 MIN_SATSET4,
			 MAX_SATSET4,
			 1);

SatSet5.Init( &theAnyStrings.c6d[0],  //format
  				  8, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  6,  //chars
		  		  &theCntFunc, //pControl
				  140,//6,  //cntnum - function for control of value
				  140, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet5[0], //remote command	  
  		 		  &theAnyStrings.c6d[0], //remote format
		 		  6,  //remchars 
		 		  140 //remnum
			 ,1 ,	 MIN_SATSET5,
			 MAX_SATSET5,			 1);

SatSet6.Init( &theAnyStrings.c2d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  141,//6,  //cntnum - function for control of value
				  141, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet6[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  141 //remnum
			,1,	 MIN_SATSET6,
			  MAX_SATSET6,
			 1);

SatSet7.Init( &theAnyStrings.c2d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  142,//6,  //cntnum - function for control of value
				  142, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet7[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  142 //remnum
			,1,	 MIN_SATSET7,
			 MAX_SATSET7,
			 1);



 SatGet0.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 143,	 //oprnum
					 &theAnyStrings.cRemSatGet0[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					143, 	//remnum
					143	 //cntnum
					);	

 SatGet1.Init(
 				&theAnyStrings.c41f[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 144,	 //oprnum
					 &theAnyStrings.cRemSatGet1[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.c41f[0], //remote format
  			 //test		10, //remchars
			   5,  //remchars 	   - test
	  				//	9,//t
					144, 	//remnum
					144	 //cntnum
					);	
 SatGet2.Init(
 				&theAnyStrings.c52f[0], 	  //format for resultstr
					8, 2, 
					&theCntFunc,
				 145,	 //oprnum
					 &theAnyStrings.cRemSatGet2[0]
			 //test		, &theAnyStrings.cVolume[0],
		  //	 ,&theAnyStrings.c63f[0], //remote format
			 ,&theAnyStrings.c52f[0], //remote format
  			 //test		10, //remchars
			   7,  //remchars 	   - test
	  				//	9,//t
					145, 	//remnum
					145	 //cntnum
					);	
 SatGet3.Init(
 			 //	&theAnyStrings.cd[0], 	  //format for resultstr
				&theAnyStrings.c41f[0], 	
					11, 2, 
					&theCntFunc,
				 146,	 //oprnum
					 &theAnyStrings.cRemSatGet3[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
 			   5,  //remchars 	   - test
	  				//	9,//t
					146, 	//remnum
					146	 //cntnum
					);	
 SatGet4.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 147,	 //oprnum
					 &theAnyStrings.cRemSatGet4[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					147, 	//remnum
					147	 //cntnum
					);	
 SatGet5.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 148,	 //oprnum
					 &theAnyStrings.cRemSatGet5[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					148, 	//remnum
					148	 //cntnum
					);	
 SatGet6.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 149,	 //oprnum
					 &theAnyStrings.cRemSatGet6[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					149, 	//remnum
					149	 //cntnum
					);	
 SatGet7.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					11, 2, 
					&theCntFunc,
				 150,	 //oprnum
					 &theAnyStrings.cRemSatGet7[0]
			 //test		, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					150, 	//remnum
					150	 //cntnum
					);	

#ifdef PROG_PU_MSAT1

SatGet8.Init(
 				&theAnyStrings.cd[0], 	  //format for resultstr
					22, 2, 
					&theCntFunc,
				 258,	 //oprnum
					 &theAnyStrings.cRemSatGet8[0]
			 //test	, &theAnyStrings.cVolume[0],
			 ,&theAnyStrings.cd[0], //remote format
  			 //test		10, //remchars
			   8,  //remchars 	   - test
	  				//	9,//t
					258, 	//remnum
					258	 //cntnum
					);	

#endif

SatTestMode.Init( &theAnyStrings.cs[0], 
					11, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatTestModeV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					151, //cntnum control of value
					151, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatTestMode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					151  //remnum //selector for operation if receive remote command
					,0
					);

SatPC.Init( &theAnyStrings.cs[0], 
					11, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatPCV[0], //variants
					0, //init value
					3,//1, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					152, //cntnum control of value
					152, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatPC[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					152  //remnum //selector for operation if receive remote command
									,0
	);

SatInput.Init( &theAnyStrings.cs[0], 
					7, 2, //x,y
				    0, //1 , //notchangable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatInputV[0], //variants
					0, //init value
					9, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					153, //cntnum control of value
					153, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatInput[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					153  //remnum //selector for operation if receive remote command
									,0
	);

SatLock.Init( &theAnyStrings.cs[0], 
					19, 1, //x,y
				    0, //1 , //notchangable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatLockV[0], //variants
					0, //init value
					6, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					154, //cntnum control of value
					154, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatLock[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					154  //remnum //selector for operation if receive remote command
												,0

					);

SatSearch.Init( &theAnyStrings.cs[0], 
					7, 2, //x,y
				    0, //1 , //notchangable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatInputV[0], //variants
					0, //init value
					9, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					155, //cntnum control of value
					155, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
	 				 , &theAnyStrings.cRemSatSearch[0] //pointer of prefix for remote command premote
   //				 , &theAnyStrings.cRemSatInput[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					155  //remnum //selector for operation if receive remote command
									,0
	);

SatXilBlock.Init( &theAnyStrings.cs[0], 
					22, 2, //x,y
				    0, //1 , //notchangable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatXilBlockV[0], //variants
					0, //init value
					1, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					156, //cntnum control of value
					156, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatXilBlock[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					156  //remnum //selector for operation if receive remote command
								,1
		);


SatTiming.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatTimingV[0], //variants
					0, //init value
					6, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					162,//157, //cntnum control of value
					162,//157, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatTiming[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					162//157  //remnum //selector for operation if receive remote command
										,0
);

SatSet8.Init( &theAnyStrings.c4dd[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  4,  //chars
		  		  &theCntFunc, //pControl
				  163,//158,//6,  //cntnum - function for control of value
				  163,//158, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatSet8[0], //remote command	  
  		 		  &theAnyStrings.c4dd[0], //remote format
		 		  4,  //remchars 
		 		  163//158 //remnum
			,1,	 MIN_SATSET8,
			 MAX_SATSET8,
			 1);

SatTestModeI.Init( &theAnyStrings.cs[0], 
				  //	23, 2, //x,y
					22, 2, //x,y
				    0 , // not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatTestModeIV[0], //variants
					0, //init value
				  //	1, //chars in one on indikator

#ifndef LINE_LOCK

					2, //chars in one on indikator
					2, //  ???

#else
					3, //chars in one on indikator
					16, //  ???

#endif
					&theCntFunc, //pControl
					164,//159, //cntnum control of value
					164,//159, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatTestMode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					2, //remchars //chars in celling pole of remote command 
					164//159  //remnum //selector for operation if receive remote command
									,1
	);

SatSound.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatSoundV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					165,//160, //cntnum control of value5
					165,//160, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatSound[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					165//160  //remnum //selector for operation if receive remote command
										,0
);

SatFactory.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatFactoryV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					166,//161, //cntnum control of value
					166,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatFactory[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					2, //remchars //chars in celling pole of remote command 
					166//161  //remnum //selector for operation if receive remote command
										,0
);


SatDF.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatDFV[0], //variants
					0, //init value
					3, //chars in one on indikator
					13, // 
					&theCntFunc, //pControl
					171,//161, //cntnum control of value
					171,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatDF[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					2, //remchars //chars in celling pole of remote command 
					171//161  //remnum //selector for operation if receive remote command
										,0
);

SatTF.Init( &theAnyStrings.cs[0], 
					5, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatTFV[0], //variants
					0, //init value
					15,//4, //chars in one on indikator
					16, // 
					&theCntFunc, //pControl
					172,//161, //cntnum control of value
					172,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatTF[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					172//161  //remnum //selector for operation if receive remote command
										,0
);

#ifdef RECEIVE_MOD_LOCK


SatExtLock.Init( &theAnyStrings.cs[0], 
					11, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatExtLockV[0], //variants
					0, //init value
					3,//4, //chars in one on indikator
					2, //variants? 
					&theCntFunc, //pControl
					176,//161, //cntnum control of value
					176,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatExtLock[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					176//161  //remnum //selector for operation if receive remote command
										,0
);

SatExtLockP.Init( &theAnyStrings.cs[0], 
					11, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatExtLockPV[0], //variants
					0, //init value
					1,//4, //chars in one on indikator
					2, //variants 
					&theCntFunc, //pControl
					177,//161, //cntnum control of value
					177,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatExtLockP[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					177//161  //remnum //selector for operation if receive remote command
										,0
);

#endif

SatLowP.Init( &theAnyStrings.cs[0], 
					11, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatLowPV[0], //variants
					0, //init value
					3,//4, //chars in one on indikator
					2, //variants 
					&theCntFunc, //pControl
					178,//161, //cntnum control of value
					178,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatLowP[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					178//161  //remnum //selector for operation if receive remote command
										,0
);


SatALev.Init( &theAnyStrings.cs[0], 
					8, 2, //x,y
				    0 , // not changable	   
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatALevV[0], //variants
					0, //init value
					8,//4, //chars in one on indikator
					3, //variants 
					&theCntFunc, //pControl
					179,//161, //cntnum control of value
					179,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatALev[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					179//161  //remnum //selector for operation if receive remote command
										,0
);

SatADemo.Init( &theAnyStrings.cs[0], 
					17, 1, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatADemoV[0], //variants
					0, //init value
					3,//4, //chars in one on indikator
					2, //variants 
					&theCntFunc, //pControl
					180,//161, //cntnum control of value
					180,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatADemo[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					180//161  //remnum //selector for operation if receive remote command
										,0
);

SatACode.Init( &theAnyStrings.c8d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  181,//6,  //cntnum - function for control of value
				  181, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatACode[0], //remote command	  
  		 		  &theAnyStrings.c8d[0], //remote format
		 		  8,  //remchars 
		 		  181 //remnum
				 ,1,	 MIN_SATACODE,
			      MAX_SATACODE,
			     1);

SatACnt.Init( &theAnyStrings.c8d[0],  //format
  				  7, 2,  //x,y
				  0 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  182,//6,  //cntnum - function for control of value
				  182, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatACnt[0], //remote command	  
  		 		  &theAnyStrings.c8d[0], //remote format
		 		  8,  //remchars 
		 		  182 //remnum
				 ,1,	 MIN_SATACNT,
			      MAX_SATACNT,
			     1);

#endif

#ifdef USE_HTTP

WebPassword.Init( &theAnyStrings.c8d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  170,//6,  //cntnum - function for control of value
				  170, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemWebPassword[0], //remote command	  
  		 		  &theAnyStrings.c8d[0], //remote format
		 		  8,  //remchars 
		 		  170 //remnum
			,1,	 MIN_WEBPASSWORD,
			 MAX_WEBPASSWORD,
			 1);

#endif

#ifdef PROG_PU_MSAT
SatRate.Init( &theAnyStrings.c8d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  173,//6,  //cntnum - function for control of value
				  173, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatRate[0], //remote command	  
  		 		  &theAnyStrings.c8d[0], //remote format
		 		  8,  //remchars 
		 		  173 //remnum
				 ,1,	 MIN_SATRATE,
			      MAX_SATRATE,
			     1);

SatTimer.Init( &theAnyStrings.c2d[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  2,  //chars
		  		  &theCntFunc, //pControl
				  174,//6,  //cntnum - function for control of value
				  174, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemSatTimer[0], //remote command	  
  		 		  &theAnyStrings.c2d[0], //remote format
		 		  2,  //remchars 
		 		  174 //remnum
				 ,1,	 MIN_SATTIMER,
			      MAX_SATTIMER,
			     1);





#endif



#ifdef YOURNAL

LogStr0.Init(
 					//&theAnyStrings.cCommandF[0]
 					"%24s",//char *,// pSetFormat, - format for makeresultsstr
                    1,// char,// SetXPos,
                    1,//  char,// SetYPos,
                    //   char SetChangable, 
                    //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      167, //  Uint16,// SetCntNum,
                      167,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemLogStr0[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  167//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

LogStr1.Init(
 					//&theAnyStrings.cCommandF[0]
 					"%24s",//char *,// pSetFormat, - format for makeresultsstr
                    1,// char,// SetXPos,
                    2,//  char,// SetYPos,
                    //   char SetChangable, 
                    //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      168, //  Uint16,// SetCntNum,
                      168,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemLogStr1[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  168//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

LogClear.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cLogClearV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					169,//161, //cntnum control of value
					169,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemLogClear[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					169//161  //remnum //selector for operation if receive remote command
										,0
);


#endif






#ifdef PROG_BMDN

AllConfigFileVersion.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      157, //  Uint16,// SetCntNum,
                      157,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  157//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

AllConfigFileVersion1.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      158, //  Uint16,// SetCntNum,
                      158,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion1[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  158//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

AllConfigFileVersion2.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      159, //  Uint16,// SetCntNum,
                      159,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion2[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  159//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

AllConfigFileVersion3.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      160, //  Uint16,// SetCntNum,
                      160,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion3[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  160//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

AllConfigFileVersion4.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      160, //  Uint16,// SetCntNum,
                      160,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion4[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c1400c[0],//  char *,// SetpRemFormat,
                 TBUFF2_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  160//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

AllConfigFileVersion5.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      160, //  Uint16,// SetCntNum,
                      160,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAllConfigFileVersion5[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c1400c[0],//  char *,// SetpRemFormat,
                 TBUFF2_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  160//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );




ModEth.Init( &theAnyStrings.c4X[0],  //format
  				  1, 1,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  161,//6,  //cntnum - function for control of value
				  161, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 1,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cModEth[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  161 //remnum
			   ,1,0,0,0);


#endif

#ifdef PROG_PU_M_V_A

AttData.Init( &theAnyStrings.c08X[0],  //format
  				  11, 2,  //x,y
				  1 ,		//  changable
	   			  ZeroStorage, //sweep in storage - new
				  8,  //chars
		  		  &theCntFunc, //pControl
				  175,//6,  //cntnum - function for control of value
				  175, //	6, //oprnum - operation if setted new value
				  &theAnyStrings.cmes0[0], // message line 0 
				  &theAnyStrings.cmes1[0], // mesaage line 1
   				  0, 0,//, 0//,		//  0 digit after point,hex			  
   				  0,  //init value
				  &theAnyStrings.cRemAttData[0], //remote command	  
  		 		  &theAnyStrings.c08X[0], //remote format
		 		  8,  //remchars 
		 		  175 //remnum
			,1,	 MIN_ATTDATA,
			 MAX_ATTDATA,
			 1);
#endif

#ifdef HAVE_GATEWAY
	
NetMask0.Init( &theAnyStrings.c2X[0],  //format
				   16, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    2,  //chars
					&theCntFunc, //pControl
				   244,//6,  //cntnum - function for control of value
				   244, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetMask0[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c2X[0], //remote format
		 2,  //remchars 
		 244 //remnum
		   //	  ,1,0,0,0);
			 ,1,0,255,1);

NetMask1.Init( &theAnyStrings.c2X[0],  //format
				   13, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    2,  //chars
					&theCntFunc, //pControl
				   245,//6,  //cntnum - function for control of value
				   245, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetMask1[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c2X[0], //remote format
		 2,  //remchars 
		 245 //remnum
			//  ,1,0,0,0);
		    ,1,0,255,1);

NetMask2.Init( &theAnyStrings.c2X[0],  //format
				   10, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    2,  //chars
					&theCntFunc, //pControl
				   246,//6,  //cntnum - function for control of value
				   246, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0xff,  //init value
		&theAnyStrings.cRemNetMask2[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c2X[0], //remote format
		 2,  //remchars 
		 246 //remnum
		  //	  ,1,0,0,0);
		   ,1,0,255,1);

NetMask3.Init( &theAnyStrings.c2X[0],  //format
//NetMask3.Init( &theAnyStrings.c3d[0],  //format
				   7, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
			 	    2,  //chars
			   //	    3,  //chars
					&theCntFunc, //pControl
				   247,//6,  //cntnum - function for control of value
				   247, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
					 	 0, 1//, 0//,		//  0 digit after point, hex			  
				 //		 0, 0//, 0//,		//  0 digit after point, dec			  
		//		4
		,0xff,  //init value
		&theAnyStrings.cRemNetMask3[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c2X[0], //remote format
		 2,  //remchars 
		 247 //remnum
		 //	  ,1,0,0,0);
		 ,1,0,255,1);


Network0.Init( &theAnyStrings.c3d[0],  //format
				   17, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    3,  //chars
					&theCntFunc, //pControl
				   248,//6,  //cntnum - function for control of value
				   248, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 0//, 0//,		//  0 digit after point, dec			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetwork0[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 248 //remnum
		   //	  ,1,0,0,0);
			 ,1,0,255,1);

Network1.Init( &theAnyStrings.c3d[0],  //format
				   13, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    3,  //chars
					&theCntFunc, //pControl
				   249,//6,  //cntnum - function for control of value
				   249, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 0//, 0//,		//  0 digit after point, dec			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetwork1[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 249 //remnum
		   //	  ,1,0,0,0);
			 ,1,0,255,1);


Network2.Init( &theAnyStrings.c3d[0],  //format
				   9, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    3,  //chars
					&theCntFunc, //pControl
				   250,//6,  //cntnum - function for control of value
				   250, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 0//, 0//,		//  0 digit after point, d			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetwork2[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 250 //remnum
		   //	  ,1,0,0,0);
			 ,1,0,255,1);


Network3.Init( &theAnyStrings.c3d[0],  //format
				   5, 2,  //x,y
				   1 ,		//changable
					ZeroStorage, //sweep in storage - new
				    3,  //chars
					&theCntFunc, //pControl
				   251,//6,  //cntnum - function for control of value
				   251, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
						 0, 0//, 0//,		//  0 digit after point,d			  
		//		4
		,0,  //init value
		&theAnyStrings.cRemNetwork3[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 251 //remnum
		   //	  ,1,0,0,0);
			 ,1,0,255,1);





		



#endif //HAVE_GATEWAY

#ifdef USE_SOCKETSD

IPAddressUDP.Init( &theAnyStrings.c08X[0],  //format
				   4, 2,  //x,y
				   1 ,		//changable
		   //		   &ExpertStorage.Clk0, //storageaddr
					IPAddressStorage, //sweep in storage - new
//				  40000000l,
				    8,  //chars
//					 3,
					&theCntFunc, //pControl
				   351,//6,  //cntnum - function for control of value
				   351, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
 					&theAnyStrings.cmes1[0], // mesaage line 1
			//		 1, 1, 0//,		//have sign, 1 digit after point, decimal			  
						 0, 1//, 0//,		//  0 digit after point, hex			  
		//		4
		,0x9B9B9B0F,  //init value
		&theAnyStrings.cRemIPAddressUDP[0] //remote command
	//	, &theAnyStrings.c8d[0], //remote format
		, &theAnyStrings.c08X[0], //remote format
		 18,  //remchars 
		 351 //remnum
					,1 ,0,255,1	);

#endif



#ifndef PROG_MD310_SATI

  LogoItem.Init(&theAnyStrings.cLogoLd[0], 
  //	&theAnyStrings.cConfig[0],
	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
 //t   NULL, NULL, NULL, &ConfigItem,
#ifndef PROG_PU_MSAT
   &LogoItem, &LogoItem,&LogoItem, &ConfigItem,
#else
    &LogoItem, &LogoItem,&LogoItem, &SatSystemItem,
#endif

#ifndef PROG_PU_MSAT
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

#else
  //	&SatLock, &SatXilBlock, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
 	&SatLock, &SatXilBlock, &SatTestModeI, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
   //	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);	//t
#endif
//___________________________________________
#ifndef PROG_PU_MSAT
  ConfigItem.Init(&theAnyStrings.cLogoLd[0], 
#else
  ConfigItem.Init(&theAnyStrings.cLogoLd1[0],
#endif
  	&theAnyStrings.cConfig[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
#ifndef PROG_PU_MSAT
 //   &ConfigItem, &ConfigItem, &LogoItem, &TestItem,
    &ConfigItem, &ConfigItem, &LogoItem, &XilinxItem,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

#else
//	  &SatSystemItem, &SatIndicationItem, &LogoItem, &TestItem,
 &SatSystemItem, &SatIndicationItem, &LogoItem, &XilinxItem,
	  NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

#endif
   
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
//141116  &TimeItem, &WebPasswordItem, &ConfigItem, NULL,
  &TimeItem, &NetMaskItem, &ConfigItem, NULL,
#endif
#else
   &XilinxItem, &AddressRS485Item, &ConfigItem, NULL,
#endif
  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
//___________________________________________

//______________________________________________________

 #ifdef PROG_PU_MSAT

   
 NetMaskItem.Init(&theAnyStrings.cNetMask[0], 
  	&theAnyStrings.cNetMaskL[0],
  //	&theAnyStrings.cIPAddrL[0],

 	1,
  &IPItem, &NetworkItem, &ConfigItem, NULL,
//  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
  NULL, NULL, NULL, NULL, NULL, &NetMask3,  &NetMask2, &NetMask1, &NetMask0, NULL, NULL);
  //NULL, NULL, NULL, NULL, NULL, &NetMask3,  &NetMask2, &NetMask1, &IPAddress0, NULL, NULL);
//___________________________________________
//______________________________________________________
   
 NetworkItem.Init(&theAnyStrings.cNetwork[0], 
  	&theAnyStrings.cIPAddrL[0],
  //	&theAnyStrings.cIPAddrL[0],

 	1,
  &NetMaskItem, &WebPasswordItem, &ConfigItem, NULL,
//  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
  NULL, NULL, NULL, NULL, NULL, &Network3,  &Network2, &Network1, &Network0, NULL, NULL);

 




#endif


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
//	 &AddressRS485Item, &SatALevItem, &ConfigItem, NULL,
	 &WebPasswordItem, &SatALevItem, &ConfigItem, NULL,
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
    &SatACodeItem, &XilinxItem, &ConfigItem, NULL,	  //130415
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
 // &TestItem, &DateItem, &ConfigItem, NULL, //140227
  &SatADemoItem, &DateItem, &ConfigItem, NULL, //140227
#else
//140227    &SatSet3Item, &IPItem, &ConfigItem, NULL,
  &SatADemoItem, &IPItem, &ConfigItem, NULL,	  //140227
#endif  
   
#endif
   NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, &XilFileData, NULL);

#ifdef USE_HTTP

 WebPasswordItem.Init(&theAnyStrings.cWebPassword[0], 
  	&theAnyStrings.cEmpty[0],
	1,
 //   &IPItem, &AddressRS485Item, &ConfigItem, NULL,
//141116  &IPItem, &IdItem, &ConfigItem, NULL,
  &NetworkItem, &IdItem, &ConfigItem, NULL,	  //141116
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
//___________________________________________

#ifdef PROG_PU_MSAT





 SatSet0Item.Init(&theAnyStrings.cSatSet0[0], 
  	&theAnyStrings.cEmpty[0],
//	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//120925    &SatTimingItem, &SatSet1Item, &SatSystemItem, NULL,
//    &SatFactoryItem, &SatSet1Item, &SatSystemItem, NULL,
 //1304161   &SatTFItem, &SatSet1Item, &SatSystemItem, NULL,
//130422    &SatTFItem, &SatSet8Item, &SatSystemItem, NULL,	//1304161
//130423    &SatRateItem, &SatSet8Item, &SatSystemItem, NULL,	//1304161
//130423    &CusDetItem, &SatSet8Item, &SatSystemItem, NULL,	//1304161
 //130517   &SatDFItem, &SatSet8Item, &CusDetItem, NULL,	//1304161
    &SatTimerItem, &SatSet8Item, &CusDetItem, NULL,	//130716
  	NULL, NULL, NULL,  NULL, NULL, &SatSet0, NULL, NULL, NULL,      NULL, NULL);

//______________________________________________________________130416_1
SatSet8Item.Init(&theAnyStrings.cSatSet8[0], 
  	&theAnyStrings.cEmpty[0],
//	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130409    &SatSet7Item, &SatTestModeItem, &SatSystemItem, NULL,
//130416    &SatSet6Item, &SatTestModeItem, &SatSystemItem, NULL,
//130423    &SatSet0Item, &SatSet1Item, &SatSystemItem, NULL,	 //130416
    &SatSet0Item, &SatSet6Item, &CusDetItem, NULL,	 //130416
  	NULL, NULL, NULL,  NULL, NULL, &SatSet8, NULL, NULL, NULL,      NULL, NULL);
//_________________________________________________________________130416_1



SatSet1Item.Init(&theAnyStrings.cSatSet1[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//1304161    &SatSet0Item, &SatSet2Item, &SatSystemItem, NULL,
//130423    &SatSet8Item, &SatSet2Item, &SatSystemItem, NULL,	//1304161
    &CusDetItem, &SatSet2Item, &SatSystemItem, NULL,	//1304161
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet1, NULL, NULL, NULL,      NULL, NULL);


SatSet2Item.Init(&theAnyStrings.cSatSet2[0], 
  //	&theAnyStrings.cEmpty[0],
	  &theAnyStrings.cMinus[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130415    &SatSet1Item, &SatSet3Item, &SatSystemItem, NULL,
    &SatSet1Item, &SatSet4Item, &SatSystemItem, NULL,	//130415
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet2, NULL, NULL, NULL,      NULL, NULL);

SatSet3Item.Init(&theAnyStrings.cSatSet3[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130415    &SatSet2Item, &SatSet4Item, &SatSystemItem, NULL,
//140227    &TestItem, &XilinxItem, &ConfigItem, NULL,	  //130415 moved to system menu group
 //&SatTimingItem, &XilinxItem, &SatSystemItem, NULL,	
#ifndef RECEIVE_MOD_LOCK
    &SatTimingItem, &SatSoundItem, &SatSystemItem, NULL,	//130412
#else
    &SatTimingItem, &SatExtLockItem, &SatSystemItem, NULL,	//130412
#endif


  	NULL, NULL, NULL,  NULL, NULL,     &SatSet3, NULL, NULL, NULL,      NULL, NULL);

SatSet4Item.Init(&theAnyStrings.cSatSet4[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130415    &SatSet3Item, &SatSet5Item, &SatSystemItem, NULL,
    &SatSet2Item, &SatSet5Item, &SatSystemItem, NULL, //130415
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet4, NULL, NULL, NULL,      NULL, NULL);

SatSet5Item.Init(&theAnyStrings.cSatSet5[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130423    &SatSet4Item, &SatSet6Item, &SatSystemItem, NULL,
//130423    &SatSet4Item, &SatSet7Item, &SatSystemItem, NULL,
    &SatSet4Item, &SatTestModeItem, &SatSystemItem, NULL,
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet5, NULL, NULL, NULL,      NULL, NULL);
//____________________________________________________________________-130423 cusdet
SatSet6Item.Init(&theAnyStrings.cSatSet6[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],

 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130409    &SatSet5Item, &SatSet7Item, &SatSystemItem, NULL,
//130416    &SatSet5Item, &SatSet8Item, &SatSystemItem, NULL,
//130423    &SatSet5Item, &SatDFItem, &SatSystemItem, NULL,//130416
    &SatSet8Item, &SatDFItem, &CusDetItem, NULL,//130416
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet6, NULL, NULL, NULL,      NULL, NULL);
//____________________________________________________________________-130423 cusdet

//___________________________________________________now do not used
SatSet7Item.Init(&theAnyStrings.cSatSet7[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130423    &SatSet6Item, &SatSet8Item, &SatSystemItem, NULL,
    &SatSet5Item, &SatSet8Item, &SatSystemItem, NULL,
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet7, NULL, NULL, NULL,      NULL, NULL);
//______________________________________________________now do not used

//__________________________________________________________________130416_
SatDFItem.Init(&theAnyStrings.cSatDF[0], 
  	&theAnyStrings.cEmpty[0],
	1,
//1304161    &SatSet6Item, &SatSet8Item, &SatSystemItem, NULL,
 //130423   &SatSet6Item, &SatTestModeItem, &SatSystemItem, NULL, //1304161
//130423    &SatSet5Item, &SatTestModeItem, &SatSystemItem, NULL, //1304161
//130517    &SatSet6Item, &SatSet0Item, &CusDetItem, NULL, //1304161
    &SatSet6Item, &SatTimerItem, &CusDetItem, NULL, //1304161
  	&SatDF, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
//__________________________________________________________________130416_

//______________________________________________________________________130517
SatTimerItem.Init(&theAnyStrings.cSatTimer[0], 
  	&theAnyStrings.cEmpty[0],
	1,
//1304161    &SatSet6Item, &SatSet8Item, &SatSystemItem, NULL,
 //130423   &SatSet6Item, &SatTestModeItem, &SatSystemItem, NULL, //1304161
//130423    &SatSet5Item, &SatTestModeItem, &SatSystemItem, NULL, //1304161
    &SatDFItem, &SatSet0Item, &CusDetItem, NULL, //1304161
  	NULL, NULL, NULL, NULL, NULL,   &SatTimer, NULL, NULL,  NULL,  NULL, NULL);




//______________________________________________________________________130517




//______________________________________________________________130416_1
	 /*
SatSet8Item.Init(&theAnyStrings.cSatSet8[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
//130409    &SatSet7Item, &SatTestModeItem, &SatSystemItem, NULL,
//130416    &SatSet6Item, &SatTestModeItem, &SatSystemItem, NULL,
    &SatDFItem, &SatTestModeItem, &SatSystemItem, NULL,	 //130416
  	NULL, NULL, NULL,  NULL, NULL,     &SatSet8, NULL, NULL, NULL,      NULL, NULL);
	*/
//_________________________________________________________________130416_1

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

#ifdef PROG_PU_MSAT1	
    &SatSet3Item, &SatLowPItem, &SatSystemItem, NULL,	
#else

#ifndef PROG_PU_MSAT3	
	&SatSet3Item, &SatTFItem, &SatSystemItem, NULL,	
#else
     &SatSet3Item, &SatLowPItem, &SatSystemItem, NULL,	
#endif


#endif    
    
     
  #else
 //	&SatExtLockPItem, &SatTFItem, &SatSystemItem, NULL,

#ifdef PROG_PU_MSAT1

#ifndef PROG_PU_MSAT4		
	&SatExtLockPItem, &SatLowPItem, &SatSystemItem, NULL,
#else
	&SatExtLockPItem, &SatTFItem, &SatSystemItem, NULL,	

#endif


#else
#ifndef PROG_PU_MSAT3	
	&SatExtLockPItem, &SatTFItem, &SatSystemItem, NULL,	
#else
   &SatExtLockPItem, &SatLowPItem, &SatSystemItem, NULL,

#endif


#endif    

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
#ifdef PROG_PU_MSAT1	

#ifndef PROG_PU_MSAT4
    &SatLowPItem, &SatRateItem, &SatSystemItem, NULL,  //130416
#else
    &SatSoundItem, &SatRateItem, &SatSystemItem, NULL,
#endif

#else

#ifndef PROG_PU_MSAT3	
	 &SatSoundItem, &SatRateItem, &SatSystemItem, NULL,  //130416
#else
    &SatLowPItem, &SatRateItem, &SatSystemItem, NULL, 
#endif


#endif

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

#ifndef 	PROG_PU_MSAT1
SatGet2Item.Init(&theAnyStrings.cSatGet2[0], 
  	&theAnyStrings.cEmpty[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet1Item, &SatGet3Item, &SatIndicationItem, NULL,
 //   &SatGet1Item, &SatInputItem, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet2, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
#else
SatGet2Item.Init(&theAnyStrings.cSatGet2[0], 
  	&theAnyStrings.cSatGet8[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
    &SatGet1Item, &SatGet3Item, &SatIndicationItem, NULL,
 //   &SatGet1Item, &SatInputItem, &SatIndicationItem, NULL,
  	NULL, NULL, NULL,  &SatGet2, &SatGet8,   NULL, NULL, NULL,  NULL,  NULL, NULL);



#endif



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



SatSystemItem.Init(&theAnyStrings.cLogoLd1[0], 
  	&theAnyStrings.cSatSystem[0],
 //	 &theAnyStrings.cVersion[0],
 	1,
//t 	 &LossItem, &CommandItem, &LogoItem, &ConfClkItem,
#ifndef YOURNAL
//130423    &SatIndicationItem, &ConfigItem, &LogoItem, &SatSet0Item,
    &SatIndicationItem, &ConfigItem, &LogoItem, &SatSet1Item,
#else
//130423    &SatLogItem, &ConfigItem, &LogoItem, &SatSet0Item,
    &SatLogItem, &ConfigItem, &LogoItem, &SatSet1Item,
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


#else //PROG_MD310_SATI

#ifndef PROG_MD310_SATI2

#include menu_310s.cpp

#else
#include menu_310s2.cpp
#endif


#endif

/*
 extern "C" Item::Init(char* l0, char* l1, 
 char v,Item* SetLeft,  Item* SetRight, Item* SetUp, Item* SetDown,
 MDataV * SetpDataP0, MDataV * SetpDataP1, MDataV * SetpDataP2,
 MDataI* SetpDataI0, MDataI* SetpDataI1,
 MDataC* SetpDataC0,MDataC* SetpDataC1, MDataC* SetpDataC2,MDataC* SetpDataC3,
 MDataS* SetpDataS0, MDataS* SetpDataS1)

*/



 UsedMenu.Init(&LogoItem, REDRAWPERIOD); //


//____________________________________________
//to use embisr  UsedPult.InitDevise(); //hier init hardware of pult



//
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RunCommand
* Returned Value   : none
* Comments         :
*    This routine is used to run command from remote 
*END*----------------------------------------------------------------------*/
 
extern "C" void RunCommand(char * pCommand)
{
  //usart1 channel	printfp("\n\r RunCommand\n\r");
#ifdef PROG_BACO
 return;
#endif

// printEthString(pCommand, 20); 	  //t
 //	printEthString("RunCommand", 20);

	IdCommand = 0;
	IdCommand += LockMode.RunRemoteC(pCommand, 16);

#ifdef TRAP_ENABLED
	IdCommand += TrapTimer.RunRemoteC(pCommand, 16);
	IdCommand += TrapIp.RunRemoteC(pCommand, 16);
#endif //TRAP_ENABLED

 //	IdCommand += ClkNumber.RunRemoteC(pCommand, 10);
    IdCommand += IPAddress.RunRemoteC(pCommand, 16);
#ifdef HAVE_GATEWAY
	 IdCommand += Network.RunRemoteC(pCommand, 16);
  	 IdCommand += NetMask.RunRemoteC(pCommand, 16);
#endif
	IdCommand += IPAddress0.RunRemoteC(pCommand, 10);
	IdCommand += IPAddress1.RunRemoteC(pCommand, 10);
	IdCommand += IPAddress2.RunRemoteC(pCommand, 10);
	IdCommand += IPAddress3.RunRemoteC(pCommand, 10);
//	IdCommand += VolNumber.RunRemoteI(pCommand); 
//	IdCommand += CommandData.RunRemoteV(pCommand);
 	IdCommand += DevData.RunRemoteS(pCommand);
	IdCommand += RestartData.RunRemoteV(pCommand);
	IdCommand += UARTAddress.RunRemoteC(pCommand, 10);
	IdCommand += DevId.RunRemoteC(pCommand, 16);
	IdCommand += DevYear.RunRemoteC(pCommand, 10);
	IdCommand += DevVer1.RunRemoteC(pCommand, 16);
	IdCommand += DevVer2.RunRemoteC(pCommand, 16);
	IdCommand += TestMode.RunRemoteC(pCommand, 16);
	IdCommand += POK.RunRemoteC(pCommand, 16);
	IdCommand += MAC0.RunRemoteC(pCommand, 16);
  	IdCommand += MAC1.RunRemoteC(pCommand, 16);
	IdCommand += XilFileData.RunRemoteS(pCommand);
#ifdef PROG_DMU6
    IdCommand += XilFileData2.RunRemoteS(pCommand);
#endif

#ifndef PROG_BMDN6MI
	IdCommand += XilFileData2.RunRemoteS(pCommand);
	IdCommand += XilFileData3.RunRemoteS(pCommand);
#endif

 	IdCommand += FileUpdate.RunRemoteS(pCommand);
	IdCommand += ProgVersion.RunRemoteS(pCommand);
	IdCommand += SBuffersState.RunRemoteC(pCommand, 16);
#ifdef PROG_TUTS
	IdCommand += TSInp.RunRemoteC(pCommand, 16);
	IdCommand += TSInpTrg.RunRemoteC(pCommand, 16);
 	IdCommand += TSOut.RunRemoteC(pCommand, 16);
#endif //PROG_TUTS

#ifdef PROG_BMD35
	IdCommand += RemoteMode.RunRemoteC(pCommand, 16);
#endif //PROG_BMD35

#ifdef PROG_PROV
	IdCommand += RemoteMode.RunRemoteC(pCommand, 16);
#endif //PROG_PROV


#ifdef PROG_MPC35
	IdCommand += RemoteMode.RunRemoteC(pCommand, 16);
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	IdCommand += RemoteMode.RunRemoteC(pCommand, 16);
#endif //PROG_MPC35



#ifdef PROG_DTVM
	IdCommand += RateData.RunRemoteV(pCommand);
	IdCommand += VideoData.RunRemoteV(pCommand);
	IdCommand += TestSignalData.RunRemoteV(pCommand);
	IdCommand += SoundData.RunRemoteV(pCommand);
	IdCommand += StateData.RunRemoteC(pCommand,10);
	IdCommand += ErrData.RunRemoteC(pCommand,10);
	IdCommand += PointData.RunRemoteC(pCommand,10);
	IdCommand += AddrData.RunRemoteC(pCommand,10);
   
#endif //PROG_DTVM

#ifdef PROG_KTVM
	IdCommand += RateData.RunRemoteV(pCommand);
	IdCommand += VideoData.RunRemoteV(pCommand);
	IdCommand += TestSignalData.RunRemoteV(pCommand);
	IdCommand += SoundData.RunRemoteV(pCommand);
	IdCommand += StateData.RunRemoteC(pCommand,10);
  //	IdCommand += ErrData.RunRemoteC(pCommand,10);
	IdCommand += PointData.RunRemoteC(pCommand,10);
	IdCommand += AddrData.RunRemoteC(pCommand,10);
#endif //PROG_KTVM   

#ifdef IncEmbIndicator
	IdCommand += KeyData.RunRemoteC(pCommand,10);
	IdCommand += IndData0.RunRemoteS(pCommand);
	IdCommand += IndData1.RunRemoteS(pCommand);
    IdCommand += CurData.RunRemoteC(pCommand,10);
	IdCommand += LedData.RunRemoteC(pCommand,10);

#endif //IncEmbIndicator

#ifdef CLOCK_ENABLED
	IdCommand += TimeData1.RunRemoteC(pCommand,10);
	IdCommand += TimeData2.RunRemoteC(pCommand,10);
	IdCommand += TimeData3.RunRemoteC(pCommand,10);
	IdCommand += TimeData4.RunRemoteC(pCommand,10);
	IdCommand += TimeData5.RunRemoteC(pCommand,10);
	IdCommand += TimeData6.RunRemoteC(pCommand,10);
#endif //

#ifdef YOURNAL
IdCommand += CRecord.RunRemoteS(pCommand);
#endif //YOURNAL

#ifdef PROG_BMDN
IdCommand += ConfigFile.RunRemoteC(pCommand,16);
//#ifndef PROG_BMDN6MI
IdCommand += ConfigFile1.RunRemoteC(pCommand,16);

#ifndef PROG_BMDN6MI
IdCommand += ConfigFile2.RunRemoteC(pCommand,16);
IdCommand += ConfigFile3.RunRemoteC(pCommand,16);
IdCommand += ConfigFile4.RunRemoteC(pCommand,16);
IdCommand += ConfigFile5.RunRemoteC(pCommand,16);
IdCommand += ConfigFile6.RunRemoteC(pCommand,16);
IdCommand += ConfigFile7.RunRemoteC(pCommand,16);
IdCommand += ConfigFile8.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile9.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile10.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile11.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile12.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile13.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile14.RunRemoteC(pCommand,16);
//IdCommand += ConfigFile15.RunRemoteC(pCommand,16);
#endif
IdCommand += ConfigFileVersion.RunRemoteS(pCommand);
IdCommand += AllConfigFileVersion.RunRemoteS(pCommand);
IdCommand += AllConfigFileVersion1.RunRemoteS(pCommand);
IdCommand += AllConfigFileVersion2.RunRemoteS(pCommand);
IdCommand += AllConfigFileVersion3.RunRemoteS(pCommand);


IdCommand += ModForSS.RunRemoteC(pCommand,16);
IdCommand += ModEth.RunRemoteC(pCommand,16);

IdCommand += XilFileDatax0.RunRemoteS(pCommand);
#ifndef PROG_BMDN6MI
IdCommand += XilFileDatax1.RunRemoteS(pCommand);
IdCommand += XilFileDatax2.RunRemoteS(pCommand);
IdCommand += XilFileDatax3.RunRemoteS(pCommand);
IdCommand += XilFileDatax4.RunRemoteS(pCommand);
IdCommand += XilFileDatax5.RunRemoteS(pCommand);
IdCommand += XilFileDatax6.RunRemoteS(pCommand);
IdCommand += XilFileDatax7.RunRemoteS(pCommand);
IdCommand += XilFileDatax8.RunRemoteS(pCommand);
/*
IdCommand += XilFileDatax9.RunRemoteS(pCommand);
IdCommand += XilFileDatax10.RunRemoteS(pCommand);
IdCommand += XilFileDatax11.RunRemoteS(pCommand);
IdCommand += XilFileDatax12.RunRemoteS(pCommand);
IdCommand += XilFileDatax13.RunRemoteS(pCommand);
IdCommand += XilFileDatax14.RunRemoteS(pCommand);
IdCommand += XilFileDatax15.RunRemoteS(pCommand);
*/

#endif
IdCommand += Priority0.RunRemoteC(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand += Priority1.RunRemoteC(pCommand,16);
IdCommand += Priority2.RunRemoteC(pCommand,16);
IdCommand += Priority3.RunRemoteC(pCommand,16);
IdCommand += Priority4.RunRemoteC(pCommand,16);
IdCommand += Priority5.RunRemoteC(pCommand,16);
IdCommand += Priority6.RunRemoteC(pCommand,16);
IdCommand += Priority7.RunRemoteC(pCommand,16);
IdCommand += Priority8.RunRemoteC(pCommand,16);
#endif

IdCommand += Threshold0.RunRemoteC(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand += Threshold1.RunRemoteC(pCommand,16);
IdCommand += Threshold2.RunRemoteC(pCommand,16);
IdCommand += Threshold3.RunRemoteC(pCommand,16);
IdCommand += Threshold4.RunRemoteC(pCommand,16);
IdCommand += Threshold5.RunRemoteC(pCommand,16);
IdCommand += Threshold6.RunRemoteC(pCommand,16);
IdCommand += Threshold7.RunRemoteC(pCommand,16);
IdCommand += Threshold8.RunRemoteC(pCommand,16);
#endif

IdCommand += Protect0.RunRemoteC(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand += Protect1.RunRemoteC(pCommand,16);
IdCommand += Protect2.RunRemoteC(pCommand,16);
IdCommand += Protect3.RunRemoteC(pCommand,16);
IdCommand += Protect4.RunRemoteC(pCommand,16);
IdCommand += Protect5.RunRemoteC(pCommand,16);
IdCommand += Protect6.RunRemoteC(pCommand,16);
IdCommand += Protect7.RunRemoteC(pCommand,16);
IdCommand += Protect8.RunRemoteC(pCommand,16);
IdCommand += Protect9.RunRemoteC(pCommand,16);
IdCommand += Protect10.RunRemoteC(pCommand,16);
IdCommand += Protect11.RunRemoteC(pCommand,16);
IdCommand += Protect12.RunRemoteC(pCommand,16);
IdCommand += Protect13.RunRemoteC(pCommand,16);
IdCommand += Protect14.RunRemoteC(pCommand,16);
IdCommand += Protect15.RunRemoteC(pCommand,16);
IdCommand += Protect16.RunRemoteC(pCommand,16);
IdCommand += Protect17.RunRemoteC(pCommand,16);
#endif

#endif //PROG_BMDN


#ifdef PROG_PRM_PCH_DEM
IdCommand += SymbolRate.RunRemoteC(pCommand,16);
IdCommand += FreqPCh.RunRemoteC(pCommand,16);
IdCommand += ModulSK.RunRemoteC(pCommand,16);
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL
IdCommand += XilFileData4.RunRemoteS(pCommand);
#endif // PROG_PRM_PCH_DEM_XIL
#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
IdCommand += DecFileData.RunRemoteS(pCommand);
#endif//+= DecFileData.RunRemoteS(pCommand);

#ifdef PROG_BMDN4
 IdCommand += OperateProg.RunRemoteS(pCommand);
#endif

#ifdef PROG_PU_M710
 IdCommand += OperateProg.RunRemoteS(pCommand);
#endif

#ifdef PROG_PU_MSAT
IdCommand += SatSet0.RunRemoteC(pCommand,10);
IdCommand += SatSet1.RunRemoteC(pCommand,10);
IdCommand += SatSet2.RunRemoteC(pCommand,10);
IdCommand += SatSet3.RunRemoteC(pCommand,10);
IdCommand += SatSet4.RunRemoteC(pCommand,10);
IdCommand += SatSet5.RunRemoteC(pCommand,10);
IdCommand += SatSet6.RunRemoteC(pCommand,10);
IdCommand += SatSet7.RunRemoteC(pCommand,10);
IdCommand += SatSet8.RunRemoteC(pCommand,10);

IdCommand += SatGet0.RunRemoteI(pCommand);
IdCommand += SatGet1.RunRemoteI(pCommand);
IdCommand += SatGet2.RunRemoteI(pCommand);
IdCommand += SatGet3.RunRemoteI(pCommand);
IdCommand += SatGet4.RunRemoteI(pCommand);
IdCommand += SatGet5.RunRemoteI(pCommand);
IdCommand += SatGet6.RunRemoteI(pCommand);
IdCommand += SatGet7.RunRemoteI(pCommand);
IdCommand += SatTestMode.RunRemoteV(pCommand);
IdCommand += SatPC.RunRemoteV(pCommand);

IdCommand += SatInput.RunRemoteV(pCommand);
IdCommand += SatLock.RunRemoteV(pCommand);
IdCommand += SatSearch.RunRemoteV(pCommand);
IdCommand += SatXilBlock.RunRemoteV(pCommand);

IdCommand += SatTiming.RunRemoteV(pCommand);

IdCommand += SatSound.RunRemoteV(pCommand);
IdCommand += SatFactory.RunRemoteV(pCommand);

IdCommand += SatDF.RunRemoteV(pCommand);
IdCommand += SatTF.RunRemoteV(pCommand);
IdCommand += SatRate.RunRemoteC(pCommand,16);
IdCommand += SatTimer.RunRemoteC(pCommand,16);

#endif

#ifdef USE_HTTP
IdCommand += WebPassword.RunRemoteC(pCommand,10);
#endif

#ifdef YOURNAL
IdCommand += LogClear.RunRemoteV(pCommand);
#endif

#ifdef PROG_MD310_SATI
	
IdCommand += RAnyConfig.RunRemoteS(pCommand);
IdCommand += RAnyConfig1.RunRemoteS(pCommand);
IdCommand += RAnyConfig2.RunRemoteS(pCommand);
IdCommand += RAnyConfig3.RunRemoteS(pCommand);
IdCommand += RAnyConfig4.RunRemoteS(pCommand);
IdCommand += RAnyConfig5.RunRemoteS(pCommand);
IdCommand += RAnyConfig6.RunRemoteS(pCommand);
IdCommand += RAnyConfig7.RunRemoteS(pCommand);
IdCommand += RAnyConfig8.RunRemoteS(pCommand);
IdCommand += RAnyConfig9.RunRemoteS(pCommand);
IdCommand += IFmoduleData.RunRemoteS(pCommand);
IdCommand += IFmoduleHeader.RunRemoteS(pCommand);

#endif

#ifdef USE_SOCKETSD
  IdCommand += IPAddressUDP.RunRemoteC(pCommand, 16);
#endif





/*	ClkNumber.RunRemoteC(pCommand, 10); 
	RemNumber.RunRemoteC(pCommand, 10); 
	VolNumber.RunRemoteI(pCommand); 
	ErrNumber.RunRemoteI(pCommand); 
	BerNumber.RunRemoteI(pCommand); 
	LossNumber.RunRemoteI(pCommand); 
	InsBerData.RunRemoteV(pCommand); 
	PolRtData.RunRemoteV(pCommand); 
	PolRdData.RunRemoteV(pCommand); 
	PolSdData.RunRemoteV(pCommand); 
	PolTtData.RunRemoteV(pCommand); 
  */	
	if(!IdCommand) //not property command
	{
		strcpy(pTBuff, "K1"); 
		for(int16 i = strlen("K1"); i > 0; i--)
		{
		pTBuff++;
		}
     *pTBuff++ = ';';
	}
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RunCommandS
* Returned Value   : none
* Comments         :
*    This routine is used to run command from snmp
*END*----------------------------------------------------------------------*/
 
extern "C" void RunCommandS(char * pCommand)
{
 //  printEthString("RunCommandS", 20);

	IdCommandS = 0;
	IdCommandS += LockMode.RunRemoteCS(pCommand, 16);

#ifdef TRAP_ENABLED
	IdCommandS += TrapTimer.RunRemoteCS(pCommand, 16);
	IdCommandS += TrapIp.RunRemoteCS(pCommand, 16);
#endif //TRAP_ENABLED

 //	IdCommandS += ClkNumber.RunRemoteCS(pCommand, 10);
 	IdCommandS += IPAddress.RunRemoteCS(pCommand, 16);
#ifdef HAVE_GATEWAY
	 IdCommandS += Network.RunRemoteCS(pCommand, 16);
 	 IdCommandS += NetMask.RunRemoteCS(pCommand, 16);
#endif

	IdCommandS += IPAddress0.RunRemoteCS(pCommand, 10);
	IdCommandS += IPAddress1.RunRemoteCS(pCommand, 10);
	IdCommandS += IPAddress2.RunRemoteCS(pCommand, 10);
	IdCommandS += IPAddress3.RunRemoteCS(pCommand, 10);
 // 	IdCommandS += CommandData.RunRemoteVS(pCommand);
 //	IdCommandS += VolNumber.RunRemoteIS(pCommand);
	IdCommandS += DevData.RunRemoteSS(pCommand);
    IdCommandS += RestartData.RunRemoteVS(pCommand);
	IdCommandS += UARTAddress.RunRemoteCS(pCommand, 10);
	IdCommandS += DevId.RunRemoteCS(pCommand, 16);
	IdCommandS += DevYear.RunRemoteCS(pCommand, 10);
	IdCommandS += DevVer1.RunRemoteCS(pCommand, 16);
	IdCommandS += DevVer2.RunRemoteCS(pCommand, 16);
	IdCommandS += TestMode.RunRemoteCS(pCommand, 16);
	IdCommandS += POK.RunRemoteCS(pCommand, 16);
	IdCommandS += Mf20Data.RunRemoteCS(pCommand, 16);
	IdCommandS += Mf20DataR.RunRemoteCS(pCommand, 16); 
	IdCommandS += TBuffer1.RunRemoteSS(pCommand);
	IdCommandS += TBuffer2.RunRemoteSS(pCommand);
	IdCommandS += MAC0.RunRemoteCS(pCommand, 16);
	IdCommandS += MAC1.RunRemoteCS(pCommand, 16);
	IdCommandS += XilFileData.RunRemoteSS(pCommand);
#ifdef PROG_DMU6
    IdCommandS += XilFileData2.RunRemoteSS(pCommand);
#endif

#ifndef PROG_BMDN6MI
	IdCommandS += XilFileData2.RunRemoteSS(pCommand);
	IdCommandS += XilFileData3.RunRemoteSS(pCommand);
#endif
	IdCommandS += FileUpdate.RunRemoteSS(pCommand);
	IdCommandS += ProgVersion.RunRemoteSS(pCommand);
	IdCommandS += SBuffersState.RunRemoteCS(pCommand, 16);
#ifdef PROG_TUTS
	IdCommandS += TSInp.RunRemoteCS(pCommand, 16);
	IdCommandS += TSInpTrg.RunRemoteCS(pCommand, 16);
 	IdCommandS += TSOut.RunRemoteCS(pCommand, 16);
#endif //PROG_TUTS

#ifdef PROG_BMD35
	IdCommandS += RemoteMode.RunRemoteCS(pCommand, 16);
#endif //PROG_BMD35

#ifdef PROG_PROV
	IdCommandS += RemoteMode.RunRemoteCS(pCommand, 16);
#endif //PROG_PROV


#ifdef PROG_MPC35
	IdCommandS += RemoteMode.RunRemoteCS(pCommand, 16);
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	IdCommandS += RemoteMode.RunRemoteCS(pCommand, 16);
#endif //PROG_MPC35




#ifdef PROG_DTVM
	IdCommandS += RateData.RunRemoteVS(pCommand);
	IdCommandS += VideoData.RunRemoteVS(pCommand);
	IdCommandS += TestSignalData.RunRemoteVS(pCommand);
	IdCommandS += SoundData.RunRemoteVS(pCommand);
	IdCommandS += StateData.RunRemoteCS(pCommand,10);
	IdCommandS += ErrData.RunRemoteCS(pCommand,10);
	IdCommandS += PointData.RunRemoteCS(pCommand,10);
	IdCommandS += AddrData.RunRemoteCS(pCommand,10);
   #endif //PROG_DTVM

#ifdef PROG_KTVM
	IdCommandS += RateData.RunRemoteVS(pCommand);
	IdCommandS += VideoData.RunRemoteVS(pCommand);
	IdCommandS += TestSignalData.RunRemoteVS(pCommand);
	IdCommandS += SoundData.RunRemoteVS(pCommand);
	IdCommandS += StateData.RunRemoteCS(pCommand,10);
 //	IdCommandS += ErrData.RunRemoteCS(pCommand,10);
	IdCommandS += PointData.RunRemoteCS(pCommand,10);
	IdCommandS += AddrData.RunRemoteCS(pCommand,10);
	
#endif //PROG_KTVM

#ifdef IncEmbIndicator
    IdCommandS += KeyData.RunRemoteCS(pCommand,10);
	IdCommandS += IndData0.RunRemoteSS(pCommand);
 	IdCommandS += IndData1.RunRemoteSS(pCommand);
	IdCommandS += CurData.RunRemoteCS(pCommand,10);
	IdCommandS += LedData.RunRemoteCS(pCommand,10);
#endif //IncEmbIndicator

#ifdef CLOCK_ENABLED
	IdCommandS += TimeData1.RunRemoteCS(pCommand,10);
	IdCommandS += TimeData2.RunRemoteCS(pCommand,10);
	IdCommandS += TimeData3.RunRemoteCS(pCommand,10);
	IdCommandS += TimeData4.RunRemoteCS(pCommand,10);
	IdCommandS += TimeData5.RunRemoteCS(pCommand,10);
	IdCommandS += TimeData6.RunRemoteCS(pCommand,10);
#endif //

#ifdef YOURNAL
IdCommandS += CRecord.RunRemoteSS(pCommand);
#endif //YOURNAL

#ifdef PROG_BMDN
IdCommandS += ConfigFile.RunRemoteCS(pCommand,16);
//#ifndef PROG_BMDN6MI
IdCommandS += ConfigFile1.RunRemoteCS(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommandS += ConfigFile2.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile3.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile4.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile5.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile6.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile7.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile8.RunRemoteCS(pCommand,16);
/*
IdCommandS += ConfigFile9.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile10.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile11.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile12.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile13.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile14.RunRemoteCS(pCommand,16);
IdCommandS += ConfigFile15.RunRemoteCS(pCommand,16);
*/
#endif

IdCommandS += ConfigFileVersion.RunRemoteSS(pCommand);
IdCommandS += AllConfigFileVersion.RunRemoteSS(pCommand);
IdCommandS += AllConfigFileVersion1.RunRemoteSS(pCommand);
IdCommandS += AllConfigFileVersion2.RunRemoteSS(pCommand);
IdCommandS += AllConfigFileVersion3.RunRemoteSS(pCommand);


IdCommandS += ModForSS.RunRemoteCS(pCommand,16);
IdCommandS += ModEth.RunRemoteCS(pCommand,16);

IdCommandS += XilFileDatax0.RunRemoteSS(pCommand);
#ifndef PROG_BMDN6MI
IdCommandS += XilFileDatax1.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax2.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax3.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax4.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax5.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax6.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax7.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax8.RunRemoteSS(pCommand);
/*
IdCommandS += XilFileDatax9.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax10.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax11.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax12.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax13.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax14.RunRemoteSS(pCommand);
IdCommandS += XilFileDatax15.RunRemoteSS(pCommand);
*/
#endif
IdCommandS += Priority0.RunRemoteCS(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommandS += Priority1.RunRemoteCS(pCommand,16);
IdCommandS += Priority2.RunRemoteCS(pCommand,16);
IdCommandS += Priority3.RunRemoteCS(pCommand,16);
IdCommandS += Priority4.RunRemoteCS(pCommand,16);
IdCommandS += Priority5.RunRemoteCS(pCommand,16);
IdCommandS += Priority6.RunRemoteCS(pCommand,16);
IdCommandS += Priority7.RunRemoteCS(pCommand,16);
IdCommandS += Priority8.RunRemoteCS(pCommand,16);
#endif
IdCommandS += Threshold0.RunRemoteCS(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommandS += Threshold1.RunRemoteCS(pCommand,16);
IdCommandS += Threshold2.RunRemoteCS(pCommand,16);
IdCommandS += Threshold3.RunRemoteCS(pCommand,16);
IdCommandS += Threshold4.RunRemoteCS(pCommand,16);
IdCommandS += Threshold5.RunRemoteCS(pCommand,16);
IdCommandS += Threshold6.RunRemoteCS(pCommand,16);
IdCommandS += Threshold7.RunRemoteCS(pCommand,16);
IdCommandS += Threshold8.RunRemoteCS(pCommand,16);
#endif
IdCommandS += Protect0.RunRemoteCS(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommandS += Protect1.RunRemoteCS(pCommand,16);
IdCommandS += Protect2.RunRemoteCS(pCommand,16);
IdCommandS += Protect3.RunRemoteCS(pCommand,16);
IdCommandS += Protect4.RunRemoteCS(pCommand,16);
IdCommandS += Protect5.RunRemoteCS(pCommand,16);
IdCommandS += Protect6.RunRemoteCS(pCommand,16);
IdCommandS += Protect7.RunRemoteCS(pCommand,16);
IdCommandS += Protect8.RunRemoteCS(pCommand,16);
IdCommandS += Protect9.RunRemoteCS(pCommand,16);
IdCommandS += Protect10.RunRemoteCS(pCommand,16);
IdCommandS += Protect11.RunRemoteCS(pCommand,16);
IdCommandS += Protect12.RunRemoteCS(pCommand,16);
IdCommandS += Protect13.RunRemoteCS(pCommand,16);
IdCommandS += Protect14.RunRemoteCS(pCommand,16);
IdCommandS += Protect15.RunRemoteCS(pCommand,16);
IdCommandS += Protect16.RunRemoteCS(pCommand,16);
IdCommandS += Protect17.RunRemoteCS(pCommand,16);
#endif
#endif //PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
IdCommandS += SymbolRate.RunRemoteCS(pCommand,16);
IdCommandS += FreqPCh.RunRemoteCS(pCommand,16);
IdCommandS += ModulSK.RunRemoteCS(pCommand,16);
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL
IdCommandS += XilFileData4.RunRemoteSS(pCommand);
#endif // PROG_PRM_PCH_DEM_XIL
#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
IdCommandS += DecFileData.RunRemoteSS(pCommand);
#endif//+= DecFileData.RunRemoteS(pCommand);
#ifdef PROG_BMDN4
 IdCommandS += OperateProg.RunRemoteSS(pCommand);
#endif

#ifdef PROG_PU_M710
 IdCommandS += OperateProg.RunRemoteSS(pCommand);
#endif


#ifdef PROG_PU_MSAT
IdCommandS += SatSet0.RunRemoteCS(pCommand,10);
IdCommandS += SatSet1.RunRemoteCS(pCommand,10);
IdCommandS += SatSet2.RunRemoteCS(pCommand,10);
IdCommandS += SatSet3.RunRemoteCS(pCommand,10);
IdCommandS += SatSet4.RunRemoteCS(pCommand,10);
IdCommandS += SatSet5.RunRemoteCS(pCommand,10);
IdCommandS += SatSet6.RunRemoteCS(pCommand,10);
IdCommandS += SatSet7.RunRemoteCS(pCommand,10);
IdCommandS += SatSet8.RunRemoteCS(pCommand,10);


IdCommandS += SatGet0.RunRemoteIS(pCommand);
IdCommandS += SatGet1.RunRemoteIS(pCommand);
IdCommandS += SatGet2.RunRemoteIS(pCommand);
IdCommandS += SatGet3.RunRemoteIS(pCommand);
IdCommandS += SatGet4.RunRemoteIS(pCommand);
IdCommandS += SatGet5.RunRemoteIS(pCommand);
IdCommandS += SatGet6.RunRemoteIS(pCommand);
IdCommandS += SatGet7.RunRemoteIS(pCommand);
IdCommandS += SatTestMode.RunRemoteVS(pCommand);
IdCommandS += SatPC.RunRemoteVS(pCommand);

IdCommandS += SatInput.RunRemoteVS(pCommand);
IdCommandS += SatLock.RunRemoteVS(pCommand);
IdCommandS += SatSearch.RunRemoteVS(pCommand);
IdCommandS += SatXilBlock.RunRemoteVS(pCommand);

IdCommandS += SatTiming.RunRemoteVS(pCommand);

IdCommandS += SatSound.RunRemoteVS(pCommand);
IdCommandS += SatFactory.RunRemoteVS(pCommand);

IdCommandS += SatDF.RunRemoteVS(pCommand);
IdCommandS += SatTF.RunRemoteVS(pCommand);
IdCommandS += SatRate.RunRemoteCS(pCommand,16);
IdCommandS += SatTimer.RunRemoteCS(pCommand,16);




#endif

#ifdef USE_HTTP
IdCommandS += WebPassword.RunRemoteCS(pCommand,10);
#endif



#ifdef YOURNAL
IdCommandS += LogClear.RunRemoteVS(pCommand);
#endif

#ifdef PROG_MD310_SATI
	
IdCommandS += RAnyConfig.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig1.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig2.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig3.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig4.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig5.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig6.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig7.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig8.RunRemoteSS(pCommand);
IdCommandS += RAnyConfig9.RunRemoteSS(pCommand);
IdCommandS += IFmoduleData.RunRemoteSS(pCommand);
IdCommandS += IFmoduleHeader.RunRemoteSS(pCommand);


#endif

#ifdef USE_SOCKETSD
  IdCommandS += IPAddressUDP.RunRemoteCS(pCommand, 16);
#endif






/*    
	ClkNumber.RunRemoteC(pCommand, 10); 
	RemNumber.RunRemoteC(pCommand, 10); 
	VolNumber.RunRemoteI(pCommand); 
	ErrNumber.RunRemoteI(pCommand); 
	BerNumber.RunRemoteI(pCommand); 
	LossNumber.RunRemoteI(pCommand); 
	InsBerData.RunRemoteV(pCommand); 
	PolRtData.RunRemoteV(pCommand); 
	PolRdData.RunRemoteV(pCommand); 
	PolSdData.RunRemoteV(pCommand); 
	PolTtData.RunRemoteV(pCommand); 
  */
  /*	
	if(!IdCommand) //not property command
	{
		strcpy(pTBuff, "K1"); 
		for(int16 i = strlen("K1"); i > 0; i--)
		{
		pTBuff++;
		}
     *pTBuff++ = ';';
	}
   */	 
   	if(!IdCommandS) //not property command
	{
		strcpy(pTBuffS, "K1"); 
		for(int16 i = strlen("K1"); i > 0; i--)
		{
		pTBuffS++;
		}
     *pTBuffS++ = ';';
	}

   }



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RunCommand0
* Returned Value   : none
* Comments         :
*    This routine is used to run command from remote  usart0
*END*----------------------------------------------------------------------*/
 
extern "C" void RunCommand0(char * pCommand)
{
//my usart channel  printfp("\n\r RunCommand0\n\r");


// printEthString("RunCommand0", 20);

	IdCommand0 = 0;
	IdCommand0 += LockMode.RunRemoteC0(pCommand, 16);

#ifdef TRAP_ENABLED
	IdCommand0 += TrapTimer.RunRemoteC0(pCommand, 16);
	IdCommand0 += TrapIp.RunRemoteC0(pCommand, 16);
#endif //TRAP_ENABLED


 //	IdCommand0 += ClkNumber.RunRemoteC0(pCommand, 10);
	IdCommand0 += IPAddress.RunRemoteC0(pCommand, 16);
#ifdef HAVE_GATEWAY
	 IdCommand0 += Network.RunRemoteC0(pCommand, 16);
 	 IdCommand0 += NetMask.RunRemoteC0(pCommand, 16);
#endif
	IdCommand0 += IPAddress0.RunRemoteC0(pCommand, 10);
	IdCommand0 += IPAddress1.RunRemoteC0(pCommand, 10);
	IdCommand0 += IPAddress2.RunRemoteC0(pCommand, 10);
	IdCommand0 += IPAddress3.RunRemoteC0(pCommand, 10);
//	IdCommand0 += VolNumber.RunRemoteI0(pCommand); 
 //	IdCommand0 += CommandData.RunRemoteV0(pCommand);
	IdCommand0 += DevData.RunRemoteS0(pCommand);
	IdCommand0 += RestartData.RunRemoteV0(pCommand);
	IdCommand0 += UARTAddress.RunRemoteC0(pCommand, 10);
	IdCommand0 += DevId.RunRemoteC0(pCommand, 16);
	IdCommand0 += DevYear.RunRemoteC0(pCommand, 10);
	IdCommand0 += DevVer1.RunRemoteC0(pCommand, 16);
	IdCommand0 += DevVer2.RunRemoteC0(pCommand, 16);
	IdCommand0 += TestMode.RunRemoteC0(pCommand, 16);
	IdCommand0 += POK.RunRemoteC0(pCommand, 16);
	IdCommand0 += MAC0.RunRemoteC0(pCommand, 16);
	IdCommand0 += MAC1.RunRemoteC0(pCommand, 16);
	IdCommand0 += XilFileData.RunRemoteS0(pCommand);
#ifdef PROG_DMU6
    IdCommand0 += XilFileData2.RunRemoteS0(pCommand);
#endif

#ifndef PROG_BMDN6MI
	IdCommand0 += XilFileData2.RunRemoteS0(pCommand);
	IdCommand0 += XilFileData3.RunRemoteS0(pCommand);
#endif
	IdCommand0 += FileUpdate.RunRemoteS0(pCommand);
	IdCommand0 += ProgVersion.RunRemoteS0(pCommand);
	IdCommand0 += SBuffersState.RunRemoteC0(pCommand, 16);
 #ifdef PROG_TUTS
	IdCommand0 += TSInp.RunRemoteC0(pCommand, 16);
	IdCommand0 += TSInpTrg.RunRemoteC0(pCommand, 16);
 	IdCommand0 += TSOut.RunRemoteC0(pCommand, 16);
#endif //PROG_TUTS

#ifdef PROG_BMD35
	IdCommand0 += RemoteMode.RunRemoteC0(pCommand, 16);
#endif //PROG_BMD35

#ifdef PROG_PROV
	IdCommand0 += RemoteMode.RunRemoteC0(pCommand, 16);
#endif //PROG_PROV


#ifdef PROG_MPC35
	IdCommand0 += RemoteMode.RunRemoteC0(pCommand, 16);
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	IdCommand0 += RemoteMode.RunRemoteC0(pCommand, 16);
#endif //PROG_MPC35




#ifdef PROG_DTVM
	IdCommand0 += RateData.RunRemoteV0(pCommand);
	IdCommand0 += VideoData.RunRemoteV0(pCommand);
	IdCommand0 += TestSignalData.RunRemoteV0(pCommand);
	IdCommand0 += SoundData.RunRemoteV0(pCommand);
	IdCommand0 += StateData.RunRemoteC0(pCommand,10);
	IdCommand0 += ErrData.RunRemoteC0(pCommand,10);
	IdCommand0 += PointData.RunRemoteC0(pCommand,10);
    IdCommand0 += AddrData.RunRemoteC0(pCommand,10);
	IdCommand0 += KeyData.RunRemoteC0(pCommand,10);
	IdCommand0 += IndData0.RunRemoteS0(pCommand);
	IdCommand0 += IndData1.RunRemoteS0(pCommand);
	IdCommand0 += CurData.RunRemoteC0(pCommand,10);
#endif //PROG_DTVM

#ifdef PROG_KTVM
	IdCommand0 += RateData.RunRemoteV0(pCommand);
	IdCommand0 += VideoData.RunRemoteV0(pCommand);
	IdCommand0 += TestSignalData.RunRemoteV0(pCommand);
	IdCommand0 += SoundData.RunRemoteV0(pCommand);
	IdCommand0 += StateData.RunRemoteC0(pCommand,10);
 //	IdCommand0 += ErrData.RunRemoteC0(pCommand,10);
	IdCommand0 += PointData.RunRemoteC0(pCommand,10);
    IdCommand0 += AddrData.RunRemoteC0(pCommand,10);
   

#endif //PROG_KTVM

#ifdef IncEmbIndicator
    IdCommand0 += KeyData.RunRemoteC0(pCommand,10);
	IdCommand0 += IndData0.RunRemoteS0(pCommand);
	IdCommand0 += IndData1.RunRemoteS0(pCommand);
	IdCommand0 += CurData.RunRemoteC0(pCommand,10);
	IdCommand0 += LedData.RunRemoteC0(pCommand,10);
#endif //IncEmbIndicator

#ifdef CLOCK_ENABLED
	IdCommand0 += TimeData1.RunRemoteC0(pCommand,10);
	IdCommand0 += TimeData2.RunRemoteC0(pCommand,10);
	IdCommand0 += TimeData3.RunRemoteC0(pCommand,10);
	IdCommand0 += TimeData4.RunRemoteC0(pCommand,10);
	IdCommand0 += TimeData5.RunRemoteC0(pCommand,10);
	IdCommand0 += TimeData6.RunRemoteC0(pCommand,10);
#endif //

#ifdef YOURNAL
IdCommand0 += CRecord.RunRemoteS0(pCommand);
#endif //YOURNAL

#ifdef PROG_BMDN
IdCommand0 += ConfigFile.RunRemoteC0(pCommand,16);
//#ifndef PROG_BMDN6MI
IdCommand0 += ConfigFile1.RunRemoteC0(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand0 += ConfigFile2.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile3.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile4.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile5.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile6.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile7.RunRemoteC0(pCommand,16);
IdCommand0 += ConfigFile8.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile9.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile10.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile11.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile12.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile13.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile14.RunRemoteC0(pCommand,16);
//IdCommand0 += ConfigFile15.RunRemoteC0(pCommand,16);
#endif

IdCommand0 += ConfigFileVersion.RunRemoteS0(pCommand);
IdCommand0 += AllConfigFileVersion.RunRemoteS0(pCommand);
IdCommand0 += AllConfigFileVersion1.RunRemoteS0(pCommand);
IdCommand0 += AllConfigFileVersion2.RunRemoteS0(pCommand);
IdCommand0 += AllConfigFileVersion3.RunRemoteS0(pCommand);


IdCommand0 += ModForSS.RunRemoteC0(pCommand,16);
IdCommand0 += ModEth.RunRemoteC0(pCommand,16);

IdCommand0 += XilFileDatax0.RunRemoteS0(pCommand);
#ifndef PROG_BMDN6MI
IdCommand0 += XilFileDatax1.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax2.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax3.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax4.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax5.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax6.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax7.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax8.RunRemoteS0(pCommand);
/*
IdCommand0 += XilFileDatax9.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax10.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax11.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax12.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax13.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax14.RunRemoteS0(pCommand);
IdCommand0 += XilFileDatax15.RunRemoteS0(pCommand);
 */
#endif

IdCommand0 += Priority0.RunRemoteC0(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand0 += Priority1.RunRemoteC0(pCommand,16);
IdCommand0 += Priority2.RunRemoteC0(pCommand,16);
IdCommand0 += Priority3.RunRemoteC0(pCommand,16);
IdCommand0 += Priority4.RunRemoteC0(pCommand,16);
IdCommand0 += Priority5.RunRemoteC0(pCommand,16);
IdCommand0 += Priority6.RunRemoteC0(pCommand,16);
IdCommand0 += Priority7.RunRemoteC0(pCommand,16);
IdCommand0 += Priority8.RunRemoteC0(pCommand,16);
#endif

IdCommand0 += Threshold0.RunRemoteC0(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand0 += Threshold1.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold2.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold3.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold4.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold5.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold6.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold7.RunRemoteC0(pCommand,16);
IdCommand0 += Threshold8.RunRemoteC0(pCommand,16);
#endif

IdCommand0 += Protect0.RunRemoteC0(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand0 += Protect1.RunRemoteC0(pCommand,16);
IdCommand0 += Protect2.RunRemoteC0(pCommand,16);
IdCommand0 += Protect3.RunRemoteC0(pCommand,16);
IdCommand0 += Protect4.RunRemoteC0(pCommand,16);
IdCommand0 += Protect5.RunRemoteC0(pCommand,16);
IdCommand0 += Protect6.RunRemoteC0(pCommand,16);
IdCommand0 += Protect7.RunRemoteC0(pCommand,16);
IdCommand0 += Protect8.RunRemoteC0(pCommand,16);
IdCommand0 += Protect9.RunRemoteC0(pCommand,16);
IdCommand0 += Protect10.RunRemoteC0(pCommand,16);
IdCommand0 += Protect11.RunRemoteC0(pCommand,16);
IdCommand0 += Protect12.RunRemoteC0(pCommand,16);
IdCommand0 += Protect13.RunRemoteC0(pCommand,16);
IdCommand0 += Protect14.RunRemoteC0(pCommand,16);
IdCommand0 += Protect15.RunRemoteC0(pCommand,16);
IdCommand0 += Protect16.RunRemoteC0(pCommand,16);
IdCommand0 += Protect17.RunRemoteC0(pCommand,16);
#endif



#endif //PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
IdCommand0 += SymbolRate.RunRemoteC0(pCommand,16);
IdCommand0 += FreqPCh.RunRemoteC0(pCommand,16);
IdCommand0 += ModulSK.RunRemoteC0(pCommand,16);
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL
IdCommand0 += XilFileData4.RunRemoteS0(pCommand);
#endif // PROG_PRM_PCH_DEM_XIL

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
IdCommand0 += DecFileData.RunRemoteS0(pCommand);
#endif//+= DecFileData.RunRemoteS(pCommand);

#ifdef PROG_BMDN4
 IdCommand0 += OperateProg.RunRemoteS0(pCommand);
#endif

#ifdef PROG_PU_M710
  IdCommand0 += OperateProg.RunRemoteS0(pCommand);
#endif

#ifdef PROG_PU_MSAT
IdCommand0 += SatSet0.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet1.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet2.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet3.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet4.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet5.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet6.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet7.RunRemoteC0(pCommand,10);
IdCommand0 += SatSet8.RunRemoteC0(pCommand,10);


IdCommand0 += SatGet0.RunRemoteI0(pCommand);
IdCommand0 += SatGet1.RunRemoteI0(pCommand);
IdCommand0 += SatGet2.RunRemoteI0(pCommand);
IdCommand0 += SatGet3.RunRemoteI0(pCommand);
IdCommand0 += SatGet4.RunRemoteI0(pCommand);
IdCommand0 += SatGet5.RunRemoteI0(pCommand);
IdCommand0 += SatGet6.RunRemoteI0(pCommand);
IdCommand0 += SatGet7.RunRemoteI0(pCommand);
IdCommand0 += SatTestMode.RunRemoteV0(pCommand);
IdCommand0 += SatPC.RunRemoteV0(pCommand);

IdCommand0 += SatInput.RunRemoteV0(pCommand);
IdCommand0 += SatLock.RunRemoteV0(pCommand);
IdCommand0 += SatSearch.RunRemoteV0(pCommand);
IdCommand0 += SatXilBlock.RunRemoteV0(pCommand);
IdCommand0 += SatTiming.RunRemoteV0(pCommand);

IdCommand0 += SatSound.RunRemoteV0(pCommand);
IdCommand0 += SatFactory.RunRemoteV0(pCommand);

IdCommand0 += SatDF.RunRemoteV0(pCommand);
IdCommand0 += SatTF.RunRemoteV0(pCommand);
IdCommand0 += SatRate.RunRemoteC0(pCommand,16);
IdCommand0 += SatTimer.RunRemoteC0(pCommand,16);


#endif

#ifdef USE_HTTP
IdCommand0 += WebPassword.RunRemoteC0(pCommand,10);
#endif


#ifdef YOURNAL
IdCommand0 += LogClear.RunRemoteV0(pCommand);
#endif

#ifdef PROG_MD310_SATI
	
IdCommand0 += RAnyConfig.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig1.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig2.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig3.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig4.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig5.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig6.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig7.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig8.RunRemoteS0(pCommand);
IdCommand0 += RAnyConfig9.RunRemoteS0(pCommand);
IdCommand0 += IFmoduleData.RunRemoteS0(pCommand);
IdCommand0 += IFmoduleHeader.RunRemoteS0(pCommand);
#endif

#ifdef USE_SOCKETSD
  IdCommand0 += IPAddressUDP.RunRemoteC0(pCommand, 16);
#endif


/*	ClkNumber.RunRemoteC(pCommand, 10); 
	RemNumber.RunRemoteC(pCommand, 10); 
	VolNumber.RunRemoteI(pCommand); 
	ErrNumber.RunRemoteI(pCommand); 
	BerNumber.RunRemoteI(pCommand); 
	LossNumber.RunRemoteI(pCommand); 
	InsBerData.RunRemoteV(pCommand); 
	PolRtData.RunRemoteV(pCommand); 
	PolRdData.RunRemoteV(pCommand); 
	PolSdData.RunRemoteV(pCommand); 
	PolTtData.RunRemoteV(pCommand); 
  */	
	if(!IdCommand0) //not property command
	{
		pTBuff0_control(strlen("K1"));
		strcpy(pTBuff0, "K1"); 
		for(int16 i = strlen("K1"); i > 0; i--)
		{
		pTBuff0++;
		}
	 pTBuff0_control(1l);
     *pTBuff0++ = ';';
	}
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :RunCommand3
* Returned Value   : none
* Comments         :
*    This routine is used to run command from remote usart3
*END*----------------------------------------------------------------------*/
 
extern "C" void RunCommand3(char * pCommand)
{
  // printEthString("RunCommand3", 20);
//my ethernet channel  printfp("\n\r RunCommand3\n\r");


	IdCommand3 = 0;
	IdCommand3 += LockMode.RunRemoteC3(pCommand, 16);

#ifdef TRAP_ENABLED
	IdCommand3 += TrapTimer.RunRemoteC3(pCommand, 16);
	IdCommand3 += TrapIp.RunRemoteC3(pCommand, 16);
#endif //TRAP_ENABLED

 //	IdCommand3 += ClkNumber.RunRemoteC3(pCommand, 10);
     IdCommand3  += IPAddress.RunRemoteC3(pCommand, 16);
#ifdef HAVE_GATEWAY
	 IdCommand3 += Network.RunRemoteC3(pCommand, 16);
	 IdCommand3 += NetMask.RunRemoteC3(pCommand, 16);
#endif
//141014	 	IdCommand3 += IPAddress0.RunRemoteC3(pCommand, 10);
 //141014		IdCommand3 += IPAddress1.RunRemoteC3(pCommand, 10);
 //141014		IdCommand3 += IPAddress2.RunRemoteC3(pCommand, 10);
 //141014		IdCommand3 += IPAddress3.RunRemoteC3(pCommand, 10);
 //	IdCommand3 += VolNumber.RunRemoteI3(pCommand); 
 //	IdCommand3 += CommandData.RunRemoteV3(pCommand);
	IdCommand3 += DevData.RunRemoteS3(pCommand);
	IdCommand3 += RestartData.RunRemoteV3(pCommand);
	IdCommand3 += UARTAddress.RunRemoteC3(pCommand, 10);
	IdCommand3 += DevId.RunRemoteC3(pCommand, 16);
	IdCommand3 += DevYear.RunRemoteC3(pCommand, 10);
	IdCommand3 += DevVer1.RunRemoteC3(pCommand, 16);
	IdCommand3 += DevVer2.RunRemoteC3(pCommand, 16);
	IdCommand3 += TestMode.RunRemoteC3(pCommand, 16);
	IdCommand3 += POK.RunRemoteC3(pCommand, 16);
	IdCommand3  += MAC0.RunRemoteC3(pCommand, 16);
	IdCommand3  += MAC1.RunRemoteC3(pCommand, 16);
	IdCommand3 += XilFileData.RunRemoteS3(pCommand);
#ifdef PROG_DMU6
    IdCommand3 += XilFileData2.RunRemoteS3(pCommand);
#endif


#ifndef PROG_BMDN6MI
    IdCommand3 += XilFileData2.RunRemoteS3(pCommand);
    IdCommand3 += XilFileData3.RunRemoteS3(pCommand);
#endif
 	IdCommand3 += FileUpdate.RunRemoteS3(pCommand);
	IdCommand3 += ProgVersion.RunRemoteS3(pCommand);
	IdCommand3 += SBuffersState.RunRemoteC3(pCommand, 16);

#ifdef PROG_TUTS
	IdCommand3 += TSInp.RunRemoteC3(pCommand, 16);
	IdCommand3 += TSInpTrg.RunRemoteC3(pCommand, 16);
 	IdCommand3 += TSOut.RunRemoteC3(pCommand, 16);
#endif //PROG_TUTS

#ifdef PROG_BMD35
	IdCommand3 += RemoteMode.RunRemoteC3(pCommand, 16);
#endif //PROG_BMD35

#ifdef PROG_MPC35
	IdCommand3 += RemoteMode.RunRemoteC3(pCommand, 16);
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	IdCommand3 += RemoteMode.RunRemoteC3(pCommand, 16);
#endif //PROG_MPC35




#ifdef PROG_DTVM
	IdCommand3 += RateData.RunRemoteV3(pCommand);
	IdCommand3 += VideoData.RunRemoteV3(pCommand);
	IdCommand3 += TestSignalData.RunRemoteV3(pCommand);
	IdCommand3 += SoundData.RunRemoteV3(pCommand);
	IdCommand3 += StateData.RunRemoteC3(pCommand,10);
	IdCommand3 += ErrData.RunRemoteC3(pCommand,10);
	IdCommand3 += PointData.RunRemoteC3(pCommand,10);
	IdCommand3 += AddrData.RunRemoteC3(pCommand,10);
  
#endif //PROG_DTVM

#ifdef PROG_KTVM
	IdCommand3 += RateData.RunRemoteV3(pCommand);
	IdCommand3 += VideoData.RunRemoteV3(pCommand);
	IdCommand3 += TestSignalData.RunRemoteV3(pCommand);
	IdCommand3 += SoundData.RunRemoteV3(pCommand);
	IdCommand3 += StateData.RunRemoteC3(pCommand,10);
  //	IdCommand3 += ErrData.RunRemoteC3(pCommand,10);
	IdCommand3 += PointData.RunRemoteC3(pCommand,10);
	IdCommand3 += AddrData.RunRemoteC3(pCommand,10);
   


#endif //PROG_KTVM

#ifdef IncEmbIndicator
	IdCommand3 += KeyData.RunRemoteC3(pCommand,10);
	IdCommand3 += IndData0.RunRemoteS3(pCommand);
	IdCommand3 += IndData1.RunRemoteS3(pCommand);
	IdCommand3 += CurData.RunRemoteC3(pCommand,10);
	IdCommand3 += LedData.RunRemoteC3(pCommand,10);
#endif //IncEmbIndicator

#ifdef CLOCK_ENABLED
	IdCommand3 += TimeData1.RunRemoteC3(pCommand,10);
	IdCommand3 += TimeData2.RunRemoteC3(pCommand,10);
	IdCommand3 += TimeData3.RunRemoteC3(pCommand,10);
	IdCommand3 += TimeData4.RunRemoteC3(pCommand,10);
	IdCommand3 += TimeData5.RunRemoteC3(pCommand,10);
	IdCommand3 += TimeData6.RunRemoteC3(pCommand,10);
#endif //

#ifdef YOURNAL
IdCommand3 += CRecord.RunRemoteS3(pCommand);
#endif //YOURNAL

#ifdef PROG_BMDN
IdCommand3 += ConfigFile.RunRemoteC3(pCommand,16);
//#ifndef PROG_BMDN6MI
IdCommand3 += ConfigFile1.RunRemoteC3(pCommand,16);
#ifndef PROG_BMDN6MI


IdCommand3 += ConfigFile2.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile3.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile4.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile5.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile6.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile7.RunRemoteC3(pCommand,16);
IdCommand3 += ConfigFile8.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile9.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile10.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile11.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile12.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile13.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile14.RunRemoteC3(pCommand,16);
//IdCommand3 += ConfigFile15.RunRemoteC3(pCommand,16);
#endif

IdCommand3 += ConfigFileVersion.RunRemoteS3(pCommand);
IdCommand3 += AllConfigFileVersion.RunRemoteS3(pCommand);
IdCommand3 += AllConfigFileVersion1.RunRemoteS3(pCommand);
IdCommand3 += AllConfigFileVersion2.RunRemoteS3(pCommand);
IdCommand3 += AllConfigFileVersion3.RunRemoteS3(pCommand);
IdCommand3 += AllConfigFileVersion4.RunRemoteSB3(pCommand);
IdCommand3 += AllConfigFileVersion5.RunRemoteSB3(pCommand);



IdCommand3 += ModForSS.RunRemoteC3(pCommand,16);
IdCommand3 += ModEth.RunRemoteC3(pCommand,16);

IdCommand3 += XilFileDatax0.RunRemoteS3(pCommand);
#ifndef PROG_BMDN6MI
IdCommand3 += XilFileDatax1.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax2.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax3.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax4.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax5.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax6.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax7.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax8.RunRemoteS3(pCommand);
/*
IdCommand3 += XilFileDatax9.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax10.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax11.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax12.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax13.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax14.RunRemoteS3(pCommand);
IdCommand3 += XilFileDatax15.RunRemoteS3(pCommand);
*/
#endif

IdCommand3 += Priority0.RunRemoteC3(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand3 += Priority1.RunRemoteC3(pCommand,16);
IdCommand3 += Priority2.RunRemoteC3(pCommand,16);
IdCommand3 += Priority3.RunRemoteC3(pCommand,16);
IdCommand3 += Priority4.RunRemoteC3(pCommand,16);
IdCommand3 += Priority5.RunRemoteC3(pCommand,16);
IdCommand3 += Priority6.RunRemoteC3(pCommand,16);
IdCommand3 += Priority7.RunRemoteC3(pCommand,16);
IdCommand3 += Priority8.RunRemoteC3(pCommand,16);
#endif
IdCommand3 += Threshold0.RunRemoteC3(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand3 += Threshold1.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold2.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold3.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold4.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold5.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold6.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold7.RunRemoteC3(pCommand,16);
IdCommand3 += Threshold8.RunRemoteC3(pCommand,16);
#endif
IdCommand3 += Protect0.RunRemoteC3(pCommand,16);
#ifndef PROG_BMDN6MI
IdCommand3 += Protect1.RunRemoteC3(pCommand,16);
IdCommand3 += Protect2.RunRemoteC3(pCommand,16);
IdCommand3 += Protect3.RunRemoteC3(pCommand,16);
IdCommand3 += Protect4.RunRemoteC3(pCommand,16);
IdCommand3 += Protect5.RunRemoteC3(pCommand,16);
IdCommand3 += Protect6.RunRemoteC3(pCommand,16);
IdCommand3 += Protect7.RunRemoteC3(pCommand,16);
IdCommand3 += Protect8.RunRemoteC3(pCommand,16);
IdCommand3 += Protect9.RunRemoteC3(pCommand,16);
IdCommand3 += Protect10.RunRemoteC3(pCommand,16);
IdCommand3 += Protect11.RunRemoteC3(pCommand,16);
IdCommand3 += Protect12.RunRemoteC3(pCommand,16);
IdCommand3 += Protect13.RunRemoteC3(pCommand,16);
IdCommand3 += Protect14.RunRemoteC3(pCommand,16);
IdCommand3 += Protect15.RunRemoteC3(pCommand,16);
IdCommand3 += Protect16.RunRemoteC3(pCommand,16);
IdCommand3 += Protect17.RunRemoteC3(pCommand,16);
#endif
#endif //PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
IdCommand3 += SymbolRate.RunRemoteC3(pCommand,16);
IdCommand3 += FreqPCh.RunRemoteC3(pCommand,16);
IdCommand3 += ModulSK.RunRemoteC3(pCommand,16);
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL
IdCommand3 += XilFileData4.RunRemoteS3(pCommand);
#endif // PROG_PRM_PCH_DEM_XIL

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
IdCommand3 += DecFileData.RunRemoteS3(pCommand);
#endif//+= DecFileData.RunRemoteS(pCommand);

#ifdef PROG_BMDN4
 IdCommand3 += OperateProg.RunRemoteS3(pCommand);
#endif

#ifdef PROG_PU_M710
 IdCommand3 += OperateProg.RunRemoteS3(pCommand);
#endif

#ifdef PROG_PU_MSAT
IdCommand3 += SatSet0.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet1.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet2.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet3.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet4.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet5.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet6.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet7.RunRemoteC3(pCommand,10);
IdCommand3 += SatSet8.RunRemoteC3(pCommand,10);


IdCommand3 += SatGet0.RunRemoteI3(pCommand);
IdCommand3 += SatGet1.RunRemoteI3(pCommand);
IdCommand3 += SatGet2.RunRemoteI3(pCommand);
IdCommand3 += SatGet3.RunRemoteI3(pCommand);
IdCommand3 += SatGet4.RunRemoteI3(pCommand);
IdCommand3 += SatGet5.RunRemoteI3(pCommand);
IdCommand3 += SatGet6.RunRemoteI3(pCommand);
IdCommand3 += SatGet7.RunRemoteI3(pCommand);
IdCommand3 += SatTestMode.RunRemoteV3(pCommand);
IdCommand3 += SatPC.RunRemoteV3(pCommand);

IdCommand3 += SatInput.RunRemoteV3(pCommand);
IdCommand3 += SatLock.RunRemoteV3(pCommand);
IdCommand3 += SatSearch.RunRemoteV3(pCommand);
IdCommand3 += SatXilBlock.RunRemoteV3(pCommand);

IdCommand3 += SatTiming.RunRemoteV3(pCommand);

IdCommand3 += SatSound.RunRemoteV3(pCommand);
IdCommand3 += SatFactory.RunRemoteV3(pCommand);

IdCommand3 += SatDF.RunRemoteV3(pCommand);
IdCommand3 += SatTF.RunRemoteV3(pCommand);
IdCommand3 += SatRate.RunRemoteC3(pCommand, 16);
IdCommand3 += SatTimer.RunRemoteC3(pCommand,16);


#endif

#ifdef USE_HTTP
IdCommand3 += WebPassword.RunRemoteC3(pCommand,10);
#endif


#ifdef YOURNAL
IdCommand3 += LogClear.RunRemoteV3(pCommand);
#endif

#ifdef PROG_MD310_SATI
	
IdCommand3 += RAnyConfig.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig1.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig2.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig3.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig4.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig5.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig6.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig7.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig8.RunRemoteS3(pCommand);
IdCommand3 += RAnyConfig9.RunRemoteS3(pCommand);
IdCommand3 += IFmoduleData.RunRemoteS3(pCommand);
IdCommand3 += IFmoduleHeader.RunRemoteS3(pCommand);

#endif








/*	ClkNumber.RunRemoteC(pCommand, 10); 
	RemNumber.RunRemoteC(pCommand, 10); 
	VolNumber.RunRemoteI(pCommand); 
	ErrNumber.RunRemoteI(pCommand); 
	BerNumber.RunRemoteI(pCommand); 
	LossNumber.RunRemoteI(pCommand); 
	InsBerData.RunRemoteV(pCommand); 
	PolRtData.RunRemoteV(pCommand); 
	PolRdData.RunRemoteV(pCommand); 
	PolSdData.RunRemoteV(pCommand); 
	PolTtData.RunRemoteV(pCommand); 
  */	
	if(!IdCommand3) //not property command
	{
		strcpy(pTBuff3, "K1"); 
		for(int16 i = strlen("K1"); i > 0; i--)
		{
		pTBuff3++;
		}
     *pTBuff3++ = ';';
	}
}


extern "C" unsigned char CheckNetMask(unsigned long mask)
{

unsigned char ret = 1;
unsigned long flag = 1l;

 if(mask == 0xFFFFFFFFl) ret = 0;
// printfpd("\n\r mask = %x\n\r", mask);

for( unsigned i	= 0; i < 32; i++)
{
// printfpd(" i = %d ", i);
  if(flag & mask)
  {
   flag <<= 1;
 //  printfpd("\n\rbreak i = %d \n\r", i);
   break;
   }
  flag <<= 1;
}

for( unsigned j	= i + 1; j < 32; j++)
{

 // printfpd(" j = %d ", j);

  if(!(flag & mask))
  {

 //  printfpd("\n\rbreak j = %d \n\r", j);

   ret = 0; 
   break;
  }

  flag <<= 1;
}
 // printfpd("\n\r ret = %x\n\r", ret);

 return ret;
}


extern "C" unsigned char ReadDevId(unsigned char flag_lock)
{


//return;	  //t


 char Buf[DEV_ID_SIZE];
 unsigned int DeviceAddress = ID_ADDRESS;
 read_dataflash (DeviceAddress, DEV_ID_SIZE, (char *)&Buf[0]);
// read_dataflash (DeviceAddress, DEV_ID_SIZE+100, (char *)&Buf[0]);
 read_flag = 1;



//__________________________________________________crc
unsigned char flag_crc = 0;
unsigned char id_crc = 0;
unsigned long check_ver = 0;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

check_ver = ( ((unsigned long)Buf[485] << 24) + ((unsigned long)Buf[486] << 16) 
 	+ ((unsigned long)Buf[487] << 8) +  (unsigned long)Buf[488]);



 if(id_crc == Buf[DEV_ID_SIZE - 1])	
 {
    flag_crc = 1;
  //	printfp("\n\r1");
   if(start_main_loop) printfp("\n\r ReadDevId checksum ok!");	
 }
 else
 {
    if(start_main_loop) printfp("\n\r ReadDevId checksum wrong!");	

   read_dataflash (ID_ADDRESS3, DEV_ID_SIZE, (char *)&Buf[0]);	   //new address

id_crc = 0;	  //150831	!!!!!!!!


for( icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

check_ver = ( ((unsigned long)Buf[485] << 24) + ((unsigned long)Buf[486] << 16) 
 	+ ((unsigned long)Buf[487] << 8) +  (unsigned long)Buf[488]);



 if(id_crc == Buf[DEV_ID_SIZE - 1])	
 {
    flag_crc = 1;
  //	printfp("\n\r1");
 }
 else  //need use first address for id to property change old wersions of prog without this feature
 {

  read_dataflash (ID_ADDRESS, DEV_ID_SIZE, (char *)&Buf[0]); //150120


 }

 }

//__________________________________________________crc

 DevId.Value =  (float64) (((unsigned int)Buf[0] << 8) + (unsigned int)Buf[1]);
 DevId.ChangingValue = DevId.Value;
 DevYear.Value = (float64)( ((unsigned int)Buf[2] << 8) + (unsigned int)Buf[3]);
 DevYear.ChangingValue =  DevYear.Value;
 DevVer1.Value = (float64)( ((unsigned int)Buf[4] << 8) + (unsigned int)Buf[5]);
 DevVer1.ChangingValue =  DevVer1.Value;
 DevVer2.Value = (float64)( ((unsigned int)Buf[6] << 8) + (unsigned int)Buf[7]);
 DevVer2.ChangingValue =  DevVer2.Value;
 POK.Value = (float64)( ((unsigned int)Buf[8] << 8) + (unsigned int)Buf[9]);
 POK.ChangingValue =  POK.Value;
 MAC0.Value = (float64)( ((unsigned int)Buf[10] << 16) + ((unsigned int)Buf[11] << 8) + (unsigned int)Buf[12]);
 MAC0.ChangingValue =  MAC0.Value;
 MAC1.Value = (float64)( ((unsigned int)Buf[13] << 16) + ((unsigned int)Buf[14] << 8) + (unsigned int)Buf[15]);
 MAC1.ChangingValue =  MAC1.Value;
 IPAddress.Value = (float64)( ((unsigned int)Buf[16] << 24) + ((unsigned int)Buf[17] << 16) 
 	+ ((unsigned int)Buf[18] << 8) +  (unsigned int)Buf[19]);
 IPAddress.ChangingValue =  IPAddress.Value;
	 /*
  if((!flag_crc) && (check_ver == SOFT_VER))
  {
  	
	DevId.Value = DEFAULT_ID; //0x1234;
	DevId.ChangingValue = DevId.Value;
	DevVer1.Value = DEFAULT_VER; //0;
    DevVer1.ChangingValue =  DevVer1.Value;
	DevVer2.Value = DEFAULT_VER; //0;
 	DevVer2.ChangingValue =  DevVer2.Value;
	POK.Value = DEFAULT_POK;//0;	 //set not 0x1000
 	POK.ChangingValue =  POK.Value;
	MAC0.Value = DEFAULT_MAC0; //0x001111;
 	MAC0.ChangingValue =  MAC0.Value;
  	MAC1.Value = DEFAULT_MAC1; //0x001234;
 	MAC1.ChangingValue =  MAC0.Value;
	IPAddress.Value = DEFAULT_IP; //0x9B9B9b0f;
  	IPAddress.ChangingValue =  IPAddress.Value;
  }
	  */

if(!flag_crc) 
  {
  	
#ifdef HAVE_GATEWAY
	NetMask.Value = DEFAULT_MASK; 
	NetMask.ChangingValue =  NetMask.Value;
#endif

  }



 MakeIPAddresses();
 TestMode.Value = (float64)( ((unsigned int)Buf[20] << 24) + ((unsigned int)Buf[21] << 16) 
 	+ ((unsigned int)Buf[22] << 8) +  (unsigned int)Buf[23]);
 TestMode.ChangingValue =  TestMode.Value;

 UARTAddress.Value = (float64)( ((unsigned int)Buf[24] << 24) + ((unsigned int)Buf[25] << 16) 
 	+ ((unsigned int)Buf[26] << 8) +  (unsigned int)Buf[27]);
 UARTAddress.ChangingValue =  UARTAddress.Value;


#ifdef PROG_TUTS
 TSOut.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 TSOut.ChangingValue =  TSOut.Value;

#endif //PROG_TUTS

#ifdef PROG_BMD35
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_BMD35

#ifdef PROG_PROV
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_PROV


#ifdef PROG_MPC35
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_MPC35

#ifdef KTVM_PROT2
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //KTVM_PROT2

#ifdef  LOCK_ENABLED  //091111
 /*101117  do not enable keep
 LockMode.Value = (float64)( ((unsigned int)Buf[32] << 24) + ((unsigned int)Buf[33] << 16) 
 	+ ((unsigned int)Buf[34] << 8) +  (unsigned int)Buf[35]);
 LockMode.ChangingValue =  LockMode.Value;
 */

//091111#ifdef  LOCK_ENABLED
//091111	 	 if(LockMode.Value == 1)  SetBufferState((unsigned long)LOCK_MODE1);  //not write unlock
//091111	 	 if(LockMode.Value == 2)   SetBufferState((unsigned long)LOCK_MODE2);  //only read
/* 101117  do not enable keep
		 if(LockMode.Value == 3)   SetBufferState((unsigned long)LOCK_MODE3);  //full +
		 else {LockMode.Value = 0; LockMode.ChangingValue =  LockMode.Value; SetBufferState((unsigned long)LOCK_MODE2);}	 //091111 keep after reboot only key5
*/

if(!flag_lock)
{
  LockMode.Value = 0; LockMode.ChangingValue =  LockMode.Value; SetBufferState((unsigned long)LOCK_MODE2);
}

#endif // LOCK_ENABLED
// OID_ptr = (uchar_ptr)&OID[0];
// sprintf((char *)OID_ptr, "%08X",(uint_32)DevId.Value);

#ifdef TRAP_ENABLED

TrapTimer.Value = (float64)( ((unsigned int)Buf[36] << 24) + ((unsigned int)Buf[37] << 16) 
 	+ ((unsigned int)Buf[38] << 8) +  (unsigned int)Buf[39]);
 TrapTimer.ChangingValue =  TrapTimer.Value;

TrapIp.Value = (float64)( ((unsigned int)Buf[40] << 24) + ((unsigned int)Buf[41] << 16) 
 	+ ((unsigned int)Buf[42] << 8) +  (unsigned int)Buf[43]);
 TrapIp.ChangingValue =  TrapIp.Value;


#endif //TRAP_ENABLED 

#ifdef 	PROG_PRM_PCH_N_2

RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
#endif
  /* it is maked in prm_pch_L
#ifdef 	PROG_PRM_PCH_SPI

RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
#endif
 */



#ifdef 	PROG_PRM_PCH_L
RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(2, ((unsigned int)Buf[52] << 24) + ((unsigned int)Buf[53] << 16) 
 	+ ((unsigned int)Buf[54] << 8) +  (unsigned int)Buf[55]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(3, ((unsigned int)Buf[60] << 24) + ((unsigned int)Buf[61] << 16) 
 	+ ((unsigned int)Buf[62] << 8) +  (unsigned int)Buf[63]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);
RestoreAttRPU(1, ((unsigned int)Buf[68] << 24) + ((unsigned int)Buf[69] << 16) 
	+ ((unsigned int)Buf[70] << 8) +  (unsigned int)Buf[71]);
RestoreAttRPU(2, ((unsigned int)Buf[72] << 24) + ((unsigned int)Buf[73] << 16) 
	+ ((unsigned int)Buf[74] << 8) +  (unsigned int)Buf[75]);
RestoreAttRPU(3, ((unsigned int)Buf[76] << 24) + ((unsigned int)Buf[77] << 16) 
	+ ((unsigned int)Buf[78] << 8) +  (unsigned int)Buf[79]);
#endif // PROG_PRM_PCH_L

#ifdef 	PROG_PRM_PCH_L
RestoreFreq(4, ((unsigned int)Buf[80] << 24) + ((unsigned int)Buf[81] << 16) 
 	+ ((unsigned int)Buf[82] << 8) +  (unsigned int)Buf[83]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(5, ((unsigned int)Buf[84] << 24) + ((unsigned int)Buf[85] << 16) 
 	+ ((unsigned int)Buf[86] << 8) +  (unsigned int)Buf[87]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(6, ((unsigned int)Buf[88] << 24) + ((unsigned int)Buf[89] << 16) 
 	+ ((unsigned int)Buf[90] << 8) +  (unsigned int)Buf[91]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);
RestoreAttRPU(4, ((unsigned int)Buf[92] << 24) + ((unsigned int)Buf[93] << 16) 
	+ ((unsigned int)Buf[94] << 8) +  (unsigned int)Buf[95]);
RestoreAttRPU(5, ((unsigned int)Buf[96] << 24) + ((unsigned int)Buf[97] << 16) 
	+ ((unsigned int)Buf[98] << 8) +  (unsigned int)Buf[99]);
RestoreAttRPU(6, ((unsigned int)Buf[100] << 24) + ((unsigned int)Buf[101] << 16) 
	+ ((unsigned int)Buf[102] << 8) +  (unsigned int)Buf[103]);
#endif // PROG_PRM_PCH_L

#ifdef PROG_BMDN
//_________________________________________________________________________
ConfigFile.Value = (float64)( ((unsigned int)Buf[104] << 24) + ((unsigned int)Buf[105] << 16) 
 	+ ((unsigned int)Buf[106] << 8) +  (unsigned int)Buf[107]);
 ConfigFile.ChangingValue =  ConfigFile.Value;
//__________________________________________________________________________
//#ifndef PROG_BMDN6MI
//_________________________________________________________________________
ConfigFile1.Value = (float64)( ((unsigned int)Buf[108] << 24) + ((unsigned int)Buf[109] << 16) 
 	+ ((unsigned int)Buf[110] << 8) +  (unsigned int)Buf[111]);
 ConfigFile1.ChangingValue =  ConfigFile1.Value;
//_________________________________________________________________________
#ifndef PROG_BMDN6MI


ConfigFile2.Value = (float64)( ((unsigned int)Buf[112] << 24) + ((unsigned int)Buf[113] << 16) 
 	+ ((unsigned int)Buf[114] << 8) +  (unsigned int)Buf[115]);
 ConfigFile2.ChangingValue =  ConfigFile2.Value;
//_________________________________________________________________________
ConfigFile3.Value = (float64)( ((unsigned int)Buf[116] << 24) + ((unsigned int)Buf[117] << 16) 
 	+ ((unsigned int)Buf[118] << 8) +  (unsigned int)Buf[119]);
 ConfigFile3.ChangingValue =  ConfigFile3.Value;
//_________________________________________________________________________
ConfigFile4.Value = (float64)( ((unsigned int)Buf[120] << 24) + ((unsigned int)Buf[121] << 16) 
 	+ ((unsigned int)Buf[122] << 8) +  (unsigned int)Buf[123]);
 ConfigFile4.ChangingValue =  ConfigFile4.Value;
//_________________________________________________________________________
ConfigFile5.Value = (float64)( ((unsigned int)Buf[124] << 24) + ((unsigned int)Buf[125] << 16) 
 	+ ((unsigned int)Buf[126] << 8) +  (unsigned int)Buf[127]);
 ConfigFile5.ChangingValue =  ConfigFile5.Value;
//_________________________________________________________________________
ConfigFile6.Value = (float64)( ((unsigned int)Buf[128] << 24) + ((unsigned int)Buf[129] << 16) 
 	+ ((unsigned int)Buf[130] << 8) +  (unsigned int)Buf[131]);
 ConfigFile6.ChangingValue =  ConfigFile6.Value;
//_________________________________________________________________________
ConfigFile7.Value = (float64)( ((unsigned int)Buf[132] << 24) + ((unsigned int)Buf[133] << 16) 
 	+ ((unsigned int)Buf[134] << 8) +  (unsigned int)Buf[135]);
 ConfigFile7.ChangingValue =  ConfigFile7.Value;
//_________________________________________________________________________
ConfigFile8.Value = (float64)( ((unsigned int)Buf[136] << 24) + ((unsigned int)Buf[137] << 16) 
 	+ ((unsigned int)Buf[138] << 8) +  (unsigned int)Buf[139]);
 ConfigFile8.ChangingValue =  ConfigFile8.Value;
//_________________________________________________________________________
ConfigFile9.Value = (float64)( ((unsigned int)Buf[140] << 24) + ((unsigned int)Buf[141] << 16) 
 	+ ((unsigned int)Buf[142] << 8) +  (unsigned int)Buf[143]);
 ConfigFile9.ChangingValue =  ConfigFile9.Value;
//_________________________________________________________________________
ConfigFile10.Value = (float64)( ((unsigned int)Buf[144] << 24) + ((unsigned int)Buf[145] << 16) 
 	+ ((unsigned int)Buf[146] << 8) +  (unsigned int)Buf[147]);
 ConfigFile10.ChangingValue =  ConfigFile10.Value;
//_________________________________________________________________________
ConfigFile11.Value = (float64)( ((unsigned int)Buf[148] << 24) + ((unsigned int)Buf[149] << 16) 
 	+ ((unsigned int)Buf[150] << 8) +  (unsigned int)Buf[151]);
 ConfigFile11.ChangingValue =  ConfigFile11.Value;
//_________________________________________________________________________
ConfigFile12.Value = (float64)( ((unsigned int)Buf[152] << 24) + ((unsigned int)Buf[153] << 16) 
 	+ ((unsigned int)Buf[154] << 8) +  (unsigned int)Buf[155]);
 ConfigFile12.ChangingValue =  ConfigFile12.Value;
//_________________________________________________________________________
ConfigFile13.Value = (float64)( ((unsigned int)Buf[156] << 24) + ((unsigned int)Buf[157] << 16) 
 	+ ((unsigned int)Buf[158] << 8) +  (unsigned int)Buf[159]);
 ConfigFile13.ChangingValue =  ConfigFile13.Value;
//_________________________________________________________________________
ConfigFile14.Value = (float64)( ((unsigned int)Buf[160] << 24) + ((unsigned int)Buf[161] << 16) 
 	+ ((unsigned int)Buf[162] << 8) +  (unsigned int)Buf[163]);
 ConfigFile14.ChangingValue =  ConfigFile14.Value;
//_________________________________________________________________________
ConfigFile15.Value = (float64)( ((unsigned int)Buf[164] << 24) + ((unsigned int)Buf[165] << 16) 
 	+ ((unsigned int)Buf[166] << 8) +  (unsigned int)Buf[167]);
 ConfigFile15.ChangingValue =  ConfigFile15.Value;
#endif
//_________________________________________________________________________

if(flag_crc)
{
ModForSS.Value = (float64)( ((unsigned int)Buf[168] << 24) + ((unsigned int)Buf[169] << 16) 
 	+ ((unsigned int)Buf[170] << 8) +  (unsigned int)Buf[171]);
}
else
{
 ModForSS.Value = 1; //one trunk mode for bmdn6; do not operate power md310
}

 ModForSS.ChangingValue =  ModForSS.Value;

if(!((unsigned long)ModForSS.Value & 2l))
{
  ClearBufferState((unsigned long)OPERATE_POWER_ON);
}
 else
{
  SetBufferState((unsigned long)OPERATE_POWER_ON);
}


//___________________________________________________________________________
Priority0.Value = (float64)( ((unsigned int)Buf[172] << 24) + ((unsigned int)Buf[173] << 16) 
 	+ ((unsigned int)Buf[174] << 8) +  (unsigned int)Buf[175]);
Priority0.ChangingValue =  Priority0.Value;

#ifndef PROG_BMDN6MI
//___________________________________________________________________________
Priority1.Value = (float64)( ((unsigned int)Buf[176] << 24) + ((unsigned int)Buf[177] << 16) 
 	+ ((unsigned int)Buf[178] << 8) +  (unsigned int)Buf[179]);
Priority1.ChangingValue =  Priority1.Value;
//___________________________________________________________________________
Priority2.Value = (float64)( ((unsigned int)Buf[180] << 24) + ((unsigned int)Buf[181] << 16) 
 	+ ((unsigned int)Buf[182] << 8) +  (unsigned int)Buf[183]);
Priority2.ChangingValue =  Priority2.Value;
//___________________________________________________________________________
Priority3.Value = (float64)( ((unsigned int)Buf[184] << 24) + ((unsigned int)Buf[185] << 16) 
 	+ ((unsigned int)Buf[186] << 8) +  (unsigned int)Buf[187]);
Priority3.ChangingValue =  Priority3.Value;
//___________________________________________________________________________
Priority4.Value = (float64)( ((unsigned int)Buf[188] << 24) + ((unsigned int)Buf[189] << 16) 
 	+ ((unsigned int)Buf[190] << 8) +  (unsigned int)Buf[191]);
Priority4.ChangingValue =  Priority4.Value;
//___________________________________________________________________________
Priority5.Value = (float64)( ((unsigned int)Buf[192] << 24) + ((unsigned int)Buf[193] << 16) 
 	+ ((unsigned int)Buf[194] << 8) +  (unsigned int)Buf[195]);
Priority5.ChangingValue =  Priority5.Value;
//___________________________________________________________________________
Priority6.Value = (float64)( ((unsigned int)Buf[196] << 24) + ((unsigned int)Buf[197] << 16) 
 	+ ((unsigned int)Buf[198] << 8) +  (unsigned int)Buf[199]);
Priority6.ChangingValue =  Priority6.Value;
//___________________________________________________________________________
Priority7.Value = (float64)( ((unsigned int)Buf[200] << 24) + ((unsigned int)Buf[201] << 16) 
 	+ ((unsigned int)Buf[202] << 8) +  (unsigned int)Buf[203]);
Priority7.ChangingValue =  Priority7.Value;
//___________________________________________________________________________
Priority8.Value = (float64)( ((unsigned int)Buf[204] << 24) + ((unsigned int)Buf[205] << 16) 
 	+ ((unsigned int)Buf[206] << 8) +  (unsigned int)Buf[207]);
Priority8.ChangingValue =  Priority8.Value;
#endif


//___________________________________________________________________________
Threshold0.Value = (float64)( ((unsigned int)Buf[208] << 24) + ((unsigned int)Buf[209] << 16) 
 	+ ((unsigned int)Buf[210] << 8) +  (unsigned int)Buf[211]);
Threshold0.ChangingValue =  Threshold0.Value;

#ifndef PROG_BMDN6MI
//___________________________________________________________________________
Threshold1.Value = (float64)( ((unsigned int)Buf[212] << 24) + ((unsigned int)Buf[213] << 16) 
 	+ ((unsigned int)Buf[214] << 8) +  (unsigned int)Buf[215]);
Threshold1.ChangingValue =  Threshold1.Value;
//___________________________________________________________________________
Threshold2.Value = (float64)( ((unsigned int)Buf[216] << 24) + ((unsigned int)Buf[217] << 16) 
 	+ ((unsigned int)Buf[218] << 8) +  (unsigned int)Buf[219]);
Threshold2.ChangingValue =  Threshold2.Value;
//___________________________________________________________________________
Threshold3.Value = (float64)( ((unsigned int)Buf[220] << 24) + ((unsigned int)Buf[221] << 16) 
 	+ ((unsigned int)Buf[222] << 8) +  (unsigned int)Buf[223]);
Threshold3.ChangingValue =  Threshold3.Value;
//___________________________________________________________________________
Threshold4.Value = (float64)( ((unsigned int)Buf[224] << 24) + ((unsigned int)Buf[225] << 16) 
 	+ ((unsigned int)Buf[226] << 8) +  (unsigned int)Buf[227]);
Threshold4.ChangingValue =  Threshold4.Value;
//___________________________________________________________________________
Threshold5.Value = (float64)( ((unsigned int)Buf[228] << 24) + ((unsigned int)Buf[229] << 16) 
 	+ ((unsigned int)Buf[230] << 8) +  (unsigned int)Buf[231]);
Threshold5.ChangingValue =  Threshold5.Value;
//___________________________________________________________________________
Threshold6.Value = (float64)( ((unsigned int)Buf[232] << 24) + ((unsigned int)Buf[233] << 16) 
 	+ ((unsigned int)Buf[234] << 8) +  (unsigned int)Buf[235]);
Threshold6.ChangingValue =  Threshold6.Value;
//___________________________________________________________________________
Threshold7.Value = (float64)( ((unsigned int)Buf[236] << 24) + ((unsigned int)Buf[237] << 16) 
 	+ ((unsigned int)Buf[238] << 8) +  (unsigned int)Buf[239]);
Threshold7.ChangingValue =  Threshold7.Value;
//___________________________________________________________________________
Threshold8.Value = (float64)( ((unsigned int)Buf[240] << 24) + ((unsigned int)Buf[241] << 16) 
 	+ ((unsigned int)Buf[242] << 8) +  (unsigned int)Buf[243]);
Threshold8.ChangingValue =  Threshold8.Value;
#endif
#endif
//___________________________________________________________________________
#ifdef PROG_PU_M_V
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif

#ifdef PROG_PU_M_V_A
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif // PROG_PU_M_V_A


#ifdef PROG_UPS
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif




#ifdef PROG_PRM_PCH_DEM
//_________________________________________________________________________
SymbolRate.Value = (float64)( ((unsigned int)Buf[278] << 24) + ((unsigned int)Buf[279] << 16) 
 	+ ((unsigned int)Buf[280] << 8) +  (unsigned int)Buf[281]);
 SymbolRate.ChangingValue =  SymbolRate.Value;
FreqPCh.Value = (float64)( ((unsigned int)Buf[282] << 24) + ((unsigned int)Buf[283] << 16) 
 	+ ((unsigned int)Buf[284] << 8) +  (unsigned int)Buf[285]);
 FreqPCh.ChangingValue =  FreqPCh.Value;
ModulSK.Value = (float64)( ((unsigned int)Buf[286] << 24) + ((unsigned int)Buf[287] << 16) 
 	+ ((unsigned int)Buf[288] << 8) +  (unsigned int)Buf[289]);
 ModulSK.ChangingValue =  ModulSK.Value;



/*
MDataC	SymbolRate;
MDataC	FreqPCh;
MDataC	ModulSK;
 */
#endif

#ifdef PROG_BMDN

Protect0.Value = (float64)( ((unsigned int)Buf[290] << 24) + ((unsigned int)Buf[291] << 16) 
 	+ ((unsigned int)Buf[292] << 8) +  (unsigned int)Buf[293]);
Protect0.ChangingValue =  Protect0.Value;
SetProt(0, Protect0.Value);

#ifndef PROG_BMDN6MI

Protect1.Value = (float64)( ((unsigned int)Buf[294] << 24) + ((unsigned int)Buf[295] << 16) 
 	+ ((unsigned int)Buf[296] << 8) +  (unsigned int)Buf[297]);
Protect1.ChangingValue =  Protect1.Value;
SetProt(1, Protect1.Value);
Protect2.Value = (float64)( ((unsigned int)Buf[298] << 24) + ((unsigned int)Buf[299] << 16) 
 	+ ((unsigned int)Buf[300] << 8) +  (unsigned int)Buf[301]);
Protect2.ChangingValue =  Protect2.Value;
SetProt(2, Protect2.Value);

Protect3.Value = (float64)( ((unsigned int)Buf[302] << 24) + ((unsigned int)Buf[303] << 16) 
 	+ ((unsigned int)Buf[304] << 8) +  (unsigned int)Buf[305]);
Protect3.ChangingValue =  Protect3.Value;
SetProt(3, Protect3.Value);

Protect4.Value = (float64)( ((unsigned int)Buf[306] << 24) + ((unsigned int)Buf[307] << 16) 
 	+ ((unsigned int)Buf[308] << 8) +  (unsigned int)Buf[309]);
Protect4.ChangingValue =  Protect4.Value;
SetProt(4, Protect4.Value);

Protect5.Value = (float64)( ((unsigned int)Buf[310] << 24) + ((unsigned int)Buf[311] << 16) 
 	+ ((unsigned int)Buf[312] << 8) +  (unsigned int)Buf[313]);
Protect5.ChangingValue =  Protect5.Value;
SetProt(5, Protect5.Value);

Protect6.Value = (float64)( ((unsigned int)Buf[314] << 24) + ((unsigned int)Buf[315] << 16) 
 	+ ((unsigned int)Buf[316] << 8) +  (unsigned int)Buf[317]);
Protect6.ChangingValue =  Protect6.Value;
SetProt(6, Protect6.Value);

Protect7.Value = (float64)( ((unsigned int)Buf[318] << 24) + ((unsigned int)Buf[319] << 16) 
 	+ ((unsigned int)Buf[320] << 8) +  (unsigned int)Buf[321]);
Protect7.ChangingValue =  Protect7.Value;
SetProt(7, Protect7.Value);

Protect8.Value = (float64)( ((unsigned int)Buf[322] << 24) + ((unsigned int)Buf[323] << 16) 
 	+ ((unsigned int)Buf[324] << 8) +  (unsigned int)Buf[325]);
Protect8.ChangingValue =  Protect8.Value;
SetProt(8, Protect8.Value);

Protect9.Value = (float64)( ((unsigned int)Buf[326] << 24) + ((unsigned int)Buf[327] << 16) 
 	+ ((unsigned int)Buf[328] << 8) +  (unsigned int)Buf[329]);
Protect9.ChangingValue =  Protect9.Value;
SetProt(9, Protect9.Value);

Protect10.Value = (float64)( ((unsigned int)Buf[330] << 24) + ((unsigned int)Buf[331] << 16) 
 	+ ((unsigned int)Buf[332] << 8) +  (unsigned int)Buf[333]);
Protect10.ChangingValue =  Protect10.Value;
SetProt(10, Protect10.Value);

Protect11.Value = (float64)( ((unsigned int)Buf[334] << 24) + ((unsigned int)Buf[335] << 16) 
 	+ ((unsigned int)Buf[336] << 8) +  (unsigned int)Buf[337]);
Protect11.ChangingValue =  Protect11.Value;
SetProt(11, Protect11.Value);

Protect12.Value = (float64)( ((unsigned int)Buf[338] << 24) + ((unsigned int)Buf[339] << 16) 
 	+ ((unsigned int)Buf[340] << 8) +  (unsigned int)Buf[341]);
Protect12.ChangingValue =  Protect12.Value;
SetProt(12, Protect12.Value);

Protect13.Value = (float64)( ((unsigned int)Buf[342] << 24) + ((unsigned int)Buf[343] << 16) 
 	+ ((unsigned int)Buf[344] << 8) +  (unsigned int)Buf[345]);
Protect13.ChangingValue =  Protect13.Value;
SetProt(13, Protect13.Value);

Protect14.Value = (float64)( ((unsigned int)Buf[346] << 24) + ((unsigned int)Buf[347] << 16) 
 	+ ((unsigned int)Buf[348] << 8) +  (unsigned int)Buf[349]);
Protect14.ChangingValue =  Protect14.Value;
SetProt(14, Protect14.Value);

Protect15.Value = (float64)( ((unsigned int)Buf[350] << 24) + ((unsigned int)Buf[351] << 16) 
 	+ ((unsigned int)Buf[352] << 8) +  (unsigned int)Buf[353]);
Protect15.ChangingValue =  Protect15.Value;
SetProt(15, Protect15.Value);

Protect16.Value = (float64)( ((unsigned int)Buf[354] << 24) + ((unsigned int)Buf[355] << 16) 
 	+ ((unsigned int)Buf[356] << 8) +  (unsigned int)Buf[357]);
Protect16.ChangingValue =  Protect16.Value;
SetProt(16, Protect16.Value);

Protect17.Value = (float64)( ((unsigned int)Buf[358] << 24) + ((unsigned int)Buf[359] << 16) 
 	+ ((unsigned int)Buf[360] << 8) +  (unsigned int)Buf[361]);
Protect17.ChangingValue =  Protect17.Value;
SetProt(17, Protect17.Value);

#endif

#endif

#ifdef HAVE_GATEWAY

 Network.Value = (float64)( ((unsigned int)Buf[362] << 24) + ((unsigned int)Buf[363] << 16) 
 	+ ((unsigned int)Buf[364] << 8) +  (unsigned int)Buf[365]);
 Network.ChangingValue =  Network.Value;

		Network0.Value = (unsigned)Network.Value & 0xff;
		Network0.ChangingValue = Network0.Value;

		Network1.Value = (unsigned char)((unsigned)Network.Value >> 8);
		Network1.ChangingValue = Network1.Value;
        
		Network2.Value = (unsigned char)((unsigned)Network.Value >> 16);
		Network2.ChangingValue = Network2.Value;

		Network3.Value = (unsigned char)((unsigned)Network.Value >> 24);
		Network3.ChangingValue = Network3.Value;



 NetMask.Value = (float64)( ((unsigned int)Buf[366] << 24) + ((unsigned int)Buf[367] << 16) 
 	+ ((unsigned int)Buf[368] << 8) +  (unsigned int)Buf[369]);


 if(!CheckNetMask((unsigned long)NetMask.Value))
//if(0)
 {
     NetMask.Value = DEFAULT_MASK; //140904
 }
 NetMask.ChangingValue =  NetMask.Value;


		NetMask0.Value = (unsigned)NetMask.Value & 0xff;
		NetMask0.ChangingValue = NetMask0.Value;

		NetMask1.Value = (unsigned char)((unsigned)NetMask.Value >> 8);
		NetMask1.ChangingValue = NetMask1.Value;

		NetMask2.Value = (unsigned char)((unsigned)NetMask.Value >> 16);
		NetMask2.ChangingValue = NetMask2.Value;

		NetMask3.Value = (unsigned char)((unsigned)NetMask.Value >> 24);
		NetMask3.ChangingValue = NetMask3.Value;



#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU3
//_________________________________________________________________________
SymbolRate2.Value = (float64)( ((unsigned int)Buf[370] << 24) + ((unsigned int)Buf[371] << 16) 
 	+ ((unsigned int)Buf[372] << 8) +  (unsigned int)Buf[373]);
 SymbolRate2.ChangingValue =  SymbolRate2.Value;
FreqPCh2.Value = (float64)( ((unsigned int)Buf[374] << 24) + ((unsigned int)Buf[375] << 16) 
 	+ ((unsigned int)Buf[376] << 8) +  (unsigned int)Buf[377]);
 FreqPCh2.ChangingValue =  FreqPCh2.Value;
ModulSK2.Value = (float64)( ((unsigned int)Buf[378] << 24) + ((unsigned int)Buf[379] << 16) 
 	+ ((unsigned int)Buf[380] << 8) +  (unsigned int)Buf[381]);
 ModulSK2.ChangingValue =  ModulSK2.Value;
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
//_________________________________________________________________________
SymbolRate2.Value = (float64)( ((unsigned int)Buf[370] << 24) + ((unsigned int)Buf[371] << 16) 
 	+ ((unsigned int)Buf[372] << 8) +  (unsigned int)Buf[373]);
 SymbolRate2.ChangingValue =  SymbolRate2.Value;
FreqPCh2.Value = (float64)( ((unsigned int)Buf[374] << 24) + ((unsigned int)Buf[375] << 16) 
 	+ ((unsigned int)Buf[376] << 8) +  (unsigned int)Buf[377]);
 FreqPCh2.ChangingValue =  FreqPCh2.Value;
ModulSK2.Value = (float64)( ((unsigned int)Buf[378] << 24) + ((unsigned int)Buf[379] << 16) 
 	+ ((unsigned int)Buf[380] << 8) +  (unsigned int)Buf[381]);
 ModulSK2.ChangingValue =  ModulSK2.Value;
#endif



#ifdef PROG_COMMUTATOR1
  numa[0] =  Buf[382]; numa[1] =  Buf[383];numa[2] =  Buf[384];
  numb[0] =  Buf[385]; numb[1] =  Buf[386];numb[2] =  Buf[387];
  numc[0] =  Buf[388]; numc[1] =  Buf[389];numc[2] =  Buf[390];

#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
//_________________________________________________________________________
SymbolRate3.Value = (float64)( ((unsigned int)Buf[391] << 24) + ((unsigned int)Buf[392] << 16) 
 	+ ((unsigned int)Buf[393] << 8) +  (unsigned int)Buf[394]);
 SymbolRate3.ChangingValue =  SymbolRate3.Value;
FreqPCh3.Value = (float64)( ((unsigned int)Buf[395] << 24) + ((unsigned int)Buf[396] << 16) 
 	+ ((unsigned int)Buf[397] << 8) +  (unsigned int)Buf[398]);
 FreqPCh3.ChangingValue =  FreqPCh3.Value;
ModulSK3.Value = (float64)( ((unsigned int)Buf[399] << 24) + ((unsigned int)Buf[400] << 16) 
 	+ ((unsigned int)Buf[401] << 8) +  (unsigned int)Buf[402]);
 ModulSK3.ChangingValue =  ModulSK3.Value;

SymbolRate4.Value = (float64)( ((unsigned int)Buf[403] << 24) + ((unsigned int)Buf[404] << 16) 
 	+ ((unsigned int)Buf[405] << 8) +  (unsigned int)Buf[406]);
 SymbolRate4.ChangingValue =  SymbolRate4.Value;
FreqPCh4.Value = (float64)( ((unsigned int)Buf[407] << 24) + ((unsigned int)Buf[408] << 16) 
 	+ ((unsigned int)Buf[409] << 8) +  (unsigned int)Buf[410]);
 FreqPCh4.ChangingValue =  FreqPCh4.Value;
ModulSK4.Value = (float64)( ((unsigned int)Buf[411] << 24) + ((unsigned int)Buf[412] << 16) 
 	+ ((unsigned int)Buf[413] << 8) +  (unsigned int)Buf[414]);
 ModulSK4.ChangingValue =  ModulSK4.Value;

test0 = Buf[415];  test1 = Buf[416]; test2 = Buf[417]; test3 = Buf[418];

decoder0 = Buf[419];  decoder1 = Buf[420]; decoder2 = Buf[421]; decoder3 = Buf[422];

#endif


#ifdef PROG_PU_MSAT

SatSet0.Value = (float64)( ((unsigned int)Buf[423] << 24) + ((unsigned int)Buf[424] << 16) 
 	+ ((unsigned int)Buf[425] << 8) +  (unsigned int)Buf[426]);
 SatSet0.ChangingValue =  SatSet0.Value;

SatSet1.Value = (float64)( ((unsigned int)Buf[427] << 24) + ((unsigned int)Buf[428] << 16) 
 	+ ((unsigned int)Buf[429] << 8) +  (unsigned int)Buf[430])/(float64)1000;
 SatSet1.ChangingValue =  SatSet1.Value;

SatSet2.Value = (float64)( ((unsigned int)Buf[431] << 24) + ((unsigned int)Buf[432] << 16) 
 	+ ((unsigned int)Buf[433] << 8) +  (unsigned int)Buf[434]);

SatSet2.Value /= (float64)10;
 SatSet2.ChangingValue =  SatSet2.Value;

SatSet3.Value = (float64)( ((signed int)Buf[435] << 24) + ((signed int)Buf[436] << 16) 
 	+ ((signed int)Buf[437] << 8) +  (signed int)Buf[438]);
 SatSet3.ChangingValue =  SatSet3.Value;

SatSet4.Value = (float64)( ((unsigned int)Buf[439] << 24) + ((unsigned int)Buf[440] << 16) 
 	+ ((unsigned int)Buf[441] << 8) +  (unsigned int)Buf[442]);
 SatSet4.ChangingValue =  SatSet4.Value;

SatSet5.Value = (float64)( ((unsigned int)Buf[443] << 24) + ((unsigned int)Buf[444] << 16) 
 	+ ((unsigned int)Buf[445] << 8) +  (unsigned int)Buf[446]);
 SatSet5.ChangingValue =  SatSet5.Value;

SatSet6.Value = (float64)( ((unsigned int)Buf[447] << 24) + ((unsigned int)Buf[448] << 16) 
 	+ ((unsigned int)Buf[449] << 8) +  (unsigned int)Buf[450]);
 SatSet6.ChangingValue =  SatSet6.Value;

SatSet7.Value = (float64)( ((unsigned int)Buf[451] << 24) + ((unsigned int)Buf[452] << 16) 
 	+ ((unsigned int)Buf[453] << 8) +  (unsigned int)Buf[454]);
 SatSet7.ChangingValue =  SatSet7.Value;

SatTestMode.Value =  (unsigned char)Buf[455];
SatTestMode.ChangingValue =  (unsigned char)Buf[455];

SatPC.Value =  (unsigned char)Buf[456];
SatPC.ChangingValue =  (unsigned char)Buf[456]; 

SatTiming.Value =  (unsigned char)Buf[457];
SatTiming.ChangingValue =  (unsigned char)Buf[457];

SatSet8.Value = (float64)( ((unsigned int)Buf[458] << 24) + ((unsigned int)Buf[459] << 16) 
 	+ ((unsigned int)Buf[460] << 8) +  (unsigned int)Buf[461]);
 SatSet8.ChangingValue =  SatSet8.Value;

SatSound.Value =  (unsigned char)Buf[462];
SatSound.ChangingValue =  (unsigned char)Buf[462];
 

#endif

#ifdef PROG_MD310_SATI
SatSound.Value =  (unsigned char)Buf[462];
SatSound.ChangingValue =  (unsigned char)Buf[462];
#endif

#ifdef PROG_BMDN
//_________________________________________________________________________
ModEth.Value = (float64)( ((unsigned long)Buf[463] << 24) + ((unsigned long)Buf[464] << 16) 
 	+ ((unsigned long)Buf[465] << 8) +  (unsigned long)Buf[466]);
ModEth.ChangingValue =  ModEth.Value;
#endif

#ifdef USE_HTTP
//_________________________________________________________________________
WebPassword.Value = (float64)( ((unsigned long)Buf[467] << 24) + ((unsigned long)Buf[468] << 16) 
 	+ ((unsigned long)Buf[469] << 8) +  (unsigned long)Buf[470]);
WebPassword.ChangingValue =  WebPassword.Value;

#ifdef PROG_PU_MSAT

  dev1.pum100s1.WebPasswordr0 = 	(unsigned)WebPassword.Value;
 	 dev1.pum100s1.WebPasswordr1 = 	(unsigned)WebPassword.Value>>8;
 	 dev1.pum100s1.WebPasswordr2 = 	(unsigned)WebPassword.Value>>16;
 	 dev1.pum100s1.WebPasswordr3 = 	(unsigned)WebPassword.Value>>24;

#endif
#endif

#ifdef PROG_PU_MSAT
SatDF.Value =  (unsigned char)Buf[471];
SatDF.ChangingValue =  (unsigned char)Buf[471];

SatTF.Value =  (unsigned char)Buf[472];
SatTF.ChangingValue =  (unsigned char)Buf[472];

SatRate.Value = (float64)( ((unsigned long)Buf[473] << 24) + ((unsigned long)Buf[474] << 16) 
 	+ ((unsigned long)Buf[475] << 8) +  (unsigned long)Buf[476]);
SatRate.ChangingValue =  SatRate.Value;

SatTimer.Value = (float64)( ((unsigned long)Buf[477] << 24) + ((unsigned long)Buf[478] << 16) 
 	+ ((unsigned long)Buf[479] << 8) +  (unsigned long)Buf[480]);
SatTimer.ChangingValue =  SatTimer.Value;


#endif

#ifdef PROG_PU_M_V_A

 if(flag_crc)
 {
AttData.Value = (float64)( ((unsigned long)Buf[481] << 24) + ((unsigned long)Buf[482] << 16) 
 	+ ((unsigned long)Buf[483] << 8) +  (unsigned long)Buf[484]);
AttData.ChangingValue =  AttData.Value;
 }
 else
 {
 AttData.Value = 0;
 AttData.ChangingValue =  AttData.Value;
 }

#endif


#ifdef PROG_PU_MSAT
#ifdef RECEIVE_MOD_LOCK

SatExtLock.Value =  (unsigned char)Buf[489];
SatExtLock.ChangingValue =  (unsigned char)Buf[489];
// printfpd("\n\rLr:%d", (unsigned)SatExtLock.Value);


SatExtLockP.Value =  (unsigned char)Buf[490];
SatExtLockP.ChangingValue =  (unsigned char)Buf[490];
//printfpd("\n\rLr1:%d", (unsigned)SatExtLockP.Value);

#endif
SatLowP.Value =  (unsigned char)Buf[491];
SatLowP.ChangingValue =  (unsigned char)Buf[491];

SatALev.Value =  (unsigned char)Buf[492];
SatALev.ChangingValue =  (unsigned char)Buf[492];

//printfpd("\n\r Satalev: %d", SatALev.Value);


SatADemo.Value =  (unsigned char)Buf[493];
SatADemo.ChangingValue =  (unsigned char)Buf[493];

SatACode.Value = (float64)( ((unsigned long)Buf[494] << 24) + ((unsigned long)Buf[495] << 16) 
 	+ ((unsigned long)Buf[496] << 8) +  (unsigned long)Buf[497]);

SatACode.Value = 0; //not need keep
SatACode.ChangingValue =  0; //to do not view on display

//printfpd("\n\r Satacode: %d", SatACode.Value);

#endif

#ifdef 	PROG_PU_M_MUX
  modforss = Buf[498];
#endif


#ifdef PROG_PU_MSAT  

 FlagOldSatAlev = Buf[499];// = 0;
 OldSatAlev = Buf[500]; //0;
#endif



#ifdef   PROG_MD310_SATI

 LoadVariants.Value =  Buf[501];
 LoadVariants.ChangingValue	= Buf[501];

 SaveVariants.Value =  Buf[502];
 SaveVariants.ChangingValue	= Buf[502];

 MRfOut.Value =  Buf[503];
 MRfOut.ChangingValue	= Buf[503];

MOutLev.Value =  (float64)((Buf[504] << 24) + (Buf[505] << 16) 
 	+ (Buf[506] << 8) +  Buf[507])/(float64)10;

MOutLev.ChangingValue =  MOutLev.Value;


MTFreq.Value = (float64)( ((unsigned long)Buf[508] << 24) + ((unsigned long)Buf[509] << 16) 
 	+ ((unsigned long)Buf[510] << 8) +  (unsigned long)Buf[511]) / (float64)10000;
MTFreq.ChangingValue =  MTFreq.Value;


MRFreq.Value = (float64)( ((unsigned long)Buf[512] << 24) + ((unsigned long)Buf[513] << 16) 
 	+ ((unsigned long)Buf[514] << 8) +  (unsigned long)Buf[515]) / (float64)10000;
MRFreq.ChangingValue =  MRFreq.Value;

  //	 printfpdv("\n\r read freq: %5.4f",MRFreq.Value);


 MDemod.Value =  Buf[516];
 MDemod.ChangingValue	= Buf[516];


 MEthMode.Value =  Buf[517];
 MEthMode.ChangingValue	= Buf[517];

 //printfpd("\n\r read em %d:", (unsigned)MEthMode.Value);


 MEthPause.Value =  Buf[518];
 MEthPause.ChangingValue	= Buf[518];

 MEthctl.Value =  Buf[519];
 MEthctl.ChangingValue	= Buf[519];


MEthMaxF.Value = (float64)( ((unsigned long)Buf[520] << 24) + ((unsigned long)Buf[521] << 16) 
 	+ ((unsigned long)Buf[522] << 8) +  (unsigned long)Buf[523]);
MEthMaxF.ChangingValue =  MEthMaxF.Value;

MEthVlanP.Value = (float64)( ((unsigned long)Buf[524] << 24) + ((unsigned long)Buf[525] << 16) 
 	+ ((unsigned long)Buf[526] << 8) +  (unsigned long)Buf[527]);
MEthVlanP.ChangingValue =  MEthVlanP.Value;

MTEbN0.Value = (float64)( ((unsigned long)Buf[528] << 24) + ((unsigned long)Buf[529] << 16) 
 	+ ((unsigned long)Buf[530] << 8) +  (unsigned long)Buf[531]);
MTEbN0.ChangingValue =  MTEbN0.Value;

MTBER.Value = (float64)( ((unsigned long)Buf[532] << 24) + ((unsigned long)Buf[533] << 16) 
 	+ ((unsigned long)Buf[534] << 8) +  (unsigned long)Buf[535]);
MTBER.ChangingValue =  MTBER.Value;


 MIfLoop.Value =  Buf[536];
 MIfLoop.ChangingValue	= Buf[536];

 MUnModul.Value =  Buf[537];
 MUnModul.ChangingValue	= Buf[537];

 MACMM.Value =  Buf[538];
 MACMM.ChangingValue	= Buf[538];

MTBERE.Value = (float64)( ((unsigned long)Buf[539] << 24) + ((unsigned long)Buf[540] << 16) 
 	+ ((unsigned long)Buf[541] << 8) +  (unsigned long)Buf[542]);
MTBERE.ChangingValue =  MTBERE.Value;

MTMode.Value = Buf[543];
MTMode.ChangingValue  = MTMode.Value;

MRMode.Value = Buf[544];
MRMode.ChangingValue  = MRMode.Value;

MRCntl.Value = Buf[545];
MRCntl.ChangingValue  = MRCntl.Value;

MOutLevO.Value =  ((Buf[546] << 24) + (Buf[547] << 16) 
 	+ (Buf[548] << 8) +  Buf[549] )/ (float64)1000;
MOutLevO.ChangingValue =  MOutLevO.Value;  

//printfpdv("\n\rrd MOutLevo: % 5.3f",MOutLevO.Value);


MOutLevOS.Value =   Buf[550];
MOutLevOS.ChangingValue =  MOutLevOS.Value;

MKOUT.Value =  ((Buf[551] << 24) + (Buf[552] << 16) 
 	+ (Buf[553] << 8) +  Buf[554])/(float64)10;
MKOUT.ChangingValue =  MKOUT.Value;

MKOUT1.Value =  (Buf[555] << 24) + (Buf[556] << 16) 
 	+ (Buf[557] << 8) +  Buf[558];
MKOUT1.ChangingValue =  MKOUT1.Value;

MKIN1.Value =  (Buf[559] << 24) + (Buf[560] << 16) 
 	+ (Buf[561] << 8) +  Buf[562];
MKIN1.ChangingValue =  MKIN1.Value;

MKIN2.Value =  (Buf[563] << 24) + (Buf[564] << 16) 
 	+ (Buf[565] << 8) +  Buf[566];
MKIN2.ChangingValue =  MKIN2.Value;

MKIN3.Value =  (Buf[567] << 24) + (Buf[568] << 16) 
 	+ (Buf[569] << 8) +  Buf[570];
MKIN3.ChangingValue =  MKIN3.Value;

unsigned long cnt = 571;
unsigned long ims = 0;

#ifdef RACM

 RACMOnOff.Value =  Buf[cnt++];
 RACMOnOff.ChangingValue =  RACMOnOff.Value;

ratimelock.Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
ratimelock.ChangingValue =  ratimelock.Value;

//  if(start_main_loop) printfpd("\n\r ratimelock : %d", ratimelock.Value);	


ratimemode.Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
ratimemode.ChangingValue =  ratimemode.Value;

//if(start_main_loop) printfpd("\n\r ratimemode : %d", ratimemode.Value);	

ratimemse.Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
ratimemse.ChangingValue =  ratimemse.Value;

//if(start_main_loop) printfpd("\n\r ratimemse : %d", ratimemse.Value);	


ratimestep.Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
ratimestep.ChangingValue =  ratimestep.Value;

//if(start_main_loop) printfpd("\n\r ratimestep : %d", ratimestep.Value);	


//if(start_main_loop)    printfpd("\n\r  uebn read start cnt %d", cnt);	//


uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//1
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//2
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//3
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//4
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//5
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//6
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//7
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//8
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//9
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//10
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//11
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//12
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//13
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//14
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;
ims++;//15
uebn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];

uebn[ims].Value /= 10.0;
uebn[ims].ChangingValue =  uebn[ims].Value;


//printfpd("\n\r ims = %d", ims);

//if(start_main_loop)    printfpd("\n\r  uebn read finish cnt %d", cnt);	//656


ims = 0;

//MDataC debn[16];
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//1
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//2
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//3
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//4
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//5
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//6
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//7
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//8
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//9
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//10
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//11
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//12
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//13
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//14
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;
ims++;//15
debn[ims].Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
debn[ims].Value /= 10.0;
debn[ims].ChangingValue =  debn[ims].Value;

// if(start_main_loop) printfpd("\n\r read debn finish cnt %d", cnt);	//768

 

ims = 0;//1

 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //1
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //2
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //3
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //4
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //5
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //6
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //7
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //8
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //9
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //10
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //11
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //12
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //13
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //14
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;
 ims++;  //15
 enamode[ims].Value =  Buf[cnt++];
 enamode[ims].ChangingValue = enamode[ims].Value;


 ims = 0;  //1

 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //1
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //2
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //3
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //4
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //5
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //6
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //7
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //8
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //9
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //10
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //11
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //12
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //13
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //14
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;
 ims++;  //15
 numode[ims].Value =  Buf[cnt++];
 numode[ims].ChangingValue = numode[ims].Value;

 ims = 0;  //1
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //1
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //2
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //3
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //4
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //5
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //6
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //7
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //8
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //9
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //10
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //11
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //12
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //13
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //14
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
 ims++;  //15
 ndmode[ims].Value =  Buf[cnt++];
 ndmode[ims].ChangingValue = ndmode[ims].Value;
   

 ims = 0;  //1
	  /*
MDataV enamode[16];
MDataV numode[16];
MDataV ndmode[16];
   */

if(!flag_crc)
{
 ACM_DEFAULT_init();
}

 RACMOnOffT.Value =  Buf[cnt++];
 RACMOnOffT.ChangingValue =  RACMOnOffT.Value;

RACMOffset.Value =  (Buf[cnt++] << 24) + (Buf[cnt++] << 16) 
 	+ (Buf[cnt++] << 8) +  Buf[cnt++];
RACMOffset.Value /= 10.0;
RACMOffset.ChangingValue =  RACMOffset.Value;





#endif
//cnt= 764
//cnt = 765
//cnt = 769


// if(start_main_loop) printfpd("\n\r read cnt %d", cnt);	//

//______________________________________________________________


#endif


#ifdef PROG_ODU1
 ten_mhz =  Buf[769];
#endif

#ifdef USE_SOCKETSD

IPAddressUDP.Value =  (Buf[770] << 24) + (Buf[771] << 16) + (Buf[772] << 8) +  Buf[773];
IPAddressUDP.ChangingValue =  IPAddressUDP.Value;


#endif



return flag_crc;
}

//___________________________________

extern "C" unsigned char ReadDevId_test(unsigned char flag_lock)
{

   printfp("\n\r ReadDevId_test");
//return;	  //t


 char Buf[DEV_ID_SIZE];
 unsigned int DeviceAddress = ID_ADDRESS;
 read_dataflash (DeviceAddress, DEV_ID_SIZE, (char *)&Buf[0]);
// read_dataflash (DeviceAddress, DEV_ID_SIZE+100, (char *)&Buf[0]);
 read_flag = 1;



//__________________________________________________crc
unsigned char flag_crc = 0;
unsigned char id_crc = 0;
unsigned long check_ver = 0;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

check_ver = ( ((unsigned long)Buf[485] << 24) + ((unsigned long)Buf[486] << 16) 
 	+ ((unsigned long)Buf[487] << 8) +  (unsigned long)Buf[488]);



//test  if(id_crc == Buf[DEV_ID_SIZE - 1])	

 if(0) //test
 {
    flag_crc = 1;
  //	printfp("\n\r1");
 }
 else
 {
   read_dataflash (ID_ADDRESS3, DEV_ID_SIZE, (char *)&Buf[0]);	   //new address


 id_crc = 0;

for( icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

check_ver = ( ((unsigned long)Buf[485] << 24) + ((unsigned long)Buf[486] << 16) 
 	+ ((unsigned long)Buf[487] << 8) +  (unsigned long)Buf[488]);

 printfpd(" id_crc: %02X", id_crc);
 printfpd(" Buf[DEV_ID_SIZE - 1]: %02X",Buf[DEV_ID_SIZE - 1]);


 if(id_crc == Buf[DEV_ID_SIZE - 1])	
 {
    flag_crc = 1;
  	printfp("\n\r flag_crc = 1");
 }
 else  //need use first address for id to property change old wersions of prog without this feature
 {
   	printfp("\n\r flag_crc != 1");

  read_dataflash (ID_ADDRESS, DEV_ID_SIZE, (char *)&Buf[0]); //150120


 }

 }

//__________________________________________________crc

 DevId.Value =  (float64) (((unsigned int)Buf[0] << 8) + (unsigned int)Buf[1]);
 DevId.ChangingValue = DevId.Value;
 DevYear.Value = (float64)( ((unsigned int)Buf[2] << 8) + (unsigned int)Buf[3]);
 DevYear.ChangingValue =  DevYear.Value;
 DevVer1.Value = (float64)( ((unsigned int)Buf[4] << 8) + (unsigned int)Buf[5]);
 DevVer1.ChangingValue =  DevVer1.Value;
 DevVer2.Value = (float64)( ((unsigned int)Buf[6] << 8) + (unsigned int)Buf[7]);
 DevVer2.ChangingValue =  DevVer2.Value;
 POK.Value = (float64)( ((unsigned int)Buf[8] << 8) + (unsigned int)Buf[9]);
 POK.ChangingValue =  POK.Value;
 MAC0.Value = (float64)( ((unsigned int)Buf[10] << 16) + ((unsigned int)Buf[11] << 8) + (unsigned int)Buf[12]);
 MAC0.ChangingValue =  MAC0.Value;
 MAC1.Value = (float64)( ((unsigned int)Buf[13] << 16) + ((unsigned int)Buf[14] << 8) + (unsigned int)Buf[15]);
 MAC1.ChangingValue =  MAC1.Value;
 IPAddress.Value = (float64)( ((unsigned int)Buf[16] << 24) + ((unsigned int)Buf[17] << 16) 
 	+ ((unsigned int)Buf[18] << 8) +  (unsigned int)Buf[19]);
 IPAddress.ChangingValue =  IPAddress.Value;
	 /*
  if((!flag_crc) && (check_ver == SOFT_VER))
  {
  	
	DevId.Value = DEFAULT_ID; //0x1234;
	DevId.ChangingValue = DevId.Value;
	DevVer1.Value = DEFAULT_VER; //0;
    DevVer1.ChangingValue =  DevVer1.Value;
	DevVer2.Value = DEFAULT_VER; //0;
 	DevVer2.ChangingValue =  DevVer2.Value;
	POK.Value = DEFAULT_POK;//0;	 //set not 0x1000
 	POK.ChangingValue =  POK.Value;
	MAC0.Value = DEFAULT_MAC0; //0x001111;
 	MAC0.ChangingValue =  MAC0.Value;
  	MAC1.Value = DEFAULT_MAC1; //0x001234;
 	MAC1.ChangingValue =  MAC0.Value;
	IPAddress.Value = DEFAULT_IP; //0x9B9B9b0f;
  	IPAddress.ChangingValue =  IPAddress.Value;
  }
	  */

if(!flag_crc) 
  {
  	
#ifdef HAVE_GATEWAY
	NetMask.Value = DEFAULT_MASK; 
	NetMask.ChangingValue =  NetMask.Value;
#endif

  }



 MakeIPAddresses();
 TestMode.Value = (float64)( ((unsigned int)Buf[20] << 24) + ((unsigned int)Buf[21] << 16) 
 	+ ((unsigned int)Buf[22] << 8) +  (unsigned int)Buf[23]);
 TestMode.ChangingValue =  TestMode.Value;

 UARTAddress.Value = (float64)( ((unsigned int)Buf[24] << 24) + ((unsigned int)Buf[25] << 16) 
 	+ ((unsigned int)Buf[26] << 8) +  (unsigned int)Buf[27]);
 UARTAddress.ChangingValue =  UARTAddress.Value;


#ifdef PROG_TUTS
 TSOut.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 TSOut.ChangingValue =  TSOut.Value;

#endif //PROG_TUTS

#ifdef PROG_BMD35
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_BMD35

#ifdef PROG_PROV
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_PROV


#ifdef PROG_MPC35
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //PROG_MPC35

#ifdef KTVM_PROT2
 RemoteMode.Value = (float64)( ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
 RemoteMode.ChangingValue =  RemoteMode.Value;

#endif //KTVM_PROT2

#ifdef  LOCK_ENABLED  //091111
 /*101117  do not enable keep
 LockMode.Value = (float64)( ((unsigned int)Buf[32] << 24) + ((unsigned int)Buf[33] << 16) 
 	+ ((unsigned int)Buf[34] << 8) +  (unsigned int)Buf[35]);
 LockMode.ChangingValue =  LockMode.Value;
 */

//091111#ifdef  LOCK_ENABLED
//091111	 	 if(LockMode.Value == 1)  SetBufferState((unsigned long)LOCK_MODE1);  //not write unlock
//091111	 	 if(LockMode.Value == 2)   SetBufferState((unsigned long)LOCK_MODE2);  //only read
/* 101117  do not enable keep
		 if(LockMode.Value == 3)   SetBufferState((unsigned long)LOCK_MODE3);  //full +
		 else {LockMode.Value = 0; LockMode.ChangingValue =  LockMode.Value; SetBufferState((unsigned long)LOCK_MODE2);}	 //091111 keep after reboot only key5
*/

if(!flag_lock)
{
  LockMode.Value = 0; LockMode.ChangingValue =  LockMode.Value; SetBufferState((unsigned long)LOCK_MODE2);
}

#endif // LOCK_ENABLED
// OID_ptr = (uchar_ptr)&OID[0];
// sprintf((char *)OID_ptr, "%08X",(uint_32)DevId.Value);

#ifdef TRAP_ENABLED

TrapTimer.Value = (float64)( ((unsigned int)Buf[36] << 24) + ((unsigned int)Buf[37] << 16) 
 	+ ((unsigned int)Buf[38] << 8) +  (unsigned int)Buf[39]);
 TrapTimer.ChangingValue =  TrapTimer.Value;

TrapIp.Value = (float64)( ((unsigned int)Buf[40] << 24) + ((unsigned int)Buf[41] << 16) 
 	+ ((unsigned int)Buf[42] << 8) +  (unsigned int)Buf[43]);
 TrapIp.ChangingValue =  TrapIp.Value;


#endif //TRAP_ENABLED 

#ifdef 	PROG_PRM_PCH_N_2

RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
#endif
  /* it is maked in prm_pch_L
#ifdef 	PROG_PRM_PCH_SPI

RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
#endif
 */



#ifdef 	PROG_PRM_PCH_L
RestoreFreq(1, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
 	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(2, ((unsigned int)Buf[52] << 24) + ((unsigned int)Buf[53] << 16) 
 	+ ((unsigned int)Buf[54] << 8) +  (unsigned int)Buf[55]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(3, ((unsigned int)Buf[60] << 24) + ((unsigned int)Buf[61] << 16) 
 	+ ((unsigned int)Buf[62] << 8) +  (unsigned int)Buf[63]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);
RestoreAttRPU(1, ((unsigned int)Buf[68] << 24) + ((unsigned int)Buf[69] << 16) 
	+ ((unsigned int)Buf[70] << 8) +  (unsigned int)Buf[71]);
RestoreAttRPU(2, ((unsigned int)Buf[72] << 24) + ((unsigned int)Buf[73] << 16) 
	+ ((unsigned int)Buf[74] << 8) +  (unsigned int)Buf[75]);
RestoreAttRPU(3, ((unsigned int)Buf[76] << 24) + ((unsigned int)Buf[77] << 16) 
	+ ((unsigned int)Buf[78] << 8) +  (unsigned int)Buf[79]);
#endif // PROG_PRM_PCH_L

#ifdef 	PROG_PRM_PCH_L
RestoreFreq(4, ((unsigned int)Buf[80] << 24) + ((unsigned int)Buf[81] << 16) 
 	+ ((unsigned int)Buf[82] << 8) +  (unsigned int)Buf[83]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(5, ((unsigned int)Buf[84] << 24) + ((unsigned int)Buf[85] << 16) 
 	+ ((unsigned int)Buf[86] << 8) +  (unsigned int)Buf[87]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(6, ((unsigned int)Buf[88] << 24) + ((unsigned int)Buf[89] << 16) 
 	+ ((unsigned int)Buf[90] << 8) +  (unsigned int)Buf[91]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);
RestoreAttRPU(4, ((unsigned int)Buf[92] << 24) + ((unsigned int)Buf[93] << 16) 
	+ ((unsigned int)Buf[94] << 8) +  (unsigned int)Buf[95]);
RestoreAttRPU(5, ((unsigned int)Buf[96] << 24) + ((unsigned int)Buf[97] << 16) 
	+ ((unsigned int)Buf[98] << 8) +  (unsigned int)Buf[99]);
RestoreAttRPU(6, ((unsigned int)Buf[100] << 24) + ((unsigned int)Buf[101] << 16) 
	+ ((unsigned int)Buf[102] << 8) +  (unsigned int)Buf[103]);
#endif // PROG_PRM_PCH_L

#ifdef PROG_BMDN
//_________________________________________________________________________
ConfigFile.Value = (float64)( ((unsigned int)Buf[104] << 24) + ((unsigned int)Buf[105] << 16) 
 	+ ((unsigned int)Buf[106] << 8) +  (unsigned int)Buf[107]);
 ConfigFile.ChangingValue =  ConfigFile.Value;
//__________________________________________________________________________
//#ifndef PROG_BMDN6MI
//_________________________________________________________________________
ConfigFile1.Value = (float64)( ((unsigned int)Buf[108] << 24) + ((unsigned int)Buf[109] << 16) 
 	+ ((unsigned int)Buf[110] << 8) +  (unsigned int)Buf[111]);
 ConfigFile1.ChangingValue =  ConfigFile1.Value;
//_________________________________________________________________________
#ifndef PROG_BMDN6MI


ConfigFile2.Value = (float64)( ((unsigned int)Buf[112] << 24) + ((unsigned int)Buf[113] << 16) 
 	+ ((unsigned int)Buf[114] << 8) +  (unsigned int)Buf[115]);
 ConfigFile2.ChangingValue =  ConfigFile2.Value;
//_________________________________________________________________________
ConfigFile3.Value = (float64)( ((unsigned int)Buf[116] << 24) + ((unsigned int)Buf[117] << 16) 
 	+ ((unsigned int)Buf[118] << 8) +  (unsigned int)Buf[119]);
 ConfigFile3.ChangingValue =  ConfigFile3.Value;
//_________________________________________________________________________
ConfigFile4.Value = (float64)( ((unsigned int)Buf[120] << 24) + ((unsigned int)Buf[121] << 16) 
 	+ ((unsigned int)Buf[122] << 8) +  (unsigned int)Buf[123]);
 ConfigFile4.ChangingValue =  ConfigFile4.Value;
//_________________________________________________________________________
ConfigFile5.Value = (float64)( ((unsigned int)Buf[124] << 24) + ((unsigned int)Buf[125] << 16) 
 	+ ((unsigned int)Buf[126] << 8) +  (unsigned int)Buf[127]);
 ConfigFile5.ChangingValue =  ConfigFile5.Value;
//_________________________________________________________________________
ConfigFile6.Value = (float64)( ((unsigned int)Buf[128] << 24) + ((unsigned int)Buf[129] << 16) 
 	+ ((unsigned int)Buf[130] << 8) +  (unsigned int)Buf[131]);
 ConfigFile6.ChangingValue =  ConfigFile6.Value;
//_________________________________________________________________________
ConfigFile7.Value = (float64)( ((unsigned int)Buf[132] << 24) + ((unsigned int)Buf[133] << 16) 
 	+ ((unsigned int)Buf[134] << 8) +  (unsigned int)Buf[135]);
 ConfigFile7.ChangingValue =  ConfigFile7.Value;
//_________________________________________________________________________
ConfigFile8.Value = (float64)( ((unsigned int)Buf[136] << 24) + ((unsigned int)Buf[137] << 16) 
 	+ ((unsigned int)Buf[138] << 8) +  (unsigned int)Buf[139]);
 ConfigFile8.ChangingValue =  ConfigFile8.Value;
//_________________________________________________________________________
ConfigFile9.Value = (float64)( ((unsigned int)Buf[140] << 24) + ((unsigned int)Buf[141] << 16) 
 	+ ((unsigned int)Buf[142] << 8) +  (unsigned int)Buf[143]);
 ConfigFile9.ChangingValue =  ConfigFile9.Value;
//_________________________________________________________________________
ConfigFile10.Value = (float64)( ((unsigned int)Buf[144] << 24) + ((unsigned int)Buf[145] << 16) 
 	+ ((unsigned int)Buf[146] << 8) +  (unsigned int)Buf[147]);
 ConfigFile10.ChangingValue =  ConfigFile10.Value;
//_________________________________________________________________________
ConfigFile11.Value = (float64)( ((unsigned int)Buf[148] << 24) + ((unsigned int)Buf[149] << 16) 
 	+ ((unsigned int)Buf[150] << 8) +  (unsigned int)Buf[151]);
 ConfigFile11.ChangingValue =  ConfigFile11.Value;
//_________________________________________________________________________
ConfigFile12.Value = (float64)( ((unsigned int)Buf[152] << 24) + ((unsigned int)Buf[153] << 16) 
 	+ ((unsigned int)Buf[154] << 8) +  (unsigned int)Buf[155]);
 ConfigFile12.ChangingValue =  ConfigFile12.Value;
//_________________________________________________________________________
ConfigFile13.Value = (float64)( ((unsigned int)Buf[156] << 24) + ((unsigned int)Buf[157] << 16) 
 	+ ((unsigned int)Buf[158] << 8) +  (unsigned int)Buf[159]);
 ConfigFile13.ChangingValue =  ConfigFile13.Value;
//_________________________________________________________________________
ConfigFile14.Value = (float64)( ((unsigned int)Buf[160] << 24) + ((unsigned int)Buf[161] << 16) 
 	+ ((unsigned int)Buf[162] << 8) +  (unsigned int)Buf[163]);
 ConfigFile14.ChangingValue =  ConfigFile14.Value;
//_________________________________________________________________________
ConfigFile15.Value = (float64)( ((unsigned int)Buf[164] << 24) + ((unsigned int)Buf[165] << 16) 
 	+ ((unsigned int)Buf[166] << 8) +  (unsigned int)Buf[167]);
 ConfigFile15.ChangingValue =  ConfigFile15.Value;
#endif
//_________________________________________________________________________

if(flag_crc)
{
ModForSS.Value = (float64)( ((unsigned int)Buf[168] << 24) + ((unsigned int)Buf[169] << 16) 
 	+ ((unsigned int)Buf[170] << 8) +  (unsigned int)Buf[171]);
}
else
{
 ModForSS.Value = 1; //one trunk mode for bmdn6; do not operate power md310
}

 ModForSS.ChangingValue =  ModForSS.Value;

if(!((unsigned long)ModForSS.Value & 2l))
{
  ClearBufferState((unsigned long)OPERATE_POWER_ON);
}
 else
{
  SetBufferState((unsigned long)OPERATE_POWER_ON);
}


//___________________________________________________________________________
Priority0.Value = (float64)( ((unsigned int)Buf[172] << 24) + ((unsigned int)Buf[173] << 16) 
 	+ ((unsigned int)Buf[174] << 8) +  (unsigned int)Buf[175]);
Priority0.ChangingValue =  Priority0.Value;

#ifndef PROG_BMDN6MI
//___________________________________________________________________________
Priority1.Value = (float64)( ((unsigned int)Buf[176] << 24) + ((unsigned int)Buf[177] << 16) 
 	+ ((unsigned int)Buf[178] << 8) +  (unsigned int)Buf[179]);
Priority1.ChangingValue =  Priority1.Value;
//___________________________________________________________________________
Priority2.Value = (float64)( ((unsigned int)Buf[180] << 24) + ((unsigned int)Buf[181] << 16) 
 	+ ((unsigned int)Buf[182] << 8) +  (unsigned int)Buf[183]);
Priority2.ChangingValue =  Priority2.Value;
//___________________________________________________________________________
Priority3.Value = (float64)( ((unsigned int)Buf[184] << 24) + ((unsigned int)Buf[185] << 16) 
 	+ ((unsigned int)Buf[186] << 8) +  (unsigned int)Buf[187]);
Priority3.ChangingValue =  Priority3.Value;
//___________________________________________________________________________
Priority4.Value = (float64)( ((unsigned int)Buf[188] << 24) + ((unsigned int)Buf[189] << 16) 
 	+ ((unsigned int)Buf[190] << 8) +  (unsigned int)Buf[191]);
Priority4.ChangingValue =  Priority4.Value;
//___________________________________________________________________________
Priority5.Value = (float64)( ((unsigned int)Buf[192] << 24) + ((unsigned int)Buf[193] << 16) 
 	+ ((unsigned int)Buf[194] << 8) +  (unsigned int)Buf[195]);
Priority5.ChangingValue =  Priority5.Value;
//___________________________________________________________________________
Priority6.Value = (float64)( ((unsigned int)Buf[196] << 24) + ((unsigned int)Buf[197] << 16) 
 	+ ((unsigned int)Buf[198] << 8) +  (unsigned int)Buf[199]);
Priority6.ChangingValue =  Priority6.Value;
//___________________________________________________________________________
Priority7.Value = (float64)( ((unsigned int)Buf[200] << 24) + ((unsigned int)Buf[201] << 16) 
 	+ ((unsigned int)Buf[202] << 8) +  (unsigned int)Buf[203]);
Priority7.ChangingValue =  Priority7.Value;
//___________________________________________________________________________
Priority8.Value = (float64)( ((unsigned int)Buf[204] << 24) + ((unsigned int)Buf[205] << 16) 
 	+ ((unsigned int)Buf[206] << 8) +  (unsigned int)Buf[207]);
Priority8.ChangingValue =  Priority8.Value;
#endif


//___________________________________________________________________________
Threshold0.Value = (float64)( ((unsigned int)Buf[208] << 24) + ((unsigned int)Buf[209] << 16) 
 	+ ((unsigned int)Buf[210] << 8) +  (unsigned int)Buf[211]);
Threshold0.ChangingValue =  Threshold0.Value;

#ifndef PROG_BMDN6MI
//___________________________________________________________________________
Threshold1.Value = (float64)( ((unsigned int)Buf[212] << 24) + ((unsigned int)Buf[213] << 16) 
 	+ ((unsigned int)Buf[214] << 8) +  (unsigned int)Buf[215]);
Threshold1.ChangingValue =  Threshold1.Value;
//___________________________________________________________________________
Threshold2.Value = (float64)( ((unsigned int)Buf[216] << 24) + ((unsigned int)Buf[217] << 16) 
 	+ ((unsigned int)Buf[218] << 8) +  (unsigned int)Buf[219]);
Threshold2.ChangingValue =  Threshold2.Value;
//___________________________________________________________________________
Threshold3.Value = (float64)( ((unsigned int)Buf[220] << 24) + ((unsigned int)Buf[221] << 16) 
 	+ ((unsigned int)Buf[222] << 8) +  (unsigned int)Buf[223]);
Threshold3.ChangingValue =  Threshold3.Value;
//___________________________________________________________________________
Threshold4.Value = (float64)( ((unsigned int)Buf[224] << 24) + ((unsigned int)Buf[225] << 16) 
 	+ ((unsigned int)Buf[226] << 8) +  (unsigned int)Buf[227]);
Threshold4.ChangingValue =  Threshold4.Value;
//___________________________________________________________________________
Threshold5.Value = (float64)( ((unsigned int)Buf[228] << 24) + ((unsigned int)Buf[229] << 16) 
 	+ ((unsigned int)Buf[230] << 8) +  (unsigned int)Buf[231]);
Threshold5.ChangingValue =  Threshold5.Value;
//___________________________________________________________________________
Threshold6.Value = (float64)( ((unsigned int)Buf[232] << 24) + ((unsigned int)Buf[233] << 16) 
 	+ ((unsigned int)Buf[234] << 8) +  (unsigned int)Buf[235]);
Threshold6.ChangingValue =  Threshold6.Value;
//___________________________________________________________________________
Threshold7.Value = (float64)( ((unsigned int)Buf[236] << 24) + ((unsigned int)Buf[237] << 16) 
 	+ ((unsigned int)Buf[238] << 8) +  (unsigned int)Buf[239]);
Threshold7.ChangingValue =  Threshold7.Value;
//___________________________________________________________________________
Threshold8.Value = (float64)( ((unsigned int)Buf[240] << 24) + ((unsigned int)Buf[241] << 16) 
 	+ ((unsigned int)Buf[242] << 8) +  (unsigned int)Buf[243]);
Threshold8.ChangingValue =  Threshold8.Value;
#endif
#endif
//___________________________________________________________________________
#ifdef PROG_PU_M_V
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif

#ifdef PROG_PU_M_V_A
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif // PROG_PU_M_V_A


#ifdef PROG_UPS
//for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 udevconfig.byte[iid] = Buf[244 + iid];
}

#endif




#ifdef PROG_PRM_PCH_DEM
//_________________________________________________________________________
SymbolRate.Value = (float64)( ((unsigned int)Buf[278] << 24) + ((unsigned int)Buf[279] << 16) 
 	+ ((unsigned int)Buf[280] << 8) +  (unsigned int)Buf[281]);
 SymbolRate.ChangingValue =  SymbolRate.Value;
FreqPCh.Value = (float64)( ((unsigned int)Buf[282] << 24) + ((unsigned int)Buf[283] << 16) 
 	+ ((unsigned int)Buf[284] << 8) +  (unsigned int)Buf[285]);
 FreqPCh.ChangingValue =  FreqPCh.Value;
ModulSK.Value = (float64)( ((unsigned int)Buf[286] << 24) + ((unsigned int)Buf[287] << 16) 
 	+ ((unsigned int)Buf[288] << 8) +  (unsigned int)Buf[289]);
 ModulSK.ChangingValue =  ModulSK.Value;



/*
MDataC	SymbolRate;
MDataC	FreqPCh;
MDataC	ModulSK;
 */
#endif

#ifdef PROG_BMDN

Protect0.Value = (float64)( ((unsigned int)Buf[290] << 24) + ((unsigned int)Buf[291] << 16) 
 	+ ((unsigned int)Buf[292] << 8) +  (unsigned int)Buf[293]);
Protect0.ChangingValue =  Protect0.Value;
SetProt(0, Protect0.Value);

#ifndef PROG_BMDN6MI

Protect1.Value = (float64)( ((unsigned int)Buf[294] << 24) + ((unsigned int)Buf[295] << 16) 
 	+ ((unsigned int)Buf[296] << 8) +  (unsigned int)Buf[297]);
Protect1.ChangingValue =  Protect1.Value;
SetProt(1, Protect1.Value);
Protect2.Value = (float64)( ((unsigned int)Buf[298] << 24) + ((unsigned int)Buf[299] << 16) 
 	+ ((unsigned int)Buf[300] << 8) +  (unsigned int)Buf[301]);
Protect2.ChangingValue =  Protect2.Value;
SetProt(2, Protect2.Value);

Protect3.Value = (float64)( ((unsigned int)Buf[302] << 24) + ((unsigned int)Buf[303] << 16) 
 	+ ((unsigned int)Buf[304] << 8) +  (unsigned int)Buf[305]);
Protect3.ChangingValue =  Protect3.Value;
SetProt(3, Protect3.Value);

Protect4.Value = (float64)( ((unsigned int)Buf[306] << 24) + ((unsigned int)Buf[307] << 16) 
 	+ ((unsigned int)Buf[308] << 8) +  (unsigned int)Buf[309]);
Protect4.ChangingValue =  Protect4.Value;
SetProt(4, Protect4.Value);

Protect5.Value = (float64)( ((unsigned int)Buf[310] << 24) + ((unsigned int)Buf[311] << 16) 
 	+ ((unsigned int)Buf[312] << 8) +  (unsigned int)Buf[313]);
Protect5.ChangingValue =  Protect5.Value;
SetProt(5, Protect5.Value);

Protect6.Value = (float64)( ((unsigned int)Buf[314] << 24) + ((unsigned int)Buf[315] << 16) 
 	+ ((unsigned int)Buf[316] << 8) +  (unsigned int)Buf[317]);
Protect6.ChangingValue =  Protect6.Value;
SetProt(6, Protect6.Value);

Protect7.Value = (float64)( ((unsigned int)Buf[318] << 24) + ((unsigned int)Buf[319] << 16) 
 	+ ((unsigned int)Buf[320] << 8) +  (unsigned int)Buf[321]);
Protect7.ChangingValue =  Protect7.Value;
SetProt(7, Protect7.Value);

Protect8.Value = (float64)( ((unsigned int)Buf[322] << 24) + ((unsigned int)Buf[323] << 16) 
 	+ ((unsigned int)Buf[324] << 8) +  (unsigned int)Buf[325]);
Protect8.ChangingValue =  Protect8.Value;
SetProt(8, Protect8.Value);

Protect9.Value = (float64)( ((unsigned int)Buf[326] << 24) + ((unsigned int)Buf[327] << 16) 
 	+ ((unsigned int)Buf[328] << 8) +  (unsigned int)Buf[329]);
Protect9.ChangingValue =  Protect9.Value;
SetProt(9, Protect9.Value);

Protect10.Value = (float64)( ((unsigned int)Buf[330] << 24) + ((unsigned int)Buf[331] << 16) 
 	+ ((unsigned int)Buf[332] << 8) +  (unsigned int)Buf[333]);
Protect10.ChangingValue =  Protect10.Value;
SetProt(10, Protect10.Value);

Protect11.Value = (float64)( ((unsigned int)Buf[334] << 24) + ((unsigned int)Buf[335] << 16) 
 	+ ((unsigned int)Buf[336] << 8) +  (unsigned int)Buf[337]);
Protect11.ChangingValue =  Protect11.Value;
SetProt(11, Protect11.Value);

Protect12.Value = (float64)( ((unsigned int)Buf[338] << 24) + ((unsigned int)Buf[339] << 16) 
 	+ ((unsigned int)Buf[340] << 8) +  (unsigned int)Buf[341]);
Protect12.ChangingValue =  Protect12.Value;
SetProt(12, Protect12.Value);

Protect13.Value = (float64)( ((unsigned int)Buf[342] << 24) + ((unsigned int)Buf[343] << 16) 
 	+ ((unsigned int)Buf[344] << 8) +  (unsigned int)Buf[345]);
Protect13.ChangingValue =  Protect13.Value;
SetProt(13, Protect13.Value);

Protect14.Value = (float64)( ((unsigned int)Buf[346] << 24) + ((unsigned int)Buf[347] << 16) 
 	+ ((unsigned int)Buf[348] << 8) +  (unsigned int)Buf[349]);
Protect14.ChangingValue =  Protect14.Value;
SetProt(14, Protect14.Value);

Protect15.Value = (float64)( ((unsigned int)Buf[350] << 24) + ((unsigned int)Buf[351] << 16) 
 	+ ((unsigned int)Buf[352] << 8) +  (unsigned int)Buf[353]);
Protect15.ChangingValue =  Protect15.Value;
SetProt(15, Protect15.Value);

Protect16.Value = (float64)( ((unsigned int)Buf[354] << 24) + ((unsigned int)Buf[355] << 16) 
 	+ ((unsigned int)Buf[356] << 8) +  (unsigned int)Buf[357]);
Protect16.ChangingValue =  Protect16.Value;
SetProt(16, Protect16.Value);

Protect17.Value = (float64)( ((unsigned int)Buf[358] << 24) + ((unsigned int)Buf[359] << 16) 
 	+ ((unsigned int)Buf[360] << 8) +  (unsigned int)Buf[361]);
Protect17.ChangingValue =  Protect17.Value;
SetProt(17, Protect17.Value);

#endif

#endif

#ifdef HAVE_GATEWAY

 Network.Value = (float64)( ((unsigned int)Buf[362] << 24) + ((unsigned int)Buf[363] << 16) 
 	+ ((unsigned int)Buf[364] << 8) +  (unsigned int)Buf[365]);
 Network.ChangingValue =  Network.Value;

		Network0.Value = (unsigned)Network.Value & 0xff;
		Network0.ChangingValue = Network0.Value;

		Network1.Value = (unsigned char)((unsigned)Network.Value >> 8);
		Network1.ChangingValue = Network1.Value;
        
		Network2.Value = (unsigned char)((unsigned)Network.Value >> 16);
		Network2.ChangingValue = Network2.Value;

		Network3.Value = (unsigned char)((unsigned)Network.Value >> 24);
		Network3.ChangingValue = Network3.Value;



 NetMask.Value = (float64)( ((unsigned int)Buf[366] << 24) + ((unsigned int)Buf[367] << 16) 
 	+ ((unsigned int)Buf[368] << 8) +  (unsigned int)Buf[369]);


 if(!CheckNetMask((unsigned long)NetMask.Value))
//if(0)
 {
     NetMask.Value = DEFAULT_MASK; //140904
 }
 NetMask.ChangingValue =  NetMask.Value;


		NetMask0.Value = (unsigned)NetMask.Value & 0xff;
		NetMask0.ChangingValue = NetMask0.Value;

		NetMask1.Value = (unsigned char)((unsigned)NetMask.Value >> 8);
		NetMask1.ChangingValue = NetMask1.Value;

		NetMask2.Value = (unsigned char)((unsigned)NetMask.Value >> 16);
		NetMask2.ChangingValue = NetMask2.Value;

		NetMask3.Value = (unsigned char)((unsigned)NetMask.Value >> 24);
		NetMask3.ChangingValue = NetMask3.Value;



#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU3
//_________________________________________________________________________
SymbolRate2.Value = (float64)( ((unsigned int)Buf[370] << 24) + ((unsigned int)Buf[371] << 16) 
 	+ ((unsigned int)Buf[372] << 8) +  (unsigned int)Buf[373]);
 SymbolRate2.ChangingValue =  SymbolRate2.Value;
FreqPCh2.Value = (float64)( ((unsigned int)Buf[374] << 24) + ((unsigned int)Buf[375] << 16) 
 	+ ((unsigned int)Buf[376] << 8) +  (unsigned int)Buf[377]);
 FreqPCh2.ChangingValue =  FreqPCh2.Value;
ModulSK2.Value = (float64)( ((unsigned int)Buf[378] << 24) + ((unsigned int)Buf[379] << 16) 
 	+ ((unsigned int)Buf[380] << 8) +  (unsigned int)Buf[381]);
 ModulSK2.ChangingValue =  ModulSK2.Value;
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
//_________________________________________________________________________
SymbolRate2.Value = (float64)( ((unsigned int)Buf[370] << 24) + ((unsigned int)Buf[371] << 16) 
 	+ ((unsigned int)Buf[372] << 8) +  (unsigned int)Buf[373]);
 SymbolRate2.ChangingValue =  SymbolRate2.Value;
FreqPCh2.Value = (float64)( ((unsigned int)Buf[374] << 24) + ((unsigned int)Buf[375] << 16) 
 	+ ((unsigned int)Buf[376] << 8) +  (unsigned int)Buf[377]);
 FreqPCh2.ChangingValue =  FreqPCh2.Value;
ModulSK2.Value = (float64)( ((unsigned int)Buf[378] << 24) + ((unsigned int)Buf[379] << 16) 
 	+ ((unsigned int)Buf[380] << 8) +  (unsigned int)Buf[381]);
 ModulSK2.ChangingValue =  ModulSK2.Value;
#endif



#ifdef PROG_COMMUTATOR1
  numa[0] =  Buf[382]; numa[1] =  Buf[383];numa[2] =  Buf[384];
  numb[0] =  Buf[385]; numb[1] =  Buf[386];numb[2] =  Buf[387];
  numc[0] =  Buf[388]; numc[1] =  Buf[389];numc[2] =  Buf[390];

#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
//_________________________________________________________________________
SymbolRate3.Value = (float64)( ((unsigned int)Buf[391] << 24) + ((unsigned int)Buf[392] << 16) 
 	+ ((unsigned int)Buf[393] << 8) +  (unsigned int)Buf[394]);
 SymbolRate3.ChangingValue =  SymbolRate3.Value;
FreqPCh3.Value = (float64)( ((unsigned int)Buf[395] << 24) + ((unsigned int)Buf[396] << 16) 
 	+ ((unsigned int)Buf[397] << 8) +  (unsigned int)Buf[398]);
 FreqPCh3.ChangingValue =  FreqPCh3.Value;
ModulSK3.Value = (float64)( ((unsigned int)Buf[399] << 24) + ((unsigned int)Buf[400] << 16) 
 	+ ((unsigned int)Buf[401] << 8) +  (unsigned int)Buf[402]);
 ModulSK3.ChangingValue =  ModulSK3.Value;

SymbolRate4.Value = (float64)( ((unsigned int)Buf[403] << 24) + ((unsigned int)Buf[404] << 16) 
 	+ ((unsigned int)Buf[405] << 8) +  (unsigned int)Buf[406]);
 SymbolRate4.ChangingValue =  SymbolRate4.Value;
FreqPCh4.Value = (float64)( ((unsigned int)Buf[407] << 24) + ((unsigned int)Buf[408] << 16) 
 	+ ((unsigned int)Buf[409] << 8) +  (unsigned int)Buf[410]);
 FreqPCh4.ChangingValue =  FreqPCh4.Value;
ModulSK4.Value = (float64)( ((unsigned int)Buf[411] << 24) + ((unsigned int)Buf[412] << 16) 
 	+ ((unsigned int)Buf[413] << 8) +  (unsigned int)Buf[414]);
 ModulSK4.ChangingValue =  ModulSK4.Value;

test0 = Buf[415];  test1 = Buf[416]; test2 = Buf[417]; test3 = Buf[418];

decoder0 = Buf[419];  decoder1 = Buf[420]; decoder2 = Buf[421]; decoder3 = Buf[422];

#endif


#ifdef PROG_PU_MSAT

SatSet0.Value = (float64)( ((unsigned int)Buf[423] << 24) + ((unsigned int)Buf[424] << 16) 
 	+ ((unsigned int)Buf[425] << 8) +  (unsigned int)Buf[426]);
 SatSet0.ChangingValue =  SatSet0.Value;

SatSet1.Value = (float64)( ((unsigned int)Buf[427] << 24) + ((unsigned int)Buf[428] << 16) 
 	+ ((unsigned int)Buf[429] << 8) +  (unsigned int)Buf[430])/(float64)1000;
 SatSet1.ChangingValue =  SatSet1.Value;

SatSet2.Value = (float64)( ((unsigned int)Buf[431] << 24) + ((unsigned int)Buf[432] << 16) 
 	+ ((unsigned int)Buf[433] << 8) +  (unsigned int)Buf[434]);

SatSet2.Value /= (float64)10;
 SatSet2.ChangingValue =  SatSet2.Value;

SatSet3.Value = (float64)( ((signed int)Buf[435] << 24) + ((signed int)Buf[436] << 16) 
 	+ ((signed int)Buf[437] << 8) +  (signed int)Buf[438]);
 SatSet3.ChangingValue =  SatSet3.Value;

SatSet4.Value = (float64)( ((unsigned int)Buf[439] << 24) + ((unsigned int)Buf[440] << 16) 
 	+ ((unsigned int)Buf[441] << 8) +  (unsigned int)Buf[442]);
 SatSet4.ChangingValue =  SatSet4.Value;

SatSet5.Value = (float64)( ((unsigned int)Buf[443] << 24) + ((unsigned int)Buf[444] << 16) 
 	+ ((unsigned int)Buf[445] << 8) +  (unsigned int)Buf[446]);
 SatSet5.ChangingValue =  SatSet5.Value;

SatSet6.Value = (float64)( ((unsigned int)Buf[447] << 24) + ((unsigned int)Buf[448] << 16) 
 	+ ((unsigned int)Buf[449] << 8) +  (unsigned int)Buf[450]);
 SatSet6.ChangingValue =  SatSet6.Value;

SatSet7.Value = (float64)( ((unsigned int)Buf[451] << 24) + ((unsigned int)Buf[452] << 16) 
 	+ ((unsigned int)Buf[453] << 8) +  (unsigned int)Buf[454]);
 SatSet7.ChangingValue =  SatSet7.Value;

SatTestMode.Value =  (unsigned char)Buf[455];
SatTestMode.ChangingValue =  (unsigned char)Buf[455];

SatPC.Value =  (unsigned char)Buf[456];
SatPC.ChangingValue =  (unsigned char)Buf[456]; 

SatTiming.Value =  (unsigned char)Buf[457];
SatTiming.ChangingValue =  (unsigned char)Buf[457];

SatSet8.Value = (float64)( ((unsigned int)Buf[458] << 24) + ((unsigned int)Buf[459] << 16) 
 	+ ((unsigned int)Buf[460] << 8) +  (unsigned int)Buf[461]);
 SatSet8.ChangingValue =  SatSet8.Value;

SatSound.Value =  (unsigned char)Buf[462];
SatSound.ChangingValue =  (unsigned char)Buf[462];
 

#endif

#ifdef PROG_MD310_SATI
SatSound.Value =  (unsigned char)Buf[462];
SatSound.ChangingValue =  (unsigned char)Buf[462];
#endif

#ifdef PROG_BMDN
//_________________________________________________________________________
ModEth.Value = (float64)( ((unsigned long)Buf[463] << 24) + ((unsigned long)Buf[464] << 16) 
 	+ ((unsigned long)Buf[465] << 8) +  (unsigned long)Buf[466]);
ModEth.ChangingValue =  ModEth.Value;
#endif

#ifdef USE_HTTP
//_________________________________________________________________________
WebPassword.Value = (float64)( ((unsigned long)Buf[467] << 24) + ((unsigned long)Buf[468] << 16) 
 	+ ((unsigned long)Buf[469] << 8) +  (unsigned long)Buf[470]);
WebPassword.ChangingValue =  WebPassword.Value;

#ifdef PROG_PU_MSAT

  dev1.pum100s1.WebPasswordr0 = 	(unsigned)WebPassword.Value;
 	 dev1.pum100s1.WebPasswordr1 = 	(unsigned)WebPassword.Value>>8;
 	 dev1.pum100s1.WebPasswordr2 = 	(unsigned)WebPassword.Value>>16;
 	 dev1.pum100s1.WebPasswordr3 = 	(unsigned)WebPassword.Value>>24;

#endif
#endif

#ifdef PROG_PU_MSAT
SatDF.Value =  (unsigned char)Buf[471];
SatDF.ChangingValue =  (unsigned char)Buf[471];

SatTF.Value =  (unsigned char)Buf[472];
SatTF.ChangingValue =  (unsigned char)Buf[472];

SatRate.Value = (float64)( ((unsigned long)Buf[473] << 24) + ((unsigned long)Buf[474] << 16) 
 	+ ((unsigned long)Buf[475] << 8) +  (unsigned long)Buf[476]);
SatRate.ChangingValue =  SatRate.Value;

SatTimer.Value = (float64)( ((unsigned long)Buf[477] << 24) + ((unsigned long)Buf[478] << 16) 
 	+ ((unsigned long)Buf[479] << 8) +  (unsigned long)Buf[480]);
SatTimer.ChangingValue =  SatTimer.Value;


#endif

#ifdef PROG_PU_M_V_A

 if(flag_crc)
 {
AttData.Value = (float64)( ((unsigned long)Buf[481] << 24) + ((unsigned long)Buf[482] << 16) 
 	+ ((unsigned long)Buf[483] << 8) +  (unsigned long)Buf[484]);
AttData.ChangingValue =  AttData.Value;
 }
 else
 {
 AttData.Value = 0;
 AttData.ChangingValue =  AttData.Value;
 }

#endif


#ifdef PROG_PU_MSAT
#ifdef RECEIVE_MOD_LOCK

SatExtLock.Value =  (unsigned char)Buf[489];
SatExtLock.ChangingValue =  (unsigned char)Buf[489];
// printfpd("\n\rLr:%d", (unsigned)SatExtLock.Value);


SatExtLockP.Value =  (unsigned char)Buf[490];
SatExtLockP.ChangingValue =  (unsigned char)Buf[490];
//printfpd("\n\rLr1:%d", (unsigned)SatExtLockP.Value);

#endif
SatLowP.Value =  (unsigned char)Buf[491];
SatLowP.ChangingValue =  (unsigned char)Buf[491];

SatALev.Value =  (unsigned char)Buf[492];
SatALev.ChangingValue =  (unsigned char)Buf[492];

//printfpd("\n\r Satalev: %d", SatALev.Value);


SatADemo.Value =  (unsigned char)Buf[493];
SatADemo.ChangingValue =  (unsigned char)Buf[493];

SatACode.Value = (float64)( ((unsigned long)Buf[494] << 24) + ((unsigned long)Buf[495] << 16) 
 	+ ((unsigned long)Buf[496] << 8) +  (unsigned long)Buf[497]);

SatACode.Value = 0; //not need keep
SatACode.ChangingValue =  0; //to do not view on display

//printfpd("\n\r Satacode: %d", SatACode.Value);

#endif

#ifdef 	PROG_PU_M_MUX
  modforss = Buf[498];
#endif


#ifdef PROG_PU_MSAT  

 FlagOldSatAlev = Buf[499];// = 0;
 OldSatAlev = Buf[500]; //0;
#endif



#ifdef   PROG_MD310_SATI

 LoadVariants.Value =  Buf[501];
 LoadVariants.ChangingValue	= Buf[501];

 SaveVariants.Value =  Buf[502];
 SaveVariants.ChangingValue	= Buf[502];

 MRfOut.Value =  Buf[503];
 MRfOut.ChangingValue	= Buf[503];

MOutLev.Value =  (float64)((Buf[504] << 24) + (Buf[505] << 16) 
 	+ (Buf[506] << 8) +  Buf[507])/(float64)10;

MOutLev.ChangingValue =  MOutLev.Value;


MTFreq.Value = (float64)( ((unsigned long)Buf[508] << 24) + ((unsigned long)Buf[509] << 16) 
 	+ ((unsigned long)Buf[510] << 8) +  (unsigned long)Buf[511]) / (float64)10000;
MTFreq.ChangingValue =  MTFreq.Value;


MRFreq.Value = (float64)( ((unsigned long)Buf[512] << 24) + ((unsigned long)Buf[513] << 16) 
 	+ ((unsigned long)Buf[514] << 8) +  (unsigned long)Buf[515]) / (float64)10000;
MRFreq.ChangingValue =  MRFreq.Value;

  //	 printfpdv("\n\r read freq: %5.4f",MRFreq.Value);


 MDemod.Value =  Buf[516];
 MDemod.ChangingValue	= Buf[516];


 MEthMode.Value =  Buf[517];
 MEthMode.ChangingValue	= Buf[517];

 //printfpd("\n\r read em %d:", (unsigned)MEthMode.Value);


 MEthPause.Value =  Buf[518];
 MEthPause.ChangingValue	= Buf[518];

 MEthctl.Value =  Buf[519];
 MEthctl.ChangingValue	= Buf[519];


MEthMaxF.Value = (float64)( ((unsigned long)Buf[520] << 24) + ((unsigned long)Buf[521] << 16) 
 	+ ((unsigned long)Buf[522] << 8) +  (unsigned long)Buf[523]);
MEthMaxF.ChangingValue =  MEthMaxF.Value;

MEthVlanP.Value = (float64)( ((unsigned long)Buf[524] << 24) + ((unsigned long)Buf[525] << 16) 
 	+ ((unsigned long)Buf[526] << 8) +  (unsigned long)Buf[527]);
MEthVlanP.ChangingValue =  MEthVlanP.Value;

MTEbN0.Value = (float64)( ((unsigned long)Buf[528] << 24) + ((unsigned long)Buf[529] << 16) 
 	+ ((unsigned long)Buf[530] << 8) +  (unsigned long)Buf[531]);
MTEbN0.ChangingValue =  MTEbN0.Value;

MTBER.Value = (float64)( ((unsigned long)Buf[532] << 24) + ((unsigned long)Buf[533] << 16) 
 	+ ((unsigned long)Buf[534] << 8) +  (unsigned long)Buf[535]);
MTBER.ChangingValue =  MTBER.Value;


 MIfLoop.Value =  Buf[536];
 MIfLoop.ChangingValue	= Buf[536];

 MUnModul.Value =  Buf[537];
 MUnModul.ChangingValue	= Buf[537];

 MACMM.Value =  Buf[538];
 MACMM.ChangingValue	= Buf[538];

MTBERE.Value = (float64)( ((unsigned long)Buf[539] << 24) + ((unsigned long)Buf[540] << 16) 
 	+ ((unsigned long)Buf[541] << 8) +  (unsigned long)Buf[542]);
MTBERE.ChangingValue =  MTBERE.Value;

MTMode.Value = Buf[543];
MTMode.ChangingValue  = MTMode.Value;

MRMode.Value = Buf[544];
MRMode.ChangingValue  = MRMode.Value;

MRCntl.Value = Buf[545];
MRCntl.ChangingValue  = MRCntl.Value;

MOutLevO.Value =  ((Buf[546] << 24) + (Buf[547] << 16) 
 	+ (Buf[548] << 8) +  Buf[549] )/ (float64)1000;
MOutLevO.ChangingValue =  MOutLevO.Value;  

//printfpdv("\n\rrd MOutLevo: % 5.3f",MOutLevO.Value);


MOutLevOS.Value =   Buf[550];
MOutLevOS.ChangingValue =  MOutLevOS.Value;

MKOUT.Value =  ((Buf[551] << 24) + (Buf[552] << 16) 
 	+ (Buf[553] << 8) +  Buf[554])/(float64)10;
MKOUT.ChangingValue =  MKOUT.Value;

MKOUT1.Value =  (Buf[555] << 24) + (Buf[556] << 16) 
 	+ (Buf[557] << 8) +  Buf[558];
MKOUT1.ChangingValue =  MKOUT1.Value;

MKIN1.Value =  (Buf[559] << 24) + (Buf[560] << 16) 
 	+ (Buf[561] << 8) +  Buf[562];
MKIN1.ChangingValue =  MKIN1.Value;

MKIN2.Value =  (Buf[563] << 24) + (Buf[564] << 16) 
 	+ (Buf[565] << 8) +  Buf[566];
MKIN2.ChangingValue =  MKIN2.Value;

MKIN3.Value =  (Buf[567] << 24) + (Buf[568] << 16) 
 	+ (Buf[569] << 8) +  Buf[570];
MKIN3.ChangingValue =  MKIN3.Value;


//______________________________________________________________


//________________________________________________________________


#endif




return flag_crc;
}



//__________________________________

extern "C" unsigned char ReadDevId2(unsigned char flag_lock)
{

 char Buf[DEV_ID_SIZE2];
 unsigned int DeviceAddress = ID_ADDRESS2;
 read_dataflash (DeviceAddress, DEV_ID_SIZE2, (char *)&Buf[0]);
// read_flag = 1;



//__________________________________________________crc
unsigned char flag_crc = 0;
unsigned char id_crc = 0;
unsigned long check_ver = 0;
unsigned long tmp;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE2 - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

 check_ver = ( ((unsigned long)Buf[60] << 24) + ((unsigned long)Buf[61] << 16) 
 	+ ((unsigned long)Buf[62] << 8) +  (unsigned long)Buf[63]);



 if(id_crc == Buf[DEV_ID_SIZE2 - 1])	
 {
    flag_crc = 1;
  //	printfp("\n\r1");
 }
 else
 {
//try read second time
  read_dataflash (DeviceAddress, DEV_ID_SIZE2, (char *)&Buf[0]);
  id_crc = 0;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE2 - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;
  check_ver = ( ((unsigned long)Buf[60] << 24) + ((unsigned long)Buf[61] << 16) 
 	+ ((unsigned long)Buf[62] << 8) +  (unsigned long)Buf[63]);


  if(id_crc == Buf[DEV_ID_SIZE2 - 1])	
 {
    flag_crc = 1;
 //	printfp("\n\r2");

 }
  else
  {
//try read three time

 read_dataflash (DeviceAddress, DEV_ID_SIZE2, (char *)&Buf[0]);
  id_crc = 0;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE2 - 1); icrc++ )
 {
  id_crc +=  Buf[icrc];
 }
 id_crc += 1;

 check_ver = ( ((unsigned long)Buf[60] << 24) + ((unsigned long)Buf[61] << 16) 
 	+ ((unsigned long)Buf[62] << 8) +  (unsigned long)Buf[63]);


  if(id_crc == Buf[DEV_ID_SIZE2 - 1])	
 {
    flag_crc = 1;
   //	printfp("\n\r3");

 }
 else
 {
//three time crc bad
  // printfp("\n\r4");
 }
  }
 }
//__________________________________________________crc


  if((!flag_crc) && (check_ver == SOFT_VER))
  {
  	
    }


#ifdef 	PROG_PRM_PCH_L
RestoreFreq(1, ((unsigned int)Buf[0] << 24) + ((unsigned int)Buf[1] << 16) 
 	+ ((unsigned int)Buf[2] << 8) +  (unsigned int)Buf[3]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(2, ((unsigned int)Buf[4] << 24) + ((unsigned int)Buf[5] << 16) 
 	+ ((unsigned int)Buf[6] << 8) +  (unsigned int)Buf[7]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(3, ((unsigned int)Buf[8] << 24) + ((unsigned int)Buf[9] << 16) 
 	+ ((unsigned int)Buf[10] << 8) +  (unsigned int)Buf[11]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);


RestoreAttRPU(1, ((unsigned int)Buf[12] << 24) + ((unsigned int)Buf[13] << 16) 
	+ ((unsigned int)Buf[14] << 8) +  (unsigned int)Buf[15]);

  #ifdef MAKET_PLATA
   tmp =  ((unsigned int)Buf[12] << 24) + ((unsigned int)Buf[13] << 16) 
	+ ((unsigned int)Buf[14] << 8) +  (unsigned int)Buf[15];
    printfpd("\n\rattrpu : %d", tmp);
	#endif

RestoreAttRPU(2, ((unsigned int)Buf[16] << 24) + ((unsigned int)Buf[17] << 16) 
	+ ((unsigned int)Buf[18] << 8) +  (unsigned int)Buf[19]);
RestoreAttRPU(3, ((unsigned int)Buf[20] << 24) + ((unsigned int)Buf[21] << 16) 
	+ ((unsigned int)Buf[22] << 8) +  (unsigned int)Buf[23]);

RestoreFreq(4, ((unsigned int)Buf[24] << 24) + ((unsigned int)Buf[25] << 16) 
 	+ ((unsigned int)Buf[26] << 8) +  (unsigned int)Buf[27]);
//091109RestoreAtt(1, ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
//091109 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
RestoreFreq(5, ((unsigned int)Buf[28] << 24) + ((unsigned int)Buf[29] << 16) 
 	+ ((unsigned int)Buf[30] << 8) +  (unsigned int)Buf[31]);
//091109RestoreAtt(2, ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
//091109 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);
RestoreFreq(6, ((unsigned int)Buf[32] << 24) + ((unsigned int)Buf[33] << 16) 
 	+ ((unsigned int)Buf[34] << 8) +  (unsigned int)Buf[35]);
//091109RestoreAtt(3, ((unsigned int)Buf[64] << 24) + ((unsigned int)Buf[65] << 16) 
//091109 	+ ((unsigned int)Buf[66] << 8) +  (unsigned int)Buf[67]);
RestoreAttRPU(4, ((unsigned int)Buf[36] << 24) + ((unsigned int)Buf[37] << 16) 
	+ ((unsigned int)Buf[38] << 8) +  (unsigned int)Buf[39]);
RestoreAttRPU(5, ((unsigned int)Buf[40] << 24) + ((unsigned int)Buf[41] << 16) 
	+ ((unsigned int)Buf[42] << 8) +  (unsigned int)Buf[43]);
RestoreAttRPU(6, ((unsigned int)Buf[44] << 24) + ((unsigned int)Buf[45] << 16) 
	+ ((unsigned int)Buf[46] << 8) +  (unsigned int)Buf[47]);
#endif // PROG_PRM_PCH_L



#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH 


tmp = ( ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
  #ifdef MAKET_PLATA
  printfpd("\n\rf : %d", tmp);
#endif

  InitFreq(tmp);


tmp = ( ((unsigned int)Buf[52] << 24) + ((unsigned int)Buf[53] << 16) 
 	+ ((unsigned int)Buf[54] << 8) +  (unsigned int)Buf[55]);

  RestoreAtt(1, tmp);
    #ifdef MAKET_PLATA

    printfpd("\n\ratt : %d", tmp);
	#endif


tmp = ( ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);

  RestoreAtt2(1, tmp);
    #ifdef MAKET_PLATA

    printfpd("\n\ratt2 : %d", tmp);
	#endif


#endif

#ifdef	 PROG_PRM_PCH_SPI_XIL 
#ifndef	 PROG_PRM_PCH_SPI_XIL_ETH 


tmp = ( ((unsigned int)Buf[48] << 24) + ((unsigned int)Buf[49] << 16) 
 	+ ((unsigned int)Buf[50] << 8) +  (unsigned int)Buf[51]);
  #ifdef MAKET_PLATA
  printfpd("\n\rfreq : %d", tmp);
#endif

  InitFreq(tmp);


tmp = ( ((unsigned int)Buf[52] << 24) + ((unsigned int)Buf[53] << 16) 
 	+ ((unsigned int)Buf[54] << 8) +  (unsigned int)Buf[55]);

  RestoreAtt(1, tmp);
    #ifdef MAKET_PLATA

    printfpd("\n\ratt : %d", tmp);
	#endif


tmp = ( ((unsigned int)Buf[56] << 24) + ((unsigned int)Buf[57] << 16) 
 	+ ((unsigned int)Buf[58] << 8) +  (unsigned int)Buf[59]);

  RestoreAtt2(1, tmp);

    #ifdef MAKET_PLATA
    printfpd("\n\ratt2 : %d", tmp);
	#endif


#endif
#endif



#ifdef PROG_PRM_PCH_L_61

#ifndef PROG_PUPM2 
#ifndef	 PROG_PRM_PCH_SPI_NOXIL_ETH 
#ifndef	 PROG_PRM_PCH_SPI_XIL_ETH 

#ifndef	 PROG_PRM_PCH_SPI_XIL 
  SourcePCH = Buf[64];

   #ifdef MAKET_PLATA

    printfpd("\n\rSourcePCH : %x", SourcePCH);
	#endif

#endif
#endif
#endif
#endif
#endif


#ifdef 	PROG_PD3

 freqpd =  (Buf[65] << 8) +	 Buf[66];
 attpd = Buf[67];

#endif

 #ifdef	 PROG_PRM_PCH_SPI_ETH_UART 

 prm_inp = Buf[68];
 Filtr = Buf[69];


#ifdef MAKET_PLATA

    printfpd("\n\rprm_inp : %x", prm_inp);
	 printfpd("\n\rFiltr : %x", Filtr);

	#endif


#endif





  if(!flag_crc)
  {
  	
    }




return flag_crc;

/*
#ifdef 	PROG_PRM_PCH_L
 tmp = GetFreq(1);
 Buf[0] = (char)(tmp >> 24);  Buf[1] = (char)(tmp >> 16);	Buf[2] = (char)(tmp >> 8);
 Buf[3] = (char)(tmp);
 tmp = GetFreq(2);
 Buf[4] = (char)(tmp >> 24);  Buf[5] = (char)(tmp >> 16);	Buf[6] = (char)(tmp >> 8);
 Buf[7] = (char)(tmp);
 tmp = GetFreq(3);
 Buf[8] = (char)(tmp >> 24);  Buf[9] = (char)(tmp >> 16);	Buf[10] = (char)(tmp >> 8);
 Buf[11] = (char)(tmp);
 tmp = GetAttRPU(1);
 Buf[12] = (char)(tmp >> 24);  Buf[13] = (char)(tmp >> 16);	Buf[14] = (char)(tmp >> 8);
 Buf[15] = (char)(tmp);
 tmp = GetAttRPU(2);
 Buf[16] = (char)(tmp >> 24);  Buf[17] = (char)(tmp >> 16);	Buf[18] = (char)(tmp >> 8);
 Buf[19] = (char)(tmp);
 tmp = GetAttRPU(3);
 Buf[20] = (char)(tmp >> 24);  Buf[21] = (char)(tmp >> 16);	Buf[22] = (char)(tmp >> 8);
 Buf[23] = (char)(tmp);
 tmp = GetFreq(4);
 Buf[24] = (char)(tmp >> 24);  Buf[25] = (char)(tmp >> 16);	Buf[26] = (char)(tmp >> 8);
 Buf[27] = (char)(tmp);
 tmp = GetFreq(5);
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);
tmp = GetFreq(6);
 Buf[32] = (char)(tmp >> 24);  Buf[33] = (char)(tmp >> 16);	Buf[34] = (char)(tmp >> 8);
 Buf[35] = (char)(tmp);

 tmp = GetAttRPU(4);
 Buf[36] = (char)(tmp >> 24);  Buf[37] = (char)(tmp >> 16);	Buf[38] = (char)(tmp >> 8);
 Buf[39] = (char)(tmp);
// tmp = GetAtt(4);
// Buf[84] = (char)(tmp >> 24);  Buf[85] = (char)(tmp >> 16);	Buf[86] = (char)(tmp >> 8);
// Buf[87] = (char)(tmp);
 tmp = GetAttRPU(5);
 Buf[40] = (char)(tmp >> 24);  Buf[41] = (char)(tmp >> 16);	Buf[42] = (char)(tmp >> 8);
 Buf[43] = (char)(tmp);
// tmp = GetAtt(5);
// Buf[92] = (char)(tmp >> 24);  Buf[93] = (char)(tmp >> 16);	Buf[94] = (char)(tmp >> 8);
// Buf[95] = (char)(tmp);
 tmp = GetAttRPU(6);
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);


//48 ...60 - rezerved


#endif //PROG_PRM_PCH_L



*/

}

//_________________________________


extern "C" unsigned char CheckDevId(unsigned int DeviceAddress)
{


//return;	  //t


 char Buf[DEV_ID_SIZE];
 //unsigned int DeviceAddress = ID_ADDRESS;
 read_dataflash (DeviceAddress, DEV_ID_SIZE, (char *)&Buf[0]);
// read_dataflash (DeviceAddress, DEV_ID_SIZE+100, (char *)&Buf[0]);
 read_flag = 1;



//__________________________________________________crc
unsigned char flag_crc = 0;
unsigned char id_crc = 0;
unsigned long check_ver = 0;

 // printfp("\n\r CheckDevId \n\r");

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
//  if(!(id_crc%10)) printfp("\n\r");
  id_crc +=  Buf[icrc];
//  printfpd(" %3d:",icrc);
 // printfpd(" %02X ", Buf[icrc]);
 // printfpd(" %02X ", id_crc);


 }
 id_crc += 1;

check_ver = ( ((unsigned long)Buf[485] << 24) + ((unsigned long)Buf[486] << 16) 
 	+ ((unsigned long)Buf[487] << 8) +  (unsigned long)Buf[488]);


 //	 printfpd("\n\r %02X <-> ", Buf[DEV_ID_SIZE - 1]);
 //	  printfpd(" %02X ", id_crc);


 if(id_crc == Buf[DEV_ID_SIZE - 1])	
 {
   
   //	printfp("... Ok! \n\r");
	  return 1;

 }
 

// printfp("... Wrong! \n\r");

 return 0;
}


extern "C" void WriteDevId(void)
{

//return; //

// printfp("\n\rWriteDevId"); //t

//#ifdef TEST_REMOTE_FF
//#ifdef MAKET_PLATA	
//printfp("\n\rWritedevId");
//#endif
//#endif
//writeid_counter++;

//i40826 if((!start_main_loop) || (!read_flag)) return;

//150518 to do not have olwais hot restart if(!read_flag) return;	//140826


writeid_counter++;

#ifdef MAKET_PLATA	
printfpd("\n\rWritedevId : %d ", DEV_ID_SIZE);
#endif


 char Buf[DEV_ID_SIZE];
  char Buf1[DEV_ID_SIZE];

 unsigned int DeviceAddress = ID_ADDRESS;
 unsigned int AddressSrc    = (unsigned int)(&Buf[0]);
 unsigned int tmp;
 signed int stmp;
 unsigned int cnt;

 tmp = 	DevId.Value;
 Buf[0] = (char)(tmp >> 8);	  Buf[1] = (char)(tmp);
 tmp = 	DevYear.Value;
 Buf[2] = (char)(tmp >> 8);	  Buf[3] = (char)(tmp);
 tmp = 	DevVer1.Value;
 Buf[4] = (char)(tmp >> 8);	  Buf[5] = (char)(tmp);
 tmp = 	DevVer2.Value;
 Buf[6] = (char)(tmp >> 8);	  Buf[7] = (char)(tmp);
 tmp = 	POK.Value;
 Buf[8] = (char)(tmp >> 8);	  Buf[9] = (char)(tmp);
 tmp = 	MAC0.Value;
 Buf[10] = (char)(tmp >> 16); Buf[11] = (char)(tmp >> 8);	Buf[12] = (char)(tmp);
 tmp = 	MAC1.Value;
 Buf[13] = (char)(tmp >> 16); Buf[14] = (char)(tmp >> 8);	Buf[15] = (char)(tmp);
 tmp = 	IPAddress.Value;
 Buf[16] = (char)(tmp >> 24);  Buf[17] = (char)(tmp >> 16);	Buf[18] = (char)(tmp >> 8);
 Buf[19] = (char)(tmp);	
 tmp = 	TestMode.Value;
 Buf[20] = (char)(tmp >> 24);  Buf[21] = (char)(tmp >> 16);	Buf[22] = (char)(tmp >> 8);
 Buf[23] = (char)(tmp);	
 tmp = 	UARTAddress.Value;
 Buf[24] = (char)(tmp >> 24);  Buf[25] = (char)(tmp >> 16);	Buf[26] = (char)(tmp >> 8);
 Buf[27] = (char)(tmp);

//tmp = 	LockMode.Value;
// Buf[24] = (char)(tmp >> 24);  Buf[25] = (char)(tmp >> 16);	Buf[26] = (char)(tmp >> 8);
// Buf[27] = (char)(tmp);

 	
#ifdef PROG_TUTS
 tmp = 	TSOut.Value;
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);	
#endif //PROG_TUTS 
	
#ifdef PROG_BMD35
 tmp = 	RemoteMode.Value;
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);	
#endif //PROG_BMD35 	

#ifdef PROG_PROV
 tmp = 	RemoteMode.Value;
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);	
#endif //PROG_PROV 	


#ifdef PROG_MPC35
 tmp = 	RemoteMode.Value;
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);	
#endif //PROG_MPC35 

#ifdef KTVM_PROT2
 tmp = 	RemoteMode.Value;
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);	
#endif //PROG_MPC35 	
	

 tmp = 	LockMode.Value;
 Buf[32] = (char)(tmp >> 24);  Buf[33] = (char)(tmp >> 16);	Buf[34] = (char)(tmp >> 8);
 Buf[35] = (char)(tmp);	

#ifdef TRAP_ENABLED
 tmp = 	TrapTimer.Value;
 Buf[36] = (char)(tmp >> 24);  Buf[37] = (char)(tmp >> 16);	Buf[38] = (char)(tmp >> 8);
 Buf[39] = (char)(tmp);	

 tmp = 	TrapIp.Value;
 Buf[40] = (char)(tmp >> 24);  Buf[41] = (char)(tmp >> 16);	Buf[42] = (char)(tmp >> 8);
 Buf[43] = (char)(tmp);	
#endif //TRAP_ENABLED


#ifdef 	PROG_PRM_PCH_N_2
 tmp = GetFreqN();
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);
 tmp = GetAttN();
 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);
#endif
   
 /*	 it is maked in prm_pch_L
#ifdef 	PROG_PRM_PCH_SPI
 tmp = GetFreqN();
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);
 tmp = GetAttN();
 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);
#endif
 */



#ifdef 	PROG_PRM_PCH_L
 tmp = GetFreq(1);
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);
 tmp = GetAtt(1);
 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);
 tmp = GetFreq(2);
 Buf[52] = (char)(tmp >> 24);  Buf[53] = (char)(tmp >> 16);	Buf[54] = (char)(tmp >> 8);
 Buf[55] = (char)(tmp);
 tmp = GetAtt(2);
 Buf[56] = (char)(tmp >> 24);  Buf[57] = (char)(tmp >> 16);	Buf[58] = (char)(tmp >> 8);
 Buf[59] = (char)(tmp);
 tmp = GetFreq(3);
 Buf[60] = (char)(tmp >> 24);  Buf[61] = (char)(tmp >> 16);	Buf[62] = (char)(tmp >> 8);
 Buf[63] = (char)(tmp);
 tmp = GetAtt(3);
 Buf[64] = (char)(tmp >> 24);  Buf[65] = (char)(tmp >> 16);	Buf[66] = (char)(tmp >> 8);
 Buf[67] = (char)(tmp);
 tmp = GetAttRPU(1);
 Buf[68] = (char)(tmp >> 24);  Buf[69] = (char)(tmp >> 16);	Buf[70] = (char)(tmp >> 8);
 Buf[71] = (char)(tmp);
 tmp = GetAttRPU(2);
 Buf[72] = (char)(tmp >> 24);  Buf[73] = (char)(tmp >> 16);	Buf[74] = (char)(tmp >> 8);
 Buf[75] = (char)(tmp);
tmp = GetAttRPU(3);
 Buf[76] = (char)(tmp >> 24);  Buf[77] = (char)(tmp >> 16);	Buf[78] = (char)(tmp >> 8);
 Buf[79] = (char)(tmp);

#endif //PROG_PRM_PCH_L


#ifdef 	PROG_PRM_PCH_L

 tmp = GetFreq(4);
 Buf[80] = (char)(tmp >> 24);  Buf[81] = (char)(tmp >> 16);	Buf[82] = (char)(tmp >> 8);
 Buf[83] = (char)(tmp);
// tmp = GetAtt(4);
// Buf[84] = (char)(tmp >> 24);  Buf[85] = (char)(tmp >> 16);	Buf[86] = (char)(tmp >> 8);
// Buf[87] = (char)(tmp);
 tmp = GetFreq(5);
 Buf[84] = (char)(tmp >> 24);  Buf[85] = (char)(tmp >> 16);	Buf[86] = (char)(tmp >> 8);
 Buf[87] = (char)(tmp);
// tmp = GetAtt(5);
// Buf[92] = (char)(tmp >> 24);  Buf[93] = (char)(tmp >> 16);	Buf[94] = (char)(tmp >> 8);
// Buf[95] = (char)(tmp);
 tmp = GetFreq(6);
 Buf[88] = (char)(tmp >> 24);  Buf[89] = (char)(tmp >> 16);	Buf[90] = (char)(tmp >> 8);
 Buf[91] = (char)(tmp);
// tmp = GetAtt(6);
// Buf[64] = (char)(tmp >> 24);  Buf[65] = (char)(tmp >> 16);	Buf[66] = (char)(tmp >> 8);
// Buf[67] = (char)(tmp);
 tmp = GetAttRPU(4);
 Buf[92] = (char)(tmp >> 24);  Buf[93] = (char)(tmp >> 16);	Buf[94] = (char)(tmp >> 8);
 Buf[95] = (char)(tmp);
 tmp = GetAttRPU(5);
 Buf[96] = (char)(tmp >> 24);  Buf[97] = (char)(tmp >> 16);	Buf[98] = (char)(tmp >> 8);
 Buf[99] = (char)(tmp);
 tmp = GetAttRPU(6);
 Buf[100] = (char)(tmp >> 24);  Buf[101] = (char)(tmp >> 16);	Buf[102] = (char)(tmp >> 8);
 Buf[103] = (char)(tmp);

#endif //PROG_PRM_PCH_L

#ifdef PROG_BMDN
tmp = ConfigFile.Value;
 Buf[104] = (char)(tmp >> 24);  Buf[105] = (char)(tmp >> 16);	Buf[106] = (char)(tmp >> 8);
 Buf[107] = (char)(tmp);

//#ifndef PROG_BMDN6MI
tmp = ConfigFile1.Value;
 Buf[108] = (char)(tmp >> 24);  Buf[109] = (char)(tmp >> 16);	Buf[110] = (char)(tmp >> 8);
 Buf[111] = (char)(tmp);

#ifndef PROG_BMDN6MI

tmp = ConfigFile2.Value;
 Buf[112] = (char)(tmp >> 24);  Buf[113] = (char)(tmp >> 16);	Buf[114] = (char)(tmp >> 8);
 Buf[115] = (char)(tmp);
tmp = ConfigFile3.Value;
 Buf[116] = (char)(tmp >> 24);  Buf[117] = (char)(tmp >> 16);	Buf[118] = (char)(tmp >> 8);
 Buf[119] = (char)(tmp);
tmp = ConfigFile4.Value;
 Buf[120] = (char)(tmp >> 24);  Buf[121] = (char)(tmp >> 16);	Buf[122] = (char)(tmp >> 8);
 Buf[123] = (char)(tmp);
tmp = ConfigFile5.Value;
 Buf[124] = (char)(tmp >> 24);  Buf[125] = (char)(tmp >> 16);	Buf[126] = (char)(tmp >> 8);
 Buf[127] = (char)(tmp);
tmp = ConfigFile6.Value;
 Buf[128] = (char)(tmp >> 24);  Buf[129] = (char)(tmp >> 16);	Buf[130] = (char)(tmp >> 8);
 Buf[131] = (char)(tmp);
tmp = ConfigFile7.Value;
 Buf[132] = (char)(tmp >> 24);  Buf[133] = (char)(tmp >> 16);	Buf[134] = (char)(tmp >> 8);
 Buf[135] = (char)(tmp);
tmp = ConfigFile8.Value;
 Buf[136] = (char)(tmp >> 24);  Buf[137] = (char)(tmp >> 16);	Buf[138] = (char)(tmp >> 8);
 Buf[139] = (char)(tmp);
tmp = ConfigFile9.Value;
 Buf[140] = (char)(tmp >> 24);  Buf[141] = (char)(tmp >> 16);	Buf[142] = (char)(tmp >> 8);
 Buf[143] = (char)(tmp);
tmp = ConfigFile10.Value;
 Buf[144] = (char)(tmp >> 24);  Buf[145] = (char)(tmp >> 16);	Buf[146] = (char)(tmp >> 8);
 Buf[147] = (char)(tmp);
tmp = ConfigFile11.Value;
 Buf[148] = (char)(tmp >> 24);  Buf[149] = (char)(tmp >> 16);	Buf[150] = (char)(tmp >> 8);
 Buf[151] = (char)(tmp);
tmp = ConfigFile12.Value;
 Buf[152] = (char)(tmp >> 24);  Buf[153] = (char)(tmp >> 16);	Buf[154] = (char)(tmp >> 8);
 Buf[155] = (char)(tmp);
tmp = ConfigFile13.Value;
 Buf[156] = (char)(tmp >> 24);  Buf[157] = (char)(tmp >> 16);	Buf[158] = (char)(tmp >> 8);
 Buf[159] = (char)(tmp);
tmp = ConfigFile14.Value;
 Buf[160] = (char)(tmp >> 24);  Buf[161] = (char)(tmp >> 16);	Buf[162] = (char)(tmp >> 8);
 Buf[163] = (char)(tmp);
tmp = ConfigFile15.Value;
 Buf[164] = (char)(tmp >> 24);  Buf[165] = (char)(tmp >> 16);	Buf[166] = (char)(tmp >> 8);
 Buf[167] = (char)(tmp);
#endif

tmp = ModForSS.Value;
 Buf[168] = (char)(tmp >> 24);  Buf[169] = (char)(tmp >> 16);	Buf[170] = (char)(tmp >> 8);
 Buf[171] = (char)(tmp);
tmp = Priority0.Value;
 Buf[172] = (char)(tmp >> 24);  Buf[173] = (char)(tmp >> 16);	Buf[174] = (char)(tmp >> 8);
 Buf[175] = (char)(tmp);
#ifndef PROG_BMDN6MI
tmp = Priority1.Value;
 Buf[176] = (char)(tmp >> 24);  Buf[177] = (char)(tmp >> 16);	Buf[178] = (char)(tmp >> 8);
 Buf[179] = (char)(tmp);
tmp = Priority2.Value;
 Buf[180] = (char)(tmp >> 24);  Buf[181] = (char)(tmp >> 16);	Buf[182] = (char)(tmp >> 8);
 Buf[183] = (char)(tmp);
tmp = Priority3.Value;
 Buf[184] = (char)(tmp >> 24);  Buf[185] = (char)(tmp >> 16);	Buf[186] = (char)(tmp >> 8);
 Buf[187] = (char)(tmp);
tmp = Priority4.Value;
 Buf[188] = (char)(tmp >> 24);  Buf[189] = (char)(tmp >> 16);	Buf[190] = (char)(tmp >> 8);
 Buf[191] = (char)(tmp);
tmp = Priority5.Value;
 Buf[192] = (char)(tmp >> 24);  Buf[193] = (char)(tmp >> 16);	Buf[194] = (char)(tmp >> 8);
 Buf[195] = (char)(tmp);
tmp = Priority6.Value;
 Buf[196] = (char)(tmp >> 24);  Buf[197] = (char)(tmp >> 16);	Buf[198] = (char)(tmp >> 8);
 Buf[199] = (char)(tmp);
tmp = Priority7.Value;
 Buf[200] = (char)(tmp >> 24);  Buf[201] = (char)(tmp >> 16);	Buf[202] = (char)(tmp >> 8);
 Buf[203] = (char)(tmp);
tmp = Priority8.Value;
 Buf[204] = (char)(tmp >> 24);  Buf[205] = (char)(tmp >> 16);	Buf[206] = (char)(tmp >> 8);
 Buf[207] = (char)(tmp);
#endif
tmp = Threshold0.Value;
 Buf[208] = (char)(tmp >> 24);  Buf[209] = (char)(tmp >> 16);	Buf[210] = (char)(tmp >> 8);
 Buf[211] = (char)(tmp);

#ifndef PROG_BMDN6MI
tmp = Threshold1.Value;
 Buf[212] = (char)(tmp >> 24);  Buf[213] = (char)(tmp >> 16);	Buf[214] = (char)(tmp >> 8);
 Buf[215] = (char)(tmp);
tmp = Threshold2.Value;
 Buf[216] = (char)(tmp >> 24);  Buf[217] = (char)(tmp >> 16);	Buf[218] = (char)(tmp >> 8);
 Buf[219] = (char)(tmp);
tmp = Threshold3.Value;
 Buf[220] = (char)(tmp >> 24);  Buf[221] = (char)(tmp >> 16);	Buf[222] = (char)(tmp >> 8);
 Buf[223] = (char)(tmp);
tmp = Threshold4.Value;
 Buf[224] = (char)(tmp >> 24);  Buf[225] = (char)(tmp >> 16);	Buf[226] = (char)(tmp >> 8);
 Buf[227] = (char)(tmp);
tmp = Threshold5.Value;
 Buf[228] = (char)(tmp >> 24);  Buf[229] = (char)(tmp >> 16);	Buf[230] = (char)(tmp >> 8);
 Buf[231] = (char)(tmp);
tmp = Threshold6.Value;
 Buf[232] = (char)(tmp >> 24);  Buf[233] = (char)(tmp >> 16);	Buf[234] = (char)(tmp >> 8);
 Buf[235] = (char)(tmp);
tmp = Threshold7.Value;
 Buf[236] = (char)(tmp >> 24);  Buf[237] = (char)(tmp >> 16);	Buf[238] = (char)(tmp >> 8);
 Buf[239] = (char)(tmp);
tmp = Threshold8.Value;
 Buf[240] = (char)(tmp >> 24);  Buf[241] = (char)(tmp >> 16);	Buf[242] = (char)(tmp >> 8);
 Buf[243] = (char)(tmp);

#endif

#endif //PROG_BMDN
#ifdef PROG_PU_M_V
//101117 for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 Buf[244 + iid] = udevconfig.byte[iid];
}
#endif

#ifdef PROG_PU_M_V_A
//101117 for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 Buf[244 + iid] = udevconfig.byte[iid];
}
#endif


#ifdef PROG_UPS
//101117 for(long iid = 0; iid < DEVCONFIG_QUANTITY; iid++)
for(long iid = 0; iid < 34; iid++)
{
 Buf[244 + iid] = udevconfig.byte[iid];		  //110411 - not used - setted in init
}
#endif




#ifdef PROG_PRM_PCH_DEM
tmp = SymbolRate.Value;
 Buf[278] = (char)(tmp >> 24);  Buf[279] = (char)(tmp >> 16);	Buf[280] = (char)(tmp >> 8);
 Buf[281] = (char)(tmp);

tmp = FreqPCh.Value;
 Buf[282] = (char)(tmp >> 24);  Buf[283] = (char)(tmp >> 16);	Buf[284] = (char)(tmp >> 8);
 Buf[285] = (char)(tmp);

tmp = ModulSK.Value;
 Buf[286] = (char)(tmp >> 24);  Buf[287] = (char)(tmp >> 16);	Buf[288] = (char)(tmp >> 8);
 Buf[289] = (char)(tmp);
#endif

#ifdef PROG_BMDN

tmp = Protect0.Value;
 Buf[290] = (char)(tmp >> 24);  Buf[291] = (char)(tmp >> 16);	Buf[292] = (char)(tmp >> 8);
 Buf[293] = (char)(tmp);

#ifndef PROG_BMDN6MI

tmp = Protect1.Value;
 Buf[294] = (char)(tmp >> 24);  Buf[295] = (char)(tmp >> 16);	Buf[296] = (char)(tmp >> 8);
 Buf[297] = (char)(tmp);

tmp = Protect2.Value;
 Buf[298] = (char)(tmp >> 24);  Buf[299] = (char)(tmp >> 16);	Buf[300] = (char)(tmp >> 8);
 Buf[301] = (char)(tmp);

tmp = Protect3.Value;
 Buf[302] = (char)(tmp >> 24);  Buf[303] = (char)(tmp >> 16);	Buf[304] = (char)(tmp >> 8);
 Buf[305] = (char)(tmp);

tmp = Protect4.Value;
 Buf[306] = (char)(tmp >> 24);  Buf[307] = (char)(tmp >> 16);	Buf[308] = (char)(tmp >> 8);
 Buf[309] = (char)(tmp);

tmp = Protect5.Value;
 Buf[310] = (char)(tmp >> 24);  Buf[311] = (char)(tmp >> 16);	Buf[312] = (char)(tmp >> 8);
 Buf[313] = (char)(tmp);

tmp = Protect6.Value;
 Buf[314] = (char)(tmp >> 24);  Buf[315] = (char)(tmp >> 16);	Buf[316] = (char)(tmp >> 8);
 Buf[317] = (char)(tmp);

tmp = Protect7.Value;
 Buf[318] = (char)(tmp >> 24);  Buf[319] = (char)(tmp >> 16);	Buf[320] = (char)(tmp >> 8);
 Buf[321] = (char)(tmp);

tmp = Protect8.Value;
 Buf[322] = (char)(tmp >> 24);  Buf[323] = (char)(tmp >> 16);	Buf[324] = (char)(tmp >> 8);
 Buf[325] = (char)(tmp);

tmp = Protect9.Value;
 Buf[326] = (char)(tmp >> 24);  Buf[327] = (char)(tmp >> 16);	Buf[328] = (char)(tmp >> 8);
 Buf[329] = (char)(tmp);

tmp = Protect10.Value;
 Buf[330] = (char)(tmp >> 24);  Buf[331] = (char)(tmp >> 16);	Buf[332] = (char)(tmp >> 8);
 Buf[333] = (char)(tmp);

tmp = Protect11.Value;
 Buf[334] = (char)(tmp >> 24);  Buf[335] = (char)(tmp >> 16);	Buf[336] = (char)(tmp >> 8);
 Buf[337] = (char)(tmp);

tmp = Protect12.Value;
 Buf[338] = (char)(tmp >> 24);  Buf[339] = (char)(tmp >> 16);	Buf[340] = (char)(tmp >> 8);
 Buf[341] = (char)(tmp);

tmp = Protect13.Value;
 Buf[342] = (char)(tmp >> 24);  Buf[343] = (char)(tmp >> 16);	Buf[344] = (char)(tmp >> 8);
 Buf[345] = (char)(tmp);

tmp = Protect14.Value;
 Buf[346] = (char)(tmp >> 24);  Buf[347] = (char)(tmp >> 16);	Buf[348] = (char)(tmp >> 8);
 Buf[349] = (char)(tmp);

tmp = Protect15.Value;
 Buf[350] = (char)(tmp >> 24);  Buf[351] = (char)(tmp >> 16);	Buf[352] = (char)(tmp >> 8);
 Buf[353] = (char)(tmp);

tmp = Protect16.Value;
 Buf[354] = (char)(tmp >> 24);  Buf[355] = (char)(tmp >> 16);	Buf[356] = (char)(tmp >> 8);
 Buf[357] = (char)(tmp);

tmp = Protect17.Value;
 Buf[358] = (char)(tmp >> 24);  Buf[359] = (char)(tmp >> 16);	Buf[360] = (char)(tmp >> 8);
 Buf[361] = (char)(tmp);

#endif
#endif

#ifdef HAVE_GATEWAY

tmp = Network.Value;
 Buf[362] = (char)(tmp >> 24);  Buf[363] = (char)(tmp >> 16);	Buf[364] = (char)(tmp >> 8);
 Buf[365] = (char)(tmp);

tmp = NetMask.Value;
 Buf[366] = (char)(tmp >> 24);  Buf[367] = (char)(tmp >> 16);	Buf[368] = (char)(tmp >> 8);
 Buf[369] = (char)(tmp);



#else

tmp = 0x9b9b9b01;
 Buf[362] = (char)(tmp >> 24);  Buf[363] = (char)(tmp >> 16);	Buf[364] = (char)(tmp >> 8);
 Buf[365] = (char)(tmp);

tmp = 0xffff0000;
 Buf[366] = (char)(tmp >> 24);  Buf[367] = (char)(tmp >> 16);	Buf[368] = (char)(tmp >> 8);
 Buf[369] = (char)(tmp);

#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU3
tmp = SymbolRate2.Value;
 Buf[370] = (char)(tmp >> 24);  Buf[371] = (char)(tmp >> 16);	Buf[372] = (char)(tmp >> 8);
 Buf[373] = (char)(tmp);

tmp = FreqPCh2.Value;
 Buf[374] = (char)(tmp >> 24);  Buf[375] = (char)(tmp >> 16);	Buf[376] = (char)(tmp >> 8);
 Buf[377] = (char)(tmp);

tmp = ModulSK2.Value;
 Buf[378] = (char)(tmp >> 24);  Buf[379] = (char)(tmp >> 16);	Buf[380] = (char)(tmp >> 8);
 Buf[381] = (char)(tmp);
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
tmp = SymbolRate2.Value;
 Buf[370] = (char)(tmp >> 24);  Buf[371] = (char)(tmp >> 16);	Buf[372] = (char)(tmp >> 8);
 Buf[373] = (char)(tmp);

tmp = FreqPCh2.Value;
 Buf[374] = (char)(tmp >> 24);  Buf[375] = (char)(tmp >> 16);	Buf[376] = (char)(tmp >> 8);
 Buf[377] = (char)(tmp);

tmp = ModulSK2.Value;
 Buf[378] = (char)(tmp >> 24);  Buf[379] = (char)(tmp >> 16);	Buf[380] = (char)(tmp >> 8);
 Buf[381] = (char)(tmp);
#endif


#ifdef PROG_COMMUTATOR1
   Buf[382] = numa[0]; 	  Buf[383] = numa[1]; 	Buf[384] = numa[2]; 
   Buf[385] = numb[0]; 	  Buf[386] = numb[1]; 	Buf[387] = numb[2]; 
   Buf[388] = numc[0]; 	  Buf[389] = numc[1]; 	Buf[390] = numc[2]; 

   
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
tmp = SymbolRate3.Value;
 Buf[391] = (char)(tmp >> 24);  Buf[392] = (char)(tmp >> 16);	Buf[393] = (char)(tmp >> 8);
 Buf[394] = (char)(tmp);

tmp = FreqPCh3.Value;
 Buf[395] = (char)(tmp >> 24);  Buf[396] = (char)(tmp >> 16);	Buf[397] = (char)(tmp >> 8);
 Buf[398] = (char)(tmp);

tmp = ModulSK3.Value;
 Buf[399] = (char)(tmp >> 24);  Buf[400] = (char)(tmp >> 16);	Buf[401] = (char)(tmp >> 8);
 Buf[402] = (char)(tmp);


tmp = SymbolRate4.Value;
 Buf[403] = (char)(tmp >> 24);  Buf[404] = (char)(tmp >> 16);	Buf[405] = (char)(tmp >> 8);
 Buf[406] = (char)(tmp);

tmp = FreqPCh4.Value;
 Buf[407] = (char)(tmp >> 24);  Buf[408] = (char)(tmp >> 16);	Buf[409] = (char)(tmp >> 8);
 Buf[410] = (char)(tmp);

 tmp = ModulSK4.Value;
 Buf[411] = (char)(tmp >> 24);  Buf[412] = (char)(tmp >> 16);	Buf[413] = (char)(tmp >> 8);
 Buf[414] = (char)(tmp);

 Buf[415] = (char)(test0); Buf[416] = (char)(test1); Buf[417] = (char)(test2);
 Buf[418] = (char)(test3);

 Buf[419] = (char)(decoder0); Buf[420] = (char)(decoder1); Buf[421] = (char)(decoder2);
 Buf[422] = (char)(decoder3);

#endif

#ifdef PROG_PU_MSAT
 tmp = SatSet0.Value;
 Buf[423] = (char)(tmp >> 24);  Buf[424] = (char)(tmp >> 16);	Buf[425] = (char)(tmp >> 8);
 Buf[426] = (char)(tmp);

 tmp = SatSet1.Value *1000l; //to keep digits after point
 Buf[427] = (char)(tmp >> 24);  Buf[428] = (char)(tmp >> 16);	Buf[429] = (char)(tmp >> 8);
 Buf[430] = (char)(tmp);

 tmp = SatSet2.Value * 10;
 Buf[431] = (char)(tmp >> 24);  Buf[432] = (char)(tmp >> 16);	Buf[433] = (char)(tmp >> 8);
 Buf[434] = (char)(tmp);

 stmp = SatSet3.Value;
 Buf[435] = (char)(stmp >> 24);  Buf[436] = (char)(stmp >> 16);	Buf[437] = (char)(stmp >> 8);
 Buf[438] = (char)(stmp);

 tmp = SatSet4.Value;
 Buf[439] = (char)(tmp >> 24);  Buf[440] = (char)(tmp >> 16);	Buf[441] = (char)(tmp >> 8);
 Buf[442] = (char)(tmp);

 tmp = SatSet5.Value;
 Buf[443] = (char)(tmp >> 24);  Buf[444] = (char)(tmp >> 16);	Buf[445] = (char)(tmp >> 8);
 Buf[446] = (char)(tmp);

 tmp = SatSet6.Value;
 Buf[447] = (char)(tmp >> 24);  Buf[448] = (char)(tmp >> 16);	Buf[449] = (char)(tmp >> 8);
 Buf[450] = (char)(tmp);

 tmp = SatSet7.Value;
 Buf[451] = (char)(tmp >> 24);  Buf[452] = (char)(tmp >> 16);	Buf[453] = (char)(tmp >> 8);
 Buf[454] = (char)(tmp);

 tmp = SatTestMode.Value;
 Buf[455] = (char)(tmp);

 tmp = SatPC.Value;
 Buf[456] = (char)(tmp);

tmp = SatTiming.Value;
 Buf[457] = (char)(tmp);

 tmp = SatSet8.Value;
 Buf[458] = (char)(tmp >> 24);  Buf[459] = (char)(tmp >> 16);	Buf[460] = (char)(tmp >> 8);
 Buf[461] = (char)(tmp);

tmp = SatSound.Value;
 Buf[462] = (char)(tmp);


#endif

#ifdef PROG_MD310_SATI	

tmp = SatSound.Value;
 Buf[462] = (char)(tmp);


#endif


#ifdef PROG_BMDN

 tmp = ModEth.Value;
 Buf[463] = (char)(tmp >> 24);  Buf[464] = (char)(tmp >> 16);	Buf[465] = (char)(tmp >> 8);
 Buf[466] = (char)(tmp);

#endif

#ifdef USE_HTTP
 tmp = WebPassword.Value;
 Buf[467] = (char)(tmp >> 24);  Buf[468] = (char)(tmp >> 16);	Buf[469] = (char)(tmp >> 8);
 Buf[470] = (char)(tmp);

#endif

#ifdef PROG_PU_MSAT
tmp = SatDF.Value;
 Buf[471] = (char)(tmp);
tmp = SatTF.Value;
 Buf[472] = (char)(tmp);

tmp = SatRate.Value;
 Buf[473] = (char)(tmp >> 24);  Buf[474] = (char)(tmp >> 16);	Buf[475] = (char)(tmp >> 8);
 Buf[476] = (char)(tmp);

tmp = SatTimer.Value;
 Buf[477] = (char)(tmp >> 24);  Buf[478] = (char)(tmp >> 16);	Buf[479] = (char)(tmp >> 8);
 Buf[480] = (char)(tmp);



#endif

#ifdef PROG_PU_M_V_A
 tmp = AttData.Value;
 Buf[481] = (char)(tmp >> 24);  Buf[482] = (char)(tmp >> 16);	Buf[483] = (char)(tmp >> 8);
 Buf[484] = (char)(tmp);
#endif

 tmp = SOFT_VER;
 Buf[485] = (char)(tmp >> 24);  Buf[486] = (char)(tmp >> 16);	Buf[487] = (char)(tmp >> 8);
 Buf[488] = (char)(tmp);


#ifdef PROG_PU_MSAT
#ifdef RECEIVE_MOD_LOCK

tmp = SatExtLock.Value;
 Buf[489] = (char)(tmp);
// printfpd("\n\rLw:%d", tmp);

tmp = SatExtLockP.Value;
 Buf[490] = (char)(tmp);
//  printfpd("\n\rLw1:%d", tmp);

#endif

tmp = SatLowP.Value;
 Buf[491] = (char)(tmp);

tmp = SatALev.Value;
//printfpd("\n\r SatALev: %d", SatALev.Value);

 Buf[492] = (char)(tmp);

tmp = SatADemo.Value;
 Buf[493] = (char)(tmp);

//printfpd("\n\r SatADemo: %d", SatADemo.Value);


//tmp = SatACode.Value;
tmp = 0; //satacode do not keep
 Buf[494] = (char)(tmp >> 24);  Buf[495] = (char)(tmp >> 16);	Buf[496] = (char)(tmp >> 8);
 Buf[497] = (char)(tmp);




#endif

#ifdef 	PROG_PU_M_MUX
 Buf[498] =	 modforss;
#endif



#ifdef PROG_PU_MSAT	

 Buf[499] = FlagOldSatAlev;// = 0;
 Buf[500] = OldSatAlev; //0;

#endif


 // printfp("\n\r...write");
#ifdef   PROG_MD310_SATI


//______________________________________________________________________
 Buf[501]  =  LoadVariants.Value;
 Buf[502]  =  SaveVariants.Value;
 Buf[503]  =  MRfOut.Value;

 tmp = (unsigned)(MOutLev.Value*(float64)10);

//ok printfpdv(" MOut: % 5.3f",MOutLev.Value);

 Buf[504] = (char)(tmp >> 24);  Buf[505] = (char)(tmp >> 16);	Buf[506] = (char)(tmp >> 8);
 Buf[507] = (char)(tmp);

 tmp = MTFreq.Value * 10000;

 Buf[508] = (char)(tmp >> 24);  Buf[509] = (char)(tmp >> 16);	Buf[510] = (char)(tmp >> 8);
 Buf[511] = (char)(tmp);

// printfpdv("\n\r write rfreq: %5.4f",MRFreq.Value);


 tmp = MRFreq.Value * 10000;

 Buf[512] = (char)(tmp >> 24);  Buf[513] = (char)(tmp >> 16);	Buf[514] = (char)(tmp >> 8);
 Buf[515] = (char)(tmp);

 Buf[516] = MDemod.Value;

 Buf[517] = MEthMode.Value;
// printfpd("\n\r write em %d:", (unsigned)MEthMode.Value);


 Buf[518] = MEthPause.Value;
 Buf[519] = MEthctl.Value;

tmp = MEthMaxF.Value;

 Buf[520] = (char)(tmp >> 24);  Buf[521] = (char)(tmp >> 16);	Buf[522] = (char)(tmp >> 8);
 Buf[523] = (char)(tmp);


tmp = MEthVlanP.Value;

 Buf[524] = (char)(tmp >> 24);  Buf[525] = (char)(tmp >> 16);	Buf[526] = (char)(tmp >> 8);
 Buf[527] = (char)(tmp);

tmp = MTEbN0.Value;

 Buf[528] = (char)(tmp >> 24);  Buf[529] = (char)(tmp >> 16);	Buf[530] = (char)(tmp >> 8);
 Buf[531] = (char)(tmp);

tmp = MTBER.Value;

 Buf[532] = (char)(tmp >> 24);  Buf[533] = (char)(tmp >> 16);	Buf[534] = (char)(tmp >> 8);
 Buf[535] = (char)(tmp);



 Buf[536] = MIfLoop.Value;
 Buf[537] = MUnModul.Value;
 Buf[538] = MACMM.Value;

tmp = MTBERE.Value;

 Buf[539] = (char)(tmp >> 24);  Buf[540] = (char)(tmp >> 16);	Buf[541] = (char)(tmp >> 8);
 Buf[542] = (char)(tmp);

 Buf[543] = MTMode.Value;
 Buf[544] = MRMode.Value;


 Buf[545] = MRCntl.Value;
  //	 printfpd("\n\r write rc %d:", (unsigned)MRCntl.Value);

 tmp = MOutLevO.Value *(float64)1000;

// printfpdv("\n\rwr MOutLevo: % 5.3f",MOutLevO.Value);
// printfpdv("tmpo: % 5.3f",tmp);


 Buf[546] = (char)(tmp >> 24);  Buf[547] = (char)(tmp >> 16);	Buf[548] = (char)(tmp >> 8);
 Buf[549] = (char)(tmp);

 Buf[550] =  MOutLevOS.Value;


 tmp = MKOUT.Value * 10;

//ok printfpdv(" MOut: % 5.3f",MOutLev.Value);

 Buf[551] = (char)(tmp >> 24);  Buf[552] = (char)(tmp >> 16);	Buf[553] = (char)(tmp >> 8);
 Buf[554] = (char)(tmp);


 tmp = MKOUT1.Value;

 Buf[555] = (char)(tmp >> 24);  Buf[556] = (char)(tmp >> 16);	Buf[557] = (char)(tmp >> 8);
 Buf[558] = (char)(tmp);

 tmp = MKIN1.Value;

 Buf[559] = (char)(tmp >> 24);  Buf[560] = (char)(tmp >> 16);	Buf[561] = (char)(tmp >> 8);
 Buf[562] = (char)(tmp);

 tmp = MKIN2.Value;

 Buf[563] = (char)(tmp >> 24);  Buf[564] = (char)(tmp >> 16);	Buf[565] = (char)(tmp >> 8);
 Buf[566] = (char)(tmp);

 tmp = MKIN3.Value;

 Buf[567] = (char)(tmp >> 24);  Buf[568] = (char)(tmp >> 16);	Buf[569] = (char)(tmp >> 8);
 Buf[570] = (char)(tmp);

#ifdef RACM
 Buf[571] = (char)(RACMOnOff.Value);

 //if(start_main_loop) printfpd("\n\rwrite  ratimelock : %d", ratimelock.Value);	
 

 tmp = ratimelock.Value;
 Buf[572] = (char)(tmp >> 24);  Buf[573] = (char)(tmp >> 16);	Buf[574] = (char)(tmp >> 8);
 Buf[575] = (char)(tmp);


// MDataC ratimelock;

 // if(start_main_loop) printfpd("\n\rwrite  ratimemode : %d",  ratimemode.Value);	

//MDataC ratimemode;
 tmp = ratimemode.Value;
 Buf[576] = (char)(tmp >> 24);  Buf[577] = (char)(tmp >> 16);	Buf[578] = (char)(tmp >> 8);
 Buf[579] = (char)(tmp);


  //if(start_main_loop) printfpd("\n\rwrite ratimemse : %d",  ratimemse.Value);	

//MDataC ratimemse;

 tmp = ratimemse.Value;
 Buf[580] = (char)(tmp >> 24);  Buf[581] = (char)(tmp >> 16);	Buf[582] = (char)(tmp >> 8);
 Buf[583] = (char)(tmp);


// if(start_main_loop) printfpd("\n\rwrite ratimestep : %d",  ratimestep.Value);	

//MDataC ratimestep;

 tmp =  ratimestep.Value;
 Buf[584] = (char)(tmp >> 24);  Buf[585] = (char)(tmp >> 16);	Buf[586] = (char)(tmp >> 8);
 Buf[587] = (char)(tmp);



//MDataC uebn[16];	   //64

//if(start_main_loop)    printfp("\n\r  uebn write start  cnt  588");	//768


 tmp =  uebn[0].Value * 10.0;
 Buf[588] = (char)(tmp >> 24);  Buf[589] = (char)(tmp >> 16);	Buf[590] = (char)(tmp >> 8);
 Buf[591] = (char)(tmp);

 cnt = 592;

 
 tmp =  uebn[1].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[2].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 //cnt = 592;

 tmp =  uebn[3].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[4].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[5].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[6].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[7].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[8].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[9].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[10].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[11].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[12].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[13].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[14].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  uebn[15].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

//if(start_main_loop)    printfpd("\n\r  uebn write finish cnt %d", cnt);	//768


//MDataC debn[16];	//64

 tmp =  debn[0].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[1].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[2].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[3].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[4].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[5].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[6].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[7].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[8].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[9].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[10].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[11].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[12].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[13].Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[14].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

 tmp =  debn[15].Value * 10.0;
  Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);

//if(start_main_loop)    printfpd("\n\r  debn write finish cnt %d", cnt);	//768

//MDataV enamode[16];  16

 Buf[cnt++] = (char)(enamode[0].Value);
 Buf[cnt++] = (char)(enamode[1].Value);
 Buf[cnt++] = (char)(enamode[2].Value);
 Buf[cnt++] = (char)(enamode[3].Value);
 Buf[cnt++] = (char)(enamode[4].Value);
 Buf[cnt++] = (char)(enamode[5].Value);
 Buf[cnt++]= (char)(enamode[6].Value);
 Buf[cnt++] = (char)(enamode[7].Value);
 Buf[cnt++] = (char)(enamode[8].Value);
 Buf[cnt++] = (char)(enamode[9].Value);
 Buf[cnt++] = (char)(enamode[10].Value);
 Buf[cnt++] = (char)(enamode[11].Value);
 Buf[cnt++] = (char)(enamode[12].Value);
 Buf[cnt++] = (char)(enamode[13].Value);
 Buf[cnt++] = (char)(enamode[14].Value);
 Buf[cnt++] = (char)(enamode[15].Value);


//MDataV numode[16];	16
Buf[cnt++] = (char)(numode[0].Value);
Buf[cnt++] = (char)(numode[1].Value);
Buf[cnt++] = (char)(numode[2].Value);
Buf[cnt++] = (char)(numode[3].Value);
Buf[cnt++] = (char)(numode[4].Value);
Buf[cnt++] = (char)(numode[5].Value);
Buf[cnt++] = (char)(numode[6].Value);
Buf[cnt++] = (char)(numode[7].Value);
Buf[cnt++] = (char)(numode[8].Value);
Buf[cnt++]= (char)(numode[9].Value);
Buf[cnt++] = (char)(numode[10].Value);
Buf[cnt++] = (char)(numode[11].Value);
Buf[cnt++] = (char)(numode[12].Value);
Buf[cnt++]= (char)(numode[13].Value);
Buf[cnt++] = (char)(numode[14].Value);
Buf[cnt++] = (char)(numode[15].Value);



//MDataV ndmode[16];   16

Buf[cnt++]= (char)(ndmode[0].Value);
Buf[cnt++] = (char)(ndmode[1].Value);
Buf[cnt++] = (char)(ndmode[2].Value);
Buf[cnt++] = (char)(ndmode[3].Value);
Buf[cnt++] = (char)(ndmode[4].Value);
Buf[cnt++]= (char)(ndmode[5].Value);
Buf[cnt++] = (char)(ndmode[6].Value);
Buf[cnt++]= (char)(ndmode[7].Value);
Buf[cnt++] = (char)(ndmode[8].Value);
Buf[cnt++] = (char)(ndmode[9].Value);
Buf[cnt++] = (char)(ndmode[10].Value);
Buf[cnt++] = (char)(ndmode[11].Value);
Buf[cnt++]= (char)(ndmode[12].Value);
Buf[cnt++] = (char)(ndmode[13].Value);
Buf[cnt++] = (char)(ndmode[14].Value);
Buf[cnt++] = (char)(ndmode[15].Value);

Buf[cnt++] = (char)(RACMOnOffT.Value);

 tmp =  RACMOffset.Value * 10.0;
 Buf[cnt++] = (char)(tmp >> 24);  Buf[cnt++] = (char)(tmp >> 16);	Buf[cnt++] = (char)(tmp >> 8);
 Buf[cnt++] = (char)(tmp);





#endif
//cnt = 764; //for enover devices
// if(start_main_loop) printfpd("\n\r cnt = %d", cnt);  // 764
//cnt = 765; 	//(RACMOnOffT
//cnt = 769; 	//(RACMOffset


//______________________________________________________________________


#endif

#ifdef PROG_ODU1
 Buf[769] = ten_mhz;
#endif

#ifdef USE_SOCKETSD

 tmp =  IPAddressUDP.Value;
 Buf[770] = (char)(tmp >> 24);  Buf[771] = (char)(tmp >> 16);	Buf[772] = (char)(tmp >> 8);
 Buf[773] = (char)(tmp);

#endif


//__________________________________________________crc
 Buf[DEV_ID_SIZE - 1] = 0;
 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  Buf[DEV_ID_SIZE - 1] +=  Buf[icrc];
 }
 Buf[DEV_ID_SIZE - 1] += 1;
//__________________________________________________crc

 for(icrc = 0; icrc < (DEV_ID_SIZE); icrc++ )
 {

  Buf1[icrc] =  Buf[icrc];

 }

//150925_int_disable();

 write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE);

//#ifdef PROG_PRM_PCH_L_8  
// return;
//#endif

for(icrc = 0; icrc < (DEV_ID_SIZE); icrc++ )
 {
  Buf[icrc] =  Buf1[icrc];			//restore buff
 }


   if(! CheckDevId(DeviceAddress))
   {

    write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE);
 //	#ifdef MAKET_PLATA	
  //  printfp("\n\rCheckDevId ID_ADDRESS Wrong! ");
 //   #endif
   }
   else
   {
   //  printfp("\n\rCheckDevId ID_ADDRESS Ok! ");

   }

 //printfp("write  ID_ADDRESS3 \n\r");
for(icrc = 0; icrc <(DEV_ID_SIZE); icrc++ )
 {
  Buf[icrc] =  Buf1[icrc];			//restore buff
 //  if(!(icrc %10)) printfp("\n\r");
 // printfpd(" %02X", Buf[icrc]);
  }

  AddressSrc  = (unsigned int)(&Buf1[0]);

 write_dataflash ((unsigned int)ID_ADDRESS3, AddressSrc, DEV_ID_SIZE);

 if(! CheckDevId((unsigned int)ID_ADDRESS3))
   {

 for(icrc = 0; icrc < (DEV_ID_SIZE); icrc++ )
 {
  Buf1[icrc] =  Buf[icrc];	 //restore buff
 }



    write_dataflash ((unsigned int)ID_ADDRESS3, AddressSrc, DEV_ID_SIZE);
 //	#ifdef MAKET_PLATA	
   // printfp("\n\rCheckDevId ID_ADDRESS3 Wrong! ");
   // #endif
   }
     else
   {
   //  printfp("\n\rCheckDevId3 ID_ADDRESS Ok! ");

   }



// write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE + 100);  //t	hangt!!!!
 /*
 delay_mcs(50000l); //wait 50 ms
// printfp("\n\rstart");
 if(! ReadDevId(1))
 {
// printfp("\n\rstart2");
    write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE); //hier need write NOT READED NOW PARAMETERS!
	delay_mcs(50000l); //wait 50 ms

      if(! ReadDevId(1))
      {
//   	  printfp("\n\rstart3");
         write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE);
		 delay_mcs(50000l); //wait 50 ms

	  }
 }

	*/
// OID_ptr = (uchar_ptr)&OID[0];
// sprintf((char *)OID_ptr, "%08X",(uint_32)DevId.Value);
//delay_mcs(50000l); //wait 50 ms
//150925  _int_enable();
}

//________________________________________________________________
extern "C" void WriteDevId2(void)
{
 //printf("\n\rWriteDevId"); //t

//#ifdef TEST_REMOTE_FF
#ifdef MAKET_PLATA	
printfp("\n\rWritedevId2");
#endif
//#endif
//writeid_counter++;

 if((!start_main_loop) || (!read_flag)) return;

 char Buf[DEV_ID_SIZE2];
 unsigned int DeviceAddress = ID_ADDRESS2;
 unsigned int AddressSrc    = (unsigned int)(&Buf[0]);
 unsigned int tmp;

for(unsigned j = 0; j < DEV_ID_SIZE2; j++)
{
  Buf[j] = 0;
}
   
 /*	 it is maked in prm_pch_L
#ifdef 	PROG_PRM_PCH_SPI
 tmp = GetFreqN();
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);
 tmp = GetAttN();
 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);
#endif
 */

#ifdef 	PROG_PRM_PCH_L
 tmp = GetFreq(1);
 Buf[0] = (char)(tmp >> 24);  Buf[1] = (char)(tmp >> 16);	Buf[2] = (char)(tmp >> 8);
 Buf[3] = (char)(tmp);
 tmp = GetFreq(2);
 Buf[4] = (char)(tmp >> 24);  Buf[5] = (char)(tmp >> 16);	Buf[6] = (char)(tmp >> 8);
 Buf[7] = (char)(tmp);
 tmp = GetFreq(3);
 Buf[8] = (char)(tmp >> 24);  Buf[9] = (char)(tmp >> 16);	Buf[10] = (char)(tmp >> 8);
 Buf[11] = (char)(tmp);
 tmp = GetAttRPU(1);
 Buf[12] = (char)(tmp >> 24);  Buf[13] = (char)(tmp >> 16);	Buf[14] = (char)(tmp >> 8);
 Buf[15] = (char)(tmp);
 tmp = GetAttRPU(2);
 Buf[16] = (char)(tmp >> 24);  Buf[17] = (char)(tmp >> 16);	Buf[18] = (char)(tmp >> 8);
 Buf[19] = (char)(tmp);
 tmp = GetAttRPU(3);
 Buf[20] = (char)(tmp >> 24);  Buf[21] = (char)(tmp >> 16);	Buf[22] = (char)(tmp >> 8);
 Buf[23] = (char)(tmp);
 tmp = GetFreq(4);
 Buf[24] = (char)(tmp >> 24);  Buf[25] = (char)(tmp >> 16);	Buf[26] = (char)(tmp >> 8);
 Buf[27] = (char)(tmp);
 tmp = GetFreq(5);
 Buf[28] = (char)(tmp >> 24);  Buf[29] = (char)(tmp >> 16);	Buf[30] = (char)(tmp >> 8);
 Buf[31] = (char)(tmp);
tmp = GetFreq(6);
 Buf[32] = (char)(tmp >> 24);  Buf[33] = (char)(tmp >> 16);	Buf[34] = (char)(tmp >> 8);
 Buf[35] = (char)(tmp);

 tmp = GetAttRPU(4);
 Buf[36] = (char)(tmp >> 24);  Buf[37] = (char)(tmp >> 16);	Buf[38] = (char)(tmp >> 8);
 Buf[39] = (char)(tmp);
// tmp = GetAtt(4);
// Buf[84] = (char)(tmp >> 24);  Buf[85] = (char)(tmp >> 16);	Buf[86] = (char)(tmp >> 8);
// Buf[87] = (char)(tmp);
 tmp = GetAttRPU(5);
 Buf[40] = (char)(tmp >> 24);  Buf[41] = (char)(tmp >> 16);	Buf[42] = (char)(tmp >> 8);
 Buf[43] = (char)(tmp);
// tmp = GetAtt(5);
// Buf[92] = (char)(tmp >> 24);  Buf[93] = (char)(tmp >> 16);	Buf[94] = (char)(tmp >> 8);
// Buf[95] = (char)(tmp);
 tmp = GetAttRPU(6);
 Buf[44] = (char)(tmp >> 24);  Buf[45] = (char)(tmp >> 16);	Buf[46] = (char)(tmp >> 8);
 Buf[47] = (char)(tmp);


  

//48 ...60 - rezerved


#endif //PROG_PRM_PCH_L

#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH 
 tmp = (unsigned int)GetFreqN();
//#ifdef MAKET_PLATA
//  printfpd("\n\rw: %d", tmp);
//#endif

 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);

tmp = GetAtt(1);
 Buf[52] = (char)(tmp >> 24);  Buf[53] = (char)(tmp >> 16);	Buf[54] = (char)(tmp >> 8);
 Buf[55] = (char)(tmp);

tmp = GetAtt2(1);
 Buf[56] = (char)(tmp >> 24);  Buf[57] = (char)(tmp >> 16);	Buf[58] = (char)(tmp >> 8);
 Buf[59] = (char)(tmp);


#endif




#ifdef	 PROG_PRM_PCH_SPI_XIL
#ifndef   PROG_PRM_PCH_SPI_XIL_ETH 

 tmp = (unsigned int)GetFreqN();
//#ifdef MAKET_PLATA
//  printfpd("\n\rw: %d", tmp);
//#endif

 Buf[48] = (char)(tmp >> 24);  Buf[49] = (char)(tmp >> 16);	Buf[50] = (char)(tmp >> 8);
 Buf[51] = (char)(tmp);

tmp = GetAtt(1);
 Buf[52] = (char)(tmp >> 24);  Buf[53] = (char)(tmp >> 16);	Buf[54] = (char)(tmp >> 8);
 Buf[55] = (char)(tmp);

tmp = GetAtt2(1);
 Buf[56] = (char)(tmp >> 24);  Buf[57] = (char)(tmp >> 16);	Buf[58] = (char)(tmp >> 8);
 Buf[59] = (char)(tmp);

#endif
#endif


   

 tmp = SOFT_VER;
 Buf[60] = (char)(tmp >> 24);  Buf[61] = (char)(tmp >> 16);	Buf[62] = (char)(tmp >> 8);
 Buf[63] = (char)(tmp);


#ifdef PROG_PRM_PCH_L_61 
#ifndef PROG_PUPM2 
#ifndef	 PROG_PRM_PCH_SPI_NOXIL_ETH 
#ifndef	 PROG_PRM_PCH_SPI_XIL_ETH 
 Buf[64] = SourcePCH;
#endif
#endif
#endif
#endif

#ifdef 	PROG_PD3

 Buf[65] = freqpd >> 8;
 Buf[66] = freqpd;
 Buf[67] =  attpd;

#endif

  #ifdef	 PROG_PRM_PCH_SPI_ETH_UART 

Buf[68] =  prm_inp;
Buf[69] =  Filtr;


#endif


//__________________________________________________crc
 Buf[DEV_ID_SIZE2 - 1] = 0;
 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE2 - 1); icrc++ )
 {
  Buf[DEV_ID_SIZE2 - 1] +=  Buf[icrc];
 }
 Buf[DEV_ID_SIZE2 - 1] += 1;
//__________________________________________________crc

 write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE2);
 /*
 delay_mcs(50000l); //wait 50 ms
// printfp("\n\rstart");
 if(! ReadDevId(1))
 {
// printfp("\n\rstart2");
    write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE); //hier need write NOT READED NOW PARAMETERS!
	delay_mcs(50000l); //wait 50 ms

      if(! ReadDevId(1))
      {
//   	  printfp("\n\rstart3");
         write_dataflash (DeviceAddress, AddressSrc, DEV_ID_SIZE);
		 delay_mcs(50000l); //wait 50 ms

	  }
 }

	*/
// OID_ptr = (uchar_ptr)&OID[0];
// sprintf((char *)OID_ptr, "%08X",(uint_32)DevId.Value);
//delay_mcs(50000l); //wait 50 ms
}


//________________________________________________________________


//#ifdef IncEmbIndicator



extern "C" AnyStrings::Init()
	{

  		strcpy(cLogoLd,    "    SNMP Controller     ");
	#ifdef PROG_MF20
   #ifndef PROG_BACO
		 strcpy(cLogoLd,   "         MF-20          ");
#else
     #ifndef PROG_BACOD
		 strcpy(cLogoLd,   "       B A C O          ");
	 #else
		 strcpy(cLogoLd,   "   B A C O - D M U      ");

     #endif

	#endif
	#endif // PROG_MF20

	#ifdef PROG_TUTS
		 strcpy(cLogoLd,   "         TUTS           ");
	#endif // PROG_TUTS

	#ifdef PROG_KTVM
		 strcpy(cLogoLd,   "         KTVM           ");
	#endif // PROG_KTVM

	#ifdef PROG_DTVM
		 strcpy(cLogoLd,   "         DTVM           ");
	#endif // PROG_DTVM



   #ifdef PROG_BMD34

   		#ifdef PROG_BMD2
		 strcpy(cLogoLd,   "         BMD-2          ");
		#else // PROG_BMD2
 		#ifdef PROG_BMD34PS
		 strcpy(cLogoLd,   "         BMD-34PS       ");
		#else // PROG_BMD34PS
  		 strcpy(cLogoLd,   "         BMD-34         ");
   		#endif	//no PROG_BMD34PS
	  	#endif	//no PROG_BMD2

	#endif // PROG_BMD34

 #ifdef PROG_BMD35
   	   	 strcpy(cLogoLd,   "         BMD-35         ");
 #endif // PROG_BMD35

 #ifdef PROG_PROV
   	   	 strcpy(cLogoLd,   "       PROVINGENT       ");
 #endif // PROG_PROV


#ifdef PROG_MPC35
   	   	 strcpy(cLogoLd,   "         MPC-35         ");
 #endif // PROG_MPC35



    #ifdef PROG_MPC155
		 strcpy(cLogoLd,   "         MPC-155        ");
	#endif // PROG_MPC155

    #ifdef PROG_MPC4E
		 strcpy(cLogoLd,   "         MPC-4E         ");
	#endif // PROG_MPC4E

  
#ifdef PROG_BMDN
#ifndef PROG_BMDN5 
	  strcpy(cLogoLd,      "         BMND-N         ");
#else
#ifndef PROG_BMDN6 
	  strcpy(cLogoLd,      "         ACT155051      ");
#else

#ifndef PROG_MD310
#ifndef PROG_MD310_SAT
#ifndef PROG_BMDN6M 
	  strcpy(cLogoLd,      "         ACT155052      ");
#else //6M
	    strcpy(cLogoLd,      "         MD310E         "); //6M : imitate md310

#endif
#else
//	  strcpy(cLogoLd,      "       S A T-155052     ");
#ifndef PROG_MD310_SATI2
	  strcpy(cLogoLd,       "         MD100SE-1      ");
#else

//#ifndef PROG_ODU
#ifndef PROG_ODU1
#ifndef PROG_DMU6

	   strcpy(cLogoLd,      "         MD100SE-2      ");
#else
        strcpy(cLogoLd,      "         DMU-6          ");
#endif

#else

#ifndef PROG_ODU4
       strcpy(cLogoLd,       "          RMB-1         ");
#else
       strcpy(cLogoLd,       "          RMBA-1         ");
#endif



#endif


#endif
#endif
#else
	  strcpy(cLogoLd,      "         MD310E         ");

#endif //md310
#endif //bmdn6
#endif //bmdn5
#endif // PROG_BMDN

#ifdef PROG_COMMUTATOR
		 strcpy(cLogoLd,   "       COMMUTATOR       ");
#endif

#ifdef PROG_BMD155
#ifdef PROG_ACT155
		 strcpy(cLogoLd,   "         ACT-155        ");
#else	 //PROG_ACT155
#ifdef PROG_ACT155N
		 strcpy(cLogoLd,   "         ACT-155N       ");
#else // 
#ifdef PROG_BMD155PS
		 strcpy(cLogoLd,   "         BMD-155PS      ");
#else // 
		 strcpy(cLogoLd,   "         BMD-155        ");
#endif
#endif // PROG_BMD155PS
#endif	//PROG_ACT155
#endif // PROG_BMD155

#ifdef PROG_MPC34
   
		 strcpy(cLogoLd,   "         MPC-34         ");
#endif // PROG_MPC34

#ifdef PROG_BUKC
		 strcpy(cLogoLd,   "         BUK-C          ");
#endif // PROG_BUKC

#ifdef PROG_PRM_PCH_DEM
#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU3
		 strcpy(cLogoLd,   "         DMU3           ");
#else
#ifndef PROG_PRM_PCH_DEM_XIL_CHN_DMU5
		 strcpy(cLogoLd,   "         DMU4           ");
#else
#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU5
#ifndef PROG_DMU6
		 strcpy(cLogoLd,   "         DMU5           ");
#else
    	  strcpy(cLogoLd,   "         DMU5.1         ");

#endif
#else

	    strcpy(cLogoLd,   "         PRM-PCH-DEM    ");
#endif
#endif //PROG_PRM_PCH_DEM
#endif
#endif


#ifdef PROG_PRM_PCH
	   strcpy(cLogoLd,   "         PRM-PCH        ");
#ifdef PROG_PRM_PCH_C

#ifdef PROG_PRM_PCH_S
#ifndef PROG_PRM_PCH_L
		 strcpy(cLogoLd,   "         PRM-PCH-S      ");
#else  // PROG_PRM_PCH_L
#ifndef PROG_PRM_PCH_N
#ifndef PROG_PRM_PCH_L_6
//#ifndef PROG_PUPM2
		 strcpy(cLogoLd,   "         PRM-PCH-L      ");
#else
#ifndef PROG_PUPM3
#ifndef PROG_PRM_PCH_L_8

		 strcpy(cLogoLd,   "        PRM-PCH-L-6     ");
#else
		 strcpy(cLogoLd,   "        PRM-PCH-L-8     ");

#endif
#else
	    strcpy(cLogoLd,   "         PUPM-3         ");
#endif
#ifdef PROG_PRM_PCH_SPI

#ifndef	PROG_PRM_PCH_SPI_XIL_ETH
		 strcpy(cLogoLd,   "        PRM-PCH-SPI     ");
#else
		 strcpy(cLogoLd,   "  PRM-PCH-SPI-XIL-ETH   ");
#endif
#ifdef	PROG_PRM_PCH_SPI_NOXIL_ETH
#ifndef PROG_PD3
#ifndef	PROG_PRM_PCH_SPI_ETH_UART

		 strcpy(cLogoLd,   " PRM-PCH-SPI-NOXIL-ETH  ");
#else
		  strcpy(cLogoLd,   " PRM-PCH-SPI-ETH-UART   ");


#endif




#else
		 strcpy(cLogoLd,   "           PD3          ");

#endif
#endif
#endif

#ifdef PROG_PRM_PCH_SPI_STEND
		 strcpy(cLogoLd,   "      PRM-PCH-SPI-STEND ");
#endif



//  		 strcpy(cLogoLd,   "      PRM-PCH-L-6-100   ");	   //110623
#endif	 //prm-pch-l-6

#else	// PROG_PRM_PCH_N
		  strcpy(cLogoLd,   "         PRM-PCH-N      ");

#ifdef PROG_PRM_PCH_N_3_NOV
		  strcpy(cLogoLd,   "       PRM-PCH-N-NOV  ");

#endif

#ifdef PROG_PRM_PCH_N_3_FSB
		 strcpy(cLogoLd,   "       PRM-PCH-N-F    ");

#endif



   //		 strcpy(cLogoLd,   "         PRM-PCH-N      ");
#endif 	 // PROG_PRM_PCH_N
#endif // PROG_PRM_PCH_L
#else  // PROG_PRM_PCH_S
		 strcpy(cLogoLd,   "         PRM-PCH-C      ");
#endif // PROG_PRM_PCH_S




#else  // PROG_PRM_PCH_C
		 strcpy(cLogoLd,   "         PRM-PCH        ");

#endif //PROG_PRM_PCH_C

#endif // PROG_PRM_PCH

#ifdef PROG_PUPM2

#ifndef PROG_PUPM3_1
		 strcpy(cLogoLd,   "         PU-PM-2        ");
#else
		  strcpy(cLogoLd,   "        PU-PM-3        ");

#endif		 
#endif



#ifdef PROG_PU_M
#ifndef PROG_PU_M710
		 strcpy(cLogoLd,   "         PU-M           ");
#else
		 strcpy(cLogoLd,   "         MD-34E         ");

#endif
#endif // PROG_PU_M

#ifdef PROG_PU_M100
		 strcpy(cLogoLd,   "         PU-M100        ");
#endif // PROG_PU_M100

#ifdef PROG_PU_MSAT
	  //	 strcpy(cLogoLd,   " PU-MSAT                ");
#ifndef PROG_PU_MSAT1
		 strcpy(cLogoLd,   "SBSL-LinkDoubler1       ");
#else
#ifndef PROG_PU_MSAT3
#ifndef PROG_PU_MSAT4

		 strcpy(cLogoLd,   "SBSL-LinkDoubler2       ");
#else
//#ifndef PROG_PU_MSAT4

		 strcpy(cLogoLd,   "SBSL-LinkDoubler4       ");

#endif

#else
 		  strcpy(cLogoLd,   "SBSL-LinkDoubler3       ");

//#endif

#endif
#endif

//		 strcpy(cLogoLd1,  "        PU-MSAT         ");
 strcpy(cLogoLd1,  "        SBSL-100        ");


#endif // PROG_PU_M100


#ifdef PROG_PU_M_MUX
		 strcpy(cLogoLd,   "         PU-M-MUX       ");
#endif // PROG_PUM

#ifdef PROG_PU_M_V
#ifdef PROG_COMMUTATOR1
		 strcpy(cLogoLd,   "       COMMUTATOR1      ");
#else

		 strcpy(cLogoLd,   "         PU-M-V         ");
#endif
#endif // PROG_PUM

#ifdef PROG_PU_M_V_A
		 strcpy(cLogoLd,   "        PU-M-V-A        ");
#endif // PROG_PUM


#ifdef PROG_UPS
#ifdef PROG_UPS1
		 strcpy(cLogoLd,   "         UPS1           ");
#else
		 strcpy(cLogoLd,   "         UPS            ");
#endif
#endif // PROG_UPS




#ifdef PROG_BUKU
		 strcpy(cLogoLd,   "         BUK-U          ");
#endif // PROG_BUKU

#ifdef PROG_PUM
		 strcpy(cLogoLd,   "          PUM           ");
#endif // PROG_PUM






		strcpy(cVersion,    SOFT_VER_STRING);
   		strcpy(cConfig,    "        System          ");
 		strcpy(cIPAddrU,   "      IP Address:       ");
		strcpy(cIPAddrL,   "       .   .   .        ");

#ifdef HAVE_GATEWAY
     	strcpy(cNetwork,   "    Default Gateway:    ");
   		strcpy(cNetMask,   "      Subnet Mask:      ");
   		strcpy(cNetMaskL,  "        .  .  .         ");
#endif

		strcpy(cAddrRS485, "    Address for UART:   ");
		strcpy(cId       , "    Devise ID :         ");
		strcpy(cVer		 , "Year:      Ver:    .    ");
		strcpy(cTestMode,  " System Test Mode :     ");
		strcpy(cPOK,       " Programm OK:           ");
   		strcpy(cmes0,      "        THIS VALUE      ");
		strcpy(cmes1,      "      IS NOT ALLOWED    ");
		strcpy(cMACAddress,"     MAC Address:       ");
		strcpy(cXilinxFile,"      FPGA ver:         ");
		strcpy(cFirmware,  "    Firmware ver:       ");
		strcpy(cIFmodule,  "    IF Module ver:      ");


#ifdef CLOCK_ENABLED
   		strcpy(cDate,	   "         Date:          ");
		strcpy(cTime,      "         Time:          ");
#endif

#ifdef	PROG_MD310_SATI
		strcpy(cSClear,  	 "   Clear Statistics     ");

		strcpy(cSatSound,    "        Alarm:          ");
		strcpy(cSatSoundV,  	   "OFFON ");

		strcpy(cSatSystem ,    "     Configuration      ");

		strcpy(cSatIndication , "   Monitoring  Modem    ");
		strcpy(cSatIndicationE ,"  Monitoring  Ethernet  ");
		strcpy(cEthMode ,"Ethernet Mode:          ");
		strcpy(cEthStat ,"   Ethernet Statistics  ");
		strcpy(cEthSend ,"M Frames:               ");
	//trcpy(cEthReceive ,   " Received:              ");

		strcpy(cEthSendU ,     " Dropped Mod:           ");
		strcpy(cEthRcvD ,      " Dropped Dem:           ");

		strcpy(cEthReceive ,   "Rx Eth:                 ");
		strcpy(cEthTransmit ,  "Tx Eth:                 ");



		strcpy(cEthReceiveCRC ,"Rx Eth CRC Err:         ");



		strcpy(cModTest ,	"         Test           ");
		strcpy(cModIFLoop,	" IF Loop :              ");
		strcpy(cModUnmodul ," Unmodulated:           ");


//		strcpy(cMonEBN ,  "  Eb/N0:                ");
		strcpy(cMonEBN ,  "Eb/N0:      BER:    e-  ");
		strcpy(cMonTREBN ,"Threshold Eb/N0:      dB");
//		strcpy(cMonBER ,  "  BER:                  ");
	 //	strcpy(cMonBER ,  "RLEV     dBmdF       kHz");
		strcpy(cMonBER ,  "RL     dBm  dF       kHz");
		strcpy(cMonTRBER ,"Threshold BER:      e-  ");
		strcpy(cMonAGC ,  "  AGC:                  ");
		strcpy(cMonSweep ,"  Sweep:                ");

		strcpy(cSatLog ,     "          Log           ");
		strcpy(cModulator,   "     Modulator Conf     ");
		strcpy(cRfOutput,    "  Rf Output:            ");
		strcpy(cTxOutLevel,  "Output Level:-       dBm");
//		strcpy(cTxOutLevelO, "Out Lev Offset:      dBm");
//		strcpy(cTxOutLevelK, "Out Lev @:              ");

		strcpy(cTxOutLevelO, "Transmitter calibration:");
		strcpy(cTxOutLevelK, "  Receiver calibration: ");



//		strcpy(cTxMode, 	 "   Transmitter Mode:    ");
//		strcpy(cTxMode, 	 "Transmit Mode:          ");
		strcpy(cTxMode, 	 "#                       ");


		strcpy(cTxModul,     "TxModType:              ");
		strcpy(cTxModulI,    "Mod#                    ");
		strcpy(cTxCodeRate,  "TxCodeRate:             ");
  //		strcpy(cTxDataRate,  "TxSRate:            Msps");
	 //strcpy(cTxDataRate,  "    Msps                ");
		strcpy(cTxFreq,      "TxFreq:              MHz");

		strcpy(cDemodulator, "   Demodulator Conf     ");
		strcpy(cRxMode, 	 "Receiver Mode:          ");
		strcpy(cRxModul,     "RxModType:              ");
		strcpy(cRxModulI,    "Dem#                    ");
		strcpy(cRxCodeRate,  "RxCodeRate:             ");
	 //	strcpy(cRxDataRate,  "RxSRate:            Msps");
		strcpy(cRxDataRate,  "    Msps ALP     DFE    ");
		strcpy(cTxDataRate,  "    Msps ALP            ");


		strcpy(cRxFreq,      "RxFreq:              MHz");
		strcpy(cRxOnOff,     "Demodulator:            ");	//on/off



		strcpy(cCommon,      "       Modem Conf       ");
   //		strcpy(cModTest,      "      Test Conf         ");

		strcpy(cModInterface,      "      Ethernet Conf     ");
		strcpy(cInterfaceMode,     "    Mode:               ");
		strcpy(cInterfacePause,    "    Pause:              ");
		strcpy(cInterfaceInBand,   "   InBand Contrl:       ");
		strcpy(cInterfaceMaxFrame, "   MaxFrame:            ");
		strcpy(cInterfaceVLANP,    "VLAN Priority Mask:     ");
		strcpy(cInterfaceRate,    "Rate:                kb/s");
		#ifdef PROG_MD310_SATI2
		 strcpy(cInterfaceRate,   "RateM:              kb/s");
		 strcpy(cInterfaceRateD,  "RateD:              kb/s");
		#endif


		strcpy(cSaveLoad,    "       SAVE/LOAD        ");
		strcpy(cSave,         "      Save# :           ");
		strcpy(cLoad,         "      Load# :           ");






		strcpy(cModConfigFile, "     Config File :      ");


#ifdef PROG_MD310_SATI2	
	strcpy(cMdConfigFile, "Md Cfg#             Msps");

	strcpy(cDmConfigFile, "Dm Cfg#             Msps");

#endif


		for(unsigned ci = 0; ci < (NAMES_LEN * MAX_NUM_CFG - 2);ci++)
		{
		  cNamesConfigFilesV[ci] = ' ';
		}
		cNamesConfigFilesV[NAMES_LEN * MAX_NUM_CFG - 1] = 0;
			 
		for( ci = 0; ci < (PARAMS_LEN * MAX_NUM_CFG - 2);ci++)
		{
		  cParamsConfigFilesV[ci] = ' ';
		}
		cParamsConfigFilesV[PARAMS_LEN * MAX_NUM_CFG - 1] = 0;
			
#endif

#ifdef PROG_PU_MSAT
		strcpy(cSatSystem ,"     Configuration      ");
		strcpy(cSatIndication ,"       Indication       ");
		strcpy(cSatLog ,   "          Log           ");
//		strcpy(cSatSet0   ,"  Min Distance  :       ");
		strcpy(cSatSet0   ,"Processing Freq (Hz):   ");
 //		strcpy(cSatSet1   ,"  Max Distance  :       ");
 		strcpy(cSatSet1   ,"  System Delay (ms):    ");
		strcpy(cSatSet2   ,"  Output Level (dbm):   ");
  //140227		strcpy(cSatSet3   ,"       Debug Keys:      ");
		strcpy(cSatSet3   ,"      Slave Level:      ");


		strcpy(cSatSet4   ,"Transmit Freq (kHz):    ");
		strcpy(cSatSet5   ,"Receive Freq (kHz):     ");
//130409		strcpy(cSatSet6   ,"  Transmit Bound (MHz): ");
		strcpy(cSatSet6   ,"   Analog Filter (MHz): "); //130409
		strcpy(cSatSet7   ,"  Receive Bound (MHz):  ");
		strcpy(cSatSet8   ,"Processing Offset (kHz):");
	//	strcpy(cSatGet0   ,"  Buffer Fill   :       ");
		strcpy(cSatGet0   ,"  Buffer Fill   :       ");
		strcpy(cSatGet1   ," Frequency Offset (kHz):");
  //		strcpy(cSatGet2   ,"  Input Signal  :       ");
  //		strcpy(cSatGet3   ,"      Lock      :       ");
  //		strcpy(cSatGet4   ,"      Sweep     :       ");
		strcpy(cSatGet2   ,"   Channel Delay (ms):  ");
#ifdef PROG_PU_MSAT1
  	    strcpy(cSatGet8   ,"                    (  )");
#endif

		strcpy(cSatGet3   ,"    IF-Balance (dB):    ");
		strcpy(cSatGet4   ,  "       SatGet4  :       ");

		strcpy(cSatGet5   ,  "     SatGet5    :       ");
		strcpy(cSatGet6   ,  "     SatGet6    :       ");
		strcpy(cSatGet7     ,"     SatGet7    :       ");
		strcpy(cSatTestMode, "       Test Mode:       ");
 		strcpy(cSatTiming,   "      UPLink Mode:      ");
		strcpy(cSatSound,    "        Alarm:          ");
		strcpy(cSatFactory,  "    Factory setting:    ");
		strcpy(cSatDF,       "  Digital Filter (kHz): ");
		strcpy(cSatTF,       "       Time Frame:      ");
		strcpy(cSatRate,     "     Symbol Rate (kHz): ");

	    strcpy(cSatTimer,    "       Unlock Timer     ");



		strcpy(cCusDet,      "     Custom Details     ");




		strcpy(cSatPC,	     "   Debug mode:          ");

#ifdef RECEIVE_MOD_LOCK

		strcpy(cSatExtLockV,    "No Yes");
		strcpy(cSatExtLockPV,	"10");
		strcpy(cSatExtLock,     "     External Lock      ");
   		strcpy(cSatExtLockP,    " External Lock Polarity ");



#endif

	   strcpy(cSatLowPV,        "No Yes");
	   strcpy(cSatLowP,         "        Low Power       ");


  	   strcpy(cSatALevV,        "5  MSb/s15 MSb/s50 MSb/s");
	   strcpy(cSatALev,         "     Access Level        ");


   	   strcpy(cSatADemoV,        "OFFON ");
	   strcpy(cSatADemo,         " Demo Mode :             ");


  	   strcpy(cSatACode,         "      Access Code        ");





		strcpy(cSatInput,	 "     IF Down Link:      "); //	Input
		strcpy(cSatLock,	 "         Lock:          ");
		strcpy(cSatSearch,	 "      IF Up Link:       ");  //	Search


		strcpy(cSatTestModeV,	   "OFFON ");
	  //	strcpy(cSatTestModeIV,	   " T");
#ifndef LINE_LOCK
		strcpy(cSatTestModeIV,	   "M MTS ST");
#else
  //	   strcpy(cSatTestModeIV,	   "M +MT+S +ST+M -MT-S -ST-M  MT S  ST M  MT S  ST ");
		    strcpy(cSatTestModeIV,	   "M  MT S  ST M  MT S  ST M -MT-S -ST-M +MT+S +ST+");

#endif

		strcpy(cSatTimingV,  	   "MasterSlave ");

	strcpy(cSatSoundV,  	   "OFFON ");


	strcpy(cSatFactoryV,  	   "No Yes");
 //	strcpy(cSatDFV,"10 20 30 40 50 56 65 80 100130200400OFF");	//len :3*13+1 = 40
	strcpy(cSatDFV,"OFF10 20 30 40 50 56 65 80 100130200400");	//len :3*13+1 = 40
//	strcpy(cSatTFV,"0,160,330,490,660,820,981,181,311,471,641,801,972,142,292,462,62");	//len : 16*4 + 1 = 65
#ifndef 	PROG_PU_MSAT1
	strcpy(cSatTFV,"0,16ms => 25km 0,33ms => 48km 0,49ms => 73km 0,66ms => 99km 0,82ms => 123km0,98ms => 147km1,18ms => 177km1,31ms => 196km1,47ms => 220km1,64ms => 246km1,80ms => 270km1,97ms => 295km2,14ms => 321km2,29ms => 343km2,46ms => 369km2,62ms => 392km");	//len : 16*15 + 1 = 241
#else
	strcpy(cSatTFV,"0,33ms => 48km 0,49ms => 73km 0,66ms => 99km 0,82ms => 123km0,98ms => 147km1,18ms => 177km1,31ms => 196km1,47ms => 220km1,64ms => 246km1,80ms => 270km1,97ms => 295km2,14ms => 321km2,29ms => 343km2,46ms => 369km2,62ms => 392km4,70ms => 705km");	//len : 16*15 + 1 = 241
#endif

		strcpy(cSatPCV,	   		   "OFFON ");
//		strcpy(cSatInputV,	 "OffOn ");
//		strcpy(cSatInputV,	 "Available   Lost   ");
    	strcpy(cSatInputV,	 "  Lost   Available");

		strcpy(cSatLockV,	 "UNLOCKLOCK  ");
		strcpy(cSatSearchV,	 "OFFON ");
		strcpy(cSatXilBlockV,	 " B");



#endif

		strcpy(cMACData,   "           -            ");
 		strcpy(cGetCom,    " Get The Command");
   //t		strcpy(cEmpty,     "                ");
		strcpy(cEmpty,     "                        ");
		strcpy(cTimed,     "         :    :         ");
		strcpy(cDated,     "    d:   m:   y:        ");
		strcpy(cMinus,     "         -              ");
		strcpy(cCommands,  "StartStop Clear");
		strcpy(cInsBers,   "None 10^-110^-210^-310^-410^-510^-610^-7");
		strcpy(cCommandF,  "%5s");
		strcpy(cCommandP,  "%6s");
		strcpy(cPhase,   "NormalInvert");
		strcpy(c87,   "87");
		strcpy(cNEO,   "NEO");
		strcpy(cInType,  "  LVDS     RS449    TTL    RS449-TTL");
		strcpy(cPatType, " alt 0s 1s  2 in 3    2^3-1     2^4-1     2^7-1     2^9-1     2^11-1    2^15-1 O  2^15-1 M  2^32-1  ");		
	  		strcpy(cVolume,    "%.4LE");
		strcpy(cVCC18,    "%.2Lf");
		strcpy(cBits,      "Bits:           ");
		strcpy(cmRemote,   "R:       B:  P: ");
		strcpy(cRemote,    "     Remote     ");
		strcpy(cBer,       "BER:            ");
		strcpy(cErr,       "Err:            ");
		strcpy(cLoss,      "Loss:           ");
		strcpy(cLoop,      "   Loop:        ");
		strcpy(cClocks,    "     Clocks     ");
		strcpy(cTest,      "      Test      ");
		strcpy(cInterface, "   Interface    ");
		strcpy(cMonitoring,"   Monitoring   ");	
		strcpy(cMonitoringVCC18,"VCC 1,8V:       ");	
		strcpy(cmInType,   "Interface Type  ");
		strcpy(cmPatType,  " Pattern  Type  ");
		strcpy(cmSynce,    "     Synce      ");
		strcpy(cmAutoSynce,"Autoresync:     ");
		strcpy(cOffOn,	   "OffOn ");
#ifdef PROG_DTVM
		strcpy(cRateData,	   "3E14E1");
		strcpy(cRemRateData,   "C6");
		strcpy(cVideoData,	   "PAL  SECAMY/C  ");
		strcpy(cRemVideoData,  "C7");
		strcpy(cTestSignalData,	   "ÂûêëBARSL1  L2  L3  L4  ");
		strcpy(cRemTestSignalData,  "C8");
		strcpy(cSoundData,	   "2Ìîíî4Ìîíî");
		strcpy(cRemSoundData,  "C9");
		strcpy(cRemStateData,  "CA");
		strcpy(cRemErrData,    "CB");
		strcpy(cRemPointData,   "CC");
		strcpy(cRemAddrData,    "CD");
	  

#endif //PROG_DTVM

#ifdef PROG_KTVM
		strcpy(cRateData,	   "3E14E1");
		strcpy(cRemRateData,   "C6");
		strcpy(cVideoData,	   "1  2  Y/C");
		strcpy(cRemVideoData,  "C7");
		strcpy(cTestSignalData,	   "ÂûêëBARSL1  L2  L3  L4  ");
		strcpy(cRemTestSignalData,  "C8");
		strcpy(cSoundData,	   "2Ìîíî4Ìîíî");
		strcpy(cRemSoundData,  "C9");
		strcpy(cRemStateData,  "CA");
	//	strcpy(cRemErrData,    "CB");
		strcpy(cRemPointData,   "CC");
		strcpy(cRemAddrData,    "CD");
	   
#endif //PROG_KTVM

#ifdef IncEmbIndicator

	  strcpy(cRemKeyData,    "CE");
	  strcpy(cRemIndData0,   "CF");
	  strcpy(cRemIndData1,   "CG");

//	  strcpy(cRemCurData,    "CH");
	  strcpy(cRemCurData,    "Ch");

	  strcpy(cRemLedData,    "CI");

#endif //IncEmbIndicator

#ifdef PROG_BMD35
	   		strcpy(cRemoteMode,	   "CJ");
#endif //PROG_BMD35

#ifdef PROG_MPC35
	   		strcpy(cRemoteMode,	   "CJ");
#endif //PROG_MPC35

#ifdef KTVM_PROT2
	   		strcpy(cRemoteMode,	   "CJ");
#endif //PROG_MPC35



		strcpy(cLockMode,	   "CH");

#ifdef TRAP_ENABLED
	   strcpy(cTrapTimer,	   "CL");
	   strcpy(cTrapIp,	   	   "CM");
#endif // TRAP_ENABLED

#ifdef CLOCK_ENABLED
	    strcpy(cTimeData1, 	   "CN");
	    strcpy(cTimeData2, 	   "CO");
	    strcpy(cTimeData3, 	   "CP");
	    strcpy(cTimeData4, 	   "CQ");
	    strcpy(cTimeData5, 	   "CR");
	    strcpy(cTimeData6, 	   "CS");
#endif //CLOCK_ENABLED

#ifdef YOURNAL
         strcpy(cCRecord, 	   "CT");
strcpy(cLogClearV,  	   "No Yes");
strcpy(cLogClear,  	   "        Clear Log:      ");

#endif // YOURNAL

#ifdef PROG_BMDN
		strcpy(cConfigFile,    "CU");
		strcpy(cConfigFile1,    "E1");
		strcpy(cConfigFile2,    "E2");
		strcpy(cConfigFile3,    "E3");
		strcpy(cConfigFile4,    "E4");
		strcpy(cConfigFile5,    "E5");
		strcpy(cConfigFile6,    "E6");
		strcpy(cConfigFile7,    "E7");
//___________________________________________________8 modems
		strcpy(cConfigFile8,    "E8");
//___________________________________________________9 modems
		strcpy(cConfigFile9,    "E9");
		strcpy(cConfigFile10,    "EA");
		strcpy(cConfigFile11,    "EB");
		strcpy(cConfigFile12,    "EC");
		strcpy(cConfigFile13,    "ED");
		strcpy(cConfigFile14,    "EE");
		strcpy(cConfigFile15,    "EF");
		strcpy(cModForSS,    	 "EH");

#endif //PROG_BMDN




		strcpy(cRt       , "    RT:         ");
		strcpy(cRd       , "    RD:         ");
		strcpy(cTt       , "    TT:         ");
		strcpy(cSd       , "    SD:         ");
		strcpy(cmTiming  , " Mode:          ");
		strcpy(cTiming  , "Slave Master");
		strcpy(cInsBer,    "Inserted:       ");
		strcpy(cTrClocks,  " Transmit Clocks");	
		strcpy(cHz,        "              Hz");	
		strcpy(cFclkf,     "%11.1f");	
//		strcpy(cFclk,      "%8ld");	
		strcpy(cFclk,      "%08ld");	
		strcpy(cRem,      "%6ld");	
		strcpy(cRemVol,	   "B2");
		strcpy(cRemErr,	   "B3");
		strcpy(cRemBer,	   "B1");
		strcpy(cRemLoss,   "B5");	
		strcpy(cRemLEDData,"B7");
		strcpy(cRemIP	  ,"B8");
		strcpy(cRemIP3	  ,"B9");	
		strcpy(cRemIP2	  ,"BA");
		strcpy(cRemIP1	  ,"BB");
		strcpy(cRemIP0	  ,"BC");
		strcpy(cRemUARTAddr,"BD");	
		strcpy(cRemId      ,"BE");	
		strcpy(cRemYear    ,"BF");
		strcpy(cRemVer     ,"BG");
		strcpy(cRemVer2    ,"BS");
		strcpy(cRemTestMode,"BH");	
		strcpy(cRemPOK,		"BI");
		strcpy(cRemMf20Data,"BJ");	
		strcpy(cRemMf20DataR,"BK");	
		strcpy(cRemSBuffersState,"BL");	
		strcpy(cRemTBuffer1,"BM");	
		strcpy(cRemTBuffer2,"BN");
	    strcpy(cRemMAC0    ,"BP");
	    strcpy(cRemMAC1    ,"BR");
		strcpy(cRemXilFileData, "BT");
		strcpy(cRemXilFileData2,"C2");
		strcpy(cRemXilFileData3,"BZ");
		strcpy(cFileUpdate, "BV");
		strcpy(cProgVersion,"BX");
#ifdef PROG_BMDN
	   strcpy(cConfigFileVersion,"EG");
       strcpy(cAllConfigFileVersion,"GD");
       strcpy(cAllConfigFileVersion1,"GE");
       strcpy(cAllConfigFileVersion2,"GF");
       strcpy(cAllConfigFileVersion3,"GG");
       strcpy(cAllConfigFileVersion4,"I0");
       strcpy(cAllConfigFileVersion5,"I2");

       strcpy(cModEth, 			   	 "GH");


	   strcpy(cRemXilFileDatax0, "EI");
	   strcpy(cRemXilFileDatax1, "EJ");
	   strcpy(cRemXilFileDatax2, "EK");
	   strcpy(cRemXilFileDatax3, "EL");
	   strcpy(cRemXilFileDatax4, "EM");
	   strcpy(cRemXilFileDatax5, "EN");
	   strcpy(cRemXilFileDatax6, "EO");
	   strcpy(cRemXilFileDatax7, "EP");
	   strcpy(cRemXilFileDatax8, "EQ");
	   strcpy(cRemXilFileDatax9, "ER");
	   strcpy(cRemXilFileDatax10, "ES");
	   strcpy(cRemXilFileDatax11, "ET");
	   strcpy(cRemXilFileDatax12, "EU");
	   strcpy(cRemXilFileDatax13, "EV");
	   strcpy(cRemXilFileDatax14, "EW");
	   strcpy(cRemXilFileDatax15, "EX");

	   strcpy(cPriority0, "F0");
#ifndef PROG_BMDN6MI

	   strcpy(cPriority1, "F1");
	   strcpy(cPriority2, "F2");
	   strcpy(cPriority3, "F3");
	   strcpy(cPriority4, "F4");
	   strcpy(cPriority5, "F5");
	   strcpy(cPriority6, "F6");
	   strcpy(cPriority7, "F7");
	   strcpy(cPriority8, "F8");
#endif


	   strcpy(cThreshold0, "F9");
	   strcpy(cThreshold1, "FA");
	   strcpy(cThreshold2, "FB");
	   strcpy(cThreshold3, "FC");
	   strcpy(cThreshold4, "FD");
	   strcpy(cThreshold5, "FE");
	   strcpy(cThreshold6, "FF");
	   strcpy(cThreshold7, "FG");
	   strcpy(cThreshold8, "FH");

	   strcpy(cProtect0, "FM");
	   strcpy(cProtect1, "FN");
	   strcpy(cProtect2, "FO");
	   strcpy(cProtect3, "FP");
	   strcpy(cProtect4, "FQ");
	   strcpy(cProtect5, "FR");
	   strcpy(cProtect6, "FS");
	   strcpy(cProtect7, "FT");
	   strcpy(cProtect8, "FU");
	   strcpy(cProtect9, "FV");
	   strcpy(cProtect10, "FW");
	   strcpy(cProtect11, "FX");
	   strcpy(cProtect12, "FY");
	   strcpy(cProtect13, "FZ");
	   strcpy(cProtect14, "Fa");
	   strcpy(cProtect15, "Fb");
	   strcpy(cProtect16, "Fc");
	   strcpy(cProtect17, "Fd");
#endif

#ifdef PROG_BMDN4
   strcpy(cRemOperateProg, "Fg");
#endif

#ifdef PROG_PU_M710
	strcpy(cRemOperateProg, "Fg");
#endif

#ifdef HAVE_GATEWAY
	   strcpy(cRemNetwork, "Fe");
	   strcpy(cRemNetMask, "Ff");

       strcpy(cRemNetMask0, "HR");
       strcpy(cRemNetMask1, "HS");
	   strcpy(cRemNetMask2, "HT");
	   strcpy(cRemNetMask3, "HU");
 	   strcpy(cRemNetwork0, "HV");
 	   strcpy(cRemNetwork1, "HW");
 	   strcpy(cRemNetwork2, "HX");
 	   strcpy(cRemNetwork3, "HY");


#endif

#ifdef PROG_PU_MSAT
	  strcpy(cRemSatSet0, "Fh");
	  strcpy(cRemSatSet1, "Fi");
	  strcpy(cRemSatSet2, "Fj");
	  strcpy(cRemSatSet3, "Fk");
	  strcpy(cRemSatSet4, "Fl");
	  strcpy(cRemSatSet5, "Fm");
	  strcpy(cRemSatSet6, "Fn");
	  strcpy(cRemSatSet7, "Fo");
      strcpy(cRemSatSet8, "GI");

	  strcpy(cRemSatGet0, "Fp");
	  strcpy(cRemSatGet1, "Fq");
	  strcpy(cRemSatGet2, "Fr");
	  strcpy(cRemSatGet3, "Fs");
	  strcpy(cRemSatGet4, "Ft");
	  strcpy(cRemSatGet5, "Fu");
	  strcpy(cRemSatGet6, "Fv");
	  strcpy(cRemSatGet7, "Fw");

#ifdef PROG_PU_MSAT1
	  strcpy(cRemSatGet8, "Z0");
#endif

	  strcpy(cRemSatTestMode, "Fx");
	  strcpy(cRemSatPC, "Fy");
	  strcpy(cRemSatInput , "Fz");
	  strcpy(cRemSatLock  , "GA");
	  strcpy(cRemSatSearch, "GB");
	  strcpy(cRemSatXilBlock, "GC");
	   strcpy(cRemSatTiming, "GH");
   strcpy(cRemSatSound, "GJ");
   strcpy(cRemSatFactory, "GK");
     strcpy(cRemSatDF, "GP");
	  strcpy(cRemSatTF, "GQ");
	  strcpy(cRemSatRate, "GR");
	    strcpy(cRemSatTimer, "GS");

#ifdef RECEIVE_MOD_LOCK

		strcpy(cRemSatExtLock,"GT");
		strcpy(cRemSatExtLockP,"GU");
#endif
	   strcpy(cRemSatLowP,"GV");
	   strcpy(cRemSatALev,"GW");
   	   strcpy(cRemSatALev,"GX");
       strcpy(cRemSatALev,"GY");
       strcpy(cRemSatALev,"GZ");



#endif
	  strcpy(cIdInd      ,  "    Serial Number :     ");	
#ifdef USE_HTTP
	 strcpy(cRemWebPassword, "GO");
	 strcpy(cWebPassword,   "     Web Password :     ");

#endif

#ifdef YOURNAL
  strcpy(cRemLogStr0, "GL");
  strcpy(cRemLogStr1, "GM");
  strcpy(cRemLogClear, "GN");

#endif




#ifdef PROG_PRM_PCH_DEM
  strcpy(cSymbolRate, "FI");
  strcpy(cFreqPCh, "FJ");
  strcpy(cModulSK, "FK");
#endif //PROG_PRM_PCH_DEM

#ifdef PROG_PRM_PCH_DEM_XIL
  strcpy(cRemXilFileData4, "FL");
#endif

#ifdef PROG_PRM_PCH_DEM_XIL_CHN_DMU4
 strcpy(cRemDecFileData, "EY");
#endif

#ifdef USE_SOCKETSD
strcpy(cRemIPAddressUDP, "LP12345");
#endif



		strcpy(cRemCom,	   "N0");
		strcpy(cDevDat,	   "N1");
		strcpy(cRemIns,	   "a07");
		strcpy(cRemSynce,  "a04");
		strcpy(cRemLoop,   "a05");
		strcpy(cRemClk,	   "C0");
#ifdef PROG_TUTS
		strcpy(cTSInp,	   "C3");
		strcpy(cTSInpTrg,  "C5");
		strcpy(cTSOut,	   "C4");
#endif //PROG_TUTS
		strcpy(cRemRem,	   "a16");
		strcpy(cRemBits,   "a17");
		strcpy(cRemParity, "a18");
		strcpy(cRemVCC18,  "a19");
		strcpy(cRemPolRt,  "a10");	
		strcpy(cRemPolRd,  "a13");
		strcpy(cRemPolTt,  "a14");
		strcpy(cRemPolSd,  "a15");
		strcpy(cRemTiming,  "a00");
		strcpy(cRemInType, "a09");
		strcpy(cRemPatType, "a08");
		strcpy(cRazd,	   ";");
		strcpy(c1d,		   "%1d");
		strcpy(c1X,		   "%1X");
		strcpy(c2X,		   "%02X");
		strcpy(c2d,		   "%2d");
		strcpy(c02d,		   "%02d");

		strcpy(c3d,		   "%3d");
		strcpy(cPoint,	   ".");
		strcpy(c8d,		   "%8ld");	
		strcpy(cd,		   "%d");	
	
		strcpy(cK0,		   "K0");	
		strcpy(cK1,		   "K1");	
		strcpy(cs,	   	   "%s");
  //		strcpy(c4X,	   	   "%4lX");
		strcpy(c4X,	   	   "%04X");
		strcpy(c06X,   	   "%06X");
	   	strcpy(c4d,	   	   "%04d");
		strcpy(c4dd,	   	   "%4d");
		strcpy(c6d,	   	   "%6d");
		strcpy(c08X,   	   "%08X");
		strcpy(c30c,   	   "%30c");
	  	strcpy(c514c,  	   "%514c");
		strcpy(c256c,  	   "%256c");
		strcpy(c64X,  	   "%64X");

 	 	strcpy(c200c,  	   "%200c");
		strcpy(c1400c,     "%1400c");

// 		strcpy(c200c,  	   "%300c");


		strcpy(c100c,  	   "%100c");
		strcpy(cRemSpi,	   "D0");
		strcpy(cRemSpiCs,  "D1");
		strcpy(cRestart,   "@");
		strcpy(c9d,		   "%9ld");
		strcpy(c5d,		   "%5ld");
	    strcpy(c63f,		   "%6.3f");
		 strcpy(c52f,		   "%5.2f");

	    strcpy(c41f,		   "%4.1f");
		  strcpy(c42f,		   "%4.2f");

		strcpy(c61f,		   "%6.1f");

		strcpy(c21f,		   "%2.1f");

        strcpy(c71e,		   "%7.1e");
		   strcpy(c31f,		   "%3.1f");
 	    strcpy(c32f,		   "%3.2f");

  	    strcpy(c031f,		   "% 3.1f");

		     strcpy(c74f,		   "%7.4f");
			   strcpy(c84f,		   "%8.4f");


#ifdef PROG_MD310_SATI
#ifndef PROG_MD310_SATI2
#include "md310s_variables.cpp";
#else
#include "md310s2_variables.cpp";

#endif


#endif

}

extern "C" void CntFunc::Operate(Uint16 sel)
{
  static key_step = 0;	
  uint_32 data_len;
  unsigned i;
#ifdef YOURNAL
char * stopstring;
unsigned long num;
#endif


   //	 printf("\n\r\test");




 // #ifdef  PROG_BACO
//	if((LockMode.Value  == 2) && (sel != 47)) return;
//  #endif

	 Uint16 selcnt = 265;
 	switch(sel)
	{


	case 1:	UsedExp.State.Reg2.bit.XILR0 = 1; //load XilR0
			UsedExp.State.Reg2.bit.Some  = 1; //some load
		    break; //ClkNumber	
	case 2:	 //IPAddress 
		   //	 if (UsedExp.State.Reg1.bit.Init) break; //if init not finished not need  
		//   	rtcs_result = RTCS_if_bind(ihandle0, GetIP(), 0x00000000);
		   /*
			IPAddress3.Value = 	((uint_32)IPAddress.Value >> 24)	& 0xff;
		    IPAddress3.WriteStorageC((IPAddress3Storage), (IPAddress3.Value));
			IPAddress2.Value = 	((uint_32)IPAddress.Value >> 16)	& 0xff;
		    IPAddress2.WriteStorageC((IPAddress2Storage), (IPAddress2.Value));
 			IPAddress1.Value = 	((uint_32)IPAddress.Value >> 8)	& 0xff;
			IPAddress1.WriteStorageC((IPAddress1Storage), (IPAddress1.Value));
			IPAddress0.Value = 	((uint_32)IPAddress.Value)	& 0xff;
			IPAddress0.WriteStorageC((IPAddress0Storage), (IPAddress0.Value));
			*/
			WriteDevId();
		    MakeIPAddresses();
 		   	UsedExp.State.Reg2.bit.IP = 1; //changeIP
			UsedExp.State.Reg2.bit.Some  = 1; //some load
	  //t		UsedMenu.Draw();
  			break;
	case 5:	 //hier make DevData

		  //	Add_Event(EV_COMMAND, 2, "49"); //for test

	  		 DeviseData((uchar_ptr)&DevData.Value[0], &data_len); break;
	case 6:	 printfp("\n\n\n\r Command for restart \n\n\n\n\r");

	if(RestartData.Value)  dev_restart(); break;
	
	case 7:
	case 8:
	case 9:
	case 10:  //	if (UsedExp.State.Reg1.bit.Init) break; //if init not finished IPaddresses 0,1,2,3 not can change full ipaddress
				IPAddress.Value = 	((char)IPAddress3.Value << 24) + ((char)IPAddress2.Value<<16)	+
										 ((char)IPAddress1.Value<<8) + (char)IPAddress0.Value;
			  //to flash	IPAddress.WriteStorageC((IPAddressStorage), (IPAddress.Value));
				UsedExp.State.Reg2.bit.IP = 1; //changeIP
				UsedExp.State.Reg2.bit.Some  = 1; //some load
				WriteDevId();
			//	for(;;) //t100608
		//	printf("test"); //100608
				
	  //t			UsedMenu.Draw();
  				break;
	case 11:
		 //	 #ifdef YOURNAL
		 //	  	Add_Event(EV_COMMAND, 2, "49"); //for test
		 //	#endif
		 //		 WriteDevId();	  		break;	 //uaartaddress
    case 12:
	case 13:
	case 14:
	case 15:
			  WriteDevId(); break;
	case 16: UsedExp.State.Reg2.bit.ChTM = 1; // ChangeTestMode();
			 UsedExp.State.Reg2.bit.Some = 1;
		  // printf("\n\r...case16");
		  //130917	  WriteDevId();
			 break;
	case 17: WriteDevId();	//pok
			 #ifdef PROG_MD310_SAT
 				OperateACM();
			 #endif
	 			break;
	case 18: embRS232_rcvbuf_Add((unsigned char)(Mf20Data.Value));
		 	 UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; break;	  //for answer mf20 will use SNMP
	case 19 : break;
	case 21:  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; break ; //TBuffer1.len = ((Uint16)TBuffer1.Value[1] << 8) +  TBuffer1.Value[0];
	case 22:  UsedExp.State.Reg1.bit.Mf20SnmpOn = 1; // SendBuffToMf(&RBuffer1.Value[0]);
	  //		  MessageChar(1,1, RBuffer1.Value[0]);
	 		  break;
	case 23:
	case 24:   WriteDevId();  break;	   //new mac can be used after restart
	case 26:   //OperateFile();
			   //	 Ring(1,1,5,2);	   //temporary

				UsedExp.State.Reg2.bit.FU = 1; //operate file
				UsedExp.State.Reg2.bit.Some  = 1; //some load
				break;
#ifdef PROG_TUTS
    case 30:  //inputs
				  Reset_Triggered(0xFFFFFFFFl);
    			break;
  	case 31:  //outputs
    			TUTS_Output_Set((unsigned char) TSOut.Value);
				WriteDevId(); 
    			break;
	case 32:  //inputs triggered
			  //Reset_Triggered();
			  // TSInpTrg.Value = 0l;	   //t
  			  // TSInpTrg.ChangingValue = 0l ;	  //t

				break;
#endif// PROG_TUTS

#ifdef PROG_DTVM
	 case 33:  dtvm_init();  break;	  //rate
	 case 34:  dtvm_init();break;    //video
     case 35:  dtvm_init(); break ;    //test
	 case 36:  dtvm_init();  break;	  //sound
	 case 37:  break; 				  //stat
	 case 38:  break; 				  //err
	 case 39:  break; 				  //point
	 case 40:  break; 				  //addr
  	

#endif //PROG_DTVM

#ifdef PROG_KTVM
	 case 33:  start_ktvm(); break; //090603  Encoder_Set();  break;	  //rate
 	 case 34:  start_ktvm(); break;    //video !!!!!!!!!!!!!!!!!!!!!MAKE NOTHING!!!!!!!!!!!!!!!!! it is question
     case 35:  start_ktvm(); break;    //test  !!!!!!!!!!!!!!!!!!!!!MAKE NOTHING!!!!!!!!!!!!!!!!! it is question
	 case 36:  start_ktvm(); break; //090603 Encoder_Set();  break;	  //sound
	 case 37:  break; 				  //stat
   //	 case 38:  break; 				  //err
	 case 39:  break; 				  //point
	 case 40:  break; 				  //addr
	

#endif //PROG_KTVM



#ifdef IncEmbIndicator
 	case 41: 
#ifndef PROG_PU_MSAT
	 	   //140707	   if(TestMode.Value == 0x20)
			   if(1)
				{
#else
				 if(1)
				{

#endif
	  				AddKeyBuffer( (unsigned char) KeyData.Value);
	  			}
	  			else
	  			{
				#ifdef IncEmbIndicator
	  				embIndicator.m_RBuff.Add( (unsigned char) KeyData.Value);
				#endif //IncEmbIndicator
	   			}
				break;
    case 42:  break; 				  //Ind0
	case 43:  break; 				  //Ind1
	case 44:  break; 				  //Cur
#endif //IncEmbIndicator

#ifdef PROG_BMD35
	case 46: WriteDevId();   break; 	 //remnum
#endif //PROG_BMD35

#ifdef PROG_PROV
	case 46: WriteDevId();   break; 	 //remnum
#endif //PROG_PROV


#ifdef PROG_MPC35
	case 46: WriteDevId();   break; 	 //remnum
#endif //PROG_MPC35

#ifdef  LOCK_ENABLED
	case 47:

 //  printfp("\n\rmake some with lock");
	  //	 ClearBufferState((unsigned long)LOCK_MODE1);
	  //		ClearBufferState((unsigned long)LOCK_MODE2);
	   	 ClearBufferState((unsigned long)LOCK_MODE1);
		 ClearBufferState((unsigned long)LOCK_MODE3);
	     SetBufferState((unsigned long)LOCK_MODE2);
	 //	printfpd(" key_step %d ", key_step);
		switch(key_step)
		{
		 case 0:  if(LockMode.Value == TWO_KEY)     {/*printfp(" key 2 ");*/LockMode.Value = 2; key_step = 1;} else {/*printfp("2a")*/;LockMode.Value = 2; key_step = 0; }  break;
		 case 1:  if(LockMode.Value == THREE_KEY)   {/*printfp(" key 3 ");*/LockMode.Value = 1; key_step = 2; SetBufferState((unsigned long)LOCK_MODE1);  ClearBufferState((unsigned long)LOCK_MODE2); return;} else {/*printfp("3a")*/;LockMode.Value = 2; key_step = 0;} break;//unlock without writing
		 case 2:  if(LockMode.Value == FOUR_KEY)    {/*printfp(" key 4 ");*/LockMode.Value = 0; key_step = 3;ClearBufferState((unsigned long)LOCK_MODE2);} else {/*printfp("4a")*/;LockMode.Value = 2;key_step = 0; } break;
		 case 3:  if(LockMode.Value == FIVE_KEY)    {/*printfp(" key 5 ");*/LockMode.Value = 3; SetBufferState((unsigned long)LOCK_MODE3); ClearBufferState((unsigned long)LOCK_MODE2); key_step = 0; } else {/*printfp("5a")*/;LockMode.Value = 2;key_step = 0; } break;
		 default : if(LockMode.Value  == FIRST_KEY) {/*printfp(" key 1 ");*/LockMode.Value = 2; key_step = 0;}	break;
		 }
	 //1 key : LOCK_MODE2	  value : 2
	 //2 key : LOCK_MODE2	  value : 2
	 //3 key : LOCK_MODE1	  value : 1
	 //4 key : LOCK_MODE2	  value : 0
	 //5 key : LOCK_MODE3	  value : 3

	  //	 ClearBufferState((unsigned long)LOCK_MODE1);
	  //	 ClearBufferState((unsigned long)LOCK_MODE2);
	  //	 if(LockMode.Value == 1) { SetBufferState((unsigned long)LOCK_MODE1); break;} //not write unlock
	  //	 if(LockMode.Value == 2) SetBufferState((unsigned long)LOCK_MODE2);
 		 WriteDevId();
		 break;
#endif // LOCK_ENABLED

#ifdef TRAP_ENABLED

	 case 48:   WriteDevId();
		 		break;


	 case 49:	 WriteDevId();
	 		//	Add_Event(EV_COMMAND, 2, "49"); //for test
		 		break;
#endif //TRAP_ENABLED

#ifdef CLOCK_ENABLED
	 case 50 :  ClockWriteSec((unsigned char) TimeData1.Value);	break;
	 case 51 :  ClockWriteMin((unsigned char) TimeData2.Value);	break;
	 case 52 :  ClockWriteHours((unsigned char) TimeData3.Value);	break;
	 case 53 :  ClockWriteDate((unsigned char) TimeData4.Value);	break;
	 case 54 :  ClockWriteMonth((unsigned char) TimeData5.Value);	break;
	 case 55 :  ClockWriteYear((unsigned char) TimeData6.Value);	break;

#endif //  CLOCK_ENABLED

#ifdef YOURNAL
	 case 56 :
//120529	 			GetRecord();	 //use setted record as address and fill records beffer to values ferm nvram
	  		 //	printf("\n\r%s", CRecord.Value);
 		  num =  strtol(CRecord.Value, &stopstring,16);
 	 //	  if(num > (RECORDS_MAX_QUANTITY - 1)) num = 0; 
	 #ifdef PRINT_YOURNAL
 //  printfpd("\n\r addr : 0x%lX", addr);
	 printEthLongHex(num);
#endif

		  GetRecord1(num);



			 break;

#endif // YOURNAL	 

#ifdef PROG_BMDN
	 case 57 : 
	 
   //	 printfp("\n\rFillCFV0 = 1");
	 
	  UsedExp.State.Reg2.bit.FillCFV0 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	  UsedExp.State.Reg2.bit.Some = 1;
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 


#ifdef TRY_UNBLOCK 
 //  	   WriteDevId(); printf("123456789"); //t101028
#endif
	   break;

 //	data_len = 0;  
	 case 58 :	UsedExp.State.Reg2.bit.FillCFV1 = 1;   UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;

#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 

break;
 //data_len = 1;break;

	 case 59 :	UsedExp.State.Reg2.bit.FillCFV2 = 1;    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
break;
 //data_len = 2;
	 case 60 :	UsedExp.State.Reg2.bit.FillCFV3 = 1;    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
break;
// data_len = 3;
	 case 61 :	UsedExp.State.Reg2.bit.FillCFV4 = 1;   UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
 break;
// data_len = 4;
	 case 62 :	UsedExp.State.Reg2.bit.FillCFV5 = 1;    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
break;
// data_len = 5;
	 case 63 :	UsedExp.State.Reg2.bit.FillCFV6 = 1;    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
break;
// data_len = 6;
	 case 64 :	UsedExp.State.Reg2.bit.FillCFV7 = 1;    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
break;
// data_len = 7;
//______________________________________8 modems

 	 case 65 :	UsedExp.State.Reg2.bit.FillCFV8 = 1;
 	    UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
 break;
// data_len = 7;
//______________________________________9modems
 //	 case 66 :	data_len = 9;
 //	 case 67 :	data_len = 10;
 //	 case 68 :	data_len = 11;
 //	 case 69 :	data_len = 12;
 //	 case 70 :	data_len = 13;
 //	 case 71 :	data_len = 14;
 //	 case 72 :	data_len = 15;

	 //	   UsedExp.State.Reg2.bit.WriteId = 1;
		//   State.Reg2.bit.FillCFV = 1;
	 //	   UsedExp.State.Reg2.bit.Some = 1;




#ifdef TRY_UNBLOCK 			 
	  		  WriteDevId();	 //in future need make setneedwritedevid  hier can operate with blocking tcpiptask!!!
//	  		  ConfigFileLoadm(GetNumConfigFile(data_len), data_len);	 //to all plats - temporary?
	 //	_int_enable();
   	  	printf("123456789");

	  	//	  ConfigFileRunm(data_len);
		  break;
#endif //TRY_UNBLOCK			  
		  //	  for(;;); //for test
			//  break;

 case 74 : //	 CommutateModForSS();
 if(!((unsigned long)ModForSS.Value & 2l))
{
  ClearBufferState((unsigned long)OPERATE_POWER_ON);
}
 else
{
  SetBufferState((unsigned long)OPERATE_POWER_ON);
}

 			 UsedExp.State.Reg2.bit.WriteId = 1;
		     UsedExp.State.Reg2.bit.Some = 1;

			   break;
#endif // PROG_BMDN	

#ifdef PRM_PCH_DEM

case 109:	 
			//need call function to set
			SetNeedWriteDevId();
			break;
case 110:
			//need call function to set
			SetNeedWriteDevId();
			break;
case 111:
			//need call function to set
			SetNeedWriteDevId();
			break;
 	
#endif //PRM_PCH_DEM	

#ifdef PROG_BMDN

case 113:
 			SetProt(0, Protect0.Value);
			SetParseFlags(0);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;

#ifndef PROG_BMDN6MI

case 114:
 			SetProt(1, Protect1.Value);
			SetParseFlags(1);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 115:
 			SetProt(2, Protect2.Value);
			SetParseFlags(2);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 116:
 			SetProt(3, Protect3.Value);
			SetParseFlags(3);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 117:
 			SetProt(4, Protect4.Value);
			SetParseFlags(4);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 118:
 			SetProt(5, Protect5.Value);
			SetParseFlags(5);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 119:
 			SetProt(6, Protect6.Value);
			SetParseFlags(6);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 120:
 			SetProt(7, Protect7.Value);
			SetParseFlags(7);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 121:
 			SetProt(8, Protect8.Value);
			SetParseFlags(8);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 122:
 			SetProt(9, Protect9.Value);
			SetParseFlags(9);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 123:
 			SetProt(10, Protect10.Value);
			SetParseFlags(10);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 124:
 			SetProt(11, Protect11.Value);
			SetParseFlags(11);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 125:
 			SetProt(12, Protect12.Value);
			SetParseFlags(12);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 126:
 			SetProt(13, Protect13.Value);
			SetParseFlags(13);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 127:
 			SetProt(14, Protect14.Value);
			SetParseFlags(14);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 128:
 			SetProt(15, Protect15.Value);
			SetParseFlags(15);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 129:
 			SetProt(16, Protect16.Value);
			SetParseFlags(16);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;
case 130:
 			SetProt(17, Protect17.Value);
			SetParseFlags(17);	 //may be make delayyed - to not waiting
			SetNeedWriteDevId();
			break;

#endif
#endif // PROG_BMDN

#ifdef HAVE_GATEWAY
case 131:
		UsedExp.State.Reg2.bit.Network = 1; //change Network   and need write to flash
		UsedExp.State.Reg2.bit.Some  = 1; //some load

	    Network0.Value = (unsigned)Network.Value & 0xff;
		Network0.ChangingValue = Network0.Value;

		Network1.Value = (unsigned char)((unsigned)Network.Value >> 8);
		Network1.ChangingValue = Network1.Value;
        
		Network2.Value = (unsigned char)((unsigned)Network.Value >> 16);
		Network2.ChangingValue = Network2.Value;

		Network3.Value = (unsigned char)((unsigned)Network.Value >> 24);
		Network3.ChangingValue = Network3.Value;


		break;
case 132:


		NetMask0.Value = (unsigned long)NetMask.Value & 0xff;
		NetMask0.ChangingValue = NetMask0.Value;

		NetMask1.Value = (unsigned char)((unsigned)NetMask.Value >> 8);
		NetMask1.ChangingValue = NetMask1.Value;

		NetMask2.Value = (unsigned char)((unsigned)NetMask.Value >> 16);
		NetMask2.ChangingValue = NetMask2.Value;

		NetMask3.Value = (unsigned char)((unsigned)NetMask.Value >> 24);
		NetMask3.ChangingValue = NetMask3.Value;

//printfpd("\n\rnm0 %x ", NetMask0.Value);
//printfpd("  nm %x ", NetMask.Value);

				 

		UsedExp.State.Reg2.bit.WriteId = 1;

		UsedExp.State.Reg2.bit.NetMask = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
	    break;
#endif


#ifdef PROG_BMDN4
case 134:
        UsedExp.State.Reg2.bit.OperProg = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
		break;
#endif

#ifdef PROG_PU_M710
case 134:
        UsedExp.State.Reg2.bit.OperProg = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
		break;
#endif


#ifdef PROG_PU_MSAT
case 135:
		UsedExp.State.Reg2.bit.SatSet0 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 136:
		UsedExp.State.Reg2.bit.SatSet1 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 137:
		UsedExp.State.Reg2.bit.SatSet2 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 138:
		UsedExp.State.Reg2.bit.SatSet3 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 139:
		UsedExp.State.Reg2.bit.SatSet4 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 140:
		UsedExp.State.Reg2.bit.SatSet5 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 141:
		UsedExp.State.Reg2.bit.SatSet6 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 142:
		UsedExp.State.Reg2.bit.SatSet7 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 151:
		UsedExp.State.Reg2.bit.SatTestMode = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
case 152:
		UsedExp.State.Reg2.bit.SatPC = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 162:
		UsedExp.State.Reg2.bit.SatTiming = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 163:
		UsedExp.State.Reg2.bit.SatSet8 = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 165:
		UsedExp.State.Reg2.bit.SatSound = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 166:
		UsedExp.State.Reg2.bit.SatFactory = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;
#endif


#ifdef PROG_BMDN
case 161:
        UsedExp.State.Reg2.bit.ModEth = 1; //change ModEth
		UsedExp.State.Reg2.bit.Some  = 1; //some load
		break;
#endif

case 169:
#ifdef YOURNAL
 #ifdef DEB_LOG

printfp("\n\r 169 set bit");
#endif



	  UsedExp.State.Reg2.bit.LogClear = 1; //change NetMask
      UsedExp.State.Reg2.bit.Some  = 1; //some load
	    break;
#endif


case 170:
#ifdef USE_HTTP
	   UsedExp.State.Reg2.bit.WriteId = 1;
       UsedExp.State.Reg2.bit.Some  = 1; //some load
	    break;
#endif

#ifdef PROG_PU_MSAT
case 171:
		UsedExp.State.Reg2.bit.SatDF = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 172:
		UsedExp.State.Reg2.bit.SatTF = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 173:
		UsedExp.State.Reg2.bit.SatRate = 1; //change SatRate
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 174:
		UsedExp.State.Reg2.bit.SatTimer = 1; //change SatTimer
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

#ifdef RECEIVE_MOD_LOCK


case 176:
		UsedExp.State.Reg2.bit.SatExtLock = 1; //change SatExtLock
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 177:
		UsedExp.State.Reg2.bit.SatExtLockP = 1; //change SatExtLockP
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

#endif

case 178:
		UsedExp.State.Reg2.bit.SatLowP = 1; //change SatExtLockP
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 179:
		UsedExp.State.Reg2.bit.SatALev = 1; //change SatALev
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 180:
		UsedExp.State.Reg2.bit.SatADemo = 1; //change SatALev
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 181:
		UsedExp.State.Reg2.bit.SatACode = 1; //change SatALev
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

case 182:  break; //satacnt


#endif


#ifdef 	PROG_MD310_SATI


case 183: 
	  //	printfp("\n\r");
	 //	for(i = 0; i < NamesConfigFiles.Quantity; i++)
	 //	{
	  //	printfpd("\n\r %d ",ReallyNumCfg[i]);
	 //	}

	  if( ConfigFile.Value == ReallyNumCfg[NamesConfigFiles.ChangingValue])	 break;


   	  ParamsConfigFiles.Value = NamesConfigFiles.ChangingValue;
      ParamsConfigFiles.ChangingValue  = ParamsConfigFiles.Value;




	  ConfigFile.Value = ReallyNumCfg[NamesConfigFiles.ChangingValue];
	   ConfigFile.ChangingValue = ConfigFile.Value;
   //	  	printfpd("\n\r 183  CF : %d", (unsigned long)ConfigFile.Value);
	//   	printfpd(" NCF : %d", (unsigned long)NamesConfigFiles.ChangingValue);
	 //	   	printfpd(" NCFv : %d", (unsigned long)NamesConfigFiles.Value);

  	  UsedExp.State.Reg2.bit.FillCFV0 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	  UsedExp.State.Reg2.bit.Some = 1;
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 



break; //	  NamesConfigFiles



case 184 :// GetCurConfigFromFile(LoadVariants.Value);
		   UsedExp.State.Reg2.bit.LoadVariants = 1;
		   UsedExp.State.Reg2.bit.WriteId = 1;
		   UsedExp.State.Reg2.bit.Some = 1;
		   break;	 //load

case 185 : //PutCurConfigToFile(SaveVariants.Value);
		  UsedExp.State.Reg2.bit.SaveVariants = 1;
		  UsedExp.State.Reg2.bit.WriteId = 1;
		  UsedExp.State.Reg2.bit.Some = 1;
		  break;

case 186 :     break;	 //AnyConfig

case 187 :     break;	 //RAnyConfig




case 188 : ReadRAnyConfig(CurReadedAnyCofig.Value); break;	 //? do not used?

case 189 :     break;		//RAnyConfig1
case 190 :     break;	   // RAnyConfig2
case 191 :     break;	   //RAnyConfig3
case 192 :     break;	   //FirmFileData
case 193 :    UsedExp.State.Reg2.bit.MRfOut = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
    		  break;		//MRfOut
case 194 :    UsedExp.State.Reg2.bit.MOutLev = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLev
case 195 :    break;	   //	MTDRate
case 196 :    break;		//MRDRate
case 197 :  //  printfp("\n\r 197 :");
				UsedExp.State.Reg2.bit.MTFreq = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
     	  	  break;	   //	 MTFreq
case 198 :    UsedExp.State.Reg2.bit.MRFreq = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;	   //MRFreq
case 199 :    break;	   //MTModul
case 200 :    break;	   //	MRModul
case 201 :    break;	   //MTCode
case 202 :    break;		//MRCode
case 203 :    UsedExp.State.Reg2.bit.MDemod = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;	   //MDemod
case 204 :    UsedExp.State.Reg2.bit.MEthMode = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
              break;	  //	MEthMode
case 205 :    UsedExp.State.Reg2.bit.MEthPause = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;	  // MEthPause
case 206 :    UsedExp.State.Reg2.bit.MEthctl = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;	  //MEthctl
case 207 :    UsedExp.State.Reg2.bit.MEthMaxF = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
    		  break;	   //MEthMaxF
case 208 :    UsedExp.State.Reg2.bit.MEthVlanP = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
  			  break;	   //MEthVlanP
case 209 :    break;	   //MEbN0
case 210 :    UsedExp.State.Reg2.bit.MTEbN0 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
    		  break;	   //MTEbN0
case 211 :    break;	   //MBER
case 212 :    UsedExp.State.Reg2.bit.MTBER = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
    		  break;		//MTBER
case 213 :    break;		//MAGC
case 214 :    break;		//MSweep
case 215 :    break;		// MEthSend
case 216 :    break;		// MEthReceived
case 217 :    break;		//MEthModeI
case 218 :    UsedExp.State.Reg2.bit.MIfLoop = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;
case 219 :    UsedExp.State.Reg2.bit.MUnModul = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;

case 220 :    UsedExp.State.Reg2.bit.MACMM = 1;//
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;


case 221 :    UsedExp.State.Reg2.bit.MTBERE = 1;//
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;


case 222 :    UsedExp.State.Reg2.bit.IFmoduleData = 1;//
			//  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;

case 234 :	  UsedExp.State.Reg2.bit.MTMode = 1;//
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;

case 235 :	  UsedExp.State.Reg2.bit.MRMode = 1;//
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;

case 236 :	  UsedExp.State.Reg2.bit.MRCntl = 1;//
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
			  break;


case 237 :    UsedExp.State.Reg2.bit.MOutLevO = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLev

case 238 :    UsedExp.State.Reg2.bit.MOutLevOS = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLevOS

case 239 :	   break; //mbere


case 240 :    UsedExp.State.Reg2.bit.MOutLev1 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLev

case 241 :    UsedExp.State.Reg2.bit.MOutLev2 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLev

case 242 :    UsedExp.State.Reg2.bit.MKout = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//MOutLev


#endif


#ifdef HAVE_GATEWAY
	   
case 244 :
case 245 :
case 246 :
case 247 :
			NetMask.Value = (unsigned)NetMask0.Value  +  ((unsigned)NetMask1.Value << 8) + ((unsigned)NetMask2.Value << 16)	+  ((unsigned)NetMask3.Value << 24);
			NetMask.ChangingValue = NetMask.Value;
			UsedExp.State.Reg2.bit.WriteId = 1;
			UsedExp.State.Reg2.bit.NetMask = 1; //change NetMask
			UsedExp.State.Reg2.bit.Some  = 1; //some load

			break;

case 248 :
case 249 :
case 250 :
case 251 :
			Network.Value = (unsigned)Network0.Value  +  ((unsigned)Network1.Value << 8) + ((unsigned)Network2.Value << 16)	+  ((unsigned)Network3.Value << 24);
			Network.ChangingValue = Network.Value;
			UsedExp.State.Reg2.bit.WriteId = 1;
			UsedExp.State.Reg2.bit.Network = 1; //change Network
			UsedExp.State.Reg2.bit.Some  = 1; //some load

			break;


		
#endif



#ifdef 	PROG_MD310_SATI

case 252 :    UsedExp.State.Reg2.bit.MKout1 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//

case 253 :    UsedExp.State.Reg2.bit.MKin1 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//

case 254 :    UsedExp.State.Reg2.bit.MKin2 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//

case 255 :    UsedExp.State.Reg2.bit.MKin3 = 1;//need use bit MIfLoop.Value == 0 ? flagloop0 = 1; :  flagloop0 = 0; break; //if loop
			  UsedExp.State.Reg2.bit.WriteId = 1;
	  		  UsedExp.State.Reg2.bit.Some = 1;
   			  break;		//




#endif


case 256: 
	  //	printfp("\n\r");
	 //	for(i = 0; i < NamesConfigFiles.Quantity; i++)
	 //	{
	  //	printfpd("\n\r %d ",ReallyNumCfg[i]);
	 //	}

#ifdef PROG_MD310_SATI2


	    if( ConfigFile1.Value == ReallyNumCfg[NamesConfigFiles1.ChangingValue]) break;


	   ParamsConfigFiles1.Value = NamesConfigFiles1.Value;
      ParamsConfigFiles1.ChangingValue  = ParamsConfigFiles1.Value;



	  ConfigFile1.Value = ReallyNumCfg[NamesConfigFiles1.ChangingValue];
	   ConfigFile1.ChangingValue = ConfigFile1.Value;
	  //	printfpd("\n\r CF : %d", (unsigned long)ConfigFile.Value);
	   //	printfpd("\n\r NCF : %d", (unsigned long)NamesConfigFiles.ChangingValue);
  	  UsedExp.State.Reg2.bit.FillCFV1 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	  UsedExp.State.Reg2.bit.Some = 1;
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 

#endif

#ifdef 	PROG_MD310_SATI

case 257:
		UsedExp.State.Reg2.bit.SatSound = 1; //change NetMask
		UsedExp.State.Reg2.bit.Some  = 1; //some load
        break;

#endif


break; //	  NamesConfigFiles1


case 258:	  break; //satget8

case 259:
//printfp("\n\r ______259__\n\r");

#ifdef 	PROG_MD310_SATI
//printfp("\n\r ______259\n\r");
InitEthStat(); SClear.Value = 0;  SClear.ChangingValue = 0;		break;

//#endif
	 
case 260: 
	  //	printfp("\n\r");
	 //	for(i = 0; i < NamesConfigFiles.Quantity; i++)
	 //	{
	  //	printfpd("\n\r %d ",ReallyNumCfg[i]);


	 //	}

	
	  if( ConfigFile.Value == ReallyNumCfg[ParamsConfigFiles.ChangingValue]) break;



	    NamesConfigFiles.Value = ParamsConfigFiles.Value;
        NamesConfigFiles.ChangingValue = ParamsConfigFiles.Value;

   //	    ParamsConfigFiles.Value = NamesConfigFiles.Value;
   //     ParamsConfigFiles.ChangingValue  = ParamsConfigFiles.Value;




	  ConfigFile.Value = ReallyNumCfg[ParamsConfigFiles.ChangingValue];
	   ConfigFile.ChangingValue = ConfigFile.Value;
   //	  	printfpd("\n\r260: CF : %d", (unsigned long)ConfigFile.Value);
	//  	printfpd(" NCF : %d", (unsigned long)NamesConfigFiles.ChangingValue);
  	  UsedExp.State.Reg2.bit.FillCFV0 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	  UsedExp.State.Reg2.bit.Some = 1;
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 



break; //	  NamesConfigFiles

#endif

case 261: 
	  //	printfp("\n\r");
	 //	for(i = 0; i < NamesConfigFiles.Quantity; i++)
	 //	{
	  //	printfpd("\n\r %d ",ReallyNumCfg[i]);
	 //	}
#ifdef PROG_MD310_SATI2
   //	  NamesConfigFiles1.Value = ParamsConfigFiles1.Value;
    // NamesConfigFiles1.ChangingValue = ParamsConfigFiles1.Value;

  //  ParamsConfigFiles1.Value = NamesConfigFiles1.Value;
  //      ParamsConfigFiles1.ChangingValue  = ParamsConfigFiles1.Value;

	     if( ConfigFile1.Value == ReallyNumCfg[ParamsConfigFiles1.ChangingValue]) break;

		  NamesConfigFiles1.Value = ParamsConfigFiles1.Value;
          NamesConfigFiles1.ChangingValue = ParamsConfigFiles1.Value;



	  ConfigFile1.Value = ReallyNumCfg[ParamsConfigFiles1.ChangingValue];
	   ConfigFile1.ChangingValue = ConfigFile1.Value;
	  //	printfpd("\n\r CF : %d", (unsigned long)ConfigFile.Value);
	   //	printfpd("\n\r NCF : %d", (unsigned long)NamesConfigFiles.ChangingValue);
  	  UsedExp.State.Reg2.bit.FillCFV1 = 1;
	 UsedExp.State.Reg2.bit.WriteId = 1;
	  UsedExp.State.Reg2.bit.Some = 1;
#ifdef YOURNAL        //before init
  Add_Event(EV_MY_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 

//#endif

case 262:		
		 //DFE
		 break;

case 263:
#ifdef RACM
		 lost_mailboxes = 0;

#endif
	  break;	
		
case 264:
case 265:
case 266:
case 267:
case 268:
case 269:
case 270:
case 271:
case 272:
case 273:
case 274:
case 275:
case 276:
case 277:
case 278:
case 279:
case 280:
case 281:
case 282:
case 283:
case 284:
case 285:
case 286:
case 287:
case 288:
case 289:
case 290:
case 291:
case 292:
case 293:
case 294:
case 295:
case 296:
case 297:
case 298:
case 299:
case 300:
case 301:
case 302:
case 303:
case 304:
case 305:
case 306:
case 307:
case 308:
case 309:
case 310:
case 311:
case 312:
case 313:
case 314:
case 315:
case 316:
case 317:
case 318:
case 319:
case 320:
case 321:
case 322:
case 323:
case 324:
case 325:
case 326:
case 327:
case 328:
case 329:
case 330:
case 331:
case 332:
case 333:
case 334:
case 335:
case 336:
case 337:
case 338:
case 339:
case 340:
case 341:
case 342:
case 343:
case 344:
case 345:
case 346:
case 347:
	
   SetNeedWriteDevId();	 break;

case 350:  //offset
	
   SetNeedWriteDevId();	 break;


	  
#endif //sati

#ifdef USE_SOCKETSD

case 351:	 
			//need call function to set

			printfpd("\n\r >%08X ", (unsigned long)IPAddressUDP.Value);
			printfpd("cv : %08X ", (unsigned long)IPAddressUDP.ChangingValue);


			SetNeedWriteDevId();
			break;

#endif



default:	break;


	}
}


extern "C" Uint16 CntFunc::Control(Uint16 sel, float64 CValue)
{
 //	if (UsedExp.State.Reg1.bit.Init) return 1; //not check if init not ended
// uint_32 aaatest;
Uint16 ret = 0;
//  printfp("\n\r Control");
//printfpd("\n\r sel:%d", sel);
#ifdef LOCK_ENABLED
#ifdef PROG_PU_MSAT
unsigned long keeplockmode;
  if(key_enter_flag)
  {
   keeplockmode =  LockMode.Value;
   LockMode.Value = 3;
   SetBufferState((unsigned long)LOCK_MODE3); ClearBufferState((unsigned long)LOCK_MODE2);
      //     printfpd("\n\r keeplockmode s =%d", keeplockmode);
  	key_enter_flag--;
   }
#endif

#ifdef PROG_MD310_SATI
unsigned long keeplockmode;
  if(key_enter_flag)
  {
   keeplockmode =  LockMode.Value;
   LockMode.Value = 3;
   SetBufferState((unsigned long)LOCK_MODE3); ClearBufferState((unsigned long)LOCK_MODE2); 

   key_enter_flag--;

   //     printfpd("\n\r keeplockmode s =%d", keeplockmode);
  
   }
#endif





#endif

	switch(sel)
	{
	  /*
	case 1:	 if (1){return 1;}	 //temporary to can set every value	 	// if ((CValue <= 40000000l) && (CValue >= 600l)){return 1;}	 //for clknumber
	  //		if((!InType.Value) ||(InType.Value == 2) &&  //lvds or ttl
	  //		(CValue <= 55000000l) && (CValue >= 600l)) {return 1;}
	  //	    else if((CValue <= 10000000l) && (CValue >= 600l)) {return 1;} //rs449
	   	    else {return 0;} break;
		*/
	case 0:
	 			ret = 1;
			   break;
	case 1:	   //some write
#ifdef LOCK_ENABLED
	 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret =  0;
	 else ret = 1;
#endif
   break;
case 2:	   //ip address full
#ifdef LOCK_ENABLED
#ifndef PROG_PRM_PCH_SPI_XIL_ETH
  //   if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
     if(LockMode.Value != 3 ) ret = 0;
#else
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
	 else ret = 1;
#endif




	   break;
	case 5:	//DevData
//	printfp("DevData");
	   //		 aaatest = strlen(&DevData.Value[0]);
      //delete error!       if(CValue != 10) {return 0;}  //check number of digits in address
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
	 //	  	 if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) && (LockMode.Value)) ret = 0;
	 	 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
			 ret = 1;
   //		  printfpd("L :%d", (unsigned long)LockMode.Value);
          
	    break;
	case 6:	//RestartData
	printfp("\n\n\n\r Command for restart \n\n\n\n\r");
//	return 0;
	   //		 aaatest = strlen(&DevData.Value[0]);
      //delete error!       if(CValue != 10) {return 0;}  //check number of digits in address
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
 //			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) && (LockMode.Value)) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
			 ret = 1;


 //___________________________________________IP addr
	    break;
	case 7:	
	#ifdef LOCK_ENABLED
#ifndef PROG_PRM_PCH_SPI_XIL_ETH
     if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
#else
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
			 else
	#endif //LOCK_ENABLED	
			 if((CValue < 0) || (CValue > 255)){ ret = 0;}
			 else ret = 1;
   break;
	case 8:	
	#ifdef LOCK_ENABLED
#ifndef PROG_PRM_PCH_SPI_XIL_ETH
     if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
#else
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
	 else
	 #endif //LOCK_ENABLED	
			 if((CValue < 0) || (CValue > 255)){ ret = 0;}
			 else ret = 1;
   break;
	case 9:	
	#ifdef LOCK_ENABLED
#ifndef PROG_PRM_PCH_SPI_XIL_ETH
     if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
#else
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
	 else
	 #endif //LOCK_ENABLED	
			 if((CValue < 0) || (CValue > 255)){ ret = 0;}
			 else ret = 1;
   break;
	case 10: 
	#ifdef LOCK_ENABLED
#ifndef PROG_PRM_PCH_SPI_XIL_ETH
     if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
#else
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
	else
	#endif //LOCK_ENABLED	
	 			if((CValue < 0) || (CValue > 255)){ ret = 0;}
			 else ret = 1;

			 //uartaddr
   break;
	case 11: 
	#ifdef LOCK_ENABLED
	if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
	else
	#endif //LOCK_ENABLED	
			if((CValue < 0) || (CValue > 255)){ ret = 0;}
			 else ret = 1;
//____________________________Device ID
   break;
	case 12:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
			 if((LockMode.Value != 3 )) ret = 0;
			 else
#endif //LOCK_ENABLED
			if((CValue < 0) || (CValue > 0x9999)){ ret = 0;}	//140203
			else  ret = 1;
//____________________________Device Year
   break;
	case 13:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
			 if((LockMode.Value != 3 )) ret = 0;
			 else
#endif //LOCK_ENABLED
			if(CValue > 0xffff){ ret = 0;}	
			else  ret = 1;
//____________________________Device ver1
   break;
	case 14:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
		   //	 if((LockMode.Value != 3 )) ret = 0;
			   if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;

			 else
#endif //LOCK_ENABLED
			 if(CValue > 0xffff){ ret = 0;}	
			 else ret = 1;
//____________________________Device ver2
   break;
	case 15:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
		  //	 if((LockMode.Value != 3 )) ret = 0;
			   if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;

			 else
#endif //LOCK_ENABLED	
			 if(CValue > 0xffff){ ret = 0;}	
			 else ret = 1;




//__________________________________________________ Test Mode
      break;
    case 16:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) return 0;
		   //	 if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) && (LockMode.Value))
			 if((LockMode.Value != 3 )  && (LockMode.Value != 1 )) 
			 {
		 //	 printfp("\n\rret0");
		  //	  printfpd("\n\r lock %d", LockMode.Value);
			     ret = 0;	 //091111
			  /*   091111
			 if(
			 (CValue != 0x2) && (CValue != 0x3) 	//&& (CValue != 0x4)
			 &&  (CValue != 0xB)  && (CValue != 0xC) 	&& (CValue != 0xD) 
			  &&  (CValue != 0xE)  && (CValue != 0xF) 	&& (CValue != 0x10) 
			  &&  (CValue != 0x11)  && (CValue != 0x12)
			 )
			  ret = 0;
			  else
			   if(CValue > 0xffff){ ret = 0;}
			  else
			  ret = 1;
			  */
			 }
			 else
#endif //LOCK_ENABLED			 
			 // ret = 1;	
    		 if(CValue > 0xffff){ 
    		//  printfp("\n\rret0");
 		  //	     printfpd("\n\r lock %d", LockMode.Value);

    		 
    		 ret = 0;}	  //testmode
			 else 
			 {
// printfp("\n\rret1");

			 ret = 1;
			 }
//________________________POK
   break;
    case 17:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
    
    
     if(CValue > 0xffff){ ret = 0;}	  //pok
			 else ret = 1;
//___________________________________________________________mac0
   break;
    case 23:

#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
			 if(CValue > 0xffffffl){ ret = 0;}
			 else ret = 1;						   //mac1



//_____________________________________________________mac1
   break;
    case 24:
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
    
     if(CValue > 0xffffffl){ ret = 0;}
			 else ret = 1;	
	    break;		 					  
  case 26: //operate file
#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
#endif //LOCK_ENABLED	
    		  ret = 1;						  	
		   break;
#ifdef PROG_TUTS
 //  break;
    case 30:  //inputs
			 //	  Reset_Triggered(0xFFFFFFFFl);
    		 //	break;
				ret = 0;
   break;
  	case 31:  //outputs
    		 #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			 ret = 1;
   break;
	case 32:  //inputs triggered
			  //Reset_Triggered();
			  // TSInpTrg.Value = 0l;	   //t
  			  // TSInpTrg.ChangingValue = 0l ;	  //t

			   ret = 0;
			    break;
#endif// PROG_TUTS


#ifdef PROG_DTVM





	   break;
	case 33: // if(CValue > 0xffffff){ ret = 0;}		//Rate
			 // else
			  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	

			   ret = 1;
	   break;
	case 34: // if(CValue > 0xffffff){ ret = 0;}		 //Video
			 // else
			  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	

			   ret = 1;
	    break;
	case 35: // if(CValue > 0xffffff){ ret = 0;}		//TestSignal
			 // else
			  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	

			   ret = 1;
      break;
 	case 36: // if(CValue > 0xffffff){ ret = 0;}		//Sound
			 // else
			  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	

			   ret = 1;
   break;
	case 37:  			  //else 
			   #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			  if(CValue > 0xff){ ret = 0;}		//state

			  ret = 1;
   break;
	case 38: 			  //else 
			   #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   if(CValue > 0xff){ ret = 0;}		//err

			  ret = 1;
   break;
	case 39:  
	  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	 
	if(CValue > 0xff){ ret = 0;}		//point
			  //else 
			  ret = 1;
   break;
	case 40: 
	   #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
	 if(CValue > 0xff){ ret = 0;}		//addr
			  //else 
			  ret = 1;
   break;
	case 41: // if(CValue > 0xffffffff){ ret = 0;}		//key
  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	 
		    ret = 1;

			  //else 
	    break;	   
	case 42: // if(CValue > 0xffffffff){ ret = 0;}		//ind0
			  //else 
			  ret = 1;
	    break;
	case 43: // if(CValue > 0xffffffff){ ret = 0;}		//ind1
			  //else 
			  ret = 1;
			     break;
	case 44: // if(CValue > 0xffffffff){ ret = 0;}		//cur
			  //else 
			  ret = 1;
			     break;




#endif //PROG_DTVM

#ifdef PROG_KTVM
	case 33: // if(CValue > 0xffffff){ ret = 0;}		//Rate
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
			      break;
	case 34: // if(CValue > 0xffffff){ ret = 0;}		 //Video
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
   break;

	case 35: // if(CValue > 0xffffff){ ret = 0;}		//TestSignal
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
	      break;
 	case 36: // if(CValue > 0xffffff){ ret = 0;}		//Sound
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
			      break;
	case 37:  
	  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
	 if(CValue > 0xff){ ret = 0;}		//state
			  //else 
			  ret = 1;
   break;
  	case 39: 
  	  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
  	  if(CValue > 0xff){ ret = 0;}		//point
			  //else 
			  ret = 1;
   break;
	case 40:  
	  #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
	 if(CValue > 0xff){ ret = 0;}		//addr
			  //else 
			  ret = 1;
   break;
	case 41: // if(CValue > 0xffffffff){ ret = 0;}		//key
 			#ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	 
			  //else 
			  ret = 1;
   break;

	case 42: // if(CValue > 0xffffffff){ ret = 0;}		//ind0
			  //else 
			  ret = 1;
	    break;
	case 43: // if(CValue > 0xffffffff){ ret = 0;}		//ind1
			  //else 
			  ret = 1;
   break;
	case 44: // if(CValue > 0xffffffff){ ret = 0;}		//cur
			  //else 
			  ret = 1;
		  break;

#endif //PROG_KTVM

case 41: // if(CValue > 0xffffffff){ ret = 0;}		//keydata
			  //else 
			  ret = 1;
			     break;




#ifdef PROG_BMD35
   break;
	case 46: // if(CValue > 0xffffff){ ret = 0;}		//RemoteMode
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
			    break;
#endif //PROG_BMD35

#ifdef PROG_PROV
 //  break;
	case 46: // if(CValue > 0xffffff){ ret = 0;}		//RemoteMode
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;
			    break;
#endif //PROG_PROV


#ifdef PROG_MPC35
 //  break;
	case 46: // if(CValue > 0xffffff){ ret = 0;}		//RemoteMode
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;	 break;
#endif //PROG_MPC35

#ifdef KTVM_PROT2
 //  break;
	case 46: // if(CValue > 0xffffff){ ret = 0;}		//RemoteMode
			 // else
			    #ifdef LOCK_ENABLED
    	   //	 if(LockMode.Value == 2 ) ret = 0;
			 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED	
			   ret = 1;	  break;
#endif //KTVM_PROT2
  //    break;
   case 47: // if(CValue > 0xffffff){ ret = 0;}		//LockMode
			 // else
			   ret = 1;
			 break;
#ifdef TRAP_ENABLED
	     
     case 48: // if(CValue > 0xffffff){ ret = 0;}		//trap timer
			 // else
			   ret = 1;
		   break;
	     case 49: // if(CValue > 0xffffff){ ret = 0;}		//trap ip
			 // else
			   ret = 1;	  break;
#endif //TRAP_ENABLED


#ifdef CLOCK_ENABLED
  // break;
	   case 50 : 
	         #ifdef LOCK_ENABLED
       	//     if((LockMode.Value != 3 ) && (LockMode.Value != 1 )) ret = 0;
	   	//	 else
			 #endif //LOCK_ENABLED	
	   		 if((CValue > TIMEDATA1_MAX) || (CValue < TIMEDATA1_MIN)){ ret = 0;}	
	   		 else
	   		  ret = 1;
		    break;
	   case 51 : 
	         #ifdef LOCK_ENABLED
       //	     if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) ) ret = 0;
	   //		 else
			 #endif //LOCK_ENABLED	
 //			 if(CValue > 59){ ret = 0;}	
			  if((CValue > TIMEDATA2_MAX) || (CValue < TIMEDATA2_MIN)){ ret = 0;}	
	   		 else
	   		  ret = 1;
		     break;
	   case 52 : 
	         #ifdef LOCK_ENABLED
       //	    if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) ) ret = 0;
	   //		 else
			 #endif //LOCK_ENABLED	
	  //		 if(CValue > 23){ ret = 0;}	
			 if((CValue > TIMEDATA3_MAX) || (CValue < TIMEDATA3_MIN)){ ret = 0;}	
	   		 else
	   		  ret = 1;
		     break;
	   case 53 : 
	         #ifdef LOCK_ENABLED
      //	     if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) ) ret = 0;
	  //		 else
			 #endif //LOCK_ENABLED	
	   //		 if((CValue > 31)|| (CValue < 1))  { ret = 0;}	
	  	  if((CValue > TIMEDATA4_MAX) || (CValue < TIMEDATA4_MIN)){ ret = 0;}	
	   		 else
	   	 ret = 1;
		    break;
	   case 54 : 
	         #ifdef LOCK_ENABLED
       //	     if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) ) ret = 0;
	   //		 else
			 #endif //LOCK_ENABLED	
		//	 if((CValue > 12) || (CValue < 1)){ ret = 0;}	
			 if((CValue > TIMEDATA5_MAX) || (CValue < TIMEDATA5_MIN)){ ret = 0;}	
	   		 else
	   		  ret = 1;
		    break;
	   case 55 : 
	         #ifdef LOCK_ENABLED
      // 	     if((LockMode.Value != 3 ) && (LockMode.Value != 1 ) ) ret = 0;
	  // 		 else
			 #endif //LOCK_ENABLED	
	  // 	 if(CValue > 99){ ret = 0;}	
	   	  	 if((CValue > TIMEDATA6_MAX) || (CValue < TIMEDATA6_MIN)){ ret = 0;}	
	   	 	else
	   		  ret = 1;
 			 break;
#endif //  CLOCK_ENABLED

#ifdef YOURNAL
	case 56: 		//crecord
#ifdef PRINT_YOURNAL
 //  printfpd("\n\r addr : 0x%lX", addr);
	 printEthLongHex(0x56);
#endif

	   ret = 1;
 			 break;

#endif


#ifdef PROG_BMDN
	case 57: 

	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 

			 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
   // 	 	 if((LockMode.Value != 3 )) ret = 0;  //121004 maked to need key5
			 else
			 #endif //LOCK_ENABLED
		 //	 if(CValue > MAX_CONFIG_FILE_NUM )
			 if(CValue > MAX_CFG_FILE_VARIANT )
			 ret = 0;
			 
			 	
			 else ret = 1;	 //else added 121002
	    break;
	case 74: 

			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if(CValue > MAX_MODFORSS_NUM )
			 ret = 0;
			 
			 	
			 else ret = 1;
	     break;
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if(CValue > MAX_PRIORITY)
			 ret = 0;
			 
			 	
			 else ret = 1;

	    break;
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if(CValue > MAX_THRESHOLD)
			 ret = 0;
			 	
			 else ret = 1;
			 break;
//#define DEV_ID_SIZE	   (208) //BMDN1
#endif //PROG_BMDN

#ifdef PROG_PRM_PCH_DEM
/*
MDataC	SymbolRate;
MDataC	FreqPCh;
MDataC	ModulSK;
*/
      break;
	case 109:
			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue > MAX_SYMBOL_RATE) || (CValue < MIN_SYMBOL_RATE))
			 ret = 0;
	    break;
	case 110:
			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
		   //	 if((CValue > MAX_FREQPCH) || (CValue < MIN_FREQPCH))
			  if(((CValue < MAX_FREQPCH1) && (CValue > MIN_FREQPCH1))
  	 			||  ((CValue < MAX_FREQPCH2) && (CValue > MIN_FREQPCH2)))
			 ret = 0;

	      break;		
	case 111:
			 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
//			 if((CValue > MAX_MODULSK) || (CValue < MIN_MODULSK))
//			 ret = 0;

 if(
  	  (CValue == MODUL1) ||
  	  (CValue == MODUL2) ||
  	  (CValue == MODUL3) ||
  	  (CValue == MODUL4) ||
  	  (CValue == MODUL5) ||
  	  (CValue == MODUL6) ||
  	  (CValue == MODUL7) 
      )
	  {
			 ret = 1;
	  }
	  else
	  {
	  ret = 0;
	  }


	  break;

#endif // PROG_PRM_PCH_DEM

#ifdef PROG_BMDN
   //  break;
   case 113:
   case 114:
   case 115:
   case 116:
   case 117:
   case 118:
   case 119:
   case 120:
   case 121:
   case 122:
   case 123:
   case 124:
   case 125:
   case 126:
   case 127:
   case 128:
   case 129:
   case 130:

	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 ret = 1;
   		  break;

#endif // PROG_BMDN

#ifdef HAVE_GATEWAY
 //  break;
  case 131:
  case 132:

#ifdef LOCK_ENABLED
//141006    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 ))
             if(LockMode.Value != 3 ) //ret = 0;
			 {
    	 	  ret = 0;
	   //		  printfp("\n\r ret = 0");
			  }
			 else
			 #endif //LOCK_ENABLED
			 {
			 ret = 1;
   		 //    printfp("\n\r ret = 1");
			  }
			 break;

#endif

#ifdef PROG_BMDN4
 //  break;
  case 134:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 ret = 1;
			  break;

#endif

#ifdef PROG_PU_M710
   break;
  case 134:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 ret = 1;
			  break;

#endif



#ifdef PROG_PU_MSAT
    //  break;


/*
	    strcpy(cSatSet0   ,"  Min Distance  :       ");	 -> operation rate
		strcpy(cSatSet1   ,"  Max Distance  :       ");	 ->	system delay
		strcpy(cSatSet2   ,"  Output Level  :       ");
		strcpy(cSatSet3   ,"  Averated Distance :   ");	 -> debug keys  
		strcpy(cSatSet4   ,"  Transmit Frequency :  ");
		strcpy(cSatSet5   ,"  Receive Frequency :   ");
		strcpy(cSatSet6   ,"  Transmit Bound:       ");
		strcpy(cSatSet7   ,"  Receive Bound :       ");

	  */

case 135:			//min distance

 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATSET0) || (CValue > MAX_SATSET0)) ret = 0;
			 else ret = 1;
	   break;
case 136:					 //max distance

 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATSET1) || (CValue > MAX_SATSET1)) ret = 0;
			 else ret = 1;
	   break;
case 137:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			   if((CValue < MIN_SATSET2) || (CValue > MAX_SATSET2)) ret = 0;

			 else ret = 1;
	      break;
case 138:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATSET3) || (CValue > MAX_SATSET3)) ret = 0;

			 else ret = 1;
	      break;
case 139:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATSET4) || (CValue > MAX_SATSET4)) ret = 0;

			 else ret = 1;
		   break;
case 140:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATSET5) || (CValue > MAX_SATSET5)) ret = 0;

			 else ret = 1;
		   break;
case 141:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			   if((CValue < MIN_SATSET6) || (CValue > MAX_SATSET6)) ret = 0;

			 else ret = 1;
		    break;
case 142:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATSET7) || (CValue > MAX_SATSET7)) ret = 0;

			 else ret = 1;

		    break;
case 151:				 //sattestmode
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			   if(CValue > 1) ret = 0;

			 else ret = 1;

		    break;
case 152:				//satpc
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			   if(CValue > 1) ret = 0;

			 else ret = 1;


//#endif
	   break;

case 162:				 //sattiming
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			   if(CValue > 1) ret = 0;

			 else ret = 1;

		    break;

case 163:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATSET8) || (CValue > MAX_SATSET8)) ret = 0;

			 else ret = 1;

		    break;

case 165:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATSOUND) || (CValue > MAX_SATSOUND)) ret = 0;

			 else ret = 1;

		    break;

case 166:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATFACTORY) || (CValue > MAX_SATFACTORY)) ret = 0;

			 else ret = 1;

		    break;

//156, 162...166
#endif


#ifdef PROG_BMDN
//   break;
//157...161
  case 161:	//ModEth
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  ret = 1;
		   	  break;
#endif
  	 break;
case 169:

#ifdef YOURNAL

#ifdef DEB_LOG

printfp("\n\r 169 control");
#endif


 			#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_LOGCLEAR) || (CValue > MAX_LOGCLEAR)) ret = 0;

			 else ret = 1;

		    break;

#endif

case 170:

#ifdef USE_HTTP

 			#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_WEBPASSWORD) || (CValue > MAX_WEBPASSWORD)) ret = 0;

			 else ret = 1;

		    break;

#endif


#ifdef PROG_PU_MSAT

case 171:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATDF) || (CValue > MAX_SATDF)) ret = 0;

			 else ret = 1;
	      break;

case 172:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATTF) || (CValue > MAX_SATTF)) ret = 0;
			 else ret = 1;
	      break;

case 173:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATRATE) || (CValue > MAX_SATRATE)) ret = 0;
			 else ret = 1;
	      break;


case 174:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATTIMER) || (CValue > MAX_SATTIMER)) ret = 0;
			 else ret = 1;
	      break;

#ifdef RECEIVE_MOD_LOCK

case 176:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATEXTLOCK) || (CValue > MAX_SATEXTLOCK)) ret = 0;
			 else ret = 1;
	      break;


case 177:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATEXTLOCKP) || (CValue > MAX_SATEXTLOCKP)) ret = 0;
			 else ret = 1;
	      break;

#endif

case 178:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATLOWP) || (CValue > MAX_SATLOWP)) ret = 0;
			 else ret = 1;
	      break;


//#endif

case 179:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATALEV) || (CValue > MAX_SATALEV)) ret = 0;
			 else ret = 1;
	      break;


case 180:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATADEMO) || (CValue > MAX_SATADEMO)) ret = 0;
			 else ret = 1;
	      break;

case 181:
 
 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_SATACODE) || (CValue > MAX_SATACODE)) ret = 0;
			 else ret = 1;
	      break;



case 182:  break; //satacnt



#endif


#ifdef 	PROG_MD310_SATI
case 183: 

 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue > MAX_NUM_CFG1)) ret = 0;
			 else ret = 1;
//	      break;

break; //	  NamesConfigFiles


case 184:

#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
		      ret = 1;
break;

case 185:

#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
		      ret = 1;
break;

case 188:	//curreadedanyconfig

#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
		      ret = 1;
break;

case 193 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRFOUT) || (CValue > MAX_MRFOUT)) ret = 0;
			 else ret = 1;
	      break;


case 194 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MOUTLEV) || (CValue > MAX_MOUTLEV)) ret = 0;
			 else ret = 1;
	      break;


case 195 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTDRATE) || (CValue > MAX_MTDRATE)) ret = 0;
			 else ret = 1;
	      break;


case 196 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRDRATE) || (CValue > MAX_MRDRATE)) ret = 0;
			 else ret = 1;
	      break;

case 197 :	//   printfp("\n\r 197 CTL :");

		   //	  printfpdv(" 6: %6.3f",CValue);

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < (float)MIN_MTFREQ) || (CValue > (float)MAX_MTFREQ))
			   {

			  // printfp("\n\r ret = 0");

			   ret = 0;
			   }
			 else ret = 1;
	      break;

case 198 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRFREQ) || (CValue > MAX_MRFREQ)) ret = 0;
			 else ret = 1;
	      break;

case 199 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTMODUL) || (CValue > MAX_MTMODUL)) ret = 0;
			 else ret = 1;
	      break;
case 200 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRMODUL) || (CValue > MAX_MRMODUL)) ret = 0;
			 else ret = 1;
	      break;
case 201 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTCODE) || (CValue > MAX_MTCODE)) ret = 0;
			 else ret = 1;
	      break;
case 202 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRCODE) || (CValue > MAX_MRCODE)) ret = 0;
			 else ret = 1;
	      break;
case 203 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MDEMOD) || (CValue > MAX_MDEMOD)) ret = 0;
			 else ret = 1;
	      break;

case 204 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_METHMODE) || (CValue > MAX_METHMODE)) ret = 0;
			 else ret = 1;
	      break;


case 205 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_METHPAUSE) || (CValue > MAX_METHPAUSE)) ret = 0;
			 else ret = 1;
	      break;


case 206 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_METHCTL) || (CValue > MAX_METHCTL)) ret = 0;
			 else ret = 1;
	      break;

case 207 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_METHMAXF) || (CValue > MAX_METHMAXF)) ret = 0;
			 else ret = 1;
	      break;

case 208 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_METHVLANP) || (CValue > MAX_METHVLANP)) ret = 0;
			 else ret = 1;
	      break;

case 210 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTEBN0) || (CValue > MAX_MTEBN0)) ret = 0;
			 else ret = 1;
	      break;


case 212 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTBER) || (CValue > MAX_MTBER)) ret = 0;
			 else ret = 1;
	      break;


case 218 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MIFLOOP) || (CValue > MAX_MIFLOOP)) ret = 0;
			 else ret = 1;
	      break;

case 219 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MUNMODUL) || (CValue > MAX_MUNMODUL)) ret = 0;
			 else ret = 1;
	      break;

case 220 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MACMM) || (CValue > MAX_MACMM)) ret = 0;
			 else ret = 1;
	      break;



case 213 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MAGC) || (CValue > MAX_MAGC)) ret = 0;
			 else ret = 1;
	      break;


case 214 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MSWEEP) || (CValue > MAX_MSWEEP)) ret = 0;
			 else ret = 1;
	      break;


case 221 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTBERE) || (CValue > MAX_MTBERE)) ret = 0;
			 else ret = 1;
	      break;

case 222 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
  			 ret = 1;
	      break;

case 232 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTCDTYPE) || (CValue > MAX_MTCDTYPE)) ret = 0;
			 else ret = 1;
	      break;

case 233 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRCDTYPE) || (CValue > MAX_MRCDTYPE)) ret = 0;
			 else ret = 1;
	      break;

case 234 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MTMODE) || (CValue > MAX_MTMODE)) ret = 0;
			 else ret = 1;
	      break;

case 235 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRMODE) || (CValue > MAX_MRMODE)) ret = 0;
			 else ret = 1;
	      break;

case 236 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MRCNTL) || (CValue > MAX_MRCNTL)) ret = 0;
			 else ret = 1;
	      break;


case 237 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MOUTLEVO) || (CValue > MAX_MOUTLEVO)) ret = 0;
			 else ret = 1;
	      break;

case 238 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MOUTLEVOS) || (CValue > MAX_MOUTLEVOS)) ret = 0;
			 else ret = 1;
	      break;


case 239 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MBERE) || (CValue > MAX_MBERE)) ret = 0;
			 else ret = 1;
	      break;



case 240 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MOUTLEV1) || (CValue > MAX_MOUTLEV1)) ret = 0;
			 else ret = 1;
	      break;


case 241 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MOUTLEV2) || (CValue > MAX_MOUTLEV2)) ret = 0;
			 else ret = 1;
	      break;

case 242 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MKOUT) || (CValue > MAX_MKOUT)) ret = 0;
			 else ret = 1;
	      break;

case 243 :
 		     ret = 1;
	      break;




#endif	  //sati


 
case 244 :
case 245 :
case 246 :
case 247 :


 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) 
    	 	 {
    	 	 ret = 0;
		//	 printfp("\n\r ret = 0 ");
			 }
			 else
 #endif //LOCK_ENABLED
 			{
		     ret = 1;
	   //		  printfp("\n\r ret = 1 ");

			 }
	      break;


case 248 :
case 249 :
case 250 :
case 251 :


 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) 
    	 	 {
    	 	 ret = 0;
		//	 printfp("\n\r ret = 0 ");
			 }
			 else
 #endif //LOCK_ENABLED
 			{
		     ret = 1;
	   //		  printfp("\n\r ret = 1 ");

			 }
	      break;

  
#ifdef PROG_MD310_SATI	

case 252 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MKOUT1) || (CValue > MAX_MKOUT1)) ret = 0;
			 else ret = 1;
	      break;

case 253 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MKIN1) || (CValue > MAX_MKIN1)) ret = 0;
			 else ret = 1;
	      break;

case 254 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MKIN2) || (CValue > MAX_MKIN2)) ret = 0;
			 else ret = 1;
	      break;

case 255 :

 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue < MIN_MKIN3) || (CValue > MAX_MKIN3)) ret = 0;
			 else ret = 1;
	      break;


#endif

#ifdef PROG_MD310_SATI2
case 256 :

 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if(CValue > MAX_NUM_CFG) ret = 0;
			 else ret = 1;
	      break;

#endif

#ifdef PROG_MD310_SATI	
case 257:
 
	 #ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_SATSOUND) || (CValue > MAX_SATSOUND)) ret = 0;

			 else ret = 1;

		    break;

#endif

case 259:	  //break; //satget8

#ifndef YOURNAL

#ifdef PROG_MD310_SATI	



 			#ifdef LOCK_ENABLED
    	 	 if((LockMode.Value != 3 )&& (LockMode.Value != 1 )) ret = 0;
			 else
			 #endif //LOCK_ENABLED
			 if((CValue < MIN_LOGCLEAR) || (CValue > MAX_LOGCLEAR)) ret = 0;

			 else ret = 1;

		    break;

#endif
#endif

 
#ifdef 	PROG_MD310_SATI
case 260: 

 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if((CValue > MAX_NUM_CFG)) ret = 0;
			 else ret = 1;
//	      break;

break; //	  NamesConfigFiles



#endif

#ifdef PROG_MD310_SATI2
case 261 :

 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if(CValue > MAX_NUM_CFG1) ret = 0;
			 else ret = 1;
	      break;


		 
case 262:		
		 //DFE
		 break;

#ifdef RACM
case 263:		
 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			  if(CValue > MAX_RACM) ret = 0;
			 else ret = 1;
	      break;

case 264:		
 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_ratimelock) || (CValue > MAX_ratimelock)) ret = 0;
			 else ret = 1;
	      break;

case 265:		
 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_ratimemode) || (CValue > MAX_ratimemode)) ret = 0;
			 else ret = 1;
	      break;

case 266:		
 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_ratimemse) || (CValue > MAX_ratimemse)) ret = 0;
			 else ret = 1;
	      break;

case 267:		
 #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_ratimestep) || (CValue > MAX_ratimestep)) ret = 0;
			 else ret = 1;
	      break;

case 268:
case 269:
case 270:
case 271:
case 272:
case 273:
case 274:
case 275:
case 276:
case 277:
case 278:
case 279:
case 280:
case 281:
case 282:
case 283:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_uebn) || (CValue > MAX_uebn)) ret = 0;
			 else ret = 1;
	      break;

case 284:
case 285:
case 286:
case 287:
case 288:
case 289:
case 290:
case 291:
case 292:
case 293:
case 294:
case 295:
case 296:
case 297:
case 298:
case 299:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_uebn) || (CValue > MAX_uebn)) ret = 0;
			 else ret = 1;
	      break;


case 300:
case 301:
case 302:
case 303:
case 304:
case 305:
case 306:
case 307:
case 308:
case 309:
case 310:
case 311:
case 312:
case 313:
case 314:
case 315:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_enamode) || (CValue > MAX_enamode)) ret = 0;
			 else ret = 1;
	      break;



case 316:
case 317:
case 318:
case 319:
case 320:
case 321:
case 322:
case 323:
case 324:
case 325:
case 326:
case 327:
case 328:
case 329:
case 330:
case 331:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_numode) || (CValue > MAX_numode)) ret = 0;
			 else ret = 1;
	      break;


case 332:
case 333:
case 334:
case 335:
case 336:
case 337:
case 338:
case 339:
case 340:
case 341:
case 342:
case 343:
case 344:
case 345:
case 346:
case 347:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_ndmode) || (CValue > MAX_ndmode)) ret = 0;
			 else ret = 1;
	      break;
//348 : msei
case 349:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if(CValue > MAX_RACM) ret = 0;
			 else ret = 1;
	      break;

case 350:

    #ifdef LOCK_ENABLED
    	 	 if(LockMode.Value != 3 ) ret = 0;
			 else
 #endif //LOCK_ENABLED
			 if((CValue < MIN_RACMOffset) || (CValue > MAX_RACMOffset)) ret = 0;
			 else ret = 1;
	      break;




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






#endif	//racm

#endif //sati

case 351:	   //ipudp address full

#ifdef USE_SOCKETSD

#ifdef LOCK_ENABLED
	 if(LockMode.Value != 3 )  ret = 0;	 //140602
#endif
	 else ret = 1;



printfpd("\n\r control>%08X ", (unsigned long)IPAddressUDP.Value);
			printfpd("cv : %08X ", (unsigned long)IPAddressUDP.ChangingValue);
			printfpd("\n\rcvalue : %08X ", (unsigned long)CValue);
			printfpd("\n\rlockmode : %08X ", (unsigned long)LockMode.Value);


			 printfpd("ret : %d ", ret);
#endif


	   break;



 //  	default: ret = 1;  printfpd("\n\rsel:%d", sel);	    break;
  	default: ret = 0;	    break;
	}

#ifdef LOCK_ENABLED
   /*
#ifdef PROG_PU_MSAT
//printfp("\n\rmake lock???");

 if(key_enter_flag)
  {
   key_enter_flag = 0;
   LockMode.Value =  keeplockmode;
 //    printfpd("\n\r keeplockmode f =%d", keeplockmode);
   keeplockmode = 2;

   }
#endif
 */

#endif
//   printfpd("\n\r ret =%d", ret);
return ret;
}


  extern "C" ExDt::Init()
{
// testexp = 5;
#ifndef	 PROG_ACT155N
  //	State.Reg1.bit.UCDE  = 1; //default uart can disable ethernet
	State.Reg1.bit.UCDE  = 1; //make back
#else  //PROG_ACT155N
	State.Reg1.bit.UCDE  = 1; //default uart  can disable ethernet
#endif //PROG_ACT155N
	State.Reg1.bit.All0s  = 0;
	State.Reg1.bit.Zumm = 0; //zummer off
	State.Reg1.bit.Mf20SnmpOn = 0; // at start use 232
	State.Reg1.bit.Frozen = 0; //display is not frozen
	State.Reg2.bit.FU = 0; //need load file
	State.Reg2.bit.SSC = 0; //need load ds2174
	State.Reg2.bit.Boot = 0; //not need boot
	State.Reg2.bit.XILR0 = 0;
	State.Reg2.bit.XILR1 = 0;
	State.Reg2.bit.ParseE = 0;
	State.Reg2.bit.NIRQ = 0;
	State.Reg2.bit.ChTM = 0;
#ifdef PROG_TUTS
	State.Reg2.bit.SetOutp = 1;           //need set outputs
#endif //PROG_TUTS

#ifdef PROG_DTVM
	State.Reg2.bit.InitCS24 = 0;           // init maked in start
#endif //PROG_DTVM


	State.Reg2.bit.LJ = 0;
	State.Reg2.bit.Parse0 = 0;
	State.Reg2.bit.Parse3 = 0;
	State.Reg2.bit.Parse1 = 0;
 	State.Reg1.bit.Init = 1; //initialize all classes not ended
	State.Reg2.bit.Draw = 1;  //need draw menu
	State.Reg2.bit.Some = 1;
	State.Reg1.bit.ProgMode = 0; //Programmer Mode off.
	State.Reg1.bit.WTBuff1 = 1; //now writted TBuff1.
	State.Reg1.bit.Restart = 0; //Restart Mode off.
	State.Reg1.bit.Mf20Ready = 0; //MF20 blocks are not ready
	KeyRingInterval = 0x2l;
	State.Reg2.bit.DcrBoot = 0; //not boot
	KeyCounter = 3l;
	State.Reg1.bit.EthOff = 0;//ethernet is not off 
	State.Reg1.bit.EthBad = 0;//ethernet is not bad 
 	State.Reg2.bit.WriteId = 0;

#ifdef PROG_BMDN
	State.Reg2.bit.ACMMask0 = 0;
	State.Reg2.bit.FillCFV0 = 0;
	State.Reg2.bit.FillCFV1 = 0;
	State.Reg2.bit.FillCFV2 = 0;
	State.Reg2.bit.FillCFV3 = 0;
	State.Reg2.bit.FillCFV4 = 0;
	State.Reg2.bit.FillCFV5 = 0;
	State.Reg2.bit.FillCFV6 = 0;
	State.Reg2.bit.FillCFV7 = 0;
	State.Reg2.bit.FillCFV8 = 0;

	State.Reg2.bit.ModEth = 0;
#endif //PROG_BMDN

#ifdef PROG_MD310_SATI
State.Reg2.bit.SatSound = 0;
State.Reg2.bit.MAll = 0;
State.Reg2.bit.NamesConfigFiles = 0;
State.Reg2.bit.LoadVariants = 0;
State.Reg2.bit.SaveVariants = 0;
State.Reg2.bit.AnyConfig = 0;	 //working anyconfig
State.Reg2.bit.RAnyConfig = 0;	//for reading to pc only
State.Reg2.bit.CurReadedAnyCofig = 0; //number of readed anyconfig to set this variable - filled readanyconfig for reading
State.Reg2.bit.RAnyConfig1 = 0;
State.Reg2.bit.RAnyConfig2 = 0;
State.Reg2.bit.RAnyConfig3 = 0;
State.Reg2.bit.MRfOut = 0;
State.Reg2.bit.MOutLev = 0;
State.Reg2.bit.MOutLev1 = 0;
State.Reg2.bit.MOutLev2 = 0;
State.Reg2.bit.MKout = 0;
//State.Reg2.bit.MRateE = 0;

State.Reg2.bit.MKout1 = 0;
State.Reg2.bit.MKin1 = 0;
State.Reg2.bit.MKin2 = 0;
State.Reg2.bit.MKin3 = 0;




State.Reg2.bit.MOutLevO = 0;
State.Reg2.bit.MOutLevOS = 0;

State.Reg2.bit.MTDRate = 0;
State.Reg2.bit.MRDRate = 0;
State.Reg2.bit.MTFreq = 0;
State.Reg2.bit.MRFreq = 0;
State.Reg2.bit.MTModul = 0;
State.Reg2.bit.MRModul = 0;
State.Reg2.bit.MTCdType = 0;
State.Reg2.bit.MRCdType = 0;

State.Reg2.bit.MTMode = 0;
State.Reg2.bit.MRMode = 0;



State.Reg2.bit.MTCode = 0;
State.Reg2.bit.MRCode = 0;
State.Reg2.bit.MDemod = 0;
State.Reg2.bit.MEthMode = 0;
State.Reg2.bit.MEthPause = 0;
State.Reg2.bit.MEthctl = 0;
State.Reg2.bit.MEthMaxF = 0;
State.Reg2.bit.MEthVlanP = 0;
State.Reg2.bit.MEbN0 = 0;
State.Reg2.bit.MTEbN0  = 0;
State.Reg2.bit.MBER = 0;
State.Reg2.bit.MTBER = 0;
State.Reg2.bit.MTBERE = 0;
State.Reg2.bit.MAGC = 0;
State.Reg2.bit.MSweep  = 0;
State.Reg2.bit.MEthModeI  = 0;	  //indication
State.Reg2.bit.MEthSend = 0;
State.Reg2.bit.MEthReceived  = 0;
State.Reg2.bit.MIfLoop = 0;
State.Reg2.bit.MUnModul = 0;
State.Reg2.bit.MACMM = 0;
State.Reg2.bit.IFmoduleData = 0;

State.Reg2.bit.MEthReceivedCRC  = 0;
State.Reg2.bit.MEthSendU  = 0;
#endif








#ifdef   STEND_SPI
	State.Reg2.bit.SendBuf = 0;           //send buffer tospi
#endif


#ifdef PROG_BMDN3
	State.Reg2.bit.RAConf0  = 0;
	State.Reg2.bit.RAConf1  = 0;
	State.Reg2.bit.ProtSt0  = 0;
	State.Reg2.bit.ProtSt1  = 0;
	State.Reg2.bit.AcmCnt0  = 0;
	State.Reg2.bit.AcmCnt1  = 0;
	State.Reg2.bit.AcmCntR  = 0;


	State.Reg2.bit.MaskGet0 = 0;
	State.Reg2.bit.MaskGet1 = 0;
	State.Reg2.bit.MaskGetR = 0;
	State.Reg2.bit.AcmEn0   = 0;
	State.Reg2.bit.AcmEn1   = 0;
	State.Reg2.bit.AcmEnR   = 0;
	State.Reg2.bit.AcmPrEn0 = 0;
	State.Reg2.bit.AcmPrEn1 = 0;
	State.Reg2.bit.AcmSw0 = 0;
	State.Reg2.bit.AcmSw1 = 0;
	State.Reg2.bit.AcmSwR = 0;
	State.Reg2.bit.ChPr   = 0;

	State.Reg2.bit.AcmTr0 = 0;
	State.Reg2.bit.AcmTr1 = 0;
	State.Reg2.bit.AcmTrR = 0;
	State.Reg2.bit.RAConfR  = 0;
	State.Reg2.bit.AcmPrEnR = 0;
    State.Reg2.bit.ProtSt = 0;

#endif

#ifdef PROG_BMDN4
	State.Reg2.bit.RAConf0  = 0;
	State.Reg2.bit.RAConf1  = 0;
	State.Reg2.bit.ProtSt0  = 0;
	State.Reg2.bit.ProtSt1  = 0;
	State.Reg2.bit.AcmCnt0  = 0;
	State.Reg2.bit.AcmCnt1  = 0;
	State.Reg2.bit.AcmCntR  = 0;


	State.Reg2.bit.MaskGet0 = 0;
	State.Reg2.bit.MaskGet1 = 0;
	State.Reg2.bit.MaskGetR = 0;
	State.Reg2.bit.AcmEn0   = 0;
	State.Reg2.bit.AcmEn1   = 0;
	State.Reg2.bit.AcmEnR   = 0;
	State.Reg2.bit.AcmPrEn0 = 0;
	State.Reg2.bit.AcmPrEn1 = 0;
	State.Reg2.bit.AcmSw0 = 0;
	State.Reg2.bit.AcmSw1 = 0;
	State.Reg2.bit.AcmSwR = 0;
	State.Reg2.bit.ChPr   = 0;

	State.Reg2.bit.AcmTr0 = 0;
	State.Reg2.bit.AcmTr1 = 0;
	State.Reg2.bit.AcmTrR = 0;
	State.Reg2.bit.RAConfR  = 0;
	State.Reg2.bit.AcmPrEnR = 0;
    State.Reg2.bit.ProtSt = 0;

#endif

#ifdef PROG_PRM_PCH_DEM
	State.Reg2.bit.lxil0 = 0;
	State.Reg2.bit.lxil1 = 0;
	State.Reg2.bit.lxil2 = 0;
#endif //PROG_PRM_PCH_DEM


#ifdef HAVE_GATEWAY
	State.Reg2.bit.Network = 0;
	State.Reg2.bit.NetMask = 0;
#endif // HAVE_GATEWAY

#ifdef PROG_BMDN4
	State.Reg2.bit.OperProg = 0;
 #endif // HAVE_GATEWAY

#ifdef PROG_PU_M710
	State.Reg2.bit.OperProg = 0;
 #endif // HAVE_GATEWAY


#ifdef PROG_PU_MSAT
	State.Reg2.bit.SatSet0 = 0;
	State.Reg2.bit.SatSet1 = 0;
	State.Reg2.bit.SatSet2 = 0;
	State.Reg2.bit.SatSet3 = 0;
	State.Reg2.bit.SatSet4 = 0;
	State.Reg2.bit.SatSet5 = 0;
	State.Reg2.bit.SatSet6 = 0;
	State.Reg2.bit.SatSet7 = 0;
	State.Reg2.bit.SatSet8 = 0;

	State.Reg2.bit.SatTestMode = 0;
	State.Reg2.bit.SatPC = 0;
	State.Reg2.bit.SatTiming = 0;
	State.Reg2.bit.SatSound = 0;
	State.Reg2.bit.SatFactory = 0;
	State.Reg2.bit.SatDF = 0;
	State.Reg2.bit.SatTF = 0;
	State.Reg2.bit.SatRate = 0;
	State.Reg2.bit.SatTimer = 0;
#ifdef RECEIVE_MOD_LOCK

	State.Reg2.bit.SatExtLock = 0;
	State.Reg2.bit.SatExtLockP = 0;
#endif
   State.Reg2.bit.SatLowP = 0;

 State.Reg2.bit.SatALev = 0;
 State.Reg2.bit.SatADemo = 0;
  State.Reg2.bit.SatACode = 0;
   State.Reg2.bit.SatACnt = 0;





	State.Reg2.bit.SatAll = 0;

 #endif // 

#ifdef USE_HTTP
	  State.Reg2.bit.WebPassword = 0;
#endif


#ifdef YOURNAL
	  State.Reg2.bit.LogClear = 0;
#endif



}

extern "C" void ExDt::Set()
{
}
extern "C" void ExDt::LoadDevises()
{
//   	Ring(1,1,5,1);
//   MessageChar(1,1,(State.Reg1.all >> 8));
//   MessageChar(4,1,(State.Reg1.all));		
//   MessageChar(1,2,(State.Reg2.all >> 8));
//   MessageChar(4,2,(State.Reg2.all));	
   if(State.Reg1.bit.Init)
 	{
//	ResetWD();
   //	RedrawCounter = UsedMenu.RedrawPeriod;	
	RedrawCounter = 0;	
 	State.Reg1.bit.Init = 0;
 	}

   if(State.Reg2.bit.Parse0)
 	{
 //	Ring(1,1,5,1);	 //ok
   //  wd_reset();
  // my_int_disable_usart0();

 	Parse0();
 //  my_int_enable_usart0();

 //	my_int_enable_usart0();	
   //  usart0_connecting(1); //connect

 	State.Reg2.bit.Parse0 = 0;
 	}

   if(State.Reg2.bit.Parse3)
 	{
	Parse3();	
 	State.Reg2.bit.Parse3 = 0;
 	}

   if(State.Reg2.bit.Parse1)
 	{
 //	Ring(1,1,5,1);
	Parse1();	
 	State.Reg2.bit.Parse1 = 0;
 	}



 	if(State.Reg2.bit.FU)
  	{
//	ResetWD();
  //	State.Reg2.bit.LDDS = 0;
     OperateFile();
	 State.Reg2.bit.FU = 0;
 	}

	if(State.Reg2.bit.XILR0)
	{
	LoadXILR0();
	State.Reg2.bit.XILR0 = 0;
	}
		
	if(State.Reg2.bit.XILR1)
	{
	LoadXILR1();
	State.Reg2.bit.XILR1 = 0;
	}	

	if(State.Reg2.bit.ParseE)
	{
  //	LoadXILR2();
      ParseE();
	State.Reg2.bit.ParseE = 0;
	}	
	if(State.Reg2.bit.LED)
	{
	LoadLED();
	State.Reg2.bit.LED = 0;
	}
	if(State.Reg2.bit.LJ)
	{
   //	ClearVE();
  // 	LoadAndJump();
	State.Reg2.bit.LJ = 0;
	}	
	
	if(State.Reg2.bit.SSC)
	{
//	for(long t = 0l; t < 100000l; t++ )
//	ResetWD();
  //	LoadDs2174();
//	State.Reg2.bit.SSC = 0;
	 #ifdef PROG_MF20
	  #ifndef PROG_BACO
      SaveCommut2(CurSlot);
	  CurSlot++;
	  if(CurSlot == MF20_SLOTS)
	  {
	   State.Reg2.bit.SSC = 0;
	  }

	  #endif
	 #endif //PROG_MF20

//#ifdef PROG_KTVM
   //   SaveCommut2(CurSlot);
	 // CurSlot++;
	//  if(CurSlot == MF20_SLOTS)
	//  {
	   State.Reg2.bit.SSC = 0;
	//  }
//#endif //PROG_KTVM


 //  #ifdef PROG_TUTS
   //   SaveCommut2(CurSlot);
	 // CurSlot++;
	//  if(CurSlot == MF20_SLOTS)
	//  {
   //	   State.Reg2.bit.SSC = 0;
	//  }
 //	 #endif //PROG_TUTS


 	}
	
 //	if(State.Reg2.bit.Boot)
 //	{
 //	InitBoot();
//not need	State.Reg2.bit.Boot = 0;
 //	}	
	
	if(State.Reg2.bit.Draw)
	{
   		if(!RedrawCounter)
		 {
		//ok printfp("2");
     		RedrawCounter = UsedMenu.RedrawPeriod;
	    	UsedMenu.Draw();
	        State.Reg2.bit.Draw = 0;

	  	 }
	  	 else
	  	 {RedrawCounter--;}
	}

	if(State.Reg2.bit.ChTM)
	{
	   ChangeTestMode();
	   State.Reg2.bit.ChTM = 0;
	}
#ifdef PROG_TUTS
	if(State.Reg2.bit.SetOutp)
	{
	  Set_Outputs((unsigned char) TSOut.Value);
	  State.Reg2.bit.SetOutp = 0;
	}
#endif //PROG_TUTS

#ifdef PROG_DTVM
	if(State.Reg2.bit.InitCS24)
	{
   //	  Init_CS24();
	  State.Reg2.bit.InitCS24 = 0;
	}
#endif //PROG_DTVM




	if(State.Reg2.bit.IP)  //change ip address
	{
   	    RTCS_if_unbind(ihandle0, OldIP);
        RTCS_if_bind(ihandle0, GetIP(), 0xFFFFFF00);
		OldIP = GetIP();
    	State.Reg2.bit.IP = 0;
	 //	dev_restart(); //to test
	}


#ifdef HAVE_GATEWAY

	if(State.Reg2.bit.Network)  //change ip address
	{
   	    RTCS_gate_remove(OldNetwork,(OldNetwork & GetNetMask()), GetNetMask());
   	//	RTCS_gate_add(GetNetwork(),(GetNetwork() & GetNetMask()), GetNetMask());   //for test
		RTCS_gate_add(GetNetwork(),0, 0);   //for test
 		OldNetwork = GetNetwork();
		WriteDevId();
    	State.Reg2.bit.Network = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.NetMask)  //change ip address
	{

   	    RTCS_if_unbind(ihandle0, OldIP);
        RTCS_if_bind(ihandle0, GetIP(), GetNetMask());
		OldIP = GetIP();

   	  //  RTCS_gate_remove(GetNetwork(),(GetNetwork() & OldNetMask), OldNetMask);
	 //	RTCS_gate_add(GetNetwork(),(GetNetwork() & GetNetMask()), GetNetMask());   //for test
	 //	RTCS_gate_add(GetNetwork(),GetNetwork(), GetNetMask());   //for test
 	  	OldNetMask = GetNetMask();
		WriteDevId();

    	State.Reg2.bit.NetMask = 0;
	 //	dev_restart(); //to test
	}



#endif
#ifdef PROG_BMDN4
if(State.Reg2.bit.OperProg)  //change ip address
	{
	  	ParseOperProg();
		timer_oper_prog = TIMER_OPER_PROG;
    	State.Reg2.bit.OperProg = 0;
	 //	dev_restart(); //to test
	}

#endif

#ifdef PROG_PU_M710
if(State.Reg2.bit.OperProg)  //change ip address
	{
	  	ParseOperProg();
		timer_oper_prog = TIMER_OPER_PROG;
    	State.Reg2.bit.OperProg = 0;
	 //	dev_restart(); //to test
	}

#endif





#ifdef PROG_PU_MSAT

/*
	    strcpy(cSatSet0   ,"  Min Distance  :       ");
		strcpy(cSatSet1   ,"  Max Distance  :       ");
		strcpy(cSatSet2   ,"  Output Level  :       ");
		strcpy(cSatSet3   ,"  Averated Distance :   ");
		strcpy(cSatSet4   ,"  Transmit Frequency :  ");
		strcpy(cSatSet5   ,"  Receive Frequency :   ");
		strcpy(cSatSet6   ,"  Transmit Bound:       ");
		strcpy(cSatSet7   ,"  Receive Bound :       ");

	  */


if(State.Reg2.bit.SatSet0)  //change ip address
	{
	//   SetMinDistance();
	   SetFreqProc();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet0 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet1)  //
	{
	   SetSysDelay(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet1 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet2)  //change ip address
	{
	    SetOutLevel(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet2 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet3)  //change ip address
	{
        SetAverDistance(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet3 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatDF)  //change ip address
	{
        SetAverDistance(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatDF = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatTF)  //change ip address
	{
        SetAverDistance(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatTF = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatRate)  //change ip address
	{
        SetSatRate(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatRate = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatTimer)  //change ip address
	{
        SetSatTimer(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatTimer = 0;
	 //	dev_restart(); //to test
	}

#ifdef RECEIVE_MOD_LOCK

if(State.Reg2.bit.SatExtLock)  //change ip address
	{
        SetSatExtLock(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatExtLock = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatExtLockP)  //change ip address
	{
        SetSatExtLockP(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatExtLockP = 0;
	 //	dev_restart(); //to test
	}

#endif

   if(State.Reg2.bit.SatLowP)  //change ip address
	{
        SetSatLowP(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatLowP = 0;
	 //	dev_restart(); //to test
	}

 if(State.Reg2.bit.SatALev)  //
	{
        SetSatALev(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatALev = 0;
	 //	dev_restart(); //to test
	}

 if(State.Reg2.bit.SatADemo)  //
	{
        SetSatADemo(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatADemo = 0;
	 //	dev_restart(); //to test
	}

 if(State.Reg2.bit.SatACode)  //
	{
        SetSatACode(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatACode = 0;
	 //	dev_restart(); //to test
	}

 if(State.Reg2.bit.SatACnt)  //
	{
        SetSatACnt(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatACnt = 0;
	 //	dev_restart(); //to test
	}







if(State.Reg2.bit.SatSet4)  //change ip address
	{
	      SetTrFrequency(); 

	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet4 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet5)  //change ip address
	{
	      SetRcvFrequency(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet5 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet6)  //change ip address
	{
	   	 SetTrBound(); 
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet6 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet7)  //change ip address
	{
	   SetRcvBound();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet7 = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSet8)  //change ip address
	{
	   SetOffset();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSet8 = 0;
	 //	dev_restart(); //to test
	}


if(State.Reg2.bit.SatTestMode)  //
	{
	   SetSatTestMode();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatTestMode = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatTiming)  //
	{
	   SetSatTiming();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatTiming = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatSound)  //
	{
	   SetSatSound();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSound = 0;
	 //	dev_restart(); //to test
	}

if(State.Reg2.bit.SatFactory)  //
	{
	   SetSatFactory();
	 //some for make
	//   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatFactory = 0;
	 //	dev_restart(); //to test
	}
/*
#ifdef YOURNAL
if(State.Reg2.bit.LogClear)  //
	{
	 //  SetLogClear();
	 //some for make
	//   State.Reg2.bit.WriteId = 1;

#ifdef DEB_LOG

printfp("\n\r bit.LogClear = 1");
#endif


	if(LogClear.Value)
	{
	 ClearYournal();

   //		 dev1.pum100s1.LogClearr0 = 	0;


	 LogClear.Value = 0;
	 LogClear.ChangingValue = 0;

	}

	   	State.Reg2.bit.LogClear = 0;
	 //	dev_restart(); //to test
	}


#endif
  */
if(State.Reg2.bit.SatAll)  //
	{
	//hier need set calling all funktions
	 //  SetSatTiming();
	   //some for make
   //	  CheckRestoringData();  //check all setted data
      LoadDDSs(); //need to make at start full loading ddss
      StartLoadAll();

	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatAll = 0;
	 //	dev_restart(); //to test
	}



if(State.Reg2.bit.SatPC)  //
	{
	   SetSatPC();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatPC = 0;
	 //	dev_restart(); //to test
	}




#endif



#ifdef YOURNAL
if(State.Reg2.bit.LogClear)  //
	{
	 //  SetLogClear();
	 //some for make
	//   State.Reg2.bit.WriteId = 1;

#ifdef DEB_LOG

printfp("\n\r bit.LogClear = 1");
#endif


	if(LogClear.Value)
	{
	 ClearYournal();

   //		 dev1.pum100s1.LogClearr0 = 	0;


	 LogClear.Value = 0;
	 LogClear.ChangingValue = 0;

	}

	   	State.Reg2.bit.LogClear = 0;
	 //	dev_restart(); //to test
	}


#endif


//___________________________________________________________
   if(State.Reg2.bit.WriteId)  //change ip address
	{
   	    WriteDevId();
#ifdef 	PROG_MD310_SATI
        KeepParamsInIFModule();
#endif
    	State.Reg2.bit.WriteId = 0;
	 //	dev_restart(); //to test
	}

#ifdef PROG_BMDN3

if(State.Reg2.bit.RAConf0)  //
	{
 #ifndef PROG_BMDN6MI
	  DevAcmConfigurationGet(0);
 #endif
  	  State.Reg2.bit.RAConf0 = 0;
	}

if(State.Reg2.bit.RAConfR)  //
	{
	#ifndef PROG_BMDN6MI
	  DevAcmConfigurationGet(ldeviceindex1);
	  #endif
  	  State.Reg2.bit.RAConfR = 0;
	}



if(State.Reg2.bit.RAConf1)  //
	{
	#ifndef PROG_BMDN6MI
      DevAcmConfigurationGet(1);
#endif
  	  State.Reg2.bit.RAConf1 = 0;
	}

if(State.Reg2.bit.ProtSt0)  //
	{
   //   DevAcmConfigurationGet(1);
#ifndef PROG_BMDN6MI
   GetRxPhyId(0);
#endif
  	  State.Reg2.bit.ProtSt0 = 0;
	}

if(State.Reg2.bit.ProtSt1)  //
	{
   //   DevAcmConfigurationGet(1);
#ifndef PROG_BMDN6MI
   GetRxPhyId(1);
#endif
  	  State.Reg2.bit.ProtSt1 = 0;
	}


if(State.Reg2.bit.AcmCnt0)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(0);
  	  State.Reg2.bit.AcmCnt0 = 0;
	}

if(State.Reg2.bit.AcmCnt1)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(1);
  	  State.Reg2.bit.AcmCnt1 = 0;
	}

if(State.Reg2.bit.AcmCntR)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(ldeviceindex8);
  	  State.Reg2.bit.AcmCntR = 0;
	}



if(State.Reg2.bit.MaskGet0)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmProfileMaskGet(0);
  	  State.Reg2.bit.MaskGet0 = 0;
	}

if(State.Reg2.bit.MaskGet1)  //
	{
   //   DevAcmConfigurationGet(1);
      ModemAcmProfileMaskGet(1);
  	  State.Reg2.bit.MaskGet1 = 0;
	}

if(State.Reg2.bit.MaskGetR)  //
	{
   //   DevAcmConfigurationGet(1);
      ModemAcmProfileMaskGet(ldeviceindex4);
  	  State.Reg2.bit.MaskGetR = 0;
	}


if(State.Reg2.bit.AcmEn0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 ModemAcmEngineEnable(0, 1, 1);
  	  State.Reg2.bit.AcmEn0 = 0;
	}


if(State.Reg2.bit.AcmEn1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
      ModemAcmEngineEnable(1, 1, 1);
  	  State.Reg2.bit.AcmEn1 = 0;
	}

if(State.Reg2.bit.AcmEnR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
        ProtectionOff(ldeviceindex3);
        ModemAcmEngineEnable(ldeviceindex3, lrx, ltx);
        ProtectionOn(ldeviceindex3);
  	    State.Reg2.bit.AcmEnR = 0;
	}


if(State.Reg2.bit.AcmPrEn0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
      ModemAcmProfileEnable(0 , 0xFFFF);
  	  State.Reg2.bit.AcmPrEn0 = 0;
	}


if(State.Reg2.bit.AcmPrEn1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmProfileEnable(0 , 0xFFFF);
  	  State.Reg2.bit.AcmPrEn1 = 0;
	}

if(State.Reg2.bit.AcmPrEnR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ProtectionOff(ldeviceindex2);
  ModemAcmEngineEnable(ldeviceindex2,0, 0);	//tx enable olwais!!!!!
  		ModemAcmProfileEnable(ldeviceindex2 , lprofile2);
  ModemAcmEngineEnable(ldeviceindex2,1, 1);	//tx enable olwais!!!!!
     ProtectionOn(ldeviceindex2);

  	    State.Reg2.bit.AcmPrEnR = 0;
	}


if(State.Reg2.bit.AcmSw0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmSwitch(0, 0, 0);
  	  State.Reg2.bit.AcmSw0 = 0;
	}

if(State.Reg2.bit.AcmSw1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmSwitch(1, 0, 0);
  	  State.Reg2.bit.AcmSw1 = 0;
	}

if(State.Reg2.bit.AcmSwR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
   ProtectionOff(ldeviceindex5);
   ModemAcmEngineEnable(ldeviceindex5,0, 0);
   ModemAcmSwitch(ldeviceindex5, lacmprofile, lislocal );
   ModemAcmEngineEnable(ldeviceindex5,1, 1);
   ProtectionOn(ldeviceindex5);

  	  State.Reg2.bit.AcmSwR = 0;
	}

if(State.Reg2.bit.ChPr)  //
	{
      ChProt(ldeviceindex6, lprot);
  	  State.Reg2.bit.ChPr = 0;
	}



if(State.Reg2.bit.AcmTr0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 	ModemAcmThresholdSet(0, 0, 0, 0, 0,  0,  0, 1);
   	  State.Reg2.bit.AcmTr0 = 0;
	}

if(State.Reg2.bit.AcmTr1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 	ModemAcmThresholdSet(1, 0, 0, 0, 0,  0,  0, 1);
   	  State.Reg2.bit.AcmTr1 = 0;
	}

if(State.Reg2.bit.AcmTrR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 ProtectionOff(ldeviceindex);
   ModemAcmEngineEnable(ldeviceindex,0, 1);	//tx enable olwais!!!!!
   ModemAcmThresholdSet( //1, 0, 0, 0, 0,  0,  0, 1);
				ldeviceindex,
 				lengineTable,
 				lprofile,
 				lmseTenthsVal,
				lldpcMantissaTenths,
 				lldpcExponent,
 				lcriteria,
 				lnextProfile);
   ModemAcmEngineEnable(ldeviceindex,1, 1);	//tx enable olwais!!!!!
     ProtectionOn(ldeviceindex);

   State.Reg2.bit.AcmTrR = 0;
	}

if(State.Reg2.bit.ProtSt)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  //	ModemAcmThresholdSet(1, 0, 0, 0, 0,  0,  0, 1);
#ifndef PROG_BMDN6MI

      GetRxPhyId(ldeviceindex7);
#endif
   	  State.Reg2.bit.ProtSt = 0;
	}

#endif

#ifdef PROG_BMDN4

if(State.Reg2.bit.RAConf0)  //
	{
 #ifndef PROG_BMDN6MI
	  DevAcmConfigurationGet(0);
#endif
  	  State.Reg2.bit.RAConf0 = 0;
	}

if(State.Reg2.bit.RAConfR)  //
	{
	#ifndef PROG_BMDN6MI
	  DevAcmConfigurationGet(ldeviceindex1);
	  #endif
  	  State.Reg2.bit.RAConfR = 0;
	}



if(State.Reg2.bit.RAConf1)  //
	{
	#ifndef PROG_BMDN6MI
      DevAcmConfigurationGet(1);
	  #endif
  	  State.Reg2.bit.RAConf1 = 0;
	}

if(State.Reg2.bit.ProtSt0)  //
	{
   //   DevAcmConfigurationGet(1);
#ifndef PROG_BMDN6MI

   GetRxPhyId(0);

#endif
  	  State.Reg2.bit.ProtSt0 = 0;
	}

if(State.Reg2.bit.ProtSt1)  //
	{
   //   DevAcmConfigurationGet(1);
#ifndef PROG_BMDN6MI

   GetRxPhyId(1);
#endif
  	  State.Reg2.bit.ProtSt1 = 0;
	}


if(State.Reg2.bit.AcmCnt0)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(0);
  	  State.Reg2.bit.AcmCnt0 = 0;
	}

if(State.Reg2.bit.AcmCnt1)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(1);
  	  State.Reg2.bit.AcmCnt1 = 0;
	}

if(State.Reg2.bit.AcmCntR)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmCountersGet(ldeviceindex8);
  	  State.Reg2.bit.AcmCntR = 0;
	}



if(State.Reg2.bit.MaskGet0)  //
	{
   //   DevAcmConfigurationGet(1);
  ModemAcmProfileMaskGet(0);
  	  State.Reg2.bit.MaskGet0 = 0;
	}

if(State.Reg2.bit.MaskGet1)  //
	{
   //   DevAcmConfigurationGet(1);
      ModemAcmProfileMaskGet(1);
  	  State.Reg2.bit.MaskGet1 = 0;
	}

if(State.Reg2.bit.MaskGetR)  //
	{
   //   DevAcmConfigurationGet(1);
      ModemAcmProfileMaskGet(ldeviceindex4);
  	  State.Reg2.bit.MaskGetR = 0;
	}


if(State.Reg2.bit.AcmEn0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 ModemAcmEngineEnable(0, 1, 1);
  	  State.Reg2.bit.AcmEn0 = 0;
	}


if(State.Reg2.bit.AcmEn1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
      ModemAcmEngineEnable(1, 1, 1);
  	  State.Reg2.bit.AcmEn1 = 0;
	}

if(State.Reg2.bit.AcmEnR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
        ProtectionOff(ldeviceindex3);
        ModemAcmEngineEnable(ldeviceindex3, lrx, ltx);
        ProtectionOn(ldeviceindex3);
  	    State.Reg2.bit.AcmEnR = 0;
	}


if(State.Reg2.bit.AcmPrEn0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
      ModemAcmProfileEnable(0 , 0xFFFF);
  	  State.Reg2.bit.AcmPrEn0 = 0;
	}


if(State.Reg2.bit.AcmPrEn1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmProfileEnable(0 , 0xFFFF);
  	  State.Reg2.bit.AcmPrEn1 = 0;
	}

if(State.Reg2.bit.AcmPrEnR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ProtectionOff(ldeviceindex2);
  ModemAcmEngineEnable(ldeviceindex2,0, 0);	//tx enable olwais!!!!!
  		ModemAcmProfileEnable(ldeviceindex2 , lprofile2);
  ModemAcmEngineEnable(ldeviceindex2,1, 1);	//tx enable olwais!!!!!
     ProtectionOn(ldeviceindex2);

  	    State.Reg2.bit.AcmPrEnR = 0;
	}


if(State.Reg2.bit.AcmSw0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmSwitch(0, 0, 0);
  	  State.Reg2.bit.AcmSw0 = 0;
	}

if(State.Reg2.bit.AcmSw1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  ModemAcmSwitch(1, 0, 0);
  	  State.Reg2.bit.AcmSw1 = 0;
	}

if(State.Reg2.bit.AcmSwR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
   ProtectionOff(ldeviceindex5);
   ModemAcmEngineEnable(ldeviceindex5,0, 0);
   ModemAcmSwitch(ldeviceindex5, lacmprofile, lislocal );
   ModemAcmEngineEnable(ldeviceindex5,1, 1);
   ProtectionOn(ldeviceindex5);

  	  State.Reg2.bit.AcmSwR = 0;
	}

if(State.Reg2.bit.ChPr)  //
	{
      ChProt(ldeviceindex6, lprot);
  	  State.Reg2.bit.ChPr = 0;
	}



if(State.Reg2.bit.AcmTr0)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 	ModemAcmThresholdSet(0, 0, 0, 0, 0,  0,  0, 1);
   	  State.Reg2.bit.AcmTr0 = 0;
	}

if(State.Reg2.bit.AcmTr1)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 	ModemAcmThresholdSet(1, 0, 0, 0, 0,  0,  0, 1);
   	  State.Reg2.bit.AcmTr1 = 0;
	}

if(State.Reg2.bit.AcmTrR)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
 ProtectionOff(ldeviceindex);
   ModemAcmEngineEnable(ldeviceindex,0, 1);	//tx enable olwais!!!!!
   ModemAcmThresholdSet( //1, 0, 0, 0, 0,  0,  0, 1);
				ldeviceindex,
 				lengineTable,
 				lprofile,
 				lmseTenthsVal,
				lldpcMantissaTenths,
 				lldpcExponent,
 				lcriteria,
 				lnextProfile);
   ModemAcmEngineEnable(ldeviceindex,1, 1);	//tx enable olwais!!!!!
     ProtectionOn(ldeviceindex);

   State.Reg2.bit.AcmTrR = 0;
	}

if(State.Reg2.bit.ProtSt)  //
	{
   //   DevAcmConfigurationGet(1);
 //     ModemAcmProfileMaskGet(1);
  //	ModemAcmThresholdSet(1, 0, 0, 0, 0,  0,  0, 1);
#ifndef PROG_BMDN6MI

      GetRxPhyId(ldeviceindex7);
#endif
   	  State.Reg2.bit.ProtSt = 0;
	}

#endif



#ifdef PROG_BMDN

if(State.Reg2.bit.ModEth)  //
	{
  //	   SetOffset();
	   //some for make
	   StartEthTimed(0);
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.ModEth = 0;
	 //	dev_restart(); //to test
	}


	if(State.Reg2.bit.FillCFV0)  //
	{
  //do not need read; we are writen now!!!! it can be make damage 
  //	  FillConfigFileVersion();	//do not change some
	  /*
	  if(ModemIsUsed(0))
	  {
  //	  LoadSyntmf(GetNumConfigFile(0), 0);	//101012
	  ConfigFileLoadm(GetNumConfigFile(0), 0);	 //to all plats - temporary?
	  ConfigFileRunm(0);
	  }
		*/
	  StartNewConfigFile(0);
	  State.Reg2.bit.FillCFV0 = 0;
	}

if(State.Reg2.bit.ACMMask0)  //
	{
   	//  FillConfigFileVersion();
	  /*
	  if(ModemIsUsed(0))
	  {
  //	  LoadSyntmf(GetNumConfigFile(0), 0);	//101012
	  ConfigFileLoadm(GetNumConfigFile(0), 0);	 //to all plats - temporary?
	  ConfigFileRunm(0);
	  }
		*/
	  SetACMMask(0,acmmask0);
	  SetACMMask(1,acmmask0);
	  State.Reg2.bit.ACMMask0 = 0;
	}

 

	if(State.Reg2.bit.FillCFV1)  //
	{
 //  	  FillConfigFileVersion();
 /*
  if(ModemIsUsed(1))
	  {
  //	  LoadSyntmf(GetNumConfigFile(1), 1);	//101012
	  ConfigFileLoadm(GetNumConfigFile(1), 1);	 //to all plats - temporary?
	  ConfigFileRunm(1);
	  }
	  */

#ifndef PROG_MD310_SATI2	
	  StartNewConfigFile(1);
#else
	  StartNewConfigFile(0); //different config files for one modem
#endif



	  State.Reg2.bit.FillCFV1 = 0;
	}

	if(State.Reg2.bit.FillCFV2)  //
	{
 //  	  FillConfigFileVersion();
 /*
  if(ModemIsUsed(2))
	  {
  //	  LoadSyntmf(GetNumConfigFile(2), 2);	//101012
	  ConfigFileLoadm(GetNumConfigFile(2), 2);	 //to all plats - temporary?
	  ConfigFileRunm(2);
	  }
	  */
	  StartNewConfigFile(2);
	  State.Reg2.bit.FillCFV2 = 0;
	}

	if(State.Reg2.bit.FillCFV3)  //
	{
 //  	  FillConfigFileVersion();
 /*
 if(ModemIsUsed(3))
	  {
  //	  LoadSyntmf(GetNumConfigFile(3), 3);	//101012
	  ConfigFileLoadm(GetNumConfigFile(3), 3);	 //to all plats - temporary?
	  ConfigFileRunm(3);
	  }
	  */
	  StartNewConfigFile(3);
	  State.Reg2.bit.FillCFV3 = 0;
	}

	if(State.Reg2.bit.FillCFV4)  //
	{
 //  	  FillConfigFileVersion();
 /*
 if(ModemIsUsed(4))
	  {
  //	  LoadSyntmf(GetNumConfigFile(4), 4);	//101012
	  ConfigFileLoadm(GetNumConfigFile(4), 4);	 //to all plats - temporary?
	  ConfigFileRunm(4);
	  }
	  */
	  StartNewConfigFile(4);
	  State.Reg2.bit.FillCFV4 = 0;
	}

	if(State.Reg2.bit.FillCFV5)  //
	{
 //  	  FillConfigFileVersion();
 /*
 if(ModemIsUsed(5))
	  {
  //	  LoadSyntmf(GetNumConfigFile(5), 5);	//101012
	  ConfigFileLoadm(GetNumConfigFile(5), 5);	 //to all plats - temporary?
	  ConfigFileRunm(5);
	  }
	  */
	  StartNewConfigFile(5);
	  State.Reg2.bit.FillCFV5 = 0;
	}

	if(State.Reg2.bit.FillCFV6)  //
	{
//   	  FillConfigFileVersion();
/*
 if(ModemIsUsed(6))
	  {
  //	  LoadSyntmf(GetNumConfigFile(6), 6);	//101012
	  ConfigFileLoadm(GetNumConfigFile(6), 6);	 //to all plats - temporary?
	  ConfigFileRunm(6);
	  }
	  */
	  StartNewConfigFile(6);
	  State.Reg2.bit.FillCFV6 = 0;
	}

	if(State.Reg2.bit.FillCFV7)  //
	{
//   	  FillConfigFileVersion();
/*
 	if(ModemIsUsed(7))
	  {
  //	  LoadSyntmf(GetNumConfigFile(7), 7);	//101012
	  ConfigFileLoadm(GetNumConfigFile(7), 7);	 //to all plats - temporary?
	  ConfigFileRunm(7);
	  }
	  */
	  StartNewConfigFile(7);
	  State.Reg2.bit.FillCFV7 = 0;
	}

if(State.Reg2.bit.FillCFV8)  //
	{
//   	  FillConfigFileVersion();
/*
 	if(ModemIsUsed(8))
	  {
  //	  LoadSyntmf(GetNumConfigFile(8), 8);	//101012
	  ConfigFileLoadm(GetNumConfigFile(8), 8);	 //to all plats - temporary?
	  ConfigFileRunm(8);
	  }
	  */
	  StartNewConfigFile(8);
	  State.Reg2.bit.FillCFV8 = 0;
	}



#endif //PROG_BMDN


#ifdef PROG_MD310_SATI

if(State.Reg2.bit.SatSound)  //
	{
	   SetSatSound();
	   //some for make
	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.SatSound = 0;
	 //	dev_restart(); //to test
	}




if(State.Reg2.bit.MAll)  //
	{
	//hier need set calling all funktions
	 //  SetSatTiming();
	   //some for make
   //	  CheckRestoringData();  //check all setted data
 //     LoadDDSs(); //need to make at start full loading ddss
      StartLoadAllM();

	   State.Reg2.bit.WriteId = 1;

	   	State.Reg2.bit.MAll = 0;
	 //	dev_restart(); //to test
	}


if(State.Reg2.bit.NamesConfigFiles)  //
	{




    State.Reg2.bit.NamesConfigFiles = 0;
	}
if(State.Reg2.bit.LoadVariants)  //
	{

	    SetLoadVariants();

	State.Reg2.bit.LoadVariants = 0;
	}

if(State.Reg2.bit.SaveVariants)  //
	{
	  SetSaveVariants();

	State.Reg2.bit.SaveVariants = 0;
	}

if(State.Reg2.bit.AnyConfig)  //
	{


	State.Reg2.bit.AnyConfig = 0;	 //working anyconfig
	}

if(State.Reg2.bit.RAnyConfig)  //
	{


	State.Reg2.bit.RAnyConfig = 0;	//for reading to pc only
	}

if(State.Reg2.bit.CurReadedAnyCofig)  //
	{


	State.Reg2.bit.CurReadedAnyCofig = 0; //number of readed anyconfig to set this variable - filled readanyconfig for reading
	}



if(State.Reg2.bit.RAnyConfig1)  //
	{


	State.Reg2.bit.RAnyConfig1 = 0;
	}


if(State.Reg2.bit.RAnyConfig2)  //
	{


	State.Reg2.bit.RAnyConfig2 = 0;
	}


if(State.Reg2.bit.RAnyConfig3)  //
	{


	State.Reg2.bit.RAnyConfig3 = 0;
	}


if(State.Reg2.bit.MRfOut)  //
	{
	     SetMRfOut();

	  State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MRfOut = 0;
	}




if(State.Reg2.bit.MOutLev1)  //
	{

	  SetMOutLev1();
	  State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MOutLev1 = 0;
	}

if(State.Reg2.bit.MOutLev1)  //
	{

	  SetMOutLev2();
	  State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MOutLev2 = 0;
	}

if(State.Reg2.bit.MKout)  //
	{

	  SetMKout();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MKout = 0;
	}

if(State.Reg2.bit.MKout1)  //
	{

	  SetMKout1();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MKout1 = 0;
	}

if(State.Reg2.bit.MKin1)  //
	{

	  SetMKin1();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MKin1 = 0;
	}



if(State.Reg2.bit.MKin2)  //
	{

	  SetMKin2();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MKin2 = 0;
	}


if(State.Reg2.bit.MKin3)  //
	{

	  SetMKin3();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MKin3 = 0;
	}




 /*

if(State.Reg2.bit.MRateE)  //
	{

	  SetMRateE();
	    State.Reg2.bit.WriteId = 1;

	  State.Reg2.bit.MRateE = 0;
	}


  */


if(State.Reg2.bit.MOutLevO)  //
	{

	  SetMOutLev();
	   State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MOutLevO = 0;
	}

if(State.Reg2.bit.MOutLevOS)  //
	{

	  SetMOutLev();
	   State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MOutLevOS = 0;
	}

if(State.Reg2.bit.MOutLev)  //
	{

	  SetMOutLev();
	     State.Reg2.bit.WriteId = 1;

	State.Reg2.bit.MOutLev = 0;
	}





if(State.Reg2.bit.MTDRate)  //
	{
	  SetMTDRate();


	State.Reg2.bit.MTDRate = 0;
	}


if(State.Reg2.bit.MRDRate)  //
	{

	 SetMRDRate();
	State.Reg2.bit.MRDRate = 0;
	}



if(State.Reg2.bit.MTFreq)  //
	{
	  SetMTFreq();

	State.Reg2.bit.MTFreq = 0;
	}


if(State.Reg2.bit.MRFreq)  //
	{
	  SetMRFreq();


	State.Reg2.bit.MRFreq = 0;
	}



if(State.Reg2.bit.MTModul)  //
	{
	   SetMTModul();
	State.Reg2.bit.MTModul = 0;
	}
	 
if(State.Reg2.bit.MTCdType)  //
	{
	   SetMTCdType();
	State.Reg2.bit.MTCdType = 0;
	}

if(State.Reg2.bit.MRCdType)  //
	{
	   SetMRCdType();
	State.Reg2.bit.MRCdType = 0;
	}

if(State.Reg2.bit.MTMode)  //
	{
	   SetMTMode();
	State.Reg2.bit.MTMode= 0;
	}

if(State.Reg2.bit.MRMode)  //
	{
	   SetMRMode();
	State.Reg2.bit.MRMode= 0;
	}

if(State.Reg2.bit.MRCntl)  //
	{
	   SetMRMode();
	State.Reg2.bit.MRCntl= 0;
	}







if(State.Reg2.bit.MRModul)  //
	{

	   SetMRModul();

	State.Reg2.bit.MRModul = 0;
	}


if(State.Reg2.bit.MTCode)  //
	{
	  SetMTCode();

	State.Reg2.bit.MTCode = 0;
	}


if(State.Reg2.bit.MRCode)  //
	{
	  SetMRCode();

	State.Reg2.bit.MRCode = 0;
	}


if(State.Reg2.bit.MDemod)  //
	{

	   SetMDemod();

	State.Reg2.bit.MDemod = 0;
	}
	

if(State.Reg2.bit.MEthMode)  //
	{

	   SetMEthMode();

	State.Reg2.bit.MEthMode = 0;
	}


if(State.Reg2.bit.MEthPause)  //
	{

	 SetMEthPause();

	State.Reg2.bit.MEthPause = 0;
	}
	
	
	
if(State.Reg2.bit.MEthctl)  //
	{
	  SetMEthctl();


	State.Reg2.bit.MEthctl = 0;
	}


if(State.Reg2.bit.MEthMaxF)  //
	{

	  SetMEthMaxF();

	State.Reg2.bit.MEthMaxF = 0;
	}


if(State.Reg2.bit.MEthVlanP)  //
	{
	   SetMEthVlanP();


	State.Reg2.bit.MEthVlanP = 0;
	}


if(State.Reg2.bit.MEbN0)  //
	{


	State.Reg2.bit.MEbN0 = 0;
	}


if(State.Reg2.bit.MTEbN0)  //
	{
	  SetMTEbN0();


	State.Reg2.bit.MTEbN0  = 0;
	}


if(State.Reg2.bit.MBER)  //
	{


	State.Reg2.bit.MBER = 0;
	}


if(State.Reg2.bit.MTBER)  //
	{
	   SetMTBER();

	State.Reg2.bit.MTBER = 0;
	}


if(State.Reg2.bit.MTBERE)  //
	{

	  SetMTBERE();

	State.Reg2.bit.MTBERE = 0;
	}


if(State.Reg2.bit.MAGC)  //
	{


	State.Reg2.bit.MAGC = 0;
	}


if(State.Reg2.bit.MSweep)  //
	{


	State.Reg2.bit.MSweep  = 0;
	}
	
	
	
if(State.Reg2.bit.MEthModeI)  //
	{

	State.Reg2.bit.MEthModeI  = 0;	  //indication
	}




if(State.Reg2.bit.MEthSend)  //
	{


	State.Reg2.bit.MEthSend = 0;
	}


if(State.Reg2.bit.MEthReceived)  //
	{


	State.Reg2.bit.MEthReceived  = 0;
	}

if(State.Reg2.bit.MEthReceivedCRC)  //
	{


	State.Reg2.bit.MEthReceivedCRC  = 0;
	}

if(State.Reg2.bit.MEthSendU)  //
	{


	State.Reg2.bit.MEthSendU  = 0;
	}





if(State.Reg2.bit.MIfLoop)  //
	{
    SetMIfLoop();
	State.Reg2.bit.MIfLoop = 0;
	}



if(State.Reg2.bit.MUnModul)  //
	{
    SetMUnModul();
	State.Reg2.bit.MUnModul = 0;
	}





if(State.Reg2.bit.MACMM)  //
	{
	 SetMACMM();

	State.Reg2.bit.MACMM = 0;
	}



if(State.Reg2.bit.IFmoduleData)  //
	{

 //	WriteIFmoduleData();
	State.Reg2.bit.IFmoduleData = 0;
	}


#endif







#ifdef   STEND_SPI
if(State.Reg2.bit.SendBuf)  //
	{
	  SendSSCBuff();
	  State.Reg2.bit.SendBuf = 0;
	}
#endif






#ifdef PROG_PRM_PCH_DEM
	if(State.Reg2.bit.lxil0)  //
	{
	  m_load_xilinx4(1,0); //load xilinx1 to file1
	  State.Reg2.bit.lxil0 = 0;
	}

	if(State.Reg2.bit.lxil1)  //
	{
	  m_load_xilinx4(2,0); //load xilinx1 to file2
	  State.Reg2.bit.lxil1 = 0;
	}

	if(State.Reg2.bit.lxil2)  //
	{
	  m_load_xilinx5(3,0); //3,0); //inx3,4 to file3
	  State.Reg2.bit.lxil2 = 0;
	}

#endif //PROG_PRM_PCH_DEM






//___________________________________________________________






  //	State.Reg2.bit.NIRQ = 0; //t0711
if(State.Reg2.bit.NIRQ)   //need run irq 2
{
  //	    delay_mcs(100);	
 // 	 static int pult_cnt;	//t
 //	 if(pult_cnt < 10)
 //  	 {
 // 	 pult_cnt++;
 //  	 }
 //  	 else
 //  	 {
 //  	 pult_cnt = 0;
	   // Ring(1,1,5,1);

  // 	  unsigned char chps; 
 //  	  	embIndicator.IsrXX();
 
  //t	embIndicator.IsrXX(); //to use embisr
   
 //____________________________________ 
  //   chps = UsedPult.GetDataChar();

 /*
	    chps = UsedPult.GetControlChar();

		if(chps & 0x02) //key pressed
		{
		   chps = UsedPult.GetDataChar();
 		}
		else
		{
	        UsedPult.SendDataChar('S'); //t
		}
   */
 //_______________________________________
//    _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR); 

  //  PultDelay();
   //	  UsedPult.Key = UsedPult.GetDataChar();	//t

/*	  to not hangt	*/
   UsedPult.PultCRd.all = UsedPult.GetControlChar();
 //	  delay_mcs(100);	
	if(!UsedPult.PultCRd.bit.RI)
  //transmit
   {
	 if(CntIBuff)
	 {
	 //ok	  delay_mcs(100);
//bad	  delay_mcs(10);
 //bad		 delay_mcs(50);
  //t		   delay_mcs(75);		//ok

//___________________________________________________________________!!!!!!NEED DELETE DELAY!!!!		  	
		  write_xil_char((uint_32)(PKU_ADDR),IBuff[urIBuff++]);
		  if(urIBuff >= IBUFFSIZE) {urIBuff = 0;}
		  CntIBuff--;
	 }
 //	  else  if(*pcStr4)	   //item up
 //	 {
 //	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr4));
 //	   pcStr4++;
 // 	 }
 //	    else if(*pcStr5)   //item down
 //	 {
 //	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr5));
 //	   pcStr5++;
 // 	 }
// 	   else if(*pcStr3)	  //ticket
//	 {
//	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr3));
//	   pcStr3++;
//  	 }
//	  else  if(*pcStr)	//data
//	 {
//	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr));
//	   pcStr++;
//  	 }
//     else if(*pcStr2)
//	 {
//	   write_xil_char((uint_32)(PKU_ADDR), (char)(*pcStr2));
//	   pcStr2++;
//  	 }
   
	 else
	 {
	   UsedPult.PultCWr.bit.TI = 0;	   //get off transmit interrupt
       UsedPult.SendControlChar(UsedPult.PultCWr.all);
	 }
   }
   else //	if(UsedPult.PultCRd.bit.RI)	   //ignore keys if make transmit
   {	
    UsedPult.Key = UsedPult.GetDataChar();
  //  write_xil_char((uint_32)(PKU_ADDR), (char)(0x55));	//t
   //printEthLongHex(7);
    ticket_on();
    UsedPult.State.KeyPr = 1; //key is pressed
    }


 
   /*
	if(UsedPult.TBufferCnt)
	{
	 write_xil_char((uint_32)(PKU_ADDR), (char)(*UsedPult.pTBuffer));
	 UsedPult.pTBuffer--;
	 UsedPult.TBufferCnt--;
  	}
	else
	{
      UsedPult.PultCWr.bit.TI = 0;	 //not request transmit interrupt
      UsedPult.SendControlChar(UsedPult.PultCWr.all);
	}
	 */
    /*	*/
//________________________________________
 //  _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
   //      				      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
     //           	  				      AT91RM9200_AIC_SMR_PRIO_MIN );  



	if(!PultInts)
	{
   	State.Reg2.bit.NIRQ = 0;
	}
	else
	{
	PultInts--;
	}
 //  		printf(".");			 //t
	//   UsedPult.ReplaceChar('R');	//t
	 //	 UsedPult.SendDataChar('R');
	 //	dev_restart(); //to test
// 	 } //pult_cnt
 	my_int_enable_irq2();
}

#ifndef PROG_BMDN3	
#ifndef PROG_BMDN4
    if((!State.Reg2.bit.NIRQ) && (!State.Reg2.bit.Draw)
      && (!State.Reg2.bit.SSC)
    )
    {	
	State.Reg2.bit.Some = 0; //all loaded
	}
#else
   State.Reg2.bit.Some = 0;
#endif
#else
   State.Reg2.bit.Some = 0;
#endif


}

//extern "C" void ExDt::ClearVE()
//{
//}

extern "C" void ExDt::LoadLED()
{
  //	unsigned char tmp = 0xfd;
 //	if(!State.Reg1.bit.Sync) tmp &= 0xfe; //led "RLoss" on
 //	if(State.Reg1.bit.All1s) tmp &= 0xf7; //led "all1s" on
 //	if(State.Reg1.bit.All0s) tmp &= 0xfb; //led "all0s" on	
}

extern "C" void ExDt::Zummer(unsigned char move)
{
  /*
	if(!move) //off
	{
		UsedExp.State.Reg1.bit.Zumm  = 0; //zummer 
 	}
	else //on
	{
	//	ExpertRegs.XILR2 = 0x1; //zummer on - temporary hier
 		UsedExp.State.Reg1.bit.Zumm  = 1; //zummer on
// 		KeyRingCounter = KeyRingInterval;
 		KeyCounter = KeyRingInterval;
 	}

	  //  UsedExp.State.Reg1.bit.Zumm = move ? 1 : 0;
		UsedExp.State.Reg2.bit.XILR2 = 1; //need load xilr2
  		UsedExp.State.Reg2.bit.Some = 1; //need some update
  		LoadDevises();
	 */
}
extern "C" void ExDt::CheckLosses()
{
}
extern "C" void ExDt::SetStatus(unsigned char tmp)
{
   /*	
	State.Reg1.bit.RLoss = (tmp & 0x2) ? 0 : 1; //1 - loss of sync
	State.Reg1.bit.Sync  = (tmp & 0x1) ? 1 : 0; 
	State.Reg1.bit.All1s  = (tmp & 0x40) ? 1 : 0; 
	State.Reg1.bit.All0s  = (tmp & 0x20) ? 1 : 0; 
	State.Reg2.bit.LED = 1; //need load LED
  	State.Reg2.bit.Some = 1; //need some update
  	CheckLosses();
	*/
}
extern "C" void ExDt::LoadDs2174()
{
}
extern "C" void ExDt::SetRs449(unsigned char state)
{
}
extern "C" void ExDt::LoadXILR0()
{
 //write_xil_long(0,(uint_32)ClkNumber.Value );
}
extern "C" void ExDt::LoadXILR1()
{
}
//extern "C" void ExDt::LoadXILR2()
//{
//}
extern "C"  void ExDt::GetData()
{
}
extern "C" void ExDt::LoadDDS()
{
}

extern "C" unsigned char PrintDevId(void)
{

 char Buf[DEV_ID_SIZE];
 unsigned int DeviceAddress = ID_ADDRESS;
 read_dataflash (DeviceAddress, DEV_ID_SIZE, (char *)&Buf[0]);
// read_dataflash (DeviceAddress, DEV_ID_SIZE+100, (char *)&Buf[0]);
// read_flag = 1;



//__________________________________________________crc
//unsigned char flag_crc = 0;
//unsigned char id_crc = 0;
//unsigned long check_ver = 0;

 for(unsigned long icrc = 0; icrc < (DEV_ID_SIZE - 1); icrc++ )
 {
  // printfpd(" %02X", 3)
//  id_crc +=  Buf[icrc];
  ToPdcTu0(  Buf[icrc]);
}

}





