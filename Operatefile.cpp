extern "C" void OperateFile()
{
//printf("\n\r Operate File");
//_________________________for tftp loader
 _ip_address server;
  char_ptr filename;
//_________________________for flash writer
  unsigned long addr_dest, operation;
  unsigned int addr_src;
  unsigned int size;
  signed char errorw = 1;

#ifdef PROG_PU_MSAT
    unsigned int size1;
	   AT91RM9200_PIO_REG_STRUCT_PTR pio_ptrb;

#endif


    char bufstop[] = "1234567890";
  char * stopstring;
  uint_32 keep;
  stopstring = &bufstop[0];
  #define BUFFNAMESIZE (50)
  #define ENABLED_BUFFNAMESIZE (8)

  char BuffName[BUFFNAMESIZE]; 
  #define BUFFSIZESIZE (9)
  char BuffSize[BUFFSIZESIZE];
   uint_32 cnt, getpoint, error;
  #define IPADDRSIZE (9)

  // my_int_disable_usart0();
//  usart0_connecting (0); //disconnect

  
 //for (int i = 0; i < TFTP_BUFFER_SIZE; i++)
// {
  // TFTP_Buffer[i] = 0;
 //}
 //t server  =  (_ip_address)0x9B9B9B9D;
  getpoint = 0; 
  server = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);
  getpoint = (uint_32)IPADDRSIZE;
  for(cnt = 0; cnt < (BUFFNAMESIZE - 1); cnt++)
  {
	 if(FileUpdate.Value[cnt + getpoint] == '-') break;
	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
	  else {BuffName[cnt] =  FileUpdate.Value[cnt + getpoint];}
  }
  if(cnt > (ENABLED_BUFFNAMESIZE + 2)) //have symbols "-" 
  {
 // my_printf((unsigned char)cnt);
  return; //tftp do not work witch long names
  }

  BuffName[cnt] =  '\0';
 // filename = "hello7.bin";
  filename = &BuffName[0];
  getpoint += (cnt + 1); 

  for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
	// if(FileUpdate.Value[cnt + getpoint] == '-') break;
   //	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
   //	  else {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
   //	  }
  }
    BuffSize[cnt] =  '\0';

   size =  strtoll(&BuffSize[0], &stopstring,10);

#ifdef PROG_PU_MSAT
    size1 = XilSizeToDownloadD;
	 pio_ptrb =  (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

#endif

  if(size > TFTP_BUFFER_SIZE)  size = TFTP_BUFFER_SIZE;
 
  getpoint += (cnt + 1);
   for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
	// if(FileUpdate.Value[cnt + getpoint] == '-') break;
   //	  if(FileUpdate.Value[cnt + getpoint] == '+'){	BuffName[cnt] = '.';  }
   //	  else {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
   //	  }
  }
    BuffSize[cnt] =  '\0';

   addr_dest =  strtoll(&BuffSize[0], &stopstring,16);

   getpoint += (BUFFSIZESIZE);

   operation = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);

 
  addr_src = (unsigned int)&TFTP_Buffer[0];
   //need get off watch dog.
 //   RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"hello7.bin", (uchar_ptr)&TFTP_Buffer[0]);
  usart_command_eth_on();
    
   UsedExp.State.Reg1.bit.UCDE = 0; //usart not can now disable ethernet
   keep = (uint_32)SBuffersState.Value;
   keep |= (uint_32)TFTP_PROCEED;
    keep &= ~((uint_32)FILE_WRITE_OK);
   SBuffersState.Value = (float64)keep;

 //	 my_int_disable_irq0();


#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	
		if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rcheck flash ");
      OperateBuffers_usart0t();

#endif   
	    pio_ptrb->CODR = 1<<12; //get down line prog for xilinx
		delay_mcs(1000);

        errorw = (signed char)check_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1); //90 : without header
     if(errorw) 
     {
#ifdef TEST_HANGING      
      printfp("\n\rreturn to error flash ");
      OperateBuffers_usart0t();

#endif   

	  pio_ptrb->SODR = 1<<12; //get up line prog for xilinx

	 
     return;
	 }
		}
#endif
#endif


   
   error = RTCS_load_TFTP_BIN(server,filename, (uchar_ptr)&TFTP_Buffer[0]);
   // wd_reset();

   UsedExp.State.Reg1.bit.UCDE = 1; //now usart can disable ethernet
//ok  RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,"hello7.bin", (uchar_ptr)&TFTP_Buffer[0]);	 //t
//RTCS_load_TFTP_BIN((_ip_address)0x9B9B9B9D,filename, (uchar_ptr)&TFTP_Buffer[0]);	 //t
//  delay_mcs(40000);

// printf("\n\r1");

  if(error)
  {
  	 keep &= ~((uint_32)TFTP_PROCEED);
     SBuffersState.Value = (float64)keep;
     return; //to not write bad loading
   }
//  printf("\n\r2");
    // if((addr_dest < 0xC0030000) ||  ((size + addr_dest) >= ID_ADDRESS)) return;
	if(operation == 1l)	  //write file
	{
//printf("\n\r2a");

	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t
//#endif


#ifdef PROG_PU_MSAT

if(addr_dest == (XilFileDataAddressD - 0x20))
		{
       addr_dest = XilFileDataAddressD2 - 0x20;		 //need check addresses of configfiles
      printfp("\n\rChange address ");
		 }
#endif

#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	

if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rInvertBitOrdering ");
      OperateBuffers_usart0t();

#endif      
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	  size = 90; // header only
  	  addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }
#endif
#endif

#ifdef PROG_MF20
if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{
 	     errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
		 return;
		}
#endif

//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif




#ifdef PROG_PU_MSAT
#ifndef MAKET_PLATA	
		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{

#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

#endif   
//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<12; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
            StartLoadAll();
		    wd_reset();
   //ok		  TestWriteFlash2();
		}

#endif
#endif
	   /* this maked in operation == 5
#ifdef PROG_BMDN

		wd_reset();
 	 //	delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest < (CFG_DATAFLASH_LOGIC_ADDR_CS1X))
		{

//#ifdef TEST_HANGING      
      printfp("\n\rstart write ");
      OperateBuffers_usart0t();

//#endif   
//write to second flash local addr = 0;
//___________________________________________try write from second try
 //       errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 //		printfpd("\n\r error1 = %d", errorw);
 //		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
        errorw = (signed char)write_dataflashx (CFG_DATAFLASH_LOGIC_ADDR_CS0X + VER_OFFSET, (unsigned int)&TFTP_Buffer[0x60],  size); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);

	    wd_reset();
   //ok		  TestWriteFlash2();

	   errorw = 0; // do not need write this in base flash
		}


#endif
	 */


	delay_mcs(2000000);

	 if(errorw == (signed char)1)
	 {
  //	 printfp("\n\r write name");

     write_dataflash (addr_dest, addr_src,  size);
	 }
//#ifdef PROG_PU_MSAT
//}
//#endif



  //	  wd_reset();
//printf("\n\r4");
  	   delay_mcs(100);


	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
	else if(operation == 2l)   //run file
	{
	  usart_select(0); //debug uart on
	  my_int_disable();
	  wd_deinit();
	  _arm920t_dcache_disable();
	  _arm920t_icache_disable();

 	  Jump(&TFTP_Buffer[0]);
	}
	else if(operation == 3l)   //programm pult
	{
#ifdef PROGRAMM_PULT
	 ProgrammPultTFTP();
#endif //PROGRAMM_PULT 
	}
else if(operation == 4l)   //programm pult
	{
#ifdef LOAD_EXT_MODEM
	 unsigned char * src =  (uchar_ptr)&TFTP_Buffer[0];
	 unsigned char * dst =  (uchar_ptr)NVRAM_BASE;
	 for(cnt = 0; cnt < DATA_SIZE_EXTMODEM; cnt++)
	 {
	  * dst++ = *src++;
	 } 
	 LoadExtModem();
#endif // LOAD_EXT_MODEM
	}
else if(operation == 5l)   //programm flash through xilinx
	{
#ifdef XIL_FLASH
  //	      write_dataflashx (addr_dest, addr_src,  size);
//___________________________________________________________________
// if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start write xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif
  //now write all to have header in far flash   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);
//121018   write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0],  size);
 
//printfp("\n\r");
 for(unsigned long i = 0; i < 0x60; i++)
 {
  TFTP_Buffer1[i] =	TFTP_Buffer[i];
//  printfpd(" %02X",TFTP_Buffer[i]);
 } 
// */
//  	 delay_mcs(100000l);

 write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  // wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
  
  
 write_dataflashx (addr_dest,  (unsigned int)&TFTP_Buffer[0x60],  size);	//121018 - write only xilinx data(try use zero address for xilinx loading) 
//keep header in main flash 
 //  write_dataflash ((unsigned int)XilFileDataAddressD3, (unsigned int)&TFTP_Buffer[0],  0x60);
  	delay_mcs(10000l);
	/*
  for(i = 1; i < 0x61; i++)
 {
  TFTP_Buffer1[i] =	i;
  printfpd(" %02X",TFTP_Buffer[i]);
 } 
	 */
  		/*
     write_dataflash ((unsigned int)HEADER_XIL_FLASH_ADDRESS, (unsigned int)&TFTP_Buffer1[0],  0x60);
  //	  wd_reset();
//printf("\n\r4");
  	 delay_mcs(100000l);
	 */
	//  wd_reset();
  //	   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
  //	   {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
  //	   }
 //	FillDatat(0); //for test

 //	FillXilFileDatax(MODEM_QUANTITY);
	FillXilFileDatax(0);
  //	  wd_reset();

	// FillProgVersion();

//#ifdef PROG_BMDN
//	FillConfigFileVersion();
//#endif // PROG_BMDN


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;




//___________________________________________________________________


	  //in addr _dest - need make address of conkretycal xilinx
#endif
	}
	else if(operation == 6l)	  //compare file
	{
//printf("\n\r2a");

//120710	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t

#ifdef XIL_FLASH
#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start compare xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif

 if(addr_dest < CFG_DATAFLASH_LOGIC_ADDR_CS1X)
 {
#ifdef DEBUG_WRITE_XIL
  printfp("\n\r addr ok");
#endif


   CompareToFilex(size);
 }
#endif

//#endif
#ifdef PROG_PU_MSAT
if(addr_dest == (XilFileDataAddressD - 0x20))
		{
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();
	  InvertBitOrdering();	 //bit order need inverted.

	  wd_reset();
  	   size = 90; // header only
  		 addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }

#endif
//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif
 //    write_dataflash (addr_dest, addr_src,  size);
//#ifdef PROG_PU_MSAT
//}
//#endif
  //	  wd_reset();
//printf("\n\r4");
  	   delay_mcs(100);
#ifdef PROG_PU_MSAT

		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD - 0x20))
		{
//write to second flash local addr = 0;
//___________________________________________try write from second try
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 		delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	   CompareToFile(size1);

	
	    wd_reset();
   //ok		  TestWriteFlash2();
		}
#endif
	//  wd_reset();
	//   if(addr_dest == ((uint_32)XilFileDataAddressD - (uint_32)XILINXBEFORESIZE)) 
	 //  {
	   // printf("\r\n reload");
	   //	for(;;)
	   //	{
       //   wd_reset();
		//  m_load_xilinx3_ram((char)XILINXPG, 1);
  //		  m_load_xilinx3((char)XILINXPG, 1);
	   //	}
 	//   }

 //	 FillXilFileData((char)XILINXPG);
  //	  wd_reset();
#ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();

#ifdef PROG_BMDN
	FillConfigFileVersion();
#endif // PROG_BMDN

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}




}
