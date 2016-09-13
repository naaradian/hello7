#define ENDIAN_C

#include "string.h"
#include "defs610.h"
#include "endian.h"
#include "utils.h"


// macros for swap request and response functions.
// used for switching UINT64,UINT32,UINT16 and BYTES var's bytes order.
// the macros also increment the buffer pointer by the number of bytes of the var type
#define PVG610_SWAP_DWORDS(N)              pvg610SwapDwords(pMsgBuffer, N);  pMsgBuffer += N*sizeof(UINT32);
#define PVG610_SWAP_WORDS(N)               pvg610SwapWords(pMsgBuffer, N);   pMsgBuffer += N*sizeof(UINT16);
#define PVG610_ALL_DWORDS_FROM_NOW_ON()    pvg610AllDwordsFromNowOn(pMsgBuffer, pBufferAddressEnd);
#define PVG610_SKIP_BYTES(N)               pMsgBuffer += N;
#define PVG610_ALL_WORDS_FROM_NOW_ON()     pvg610AllWordsFromNowOn(pMsgBuffer, pBufferAddressEnd);


BOOLEAN gEndianConversion = FALSE;

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610SwapBytes(BYTE *ptr, int offset1, int offset2)
{
    BYTE temp;
    temp = ptr[offset1];
    ptr[offset1] = ptr[offset2];
    ptr[offset2] = temp;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610SwapWordBytes(BYTE *ptr)
{
    pvg610SwapBytes(ptr, 0, 1);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610SwapDwordBytes(BYTE *ptr)
{
    pvg610SwapBytes(ptr, 0, 3);
    pvg610SwapBytes(ptr, 1, 2);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610SwapWords(BYTE* ptr, int numWords)
{
    int ix;

    for (ix=numWords; ix>0; ix--)
    {
        pvg610SwapWordBytes(ptr);
        ptr+= sizeof(UINT16);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610SwapDwords(BYTE* ptr, int numDwords)
{
    int ix;

    for (ix=numDwords; ix>0; ix--)
    {
        pvg610SwapDwordBytes(ptr);
        ptr+= sizeof(UINT32);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610AllWordsFromNowOn(BYTE *ptr, BYTE *endPtr)
{
    while (ptr < endPtr) {
        pvg610SwapWordBytes(ptr);
        ptr += sizeof(UINT16);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610AllDwordsFromNowOn(BYTE *ptr, BYTE *endPtr)
{
    while (ptr < endPtr) {
        pvg610SwapDwordBytes(ptr);
        ptr += sizeof(UINT32);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Configure endian conversion
///////////////////////////////////////////////////////////////////////////////
void pvg610EndianConversionConfigure(BOOLEAN enabled)
{
    gEndianConversion = enabled;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void pvg610RequestParamSwap(PVG610_COM_OPCODE_ENUM opcode, BYTE *pMsgBuffer, UINT32 msgBufferLen)
{
    BYTE *pBufferAddressEnd = pMsgBuffer + msgBufferLen;

    if (gEndianConversion == FALSE)
    {
        return;
    }

    switch (opcode)
    {
    case PVG610_COM_JUMP_TO_FW_MSG_OPCODE_E:
    case PVG610_COM_VERSION_GET_OPCODE_E:
    case PVG610_COM_START_TRANSFERRING_BOOT_FW_OPCODE_E:
    case PVG610_COM_BOOT_FW_DATA_MSG_OPCODE_E:
    case PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E:
    case PVG610_COM_LOAD_CONFIG_FILE_OPCODE_E:
    case PVG610_COM_RUN_CONFIG_FILE_OPCODE_E:
    case PVG610_COM_ALARM_ENABLE_GET_OPCODE_E:
    case PVG610_COM_ALARM_STATUS_GET_OPCODE_E:
    case PVG610_COM_SYS_INFO_PARAMS_GET_OPCODE_E:
    case PVG610_COM_HARD_RESET_OPCODE_E:
    case PVG610_COM_ACQUIRE_START_OPCODE_E:
    case PVG610_COM_ACM_ENGINE_ENABLE_OPCODE_E:
    case PVG610_COM_ACM_SWITCH_OPCODE_E:
    case PVG610_COM_ACM_TDD_SWITCH_OPCODE_E:
    case PVG610_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E:
    case PVG610_COM_DEBUG_PVG610_OPCODE_E:
    case PVG610_COM_SYNC_TX_BYTE_CLK_OPCODE_E:
    case PVG610_COM_MODEM_STATUS_GET_OPCODE_E:
    case PVG610_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E:
    case PVG610_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E:
    case PVG610_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
    case PVG610_COM_MODEM_SLAVE_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
    case PVG610_COM_MODEM_EQUALIZER_STATUS_GET_OPCODE_E:
    case PVG610_COM_MODEM_XPIC_STATUS_GET_OPCODE_E:
    case PVG610_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E:
    case PVG610_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E:
    case PVG610_COM_ACM_COUNTERS_GET_OPCODE_E:
    case PVG610_COM_NET_FIFO_STATUS_GET_OPCODE_E:
    case PVG610_COM_NET_STM1_PM_GET_OPCODE_E:
    case PVG610_COM_NET_ETH_PM_GET_OPCODE_E:
    case PVG610_COM_NET_STM1_ALARM_GET_OPCODE_E:
    case PVG610_COM_NET_E1_STM1_SIGNALS_FORCE_E:
    case PVG610_COM_NET_E1_CABLE_CONFIG_E:
    case PVG610_COM_NET_TRIBUTARY_HIZ_SET_E:
    case PVG610_COM_NET_E1_PRBS_MONITOR_CONNECT_E:
    case PVG610_COM_NET_E1_PRBS_GENERATOR_CONNECT_E:
    case PVG610_COM_NET_STM1_PRBS_MONITOR_CONNECT_E:
    case PVG610_COM_NET_STM1_PRBS_GENERATOR_CONNECT_E:
    case PVG610_COM_NET_PRBS_ERRORS_GET_E:
    case PVG610_COM_NET_ETH_STATUS_GET_OPCODE_E:
    case PVG610_COM_NET_ETH_STATUS_GET_DONE_OPCODE_E:
    case PVG610_COM_NET_ETH_PARAMS_SET_OPCODE_E:
    case PVG610_COM_PROTECTION_TX_MODE_SET_E:
    case PVG610_COM_PROTECTION_RX_MODE_SET_E:
    case PVG610_COM_PROTECTION_RX_FORCE_SET_E:
    case PVG610_COM_PROTECTION_SYS_MODE_SET_E:
    case PVG610_COM_BOOT_HEADER_MSG_OPCODE_E:
    case PVG610_COM_BOOT_DATA_MSG_OPCODE_E:
    case PVG610_COM_BOOT_CHECKSUM_MSG_OPCODE_E:
    case PVG610_GPIO_INT_CONFIG_OPCODE_E:
    case PVG610_COM_NET_GPI_ERRORS_GET_E:
    case PVG610_COM_NET_GPI_PRBS_GENERATOR_COMMAND_E:
    case PVG610_COM_MODEM_XPIC_SLAVE_MUTE_SET_OPCODE_E:
    case PVG610_COM_FLASH_INFO_GET_START_OPCODE_E:
    case PVG610_COM_PROTECTION_STATUS_GET_OPCODE_E:
    case PVG610_COM_ACM_CONFIGURATION_GET_OPCODE_E:
    case PVG610_COM_TX_RX_START_OPCODE_E:
    case PVG610_COM_ACM_IMPROVE_OPCODE_E:
    case PVG610_COM_ACM_PROFILE_MASK_GET_OPCODE_E:
    case PVG610_COM_UNSOLICITED_UART_MSGS_SET_OPCODE_E:
    case PVG610_ETH_PAUSE_SET_OPCODE_E:
        // no swapping
        break;

    case PVG610_COM_REGISTER_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ALARM_ENABLE_SET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_LOOPBACK_SET_OPCODE_E:
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_TRANSMITTER_MODE_SET_OPCODE_E:
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_DWORDS(1);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ACM_PROFILE_ENABLE_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_GENERAL_CONTROL_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_MEMORY_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_MEMORY_SET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_GENERAL_CONTROL_SET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_MAILBOX_MESSAGE_SEND_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_NET_E1_PM_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_NET_E1_ALARM_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_REGISTER_WRITE_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_REGISTER_RANGE_WRITE_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_REGISTER_RANGE_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_MULTIPLE_REGSITERS_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(1);
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_DWORD_FIFO_READ_OPCODE_E:
        PVG610_SWAP_WORDS(2);
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_DWORD_FIFO_WRITE_OPCODE_E:
        PVG610_SWAP_WORDS(2);
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_WORDS(1);
        PVG610_ALL_DWORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_FROM_ROM_WRITE_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(1);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_CONFIG_FILE_FROM_EMBEDDED_GET_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_GPIO_WRITE_OPCODE_E:
        PVG610_SWAP_WORDS(2);
        break;

    case PVG610_GPIO_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_MODEM_PREEMPHASIS_COEFS_SET_OPCODE_E:
        PVG610_SWAP_WORDS(62);
        break;

    case PVG610_COM_IQ_DELAY_SET_OPCODE_E:
        PVG610_SWAP_WORDS(15);
        break;

    case PVG610_COM_ACM_THRESHOLD_SET_E:
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ACM_THRESHOLD_GET_E:
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ACM_GPM_DYNAMIC_ALLOCATION_SET_OPCODE:
        PVG610_SWAP_DWORDS(4);
        break;

    case PVG610_COM_MODEM_RX_FREQ_OFFSET_SET_OPCODE_E:
    case PVG610_COM_MODEM_TX_FREQ_OFFSET_SET_OPCODE_E:
         PVG610_SWAP_DWORDS(1);
         break;

    case PVG610_COM_MODEM_PREDISTORTION_COEFS_SET_OPCODE_E:
        PVG610_SWAP_WORDS(4);
        PVG610_SWAP_DWORDS(2);
        break;

    case PVG610_COM_MODEM_IQ_IMBALANCE_TXTX_SET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_FLASH_FW_BURN_START_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    default:
        break;
    }
}


///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610ResponseParamSwap(PVG610_COM_OPCODE_ENUM opcode, BYTE *pMsgBuffer, UINT32 msgBufferLen)
{
    BYTE *pBufferAddressEnd = pMsgBuffer + msgBufferLen;

    if (gEndianConversion == FALSE)
    {
        return;
    }

    switch (opcode)
    {
    case PVG610_COM_JUMP_TO_FW_MSG_OPCODE_E:
    case PVG610_COM_BOOT_HEADER_MSG_OPCODE_E:
    case PVG610_COM_BOOT_DATA_MSG_OPCODE_E:
    case PVG610_COM_BOOT_CHECKSUM_MSG_OPCODE_E:
    case PVG610_COM_VERSION_GET_OPCODE_E:
    case PVG610_COM_START_TRANSFERRING_BOOT_FW_OPCODE_E:
    case PVG610_COM_BOOT_FW_DATA_MSG_OPCODE_E:
    case PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E:
    case PVG610_COM_LOAD_CONFIG_FILE_OPCODE_E:
    case PVG610_COM_RUN_CONFIG_FILE_OPCODE_E:
    case PVG610_COM_ALARM_ENABLE_SET_OPCODE_E:
    case PVG610_COM_HARD_RESET_OPCODE_E:
    case PVG610_COM_LOOPBACK_SET_OPCODE_E:
    case PVG610_COM_TRANSMITTER_MODE_SET_OPCODE_E:
    case PVG610_COM_ACQUIRE_START_OPCODE_E:
    case PVG610_COM_ACM_ENGINE_ENABLE_OPCODE_E:
    case PVG610_COM_ACM_TDD_SWITCH_OPCODE_E:
    case PVG610_COM_ACM_THRESHOLD_SET_E:
    case PVG610_COM_ACM_PROFILE_ENABLE_OPCODE_E:
    case PVG610_COM_ACM_SWITCH_OPCODE_E:
    case PVG610_COM_ACM_GPM_DYNAMIC_ALLOCATION_SET_OPCODE:
    case PVG610_COM_GENERAL_CONTROL_SET_OPCODE_E:
    case PVG610_COM_MAILBOX_MESSAGE_SEND_OPCODE_E:
    case PVG610_COM_DEBUG_PVG610_OPCODE_E:
    case PVG610_COM_SYNC_TX_BYTE_CLK_OPCODE_E:
    case PVG610_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E:
    case PVG610_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E:
    case PVG610_COM_MODEM_IQ_IMBALANCE_TXTX_SET_OPCODE_E:
    case PVG610_COM_PROTECTION_STATUS_GET_OPCODE_E:
    case PVG610_COM_REGISTER_WRITE_OPCODE_E:
    case PVG610_COM_REGISTER_RANGE_WRITE_OPCODE_E:
    case PVG610_COM_DWORD_FIFO_WRITE_OPCODE_E:
    case PVG610_COM_FROM_ROM_WRITE_OPCODE_E:
    case PVG610_COM_CONFIG_FILE_FROM_EMBEDDED_GET_OPCODE_E:
    case PVG610_COM_NET_E1_STM1_SIGNALS_FORCE_E:
    case PVG610_COM_NET_E1_CABLE_CONFIG_E:
    case PVG610_COM_NET_TRIBUTARY_HIZ_SET_E:
    case PVG610_COM_NET_E1_PRBS_MONITOR_CONNECT_E:
    case PVG610_COM_NET_E1_PRBS_GENERATOR_CONNECT_E:
    case PVG610_COM_NET_STM1_PRBS_MONITOR_CONNECT_E:
    case PVG610_COM_NET_STM1_PRBS_GENERATOR_CONNECT_E:
    case PVG610_COM_NET_ETH_STATUS_GET_OPCODE_E:
    case PVG610_COM_NET_ETH_STATUS_GET_DONE_OPCODE_E:
    case PVG610_COM_NET_ETH_PARAMS_SET_OPCODE_E:
    case PVG610_COM_PROTECTION_TX_MODE_SET_E:
    case PVG610_COM_PROTECTION_RX_MODE_SET_E:
    case PVG610_COM_PROTECTION_RX_FORCE_SET_E:
    case PVG610_COM_PROTECTION_SYS_MODE_SET_E:
    case PVG610_GPIO_INT_CONFIG_OPCODE_E:
    case PVG610_GPIO_WRITE_OPCODE_E:
    case PVG610_COM_NET_GPI_PRBS_GENERATOR_COMMAND_E:
    case PVG610_COM_IQ_DELAY_SET_OPCODE_E:
    case PVG610_COM_MODEM_RX_FREQ_OFFSET_SET_OPCODE_E:
    case PVG610_COM_MODEM_TX_FREQ_OFFSET_SET_OPCODE_E:
    case PVG610_COM_MODEM_XPIC_SLAVE_MUTE_SET_OPCODE_E:
    case PVG610_COM_MODEM_PREDISTORTION_COEFS_SET_OPCODE_E:
    case PVG610_COM_FLASH_FW_BURN_START_OPCODE_E:
    case PVG610_COM_TX_RX_START_OPCODE_E:
    case PVG610_COM_ACM_IMPROVE_OPCODE_E:
    case PVG610_COM_UNSOLICITED_UART_MSGS_SET_OPCODE_E:
        // no swapping
        break;

    case PVG610_COM_ACM_PROFILE_MASK_GET_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_NET_PRBS_ERRORS_GET_E:
        PVG610_SWAP_WORDS(2);
        PVG610_SWAP_DWORDS(2);
        break;

    case PVG610_COM_NET_GPI_ERRORS_GET_E:
        PVG610_SWAP_DWORDS(2);
        break;

    case PVG610_COM_ACM_CONFIGURATION_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(32); //16 x UINT32(field 1) + 16 x UINT32(field 2)    =   32 x UINT32()total DWORDS 
        break;

    case PVG610_COM_REGISTER_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ALARM_ENABLE_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_ALARM_STATUS_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_SYS_INFO_PARAMS_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(3);
        break;

    case PVG610_COM_MODEM_STATUS_GET_OPCODE_E:
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(5);
        PVG610_SWAP_DWORDS(4);
        break;

    case PVG610_COM_GENERAL_CONTROL_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(1);
        break;

    case PVG610_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E:
        PVG610_ALL_DWORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(4);
        PVG610_SWAP_WORDS(1);
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_DWORDS(2);
        break;

    case PVG610_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_MODEM_SLAVE_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_MODEM_EQUALIZER_STATUS_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_MODEM_XPIC_STATUS_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(2);
        PVG610_SWAP_WORDS(2);
        break;

    case PVG610_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E:
        PVG610_SWAP_WORDS(4);
        PVG610_SWAP_DWORDS(2);
        break;

    case PVG610_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E:
        PVG610_SWAP_WORDS(62);
        break;

    case PVG610_COM_ACM_COUNTERS_GET_OPCODE_E:
        PVG610_SWAP_WORDS(2);
        break;

    case PVG610_COM_NET_FIFO_STATUS_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_NET_E1_PM_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_NET_STM1_PM_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_NET_ETH_PM_GET_OPCODE_E:
        PVG610_SWAP_DWORDS(40);
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_NET_E1_ALARM_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_NET_STM1_ALARM_GET_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_REGISTER_RANGE_READ_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_MULTIPLE_REGSITERS_READ_OPCODE_E:
        PVG610_ALL_WORDS_FROM_NOW_ON();
        break;

    case PVG610_COM_DWORD_FIFO_READ_OPCODE_E:
        PVG610_ALL_DWORDS_FROM_NOW_ON();
        break;

    case PVG610_GPIO_READ_OPCODE_E:
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_FLASH_INFO_GET_START_OPCODE_E:
        PVG610_SKIP_BYTES(4);
        PVG610_SWAP_DWORDS(2);
        PVG610_SWAP_WORDS(1);
        break;

    case PVG610_COM_ACM_THRESHOLD_GET_E:
        PVG610_SKIP_BYTES(2);
        PVG610_SWAP_WORDS(1);
        break;

    default:
        break;

    }
}
