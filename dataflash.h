//*---------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*---------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*---------------------------------------------------------------------------
//* File Name           : AT91_SpiDataFlash.h
//* Object              : Data Flash Atmel Description File
//* Translator          :
//*
//* 1.0 03/04/01 HI	: Creation
//*
//*---------------------------------------------------------------------------

#ifndef _DataFlash_h
#define _DataFlash_h
				 
//160217 #define CFG_MAX_DATAFLASH_BANKS 	2

//#define CFG_MAX_DATAFLASH_BANKS 	1	//150817
#define CFG_MAX_DATAFLASH_BANKS 	3


#define CFG_MAX_DATAFLASH_BANKSX 	16
//#define CFG_MAX_DATAFLASH_BANKSX 	1

#define CFG_DATAFLASH_LOGIC_ADDR_CS0	0xC0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS3	0xD0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS1	0xE0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS2	0xF0000000


 /*
#define CFG_DATAFLASH_LOGIC_ADDR_CS0X	0x00000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS1X	0x10000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS2X	0x20000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS3X	0x30000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS4X	0x40000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS5X	0x50000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS6X	0x60000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS7X	0x70000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS8X	0x80000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS9X	0x90000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS10X	0xA0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS11X	0xB0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS12X	0xC0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS13X	0xD0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS14X	0xE0000000
#define CFG_DATAFLASH_LOGIC_ADDR_CS15X	0xF0000000

 */

//_______________________________________________porting
extern void _at91rm9200_pio_set(unsigned long, unsigned long, unsigned long, unsigned long);
#define  AT91RM9200_PIO_PORT_A			 (0)
#define  AT91RM9200_PIO_PERIPHERAL_A	 (0)
#define  AT91C_PMC_PCER  ((unsigned long *) 	0xFFFFFC10) // (PMC) Peripheral Clock Enable Register
#define  AT91C_ID_SPI    ((unsigned int) 13) // Serial Peripheral Interface
//#define AT91C_SPI_CR    ((unsigned long *) 	0xFFFE0000) // (SPI) Control Register
#define AT91C_SPI_SWRST       ((unsigned int) 0x1 <<  7) // (SPI) SPI Software 
//_________________________________________________
 // ========== Register definition for PDC_SPI peripheral ========== 
#define AT91C_SPI_PTCR  ((unsigned long *) 	0xFFFE0120) // (PDC_SPI) PDC Transfer Control Register
#define AT91C_SPI_TNPR  ((unsigned long *) 	0xFFFE0118) // (PDC_SPI) Transmit Next Pointer Register
#define AT91C_SPI_RNPR  ((unsigned long *) 	0xFFFE0110) // (PDC_SPI) Receive Next Pointer Register
#define AT91C_SPI_TPR   ((unsigned long *) 	0xFFFE0108) // (PDC_SPI) Transmit Pointer Register
#define AT91C_SPI_RPR   ((unsigned long *) 	0xFFFE0100) // (PDC_SPI) Receive Pointer Register
#define AT91C_SPI_PTSR  ((unsigned long *) 	0xFFFE0124) // (PDC_SPI) PDC Transfer Status Register
#define AT91C_SPI_TNCR  ((unsigned long *) 	0xFFFE011C) // (PDC_SPI) Transmit Next Counter Register
#define AT91C_SPI_RNCR  ((unsigned long *) 	0xFFFE0114) // (PDC_SPI) Receive Next Counter Register
#define AT91C_SPI_TCR   ((unsigned long *) 	0xFFFE010C) // (PDC_SPI) Transmit Counter Register
#define AT91C_SPI_RCR   ((unsigned long *) 	0xFFFE0104) // (PDC_SPI) Receive Counter Register
// ========== Register definition for SPI peripheral ========== 
#define AT91C_SPI_CSR   ((unsigned long *) 	0xFFFE0030) // (SPI) Chip Select Register
#define AT91C_SPI_IDR   ((unsigned long *) 	0xFFFE0018) // (SPI) Interrupt Disable Register
#define AT91C_SPI_SR    ((unsigned long *) 	0xFFFE0010) // (SPI) Status Register
#define AT91C_SPI_RDR   ((unsigned long *) 	0xFFFE0008) // (SPI) Receive Data Register
#define AT91C_SPI_CR    ((unsigned long *) 	0xFFFE0000) // (SPI) Control Register
#define AT91C_SPI_IMR   ((unsigned long *) 	0xFFFE001C) // (SPI) Interrupt Mask Register
#define AT91C_SPI_IER   ((unsigned long *) 	0xFFFE0014) // (SPI) Interrupt Enable Register
#define AT91C_SPI_TDR   ((unsigned long *) 	0xFFFE000C) // (SPI) Transmit Data Register
#define AT91C_SPI_MR    ((unsigned long *) 	0xFFFE0004) // (SPI) Mode Register
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
// -------- SPI_CR : (SPI Offset: 0x0) SPI Control Register -------- 
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS      ((unsigned int) 0x1 <<  1) // (SPI) SPI Disable
#define AT91C_SPI_SWRST       ((unsigned int) 0x1 <<  7) // (SPI) SPI Software reset
// -------- SPI_MR : (SPI Offset: 0x4) SPI Mode Register -------- 
#define AT91C_SPI_MSTR        ((unsigned int) 0x1 <<  0) // (SPI) Master/Slave Mode
#define AT91C_SPI_PS          ((unsigned int) 0x1 <<  1) // (SPI) Peripheral Select
#define 	AT91C_SPI_PS_FIXED                ((unsigned int) 0x0 <<  1) // (SPI) Fixed Peripheral Select
#define 	AT91C_SPI_PS_VARIABLE             ((unsigned int) 0x1 <<  1) // (SPI) Variable Peripheral Select
#define AT91C_SPI_PCSDEC      ((unsigned int) 0x1 <<  2) // (SPI) Chip Select Decode
#define AT91C_SPI_DIV32       ((unsigned int) 0x1 <<  3) // (SPI) Clock Selection
#define AT91C_SPI_MODFDIS     ((unsigned int) 0x1 <<  4) // (SPI) Mode Fault Detection
#define AT91C_SPI_LLB         ((unsigned int) 0x1 <<  7) // (SPI) Clock Selection
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_DLYBCS      ((unsigned int) 0xFF << 24) // (SPI) Delay Between Chip Selects
// -------- SPI_RDR : (SPI Offset: 0x8) Receive Data Register -------- 
#define AT91C_SPI_RD          ((unsigned int) 0xFFFF <<  0) // (SPI) Receive Data
#define AT91C_SPI_RPCS        ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_TDR : (SPI Offset: 0xc) Transmit Data Register -------- 
#define AT91C_SPI_TD          ((unsigned int) 0xFFFF <<  0) // (SPI) Transmit Data
#define AT91C_SPI_TPCS        ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_SR : (SPI Offset: 0x10) Status Register -------- 
#define AT91C_SPI_RDRF        ((unsigned int) 0x1 <<  0) // (SPI) Receive Data Register Full
#define AT91C_SPI_TDRE        ((unsigned int) 0x1 <<  1) // (SPI) Transmit Data Register Empty
#define AT91C_SPI_MODF        ((unsigned int) 0x1 <<  2) // (SPI) Mode Fault Error
#define AT91C_SPI_OVRES       ((unsigned int) 0x1 <<  3) // (SPI) Overrun Error Status
#define AT91C_SPI_SPENDRX     ((unsigned int) 0x1 <<  4) // (SPI) End of Receiver Transfer
#define AT91C_SPI_SPENDTX     ((unsigned int) 0x1 <<  5) // (SPI) End of Receiver Transfer
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_TXBUFE      ((unsigned int) 0x1 <<  7) // (SPI) TXBUFE Interrupt
#define AT91C_SPI_SPIENS      ((unsigned int) 0x1 << 16) // (SPI) Enable Status
// -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register -------- 
// -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register -------- 
// -------- SPI_IMR : (SPI Offset: 0x1c) Interrupt Mask Register -------- 
// -------- SPI_CSR : (SPI Offset: 0x30) Chip Select Register -------- 
#define AT91C_SPI_CPOL        ((unsigned int) 0x1 <<  0) // (SPI) Clock Polarity
#define AT91C_SPI_NCPHA       ((unsigned int) 0x1 <<  1) // (SPI) Clock Phase
#define AT91C_SPI_BITS        ((unsigned int) 0xF <<  4) // (SPI) Bits Per Transfer
#define 	AT91C_SPI_BITS_8                    ((unsigned int) 0x0 <<  4) // (SPI) 8 Bits Per transfer
#define 	AT91C_SPI_BITS_9                    ((unsigned int) 0x1 <<  4) // (SPI) 9 Bits Per transfer
#define 	AT91C_SPI_BITS_10                   ((unsigned int) 0x2 <<  4) // (SPI) 10 Bits Per transfer
#define 	AT91C_SPI_BITS_11                   ((unsigned int) 0x3 <<  4) // (SPI) 11 Bits Per transfer
#define 	AT91C_SPI_BITS_12                   ((unsigned int) 0x4 <<  4) // (SPI) 12 Bits Per transfer
#define 	AT91C_SPI_BITS_13                   ((unsigned int) 0x5 <<  4) // (SPI) 13 Bits Per transfer
#define 	AT91C_SPI_BITS_14                   ((unsigned int) 0x6 <<  4) // (SPI) 14 Bits Per transfer
#define 	AT91C_SPI_BITS_15                   ((unsigned int) 0x7 <<  4) // (SPI) 15 Bits Per transfer
#define 	AT91C_SPI_BITS_16                   ((unsigned int) 0x8 <<  4) // (SPI) 16 Bits Per transfer
#define AT91C_SPI_SCBR        ((unsigned int) 0xFF <<  8) // (SPI) Serial Clock Baud Rate
#define AT91C_SPI_DLYBS       ((unsigned int) 0xFF << 16) // (SPI) Serial Clock Baud Rate
#define AT91C_SPI_DLYBCT      ((unsigned int) 0xFF << 24) // (SPI) Delay Between Consecutive Transfers
//________________________
#define BSP_MAIN_CLOCK				(18432000)
#define BSP_PLL_DIVF				(4)
#define BSP_PLL_MULF				(33) //my to have pll lover 180 MHz may be 33 to 152 MHz?
//#define BSP_PLL_MULF				(39)//111123 //my to have pll lover 180 MHz may be 33 to 152 MHz?
//#define BSP_PLL_MULF				(48) //make 180 MHz?
#define BSP_PLL_OP_FREQ_RANGE		PLL_FREQ_OP_150_240 //PLL_FREQ_OP_80_160
#define BSP_PROCESSOR_CLOCK			(BSP_MAIN_CLOCK / BSP_PLL_DIVF * BSP_PLL_MULF)
#define BSP_MASTER_CLOCK			(BSP_PROCESSOR_CLOCK / 3)
#define AT91C_MASTER_CLOCK			BSP_MASTER_CLOCK			
//_________________________________________________
 // *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Peripheral Data Controller
// *****************************************************************************
typedef struct _AT91S_PDC {
	unsigned long	 PDC_RPR; 	// Receive Pointer Register
	unsigned long	 PDC_RCR; 	// Receive Counter Register
	unsigned long	 PDC_TPR; 	// Transmit Pointer Register
	unsigned long	 PDC_TCR; 	// Transmit Counter Register
	unsigned long	 PDC_RNPR; 	// Receive Next Pointer Register
	unsigned long	 PDC_RNCR; 	// Receive Next Counter Register
	unsigned long	 PDC_TNPR; 	// Transmit Next Pointer Register
	unsigned long	 PDC_TNCR; 	// Transmit Next Counter Register
	unsigned long	 PDC_PTCR; 	// PDC Transfer Control Register
	unsigned long	 PDC_PTSR; 	// PDC Transfer Status Register
} AT91S_PDC, *AT91PS_PDC;

// -------- PDC_PTCR : (PDC Offset: 0x20) PDC Transfer Control Register -------- 
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
// -------- PDC_PTSR : (PDC Offset: 0x24) PDC Transfer Status Register -------- 
//_______________________________________________porting


typedef struct {
	unsigned long base;		/* logical base address for a bank */
	unsigned long size;		/* total bank size */
	unsigned long page_count;
	unsigned long page_size;
	unsigned long id;		/* device id */
} dataflash_info_t;

typedef unsigned int AT91S_DataFlashStatus;

/*----------------------------------------------------------------------*/
/* DataFlash Structures							*/
/*----------------------------------------------------------------------*/

/*---------------------------------------------*/
/* DataFlash Descriptor Structure Definition   */
/*---------------------------------------------*/
typedef struct _AT91S_DataflashDesc {
	unsigned char 			*tx_cmd_pt;
	unsigned int 			tx_cmd_size;
	unsigned char 			*rx_cmd_pt;
	unsigned int 			rx_cmd_size;
	unsigned char 			*tx_data_pt;
	unsigned int 			tx_data_size;
	unsigned char 			*rx_data_pt;
	unsigned int 			rx_data_size;
	volatile unsigned char 	state;
	volatile unsigned char 	DataFlash_state;
	unsigned char 			command[8];
} AT91S_DataflashDesc, *AT91PS_DataflashDesc;

/*---------------------------------------------*/
/* DataFlash device definition structure       */
/*---------------------------------------------*/
typedef struct _AT91S_Dataflash {
	int pages_number;			/* dataflash page number */
	int pages_size;				/* dataflash page size */
	int page_offset;			/* page offset in command */
	int byte_mask;				/* byte mask in command */
	int cs;
} AT91S_DataflashFeatures, *AT91PS_DataflashFeatures;

	  
/*---------------------------------------------*/
/* DataFlash Structure Definition	       */
/*---------------------------------------------*/
typedef struct _AT91S_DataFlash {
	AT91PS_DataflashDesc pDataFlashDesc;	/* dataflash descriptor */
	AT91PS_DataflashFeatures pDevice;	/* Pointer on a dataflash features array */
} AT91S_DataFlash, *AT91PS_DataFlash;


typedef struct _AT91S_DATAFLASH_INFO {

	AT91S_DataflashDesc 	Desc;
	AT91S_DataflashFeatures Device; /* Pointer on a dataflash features array */
	unsigned long 			logical_address;
	unsigned int 			id;			/* device id */
} AT91S_DATAFLASH_INFO, *AT91PS_DATAFLASH_INFO;


/*-------------------------------------------------------------------------------------------------*/
#define AT45DB041		0x24//0x1c
#define AT45DB161		0x2c
#define AT45DB041E		0x25
//#define AT45DB321		0x34
#define AT45DB321		0x27
//#define AT45DB642		0x3c
#define AT45DB642		0x28
#define AT45DB128		0x10
#define AT45DB641E	    0x29//	0x28 + 1 //my	for adesto

#define AT91C_DATAFLASH_TIMEOUT		100000	/* For AT91F_DataFlashWaitReady */
#define AT91C_DATAFLASH_TIMEOUTX	400000 //? temporary?	/* For AT91F_DataFlashWaitReadyx */

/* DataFlash return value */
#define AT91C_DATAFLASH_BUSY			0x00
#define AT91C_DATAFLASH_OK				0x01
#define AT91C_DATAFLASH_ERROR			0x02
#define AT91C_DATAFLASH_MEMORY_OVERFLOW	0x03
#define AT91C_DATAFLASH_BAD_COMMAND		0x04
#define AT91C_DATAFLASH_BAD_ADDRESS		0x05


/* Driver State */
#define IDLE		0x0
#define BUSY		0x1
#define ERROR		0x2

/* DataFlash Driver State */
#define GET_STATUS	0x0F

/*-------------------------------------------------------------------------------------------------*/
/* Command Definition  */
/*-------------------------------------------------------------------------------------------------*/

/* READ COMMANDS */
#define DB_CONTINUOUS_ARRAY_READ	0xE8	/* Continuous array read */
#define DB_CONTINUOUS_ARRAY_READX	0x68	/* Continuous array read */

#define DB_BURST_ARRAY_READ			0xE8	/* Burst array read */
#define DB_PAGE_READ				0xD2	/* Main memory page read */
#define DB_BUF1_READ				0xD4	/* Buffer 1 read */
#define DB_BUF2_READ				0xD6	/* Buffer 2 read */
#define DB_STATUS					0xD7	/* Status Register */
#define DB_MANUF					0x9F	/* Manufacturer */	//my
#define DB_RESET					0xF0	/* Soft Reset */	//my



/* PROGRAM and ERASE COMMANDS */
#define DB_BUF1_WRITE				0x84	/* Buffer 1 write */
#define DB_BUF2_WRITE				0x87	/* Buffer 2 write */
#define DB_BUF1_PAGE_ERASE_PGM		0x83	/* Buffer 1 to main memory page program with built-In erase */
#define DB_BUF1_PAGE_ERASE_FASTPGM	0x93	/* Buffer 1 to main memory page program with built-In erase, Fast program */
#define DB_BUF2_PAGE_ERASE_PGM		0x86	/* Buffer 2 to main memory page program with built-In erase */
#define DB_BUF2_PAGE_ERASE_FASTPGM	0x96	/* Buffer 1 to main memory page program with built-In erase, Fast program */
#define DB_BUF1_PAGE_PGM			0x88	/* Buffer 1 to main memory page program without built-In erase */
#define DB_BUF1_PAGE_FASTPGM		0x98	/* Buffer 1 to main memory page program without built-In erase, Fast program */
#define DB_BUF2_PAGE_PGM			0x89	/* Buffer 2 to main memory page program without built-In erase */
#define DB_BUF2_PAGE_FASTPGM		0x99	/* Buffer 1 to main memory page program without built-In erase, Fast program */
#define DB_PAGE_ERASE				0x81	/* Page Erase */
#define DB_BLOCK_ERASE				0x50	/* Block Erase */
#define DB_PAGE_PGM_BUF1			0x82	/* Main memory page through buffer 1 */
#define DB_PAGE_FASTPGM_BUF1		0x92	/* Main memory page through buffer 1, Fast program */
#define DB_PAGE_PGM_BUF2			0x85	/* Main memory page through buffer 2 */
#define DB_PAGE_FastPGM_BUF2		0x95	/* Main memory page through buffer 2, Fast program */

/* ADDITIONAL COMMANDS */
#define DB_PAGE_2_BUF1_TRF			0x53	/* Main memory page to buffer 1 transfert */
#define DB_PAGE_2_BUF2_TRF			0x55	/* Main memory page to buffer 2 transfert */
#define DB_PAGE_2_BUF1_CMP			0x60	/* Main memory page to buffer 1 compare */
#define DB_PAGE_2_BUF2_CMP			0x61	/* Main memory page to buffer 2 compare */
#define DB_AUTO_PAGE_PGM_BUF1		0x58	/* Auto page rewrite throught buffer 1 */
#define DB_AUTO_PAGE_PGM_BUF2		0x59	/* Auto page rewrite throught buffer 2 */

/*-------------------------------------------------------------------------------------------------*/

extern AT91S_DATAFLASH_INFO dataflash_info[CFG_MAX_DATAFLASH_BANKS];
extern AT91S_DATAFLASH_INFO dataflash_infox[CFG_MAX_DATAFLASH_BANKSX];

extern void AT91F_SpiInit (void);
extern int AT91F_DataflashProbe (int i, AT91PS_DataflashDesc pDesc);
extern int AT91F_DataflashProbex (int i, AT91PS_DataflashDesc pDesc);

extern int AT91F_DataFlashRead (AT91PS_DataFlash, unsigned long , unsigned long, char *);	
extern int AT91F_DataFlashReadx (AT91PS_DataFlash, unsigned long , unsigned long, char *);							
extern AT91S_DataFlashStatus AT91F_DataFlashWrite(AT91PS_DataFlash ,unsigned char *, int, int);
extern int AT91F_DataflashInit (void);
extern int AT91F_DataflashInitx (void);

extern void AT91F_DataflashPrintInfo(void);
extern int addr_dataflash (unsigned long addr);
extern int read_dataflash (unsigned long addr, unsigned long size, char *result);
extern int write_dataflash (unsigned long addr_dest, unsigned int addr_src, unsigned int size);
//#ifdef XIL_FLASH
extern int write_dataflashx (unsigned long addr_dest, unsigned int addr_src, unsigned int size);
extern AT91S_DataFlashStatus AT91F_DataFlashWritex(AT91PS_DataFlash ,unsigned char *, int, int);
//#endif
#endif
