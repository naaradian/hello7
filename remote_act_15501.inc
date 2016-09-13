// file: remote_act_15501.c
///////////////////////////////
///   answer  ///
///////////////////////////////
//////////////////////////////////////////////////
		i232=0;		//090629

		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
		 //	printf(" %02X", byte);

			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
		   	  //	 printEthStringAdd(0,0);
	  //091218			embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
			case 0x5A: mode5A=1; break;
			default:
				if(mode5A) 
				{
					embMsg232.Add(Modify5A(byte));
			 //		printEthStringAdd(1,byte);

					mode5A=0;
				}
				else 
				{
				embMsg232.Add(byte);
		  // 		printEthStringAdd(1,byte);
				}
				
			}
			if(embMsg232.IsEnd()) 
			{
	   //		printEthStringAdd(1,0x77);
	   //		printEthStringAdd(1,0x78);
	   //	 	printEthStringAdd(2,0);
				break;
			}
  //091224			if(++i232>10) break;	//090629
  //			if(++i232>20) break;	//090629
		}
      
//________________________________________________________________
   if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
		//091218	    if(embMsg232.ChkCRC())	  //091111
		   	    if(1)	  //091218
				{
				  embMsgRequest = &embMsg232;
				  flagRequest=1;
				}
				else			//091111
				{
				  embMsg232.Init();	//091111
				}
			}

//________________________________________________________________      
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>232
if(flagRequest == 1) //embMsgRequest->IsEnd())
{
 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
			  //	printf("\n\rbefore : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
					
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);
			 //	printf("\n\rafter : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
			embRS485.TransEC(0x55);	  //EC - RDN!!! in all
   			embRS485.TransEC(0xAA);
   			for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	 //  	   printf(".%0X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransEC(0x5A); embRS485.TransEC(0x00); break;
								case 0x55: embRS485.TransEC(0x5A); embRS485.TransEC(0x01); break;
								case 0xA5: embRS485.TransEC(0x5A); embRS485.TransEC(0x02); break;
								case 0xAA: embRS485.TransEC(0x5A); embRS485.TransEC(0x03); break;
								default: embRS485.TransEC(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransEC(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
		  				}	 //!= 3
					   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());

			 	switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,i);	 //_______for test
						break;
//______________________________________________________________________________________________						
					case 0x02 :
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
		  
//______________________________________________________________________________PS
					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
				 //	printEthLongHex(0x07);

//printEthLongHex(0x07);
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Cai?in ninoiyiey
				//	printEthLongHex(0x08);

//printEthLongHex(0x08);
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
//printEthLongHex(0x09);
						if(embMsgRequest->Body(1)<=0x10)
						{
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
//printEthLongHex(0x0A);
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
//printEthLongHex(0x0B);
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0D:
//printEthLongHex(0x0D);
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


					case 0x13:
//printEthLongHex(0x13);
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
//printEthLongHex(0x14);
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
						break;
					case 0x15:

						break;
//________________________________________________________________________PS
#ifdef PROG_BMD155PS
 					case 0x17:
//printEthLongHex(0x17);
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
#ifdef PROG_BMD34PS
 					case 0x17:
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
				   case 0x22:
							embMsgAns.SetType(0x22);
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
//________________________________________________________________________PS

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

//					if(flagRequest == 1) 
					{
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

				}
				else	//not self addr
				{
 //					if(flagRequest == 1) 
					{
							tBuffEmbMsgEast.Add(embMsg232);
							tBuffEmbMsgWest.Add(embMsg232);

							unEmb2NetStat.emb2NetStat.selfPacketSend++;
							embMsg232.Init();  //091221
				
					}
		
  
				}	   //not self addr
		
	 			flagRequest = 0;
			embMsgRequest = NULL;
}  //have flagrequest not zero
/////////////////////////////////////////////////////////////////////////////////////
      
      
      
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<232      
      
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>485
 			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
			   	switch(byte)
				{
				case 0x55: embMsg485.Init(); // printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485.Init(); // printf("\n\r++++");
				break; // Iaeao
					//			case 0xA5: break; // Ia?ea?ia caanu iao!
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);

				}
			  	 // 	printf("_%X", byte);

			  if(embMsg485.IsEnd()) 
		  				break;
} //embrs485 usedReceive

		 if(embMsg485.IsEnd()) 
				{
					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
					      aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
						   							
							embMsg485.SetAddrI(aS);	 //t 091019
							embMsg485.SetAddrS(aR);	 //t 091019
							embMsg485.SetAddrR(aI);	 //t 091019

//							embMsg485.SetAddrI(aI);	 //t 091221
//							embMsg485.SetAddrS(aS);	 //t 091221
//							embMsg485.SetAddrR(aR);	 //t 091221
					 
							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg485.FullSize(); i++) 
							{
								switch(embMsg485.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485.body[i]);
								}
							}
							embRS232.Trans(0x55);
						   	embMsg485.Init(); //091221 //my	 ??? need ???		
				 	}
					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{
		 					if(embMsg485.TOM() & 0x01)
							{
								aI = embMsg485.AddrI();
								aS = embMsg485.AddrS();
								aR = embMsg485.AddrR();

								embMsg485.SetAddrI(aS);
								embMsg485.SetAddrS(aR);
								embMsg485.SetAddrR(aI);

								tBuffEmbMsgEast.Add(embMsg485);
								tBuffEmbMsgWest.Add(embMsg485);
								unEmb2NetStat.emb2NetStat.selfPacketSend++;	
						 		embMsg485.Init();//091221  //my	 ??? need ???					
							}
							else
							{
							  	flagRequest=3;
								embMsg485.SetRS485();
								embMsgRequest = &embMsg485;
							}
						}  //s != self
					}	//r != S
				}  //embrs485.isend
            
if(flagRequest == 3) //embMsgRequest->IsEnd())
{
 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
 				 //						else   //flagRequest == 3 or 4
				 //		{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aR);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aS);
				//		}	 //==3
					   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());

			 	switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,i);	 //_______for test
						break;
//______________________________________________________________________________________________						
					case 0x02 :
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
		  
//______________________________________________________________________________PS
					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
				 //	printEthLongHex(0x07);

//printEthLongHex(0x07);
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Cai?in ninoiyiey
				//	printEthLongHex(0x08);

//printEthLongHex(0x08);
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
//printEthLongHex(0x09);
						if(embMsgRequest->Body(1)<=0x10)
						{
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
//printEthLongHex(0x0A);
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
//printEthLongHex(0x0B);
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0D:
//printEthLongHex(0x0D);
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


					case 0x13:
//printEthLongHex(0x13);
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
//printEthLongHex(0x14);
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
						break;
					case 0x15:

						break;
//________________________________________________________________________PS
#ifdef PROG_BMD155PS
 					case 0x17:
//printEthLongHex(0x17);
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
#ifdef PROG_BMD34PS
 					case 0x17:
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
				   case 0x22:
							embMsgAns.SetType(0x22);
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
//________________________________________________________________________PS

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

  

					if(flagRequest == 3) 
					{
			  //		RS485_receive_disable();

						embRS485.Trans(0x55);
					//	 printf("\n\r>>>>embMsgRequest->AddrS() = %X", embMsgRequest->AddrS());	 //3310
					//	 printf("\n\r>>>>embMsgRequest->AddrI() = %X", embMsgRequest->AddrI());	 //	3309
					//	 printf("\n\r>>>>embMsgRequest->AddrR() = %X", embMsgRequest->AddrR());	 //enower

					//	 printf("\n\r>>>>55");

						embRS485.Trans(0xAA);
					//	 printf(".AA");

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
									embRS485.EmptyReceive();

				//		 printf(".55");
			//	  RS485_receive_enable();
			 embMsg485.Init();	//090122

				flagRequest = 0;

			 	}	   // ==3
 
	//_________________________________________________________________________________RDN
			 
 

				}
				else	//not self addr
				{
			  		
  
				}	   //not self addr
            
		 	flagRequest = 0;
			embMsgRequest = NULL;
}  //have flagrequest not zero

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<485
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>485E
//_____________________________________________________________________RDN
//if(!embMsg485.IsEnd())
//		{
			while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
			   	switch(byte)
				{
				case 0x55: embMsg485E.Init(); // printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485E.Init();//  printf("\n\r++++");
				break; // Iaeao
					//			case 0xA5: break; // Ia?ea?ia caanu iao!
				case 0x5A: mode5A485E=1; break;
				default:
					if(mode5A485E) 
					{
						embMsg485E.Add(Modify5A(byte));
						mode5A485E=0;
					}
					else embMsg485E.Add(byte);

				}
			  //	  	printf(".%X", byte);
			  if(embMsg485E.IsEnd()) 
		  				break;
			} //embrs485 usedReceive
 //	}  //	!embMsg485.IsEnd
//_____________________________________________________________________RDN
//______________________________________________________________________232e
// }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

//}  //!embrs232.isend






 if(embMsg485E.IsEnd()) 
				{
		 
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
				  			aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();

							embMsg485E.SetAddrI(aR);  //as in act155-02 ok!
							embMsg485E.SetAddrS(aS);
							embMsg485E.SetAddrR(aI);
   

							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg485E.FullSize(); i++) 
							{
								switch(embMsg485E.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485E.body[i]);
								}
							}
							embRS232.Trans(0x55);
						  	embMsg485E.Init();//091221  //my		??? need ???
						}
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
						if(embMsg485E.AddrS()==SelfID())
						{
   							if(embMsg485E.TOM() & 0x01)
							{
								aI = embMsg485E.AddrI();
								aS = embMsg485E.AddrS();
								aR = embMsg485E.AddrR();
								embMsg485E.SetAddrI(aS);
								embMsg485E.SetAddrS(aR);
								embMsg485E.SetAddrR(aI);
								tBuffEmbMsgEast.Add(embMsg485E);
								tBuffEmbMsgWest.Add(embMsg485E);

						unEmb2NetStat.emb2NetStat.selfPacketSend++;	
						 		embMsg485E.Init();//091221  //my		??? need ???				
							}
							else
							{
	   							flagRequest=4;
								embMsg485E.SetRS485();
								embMsgRequest = &embMsg485E;
							}
						}  //s != self
					}	//r != S
				}  //embrs485E.isend
 //091221	  else //1024
 
if(flagRequest == 4) //embMsgRequest->IsEnd())
{
 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
 			 //						else   //flagRequest == 3 or 4
				//		{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aR);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aS);
				  //		}	 //==3
					   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());

			 	switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,i);	 //_______for test
						break;
//______________________________________________________________________________________________						
					case 0x02 :
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
		  
//______________________________________________________________________________PS
					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
				 //	printEthLongHex(0x07);

//printEthLongHex(0x07);
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Cai?in ninoiyiey
				//	printEthLongHex(0x08);

//printEthLongHex(0x08);
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
//printEthLongHex(0x09);
						if(embMsgRequest->Body(1)<=0x10)
						{
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
//printEthLongHex(0x0A);
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
//printEthLongHex(0x0B);
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0D:
//printEthLongHex(0x0D);
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


					case 0x13:
//printEthLongHex(0x13);
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
//printEthLongHex(0x14);
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
						break;
					case 0x15:

						break;
//________________________________________________________________________PS
#ifdef PROG_BMD155PS
 					case 0x17:
//printEthLongHex(0x17);
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
#ifdef PROG_BMD34PS
 					case 0x17:
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
				   case 0x22:
							embMsgAns.SetType(0x22);
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
//________________________________________________________________________PS

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

		
		 
	//_________________________________________________________________________________RDN
			 
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
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
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


				}
				else	//not self addr
				{
				  		
  
				}	   //not self addr
		
			 			flagRequest = 0;
			embMsgRequest = NULL;
}  //have flagrequest not zero

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<485E

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>rbuffnsg
	if(rBuffEmbMsg.Used())    //?????????????????? need while ??????
 //  while(rBuffEmbMsg.Used())    //091223
				{
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
					rBuffEmbMsg.Get(embMsgA);
					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
//				   		for(long j =0; j <1000; j++) //091221 //for test
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
//for(long k =0; k <2000; k++) //091221 //for test
								embRS232.Trans(0x55);
//								embRS232.Trans_RDN(COMP_DEF_MAC_END);
//091221 not need!				embRS232.Trans_RDN_Full(embRS232.HostMAC);
								flagRequest = 0;
							}
						}
					}
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
					  	  //	printf("2");
								flagRequest=2;
								embMsgRequest = &embMsgA;
							}
						}
					}
	}  //buf
   
   if(flagRequest == 2) //embMsgRequest->IsEnd())
{
 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
			  //	printf("\n\rbefore : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
					
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);
			 //	printf("\n\rafter : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
			embRS485.TransEC(0x55);	  //EC - RDN!!! in all
   			embRS485.TransEC(0xAA);
   			for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	 //  	   printf(".%0X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransEC(0x5A); embRS485.TransEC(0x00); break;
								case 0x55: embRS485.TransEC(0x5A); embRS485.TransEC(0x01); break;
								case 0xA5: embRS485.TransEC(0x5A); embRS485.TransEC(0x02); break;
								case 0xAA: embRS485.TransEC(0x5A); embRS485.TransEC(0x03); break;
								default: embRS485.TransEC(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransEC(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
		  				}	 //!= 3
						else   //flagRequest == 3 or 4
						{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aR);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aS);
						}	 //==3
					   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());

			 	switch(embMsgRequest->Type())
					{
			 		case 0x01: // cai?in oeia
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
				   		for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);	 //hier added 0xff ...
					//	for(i=0; i<44; i++) embMsgAns.SetBody(i,i);	 //_______for test
						break;
//______________________________________________________________________________________________						
					case 0x02 :
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
		  
//______________________________________________________________________________PS
					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
				 //	printEthLongHex(0x07);

//printEthLongHex(0x07);
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x08: // Cai?in ninoiyiey
				//	printEthLongHex(0x08);

//printEthLongHex(0x08);
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
//printEthLongHex(0x09);
						if(embMsgRequest->Body(1)<=0x10)
						{
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
//printEthLongHex(0x0A);
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
//printEthLongHex(0x0B);
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0D:
//printEthLongHex(0x0D);
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

#ifdef PROG_PU_M_MUX
						case 0x12: // Запрос состояния
							embMsgAns.SetType(0x12);
							embMsgAns.SetLength(40);
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unEmb2Mux34.byte[i]);
						break;
#endif //PROG_PU_M_MUX

					case 0x13:
//printEthLongHex(0x13);
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
//printEthLongHex(0x14);
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
							for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);
						break;
					case 0x15:

						break;
//________________________________________________________________________PS
#ifdef PROG_BMD155PS
 					case 0x17:
//printEthLongHex(0x17);
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
#ifdef PROG_BMD34PS
 					case 0x17:
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
#endif //PROG_BMD155PS
				   case 0x22:
							embMsgAns.SetType(0x22);
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
//________________________________________________________________________PS

					}  //switch

					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();
 
				}
				else	//not self addr
				{
						
  
				}	   //not self addr
		
				if(flagRequest == 2) 
				{
						tBuffEmbMsgEast.Add(embMsgAns);
						tBuffEmbMsgWest.Add(embMsgAns);
		 		}	// == 2
			flagRequest = 0;
			embMsgRequest = NULL;
}  //have flagrequest not zero







/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
