// file: answerpum.cpp
///////////////////////////////
///   answer  ///
///////////////////////////////

//________________________________________________________________________

#ifdef RS485_MSG_BUFF
		   if(flag_wait_rs485)
		   {
		   if(time1 < time_lastsend_rs485) 	time_lastsend_rs485 = time1;
		   if((time1 - time_lastsend_rs485) > RS485_TRANS_TIMEOUT)	flag_wait_rs485 = 0;
		   }


 			if(tBuffRS485.Used() && (!(flag_wait_rs485)) )	//090713
			{
			   flag_wait_rs485 = 1;
			   time_lastsend_rs485 = time1;
			//	EmbMsg embMsgA;
				embMsgA.Init();
				tBuffRS485.Get(embMsgA);
            
           // embMsgA.SetRS485(); //26
 //#ifndef  RS485_DISABLED

        //       usart0_s_req_ant++;
        //       printfpd("\n\n\rs_req_ant> %d \n",usart0_s_req_ant);//ok


				embRS232S.Trans2(0x55);	  //EC - RDN!!! in all
			  	embRS232S.Trans2(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
								case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
								case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
								case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
								default:
                        { 
                         embRS232S.Trans2(embMsgA.body[i]);
#ifdef KSS_PRINT_LOG                         
                         printfpd("_%02X", embMsgA.body[i]);
#endif                         
                         }
								}
							   //	RS485_receive_reset();
							}
						   
							embRS232S.Trans2(0x55);
//#endif    //   RS485_DISABLED

//#endif //   RS485E_ENABLED
			}

#endif //RS485_MSG_BUFF

#ifdef   CHANGE_USART12
	else	 if(embMsg232S.IsEnd()) 
   
				{   //isend
            
#ifdef CHECK_CRC           
       if(embMsg232S.ChkCRC())   
#else       
       if(1)
#endif       
				{  //crc
            
            
            
            
 #ifdef KSS_PRINT_LOG 
			  		printfp("\n\r___________________________1\n\r");
                    printfpd("S : %X ", embMsg232S.AddrS());
                    printfpd("R : %X ", embMsg232S.AddrR());
                    printfpd("I : %X ", embMsg232S.AddrI());
 #endif
               
               
               
					if(embMsg232S.AddrS()==embMsg232S.AddrR())
					{
#ifdef KSS_PRINT_LOG                
               	printfp("\n\r___________________________1a");
#endif
					  	// ->>	// Ioaao a RS-232
					  	aI = embMsg232S.AddrI();
							aS = embMsg232S.AddrS();
							aR = embMsg232S.AddrR();
							 /*
							embMsg232S.SetAddrI(aR);
							embMsg232S.SetAddrS(aI);
							embMsg232S.SetAddrR(aS);
							  */
							embMsg232S.SetAddrI(aR);	 //t 091019
							embMsg232S.SetAddrS(aS);	 //t 091019
							embMsg232S.SetAddrR(aI);	 //t 091019



                  //   printfp("\n\r>");
                  
							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg232S.FullSize(); i++) 
							{
								switch(embMsg232S.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg232S.body[i]);
                  //      printfpd("*%02X*",embMsg232S.body[i]);
								}
							}
							embRS232.Trans(0x55);
                     
					   //	   embRS232.Trans_RDN(COMP_DEF_MAC_END); //temporary send to mac 001111000000
//						   embRS232.Trans_RDN_Full(embRS232.HostMAC);	
					   embMsg232S.Init();
				 	}
					
					if(embMsg232S.AddrR()!=embMsg232S.AddrS())
					{
#ifdef KSS_PRINT_LOG                
                  	printfp("\n\r___________________________2\n\r");
#endif                     
                 //    printfpd("S : %X ", embMsg232S.AddrS());
                  //   printfpd("R : %X ", embMsg232S.AddrR());
                  //   printfpd("I : %X ", embMsg232S.AddrI());

			  //		printf("2");
						if(embMsg232S.AddrS()==SelfID())
						{
#ifdef KSS_PRINT_LOG                   
                     	printfp("\n\r___________________________3");
#endif
				 //		printf("3");

						// ->>	// O?aiceoii ioaao a eeie?
							if(embMsg232S.TOM() & 0x01)
							{
								aI = embMsg232S.AddrI();
								aS = embMsg232S.AddrS();
								aR = embMsg232S.AddrR();
                         
								embMsg232S.SetAddrI(aS);
								embMsg232S.SetAddrS(aR);
								embMsg232S.SetAddrR(aI);
                                                    
	                 //    embMsg232S.SetAddrI(aI);
							//	embMsg232S.SetAddrS(aS);
						  //		embMsg232S.SetAddrR(aR);
                          
                    //    printEthLongHex(1);
#ifdef FIND_CONF_ERR
		printfp("6");
#endif                              

								tBuffEmbMsgEast.Add(embMsg232S);
								tBuffEmbMsgWest.Add(embMsg232S);
//_____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 110902
                        tBuffEmbMsgNorth.Add(embMsg232S);
								tBuffEmbMsgSouth.Add(embMsg232S);
//____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 110902        

                        

								unEmb2NetStat.emb2NetStat.selfPacketSend++;	
						 		embMsg232S.Init(); //my			
                   flagRequest=0;  //26
			
							}
							else
							{
#ifdef KSS_PRINT_LOG                      
                        	printfp("\n\r___________________________4");
#endif
					 //		printf("4");
								// ->>	// Iieo?eee cai?in ec RS-485
								flagRequest=3;
								embMsg232S.SetRS485();
								embMsgRequest = &embMsg232S;
							}
                     
                     
						}  //s = self
                  else
                  { 
                  
//_____________________________________________________________
#ifdef KSS_PRINT_LOG 
  	printfp("\n\r___________________________5\n\r");
#endif    
    // flagRequest=0;
     embMsg232S.Init();
                  } 
					}	//r != S
//____________________________________________ crc              
              }   //crc
              else
              { 
                  embMsg232S.Init();
              }  //crc
//_______________________________________________crc  
				}  //embMsg232S.isend


#endif  //CHANGE_USART12           
//#endif // RS485_DISABLED
   
//130114 not request from rs485  		  else //10.24
         /*
  			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
        	{
 #ifdef  DEBUG_TRANZIT 
          if( embMsg232.AddrS() == 0x6431) {  printfp("_p_");}
 #endif        
         
			//	{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
			  //	}
			}
         */
      if(rBuffEmbMsg232.Used())
				{
//#ifdef FIND_CONF_ERR
//		printfp("1");
//#endif      
		//			EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsg232.Get(embMsgA);
 #ifdef  DEBUG_TRANZIT 
        //  if( embMsgA.AddrS() == 0x6431) {  printfp("_p_");}
            if( embMsgA.AddrS() == 0x7766) {  printfp("_p_");}

 #endif        
         
			//	{
				  embMsgRequest = &embMsgA;
					flagRequest=1;
			  //	}
			}
			else
			{
         
//_______________________________________________need replace to 4 buffers with send to 3 direction         
//========================================================         
				if(rBuffEmbMsgWest.Used())
				{
				//	printf("1");
#ifdef FIND_CONF_ERR
		printfp("1");
#endif                
		  //		  //Msg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgWest.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{
											
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}	//for
								embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//								embRS232.Trans_RDN_Full(embRS232.HostMAC);	

								flagRequest = 0;
							}  //s
						}  //tom 20
					}      //tom 1
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=21;
								embMsgRequest = &embMsgA;
							}
						}
					} // tom 1
				}  //rbufembmsg
//========================================================================            
//======================================================== 
           if(!flagRequest)
				if(rBuffEmbMsgEast.Used())
				{
#ifdef FIND_CONF_ERR
		printfp("2");
#endif                
				//	printf("1");
        //     printEthLongHex(6);
			 //		EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgEast.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{
											
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}	//for
								embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//								embRS232.Trans_RDN_Full(embRS232.HostMAC);	

								flagRequest = 0;
							}  //s
						}  //tom 20
					}      //tom 1
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
             //         printEthLongHex(7);

								flagRequest=22;
								embMsgRequest = &embMsgA;
							}
						}
					} // tom 1
				}  //rbufembmsg
//========================================================================            
//========================================================         
			    if(!flagRequest)
         	if(rBuffEmbMsgNorth.Used())
				{
#ifdef FIND_CONF_ERR
		printfp("3");
#endif                
				//	printf("1");
			 //		EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgNorth.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{
											
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}	//for
								embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//								embRS232.Trans_RDN_Full(embRS232.HostMAC);	

								flagRequest = 0;
							}  //s
						}  //tom 20
					}      //tom 1
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=23;
								embMsgRequest = &embMsgA;
							}
						}
					} // tom 1
				}  //rbufembmsg
//========================================================================            
//========================================================         
			   if(!flagRequest)
         	if(rBuffEmbMsgSouth.Used())
				{
#ifdef FIND_CONF_ERR
		printfp("4");
#endif                
				//	printf("1");
			  //		EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgSouth.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{
											
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}	//for
								embRS232.Trans(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//								embRS232.Trans_RDN_Full(embRS232.HostMAC);	

								flagRequest = 0;
							}  //s
						}  //tom 20
					}      //tom 1
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=24;
								embMsgRequest = &embMsgA;
							}
						}
					} // tom 1
				}  //rbufembmsg
//========================================================================            

            
//_________________________________________________will be replaced    







        

			}


			if(flagRequest) //embMsgRequest->IsEnd())
			{
		//  	  printf(" f:%d",flagRequest );

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());

 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
				 //t26			embMsgRequest->SetAddrI(aS);
				 //t26			embMsgRequest->SetAddrS(aR);
				 //t26			embMsgRequest->SetAddrR(aI);
             
             //6267 6267 6548
           //    printfpd("\n\r i:%x", embMsgRequest->AddrI());
           //    printfpd("\n\r s:%x", embMsgRequest->AddrS());
           //    printfpd("\n\r r:%x", embMsgRequest->AddrR());

             
                     /*27
				 			embMsgRequest->SetAddrI(aR);
				 			embMsgRequest->SetAddrS(aI);
				 			embMsgRequest->SetAddrR(aS);
                       */
                       
                     embMsgRequest->SetAddrI(aS);
				 			embMsgRequest->SetAddrS(aR);
				 			embMsgRequest->SetAddrR(aI);

             
             

				   //			RS485_disable_RX_interrupt();
             
#ifndef RS485_MSG_BUFF

//need transe get off
       
                     
#else  //	 RS485_MSG_BUFF


		tBuffRS485.Add(*embMsgRequest);  //? need self buff for rs232S
#endif	//   RS485_MSG_BUFF


					 //	  }
					//    }
                flagRequest = 0;	//121127
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
						else   //flagRequest == 3 or 4
						{
				 //		printf("\n\r I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

						//	embMsgRequest->SetAddrI(aS);   //t	 091019
						//	embMsgRequest->SetAddrS(aR);   //t	091019
						//	embMsgRequest->SetAddrR(aI);   //t	091019
							  
				   //100118			embMsgAns.SetAddrI(aR);
				   //100118			embMsgAns.SetAddrS(aI);
				   //100118			embMsgAns.SetAddrR(aS);

							embMsgAns.SetAddrI(aS);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aR);

							
						}	 //==3
		  //				printf("5");
		//100118			   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
          //23     usart0_request_cnt++;
          //23     printfpd("\n\n\rreq> %d \n",usart0_request_cnt);//ok
            //ok     printEthLongHex(8);
               //  printEthLongHex(8);
                 
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			   //ok 1			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());

					//	embMsgAns.SetAddrI(SelfID());  //t
					//	embMsgAns.SetAddrS(SelfID());  //t


				switch(embMsgRequest->Type())
					{
					case 0x01: // запрос типа

			   //		printEthLongHex(0x01);

					 //	embMsgAns.SetAddrI(SelfID());  //t
					 //	embMsgAns.SetAddrS(SelfID());  //t

						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

		  //			case 0x05: // Загрузка файла (запись в устройство) 

		  //				SaveFile();
		  //				break;
					 

//______________________________________________________________________________________________						
					case 0x02 :
			   //		printEthLongHex(0x02);

						   embMsgAns.SetType(0x02);
						   embMsgAns.SetLength(embMsgRequest->Body(2) + 3);
						   embMsgAns.SetBody(0,embMsgRequest->Body(0));	//#	number 1 Byte
						   embMsgAns.SetBody(1,embMsgRequest->Body(1));	//#	number 2 Byte
						   embMsgAns.SetBody(2,embMsgRequest->Body(2));	// celling

						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							write_xil_char( ( (embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i), embMsgRequest->Body(3 + i));
						   }


						   for( i = 0; i < embMsgRequest->Body(2); i++)
						   {
							 embMsgAns.SetBody(3 + i ,read_xil_char((embMsgRequest->Body(0)<<8) + embMsgRequest->Body(1) + i));
						   }
							//need make GetPort
					    break;
					   	   				

			 
					case 0x05: // Загрузка файла (запись в устройство) 
				//	printEthLongHex(0x05);

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
			  //		printEthLongHex(0x38);

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

					case 0x08: // Запрос состояния
				//	printEthLongHex(0x08);

						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155.byte[i]);
						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
//						unStateBMD155.stateBMD155.demPI=0;
//						unStateBMD155.stateBMD155.loopPI=0;
//						unStateBMD155.stateBMD155.statePI=0;
						break;
					case 0x09:
			  	//	printEthLongHex(0x09);

						if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
					   //		printEthLongHex(0x91);
								embMsg485Request_1.Init();
								embMsg485Request_1.SetAddr(0);//embMsg.Body(0));
								embMsg485Request_1.SetLength(2);
								embMsg485Request_1.SetBody(0,embMsgRequest->Body(1));
								embMsg485Request_1.SetBody(1,embMsgRequest->Body(2));
								embMsg485Request_1.CalcCRC();
								embMsg485Request_1.SetReadyToSend();
							}
							if(embMsgRequest->Body(0)==2)
							{
								embMsg485Request_2.Init();
								embMsg485Request_2.SetAddr(0);//embMsg.Body(0));
								embMsg485Request_2.SetLength(2);
								embMsg485Request_2.SetBody(0,embMsgRequest->Body(1));
								embMsg485Request_2.SetBody(1,embMsgRequest->Body(2));
								embMsg485Request_2.CalcCRC();
								embMsg485Request_2.SetReadyToSend();
							}
						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
				//	printEthLongHex(0x0A);

						//			Запрос: Установить биты <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						//      Ответ: <Номер байта/16><Номер бита/8><Число бит/8><Значение/8>
						WritePort();
						break;
					case 0x0B:
				  //	printEthLongHex(0x0B);

						//      Запрос: Чтение порта: <Номер байта/16><Число байт/8>
						//      Ответ: <Номер байта/16><Число байт N/8><Байты/N >
						ReadPort();
						break;
					case 0x10:
			   //		printEthLongHex(0x10);

							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
							for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
						break;
					case 0x12: // Запрос состояния
			   //		printEthLongHex(0x12);


							embMsgAns.SetType(0x12);
							embMsgAns.SetLength(40);
              /*       
#ifdef PROG_PU_M_MUX
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unEmb2Mux34.byte[i]);
#endif // PROG_PU_M_MUX
          */
					break;
					case 0x13:
				//	printEthLongHex(0x13);

							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsg.Body(0));
							embMsgAns.SetBody(1,embMsg.Body(1));
							embMsgAns.SetBody(2,embMsg.Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsg.Body(2)<<8) +	embMsg.Body(1);

							bt = (unsigned char *)(NVRAM_BASE);
//							bt = (unsigned char far*)0x80000000;

							if(embMsg.Body(0)) *(bt + addr1)= embMsg.Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x14: // Запрос состояния
			   //		printEthLongHex(0x14);

							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
//							for(i=0; i<42; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);

						break;
	   				case 0x22:
							embMsgAns.SetType(0x22);

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

       /*
#ifdef USdef US5

					case 0x39: // request rs125 state

			   		// printEthLongHex(0x01);
					//	embMsgAns.SetAddrI(SelfID());  //t
					//	embMsgAns.SetAddrS(SelfID());  //t

						embMsgAns.SetType(0x39);
						embMsgAns.SetLength(MES_MAX_LEN);
						for(i=0; i<MES_MAX_LEN; i++) embMsgAns.SetBody(i,StatBuffer[i]);
						break;

					case 0x40: // request rs125 state

			   //		printEthLongHex(0x01);
			   //		embMsgAns.SetAddrI(SelfID());  //t
			   //		embMsgAns.SetAddrS(SelfID());  //t

						embMsgAns.SetType(0x40);
						embMsgAns.SetLength(MES_OCT_LEN);
						for(i=0; i<MES_OCT_LEN; i++) embMsgAns.SetBody(i,StatBuffer[i]);
						break;

					case 0x41: // request rs125 state

			   		// printEthLongHex(0x01);
					//	embMsgAns.SetAddrI(SelfID());  //t
					//	embMsgAns.SetAddrS(SelfID());  //t
						im = 0;
						embMsgAns.SetType(0x41);
						embMsgAns.SetLength(REAL_MES_LEN);
						for(i=0; i<MES_MAX_LEN; i++) 
						{
						if(IsNotRezerved(i))
							{
							embMsgAns.SetBody(im++,StatBuffer[i]);
							}
						}
						break;

					case 0x42: // request max, min , centered values of period of keep

			   			embMsgAns.SetType(0x42);
						embMsgAns.SetLength(MAX_MIN_CENTER_LEN);
						MakeStat();
				   		 for(i=0; i<MAX_MIN_CENTER_LEN; i++) 
				   		 {
				   	  		embMsgAns.SetBody(i,ukeep_st.byte[i]);
				   	  	 }
						
						break;






#endif //USE_RS125
                      */
                      
	case 0x4C: 
            	  embMsgAns.SetType(0x4C);
                 embMsgAns.SetLength((DEVCONFIG_QUANTITY << 1) + 2);
                 if(embMsgRequest->Body(0) > DEVCONFIG_QUANTITY)    //get current
                 {
                 for(i=0; i<((DEVCONFIG_QUANTITY << 1) + 2); i++) embMsgAns.SetBody(i,Getudevconfig(i));
                 }
                 else    //need set and write to flash
                 {
                  for(i=0; i<((DEVCONFIG_QUANTITY << 1) + 2); i++)
                  {
              
                   embMsgAns.SetBody(i,embMsgRequest->Body(i));
                   Setudevconfig((unsigned char)i,(unsigned char)embMsgRequest->Body(i));
                //   Setudevconfig(1,1); //t
                 //  SetNeedWriteDevId();
                  }
                  SetNeedWriteDevId();
                 } 
                	                  
                 break; 
                 
			case 0x4D: 
	  //		printfp("\n\r 4d"); //___________________________
            	  embMsgAns.SetType(0x4D);
                 embMsgAns.SetLength(DEV_INFO_SIZE + 4);
                 embMsgAns.SetBody(0,embMsgRequest->Body(0));
//_______________________________________________________________
           if((embMsgRequest->Body(0) <= DEVCONFIG_QUANTITY) && embMsgRequest->Body(0))
           {
           cur_rem_pointer = GetDevPointer(embMsgRequest->Body(0));
       //    printfp("ok quantityr");		//________________________

           if(cur_rem_pointer != BAD_POINTER)
            {
		//	printfp("ok pointer");	  //________________________

            embMsgAns.SetBody(1,GetDevType(cur_rem_pointer));
            embMsgAns.SetBody(2,devstate[embMsgRequest->Body(0) - 1]); 
            embMsgAns.SetBody(3,0);
            
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             embMsgAns.SetBody(4 + i,statedev[embMsgRequest->Body(0) - 1].byte[i]);  //addr from 1 to 16
            }
           
            }    // BAD_POINTER
            else
            { 
             for(i = 0; i < DEV_INFO_SIZE + 3; i++)
            {
             embMsgAns.SetBody(1 + i,0);  //addr from 1 to 16
            }
            } 
           } // DEVCONFIG_QUANTITy
            else
            { 
             for(i = 0; i < DEV_INFO_SIZE + 3; i++)
            {
             embMsgAns.SetBody(1 + i,0);  //addr from 1 to 16
            }
            } 
			   break;
        /*
	case 0x4E: // 

			   //		printEthLongHex(0x4e);

					 //	embMsgAns.SetAddrI(SelfID());  //t
					 //	embMsgAns.SetAddrS(SelfID());  //t

						embMsgAns.SetType(0x4E);
						embMsgAns.SetLength(32);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,uemb4pumfabinfo.byte[i]);
						break;

            */
                 
                      
    /*                  
	case 0x4D: 
            	  embMsgAns.SetType(0x4D);
                 embMsgAns.SetLength(DEV_INFO_SIZE + 4);
                 embMsgAns.SetBody(0,embMsgRequest->Body(0));
//_______________________________________________________________
           if((embMsgRequest->Body(0) <= DEVCONFIG_QUANTITY) && embMsgRequest->Body(0))
           {
           cur_rem_pointer = GetDevPointer(embMsgRequest->Body(0));
           
           if(cur_rem_pointer != BAD_POINTER)
            {
            embMsgAns.SetBody(1,GetDevType(cur_rem_pointer));
            embMsgAns.SetBody(2,devstate[embMsgRequest->Body(0) - 1]); 
            embMsgAns.SetBody(3,0);
            
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             embMsgAns.SetBody(4 + i,statedev[embMsgRequest->Body(0) - 1].byte[i]);  //addr from 1 to 16
            }
           
            }    // BAD_POINTER
            else
            { 
             for(i = 0; i < DEV_INFO_SIZE + 3; i++)
            {
             embMsgAns.SetBody(1 + i,0);  //addr from 1 to 16
            }
            } 
           } // DEVCONFIG_QUANTITy
            else
            { 
             for(i = 0; i < DEV_INFO_SIZE + 3; i++)
            {
             embMsgAns.SetBody(1 + i,0);  //addr from 1 to 16
            }
            } 
             */         
              case 0x53: // request max, min , centered values of period of keep

			   			embMsgAns.SetType(0x53);
                     
                      switch(embMsgRequest->Body(0))
							 {
							case 1:
                          embMsgAns.SetLength(12);
                          embMsgAns.SetBody(0, embMsgRequest->Body(0));
								  embMsgAns.SetBody(1, embMsgRequest->Body(1));
                          if(embMsgRequest->Body(1) > 2) break;
                          embMsgAns.SetBody(2, e4ust[embMsgRequest->Body(1)].mode);
                     //        embMsgAns.SetBody(2,4)
                          embMsgAns.SetBody(3, e4ust[embMsgRequest->Body(1)].x);
                          embMsgAns.SetBody(4, e4ust[embMsgRequest->Body(1)].x>>8);
                          embMsgAns.SetBody(5, e4ust[embMsgRequest->Body(1)].y);
                          embMsgAns.SetBody(6, e4ust[embMsgRequest->Body(1)].y>>8);
                          embMsgAns.SetBody(7, e4ust[embMsgRequest->Body(1)].flags);
                          embMsgAns.SetBody(8, e4ust[embMsgRequest->Body(1)].flags>>8);
                          embMsgAns.SetBody(9, e4ust[embMsgRequest->Body(1)].current);
                          embMsgAns.SetBody(10, e4ust[embMsgRequest->Body(1)].voltage);
                          embMsgAns.SetBody(11, e4ust[embMsgRequest->Body(1)].temp);
                      //    embMsgAns.SetBody(11, 0x12);
								 break;
							case 2:  
                     
//________________________________________________________121004
                     pamsgr = 0;
      keep_ans = 2; //need send to asu second message from rs485 first is self request
                     keep_is485 = embMsgRequest->IsRS485();
                     keep_addri = embMsgAns.AddrI();
                     keep_addrs = embMsgAns.AddrS();
                     keep_addrr = embMsgAns.AddrR();  
                     keep_flagrequest = flagRequest;
                     
                     amsgr.body[pamsgr++] =  embMsgRequest->IsRS485();
                     amsgr.body[pamsgr++] =  embMsgAns.AddrI()>>8;
                     amsgr.body[pamsgr++] =  embMsgAns.AddrI();
                     amsgr.body[pamsgr++] =  embMsgAns.AddrS()>>8;
                     amsgr.body[pamsgr++] =  embMsgAns.AddrS();
                     amsgr.body[pamsgr++] =  embMsgAns.AddrR()>>8;
                     amsgr.body[pamsgr++] =  embMsgAns.AddrR();
                     amsgr.body[pamsgr++] =  flagRequest;
                     
                     flagRequest = 0; //do not need answer now!!!!!
 //________________________________________________________121004                             
  //121004                        embMsgAns.SetLength(1);
 //121004                         embMsgAns.SetBody(0, embMsgRequest->Body(0));
                          
                          send_command = 1;
                        //  send_command = 2;
                          if(embMsgRequest->Body(1) > STR_UST_LEN) break;
                  //        printEthLongHex(embMsgRequest->Body(1));
                 //23         printfp("\n\n\r req : ");
                          command_str[0] = embMsgRequest->Body(1);
                          amsgr.body[pamsgr++] = embMsgRequest->Body(1);
                          for(i = 0; i < embMsgRequest->Body(1); i++)
                          { /* Body */
                          command_str[i+1] = embMsgRequest->Body(i + 2);
                          amsgr.body[pamsgr++] =  embMsgRequest->Body(i + 2);
                   //23         printfpd(" %02X", embMsgRequest->Body(i + 2));

                          } /* Endbody */
                   //23           printfp("\n\n\r ");
                           amsgbuffer.Add(amsgr);
                         // command_str[i] = 0; //olwais zero!
//________________________________________________________________121004
      		if(keep_flagrequest == 1) 
					{
         //      usart0_ans_cnt++;
         //      printfpd("\n\n\r> %d \n",usart0_ans_cnt);//ok
        //23       usart0_ans1_cnt++;
        //23       printfpd("\n\n\rreq_ans1> %d \n",usart0_ans1_cnt);//ok

				  		embMsg232.Init(); //090122
				  	}	//  == 1
	         if(keep_flagrequest == 3) 
					{
	    	  		 embMsg232S.Init();	//090122
 			 	   }	   // ==3

//________________________________________________________________121004                          
         					 break;
							case 3:          
                          embMsgAns.SetLength(1);
                          embMsgAns.SetBody(0, embMsgRequest->Body(0));
                          numa[0] = embMsgRequest->Body(1);
                          numa[1] = embMsgRequest->Body(2);
                          numa[2] = embMsgRequest->Body(3);
                          numb[0] = embMsgRequest->Body(4);
                          numb[1] = embMsgRequest->Body(5);
                          numb[2] = embMsgRequest->Body(6);
                          numc[0] = embMsgRequest->Body(7);
                          numc[1] = embMsgRequest->Body(8);
                          numc[2] = embMsgRequest->Body(9);
                           SetNeedWriteDevId();

                          break;
                         
						   case 4:          
                          embMsgAns.SetLength(10);
                          embMsgAns.SetBody(0, embMsgRequest->Body(0));
                          embMsgAns.SetBody(1, numa[0]);
                          embMsgAns.SetBody(2, numa[1]);
                          embMsgAns.SetBody(3, numa[2]);
                          embMsgAns.SetBody(4, numb[0]);
                          embMsgAns.SetBody(5, numb[1]);
                          embMsgAns.SetBody(6, numb[2]);
                          embMsgAns.SetBody(7, numc[0]);
                          embMsgAns.SetBody(8, numc[1]);
                          embMsgAns.SetBody(9, numc[2]);
                          
                   		 break;
                   case 0x54:
//hier need keep addresses af future answer and make request for ant
//future ansver vill be send in parser answers from antenna                   
                     keep_is485 = embMsgRequest->IsRS485();
                     keep_addri = embMsgAns.AddrI();
                     keep_addrs = embMsgAns.AddrS();
                     keep_addrr = embMsgAns.AddrR();  
                     keep_flagrequest = flagRequest;
                     
                     flagRequest = 0; //do not need answer now!!!!!
                     
                     
//need make to do not answer now 

	//                  WritePort();    //send command to antenna as to up1
      embMsg485Request_1.Init();
		embMsg485Request_1.SetAddr(0);//0x01);
		embMsg485Request_1.SetLength(4);//4
		embMsg485Request_1.SetBody(0,0x07);
		embMsg485Request_1.SetBody(1,embMsgRequest->Body(0));
		embMsg485Request_1.SetBody(2,embMsgRequest->Body(1)&0x3F);
		embMsg485Request_1.SetBody(3,embMsgRequest->Body(4));
		embMsg485Request_1.CalcCRC();
		embMsg485Request_1.SetReadyToSend();
      
    //     usart0_s_req_ant++;
    //     printfpd("\n\n\rs_req_ant> %d \n",usart0_s_req_ant);//ok
     
      		if(keep_flagrequest == 1) 
					{
				  		embMsg232.Init(); //090122
				  	}	//  == 1
	         if(keep_flagrequest == 3) 
					{
	    	  		 embMsg232S.Init();	//090122
 			 	   }	   // ==3
    break;        
                          
    default:   
    break;
                         
                        }
 
					}
//>>>>
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(flagRequest == 1) 
					{
         //23      usart0_ans_cnt++;
         //23      printfpd("\n\n\rans> %d \n",usart0_ans_cnt);//ok
               
						embRS232.Trans(0x55);
						embRS232.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsgAns.body[i]);
							}
						}
						embRS232.Trans(0x55);
			 //			embRS232.EmptyReceive();
						embMsg232.Init(); //090122
						flagRequest = 0;
					}	//  == 1
			   //	 for(long it = 0; it< 50; it++)	//t
            
//#ifndef  RS485_DISABLED
            
	  		if(flagRequest == 3) 
					{
			  //		RS485_receive_disable();
#ifndef RS485_MSG_BUFF
           
                     
						embRS485.Trans(0x55);
					//	 printf("\n\r>>>>embMsgRequest->AddrS() = %X", embMsgRequest->AddrS());	 //3310
					//	 printf("\n\r>>>>embMsgRequest->AddrI() = %X", embMsgRequest->AddrI());	 //	3309
					//	 printf("\n\r>>>>embMsgRequest->AddrR() = %X", embMsgRequest->AddrR());	 //enower
				   
				   	// 	 printf("\n\r>>>>55");


						embRS485.Trans(0xAA);
					// 	 printf(".AA");

						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
					 //	  printf(".%0X",	embMsgAns.body[i]);

							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgAns.body[i]);
							}
						}
			  						embRS485.Trans(0x55);
#else                           
                           
                           	tBuffRS485.Add(embMsgAns);  //120621
#endif
							//120621		embRS485.EmptyReceive();

				   //		 printf(".55");
			//	  RS485_receive_enable();
   	  		 embMsg232S.Init();	//090122
		  //t		 printf(".");
		 		flagRequest = 0;

			 	}	   // ==3
//#endif 
	//_________________________________________________________________________________RDN
			 /*
	if(flagRequest == 4) 
			   	{ 
						   embRS485.TransE(0x55);
		  					embRS485.TransE(0xAA);
		  				for(i=0; i<embMsgAns.FullSize(); i++) 
						{
					//	  printf(".%0X",	embMsgAns.body[i]);

							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03E(0x03ak;
								default: embRS485.TransE(embMsgAns.body[i]);
							}
						}
						embRS485.TransE(0x55);
						embRS485.EmptyReceiveE();

			 			  embRS485.Trans_RDN(embMsgAns.AddrS());
						   embMsg485E.Init();	//090122

								flagRequest = 0;
					}	// ==4
					
 //________________________________________________________________________________________RDN
               //    printEthLongHex(11);

                  */
				}
				else	//not self addr
				{
            /*
            if(flagRequest == 4) 
					{
              //?? add to channells ans????? 
               
                  embMsg485E.Init();
               }
                   */
             if(flagRequest == 3) 
					{
                 //?? add to channells ans?????
               
                  embMsg232S.Init();
               }

            
            
					if(flagRequest == 1) 
					{
//						if((ready_transit)||(ready_mod))
			   //			{
   	 	 	   //	   	  	printf("\n\rT");
	   			 //		printd('\n');
				 //		printd('\r');
				 //		printd('T');

#ifdef  DEBUG_TRANZIT 
 //       if( embMsg232.AddrS() == 0x6431) {  printfp("_t_");}
        if( embMsg232.AddrS() == 0x7766) {  printfp("_t_\n\r");}
#endif


			//		   		printf("\n\r> %04X ", embMsgRequest->AddrS());		//t
	   	//	my_int_disable_irq0();
      //     printEthLongHex(3);
      
               usart0_ans1_cnt++;
           //    printfpd("\n\n\r> %d \n",usart0_ans1_cnt);//ok
      
#ifdef FIND_CONF_ERR
		printfp("7");
      
   for(i=0; i< embMsg232.FullSize(); i++) 
						{
						  printfpd(".%0X",	embMsg232.body[i]);
					   }
   
      
#endif         

							tBuffEmbMsgEast.Add(embMsg232);
							tBuffEmbMsgWest.Add(embMsg232);
							tBuffEmbMsgNorth.Add(embMsg232);
							tBuffEmbMsgSouth.Add(embMsg232);

							unEmb2NetStat.emb2NetStat.selfPacketSend++;
			//_____________my
				   //			if	(tBuffEmbMsgEast.Used())
					 //		{
								 //	printf("\n\r@");
							 //		printf("\n\r@, %d", uscnt);
							//		my_int_disable_usart0();
							//		uscnt++;
					   //		}
           //_______________my
	   	//	my_int_enable_irq0();
				//		}
            embMsg232.Init();    //110902

					}
		//  			else
	  	//   		embMsg232.Init();
  
				}	   //not self addr
//==========================================================================		
	//110725			if(flagRequest == 2) 
	//			{
	//					tBuffEmbMsgEast.Add(embMsgAns);
	//					tBuffEmbMsgWest.Add(embMsgAns);
	//	 		}	// == 2
//==========================================================================
//==========================================================================		
				if(flagRequest == 21) 
				{
				 //		tBuffEmbMsgEast.Add(embMsgAns);
				 //		tBuffEmbMsgWest.Add(embMsgAns);
                  
            embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgAns.FullSize(); i++) 
				{

					switch(embMsgAns.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgAns.body[i]);
					}
				}
				    embSerialACT155.AddModM(0x55);
                  
		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(flagRequest == 22) 
				{
         //    printEthLongHex(10);
         //        printEthLongHex(4);

		//				tBuffEmbMsgEast.Add(embMsgAns);   //?? why do not work buffer !!!
                  
      //___________________________________________
      
		embSerialACT155.AddTransit(0x55);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgAns.FullSize(); i++) 
				{
					switch(embMsgAns.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgAns.body[i]);
					}
	 //				ResetWatchDog();
				}
				embSerialACT155.AddTransitM(0x55);

  
//___________________________________________
            
                  
     
			  //			tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(flagRequest == 23) 
				{
				//		tBuffEmbMsgNorth.Add(embMsgAns);    //???? why do not work
                  
                  
	            embSerialACT155.AddUD1(0x55);	
					embSerialACT155.AddUD1(0xAA);	
					for(i=0; i<embMsgAns.FullSize(); i++) 
					{
						switch(embMsgAns.body[i])
						{
						case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
						case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
						case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
						case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
						default: embSerialACT155.AddUD1(embMsgAns.body[i]);
						}
					}
		  embSerialACT155.AddUD1M(0x55);	
                  
                  
                  
			  //			tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2
//==========================================================================
//==========================================================================		
				if(flagRequest == 24) 
				{
				  //		tBuffEmbMsgSouth.Add(embMsgAns);     ///???
                  
               embSerialACT155.AddUD2(0x55);	
					embSerialACT155.AddUD2(0xAA);	
					for(i=0; i<embMsgAns.FullSize(); i++) 
					{
						switch(embMsgAns.body[i])
						{
						case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
						case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
						case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
						case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
						default: embSerialACT155.AddUD2(embMsgAns.body[i]);
						}
					}

		   embSerialACT155.AddUD2M(0x55);	                  
			  //			tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2
//==========================================================================






//============================================================================================		
//				if(flagRequest == 7) 
//				{
		  		   
 //					 	tBuffEmbMsgEast.Add(embMsgAns);
				 //tranzit not need		tBuffEmbMsgWest.Add(embMsgAns);
	//					unEmb2NetStat.emb2NetStat.selfPacketSend++;
 	//			}	// == 7
//================================================================================================

 //============================================================================================		





			 //	embRS485.Trans(0x99); //t100118
			 //	 printf(".");	   //t100118

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//	}
  //		embRS485.Trans(0x99); //t100118	    - get to not ping mode!!!!
  //				 printf(".");	   //t100118


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
