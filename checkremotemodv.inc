//file: checkremotemod.cpp


//////////////////////////////////////////////////
		i232=0;		//090629

/* 101115 temporary 
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

 */


//_______________________________________________________

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
   //        printfp("\n\r");
   //        printfp("_");
   //        printfpd("%X",embMsg485.body[0]);
    //                printfp("_");
    //           printfpd("%X",embMsg485.body[1]);
    //                     printfp("_");
    //           printfpd("%X",embMsg485.body[2]);
    //      printfp("_");
    //           printfpd("%X",embMsg485.body[3]);
               


           
           if((embMsg485.Addr() > DEVCONFIG_QUANTITY) || (!embMsg485.Addr())) break;
       if(GetTestMode() == 0x50)
{
     printfp("\n\r");
}     
           cur_ans_pointer = GetDevPointer(embMsg485.Addr());
           if(cur_ans_pointer != BAD_POINTER)
            {
  //      if(GetTestMode() == 0x50)
  //    {
  //            printfp("\n\rst1");
  //    }        
  
             devans[embMsg485.Addr() - 1] = 0;
             devstate[embMsg485.Addr() - 1] = 1; 
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[embMsg485.Addr() - 1].byte[i] = embMsg485.Body(i);  //addr from 1 to 16
       if(GetTestMode() == 0x50)
      {
                printfp("_");
               printfpd("%X",embMsg485.body[i]);
      }               
            }
           
            } 
         
         
		 /*	  
		  	  if(embMsg485.Addr() == RRL_ADDR1)
	 		  	{
				received1++;
			  //	  ans1=0;
		  	 		for(i=0; i<16; i++)
			   		{
					  
						unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsg485.Body(i);
						unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485.Body(i);
//____________________________________________________________	
 					
				//	  	if(i == 0)
				//	  	{
				//	  	 printf("\n\r> .%02X",embMsg485.Body(i) );
				  //	  	}
					 //	else
					 //	{
				 //		  printf(".%02X",embMsg485.Body(i) );
					 //	}
  						
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
   			   			 
	//					if(i == 0)
	 //				  	{
				   //	  	 printf("\n\r> .%02X",embMsg485.Body(i) );
		//			  	}
		  //				else
			 //			{
				   //		  printf(".%02X",embMsg485.Body(i) );
				//		}
						
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
            */
            
			}	//Is end
		} //while



	  //	if(time1-time1old > 10)   // 10
	  //	if(time1-time1old > 20)   // 10
	//  	if(time1-time1old > 30)   // 10
 //t090429  		if((time1-time1old > 30) && is_usart1_enabled()) //t
 
 
 
#ifndef USART1_TRY_PDC
   		if((time1-time1old485 > PUMV485_REQUEST_DELAY) && is_usart1_enabled() ) //t
#else
         if(time1-time1old485 > PUMV485_REQUEST_DELAY) //t

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

				time1old485 = time1;

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
				time1old485 = time1;
				ss++;
  //          SendTraceRequest();
            cur_req_quantity = GetDevQuantity();
            if(cur_req_quantity)   //not zero
            {
               if(cur_req_pointer >= cur_req_quantity) //pointer get from zero and quantity used from one
               {
                 cur_req_pointer = 0;
               }
            cur_req_addr = GetDevAddr(cur_req_pointer);
            if((cur_req_addr <= DEVCONFIG_QUANTITY) && cur_req_addr)    
            {
            devans[cur_req_addr - 1]++;   //addresses 1...16 devans 0 ... 15
               
            embMsg485Request.Init();
      //t      embMsg485Request.SetAddr(cur_req_addr);
            embMsg485Request.SetAddr(1);    //t
				embMsg485Request.SetLength(1);
				embMsg485Request.SetBody(0,0x00);
				embMsg485Request.CalcCRC();
            
		      embRS485.Trans(0xFF);
				embRS485.Trans(0xAA);
        if(GetTestMode() == 0x50)
{           
             printfp("\n\r");
 }    
     
     
              /*  ok
            embRS485.Trans(0x11); 
               printfp(".");
              printfpd("%X", 0x11);
            embRS485.Trans(1);
               printfp(".");
                  printfpd("%X", 1);
            embRS485.Trans(0);
               printfp(".");
                  printfpd("%X", 0);
             embRS485.Trans(3); 
                printfp(".");
                   printfpd("%X", 0x12);
                   */
             
				for(i=0; i<embMsg485Request.Length()+3; i++) 
				{
					switch(embMsg485Request.body[i])
					{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(embMsg485Request.body[i]);
       if(GetTestMode() == 0x50)
{

                printfp(".");
               printfpd("%X", embMsg485Request.body[i]);
}               
					}
				}
            
           } //correct addr

				embMsg485Request.Init();
            cur_req_pointer++;
              
            } 

            
/*            
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
			  	 
  //				embRS485.TransS(0xFF);
  //				embRS485.TransS(0xAA);
  //				for(i=0; i<embMsg485Request.Length()+3; i++) 
  //				{
  //					switch(embMsg485Request.body[i])
  //					{
  //					case 0x5A: embRS485.TransS(0x5A); embRS485.TransS(0x00); break;
  //					case 0x55: embRS485.TransS(0x5A); embRS485.TransS(0x01); break;
  //					case 0xA5: embRS485.TransS(0x5A); embRS485.TransS(0x02); break;
  //					case 0xAA: embRS485.TransS(0x5A); embRS485.TransS(0x03); break;
  //					default: embRS485.TransS(embMsg485Request.body[i]);
  //					}
  //				}
  //		  		 embRS485.TransSGO();
					
					
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
            */
            
			}
		}
      
////////////////////////////////////////////////
	 //	if(ans1>=200)
    
  for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
   if(devans[in] > MAX_NOT_ANSWERS_Q)
   {
      devstate[in] = 0;
     for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
   }         
  }

    
     /*
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
      
      */
/////////////////////////////////////////////////	UPP



//_______________________________________________________






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
 //t091224			if(++i232>10) break;	//090629
  //			if(++i232>20) break;	//090629
		}

//101115		if(!embMsg232.IsEnd())
//101115		{
/*	091224
//_______________________________________________________________232e
		while(embRS232.UsedReceiveE())
		{
 			byte = embRS232.ReceiveE();
	  		switch(byte)
			{
			case 0x55: 
			embMsg232E.Init();
//091218	embRS232.TransE(0x55);
//			embRS232.Trans_RDN(embMsgRequest->AddrS());		  //????????????????? neew keep before address of computer!!!
//			embRS232.Trans_RDN(COMP_DEF_MAC_END);	 //temporary zero mac: 001111000000
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
 091224 */
//_______________________________________________________________232e

   //	 	printf("\n\r>>>>");
	/* 101115
			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
			   	switch(byte)
				{
				case 0x55: embMsg485.Init(); // printf("\n\r++++");
				 break; 
				case 0xAA: embMsg485.Init();//  printf("\n\r++++");
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
			   //	  	printf("_%X", byte);

			  if(embMsg485.IsEnd()) 
		  				break;
			} //embrs485 usedReceive
  */
//_____________________________________________________________________RDN
  /* 101112
if(!embMsg485.IsEnd())
		{
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
	}  //	!embMsg485.IsEnd
	*/
//_____________________________________________________________________RDN
//______________________________________________________________________232e
//091224 }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

//101115}  //!embrs232.isend
