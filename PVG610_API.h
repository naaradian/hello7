#ifndef _PVG610_API_H_
#define _PVG610_API_H_

#ifdef __cplusplus
extern "C" {
#endif
               
#ifdef HOSTDRIVER_EXPORTS
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT
#endif


#include "defs610.h"
#include "hostProtocolStructs.h"


//----------------------------------------------------
// ENUMS
//----------------------------------------------------


/*
typedef enum
{
    // success
    PVG610_SUCCESS_MSG_E,

    // boot errors
    PVG610_BOOT_DATA_TOO_BIG_E,
    PVG610_BOOT_DATA_TOO_SMALL_E,
    PVG610_BOOT_DATA_WRONG_INDEX_E,
    PVG610_BOOT_INVALID_CHECKSUM_E,
    PVG610_BOOT_INVALID_JUMP_ADDRESS_E,
    PVG610_BOOT_OPCODE_UNEXPECTED_E,
    PVG610_BOOT_FW_NOT_ALIVE_E,
    PVG610_FW_NOT_ALIVE_E,

    //================================================

    // general errors
    PVG610_INVALID_MSG_RX_E,
    PVG610_INVALID_MSG_OPCODE_E,
    PVG610_ERROR_IN_COM_RECEIVE_E,
    PVG610_INVALID_MODEM_INDEX_E,
    PVG610_ERROR_NOT_CONFIGURED_E,
    PVG610_INVALID_INTERFACE_E,
    PVG610_MEDIA_NOT_INITIALIZED_E,
    PVG610_INVALID_MEDIA_E,
    PVG610_INVALID_DEVICE_INDEX_E,
    PVG610_HOST_MAILBOX_EMPTY_E,
    PVG610_HOST_MAILBOX_FULL_E,
    PVG610_ERROR_IN_SWITCH_E,
    PVG610_ERROR_ACM_ENGINE_ENABLED_E,
    PVG610_PRBS_ALREADY_CONNECTED_E,
    PVG610_INVALID_PARAMS_E,
    PVG610_ERROR_APLL_ALREADY_CONFIGURED_E,
    PVG610_ERROR_GPI_PBRS_NOT_READY_E,
    PVG610_ERROR_GPI_PBRS_BYPASS_E,
    PVG610_PERIPHERAL_NOT_READY_E,

    // flash errors
    PVG610_FLASH_TIMEOUT_E,
    PVG610_ERROR_IN_FLASH_OPERATION_E,


    // config file errors
    PVG610_ERROR_CFG_FILE_LEN_TOO_BIG_E,
    PVG610_ERROR_CFG_FILE_LEN_TOO_SMALL_E,
    PVG610_ERROR_CFG_FILE_CRC_E,
    PVG610_ERROR_CFG_FILE_UNKNOWN_RECORD_TYPE_E,
    PVG610_ERROR_CFG_FILE_VERSION_E,
    PVG610_ERROR_CFG_FILE_MODEM_TYPE_E,

    // iq Samples get errror
    PVG610_IQ_SAMPLES_GET_ERROR_E,

    // loopback errors
    PVG610_LOOPBACK_INVALID_REQUEST_E,

    // peripherals error
    PVG610_PERIPHERAL_TOO_MANY_BYTES_E,
    PVG610_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E,
    PVG610_PERIPHERAL_I2C_ERROR_E,
    PVG610_PERIPHERAL_I2C_SHARING_ERROR_E,
    PVG610_PERIPHERAL_TIMEOUT_E,
    PVG610_PERIPHERAL_INVALID_SLAVE_ADDRESS_E,

    //ethernet error
    PVG610_ETHERNET_TIMEOUT_E,
    PVG610_ETHERNET_NOT_CONFIGURED_E,

    //reset block errors
    PVG610_BLOCK_RESET_WRONG_VALUE_E,

    //acm up request
    PVG610_ACM_IMPROVE_REQUEST_EXPIRED_E,

    //predistortion saturation  
    PVG610_PREDISTORTION_REACHED_SATURATION_E,

    //test bus busy
    PVG610_TEST_BUS_BUSY_E,

    PVG610_ACM_ENGINE_NOT_ALLOWED_UNDER_PROTECTION_E,

} PVG610_ERROR_MSG_ENUM;
*/

//__________________________________________________________

#define    PVG610_SUCCESS_MSG_E (0)

    // boot errors
#define    PVG610_BOOT_DATA_TOO_BIG_E (1)
#define    PVG610_BOOT_DATA_TOO_SMALL_E (2)
#define    PVG610_BOOT_DATA_WRONG_INDEX_E (3)
#define    PVG610_BOOT_INVALID_CHECKSUM_E (4)
#define    PVG610_BOOT_INVALID_JUMP_ADDRESS_E (5)
#define    PVG610_BOOT_OPCODE_UNEXPECTED_E (6)
#define    PVG610_BOOT_FW_NOT_ALIVE_E (7)
#define    PVG610_FW_NOT_ALIVE_E (8)

    //================================================

    // general errors
#define    PVG610_INVALID_MSG_RX_E (9)
#define    PVG610_INVALID_MSG_OPCODE_E (10)
#define    PVG610_ERROR_IN_COM_RECEIVE_E (11)
#define    PVG610_INVALID_MODEM_INDEX_E (12)
#define    PVG610_ERROR_NOT_CONFIGURED_E (13)
#define    PVG610_INVALID_INTERFACE_E (14)
#define    PVG610_MEDIA_NOT_INITIALIZED_E (15)
#define    PVG610_INVALID_MEDIA_E (16)
#define    PVG610_INVALID_DEVICE_INDEX_E (17)
#define    PVG610_HOST_MAILBOX_EMPTY_E (18)
#define    PVG610_HOST_MAILBOX_FULL_E (19)
#define    PVG610_ERROR_IN_SWITCH_E (20)
#define    PVG610_ERROR_ACM_ENGINE_ENABLED_E (21)
#define    PVG610_PRBS_ALREADY_CONNECTED_E (22)
#define    PVG610_INVALID_PARAMS_E (23)
#define    PVG610_ERROR_APLL_ALREADY_CONFIGURED_E (24)
#define    PVG610_ERROR_GPI_PBRS_NOT_READY_E (25)
#define    PVG610_ERROR_GPI_PBRS_BYPASS_E (26)
#define    PVG610_PERIPHERAL_NOT_READY_E (27)

    // flash errors
#define    PVG610_FLASH_TIMEOUT_E (28)
#define    PVG610_ERROR_IN_FLASH_OPERATION_E (29)


    // config file errors
#define    PVG610_ERROR_CFG_FILE_LEN_TOO_BIG_E (30)
#define    PVG610_ERROR_CFG_FILE_LEN_TOO_SMALL_E (31)
#define    PVG610_ERROR_CFG_FILE_CRC_E (32)
#define    PVG610_ERROR_CFG_FILE_UNKNOWN_RECORD_TYPE_E (33)
#define    PVG610_ERROR_CFG_FILE_VERSION_E (34)
#define    PVG610_ERROR_CFG_FILE_MODEM_TYPE_E (35)

    // iq Samples get errror
#define    PVG610_IQ_SAMPLES_GET_ERROR_E (36)

    // loopback errors
#define    PVG610_LOOPBACK_INVALID_REQUEST_E (37)

    // peripherals error
#define    PVG610_PERIPHERAL_TOO_MANY_BYTES_E (38)
#define    PVG610_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E (39)
#define    PVG610_PERIPHERAL_I2C_ERROR_E (40)
#define    PVG610_PERIPHERAL_I2C_SHARING_ERROR_E (41)
#define    PVG610_PERIPHERAL_TIMEOUT_E (42)
#define    PVG610_PERIPHERAL_INVALID_SLAVE_ADDRESS_E (43)

    //ethernet error
#define    PVG610_ETHERNET_TIMEOUT_E (44)
#define    PVG610_ETHERNET_NOT_CONFIGURED_E (45)

    //reset block errors
#define    PVG610_BLOCK_RESET_WRONG_VALUE_E (46)

    //acm up request
#define    PVG610_ACM_IMPROVE_REQUEST_EXPIRED_E (47)

    //predistortion saturation  
#define    PVG610_PREDISTORTION_REACHED_SATURATION_E (48)

    //test bus busy
#define    PVG610_TEST_BUS_BUSY_E (49)

#define    PVG610_ACM_ENGINE_NOT_ALLOWED_UNDER_PROTECTION_E (50)

    //GPM Dynamic Allocation Errors
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_ETH_SERVICE_NOT_APPLICABLE_E (51)
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_GPI_SERVICE_NOT_APPLICABLE_E (52)
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_PDH_SERVICES_NOT_APPLICABLE_E (53)
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_BANDWITH_NOT_APPLICABLE_E (54)
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_BANDWITH_LEFTOVERS_TOO_HIGH_E (55)
#define     PVG610_ACM_GPM_DYNAMIC_ALLOCATION_FAILED_INVALID_PDH_PORTS_E (56)


#define PVG610_ERROR_MSG_ENUM BYTE




//__________________________________________________________


/*

typedef enum
{
    PVG610_COM_MEDIA_NULL_E,
    PVG610_COM_MEDIA_UART_E,
    PVG610_COM_MEDIA_SPI_E,
    PVG610_COM_MEDIA_DPRAM_E,

    PVG610_COM_MEDIA_MAX_E = PVG610_COM_MEDIA_DPRAM_E
} PVG610_COM_MEDIA_ENUM;

*/

#define    PVG610_COM_MEDIA_NULL_E (0)
#define    PVG610_COM_MEDIA_UART_E (1)
#define    PVG610_COM_MEDIA_SPI_E  (2)
#define    PVG610_COM_MEDIA_DPRAM_E (3)

#define    PVG610_COM_MEDIA_MAX_E (3)

#define    PVG610_COM_MEDIA_ENUM BYTE



/*
typedef enum
{
    PVG610_FIRMWARE_INDEX_1_E,
    PVG610_FIRMWARE_INDEX_2_E
} PVG610_FIRMWARE_INDEX_ENUM;

*/

#define    PVG610_FIRMWARE_INDEX_1_E (0)
#define    PVG610_FIRMWARE_INDEX_2_E (1)
#define    PVG610_FIRMWARE_INDEX_ENUM BYTE

/*
typedef enum
{
    PVG610_ACQUIRE_IN_PROGRESS_E,
    PVG610_ACQUIRE_LOCKED_E,
    PVG610_ACQUIRE_FAILED_E
} PVG610_ACQUIRE_STATUS_ENUM;
 */

#define     PVG610_ACQUIRE_IN_PROGRESS_E (0)
#define     PVG610_ACQUIRE_LOCKED_E      (1)
#define     PVG610_ACQUIRE_FAILED_E	     (2)

#define     PVG610_ACQUIRE_STATUS_ENUM BYTE


/*

typedef enum
{
    PVG610_ACQUIRE_SUCCESS_E        = 0,
    PVG610_ACQUIRE_ERR_AGC_E        = 1,    // acquisition failed at AGC
    PVG610_ACQUIRE_ERR_TIMING_E     = 2,    // acquisition failed at timing
    PVG610_ACQUIRE_ERR_FREQ_SWEEP_E = 3,    // acquisition failed at frequency sweep
    PVG610_ACQUIRE_ERR_MSE_E        = 4,
    PVG610_ACQUIRE_ERR_BIT_E        = 5,
    PVG610_ACQUIRE_ERR_SERVICE_E    = 6,
    PVG610_ACQUIRE_ERR_BLIND_E      = 7,    // acquisition failed at BLIND
    PVG610_ACQUIRE_ERR_TIMEOUT_E    = 10,   // acquisition failed on timeout
    PVG610_ACQUIRE_ERR_STOPPED_E    = 11,
    PVG610_ACQUIRE_ERR_FATAL_E      = 12
} PVG610_ACQUIRE_ERR_ENUM;

*/

#define    PVG610_ACQUIRE_SUCCESS_E        (0)
#define    PVG610_ACQUIRE_ERR_AGC_E        (1)    // acquisition failed at AGC
#define    PVG610_ACQUIRE_ERR_TIMING_E     (2)    // acquisition failed at timing
#define    PVG610_ACQUIRE_ERR_FREQ_SWEEP_E (3)    // acquisition failed at frequency sweep
#define    PVG610_ACQUIRE_ERR_MSE_E        (4)
#define    PVG610_ACQUIRE_ERR_BIT_E        (5)
#define    PVG610_ACQUIRE_ERR_SERVICE_E    (6)
#define    PVG610_ACQUIRE_ERR_BLIND_E      (7)    // acquisition failed at BLIND
#define    PVG610_ACQUIRE_ERR_TIMEOUT_E    (10)   // acquisition failed on timeout
#define    PVG610_ACQUIRE_ERR_STOPPED_E    (11)
#define    PVG610_ACQUIRE_ERR_FATAL_E      (12)
#define    PVG610_ACQUIRE_ERR_FREQ_SWEEP_SLAVE_E (13)


#define    PVG610_ACQUIRE_ERR_ENUM BYTE


/*
typedef enum
{
    PVG610_ACQUIRE_MODE_PREVIOUS_E,
    PVG610_ACQUIRE_MODE_AUTO_E,
    PVG610_ACQUIRE_MODE_MANUAL_E
} PVG610_ACQUIRE_MODE_ENUM;
*/

#define    PVG610_ACQUIRE_MODE_PREVIOUS_E (0)
#define    PVG610_ACQUIRE_MODE_AUTO_E 	  (1)
#define    PVG610_ACQUIRE_MODE_MANUAL_E	  (2)

#define    PVG610_ACQUIRE_MODE_ENUM BYTE




/*
typedef enum
{
    PVG610_SPECTRAL_INVERSION_MODE_PREVIOUS_E,
    PVG610_SPECTRAL_INVERSION_MODE_NEVER_E,
    PVG610_SPECTRAL_INVERSION_MODE_ALWAYS_E,
    PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E
} PVG610_SPECTRAL_INVERSION_MODE_ENUM;
*/

#define    PVG610_SPECTRAL_INVERSION_MODE_PREVIOUS_E    (0)
#define    PVG610_SPECTRAL_INVERSION_MODE_NEVER_E       (1)
#define    PVG610_SPECTRAL_INVERSION_MODE_ALWAYS_E 		(2)
#define    PVG610_SPECTRAL_INVERSION_MODE_SMART_AUTO_E  (3)

#define    PVG610_SPECTRAL_INVERSION_MODE_ENUM BYTE




/*
typedef enum {
    PVG610_LOOPBACK_NONE_E,        // return to normal operation
    PVG610_LOOPBACK_INTERFACE_E,
    PVG610_LOOPBACK_MODEM_E
} PVG610_LOOPBACK_TYPE_ENUM;
*/

#define    PVG610_LOOPBACK_NONE_E 		(0)        // return to normal operation
#define    PVG610_LOOPBACK_INTERFACE_E 	(1)
#define    PVG610_LOOPBACK_MODEM_E 		(2)

#define PVG610_LOOPBACK_TYPE_ENUM BYTE




/*
typedef enum {
    PVG610_TRANSMITTER_MODE_NORMAL_E,
    PVG610_TRANSMITTER_MODE_ONETONE_E,
    PVG610_TRANSMITTER_MODE_TWOTONE_E,
    PVG610_TRANSMITTER_MODE_TONE_SWEEP_E,
    PVG610_TRANSMITTER_MODE_WHITE_NOISE_E,
    PVG610_TRANSMITTER_MODE_MUTE_E,
    PVG610_TRANSMITTER_MODE_PRBS_E
} PVG610_TRANSMITTER_MODE_ENUM;
*/

#define    PVG610_TRANSMITTER_MODE_NORMAL_E (0)
#define    PVG610_TRANSMITTER_MODE_ONETONE_E (1)
#define    PVG610_TRANSMITTER_MODE_TWOTONE_E (2)
#define    PVG610_TRANSMITTER_MODE_TONE_SWEEP_E (3)
#define    PVG610_TRANSMITTER_MODE_WHITE_NOISE_E (4)
#define    PVG610_TRANSMITTER_MODE_MUTE_E (5)
#define    PVG610_TRANSMITTER_MODE_PRBS_E (6)
#define    PVG610_TRANSMITTER_MODE_STUB_E (7)


#define PVG610_TRANSMITTER_MODE_ENUM BYTE




/*
typedef enum {
    PVG610_PROTECTION_MODE_NONE_E, // no protection
    PVG610_PROTECTION_MODE_WORKING_E,
    PVG610_PROTECTION_MODE_PROTECTION_E
} PVG610_PROTECTION_MODE_ENUM;
*/

#define     PVG610_PROTECTION_MODE_NONE_E       (0) // no protection
#define     PVG610_PROTECTION_MODE_WORKING_E    (1)
#define     PVG610_PROTECTION_MODE_PROTECTION_E (2)

#define     PVG610_PROTECTION_MODE_ENUM BYTE



/*
typedef enum {
    PVG610_ACM_PROFILE_0_E,
    PVG610_ACM_PROFILE_1_E,
    PVG610_ACM_PROFILE_2_E,
    PVG610_ACM_PROFILE_3_E,
    PVG610_ACM_PROFILE_4_E,
    PVG610_ACM_PROFILE_5_E,
    PVG610_ACM_PROFILE_6_E,
    PVG610_ACM_PROFILE_7_E,
    PVG610_ACM_PROFILE_8_E,
    PVG610_ACM_PROFILE_9_E,
    PVG610_ACM_PROFILE_10_E,
    PVG610_ACM_PROFILE_11_E,
    PVG610_ACM_PROFILE_12_E,
    PVG610_ACM_PROFILE_13_E,
    PVG610_ACM_PROFILE_14_E,
    PVG610_ACM_PROFILE_15_E
} PVG610_ACM_PROFILE_ENUM;
*/

#define    PVG610_ACM_PROFILE_0_E  (0)
#define    PVG610_ACM_PROFILE_1_E  (1)
#define    PVG610_ACM_PROFILE_2_E  (2)
#define    PVG610_ACM_PROFILE_3_E  (3)
#define    PVG610_ACM_PROFILE_4_E  (4)
#define    PVG610_ACM_PROFILE_5_E  (5)
#define    PVG610_ACM_PROFILE_6_E  (6)
#define    PVG610_ACM_PROFILE_7_E  (7)
#define    PVG610_ACM_PROFILE_8_E  (8)
#define    PVG610_ACM_PROFILE_9_E  (9)
#define    PVG610_ACM_PROFILE_10_E (10)
#define    PVG610_ACM_PROFILE_11_E (11)
#define    PVG610_ACM_PROFILE_12_E (12)
#define    PVG610_ACM_PROFILE_13_E (13)
#define    PVG610_ACM_PROFILE_14_E (14)
#define    PVG610_ACM_PROFILE_15_E (15)

#define  PVG610_ACM_PROFILE_ENUM BYTE






/*
typedef enum
{
    PVG610_ACM_IMPROVE_TABLE_E,
    PVG610_ACM_DEGRADE_TABLE_E
} PVG610_ACM_TABLE_ENUM;

*/

#define PVG610_ACM_IMPROVE_TABLE_E (1)
#define PVG610_ACM_DEGRADE_TABLE_E (0)

#define PVG610_ACM_TABLE_ENUM BYTE


/*
typedef enum
{
    PVG610_CRITERIA_NA_E,
    PVG610_CRITERIA_ALL_E,
    PVG610_CRITERIA_ANY_E,
    PVG610_CRITERIA_MSE_ONLY_E,
} PVG610_ACM_CRITERIA_ENUM;
*/

#define    PVG610_CRITERIA_NA_E		     (0)
#define    PVG610_CRITERIA_ALL_E	     (1)
#define    PVG610_CRITERIA_ANY_E		 (2)
#define    PVG610_CRITERIA_MSE_ONLY_E	 (3)

#define    PVG610_ACM_CRITERIA_ENUM BYTE




/*
typedef enum
{
    PVG610_IQ_DELAY_TX_E,
    PVG610_IQ_DELAY_RX_MASTER_E,
    PVG610_IQ_DELAY_RX_SLAVE_E
} PVG610_IQ_DELAY_MODE_ENUM;
*/

#define    PVG610_IQ_DELAY_TX_E 		(0)
#define    PVG610_IQ_DELAY_RX_MASTER_E 	(1)
#define    PVG610_IQ_DELAY_RX_SLAVE_E 	(2)

#define PVG610_IQ_DELAY_MODE_ENUM BYTE

/*
typedef enum {
    PVG610_NET_TRIB_GPI_E,
    PVG610_NET_TRIB_ETH_E,
    PVG610_NET_TRIB_STM1_A_E,
    PVG610_NET_TRIB_STM1_B_E,
    PVG610_NET_TRIB_EOW_E,
    PVG610_NET_TRIB_OMI_E,
    PVG610_NET_TRIB_E1_0_E,
    PVG610_NET_TRIB_E1_1_E,
    PVG610_NET_TRIB_E1_2_E,
    PVG610_NET_TRIB_E1_3_E,
    PVG610_NET_TRIB_E1_4_E,
    PVG610_NET_TRIB_E1_5_E,
    PVG610_NET_TRIB_E1_6_E,
    PVG610_NET_TRIB_E1_7_E,
    PVG610_NET_TRIB_E1_8_E,
    PVG610_NET_TRIB_E1_9_E,
    PVG610_NET_TRIB_E1_10_E,
    PVG610_NET_TRIB_E1_11_E,
    PVG610_NET_TRIB_E1_12_E,
    PVG610_NET_TRIB_E1_13_E,
    PVG610_NET_TRIB_E1_14_E,
    PVG610_NET_TRIB_E1_15_E,
    PVG610_NET_TRIB_E1_16_E,
    PVG610_NET_TRIB_E1_17_E,
    PVG610_NET_TRIB_E1_18_E,
    PVG610_NET_TRIB_E1_19_E,
    PVG610_NET_TRIB_E1_20_E,
    PVG610_NET_TRIB_ALL_E
} PVG610_NET_TRIB_INDEX_ENUM;
*/

#define    PVG610_NET_TRIB_GPI_E (0)
#define    PVG610_NET_TRIB_ETH_E (1)
#define    PVG610_NET_TRIB_STM1_A_E (2)
#define    PVG610_NET_TRIB_STM1_B_E (3)
#define    PVG610_NET_TRIB_EOW_E   (4)
#define    PVG610_NET_TRIB_OMI_E   (5)
#define    PVG610_NET_TRIB_E1_0_E  (6)
#define    PVG610_NET_TRIB_E1_1_E  (7)
#define    PVG610_NET_TRIB_E1_2_E  (8)
#define    PVG610_NET_TRIB_E1_3_E  (9)
#define    PVG610_NET_TRIB_E1_4_E  (10)
#define    PVG610_NET_TRIB_E1_5_E  (11)
#define    PVG610_NET_TRIB_E1_6_E  (12)
#define    PVG610_NET_TRIB_E1_7_E  (13)
#define    PVG610_NET_TRIB_E1_8_E  (14)
#define    PVG610_NET_TRIB_E1_9_E  (15)
#define    PVG610_NET_TRIB_E1_10_E (16)
#define    PVG610_NET_TRIB_E1_11_E (17)
#define    PVG610_NET_TRIB_E1_12_E (18)
#define    PVG610_NET_TRIB_E1_13_E (19)
#define    PVG610_NET_TRIB_E1_14_E (20)
#define    PVG610_NET_TRIB_E1_15_E (21)
#define    PVG610_NET_TRIB_E1_16_E (22)
#define    PVG610_NET_TRIB_E1_17_E (23)
#define    PVG610_NET_TRIB_E1_18_E (24)
#define    PVG610_NET_TRIB_E1_19_E (25)
#define    PVG610_NET_TRIB_E1_20_E (26)
#define    PVG610_NET_TRIB_ALL_E  (27)

#define	   PVG610_NET_TRIB_INDEX_ENUM BYTE




/*
typedef enum {
    PVG610_NET_TEST_SIGNAL_NORMAL_E,
    PVG610_NET_TEST_SIGNAL_AIS_E,
    PVG610_NET_TEST_SIGNAL_RDI_E
} PVG610_NET_TEST_SIGNAL_ENUM;
*/

#define    PVG610_NET_TEST_SIGNAL_NORMAL_E  (0)
#define    PVG610_NET_TEST_SIGNAL_AIS_E 	(1)
#define    PVG610_NET_TEST_SIGNAL_RDI_E		(2)

#define   PVG610_NET_TEST_SIGNAL_ENUM BYTE



/*
typedef enum {
    PVG610_NET_E1_CABLE_CONFIG_E1_75_OHM_E,
    PVG610_NET_E1_CABLE_CONFIG_E1_120_OHM_E,
    PVG610_NET_E1_CABLE_CONFIG_T1_0_TO_133_FEET_E,
    PVG610_NET_E1_CABLE_CONFIG_T1_133_TO_266_FEET_E,
    PVG610_NET_E1_CABLE_CONFIG_T1_266_TO_399_FEET_E,
    PVG610_NET_E1_CABLE_CONFIG_T1_399_TO_533_FEET_E,
    PVG610_NET_E1_CABLE_CONFIG_T1_533_TO_655_FEET_E,
    PVG610_NET_E1_CABLE_CONFIG_J1_E
} PVG610_NET_E1_CABLE_CONFIG_ENUM;
*/

#define     PVG610_NET_E1_CABLE_CONFIG_E1_75_OHM_E	 (0)
#define     PVG610_NET_E1_CABLE_CONFIG_E1_120_OHM_E	  (1)
#define     PVG610_NET_E1_CABLE_CONFIG_T1_0_TO_133_FEET_E (2)
#define     PVG610_NET_E1_CABLE_CONFIG_T1_133_TO_266_FEET_E	 (3)
#define     PVG610_NET_E1_CABLE_CONFIG_T1_266_TO_399_FEET_E	 (4)
#define     PVG610_NET_E1_CABLE_CONFIG_T1_399_TO_533_FEET_E	 (5)
#define     PVG610_NET_E1_CABLE_CONFIG_T1_533_TO_655_FEET_E	(6)
#define     PVG610_NET_E1_CABLE_CONFIG_J1_E	(7)

#define    PVG610_NET_E1_CABLE_CONFIG_ENUM BYTE




/*
typedef enum {
    PVG610_ETH_10_100_MBPS_E,
    PVG610_ETH_1000_MBPS_E,
    PVG610_ETH_NOT_CONFIGURED_E
} PVG610_NET_ETH_INTERFACE_MODE_ENUM;
*/

#define    PVG610_ETH_10_100_MBPS_E (0)
#define    PVG610_ETH_1000_MBPS_E  (1)
#define    PVG610_ETH_NOT_CONFIGURED_E (2)

#define PVG610_NET_ETH_INTERFACE_MODE_ENUM BYTE


/*
typedef enum
{
    PVG610_TEST_BUS_ENMAP_E,
    PVG610_TEST_BUS_PEF_E,
    PVG610_TEST_BUS_SINC_E,
    PVG610_TEST_BUS_ADC_IF_E,
    PVG610_TEST_BUS_AAF_E,
    PVG610_TEST_BUS_RX_INTERP_E,
    PVG610_TEST_BUS_RX_RRC_E,
    PVG610_TEST_BUS_SLICER_INPUT_E,
    PVG610_MAX_TEST_BUS_OPTIONS_E
} PVG610_TEST_BUS_ENUM;

*/

#define   PVG610_TEST_BUS_ENMAP_E (0)
#define    PVG610_TEST_BUS_PEF_E (1)
#define    PVG610_TEST_BUS_SINC_E (2)
#define    PVG610_TEST_BUS_DAC_IF_E (3)
#define    PVG610_TEST_BUS_ADC_IF_E (4)
#define    PVG610_TEST_BUS_AAF_E (5)
#define    PVG610_TEST_BUS_RX_INTERP_E (6)
#define    PVG610_TEST_BUS_RX_RRC_E (7)
#define    PVG610_TEST_BUS_SLICER_INPUT_E (8)
#define    PVG610_MAX_TEST_BUS_OPTIONS_E (9)

#define PVG610_TEST_BUS_ENUM BYTE







// Interrupt type
/*
typedef enum {
    PVG610_GPIO_INT_DISABLE_ALL_E,
    PVG610_GPIO_INT_RISING_EDGE_E,
    PVG610_GPIO_INT_FALLING_EDGE_E,
    PVG610_GPIO_INT_LEVEL_HIGH_E,
    PVG610_GPIO_INT_LEVEL_LOW_E
} PVG610_GPIO_INT_ENUM;
*/

#define    PVG610_GPIO_INT_DISABLE_ALL_E (0)
#define    PVG610_GPIO_INT_RISING_EDGE_E (1)
#define    PVG610_GPIO_INT_FALLING_EDGE_E (2)
#define    PVG610_GPIO_INT_LEVEL_HIGH_E (3)
#define    PVG610_GPIO_INT_LEVEL_LOW_E (4)

#define PVG610_GPIO_INT_ENUM BYTE



/*
typedef enum
{
    PVG610_PHASE_0_POLARITY_0_E,
    PVG610_PHASE_0_POLARITY_1_E,
    PVG610_PHASE_1_POLARITY_0_E,
    PVG610_PHASE_1_POLARITY_1_E
} PVG610_SPI_PHASE_POLARITY_ENUM;
*/

#define    PVG610_PHASE_0_POLARITY_0_E  (0)
#define    PVG610_PHASE_0_POLARITY_1_E	(1)
#define    PVG610_PHASE_1_POLARITY_0_E	(2)
#define    PVG610_PHASE_1_POLARITY_1_E	(3)

#define    PVG610_SPI_PHASE_POLARITY_ENUM BYTE


/*
typedef enum
{
    PVG610_SPI_FREQUENCY_100K_E,
    PVG610_SPI_FREQUENCY_500K_E,
    PVG610_SPI_FREQUENCY_1M_E,
    PVG610_SPI_FREQUENCY_2M_E,
    PVG610_SPI_FREQUENCY_5M_E,
    PVG610_SPI_FREQUENCY_8M_E,
    PVG610_SPI_FREQUENCY_10M_E
} PVG610_SPI_FREQUENCY_ENUM;
*/

#define    PVG610_SPI_FREQUENCY_100K_E (0)
#define    PVG610_SPI_FREQUENCY_500K_E (1)
#define    PVG610_SPI_FREQUENCY_1M_E   (2)
#define    PVG610_SPI_FREQUENCY_2M_E   (3)
#define    PVG610_SPI_FREQUENCY_5M_E   (4)
#define    PVG610_SPI_FREQUENCY_8M_E   (5)
#define    PVG610_SPI_FREQUENCY_10M_E  (6)

#define    PVG610_SPI_FREQUENCY_ENUM BYTE


/*
typedef enum {
    PVG610_SPI_DATA_FRAME_SIZE_4_BITS_E,
    PVG610_SPI_DATA_FRAME_SIZE_5_BITS_E,
    PVG610_SPI_DATA_FRAME_SIZE_6_BITS_E,
    PVG610_SPI_DATA_FRAME_SIZE_7_BITS_E,
    PVG610_SPI_DATA_FRAME_SIZE_8_BITS_E
} PVG610_SPI_DATA_FRAME_SIZE_ENUM;
*/


#define    PVG610_SPI_DATA_FRAME_SIZE_4_BITS_E (0)
#define    PVG610_SPI_DATA_FRAME_SIZE_5_BITS_E (1)
#define    PVG610_SPI_DATA_FRAME_SIZE_6_BITS_E (2)
#define    PVG610_SPI_DATA_FRAME_SIZE_7_BITS_E (3)
#define    PVG610_SPI_DATA_FRAME_SIZE_8_BITS_E (4)

#define PVG610_SPI_DATA_FRAME_SIZE_ENUM BYTE




/*
typedef enum{
    PVG610_I2C_FREQUENCY_100K_E,
    PVG610_I2C_FREQUENCY_400K_E
} PVG610_I2C_FREQUENCY_ENUM;
*/

#define   PVG610_I2C_FREQUENCY_100K_E  (0)
#define   PVG610_I2C_FREQUENCY_400K_E  (1)

#define PVG610_I2C_FREQUENCY_ENUM  BYTE



/*
typedef enum {
    PVG610_CALIB_SUCCESS_E,
    PVG610_CALIB_MISMATCH_E,
    PVG610_CALIB_TIMEOUT_E
} PVG610_CALIB_STATUS_ENUM;
*/

#define    PVG610_CALIB_SUCCESS_E  (0)
#define    PVG610_CALIB_MISMATCH_E (1)
#define    PVG610_CALIB_TIMEOUT_E  (2)

#define PVG610_CALIB_STATUS_ENUM BYTE




//used in the blockReset function
/*
typedef enum
{
    PVG610_BLOCK_LDPC_ENC_E,
    PVG610_BLOCK_LDPC_DEC_E,
    PVG610_BLOCK_BCTX_E,
    PVG610_BLOCK_BCFE_E,
    PVG610_BLOCK_BCBE_E
} PVG610_BLOCK_RESET_ENUM;
*/

#define     PVG610_BLOCK_LDPC_ENC_E (0)
#define     PVG610_BLOCK_LDPC_DEC_E	(1)
#define     PVG610_BLOCK_BCTX_E		(2)
#define     PVG610_BLOCK_BCFE_E		(3)
#define     PVG610_BLOCK_BCBE_E		(4)
#define     PVG610_BLOCK_PRTX_E		(5)


#define     PVG610_BLOCK_RESET_ENUM BYTE




/*
typedef enum { // bit description of alarms (PVG610_ALARMS_STRUCT)
    PVG610_ALARM_MODEM_BIT_E                = 0,
    PVG610_ALARM_MAILBOX_RX_BIT_E           = 1,  
    PVG610_ALARM_PM_ONE_SEC_BIT_E           = 2,
    PVG610_ALARM_FW_RECOVERY_DONE_BIT_E     = 3,
    PVG610_ALARM_SW_BOOT_BIT_E              = 4,
    PVG610_ALARM_GPIO_0_E                   = 5,
    PVG610_ALARM_GPIO_1_E                   = 6,
    PVG610_ALARM_GPIO_2_E                   = 7,
    PVG610_ALARM_GPIO_3_E                   = 8,
    PVG610_ALARM_GPIO_4_E                   = 9,
    PVG610_ALARM_GPIO_5_E                   = 10,
    PVG610_ALARM_GPIO_6_E                   = 11,
    PVG610_ALARM_GPIO_7_E                   = 12,
    PVG610_ALARM_GPIO_8_E                   = 13,
    PVG610_ALARM_GPIO_9_E                   = 14,
    PVG610_ALARM_GPIO_10_E                  = 15,
    PVG610_ALARM_GPIO_11_E                  = 16,
    PVG610_ALARM_GPIO_12_E                  = 17,
    PVG610_ALARM_GPIO_13_E                  = 18,
    PVG610_ALARM_GPIO_14_E                  = 19,
    PVG610_ALARM_GPIO_15_E                  = 20,
    PVG610_ALARM_ACM_IMPROVE_REQUEST_E      = 21,

    // bits 21-31 reserved
} PVG610_ALARM_BITS_ENUM;
*/

#define    PVG610_ALARM_MODEM_BIT_E                 (0)
#define    PVG610_ALARM_MAILBOX_RX_BIT_E            (1)  
#define    PVG610_ALARM_PM_ONE_SEC_BIT_E            (2)
#define    PVG610_ALARM_FW_RECOVERY_DONE_BIT_E      (3)
#define    PVG610_ALARM_SW_BOOT_BIT_E               (4)
#define    PVG610_ALARM_GPIO_0_E                    (5)
#define    PVG610_ALARM_GPIO_1_E                    (6)
#define    PVG610_ALARM_GPIO_2_E                    (7)
#define    PVG610_ALARM_GPIO_3_E                    (8)
#define    PVG610_ALARM_GPIO_4_E                    (9)
#define    PVG610_ALARM_GPIO_5_E                    (10)
#define    PVG610_ALARM_GPIO_6_E                    (11)
#define    PVG610_ALARM_GPIO_7_E                    (12)
#define    PVG610_ALARM_GPIO_8_E                    (13)
#define    PVG610_ALARM_GPIO_9_E                    (14)
#define    PVG610_ALARM_GPIO_10_E                   (15)
#define    PVG610_ALARM_GPIO_11_E                   (16)
#define    PVG610_ALARM_GPIO_12_E                   (17)
#define    PVG610_ALARM_GPIO_13_E                   (18)
#define    PVG610_ALARM_GPIO_14_E                   (19)
#define    PVG610_ALARM_GPIO_15_E                   (20)
#define    PVG610_ALARM_ACM_IMPROVE_REQUEST_E       (21)
#define    PVG610_ALARM_BCTX_COLLISION_DETECTION_E  (22)
#define    PVG610_ALARM_ACM_TX_SWITCH_E             (23)
#define    PVG610_ALARM_ACM_RX_SWITCH_E             (24)
#define    PVG610_ALARM_MODEM_LOL_E                 (25)
#define    PVG610_ALARM_MODEM_LOCKED_E              (26)


    // bits 21-31 reserved
#define PVG610_ALARM_BITS_ENUM;




/*
typedef enum // bit description of netE1Alarms (PVG610_NET_E1_ALARMS_STRUCT)
{
    PVG610_NET_E1_ALARM_LOS_E     = 0,
    PVG610_NET_E1_ALARM_LOF_E     = 1,
    PVG610_NET_E1_ALARM_AIS_E     = 2,
    // bit 3 reserved
    PVG610_NET_E1_ALARM_TS16AIS_E = 4,
    PVG610_NET_E1_ALARM_RAI_E     = 5,
    PVG610_NET_E1_ALARM_RMA_E     = 6,
    PVG610_NET_E1_ALARM_LCMFA_E   = 7,
    PVG610_NET_E1_ALARM_LSMFA_E   = 8
    // bits 9-15 reserved
} PVG610_NET_E1_ALARMS_ENUM;
*/

#define     PVG610_NET_E1_ALARM_LOS_E      (0)
#define     PVG610_NET_E1_ALARM_LOF_E      (1)
#define     PVG610_NET_E1_ALARM_AIS_E      (2)
    // bit 3 reserved
#define     PVG610_NET_E1_ALARM_TS16AIS_E  (4)
#define     PVG610_NET_E1_ALARM_RAI_E      (5)
#define     PVG610_NET_E1_ALARM_RMA_E      (6)
#define     PVG610_NET_E1_ALARM_LCMFA_E    (7)
#define     PVG610_NET_E1_ALARM_LSMFA_E    (8)
    // bits 9-15 reserved
#define  PVG610_NET_E1_ALARMS_ENUM BYTE




/*

typedef enum // bit description of netStm1Alarms (PVG610_NET_STM1_ALARMS_STRUCT)
{
    PVG610_NET_STM1_ALARM_LOS_E = 0,
    PVG610_NET_STM1_ALARM_OOF_E = 1,
    PVG610_NET_STM1_ALARM_LOF_E = 2,
    PVG610_NET_STM1_ALARM_AIS_E = 3,
    PVG610_NET_STM1_ALARM_RDI_E = 4,
    PVG610_NET_STM1_ALARM_TIM_E = 5,
    PVG610_NET_STM1_ALARM_TIU_E = 6,
    PVG610_NET_STM1_ALARM_REI_E = 7
    // bits 8-15 reserved
} PVG610_NET_STM1_ALARMS_ENUM;

*/

#define    PVG610_NET_STM1_ALARM_LOS_E  (0)
#define    PVG610_NET_STM1_ALARM_OOF_E  (1)
#define    PVG610_NET_STM1_ALARM_LOF_E  (2)
#define    PVG610_NET_STM1_ALARM_AIS_E  (3)
#define    PVG610_NET_STM1_ALARM_RDI_E  (4)
#define    PVG610_NET_STM1_ALARM_TIM_E  (5)
#define    PVG610_NET_STM1_ALARM_TIU_E  (6)
#define    PVG610_NET_STM1_ALARM_REI_E  (7)
    // bits 8-15 reserved
#define PVG610_NET_STM1_ALARMS_ENUM BYTE





/*
typedef enum // bit description of netFifoStatus (PVG610_NET_FIFO_STATUS_STRUCT)
{
    PVG610_NET_FIFO_STATUS_EMPTY_E        = 0, 
    PVG610_NET_FIFO_STATUS_FULL_E         = 1, 
    PVG610_NET_FIFO_STATUS_ALMOST_EMPTY_E = 2, 
    PVG610_NET_FIFO_STATUS_ALMOST_FULL_E  = 3, 
    PVG610_NET_FIFO_STATUS_LEVEL_E        = 4  // bits 4-15
} PVG610_NET_FIFO_STATUS_ENUM;
*/

#define    PVG610_NET_FIFO_STATUS_EMPTY_E         (0) 
#define    PVG610_NET_FIFO_STATUS_FULL_E          (1) 
#define    PVG610_NET_FIFO_STATUS_ALMOST_EMPTY_E  (2) 
#define    PVG610_NET_FIFO_STATUS_ALMOST_FULL_E   (3) 
#define    PVG610_NET_FIFO_STATUS_LEVEL_E         (4)  // bits 4-15

#define PVG610_NET_FIFO_STATUS_ENUM BYTE


/*
typedef enum
{
    PVG610_PROTECTION_RX_UNLOCK_E         = 0, 
    PVG610_PROTECTION_RX_LOCK_E           = 1 
}PVG610_PROTECTION_RX_STATE_ENUM;
*/

#define  PVG610_PROTECTION_RX_UNLOCK_E       (0) 
#define  PVG610_PROTECTION_RX_LOCK_E         (1)
 
#define  PVG610_PROTECTION_RX_STATE_ENUM BYTE


/*
typedef enum {
    PVG610_GPI_BER_COMMAND_STOP_E       = 0,
    PVG610_GPI_BER_COMMAND_START_E      = 1,
} PVG610_GPI_BER_COMMAND_ENUM;
*/

#define    PVG610_GPI_BER_COMMAND_STOP_E       (0)
#define    PVG610_GPI_BER_COMMAND_START_E      (1)

#define PVG610_GPI_BER_COMMAND_ENUM BYTE


/*
typedef enum {
    PVG610_RX_TIMING_BIT_E              = 0, // lock/unlock
    PVG610_PREAMBLE_STATE_BIT_E         = 1, // 2 bits: 0 -> unlocked, 1 -> verify, 2 -> locked, 3 -> not active 
    PVG610_LDPC_EN_BIT_E                = 3, // 0 RS , 1 LDPC
    PVG610_SYNC_UNLOCK_BIT_E            = 4, // Sync unlock
    PVG610_LDPC_UNLOCK_BIT_E            = 5, // LDPC unlock
    PVG610_LDPC_UNCOR_BIT_E             = 6, // LDPC uncor
    PVG610_RS_UNCOR_BIT_E               = 7, // RS uncor

} PVG610_DEBUG_INDICATIONS_ENUM;

*/

#define  PVG610_RX_TIMING_BIT_E               (0) // lock/unlock
#define    PVG610_PREAMBLE_STATE_BIT_E        (1) // 2 bits: 0 -> unlocked, 1 -> verify, 2 -> locked, 3 -> not active 
#define    PVG610_LDPC_EN_BIT_E               (3) // 0 RS , 1 LDPC
#define    PVG610_SYNC_UNLOCK_BIT_E           (4) // Sync unlock
#define    PVG610_LDPC_UNLOCK_BIT_E           (5) // LDPC unlock
#define    PVG610_LDPC_UNCOR_BIT_E            (6) // LDPC uncor
#define    PVG610_RS_UNCOR_BIT_E              (7) // RS uncor

#define PVG610_DEBUG_INDICATIONS_ENUM BYTE

/*
typedef enum {
    PVG610_DEVICE_RESET_ALL_E       = 0,
    PVG610_DEVICE_RESET_CPU_E       = 1,
    
} PVG610_DEVICE_RESET_TYPE_ENUM;
*/
#define    PVG610_DEVICE_RESET_ALL_E       (0)
#define    PVG610_DEVICE_RESET_CPU_E       (1)
    
#define PVG610_DEVICE_RESET_TYPE_ENUM BYTE


/*
typedef enum {
    PVG610_MODULATION_QPSK_E      =   0,
    PVG610_MODULATION_8_POINTS_E  =   1,
    PVG610_MODULATION_16_POINTS_E =   2,
    PVG610_MODULATION_32_POINTS_E =   3,
    PVG610_MODULATION_64_QUAM_E   =   4,
    PVG610_MODULATION_128_QUAM_E  =   4,
    PVG610_MODULATION_256_QUAM_E  =   6,

} PVG610_MODULATION_TYPE;
*/

#define    PVG610_MODULATION_QPSK_E         (0)
#define    PVG610_MODULATION_8_POINTS_E     (1)
#define    PVG610_MODULATION_16_POINTS_E    (2)
#define    PVG610_MODULATION_32_POINTS_E    (3)
#define    PVG610_MODULATION_64_QUAM_E      (4)
#define    PVG610_MODULATION_128_QUAM_E     (5)   //???
#define    PVG610_MODULATION_256_QUAM_E     (6)

#define PVG610_MODULATION_TYPE BYTE





//----------------------------------------------------
// STRUCT
//----------------------------------------------------
#ifdef WIN32
    #pragma pack( push, com_structs, 1)
#endif


typedef __PACK_PREFIX__ struct {
    BYTE   phyId;
    BYTE   regAddress;
    UINT16 val;
} __PACK__ PVG610_NET_ETH_PHY_REG_SET_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE   phyId;
    BYTE   regAddress;
} __PACK__ PVG610_NET_ETH_PHY_REG_GET_STRUCT;




typedef __PACK_PREFIX__ struct {
    BOOLEAN                 flashHeaderValid;
    BOOLEAN                 firmware1Valid;
    BOOLEAN                 firmware2Valid;
    BOOLEAN                 configFileValid;
    UINT32                  firmware1ver;
    UINT32                  firmware2ver;
    UINT16                  configFileLength;
} __PACK__ PVG610_FLASH_INFO_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE                majorVersion;
    BYTE                minorVersion;
    BYTE                buildVersion;
    BYTE                reserved[4];
} __PACK__ PVG610_MODEM_VERSION_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE        info[32];
} __PACK__ PVG610_HOST_INFO_STRUCT;

typedef  __PACK_PREFIX__ struct
{
    UINT32 systemClock;
    UINT32 rxSampleClock;
    UINT32 txSampleClock;
    UINT32 ddsSampleClock;
    BYTE   DDS_ExtPllActive;
    UINT32 netTribEnFlags;
} __PACK__ PVG610_MODEM_SYS_INFO_PARAMS_STRUCT;

typedef __PACK_PREFIX__ struct // bit fields described in PVG610_ALARM_BITS_ENUM
{
    UINT32              alarms;
} __PACK__ PVG610_ALARMS_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE                acquireStatus;          // PVG610_ACQUIRE_STATUS_ENUM: locked, failed, in progress
    BYTE                lastAcquireError;       // PVG610_ACQUIRE_ERR_ENUM
    INT16               absoluteMseTenths;      // in 0.1 dB steps
    INT16               normalizedMseTenths;    // in 0.1 dB steps
    INT16               radialMseTenths;        // in 0.1 dB steps
    INT16               internalAgc;            // in dB, normal range [-5 to 40]
    UINT16              externalAgcRegister;    // Directly reflects PVG register
    INT32               carrierOffset;          // in Hz, normal range [-1e6 to 1e6]
    UINT32              rxSymbolRate;           // in Baud, up to 50e6
    UINT32              txSymbolRate;           // in Baud, up to 50e6
    UINT32              ldpcDecoderStress;      // fraction in range [0,1]
    BYTE                txAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
    BYTE                rxAcmProfile;           // see PVG610_ACM_PROFILE_ENUM
    BOOLEAN             acmEngineEnabled;       // enabled/disabled
    BYTE                debugIndications;       // PVG610_DEBUG_INDICATIONS_ENUM
} __PACK__ PVG610_MODEM_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16               acmRxProfilesHistory;
    UINT16               acmTxProfilesHistory;
} __PACK__ PVG610_ACM_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT32               lolTimeMsec;                // cumulative, clear on read
    UINT32               numLolEvents;               // cumulative, clear on read
    UINT32               numAcquireTrials;           // cumulative, clear on read
    UINT32               lastLockTimeSymbols;        // in Usec
    UINT32               lastLockTimeBits;           // in Usec
    UINT32               lastLockTimeService;        // in Usec
    UINT32               lastAcquireTimeUsec;        // in Usec
    UINT32               lastTotalAcquireTimeUsec;   // in Usec
} __PACK__ PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT32  fecBlockCounter;               // cumulative, clear on read
    UINT32  fecUncorrectedBlockCounter;    // cumulative, clear on read
    UINT32  rsByteCounter;                 // cumulative, clear on read
    UINT32  rsErrorByteCounter;            // cumulative, clear on read
    UINT16  ldpcAvgIterations;             // in 1/256 iterations units
    BYTE    viterbiNormalRate;
    BYTE    reserved;
    UINT32  protectionRxBytesFromProtection;
    UINT32  protectionUncorrectedBytes;
 // UINT32 outputUncorrectedBytes; //100902
} __PACK__ PVG610_MODEM_FEC_COUNTERS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16  fffTaps[48];            // real0, imag0, real1, imag1, …, real23, imag23.
    UINT16  dfeTaps[6];             // real0, imag0, real1, imag1, real2, imag2
} __PACK__ PVG610_MODEM_EQU_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    INT32               xpdTenths;                      // estimated in tenths of dB
    INT32               slaveCarrierOffset;             // in Hz, range[-1e6 to 1e6]
    INT16               slaveInternalAgc;               // in dB, normal range [-5 to 40]
    UINT16              slaveExternalAgcRegister;       // directly reflects register
    BYTE                calibStatus;
    BOOLEAN             slaveSweepInProgress;            // PVG610_CALIB_STATUS_ENUM
//    BOOLEAN             isXpdValid;
} __PACK__ PVG610_MODEM_XPIC_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    INT16               g1Re;
    INT16               g1Im;
    INT16               g3Re;
    INT16               g3Im;
    INT32               g5Re;
    INT32               g5Im;
} __PACK__ PVG610_MODEM_PREDISTORTION_STRUCT;

typedef __PACK_PREFIX__ struct {
    INT16           hReCoefs[10];
    INT16           hImCoefs[10];
    INT16           gReCoefs[10];
    INT16           gImCoefs[10];
    INT16           shImCoefs[10];
    INT16           shReCoefs[10];
    INT16           shHOut;
    INT16           shGOut;
} __PACK__ PVG610_MODEM_PREEMPHASIS_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE        loopbackType;       // see PVG610_LOOPBACK_TYPE_ENUM
//port    UINT32      durationMilli;      // 0 = not limited
	BYTE		durationMilli0;	 //port
	BYTE		durationMilli1;	 //port
	BYTE		durationMilli2;	 //port
	BYTE		durationMilli3;	 //port
    BOOLEAN     nearEnd;            // false = far-end
    BYTE        tributary;          // see PVG610_NET_TRIB_INDEX_ENUM. Only relevant when loopbackType is LOOPBACK_TYPE_INTERFACE_E
} __PACK__ PVG610_LOOPBACK_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE        transmitterMode;    // see PVG610_TRANSMITTER_MODE_ENUM
    INT32       toneFreqKhz;        // relevant for one-tone, two-tone and tone-sweep
    UINT16      sweepTimeMilli;     // relevant for tone-sweep only. Steps are in 1 msec units.
} __PACK__ PVG610_TRANSMITTER_MODE_STRUCT;

typedef __PACK_PREFIX__ struct {
    INT16               diffPhaseTenthsDeg;     // in 0.1 deg resolution
    INT16               diffGainTenthsDB;       // in 0.1 dB resolution
    INT16               dcLeakageITenthsPercent;
    INT16               dcLeakageQTenthsPercent;
} __PACK__ PVG610_IQ_IMBALANCE_STRUCT;

typedef __PACK_PREFIX__ struct {
    PVG610_IQ_IMBALANCE_STRUCT    txTx;
    PVG610_IQ_IMBALANCE_STRUCT    rxRx;
    PVG610_IQ_IMBALANCE_STRUCT    rxTx;
} __PACK__ PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16              msgLen;
    BYTE                message[32];
} __PACK__ PVG610_MAILBOX_MESSAGE_STRUCT;

typedef __PACK_PREFIX__ struct { // bit fields described in PVG610_NET_E1_ALARMS_ENUM
    UINT16              netE1Alarms;
} __PACK__ PVG610_NET_E1_ALARMS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16              crcBlockErrors;
    UINT16              excessiveCrcErrors;
    UINT16              framingBitAlignmentErrors;
    UINT16              farEndBlockErrors;
    UINT16              lineCodeViolations;
    PVG610_NET_E1_ALARMS_STRUCT    alarms;     // cumulative over the 1-second period
} __PACK__ PVG610_NET_E1_PM_STRUCT;

typedef __PACK_PREFIX__ struct { // bit fields described in PVG610_NET_STM1_ALARMS_ENUM
    UINT16              netStm1Alarms;
} __PACK__ PVG610_NET_STM1_ALARMS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16              b1Counter;
    UINT16              b2Counter;
    UINT16              reiCounter;
    PVG610_NET_STM1_ALARMS_STRUCT  alarms;     // cumulative over the 1-second period
} __PACK__ PVG610_NET_STM1_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT32              truncatedFrames;
    UINT32              longEvents;
    UINT32              vlanTagsDetected;
    UINT32              unsopprtedOpcodes;
    UINT32              pauseFrames;
    UINT32              controlFrames;
    UINT32              dribbleNibbles;
    UINT32              broadcasts;
    UINT32              multicasts;
    UINT32              dones;
    UINT32              outOfRangeErrors;
    UINT32              lengthCheckErrors;
    UINT32              crcErrors;
    UINT32              codeErrors;
    UINT32              falseCarrierErrors;
    UINT32              rxDvEvent;
    UINT32              previosPacketDropped;
    UINT32              byteCounterLow;
    UINT32              byteCounterHigh;
} __PACK__ PVG610_NET_ETH_RX_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT32              vlanTags;
    UINT32              backpressuresEvents;
    UINT32              pauseFrames;
    UINT32              controlFrames;
    UINT32              wireByteCounterLow;
    UINT32              wireByteCounterHigh;
    UINT32              underruns;
    UINT32              giants;
    UINT32              lateCollisions;
    UINT32              maxCollisions;
    UINT32              excessiveDefers;
    UINT32              nonExcessiveDefers;
    UINT32              broadcasts;
    UINT32              multicasts;
    UINT32              dones;
    UINT32              reserved;
    UINT32              lengthCheckErrors;
    UINT32              crcErrors;
    UINT32              collisions;
    UINT32              byteCounterLow;
    UINT32              byteCounterHigh;
} __PACK__ PVG610_NET_ETH_TX_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16              fcsErrors;
    UINT16              checErrors;
    UINT16              droppedFrames;
    UINT16              frameDelineationLosses;
} __PACK__ PVG610_NET_ETH_GFP_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16              rxQ1Frames;
    UINT16              rxQ1DroppedFrames;
    UINT16              rxQ2Frames;
    UINT16              rxQ2DroppedFrams;
    UINT16              txFrames;
    UINT16              txDroppedFrames;
} __PACK__ PVG610_NET_ETH_QOS_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    PVG610_NET_ETH_RX_PM_STRUCT    rx;
    PVG610_NET_ETH_TX_PM_STRUCT    tx;
    PVG610_NET_ETH_GFP_PM_STRUCT   gfp;
    PVG610_NET_ETH_QOS_PM_STRUCT   qos;
} __PACK__ PVG610_NET_ETH_PM_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE autoNegotiation;
    BYTE speed;
    BYTE duplex;
    BYTE loopback;
    BYTE interfaceMode;
    BYTE phyId;
    BYTE reset;
    BYTE changePhyId;
} __PACK__ PVG610_NET_ETH_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct { // bit fields described in PVG610_NET_FIFO_STATUS_ENUM
    UINT16      netFifoStatus;
} __PACK__ PVG610_NET_FIFO_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    PVG610_NET_FIFO_STATUS_STRUCT   txGpi;
    PVG610_NET_FIFO_STATUS_STRUCT   txStm1[2];
    PVG610_NET_FIFO_STATUS_STRUCT   txE1[21];
    PVG610_NET_FIFO_STATUS_STRUCT   txOmi;
    PVG610_NET_FIFO_STATUS_STRUCT   txEthQ1;
    PVG610_NET_FIFO_STATUS_STRUCT   txEthQ2;
    PVG610_NET_FIFO_STATUS_STRUCT   txEow;

    PVG610_NET_FIFO_STATUS_STRUCT   rxGpi;
    PVG610_NET_FIFO_STATUS_STRUCT   rxStm1[2];
    PVG610_NET_FIFO_STATUS_STRUCT   rxE1[21];
    PVG610_NET_FIFO_STATUS_STRUCT   rxOmi;
    PVG610_NET_FIFO_STATUS_STRUCT   rxEth;

} __PACK__ PVG610_NET_FIFOS_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT16      e1PrbsFromTheAirCounter;
    UINT16      e1PrbsFromTheLineCounter;
    UINT32      stm1PrbsFromTheAirCounter;  // only the 20 lsb bits are relevant. The 12 msb bits are zero.
    UINT32      stm1PrbsFromTheLineCounter;
} __PACK__ PVG610_NET_PRBS_ERRORS_STRUCT;

typedef __PACK_PREFIX__ struct {
    UINT32      gpiTotalBits;
    UINT32      gpiErrorBits;
} __PACK__ PVG610_NET_PRBS_GPI_ERRORS_INFO_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE        protectionRxState;          // PVG610_PROTECTION_RX_STATE_ENUM
    BYTE        rxPhyId;
} __PACK__ PVG610_PROTECTION_STATUS_STRUCT;

typedef __PACK_PREFIX__ struct {           
    UINT32      acmNumOfSymbols[16];
    UINT32      gpiPayloadSizeInBytes[16];
    BYTE        modulation[16];             // PVG610_MODULATION_TYPE
} __PACK__ PVG610_ACM_COFIGURATION_STRUCT;

#ifdef WIN32
    #pragma pack( pop, com_structs )
#endif

// Init functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_Open                     (void);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_Close                    (void);



//----------------------------------------------------
// Communication Control Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ComConfigure             (BYTE deviceIndex, PVG610_COM_MEDIA_ENUM media, UINT32 systemClockInHz);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ComTimeoutSet            (BYTE deviceIndex, UINT32 timeoutInMilli);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ComMessageRelay          (BYTE deviceIndexSrc, BYTE deviceIndexDest);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ComMessageForward        (BYTE deviceIndex, BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen);

//----------------------------------------------------
// Boot, Flash Handling and Firmware Upgrade Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FlashHeaderBurn          (BYTE deviceIndex, BYTE *pBuffer, UINT16 len);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareBurn        (BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex, BYTE *pBuffer, UINT32 len);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareErase       (BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FlashInfoGet             (BYTE deviceIndex, PVG610_FLASH_INFO_STRUCT *pVer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareReload      (BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FirmwareFromHostBoot     (BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_FirmwareFromHostReload   (BYTE deviceIndex, BYTE *pBuffer, UINT32 len);

//----------------------------------------------------
// Configuration File Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromHostLoad   (BYTE deviceIndex, BYTE modemIndex, BYTE *pBuffer, UINT16 len);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromEmbeddedGet(BYTE deviceIndex, BYTE modemIndex, BYTE *pBuffer, UINT16 len, UINT16 *pReadLen);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileToFlashBurn    (BYTE deviceIndex, BYTE modemIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromFlashLoad  (BYTE deviceIndex, BYTE modemIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromFlashErase (BYTE deviceIndex, BYTE modemIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileRun            (BYTE deviceIndex, BYTE modemIndex);

//----------------------------------------------------
// Direct Setup Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRead             (BYTE deviceIndex, BYTE modemIndex, UINT16 offset, BOOLEAN xpicSlave, UINT16 *pVal);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RegisterWrite            (BYTE deviceIndex, BYTE modemIndex, UINT16 offset, BOOLEAN xpicSlave, UINT16 val);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeRead        (BYTE deviceIndex, BYTE modemIndex, UINT16 offset, BOOLEAN xpicSlave, UINT16 len, BOOLEAN increment, UINT16 *pBuffer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeWrite       (BYTE deviceIndex, BYTE modemIndex, UINT16 offset, BOOLEAN xpicSlave, UINT16 len, BOOLEAN increment, UINT16 *pBuffer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_MultipleRegistersRead    (BYTE deviceIndex, BYTE modemIndex, UINT16 *pOffset, BOOLEAN xpicSlave, UINT16 len, UINT16 *pBuffer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeFromRomWrite(BYTE deviceIndex, BYTE modemIndex, UINT16 offset, BOOLEAN xpicSlave, UINT16 len, BOOLEAN increment, BYTE tableIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_DwordFifoRead            (BYTE deviceIndex, BYTE modemIndex, UINT16 offsetLow, UINT16 offsetHigh, BOOLEAN xpicSlave, UINT16 lenInDword, UINT32 *pBuffer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_DwordFifoWrite           (BYTE deviceIndex, BYTE modemIndex, UINT16 offsetLow, UINT16 offsetHigh, BOOLEAN xpicSlave, UINT16 lenInDword, UINT32 *pBuffer);

//----------------------------------------------------
// Status and Performance Monitoring Functions (general)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_VersionGet               (BYTE deviceIndex, /*@out@*/ PVG610_MODEM_VERSION_STRUCT *pVer);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_AlarmEnableSet           (BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsMask);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_AlarmEnableGet           (BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsMask);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_AlarmStatusGet           (BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsStatus);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_HostInfoSet              (BYTE deviceIndex, PVG610_HOST_INFO_STRUCT *pInfo);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_HostInfoGet              (BYTE deviceIndex, PVG610_HOST_INFO_STRUCT *pInfo);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_SysInfoParamsGet         (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_SYS_INFO_PARAMS_STRUCT *pSi);

//----------------------------------------------------
// Status and Performance Monitoring Functions (modem)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGet             (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGetS             (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGetR             (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_AcmCountersGet             (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_COUNTERS_STRUCT *pMc);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcquireCountersGet    (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT *pAc);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemFecCountersGet        (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_FEC_COUNTERS_STRUCT *pFc);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqImbalanceStatusGet  (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT *pIs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemSlaveIqImbalanceStatusGet (BYTE deviceIndex, BYTE modemIndex, PVG610_IQ_IMBALANCE_STRUCT  *rxRx);

DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqImbalanceTxTxSet(BYTE deviceIndex, BYTE modemIndex, INT16 diffPhaseTenthsDeg, INT16 diffGainTenthsDB, INT16 dcLeakageITenthsPercent, INT16 dcLeakageQTenthsPercent);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemEqualizerStatusGet    (BYTE deviceIndex, BYTE modemIndex, BOOLEAN xpicSlave, PVG610_MODEM_EQU_STATUS_STRUCT *pEs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemXpicStatusGet         (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_XPIC_STATUS_STRUCT *pXs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemPredistortionCoefsGet (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREDISTORTION_STRUCT *pPs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemPreemphasisCoefsGet   (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREEMPHASIS_STRUCT *pPs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqSamplesGet          (BYTE deviceIndex, BYTE modemIndex, UINT16 numIqPairs, INT16 *pBuffer, BOOLEAN xpicSlave, PVG610_TEST_BUS_ENUM testBusSel);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionStatusGet        (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_STATUS_STRUCT *pPs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_AcmConfigurationGet        (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_COFIGURATION_STRUCT *pCs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmThresholdGet     (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_TABLE_ENUM engineTable, PVG610_ACM_PROFILE_ENUM profile, INT16 *mseTenthsVal, BYTE *ldpcMantissaTenths, BYTE *ldpcExponent, PVG610_ACM_CRITERIA_ENUM *criteria, PVG610_ACM_PROFILE_ENUM *nextProfile);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmProfileMaskGet     (BYTE deviceIndex, BYTE modemIndex, UINT16 *profilesMask);
//----------------------------------------------------
// 
// Status / Performance Monitoring Functions - networking
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1AlarmsGet             (BYTE deviceIndex, BYTE modemIndex, UINT32 e1IndexMask, PVG610_NET_E1_ALARMS_STRUCT *pStat);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PmGet                 (BYTE deviceIndex, BYTE modemIndex, UINT32 e1IndexMask, PVG610_NET_E1_PM_STRUCT *pPm, UINT16 *pOneSecondPeriodCounter);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1AlarmsGet           (BYTE deviceIndex, BYTE modemIndex, BYTE stm1IndexMask, PVG610_NET_STM1_ALARMS_STRUCT *pStat);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PmGet               (BYTE deviceIndex, BYTE modemIndex, BYTE stm1IndexMask, PVG610_NET_STM1_PM_STRUCT *pPm, UINT16 *pOneSecondPeriodCounter);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPmGet                (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_ETH_PM_STRUCT *pPm, UINT16 *pOneSecondPeriodCounter);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetEthStatusGet            (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_ETH_STATUS_STRUCT *pEs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetFifoStatusGet           (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_FIFOS_STATUS_STRUCT *pFs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_EthernetPauseSet           (BYTE deviceIndex, BYTE modemIndex,BYTE pauseMode);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_EthernetVlanSet			  (BYTE deviceIndex, BYTE modemIndex,BYTE lowPriority);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_EthernetLargeFrameSet      (BYTE deviceIndex, BYTE modemIndex,UINT16 macMaxPkt);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_EthernetInBandControlSet   (BYTE deviceIndex, BYTE modemIndex,BYTE inBandControl);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPhyRegGet            (BYTE deviceIndex, BYTE modemIndex, BYTE phyId, BYTE regAddress, UINT16* val);

//----------------------------------------------------
// Operative Functions (general)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_DeviceReset              (BYTE deviceIndex, PVG610_DEVICE_RESET_TYPE_ENUM resetType);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_BlocksHardReset          (BYTE deviceIndex, BYTE modemIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_BlockReset               (BYTE deviceIndex, BYTE modemIndex, PVG610_BLOCK_RESET_ENUM block);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_LoopbackSet              (BYTE deviceIndex, BYTE modemIndex, PVG610_LOOPBACK_STRUCT *lb);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_LoopbackGet              (BYTE deviceIndex, BYTE modemIndex, PVG610_LOOPBACK_TYPE_ENUM *loopbackValue, BOOLEAN *loopbackNearEnd, UINT32 *tributaryMask);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_TransmitterModeSet       (BYTE deviceIndex, BYTE modemIndex, PVG610_TRANSMITTER_MODE_STRUCT *tx);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_TxRxOperationStart       (BYTE deviceIndex, BYTE modemIndex);

//----------------------------------------------------
// Operative Functions (Modem)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcquireStart        (BYTE deviceIndex, BYTE modemIndex, PVG610_ACQUIRE_MODE_ENUM  acqMode, PVG610_SPECTRAL_INVERSION_MODE_ENUM siMode);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemPreemphasisCoefsSet (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREEMPHASIS_STRUCT *pPs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemPredistortionCoefsSet (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREDISTORTION_STRUCT *pPs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_TxByteClkSync            (BYTE deviceIndex, BYTE modemIndex);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_XpicDelaySet             (BYTE deviceIndex, BYTE modemIndex, BYTE delay);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_XpicSlaveMuteSet         (BYTE deviceIndex, BYTE modemIndex, BOOLEAN mute);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_PreambleSet              (BYTE deviceIndex, BYTE modemIndex, BYTE index);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_IqDelaySet               (BYTE deviceIndex, BYTE modemIndex, PVG610_IQ_DELAY_MODE_ENUM txMode, BYTE fdfTableIndex, INT16 fdfIntDelay);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_UnsolicitedUartMsgsSet   (BYTE deviceIndex, BYTE modemIndex, BYTE eventsMask, BYTE periodicTimerIn50MsecUnits);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_RxFreqOffsetSet          (BYTE deviceIndex, BYTE modemIndex, INT32 offsetInKHz);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_TxFreqOffsetSet          (BYTE deviceIndex, BYTE modemIndex, INT32 offsetInKHz);

//----------------------------------------------------
// Operative Functions (ACM)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmEngineEnable     (BYTE deviceIndex, BYTE modemIndex, BOOLEAN enableRx, BOOLEAN enableTx);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmSwitch           (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_PROFILE_ENUM acmProfile, BOOLEAN isLocal);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmProfileEnable    (BYTE deviceIndex, BYTE modemIndex, UINT16 profilesMask);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemGpmDynamicAllocationSet  (BYTE deviceIndex, BYTE modemIndex, UINT32 profile, UINT32 gpiBwKbps, UINT32 ethBwKbps, UINT32 pdhMask);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmTddSwitch        (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_PROFILE_ENUM localAcmProfile, PVG610_ACM_PROFILE_ENUM remoteAcmProfile);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmThresholdSet     (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_TABLE_ENUM engineTable, PVG610_ACM_PROFILE_ENUM profile, INT16 mseTenthsVal, BYTE ldpcMantissaTenths, BYTE ldpcExponent, PVG610_ACM_CRITERIA_ENUM criteria, PVG610_ACM_PROFILE_ENUM nextProfile);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmImproveIfNeeded  (BYTE deviceIndex, BYTE modemIndex);

//----------------------------------------------------
// Operative Functions (networking)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1Stm1SignalsForce      (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_TRIB_INDEX_ENUM ifIndex, PVG610_NET_TEST_SIGNAL_ENUM signal, BOOLEAN toTheAir);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1CableConfig           (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_TRIB_INDEX_ENUM e1Index, PVG610_NET_E1_CABLE_CONFIG_ENUM cableConfig);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetTributaryHizSet         (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_TRIB_INDEX_ENUM ifIndex, BOOLEAN hiz);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PrbsMonitorConnect    (BYTE deviceIndex, BYTE modemIndex, BOOLEAN connect, PVG610_NET_TRIB_INDEX_ENUM e1Index, BOOLEAN fromTheAir);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PrbsMonitorConnect  (BYTE deviceIndex, BYTE modemIndex, BOOLEAN connect, PVG610_NET_TRIB_INDEX_ENUM stm1Index, BOOLEAN fromTheAir);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PrbsGeneratorConnect  (BYTE deviceIndex, BYTE modemIndex, BOOLEAN connect, PVG610_NET_TRIB_INDEX_ENUM e1Index, BOOLEAN fromTheAir);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PrbsGeneratorConnect(BYTE deviceIndex, BYTE modemIndex, BOOLEAN connect, PVG610_NET_TRIB_INDEX_ENUM stm1Index, BOOLEAN fromTheAir);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetPrbsErrorsGet           (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_PRBS_ERRORS_STRUCT *pPrbs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetGpiErrorsGet            (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_PRBS_GPI_ERRORS_INFO_STRUCT *pGpi);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetGpiPrbsGeneratorCommand (BYTE deviceIndex, BYTE modemIndex, PVG610_GPI_BER_COMMAND_ENUM command);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetEthParamsSet            (BYTE deviceIndex, BYTE modemIndex, PVG610_NET_ETH_STATUS_STRUCT *pEs);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_MailboxMessageSend         (BYTE deviceIndex, BYTE modemIndex, PVG610_MAILBOX_MESSAGE_STRUCT *pMbx);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_MailboxMessageReceive      (BYTE deviceIndex, BYTE modemIndex, PVG610_MAILBOX_MESSAGE_STRUCT *pMbx);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPhyRegSet            (BYTE deviceIndex, BYTE modemIndex, BYTE phyId, BYTE regAddress, UINT16 val);

//----------------------------------------------------
// Operative Functions (protection)
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionTxModeSet        (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_MODE_ENUM protectionMode, BYTE phyId, BOOLEAN copyAcmFormWorking);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionRxModeSet        (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_MODE_ENUM protectionMode, BYTE phyId);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionRxForceSet       (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_MODE_ENUM protectionMode);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionSysModeSet       (BYTE deviceIndex, BYTE modemIndex, BOOLEAN enable);

//----------------------------------------------------
// Peripheral Access Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_I2CTransaction           (BYTE deviceIndex, BYTE slaveAddress, BYTE *txBuffer, BYTE txBufferLen, BYTE *rxBuffer, BYTE rxBufferLen, PVG610_I2C_FREQUENCY_ENUM frequency);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_SPITransaction           (BYTE deviceIndex, BYTE slaveAddress, BYTE *txBuffer, BYTE txBufferLen, BYTE *rxBuffer, BYTE rxBufferLen, PVG610_SPI_DATA_FRAME_SIZE_ENUM dataFrameSize, PVG610_SPI_PHASE_POLARITY_ENUM phasePolarity, PVG610_SPI_FREQUENCY_ENUM frequency);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_GPIOIntConfig            (BYTE deviceIndex, BYTE index, PVG610_GPIO_INT_ENUM intType);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_GPIORead                 (BYTE deviceIndex, UINT16 mask, UINT16 *readData);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_GPIOWrite                (BYTE deviceIndex, UINT16 mask, UINT16 data);

//----------------------------------------------------
// Debug Functions
//----------------------------------------------------
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_GeneralControlSet        (BYTE deviceIndex, BYTE modemIndex, UINT32 opcode, BYTE  length, BYTE *data);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_GeneralControlGet        (BYTE deviceIndex, BYTE modemIndex, UINT32 opcode, BYTE *length, BYTE *data);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_DebugMsgGet              (BYTE deviceIndex, BYTE modemIndex, BYTE *pBuffer, UINT32 *lenBytes);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_MemoryGet                (BYTE deviceIndex, BYTE modemIndex, UINT32 address,UINT32 len, BYTE *data);
DLLEXPORT PVG610_ERROR_MSG_ENUM PVG610_API_MemorySet                (BYTE deviceIndex, BYTE modemIndex, UINT32 address,UINT32 len, BYTE *data, BYTE mode);

/////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* _PVG610_API_H_ */
