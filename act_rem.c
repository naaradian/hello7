//file: act_rem.c

// my_int_disable();
///////////////////////////////////////	UPP /////////////////////////////////////////////
		while(embRS485.UsedReceive())
		{
			byte = embRS485.Receive();
			/*embRS232.Trans(HexChar((byte>>4)&0x0F));	
			embRS232.Trans(HexChar(byte&0x0F));	
			embRS232.Trans('.');*/
			switch(byte)
			{
				case 0xAA: embMsg485.Init(); stemp++; break; // Пакет
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
			{
			  
		  	  if(embMsg485.Addr() == RRL_ADDR1)
	 		  	{
				received1++;
			  //	  ans1=0;
		  	 		for(i=0; i<16; i++)
			   		{
					  
						unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsg485.Body(i);
						unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485.Body(i);
//____________________________________________________________	
 /*					
					  	if(i == 0)
					  	{
				//	  	 printf("\n\r> .%02X",embMsg485.Body(i) );
					  	}
						else
						{
				 //		  printf(".%02X",embMsg485.Body(i) );
						}
  */						
//____________________________________________________________
						
					}
					for(i=16; i<32; i++)
					{
			   		  	unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485.Body(i);
//____________________________________________________________
  //					 	  printf(".%02X",embMsg485.Body(i) );
//____________________________________________________________
					}

  	   //			 ParsePPU(&unStateRRL.stateRRL.ppu1_bytes[0], ans1,ans2); //for test
					  ans1=0;
	   			}  //addr = 1

			  if(embMsg485.Addr() == RRL_ADDR2)
				{ 
				received1++;

			   //	  ans2=0;
				for(i=0; i<16; i++)
			   		{
					   
						unStateBMD155.stateBMD155.ppu2_bytes[i] = embMsg485.Body(i);
				   		unStateRRL.stateRRL.ppu2_bytes[i] = embMsg485.Body(i);
 //______________________________________________________
   /*			   			 
						if(i == 0)
					  	{
				   //	  	 printf("\n\r> .%02X",embMsg485.Body(i) );
					  	}
						else
						{
				   //		  printf(".%02X",embMsg485.Body(i) );
						}
	*/					
//____________________________________________________________
						 
					}
			     for(i=16; i<32; i++)
					{
					   	unStateRRL.stateRRL.ppu2_bytes[i] = embMsg485.Body(i);
//____________________________________________________________
  	 //					  printf(".%02X",embMsg485.Body(i) );
//____________________________________________________________
					}

   		   //		 ParsePPU(&unStateRRL.stateRRL.ppu2_bytes[0],ans1,ans2); //for test
					  ans2=0;
  				}  //addr = 2
			}	//Is end
		} //while



	  //	if(time1-time1old > 10)   // 10
	  //	if(time1-time1old > 20)   // 10
	//  	if(time1-time1old > 30)   // 10
 //t090429  		if((time1-time1old > 30) && is_usart1_enabled()) //t
 
 
 
#ifndef USART1_TRY_PDC
   		if((time1-time1old > D485_REQUEST_DELAY) && is_usart1_enabled() ) //t
#else
         if(time1-time1old > D485_REQUEST_DELAY) //t

#endif         



  // 	if((((time1-time1old) > 30) && is_usart1_enabled()) ||  ((time1-time1old) > 500))
	   //		if(0) //for test
	   //	if(time1-time1old > 60)   // 10
	   //	if(time1-time1old>50) // 10
		{
			send41++;
		//	printf(" %d", time1);
		//ok	 printEthLongHex(1);
			if(embMsg485Request.IsReadyToSend())
			{
		//	   printEthLongHex(2);

				time1old = time1;

				 /*
				embRS485.TransS(0xFF);
				embRS485.TransS(0xAA);
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.TransS(0x5A); embRS485.TransS(0x00); break;
					case 0x55: embRS485.TransS(0x5A); embRS485.TransS(0x01); break;
					case 0xA5: embRS485.TransS(0x5A); embRS485.TransS(0x02); break;
					case 0xAA: embRS485.TransS(0x5A); embRS485.TransS(0x03); break;
					default: embRS485.TransS(embMsg485Request.body[i]);
					}
				}
		   	   embRS485.TransSGO();
			   	*/
				
			   embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485Request.body[i]);
					}
				}
				 

		   	    embMsg485Request.Init();
			   }  //is ready
			else
			{
				time1old = time1;
				ss++;
				embMsg485Request.Init();
//				if(addr485 >1)
				if(addr485 == RRL_ADDR2)
				{
					ans1++;
					addr485=RRL_ADDR1;
				}
				else
				{
					ans2++;
					addr485=RRL_ADDR2;
				}
				embMsg485Request.SetAddr(addr485);
				embMsg485Request.SetLength(1);
				embMsg485Request.SetBody(0,0x00);
				embMsg485Request.CalcCRC();
			  	 /*
				embRS485.TransS(0xFF);
				embRS485.TransS(0xAA);
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.TransS(0x5A); embRS485.TransS(0x00); break;
					case 0x55: embRS485.TransS(0x5A); embRS485.TransS(0x01); break;
					case 0xA5: embRS485.TransS(0x5A); embRS485.TransS(0x02); break;
					case 0xAA: embRS485.TransS(0x5A); embRS485.TransS(0x03); break;
					default: embRS485.TransS(embMsg485Request.body[i]);
					}
				}
		  		 embRS485.TransSGO();
					*/
					
				embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485Request.body[i]);
					}
				}


				embMsg485Request.Init();
			}
		}
////////////////////////////////////////////////
	 //	if(ans1>=200)
		if(ans1>=10)
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu1_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu1_bytes[i] = 0;
			}
//			unStateRRL.stateRRL.state = 0x00;  //keep comments
		 ans1 = 0;
		}
	// 	if(ans2>=200)
	 	if(ans2>=10)
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu2_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu2_bytes[i] = 0;
			}
			unStateRRL.stateRRL.state = 0x00;		//keep non-comments
			ans2 = 0;
		}
/////////////////////////////////////////////////	UPP
//my_int_enable();





//////////////////////////////////////////////////	PROTOKOLS
//my_int_disable();



//protokols after UPP to MODEM can somtime read data from upp with all rates for requests for ethernet:

		i232=0;
	//   int tmprem;
	//   if( !send485_enabled)  //t
		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();

//___________________________________________________________________
	   //		printf(" %02X", byte);	   //temporary
		 //	 embRS232.Trans(byte); //temporary send back and to 232
	   //		 embRS232.Trans('-'); //temporary send back and to 232
//___________________________________________________________________

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
			{
			//print("\n\nCRC: % 02X CalcCRC : %02X",embMsg232.CRC(), embMsg232.CalcCRC());
		//	tmprem = embMsg232.CRC();
		 // 	printEthLongHex(embMsg232.CRC());
		 //	 printEthString(" ", 4);
		  //	  if(!(embMsg232.ChkCRC()))
		  //	  {
		  //	   printEthLongHex(tmprem);
		 //	  }
		  //	  else
		   //	  {
			//   printEthLongHex(1);
			//   }

//		 	 printEthLongHex(embMsg232.ChkCRC());
		  //	   printEthString(" ", 4);

		 //	printEthLongHex(embMsg232.CalcCRC());
		 //	   printEthString(" ", 4);

				break;
			}
  			if(++i232 > 10) break;
		}
      
//++++++++++++++++++++++++++++++++++++++++++++++++++++p
	if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
			 //  ParseMsg((unsigned char *)&embMsg232); 
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
         
			if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
#else
				if(1) //090427
#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
				{

			//	   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn		??????
 						{
		  //only1		printf("\n\r f1:%d",flagRequest );
			// hier are data to transmit to tuts
			// t1022		    my_int_disable();	//t

					
//_____________________________________________________________________________________
		 		   //			printf("\n\rbefore: \n\r ");
			  //	   if(embMsgRequest->CRC() != embMsgRequest->CalcCRC())
				//   			for(i=0; i<embMsgRequest->FullSize(); i++) 
				  // 			{
				   	// 		   printf(" %02X",	embMsgRequest->body[i]);
				   	  //		}
 	   	 		   	  //		printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());
				//   printf("\n\rflagrequest : %d", flagRequest);

//_____________________________________________________________________________________
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

//t 090430_________________________________________
					  //		if(embMsg485E.body[1] < 0x10)
					  // 	    static int ecount2 = 0;
  	 			  	 // 		printf("\n\r>M %ld",++ecount2);
				   	  // 		printf("\n\rTR>time1 : %d S :%X R:%X I :%X N:%X >",time1, aS,aR,aI,embMsgRequest->body[1]); //090427
//___________t 090430
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//bt = (unsigned char *)(NVRAM_BASE);
 //*(bt+200) = (++ecount2 >> 8);
 //*(bt+201) = (ecount2);
 //*(bt+201) = (0x33);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


				   //		embMsgRequest->CalcCRC(); //0129

				   //			RS485_disable_RX_interrupt();

							embRS485.TransE(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransE(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());

//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
				    flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
#include stack_commands.c

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

					if(flagRequest == 1) 
					{
			   //		 printf("\n\r.................1");
			  			 
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

						 embMsg232.Init();  //17.10.2008

						flagRequest = 0;
					}	//  == 1



				}
				else	//not self addr
				{
					if(flagRequest == 1) 
					{
	 

					 		tBuffEmbMsgEast.Add(embMsg232);
					 		tBuffEmbMsgWest.Add(embMsg232);

#ifdef 	ETH_TRANZIT
					   		 //	tBuffEmbMsgEthWest.Add(embMsg232);
 							 //	tBuffEmbMsgEthEast.Add(embMsg232);
if(IsEthTransitMode())
{
                      
							 tBuffEmbMsgEthAll.Add(embMsg232);
							 tBuffEmbMsgEthAll1.Add(embMsg232);   //t
}                       
				  
#endif //ETH_TRANZIT

							unEmb2NetStat.emb2NetStat.selfPacketSend++;

							 embMsg232.Init();  //17.10.2008
     					}
	 
			}	   //not self addr
  //============================================================================================		
		//================================================================================================
 //============================================================================================		
	//================================================================================================

 //============================================================================================		
	 //================================================================================================
             embMsg232.Init(); //090708
				flagRequest = 0;
				embMsgRequest = NULL;
}  //have flagrequest not zero
         
         


//++++++++++++++++++++++++++++++++++++++++++++++++++++p      
      
//++++++++++++++++++++++++++++++++++++++++++++++++++++p1 
	while(embRS485.UsedReceiveE())
			{
				byte = embRS485.ReceiveE();
				
			   	switch(byte)
				{
				case 0x55: embMsg485E.Init(); //  printf("\n\r++++");
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
				 
			  //	 embMsg485E.Add(byte);	 //1021



			 //	  	printf(".%X", byte);
			     if(embMsg485E.IsEnd()) 	break;	 //t1023

		 
	   //t1023			break;
	 		} //embrs485 usedReceive
         
  if(embMsg485E.IsEnd()) 
		 //	 if(embMsg485E.IsEnd() && is_usart1_enabled())   //t1021 timer after send request is finished
				{
//______________________________________________________________
		   	  //		static long cnt485t  = 0;	 //090430
		   //			if(embMsg485E.AddrI() == 0x1234)
	  //		if(embMsg485E.body[1] < 0x10)

	 //	printf("\n\rRec>cnt %d S: %X R: %X I: %X N: %X time1 : %d" , ++cnt485t, embMsg485E.AddrS(), embMsg485E.AddrR(), embMsg485E.AddrI(), embMsg485E.body[1], time1); //090429
//______________________________________________________________
				 //  unsigned long tmpl;
				 //  tmpl =  embMsg485E.AddrI() & 0xff;
				 //  tmpl <<= 8;
				 //  tmpl += embMsg485E.AddrS()& 0xff;
				 //  tmpl <<= 8;
				//   tmpl += embMsg485E.AddrR()& 0xff;
				   // printEthLongHex(tmpl);

					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{

			  //			printEthLongHex(tmpl);

				  			aI = embMsg485E.AddrI();
							aS = embMsg485E.AddrS();
							aR = embMsg485E.AddrR();
				   //			embMsg485E.SetAddrI(aR);
				   //			embMsg485E.SetAddrS(aI);
				   //			embMsg485E.SetAddrR(aS);
								embMsg485E.SetAddrI(aR);
								embMsg485E.SetAddrS(aS);
								embMsg485E.SetAddrR(aI);

//______________________________________________________________________________
#ifdef CAN_ETHERNET_ASU
							embRS232.TransEC(0x55);
							embRS232.TransEC(0xAA);
							for(i=0; i<embMsg485E.FullSize(); i++) 
							{
								switch(embMsg485E.body[i])
								{
								case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
								case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
								case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
								case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
								default: embRS232.TransEC(embMsg485E.body[i]);
								}
							}
							embRS232.TransEC(0x55);
					  //		embRS232.Trans_RDN(COMP_DEF_MAC_END);
							embRS232.Trans_RDN_Full(embMsg485E.HostMAC);	

//______________________________________________________________________________
#else
   //my_int_disable(); //t
    //usart_command_eth_off();  //t

			 //	  if(embMsg485E.ChkCRC())
			 //    {
			 //		   embMsg485E.CalcCRC(); //t
			  //	   	   ParseMsg((unsigned char *)&embMsg485E); //t
			  	  //		embRS232.Trans(0x55);
				//  delay_mcs(2000l);  	//t1021
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
					// 	delay_mcs(2000l);  	//t1021
					  //	embRS232.Trans(0x55);
						//	 return; //t1021
				 //	   }
   //	usart_command_eth_on();	//t
   //my_int_enable();	//t

// comment was
#endif
//___________________________________________________________________________________




					   //	  embMsg485E.Init(); //1021
				 	    embMsg485E.Init(); //090430
			   	} //s == r!
				else 		//t1021
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
								tBuffEmbMsgEast.Add(embMsg485E);   //<<<<<<<<<<<<<<<<<<<<<<
								tBuffEmbMsgWest.Add(embMsg485E);
#ifdef 	ETH_TRANZIT
if(IsEthTransitMode())
{

						tBuffEmbMsgEthAll.Add(embMsg485E);
 						tBuffEmbMsgEthAll1.Add(embMsg485E);   //t
 }

				  						//		tBuffEmbMsgEthWest.Add(embMsg485E);
 						//		tBuffEmbMsgEthEast.Add(embMsg485E);
#endif //ETH_TRANZIT
						unEmb2NetStat.emb2NetStat.selfPacketSend++;	
				 	   embMsg485E.Init(); //090430				
							}
							else
							{
								// ->>	// Iieo?eee cai?in ec Ethernet
	 								flagRequest=4;
								embMsg485E.SetRS485();
								embMsgRequest = &embMsg485E;
							}
						}  //s != self
					}	//r != S
				  
				}  //embrs485E.isend
            
			if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
#else
				if(1) //090427
#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
				{

			//	   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
				   //____________________________________________________________________________________RDN >>
 							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aR);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aS);
					      flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
#include stack_commands.c
   
					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

						 
	if(flagRequest == 4) 
			   	{ 
			  //	 printf("->4");


						   embRS485.TransE(0x55);
		  				   embRS485.TransE(0xAA);
					//	   printf("\n\r");

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

//<<<<<<<<<<<<<<<<<<<
 

 

//>>>>>>>>>>>>>>>>>>>
						  embMsg485E.Init();  //17.10.2008

								flagRequest = 0;
					}	// ==4
					
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
                embMsg485E.Init(); //090708
            }
			  //================================================================================================
            embMsg485E.Init();    //090708
				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero
 
//++++++++++++++++++++++++++++++++++++++++++++++++++++p1 

//++++++++++++++++++++++++++++++++++++++++++++++++++++p2  

//=================================================================================
#ifdef ETH_TRANZIT	  //090430
				if(rBuffEmbMsgEast.Used())
				{
      //      printf("\n\r east");
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
				//	printf("'");
					rBuffEmbMsgEast.Get(embMsgA);
               
//______________________________________________  
/*             
printf("\n\r>");
 for(i=0; i<embMsgA.FullSize(); i++) 
								{
                         printf(" %02X", embMsgA.body[i]);
                        }
                      */
//_______________________________________________               
               
#ifndef ANSWER_OLWAIS
					 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485());
#endif //ANSWER_OLWAIS

				 //	   printf(" %02X", embMsgA.TOM());

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				// 	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				   	 //	 printf(" p3");

				   	  		if(embMsgA.AddrS()==SelfID())//eee ?aaai 0000 eee FFFF
					   //	   if(1) //090427
							{  
					  	// 	 printf(" p4");
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
#ifndef ALL_ADDR
						if(embMsgA.AddrS()==SelfID())
						{
             //ok      	 printf(" p6a");

#else
//091228			  if((embMsgA.AddrS()>= 0x6000) &&  (embMsgA.AddrS()< 0x7000))
//091228			  {
                    if(1)  //091228
                    {  //091228
                  
                    
					//not	   printf("~");

					   //		if(1)	//090427
#endif // ALL_ADDR
					 //		{
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
				}	//rBuffEmbMsgEast.Used()
//#endif //ETH_TRANZIT
//=================================================================================
			if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
#else
				if(1) //090427
#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
				{

			//	   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn		??????
 						{
		  //only1		printf("\n\r f1:%d",flagRequest );
			// hier are data to transmit to tuts
			// t1022		    my_int_disable();	//t

					
//_____________________________________________________________________________________
		 		   //			printf("\n\rbefore: \n\r ");
			  //	   if(embMsgRequest->CRC() != embMsgRequest->CalcCRC())
				//   			for(i=0; i<embMsgRequest->FullSize(); i++) 
				  // 			{
				   	// 		   printf(" %02X",	embMsgRequest->body[i]);
				   	  //		}
 	   	 		   	  //		printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());
				//   printf("\n\rflagrequest : %d", flagRequest);

//_____________________________________________________________________________________
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

//t 090430_________________________________________
					  //		if(embMsg485E.body[1] < 0x10)
					  // 	    static int ecount2 = 0;
  	 			  	 // 		printf("\n\r>M %ld",++ecount2);
				   	  // 		printf("\n\rTR>time1 : %d S :%X R:%X I :%X N:%X >",time1, aS,aR,aI,embMsgRequest->body[1]); //090427
//___________t 090430
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//bt = (unsigned char *)(NVRAM_BASE);
 //*(bt+200) = (++ecount2 >> 8);
 //*(bt+201) = (ecount2);
 //*(bt+201) = (0x33);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


				   //		embMsgRequest->CalcCRC(); //0129

				   //			RS485_disable_RX_interrupt();

							embRS485.TransE(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransE(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());

//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
					  flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
#include stack_commands.c

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

			 					
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
						//  			else
	  	//   		embMsg232.Init();
 //_________________________________________________________________________________232e

			//  		else
		 // 				embMsg232E.Init();

 //_________________________________________________________________________________232e
 
				}	   //not self addr
  //============================================================================================		
				if(flagRequest == 2) 
				{
		  		  		tBuffEmbMsgEast.Add(embMsgAns);
				  		tBuffEmbMsgWest.Add(embMsgAns);
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
			 	}	// == 2
//================================================================================================
 //============================================================================================		
			 //================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero


//#endif //ETH_TRANZIT

//++++++++++++++++++++++++++++++++++++++++++++++++++++p2  //ethernet

//++++++++++++++++++++++++++++++++++++++++++++++++++++p3
 	if(rBuffEmbMsgWest.Used())
				{
      //       printf("\n\r west");
       //     printf("1w");
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
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485());
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
#ifndef ALL_ADDR
							if(embMsgA.AddrS()==SelfID())
#else
                     if(1) //091228
#endif                     
                     
							{
						  //	  printf(" p7");

								flagRequest=7;
								embMsgRequest = &embMsgA;
							}
						}  //embMsgA.AddrI()!=embMsgA.AddrS()
					}  //else	embMsgA.TOM()&0x01
				  }	//cashe
				}	//rBuffEmbMsgWest.Used()
		if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
            { 
#else
				if(1) //090427
            {
    //           printf("p8");

#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
		  //		{

	  //			   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn		??????
 						{
		  //only1		printf("\n\r f1:%d",flagRequest );
			// hier are data to transmit to tuts
			// t1022		    my_int_disable();	//t

					
//_____________________________________________________________________________________
		 		   //			printf("\n\rbefore: \n\r ");
			  //	   if(embMsgRequest->CRC() != embMsgRequest->CalcCRC())
				//   			for(i=0; i<embMsgRequest->FullSize(); i++) 
				  // 			{
				   	// 		   printf(" %02X",	embMsgRequest->body[i]);
				   	  //		}
 	   	 		   	  //		printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());
				//   printf("\n\rflagrequest : %d", flagRequest);

//_____________________________________________________________________________________
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

//t 090430_________________________________________
					  //		if(embMsg485E.body[1] < 0x10)
					  // 	    static int ecount2 = 0;
  	 			  	 // 		printf("\n\r>M %ld",++ecount2);
				   	  // 		printf("\n\rTR>time1 : %d S :%X R:%X I :%X N:%X >",time1, aS,aR,aI,embMsgRequest->body[1]); //090427
//___________t 090430
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//bt = (unsigned char *)(NVRAM_BASE);
 //*(bt+200) = (++ecount2 >> 8);
 //*(bt+201) = (ecount2);
 //*(bt+201) = (0x33);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


				   //		embMsgRequest->CalcCRC(); //0129

				   //			RS485_disable_RX_interrupt();

							embRS485.TransE(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransE(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   embRS485.Trans_RDN(embMsgRequest->AddrS());

//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
					   flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
#include stack_commands.c
 
					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

							
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
				 
 //_________________________________________________________________________________232e
 
				}	   //not self addr
  //============================================================================================		
			 //================================================================================================
 //============================================================================================		
				if(flagRequest == 7) 
				{
		 			 	tBuffEmbMsgEast.Add(embMsgAns);
						tBuffEmbMsgWest.Add(embMsgAns);
	  		  			unEmb2NetStat.emb2NetStat.selfPacketSend++;
			  	}	// == 7
//================================================================================================
 
				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero
            



 #endif //ETH_TRANZIT
//++++++++++++++++++++++++++++++++++++++++++++++++++++p3 


//++++++++++++++++++++++++++++++++++++++++++++++++++++p4
#ifdef ETH_TRANZIT
 		 //		else // 090115
      if(IsEthTransitMode())
		   	if(rBuffEmbMsgE.Used())
				{
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
			   	 //	printf(">>>>>"); //090701
					rBuffEmbMsgE.Get(embMsgA);

#ifndef ANSWER_OLWAIS
					 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	 	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485());
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

	 //						if(embMsgA.AddrS()==SelfID())

#ifndef ALL_ADDR
						if(embMsgA.AddrS()==SelfID())
						{
#else
					   //		if(0)	//090427
					 //t	 if((embMsgA.AddrS()>= 0x7000) &&  (embMsgA.AddrS()< 0x8000))
						 if(1)		 //t090703
					 {
         //       		 printf(" r> %ld : %x ",counter_mreceive++, embMsgA.AddrS());
#endif // ALL_ADDR

				 //			{
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
//=================================================================================
		if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
#else
				if(1) //090427
#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
				{

			//	   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn		??????
 						{
		  //only1		printf("\n\r f1:%d",flagRequest );
			// hier are data to transmit to tuts
			// t1022		    my_int_disable();	//t

					
//_____________________________________________________________________________________
		 		   //			printf("\n\rbefore: \n\r ");
			  //	   if(embMsgRequest->CRC() != embMsgRequest->CalcCRC())
				//   			for(i=0; i<embMsgRequest->FullSize(); i++) 
				  // 			{
				   	// 		   printf(" %02X",	embMsgRequest->body[i]);
				   	  //		}
 	   	 		   	  //		printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());
				//   printf("\n\rflagrequest : %d", flagRequest);

//_____________________________________________________________________________________
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

//t 090430_________________________________________
					  //		if(embMsg485E.body[1] < 0x10)
					  // 	    static int ecount2 = 0;
  	 			  	 // 		printf("\n\r>M %ld",++ecount2);
				   	  // 		printf("\n\rTR>time1 : %d S :%X R:%X I :%X N:%X >",time1, aS,aR,aI,embMsgRequest->body[1]); //090427
//___________t 090430
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//bt = (unsigned char *)(NVRAM_BASE);
 //*(bt+200) = (++ecount2 >> 8);
 //*(bt+201) = (ecount2);
 //*(bt+201) = (0x33);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


				   //		embMsgRequest->CalcCRC(); //0129

				   //			RS485_disable_RX_interrupt();

							embRS485.TransE(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransE(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


											for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   	embRS485.Trans_RDN(embMsgRequest->AddrS());

//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
						 flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
#include stack_commands.c
                    
						  
					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

			 					
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
				  		//  		else
		 // 				embMsg232E.Init();

 //_________________________________________________________________________________232e
 
				}	   //not self addr
  //============================================================================================		
			   //============================================================================================		
				if(flagRequest == 6) 
				{
            
							//	tBuffEmbMsgEthWest.Add(embMsgAns);
 							//	tBuffEmbMsgEthEast.Add(embMsgAns);
             //   for (long ians = 0; ians < 100; ians++) //test
             //  {
#ifdef ETH_TRANZIT
             
               		 tBuffEmbMsgEthAll.Add(embMsgAns);
  						 tBuffEmbMsgEthAll1.Add(embMsgAns);       //t
#endif                   
              //  } //test
                      
  						unEmb2NetStat.emb2NetStat.selfPacketSend++;
                  
		  		}	// == 6
//================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//	}



//++++++++++++++++++++++++++++++++++++++++++++++++++++p4


    
      
      
      
      
      
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



