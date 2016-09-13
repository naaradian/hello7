//file : remotemx155.c

//////////////////////////////////////////////////

		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; break;
			default:
				if(mode5A) 
				{
					embMsg232.Add(Modify5A(byte));
					mode5A=0;
				}
				else embMsg232.Add(byte);
			}
			if(embMsg232.IsEnd()) 
				break;
		}

		if(!embMsg232.IsEnd())
		{
			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
				switch(byte)
				{
				case 0x55: 
					embMsg485.Init();
					break; 
				case 0xAA: embMsg485.Init(); break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);
				}
				if(embMsg485.IsEnd())
			  				break;

			}
//_____________________________________________________________________RDN
if(!embMsg485.IsEnd())
		{
			while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
			   	switch(byte)
				{
				case 0x55: embMsg485E.Init();//  printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485E.Init(); // printf("\n\r++++");
				break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
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
	}  //	!embMsg485.IsEnd
}
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
  if(embMsg485E.IsEnd()) 
				{
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
						// ->>	// Ответ в RS-232
							aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();
							embMsg485E.SetAddrI(aR);
							embMsg485E.SetAddrS(aI);
							embMsg485E.SetAddrR(aS);
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
					}
					
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
						if(embMsg485E.AddrS()==SelfID())
						{

						// ->>	// Транзитом ответ в линию
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
						 //		embMsg485.Init(); //my						
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
	else //1024
 if(embMsg485.IsEnd()) 
				{
				    if(embMsg485.AddrI() != SelfID())
					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
						// ->>	// Ответ в RS-232
							aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aS);
							embMsg485.SetAddrS(aR);
							embMsg485.SetAddrR(aI);
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
								default: embRS232.TransEC(embMsg485.body[i]);
								}
							}
							embRS232.Trans(0x55);
					}
					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{
							if(!(embMsg485.TOM()&0x01))
							{
								flagRequest=3;
								embMsg485.SetRS485();
								embMsgRequest = &embMsg485;
							}
						}
					}
				}

			else //1024

			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
			else
			{
				if(rBuffEmbMsg.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					rBuffEmbMsg.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x60)
						{
							if(embMsgA.AddrS()==SelfID())//или равен 0000 или FFFF
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
								}
								embRS232.Trans(0x55);
								flagRequest = 0;							}
						}
					}
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=2;
								embMsgRequest = &embMsgA;
							}
						}
					}
				}
			}

			if(flagRequest)//embMsgRequest->IsEnd())
			{
				if(embMsgRequest->IsRS485())
				{
				//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
							embMsgAns.SetAddrS(aI);
						    embMsgAns.SetAddrR(aR);
							embRS485.TransEC(0x55);	  //EC - RDN!!! in all
							embRS485.TransEC(0xAA);
							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					//		   printf(".%0X",	embMsgRequest->body[i]);
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
				
						flagRequest = 0;
					}
				}

				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
						embMsgAns.SetRS485();
						aI = embMsgRequest->AddrI();
						aS = embMsgRequest->AddrS();
						aR = embMsgRequest->AddrR();
						embMsgAns.SetAddrI(aS);
						embMsgAns.SetAddrS(aI);
						embMsgAns.SetAddrR(aR);
					}
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
					switch(embMsgRequest->Type())
					{
					case 0x01: // запрос типа
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

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

					case 0x06:	//Выгрузка файла (чтение из устройства)
						/// формируем ответ ///
						ul2uc.uc[0] = embMsgRequest->Body(0);
						ul2uc.uc[1] = embMsgRequest->Body(1);
						ul2uc.uc[2] = embMsgRequest->Body(2);
						ul2uc.uc[3] = embMsgRequest->Body(3);
				   //		addrRAM = (unsigned char *)ul2uc.ul;
						addrRAM = (unsigned char *)NVRAM_BASE;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						ui2uc.uc[2] =  0;
						ui2uc.uc[3] =  0;
						shift = ui2uc.ui;
						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						ui2uc.uc[2] = 0;
						ui2uc.uc[3] = 0;

						len = ui2uc.ui;
						temp_crc=0;
						embMsgAns.SetType(0x06);
						embMsgAns.SetLength(len+10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));

						for(i=0; i<len; i++)
						{
							temp_crc += *(addrRAM+i+shift);
							embMsgAns.SetBody(i+8,*(addrRAM+i+shift));
						}
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(len+8,ui2uc.uc[0]);
						embMsgAns.SetBody(len+9,ui2uc.uc[1]);
						break;
//////
					case 0x07: /// Генерим запрос маркера во все направления
			//			printf("\n\r command 07");
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x0A:
			//			printf("\n\r command 0A");
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
			 //			printf("\n\r command 0B");
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
					case 0x0C:
			   //			printf("\n\r command 0C");
							embMsgAns.SetTOM(0x20);
							embMsgAns.SetAddrI(SelfID());
							embMsgAns.SetAddrS(SelfID());
							embMsgAns.SetType(0x0C);
							embMsgAns.SetLength(0);
							SetHLX();
///
//					CfgCard();
//					SaveCommut();
///
							embMsg.Init();
						break;
					case 0x0D:
				//		printf("\n\r command 0D");
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
			   //			printf("\n\r command 13");
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
							bt = (unsigned char *)NVRAM_BASE;
							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x14: // Запрос состояния
			 //			printf("\n\r command 14");
							UpdateStateE1();
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(64);
							for(i=0; i<64; i++) embMsgAns.SetBody(i,unEmb2Mux155.byte[i]);
						break;
					case 0x15: // Запрос состояния
			 //			printf("\n\r command 15");
							UpdateSTM1Map();
							embMsgAns.SetType(0x15);
							embMsgAns.SetLength(128);
							for(i=0; i<128; i++) embMsgAns.SetBody(i,unSTM1.u[i]);
						break;
					case 0x22: //change ip address
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

					}
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(flagRequest == 1) 
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

						flagRequest = 0;
						embMsgRequest = NULL;
					}
					if(flagRequest == 3) 
					{
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
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
						flagRequest = 0;
						embMsgRequest = NULL;
					}
//_________________________________________________________________________________RDN
				if(flagRequest == 4) 
			   	{ 
			   embRS485.TransE(0x55);
						embRS485.TransE(0xAA);
					//	 printf(".AA");

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
				  embRS485.Trans_RDN(embMsgAns.AddrS());
					 	embRS485.EmptyReceiveE();	//my: from testing mf20	//remaked 20.02.2008

						flagRequest = 0;
					}	// ==3
					flagRequest = 0;
					embMsgRequest = NULL;
				}
				else
				{
					   	if(flagRequest == 1) 
					{
						embMsg232.Init();  //???need
					}
				  	   	if(flagRequest == 3) 
					{
						embMsg485.Init();  //???need
					}
						if(flagRequest == 4) 
					{
						embMsg485E.Init();  //???need
					}
				}
		
				flagRequest = 0;
				embMsgRequest = NULL;
			}
