   
		while(embSerialACT155.UsedUD1())
		{
			byte = embSerialACT155.GetUD1();
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
		 		printfp("\n\rans1<");
		 	}

		
				countUD1=0;
				for(i=0; i<32; i++)
				{

if(GetTestMode() == 0x50)
			{
			   printfp("_");
			   printfpd("%X",embMsg485_1.Body(i));

		  //				printf(".%0X",embMsgUD_1.Body(i));
			 }


						unStateRRL.stateRRL.ppu1_bytes[i] = embMsg485_1.Body(i);
				}
				for(i=0; i<16; i++)
				{
						unStateBMD155.stateBMD155.ppu1_bytes[i] = embMsg485_1.Body(i);
				}
				embMsg485_1.Init();
			}
		}

//  		if(time1-time1old > 30) // 10
 // if(0)	   //test
 		if(time1-time1old > UPDOWN_PERIOD) // 10
		{
			time1old = time1;
			countUD1++;
			if(embMsg485Request_1.IsReadyToSend())
			{
   //			printEthStringAdd(0,0);

				embSerialACT155.AddUD1(0xFF);
				embSerialACT155.AddUD1(0xAA);
				for(i=0; i<embMsg485Request_1.Length()+5; i++) 
				{
		//		printEthStringAdd(1,embMsg485Request_1.body[i]);

					switch(embMsg485Request_1.body[i])
					{
					case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
					case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
					case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
					case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
					default: embSerialACT155.AddUD1(embMsg485Request_1.body[i]);
					}
				}
				embMsg485Request_1.Init();
		  //		printEthStringAdd(2,0);

			}
			else
			{
				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(1);
				embMsg485Request_1.SetBody(0,0x00);
				embMsg485Request_1.CalcCRC();
 if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r1>");
		 	}

				embSerialACT155.AddUD1(0xFF);
				embSerialACT155.AddUD1(0xAA);
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
					case 0x5A: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x00); break;
					case 0x55: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x01); break;
					case 0xA5: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x02); break;
					case 0xAA: embSerialACT155.AddUD1(0x5A); embSerialACT155.AddUD1(0x03); break;
					default: embSerialACT155.AddUD1(embMsg485Request_1.body[i]);
					}


				}
				embMsg485Request_1.Init();
			}
		}

		if(countUD1 > 4) 
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
		}
////////////////////////////////////////////////
		while(embSerialACT155.UsedUD2())
		{
			byte = embSerialACT155.GetUD2();
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
				countUD2=0;
				for(i=0; i<32; i++)
				{
					unStateRRL.stateRRL.ppu2_bytes[i] = embMsg485_2.Body(i);
				}
				for(i=0; i<16; i++)
				{
					unStateBMD155.stateBMD155.ppu2_bytes[i] = embMsg485_2.Body(i);
				}
				embMsg485_2.Init(); 
			}
		}
	 //	if(time1-time2old>10) // 10
 //  if(0)  //test
  // 		if(time1-time2old > 30) //port
		if(time1-time2old > UPDOWN_PERIOD) //port
		{
			time2old = time1;
			countUD2++;
			if(embMsg485Request_2.IsReadyToSend())
			{
				embSerialACT155.AddUD2(0xFF);
				embSerialACT155.AddUD2(0xAA);
				for(i=0; i<embMsg485Request_2.Length()+5; i++) 
				{
					switch(embMsg485Request_2.body[i])
					{
					case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
					case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
					case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
					case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
					default: embSerialACT155.AddUD2(embMsg485Request_2.body[i]);
					}
				}
				embMsg485Request_2.Init();
			}
			else
			{
				embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(1);
				embMsg485Request_2.SetBody(0,0x00);
				embMsg485Request_2.CalcCRC();

				embSerialACT155.AddUD2(0xFF);
				embSerialACT155.AddUD2(0xAA);
				for(i=0; i<embMsg485Request_2.Length()+3; i++) 
				{
					switch(embMsg485Request_2.body[i])
					{
					case 0x5A: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x00); break;
					case 0x55: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x01); break;
					case 0xA5: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x02); break;
					case 0xAA: embSerialACT155.AddUD2(0x5A); embSerialACT155.AddUD2(0x03); break;
					default: embSerialACT155.AddUD2(embMsg485Request_2.body[i]);
					}
				}
				embMsg485Request_2.Init();
			}
		}

		if(countUD2>4) 
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
		}

