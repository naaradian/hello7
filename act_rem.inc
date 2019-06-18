//file: act_rem.inc

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
   		if((time1-time1old > D485_REQUEST_DELAY) && is_usart1_enabled() ) //t



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
				embRS232.Trans(0x55);
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

   		if(!embMsg232.IsEnd())
  //		if(1)
		{
//_______________________________________________________________232e
		while(embRS232.UsedReceiveE())
		{
 			byte = embRS232.ReceiveE();
	  	switch(byte)
			{
			case 0x55: 
				embMsg232E.Init();
 			   	embRS232.TransE(0x55);
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
// if(1) // t
 {
//_______________________________________________________________232e
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>HIER TUTS!

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
 //_____________________________________________________________________RDN
//______________________________________________________________________232e
 }//to 1  //	!embMsg232.IsEnd
//______________________________________________________________________232e

}//to 1  //!embrs232.isend

//my_int_enable();

///////////////////////////////
///   answer  ///
///////////////////////////////
//my_int_disable();
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
						tBuffEmbMsgEthAll.Add(embMsg485E);
						tBuffEmbMsgEthAll1.Add(embMsg485E);

						/*
	   						InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsg485E.FullSize(); i++) 
						{
				 			switch(embMsg485E.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsg485E.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();






						   */
						//		tBuffEmbMsgEthWest.Add(embMsg485E);
 						//		tBuffEmbMsgEthEast.Add(embMsg485E);
#endif //ETH_TRANZIT

						
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
						  /*
					   //	   	printf("\n\r>");
							for(i=0; i<embMsg485E.FullSize(); i++) 
							{
						   //		switch(embMsg485E.body[i])
							//	{
							//	case 0x5A: embRS232.TransEC(0x5A); embRS232.TransEC(0x00); break;
							//	case 0x55: embRS232.TransEC(0x5A); embRS232.TransEC(0x01); break;
							//	case 0xA5: embRS232.TransEC(0x5A); embRS232.TransEC(0x02); break;
							//	case 0xAA: embRS232.TransEC(0x5A); embRS232.TransEC(0x03); break;
							 //	default:
						 //		 printf(".%02X", embMsg485E.body[i]);
							//	}
							}
							*/
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 		else //t1023
 			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
			 //  ParseMsg((unsigned char *)&embMsg232); 
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
//________________________________________________________________________232e			
		     else if(embMsg232E.IsEnd())//&&embMsg.ChkCRC())
  			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg232E;
					flagRequest=5;	//new
				//	my_printf(0x20);   //t
				}
			}
//________________________________________________________________________232e	
			else
			{

//=================================================================================
#ifdef ETH_TRANZIT	  //090430
				if(rBuffEmbMsgEast.Used())
				{
					printf("1e");	//t

					EmbMsg embMsgA;
					 embMsgA.Init();	//my
				//	printf("'");
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
						printf("2e");	//t

#else
//091228						  if((embMsgA.AddrS()>= 0x6000) &&  (embMsgA.AddrS()< 0x7000))
//091228						  {
					//not	   printf("~");

					   if(1)	//091228
					   {		 //091228
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
//=================================================================================
//=================================================================================
		  	   else // 090115
			 	if(rBuffEmbMsgWest.Used())
				{
					printf("1w");	//t

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

//091228							if(embMsgA.AddrS()==SelfID())
#ifndef ALL_ADDR			
	 	 	if(embMsgA.AddrS()==SelfID())
#else
			if(1)	  //t
#endif //ALL_ADDR

							{
						  //	  printf(" p7");
							 printf("2w");	//t

								flagRequest=7;
								embMsgRequest = &embMsgA;
							}
						}  //embMsgA.AddrI()!=embMsgA.AddrS()
					}  //else	embMsgA.TOM()&0x01
				  }	//cashe
				}	//rBuffEmbMsgWest.Used()
#endif //ETH_TRANZIT
//=================================================================================

//=================================================================================
#ifdef ETH_TRANZIT
 				else // 090115
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

	 //						if(embMsgA.AddrS()==SelfID())

#ifndef ALL_ADDR
						if(embMsgA.AddrS()==SelfID())
						{
#else
					   //		if(0)	//090427
					 //t	 if((embMsgA.AddrS()>= 0x7000) &&  (embMsgA.AddrS()< 0x8000))
						 if(1)		 //t090703
					 {
				   		 printf(".");
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


			}

			if(flagRequest) //embMsgRequest->IsEnd())
			{
  //091228	   		 printf("\n\r flagRequest = %d", flagRequest);

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
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

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

					}  //switch

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
//___________________________________________________________________________________232e
					if(flagRequest == 5) 
					{
				 //	 printf("->5");

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
				 //		embRS232.Trans_RDN(COMP_DEF_MAC_END);	
						embRS232.Trans_RDN_Full(embRS232.HostMAC);	
		  //				embRS232.EmptyReceiveE();

					  	embMsgAns.Init(); //my as in mf_20 previons
						 embMsg232E.Init();  //17.10.2008

					 	flagRequest = 0;
					}
//______________________________________________________________________________________232e

			    
	//_________________________________________________________________________________RDN
			 
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
 bt = (unsigned char *)(NVRAM_BASE);
 *(bt+200) = ecount2 >> 8;
 *(bt+201) = (ecount2++);
 *(bt+201) = (0x33);


 

//>>>>>>>>>>>>>>>>>>>
						  embMsg485E.Init();  //17.10.2008

								flagRequest = 0;
					}	// ==4
					
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
					if(flagRequest == 1) 
					{
			  //		 printf("nsa->1");

//						if((ready_transit)||(ready_mod))
			   //			{
   	 	 	   //	   	  	printf("\n\rT");
	   			 //		printd('\n');
				 //		printd('\r');
				 //		printd('T');



			//		   		printf("\n\r> %04X ", embMsgRequest->AddrS());		//t
	   	//	my_int_disable_irq0();
			   /*
			   if(!(embMsg232.ChkCRC()))
		  	  {
		  	   printEthLongHex(0);
		 	  }
		  	  else
		   	  {
			   printEthLongHex(1);
		      }

				*/


					 		tBuffEmbMsgEast.Add(embMsg232);
					 		tBuffEmbMsgWest.Add(embMsg232);

#ifdef 	ETH_TRANZIT
					   		 //	tBuffEmbMsgEthWest.Add(embMsg232);
 							 //	tBuffEmbMsgEthEast.Add(embMsg232);
							 tBuffEmbMsgEthAll.Add(embMsg232);
							  tBuffEmbMsgEthAll1.Add(embMsg232);
							 /*
					InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsg232.FullSize(); i++) 
						{
				 			switch(embMsg232.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsg232.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();

					  */

#endif //ETH_TRANZIT

							unEmb2NetStat.emb2NetStat.selfPacketSend++;

							 embMsg232.Init();  //17.10.2008

			//_____________my
				   //			if	(tBuffEmbMsgEast.Used())
					 //		{
								 //	printf("\n\r@");
							 //		printf("\n\r@, %d", uscnt);
							//		my_int_disable_usart0();
							//		uscnt++;
					   //		usart0();
							//		uscnt++;
					   //		y_int_enable_irq0();
				//		}
					}
		//  			else
	  	//   		embMsg232.Init();
 //_________________________________________________________________________________232e

	if(flagRequest == 5) 
					{
				 //	 printf("nsa->5");
				   			tBuffEmbMsgEast.Add(embMsg232E);
							tBuffEmbMsgWest.Add(embMsg232E);
#ifdef 	ETH_TRANZIT
					   		 //	tBuffEmbMsgEthWest.Add(embMsg232E);
 					   		 //	tBuffEmbMsgEthEast.Add(embMsg232E);
							  tBuffEmbMsgEthAll.Add(embMsg232E);
							  tBuffEmbMsgEthAll1.Add(embMsg232E);

							 /*
							InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsg232E.FullSize(); i++) 
						{
				 			switch(embMsg232E.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsg232E.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();
							  */
#endif //ETH_TRANZIT




							unEmb2NetStat.emb2NetStat.selfPacketSend++;
							embMsg232E.Init(); //17.10.2008
					}
		//  		else
		 // 				embMsg232E.Init();

 //_________________________________________________________________________________232e
 
				}	   //not self addr
  //============================================================================================		
				if(flagRequest == 2) 
				{
			//	 printf("nsa->2");

					// iinoaaeou a aoooa? ia ia?aaa?o a naou a niioaaonoaee n dir
//					if((ready_transit)||(ready_mod))
					{
//					printf(" Send ");
  	 //t				  printf(".");

				   //	    delay_mcs(200000l);
				   //		_int_disable();
  //			     for(int cntp = 0l; cntp < 1000000l;cntp++){}
				  		tBuffEmbMsgEast.Add(embMsgAns);
				  		tBuffEmbMsgWest.Add(embMsgAns);
				  //		 printf(".%02X", embMsgAns.body[1]);
#ifdef 	ETH_TRANZIT
							//	tBuffEmbMsgEthWest.Add(embMsgAns);
 							//	tBuffEmbMsgEthEast.Add(embMsgAns);

//-->>>>>>>>>>>>>>>>>>>>>>>>>
/*
						   InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsgAns.FullSize(); i++) 
						{
				 			switch(embMsgAns.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsgAns.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();

					  //	embRS485.TransE(0x55);
					  //	embRS485.EmptyReceiveE();  //?
					  //	  embRS485.Trans_RDN(embMsgAns.AddrS());
					  */
//-->>>>>>>>>>>>>>>>>>>>>>>>>



#endif //ETH_TRANZIT
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
				   	 //	delay_transit = 0;
					//   if	(tBuffEmbMsgEast.Used())
					  //		{
								 //	printf("\n\r@");
							 //		printf("\n\r@, %d", uscnt);
							//		my_int_disable_usart0();
							//		uscnt1++;
						//	}

				 //  delay_transit = time1;
				   //		_int_enable();

				    }
				}	// == 2
//================================================================================================
 //============================================================================================		
				if(flagRequest == 7) 
				{
		   //		 printf("nsa->7");

					// iinoaaeou a aoooa? ia ia?aaa?o a naou a niioaaonoaee n dir
//					if((ready_transit)||(ready_mod))
					{
//					printf(" Send ");
  	 //t				  printf(".");

				   //	    delay_mcs(200000l);
				   //		_int_disable();
  //				       for(int cntp = 0l; cntp < 1000000l;cntp++){}
					 	tBuffEmbMsgEast.Add(embMsgAns);
						tBuffEmbMsgWest.Add(embMsgAns);
				  //		 printf("_%02X", embMsgAns.body[1]);
#ifdef 	ETH_TRANZIT
							//	tBuffEmbMsgEthWest.Add(embMsgAns);
 							//	tBuffEmbMsgEthEast.Add(embMsgAns);

//-->>>>>>>>>>>>>>>>>>>>>>>>>
/*
						   InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsgAns.FullSize(); i++) 
						{
				 			switch(embMsgAns.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsgAns.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();

					  //	embRS485.TransE(0x55);
					  //	embRS485.EmptyReceiveE();  //?
					  //	  embRS485.Trans_RDN(embMsgAns.AddrS());
					  */
//-->>>>>>>>>>>>>>>>>>>>>>>>>



#endif //ETH_TRANZIT
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
				   	 //	delay_transit = 0;
					//   if	(tBuffEmbMsgEast.Used())
					  //		{
								 //	printf("\n\r@");
							 //		printf("\n\r@, %d", uscnt);
							//		my_int_disable_usart0();
							//		uscnt1++;
						//	}

				 //  delay_transit = time1;
				   //		_int_enable();

				    }
				}	// == 7
//================================================================================================

 //============================================================================================		
				if(flagRequest == 6) 
				{
		   //		cntflag6++;				 //test
			//	printf(" %d", cntflag6);  //test
			  //	 printf("nsa->6");
					// iinoaaeou a aoooa? ia ia?aaa?o a naou a niioaaonoaee n dir
//					if((ready_transit)||(ready_mod))
					{
//					printf(" Send ");
  	 //t				  printf(".");

				   //	    delay_mcs(200000l);
				   //		_int_disable();
  //				       for(int cntp = 0l; cntp < 1000000l;cntp++){}
				 //		tBuffEmbMsgEast.Add(embMsgAns);
				 //		tBuffEmbMsgWest.Add(embMsgAns);
#ifdef 	ETH_TRANZIT
							//	tBuffEmbMsgEthWest.Add(embMsgAns);
 							//	tBuffEmbMsgEthEast.Add(embMsgAns);
							 tBuffEmbMsgEthAll.Add(embMsgAns);
							 tBuffEmbMsgEthAll1.Add(embMsgAns);

						//	 printf(" %02X", embMsgAns.body[1]);
//-->>>>>>>>>>>>>>>>>>>>>>>>>
					 /*
						   InitAnsE();
						   AddCharAnsE(0x55);
						   AddCharAnsE(0xAA);
		  				for(i=0; i<embMsgAns.FullSize(); i++) 
						{
				 			switch(embMsgAns.body[i])
							{
								case 0x5A:   AddCharAnsE(0x5A);AddCharAnsE(0x00); break;
								case 0x55:AddCharAnsE(0x5A);AddCharAnsE(0x01); break;
								case 0xA5: AddCharAnsE(0x5A);AddCharAnsE(0x02); break;
								case 0xAA:AddCharAnsE(0x5A);AddCharAnsE(0x03); break;
								default: AddCharAnsE(embMsgAns.body[i]); 
							}
						}

						 AddCharAnsE(0x55);
						 SendAnsTransitToEth();
								 */
					  //	embRS485.TransE(0x55);
					  //	embRS485.EmptyReceiveE();  //?
					  //	  embRS485.Trans_RDN(embMsgAns.AddrS());
//-->>>>>>>>>>>>>>>>>>>>>>>>>



#endif //ETH_TRANZIT
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
				   	 //	delay_transit = 0;
					//   if	(tBuffEmbMsgEast.Used())
					  //		{
								 //	printf("\n\r@");
							 //		printf("\n\r@, %d", uscnt);
							//		my_int_disable_usart0();
							//		uscnt1++;
						//	}

				 //  delay_transit = time1;
				   //		_int_enable();

				    }
				}	// == 6
//================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//	}

//my_int_enable();
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



