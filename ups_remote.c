//file ups_remote.c
//extern "C" void remote_usart0_and_usart11()
//	while(1)
 //	{
 //	static char cnt06;

static unsigned char byte; 
static unsigned short i=0;//, j=0;
//static unsigned char mode5A=0; 



  //	unsigned char  *addrRAM;
//static unsigned short shift;
static unsigned long shift;
static  unsigned short len;
static  unsigned short temp_crc;
static  unsigned char cycle;
//unsigned long tmp;
static unsigned char test = 0;
//_________________________>> from bmd_34
//i232=0;
//_________________________<< from bmd_34
   		while(embRS232.UsedReceive())
 		{
	//	printf("1");

  			byte = embRS232.Receive();
  			switch(byte)         
			{
			case 0x55: 
				embMsg.Init();
			 //	my_printf(byte);
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg.Init(); 
				break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; 
		 //	  MessageChar(1,2,2);

			break;
			default:
				if(mode5A) 
				{
	   				embMsg.Add(Modify5A(byte));
					mode5A=0;
				}
				else 
				{
    		 //	   MessageChar(1,1,4);
  	               embMsg.Add(byte);
				}
			}  // switch byte
		  
//___________________________________________________________>>> from bmd_34
			if(embMsg.IsEnd()) 
				break;
  //			if(++i232> 10) break;
		}	 //while
  		if(!embMsg.IsEnd()) // t
		{
//_______________________________________________________________232e
//	   if(!embMsg232E.IsEnd()) // t
//	   if(1)
// {
//_______________________________________________________________232e

			while(embRS485.UsedReceive())
			{
	  //		printf("3");

		  //ok 	my_printf(0x22);	 //t
				byte = embRS485.Receive();
			   //		printf("_____________485:");
		  	   //		my_printf(byte);	//t
	 	 //		  printfpd(" %02X",byte);
				switch(byte)
				{
				case 0x55: embMsg485F.Init();  break; 
				case 0xAA: embMsg485F.Init(); 
         //    printfp("\n\r");
  break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485F.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485F.Add(byte);
				}

				if(embMsg485F.IsEnd()) 
		   				break;
			}

		  //_____________________________________________________________________RDN
//if(!embMsg485F.IsEnd())
//if(!embMsg485E.IsEnd())	  //t091225
  //		{
    // 	}  //	!embMsg485.IsEnd
// }  //	
}
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
     
   			if(embMsg485F.IsEnd()) 
				{
// printfp(" embMsg485F.IsEnd()");
// printfpd("r:%X",embMsg485F.AddrR());
// printfpd("s:%X",embMsg485F.AddrS());
 
 
// static int ecount3 = 0l;
  //				  	 printf("\n\r>485 %d",++ecount3);	   //ttttttt

//_______________________________________________________________________
//hier betveen msg can receive from ethernet with disabling - no data will be added to end of buffer
//_______________________________________________________________________

				  					
					if(embMsg485F.AddrR()!=embMsg485F.AddrS())
					{
 // 	 printfp(" embMsg485F.AddrR()!=embMsg485F.AddrS()");
				   
						// ->>	// Транзитом ответ в линию
						  								// ->>	// Получили запрос из RS-485
	//		if(embMsg485F.ChkCRC() && ((embMsg485F.AddrS()==SelfID()) || (embMsg485F.AddrS()== 0) ) )
	  		if( ((embMsg485F.AddrS()==SelfID()) || (embMsg485F.AddrS()== 0) ) )
								//	if(embMsg485.ChkCRC() && (embMsg485.AddrS()==SelfID()) )
						 			{
//	 printfp(" = || 0");
                           
                        //       embMsg485F.ChkCRC(); //for test
									   	flagRequest=3;
										embMsg485F.SetRS485();
										embMsgRequest = &embMsg485F;
									}
									else
									{
									   flagRequest=0;
									   embMsg485F.Init();

									}

					}	  //
					else
					{
         //       printfp("\n\r embMsg485F.AddrR()==embMsg485F.AddrS()");

					  flagRequest=0;
					  embMsg485F.Init();
					}

					
	 			}

	  else //10.24
	  //		if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
	  if(embMsg.IsEnd())//&&embMsg.ChkCRC())

			{
				{
			  //	  embMsgRequest = &embMsg232;
			  		embMsgRequest = &embMsg;
					flagRequest=1;
				//	my_printf(0x20);   //t
				}
			}
//________________________________________________________________________232e			
//________________________________________________________________________232e	
 					   



			if(flagRequest)//embMsgRequest->IsEnd())
			{
	    //		printfpd(" f:%d ",flagRequest);
		
		   	 //	my_printf(0x21);   //t
            if(embMsgRequest->AddrI() != SelfID())  //110405  do not receive self answers
				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
 //090706		 	  	   if(embMsgRequest->ChkCRC()) //090121	 NEED Recomment!
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//hier can use cache!!!!
//#ifndef ANSWER_OLWAIS
//090706					 if(buff_cashe_request.compare((unsigned long)embMsgRequest->body[1], (unsigned long)embMsgRequest->AddrS(), (unsigned long)embMsgRequest->AddrI(), (unsigned long)embMsgRequest->AddrR(), (unsigned long)embMsgRequest->IsRS485()) != 1)
//#else  //ANSWER_OLWAIS
   			//   	  	 if(1)	//crc checked up
//#endif //ANSWER_OLWAIS
   			   		{
//#ifndef ANSWER_OLWAIS
//   	   	 	  	  	buff_cashe_request.add(embMsgRequest->body[1], embMsgRequest->AddrS(), embMsgRequest->AddrI(), embMsgRequest->AddrR());
//#endif //ANSWER_OLWAIS
 
 //t090205				{
				 
			  //_______________________________________________________________
	   //		   if(!(embMsgRequest->ChkCRC()))
	   //		   {
	   //				 printf("\n\r crc is not correct! :");
	   //				for(long ip=0; ip<embMsgRequest->FullSize(); ip++) 
	   //	 			 {
	   //	   			   printf(".%0X",	embMsgRequest->body[ip]);
	   //		 		 }
	   //		   }
		 //	  printf("\n\r  Len : %X  11: %X 12 : %X", embMsgRequest->Length(), embMsgRequest->body[embMsgRequest->Length()+11],  embMsgRequest->body[embMsgRequest->Length()+12]);

		   //	 	  printf("\n\r CRC: %X ChkCRC: %X CalcRC : %X", embMsgRequest->CRC(), embMsgRequest->ChkCRC(),embMsgRequest->CalcCRC());
		


				  //_______________________________________________________________


					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
				   	// 	my_printf(0x23); //t
			  //		  printfp(" IsRS485 ");

				   //	 	if(flagRequest!=3)
						//____________________________________________________________________________________RDN >>
						if( (flagRequest!=3)  ) //rdn
 						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);

				   //			RS485_disable_RX_interrupt();

							embRS485.Trans(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.Trans(0xAA);
					 //			 printf(".AA");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					  //30		   printf(".%02X",	embMsgRequest->body[i]);
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgRequest->body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.Trans(0x55);
		  
  							flagRequest = 0;
						}
						else
						{
            //       printfp("fl = 3 ");
 
         //         printfp("embMsgAns.SetRS485()");

							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
                     
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
                     
							aR = embMsgRequest->AddrR();
                     
					 		embMsgAns.SetAddrI(aS);	 //t
					 		embMsgAns.SetAddrS(aI);	 //t
					 		embMsgAns.SetAddrR(aR);	 //t
            /*         
                     printfp("aS:");
                     printfpd(" %02X", aS);
                     printfp("aI:");
                     printfpd(" %02X", aI);
                     printfp("aR:");
                     printfpd(" %02X", aR);
                     printfp("embMsgAns.aS:");
                     printfpd(" %02X", (unsigned long)embMsgAns.AddrS());
                     printfp("embMsgAns.aI:");
                     printfpd(" %02X", (unsigned long)embMsgAns.AddrI());
                     printfp("embMsgAns.aR:");
                     printfpd(" %02X", (unsigned long)embMsgAns.AddrR());
                */
	 					}
					}
					else //not 485
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
               
               
#include stack_commands_ups.c       
        
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
					  	embMsgAns.Init(); //my as in mf_20 previons
						embMsg.Init();
					 	flagRequest = 0;
					}


					if(flagRequest == 3) 
					{

			 //	  	 my_printf(0x26);	//t
   		 //	 	  printfp("\n\r>");
					  embRS485.Trans(0x55);
					  embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
	  				//		printfpd(".%02X",embMsgAns.body[i]);
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
			   		 //   embMsg485.Init(); // t my
	 			 	embMsg485F.Init();	//090121
    //           	  printfp("\n\r>embMsg485F.Init()");
						flagRequest = 0;
					}
                    	
               
				}     //addr - self
				else
				{
             if(flagRequest == 1) 
				{

				 	embMsg.Init();
               
 				}   //addr -not self
		
				if(flagRequest == 3) 
				{
				 	embMsg485F.Init();
	
				}
				flagRequest = 0;
				embMsgRequest = NULL;
            } //addr not self
} // flagrequest != 0
//}
