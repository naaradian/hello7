//remotemux.inc

//////////////////////////////////////////////////


   //		i232=0;


		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
	//100811			embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
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
  //090519			if(++i232>10) break;
		}

		if(!embMsg232.IsEnd())
		{
//_______________________________________________________________232e
/*
		while(embRS232.UsedReceiveE())
		{
 			byte = embRS232.ReceiveE();
	  	switch(byte)
			{
			case 0x55: 
				embMsg232E.Init();
 	//100811		   	embRS232.TransE(0x55);
  //			   	embRS232.Trans_RDN(embMsgRequest->AddrS());		  //????????????????? neew keep before address of computer!!!
			 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);	 //temporary zero mac: 001111000000
				  embRS232.Trans_RDN_Full(embRS232.HostMAC);	
				break; 
			case 0xAA: embMsg232E.Init(); 
  			
			break; // Iaeao
				//			case 0xA5: break; // Ia?ea?ia caanu iao!
			case 0x5A: mode5A232E=1; 
			    	break;
			default:
				if(mode5A232E) 
				{
   					embMsg232E.Add(Modify5A(byte));
					mode5A232E=0;
				}
				else 
				{
    	            embMsg232E.Add(byte);
				}
			}  // switch byte
		  
			if(embMsg232E.IsEnd()) 
				break;
		  //	if(++i232> 10) break;
		}	 //while
 if(!embMsg232E.IsEnd()) // t
 {
 */
//_______________________________________________________________232e

			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
				switch(byte)
				{
				case 0x55: embMsg485.Init(); break; 
				case 0xAA: embMsg485.Init(); break; // Iaeao
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
	}  //	!embMsg485.IsEnd
//_____________________________________________________________________RDN
//______________________________________________________________________232e
// }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

		}
///////////////////////////////
///   Oi?ie?iaaiea ioaaoa   ///
///////////////////////////////
 if(embMsg485E.IsEnd()) 
				{
					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
						// ->>	// Ioaao a RS-232
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
					 //		embRS232.Trans_RDN(COMP_DEF_MAC_END);
					 //		  embRS232.Trans_RDN_Full(embRS232.HostMAC);		
					}
					
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
						if(embMsg485E.AddrS()==SelfID())
						{

						// ->>	// O?aiceoii ioaao a eeie?
							if(embMsg485E.TOM() & 0x01)
							{
								aI = embMsg485E.AddrI();
								aS = embMsg485E.AddrS();
								aR = embMsg485E.AddrR();
								embMsg485E.SetAddrI(aS);
								embMsg485E.SetAddrS(aR);
								embMsg485E.SetAddrR(aI);
								tBuffEmbMsgEast.Add(embMsg485E);
				  //tranzit not need				tBuffEmbMsgWest.Add(embMsg485E);

#ifdef 	ETH_TRANZIT
						tBuffEmbMsgEthAll.Add(embMsg485E);
						tBuffEmbMsgEthAll1.Add(embMsg485E);
#endif //ETH_TRANZIT




								unEmb2NetStat.emb2NetStat.selfPacketSend++;	
						 //		embMsg485.Init(); //my						
							}
							else
							{
								// ->>	// Iieo?eee cai?in ec Ethernet
	  //!!!!!!!!!							flagRequest=3;
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
						// ->>	// Ioaao a RS-232
							aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aR);
							embMsg485.SetAddrS(aI);
							embMsg485.SetAddrR(aS);
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
						//	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//							  embRS232.Trans_RDN_Full(embRS232.HostMAC);		
					}
					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{

						// ->>	// O?aiceoii ioaao a eeie?
							if(embMsg485.TOM()&0x01)
							{
								aI = embMsg485.AddrI();
								aS = embMsg485.AddrS();
								aR = embMsg485.AddrR();
								embMsg485.SetAddrI(aS);
								embMsg485.SetAddrS(aR);
								embMsg485.SetAddrR(aI);
								tBuffEmbMsgEast.Add(embMsg485);
						   //tranzit not need		tBuffEmbMsgWest.Add(embMsg485);
								unEmb2NetStat.emb2NetStat.selfPacketSend++;							
							}
							else
							{
								// ->>	// Iieo?eee cai?in ec RS-485
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
//________________________________________________________________________232e			
		  /*
			     else if(embMsg232E.IsEnd())//&&embMsg.ChkCRC())
  			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg232E;
					flagRequest=5;	//new
				//	my_printf(0x20);   //t
				}
			}
			*/
//________________________________________________________________________232e	
			else
			{
			 //	 printf(" p0");
#ifndef MPC35_MOD_CHANNEL

				if(rBuffEmbMsg.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					rBuffEmbMsg.Get(embMsgA);

				//	 printf(" p1");

					if(embMsgA.TOM()&0x01)
					{
				  //	printf(" p2");

						if(embMsgA.TOM()&0x60)
						{
					  //	printf(" p3");

							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{
						 //	printf(" p4");

										
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
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
//								  embRS232.Trans_RDN_Full(embRS232.HostMAC);		
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
								flagRequest=2;
								embMsgRequest = &embMsgA;
							}
						}
					}
				}

#else //MPC35_MOD_CHANNEL

//=================================================================================
				if(rBuffEmbMsgEast.Used())
				{
					EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgEast.Get(embMsgA);
#ifndef ANSWER_OLWAIS
					 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR());
#endif //ANSWER_OLWAIS

				 //	   printf(" %02X", embMsgA.TOM());

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				 //	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				   //		 printf(" p3");

							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{  
					  //		 printf(" p4");
//______________________________________________________________________
#ifdef CAN_ETHERNET_ASU
											
								embRS232.TransEC(0x55);
								embRS232.TransEC(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
									case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
									case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
									case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
									default: embRS232.TransEC(embMsgA.body[i]);
									}
								}
								embRS232.TransEC(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
								embRS232.Trans_RDN_Full(embRS232.HostMAC);	
#else	// NOT CAN_ETHERNET_ASU
//_________________________________________________________________________
//______________________________________________________________________________
 //my_int_disable();	//t
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

 //  my_int_enable();

#endif	 // NOT CAN_ETHERNET_ASU
//___________________________________________________________________________________




								flagRequest = 0;
							}  //embMsgA.AddrS()==SelfID()
						}	//embMsgA.TOM()&0x20
					}		//(embMsgA.TOM()&0x01)
					else
					{	
				//	   	 printf(" p5");

						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
					//  	 printf(" p6");

							if(embMsgA.AddrS()==SelfID())
							{
					 //  	  	  printf(" p7");
					  	

								flagRequest=2;
								embMsgRequest = &embMsgA;

				   	//		for(i=0; i<embMsgRequest->FullSize(); i++) 
				   	  //		{
				   	 	//	   printf(" %02X",	embMsgRequest->body[i]);
				   	   //		}
 	   	 		   	  //		printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());

							}
						}  //embMsgA.AddrI()!=embMsgA.AddrS()
					}  //else	embMsgA.TOM()&0x01
					}
				}	//rBuffEmbMsg.Used()
//=================================================================================
//=================================================================================
			   else // 090115
			 	if(rBuffEmbMsgWest.Used())
				{
					EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgWest.Get(embMsgA);
#ifndef ANSWER_OLWAIS
					 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR());
#endif //ANSWER_OLWAIS

				 //	   printf(" %02X", embMsgA.TOM());

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				//	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				  //		 printf(" p3");

							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{  
					 //		 printf(" p4");
//______________________________________________________________________
#ifdef CAN_ETHERNET_ASU
											
								embRS232.TransEC(0x55);
								embRS232.TransEC(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
									case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
									case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
									case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
									default: embRS232.TransEC(embMsgA.body[i]);
									}
								}
								embRS232.TransEC(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
								embRS232.Trans_RDN_Full(embRS232.HostMAC);	
#else	// NOT CAN_ETHERNET_ASU
//_________________________________________________________________________
//______________________________________________________________________________
 //my_int_disable();	//t
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

 //  my_int_enable();

#endif	 // NOT CAN_ETHERNET_ASU
//___________________________________________________________________________________




								flagRequest = 0;
							}  //embMsgA.AddrS()==SelfID()
						}	//embMsgA.TOM()&0x20
					}		//(embMsgA.TOM()&0x01)
					else
					{	
					   //	 printf(" p5");

						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
					  //	 printf(" p6");

							if(embMsgA.AddrS()==SelfID())
							{
						  //	  printf(" p7");

								flagRequest=7;
								embMsgRequest = &embMsgA;
							}
						}  //embMsgA.AddrI()!=embMsgA.AddrS()
					}  //else	embMsgA.TOM()&0x01
				  }	//cashe
				}	//rBuffEmbMsg.Used()
//=================================================================================

//=================================================================================
#ifdef ETH_TRANZIT
 				else // 090115
			   	if(rBuffEmbMsgE.Used())
				{
					EmbMsg embMsgA;
					 embMsgA.Init();	//my

					rBuffEmbMsgE.Get(embMsgA);

#ifndef ANSWER_OLWAIS
					 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR());
#endif //ANSWER_OLWAIS

			   	 //   printf(" p0");

				 //	   printf(" %02X", embMsgA.TOM());

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				//	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				 // 		 printf(" p3");

							if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
							{  
				  //	 		 printf(" p4");
//______________________________________________________________________
#ifdef CAN_ETHERNET_ASU
											
								embRS232.TransEC(0x55);
								embRS232.TransEC(0xAA);
							//	printf("\n\r");
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
							   //		 printf(" %02X",embMsgA.body[i]);

									case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
									case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
									case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
									case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
									default: embRS232.TransEC(embMsgA.body[i]);
									}
								}
								embRS232.TransEC(0x55);
							 //	embRS232.Trans_RDN(COMP_DEF_MAC_END);
								embRS232.Trans_RDN_Full(embRS232.HostMAC);	
#else	// NOT CAN_ETHERNET_ASU
//_________________________________________________________________________
//______________________________________________________________________________
 //my_int_disable();	//t
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

 //  my_int_enable();

#endif	 // NOT CAN_ETHERNET_ASU
//___________________________________________________________________________________




								flagRequest = 0;
							}  //embMsgA.AddrS()==SelfID()
						}	//embMsgA.TOM()&0x20
					}		//(embMsgA.TOM()&0x01)
					else
					{	
				 //	  	 printf(" p5");

						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
				 //	  	 printf(" p6");

							if(embMsgA.AddrS()==SelfID())
							{
	 //						cnt_req++;
	 //1230				 	  	  printf("r:%d ",cnt_req);	  //without this print work worst
						//	 EthSendTimer =	(( ETH_ANS_TIMER) * ((BSP_ALARM_FREQUENCY * CORE_ALARM_FREQUENCY) / 1000l));
							//	flagRequest=2;
								flagRequest=6;

		 //		cntflag6++;				 //test
		  //		printf(" %d", cntflag6);  //test

								embMsgRequest = &embMsgA;
							}
						}  //embMsgA.AddrI()!=embMsgA.AddrS()
					}  //else	embMsgA.TOM()&0x01
			  	   }  // buff_cashe.request
				}	//rBuffEmbMsg.Used()

#endif // ETH_TRANZIT


#endif //  MPC35_MOD_CHANNEL
			}

			if(flagRequest)//embMsgRequest->IsEnd())
			{
				if(embMsgRequest->IsRS485())
				{
		 //			if(flagRequest!=3)
//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
				//			embMsgRequest->SetAddrS(aR);  //bmd
				//			embMsgRequest->SetAddrR(aI);  //bmd


						embMsgAns.SetAddrS(aI);		 //mux
						embMsgAns.SetAddrR(aR);		 //mux


				   //			RS485_disable_RX_interrupt();

							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					//			 printf(".AA");


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
//____________________________________________________________________________________RDN  <<
					  		flagRequest = 0;   //?? only in mpc34 need????????????????????
					}
				}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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
					case 0x01: // cai?in oeia
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;

//==========================================================================================SVCPACK
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
		  
//___________________________________________________________________________________

//==========================================================================================SVCPACK
					case 0x07: /// Aaia?ei cai?in ia?ea?a ai ana iai?aaeaiey
						if(ready_transit) old_ready_transit=0;
						if(ready_mod) old_ready_mod=0;
						break;
					case 0x0A:
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
					case 0x12: // Cai?in ninoiyiey
							embMsgAns.SetType(0x12);
							embMsgAns.SetLength(40);
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unEmb2Mux34.byte[i]);
						break;
					case 0x13:
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);

						  //	bt = (unsigned char far*)0x80000000;
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

					}	 //switch
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
						  embRS232.EmptyReceive();
						  embMsg232.Init(); //090122


						flagRequest = 0;
					}
//___________________________________________________________________________________232e
					 /*
					if(flagRequest == 5) 
					{
						embRS232.TransE(0x55);
						embRS232.TransE(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS232.TransE(0x5A); embRS232.TransE(0x00); break;
								case 0x55: embRS232.TransE(0x5A); embRS232.TransE(0x01); break;
								case 0xA5: embRS232.TransE(0x5A); embRS232.TransE(0x02); break;
								case 0xAA: embRS232.TransE(0x5A); embRS232.TransE(0x03); break;
								default: embRS232.TransE(embMsgAns.body[i]);
							}
						}
						embRS232.TransE(0x55);
					//	embRS232.Trans_RDN(COMP_DEF_MAC_END);
						  embRS232.Trans_RDN_Full(embRS232.HostMAC);	
						   embRS232.EmptyReceiveE();
	
					  	embMsgAns.Init(); //my as in mf_20 previons
						embMsg232E.Init(); //090122

					 	flagRequest = 0;
					}
					*/
//______________________________________________________________________________________232e


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
					   embMsg485.Init(); //090122

						flagRequest = 0;
					}
//_________________________________________________________________________________RDN
				if(flagRequest == 4) 
			   	{ 
			  //		RS485_receive_disable();

			   embRS485.TransE(0x55);
					//	 printf("\n\r>>>>embMsgRequest->AddrS() = %X", embMsgRequest->AddrS());	 //3310
					//	 printf("\n\r>>>>embMsgRequest->AddrI() = %X", embMsgRequest->AddrI());	 //	3309
					//	 printf("\n\r>>>>embMsgRequest->AddrR() = %X", embMsgRequest->AddrR());	 //enower

					//	 printf("\n\r>>>>55");

						embRS485.TransE(0xAA);
					//	 printf("\n\r");

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
				//		 printf(".55");
			//	  RS485_receive_enable();
				  embRS485.Trans_RDN(embMsgAns.AddrS());
			 	embRS485.EmptyReceiveE();	//my: from testing mf20	//remaked 20.02.2008
					   embMsg485E.Init(); //090122

						flagRequest = 0;
					}	// ==4

//________________________________________________________________________________________RDN

				}        //   self or common address ?
			//	else   //not self address!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//	{
#ifdef MPC35_MOD_CHANNEL
// hier need add all for modem and ethernet channells!!!!
			if(flagRequest == 1) 
					{

					 		tBuffEmbMsgEast.Add(embMsg232);
			    //tranzit not need 		 		tBuffEmbMsgWest.Add(embMsg232);

#ifdef 	ETH_TRANZIT
		   
							 tBuffEmbMsgEthAll.Add(embMsg232);
							  tBuffEmbMsgEthAll1.Add(embMsg232);
#endif //ETH_TRANZIT

							unEmb2NetStat.emb2NetStat.selfPacketSend++;

							 embMsg232.Init();  //17.10.2008
		   					}
		
 //_________________________________________________________________________________232e

	if(flagRequest == 5) 
					{
				   			tBuffEmbMsgEast.Add(embMsg232E);
			    //tranzit not need 				tBuffEmbMsgWest.Add(embMsg232E);
#ifdef 	ETH_TRANZIT
					   	   	  tBuffEmbMsgEthAll.Add(embMsg232E);
							  tBuffEmbMsgEthAll1.Add(embMsg232E);

#endif //ETH_TRANZIT

							unEmb2NetStat.emb2NetStat.selfPacketSend++;
							embMsg232E.Init(); //17.10.2008
					}
#endif //MPC35_MOD_CHANNEL
		  

			//	}  //not self addr
#ifdef MPC35_MOD_CHANNEL
//============================================================================================		
				if(flagRequest == 2) 
				{
 				  		tBuffEmbMsgEast.Add(embMsgAns);
				  //tranzit not need 		tBuffEmbMsgWest.Add(embMsgAns);
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
				}	// == 2
//================================================================================================
 //============================================================================================		
				if(flagRequest == 7) 
				{
		  		   
					 	tBuffEmbMsgEast.Add(embMsgAns);
				 //tranzit not need		tBuffEmbMsgWest.Add(embMsgAns);
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
 				}	// == 7
//================================================================================================

 //============================================================================================		
 #ifdef 	ETH_TRANZIT			
				if(flagRequest == 6) 
				{
				 tBuffEmbMsgEthAll.Add(embMsgAns);
			  	 tBuffEmbMsgEthAll1.Add(embMsgAns);
				 unEmb2NetStat.emb2NetStat.selfPacketSend++;
			  	}	// == 6

 #endif //ETH_TRANZIT

//================================================================================================



#endif //MPC35_MOD_CHANNEL




		
				flagRequest = 0;
				embMsgRequest = NULL;
			}
