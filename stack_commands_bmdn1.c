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
             //      for(i)
			  //101227			if(ready_transit) old_ready_transit=0;
			  //101227			if(ready_mod) old_ready_mod=0;
                  
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
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[0].byte[i]);
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
					  case 0x5C: // Cai?in ninoiyiey
							embMsgAns.SetType(0x5C);
							embMsgAns.SetLength(42);
						 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUMp[4].byte[i]);
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
                        
                        

					}  //switch

