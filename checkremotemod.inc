//file: checkremotemod.cpp


//////////////////////////////////////////////////
		i232=0;		//090629


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

   //	 	printf("\n\r>>>>");
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

//_____________________________________________________________________RDN
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
//_____________________________________________________________________RDN
//______________________________________________________________________232e
//091224 }  //	!embMsg232.IsEnd
//______________________________________________________________________232e

}  //!embrs232.isend
