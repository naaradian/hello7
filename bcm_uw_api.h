/*****************************************************************************************   
* MaxLinear, Inc. retains all right, title and interest (including all intellectual
* property rights) in and to this computer program, which is protected by applicable
* intellectual property laws.  Unless you have obtained a separate written license from
* MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., you are not authorized
* to utilize all or a part of this computer program for any purpose (including
* reproduction, distribution, modification, and compilation into object code), and you
* must immediately destroy or return all copies of this computer program.  If you are
* licensed by MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., your rights
* to utilize this computer program are limited by the terms of that license.
*
* This computer program contains trade secrets owned by MaxLinear, Inc. and, unless
* authorized by MaxLinear, Inc. in writing, you agree to maintain the confidentiality
* of this computer program and related information and to not disclose this computer
* program and related information to any other person or entity.
*
* Misuse of this computer program or any information contained in it may results in
* violations of applicable law.  MaxLinear, Inc. vigorously enforces its copyright,
* trade secret, patent, contractual, and other legal rights.
*
* THIS COMPUTER PROGRAM IS PROVIDED �AS IS� WITHOUT ANY WARRANTIES, AND MAXLINEAR, INC.
* EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE WARRANTIES OF
* MERCHANTIBILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NONINFRINGEMENT.
****************************************************************************************
*                                        Copyright (c) 2012, MaxLinear, Inc.
****************************************************************************************/



#ifndef _BCM_UW_API_H_
#define _BCM_UW_API_H_

    #ifdef __cplusplus
    extern "C" {
    #endif

    #ifdef HOSTDRIVER_EXPORTS
        #define DLLEXPORT __declspec(dllexport)
    #else
        #define DLLEXPORT
    #endif

#include "defs_uw.h"

//-----------------------------------------------------------
// defines
//-----------------------------------------------------------
#define BCM_UW_LONG_API_PROBE_TIMEOUT_MSEC       100
#define BCM_UW_FLASH_INFO_MAX_SIZE               16

//agc table row size
#define BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS     81
#define BCM_UW_WB_AGC_DB_TO_DAC_TABLE_ROWS       256
#define BCM_UW_WB_TXAGC_ADC_TO_DBM_TABLE_ROWS    161
#define BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_ROWS     121

//-----------------------------------------------------------
// enums
// ** update also mdp enum **
//-----------------------------------------------------------
/*
typedef enum {
    //success
    BCM_UW_SUCCESS_MSG_E,                                           //= 0

    //boot errors
    BCM_UW_BOOT_DATA_TOO_BIG_E,                                     //= 1
    BCM_UW_BOOT_DATA_TOO_SMALL_E,                                   //= 2
    BCM_UW_BOOT_DATA_WRONG_INDEX_E,                                 //= 3
    BCM_UW_BOOT_INVALID_CHECKSUM_E,                                 //= 4
    BCM_UW_BOOT_INVALID_JUMP_ADDRESS_E,                             //= 5
    BCM_UW_BOOT_OPCODE_UNEXPECTED_E,                                //= 6
    BCM_UW_BOOT_FW_NOT_ALIVE_E,                                     //= 7
    BCM_UW_FW_NOT_ALIVE_E,                                          //= 8
    BCM_UW_BOOT_PLL_ERROR_E,                                        //= 9
    BCM_UW_BOOT_DDR_ERROR_E,                                        //= 10, N/A 650

    //Communication Layer errors
    BCM_UW_INVALID_MSG_RX_E,                                        //= 11
    BCM_UW_INVALID_MSG_OPCODE_E,                                    //= 12
    BCM_UW_ERROR_IN_COM_RECEIVE_E,                                  //= 13
    BCM_UW_INVALID_MODEM_INDEX_E,                                   //= 14
    BCM_UW_HOST_BUSY_E,                                             //= 15
    BCM_UW_INVALID_PARAMS_E,                                        //= 16
    BCM_UW_MEDIA_NOT_INITIALIZED_E,                                 //= 17
    BCM_UW_INVALID_MEDIA_E,                                         //= 18
    BCM_UW_INVALID_DEVICE_INDEX_E,                                  //= 19

    //Config File errors
    BCM_UW_ERROR_CFG_FILE_LEN_TOO_BIG_E,                            //= 20
    BCM_UW_ERROR_CFG_FILE_LEN_TOO_SMALL_E,                          //= 21
    BCM_UW_ERROR_CFG_FILE_CRC_E,                                    //= 22
    BCM_UW_ERROR_CFG_FILE_UNKNOWN_RECORD_TYPE_E,                    //= 23
    BCM_UW_ERROR_CFG_FILE_VERSION_E,                                //= 24
    BCM_UW_ERROR_CFG_FILE_ALREADY_CONFIGURED_E,                     //= 25
    BCM_UW_ERROR_CFG_FILE_TIMEOUT_E,                                //= 26  !used

    //Peripherals errors
    BCM_UW_PERIPHERAL_NOT_READY_E,                                  //= 27
    BCM_UW_PERIPHERAL_TOO_MANY_BYTES_E,                             //= 28
    BCM_UW_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E,             //= 29
    BCM_UW_PERIPHERAL_I2C_ERROR_E,                                  //= 30
    BCM_UW_PERIPHERAL_SPI_ERROR_E,                                  //= 31
    BCM_UW_PERIPHERAL_TIMEOUT_E,                                    //= 32
    BCM_UW_PERIPHERAL_INVALID_SLAVE_ADDRESS_E,                      //= 33

    //API errors
    BCM_UW_ERROR_NOT_CONFIGURED_E,                                  //= 34
    BCM_UW_IQ_SAMPLES_GET_ERROR_E,                                  //= 35
    BCM_UW_LOOPBACK_INVALID_REQUEST_E,                              //= 36
    BCM_UW_ERROR_IN_SWITCH_E,                                       //= 37
    BCM_UW_ERROR_ACM_ENGINE_ENABLED_E,                              //= 38
    BCM_UW_ACM_IMPROVE_REQUEST_EXPIRED_E,                           //= 39
    BCM_UW_TEST_BUS_BUSY_E,                                         //= 40
    BCM_UW_HOST_MAILBOX_EMPTY_E,                                    //= 41
    BCM_UW_HOST_MAILBOX_FULL_E,                                     //= 42

    //General API errors
    BCM_UW_API_GENERAL_ERROR_E,                                     //= 43
    BCM_UW_API_NOT_SUPPORTED_E,                                     //= 44
    BCM_UW_API_INVALID_PARAMS_E,                                    //= 45
    BCM_UW_API_NOT_READY_E,                                         //= 46

    //Misc
    BCM_UW_MODEM_RECONFIG_ERROR_E,                                  //= 47
    BCM_UW_ETH_UCODE_ERROR_E,                                       //= 48
    BCM_UW_ETH_IO_ERROR_E,                                          //= 49

    //DSP
    BCM_UW_DSP_APP_LOAD_INVALID_CHECKSUM_E,                         //= 50
    BCM_UW_DSP_APP_LOAD_DATA_LEN_ERR_E,                             //= 51
    BCM_UW_DSP_APP_LOAD_NOT_DONE_E,                                 //= 52
    BCM_UW_DSP_BOOT_LOADER_NOT_SET_E,                               //= 53

    //FLASH
    BCM_UW_FLASH_ERROR_E,                                           //= 54
    BCM_UW_FLASH_FILE_SYSTEM_ERROR_E,                               //= 55

    //RF
    BCM_UW_RF_ERROR_E                                                 = 230,

} BCM_UW_ERROR_MSG_ENUM;
 */
#define     BCM_UW_SUCCESS_MSG_E                        (0)                    //= 0

    //boot errors
#define     BCM_UW_BOOT_DATA_TOO_BIG_E                  (1)                    //= 1
#define     BCM_UW_BOOT_DATA_TOO_SMALL_E                (2)                  //= 2
#define     BCM_UW_BOOT_DATA_WRONG_INDEX_E              (3)                    //= 3
#define     BCM_UW_BOOT_INVALID_CHECKSUM_E              (4)                   //= 4
#define     BCM_UW_BOOT_INVALID_JUMP_ADDRESS_E          (5)                   //= 5
#define     BCM_UW_BOOT_OPCODE_UNEXPECTED_E             (6)                   //= 6
#define     BCM_UW_BOOT_FW_NOT_ALIVE_E                  (7)                   //= 7
#define     BCM_UW_FW_NOT_ALIVE_E                       (8)                  //= 8
#define     BCM_UW_BOOT_PLL_ERROR_E                     (9)                   //= 9
#define     BCM_UW_BOOT_DDR_ERROR_E                     (10)                   //= 10, N/A 650

    //Communication Layer errors						  
#define     BCM_UW_INVALID_MSG_RX_E                     (11)                  //= 11
#define     BCM_UW_INVALID_MSG_OPCODE_E                 (12)                   //= 12
#define     BCM_UW_ERROR_IN_COM_RECEIVE_E               (13)                  //= 13
#define     BCM_UW_INVALID_MODEM_INDEX_E                (14)                   //= 14
#define     BCM_UW_HOST_BUSY_E                          (15)                   //= 15
#define     BCM_UW_INVALID_PARAMS_E                     (16)                   //= 16
#define     BCM_UW_MEDIA_NOT_INITIALIZED_E              (17)                   //= 17
#define     BCM_UW_INVALID_MEDIA_E                      (18)                   //= 18
#define     BCM_UW_INVALID_DEVICE_INDEX_E               (19)                   //= 19

    //Config File errors
#define     BCM_UW_ERROR_CFG_FILE_LEN_TOO_BIG_E           (20)                 //= 20
#define     BCM_UW_ERROR_CFG_FILE_LEN_TOO_SMALL_E         (21)                 //= 21
#define     BCM_UW_ERROR_CFG_FILE_CRC_E                   (22)                 //= 22
#define     BCM_UW_ERROR_CFG_FILE_UNKNOWN_RECORD_TYPE_E   (23)                 //= 23
#define     BCM_UW_ERROR_CFG_FILE_VERSION_E               (24)                 //= 24
#define     BCM_UW_ERROR_CFG_FILE_ALREADY_CONFIGURED_E    (25)                 //= 25
#define     BCM_UW_ERROR_CFG_FILE_TIMEOUT_E               (26)                 //= 26  !used

    //Peripherals errors
#define     BCM_UW_PERIPHERAL_NOT_READY_E                       (27)           //= 27
#define     BCM_UW_PERIPHERAL_TOO_MANY_BYTES_E                  (28)           //= 28
#define     BCM_UW_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E  (29)           //= 29
#define     BCM_UW_PERIPHERAL_I2C_ERROR_E                       (30)           //= 30
#define     BCM_UW_PERIPHERAL_SPI_ERROR_E                       (31)           //= 31
#define     BCM_UW_PERIPHERAL_TIMEOUT_E                         (32)           //= 32
#define     BCM_UW_PERIPHERAL_INVALID_SLAVE_ADDRESS_E           (33)           //= 33

    //API errors
#define     BCM_UW_ERROR_NOT_CONFIGURED_E                       (34)           //= 34
#define     BCM_UW_IQ_SAMPLES_GET_ERROR_E                       (35)           //= 35
#define     BCM_UW_LOOPBACK_INVALID_REQUEST_E                   (36)           //= 36
#define     BCM_UW_ERROR_IN_SWITCH_E                            (37)           //= 37
#define     BCM_UW_ERROR_ACM_ENGINE_ENABLED_E                   (38)           //= 38
#define     BCM_UW_ACM_IMPROVE_REQUEST_EXPIRED_E                (39)           //= 39
#define     BCM_UW_TEST_BUS_BUSY_E                              (40)           //= 40
#define     BCM_UW_HOST_MAILBOX_EMPTY_E                         (41)           //= 41
#define     BCM_UW_HOST_MAILBOX_FULL_E                          (42)           //= 42

    //General API errors
#define     BCM_UW_API_GENERAL_ERROR_E                          (43)           //= 43
#define     BCM_UW_API_NOT_SUPPORTED_E                          (44)           //= 44
#define     BCM_UW_API_INVALID_PARAMS_E                         (45)           //= 45
#define     BCM_UW_API_NOT_READY_E                              (46)           //= 46

    //Misc
#define     BCM_UW_MODEM_RECONFIG_ERROR_E                       (47)           //= 47
#define     BCM_UW_ETH_UCODE_ERROR_E                            (48)           //= 48
#define     BCM_UW_ETH_IO_ERROR_E                               (49)           //= 49

    //DSP
#define     BCM_UW_DSP_APP_LOAD_INVALID_CHECKSUM_E              (50)           //= 50
#define     BCM_UW_DSP_APP_LOAD_DATA_LEN_ERR_E                  (51)           //= 51
#define     BCM_UW_DSP_APP_LOAD_NOT_DONE_E                      (52)           //= 52
#define     BCM_UW_DSP_BOOT_LOADER_NOT_SET_E                    (53)           //= 53

    //FLASH
#define     BCM_UW_FLASH_ERROR_E                                (54)           //= 54
#define     BCM_UW_FLASH_FILE_SYSTEM_ERROR_E                    (55)           //= 55

    //RF
#define     BCM_UW_RF_ERROR_E                                     (230)  //            = 230,

#define     BCM_UW_ERROR_MSG_ENUM   unsigned char




/*
typedef enum {
    BCM_UW_WORKING_BASIC_E,
    BCM_UW_WORKING_MAX_THROUGHPUT_E,
    BCM_UW_WORKING_MAX_PROTECTION_E,
    BCM_UW_PROTECTION_E,
    BCM_UW_WORKING_MAX_THROUGHPUT_INTERNAL_E,
    BCM_UW_WORKING_MAX_PROTECTION_INTERNAL_E,
    BCM_UW_PROTECTION_INTERNAL_E,
} BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM;
*/


#define  BCM_UW_WORKING_BASIC_E							(0)
#define  BCM_UW_WORKING_MAX_THROUGHPUT_E				(1)
#define  BCM_UW_WORKING_MAX_PROTECTION_E				(2)
#define  BCM_UW_PROTECTION_E							(3)
#define  BCM_UW_WORKING_MAX_THROUGHPUT_INTERNAL_E		(4)
#define  BCM_UW_WORKING_MAX_PROTECTION_INTERNAL_E		(5)
#define  BCM_UW_PROTECTION_INTERNAL_E					(6)

#define  BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM			unsigned char


/*
typedef enum {
    BCM_UW_COM_MEDIA_NULL_E                 = 0,                    // No media, e.g. MC reachange via GP, or unconfigured
    BCM_UW_COM_MEDIA_UART_E                 = 1,
    BCM_UW_COM_MEDIA_SPI_E                  = 2,
                                                                    // reserved due to backward compatibility
    BCM_UW_COM_MEDIA_MII_DEVICE_E           = 4,                    // MII used for host-device communication
    BCM_UW_COM_MEDIA_IP_CLIENT_E            = 5,                    // Remote connection of MDP to message relay in host. Not for host-device communication
    BCM_UW_COM_MEDIA_MAX_E                  = 6
} BCM_UW_COM_MEDIA_ENUM;
*/

#define     BCM_UW_COM_MEDIA_NULL_E                  (0)                    // No media, e.g. MC reachange via GP, or unconfigured
#define     BCM_UW_COM_MEDIA_UART_E                  (1)
#define     BCM_UW_COM_MEDIA_SPI_E                   (2)
                                                                    // reserved due to backward compatibility
#define     BCM_UW_COM_MEDIA_MII_DEVICE_E            (4)                    // MII used for host-device communication
#define     BCM_UW_COM_MEDIA_IP_CLIENT_E             (5)                    // Remote connection of MDP to message relay in host. Not for host-device communication
#define     BCM_UW_COM_MEDIA_MAX_E                   (6)
#define     BCM_UW_COM_MEDIA_ENUM			unsigned char




 /*
typedef enum {
    BCM_UW_ACQUIRE_IN_PROGRESS_E,
    BCM_UW_ACQUIRE_LOCKED_E,
    BCM_UW_ACQUIRE_FAILED_E,
    BCM_UW_ACQUIRE_NOT_ACTIVATED_E,
} BCM_UW_ACQUIRE_STATUS_ENUM;
*/

#define     BCM_UW_ACQUIRE_IN_PROGRESS_E			(0)
#define     BCM_UW_ACQUIRE_LOCKED_E					(1)
#define     BCM_UW_ACQUIRE_FAILED_E					(2)
#define     BCM_UW_ACQUIRE_NOT_ACTIVATED_E			(3)
#define     BCM_UW_ACQUIRE_STATUS_ENUM			 unsigned char

/*
typedef enum {
    BCM_UW_ACQUIRE_SUCCESS_E                   = 0,
    BCM_UW_ACQUIRE_ERR_INT_PREAMBLE_LOSS_E     = 1,
    BCM_UW_ACQUIRE_ERR_INT_BIT_LOSS_E          = 2,
    BCM_UW_ACQUIRE_ERR_FEC_ULOCKED_TIMOUT_E    = 3,
    BCM_UW_ACQUIRE_ERR_AT_FRAME_0_SYNC_E       = 4,
    BCM_UW_ACQUIRE_ERR_TIMEOUT_E               = 5,
    BCM_UW_ACQUIRE_ERR_AT_FRAME_2_SYNC_E       = 6,
    BCM_UW_ACQUIRE_ERR_FATAL_E                 = 7,
} BCM_UW_ACQUIRE_LAST_ERR_ENUM;

*/

#define     BCM_UW_ACQUIRE_SUCCESS_E                   (0)
#define     BCM_UW_ACQUIRE_ERR_INT_PREAMBLE_LOSS_E     (1)
#define     BCM_UW_ACQUIRE_ERR_INT_BIT_LOSS_E          (2)
#define     BCM_UW_ACQUIRE_ERR_FEC_ULOCKED_TIMOUT_E    (3)
#define     BCM_UW_ACQUIRE_ERR_AT_FRAME_0_SYNC_E       (4)
#define     BCM_UW_ACQUIRE_ERR_TIMEOUT_E               (5)
#define     BCM_UW_ACQUIRE_ERR_AT_FRAME_2_SYNC_E       (6)
#define     BCM_UW_ACQUIRE_ERR_FATAL_E                 (7)
#define     BCM_UW_ACQUIRE_LAST_ERR_ENUM		   unsigned char


 /*
typedef enum {
    BCM_UW_ACQUIRE_MODE_PREVIOUS_E,
    BCM_UW_ACQUIRE_MODE_AUTO_E,
    BCM_UW_ACQUIRE_MODE_MANUAL_E
} BCM_UW_ACQUIRE_MODE_ENUM;
*/

#define   BCM_UW_ACQUIRE_MODE_PREVIOUS_E     (0)
#define   BCM_UW_ACQUIRE_MODE_AUTO_E		 (1)
#define   BCM_UW_ACQUIRE_MODE_MANUAL_E		 (2)
#define   BCM_UW_ACQUIRE_MODE_ENUM			unsigned char

/*
typedef enum {
    BCM_UW_SPECTRAL_INVERSION_MODE_PREVIOUS_E,
    BCM_UW_SPECTRAL_INVERSION_MODE_NEVER_E,
    BCM_UW_SPECTRAL_INVERSION_MODE_ALWAYS_E,
    BCM_UW_SPECTRAL_INVERSION_MODE_SMART_AUTO_E
} BCM_UW_SPECTRAL_INVERSION_MODE_ENUM;
*/

#define    BCM_UW_SPECTRAL_INVERSION_MODE_PREVIOUS_E    (9)
#define    BCM_UW_SPECTRAL_INVERSION_MODE_NEVER_E		(1)
#define    BCM_UW_SPECTRAL_INVERSION_MODE_ALWAYS_E		(2)
#define    BCM_UW_SPECTRAL_INVERSION_MODE_SMART_AUTO_E	(3)
#define    BCM_UW_SPECTRAL_INVERSION_MODE_ENUM		 unsigned char



/*
typedef enum {
    BCM_UW_LOOPBACK_NONE_E,                                         // return to normal operation
    BCM_UW_LOOPBACK_INTERFACE_E,                                    // N/A 650
    BCM_UW_LOOPBACK_MODEM_E,                                        // loopback
} BCM_UW_LOOPBACK_TYPE_ENUM;
*/
#define     BCM_UW_LOOPBACK_NONE_E             (0)                            // return to normal operation
#define     BCM_UW_LOOPBACK_INTERFACE_E        (1)                            // N/A 650
#define     BCM_UW_LOOPBACK_MODEM_E            (2)                            // loopback
#define     BCM_UW_LOOPBACK_TYPE_ENUM		   unsigned char



/*
typedef enum {
    BCM_UW_PROTECTION_MODE_NONE_E,                                  //=0 - no protection , no force
    BCM_UW_PROTECTION_MODE_WORKING_E,                               //=1 - working
    BCM_UW_PROTECTION_MODE_PROTECTION_E,                            //=2 - protection
    BCM_UW_PROTECTION_MODE_RXONLY_NONE_E,                           //=3 - no protection , no force (rx only)
    BCM_UW_PROTECTION_MODE_RXONLY_WORKING_E,                        //=4 - working (rx only)
    BCM_UW_PROTECTION_MODE_RXONLY_PROTECTION_E,                     //=5 - protection (rx only)
} BCM_UW_PROTECTION_MODE_ENUM;
*/

#define      BCM_UW_PROTECTION_MODE_NONE_E                    (0)              //=0 - no protection , no force
#define      BCM_UW_PROTECTION_MODE_WORKING_E                 (1)              //=1 - working
#define      BCM_UW_PROTECTION_MODE_PROTECTION_E              (2)              //=2 - protection
#define      BCM_UW_PROTECTION_MODE_RXONLY_NONE_E             (3)              //=3 - no protection , no force (rx only)
#define      BCM_UW_PROTECTION_MODE_RXONLY_WORKING_E          (4)              //=4 - working (rx only)
#define      BCM_UW_PROTECTION_MODE_RXONLY_PROTECTION_E       (5)              //=5 - protection (rx only)
#define      BCM_UW_PROTECTION_MODE_ENUM			 unsigned char
/*
typedef enum {
    BCM_UW_PROTECTION_SYS_MODE_EXTERNAL_E,
    BCM_UW_PROTECTION_SYS_MODE_INTERNAL_E
} BCM_UW_PROTECTION_SYS_MODE_ENUM;
*/

#define     BCM_UW_PROTECTION_SYS_MODE_EXTERNAL_E		 (0)
#define     BCM_UW_PROTECTION_SYS_MODE_INTERNAL_E		 (1)
#define     BCM_UW_PROTECTION_SYS_MODE_ENUM			unsigned char

/*
typedef enum {
    BCM_UW_ACM_PROFILE_0_E,
    BCM_UW_ACM_PROFILE_1_E,
    BCM_UW_ACM_PROFILE_2_E,
    BCM_UW_ACM_PROFILE_3_E,
    BCM_UW_ACM_PROFILE_4_E,
    BCM_UW_ACM_PROFILE_5_E,
    BCM_UW_ACM_PROFILE_6_E,
    BCM_UW_ACM_PROFILE_7_E,
    BCM_UW_ACM_PROFILE_8_E,
    BCM_UW_ACM_PROFILE_9_E,
    BCM_UW_ACM_PROFILE_10_E,
    BCM_UW_ACM_PROFILE_11_E,
    BCM_UW_ACM_PROFILE_12_E,
    BCM_UW_ACM_PROFILE_13_E,
    BCM_UW_ACM_PROFILE_14_E,
    BCM_UW_ACM_PROFILE_15_E
} BCM_UW_ACM_PROFILE_ENUM;
*/

#define     BCM_UW_ACM_PROFILE_0_E		   (0)
#define     BCM_UW_ACM_PROFILE_1_E		   (1)
#define     BCM_UW_ACM_PROFILE_2_E		   (2)
#define     BCM_UW_ACM_PROFILE_3_E		   (3)
#define     BCM_UW_ACM_PROFILE_4_E		   (4)
#define     BCM_UW_ACM_PROFILE_5_E		   (5)
#define     BCM_UW_ACM_PROFILE_6_E		   (6)
#define     BCM_UW_ACM_PROFILE_7_E		   (7)
#define     BCM_UW_ACM_PROFILE_8_E		   (8)
#define     BCM_UW_ACM_PROFILE_9_E		   (9)
#define     BCM_UW_ACM_PROFILE_10_E		   (10)
#define     BCM_UW_ACM_PROFILE_11_E		   (11)
#define     BCM_UW_ACM_PROFILE_12_E		   (12)
#define     BCM_UW_ACM_PROFILE_13_E		   (13)
#define     BCM_UW_ACM_PROFILE_14_E		   (14)
#define     BCM_UW_ACM_PROFILE_15_E		   (15)
#define     BCM_UW_ACM_PROFILE_ENUM		   unsigned char



 /*
typedef enum {
    BCM_UW_ACM_DEGRADE_TABLE_E,
    BCM_UW_ACM_IMPROVE_TABLE_E,
} BCM_UW_ACM_TABLE_ENUM;
*/

#define     BCM_UW_ACM_DEGRADE_TABLE_E	  (0)
#define     BCM_UW_ACM_IMPROVE_TABLE_E	  (1)
#define     BCM_UW_ACM_TABLE_ENUM	   unsigned char

/*
typedef enum {
    BCM_UW_ACM_CRITERIA_NA_E,
    BCM_UW_ACM_CRITERIA_ALL_E,                                      //AND (mse,ber)
    BCM_UW_ACM_CRITERIA_ANY_E,                                      //OR (mse,ber)
    BCM_UW_ACM_CRITERIA_MSE_ONLY_E,
} BCM_UW_ACM_CRITERIA_ENUM;
*/

#define     BCM_UW_ACM_CRITERIA_NA_E			   (0)
#define     BCM_UW_ACM_CRITERIA_ALL_E              (1)                        //AND (mse,ber)
#define     BCM_UW_ACM_CRITERIA_ANY_E              (2)                        //OR (mse,ber)
#define     BCM_UW_ACM_CRITERIA_MSE_ONLY_E		   (3)
#define     BCM_UW_ACM_CRITERIA_ENUM			unsigned char


/*
typedef enum {
    BCM_UW_TESTBUS1_INPUT_E,
    BCM_UW_SLICER_INPUT_E,
    BCM_UW_API_INPUT_E,
} BCM_UW_IQ_SAMPLES_SEL_ENUM;
*/

#define   BCM_UW_TESTBUS1_INPUT_E   				(0)
#define   BCM_UW_SLICER_INPUT_E						(1)
#define   BCM_UW_API_INPUT_E						(2)
#define   BCM_UW_IQ_SAMPLES_SEL_ENUM			 unsigned char

/*
typedef enum {
    BCM_UW_GPIO_INT_DISABLE_ALL_E,
    BCM_UW_GPIO_INT_RISING_EDGE_E,
    BCM_UW_GPIO_INT_FALLING_EDGE_E,
    BCM_UW_GPIO_INT_LEVEL_HIGH_E,
    BCM_UW_GPIO_INT_LEVEL_LOW_E
} BCM_UW_GPIO_INT_ENUM;
*/

#define      BCM_UW_GPIO_INT_DISABLE_ALL_E			(0)
#define      BCM_UW_GPIO_INT_RISING_EDGE_E			(1)
#define      BCM_UW_GPIO_INT_FALLING_EDGE_E			(2)
#define      BCM_UW_GPIO_INT_LEVEL_HIGH_E			(3)
#define      BCM_UW_GPIO_INT_LEVEL_LOW_E			(4)
#define      BCM_UW_GPIO_INT_ENUM				 unsigned char

/*
typedef enum {
    BCM_UW_SPIA_M_CS0_E, //CS0
    BCM_UW_SPI_CS1_E,
    BCM_UW_SPI_CS2_E,
    BCM_UW_SPI_CS3_E,
    BCM_UW_SPI_CS4_E,
    BCM_UW_SPI_CS5_E,
    BCM_UW_SPI_CS6_E,
    BCM_UW_SPI_CS7_E,
    BCM_UW_SPI_CS8_E,
    BCM_UW_SPI_CS9_E,
    BCM_UW_SPI_CS10_E,
    BCM_UW_SPI_CS11_E,
    BCM_UW_SPI_CS12_E,
    BCM_UW_SPI_CS13_E,
    BCM_UW_SPI_CS14_E,
    BCM_UW_SPI_CS15_E,
    BCM_UW_SPIB_M_CS0_E //CS16
} BCM_UW_SPI_MASTER_CS_ENUM;
*/

#define    BCM_UW_SPIA_M_CS0_E					(0)	 //CS0
#define    BCM_UW_SPI_CS1_E						(1)
#define    BCM_UW_SPI_CS2_E						(2)
#define    BCM_UW_SPI_CS3_E						(3)
#define    BCM_UW_SPI_CS4_E						(4)
#define    BCM_UW_SPI_CS5_E						(5)
#define    BCM_UW_SPI_CS6_E						(6)
#define    BCM_UW_SPI_CS7_E						(7)
#define    BCM_UW_SPI_CS8_E						(8)
#define    BCM_UW_SPI_CS9_E						(9)
#define    BCM_UW_SPI_CS10_E					(10)
#define    BCM_UW_SPI_CS11_E					(11)
#define    BCM_UW_SPI_CS12_E					(12)
#define    BCM_UW_SPI_CS13_E					(13)
#define    BCM_UW_SPI_CS14_E					(14)
#define    BCM_UW_SPI_CS15_E					(15)
#define    BCM_UW_SPIB_M_CS0_E 					(16)//CS16
#define    BCM_UW_SPI_MASTER_CS_ENUM		  unsigned char
/*
typedef enum {
    BCM_UW_PHASE_0_POLARITY_0_E,
    BCM_UW_PHASE_0_POLARITY_1_E,
    BCM_UW_PHASE_1_POLARITY_0_E,
    BCM_UW_PHASE_1_POLARITY_1_E
} BCM_UW_SPI_PHASE_POLARITY_ENUM;
*/

#define   BCM_UW_PHASE_0_POLARITY_0_E			(0)
#define   BCM_UW_PHASE_0_POLARITY_1_E			(1)
#define   BCM_UW_PHASE_1_POLARITY_0_E			(2)
#define   BCM_UW_PHASE_1_POLARITY_1_E			(3)
#define   BCM_UW_SPI_PHASE_POLARITY_ENUM	   unsigned char

 /*
typedef enum {
    BCM_UW_SPI_FREQUENCY_100K_E,
    BCM_UW_SPI_FREQUENCY_500K_E,
    BCM_UW_SPI_FREQUENCY_1M_E,
    BCM_UW_SPI_FREQUENCY_2M_E,
    BCM_UW_SPI_FREQUENCY_5M_E,
    BCM_UW_SPI_FREQUENCY_8M_E,
    BCM_UW_SPI_FREQUENCY_10M_E
} BCM_UW_SPI_FREQUENCY_ENUM;
*/

#define     BCM_UW_SPI_FREQUENCY_100K_E	  (0)
#define     BCM_UW_SPI_FREQUENCY_500K_E	  (1)
#define     BCM_UW_SPI_FREQUENCY_1M_E	  (2)
#define     BCM_UW_SPI_FREQUENCY_2M_E	  (3)
#define     BCM_UW_SPI_FREQUENCY_5M_E	  (4)
#define     BCM_UW_SPI_FREQUENCY_8M_E	  (5)
#define     BCM_UW_SPI_FREQUENCY_10M_E	  (6)
#define     BCM_UW_SPI_FREQUENCY_ENUM	 unsigned char



/*
typedef enum {
    BCM_UW_I2C_FREQUENCY_100K_E,
    BCM_UW_I2C_FREQUENCY_400K_E
} BCM_UW_I2C_FREQUENCY_ENUM;
*/

#define   BCM_UW_I2C_FREQUENCY_100K_E   (0)
#define   BCM_UW_I2C_FREQUENCY_400K_E	(1)
#define   BCM_UW_I2C_FREQUENCY_ENUM	   unsigned char


/*
typedef enum {
    BCM_UW_ALARM_MDM_BIT_E,
    BCM_UW_ALARM_MDM_LOCKED_E,
    BCM_UW_ALARM_MDM_LOL_E,
    BCM_UW_ALARM_ACM_TX_SWITCH_E,
    BCM_UW_ALARM_ACM_RX_SWITCH_E,
    BCM_UW_ALARM_ACM_IMPRV_REQ_E,
    BCM_UW_ALARM_TXTX_CALIB_DONE_E,
    BCM_UW_ALARM_ENC_SNIP_E,
    BCM_UW_ALARM_TX_SNIP_E,
    BCM_UW_ALARM_IMB_MBX_RX_E,
    BCM_UW_ALARM_PROTC_PRRX_SWITCH_E,
    BCM_UW_ALARM_PPS_CALIB_DONE_E,
    BCM_UW_ALARM_ADPD_CALIB_DONE_E,
    BCM_UW_ALARM_ETH_BW_CHANGED_E,
    BCM_UW_ALARM_WBRX_SNAPSHOT_DONE_E,
    BCM_UW_ALARM_FIFO_ERROR_E,

    BCM_UW_ALARM_SC1_MDM_BIT_E,
    BCM_UW_ALARM_SC1_MDM_LOCKED_E,
    BCM_UW_ALARM_SC1_MDM_LOL_E,
    BCM_UW_ALARM_SC1_ACM_TX_SWITCH_E,
    BCM_UW_ALARM_SC1_ACM_RX_SWITCH_E,
    BCM_UW_ALARM_SC1_ACM_IMPRV_REQ_E,
    BCM_UW_ALARM_SC1_TXTX_CALIB_DONE_E,
    BCM_UW_ALARM_SC1_ENC_SNIP_E,
    BCM_UW_ALARM_SC1_TX_SNIP_E,
    BCM_UW_ALARM_SC1_IMB_MBX_RX_E,
    BCM_UW_ALARM_SC1_PROTC_PRRX_SWITCH_E,
    BCM_UW_ALARM_SC1_PPS_CALIB_DONE_E,
    BCM_UW_ALARM_SC1_ADPD_CALIB_DONE_E,
    BCM_UW_ALARM_SC1_ETH_BW_CHANGED_E,
    BCM_UW_ALARM_AVS_CHANGED_E,
    BCM_UW_ALARM_SC1_FIFO_ERROR_E
} BCM_UW_ALARM_BITS_ENUM;
*/

#define      BCM_UW_ALARM_MDM_BIT_E			     (0)
#define      BCM_UW_ALARM_MDM_LOCKED_E		     (1)
#define      BCM_UW_ALARM_MDM_LOL_E			     (2)
#define      BCM_UW_ALARM_ACM_TX_SWITCH_E	     (3)
#define      BCM_UW_ALARM_ACM_RX_SWITCH_E	     (4)
#define      BCM_UW_ALARM_ACM_IMPRV_REQ_E	     (5)
#define      BCM_UW_ALARM_TXTX_CALIB_DONE_E	     (6)
#define      BCM_UW_ALARM_ENC_SNIP_E		     (7)
#define      BCM_UW_ALARM_TX_SNIP_E			     (8)
#define      BCM_UW_ALARM_IMB_MBX_RX_E		     (9)
#define      BCM_UW_ALARM_PROTC_PRRX_SWITCH_E    (10)
#define      BCM_UW_ALARM_PPS_CALIB_DONE_E	     (11)
#define      BCM_UW_ALARM_ADPD_CALIB_DONE_E	     (12)
#define      BCM_UW_ALARM_ETH_BW_CHANGED_E	     (13)
#define      BCM_UW_ALARM_WBRX_SNAPSHOT_DONE_E   (14)
#define      BCM_UW_ALARM_FIFO_ERROR_E		   	 (15)

#define      BCM_UW_ALARM_SC1_MDM_BIT_E		      (16)
#define      BCM_UW_ALARM_SC1_MDM_LOCKED_E	      (17)
#define      BCM_UW_ALARM_SC1_MDM_LOL_E		      (18)
#define      BCM_UW_ALARM_SC1_ACM_TX_SWITCH_E     (19)
#define      BCM_UW_ALARM_SC1_ACM_RX_SWITCH_E     (20)
#define      BCM_UW_ALARM_SC1_ACM_IMPRV_REQ_E     (21)
#define      BCM_UW_ALARM_SC1_TXTX_CALIB_DONE_E	  (22)
#define      BCM_UW_ALARM_SC1_ENC_SNIP_E		  (23)
#define      BCM_UW_ALARM_SC1_TX_SNIP_E			  (24)
#define      BCM_UW_ALARM_SC1_IMB_MBX_RX_E		  (25)
#define      BCM_UW_ALARM_SC1_PROTC_PRRX_SWITCH_E (26)
#define      BCM_UW_ALARM_SC1_PPS_CALIB_DONE_E	  (27)
#define      BCM_UW_ALARM_SC1_ADPD_CALIB_DONE_E	  (28)
#define      BCM_UW_ALARM_SC1_ETH_BW_CHANGED_E	  (29)
#define      BCM_UW_ALARM_AVS_CHANGED_E			  (30)
#define      BCM_UW_ALARM_SC1_FIFO_ERROR_E		  (31)
#define      BCM_UW_ALARM_BITS_ENUM			   unsigned char


/*
typedef enum {
    BCM_UW_DSP_ALARM_DIF0_AF_E                      = 0,
    BCM_UW_DSP_ALARM_DIF1_AF_E                      = 1,
    BCM_UW_DSP_ALARM_DOF_AE_E                       = 2,
    BCM_UW_DSP_ALARM_MBX_RX_E                       = 3,
    BCM_UW_DSP_ALARM_GPO30_E                        = 4,
    BCM_UW_DSP_ALARM_GPO31_E                        = 5,
    BCM_UW_DSP_ALARM_ECC_E                          = 6,
    BCM_UW_DSP_ALARM_GVI_E                          = 7,
    BCM_UW_DSP_ALARM_UOP_E                          = 8,
    BCM_UW_DSP_ALARM_NUM_E
} BCM_UW_DSP_ALARM_BITS_ENUM;
*/

#define      BCM_UW_DSP_ALARM_DIF0_AF_E                      (0)
#define      BCM_UW_DSP_ALARM_DIF1_AF_E                      (1)
#define      BCM_UW_DSP_ALARM_DOF_AE_E                       (2)
#define      BCM_UW_DSP_ALARM_MBX_RX_E                       (3)
#define      BCM_UW_DSP_ALARM_GPO30_E                        (4)
#define      BCM_UW_DSP_ALARM_GPO31_E                        (5)
#define      BCM_UW_DSP_ALARM_ECC_E                          (6)
#define      BCM_UW_DSP_ALARM_GVI_E                          (7)
#define      BCM_UW_DSP_ALARM_UOP_E                          (8)
#define      BCM_UW_DSP_ALARM_NUM_E							 (9)
#define      BCM_UW_DSP_ALARM_BITS_ENUM					unsigned char


/*
typedef enum {
    BCM_UW_PROTECTION_RX_UNLOCK_E                   = 0,
    BCM_UW_PROTECTION_RX_LOCK_E                     = 1,
    BCM_UW_PROTECTION_RX_TR_W_E                     = 2,
    BCM_UW_PROTECTION_RX_TR_P_E                     = 3
} BCM_UW_PROTECTION_RX_STATE_ENUM;
*/

#define      BCM_UW_PROTECTION_RX_UNLOCK_E                    (0)
#define      BCM_UW_PROTECTION_RX_LOCK_E                      (1)
#define      BCM_UW_PROTECTION_RX_TR_W_E                      (2)
#define      BCM_UW_PROTECTION_RX_TR_P_E                      (3)
#define      BCM_UW_PROTECTION_RX_STATE_ENUM			unsigned char



/*
typedef enum {
    BCM_UW_IND_RX_TIMING_BIT_E                      = 0,            // timing lock/unlock
    BCM_UW_IND_PREAMBLE_STATE_BIT_E                 = 1,            // preamble state (2bits)
    BCM_UW_IND_LDPC_EN_BIT_E                        = 3,            // LDPC (1=enable, 0=RS)
    BCM_UW_IND_RS_UNLOCK_BIT_E                      = 4,            // RS unlock
    BCM_UW_IND_LDPC_UNLOCK_BIT_E                    = 5,            // LDPC unlock
    BCM_UW_IND_LDPC_UNCOR_BIT_E                     = 6,            // LDPC uncor
    BCM_UW_IND_RS_UNCOR_BIT_E                       = 7,            // RS uncor
} BCM_UW_INDICATIONS_ENUM;
*/

#define      BCM_UW_IND_RX_TIMING_BIT_E                      (0)            // timing lock/unlock
#define      BCM_UW_IND_PREAMBLE_STATE_BIT_E                 (1)            // preamble state (2bits)
#define      BCM_UW_IND_LDPC_EN_BIT_E                        (3)            // LDPC (1=enable, 0=RS)
#define      BCM_UW_IND_RS_UNLOCK_BIT_E                      (4)            // RS unlock
#define      BCM_UW_IND_LDPC_UNLOCK_BIT_E                    (5)            // LDPC unlock
#define      BCM_UW_IND_LDPC_UNCOR_BIT_E                     (6)            // LDPC uncor
#define      BCM_UW_IND_RS_UNCOR_BIT_E                       (7)            // RS uncor
#define      BCM_UW_INDICATIONS_ENUM				 unsigned char



/*
typedef enum {
    BCM_UW_DEVICE_RESET_ALL_E                       = 0,
    BCM_UW_DEVICE_RESET_CPU_E                       = 1,
} BCM_UW_DEVICE_RESET_TYPE_ENUM;
*/

#define     BCM_UW_DEVICE_RESET_ALL_E                       (0)
#define     BCM_UW_DEVICE_RESET_CPU_E                       (1)
#define 	BCM_UW_DEVICE_RESET_TYPE_ENUM			 unsigned char



/*
typedef enum {
    BCM_UW_MODULATION_QPSK_E                        = 0,
    BCM_UW_MODULATION_8_POINTS_E                    = 1,
    BCM_UW_MODULATION_16_POINTS_E                   = 2,
    BCM_UW_MODULATION_32_POINTS_E                   = 3,
    BCM_UW_MODULATION_64_QAM_E                      = 4,
    BCM_UW_MODULATION_128_QAM_E                     = 5,
    BCM_UW_MODULATION_256_QAM_E                     = 6,
    BCM_UW_MODULATION_512_QAM_E                     = 7,
    BCM_UW_MODULATION_1024_QAM_E                    = 8,
    BCM_UW_MODULATION_2048_QAM_E                    = 9,
    BCM_UW_MODULATION_4096_QAM_E                    = 10,
} BCM_UW_MODULATION_TYPE_ENUM;
*/

#define   BCM_UW_MODULATION_QPSK_E                         (0)
#define   BCM_UW_MODULATION_8_POINTS_E                     (1)
#define   BCM_UW_MODULATION_16_POINTS_E                    (2)
#define   BCM_UW_MODULATION_32_POINTS_E                    (3)
#define   BCM_UW_MODULATION_64_QAM_E                       (4)
#define   BCM_UW_MODULATION_128_QAM_E                      (5)
#define   BCM_UW_MODULATION_256_QAM_E                      (6)
#define   BCM_UW_MODULATION_512_QAM_E                      (7)
#define   BCM_UW_MODULATION_1024_QAM_E                     (8)
#define   BCM_UW_MODULATION_2048_QAM_E                     (9)
#define   BCM_UW_MODULATION_4096_QAM_E                     (10)
#define   BCM_UW_MODULATION_TYPE_ENUM;			  unsigned char


/*
typedef enum {
    BCM_UW_TESTBUS_NO_CHANGE_E,
    BCM_UW_TESTBUS_TX_MAPPER_E,
    BCM_UW_TESTBUS_GAIN_0_E,
    BCM_UW_TESTBUS_RRC_MASTER_E,
    BCM_UW_TESTBUS_RRC_SLAVE_1_E,
    BCM_UW_TESTBUS_RRC_SLAVE_2_E,
    BCM_UW_TESTBUS_RRC_SLAVE_3_E,
    BCM_UW_TESTBUS_SLICER_MASTER_E,
    BCM_UW_TESTBUS_SLICER_SLAVE_2_E,
    BCM_UW_TESTBUS_DEM_IN_MASTER_E,
    BCM_UW_TESTBUS_DEM_IN_SLAVE_1_E,
    BCM_UW_TESTBUS_DEM_IN_SLAVE_2_E,
    BCM_UW_TESTBUS_DEM_IN_SLAVE_3_E,
    BCM_UW_TESTBUS_MOD_OUT_E,
    BCM_UW_TESTBUS_AF_CONSTRUCTOR_E,
    BCM_UW_TESTBUS_FEC_IN_E,
    BCM_UW_TESTBUS_ENCRYPTION_E,
    BCM_UW_TESTBUS_PRRX_E,
} BCM_UW_TESTBUS_SEL_ENUM;
*/


#define    BCM_UW_TESTBUS_NO_CHANGE_E			(0)
#define    BCM_UW_TESTBUS_TX_MAPPER_E			(1)
#define    BCM_UW_TESTBUS_GAIN_0_E				(2)
#define    BCM_UW_TESTBUS_RRC_MASTER_E			(3)
#define    BCM_UW_TESTBUS_RRC_SLAVE_1_E			(4)
#define    BCM_UW_TESTBUS_RRC_SLAVE_2_E			(5)
#define    BCM_UW_TESTBUS_RRC_SLAVE_3_E			(6)
#define    BCM_UW_TESTBUS_SLICER_MASTER_E		(7)
#define    BCM_UW_TESTBUS_SLICER_SLAVE_2_E		(8)
#define    BCM_UW_TESTBUS_DEM_IN_MASTER_E		(9)
#define    BCM_UW_TESTBUS_DEM_IN_SLAVE_1_E		(10)
#define    BCM_UW_TESTBUS_DEM_IN_SLAVE_2_E		(11)
#define    BCM_UW_TESTBUS_DEM_IN_SLAVE_3_E		(12)
#define    BCM_UW_TESTBUS_MOD_OUT_E				(13)
#define    BCM_UW_TESTBUS_AF_CONSTRUCTOR_E		(14)
#define    BCM_UW_TESTBUS_FEC_IN_E				(15)
#define    BCM_UW_TESTBUS_ENCRYPTION_E			(16)
#define    BCM_UW_TESTBUS_PRRX_E				(17)
#define    BCM_UW_TESTBUS_SEL_ENUM			unsigned char


 /*
typedef enum {
    BCM_UW_INJECTION_DISABLE_E                      = 0,
    BCM_UW_INJECTION_ENCRYPTION_E                   = 1,
} BCM_UW_INJECTION_SEL_ENUM;
*/

#define     BCM_UW_INJECTION_DISABLE_E                     (0)
#define     BCM_UW_INJECTION_ENCRYPTION_E                  (1)
#define     BCM_UW_INJECTION_SEL_ENUM			  unsigned char


/*
typedef enum {
    BCM_UW_CALIB_DISABLED_E,
    BCM_UW_CALIB_IN_PROCESS_E,
    BCM_UW_CALIB_SUCCESS_CALIB_E,
    BCM_UW_CALIB_NO_CORRELATION_FAILURE_E,
    BCM_UW_CALIB_TIME_OUT_FAILURE_E,
    BCM_UW_CALIB_WAITING_TO_START_E,
} BCM_UW_CALIB_STATUS_ENUM;
*/

#define    BCM_UW_CALIB_DISABLED_E						(0)
#define    BCM_UW_CALIB_IN_PROCESS_E					(1)
#define    BCM_UW_CALIB_SUCCESS_CALIB_E					(2)
#define    BCM_UW_CALIB_NO_CORRELATION_FAILURE_E		(3)
#define    BCM_UW_CALIB_TIME_OUT_FAILURE_E				(4)
#define    BCM_UW_CALIB_WAITING_TO_START_E				(5)
#define    BCM_UW_CALIB_STATUS_ENUM				  unsigned char


/*
typedef enum {
    BCM_UW_HC_ENGINE_1_E                            = 0,            //header compression Engine number 1
    BCM_UW_HC_ENGINE_2_E                            = 1,            //header compression Engine number 2
} BCM_UW_HC_ENGINE_ENUM;
*/

#define  BCM_UW_HC_ENGINE_1_E                            (0)            //header compression Engine number 1
#define  BCM_UW_HC_ENGINE_2_E                            (1)            //header compression Engine number 2
#define  BCM_UW_HC_ENGINE_ENUM					  unsigned char
/*
typedef enum {
    BCM_UW_PLA_MODE_SINGLE_E,                                       //no PLA
    BCM_UW_PLA_MODE_MASTER_E,                                       //Master (SC0 only)
    BCM_UW_PLA_MODE_SLAVE_E,                                        //N/A 650
} BCM_UW_PLA_MODE_ENUM;
*/

#define     BCM_UW_PLA_MODE_SINGLE_E     (0)                                     //no PLA
#define     BCM_UW_PLA_MODE_MASTER_E     (1)                                  //Master (SC0 only)
#define     BCM_UW_PLA_MODE_SLAVE_E      (2)                                  //N/A 650
#define     BCM_UW_PLA_MODE_ENUM	   unsigned char
/*
typedef enum {
    BCM_UW_API_PEER_DEVICE_650_E,                                   //peer is 650
    BCM_UW_API_PEER_DEVICE_620_E,                                   //peer is 620
    BCM_UW_API_PEER_DEVICE_620_DE_E                                 //peer is 620_DE
} BCM_UW_API_PEER_DEVICE_ENUM;
*/

#define    BCM_UW_API_PEER_DEVICE_650_E    		(0)                               //peer is 650
#define    BCM_UW_API_PEER_DEVICE_620_E         (1)                          //peer is 620
#define    BCM_UW_API_PEER_DEVICE_620_DE_E      (2)                           //peer is 620_DE
#define    BCM_UW_API_PEER_DEVICE_ENUM		unsigned char


 /*
typedef enum {
    BCM_UW_PLA_FORCE_MASTER_E,
    BCM_UW_PLA_FORCE_SLAVE_E,
    BCM_UW_PLA_FORCE_NONE_E,
} BCM_UW_PLA_FORCE_ENUM;
 */

#define    BCM_UW_PLA_FORCE_MASTER_E		(0)
#define    BCM_UW_PLA_FORCE_SLAVE_E			(1)
#define    BCM_UW_PLA_FORCE_NONE_E			(2)
#define    BCM_UW_PLA_FORCE_ENUM		   unsigned char


/*
typedef enum {
    BCM_UW_PLA_STATE_BOTH_E,
    BCM_UW_PLA_STATE_MASTER_ONLY_E,
    BCM_UW_PLA_STATE_SLAVE_ONLY_E,
    BCM_UW_PLA_STATE_FORCE_MASTER_E,
    BCM_UW_PLA_STATE_FORCE_SLAVE_E,
} BCM_UW_PLA_STATE_ENUM;
*/

#define    BCM_UW_PLA_STATE_BOTH_E				  (0)
#define    BCM_UW_PLA_STATE_MASTER_ONLY_E		  (1)
#define    BCM_UW_PLA_STATE_SLAVE_ONLY_E		  (2)
#define    BCM_UW_PLA_STATE_FORCE_MASTER_E		  (3)
#define    BCM_UW_PLA_STATE_FORCE_SLAVE_E		  (4)
#define    BCM_UW_PLA_STATE_ENUM				unsigned char



/*
typedef enum {
    BCM_UW_DIG_XPD_MODE_CONSTRUCTIVE_E,
    BCM_UW_DIG_XPD_MODE_DESTRUCTIVE_E
} BCM_UW_DIG_XPD_MODE_ENUM;
*/

#define  BCM_UW_DIG_XPD_MODE_CONSTRUCTIVE_E	  (0)
#define  BCM_UW_DIG_XPD_MODE_DESTRUCTIVE_E	  (1)
#define  BCM_UW_DIG_XPD_MODE_ENUM			unsigned char


/*
typedef enum {
    BCM_UW_MODEM_LOCK_CRITERIA_BIT_E,
    BCM_UW_MODEM_LOCK_CRITERIA_CORRELLATOR_E,
} BCM_UW_MODEM_LOCK_CRITERIA_ENUM;
*/

#define   BCM_UW_MODEM_LOCK_CRITERIA_BIT_E				(0)
#define   BCM_UW_MODEM_LOCK_CRITERIA_CORRELLATOR_E		(1)
#define   BCM_UW_MODEM_LOCK_CRITERIA_ENUM			  unsigned char



 /*
typedef enum {
    BCM_UW_CHAIN_MAIN_E                   = 0,
    BCM_UW_CHAIN_XPIC_SLAVE_E             = 1,
    BCM_UW_CHAIN_MRC_DIVERSITY_E          = 2,
    BCM_UW_CHAIN_MRCX_DIVERSITY_SLAVE_E   = 3,
    BCM_UW_CHAIN_MIMO_SPATIAL_E           = 2,
    BCM_UW_CHAIN_MIMOX_SPATIAL_SLAVE_E    = 3,
    BCM_UW_CHAIN_MAX                      = 99,                     //invalid entry, used for status APIs signifying "no chain"
} BCM_UW_MODEM_CHAIN_ENUM;
*/

#define     BCM_UW_CHAIN_MAIN_E                   (0)
#define     BCM_UW_CHAIN_XPIC_SLAVE_E             (1)
#define     BCM_UW_CHAIN_MRC_DIVERSITY_E          (2)
#define     BCM_UW_CHAIN_MRCX_DIVERSITY_SLAVE_E   (3)
#define     BCM_UW_CHAIN_MIMO_SPATIAL_E           (2)
#define     BCM_UW_CHAIN_MIMOX_SPATIAL_SLAVE_E    (3)
#define     BCM_UW_CHAIN_MAX                      (99)                     //invalid entry, used for status APIs signifying "no chain"
#define     BCM_UW_MODEM_CHAIN_ENUM		   unsigned char



/*
typedef enum {
    BCM_UW_WB_RX_0_E                      = 0,
    BCM_UW_WB_RX_1_E                      = 1,
    BCM_UW_WB_RX_2_E                      = 2,
    BCM_UW_WB_RX_3_E                      = 3,
    BCM_UW_WB_RX_ADPD0_E                  = 4,
    BCM_UW_WB_RX_ADPD1_E                  = 5,
    BCM_UW_WB_RX_ENV0_E                   = 7,
    BCM_UW_WB_RX_ENV1_E                   = 8,
} BCM_UW_WB_RX_NAME_ENUM;
*/

#define     BCM_UW_WB_RX_0_E                      (0)
#define     BCM_UW_WB_RX_1_E                      (1)
#define     BCM_UW_WB_RX_2_E                      (2)
#define     BCM_UW_WB_RX_3_E                      (3)
#define     BCM_UW_WB_RX_ADPD0_E                  (4)
#define     BCM_UW_WB_RX_ADPD1_E                  (5)
#define     BCM_UW_WB_RX_ENV0_E                   (7)
#define     BCM_UW_WB_RX_ENV1_E                   (8)
#define     BCM_UW_WB_RX_NAME_ENUM			  unsigned char 



/*
typedef enum {
    BCM_UW_WB_TX_0_E,
    BCM_UW_WB_TX_1_E,
    BCM_UW_WB_TX_XC_0_E,
    BCM_UW_WB_TX_XC_1_E,
} BCM_UW_WB_TX_NAME_ENUM;
*/

#define   BCM_UW_WB_TX_0_E				(0)
#define   BCM_UW_WB_TX_1_E				(1)
#define   BCM_UW_WB_TX_XC_0_E			(2)
#define   BCM_UW_WB_TX_XC_1_E			(3)
#define   BCM_UW_WB_TX_NAME_ENUM	   unsigned char


/*
typedef enum {
    BCM_UW_FIRMWARE_INDEX_0_E,
    BCM_UW_FIRMWARE_INDEX_1_E
} BCM_UW_FIRMWARE_INDEX_ENUM;
*/

#define    BCM_UW_FIRMWARE_INDEX_0_E    (0)
#define    BCM_UW_FIRMWARE_INDEX_1_E	(1)
#define    BCM_UW_FIRMWARE_INDEX_ENUM	unsigned char



/*
typedef enum {
    BCM_UW_FRAG_SIZE_128_E,
    BCM_UW_FRAG_SIZE_256_E,
    BCM_UW_FRAG_SIZE_512_E,
    BCM_UW_FRAG_SIZE_1024_E,
    BCM_UW_FRAG_SIZE_INIFINITE_E,
} BCM_UW_FRAG_SIZE_ENUM;
*/

#define    BCM_UW_FRAG_SIZE_128_E		    (0)
#define    BCM_UW_FRAG_SIZE_256_E			(1)
#define    BCM_UW_FRAG_SIZE_512_E			(2)
#define    BCM_UW_FRAG_SIZE_1024_E			(3)
#define    BCM_UW_FRAG_SIZE_INIFINITE_E		(4)
#define    BCM_UW_FRAG_SIZE_ENUM		unsigned char



/*
typedef enum {
    BCM_UW_REPEATER_MODE_AAF_E,
    BCM_UW_REPEATER_MODE_RRC_E,
    BCM_UW_REPEATER_MODE_RXRX_E,
} BCM_UW_REPEATER_MODE_ENUM;
*/

#define  BCM_UW_REPEATER_MODE_AAF_E			(0)
#define  BCM_UW_REPEATER_MODE_RRC_E			(1)
#define  BCM_UW_REPEATER_MODE_RXRX_E		(2)
#define  BCM_UW_REPEATER_MODE_ENUM		 unsigned char


/*
typedef enum {
    BCM_UW_WB_TRANSMITTER_MODE_NORMAL_E,
    BCM_UW_WB_TRANSMITTER_MODE_ONETONE_E,
    BCM_UW_WB_TRANSMITTER_MODE_TWOTONE_E,
    BCM_UW_WB_TRANSMITTER_MODE_MUTE_E
} BCM_UW_WB_TRANSMITTER_MODE_ENUM;
*/

#define  BCM_UW_WB_TRANSMITTER_MODE_NORMAL_E		(0)
#define  BCM_UW_WB_TRANSMITTER_MODE_ONETONE_E		(1)
#define  BCM_UW_WB_TRANSMITTER_MODE_TWOTONE_E		(2)
#define  BCM_UW_WB_TRANSMITTER_MODE_MUTE_E			(3)
#define  BCM_UW_WB_TRANSMITTER_MODE_ENUM		 unsigned char


/*
typedef enum {
    BCM_UW_WB_AGC_LOCK_STATUS_IDLE_E,
    BCM_UW_WB_AGC_LOCK_STATUS_UNLOCKED_E,
    BCM_UW_WB_AGC_LOCK_STATUS_SEMI_LOCKED_E,
    BCM_UW_WB_AGC_LOCK_STATUS_LOCKED_E,
} BCM_UW_WB_AGC_LOCK_STATUS_ENUM;
*/

#define     BCM_UW_WB_AGC_LOCK_STATUS_IDLE_E			(0)
#define     BCM_UW_WB_AGC_LOCK_STATUS_UNLOCKED_E		(1)
#define     BCM_UW_WB_AGC_LOCK_STATUS_SEMI_LOCKED_E		(2)
#define     BCM_UW_WB_AGC_LOCK_STATUS_LOCKED_E			(3)
#define     BCM_UW_WB_AGC_LOCK_STATUS_ENUM			unsigned char


/*
typedef enum {
    BCM_UW_WB_RX_SOURCE_ADC_0_E,
    BCM_UW_WB_RX_SOURCE_ADC_0_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_0_Q_E,
    BCM_UW_WB_RX_SOURCE_ADC_1_E,
    BCM_UW_WB_RX_SOURCE_ADC_1_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_1_Q_E,
    BCM_UW_WB_RX_SOURCE_ADC_2_E,
    BCM_UW_WB_RX_SOURCE_ADC_2_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_2_Q_E,
    BCM_UW_WB_RX_SOURCE_ADC_3_E,
    BCM_UW_WB_RX_SOURCE_ADC_3_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_3_Q_E,
    BCM_UW_WB_RX_SOURCE_ADC_4_E,
    BCM_UW_WB_RX_SOURCE_ADC_4_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_4_Q_E,
    BCM_UW_WB_RX_SOURCE_ADC_5_E,
    BCM_UW_WB_RX_SOURCE_ADC_5_I_E,
    BCM_UW_WB_RX_SOURCE_ADC_5_Q_E,

    BCM_UW_WB_RX_SOURCE_ADC_MAX_E
} BCM_UW_WB_RX_SOURCE_NAME_ENUM;
*/

#define       BCM_UW_WB_RX_SOURCE_ADC_0_E		(0)
#define       BCM_UW_WB_RX_SOURCE_ADC_0_I_E		(1)
#define       BCM_UW_WB_RX_SOURCE_ADC_0_Q_E		(2)
#define       BCM_UW_WB_RX_SOURCE_ADC_1_E		(3)
#define       BCM_UW_WB_RX_SOURCE_ADC_1_I_E		(4)
#define       BCM_UW_WB_RX_SOURCE_ADC_1_Q_E		(5)
#define       BCM_UW_WB_RX_SOURCE_ADC_2_E		(6)
#define       BCM_UW_WB_RX_SOURCE_ADC_2_I_E		(7)
#define       BCM_UW_WB_RX_SOURCE_ADC_2_Q_E		(8)
#define       BCM_UW_WB_RX_SOURCE_ADC_3_E		(9)
#define       BCM_UW_WB_RX_SOURCE_ADC_3_I_E		(10)
#define       BCM_UW_WB_RX_SOURCE_ADC_3_Q_E		(11)
#define       BCM_UW_WB_RX_SOURCE_ADC_4_E		(12)
#define       BCM_UW_WB_RX_SOURCE_ADC_4_I_E		(13)
#define       BCM_UW_WB_RX_SOURCE_ADC_4_Q_E		(14)
#define       BCM_UW_WB_RX_SOURCE_ADC_5_E		(15)
#define       BCM_UW_WB_RX_SOURCE_ADC_5_I_E		(16)
#define       BCM_UW_WB_RX_SOURCE_ADC_5_Q_E		(17)

#define       BCM_UW_WB_RX_SOURCE_ADC_MAX_E		(18)
#define       BCM_UW_WB_RX_SOURCE_NAME_ENUM	   unsigned char

/*
typedef enum {
    BCM_UW_WB_TX_DEST_DAC_0_E,
    BCM_UW_WB_TX_DEST_DAC_0_I_E,
    BCM_UW_WB_TX_DEST_DAC_0_Q_E,
    BCM_UW_WB_TX_DEST_DAC_1_E,
    BCM_UW_WB_TX_DEST_DAC_1_I_E,
    BCM_UW_WB_TX_DEST_DAC_1_Q_E,

    BCM_UW_WB_TX_DEST_DAC_MAX_E
} BCM_UW_WB_TX_DEST_NAME_ENUM;
*/

#define    BCM_UW_WB_TX_DEST_DAC_0_E	   (0)
#define    BCM_UW_WB_TX_DEST_DAC_0_I_E	   (1)
#define    BCM_UW_WB_TX_DEST_DAC_0_Q_E	   (2)
#define    BCM_UW_WB_TX_DEST_DAC_1_E	   (3)
#define    BCM_UW_WB_TX_DEST_DAC_1_I_E	   (4)
#define    BCM_UW_WB_TX_DEST_DAC_1_Q_E	   (5)

#define    BCM_UW_WB_TX_DEST_DAC_MAX_E	   (6)
#define    BCM_UW_WB_TX_DEST_NAME_ENUM	  unsigned char

 /*
typedef enum {
    BCM_UW_WB_RX_AGC_MODE_IDLE_E,
    BCM_UW_WB_RX_AGC_MODE_ONE_TO_ONE_E,
    BCM_UW_WB_RX_AGC_MODE_ONE_TO_TWO_E,
    BCM_UW_WB_RX_AGC_MODE_TWO_TO_TWO_E,
    BCM_UW_WB_RX_AGC_MODE_TWO_TO_FOUR_E,
    BCM_UW_WB_RX_AGC_MODE_ADPD_E,
} BCM_UW_WB_RX_AGC_MODE_ENUM;
*/

#define     BCM_UW_WB_RX_AGC_MODE_IDLE_E			 (1)
#define     BCM_UW_WB_RX_AGC_MODE_ONE_TO_ONE_E		 (2)
#define     BCM_UW_WB_RX_AGC_MODE_ONE_TO_TWO_E		 (3)
#define     BCM_UW_WB_RX_AGC_MODE_TWO_TO_TWO_E		 (4)
#define     BCM_UW_WB_RX_AGC_MODE_TWO_TO_FOUR_E		 (5)
#define     BCM_UW_WB_RX_AGC_MODE_ADPD_E			 (6)
#define     BCM_UW_WB_RX_AGC_MODE_ENUM		 unsigned char



/*
typedef enum {
    BCM_UW_WB_TX_AGC_MODE_IDLE_E,
    BCM_UW_WB_TX_AGC_MODE_SINGLE_E,
    BCM_UW_WB_TX_AGC_MODE_DUAL_WB_E,
    BCM_UW_WB_TX_AGC_MODE_DUAL_DCC_E,
} BCM_UW_WB_TX_AGC_MODE_ENUM;
*/

#define  BCM_UW_WB_TX_AGC_MODE_IDLE_E	     (0)
#define  BCM_UW_WB_TX_AGC_MODE_SINGLE_E		 (1)
#define  BCM_UW_WB_TX_AGC_MODE_DUAL_WB_E	 (2)
#define  BCM_UW_WB_TX_AGC_MODE_DUAL_DCC_E	 (3)
#define  BCM_UW_WB_TX_AGC_MODE_ENUM		   unsigned char


/*
typedef enum {
    BCM_UW_ADPD_MODE_OFF_E,                                         // filter is reset, feedback HW may be switched off
    BCM_UW_ADPD_MODE_RESET_E,                                       // filter is reset, HW is on, and delay is calibrated
    BCM_UW_ADPD_MODE_TRACKING_E,                                    // filter is active and tracking
    BCM_UW_ADPD_MODE_FREEZE_E,                                      // filter is active, frozen
    BCM_UW_ADPD_MODE_AUTO_E,                                        // filter is auto tracking, frozen, reset
} BCM_UW_ADPD_MODE_ENUM;
*/
		 
#define    BCM_UW_ADPD_MODE_OFF_E          (0)                                  // filter is reset, feedback HW may be switched off
#define    BCM_UW_ADPD_MODE_RESET_E        (1)                               // filter is reset, HW is on, and delay is calibrated
#define    BCM_UW_ADPD_MODE_TRACKING_E     (2)                               // filter is active and tracking
#define    BCM_UW_ADPD_MODE_FREEZE_E       (3)                               // filter is active, frozen
#define    BCM_UW_ADPD_MODE_AUTO_E         (4)                               // filter is auto tracking, frozen, reset
#define    BCM_UW_ADPD_MODE_ENUM		  unsigned char


/*
typedef enum {
    BCM_UW_TXTX_MODE_RESET_E,
    BCM_UW_TXTX_MODE_TRACKING_E,
    BCM_UW_TXTX_MODE_FREEZE_E
} BCM_UW_TXTX_MODE_ENUM;
*/

#define   BCM_UW_TXTX_MODE_RESET_E	      (0)
#define   BCM_UW_TXTX_MODE_TRACKING_E	  (1)
#define   BCM_UW_TXTX_MODE_FREEZE_E		  (2)
#define   BCM_UW_TXTX_MODE_ENUM			unsigned char


/*
typedef enum {
    BCM_UW_ETH_PORT_1000MBPS_E,
    BCM_UW_ETH_PORT_2500MBPS_E,
    BCM_UW_ETH_PORT_100MBPS_E,
    BCM_UW_ETH_PORT_10MBPS_E
} BCM_UW_ETH_PORT_SPEED_ENUM;
*/

#define    BCM_UW_ETH_PORT_1000MBPS_E	  (0)
#define    BCM_UW_ETH_PORT_2500MBPS_E	  (1)
#define    BCM_UW_ETH_PORT_100MBPS_E	  (2)
#define    BCM_UW_ETH_PORT_10MBPS_E		  (3)
#define    BCM_UW_ETH_PORT_SPEED_ENUM	unsigned char


/*
typedef enum {
    BCM_UW_ETH_PORT_LINK_DOWN_E,
    BCM_UW_ETH_PORT_LINK_UP_E,
} BCM_UW_ETH_PORT_LINK_STATUS_ENUM;
*/

#define    BCM_UW_ETH_PORT_LINK_DOWN_E			(0)
#define    BCM_UW_ETH_PORT_LINK_UP_E			(1)
#define    BCM_UW_ETH_PORT_LINK_STATUS_ENUM	  unsigned char

/*
typedef enum {
    BCM_UW_ETH_PORT_PAUSE_ADV_NO_PAUSE_E,
    BCM_UW_ETH_PORT_PAUSE_ADV_ASYMMETRIC_PAUSE_E,
    BCM_UW_ETH_PORT_PAUSE_ADV_SYMMETRIC_PAUSE_E,
    BCM_UW_ETH_PORT_PAUSE_ADV_BOTH_PAUSE_E
} BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM;
*/

#define  	BCM_UW_ETH_PORT_PAUSE_ADV_NO_PAUSE_E			(0)
#define     BCM_UW_ETH_PORT_PAUSE_ADV_ASYMMETRIC_PAUSE_E	(1)
#define     BCM_UW_ETH_PORT_PAUSE_ADV_SYMMETRIC_PAUSE_E		(2)
#define     BCM_UW_ETH_PORT_PAUSE_ADV_BOTH_PAUSE_E			(3)
#define  	BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM 	unsigned char



#define    BCM_UW_ETH_PORT_DISABLE_E	     (0)
#define    BCM_UW_ETH_PORT_ENABLE_E			 (1)
#define    BCM_UW_ETH_PORT_DISABLE_TX_E		 (2)
#define    BCM_UW_ETH_PORT_DISABLE_RX_E		 (3)
#define	   BCM_UW_ETH_PORT_STATE_ENUM		unsigned char


/*
typedef enum {
    BCM_UW_ETH_PORT_IF_SGMII_E,
    BCM_UW_ETH_PORT_IF_1000X_E,
} BCM_UW_ETH_PORT_IF_ENUM;
*/

#define  BCM_UW_ETH_PORT_IF_SGMII_E	   (0)
#define  BCM_UW_ETH_PORT_IF_1000X_E	   (1)
#define  BCM_UW_ETH_PORT_IF_ENUM	  unsigned char 


/*
typedef enum {
    BCM_UW_ETH_PORT_KEEP_CRC_E,
    BCM_UW_ETH_PORT_STRIP_AND_APPEND_CRC_E,
    BCM_UW_ETH_PORT_STRIP_CRC_E,
    BCM_UW_ETH_PORT_APPEND_CRC_E
} BCM_UW_ETH_PORT_CRC_MODE_ENUM;
*/

#define     BCM_UW_ETH_PORT_KEEP_CRC_E				   (0)
#define     BCM_UW_ETH_PORT_STRIP_AND_APPEND_CRC_E	   (1)
#define     BCM_UW_ETH_PORT_STRIP_CRC_E				   (2)
#define     BCM_UW_ETH_PORT_APPEND_CRC_E			   (3)
#define     BCM_UW_ETH_PORT_CRC_MODE_ENUM	      unsigned char
 /*
typedef enum {
    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_DIS_TX_DIS_E     = 0,
    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_DIS_TX_EN_E      = 1,
    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_EN_TX_DIS_E      = 2,
    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_EN_TX_EN_E       = 3,
} BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_ENUM;
*/

#define    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_DIS_TX_DIS_E      (0)
#define    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_DIS_TX_EN_E       (1)
#define    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_EN_TX_DIS_E       (2)
#define    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_RX_EN_TX_EN_E        (3)
#define    BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_ENUM;			 unsigned char


/*
typedef enum {
    BCM_UW_ETH_PORT_LOOPBACK_NONE_E,                                // Normal mode
    BCM_UW_ETH_PORT_LOOPBACK_MAC_LOCAL_E,                           // MAC loopback mode, packets egressing the port will be looped back internal to the MAC
    BCM_UW_ETH_PORT_LOOPBACK_PCS_LOCAL_E,                           // PHY loopback mode, packets egressing the port will be looped back internally in PCS
    BCM_UW_ETH_PORT_LOOPBACK_PMD_LOCAL_E,                           // PHY loopback mode, packets ingressing the port will be looped back internally in PMD
    BCM_UW_ETH_PORT_LOOPBACK_PCS_LINE_E,                            // PHY loopback mode, packets ingressing the port will be looped back to the line over PCS
    BCM_UW_ETH_PORT_LOOPBACK_PMD_LINE_E                             // PHY loopback mode, packets ingressing the port will be looped back to the line over PMD
} BCM_UW_ETH_PORT_LOOPBACK_TYPE_ENUM;
*/

#define    BCM_UW_ETH_PORT_LOOPBACK_NONE_E          (0)                      // Normal mode
#define    BCM_UW_ETH_PORT_LOOPBACK_MAC_LOCAL_E     (1)                      // MAC loopback mode, packets egressing the port will be looped back internal to the MAC
#define    BCM_UW_ETH_PORT_LOOPBACK_PCS_LOCAL_E     (2)                      // PHY loopback mode, packets egressing the port will be looped back internally in PCS
#define    BCM_UW_ETH_PORT_LOOPBACK_PMD_LOCAL_E     (3)                      // PHY loopback mode, packets ingressing the port will be looped back internally in PMD
#define    BCM_UW_ETH_PORT_LOOPBACK_PCS_LINE_E      (4)                      // PHY loopback mode, packets ingressing the port will be looped back to the line over PCS
#define    BCM_UW_ETH_PORT_LOOPBACK_PMD_LINE_E      (5)                      // PHY loopback mode, packets ingressing the port will be looped back to the line over PMD
#define    BCM_UW_ETH_PORT_LOOPBACK_TYPE_ENUM	   unsigned char



/*
typedef enum {
    BCM_UW_ETH_PORT_AN_ABL_CL37_E,
    BCM_UW_ETH_PORT_AN_ABL_CL73_E,
    BCM_UW_ETH_PORT_AN_ABL_SGMII_E,
    BCM_UW_ETH_PORT_AN_ABL_CL37BAM_E,                               //2.5Gbps
    BCM_UW_ETH_PORT_AN_ABL_CL73BAM_E                                //2.5Gbps
} BCM_UW_ETH_PORT_AN_ABILITY_MODE_ENUM;
*/

#define    BCM_UW_ETH_PORT_AN_ABL_CL37_E   			(0)
#define    BCM_UW_ETH_PORT_AN_ABL_CL73_E			(1)
#define    BCM_UW_ETH_PORT_AN_ABL_SGMII_E			(2)
#define    BCM_UW_ETH_PORT_AN_ABL_CL37BAM_E         (3)                      //2.5Gbps
#define    BCM_UW_ETH_PORT_AN_ABL_CL73BAM_E         (4)                       //2.5Gbps
#define    BCM_UW_ETH_PORT_AN_ABILITY_MODE_ENUM	   unsigned char

 /*
typedef enum {
    BCM_UW_ETH_PORT_VLAN_TAG_NONE_E,
    BCM_UW_ETH_PORT_OUTER_VLAN_TAG_ENABLE_E,
    BCM_UW_ETH_PORT_INNER_VLAN_TAG_ENABLE_E,
    BCM_UW_ETH_PORT_OUTER_INNER_VLAN_TAG_ENABLE_E
} BCM_UW_ETH_PORT_VLAN_TAG_MODE;
*/

#define    BCM_UW_ETH_PORT_VLAN_TAG_NONE_E						 (0)
#define    BCM_UW_ETH_PORT_OUTER_VLAN_TAG_ENABLE_E				 (1)
#define    BCM_UW_ETH_PORT_INNER_VLAN_TAG_ENABLE_E				 (2)
#define    BCM_UW_ETH_PORT_OUTER_INNER_VLAN_TAG_ENABLE_E		 (3)
#define    BCM_UW_ETH_PORT_VLAN_TAG_MODE					 unsigned char


/*
typedef enum {
    BCM_UW_ETH_PORT_SET_PORT_INTERFACE_E                 = 0x1,
    BCM_UW_ETH_PORT_SET_PORT_SPEED_E                     = 0x2,
    BCM_UW_ETH_PORT_SET_PORT_ENABLE_E                    = 0x4,
    BCM_UW_ETH_PORT_SET_AUTO_NEGOTIATION_ENABLE_E        = 0x8,
    BCM_UW_ETH_PORT_SET_CRC_PROCESSING_MODE_E            = 0x10,
    BCM_UW_ETH_PORT_SET_FC_PAUSE_BEHAVIOR_E              = 0x20,
    BCM_UW_ETH_PORT_SET_FC_PAUSE_TIMER_E                 = 0x40,
    BCM_UW_ETH_PORT_SET_FC_PAUSE_REFRESH_RATE            = 0x80,
    BCM_UW_ETH_PORT_SET_TX_MAC_ADDRESS_E                 = 0x100,
    BCM_UW_ETH_PORT_SET_MAX_FRAME_SIZE_E                 = 0x200,
    BCM_UW_ETH_PORT_SET_MIN_FRAME_SIZE_E                 = 0x400,
    BCM_UW_ETH_PORT_SET_JUMBO_FRAME_SIZE_E               = 0x800,
    BCM_UW_ETH_PORT_SET_PAUSE_THRESHOLD_HIGH_E           = 0x1000,
    BCM_UW_ETH_PORT_SET_PAUSE_THRESHOLD_LOW_E            = 0x2000,
    BCM_UW_ETH_PORT_SET_TX_AVG_IPG                       = 0x4000,
    BCM_UW_ETH_PORT_SET_RX_MIN_IPG_ENABLE                = 0x8000,
    BCM_UW_ETH_PORT_SET_TX_PREAMBLE_LENGTH_E             = 0x10000,
    BCM_UW_ETH_PORT_SET_LOOPBACK_TYPE_E                  = 0x20000,
    BCM_UW_ETH_PORT_SET_CTRL_DISCARD_MASK_ENABLE_E       = 0x40000,
    BCM_UW_ETH_PORT_SET_PAUSE_ABILITY_MODE_E             = 0x80000,
    BCM_UW_ETH_PORT_SET_AUTONEG_ABILITY_MODE_E           = 0x100000,
    BCM_UW_ETH_PORT_SET_VLAN_TAG_ENABLE_MODE_E           = 0x200000,
    BCM_UW_ETH_PORT_SET_OUTER_VLAN_TPID_E                = 0x400000,
    BCM_UW_ETH_PORT_SET_INNER_VLAN_TPID_E                = 0x800000,
} BCM_UW_ETH_PORT_SET_SELECT_ENUM;
*/


#define    BCM_UW_ETH_PORT_SET_PORT_INTERFACE_E                  (0x1)
#define    BCM_UW_ETH_PORT_SET_PORT_SPEED_E                      (0x2)
#define    BCM_UW_ETH_PORT_SET_PORT_ENABLE_E                     (0x4)
#define    BCM_UW_ETH_PORT_SET_AUTO_NEGOTIATION_ENABLE_E         (0x8)
#define    BCM_UW_ETH_PORT_SET_CRC_PROCESSING_MODE_E             (0x10)
#define    BCM_UW_ETH_PORT_SET_FC_PAUSE_BEHAVIOR_E               (0x40)
#define    BCM_UW_ETH_PORT_SET_FC_PAUSE_REFRESH_RATE             (0x80)
#define    BCM_UW_ETH_PORT_SET_TX_MAC_ADDRESS_E                  (0x100)
#define    BCM_UW_ETH_PORT_SET_MAX_FRAME_SIZE_E                  (0x200)
#define    BCM_UW_ETH_PORT_SET_MIN_FRAME_SIZE_E                  (0x400)
#define    BCM_UW_ETH_PORT_SET_JUMBO_FRAME_SIZE_E                (0x800)
#define    BCM_UW_ETH_PORT_SET_PAUSE_THRESHOLD_HIGH_E            (0x1000)
#define    BCM_UW_ETH_PORT_SET_PAUSE_THRESHOLD_LOW_E             (0x2000)
#define    BCM_UW_ETH_PORT_SET_TX_AVG_IPG                        (0x4000)
#define    BCM_UW_ETH_PORT_SET_RX_MIN_IPG_ENABLE                 (0x8000)
#define    BCM_UW_ETH_PORT_SET_TX_PREAMBLE_LENGTH_E              (0x10000)
#define    BCM_UW_ETH_PORT_SET_LOOPBACK_TYPE_E                   (0x20000)
#define    BCM_UW_ETH_PORT_SET_CTRL_DISCARD_MASK_ENABLE_E        (0x40000)
#define    BCM_UW_ETH_PORT_SET_PAUSE_ABILITY_MODE_E              (0x80000)
#define    BCM_UW_ETH_PORT_SET_AUTONEG_ABILITY_MODE_E            (0x100000)
#define    BCM_UW_ETH_PORT_SET_VLAN_TAG_ENABLE_MODE_E            (0x200000)
#define    BCM_UW_ETH_PORT_SET_OUTER_VLAN_TPID_E                 (0x400000)
#define    BCM_UW_ETH_PORT_SET_INNER_VLAN_TPID_E                 (0x800000)
#define    BCM_UW_ETH_PORT_SET_SELECT_ENUM				   unsigned char

/*
typedef enum {
    BCM_UW_CHIP_TYPE_650_E,
    BCM_UW_CHIP_TYPE_820D_E,
    BCM_UW_CHIP_TYPE_MDDK_E,
    BCM_UW_CHIP_TYPE_651_E,
    BCM_UW_CHIP_TYPE_652_E,
} BCM_UW_CHIP_TYPE_ENUM;
*/

#define    BCM_UW_CHIP_TYPE_650_E			 (0)
#define    BCM_UW_CHIP_TYPE_820D_E			 (1)
#define    BCM_UW_CHIP_TYPE_MDDK_E			 (2)
#define    BCM_UW_CHIP_TYPE_651_E			 (3)
#define    BCM_UW_CHIP_TYPE_652_E			 (4)
#define    BCM_UW_CHIP_TYPE_ENUM		   unsigned char


/*
typedef enum {
    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_INPUT_E,
    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_AGC_OUTPUT_E,
    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_IQMC_OUTPUT_E,
    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_RXRX_OUTPUT_E,
    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_NCO_OUTPUT_E
} BCM_UW_BLOCK_CHANNEL_INDEX_SEL_ENUM;
*/

#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_INPUT_E		  (0)
#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_AGC_OUTPUT_E	  (1)
#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_IQMC_OUTPUT_E	  (2)
#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_RXRX_OUTPUT_E	  (3)
#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_NCO_OUTPUT_E	  (4)
#define    BCM_UW_BLOCK_CHANNEL_INDEX_SEL_ENUM		 unsigned char

/*
typedef enum {
    BCM_UW_BLOCK_HOST_TB_SEL_SW_E                       = 2,
    BCM_UW_BLOCK_HOST_TB_SEL_DISABLE_E                  = 3,
} BCM_UW_BLOCK_HOST_TB_SEL_ENUM;
*/

#define    BCM_UW_BLOCK_HOST_TB_SEL_SW_E                       (2)
#define    BCM_UW_BLOCK_HOST_TB_SEL_DISABLE_E                  (3)
#define    BCM_UW_BLOCK_HOST_TB_SEL_ENUM			unsigned char

/*
typedef enum {
    BCM_UW_RF_TX_DEV_0_E,
    BCM_UW_RF_TX_DEV_1_E,
    BCM_UW_RF_TX_DEV_MAX_E
} BCM_UW_RF_TX_DEV_IDX_ENUM;
*/

#define    BCM_UW_RF_TX_DEV_0_E					(0)
#define    BCM_UW_RF_TX_DEV_1_E					(1)
#define   BCM_UW_RF_TX_DEV_MAX_E				(2)
#define    BCM_UW_RF_TX_DEV_IDX_ENUM	   unsigned char

/*
typedef enum {
    BCM_UW_RF_RX_DEV_0_E,
    BCM_UW_RF_RX_DEV_1_E,
    BCM_UW_RF_RX_DEV_2_E,
    BCM_UW_RF_RX_DEV_3_E,
    BCM_UW_RF_RX_DEV_MAX_E
} BCM_UW_RF_RX_DEV_IDX_ENUM;
*/

#define    BCM_UW_RF_RX_DEV_0_E			 (0)
#define    BCM_UW_RF_RX_DEV_1_E			 (1)
#define    BCM_UW_RF_RX_DEV_2_E			 (2)
#define    BCM_UW_RF_RX_DEV_3_E			 (3)
#define    BCM_UW_RF_RX_DEV_MAX_E		 (4)
#define    BCM_UW_RF_RX_DEV_IDX_ENUM	unsigned char



/*
typedef enum {
    BCM_UW_RF_CS_224_E  = 224,
    BCM_UW_RF_CS_112_E  = 112,
    BCM_UW_RF_CS_56_E   = 56,
    BCM_UW_RF_CS_40_E   = 40,
    BCM_UW_RF_CS_28_E   = 28,
    BCM_UW_RF_CS_14_E   = 14,
    BCM_UW_RF_CS_7_E    = 7,
    BCM_UW_RF_CS_3_5_E  = 3,
    BCM_UW_RF_CS_MAX_E  = 255,
    BCM_UW_RF_CS_ALL_E  = BCM_UW_RF_CS_MAX_E
} BCM_UW_RF_CS_ENUM;
*/

#define    BCM_UW_RF_CS_224_E   (224)
#define    BCM_UW_RF_CS_112_E   (112)
#define    BCM_UW_RF_CS_56_E    (56)
#define    BCM_UW_RF_CS_40_E    (40)
#define    BCM_UW_RF_CS_28_E    (28)
#define    BCM_UW_RF_CS_14_E    (14)
#define    BCM_UW_RF_CS_7_E     (7)
#define    BCM_UW_RF_CS_3_5_E   (3)
#define    BCM_UW_RF_CS_MAX_E   (255)
#define    BCM_UW_RF_CS_ALL_E   (BCM_UW_RF_CS_MAX_E)
#define    BCM_UW_RF_CS_ENUM   unsigned char 

 /*
typedef enum {
    BCM_UW_RF_CHIP_TYPE_RX_E,
    BCM_UW_RF_CHIP_TYPE_RXSYNT_E,
    BCM_UW_RF_CHIP_TYPE_TX_E,
    BCM_UW_RF_CHIP_TYPE_TXSYNT_E,
    BCM_UW_RF_CHIP_TYPE_MAX_E
} BCM_UW_RF_CHIP_TYPE_ENUM;
*/

#define    BCM_UW_RF_CHIP_TYPE_RX_E				  (0)
#define    BCM_UW_RF_CHIP_TYPE_RXSYNT_E			  (1)
#define    BCM_UW_RF_CHIP_TYPE_TX_E				  (2)
#define    BCM_UW_RF_CHIP_TYPE_TXSYNT_E			  (3)
#define    BCM_UW_RF_CHIP_TYPE_MAX_E			  (4)
#define    BCM_UW_RF_CHIP_TYPE_ENUM			   unsigned char

/*
typedef enum {
    BCM_UW_DSP_0_E      = 0,
    BCM_UW_DSP_1_E      = 1,
    BCM_UW_DSP_2_E      = 2,
    BCM_UW_DSP_3_E      = 3,
    BCM_UW_DSP_4_E      = 4,
    BCM_UW_DSP_5_E      = 5,
    BCM_UW_NUM_OF_DSP_E
} BCM_UW_DSP_IDX_ENUM;
*/

#define    BCM_UW_DSP_0_E      		(0)
#define    BCM_UW_DSP_1_E      		(1)
#define    BCM_UW_DSP_2_E      		(2)
#define    BCM_UW_DSP_3_E      		(3)
#define    BCM_UW_DSP_4_E      		(4)
#define    BCM_UW_DSP_5_E      		(5)
#define    BCM_UW_NUM_OF_DSP_E		(6)
#define    BCM_UW_DSP_IDX_ENUM	 unsigned char

/*
typedef enum {
    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_8_BIT_E  = 0,
    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_16_BIT_E = 1,
    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_32_BIT_E = 2,
    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_64_BIT_E = 3
} BCM_UW_DSP_PACK_DPACK_WORD_SIZE_ENUM;
*/

#define    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_8_BIT_E    (0)
#define    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_16_BIT_E   (1)
#define    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_32_BIT_E   (2)
#define    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_64_BIT_E   (3)
#define    BCM_UW_DSP_PACK_DPACK_WORD_SIZE_ENUM	  unsigned char

/*
typedef enum {
    BCM_UW_DSP_DEPACKER_MODE_DISABLED_E      = 0,
    BCM_UW_DSP_DEPACKER_MODE_DATA_ONLY_E     = 1,
    BCM_UW_DSP_DEPACKER_MODE_CTRL_AND_DATA_E = 2
} BCM_UW_DSP_DEPACKER_MODE_ENUM;
*/

#define    BCM_UW_DSP_DEPACKER_MODE_DISABLED_E        (0)
#define    BCM_UW_DSP_DEPACKER_MODE_DATA_ONLY_E       (1)
#define    BCM_UW_DSP_DEPACKER_MODE_CTRL_AND_DATA_E   (2)
#define    BCM_UW_DSP_DEPACKER_MODE_ENUM         unsigned char 



/*
typedef enum {
    BCM_UW_DSP_DEPACKER_STROBE_SOURCE_PACKER0_E = 0,
    BCM_UW_DSP_DEPACKER_STROBE_SOURCE_PACKER1_E = 1,
} BCM_UW_DSP_DEPACKER_STROBE_SOURCE_ENUM;
*/

#define  BCM_UW_DSP_DEPACKER_STROBE_SOURCE_PACKER0_E   (0)
#define  BCM_UW_DSP_DEPACKER_STROBE_SOURCE_PACKER1_E   (1)
#define  BCM_UW_DSP_DEPACKER_STROBE_SOURCE_ENUM;  unsigned char
/*
typedef enum {
    BCM_UW_DSP_DIF_MODE_DISABLED_E     = 0,
    BCM_UW_DSP_DIF_MODE_FIFO_E         = 1,
    BCM_UW_DSP_DIF_MODE_DMEM_E         = 2,
    BCM_UW_DSP_DIF_MODE_FREE_RUNNING_E = 3
} BCM_UW_DSP_DIF_MODE_ENUM;
*/

#define    BCM_UW_DSP_DIF_MODE_DISABLED_E       (0)
#define    BCM_UW_DSP_DIF_MODE_FIFO_E           (1)
#define    BCM_UW_DSP_DIF_MODE_DMEM_E           (2)
#define    BCM_UW_DSP_DIF_MODE_FREE_RUNNING_E   (3)
#define    BCM_UW_DSP_DIF_MODE_ENUM		  unsigned char

/*
typedef enum {
    BCM_UW_DSP_DIF1_INPUT_SEL_PACKER1_E = 0,
    BCM_UW_DSP_DIF1_INPUT_SEL_MCI_E     = 1
} BCM_UW_DSP_DIF1_INPUT_SEL_ENUM;
*/

#define  BCM_UW_DSP_DIF1_INPUT_SEL_PACKER1_E  (0)
#define  BCM_UW_DSP_DIF1_INPUT_SEL_MCI_E      (1)
#define  BCM_UW_DSP_DIF1_INPUT_SEL_ENUM	unsigned char

/*
typedef enum {
    BCM_UW_DSP_DOF_MODE_DISABLED_E     = 0,
    BCM_UW_DSP_DOF_MODE_FIFO_E         = 1,
    BCM_UW_DSP_DOF_MODE_FREE_RUNNING_E = 2
} BCM_UW_DSP_DOF_MODE_ENUM;
*/

#define    BCM_UW_DSP_DOF_MODE_DISABLED_E       (0)
#define    BCM_UW_DSP_DOF_MODE_FIFO_E           (1)
#define    BCM_UW_DSP_DOF_MODE_FREE_RUNNING_E   (2)
#define    BCM_UW_DSP_DOF_MODE_ENUM		unsigned char

/*
typedef enum {
    BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_PACKER0_E = 0,
    BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_PACKER1_E = 1,
} BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_ENUM;
*/

#define     BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_PACKER0_E   (0)
#define     BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_PACKER1_E   (1)
#define     BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_ENUM		unsigned char


/*
typedef enum {
    BCM_UW_DSP_CIF_MODE_DISABLED_E              = 0,
    BCM_UW_DSP_CIF_MODE_DSP_PATH_ENABLED_E      = 1,
    BCM_UW_DSP_CIF_MODE_DEPACKER_PATH_ENABLED_E = 2,
    BCM_UW_DSP_CIF_MODE_BOTH_PATHS_ENABLED_E    = 3                 // DSP and De-Packer paths enabled
} BCM_UW_DSP_CIF_MODE_ENUM;
*/

#define    BCM_UW_DSP_CIF_MODE_DISABLED_E                (0)
#define    BCM_UW_DSP_CIF_MODE_DSP_PATH_ENABLED_E        (1)
#define    BCM_UW_DSP_CIF_MODE_DEPACKER_PATH_ENABLED_E   (2)
#define    BCM_UW_DSP_CIF_MODE_BOTH_PATHS_ENABLED_E      (3)                 // DSP and De-Packer paths enabled
#define    BCM_UW_DSP_CIF_MODE_ENUM					  unsigned char



 /*
typedef enum {
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DISABLED_E    = 0,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_1_E = 1,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_2_E = 2,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_3_E = 3,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_4_E = 4,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_6_E = 5,
    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_8_E = 6,
} BCM_UW_DSP_BLOCK_CLOCK_CONFIG_ENUM;
*/

#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DISABLED_E      (0)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_1_E   (1)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_2_E   (2)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_3_E   (3)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_4_E   (4)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_6_E   (5)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_DIVIDE_BY_8_E   (6)
#define    BCM_UW_DSP_BLOCK_CLOCK_CONFIG_ENUM	  unsigned char

/*
typedef enum {
    BCM_UW_DSP_MEMORY_TYPE_DMEM_0_E        = 0,
    BCM_UW_DSP_MEMORY_TYPE_DMEM_1_E        = 1,
    BCM_UW_DSP_MEMORY_TYPE_DMEM_2_E        = 2,
    BCM_UW_DSP_MEMORY_TYPE_DMEM_3_E        = 3,
    BCM_UW_DSP_MEMORY_TYPE_DMEM_4_E        = 4,
    BCM_UW_DSP_MEMORY_TYPE_DMEM_5_E        = 5,
    BCM_UW_DSP_MEMORY_TYPE_SHARED_SRAM_0_E = 6,
    BCM_UW_DSP_MEMORY_TYPE_SHARED_SRAM_1_E = 7
} BCM_UW_DSP_MEMORY_TYPE_ENUM;
*/

#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_0_E          (0)
#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_1_E          (1)
#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_2_E          (2)
#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_3_E          (3)
#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_4_E          (4)
#define    BCM_UW_DSP_MEMORY_TYPE_DMEM_5_E          (5)
#define    BCM_UW_DSP_MEMORY_TYPE_SHARED_SRAM_0_E   (6)
#define    BCM_UW_DSP_MEMORY_TYPE_SHARED_SRAM_1_E   (7)
#define    BCM_UW_DSP_MEMORY_TYPE_ENUM      unsigned char


 /*
typedef enum {
    BCM_UW_ETH_CLK_SRC_SGMII_0_E  = 0,
    BCM_UW_ETH_CLK_SRC_SGMII_1_E  = 1,
    BCM_UW_ETH_CLK_SRC_SGMII_2_E  = 2,
    BCM_UW_ETH_CLK_SRC_SGMII_3_E  = 3,
    BCM_UW_ETH_CLK_SRC_SGMII_4_E  = 4,
    BCM_UW_ETH_CLK_SRC_SGMII_5_E  = 5,
    BCM_UW_ETH_CLK_SRC_SGMII_6_E  = 6,
    BCM_UW_ETH_CLK_SRC_SGMII_7_E  = 7,
    BCM_UW_ETH_CLK_SRC_SYNCE_IN_E = 15
} BCM_UW_ETH_PORT_CLK_SRC_ENUM;
*/

#define      BCM_UW_ETH_CLK_SRC_SGMII_0_E  		(0)
#define      BCM_UW_ETH_CLK_SRC_SGMII_1_E   	(1)
#define      BCM_UW_ETH_CLK_SRC_SGMII_2_E   	(2)
#define      BCM_UW_ETH_CLK_SRC_SGMII_3_E   	(3)
#define      BCM_UW_ETH_CLK_SRC_SGMII_4_E   	(4)
#define      BCM_UW_ETH_CLK_SRC_SGMII_5_E   	(5)
#define      BCM_UW_ETH_CLK_SRC_SGMII_6_E   	(6)
#define      BCM_UW_ETH_CLK_SRC_SGMII_7_E   	(7)
#define      BCM_UW_ETH_PORT_CLK_SRC_ENUM   unsigned char

/*
typedef enum {
    BCM_UW_8KHZ_MODE_OFF_E,
    BCM_UW_8KHZ_MODE_8KHZ_DDS_E,
    BCM_UW_8KHZ_MODE_4KHZ_DDS_E,
    BCM_UW_8KHZ_MODE_2KHZ_DDS_E,
} BCM_UW_8KHZ_MODE_ENUM;
*/

#define    BCM_UW_8KHZ_MODE_OFF_E		   (0)
#define    BCM_UW_8KHZ_MODE_8KHZ_DDS_E	   (1)
#define    BCM_UW_8KHZ_MODE_4KHZ_DDS_E	   (2)
#define    BCM_UW_8KHZ_MODE_2KHZ_DDS_E	   (3)
#define    BCM_UW_8KHZ_MODE_ENUM		unsigned char

/*
typedef enum {
    BCM_UW_PPS_RTC_CALIB_MODE_COARSE_AND_FINE_E,
    BCM_UW_PPS_RTC_CALIB_MODE_FINE_E,
    BCM_UW_PPS_RTC_CALIB_MODE_AUTO_E,
    BCM_UW_PPS_RTC_CALIB_MODE_AUTO_OFF_E,
} BCM_UW_PPS_RTC_CALIB_MODE_ENUM;
*/

#define     BCM_UW_PPS_RTC_CALIB_MODE_COARSE_AND_FINE_E		(0)
#define     BCM_UW_PPS_RTC_CALIB_MODE_FINE_E				(1)
#define     BCM_UW_PPS_RTC_CALIB_MODE_AUTO_E				(2)
#define     BCM_UW_PPS_RTC_CALIB_MODE_AUTO_OFF_E			(3)
#define     BCM_UW_PPS_RTC_CALIB_MODE_ENUM			  unsigned char

/*
typedef enum {
    BCM_UW_PPS_SOURCE_INTERNAL_E,
    BCM_UW_PPS_SOURCE_EXTERNAL_E,
    BCM_UW_PPS_SOURCE_PEER_SC_E,
} BCM_UW_PPS_SOURCE_ENUM;
*/

#define    BCM_UW_PPS_SOURCE_INTERNAL_E	  (0)
#define    BCM_UW_PPS_SOURCE_EXTERNAL_E	  (1)
#define    BCM_UW_PPS_SOURCE_PEER_SC_E	  (2)
#define    BCM_UW_PPS_SOURCE_ENUM	   unsigned char

/*
typedef enum {
    BCM_UW_PPS_OUTPUT_MODE_OFF_E,
    BCM_UW_PPS_OUTPUT_MODE_ON_E,
    BCM_UW_PPS_OUTPUT_MODE_AUTO_E,
} BCM_UW_PPS_OUTPUT_MODE_ENUM;
*/

#define    BCM_UW_PPS_OUTPUT_MODE_OFF_E		(0)
#define    BCM_UW_PPS_OUTPUT_MODE_ON_E		(1)
#define    BCM_UW_PPS_OUTPUT_MODE_AUTO_E	(2)
#define    BCM_UW_PPS_OUTPUT_MODE_ENUM	 unsigned char

/*
typedef enum {
    BCM_UW_PPS_CALIB_STATUS_NOT_CALIBRATED_E,
    BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_COARSE_E,
    BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_FINE_E,
    BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_AUTO_FINE_E,
    BCM_UW_PPS_CALIB_STATUS_SUCCESS_E,
    BCM_UW_PPS_CALIB_STATUS_FAILED_E,
} BCM_UW_PPS_CALIB_STATUS_ENUM;
*/

#define     BCM_UW_PPS_CALIB_STATUS_NOT_CALIBRATED_E			 (0)
#define     BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_COARSE_E			 (1)
#define     BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_FINE_E			 (2)
#define     BCM_UW_PPS_CALIB_STATUS_IN_PROCESS_AUTO_FINE_E		 (3)
#define     BCM_UW_PPS_CALIB_STATUS_SUCCESS_E					 (4)
#define     BCM_UW_PPS_CALIB_STATUS_FAILED_E					 (5)
#define     BCM_UW_PPS_CALIB_STATUS_ENUM					unsigned char



/*
typedef enum {
    BCM_UW_PPS_CALIB_FAIL_REASON_NOT_RELEVANT_E,
    BCM_UW_PPS_CALIB_FAIL_REASON_SLAVE_LOL_E,
    BCM_UW_PPS_CALIB_FAIL_NO_RESPONSE_FROM_MASTER_E,
    BCM_UW_PPS_CALIB_FAIL_SLAVE_ACM_SWITCH_E,
    BCM_UW_PPS_CALIB_FAIL_COARSE_NEEDED_E,
    BCM_UW_PPS_CALIB_FAIL_GENERAL_FAIL_E,
    BCM_UW_PPS_CALIB_FAIL_OTHER_MSG_RECEIVED_E,
} BCM_UW_PPS_CALIB_FAIL_REASON_ENUM;
*/

#define    BCM_UW_PPS_CALIB_FAIL_REASON_NOT_RELEVANT_E			(0)
#define    BCM_UW_PPS_CALIB_FAIL_REASON_SLAVE_LOL_E				(1)
#define    BCM_UW_PPS_CALIB_FAIL_NO_RESPONSE_FROM_MASTER_E		(2)
#define    BCM_UW_PPS_CALIB_FAIL_SLAVE_ACM_SWITCH_E				(3)
#define    BCM_UW_PPS_CALIB_FAIL_COARSE_NEEDED_E				(4)
#define    BCM_UW_PPS_CALIB_FAIL_GENERAL_FAIL_E					(5)
#define    BCM_UW_PPS_CALIB_FAIL_OTHER_MSG_RECEIVED_E			(6)
#define    BCM_UW_PPS_CALIB_FAIL_REASON_ENUM			   unsigned char


/*
typedef enum {
    BCM_UW_WB_RXAGC_ANALOG_GAIN_0_E,
    BCM_UW_WB_RXAGC_ANALOG_GAIN_1_E,
    BCM_UW_WB_RXAGC_ANALOG_GAIN_2_E,
    BCM_UW_WB_RXAGC_ANALOG_GAIN_3_E,
} BCM_UW_WB_RXAGC_ANALOG_GAIN_ENUM;
*/

#define    BCM_UW_WB_RXAGC_ANALOG_GAIN_0_E		 (0)
#define    BCM_UW_WB_RXAGC_ANALOG_GAIN_1_E		 (1)
#define    BCM_UW_WB_RXAGC_ANALOG_GAIN_2_E		 (2)
#define    BCM_UW_WB_RXAGC_ANALOG_GAIN_3_E		 (3)
#define    BCM_UW_WB_RXAGC_ANALOG_GAIN_ENUM		 unsigned char


/*
typedef enum {
    BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_STEP_E,
    BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_RAMP_E,
} BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_ENUM;
*/

#define    BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_STEP_E	 (0)
#define    BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_RAMP_E	 (1)
#define    BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_ENUM   unsigned char



//----------------------------------------------------
// STRUCTS - use ONLY "PACKED" structs
//----------------------------------------------------

#ifdef WIN32
    #pragma pack( push, com_structs, 1)
#endif

#pragma Push_align_members(1)
typedef __PACK_PREFIX__ struct
{
    BYTE                majorVersion;
    BYTE                minorVersion;
    UINT16              buildVersion;
    BYTE                cpuType;                                    // N/A 650 (0 is same as deprecated MC_E)
    BYTE                chipVersion;                                // e.g 0xa1, 0xb0
    BYTE                chipType;                                   // see BCM_UW_CHIP_TYPE_ENUM
} __PACK__ BCM_UW_MODEM_VERSION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                majorVersion;
    BYTE                minorVersion;
    UINT16              buildVersion;
} __PACK__ BCM_UW_FIRMWARE_VERSION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                info[32];
} __PACK__ BCM_UW_HOST_INFO_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT8               bits0to7;
    UINT8               bits8to15;
    UINT8               bits16to23;
    UINT8               bits24to31;
    UINT8               bits32to39;
} __PACK__ BCM_UW_GPIO_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32               alarms;                                    // see BCM_UW_ALARM_BITS_ENUM
    BCM_UW_GPIO_STRUCT   mcGpios;                                   //
    BCM_UW_GPIO_STRUCT   gpGpios;                                   // N/A 650
    UINT32               sc0EthBw;                                  // not a mask, but provides the information related to BCM_UW_ALARM_ETH_BW_E bit
    UINT32               sc1EthBw;                                  // not a mask, but provides the information related to BCM_UW_ALARM_SC1_ETH_BW_E bit
    UINT16               dspAlarms[BCM_UW_NUM_OF_DSP_E];            // see BCM_UW_DSP_ALARM_BITS_ENUM
} __PACK__ BCM_UW_ALARMS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                acquireStatus;                              // see BCM_UW_ACQUIRE_STATUS_ENUM
    BYTE                lastAcquireError;                           // see BCM_UW_ACQUIRE_LAST_ERR_ENUM
    INT16               absoluteMseTenths;                          // in 0.1 dB steps
    INT16               normalizedMseTenths;                        // in 0.1 dB steps
    INT16               radialMseTenths;                            // in 0.1 dB steps
    INT16               internalAgc;                                // in dB, normal range [-5 to 40]
    UINT16              externalAgcRegister;                        // directly reflects register
    INT32               carrierOffset;                              // in Hz, normal range [-1e6 to 1e6]
    UINT32              rxSymbolRate;                               // in Baud, up to 112e6
    UINT32              txSymbolRate;                               // in Baud, up to 112e6
    UINT32              ldpcDecoderStress;                          // fraction in range [0,1]
    BYTE                txAcmProfile;                               // see BCM_UW_ACM_PROFILE_ENUM
    BYTE                rxAcmProfile;                               // see BCM_UW_ACM_PROFILE_ENUM
    BOOLEAN             acmEngineRxSensorsEnabled;                  // ACM engine Rx enable\disable
    BOOLEAN             acmEngineTxSwitchEnabled;                   // ACM engine Tx enable\disable
    BYTE                debugIndications;                           // see BCM_UW_INDICATIONS_ENUM
    UINT32              resPhNoiseVal;                              // reg value
    INT16               aafGain;                                    // N/A 650
    INT16               timingSnr;                                  // in 0.1 dB steps, range [0-100]
    BYTE                networkStatus;                              // Network status, [0]Not Locked [1]Locked [2]N/R = PRBS mode
    INT32               txCarrierOffset;                            // in Hz
} __PACK__ BCM_UW_MODEM_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT32               xpdTenths;                                  // estimated in tenths of dB
    INT32               slaveCarrierOffset;                         // in Hz, range[-1e6 to 1e6]
    INT16               slaveInternalAgc;                           // in dB, normal range [-5 to 40]   // N/A 650
    UINT16              slaveExternalAgcRegister;                   // directly reflects register       // N/A 650
    BOOLEAN             slaveSweepInProgress;                       // Slave Sweep status
    INT16               aafGainSlave;                               // in 0.1 dB steps                  // N/A 650
    BYTE                ecCalibStatus;                              // see BCM_UW_CALIB_STATUS_ENUM
} __PACK__ BCM_UW_MODEM_XPIC_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mrcMasterChain;                             // BCM_UW_MODEM_CHAIN_ENUM
    INT32               mrcGainDiffTenths;                          // estimated in tenths of dB [-99, +99]
    INT32               xpdTenths;                                  // estimated in tenths of dB
    INT32               diversityXpdTenths;                         // estimated in tenths of dB
    BOOLEAN             slaveSweepInProgress;                       // Slave sweep status
    BOOLEAN             diversitySlaveSweepInProgress;              // Diversiry slave sweep status
    BOOLEAN             diversityMasterSweepInProgress;             // Diversiry Master sweep status                                                                    
    INT32               diversityCarrierOffset;                     // in Hz, range[-1e6 to 1e6]
    INT32               slaveCarrierOffset;                         // in Hz, range[-1e6 to 1e6]
    INT32               diversitySlaveCarrierOffset;                // in Hz, range[-1e6 to 1e6]

    INT16               preCombinerMainAbsoluteMseTenths;           // in 0.1 dB steps
    INT16               preCombinerMainNormalizedMseTenths;         // in 0.1 dB steps
    INT16               preCombinerMainRadialMseTenths;             // in 0.1 dB steps
    INT16               preCombinerDiversityAbsoluteMseTenths;      // in 0.1 dB steps
    INT16               preCombinerDiversityNormalizedMseTenths;    // in 0.1 dB steps
    INT16               preCombinerDiversityRadialMseTenths;        // in 0.1 dB steps

    INT32               carrierOffset;                              // in Hz, normal range [-1e6 to 1e6]

    // combiner taps
    UINT32              combinerTapsMain[64];                       // real0, imag0, real1, imag1, �, real31, imag31. Relevant only in MRCX combiner mode
    UINT32              combinerTapsDiversity[64];                  // real0, imag0, real1, imag1, �, real31, imag31. Relevant only in MRCX combiner mode
} __PACK__ BCM_UW_MODEM_MRC_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT32               mimoGainDiffTenths;                         // estimated in tenths of dB [-99, +99]
    UINT32              eta;                                        // estimated precision TBD [0, +1]
    BOOLEAN             slaveSweepInProgress;                       // Slave Sweep status
    BOOLEAN             spatialSlaveSweepInProgress;                // Spatial slave sweep status
    INT32               xpdTenths;                                  // estimated in tenths of dB
    INT32               spatialXpdTenths;                           // estimated in tenths of dB
    INT32               spatialCarrierOffset;                       // in Hz, range[-1e6 to 1e6]
    INT32               slaveCarrierOffset;                         // in Hz, range[-1e6 to 1e6]
    INT32               spatialSlaveCarrierOffset;                  // in Hz, range[-1e6 to 1e6]
} __PACK__ BCM_UW_MODEM_MIMO_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             timingAdjust;
} __PACK__ BCM_UW_MODEM_MIMO_CONFIGURATION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              regVal[17];
    UINT32              wordCnt;
} __PACK__ BCM_UW_MODEM_RS_HIST_GET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              acmRxProfilesHistory;
    UINT16              acmTxProfilesHistory;
} __PACK__ BCM_UW_ACM_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              lolTimeMsec;                                // cumulative, clear on read
    UINT32              numLolEvents;                               // cumulative, clear on read
    UINT32              numAcquireTrials;                           // cumulative, clear on read
    UINT32              lastLockTimeSymbols;                        // in Usec
    UINT32              lastLockTimeBits;                           // in Usec
    UINT32              lastLockTimeService;                        // in Usec
    UINT32              lastAcquireTimeUsec;                        // in Usec
    UINT32              lastTotalAcquireTimeUsec;                   // in Usec
} __PACK__ BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              fecLdpcBlockCounter;                        // cumulative, clear on read
    UINT32              fecLdpcUncorrectedBlockCounter;             // cumulative, clear on read
    UINT32              fecRsBlockCounter;                          // cumulative, clear on read
    UINT32              fecRsUncorrectedBlockCounter;               // cumulative, clear on read
    UINT32              ldpcAvgIterations;                          // in 1/32768 iterations units
    UINT32              rxBytesFromProtection;
    UINT32              rxErrBytesFromProtection;
    UINT32              rxBytesFromWorking;
    UINT32              rxErrBytesFromWorking;
    UINT32              rxOutputTotalBytes;
    UINT32              rxOutputTotalErrBytes;
    UINT32              rsAvgErrBytes;
} __PACK__ BCM_UW_MODEM_FEC_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              fffTaps[48];                                // backwards compatible to 610
    UINT32              fffTaps_20Bit[80];                          // real0, imag0, real1, imag1, �, real39, imag39

    INT32               ec1Taps_20Bit[16];                          // real0, imag0, real1, imag1, �, real7, imag7
    INT32               ec2Taps_20Bit[16];                          // real0, imag0, real1, imag1, �, real7, imag7

    UINT16              ec1Delay;                                   // up to 600
    UINT16              ec2Delay;                                   // up to 600
} __PACK__ BCM_UW_MODEM_EQU_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               g1Re;                                       // (13.11) using BCM85620 fixed point
    INT16               g1Im;                                       //
    INT16               g3Re;                                       // (15.12)
    INT16               g3Im;                                       //
    INT32               g5Re;                                       // (17.12)
    INT32               g5Im;                                       //
} __PACK__ BCM_UW_MODEM_PREDISTORTION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               g1Re;                                       // fixed point, all are (16.12)
    INT16               g1Im;
    INT16               g2Re;
    INT16               g2Im;
    INT16               g3Re;
    INT16               g3Im;
    INT16               g4Re;
    INT16               g4Im;
    INT16               g5Re;
    INT16               g5Im;
} __PACK__ BCM_UW_MODEM_EX_PREDISTORTION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               hReCoefs[10];
    INT16               hImCoefs[10];
    INT16               gReCoefs[10];
    INT16               gImCoefs[10];
    INT16               shImCoefs[10];
    INT16               shReCoefs[10];
    INT16               shHOut;
    INT16               shGOut;
} __PACK__ BCM_UW_MODEM_PREEMPHASIS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                loopbackType;                               // see BCM_UW_LOOPBACK_TYPE_ENUM
    UINT32              durationMilli;                              // 0 = not limited
    BOOLEAN             nearEnd;                                    // N/A 650
    BYTE                tributary;                                  // N/A 650
} __PACK__ BCM_UW_LOOPBACK_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               diffPhaseTenthsDeg;                         // in deg/10 resolution
    INT16               diffGainTenthsDB;                           // in dB/10 resolution
    INT16               dcLeakageITenthsPercent;                    // in %/10
    INT16               dcLeakageQTenthsPercent;                    // in %/10
} __PACK__ BCM_UW_IQ_IMBALANCE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               diffPhaseDeg;                               // in deg/100 resolution
    INT16               diffGainDB;                                 // in dB/100 resolution
    INT16               dcLeakageIPercent;                          // in %/100
    INT16               dcLeakageQPercent;                          // in %/100
} __PACK__ BCM_UW_IQ_IMBALANCE_EX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_IQ_IMBALANCE_STRUCT    txTx;                             // N/A 650
    BCM_UW_IQ_IMBALANCE_STRUCT    rxRx;                             // N/A 650
    BCM_UW_IQ_IMBALANCE_STRUCT    rxTx;                             //
} __PACK__ BCM_UW_MODEM_IQ_IMBALANCE_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              msgLen;
    BYTE                message[32];
} __PACK__ BCM_UW_MAILBOX_MESSAGE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                protectionRxState;                          // see BCM_UW_PROTECTION_RX_STATE_ENUM
    BYTE                rxPhyId;                                    //
    BYTE                protectionRxStateExt;                       // see BCM_UW_PROTECTION_RX_STATE_ENUM
    BYTE                protectionMode;                             // mode: 0 = none, 1 = Working, 2 = Protection
} __PACK__ BCM_UW_PROTECTION_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              acmNumOfSymbols[16];
    UINT32              gpiPayloadSizeInBytes[16];
    BYTE                modulation[16];                             // see BCM_UW_MODULATION_TYPE
} __PACK__ BCM_UW_ACM_CONFIGURATION_STRUCT;

typedef __PACK_PREFIX__ struct
{
    //errors
    BOOLEAN             pllSysIsErr;
    BOOLEAN             pllCpuIsErr;
    BOOLEAN             pllEdbIsErr;
    BOOLEAN             pllDdsIsErr;
    BOOLEAN             pllAuxIsErr;
    BOOLEAN             pllDacIsErr[3];
    BOOLEAN             pllAdcIsErr[6];
    BOOLEAN             versionMismatchErr;

    //clocks
    UINT16              pllSys;                                     // MHz
    UINT16              pllCpu;                                     // MHz

} __PACK__ BCM_UW_DEVCONF_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              numCompressedFlowsEngine1;                  // Number of compressed flows for engine 1
    UINT16              numCompressedFlowsEngine2;                  // Number of compressed flows for engine 2
    BYTE                netCompressionPercent;                      // Average compression gain - Net
    BYTE                grossCompressionPercent;                    // Average compression gain - Gross
    UINT32              currentBwThreshEngine1;                     // Current bandwidth threshold for engine 1
    UINT32              currentBwThreshEngine2;                     // Current bandwidth threshold for engine 2
    UINT16              unCleanCompressedFlowsEngine1;              // Number of compressed flows after QFLUSH for engine 1
    UINT16              unCleanCompressedFlowsEngine2;              // Number of compressed flows after QFLUSH for engine 2
} __PACK__ BCM_UW_HC_STATISTIC_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mask[13];                                   // 13 bytes of mask
} __PACK__ BCM_UW_HC_MASK_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                engine;
    BOOLEAN             adaptiveThreshEnable;                       // One bit selector, fixed threshold for learning [0] or adaptive threshold learning mechanism [1] - task enable
    UINT32              fixedBwThreshBps;                           // This field is relevant only if adaptiveThreshEnable is false. It sets the bandwidth in bps. Range is 100bps-10Mbps
    BYTE                dynamicLearningTableTargetPercent;          // The desired percents up to 100%, used by the adaptive learning task
    UINT32              minDynamicBwThreshBps;                      // The minimum BW threshold used by the adaptive learning task, Range is 100bps-10Mbps
    BYTE                threshUpdateStepPercent;                    // How many percents increase or decrease in every step used by the adaptive learning task, Range 1-50%
    UINT32              threshUpdatePeriodMsec;                     // Period in milliseconds between threshold update by the adaptive learning task, Range [100mSec-100Sec]
    UINT32              measurementPeriodMsec;                      // Period in millisecond between 2 measurements used by the adaptive learning task, Range [30msec-1Sec]
} __PACK__ BCM_UW_HC_LEARNING_AGEING_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             periodicEnable;                             // Running mode of the DB refresh task (0=one shot, 1= periodic).
    UINT32              frequencyMsec;                              // Set how often the task DB refresh task will start a new iteration. Note: affect only in periodic mode
    UINT16              rateEntries;                                // Set how many entries will be refreshed per compression window. Valid numbers are between 1-1024
} __PACK__ BCM_UW_HC_DB_REFRESH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              fifoA;                                      //fifo_A latency [Nano tenths]
    UINT32              equalizer;                                  //equalizer [Nano tenths]
    UINT32              dataRx;                                     //data RX [Nano tenths]
    UINT32              chainDelay;                                 //chain delay [Nano tenths]
} __PACK__ BCM_UW_MODEM_FIFO_LEVELS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                plaMode;
    BYTE                rxState;
    BYTE                txState;
    BOOLEAN             plaAISCondition;
    BOOLEAN             cableDown;                                  // N/A 650
} __PACK__ BCM_UW_PLA_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              splitterMasterPacketsLow;
    UINT32              splitterMasterPacketsHigh;
    UINT32              splitterSlavePacketsLow;
    UINT32              splitterSlavePacketsHigh;
    UINT32              combinerMasterPacketsLow;
    UINT32              combinerMasterPacketsHigh;
    UINT32              combinerSlavePacketsLow;
    UINT32              combinerSlavePacketsHigh;
    UINT32              fcsMasterErrorOnAirLow;
    UINT32              fcsMasterErrorOnAirHigh;
    UINT32              fcsSlaveErrorOnAirLow;
    UINT32              fcsSlaveErrorOnAirHigh;
} __PACK__ BCM_UW_PLA_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              mask;                                       // Bit mask indicating which of the 10 DAC values are to be changed.    // 650 function - handles only the LSB 8 channels
    UINT16              value[10];                                  // For each DAC value, only the 10 LSBs are effective (6 MSBs are ignored). The value is 10 bit unsigned
} __PACK__ BCM_UW_AUXDAC_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              singleEndedMask;                            // Bit mask indicating which of the 8 single-ended DAC values are to be changed.
    UINT16              singleEndedValues[8];                       // For each DAC value, only the 10 LSBs are effective. The value is 10 bit unsigned.
    UINT32              differentialMask;                           // Bit mask indicating which of the 18 differential DAC values are to be changed.
    UINT32              differentialValues[18];                     // For each DAC value, only the 18 LSBs are effective. The value is 18 bit signed.
} __PACK__ BCM_UW_AUXDAC_EX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              value[16];                                  // For each ADC value, only the 10 LSBs are effective. The value is 10 bit unsigned.
} __PACK__ BCM_UW_AUXADC_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             enable;
    BOOLEAN             trackInhibit;
    BYTE                xpdConDes;                                  // see BCM_UW_DIG_XPD_MODE_ENUM
    INT16               snrTenthsDB;                                // 0 - bypass, 0 < snrTenthsDB <= 1000
    INT16               xpdTenthsDB;                                // 0 - bypass, 0 < xpdTenthsDB <= 600
    INT16               txPnTenthsDB;                               // 0 - bypass, -1500 <= txPnTenthsDB <= -800
    INT16               rxPnTenthsDB;                               // 0 - bypass, -1500 <= rxPnTenthsDB <= -800
    INT16               snr2TenthsDB;
    UINT16              etaHundredth;
} __PACK__ BCM_UW_DIG_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               coeffG[16];
} __PACK__ BCM_UW_DIG_CONFIG_EX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // agc mode - see BCM_UW_WB_RX_AGC_MODE_ENUM
    BYTE                lockStatus;                                 // main lock - see BCM_UW_WB_AGC_LOCK_STATUS_ENUM
    BYTE                peakDetectorLockStatus;                     // peak detector lock - see BCM_UW_WB_AGC_LOCK_STATUS_ENUM
    BYTE                innerAgcLockStatus[4];                      // inner agc lock - see BCM_UW_WB_AGC_LOCK_STATUS_ENUM
    INT16               rslDbHundredths[2];                         // rsl
    INT16               peakToAvgDbHundredths;                      // peak to average
    INT16               innerAgcDigitalGainsDbHundredths[2];        // inner agc digital gain
    INT16               digitalGainsDbHundredths[3];                // main agc digital gains
    INT16               analogGainsDbHundredths[4];                 // main agc analog gains
    UINT32              analogGainWords[4];                         // values written to DACs
    INT16               wbPowerDetectorDbHundredths[2];             // power detector - wideband output
    INT16               bbAafPowerDetectorDbHundredths[4];          // power detector - AAF output, up to two chains observed
    INT16               bbRrcPowerDetectorDbHundredths[4];          // power detector - RRC output, up to two chains observed
    BYTE                disturberDetected;                          // Induction of Gain Modifier transfering gain due to disturbances
} __PACK__ BCM_UW_WB_RXAGC_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // agc mode - see BCM_UW_WB_TX_AGC_MODE_ENUM
    BYTE                lockStatus;                                 // main lock - see BCM_UW_WB_AGC_LOCK_STATUS_ENUM
    INT16               currentTargetPowerDbmHundredths[2];         // instantaneous target power values, output of ramp function
    INT16               digitalGainsDbHundredths[3];                // digital gains (mode dependent)
    INT16               analogGainsDbHundredths[4];                 // analog gains
    UINT32              analogGainWords[4];                         // values written to DACs
    UINT16              analogPowerMeterWord;                       // value read from ADC
    INT16               analogPowerMeterDbm;                        // volt to dBM LUT output
    BOOLEAN             isOpenLoop;                                 // open loop mode indication
    INT16               currentCombinedTargetPowerDbmHundredths;    // instantaneous combined target power values
} __PACK__ BCM_UW_WB_TXAGC_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_IQ_IMBALANCE_STRUCT      rxRx;
    INT32                           ncoFreqKhz;
} __PACK__ BCM_UW_WB_RX_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_IQ_IMBALANCE_EX_STRUCT   txTx;
    UINT16                          txTxFracDelay;
    INT32                           ncoFreqKhz;
    BYTE                            transmitterMode;                // see BCM_UW_WB_TRANSMITTER_MODE_ENUM
} __PACK__ BCM_UW_WB_TX_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN                         flashHeaderValid;
    BOOLEAN                         firmware0Valid;
    BOOLEAN                         firmware1Valid;
    BOOLEAN                         ffsValid;
    UINT32                          firmware0BurnNumber;
    UINT32                          firmware1BurnNumber;
    BCM_UW_FIRMWARE_VERSION_STRUCT  firmware0ver;
    BCM_UW_FIRMWARE_VERSION_STRUCT  firmware1ver;
} __PACK__ BCM_UW_FLASH_INFO_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               freq[4];                                    // [MHz/10]
    UINT16              depth[4];                                   // [TdB]
    BYTE                mphase[4];                                  // 0=NON_MINIMUM_PHASE_E 1=MINIMUM_PHASE_E
    BYTE                enable[4];                                  // enable
} __PACK__ BCM_UW_DIG_NOTCH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             enable;                                     // enable
    INT16               gainDbTenth;                                // in 0.2 dB steps
    UINT16              a2Re;                                       // <14,12>
    UINT16              a2Im;                                       // <14,12>
    UINT16              a4Re;                                       // <14,12>
    UINT16              a4Im;                                       // <14,12>
} __PACK__ BCM_UW_DIG_PA_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                packetType;                                 // type value for this API
    BYTE                fieldOffset[7];                             // array
    BYTE                classifierIndex[7];                         // array - each point to one of the "Classifiers" defined by the other parser API
    BOOLEAN             headerIs1588;                               // 1588 bit
    BYTE                classifierIndexSelect;                      // one of the 7 "classifierIndex" defined in this API (6=disable)
    UINT16              value2;                                     // relevant to the "classifierIndexSelect"
} __PACK__ BCM_UW_HC_PARSER_TYPE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                index;
    UINT16              mask;
    UINT16              value1;
} __PACK__ BCM_UW_HC_PARSER_CLASSIFIER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               tapsI[32];                                  // s<16,15>
    INT16               integerDelayQ;                              //
} __PACK__ BCM_UW_IQ_MISMATCH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT32               taps[40];                                   // s<18,15>
    BOOLEAN             enable;                                     //
} __PACK__ BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                transmitterMode;                            // see BCM_UW_WB_TRANSMITTER_MODE_ENUM
    INT32               toneFreqKhz;                                //
    BOOLEAN             useExplicitPower;                           // False - use implicit power, same as current mask power
    INT16               transmitPowerDbTenths;                      // manual gain
} __PACK__ BCM_UW_WB_TRANSMITTER_MODE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                transmitterMode;                            // see BCM_UW_WB_TRANSMITTER_MODE_ENUM
    INT32               toneFreqKhz;                                //
    BOOLEAN             useExplicitPower;                           // False - use implicit power, same as current mask power
    INT16               transmitPowerDbTenths;                      // manual gain
    UINT32              muteTimeMili;                               // mute time [mili] (optional)
} __PACK__ BCM_UW_WB_TRANSMITTER_MODE_EX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               analogGain0[BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_ROWS];    // indexing is in whole dBs, from [-110dB...+10dB]
    INT16               analogGain1[BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_ROWS];    // values are gains in dB, signed with 9 bit precision, e.g. +5dB is represented as 0x0A00 and -18dB
    INT16               analogGain2[BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_ROWS];
    INT16               analogGain3[BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_ROWS];
} __PACK__ BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               analogGain0[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];    // indexing is in whole dBs, from [-20dB...+40dB] TBD
    INT16               analogGain1[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];    // values are gains in dB, signed with 9 bit precision, e.g. +5dB is represented as 0x0A00 and -18dB
    INT16               analogGain2[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];
    INT16               analogGain3[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];
    INT16               cfrGain[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];
    INT16               wbGain[BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_ROWS];
} __PACK__ BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              analogDacWord0[BCM_UW_WB_AGC_DB_TO_DAC_TABLE_ROWS];    // indexing is by 0.5dB, from -64dB to +63.5dB
    UINT16              analogDacWord1[BCM_UW_WB_AGC_DB_TO_DAC_TABLE_ROWS];    // values are AUX DAC 16-bit words
    UINT16              analogDacWord2[BCM_UW_WB_AGC_DB_TO_DAC_TABLE_ROWS];
    UINT16              analogDacWord3[BCM_UW_WB_AGC_DB_TO_DAC_TABLE_ROWS];
} __PACK__ BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              lowPriorityFlowFifoLevel;
    UINT16              highPriorityFlowFifoLevel;
    UINT16              lowPriorityFlowPacketCounter;
    UINT16              highPriorityFlowPacketCounter;
} __PACK__ BCM_UW_MAC_FIFO_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              fragFragmentsHigh;
    UINT32              fragFragmentsLow;
    UINT32              fragUnfragmentedPacketsHigh;
    UINT32              fragUnfragmentedPacketsLow;
    UINT32              defragFragmentsHigh;
    UINT32              defragFragmentsLow;
    UINT32              defragUnfragmentedPacketsHigh;
    UINT32              defragUnfragmentedPacketsLow;
    UINT32              defragErrorPacketsHigh;
    UINT32              defragErrorPacketsLow;
} __PACK__ BCM_UW_FRAG_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              adcWord[BCM_UW_WB_TXAGC_ADC_TO_DBM_TABLE_ROWS];        // indexing is by 0.5dB, from -20dB to +40dB
} __PACK__ BCM_UW_WB_AGC_ADC_TO_DBM_TABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              rxFrequency0Khz;
    UINT32              rxFrequency1Khz;
    UINT32              txFrequency0Khz;
    UINT32              txFrequency1Khz;
    INT16               targetPowerDbmTenths;
} __PACK__ BCM_UW_RF_ALL_INITIALIZE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16              mctVersion;
    UINT16              mctRevision;
    UINT16              mctBuild;
    UINT16              xmlVersion;
    UINT16              xmlRevision;
    UINT16              xmlBuild;
    UINT16              xmlChipType;
    BYTE                xmlChipSN[11];
} __PACK__ BCM_UW_RF_CHIP_FILES_PROPERTIES_STRUCT;

typedef __PACK_PREFIX__ struct
{
    //chip data
    BYTE                chipType;                                   // E.g. "S"/"T"/"R"/"?"
    BYTE                chipBand;                                   // E.g. "U"/"K"/"X"...
    BYTE                chipVersion;                                

    //synt lock
    BOOLEAN             isLocked;

    //temperature readout
    UINT16              temperatureAdcReading;                      // raw reading of AUX ADC used connected to temperature sensor
    INT8                temperatureDegrees;                         // conversion of raw reading into degrees based on calibration data. If not calibrated, meaningless

    //actual frequency
    UINT32              frequency;

    BOOLEAN             isValid;
} __PACK__ BCM_UW_RF_SYNT_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    //chip data
    BYTE                chipType;                                   // E.g. "S"/"T"/"R"/"?"
    BYTE                chipBand;                                   // E.g. "U"/"K"/"X"...
    BYTE                chipVersion;                                // E.g. 0xA0
    BOOLEAN             isCalibrated;

    //temperature readout
    UINT16              temperatureAdcReading;                      // raw reading of AUX ADC used connected to temperature sensor
    INT8                temperatureDegrees;                         // conversion of raw reading into degrees based on calibration data. If not calibrated, meaningless

    //power output readout
    UINT16              powerOutAdcReading;                         // reading of WB ADPD power meter
    INT16               powerOutDbmTenths;                          // conversion of raw reading into tenths of dBm based on calibration data, typical values are [-30dB..+30dB]. If not calibrated, meaningless

    //synt chip status
    BCM_UW_RF_SYNT_STATUS_STRUCT    syntStatus;

    //mct & xml files data
    BCM_UW_RF_CHIP_FILES_PROPERTIES_STRUCT filesProperties;

} __PACK__ BCM_UW_RF_TX_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    //chip data
    BYTE                chipType;                                   // E.g. "S"/"T"/"R"/"?"
    BYTE                chipBand;                                   // E.g. "U"/"K"/"X"...
    BYTE                chipVersion;                                // E.g. 0xA0
    BOOLEAN             isCalibrated;

    //temperature readout
    UINT16              temperatureAdcReading;                      // raw reading of AUX ADC used connected to temperature sensor
    INT8                temperatureDegrees;                         // conversion of raw reading into degrees based on calibration data. If not calibrated, meaningless

    //RSSI readout
    UINT16              rssiAdcReading;                             // raw reading of AUX ADC used connected to RSSI sensor
    INT16               rssiDdmTenths;                              // conversion of raw reading into tenths of dBm based on calibration data and AGC status (LNA gains). If not calibrated, meaningless

    //synt chip status
    BCM_UW_RF_SYNT_STATUS_STRUCT    syntStatus;

    //mct & xml files data
    BCM_UW_RF_CHIP_FILES_PROPERTIES_STRUCT filesProperties;

} __PACK__ BCM_UW_RF_RX_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               rslDbTenths0;
    INT16               rslDbTenths1;
} __PACK__ BCM_UW_RF_RX_RSL_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                rfDevIdx;
    BYTE                rfDevType;                                  // see BCM_UW_RF_CHIP_TYPE_ENUM
    INT16               messageIdx;                                 // progress is sequential 1,2,3... Error is indicated by messageIdx < 0
    INT32               paramsInt[2];                                  
    INT16               paramsShort;                                   
    INT16               uwErrorCode;                                // error code of BCM_UW_ERROR_MSG_ENUM
} __PACK__ BCM_UW_RF_PROGRESS_ERROR_MSG_STRUCT;                        

typedef __PACK_PREFIX__ struct
{
    BCM_UW_RF_PROGRESS_ERROR_MSG_STRUCT message[14];                // HOST_PROTOCOL_MAX_PAYLOAD_LEN / sizeof(BCM_UW_RF_PROGRESS_ERROR_MSG_STRUCT)
    BYTE                text[16];                                   // free text from progress mechanism
    BYTE                lastMessageIdx;                             // indicates the last message index
} __PACK__ BCM_UW_RF_PROGRESS_ERROR_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              firmware0Offset;
    UINT32              firmware1Offset;
    UINT32              ffsOffset;
    UINT32              firmware0Length;
    UINT32              firmware1Length;
    UINT32              ffsLength;
    UINT32              flashInfoLength;
    UINT32              checksum;
    BYTE                flashInfo[BCM_UW_FLASH_INFO_MAX_SIZE];
} __PACK__ BCM_UW_FLASH_HEADER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                laneMapRx[4];                               // Rx lanes array
    BYTE                laneMapTx[4];                               // Tx lanes array
} __PACK__ BCM_UW_ETH_PORT_INITIALIZE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32              cmdSelect;                                  // see BCM_UW_ETH_PORT_SET_SELECT_ENUM
    UINT32              portIf;                                     // see BCM_UW_ETH_PORT_IF_ENUM
    BYTE                speed;                                      // see BCM_UW_ETH_PORT_SPEED_ENUM
    BYTE                portEnable;                                 // see BCM_UW_ETH_PORT_STATE_ENUM
    BOOLEAN             autoNegotiationEnable;                      // boolean
    BYTE                crcProcessingMode;                          // see BCM_UW_ETH_PORT_CRC_MODE_ENUM
    BYTE                fcPauseBehavior;                            // see BCM_UW_ETH_PORT_PAUSE_BEHAVIOR_ENUM
    UINT16              fcPauseTimer;                               // value
    UINT16              fcPauseRefreshRate;                         // value
    BYTE                txMacAddr[6];                               // value
    UINT16              maxFrameSize;                               // value
    UINT16              minFrameSize;                               // value
    UINT16              jumboFrameSize;                             // value
    UINT16              pauseThresholdHigh;                         // value
    UINT16              pauseThresholdLow;                          // value
    BYTE                txAvgIPG;                                   // value
    BOOLEAN             rxMinIPGEnable;                             // value
    BYTE                txPreambleLength;                           // boolean
    BYTE                loopbackType;                               // see BCM_UW_ETH_PORT_LOOPBACK_TYPE_ENUM
    UINT32              controlDiscardMask;                         // value
    BYTE                pauseAbilityMode;                           // see BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM
    BYTE                autonegAbilityMode;                         // see BCM_UW_ETH_PORT_AN_ABILITY_MODE_ENUM
    BYTE                vlanTagEnableMode;                          // see BCM_UW_ETH_PORT_VLAN_TAG_MODE
    UINT16              outerVlanTpid;                              // value
    UINT16              innerVlanTpid;                              // value
} __PACK__ BCM_UW_ETH_PORT_CONFIGURE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE                linkStatus;                                 // see BCM_UW_ETH_PORT_LINK_STATUS_ENUM
    BYTE                speed;                                      // see BCM_UW_ETH_PORT_SPEED_ENUM
    BYTE                partnerAnPauseAbility;                      // see BCM_UW_ETH_PORT_PAUSE_ABILITY_MODE_ENUM
} __PACK__ BCM_UW_ETH_PORT_STATUS_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32              rx64OctetsLo;                               // Receive 64 Byte Frame Counter - 32 low bits
    UINT8               rx64OctetsHi;                               // Receive 64 Byte Frame Counter - 8 high bits
    UINT32              rx65to127OctetsLo;                          // Receive 65-127 Byte Frame Counter - 32 low bits
    UINT8               rx65to127OctetsHi;                          // Receive 65-127 Byte Frame Counter - 8 high bits
    UINT32              rx128to255OctetsLo;                         // Receive 128-255 Byte Frame Counter - 32 low bits
    UINT8               rx128to255OctetsHi;                         // Receive 128-255 Byte Frame Counter - 8 high bits
    UINT32              rx256to511OctetsLo;                         // Receive 256-511 Byte Frame Counter - 32 low bits
    UINT8               rx256to511OctetsHi;                         // Receive 256-511 Byte Frame Counter - 8 high bits
    UINT32              rx512to1023OctetsLo;                        // Receive 512-1023 Byte Frame Counter - 32 low bits
    UINT8               rx512to1023OctetsHi;                        // Receive 512-1023 Byte Frame Counter - 8 high bits
    UINT32              rx1024to1518OctetsLo;                       // Receive 1024-1518 Byte Frame Counter - 32 low bits
    UINT8               rx1024to1518OctetsHi;                       // Receive 1024-1518 Byte Frame Counter - 8 high bits
    UINT32              rxGv1519to1522OctetsLo;                     // Receive 1519-1522 Byte Good VLAN Frame Counter - 32 low bits
    UINT8               rxGv1519to1522OctetsHi;                     // Receive 1519-1522 Byte Good VLAN Frame Counter - 8 high bits
    UINT32              rx1519to2047OctetsLo;                       // Receive 1519-2047 Byte Frame Counter - 32 low bits
    UINT8               rx1519to2047OctetsHi;                       // Receive 1519-2047 Byte Frame Counter - 8 high bits
    UINT32              rx2048to4095OctetsLo;                       // Receive 2048-4095 Byte Frame Counter - 32 low bits
    UINT8               rx2048to4095OctetsHi;                       // Receive 2048-4095 Byte Frame Counter - 8 high bits
    UINT32              rx4096to9216OctetsLo;                       // Receive 4096-9216 Byte Frame Counter - 32 low bits
    UINT8               rx4096to9216OctetsHi;                       // Receive 4096-9216 Byte Frame Counter - 8 high bits
    UINT32              rx9217to16383OctetsLo;                      // Receive 9217-16383 Byte Frame Counter - 32 low bits
    UINT8               rx9217to16383OctetsHi;                      // Receive 9217-16383 Byte Frame Counter - 8 high bits
    UINT32              rxAllPacketsLo;                             // Receive frame/packet Counter - 32 low bits
    UINT8               rxAllPacketsHi;                             // Receive frame/packet Counter - 8 high bits
    UINT32              rxUnicastPacketsLo;                         // Receive Unicast Frame Counter - 32 low bits
    UINT8               rxUnicastPacketsHi;                         // Receive Unicast Frame Counter - 8 high bits
    UINT32              rxMulticastPacketsLo;                       // Receive Multicast Frame Counter - 32 low bits
    UINT8               rxMulticastPacketsHi;                       // Receive Multicast Frame Counter - 8 high bits
    UINT32              rxBroadcastPacketsLo;                       // Receive Broadcast Frame Counter - 32 low bits
    UINT8               rxBroadcastPacketsHi;                       // Receive Broadcast Frame Counter - 8 high bits
    UINT32              rxBadCRCPacketsLo;                          // Receive FCS Error Frame Counter - 32 low bits
    UINT8               rxBadCRCPacketsHi;                          // Receive FCS Error Frame Counter - 8 high bits
    UINT32              rxMacCtrlPacketsLo;                         // Receive Control Frame Counter - 32 low bits
    UINT8               rxMacCtrlPacketsHi;                         // Receive Control Frame Counter - 8 high bits
    UINT32              rxPauseCtrlPacketsLo;                       // Receive PAUSE Frame Counter - 32 low bits
    UINT8               rxPauseCtrlPacketsHi;                       // Receive PAUSE Frame Counter - 8 high bits
    UINT32              rxUnsuppOpCodCtrlPacketsLo;                 // Receive Unsupported Opcode Frame Counter - 32 low bits
    UINT8               rxUnsuppOpCodCtrlPacketsHi;                 // Receive Unsupported Opcode Frame Counter - 8 high bits
    UINT32              rxUnsuppDACtrlPacketsLo;                    // Receive Unsupported DA for PAUSE/PFC Frame Counter - 32 low bits
    UINT8               rxUnsuppDACtrlPacketsHi;                    // Receive Unsupported DA for PAUSE/PFC Frame Counter - 8 high bits
    UINT32              rxIncorrectSAPacketsLo;                     // Receive Incorrect SA Frame Counter - 32 low bits
    UINT8               rxIncorrectSAPacketsHi;                     // Receive Incorrect SA Frame Counter - 8 high bits
    UINT32              rxOutOfRangePacketsLo;                      // Receive Length Out of Range Frame Counter - 32 low bits
    UINT8               rxOutOfRangePacketsHi;                      // Receive Length Out of Range Frame Counter - 8 high bits
    UINT32              rxCodeErrPacketsLo;                         // Receive Code Error Frame Counter - 32 low bits
    UINT8               rxCodeErrPacketsHi;                         // Receive Code Error Frame Counter - 8 high bits
    UINT32              rxOverSizedPacketsLo;                       // Receive Oversized Frame Counter - 32 low bits
    UINT8               rxOverSizedPacketsHi;                       // Receive Oversized Frame Counter - 8 high bits
    UINT32              rxJabberPacketsLo;                          // Receive Jabber Frame Counter - 32 low bits
    UINT8               rxJabberPacketsHi;                          // Receive Jabber Frame Counter - 8 high bits
    UINT32              rxMtuPacketsLo;                             // Receive MTU Check Error Frame Counter - 32 low bits
    UINT8               rxMtuPacketsHi;                             // Receive MTU Check Error Frame Counter - 8 high bits
    UINT32              rxGoodPacketsLo;                            // Receive Good Packet Counter - 32 low bits
    UINT8               rxGoodPacketsHi;                            // Receive Good Packet Counter  - 8 high bits
    UINT32              rxBytesLo;                                  // Receive Byte Counter - 32 low bits
    UINT8               rxBytesHi;                                  // Receive Byte Counter - 8 high bits
    UINT32              rxPromiscPacketsLo;                         // Receive Promiscuous Frame Counter - 32 low bits
    UINT8               rxPromiscPacketsHi;                         // Receive Promiscuous Frame Counter - 8 high bits
    UINT32              rxVtagPacketsLo;                            // Receive VLAN Tag Frame Counter - for single and double VLANs - 32 low bits
    UINT8               rxVtagPacketsHi;                            // Receive VLAN Tag Frame Counter - for single and double VLANs - 8 high bits
    UINT32              rxDVtagPacketsLo;                           // Receive Double VLAN Tag Frame Counter - 32 low bits
    UINT8               rxDVtagPacketsHi;                           // Receive Double VLAN Tag Frame Counter - 8 high bits
    UINT32              rxTruncatedPacketsLo;                       // Receive Truncated Frame Counter (due to RX FIFO full) - 32 low bits
    UINT8               rxTruncatedPacketsHi;                       // Receive Truncated Frame Counter (due to RX FIFO full) - 8 high bits
    UINT32              rxUnderSizedPacketsLo;                      // Receive Undersize Frame Counter - 32 low bits
    UINT8               rxUnderSizedPacketsHi;                      // Receive Undersize Frame Counter - 8 high bits
    UINT32              rxFragPacketsLo;                            // Receive Fragment Counter - 32 low bits
    UINT8               rxFragPacketsHi;                            // Receive Fragment Counter - 8 high bits
}  __PACK__ BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32              tx64OctetsLo;                               // Transmit 64 Byte Frame Counter - 32 low bits
    UINT8               tx64OctetsHi;                               // Transmit 64 Byte Frame Counter - 8 high bits
    UINT32              tx65to127OctetsLo;                          // Transmit 65-127 Byte Frame Counter - 32 low bits
    UINT8               tx65to127OctetsHi;                          // Transmit 65-127 Byte Frame Counter - 8 high bits
    UINT32              tx128to255OctetsLo;                         // Transmit 128-255 Byte Frame Counter - 32 low bits
    UINT8               tx128to255OctetsHi;                         // Transmit 128-255 Byte Frame Counter - 8 high bits
    UINT32              tx256to511OctetsLo;                         // Transmit 256-511 Byte Frame Counter - 32 low bits
    UINT8               tx256to511OctetsHi;                         // Transmit 256-511 Byte Frame Counter - 8 high bits
    UINT32              tx512to1023OctetsLo;                        // Transmit 512-1023 Byte Frame Counter - 32 low bits
    UINT8               tx512to1023OctetsHi;                        // Transmit 512-1023 Byte Frame Counter - 8 high bits
    UINT32              tx1024to1518OctetsLo;                       // Transmit 1024-1518 Byte Frame Counter - 32 low bits
    UINT8               tx1024to1518OctetsHi;                       // Transmit 1024-1518 Byte Frame Counter - 8 high bits
    UINT32              txGv1519to1522OctetsLo;                     // Transmit 1519-1522 Byte Good VLAN Frame Counter - 32 low bits
    UINT8               txGv1519to1522OctetsHi;                     // Transmit 1519-1522 Byte Good VLAN Frame Counter - 8 high bits
    UINT32              tx1519to2047OctetsLo;                       // Transmit 1519-2047 Byte Frame Counter - 32 low bits
    UINT8               tx1519to2047OctetsHi;                       // Transmit 1519-2047 Byte Frame Counter - 8 high bits
    UINT32              tx2048to4095OctetsLo;                       // Transmit 2048-4095 Byte Frame Counter - 32 low bits
    UINT8               tx2048to4095OctetsHi;                       // Transmit 2048-4095 Byte Frame Counter - 8 high bits
    UINT32              tx4096to9216OctetsLo;                       // Transmit 4096-9216 Byte Frame Counter - 32 low bits
    UINT8               tx4096to9216OctetsHi;                       // Transmit 4096-9216 Byte Frame Counter - 8 high bits
    UINT32              tx9217to16383OctetsLo;                      // Transmit 9217-16383 Byte Frame Counter - 32 low bits
    UINT8               tx9217to16383OctetsHi;                      // Transmit 9217-16383 Byte Frame Counter - 8 high bits
    UINT32              txAllPacketsLo;                             // Transmit Frame/packet Counter - 32 low bits
    UINT8               txAllPacketsHi;                             // Transmit Frame/packet Counter - 8 high bits
    UINT32              txGoodPacketsLo;                            // Transmit Good Frame Counter - 32 low bits
    UINT8               txGoodPacketsHi;                            // Transmit Good Frame Counter - 8 high bits
    UINT32              txUnicastPacketsLo;                         // Transmit Unicast Frame Counter - 32 low bits
    UINT8               txUnicastPacketsHi;                         // Transmit Unicast Frame Counter - 8 high bits
    UINT32              txMulticastPacketsLo;                       // Transmit Multicast Frame Counter - 32 low bits
    UINT8               txMulticastPacketsHi;                       // Transmit Multicast Frame Counter - 8 high bits
    UINT32              txBroadcastPacketsLo;                       // Transmit Broadcast Frame Counter - 32 low bits
    UINT8               txBroadcastPacketsHi;                       // Transmit Broadcast Frame Counter - 8 high bits
    UINT32              txPauseCtrlPacketsLo;                       // Transmit PAUSE Frame Counter - 32 low bits
    UINT8               txPauseCtrlPacketsHi;                       // Transmit PAUSE Frame Counter - 8 high bits
    UINT32              txJabberPacketsLo;                          // Transmit Jabber Frame Counter - 32 low bits
    UINT8               txJabberPacketsHi;                          // Transmit Jabber Frame Counter - 8 high bits
    UINT32              txBadCRCPacketsLo;                          // Transmit FCS Error Frame Counter - 32 low bits
    UINT8               txBadCRCPacketsHi;                          // Transmit FCS Error Frame Counter - 8 high bits
    UINT32              txMacCtrlPacketsLo;                         // Transmit Control Frame Counter - 32 low bits
    UINT8               txMacCtrlPacketsHi;                         // Transmit Control Frame Counter - 8 high bits
    UINT32              txOverSizedPacketsLo;                       // Transmit Oversized Frame Counter - 32 low bits
    UINT8               txOverSizedPacketsHi;                       // Transmit Oversized Frame Counter - 8 high bits
    UINT32              txSetBySysErrPacketsLo;                     // Transmit Error (set by system) Counter - 32 low bits
    UINT8               txSetBySysErrPacketsHi;                     // Transmit Error (set by system) Counter - 8 high bits
    UINT32              txVtagPacketsLo;                            // Transmit VLAN Tag Frame Counter - for single and double VLANs - 32 low bits
    UINT8               txVtagPacketsHi;                            // Transmit VLAN Tag Frame Counter - for single and double VLANs - 8 high bits
    UINT32              txDVtagPacketsLo;                           // Transmit Double VLAN Tag Frame Counter - 32 low bits
    UINT8               txDVtagPacketsHi;                           // Transmit Double VLAN Tag Frame Counter - 8 high bits
    UINT32              txTotalBytesLo;                             // Transmit Byte Counter - 32 low bits
    UINT8               txTotalBytesHi;                             // Transmit Byte Counter - 8 high bits
}  __PACK__ BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT;
typedef __PACK_PREFIX__ struct
{
    //resistance
    UINT16              rmonInternalAdcReading;                     // ADC internal
    UINT16              rmonExternalAdcReading;                     // ADC external
    INT16               rmonPercentDeviationTenths;                 // deviation [%/10]

    //temperature
    INT16               temperatureTenths[2];                       // [deg(c)/10]

    //voltages [mv]
    UINT16              v3p3[2];                                    // V3.3 - pvtmon0,pvtmon1
    UINT16              v1p8[2];                                    // V1.8 - ..
    UINT16              vddc[2];                                    // Vddc - ..

    //1V [mv]
    UINT16              v1p0Eth[3];                                 // at ETH - current,min,max (clear on read)
    UINT16              v1p0Dsp0[3];                                // at DSP - ..
    UINT16              v1p0Ecr[3];                                 // at ECR - ..
    UINT16              v1p0Sc1[3];                                 // at SC1 - ..
} __PACK__ BCM_UW_PVTMON_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BOOLEAN             enable;
    BYTE                tbStrobeSignal;                             // select strobe from tb inputs 0..36

    //data
    BYTE                wordSize;                                   // see BCM_UW_DSP_PACK_DPACK_WORD_SIZE_ENUM
    BYTE                dataMuxMapping[64];                         // 0..35 tb inputs, 37 = const 1, 38 = const 0

    //control
    BYTE                ctrlMuxMapping[16];                         // 0..35 tb inputs, 37 = const 1, 38 = const 0
    BOOLEAN             ctrlPathEnable;
    UINT16              ctrlEventDetectorMask[3];
    BYTE                ctrlEventDetectorMode[3];
    BYTE                ctrlEventDetectorChangeCtrlBit[3];
    BYTE                ctrlEventDetectorMinTimeBetweenEvents[3];   // in rows
} __PACK__ BCM_UW_DSP_BLOCK_PACKER_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // see BCM_UW_DSP_DEPACKER_MODE_ENUM
    BYTE                wordSize;                                   // see BCM_UW_DSP_PACK_DPACK_WORD_SIZE_ENUM
    BYTE                ibMuxMapping[37];                           // 0..36 select data input bit, 64..79 select ctrl input bit, 80 = const 0, 81 = const 1
    BOOLEAN             ibIdleStrobe;                               // Strobe passes to the injection bus or gated when idle
    UINT32              ibIdleValueLow;                             // Pre-configured value bits 31:0
    BYTE                ibIdleValueHigh;                            // Pre-configured value bits 35:32
    BOOLEAN             ibAFMask;                                   // Mask or unmask IB AF signal
    BYTE                ibStrobeSource;                             // see BCM_UW_DSP_DEPACKER_STROBE_SOURCE_ENUM
} __PACK__ BCM_UW_DSP_BLOCK_DEPACKER_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // see BCM_UW_DSP_DIF_MODE_ENUM
    BYTE                segmentThreshold;                           // Segment threshold in rows (0..255 for DIF0, 0..127 for DIF1)
    BYTE                AEThreshold;                                // AE threshold in rows (0..254 for DIF0, 0..126 for DIF1)
    BYTE                AEHysteresis;                               // AE Hysteresis in rows (0..3)
    BYTE                AFThreshold;                                // AF threshold in rows (0..254 for DIF0, 0..126 for DIF1)
    UINT16              freeRunningBufferSize;                      // Periodic interrupt will assert every Buffer Size write operations. (1..256 for DIF0, 1..128 for DIF1)
    UINT16              freeRunningReturnToZero;                    // Number of rows to be written to trigger return to address 0 (1..256 for DIF0, 1..128 for DIF1)
    BYTE                dif1InputSel;                               // see BCM_UW_DIF1_INPUT_SEL_ENUM - relevant only for DIF1
} __PACK__ BCM_UW_DSP_BLOCK_DIF_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // see BCM_UW_DSP_DOF_MODE_ENUM
    BYTE                segmentThreshold;                           // Segment threshold in rows (0..32)
    BYTE                AEThreshold;                                // AE threshold in rows (0..32)
    BYTE                AFThreshold;                                // AF threshold in rows (0..32)
    BYTE                AFHysteresis;                               // AF Hysteresis in rows (0..3)
    BYTE                freeRunningBufferSize;                      // Size of the buffer in rows (1..32)
    BYTE                freeRunningReturnToZero;                    // Number of rows to be read to trigger return to address 0 (1..32)
} __PACK__ BCM_UW_DSP_BLOCK_DOF_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mode;                                       // see BCM_UW_DSP_CIF_MODE_ENUM
    BYTE                packerConnectivity;                         // see BCM_UW_DSP_CIF_PACKER_CONNECTIVITY_ENUM
} __PACK__ BCM_UW_DSP_BLOCK_CIF_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             enable;
    UINT32              INT1MaskLow;                                // 31:0
    UINT32              INT1MaskHigh;                               // 63:32
    UINT32              INT2MaskLow;                                // 31:0
    UINT32              INT2MaskHigh;                               // 63:32
    BYTE                VINTSource[8];                              // Bits 5:0 - Select VINT interrupt source 0..63. Bit 7 - enable priority
    UINT16              VINTVector[8];                              // TODO: Implement handlers at fixed addresses
} __PACK__ BCM_UW_DSP_BLOCK_IC_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mask;                                       // Bit 5 - DIF0 AE, Bit 4 - DIF0 Segment Threshold, Bit 3 - DOF AF, Bit 2 - DIF1 AE, Bit 1 - DIF1 Segment Threshold, Bit 0 - Not in use
} __PACK__ BCM_UW_DSP_BLOCK_WAIT_AGGREGATOR_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                testbusId[2];
    BYTE                injectionId;
} __PACK__ BCM_UW_DSP_BLOCK_TESTBUS_INJECTION_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_DSP_BLOCK_PACKER_CONFIG_STRUCT               packer[2];
    BCM_UW_DSP_BLOCK_CIF_CONFIG_STRUCT                  cif;
    BCM_UW_DSP_BLOCK_DIF_CONFIG_STRUCT                  dif[2];
    BCM_UW_DSP_BLOCK_DOF_CONFIG_STRUCT                  dof;
    BCM_UW_DSP_BLOCK_DEPACKER_CONFIG_STRUCT             depacker;
    BCM_UW_DSP_BLOCK_IC_CONFIG_STRUCT                   ic;
    BCM_UW_DSP_BLOCK_WAIT_AGGREGATOR_CONFIG_STRUCT      wait_aggregator;
    BCM_UW_DSP_BLOCK_TESTBUS_INJECTION_CONFIG_STRUCT    testbus_injection;
    UINT32                                              user_config[20];
} __PACK__ BCM_UW_DSP_BLOCK_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                mciInputDspIdx;                             // For each of 6 DSP blocks, Bits 2:0 select source MCI bus. Bit 7 - Enable input bus.
    BYTE                dspBlockClock;                              // BCM_UW_DSP_BLOCK_CLOCK_CONFIG_ENUM - per DSP block
    BYTE                bpRequestMask;                              // Per DSP block, bits 5:0 select bp request from DSPs 0..5
    BYTE                dspGPIDspIdx[32];                           // For each of 32 GPI signals to DSPx, select source DSP GPO (according to connectivity matrix)
    BYTE                dspMcciRdIndDspIdx[8];                      // For each of 8 MCCI read indication inputs to DSP0, select source DSP read indication outputs.
    BOOLEAN             loggerCapturePortEn;                        // For each of 6 DSP blocks, enable logger capture
    UINT16              loggerEventMask;                            // For each of 6 DSP blocks, select logger events
} __PACK__ BCM_UW_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT  perDspConfig[BCM_UW_NUM_OF_DSP_E];
} __PACK__ BCM_UW_DSP_SUBSYSTEM_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                                            dspIdx;         // see BCM_UW_DSP_IDX_ENUM
    BCM_UW_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT      subsystemBlockConfig;
} __PACK__ BCM_UW_COM_DSP_SUBSYSTEM_PER_DSP_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                length;
    BYTE                data[128];
} __PACK__ BCM_UW_COM_DSP_HOST_MSG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32              frameLengthHi;
    UINT32              frameLengthLow;
    UINT32              frameCountHi;
    UINT32              frameCountLow;
    UINT32              frameErrCountHi;
    UINT32              frameErrCountLow;
    UINT32              byteCountHi;
    UINT32              byteCountLow;
    UINT32              bitErrorCountHi;
    UINT32              bitErrorCountLow;
    UINT32              berMissedHi;
    UINT32              berMissedLow;
} __PACK__ BCM_UW_BER_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               deltaMv;                                    // Desired delta voltage from host, multiple of power supply step 
    UINT16              vddc;                                       // Same as PVTMON status
    BYTE                state;                                      // V1, V2, V3 track, LVM1
    BOOLEAN             initVoltageDone;                            // Indicates initial voltage was done
} __PACK__ BCM_UW_AVS_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16               txPowerImproveThDbmTenths[3];               // tx Power improve
    INT16               txPowerDegradeThDbmTenths[3];               // tx Power degrade
    INT16               peakToAverageImproveThDbTenths[2];          // peak to average improve
    INT16               peakToAverageDegradeThDbTenths[2];          // peak to average degrade
} __PACK__ BCM_UW_ADPD_AUTO_MODE_CONFIGURE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                adpdModeConfigured;   
    BYTE                adpdModeActual;                                       
} __PACK__ BCM_UW_ADPD_STATUS_STRUCT;                                         

typedef __PACK_PREFIX__ struct
{
    BOOLEAN             txReady;
} __PACK__ BCM_UW_TXRXOP_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                masterDelay;   
    BYTE                slaveDelay;
    BYTE                calibStatus;                                //see BCM_UW_CALIB_STATUS_ENUM
} __PACK__ BCM_UW_XPIC_DELAY_CALIB_STRUCT;                             


typedef __PACK_PREFIX__ struct
{
    BYTE                txPowerMode;                                //see BCM_UW_TXRXOP_CONTROL_TXPWR_MODE_ENUM
} __PACK__ BCM_UW_TXRXOP_CONTROL_STRUCT;
#pragma Pop_align_members()


//----------------------------------------------------
// Functions
//----------------------------------------------------

#ifdef WIN32
    #pragma pack( pop, com_structs )
#endif

//----------------------------------------------------
// Initialization and Communication Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_Open                                 (void);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_Close                                (void);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComConfigure                         (BYTE deviceIndex, BCM_UW_COM_MEDIA_ENUM media, BCM_UW_COM_MEDIA_ENUM dummy, UINT32 refClockInHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComRemoteDeviceConfigure             (BYTE deviceIndex, BYTE remoteDeviceIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComTimeoutSet                        (BYTE deviceIndex, UINT32 timeoutInMilli);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ComMessageForward                    (BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen);

//----------------------------------------------------
// Boot and Configuration Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FirmwareFromHostBoot                 (BYTE deviceIndex, BYTE *pBuffer, UINT32 len, BCM_UW_DEVICE_RESET_TYPE_ENUM reserved);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigure                      (BYTE deviceIndex, char *pBuffer, UINT32 len, BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationParameterModify   (BYTE deviceIndex, char *paramName, INT32 paramValue);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationStringParameterModify (BYTE deviceIndex, char *paramName, char *paramValue);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationStart             (BYTE deviceIndex, BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DeviceConfigurationResultGet         (BYTE deviceIndex, BCM_UW_DEVCONF_STATUS_STRUCT *pDevConfRetStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ConfigFileFromHostLoad               (BYTE deviceIndex, BYTE scIndex, BYTE *pBuffer, UINT32 len);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ConfigFileExFromHostLoad             (BYTE deviceIndex, BYTE scIndex, BYTE *pTxBin, UINT32 lenTx, BYTE *pRxBin, UINT32 lenRx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationStart                   (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationControlSet              (BYTE deviceIndex, BYTE scIndex, BCM_UW_TXRXOP_CONTROL_STRUCT *pTxRxOpCtrlStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxRxOperationStatusGet               (BYTE deviceIndex, BYTE scIndex, BCM_UW_TXRXOP_STATUS_STRUCT *pTxRxOpStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_VersionGet                           (BYTE deviceIndex, BCM_UW_MODEM_VERSION_STRUCT *pVer);

//----------------------------------------------------
// Host-related and General Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmEnableGet                       (BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsMask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmEnableSet                       (BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsMask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AlarmStatusGet                       (BYTE deviceIndex, BCM_UW_ALARMS_STRUCT *pAlarmsStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HostInfoGet                          (BYTE deviceIndex, BCM_UW_HOST_INFO_STRUCT *pInfo);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HostInfoSet                          (BYTE deviceIndex, BCM_UW_HOST_INFO_STRUCT *pInfo);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_MailboxMessageSend                   (BYTE deviceIndex, BYTE scIndex, BCM_UW_MAILBOX_MESSAGE_STRUCT *pMbx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_MailboxMessageReceive                (BYTE deviceIndex, BYTE scIndex, BCM_UW_MAILBOX_MESSAGE_STRUCT *pMbx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TestBusSet                           (BYTE deviceIndex, BYTE scIndex, BCM_UW_TESTBUS_SEL_ENUM testBus1, BCM_UW_TESTBUS_SEL_ENUM testBus2);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_InjectionBusSet                      (BYTE deviceIndex, BYTE scIndex, BCM_UW_INJECTION_SEL_ENUM injSel);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PvtmonRead                           (BYTE deviceIndex, BCM_UW_PVTMON_STRUCT *pVts);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsProcess                           (BYTE deviceIndex, BOOLEAN restart);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsStatusGet                         (BYTE deviceIndex, BCM_UW_AVS_STATUS_STRUCT *avsStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AvsRecommendedLvmGet                 (BYTE deviceIndex, BYTE *lvm);

//----------------------------------------------------
// Modem Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemStatusGet                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_STATUS_STRUCT *pMs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcquireCountersGet              (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_ACQUIRE_COUNTERS_STRUCT *pAc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemFecCountersGet                  (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_FEC_COUNTERS_STRUCT *pFc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqImbalanceStatusGet            (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_IQ_IMBALANCE_STATUS_STRUCT *pIs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemEqualizerStatusGet              (BYTE deviceIndex, BYTE scIndex, BOOLEAN xpicSlave, BCM_UW_MODEM_EQU_STATUS_STRUCT *pEs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemEqualizerExStatusGet            (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, BCM_UW_MODEM_EQU_STATUS_STRUCT *pEs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemXpicStatusGet                   (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_XPIC_STATUS_STRUCT *pXs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRsHistGet                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_RS_HIST_GET_STRUCT *pRhs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsGet           (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREDISTORTION_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsSet           (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREDISTORTION_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsExGet         (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_EX_PREDISTORTION_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPredistortionCoefsExSet         (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_EX_PREDISTORTION_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPreemphasisCoefsGet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREEMPHASIS_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemPreemphasisCoefsSet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_PREEMPHASIS_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesGet                    (BYTE deviceIndex, BYTE scIndex, UINT16 numIqPairs, INT16 *pBuffer, BCM_UW_IQ_SAMPLES_SEL_ENUM inputSel);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesExGet                  (BYTE deviceIndex, BYTE scIndex, UINT32 *pBuffer, BCM_UW_IQ_SAMPLES_SEL_ENUM inputSel);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemIqSamplesSourceSet              (BYTE deviceIndex, BYTE scIndex, BCM_UW_TESTBUS_SEL_ENUM source);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcquireStart                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACQUIRE_MODE_ENUM acqMode, BCM_UW_SPECTRAL_INVERSION_MODE_ENUM siMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PreambleSet                          (BYTE deviceIndex, BYTE scIndex, BYTE index);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxIqDelaySet                         (BYTE deviceIndex, BYTE scIndex, INT16 fdfFracDelay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetSet                      (BYTE deviceIndex, BYTE scIndex, INT32 offsetInKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetSlaveSet                 (BYTE deviceIndex, BYTE scIndex, INT32 offsetInKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RxFreqOffsetExSet                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, INT32 offsetInKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxFreqOffsetSet                      (BYTE deviceIndex, BYTE scIndex, INT32 offsetInKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelaySet                         (BYTE deviceIndex, BYTE scIndex, BYTE delay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicSlaveMuteSet                     (BYTE deviceIndex, BYTE scIndex, BOOLEAN mute);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicToFddSet                         (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelayCalibrationStart            (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_XpicDelayCalibrationStatusGet        (BYTE deviceIndex, BYTE scIndex, BCM_UW_XPIC_DELAY_CALIB_STRUCT *xpicDelayCalibStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxChainDelaySet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, BYTE delay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxChainDelayGet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, BYTE *delay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionStatusGet                  (BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_STATUS_STRUCT *pPs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionModeSet                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_MODE_ENUM protectionMode, BCM_UW_PROTECTION_SYS_MODE_ENUM protectionSysMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionTxRxPhyIdSet               (BYTE deviceIndex, BYTE scIndex, BYTE txPhyId, BYTE rxPhyId);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionRxForceSet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_PROTECTION_MODE_ENUM protectionMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ProtectionTxRxPhyIdExSet             (BYTE deviceIndex, BYTE scIndex, BYTE txPhyId, BYTE rxPhyId, BYTE protectionTxPhyId);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemLockCriteriaSet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_LOCK_CRITERIA_ENUM modemLockCriteria);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemRxFreqLimitSet                  (BYTE deviceIndex, BYTE scIndex, UINT16 fc0FreqLimitKHz);

//----------------------------------------------------
// Modem Modes
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcStatusGet                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_MRC_STATUS_STRUCT *pStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoStatusGet                   (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_MIMO_STATUS_STRUCT *pStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoConfigurationSet            (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_MIMO_CONFIGURATION_STRUCT *pConfig);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoXcDelayCalibrationStart     (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoXcDelayCalibrationStatusGet (BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *xcCalibStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMimoDiversityMuteSet            (BYTE deviceIndex, BYTE scIndex, BOOLEAN mute);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcXcDelayCalibrationStart      (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemMrcXcDelayCalibrationStatusGet  (BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *xcCalibStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RepeaterModeSet                      (BYTE deviceIndex, BYTE scIndex, BCM_UW_REPEATER_MODE_ENUM upLinkMode, BCM_UW_REPEATER_MODE_ENUM downLinkMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RepeaterBaudSet                      (BYTE deviceIndex, BYTE scIndex, UINT32 upLinkBaudKhz, UINT32 downLinkBaudKhz);

//----------------------------------------------------
// Modem Filters
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemTxOutputFilterSet               (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT *pTxOutFilter);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemTxOutputFilterGet               (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_TX_OUTPUT_FILTER_STRUCT *pTxOutFilter);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdModeSet                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_MODE_ENUM adpdMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdCalibrationStart                 (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdCalibrationStatusGet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *adpdCalibStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdGearShiftSet                     (BYTE deviceIndex, BYTE scIndex, BOOLEAN isFastGear);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdAutoModeConfigure                (BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_AUTO_MODE_CONFIGURE_STRUCT *pAdpdAutoModeConfig);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdSystemFreeze                     (BYTE deviceIndex, BYTE scIndex, BOOLEAN isFreeze);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AdpdStatusGet                        (BYTE deviceIndex, BYTE scIndex, BCM_UW_ADPD_STATUS_STRUCT *adpdStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerDelaySet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_CHAIN_ENUM chain, UINT16 ec1Delay, UINT16 ec2Delay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerCalibrationStart         (BYTE deviceIndex, BYTE scIndex, UINT16 cableLengthMetersMin, UINT16 cableLengthMetersMax);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EchoCancelerCalibrationStatusGet     (BYTE deviceIndex, BYTE scIndex, BCM_UW_CALIB_STATUS_ENUM *ecCalibStatus);

//----------------------------------------------------
// Diagnostic Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_LoopbackSet                          (BYTE deviceIndex, BCM_UW_LOOPBACK_STRUCT *lb);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigConfigure                         (BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_CONFIG_STRUCT *digConfig);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigExConfigure                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_CONFIG_EX_STRUCT *digConfig);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigNotchSet                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_NOTCH_STRUCT *digNotch);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DigPaSet                             (BYTE deviceIndex, BYTE scIndex, BCM_UW_DIG_PA_STRUCT *digPa);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_BerMonitorEnable                     (BYTE deviceIndex, BYTE scIndex, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_BerCountersGet                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_BER_COUNTERS_STRUCT *pBerCountersStruct);

//----------------------------------------------------
// ACM Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmCountersGet                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_COUNTERS_STRUCT *pMc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmConfigurationGet                  (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_CONFIGURATION_STRUCT *pCs);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdGet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_TABLE_ENUM engineTable, BCM_UW_ACM_PROFILE_ENUM profile, INT16 *mseTenthsVal, BYTE *ldpcMantissaTenths, BYTE *ldpcExponent, BCM_UW_ACM_CRITERIA_ENUM *criteria, BCM_UW_ACM_PROFILE_ENUM *nextProfile);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdSet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_TABLE_ENUM engineTable, BCM_UW_ACM_PROFILE_ENUM profile, INT16 mseTenthsVal, BYTE ldpcMantissaTenths, BYTE ldpcExponent, BCM_UW_ACM_CRITERIA_ENUM criteria, BCM_UW_ACM_PROFILE_ENUM nextProfile);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdXpdGet              (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_TABLE_ENUM engineTable, BCM_UW_ACM_PROFILE_ENUM profile, UINT16 *xpdTenthsVal);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmThresholdXpdSet              (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_TABLE_ENUM engineTable, BCM_UW_ACM_PROFILE_ENUM profile, UINT16 xpdTenthsVal);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmProfileMaskGet               (BYTE deviceIndex, BYTE scIndex, UINT16 *profilesMask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmProfileEnable                (BYTE deviceIndex, BYTE scIndex, UINT16 profilesMask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmEnhancedEngineModeGet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM *acmEnhancedEngineModeGet);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmEnhancedEngineModeSet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_ENHANCED_ENGINE_MODE_ENUM acmEnhancedEngineModeSet);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmEngineEnable                 (BYTE deviceIndex, BYTE scIndex, BOOLEAN enableRxSensors, BOOLEAN enableTxSwitch);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmSwitch                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_ACM_PROFILE_ENUM acmProfile, BOOLEAN isLocal);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemAcmImproveIfNeeded              (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_ModemGpmDynamicAllocationSet         (BYTE deviceIndex, BYTE scIndex, UINT32 profile, UINT32 gpiBwKbps, UINT32 ethBwKbps, UINT32 txRxMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AcmTxPowerGainUpdate                 (BYTE deviceIndex, BYTE scIndex, BYTE profile, UINT16 txGain);

//----------------------------------------------------
// Networking Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetFixedLatencySet                   (BYTE deviceIndex, BYTE scIndex, BYTE usecTenths);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetAsymmetryDelayGet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_MODEM_FIFO_LEVELS_STRUCT *pFifoLevelStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaStatusGet                         (BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_STATUS_STRUCT *pPlaStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaLimitAcmSet                       (BYTE deviceIndex, BYTE scIndex, UINT16 plaAcmRatioHundredths);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaLimitMseSet                       (BYTE deviceIndex, BYTE scIndex, INT16 mseThrLowTenths, INT16 mseThrHighTenths);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaModeSet                           (BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_MODE_ENUM mode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaForceSet                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_FORCE_ENUM txForce, BCM_UW_PLA_FORCE_ENUM rxForce);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaCountersGet                       (BYTE deviceIndex, BYTE scIndex, BCM_UW_PLA_COUNTERS_STRUCT *plaCounters);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PlaCountersClear                     (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PeerDeviceSet                        (BYTE deviceIndex, BYTE scIndex, BCM_UW_API_PEER_DEVICE_ENUM peerDevice);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationSizeSet                 (BYTE deviceIndex, BYTE scIndex, BCM_UW_FRAG_SIZE_ENUM fragSize);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationCountersGet             (BYTE deviceIndex, BYTE scIndex, BCM_UW_FRAG_COUNTERS_STRUCT *fragCounters);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FragmentationCountersClear           (BYTE deviceIndex, BYTE scIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxMacFifoStatusGet                   (BYTE deviceIndex, BYTE scIndex, BCM_UW_MAC_FIFO_STATUS_STRUCT *fifoStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_TxMacFifoIndicationSet               (BYTE deviceIndex, BYTE scIndex, BOOLEAN enable, UINT16 hFifoLevelTh, BYTE hIndGpio, UINT16 lFifoLevelTh, BYTE lIndGpio);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_8KhzModeSet                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_8KHZ_MODE_ENUM clkOutMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsConfigure                         (BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_SOURCE_ENUM source, UINT32 offsetNsec);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsRtcCalibrationStart               (BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_RTC_CALIB_MODE_ENUM calibMode, UINT16 calibPeriodMsec);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsOutputModeSet                     (BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_OUTPUT_MODE_ENUM outputMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_PpsStatusGet                         (BYTE deviceIndex, BYTE scIndex, BCM_UW_PPS_CALIB_STATUS_ENUM *calibStatus, BCM_UW_PPS_CALIB_FAIL_REASON_ENUM *calibFailReason);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortInitialize                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_ETH_PORT_INITIALIZE_STRUCT *pInit);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortFwLoad                        (BYTE deviceIndex, BYTE scIndex, BYTE *buff, UINT32 len);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortConfigure                     (BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_CONFIGURE_STRUCT *pConfig);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortStatusGet                     (BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_STATUS_STRUCT *pData);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortCountersClear                 (BYTE deviceIndex, BYTE scIndex, BYTE port);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortRxCountersGet                 (BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT *pData);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortTxCountersGet                 (BYTE deviceIndex, BYTE scIndex, BYTE port, BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT *pData);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_EthPortClkSet                        (BYTE deviceIndex, BCM_UW_ETH_PORT_CLK_SRC_ENUM primaryClk, BCM_UW_ETH_PORT_CLK_SRC_ENUM secondaryClk);

//----------------------------------------------------
// Header Compression Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcEngineEnable                       (BYTE deviceIndex, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcMaskSet                            (BYTE deviceIndex, BCM_UW_HC_ENGINE_ENUM engine, BYTE maskIndex, BCM_UW_HC_MASK_STRUCT *mask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcTypeSet                            (BYTE deviceIndex, UINT16 packetType, BYTE engine1MaskIndex, BYTE engine2MaskIndex, UINT16 lenThreshold, UINT16 alternateType);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcLearningAndAgeingConfigure         (BYTE deviceIndex, BCM_UW_HC_LEARNING_AGEING_STRUCT *pHCLa);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcDBRefreshConfigure                 (BYTE deviceIndex, BCM_UW_HC_DB_REFRESH_STRUCT *pHcDbRefresh);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcDBFlush                            (BYTE deviceIndex, BCM_UW_HC_ENGINE_ENUM reserved);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcStatisticsGet                      (BYTE deviceIndex, BCM_UW_HC_STATISTIC_STRUCT *pHcStatistics);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExEngineEnable                     (BYTE deviceIndex, BYTE scIndex, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExMaskSet                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_ENGINE_ENUM engine, BYTE maskIndex, BCM_UW_HC_MASK_STRUCT *mask);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExTypeSet                          (BYTE deviceIndex, BYTE scIndex, UINT16 packetType, BYTE engine1MaskIndex, BYTE engine2MaskIndex, UINT16 lenThreshold, UINT16 alternateType);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExLearningAndAgeingConfigure       (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_LEARNING_AGEING_STRUCT *pHCLa);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExDBRefreshConfigure               (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_DB_REFRESH_STRUCT *pHcDbRefresh);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExDBFlush                          (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_ENGINE_ENUM reserved);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcExStatisticsGet                    (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_STATISTIC_STRUCT *pHcStatistics);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcParserTypeSet                      (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_PARSER_TYPE_STRUCT *pParserType);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_HcParserClassifierSet                (BYTE deviceIndex, BYTE scIndex, BCM_UW_HC_PARSER_CLASSIFIER_STRUCT *pParserClassifier);

//----------------------------------------------------
// Peripheral Access Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIOIntConfig                        (BYTE deviceIndex, BYTE bitIndex, BCM_UW_GPIO_INT_ENUM intType, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIORead                             (BYTE deviceIndex, BCM_UW_GPIO_STRUCT mask, BCM_UW_GPIO_STRUCT *readData, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GPIOWrite                            (BYTE deviceIndex, BCM_UW_GPIO_STRUCT mask, BCM_UW_GPIO_STRUCT data, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACWrite                          (BYTE deviceIndex, BCM_UW_AUXDAC_STRUCT *pAuxDac);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACExWrite                        (BYTE deviceIndex, BCM_UW_AUXDAC_EX_STRUCT *pAuxDac);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxDACExRead                         (BYTE deviceIndex, BCM_UW_AUXDAC_EX_STRUCT *pAuxDac);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_AuxADCRead                           (BYTE deviceIndex, BCM_UW_AUXADC_STRUCT *pAuxAdc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetEthPhyRegGet                      (BYTE deviceIndex, BYTE scIndex, BYTE phyId, BYTE regAddress, UINT16* val);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_NetEthPhyRegSet                      (BYTE deviceIndex, BYTE scIndex, BYTE phyId, BYTE regAddress, UINT16 val);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_I2CTransaction                       (BYTE deviceIndex, BYTE slaveAddress, BYTE *txBuffer, BYTE txBufferLen, BYTE *rxBuffer, BYTE rxBufferLen, BCM_UW_I2C_FREQUENCY_ENUM frequency);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_SPITransaction                       (BYTE deviceIndex, BCM_UW_SPI_MASTER_CS_ENUM spiMasterCs, BYTE *txBuffer, BYTE txBufferLen, BYTE *rxBuffer, BCM_UW_SPI_PHASE_POLARITY_ENUM phasePolarity, BCM_UW_SPI_FREQUENCY_ENUM frequency);

//----------------------------------------------------
// Debug Functions
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GeneralControlSet                    (BYTE deviceIndex, BYTE scIndex, UINT32 opcode, BYTE  length, BYTE *data, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_GeneralControlGet                    (BYTE deviceIndex, BYTE scIndex, UINT32 opcode, BYTE *length, BYTE *data, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DebugMsgGet                          (BYTE deviceIndex, BYTE scIndex, BYTE *pBuffer, UINT32 *lenBytes, CPU_TYPE_ENUM cpu);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RegisterRead                         (BYTE deviceIndex, BYTE scIndex, UINT32 offset, CPU_TYPE_ENUM cpu, UINT16 *pVal);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RegisterWrite                        (BYTE deviceIndex, BYTE scIndex, UINT32 offset, CPU_TYPE_ENUM cpu, UINT16 val);

//----------------------------------------------------
// New Functions - WideBand
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxStatusGet                        (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_WB_RX_STATUS_STRUCT *wbRxStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxStatusGet                        (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TX_STATUS_STRUCT *wbTxStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxFreqSet                          (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, INT32 ncoFreqKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxFreqSet                          (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, INT32 ncoFreqKHz);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqDelaySet                       (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, INT16 fdfFracDelay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxSet                            (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, INT16 diffPhaseDeg, INT16 diffGainDB, INT16 dcLeakageIPercent, INT16 dcLeakageQPercent);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxModeSet                        (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_TXTX_MODE_ENUM txTxMode);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxDelaySet                       (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, UINT16 txTxFracDelay);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxCalibrationStart               (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxTxCalibrationStatusGet           (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_CALIB_STATUS_ENUM *txTxCalibStatus);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqMismatchCorrectionSet          (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_IQ_MISMATCH_STRUCT *pIqmc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxIqMismatchCorrectionGet          (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_IQ_MISMATCH_STRUCT *pIqmc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTransmitterModeSet                 (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TRANSMITTER_MODE_STRUCT *tx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTransmitterModeExSet               (BYTE deviceIndex, BCM_UW_WB_TX_NAME_ENUM wbTxIndex, BCM_UW_WB_TRANSMITTER_MODE_EX_STRUCT *tx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSpectralInversionSet             (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BOOLEAN specInvOn);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSnapshotConfigure                (BYTE deviceIndex, BCM_UW_WB_RX_NAME_ENUM wbRxIndex, BCM_UW_BLOCK_CHANNEL_INDEX_SEL_ENUM blockSel, BCM_UW_BLOCK_HOST_TB_SEL_ENUM hostSel, BYTE dataMode, BOOLEAN repeat, BOOLEAN dummy1);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxSnapshotGet                      (BYTE deviceIndex, INT16 *pBuffer);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcStatusGet                     (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_STATUS_STRUCT* rxagcStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcGainDistributionTableSet      (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_GAIN_DIST_TABLE_STRUCT *rxAgcGDTable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcDbToDacTableSet               (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *rxAgcDB2DACTable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcFreeze                        (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcGainDistributionRowForce      (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BYTE row, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcSetPointAndPeakSet            (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, INT16 mainSetPointDbTenth, INT16 innerSetPointDbTenth, INT16 peakValueDbTenth);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBandwidthSet                  (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BYTE mainTrackIndex, BYTE gainModifierIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBackoffOffsetSet              (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, INT16 gainOffset0DbTenth, INT16 gainOffset1DbTenth, INT16 gainOffset2DbTenth, INT16 gainOffset3DbTenth);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcBackofCompensationSet         (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BCM_UW_WB_RXAGC_ANALOG_GAIN_ENUM analogGainIdx, INT16 totalGainCompensationDbTenth);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbRxAgcTableOffsetSet                (BYTE deviceIndex, BCM_UW_WB_RX_SOURCE_NAME_ENUM adcIndex, BOOLEAN enable, INT16 offsetDbTenth);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcStatusGet                     (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_TXAGC_STATUS_STRUCT *txagc);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcConfigure                     (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BOOLEAN isOpenLoop, UINT16 targetPowerChangeRateDbHundredth);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcTargetPowerSet                (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, INT16 targetPower0DbmTenth, INT16 targetPower1DbmTenth);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcGainDistributionTableSet      (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_TXAGC_GAIN_DIST_TABLE_STRUCT *txAgcGDTable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcDbToDacTableSet               (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_AGC_DB_TO_DAC_TABLE_STRUCT *txAgcDB2DACTable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcAdcToDbmTableSet              (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BCM_UW_WB_AGC_ADC_TO_DBM_TABLE_STRUCT *txAgcAdc2DBMTable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcFreeze                        (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BOOLEAN enable);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_WbTxAgcGainDistributionRowForce      (BYTE deviceIndex, BCM_UW_WB_TX_DEST_NAME_ENUM dacIndex, BYTE row, BOOLEAN enable);

//----------------------------------------------------
// RF Functions - Initializtion and Operation
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_AllInitialize                     (BYTE deviceIndex, BCM_UW_RF_ALL_INITIALIZE_STRUCT *initData);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxStandbySet                      (BYTE deviceIndex, BYTE rfTxIdx, BOOLEAN isStandby);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxPowerDown                       (BYTE deviceIndex, BYTE rfTxIdx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxAdpdEnable                      (BYTE deviceIndex, BYTE rfTxIdx, BOOLEAN isOn);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_TxStatusGet                       (BYTE deviceIndex, BYTE rfTxIdx, BCM_UW_RF_TX_STATUS_STRUCT *txStat);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxStandbySet                      (BYTE deviceIndex, BYTE rfRxIdx, BOOLEAN isStandby);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxPowerDown                       (BYTE deviceIndex, BYTE rfRxIdx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxRslGet                          (BYTE deviceIndex, BYTE rfRxIdx, BCM_UW_RF_RX_RSL_STRUCT *rslData);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxStatusGet                       (BYTE deviceIndex, BYTE rfRxIdx, BCM_UW_RF_RX_STATUS_STRUCT *rxStat);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RxTxLoopbackSet                   (BYTE deviceIndex, BYTE rfRxIdx, BOOLEAN isLoopbackOn);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_LoSharingSet                      (BYTE deviceIndex, BOOLEAN isTx, BYTE rfDevIdxMaster, BYTE rfDevIdxSlave);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_ProgressErrorGet                  (BYTE deviceIndex, BCM_UW_RF_PROGRESS_ERROR_STRUCT *progressErrorData);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_InternalControl                   (BYTE deviceIndex, BYTE rfDevIdx, BOOLEAN isLong, UINT32 opcode, BYTE *txData, BYTE txLength, BYTE *rxData, BYTE *rxLength);

DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RegisterRead                      (BYTE deviceIndex, BYTE rfTxIdx, BCM_UW_RF_CHIP_TYPE_ENUM chipType, UINT16 regAddress, UINT16 *pVal);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_RF_RegisterWrite                     (BYTE deviceIndex, BYTE rfTxIdx, BCM_UW_RF_CHIP_TYPE_ENUM chipType, UINT16 regAddress, UINT16 val);

//----------------------------------------------------
// Flash Handling Functions
//----------------------------------------------------
// general and flash FW images
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashHeaderBurn                      (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_HEADER_STRUCT *header);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashHeaderGet                       (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_HEADER_STRUCT *header);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashInfoGet                         (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FLASH_INFO_STRUCT *pVer);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareErase                   (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareBurn                    (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex, BYTE *buffer, UINT32 length);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFirmwareBurnEnd                 (BYTE deviceIndex, BYTE flashIndex, BCM_UW_FIRMWARE_INDEX_ENUM firmwareIndex);

// FFS functions
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFSFormat                        (BYTE deviceIndex, BYTE flashIndex);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFilePut                         (BYTE deviceIndex, BYTE flashIndex, BYTE *filename, BYTE *buffer, UINT32 length);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileGet                         (BYTE deviceIndex, BYTE flashIndex, BYTE *filename, BYTE *buffer, UINT32 bufLen, UINT32 *retLen);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileDelete                      (BYTE deviceIndex, BYTE flashIndex, BYTE *filename);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileList                        (BYTE deviceIndex, BYTE flashIndex, BYTE *buffer, UINT32 length);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_FlashFileSizeGet                     (BYTE deviceIndex, BYTE flashIndex, BYTE *filename, UINT32 *size);

//----------------------------------------------------
// DSP
//----------------------------------------------------
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspBootLoaderSet                     (BYTE deviceIndex, BYTE *pDspBootLoader, UINT32 lenBytes);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspSubsystemConfigure                (BYTE deviceIndex, BCM_UW_DSP_SUBSYSTEM_CONFIG_STRUCT *pDspSubsystemConfigStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspBlockConfigure                    (BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_DSP_BLOCK_CONFIG_STRUCT *pDspBlockConfigStruct);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspApplicationLoad                   (BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BYTE *pDspApplication, UINT32 lenBytes);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspStart                             (BYTE deviceIndex, BYTE dspStartBitField);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspStop                              (BYTE deviceIndex, BYTE dspStopBitField);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspDebugSet                          (BYTE deviceIndex, UINT32 opcode, BYTE length, BYTE *data);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspDebugGet                          (BYTE deviceIndex, UINT32 opcode, BYTE lengthTx, BYTE *dataTx, BYTE *lengthRx, BYTE *dataRx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMemoryWrite                       (BYTE deviceIndex, BCM_UW_DSP_MEMORY_TYPE_ENUM dspMemory, UINT32 startAddr, UINT32 length, BYTE *data);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMemoryRead                        (BYTE deviceIndex, BCM_UW_DSP_MEMORY_TYPE_ENUM dspMemory, UINT32 startAddr, UINT32 length, BYTE *data);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMailboxMessageReceive             (BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_COM_DSP_HOST_MSG_STRUCT *pMbx);
DLLEXPORT BCM_UW_ERROR_MSG_ENUM BCM_UW_API_DspMailboxMessageSend                (BYTE deviceIndex, BCM_UW_DSP_IDX_ENUM dspIdx, BCM_UW_COM_DSP_HOST_MSG_STRUCT *pMbx);


/////////////////////////////////////////////////////////////////////////////////

    #ifdef __cplusplus
    } //close extern "C"
    #endif

#endif /* _BCM_UW_API_H_ */

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
