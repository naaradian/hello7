

extern "C" void CopyBuffers(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
 char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];

  for(unsigned i = 0; i < 90; i++)	 //need header only
 //  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
   *pBuff1++ = *pBuff++; // TFTP_Buffer1[i]  =  TFTP_Buffer[i];

 //  if(!(i % 16))
//   printfpd("\n\r %X >", i);
//   printfpd(" %02X", TFTP_Buffer[i]);

  }

  	//  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);
 	/*
    read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, TEST_DATA_SIZE, &TestR[0]);
   for( i = 0; i < TEST_DATA_SIZE; i++)
  {
  if(!(i % 16))
   printfpd("\n\r %X >", i);
   printfpd(" %02X", TestR[i]);
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
  }
   */
}

#define  TEST_SIZE (1000)
extern "C" void TestWriteFlash6(void)
{
    AT91RM9200_PIO_REG_STRUCT_PTR pio_ptrb;
	pio_ptrb =  (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);

 printfp("\n\rTestWriteFlash6");
   pio_ptrb->CODR = 1<<0; //temporary!!! set to zero

  // return;
 char Test[TEST_SIZE];
// char TestR[TEST_DATA_SIZE];

// unsigned long j = 0;
//  for(j = 0; j < END_ADDR; j += TEST_DATA_SIZE)
 for(int j = 0; j < TEST_SIZE; j++)
 {
	  Test[j]	= j;
 }
//  for(unsigned i = 0; i < XilSizeToDownloadD; i++)

  for(unsigned i = 0; i < 1000; i++)
  {
   TFTP_Buffer[i]  = 't';
  }

   for( i = 0; i < 100; i++)
//   for( i = 0; i < 10000; i++)
  {
   ToPdcTu0('.');
	   delay_mcs(10);
	   OperateBuffers_usart0t();

     }
	  pio_ptrb->CODR = 1<<0; //temporary!!! set to zero
   	   AT91F_DataflashInit();


  	  write_dataflash(CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_SIZE);

  //	  read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1 + (unsigned long)END_ADDR - TEST_DATA_SIZE , TEST_DATA_SIZE, &TestR[0]);
   read_dataflash(CFG_DATAFLASH_LOGIC_ADDR_CS1,TEST_SIZE, &TFTP_Buffer[0]);

 //  delay_mcs(100000);

 //  for( i = 0; i < XilSizeToDownloadD; i++)
   for( i = 0; i < TEST_SIZE; i++)
  {
   if(!(i % 256))
    {    OperateBuffers_usart0t();  wd_reset();
 //  delay_mcs(1000000);
   }


 //  printfpd("\n\r %X >", (i + j));
  // printfpd("X", TFTP_Buffer[i]);
//   OperateBuffers_usart0t();
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
 ToPdcTu0(TFTP_Buffer[i]);

  }
//   OperateBuffers_usart0t();
//   delay_mcs(10000);
   wd_reset();

// ToPdcTu0(TFTP_Buffer[i]);

 // }
// ToPdcTu0(TFTP_Buffer[i]);
//  pio_ptrb->SODR = 1<<0; //temporary!!! set to zero

}


extern "C" void InvertBitOrdering(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
// char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];
 unsigned char ByteBuff;
 unsigned char ByteBuff1;

  for(unsigned i = 0; i < XilSizeToDownloadD; i++)	 //need header only
 //  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
   ByteBuff = *pBuff; // TFTP_Buffer1[i]  =  TFTP_Buffer[i];
   ByteBuff1 = 0;
   if(ByteBuff & MASK_BIT_0)  (ByteBuff1 |= MASK_BIT_7);
   if(ByteBuff & MASK_BIT_1)  (ByteBuff1 |= MASK_BIT_6);
   if(ByteBuff & MASK_BIT_2)  (ByteBuff1 |= MASK_BIT_5);
   if(ByteBuff & MASK_BIT_3)  (ByteBuff1 |= MASK_BIT_4);
   if(ByteBuff & MASK_BIT_4)  (ByteBuff1 |= MASK_BIT_3);
   if(ByteBuff & MASK_BIT_5)  (ByteBuff1 |= MASK_BIT_2);
   if(ByteBuff & MASK_BIT_6)  (ByteBuff1 |= MASK_BIT_1);
   if(ByteBuff & MASK_BIT_7)  (ByteBuff1 |= MASK_BIT_0);
   *pBuff++ = ByteBuff1;
  
 //  if(!(i % 16))
//   printfpd("\n\r %X >", i);
//   printfpd(" %02X", TFTP_Buffer[i]);

  }

  	//  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);
 	/*
    read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, TEST_DATA_SIZE, &TestR[0]);
   for( i = 0; i < TEST_DATA_SIZE; i++)
  {
  if(!(i % 16))
   printfpd("\n\r %X >", i);
   printfpd(" %02X", TestR[i]);
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
  }
   */
}





extern "C" void OperateFile()
{
//printfp("\n\r Operate File");
#ifdef CF_PRINT
printfp("\n\r Operate File");
 OperateBuffers_usart0t();
#endif

//_________________________for tftp loader
 _ip_address server;
  char_ptr filename;
//_________________________for flash writer
  unsigned long addr_dest, operation;
  unsigned int addr_src;
  unsigned int size;
  signed char errorw = 1;
  unsigned i;

    unsigned int size1;//= XilSizeToDownloadD;
	   AT91RM9200_PIO_REG_STRUCT_PTR pio_ptrb;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);



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
  return; //tftp do not work witch long names
  }

  BuffName[cnt] =  '\0';
   filename = &BuffName[0];
  getpoint += (cnt + 1); 

  for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
   }
    BuffSize[cnt] =  '\0';

   size =  strtoll(&BuffSize[0], &stopstring,10);

// printfpd("\n\r send size = %d \n\r", size);	

    size1 = XilSizeToDownloadD_VNV;
	 size1 =  1000; //t


	pio_ptrb =  (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;


  if(size > TFTP_BUFFER_SIZE)  size = TFTP_BUFFER_SIZE;
 
  getpoint += (cnt + 1);
   for(cnt = 0; cnt <  (BUFFSIZESIZE - 1); cnt++)
  {
    BuffSize[cnt] =  FileUpdate.Value[cnt + getpoint];
  }
    BuffSize[cnt] =  '\0';

   addr_dest =  strtoll(&BuffSize[0], &stopstring,16);

  // #ifdef PACK_CFG
  
   printfpd("\n\r addr_dest : 0x%08X", addr_dest);
 // #endif
  
   getpoint += (BUFFSIZESIZE);

   operation = strtoll(&FileUpdate.Value[getpoint], &stopstring,16);

 
  addr_src = (unsigned int)&TFTP_Buffer[0];

   //need get off watch dog.

//  usart_command_eth_on();
    
   UsedExp.State.Reg1.bit.UCDE = 0; //usart not can now disable ethernet

   keep = (uint_32)SBuffersState.Value;
   keep |= (uint_32)TFTP_PROCEED;
    keep &= ~((uint_32)FILE_WRITE_OK);
   SBuffersState.Value = (float64)keep;





//#ifdef PROG_DMU6



//#ifndef MAKET_PLATA
#ifdef TEST_HANGING      
      printfpd("\n\rtry addr : 0x%08X ", addr_dest);
 //	  printfpd("\n\rXilFileDataAddressD: 0x%08X ",XilFileDataAddressD);

      OperateBuffers_usart0t();

#endif   


	
		if(addr_dest == (XilFileDataAddressD - 0x20))		//xilinx 1
		{

#ifdef TEST_HANGING      
      printfp("\n\rcheck flash cs1 ");
      OperateBuffers_usart0t();

#endif   
 	   errorw = 1;
#ifndef MAKET_PLATA	
	   //hier need found block and set selectoe and set selector

	 //	 for(long ff=0; ff < 100000; ff++)
	 //	 {
	//    pio_ptrb->SODR = 1<<0; // TEMPORARY get down line prog for xilinx 1
   //		AT91F_DataflashInit ();		 //hier find xilinx flash


	    pio_ptrb->CODR = 1<<0; //  get down line prog (B0) for xilinx 1
	   //	}
	 //	  pio_ptrb->SODR = 1<<0;

		delay_mcs(1000);
#endif
        errorw = (signed char)check_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1); //90 : without header
  
     if(errorw) 
     {
#ifdef TEST_HANGING      
      printfp("\n\rerror check_dataflash cs1");
      OperateBuffers_usart0t();

#endif   

#ifndef MAKET_PLATA	
   //t	  pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
	  pio_ptrb->CODR = 1<<0; //get up line prog for xilinx1
//#endif
     return;
#endif

	 }
	 else
	 {
	     printfp("\n\r flash cs1 ok ");

	 }
}

	if(addr_dest == (XilFileDataAddressD2 - 0x20))	  //xilinx 2
		{

#ifdef TEST_HANGING      
      printfp("\n\rcheck flash cs2");
      OperateBuffers_usart0t();

#endif   
	  //   SetSelector(SDMU);
	  //	 SetSelector(CNL2);



	   errorw = 1;
#ifndef MAKET_PLATA	
	   //hier need found block and set selectoe and set selector
	    pio_ptrb->CODR = 1<<6; //  get down line prog for xilinx2

//AT91F_DataflashInit ();		 //hier find xilinx flash	 160915

		delay_mcs(1000);
#endif
        errorw = (signed char)check_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS2); //90 : without header
  
     if(errorw) 
     {
#ifdef TEST_HANGING      
      printfp("\n\rerror check_dataflash cs2 ");
      OperateBuffers_usart0t();

#endif   

#ifndef MAKET_PLATA	


 	  pio_ptrb->SODR = 1<<6; //get up line prog for xilinx2
//#endif
     return;
#endif

	 }
	 else
	 {
	     printfp("\n\r flash cs2 ok ");

	 }

//#endif

 }
 




   
   error = RTCS_load_TFTP_BIN(server,filename, (uchar_ptr)&TFTP_Buffer[0]);
   // wd_reset();

   UsedExp.State.Reg1.bit.UCDE = 1; //now usart can disable ethernet

  if(error)
  {
  	 keep &= ~((uint_32)TFTP_PROCEED);
     SBuffersState.Value = (float64)keep;
	 printfp("\n\r ...Error of TFTP load");
   	 OperateBuffers_usart0t();
     return; //to not write bad loading
   }


 #ifdef CF_PRINT
 printfpd("\n\r ...operation : %d", operation);
 OperateBuffers_usart0t();
 #endif
	wd_reset();
	if(operation == 1l)	  //write file
	{
//printfp("\n\r2a");
 #ifdef CF_PRINT
 printfpd("\n\r addr dest : 0x%x", addr_dest);
 OperateBuffers_usart0t();
 #endif

//fndef PROG_MD310_SATI	  //for config files is need bigger address!!!
	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//ndif

   
//#ifdef PROG_DMU6
//#ifndef MAKET_PLATA	

//if(addr_dest == (XilFileDataAddressD - 0x20))
if((addr_dest == (XilFileDataAddressD - 0x20)) ||  (addr_dest == (XilFileDataAddressD2 - 0x20)))
		{

#ifdef TEST_HANGING      
      printfp("\n\r header size is maked as size ");
      OperateBuffers_usart0t();

#endif      
      wd_reset();
//	  TestWriteFlash4();	//copy  header data to enover buffer  TFTPBuffer1
	  CopyBuffers();   //copy herader
	  
#ifdef TEST_HANGING      
   //   printfp("\n\rInvertBitOrdering ");
  //    OperateBuffers_usart0t();

#endif     
   //	  InvertBitOrdering();	//t  //bit order need inverted.
   
	  wd_reset();
  	  size = 90; // header only
  	  addr_src =  (unsigned int)&TFTP_Buffer1[0]; //use tftpbuffer1 to do not broken tftpbuffer
  //	   write_dataflash (addr_dest, (unsigned int)&TFTP_Buffer1[0], 256);

	  }

//_____________________________________________
//#ifdef PROG_MD310_SATI
	 //	 InvertBitOrdering();//for test

// printfpd("\n\r addr_dest :%x", addr_dest);
//#ifndef PROG_DMU6	  //used before for dmu6

//#ifdef PROG_DMU6	  //160614

	    if(addr_dest == (XilFileDataAddressD - 0x20))

//#else
 //     if(0)

//#endif
		{
	  	  printfp("\n\r.XilFileDataAddressD - 0x20....change address !!!!");
// #ifndef PROG_DMU6	

		 addr_dest = XilFileDataAddressD7 - 0x20;
#ifdef TEST_HANGING      
      printfp("\n\r addr_dest = XilFileDataAddressD7 - 0x20 ");
#endif      


//#ifndef PROG_DMU6	

//	   return; //do not use xilinx! and do not write to config files
//#else
  //if(!SetSelectorToProv())

   //  if(SetSelectorToProv() == CODE_WRONG)
 //t	 SetSelectorToProv(); 
// SetSelector(SDMP);
  //SetSelector(CNL1);


//#endif
 }	//	XilFileDataAddressD

// printfpd("\n\r addr_dest :%x", addr_dest);
 // printfpd("\n\r XilFileDataAddressD2 - 0x20 :%x", XilFileDataAddressD2 - 0x20);

//#ifdef PROG_DMU6	  //160614


if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{

	  	  printfp("\n\r..............change address !!!!");
// #ifndef PROG_DMU6
	
		 addr_dest = XilFileDataAddressD7A - 0x20;

#ifdef TEST_HANGING      
      printfp("\n\r addr_dest = XilFileDataAddressD7A - 0x20 ");
#endif      
 		}

	//	}




  // #endif  // PACK_CFG


//#endif	  //sati
//_________________________________________________________


//#ifdef PROG_DMU6
//#ifndef MAKET_PLATA	
		wd_reset();
		if(addr_dest ==XilFileDataAddressD7 - 0x20)
		{

#ifdef TEST_HANGING      
      printfpd("\n\rstart write cs1 size : %d ", size1);
	      printfpd("\n\r addr : 0x%08X ", (unsigned long)CFG_DATAFLASH_LOGIC_ADDR_CS1);
      OperateBuffers_usart0t();

#endif   
		   pio_ptrb->CODR = 1<<0;

		  AT91F_DataflashInit();


  printf("\n\rwr:>");
    for( i = 0; i < 200; i++)
  {
   if(!(i % 256))
    {    OperateBuffers_usart0t();  wd_reset();
 //  delay_mcs(1000000);
   }


 //  printfpd("\n\r %X >", (i + j));
   printfpd(" %02X", TFTP_Buffer[i + 0x60]);
//   OperateBuffers_usart0t();
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
 //ToPdcTu0(TFTP_Buffer[i]);

  }


	
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	    	printfpd("\n\r errorw = %d ", errorw);
	   wd_reset();





#ifndef MAKET_PLATA	
		//	for(long ff = 0; ff< 10000; ff++)
	   //		{
	  //	   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx		 
	   //	   pio_ptrb->CODR = 1<<0; //get down line prog for xilinx
	   //	   }
	 #endif

			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
   // may be need restart ?         StartLoadAll();
		    wd_reset();
   //ok		  TestWriteFlash2();

  for( i = 0; i < 200; i++)
  {
    TFTP_Buffer[i] = '^';

  }





	    read_dataflash(CFG_DATAFLASH_LOGIC_ADDR_CS1,TEST_SIZE, &TFTP_Buffer[0]);

  printf("\n\r r:>");
    for( i = 0; i < 200; i++)
  {
   if(!(i % 256))
    {    OperateBuffers_usart0t();  wd_reset();
 //  delay_mcs(1000000);
   }


 //  printfpd("\n\r %X >", (i + j));
   printfpd(" %02X", TFTP_Buffer[i]);
//   OperateBuffers_usart0t();
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
 //ToPdcTu0(TFTP_Buffer[i]);

  }




		}


	if(addr_dest ==XilFileDataAddressD7A - 0x20)
		{

#ifdef TEST_HANGING      
      printfpd("\n\rstart write cs2 size : %d ", size1);
	      printfpd("\n\r addr : 0x%08X ", (unsigned long)CFG_DATAFLASH_LOGIC_ADDR_CS2);
      OperateBuffers_usart0t();

#endif   
 #ifndef MAKET_PLATA	
	
 	   pio_ptrb->CODR = 1<<6;

#endif

		  AT91F_DataflashInit();
         errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS2, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
//#ifndef MAKET_PLATA	 
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	  	printfpd("\n\r errorw = %d ", errorw);
	   wd_reset();

#ifndef MAKET_PLATA	
	  //	   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
		      pio_ptrb->SODR = 1<<6; //get down line prog for xilinx


#endif

			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
   // may be need restart ?         StartLoadAll();
		    wd_reset();
   //ok		  TestWriteFlash2();
		}

	 delay_mcs(2000000);

   #ifndef MAKET_PLATA	
	 if(errorw == (signed char)1)
#else
	 if(1)
#endif
	 {
 	 printfp("\n\r write name");
#ifdef TEST_HANGING      
      printfpd("\n\rstart write addr : 0x%08X ", addr_dest);
	  printfpd("size : %d ", size);
#endif   
     write_dataflash (addr_dest, addr_src,  size);
	 }
	 else
	 {
	  printfp("\n\r Error writing file!!!!!");
	 }

// #ifdef PACK_CFG
//}
//#endif
 #ifdef TEST_HANGING  
 printfp("\n\r ...writing is  finished");
 OperateBuffers_usart0t();
 #endif
  	   delay_mcs(100);

    FillXilFileData((char)XILINXPG);   //after init flsh make this
	 FillProgVersion();
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
	else if(operation == 6l)	  //compare file
	{
//printf("\n\r2a");

//120710	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
//printf("\n\r3");
//#ifdef PROG_PRM_PCH_SPI

 //  AT91F_DataflashInitx();  //t


#ifndef PROG_DMU6
#ifdef XIL_FLASH

 AT91F_DataflashInitx();  //t

#ifdef DEBUG_WRITE_XIL
  printfp("\n\r start compare xil flash");
  printfpd(" addr: 0x%X", addr_dest);
   printfpd(" size: %d", size);
#endif

 if(addr_dest < CFG_DATAFLASH_LOGIC_ADDR_CS1X)
 {

#ifdef DEBUG_WRITE_XIL
  printfpd("\n\r addr < CFG_DATAFLASH_LOGIC_ADDR_CS1X : %d \n\r" , size);
  OperateBuffers_usart0t();

#endif

 //  return; //to test

 //t  CompareToFilex(size);
#ifndef PROG_MD310
#ifndef PROG_KAZAH
  InvertBitOrdering();		//t new 
#endif
#endif


#ifdef PROG_ODU1
  	  CompareToFilex(ODU_XIL_SIZE);	//t


#else
	    CompareToFilex(1000);

#endif
   //ok	  CompareToFilex(1000);	//t
 //  CompareToFilex(10000);


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
#endif
	  /*
#ifdef PROG_DMU6
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
	*/
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


#ifdef PROG_DMU6
		printfpd("\n\r compare file dmu addr_dest : 0x%08X", addr_dest );
		printfpd(" size1 : 0x%08X", size1 );

	//	printfpd(" XilFileDataAddressD - 0x20: 0x%08X", XilFileDataAddressD - 0x20);


		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

   //		if(addr_dest == (XilFileDataAddressD - 0x20))
		if(addr_dest ==0)
		{
//write to second flash local addr = 0;
//___________________________________________try write from second try
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  size); //90 : without header
 	 //	delay_mcs(2000000);
//_________________________________________
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0],  size);
	//	   TestWriteFlash3();
  //		  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer1[0],  255); //t
   //     write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	//t   CompareToFile(size1);
	   pio_ptrb->CODR = 1<<0; //get down line prog for xilinx
	    AT91F_DataflashInit();
  	CompareToFile(200);		  //t
//  CompareToFile(1000);	
		// CompareToFile(size1);

	     pio_ptrb->SODR = 1<<0;
	
	    wd_reset();
   //ok		  TestWriteFlash2();
		}

	 //	 printfp ("\n\r check need compare cs2");

			if(addr_dest == 0x10000000)
		{
		printfp ("\n\r need compare cs2");
	   CompareToFilecs2(size1);
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

#ifndef PROG_VNV

#ifdef PROG_BMDN3
ScanTxtFiles();
#endif

#ifdef PROG_BMDN4
ScanTxtFiles();
#endif
#endif

	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}
if(operation == 8l)	  //fast write file
	{
//printfp("\n\r2a");
 #ifdef CF_PRINT
 printfpd("\n\r addr dest : 0x%x", addr_dest);
 OperateBuffers_usart0t();
 #endif

#ifndef PROG_MD310_SATI	  //for config files is need bigger address!!!
	 if((addr_dest < 0xC0000000) ||  ((size + addr_dest) >=0xC083ffff)) return;
#endif


//printfp("\n\r3");
//#ifdef PROG_PRM_PCH_SPI
//   AT91F_DataflashInit();  //t
//#endif
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
 /*
#ifdef PROG_DMU6
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
 */


//#ifdef PROG_PU_MSAT
//if(addr_dest != (XilFileDataAddressD - 0x20))
  //		{
//#endif

   //  printfp("\n\r..............change address ?????");

#ifdef PROG_MD310_SATI
	 //	 InvertBitOrdering();//for test

// printfpd("\n\r addr_dest :%x", addr_dest);
//#ifndef PROG_DMU6	
	  if(addr_dest == (XilFileDataAddressD - 0x20))
		{
	  //	  printfp("\n\r..............change address !!!!");
// #ifndef PROG_DMU6	

		 addr_dest = XilFileDataAddressD7 - 0x20;
#ifndef PROG_DMU6	

	   return; //do not use xilinx! and do not write to config files
#else
 // if(!SetSelectorToProv())
   if(SetSelectorToProv() != CODE_WRONG)

  {
	 printfp("\\Do not have Provingent plata... return");
  	   return;
   }
#endif
		}

if(addr_dest == (XilFileDataAddressD2 - 0x20))
		{
	  //	  printfp("\n\r..............change address !!!!");
// #ifndef PROG_DMU6
	
		 addr_dest = XilFileDataAddressD7A - 0x20;

  #ifndef PROG_DMU6	
     return; //do not use xilinx! and do not write to config files


#else
  //if(!SetSelectorToDMU())
   if(SetSelectorToDMU() != CODE_WRONG)

  {
	 printfp("\\Do not have Provingent plata... return");
  	   return;
   }


	//   return; //do not use xilinx! and do not write to config files
#endif
		}

//#endif

// printfpd("\n\r dest :%x", addr_dest);
// printfpd("\n\r size :%x", size);


		 else if(addr_dest == ((unsigned long)PROG_ADDRESS - (unsigned long)HEADER_SIZE))
		{
	//	  printfp("\n\r..............change size !!!!");

	   //	 size = 600000l; //big programm size	was 524k
		 size = BIG_PROG_SIZE; //big programm size	was 524k
		}
		 /*
	    else if(addr_dest >= ((unsigned long)CONFIG_FILES_ADDRESS_OLD - (unsigned long)HEADER_SIZE - (unsigned long)HEADER_SIZE))
		{
		//set to another flash
		 addr_dest += 0x20000000; //0xc00000000 ->  0xe0000000
		 addr_dest -= 0x00220000;

		printfp("\n\r..............change address for config !!!!");
		printfpd("\n\r new addr dest : 0x%x", addr_dest);


		}

		  */

   #ifdef PACK_CFG

   //   else if(addr_dest >= ((unsigned long)CONFIG_FILES_ADDRESS_OLD - (unsigned long)HEADER_SIZE - (unsigned long)HEADER_SIZE))
      else if(addr_dest >= (unsigned long)START_ADDR_CFG_FILE)
		{
		//set to another flash
	  //	 addr_dest += 0x20000000; //0xc00000000 ->  0xe0000000
	  //	 addr_dest -= 0x00220000;
		 num_cfg_file = (addr_dest - START_ADDR_CFG_FILE) / OLD_CONFIG_FILE_VARIANTS_STEP;
	
		printfpd("\n\r old addr dest : 0x%x", addr_dest);
		printfpd(" num_cfg_file : %d", num_cfg_file);

	//	PackConfig(); // convert config file from 40 to 19 K

		 addr_dest =  START_ADDR_CFG_FILE + (num_cfg_file * CONFIG_FILE_VARIANTS_STEP);

		printfp("\n\r..............change address for config !!!!");
		printfpd("\n\r new addr dest : 0x%x", addr_dest);

		 for(i = 0; i < 6000; i ++)
		 {
			TFTP_Buffer[SYNT_DATA_OFFSET + i] = TFTP_Buffer[OLD_FILE_SIZE - 6000 + i];
		 }



 	    write_dataflash (addr_dest, addr_src, FILE_SIZE);

   //     write_dataflash (addr_dest + SYNT_DATA_OFFSET + 1, addr_src + OLD_FILE_SIZE - 6000 + 1,  6000); //write last 6k of file

		config_flag = 1; 
		}




   #endif  // PACK_CFG


#endif


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
	 delay_mcs(2000000);

#endif
#endif

#ifdef PROG_DMU6
#ifndef MAKET_PLATA	
		wd_reset();
 		delay_mcs(2000000); //waiting two sec to write to first flash

		if(addr_dest == (XilFileDataAddressD7 - 0x20))
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
		   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
  #ifndef PROG_VNV

            StartLoadAllM();
  #endif

		    wd_reset();
   //ok		  TestWriteFlash2();
		}

		if(addr_dest == (XilFileDataAddressD7A - 0x20))
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
        errorw = (signed char)write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS2, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
  //     errorw = (signed char)write_dataflash1(CFG_DATAFLASH_LOGIC_ADDR_CS1, (unsigned int)&TFTP_Buffer[0x60],  size1); //90 : without header
	 //  	printfpd("\n\r error2 = %d", errorw);
	   wd_reset();
		   pio_ptrb->SODR = 1<<0; //get up line prog for xilinx
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
			delay_mcs(1000000l); //wait while loading
  #ifndef PROG_VNV

            StartLoadAllM();
  #endif
		    wd_reset();
   //ok		  TestWriteFlash2();
		}



	 delay_mcs(2000000);

#endif
#endif


 #ifdef PACK_CFG
if(!config_flag)
{  

 #endif

	 if(errorw == (signed char)1)
	 {
  //	 printfp("\n\r write name");

     write_dataflash (addr_dest, addr_src,  size);

	 }

 #ifdef PACK_CFG
}
#endif

 #ifdef CF_PRINT
 printfp("\n\r ...writing is  finished");
 OperateBuffers_usart0t();
 #endif



  //	  wd_reset();
//printfp("\n\r4");
  	   delay_mcs(100);

 #ifndef 	PROG_PRM_PCH_DEM_XIL
   FillXilFileData((char)XILINXPG);   //after init flsh make this
#else
   FillXilFileData((char)XILINXPG1);   //after init flsh make this
#endif   

	 FillProgVersion();


	 keep &= ~((uint_32)TFTP_PROCEED);
	 keep |= (uint_32)FILE_WRITE_OK;

     SBuffersState.Value = (float64)keep;
 
	}

}


