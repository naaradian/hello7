//file: bmdn1_rem.c

// my_int_disable();
///////////////////////////////////////	UPP /////////////////////////////////////////////
///////////////////////////////////////	UPP /////////////////////////////////////////////
		while(embRS485.UsedReceive())
		{
			byte = embRS485.Receive();
         
 #ifdef ETH_DEBUG_ENABLED
//    printEthLongHex(byte);

//	  printEthStringAdd(0,0);
//	  printEthStringAdd(1,1);
//	  printEthStringAdd(2,0);
#endif

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
			  
//		  	  if(embMsg485.Addr() == RRL_ADDR1)
	 	//	  if(1)
           	{
				received1++;
          #ifdef ETH_DEBUG_ENABLED
   //      printEthLongHex(received1);
   /*
    if(GetTestMode() == 0x50)
			{
     printEthLongHex(0x888888);
    
         
  	  printEthStringAdd(0,0);
     }
     */
//	  printEthStringAdd(1,1);
//	  printEthStringAdd(2,0);
#endif
   
            
			  //	  ans1=0;
    if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1<");
		 	}
       
           
           
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
         #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    /*
    if(GetTestMode() == 0x50)
			{


  //	  printEthStringAdd(0,0);
  	  printEthStringAdd(1,embMsg485.Body(i));
     }
     */
//	  printEthStringAdd(2,0);
#endif




						
					}
					for(i=16; i<32; i++)
					{
               
             #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    /*
 if(GetTestMode() == 0x50)
			{


//	  printEthStringAdd(0,0);
  	  printEthStringAdd(1,embMsg485.Body(i));
//	  printEthStringAdd(2,0);
}
*/
#endif
       
               
               if(GetTestMode() == 0x50)
			{
	 //		   printfp("_");
			   printfpd("_%X", embMsg485.Body(i));

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }
          //    printEthLongHex(received1);

               
               
               
			   	  	unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485.Body(i);
//____________________________________________________________
  //					 	  printf(".%02X",embMsg485.Body(i) );
//____________________________________________________________
					}
               
            #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    /*
   if(GetTestMode() == 0x50)
			{

//	  printEthStringAdd(0,0);
 //	  printEthStringAdd(1,embMsg485.Body(i));
	  printEthStringAdd(2,0);
     }
     */
#endif
           
               

  	   //			 ParsePPU(&unStateRRL.stateRRL.ppu1_bytes[0], ans1,ans2); //for test
					  ans1=0;
	   			}  //addr = 1
               
               
#ifndef ONE_TRUNK
               

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
            
#endif // ONE_TRUNK
            
            
			}	//Is end
		} //while



	  //	if(time1-time1old > 10)   // 10
	  //	if(time1-time1old > 20)   // 10
	//  	if(time1-time1old > 30)   // 10
 //t090429  		if((time1-time1old > 30) && is_usart1_enabled()) //t
 
 
 
         if(time1-time1old > D485_REQUEST_DELAY) //t

  // 	if((((time1-time1old) > 30) && is_usart1_enabled()) ||  ((time1-time1old) > 500))
	   //		if(0) //for test
	   //	if(time1-time1old > 60)   // 10
	   //	if(time1-time1old>50) // 10
		{
			send41++;
         ans1++;
          
		//	printf(" %d", time1);
		//ok	 printEthLongHex(1);
      
      
  //hier need to use buffer for sending messages   
 
  
  
     //     if(tBuffEmbMsg485Request_1.Used() && send_keeper1)
          if(tBuffEmbMsg485Request_1.Used())
			{
		//	printfp("\n\r________t1");
		//		EmbMsg485 embMsg485Request_1;
      
 #ifdef ETH_DEBUG_ENABLED
      
      
  if(GetTestMode() == 0x50)
			{
        	printEthLongHex(0x999999);

//	  printEthStringAdd(0,0);
 //	  printEthStringAdd(1,embMsg485.Body(i));
  //	  printEthStringAdd(2,0);
     }
#endif
     
      
      
				embMsg485Request.Init();
				tBuffEmbMsg485Request_1.Get(embMsg485Request);
            embMsg485Request.SetReadyToSend();   //new
            
   #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
 //  if(GetTestMode() == 0x50)
  //			{
 //   printEthStringAdd(0,0);
   //   printEthLongHex(0x11 + (embMsg485Request.body[1] << 8));
  //	printEthLongHex(0x11 + (embMsg485Request.body[2] << 8));
  //    printEthStringAdd(2,0);
   //  }
//	  printEthStringAdd(2,0);
#endif
       
            
            
            

         }
       //  else  if(tBuffEmbMsg485Request_2.Used() && send_keeper2)
       
#ifndef ONE_TRUNK
       
         else  if(tBuffEmbMsg485Request_2.Used())
			{
		//	printfp("\n\r________t1");
		//		EmbMsg485 embMsg485Request_1;
				embMsg485Request.Init();
				tBuffEmbMsg485Request_2.Get(embMsg485Request);
            embMsg485Request.SetReadyToSend();

         }

#endif         
  
  
   
      
      
			if(embMsg485Request.IsReadyToSend())
			{
//can dublicate it to rs232 to testing it         
         
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
               
        if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1>");
		 	}
         
          #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    if(GetTestMode() == 0x50)
			{


	  printEthStringAdd(0,0);
  //	  printEthStringAdd(1,embMsg485.Body(i));
     }
//	  printEthStringAdd(2,0);
#endif

        
               
               
				
			   embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485Request.Length()+5; i++) 
				{
            
   if(GetTestMode() == 0x50)
					{
			   			printfp(".");
			   			printfpd("%X",embMsg485Request.body[i]);
			 		}
         
     #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    if(GetTestMode() == 0x50)
			{


//	  printEthStringAdd(0,0);
	  printEthStringAdd(1,embMsg485Request.body[i]);
     }
//	  printEthStringAdd(2,0);
#endif
          
            
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
                
            #ifdef ETH_DEBUG_ENABLED
    //ok     printEthLongHex(received1);
    if(GetTestMode() == 0x50)
			{


	 // printEthStringAdd(0,0);
  //	  printEthStringAdd(1,embMsg485.Body(i));
   //  }
	  printEthStringAdd(2,0);
     }
#endif
           
                
                
	    }  //is ready
	else
        //  if(0) //temporary
     		{
				time1old = time1;
				ss++;
				embMsg485Request.Init();
            
#ifndef ONE_TRUNK
            
//				if(addr485 >1)
				if(addr485 == RRL_ADDR2)
				{
	 //				ans1++;
					addr485=RRL_ADDR1;
				}
				else
				{
		//			ans2++;
					addr485=RRL_ADDR2;
				}
				embMsg485Request.SetAddr(addr485);
#else
           embMsg485Request.SetAddr(RRL_ADDR1);

#endif   


         
            
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
               
                 if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1>>");
		 	}

					
				embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
				for(i=0; i<embMsg485Request.Length()+5; i++) 
				{
            
          if(GetTestMode() == 0x50)
					{
			   			printfp(".");
			   			printfpd("%X",embMsg485Request.body[i]);
			 		}
   
            
            
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
   
     #ifndef ONE_TRUNK

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
      
     #endif 
/////////////////////////////////////////////////	UPP
//my_int_enable();






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

//#ifdef RS485_MSG_BUFF
		   if(flag_wait_rs485)
		   {
		   if(time1 < time_lastsend_rs485) 	time_lastsend_rs485 = time1;
		   if((time1 - time_lastsend_rs485) > RS485_TRANS_TIMEOUT)	flag_wait_rs485 = 0;
		   }


 	  //		if(tBuffRS485.Used() && (!(flag_wait_rs485)) )	//090713
         if(tBuffEmbMsg485Request_1.Used() && (!(flag_wait_rs485)) )
			{
			   flag_wait_rs485 = 1;
			   time_lastsend_rs485 = time1;
	  //			EmbMsg embMsgA;
     			EmbMsg485 embMsgA;
				embMsgA.Init();
 //				tBuffRS485.Get(embMsgA);
 				tBuffEmbMsg485Request_1.Get(embMsgA);
            
            
/*            
#ifdef RS485E_ENABLED

				embRS485.TransE(0x55);	  //EC - RDN!!! in all
			  	embRS485.TransE(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   	embRS485.Trans_RDN(embMsgA.AddrS());
   
#else
*/
				embRS485.Trans(0x55);	  //EC - RDN!!! in all
			  	embRS485.Trans(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.Trans(0x55);

//#endif
            
            
            
            
            
//- - - - - - - - - -
 /*
				embRS485.Trans(0x55);	  //EC - RDN!!! in all
			  	embRS485.Trans(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.Trans(0x55);
//						   	embRS485.Trans_RDN(embMsgA.AddrS());
     */

//- - - - - - - - - -




			}

//#endif //RS485_MSG_BUFF

//________________________________________________________________________


//________________________________________________________________________rs485e

//#ifdef RS485_MSG_BUFF
		   if(flag_wait_rs485E)
		   {
		   if(time1 < time_lastsend_rs485E) 	time_lastsend_rs485E = time1;
		   if((time1 - time_lastsend_rs485E) > RS485E_TRANS_TIMEOUT)	flag_wait_rs485E = 0;
		   }


 			if(tBuffRS485E.Used() && (!(flag_wait_rs485E)) )	//090713
			{
			   flag_wait_rs485E = 1;
			   time_lastsend_rs485E = time1;
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffRS485E.Get(embMsgA);
            
//#ifdef RS485E_ENABLED

				embRS485.TransE(0x55);	  //EC - RDN!!! in all
			  	embRS485.TransE(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.TransE(0x5A); embRS485.TransE(0x00); break;
								case 0x55: embRS485.TransE(0x5A); embRS485.TransE(0x01); break;
								case 0xA5: embRS485.TransE(0x5A); embRS485.TransE(0x02); break;
								case 0xAA: embRS485.TransE(0x5A); embRS485.TransE(0x03); break;
								default: embRS485.TransE(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.TransE(0x55);
						   	embRS485.Trans_RDN(embMsgA.AddrS());
   /*
#else
				embRS485.Trans(0x55);	  //EC - RDN!!! in all
			  	embRS485.Trans(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.Trans(0x55);

#endif
            
  */          
            
            
            
//- - - - - - - - - -
 /*
				embRS485.Trans(0x55);	  //EC - RDN!!! in all
			  	embRS485.Trans(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
							{
								switch(embMsgA.body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgA.body[i]);
								}
							   //	RS485_receive_reset();
							}
						   
							embRS485.Trans(0x55);
//						   	embRS485.Trans_RDN(embMsgA.AddrS());
     */

//- - - - - - - - - -




			}

//#endif //RS485_MSG_BUFF

//________________________________________________________________________rs485e




		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
 //          printEthLongHex(byte);

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
 		//	if(++i232 > RS232_BYTES_LIMIT) break;
		}
      
//++++++++++++++++++++++++++++++++++++++++++++++++++++p
	if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
			 //  ParseMsg((unsigned char *)&embMsg232); 
#ifdef CHECK_CRC           
       if(embMsg232.ChkCRC())   
#else       
       if(1)
#endif       
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
            else{ /* Body */
             embMsg232.Init();
            
         } /* Endbody */
			}
         
	  	if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
//			   if(1) //100524


		if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))  //we are node
#else
		if(1) //090427
#endif //ALL_ADDR
			// &&(embMsgRequest->TOM()|0x01))
		{

			//	   printf("p8");
         //     rxusart++;
         //     printfpd(" \n\r %d", rxusart);
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) //need resend to rs485 ?
					{
					//t	if(flagRequest!=3)
 //____________________________________________________________________________________RDN >>
 			 //			if( (flagRequest!=3)   &&  (flagRequest!=4)) //rdn		??????
 			 //			{
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

							embMsgRequest->SetAddrI(aS);  //we are saurce
							embMsgRequest->SetAddrS(aR);  //as nede set te reeceiver
							embMsgRequest->SetAddrR(aI);  // as reseiver set source this request

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
               
//160603		tBuffRS485.Add(*embMsgRequest);   //send to edik request - wrong - need ti rs485e!!!

          tBuffRS485E.Add(*embMsgRequest);  //160603
//  #ifdef DEBUG_485E
//  printfp("\n\r send rs485e");
//  #endif

//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 			  //			}	 //!= 3
           
           
           
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
#include stack_commands_odu.c       //232

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

			  //		if(flagRequest == 1) 
			//		{
			   //		 printf("\n\r.................1");
//for(long tst = 0; tst < 100; tst++)	   //t100524
//{	   //t100524	

       //            txusart++;
       //       printfpd("   %d", txusart);

	  			 
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
				//	}	//  == 1



 	}
	else	//not self addr
  	{
  		if(flagRequest == 1) 
  		{
	 

					 		tBuffEmbMsgEast.Add(embMsg232);
		 //transit not need need eth_transit			 		tBuffEmbMsgWest.Add(embMsg232);
    #ifdef ETH_TRANZIT   
  //eth_transit is need only for modem channel!!!!                   tBuffEmbMsgEthAll.Add(embMsg232);
    #endif                  
							unEmb2NetStat.emb2NetStat.selfPacketSend++;

							 embMsg232.Init();  //17.10.2008
                      flagRequest = 0;
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


 #ifdef DEBUG_485E
			 	  	printfpd(".%X", byte);        //ok!!!
#endif               
          
			     if(embMsg485E.IsEnd()) 
			     
			       {
                
   #ifdef DEBUG_485E
			 	  	printfp("\n\r");
#endif                 
                
                
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
               
//#ifdef CHECK_CRC           
//       if(embMsg485E.ChkCRC())
//         {
//       #else       
       if(1)
       {
//#endif       
			  
		           

					if(embMsg485E.AddrS()==embMsg485E.AddrR())
					{
               
   #ifdef DEBUG_485E
			 	  	printfp("\n\r embMsg485E.AddrS()==embMsg485E.AddrR()");
#endif                 
               

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
//___________________________________________________________________________________




					   //	  embMsg485E.Init(); //1021
				 	    embMsg485E.Init(); //090430
			   	} //s == r!
				else 		//t1021
					if(embMsg485E.AddrR()!=embMsg485E.AddrS())
					{
               
#ifdef DEBUG_485E
			 	  	printfp("\n\r embMsg485E.AddrR()!=embMsg485E.AddrS()");
#endif     
						if(embMsg485E.AddrS()==SelfID())
						{
#ifdef DEBUG_485E
			 	  	printfp("\n\rembMsg485E.AddrS()==SelfID()");
#endif     
                  
                  

						// ->>	// O?aiceoii ioaao a eeie?
							if(embMsg485E.TOM() & 0x01)
							{
                     
#ifdef DEBUG_485E
			 	  	printfp("\n\rmbMsg485E.TOM() & 0x01");
#endif                         
								aI = embMsg485E.AddrI();
								aS = embMsg485E.AddrS();
								aR = embMsg485E.AddrR();
								embMsg485E.SetAddrI(aS);
								embMsg485E.SetAddrS(aR);
								embMsg485E.SetAddrR(aI);
                        
                        
                        
                        
                        
								tBuffEmbMsgEast.Add(embMsg485E);   //<<<<<<<<<<<<<<<<<<<<<<
                        
					  //			tBuffEmbMsgWest.Add(embMsg485E);
 //   #ifdef ETH_TRANZIT   
 //  hier is not need eth_transit                   tBuffEmbMsgEthAll.Add(embMsg485E);
 //   #endif                       
                        
                        
                        
						unEmb2NetStat.emb2NetStat.selfPacketSend++;	
				 	   embMsg485E.Init(); //090430				
							}
                     
                     
                     
       #ifdef PROG_ODU4                 
                     
							else
							{
								// ->>	// Iieo?eee cai?in ec Ethernet
                        
#ifdef DEBUG_485E
			 	  	printfp("\n\rflagRequest=4");
#endif                               
	 								flagRequest=4;
								embMsg485E.SetRS485();
								embMsgRequest = &embMsg485E;
							}
           
       #endif //PROG_ODU4              
                     
						}  //s != self
					}	//r != S
               }   //crc
               else
               { 
               embMsg485E.Init();
            } 
				  
 	}  //embrs485E.isend
   
#ifdef PROG_ODU4  
            
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
            
 #ifdef DEBUG_485E
			 	  	printfp("\n\rembMsgRequest->AddrS()==SelfID()");
#endif  
            

			//	   printf("p8");

					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
               //____________________tuts
           //    embMsgAns.SetRS485();
			  //				aI = embMsgRequest->AddrI();
			  //				if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
			  //				else aS = SelfID();
			  //				aR = embMsgRequest->AddrR();
			  //		 		embMsgAns.SetAddrI(aS);	 //t
			  //		 		embMsgAns.SetAddrS(aI);	 //t
			  //		 		embMsgAns.SetAddrR(aR);	 //t

               
               //___________________tuts
               
               
				   //____________________________________________________________________________________RDN >>
 							embMsgAns.SetRS485();
                     
                     
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aS);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aR);
                     
                     
                     
                     
                     
                     
                     
			//160616		      flagRequest = 0;	 //t	   //new! 21.02.2008

					}
					else //no RS485
					{
               
       #ifdef DEBUG_485E
			 	  	printfp("\n\rno RS485");
#endif          
               
               
#ifndef	ALL_ADDR
				 		embMsgAns.SetAddrI(SelfID());
#else
				//		  printf("f = %d", flagRequest);

				 embMsgAns.SetAddrI(embMsgRequest->AddrS());  //090427
#endif //	ALL_ADDR

			 	embMsgAns.SetAddrS(embMsgRequest->AddrI());	
			 					
					}
			//			printf("\n\r     embMsgRequest->Type:%d ",embMsgRequest->Type());
#include stack_commands_odu.c     //rBuffEmbMsgE
   
					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

						 
	if(flagRequest == 4) 
			   	{ 
			  //	 printf("->4");
   #ifdef DEBUG_485E
			 	  	printfp("\n\rflagRequest==4");
#endif  

						   embRS485.TransE(0x55);
		  				   embRS485.TransE(0xAA);
#ifdef DEBUG_485E
                     
						   printfp("\n\rans>");
#endif                     

		  				for(i=0; i<embMsgAns.FullSize(); i++) 
						{
#ifdef DEBUG_485E
                  
						  printfpd(".%0X",	embMsgAns.body[i]);
                    
#endif                    

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
                  
#ifdef DEBUG_485E
                     
						   printfp("\n\r");
#endif                         
					 //	embRS485.EmptyReceiveE();

			 			  embRS485.Trans_RDN(embMsgAns.AddrS());
                    
                   embRS485.EmptyReceiveE();
 

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
   #endif //PROG_ODU4
//++++++++++++++++++++++++++++++++++++++++++++++++++++p1 

//++++++++++++++++++++++++++++++++++++++++++++++++++++p2  


   //?????????? what is it ???????!!!!!!!!!!!!!!!!!!!!!!!!!

     //		while(embRS485.UsedReceive())
   //		if(embRS485.UsedReceive())	//100113
	//		{
	  //			byte = embRS485.Receive();
            
            /*
            
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
      
      */
	//		} //embrs485 usedReceive
       /*
 if(embMsg485.IsEnd()) 
				{
#ifdef CHECK_CRC           
       if(embMsg485.ChkCRC())
         {
       #else       
       if(1)
       {
#endif                 
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
               } //crc
               else
               { 
                               embMsg485.Init();
            } 
               
				}  //embrs485.isend

          */
         /*
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
		tBuffRS485.Add(*embMsgRequest);

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
#include stack_commands_odu.c   //485
      
      
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

*/  


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//#ifndef ETH_TRANZIT	  //090430
				if(rBuffEmbMsg.Used())
				{
//printEthLongHex(4); 
//#ifdef ETH_DEBUG_ENABLED
//	  printEthStringAdd(0,0);
//	  printEthStringAdd(1,1);
//	  printEthStringAdd(2,0);
//#endif

         //   printf("e");
         
         
         
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
				//	printf("'");
					rBuffEmbMsg.Get(embMsgA);
               
               
      //    #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_2 ");
       //   #endif
       
               
               
//printEthLongHex(embMsgA.AddrS());               
//______________________________________________  
//_______________________________________________               
  /*             
#ifndef ANSWER_OLWAIS
			 //110729		 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
                if(1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	// 110729	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485());
#endif //ANSWER_OLWAIS

				 //	   printf(" %02X", embMsgA.TOM());
             
  //________________________________________________________________
  
  				  embMsgRequest = &embMsgA;
					flagRequest=1;
				}
    			}
         
	  	if(flagRequest) //embMsgRequest->IsEnd())
			{
	   //		 printf("\n\r flagRequest = %d", flagRequest);

	   //		printf("\n\r> %04X ", embMsgRequest->AddrS());
#ifndef ALL_ADDR
//			   if(1) //100524


		if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))  //we are node
#else
		if(1) //090427
#endif //ALL_ADDR
			// &&(embMsgRequest->TOM()|0x01))
		{

 					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) //need resend to rs485 ?
					{
					//t	if(flagRequest!=3)
					
							aI = embMsgRequest->AddrI();
                     
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
                     
                     
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);  //we are saurce
							embMsgRequest->SetAddrS(aR);  //as nede set te reeceiver
							embMsgRequest->SetAddrR(aI);  // as reseiver set source this request

          tBuffRS485E.Add(*embMsgRequest);  //160603
           
				    flagRequest = 0;	 //t	   //new! 21.02.2008

					}
             }
        }
          */
  //_________________________________________________________________           
             
             
             

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				// 	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				   	 //	 printf(" p3");

				   	  		if(embMsgA.AddrS()==SelfID())//we are node : send to
					   //	   if(1) //090427
							{  
					  	// 	 printf(" p4");
//______________________________________________________________________
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
     //   #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_3 ");
      //    #endif
					  	

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
                     
                     
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                /*
 	aI = embMsgRequest->AddrI();
                     
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
                     
                     
							aR = embMsgRequest->AddrR();

							embMsgRequest->SetAddrI(aS);  //we are s0urce
							embMsgRequest->SetAddrS(aR);  //as nede set te reeceiver
							embMsgRequest->SetAddrR(aI);  // as re

                */
 
 
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>                    
                     
                     
                     
                     

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
               
 /*              
#ifndef  RS485_MSG_BUFF

							embRS485.Trans(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.Trans(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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
//						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
#else  //	 RS485_MSG_BUFF
 */
 //160603		tBuffRS485.Add(*embMsgRequest);     // ? may be rs485E!!!!!!!
 
 		tBuffRS485E.Add(*embMsgRequest);     // 160603 ? may be rs485E!!!!!!!
      
      
//#endif	//   RS485_MSG_BUFF


//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
                  
       //           #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_4 ");
      //    #endif
  
                  
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
#include stack_commands_odu.c // rBuffEmbMsg

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

			 					
 //________________________________________________________________________________________RDN


				}
            
		  //		else	//not self addr
		  //		{
						//  			else
	  	//   		embMsg232.Init();
 	  //	160603		}	   //not self addr
  //============================================================================================		
			//	if(flagRequest == 2) 
			//	{
    //        printEthLongHex(5);
#ifdef DEBUG_TRANZIT
	       txtransb++;
			 printfpd(" t: %d \n\r", txtransb);
#endif            
            
		  		  		tBuffEmbMsgEast.Add(embMsgAns);
	  //transit not need			  		tBuffEmbMsgWest.Add(embMsgAns);
     
  // #ifdef ETH_TRANZIT   
       //               tBuffEmbMsgEthAll.Add(embMsgAns);
   // #endif         
   //  need add eth_tranzit buffer
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
			 //	}	// == 2
            
            
       //    }    //not sel addr 160603
            
//================================================================================================
 //============================================================================================		
			 //================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//#endif // no eth_tranzit



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef ETH_TRANZIT	  

				if(rBuffEmbMsgE.Used())
				{
//printEthLongHex(4); 
//#ifdef ETH_DEBUG_ENABLED
//	  printEthStringAdd(0,0);
//	  printEthStringAdd(1,1);
//	  printEthStringAdd(2,0);
//#endif

         //   printf("e");
         
         
         
					EmbMsg embMsgA;
					 embMsgA.Init();	//my
				//	printf("'");
					rBuffEmbMsgE.Get(embMsgA);
               
               
      //    #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_2 ");
       //   #endif
       
               
               
//printEthLongHex(embMsgA.AddrS());               
//______________________________________________  
//_______________________________________________               
               
#ifndef ANSWER_OLWAIS
			 //110729		 if(buff_cashe_request.compare((unsigned long)embMsgA.body[1], (unsigned long)embMsgA.AddrS(), (unsigned long)embMsgA.AddrI(), (unsigned long)embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485()) != 1)
                if(1)
#else  //ANSWER_OLWAIS
   			   	  	 if(1)
#endif //ANSWER_OLWAIS
   			   		{
#ifndef ANSWER_OLWAIS
   	   	// 110729	  	  	buff_cashe_request.add(embMsgA.body[1], embMsgA.AddrS(), embMsgA.AddrI(), embMsgA.AddrR(), (unsigned long)embMsgA.IsRS485());
#endif //ANSWER_OLWAIS

				 //	   printf(" %02X", embMsgA.TOM());

				 	if(embMsgA.TOM()&0x01)
				//	if(1)	//t
					{
				// 	 printf(" p2");

						if(embMsgA.TOM()&0x20)
						{
				   	 //	 printf(" p3");

				   	  		if(embMsgA.AddrS()==SelfID())//we are node : send to
					   //	   if(1) //090427
							{  
					  	// 	 printf(" p4");
//______________________________________________________________________
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
     //   #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_3 ");
      //    #endif
					  	

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
               
 /*              
#ifndef  RS485_MSG_BUFF

							embRS485.Trans(0x55);	  //EC - RDN!!! in all

					 //		 printf("\n\r###55");

							embRS485.Trans(0xAA);
					 	  //		 printf(".AA");
					  	 //		 printf("\n\r");


							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
					 	  //	   printf(" %02X",	embMsgRequest->body[i]);
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
//						   	embRS485.Trans_RDN(embMsgRequest->AddrS());
#else  //	 RS485_MSG_BUFF
 */
 //160603		tBuffRS485.Add(*embMsgRequest);     // ? may be rs485E!!!!!!!
 
 		tBuffRS485E.Add(*embMsgRequest);     // 160603 ? may be rs485E!!!!!!!
      
      
//#endif	//   RS485_MSG_BUFF


//  	 printf("\n\rCRC : %X CalcCRC : % X", embMsgRequest->CRC(), embMsgRequest->CalcCRC());


					 //	  }
					//    }

			   	//t1022    my_int_enable();   //t

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,data for tuts
//____________________________________________________________________________________RDN  <<
 						}	 //!= 3
                  
       //           #ifdef DEBUG_TRANZIT
      //         printfp(" D_T_4 ");
      //    #endif
  
                  
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
#include stack_commands_odu.c // rBuffEmbMsg

					embMsgAns.SetCycle(cycle++);
				 //	 printf(",%1X",flagRequest);
					embMsgAns.CalcCRC();

  				  //	printEthLongHex(flagRequest);	 //t

			 					
 //________________________________________________________________________________________RDN


				}
            
		  //		else	//not self addr
		  //		{
						//  			else
	  	//   		embMsg232.Init();
 	  //	160603		}	   //not self addr
  //============================================================================================		
			//	if(flagRequest == 2) 
			//	{
    //        printEthLongHex(5);
#ifdef DEBUG_TRANZIT
	       txtransb++;
			 printfpd(" t: %d \n\r", txtransb);
#endif            
            
		  		 // 		tBuffEmbMsgEast.Add(embMsgAns);
	  //transit not need			  		tBuffEmbMsgWest.Add(embMsgAns);
     
//   #ifdef ETH_TRANZIT   
                      tBuffEmbMsgEthAll.Add(embMsgAns);
  //  #endif         
   //  need add eth_tranzit buffer
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
			 //	}	// == 2
            
            
       //    }    //not sel addr 160603
            
//================================================================================================
 //============================================================================================		
			 //================================================================================================

				flagRequest = 0;
				embMsgRequest = NULL;
			}  //have flagrequest not zero

//#endif // no eth_tranzit


 #endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



      
  // hier comment    
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    ANSWER   ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



