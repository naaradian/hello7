//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : at45c.h
//* Object              : 
//*
//* 1.0 10/12/03 HIi    : Creation
//*----------------------------------------------------------------------------

//#include <AT91RM9200.h>
//#include <lib_AT91RM9200.h>
#include <dataflash.h>
//#include <main.h>
#include <hello7.h>
//#include <mqx.h>
//#include <bsp.h>

extern "C" void cashe_off();
extern "C" void cashe_on();



//bad work #define AT91C_SPI_CLK 10000000
//#define AT91C_SPI_CLK 1000000    //t - ok
//#define AT91C_SPI_CLK  2000000    //t - ok
#define AT91C_SPI_CLK   1000000    //150817 for test
//ok #define AT91C_SPI_CLK   5000000    //150817 for test
#define AT91C_SPI_CLK10 10000000  
#define AT91C_SPI_CLK5   5000000  
#define AT91C_SPI_CLK2   2000000  


//#define AT91C_SPI_CLK 1500000    //
//t #define AT91C_SPI_CLK 5000000    //t - ok
//#define AT91C_SPI_CLK 8000000  //t -ok
#define AT91C_SPI_PCS0_SERIAL_DATAFLASH		0xE     /* Chip Select 0 : NPCS0 %1110 */
#define AT91C_SPI_PCS3_DATAFLASH_CARD		   0x7     /* Chip Select 3 : NPCS3 %0111 */
#define AT91C_SPI_PCS1_SERIAL_DATAFLASH		0xD     /* Chip Select 1 : NPCS1 %1101 */
#define AT91C_SPI_PCS2_SERIAL_DATAFLASH		0xB     /* Chip Select 2 : NPCS2 %1011 */
#define AT91C_SPI_PCS3_SERIAL_DATAFLASH		0x7     /* Chip Select 3 : NPCS3 %0111 */



/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiInit						      							  */
/* \brief SPI Low level Init												  */
/*----------------------------------------------------------------------------*/
void AT91F_SpiInit(void) {
 unsigned long tmp;
// AT91RM9200_PMC_REG_STRUCT_PTR  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE; /* Power Management Controller; */
 	/* Configure PIOs */
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 0, AT91RM9200_PIO_PERIPHERAL_A, 0); 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 2, AT91RM9200_PIO_PERIPHERAL_A, 0); 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 3, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs0
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs1
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs2
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);   //cs3


//	AT91C_BASE_PIOA->PIO_ASR = AT91C_PA3_NPCS0 | AT91C_PA4_NPCS1 | AT91C_PA1_MOSI | AT91C_PA5_NPCS2 |
//				   AT91C_PA6_NPCS3 | AT91C_PA0_MISO | AT91C_PA2_SPCK;
//	AT91C_BASE_PIOA->PIO_PDR = AT91C_PA3_NPCS0 | AT91C_PA4_NPCS1 | AT91C_PA1_MOSI | AT91C_PA5_NPCS2 |
//				   AT91C_PA6_NPCS3 | AT91C_PA0_MISO | AT91C_PA2_SPCK;
	/* Enable CLock */
//	AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_SPI;
  tmp =   *AT91C_PMC_PCER;
 *AT91C_PMC_PCER = tmp | (1 << AT91C_ID_SPI);

	/* Reset the SPI */
 	AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SWRST;
// *AT91C_SPI_CR = AT91C_SPI_SWRST;

    	/* Configure SPI in Master Mode with No CS selected !!! */
	AT91C_BASE_SPI->SPI_MR = AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PCS;

	/* Configure CS0 and CS3 */
	*(AT91C_SPI_CSR + 0) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK)) << 8);

//	*(AT91C_SPI_CSR + 3) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK)) << 8);
   *(AT91C_SPI_CSR + 3) = (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK)) << 8);

#ifndef PROG_PD3
  *(AT91C_SPI_CSR + 2) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK)) << 8);
#else
   *(AT91C_SPI_CSR + 2) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK2)) << 8);
//   *(AT91C_SPI_CSR + 2) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK10)) << 8);
#endif



//#ifndef PROG_PD3  
   *(AT91C_SPI_CSR + 1) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK)) << 8);
//#else
// *(AT91C_SPI_CSR + 1) = AT91C_SPI_CPOL | (AT91C_SPI_DLYBS & 0x100000) | ((AT91C_MASTER_CLOCK / (2*AT91C_SPI_CLK10)) << 8);
//#endif   

}


/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiEnable					      							  */
/* \brief Enable SPI chip select											  */
/*----------------------------------------------------------------------------*/
void AT91F_SpiEnable(int cs) {
//if(start_main_loop)
//printfpd("\n\r  AT91F_SpiEnable %d", cs);


	switch(cs) {
	case 0:	/* Configure SPI CS0 for Serial DataFlash AT45DBxx */
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS0_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
		break;
	case 3:	/* Configure SPI CS3 for Serial DataFlash Card */
		/* Set up PIO SDC_TYPE to switch on DataFlash Card and not MMC/SDCard */
  //not need now		AT91C_BASE_PIOB->PIO_PER = AT91C_PIO_PB7;	/* Set in PIO mode */
  //not need now		AT91C_BASE_PIOB->PIO_OER = AT91C_PIO_PB7;	/* Configure in output */
		/* Clear Output */
  //not need now		AT91C_BASE_PIOB->PIO_CODR = AT91C_PIO_PB7;
		/* Configure PCS */
  		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
  	//	AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS3_DATAFLASH_CARD<<16) & AT91C_SPI_PCS);
      AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS3_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
		break;
   case 1:	/* Configure SPI CS1 for Serial DataFlash AT45DBxx */
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS1_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
		break;
      
   case 2:	/* Configure SPI CS1 for Serial DataFlash AT45DBxx */
		AT91C_BASE_SPI->SPI_MR &= 0xFFF0FFFF;
		AT91C_BASE_SPI->SPI_MR |= ((AT91C_SPI_PCS2_SERIAL_DATAFLASH<<16) & AT91C_SPI_PCS);
      
        break;
      
	}

	/* SPI_Enable */
	AT91C_BASE_SPI->SPI_CR = AT91C_SPI_SPIEN;
}

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiWrite						                              */
/* \brief Set the PDC registers for a transfert				                  */
/*----------------------------------------------------------------------------*/
unsigned int AT91F_SpiWrite ( AT91PS_DataflashDesc pDesc)
{
   	unsigned int timeout;
	
	pDesc->state = BUSY;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

   	/* Initialize the Transmit and Receive Pointer */
    	AT91C_BASE_SPI->SPI_RPR = (unsigned int)pDesc->rx_cmd_pt ;
    	AT91C_BASE_SPI->SPI_TPR = (unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
    	AT91C_BASE_SPI->SPI_RCR = pDesc->rx_cmd_size;
    	AT91C_BASE_SPI->SPI_TCR = pDesc->tx_cmd_size;

	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   	}

     /* arm simple, non interrupt dependent timer */
	timeout = 0;

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;

   	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
   	pDesc->state = IDLE;

	if (timeout >= AT91C_DATAFLASH_TIMEOUT){
		return AT91C_DATAFLASH_ERROR;
	}

	return AT91C_DATAFLASH_OK;
}

#ifdef XIL_FLASH

void pvg610HostSpiDataReceivex(unsigned char , unsigned char *, unsigned char *, unsigned long );
//void WriteSpiBm(unsigned char , unsigned long , unsigned char * );
/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiWritex						                              */
/* \brief Set the PDC registers for a transfert				                  */
/*----------------------------------------------------------------------------*/
extern "C" unsigned int AT91F_SpiWritex (unsigned char deviceindex, AT91PS_DataflashDesc pDesc)
{
 //  unsigned int timeout;
 //	pDesc->state = BUSY;
 
 //   printfp("\n\r AT91F_SpiWritex");
 //   OperateBuffers_usart0t();
//   void WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
  //    WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->rx_cmd_pt); //1 - temporary

//   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

   	/* Initialize the Transmit and Receive Pointer */
//    	AT91C_BASE_SPI->SPI_RPR = (unsigned int)pDesc->rx_cmd_pt ;
//    	AT91C_BASE_SPI->SPI_TPR = (unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
//    	AT91C_BASE_SPI->SPI_RCR = pDesc->rx_cmd_size;
//    	AT91C_BASE_SPI->SPI_TCR = pDesc->tx_cmd_size;

  //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
//	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
//		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
  //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
  //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
//	timeout = 0;

   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;

   //	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
    //	pDesc->state = IDLE;
//     WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->tx_cmd_pt); //1 - temporary
//pvg610HostSpiDataSend(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen) 
//120627     pvg610HostSpiDataSendx(deviceindex, pDesc->tx_cmd_pt, pDesc->tx_cmd_size); //1 -temporary    need make support big volumes     
//void pvg610HostSpiDataReceive(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)  
 //   if(pDesc->rx_data_size) 
 //    { 
   //       printfp("\n\r (pDesc->rx_data_size != 0");
//120627          pvg610HostSpiDataReceivex(deviceindex, pDesc->tx_cmd_pt, pDesc->rx_data_pt , pDesc->rx_data_size); //1 - temporary    
   //  }
  /* 
//___________________________________temporary
   if(pDesc->rx_cmd_size > 10 )  pDesc->rx_cmd_size = 10;
   if(pDesc->tx_cmd_size > 10 )  pDesc->tx_cmd_size = 10;
   if(pDesc->rx_data_size > 10 )  pDesc->rx_data_size = 10;
   if(pDesc->tx_data_size > 10 )  pDesc->tx_data_size = 10;
 
 //____________________________      

      */

   char tmpBuffer[500]; //???? 1000 ok?
   char * ptmpBuffer = & tmpBuffer[0];
   char tmpBufferR[500]; //???? 1000 ok?
   char * ptmpBufferR = & tmpBufferR[0];
   char * pkeepBufferR =  pDesc->rx_cmd_pt;
   
   char * panyBuffer;
   unsigned long wlen = pDesc->tx_cmd_size;
  
//_____________________________
   ptmpBuffer = & tmpBuffer[0];
   wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size + pDesc->rx_data_size;
  
 //    printfp("\n\r________________\n\r");
 //  printfpd ("\n\rAT91F_SpiWritex len  %d",wlen);
 //  printfpd (" deviceindex:  %d",deviceindex);
 
     
    while(wlen--){  
                 *ptmpBuffer++ = 0;
                   } 

  // wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size + pDesc->rx_data_size ;
   
  
   //   printfp("\n\r________________\n\r");


//__________________________          
   
 //  pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size);  
  
//   char tmpBuffer[1000]; //???? 1000 ok?




   ptmpBuffer = & tmpBuffer[0];
   
   wlen = pDesc->tx_cmd_size;
   
   
   
    panyBuffer = pDesc->tx_cmd_pt;
    
    
  //   printfpd ("\n\r wlen_cmd  %d \n\r",wlen);   //hier zero!!!!
  
  //  printfp ("\n\r send  cmd:");
 
   while(wlen--){  
             //         printfpd (" %02X",*panyBuffer);
                      *ptmpBuffer++ = *panyBuffer++;
                } 
                
   //   printfp (" finish of send cmd \n\r");
            
                
   wlen = pDesc->tx_data_size;
   
   
      panyBuffer = pDesc->tx_data_pt;
         //?????tx datapt is crash?
         
    //   printfpd ("\n\r wlen_data  %d \n\r",wlen);   //hier zero!!!!
   
         
        //      printfp ("\n\r send  data:");

     while(wlen--){  
              //     printfpd (" %02X",*panyBuffer);
                   *ptmpBuffer++ = *panyBuffer++;
                   } 
                   
              //       printfp (" finish of send data \n\r");

                   
//_____________________________
  ptmpBuffer = & tmpBuffer[0];
  
  wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size + pDesc->rx_data_size;
  
  //   printfp("\n\r________________\n\r");
  //  printfpd ("\n\rwlen  %d",wlen);
  //     printfpd ("\n\rrx cmd  %d",pDesc->rx_cmd_size);
  //     printfpd ("\n\rrx dat  %d",pDesc->rx_data_size);
  //     printfpd ("\n\rtx cmd  %d",pDesc->tx_cmd_size);
  //     printfpd ("\n\rtx dat  %d",pDesc->tx_data_size);
       
  //     printfp("\n\r________________\n\r");
   //      OperateBuffers_usart0t();
     
  //  while(wlen--){  
    //             printfpd (" %02X",*ptmpBuffer++);
      //             } 

 
     // printfp("\n\r________________\n\r");


//__________________________                   
  //   pDesc->tx_cmd_pt = &tmpBuffer[0];
  //    pDesc->rx_cmd_pt = &tmpBufferR[0];

    wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size + pDesc->rx_data_size + pDesc->rx_cmd_size;
   
    //   printfpd (" wlen  %d",wlen);
     //  printfpd (" rx cmd  %d",pDesc->rx_cmd_size);
    //   printfpd (" rx dat  %d",pDesc->rx_data_size);
    //   printfpd (" tx cmd  %d",pDesc->tx_cmd_size);
    //   printfpd (" tx dat  %d",pDesc->tx_data_size);
     //  OperateBuffers_usart0t();
 
//   printfpd("\n\r>>> %X", *pDesc->tx_data_pt);
      

//    pDesc->tx_cmd_size += pDesc->tx_data_size  + pDesc->rx_data_size + pDesc->rx_cmd_size;
     
 //t    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size); 
//ok     pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + 2); 

//ok     pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + 5); 

 //    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt,
 
  //   wlen += 20;//t
     
 //  printfpd ("\n\r wlen send-receive  %d \n\r",wlen);   
 
 

#ifdef PR_FL 
        if(start_main_loop)
  { 


 
//  printfpd ("\n\r call pvg610HostSpiDataSendReceivex deviceindex :0x%X \n\r", deviceindex);

  }


#endif 
  
 
 
#ifndef HIDE_OLD
     pvg610HostSpiDataSendReceivex(deviceindex,  &tmpBuffer[0], &tmpBufferR[0], wlen);
#endif     
     
  //ok    pDesc->tx_cmd_size +  3);
 //     pDesc->tx_cmd_size + // 5);
 //     pDesc->tx_data_size  + pDesc->rx_data_size + pDesc->rx_cmd_size); 
 //t   pDesc->tx_data_size  + pDesc->rx_data_size); // + pDesc->rx_cmd_size); 
  //  pDesc->tx_data_size  + pDesc->rx_data_size); // + pDesc->rx_cmd_size); 
   //    wlen);
  //   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, wlen);        
 
  
//   pDesc->tx_cmd_pt = &tmpBuffer[0];
   
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
 //   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size); //t 
								  //		BYTE *pRxBuff,UINT32 buffLen)

    
//this make individual cs for data - it is wrong!!!!!!

//  if ( pDesc->tx_data_size != 0 )
//   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_data_pt, pDesc->rx_data_pt, pDesc->tx_data_size);  
//this make individual cs for data - it is wrong!!!!!!
   
   //  else{ 
   //          printfp("\n\r (pDesc->rx_data_size == 0");

  // } 
     
 //	if (timeout >= AT91C_DATAFLASH_TIMEOUTX){
  //		return AT91C_DATAFLASH_ERROR;
 //	}
 
 //pDesc->state = IDLE; //120625

    //      printfp("\n\rr cmd :");
     
     ptmpBufferR = &tmpBufferR[0];
     
// printfpd("\n\r+> %X", *pDesc->tx_data_pt);
     
         for(unsigned ik=0; ik<8; ik++ )
         {
      //   printfpd(" %02X", *ptmpBufferR);
           *pkeepBufferR++ =  *ptmpBufferR++;
         } 
// printfpd("\n\r+>> %X", *pDesc->tx_data_pt);    

//hier is crashed in get status   

 //printfpd("\n\r rx_data_size : %d \n\r", pDesc->rx_data_size);
                       
    //      printfp(" r data: ");
          ptmpBufferR = &tmpBufferR[pDesc->tx_cmd_size + pDesc->tx_data_size];
          pkeepBufferR = pDesc->rx_data_pt;
          
      // for( ik= pDesc->tx_cmd_size + pDesc->tx_data_size; ik< pDesc->tx_cmd_size + pDesc->tx_data_size+ pDesc->rx_data_size; ik++ )
            for( ik= 0; ik< pDesc->rx_data_size ; ik++ )
     //  for( ik= 0; ik< wlen; ik++ )
         {
       //  printfpd(" %02X ", *ptmpBufferR);
           *pkeepBufferR++ =  *ptmpBufferR++;
         } 
 //printfp("\n\r");        
//  printfpd("\n\r+>>> %X", *pDesc->tx_data_pt);

	return AT91C_DATAFLASH_OK;
}
   /*
extern "C" unsigned int AT91F_SpiWritexW (unsigned char deviceindex, AT91PS_DataflashDesc pDesc)
{
   unsigned int timeout;
 //	pDesc->state = BUSY;
    printfp("\n\r AT91F_SpiWritexW");
   
//   void WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
  //    WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->rx_cmd_pt); //1 - temporary

//   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;


 
   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;

   //	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
    //	pDesc->state = IDLE;
//     WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->tx_cmd_pt); //1 - temporary
//pvg610HostSpiDataSend(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen) 
//120627     pvg610HostSpiDataSendx(deviceindex, pDesc->tx_cmd_pt, pDesc->tx_cmd_size); //1 -temporary    need make support big volumes     
//void pvg610HostSpiDataReceive(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)  
 //   if(pDesc->rx_data_size) 
 //    { 
   //       printfp("\n\r (pDesc->rx_data_size != 0");
//120627          pvg610HostSpiDataReceivex(deviceindex, pDesc->tx_cmd_pt, pDesc->rx_data_pt , pDesc->rx_data_size); //1 - temporary    
   //  }
   char tmpBuffer[1000]; //???? 1000 ok?
   char * ptmpBuffer = & tmpBuffer[0];
   char * panyBuffer;
   unsigned long wlen = pDesc->tx_cmd_size;
  
//_____________________________
   ptmpBuffer = & tmpBuffer[0];
     wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size;
  
 //    printfp("\n\r________________\n\r");
     
    while(wlen--){  
                 *ptmpBuffer++ = 0;
                   } 

  // wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size + pDesc->rx_data_size ;
   
 //   printfpd ("\n\r  %d",wlen);
    
   //   printfp("\n\r________________\n\r");


//__________________________          
   
 //  pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size);  
  
//   char tmpBuffer[1000]; //???? 1000 ok?

   ptmpBuffer = & tmpBuffer[0];
   wlen = pDesc->tx_cmd_size;
    panyBuffer = pDesc->tx_cmd_pt;
   while(wlen--){  
                 *ptmpBuffer++ = *panyBuffer++;
                } 
   wlen = pDesc->tx_data_size;
      panyBuffer = pDesc->tx_data_pt;

     while(wlen--){  
                 *ptmpBuffer++ = *panyBuffer++;
                   } 
                   
//_____________________________
  ptmpBuffer = & tmpBuffer[0];
  
  wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size;
  
     printfp("\n\r________________\n\r");
      printfpd ("\n\rcmds:%d \n\r ",pDesc->tx_cmd_size);
       printfpd ("\n\rdats:%d \n\r ",pDesc->tx_data_size);
       printfp("\n\r________________\n\r");
     
    while(wlen--){  
                 printfpd (" %02X",*ptmpBuffer++);
                   } 

 
      printfp("\n\r________________\n\r");


//__________________________                   
     pDesc->tx_cmd_pt = &tmpBuffer[0];
    
    wlen = pDesc->tx_data_size +   pDesc->tx_cmd_size;
   //  printfpd ("\n\r  %d",wlen);
       printfpd ("\n\rrx cmd  %d",pDesc->rx_cmd_size);
       printfpd ("\n\rrx dat  %d",pDesc->rx_data_size);
       printfpd ("\n\rtx cmd  %d",pDesc->tx_cmd_size);
       printfpd ("\n\rtx dat  %d",pDesc->tx_data_size);
       
 //___________________________________temporary
   if(pDesc->rx_cmd_size > 10 )  pDesc->rx_cmd_size = 10;
   if(pDesc->tx_cmd_size > 10 )  pDesc->tx_cmd_size = 10;
   if(pDesc->rx_data_size > 10 )  pDesc->rx_data_size = 10;
   if(pDesc->tx_data_size > 10 )  pDesc->tx_data_size = 10;
 
 //____________________________      
       

//    pDesc->tx_cmd_size += pDesc->tx_data_size  + pDesc->rx_data_size + pDesc->rx_cmd_size;
     
 //t    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size); 
//ok     pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + 2); 

//ok     pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + 5); 

     pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt,
  //    pDesc->tx_cmd_size +       pDesc->tx_data_size);//  + pDesc->rx_data_size + pDesc->rx_cmd_size); 
    wlen);
 
  //bad dvice is crashed!!!!   pDesc->tx_data_size  + pDesc->rx_data_size); // + pDesc->rx_cmd_size); 

  //   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, wlen);        
 
  
//   pDesc->tx_cmd_pt = &tmpBuffer[0];
   
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
 //   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_cmd_pt, pDesc->tx_cmd_size + pDesc->tx_data_size + pDesc->rx_data_size);  
//    pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_cmd_pt, pDesc->rx_data_pt, pDesc->tx_cmd_size); //t 
								  //		BYTE *pRxBuff,UINT32 buffLen)

    
//this make individual cs for data - it is wrong!!!!!!

//  if ( pDesc->tx_data_size != 0 )
//   pvg610HostSpiDataSendReceivex(deviceindex,  pDesc->tx_data_pt, pDesc->rx_data_pt, pDesc->tx_data_size);  
//this make individual cs for data - it is wrong!!!!!!
   
   //  else{//  Body 
   //          printfp("\n\r (pDesc->rx_data_size == 0");

  // } // Endbody 
     
 //	if (timeout >= AT91C_DATAFLASH_TIMEOUTX){
  //		return AT91C_DATAFLASH_ERROR;
 //	}
 
 //pDesc->state = IDLE; //120625

     //     printfp("\n\r AT91F_SpiWritex");
 

	return AT91C_DATAFLASH_OK;
}
     */

extern "C" unsigned int AT91F_SpiWriteReadx (unsigned char deviceindex, AT91PS_DataflashDesc pDesc)
{
 //  unsigned int timeout;
 //	pDesc->state = BUSY;
  //  printfp("\n\r AT91F_SpiWriteReadx");

   
//   void WriteSpiBm(unsigned char deviceindex, unsigned long length_of_data, unsigned char * BufferData)
  //    WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->rx_cmd_pt); //1 - temporary

//   	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

   	/* Initialize the Transmit and Receive Pointer */
//    	AT91C_BASE_SPI->SPI_RPR = (unsigned int)pDesc->rx_cmd_pt ;
//    	AT91C_BASE_SPI->SPI_TPR = (unsigned int)pDesc->tx_cmd_pt ;

    	/* Intialize the Transmit and Receive Counters */
//    	AT91C_BASE_SPI->SPI_RCR = pDesc->rx_cmd_size;
//    	AT91C_BASE_SPI->SPI_TCR = pDesc->tx_cmd_size;

  //	if ( pDesc->tx_data_size != 0 ) {
	   	/* Initialize the Next Transmit and Next Receive Pointer */
//	   	AT91C_BASE_SPI->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
//		AT91C_BASE_SPI->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

		/* Intialize the Next Transmit and Next Receive Counters */
  //		AT91C_BASE_SPI->SPI_RNCR = pDesc->rx_data_size ;
  //	 	AT91C_BASE_SPI->SPI_TNCR = pDesc->tx_data_size ;
   //	}

     /* arm simple, non interrupt dependent timer */
//	timeout = 0;

   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTEN + AT91C_PDC_RXTEN;

   //	while(!(AT91C_BASE_SPI->SPI_SR & AT91C_SPI_RXBUFF));

   //	AT91C_BASE_SPI->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;
    //	pDesc->state = IDLE;
//     WriteSpiBm(1, pDesc->tx_cmd_size, pDesc->tx_cmd_pt); //1 - temporary
//pvg610HostSpiDataSend(BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen) 
#ifndef HIDE_OLD
     pvg610HostSpiDataSendx(deviceindex, pDesc->tx_cmd_pt, pDesc->tx_cmd_size); //1 -temporary    need make support big volumes     
//void pvg610HostSpiDataReceive(BYTE deviceIndex, BYTE *pTxBuff, BYTE *pRxBuff, UINT32 buffLen)  
 //   if(pDesc->rx_data_size) 
 //    { 
   //       printfp("\n\r (pDesc->rx_data_size != 0");
          pvg610HostSpiDataReceivex(deviceindex, pDesc->tx_cmd_pt, pDesc->rx_data_pt , pDesc->rx_data_size); //1 - temporary    
#endif


   //  }
   //  else{ /* Body */
   //          printfp("\n\r (pDesc->rx_data_size == 0");

  // } /* Endbody */
     
 //	if (timeout >= AT91C_DATAFLASH_TIMEOUTX){
  //		return AT91C_DATAFLASH_ERROR;
 //	}
 
 //pDesc->state = IDLE; //120625

     //     printfp("\n\r AT91F_SpiWritex");

	return AT91C_DATAFLASH_OK;
}



#endif




/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashSendCommand					*/
/* \brief Generic function to send a command to the dataflash		*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashSendCommand(
	AT91PS_DataFlash pDataFlash,
	unsigned char OpCode,
	unsigned int CmdSize,
	unsigned int DataflashAddress)
{
    unsigned int adr;

	if ( (pDataFlash->pDataFlashDesc->state) != IDLE)
		return AT91C_DATAFLASH_BUSY;

	/* process the address to obtain page address and byte address */
	adr = ((DataflashAddress / (pDataFlash->pDevice->pages_size)) << pDataFlash->pDevice->page_offset) + (DataflashAddress % (pDataFlash->pDevice->pages_size));

	/* fill the  command  buffer */
	pDataFlash->pDataFlashDesc->command[0] = OpCode;
//	if (pDataFlash->pDevice->pages_number >= 16384)
   if(0)
	{
		pDataFlash->pDataFlashDesc->command[1] = (unsigned char)((adr & 0x0F000000) >> 24);
		pDataFlash->pDataFlashDesc->command[2] = (unsigned char)((adr & 0x00FF0000) >> 16);
		pDataFlash->pDataFlashDesc->command[3] = (unsigned char)((adr & 0x0000FF00) >> 8);
		pDataFlash->pDataFlashDesc->command[4] = (unsigned char)(adr & 0x000000FF);
	}
	else
	{	
		pDataFlash->pDataFlashDesc->command[1] = (unsigned char)((adr & 0x00FF0000) >> 16);
		pDataFlash->pDataFlashDesc->command[2] = (unsigned char)((adr & 0x0000FF00) >> 8);
		pDataFlash->pDataFlashDesc->command[3] = (unsigned char)(adr & 0x000000FF) ;
		pDataFlash->pDataFlashDesc->command[4] = 0;
	}
	pDataFlash->pDataFlashDesc->command[5] = 0;
	pDataFlash->pDataFlashDesc->command[6] = 0;
	pDataFlash->pDataFlashDesc->command[7] = 0;

	/* Initialize the SpiData structure for the spi write fuction */
	pDataFlash->pDataFlashDesc->tx_cmd_pt   =  pDataFlash->pDataFlashDesc->command ;
	pDataFlash->pDataFlashDesc->tx_cmd_size =  CmdSize ;
	pDataFlash->pDataFlashDesc->rx_cmd_pt   =  pDataFlash->pDataFlashDesc->command ;
	pDataFlash->pDataFlashDesc->rx_cmd_size =  CmdSize ;

	return AT91F_SpiWrite (pDataFlash->pDataFlashDesc);
 //   return  (AT91S_DataFlashStatus)(0);	 //t		
}


#ifdef XIL_FLASH

/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashSendCommand					*/
/* \brief Generic function to send a command to the dataflash		*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashSendCommandx(
	AT91PS_DataFlash pDataFlash,
	unsigned char OpCode,
	unsigned int CmdSize,
	unsigned int DataflashAddress)
{
    unsigned int adr;

	if ( (pDataFlash->pDataFlashDesc->state) != IDLE)  { /* Body */
       printfp("\n\r pDataFlash->pDataFlashDesc->state) != IDLE");
		return AT91C_DATAFLASH_BUSY;}

	/* process the address to obtain page address and byte address */
	adr = ((DataflashAddress / (pDataFlash->pDevice->pages_size)) << pDataFlash->pDevice->page_offset) + (DataflashAddress % (pDataFlash->pDevice->pages_size));

	/* fill the  command  buffer */
	pDataFlash->pDataFlashDesc->command[0] = OpCode;
//	if (pDataFlash->pDevice->pages_number >= 16384)
   if(0)
	{
		pDataFlash->pDataFlashDesc->command[1] = (unsigned char)((adr & 0x0F000000) >> 24);
		pDataFlash->pDataFlashDesc->command[2] = (unsigned char)((adr & 0x00FF0000) >> 16);
		pDataFlash->pDataFlashDesc->command[3] = (unsigned char)((adr & 0x0000FF00) >> 8);
		pDataFlash->pDataFlashDesc->command[4] = (unsigned char)(adr & 0x000000FF);
	}
	else
	{	
		pDataFlash->pDataFlashDesc->command[1] = (unsigned char)((adr & 0x00FF0000) >> 16);
		pDataFlash->pDataFlashDesc->command[2] = (unsigned char)((adr & 0x0000FF00) >> 8);
		pDataFlash->pDataFlashDesc->command[3] = (unsigned char)(adr & 0x000000FF) ;
		pDataFlash->pDataFlashDesc->command[4] = 0;
	}
	pDataFlash->pDataFlashDesc->command[5] = 0;
	pDataFlash->pDataFlashDesc->command[6] = 0;
	pDataFlash->pDataFlashDesc->command[7] = 0;

	/* Initialize the SpiData structure for the spi write fuction */
	pDataFlash->pDataFlashDesc->tx_cmd_pt   =  pDataFlash->pDataFlashDesc->command ;
	pDataFlash->pDataFlashDesc->tx_cmd_size =  CmdSize ;
	pDataFlash->pDataFlashDesc->rx_cmd_pt   =  pDataFlash->pDataFlashDesc->command ;
	pDataFlash->pDataFlashDesc->rx_cmd_size =  0; //my CmdSize ;
 //   printfp("\n\r AT91F_DataFlashSendCommandx");

	return AT91F_SpiWritex (pDataFlash->pDevice->cs, pDataFlash->pDataFlashDesc);
 //   return  (AT91S_DataFlashStatus)(0);	 //t		
}




#endif




/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashGetStatus					*/
/* \brief Read the status register of the dataflash			*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashGetStatus(AT91PS_DataflashDesc pDesc)
{
	AT91S_DataFlashStatus status;

	/* if a transfert is in progress ==> return 0 */
	if( (pDesc->state) != IDLE)
		return AT91C_DATAFLASH_BUSY;

	/* first send the read status command (D7H) */
 //        for(;;){ /* Body */
  	pDesc->command[0] = DB_STATUS;
	pDesc->command[1] = 0;

	pDesc->DataFlash_state  = GET_STATUS;
    	pDesc->tx_data_size 	= 0 ;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_size 		= 2 ;
    	pDesc->tx_cmd_size 		= 2 ;
    //	pDesc->rx_cmd_size 		= 16 ;
    //	pDesc->tx_cmd_size 		= 16 ;
    
    	status = AT91F_SpiWrite (pDesc);
      
      
      

	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   //     } /* Endbody */
	return status;
}


/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashGetManufx					*/
/* \brief Read the status register of the dataflash			*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashGetManuf(AT91PS_DataflashDesc pDesc)
{                                                    
	AT91S_DataFlashStatus status;
   unsigned char tmp;
   
   
  //ok       return; //121003 for test
	/* if a transfert is in progress ==> return 0 */
   
 //    printfpd("\n\rAT91F_DataFlashGetStatusx: %d ", cs);
	if( (pDesc->state) != IDLE){ 
  //   printfp("\n\rAT91F_DataFlashGetStatusx:BUSY ");
  //         OperateBuffers_usart0t();
   		return AT91C_DATAFLASH_BUSY;
         }
         else{ /* Body */
     //     printfp("\n\rAT91F_DataFlashGetStatusx ");
       
      } /* Endbody */
                         /*
         	pDesc->command[0] = DB_RESET;
      pDesc->rx_data_size 	= 0;//1 ;
    	pDesc->tx_data_size 	= 3;	
     	pDesc->rx_cmd_size 		= 0;//2 ;
    	pDesc->tx_cmd_size 		= 1;//162 ;
     
            
            
	pDesc->command[1] = 0;
	pDesc->command[2] = 0;
	pDesc->command[3] = 0;
    
     status = AT91F_SpiWrite (pDesc);
  
               */
      

	/* first send the read status command (D7H) */
 //        for(;;){ /* Body */
    //    printfpd("\n\r> %X", *pDesc->tx_data_pt);
           /*
	   pDesc->DataFlash_state  = GET_STATUS;
      pDesc->rx_data_size 	= 5;//1 ;
    	pDesc->tx_data_size 	= 5;	// Transmit the command and receive response 
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_size 		= 1;//2 ;
    	pDesc->tx_cmd_size 		= 1;//162 ;
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
        //t	pDesc->command[0] = DB_MANUF;
        	pDesc->command[0] = 0xd7;
      	pDesc->command[1] = 0;
         	pDesc->command[2] = 0;
	pDesc->command[3] = 0;
	pDesc->command[4] = 0;
                  */
  //  	pDesc->command[0] = DB_MANUF;
 //	pDesc->command[1] = 0;
  //    printfpd("\n\r> %X", *pDesc->tx_data_pt);

	   pDesc->DataFlash_state  = GET_STATUS;
     //t pDesc->rx_data_size 	= 4;//1 ;
      pDesc->rx_data_size 	=6;//1 ;
    	pDesc->tx_data_size 	= 0;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
 //t   	pDesc->rx_cmd_size 		= 4;//2 ;
    	pDesc->rx_cmd_size 		= 6;//2 ;
    //	pDesc->tx_cmd_size 		= 1;//162 ;
  //  pDesc->tx_cmd_size 		= 4;  //read bc
    pDesc->tx_cmd_size 		= 6;  //read bc
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
        	pDesc->command[0] = DB_MANUF;
      	pDesc->command[1] = 0;
   	   pDesc->command[2] = 0;
      	pDesc->command[3] = 0;
         pDesc->command[4] = 0;
         pDesc->command[5] = 0;
    	         
    
    	status = AT91F_SpiWrite(pDesc);
      

   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
      
      
      
  //    printfpd("\n\r>> %X", *pDesc->tx_data_pt);
  
 // tmp =  *( (unsigned char *) (pDesc->rx_cmd_pt) +1);

 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
  
//#ifdef PR_FL	
     /*
   if(start_main_loop)
   { 
   printfpd("\n\rManuf read : %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)));    //ff
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+1));   //1f
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+2));   //28
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+3));   //00
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+4));   //01
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+5)); //0

     
   printfpd("manuf : %X ", * (unsigned char *)  pDesc->rx_cmd_pt);
   }
   
   */
   // printfpd("tmp : %X ", tmp);
 
//  #endif
  

  //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
// #endif  
   
   
   
 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_data_pt) +1);
 
 //  printfp("\n\rAT91F_DataFlashGetStatusx: pDesc->DataFlash_state =  ");
 //  printfpd(" %X ", pDesc->DataFlash_state);
 //   printfp("  pDesc->state : ");
 //  printfpd(" %X ",pDesc->state);
   //     } /* Endbody */
  //   OperateBuffers_usart0t();
	return status;
}



#ifdef XIL_FLASH

/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashGetStatusx					*/
/* \brief Read the status register of the dataflash			*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashGetStatusx(int cs,AT91PS_DataflashDesc pDesc)
{                                                    
	AT91S_DataFlashStatus status;
   unsigned char tmp;
   
//  if(start_main_loop){ 
   
  //  printfpd("\n\rAT91F_DataFlashGetStatusx %d", cs);
  //   OperateBuffers_usart0t();
    //     }
 
  //ok       return; //121003 for test
	/* if a transfert is in progress ==> return 0 */
   
 //    printfpd("\n\rAT91F_DataFlashGetStatusx: %d ", cs);
	if( (pDesc->state) != IDLE){ 
   //   if(start_main_loop){ 
   
    // printfp("\n\rpDesc->state) != IDLE");
   //  OperateBuffers_usart0t();
     //    }
  //         OperateBuffers_usart0t();
   		return AT91C_DATAFLASH_BUSY;
         }
         else{ /* Body */
     //     printfp("\n\rAT91F_DataFlashGetStatusx ");
       
      } /* Endbody */

	/* first send the read status command (D7H) */
 //        for(;;){ /* Body */
  	pDesc->command[0] = DB_STATUS;
	pDesc->command[1] = 0;
  //    printfpd("\n\r> %X", *pDesc->tx_data_pt);

	   pDesc->DataFlash_state  = GET_STATUS;
      pDesc->rx_data_size 	= 4;//1 ;
    	pDesc->tx_data_size 	= 0;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_size 		= 0;//2 ;
    	pDesc->tx_cmd_size 		= 1;//162 ;
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
    	status = AT91F_SpiWritex (cs,pDesc);
      

   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
      
      
      
  //    printfpd("\n\r>> %X", *pDesc->tx_data_pt);
  
  tmp =  *( (unsigned char *) (pDesc->rx_cmd_pt) +1);

	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
   
  #ifdef PR_FL	
   if(start_main_loop){ 
   

 // printfpd("\n\r read : %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)));
 //  printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+1));
 //  printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+2));
 //  printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+3));

 //  printfpd("state : %X ",  pDesc->DataFlash_state);
 //   printfpd("tmp : %X ", tmp);

  
//  #endif
  

  //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
  //     OperateBuffers_usart0t();
         }

   
   
   
   
 #endif  
   
   
   
 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_data_pt) +1);
 
 //  printfp("\n\rAT91F_DataFlashGetStatusx: pDesc->DataFlash_state =  ");
 //  printfpd(" %X ", pDesc->DataFlash_state);
 //   printfp("  pDesc->state : ");
 //  printfpd(" %X ",pDesc->state);
   //     } /* Endbody */
  //   OperateBuffers_usart0t();
	return status;
}


/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashGetManufx					*/
/* \brief Read the status register of the dataflash			*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashGetManufx(int cs,AT91PS_DataflashDesc pDesc)
{                                                    
	AT91S_DataFlashStatus status;
   unsigned char tmp;
   
   
  //ok       return; //121003 for test
	/* if a transfert is in progress ==> return 0 */
   
 //    printfpd("\n\rAT91F_DataFlashGetStatusx: %d ", cs);
	if( (pDesc->state) != IDLE){ 
  //   printfp("\n\rAT91F_DataFlashGetStatusx:BUSY ");
  //         OperateBuffers_usart0t();
   		return AT91C_DATAFLASH_BUSY;
         }
         else{ /* Body */
     //     printfp("\n\rAT91F_DataFlashGetStatusx ");
       
      } /* Endbody */
      
 

	/* first send the read status command (D7H) */
 //        for(;;){ /* Body */
 
 
 
  	pDesc->command[0] = DB_MANUF;
	pDesc->command[1] = 0;
  //    printfpd("\n\r> %X", *pDesc->tx_data_pt);
 #ifndef PROG_ODU10000
 
	   pDesc->DataFlash_state  = GET_STATUS;
      pDesc->rx_data_size 	= 4;//1 ;
    	pDesc->tx_data_size 	= 0;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_size 		= 0;//2 ;
    	pDesc->tx_cmd_size 		= 1;//162 ;
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
 #else     
         pDesc->DataFlash_state  = GET_STATUS;
     //t pDesc->rx_data_size 	= 4;//1 ;
      pDesc->rx_data_size 	=6;//1 ;
    	pDesc->tx_data_size 	= 0;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
 //t   	pDesc->rx_cmd_size 		= 4;//2 ;
    	pDesc->rx_cmd_size 		= 6;//2 ;
    //	pDesc->tx_cmd_size 		= 1;//162 ;
  //  pDesc->tx_cmd_size 		= 4;  //read bc
    pDesc->tx_cmd_size 		= 6;  //read bc
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
        	pDesc->command[0] = DB_MANUF;
      	pDesc->command[1] = 0;
   	   pDesc->command[2] = 0;
      	pDesc->command[3] = 0;
         pDesc->command[4] = 0;
         pDesc->command[5] = 0;

      
      
  #endif    
      
    	status = AT91F_SpiWritex (cs, pDesc);
      

   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
      
      
      
  //    printfpd("\n\r>> %X", *pDesc->tx_data_pt);
  
  tmp =  *( (unsigned char *) (pDesc->rx_cmd_pt) +1);

 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
   if(start_main_loop)
  { 
   
  #ifdef PR_FL	
   printfpd("\n\rManuf read : %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+1));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+2));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+3));

   printfpd("manuf : %X ", * (unsigned char *)  pDesc->rx_cmd_pt);
   // printfpd("tmp : %X ", tmp);
   
  
//  #endif
  

  //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
   
   
   
 #endif  
    }
   
   
 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_data_pt) +1);
 
 //  printfp("\n\rAT91F_DataFlashGetStatusx: pDesc->DataFlash_state =  ");
 //  printfpd(" %X ", pDesc->DataFlash_state);
 //   printfp("  pDesc->state : ");
 //  printfpd(" %X ",pDesc->state);
   //     } /* Endbody */
  //   OperateBuffers_usart0t();
	return status;
}

/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashGetStatusx					*/
/* \brief Read the status register of the dataflash			*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashReset(int cs,AT91PS_DataflashDesc pDesc)
{                                                    
	AT91S_DataFlashStatus status;
   unsigned char tmp;
   
   
  //ok       return; //121003 for test
	/* if a transfert is in progress ==> return 0 */
   
 //    printfpd("\n\rAT91F_DataFlashGetStatusx: %d ", cs);
	if( (pDesc->state) != IDLE){ 
  //   printfp("\n\rAT91F_DataFlashGetStatusx:BUSY ");
  //         OperateBuffers_usart0t();
   		return AT91C_DATAFLASH_BUSY;
         }
         else{ /* Body */
     //     printfp("\n\rAT91F_DataFlashGetStatusx ");
       
      } /* Endbody */

	/* first send the read status command (D7H) */
 //        for(;;){ /* Body */
  	pDesc->command[0] = DB_RESET;
	pDesc->command[1] = 0;
	pDesc->command[2] = 0;
	pDesc->command[3] = 0;


  //    printfpd("\n\r> %X", *pDesc->tx_data_pt);

	   pDesc->DataFlash_state  = GET_STATUS;
      pDesc->rx_data_size 	= 0;//1 ;
    	pDesc->tx_data_size 	= 0;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_pt 		= pDesc->command ;
    	pDesc->rx_cmd_size 		= 0;//2 ;
    	pDesc->tx_cmd_size 		= 4;//162 ;
      
      pDesc->rx_data_pt 		= pDesc->command ; //my
      
    	status = AT91F_SpiWritex (cs,pDesc);
      

   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
   // 	status = AT91F_SpiWritex (cs,pDesc);   //t
      
      
      
  //    printfpd("\n\r>> %X", *pDesc->tx_data_pt);
  
  tmp =  *( (unsigned char *) (pDesc->rx_cmd_pt) +1);

 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
   
  #ifdef PR_FL	
   printfpd("\n\rSoft Reset : %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+1));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+2));
   printfpd(" %X ", *( (unsigned char *) (pDesc->rx_cmd_pt)+3));

   printfpd("reset : %X ", * (unsigned char *)  pDesc->rx_cmd_pt);
   // printfpd("tmp : %X ", tmp);

  
//  #endif
  

  //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);
   
   
   
   
   
 #endif  
   
   
   
 //	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_data_pt) +1);
 
 //  printfp("\n\rAT91F_DataFlashGetStatusx: pDesc->DataFlash_state =  ");
 //  printfpd(" %X ", pDesc->DataFlash_state);
 //   printfp("  pDesc->state : ");
 //  printfpd(" %X ",pDesc->state);
   //     } /* Endbody */
  //   OperateBuffers_usart0t();
	return status;
}


#endif


#if 0
/*----------------------------------------------------------------------*/
/* fn    AT91F_DataFlashExtID											*/
/* brief Read the extended ID											*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashExtID(AT91PS_DataflashDesc pDesc)
{
	AT91S_DataFlashStatus status;

	/* if a transfert is in progress ==> return 0 */
	if( (pDesc->state) != IDLE)
		return AT91C_DATAFLASH_BUSY;

	/* first send the read status command (D7H) */
	pDesc->command[0] = 0x9F;
	pDesc->command[1] = 0;

	pDesc->DataFlash_state  = GET_STATUS;
    	pDesc->tx_data_size 	= 0 ;	/* Transmit the command and receive response */
    	pDesc->tx_cmd_pt 	= pDesc->command ;
    	pDesc->rx_cmd_pt 	= pDesc->command ;
    	pDesc->rx_cmd_size 	= 5 ;
    	pDesc->tx_cmd_size 	= 5 ;
    	status = AT91F_SpiWrite (pDesc);

	pDesc->DataFlash_state = *( (unsigned char *) (pDesc->rx_cmd_pt) +1);

	return status;
}
#endif


/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashWaitReady					*/
/* \brief wait for dataflash ready (bit7 of the status register == 1)	*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWaitReady(AT91PS_DataflashDesc pDataFlashDesc, unsigned int timeout)
{
	pDataFlashDesc->DataFlash_state = IDLE;

	do {
   
//#ifdef TEST_HANGING      
//      if(!(timeout%999)) printfpd(" %d", timeout);
//#endif         
		AT91F_DataFlashGetStatus(pDataFlashDesc);
//#ifdef TEST_HANGING      
//      if(!(timeout%1000)) printfpd(" %d", timeout);
//#endif      
      
		timeout--;
	    }
	while( ((pDataFlashDesc->DataFlash_state & 0x80) != 0x80) && (timeout > 0) );

	if((pDataFlashDesc->DataFlash_state & 0x80) != 0x80)
		return AT91C_DATAFLASH_ERROR;
	
	return AT91C_DATAFLASH_OK;
}

#ifdef XIL_FLASH

/*----------------------------------------------------------------------*/
/* \fn    AT91F_DataFlashWaitReadyx					*/
/* \brief wait for dataflash ready (bit7 of the status register == 1)	*/
/*----------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWaitReadyx(AT91PS_DataFlash pDataFlash, unsigned int timeout)
{
	pDataFlash->pDataFlashDesc->DataFlash_state = IDLE;
#ifdef PR_FL	   
   //  printfp("\n\r  AT91F_DataFlashWaitReadyx");
#endif  

    
	do {
 //  printfp("\n\r>>");
		AT91F_DataFlashGetStatusx(pDataFlash->pDevice->cs, pDataFlash->pDataFlashDesc);
		timeout--;
   //   printfpd(" %d", timeout);   //399999
   //   OperateBuffers_usart0t();
 //       printfp("\n\r--");

      if(!timeout) break;
 //    printfp("\n\r<<");
 
	}
  //	while( ((pDataFlash->pDataFlashDesc->DataFlash_state & 0x80) != 0x80) && (timeout > 0) );
  	while ((pDataFlash->pDataFlashDesc->DataFlash_state & 0x80) != 0x80);

	if((pDataFlash->pDataFlashDesc->DataFlash_state & 0x80) != 0x80){
 //    printfp("\n\r error state");
    //  OperateBuffers_usart0t();
 
   		return AT91C_DATAFLASH_ERROR;
         }
         else{ /* Body */
   //           printfp("state ok");
      } /* Endbody */
	 //   printfp("state ok");
    //  OperateBuffers_usart0t();

	return AT91C_DATAFLASH_OK;
}

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataFlashContinuousReadx 				*/
/* Object              : Continuous stream Read 				*/
/* Input Parameters    : DataFlash Service					*/
/*						: <src> = dataflash address	*/
/*                     : <*dataBuffer> = data buffer pointer			*/
/*                     : <sizeToRead> = data buffer size			*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashContinuousReadx (
 	AT91PS_DataFlash pDataFlash,
	int src,
	unsigned char *dataBuffer,
	int sizeToRead )
{
	AT91S_DataFlashStatus status;
   
   
   
	/* Test the size to read in the device */
	if ( (src + sizeToRead) > (pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number)))
   { /* Body */
 //  printfpd("\n\r src + sizeToRead %d", src + sizeToRead);
   printfpd("\n\r pages_size * pages_number %d",(pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number))); 
   printfp("\n\r DATAFLASH_MEMORY_OVERFLOW") ;
     return AT91C_DATAFLASH_MEMORY_OVERFLOW;

   
} /* Endbody */
else
{
 //  printfpd("\n\r src + sizeToRead %d", src + sizeToRead);
 //  printfpd("\n\r pages_size * pages_number %d",(pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number))); 

  // printfp("\n\r DATAFLASH_MEMORY_ok") ;
 
}
	  

	pDataFlash->pDataFlashDesc->rx_data_pt = dataBuffer;
	pDataFlash->pDataFlashDesc->rx_data_size = sizeToRead;
	pDataFlash->pDataFlashDesc->tx_data_pt = dataBuffer;
	pDataFlash->pDataFlashDesc->tx_data_size = 0;//my sizeToRead;
	
	status = AT91F_DataFlashSendCommandx (pDataFlash, DB_CONTINUOUS_ARRAY_READ, 8, src);
	/* Send the command to the dataflash */
	return(status);
}



#endif



/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataFlashContinuousRead 				*/
/* Object              : Continuous stream Read 				*/
/* Input Parameters    : DataFlash Service					*/
/*						: <src> = dataflash address	*/
/*                     : <*dataBuffer> = data buffer pointer			*/
/*                     : <sizeToRead> = data buffer size			*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashContinuousRead (
 	AT91PS_DataFlash pDataFlash,
	int src,
	unsigned char *dataBuffer,
	int sizeToRead )
{
	AT91S_DataFlashStatus status;
	/* Test the size to read in the device */
	if ( (src + sizeToRead) > (pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number)))
		return AT91C_DATAFLASH_MEMORY_OVERFLOW;

	pDataFlash->pDataFlashDesc->rx_data_pt = dataBuffer;
	pDataFlash->pDataFlashDesc->rx_data_size = sizeToRead;
	pDataFlash->pDataFlashDesc->tx_data_pt = dataBuffer;
	pDataFlash->pDataFlashDesc->tx_data_size = sizeToRead;
	
	status = AT91F_DataFlashSendCommand (pDataFlash, DB_CONTINUOUS_ARRAY_READ, 8, src);
	/* Send the command to the dataflash */
	return(status);
}



/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_MainMemoryToBufferTransfert			*/
/* Object              : Read a page in the SRAM Buffer 1 or 2			*/
/* Input Parameters    : DataFlash Service					*/
/*                     : Page concerned						*/
/*                     : 							*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_MainMemoryToBufferTransfert(
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned int page)
{
	int cmdsize;
	/* Test if the buffer command is legal */
	if ((BufferCommand != DB_PAGE_2_BUF1_TRF) && (BufferCommand != DB_PAGE_2_BUF2_TRF))
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* no data to transmit or receive */
    	pDataFlash->pDataFlashDesc->tx_data_size = 0;
	cmdsize = 4;
  //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
		cmdsize = 5;
	return(AT91F_DataFlashSendCommand (pDataFlash, BufferCommand, cmdsize, page*pDataFlash->pDevice->pages_size));
}

#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_MainMemoryToBufferTransfertx			*/
/* Object              : Read a page in the SRAM Buffer 1 or 2			*/
/* Input Parameters    : DataFlash Service					*/
/*                     : Page concerned						*/
/*                     : 							*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_MainMemoryToBufferTransfertx(
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned int page)
{
	int cmdsize;
	/* Test if the buffer command is legal */
	if ((BufferCommand != DB_PAGE_2_BUF1_TRF) && (BufferCommand != DB_PAGE_2_BUF2_TRF))
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* no data to transmit or receive */
    	pDataFlash->pDataFlashDesc->tx_data_size = 0;
	cmdsize = 4;
 //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
		cmdsize = 5;
	return(AT91F_DataFlashSendCommand (pDataFlash, BufferCommand, cmdsize, page*pDataFlash->pDevice->pages_size));
}

#endif





/*----------------------------------------------------------------------------- */
/* Function Name       : AT91F_DataFlashWriteBuffer				*/
/* Object              : Write data to the internal sram buffer 1 or 2		*/
/* Input Parameters    : DataFlash Service					*/
/*			: <BufferCommand> = command to write buffer1 or buffer2	*/
/*                     : <*dataBuffer> = data buffer to write			*/
/*                     : <bufferAddress> = address in the internal buffer	*/
/*                     : <SizeToWrite> = data buffer size			*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWriteBuffer (
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned char *dataBuffer,
	unsigned int bufferAddress,
	int SizeToWrite )
{
	int cmdsize;
	/* Test if the buffer command is legal */
	if ((BufferCommand != DB_BUF1_WRITE) && (BufferCommand != DB_BUF2_WRITE))
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* buffer address must be lower than page size */
	if (bufferAddress > pDataFlash->pDevice->pages_size)
		return AT91C_DATAFLASH_BAD_ADDRESS;

	if ( (pDataFlash->pDataFlashDesc->state)  != IDLE)
		return AT91C_DATAFLASH_BUSY;

    	/* Send first Write Command */
    pDataFlash->pDataFlashDesc->command[0] = BufferCommand;
	pDataFlash->pDataFlashDesc->command[1] = 0;
 //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
	{
	   	pDataFlash->pDataFlashDesc->command[2] = 0;
	   	pDataFlash->pDataFlashDesc->command[3] = (unsigned char)(((unsigned int)(bufferAddress &  pDataFlash->pDevice->byte_mask)) >> 8) ;
	   	pDataFlash->pDataFlashDesc->command[4] = (unsigned char)((unsigned int)bufferAddress  & 0x00FF) ;
		cmdsize = 5;
	}
	else
	{
	   	pDataFlash->pDataFlashDesc->command[2] = (unsigned char)(((unsigned int)(bufferAddress &  pDataFlash->pDevice->byte_mask)) >> 8) ;
	   	pDataFlash->pDataFlashDesc->command[3] = (unsigned char)((unsigned int)bufferAddress  & 0x00FF) ;
	   	pDataFlash->pDataFlashDesc->command[4] = 0;
		cmdsize = 4;
	}
		
    pDataFlash->pDataFlashDesc->tx_cmd_pt 	 = pDataFlash->pDataFlashDesc->command ;
    pDataFlash->pDataFlashDesc->tx_cmd_size  = cmdsize ;
    pDataFlash->pDataFlashDesc->rx_cmd_pt 	 = pDataFlash->pDataFlashDesc->command ;
    pDataFlash->pDataFlashDesc->rx_cmd_size  = cmdsize ;

    pDataFlash->pDataFlashDesc->rx_data_pt 	 = dataBuffer ;
    pDataFlash->pDataFlashDesc->tx_data_pt 	 = dataBuffer ;
    pDataFlash->pDataFlashDesc->rx_data_size = SizeToWrite ;
    pDataFlash->pDataFlashDesc->tx_data_size = SizeToWrite ;

    return AT91F_SpiWrite(pDataFlash->pDataFlashDesc);
}

#ifdef XIL_FLASH

/*----------------------------------------------------------------------------- */
/* Function Name       : AT91F_DataFlashWriteBuffer				*/
/* Object              : Write data to the internal sram buffer 1 or 2		*/
/* Input Parameters    : DataFlash Service					*/
/*			: <BufferCommand> = command to write buffer1 or buffer2	*/
/*                     : <*dataBuffer> = data buffer to write			*/
/*                     : <bufferAddress> = address in the internal buffer	*/
/*                     : <SizeToWrite> = data buffer size			*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWriteBufferx (
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned char *dataBuffer,
	unsigned int bufferAddress,
	int SizeToWrite )
{
	int cmdsize;
//   printfp("\n\r AT91F_DataFlashWriteBufferx");
   
	/* Test if the buffer command is legal */
	if ((BufferCommand != DB_BUF1_WRITE) && (BufferCommand != DB_BUF2_WRITE))
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* buffer address must be lower than page size */
	if (bufferAddress > pDataFlash->pDevice->pages_size)
		return AT91C_DATAFLASH_BAD_ADDRESS;

	if ( (pDataFlash->pDataFlashDesc->state)  != IDLE)
		return AT91C_DATAFLASH_BUSY;
     //  printfp("\n\r Send first Write Command");

    	/* Send first Write Command */
    pDataFlash->pDataFlashDesc->command[0] = BufferCommand;
	pDataFlash->pDataFlashDesc->command[1] = 0;
 //	if (pDataFlash->pDevice->pages_number >= 16384)
     if(0)
	{
	   	pDataFlash->pDataFlashDesc->command[2] = 0;
	   	pDataFlash->pDataFlashDesc->command[3] = (unsigned char)(((unsigned int)(bufferAddress &  pDataFlash->pDevice->byte_mask)) >> 8) ;
	   	pDataFlash->pDataFlashDesc->command[4] = (unsigned char)((unsigned int)bufferAddress  & 0x00FF) ;
		cmdsize = 5;
	}
	else
	{
	   	pDataFlash->pDataFlashDesc->command[2] = (unsigned char)(((unsigned int)(bufferAddress &  pDataFlash->pDevice->byte_mask)) >> 8) ;
	   	pDataFlash->pDataFlashDesc->command[3] = (unsigned char)((unsigned int)bufferAddress  & 0x00FF) ;
	   	pDataFlash->pDataFlashDesc->command[4] = 0;
		cmdsize = 4;
	}
		
    pDataFlash->pDataFlashDesc->tx_cmd_pt 	 = pDataFlash->pDataFlashDesc->command ;
    pDataFlash->pDataFlashDesc->tx_cmd_size  = cmdsize ;
    pDataFlash->pDataFlashDesc->rx_cmd_pt 	 = pDataFlash->pDataFlashDesc->command ;
    pDataFlash->pDataFlashDesc->rx_cmd_size  = 0;//my cmdsize ;

    pDataFlash->pDataFlashDesc->rx_data_pt 	 = dataBuffer ;
    pDataFlash->pDataFlashDesc->tx_data_pt 	 = dataBuffer ;
    pDataFlash->pDataFlashDesc->rx_data_size = 0; //my SizeToWrite ;
    pDataFlash->pDataFlashDesc->tx_data_size = SizeToWrite ;

    return AT91F_SpiWritex(pDataFlash->pDevice->cs ,pDataFlash->pDataFlashDesc);
//    return AT91F_SpiWritexW(pDataFlash->pDevice->cs ,pDataFlash->pDataFlashDesc);
}





#endif



/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_PageErase                                        */             
/* Object              : Read a page in the SRAM Buffer 1 or 2			*/
/* Input Parameters    : DataFlash Service					*/
/*                     : Page concerned						*/
/*                     : 							*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_PageErase(
	AT91PS_DataFlash pDataFlash,
	unsigned int page)
{
	int cmdsize;
	/* Test if the buffer command is legal */	
	/* no data to transmit or receive */
    	pDataFlash->pDataFlashDesc->tx_data_size = 0;
	
	cmdsize = 4;
 //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
		cmdsize = 5;
	return(AT91F_DataFlashSendCommand (pDataFlash, DB_PAGE_ERASE, cmdsize, page*pDataFlash->pDevice->pages_size));
}

#ifdef XIL_FLASH
/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_PageErasex                                        */             
/* Object              : Read a page in the SRAM Buffer 1 or 2			*/
/* Input Parameters    : DataFlash Service					*/
/*                     : Page concerned						*/
/*                     : 							*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_PageErasex(
	AT91PS_DataFlash pDataFlash,
	unsigned int page)
{
	int cmdsize;
	/* Test if the buffer command is legal */	
	/* no data to transmit or receive */
    	pDataFlash->pDataFlashDesc->tx_data_size = 0;
       	pDataFlash->pDataFlashDesc->rx_data_size = 0;   //my

	
	cmdsize = 4;
  //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
		cmdsize = 5;
	return(AT91F_DataFlashSendCommandx (pDataFlash, DB_PAGE_ERASE, cmdsize, page*pDataFlash->pDevice->pages_size));
}




#endif



/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_WriteBufferToMain				*/
/* Object              : Write buffer to the main memory			*/
/* Input Parameters    : DataFlash Service					*/
/*		: <BufferCommand> = command to send to buffer1 or buffer2	*/
/*                     : <dest> = main memory address				*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_WriteBufferToMain (
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned int dest )
{
	int cmdsize;
	/* Test if the buffer command is correct */
	if ((BufferCommand != DB_BUF1_PAGE_PGM) &&
	    (BufferCommand != DB_BUF1_PAGE_ERASE_PGM) &&
	    (BufferCommand != DB_BUF2_PAGE_PGM) &&
	    (BufferCommand != DB_BUF2_PAGE_ERASE_PGM) )
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* no data to transmit or receive */
	pDataFlash->pDataFlashDesc->tx_data_size = 0;

	cmdsize = 4;
 //	if (pDataFlash->pDevice->pages_number >= 16384)
   if(0)
		cmdsize = 5;
	/* Send the command to the dataflash */
	return(AT91F_DataFlashSendCommand (pDataFlash, BufferCommand, cmdsize, dest));
}

#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_WriteBufferToMainx				*/
/* Object              : Write buffer to the main memory			*/
/* Input Parameters    : DataFlash Service					*/
/*		: <BufferCommand> = command to send to buffer1 or buffer2	*/
/*                     : <dest> = main memory address				*/
/* Return value		: State of the dataflash				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_WriteBufferToMainx (
	AT91PS_DataFlash pDataFlash,
	unsigned char BufferCommand,
	unsigned int dest )
{
	int cmdsize;
	/* Test if the buffer command is correct */
	if ((BufferCommand != DB_BUF1_PAGE_PGM) &&
	    (BufferCommand != DB_BUF1_PAGE_ERASE_PGM) &&
	    (BufferCommand != DB_BUF2_PAGE_PGM) &&
	    (BufferCommand != DB_BUF2_PAGE_ERASE_PGM) )
		return AT91C_DATAFLASH_BAD_COMMAND;

	/* no data to transmit or receive */
	pDataFlash->pDataFlashDesc->tx_data_size = 0;
    	pDataFlash->pDataFlashDesc->rx_data_size = 0;  //my


	cmdsize = 4;
  //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
		cmdsize = 5;
 //   printfp("\n\r AT91F_WriteBufferToMainx");
      
	/* Send the command to the dataflash */
	return(AT91F_DataFlashSendCommandx (pDataFlash, BufferCommand, cmdsize, dest));
}


#endif


/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_PartialPageWrite					*/
/* Object              : Erase partielly a page					*/
/* Input Parameters    : <page> = page number					*/
/*			: <AdrInpage> = adr to begin the fading			*/
/*                     : <length> = Number of bytes to erase			*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_PartialPageWrite (
	AT91PS_DataFlash pDataFlash,
	unsigned char *src,
	unsigned int dest,
	unsigned int size)
{
	unsigned int page;
	unsigned int AdrInPage;

	page = dest / (pDataFlash->pDevice->pages_size);
	AdrInPage = dest % (pDataFlash->pDevice->pages_size);

	/* Read the contents of the page in the Sram Buffer */
	AT91F_MainMemoryToBufferTransfert(pDataFlash, DB_PAGE_2_BUF1_TRF, page);
	AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	
	/*Update the SRAM buffer */
	AT91F_DataFlashWriteBuffer(pDataFlash, DB_BUF1_WRITE, src, AdrInPage, size);
	AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	
	/* Erase page if a 128 Mbits device */
  //	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
	{
		AT91F_PageErase(pDataFlash, page);
		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	}

	/* Rewrite the modified Sram Buffer in the main memory */
	return(AT91F_WriteBufferToMain(pDataFlash, DB_BUF1_PAGE_ERASE_PGM, (page*pDataFlash->pDevice->pages_size)));
}

#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_PartialPageWritex					*/
/* Object              : Erase partielly a page					*/
/* Input Parameters    : <page> = page number					*/
/*			: <AdrInpage> = adr to begin the fading			*/
/*                     : <length> = Number of bytes to erase			*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_PartialPageWritex (
	AT91PS_DataFlash pDataFlash,
	unsigned char *src,
	unsigned int dest,
	unsigned int size)
{
	unsigned int page;
	unsigned int AdrInPage;
 //     printfp("\n\r AT91F_PartialPageWritex");


	page = dest / (pDataFlash->pDevice->pages_size);
	AdrInPage = dest % (pDataFlash->pDevice->pages_size);
   
  //   printfpd(" page 0x%X", (page));    
 //         printfpd(" AdrInPage 0x%X", (AdrInPage )); 


	/* Read the contents of the page in the Sram Buffer */
	AT91F_MainMemoryToBufferTransfertx(pDataFlash, DB_PAGE_2_BUF1_TRF, page);
   
 //ok  return 0;    //test
   
	AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
  //t	   return 0;   //bad
	/*Update the SRAM buffer */
	AT91F_DataFlashWriteBufferx(pDataFlash, DB_BUF1_WRITE, src, AdrInPage, size);
   
	AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
   
 //	printfp("\n\r AT91F_PartialPageWritex");
   
	/* Erase page if a 128 Mbits device */
//	if (pDataFlash->pDevice->pages_number >= 16384)
    if(0)
	{
		AT91F_PageErasex(pDataFlash, page);
		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
	}

	/* Rewrite the modified Sram Buffer in the main memory */
	return(AT91F_WriteBufferToMainx(pDataFlash, DB_BUF1_PAGE_ERASE_PGM, (page*pDataFlash->pDevice->pages_size)));
}


#endif



/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataFlashWrite             			*/
/* Object              :							*/
/* Input Parameters    : <*src> = Source buffer					*/
/*                     : <dest> = dataflash adress				*/
/*                     : <size> = data buffer size				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWrite(
	AT91PS_DataFlash pDataFlash,
	unsigned char *src,
	int dest,
	int size )
{
	unsigned int length;
	unsigned int page;
	unsigned int status;

	AT91F_SpiEnable(pDataFlash->pDevice->cs);

    if ( (dest + size) > (pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number)))
		return AT91C_DATAFLASH_MEMORY_OVERFLOW;

    	/* If destination does not fit a page start address */
    if ((dest % ((unsigned int)(pDataFlash->pDevice->pages_size)))  != 0 ) {
		length = pDataFlash->pDevice->pages_size - (dest % ((unsigned int)(pDataFlash->pDevice->pages_size)));

		if (size < length)
			length = size;

		if(!AT91F_PartialPageWrite(pDataFlash,src, dest, length))
			return AT91C_DATAFLASH_ERROR;

		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);

		/* Update size, source and destination pointers */
        	size -= length;
        	dest += length;
        	src += length;
    }

    while (( size - pDataFlash->pDevice->pages_size ) >= 0 ) 
    {
    wd_reset();
    
  //  printfpd("\n\r %d", size);
  //  OperateBuffers_usart0t();
		/* program dataflash page */		
		page = (unsigned int)dest / (pDataFlash->pDevice->pages_size);

		status = AT91F_DataFlashWriteBuffer(pDataFlash, DB_BUF1_WRITE, src, 0, pDataFlash->pDevice->pages_size);
		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	
		status = AT91F_PageErase(pDataFlash, page);
		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
		if (!status)
			return AT91C_DATAFLASH_ERROR;
		
		status = AT91F_WriteBufferToMain (pDataFlash, DB_BUF1_PAGE_PGM, dest);
		if(!status)
			return AT91C_DATAFLASH_ERROR;

		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	
		/* Update size, source and destination pointers */
	   	size -= pDataFlash->pDevice->pages_size ;
	   	dest += pDataFlash->pDevice->pages_size ;
	   	src  += pDataFlash->pDevice->pages_size ;
    }

    /* If still some bytes to read */
    if ( size > 0 ) {
		/* program dataflash page */
		if(!AT91F_PartialPageWrite(pDataFlash, src, dest, size) )
			return AT91C_DATAFLASH_ERROR;
		AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT);
	}
    return AT91C_DATAFLASH_OK;
}


#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataFlashWritex             			*/
/* Object              :							*/
/* Input Parameters    : <*src> = Source buffer					*/
/*                     : <dest> = dataflash adress				*/
/*                     : <size> = data buffer size				*/
/*------------------------------------------------------------------------------*/
AT91S_DataFlashStatus AT91F_DataFlashWritex(
	AT91PS_DataFlash pDataFlash,
	unsigned char *src,
	int dest,
	int size )
{
	unsigned int length;
	unsigned int page;
	unsigned int status;
  //   printfp("\n\r AT91F_DataFlashWritex");
               //   OperateBuffers_usart0t();
               
#ifdef DEBUG_WRITE_XIL
     printfpd ("\n\r dataflashwritex size : %d", size);
#endif  
               
     

 //not need	AT91F_SpiEnable(pDataFlash->pDevice->cs);

    if ( (dest + size) > (pDataFlash->pDevice->pages_size * (pDataFlash->pDevice->pages_number)))
	 { /* Body */      //    printfp("\n\r err1");    
     //     printfpd("\n\r p %d", pDataFlash->pDevice->pages_size); 
       //    printfpd(" n %d", pDataFlash->pDevice->pages_number);
         //   printfpd(" dest+ size : %X", (dest + size)); 
           
           //   OperateBuffers_usart0t();
           
#ifdef DEBUG_WRITE_XIL
       printfpd("\n\r pages_size : %d", pDataFlash->pDevice->pages_size); 
        printfpd(" pages_number %d", pDataFlash->pDevice->pages_number);
         printfpd(" dest+ size : %X", (dest + size)); 


     printfp ("\n\r AT91C_DATAFLASH_MEMORY_OVERFLOW");
#endif  
           

    	return AT91C_DATAFLASH_MEMORY_OVERFLOW;   }

    	/* If destination does not fit a page start address */
    if ((dest % ((unsigned int)(pDataFlash->pDevice->pages_size)))  != 0 )
    {
		length = pDataFlash->pDevice->pages_size - (dest % ((unsigned int)(pDataFlash->pDevice->pages_size)));

		if (size < length)
			length = size;
    //   printfpd(" length : %X", (length));    
    //      printfpd(" dest : %X", (dest )); 
     //       OperateBuffers_usart0t();

//ok  return;     //t
  
		if(!AT91F_PartialPageWritex(pDataFlash,src, dest, length))
		{ /* Body */    //    printfp("\n\r err2");
                //   OperateBuffers_usart0t();
#ifdef DEBUG_WRITE_XIL
     printfp ("\n\r AT91C_DATAFLASH_ERROR");
#endif  
                

 	return AT91C_DATAFLASH_ERROR; }
   
// return 0; //temporary for test

		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);

		/* Update size, source and destination pointers */
        	size -= length;
        	dest += length;
        	src += length;
    }
 //    printfp("\n\r step1");     //not hier
      // OperateBuffers_usart0t();
//bad  return 0; //t
  
    while (( size - pDataFlash->pDevice->pages_size ) >= 0 ) 
    {
		/* program dataflash page */		
		page = (unsigned int)dest / (pDataFlash->pDevice->pages_size);

		status = AT91F_DataFlashWriteBufferx(pDataFlash, DB_BUF1_WRITE, src, 0, pDataFlash->pDevice->pages_size);
		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
	
		status = AT91F_PageErasex(pDataFlash, page);
		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
		if (!status)
			return AT91C_DATAFLASH_ERROR;
		
		status = AT91F_WriteBufferToMainx (pDataFlash, DB_BUF1_PAGE_PGM, dest);
		if(!status)
			return AT91C_DATAFLASH_ERROR;

		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
	
		/* Update size, source and destination pointers */
	   	size -= pDataFlash->pDevice->pages_size ;
	   	dest += pDataFlash->pDevice->pages_size ;
	   	src  += pDataFlash->pDevice->pages_size ;
    }
     //   printfp("\n\r step2");

    /* If still some bytes to read */
    if ( size > 0 ) {
		/* program dataflash page */
		if(!AT91F_PartialPageWritex(pDataFlash, src, dest, size) )
			return AT91C_DATAFLASH_ERROR;
		AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX);
	}
 #ifdef DEBUG_WRITE_XIL
     printfp ("\n\r AT91C_DATAFLASH_OK");
#endif  
  
 //  printfp("\n\r ok");
    return AT91C_DATAFLASH_OK;
}

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataFlashRead 					*/
/* Object              : Read a block in dataflash				*/
/* Input Parameters    : 							*/
/* Return value		: 							*/
/*------------------------------------------------------------------------------*/
int AT91F_DataFlashReadx(
	AT91PS_DataFlash pDataFlash,
	unsigned long addr,
	unsigned long size,
	char *buffer)
{
	unsigned long SizeToRead;
#ifdef PR_FL	   
   //  printfp("\n\r AT91F_DataFlashReadx");
#endif  
//   AT91F_DataflashInitx();
 //ok AT91F_DataflashProbex(pDataFlash->pDevice->cs, pDataFlash->pDataFlashDesc);   //my
   

//	AT91F_SpiEnable(pDataFlash->pDevice->cs);

 //	if(AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX) != AT91C_DATAFLASH_OK)
  //		return -1;
      
  //    printfpd(" addr : %X", (addr));
   //     printfpd(" size : %X", (size));  

	while (size)
	{
		SizeToRead = (size < 0x8000)? size:0x8000;

		if (AT91F_DataFlashWaitReadyx(pDataFlash, AT91C_DATAFLASH_TIMEOUTX) != AT91C_DATAFLASH_OK){ /* Body */
	//       printfp("\n\r DataFlashWaitReadyx wrong");
			return -1;
         }
         else{ /* Body */
   //      printfp("\n\r DataFlashWaitReadyx ok");
 
      } /* Endbody */

		if (AT91F_DataFlashContinuousReadx (pDataFlash, addr, (unsigned char *)buffer, SizeToRead) != AT91C_DATAFLASH_OK)
      { /* Body */
  //     printfp("\n\r DataFlashContinuousReadx wrong");

       	return -1;
  
	} /* Endbody */
   else{ /* Body */
   
    //    printfp("\n\r DataFlashContinuousReadx ok");

} /* Endbody */
  	
		size -= SizeToRead;
		addr += SizeToRead;
		buffer += SizeToRead;
	}

   	return AT91C_DATAFLASH_OK;
}



#endif

/*------------------------------------------------------------------------------*/
/* Function Name       :    AT91F_DataFlashRead 				                   	*/
/* Object              :    Read a block in dataflash		                      	*/
/* Input Parameters    : 						                                     	*/
/* Return value		: 							                                      */
/*------------------------------------------------------------------------------*/
int AT91F_DataFlashRead(
	AT91PS_DataFlash pDataFlash,
	unsigned long addr,
	unsigned long size,
	char *buffer)
{
	unsigned long SizeToRead;
    /*
   _DCACHE_FLUSH();  //keep data from cache in memory
   _DCACHE_INVALIDATE();  //clear cashe for are ready for new data
   _DCACHE_DISABLE();
      */
//   cashe_off();

	AT91F_SpiEnable(pDataFlash->pDevice->cs);

	if(AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT) != AT91C_DATAFLASH_OK)
   {
	    if(start_main_loop) printfp("\n\rNot Ready");	
   	return -1;
    }
    
	while (size)
	{
		SizeToRead = (size < 0x8000)? size:0x8000;

		if (AT91F_DataFlashWaitReady(pDataFlash->pDataFlashDesc, AT91C_DATAFLASH_TIMEOUT) != AT91C_DATAFLASH_OK)
			return -1;

		if (AT91F_DataFlashContinuousRead (pDataFlash, addr, (unsigned char *)buffer, SizeToRead) != AT91C_DATAFLASH_OK)
  	return -1;

		size -= SizeToRead;
		addr += SizeToRead;
		buffer += SizeToRead;
	}
   
 //  _DCACHE_ENABLE();
 //    cashe_on();

   	return AT91C_DATAFLASH_OK;
}

extern unsigned char start_main_loop;

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataflashProbe 					*/
/* Object              : 							*/
/* Input Parameters    : 							*/
/* Return value	       : Dataflash status register				*/
/*------------------------------------------------------------------------------*/
int AT91F_DataflashProbe(int cs, AT91PS_DataflashDesc pDesc)
{
//if(start_main_loop)
//printfpd("\n\r AT91F_DataflashProbe %d", cs);

	AT91F_SpiEnable(cs);
  //    for(;;) //to test
  // 	AT91F_DataFlashGetStatus(pDesc);
    //  AT91F_DataFlashGetManuf(pDesc);
     //if (pDesc->command[3] & 0x01) have 641e!!!!
     
//     #define AT45DB642		0x3c
//#define AT45DB128		0x10
//#define AT45DB641E		0x08 //my
 //     if(((pDesc->command[1] & 0x3C) == AT45DB642) && (pDesc->command[3] == 0x1))
 //     { /* Body */
 //     return   (int)AT45DB641E;
 //  } /* Endbody */
 
 //if(start_main_loop)
 //if(1)
// { 
   AT91F_DataFlashGetManuf(pDesc);
   
  if(start_main_loop)
  { 
   printfpd("\n\r 0:%x ", pDesc->command[0]);   //ff
   printfpd(" 1: %x", pDesc->command[1]);      //1f
   printfpd(" 2: %x", pDesc->command[2]);      //28
   printfpd(" 3: %x", pDesc->command[3]);      //0
   printfpd(" 4: %x\n\r", pDesc->command[4]);   //1 -adesto   0 - 642
 }
 
//  else
 // { /* Body */
     
  //   AT91F_DataFlashGetStatus(pDesc);

     
     
 //  } /* Endbody */

 
 
//#ifndef ADESTO      
   //	return ((pDesc->command[1] == 0xFF)? 0: (pDesc->command[1] & 0x3C));
//#else      
  //     	return ((pDesc->command[1] == 0xFF)? 0 : (int)AT45DB641E);	
//#endif    
  if(pDesc->command[2] == 0x27) return  pDesc->command[2]; //adeste at45db321e

 return ((pDesc->command[2] == 0xFF)? 0: (pDesc->command[2] + pDesc->command[4])); //0x28 - atmel or 0x29 - adesto
     
}

#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataflashProbe 					*/
/* Object              : 							*/
/* Input Parameters    : 							*/
/* Return value	       : Dataflash status register				*/
/*------------------------------------------------------------------------------*/
int AT91F_DataflashProbex(int cs, AT91PS_DataflashDesc pDesc)
{
  //	AT91F_SpiEnable(cs);      //hier was test cs for my need in getstatus set needed addr
  //    for(;;) //to test
  //  delay_mcs(100000l);
  
    if(start_main_loop)
  { 

#ifdef PR_FL  
  printfpd ("\n\rAT91F_DataflashProbex cs : 0x%02X \n\r", cs);
#endif 
    }
 
//_____________________________________________
//unsigned timeout = (unsigned)1;

pDesc->DataFlash_state = IDLE;

//AT91F_DataFlashReset(cs, pDesc);
//AT91F_DataFlashReset(cs, pDesc);
//AT91F_DataFlashReset(cs, pDesc);
//AT91F_DataFlashReset(cs, pDesc);
//AT91F_DataFlashReset(cs, pDesc);


// delay_mcs(100000l);
//AT91F_DataFlashGetStatusx(cs, pDesc);
//AT91F_DataFlashGetStatusx(cs, pDesc);
//AT91F_DataFlashGetStatusx(cs, pDesc);
//AT91F_DataFlashGetStatusx(cs, pDesc);
//AT91F_DataFlashGetStatusx(cs, pDesc);

 //AT91F_DataFlashGetManufx(cs, pDesc);
// AT91F_DataFlashGetStatusx(cs, pDesc);


// 	do {
 //  printfp("\n\r>>");
	 //	AT91F_DataFlashGetStatusx(cs, pDesc);
      AT91F_DataFlashGetManufx(cs, pDesc);
    //   AT91F_DataFlashGetManufx(cs, pDesc);
     //   AT91F_DataFlashGetManufx(cs, pDesc);


  //		timeout--;
      
//#ifdef PR_FL	      
  //    printfpd(" %X", pDesc->DataFlash_state);
//#endif      
      
   //   OperateBuffers_usart0t();
 //       printfp("\n\r--");

    //  if(!timeout){ /* Body */
      
  //    printfp("\n\rTimeout break\n\r");
    //  break;
  // } /* Endbody */
      
  //   break;
 //    printfp("\n\r<<");
 
 //	}
  //	while( ((pDataFlash->pDataFlashDesc->DataFlash_state & 0x80) != 0x80) && (timeout > 0) );
  //	while ((pDesc->command[0]  & 0x1f) != 0x1f);
  
  if(start_main_loop)
  { 
   printfpd("\n\r 0:%x ", pDesc->command[0]);   //ff
   printfpd(" 1: %x", pDesc->command[1]);      //1f
   printfpd(" 2: %x", pDesc->command[2]);      //28
   printfpd(" 3: %x", pDesc->command[3]);      //0
   printfpd(" 4: %x\n\r", pDesc->command[4]);   //1 -adesto   0 - 642
 }
 

  
     if(start_main_loop)
{ 
   
 #ifdef PR_FL	      
      printfpd("pDesc->DataFlash_state: %X", pDesc->DataFlash_state);
#endif   
}     

 //	if((pDesc->DataFlash_state & 0x80) != 0x80){
  // printfp("error DataFlash_state");
  //  OperateBuffers_usart0t();
 
    //		return 0;
    //     }
 
 
 
 
 
 
 //____________________________________________
 
 
 

//141126   	AT91F_DataFlashGetStatusx(cs, pDesc);
 //     printfpd("\n\r....AT91F_DataflashProbex : %d", cs);
 
   //   printfpd("\n\rc0: %02X", pDesc->command[0]);
    //    printfpd(" c1: %02X \n\r", pDesc->command[1]);

 
     //	return ((pDesc->command[0] == 0xFF)? 0: (pDesc->command[0] & 0x3C));
     
     
#ifndef PROG_ODU1000     
 //keep old    	return ((pDesc->command[1] == 0xFF)? 0: (pDesc->command[1] & 0x3C)); //size
      
        if(pDesc->command[2] == 0x27) return  pDesc->command[2]; //adeste at45db321e

 return ((pDesc->command[2] == 0xFF)? 0: (pDesc->command[2] + pDesc->command[4])); //0x28 - atmel or 0x29 - adesto

#else      
       return ((pDesc->command[2] == 0xFF)? 0: (pDesc->command[2] + pDesc->command[4])); //0x28 - atmel or 0x29 - adesto

#endif      
      
      
}


#endif
