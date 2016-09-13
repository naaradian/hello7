extern "C" unsigned char OperateCommand(unsigned char * pData)
{
unsigned  char ret;
 ret = 0; 
unsigned char rch;// = * pData; 
switch(* pData)
{
case 0x55:       current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;
                 return;
case 0xA5:       current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;
                 return;   //added
case 0xAA:    embMsgSSC2N_Init();
              current_command_state = RECEIVE_COMMAND;
              current_command_data_counter = 0;
              current_command_counter = 1;
#ifdef TEST_PRINT_SPI     
              printfp("\n\r> start ");
               printfpd(" ,%X ", 0xAA); 
 printfpd("<c:%d>", current_command_counter);
               
#endif      
              return;
case 0x5A: mode5ASSC2=1; return;

default:
					if(mode5ASSC2) 
					{
						rch = (Modify5A(* pData));
						mode5ASSC2=0;
					}
					else rch = * pData;
               break;
}
  current_command_counter++;
#ifdef TEST_PRINT_SPI 
 printfpd(" ,%X ", rch); //110914
  printfpd("<c:%d>", current_command_counter);

#endif
embMsgSSC2N_Add(rch);
 if((current_command_counter == LENGTH_POS) &&  ( current_command_state == RECEIVE_COMMAND))
  {
     current_command_length = rch;
  }
 else 
 if((current_command_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
#ifndef PROG_PRM_PCH_SPI_XIL   
     if((((unsigned char)rch) == (MY_ADDRESS + (unsigned char)MASK_REQUEST))
#else 
     if((((unsigned char)rch) == (MY_ADDRESS_XIL + (unsigned char)MASK_REQUEST))
#endif     
     
     ||  (rch == (unsigned char)BRD_ADDRESS))
     {
      current_command_state = RUN_COMMAND;
       ret = 1;
            } 
        else
        {
#ifdef  IncEmbSerialSPI  
    SetLineDataSPIOffX();
    SetLineAlarmOffX();
#else  
#ifndef BACK_TO_SSC   
//    SetLineDataOffOff(); //setted  line data to zero
    SetLineAlarmOff(); //temporary - no alarms
#else
    SetLineDataSSC2Off();
    SetLineAlarmOff();
#endif    
#endif


      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
      }
  } 
 // else if((current_command_counter == COMMAND_POS) &&  (current_command_state == RUN_COMMAND))
  else if(current_command_counter == COMMAND_POS)
  {
     if(rch <= COMMANDS_QUANTITY)
     {

#ifdef TEST_PRINT_SPI
	   	 	printfpd("[command: %02X]",rch);
#endif
      current_command_type =  rch;   //120721
      }
      else{ /* Body */
          current_command_state = WAITING_COMMAND;

      current_command_type = NO_COMMAND_SSC2;
   } /* Endbody */
  } //counter
    else      if (current_command_state == RUN_COMMAND)
  {
   if((current_command_counter == CommandDataLength[current_command_type]))
  {
   current_command_crc =  rch;   //120720

   if(CheckSSC2CRC())
   {
   
#ifdef  IncEmbSerialSPI  
      SetLineAlarmToOneX();
       SetLineDataSPIToZeroX();
#else   
#ifndef BACK_TO_SSC   
    SetLineDataOffToZero(); //setted  line data to zero
    SetLineAlarmToOne(); //temporary - no alarms
#else
    SetLineDataSSC2ToZero();
    SetLineAlarmToOne();
#endif    
#endif    
    SetRunCommandSSC2(); //ok //hier only set to run - it is interrupt
#ifdef TEST_PRINT_SPI   
    printfp("(CRC Ok)");    
#endif    
#ifdef PRINT_DEBUG_CRC
	   	 	printfpd("calc crc: %02X", crc_glob);
	   	 	printfpd("<->packet crc:  %02X\n\r",  body_glob);
#endif
   }
   else
   {
       current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
    printfp("(CRC Bad)");
#endif   

#ifdef  IncEmbSerialSPI  
    SetLineDataSPIOffX();
    SetLineAlarmOffX();
#else  
#ifndef BACK_TO_SSC   
    SetLineAlarmOff(); //temporary - no alarms
#else
    SetLineDataSSC2Off();
    SetLineAlarmOff();
#endif    
#endif 
   }  //crc
 } //counter
  else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  {
      current_command_state = WAITING_COMMAND;
    current_command_counter = 0;
  }
  
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
            &&  (current_command_state == RUN_COMMAND))
   { 
    current_command_data[current_command_data_counter++] = rch;
  }
 } //120713
 return ret; 
}
