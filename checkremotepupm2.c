//file: checkremoteprm_pch.cpp
 /*
extern "C" unsigned char NeedCellingCommandDataLength()
{
  if((current_command_type == 0x43)	||(Havefirstaddr && Havetwoaddr)) return 0;
 return 1;
}
  */
/*
#define NO_COMMAND_SSC2 (0)
 
#define COP1 (0x43) //1
#define COP2 (0x44) //2
#define COP3 (0x48) //3

#define CODE_NORMA     (0)
#define CODE_BAD_CRC   (0x1)
#define CODE_BAD_COP   (0x2)
#define CODE_NO_FORMAT (0x3)
 */

 /*
extern "C" void SetRunCommandPUPM2(unsigned char code)
{

} 
  */

//////////////////////////////////////////////////
	 //	i232=0;

		while(embRS232.UsedReceive())
		{
			byte = embRS232.Receive();
		 //	printf(" %02X", byte);

			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
	 //100811			embRS232.Trans(0x55);
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
				break;
 //090519			if(++i232>10) break;
		}


  

//121217 #ifdef PROG_PRM_PCH_N

		if(!embMsg232.IsEnd())
		{
   //	 	printf("\n\r>>>>");


			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
 	  //   	printfpd("_%02X", byte);	  //test
//__________________________________test
//			embRS485.Trans(byte);
//__________________________________test

#ifdef PROT_PUPM2
		OperateCommandPuPm2(&byte);
#else
			   	switch(byte)
				{
				case 0x55:
		   	  //	 embMsg485.ParseN();
				 
				if(embMsg485.ParseN())
				{
					for(long i = 0; i < embMsg485.GetAnsLen(); i++)
					{
					  embRS485.Trans(embMsg485.GetAns(i));
					}
				} 
				  
				embMsg485.Init();
				   
				break; 
		 //many commands in one 0x55 		case 0xAA: embMsg485.Init(); break;  
				case 0x5A: mode5A485=1; break;
				default:
					if(mode5A485) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A485=0;
					}
					else embMsg485.Add(byte);

				}

#endif //PROT_PUPM2


			 //	  	printf(".%X", byte);
			} //embrs485 usedReceive
}  //!embrs232.isend

//121217#endif PROG_PRM_PCH_N