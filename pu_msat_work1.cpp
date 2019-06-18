//file : pu_msat_work1.cpp

typedef struct _AT91S_SPI {
	unsigned long	 SPI_CR; 	// Control Register
	unsigned long	 SPI_MR; 	// Mode Register
	unsigned long	 SPI_RDR; 	// Receive Data Register
	unsigned long	 SPI_TDR; 	// Transmit Data Register
	unsigned long	 SPI_SR; 	// Status Register
	unsigned long	 SPI_IER; 	// Interrupt Enable Register
	unsigned long	 SPI_IDR; 	// Interrupt Disable Register
	unsigned long	 SPI_IMR; 	// Interrupt Mask Register
	unsigned long	 Reserved0[4]; 	// 
	unsigned long	 SPI_CSR[4]; 	// Chip Select Register
	unsigned long	 Reserved1[48]; 	// 
	unsigned long	 SPI_RPR; 	// Receive Pointer Register
	unsigned long	 SPI_RCR; 	// Receive Counter Register
	unsigned long	 SPI_TPR; 	// Transmit Pointer Register
	unsigned long	 SPI_TCR; 	// Transmit Counter Register
	unsigned long	 SPI_RNPR; 	// Receive Next Pointer Register
	unsigned long	 SPI_RNCR; 	// Receive Next Counter Register
	unsigned long	 SPI_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 SPI_TNCR; 	// Transmit Next Counter Register
	unsigned long	 SPI_PTCR; 	// PDC Transfer Control Register
	unsigned long	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;

   
#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0xFFFE0000) // (SPI) Base Address
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS       ((unsigned int) 0x1 <<  1) // (SPI) SPI Disable

#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS3 %0111 */
/* 
struct PUM100S1
{
 unsigned char SatSet0r0;	//processing freq
 unsigned char SatSet0r1;	//processing freq
 unsigned char SatSet0r2;	//processing freq
 unsigned char SatSet0r3;	//processing freq

 unsigned char SatSet1r0;   //system delay
 unsigned char SatSet1r1;   //system delay
 unsigned char SatSet1r2;   //system delay
 unsigned char SatSet1r3;   //system delay

 unsigned char SatSet2r0;   //output level
 unsigned char SatSet3r0;
 unsigned char SatSet3r1; //debug keys
 unsigned char SatSet4r0;
 unsigned char SatSet4r1; 
 unsigned char SatSet4r2;  //transmit frequency
 unsigned char SatSet5r0;
 unsigned char SatSet5r1; 
 unsigned char SatSet5r2;  //receive frequency
 unsigned char SatSet6r0;  //transmit bound
 unsigned char SatSet7r0;  //receive bound
 unsigned char SatSet8r0;  
 unsigned char SatSet8r1;  //processing offset
 unsigned char SatTestModer0;  //sattestmode
 unsigned char SatPCr0;        //debug mode
 unsigned char SatTimingr0;  //timing
 unsigned char SatSoundr0;  //timing        ____25


//___________________________________________________140902
//MDataV	SatExtLock;
   unsigned char  SatExtLockr0;
//MDataV	SatExtLockP;
   unsigned char  SatExtLockPr0;
//#endif
//MDataV	SatLowP;
   unsigned char  SatLowPr0;
//MDataV	SatALev;
   unsigned char  SatALevr0;
//MDataC	SatACode;
//MDataV	SatADemo;
   unsigned char  SatADemor0;
//MDataC	SatACnt;
   unsigned char  SatACntr0;
   unsigned char  SatACntr1;
   unsigned char  SatACntr2;
   unsigned char  SatACntr3;
//#ifdef YOURNAL
//MDataS	LogStr0;
//MDataS	LogStr1;
//MDataV	LogClear;
   unsigned char  LogClearr0;
//#endif
//#ifdef USE_HTTP
//MDataC	WebPassword;
   unsigned char  WebPasswordr0;
   unsigned char  WebPasswordr1;
   unsigned char  WebPasswordr2;
   unsigned char  WebPasswordr3;
//___________________________________________________ +14 bytes


 unsigned char SatGet1r0;  //freq offset  
 unsigned char SatGet1r1;  //freq offset  
 unsigned char SatGet1r2;  //freq offset  
 unsigned char SatGet1r3;  //freq offset  
     
 unsigned char SatGet2r0;  //channel delay    
 unsigned char SatGet2r1;  //channel delay    
 unsigned char SatGet2r2;  //channel delay    
 unsigned char SatGet2r3;  //channel delay   




 unsigned char SatGet3r0;  //if balance       
 unsigned char SatInputr0;  //if down link     
 unsigned char SatLockr0;  //lock             
 unsigned char SatSearchr0;  //if up link	 ____37=>	 51
 };

union UPUM100S1
{
   PUM100S1 pum100s1;
   unsigned char byte[LEN_PUM100S1];
};
 

extern UPUM100S1 dev1;
*/
//#include "pum100s1.cpp"


unsigned int SpiWriteN2 ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1
	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;


//select needed flash:
//		test
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS1_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
 
	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->sc->ata_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
   	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}

unsigned int SpiWriteCS2 ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;

AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
//select needed flash:
//		test
 		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;

		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
   	   	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);



	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		A/		A_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
 //101113  	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));
																
    delay_mcs(1000); //101113

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}





extern "C" void SendToDDS(unsigned long len, unsigned long pData)
{
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */
// SetLed3(0); //get off led 3
//______________________________________________for test
#ifdef	 TEST_PRM_PCH_N_2
long len1 = len;
unsigned char* pPr = (unsigned char * )pData;
//printf("\n\r DDS:");
while(len1--)
{
//printf(" %02X", *pPr++);
}
#endif
//______________________________________________




// SpiWriteN2 ( len,  pData);
 SpiWriteCS2 ( len,  pData);





}

unsigned int SpiWriteCS3 ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




	static char RxBuff[32];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;

AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
//select needed flash:
//		test
 		AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;

		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
   	   	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS3_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);



	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
  //	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
  // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
   
   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR =(unsigned long)RxBuff; //(unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = pData; //(unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = len;//pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = len; //pDesc->tx_cmd_size;

   //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
  //	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
 //		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
   //		A/		A_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
   //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
 //101113  	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));
																
    delay_mcs(1000); //101113

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	


//   	pDesc->state = IDLE;

//	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
//		return AT91C_DATAFLASH_ERROR;
//	}
	   
  //	return AT91C_DATAFLASH_OK;
 
 // delay_mcs(50);
 // 	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS;
 //  AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;   //csoff
 //  AT91C_BASE_SPI->SPI_MR |= AT91C_SPI_PCS;	//no cs
//  delay_mcs(50);
	return 1;
}



extern "C" void SendToDDS3(unsigned long len, unsigned long pData)
{
// AT91PS_DataflashDesc pDesc;
/*
unsigned long no_hangt = NO_HANGT_VAL;
while((!(SpiWriteN2 ( len,  pData))) && no_hangt--);
 */
// SetLed3(0); //get off led 3
//______________________________________________for test
#ifdef	 TEST_PRM_PCH_N_2
long len1 = len;
unsigned char* pPr = (unsigned char * )pData;
//printf("\n\r DDS:");
while(len1--)
{
//printf(" %02X", *pPr++);
}
#endif
//______________________________________________




// SpiWriteN2 ( len,  pData);
 SpiWriteCS3 ( len,  pData);





}

#define FILTER_SEND_SIZE	(6)

extern "C" void LoadFilter(unsigned char cs, unsigned char data)
{
//printfp("\n\r LoadFilter");
//printfpd(" %d>", cs);
//printfpd(" 0x%X", data);

  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  unsigned char mask = 1;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //ce
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //ld
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //le0
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //le1
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //le2

   pio_ptr->SODR = MASK_BIT_19 |  MASK_BIT_18 |MASK_BIT_17 |MASK_BIT_14 | MASK_BIT_13;


	data -=  1; // enabled values 1...30  0 - for 1 MHz
	data <<= 1;
	data +=  1; //write bit

switch (cs)
{
  case 0 : 	  pio_ptr->CODR = MASK_BIT_17; break;
  case 1 : 	  pio_ptr->CODR = MASK_BIT_18; break;
  case 2 : 	  pio_ptr->CODR = MASK_BIT_19; break;
  default :   break;
}

		for(unsigned j = 0; j < FILTER_SEND_SIZE; j++)
		{
		   pio_ptr->CODR  = MASK_BIT_13;
		//   delay_mcs(2);
		   if(data & mask)   pio_ptr->SODR  = MASK_BIT_14;
		   else  pio_ptr->CODR  = MASK_BIT_14;
	       delay_mcs(2);
	       pio_ptr->SODR  = MASK_BIT_13;
		   delay_mcs(2);
		   mask <<= 1;
		}
delay_mcs(2);

 switch (cs)
{
  case 0 : 	  pio_ptr->SODR = MASK_BIT_17; break;
  case 1 : 	  pio_ptr->SODR = MASK_BIT_18; break;
  case 2 : 	  pio_ptr->SODR = MASK_BIT_19; break;
  default :   break;
}



}

extern "C" void ResetPult(void)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);

   pio_ptr->SODR = MASK_BIT_20;
   delay_mcs(10);
   pio_ptr->CODR = MASK_BIT_20;
   delay_mcs(10);
   pio_ptr->SODR = MASK_BIT_20;

}


extern "C" void SetTxLevel(unsigned char level)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 25, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 26, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 27, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //

   pio_ptr->CODR = MASK_BIT_24 |  MASK_BIT_25 | MASK_BIT_26 | MASK_BIT_27 
   						| MASK_BIT_28 | MASK_BIT_29;

 //  pio_ptr->SODR = (level & 0x2f) <<  24;
   pio_ptr->SODR = (level & 0x3f) <<  24;

}

extern "C" void InitOBusWR()
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //data
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //


   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //ale	 address enable
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //wr	 write data
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO,1);	  //rd	 read data
}

extern "C" void InitOBusRD()
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //data
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 0);	  //


   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //ale	 address enable
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);	  //wr	 write data
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO,1);	  //rd	 read data
}


extern "C" void SetAddr(unsigned char addr)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

  InitOBusWR();

  pio_ptr->SODR = MASK_BIT_8;//ale to one
  pio_ptr->SODR = MASK_BIT_9;//wr to one
  pio_ptr->SODR = MASK_BIT_10;//rd to one

  delay_mcs(2);

  if(addr & MASK_BIT_0)  pio_ptr->SODR = MASK_BIT_0; else  	 pio_ptr->CODR = MASK_BIT_0;
  if(addr & MASK_BIT_1)  pio_ptr->SODR = MASK_BIT_1; else  	 pio_ptr->CODR = MASK_BIT_1;
  if(addr & MASK_BIT_2)  pio_ptr->SODR = MASK_BIT_2; else  	 pio_ptr->CODR = MASK_BIT_2;
  if(addr & MASK_BIT_3)  pio_ptr->SODR = MASK_BIT_3; else  	 pio_ptr->CODR = MASK_BIT_3;
  if(addr & MASK_BIT_4)  pio_ptr->SODR = MASK_BIT_4; else  	 pio_ptr->CODR = MASK_BIT_4;
  if(addr & MASK_BIT_5)  pio_ptr->SODR = MASK_BIT_5; else  	 pio_ptr->CODR = MASK_BIT_5;
  if(addr & MASK_BIT_6)  pio_ptr->SODR = MASK_BIT_6; else  	 pio_ptr->CODR = MASK_BIT_6;
  if(addr & MASK_BIT_7)  pio_ptr->SODR = MASK_BIT_7; else  	 pio_ptr->CODR = MASK_BIT_7;

  delay_mcs(2);
  pio_ptr->CODR = MASK_BIT_8;  //ale to zero
  delay_mcs(2);
  pio_ptr->SODR = MASK_BIT_8; //ale to one
  delay_mcs(2);

}






extern "C" void WriteIOBus(unsigned char addr, unsigned char data)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

  SetAddr(addr);

  if(data & MASK_BIT_0)  pio_ptr->SODR = MASK_BIT_0; else  	 pio_ptr->CODR = MASK_BIT_0;
  if(data & MASK_BIT_1)  pio_ptr->SODR = MASK_BIT_1; else  	 pio_ptr->CODR = MASK_BIT_1;
  if(data & MASK_BIT_2)  pio_ptr->SODR = MASK_BIT_2; else  	 pio_ptr->CODR = MASK_BIT_2;
  if(data & MASK_BIT_3)  pio_ptr->SODR = MASK_BIT_3; else  	 pio_ptr->CODR = MASK_BIT_3;
  if(data & MASK_BIT_4)  pio_ptr->SODR = MASK_BIT_4; else  	 pio_ptr->CODR = MASK_BIT_4;
  if(data & MASK_BIT_5)  pio_ptr->SODR = MASK_BIT_5; else  	 pio_ptr->CODR = MASK_BIT_5;
  if(data & MASK_BIT_6)  pio_ptr->SODR = MASK_BIT_6; else  	 pio_ptr->CODR = MASK_BIT_6;
  if(data & MASK_BIT_7)  pio_ptr->SODR = MASK_BIT_7; else  	 pio_ptr->CODR = MASK_BIT_7;

  delay_mcs(2);
  pio_ptr->CODR = MASK_BIT_9;  //wr to zero
  delay_mcs(2);
  pio_ptr->SODR = MASK_BIT_9; //wr to one
  delay_mcs(2);
}

extern "C" unsigned char ReadIOBus(unsigned char addr)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 unsigned char ret;
 SetAddr(addr);
 delay_mcs(2);
 InitOBusRD();
 pio_ptr->CODR = MASK_BIT_10;  //rd to zero
 delay_mcs(2);
 ret = (unsigned char)pio_ptr->PDSR;
 pio_ptr->SODR = MASK_BIT_10;  //rd to one
 return ret;
}
	/*
	    strcpy(cSatSet0   ,"  Min Distance  :       ");
		strcpy(cSatSet1   ,"  Max Distance  :       ");
		strcpy(cSatSet2   ,"  Output Level  :       ");
		strcpy(cSatSet3   ,"  Averated Distance :   ");
		strcpy(cSatSet4   ,"  Transmit Frequency :  ");
		strcpy(cSatSet5   ,"  Receive Frequency :   ");
		strcpy(cSatSet6   ,"  Transmit Bound:       ");
		strcpy(cSatSet7   ,"  Receive Bound :       ");

	  */

/*
#define	 MIN_SATSET0	(0)
#define	 MAX_SATSET0	(511)
#define	 MIN_SATSET1	(0)
#define	 MAX_SATSET1	(511)
#define	 MIN_SATSET2	(0)
#define	 MAX_SATSET2	(255)
#define	 MIN_SATSET3	(0)
#define	 MAX_SATSET3	(511)
#define	 MIN_SATSET4	(400)	 // 100000
#define	 MAX_SATSET4	(1000)	 // 100000
#define	 MIN_SATSET5	(400)	// 100000
#define	 MAX_SATSET5	(1000)	 //100000
#define	 MIN_SATSET6	(1)
#define	 MAX_SATSET6	(30)  //1000000
#define	 MIN_SATSET7	(1)
#define	 MAX_SATSET7	(30)   //1000000

#define	 MIN_SATTESTMODE	(0)
#define	 MAX_SATTESTMODE	(1)

#define	 MIN_SATPC	(0)
#define	 MAX_SATPC	(1)

#define	 MIN_SATINPUT	(0)
#define	 MAX_SATINPUT	(1)

#define	 MIN_SATLOCK	(0)
#define	 MAX_SATLOCK	(1)

#define	 MIN_SATSEARCH	(0)
#define	 MAX_SATSEARCH	(1)
*/







extern "C" void CheckRestoringData()
{
#ifdef YOURNAL
 LogStr0.ModifyDown(LogStr0.CntNum); //LogStr1 modifed into
#endif

if ((SatSet0.Value < MIN_SATSET0) || (SatSet0.Value > MAX_SATSET0))	
 {
 SatSet0.Value = MIN_SATSET0;
 SatSet0.ChangingValue = MIN_SATSET0;
 }

if ((SatSet1.Value < MIN_SATSET1) || (SatSet1.Value > MAX_SATSET1))	
 {


 SatSet1.Value = MIN_SATSET1;
 SatSet1.ChangingValue = MIN_SATSET1;

// printfpd("\n\r d : %ld", SatSet1.Value);
 }

if ((SatSet2.Value < (float64)MIN_SATSET2) || (SatSet2.Value > (float64)MAX_SATSET2))	
 {
 SatSet2.Value = MIN_SATSET2;
 SatSet2.ChangingValue = MIN_SATSET2;
 }

if ((SatSet3.Value < MIN_SATSET3) || (SatSet3.Value > MAX_SATSET3))	
 {
 SatSet3.Value = MIN_SATSET3;
 SatSet3.ChangingValue = MIN_SATSET3;
 }

if ((SatSet4.Value < MIN_SATSET4) || (SatSet4.Value > MAX_SATSET4))	
 {
 SatSet4.Value = MIN_SATSET4;
 SatSet4.ChangingValue = MIN_SATSET4;
 }

if ((SatSet5.Value < MIN_SATSET5) || (SatSet5.Value > MAX_SATSET5))	
 {
 SatSet5.Value = MIN_SATSET5;
 SatSet5.ChangingValue = MIN_SATSET5;
 }

if ((SatSet6.Value < MIN_SATSET6) || (SatSet6.Value > MAX_SATSET6))	
 {
 SatSet6.Value = MIN_SATSET6;
 SatSet6.ChangingValue = MIN_SATSET6;
 }

if ((SatSet8.Value < MIN_SATSET8) || (SatSet8.Value > MAX_SATSET8))	
 {
 SatSet8.Value = MIN_SATSET8;
 SatSet8.ChangingValue = MIN_SATSET8;
 }

if ((SatSet7.Value < MIN_SATSET7) || (SatSet7.Value > MAX_SATSET7))	
 {
 SatSet7.Value = MIN_SATSET7;
 SatSet7.ChangingValue = MIN_SATSET7;
 }


if ((SatTestMode.Value < MIN_SATTESTMODE) || (SatTestMode.Value > MAX_SATTESTMODE))	
 {
 SatTestMode.Value = MIN_SATTESTMODE;
 SatTestMode.ChangingValue = MIN_SATTESTMODE;
 }

if ((SatTestModeI.Value < MIN_SATTESTMODEI) || (SatTestModeI.Value > MAX_SATTESTMODEI))	
 {
 SatTestModeI.Value = MIN_SATTESTMODEI;
 SatTestModeI.ChangingValue = MIN_SATTESTMODEI;
 }


if ((SatTiming.Value < MIN_SATTIMING) || (SatTiming.Value > MAX_SATTIMING))	
 {
 SatTiming.Value = MIN_SATTIMING;
 SatTiming.ChangingValue = MIN_SATTIMING;
 }


if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
 {
 SatPC.Value 		 = MIN_SATPC;
 SatPC.ChangingValue = MIN_SATPC;
 }


if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
 {
 SatPC.Value 		 = MIN_SATPC;
 SatPC.ChangingValue = MIN_SATPC;
 }
 /*
if ((SatInput.Value < MIN_SATINPUT) || (SatInput.Value > MAX_SATINPUT))	
 {
 SatInput.Value 		 = MIN_SATINPUT;
 SatInput.ChangingValue  = MIN_SATINPUT;
 }
	*/

if ((SatLock.Value < MIN_SATLOCK) || (SatLock.Value > MAX_SATLOCK))	
 {
 SatLock.Value 		 = MIN_SATLOCK;
 SatLock.ChangingValue  = MIN_SATLOCK;
 }

 /*
if ((SatSearch.Value < MIN_SATSEARCH) || (SatSearch.Value > MAX_SATSEARCH))	
 {
 SatSearch.Value 		 = MIN_SATSEARCH;
 SatSearch.ChangingValue  = MIN_SATSEARCH;
 }
   */
if ((SatXilBlock.Value < MIN_SATXILBLOCK) || (SatXilBlock.Value > MAX_SATXILBLOCK))	
 {
 SatXilBlock.Value 		 = MIN_SATXILBLOCK;
 SatXilBlock.ChangingValue  = MIN_SATXILBLOCK;
 }

if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
 {
 SatSound.Value = MIN_SATSOUND;
 SatSound.ChangingValue = MIN_SATSOUND;
 }

if ((SatDF.Value < MIN_SATDF) || (SatDF.Value > MAX_SATDF))	
 {
 SatDF.Value = MIN_SATDF;
 SatDF.ChangingValue = MIN_SATDF;
 }

if ((SatTF.Value < MIN_SATTF) || (SatTF.Value > MAX_SATTF))	
 {
 SatTF.Value = MIN_SATTF;
 SatTF.ChangingValue = MIN_SATTF;
 }

if ((SatRate.Value < MIN_SATRATE) || (SatRate.Value > MAX_SATRATE))	
 {
 SatRate.Value = MIN_SATRATE;
 SatRate.ChangingValue = MIN_SATRATE;
 }

if ((SatTimer.Value < MIN_SATTIMER) || (SatTimer.Value > MAX_SATTIMER))	
 {
 SatTimer.Value = MIN_SATTIMER;
 SatTimer.ChangingValue = MIN_SATTIMER;
 }

#ifdef RECEIVE_MOD_LOCK

if ((SatExtLock.Value < MIN_SATEXTLOCK) || (SatExtLock.Value > MAX_SATEXTLOCK))	
 {
 //printfpd("\n\rLV %d", SatExtLock.Value);
 SatExtLock.Value = MIN_SATEXTLOCK;
 SatExtLock.ChangingValue = MIN_SATEXTLOCK;
// printfpd("\n\rLV1 %d", SatExtLock.Value);
 }

if ((SatExtLockP.Value < MIN_SATEXTLOCKP) || (SatExtLockP.Value > MAX_SATEXTLOCKP))	
 {
// printfpd("\n\rLPV %d", SatExtLockP.Value);

 SatExtLockP.Value = MIN_SATEXTLOCKP;
 SatExtLockP.ChangingValue = MIN_SATEXTLOCKP;
 }

#endif

if ((SatLowP.Value < MIN_SATLOWP) || (SatLowP.Value > MAX_SATLOWP))	
 {
// printfpd("\n\rLPV %d", SatExtLockP.Value);

 SatLowP.Value = MIN_SATLOWP;
 SatLowP.ChangingValue = MIN_SATLOWP;
 }

if (((unsigned)SatALev.Value < (unsigned)MIN_SATALEV) || ((unsigned)SatALev.Value > (unsigned)MAX_SATALEV))	
 {
// printfpd("\n\r change SatALev.Value %d", SatALev.Value);

 SatALev.Value = MIN_SATALEV;
 SatALev.ChangingValue = MIN_SATALEV;
 }

 // printfpd("\n\SatADemo_s %d", SatADemo.Value);


if ((SatADemo.Value < MIN_SATADEMO) || (SatADemo.Value > MAX_SATADEMO))	
 {
 //printfpd("\n\SatADemo_c %d", SatADemo.Value);

 SatADemo.Value = MIN_SATADEMO;
 SatADemo.ChangingValue = MIN_SATADEMO;
 }


 SatACode.Value = 0;
 SatACode.ChangingValue = 0; //to do not view on display SatACode.Value;

// SatADemo.Value = 0;
// SatADemo.ChangingValue = SatADemo.Value;

// SatACnt.Value = 0;
// SatACnt.ChangingValue = SatACnt.Value;

  SatACnt.Value =  ONE_DAY_VALUE;	   //to do not clear satademo
  SatACnt.ChangingValue = SatACnt.Value;






//if ((SatFactory.Value < MIN_SATFACTORY) || (SatFactory.Value > MAX_SATFACTORY))	
// {
 SatFactory.Value = MIN_SATFACTORY;	 //at start olwais "No"
 SatFactory.ChangingValue = MIN_SATFACTORY;
// }
  SatSearch.Value =  MIN_SATSEARCH;
  SatSearch.ChangingValue =  MIN_SATSEARCH;

  SatInput.Value =  MIN_SATINPUT;
  SatInput.ChangingValue =  MIN_SATINPUT;



}


extern "C" void PrintSat()
{
//printfpd("\n\r %d", SatTF.ChangingValue);
//printfpd("\n\r %d", SatDF.ChangingValue);
}


extern "C" void CheckWEBData()
{

if ((SatSet0.Value < MIN_SATSET0) || (SatSet0.Value > MAX_SATSET0))	
 {
 SatSet0.Value = MIN_SATSET0;
 SatSet0.ChangingValue = MIN_SATSET0;
 }

if ((SatSet1.Value < MIN_SATSET1) || (SatSet1.Value > MAX_SATSET1))	
 {


 SatSet1.Value = MIN_SATSET1;
 SatSet1.ChangingValue = MIN_SATSET1;

// printfpd("\n\r d : %ld", SatSet1.Value);
 }

if ((SatSet2.Value < (float64)MIN_SATSET2) || (SatSet2.Value > (float64)MAX_SATSET2))	
 {
 SatSet2.Value = MIN_SATSET2;
 SatSet2.ChangingValue = MIN_SATSET2;
 }

if ((SatSet3.Value < MIN_SATSET3) || (SatSet3.Value > MAX_SATSET3))	
 {
 SatSet3.Value = MIN_SATSET3;
 SatSet3.ChangingValue = MIN_SATSET3;
 }

if ((SatSet4.Value < MIN_SATSET4) || (SatSet4.Value > MAX_SATSET4))	
 {
 SatSet4.Value = MIN_SATSET4;
 SatSet4.ChangingValue = MIN_SATSET4;
 }

if ((SatSet5.Value < MIN_SATSET5) || (SatSet5.Value > MAX_SATSET5))	
 {
 SatSet5.Value = MIN_SATSET5;
 SatSet5.ChangingValue = MIN_SATSET5;
 }

if ((SatSet6.Value < MIN_SATSET6) || (SatSet6.Value > MAX_SATSET6))	
 {
 SatSet6.Value = MIN_SATSET6;
 SatSet6.ChangingValue = MIN_SATSET6;
 }

if ((SatSet8.Value < MIN_SATSET8) || (SatSet8.Value > MAX_SATSET8))	
 {
 SatSet8.Value = MIN_SATSET8;
 SatSet8.ChangingValue = MIN_SATSET8;
 }

if ((SatSet7.Value < MIN_SATSET7) || (SatSet7.Value > MAX_SATSET7))	
 {
 SatSet7.Value = MIN_SATSET7;
 SatSet7.ChangingValue = MIN_SATSET7;
 }


if ((SatTestMode.Value < MIN_SATTESTMODE) || (SatTestMode.Value > MAX_SATTESTMODE))	
 {
 SatTestMode.Value = MIN_SATTESTMODE;
 SatTestMode.ChangingValue = MIN_SATTESTMODE;
 }

if ((SatTestModeI.Value < MIN_SATTESTMODEI) || (SatTestModeI.Value > MAX_SATTESTMODEI))	
 {
 SatTestModeI.Value = MIN_SATTESTMODEI;
 SatTestModeI.ChangingValue = MIN_SATTESTMODEI;
 }


if ((SatTiming.Value < MIN_SATTIMING) || (SatTiming.Value > MAX_SATTIMING))	
 {
 SatTiming.Value = MIN_SATTIMING;
 SatTiming.ChangingValue = MIN_SATTIMING;
 }


if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
 {
 SatPC.Value 		 = MIN_SATPC;
 SatPC.ChangingValue = MIN_SATPC;
 }


if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
 {
 SatPC.Value 		 = MIN_SATPC;
 SatPC.ChangingValue = MIN_SATPC;
 }
 /*
if ((SatInput.Value < MIN_SATINPUT) || (SatInput.Value > MAX_SATINPUT))	
 {
 SatInput.Value 		 = MIN_SATINPUT;
 SatInput.ChangingValue  = MIN_SATINPUT;
 }
	*/

if ((SatLock.Value < MIN_SATLOCK) || (SatLock.Value > MAX_SATLOCK))	
 {
 SatLock.Value 		 = MIN_SATLOCK;
 SatLock.ChangingValue  = MIN_SATLOCK;
 }

 /*
if ((SatSearch.Value < MIN_SATSEARCH) || (SatSearch.Value > MAX_SATSEARCH))	
 {
 SatSearch.Value 		 = MIN_SATSEARCH;
 SatSearch.ChangingValue  = MIN_SATSEARCH;
 }
   */
if ((SatXilBlock.Value < MIN_SATXILBLOCK) || (SatXilBlock.Value > MAX_SATXILBLOCK))	
 {
 SatXilBlock.Value 		 = MIN_SATXILBLOCK;
 SatXilBlock.ChangingValue  = MIN_SATXILBLOCK;
 }

if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
 {
 SatSound.Value = MIN_SATSOUND;
 SatSound.ChangingValue = MIN_SATSOUND;
 }

#ifdef YOURNAL
   LogClear.Value = MIN_LOGCLEAR;	
#endif
//if ((SatFactory.Value < MIN_SATFACTORY) || (SatFactory.Value > MAX_SATFACTORY))	
// {
// SatFactory.Value = MIN_SATFACTORY;	 //at start olwais "No"
// SatFactory.ChangingValue = MIN_SATFACTORY;
// }
//  SatSearch.Value =  MIN_SATSEARCH;
//  SatSearch.ChangingValue =  MIN_SATSEARCH;

//  SatInput.Value =  MIN_SATINPUT;
//  SatInput.ChangingValue =  MIN_SATINPUT;

 
#ifdef USE_HTTP
if ((WebPassword.Value < MIN_WEBPASSWORD) || (WebPassword.Value > MAX_WEBPASSWORD))	
 {
 WebPassword.Value = MAX_WEBPASSWORD;
 WebPassword.ChangingValue = MAX_WEBPASSWORD;
 }
#endif
 
if ((SatTF.Value < MIN_SATTF) || (SatTF.Value > MAX_SATTF))	
 {
 SatTF.Value = MIN_SATTF;
 SatTF.ChangingValue = MIN_SATTF;
 }

if ((SatRate.Value < MIN_SATRATE) || (SatRate.Value > MAX_SATRATE))	
 {
 SatRate.Value = MIN_SATRATE;
 SatRate.ChangingValue = MIN_SATRATE;
 }

if ((SatDF.Value < MIN_SATDF) || (SatDF.Value > MAX_SATDF))	
 {
 SatDF.Value = MIN_SATDF;
 SatDF.ChangingValue = MIN_SATDF;
 }

if ((SatTimer.Value < MIN_SATTIMER) || (SatTimer.Value > MAX_SATTIMER))	
 {
 SatTimer.Value = MIN_SATTIMER;
 SatTimer.ChangingValue = MIN_SATTIMER;
 }
 

}


#define DEF_SATSET0 (1234567)	  //processinf freq
#define DEF_SATSET1 (270.214)	  //system delay
#define DEF_SATSET2 ((float64)(25.0))	  //output level
//130409#define DEF_SATSET3 (0x400)	  //debug keys
#define DEF_SATSET3 (0x4)	  //debug keys
#define DEF_SATSET4 (70000)	  //transmit freq
#define DEF_SATSET5 (70000)	  //receive freq
#define DEF_SATSET6 (1)	  	  //transmit bound
#define DEF_SATSET7 (1)	  	  //receive bound
#define DEF_SATSET8 (300)	  	  //processing offset
#define	DEF_SATTESTMODE	 (0)	//test mode
#define	DEF_SATTIMING	 (0)	//uplink mode
#define	DEF_SATSOUND (1) //alarm satsound
#define	DEF_SATPC	 (0) //debug mode




extern "C" void SetFactoryData()
{

//if ((SatSet0.Value < MIN_SATSET0) || (SatSet0.Value > MAX_SATSET0))	
// {
 SatSet0.Value = DEF_SATSET0;
 SatSet0.ChangingValue = DEF_SATSET0;
// }

//if ((SatSet1.Value < MIN_SATSET1) || (SatSet1.Value > MAX_SATSET1))	
// {
 SatSet1.Value = DEF_SATSET1;
 SatSet1.ChangingValue = DEF_SATSET1;
//
// printfpd("\n\r d : %ld", SatSet1.Value);
// }

//if ((SatSet2.Value < (float64)MIN_SATSET2) || (SatSet2.Value > (float64)MAX_SATSET2))	
// {
 SatSet2.Value = DEF_SATSET2;
 SatSet2.ChangingValue = DEF_SATSET2;
// }

//if ((SatSet3.Value < MIN_SATSET3) || (SatSet3.Value > MAX_SATSET3))	
// {
 SatSet3.Value = DEF_SATSET3;
 SatSet3.ChangingValue = DEF_SATSET3;
// }

//if ((SatSet4.Value < MIN_SATSET4) || (SatSet4.Value > MAX_SATSET4))	
// {
 SatSet4.Value = DEF_SATSET4;
 SatSet4.ChangingValue = DEF_SATSET4;
// }

//if ((SatSet5.Value < MIN_SATSET5) || (SatSet5.Value > MAX_SATSET5))	
// {
 SatSet5.Value = DEF_SATSET5;
 SatSet5.ChangingValue = DEF_SATSET5;
// }

//if ((SatSet6.Value < MIN_SATSET6) || (SatSet6.Value > MAX_SATSET6))	
// {
 SatSet6.Value = DEF_SATSET6;
 SatSet6.ChangingValue = DEF_SATSET6;
// }

//if ((SatSet8.Value < MIN_SATSET8) || (SatSet8.Value > MAX_SATSET8))	
// {
 SatSet8.Value = DEF_SATSET8;
 SatSet8.ChangingValue = DEF_SATSET8;
// }

//if ((SatSet7.Value < MIN_SATSET7) || (SatSet7.Value > MAX_SATSET7))	
// {
 SatSet7.Value = DEF_SATSET7;
 SatSet7.ChangingValue = DEF_SATSET7;
// }


//if ((SatTestMode.Value < MIN_SATTESTMODE) || (SatTestMode.Value > MAX_SATTESTMODE))	
// {
 SatTestMode.Value = DEF_SATTESTMODE;
 SatTestMode.ChangingValue = DEF_SATTESTMODE;
// }

///if ((SatTestModeI.Value < MIN_SATTESTMODEI) || (SatTestModeI.Value > MAX_SATTESTMODEI))	
// {
// SatTestModeI.Value = MIN_SATTESTMODEI;
// SatTestModeI.ChangingValue = MIN_SATTESTMODEI;
// }


//if ((SatTiming.Value < MIN_SATTIMING) || (SatTiming.Value > MAX_SATTIMING))	
// {
 SatTiming.Value = DEF_SATTIMING;
 SatTiming.ChangingValue = DEF_SATTIMING;
// }


//if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
// {
 SatPC.Value 		 = DEF_SATPC;
 SatPC.ChangingValue = DEF_SATPC;
// }


//if ((SatPC.Value < MIN_SATPC) || (SatPC.Value > MAX_SATPC))	
// {
// SatPC.Value 		 = MIN_SATPC;
// SatPC.ChangingValue = MIN_SATPC;
// }

//if ((SatInput.Value < MIN_SATINPUT) || (SatInput.Value > MAX_SATINPUT))	
// {
 //SatInput.Value 		 = MIN_SATINPUT;
// SatInput.ChangingValue  = MIN_SATINPUT;
// }


//if ((SatLock.Value < MIN_SATLOCK) || (SatLock.Value > MAX_SATLOCK))	
// {
// SatLock.Value 		 = MIN_SATLOCK;
// SatLock.ChangingValue  = MIN_SATLOCK;
/// }


//if ((SatSearch.Value < MIN_SATSEARCH) || (SatSearch.Value > MAX_SATSEARCH))	
// {
// SatSearch.Value 		 = MIN_SATSEARCH;
// SatSearch.ChangingValue  = MIN_SATSEARCH;
// }

//if ((SatXilBlock.Value < MIN_SATXILBLOCK) || (SatXilBlock.Value > MAX_SATXILBLOCK))	
// {
// SatXilBlock.Value 		 = MIN_SATXILBLOCK;
// SatXilBlock.ChangingValue  = MIN_SATXILBLOCK;
 //}

//if ((SatSound.Value < MIN_SATSOUND) || (SatSound.Value > MAX_SATSOUND))	
// {
 SatSound.Value = DEF_SATSOUND;
 SatSound.ChangingValue = DEF_SATSOUND;
// }

//if ((SatFactory.Value < MIN_SATFACTORY) || (SatFactory.Value > MAX_SATFACTORY))	
// {
 SatFactory.Value = MIN_SATFACTORY;	 //at start olwais "No"
 SatFactory.ChangingValue = MIN_SATFACTORY;
// }

 SatDF.Value = MIN_SATDF;	 //at start olwais "No"
 SatDF.ChangingValue = MIN_SATDF;

 SatTF.Value = MIN_SATTF;	 //at start olwais "No"
 SatTF.ChangingValue = MIN_SATTF;

 SatRate.Value = MIN_SATRATE;
 SatRate.ChangingValue = MIN_SATRATE;


}



#define FREQ_PROC_ADDR (2)
#define SYS_DELAY_ADDR (3)
#define	STW_ADDR 	   (4)
#define	DEBUG_ADDR1    (5)
#define	DEBUG_ADDR2    (6)
#define	REZERV_ADDR    (7)
#define	STR_ADDR 	   (8)
#define	CHD_ADDR 	   (9)
#define	SWEEP_ADDR 	   (0xA)

extern "C" void SetAllUnch()
{
return; //130415 

#ifdef MAKET_PLATA
return;
#endif


SatSet0.Changable = 0;	  //processing frequency
SatSet1.Changable = 0;	
SatTestMode.Changable = 0;	
SatTiming.Changable = 0;
SatPC.Changable = 0;
SatSound.Changable = 0;
SatFactory.Changable = 0;
#ifdef YOURNAL
LogClear.Changable = 0;
#endif
}

extern "C" void SetAllCh()
{
SatSet0.Changable = 1;
SatSet1.Changable = 1;
SatTestMode.Changable = 1;	
SatTiming.Changable = 1;	
SatPC.Changable = 1;
SatSound.Changable = 1;
SatFactory.Changable = 1;
#ifdef YOURNAL
LogClear.Changable = 1;
#endif
}


#define DELAY_MASK	(0x3)
#define ST_SIZE	(10)

extern "C" void UpdateDataVal()
{
 unsigned char RGstr = 0;
 signed char RGsat = 0;
 signed char RGf = 0;
// signed char test = 0x81;
 //signed char test1 = -1;
 static float SRGstr[ST_SIZE];
 float tmp3;

 unsigned char tmp;
 float M;
 float DD;



static unsigned char cnt;
cnt++;

  SatGet0.Value = cnt & 0xffffl;   //doppler buffer state 
// if(!(cnt))
// {
//  printfpd(" %d", SatGet0.Value);
//   printfpd("%d", cnt);

// }
	 
 for(unsigned i = 0; i <= (ST_SIZE - 2); i++)
{
 SRGstr[i] =  SRGstr[i+1];
}

 RGstr = ReadIOBus(STR_ADDR);

 SRGstr[ST_SIZE - 1] = (float)(RGstr & 0xf);
   		 
  //	 RGstr = 0; //for test140227

 if(RGstr & MASK_BIT_7)
// if(1) //t
  {
  if(!SatLock.Value)
   {
#ifdef YOURNAL
     Add_Event(EV_LOCK, 0, NULL); //for test
#endif
   }

#ifdef LINE_LOCK
  SetOLock();
#endif

 SatLock.Value = 1;
 SatLock.ChangingValue = 1;
 }
 else{

 if(SatLock.Value)
   {
#ifdef YOURNAL
     Add_Event(EV_UNLOCK, 0, NULL); //for test
#endif
   }

#ifdef LINE_LOCK
 ClearOLock();
#endif

 SatLock.Value = 0;
 SatLock.ChangingValue = 0;

 		if(SatSound.Value)
 		{
		 Ring(1,1,5,4);
 		}

 }
dev1.pum100s1.SatLockr0 = (unsigned char)SatLock.Value;

//_________________________________________________


//_________________________________________________

 if(RGstr & MASK_BIT_6) {
#ifdef YOURNAL
 if(!SatInput.Value)
 {
   Add_Event(EV_DOWNLINK_LOST, 0, NULL);
 }
#endif

 SatInput.Value = 1;
 SatInput.ChangingValue = 1;
 }
 else{
 #ifdef YOURNAL
 if(SatInput.Value)
 {
   Add_Event(EV_DOWNLINK_AVAILABLE, 0, NULL);
 }
#endif

 SatInput.Value = 0;
 SatInput.ChangingValue = 0;
 }

dev1.pum100s1.SatInputr0 = (unsigned char)SatInput.Value;


 if(RGstr & MASK_BIT_5) {
#ifdef YOURNAL
 if(!SatSearch.Value)
 {
   Add_Event(EV_UPLINK_AVAILABLE, 0, NULL);
 }
#endif

 SatSearch.Value = 1;
 SatSearch.ChangingValue = 1;
 }
 else{
#ifdef YOURNAL
 if(SatSearch.Value)
 {
   Add_Event(EV_UPLINK_LOST, 0, NULL);
 }
#endif
 SatSearch.Value = 0;
 SatSearch.ChangingValue = 0;
 }
 dev1.pum100s1.SatSearchr0 = (unsigned char)SatSearch.Value;


if(RGstr & MASK_BIT_4) {
// if(1) {	//t
   if(!(unsigned)SatXilBlock.Value)
   {
 /* 130415
	SetAllUnch();
  	SatXilBlock.Value = 1;
 	SatXilBlock.ChangingValue = 1;
 */
  	SatXilBlock.Value = 0;	 //130415
 	SatXilBlock.ChangingValue = 0; //130415
   }
 }
 else{
 		if((unsigned)SatXilBlock.Value)
 		{
 //130415		SetAllCh();
 		SatXilBlock.Value = 0;
 		SatXilBlock.ChangingValue = 0;
 		}
 }

 dev1.pum100s1.SatGet3r0 = (unsigned char)SatGet3.Value;

  if(SatLock.Value) //lock
  {
  //	 printfp("\n\r");
	tmp3 = 0;
   for(i = 0; i <= (ST_SIZE - 1); i++)
 {
   tmp3 +=  SRGstr[i];
 
 //  printfpdv("%4.1f ", tmp3);
 }
	tmp3 /= 10.0;

    SatGet3.Value = tmp3 - 8.0;
	
// SatGet3.Value = (signed char)(RGstr & 0xf) - (signed char)8;
//    SatGet3.Value = (signed char)((RGstr & 0xf) - (signed char)8) * ((signed char)2);
 //	SatGet3.Value = (signed char)(cnt & 0xf) - (signed char)8; //for test
  }
  else
 {
  SatGet3.Value = MAGIC_VAL;
 }

 RGf = (signed char)ReadIOBus(SWEEP_ADDR);	  //141210 make it early


 //RGsat = ReadIOBus(CHD_ADDR);

  tmp = RGf & DELAY_MASK;
  switch(tmp)
  {
   case 0: M =  0.0; break;
   case 1: M =  1.0; break;
   case 2: M = -2.0; break;
   case 3: M = -1.0; break;
  }
  DD  = M * 2.048;

 RGsat = ReadIOBus(CHD_ADDR);  //new dop code

 //printfpd("\n\r RGsat: 0x%x", RGsat);

	/*
 if(RGsat & 0x80)	//negative number	need convert from dop code
 {
 tmp   = ~RGsat + 1; 
 RGsat = tmp | 0x80; 	
 }
  */
//  printfpd(" modufy RGsat: 0x%x", RGsat);
 // printfpd(" dec RGsat: %d", RGsat);
 // printfpd("\n\r dec test: %d", test);
 //  printfpd(" hex test1: 0x%x", test1);

//  printfpdv(" dd: %f", DD);


//141210  SatGet2.Value = SatSet1.Value + ((float64)RGsat /  (float64)512 - 0.5) * 1.31;

 SatGet2.Value = SatSet1.Value + DD +  ((float64)((RGsat * 4) + 1.5) /  (float64)128 ) * 1.31;

// printfpd(" modufy RGsat: 0x%x", RGsat);
 //printEthLongHex(RGsat);

 dev1.pum100s1.SatGet2r0 = (unsigned char)SatGet2.Value;
 dev1.pum100s1.SatGet2r1 = (unsigned char)((unsigned long)SatGet2.Value>>8);
 dev1.pum100s1.SatGet2r2 = (unsigned char)((unsigned long)SatGet2.Value>>16);
 dev1.pum100s1.SatGet2r3 = (unsigned char)((unsigned long)SatGet2.Value>>24);


if(SatTestMode.Value) 
{
SatGet2.Value = 0; //in test mode is 0
}


// SatGet2.ChangingValue = SatGet2.Value;

//141210 to make it early RGf = (signed char)ReadIOBus(SWEEP_ADDR);

// RGf = -1; //for test
// RGf = (signed char)cnt;

 //SatGet1.Value =   ((float64)RGf *  (float64)383.7)*( (float64)100000000 /  (float64)(F_SYSTEM));
//_______141210 use in RGf  bits 7,,,2 in dop code

  if(RGf & 0x80)	//negative number	need convert from dop code
 {
 tmp   = ((~(RGf >> 2)) & 0x3f) + 1; 
 RGsat = tmp | 0x80; 	
 }
 else
 {
   RGf >>= 2;
 }
 SatGet1.Value =   ((float64)((float64)RGf * 4.0 + 1.5)  *  (float64)383.7) * ( (float64)100000 /  (float64)(F_SYSTEM));
//___________________________________--141210
//141210SatGet1.Value =   ((float64)RGf *  (float64)383.7) * ( (float64)100000 /  (float64)(F_SYSTEM));

 dev1.pum100s1.SatGet1r0 = (unsigned char)((signed long)SatGet1.Value & 0xff);
 dev1.pum100s1.SatGet1r1 = (unsigned char)((signed long)SatGet1.Value>>8);
 dev1.pum100s1.SatGet1r2 = (unsigned char)((signed long)SatGet1.Value>>16);
 dev1.pum100s1.SatGet1r3 = (unsigned char)((signed long)SatGet1.Value>>24);



 UsedExp.State.Reg2.bit.Draw = 1;
 UsedExp.State.Reg2.bit.Some = 1;

}

extern "C" float GetFreqOffset()
{
//printfpdv("\n\r %f",SatGet1.Value);
return (float) SatGet1.Value;
}

extern "C" float GetChannelDelay()
{
//printfpdv("\n\r %f",SatGet1.Value);
return (float) SatGet2.Value;
}

extern "C" float GetIFBalance()
{
//printfpdv("\n\r %f",SatGet1.Value);
//return (signed) SatGet3.Value;
return (float)SatGet3.Value;
}

extern "C" signed GetSatLock()
{
//printfpdv("\n\r %f",SatGet1.Value);
return (signed) SatLock.Value;
}

extern "C" char* GetSatInput()
{

if(SatInput.Value)return ("Available");	   //down link
else return ("Lost");
}

extern "C" char* GetSatSearch()
{

if(SatSearch.Value)return ("Available");   //up link
else return ("Lost");
}

extern "C" unsigned GetSatACnt()
{
return (unsigned) SatACnt.Value;
}

extern "C" void MakeAndLoadRGstw();

extern "C" void  SetFreqProc()
{
//printfp("\n\rSetFreqProc");
//130412 unsigned char RGf;
 unsigned long RGf;
 //	 printfpd("ss0_before:%d",SatSet0.Value);

 if(SatSet0.Value){
   RGf = (unsigned long)((float64)F_SYSTEM) / SatSet0.Value;
//   dev1.pum100s1.SatSet0r0 = RGf;
// printfpd("RGf:%d",RGf);
   WriteIOBus(FREQ_PROC_ADDR, (unsigned char)(RGf & 0xff));
   if(RGf)
   {
   SatSet0.Value = (float64)((float64)F_SYSTEM) /(float64)RGf;
   SatSet0.ChangingValue = SatSet0.Value;
//   printfpd("ss0_after:%d",SatSet0.Value);
	}
	else
	{
   SatSet0.Value = MIN_SATSET0;
   SatSet0.ChangingValue = SatSet0.Value;

	
	}
   dev1.pum100s1.SatSet0r0 =  (unsigned char)SatSet0.Value;
   dev1.pum100s1.SatSet0r1 =  (unsigned char)((unsigned long)SatSet0.Value >> 8);
   dev1.pum100s1.SatSet0r2 =  (unsigned char)((unsigned long)SatSet0.Value >> 16);
   dev1.pum100s1.SatSet0r3 =  (unsigned char)((unsigned long)SatSet0.Value >> 24);

 }
	MakeAndLoadRGstw();  //130412
}

//extern "C" void printfpdv(char* format, float64 data);
extern "C" void printfpdv(char* format, float data);


 
 extern "C" unsigned long GetRGdd()
{
 unsigned ret;

 float32 RGdd;
// RGdd = (unsigned long)(((SatSet1.Value * (float64)(F_SYSTEM)) / (float64)100000000) - (float64)238.47) / (float64)0.2048;
 RGdd =  SatSet1.ChangingValue;

 dev1.pum100s1.SatSet1r0 = (unsigned char)SatSet1.Value;
 dev1.pum100s1.SatSet1r1 = (unsigned char)((unsigned long)SatSet1.Value >> 8);
 dev1.pum100s1.SatSet1r2 = (unsigned char)((unsigned long)SatSet1.Value >> 16);
 dev1.pum100s1.SatSet1r3 = (unsigned char)((unsigned long)SatSet1.Value >> 24);

// printfpdv("\n\r make rgdd :%10.4f",(float64 )RGdd );

 RGdd *= (float64)(F_SYSTEM) / (float64)100000000;
//printfpdv(" -> %10.4f",(float64 )RGdd );

// RGdd -= (float64)238.47;
// RGdd -= (float64)212.25;
 RGdd -= (float64)MIN_SATSET1;
//printfpdv(" -> %10.4f",(float64 )RGdd );
#ifdef PROG_PU_MSAT3

RGdd /= (float64)0.2048;
// RGdd /= (float64)0.4096;
#else
RGdd /= (float64)0.1024;
// RGdd *= (float64)9.765625;

#endif


//printfpdv(" -> %10.4f",(float64 )RGdd );

ret  = 	 (unsigned)RGdd;

//printfpd(" ul-> %d",(unsigned long)ret );

   if(RGdd - ret > 0.5) ret++;
 //  printfpd(" ul-> %d",(unsigned long)ret );

 return (unsigned long)ret;
}


#ifdef RECEIVE_MOD_LOCK   

extern "C" void SetModLock()
{
  //  WriteIOBus(STW_ADDR, RGstw);
  MakeAndLoadRGstw();
}

extern "C" void SetModUnLock()
{
 //   WriteIOBus(STW_ADDR, RGstw);
  MakeAndLoadRGstw();
}

#endif



extern "C" void MakeAndLoadRGstw()
{
 unsigned char RGstw = 0;
 unsigned long RGdd;
 unsigned long tmp;
// unsigned char RGstw0;

 // RGdd = (unsigned char)(((SatSet1.Value * (float64)(F_SYSTEM)) / (float64)100000000) - (float64)238.47) / (float64)0.2048;
  RGdd =GetRGdd();
 // RGstw0 = RGdd & MASK_BIT_0;

 //	printfpd("\n\r RGdd : %d", (unsigned long)RGdd);

 //printfp("MakeRGstw");

 dev1.pum100s1.SatTestModer0 = 	(unsigned char)SatTestMode.Value;
 dev1.pum100s1.SatPCr0 		 = 	(unsigned char)SatPC.Value;
 dev1.pum100s1.SatTimingr0 	 = 	(unsigned char)SatTiming.Value;


 tmp = (unsigned long)((float64)F_SYSTEM / SatSet0.Value);


 if(SatTestMode.Value) {RGstw |= MASK_BIT_7;}
//130412  if(SatPC.Value) {RGstw |= MASK_BIT_6;}	  //satpc will used to freq as high bit
 if(tmp & 0x100) {RGstw |= MASK_BIT_6;}	
 if(SatTiming.Value) {RGstw |= MASK_BIT_5;}

#ifdef PROG_PU_MSAT3
 if(RGdd & MASK_BIT_0) {RGstw |= MASK_BIT_0;}
#else
 if(RGdd & MASK_BIT_1) {RGstw |= MASK_BIT_0;}
#endif


#ifdef RECEIVE_MOD_LOCK
  if(SatExtLock.Value)
  {
  //	printfp("\n\rSatExtLock = YES");

    if(SatExtLockP.Value)	//normal polarity
   { 
      if (lockstate)
      	{

//printfp("\n\r1");

		  RGstw |= MASK_BIT_4;
		}
		else
		{
//printfp("\n\r2");

		   RGstw &= ~(MASK_BIT_4);
		}

	}
	else   //SatExtLockP   invert polarity
	{
	if (!lockstate)
      	{
//printfp("\n\r3");

		  RGstw |= MASK_BIT_4;
		}
		else
		{
//printfp("\n\r4");

		   RGstw &= ~(MASK_BIT_4);
		}
	}	//SatExtLockP
  }	  //
  else	//SatExtLock
  {
 // printfp("\n\rSatExtLock = NO");
// printfp("\n\r5");

	RGstw |= MASK_BIT_4;  //olwais on
  }
#endif

#ifdef PROG_PU_MSAT3
   if(SatLowP.Value)
  {
	 RGstw |= (unsigned char)(MASK_BIT_3);
  }
  else
  {
	 RGstw &= (unsigned char)(~(MASK_BIT_3));

  }

#else
 if(RGdd & MASK_BIT_0) {RGstw |= MASK_BIT_3; }
 else {  RGstw &= (unsigned char)(~(MASK_BIT_3)); }

#endif

// printfpd("\n\r RGstw: 0x%x", RGstw);
 // printfpd(" lockstate 0x%x", lockstate);


 WriteIOBus(STW_ADDR, RGstw);
}

extern "C" void  SetSysDelay()
{
//printfp("\n\r SetSysDelay");
  unsigned char RGd;
  unsigned long RGdd;
  unsigned char RGstw0;
 float64 MinSatSet1, MaxSatSet1, DelMin, DelMax;


//  RGd = (unsigned char)(((SatSet1.Value * (float64)(F_SYSTEM)) / (float64)100000000) - (float64)248.73) / (float64)0.4096;
//  RGdd = (unsigned long)(((SatSet1.Value * (float64)(F_SYSTEM)) / (float64)100000000) - (float64)238.47) / (float64)0.2048;
  RGdd = GetRGdd();
//  printfpd("\n\r%d",RGdd );
//#ifdef PROG_PU_MSAT1
//  RGd =  RGdd >> 1;
//#else
//  RGd =  RGdd >> 2;
//#endif
 // dev1.pum100s1.SatSet1r0 = RGd;
  RGstw0 = RGdd & MASK_BIT_0;

 //printfpd("\n\rRGd : 0x%X",RGd );

 // WriteIOBus(SYS_DELAY_ADDR, RGd);
 // MakeAndLoadRGstw();

 // SatSet1.Value = ((float64)248.73 + RGd * (float64)0.4096)*((float64)100000000 / (float64)F_SYSTEM);
// SatSet1.Value = ((float64)238.47 + (float64)((float64)(RGd<<1) + (float64)RGstw0)  * (float64)0.2048)*((float64)100000000 / (float64)F_SYSTEM);
// SatSet1.Value = (float64)238.47;

// SatSet1.Value += (float64)RGdd  * (float64)0.2048;
 // printfpdv("\n\rv:%15.8f",(float64 )SatSet1.Value );

// SatSet1.Value *= (float64)100000000 / (float64)F_SYSTEM;

// SatSet1.Value *= (float64)1000;
// SatSet1.Value += (float64)5;
// SatSet1.Value /= (float64)1000;

// MinSatSet1 = ((float64)238.47 + ((float64)RGdd  * (float64)0.2048))*((float64)100000000 / (float64)F_SYSTEM);
// MaxSatSet1 = ((float64)238.47 + ((float64)(RGdd + 1)  * (float64)0.2048))*((float64)100000000 / (float64)F_SYSTEM);
#ifdef PROG_PU_MSAT3
 MinSatSet1 = ((float64)MIN_SATSET1 + ((float64)RGdd  * (float64)0.2048))*((float64)100000000 / (float64)F_SYSTEM);
 MaxSatSet1 = ((float64)MIN_SATSET1 + ((float64)(RGdd + 1)  * (float64)0.2048))*((float64)100000000 / (float64)F_SYSTEM);
#else
 MinSatSet1 = ((float64)MIN_SATSET1 + ((float64)RGdd  * (float64)0.1024))*((float64)100000000 / (float64)F_SYSTEM);
 MaxSatSet1 = ((float64)MIN_SATSET1 + ((float64)(RGdd + 1)  * (float64)0.1024))*((float64)100000000 / (float64)F_SYSTEM);
#endif


 DelMin = SatSet1.ChangingValue - MinSatSet1;
 DelMax = MaxSatSet1 - SatSet1.ChangingValue;
// printfpdv("\n\rDelMin:%15.8f",(float64 )DelMin );
// printfpdv(" DelMax:%15.8f",(float64 )DelMax );
// printfpdv("\n\r MinSatSet1:%15.8f",(float64 )MinSatSet1 );
// printfpdv(" MaxSatSet1:%15.8f",(float64 )MaxSatSet1 );



 if(DelMin < DelMax)
 {
// printfp("\n\r set <");
  SatSet1.Value =  MinSatSet1;
//  SatSet1.ChangingValue =  SatSet1.Value;
 }
 else
 {
// printfp("\n\r set >");

  SatSet1.Value =  MaxSatSet1;
 // SatSet1.ChangingValue =  SatSet1.Value;

 }

 SatSet1.ChangingValue = SatSet1.Value;
//printfpdv("\n\rv:%15.8f",(float64 )SatSet1.Value );

// printfpd("\n\rRGd: %d", RGd);

 RGdd = GetRGdd();
//  printfpd("\n\r%d",RGdd );
#ifdef PROG_PU_MSAT3
  RGd =  RGdd >> 1;
#else
  RGd =  RGdd >> 2;
#endif
 // dev1.pum100s1.SatSet1r0 = RGd;
  RGstw0 = RGdd & MASK_BIT_0;


 WriteIOBus(SYS_DELAY_ADDR, RGd);
  MakeAndLoadRGstw();

}

extern "C" void  SetOutLevel() 
{
//printfp("\n\r SetOutLevel");
// SetTxLevel(SatSet2.Value);

// SetTxLevel((SatSet2.Value +(float64)12) * ((float64)(-2)));
 unsigned long tmp =  (unsigned long)(SatSet2.Value * (float64)10);
 tmp += 2l;
 tmp /= 5l;
 tmp *= 5l;
 SatSet2.Value = (float64)(tmp) / (float64)(10);  
 SatSet2.ChangingValue = SatSet2.Value;

 dev1.pum100s1.SatSet2r0 = SatSet2.Value;


 SetTxLevel((SatSet2.Value - (float64)12) * ((float64)(2)));

}

//130517extern "C" void  SetAny(unsigned long af, unsigned char df, unsigned long pf, unsigned long dpf) 
extern "C" void  SetAny(unsigned long af, unsigned char df, unsigned long pf, unsigned long dpf, unsigned long st) 
{
 //printfp(" SetAny");
		   key_enter_flag = 1;
           if(SatSet6.pControl->Control(SatSet6.CntNum, af))
			 {
			 SatSet6.ChangingValue =  af;
			 SatSet6.Value =  af;
	         UsedExp.State.Reg2.bit.SatSet6 = 1;
		   	 }
		    key_enter_flag = 1;
  		   if(SatDF.pControl->Control(SatDF.CntNum, df))
			 {
			 SatDF.ChangingValue =  df;
			 SatDF.Value =  df;
	         UsedExp.State.Reg2.bit.SatDF = 1;
		   	 }
		    key_enter_flag = 1;
  		   if(SatSet0.pControl->Control(SatSet0.CntNum, pf))
			 {
			 SatSet0.ChangingValue =  pf;
			 SatSet0.Value =  pf;
	         UsedExp.State.Reg2.bit.SatSet0 = 1;
		   	 }
		     key_enter_flag = 1;
 			if(SatSet8.pControl->Control(SatSet8.CntNum, dpf))
			 {
			 SatSet8.ChangingValue =  dpf;
			 SatSet8.Value =  dpf;
	         UsedExp.State.Reg2.bit.SatSet8 = 1;
		   	 }
			 key_enter_flag = 1;
			if(SatTimer.pControl->Control(SatTimer.CntNum, st))
			 {
			 SatTimer.ChangingValue =  st;
			 SatTimer.Value =  st;
	         UsedExp.State.Reg2.bit.SatTimer = 1;
		   	 }


}


extern "C" void  SetSatRate() 
{
// printfp(" SetSatRate");

   OldAlev = 0xFF;	 //need check access level


unsigned long tmp = (unsigned long)SatRate.Value * 1000l; //in Hz
unsigned long tmp1 = (tmp + 500000l)/1000000l; // near value 
if(tmp1 > MAX_SATSET6) tmp1 = MAX_SATSET6;

//unsigned long tmp2 = 3*tmp;
//if(tmp2 > MAX_SATSET0) tmp2 = MAX_SATSET0;

unsigned long tmp3 = tmp<<1;  //2*tmp
if(tmp3 > MAX_SATSET0) tmp3 = MAX_SATSET0;

unsigned long tmp4 = (tmp<<1) + (tmp>>1); // = 2,5*tmp
if(tmp4 > MAX_SATSET0) tmp4 = MAX_SATSET0;



//printfpd("\n\r tmp2:%d", tmp2);
/*130517
if     (tmp < 25000 ){ SetAny(1, 10, 195694l, 45l);}
else if(tmp < 50000 ){ SetAny(1, 11, 195694l, 60l);}
else if(tmp < 100000){ SetAny(1, 11, 195694l, 70l);}
else if(tmp < 250000){ SetAny(1, 12, 396000l,100l);}
else if(tmp < 450000){ SetAny(1, 0, 1000000l,200l);}
else if(tmp < 600000){ SetAny(1, 0, 1800000l,300l);}
else              { SetAny(tmp1, 0, tmp2 ,300l);}
*/

if     (tmp < 25000 ){ SetAny(1, 10, 195694l, 45l,7l);}
else if(tmp < 50000 ){ SetAny(1, 11, 195694l, 60l,6l);}
else if(tmp < 100000){ SetAny(1, 11, 195694l, 70l,5l);}
else if(tmp < 250000){ SetAny(1, 12, tmp3,100l,2l);}
else if(tmp < 450000){ SetAny(1, 0, tmp3,200l,2l);}
else if(tmp < 600000){ SetAny(1, 0, tmp3,300l,2l);}
//140226else              { SetAny(tmp1, 0, tmp4 ,300l,2l);}
else              { SetAny(tmp1, 0, tmp4 ,300l,3l);}



}

extern "C" void  SetSatTimer() 
{
// printfp(" SetSatTimer");

   SetAverDistance();

}

#ifdef RECEIVE_MOD_LOCK


extern "C" void  SetSatExtLock() 
{
 //printfp(" SetSatExtLock");
// lockstate = MOD_LOCK;//MOD_UNDEF;
 MakeAndLoadRGstw();
 dev1.pum100s1.SatExtLockr0 = SatExtLock.Value;

}

extern "C" void  SetSatExtLockP() 
{
// printfp(" SetSatExtLockP");
 //lockstate = MOD_UNDEF;
 MakeAndLoadRGstw();
  dev1.pum100s1.SatExtLockPr0 = SatExtLockP.Value;

}

#endif

extern "C" void  SetSatLowP() 
{
// printfp(" SetSatLowP");
 MakeAndLoadRGstw();
   dev1.pum100s1.SatLowPr0 = SatLowP.Value;

}

extern "C" void  SetSatALev() 
{
// printfp("\n\rSetSatALev");

//  printfpd(" lev: %d",SatALev.Value);
 // printfpd(" lev_ch: %d",SatALev.ChangingValue);

 if(OldAlev == SatALev.Value)
 {
// printfp("\n\rSetSatALev return");

  return;
 }
// printfp(" SetSatALev");
	 dev1.pum100s1.SatALevr0 = SatALev.Value;


switch(SatALev.Value)
{
 case 0: //5
 if(SatRate.Value > SATRATE_LEV0)
 {
// printfp("\n\rSetLev 0");

 SatRate.Value = SATRATE_LEV0;
 SatRate.ChangingValue = SatRate.Value;
 SetSatRate();
 }
 break;

 case 1: //15
 if(SatRate.Value > SATRATE_LEV1)
 {
// printfp("\n\rSetSatALev1");
 SatRate.Value = SATRATE_LEV1;
 SatRate.ChangingValue = SatRate.Value;
 SetSatRate();
 }
 break;

 case 2: //50
 // SetSatRate();
 
 break;


 default : break;

}  //case
  OldAlev = SatALev.Value;
}

extern "C" void  SetSatACode() 
{
// printfp("\n\rSetSatACode");
  // printfpd(" lev: %d",SatALev.Value);
    // printfpd(" lev_ch: %d",SatALev.ChangingValue);


if((unsigned)SatACode.Value == (unsigned)ING_CODE_LEV0)
{
 // printfp("\n\rLEV0___________________");
  SatALev.Value =  0;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}


if((unsigned)SatACode.Value == (unsigned)ING_CODE_LEV1)
{
//printfp("\n\rLEV1___________________");
  SatALev.Value =  1;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}

if((unsigned)SatACode.Value == (unsigned)ING_CODE_LEV2)
{
 //printfp("\n\rLEV2___________________");
  SatALev.Value =  2;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}

if(SatACode.Value == (((DevId.Value + 2) * 2) + 3) *3)

{
// printfp("\n\rLEV0___________________");
  SatALev.Value =  0;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}


if(SatACode.Value == (((DevId.Value + 3) * 3) + 4) *4)

{
 //printfp("\n\rLEV1___________________");
  SatALev.Value =  1;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}

if(SatACode.Value == (((DevId.Value + 4) * 4) + 5) *5)

{
 //printfp("\n\rLEV2___________________");
  SatALev.Value =  2;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
}
//clear value
SatACode.Value = 0;
SatACode.ChangingValue = 0; //to do not viewSatACode.Value;
}

extern "C" void  SetSatADemo() 
{
// printfpd("\n\rSetSatADemo %x", SatADemo.Value);


switch((unsigned)SatADemo.Value)
{
   dev1.pum100s1.SatADemor0 = SatADemo.Value;

 case 0: 
 //satalev get to zero to counter only!!!!!
 if(FlagOldSatAlev = (unsigned long)SIGN_FLAG)
 {
  FlagOldSatAlev = 0;
  SatALev.Value = (unsigned)OldSatAlev; //0;
  SatALev.ChangingValue = SatALev.Value;
  SetSatALev();
  }

  SatACnt.Value =  0;
  SatACnt.ChangingValue = SatACnt.Value;

 break;
	
 case 1:
  FlagOldSatAlev = (unsigned long)SIGN_FLAG; 
  OldSatAlev = 	SatALev.Value;
  SatALev.Value =  2;
  SatALev.ChangingValue = SatALev.Value;

  SetSatALev();
  SatACnt.Value =  ONE_DAY_VALUE;
  SatACnt.ChangingValue = SatACnt.Value;

 break;

 default : break;

}  //case


}

extern "C" void  SetSatACnt() 
{
	
  if((unsigned)SatADemo.Value)
   {
	if((unsigned)SatACnt.Value)
	{
 //	   printfpd("\r%d",SatACnt.Value);
	 SatACnt.Value--;
	 SatACnt.ChangingValue = SatACnt.Value;

	 dev1.pum100s1.SatACntr0 = 	(unsigned)SatACnt.Value;
	 dev1.pum100s1.SatACntr1 = 	(unsigned)SatACnt.Value>>8;
	 dev1.pum100s1.SatACntr2 = 	(unsigned)SatACnt.Value>>16;
	 dev1.pum100s1.SatACntr3 = 	(unsigned)SatACnt.Value>>24;


	}
	else
	{
	SatADemo.Value =  0;
  	SatADemo.ChangingValue = SatADemo.Value;
   	 SetSatADemo();
  //	SatALev.Value =  0;
  //  SatALev.ChangingValue = SatALev.Value;
   // SetSatALev();
 	}
   }


}






 
extern "C" void  SetAverDistance() 
{
 //printfp("\n\rSetAverDistance = DF + Timer+ Deb Key");

/*
 WriteIOBus(DEBUG_ADDR1, (unsigned char)(SatSet3.Value));
 WriteIOBus(DEBUG_ADDR2, (unsigned char)(((unsigned)SatSet3.Value) >> 8));

*/

unsigned char tmp;

switch((unsigned char)SatDF.Value)
{
 case 9:  tmp = 0xA; break;
 case 10: tmp = 0xC; break;
 case 11: tmp = 0xE; break;
 case 12: tmp = 0xF; break;
 default :  tmp = (unsigned char)SatDF.Value; break;
}


//WriteIOBus(DEBUG_ADDR1, (unsigned char)((SatDF.Value << 4) + SatTF.Value));
WriteIOBus(DEBUG_ADDR1, (unsigned char)((tmp << 4) + SatTF.Value));
//130517WriteIOBus(DEBUG_ADDR2, (unsigned char)((unsigned)SatSet3.Value));
//unsigned char tmp2 = 

if((signed char)SatSet3.Value < 0)
{
 tmp = 16 + (signed char)SatSet3.Value;
}
else
{
 tmp =  (signed char)SatSet3.Value;
}
// printfpd("\n\r %x", tmp);

WriteIOBus(DEBUG_ADDR2, (unsigned char) (((unsigned)SatSet3.Value << 4) + (unsigned)SatTimer.Value) ) ;
//tWriteIOBus(DEBUG_ADDR2, (unsigned char) ((tmp << 4) + (unsigned)SatTimer.Value) );


 /*	 130409
 dev1.pum100s1.SatSet3r0 = SatSet3.Value;
 dev1.pum100s1.SatSet3r1 = (unsigned long)SatSet3.Value >> 8;
 */
// dev1.pum100s1.SatSet3r0 = (SatDF.Value << 4) + SatTF.Value;
 dev1.pum100s1.SatSet3r0 = (tmp << 4) + SatTF.Value;
//130517 dev1.pum100s1.SatSet3r1 = (unsigned long)SatSet3.Value;
 dev1.pum100s1.SatSet3r1 = ((unsigned long)SatSet3.Value << 4) + (unsigned)SatTimer.Value;


}

#define MULT_VALF (1000)
extern "C" void LoadDDSN3a();

extern "C" void  SetTrFrequency() 
{
// printfp("SetTrFrequency");
 LoadDDSN3a();
// LoadFreqPCha(SatSet4.Value * MULT_VALF);

 dev1.pum100s1.SatSet4r0 = (unsigned char)SatSet4.Value;
 dev1.pum100s1.SatSet4r1 = (unsigned char)((unsigned long)SatSet4.Value >> 8);
 dev1.pum100s1.SatSet4r2 = (unsigned char)((unsigned long)SatSet4.Value >> 16);

signed short tmp8 = SatSet8.Value;

 dev1.pum100s1.SatSet8r0 = tmp8 & 0xff;
 dev1.pum100s1.SatSet8r1 = (tmp8>>8) & 0xff;



 LoadFreqPCha((SatSet4.Value + SatSet8.Value) * MULT_VALF);
}
extern "C" void LoadDDSN3();

extern "C" void  SetRcvFrequency() 
{
// printfp("SetRcvFrequency");
 LoadDDSN3();


 LoadFreqPCh((SatSet5.Value + SatSet8.Value) * MULT_VALF);

 dev1.pum100s1.SatSet5r0 = (unsigned char)SatSet5.Value;
 dev1.pum100s1.SatSet5r1 = (unsigned char)((unsigned long)SatSet5.Value >> 8);
 dev1.pum100s1.SatSet5r2 = (unsigned char)((unsigned long)SatSet5.Value >> 16);

}

extern "C" void  SetTrBound() 
{
// printfp("SetTrBound+Rcv");
 dev1.pum100s1.SatSet6r0 = (unsigned char)SatSet6.Value;
 LoadFilter(0, SatSet6.Value);

//_________________________________130409
SatSet7.Value = SatSet6.Value;
SatSet7.ChangingValue =  SatSet6.Value;
dev1.pum100s1.SatSet7r0 = (unsigned char)SatSet7.Value;
LoadFilter(1, SatSet7.Value);
LoadFilter(2, SatSet7.Value);
//_________________________________130409
}

extern "C" void  SetRcvBound()
{
// printfp("SetRcvBound+Trncm");

 dev1.pum100s1.SatSet7r0 = (unsigned char)SatSet7.Value;
 LoadFilter(1, SatSet7.Value);
 LoadFilter(2, SatSet7.Value);
//_________________________________130409
SatSet6.Value = SatSet7.Value;
SatSet6.ChangingValue =  SatSet7.Value;
dev1.pum100s1.SatSet6r0 = (unsigned char)SatSet6.Value;
LoadFilter(0, SatSet6.Value);
//_________________________________130409


}

extern "C" void  SetOffset()
{
// printfp("SetOffset");
 SetTrFrequency();
 SetRcvFrequency();
}

extern "C" void  SetSatTestModeI()
{
 //printfp("SetSatTestModeI");


#ifndef LINE_LOCK


 SatTestModeI.Value = SatTestMode.Value + (SatTiming.Value << 1); //+1 for blink

#else LINE_LOCK
if(SatExtLockP.Value)
{
 SatTestModeI.Value = SatTestMode.Value + (SatTiming.Value << 1) + (GetLock() << 2) + (SatExtLock.Value << 3);
}
else
{
 SatTestModeI.Value = SatTestMode.Value + (SatTiming.Value << 1) + (((~GetLock()) & 1) << 2) + (SatExtLock.Value << 3);
}

 // printfpd("\n\rt: %d", (unsigned)SatTestModeI.Value);
  //	GetLock(); //read line pc12
#endif

 SatTestModeI.ChangingValue = SatTestModeI.Value;
// printfpd(" %d", SatTestModeI.Value);


}

extern "C" void  SetSatTestMode()
{
// unsigned char RGstw = 0;
// printfp("SetSatTestMode");

MakeAndLoadRGstw();

 /*
 if(SatTestMode.Value) {RGstw |= MASK_BIT_7;}
 if(SatPC.Value) {RGstw |= MASK_BIT_6;}
if(SatTiming.Value) {RGstw |= MASK_BIT_5;}

 WriteIOBus(STW_ADDR, RGstw);
	*/

// SatTestModeI.Value = SatTestMode.Value;
// SatTestModeI.ChangingValue = SatTestModeI.Value;
  SetSatTestModeI();
}

extern "C" void  SetSatTiming()
{
// unsigned char RGstw = 0;
// printfp(" SetSatTiming");

MakeAndLoadRGstw();

SetSatTestModeI(); //for indikating comman variable

  /*
 if(SatTestMode.Value) {RGstw |= MASK_BIT_7;}
 if(SatPC.Value) {RGstw |= MASK_BIT_6;}
 if(SatTiming.Value) {RGstw |= MASK_BIT_5;}

 WriteIOBus(STW_ADDR, RGstw);
	*/
}

extern "C" void  SetSatSound()
{
// unsigned char RGstw = 0;
 //printfp(" SetSatSound");
}

extern "C" void  SetLogClear()
{
// unsigned char RGstw = 0;
// printfp(" SetLogClear");
}

extern "C" void  SetSatFactory()
{
// unsigned char RGstw = 0;
// printfp(" SetSatFactory");
 if(SatFactory.Value)
 {
 SetFactoryData();
  LoadDDSs(); //need to make at start full loading ddss
  StartLoadAll();
// SatFactory.Value = MIN_SATFACTORY;		   //set back to No
// SatFactory.ChangingValue = MIN_SATFACTORY;
 }
}




extern "C" void  SetSatPC()
{
// unsigned char RGstw = 0;
 //printfp("SetSatPC");

MakeAndLoadRGstw();
  /*
 if(SatTestMode.Value) {RGstw |= MASK_BIT_7;}
 if(SatPC.Value) {RGstw |= MASK_BIT_6;}
if(SatTiming.Value) {RGstw |= MASK_BIT_5;}

 WriteIOBus(STW_ADDR, RGstw);
 */
}

extern "C" void StartLoadAll()
{

//okprintfpd("\n\rSatADemo1 %x", SatADemo.Value);

SetTrFrequency();
SetRcvFrequency();
SetTrBound(); 
SetRcvBound();
SetFreqProc();
SetSysDelay();
SetOutLevel();
SetAverDistance(); //debug bytes
SetSatTestMode();
SetSatPC();
SetSatTiming();
SetSatSound();
SetSatLowP();
SetSatALev();
//SetSatACode();
//this clear satalev SetSatADemo();


//ok printfpd("\n\rSatADemo 2 %x", SatADemo.Value);

#ifdef RECEIVE_MOD_LOCK

SetSatExtLock();
SetSatExtLockP();
#endif
SetSysDelay(); //141216

}
 //#define TEST_DATA_SIZE (256)

#define	END_ADDR 4194304


extern "C" void TestWriteFlash1(void)
{
 char Test[TEST_DATA_SIZE];
 char TestR[TEST_DATA_SIZE];

 unsigned long j = 0;
  for(j = 0; j < END_ADDR; j += TEST_DATA_SIZE)
 // for(j = 0; j < TEST_DATA_SIZE; j += TEST_DATA_SIZE)
  {
  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
  Test[i]  = i;
  }

  //t	  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);

  //	  read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1 + (unsigned long)END_ADDR - TEST_DATA_SIZE , TEST_DATA_SIZE, &TestR[0]);
	    read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1 + j, TEST_DATA_SIZE, &TestR[0]);

    delay_mcs(10000);

   for( i = 0; i < TEST_DATA_SIZE; i++)
  {
  if(!(i % 16))
   printfpd("\n\r %X >", (i + j));
   printfpd(" %02X", TestR[i]);
//   OperateBuffers_usart0t();
//   if(!(i % 16))
//   printfpd("\n\r %X >", i);
  }

   OperateBuffers_usart0t();
   delay_mcs(10000);
   wd_reset();
  }
}

extern "C" void TestWriteFlash2(void)
{
 char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];

  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
  Test[i]  = i;
  }

  	  write_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);
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

extern "C" void TestWriteFlash3(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];

  for(unsigned i = 0; i < TEST_DATA_SIZE; i++)
  {
   TFTP_Buffer[i]  = i;
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

extern "C" void TestWriteFlash4(void)
{
// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];
 char * pBuff1 = &TFTP_Buffer1[0];
 char * pBuff = &TFTP_Buffer[0];

  for(unsigned i = 0; i < XilSizeToDownloadD; i++)
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


extern "C" void TestWriteFlash5(void)
{

 //printfp("\n\rTestWriteFlash5");

// char Test[TEST_DATA_SIZE];
// char TestR[TEST_DATA_SIZE];

// unsigned long j = 0;
//  for(j = 0; j < END_ADDR; j += TEST_DATA_SIZE)
 // for(j = 0; j < TEST_DATA_SIZE; j += TEST_DATA_SIZE)
//  {
  for(unsigned i = 0; i < XilSizeToDownloadD; i++)
  {
   TFTP_Buffer[i]  = 0x99;
  }

   for( i = 0; i < 10000; i++)
//   for( i = 0; i < 10000; i++)
  {
   ToPdcTu0('.');
	   delay_mcs(10);
	   OperateBuffers_usart0t();

     }


  //t	  write_da  //t	  write_daAFLASH_LOGIC_ADDR_CS1,(unsigned int)&Test[0],  TEST_DATA_SIZE);

  //	  read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1 + (unsigned long)END_ADDR - TEST_DATA_SIZE , TEST_DATA_SIZE, &TestR[0]);
   read_dataflash (CFG_DATAFLASH_LOGIC_ADDR_CS1, XilSizeToDownloadD, &TFTP_Buffer[0]);

   delay_mcs(100000);

   for( i = 0; i < XilSizeToDownloadD; i++)
//   for( i = 0; i < 10000; i++)
  {
   if(!(i % 256)) {    OperateBuffers_usart0t();  wd_reset();
   delay_mcs(1000000);
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
 //  wd_reset();

// ToPdcTu0(TFTP_Buffer[i]);

 // }
// ToPdcTu0(TFTP_Buffer[i]);
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


//t#define  PERIOD_KEEP_STATE	(1000 * 60 * 60) //1 hour
//#define  PERIOD_KEEP_STATE	(1000 * 60) //1 min
#define  PERIOD_KEEP_STATE	(1000 * 60 * 5) //5 min

extern "C" void KeepState(void)
{
static unsigned long timerkeep;
if(timerkeep > time1) timerkeep = time1;

char STATEREG[3];
 if((time1 - timerkeep) > PERIOD_KEEP_STATE)
 {
   timerkeep = 	time1;
    STATEREG[0] = ReadIOBus(SWEEP_ADDR);
	STATEREG[1] = ReadIOBus(CHD_ADDR);
	STATEREG[2] = ReadIOBus(STR_ADDR);
  //	ReadIOBus(CHD_ADDR);
#ifdef YOURNAL
	Add_Event(EV_STATE_TIMER, 3, STATEREG);
#endif

 }
}

extern "C" void FillClasses()
{
 unsigned char tmp;

  SatSet0.Value = 	dev1.pum100s1.SatSet0r0	+  (dev1.pum100s1.SatSet0r1 << 8) +	  (dev1.pum100s1.SatSet0r2 << 16) +	 (dev1.pum100s1.SatSet0r3 << 24);
  SatSet0.ChangingValue = SatSet0.Value;

  SatSet1.Value = 	dev1.pum100s1.SatSet1r0	+  (dev1.pum100s1.SatSet1r1 << 8) +	  (dev1.pum100s1.SatSet1r2 << 16) +	 (dev1.pum100s1.SatSet1r3 << 24);
   SatSet1.ChangingValue = SatSet1.Value;

 
 
  SatSet2.Value = 	dev1.pum100s1.SatSet2r0;
   SatSet2.ChangingValue = SatSet2.Value;
	 
//130409  SatSet3.Value = 	dev1.pum100s1.SatSet3r0	+  (dev1.pum100s1.SatSet3r1 << 8);
//130517  SatSet3.Value = 	dev1.pum100s1.SatSet3r1;//	+  (dev1.pum100s1.SatSet3r1 << 8);
  SatSet3.Value = 	dev1.pum100s1.SatSet3r1 >> 4;//	+  (dev1.pum100s1.SatSet3r1 << 8);
   SatSet3.ChangingValue = SatSet3.Value;

 
   SatTimer.Value =  dev1.pum100s1.SatSet3r1 & 0xf;//	+  (dev1.pum100s1.SatSet3r1 << 8);
    SatTimer.ChangingValue = SatTimer.Value;

 
  SatSet4.Value = 	dev1.pum100s1.SatSet4r0	+  (dev1.pum100s1.SatSet4r1 << 8) +	  (dev1.pum100s1.SatSet4r2 << 16);
     SatSet4.ChangingValue = SatSet4.Value;


  SatSet5.Value = 	dev1.pum100s1.SatSet5r0	+  (dev1.pum100s1.SatSet5r1 << 8) +	  (dev1.pum100s1.SatSet5r2 << 16);
     SatSet5.ChangingValue = SatSet5.Value;

 
  SatSet6.Value = 	dev1.pum100s1.SatSet6r0;
     SatSet6.ChangingValue = SatSet6.Value;


  SatSet7.Value = 	dev1.pum100s1.SatSet7r0;
     SatSet5.ChangingValue = SatSet5.Value;



  SatSet8.Value = 	dev1.pum100s1.SatSet8r0	+  (dev1.pum100s1.SatSet8r1 << 8);
    SatSet8.ChangingValue = SatSet8.Value;



  SatTestMode.Value = 	dev1.pum100s1.SatTestModer0;
    SatTestMode.ChangingValue = SatTestMode.Value;


  SatPC.Value = 	dev1.pum100s1.SatPCr0;
  SatPC.ChangingValue = SatPC.Value;

  SatTiming.Value = 	dev1.pum100s1.SatTimingr0;
   SatTiming.ChangingValue = SatTiming.Value;


  SatSound.Value = 	dev1.pum100s1.SatSoundr0;
    SatSound.ChangingValue = SatSound.Value;

  tmp = dev1.pum100s1.SatSet3r0 >> 4;
  SatTF.Value = dev1.pum100s1.SatSet3r0 & 0xF;
    SatTF.ChangingValue = SatTF.Value;


//___________________________________________________140902
  SatExtLock.Value = 	dev1.pum100s1.SatExtLockr0;
    SatExtLock.ChangingValue =  SatExtLock.Value;


 //  unsigned char  SatExtLockr0;
//MDataV	SatExtLockP;
 //  unsigned char  SatExtLockPr0;
  SatExtLockP.Value = 	dev1.pum100s1.SatExtLockPr0;
     SatExtLockP.ChangingValue =  SatExtLockP.Value;


//#endif
//MDataV	SatLowP;

 //  unsigned char  SatLowPr0;
   SatLowP.Value = 	dev1.pum100s1.SatLowPr0;
	  SatLowP.ChangingValue = SatLowP.Value;


//MDataV	SatALev;
 //  unsigned char  SatALevr0;
   SatALev.Value = 	dev1.pum100s1.SatALevr0;
	  SatALev.ChangingValue = SatALev.Value;

//MDataC	SatACode;
//MDataV	SatADemo;
 //  unsigned char  SatADemor0;
     SatADemo.Value = 	dev1.pum100s1.SatADemor0;
	   SatADemo.ChangingValue = SatADemo.Value;


//MDataC	SatACnt;
 //  unsigned char  SatACntr0;
 //  unsigned char  SatACntr1;
 //  unsigned char  SatACntr2;
 //  unsigned char  SatACntr3;

   SatACnt.Value = 	dev1.pum100s1.SatACntr0	+  (dev1.pum100s1.SatACntr1 << 8) +	  (dev1.pum100s1.SatACntr2 << 16) +	 (dev1.pum100s1.SatACntr3 << 24);
     SatACnt.ChangingValue = SatACnt.Value;


//#ifdef YOURNAL
//MDataS	LogStr0;
//MDataS	LogStr1;
//MDataV	LogClear;
 //  unsigned char  LogClearr0;
    LogClear.Value = 	dev1.pum100s1.LogClearr0;
	   LogClear.ChangingValue =  LogClear.Value;

	    dev1.pum100s1.LogClearr0 = 	0;	  //one time make this


//#endif
//#ifdef USE_HTTP
//MDataC	WebPassword;
//   unsigned char  WebPasswordr0;
//   unsigned char  WebPasswordr1;
//   unsigned char  WebPasswordr2;
//   unsigned char  WebPasswordr3;

   WebPassword.Value = 	dev1.pum100s1.WebPasswordr0	+  (dev1.pum100s1.WebPasswordr1 << 8) +	  (dev1.pum100s1.WebPasswordr2 << 16) +	 (dev1.pum100s1.WebPasswordr3 << 24);
    WebPassword.ChangingValue = WebPassword.Value;

//___________________________________________________ +14 bytes



  switch(tmp)
  {
   case 0xa:  SatDF.Value = 9;   break;
   case 0xc:  SatDF.Value = 10;  break;
   case 0xe:  SatDF.Value = 11;  break;
   case 0xf:  SatDF.Value = 12;  break;
   default :  SatDF.Value = tmp; break;
   }
  CheckRestoringData();	//need hier

  UsedExp.State.Reg2.bit.SatAll = 1;	  //load all
 // ????? UsedExp.State.Reg2.bit.LogClear = 1; //clear if need
}

extern "C" void Reset_DDS()
{
AT91RM9200_PIO_REG_STRUCT_PTR  piob_ptr;

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
        piob_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
	    piob_ptr->SODR = 1<<22; //cs to one
		delay_mcs(5000);
        piob_ptr->CODR = 1<<22; //cs to zero
}

#ifdef LINE_LOCK
extern "C" void Init_Alarms_IOs()
{
AT91RM9200_PIO_REG_STRUCT_PTR  pioc_ptr;

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 12, AT91RM9200_PIO_PERIPHERAL_IO, 0);  //inp lock
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //onorm
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);  //o lock



        pioc_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
 	    pioc_ptr->SODR = 1<<11; //onorm to one
        pioc_ptr->CODR = 1<<10; //olock to zero
}


extern "C" void SetOLock()
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pioc_ptr;
   pioc_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   pioc_ptr->SODR = 1<<10; //olock to one
}

extern "C" void ClearOLock()
{
   AT91RM9200_PIO_REG_STRUCT_PTR  pioc_ptr;
   pioc_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;
   pioc_ptr->CODR = 1<<10; //olock to zero
}





extern "C" unsigned char GetLock()
{
AT91RM9200_PIO_REG_STRUCT_PTR  pioc_ptr;
 pioc_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;

unsigned long status;


     status = pioc_ptr->PDSR; //wait line init hier zero
//  printfpd("lockstate : %d", lockstate);

     if(status & (1<<12))
      { 

//printfp("l");
	      if(lockstate != (unsigned char)MOD_LOCK)
          { 
//printfp("L");

       //   SetModLock();
          lockstate = (unsigned char)MOD_LOCK;
      //    unlockcounter = 0;
	    SetModLock();

           }
   		return 1;
      }
	else
	  {
//printfp("u");

	     if((lockstate != (unsigned char)MOD_UNLOCK))
          { 
//printfp("U");

       //    SetModUnLock();
           lockstate = (unsigned char)MOD_UNLOCK;
		       SetModUnLock();
          }

	  }


return 0;

}  

#endif


/* it need for md 310s
extern "C" void FillFirmwareFileData(char pg)
{
 char * pData;
 int i;

  unsigned int source_addr;

	source_addr = (unsigned int)XilDataAddressD2;
 read_dataflash (source_addr,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);

// for(i = 0; i < TBUFF1_VALUE; i++)
 for(i = 0; i < DISP_LEN; i++)
 {
 FirmFileData.Value[i] = *pData++;
 }
}

 */

extern "C" char*  GetLogStr0()
{
 return (LogStr0.Value);
}

extern "C" char*  GetLogStr1()
{
 return (LogStr1.Value);
}

extern "C" long GetSerial()
{
 return (long)DevId.Value;
}

 extern void Set_SYMBRATE( unsigned long Val)
 {
 //  if(SatRate->heCntFunc(SatRate.cntmum))
 //  {
  // SatRate.Value = value;
  // SatRate.ChangingValue =	SatRate.Value;
 //  }
  char tmp = LockMode.Value; 
	LockMode.Value = 3; 

    if(theCntFunc.Control(SatRate.CntNum, Val))
	 {	
	  	SatRate.ChangingValue = Val;
		SatRate.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatRate.OprNum);
	 }

   LockMode.Value = tmp; 

 }


 extern "C" long Get_SYMBRATE()
  {
   return SatRate.Value;
  }

 extern "C" long Get_IFDOWNLINK()
 {
   printfpd("\n\r Get Down: %d", SatInput.Value);
   return SatInput.Value;
 }

  extern "C" long Get_IFUPLINK()
 {
   printfpd("\n\r Get Up %d", SatSearch.Value);
   return SatSearch.Value;
 }

extern "C" void Set_SYSDELAY( unsigned long  Val)
{
  //  printfpd("\n\rSet_SYSDELAY %d",Val);
char tmp = LockMode.Value; 
	LockMode.Value = 3; 


  float64 val =	  Val / 1000.0;
  if(theCntFunc.Control(SatSet1.CntNum, val))
	 {	
	  	SatSet1.ChangingValue = val;
		SatSet1.Value = val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet1.OprNum);
	 //	printfp("...ok");
	 }
	 else
	 {
	//  printfp("..wrong");

	 }

   LockMode.Value = tmp; 

}
 
extern "C" long Get_SYSDELAY()
{
   return SatSet1.Value  * 1000l;
}

extern "C" void Set_OUTLEVEL( signed long Val)
{
// Val /= (-10l);
  //   printfpd("\n\rSet_OUTLEVEL %d",Val);

char tmp = LockMode.Value; 
	LockMode.Value = 3; 

  float64 val =	  Val / 10.0;

  val*= -1.0;

//printfpdv(" %f", val);

if(theCntFunc.Control(SatSet2.CntNum, val))
	 {	
	  	SatSet2.ChangingValue = val;
		SatSet2.Value = val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet2.OprNum);
	//	printfp("...ok");

	 }
	  else
	 {
   //	  printfp("..wrong");

	 }
   LockMode.Value = tmp; 


}
 
extern "C" long Get_OUTLEVEL()
{
   return SatSet2.Value * (-10l);
}

extern "C" void Set_RFREQ( unsigned long Val)
{
char tmp = LockMode.Value; 
	LockMode.Value = 3; 

  if(theCntFunc.Control(SatSet5.CntNum, Val))
	 {	
	  	SatSet5.ChangingValue = Val;
		SatSet5.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet5.OprNum);
	 }
  LockMode.Value = tmp; 

}
 
extern "C" long Get_RFREQ()
{
  return SatSet5.Value;
}

extern "C" void Set_TFREQ( unsigned long Val)
{
 char tmp = LockMode.Value; 
	LockMode.Value = 3; 

   if(theCntFunc.Control(SatSet4.CntNum, Val))
	 {	
	  	SatSet4.ChangingValue = Val;
		SatSet4.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet4.OprNum);
	 }
   LockMode.Value = tmp; 
}

extern "C" long Get_TFREQ()
{
   return SatSet4.Value;
}

extern "C"   long Get_FREQOFFSET(void)
{
  return SatGet1.Value * 10;

}
extern "C"   long Get_CHANNELDELAY(void)
{
  return SatGet2.Value * 100;

}

extern "C"   long Get_IFBALANCE(void)
{

    return SatGet3.Value * 10;

}

  extern "C" void Set_TFRAME( unsigned long Val)
  {
   char tmp = LockMode.Value; 
	LockMode.Value = 3; 
   if(theCntFunc.Control(SatTF.CntNum, Val))
	 {	
	  	SatTF.ChangingValue = Val;
		SatTF.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatTF.OprNum);
	 }
	LockMode.Value = tmp; 
  }
  extern "C" long Get_TFRAME()
  {

     printfpd("\n\r Get_TFRAME %d", SatTF.Value);

   return SatTF.Value;
  }
  
  extern "C" void Set_SLEVEL( signed long Val) 
  {
    char tmp = LockMode.Value; 
	  printfpd("\n\rSet_SLEVEL %d",Val);

	LockMode.Value = 3; 
   if(theCntFunc.Control(SatSet3.CntNum, Val))
	 {	
	  	SatSet3.ChangingValue = Val;
		SatSet3.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet3.OprNum);
	 }
	LockMode.Value = tmp; 
  }

  extern "C" long Get_SLEVEL()
  {
     return SatSet3.Value;
  }
  
  extern "C" void Set_UPLINKMODE( unsigned long Val) 
  {
   char tmp = LockMode.Value; 
	LockMode.Value = 3; 
	Val -= 1;
   if(theCntFunc.Control(SatTiming.CntNum, Val))
	 {	
	   SatTiming.ChangingValue = Val;
		SatTiming.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatTiming.OprNum);
	 }
	LockMode.Value = tmp; 

  }

  extern "C" long Get_UPLINKMODE()
  {
   return SatTiming.Value + 1;
  }
  
  extern "C" void Set_TESTMODE( unsigned long Val) 
  {
   char tmp = LockMode.Value; 
	LockMode.Value = 3; 
	Val -= 1;
   if(theCntFunc.Control(SatTestMode.CntNum, Val))
	 {	
	   SatTestMode.ChangingValue = Val;
		SatTestMode.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatTestMode.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_TESTMODE()
  {
   return SatTestMode.Value + 1;
  }
  
  extern "C" void Set_EXTLOCK( unsigned long Val) 
  {
      char tmp = LockMode.Value; 
	LockMode.Value = 3; 
	Val -= 1;
   if(theCntFunc.Control(SatExtLock.CntNum, Val))
	 {	
	   SatExtLock.ChangingValue = Val;
		SatExtLock.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatExtLock.OprNum);
	 }
	LockMode.Value = tmp; 


  }

  extern "C" long Get_EXTLOCK()
  {
   return SatExtLock.Value + 1;
  }
  
  extern "C" void Set_EXTLOCKP( unsigned long Val) 
  {
      char tmp = LockMode.Value; 
	LockMode.Value = 3; 
	Val -= 1;
   if(theCntFunc.Control(SatExtLockP.CntNum, Val))
	 {	
	   SatExtLockP.ChangingValue = Val;
		SatExtLockP.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatExtLockP.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_EXTLOCKP()
  {
   return SatExtLockP.Value + 1;
  }
  
  extern "C" void Set_ALARM( unsigned long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
	Val -= 1;
   if(theCntFunc.Control(SatSound.CntNum, Val))
	 {	
	   SatSound.ChangingValue = Val;
		SatSound.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSound.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_ALARM()
  {
   return SatSound.Value + 1;
  }
//______________________

 extern "C" void Set_ANALOGFILTER( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
  //	Val -= 1;
   if(theCntFunc.Control(SatSet6.CntNum, Val))
	 {	
	   SatSet6.ChangingValue = Val;
		SatSet6.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet6.OprNum);
	 }
	LockMode.Value = tmp; 



  }


  extern "C" long Get_ANALOGFILTER()
  {
   return SatSet6.Value;
  }


  extern "C" void Set_DIGITALFILTER( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
     if(theCntFunc.Control(SatDF.CntNum, Val))
	 {	
	   SatDF.ChangingValue = Val;
		SatDF.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatDF.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_DIGITALFILTER()
  {
   return SatDF.Value;
  }


  extern "C" void Set_UNLOCKTIMER( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
    if(theCntFunc.Control(SatTimer.CntNum, Val))
	 {	
	   SatTimer.ChangingValue = Val;
		SatTimer.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatTimer.OprNum);
	 }
	LockMode.Value = tmp; 



  }
 
  extern "C" long Get_UNLOCKTIMER()
  {
   return SatTimer.Value;
  }


  extern "C" void Set_PROCESSINGFREQ( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
     if(theCntFunc.Control(SatSet0.CntNum, Val))
	 {	
	   SatSet0.ChangingValue = Val;
	   SatSet0.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet0.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_PROCESSINGFREQ()
  {
   return SatSet0.Value;
  }


  extern "C" void Set_PROCESSINGOFFSET( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
      if(theCntFunc.Control(SatSet8.CntNum, Val))
	 {	
	   SatSet8.ChangingValue = Val;
		SatSet8.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet8.OprNum);
	 }
	LockMode.Value = tmp; 



  }
 
  extern "C" long Get_PROCESSINGOFFSET()
  {
   return SatSet8.Value;
  }


  extern "C" void Set_ACCESSCODE( signed long Val) 
  {
    printfpd("\n\rSet_ACCESSCODE %d",Val);

       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
      if(theCntFunc.Control(SatACode.CntNum, Val))
	 {
	 	 printfp("...ok");
	   SatACode.ChangingValue = Val;
		SatACode.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatACode.OprNum);
	 }
	 else
	 {
	    printfp("...wrong");

	 }
	LockMode.Value = tmp; 



  }
 
  extern "C" unsigned long Get_ACCESSCODE()
  {
 return 1;

  }


  extern "C" void Set_ACCESSLEVEL( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
      if(theCntFunc.Control(SatSet8.CntNum, Val))
	 {	
	   SatSet8.ChangingValue = Val;
		SatSet8.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatSet8.OprNum);
	 }
	LockMode.Value = tmp; 



  }

  extern "C" long Get_ACCESSLEVEL()
  {
 return SatALev.Value;

  }


  extern "C" void Set_DEMOMODE( signed long Val) 
  {
       char tmp = LockMode.Value; 
	LockMode.Value = 3; 
      if(theCntFunc.Control(SatADemo.CntNum, Val))
	 {	
	   SatADemo.ChangingValue = Val;
		SatADemo.Value = Val;
	  //	WriteStorageC(StorageAddr,Value);
	 	theCntFunc.Operate(SatADemo.OprNum);
	 }
	LockMode.Value = tmp; 



  }
 
  extern "C" long Get_DEMOMODE() 
  {
 return SatADemo.Value;

  }


 // extern "C" long Get_FPGAVER();
 // extern "C" long Get_PROGVER();

extern "C"   unsigned char * Get_FPGAVER(unsigned long* len)
{
 *len = 24;
// static char S[] = "Hello";
  return  XilFileData.Value;

//  memcpy((Key+15), XilFileData.Value, 24); 
}
extern "C"   unsigned char * Get_PROGVER(unsigned long* len)
{
  *len = 24;
// static char S[] = "Hello";
  return (unsigned char *)&theAnyStrings.cVersion[0];
   //  memcpy((Key+15), &theAnyStrings.cVersion[0], 24);  

}












