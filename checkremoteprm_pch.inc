//file: checkremoteprm_pch.cpp


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


  

#ifdef PROG_PRM_PCH_N

		if(!embMsg232.IsEnd())
		{
   //	 	printf("\n\r>>>>");
			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
 //	     	printf("_%02X", byte);	  //test
//__________________________________test
//			embRS485.Trans(byte);
//__________________________________test
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
			 //	  	printf(".%X", byte);
			} //embrs485 usedReceive
}  //!embrs232.isend

#endif PROG_PRM_PCH_N