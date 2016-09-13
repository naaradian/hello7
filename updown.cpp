//file updown.cpp

	while(embSerialACT155.UsedUD1(0))
		{
			byte = embSerialACT155.GetUD1(0);
	   //		printf("_%c",byte);
			switch(byte)
			{
				case 0xAA: embMsg485_1.Init(); stemp++; break; // Пакет
				case 0x5A: mode5AUp1=1; break;
				default:
					if(mode5AUp1) 
					{
						embMsg485_1.Add(Modify5A(byte));
						mode5AUp1=0;
					}
					else embMsg485_1.Add(byte);
			}
			if(embMsg485_1.IsEnd())
			{	
			
			if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1<");
		 	}
	
				countUD1=0;
				
			 crcud = 0;
			for(i=0; i<31; i++)
				{
				crcud += embMsg485_1.Body(i);
			    }
				crcud += 1;

  if(crcud == embMsg485_1.Body(31))
  {
	
				for(i=0; i<32; i++)
				{
						unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485_1.Body(i);
			if(GetTestMode() == 0x50)
			{
			   printfp("_");
			   printfpd("%X", embMsg485_1.Body(i));

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }

				}
				for(i=0; i<16; i++)
				{
						unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsg485_1.Body(i);
				}
//______________________________________________
		  //	if( !(embMsg485_1.Body(0xD))) //answer to request of state command
		  //	{
			 power1 = embMsg485_1.Body(0x1);
			 pdpower1 = embMsg485_1.Body(0x2);
		 //	 printfpd("\n\r1 : %d ", pdpower1);
			 trunk1.byte = embMsg485_1.Body(0x8);
		//	 printEthLongHex(0x10000+ (embMsg485_1.Body(0x9)<<8)+ embMsg485_1.Body(0xA));
	  //		 printEthLongHex(embMsg485_1.Body(0x8));
		  //	}
//_______________________________________________
}
else
{
	countUD1 = ALARM_LEVEL_UD; //alarm
}
				embMsg485_1.Init();
		   //		OperateTrunks();
			}


		}

 		if(time1-time1old > PERIOD_UP_DOWN) // 10
   //		if(time1-time1old > 100) // 10
		{
			time1old = time1;
			countUD1++;
  //130624	   		if(embMsg485Request_1.IsReadyToSend())
 //13.06.21			if(embMsg485Request_1.IsReadyToSend() && send_keeper1)
//130624			{
          if(tBuffEmbMsg485Request_1.Used() && send_keeper1)
			{
		//	printfp("\n\r________t1");
				EmbMsg485 embMsg485Request_1;
				embMsg485Request_1.Init();
				tBuffEmbMsg485Request_1.Get(embMsg485Request_1);

			send_keeper1 = 0;
   //			printEthStringAdd(0,0);
		if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1>");
		 	}

				embSerialACT155.AddUD1(0xFF,0);
				embSerialACT155.AddUD1(0xAA,0);
				for(i=0; i<embMsg485Request_1.Length()+5; i++) 
				{
					if(GetTestMode() == 0x50)
					{
			   			printfp(".");
			   			printfpd("%X",embMsg485Request_1.body[i]);
			 		}

		//		printEthStringAdd(1,embMsg485Request_1.body[i]);

					switch(embMsg485Request_1.body[i])
					{
					case 0x5A: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x00,0); break;
					case 0x55: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x01,0); break;
					case 0xA5: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x02,0); break;
					case 0xAA: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x03,0); break;
					default: embSerialACT155.AddUD1(embMsg485Request_1.body[i],0);
					}
				}
				 embSerialACT155.SetMaskTransUD1(0);


				embMsg485Request_1.Init();
		  //		printEthStringAdd(2,0);

			}
			else
			{
			send_keeper1 = 1;
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(1);
				embMsg485Request_1.SetBody(0,0x00);
				embMsg485Request_1.CalcCRC();
					if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1>");
		 	}


				embSerialACT155.AddUD1(0xFF,0);
				embSerialACT155.AddUD1(0xAA,0);
				for(i=0; i<embMsg485Request_1.Length()+3; i++) 
				{

if(GetTestMode() == 0x50)
			{
			   printfp(".");
			   printfpd("%X",embMsg485Request_1.body[i]);

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }

					switch(embMsg485Request_1.body[i])
					{
					case 0x5A: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x00,0); break;
					case 0x55: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x01,0); break;
					case 0xA5: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x02,0); break;
					case 0xAA: embSerialACT155.AddUD1(0x5A,0); embSerialACT155.AddUD1(0x03,0); break;
					default: embSerialACT155.AddUD1(embMsg485Request_1.body[i],0);
					}
				
				
				} //for
				 embSerialACT155.SetMaskTransUD1(0);
				embMsg485Request_1.Init();
		   //		 flag_trunk |= 1;
			}	//else
	//	} //time

   //		if(countUD1 > 4) 
		if(countUD1 > ALARM_LEVEL_UD) 
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu1_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu1_bytes[i] = 0;
			}
			unStateRRL.stateRRL.state = 0x00;
#ifdef O_POWER
			flag_enable_operate_power1 = 1;
#endif
		}

	} //time
////////////////////////////////////////////////
		while(embSerialACT155.UsedUD2(0))
		{
			byte = embSerialACT155.GetUD2(0);
	  //		printf(".%c",byte);

			switch(byte)
			{
				case 0xAA: embMsg485_2.Init(); stemp++; break; // Пакет
				case 0x5A: mode5AUp2=1; break;
				default:
					if(mode5AUp2) 
					{
						embMsg485_2.Add(Modify5A(byte));
						mode5AUp2=0;
					}
					else embMsg485_2.Add(byte);
			}
			if(embMsg485_2.IsEnd())
			{
				if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r2<");
		 	}
		
				countUD2=0;
	 

				crcud = 0;

				for(i=0; i<31; i++)
				{
				crcud += embMsg485_2.Body(i);
			    }
				crcud += 1;

  if(crcud == embMsg485_2.Body(31))
  {
  
				for(i=0; i<32; i++)
				{
	        if(GetTestMode() == 0x50)
			{
			   printfp("_");
			   printfpd("%X", embMsg485_2.Body(i));

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }


					unStateRRL.stateRRL.ppu2_bytes[i] = embMsg485_2.Body(i);
				}
				for(i=0; i<16; i++)
				{
					unStateBMD155.stateBMD155.ppu2_bytes[i] = embMsg485_2.Body(i);
				}
//__________________________________________________________________________
	 //	if( !(embMsg485_2.Body(0xD))) //answer to request of state command
	 //	{
 			power2 = embMsg485_2.Body(0x1);
			pdpower2 = embMsg485_2.Body(0x2);
	   //		 printfpd(" 2 : %d ", pdpower2);
 			trunk2.byte = embMsg485_2.Body(0x8);
   		//	printEthLongHex(0x20000+ (embMsg485_2.Body(0x9)<<8)+ embMsg485_2.Body(0xA));

	 //	}
//___________________________________________________________________________
  }	
  else
  {
	 countUD2 = ALARM_LEVEL_UD;
  }		
				embMsg485_2.Init(); 
			 //	OperateTrunks();
			//    flag_trunk |= 1;
			}
		}
	 //	if(time1-time2old>10) // 10

   		if(time1-time2old > PERIOD_UP_DOWN) //port
	  //	if(time1-time2old > 100) //port
		{
			time2old = time1;
			countUD2++;
 //130624		 	if(embMsg485Request_2.IsReadyToSend())
 //130621			if(embMsg485Request_2.IsReadyToSend() && send_keeper2)
//130624			{

    if(tBuffEmbMsg485Request_2.Used() && send_keeper2)
			{
		//	printfp("\n\r________t1");
				EmbMsg485 embMsg485Request_2;
				embMsg485Request_2.Init();
				tBuffEmbMsg485Request_2.Get(embMsg485Request_2);



			  send_keeper2 = 0;
						if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r2>");
		 	}

				embSerialACT155.AddUD2(0xFF,0);
				embSerialACT155.AddUD2(0xAA,0);
				for(i=0; i<embMsg485Request_2.Length()+5; i++) 
				{

			if(GetTestMode() == 0x50)
			 {
			   printfp(".");
			   printfpd("%X",embMsg485Request_2.body[i]);
     		 }

					switch(embMsg485Request_2.body[i])
					{
					case 0x5A: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x00,0); break;
					case 0x55: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x01,0); break;
					case 0xA5: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x02,0); break;
					case 0xAA: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x03,0); break;
					default: embSerialACT155.AddUD2(embMsg485Request_2.body[i],0);
					}
				}
				 embSerialACT155.SetMaskTransUD2(0);
				embMsg485Request_2.Init();
			}
			else
			{
			  send_keeper2 = 1;

				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(1);
				embMsg485Request_2.SetBody(0,0x00);
				embMsg485Request_2.CalcCRC();
				if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r2>");
		 	}

				embSerialACT155.AddUD2(0xFF,0);
				embSerialACT155.AddUD2(0xAA,0);
				for(i=0; i<embMsg485Request_2.Length()+3; i++) 
				{
			if(GetTestMode() == 0x50)
			 {
			   printfp(".");
			   printfpd("%X",embMsg485Request_2.body[i]);
     		 }

					switch(embMsg485Request_2.body[i])
					{
					case 0x5A: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x00,0); break;
					case 0x55: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x01,0); break;
					case 0xA5: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x02,0); break;
					case 0xAA: embSerialACT155.AddUD2(0x5A,0); embSerialACT155.AddUD2(0x03,0); break;
					default: embSerialACT155.AddUD2(embMsg485Request_2.body[i],0);
					}
				}
				 embSerialACT155.SetMaskTransUD2(0);
				embMsg485Request_2.Init();
			  //	   flag_trunk |= 2;

			}


	//	} //time

		if(countUD2>ALARM_LEVEL_UD) 
		{
			for(i=0; i<16; i++)
			{
				unStateBMD155.stateBMD155.ppu2_bytes[i] = 0;
			}
			for(i=0; i<32; i++)
			{
				unStateRRL.stateRRL.ppu2_bytes[i] = 0;
			}
			unStateRRL.stateRRL.state = 0x00;
#ifdef O_POWER
			flag_enable_operate_power2 = 1;
#endif

		}

	 //	if(flag_trunk > 2)	 //send requests of state for every trunk
	 //	{
	  //	  flag_trunk = 0;
//#ifndef PROG_MD310
		  OperateTrunks();
//#endif
	 //	}

	  } //time