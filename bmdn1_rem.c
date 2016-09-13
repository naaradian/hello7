//file: bmdn1_rem.c

// my_int_disable();
///////////////////////////////////////	UPP /////////////////////////////////////////////
  /////////////////////////////////////////////////	UPP
//my_int_enable();


 

//////////////////////////////////////////////////	PROTOKOLS
//my_int_disable();



//protokols after UPP to MODEM can somtime read data from upp with all rates for requests for ethernet:

		i232=0;
	//   int tmprem;
	//   if( !send485_enabled)  //t
  //	printf(".");

//++++++++++++++++++++++++++++++++++++++++++++++++++++p4
 // >>hier comment

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
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffRS485.Get(embMsgA);
//- - - - - - - - - -

				embRS485.TransEC(0x55);	  //EC - RDN!!! in all
			  	embRS485.TransEC(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.TransEC(0x5A); embRS485.TransEC(0x00); break;
								case 0x55: embRS485.TransEC(0x5A); embRS485.TransEC(0x01); break;
								case 0xA5: embRS485.TransEC(0x5A); embRS485.TransEC(0x02); break;
								case 0xAA: embRS485.TransEC(0x5A); embRS485.TransEC(0x03); break;
								default: embRS485.TransEC(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransEC(0x55);
						   	embRS485.Trans_RDN(embMsgA.AddrS());
 

//- - - - - - - - - -




			}

#endif //RS485_MSG_BUFF

//________________________________________________________________________



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
	 //100811 test			embRS232.Trans(0x55);
//__________________________test  !!!!
//	for(i = 0; i < 1300; i ++)
//	{
//	  embRS232.Trans(0x55);
//	} 

//__________________________test  !!!

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

 //______________________________________________________________________
			   /*
					 printEthStringAdd(0,0);

					for(i=0; i<embMsg232.FullSize(); i++) 
						{
 							printEthStringAdd(1,embMsg232.body[i]);
			   
						}


		 //	printEthStringAdd(0,0);
		 //	printEthStringAdd(1,embMsg232.CRC());
		 //	printEthStringAdd(1,embMsg232.CalcCRC());
			printEthStringAdd(2,0);
			   */
//________________________________________________________________________

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

//	 	 printEthLongHex(embMsg232.ChkCRC());
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
//			   if(1) //100524


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
#ifndef RS485_MSG_BUFF

							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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

#else  //	 RS485_MSG_BUFF
		tBuffRS485.Add(*embMsgRequest);
#endif	//   RS485_MSG_BUFF




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
#include stack_commands_bmdn1.c

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

					if(flagRequest == 1) 
					{
			   //		 printf("\n\r.................1");
//for(long tst = 0; tst < 100; tst++)	   //t100524
//{	   //t100524		  			 
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
//} //t100524
			  			
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
      
//=================================================================================
#ifdef ETH_TRANZIT	  //090430
				if(rBuffEmbMsgEast.Used())
				{

//#ifdef ETH_DEBUG_ENABLED
//	  printEthStringAdd(0,0);
//	  printEthStringAdd(1,1);
//	  printEthStringAdd(2,0);
//#endif

         //   printf("e");
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
				//	printf("'");
					rBuffEmbMsgEast.Get(embMsgA);
               
//______________________________________________  
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
#ifndef  RS485_MSG_BUFF

							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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
#else  //	 RS485_MSG_BUFF
		tBuffRS485.Add(*embMsgRequest);
#endif	//   RS485_MSG_BUFF


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
#include stack_commands_bmdn1.c

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

//#ifdef ETH_DEBUG_ENABLED
//	    printEthStringAdd(2,0);
//	  printEthStringAdd(0,0);
//	  printEthStringAdd(1,2);
  //	  printEthStringAdd(2,0);
//#endif

      //       printf("\n\r west");
      //      printf("w");
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
//#ifdef ETH_DEBUG_ENABLED
//   	  printEthStringAdd(1,3);
//#endif


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

//#ifdef ETH_DEBUG_ENABLED
//   	  printEthStringAdd(1,4);
//#endif

#ifndef ALL_ADDR
	  			if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
            { 

//#ifdef ETH_DEBUG_ENABLED
//   	  printEthStringAdd(1,5);
//#endif


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
#ifndef   RS485_MSG_BUFF
							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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
#else  //	 RS485_MSG_BUFF
		tBuffRS485.Add(*embMsgRequest);
#endif	//   RS485_MSG_BUFF


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
#include stack_commands_bmdn1.c
 
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
#ifndef   RS485_MSG_BUFF
							embRS485.TransEC(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.TransEC(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


											for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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
#else  //	 RS485_MSG_BUFF
		tBuffRS485.Add(*embMsgRequest);
#endif	//   RS485_MSG_BUFF


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
#include stack_commands_bmdn1.c
                    
						  
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
             //  		 tBuffEmbMsgEthAll.Add(embMsgAns);
  			 //			 tBuffEmbMsgEthAll1.Add(embMsgAns);       //t
              //  } //test
                      
  						unEmb2NetStat.emb2NetStat.selfPacketSend++;
		  		}	// == 6
//================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//	}


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
			     if(embMsg485E.IsEnd()) 
			     
			       {
#ifdef RS485_MSG_BUFF
	//	  flag_wait_rs485 = 0;
#endif
			     
			     
			     	break;	 //t1023

		 			}
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
#include stack_commands_bmdn1.c
   
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




   		while(embRS485.UsedReceive())
   //		if(embRS485.UsedReceive())	//100113
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
			  {
#ifdef RS485_MSG_BUFF
	  //	  flag_wait_rs485 = 0;
#endif

		  				break;
		}
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
//printf("\n\r");
							for(i=0; i<embMsg485.FullSize(); i++) 
							{
								switch(embMsg485.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485.body[i]);
//printf(" %02X",embMsg485.body[i]);
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
if(IsEthTransitMode())
{

						tBuffEmbMsgEthAll.Add(embMsg485);
 						tBuffEmbMsgEthAll1.Add(embMsg485);   //t
 }

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



if(flagRequest) //embMsgRequest->IsEnd())
{
#ifndef ALL_ADDR
 if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
#else //ALL_ADDR
 if(1)
#endif //ALL_ADDR
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
 						if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn
 						{
		   //	  printf("\n\rbefore : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
					
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else
													
							 aS = SelfID();



							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);
	   //		 	printf("\n\rafter : I = %X S = %X R = %X", embMsgRequest->AddrI(),embMsgRequest->AddrS(), embMsgRequest->AddrR());
#ifndef   RS485_MSG_BUFF		
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
#else  //	 RS485_MSG_BUFF
		tBuffRS485.Add(*embMsgRequest);
#endif	//   RS485_MSG_BUFF

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
#ifndef ALL_ADDR
						embMsgAns.SetAddrI(SelfID());
#else
					  embMsgAns.SetAddrI(embMsgRequest->AddrS());
#endif


						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());


//<<<<<<<<<<<<<<<<<<   hier stack commands
#include stack_commands_bmdn1.c
      
      
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

//___________________________________________________________________________________232e
//______________________________________________________________________________________232e

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
			 
   					
 //________________________________________________________________________________________RDN


				}
				else	//not self addr
				{
							
  
				}	   //not self addr
		
  			flagRequest = 0;
			embMsgRequest = NULL;
   //	return; //t 100113
}  //have flagrequest not zero      






      
  // hier comment    
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



