//file: stack_commands.c


///////////////////////////////////////	UPP /////////////////////////////////////////////

			 	switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
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
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Cai?in ninoiyiey
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
					case 0x09:
						if(embMsgRequest->Body(1)<=0x10)
						{
						  /* to act155n
							if(embMsgRequest->Body(0)==1)
							{
								send1[0]=embMsgRequest->Body(1);
								send1[1]=embMsgRequest->Body(2);
							}
							if(embMsgRequest->Body(0)==2)
							{
								send2[0]=embMsgRequest->Body(1);
								send2[1]=embMsgRequest->Body(2);
							}
						 */
						embMsg485Request.Init();
					 //	embMsg485Request.SetAddr(embMsg.Body(0));
						embMsg485Request.SetAddr(embMsgRequest->Body(0));
						embMsg485Request.SetLength(2);
					  //	embMsg485Request.SetBody(0,embMsg.Body(1));
						embMsg485Request.SetBody(0,embMsgRequest->Body(1));
					  //	embMsg485Request.SetBody(1,embMsg.Body(2));
						embMsg485Request.SetBody(1,embMsgRequest->Body(2));
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();

						}
						else
						{
							switch(embMsgRequest->Body(1))
							{
							case 0x11: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFD)|0x02);
								else outportb(0x583,inportb(0x583)&0xFD);
								break;
							case 0x12: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFE)|0x01);
								else outportb(0x583,inportb(0x583)&0xFE);
								break;
							}
						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(3);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
							/*
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
							*/

					if((embMsgRequest->Body(1)&0xC0)==0x80)
					{
						embMsg485Request.Init();
						embMsg485Request.SetAddr(0x01);
						embMsg485Request.SetLength(4);
						embMsg485Request.SetBody(0,0x07);
						embMsg485Request.SetBody(1,embMsgRequest->Body(0));
						embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
						embMsg485Request.SetBody(3,embMsgRequest->Body(4));
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();
					}
					else if((embMsgRequest->Body(1)&0xC0)==0xC0)
					{
						embMsg485Request.Init();
						embMsg485Request.SetAddr(0x02);
						embMsg485Request.SetLength(4);
						embMsg485Request.SetBody(0,0x07);
						embMsg485Request.SetBody(1,embMsgRequest->Body(0));
						embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
						embMsg485Request.SetBody(3,embMsgRequest->Body(4));
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();
					}
					else
					{
					 outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
					 embMsgAns.SetType(0x0A);
					 embMsgAns.SetBody(0,embMsgRequest->Body(0));
					 embMsgAns.SetBody(1,embMsgRequest->Body(1));
					 embMsgAns.SetBody(2,0);
					 embMsgAns.SetBody(3,8);
					 embMsgAns.SetBody(4,embMsgRequest->Body(4));
					 embMsgAns.SetLength(5);
					}
					   
						break;
					case 0x0B:
					/*
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
					   */

					if((embMsgRequest->Body(1)&0xC0)==0x80)
					{
						embMsg485Request.Init();
						embMsg485Request.SetAddr(0x01);
						embMsg485Request.SetLength(3);
						embMsg485Request.SetBody(0,0x08);
						embMsg485Request.SetBody(1,embMsgRequest->Body(0));
						embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();
					}
					 else if((embMsgRequest->Body(1)&0xC0)==0xC0)
					{
						embMsg485Request.Init();
						embMsg485Request.SetAddr(0x02);
						embMsg485Request.SetLength(3);
						embMsg485Request.SetBody(0,0x08);
						embMsg485Request.SetBody(1,embMsgRequest->Body(0));
						embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();
					}
		   			else
					{
					  inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
					  embMsgAns.SetType(0x0B);
					  embMsgAns.SetBody(0,embMsgRequest->Body(0));
					  embMsgAns.SetBody(1,embMsgRequest->Body(1));
					  embMsgAns.SetBody(2,0);
					  embMsgAns.SetBody(3,8);
					  embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
					  embMsgAns.SetLength(5);

					}
					  
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
				   		case 0x10:
//						printf("\n\r 0x10");
							embMsgAns.SetType(0x10);
							embMsgAns.SetLength(66);
							for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
						break;
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
						break;
						case 0x15:
						break;
						case 0x22:
							embMsgAns.SetType(0x22);
                     /*
							if(embMsgRequest->Body(0))// set
							{
							   SetIPRem(
							   (embMsgRequest->Body(1) << 24) +
							   (embMsgRequest->Body(2) << 16) +
							   (embMsgRequest->Body(3) << 8) +
							   	embMsgRequest->Body(4)
				 			   );
							}
						   						   
							embMsgAns.SetLength(5);	
							embMsgAns.SetBody(0,embMsgRequest->Body(0)); 	
							embMsgAns.SetBody(1, (GetIPRem() >> 24) & 0xff);
							embMsgAns.SetBody(2, (GetIPRem() >> 16) & 0xff);
							embMsgAns.SetBody(3, (GetIPRem() >> 8) & 0xff);
							embMsgAns.SetBody(4, GetIPRem() & 0xff);
   							break;
                           */
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

                           
					}  //switch

