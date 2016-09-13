//menu_310s.cpp

//char c[2,2];

NamesConfigFiles.Init( &theAnyStrings.cs[0], 
					7, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cNamesConfigFilesV[0], //variants
					0, //init value
					NAMES_LEN, //chars in one on indikator
					MAX_NUM_CFG, // 
					&theCntFunc, //pControl
					183, //cntnum control of value
					183, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cConfigFile[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					183,  //remnum //selector for operation if receive remote command
					0
);

LoadVariants.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cLoadVariantsV[0], //variants
					0, //init value
					7, //chars in one on indikator	 factory
					11, // 	variants
					&theCntFunc, //pControl
					184, //cntnum control of value
					184, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemLoadVariants[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					184,  //remnum //selector for operation if receive remote command
					0
);

SaveVariants.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSaveVariantsV[0], //variants
					0, //init value
					2, //chars in one on indikator	 factory
					10, // 	variants
					&theCntFunc, //pControl
					185, //cntnum control of value
					185, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSaveVariants[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					185,  //remnum //selector for operation if receive remote command
					0
);

AnyConfig.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      186, //  Uint16,// SetCntNum,
                      186,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cAnyConfig[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  186//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

RAnyConfig.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      187, //  Uint16,// SetCntNum,
                      187,//  Uint16,// SetOprNum, 
              //      char *SetpMes0, char *SetpMes1,
              //      char SetDgAftPnt,
              //     char SetHexOrDec//,
              //    ,float64 SetValue,
                     &theAnyStrings.cRAnyConfig[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			  //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  187//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


CurReadedAnyCofig.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cCurReadedAnyCofigV[0], //variants
					0, //init value
					1, //chars in one on indikator	 factory
					10, // 	variants
					&theCntFunc, //pControl
					188, //cntnum control of value
					188, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemCurReadedAnyCofig[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					188,  //remnum //selector for operation if receive remote command
					0
);


RAnyConfig1.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      189, //  Uint16,// SetCntNum,
                      189,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig1[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  189//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

RAnyConfig2.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      190, //  Uint16,// SetCntNum,
                      190,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig2[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  190//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

RAnyConfig3.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      191, //  Uint16,// SetCntNum,
                      191,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig3[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  191//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

FirmFileData.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      192, //  Uint16,// SetCntNum,
                      192,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemFirmFileData[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  192//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


//________________________________________________________________________________________

MRfOut.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMRfOutV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					193, //cntnum control of value
					193, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRfOut[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					193,  //remnum //selector for operation if receive remote command
					0
);


MOutLev.Init( &theAnyStrings.c31f[0],  //format
  				  15, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  194,//6,  //cntnum - function for control of value
				   194, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMOutLev[0] //remote command	  
  		, &theAnyStrings.c031f[0], //remote format
		 5,  //remchars 
		 194 //remnum
		 ,1,	 MIN_MOUTLEV,
			 MAX_MOUTLEV,
			 1);






MTDRate.Init( &theAnyStrings.c74f[0],  //format
  				  11, 2,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    7,  //chars
		  			&theCntFunc, //pControl
				  195,//6,  //cntnum - function for control of value
				   195, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 4, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMTDRate[0] //remote command	  
  		, &theAnyStrings.c74f[0], //remote format
		 8,  //remchars 
		 195 //remnum
		 ,1,	 MIN_MTDRATE,
			 MAX_MTDRATE,
			 1);






 MRDRate.Init( &theAnyStrings.c74f[0],  //format
  				  11, 2,  //x,y
				   0 ,		//   not changable
	   					ZeroStorage, //sweep in storage - new
				    7,  //chars
		  			&theCntFunc, //pControl
				  196,//6,  //cntnum - function for control of value
				   196, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 4, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMRDRate[0] //remote command	  
  		, &theAnyStrings.c74f[0], //remote format
		 8,  //remchars 
		 196 //remnum
		 ,1,	 MIN_MRDRATE,
			 MAX_MRDRATE,
			 1);


 
MTFreq.Init( &theAnyStrings.c74f[0],  //format
  				  13, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    6,  //chars
		  			&theCntFunc, //pControl
				  197,//6,  //cntnum - function for control of value
				   197, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 4, 0//, 0//,		//0 digit after point,dec			  
   				,70,  //init value
			&theAnyStrings.cRemMTFreq[0] //remote command	  
  		, &theAnyStrings.c74f[0], //remote format
		 8,  //remchars 
		 197 //remnum
		 ,1,	 MIN_MTFREQ,
			 MAX_MTFREQ,
			 1);

MRFreq.Init( &theAnyStrings.c74f[0],  //format
  				  13, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    6,  //chars
		  			&theCntFunc, //pControl
				  198,//6,  //cntnum - function for control of value
				   198, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 4, 0//, 0//,		//0 digit after point,dec			  
   				,70,  //init value
			&theAnyStrings.cRemMRFreq[0] //remote command	  
  		, &theAnyStrings.c74f[0], //remote format
		 8,  //remchars 
		 198 //remnum
		 ,1,	 MIN_MRFREQ,
			 MAX_MRFREQ,
			 1);




MTModul.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    0 , //  not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMTModulV[0], //variants
					0, //init value
					6, //chars in one on indikator	 factory
					7, // 	variants
					&theCntFunc, //pControl
					199, //cntnum control of value
					199, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMTModul[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					199,  //remnum //selector for operation if receive remote command
					0
);



MRModul.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    0, //  not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMTModulV[0], //variants
					0, //init value
					6, //chars in one on indikator	 factory
					7, // 	variants
					&theCntFunc, //pControl
					200, //cntnum control of value
					200, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRModul[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					200,  //remnum //selector for operation if receive remote command
					0
);

MTCode.Init( &theAnyStrings.c63f[0],  //format
  				  19, 2,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    6,  //chars
		  			&theCntFunc, //pControl
				  201,//6,  //cntnum - function for control of value
				   201, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], //mesaage line 1
   						 1, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMTCode[0] //remote command	  
  		, &theAnyStrings.c63f[0], //remote format
		 5,  //remchars 
		 201 //remnum
		 ,1,	 MIN_MTCODE,
			 MAX_MTCODE,
			 1);


MRCode.Init( &theAnyStrings.c63f[0],  //format
  				  19, 2,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    6,  //chars
		  			&theCntFunc, //pControl
				  202,//6,  //cntnum - function for control of value
				   202, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMRCode[0] //remote command	  
  		, &theAnyStrings.c63f[0], //remote format
		 5,  //remchars 
		 202 //remnum
		 ,1,	 MIN_MRCODE,
			 MAX_MRCODE,
			 1);




/*
MTCode.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMTCodeV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					201, //cntnum control of value
					201, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMTCode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					201,  //remnum //selector for operation if receive remote command
					0
);


MRCode.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMRCodeV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					202, //cntnum control of value
					202, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRCode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					202,  //remnum //selector for operation if receive remote command
					0
);
*/

MDemod.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMDemodV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					203, //cntnum control of value
					203, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMDemod[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					203,  //remnum //selector for operation if receive remote command
					0
);







MEthMode.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMEthModeV[0], //variants
					0, //init value
					4, //chars in one on indikator	 factory
					6, // 	variants	  //auto 1g 100
					&theCntFunc, //pControl
					204, //cntnum control of value
					204, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMEthMode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					204,  //remnum //selector for operation if receive remote command
					0
);


MEthPause.Init( &theAnyStrings.cs[0], 
					16, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMEthPauseV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					205, //cntnum control of value
					205, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMEthPause[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					205,  //remnum //selector for operation if receive remote command
					0
);



MEthctl.Init( &theAnyStrings.cs[0], 
					19, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMEthctlV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					206, //cntnum control of value
					206, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMEthctl[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					206,  //remnum //selector for operation if receive remote command
					0
);



MEthMaxF.Init( &theAnyStrings.c8d[0],  //format
  				  14, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    8,  //chars
		  			&theCntFunc, //pControl
				  207,//6,  //cntnum - function for control of value
				   207, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMEthMaxF[0] //remote command	  
  		, &theAnyStrings.c08X[0], //remote format
		 8,  //remchars 
		 207 //remnum
		 ,1,	 MIN_METHMAXF,
			 MAX_METHMAXF,
			 1);








MEthVlanP.Init( &theAnyStrings.c1d[0],  //format
  				  19, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    1,  //chars
		  			&theCntFunc, //pControl
				  208,//6,  //cntnum - function for control of value
				   208, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMEthVlanP[0] //remote command	  
  		, &theAnyStrings.c1d[0], //remote format
		 8,  //remchars 
		 208 //remnum
		 ,1,	 MIN_METHVLANP,
			 MAX_METHVLANP,
			 1);


MEbN0.Init(&theAnyStrings.c41f[0], 	  //format for resultstr
					7, 1, 
					&theCntFunc,
				 209,	 //oprnum
					 &theAnyStrings.cRemMEbN0[0]
 		 ,&theAnyStrings.c41f[0], //remote format
			   8,  //remchars 	   - test
					209, 	//remnum
					209	 //cntnum
					);	
	  /*
MTEbN0.Init(&theAnyStrings.c41f[0], 	  //format for resultstr
					17, 2, 
					&theCntFunc,
				 210,	 //oprnum
					 &theAnyStrings.cRemMTEbN0[0]
 		 ,&theAnyStrings.c41f[0], //remote format
			   8,  //remchars 	   - test
					210, 	//remnum
					210	 //cntnum
					);
					
   */					
MTEbN0.Init( &theAnyStrings.c41f[0],  //format
  				  18, 2,  //x,y
				   1 ,		//   changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  210,//6,  //cntnum - function for control of value
				   210, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		//1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMEbN0[0] //remote command	  
  		, &theAnyStrings.c31f[0], //remote format
		 3,  //remchars 
		 210 //remnum
		 ,1,	 MIN_MTEBN0,
			 MAX_MTEBN0,
			 1);
						
//________________________________________

MBER.Init(&theAnyStrings.c21f[0], 	  //format for resultstr
					17, 1, 
					&theCntFunc,
				 211,	 //oprnum
					 &theAnyStrings.cRemMBER[0]
 		 ,&theAnyStrings.c71e[0], //remote format
			   8,  //remchars 	   - test
					211, 	//remnum
					211	 //cntnum
					);
					
						

   /*
MTBER.Init(&theAnyStrings.c71e[0], 	  //format for resultstr
					17, 2, 
					&theCntFunc,
				 212,	 //oprnum
					 &theAnyStrings.cRemMTBER[0]
 		 ,&theAnyStrings.c71e[0], //remote format
				  8,  //remchars 	   - test
					212, 	//remnum
					212	 //cntnum
					);	

	 */

MTBER.Init( &theAnyStrings.c21f[0],  //format
  				  16, 2,  //x,y
				   1 ,		//   changable
	   					ZeroStorage, //sweep in storage - new
				    2,  //chars
		  			&theCntFunc, //pControl
				  212,//6,  //cntnum - function for control of value
				   212, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMTBER[0] //remote command	  
  		, &theAnyStrings.c21f[0], //remote format
		 2,  //remchars 
		 212 //remnum
		 ,1,	 MIN_MTBER,
			 MAX_MTBER,
			 1);

//________________________________________________________


MAGC.Init( &theAnyStrings.c41f[0],  //format
  				  3, 2,  //x,y
				   0 ,		// not  changable
	   					ZeroStorage, //sweep in storage - new
				    4,  //chars
		  			&theCntFunc, //pControl
				  213,//6,  //cntnum - function for control of value
				   213, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		//1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMAGC[0] //remote command	  
  		, &theAnyStrings.c41f[0], //remote format
		 4,  //remchars 
		 213 //remnum
		 ,1,	 MIN_MAGC,
			 MAX_MAGC,
			 1);



  /*

(&theAnyStrings.c41f[0], 	  //format for resultstr
					17, 2, 
					&theCntFunc,
				 213,	 //oprnum
					 &theAnyStrings.cRemMAGC[0]
 		 ,&theAnyStrings.c41f[0], //remote format
			   8,  //remchars 	   - test
					213, 	//remnum
					213	 //cntnum
					);	
	*/

MSweep.Init( &theAnyStrings.c61f[0],  //format
  				  15, 2,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    4,  //chars
		  			&theCntFunc, //pControl
				  214,//6,  //cntnum - function for control of value
				   214, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMSweep[0] //remote command	  
  		, &theAnyStrings.c41f[0], //remote format
		 4,  //remchars 
		 214 //remnum
		 ,1,	 MIN_MSWEEP,
			 MAX_MSWEEP,
			 1);



   /*

(&theAnyStrings.c8d[0], 	  //format for resultstr
					17, 2, 
					&theCntFunc,
				 214,	 //oprnum
					 &theAnyStrings.cRemMSweep[0]
 		 ,&theAnyStrings.c8d[0], //remote format
			   8,  //remchars 	   - test
					214, 	//remnum
					214	 //cntnum
					);	

	  */
MEthSend.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 2, 
					&theCntFunc,
				 215,	 //oprnum
					 &theAnyStrings.cRemMEthSend[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					215, 	//remnum
					215	 //cntnum
					);	


MEthReceived.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 2, 
					&theCntFunc,
				 216,	 //oprnum
					 &theAnyStrings.cRemMEthReceived[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					216, 	//remnum
					216	 //cntnum
					);	

MEthTransmit.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 1, 
					&theCntFunc,
				 216,	 //oprnum
					 &theAnyStrings.cRemMEthReceived[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					216, 	//remnum
					216	 //cntnum
					);	




MEthModeI.Init( &theAnyStrings.cs[0], 
					17, 2, //x,y
				    0 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMEthModeIV[0], //variants
					0, //init value
					7, //chars in one on indikator	 factory
					9, // 	variants
					&theCntFunc, //pControl
					217, //cntnum control of value
					217, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMEthModeI[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					217,  //remnum //selector for operation if receive remote command
					0
);



MIfLoop.Init( &theAnyStrings.cs[0], 
					19, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMIfLoopV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					218, //cntnum control of value
					218, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMIfLoop[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					218,  //remnum //selector for operation if receive remote command
					0
);

MUnModul.Init( &theAnyStrings.cs[0], 
					19, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMUnModulV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					219, //cntnum control of value
					219, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMUnModul[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					219,  //remnum //selector for operation if receive remote command
					0
);

MACMM.Init( &theAnyStrings.cs[0], 
					19, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMACMMV[0], //variants
					0, //init value
					3, //chars in one on indikator	 factory
					3, // 	variants
					&theCntFunc, //pControl
					220, //cntnum control of value
					220, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMACMM[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					220,  //remnum //selector for operation if receive remote command
					0
);

MTBERE.Init( &theAnyStrings.c02d[0],  //format
  				  23, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    2,  //chars
		  			&theCntFunc, //pControl
				  221,//6,  //cntnum - function for control of value
				   221, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMTBERE[0] //remote command	  
  		, &theAnyStrings.c2d[0], //remote format
		 2,  //remchars 
		 221 //remnum
		 ,1,	 MIN_MTBERE,
			 MAX_MTBERE,
			 1);



IFmoduleData.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      222, //  Uint16,// SetCntNum,
                      222,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemIFmoduleData[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  222//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


//________________________________________________________________


RAnyConfig4.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      223, //  Uint16,// SetCntNum,
                      223,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig4[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  223//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
RAnyConfig5.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      224, //  Uint16,// SetCntNum,
                      224,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig5[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  224//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
RAnyConfig6.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      225, //  Uint16,// SetCntNum,
                      225,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig6[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  225//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
RAnyConfig7.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      226, //  Uint16,// SetCntNum,
                      226,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig7[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  226//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
RAnyConfig8.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      227, //  Uint16,// SetCntNum,
                      227,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig8[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  227//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );
RAnyConfig9.Init(
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      228, //  Uint16,// SetCntNum,
                      228,//  Uint16,// SetOprNum, 
                     &theAnyStrings.cRAnyConfig9[0],//   char*,// SetpRemote,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  228//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );


MEthReceivedCRC.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 2, 
					&theCntFunc,
				 229,	 //oprnum
					 &theAnyStrings.cRemMEthReceivedCRC[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					229, 	//remnum
					229	 //cntnum
					);	


MEthSendU.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 2, 
					&theCntFunc,
				 230,	 //oprnum
					 &theAnyStrings.cRemMEthSendU[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					230, 	//remnum
					230	 //cntnum
					);	

MEthRcvD.Init(&theAnyStrings.cd[0], 	  //format for resultstr
					16, 2, 
					&theCntFunc,
				 230,	 //oprnum
					 &theAnyStrings.cRemMEthSendU[0]
 		 ,&theAnyStrings.cd[0], //remote format
			   8,  //remchars 	   - test
					230, 	//remnum
					230	 //cntnum
					);	




IFmoduleHeader.Init(
 					 //&theAnyStrings.cCommandF[0]
 					 "%24s",//char *,// pSetFormat, - format for makeresultsstr
                       1,// char,// SetXPos,
                       2,//  char,// SetYPos,
                     //   char SetChangable, 
                     //   volatile char* SetStorageAddr,
					//	   Uint32 SetStorageAddr,
                     24,//    char,// SetCharsInOne, //quantity of visible symbols on LED
                      &theCntFunc,//   CntFunc * ,//SetpControl,
                      231, //  Uint16,// SetCntNum,
                      231,//  Uint16,// SetOprNum, 
                  //      char *SetpMes0, char *SetpMes1,
                   //      char SetDgAftPnt,
                   //     char SetHexOrDec//,
                  //    ,float64 SetValue,
                     &theAnyStrings.cRemIFmoduleHeader[0],//   char*,// SetpRemote,
              //       &theAnyStrings.c514c[0],//  char *,// SetpRemFormat, 
			   //		  &theAnyStrings.c100c[0],//  char *,// SetpRemFormat,
			    	     &theAnyStrings.c200c[0],//  char *,// SetpRemFormat,
                 TBUFF1_VALUE,//   5,// vill be 30  //char,// SetRemChars,//shars of value in remote command or answer
                  231//   char// SetRemNum - number of functions                      
               ,0 //len = 2  //in first two bytes is lengtch of data
         );

MTCdType.Init( &theAnyStrings.cs[0], 
					14, 2, //x,y
				    0 , //  not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMTCdTypeV[0], //variants
					0, //init value
					4, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					232, //cntnum control of value
					232, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMTCdType[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					232,  //remnum //selector for operation if receive remote command
					0
);

MRCdType.Init( &theAnyStrings.cs[0], 
					14, 2, //x,y
				    0  , //  not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMRCdTypeV[0], //variants
					0, //init value
					4, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					233, //cntnum control of value
					233, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRCdType[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					233,  //remnum //selector for operation if receive remote command
					0
);

MTMode.Init( &theAnyStrings.cs[0], 
			   //		21, 2, //x,y
					15, 2, //x,y
				    1  , //   changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMTModeV[0], //variants
					0, //init value
				//	1, //chars in one on indikator	 factory
					8, //chars in one on indikator	 factory
					16, // 	variants
					&theCntFunc, //pControl
					234, //cntnum control of value
					234, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMTMode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					234,  //remnum //selector for operation if receive remote command
					0
);


MRMode.Init( &theAnyStrings.cs[0], 
					21, 2, //x,y
				    0  , //  not changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMRModeV[0], //variants
					0, //init value
					1, //chars in one on indikator	 factory
					16, // 	variants
					&theCntFunc, //pControl
					235, //cntnum control of value
					235, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRMode[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					235,  //remnum //selector for operation if receive remote command
					0
);

MRCntl.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1  , //   changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMRCntlV[0], //variants
					0, //init value
					12, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					236, //cntnum control of value
					236, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMRCntl[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					236,  //remnum //selector for operation if receive remote command
					0
);

MOutLevO.Init( &theAnyStrings.c32f[0],  //format
  				  5, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  237,//6,  //cntnum - function for control of value
				   237, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 2, 0//, 0//,		// 2 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMOutLevO[0] //remote command	  
  		, &theAnyStrings.c32f[0], //remote format
		 5,  //remchars 
		 237 //remnum
		 ,1,	 MIN_MOUTLEVO,
			 MAX_MOUTLEVO,
			 1);


MOutLevOS.Init( &theAnyStrings.cs[0], 
					4, 2, //x,y
				    1  , //   changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cMOutLevOSV[0], //variants
					0, //init value
					1, //chars in one on indikator	 factory
					2, // 	variants
					&theCntFunc, //pControl
					238, //cntnum control of value
					238, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemMOutLevOS[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c08X[0], //format remote
					8, //remchars //chars in celling pole of remote command 
					238,  //remnum //selector for operation if receive remote command
					0
);




MBERE.Init( &theAnyStrings.c2d[0],  //format
  				  23, 1,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    2,  //chars
		  			&theCntFunc, //pControl
				  239,//6,  //cntnum - function for control of value
				   239, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		//0 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMBERE[0] //remote command	  
  		, &theAnyStrings.c2d[0], //remote format
		 2,  //remchars 
		 239 //remnum
		 ,1,   MIN_MBERE,
			 MAX_MBERE,
			 1);


MOutLev1.Init( &theAnyStrings.c02d[0],  //format
  				  20, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    2,  //chars
		  			&theCntFunc, //pControl
				  240,//6,  //cntnum - function for control of value
				   240, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMOutLev1[0] //remote command	  
  		, &theAnyStrings.c02d[0], //remote format
		 5,  //remchars 
		 240 //remnum
		 ,1,	 MIN_MOUTLEV1,
			 MAX_MOUTLEV1,
			 1);

MOutLev2.Init( &theAnyStrings.c1d[0],  //format
  				  23, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    1,  //chars
		  			&theCntFunc, //pControl
				  241,//6,  //cntnum - function for control of value
				   241, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMOutLev2[0] //remote command	  
  		, &theAnyStrings.c1d[0], //remote format
		 5,  //remchars 
		 241 //remnum
		 ,1,	 MIN_MOUTLEV2,
			 MAX_MOUTLEV2,
			 1);


MKOUT.Init( &theAnyStrings.c31f[0],  //format
  				  13, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  242,//6,  //cntnum - function for control of value
				   242, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 1, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMKout[0] //remote command	  
  		, &theAnyStrings.c31f[0], //remote format
		 5,  //remchars 
		 242 //remnum
		 ,1,	 MIN_MKOUT,
			 MAX_MKOUT,
			 1);

MRateE.Init( &theAnyStrings.cd[0],  //format
  				  11, 2,  //x,y
				   0 ,		//  not changable
	   					ZeroStorage, //sweep in storage - new
				    10,  //chars
		  			&theCntFunc, //pControl
				  243,//6,  //cntnum - function for control of value
				   243, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMRateE[0] //remote command	  
  		, &theAnyStrings.cd[0], //remote format
		 3,  //remchars 
		 243 //remnum
		 ,1,	 MIN_MRATEE,
			 MAX_MRATEE,
			 1);
//____
MKOUT1.Init( &theAnyStrings.c3d[0],  //format
  				  20, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  252,//6,  //cntnum - function for control of value
				   252, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMKout1[0] //remote command	  
  		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 252 //remnum
		 ,1,	 MIN_MKOUT1,
			 MAX_MKOUT1,
			 1);


MKIN1.Init( &theAnyStrings.c3d[0],  //format
  				  5, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  253,//6,  //cntnum - function for control of value
				   253, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMKin1[0] //remote command	  
  		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 253 //remnum
		 ,1,	 MIN_MKIN1,
			 MAX_MKIN1,
			 1);

MKIN2.Init( &theAnyStrings.c3d[0],  //format
  				  13, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  254,//6,  //cntnum - function for control of value
				   254, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMKin2[0] //remote command	  
  		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 254 //remnum
		 ,1,	 MIN_MKIN2,
			 MAX_MKIN2,
			 1);


MKIN3.Init( &theAnyStrings.c3d[0],  //format
  				  20, 2,  //x,y
				   1 ,		//  changable
	   					ZeroStorage, //sweep in storage - new
				    3,  //chars
		  			&theCntFunc, //pControl
				  255,//6,  //cntnum - function for control of value
				   255, //	6, //oprnum - operation if setted new value
					&theAnyStrings.cmes0[0], // message line 0 
					&theAnyStrings.cmes1[0], // mesaage line 1
   						 0, 0//, 0//,		// 1 digit after point,dec			  
   				,0,  //init value
			&theAnyStrings.cRemMKin3[0] //remote command	  
  		, &theAnyStrings.c3d[0], //remote format
		 3,  //remchars 
		 255 //remnum
		 ,1,	 MIN_MKIN3,
			 MAX_MKIN3,
			 1);

 
SatSound.Init( &theAnyStrings.cs[0], 
					9, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cSatSoundV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					257,//160, //cntnum control of value5
					257,//160, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemSatSound[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					257//160  //remnum //selector for operation if receive remote command
										,0
);

 
SClear.Init( &theAnyStrings.cs[0], 
					12, 2, //x,y
				    1 , //changable
					ZeroStorage,		//hier is zero - not saved
					&theAnyStrings.cLogClearV[0], //variants
					0, //init value
					3, //chars in one on indikator
					2, // 
					&theCntFunc, //pControl
					259,//161, //cntnum control of value
					259,//161, //oprnum - operation if setted nev value
					&theAnyStrings.cmes0[0],  //messages to error setted value
					&theAnyStrings.cmes1[0]	//two line of message
					 , &theAnyStrings.cRemLogClear[0] //pointer of prefix for remote command premote
					 , &theAnyStrings.c1d[0], //format remote
					1, //remchars //chars in celling pole of remote command 
					259//161  //remnum //selector for operation if receive remote command
										,0
);






 

















  LogoItem.Init(&theAnyStrings.cLogoLd[0], 
  //	&theAnyStrings.cConfig[0],
	 &theAnyStrings.cVersion[0],
 	1,
    &LogoItem, &LogoItem,&LogoItem, &SatIndicationItem,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

  ConfigItem.Init(&theAnyStrings.cLogoLd[0], 	  //system
   	&theAnyStrings.cConfig[0],
 	1,
  //	  &SatSystemItem, &SatIndicationItem, &LogoItem, &TestItem,
	  &SatSystemItem, &SatIndicationItem, &LogoItem, &IdItem,
	  NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

 IPItem.Init(&theAnyStrings.cIPAddrU[0], 
  	&theAnyStrings.cIPAddrL[0],
 	1,
#ifdef CLOCK_ENABLED
#ifndef USE_HTTP
  &TimeItem, &AddressRS485Item, &ConfigItem, NULL,
#else
  &TimeItem, &NetMaskItem, &ConfigItem, NULL,
#endif
#else


 //  &XilinxItem, &AddressRS485Item, &ConfigItem, NULL,
 &IFmoduleItem,&AddressRS485Item, &ConfigItem, NULL,
#endif
  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
//___________________________________________


//______________________________________________________
   
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
 // &NetMaskItem, &WebPasswordItem, &ConfigItem, NULL
  &NetMaskItem, &SatSoundItem, &ConfigItem, NULL,
//  	NULL, NULL, NULL, NULL, NULL, &IPAddress3,  &IPAddress2, &IPAddress1, &IPAddress0, NULL, NULL);
  NULL, NULL, NULL, NULL, NULL, &Network3,  &Network2, &Network1, &Network0, NULL, NULL);

 


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
 //   &AddressRS485Item, &TestItem, &ConfigItem, NULL, 
 //	&AddressRS485Item, &XilinxItem , &ConfigItem, NULL,
//	&WebPasswordItem, &XilinxItem , &ConfigItem, NULL,
	&WebPasswordItem, &TxOutLevOItem1 , &ConfigItem, NULL,

 //140203 	NULL, NULL, NULL, NULL, NULL,  &DevId,   &DevYear,  &DevVer1,  &DevVer2, NULL, NULL);
  	NULL, NULL, NULL, NULL, NULL,  &DevId,    NULL,   NULL,   NULL, NULL, NULL);
//___________________________________________



//___________________________________________
 TestItem.Init(&theAnyStrings.cTestMode[0], 
  	&theAnyStrings.cPOK[0],
  	1,
  //  &XilinxItem, &IdItem, &ConfigItem, NULL,
    &IdItem, &XilinxItem, &ConfigItem, NULL,
  	NULL, NULL, NULL, NULL, NULL,  &POK, &TestMode,  NULL,  NULL, NULL, NULL);
//___________________________________________
 //___________________________________________
 MACItem.Init(&theAnyStrings.cMACAddress[0], 
  	&theAnyStrings.cMACData[0],
  	1,
//#ifndef PROG_PU_MSAT
//    &AddressRS485Item, &XilinxItem, &ConfigItem, NULL,
    &AddressRS485Item, &TxOutLevOItem1, &ConfigItem, NULL,
//#else
//    &AddressRS485Item, &SatSet0Item, &ConfigItem, NULL,
//#endif

  	NULL, NULL, NULL, NULL, NULL, &MAC0, &MAC1,  NULL,  NULL, NULL, NULL);


//_______________________________________________________________________________________
//TxOutLevOItem1.Init(&theAnyStrings.cConfig[0], 	  //configuration
//  	&theAnyStrings.cTxOutLevelO[0],

TxOutLevOItem1.Init(&theAnyStrings.cTxOutLevelO[0], 	  //configuration
  	&theAnyStrings.cEmpty[0],

	 1,
    &IdItem, &TxOutLevKItem1, &ConfigItem, NULL,//&SatSet1Item,
//	&MOutLevOS, NULL, NULL, NULL, NULL,  &MOutLevO, NULL, NULL,  NULL,  NULL, NULL);
//	 NULL, NULL, NULL, NULL, NULL,  &MOutLevO, NULL, NULL,  NULL,  NULL, NULL);
//	 NULL, NULL, NULL, NULL, NULL,  &MOutLevO, &MKOUT, &MKOUT1,  NULL,  NULL, NULL);
	 &MOutLevOS, NULL, NULL, NULL, NULL,  &MOutLevO, &MKOUT, &MKOUT1,  NULL,  NULL, NULL);

//TxOutLevKItem1.Init(&theAnyStrings.cConfig[0], 	  //configuration
//  	&theAnyStrings.cTxOutLevelK[0],
TxOutLevKItem1.Init(&theAnyStrings.cTxOutLevelK[0], 	  //configuration
  	&theAnyStrings.cEmpty[0],
	 1,
    &TxOutLevOItem1, &FirmwareItem, &ConfigItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MKIN1,  &MKIN2, &MKIN3,  NULL,  NULL, NULL);
//________________________________________________________________________________________


 
XilinxItem.Init(&theAnyStrings.cXilinxFile[0], 
  	&theAnyStrings.cEmpty[0],
	1,

#ifdef CLOCK_ENABLED
//  &TestItem, &FirmwareItem, &ConfigItem, NULL,
  &IdItem, &FirmwareItem, &ConfigItem, NULL,
#else
    &IdItem, &FirmwareItem, &ConfigItem, NULL,
#endif  

   NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, &XilFileData, NULL);


//_______________________________________________________________

FirmwareItem.Init(&theAnyStrings.cFirmware[0], 
  	&theAnyStrings.cEmpty[0],
	1,

//#ifdef CLOCK_ENABLED
//  &XilinxItem, &IFmoduleItem, &ConfigItem, NULL,
//#else
//    &XilinxItem, &IFmoduleItem, &ConfigItem, NULL,
//#endif  
	 &TxOutLevKItem1, &MRCntlItem, &ConfigItem, NULL,



   NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, &FirmFileData, NULL);




MRCntlItem.Init(&theAnyStrings.cMRCntl[0], 
  	&theAnyStrings.cEmpty[0],
	1,

#ifdef CLOCK_ENABLED
  &FirmwareItem, &DateItem, &ConfigItem, NULL,
#else
    &FirmwareItem, &IPItem, &ConfigItem, NULL,
#endif  

   &MRCntl, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, NULL, NULL);



IFmoduleItem.Init(&theAnyStrings.cIFmodule[0], 
  	&theAnyStrings.cEmpty[0],
	1,

#ifdef CLOCK_ENABLED
  &FirmwareItem, &DateItem, &ConfigItem, NULL,
#else
    &FirmwareItem, &IPItem, &ConfigItem, NULL,
#endif  

   NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, &IFmoduleHeader, NULL);


//_______________________________________________________________



SatSoundItem.Init(&theAnyStrings.cSatSound[0], 
  	&theAnyStrings.cEmpty[0],
	1,
 &NetworkItem,&WebPasswordItem, &ConfigItem, NULL,
   	&SatSound, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);





#ifdef USE_HTTP

 WebPasswordItem.Init(&theAnyStrings.cWebPassword[0], 
  	&theAnyStrings.cEmpty[0],
	1,
  //  &IPItem,&AddressRS485Item, &ConfigItem, NULL,
  //	 &IPItem,&IdItem, &ConfigItem, NULL,
//	 &NetworkItem,&IdItem, &ConfigItem, NULL,
	 &SatSoundItem,&IdItem, &ConfigItem, NULL,
    NULL, NULL, NULL, NULL, NULL, &WebPassword, NULL,  NULL,  NULL, NULL, NULL);
									  

#endif





//#ifdef PROG_PU_MSAT
#ifdef CLOCK_ENABLED
   
 DateItem.Init(&theAnyStrings.cDate[0], 
  	&theAnyStrings.cDated[0],
	1,
//    &IFmoduleItem, &TimeItem, &ConfigItem, NULL,
	&MRCntlItem, &TimeItem, &ConfigItem, NULL,
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


SatIndicationItem.Init(&theAnyStrings.cLogoLd[0], 
  	&theAnyStrings.cSatIndication[0],
 	1,
#ifndef YOURNAL
    &ConfigItem, &SatSystemItem, &LogoItem, &SatGet1Item,
#else
    &ConfigItem, &SatIndicationEItem, &LogoItem, &MonEBNItem,//&SatGet1Item,
#endif
    NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);




//MonEBNItem.Init(&theAnyStrings.cSatIndication[0], 
//  	&theAnyStrings.cMonEBN[0],
// 	1,
//    &MonSweepItem, &MonTREBNItem, &SatIndicationItem, NULL,//&SatGet1Item,
//    NULL, NULL, NULL, &MEbN0, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


MonEBNItem.Init(&theAnyStrings.cMonEBN[0], 
  	&theAnyStrings.cMonBER[0],
 	1,
 //   &MonSweepItem, &MonTREBNItem, &SatIndicationItem, NULL,//&SatGet1Item,
    &RxDataRateItem1, &TxModulItem1, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL,  &MEbN0, &MBER,  &MAGC,  &MBERE, &MSweep, NULL,  NULL, NULL);
//    NULL, NULL, NULL,&MEbN0, NULL,   &MAGC, &MSweep, NULL,  NULL,  NULL, NULL);


//________________________________________________________________________
TxModulItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cTxModul[0],
	 1,
    &MonEBNItem, &TxCodeRateItem1, &SatIndicationItem, NULL,//&SatSet1Item,
	&MTModul, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


TxCodeRateItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cTxCodeRate[0],
	 1,
    &TxModulItem1, &TxDataRateItem1, &SatIndicationItem, NULL,//&SatSet1Item,
	&MTCdType, NULL, NULL, NULL,   NULL, &MTCode, NULL, NULL,  NULL,  NULL, NULL);

TxDataRateItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cTxDataRate[0],
	 1,
    &TxCodeRateItem1, &RxModulItem1, &SatIndicationItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MTDRate, NULL, NULL,  NULL,  NULL, NULL);



RxModulItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cRxModul[0],
	1,
    &TxDataRateItem1, &RxCodeRateItem1, &SatIndicationItem, NULL,//&SatSet1Item,
	&MRModul, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

RxCodeRateItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cRxCodeRate[0],
	1,
    &RxModulItem1, &RxDataRateItem1, &SatIndicationItem, NULL,//&SatSet1Item,
	 &MRCdType, NULL, NULL, NULL,   NULL, &MRCode,NULL, NULL,  NULL,  NULL, NULL);

RxDataRateItem1.Init(&theAnyStrings.cSatIndication[0], 	  //configuration
  	&theAnyStrings.cRxDataRate[0],
	1,
    &RxCodeRateItem1, &MonEBNItem, &SatIndicationItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL, &MRDRate, NULL, NULL,  NULL,  NULL, NULL);



//________________________________________________________________________


/*
MonTREBNItem.Init(&theAnyStrings.cSatIndication[0], 
  	&theAnyStrings.cMonTREBN[0],
 	1,
    &MonEBNItem, &MonBERItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL,&MTEbN0, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

MonBERItem.Init(&theAnyStrings.cSatIndication[0], 
  	&theAnyStrings.cMonBER[0],
 	1,
    &MonTREBNItem, &MonTRBERItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MBER, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

MonTRBERItem.Init(&theAnyStrings.cSatIndication[0], 
  	&theAnyStrings.cMonTRBER[0],
 	1,
    &MonBERItem, &MonAGCItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MTBER, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


MonAGCItem.Init(&theAnyStrings.cSatIndication[0], 
  	&theAnyStrings.cMonAGC[0],
 	1,
    &MonTRBERItem, &MonSweepItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MAGC, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


MonSweepItem.Init(&theAnyStrings.cSatIndication[0], 
  	&theAnyStrings.cMonSweep[0],
 	1,
    &MonAGCItem, &MonEBNItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MSweep, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

  */



//________________________________________________________

SatIndicationEItem.Init(&theAnyStrings.cLogoLd[0], 
  	&theAnyStrings.cSatIndicationE[0],
 	1,
#ifndef YOURNAL
    &ConfigItem, &SatSystemItem, &LogoItem, &SatGet1Item,
#else
    &SatIndicationItem, &ModTestItem, &LogoItem, &EthModeItem,//&SatGet1Item,
#endif
    NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


EthModeItem.Init(&theAnyStrings.cSatIndicationE[0], 
  	&theAnyStrings.cEthMode[0],
 	1,
    &EthStatItem, &EthStatItem, &SatIndicationEItem, NULL,//&SatGet1Item,
    &MEthModeI, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

EthStatItem.Init(&theAnyStrings.cSatIndicationE[0], 
  	&theAnyStrings.cEthStat[0],
 	1,
     &EthModeItem, &EthModeItem, &SatIndicationEItem, &SClearItem,//&SatGet1Item,
 //   &EthModeItem, &EthModeItem, &SatIndicationEItem, &EthSendItem,//&SatGet1Item,
    NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

SClearItem.Init(&theAnyStrings.cSClear[0], 
  	&theAnyStrings.cEmpty[0],
	1,
    &EthReceiveCRCItem, &EthSendItem,&EthStatItem, NULL,
  	&SClear, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,   NULL,  NULL);



EthSendItem.Init(&theAnyStrings.cEthStat[0], 
  	&theAnyStrings.cEthSend[0],
 	1,
    &SClearItem, &EthSendUItem, &EthStatItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL,&MEthSend, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

EthSendUItem.Init(&theAnyStrings.cEthStat[0], 
  	&theAnyStrings.cEthSendU[0],
 	1,
    &EthSendItem, &EthRcvDItem, &EthStatItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL,&MEthSendU, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

EthRcvDItem.Init(&theAnyStrings.cEthStat[0], 
  	&theAnyStrings.cEthRcvD[0],
 	1,
    &EthSendUItem, &EthReceiveItem, &EthStatItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL,&MEthRcvD, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


EthReceiveItem.Init(&theAnyStrings.cEthTransmit[0], 
  	&theAnyStrings.cEthReceive[0],
 	1,
    &EthRcvDItem, &EthReceiveCRCItem, &EthStatItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MEthReceived, &MEthTransmit,   NULL, NULL, NULL,  NULL,  NULL, NULL);

EthReceiveCRCItem.Init(&theAnyStrings.cEthStat[0], 
  	&theAnyStrings.cEthReceiveCRC[0],
 	1,
    &EthReceiveItem, &SClearItem, &EthStatItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, &MEthReceivedCRC, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);




//-----------------------------------------------------------
ModTestItem.Init(&theAnyStrings.cLogoLd[0], 
  	&theAnyStrings.cModTest[0],
 	1,
#ifndef YOURNAL
    &ConfigItem, &SatSystemItem, &LogoItem, &SatGet1Item,
#else
    &SatIndicationEItem, &SatLogItem, &LogoItem, &ModIFLoopItem,//&SatGet1Item,
#endif
    NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);




ModIFLoopItem.Init(&theAnyStrings.cModTest[0], 
  	&theAnyStrings.cModIFLoop[0],
 	1,
    &ModUnmodulItem, &ModUnmodulItem, &ModTestItem, NULL,//&SatGet1Item,
    &MIfLoop, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


ModUnmodulItem.Init(&theAnyStrings.cModTest[0], 
  	&theAnyStrings.cModUnmodul[0],
 	1,
    &ModIFLoopItem, &ModIFLoopItem, &ModTestItem, NULL,//&SatGet1Item,
    &MUnModul, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


//___________________________________________________________



SatSystemItem.Init(&theAnyStrings.cLogoLd[0], 	  //configuration
  	&theAnyStrings.cSatSystem[0],
 	1,
    &SaveLoadItem, &ConfigItem, &LogoItem, &ModulatorItem,//&SatSet1Item,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

//________________________________________________________140709


ModulatorItem.Init(&theAnyStrings.cSatSystem[0], 	  //configuration
  	&theAnyStrings.cModulator[0],
	 1,
    &InterfaceItem, &DemodulatorItem, &SatSystemItem, &TxModeItem,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);



RfOutItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cRfOutput[0],
	 1,
    &TxFreqItem, &TxOutLevItem, &ModulatorItem, NULL,//&SatSet1Item,
	&MRfOut, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

TxOutLevItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxOutLevel[0],
	 1,
//    &RfOutItem, &TxOutLevOItem, &ModulatorItem, NULL,//&SatSet1Item,
    &RfOutItem, &TxModeItem, &ModulatorItem, NULL,//&SatSet1Item,
  	NULL, NULL, NULL, NULL, NULL,  &MOutLev, NULL, NULL,  NULL,  NULL, NULL);
 //	NULL, NULL, NULL, NULL, NULL,  &MOutLev, &MOutLev1, &MOutLev2,  NULL,  NULL, NULL);
//_______________________________________________________________________________________
 /*
TxOutLevOItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxOutLevelO[0],
	 1,
    &TxOutLevItem, &TxOutLevKItem, &ModulatorItem, NULL,//&SatSet1Item,
//	&MOutLevOS, NULL, NULL, NULL, NULL,  &MOutLevO, NULL, NULL,  NULL,  NULL, NULL);
	 NULL, NULL, NULL, NULL, NULL,  &MOutLevO, NULL, NULL,  NULL,  NULL, NULL);

TxOutLevKItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxOutLevelK[0],
	 1,
    &TxOutLevOItem, &TxModeItem, &ModulatorItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MKOUT, NULL, NULL,  NULL,  NULL, NULL);

*/
//________________________________________________________________________________________


TxModeItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxMode[0],
	 1,
//    &TxOutLevKItem, &TxModulItem, &ModulatorItem, NULL,//&SatSet1Item,
    &TxOutLevItem, &TxModulItem, &ModulatorItem, NULL,//&SatSet1Item,
	&MTMode, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

TxModulItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxModul[0],
	 1,
    &TxModeItem, &TxCodeRateItem, &ModulatorItem, NULL,//&SatSet1Item,
	&MTModul, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


TxCodeRateItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxCodeRate[0],
	 1,
    &TxModulItem, &TxDataRateItem, &ModulatorItem, NULL,//&SatSet1Item,
	 &MTCdType, NULL, NULL, NULL,   NULL, &MTCode, NULL, NULL,  NULL,  NULL, NULL);

TxDataRateItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxDataRate[0],
	 1,
    &TxCodeRateItem, &TxFreqItem, &ModulatorItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MTDRate, NULL, NULL,  NULL,  NULL, NULL);



TxFreqItem.Init(&theAnyStrings.cModulator[0], 	  //configuration
  	&theAnyStrings.cTxFreq[0],
	 1,
    &TxDataRateItem, &RfOutItem, &ModulatorItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MTFreq, NULL, NULL,  NULL,  NULL, NULL);




//_____________________________________________________________________________

DemodulatorItem.Init(&theAnyStrings.cSatSystem[0], 	  //configuration
  	&theAnyStrings.cDemodulator[0],
	1,
    &ModulatorItem, &CommonItem, &SatSystemItem, &RxModeItem,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

RxModeItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxMode[0],
	1,
    &MonTBERItem, &RxModulItem, &DemodulatorItem, NULL,//&SatSet1Item,
	&MRMode, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

RxModulItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxModul[0],
	1,
    &RxModeItem, &RxCodeRateItem, &DemodulatorItem, NULL,//&SatSet1Item,
	&MRModul, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);



RxCodeRateItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxCodeRate[0],
	1,
    &RxModulItem, &RxDataRateItem, &DemodulatorItem, NULL,//&SatSet1Item,
	 &MRCdType, NULL, NULL, NULL,   NULL, &MRCode,NULL, NULL,  NULL,  NULL, NULL);
RxDataRateItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxDataRate[0],
	1,
    &RxCodeRateItem, &RxFreqItem, &DemodulatorItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL, &MRDRate, NULL, NULL,  NULL,  NULL, NULL);
RxFreqItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxFreq[0],
	1,
    &RxDataRateItem, &RxOnOffItem, &DemodulatorItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   &MRFreq, NULL, NULL,  NULL,  NULL, NULL);

RxOnOffItem.Init(&theAnyStrings.cDemodulator[0], 	  //configuration
  	&theAnyStrings.cRxOnOff[0],
	1,
    &RxFreqItem, &MonTEBNItem, &DemodulatorItem, NULL,//&SatSet1Item,
	&MDemod, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

MonTEBNItem.Init(&theAnyStrings.cDemodulator[0], 
  	&theAnyStrings.cMonTREBN[0],
 	1,
    &RxOnOffItem, &MonTBERItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, NULL,   NULL, &MTEbN0, NULL, NULL,  NULL,  NULL, NULL);


MonTBERItem.Init(&theAnyStrings.cDemodulator[0], 
  	&theAnyStrings.cMonTRBER[0],
 	1,
    &MonTEBNItem, &RxModeItem, &SatIndicationItem, NULL,//&SatGet1Item,
    NULL, NULL, NULL, NULL,   NULL,  &MTBER, &MTBERE, NULL,  NULL,  NULL, NULL);

 

//______________________________________________________________________





CommonItem.Init(&theAnyStrings.cSatSystem[0], 	  //Modem Conf configuration
  	&theAnyStrings.cCommon[0],
	1,
    &DemodulatorItem, &InterfaceItem, &SatSystemItem, &ConfigFileItem,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

//ModTestItem.Init(&theAnyStrings.cSatSystem[0], 	  //configuration
//  	&theAnyStrings.cModTest[0],
//	1,
//    &CommonItem, &InterfaceItem, &SatSystemItem, &DemodulatorItem,//&SatSet1Item,
//	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);


//_____________________________________________________
InterfaceItem.Init(&theAnyStrings.cSatSystem[0], 	  //configuration
  	&theAnyStrings.cModInterface[0],
	1,
    &CommonItem, &ModulatorItem, &SatSystemItem, &InterfaceModeItem,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);

InterfaceModeItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfaceMode[0],
	1,
    &InterfaceRateItem, &InterfacePauseItem, &InterfaceItem, NULL,//&SatSet1Item,
	&MEthMode, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
InterfacePauseItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfacePause[0],
	1,
    &InterfaceModeItem, &InterfaceInBandItem, &InterfaceItem, NULL,//&SatSet1Item,
	&MEthPause, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
InterfaceInBandItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfaceInBand[0],
	1,
    &InterfacePauseItem, &InterfaceMaxFrameItem, &InterfaceItem, NULL,//&SatSet1Item,
	&MEthctl, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);
InterfaceMaxFrameItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfaceMaxFrame[0],
	1,
    &InterfaceInBandItem, &InterfaceVLANPItem, &InterfaceItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,   &MEthMaxF, NULL, NULL,  NULL,  NULL, NULL);
InterfaceVLANPItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfaceVLANP[0],
	1,
    &InterfaceMaxFrameItem, &InterfaceRateItem, &InterfaceItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MEthVlanP, NULL, NULL,  NULL,  NULL, NULL);

InterfaceRateItem.Init(&theAnyStrings.cModInterface[0], 	  //configuration
  	&theAnyStrings.cInterfaceRate[0],
	1,
    &InterfaceVLANPItem, &InterfaceModeItem, &InterfaceItem, NULL,//&SatSet1Item,
	NULL, NULL, NULL, NULL, NULL,  &MRateE, NULL, NULL,  NULL,  NULL, NULL);






//_____________________________________________________





//_____________________________________________
ConfigFileItem.Init(&theAnyStrings.cModConfigFile[0], 	  //configuration
  	&theAnyStrings.cEmpty[0],
	1,
    &MACMMItem, &MACMMItem, &CommonItem, &ConfigFileItem,//&SatSet1Item,
  //	NULL, NULL, NULL, NULL, NULL,   &ConfigFile, NULL, NULL,  NULL,  NULL, NULL);

 //	&NamesConfigFiles, NULL, NULL, NULL, NULL,   &ConfigFile, NULL, NULL,  NULL,  NULL, NULL);
		&NamesConfigFiles, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  NULL,  NULL, NULL);

//________________________________________________________140709

MACMMItem.Init(&theAnyStrings.cCommon[0], 
  	&theAnyStrings.cMACMM[0],
 	1,
    &ConfigFileItem, &ConfigFileItem, &CommonItem, NULL,//&SatGet1Item,
    &MACMM, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,  NULL, NULL);




#ifdef YOURNAL

SatLogItem.Init(&theAnyStrings.cLogoLd[0], 
  	&theAnyStrings.cSatLog[0],
 	1,
    &ModTestItem, &SaveLoadItem, &LogoItem, &SatLogViewItem,
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

SaveLoadItem.Init(&theAnyStrings.cLogoLd[0], 
  	&theAnyStrings.cSaveLoad[0],
	1,
    &SatLogItem, &SatSystemItem,&LogoItem, &SaveItem,
  	 NULL, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,   NULL,  NULL);

SaveItem.Init(&theAnyStrings.cSaveLoad[0], 
  	&theAnyStrings.cSave[0],
	1,
    &LoadItem, &LoadItem,&SaveLoadItem, NULL,
  	 &SaveVariants, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,   NULL,  NULL);

LoadItem.Init(&theAnyStrings.cSaveLoad[0], 
  	&theAnyStrings.cLoad[0],
	1,
    &SaveItem, &SaveItem,&SaveLoadItem, NULL,
  	 &LoadVariants, NULL, NULL, NULL, NULL,   NULL, NULL, NULL,  NULL,   NULL,  NULL);



//140709 #endif

/*
char CONFIG_BUFF[CONFIG_SIZE];



extern "C" void combine_TCP_buff(void *p, unsigned short **sz)
//extern "C" void combine_TCP_buff(void *p, unsigned long *sz)
{
	char *tcp_buff = (char*)p;
	*sz = (unsigned short*)p;
	tcp_buff[2] = 0x83;
	sprintf(
		&tcp_buff[3],
		"TYPE=RX\r\n"
		"DEV=AGRPU40e\r\n"
		"RF=2700_40100\r\n"
		"IF=%d\r\n"
		"IFBW=%d\r\n"
		"ATT1=0_30\r\n"
		"ATT1STEP=%d\r\n"
		"ATT2=0_30\r\n"
		"ATT2STEP=%d\r\n"
		"HV=%2.1f\r\n"
		"CV=%02X.%02X\r\n"
		"FV=%2.1f\r\n"
		"SN=%014d",
		70,
		40,
		2,
		2,
		1.0,
		((unsigned)SOFT_VER >> 8), ((unsigned)SOFT_VER & 0xff),
		9.0,
		SelfID()
	);
	**sz = 2+1+strlen(&tcp_buff[3]);
//	*sz = 2+1+strlen(&tcp_buff[3]);
}

extern "C" void MakeAnsUdp()
{
 //	char tcp_buff[180]; // указатель на буфер для отправки
    	unsigned short *tcp_sz; // указатель на кол-во байт для отправки
	//	combine_TCP_buff(tcp_buff, &tcp_sz);

		combine_TCP_buff(buffer_rad_TU, &tcp_sz);
		buffer_rad_T_lenU =  (unsigned long)*tcp_sz;

		if(buffer_rad_T_lenU >= BUFFER_SIZE_T ) 
		{
	 		buffer_rad_T_lenU = 0;
			SetBufferState((unsigned long)IP_BUFFER_OVERFLOW);
		}

}



//______________________________________________________________




extern "C" void ToBufferIPU(char *IPBuffU, unsigned long len)
{

if(!len) return; //091111

if (len  > (BUFFER_SIZE_T - 1))
{
 len = BUFFER_SIZE_T - 1; //091218
 return; //091111
}

//hier can parse data and make answer in buffer 
//char buffer_rad_TU[BUFFER_SIZE];
//unsigned long  buffer_rad_T_lenU;

  // while(len--)
  // {
 //   printf(" %02X", *IPBuff)
//need use enover buffer    embRS232_rcvbuf_Add((unsigned char)(*IPBuffU++));  //101111
//101111	 my_rx_usart0_int((unsigned char)(*IPBuff++)); //101022

 //  }
    MakeAnsUdp();

}

 */


 /*
extern "C" Item::Init(char* l0, char* l1, 
		char v,Item* SetLeft,
 Item* SetRight, Item* SetUp, Item* SetDown,
 MDataV * SetpDataP0, MDataV * SetpDataP1, MDataV * SetpDataP2,
 MDataI* SetpDataI0, MDataI* SetpDataI1,
 MDataC* SetpDataC0,MDataC* SetpDataC1, MDataC* SetpDataC2,MDataC* SetpDataC3,
  MDataS* SetpDataS0, MDataS* SetpDataS1)
*/

 // 3 mdatav  2 mdatai  4 mdatac  2 mdatas
 /*
extern "C" void CheckParameters()
{

 MRfOut.Value = 0;
 MRfOut.ChangingValue = MRfOut.Value; 
}

  */