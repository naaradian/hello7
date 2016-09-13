//trunks.cpp

extern "C" unsigned char CheckCurrentTrunk()
{
//printEthLongHex(8);
//printfp("\n\rCheckCur ");

 unsigned char ret = 1;

 if(!currenttrunk)
 {
   if((countUD1 > ALARM_LEVEL_UD) || (!trunk1.modetrunk.lock_pm) //|| (!trunk1.modetrunk.lock_pd) 
   			|| (!trunk1.modetrunk.onpd) || (power1 <= (unsigned char)POWER_ALARM))
			{
				cur_err++;
	 //			 printEthLongHex(0x100);

			  // ret = 0;
   			}
			else
			{
	 //		    printEthLongHex(0x200);

				cur_err = 0;
			}
 }
 else
 {
   if((countUD2 > ALARM_LEVEL_UD) || (!trunk2.modetrunk.lock_pm)//|| (!trunk2.modetrunk.lock_pd) 
   			|| (!trunk2.modetrunk.onpd) || (power2 <= (unsigned char)POWER_ALARM))
			{
				cur_err++;
		//		 printEthLongHex(0x300);

			  //  ret = 0;
   			}
			else
			{
				cur_err = 0;
		//		 printEthLongHex(0x400);

			}

 }
//printfpd("\n\rc:%d", ret);
//printfpd("\n\rtr :%d", currenttrunk);
 if(cur_err >= MAX_CUR_ERR)	ret = 0;
 return ret;
}

extern "C" unsigned char CheckNotCurrentTrunk()
{
//printEthLongHex(7);
//printfp("\n\rCheckNotCur ");
 unsigned char ret = 1;

 if(currenttrunk)
 {
   if( (trunk1.modetrunk.onpd) )
			{
			    ret = 0;
   			}
 }
 else
 {
   if((trunk2.modetrunk.onpd) )
			{
			    ret = 0;
   			}
 }
//printfpd("n:%d ", ret);

 return ret;
}


extern "C" unsigned char HaveEnoverTrunks()
{
//printEthLongHex(5);
//printfp("\n\rHaveEn ");
 unsigned char ret = 1;

 if(currenttrunk) //check for enover trunk
 {
// printEthLongHex(0x51);
   if((oldflag_ud1) || (!trunk1.modetrunk.lock_pm) //|| (!trunk1.modetrunk.lock_pd) 
   			)// || (power1 < POWER_TRESHOLD))
			{
			    ret = 0;
   			}
 }
 else
 {
//printfpd("o:%d ",oldflag_ud2);
//printfpd("pm:%d ", trunk2.modetrunk.lock_pm);
//printfpd("pw:%d ", power2);
 //hier  printEthLongHex(0x52);

   if((oldflag_ud2) || (!trunk2.modetrunk.lock_pm) //|| (!trunk2.modetrunk.lock_pd) 
   		   )   //	|| (power2 < POWER_TRESHOLD))
			{
			    ret = 0;
   			}
 }
//0 printEthLongHex(ret);
//printfpd("h:%d ", ret);
 return ret;
// printEthLongHex(4);
}
extern "C" void SetCurrentTrunk(unsigned char st)
{
//printEthLongHex(4);
//printfp("\n\rSetCur ");

if(!currenttrunk)
 {

				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
			  //	embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
				   /*
			 if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
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
				}
				embMsg485Request_1.Init();
				*/
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
		 //		embMsg485Request_2.SetReadyToSend();
		    tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
				/*
	 		if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
		 	}

				embSerialACT155.AddUD2(0xFF,0);
				embSerialACT155.AddUD2(0xAA,0);
				for(i=0; i<embMsg485Request_2.Length()+3; i++) 
				{
			if(GetTestMode() == 0x50)
			{
			   printfp(".");
			   printfpd("%X",embMsg485Request_2.body[i]);

		  //				printf(".%0X",embMsgUD_1.Body(i));
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
				embMsg485Request_2.Init();
				 */
}


}

extern "C" void SetNotCurrentTrunk(unsigned char st)
{
//printEthLongHex(3);
//printfp("\n\rSetNotCur ");
if(currenttrunk)
 {

				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
			//	embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
				/*
			 if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
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
				}
				embMsg485Request_1.Init();
				*/
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
			 //	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
				/*
	 		if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
		 	}

				embSerialACT155.AddUD2(0xFF,0);
				embSerialACT155.AddUD2(0xAA,0);
				for(i=0; i<embMsg485Request_2.Length()+3; i++) 
				{
			if(GetTestMode() == 0x50)
			{
			   printfp(".");
			   printfpd("%X",embMsg485Request_2.body[i]);

		  //				printf(".%0X",embMsgUD_1.Body(i));
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
				embMsg485Request_2.Init();
				 */
}


}


extern "C" void SetTrunk(unsigned char trunk, unsigned char st)
{
//printEthLongHex(10);
//printfp("\n\rSetNotCur ");
if(!trunk)
 {

				embMsg485Request_1.Init();
				embMsg485Request_1.SetAddr(0);// был 1 //addr485);
				embMsg485Request_1.SetLength(2);
				embMsg485Request_1.SetBody(0,3);
			    embMsg485Request_1.SetBody(1,st);
				embMsg485Request_1.CalcCRC();
		   //		embMsg485Request_1.SetReadyToSend();
				   tBuffEmbMsg485Request_1.Add(embMsg485Request_1);
				/*
			 if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
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
				}
				embMsg485Request_1.Init();
				*/
}
else   //trunc2
{
			   embMsg485Request_2.Init();
				embMsg485Request_2.SetAddr(0);// был 1 //addr485);
				embMsg485Request_2.SetLength(2);
				embMsg485Request_2.SetBody(0,3);
				embMsg485Request_2.SetBody(1,st);
				embMsg485Request_2.CalcCRC();
			 //	embMsg485Request_2.SetReadyToSend();
				   tBuffEmbMsg485Request_2.Add(embMsg485Request_2);
				/*
	 		if(GetTestMode() == 0x50)
			{
		 		printfp("\n\r>");
		 	}

				embSerialACT155.AddUD2(0xFF,0);
				embSerialACT155.AddUD2(0xAA,0);
				for(i=0; i<embMsg485Request_2.Length()+3; i++) 
				{
			if(GetTestMode() == 0x50)
			{
			   printfp(".");
			   printfpd("%X",embMsg485Request_2.body[i]);

		  //				printf(".%0X",embMsgUD_1.Body(i));
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
				embMsg485Request_2.Init();
				 */
}


}





extern "C" void ChangeCurrentTrunk()
{
//printEthLongHex(1);
//printfp("\n\rChangeCur ");

 SetCurrentTrunk(0); //get off
 if(!currenttrunk) {currenttrunk = 1;}
 else { currenttrunk = 0;  }
 SetCurrentTrunk(1);  //get on
}

extern "C" void OperateTrunks()
{
//   return; //for test
//printEthLongHex(2);
//printfp("\n\rOpTr ");

#ifdef PROG_MD310	//do not use one trunk mode
#ifndef PROG_BMDN6
  if(GetModForSS())
 {
	SetModForSS(0);
//printfp("\n\r________________________3");

 }
  return;
#endif
#endif


  if(GetModForSS())
 // if(1)
 {

   if(!CheckCurrentTrunk())
 {
  if(HaveEnoverTrunks())
  {
  	ChangeCurrentTrunk();
 //	printEthLongHex(10);
  }
 }

  if(!CheckNotCurrentTrunk())
 {
  SetNotCurrentTrunk(0);
 // printEthLongHex(11);
 }

 //printfp("\n\r________________________2");
 
  
 // return;
  } 
    else
  {
     if( (!trunk1.modetrunk.onpd) )
			{
//printEthLongHex(12);
//printfp("\n\r________________________0");
			    SetTrunk(0, 1);
   			}
     if( (!trunk2.modetrunk.onpd) )
			{
//printEthLongHex(13);
//printfp("\n\r________________________1");

			    SetTrunk(1, 1);
   			}
  }
}


