//file : work.c
#include <mqx.h>
#include <bsp.h>
#include <log.h>
#include <klog.h>
#include <rtcs.h>
#include <enet.h>
#include "hello7.h"
#include "io_prv.h"

#include "psp_prv.h"
#include "spi_pol.h"
#include "spi_polpv.h"
#include <dataflash.h>
#include <string.h>
#include <stdlib.h>
#include <hello7.h>



#define int16                 uint_32

//#define PROG_PU_M_MUX //101115 for test

//#define NVRAM_BASE      			(pointer)(0x10000000) /* cs0 */
//#define NVRAM_SIZE      			(0x00008000) /*  32KB x 8  */
//#define SDRAM_BASE      			(pointer)(0x20000000) /* cs1 */
//#define SDRAM_SIZE      			(0x02000000) /* 32Mb x32 */
//#define XILINX_BASE      			(pointer)(0x30000000) /* cs2 */
//#define XILINX_SIZE      			(0x02000000) /* 32Mb x 8 */
//#define PERIPH_SIZE      			(0x00000FFF) /* */
//#define INTERNAL_SIZE      		(0x003FFFFF) /* */





//#include "charq.h"
//#include "serinprv.h"
//#include "mqx_inc.h"
//#include "bsp_prv.h"

extern void  pTBuff0_init(void);
extern void  pRBuff0_init(void);
//char HostMAC[6];

pointer fn_ptr;
pointer fs_ptr;
pointer fx_ptr;
pointer fk_ptr;

//usart0 buffers and variables
char IdCommand0;
uint_32 CommandSize0;
uint_32 BufferSize0;
char step0;
char RBuff0[ACT_BUFFER_SIZE1];
char *  pRBuff0;
char TBuff0[ACT_BUFFER_SIZE1];
char *  pTBuff0;
long pTBuff0_cnt;
long pRBuff0_cnt;

long pTBuff3_cnt;
long pRBuff3_cnt;

long pTBuff3B_cnt;
long pRBuff3B_cnt;



char TBuff0mf[SIZETX0MF];
char *  pTBuff0mf;
unsigned long TBuff0mf_cnt;
//usart1 buffers and variables
char IdCommand;
uint_32 CommandSize;
uint_32 BufferSize;
char step;
char RBuff[ACT_BUFFER_SIZE1];
char *  pRBuff;
char TBuff[ACT_BUFFER_SIZE1];
char *  pTBuff;
//usart3 buffers and variables
char IdCommand3;
uint_32 CommandSize3;
uint_32 BufferSize3;
char step3;
char RBuff3[ACT_BUFFER_SIZE1];
char *  pRBuff3;
char TBuff3[ACT_BUFFER_SIZE1];
//char TBuff3[TBUFF2_VALUE];
char *  pTBuff3;

//char TBuff3B[TBUFF2_VALUE];
//char *  pTBuff3B;


//usart2 buffers and variables
char IdCommand2;
uint_32 CommandSize2;
uint_32 BufferSize2;
char step2;
char RBuff2[ACT_BUFFER_SIZE1];
char *  pRBuff2;
char TBuff2[ACT_BUFFER_SIZE1];
char *  pTBuff2;




//snmp buffers and variables
char IdCommandS;
uint_32 CommandSizeS;
uint_32 BufferSizeS;
//t char TBuffS[128];
char TBuffS[ACT_BUFFER_SIZE1];
char *  pTBuffS;
extern char* pnvram;
extern char* pxilinx;
extern char* pxilinx3;



//char Test;
extern void m_uart_monitor(void);
extern void Ring(unsigned char , unsigned char , unsigned char , unsigned char );	 
//extern void embRS232_rcvbuf_Add(unsigned char);
extern AT91RM9200_SERIAL_INIT_STRUCT  _bsp_atevbrm9200_uart_init;
extern AT91RM9200_SERIAL_INIT_STRUCT  _bsp_atevbrm9200_uart1_init;
extern AT91RM9200_SERIAL_INIT_STRUCT  _bsp_atevbrm9200_uart0_init;
extern AT91RM9200_SERIAL_INIT_STRUCT  _bsp_atevbrm9200_uart3_init;
extern AT91RM9200_SERIAL_INIT_STRUCT  _bsp_atevbrm9200_uart2_init;


extern void _at91rm9200_usart1_int_isr (pointer);
extern void dev_restart(void);
extern uint_32 Stephany8;
extern uint_32 Stephany9;
extern uint_32 Stephany10;
extern uint_32 Stephany11;
extern uint_32 Stephany12;
extern uint_32 Stephany13;
extern pointer fh_ptr;
extern pointer fusart1_ptr;
extern pointer fusart0_ptr;
extern pointer fusart3_ptr;
extern pointer fusart2_ptr;

extern void jump(uint_32);
extern unsigned int UseClass();
extern void RunCommand(char *);
extern void RunCommand0(char *);
extern void RunCommand3(char *);
extern void RunCommandS(char *);
extern uint_32 SetIp(char_ptr);
void usart_command_eth_off(void);
//extern _mqx_uint _mqx(MQX_INITIALIZATION_STRUCT_PTR);
//extern  MQX_INITIALIZATION_STRUCT _PTR_ MQX_init_struct;

uint_32 spi_init_data;
extern unsigned int  testclass;
extern void emb_use_irq1(void);
extern void emb_use_irq0(void);
//#define XilDataAddressD        (0xC07C0000)
//to add name #define XilDataAddressD        (0xC07C9B20)    //is load to 0xc07c9b00, but first 32 bytes are "dummy" - writer change data in  vector 6
//#define XilDataAddressD        (0xC07C9B60)    //is load to 0xc07c9b00, but first 96 bytes are "dummy" - writer change data in  vector 6

//#define TestDataAddressD       (0xC07A7620)    //is load to 0xc07A7600, but first 32 bytes are "dummy" - writer change data in vector 6

//#define XilDataAddressD       (0xC07C9B24)    //t
//#define XilSizeToDownloadD    (0x18000)
//t #define XilSizeToDownloadD    (0x11170)   //70k now
//#define XilSizeToDownloadD    (0x11558)   //71k now

//#define XilSizeToDownloadD    (0xc)   //for test

//#define XilSizeToDownloadD    (0x60)
//#define XilAddressToDownloadD (0x21000000)    //to 16 M - is bad!
//#define XilAddressToDownloadD  (0x20f00000)    //in low 16M
#define DelayConst (62500)
#define DelaySSC (50)

//extern void    _at91rm9200_dbug_uart_serial_int_putc(IO_SERIAL_INT_DEVICE_STRUCT_PTR, char);
// Constant declarations used by I2S mode
#define AT91C_I2S_NB_SLOT_BY_FRAME	2
#define AT91C_I2S_NB_BITS_BY_SLOT	16
#define AT91C_WAV_FILE_SAMPLING_FREQ	44100 // in Hz


#define AT91PS_SSC			AT91RM9200_SSC_REG_STRUCT_PTR	

#define SSC_CMR            CMR
#define SSC_IDR            IDR
#define SSC_CR             CR
#define SSC_SR             SR
#define SSC_RCMR           RCMR
#define SSC_TCMR           TCMR
#define SSC_TFMR           TFMR
#define SSC_RFMR           RFMR
#define SSC_RPR            PDC.RPR   
#define SSC_IMR            IMR   
#define SSC_IER            IER  
//#define AT91C_SSC_SWRST    AT91RM9200_SSC_CR_SWRST
//#define AT91C_SSC_RXDIS    (0x2)
//#define AT91C_SSC_TXDIS    (0x2000)
#define AT91PS_PDC         AT91RM9200_PDC_REG_STRUCT_PTR

#define PDC_RNPR           RNPR
#define PDC_RNCR           RNCR
#define PDC_TNPR           TNPR
#define PDC_TNCR           TNCR
#define PDC_RPR            RPR
#define PDC_RCR            RCR
#define PDC_TPR            TPR
#define PDC_TCR            TCR
#define PDC_PTCR           PTCR
#define PDC_PTSR           PTSR

// #define XIL_LOAD_FREQ      100000
//#define XIL_LOAD_FREQ          10000


//#define AT91C_PDC_TXTEN    AT91RM9200_PDC_PTCR_TXT_ENABLE
//#define AT91C_PDC_RXTEN    AT91RM9200_PDC_PTCR_RXT_ENABLE
//#define AT91C_PDC_TXTDIS   AT91RM9200_PDC_PTCR_TXT_DISABLE
//#define AT91C_PDC_RXTDIS   AT91RM9200_PDC_PTCR_RXT_DISABLE
//* Define the standard I2S mode configuration

//* Configuration to set in the SSC Transmit Clock Mode Register
//* Parameters :  nb_bit_by_slot : 8, 16 or 32 bits
//* 			  nb_slot_by_frame : number of channels
// -------- SSC_CR : (SSC Offset: 0x0) SSC Control Register -------- 
#define AT91C_SSC_RXEN        ((unsigned int) 0x1 <<  0) // (SSC) Receive Enable
#define AT91C_SSC_RXDIS       ((unsigned int) 0x1 <<  1) // (SSC) Receive Disable
#define AT91C_SSC_TXEN        ((unsigned int) 0x1 <<  8) // (SSC) Transmit Enable
#define AT91C_SSC_TXDIS       ((unsigned int) 0x1 <<  9) // (SSC) Transmit Disable
#define AT91C_SSC_SWRST       ((unsigned int) 0x1 << 15) // (SSC) Software Reset
// -------- SSC_RCMR : (SSC Offset: 0x10) SSC Receive Clock Mode Register -------- 
#define AT91C_SSC_CKS         ((unsigned int) 0x3 <<  0) // (SSC) Receive/Transmit Clock Selection
#define 	AT91C_SSC_CKS_DIV                  ((unsigned int) 0x0) // (SSC) Divided Clock
#define 	AT91C_SSC_CKS_TK                   ((unsigned int) 0x1) // (SSC) TK Clock signal
#define 	AT91C_SSC_CKS_RK                   ((unsigned int) 0x2) // (SSC) RK pin
#define AT91C_SSC_CKO         ((unsigned int) 0x7 <<  2) // (SSC) Receive/Transmit Clock Output Mode Selection
#define 	AT91C_SSC_CKO_NONE                 ((unsigned int) 0x0 <<  2) // (SSC) Receive/Transmit Clock Output Mode: None RK pin: Input-only
#define 	AT91C_SSC_CKO_CONTINOUS            ((unsigned int) 0x1 <<  2) // (SSC) Continuous Receive/Transmit Clock RK pin: Output
#define 	AT91C_SSC_CKO_DATA_TX              ((unsigned int) 0x2 <<  2) // (SSC) Receive/Transmit Clock only during data transfers RK pin: Output
#define AT91C_SSC_CKI         ((unsigned int) 0x1 <<  5) // (SSC) Receive/Transmit Clock Inversion
#define AT91C_SSC_CKG         ((unsigned int) 0x3 <<  6) // (SSC) Receive/Transmit Clock Gating Selection
#define 	AT91C_SSC_CKG_NONE                 ((unsigned int) 0x0 <<  6) // (SSC) Receive/Transmit Clock Gating: None, continuous clock
#define 	AT91C_SSC_CKG_LOW                  ((unsigned int) 0x1 <<  6) // (SSC) Receive/Transmit Clock enabled only if RF Low
#define 	AT91C_SSC_CKG_HIGH                 ((unsigned int) 0x2 <<  6) // (SSC) Receive/Transmit Clock enabled only if RF High
#define AT91C_SSC_START       ((unsigned int) 0xF <<  8) // (SSC) Receive/Transmit Start Selection
#define 	AT91C_SSC_START_CONTINOUS            ((unsigned int) 0x0 <<  8) // (SSC) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data.
#define 	AT91C_SSC_START_TX                   ((unsigned int) 0x1 <<  8) // (SSC) Transmit/Receive start
#define 	AT91C_SSC_START_LOW_RF               ((unsigned int) 0x2 <<  8) // (SSC) Detection of a low level on RF input
#define 	AT91C_SSC_START_HIGH_RF              ((unsigned int) 0x3 <<  8) // (SSC) Detection of a high level on RF input
#define 	AT91C_SSC_START_FALL_RF              ((unsigned int) 0x4 <<  8) // (SSC) Detection of a falling edge on RF input
#define 	AT91C_SSC_START_RISE_RF              ((unsigned int) 0x5 <<  8) // (SSC) Detection of a rising edge on RF input
#define 	AT91C_SSC_START_LEVEL_RF             ((unsigned int) 0x6 <<  8) // (SSC) Detection of any level change on RF input
#define 	AT91C_SSC_START_EDGE_RF              ((unsigned int) 0x7 <<  8) // (SSC) Detection of any edge on RF input
#define 	AT91C_SSC_START_0                    ((unsigned int) 0x8 <<  8) // (SSC) Compare 0
#define AT91C_SSC_STOP        ((unsigned int) 0x1 << 12) // (SSC) Receive Stop Selection
#define AT91C_SSC_STTDLY      ((unsigned int) 0xFF << 16) // (SSC) Receive/Transmit Start Delay
#define AT91C_SSC_PERIOD      ((unsigned int) 0xFF << 24) // (SSC) Receive/Transmit Period Divider Selection
// -------- SSC_RFMR : (SSC Offset: 0x14) SSC Receive Frame Mode Register -------- 
#define AT91C_SSC_DATLEN      ((unsigned int) 0x1F <<  0) // (SSC) Data Length
#define AT91C_SSC_LOOP        ((unsigned int) 0x1 <<  5) // (SSC) Loop Mode
#define AT91C_SSC_MSBF        ((unsigned int) 0x1 <<  7) // (SSC) Most Significant Bit First
#define AT91C_SSC_DATNB       ((unsigned int) 0xF <<  8) // (SSC) Data Number per Frame
#define AT91C_SSC_FSLEN       ((unsigned int) 0xF << 16) // (SSC) Receive/Transmit Frame Sync length
#define AT91C_SSC_FSLEN_ZERO       ((unsigned int) 0 << 16) // (SSC) Receive/Transmit Frame Sync length
#define AT91C_SSC_FSOS        ((unsigned int) 0x7 << 20) // (SSC) Receive/Transmit Frame Sync Output Selection
#define 	AT91C_SSC_FSOS_NONE                 ((unsigned int) 0x0 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: None RK pin Input-only
#define 	AT91C_SSC_FSOS_NEGATIVE             ((unsigned int) 0x1 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Negative Pulse
#define 	AT91C_SSC_FSOS_POSITIVE             ((unsigned int) 0x2 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Positive Pulse
#define 	AT91C_SSC_FSOS_LOW                  ((unsigned int) 0x3 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver Low during data transfer
#define 	AT91C_SSC_FSOS_HIGH                 ((unsigned int) 0x4 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver High during data transfer
#define 	AT91C_SSC_FSOS_TOGGLE               ((unsigned int) 0x5 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Toggling at each start of data transfer
#define AT91C_SSC_FSEDGE      ((unsigned int) 0x1 << 24) // (SSC) Frame Sync Edge Detection
// -------- SSC_TCMR : (SSC Offset: 0x18) SSC Transmit Clock Mode Register -------- 
// -------- SSC_TFMR : (SSC Offset: 0x1c) SSC Transmit Frame Mode Register -------- 
#define AT91C_SSC_DATDEF      ((unsigned int) 0x1 <<  5) // (SSC) Data Default Value
#define AT91C_SSC_FSDEN       ((unsigned int) 0x1 << 23) // (SSC) Frame Sync Data Enable
// -------- SSC_SR : (SSC Offset: 0x40) SSC Status Register -------- 
#define AT91C_SSC_TXRDY       ((unsigned int) 0x1 <<  0) // (SSC) Transmit Ready
#define AT91C_SSC_TXEMPTY     ((unsigned int) 0x1 <<  1) // (SSC) Transmit Empty
#define AT91C_SSC_ENDTX       ((unsigned int) 0x1 <<  2) // (SSC) End Of Transmission
#define AT91C_SSC_TXBUFE      ((unsigned int) 0x1 <<  3) // (SSC) Transmit Buffer Empty
#define AT91C_SSC_RXRDY       ((unsigned int) 0x1 <<  4) // (SSC) Receive Ready
#define AT91C_SSC_OVRUN       ((unsigned int) 0x1 <<  5) // (SSC) Receive Overrun
#define AT91C_SSC_ENDRX       ((unsigned int) 0x1 <<  6) // (SSC) End of Reception
#define AT91C_SSC_RXBUFF      ((unsigned int) 0x1 <<  7) // (SSC) Receive Buffer Full
#define AT91C_SSC_CP0         ((unsigned int) 0x1 <<  8) // (SSC) Compare 0
#define AT91C_SSC_CP1         ((unsigned int) 0x1 <<  9) // (SSC) Compare 1
#define AT91C_SSC_TXSYN       ((unsigned int) 0x1 << 10) // (SSC) Transmit Sync
#define AT91C_SSC_RXSYN       ((unsigned int) 0x1 << 11) // (SSC) Receive Sync
#define AT91C_SSC_TXENA       ((unsigned int) 0x1 << 16) // (SSC) Transmit Enable
#define AT91C_SSC_RXENA       ((unsigned int) 0x1 << 17) // (SSC) Receive Enable
// -------- SSC_IER : (SSC Offset: 0x44) SSC Interrupt Enable Register -------- 
// -------- SSC_IDR : (SSC Offset: 0x48) SSC Interrupt Disable Register -------- 
// -------- SSC_IMR : (SSC Offset: 0x4c) SSC Interrupt Mask Register -------- 




#define 	AT91C_SSC_STTOUT      ((unsigned int) 0x1 << 15) // (SSC) Receive/Transmit Start Output Selection
#define 	AT91C_SSC_CKG_NONE    ((unsigned int) 0x0 <<  6) // (SSC) Receive/Transmit Clock Gating: None, continuous clock
//#define TFTP_BUFFER_SIZE (500000)
#pragma BSS(".buff_sect")
extern uchar TFTP_Buffer[TFTP_BUFFER_SIZE];
#pragma BSS()

//    ((1<<16) & AT91C_SSC_STTDLY) +\
//        AT91C_SSC_START_FALL_RF +\
//	   AT91C_SSC_CKO_CONTINOUS      +\
extern  boolean RDN_transmit( IP_IF_PTR , char * , char * );
extern _rtcs_if_handle  ihandle0;

//t void RDN_Start_Transmit() // ( RTCSPCB_PTR    pcb_ptr   )
void RDN_Start_Transmit( char * pBuffT, char * pDest)
{
   //t RDN_transmit(ihandle0,  pRDN_BufferT, pntdst);
  //  RDN_transmit(ihandle0,  RDN_BufferT, enetdest);
  
//  printfp(pBuffT);
#ifdef PROG_ACT155N  
#ifndef USART1_TRY_PDC
    eth_command_usart1_off();
#endif    
//    send485_enabled = 0; //t
#endif //PROG_ACT155N   
//100811 _int_disable(); 
    RDN_transmit(ihandle0,  pBuffT, pDest);
//100811 _int_enable();    
}

#ifdef TRAP_ENABLED
//extern  boolean TRAP1_transmit( IP_IF_PTR  );

//t void RDN_Start_Transmit() // ( RTCSPCB_PTR    pcb_ptr   )

void TRAP_Start_Transmit( char * pBuffT, char * pDest, long len)
{
   //t RDN_transmit(ihandle0,  pRDN_BufferT, pntdst);
  //  RDN_transmit(ihandle0,  RDN_BufferT, enetdest);
#ifdef PROG_ACT155N  
#ifndef USART1_TRY_PDC
    eth_command_usart1_off();
#endif    
#endif //PROG_ACT155N    
    TRAP_transmit(ihandle0,  pBuffT, pDest, len);
}

#endif // TRAP_ENABLED


 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_nvram_char
* Returned Value   : none
* Comments         :
*    This routine is used to write char to nvram
*
*END*----------------------------------------------------------------------*/

void write_nvram_char(uint_32 Addr, char ctmp)
 {
//       if(Addr >= NVRAM_SIZE)
 //  {
 //      Ring(1,1,5,4);
 //      return ;
 //  }
  //  _io_fseek (fn_ptr , Addr ,IO_SEEK_SET );
 //   fputc(ctmp, fn_ptr);
  char* port;
  port = pnvram + Addr;
  *port = ctmp;

 }
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_buffer_char
* Returned Value   : none
* Comments         :
*    This routine is used to write char to buffer
*
*END*----------------------------------------------------------------------*/

unsigned long  write_buffer_char( char ctmp, char reset)
//void write_buffer_char( char ctmp, char reset)
 {
  static unsigned long data;
  static unsigned char counter;
  static unsigned long * Addr;
 // static unsigned char * Addr;
 // unsigned long tmp;
  if(reset == START_WRITE_BUFFER)
  {
    data = 0;
  //  tmp =  (unsigned long)&TFTP_Buffer[0];
 //   Addr = (unsigned char *)&TFTP_Buffer[0];
    Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;
    counter = 0;
  }
  else
  {
   /*
   data <<= 8;
   data += ctmp;
   */
   data += ctmp << (counter * 8);   //t
   counter++;
   if(counter > 3)
   { 
    counter = 0;
    *Addr++ = data;

    data = 0l;
    if((unsigned long)Addr > ((unsigned long)&TFTP_Buffer[0] + TFTP_BUFFER_SIZE))
    { 
    //  Addr =  (char *)&TFTP_Buffer[0];
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;

    }   //size
   }   // counter
  }   //reset
  return (unsigned long)Addr;
}

void KeepInNVRAM(unsigned long parameter)
{

unsigned char * bt;
bt = (unsigned char *)(NVRAM_BASE); 
   
   
}


 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_buffer_char1
* Returned Value   : none
* Comments         :
*    This routine is used to write char to buffer
*
*END*----------------------------------------------------------------------*/

unsigned long  write_buffer_char1( char ctmp, unsigned long shift)
//void write_buffer_char( char ctmp, char reset)
 {
 // static unsigned long data_buffer;       //need init data!!!!!!!!
//  static unsigned char counter_buffer;   //need init counter!!!!!!
  
 // printfpd(" %X", shift);
  
  
  static unsigned long * Addr;
  
  is_servicepack = 1;
  
//  static long control = 0; //t
 // static unsigned char * Addr;
 // unsigned long tmp;
    /*
   data <<= 8;
   data += ctmp;
   */
  data_buffer += ctmp << (counter_buffer * 8);   //t
//  data <<= 8;
//  data += ctmp;
   counter_buffer++;
   if(counter_buffer > 3)
   { 
 //   Addr = (unsigned long *)(TFTP_BUFFER_ADDRESS + shift - 3);
 if(shift > 0x4FFFFFFFl)  //now so
    { 
       return  (unsigned long)TFTP_BUFFER_ADDRESS;;
    }

    Addr = (unsigned long *)(shift - 3);
    
         
//    if(control < Addr)  control = Addr; else write_nvram_char(0,55); 
  //  printEthLongHex(TFTP_BUFFER_ADDRESS + shift - 3);
    counter_buffer = 0;
    *Addr++ = data_buffer;

    data_buffer = 0l;
    
    if((unsigned long)Addr > ((unsigned long)TFTP_BUFFER_ADDRESS + TFTP_BUFFER_SIZE))
    { 
    //  Addr =  (char *)TFTP_BUFFER_ADDRESS;
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;

    }   //size
   }   // counter
   return (unsigned long)Addr;
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_buffer_char2
* Returned Value   : none
* Comments         :
*    This routine is used to write char to buffer
*
*END*----------------------------------------------------------------------*/

unsigned long  write_buffer_char2( char ctmp, unsigned long shift)
//unsigned long  write_buffer_char2(unsigned char ctmp, unsigned long shift)
//void write_buffer_char( char ctmp, char reset)
 {
 // static unsigned long data_buffer;       //need init data!!!!!!!!
//  static unsigned char counter_buffer;   //need init counter!!!!!!
  
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfpd("\n\r> %lX",ctmp);
//         printfpd("\n\r< %lX",shift);

//#endif
  
  
  
  static unsigned long * Addr;
  
  is_servicepack = 1;
  
//  static long control = 0; //t
 // static unsigned char * Addr;
 // unsigned long tmp;
    /*
   data <<= 8;
   data += ctmp;
   */
  data_buffer += ctmp << (counter_buffer * 8);   //t
//  data <<= 8;
//  data += ctmp;
   counter_buffer++;
   if(counter_buffer > 3)
   { 
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfp("\n\r m3 ");
//         printfpd("\n\r< %lX",shift);

//#endif
   
   
 //   Addr = (unsigned long *)(TFTP_BUFFER_ADDRESS + shift - 3);
 if(shift > 0x4FFFFFFFl)  //now so
    { 
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfp("\n\rshift");
//#endif
  
    
    
       return  (unsigned long)TFTP_BUFFER_ADDRESS;;
    }
    
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfp("\n\r a3 ");
//         printfpd("\n\r< %lX",shift);

//#endif
    

    Addr = (unsigned long *)(shift - 3);
    
         
//    if(control < Addr)  control = Addr; else write_nvram_char(0,55); 
  //  printEthLongHex(TFTP_BUFFER_ADDRESS + shift - 3);
    counter_buffer = 0;

//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfpd(" %lX",(unsigned long)Addr);
//#endif

  if((unsigned long)Addr > ((unsigned long)TFTP_BUFFER_ADDRESS + TFTP_BUFFER_SIZE))
    { 
    //  Addr =  (char *)TFTP_BUFFER_ADDRESS;
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;

    }   //size
    
  if((unsigned long)Addr < (unsigned long)TFTP_BUFFER_ADDRESS)
    { 
    //  Addr =  (char *)TFTP_BUFFER_ADDRESS;
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;
    }   //size
    
 if((unsigned long)Addr % 4)
    { 
    //  Addr =  (char *)TFTP_BUFFER_ADDRESS;
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;
    }   //size

    
    *Addr++ = data_buffer;

    data_buffer = 0l;
    /*
    if((unsigned long)Addr > ((unsigned long)TFTP_BUFFER_ADDRESS + TFTP_BUFFER_SIZE))
    { 
    //  Addr =  (char *)TFTP_BUFFER_ADDRESS;
      Addr = (unsigned long *)TFTP_BUFFER_ADDRESS;

    }   //size
   */ 
    
    
    
   }   // counter
   
//#ifdef TEST_USART2_REMOTE
//	   	printfp("\n\r... ans");
// 	   printfp("\n\r m4 ");
//         printfpd("\n\r< %lX",shift);

//#endif
   
   return (unsigned long)Addr;
}


 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :read_nvram_char
* Returned Value   : none
* Comments         :
*    This routine is used to read char from nvram
*
*END*----------------------------------------------------------------------*/

char read_nvram_char(uint_32 Addr)
 {
 //  if(Addr >= NVRAM_SIZE)
 //  {
 //      Ring(1,1,5,4);
 //      return (0);
 //  }
  //  _io_fseek (fn_ptr , Addr ,IO_SEEK_SET );
  //  return fgetc(fn_ptr);
  char* port;
  port = pnvram + Addr;
  //   return read_xil_char((uint_32)(a1));
	return *port;
 }


//*----------------------------------------------------------------------------
//* \fn    m_get_clk
//* \get clocks to xilinx
//*----------------------------------------------------------------------------
 void m_get_clk ()
{ 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 27, AT91RM9200_PIO_PERIPHERAL_A, 0);
  AT91RM9200_PMC_REG_STRUCT_PTR  pmc_ptr;
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR) AT91RM9200_PMC_BASE;
  pmc_ptr->SCDR = AT91RM9200_PMC_SCDR_PCK0_DISABLE;
  pmc_ptr->PCKR[0] = AT91RM9200_PMC_PCKR_CSS_MAINCK;
  pmc_ptr->SCER = AT91RM9200_PMC_SCER_PCK0_ENABLE;
}

//*----------------------------------------------------------------------------
//* \fn    m_get_clk1
//* \get clocks to mux
//*----------------------------------------------------------------------------
 void m_get_clk1 ()     //maked for mux.
{
#ifndef PROG_PRM_PCH_N_2 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_B, 0);
#endif  

#ifdef MAKET_PLATA 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_B, 0);
#endif  
  
  
  AT91RM9200_PMC_REG_STRUCT_PTR  pmc_ptr;
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR) AT91RM9200_PMC_BASE;
  pmc_ptr->SCDR = AT91RM9200_PMC_SCDR_PCK1_DISABLE;
//ok  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_MAINCK;
 // pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLBCK | AT91RM9200_PMC_PCKR_PRESCALER_2;
#ifndef PROG_PRM_PCH_SPI_XIL 
  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_MAINCK;     //18384000
#else
  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLACK | AT91RM9200_PMC_PCKR_PRESCALER_4;
#endif  
  
  pmc_ptr->SCER = AT91RM9200_PMC_SCER_PCK1_ENABLE;
}

//*----------------------------------------------------------------------------
//* \fn    m_get_clk2
//* \get clocks to mux
//*----------------------------------------------------------------------------
 void m_get_clk2 ()     //maked for mux.
{
#ifndef PROG_PRM_PCH_N_2 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_B, 0);
#endif  

#ifdef MAKET_PLATA 
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_B, 0);
#endif  
  
  
  AT91RM9200_PMC_REG_STRUCT_PTR  pmc_ptr;
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR) AT91RM9200_PMC_BASE;
  pmc_ptr->SCDR = AT91RM9200_PMC_SCDR_PCK1_DISABLE;
//ok  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_MAINCK;
//   pmc_ptr->PLLBR = 0x10483e0d; //121204
   
   pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLBCK | AT91RM9200_PMC_PCKR_PRESCALER_2;
//   pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLACK | AT91RM9200_PMC_PCKR_PRESCALER_2;

//  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLBCK; //121204
//#ifndef PROG_PRM_PCH_SPI_XIL 
//  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_MAINCK;     //18384000
//#else
//  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_PLLACK | AT91RM9200_PMC_PCKR_PRESCALER_2;
//  pmc_ptr->PCKR[1] = AT91RM9200_PMC_PCKR_CSS_MAINCK;// | AT91RM9200_PMC_PCKR_PRESCALER_2; //121102
//#endif  
  
  pmc_ptr->SCER = AT91RM9200_PMC_SCER_PCK1_ENABLE;
}



//*----------------------------------------------------------------------------
//* \fn    delay_mcs
//* \brief delay in microseconds
//*----------------------------------------------------------------------------
 void delay_mcs ( unsigned long time  )
{ /* Body */
  uint_32 cnt;
   //  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR); 

  uint_32 clk = (uint_32)(BSP_PROCESSOR_CLOCK) /  (uint_32)(DelayConst);
//120130  uint_32 div = 100l;
  uint_32 div = 300l; //to have really mcs
  
   cnt = (time * clk ) / div;
  for(uint_32 i = cnt; i ; i--)
   { /* Body */
   
   } /* Endbody */
   
 //   _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
   	  //				      AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
     //   				      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
                 //       AT91RM9200_AIC_SMR_SRCTYPE_LLS,   //low level
   	 // 				      AT91RM9200_AIC_SMR_PRIO_MIN );  

 
} /* Endbody */

//*----------------------------------------------------------------------------
//* \fn    delay_mcs
//* \brief delay in microseconds
//*----------------------------------------------------------------------------
// void delay_mcs1 ( uint_32 time  )
//{ /* Body */
//  uint_32 cnt;
   //  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR); 

 //  uint_32 clk = (uint_32)(BSP_PROCESSOR_CLOCK) /  (uint_32)(DelayConst);
 // uint_32 div = 100l;
  
 //  cnt = (time * clk ) / div;
 //   printf("\n\rtime = %d ,cnt = %d ", time, cnt);
 
 // for(uint_32 i = cnt; i ; i--)
 //  { /* Body */
   
 //  } /* Endbody */
   
 //   _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
   	  //				      AT91RM9200_AIC_SMR_SRCTYPE_PET,   //positive edge triggered 
     //   				      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
                 //       AT91RM9200_AIC_SMR_SRCTYPE_LLS,   //low level
   	 // 				      AT91RM9200_AIC_SMR_PRIO_MIN );  

 
//} /* Endbody */


//*----------------------------------------------------------------------------
//* \fn    delay_ms
//* \brief delay in milliseconds
//*----------------------------------------------------------------------------
 void delay_ms ( uint_32 time  )
{ /* Body */
  uint_32 cnt;
  uint_32 clk = (uint_32)(BSP_PROCESSOR_CLOCK) /  (uint_32)(DelayConst);
  uint_32 div = 100l;
   cnt = (time * clk * 1000l ) / div;
   for(uint_32 i = cnt; i ; i--)
   { /* Body */
   
   } /* Endbody */
 
} /* Endbody */

	 
/* *****************************************************************************
                SOFTWARE API FOR PDC
   ***************************************************************************** */
//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_SetNextRx
//* \brief Set the next receive transfer descriptor
//*----------------------------------------------------------------------------
 void AT91F_PDC_SetNextRx (
	AT91PS_PDC pPDC,     // \arg pointer to a PDC controller
	char *address,       // \arg address to the next bloc to be received
	unsigned int bytes)  // \arg number of bytes to be received
{
	pPDC->PDC_RNPR = (unsigned int) address;
	pPDC->PDC_RNCR = bytes;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_SetNextTx
//* \brief Set the next transmit transfer descriptor
//*----------------------------------------------------------------------------
 void AT91F_PDC_SetNextTx (
	AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
	char *address,         // \arg address to the next bloc to be transmitted
	unsigned int bytes)    // \arg number of bytes to be transmitted
{
	pPDC->PDC_TNPR = (unsigned int) address;
	pPDC->PDC_TNCR = bytes;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_SetRx
//* \brief Set the receive transfer descriptor
//*----------------------------------------------------------------------------
 void AT91F_PDC_SetRx (
	AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
	char *address,         // \arg address to the next bloc to be received
	unsigned int bytes)    // \arg number of bytes to be received
{
	pPDC->PDC_RPR = (unsigned int) address;
	pPDC->PDC_RCR = bytes;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_SetTx
//* \brief Set the transmit transfer descriptor
//*----------------------------------------------------------------------------
 void AT91F_PDC_SetTx (
	AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
	char *address,         // \arg address to the next bloc to be transmitted
	unsigned int bytes)    // \arg number of bytes to be transmitted
{
	pPDC->PDC_TPR = (unsigned int) address;
	pPDC->PDC_TCR = bytes;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_EnableTx
//* \brief Enable transmit
//*----------------------------------------------------------------------------
 void AT91F_PDC_EnableTx (
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	pPDC->PDC_PTCR = AT91C_PDC_TXTEN;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_EnableRx
//* \brief Enable receive
//*----------------------------------------------------------------------------
 void AT91F_PDC_EnableRx (
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	pPDC->PDC_PTCR = AT91C_PDC_RXTEN;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_DisableTx
//* \brief Disable transmit
//*----------------------------------------------------------------------------
 void AT91F_PDC_DisableTx (
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	pPDC->PDC_PTCR = AT91C_PDC_TXTDIS;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_DisableRx
//* \brief Disable receive
//*----------------------------------------------------------------------------
 void AT91F_PDC_DisableRx (
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	pPDC->PDC_PTCR = AT91C_PDC_RXTDIS;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_IsTxEmpty
//* \brief Test if the current transfer descriptor has been sent
//*----------------------------------------------------------------------------
 int AT91F_PDC_IsTxEmpty ( // \return return 1 if transfer is complete
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	return !(pPDC->PDC_TCR);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_IsNextTxEmpty
//* \brief Test if the next transfer descriptor has been moved to the current td
//*----------------------------------------------------------------------------
 int AT91F_PDC_IsNextTxEmpty ( // \return return 1 if transfer is complete
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	return !(pPDC->PDC_TNCR);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_IsRxEmpty
//* \brief Test if the current transfer descriptor has been filled
//*----------------------------------------------------------------------------
 int AT91F_PDC_IsRxEmpty ( // \return return 1 if transfer is complete
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	return !(pPDC->PDC_RCR);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_IsNextRxEmpty
//* \brief Test if the next transfer descriptor has been moved to the current td
//*----------------------------------------------------------------------------
 int AT91F_PDC_IsNextRxEmpty ( // \return return 1 if transfer is complete
	AT91PS_PDC pPDC )       // \arg pointer to a PDC controller
{
	return !(pPDC->PDC_RNCR);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_Open
//* \brief Open PDC: disable TX and RX reset transfer descriptors, re-enable RX and TX
//*----------------------------------------------------------------------------
 void AT91F_PDC_Open (
	AT91PS_PDC pPDC)       // \arg pointer to a PDC controller
{
    //* Disable the RX and TX PDC transfer requests
	AT91F_PDC_DisableRx(pPDC);
	AT91F_PDC_DisableTx(pPDC);

	//* Reset all Counter register Next buffer first
	AT91F_PDC_SetNextTx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetNextRx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetTx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetRx(pPDC, (char *) 0, 0);

    //* Enable the RX and TX PDC transfer requests
	AT91F_PDC_EnableRx(pPDC);
	AT91F_PDC_EnableTx(pPDC);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_Close
//* \brief Close PDC: disable TX and RX reset transfer descriptors
//*----------------------------------------------------------------------------
 void AT91F_PDC_Close (
	AT91PS_PDC pPDC)       // \arg pointer to a PDC controller
{
    //* Disable the RX and TX PDC transfer requests
	AT91F_PDC_DisableRx(pPDC);
	AT91F_PDC_DisableTx(pPDC);

	//* Reset all Counter register Next buffer first
	AT91F_PDC_SetNextTx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetNextRx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetTx(pPDC, (char *) 0, 0);
	AT91F_PDC_SetRx(pPDC, (char *) 0, 0);

}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_SendFrame
//* \brief Close PDC: disable TX and RX reset transfer descriptors
//*----------------------------------------------------------------------------
 unsigned int AT91F_PDC_SendFrame(
	AT91PS_PDC pPDC,
	char *pBuffer,
	unsigned int szBuffer,
	char *pNextBuffer,
	unsigned int szNextBuffer )
{
	if (AT91F_PDC_IsTxEmpty(pPDC)) {
		//* Buffer and next buffer can be initialized
		AT91F_PDC_SetTx(pPDC, pBuffer, szBuffer);
		AT91F_PDC_SetNextTx(pPDC, pNextBuffer, szNextBuffer);
		return 2;
	}
	else if (AT91F_PDC_IsNextTxEmpty(pPDC)) {
		//* Only one buffer can be initialized
		AT91F_PDC_SetNextTx(pPDC, pBuffer, szBuffer);
		return 1;
	}
	else {
		//* All buffer are in use...
		return 0;
	}
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_PDC_ReceiveFrame
//* \brief Close PDC: disable TX and RX reset transfer descriptors
//*----------------------------------------------------------------------------
unsigned int AT91F_PDC_ReceiveFrame (
	AT91PS_PDC pPDC,
	char *pBuffer,
	unsigned int szBuffer,
	char *pNextBuffer,
	unsigned int szNextBuffer )
{
	if (AT91F_PDC_IsRxEmpty(pPDC)) {
		//* Buffer and next buffer can be initialized
		AT91F_PDC_SetRx(pPDC, pBuffer, szBuffer);
		AT91F_PDC_SetNextRx(pPDC, pNextBuffer, szNextBuffer);
		return 2;
	}
	else if (AT91F_PDC_IsNextRxEmpty(pPDC)) {
		//* Only one buffer can be initialized
		AT91F_PDC_SetNextRx(pPDC, pBuffer, szBuffer);
		return 1;
	}
	else {
		//* All buffer are in use...
		return 0;
	}
}
//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_SetBaudrate
//* \brief Set the baudrate according to the CPU clock
//*----------------------------------------------------------------------------
void AT91F_SSC_SetBaudrate (
        AT91PS_SSC pSSC,        // \arg pointer to a SSC controller
        unsigned int mainClock, // \arg peripheral clock
        unsigned int speed)     // \arg SSC baudrate
{
        unsigned int baud_value;
        //* Define the baud rate divisor register
        if (speed == 0)
           baud_value = 0;
        else
        {
           baud_value = (unsigned int) (mainClock * 10)/(2*speed);
           if ((baud_value % 10) >= 5)
                  baud_value = (baud_value / 10) + 1;
           else
                  baud_value /= 10;
        }

        pSSC->SSC_CMR = baud_value;
}



//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_Configure
//* \brief Configure SSC
//*----------------------------------------------------------------------------
  void AT91F_SSC_Configure (
             AT91PS_SSC pSSC,          // \arg pointer to a SSC controller   ssc0_ptr
             unsigned int syst_clock,  // \arg System Clock Frequency BSP_MASTER_CLOCK
             unsigned int baud_rate,   // \arg Expected Baud Rate Frequency XIL_LOAD_FREQ
             unsigned int clock_rx,    // \arg Receiver Clock Parameters   0
             unsigned int mode_rx,     // \arg mode Register to be programmed 0
             unsigned int clock_tx,    // \arg Transmitter Clock Parameters  0
             unsigned int mode_tx)     // \arg mode Register to be programmed  0x87?
{
    //* Disable interrupts
	pSSC->SSC_IDR = (unsigned int) -1;

    //* Reset receiver and transmitter
	pSSC->SSC_CR = AT91C_SSC_SWRST | AT91C_SSC_RXDIS | AT91C_SSC_TXDIS ;

    //* Define the Clock Mode Register
	AT91F_SSC_SetBaudrate(pSSC, syst_clock, baud_rate);

     //* Write the Receive Clock Mode Register
	pSSC->SSC_RCMR =  clock_rx;

     //* Write the Transmit Clock Mode Register
	pSSC->SSC_TCMR =  clock_tx;

     //* Write the Receive Frame Mode Register
	pSSC->SSC_RFMR =  mode_rx;

     //* Write the Transmit Frame Mode Register
	pSSC->SSC_TFMR =  mode_tx;

    //* Clear Transmit and Receive Counters
	AT91F_PDC_Open((AT91PS_PDC) &(pSSC->SSC_RPR));
}
//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_EnableRx
//* \brief Enable receiving datas
//*----------------------------------------------------------------------------
 void AT91F_SSC_EnableRx (
	AT91PS_SSC pSSC)     // \arg pointer to a SSC controller
{
    //* Enable receiver
    pSSC->SSC_CR = AT91C_SSC_RXEN;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_DisableRx
//* \brief Disable receiving datas
//*----------------------------------------------------------------------------
 void AT91F_SSC_DisableRx (
	AT91PS_SSC pSSC)     // \arg pointer to a SSC controller
{
    //* Disable receiver
    pSSC->SSC_CR = AT91C_SSC_RXDIS;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_EnableTx
//* \brief Enable sending datas
//*----------------------------------------------------------------------------
 void AT91F_SSC_EnableTx (
	AT91PS_SSC pSSC)     // \arg pointer to a SSC controller
{
    //* Enable  transmitter
    pSSC->SSC_CR = AT91C_SSC_TXEN;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_DisableTx
//* \brief Disable sending datas
//*----------------------------------------------------------------------------
 void AT91F_SSC_DisableTx (
	AT91PS_SSC pSSC)     // \arg pointer to a SSC controller
{
    //* Disable  transmitter
    pSSC->SSC_CR = AT91C_SSC_TXDIS;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_EnableIt
//* \brief Enable SSC IT
//*----------------------------------------------------------------------------
 void AT91F_SSC_EnableIt (
	AT91PS_SSC pSSC, // \arg pointer to a SSC controller
	unsigned int flag)   // \arg IT to be enabled
{
	//* Write to the IER register
	pSSC->SSC_IER = flag;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_DisableIt
//* \brief Disable SSC IT
//*----------------------------------------------------------------------------
 void AT91F_SSC_DisableIt (
	AT91PS_SSC pSSC, // \arg pointer to a SSC controller
	unsigned int flag)   // \arg IT to be disabled
{
	//* Write to the IDR register
	pSSC->SSC_IDR = flag;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_ReceiveFrame
//* \brief Return 2 if PDC has been initialized with Buffer and Next Buffer, 1 if PDC has been initialized with Next Buffer, 0 if PDC is busy
//*----------------------------------------------------------------------------
 unsigned int AT91F_SSC_ReceiveFrame (
	AT91PS_SSC pSSC,
	char *pBuffer,
	unsigned int szBuffer,
	char *pNextBuffer,
	unsigned int szNextBuffer )
{
	return AT91F_PDC_ReceiveFrame(
		(AT91PS_PDC) &(pSSC->SSC_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_SendFrame
//* \brief Return 2 if PDC has been initialized with Buffer and Next Buffer, 1 if PDC has been initialized with Next Buffer, 0 if PDC is busy
//*----------------------------------------------------------------------------
 unsigned int AT91F_SSC_SendFrame(
	AT91PS_SSC pSSC,
	char *pBuffer,
	unsigned int szBuffer,
	char *pNextBuffer,
	unsigned int szNextBuffer )
{
	return AT91F_PDC_SendFrame(
		(AT91PS_PDC) &(pSSC->SSC_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_GetInterruptMaskStatus
//* \brief Return SSC Interrupt Mask Status
//*----------------------------------------------------------------------------
 unsigned int AT91F_SSC_GetInterruptMaskStatus( // \return SSC Interrupt Mask Status
        AT91PS_SSC pSsc) // \arg  pointer to a SSC controller
{
        return pSsc->SSC_IMR;
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC_IsInterruptMasked
//* \brief Test if SSC Interrupt is Masked 
//*----------------------------------------------------------------------------
 int AT91F_SSC_IsInterruptMasked(
        AT91PS_SSC pSsc,   // \arg  pointer to a SSC controller
        unsigned int flag) // \arg  flag to be tested
{
        return (AT91F_SSC_GetInterruptMaskStatus(pSsc) & flag);
}

 //*----------------------------------------------------------------------------
//* \fn    AT91F_I2S_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_Handler
//* This function updates the next SSC PDC pointer to send the next buffer
//*----------------------------------------------------------------------------
//void AT91F_I2S_Handler(void)
//{
//   AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
 //	status = pSSC1->SSC_SR;
//   	status = ssc0_ptr->SSC_SR;
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//}
//*----------------------------------------------------------------------------
//* \fn    AT91F_I2S_Init_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_INIT_Handler
//* This function initializes the synchronization between left and right channels
//*----------------------------------------------------------------------------
//void AT91F_I2S_Init_Handler(void)
//{
//	volatile unsigned int status;
//	AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
	// Disable all interrupts
//	AT91F_SSC_DisableIt (ssc0_ptr, 0xFFFFFFFF);
	// Configure AIC controller for the next SSC interrupts
 //	AT91F_AIC_ConfigureIt (
 //		AT91C_BASE_AIC,                        // AIC base address
 //		AT91C_ID_SSC1,                         // System peripheral ID
//		AT91C_IRQ_LEVEL_I2S,               	   // Max priority
//		AT91C_AIC_SRCTYPE_INT_EDGE_TRIGGERED, // Level sensitive
//		AT91F_ASM_I2S_Handler );	
// _int_install_isr(AT91RM9200_SSC0_VECTOR,
//      (void (_CODE_PTR_)(pointer))AT91F_I2S_Handler, NULL); 
// 
//  _at91rm9200_int_enable(AT91RM9200_SSC0_VECTOR, IRQ, 
//   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
    //					      AT91RM9200_AIC_SMR_PRIO_MIN);
//                           AT91RM9200_AIC_SMR_PRIO_MAX);
	// Enable SSC interrupt in AIC
 //	AT91F_AIC_EnableIt(AT91C_BASE_AIC, AT91C_ID_SSC1);
	// Get status
//	status = ssc0_ptr->SSC_SR;
	// Wait the next frame beginning (SYNC)
//	while (status & AT91C_SSC_TXSYN == 0){
//		status = ssc0_ptr->SSC_SR;
//	}
	// Select next interrupt type
//	AT91F_SSC_EnableIt (ssc0_ptr, AT91C_SSC_ENDTX);	
	// ============================= Configure PDC associated to SSC1 =============================
	// PDC already opened in SSC_Configure function 
//	
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						 AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
//					 (char *)wav_file,					// pointer to data
//					AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
//
//	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// Start music !!!	
//
//}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable
* Returned Value   : none
* Comments         :
*    disable some interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  //t aic_ptr->IDCR = 0xFFFFFFFF;
   aic_ptr->IDCR = 0xFEFDFFFF;  //timer0 and ethernet keep

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable
* Returned Value   : none
* Comments         :
*    enable some interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
 //    aic_ptr->IDCR = 0xFFFFFFFF;
  //   aic_ptr->IECR = (1l << 25); //irq0
 //    aic_ptr->IECR = (1l << 26); //pid irq1 == 26
 //    aic_ptr->IECR = (1l << 27); //pid irq2 == 27
     aic_ptr->IECR = (1l << 6); //pid usart0 == 6
     aic_ptr->IECR = (1l << 7); //pid usart1 == 7
     aic_ptr->IECR = (1l << 9); //pid usart3 == 9
 //___________________________________________________________________:::::
 
#ifdef PROG_PRM_PCH_SPI    //? need in non - macket ktvm , dtvm ??????
 aic_ptr->IECR = (1l << AT91RM9200_SSC2_PID); 
#endif //USE_PULT

#ifdef PROG_PRM_PCH_SPI_XIL    //? need in non - macket ktvm , dtvm ??????

 aic_ptr->IECR = (1l << 25); //irq0

#endif //USE_PULT

 
 
#ifdef USE_PULT    //? need in non - macket ktvm , dtvm ??????
 aic_ptr->IECR = (1l << 27); //pid irq2 == 27
#endif //USE_PULT

#ifdef PROG_BMD34
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BMD34 

#ifdef PROG_BMD35
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BMD35 

#ifdef PROG_PROV
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PROV 

#ifdef PROG_MPC35
//not need ? aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_MPC35 



#ifdef PROG_KTVM
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_KTVM 

#ifdef PROG_DTVM
 aic_ptr->IECR = (1l << 25); //irq0
 aic_ptr->IECR = (1l << 26); //pid irq1 == 26
#endif //PROG_DTVM 

#ifdef PROG_MPC155
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_MPC155  

#ifdef PROG_MPC4E
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_MPC4E  


#ifdef PROG_BMD155
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BMD155 

#ifdef PROG_COMMUTATOR
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BMD155  
 

#ifdef PROG_BMDN
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BMDN  


#ifdef PROG_BUKC
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BUKC  

#ifdef PROG_PRM_PCH
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PRM_PCH  

#ifdef PROG_PRM_PCH_DEM
 //aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PRM_PCH_DEM  

#ifdef PROG_PU_M
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_M 

#ifdef PROG_PU_M_V
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_M 

#ifdef PROG_PU_M_V_A
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_M 


#ifdef PROG_UPS
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_UPS 


#ifdef PROG_PU_M100
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_M100 

#ifdef PROG_PU_MSAT
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_MSAT 



#ifdef PROG_PU_M_MUX
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PU_M_MUX 

#ifdef PROG_BUKU
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_BUKU 

#ifdef PROG_PUM
 aic_ptr->IECR = (1l << 25); //irq0
#endif //PROG_PUM  
 
#ifdef PROG_MPC34
     //not need                           
#endif //PROG_MPC34  
//___________________________________________________________________:::::           
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_irq0
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable_irq0()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 25); //pid irq0 == 25
   

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_SSC2
* Returned Value   : none
* Comments         :
*    enable interrupt
*END*----------------------------------------------------------------------*/

void  my_int_enable_SSC2()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 16); //pid ssc2 == 16

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_SSC2
* Returned Value   : none
* Comments         :
*    disable interrupt
*END*----------------------------------------------------------------------*/

void  my_int_disable_SSC2()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 16); //pid ssc2 == 16

}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_irq0
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable_irq0()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 25); //pid irq0 == 25

}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_irq1
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable_irq1()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 26); //pid irq1 == 26

}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_irq1
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable_irq1()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 26); //pid irq1 == 26

}




/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_irq2
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable_irq2()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                 //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 27); //pid irq2 == 27

}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_irq2
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable_irq2()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                 //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 27); //pid irq2 == 27

}



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_usart0
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable_usart0()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 6); //pid usart0 == 6

}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_usart0
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable_usart0()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 6); //pid usart0 == 6

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_disable_eth
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_disable_eth()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IDCR = (1l << 24); //pid eth == 24

}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_int_enable_eth
* Returned Value   : none
* Comments         :
*    disable all interrupts
*END*----------------------------------------------------------------------*/

void  my_int_enable_eth()
{
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
   aic_ptr->IECR = (1l << 24); //pid eth == 24

}




 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SendXilData
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx through io functions
*
*END*----------------------------------------------------------------------*/
/*
void SendXilData(unsigned int SizeToDownload, unsigned int * AddressToDownload)
{
 unsigned int  i;
  SizeToDownload >>= 2; //one word in sdram is four bytes
  i = 0;
  for(i = 0; i <  SizeToDownload; i++)
  {   
    SendSerial(* AddressToDownload++);
  } 
}
   */
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_load_xilinx_IO
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx through io functions
*
*END*----------------------------------------------------------------------*/
/*
void m_load_xilinx_IO (void)
{
  unsigned int imr;//, wd;
//  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
//  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
//  unsigned int XilDataAddress = TestDataAddressD; //for test;
 
   unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS);//XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
   unsigned int XilSizeToDownload = XilSizeToDownloadD; //0x1ffff;
// unsigned int XilSizeToDownload = 16; //0x1ffff;

   volatile unsigned int status;
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
//ok
//     my_int_disable();
    imr =  aic_ptr->IMR;
    aic_ptr->IDCR = 0xFFFFFFFF;
 	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
 //   imr =  aic_ptr->IMR;
 //   aic_ptr->IDCR = 0xFFFFFFFF;
  
    
  //  delay_mcs(400l); 
    pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
     pio_ptr->CODR = 1;
     pio_ptr->CODR = 2; //clock to zero
     pio_ptr->CODR = 4; //data to zero
    delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
  //  delay_mcs(800l);
    pio_ptr->SODR = 1;
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
    delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
  //  delay_mcs(400l);
 //   delay_mcs(400l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
    status = pio_ptr->PDSR & (1 << 4); //line init hier one
    SendXilData(XilSizeToDownload, (unsigned int *)(XilAddressToDownload));
    status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //  delay_mcs(10000l);  //to view
      aic_ptr->IECR = imr;
 
 //     _int_enable();
} 
      */
      
#define AT91RM9200_DBGU_MR_OVER			(0x00080000)      
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/
void SetUsart1BaudRate(unsigned long rate)
{
 uint_32                               clkdiv;
 uint_32                               mr;
 AT91RM9200_USART_REG_STRUCT_PTR usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
 clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 8 * (rate / 10));//divide to 10 later    //will be setted over 8
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * (rate / 10));//divide to 10 later    //will be setted over 16
//make nearest value for subduvided clkdivs
 if((clkdiv % 10) > 5) clkdiv = (clkdiv / 10) + 1;
 else  clkdiv = (clkdiv / 10);
//  clkdiv = io_info_ptr->INIT.CLOCK_SPEED /
//     	  (16 * io_info_ptr->INIT.BAUD_RATE);

//  if ((clkdiv > 65535) || (clkdiv == 0)) {
 //    return (MQX_INVALID_PARAMETER);
//  } /* Endif */

  usart1_ptr->BRGR = clkdiv;
  
  mr =  usart1_ptr->MR;
  usart1_ptr->MR = mr | AT91RM9200_DBGU_MR_OVER;   //set over = 8
  


} 

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : setusart0baudrate  : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/
void SetUsart0BaudRate(unsigned long rate)
{
 uint_32                               clkdiv;
 uint_32                               mr;
 AT91RM9200_USART_REG_STRUCT_PTR usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
 clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 8 * (rate / 10));//divide to 10 later    //will be setted over 8
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * (rate / 10));//divide to 10 later    //will be setted over 16
//make nearest value for subduvided clkdivs
 if((clkdiv % 10) > 5) clkdiv = (clkdiv / 10) + 1;
 else  clkdiv = (clkdiv / 10);
//  clkdiv = io_info_ptr->INIT.CLOCK_SPEED /
//     	  (16 * io_info_ptr->INIT.BAUD_RATE);

//  if ((clkdiv > 65535) || (clkdiv == 0)) {
 //    return (MQX_INVALID_PARAMETER);
//  } /* Endif */

  usart0_ptr->BRGR = clkdiv;
  
  mr =  usart0_ptr->MR;
  usart0_ptr->MR = mr | AT91RM9200_DBGU_MR_OVER;   //set over = 8
  


} 

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : setusart2baudrate  : none
* Comments         :
*    This function maked enable pdc channel for usart2
*
*END*----------------------------------------------------------------------*/
void SetUsart2BaudRate(unsigned long rate)
{
 uint_32                               clkdiv;
 uint_32                               mr;
 AT91RM9200_USART_REG_STRUCT_PTR usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * rate);
 clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 8 * (rate / 10));//divide to 10 later    //will be setted over 8
// clkdiv = (BSP_MAIN_CLOCK * (BSP_PLL_MULF)) / (BSP_PLL_DIVF * 3  * 16 * (rate / 10));//divide to 10 later    //will be setted over 16
//make nearest value for subduvided clkdivs
 if((clkdiv % 10) > 5) clkdiv = (clkdiv / 10) + 1;
 else  clkdiv = (clkdiv / 10);
//  clkdiv = io_info_ptr->INIT.CLOCK_SPEED /
//     	  (16 * io_info_ptr->INIT.BAUD_RATE);

//  if ((clkdiv > 65535) || (clkdiv == 0)) {
 //    return (MQX_INVALID_PARAMETER);
//  } /* Endif */

  usart2_ptr->BRGR = clkdiv;
  
  mr =  usart2_ptr->MR;
  usart2_ptr->MR = mr | AT91RM9200_DBGU_MR_OVER;   //set over = 8
  


} 

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : SetUsart2RS485e  : none
* Comments         :
*    This function maked enable pdc channel for usart2
*
*END*----------------------------------------------------------------------*/
//t 130828 void SetUsart2RS485(void)
/*
void SetUsart2ToRS485(void)   //t130828
{
//printfp("\n\r SetUsart2_To_RS485");

#ifdef MAKET_PLATA	
  return;
#endif
 uint_32                               clkdiv;
 uint_32                               mr;
 AT91RM9200_USART_REG_STRUCT_PTR usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;

  mr =  usart2_ptr->MR;
  usart2_ptr->MR = mr | 1;   //set over = 8
} 

      */


#ifdef USART0_TRY_PDC
 
//#define USART0_RX_BUFFER 3  
//#define USART0_RX_BUFFER 16  
#define USART0_RX_BUFFER 2  
//#define USART0_RX_BUFFER 700  

//#define USART0_RX_BUFFER 256  
#define USART0_RX_BUFFER2   (USART0_RX_BUFFER*10)

#define USART0_TIMEOUT   1
//t#define USART0_TIMEOUT   2
//t1208#define USART0_TIMEOUT   1
// #define USART0_TIMEOUT   350


//#define USART0_TIMEOUT   16
#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)      
#define AT91RM9200_DBGU_RETTO_ENABLE		(0x00008000)
  
unsigned char Buff[USART0_RX_BUFFER]; //buffer
unsigned char Buff1[USART0_RX_BUFFER]; //buffer

unsigned char BuffTest2[USART0_RX_BUFFER2]; //buffer
unsigned char BuffTest[USART0_RX_BUFFER];
unsigned char BuffTest1[USART0_RX_BUFFER];
extern unsigned char flag_pdc0;


 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : PrintTestBuf
* Returned Value   : none
* Comments         :
*    This function print debug info from test buffer..
*
*END*----------------------------------------------------------------------*/
extern "C" void PrintTestBuf(void)
{
 static unsigned long keep = 0;
  unsigned long i = 0l;
  if(keep != counter_int)
#ifndef USART0_TRY_PDC_1T  
  printf("\n\r %d %d", counter_int, counter_int1);
#endif  
  keep =    counter_int;
  /* 
  while(i < USART0_RX_BUFFER)
    { //
 //     printf(". %02X",BuffTest[i]);
     //read from Buff to any receive 232 buffer
     i++;
    } //
 //   printf("----");

    i = 0;
     while(i < USART0_RX_BUFFER)
    { //
 //     printf("_ %02X",BuffTest1[i]);
     //read from Buff to any receive 232 buffer
     i++;
    } //
    */
#ifndef USART0_TRY_PDC_1T     
  //  printf("----");
#endif    
    i = 0;
   while(i < USART0_RX_BUFFER2)
    { //
#ifndef USART0_TRY_PDC_1T    
      printf("- %c",BuffTest2[i]);
#endif      
     //read from Buff to any receive 232 buffer
     i++;
    } //
      
    
    
}


extern unsigned char last_cnt; //need init at start!!!!!
extern unsigned long buff2_cnt; //need init at start!!!!!



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_usart0_timer_int
* Returned Value   : none
* Comments         :
*    This function maked any needed procedures for pdc usart receive.
*
*END*----------------------------------------------------------------------*/
void my_usart0_timer_int()
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 
static unsigned char cnt_flag_pdct = 0;
static unsigned char cnt_flag_pdct1 = 0;
//static unsigned char last_cnt = 0; //need init at start!!!!!
//static unsigned long buff2_cnt = 0; //need init at start!!!!!


unsigned long cnt;
unsigned long i = 0l;

usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;

// usart0_ptr->PDC.RNCR = USART0_RX_BUFFER;
   cnt = USART0_RX_BUFFER - usart0_ptr->PDC.RCR;
   
 //  if(cnt > USART0_RX_BUFFER)  cnt = 0;   //for safe
   
if(cnt >= USART0_RX_BUFFER)
    { 
          cnt = 0;//for safe
      //      BuffTest2[buff2_cnt++] = 'E';
      if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 
    }
   
   
   
   
   
   i = last_cnt;
   counter_int = cnt;//++;   //ok
   counter_int1 = last_cnt;
   if(i > cnt) i = cnt; //for safe
 //  i = 0;
//if(0) 
//if(!flag_pdc0)
//t091207  usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//t return; //t

if(flag_pdc0)
{
    while(i < cnt)
     { //
     
      cnt_flag_pdct++;
    //  BuffTest[i] = Buff[i];        
//      BuffTest[i] = cnt;  //
       BuffTest2[buff2_cnt++] = Buff[i];
  //        BuffTest2[buff2_cnt++] = 't';
       if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 
       
       my_rx_usart0_int(Buff[i]);
 //     my_rx_usart0_int(1);
     //read from Buff to any receive 232 buffer
     
      i++;
    } //
 }
else
{
    while(i < cnt)
    { //
    
      cnt_flag_pdct1++;
    //  BuffTest1[i] = Buff1[i];
      BuffTest2[buff2_cnt++] = Buff1[i];
 //     BuffTest2[buff2_cnt++] = 'T';
      if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 
      
      my_rx_usart0_int(Buff1[i]);
   //   my_rx_usart0_int(2);
         
      i++;
    } //
  // usart0_ptr->PDC.RNPR = (uint_32)&Buff[0]; //next!!!!     //set buff   
}
 //usart0_ptr->PDC.RNCR = USART0_RX_BUFFER; //next!!!!!!!!!!!!!!!!!!!!!!
 
//  BuffTest[0] = i;
//  BuffTest1[0] = cnt_flag_pdc1;
  
 // BuffTest[1] =   cnt;
  
  last_cnt = i;
 // counter_int =  usart0_ptr->PDC.RCR; //last_cnt;//usart0_ptr->PDC.RCR; //t
 // if (cnt == USART0_RX_BUFFER)  last_cnt = 0;  //t
  

 usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
// usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;
//  usart0_ptr->CR =  AT91RM9200_DBGU_STTTO_ENABLE;
}



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : my_usart0_pdc_int
* Returned Value   : none
* Comments         :
*    This function maked any needed procedures for pdc usart receive.
*
*END*----------------------------------------------------------------------*/
void my_usart0_pdc_int()
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;

static unsigned char cnt_flag_pdc = 0;
static unsigned char cnt_flag_pdc1 = 0;
//static unsigned char last_cnt = 0; //need init at start!!!!!
//static unsigned long buff2_cnt = 0; //need init at start!!!!!
unsigned long cnt;   //   2
unsigned long i = 0l;
usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;

// usart0_ptr->PDC.RNCR = USART0_RX_BUFFER;
   cnt = USART0_RX_BUFFER - usart0_ptr->PDC.RCR;
   i = last_cnt;
//   i = 0;
   last_cnt = 0;
   
   if(i >= USART0_RX_BUFFER)
    { 
         i = 0;//for safe
         //   BuffTest2[buff2_cnt++] = 'E';
      if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 
    }
   
// usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;   
//return; //t   
   
 
if(!flag_pdc0)
//if(flag_pdc0)
{
   cnt_flag_pdc++;
   flag_pdc0 = 1;
  //  usart0_ptr->PDC.RNPR = (uint_32)&Buff1[0];     //set buff1
 //   cnt = USART0_RX_BUFFER - usart0_ptr->PDC.RCR;
//this can make in scan mode    
 //  i = 0l;
  // i = last_cnt;
//t    while(i < cnt)
    while(i < USART0_RX_BUFFER)
    { //
      cnt_flag_pdc++;
//     BuffTest[i] = Buff[i];        
//      BuffTest[i] = cnt;  //
//     BuffTest2[buff2_cnt++] = Buff[i];
   //t   BuffTest2[buff2_cnt++] = Buff1[i];
      
           BuffTest2[buff2_cnt++] = Buff1[i];
      if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 
//  my_rx_usart0_int(Buff[i]);

      my_rx_usart0_int(Buff1[i]);
   //   my_rx_usart0_int(3);
     //read from Buff to any receive 232 buffer
      i++;
    } //
   usart0_ptr->PDC.RNPR = (uint_32)&Buff1[0];  //next!!!!!!   //set buff1    
//   usart0_ptr->PDC.RNPR = (uint_32)&Buff[0];  //next!!!!!!   //set buff1    
//   BuffTest[3] = cnt_flag_pdc;
   }
else
{
cnt_flag_pdc1++;
   flag_pdc0 = 0;
  //  usart0_ptr->PDC.RNPR = (uint_32)&Buff[0];      //set buff
    
  //  cnt = USART0_RX_BUFFER - usart0_ptr->PDC.RCR;
 // i =0l;
//    while(i < cnt)
   while(i < USART0_RX_BUFFER)
    { //
      cnt_flag_pdc1++;

 //     BuffTest1[i] = Buff1[i];
  //     BuffTest2[buff2_cnt++] = Buff1[i];
       BuffTest2[buff2_cnt++] = Buff[i];
       if (buff2_cnt >= USART0_RX_BUFFER2)buff2_cnt = 0; 

//      BuffTest1[i] = cnt;
  // 
   //   my_rx_usart0_int(4);
      my_rx_usart0_int(Buff[i]);

     //read from Buff to any receive 232 buffer
     i++;
    } //
   usart0_ptr->PDC.RNPR = (uint_32)&Buff[0]; //next!!!!     //set buff   
}
 usart0_ptr->PDC.RNCR = USART0_RX_BUFFER; //next!!!!!!!!!!!!!!!!!!!!!!
 
//  BuffTest[3] = cnt;
//  BuffTest1[3] = cnt_flag_pdc1;
  
//t25  last_cnt = cnt;
 // if (cnt == USART0_RX_BUFFER)  last_cnt = 0;
  
  usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//   usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;
//  BuffTest[2] = cnt_flag_pdc;
//  BuffTest1[2] = cnt_flag_pdc1;
  
//  BuffTest[3] = cnt;
//  BuffTest1[3] = last_cnt;

 
}

   
      
//#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)    
#define AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE		(0x00000100)  
      
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/
  
void enableRxPdcUsart0()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  usart0_ptr->PDC.RPR = (uint_32)&Buff[0];
  usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
  usart0_ptr->PDC.RNPR = (uint_32)&Buff1[0];
  usart0_ptr->PDC.RNCR = USART0_RX_BUFFER;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
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
   usart0_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//   usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

  usart0_ptr->RTOR = USART0_TIMEOUT;
  usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
  
}

#endif // USART0_TRY_PDC

#ifdef  USART1_TRY_PDC

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/

//#define USART0_RX_BUFFER 3  
//#define USART0_RX_BUFFER 16  
#define USART1_RX_BUFFER 1000  
//#define USART0_RX_BUFFER 700  

//#define USART0_RX_BUFFER 256  
//#define USART0_RX_BUFFER2   (USART0_RX_BUFFER*10)

//#define USART0_TIMEOUT   1
//t#define USART0_TIMEOUT   2
//t1208#define USART0_TIMEOUT   1
// #define USART0_TIMEOUT   350


//#define USART0_TIMEOUT   16
//#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)      
//#define AT91RM9200_DBGU_RETTO_ENABLE		(0x00008000)
//#pragma BSS(".buff_pdp")
  
unsigned char Buffu1[USART1_RX_BUFFER]; //buffer
unsigned char Buff1u1[USART1_RX_BUFFER]; //buffer

//#pragma BSS()


  
void enableRxPdcUsart1()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
 usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  usart1_ptr->PDC.RPR = (uint_32)&Buffu1[0];
  usart1_ptr->PDC.RCR = USART1_RX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcu1 = 0;

  usart1_ptr->PDC.RNPR = (uint_32)&Buff1u1[0];
  usart1_ptr->PDC.RNCR = USART1_RX_BUFFER;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
   usart1_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
     usart1_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
  
#ifdef PROG_PRM_PCH_N
    SetUsart1BaudRate(921600l);
#else 
//#ifdef PROG_COMMUTATOR1
#ifdef PROG_ODU1
 //   SetUsart1BaudRate(9600l);
    SetUsart1BaudRate(115200l);   //160516
#else

#ifdef PROG_ODU4
 //   SetUsart1BaudRate(9600l);
    SetUsart1BaudRate(115200l);   //160516

#else

#ifdef PROG_PRM_PCH_SPI_ETH_UART
 //   SetUsart1BaudRate(9600l);
    SetUsart1BaudRate(115200l);   //160516

#else



    SetUsart1BaudRate(38400l); 
#endif    
#endif
#endif 
#endif



}


void OperateBuffers_usart1(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
 usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
 
 unsigned long byte_cnt;
usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
 byte_cnt = usart1_ptr->PDC.RCR;
usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcu1)
 {
  if(byte_cnt < USART1_RX_BUFFER)
   {
 //   printfpd("\n\r 1: %d",byte_cnt); 
    usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart1_ptr->PDC.RCR;
    usart1_ptr->PDC.RPR = (uint_32)&Buff1u1[0];
    usart1_ptr->PDC.RCR = USART1_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu1 = 1;
    usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ReadDatau1((unsigned char *)&Buffu1[0], (USART1_RX_BUFFER - byte_cnt));
   }
 }
 else
 {
 if(byte_cnt < USART1_RX_BUFFER)
   {
  //  printfpd("\n\r 2: %d",byte_cnt); 
    usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart1_ptr->PDC.RCR;
    usart1_ptr->PDC.RPR = (uint_32)&Buffu1[0];
    usart1_ptr->PDC.RCR = USART1_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu1 = 0;
    usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ReadDatau1((unsigned char *)&Buff1u1[0], (USART1_RX_BUFFER - byte_cnt));
   }
 }
 
}





#endif // USART1_TRY_PDC

#ifdef  USART2_TRY_PDC

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart2
*
*END*----------------------------------------------------------------------*/

//#define USART0_RX_BUFFER 3  
//#define USART0_RX_BUFFER 16  
#define USART2_RX_BUFFER 1000  
//#define USART0_RX_BUFFER 700  

//#define USART0_RX_BUFFER 256  
//#define USART0_RX_BUFFER2   (USART0_RX_BUFFER*10)

//#define USART0_TIMEOUT   1
//t#define USART0_TIMEOUT   2
//t1208#define USART0_TIMEOUT   1
// #define USART0_TIMEOUT   350


//#define USART0_TIMEOUT   16
//#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)      
//#define AT91RM9200_DBGU_RETTO_ENABLE		(0x00008000)
//#pragma BSS(".buff_pdp")
  
unsigned char Buffu2[USART2_RX_BUFFER]; //buffer
unsigned char Buff1u2[USART2_RX_BUFFER]; //buffer

//#pragma BSS()


#define  T91RM9200_DBGU_MR_2_STOP_BITS (0x2000) 
void enableRxPdcUsart2()
{
  AT91RM9200_USART_REG_STRUCT_PTR         usart2_ptr;
 usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  usart2_ptr->PDC.RPR = (uint_32)&Buffu2[0];
  usart2_ptr->PDC.RCR = USART2_RX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcu2 = 0;

  usart2_ptr->PDC.RNPR = (uint_32)&Buff1u2[0];
  usart2_ptr->PDC.RNCR = USART2_RX_BUFFER;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
   usart2_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
     usart2_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
  
//#ifdef PROG_PRM_PCH_N
//    SetUsart2BaudRate(921600l);
//#else 
//101202    SetUsart2BaudRate(115200l); 
#ifndef PROG_PU_MSAT
    SetUsart2BaudRate(38400l); 
#else
    SetUsart2BaudRate(57600l); 
    usart2_ptr->MR |= T91RM9200_DBGU_MR_2_STOP_BITS;
#endif    
//#endif 

#ifdef 	PROG_MD310_SATI
     SetUsart2BaudRate(57600l); 
    usart2_ptr->MR |= T91RM9200_DBGU_MR_2_STOP_BITS;
#endif

}


void OperateBuffers_usart2(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart2_ptr;
 usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;
 
 unsigned long byte_cnt;
usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
 byte_cnt = usart2_ptr->PDC.RCR;
usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcu2)
 {
  if(byte_cnt < USART2_RX_BUFFER)
   {
  //  printfpd("\n\r 1: %d",byte_cnt); 
    usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart2_ptr->PDC.RCR;
    usart2_ptr->PDC.RPR = (uint_32)&Buff1u2[0];
    usart2_ptr->PDC.RCR = USART2_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu2 = 1;
    usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ReadDatau2((unsigned char *)&Buffu2[0], (USART2_RX_BUFFER - byte_cnt));
   }
 }
 else
 {
 if(byte_cnt < USART2_RX_BUFFER)
   {
  //  printfpd("\n\r 2: %d",byte_cnt); 
    usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart2_ptr->PDC.RCR;
    usart2_ptr->PDC.RPR = (uint_32)&Buffu2[0];
    usart2_ptr->PDC.RCR = USART2_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu2 = 0;
    usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ReadDatau2((unsigned char *)&Buff1u2[0], (USART2_RX_BUFFER - byte_cnt));
   }
 }
 
}





#endif // USART2_TRY_PDC


//_________________________________________________________________________
#ifdef  USART0_TRY_PDC_1

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/

//#define USART0_RX_BUFFER 3  
//#define USART0_RX_BUFFER 16  
#define USART0_RX_BUFFER 1000  
//#define USART0_RX_BUFFER 700  

//#define USART0_RX_BUFFER 256  
//#define USART0_RX_BUFFER2   (USART0_RX_BUFFER*10)

//#define USART0_TIMEOUT   1
//t#define USART0_TIMEOUT   2
//t1208#define USART0_TIMEOUT   1
// #define USART0_TIMEOUT   350


//#define USART0_TIMEOUT   16
//#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)      
//#define AT91RM9200_DBGU_RETTO_ENABLE		(0x00008000)
//#pragma BSS(".buff_pdp")
  
unsigned char Buffu0[USART0_RX_BUFFER]; //buffer
unsigned char Buff1u0[USART0_RX_BUFFER]; //buffer

//#pragma BSS()


  
void enableRxPdcUsart0()
{


  AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  usart0_ptr->PDC.RPR = (uint_32)&Buffu0[0];
  usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcu0 = 0;

  usart0_ptr->PDC.RNPR = (uint_32)&Buff1u0[0];
  usart0_ptr->PDC.RNCR = USART0_RX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
     usart0_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts ???
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
  
//#ifdef PROG_PRM_PCH_N
#ifdef PROG_BMDN
//#ifndef MAKET_PLATA
//    SetUsart0BaudRate(115200l);
//#else
     SetUsart0BaudRate(38400l);
//#endif    
#else 

#ifdef PROG_PRM_PCH_SPI
//#ifndef MAKET_PLATA
//    SetUsart0BaudRate(115200l);
//#else
     SetUsart0BaudRate(115200l);
//#endif    


    SetUsart0BaudRate(38400l); 
#endif //


#endif



}


void OperateBuffers_usart0(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
 
 unsigned long byte_cnt;
 usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
 byte_cnt = usart0_ptr->PDC.RCR;
 usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcu0)
 {
  if(byte_cnt < USART0_RX_BUFFER)
   {
//    printf("\n\r 1: %d",byte_cnt); 
 //    printEthLongHex(byte_cnt); 
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart0_ptr->PDC.RCR;
    usart0_ptr->PDC.RPR = (uint_32)&Buff1u0[0];
    usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
  usart0_ptr->PDC.RNPR = (uint_32)&Buffu0[0];
    usart0_ptr->PDC.RNCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
    
    flag_pdcu0 = 1;
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ReadDatau0((unsigned char *)&Buffu0[0], (USART0_RX_BUFFER - byte_cnt));
   }
   else
   byte_cnt = 0;
 }
 else
 {
 if(byte_cnt < USART0_RX_BUFFER)
   {
//    printf("\n\r 2: %d",byte_cnt); 
//  printEthLongHex(byte_cnt); 
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart0_ptr->PDC.RCR;
    usart0_ptr->PDC.RPR = (uint_32)&Buffu0[0];
    usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
    usart0_ptr->PDC.RNPR = (uint_32)&Buff1u0[0];
    usart0_ptr->PDC.RNCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;

    flag_pdcu0 = 0;
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ReadDatau0((unsigned char *)&Buff1u0[0], (USART0_RX_BUFFER - byte_cnt));
   }
   else
    byte_cnt = 0;

 }
 
}

#endif // USART0_TRY_PDC_1



//_________________________________________________________________________
#ifdef  USART0_TRY_PDC_1T

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/

//#define USART0_RX_BUFFER 3  
//#define USART0_RX_BUFFER 16  
//#define USART0_TX_BUFFER 1000  
#define USART0_TX_BUFFER 100000  
//#define USART0_RX_BUFFER 700  

//#define USART0_RX_BUFFER 256  
//#define USART0_RX_BUFFER2   (USART0_RX_BUFFER*10)

//#define USART0_TIMEOUT   1
//t#define USART0_TIMEOUT   2
//t1208#define USART0_TIMEOUT   1
// #define USART0_TIMEOUT   350


//#define USART0_TIMEOUT   16
//#define AT91RM9200_DBGU_STTTO_ENABLE		(0x00000800)      
//#define AT91RM9200_DBGU_RETTO_ENABLE		(0x00008000)
//#pragma BSS(".buff_pdp")
  
unsigned char Buffu0t[USART0_TX_BUFFER]; //buffer
unsigned char Buff1u0t[USART0_TX_BUFFER]; //buffer
unsigned long  cntBuffu0t, cntBuff1u0t;
unsigned char *  pBuffu0t;
unsigned char * pBuff1u0t;


//#pragma BSS()


  
void enableTxPdcUsart0()
{


  AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  usart0_ptr->PDC.TPR = (uint_32)&Buffu0t[0];
  usart0_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
 // flag_pdcu0 = 0;
    pBuffu0t = &Buffu0t[0];   //need init!!!!!!
    cntBuffu0t = 0;
    pBuff1u0t = &Buff1u0t[0];   //need init!!!!!!
    cntBuff1u0t = 0;


  usart0_ptr->PDC.TNPR = (uint_32)&Buff1u0t[0];
  usart0_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
   usart0_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
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



extern "C" void ToPdcTu0(unsigned char ch0t)
{

 if(!flag_pdcu0t)
 {
     if(cntBuffu0t < USART0_TX_BUFFER)
     {
      *pBuffu0t++ = ch0t;    //need init!!!!!!
      cntBuffu0t++;
     }
     
 }
 else
 {
    if(cntBuff1u0t < USART0_TX_BUFFER)
     {
     *pBuff1u0t++ = ch0t;   //need init!!!!!!
     cntBuff1u0t++;
     }
 }
 
}



extern "C" void OperateBuffers_usart0t(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart0_ptr;
 usart0_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART0_BASE;
 
 unsigned long byte_cnt;
usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = usart0_ptr->PDC.TCR;
usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 

  if(byte_cnt)  return; //pdc is not finished transmit
  
 if(cntBuffu0t)
 {
//    usart0_ptr->PDC.TPR = (uint_32)&Buffu0t[0];
//    usart0_ptr->PDC.TCR = cntBuffu0t;
    
    pBuffu0t = &Buffu0t[0];   //need init!!!!!!
 //   cntBuffu0t = 0;
    flag_pdcu0t = 1;
    usart0_ptr->PDC.TPR = (uint_32)&Buffu0t[0];
    usart0_ptr->PDC.TCR = cntBuffu0t;
 //    printEthLongHex()
      cntBuffu0t = 0;
    
    return;
 }
 
 if(cntBuff1u0t)
 {
//    usart0_ptr->PDC.TPR = (uint_32)&Buff1u0t[0];
//    usart0_ptr->PDC.TCR = cntBuff1u0t;
    
    pBuff1u0t = &Buff1u0t[0];   //need init!!!!!!
 //   cntBuff1u0t = 0;
    flag_pdcu0t = 0;
    usart0_ptr->PDC.TPR = (uint_32)&Buff1u0t[0];
    usart0_ptr->PDC.TCR = cntBuff1u0t;
    cntBuff1u0t = 0;

    
    return;
 }

 
 
 
  

/*
 if(!flag_pdcu0t)
 {
  if(byte_cnt < USART0_RX_BUFFER)
   {
//    printf("\n\r 1: %d",byte_cnt); 
 //    printEthLongHex(byte_cnt); 
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart0_ptr->PDC.RCR;
    usart0_ptr->PDC.RPR = (uint_32)&Buff1u0[0];
    usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu0 = 1;
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ReadDatau0((unsigned char *)&Buffu0[0], (USART0_RX_BUFFER - byte_cnt));
   }
 }
 else
 {
 if(byte_cnt < USART0_RX_BUFFER)
   {
//    printf("\n\r 2: %d",byte_cnt); 
//  printEthLongHex(byte_cnt); 
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = usart0_ptr->PDC.RCR;
    usart0_ptr->PDC.RPR = (uint_32)&Buffu0[0];
    usart0_ptr->PDC.RCR = USART0_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcu0 = 0;
    usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ReadDatau0((unsigned char *)&Buff1u0[0], (USART0_RX_BUFFER - byte_cnt));
   }
 }
 */
 
}

#endif // USART1_TRY_PDC_1T

//__________________________________________________________________________
#ifdef  USART1_TRY_PDC_1T

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/


#define USART1_TX_BUFFER 100000  

unsigned char Buffu1t[USART1_TX_BUFFER]; //buffer
unsigned char Buff1u1t[USART1_TX_BUFFER]; //buffer
unsigned long  cntBuffu1t, cntBuff1u1t;
unsigned char *  pBuffu1t;
unsigned char * pBuff1u1t;


//#pragma BSS()


  
void enableTxPdcUsart1()
{


  AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
 usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;


  usart1_ptr->PDC.TPR = (uint_32)&Buffu1t[0];
  usart1_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcu1 = 0;
    pBuffu1t = &Buffu1t[0];   //need init!!!!!!
    cntBuffu1t = 0;
    pBuff1u1t = &Buff1u1t[0];   //need init!!!!!!
    cntBuff1u1t = 0;


  usart1_ptr->PDC.TNPR = (uint_32)&Buff1u1t[0];
  usart1_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
   usart1_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
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



extern "C" void ToPdcTu1(unsigned char ch1t)
{

 if(!flag_pdcu1t)
 {
  if(cntBuffu1t < USART1_TX_BUFFER)
     {

     *pBuffu1t++ = ch1t;    //need init!!!!!!
     cntBuffu1t++;
     }
 }
 else
 { 
  if(cntBuff1u1t < USART1_TX_BUFFER)
     {
     *pBuff1u1t++ = ch1t;   //need init!!!!!!
     cntBuff1u1t++;
     }
 }
 
}

extern "C" void StrToPdcTu1(unsigned char dummy, unsigned char *pData)
{
  while(*pData)
  { 
 // printEthLongHex(*pData); 
      
      if(GetTestMode() == 0xC6)
    { 
       // ToPdcTu0(*pData++);
       printfpd(".%02X.", *pData);
    } 
     
    ToPdcTu1(*pData++);
  }
   
}



void OperateBuffers_usart1t(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart1_ptr;
 usart1_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART1_BASE;
 
 unsigned long byte_cnt;
usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = usart1_ptr->PDC.TCR;
usart1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 

  if(byte_cnt)  return; //pdc is not finished transmit
  
 if(cntBuffu1t)
 {
//    usart1_ptr->PDC.TPR = (uint_32)&Buffu1t[0];
//    usart1_ptr->PDC.TCR = cntBuffu1t;
    
    pBuffu1t = &Buffu1t[0];   //need init!!!!!!
//    cntBuffu1t = 0;
    flag_pdcu1t = 1;
    usart1_ptr->PDC.TPR = (uint_32)&Buffu1t[0];
    usart1_ptr->PDC.TCR = cntBuffu1t;    
    cntBuffu1t = 0;
    
    return;
 }
 
 if(cntBuff1u1t)
 {
  //  usart1_ptr->PDC.TPR = (uint_32)&Buff1u1t[0];
  //  usart1_ptr->PDC.TCR = cntBuff1u1t;
    
    pBuff1u1t = &Buff1u1t[0];   //need init!!!!!!
//    cntBuff1u1t = 0;
    flag_pdcu1t = 0;
    usart1_ptr->PDC.TPR = (uint_32)&Buff1u1t[0];
    usart1_ptr->PDC.TCR = cntBuff1u1t;
    cntBuff1u1t = 0;
    return;
 }

}

#endif // USART1_TRY_PDC_1T

//__________________________________________________________________________
#ifdef  USART2_TRY_PDC_1T

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/


#define USART2_TX_BUFFER 10000  

unsigned char Buffu2t[USART2_TX_BUFFER]; //buffer
unsigned char Buff1u2t[USART2_TX_BUFFER]; //buffer
unsigned long  cntBuffu2t, cntBuff1u2t;
unsigned char *  pBuffu2t;
unsigned char * pBuff1u2t;


//#pragma BSS()


  
void enableTxPdcUsart2()
{


  AT91RM9200_USART_REG_STRUCT_PTR         usart2_ptr;
 usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;


  usart2_ptr->PDC.TPR = (uint_32)&Buffu2t[0];
  usart2_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcu2 = 0;
    pBuffu2t = &Buffu2t[0];   //need init!!!!!!
    cntBuffu2t = 0;
    pBuff1u2t = &Buff1u2t[0];   //need init!!!!!!
    cntBuff1u2t = 0;


  usart2_ptr->PDC.TNPR = (uint_32)&Buff1u2t[0];
  usart2_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
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
 //    usart1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
   usart2_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  usart1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
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



extern "C" void ToPdcTu2(unsigned char ch2t)
{

 if(!flag_pdcu2t)
 {
  if(cntBuffu2t < USART2_TX_BUFFER)
     {
 //     printfpd("_%02X",ch2t);
 //      printfpd("_%d",cntBuff1u2t);
     *pBuffu2t++ = ch2t;    //need init!!!!!!
     cntBuffu2t++;
     }
 }
 else
 { 
  if(cntBuff1u2t < USART2_TX_BUFFER)
     {
 //     printfpd("-%02X",ch2t);
  //     printfpd("-%d",cntBuff1u2t);
     *pBuff1u2t++ = ch2t;   //need init!!!!!!
     cntBuff1u2t++;
     }
 }
 
}



void OperateBuffers_usart2t(void)
{
 AT91RM9200_USART_REG_STRUCT_PTR         usart2_ptr;
 usart2_ptr = (AT91RM9200_USART_REG_STRUCT_PTR)AT91RM9200_USART2_BASE;
 unsigned i;
 unsigned long byte_cnt;
usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = usart2_ptr->PDC.TCR;
usart2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
//  printfpd(";%d",byte_cnt);
  if(byte_cnt)  return; //pdc is not finished transmit
  
 if(cntBuffu2t)
 {
 //printf("0");
//  printfpd("+%d",cntBuffu2t);
//    usart1_ptr->PDC.TPR = (uint_32)&Buffu1t[0];
//    usart1_ptr->PDC.TCR = cntBuffu1t;
    
    pBuffu2t = &Buffu2t[0];   //need init!!!!!!
//    cntBuffu1t = 0;
    flag_pdcu2t = 1;
    usart2_ptr->PDC.TPR = (uint_32)&Buffu2t[0];
    usart2_ptr->PDC.TCR = cntBuffu2t; 
 //   for( i = 0; i <  cntBuffu2t; i++){ /* Body */
//    printfpd("-%02X", Buffu2t[i]);
 //  } /* Endbody */
       
//101202    cntBuffu1t = 0;
    cntBuffu2t = 0;
    
    return;
 }
 
 if(cntBuff1u2t)
 {
 //printf("1");
 //   printfpd("=%d",cntBuff1u2t);
  //  usart1_ptr->PDC.TPR = (uint_32)&Buff1u1t[0];
  //  usart1_ptr->PDC.TCR = cntBuff1u1t;
    
    pBuff1u2t = &Buff1u2t[0];   //need init!!!!!!
//    cntBuff1u1t = 0;
    flag_pdcu2t = 0;
    usart2_ptr->PDC.TPR = (uint_32)&Buff1u2t[0];
    usart2_ptr->PDC.TCR = cntBuff1u2t;
//    for( i = 0; i <  cntBuff1u2t; i++)    printfpd("-%02X", Buff1u2t[i]);
    
    cntBuff1u2t = 0;
    return;
 }

}

#endif // USART1_TRY_PDC_2T



//__________________________________________________________________________
#ifdef PROG_PRM_PCH_DEM
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_load_xilinx4
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx
*
*END*----------------------------------------------------------------------*/

void m_load_xilinx4 (char pg , char div)
{
//pg = 1 - load xil1 to 128qam
//pg = 2 - load xil1 to not128qam
//
//printfp("\n\r lxil4");
//printfpd(" %d", pg);

  unsigned int cnt;
  char* CurrentDataPointer;
 unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  volatile unsigned int status;
  unsigned long XilSizeToDownload;
  
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//  pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
  
  AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  imr =  aic_ptr->IMR;
  aic_ptr->IDCR = 0xFFFFFFFFl;

  switch(pg)
   
   { 
    case 1: read_dataflash ((unsigned int)XilDataAddressD,  (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD;      break;
    case 2: read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD2;   break;
    case 3: read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD3;   break;
#ifdef PROG_PRM_PCH_DEM_XIL
    case 4: read_dataflash ((unsigned int)XilDataAddressD4, (unsigned int)XilSizeToDownloadD4, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD4;   break;
           
#endif //PROG_PRM_PCH_DEM_XIL
            
    default: read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD;   break;
  } 
  
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC0_ENABLE;
  //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
  if(!div)
   {div++;}
  AT91F_SSC_Configure (ssc0_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					(XIL_LOAD_FREQ  / div),
			    	0,
					0, 
               4,
               0x7 );
               
     pio_ptr->CODR = 1;
     
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

  delay_mcs(4000l);      //delay to signal "prog"  , < 500 mcs
     /* 110419
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & 0x10))
      { 
  //    printf("\n\r cnt0 = %d",cnt);
      break;
       }
   } 
     */
  
 //  delay_mcs(2000l); //t
    pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
   delay_mcs(4000l);  //t
    /*
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //line init hier one
     if(status & 0x10)
      { 
   //   printf("\n\r cnt1 = %d",cnt);
         break;
   } 
    
     
   }
   */
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
   ssc0_ptr->TCMR = 4; //try before
 //  delay_mcs(400l); 
                     
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last

   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc0_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc0_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
   }
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
 for(cnt = 0l; cnt < 10000000l; cnt++)
 { 
  status = pio_ptr->PDSR;
  if(status & 0x20) //line done
  {
  //   printf("\n\r after load : cnt = %d",cnt);
   break;
   }
 } 
    ssc0_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)
 }
 
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_load_xilinx5
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx
*    USE NON -STANDARD IO PINS FOR LINES PROG AND DONE
*END*----------------------------------------------------------------------*/

void m_load_xilinx5 (char pg , char div)
{
//pg = 3 - load xil2,3    to file3
//printfp("\n\rlxil5");
//printfpd(" %d", pg);

  unsigned int cnt;
  char* CurrentDataPointer;
 unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  volatile unsigned int status;
  unsigned long XilSizeToDownload;
  
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

//  pio_ptr->MDER = 6;    //enable multidrive for pin prog

// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
//not used!!! _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
  
  AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  imr =  aic_ptr->IMR;
  aic_ptr->IDCR = 0xFFFFFFFFl;

  switch(pg)
   
   { 
    case 1: read_dataflash ((unsigned int)XilDataAddressD,  (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD;      break;
    case 2: read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD2;   break;
    case 3: read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD3;   break;
    default: read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
            XilSizeToDownload =  XilSizeToDownloadD;   break;
  } 
  
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC0_ENABLE;
  //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
  if(!div)
   {div++;}
  AT91F_SSC_Configure (ssc0_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					(XIL_LOAD_FREQ  / div),
			    	0,
					0, 
               4,
               0x7 );
               
//     pio_ptr->CODR = 1;

        pio_ptr->CODR = MASK_BIT_6; //pb6
     
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

  delay_mcs(500l);      //delay to signal "prog"  , < 500 mcs
  
  // for(cnt = 0; cnt < 500000l; cnt++)
  // {
  //   status = pio_ptr->PDSR; //wait line init hier zero
  //   if(!(status & 0x10))
   //   { 
  //    printf("\n\r cnt0 = %d",cnt);
//not used!!!      break;
   //    }
 //  } 

  
 //  delay_mcs(2000l); //t
 //   pio_ptr->SODR = 1;
    pio_ptr->SODR = MASK_BIT_6;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
   delay_mcs(1000l);  //t
  // for(cnt = 0; cnt < 500000l; cnt++)    //need check delay
  // {
 //    status = pio_ptr->PDSR; //line init hier one
 //    if(status & 0x10)
  //    { 
   //   printf("\n\r cnt1 = %d",cnt);
 //not used!!!        break;
 //  } 
    
     
  // }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
   ssc0_ptr->TCMR = 4; //try before
 //  delay_mcs(400l); 
                     
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last

   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc0_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc0_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
   }
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
 for(cnt = 0l; cnt < 10000000l; cnt++)
 { 
  status = pio_ptr->PDSR;
  if(status & MASK_BIT_4) //line done
  {
  //   printf("\n\r after load : cnt = %d",cnt);
   break;
   }
 } 
    ssc0_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)
 }
 




#endif   




#ifdef PROG_PRM_PCH_SPI

#define AT91RM9200_SSC_IMR_RXRDY (0x10)

void SetSSC2ToSelfClocks()
{
  AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;

 AT91F_SSC_Configure (SSC2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
		  //t	    	0x202,//rcmr - source - rk
        	// t   	0x202,//rcmr - source - rk
         //    	0x402,// try failing edge rcmr - source - rk
             	0x420,//self ! try failing edge rcmr - source - rk
		  //t110914			0xF07,  //rfmr - size for one cyckle pdc + off loop!
       //t 			0xf1F,  //rfmr - size for one cyckle pdc + off loop! //110914
      //110926  			0xf07,  //rfmr - size for one cyckle pdc + off loop! //110915
        	 //		0x01000f07,  //negative edge    ?
          		0x00000f07,  //no negative edge
          //t1     4,//   0x200, //internal clock source //0x202,// tcmr// 4,
//110921               0x204,//   0x200, //internal clock source //0x202,// tcmr// 4,
       //        0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //     0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //better    0x201,// ,
 //t110921          0x221,// ,
 //          0x421,// ,   //t110922 seldom!
 //          0x422,// ,   //seldom
  //           0x222,// , ok continuosly
   0x220,// self!, 

              
//aftr connecting rf-tf need program 0x27              
       //110710        0x00300027 //  drive tf low// 0x7+1 bits   //rfmrto test clock 
        //110712       0x00300F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock   
        //110923       0x00000F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
      //         0x00000627 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
       //110926        0x00000f3f // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
               0x00000827 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
                 	);	// End of 

   
   
}

void SetSSC2ToExtClocks()
{
   AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;

 AT91F_SSC_Configure (SSC2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
		  //t	    	0x202,//rcmr - source - rk
        	// t   	0x202,//rcmr - source - rk
         //    	0x402,// try failing edge rcmr - source - rk
             	0x422,// try failing edge rcmr - source - rk
		  //t110914			0xF07,  //rfmr - size for one cyckle pdc + off loop!
       //t 			0xf1F,  //rfmr - size for one cyckle pdc + off loop! //110914
      //110926  			0xf07,  //rfmr - size for one cyckle pdc + off loop! //110915
        	 //		0x01000f07,  //negative edge    ?
          		0x00000f07,  //no negative edge
          //t1     4,//   0x200, //internal clock source //0x202,// tcmr// 4,
//110921               0x204,//   0x200, //internal clock source //0x202,// tcmr// 4,
       //        0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //     0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //better    0x201,// ,
 //t110921          0x221,// ,
 //          0x421,// ,   //t110922 seldom!
 //          0x422,// ,   //seldom
  //           0x222,// , ok continuosly
   0x221,// , 

              
//aftr connecting rf-tf need program 0x27              
       //110710        0x00300027 //  drive tf low// 0x7+1 bits   //rfmrto test clock 
        //110712       0x00300F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock   
        //110923       0x00000F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
      //         0x00000627 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
       //110926        0x00000f3f // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
               0x00000827 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
                 	);	// End of 

   
   
}




void init_test_ssc2(void)
{

   printfp("init_test_ssc2");
//1 init transmit to self clocks
  AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
#ifndef TEST_TRANSMIT_FROM_SSC1

 AT91F_SSC_Configure (SSC2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
			    	0x201,//rcmr
					0xF27,  //rfmr - size for one cyckle pdc + set loop!
               4,//   0x200, //internal clock source //0x202,// tcmr// 4,
               0x00300027 // + drive tf low// 0x7+1 bits   //rfmrto test clock 
         	);	// End of 
#else

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 29, AT91RM9200_PIO_PERIPHERAL_A, 0); // 110729
  
 AT91F_SSC_Configure (SSC2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
		  //t	    	0x202,//rcmr - source - rk
        	// t   	0x202,//rcmr - source - rk
         //    	0x402,// try failing edge rcmr - source - rk
             	0x422,// try failing edge rcmr - source - rk
		  //t110914			0xF07,  //rfmr - size for one cyckle pdc + off loop!
       //t 			0xf1F,  //rfmr - size for one cyckle pdc + off loop! //110914
      //110926  			0xf07,  //rfmr - size for one cyckle pdc + off loop! //110915
        	 //		0x01000f07,  //negative edge    ?
          		0x00000f07,  //no negative edge
          //t1     4,//   0x200, //internal clock source //0x202,// tcmr// 4,
//110921               0x204,//   0x200, //internal clock source //0x202,// tcmr// 4,
       //        0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //     0x422,//110921 failing edge, invert, tk pin , input //   0x200, //internal clock source //0x202,// tcmr// 4,
          //better    0x201,// ,
 //t110921          0x221,// ,
 //          0x421,// ,   //t110922 seldom!
 //          0x422,// ,   //seldom
  //           0x222,// , ok continuosly
   0x221,// , 

              
//aftr connecting rf-tf need program 0x27              
       //110710        0x00300027 //  drive tf low// 0x7+1 bits   //rfmrto test clock 
        //110712       0x00300F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock   
               0x00000F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
      //         0x00000627 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
       //110926        0x00000f3f // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
       //111223        0x00000827 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
                 	);	// End of 


#endif            
            
            
            
            
            
 SSC2_ptr->IER =  AT91RM9200_SSC_IMR_RXRDY; //AT91RM9200_SSC_IMR_ENDRX; //t
 AT91F_SSC_EnableTx (SSC2_ptr);     //t        
 AT91F_SSC_EnableRx (SSC2_ptr);     //t     
//2 make tx enable
//3 make loop - transmit - receive
//4 start transmit immediatly at some write
//5 fsps : 3 : tf drive low during data transfer   
}

#define PERIOD_SSC2_SEND (500)
//t #define PERIOD_SSC1_SEND (1)

//#define PERIOD_SSC1_SEND (5)
//#define PERIOD_SSC1_SEND (200)

//#define PERIOD_SSC1_SEND (50)
//120203 #define PERIOD_SSC1_SEND (5000)
 #define PERIOD_SSC1_SEND (10)

void test_send_data_ssc2(void)
{
unsigned char ret;
unsigned long reg;

static unsigned char send_char = 0;
static unsigned long timekeep;

AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);

if(timekeep > time1) timekeep = time1;
/*
if((time1 - timekeep) > (PERIOD_SSC2_SEND >> 1)) 
{
 // SetPB19();

}
 */
if((time1 - timekeep) > PERIOD_SSC2_SEND) 
{

//t AT91F_SSC_EnableTx (SSC2_ptr);     //t        
//t AT91F_SSC_EnableRx (SSC2_ptr);     //t        
 
  printfp("\n\r...send ");
  
//   reg = SSC2_ptr->PDC.PTSR;
 //    printfpd(" %X", reg);
 
 //  reg = SSC2_ptr->SR;
 //    printfp("SR:");
 //    printfpd("%X", reg);   //hier view as tx and rx are disabled
 
// printfp(" cnt:");
// printfpd("%ld", ssc2_int_counter);
     
      
// SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
// reg  = SSC2_ptr->PDC.TCR;
// SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
//      printfpd("> %X", reg);
//t  SSC2_ptr->IER =  0xff; //if comment hier -loss    
       
 //reg  = SSC2_ptr->IMR;      
 // printfp("IMR :");
 // printfpd(" %X", reg);
  
//______________________________________  
//   ret = OperateBuffers_SSC2t();  
//   printfpd(" %d", ret);
//______________________________________ 





timekeep = time1;
 // SetPB19();
// MClearPB19();
  //    printfp(" Clear :");
    
for(unsigned i = 0; i < 16; i++)
{
 send_char++;
 ToPdcTssc2(send_char);
} 
 
//send_char++;
 //ToPdcTssc2(send_char);
 
//?? need enable transmit data pin and enable olwais
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);
  
 // ret = OperateBuffers_SSC2t(); 
 //  printfpd(" %d", ret);
   
//110724   OperateBuffers_SSC2(); 
   
   ret = OperateBuffers_SSC2t();  
 //  printfpd(" %d", ret);

//?? need make this later? why?  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0);
//?? need disable transmit data pin pdc or pin to can have "star"   
}
}

void disable_txd_pin_ssc2()  //call this function after send all after check counters transmit pdc
{


 if(OperateBuffers_SSC2t())
 {  
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0); 
  return; 
 } 
}


void init_exchange(void)
{
init_ssc2();
enableRxPdcSSC2();
enableTxPdcSSC2();
//110713 to use irq0 enable_ints_ssc2();
}

void SetLineDataSSC2ToZero()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->CODR = 1<<14; 
}

void SetLineDataSS2ToOne()
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
  pio_ptr->SODR = 1<<14; 
}

void SetLineDataSSC2Off()
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0); 
}


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


void SetLineDataSSC2ToSSC2Data()  //if def value - one to all ok
{
  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);  
}


void AT91F_SSC2_Handler(void)
{

my_int_disable_SSC2();




 //unsigned long reg;
 //ssc2_int_counter++;
//AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 
 
   if(current_command_state == WAITING_COMMAND)
   {
 //      current_command_counter = 0;
 //      current_command_state = RECEIVE_COMMAND;
   }
 

  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  
// FOR TEST ONLY!!!!
  //set line alarm to one         //????? line alarm - common or not
 // pio_ptr->CODR = 1<<18; //set line alarm to one
 // pio_ptr->SODR = 1<<19;
 //  SetLineDataSS2ToOne(); //temporary
//   }

// SSC2_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
 
//110724 printfp("AT91F_SSC2_Handler");

//   AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
 //	status = pSSC1->SSC_SR;
//   	status = ssc0_ptr->SSC_SR;
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words

 /* 110624
 
 SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 reg  = SSC2_ptr->PDC.TCR;
 SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
      printfpd("H>%X", reg);
      
 */     
 // SSC2_ptr->IER =  0xff; //if comment hier -loss    
  
  if (OperateBuffers_SSC2()) //my addr
  { /* Body */
 //  pio_ptr->CODR = 1<<19;
 //110923  SetLineDataSS2ToZero();
//  printfp("+");
  } /* Endbody */
 //moved   ParseCommandsSSC2();
   
   
   
//FOR TEST ONLY   
 // pio_ptr->SODR = 1<<18;
  my_int_enable_SSC2();
}

void AT91F_SSC2_IRQ0_Handler(void)
{

//current_command_counter = 0;   //110714 for this interrupt can set hier   to start

//my_int_disable_SSC2();
 //unsigned long reg;
 //ssc2_int_counter++;
//AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 
flag_receive_spi = 1;
 
// SetLineAlarmOff();
 
  
   if(current_command_state == WAITING_COMMAND)
   {
   //      SetLineAlarmOff();
  //110923       SetLineDataSSC2Off();
  //       current_command_counter = 0;
 //      current_command_state = RECEIVE_COMMAND;
   }
     
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  
// FOR TEST ONLY!!!!
  //set line alarm to one         //????? line alarm - common or not
 // pio_ptr->CODR = 1<<18; //test pin 
 // pio_ptr->SODR = 1<<19; //test pin
 //  SetLineDataSS2ToOne(); //temporary
//   }

// SSC2_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
 
//110724 printfp("AT91F_SSC2_Handler");

//   AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
 //	status = pSSC1->SSC_SR;
//   	status = ssc0_ptr->SSC_SR;
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words

 /* 110624
 
 SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 reg  = SSC2_ptr->PDC.TCR;
 SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
      printfpd("H>%X", reg);
      
 */     
 // SSC2_ptr->IER =  0xff; //if comment hier -loss  
//#ifdef TEST_PRINT_SPI    
//  printfp("\n\ri");
//#endif  
  if (OperateBuffers_SSC2()) //my addr
  { /* Body */
 //  pio_ptr->CODR = 1<<19;  // test pin
 //110923  SetLineDataSS2ToZero();
 //111222  SetLineAlarmToOne();   //before run or not run command
//  printfp("+");
  } /* Endbody */
 //moved   ParseCommandsSSC2();
   
   
   
//FOR TEST ONLY   
 // pio_ptr->SODR = 1<<18;  //test pin
//  my_int_enable_SSC2();
}



void enable_ints_ssc2(void)
{
//AT91RM9200_SSC_REG_STRUCT_PTR ssc2_ptr;
AT91RM9200_AIC_REG_STRUCT_PTR pAic;

  
// ssc2_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
  pAic =   (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;
  
  
  // ssc2_ptr->IER =  AT91RM9200_SSC_IMR_ENDRX;
//   ssc2_ptr->IER =  0xff; //test

   
//need load imr - to end of rx
 _int_install_isr(AT91RM9200_SSC2_VECTOR,
      (void (_CODE_PTR_)(pointer))AT91F_SSC2_Handler, NULL); 
 
  _at91rm9200_int_enable(AT91RM9200_SSC2_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
//    					      AT91RM9200_AIC_SMR_PRIO_MIN);
                           AT91RM9200_AIC_SMR_PRIO_MAX);

	// Enable SSC interrupt in AIC
 //	AT91F_AIC_EnableIt((AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE, AT91RM9200_SSC2_PID);

//AT91RM9200_AIC_REG_STRUCT_PTR pAic,      // \arg pointer to the AIC registers
 //	unsigned int irq_id ) // \arg interrupt number to initialize
//{
    //* Enable the interrupt on the interrupt controller
    pAic->IECR = 0x1 << AT91RM9200_SSC2_PID ;
  //   ssc2_ptr->IER =   AT91RM9200_SSC_IMR_ENDRX; //test

}

//#define SSC2_FREQ (5000000)

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : init_channel
* Returned Value   : none
* Comments         :
*    This function init ssc2 for spi
*
*END*----------------------------------------------------------------------*/

void init_ssc2 (void)
{
 // unsigned int cnt;
//  char* CurrentDataPointer;
// unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc2_ptr;    //0 -> 1
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
   unsigned int XilSizeToDownload    = XilSizeToDownloadD; //temporary;
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
 
 //  volatile unsigned int status;
   
     pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 //    pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_A, 0); //tf2   //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_A, 0);  //tk2   //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0); //td2    //data
//110712 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0); //td2    //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_A, 0); //rd2     //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_A, 0);  //rk2   //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_A, 0);  //rf2  //tf2   //line done

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for line alarm  //rf2  //tf2   //line done

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for some tests
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for some tests
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for some tests


//  pio_ptr->SODR = 1<<22; //set line alarm to one
 //110923	SetLineDataSSC2Off();  //for many devices systems	
 // 	SetLineAlarmOff();

 
 
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
//not need  imr =  aic_ptr->IMR;
//not need      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
//110621  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
  /*
 if(pg > 1)
 { 
   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
  } 
  if(pg > 2)
 { 
   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
  } 
   */
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc2_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC2_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset ssc2  
   ssc2_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc2_ptr->PDC));
   
 // if(!div)
 //  {div++;}
   
  AT91F_SSC_Configure (ssc2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
			    	0x202,       //rcmr
					0x7, //rfmr - size for one cyckle pdc
              0x201,// tcmr// 4,
              0x27   //tfmr     default data line level is one
         	);	// End of 
            
 ssc2_ptr->IER =  AT91RM9200_SSC_IMR_RXRDY; //AT91RM9200_SSC_IMR_ENDRX; //test            
            
 AT91F_SSC_EnableTx (ssc2_ptr);     //t        
 AT91F_SSC_EnableRx (ssc2_ptr);     //t        
             /*
             unsigned int clock_rx,    // \arg Receiver Clock Parameters   rcmr
             unsigned int mode_rx,     // \arg mode Register to be programmed 0
             unsigned int clock_tx,    // \arg Transmitter Clock Parameters  0
             unsigned int mode_tx)            
               */
            
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
/* t       
 //_____________________________________________________________________________________________ 
        	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
        //   	 (char *)XilAddressToDownload, 				// pointer to next data
              (char *)TFTP_BUFFER_ADDRESS,
          //       (char*)&Test, //t
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1)); //t
  //_________________________new              
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1));
 //________________________________________________________
t  */
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
    
 //110620   pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

 // delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
 /* 110620 
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & 0x10))
      { 
  //    printf("\n\r cnt0 = %d",cnt);
      break;
       }
   } 
   */
  
 //  delay_mcs(2000l); //t
//110620     pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
//110620     status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
//   delay_mcs(400l);  //t
  /* 110620
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //line init hier one
     if(status & 0x10)
      { 
   //   printf("\n\r cnt1 = %d",cnt);
         break;
   } 
    
     
   }
   */
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
 //110620  ssc2_ptr->TCMR = 4; //try before
 //  delay_mcs(400l); 
//#ifdef PROG_BMD2   
     /*
   delay_mcs(400l); 
      delay_mcs(400l); 
         delay_mcs(400l); 
            delay_mcs(400l); 
               delay_mcs(400l); 
                  delay_mcs(400l); 
                     delay_mcs(400l);
                     */
//#endif // PROG_BMD2                         
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last
/*t1219
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
  (XilSizeToDownload >> 1),
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)),
  (XilSizeToDownload >> 1) );
      */ //t1219
   /* 110621   
   AT91F_SSC_SendFrame(   //t
  ssc2_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc2_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc2_ptr);  //new  hier before clocks to have time to start
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc2_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc2_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc2_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
   }
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
 for(cnt = 0l; cnt < 10000000l; cnt++)
 { 
  status = pio_ptr->PDSR;
  if(status & 0x20) //line done
  {
  //   printf("\n\r after load : cnt = %d",cnt);
   break;
   }
 } 
    ssc2_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc2_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc2_ptr->PDC));
   
   */
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
 //110620 aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)
  
//SSC2Buff_Init();  
    }
  /*  
    
void Irq1_ssc2_handler(void)
{
 OperateBuffers_SSC2();
}
  */
//_______________________________________________pdc usart to ssc
//#ifdef  USART1_TRY_PDC

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcSSC2
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for receive ssc2
*
*END*----------------------------------------------------------------------*/

#define SSC2_RX_BUFFER 200  
  
unsigned char Buffssc2[SSC2_RX_BUFFER]; //buffer
unsigned char Buff1ssc2[SSC2_RX_BUFFER]; //buffer
unsigned char flag_pdcssc2;


void enableRxPdcSSC2()
{
  AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  SSC2_ptr->PDC.RPR = (uint_32)&Buffssc2[0];
  SSC2_ptr->PDC.RCR = SSC2_RX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcssc2 = 0;

  SSC2_ptr->PDC.RNPR = (uint_32)&Buff1ssc2[0];
  SSC2_ptr->PDC.RNCR = SSC2_RX_BUFFER;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
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
 //    SSC2_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
 //110620  SSC2_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SSC2_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//110620     SSC2_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
 /* 
#ifdef PROG_PRM_PCH_N
    SetSSC2BaudRate(921600l);
#else 
    SetSSC2BaudRate(38400l); 
#endif 
*/


}

/*
extern "C" void RunCommandSSC2(void)
{

     if(embMsgSSC2.ParseS())
      { 
       SetLineAlarmToOne();
      } 
      else
      { 
       SetLineAlarmToZero();
      } 



 //  if(GetTestMode() != 0x50)
//   {
  //  SetLineDataSS2ToSSC2Data();
      _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);

     for(unsigned i = 0; i< 16; i++)
     { 
     
       ToPdcTssc2(i);
   //    printfpd("-%02X", i);
     }
     OperateBuffers_SSC2t();
 //  }

}

*/

extern "C" void SetRunCommandSSC2(void)
{
NeedRunCommand = 1;


}

extern "C" void SetPB19(void)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  
// FOR TEST ONLY!!!!
  //set line alarm to one         //????? line alarm - common or not
 // pio_ptr->SODR = 1<<19; //set line alarm to one
}

void MClearPB19(void)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  
// FOR TEST ONLY!!!!
  //set line alarm to one         //????? line alarm - common or not
//  pio_ptr->CODR = 1<<19; //set line alarm to one
}

extern "C" unsigned char CheckSSC2CRC()
{

#ifdef PRINT_DEBUG_CRC
    embMsgSSC2N_ChkCRCN(0);
     return 1;
#else     
     return embMsgSSC2N_ChkCRCN(0);
#endif

 // return 1;  
//#else  
//return  embMsgSSC2N_ChkCRCN(0); //need set addr pos
//#endif
   
}

#define NO_COMMAND_SSC2 (0)  // use from zero 0 ...q-1 : commands q - no commands
 extern "C" void wd_reset(void);

extern "C" unsigned char OperateCommand(unsigned char * pData)
{

// AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
 // pio_ptr->SODR = 1<<14; 
unsigned  char ret;
 ret = 0; 
 
 
 

unsigned char rch;// = * pData; 


if(!Ready_Reseive) return 0; //not ready to receive next command

switch(* pData)
{
case 0x55:       current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;
                 current_command_length = 10; //for start
                 return;
case 0xA5:       current_command_state = WAITING_COMMAND;
                 current_command_counter = 0;
                 current_command_length = 10; //for start

                 return;   //added
case 0xAA:    embMsgSSC2N_Init();
              current_command_state = RECEIVE_COMMAND;
              current_command_data_counter = 0;
              current_command_counter = 1;
              current_command_length = 10; //for start

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

/* 
#ifdef TEST_SPI_CHANNEL
static unsigned char tch;


 if(tch != * pData )
 { 
 err++;
 printfp("\n\r err:");
 printfpd("%ld", err);
 printfp("noerr:");
 printfpd("%ld", noerr);
 printfp(" wait:");
 printfpd("%02X", tch);
 printfp(" have:");
 printfpd("%02X", * pData);
 } 
 else
 { 
  noerr++;
}
 tch = * pData + 1;
 
 return;
#endif
      */
// if(current_command_state == RECEIVE_COMMAND)
// if(current_command_state != WAITING_COMMAND)
// { 
  current_command_counter++;
 //}
 
// printfpd("<c:%d>", current_command_counter);
// printfpd("<s:%d>", current_command_state);
#ifdef TEST_PRINT_SPI 
 printfpd(" ,%X ", rch); //110914
  printfpd("<c:%d>", current_command_counter);

#endif

//if(current_command_counter == START_POS)
//  {
//___________________________hier need make 0x5a converting


//___________________________
embMsgSSC2N_Add(rch);
   /*  120713
  // if(!((rch > (unsigned char)0xAA) || (rch < (unsigned char)0xAA)))
   if(rch == (unsigned char)0xAA)
      { 
     embMsgSSC2N_Init();
     current_command_state = RECEIVE_COMMAND;
     current_command_data_counter = 0;
     current_command_counter = 1;

#ifdef TEST_PRINT_SPI     
     printfp("\n\r> start ");
#endif      
//     printfp("\n\r>");
      }
//  }      
 else 
     */
 
 if((current_command_counter == LENGTH_POS) &&  ( current_command_state == RUN_COMMAND))
// if(current_command_counter == LENGTH_POS) //t
  {
     current_command_length = rch+4;
#ifdef TEST_PRINT_SPI     
      printfpd("\n\r>data len rch+4: %d",current_command_length);
//       printfpd(" %d", *pData);
#endif
  }
 else 
 if((current_command_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
  //       printfpd("\n\r%02X ", (*pData & (~((unsigned char)MASK_REQUEST))));
  //   if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
#ifndef MAKET_PLATA
#ifndef PROG_PRM_PCH_SPI_XIL   
     if((((unsigned char)rch) == (MY_ADDRESS + (unsigned char)MASK_REQUEST))
#else 
     if((((unsigned char)rch) == (MY_ADDRESS_XIL + (unsigned char)MASK_REQUEST))
#endif  
#else
     if( 1
#endif   
     
     ||  (rch == (unsigned char)BRD_ADDRESS))
   //   if(1)
     {
 //    printfp("\n\r> addr ok ");
      current_command_state = RUN_COMMAND;
      
//#ifdef TEST_PRINT_SPI 
//       printfp("\n\rcurrent_command_state run ");
//                printfp("CommandLength:");
//      printfpd("%02X", CommandDataLength[current_command_type]);

//#endif      
//temp111115       SetLineDataOffToZero();
    //   pio_ptr->SODR = 1<<18;
   //    pio_ptr->CODR = 1<<18;
  //    MClearPB19();
 //   printfp("\n\r>");
  //    printfp(" Clear :");
  //    printfpd("% 02X", *pData);
      
//      pio_ptr->CODR = 1<<19; 
     
  //     SetState(RUN_Command);
  //     temporary commented     SetLineDataSS2ToZero();
       ret = 1;
            } 
        else
        {
        
//#ifdef TEST_PRINT_SPI 
//       printfp("\n\rcurrent_command_state waiting");

//#endif            
  //      printfp("\n\r> addr bad ");
    //    printfpd("%02X", (*pData ));
    //     printfpd(" %d ", current_command_counter);
  //     printfpd(" %d ", current_command_state);
  
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
 //  return 0;
  } 
  else if((current_command_counter == COMMAND_POS) &&  (current_command_state == RUN_COMMAND))
  {
 //    if(*pData <= COMMANDS_QUANTITY)
     if(rch <= COMMANDS_QUANTITY)
     {
 //120721     current_command_type =  *pData;
      current_command_type =  rch;   //120721
      
 //     printfp("\n\r type :");
   //   printfpd(" %d ", current_command_type);
  //    printfp(" CommandLength :");
  //    printfpd(" %d", CommandLength[current_command_type]);
 //     printfp(" CommandDataLength :");
 //     printfpd(" %d", CommandDataLength[current_command_type]);



 //     return 0;
      }
      else{ /* Body */
          current_command_state = WAITING_COMMAND;

      current_command_type = NO_COMMAND_SSC2;
  //             printfp(" type :");
   //   printfpd(" %d", current_command_type);
   //                printfp(" CommandLength :");
   //  printfpd(" %d", CommandLength[current_command_type]);

      
   } /* Endbody */
  } //counter
    else      if (current_command_state == RUN_COMMAND)

//t    if((current_command_counter == CommandDataLength[current_command_type]))
//    &&  (current_command_state == RUN_COMMAND))
  {
  
//#ifdef TEST_PRINT_SPI   
 //   printfpd("cct %d ", current_command_type);
//#endif
//131224   if((current_command_counter == CommandDataLength[current_command_type]))  //hier do not work
 if((current_command_counter ==  current_command_length))//131224
//  if (current_command_state == RUN_COMMAND)
  {

//#ifdef TEST_PRINT_SPI  
//    printfp("\n\rcurrent_command_state ");
//    printfpd("%d ", current_command_state);


//#endif
 //  current_command_crc =  *pData;
   current_command_crc =  rch;   //120720

   if(CheckSSC2CRC())
   {
   Ready_Reseive  = 0; //do not receive commands while parse this!!!
   
#ifdef  IncEmbSerialSPI  
      SetLineAlarmToOneX();
       SetLineDataSPIToZeroX();
#else   
#ifndef BACK_TO_SSC   
    SetLineDataOffToZero(); //setted  line data to zero
    SetLineAlarmToOne(); //temporary - no alarms
#else
  //  SetLineDataSSC2ToSSC2Data();
  //  SetLineDataSS2ToSSC2Data()
    SetLineDataSSC2ToZero();
    SetLineAlarmToOne();
#endif    
#endif    
    
#ifndef	 PROG_PRM_PCH_SPI_XIL_ETH     
    SetRunCommandSSC2(); //ok //hier only set to run - it is interrupt
#else   
    wd_reset(); 
    RunCommandSSC2(); //if many commands need momentally run
#endif
    
   // SetPB19();
#ifdef TEST_PRINT_SPI   
 //   printfpd(" %d ", current_command_counter);
    printfp("(CRC Ok)");    
#endif    


#ifdef PRINT_DEBUG_CRC
		//   crc_glob = crc;
		//   body_glob = body[i];
	   	 	printfpd("calc crc: %02X", crc_glob);
	   	 	printfpd("<->packet crc:  %02X\n\r",  body_glob);
#endif
   }
   else
   {
       current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
 //  printfpd(" %d ", current_command_counter);
    printfp("(CRC Bad)");
#endif   

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
    
   }  //crc
       
    //  printfpd("%02X", *pData);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{ /* Body */
    
 //     current_command_state = WAITING_COMMAND;

  // } /* Endbody */
    
  //  current_command_counter = 0; //
   // return 0;
 } //counter
//t 120713  }
//  else if(current_command_counter >= CommandLength[current_command_type])//?? hier use and zero input deta when dewise get answer and after answer get to waiting
// else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  else if(current_command_counter >= (current_command_length+1))//131224?? hier use and zero input deta when dewise get answer and after answer get to waiting 
  {
  //  RunCommandSSC2(); //hier only set to run - it is interrupt
   // SetPB19();
//#ifdef TEST_PRINT_SPI   
//        printfp("  >= CommandLength; current_command_type :");
//      printfpd("%02X", current_command_type);
//        printfpd("cnt1:%d ", current_command_counter);

//#endif      
   //  pio_ptr->SODR = 1<<19; 
  //    printfp("Cdl");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{/* Body */
    
      current_command_state = WAITING_COMMAND;

  // } /* Endbody */
    
    current_command_counter = 0;
 //   return 0;
  }
  
//  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < current_command_length) //131224
            &&  (current_command_state == RUN_COMMAND))
  
//  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type]))
   { 
//   printfp("\n\r adding data to buffer");

//#ifdef TEST_PRINT_SPI      
//   printfpd("cnt:%d ", current_command_counter);
//  printfpd("cdl:%d ", CommandDataLength[current_command_type]);
//  printfpd("ccs:%d ", current_command_state);
//      printfpd(" d: %d", *pData);

   
//#endif    
 //   printfpd("\n\rdc: %d", current_command_data_counter);
 //   printfpd(" d: %d", *pData);

  //  current_command_data[current_command_data_counter++] = *pData;
    current_command_data[current_command_data_counter++] = rch;
//111025!!!!    ToPdcTspi(*pData);
  }
 } //120713

 return ret; 
}

extern "C" unsigned char OperateCommandPolled(unsigned char * pData)
{

// AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
 // pio_ptr->SODR = 1<<14; 
unsigned  char ret;
 ret = 0; 

unsigned char rch = * pData; 
/* 
#ifdef TEST_SPI_CHANNEL
static unsigned char tch;


 if(tch != * pData )
 { 
 err++;
 printfp("\n\r err:");
 printfpd("%ld", err);
 printfp("noerr:");
 printfpd("%ld", noerr);
 printfp(" wait:");
 printfpd("%02X", tch);
 printfp(" have:");
 printfpd("%02X", * pData);
 } 
 else
 { 
  noerr++;
}
 tch = * pData + 1;
 
 return;
#endif
      */
// if(current_command_state == RECEIVE_COMMAND)
// if(current_command_state != WAITING_COMMAND)
// { 
  current_command_counter++;
 //}
 
// printfpd("<c:%d>", current_command_counter);
// printfpd("<s:%d>", current_command_state);
//#ifdef TEST_PRINT_SSC2 
//111102 printfpd(" ,%X ", rch); //110914
//#endif

//if(current_command_counter == START_POS)
//  {



  // if(!((rch > (unsigned char)0xAA) || (rch < (unsigned char)0xAA)))
   if(rch == (unsigned char)0xAA)
      { 
     embMsgSSC2N_Init();
     current_command_state = RECEIVE_COMMAND;
     current_command_data_counter = 0;
     current_command_counter = 1;
     
  //    printfp("\n\r> start ");
  //    printfp("\n\r>");
      }
//  }      
 else 
 if((current_command_counter == LENGTH_POS) &&  ( current_command_state == RECEIVE_COMMAND))
  {
     current_command_length = rch;
 //     printfp("\n\r> len: ");
//       printfpd(" %d", *pData);

  }
 else 
 if((current_command_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
  //       printfpd("\n\r%02X ", (*pData & (~((unsigned char)MASK_REQUEST))));
  //   if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
#ifndef PROG_PRM_PCH_SPI_XIL   
     if((((unsigned char)rch) == (MY_ADDRESS + (unsigned char)MASK_REQUEST))
#else 
     if((((unsigned char)rch) == (MY_ADDRESS_XIL + (unsigned char)MASK_REQUEST))
#endif     
     ||  (rch == (unsigned char)BRD_ADDRESS))
   //   if(1)
     {
 //    printfp("\n\r> addr ok ");
      current_command_state = RUN_COMMAND;
 //temp 111115      SetLineDataOffToZero();
    //   pio_ptr->SODR = 1<<18;
   //    pio_ptr->CODR = 1<<18;
  //    MClearPB19();
 //   printfp("\n\r>");
  //    printfp(" Clear :");
  //    printfpd("% 02X", *pData);
      
//      pio_ptr->CODR = 1<<19; 
     
  //     SetState(RUN_Command);
  //     temporary commented     SetLineDataSS2ToZero();
       ret = 1;
            } 
        else
        {
  //      printfp("\n\r> addr bad ");
    //    printfpd("%02X", (*pData ));
    //     printfpd(" %d ", current_command_counter);
  //     printfpd(" %d ", current_command_state);
#ifdef  IncEmbSerialSPI  
    SetLineDataSPIOffX();
    SetLineAlarmOffX();
#else  
#ifndef BACK_TO_SSC   
  //  SetLineDataOffOff(); //setted  line data to zero
    SetLineAlarmOff(); //temporary - no alarms
#else
    SetLineDataSSC2Off();
    SetLineAlarmOff();
#endif    
#endif

      current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
      }
 //  return 0;
  } 
  else if((current_command_counter == COMMAND_POS) &&  (current_command_state == RUN_COMMAND))
  {
     if(*pData <= COMMANDS_QUANTITY)
     {
      current_command_type =  *pData;
    //  printfp("\n\r type :");
   //   printfpd(" %d ", current_command_type);
  //    printfp(" CommandLength :");
  //    printfpd(" %d", CommandLength[current_command_type]);
 //     printfp(" CommandDataLength :");
 //     printfpd(" %d", CommandDataLength[current_command_type]);



 //     return 0;
      }
      else{ /* Body */
          current_command_state = WAITING_COMMAND;

      current_command_type = NO_COMMAND_SSC2;
   //            printfp(" type :");
   //   printfpd(" %d", current_command_type);
   //                printfp(" CommandLength :");
   //  printfpd(" %d", CommandLength[current_command_type]);

      
   } /* Endbody */
  }
    else if((current_command_counter == CommandDataLength[current_command_type])
    &&  (current_command_state == RUN_COMMAND))
  {
   current_command_crc =  *pData;
   
//_______________________________
   if(CheckSSC2CRC())
   {
#ifdef  IncEmbSerialSPI   
   SetLineDataSPIToZeroX();
     SetLineAlarmToOneX();
#else   
#ifndef BACK_TO_SSC   
    SetLineDataOffToZero(); //setted  line data to zero
    SetLineAlarmToOne(); //temporary - no alarms
#else
  //  SetLineDataSSC2ToSSC2Data();
  //  SetLineDataSS2ToSSC2Data()
    SetLineDataSSC2ToZero();
    SetLineAlarmToOne();
#endif
#endif    
    
    
    
    SetRunCommandSSC2(); //ok //hier only set to run - it is interrupt
    
   // SetPB19();
#ifdef TEST_PRINT_SPI   
    printfpd(" %d ", current_command_counter);
    printfp("\n\r >CRC Ok... Set :");    
#endif    
   }
   else
   {
       current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
#ifdef TEST_PRINT_SPI      
   printfpd(" %d ", current_command_counter);
    printfp("\n\r >CRC Bad..Do Not Set :");
#endif   
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
    
   } 
       
    //  printfpd("%02X", *pData);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{ /* Body */
    
 //     current_command_state = WAITING_COMMAND;

  // } /* Endbody */
    
  //  current_command_counter = 0; //
   // return 0;
 //  }



//________________________________   
   
  /*
   if(CheckSSC2CRC())
   {
    SetLineDataOffToZero(); //getted data on
    SetLineAlarmToOne(); // temporary no alarms
    
    
    SetRunCommandSSC2(); //hier only set to run - it is interrupt
   // SetPB19();
 //   printfp("\n\r >CRC Ok... Set :");        
   }
  
 //  else
 //  {
       current_command_state = WAITING_COMMAND;
      current_command_counter = 0;
//    printfp("\n\r >CRC Bad..Do Not Set :");
 //  } 
     */  
    //  printfpd("%02X", *pData);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{ /* Body */
    
 //     current_command_state = WAITING_COMMAND;

  // } /* Endbody */
    
  //  current_command_counter = 0; //
   // return 0;
  }
//  else if(current_command_counter >= CommandLength[current_command_type])//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  else if(current_command_counter >= (CommandDataLength[current_command_type]+1))//?? hier use and zero input deta when dewise get answer and after answer get to waiting
  {
  //  RunCommandSSC2(); //hier only set to run - it is interrupt
   // SetPB19();
  //      printfp("  >= CommandLength; current_command_type :");
   //   printfpd("%02X", current_command_type);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_command_state != RUN_COMMAND)
  //  { 
  //      current_command_state = WAITING_COMMAND;
  //  }
  //  else{/* Body */
    
      current_command_state = WAITING_COMMAND;

  // } /* Endbody */
    
    current_command_counter = 0;
 //   return 0;
  }
  else   if((current_command_counter > COMMAND_POS) &&  (current_command_counter < CommandDataLength[current_command_type])
            &&  (current_command_state == RUN_COMMAND))

  { 
//   printfp("\n\r adding data to buffer");
    current_command_data[current_command_data_counter++] = *pData;
//111025!!!!    ToPdcTspi(*pData);
  }


 return ret; 
}


#define BUFF_ANS_SIZE (200)

#ifdef PROG_PRM_PCH_SPI_STEND

extern "C" unsigned char OperateCommand_stend(unsigned char * pData)
{

// AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
 // pio_ptr->SODR = 1<<14; 
unsigned char BuffAns[BUFF_ANS_SIZE]; 
unsigned long ib; 
unsigned  char ret;
 ret = 0; 

unsigned char rch = * pData; 
/* 
#ifdef TEST_SPI_CHANNEL
static unsigned char tch;


 if(tch != * pData )
 { 
 err++;
 printfp("\n\r err:");
 printfpd("%ld", err);
 printfp("noerr:");
 printfpd("%ld", noerr);
 printfp(" wait:");
 printfpd("%02X", tch);
 printfp(" have:");
 printfpd("%02X", * pData);
 } 
 else
 { 
  noerr++;
}
 tch = * pData + 1;
 
 return;
#endif
      */
// if(current_command_state == RECEIVE_COMMAND)
 if(current_answer_state != WAITING_COMMAND)
 { 
  current_answer_counter++;
 }
 
// printfpd("<c:%d>", current_answer_counter);
// printfpd("<s:%d>", current_answer_state);
#ifdef TEST_PRINT_SSC2 
// printfpd(" ,%X ", rch); //110914
#endif

//if(current_command_counter == START_POS)
//  {

     if(( current_answer_state == RECEIVE_COMMAND))
     { /* Body */
       current_celling_crc += rch;
     } /* Endbody */


  // if(!((rch > (unsigned char)0xAA) || (rch < (unsigned char)0xAA)))
   if(rch == (unsigned char)0xAA)
      { 
//     embMsgSSC2N_Init();
     current_answer_state = RECEIVE_COMMAND;
     current_answer_counter = 0;
      current_celling_crc = 0;
//      printfp("\n\r> start ");
  //    printfp("\n\r>");
  BuffAns[0] = 0xAA;
      }
//  }
 else 
 if((current_answer_counter == LENGTH_POS) &&  ( current_answer_state == RECEIVE_COMMAND))
  {
     current_answer_length = rch;
     
     if(current_answer_length > BUFF_ANS_SIZE){ /* Body */
     
        current_answer_state = WAITING_COMMAND;
      current_answer_counter = 0;
 
     
   } /* Endbody */
     
 //    current_answer_state = WRITE_ANSWER;
     
 //     printfp("\n\r> len: ");
//       printfpd(" %d", *pData);
  BuffAns[current_answer_counter] = rch;
   }
 else
 if((current_answer_counter == (unsigned char)ADDR_POS) &&  ( current_command_state == (unsigned char)RECEIVE_COMMAND))
  {
   BuffAns[current_answer_counter] = rch;
  }
 else 
 if((current_answer_counter < (current_answer_length + 3)) &&  ( current_answer_state == (unsigned char)RECEIVE_COMMAND))
  {
     BuffAns[current_answer_counter] = rch;
  }
 else if((current_answer_counter == (current_answer_length + 3))
    &&  (current_answer_state == RECEIVE_COMMAND))
 {
   current_answer_crc =  *pData;
 //     printfpd("crc %02X ", current_answer_crc);
 //      printfpd("ccrc %02X", current_celling_crc - current_answer_crc + 1);

    //      printfpd("cnt %d ", current_answer_counter);

 //  if(CheckSSC2CRC())
   if((current_celling_crc - current_answer_crc + 1) ==  current_answer_crc)
   {
 //   SetRunCommandSSC2(); //hier only set to run - it is interrupt
   // SetPB19();
   
   printfp("\n\r >CRC Ok... Move to tcp :");
        
   spi_counter_r++; 
    
//hier need write answer to sended data    
     
      BuffAns[current_answer_counter] = rch;
     for(ib = 0; ib <= current_answer_length + 3; ib++)
     {
       add_char_TCP_buff(BuffAns[ib]);
    //    add_char_TCP_buff(ib);

       
       printfpd(" %02X ", BuffAns[ib]);
     } 
        printfp("\n\r");

     
       
   }
//   else
//   {
       current_answer_state = WAITING_COMMAND;
      current_answer_counter = 0;
//    printfp("\n\r >CRC Bad..Do Not Set :");
//   } 
       
    //  printfpd("%02X", *pData);
   //  pio_ptr->SODR = 1<<19; 
  //    printfp(" Set cnt zero");
   // if(current_answer_state != RUN_COMMAND)
  //  { 
  //      current_answer_state = WAITING_COMMAND;
  //  }
  //  else{ /* Body */
    
 //     current_answer_state = WAITING_COMMAND;

  // } /* Endbody */
    
  //  current_answer_counter = 0; //
   // return 0;
  }
//  else if(current_answer_counter >= CommandLength[current_answer_type])//?? hier use and zero input deta when dewise get answer and after answer get to waiting
 
 return ret; 
}

#endif


extern "C" unsigned char ReadDatassc2(unsigned char * pData, unsigned long cnt_data)
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
   ret |= OperateCommand( pData);
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



unsigned char OperateBuffers_SSC2(void)
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
 
//_______________________________________________pdc usart to ssc_



 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/


#define SSC2_TX_BUFFER 200  

unsigned char Buffssc2t[SSC2_TX_BUFFER]; //buffer
unsigned char Buff1ssc2t[SSC2_TX_BUFFER]; //buffer
unsigned long  cntBuffssc2t, cntBuff1ssc2t;
unsigned char *  pBuffssc2t;
unsigned char * pBuff1ssc2t;
unsigned char flag_pdcssc2t;

//#pragma BSS()


  
void enableTxPdcSSC2()
{

 AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;


  SSC2_ptr->PDC.TPR = (uint_32)&Buffssc2t[0];
  SSC2_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcssc2t = 0;
    pBuffssc2t = &Buffssc2t[0];   //need init!!!!!!
    cntBuffssc2t = 0;
    pBuff1ssc2t = &Buff1ssc2t[0];   //need init!!!!!!
    cntBuff1ssc2t = 0;


  SSC2_ptr->PDC.TNPR = (uint_32)&Buff1ssc2t[0];
  SSC2_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
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
 //    SSC2_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
//110621   SSC2_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SSC2_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
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



extern "C" void ToPdcTssc2(unsigned char ch1t)
{
 //printfp("ToPdcTssc2");

 if(!flag_pdcssc2t)
 {
  if(cntBuffssc2t < SSC2_TX_BUFFER)
     {

     *pBuffssc2t++ = ch1t;    //need init!!!!!!
     cntBuffssc2t++;
     }
 }
 else
 { 
  if(cntBuff1ssc2t < SSC2_TX_BUFFER)
     {
     *pBuff1ssc2t++ = ch1t;   //need init!!!!!!
     cntBuff1ssc2t++;
     }
 }
 
}



unsigned char OperateBuffers_SSC2t(void)
{
 //printfp(" OB_SSC2t");

 AT91RM9200_SSC_REG_STRUCT_PTR         SSC2_ptr;
  SSC2_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC2_BASE;
 
 unsigned long byte_cnt;
SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = SSC2_ptr->PDC.TCR;
SSC2_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 

  if(byte_cnt)  return byte_cnt; //pdc is not finished transmit
  
 if(cntBuffssc2t)
 {
//    SSC2_ptr->PDC.TPR = (uint_32)&Buffssc2t[0];
//    SSC2_ptr->PDC.TCR = cntBuffssc2t;
    
    pBuffssc2t = &Buffssc2t[0];   //need init!!!!!!
//    cntBuffssc2t = 0;
    flag_pdcssc2t = 1;
    SSC2_ptr->PDC.TPR = (uint_32)&Buffssc2t[0];
    SSC2_ptr->PDC.TCR = cntBuffssc2t;    
    cntBuffssc2t = 0;
    
    return 0;
 }
 
 if(cntBuff1ssc2t)
 {
  //  SSC2_ptr->PDC.TPR = (uint_32)&Buff1ssc2t[0];
  //  SSC2_ptr->PDC.TCR = cntBuff1ssc2t;
    
    pBuff1ssc2t = &Buff1ssc2t[0];   //need init!!!!!!
//    cntBuff1ssc2t = 0;
    flag_pdcssc2t = 0;
    SSC2_ptr->PDC.TPR = (uint_32)&Buff1ssc2t[0];
    SSC2_ptr->PDC.TCR = cntBuff1ssc2t;
    cntBuff1ssc2t = 0;
    return 0;
 }

}






//______________________________________________pdc usart transmit to ssc


#ifdef TEST_TRANSMIT_FROM_SSC1

//#define AT91RM9200_SSC_IMR_RXRDY (0x10)
void init_test_SSC1(void)
{

 //  printf("init_test_ssc1");
//1 init transmit to self clocks
  AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
  SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
  
//______________________________________
/*
 AT91F_SSC_Configure (SSC2_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
		  //t	    	0x202,//rcmr - source - rk
        	// t   	0x202,//rcmr - source - rk
         //    	0x402,// try failing edge rcmr - source - rk
             	0x422,// try failing edge rcmr - source - rk
		  //t110914			0xF07,  //rfmr - size for one cyckle pdc + off loop!
       //t 			0xf1F,  //rfmr - size for one cyckle pdc + off loop! //110914
        			0xf07,  //rfmr - size for one cyckle pdc + off loop! //110915
          //t1     4,//   0x200, //internal clock source //0x202,// tcmr// 4,
               0x204,//   0x200, //internal clock source //0x202,// tcmr// 4,
          //t    0x201,// ,
              
//aftr connecting rf-tf need program 0x27              
       //110710        0x00300027 //  drive tf low// 0x7+1 bits   //rfmrto test clock 
        //110712       0x00300F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock   
               0x00000F27 // try set 16 bytest send drive tf low// 0x7+1 bits   //rfmrto test clock 
                 	);	// End of 


     */
//______________________________________  
 /*
 AT91F_SSC_Configure (SSC1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
			  //110921  	0x201,//rcmr
         //      0x422,//110921
               0x222,//t //110921
					0xF07,  //rfmr - size for one cyckle pdc + set loop!
   //111018            4,//   0x200, //internal clock source //0x202,// tcmr// 4,
         //      0x00100004,//   0x200, //internal clock source //0x202,// tcmr// 4,
  //111018             0x00000024,//   0x200, //internal clock source //0x202,// tcmr// 4,
               0x00ff0024,//   0x200, //internal clock source //0x202,// tcmr// 4,
  //             0x00300027 // + drive tf low// 0x7+1 bits   //rfmrto test clock 
   //111018          0x003000A7//111017 // + drive tf low// 0x7+1 bits   //rfmrto test clock 
             0x003000A7//111017 // + drive tf low// 0x7+1 bits   //rfmrto test clock     
      //       0x005000A7//111017 // + drive tf low// 0x7+1 bits   //rfmrto test clock
        //            0x005000A7//111017 // + drive tf low// 0x7+1 bits   //rfmrto test clock      
    //         0x000000A7//111017 // + drive tf low// 0x7+1 bits   //rfmrto test clock   
    //           0x00300F27 // + drive tf low// 0x7+1 bits   //rfmrto test clock //110927
         	);	// End of 
            */
//___________________________________________________
 AT91F_SSC_Configure (SSC1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
			  //110921  	0x201,//rcmr
         //      0x422,//110921
               0x222,//t //110921
					0xf07,  //rfmr - size for one cyckle pdc + set loop!
               4,//   0x200, //internal clock source //0x202,// tcmr// 4,
    //           0x00300027 // + drive tf low// 0x7+1 bits   //rfmrto test clock 
               0x00300f27 // + drive tf low// 0x7+1 bits   //rfmrto test clock //110927
         	);	// End of 


//___________________________________________________            
            
            
            
 SSC1_ptr->IER =  AT91RM9200_SSC_IMR_RXRDY; //AT91RM9200_SSC_IMR_ENDRX; //t
 AT91F_SSC_EnableTx (SSC1_ptr);     //t        
 AT91F_SSC_EnableRx (SSC1_ptr);     //t     
//2 make tx enable
//3 make loop - transmit - receive
//4 start transmit immediatly at some write
//5 fsps : 3 : tf drive low during data transfer   
}

#define PERIOD_SSC1_RECEIVE ((PERIOD_SSC1_SEND >> 1)+1)

void test_receive_data_SSC1(void)
{
unsigned char ret;
unsigned long reg;
static unsigned char send_type = 0;
static unsigned char send_char = 0;
static unsigned long timekeep;

static unsigned char pinger;

//AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
 // SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;

 // _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);

if(timekeep > time1) timekeep = time1;
/*
if((time1 - timekeep) > (PERIOD_SSC1_SEND >> 1)) 
{
 // SetPB19();

}
 */
//ok if((time1 - timekeep) > 2l)         
if((time1 - timekeep) >= (unsigned long)PERIOD_SSC1_RECEIVE)         
//if(1)
{


#ifdef TEST_TRANSMIT_FROM_SSC1
//ok printfpd("\n\r%ld",irq0_counter);
#endif

//t AT91F_SSC_EnableTx (SSC1_ptr);     //t        
//t AT91F_SSC_EnableRx (SSC1_ptr);     //t        
 
//  printfp("\n\r send to ssc1:");
  
//   reg = SSC1_ptr->PDC.PTSR;
 //    printfpd(" %X", reg);
 
 //  reg = SSC1_ptr->SR;
 //    printfp("SR:");
 //    printfpd("%X", reg);   //hier view as tx and rx are disabled
 
// printfp(" cnt1:");
// printfpd("%ld", SSC1_int_counter);
     
      
// SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
// reg  = SSC1_ptr->PDC.TCR;
// SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
//      printfpd("> %X", reg);
//t  SSC1_ptr->IER =  0xff; //if comment hier -loss    
       
 //reg  = SSC1_ptr->IMR;      
 // printfp("IMR :");
 // printfpd(" %X", reg);
  
//______________________________________  
   OperateBuffers_SSC1();  
//   printfpd(" %d", ret);
//______________________________________ 





timekeep = time1;

}
}

//#define PERIOD_SSC1_SEND (500)
#define TEST_FREQ_BYTE1 (0x12)
#define TEST_FREQ_BYTE2 (0x34)

void test_send_data_SSC1(void)
{
unsigned char ret;
unsigned long reg;
static unsigned char send_type = 0;
static unsigned char send_char = 0;
static unsigned long timekeep;

static unsigned char pinger;

AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
  SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;

  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);

if(timekeep > time1) timekeep = time1;
/*
if((time1 - timekeep) > (PERIOD_SSC1_SEND >> 1)) 
{
 // SetPB19();

}
 */
//ok if((time1 - timekeep) > 2l)         
if((time1 - timekeep) >= (unsigned long)PERIOD_SSC1_SEND)         
//if(1)
{


#ifdef TEST_TRANSMIT_FROM_SSC1
//ok printfpd("\n\r%ld",irq0_counter);
#endif

//t AT91F_SSC_EnableTx (SSC1_ptr);     //t        
//t AT91F_SSC_EnableRx (SSC1_ptr);     //t  
#ifdef	 PROG_PRM_PCH_SPI_STEND     
 spi_counter_t ++;
#endif 
  printfp("\n\r send to ssc1:");
  
//   reg = SSC1_ptr->PDC.PTSR;
 //    printfpd(" %X", reg);
 
 //  reg = SSC1_ptr->SR;
 //    printfp("SR:");
 //    printfpd("%X", reg);   //hier view as tx and rx are disabled
 
// printfp(" cnt1:");
// printfpd("%ld", SSC1_int_counter);
     
      
// SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
// reg  = SSC1_ptr->PDC.TCR;
// SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 
//      printfpd("> %X", reg);
//t  SSC1_ptr->IER =  0xff; //if comment hier -loss    
       
 //reg  = SSC1_ptr->IMR;      
 // printfp("IMR :");
 // printfpd(" %X", reg);
  
//______________________________________  
//   ret = OperateBuffers_SSC1t();  
//   printfpd(" %d", ret);
//______________________________________ 





timekeep = time1;

// ToPdcTSSC1t(send_char++);
//ToPdcTSSC1t(0x5A);
//ok ToPdcTSSC1t(0x0);

//ToPdcTSSC1t(0x1);
/*
ToPdcTSSC1t(0x2);
ToPdcTSSC1t(0x4);
ToPdcTSSC1t(0x8);
      
ToPdcTSSC1t(0x10);
ToPdcTSSC1t(0x20);
ToPdcTSSC1t(0x40);
ToPdcTSSC1t(0x80);

     */





  
if(pinger)
{
pinger = 0;

  /*
 ToPdcTSSC1t(START_COMMAND);
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS);
 ToPdcTSSC1t(COMM2_LEN);
 ToPdcTSSC1t(COMMANDN2);
 ToPdcTSSC1t(TEST_FREQ_BYTE1);   //my addr
 ToPdcTSSC1t(TEST_FREQ_BYTE2); //command
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS + COMM2_LEN + COMMANDN2 + TEST_FREQ_BYTE1 + TEST_FREQ_BYTE2 + 1); //checksum
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 ToPdcTSSC1t(0x55);
 
 */
 /*
 ToPdcTSSC1t(START_COMMAND);
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS);
 ToPdcTSSC1t(COMM3_LEN);
 ToPdcTSSC1t(COMMANDN3);
 ToPdcTSSC1t(TEST_ATT_BYTE1);   //my addr
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS + COMM3_LEN + COMMANDN3 + TEST_ATT_BYTE1 + 1); //checksum
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
  */
 ToPdcTSSC1t(0x55);     
 ToPdcTSSC1t(START_COMMAND);
// ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS);
 //ToPdcTSSC1t(COMMON_ADDR);
 ToPdcTSSC1t(0x81);
// ToPdcTSSC1t(COMM1_LEN);
 ToPdcTSSC1t(1);
 ToPdcTSSC1t(COMMANDN1);
// ToPdcTSSC1t(TEST_ATT_BYTE1);   //my addr
// ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS + 1 + COMMANDN1  + 1); //checksum
// ToPdcTSSC1t(COMMON_ADDR + 1 + COMMANDN1  + 1); //checksum
 ToPdcTSSC1t(0x81 + 1 + COMMANDN1  + 1); //checksum
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
       
     /*
 ToPdcTSSC1t(START_COMMAND);
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS);
// ToPdcTSSC1t(COMM4_LEN);
 ToPdcTSSC1t(1);
 ToPdcTSSC1t(COMMANDN4);
// ToPdcTSSC1t(TEST_ATT_BYTE1);   //my addr
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS + 1 + COMMANDN4  + 1); //len request = 1checksum
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
   */
     /*
 ToPdcTSSC1t(START_COMMAND);
 ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS);
// ToPdcTSSC1t(COMM4_LEN);
 ToPdcTSSC1t(2);
 ToPdcTSSC1t(COMMANDN8);
 ToPdcTSSC1t(1);   // rejektor on
  ToPdcTSSC1t(MASK_REQUEST + MY_ADDRESS + 2 + COMMANDN8 + 1 + 1); //len request = 1checksum
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
        */

}
else
{
  pinger = 1; 
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);
 ToPdcTSSC1t(0xFE);

}
  
 /*
  ret = OperateBuffers_SSC1t();     //110922

  for(unsigned i = 0; i < 16; i ++)   //clocks for answer
 {
  ToPdcTSSC1t(0x7E);
 } 


  */


// ToPdcTSSC1t(0x55);
  

 // SetPB19();
// MClearPB19();
  //    printfp(" Clear :");
/*  
  
 if(!send_type)
 {
//for(unsigned i = 0; i < 16; i++)
//for(unsigned i = 0; i < 100; i++)
for(unsigned i = 0; i < 50; i++)

{
 send_char++;
// printfpd("_%d", send_char);
#ifdef TEST_SPI_CHANNEL
 printfpd("_%X", send_char);
 ToPdcTSSC1t(send_char);
#else 
 printfpd("_%X", i);
 ToPdcTSSC1t(i);
#endif 
}
send_type = 1; 
}
else //if (send_type == 1)
{
//for(unsigned i = 0; i < 16; i++)
//for(unsigned i = 0; i < 100; i++)
for(unsigned i = 0; i < 50; i++)
{
// send_char++;
 // printfpd("_%d", send_char);

 //ToPdcTSSC1t(send_char);
 send_char++;
 // printfpd("_%d", send_char);
#ifdef TEST_SPI_CHANNEL
 ToPdcTSSC1t(send_char);
#else 
 //ToPdcTSSC1t(0);
 printfpd("_%X", i);
  ToPdcTSSC1t(i);
#endif 
 
}
send_type = 0;   
   
}

*/
   /*
else if (send_type == 2)
{
for(unsigned i = 0; i < 16; i++)
{
// send_char++;
 // printfpd("_%d", send_char);

 //ToPdcTSSC1t(send_char);
 send_char++;
 // printfpd("_%d", send_char);
#ifdef TEST_SPI_CHANNEL
 ToPdcTSSC1t(send_char);
#else 
 ToPdcTSSC1t(i+16);
// printfpd("_%d", i+16);
#endif 
 
}
send_type = 0;   
   
}

  */

  
//  if(current_command_state == WAITING_COMMAND)
//  { 
//110712  SetLineDataSS2ToOne(); //temporary
 // }
 
  /*
  ToPdcTSSC1t(0);
  ToPdcTSSC1t(0xff);
   */
 
//send_char++;
 //ToPdcTSSC1(send_char);
 
//?? need enable transmit data pin and enable olwais
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_A, 0);
  
 // ret = OperateBuffers_SSC1t(); 
 //  printfpd(" %d", ret);
   
 //  OperateBuffers_SSC1();  //recomment 110921
   
   ret = OperateBuffers_SSC1t();  
//  printfp("\n\r ret:");
//  printfpd(" %d", ret);

//?? need make this later? why?  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0);
//?? need disable transmit data pin pdc or pin to can have "star"   
}
}



extern "C" void init_exchangeSSC1t(void)
{
init_SSC1t();
enableRxPdcSSC1t();
enableTxPdcSSC1t();
//enable_ints_SSC1t();
}

//#define SSC1_FREQ (5000000)

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : init_channel
* Returned Value   : none
* Comments         :
*    This function init SSC1 for spi
*
*END*----------------------------------------------------------------------*/

void init_SSC1t (void)
{
 // unsigned int cnt;
//  char* CurrentDataPointer;
// unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR SSC1_ptr;    //0 -> 1
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
 //  unsigned int XilSizeToDownload    = XilSizeToDownloadD; //temporary;
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
 
 //  volatile unsigned int status;
   
     pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 //    pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_A, 0); //tf2   //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_A, 0);  //tk2   //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0); //td2    //data
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 0); //td2    //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_A, 0); //rd2     //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_A, 0);  //rk2   //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_A, 0);  //rf2  //tf2   //line done

// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for line alarm  //rf2  //tf2   //line done

 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for some tests
 //_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1); //for some tests


//  pio_ptr->SODR = 1<<22; //set line alarm to one
// 	SetLineDataSSC1Off();  //for many devices systems	
 // 	SetLineAlarmOff();

 
 
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
//not need  imr =  aic_ptr->IMR;
//not need      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
//110621  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
  /*
 if(pg > 1)
 { 
   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
  } 
  if(pg > 2)
 { 
   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
  } 
   */
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   SSC1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC1_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset SSC1  
   SSC1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(SSC1_ptr->PDC));
   
 // if(!div)
 //  {div++;}
   
  AT91F_SSC_Configure (SSC1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				   SSC2_FREQ, //up to 5 MHz //	(XIL_LOAD_FREQ  / div),
			    	0x202,       //rcmr
					0x7, //rfmr - size for one cyckle pdc
              0x201,// tcmr// 4,
              0x27   //tfmr     default data line level is one
         	);	// End of 
            
 SSC1_ptr->IER =  AT91RM9200_SSC_IMR_RXRDY; //AT91RM9200_SSC_IMR_ENDRX; //test            
            
 AT91F_SSC_EnableTx (SSC1_ptr);     //t        
 AT91F_SSC_EnableRx (SSC1_ptr);     //t        
//not need  SSC1Buff_Init();  
    }
 
//_______________________________________________pdc usart to ssc
//#ifdef  USART1_TRY_PDC

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcSSC1
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for receive SSC1
*
*END*----------------------------------------------------------------------*/

#define SSC1_RX_BUFFER 200  
  
unsigned char BuffSSC1[SSC1_RX_BUFFER]; //buffer
unsigned char Buff1SSC1[SSC1_RX_BUFFER]; //buffer
unsigned char flag_pdcSSC1;


void enableRxPdcSSC1t()
{
  AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
  SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//AT91F_PDC_EnableRx (
//	AT91PS_PDC pPDC ) 

  SSC1_ptr->PDC.RPR = (uint_32)&BuffSSC1[0];
  SSC1_ptr->PDC.RCR = SSC1_RX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcSSC1 = 0;

  SSC1_ptr->PDC.RNPR = (uint_32)&Buff1SSC1[0];
  SSC1_ptr->PDC.RNCR = SSC1_RX_BUFFER;

   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
//   usart0_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;  
   /* Enable PDC Receive Transmitter */
   SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;
   
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
 //    SSC1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
 //110620  SSC1_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SSC1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
//110620     SSC1_ptr->CR = AT91RM9200_DBGU_CR_TX_ENABLE;// | AT91RM9200_DBGU_CR_RX_DISABLE;  //only tx to interrupts
 // usart0_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE |AT91RM9200_DBGU_RETTO_ENABLE;  
//  usart0_ptr->IER = AT91RM9200_DBGU_IER_TIMEOUT_INT_ENABLE;
//__________________________________
 /* 
#ifdef PROG_PRM_PCH_N
    SetSSC1BaudRate(921600l);
#else 
    SetSSC1BaudRate(38400l); 
#endif 
*/


}

unsigned char ssc1_receive_counter;
unsigned char ssc1_receive_state;
unsigned char ssc1_receive_length;

#define SSC1_ANSWER_SIZE (200)


extern "C" void SetBufferToEth()
{
   
}

unsigned char ssc1_receive_counter;
unsigned char ssc1_receive_state;
unsigned char ssc1_receive_length;

#define SSC1_ANSWER_SIZE (200)
#define  SL_SIZE (4)



extern "C" unsigned char ReadDataSSC1(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
unsigned char  SetChar;  
//static unsigned char BufferSSC1Answer[SSC1_ANSWER_SIZE];
//if(GetTestMode() != PIPE_MODE)
//{ 
// printfp("RD");
#ifdef	 PROG_PRM_PCH_SPI_STEND 
    spi_counter_r++;
#endif    
printfp("\n\r receive ssc1 :");
printfpd(" %d", cnt_data);


//return; // for test

unsigned char ret = 0;

while(cnt_data--)
{
//110921    ret |= OperateCommand( pData++);
  SetChar =  *pData++;
 //  SSC1Buff_Add(SetChar);
//t110704   SSC1Buff_Add(* pData++);
   
    printfpd(" %02X", SetChar);

//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
  ssc1_receive_counter++;
    
  if(SetChar ==  START_COMMAND)
  { 
//120119   ssc1_receive_counter = 0;
     ssc1_receive_counter = 1; //120119;

   
   ssc1_receive_state = RECEIVE_COMMAND;
  } 
// printfpd(" !%d ", ssc1_receive_counter);
  
  
  if(ssc1_receive_state == RECEIVE_COMMAND)
  { /* Body */
 //  BufferSSC1Answer[ssc1_receive_counter] = SetChar;
#ifdef PROG_PRM_PCH_SPI_STEND 
   if(flag_add_tcp)
      {
      add_char_TCP_buff(SetChar);
      }
#endif      

  } /* Endbody */
  
  if((ssc1_receive_counter == LENGTH_POS) && (ssc1_receive_state == RECEIVE_COMMAND))
  {
     ssc1_receive_length = SetChar;
      printfp("\n\r> len - 4: ");
       printfpd(" %d", SetChar);
  }
  
   if((ssc1_receive_counter > LENGTH_POS)  && (ssc1_receive_state == RECEIVE_COMMAND))
  {
    if(ssc1_receive_counter >= (ssc1_receive_length + SL_SIZE))
    { /* Body */
     ssc1_receive_state == WAITING_COMMAND;
      breakflag = 1;
    } /* Endbody */
 }
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

/*


extern "C" unsigned char ReadDataSSC1(unsigned char * pData, unsigned long cnt_data)
{
//#ifdef IncEmbRS485 
unsigned char  SetChar;  
static unsigned char BufferSSC1Answer[SSC1_ANSWER_SIZE];
//if(GetTestMode() != PIPE_MODE)
//{ 
// printfp("RD");

printfp("\n\r receive ssc1 :");
printfpd(" %d", cnt_data);

unsigned char ret = 0;

while(cnt_data--)
{
//110921    ret |= OperateCommand( pData++);
  SetChar =  * pData++;
 //  SSC1Buff_Add(SetChar);
//t110704   SSC1Buff_Add(* pData++);
   
    printfpd(" %02X", SetChar);

//110620 can hier read  embRS485.rcvbuf.Add((unsigned char)(SetChar));
//   if(TestMode.Value == 4)
//   {
  //    Stephany15++;
//      TrzBuff485_Add((unsigned char) SetChar);
//   }
  ssc1_receive_counter++;
    
  if(SetChar ==  START_COMMAND)
  { 
   ssc1_receive_counter = 0;
   ssc1_receive_state = RECEIVE_COMMAND;
  } 
  
  if(ssc1_receive_state == RECEIVE_COMMAND)
  { 
   BufferSSC1Answer[ssc1_receive_counter] = SetChar;
  }
  
  if((ssc1_receive_counter == LENGTH_POS) && (ssc1_receive_state == RECEIVE_COMMAND))
  {
     ssc1_receive_length = SetChar;
      printfp("\n\r> len: ");
       printfpd(" %d", SetChar);
  }
  
   if((ssc1_receive_counter > LENGTH_POS)  && (ssc1_receive_state == RECEIVE_COMMAND))

  {
    if(ssc1_receive_counter >= ssc1_receive_length)
    {
     ssc1_receive_state == WAITING_COMMAND;
     SetBufferToEth();
    }
 }
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

  */

unsigned char OperateBuffers_SSC1(void)
{
//printfp(" OB");
 unsigned char ret = 0;
 AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
 SSC1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;

 unsigned long byte_cnt;
 SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
 byte_cnt = SSC1_ptr->PDC.RCR;
 SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;  

 if(!flag_pdcSSC1)
 {
  if(byte_cnt < SSC1_RX_BUFFER) //receive some; more not can be
   {
//    printf("\n\r 1: %d",byte_cnt); 
    SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SSC1_ptr->PDC.RCR;
    SSC1_ptr->PDC.RPR = (uint_32)&Buff1SSC1[0];
    SSC1_ptr->PDC.RCR = SSC1_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcSSC1 = 1;
    SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;    
    ret |= ReadDataSSC1((unsigned char *)&BuffSSC1[0], (SSC1_RX_BUFFER - byte_cnt));
   }
    }
 else
 {
 if(byte_cnt < SSC1_RX_BUFFER)
   {
//    printf("\n\r 2: %d",byte_cnt); 
    SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_DISABLE; 
    byte_cnt = SSC1_ptr->PDC.RCR;
    SSC1_ptr->PDC.RPR = (uint_32)&BuffSSC1[0];
    SSC1_ptr->PDC.RCR = SSC1_RX_BUFFER; //USART0_RX_BUFFER;
    flag_pdcSSC1 = 0;
    SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_RXT_ENABLE;     
    ret |= ReadDataSSC1((unsigned char *)&Buff1SSC1[0], (SSC1_RX_BUFFER - byte_cnt));
   }
   }
 return ret;
}
 
//_______________________________________________pdc usart to ssc_



 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : enableRxPdcUsart
* Returned Value   : none
* Comments         :
*    This function maked enable pdc channel for usart
*
*END*----------------------------------------------------------------------*/


#define SSC1_TX_BUFFER 200  

unsigned char BuffSSC1t[SSC1_TX_BUFFER]; //buffer
unsigned char Buff1SSC1t[SSC1_TX_BUFFER]; //buffer
unsigned long  cntBuffSSC1t, cntBuff1SSC1t;
unsigned char *  pBuffSSC1t;
unsigned char * pBuff1SSC1t;
unsigned char flag_pdcSSC1t;

//#pragma BSS()


  
void enableTxPdcSSC1t()
{

 AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
  SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;


  SSC1_ptr->PDC.TPR = (uint_32)&BuffSSC1t[0];
  SSC1_ptr->PDC.TCR = 0;//USART0_TX_BUFFER; //USART0_RX_BUFFER;
  flag_pdcSSC1t = 0;
    pBuffSSC1t = &BuffSSC1t[0];   //need init!!!!!!
    cntBuffSSC1t = 0;
    pBuff1SSC1t = &Buff1SSC1t[0];   //need init!!!!!!
    cntBuff1SSC1t = 0;


  SSC1_ptr->PDC.TNPR = (uint_32)&Buff1SSC1t[0];
  SSC1_ptr->PDC.TNCR = 0;//USART0_TX_BUFFER;
//ok return; //t
   /* Interrupt when transmission is completed */
 //  usart0_ptr->IER = AT91RM9200_DBGU_IER_TX_EOT_INT_ENABLE;
   
   /* Enable PDC Transmitter */
   SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE;   //??? - to transmit need?
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
 //    SSC1_ptr->IER = AT91RM9200_DBGU_IER_RX_EOT_INT_ENABLE;  
   
    /* Disable Interrupt for every received symbol */
//  usart0_ptr->IDR = AT91RM9200_DBGU_IER_RX_READY_INT_ENABLE;        //100226   
//110621   SSC1_ptr->IDR = AT91RM9200_DBGU_IER_TX_READY_INT_ENABLE;    // ??? disable transmit interrupt


   
//bad return; //t

//__________________________________receive timeout

//  usart0_ptr->RTOR = USART0_TIMEOUT;
//  SSC1_ptr->CR = AT91RM9200_DBGU_CR_RX_ENABLE | AT91RM9200_DBGU_CR_TX_ENABLE | AT91RM9200_DBGU_STTTO_ENABLE;
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



extern "C" void ToPdcTSSC1t(unsigned char ch1t)
{
 printfpd(" %02X", ch1t);

 if(!flag_pdcSSC1t)
 {
  if(cntBuffSSC1t < SSC1_TX_BUFFER)
     {

     *pBuffSSC1t++ = ch1t;    //need init!!!!!!
     cntBuffSSC1t++;
     }
 }
 else
 { 
  if(cntBuff1SSC1t < SSC1_TX_BUFFER)
     {
     *pBuff1SSC1t++ = ch1t;   //need init!!!!!!
     cntBuff1SSC1t++;
     }
 }
 
}



unsigned char OperateBuffers_SSC1t(void)
{
// printfp(" OB_SSC1t");
// printfp(".");

 AT91RM9200_SSC_REG_STRUCT_PTR         SSC1_ptr;
  SSC1_ptr = (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
 
 unsigned long byte_cnt;
SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_DISABLE; 
 byte_cnt = SSC1_ptr->PDC.TCR;
SSC1_ptr->PDC.PTCR = AT91RM9200_PDC_PTCR_TXT_ENABLE; 

  if(byte_cnt)  return byte_cnt; //pdc is not finished transmit
  
 if(cntBuffSSC1t)
 {
//    SSC1_ptr->PDC.TPR = (uint_32)&BuffSSC1t[0];
//    SSC1_ptr->PDC.TCR = cntBuffSSC1t;
    
    pBuffSSC1t = &BuffSSC1t[0];   //need init!!!!!!
//    cntBuffSSC1t = 0;
    flag_pdcSSC1t = 1;
    SSC1_ptr->PDC.TPR = (uint_32)&BuffSSC1t[0];
    SSC1_ptr->PDC.TCR = cntBuffSSC1t;    
    cntBuffSSC1t = 0;
    
    return 0;
 }
 
 if(cntBuff1SSC1t)
 {
  //  SSC1_ptr->PDC.TPR = (uint_32)&Buff1SSC1t[0];
  //  SSC1_ptr->PDC.TCR = cntBuff1SSC1t;
    
    pBuff1SSC1t = &Buff1SSC1t[0];   //need init!!!!!!
//    cntBuff1SSC1t = 0;
    flag_pdcSSC1t = 0;
    SSC1_ptr->PDC.TPR = (uint_32)&Buff1SSC1t[0];
    SSC1_ptr->PDC.TCR = cntBuff1SSC1t;
    cntBuff1SSC1t = 0;
    return 0;
 }

}






#endif  //Testreansmitssc1




#endif //  PROG_PRM_PCH_SPI  


void m_load_xilinx3_ok (char pg , char div)
{
 // printfp("\n\rm_load_xilinx3");

  unsigned int cnt;
  char* CurrentDataPointer;
 unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
 //    printfp("Start load xilinx");
     unsigned int XilSizeToDownload  = 100000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
//     unsigned int XilSizeToDownload  = 75000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
#else   
   unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff;
#endif //no	 PROG_PRM_PCH_SPI_XIL_ETH
   
 //   printfpd("\n\rs:%d ", XilSizeToDownload);
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
 
   volatile unsigned int status;
     pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

     pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
 imr =  aic_ptr->IMR;
      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
 if(pg > 1)
 { 
   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
  } 
  if(pg > 2)
 { 
   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
  } 
  
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC0_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
  if(!div)
   {div++;}
  AT91F_SSC_Configure (ssc0_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
   //ok        10000l, //old xilinx
           100000l, //old xilinx
#else				
            	(XIL_LOAD_FREQ  / div),
#endif               
			    	0,
					0, 
               4,
//            0xFFFF0004, //  //  4, // 0,//   4,         //clocks + period
        // 0x24,//clock invert
      // 0x7 //lsb first// 0x87 // msb first     7 
          //t   0x1f  
        //t   0x9f      //msb first   32
      //t    0x87    
    
        0x7   //to test clock 
//    0x87  //tsp3
     //t 0x87   //test period     
    //  0xA7   //to test datdef = 1 

         	);	// End of 
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
/* t       
 //_____________________________________________________________________________________________ 
        	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
        //   	 (char *)XilAddressToDownload, 				// pointer to next data
              (char *)TFTP_BUFFER_ADDRESS,
          //       (char*)&Test, //t
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1)); //t
  //_________________________new              
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1));
 //________________________________________________________
t  */
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
    
    pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

 // delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
  
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & 0x10))
      { 
  //    printf("\n\r cnt0 = %d",cnt);
      break;
       }
   } 

  
 //  delay_mcs(2000l); //t
    pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
//   delay_mcs(400l);  //t
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //line init hier one
     if(status & 0x10)
      { 
   //   printf("\n\r cnt1 = %d",cnt);
         break;
   } 
    
     
   }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
   ssc0_ptr->TCMR = 4; //try before
 //  delay_mcs(400l); 
#ifdef PROG_BMD2   
     /*
   delay_mcs(400l); 
      delay_mcs(400l); 
         delay_mcs(400l); 
            delay_mcs(400l); 
               delay_mcs(400l); 
                  delay_mcs(400l); 
                     delay_mcs(400l);
                     */
#endif // PROG_BMD2                         
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last
/*t1219
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
  (XilSizeToDownload >> 1),
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)),
  (XilSizeToDownload >> 1) );
      */ //t1219
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc0_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc0_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
   }
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
 for(cnt = 0l; cnt < 10000000l; cnt++)
 { 
  status = pio_ptr->PDSR;
  if(status & 0x20) //line done
  {
  //   printf("\n\r after load : cnt = %d",cnt);
   break;
   }
 } 
   /*
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l); 
   delay_mcs( 400l);
      */
   ssc0_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)
  
  #ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
  //   printfp("\n\rFinish load xilinx");
  #endif
    }

      
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_load_xilinx3
* Returned Value   : none
* Comments         :
*    This function load binary configuration file to xilinx
*
*END*----------------------------------------------------------------------*/

void m_load_xilinx3 (char pg , char div)
{
 // printfp("\n\rm_load_xilinx3");

  unsigned int cnt;
  char* CurrentDataPointer;
 unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
 //    printfp("Start load xilinx");
     unsigned int XilSizeToDownload  = 100000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
//     unsigned int XilSizeToDownload  = 75000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
#else   
   unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff;
#endif //no	 PROG_PRM_PCH_SPI_XIL_ETH
   
 //   printfpd("\n\rs:%d ", XilSizeToDownload);
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
#ifdef  PROG_MD310_SATI
 //    printfp("Start load xilinx");
      XilSizeToDownload  = 270000l; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
//     unsigned int XilSizeToDownload  = 75000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 


#endif 
   volatile unsigned int status;
     pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

     pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
 imr =  aic_ptr->IMR;
      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
#ifndef PROG_MD310_SATI

  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
#else
  read_dataflash ((unsigned int)XilDataAddressD7, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));

#endif


 if(pg > 1)
 { 
   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
  } 
  if(pg > 2)
 { 
   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
  } 
  
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC0_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
  if(!div)
   {div++;}
  AT91F_SSC_Configure (ssc0_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
   //ok        10000l, //old xilinx
           100000l, //old xilinx
#else				
            	(XIL_LOAD_FREQ  / div),
#endif               
			    	0,
					0, 
               4,
//            0xFFFF0004, //  //  4, // 0,//   4,         //clocks + period
        // 0x24,//clock invert
      // 0x7 //lsb first// 0x87 // msb first     7 
          //t   0x1f  
        //t   0x9f      //msb first   32
      //t    0x87    
    
        0x7   //to test clock 
//    0x87  //tsp3
     //t 0x87   //test period     
    //  0xA7   //to test datdef = 1 

         	);	// End of 
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
/* t       
 //_____________________________________________________________________________________________ 
        	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
        //   	 (char *)XilAddressToDownload, 				// pointer to next data
              (char *)TFTP_BUFFER_ADDRESS,
          //       (char*)&Test, //t
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1)); //t
  //_________________________new              
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1));
 //________________________________________________________
t  */
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
    
    pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

 // delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
  
   for(cnt = 0; cnt < 500000l; cnt++)
 //  for(cnt = 0; cnt < 10000l; cnt++)
   {
     status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & 0x10))
      { 
  //    printf("\n\r cnt0 = %d",cnt);
      break;
       }
   } 

  
 //  delay_mcs(2000l); //t
    pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
//   delay_mcs(400l);  //t
//   for(cnt = 0; cnt < 10000l; cnt++)
   for(cnt = 0; cnt < 500000l; cnt++)
   {
     status = pio_ptr->PDSR; //line init hier one
     if(status & 0x10)
      { 
   //   printf("\n\r cnt1 = %d",cnt);
         break;
   } 
    
     
   }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
 //  delay_mcs(40000l); 

   ssc0_ptr->TCMR = 4; //try before
  //   delay_mcs(40000l); 

 //  delay_mcs(400l); 
#ifdef PROG_BMD2   
     /*
   delay_mcs(400l); 
      delay_mcs(400l); 
         delay_mcs(400l); 
            delay_mcs(400l); 
               delay_mcs(400l); 
                  delay_mcs(400l); 
                     delay_mcs(400l);
                     */
#endif // PROG_BMD2                         
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last
/*t1219
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
  (XilSizeToDownload >> 1),
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)),
  (XilSizeToDownload >> 1) );
      */ //t1219
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
  //  printfpd("\n\r Start CurrentDataPointer %x\n\r", (unsigned)CurrentDataPointer);  
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
   
 //  ssc0_ptr->TCMR = 4;
//#ifdef PROG_PU_M_MUX   //test
//      XilSizeToDownload = 450000l; //for test do not load
//#endif
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc0_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc0_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;  
  //  printfpd("\n\r CurrentDataPointer %x\n\r", (unsigned)CurrentDataPointer);  
             
   }
//_________________________________________________________________________ <  

    delay_mcs(2000l); //delay to ssc get all data
 
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
// for(cnt = 0l; cnt < 10000000l; cnt++)     //hier difference 
 for(cnt = 0l; cnt < 10000l; cnt++)     //hier difference 
 { 
  status = pio_ptr->PDSR;
  if(status & 0x20) //line done
  {
//  printfp("\r Done!");
  //   printf("\n\r after load : cnt = %d",cnt);
//#ifndef PROG_PU_M_MUX    
   break;
//#endif   
   }
 } 
   /*
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l); 
   delay_mcs( 400l);
      */
   ssc0_ptr->TCMR = 0; 
    // delay_mcs(40000l); 

   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)
  
  #ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
  //   printfp("\n\rFinish load xilinx");
  #endif
    }
 
void m_load_xilinx3t (char pg , char div)
{
 // printfp("\n\rm_load_xilinx3");
//ok if hangt  return; //t
 
  unsigned int cnt;
  char* CurrentDataPointer;
 unsigned int imr;//
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
 //    printfp("Start load xilinx");
     unsigned int XilSizeToDownload  = 100000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
//     unsigned int XilSizeToDownload  = 75000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
#else   
   unsigned int XilSizeToDownload    = XilSizeToDownloadD; //0x1ffff;
#endif //no	 PROG_PRM_PCH_SPI_XIL_ETH
   
 //   printfpd("\n\rs:%d ", XilSizeToDownload);
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
#ifdef  PROG_MD310_SATI
  //   printfp("\n\rStart load xilinx");
      XilSizeToDownload  = 300000l; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
//     unsigned int XilSizeToDownload  = 75000; //XilSizeToDownloadD; //50000l;//XIL_SIZE_ETH; 
  //   XilSizeToDownload  = 57l;

#endif 
   volatile unsigned int status;
     pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

     pio_ptr->MDER = 1;    //enable multidrive for pin prog

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 0);     //line done
    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
 imr =  aic_ptr->IMR;
      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
#ifndef PROG_MD310_SATI

  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
#else
  read_dataflash ((unsigned int)XilDataAddressD7, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));

#endif

char * point = (char *)(TFTP_BUFFER_ADDRESS);
//printfp("\n\r");
//for(unsigned i1 = 0; i1 < XilSizeToDownloadD; i1++)
//{
//   printfpd("%x ", *point++);
   OperateBuffers_usart0t();
//}


 if(pg > 1)
 { 
   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
  } 
  if(pg > 2)
 { 
   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
   XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
  } 
  
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
//2. enable ssc0 clocks;    
   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC0_ENABLE;
 //no 
 //  for(;;){ 
  //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   
   
   
   
  if(!div)
   {div++;}
  AT91F_SSC_Configure (ssc0_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
#ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
   //ok        10000l, //old xilinx
           100000l, //old xilinx
#else				
          100000l, //  	(XIL_LOAD_FREQ  / div),
#endif               
			    	0,
					0, 
       //t        4,
//            0xFFFF0004, //  //  4, // 0,//   4,         //clocks + period
         0x24,//clock invert
      // 0x7 //lsb first// 0x87 // msb first     7 
          //t   0x1f  
        //t   0x9f      //msb first   32
      //t    0x87    
    
        0x7   //to test clock 
//    0x87  //tsp3
     //t 0x87   //test period     
    //  0xA7   //to test datdef = 1 

         	);	// End of 
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
  ssc0_ptr->TCMR = 0;  
    pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
 
// return; //for test

  delay_mcs(40l);      //delay to signal "prog"  , < 500 mcs
  
   for(cnt = 0; cnt < 50000l; cnt++)
   {
     status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & 0x10))
      { 
  //    printf("\n\r cnt0 = %d",cnt);
      break;
       }
   } 

  
 //  delay_mcs(2000l); //t
    pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
    status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
  // delay_mcs(4000l);  //t
   for(cnt = 0; cnt < 5000l; cnt++)
   {
     status = pio_ptr->PDSR; //line init hier one
     if(status & 0x10)
      { 
   //   printf("\n\r cnt1 = %d",cnt);
         break;
   } 
    
     
   }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
   delay_mcs(400l); 
 //t  ssc0_ptr->TCMR = 4; //try before
   ssc0_ptr->TCMR = 0x24; //try  inversion
     delay_mcs(1l);
 //  delay_mcs(400l); 
#ifdef PROG_BMD2   
 #endif // PROG_BMD2                         
 //t  AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
 //t  for(int i = 0; i < (int)(DelaySSC); i++) //delay to start ssc
 //t  {    } 
//t    ssc0_ptr->TCMR = 4;      //enabling clocks last
   AT91F_SSC_SendFrame(   //t
  ssc0_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
  
   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc0_ptr);  //new  hier before clocks to have time to start
   
  //   ssc0_ptr->TCMR = 4; //try before

//#ifdef PROG_PU_M_MUX   //test
//      XilSizeToDownload = 450000l; //for test do not load
//#endif
   
  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc0_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc0_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
              PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
   }
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
 for(cnt = 0l; cnt < 10000l; cnt++)
 { 
  status = pio_ptr->PDSR;
  if(status & 0x20) //line done
  {
  //   printf("\n\r after load : cnt = %d",cnt);
//#ifndef PROG_PU_M_MUX    
//   break;
//#endif   
   }
 } 
   ssc0_ptr->TCMR = 0; 
    delay_mcs(400l); 
 
   //disable ssc0 clocks in pmc ;    
   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC0_DISABLE;
   //3. reset ssc0  
   ssc0_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
   AT91F_PDC_Close((AT91PS_PDC) &(ssc0_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22
 
 //  delay_mcs(5000l); 
  aic_ptr->IECR = imr;
  // }  //for(;;)
  
  #ifdef	 PROG_PRM_PCH_SPI_XIL_ETH
  //   printfp("\n\rFinish load xilinx");
  #endif
  
    }
    
    
    
//___________________________________________________________________________    
    
     
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : DeviseData
* Returned Value   : none
* Comments         :
*    This function read data from devise
*
*END*----------------------------------------------------------------------*/

void DeviseData (uchar_ptr data_ptr, uint_32 * data_len)
{
    //before change can read address from pointer
    uint_32 addr;
    uint_32 data;
    uint_32 setdata;
//    int cnt;
// _io_fseek(fn_ptr, 0,IO_SEEK_SET); //set pointer bak to start of file
// _io_fseek(fx_ptr, 0,IO_SEEK_SET); //set pointer bak to start of file

    
//    char buf[] = "123456789012345678901234567890";
    char buf[32];// = "1234567890";
    uint_32 * dev_ptr;    
    char bufstop[32];
    char * stopstring;
    char * setdata_ptr;
    uchar_ptr locdata_ptr;
  
 //   uchar_ptr locdata_ptr1;
    stopstring = &bufstop[0];
    locdata_ptr =  data_ptr;
//    locdata_ptr1 =  data_ptr;

  //  data_ptr += 2;    //to remove "0x"
 //   addr = strtol(*data_ptr, &stopstring, 0); 
    strncpy(buf,(const char *)data_ptr, 11);     //? hier can crash data_ptr?
    
    
    // addr = strtol(buf, &stopstring, 0);
    addr = strtoll(buf, &stopstring, 0);
  //t
//t   addr = 0x20000000l; //to test  

  //  if(addr < 0x20000000l){for(;;){ } } //to watch  bad addr  //t16
    
 //  return; //to test  
     
     if( (addr < cs0_addr) ||
           ((addr >= cs1_addr) && (addr < cs2_addr)) ||
               (addr >= periph_addr) )
           { /* Body */
            if(addr % 4) addr--;
            if(addr % 4) addr--; 
            if(addr % 4) addr--;  
           } /* Endbody */
  //____________________________________       
 //      char *strrchr(const char *s, int c);
      setdata_ptr =  strrchr((const char *)locdata_ptr, ':');
               
               
               
               dev_ptr = (uint_32 *)addr; 
    sprintf((char *)data_ptr, "0x%08lX", addr);
    data_ptr += 10;  //if address shorter?
        
               
    if(setdata_ptr == NULL )    //reading data
    { /* Body */
    // addr = 0xabcdefab; 
  //    data_ptr += 10;  //if address shrter?
  //t  if( (addr < cs0_addr) ||
  //t         ((addr >= cs1_addr) && (addr < cs2_addr)) ||
   //t            (addr >= periph_addr) )
        if(  (addr < INTERNAL_SIZE)  ||                                               //t
  //           ((addr >= cs0_addr) && (addr < (cs0_addr + NVRAM_SIZE)))  ||       //t
             ((addr >= cs1_addr) && (addr < (cs1_addr + SDRAM_SIZE)))  ||         //t
  //           ((addr >= cs2_addr) && (addr < (cs2_addr + XILINX_SIZE))) ||      //t
             ((addr >= periph_addr) && (addr < (periph_addr + PERIPH_SIZE)))  //||
       //        ((addr >= cs3_addr) && (addr < ((uint_32)cs3_addr + (uint_32)TRANSSWITCH_SIZE)))   
             )    //t  
           { 
              data = * dev_ptr; 
        //      printf("\n\r %X", addr);
           }
    else if((addr >= cs3_addr) && (addr < ((uint_32)cs3_addr + (uint_32)TRANSSWITCH_SIZE)))
   {
#ifdef PROG_MPC155   
       data = InOED(addr & 0xFFFF);
#endif // PROG_MPC155  

#ifdef PROG_MPC4E   
       data = InOED(addr & 0xFFFF);
#endif // PROG_MPC4E 





#ifdef PROG_KTVM   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_KTVM 

#ifdef PROG_PU_M_MUX   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_PU_M_MUX 

#ifdef PROG_PU_M_V   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_PU_M_V 

#ifdef PROG_PU_M_V_A   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_PU_M_V 





#ifdef PROG_COMMUTATOR   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_PU_M_V 


#ifdef PROG_UPS   
                addr -= cs3_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fk_ptr);   // } /* Endbody */
       
#endif // PROG_UPS 




    
   }
    else
           { /* Body */
  //t            if(addr < cs1_addr)  // use cs 0
           if ((addr >= cs0_addr) && (addr < (cs0_addr + NVRAM_SIZE)))   //t
              { /* Body */
              addr -= cs0_addr;
//              if(addr < NVRAM_SIZE)
                _io_fseek(fn_ptr, addr,IO_SEEK_SET);
         //     for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 data = fgetc(fn_ptr);   // } /* Endbody */ 
              } /* Endbody */
  //t            else              //use cs2
           else if   ((addr >= cs2_addr) && (addr < (cs2_addr + XILINX_SIZE))) //t
              { /* Body */
                 addr -= cs2_addr;
               if(addr < XILINX_SIZE) _io_fseek(fx_ptr, addr,IO_SEEK_SET);
         //     for (cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                            data = fgetc(fx_ptr); // }
              } /* Endbody */
              else                    //t
#ifdef PROG_BMDN3
               if ((addr >= (cs2_addr + STEP_TO_PROV))  && 
                (addr < (cs2_addr + STEP_TO_PROV + PROV_STATE_SIZE)))//t
               {
               #ifndef PROG_BMDN6MI
                data = GetProvData(addr - cs2_addr - STEP_TO_PROV);
                #endif
               }
             else
#endif //PROG_BMDN3              
              
              
              
               data = 0x99;           //t
          } /* Endbody */  

     
       
 //   sprintf(data_ptr, "%s", buf); //   if data is longer ?  what can be 
   //  if(dev_ptr)
   //  { /* Body */
        sprintf((char *)data_ptr, "-->0x%08X", data); //   if data is longer ?  what can be 
   //  } /* Endbody */
   //  * data_len = sizeof("123456789012345678901234567890") + 10;
   //   * data_len = sizeof(addr) + 10 + 5 + 1;
                } /* Endbody */
              else
            { /* Body */
               setdata =  strtoll(++setdata_ptr, &stopstring, 0);
               
               
   //t       if( (addr < cs0_addr) ||
   //t        ((addr >= cs1_addr) && (addr < cs2_addr)) ||
   //        ((addr >= cs1_addr + 0x00800000l) && (addr < cs2_addr)) ||   //t not resolve write to programm addresses 8 MWord - all sdram 32 MWord
   //t            (addr >= periph_addr) )
        if(  (addr < INTERNAL_SIZE)  ||                                               //t
  //           ((addr >= cs0_addr) && (addr < (cs0_addr + NVRAM_SIZE)))  ||       //t
             ((addr >= cs1_addr) && (addr < (cs1_addr + SDRAM_SIZE)))  ||         //t
  //           ((addr >= cs2_addr) && (addr < (cs2_addr + XILINX_SIZE))) ||      //t
             ((addr >= periph_addr) && (addr < (periph_addr + PERIPH_SIZE)))  //||
       //        ((addr >= cs3_addr) && (addr < (cs3_addr + TRANSSWITCH_SIZE)))  
             )    //t  
           {        
              *dev_ptr = setdata;
           } 
        else if ((addr >= cs3_addr) && (addr < (cs3_addr + TRANSSWITCH_SIZE))) 
          {
#ifdef PROG_MPC155   
           OutOED((addr & 0xFFFF), setdata);
#endif // PROG_MPC155     

#ifdef PROG_MPC4E   
  //         OutOED((addr & 0xFFFF), setdata);
#endif // PROG_MPC4E 

#ifdef PROG_KTVM   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_ktvm  

#ifdef PROG_PU_M_MUX   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_ktvm  

#ifdef PROG_PU_M_V   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_ktvm  

#ifdef PROG_PU_M_V_A   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_ktvm  


#ifdef PROG_COMMUTATOR   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_ktvm  




#ifdef PROG_UPS   
          // *dev_ptr = setdata;
                 addr -= cs3_addr;
                _io_fseek(fk_ptr, addr,IO_SEEK_SET);    
                 fputc(setdata, fk_ptr); // }
#endif // PROG_UPS  



       
          }
        else
           { /* Body */
//t               if(addr < cs1_addr)  // use cs 0
             if ((addr >= cs0_addr) && (addr < (cs0_addr + NVRAM_SIZE)))   //t
              { /* Body */
              addr -= cs0_addr;
           //   if(addr < NVRAM_SIZE) 
               _io_fseek(fn_ptr, addr,IO_SEEK_SET);    
              //   for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 fputc(setdata, fn_ptr); // }
              } /* Endbody */
               else if   ((addr >= cs2_addr) && (addr < (cs2_addr + XILINX_SIZE))) //t
           //use cs2
              { /* Body */
               addr -= cs2_addr;
//               if(addr < XILINX_SIZE)
                _io_fseek(fx_ptr, addr,IO_SEEK_SET);
          //       for ( cnt = 0 ; cnt < 1000;cnt++){ /* Body */
                 fputc(setdata, fx_ptr);   // }
              } /* Endbody */
              else{ /* Body */
                 setdata = 0x88;  //to indicate wrong writing
            } /* Endbody */
          } /* Endbody */  
            
         sprintf((char *)data_ptr, "<--0x%08X", setdata);         
            
            } /* Endbody */
     * data_len = 10 + 10 + 3 + 1;

   
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : wd_init_short
* Returned Value   : none
* Comments         :
*    This function init wd counter
*
*END*----------------------------------------------------------------------*/

void wd_init_short ( void )
{
 AT91RM9200_ST_REG_STRUCT_PTR st_ptr;
 st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x4FF;  //wd  time ~4 cek
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xFFFF;  //max wd  time 5 min to use tftp
//    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x1FFF;  //max wd  time 30sec to use tftp
    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xFFF;  //max wd  time 45sec to use tftp    
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : wd_init
* Returned Value   : none
* Comments         :
*    This function init wd counter
*
*END*----------------------------------------------------------------------*/

void wd_init ( void )
{
 AT91RM9200_ST_REG_STRUCT_PTR st_ptr;
 st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x4FF;  //wd  time ~4 cek
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xFFFF;  //max wd  time 5 min to use tftp
//    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x1FFF;  //max wd  time 30sec to use tftp
    st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x2FFF;  //max wd  time 45sec to use tftp    
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : wd_deinit
* Returned Value   : none
* Comments         :
*    This function init wd counter
*
*END*----------------------------------------------------------------------*/

void wd_deinit ( void )
{
 AT91RM9200_ST_REG_STRUCT_PTR st_ptr;
 st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0x4FF;  //wd  time ~4 cek
//t st_ptr->WDMR = AT91RM9200_ST_RSTEN | AT91RM9200_ST_EXTEN | 0xFFFF;  //max wd  time 5 min to use tftp
    st_ptr->WDMR =  0x1FFF; //wd get off  //max wd  time 5 min to use tftp
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : wd_reset
* Returned Value   : none
* Comments         :
*    This function make restart of wd counter
*
*END*----------------------------------------------------------------------*/

void wd_reset ( void )
{
//#ifdef CHECK_LOSS_MEM
//static unsigned long wd_cnt;
// printfpd("\n\r %d", wd_cnt++);
//#endif
 AT91RM9200_ST_REG_STRUCT_PTR st_ptr;
 st_ptr =  (AT91RM9200_ST_REG_STRUCT_PTR)AT91RM9200_ST_BASE;
 st_ptr->CR = AT91RM9200_ST_CR_WATCHDOG_RESTART; //bit rst en - enable internal reset and counter = 1
 }

 

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : usart_select
* Returned Value   : none
* Comments         :
*    This function can get on debug _uart or usart0
* 0 - select debug uart 1 - select usart0
*
*END*----------------------------------------------------------------------*/

void usart_select (char sel)
{
   if(sel){ /* Body */
             //debug uart off 
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 30, AT91RM9200_PIO_PERIPHERAL_IO, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 31, AT91RM9200_PIO_PERIPHERAL_IO, 0);
            //usart0 on
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 17, AT91RM9200_PIO_PERIPHERAL_A, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 18, AT91RM9200_PIO_PERIPHERAL_A, 0);
         } /* Endbody */
     else{ /* Body */
            //usart0 off
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 17, AT91RM9200_PIO_PERIPHERAL_IO, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 18, AT91RM9200_PIO_PERIPHERAL_IO, 0);
            //debug uart on  
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 30, AT91RM9200_PIO_PERIPHERAL_A, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 31, AT91RM9200_PIO_PERIPHERAL_A, 0);     
         } /* Endbody */
}

void usart0_connecting (char sel)
{
   if(sel){ /* Body */
                             //usart0 on
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 17, AT91RM9200_PIO_PERIPHERAL_A, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 18, AT91RM9200_PIO_PERIPHERAL_A, 0);
         } /* Endbody */
     else{ /* Body */
            //usart0 off
            _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 17, AT91RM9200_PIO_PERIPHERAL_IO, 0);
           _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 18, AT91RM9200_PIO_PERIPHERAL_IO, 0);
                   
         } /* Endbody */
}

 

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_usart3_init
* Returned Value   : none
* Comments         :
*    This function init usart3
*
*END*----------------------------------------------------------------------*/

void m_usart3_init
   (
      void
   )
{ 
  
   if (fusart3_ptr == NULL) 
   {
  //   printf("cannot open file: uart\n");
   } else
    {
  //t     _io_set_handle(IO_STDOUT, fusart3_ptr);      //ok
  _int_disable();
      fflush (fusart3_ptr);  
   _at91rm9200_int_enable(_bsp_atevbrm9200_uart3_init.VECTOR, IRQ,       //new for int
  	  	 	      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
      			    //  AT91RM9200_AIC_SMR_PRIO_MIN );
                       AT91RM9200_AIC_SMR_PRIO_MAX );  //? 
    //   printf("\n\r__________R A D I A N___________\r"); 
   _int_enable();
       } //else
} 

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_usart2_init
* Returned Value   : none
* Comments         :
*    This function init usart2
*
*END*----------------------------------------------------------------------*/

void m_usart2_init
   (
      void
   )
{ 
  
   if (fusart2_ptr == NULL) 
   {
  //   printf("cannot open file: uart\n");
   } else
    {
  //t     _io_set_handle(IO_STDOUT, fusart2_ptr);      //ok
  _int_disable();
      fflush (fusart2_ptr);  
   _at91rm9200_int_enable(_bsp_atevbrm9200_uart2_init.VECTOR, IRQ,       //new for int
  	  	 	      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
      			    //  AT91RM9200_AIC_SMR_PRIO_MIN );
                       AT91RM9200_AIC_SMR_PRIO_MAX );  //? 
    //   printf("\n\r__________R A D I A N___________\r"); 
   _int_enable();
       } //else
} 






/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_usart0_init
* Returned Value   : none
* Comments         :
*    This function init usart0
*
*END*----------------------------------------------------------------------*/

void m_usart0_init        //rs232
   (
      void
   )
{ 
  
//   uint_32 cnt, mode, cnt1, timeout_b_ping, timeout_a_ping;
//  _mqx_int rch;
//  timeout_b_ping =  100000;
//  timeout_a_ping =  300000000;
   if (fusart0_ptr == NULL) {
  //   printf("cannot open file: uart\n");
 //     _mqx_exit(0);
   } else {
  //t    _io_set_handle(IO_STDOUT, fusart0_ptr);      //ok
    _int_disable();

      fflush (fusart0_ptr);
        
   _at91rm9200_int_enable(_bsp_atevbrm9200_uart0_init.VECTOR, IRQ,       //new for int
  	  	 	      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  	  	 	//      AT91RM9200_AIC_SMR_SRCTYPE_HLS,  //t0315
#ifdef USART0_TRY_PDC_1         
      	     AT91RM9200_AIC_SMR_PRIO_MIN ); //have some interrupts
#else            
              AT91RM9200_AIC_SMR_PRIO_MAX );  //? 
#endif              
                
              //     (AT91RM9200_AIC_SMR_PRIO_MAX -1) );  //t 
    _int_enable();

 //__________________________________________________________________   
    
    
   //   printf("\n\r>...Init USART0\r\n>");
    /*  
 //     printf("\n\nRadian SNMP Controller v_070730 usart0:\n\n\r");    //?
 //     printf("0: Cyclic read  cs1.\n\r");    //?
 //     printf("1: Cyclic write cs1.\n\r");    //?
 //     printf("2: Cyclic read  cs2.\n\r");    //?
 //     printf("3: Cyclic write cs2.\n\r");    //?
 //     printf("4: Test of TimeKeeper.\n\r");    //?
 //     printf("5: Set Time.\n\r");    //?
 //     printf("6: Set Serial Number.\n\r");    //?
 //     printf("7: Write byte to any adress.\n\r");    //?
 //     printf("8: Read byte from any adress.\n\r");    //?
 //     printf("9: Set Default settings.\n\r");    //?
 //     printf("s: Start main programm.\n\r");    //?
 //     printf(">");    //? 
           cnt =   timeout_b_ping;    //short wathdog without ping
           cnt1 = timeout_a_ping;    //long watchdog after ping
           mode = 1;
            fflush (fusart0_ptr);
            for(;;){
            if(_io_fstatus(fusart0_ptr)){ 
              rch = fgetc(fusart0_ptr);
               } 
           //t   fflush (fh_ptr);
           //   printf("%c",rch); //t
              if(mode){
                     cnt -= 1;
                     if(!(cnt % 30000)){ 
   //                  printf("          \r");
   //                  printf(">Hit any key to stop autoboot : %2d\r",(cnt /30000)); 
                     fflush (fusart0_ptr);
                          } 
                     if(!cnt)  { 
   //                  printf(" ...Start...                       ");   
                     return; 
               } 
             } 
              else{  //mode = 0
                      cnt1 -= 1;    
                 if(!cnt1) { 
     //                 printf(" End of test mode...Start...       ");   
                      return;
                  } 
               }       
      switch( rch){ 
       case '0' :    printf(" %c ...Cyclic read  cs1.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '1' :    printf(" %c ...Cyclic write cs1.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '2' :    printf(" %c ...Cyclic read  cs2.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '3' :    printf(" %c ...Cyclic write cs2.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;  //?
       case '4' :    printf(" %c ...Test of TimeKeeper.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '5' :    printf(" %c ...Set Time.                       \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '6' :    printf(" %c ...Set Serial Number.              \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '7' :    printf(" %c ...Write byte to any adress.       \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '8' :    printf(" %c ...Read byte from any adress.      \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '9' :    printf(" %c ...Set Default settings.           \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break; //?
       case 's' :    printf(" %c ...Start...                           ", rch);  return;  //?
       default  :    ;//printf(" ...Start...\n\r");                    return; // printf("\r> %d", cnt);  
       }
              fflush (fusart0_ptr);
     }  //for
  
  */ } //else
 } 


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_usart1_init
* Returned Value   : none
* Comments         :
*    This function init usart1
*
*END*----------------------------------------------------------------------*/

void m_usart1_init     //rs485
   (
      void
   )
{ 
  
 //  uint_32 cnt, mode, cnt1, timeout_b_ping, timeout_a_ping;
//  _mqx_int rch;
//  timeout_b_ping =  100000;
//  timeout_a_ping =  300000000;
  if (fusart1_ptr == NULL) {
    } else {
  //t    _io_set_handle(IO_STDOUT, fusart1_ptr);      //ok
     _int_disable();

      fflush (fusart1_ptr);
       
  //	_int_install_isr(_bsp_atevbrm9200_uart1_init.VECTOR,   //t
  //   (void _CODE_PTR_)_at91rm9200_usart1_int_isr, NULL);   //t

     
       
   _at91rm9200_int_enable(_bsp_atevbrm9200_uart1_init.VECTOR, IRQ,       //new for int
 //  _at91rm9200_int_enable(_bsp_atevbrm9200_uart1_init.VECTOR, FIQ,       //try fiq
   	  	 	      AT91RM9200_AIC_SMR_SRCTYPE_LLS,
  //                   AT91RM9200_AIC_SMR_SRCTYPE_HLS,
   //                 AT91RM9200_AIC_SMR_SRCTYPE_NET,       //bad!
                    
   //
    //                AT91RM9200_AIC_SMR_SRCTYPE_PET,    //t

      		//  	      AT91RM9200_AIC_SMR_PRIO_MIN );   //t
                   AT91RM9200_AIC_SMR_PRIO_MAX );  //? 
             //      AT91RM9200_AIC_SMR_PRIO_MAX );  //? 

        _int_enable();

   //    printf("\n\r__________R A D I A N___________070927\r");
   //    printf("\n\r>...Init USART1\r\n>");

    /*  
 //     printf("\n\nRadian SNMP Controller v_070730 usart1:\n\n\r");    //?
 //     printf("0: Cyclic read  cs1.\n\r");    //?
 //     printf("1: Cyclic write cs1.\n\r");    //?
 //     printf("2: Cyclic read  cs2.\n\r");    //?
 //     printf("3: Cyclic write cs2.\n\r");    //?
 //     printf("4: Test of TimeKeeper.\n\r");    //?
 //     printf("5: Set Time.\n\r");    //?
 //     printf("6: Set Serial Number.\n\r");    //?
 //     printf("7: Write byte to any adress.\n\r");    //?
 //     printf("8: Read byte from any adress.\n\r");    //?
 //     printf("9: Set Default settings.\n\r");    //?
 //     printf("s: Start main programm.\n\r");    //?
 //     printf(">");    //? 
           cnt =   timeout_b_ping;    //short wathdog without ping
           cnt1 = timeout_a_ping;    //long watchdog after ping
           mode = 1;
            fflush (fusart1_ptr);
            for(;;){
            if(_io_fstatus(fusart1_ptr)){ 
              rch = fgetc(fusart1_ptr);
               }           //t   fflush (fh_ptr);
                   if(mode){
                     cnt -= 1;
                     if(!(cnt % 30000)){ 
                  //   printf("          \r");
                  //   printf(">Hit any key to stop autoboot : %2d\r",(cnt /30000)); 
                     fflush (fusart1_ptr);
                          } 
                     if(!cnt)  { 
                  //   printf(" ...Start...                       ");   
                     return; 
               } 
             } 
              else{  //mode = 0
                      cnt1 -= 1;    
                 if(!cnt1) { 
                      printf(" End of test mode...Start...       ");   
                      return;
                  } 
               }       
      switch( rch){ 
       case '0' :    printf(" %c ...Cyclic read  cs1.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '1' :    printf(" %c ...Cyclic write cs1.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '2' :    printf(" %c ...Cyclic read  cs2.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '3' :    printf(" %c ...Cyclic write cs2.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;  //?
       case '4' :    printf(" %c ...Test of TimeKeeper.             \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '5' :    printf(" %c ...Set Time.                       \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '6' :    printf(" %c ...Set Serial Number.              \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '7' :    printf(" %c ...Write byte to any adress.       \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;   //?
       case '8' :    printf(" %c ...Read byte from any adress.      \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break;    //?
       case '9' :    printf(" %c ...Set Default settings.           \r>", rch); mode = 0;  cnt1 = timeout_a_ping;      break; //?
       case 's' :    printf(" %c ...Start...                           ", rch);  return;  //?
       default  :    ;//printf(" ...Start...\n\r");                    return; // printf("\r> %d", cnt);  
       }
              fflush (fusart1_ptr);
     }  //for
     */
   } //else
 } 

 
 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _irq3_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 IRQ3 ISR handler.
*
*END*----------------------------------------------------------------------*/

void _irq3_isr
   (
         pointer dummy
   )
{  
   _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
    Stephany8++;
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _irq1_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 IRQ1 ISR handler.
*
*END*----------------------------------------------------------------------*/

void _irq1_isr
   (
         pointer dummy
   )
{  
 my_int_disable_irq1();  //added
 
#ifdef IncEmbSerialMD34AVT
   emb_use_irq1();
#endif

#ifdef PROG_DTVM
   emb_use_irq1();
#endif
   _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
    Stephany10++;
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _fiq_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 FIQ ISR handler.
*
*END*----------------------------------------------------------------------*/

void _fiq_isr
   (
         pointer dummy
   )
{   
   _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_FIQ); //set "F" (disable fiq) bit to clear interrupt in level mode!
    Stephany12++;
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _spu_isr
* Returned Value   : none
* Comments         :
*    This routine is used as the AT91RM9200 spurious ISR handler.
*
*END*----------------------------------------------------------------------*/

void _spu_isr
   (
         pointer dummy
   )
{   
   AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = 
                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;
      _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ); //set "I" (disable irq) bit to clear interrupt in level mode!
       Stephany13++;
      /* End of Interrupt */
	aic_ptr->EOICR = 0xFF; 
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_cs_init
* Returned Value   : none
* Comments         :
*    This routine is used to init and work witch cs0 and cs2 devise.
*
*END*----------------------------------------------------------------------*/

void m_cs_init
   (
   )
{
 uint_32 tmp;
 
// cs0: static ram bus 8 bit; cs2: xilinx  8 bit
AT91RM9200_MC_REG_STRUCT_PTR mc_ptr;   //memory controller
 	mc_ptr = (AT91RM9200_MC_REG_STRUCT_PTR) AT91RM9200_MC_BASE;
	
//	mc_ptr->RCR = 0x00000001;
   tmp = mc_ptr->EBI.CSA;
   mc_ptr->EBI.CSA = tmp & 0xFFFFFFFEl; // cs0 : to smc; cs2 - only as cs can used
   
//t   mc_ptr->EBI.SMC.CSR[0] =0x77004F7Fl; //cs0 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold
   mc_ptr->EBI.SMC.CSR[0] =0x12014383l; //cs0 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold
 //t  mc_ptr->EBI.SMC.CSR[2] =0x77004F7Fl; //cs2 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold  
 //t1810  mc_ptr->EBI.SMC.CSR[2] =0x12014183l; //cs2 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold  
/*
#ifndef PROG_MPC34  
   mc_ptr->EBI.SMC.CSR[2] =0x12014383l; //cs2 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold  
//   mc_ptr->EBI.SMC.CSR[0] =0x00004000l; //cs0 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold
//   mc_ptr->EBI.SMC.CSR[2] =0x00004000l; //cs2 : 128 wait states; wait line disable; 8 bit; standard protokol ; standart address;maximum RW setup  and RW hold  
#else // no PROG_MPC34
    mc_ptr->EBI.SMC.CSR[2] =0x77014383l; //cs2 : maximum delay  
#endif
  */
  
   // mc_ptr->EBI.SMC.CSR[2] = 0x77014383l;
//151021     mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
     mc_ptr->EBI.SMC.CSR[2] = 0x32014384l;
     
#ifdef PROG_BMD155
  //  mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 // mc_ptr->EBI.SMC.CSR[2] = 0x770343FFl;
//151021     mc_ptr->EBI.SMC.CSR[2] = 0x12014383l;    //ok
     mc_ptr->EBI.SMC.CSR[2] = 0x32014383l;    //ok
 //ok  mc_ptr->EBI.SMC.CSR[2] = 0x12014381l; //ok wait = 1;
 //t  mc_ptr->EBI.SMC.CSR[2] = 0x12004383l;    // acss = 0 bad
  //    mc_ptr->EBI.SMC.CSR[2] = 0x00014383l;   //rwhold = 0 rwsetup = 0;    bad
 //led ok  mc_ptr->EBI.SMC.CSR[2] = 0x77014383l;   //rwhold = 7, rwsetup = 7 ok
  // mc_ptr->EBI.SMC.CSR[2] = 0x70014383l;   //rwhold = 7, rwsetup = 0 ok
  // mc_ptr->EBI.SMC.CSR[2] = 0x70014387l;  //no work!

  //  mc_ptr->EBI.SMC.CSR[2] = 0x72014387l;  // work!  with errors
 //    mc_ptr->EBI.SMC.CSR[2] = 0x77014387l;  //ok
   //    mc_ptr->EBI.SMC.CSR[2] = 0x77014381l;   //bad
  //     mc_ptr->EBI.SMC.CSR[2] = 0x72014381l;  //bod!!!!!
   //led bad     mc_ptr->EBI.SMC.CSR[2] = 0x12014381l; 

    // mc_ptr->EBI.SMC.CSR[2] = 0x120143ffl; //t

     //t  mc_ptr->EBI.SMC.CSR[2] = 0x00004000l;
  // mc_ptr->EBI.SMC.CSR[2] = 0x00004080l;
#endif //PROG_BMD155
/*
#ifdef PROG_COMMUTATOR
  //  mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 // mc_ptr->EBI.SMC.CSR[2] = 0x770343FFl;
     mc_ptr->EBI.SMC.CSR[2] = 0x12014383l;    //ok
 //ok  mc_ptr->EBI.SMC.CSR[2] = 0x12014381l; //ok wait = 1;
 //t  mc_ptr->EBI.SMC.CSR[2] = 0x12004383l;    // acss = 0 bad
  //    mc_ptr->EBI.SMC.CSR[2] = 0x00014383l;   //rwhold = 0 rwsetup = 0;    bad
 //led ok  mc_ptr->EBI.SMC.CSR[2] = 0x77014383l;   //rwhold = 7, rwsetup = 7 ok
  // mc_ptr->EBI.SMC.CSR[2] = 0x70014383l;   //rwhold = 7, rwsetup = 0 ok
  // mc_ptr->EBI.SMC.CSR[2] = 0x70014387l;  //no work!

  //  mc_ptr->EBI.SMC.CSR[2] = 0x72014387l;  // work!  with errors
 //    mc_ptr->EBI.SMC.CSR[2] = 0x77014387l;  //ok
   //    mc_ptr->EBI.SMC.CSR[2] = 0x77014381l;   //bad
  //     mc_ptr->EBI.SMC.CSR[2] = 0x72014381l;  //bod!!!!!
   //led bad     mc_ptr->EBI.SMC.CSR[2] = 0x12014381l; 

    // mc_ptr->EBI.SMC.CSR[2] = 0x120143ffl; //t

     //t  mc_ptr->EBI.SMC.CSR[2] = 0x00004000l;
  // mc_ptr->EBI.SMC.CSR[2] = 0x00004080l;
#endif //PROG_BMD155

      */
#ifdef PROG_BMDN
#ifndef NWAIT_DISABLE

 //151021    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;    //enable
     mc_ptr->EBI.SMC.CSR[2] = 0x32014384l; //151021   //enable
  //   mc_ptr->EBI.SMC.CSR[2] = 0x32014386l;    //ok
    //   mc_ptr->EBI.SMC.CSR[2] = 0x77014387l; //110723

    //    mc_ptr->EBI.SMC.CSR[2] = 0x12014303l;   //t
    
#else 
      mc_ptr->EBI.SMC.CSR[2] = 0x27014304l;   //disable
      
#endif      


#endif //PROG_BMDN

#ifdef PROG_BUKU
  //  mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 // mc_ptr->EBI.SMC.CSR[2] = 0x770343FFl;
  //t   mc_ptr->EBI.SMC.CSR[2] = 0x12014383l;
 //151021       mc_ptr->EBI.SMC.CSR[2] = 0x12014303l;   //t
        mc_ptr->EBI.SMC.CSR[2] = 0x32014303l;   //t
     //t  mc_ptr->EBI.SMC.CSR[2] = 0x00004000l;
  // mc_ptr->EBI.SMC.CSR[2] = 0x00004080l;
#endif //PROG_BUKU

#ifdef PROG_MPC155
  //  if(CheckNWait())
  //  {
#ifndef TEST_MPC155  
 //151021    mc_ptr->EBI.SMC.CSR[3] = 0x12013384l;   //16 bit wide 16 bit access
     mc_ptr->EBI.SMC.CSR[3] = 0x32013384l;   //16 bit wide 16 bit access
  //  }
  //  else
  //  {
#else  
     mc_ptr->EBI.SMC.CSR[3] = 0x12013304l;   //test disable NWait
#endif     
   // }
 //    mc_ptr->EBI.SMC.CSR[3] = 0x12013304l;   //16 bit wide 16 bit access
#endif //PROG_MP155

#ifdef PROG_MPC4E
  //  if(CheckNWait())
  //  {
#ifndef TEST_MPC4E  
     mc_ptr->EBI.SMC.CSR[3] = 0x12013384l;   //16 bit wide 16 bit access
  //  }
  //  else
  //  {
#else  
     mc_ptr->EBI.SMC.CSR[3] = 0x12013384l;   //test disable NWait
#endif     
   // }
 //    mc_ptr->EBI.SMC.CSR[3] = 0x12013304l;   //16 bit wide 16 bit access
#endif //PROG_MPC4E

 //  _io_mem_install("nvram", NVRAM_BASE, NVRAM_FILE_SIZE);    //this work bad
   _io_mem_install("nvram", NVRAM_BASE, NVRAM_SIZE);
   _io_mem_install("sdram", SDRAM_BASE, SDRAM_SIZE);
    
   _io_mem_install("xilinx", XILINX_BASE, XILINX_SIZE);
   
   _io_mem_install("modem",  &TFTP_Buffer[0],  TFTP_BUFFER_SIZE);

   
#ifdef PROG_MPC155   
   _io_mem_install("oed", OEDBASE, OED_SIZE);
#endif // PROG_MPC155 

#ifdef PROG_MPC4E   
   _io_mem_install("oed", OEDBASE, OED_SIZE);
#endif // PROG_MPC4E 






 

#ifdef PROG_KTVM  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 //0916   mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
//090604    mc_ptr->EBI.SMC.CSR[2] = 0x37014384l;   //0916
    
     mc_ptr->EBI.SMC.CSR[2] = 0x32014386l;
    
//    mc_ptr->EBI.SMC.CSR[3] = 0x12014304l;   //8 bit wide 8 bit access nwait disable
//0916    mc_ptr->EBI.SMC.CSR[3] = 0x22014304l;   //8 bit wide 8 bit access nwait disable
    mc_ptr->EBI.SMC.CSR[3] = 0x37014304l;   //8 bit wide 8 bit access nwait disable
    
    
   _io_mem_install("ktvm", KTVMBASE, KTVM_SIZE);
    fk_ptr = (pointer)_io_fopen1("ktvm", 0); //0 - not block mode

   
#endif // PROG_KTVM   

#ifdef PROG_DTVM  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 //0916   mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
 //090608   mc_ptr->EBI.SMC.CSR[2] = 0x37014384l;   //0916
     mc_ptr->EBI.SMC.CSR[2] = 0x32014386l;   //090608

    
//    mc_ptr->EBI.SMC.CSR[3] = 0x12014304l;   //8 bit wide 8 bit access nwait disable
//0916    mc_ptr->EBI.SMC.CSR[3] = 0x22014304l;   //8 bit wide 8 bit access nwait disable
//    mc_ptr->EBI.SMC.CSR[3] = 0x37014304l;   //8 bit wide 8 bit access nwait disable
    
    
//   _io_mem_install("ktvm", KTVMBASE, KTVM_SIZE);
//    fk_ptr = (pointer)_io_fopen1("ktvm", 0); //0 - not block mode

   
#endif // PROG_DTVM   

#ifdef PROG_PU_M  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
  
#ifndef TEST_PU_M 
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
//    mc_ptr->EBI.SMC.CSR[3] = 0x12014304l;   //8 bit wide 8 bit access nwait disable
#else
    mc_ptr->EBI.SMC.CSR[2] = 0x27014304l; //without ready
#endif

#endif // PROG_PU_M

 
   

#ifdef PROG_PU_M100  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
  
#ifndef TEST_PU_M 
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
//    mc_ptr->EBI.SMC.CSR[3] = 0x12014304l;   //8 bit wide 8 bit access nwait disable
#else
    mc_ptr->EBI.SMC.CSR[2] = 0x27014304l; //without ready
#endif


 
   
#endif // PROG_PU_M100 

#ifdef PROG_PU_MSAT  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
  
#ifndef TEST_PU_M 
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
//    mc_ptr->EBI.SMC.CSR[3] = 0x12014304l;   //8 bit wide 8 bit access nwait disable
#else
    mc_ptr->EBI.SMC.CSR[2] = 0x27014304l; //without ready
#endif

   
#endif // PROG_PU_MSAT 





#ifdef PROG_PU_M_MUX  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
//     mc_ptr->EBI.SMC.CSR[2] = 0x77034384l;  //t130804

    mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
      
 
  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_PU_M_MUX   

#ifdef PROG_PU_M_V  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
    mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
      
 
  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_PU_M_V  

#ifdef PROG_PU_M_V_A  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
 //   mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
 
   // mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;   //t130712
   //  mc_ptr->EBI.SMC.CSR[2] = 0x77034384l;
    
    mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
    // mc_ptr->EBI.SMC.CSR[0] =0x12014383l;  
 
  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_PU_M_V  


#ifdef PROG_PU_M710    //md34e
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
 //121115   mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
 
//ok mc_ptr->EBI.SMC.CSR[2] = 0x770343ffl;
 mc_ptr->EBI.SMC.CSR[2] = 0x77034384l;


  //   mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
      
 
//  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
//    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_PU_M710   
 

#ifdef PROG_COMMUTATOR  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
//121122    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
    mc_ptr->EBI.SMC.CSR[2] = 0x77034384l;  //121122 as in md34e

  //  mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
     mc_ptr->EBI.SMC.CSR[3] = 0x77034384l;   //121122 as in md34e
 
  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_PU_M_V   


#ifdef PROG_UPS  
//t    mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;
  //  mc_ptr->EBI.SMC.CSR[2] = 0x22014384l;
    mc_ptr->EBI.SMC.CSR[2] = 0x27014384l;
    mc_ptr->EBI.SMC.CSR[3] = 0x27014384l;   //8 bit wide 8 bit access nwait disable
      
 
  _io_mem_install("xil2", XIL2_BASE, XIL2_SIZE);
    fk_ptr = (pointer)_io_fopen1("xil2", 0); //0 - not block mode
   
#endif // PROG_UPS   



  

#ifdef MAKET_PLATA
      mc_ptr->EBI.SMC.CSR[2] = 0x27014304l;   //NWAIT diasable
#endif // MAKET_PLATA

//#ifdef PROG_PRM_PCH_SPI_XIL
//    mc_ptr->EBI.SMC.CSR[2] = 0x27014304l; //without ready
//#endif


   
   
 //try file use  
   
    fn_ptr = (pointer)_io_fopen1("nvram", 0); //0 - not block mode
      if (fn_ptr == NULL) {
#ifndef USART0_TRY_PDC_1T      
     printf("cannot open file:nvram\t\n");
#endif     
 //t0310     _mqx_exit(0);
   }
    fs_ptr = (pointer)_io_fopen1("sdram", 0); //0 - not block mode
      if (fn_ptr == NULL) {
#ifndef USART0_TRY_PDC_1T      
     printf("cannot open file:sdram\t\n");
#endif     
 //t0310     _mqx_exit(0);
   }
   
    fx_ptr = (pointer)_io_fopen1("xilinx", 0); //0 - not block mode
     if (fx_ptr == NULL) {
#ifndef USART0_TRY_PDC_1T     
     printf("cannot open file:xilinx\n");
#endif     
//t0310     _mqx_exit(0);
   }
 //   for(;;){ /* Body */      //to test
    //  fputc(0x55, fn_ptr); 
   //   fputc(0x55, fx_ptr); 
 //     fgetc(fn_ptr); 
 //     fgetc(fx_ptr); 

    
 //   _io_fseek(fn_ptr, 0,IO_SEEK_SET); //set pointer bak to start of file
 //   _io_fseek(fx_ptr, 0,IO_SEEK_SET); //set pointer bak to start of file
//    } /* Endbody */
 }


 
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : at91_spi_ctl
* Returned Value   : none
* Comments         :
*    This routine is used to ctl to spi devises.
*
*END*----------------------------------------------------------------------*/

uint_32 at91_spi_ctl
   (
          pointer _PTR_              io_info_ptr_ptr,
          
            uint_32                    any_value,

           uint_32_ptr                    any_value1
   
   )
{
      AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
      return  spi_ptr->SR;   //startus register
}

 
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : at91_spi_write
* Returned Value   : none
* Comments         :
*    This routine is used to write to spi devises.
*
*END*----------------------------------------------------------------------*/

uint_32 at91_spi_write
   (
         pointer _PTR_              io_info_ptr_ptr,

      /* [IN] the rest of the name of the device opened */
      char_ptr                   open_name_ptr,
      
      uint_32                    val

   )
{
      AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
  //    spi_ptr->TDR = val & 0xf; //8 bit cs0
         spi_ptr->TDR = ((val & 0xfl) | 0x10000l); //8 bit cs1
      return 0;  
    
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : at91_spi_read
* Returned Value   : none
* Comments         :
*    This routine is used to read from spi devises.
*
*END*----------------------------------------------------------------------*/

char at91_spi_read
   (
      /* [OUT] the address to store device specific information */
      pointer _PTR_              io_info_ptr_ptr,

      /* [IN] the rest of the name of the device opened */
      char_ptr                   open_name_ptr,
      
        _mqx_int                timeout
  
   )
{
      AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
      while(!(spi_ptr->SR & 1)){ /* Body */
   } /* Endbody */
      return(spi_ptr->RDR & 0xffl); //8 bit
   //   return 0;  
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : at91_spi_deinit
* Returned Value   : none
* Comments         :
*    This routine is used to deinit and work witch spi devises.
*
*END*----------------------------------------------------------------------*/

uint_32 at91_spi_deinit
   (
      /* [IN] the initialization information for the device being opened */
      AT91RM9200_SERIAL_INIT_STRUCT_PTR io_init_ptr,

      /* [IN] the address of the device specific information */
      AT91RM9200_SERIAL_INFO_STRUCT_PTR io_info_ptr
   )
{

      AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
      spi_ptr->CR = 2l; //spi disable


   return 0;  
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : at91_spi_init
* Returned Value   : none
* Comments         :
*    This routine is used to init and work witch spi devises.
*
*END*----------------------------------------------------------------------*/

uint_32 at91_spi_init
   (
          /* [IN] the initialization information for the device being opened */
      AT91RM9200_SPI_INIT_STRUCT_PTR spi_init_ptr,

      /* [OUT] the address to store device specific information */
   //   pointer _PTR_              io_info_ptr_ptr,

      /* [IN] the rest of the name of the device opened */
      char_ptr                   open_name_ptr
   )
{
    //   uint_32 tmp;
      AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;
   //   spi_ptr->CR |= 0x80l; //spi reset
   //   spi_ptr->CR &= ~0x80l; //spi reset
      spi_ptr->CR = 1l; //spi enable
     // spi_ptr->MR  = 0xFF000009l; //master;mck /32; max delay; spi cs0 enable
   //t    spi_ptr->MR  = 0x00010001l; //master;mck/1; max delay; spi cs1 enable
          spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
     //tt     spi_ptr->MR  = 0x00010107l; //master;variable perpireall; mck/1; spi cs1 enable
    // tmp = spi_ptr->MR;
     //      spi_ptr->MR  = 0x00000003l; //master;variable perpireall; mck/1; spi cs1 enable
  //t    spi_ptr->MR = tmp | 0x10002l;
      //     spi_ptr->MR  = 0x00010007l; //master;variable perpireall; mck/1; spi cs1 enable
     // spi_ptr->CSR[0] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs0
    //t  spi_ptr->CSR[0] =0xffffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //t  spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
     //    spi_ptr->CSR[0] =0xffff00l; // 8 bit baud rate / 255   ; max delays ; - cs1
        spi_ptr->CSR[1] =0x0f0f0200l; // 8 bit baud rate / 255   ; max delays ; - cs1

    //   spi_ptr->CSR[1] =0x0l; // 8 bit baud rate / 255   ; max delays ; - cs1
   //   spi_ptr->IER  = 0xFFl; //interrupt enable
   
   return 0;  
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : m_spi_init
* Returned Value   : none
* Comments         :
*    This routine is used to init and work witch spi devises.
*
*END*----------------------------------------------------------------------*/

void m_spi_init
   (
   )
{
    pointer fs_ptr;
    AT91RM9200_SPI_INIT_STRUCT_PTR spi_init_ptr;
    AT91RM9200_SPI_REG_STRUCT_PTR spi_ptr =   (AT91RM9200_SPI_REG_STRUCT_PTR)AT91RM9200_SPI_BASE;

      _io_spi_polled_install(
      (char_ptr)"spi0", 
      (uint_32 (_CODE_PTR_)(pointer, char _PTR_))at91_spi_init,
      (uint_32 (_CODE_PTR_)(pointer, pointer))at91_spi_deinit,
      (char (_CODE_PTR_)(pointer, char _PTR_, _mqx_int))at91_spi_read,
      (uint_32 (_CODE_PTR_)(pointer, char _PTR_, uint_32))at91_spi_write,
      (uint_32 (_CODE_PTR_)(pointer, uint_32, uint_32_ptr))at91_spi_ctl,
      &spi_init_data);
       //  (pointer)at91_spi_init_data);
       
        at91_spi_init(spi_init_ptr, "spi1");
       fs_ptr = (pointer)_io_fopen1("spi1", 0); //  
  //     _io_set_handle(IO_STDOUT, fs_ptr);
//     for(;;){ /* Body */
 //      fputc(0x55, fs_ptr);
        if(spi_ptr->SR & 0x80l)  { /* Body */
             at91_spi_write(fs_ptr, "spi1", '1');
  //        } /* Endbody */
 //     printf("1");
 //    fgetc(fs_ptr);
     } /* Endbody */
}
void AT91F_DataflashPrintInfo(void)
{
	int i;
   //   _io_set_handle(IO_STDOUT, fh_ptr);  
        printfp("\n\n\rSearch DataFlashes : \n\r");
	for (i = 0; i < CFG_MAX_DATAFLASH_BANKS; i++) {
		if (dataflash_info[i].id != 0) {
			printfp ("DataFlash:");
			switch (dataflash_info[i].id) {
			case AT45DB161:
//#ifndef USART0_TRY_PDC_1T         
				printfp ("AT45DB161\n\r");
//#endif            
				break;

			case AT45DB321:
//#ifndef USART0_TRY_PDC_1T         
				printfp ("AT45DB321\n\r");
//#endif            
				break;

			case AT45DB642:
//#ifndef USART0_TRY_PDC_1T         
				printf ("AT45DB642\n\r");
//#endif            
				break;
			case AT45DB128:
//#ifndef USART0_TRY_PDC_1T         				
				printfp ("AT45DB128\n\r");
//#endif            
				break;
            
          case AT45DB641E:
           printfp ("AT45DB641E\n\r");
				break;


			}
		}
	}
}
void AT91F_DataflashCheck(void)
{

    // unsigned int DeviceAddress = 0xC0700000l;
     unsigned int DeviceAddress = 0xC083fbdfl;
     unsigned int AddressToDownload = 0x21000001; //upper 16Mx32 +1
     unsigned int AddressToKeep = 0x21000000; //upper 16Mx32
     unsigned char value = 0xaa;
     unsigned int SizeToDownload = 1;
     unsigned int i;
 //	crc1 = 0;
 //		pAT91->CRC32((const unsigned char *)AddressToDownload, SizeToDownload , &crc1);
      read_dataflash (DeviceAddress, SizeToDownload, (char *)(AddressToKeep));   //keep data value
 
      (*(char *)(AddressToDownload)) = value;
		// write the dataflash
		write_dataflash (DeviceAddress, AddressToDownload, SizeToDownload);
		// clear the buffer before read
		for(i=0; i < SizeToDownload; i++)
			*(unsigned char *)(AddressToDownload + i) = 0;
					
		// Read dataflash page in TestBuffer
	//	read_dataflash (DeviceAddress, SizeToDownload, (char *)AddressToDownload);
    	read_dataflash (DeviceAddress, SizeToDownload, (char *)AddressToDownload);

		printf("Verify Dataflash: ");	    
       
       //		crc2 = 0;
				
//		pAT91->CRC32((const unsigned char *)AddressToDownload, SizeToDownload , &crc2);
//		if (crc1 != crc2)
     if ( ((*(char *)(AddressToDownload)) & 0xff) != value){ 
 #ifndef USART0_TRY_PDC_1T    
        		 	printf("Failed\r\n");
             printf("\n\r in flash = %X",  ((char *)(AddressToDownload)));
             printf("\n\r need = %X", value);
#endif             
     //___________check again       
            
        write_dataflash (DeviceAddress, AddressToDownload, SizeToDownload);
        
		// clear the buffer before read
		for(i=0; i < SizeToDownload; i++)
			*(char *)(AddressToDownload + i) = 0;
         read_dataflash (DeviceAddress, SizeToDownload, (char *)(AddressToDownload));

		printf("\r\nCheck Again: ");	
        if (( (*( char *)(AddressToDownload)) & 0xff) != value)  { 
#ifndef USART0_TRY_PDC_1T        
              		printf("\n\r Failed\r\n");
            printf("\n\r in memory = %X",  (*(char *)(AddressToDownload)));
            printf("\n\r in flash = %X", value);
#endif            
            } 

     //___________check again
         } 
  	
		else
#ifndef USART0_TRY_PDC_1T      
		 	printf("OK\r\n");
          printf("\n\r in flash = %X",  (*(char *)(AddressToDownload)));
          printf("\n\r need = %X", value);
#endif         
      write_dataflash (DeviceAddress, AddressToKeep, SizeToDownload);   //keep data value
     
} 
 
  
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :m_init_remote_usart1
* Returned Value   :none
* Comments         :
*    This routine is used to init pointers for usart1
*END*----------------------------------------------------------------------*/
 
void m_init_remote_usart1()
{
 CommandSize = 0;
 BufferSize = ACT_BUFFER_SIZE1;
//int 	RBuffSize = 128; //as in .h file
	for (int i = 0; i < BufferSize; i++)
	{
	 RBuff[i] = 0;
	}
	pRBuff = &RBuff[0];
//int	TBuffSize = 128; //as in .h file
	for (i = 0; i < BufferSize; i++)
	{
	 TBuff[i] = 0;
	}
	pTBuff = &TBuff[0];	
	IdCommand = 0;
   step = 0;
   
//   _io_set_handle(IO_STDOUT, fusart1_ptr); //TEMPORARY!!!

}
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :m_init_remote_snmp
* Returned Value   :none
* Comments         :
*    This routine is used to init pointers for snmp
*END*----------------------------------------------------------------------*/
 
void m_init_remote_snmp()
{
 CommandSizeS = 0;
// BufferSizeS = 128;
 BufferSizeS = ACT_BUFFER_SIZE1;

//int 	RBuffSize = 128; //as in .h file
  //int	TBuffSize = 128; //as in .h file
	for (int i = 0; i < BufferSizeS; i++)
	{
	 TBuffS[i] = 0;
	}
	pTBuffS = &TBuffS[0];	
	IdCommandS = 0;
   
//   _io_set_handle(IO_STDOUT, fusart1_ptr); //TEMPORARY!!!

}


 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :m_init_remote_usart0
* Returned Value   :none
* Comments         :
*    This routine is used to init pointers for usart0
*END*----------------------------------------------------------------------*/
 
void m_init_remote_usart0()
{
 CommandSize0 = 0;
 BufferSize0 =  ACT_BUFFER_SIZE1; 
 pTBuff0_init();
 pRBuff0_init();

 //int 	RBuffSize = 128; //as in .h file
	for (int i = 0; i < BufferSize0; i++)
	{
	 RBuff0[i] = 0;
	}
 //	pRBuff0 = &RBuff0[0];
//int	TBuffSize = 128; //as in .h file
	for (i = 0; i < BufferSize0; i++)
	{
	 TBuff0[i] = 0;
	}
    //	pTBuff0 = &TBuff0[0];	
	IdCommand0 = 0;
   step0 = 0;
   
//   _io_set_handle(IO_STDOUT, fusart1_ptr); //TEMPORARY!!!
 //  pTBuff0_cnt = 0;
 //  pRBuff0_cnt = 0;
}
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :m_init_remote_usart3
* Returned Value   :none
* Comments         :
*    This routine is used to init pointers for usart3
*END*----------------------------------------------------------------------*/
 
void m_init_remote_usart3()
{
 CommandSize3 = 0;
 BufferSize3 = ACT_BUFFER_SIZE1;
//int 	RBuffSize = 128; //as in .h file
	for (int i = 0; i < BufferSize3; i++)
	{
	 RBuff3[i] = 0;
	}
	pRBuff3 = &RBuff3[0];
//int	TBuffSize = 128; //as in .h file
	for (i = 0; i < BufferSize3; i++)
	{
	 TBuff3[i] = 0;
	}
	pTBuff3 = &TBuff3[0];	
	IdCommand3 = 0;
   step3 = 0;
   
//   _io_set_handle(IO_STDOUT, fusart1_ptr); //TEMPORARY!!!

}

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :m_init_remote_usart2
* Returned Value   :none
* Comments         :
*    This routine is used to init pointers for usart2
*END*----------------------------------------------------------------------*/
 
void m_init_remote_usart2()
{

 CommandSize2 = 0;
 BufferSize2 = ACT_BUFFER_SIZE1;
//int 	RBuffSize = 128; //as in .h file
	for (int i = 0; i < BufferSize2; i++)
	{
	 RBuff2[i] = 0;
	}
	pRBuff2 = &RBuff2[0];
//int	TBuffSize = 128; //as in .h file
	for (i = 0; i < BufferSize2; i++)
	{
	 TBuff2[i] = 0;
	}
	pTBuff2 = &TBuff2[0];	
	IdCommand2 = 0;
   step2 = 0;
   
//   _io_set_handle(IO_STDOUT, fusart1_ptr); //TEMPORARY!!!

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit3c
* Returned Value   :none
* Comments         :
*    transmit data for port of EmbIsr  485
*END*----------------------------------------------------------------------*/
void Transmit3c(unsigned char tch)
{
#ifndef PULT_USART2
  fputc(tch, fusart3_ptr); 
#else  
 // printfpd("__>%c",tch);
  Transmit2c(tch);
 //Transmit2c(tch);
// ToPdcTu0(tch);

#endif   //PULT_USART2
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit1c
* Returned Value   :none
* Comments         :
*    transmit data for port of EmbIsr  485
*END*----------------------------------------------------------------------*/
 
void Transmit1c(unsigned char tch)
{
#ifndef USART1_TRY_PDC_1T
         fputc(tch, fusart1_ptr); 
#else
         ToPdcTu1(tch);

#endif         
}


#ifdef USE_USART2
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit2c
* Returned Value   :none
* Comments         :
*    transmit data for port usart2
*END*----------------------------------------------------------------------*/
 
void Transmit2c(unsigned char tch)
{
#ifndef USART2_TRY_PDC_1T
         fputc(tch, fusart2_ptr); 
#else
         ToPdcTu2(tch);
         OperateBuffers_usart2t(); //120426 to have delay betveen impulses
#endif         
}

#endif //USE_USART2


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit00c
* Returned Value   :none
* Comments         :
*    transmit data for port of EmbIsr  232
*END*----------------------------------------------------------------------*/
 
void Transmit00c(unsigned char tch)
{
 //        fputc(tch, fusart0_ptr); 
#ifndef USART0_TRY_PDC_1T
         fputc(tch, fusart0_ptr); 
#else
         ToPdcTu0(tch);

#endif               
         
         
}
 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit
* Returned Value   :none
* Comments         :
*    transmit data for usart1 
*END*----------------------------------------------------------------------*/
 
void Transmit()
{
			pTBuff = &TBuff[0];
   //       printEthString(pTBuff, 20);  //t

			do
			{
		 //	SendChar(pTBuff);
#ifndef USART1_TRY_PDC_1T
         fputc(*pTBuff, fusart1_ptr); 
#else
         ToPdcTu1(*pTBuff);

#endif      
       
       
       
    //     fputc(*pTBuff, fusart1_ptr); 
			}
			while(*pTBuff++);
        	pTBuff = &TBuff[0];  //set pointer to start of buffer!
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit0mf
* Returned Value   :none
* Comments         :
*    transmit data for port EmbIsr for usart0 
*END*----------------------------------------------------------------------*/
 
void Transmit0mf()
{
  unsigned long i;
// static unsigned char x = 0;
// MessageChar(x,1,tch);
// x += 4; 
// if (x > 24) x-= 24;
// fputc(tch, fusart0_ptr); 
 //    *pTBuff0mf = '\0';
     pTBuff0mf = &TBuff0mf[0];
 //			do
 //			{
		 //	SendChar(pTBuff);
 //        fputc(*pTBuff0mf, fusart0_ptr); 
 //			}
 //			while(TBuff0mf_cnt--);
         for (i  = 0l; i < TBuff0mf_cnt; i++)
         {
   //         fputc(*pTBuff0mf++, fusart0_ptr);
#ifndef USART0_TRY_PDC_1T
         fputc(*pTBuff0mf++, fusart0_ptr); 
#else
         ToPdcTu0(*pTBuff0mf++);

#endif               
            
         }
             
        	pTBuff0mf = &TBuff0mf[0];  //set pointer to start of buffer!
         TBuff0mf_cnt = 0l;
}


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit
* Returned Value   :none
* Comments         :
*    transmit data for usart0 
*END*----------------------------------------------------------------------*/
 
void Transmit0()
{
			pTBuff0 = &TBuff0[0];
			do
			{
		 //	SendChar(pTBuff);
    //     fputc(*pTBuff0, fusart0_ptr); 
#ifndef USART0_TRY_PDC_1T
         fputc(*pTBuff0, fusart0_ptr); 
#else
         ToPdcTu0(*pTBuff0);

#endif              
         
			}
			while(*pTBuff0++);
         pTBuff0_init();
       // 	pTBuff0 = &TBuff0[0];  //set pointer to start of buffer!
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit3
* Returned Value   :none
* Comments         :
*    transmit data for usart3 
*END*----------------------------------------------------------------------*/
 
void Transmit3()
{
  
			pTBuff3 = &TBuff3[0];
			do
			{
		 //	SendChar(pTBuff);
         fputc(*pTBuff3, fusart3_ptr); 
			}
			while(*pTBuff3++);
        	pTBuff3 = &TBuff3[0];  //set pointer to start of buffer!
         
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :Transmit2
* Returned Value   :none
* Comments         :
*    transmit data for usart2 
*END*----------------------------------------------------------------------*/
 
void Transmit2()
{
  
			pTBuff2 = &TBuff2[0];
			do
			{
		 //	SendChar(pTBuff);
         fputc(*pTBuff2, fusart2_ptr); 
			}
			while(*pTBuff2++);
        	pTBuff2 = &TBuff2[0];  //set pointer to start of buffer!
         
}


 
 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ReplacePC
* Returned Value   : none
* Comments         :
*    This routine is used to replace . to , to property print data to transmit 
*END*----------------------------------------------------------------------*/
 
//void ReplacePC()
void ReplacePC(char* pBuff)
{
 	//		pTBuff = &TBuff[0];
 			do
 			{
 			if(*pBuff == '.') *pBuff = ',';
 			}
 			while(*pBuff++);
}

 
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ParseBuffer
* Returned Value   : none
* Comments         :
*    This routine is used to parse buffer of remote 
*END*----------------------------------------------------------------------*/
 
 void ParseBuffer(char *pStart,  char razd)
{
  // printEthString("ParseBuffer", 20);


	char * pPrev;
   char * pNext;
   
  //  printEthString(pStart, 20);

   pPrev = pStart;
   pNext = pStart;
 //	p = strtok(pStart, &razd);
    for(int i = 0; i < BufferSize; i++)
    { /* Body */
     if((*pNext & 0xff) == '\0')
     { 
         //   if(pNext > pPrev)
         //   { 
        //     printEthString(pPrev, 20);       //t
               RunCommand(pPrev);
         //   } 
        break;
     } 
      //   if((*pNext & 0xff)  ==';')
          if((*pNext & 0xff)  == razd)
     {
      *pNext = '\0';
      RunCommand(pPrev);
      pPrev = pNext;
       pPrev++; //to first symbol of next command
     }
      pNext++;
   } /* Endbody */
 
 
   // while(p);
//______________________________________
//   pch = strtok (str," ,.-");
//  while (pch != NULL)
//  {
//    printf ("%s\n",pch);
//    pch = strtok (NULL, " ,.-");
//  }



//______________________________________   
   
   
}
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ParseBuffer0
* Returned Value   : none
* Comments         :
*    This routine is used to parse buffer of remote    usart0
*END*----------------------------------------------------------------------*/
 
 void ParseBuffer0(char *pStart,  char razd)
{
	char * pPrev;
   char * pNext;

   pPrev = pStart;
   pNext = pStart;
 //	p = strtok(pStart, &razd);
    for(int i = 0; i < BufferSize0; i++)
    { /* Body */
     if((*pNext & 0xff) == '\0')
     { 
         //   if(pNext > pPrev)
         //   { 
               RunCommand0(pPrev);
         //   } 
        break;
     } 
      //   if((*pNext & 0xff)  ==';')
          if((*pNext & 0xff)  == razd)
     {
      *pNext = '\0';
      RunCommand0(pPrev);
      pPrev = pNext;
       pPrev++; //to first symbol of next command
     }
      pNext++;
   } /* Endbody */
 
 
    // while(p);
//______________________________________
//   pch = strtok (str," ,.-");
//  while (pch != NULL)
//  {
//    printf ("%s\n",pch);
//    pch = strtok (NULL, " ,.-");
//  }



//______________________________________   
   
   
}
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ParseBuffer3
* Returned Value   : none
* Comments         :
*    This routine is used to parse buffer of remote 
*END*----------------------------------------------------------------------*/
 
 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :ParseBuffer3
* Returned Value   : none
* Comments         :
*    This routine is used to parse buffer of remote 
*END*----------------------------------------------------------------------*/
 
 void ParseBuffer3(char *pStart,  char razd)
{
	char * pPrev;
   char * pNext;

   pPrev = pStart;
   pNext = pStart;
 //	p = strtok(pStart, &razd);
    for(int i = 0; i < BufferSize3; i++)
    { /* Body */
     if((*pNext & 0xff) == '\0')
     { 
         //   if(pNext > pPrev)
         //   { 
               RunCommand3(pPrev);
         //   } 
        break;
     } 
      //   if((*pNext & 0xff)  ==';')
          if((*pNext & 0xff)  == razd)
     {
      *pNext = '\0';
      RunCommand3(pPrev);
      pPrev = pNext;
       pPrev++; //to first symbol of next command
     }
      pNext++;
   } /* Endbody */
 
 
  // while(p);
//______________________________________
//   pch = strtok (str," ,.-");
//  while (pch != NULL)
//  {
//    printf ("%s\n",pch);
//    pch = strtok (NULL, " ,.-");
//  }



//______________________________________   
   
   
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_xil_char
* Returned Value   : none
* Comments         :
*    This routine is used to write char to xilinx
*
*END*----------------------------------------------------------------------*/

void write_xil_char(uint_32 Addr, char ctmp)
 {
//  printfpd( "\n\r 0x%x : ", Addr);
 //  printfpd( " 0x%x ", ctmp);
 
  //   _psp_set_cpsr(_psp_get_cpsr() | PSP_PSR_CTRL_DIS_IRQ);
 //  _at91rm9200_int_disable(AT91RM9200_IRQ2_VECTOR); 

 //   _io_fseek (fx_ptr , Addr ,IO_SEEK_SET );
//    fputc(ctmp, fx_ptr);
   char* port;
   port = pxilinx + Addr;
   *port = ctmp;

    
    
    
    //  _at91rm9200_int_enable(AT91RM9200_IRQ2_VECTOR, IRQ, 
             				//      AT91RM9200_AIC_SMR_SRCTYPE_NET,   //negative edge triggered 
                 			  //		      AT91RM9200_AIC_SMR_PRIO_MIN );  

 //    _psp_set_cpsr(_psp_get_cpsr() & (~PSP_PSR_CTRL_DIS_IRQ));
 
 }
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    :read_xil_char
* Returned Value   : none
* Comments         :
*    This routine is used to read char from xilinx
*
*END*----------------------------------------------------------------------*/

char read_xil_char(uint_32 Addr)
 {
  //  _io_fseek (fx_ptr , Addr ,IO_SEEK_SET );
 //    return fgetc(fx_ptr);
      char* port;
      port = pxilinx + Addr;
      return *port;
  }



/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : write_xil_long
* Returned Value   : none
* Comments         :
*    This routine is used to write char to xilinx
*
*END*----------------------------------------------------------------------*/
 /*
void write_xil_long(uint_32 Addr, uint_32 ctmp)
 {
    _io_fseek (fx_ptr , Addr ,IO_SEEK_SET );
    fputc(ctmp, fx_ptr);
    ctmp >>= 8;
    fputc(ctmp, fx_ptr);
    ctmp >>= 8;
    fputc(ctmp, fx_ptr);
    ctmp >>= 8;
    fputc(ctmp, fx_ptr);
 }
 */
/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : read_xil_long
* Returned Value   : none
* Comments         :
*    This routine is used to read long from xilinx
*
*END*----------------------------------------------------------------------*/
 /*
uint_32 read_xil_long(uint_32 Addr)
 {
    uint_32 ctmp;
    _io_fseek (fx_ptr , Addr ,IO_SEEK_SET );
    ctmp  =  fgetc(fx_ptr);
    ctmp += (fgetc(fx_ptr) << 8);
    ctmp += (fgetc(fx_ptr) << 16);
    ctmp += (fgetc(fx_ptr) << 24);
    return ctmp;
 }
    */
    
#ifdef 	PROG_PRM_PCH_N_1


//*----------------------------------------------------------------------------
//* \fn    AT91F_AIC_EnableIt
//* \brief Enable corresponding IT number
//*----------------------------------------------------------------------------
void AT91F_AIC_EnableIt (
	AT91RM9200_AIC_REG_STRUCT_PTR pAic,      // \arg pointer to the AIC registers
	unsigned int irq_id ) // \arg interrupt number to initialize
{
    //* Enable the interrupt on the interrupt controller
    pAic->IECR = 0x1 << irq_id ;
}


//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC1_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_Handler
//* This function updates the next SSC PDC pointer to send the next buffer
//*----------------------------------------------------------------------------
void AT91F_SSC1_Handler(void)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
 SetLed3(0);
//   ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
//	status = ssc1_ptr->SR;
 //  	status = ssc1_ptr->SSC_SR;
 //	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR),	// PDC SSC base address
	//					 (char *)wav_file, 				// pointer to next data
	  //					AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//_____________________________________________________m     
//t if(now_is_sending == 1)
 //if(1)
// { /* Body */
  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
 // now_is_sending = 0;
 // if(need_to_sended) need_to_sended --;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->SODR = 1 << 6;
  
 // ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
 //  AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
 // if(!div)
 //  {div++;}

 /* 1003231 
  AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
         SSC1_RECEIVE_SIZE,
  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
         SSC1_RECEIVE_SIZE);
         
 //  NULL,
 // 0 );

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 
  
  ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  */
  
   if(need_to_sended >= SSC1_SEND_SIZE)
    {
     need_to_sended -= SSC1_SEND_SIZE;
    }
    else{ 
    need_to_sended = 0;
   } 
 //  ssc1_int_cnt++;
 /*  
 if(need_to_sended)
   { 
    OperateSynt(MESSAGE_LEN - need_to_sended);
   }
   
 */  

 //} 
// else
// { 
//    ssc1_int_cnt += 10;
   /*
   if(need_to_sended)
   { 
       OperateSynt(MESSAGE_LEN - need_to_sended);
   }
   */
 
// } 
//_______________________________________________________m  
  
//m   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//m  pio_ptr->SODR = 1 << 6;
 
     
     ssc1_int_cnt += 1;
      pio_ptr->SODR = 1 << 6;
}


unsigned char SSC1_BUFFER[SSC1_BUFFER_SIZE];
unsigned char SSC1_BUFFER_RECEIVE[SSC1_BUFFER_SIZE_RECEIVE];
unsigned long ssc1_int_cnt; 
//_________________________________m
unsigned char now_is_sending;
unsigned char need_to_sended;
//_________________________________m

extern "C" void Init_IOs(void)
{

//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrb;  
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
  
//prm_pch_2 : use for cs  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //  used  instead pa4
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 25, AT91RM9200_PIO_PERIPHERAL_IO, 1);    // 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 27, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 
 
#ifdef PROG_PRM_PCH_N_2 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
#endif //PROG_PRM_PCH_N_2 
 
 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 
 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->SODR = 1 << 6;

}



extern "C" void Init_SSC1(void)
{
  AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

  ssc1_int_cnt = 0l;
//_________________________________m
 now_is_sending = 0;
 need_to_sended = 0;
//_________________________________m
  
  
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   
 //  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//2. enable ssc0 clocks;    
  pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC1_ENABLE;
  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //TF output
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_A, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_A, 0);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_A, 0);  
 /*_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);  
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);   */
 
 
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->SODR = 1 << 6;

   
   
//_____________________________________________temporary
#ifdef TEST_PRM_PCH_1
  AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					XIL_LOAD_FREQ,
			    	0x104,   //need 0x100      (input)
					7, 
               4,
            //   0x300007   //to test clock 
               0x7   //to test clock 
         	);	// End of
#else
           AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					0,//AT91C_MASTER_CLOCK, // \arg master clock
					0,
			    	0x102,   //need 0x102      (input)
					7, 
               2,
               0x7   // 
         	);	// End of

                    

#endif // TEST_PRM_PCH_1           

 

//_____________________________________________temporary   
   
    /*
   
    AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
				  0, // external clocks //	BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				  0, //external clocks //	XIL_LOAD_FREQ,
			    	2, //rx clocks - input from rk pin
					7,  //? receive in bytes
               2, // tk pin4,
//            0xFFFF0004, //  //  4, // 0,//   4,         //clocks + period
        // 0x24,//clock invert
      // 0x7 //lsb first// 0x87 // msb first     7 
          //t   0x1f  
        //t   0x9f      //msb first   32
      //t    0x87    
              0x7   //transmit in bytes 
//    0x87  //tsp3
     //t 0x87   //test period     
     //  0xA7   //to test datdef = 1 
  	);	// End of
   
   */
//___________________________________________________________________
  ssc1_ptr->IDR = 0xffffffff;

 _int_install_isr(AT91RM9200_SSC1_VECTOR,
      (void (_CODE_PTR_)(pointer))AT91F_SSC1_Handler, NULL); 
 
  _at91rm9200_int_enable(AT91RM9200_SSC1_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
                     //    AT91RM9200_AIC_SMR_SRCTYPE_LLS,
    			 //		      AT91RM9200_AIC_SMR_PRIO_MIN);
                           AT91RM9200_AIC_SMR_PRIO_MAX);
	// Enable SSC interrupt in AIC

	AT91F_AIC_EnableIt((AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE, AT91RM9200_SSC1_PID);

 //100326   ssc1_ptr->IER = (unsigned int) ENDTX_INT; // 
    
//____________________________________________________________m    
 //1003233     ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
//____________________________________________________________m
   
   
   
   

//____________________________temporary
  for(long i = 0; i < SSC1_BUFFER_SIZE; i++)
  {
   SSC1_BUFFER[i] = i + 0x55;
  }
//____________________________temporary



//___________________________________________________________________   
   
   
    
}
//#define SSC1_BUFFER_SIZE  (8)
//#define SSC1_BUFFER_SIZE_RECEIVE  (8)

//unsigned char SSC1_BUFFER[SSC1_BUFFER_SIZE];
//unsigned char SSC1_BUFFER_RECEIVE[SSC1_BUFFER_SIZE_RECEIVE];



extern "C" void OperateSynt(unsigned long step)
{
 AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  
//_________________________________m
 //now_is_sending = 1;
//_________________________________m
  
  
  
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->CODR = 1 << 6;


 // AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
 //  char* CurrentDataPointer;

 
 ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//1003193  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;

 
 


//____________________________temporary
//  for(long i = 0; i < SSC1_BUFFER_SIZE; i++)
//  {
//   SSC1_BUFFER[i] = 0x55;
//  }
//____________________________temporary

//_____________________________________________________xilinx
 //  unsigned int imr;//

 // AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
 // AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
//   unsigned int XilSizeToDownload = SSC1_BUFFER_SIZE; //1003194 XilSizeToDownloadD; //0x1ffff;
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
 
//   volatile unsigned int status;
  //   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 //t100319    pio_ptr->MDER = 1;    //enable multidrive for pin prog
 /* 1003193
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_A, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_A, 0);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_A, 0);
 */
 
//    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
//                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
//1003195 imr =  aic_ptr->IMR;
//1003195      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
//1003194  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
// if(pg > 1)
// { 
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
 //  XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
 // } 
//  if(pg > 2)
// { 
//   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
 //  XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
 // } 
  
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
//1003193	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   
 //  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//2. enable ssc0 clocks;    
//1003193   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC1_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset ssc1 
  
   
//1003234   ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters

   AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
   
 // if(!div)
 //  {div++;}
  /* 1003235
  AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					(XIL_LOAD_FREQ  ),
			    	0x104,  //rx clock continuous divided clock
					7, 
               4,
    
  //t      0x7   //to test clock 
        0x300007   //to test clock 

         	);	// End of 
            
         */   
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
/* t       
 //_____________________________________________________________________________________________ 
        	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
        //   	 (char *)XilAddressToDownload, 				// pointer to next data
              (char *)TFTP_BUFFER_ADDRESS,
          //       (char*)&Test, //t
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1)); //t
  //_________________________new              
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1));
 //________________________________________________________
t  */
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
    
 //   pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

 // delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
//  
//   for(cnt = 0; cnt < 500000l; cnt++)
 //  {
  //   status = pio_ptr->PDSR; //wait line init hier zero
   //  if(!(status & 0x10))
  //    { 
  //    printf("\n\r cnt0 = %d",cnt);
  //    break;
  //     }
 //  } 

  
 //  delay_mcs(2000l); //t
  //  pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
  //  status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
//   delay_mcs(400l);  //t
 //  for(cnt = 0; cnt < 500000l; cnt++)
  // {
 //    status = pio_ptr->PDSR; //line init hier one
  //   if(status & 0x10)
  //    { 
   //   printf("\n\r cnt1 = %d",cnt);
 //        break;
  // } 
    
     
 //t  }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
 
//1003195   ssc1_ptr->TCMR = 4; //try before
 //  ssc0_ptr->TCMR = 4;
    /*1003194
   AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
     */
     
     
/* //to make _m     
  AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[0],
     
         SSC1_BUFFER_SIZE,
   (char *)((uint_32)(&SSC1_BUFFER[0]) + SSC1_BUFFER_SIZE),
  SSC1_BUFFER_SIZE );

*/ //to make ___m  

 //_________________________________________________
AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
 //	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
 	  (char *)&SSC1_BUFFER_RECEIVE[0],
         SSC1_RECEIVE_SIZE,
   NULL,
  0 );
  
 // ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  
  

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 

 delay_mcs(3);


//__________________________________________m
  AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[step],
         SSC1_SEND_SIZE,
   NULL,
  0 );
  
  
  
//__________________________________________m  

  
     ssc1_ptr->IER = (unsigned int) ENDTX_INT; // 

  
  
 //1003194  CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
//more worst   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
//more worst   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
     
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   
   
//_____________________________________________________________________________________m
   
 /*
 AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
 //	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
 	  (char *)&SSC1_BUFFER_RECEIVE[0],
         SSC1_RECEIVE_SIZE,
   NULL,
  0 );
  
  ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  
  

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 
  */
 //1003235 ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 

   



//_______________________________________________________________________________________m   

  //ssc1_ptr->IER = (unsigned int) ENDTX_INT;
   
//  AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
//   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   
   
 pio_ptr->CODR = 1 << 6;   
   
   
   
   
/* 1003192   
  for(long cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc1_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc1_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc1_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
             PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
  }
  
  */
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
// for(cnt = 0l; cnt < 10000000l; cnt++)
// { 
//  status = pio_ptr->PDSR;
//  if(status & 0x20) //line done
//  {
  //   printf("\n\r after load : cnt = %d",cnt);
 //  break;
 //  }
 //} 
   /*
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l); 
   delay_mcs( 400l);
      */
//1003191   ssc1_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
//1003191   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC1_DISABLE;
   //3. reset ssc0  
//100191   ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
//1003191   AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
//1003195  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)




//_____________________________________________________xilinx

/*


   AT91F_PDC_DisableTx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));
   AT91F_PDC_DisableRx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));

   
   
   AT91F_SSC_DisableRx (ssc1_ptr);  //new  hier before clocks to have time to start
   AT91F_SSC_DisableTx (ssc1_ptr);  //new  hier before clocks to have time to start


 AT91F_PDC_SetRx (
   (AT91PS_PDC) & ssc1_ptr -> PDC, //	AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
  (char *)&SSC1_BUFFER_RECEIVE[0],     //	char *address,         // \arg address to the next bloc to be received
      SSC1_BUFFER_SIZE_RECEIVE); //	unsigned int bytes)    // \arg number of bytes to be received
      
 AT91F_PDC_SetTx (
   (AT91PS_PDC) & ssc1_ptr -> PDC, //		AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
 (char *)&SSC1_BUFFER[0],     //      // \arg address to the next bloc to be transmitted
       SSC1_BUFFER_SIZE); //	unsigned int bytes)    // \arg number of bytes to be transmitted


*/


//    ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
   /*
AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[0],
         SSC1_BUFFER_SIZE,
   (char *)((uint_32)(&SSC1_BUFFER[0]) + SSC1_BUFFER_SIZE),
  SSC1_BUFFER_SIZE );
    */
//   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
 //  AT91F_PDC_EnableTx ((AT91PS_PDC) & (ssc1_ptr -> SSC_RPR));
  /*t
   AT91F_PDC_EnableTx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));
   AT91F_PDC_EnableRx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));

   
   
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   */
   
//  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
 //  while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc1_ptr->SSC_RPR)) != 1)
 //  {    } 
//  AT91F_PDC_Close((AT91PS_PDC) & (ssc1_ptr->PDC));



}




//*----------------------------------------------------------------------------
//* \fn    AT91F_I2S_Init_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_INIT_Handler
//* This function initializes the synchronization between left and right channels
//*----------------------------------------------------------------------------
//void AT91F_I2S_Init_Handler(void)
//{
//	volatile unsigned int status;
//	AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
	// Disable all interrupts
//	AT91F_SSC_DisableIt (ssc0_ptr, 0xFFFFFFFF);
	// Configure AIC controller for the next SSC interrupts
 //	AT91F_AIC_ConfigureIt (
 //		AT91C_BASE_AIC,                        // AIC base address
 //		AT91C_ID_SSC1,                         // System peripheral ID
//		AT91C_IRQ_LEVEL_I2S,               	   // Max priority
//		AT91C_AIC_SRCTYPE_INT_EDGE_TRIGGERED, // Level sensitive
//		AT91F_ASM_I2S_Handler );	
// _int_install_isr(AT91RM9200_SSC0_VECTOR,
//      (void (_CODE_PTR_)(pointer))AT91F_I2S_Handler, NULL); 
// 
//  _at91rm9200_int_enable(AT91RM9200_SSC0_VECTOR, IRQ, 
//   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
    //					      AT91RM9200_AIC_SMR_PRIO_MIN);
//                           AT91RM9200_AIC_SMR_PRIO_MAX);
	// Enable SSC interrupt in AIC
 //	AT91F_AIC_EnableIt(AT91C_BASE_AIC, AT91C_ID_SSC1);
	// Get status
//	status = ssc0_ptr->SSC_SR;
	// Wait the next frame beginning (SYNC)
//	while (status & AT91C_SSC_TXSYN == 0){
//		status = ssc0_ptr->SSC_SR;
//	}
	// Select next interrupt type
//	AT91F_SSC_EnableIt (ssc0_ptr, AT91C_SSC_ENDTX);	
	// ============================= Configure PDC associated to SSC1 =============================
	// PDC already opened in SSC_Configure function 
//	
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						 AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
//					 (char *)wav_file,					// pointer to data
//					AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
//
//	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// Start music !!!	
//
//}




#endif // PROG_PRM_PCH_N_1   

#ifdef PROG_PRM_PCH_SPI_NOXIL_ETH
extern "C" void Init_IOs_noxil(void)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrb;  
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
  
//prm_pch_2 : use for cs  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //  used  instead pa4
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 25, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 26, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 27, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 23, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 24, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 25, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 26, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 27, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->SODR = 1 << 6;

 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

     pio_ptr->MDDR = 1;

}


extern "C" void Check_IOs_noxil(void)
{
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra, pio_ptrb, pio_ptrc;
  static unsigned char flag;
  
   pio_ptra = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOA_BASE;
   pio_ptrb = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   pio_ptrc = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOC_BASE;

   if(!flag)
   {
   flag = 1;
   pio_ptra->SODR = 0xffffffff;
   pio_ptrb->SODR = 0xffffffff;
   pio_ptrc->SODR = 0xffffffff;
   }
   if(flag==1)
   {
   flag++;
   pio_ptra->SODR = 0x55555555;
   pio_ptrb->SODR = 0x55555555;
   pio_ptrc->SODR = 0x55555555;
   pio_ptra->CODR = 0xAAAAAAAA;
   pio_ptrb->CODR = 0xAAAAAAAA;
   pio_ptrc->CODR = 0xAAAAAAAA;
   }
   if(flag==2)
   {
   flag++;
   pio_ptra->CODR = 0x55555555;
   pio_ptrb->CODR = 0x55555555;
   pio_ptrc->CODR = 0x55555555;
   pio_ptra->SODR = 0xAAAAAAAA;
   pio_ptrb->SODR = 0xAAAAAAAA;
   pio_ptrc->SODR = 0xAAAAAAAA;
   }
   else
   { /* Body */
    flag = 0;
   pio_ptra->CODR = 0xffffffff;
   pio_ptrb->CODR = 0xffffffff;
   pio_ptrc->CODR = 0xffffffff;
   } /* Endbody */

}
#endif  //  PROG_PRM_PCH_SPI_NOXIL_ETH


//______________________________________________--spi
#ifdef 	PROG_PRM_PCH_SPI


//*----------------------------------------------------------------------------
//* \fn    AT91F_AIC_EnableIt
//* \brief Enable corresponding IT number
//*----------------------------------------------------------------------------
void AT91F_AIC_EnableIt (
	AT91RM9200_AIC_REG_STRUCT_PTR pAic,      // \arg pointer to the AIC registers
	unsigned int irq_id ) // \arg interrupt number to initialize
{
    //* Enable the interrupt on the interrupt controller
    pAic->IECR = 0x1 << irq_id ;
}


//*----------------------------------------------------------------------------
//* \fn    AT91F_SSC1_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_Handler
//* This function updates the next SSC PDC pointer to send the next buffer
//*----------------------------------------------------------------------------
void AT91F_SSC1_Handler(void)
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
 SetLed3(0);
//   ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//	volatile unsigned int status;
	//* Get status and acknowledge IT
//	status = ssc1_ptr->SR;
 //  	status = ssc1_ptr->SSC_SR;
 //	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR),	// PDC SSC base address
	//					 (char *)wav_file, 				// pointer to next data
	  //					AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//_____________________________________________________m     
//t if(now_is_sending == 1)
 //if(1)
// { /* Body */
  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
 // now_is_sending = 0;
 // if(need_to_sended) need_to_sended --;
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->SODR = 1 << 6;
  
 // ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters
 //  AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
 // if(!div)
 //  {div++;}

 /* 1003231 
  AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
         SSC1_RECEIVE_SIZE,
  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
         SSC1_RECEIVE_SIZE);
         
 //  NULL,
 // 0 );

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 
  
  ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  */
  
   if(need_to_sended >= SSC1_SEND_SIZE)
    {
     need_to_sended -= SSC1_SEND_SIZE;
    }
    else{ 
    need_to_sended = 0;
   } 
 //  ssc1_int_cnt++;
 /*  
 if(need_to_sended)
   { 
    OperateSynt(MESSAGE_LEN - need_to_sended);
   }
   
 */  

 //} 
// else
// { 
//    ssc1_int_cnt += 10;
   /*
   if(need_to_sended)
   { 
       OperateSynt(MESSAGE_LEN - need_to_sended);
   }
   */
 
// } 
//_______________________________________________________m  
  
//m   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//m  pio_ptr->SODR = 1 << 6;
 
     
     ssc1_int_cnt += 1;
      pio_ptr->SODR = 1 << 6;
}


unsigned char SSC1_BUFFER[SSC1_BUFFER_SIZE];
unsigned char SSC1_BUFFER_RECEIVE[SSC1_BUFFER_SIZE_RECEIVE];
unsigned long ssc1_int_cnt; 
//_________________________________m
unsigned char now_is_sending;
unsigned char need_to_sended;
//_________________________________m

extern "C" void Init_IOs(void)
{

//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptra;
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrb;  
//  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptrc;
  
//prm_pch_2 : use for cs  _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //  used  instead pa4
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 24, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 25, AT91RM9200_PIO_PERIPHERAL_IO, 1);    // 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 26, AT91RM9200_PIO_PERIPHERAL_IO, 1);    // 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 27, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 28, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 29, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 
 /*
#ifdef PROG_PRM_PCH_N_2 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_A, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
#endif //PROG_PRM_PCH_N_2 
 */
/* 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 
*/ 

 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 0, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 1, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 2, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 4, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 5, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 18, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 20, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 21, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
 
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_C, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //

 
//  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->SODR = 1 << 6;

}



extern "C" void Init_SSC1(void)
{
  AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;

  ssc1_int_cnt = 0l;
//_________________________________m
 now_is_sending = 0;
 need_to_sended = 0;
//_________________________________m
  
  
  pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   
 //  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//2. enable ssc0 clocks;    
  pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC1_ENABLE;
  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
// _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_IO, 1);    //TF output
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_A, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_A, 0);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_A, 0);  
 /*_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 3, AT91RM9200_PIO_PERIPHERAL_IO, 1);  
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_IO, 1);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_IO, 1);   */
 
 
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
  pio_ptr->SODR = 1 << 6;

   
   
//_____________________________________________temporary
#ifdef TEST_PRM_PCH_1
  AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					XIL_LOAD_FREQ,
			    	0x104,   //need 0x100      (input)
					7, 
               4,
            //   0x300007   //to test clock 
               0x7   //to test clock 
         	);	// End of
#else
           AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					0,//AT91C_MASTER_CLOCK, // \arg master clock
					0,
			    	0x102,   //need 0x102      (input)
					7, 
               2,
               0x7   // 
         	);	// End of

                    

#endif // TEST_PRM_PCH_1           

 

//_____________________________________________temporary   
   
    /*
   
    AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
				  0, // external clocks //	BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
				  0, //external clocks //	XIL_LOAD_FREQ,
			    	2, //rx clocks - input from rk pin
					7,  //? receive in bytes
               2, // tk pin4,
//            0xFFFF0004, //  //  4, // 0,//   4,         //clocks + period
        // 0x24,//clock invert
      // 0x7 //lsb first// 0x87 // msb first     7 
          //t   0x1f  
        //t   0x9f      //msb first   32
      //t    0x87    
              0x7   //transmit in bytes 
//    0x87  //tsp3
     //t 0x87   //test period     
     //  0xA7   //to test datdef = 1 
  	);	// End of
   
   */
//___________________________________________________________________
  ssc1_ptr->IDR = 0xffffffff;

 _int_install_isr(AT91RM9200_SSC1_VECTOR,
      (void (_CODE_PTR_)(pointer))AT91F_SSC1_Handler, NULL); 
 
  _at91rm9200_int_enable(AT91RM9200_SSC1_VECTOR, IRQ, 
   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
                     //    AT91RM9200_AIC_SMR_SRCTYPE_LLS,
    			 //		      AT91RM9200_AIC_SMR_PRIO_MIN);
                           AT91RM9200_AIC_SMR_PRIO_MAX);
	// Enable SSC interrupt in AIC

	AT91F_AIC_EnableIt((AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE, AT91RM9200_SSC1_PID);

 //100326   ssc1_ptr->IER = (unsigned int) ENDTX_INT; // 
    
//____________________________________________________________m    
 //1003233     ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
//____________________________________________________________m
   
   
   
   

//____________________________temporary
  for(long i = 0; i < SSC1_BUFFER_SIZE; i++)
  {
   SSC1_BUFFER[i] = i + 0x55;
  }
//____________________________temporary



//___________________________________________________________________   
   
   
    
}
//#define SSC1_BUFFER_SIZE  (8)
//#define SSC1_BUFFER_SIZE_RECEIVE  (8)

//unsigned char SSC1_BUFFER[SSC1_BUFFER_SIZE];
//unsigned char SSC1_BUFFER_RECEIVE[SSC1_BUFFER_SIZE_RECEIVE];



extern "C" void OperateSynt(unsigned long step)
{
 AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
  AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
  
//_________________________________m
 //now_is_sending = 1;
//_________________________________m
  
  
  
  pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
//  pio_ptr->CODR = 1 << 6;


 // AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
 //  char* CurrentDataPointer;

 
 ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//1003193  AT91RM9200_PMC_REG_STRUCT_PTR pmc_ptr;

 
 


//____________________________temporary
//  for(long i = 0; i < SSC1_BUFFER_SIZE; i++)
//  {
//   SSC1_BUFFER[i] = 0x55;
//  }
//____________________________temporary

//_____________________________________________________xilinx
 //  unsigned int imr;//

 // AT91RM9200_SSC_REG_STRUCT_PTR ssc1_ptr;
 // AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   //  unsigned int XilDataAddress = XilDataAddressD; //0xC07C0000l;
 //      unsigned int XilDataAddress = XilDataAddressD; //t; to it is added 0x60

//     unsigned int XilDataAddress = TestDataAddressD; //0xC07C0000l;

 //  unsigned int XilAddressToDownload =  (unsigned int)(TFTP_BUFFER_ADDRESS); //XilAddressToDownloadD;// 0x21000000; //upper 16Mx32 +1
//   unsigned int XilSizeToDownload = SSC1_BUFFER_SIZE; //1003194 XilSizeToDownloadD; //0x1ffff;
// unsigned int XilSizeToDownload    = ((XilSizeToDownloadD % 8l) << 3) + 8l; //0x1ffff;
 //unsigned int XilSizeToDownload = 24;   //t    2 -not data
//unsigned int XilSizeToDownload = 60000l;   //max is 65000 : 16 bit - need make two pointers
 
//   volatile unsigned int status;
  //   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

 //t100319    pio_ptr->MDER = 1;    //enable multidrive for pin prog
 /* 1003193
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 6, AT91RM9200_PIO_PERIPHERAL_A, 0);    //line prog
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_A, 0);     //cclk
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_A, 0);     //data
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 9, AT91RM9200_PIO_PERIPHERAL_A, 0);      //line init
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_A, 0);     //line done
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 11, AT91RM9200_PIO_PERIPHERAL_A, 0);
 */
 
//    AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr =                                                //my
//                                  (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my

//ok
//1003195 imr =  aic_ptr->IMR;
//1003195      aic_ptr->IDCR = 0xFFFFFFFFl;
 //t	 read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
//t  read_dataflash (XilDataAddress, 32l, (char *)(TFTP_BUFFER_ADDRESS));
//1003194  read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(TFTP_BUFFER_ADDRESS));
// if(pg > 1)
// { 
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD2, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD));
//   read_dataflash ((unsigned int)XilDataAddressD2, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));   
 //  XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD2;
 // } 
//  if(pg > 2)
// { 
//   read_dataflash ((unsigned int)XilDataAddressD3, (unsigned int)XilSizeToDownloadD3, (char *)((unsigned int)TFTP_BUFFER_ADDRESS+(unsigned int)XilSizeToDownloadD + (unsigned int)XilSizeToDownloadD2));
 //  XilSizeToDownload +=  (unsigned int)XilSizeToDownloadD3;
 // } 
  
     //    read_dataflash (XilDataAddress, XilSizeToDownload, (char *)(XilAddressToDownload));
    //  delay_mcs(400l); 
 //     aic_ptr->IECR = imr;
        
//1003193	pmc_ptr = (AT91RM9200_PMC_REG_STRUCT_PTR)AT91RM9200_PMC_BASE;
   
 //  ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
//2. enable ssc0 clocks;    
//1003193   pmc_ptr->PCER =  AT91RM9200_PMC_SCER_SSC1_ENABLE;
 //no 
 //  for(;;){ /* Body */
  //3. reset ssc1 
  
   
//1003234   ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
//4. Clear transmit and receive PDC counters

   AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
   
 // if(!div)
 //  {div++;}
  /* 1003235
  AT91F_SSC_Configure (ssc1_ptr,//pSSC1,    // \arg pointer to a SSC controller
					BSP_MASTER_CLOCK,//AT91C_MASTER_CLOCK, // \arg master clock
					(XIL_LOAD_FREQ  ),
			    	0x104,  //rx clock continuous divided clock
					7, 
               4,
    
  //t      0x7   //to test clock 
        0x300007   //to test clock 

         	);	// End of 
            
         */   
		 //t	uint_32 Test = 0xFCFCFCFC;	 //t
      // uint_32 Test = 0x7d7d7d7d;	 //t
 //       char Test[] =  { 0x55, 0x99, 0xAA, 0x66, 0x0c,0,1,0x80, 0 ,0, 0, 0xe0, 0x0C, 0x80, 0x6, 0x80}; 
/* t       
 //_____________________________________________________________________________________________ 
        	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
        //   	 (char *)XilAddressToDownload, 				// pointer to next data
              (char *)TFTP_BUFFER_ADDRESS,
          //       (char*)&Test, //t
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1)); //t
  //_________________________new              
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)((uint_32)(TFTP_BUFFER_ADDRESS) +  (XilSizeToDownload >> 1)), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
               (XilSizeToDownload >> 1));
 //________________________________________________________
t  */
//  unsigned int AT91F_SSC_SendFrame(
//	AT91PS_SSC pSSC,
//	char *pBuffer,
//	unsigned int szBuffer,
//	char *pNextBuffer,
//	unsigned int szNextBuffer )
 

  //t	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// 
//no
    
 //   pio_ptr->CODR = 1;
 //    status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22

 // delay_mcs(400l);      //delay to signal "prog"  , < 500 mcs
//  
//   for(cnt = 0; cnt < 500000l; cnt++)
 //  {
  //   status = pio_ptr->PDSR; //wait line init hier zero
   //  if(!(status & 0x10))
  //    { 
  //    printf("\n\r cnt0 = %d",cnt);
  //    break;
  //     }
 //  } 

  
 //  delay_mcs(2000l); //t
  //  pio_ptr->SODR = 1;
 //   status = pio_ptr->PDSR; //t22
 //   my_printf((unsigned char)status); //t22
  //  status = pio_ptr->PDSR & (1 << 4); //line init hier zero
//t  delay_mcs(200l);   //delay 100 to xilinx make init < 100 mcs and after init high 100 mcs
//   delay_mcs(400l);  //t
 //  for(cnt = 0; cnt < 500000l; cnt++)
  // {
 //    status = pio_ptr->PDSR; //line init hier one
  //   if(status & 0x10)
  //    { 
   //   printf("\n\r cnt1 = %d",cnt);
 //        break;
  // } 
    
     
 //t  }
 //  status = pio_ptr->PDSR & (1 << 4); //line init hier one
 
//1003195   ssc1_ptr->TCMR = 4; //try before
 //  ssc0_ptr->TCMR = 4;
    /*1003194
   AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)TFTP_BUFFER_ADDRESS,
         PDC_BUFFER_SIZE,
   (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE),
  PDC_BUFFER_SIZE );
     */
     
     
/* //to make _m     
  AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[0],
     
         SSC1_BUFFER_SIZE,
   (char *)((uint_32)(&SSC1_BUFFER[0]) + SSC1_BUFFER_SIZE),
  SSC1_BUFFER_SIZE );

*/ //to make ___m  

 //_________________________________________________
AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
 //	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
 	  (char *)&SSC1_BUFFER_RECEIVE[0],
         SSC1_RECEIVE_SIZE,
   NULL,
  0 );
  
 // ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  
  

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 

 delay_mcs(3);


//__________________________________________m
  AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[step],
         SSC1_SEND_SIZE,
   NULL,
  0 );
  
  
  
//_________________________m
  AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[step],
         SSC1_SEND_SIZE,
   NULL,
  0 );
  
  
  
//____________________DRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
//more worst   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
//more worst   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
     
      
   AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   
   
//_____________________________________________________________________________________m
   
 /*
 AT91F_SSC_ReceiveFrame(   //t
  ssc1_ptr,
 //	  (char *)&SSC1_BUFFER_RECEIVE[MESSAGE_LEN - need_to_sended],
 	  (char *)&SSC1_BUFFER_RECEIVE[0],
         SSC1_RECEIVE_SIZE,
   NULL,
  0 );
  
  ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 
  
  

   AT91F_PDC_EnableRx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
 
  */
 //1003235 ssc1_ptr->IER = (unsigned int) ENDRX_INT; // 

   



//_______________________________________________________________________________________m   

  //ssc1_ptr->IER = (unsigned int) ENDTX_INT;
   
//  AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc1_ptr->SSC_RPR));
//   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   
   
 pio_ptr->CODR = 1 << 6;   
   
   
   
   
/* 1003192   
  for(long cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
   while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc1_ptr->SSC_RPR)) != 1)
   {    } 
//_________________________________________________________________________>
    status = ssc1_ptr->SSC_SR;
   AT91F_PDC_SetNextTx((AT91PS_PDC) &(ssc1_ptr->SSC_RPR),		// PDC SSC base address	
			//		 (char *)wav_file,					// pointer to data
           	 (char *)( CurrentDataPointer), 				// pointer to next data
         //  	AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
             PDC_BUFFER_SIZE);
      CurrentDataPointer +=  PDC_BUFFER_SIZE;         
  }
  
  */
//_________________________________________________________________________ <  

 //   delay_mcs(200l); //delay to ssc get all data
//t  delay_mcs( XilSizeToDownload); //t 100 - for 4 bytes 
// for(cnt = 0l; cnt < 10000000l; cnt++)
// { 
//  status = pio_ptr->PDSR;
//  if(status & 0x20) //line done
//  {
  //   printf("\n\r after load : cnt = %d",cnt);
 //  break;
 //  }
 //} 
   /*
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l);
   delay_mcs( 400l); 
   delay_mcs( 400l);
      */
//1003191   ssc1_ptr->TCMR = 0; 
   //disable ssc0 clocks in pmc ;    
//1003191   pmc_ptr->PCDR =  AT91RM9200_PMC_SCER_SSC1_DISABLE;
   //3. reset ssc0  
//100191   ssc1_ptr->CR = AT91RM9200_SSC_CR_SWRST;
   //4. Clear transmit and receive PDC counters
//1003191   AT91F_PDC_Close((AT91PS_PDC) &(ssc1_ptr->PDC));
   //  status = pio_ptr->PDSR & (1 << 5); //line done hier 1
  //    status = pio_ptr->PDSR; //t22
  //  my_printf((unsigned char)status); //t22

 //  delay_mcs(5000l); 
//1003195  aic_ptr->IECR = imr;
  // } /* Endbody */ //for(;;)




//_____________________________________________________xilinx

/*


   AT91F_PDC_DisableTx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));
   AT91F_PDC_DisableRx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));

   
   
   AT91F_SSC_DisableRx (ssc1_ptr);  //new  hier before clocks to have time to start
   AT91F_SSC_DisableTx (ssc1_ptr);  //new  hier before clocks to have time to start


 AT91F_PDC_SetRx (
   (AT91PS_PDC) & ssc1_ptr -> PDC, //	AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
  (char *)&SSC1_BUFFER_RECEIVE[0],     //	char *address,         // \arg address to the next bloc to be received
      SSC1_BUFFER_SIZE_RECEIVE); //	unsigned int bytes)    // \arg number of bytes to be received
      
 AT91F_PDC_SetTx (
   (AT91PS_PDC) & ssc1_ptr -> PDC, //		AT91PS_PDC pPDC,       // \arg pointer to a PDC controller
 (char *)&SSC1_BUFFER[0],     //      // \arg address to the next bloc to be transmitted
       SSC1_BUFFER_SIZE); //	unsigned int bytes)    // \arg number of bytes to be transmitted


*/


//    ssc1_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC1_BASE;
   /*
AT91F_SSC_SendFrame(   //t
  ssc1_ptr,
	  (char *)&SSC1_BUFFER[0],
         SSC1_BUFFER_SIZE,
   (char *)((uint_32)(&SSC1_BUFFER[0]) + SSC1_BUFFER_SIZE),
  SSC1_BUFFER_SIZE );
    */
//   CurrentDataPointer = (char *)((uint_32)(TFTP_BUFFER_ADDRESS) + PDC_BUFFER_SIZE + PDC_BUFFER_SIZE);  
      
      
      
 //  AT91F_PDC_EnableTx ((AT91PS_PDC) & (ssc1_ptr -> SSC_RPR));
  /*t
   AT91F_PDC_EnableTx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));
   AT91F_PDC_EnableRx ((AT91PS_PDC) & (ssc1_ptr -> PDC.PTCR));

   
   
   AT91F_SSC_EnableRx (ssc1_ptr);  //new  hier before clocks to have time to start
   AT91F_SSC_EnableTx (ssc1_ptr);  //new  hier before clocks to have time to start
   */
   
//  for(cnt = 0; cnt < ((XilSizeToDownload / PDC_BUFFER_SIZE)); cnt++){     //2 buffers are now settet for loading
 //  while (AT91F_PDC_IsTxEmpty((AT91PS_PDC) & (ssc1_ptr->SSC_RPR)) != 1)
 //  {    } 
//  AT91F_PDC_Close((AT91PS_PDC) & (ssc1_ptr->PDC));



}




//*----------------------------------------------------------------------------
//* \fn    AT91F_I2S_Init_Handler
//* \brief This function is invoked by AT91F_ASM_I2S_INIT_Handler
//* This function initializes the synchronization between left and right channels
//*----------------------------------------------------------------------------
//void AT91F_I2S_Init_Handler(void)
//{
//	volatile unsigned int status;
//	AT91RM9200_SSC_REG_STRUCT_PTR ssc0_ptr;
//   ssc0_ptr =  (AT91RM9200_SSC_REG_STRUCT_PTR)AT91RM9200_SSC0_BASE;
	// Disable all interrupts
//	AT91F_SSC_DisableIt (ssc0_ptr, 0xFFFFFFFF);
	// Configure AIC controller for the next SSC interrupts
 //	AT91F_AIC_ConfigureIt (
 //		AT91C_BASE_AIC,                        // AIC base address
 //		AT91C_ID_SSC1,                         // System peripheral ID
//		AT91C_IRQ_LEVEL_I2S,               	   // Max priority
//		AT91C_AIC_SRCTYPE_INT_EDGE_TRIGGERED, // Level sensitive
//		AT91F_ASM_I2S_Handler );	
// _int_install_isr(AT91RM9200_SSC0_VECTOR,
//      (void (_CODE_PTR_)(pointer))AT91F_I2S_Handler, NULL); 
// 
//  _at91rm9200_int_enable(AT91RM9200_SSC0_VECTOR, IRQ, 
//   					      AT91RM9200_AIC_SMR_SRCTYPE_NET,
    //					      AT91RM9200_AIC_SMR_PRIO_MIN);
//                           AT91RM9200_AIC_SMR_PRIO_MAX);
	// Enable SSC interrupt in AIC
 //	AT91F_AIC_EnableIt(AT91C_BASE_AIC, AT91C_ID_SSC1);
	// Get status
//	status = ssc0_ptr->SSC_SR;
	// Wait the next frame beginning (SYNC)
//	while (status & AT91C_SSC_TXSYN == 0){
//		status = ssc0_ptr->SSC_SR;
//	}
	// Select next interrupt type
//	AT91F_SSC_EnableIt (ssc0_ptr, AT91C_SSC_ENDTX);	
	// ============================= Configure PDC associated to SSC1 =============================
	// PDC already opened in SSC_Configure function 
//	
//	AT91F_PDC_SetNextTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),	// PDC SSC base address
//						 (char *)wav_file, 				// pointer to next data
//						 AT91C_WAV_FILE_SIZE/2); 		// Number of 16 bits words
//	AT91F_PDC_SetTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR),		// PDC SSC base address	
//					 (char *)wav_file,					// pointer to data
//					AT91C_WAV_FILE_SIZE/2);  			// Number of 16 bits words
//
//	AT91F_PDC_EnableTx ((AT91PS_PDC) &(ssc0_ptr->SSC_RPR));	// Start music !!!	
//
//}



#include <prm_pch_spi_real_work.c>
#endif // PROG_PRM_PCH_SPI     