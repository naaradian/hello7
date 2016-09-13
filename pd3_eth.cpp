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


//#define ANSWER_LEN	 (32)
#define ANSWER_LEN	 (2)
#define RX_BUFF_SIZE (64)

//#define DELAY_RECEIVE	(1000)
//#define DELAY_RECEIVE	(100)
#define DELAY_RECEIVE	(10)

#define MASK_REQUEST  (0x80)

#define ANS_WRONG  (0xff)
#define ANS_OK	  (0x1)



char * SpiWriteCS2PD ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
    
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




  //	static char RxBuff[ANSWER_LEN];
	static char RxBuff[RX_BUFF_SIZE];
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
																
    delay_mcs(DELAY_RECEIVE); //101113

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
   //	return 1;
   return RxBuff;
}

char * SpiWriteCS2PD_Fast ( unsigned long len, unsigned long pData)
{
   	unsigned int timeout;
    
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1

  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
  //	 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3




  //	static char RxBuff[ANSWER_LEN];
	static char RxBuff[RX_BUFF_SIZE];
   //	static char TxBuff[] = {0x55, 0x33, 0x11};

	  //	if( AT91C_BASE_SPI->SPI_TCR) return 0;
	//	 if(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF)) return 0;

//AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
//select needed flash:
//		test
 	//	AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIDIS;

	//	AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
   	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
   	 //  	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);



  //	   AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
	
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
 //	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;
 //  	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN;
   
 //101113  	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));
																
    delay_mcs(DELAY_RECEIVE); //101113

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
   //	return 1;
   return RxBuff;
}









//#ifdef TEST_PRINT_SPI
if(GetTestMode() == 0x50)
//if(1)
{
printfp("\n\r Answer :");
//printfpd("len: %d \n\r data : ", len);
}
//#endif
unsigned long len1 = len;
unsigned char ReqFlag = (IPBuff[0] &  MASK_REQUEST) ? 1 : 0;
unsigned char SB = IPBuff[1]; //secod byte is data
unsigned char AB;
char * ans; 

// char * ans  = SpiWriteCS2PD (len, (unsigned long)&IPBuff[0]);	   //hier send command
//char * ans = SpiWriteCS2PD (1, *IPBuff);	   //hier send command

 add_char_TCP_buff(IPBuff[0]);


for(long j = 0; j< len; j++)
{
ans = SpiWriteCS2PD (1, (unsigned long)&IPBuff[j]);	


 if(GetTestMode() == 0x50)
//if(1)
{
printfpd(" %02X ", *ans);
}



 add_char_TCP_buff(*ans);

}



char RqBuff[ANSWER_LEN];
RqBuff[0] =   *IPBuff | MASK_REQUEST;

for(long i = 1; i<= (ANSWER_LEN - 1); i++)
{
RqBuff[i] = 0xff;
}
 /* 
if(!ReqFlag)
{
ans = SpiWriteCS2PD (ANSWER_LEN, (unsigned long)&RqBuff[0]);	 //hier read answer
ans++;
AB = *ans;;
ans--;
}
   */

// RqBuff[0] = 0x55;
//char * ans = SpiWriteCS2PD (ANSWER_LEN, (unsigned long)&RqBuff[0]);

if(GetTestMode() == 0x50)
//if(1)
{
printfp(" for  TCP");
printfpd(" len: %d  data : ", len);
}


if(GetTestMode() == 0x50)
{
 while(len1--)
{
//#ifdef TEST_PRINT_SPI
 printfpd(" %02X", (unsigned char)*IPBuff++);
}
//#endif
// OperateCommand(IPBuff++);
}



len1 =ANSWER_LEN;

//hier need add answer
// printfpd("time1 :  %d", time1);
//  printfpd("timerun :  %d", timerun);
 // breakflag = 1;
// timerun = time1;

 //hier need add breakflag
//while((time1-timerun) < (TIME_WAIT_SPI_ETH))
  //	{ 
   //	  PRM_PCH();
   //	  if(!breakflag) break;
   //	}
// printfpd("time1 :  %d", time1);
 // printfpd("timerun :  %d", timerun);
	/*

 if(GetTestMode() == 0x50)
 {
 printfp("\n\r Answer :");
 }

 	while(len1--)
	{
// add_char_TCP_buff('O');
// add_char_TCP_buff('k');
// add_char_TCP_buff('!');
 if(GetTestMode() == 0x50)
 {
   printfpd(" %02X", (unsigned char)*ans);
 }

  if(ReqFlag)
  {
    add_char_TCP_buff(*ans);
  }

   ans++;
	}
//}

 if(!ReqFlag)
{

  // if(SB == AB)
   if(1)
   {
	  add_char_TCP_buff(ANS_OK);
  if(GetTestMode() == 0x50)
 {
 printfp("\n\r...Ok!");
 }
   }
   else
   {
	  add_char_TCP_buff(ANS_WRONG);
 if(GetTestMode() == 0x50)
 {
 printfp("\n\r...Wromg!");
 }

   }

}
*/

breakflag = 1;

return;