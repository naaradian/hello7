//file: stack_commands_ups.c

  if(flagRequest == 1) 
					{
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
					}	
               
//if(GetTestMode() == 0x50)
//{
//   printfp("\n\r7  command :");
 //  printfpd(" %X", embMsgRequest->Type());
//}

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
                //ok     printfpd(" %X", shift);
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
           
      //      printfpd("0: %X", embMsgRequest->Body(0));
       //     printfpd("1: %X", embMsgRequest->Body(1));
       //     printfpd("2: %X", embMsgRequest->Body(2));
      //      printfpd("3: %X", embMsgRequest->Body(3));
     //       printfpd("4: %X", embMsgRequest->Body(4));
    //        printfpd("5: %X", embMsgRequest->Body(5));
     //       printfpd("6: %X", embMsgRequest->Body(6));


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
               //       printfp("\n\r command 38 :");
               //       printfpd(" %X",embMsgRequest->Body(6));

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
          /*        
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
*/
						break;
					case 0x09:
			  	//	printEthLongHex(0x09);

						if(embMsgRequest->Body(1)<=0x10)
						{
						 						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(12); //3
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
					case 0x0A:
#ifdef PROG_PU_M_MUX
				  //	 		printEthLongHex(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
					  	//	 dzhgjssj
					  		 if((embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8))	< 0x100)
							{
					//   		printEthLongHex(0x5000 + embMsgRequest->Body(4));
								outportb3(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
								SaveParameterToNVRAM(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8) , embMsgRequest->Body(4));
#ifdef PROG_PU_M_MUX_TEST
			   //		          printf("\n\r port : 0x%X  data : 0x%X", (embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)),embMsgRequest->Body(4));
#endif //PROG_PU_M_MUX_TEST							
							}
							else
#endif //PROG_PU_M_MUX

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
                        
			   		  //		for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
                        
					/*
						embMsgAns.SetLength(70);
                     
							for(i=0; i<66; i++) embMsgAns.SetBody(i,unStateRRL.byte[i]);
//_________________________101213  
				ansnum++;
                for(i=0; i<32; i++)
				{
					 Packet[i] = unStateRRL.byte[i+2];
				}

			//    Packet[5] = 44; //for test

			   if(CheckPacket(Packet))
			   {ch1ok++;}
			   else
			   {ch1bad++;}
            
             for(i=0; i<32; i++)
				{
					 Packet[i] = unStateRRL.byte[i+34];
				}
			 //	Packet[5] = 22; //for test

			   if(CheckPacket(Packet))
			   {ch2ok++;}
			   else
			   {ch2bad++;}

                   
                     
//______________________101213                     
                     embMsgAns.SetBody(66,ansnum>>24);
                     embMsgAns.SetBody(67,ansnum>>16);
                    embMsgAns.SetBody(68,ansnum>>8);
                     embMsgAns.SetBody(69,ansnum);
//______________________101213
                     
                     	 */

						break;


				   //		break;
					case 0x12: // Запрос состояния
			   //		printEthLongHex(0x12);


							embMsgAns.SetType(0x12);
							embMsgAns.SetLength(40);
#ifdef PROG_PU_M_MUX
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unEmb2Mux34.byte[i]);
#endif // PROG_PU_M_MUX

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
						// 	for(i=0; i<2; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
						 //	for(i=4; i<44; i++) embMsgAns.SetBody((i - 2),unStatePUM.byte[i]);

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

#ifdef USE_RS125

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

//_______________________________________________>> changed 0x9 -> 0x49; 0xA -> 0x4A; 0xB -. 0x4B                  
//101110					case 0x09:
					case 0x49:   //101110
			//			if(embMsgRequest->Body(1)<=0x10)
			//			{
 						embMsg485Request.Init();
 						embMsg485Request.SetAddr(embMsgRequest->Body(0));
						embMsg485Request.SetLength(2);
						embMsg485Request.SetBody(0,embMsgRequest->Body(1));
 					    embMsg485Request.SetBody(1,embMsgRequest->Body(2));
						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();

			//			}
			//			else
			//			{
			//				switch(embMsgRequest->Body(1))
			//				{
			//				case 0x11: 
			//					if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFD)|0x02);
			//					else outportb(0x583,inportb(0x583)&0xFD);
			//					break;
			//				case 0x12: 
			 //					if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFE)|0x01);
			 //					else outportb(0x583,inportb(0x583)&0xFE);
			 //					break;
			 //				}
			 //			}
						embMsgAns.SetType(0x49);
						embMsgAns.SetLength(3);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						//						embMsg.Init();
						break;
//101110					case 0x0A:
					case 0x4A:  //101110
		 //			if((embMsgRequest->Body(1)&0xC0)==0x80)
		  //			{
						embMsg485Request.Init();
						embMsg485Request.SetAddr(embMsgRequest->Body(0));
			   	//		embMsg485Request.SetLength(4);
			           	embMsg485Request.SetLength(8);
			   //			embMsg485Request.SetBody(0,0x07);
			   //			embMsg485Request.SetBody(1,embMsgRequest->Body(0));
			   //			embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
			   //			embMsg485Request.SetBody(3,embMsgRequest->Body(4));
						embMsg485Request.SetBody(0,embMsgRequest->Body(1));//byte
						embMsg485Request.SetBody(1,embMsgRequest->Body(2));	//bit
						embMsg485Request.SetBody(2,embMsgRequest->Body(3));	//quantity
						embMsg485Request.SetBody(3,embMsgRequest->Body(4));	//value
						embMsg485Request.SetBody(4,embMsgRequest->Body(5));	//value
						embMsg485Request.SetBody(5,embMsgRequest->Body(6));	//value
						embMsg485Request.SetBody(6,embMsgRequest->Body(7));	//value
						embMsg485Request.SetBody(7,embMsgRequest->Body(8));	//value
   



						embMsg485Request.CalcCRC();
						embMsg485Request.SetReadyToSend();
			//		}
			//		else if((embMsgRequest->Body(1)&0xC0)==0xC0)
			//		{
		   //				embMsg485Request.Init();
			//			embMsg485Request.SetAddr(0x02);
			//			embMsg485Request.SetLength(4);
			//			embMsg485Request.SetBody(0,0x07);
			//			embMsg485Request.SetBody(1,embMsgRequest->Body(0));
			//			embMsg485Request.SetBody(2,embMsgRequest->Body(1)&0x3F);
			//			embMsg485Request.SetBody(3,embMsgRequest->Body(4));
			//			embMsg485Request.CalcCRC();
			//			embMsg485Request.SetReadyToSend();
		   //			}
		   //			else
		  //			{
		  //			 outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
		  //			 embMsgAns.SetType(0x4A);
		  //			 embMsgAns.SetBody(0,embMsgRequest->Body(0));
		  //			 embMsgAns.SetBody(1,embMsgRequest->Body(1));
		  //			 embMsgAns.SetBody(2,0);
		  //			 embMsgAns.SetBody(3,8);
		  //			 embMsgAns.SetBody(4,embMsgRequest->Body(4));
		 //			 embMsgAns.SetLength(5);
		 //			}

		  			 embMsgAns.SetType(0x4A);
		  			 embMsgAns.SetBody(0,embMsgRequest->Body(0));
		  			 embMsgAns.SetBody(1,embMsgRequest->Body(1));
		  			 embMsgAns.SetBody(2,embMsgRequest->Body(2));
		  			 embMsgAns.SetBody(3,embMsgRequest->Body(3));
		  			 embMsgAns.SetBody(4,embMsgRequest->Body(4));
		  			 embMsgAns.SetBody(5,embMsgRequest->Body(5));
		  			 embMsgAns.SetBody(6,embMsgRequest->Body(6));
		  			 embMsgAns.SetBody(7,embMsgRequest->Body(7));
 		 			 embMsgAns.SetLength(8);

					   
						break;
//101110					case 0x0B:
					case 0x4B: //101110
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
					  embMsgAns.SetType(0x4B);
					  embMsgAns.SetBody(0,embMsgRequest->Body(0));
					  embMsgAns.SetBody(1,embMsgRequest->Body(1));
					  embMsgAns.SetBody(2,0);
					  embMsgAns.SetBody(3,8);
					  embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
					  embMsgAns.SetLength(5);

					}
					  
						break;
		     /*110411            
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
                 */
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


 //	case 0x4E: // 

			   //		printEthLongHex(0x4e);

					 //	embMsgAns.SetAddrI(SelfID());  //t
					 //	embMsgAns.SetAddrS(SelfID());  //t

	  //					embMsgAns.SetType(0x4E);
  //						embMsgAns.SetLength(32);
		  //				for(i=0; i<44; i++) embMsgAns.SetBody(i,uemb4pumfabinfo.byte[i]);
  //						break;


//_______________________________________________________________                 
                 
                 
                 
                 /*
                 
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
                   SetNeedWriteDevId();
                  }
                 } 
                 */
                  /*
              	  embMsgAns.SetBody(0,embMsgRequest->Body(0));
					  embMsgAns.SetBody(1,embMsgRequest->Body(1));
					  embMsgAns.SetBody(2,0);
					  embMsgAns.SetBody(3,8);
					  embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
					  embMsgAns.SetLength(5);
                  
	                  
                 break; 
                 
                 	*/
                 
//_________________________________________________________________<< changed 0x9 -> 0x49; 0xA -> 0x4A; 0xB -. 0x4B                  







//#endif //USE_RS125








					}
