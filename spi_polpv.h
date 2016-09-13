#ifndef _spi_polpv_h_
#define _spi_polpv_h_ 1
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
*** File: spi_polpv.h
***
*** Comments:      
***   This file includes the private definitions for the polled SPI
***  serial I/O drivers.
***
**************************************************************************
*END*********************************************************************/


#include <timer.h>


/*--------------------------------------------------------------------------*/
/*
**                            CONSTANT DEFINITIONS
*/


/* This is for verificatin on the first message byte. */
/* A 1 in the bit 0 (LSB) position is a read */
#define SPI_READ_MASK          0x01

#define SPI_MAX_NUM_RETRIES    0x10 /* 16 arbitrary, choose whatever's best */
#define SPI_MASTER_READ_ADDR_ERROR (0)

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/

/*---------------------------------------------------------------------
**
** IO SPI POLLED DEVICE STRUCT
**
** This structure used to store information about an SPI polled io device
** for the IO device table
*/
typedef struct io_spi_polled_device_struct
{

   /* The I/O init function */
   uint_32 (_CODE_PTR_ DEV_INIT)(pointer, char _PTR_);

   /* The I/O deinit function */
   uint_32 (_CODE_PTR_ DEV_DEINIT)(pointer, pointer);
   
   /* [IN] The READ function */
   //uint_32 (_CODE_PTR_ DEV_READ)(pointer, char_ptr, _mqx_int);
   char (_CODE_PTR_ DEV_READ)(pointer, char_ptr, _mqx_int);
      
   /* [IN] The WRITE function */
   uint_32 (_CODE_PTR_ DEV_WRITE)(pointer, char_ptr,  uint_32);
   
   /* The ioctl function, (change bauds etc) */
   uint_32 (_CODE_PTR_ DEV_IOCTL)(pointer, uint_32, uint_32_ptr);

   /* The I/O channel initialization data */
   pointer             DEV_INIT_DATA_PTR;
   
   /* Device specific information */
   pointer             DEV_INFO_PTR;

   /* Open count for number of accessing file descriptors */
   uint_32             COUNT;

   /* Open flags for this channel */
   uint_32             FLAGS;
   
   /* This is used to abort the current read or write immediately */
   boolean             ABORT;
   
   /* This is to let the upper layer know we've read the last chars */
   boolean             LAST_RX_CHARS;
   
   /* Can be Master, Slave, or MSLV -- a master that lost arbitration */
   uint_32             DEV_MODE;
   
   /* This is the timer id used for timed reads */
   _timer_id           TIMER_ID;
   
   /* 
   ** This lets us know that the slave is transmitting, 
   ** so we can delete the station address from the Rx buffer.
   */
   boolean             SLAVE_TX;
   
   boolean             SLAVE_RX_BD;
   
   boolean             MASTER_RX_BD;
   
   boolean             READING;
   
   /* Remove this when we start using the timeout lwsem */
   boolean             OCCUPIED;
   
   /* Pointer to the buffer to use for current Rx data */
   uchar _PTR_         RX_BUFF;
   
   /* The size left in the RX_BUFF */ 
   uint_32             RX_BUFF_SIZE;
   
   /* Light weight semaphore struct */
   LWSEM_STRUCT         LWSEM;

} IO_SPI_POLLED_DEVICE_STRUCT, _PTR_ IO_SPI_POLLED_DEVICE_STRUCT_PTR;


/*--------------------------------------------------------------------------*/
/*
**                            FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

/* I/O prototypes */
extern _mqx_int _io_spi_polled_open(FILE_DEVICE_STRUCT_PTR, char _PTR_, char _PTR_);
extern _mqx_int _io_spi_polled_close(FILE_DEVICE_STRUCT_PTR);
extern _mqx_int _io_spi_polled_read(FILE_DEVICE_STRUCT_PTR, char_ptr, _mqx_int);
extern _mqx_int _io_spi_polled_write(FILE_DEVICE_STRUCT_PTR, char_ptr, _mqx_int);
extern _mqx_int _io_spi_polled_ioctl(FILE_DEVICE_STRUCT_PTR, _mqx_uint, pointer);


#ifdef __cplusplus
}
#endif

#endif
/* EOF */
