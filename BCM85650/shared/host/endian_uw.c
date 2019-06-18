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
* THIS COMPUTER PROGRAM IS PROVIDED “AS IS” WITHOUT ANY WARRANTIES, AND MAXLINEAR, INC.
* EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE WARRANTIES OF
* MERCHANTIBILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NONINFRINGEMENT.
****************************************************************************************
*                                        Copyright (c) 2012, MaxLinear, Inc.
****************************************************************************************/



#define ENDIAN_UW_C

#include "string.h"
#include "endian_uw.h"
#include "utils_uw.h"
#include "bcm_uw_api.h"     //for PM handling


// macros for swap request and response functions.
// used for switching UINT64,UINT32,UINT16 and BYTES var's bytes order.
// the macros also increment the buffer pointer by the number of bytes of the var type
#define BCM_UW_ENDIAN_SWAP_DWORDS(N)              bcmUwEndianSwapDwords(pMsgBuffer, N);  pMsgBuffer += N*sizeof(UINT32);
#define BCM_UW_ENDIAN_SWAP_WORDS(N)               bcmUwEndianSwapWords(pMsgBuffer, N);   pMsgBuffer += N*sizeof(UINT16);
#define BCM_UW_ENDIAN_ALL_DWORDS_FROM_NOW_ON()    bcmUwEndianAllDwordsFromNowOn(pMsgBuffer, pBufferAddressEnd);
#define BCM_UW_ENDIAN_SKIP_BYTES(N)               pMsgBuffer += N;
#define BCM_UW_ENDIAN_ALL_WORDS_FROM_NOW_ON()     bcmUwEndianAllWordsFromNowOn(pMsgBuffer, pBufferAddressEnd);


BOOLEAN gEndianConversion = FALSE;

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianSwapBytes(BYTE *ptr, int offset1, int offset2)
{
    BYTE temp;
    temp = ptr[offset1];
    ptr[offset1] = ptr[offset2];
    ptr[offset2] = temp;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianSwapWordBytes(BYTE *ptr)
{
    bcmUwEndianSwapBytes(ptr, 0, 1);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianSwapDwordBytes(BYTE *ptr)
{
    bcmUwEndianSwapBytes(ptr, 0, 3);
    bcmUwEndianSwapBytes(ptr, 1, 2);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianSwapWords(BYTE* ptr, int numWords)
{
    int ix;

    for (ix=numWords; ix>0; ix--)
    {
        bcmUwEndianSwapWordBytes(ptr);
        ptr+= sizeof(UINT16);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianSwapDwords(BYTE* ptr, int numDwords)
{
    int ix;

    for (ix=numDwords; ix>0; ix--)
    {
        bcmUwEndianSwapDwordBytes(ptr);
        ptr+= sizeof(UINT32);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianAllWordsFromNowOn(BYTE *ptr, BYTE *endPtr)
{
    while (ptr < endPtr) {
        bcmUwEndianSwapWordBytes(ptr);
        ptr += sizeof(UINT16);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void bcmUwEndianAllDwordsFromNowOn(BYTE *ptr, BYTE *endPtr)
{
    while (ptr < endPtr) {
        bcmUwEndianSwapDwordBytes(ptr);
        ptr += sizeof(UINT32);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Configure endian conversion
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianConversionConfigure(BOOLEAN enabled)
{
    gEndianConversion = enabled;
}

///////////////////////////////////////////////////////////////////////////////
// REQUEST swaps
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianRequestParamSwap(BCM_UW_COM_OPCODE_ENUM opcode, BYTE *pMsgBuffer, UINT32 msgBufferLen)
{
    //BYTE *pBufferAddressEnd = pMsgBuffer + msgBufferLen;

    if (gEndianConversion == FALSE)
    {
        return;
    }

    switch (opcode)
    {
    case BCM_UW_COM_DEV_CONFIG_PARAM_MODIFY_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_DEV_CONFIG_STRING_PARAM_MODIFY_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(17);
        break;

    case BCM_UW_COM_LOAD_CONFIG_FILE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ALARM_ENABLE_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(10);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_MAILBOX_MESSAGE_SEND_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_INJECTION_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_AVS_PROCESS_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_EQUALIZER_STATUS_GET0_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_PREDISTORTION_COEFS_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_MODEM_PREDISTORTION_COEFS_EX_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(10);
        break;

    case BCM_UW_COM_MODEM_PREEMPHASIS_COEFS_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(62);
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_EX_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_SOURCE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_PREAMBLE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_TX_IQ_DELAY_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_MODEM_RX_FREQ_OFFSET_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_MODEM_TX_FREQ_OFFSET_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_MODEM_MUTE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_DELAY_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_PROTECTION_RX_FORCE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ACQUIRE_LOCK_CRITERIA_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MIMO_DIVERSITY_MUTE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_REPEATER_BAUD_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_MODEM_TX_OUTPUT_FILTER_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(40);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_ADPD_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ADPD_GEAR_SHIFT_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ADPD_AUTO_MODE_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(10);
        break;

    case BCM_UW_COM_ADPD_SYSTEM_FREEZE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ECHO_CANCELER_DELAY_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_ECHO_CANCELER_CALIB_START_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_LOOPBACK_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        break;

    case BCM_UW_COM_DIG_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(3);
        BCM_UW_ENDIAN_SWAP_WORDS(6);
        break;

    case BCM_UW_COM_DIG_CONFIGURE_EX_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(16);
        break;

    case BCM_UW_COM_DIG_NOTCH_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(8);
        BCM_UW_ENDIAN_SKIP_BYTES(8);
        break;

    case BCM_UW_COM_DIG_PA_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(5);
        break;

    case BCM_UW_COM_BER_ENABLE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ACM_THRESHOLD_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        break;

    case BCM_UW_COM_ACM_THRESHOLD_XPD_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ACM_PROFILE_ENABLE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ACM_ENHANCED_ENGINE_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ACM_GPM_DYNAMIC_ALLOCATION_SET_OPCODE:
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        break;

    case BCM_UW_COM_ACM_TX_POWER_GAIN_UPDATE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_NET_FIXED_LATENCY_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_PLA_ACM_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_PLA_MSE_LIMIT_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_PLA_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_PLA_PEER_DEVICE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_NET_FRAGMENTATION_SIZE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_NET_TXMAC_FIFO_IND_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_NET_8KHZ_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_PPS_CALIB_START_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_PPS_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_PPS_OUTPUT_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ETH_PORT_FW_DOWNLOAD_HDR_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(4);    //manual fix
        BCM_UW_ENDIAN_SKIP_BYTES(2);    //manual fix
        break;

    case BCM_UW_COM_ETH_PORT_FW_DOWNLOAD_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ETH_PORT_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(5);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(6);
        BCM_UW_ENDIAN_SWAP_WORDS(5);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(3);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_ETH_PORT_COUNTERS_CLEAR_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_HC_ENGINE_ENABLE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_HC_TYPE_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_HC_LEARNING_AGEING_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_HC_DB_REFRESH_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_HC_PARSER_TYPE_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(17);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_HC_PARSER_CLASS_ID_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_AUXDAC_WRITE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(11);
        break;

    case BCM_UW_COM_AUXDAC_EXT_WRITE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(9);
        BCM_UW_ENDIAN_SWAP_DWORDS(19);
        break;

    case BCM_UW_COM_NET_ETH_PHY_REG_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_GENERAL_CONTROL_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_REGISTER_WRITE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_RX_NCO_FREQ_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_WB_TX_NCO_FREQ_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_WB_RX_IQ_DELAY_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_WB_TXTX_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        break;

    case BCM_UW_COM_TX_TX_MODE_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_TX_TX_DELAY_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_RX_IQMC_DELAY_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(33);
        break;

    case BCM_UW_COM_TRANSMITTER_MODE_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_WB_RX_SPECTRAL_INVERSION_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_WB_RX_AGC_SETPOINT_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(3);
        break;

    case BCM_UW_COM_WB_RX_AGC_BACKOFF_OFFSET_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        break;

    case BCM_UW_COM_WB_RX_AGC_BACKOFF_COMPENSATION_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_RX_AGC_TABLE_OFFSET_SET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_TX_AGC_CONFIGURE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_TX_AGC_TARGET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_RF_TX_STANDBY_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_TX_ADPD_ENABLE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_RX_STANDBY_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_RX_TX_LOOPBACK_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_LO_SHARING_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_INTERNAL_CONTROL_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        break;

    case BCM_UW_COM_RF_REGISTER_WRITE_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_FLASH_HEADER_BURN_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_INFO_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FW_ERASE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FW_BURN_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FW_BURNEND_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FS_FORMAT_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILE_DELETE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILECHUNK_PUT_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILECHUNK_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILE_LIST_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILE_SIZE_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_BOOT_LOADER_SET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_SUBSYSTEM_PER_DSP_CONFIG_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(45);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_DSP_BLOCK_CONFIG_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_APP_LOAD_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_APP_LOAD_DONE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_START_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_STOP_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_MAILBOX_MESSAGE_RECEIVE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DSP_MAILBOX_MESSAGE_SEND_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_DEV_CONFIG_FILE_LOAD_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_ACM_THRESHOLD_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        break;

    case BCM_UW_COM_ACM_THRESHOLD_XPD_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ETH_PORT_STATUS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ETH_PORT_RX_COUNTERS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ETH_PORT_TX_COUNTERS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_AUXDAC_EXT_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(9);
        BCM_UW_ENDIAN_SWAP_DWORDS(19);
        break;

    case BCM_UW_COM_REGISTER_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_WB_RX_AGC_STATUS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_WB_TX_AGC_STATUS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_ALL_INITIALIZE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_RF_REGISTER_READ_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_FLASH_HEADER_GET_OPCODE_E:
        break;

    case BCM_UW_COM_INTERNAL_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_GENERAL_CONTROL_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_DSP_MEM_RD_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_DSP_MEM_WR_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_DSP_DEBUG_SET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_DSP_DEBUG_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    default:
        //no swapping
        break;
    }
}

///////////////////////////////////////////////////////////////////////////////
// RESPONSE swaps
///////////////////////////////////////////////////////////////////////////////
void bcmUwEndianResponseParamSwap(BCM_UW_COM_OPCODE_ENUM opcode, BYTE *pMsgBuffer, UINT32 msgBufferLen)
{
    BYTE *pBufferAddressEnd = pMsgBuffer + msgBufferLen;
    BYTE ix;

    if (gEndianConversion == FALSE)
    {
        return;
    }

    switch (opcode)
    {
    case BCM_UW_COM_DEV_CONFIG_START_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(15);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_DEV_CONFIG_RESULT_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(15);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_VERSION_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(3);
        break;

    case BCM_UW_COM_ALARM_ENABLE_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(10);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ALARM_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(10);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SWAP_WORDS(6); //manual fix
        break;

    case BCM_UW_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(32);
        break;

    case BCM_UW_COM_PVTMON_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(23);
        break;

    case BCM_UW_COM_AVS_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        break;

    case BCM_UW_COM_AVS_REC_LVM_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(5);
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        BCM_UW_ENDIAN_SKIP_BYTES(5);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(8);
        break;

    case BCM_UW_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(12);
        break;

    case BCM_UW_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(12);
        break;

    case BCM_UW_COM_MODEM_EQUALIZER_STATUS_GET0_OPCODE_E:
        BCM_UW_ENDIAN_ALL_DWORDS_FROM_NOW_ON();
        break;

    case BCM_UW_COM_MODEM_EQUALIZER_STATUS_GET1_OPCODE_E:
        BCM_UW_ENDIAN_ALL_DWORDS_FROM_NOW_ON();
        break;

    case BCM_UW_COM_MODEM_ECHO_CANCELER_EQUALIZER_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_ALL_DWORDS_FROM_NOW_ON();
        break;

    case BCM_UW_COM_MODEM_XPIC_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_MODEM_RS_HIST_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(18);
        break;

    case BCM_UW_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        break;

    case BCM_UW_COM_MODEM_PREDISTORTION_COEFS_EX_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(10);
        break;

    case BCM_UW_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(62);
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_EX_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_DELAY_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_MRC_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(3);
        BCM_UW_ENDIAN_SKIP_BYTES(3);
        BCM_UW_ENDIAN_SWAP_DWORDS(3);
        BCM_UW_ENDIAN_SWAP_WORDS(6);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(128); //manual
        break;

    case BCM_UW_COM_MODEM_MRC_COMBINER_EQU_STATUS_OPCODE_E:
        BCM_UW_ENDIAN_ALL_DWORDS_FROM_NOW_ON();
        break;

    case BCM_UW_COM_MODEM_MIMO_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_DWORDS(5);
        break;

    case BCM_UW_COM_MIMO_DELAY_CALIB_STATUS_GET_OPCODE_E:
        //no swapping
        break;


    case BCM_UW_COM_MRC_DELAY_CALIB_STATUS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_MODEM_TX_OUTPUT_FILTER_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(40);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_ADPD_CALIB_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ADPD_SYSTEM_FREEZE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_ECHO_CANCELER_CALIB_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_BER_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(12);
        break;

    case BCM_UW_COM_ACM_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_ACM_CONFIGURATION_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(32);
        BCM_UW_ENDIAN_SKIP_BYTES(16);
        break;

    case BCM_UW_COM_ACM_PROFILE_MASK_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ACM_ENHANCED_ENGINE_MODE_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_NET_ASYM_DELAY_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        break;

    case BCM_UW_COM_PLA_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(12);
        break;

    case BCM_UW_COM_NET_FRAGMENTATION_COUNTERS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(10);
        break;

    case BCM_UW_COM_NET_MACFIFO_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        break;

    case BCM_UW_COM_HC_STATISTICS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_AUXADC_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(16);
        break;

    case BCM_UW_COM_I2C_TRANSACTION_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_SPI_TRANSACTION_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_WB_RX_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(4);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_WB_TX_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(5);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_TX_TX_CALIB_STATUS_GET_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_WB_RX_IQMC_DELAY_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(33);
        break;

    case BCM_UW_COM_RF_TX_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(7);
        BCM_UW_ENDIAN_SKIP_BYTES(11);
        break;

    case BCM_UW_COM_RF_RX_RSL_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_RF_RX_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(7);
        BCM_UW_ENDIAN_SKIP_BYTES(11);
        break;

    case BCM_UW_COM_RF_PROGRESS_ERROR_GET_OPCODE_E:
        for (ix=0; ix<14; ix++)
        {
            BCM_UW_ENDIAN_SKIP_BYTES(2);
            BCM_UW_ENDIAN_SWAP_WORDS(1);
            BCM_UW_ENDIAN_SWAP_DWORDS(2);
            BCM_UW_ENDIAN_SWAP_WORDS(2);
        }
        BCM_UW_ENDIAN_SKIP_BYTES(17);
        break;

    case BCM_UW_COM_RF_INTERNAL_CONTROL_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_INFO_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        BCM_UW_ENDIAN_SWAP_DWORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_FLASH_FW_ERASE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FW_BURNEND_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_FLASH_FILE_SIZE_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_DEV_CONFIG_FILE_LOAD_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(15);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        break;

    case BCM_UW_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E:
        BCM_UW_ENDIAN_ALL_WORDS_FROM_NOW_ON();
        break;

    case BCM_UW_COM_ACM_THRESHOLD_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        BCM_UW_ENDIAN_SKIP_BYTES(4);
        break;

    case BCM_UW_COM_ACM_THRESHOLD_XPD_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_ETH_PORT_RX_COUNTERS_GET_OPCODE_E:
        for(ix=0; ix < (sizeof(BCM_UW_ETH_PORT_RX_COUNTERS_STRUCT) / (sizeof(UINT32)+sizeof(BYTE))); ix++)
        {
            BCM_UW_ENDIAN_SWAP_DWORDS(1);
            BCM_UW_ENDIAN_SKIP_BYTES(1);
        }
        break;

    case BCM_UW_COM_ETH_PORT_TX_COUNTERS_GET_OPCODE_E:
        for(ix=0; ix < (sizeof(BCM_UW_ETH_PORT_TX_COUNTERS_STRUCT) / (sizeof(UINT32)+sizeof(BYTE))); ix++)
        {
            BCM_UW_ENDIAN_SWAP_DWORDS(1);
            BCM_UW_ENDIAN_SKIP_BYTES(1);
        }
        break;

    case BCM_UW_COM_AUXDAC_EXT_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(9);
        BCM_UW_ENDIAN_SWAP_DWORDS(19);
        break;

    case BCM_UW_COM_NET_ETH_PHY_REG_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_REGISTER_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_WB_RX_AGC_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(7);
        BCM_UW_ENDIAN_SWAP_WORDS(12);
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        BCM_UW_ENDIAN_SWAP_WORDS(10);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_WB_TX_AGC_STATUS_GET_OPCODE_E:
        BCM_UW_ENDIAN_SKIP_BYTES(2);
        BCM_UW_ENDIAN_SWAP_WORDS(9);
        BCM_UW_ENDIAN_SWAP_DWORDS(4);
        BCM_UW_ENDIAN_SWAP_WORDS(2);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_RF_ALL_INITIALIZE_OPCODE_E:
        //no swapping
        break;

    case BCM_UW_COM_RF_REGISTER_READ_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_WORDS(1);
        break;

    case BCM_UW_COM_FLASH_HEADER_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(8);
        BCM_UW_ENDIAN_SKIP_BYTES(1);
        break;

    case BCM_UW_COM_GENERAL_CONTROL_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    case BCM_UW_COM_DSP_DEBUG_GET_OPCODE_E:
        BCM_UW_ENDIAN_SWAP_DWORDS(1);
        break;

    default:
        // no swapping
        break;
    }
}

