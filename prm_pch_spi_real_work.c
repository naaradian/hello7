//file : prm_pch_spi_real_work.c
unsigned char OperateBuffers_SSC2_Polled(void);




void enableRxPdcSPI1(void);

extern uchar TFTP_Buffer1[TFTP_BUFFER_SIZE];


extern "C" void ConnectEnable()
{
   //hier will be setted to zero line connect
   
   
}

extern "C" void SetLineConnectToIO(void)
{
   
}
   /*
extern "C" void DataOffSet()
{
   
}
extern "C" void DataOffClear()
{
   
}
  */


#ifdef USE_ATT_TABLE
#ifndef PROG_PRM_PCH_SPI_STEND
extern "C" void ReadAFR()
{
  read_dataflash((unsigned int)(XilDataAddressD2 - (AFR_SIZE <<1)) , (unsigned int)AFR_SIZE, (char *)(&AFR[0]));
}

extern "C" void PrintAFR()
{
printfp ("\n\r afr : \n\r");
for(unsigned i = 0 ; i < AFR_SIZE; i++)
 
//for(unsigned i = 0 ; i < 100; i++)
{

  printfpd(" %02X", AFR[i]);
  if((!(i%20))&& i){
   printfpd("\n\r %05d| ", i); 
  OperateBuffers_usart0t();
 //  printfpd("  %02X", AFR[i]);

  
}  
   
}
   
//  read_dataflash((unsigned int)(XilDataAddressD2 - (AFR_SIZE <<1)) , (unsigned int)AFR_SIZE, (char *)(&AFR[0]));
}


#ifdef TWO_RECEIVERS

extern "C" void ReadAFR1()
{
  read_dataflash((unsigned int)(XilDataAddressD2 - (AFR_SIZE <<2)) , (unsigned int)AFR_SIZE, (char *)(&AFR1[0]));
}

extern "C" void WriteAFR1()
{
//  printfpd("\n\r>%02X",AFR[0]);
  for(unsigned i = 0; i < AFR_SIZE; i++){ /* Body */
//   printfpd("\n\r>%02X",AFR[i]);
  TFTP_Buffer1[i] = AFR1[i];
} /* Endbody */
//   for( i = 0; i < 8; i++){ /* Body */
//  printfpd(">%02X",AFR[i]);
 // TFTP_Buffer1[i] = AFR[i];
//} /* Endbody */
 
  write_dataflash((unsigned int)(XilDataAddressD2 - (AFR_SIZE <<2)), (unsigned int)(&TFTP_Buffer1[0]), (unsigned int)AFR_SIZE);
//  printfpd("\n\r<%02X",AFR[0]);
// for( i = 0; i < 8; i++){ /* Body */
//    printfpd("<%02X",AFR[i]);
// } /* Endbody */

}


#endif

extern "C" void WriteAFR()
{
//  printfpd("\n\r>%02X",AFR[0]);
  for(unsigned i = 0; i < AFR_SIZE; i++){ /* Body */
//   printfpd("\n\r>%02X",AFR[i]);
  TFTP_Buffer1[i] = AFR[i];
} /* Endbody */
//   for( i = 0; i < 8; i++){ /* Body */
//  printfpd(">%02X",AFR[i]);
 // TFTP_Buffer1[i] = AFR[i];
//} /* Endbody */
 
  write_dataflash((unsigned int)(XilDataAddressD2 - (AFR_SIZE <<1)), (unsigned int)(&TFTP_Buffer1[0]), (unsigned int)AFR_SIZE);
//  printfpd("\n\r<%02X",AFR[0]);
// for( i = 0; i < 8; i++){ /* Body */
//    printfpd("<%02X",AFR[i]);
// } /* Endbody */

}





#endif
#endif

#ifdef USE_SPI

void test_send_data_spi(void);
void enableRxPdcSPI1(void);
void enableTxPdcSPI1();
unsigned char OperateBuffers_SPIt1(void);
void ToPdcTspi(unsigned char);
unsigned char OperateBuffers_SPI1(void);


//extern "C" void embMsgSSC2N_Add(unsigned char);
//extern "C" unsigned char embMsgSSC2N_ChkCRCN(unsigned long);

extern unsigned char flag_receive_spi;






#define AT91RM9200_SSC_IMR_RXRDY (0x10)

void init_test_spi_master(void)
{
 //need set spi to slave mode
 
 //  printfp("init_test_spi");
//1 init transmit to self clocks
  AT91RM9200_SPI_REG_STRUCT_PTR         spi_ptr;
  spi_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0); //
  
  //   spi_ptr->CR &= ~0x80l;//111017  //spi reset
  
   AT91F_PDC_Close((AT91PS_PDC) &(spi_ptr->PDC));
 
      spi_ptr->CR = 1l; //spi enable
           // spi_ptr->MR  = 0xFF000009l; //master;mck /32; max delay; spi cs0 enable
   //t    spi_ptr->MR  = 0x00010001l; //master;mck/1; max delay; spi cs1 enable
     //111014     spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
      spi_ptr->MR  = 0x00000001l;//slave //master;variable perpireall; mck/1; spi cs1 enable
      spi_ptr->MR &= 0xFFF0FFFF;
		spi_ptr->MR |= ((0xE<<16)); //cs0               //tt     spi_ptr->MR  = 0x00010107l; //master;variable perpireall; mck/1; spi cs1 enable
    // tmp = spi_ptr->MR;
     //      spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
  //t    spi_ptr->MR = tmp | 0x10002l;
      //     spi_ptr->MR  = 0x00010007l; //master;variable perpireall; mck/1; spi cs1 enable
     // spi_ptr->CSR[0] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs0
    //t  spi_ptr->CSR[0] =0xffffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //t  spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
     //    spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //111014      spi_ptr->CSR[1] =0x0f0f0200l; // 8 bit baud rate / 255   ; max delays ; - cs1
//111018 loss some symbols     spi_ptr->CSR[0] =0x00000003l; // 8 bit baud rate / 255   ; max delays ; - cs1
//     spi_ptr->CSR[0] =0x00000403l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //no   spi_ptr->CSR[0] =0x00000411l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
   //111018  spi_ptr->CSR[0] =0x0000203l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
  //   spi_ptr->CSR[0] =0x0000203l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
//111018     spi_ptr->CSR[0] =0x0000201l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
     spi_ptr->CSR[0] =0x0000201l;//
   //   spi_ptr->CSR[0] =0x00000203l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //    spi_ptr->CSR[0] =0x00000202l; // 8 bit baud rate / 255   ; max delays ; - cs1
 //no     spi_ptr->CSR[0] =0x00000201l; // 8 bit baud rate / 255   ; max delays ; - cs1

  //hangt    spi_ptr->CSR[0] =0x00000202l; // 8 bit baud rate / 255   ; max delays ; - cs1
    //   spi_ptr->CSR[1] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //   spi_ptr->IDR  = 0xFFl; //interrupt 

 enableRxPdcSPI1();
 enableTxPdcSPI1();
  // spi_ptr->CR = 1l; //spi enable

   
}


void init_test_spi(void)
{
 //need set spi to slave mode
 
 //  printfp("init_test_spi");
//1 init transmit to self clocks
  AT91RM9200_SPI_REG_STRUCT_PTR         spi_ptr;
  spi_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0); //
  
  //   spi_ptr->CR &= ~0x80l;//111017  //spi reset
  
   AT91F_PDC_Close((AT91PS_PDC) &(spi_ptr->PDC));
 
      spi_ptr->CR = 1l; //spi disable
     // spi_ptr->MR  = 0xFF000009l; //master;mck /32; max delay; spi cs0 enable
   //t    spi_ptr->MR  = 0x00010001l; //master;mck/1; max delay; spi cs1 enable
     //111014     spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
      spi_ptr->MR  = 0x00000002l;//slave //master;variable perpireall; mck/1; spi cs1 enable
      spi_ptr->MR &= 0xFFF0FFFF;
	 	spi_ptr->MR |= ((0xE<<16)); //cs0          
     //tt     spi_ptr->MR  = 0x00010107l; //master;variable perpireall; mck/1; spi cs1 enable
    // tmp = spi_ptr->MR;
     //      spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
  //t    spi_ptr->MR = tmp | 0x10002l;
      //     spi_ptr->MR  = 0x00010007l; //master;variable perpireall; mck/1; spi cs1 enable
     // spi_ptr->CSR[0] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs0
    //t  spi_ptr->CSR[0] =0xffffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //t  spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
     //    spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //111014      spi_ptr->CSR[1] =0x0f0f0200l; // 8 bit baud rate / 255   ; max delays ; - cs1
//111018 loss some symbols     spi_ptr->CSR[0] =0x00000003l; // 8 bit baud rate / 255   ; max delays ; - cs1
//     spi_ptr->CSR[0] =0x00000403l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //no   spi_ptr->CSR[0] =0x00000411l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
   //111018  spi_ptr->CSR[0] =0x0000203l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
  //   spi_ptr->CSR[0] =0x0000203l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
//111018     spi_ptr->CSR[0] =0x0000201l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
     spi_ptr->CSR[0] =0x0000201l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1
//    spi_ptr->CSR[0] =0x0000200l;//try 9bit // 8 bit baud rate / 255   ; max delays ; - cs1 
   //   spi_ptr->CSR[0] =0x00000203l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //    spi_ptr->CSR[0] =0x00000202l; // 8 bit baud rate / 255   ; max delays ; - cs1
 //no     spi_ptr->CSR[0] =0x00000201l; // 8 bit baud rate / 255   ; max delays ; - cs1

  //hangt    spi_ptr->CSR[0] =0x00000202l; // 8 bit baud rate / 255   ; max delays ; - cs1
    //   spi_ptr->CSR[1] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs1
      spi_ptr->IDR  = 0xFFl; //interrupt enable

 enableRxPdcSPI1();
 enableTxPdcSPI1();
  // spi_ptr->CR = 1l; //spi enable

   
}

//t111208 #define PERIOD_SPI_SEND (20)
//#define PERIOD_SPI_SEND (6)

//#define PERIOD_SPI1_SEND (3)
//#define PERIOD_SPI1_SEND (200)

//#define PERIOD_SPI1_SEND (30)
//#define PERIOD_SPI1_SEND (10)


//#define PERIOD_SPI1_SEND (1000)

#ifdef PROG_PRM_PCH_SPI_STEND
#define TEST_ATT_BYTE1 (4)

void test_send_data_spi(void)
{
unsigned char ret;
unsigned long reg;

static unsigned char send_char = 0;
static unsigned long timekeep;
static unsigned char pinger;

 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
  SPI_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_A, 0);

if(timekeep > time1) timekeep = time1;
/*
if((time1 - timekeep) > (PERIOD_SPI_SEND >> 1)) 
{
 // SetPB19();

}
 */
if((time1 - timekeep) > PERIOD_SPI_SEND) 
{

spi_counter_t ++;


//t AT91F_SPI_EnableTx (SPI_ptr);     //t        
//t AT91F_SPI_EnableRx (SPI_ptr);     //t        
 
 printfp("\n\rsend ");
  
//   reg = SPI_ptr->PDC.PTSR;
 //    printfpd(" %X", reg);
 
 //  reg = SPI_ptr->SR;
 //    printfp("SR:");
 //    printfpd("%X", reg);   //hier view as tx and rx are disabled
 
// printfp(" cnt:");
// printfpd("%ld", spi_int_counter);
     
      
// SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
// reg  = SPI_ptr->PDC.TCR;
// SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
//      printfpd("> %X", reg);
//t  SPI_ptr->IER =  0xff; //if comment hier -loss    
       
 //reg  = SPI_ptr->IMR;      
 // printfp("IMR :");
 // printfpd(" %X", reg);
  
//______________________________________  
//   ret = OperateBuffers_SPIt();  
//   printfpd(" %d", ret);
//______________________________________ 


timekeep = time1;

 // SetPB19();
// MClearPB19();
  //    printfp(" Clear :");
    
//for(unsigned i = 0; i < 16; i++)
//{
// send_char++;
 
// ToPdcTspi(send_char);
//} 

// ToPdcTspi(0x1); 
// ToPdcTspi(0x2);  
 
  
//send_char++;
 //ToPdcTspi(send_char);
 
//?? need enable transmit data pin and enable olwais
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);
  
 // ret = OperateBuffers_SPIt(); 
 //  printfpd(" %d", ret);
   
//110724   OperateBuffers_SPI(); 

if(pinger)
{

printfpd("t0.%ld ", time1);

pinger = 0;
    /*
 ToPdcTspi(START_COMMAND);
  printfpd(".%02X", START_COMMAND);
 ToPdcTspi(MASK_REQUEST + MY_ADDRESS);
  printfpd(".%02X", MASK_REQUEST + MY_ADDRESS);
 ToPdcTspi(COMM2_LEN);
  printfpd(".%02X", COMM2_LEN);
 ToPdcTspi(COMMANDN2);
  printfpd(".%02X", COMMANDN2);
 ToPdcTspi(TEST_FREQ_BYTE1);   //my addr
  printfpd(".%02X", TEST_FREQ_BYTE1);
 ToPdcTspi(TEST_FREQ_BYTE2); //command
  printfpd(".%02X", TEST_FREQ_BYTE2);
 ToPdcTspi(MASK_REQUEST + MY_ADDRESS + COMM2_LEN + COMMANDN2 + TEST_FREQ_BYTE1 + TEST_FREQ_BYTE2 + 1); //checksum
  printfpd(".%02X", MASK_REQUEST + MY_ADDRESS + COMM2_LEN + COMMANDN2 + TEST_FREQ_BYTE1 + TEST_FREQ_BYTE2 + 1);

 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
        */
  /*
 ToPdcTspi(START_COMMAND);
 ToPdcTspi(MASK_REQUEST + MY_ADDRESS);
 ToPdcTspi(COMM3_LEN);
 ToPdcTspi(COMMANDN3);
 ToPdcTspi(TEST_ATT_BYTE1);   //my addr
 ToPdcTspi(MASK_REQUEST + MY_ADDRESS + COMM3_LEN + COMMANDN3 + TEST_ATT_BYTE1 + 1); //checksum
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 */
 
  
 ToPdcTspi(START_COMMAND);
  printfpd(".%02X", START_COMMAND);
 ToPdcTspi(0xff);
 printfpd(".%02X", 0xff);
 ToPdcTspi(1);  //7
 printfpd(".%02X", 1);
 ToPdcTspi(COMMANDN4);   //1
 printfpd(".%02X", COMMANDN4);
 ToPdcTspi(5); //2
  printfpd(".%02X", 5);
//ToPdcTspi(TEST_ATT_BYTE1); //3
// printfpd(".%02X", MASK_REQUEST + MY_ADDRESS + COMM4_LEN + COMMANDN4 + TEST_ATT_BYTE1*6 + 1);
 ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
ToPdcTspi(0xFE);
   

}
else
{
printfpd("t1_%ld ", time1);
  pinger = 1; 
    
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE);
 ToPdcTspi(0xFE); 
 
 }
  
   
   
   ret = OperateBuffers_SPIt1();  
 //  printfpd(" %d", ret);

//?? need make this later? why?  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0);
//?? need disable transmit data pin pdc or pin to can have "star"   
}
}

#endif

void disable_txd_pin_spi()  //call this function after send all after check counters transmit pdc
{
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_IO, 0); 
}


void init_exchange_spi(void)
{
/*
init_spi();
enableRxPdcSPI();
enableTxPdcSPI();
  */
  
//init_spt();
 enableRxPdcSPI1();
 enableTxPdcSPI1();
  
  
  
//110713 to use irq0 enable_ints_spi();
}

void SetLineDataSPIToZero()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->CODR = 1<<0; 
}

void SetLineDataSPIToOne()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->SODR = 1<<0; 
}

void SetLineDataSPIOff()
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_IO, 0); 
}

        /*
void SetLineAlarmToZero()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->CODR = 1<<10; 
}
       void SetLineAlarmToOne()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->SODR = 1<<10; 
}

void SetLineAlarmOff()
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 10, AT91RM9200_PIO_PERIPHERAL_IO, 0); 
}

      */
void SetLineDataSS2ToSPIData()  //if def value - one to all ok
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_A, 0);  
}

void SetLineDataOffToZero()
{
 printfp("_");
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->CODR = 1<<4; 
}

void SetLineDataOffToIO()
{
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
//.  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
//  pio_ptr->SODR = 1<<4; 
}

void SetLineDataOffToOne(void)
{
// printfp("^");

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
//  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->SODR = 1<<4; 
}

extern unsigned char flag_receive_spi;

void AT91F_SPI_Receive_Polled(void)
{
  flag_receive_spi = 0;
  OperateBuffers_SPI1_Polled();
}

void AT91F_SSC2_Receive_Polled(void)
{
  flag_receive_spi = 0;
  OperateBuffers_SSC2_Polled();
}



void AT91F_SPI_IRQ0_Handler(void)
{
  flag_receive_spi = 1;
 //  DataOffSet();   //line data getted off
//current_command_counter = 0;   //110714 for this interrupt can set hier   to start

//my_int_disable_SPI();
 //unsigned long reg;
 //spi_int_counter++;
//AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
// AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 
 
// SetLineAlarmOff();
 
  
  // if(current_command_state == WAITING_COMMAND)
  // {
   //      SetLineAlarmOff();
  //110923       SetLineDataSPIOff();
  //       current_command_counter = 0;
 //      current_command_state = RECEIVE_COMMAND;
  // }
     
  //pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  
// FOR TEST ONLY!!!!
  //set line alarm to one         //????? line alarm - common or not
 // pio_ptr->CODR = 1<<18; //test pin 
 // pio_ptr->SODR = 1<<19; //test pin
 //  SetLineDataSS2ToOne(); //temporary
//   }

// SPI_ptr =  (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
 
//110724 printfp("AT91F_SPI_Handler");

//   AT91RM9200_SPI_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI0_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
 //	status = pSPI1->SPI_SR;
//   	status = ssc0_ptr->SPI_SR;
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SPI_RPR),	// PDC SPI base address
//						 (char *)wav_file, 				// pointer to next data
//						AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words

 /* 110624
 
 SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 reg  = SPI_ptr->PDC.TCR;
 SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
      printfpd("H>%X", reg);
      
 */     
 // SPI_ptr->IER =  0xff; //if comment hier -loss  
 
   
//bad return; //t
  SetLineAlarmOff();     //disable line alarm
  SetLineDataOffToOne(); //disable line data
  
  if (OperateBuffers_SPI1()) //my addr
  { /* Body */
 //  pio_ptr->CODR = 1<<19;  // test pin
 //110923  SetLineDataSS2ToZero();
 //  SetLineDataOffToZero();
 //  SetLineAlarmToOne();   //before run or not run command
//  printfp("+");
  } /* Endbody */
 //moved   ParseCommandsSPI();
   
   
   
//FOR TEST ONLY   
 // pio_ptr->SODR = 1<<18;  //test pin
//  my_int_enable_SPI();
}

 
//#define SPI_FREQ (5000000)

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : init_channel
* Returned Value   : none
* Comments         :
*    This function init spi for spi
*
*END*----------------------------------------------------------------------*/

void init_spi_for_slave_mode (void)
{
 // unsigned int cnt;
//  char* CurrentDataPointer;
// unsigned int imr;//
AT91RM9200_SPI_REG_STRUCT_PTR         spi_ptr;
  spi_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

//  pio_ptr->SODR = 1<<22; //set line alarm to one
 //110923	SetLineDataSPIOff();  //for many devices systems	
  	SetLineAlarmOff();
   
   AT91F_PDC_Close((AT91PS_PDC) &(spi_ptr->PDC));
   spi_ptr->CR = 1l; //spi enable
     // spi_ptr->MR  = 0xFF000009l; //master;mck /32; max delay; spi cs0 enable
   //t    spi_ptr->MR  = 0x00010001l; //master;mck/1; max delay; spi cs1 enable
     //111014     spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
          spi_ptr->MR  = 0x00000002l;//slave //master;variable perpireall; mck/1; spi cs1 enable
     //tt     spi_ptr->MR  = 0x00010107l; //master;variable perpireall; mck/1; spi cs1 enable
    // tmp = spi_ptr->MR;
     //      spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
  //t    spi_ptr->MR = tmp | 0x10002l;
      //     spi_ptr->MR  = 0x00010007l; //master;variable perpireall; mck/1; spi cs1 enable
     // spi_ptr->CSR[0] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs0
    //t  spi_ptr->CSR[0] =0xffffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //t  spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
     //    spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //111014      spi_ptr->CSR[1] =0x0f0f0200l; // 8 bit baud rate / 255   ; max delays ; - cs1
  //111017    spi_ptr->CSR[1] =0x00000200l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //     spi_ptr->CSR[0] =0x00000202l; // 8 bit baud rate / 255   ; max delays ; - cs1
        spi_ptr->CSR[0] =0x00000203l; // 8 bit baud rate / 255   ; max delays ; - cs1

    //   spi_ptr->CSR[1] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //   sp
enableRxPdcSPI1();
enableTxPdcSPI1();
  

      
}

 
#define SPI_RX_BUFFER1 200  
  
unsigned char Buffspi[SPI_RX_BUFFER1]; //buffer
unsigned char Buff1spi[SPI_RX_BUFFER1]; //buffer
unsigned char flag_pdcspi;


//unsigned enableRxPdcSPI1(void)
void enableRxPdcSPI1(void)
{
  AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
  SPI_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  SPI_ptr->PDC.RPR = (uint_32)&Buffspi[0];
  SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
  flag_pdcspi = 0;

  SPI_ptr->PDC.RNPR = (uint_32)&Buff1spi[0];
  SPI_ptr->PDC.RNCR = SPI_RX_BUFFER1;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
//   typedef volatile struct at91rm9200_pdc_reg_struct
//{
 //  uint_32	RPR;			/* Receive Pointer Register */
 //  uint_32	RCR;			/* Receive Counter Register */
 //  uint_32	TPR;			/* Transmit Pointer Register */
 //  uint_32	TCR;			/* Transmit Counter Register */
 //  uint_32	RNPR;			/* Receive Next Pointer Register */
 //  uint_32	RNCR;			/* Receive Next Counter Register */
 //  uint_32	TNPR;			/* Transmit Next Pointer Register */
 //  uint_32	TNCR;			/* Transmit Next Counter Register */
 //  uint_32	PTCR;			/* PDC Transfer Control Register */
 //  uint_32	PTSR;			/* PDC Transfer Status Register */
      
//} AT91RM9200_PDC_REG_STRUCT, _PTR_ AT91RM9200_PDC_REG_STRUCT_PTR;
 
 
  /* Interrupt when transmission to receive buffer is completed */
 //    SPI_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
 //110620  SPI_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SPI_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//110620     SPI_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
 /* 
#ifdef PROG_PRM_PCH_N
    SetSPIBaudRate(921600l);
#else 
    SetSPIBaudRate(38400l); 
#endif 
*/

//return 0;
}

/*
extern "C" void RunCommandSPI(void)
{

     if(embMsgSPI.ParseS())
      { 
       SetLineAlarmToOne();
      } 
      else
      { 
       SetLineAlarmToZero();
      } 



 //  if(GetTestMode() != 0x50)
//   {
  //  SetLineDataSS2ToSPIData();
      _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);

     for(unsigned i = 0; i< 16; i++)
     { 
     
   //    ToPdcTspi(i);
   //    printfpd("-%02X", i);
     }
     OperateBuffers_SPIt();
 //  }

}

*/

void SetRunCommandSPI(void)
{
NeedRunCommand = 1;


}


unsigned char CheckSPICRC()
{


 return 1;  
   
}

//111017#define NO_COMMAND_SPI (COMMANDS_QUANTITY + 100)  // use from zero 0 ...q-1 : commands q - no commands
#define NO_COMMAND_SPI (0) //to not hangt // use from zero 0 ...q-1 : commands q - no commands
// DO NOT USED NOW!!!
  /*
unsigned char OperateCommandSPI1(unsigned char * pData)
{
  AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
  SPI_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
  
// AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
 // pio_ptr->SODR = 1<<14; 
// if(current_command_state == RECEIVE_COMMAND)
// { 
  current_command_counter++;
// }
 
// printfpd(" ccc:  %d", current_command_counter);
#ifdef TEST_PRINT_SPI 
// printfpd(" :%X", * pData); //110914
#endif

#ifndef PRM_PCH_SPI_STEND

embMsgSSC2N_Add(* pData);

#else

return;

#endif

if(current_command_counter == START_POS)
  {
   if(*pData == (unsigned char)0xAA)
      { 
     embMsgSSC2N_Init();
     current_command_state = RECEIVE_COMMAND;
     current_command_data_counter = 0;
     
 //     printfp("\n\r> start ");
      }
  }
 else 
 if((current_command_counter == LENGTH_POS) &&  ( current_command_state == RECEIVE_COMMAND))
  {
     current_command_length = *pData;
  //    printfp("\n\r> len: ");
  //     printfpd(" %d", *pData);

  }
 else 
 if((current_command_counter == ADDR_POS) &&  ( current_command_state == RECEIVE_COMMAND))

  {
       //  printfpd("% 02X", *pData);
  //   if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
   
     if((((unsigned char)*pData & (~MASK_REQUEST)) == MY_ADDRESS)
     ) //091104
   //091104 temporary  ||  (*pData == (unsigned char)BRD_ADDRESS))
   //   if(1)
     {
//#ifdef TEST_PRINT_SPI      
 //  printfp("\n\r> addr ok ");
//#endif   
      current_command_state = RUN_COMMAND;
    //   pio_ptr->SODR = 1<<18;
   //    pio_ptr->CODR = 1<<18;
  //    MClearPB19();
 //   printfp("\n\r>");
  //    printfp(" Clear :");
  //    printfpd("% 02X", *pData);
      
//      pio_ptr->CODR = 1<<19; 
     
  //     SetState(RUN_Command);
  //     temporary commented     SetLineDataSS2ToZero();
       return 1;
     } 
   return 0;
  } 
  else if((current_command_counter == COMMAND_POS) &&  (current_command_state == RUN_COMMAND))
  {
     if(*pData <= COMMANDS_QUANTITY)
     {
      current_command_type =  *pData;
  //    printfp("\n\r type :");
  //    printfpd(" %d ", current_command_type);
  //    printfp(" CommandLength :");
  //    printfpd(" %d", CommandLength[current_command_type]);
  //    printfp(" CommandDataLength :");
   //   printfpd(" %d", CommandDataLength[current_command_type]);



      return 0;
      }
      else{ 
      
      current_command_type = NO_COMMAND_SPI;
   //            printfp(" type :");
   //   printfpd(" %d", current_command_type);
   //                printfp(" CommandLength :");
   //  printfpd(" %d", CommandLength[current_command_type]);

      
   }
  }
   else if((current_command_counter == CommandDataLength[current_command_type])
    &&  (current_command_state == RUN_COMMAND))
  {
   current_command_crc =  *pData;
 #ifndef PRM_PCH_SPI_STEND
  
  if(embMsgSSC2N_ChkCRCN(0)) //111005
#else
   if(1)
#endif  
  
//111005   if(CheckSSC2CRC())
   {
   
    SetRunCommandSSC2(); //if comment - ok //hier only set to run - it is interrupt
   // SetPB19();
//#ifdef TEST_PRINT_SPI     
//    printfp("\n\r >CRC Ok...  :");
//#endif
//   AT91F_SSC_DisableTx (SPI_ptr); 
 //  ToPdcTspi(0x33); //t
  // OperateBuffers_SPIt();
 //  ToPdcTspi(0x44);
 //do not get some   SPI_ptr->THR = 0x44;
   }
   else
   {
 //   printfp("\n\r >CRC Bad..Do Not Set :");
     current_command_state = WAITING_COMMAND;
 
   } 
       
    //  printfpd("%02X", *pData);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{ 
    
 //     current_command_state = WAITING_COMMAND;

  // } 
    
  //  current_command_counter = 0; //
    return 0;
  }
  
//  else if(current_command_counter >= CommandLength[current_command_type])//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  {
  //  RunCommandSPI(); //hier only set to run - it is interrupt
   // SetPB19();
  //      printfp("  >= CommandLength; current_command_type :");
   //   printfpd("%02X", current_command_type);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{
    
      current_command_state = WAITING_COMMAND;

  // }
    
    current_command_counter = 0;
    return 0;
  }
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
            &&  (current_command_state == RUN_COMMAND))

  { 
 //  printfp("\n\r adding data to buffer");
    currentntommand_data[current_command_data_counter++] = *pData;
//    embMsgSPI_Add(*pData);
  }


 return 0; 
}
   */

extern "C" unsigned char ReadDataspi(unsigned char * pData, unsigned long cnt_data)
{

//return;

//#ifdef IncEmbRS485 
unsigned char  SetChar;  

//if(GetTestMode() != PIPE_MODE)
//{ 


// cnt_data<<=2; //110914 - try use 32 bit receive
 
//#ifdef TEST_PRINT_SPI 
// printfp("\n\r r:");
// printfpd("%d",cnt_data);
//#endif // TEST_PRINT_SPI
//111212  current_command_counter = 0; //110919

unsigned char ret = 0;

if(cnt_data)   //110914
////ile(cnt_data--)
for(unsigned long cntchr = 0l; cntchr < cnt_data; cntchr++)
{
    ret = OperateCommand(pData);
 //   pData++;
#ifdef TEST_PRINT_SPI    
  SetChar =  * pData;//++;
  printfpd("=%02X", SetChar);
#endif  
    pData++;
 //  SPIBuff_Add(SetChar);
//t110704   SPIBuff_Add(* pData++);
   
 //   printfpd("=%02X", SetChar);

//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
}
//}
//else
//{
//while(cnt_data--)
//{
//#ifdef USART0_TRY_PDC_1T

//   ToPdcTu0(* pData++);

//#endif


//}

//}
//#endif 

return ret;

}

unsigned char ReadDataspiPolled(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
unsigned char  SetChar;  

//if(GetTestMode() != PIPE_MODE)
//{ 

//return;
// cnt_data<<=2; //110914 - try use 32 bit receive
 
//#ifdef TEST_PRINT_SPI 
 //printfp("\n\r rp:");
// printfpd("%d",cnt_data);
//#endif // TEST_PRINT_SPI
//  current_command_counter = 0; //110919

unsigned char ret = 0;

if(cnt_data)   //110914
////ile(cnt_data--)
for(unsigned long cntchr = 0l; cntchr < cnt_data; cntchr++)
{
SetChar =  * pData;
    ret = OperateCommandPolled(pData);
    pData++;
 //  SetChar =  * pData++;
 //  SPIBuff_Add(SetChar);
//t110704   SPIBuff_Add(* pData++);
#ifdef TEST_PRINT_SPI   
     printfpd("\n\r_%02X", SetChar);
#endif
//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
}
//}
//else
//{
//while(cnt_data--)
//{
//#ifdef USART0_TRY_PDC_1T

//   ToPdcTu0(* pData++);

//#endif


//}

//}
//#endif 

return ret;

}

extern "C" unsigned char ReadDatassc2_Polled(unsigned char * pData, unsigned long cnt_data)
{
//return;
//#ifdef IncEmbRS485 
unsigned char  SetChar;  

//if(GetTestMode() != PIPE_MODE)
//{ 


// cnt_data<<=2; //110914 - try use 32 bit receive
 
#ifdef TEST_PRINT_SSC2 
// printfp("\n\r receive : ");
// printfpd("%d",cnt_data);
#endif // TEST_PRINT_SSC2
  current_command_counter = 0; //110919

unsigned char ret = 0;

if(cnt_data)   //110914
while(cnt_data--)
{
   ret |= OperateCommandPolled( pData);
   SetChar =  * pData;
    pData++;
 //  SSC2Buff_Add(SetChar);
//t110704   SSC2Buff_Add(* pData++);
#ifdef TEST_PRINT_SPI    
     printfpd("_%02X", SetChar);
#endif     

//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
}
//}
//else
//{
//while(cnt_data--)
//{
//#ifdef USART0_TRY_PDC_1T

//   ToPdcTu0(* pData++);

//#endif


//}

//}
//#endif 

return ret;

}



#ifdef PROG_PRM_PCH_SPI_STEND
unsigned char ReadDataspi_stend(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
//unsigned char  SetChar;  

//if(GetTestMode() != PIPE_MODE)
//{ 


// cnt_data<<=2; //110914 - try use 32 bit receive
 
//#ifdef TEST_PRINT_SPI 
// printfp("\n\r r:");
// printfpd("%d",cnt_data);
//#endif // TEST_PRINT_SPI
//  current_command_counter = 0; //110919

unsigned char ret = 0;

//return;//t111027

if(cnt_data)   //110914
while(cnt_data--)
{

//     printfpd(" %02X", *pData);
     OperateCommand_stend( pData++);
 //  SetChar =  * pData++;
 //  SPIBuff_Add(SetChar);
//t110704   SPIBuff_Add(* pData++);
   
 //t110624    printfpd("_%02X", SetChar);

//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
}
//}
//else
//{
//while(cnt_data--)
//{
//#ifdef USART0_TRY_PDC_1T

//   ToPdcTu0(* pData++);

//#endif


//}

//}
//#endif 

return ret;

}
#endif

#define SPI_RDRF  (1l)

unsigned char OperateBuffers_SPI1(void)
{
//#ifdef TEST_TRANSMIT_FROM_SSC1
#ifdef TEST_PRINT_SPI 
//if(!use_standard_protocol)
//printfp(".");
#endif



 unsigned char ret = 0;
 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
 SPI_ptr =  (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

 unsigned long byte_cnt;
 unsigned long spi_sr = SPI_ptr->SR; 
 
  // printfpd("SR %lX", spi_sr); 
 
// if(!(spi_sr & (unsigned long)SPI_RDRF))
//  {
 // printfpd("SR %lX", spi_sr);  
//  return; //111017
//  }
 
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
byte_cnt = SPI_ptr->PDC.RCR;
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcspi)
 {
  if(byte_cnt < SPI_RX_BUFFER1) //receive some; more not can be
   {
#ifdef TEST_PRINT_SPI 
 //   printfpd("\n\r 1: %d",byte_cnt); 
#endif  
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buff1spi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 1;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ret |= ReadDataspi((unsigned char *)&Buffspi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
  }
 else
 {
 if(byte_cnt < SPI_RX_BUFFER1)
   {
#ifdef TEST_PRINT_SPI 
 //   printfpd("\n\r 2: %d",byte_cnt); 
#endif
 
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buffspi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 0;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ret |= ReadDataspi((unsigned char *)&Buff1spi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
   }
 return ret;
}

unsigned char OperateBuffers_SPI1_Polled(void)
{

//do not get some return; //t

//#ifdef TEST_TRANSMIT_FROM_SSC1
#ifdef TEST_PRINT_SPI 

//if(!use_standard_protocol)
printfp("$");
#endif



 unsigned char ret = 0;
 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
 SPI_ptr =  (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

 unsigned long byte_cnt;
 unsigned long spi_sr = SPI_ptr->SR; 
 
  // printfpd("SR %lX", spi_sr); 
 
// if(!(spi_sr & (unsigned long)SPI_RDRF))
//  {
 // printfpd("SR %lX", spi_sr);  
//  return; //111017
//  }
 
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
byte_cnt = SPI_ptr->PDC.RCR;
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcspi)
 {
  if(byte_cnt < SPI_RX_BUFFER1) //receive some; more not can be
   {
#ifdef TEST_PRINT_SPI 
 //   printfpd("\n\r 1: %d",byte_cnt); 
#endif  
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buff1spi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 1;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ret |= ReadDataspiPolled((unsigned char *)&Buffspi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
  }
 else
 {
 if(byte_cnt < SPI_RX_BUFFER1)
   {
#ifdef TEST_PRINT_SPI 
 //   printfpd("\n\r 2: %d",byte_cnt); 
#endif
 
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buffspi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 0;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ret |= ReadDataspiPolled((unsigned char *)&Buff1spi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
   }
 return ret;
}

unsigned char OperateBuffers_SSC2_Polled(void)
{
#ifdef TEST_TRANSMIT_FROM_SSC1
//printf(" OB");
#endif
 unsigned char ret = 0;
 AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
 SSC2_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;

 unsigned long byte_cnt;
SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
byte_cnt = SSC2_ptr->PDC.RCR;
SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcssc2)
 {
  if(byte_cnt < SSC2_RX_BUFFER) //receive some; more not can be
   {
 //   printfpd("\n\r 1: %d",byte_cnt); 
    SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SSC2_ptr->PDC.RCR;
    SSC2_ptr->PDC.RPR = (uint_32)&Buff1ssc2[0];
    SSC2_ptr->PDC.RCR = SSC2_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcssc2 = 1;
    SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ret |= ReadDatassc2((unsigned char *)&Buffssc2[0], (SSC2_RX_BUFFER - byte_cnt));
   }
  }
 else
 {
 if(byte_cnt < SSC2_RX_BUFFER)
   {
//    printfpd("\n\r 2: %d",byte_cnt); 
    SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SSC2_ptr->PDC.RCR;
    SSC2_ptr->PDC.RPR = (uint_32)&Buffssc2[0];
    SSC2_ptr->PDC.RCR = SSC2_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcssc2 = 0;
    SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ret |= ReadDatassc2((unsigned char *)&Buff1ssc2[0], (SSC2_RX_BUFFER - byte_cnt));
   }
   }
 return ret;
}



#ifdef PROG_PRM_PCH_SPI_STEND

unsigned char OperateBuffers_SPI1_stend(void)
{
//#ifdef TEST_TRANSMIT_FROM_SSC1
//#ifdef TEST_PRINT_SPI 

//if(!use_standard_protocol)
//printfp(".");
//#endif



 unsigned char ret = 0;
 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
 SPI_ptr =  (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

 unsigned long byte_cnt;
 unsigned long spi_sr = SPI_ptr->SR; 
 
  // printfpd("SR %lX", spi_sr); 
 
// if(!(spi_sr & (unsigned long)SPI_RDRF))
//  {
 // printfpd("SR %lX", spi_sr);  
//  return; //111017
//  }
 
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
byte_cnt = SPI_ptr->PDC.RCR;
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcspi)
 {
  if(byte_cnt < SPI_RX_BUFFER1) //receive some; more not can be
   {
#ifdef TEST_PRINT_SPI 
 //   printfpd("\n\r 1: %d",byte_cnt); 
#endif  
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buff1spi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 1;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ret |= ReadDataspi_stend((unsigned char *)&Buffspi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
  }
 else
 {
 if(byte_cnt < SPI_RX_BUFFER1)
   {
#ifdef TEST_PRINT_SPI 
  //  printfpd("\n\r 2: %d",byte_cnt); 
#endif
 
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SPI_ptr->PDC.RCR;
    SPI_ptr->PDC.RPR = (uint_32)&Buffspi[0];
    SPI_ptr->PDC.RCR = SPI_RX_BUFFER1; //USART0_RX_BUFFER;
    flag_pdcspi = 0;
    SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ret |= ReadDataspi_stend((unsigned char *)&Buff1spi[0], (SPI_RX_BUFFER1 - byte_cnt));
   }
   }
 return ret;
}

#endif
 
//_______________________________________________pdc usart to ssc_



 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/


#define SPI_TX_BUFFER1 200  

unsigned char Buffspit[SPI_TX_BUFFER1]; //buffer
unsigned char Buff1spit[SPI_TX_BUFFER1]; //buffer
unsigned long  cntBuffspit, cntBuff1spit;
unsigned char *  pBuffspit;
unsigned char * pBuff1spit;
unsigned char flag_pdcspit;

//#pragma BSS()


  
void enableTxPdcSPI1()
{

 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
  SPI_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;


  SPI_ptr->PDC.TPR = (uint_32)&Buffspit[0];
  SPI_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcspit = 0;
    pBuffspit = &Buffspit[0];   //need init!!!!!!
    cntBuffspit = 0;
    pBuff1spit = &Buff1spit[0];   //need init!!!!!!
    cntBuff1spit = 0;


  SPI_ptr->PDC.TNPR = (uint_32)&Buff1spit[0];
  SPI_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
   /* Enable PDC Receive Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
//ok return; //t    
//   typedef volatile struct at91rm9200_pdc_reg_struct
//{
 //  uint_32	RPR;			/* Receive Pointer Register */
 //  uint_32	RCR;			/* Receive Counter Register */
 //  uint_32	TPR;			/* Transmit Pointer Register */
 //  uint_32	TCR;			/* Transmit Counter Register */
 //  uint_32	RNPR;			/* Receive Next Pointer Register */
 //  uint_32	RNCR;			/* Receive Next Counter Register */
 //  uint_32	TNPR;			/* Transmit Next Pointer Register */
 //  uint_32	TNCR;			/* Transmit Next Counter Register */
 //  uint_32	PTCR;			/* PDC Transfer Control Register */
 //  uint_32	PTSR;			/* PDC Transfer Status Register */
      
//} AT91RM9200_PDC_REG_STRUCT, _PTR_ AT91RM9200_PDC_REG_STRUCT_PTR;
 
 
  /* Interrupt when transmission to receive buffer is completed */
 //    SPI_ptrtrIER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INTNTNABLE;        //100226   
//110621   SPI_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SPI_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//t100227     usart0_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
  
//#ifdef PROG_PRM_PCH_N
//    SetUsart0BaudRate(921600l);
//#else 
//    SetUsart0BaudRate(38400l); 
//#endif //PROG_PRM_PCH_L




}



void ToPdcTspi(unsigned char ch1t)
{
 //printfp("ToPdcTspi");

 if(!flag_pdcspit)
 {
  if(cntBuffspit < SPI_TX_BUFFER1)
     {

     *pBuffspit++ = ch1t;    //need init!!!!!!
     cntBuffspit++;
     }
 }
 else
 { 
  if(cntBuff1spit < SPI_TX_BUFFER1)
     {
     *pBuff1spit++ = ch1t;   //need init!!!!!!
     cntBuff1spit++;
     }
 }
 
}



unsigned char OperateBuffers_SPIt1(void)
{
 //printfp(" OB_SPIt");

 AT91RM9200_SPI_REG_STRUCT_PTR         SPI_ptr;
  SPI_ptr = (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
 
 unsigned long byte_cnt;
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = SPI_ptr->PDC.TCR;
SPI_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 

  if(byte_cnt)  return byte_cnt; //pdc is not finished transmit
  
 if(cntBuffspit)
 {
//    SPI_ptr->PDC.TPR = (uint_32)&Buffspit[0];
//    SPI_ptr->PDC.TCR = cntBuffspit;
    
    pBuffspit = &Buffspit[0];   //need init!!!!!!
//    cntBuffspit = 0;
    flag_pdcspit = 1;
    SPI_ptr->PDC.TPR = (uint_32)&Buffspit[0];
    SPI_ptr->PDC.TCR = cntBuffspit;    
    cntBuffspit = 0;
    
    return 0;
 }
 
 if(cntBuff1spit)
 {
  //  SPI_ptr->PDC.TPR = (uint_32)&Buff1spit[0];
  //  SPI_ptr->PDC.TCR = cntBuff1spit;
    
    pBuff1spit = &Buff1spit[0];   //need init!!!!!!
//    cntBuff1spit = 0;
    flag_pdcspit = 0;
    SPI_ptr->PDC.TPR = (uint_32)&Buff1spit[0];
    SPI_ptr->PDC.TCR = cntBuff1spit;
    cntBuff1spit = 0;
    return 0;
 }

}

extern "C" void KeepParams()
{
   
}


#endif //USE_SPI






