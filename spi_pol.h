#ifndef _spi_pol_h_
#define _spi_pol_h_ 1
/*HEADER******************************************************************
**************************************************************************
*** 
*** Copyright (c) 1989-2005 ARC International
*** All rights reserved                                          
***                                                              
*** This software embodies materials and concepts which are      
*** confidential to ARC International and is made
*** available solely pursuant to the terms of a written license   
*** agreement with ARC International             
***
*** File: spi_pol.h
***
*** Comments:      
***   This include file is used to provide information needed by
***   applications using the SPI I/O functions.
***
**************************************************************************
*END*********************************************************************/

#include <io_pcb.h>

/*--------------------------------------------------------------------------*/
/*
**                            CONSTANT DEFINITIONS
*/

/* SPI buffer size */
#define DEFAULT_SPI_RX_BUFFER_SIZE 128
#define DEFAULT_SPI_TX_BUFFER_SIZE 128
                                                 
/*
** SPI Transfer size 
*/
#define SPI_SPMODE_4_BITS     0x03
#define SPI_SPMODE_5_BITS     0x04
#define SPI_SPMODE_6_BITS     0x05
#define SPI_SPMODE_7_BITS     0x06
#define SPI_SPMODE_8_BITS     0x07
#define SPI_SPMODE_9_BITS     0x08
#define SPI_SPMODE_10_BITS    0x09
#define SPI_SPMODE_11_BITS    0x0A
#define SPI_SPMODE_12_BITS    0x0B
#define SPI_SPMODE_13_BITS    0x0C
#define SPI_SPMODE_14_BITS    0x0D
#define SPI_SPMODE_15_BITS    0x0E
#define SPI_SPMODE_16_BITS    0x0F

#define SPI_TRANSFER_4_BITS   4
#define SPI_TRANSFER_8_BITS   8
#define SPI_TRANSFER_16_BITS  16


/* At this time only min., max. and mid. supported */
#define SPI_MAX_TRANSFER_SIZE  SPI_SPMODE_16_BITS
#define SPI_MIN_TRANSFER_SIZE  SPI_SPMODE_4_BITS
#define SPI_MID_TRANSFER_SIZE  SPI_SPMODE_8_BITS

/* chip select states */
#define SPI_CHIP_SELECT_SET_1  1
#define SPI_CHIP_SELECT_SET_0  0


/* 
** IOCTL calls specific to SPI 
*/
#define IO_IOCTL_SPI_CLEAR_RX_CHARS                   (0x0211)
#define IO_IOCTL_SPI_RETURN_IMMEDIATE                 (0x0212)
#define IO_IOCTL_SPI_GET_CURRENT_MODE                 (0x0213)
#define IO_IOCTL_SPI_SET_MASTER_MODE                  (0x0214)
#define IO_IOCTL_SPI_SET_SLAVE_MODE                   (0x0215)
#define IO_IOCTL_SPI_CHIP_SELECT                      (0x0216)
#define IO_IOCTL_SPI_SET_CHIP_SELECT_STATE            (0x0217)
#define IO_IOCTL_SPI_DISABLE_DEVICE                   (0x0218)
#define IO_IOCTL_SPI_ENABLE_DEVICE                    (0x0219)
#define IO_IOCTL_SPI_GET_LAST_TX_STATUS               (0x0220)
#define IO_IOCTL_SPI_GET_LAST_RX_STATUS               (0x0221)
#define IO_IOCTL_SPI_SET_MASTER_READ_SIZE             (0x0222)
#define IO_IOCTL_SPI_SET_CONTROLLER_SLAVE_ADDRESS     (0x0223)
#define IO_IOCTL_SPI_SET_TRANSFER_MODE                (0x0224)
#define IO_IOCTL_SPI_SET_TRANSFER_SIZE                (0x0225)

/* 
** SPI device modes of operation 
*/
#define SPI_DEVICE_SLAVE_MODE             (0x021A) // Not supported
#define SPI_DEVICE_MASTER_MODE            (0x021B) 
#define SPI_DEVICE_MULMAS_MODE            (0x021C) // Multi master not supported 
#define SPI_DEVICE_LPBACK_MODE			  (0x021D)

/*
** SPI TX/RX Event Status
*/
#define SPI_TX_BUFFER                (0x0001)
#define SPI_TX_ERROR                 (0x0002)

#define SPI_RX_BUSY                  (0x0004)
#define SPI_RX_BUFFER                (0x0008)

/*
** SPI Buffer Status
*/
#define SPI_TX_NOACK                 (0x0010)
#define SPI_TX_UNDERRUN              (0x0020)
#define SPI_TX_COLLISION             (0x0040)

#define SPI_RX_OVERRUN               (0x0080)

/*
** different choose for SPI clock polarity and phase
*/
#define SPI_CLK_POL_PHA_MODE1		(0x0001) /* Inactive state of SPICLK is low & 
											    SPICLK transitions middle of bit timing */

#define SPI_CLK_POL_PHA_MODE2		(0x0002) /* Inactive state of SPICLK is low & 
											    SPICLK transitions begining of bit timing */

#define SPI_CLK_POL_PHA_MODE3		(0x0003) /* Inactive state of SPICLK is high & 
											    SPICLK transitions begining of bit timing */

#define SPI_CLK_POL_PHA_MODE4		(0x0004) /* Inactive state of SPICLK is high & 
											    SPICLK transitions middle of bit timing */

/*
** SPI Chip Selects
*/
#define SPI_CS0         0x0E
#define SPI_CS1			0x0D
#define SPI_CS2			0x0B
#define SPI_CS3			0x07


/*--------------------------------------------------------------------------*/
/*
**                            FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif
typedef struct at91rm9200_spi_init_struct
{
   /* Device Name */
   uint_32 DEVICE;

   /* The serial I/O queue size to use to buffer incoming and outgoing
   ** data.
   */
   _mqx_uint QUEUE_SIZE;

   /* The baud rate for the channel */
   uint_32   BAUD_RATE;

   /* The number of bits in a character */
   _mqx_uint BITS_PER_CHARACTER;

   /* The parity to initialize the channel to */
   _mqx_uint PARITY;

   /* The number of stop bits */
   _mqx_uint STOP_BITS;

   /* The word length */
   uint_32 WORD_SIZE;

   /* The com ports vector number */
   _mqx_uint VECTOR;

   /* The Clock speed to the uart */
   uint_32   CLOCK_SPEED;

   /* FIQ/IRQ selection */
   uchar FIQIRQ;

} AT91RM9200_SPI_INIT_STRUCT, _PTR_ AT91RM9200_SPI_INIT_STRUCT_PTR;

extern uint_32 _io_spi_polled_install(
      char_ptr,
      uint_32 (_CODE_PTR_)(pointer, char _PTR_),
      uint_32 (_CODE_PTR_)(pointer, pointer),
 //     char (_CODE_PTR_)(pointer, char _PTR_),
		     char (_CODE_PTR_)(pointer, char _PTR_, _mqx_int),
      uint_32 (_CODE_PTR_)(pointer, char _PTR_, uint_32),
      uint_32 (_CODE_PTR_)(pointer, uint_32, uint_32_ptr),
      pointer);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
