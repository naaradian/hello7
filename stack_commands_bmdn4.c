//file: stack_commands.c

command_counter++;

///////////////////////////////////////	UPP /////////////////////////////////////////////
             embMsgAns.SetLength(0); //121023 - if have wrong command - set as default minimum length
			
         
  //         printfpd("\n\r command : 0x%02X", embMsgRequest->Type());
                //  	printEthLongHex(embMsgRequest->Type());

          	switch(embMsgRequest->Type())
					{
               
              
               
					case 0x0A:
            //      break; //t121112
	  	  //			printEthLongHex(0x0A);

						//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
#ifndef PROG_BMDN6MI                  
						WritePort();
#endif                  
						break;
					case 0x0B:
         //       break; //t121112
			//	  	printEthLongHex(0x0B);

						//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
#ifndef PROG_BMDN6MI                  
						ReadPort();
#endif                  
						break;
                  
                 
          //  #ifndef PROG_BMDN6M      
				case 0x10:
			 //  		printEthLongHex(0x10);

							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
            #ifndef PROG_BMDN6MI         
							for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
            #endif         
						break;
                  
				case 0x09:
          //  printEthLongHex(0x9);

				  //	printf("\n\r 0x09");
						 if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1) //was1
							{
                       //      printEthLongHex(1);

					 //		     printf(">>");

						//	printf("\n\r Body(0)==1");
								embMsg485Request_1.Init();
								embMsg485Request_1.SetAddr(0);//embMsg.Body(0));
								embMsg485Request_1.SetLength(2);
								embMsg485Request_1.SetBody(0,embMsgRequest->Body(1));
								embMsg485Request_1.SetBody(1,embMsgRequest->Body(2));
								embMsg485Request_1.CalcCRC();
				  //130626				embMsg485Request_1.SetReadyToSend();
                        tBuffEmbMsg485Request_1.Add(embMsg485Request_1); //130626
						//		printf(".%02X",embMsg485Request_1.IsReadyToSend());
							  //	printf(".%02X",embMsg485Request_1.Body(0));
							  //  printf(".%02X\n\r",embMsg485Request_1.Body(1));
						  //      printf("\n\r>>>>>>i: %d",  embSerialACT155.count);
                    
//____________________________________________________
#ifdef O_POWER
//hier can add == 4 (freq pd ) ==5 (freq pm)

                if (embMsgRequest->Body(1) == 2) //command operate power
//                if ((embMsgRequest->Body(1) == 2) || //command operate power      
  //                  (embMsgRequest->Body(1) == 4) ||
    //                (embMsgRequest->Body(1) == 5))
                  {
             //    printfp("\n\r___________________power");
                
                 if(GetModForSS1())
                 { 
           //ok        printfp("\n\r...............modfss1 off");
                   flag_command_power = 1;
                  SetModForSS1(0); //get off operate power mode - without saving
                  UsedExp.State.Reg2.bit.WriteId = 1;
                  UsedExp.State.Reg2.bit.Some = 1;
                 } 
                } /* Endbody */

#endif
//______________________________________________________                    

							}
							if(embMsgRequest->Body(0)==2) //1
							{
                        //      printEthLongHex(2);

					   //			printf("\n\r Body(0)==2");

								embMsg485Request_2.Init();
								embMsg485Request_2.SetAddr(0);//embMsg.Body(0));
								embMsg485Request_2.SetLength(2);
								embMsg485Request_2.SetBody(0,embMsgRequest->Body(1));
								embMsg485Request_2.SetBody(1,embMsgRequest->Body(2));
								embMsg485Request_2.CalcCRC();
					 //130626			embMsg485Request_2.SetReadyToSend();
                         tBuffEmbMsg485Request_2.Add(embMsg485Request_2); //130626

                        
//____________________________________________________
#ifdef O_POWER
                if (embMsgRequest->Body(1) == 2) //command operate power
                {
                flag_command_power = 1;
                  SetModForSS1(0); //get off operate power mode - without saving
                  UsedExp.State.Reg2.bit.WriteId = 1;
                  UsedExp.State.Reg2.bit.Some = 1;

                } /* Endbody */

#endif
//______________________________________________________                             
							}

						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
			                  
                  
                  
//_______________________________________________________________________________               
               
			 		case 0x01: // cai?in oeia
            //     printEthLongHex(0x1);
 
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,i);	 //_______for test
						break;

//============================================================================================SVCPACK
//__________________________________________________________________________________

			 
					case 0x05: // Загрузка файла (запись в устройство) 
			   //		printEthLongHex(0x05);

 			   	 	   	ul2uc.uc[0] = embMsgRequest->Body(0);
				  		ul2uc.uc[1] = embMsgRequest->Body(1);
				  		ul2uc.uc[2] = embMsgRequest->Body(2);
				   		ul2uc.uc[3] = embMsgRequest->Body(3);


				  		ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);

						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port

				  		shift = ui2uc.ui;

		 				ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;  //port
						ui2uc.uc[3] = 0;  //port
				 		len = ui2uc.ui;
						temp_crc=0;

			 			for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);

		   				ui2uc.uc[0] = embMsgRequest->Body(len+8);
		   				ui2uc.uc[1] = embMsgRequest->Body(len+9);
		   				ui2uc.uc[2] = 0;  //1107
						ui2uc.uc[3] = 0;  //1107

						if(ui2uc.ui==temp_crc)
						{ //crc

						if(ul2uc.uc[3] == 0x80) //port : if try use nvram
						{
	  			 		 for(i=0; i<len; i++)
				  		   {
		  			    			write_nvram_char(i + shift, embMsgRequest->Body(i+8));
				  		   }
						 }
						 else  //enover memory
						 {
					  //   shift +=  (unsigned long)(embMsgRequest->Body(0)) << 16;	 //add to address 
						   wd_reset();
                     shift +=  ul2uc.ul;	 //add to address 
						   for(i=0; i<len; i++)
				  		   {
					 //   	write_buffer_char( embMsgRequest->Body(i+8), NO_START_WRITE_BUFFER);
						   	write_buffer_char1( embMsgRequest->Body(i+8), i+ shift);
						   }
					
						 }
				  	 
					 	} //crc
					
						embMsgAns.SetType(0x05);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);		
				 
				 	break;
				 				
//___________________________________________________________________________________
					case 0x38:	 //all commands
				//	printEthLongHex(0x38);

						embMsgAns.SetType(0x38);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);
						if(
							(embMsgRequest->Body(0) == 0x42) &&
							(embMsgRequest->Body(1) == 0x31) &&
							(embMsgRequest->Body(2) == 0x58) &&
							(embMsgRequest->Body(3) == 0x76) &&
							(embMsgRequest->Body(4) == 0x9C) &&
							(embMsgRequest->Body(5) == 0xBA) 
						   )
						   {
						   	switch(embMsgRequest->Body(6))
							{
					  		 case 0:   break; // write_buffer_char( 0, START_WRITE_BUFFER);	break;
							 case 1:   ProgWrite(); break;
							 case 2:   XilWrite(); break;
							 case 3:   DPDWrite(); break;
							 case 4 :  set_test_mode(0x27);	  dev_restart(); 	break;
							 case 5 :  dev_restart(); 	break;
							 case 6 :  write_nvram_char(RESTARTS_NVRAM_ADDRESS,0);
							 case 7 :  m_load_xilinx3((char)XILINXPG, 1);
					  	 	}							   
						   }
						   break;
		  
//___________________________________________________________________________________


//============================================================================================SVCPACK


					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
             //      for(i)
			  //101227			if(ready_transit) old_ready_transit=0;
			  //101227			if(ready_mod) old_ready_mod=0;
                  
						break;
					case 0x08: // Cai?in ninoiyiey
           //    	printEthLongHex(0x08);

						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155.byte[i]);
						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
						unStateBMD155.stateBMD155.demPI=0;
						unStateBMD155.stateBMD155.loopPI=0;
						unStateBMD155.stateBMD155.statePI=0;
						break;
				   						case 0x0D:
							embMsgAns.SetType(0x0D);
							embMsgAns.SetLength(34);
							for(i=0; i<34; i++) embMsgAns.SetBody(i,unEmb2NetStat.byte[i]);
							unEmb2NetStat.emb2NetStat.markerTime = 0;
							unEmb2NetStat.emb2NetStat.buffModPm = 0;
							unEmb2NetStat.emb2NetStat.buffTransPm = 0;
							unEmb2NetStat.emb2NetStat.buffModPd = 0;
							unEmb2NetStat.emb2NetStat.buffTransPd = 0;
							unEmb2NetStat.emb2NetStat.buff232Pm = 0;
							unEmb2NetStat.emb2NetStat.buff232Pd = 0;
							unEmb2NetStat.emb2NetStat.ready_transit=0;
							unEmb2NetStat.emb2NetStat.ready_mod=1;
						break;
                  
                 //_______________________________________________________________added
#ifdef E1_16
						case 0x12: // Запрос состояния
							embMsgAns.SetType(0x12);
							embMsgAns.SetLength(40);
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unEmb2Mux34.byte[i]);
						break;
#endif //PROG_PU_M_MUX



//_______________________________________________________________added
						case 0x13:
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);

   //							bt = (unsigned char far*)0x80000000;
							   bt = (unsigned char *)(NVRAM_BASE);

							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
                    
						case 0x14: // Cai?in ninoiyiey
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
                     
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
                      /*
                		for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
                     */
						break;
                  
						case 0x15:
						break;
	   				case 0x22:
							embMsgAns.SetType(0x22);
#ifndef HAVE_GATEWAY						

//							if(embMsgRequest->Body(0))// set
							if(embMsgRequest->Body(0) == 1)// set
							{
							   SetIPRem(
							   (embMsgRequest->Body(1) << 24) +
							   (embMsgRequest->Body(2) << 16) +
							   (embMsgRequest->Body(3) << 8) +
							   	embMsgRequest->Body(4)
				 			   );
							}
						    else  if (embMsgRequest->Body(0) == 0)
                      	{ 
                     embMsgAns.SetLength(5);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 	
							embMsgAns.SetBody(1, (GetIPRem() >> 24) & 0xff);
							embMsgAns.SetBody(2, (GetIPRem() >> 16) & 0xff);
							embMsgAns.SetBody(3, (GetIPRem() >> 8) & 0xff);
							embMsgAns.SetBody(4, GetIPRem() & 0xff);
                     }
                     else
                     { 
                     embMsgAns.SetLength(5);	
							embMsgAns.SetBody(0,0); 	
							embMsgAns.SetBody(1,0);
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,0);
							embMsgAns.SetBody(4,0);

                     
                     
                     }                     
   							break;
#else	

			 //		  printfp("\n\r Request :");
			 //	      printfpd(" %X", embMsgRequest->Body(0));
			 //		     printfpd(" %X", embMsgRequest->Body(1));
			 //			     printfpd(" %X", embMsgRequest->Body(2));
			 //				    printfpd(" %X", embMsgRequest->Body(3));
			  //					   printfpd(" %X", embMsgRequest->Body(4));
						 
							 embMsgAns.SetLength(5);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 

							 switch(embMsgRequest->Body(0))
							 {
							case 0:
								   	embMsgAns.SetBody(1, (GetIPRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetIPRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetIPRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetIPRem() & 0xff);
   									break;
							case 1:

									SetIPRem(
								   (embMsgRequest->Body(1) << 24) +
								   (embMsgRequest->Body(2) << 16) +
								   (embMsgRequest->Body(3) << 8) +
								   	embMsgRequest->Body(4)
					 			   );
									
								   	embMsgAns.SetBody(1, (GetIPRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetIPRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetIPRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetIPRem() & 0xff);
   									break;
							case 2:
   									SetNetworkRem(
								   (embMsgRequest->Body(1) << 24) +
								   (embMsgRequest->Body(2) << 16) +
								   (embMsgRequest->Body(3) << 8) +
								   	embMsgRequest->Body(4)
					 			   );
									
								   	embMsgAns.SetBody(1, (GetNetworkRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetNetworkRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetNetworkRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetNetworkRem() & 0xff);
   									break;

						   	 case 3:
   									SetNetMaskRem(
								   (embMsgRequest->Body(1) << 24) +
								   (embMsgRequest->Body(2) << 16) +
								   (embMsgRequest->Body(3) << 8) +
								   	embMsgRequest->Body(4)
					 			   );
									
								   	embMsgAns.SetBody(1, (GetNetMaskRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetNetMaskRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetNetMaskRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetNetMaskRem() & 0xff);
   									break;

							 case 0x12:
   								 		
								   	embMsgAns.SetBody(1, (GetNetworkRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetNetworkRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetNetworkRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetNetworkRem() & 0xff);
   									break;

						   	 case 0x13:
								   	embMsgAns.SetBody(1, (GetNetMaskRem() >> 24) & 0xff);
									embMsgAns.SetBody(2, (GetNetMaskRem() >> 16) & 0xff);
									embMsgAns.SetBody(3, (GetNetMaskRem() >> 8) & 0xff);
									embMsgAns.SetBody(4, GetNetMaskRem() & 0xff);
   									break;
							 default: 
							  	embMsgAns.SetBody(1,  1);
									embMsgAns.SetBody(2, 2);
									embMsgAns.SetBody(3,  3);
									embMsgAns.SetBody(4, 4);
   									break;

									
							 }
						  break;


#endif

//________________________________________________________________________bmdn1
					case 0x40: // 
						embMsgAns.SetType(0x40);
						embMsgAns.SetLength(ulevelsn15503_SIZE);
						for(i=0; i<ulevelsn15503_SIZE; i++) embMsgAns.SetBody(i,ulevelsn15503.byte[i]);
						break;
//________________________________________________________________________bmdn1
					case 0x41: // 
						embMsgAns.SetType(0x41);
						embMsgAns.SetLength(uerrsn15503work_SIZE);
						for(i=0; i<uerrsn15503work_SIZE; i++) embMsgAns.SetBody(i,uerrsn15503work.byte[i]);
						break;
                  
               case 0x50: // 
						embMsgAns.SetType(0x50);
                  if(embMsgRequest->Body(0) == 0)
                  { 
                   i = 2;
                   embMsgAns.SetLength(2 + SavedTxtFilesVal);
                   embMsgAns.SetBody(0,0);

                   embMsgAns.SetBody(1,SavedTxtFilesVal);
#ifdef FIND_CONF_ERR                   
                   printfpd("\n\r50_0_____:%d \n\r", SavedTxtFilesVal);
#endif                    
                   for(long is = 0; is<MAX_CFG_FILE_VARIANT;is++)
                   {
                      if(ScanTxtFilesNum[is])
                      {
                         embMsgAns.SetBody(i++,is);
#ifdef FIND_CONF_ERR                      
                       printfpd(" %02d", is);
#endif
                         
                      }
                    }
                    
#ifdef FIND_CONF_ERR                      
                   printfp("\n\r50_0_____<<<<<<<<");
#endif                       
                   }  //== 0
                   
                  else if(embMsgRequest->Body(0) == 1)
                  {
                     embMsgAns.SetLength(TXT_CUR_REAL_LEN + 1);
                       embMsgAns.SetBody(0,1);
                //    printEthLongHex(modemp[0].configfilefext.LengthTxt);
                
            //hier used setted current length    
           //this is not correct   if(modemp[0].configfilefext.LengthTxt !=  TXT_CUR_REAL_LEN)
                  if(embMsgRequest->Body(1) < MAX_NUM_CFG)
                  {
                    if(modemp[0].configfilefext1[embMsgRequest->Body(1)].LengthTxt !=  TXT_CUR_REAL_LEN)
                    { 
                     for(i=0; i < TXT_CUR_REAL_LEN; i++)
                      {
                   //    embMsgAns.SetBody((i+1),i);
                       embMsgAns.SetBody((i+1),0);
                      }
                    }
                    else
                    { 
//                     for(i=0; i < modemp[0].configfilefext.LengthTxt; i++)
                   //   if(embMsgRequest->Body(1) < MAX_NUM_CFG)
#ifdef FIND_CONF_ERR                   
                   printfpd("\n\r50_1_____:%d \n\r", embMsgRequest->Body(1));
#endif                   
                      for(i=0; i < 104; i++)
                      {
#ifdef FIND_CONF_ERR                      
                       printfpd(" %02X", modemp[0].configfilefext1[embMsgRequest->Body(1)].ConfigTxtData.Data[i]);
#endif
                       embMsgAns.SetBody((i+1), modemp[0].configfilefext1[embMsgRequest->Body(1)].ConfigTxtData.Data[i]);
                      }
#ifdef FIND_CONF_ERR                      
                   printfp("\n\r50_1_____<<<<<<<<");
#endif   
                      
                    } 
                   } //< MAX_NUM_CFG  
                   else
                   { /* Body */
                     for(i=0; i < TXT_CUR_REAL_LEN; i++)
                      {
                       embMsgAns.SetBody((i+1),i);
                   //    embMsgAns.SetBody((i+1),0);
                      }
                  } /* Endbody */
              
                 }
                  else if(embMsgRequest->Body(0) == 2)
                  {
                  
                    embMsgAns.SetLength(2);
                    embMsgAns.SetBody(0,2);
                    embMsgAns.SetBody(1,(GetNumConfigFile(0) & CONFIG_FILE_MASK));
                  }
                   else if(embMsgRequest->Body(0) == 3)
                  {
                   if(embMsgRequest->Length() == 2) //120608
                   {    //120608
                    embMsgAns.SetLength(2);
                    embMsgAns.SetBody(0,3);
                    embMsgAns.SetBody(1,embMsgRequest->Body(1));
                     if(embMsgRequest->Body(1) < MAX_NUM_CFG)
                     { 
#ifdef YOURNAL        //before init
  Add_Event(EV_COMMAND_CONFIG, 0, NULL);
#endif //YOURNAL 
                     
                       InitSetConfigFile(embMsgRequest->Body(1));
                     }
                    }   //120608
                  }
                  else if(embMsgRequest->Body(0) == 4)
                  {
                    embMsgAns.SetLength(2);
                    embMsgAns.SetBody(0,4);
                    embMsgAns.SetBody(1,embMsgRequest->Body(1));
                    InitSetACMMask((embMsgRequest->Body(1) + embMsgRequest->Body(2) << 1) );
                  }
                  
                   break;
                   
               case 0x51: // 
						embMsgAns.SetType(0x51);
                  embMsgAns.SetLength(E1_LINES_QUANTITY);
                   for(i=0; i < E1_LINES_QUANTITY; i++)
                      {
                       embMsgAns.SetBody(i,(unsigned char)modemp[0].netE1Alarms[i]);
                      }
                    break;

              case 0x52: // 
						embMsgAns.SetType(0x52);
              //    embMsgAns.SetLength(8);
                  embMsgAns.SetLength(32);
                   for(i=0; i < 32; i+=4)
                      {
                      /* 110922
                       embMsgAns.SetBody(i,  modemp[0].txAcmProfilesCounter[i>>2]);
                       embMsgAns.SetBody(i+1,modemp[0].txAcmProfilesCounter[i>>2]>>8);
                       embMsgAns.SetBody(1,modemp[0].txAcmProfilesCounter[i>>2]>>8);
                       embMsgAns.SetBody(dy(i+3,modemp[0].txAcmProfilesCounter[i>>2]>>24);
                       modemp[0].txAcmProfilesCounter[i>>2] = 0;
                       */
                       embMsgAns.SetBody(i,  modemp[0].rxAcmProfilesCounter[i>>2]);
                       embMsgAns.SetBody(i+1,modemp[0].rxAcmProfilesCounter[i>>2]>>8);
                       embMsgAns.SetBody(i+2,modemp[0].rxAcmProfilesCounter[i>>2]>>16);
                       embMsgAns.SetBody(i+3,modemp[0].rxAcmProfilesCounter[i>>2]>>24);
                       modemp[0].rxAcmProfilesCounter[i>>2] = 0;
         
                      }
                    break;
       case 0x55: // trunks
                  SetModForSS((unsigned long)embMsgRequest->Body(0));
						embMsgAns.SetType(0x55);
              //    embMsgAns.SetLength(8);
                  embMsgAns.SetLength(1);
                  embMsgAns.SetBody(0,(unsigned char) GetModForSS());
                    break;

       case 0x56: // power
           //      printfpd("\n\r56 : %X",embMsgRequest->Body(0));
                  SetModForSS1((unsigned long)embMsgRequest->Body(0));
						embMsgAns.SetType(0x56);
              //    embMsgAns.SetLength(8);
                  embMsgAns.SetLength(1);
                  embMsgAns.SetBody(0,(unsigned char) (GetModForSS1()));
                    break;
                    
         case 0x57: //eth 
                //  printfpd("\n\r57 : %X",embMsgRequest->Body(0));
                  SetModEth((unsigned long)embMsgRequest->Body(0));
                   StartEth(1); //151005
						embMsgAns.SetType(0x57);
              //    embMsgAns.SetLength(8);
                  embMsgAns.SetLength(1);
                  embMsgAns.SetBody(0,(unsigned char)(((inportb(BLOCK_SWEEP1 + STATUS_ETH_PORT) << 1) + (GetModEth() & ETH_AUTO))));
                    break;

 
 /*
//________________________________________________________________________bmdn1
					case 0x50: // 
						embMsgAns.SetType(0x50);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[0].byte[i]);
						unStateBMD155p[0].stateBMD155.count_block=0;
						unStateBMD155p[0].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[0].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[0].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[0].stateBMD155.count_notRS1=0;
						unStateBMD155p[0].stateBMD155.count_notRS2=0;
						unStateBMD155p[0].stateBMD155.demPI=0;
						unStateBMD155p[0].stateBMD155.loopPI=0;
						unStateBMD155p[0].stateBMD155.statePI=0;
						break;
//________________________________________________________________ 
#ifndef PROG_BMDN3
					case 0x51: // 
						embMsgAns.SetType(0x51);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[1].byte[i]);
						unStateBMD155p[1].stateBMD155.count_block=0;
						unStateBMD155p[1].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[1].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[1].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[1].stateBMD155.count_notRS1=0;
						unStateBMD155p[1].stateBMD155.count_notRS2=0;
						unStateBMD155p[1].stateBMD155.demPI=0;
						unStateBMD155p[1].stateBMD155.loopPI=0;
						unStateBMD155p[1].stateBMD155.statePI=0;
						break;
//________________________________________________________________
					case 0x52: // 
						embMsgAns.SetType(0x52);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[2].byte[i]);
						unStateBMD155p[2].stateBMD155.count_block=0;
						unStateBMD155p[2].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[2].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[2].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[2].stateBMD155.count_notRS1=0;
						unStateBMD155p[2].stateBMD155.count_notRS2=0;
						unStateBMD155p[2].stateBMD155.demPI=0;
						unStateBMD155p[2].stateBMD155.loopPI=0;
						unStateBMD155p[2].stateBMD155.statePI=0;
						break;
//________________________________________________________________ 
					case 0x53: // 
						embMsgAns.SetType(0x53);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[3].byte[i]);
						unStateBMD155p[3].stateBMD155.count_block=0;
						unStateBMD155p[3].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[3].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[3].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[3].stateBMD155.count_notRS1=0;
						unStateBMD155p[3].stateBMD155.count_notRS2=0;
						unStateBMD155p[3].stateBMD155.demPI=0;
						unStateBMD155p[3].stateBMD155.loopPI=0;
						unStateBMD155p[3].stateBMD155.statePI=0;
						break;
//________________________________________________________________                      
					case 0x54: // 
						embMsgAns.SetType(0x54);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[4].byte[i]);
						unStateBMD155p[4].stateBMD155.count_block=0;
						unStateBMD155p[4].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[4].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[4].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[4].stateBMD155.count_notRS1=0;
						unStateBMD155p[4].stateBMD155.count_notRS2=0;
						unStateBMD155p[4].stateBMD155.demPI=0;
						unStateBMD155p[4].stateBMD155.loopPI=0;
						unStateBMD155p[4].stateBMD155.statePI=0;
						break;
//________________________________________________________________ 
					case 0x55: // 
						embMsgAns.SetType(0x55);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[5].byte[i]);
						unStateBMD155p[5].stateBMD155.count_block=0;
						unStateBMD155p[5].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[5].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[5].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[5].stateBMD155.count_notRS1=0;
						unStateBMD155p[5].stateBMD155.count_notRS2=0;
						unStateBMD155p[5].stateBMD155.demPI=0;
						unStateBMD155p[5].stateBMD155.loopPI=0;
						unStateBMD155p[5].stateBMD155.statePI=0;
						break;
//________________________________________________________________
					case 0x56: // 
						embMsgAns.SetType(0x56);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[6].byte[i]);
						unStateBMD155p[6].stateBMD155.count_block=0;
						unStateBMD155p[6].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[6].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[6].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[6].stateBMD155.count_notRS1=0;
						unStateBMD155p[6].stateBMD155.count_notRS2=0;
						unStateBMD155p[6].stateBMD155.demPI=0;
						unStateBMD155p[6].stateBMD155.loopPI=0;
						unStateBMD155p[6].stateBMD155.statePI=0;
						break;
//________________________________________________________________ 
					case 0x57: // 
						embMsgAns.SetType(0x57);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155p[7].byte[i]);
						unStateBMD155p[7].stateBMD155.count_block=0;
						unStateBMD155p[7].stateBMD155.count_no_correct_block1=0;
						unStateBMD155p[7].stateBMD155.count_no_correct_block2=0;
						unStateBMD155p[7].stateBMD155.count_no_correct_result=0;
						unStateBMD155p[7].stateBMD155.count_notRS1=0;
						unStateBMD155p[7].stateBMD155.count_notRS2=0;
						unStateBMD155p[7].stateBMD155.demPI=0;
						unStateBMD155p[7].stateBMD155.loopPI=0;
						unStateBMD155p[7].stateBMD155.statePI=0;
						break;
                  
#endif //no PROG_BMDN3                 
//________________________________________________________________  
					  case 0x58: // Cai?in ninoiyiey
							embMsgAns.SetType(0x58);
							embMsgAns.SetLength(42);
						 	ength(42);
						 	mbMsgAns.SetBody(i,unStatePUMp[0].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[0].byte[i]);
						break;
//________________________________________________________________ 
#ifndef PROG_BMDN3 
					  case 0x59: // Cai?in ninoiyiey
							embMsgAns.SetType(0x59);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[1].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[1].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5A: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5A);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[2].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[2].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5B: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5B);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[3].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[3].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5C: // Cai?in nino__________________________________________________  
					  case 0x5C: // Cai?in nino=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[4].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[4].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5D: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5D);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[5].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[5].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5E: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5E);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[6].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[6].byte[i]);
						break;
//________________________________________________________________  
					  case 0x5F: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5F);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[7].byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUMp[7].byte[i]);
						break;
 #endif //no PROG_BMDN3                
//________________________________________________________________________bmdn1                        
    
                   case 0x60: // Modem Status                   
							embMsgAns.SetType(0x60);
                                       //need check all sizes! 
                     embMsgAns.SetLength(1+ (MODEM_QUANTITY * 20));
                     embMsgAns.SetBody(0 , embMsgRequest->Body(0));
                     for( i = 0; i < MODEM_QUANTITY; i += 20)
                     { 
                     embMsgAns.SetBody(i*20+1,modemp[embMsgRequest->Body(0)].acmEngineEnabled);
                     embMsgAns.SetBody(i*20+2,modemp[embMsgRequest->Body(0)].txAcmProfile);
                     embMsgAns.SetBody(i*20+3,modemp[embMsgRequest->Body(0)].rxAcmProfile);
                     embMsgAns.SetBody(i*20+4,modemp[embMsgRequest->Body(0)].txAcmProfilesCounter[embMsgRequest->Body(1)]);
                     embMsgAns.SetBody(i*20+5,(modemp[embMsgRequest->Body(0)].txAcmProfilesCounter[embMsgRequest->Body(1)] >> 8));
                     embMsgAns.SetBody(i*20+6,(modemp[embMsgRequest->Body(0)].txAcmProfilesCounter[embMsgRequest->Body(1)] >> 16));
                     embMsgAns.SetBody(i*20+7,(modemp[embMsgRequest->Body(0)].txAcmProfilesCounter[embMsgRequest->Body(1)] >> 24));
                     embMsgAns.SetBody(i*20+8,modemp[embMsgRequest->Body(0)].rxAcmProfilesCounter[embMsgRequest->Body(1)]);
                     embMsgAns.SetBody(i*20+9,(modemp[embMsgRequest->Body(0)].rxAcmProfilesCounter[embMsgRequest->Body(1)] >> 8));
                     embMsgAns.SetBody(i*20+10,(modemp[embMsgRequest->Body(0)].rxAcmProfilesCounter[embMsgRequest->Body(1)] >> 16));
                     embMsgAns.SetBody(i*20+11,(modemp[embMsgRequest->Body(0)].rxAcmProfilesCounter[embMsgRequest->Body(1)] >> 24));
                     embMsgAns.SetBody(i*20+12,modemp[embMsgRequest->Body(0)].acquireStatus);
                     embMsgAns.SetBody(i*20+13,(modemp[embMsgRequest->Body(0)].counterSlip >> 8));
                     embMsgAns.SetBody(i*20+14,modemp[embMsgRequest->Body(0)].counterSlip);
                     embMsgAns.SetBody(i*20+15,(modemp[embMsgRequest->Body(0)].absoluteMseTenths >> 8));
                     embMsgAns.SetBody(i*20+16,modemp[embMsgRequest->Body(0)].absoluteMseTenths);
                     embMsgAns.SetBody(i*20+17,(modemp[embMsgRequest->Body(0)].normalizedMseTenths >> 8));
                     embMsgAns.SetBody(i*20+18,modemp[embMsgRequest->Body(0)].normalizedMseTenths);
                     embMsgAns.SetBody(i*20+19,(modemp[embMsgRequest->Body(0)].radialMseTenths >> 8));
                     embMsgAns.SetBody(i*20+20,modemp[embMsgRequest->Body(0)].radialMseTenths);
                     break;
                     } 
						 	break;
                     
      
                    case 0x61: //  ModemAcmThresholdSet
                    embMsgAns.SetType(0x61);
                    embMsgAns.SetLength(1);
                    
                    if(
                    (embMsgRequest->Body(0) < MODEM_QUANTITY)  &&  
                    (embMsgRequest->Body(1) < TABLE_QUANTITY)  &&
                    (embMsgRequest->Body(2) < ACM_MODES)       &&
                    (embMsgRequest->Body(7) < ACM_MODES)
                     )
                    { 
                   ldeviceindex = embMsgRequest->Body(0);
                   lengineTable = embMsgRequest->Body(1);
                   lprofile = embMsgRequest->Body(2);
                   lmseTenthsVal =  embMsgRequest->Body(3);
                   lldpcMantissaTenths = embMsgRequest->Body(4); 
                   lldpcExponent = embMsgRequest->Body(5); 
                   lcriteria = embMsgRequest->Body(6);
                   lnextProfile  = embMsgRequest->Body(7);
                   embMsgAns.SetBody(0, 0); 
                   UsedExp.State.Reg2.bit.AcmTrR = 1;   UsedExp.State.Reg2.bit.Some = 1;
                   }
                   else
                   {
                       embMsgAns.SetBody(0, 0);
                   } 

 			           break;
                    case 0x62: //AcmConfigurationGet
                      
                     embMsgAns.SetType(0x62);
							embMsgAns.SetLength(ACM_MODES + 1);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     UsedExp.State.Reg2.bit.RAConfR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     ldeviceindex1 = embMsgRequest->Body(0);

                     for(i=0; i < (ACM_MODES); i++)
                     {
                      embMsgAns.SetBody((i + 1), modemp[embMsgRequest->Body(0)].modulation[i]);
                     }
                     }
                     else
                     { 
                      for(i=0; i < (ACM_MODES); i++)
                      {
                       embMsgAns.SetBody((i + 1), 0);
                      }
                     } 
                      break;
                      
                     case 0x63: //ModemAcmProfileEnable
                      
                     embMsgAns.SetType(0x63);
							embMsgAns.SetLength(1);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex2 = embMsgRequest->Body(0);
                     lprofile2 = embMsgRequest->Body(1);
                     lprofile2 <<= 8;
                     lprofile2 += embMsgRequest->Body(2);
                     UsedExp.State.Reg2.bit.AcmPrEnR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     embMsgAns.SetBody(0, 0);   
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);   
                     }
                      break;

                    case 0x64: //ModemAcmEngineEnable
                      
                     embMsgAns.SetType(0x64);
							embMsgAns.SetLength(1);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex3 = embMsgRequest->Body(0);
                     ltx = embMsgRequest->Body(1);
                     lrx = embMsgRequest->Body(2);
                     UsedExp.State.Reg2.bit.AcmEnR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     embMsgAns.SetBody(0, 0);   
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);   
                     }
                    break;      embMsgAns.SetBody(0, 1);   
                     }
                    break;  
                     embMsgAns.SetType(0x65);
							embMsgAns.SetLength(4);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex4 = embMsgRequest->Body(0);
            
            
                     UsedExp.State.Reg2.bit.MaskGetR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                    embMsgAns.SetBody(0, 0); 
                    embMsgAns.SetBody(1, embMsgRequest->Body(0));
                    embMsgAns.SetBody(2, modemp[ldeviceindex4].profilesMask >> 8); 
                    embMsgAns.SetBody(3, modemp[ldeviceindex4].profilesMask); 
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);   
                     }
                       break;
                      

                  case 0x66: //  ModemAcmSwitch
                                        
                     embMsgAns.SetType(0x66);
							embMsgAns.SetLength(1);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex5 = embMsgRequest->Body(0);
                     lacmprofile = embMsgRequest->Body(1);
                     lislocal = embMsgRequest->Body(2);
            
                     UsedExp.State.Reg2.bit.AcmSwR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                       embMsgAns.SetBody(0, 0); 
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);   
                     }
                     break;


        case 0x67: // Protection on / off
                                        
                     embMsgAns.SetType(0x67);
							embMsgAns.SetLength(1);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex6 = embMsgRequest->Body(0);
                     lprot = embMsgRequest->Body(1);
                     UsedExp.State.Reg2.bit.ChPr = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                      embMsgAns.SetBody(0, 0); 
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);   
                     }
                    break;


       case 0x68: // Protection status read
                                        
                     embMsgAns.SetType(0x68);
							embMsgAns.SetLength(3);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex7 = embMsgRequest->Body(0);
                     UsedExp.State.Reg2.bit.ProtSt = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     embMsgAns.SetBody(0, 0); 
                     embMsgAns.SetBody(1, modemp[ldeviceindex7].ProtectionRxState);
                     embMsgAns.SetBody(2,modemp[ldeviceindex7].rxPhyId);
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);  
                      embMsgAns.SetBody(1, 0); 
                      embMsgAns.SetBody(2, 0);  
                       
                     }
                    break;
                    
       case 0x69: // acm counters read
                                        
                     embMsgAns.SetType(0x69);
							embMsgAns.SetLength(3);
                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     ldeviceindex8 = embMsgRequest->Body(0);
                     UsedExp.State.Reg2.bit.AcmCntR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     embMsgAns.SetBody(0, 0); 
                     embMsgAns.SetBody(1, modemp[ldeviceindex8].acmRxProfilesHistory);
                     embMsgAns.SetBody(2, modemp[ldeviceindex8].acmTxProfilesHistory);
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);  
                      embMsgAns.SetBody(1, 0); 
                      embMsgAns.SetBody(2, 0);  
                       
                     }
                    break;

          */
      case 0x70: // read data text file
                  //   printfpd("\n\rrfil : %d ", embMsgRequest->Body(0));              
                     embMsgAns.SetType(0x70);
//							embMsgAns.SetLength(3);
//                     embMsgAns.SetBody(0, embMsgRequest->Body(0));
                     
                     if(embMsgRequest->Body(0) < MODEM_QUANTITY)
                     {
                     embMsgAns.SetLength(modemp[embMsgRequest->Body(0)].configfilefext.LengthTxt);

                       for(i=0; i < (modemp[embMsgRequest->Body(0)].configfilefext.LengthTxt); i++)
                      {
                       embMsgAns.SetBody((i), modemp[embMsgRequest->Body(0)].configfilefext.ConfigTxtData.Data[i]);
                      }
 
                     
                     ldeviceindex8 = embMsgRequest->Body(0);
                     UsedExp.State.Reg2.bit.AcmCntR = 1;
                     UsedExp.State.Reg2.bit.Some = 1;
                     embMsgAns.SetBody(0, 0); 
                     embMsgAns.SetBody(1, modemp[ldeviceindex8].acmRxProfilesHistory);
                     embMsgAns.SetBody(2, modemp[ldeviceindex8].acmTxProfilesHistory);
                     }
                      else
                     { 
                      embMsgAns.SetBody(0, 1);  
                      embMsgAns.SetBody(1, 0); 
                      embMsgAns.SetBody(2, 0);  
                       
                     }
                    break;
            /*
       case 0x55: // 
                  SetModForSS((unsigned long)embMsgRequest->Body(0));
						embMsgAns.SetType(0x55);
              //    embMsgAns.SetLength(8);
                  embMsgAns.SetLength(1);
                  embMsgAns.SetBody(0,(unsigned char) GetModForSS());
                    break;
            
       case 0xEE: // 
                  printfpd(" %02X",embMsgRequest->Body(0));
                  printfpd(" %02X",embMsgRequest->Body(1));
				 //		embMsgAns.SetType(0xEE);
             		embMsgAns.SetType(0);
                  embMsgAns.SetLength(0);
                     break;
               */

					}  //switch

