//file: checkremotemod.cpp


//////////////////////////////////////////////////
		i232=0;		//090629
      flagRequest = 0; //start find requests 110909


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
  //			{
	   //		printEthStringAdd(1,0x77);
	   //		printEthStringAdd(1,0x78);
	   //	 	printEthStringAdd(2,0);
      
#ifdef CHECK_CRC           
       if(embMsg232.ChkCRC())   
#else       
       if(1)
#endif   
    { 
    
#ifdef  DEBUG_TRANZIT      
      //    if( embMsg232.AddrS() == 0x6431) { mreqr++; printfpd(" \n\r s r= %d", mreqr);}
           if( embMsg232.AddrS() == 0x7766) { mreqr++; printfpd(" \n\r s r= %d", mreqr);}

          
#endif    
           rBuffEmbMsg232.Add(embMsg232);
				break;
			}
          
             else
             { 
                          embMsg232.Init();
              } 
               
 //t091224			if(++i232>10) break;	//090629
  //			if(++i232>20) break;	//090629
		}

		if(!embMsg232.IsEnd())
		{
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


#ifndef CHANGE_USART12
              /*
   //	 	printf("\n\r>>>>");
#ifndef  RS485_DISABLED
   
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
			} //embRS485 usedReceive

//_____________________________________________________________________RDN
if(!embMsg485.IsEnd())
#else
	while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
            RecvUstir(byte); 
         }


if(1)
#endif
		{
			while(embRS485.UsedReceiveE())
			{
				byte = embRS232S.ReceiveE();
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
			} //embRS232S usedReceive
	}  //	!embMsg485.IsEnd
               */
#else  //  CHANGE_USART12


   //	 	printf("\n\r>>>>");
//#ifndef  RS485_DISABLED
   
			while(embRS232S.UsedReceive())
			{
				byte = embRS232S.Receive();
#ifdef KSS_PRINT_LOG            
            printfpd(".%02X.", byte);
#endif            
			   	switch(byte)
				{
				case 0x55: embMsg232S.Init(); // printf("\n\r++++");
				 break; 
				case 0xAA: embMsg232S.Init();//  printf("\n\r++++");
				break; // Iaeao
					//			case 0xA5: break; // Ia?ea?ia caanu iao!
				case 0x5A: mode5AS=1; break;
				default:
					if(mode5AS) 
					{
						embMsg232S.Add(Modify5A(byte));
						mode5AS=0;
					}
					else embMsg232S.Add(byte);

				}
			   //	  	printf("_%X", byte);

			  if(embMsg232S.IsEnd()) 
		  				break;
			} //embRS232S usedReceive

//_____________________________________________________________________RDN
//if(!embMsg232S.IsEnd())
//#else  // RS485_DISABLED

      /*
	while(embRS232S.UsedReceive())
			{
				byte = embRS232S.Receive();
            RecvUstir(byte); 
         }

     */
   /*  
if(1)

#endif  // RS485_DISABLED
		{
			while(embRS232S.UsedReceiveE())
			{
				byte = embRS232S.ReceiveE();
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
                  
                  
			} //embRS232S usedReceive
         
	}  //	!embMsg485.IsEnd

       */
#endif // CHANGE_USART12   
//_____________________________________________________________________RDN
//______________________________________________________________________232e
//091224 }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

}  //!embrs232.isend
