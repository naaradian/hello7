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


#ifndef HOST_PROTOCOL_STRUCTS_H
#define HOST_PROTOCOL_STRUCTS_H

#include "utils_uw.h"
#include "bcm_uw_api.h"

//temporary placed here
#define BCM_UW_BOOT_FW_SIZE_BYTES                     (16 * 1024)

#define BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN              256
#define BCM_UW_HOST_PROTOCOL_HEADER_LEN               8
#define BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN          (BCM_UW_HOST_PROTOCOL_MAX_MSG_LEN - BCM_UW_HOST_PROTOCOL_HEADER_LEN - BCM_UW_CHECKSUM_LEN)
#define BCM_UW_HOST_PROTOCOL_PAYLOAD_OFFSET           (BCM_UW_HOST_PROTOCOL_HEADER_LEN)

//max size of the record buffer within the config file
#define BCM_UW_MAX_CONFIG_FILE_LEN                    (100 * 1024)   //config file max size

///////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////
#define BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE        5
#define BCM_UW_COM_GENERAL_RF_CONTROL_HEADER_SIZE     6
#define BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE          5
#define BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE       9
#define BCM_UW_COM_LONG_API_HEADER_SIZE               2
#define BCM_UW_COM_FLASH_CHUNK_HEADER_SIZE            19 

// host protocol header structure
#define BCM_UW_COM_SPARE_INFO_OFFSET                0x0            //not used
#define BCM_UW_COM_SPARE0_INFO_OFFSET               0x1            //..
#define BCM_UW_COM_SPARE1_INFO_OFFSET               0x2            //..
#define BCM_UW_COM_SPARE2_INFO_OFFSET               0x3            //..

#define BCM_UW_COM_OPCODE_OFFSET                    0x4
#define BCM_UW_COM_FLAGS_OFFSET                     (BCM_UW_COM_OPCODE_OFFSET + 1) // 0x0F = seqnum, 0xF0 = modem index
#define BCM_UW_COM_CODE_OFFSET                      (BCM_UW_COM_OPCODE_OFFSET + 2)
#define BCM_UW_COM_MSG_LEN_OFFSET                   (BCM_UW_COM_OPCODE_OFFSET + 3)

// host protocol "flags" field structure
#define BCM_UW_COM_FLAGS_SEQ_NUM_BIT                0
#define BCM_UW_COM_FLAGS_SEQ_NUM_MASK               0xF
#define BCM_UW_COM_FLAGS_MODEM_INDEX_BIT            4
#define BCM_UW_COM_FLAGS_MODEM_INDEX_MASK           0xF

// IP header structure
#define BCM_UW_COM_IP_PROTOCOL_HEADER_LEN           4
#define BCM_UW_COM_IP_PROTOCOL_SEQNUM_OFFSET        0
#define BCM_UW_COM_IP_PROTOCOL_DEVICE_ID_OFFSET     1
#define BCM_UW_COM_IP_PROTOCOL_GW_ERROR_OFFSET      2
#define BCM_UW_COM_IP_PROTOCOL_MODE_OFFSET          3

///////////////////////////////////////////////////////////////////////////////
// ENUMS
///////////////////////////////////////////////////////////////////////////////
 /*
typedef enum
{
    BCM_UW_COM_CONFIG_FILE_START_E,
    BCM_UW_COM_CONFIG_FILE_MIDDLE_E,
    BCM_UW_COM_CONFIG_FILE_END_E
} BCM_UW_COM_CFG_FILE_POSITION_ENUM;
*/

#define    BCM_UW_COM_CONFIG_FILE_START_E	   (0)
#define    BCM_UW_COM_CONFIG_FILE_MIDDLE_E	   (1)
#define    BCM_UW_COM_CONFIG_FILE_END_E		   (2)
#define    BCM_UW_COM_CFG_FILE_POSITION_ENUM  unsigned char



/*
typedef enum
{
    BCM_UW_COM_DSP_CHUNK_START_E,
    BCM_UW_COM_DSP_CHUNK_MIDDLE_E,
    BCM_UW_COM_DSP_CHUNK_END_E
} BCM_UW_COM_DSP_BUFFER_POSITION_ENUM;
*/

#define     BCM_UW_COM_DSP_CHUNK_START_E			  (0)
#define     BCM_UW_COM_DSP_CHUNK_MIDDLE_E			  (1)
#define     BCM_UW_COM_DSP_CHUNK_END_E				  (2)
#define     BCM_UW_COM_DSP_BUFFER_POSITION_ENUM		unsigned char

/*
typedef enum
{
    BCM_UW_COM_ETH_PORT_FW_FILE_START_E,
    BCM_UW_COM_ETH_PORT_FW_FILE_MIDDLE_E,
    BCM_UW_COM_ETH_PORT_FW_FILE_END_E
} BCM_UW_COM_ETH_PORT_FW_FILE_POSITION_ENUM;
*/

#define    BCM_UW_COM_ETH_PORT_FW_FILE_START_E				(0)
#define    BCM_UW_COM_ETH_PORT_FW_FILE_MIDDLE_E				(1)
#define    BCM_UW_COM_ETH_PORT_FW_FILE_END_E				(2)
#define    BCM_UW_COM_ETH_PORT_FW_FILE_POSITION_ENUM	unsigned char


///////////////////////////////////////////////////////////////////////////////
// STRUCTS - use ONLY "PACKED" structs
///////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
    #pragma pack( push, com_structs, 1)
#endif
#pragma Push_align_members(1)
typedef __PACK_PREFIX__ struct
{
    BYTE        acqMode;
    BYTE        siMode;
} __PACK__ BCM_UW_COM_ACQUIRE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      numIqPairs;
    BYTE        testBusSel;
} __PACK__ BCM_UW_COM_IQ_SAMPLES_REC_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      offset;
    UINT16      value;
} __PACK__ BCM_UW_COM_WRITE_REGISTER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32      offset;
} __PACK__ BCM_UW_COM_READ_REGISTER_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        chipType;   // BCM_UW_RF_CHIP_TYPE_ENUM
    UINT16      offset;
    UINT16      value;
} __PACK__ BCM_UW_COM_RF_WRITE_REGISTER_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        chipType;   // BCM_UW_RF_CHIP_TYPE_ENUM
    UINT16      offset;
} __PACK__ BCM_UW_COM_RF_READ_REGISTER_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        position;                                           //start/middle/end
    BYTE        pBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-4];    //keep buffer align to 4 byte (for checksum)
} __PACK__ BCM_UW_COM_CFG_FILE_CHUNK_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      address;
    UINT16      index;
    UINT16      size;
} __PACK__ BCM_UW_COM_BOOT_DATA_RECORD_HEADER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32      version;
    UINT32      jumpAddress;
    UINT32      totalLength;
    UINT32      reserved[2];
} __PACK__ BCM_UW_COM_BOOT_HEADER_MSG_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      opcode;
    BYTE        length;
    BYTE        pDataBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE];
} __PACK__ BCM_UW_COM_GENERAL_CONTROL_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      opcode;
    BYTE        length;
    BYTE        rfDevIdx;
    BYTE        pDataBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_GENERAL_CONTROL_HEADER_SIZE - BCM_UW_COM_GENERAL_RF_CONTROL_HEADER_SIZE]; //RF internal struct goes into general com buffer
} __PACK__ BCM_UW_COM_GENERAL_RF_CONTROL_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      param0;
    UINT32      param1;
} __PACK__ BCM_UW_COM_RF_GENERAL_DATA_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        acmProfile;
    BOOLEAN     isLocal;
} __PACK__ BCM_UW_COM_ACM_SWITCH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN     isChannelImproveTable;
    BYTE        profile;
    INT16       mseTenthsVal;
    BYTE        ldpcMantissaTenths;
    BYTE        ldpcExponent;
    BYTE        criteria;
    BYTE        nextProfile;
} __PACK__ BCM_UW_COM_ACM_THRESHOLD_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN     isChannelImproveTable;
    BYTE        profile;
    UINT16      xpdTenthsVal;
} __PACK__ BCM_UW_COM_ACM_XPD_THRESHOLD_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32      profile;
    UINT32      gpiBwKbps;
    UINT32      ethBwKbps;
    UINT32      txRxMode;
} __PACK__ BCM_UW_COM_ACM_GPM_DA_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        profile;
    UINT16      txGain;
} __PACK__ BCM_UW_COM_ACM_TX_GAIN_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        phasePolarity;
    BYTE        frequency;
    BYTE        slaveAddress;
    BYTE        txBufferLen;
    BYTE        rxBufferLen;
    BYTE        txBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_PERIPHERAL_TX_HEADER_SIZE];
} __PACK__ BCM_UW_COM_PERIPHERAL_TX_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        bitIndex;
    BYTE        intType;
} __PACK__ BCM_UW_COM_GPIO_INT_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BCM_UW_GPIO_STRUCT mask;
    BCM_UW_GPIO_STRUCT data;
} __PACK__ BCM_UW_COM_GPIO_WRITE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      checksum;
    UINT32      totalLength;
    BYTE        versionMajor;
    BYTE        versionMinor;
    UINT16      versionBuild;
    UINT32      creationTime;
    BYTE        versionPackage;
    BYTE        reserved[7];
} __PACK__ BCM_UW_COM_MODEM_CONFIG_FILE_HEADER_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        txPhyId;
    BYTE        rxPhyId;
    BYTE        protectionTxPhyId;
} __PACK__ BCM_UW_COM_PROTECTION_TX_RX_PHYID_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BOOLEAN     enableRxSensors;
    BOOLEAN     enableTxSwitch;
} __PACK__ BCM_UW_COM_ACM_ENABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        phyId;
    BYTE        regAddress;
    UINT16      val;
} __PACK__ BCM_UW_COM_ETH_PHY_REG_SET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        phyId;
    BYTE        regAddress;
} __PACK__ BCM_UW_COM_ETH_PHY_REG_GET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        testBus1;
    BYTE        testBus2;
} __PACK__ BCM_UW_COM_TESTBUS_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        engine;
    BYTE        maskIndex;
    BYTE        mask[13];
} __PACK__ BCM_UW_COM_HC_MASK_SET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      packetType;
    BYTE        engine1MaskIndex;
    BYTE        engine2MaskIndex;
    UINT16      lenThreshold;
    UINT16      alternateType;
} __PACK__ BCM_UW_COM_HC_TYPE_SET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        txForce;
    BYTE        rxForce;
} __PACK__  BCM_UW_COM_PLA_FORCE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    INT16       mseThrLowTenths;
    INT16       mseThrHighTenths;
} __PACK__  BCM_UW_COM_PLA_MSE_LIMIT_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        chain;
    BYTE        delay;
} __PACK__ BCM_UW_COM_XPIC_DELAY_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        chain;
    INT32       offsetInKHz;
} __PACK__ BCM_UW_COM_FREQ_OFFSET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE                                port;           //port specified (0-7)
    BCM_UW_ETH_PORT_CONFIGURE_STRUCT    configParams;   //see full struct
} __PACK__ BCM_UW_COM_ETH_PORT_CONFIGURE_EX_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      uCodeFileLength; 
    UINT32      uCodeVersion;
    UINT16      uCodeChecksum;
} __PACK__ BCM_UW_COM_ETH_PORT_FW_FILE_HEADER_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        position; // start/middle/end
    BYTE        pBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1];
} __PACK__ BCM_UW_COM_ETH_PORT_FW_FILE_CHUNK_STRUCT;
typedef __PACK_PREFIX__ struct
{  
    BYTE        agcIndex;      // index
    BYTE        position;   // start/middle/end
    BYTE        pBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2];
} __PACK__ BCM_UW_COM_AGC_TABLE_CHUNK_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        upLinkMode;
    BYTE        downLinkMode;
} __PACK__ BCM_UW_COM_REPEATER_MODE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32      upLinkBaudKhz;
    UINT32      downLinkBaudKhz;
} __PACK__ BCM_UW_COM_REPEATER_BAUD_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      position; // start/middle/end/offset/index/count
    BYTE        flashIndex;
    BYTE        buffLen;
    BYTE        filename[13]; // Max 8.3
    BYTE        pBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_LONG_API_HEADER_SIZE - BCM_UW_COM_FLASH_CHUNK_HEADER_SIZE]; //Flash struct goes into Long API struct
} __PACK__ BCM_UW_COM_FLASH_CHUNK_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      delay1;
    UINT16      delay2;
    BYTE        chain;
} __PACK__ BCM_UW_COM_ECHO_CANCELER_DELAY_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      cableMin;
    UINT16      cableMax;
} __PACK__ BCM_UW_COM_ECHO_CANCELER_CABLE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        primary;            // BCM_UW_ETH_PORT_CLK_SRC_ENUM
    BYTE        secondary;          // BCM_UW_ETH_PORT_CLK_SRC_ENUM
} __PACK__ BCM_UW_COM_ETH_PORT_CLK_SRC_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        dspIdx;             // according to BCM_UW_DSP_IDX_ENUM
    BYTE        position;           // start/middle/end
    BYTE        pBuffer[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-2];
} __PACK__ BCM_UW_COM_DSP_BUFFER_CHUNK_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT32      addr; 
    UINT32      length;
    BYTE        memoryType; // according to BCM_UW_DSP_MEMORY_TYPE_ENUM 
    BYTE        data[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN-BCM_UW_COM_DSP_MEMORY_WR_RD_HEADER_SIZE];
} __PACK__ BCM_UW_COM_DSP_MEMORY_WR_RD_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        protectionMode;
    BYTE        protectionSysMode;
} __PACK__ BCM_UW_COM_PROTECTION_MODE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        agcIndex;
    BYTE        isOpenLoop;
    UINT16      targetPowerChangeRateDbHundredth;
} __PACK__ BCM_UW_COM_AGC_CONF_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        agcIndex;
    INT16       targetPower0DbmTenth;
    INT16       targetPower1DbmTenth;
} __PACK__ BCM_UW_COM_AGC_TARGET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;
    BYTE        row;
    BOOLEAN     isEnable;
} __PACK__ BCM_UW_COM_AGC_ROW_FORCE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;
    BOOLEAN     freezeEn;
} __PACK__ BCM_UW_COM_AGC_FREEZE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE        wbRxIndex;
    BYTE        blockSel;
    BYTE        hostSel;     
    BYTE        dataMode;
    BOOLEAN     repeat;
    BOOLEAN     dummy1;
} __PACK__ BCM_UW_COM_WB_SNAPSHOT_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;
    INT16       mainSetPointDbTenth;
    INT16       innerSetPointDbTenth;
    INT16       peakValueDbTenth;
} __PACK__ BCM_UW_COM_AGC_SET_POINT_SET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;            //adc/dac
    INT16       gainOffset0DbTenth;
    INT16       gainOffset1DbTenth;
    INT16       gainOffset2DbTenth;
    INT16       gainOffset3DbTenth;    
} __PACK__ BCM_UW_COM_AGC_BACKOFF_OFFSET_SET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;            //adc/dac
    BYTE        mainTrackIndex;
    BYTE        gainModifierIndex;
} __PACK__ BCM_UW_COM_AGC_BANDWIDTH_SET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;
    BOOLEAN     enable;
    INT16       offsetDbTenth;
} __PACK__ BCM_UW_COM_AGC_TABLE_OFFSET_SET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        calibMode; 
    UINT16      calibPeriodMsec;
} __PACK__ BCM_UW_COM_PPS_RTC_CALIB_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        source; 
    UINT32      offsetNsec; 
} __PACK__ BCM_UW_COM_PPS_CONFIGURE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        calibStatus; 
    BYTE        calibFailReason; 
} __PACK__ BCM_UW_COM_PPS_STATUS_GET_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT8       txAckCode;
    UINT8       len;
    UINT8       txMsg[BCM_UW_HOST_PROTOCOL_MAX_PAYLOAD_LEN - BCM_UW_COM_LONG_API_HEADER_SIZE];
} __PACK__ BCM_UW_COM_LONG_API_PROBE_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BOOLEAN     enable; 
    UINT16      highPrioFifoLevelTh;
    BYTE        highPrioIndGpio;
    UINT16      lowPrioFifoLevelTh;
    BYTE        lowPrioIndGpio;
} __PACK__ BCM_UW_COM_TX_MAC_FIFO_IND_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      paramOffset;
    INT32       paramValue;
    BYTE        paramLength;
} __PACK__ BCM_UW_COM_DEVICE_CFG_PARAM_MODIFY_STRUCT;
typedef __PACK_PREFIX__ struct
{
    UINT16      paramOffset;
    BYTE        paramValue[16]; //BCM_UW_DC_VARS_VALUE_MAX_SIZE
    BYTE        paramLength;
} __PACK__ BCM_UW_COM_DEVICE_CFG_STRING_PARAM_MODIFY_STRUCT;
typedef __PACK_PREFIX__ struct
{
    BYTE        index;            //adc
    BYTE        analogGainIdx;
    INT16       totalGainCompensationDbTenth;
} __PACK__ BCM_UW_COM_AGC_BACKOFF_COMPENSATION_SET_STRUCT;

/////////////////////////////////////////////////////////////////////////////////
#pragma Pop_align_members()
#ifdef WIN32
    #pragma pack( pop, com_structs )
#endif

#endif

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

