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
*** File: spi_pol.c
***
*** Comments:      
***   This file contains the SPI polled I/O (master) driver functions.
***                                                               
**************************************************************************
*END*********************************************************************/

#include "mqx_inc.h"
#include "fio.h"
#include "fio_prv.h"
#include "io.h"
#include "io_prv.h"
#include "serial.h"
#include "spi_pol.h"
#include "spi_polpv.h"


/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : _io_spi_polled_install
* Returned Value   : uint_32 a task error code or MQX_OK
* Comments         :
*    Install the spi device.
*
*END*----------------------------------------------------------------------*/

_mqx_uint _io_spi_polled_install
   (
      /* [IN] A string that identifies the device for fopen */
      char_ptr            identifier,
  
      /* [IN] The I/O init function */
      uint_32 (_CODE_PTR_ init)(pointer, char _PTR_),
      
      /* [IN] The I/O de-init function */
      uint_32 (_CODE_PTR_ deinit)(pointer, pointer),
      
      /* [IN] The input function */
      char     (_CODE_PTR_ recv1)(pointer, char _PTR_, _mqx_int),
     
      /* [IN] The output function */
      uint_32 (_CODE_PTR_ xmit)(pointer, char _PTR_, uint_32),

      /* [IN] The I/O ioctl function */
      uint_32 (_CODE_PTR_ ioctl)(pointer, uint_32, uint_32_ptr),

      /* [IN] The I/O init data pointer */
      pointer             init_data_ptr
      
   )

{ /* Body */
   IO_SPI_POLLED_DEVICE_STRUCT_PTR pol_io_dev_ptr;

   pol_io_dev_ptr = _mem_alloc_system_zero((uint_32)
      sizeof(IO_SPI_POLLED_DEVICE_STRUCT));

#if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
   if (pol_io_dev_ptr == NULL) {
      return(MQX_OUT_OF_MEMORY);
   } /* Endif */
#endif

   pol_io_dev_ptr->DEV_INIT          = init;
   pol_io_dev_ptr->DEV_DEINIT        = deinit;
   pol_io_dev_ptr->DEV_READ          = recv1;
   pol_io_dev_ptr->DEV_WRITE         = xmit;
   pol_io_dev_ptr->DEV_IOCTL         = ioctl;
   pol_io_dev_ptr->DEV_INIT_DATA_PTR = init_data_ptr;
   
//   return (_io_dev_install(identifier,
    return (_io_dev_install1(identifier,
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char _PTR_, char _PTR_))_io_spi_polled_open,
      (_mqx_int (_CODE_PTR_)(FILE_PTR))                        _io_spi_polled_close,
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char_ptr, _mqx_int))    _io_spi_polled_read, 
      (_mqx_int (_CODE_PTR_)(FILE_PTR, char_ptr, _mqx_int))    _io_spi_polled_write, 
      (_mqx_int (_CODE_PTR_)(FILE_PTR, _mqx_uint, pointer))    _io_spi_polled_ioctl,
      (pointer)pol_io_dev_ptr)); 

} /* Endbody */


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _io_spi_polled_uninstall
* Returned Value   : _mqx_int a task error code or MQX_OK
* Comments         :
*    Un-Install a polled serial device.
*
*END*----------------------------------------------------------------------*/

_mqx_int _io_spi_polled_uninstall
   (
      /* [IN] The IO device structure for the device */
      IO_DEVICE_STRUCT_PTR   io_dev_ptr
   )
{ /* Body */
   IO_SPI_POLLED_DEVICE_STRUCT_PTR polled_dev_ptr = io_dev_ptr->DRIVER_INIT_PTR;

   if (polled_dev_ptr->COUNT == 0) {
      if (polled_dev_ptr->DEV_DEINIT) {
         (*polled_dev_ptr->DEV_DEINIT)(polled_dev_ptr->DEV_INIT_DATA_PTR,
            polled_dev_ptr->DEV_INFO_PTR);
      } /* Endif */
      _mem_free(polled_dev_ptr);
      io_dev_ptr->DRIVER_INIT_PTR = NULL;
      return(IO_OK);
   } else {
      return(IO_ERROR_DEVICE_BUSY);
   } /* Endif */

} /* Endbody */


/*FUNCTION****************************************************************
* 
* Function Name    : _io_spi_polled_open
* Returned Value   : int_32 error code
* Comments         :
*    This routine initializes the spi I/O channel. It acquires
*    memory, then stores information into it about the channel.
*    It then calls the hardware interface function to initialize the channel.
* 
*END**********************************************************************/

_mqx_int _io_spi_polled_open
   (
      /* [IN] the file handle for the device being opened */
      FILE_DEVICE_STRUCT_PTR         fd_ptr,
       
      /* [IN] the remaining portion of the name of the device */
      char                     _PTR_ open_name_ptr,

      /* [IN] the flags to be used during operation:
      ** echo, translation, xon/xoff.
      */
      char                     _PTR_ flags
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR               io_dev_ptr;
   IO_SPI_POLLED_DEVICE_STRUCT_PTR    pol_io_dev_ptr;
   _mqx_int                           result = MQX_OK;

   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   pol_io_dev_ptr = (IO_SPI_POLLED_DEVICE_STRUCT_PTR)(io_dev_ptr->DRIVER_INIT_PTR);
   
   if (pol_io_dev_ptr->COUNT) {
      /* Device is already opened */
      pol_io_dev_ptr->COUNT++;
      fd_ptr->FLAGS = pol_io_dev_ptr->FLAGS;
      return(result);
   } /* Endif */
      
   pol_io_dev_ptr->FLAGS = (uint_32)flags;
   fd_ptr->FLAGS         = (uint_32)flags;
            
   result = (*pol_io_dev_ptr->DEV_INIT)(pol_io_dev_ptr, open_name_ptr);
   if (result == MQX_OK) {
      pol_io_dev_ptr->COUNT = 1;
      pol_io_dev_ptr->DEV_MODE = SPI_DEVICE_MASTER_MODE;
      pol_io_dev_ptr->RX_BUFF = NULL;
      pol_io_dev_ptr->MASTER_RX_BD = FALSE;
   } /* Endif */
   
   return(result);

} /* Endbody */



/*FUNCTION****************************************************************
* 
* Function Name    : _io_spi_polled_close
* Returned Value   : int_32 error code
* Comments         :
*    This routine closes the SPI I/O channel.
* 
*END**********************************************************************/

_mqx_int _io_spi_polled_close
   (
      /* [IN] the file handle for the device being closed */
      FILE_DEVICE_STRUCT_PTR fd_ptr
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR            io_dev_ptr;
   IO_SPI_POLLED_DEVICE_STRUCT_PTR pol_io_dev_ptr;
   _mqx_int                        result = MQX_OK;

   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   pol_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   if (--pol_io_dev_ptr->COUNT == 0) {
      if (pol_io_dev_ptr->DEV_DEINIT) {
         result = (*pol_io_dev_ptr->DEV_DEINIT)(pol_io_dev_ptr->DEV_INIT_DATA_PTR,
            pol_io_dev_ptr->DEV_INFO_PTR);
      } /* Endif */ 
   } /* Endif */
   return(result);

} /* Endbody */


  
/*FUNCTION****************************************************************
* 
* Function Name    : _io_spi_polled_read
* Returned Value   : int_32 number of characters read
* Comments         :
*    Reads bytes into array from SPI input buffers.
*    Returns number of characters received, or 0 if timed-out
*
*END*********************************************************************/

_mqx_int _io_spi_polled_read
   (
      /* [IN] the handle returned from _fopen */
      FILE_DEVICE_STRUCT_PTR          fd_ptr,

      /* [IN] where the characters are to be stored */
      char_ptr                        data_ptr,

      /* [IN] timeout (immediate return if 0) */
      _mqx_int                        timeout
   )
{  /* Body */

   IO_DEVICE_STRUCT_PTR                  io_dev_ptr;
   IO_SPI_POLLED_DEVICE_STRUCT_PTR       pol_io_dev_ptr;
   _mqx_int                              num = 0;
   
   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   pol_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   num = (*pol_io_dev_ptr->DEV_READ)(pol_io_dev_ptr, data_ptr, timeout);

   return( num );

}  /* Endbody */



/*FUNCTION****************************************************************
* 
* Function Name    : _io_spi_polled_write
* Returned Value   : void
* Comments         :
*    This routine calls the appropriate write routine.
*
*END**********************************************************************/

_mqx_int _io_spi_polled_write
   (
      /* [IN] the handle returned from _fopen */
      FILE_DEVICE_STRUCT_PTR    fd_ptr,

      /* [IN] where the characters are */
      char_ptr  data_ptr,

      /* [IN] the number of characters to output */
      _mqx_int  n
   )
{  /* Body */
   IO_DEVICE_STRUCT_PTR                 io_dev_ptr;
   IO_SPI_POLLED_DEVICE_STRUCT_PTR      pol_io_dev_ptr;
   _mqx_int                             num = 0;
   
   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   pol_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;
               
   if ( pol_io_dev_ptr->DEV_MODE == SPI_DEVICE_MASTER_MODE ) {
      num = (*pol_io_dev_ptr->DEV_WRITE)(pol_io_dev_ptr, data_ptr, n);
   }  /* Endif */
   
   return( num );
              
} /* Endbody */
   
   
   
/*FUNCTION*****************************************************************
* 
* Function Name    : _io_spi_polled_ioctl
* Returned Value   : int_32
* Comments         :
*    Returns result of spi ioctl operation.
*
*END*********************************************************************/

_mqx_int _io_spi_polled_ioctl
   (
      /* [IN] the file handle for the device */
      FILE_DEVICE_STRUCT_PTR fd_ptr,

      /* [IN] the ioctl command */
      _mqx_uint              cmd,

      /* [IN] the ioctl parameters */
      pointer                input_param_ptr
   )
{ /* Body */
   IO_DEVICE_STRUCT_PTR               io_dev_ptr;
   IO_SPI_POLLED_DEVICE_STRUCT_PTR    pol_io_dev_ptr;
   _mqx_int                           result = MQX_OK;
//   uint_32                            old_value;
   uint_32_ptr                        param_ptr = (uint_32_ptr)input_param_ptr;

   io_dev_ptr     = (IO_DEVICE_STRUCT_PTR)fd_ptr->DEV_PTR;
   pol_io_dev_ptr = (pointer)io_dev_ptr->DRIVER_INIT_PTR;

   switch (cmd) {

      case IO_IOCTL_SPI_GET_CURRENT_MODE:
         *param_ptr = pol_io_dev_ptr->DEV_MODE;
         break;

      case IO_IOCTL_SPI_SET_MASTER_MODE:
         pol_io_dev_ptr->DEV_MODE = SPI_DEVICE_MASTER_MODE;
         *param_ptr = pol_io_dev_ptr->DEV_MODE;
         break;

      case IO_IOCTL_SPI_SET_SLAVE_MODE:
         pol_io_dev_ptr->DEV_MODE = SPI_DEVICE_SLAVE_MODE;
         *param_ptr = pol_io_dev_ptr->DEV_MODE;
         break;      

      case IO_IOCTL_SERIAL_GET_FLAGS:
         *param_ptr = pol_io_dev_ptr->FLAGS;
         break;

      case IO_IOCTL_SERIAL_SET_FLAGS:
         pol_io_dev_ptr->FLAGS = *param_ptr;
         fd_ptr->FLAGS = *param_ptr;
         break;
                             
     default:
        if (pol_io_dev_ptr->DEV_IOCTL != NULL) {
           result = (*pol_io_dev_ptr->DEV_IOCTL)(pol_io_dev_ptr->DEV_INFO_PTR, 
              cmd, param_ptr);
        } /* Endif */
        break;             
   } /* Endswitch */
   return result;

} /* Endbody */





