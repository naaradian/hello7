#ifndef HOST_PROTOCOL_STRUCTS_H
#define HOST_PROTOCOL_STRUCTS_H


#include "defs610.h"
#include "utils.h"

// temporary placed here.
#define PVG610_BOOT_FW_SIZE_BYTES                 (8*1024)	  //  86940 //t (8*1024)

#define PVG610_HOST_PROTOCOL_MAX_MSG_LEN            256
#define PVG610_HOST_PROTOCOL_HEADER_LEN             4
#define PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN        (PVG610_HOST_PROTOCOL_MAX_MSG_LEN - PVG610_HOST_PROTOCOL_HEADER_LEN - PVG610_CHECKSUM_LEN)
#define PVG610_HOST_PROTOCOL_PAYLOAD_OFFSET         (PVG610_HOST_PROTOCOL_HEADER_LEN)
// max size of the record buffer within the config file.
// the other fields are insignificant in length.
#define PVG610_MAX_CONFIG_FILE_LEN                  (16384)
#define PVG610_CHECKSUM_LEN					4 //my

///////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////
#define PVG610_COM_REGISTER_RANGE_HEADER_SIZE       6
#define PVG610_COM_MULTIPLE_REGISTERS_HEADER_SIZE   3
#define PVG610_COM_DWORD_FIFO_HEADER_SIZE           7
#define PVG610_COM_GENERAL_CONTROL_HEADER_SIZE      5

///////////////////////////////////////////////////////////////////////////////
// ENUMS
///////////////////////////////////////////////////////////////////////////////


/*
typedef enum
{
    PVG610_OPCODE_OFFSET_E,
    PVG610_TASK_CONTEXT_AND_SEQ_NUM_OFFSET_E,
    PVG610_NACK_REASON_OFFSET_E,
    PVG610_MSG_LEN_OFFSET_E,
} PVG610_HOST_PROTOCOL_MSG_HEADER_ENUM;

*/

#define    PVG610_OPCODE_OFFSET_E (0)
#define    PVG610_TASK_CONTEXT_AND_SEQ_NUM_OFFSET_E (1)
#define    PVG610_NACK_REASON_OFFSET_E (2)
#define    PVG610_MSG_LEN_OFFSET_E (3)



/*
typedef enum
{
    PVG610_COM_CONFIG_FILE_START_E,
    PVG610_COM_CONFIG_FILE_MIDDLE_E,
    PVG610_COM_CONFIG_FILE_END_E
} PVG610_COM_CFG_FILE_POSITION_ENUM;
*/

#define    PVG610_COM_CONFIG_FILE_START_E (0)
#define    PVG610_COM_CONFIG_FILE_MIDDLE_E (1)
#define    PVG610_COM_CONFIG_FILE_END_E	(2)





///////////////////////////////////////////////////////////////////////////////
// STRUCTS
///////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
    #pragma pack( push, com_structs, 1)
#endif

typedef __PACK_PREFIX__ struct
{
    BYTE    acqMode;
    BYTE    siMode;
} __PACK__ PVG610_COM_ACQUIRE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 totalNumOfPairs;
    BYTE testBusSel;
    BOOLEAN xpicSlave;
} __PACK__ PVG610_COM_IQ_SAMPLES_REC_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 numOfPairs;
    BOOLEAN xpicSlave;
} __PACK__ PVG610_COM_IQ_SAMPLES_GET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 offset;
    BOOLEAN xpicSlave;
    UINT16 value;
} __PACK__ PVG610_COM_WRITE_REGISTER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 offset;
    BOOLEAN xpicSlave;
    BYTE increment;
    UINT16 len;
    BYTE pDataBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_REGISTER_RANGE_HEADER_SIZE]; // substruct the size of the previous params
} __PACK__ PVG610_COM_WRITE_REGISTER_RANGE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 offset;
    BOOLEAN xpicSlave;
    UINT16 len;
    BYTE increment;
    BYTE tableIndex;
} __PACK__ PVG610_COM_WRITE_FROM_ROM_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE constel8Index;
    BYTE constel16Index;
    BYTE constel32Index;
} __PACK__ PVG610_COM_WRITE_LDPC_SOFT_SLICER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 offset;
    UINT16 len;
    BYTE tableIndex;
    BYTE mult;
    BYTE div;
    BOOLEAN rotate;
} __PACK__ PVG610_COM_WRITE_SCALED_MAPPER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16  offset;
    BOOLEAN xpicSlave;
} __PACK__ PVG610_COM_READ_REGISTER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE ifIndex;
    BYTE signal;
    BOOLEAN toTheAir;
} __PACK__ PVG610_NET_E1_STM1_SIGNALS_FORCE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE e1Index;
    BYTE cableConfig;
} __PACK__ PVG610_NET_E1_CABLE_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE ifIndex;
    BOOLEAN hiz;
} __PACK__ PVG610_COM_NET_TRIBUTARY_HIZ_SET_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN connect;
    BYTE ifIndex;
    BOOLEAN fromTheAir;
} __PACK__ PVG610_COM_NET_PRBS_CONNECT_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16 offset;
    BOOLEAN xpicSlave;
    BYTE increment;
    UINT16 len;
} __PACK__ PVG610_COM_READ_REGISTER_RANGE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16    len;
    BOOLEAN xpicSlave;
    UINT16    offset[(PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_MULTIPLE_REGISTERS_HEADER_SIZE) / 2];
} __PACK__ PVG610_COM_READ_MULTIPLE_REGISTERS_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE pDataBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_REGISTER_RANGE_HEADER_SIZE]; // substruct the size of the previous params
} __PACK__ PVG610_COM_READ_REGISTER_RANGE_RES_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16  offsetLow;
    UINT16  offsetHigh;
    BOOLEAN xpicSlave;
    UINT16  lenInDword;
    BYTE    pDataBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_DWORD_FIFO_HEADER_SIZE]; // substruct the size of the previous params
} __PACK__ PVG610_COM_DWORD_FIFO_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE    position; // start/middle/end
    BYTE    pBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1];
} __PACK__ PVG610_COM_CFG_FILE_CHUNK_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE    byteRx;
    BYTE    pBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - 1];
} __PACK__  PVG610_COM_DEBUG_RES_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32  address;
    UINT16  index;
    UINT16  size;
} __PACK__ PVG610_BOOT_DATA_RECORD_HEADER_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32  version;
    UINT32  jumpAddress;
    UINT32  totalLength;
    UINT32  reserved[2];
} __PACK__ PVG610_BOOT_HEADER_MSG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32 opcode;
    BYTE   length;
    BYTE   pDataBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_GENERAL_CONTROL_HEADER_SIZE]; // substruct the size of the previous params
} __PACK__ PVG610_COM_GENERAL_CONTROL_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT32  address;
    BYTE    len;
} __PACK__ PVG610_COM_MEMORY_GET_STRUCT;

typedef __PACK_PREFIX__ struct
{                                                                                     
    UINT32  address;                                                                  //address = 4 +                  
    BYTE    len;                                                                      // total ==>  5                  
    BYTE    data[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_GENERAL_CONTROL_HEADER_SIZE];    //data max size = 256 - header -5 = 243 bytes
} __PACK__ PVG610_COM_MEMORY_SET_STRUCT;                                                                                     

typedef __PACK_PREFIX__ struct
{
    BYTE    acmProfile;
    BOOLEAN isLocal;
} __PACK__ PVG610_COM_ACM_SWITCH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE    localAcmProfile;
    BYTE    remoteAcmProfile;
} __PACK__ PVG610_COM_ACM_TDD_SWITCH_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN isChannelImproveTable;
    BYTE profile; 
    INT16 mseTenthsVal; 
    BYTE ldpcMantissaTenths;
    BYTE ldpcExponent;
    BYTE criteria; 
    BYTE nextProfile;
} __PACK__ PVG610_ACM_THRESHOLD_SET_STRUCT;	  

typedef __PACK_PREFIX__ struct
{
    UINT32 profile; 
    UINT32 gpiBwKbps; 
    UINT32 ethBwKbps; 
    UINT32 pdhMask;
} __PACK__ PVG610_ACM_GPM_DYNAMIC_ALLOCATION_SET_STRUCT;


typedef __PACK_PREFIX__ struct
{
    UINT32  totalLen;
    BYTE    fwIndex;
} __PACK__ PVG610_COM_FLASH_FW_BURN_START_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE    dataFrameSize;
    BYTE    phasePolarity;
    BYTE    frequency;
    BYTE    slaveAddress;
    BYTE    txBufferLen;
    BYTE    rxBufferLen;
    BYTE    txBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - 6];
} __PACK__ PVG610_PERIPHERAL_TX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BOOLEAN transactionComplete;
    BYTE    rxBufferLen;
    BYTE    rxBuffer[PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - 2];
} __PACK__ PVG610_PERIPHERAL_RX_STRUCT;

typedef __PACK_PREFIX__ struct
{
    BYTE    bitIndex;
    BYTE    intType;
} __PACK__ PVG610_GPIO_INT_CONFIG_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16    mask;
    UINT16    data;
} __PACK__ PVG610_GPIO_WRITE_STRUCT;

typedef __PACK_PREFIX__ struct
{
    UINT16    mask;
} __PACK__ PVG610_GPIO_READ_STRUCT;


typedef __PACK_PREFIX__ struct
{
    INT16   fdfIntDelay;
    UINT16  fdfValues[14];
    BYTE    mode;
} __PACK__ PVG610_IQ_DELAY_STRUCT;

typedef  __PACK_PREFIX__ struct
{
    UINT32                  checksum;
    UINT16                  totalLength;
    BYTE                    versionMajor;
    BYTE                    versionMinor;
    BYTE                    versionBuild;
    UINT32                  creationTime;
    BYTE                    versionPackage;
    BYTE                    reserved[5];
} __PACK__ PVG610_MODEM_CONFIG_FILE_HEADER_STRUCT;

typedef  __PACK_PREFIX__ struct
{
    PVG610_MODEM_CONFIG_FILE_HEADER_STRUCT header;
    BYTE                                   recordsBuffer[PVG610_MAX_CONFIG_FILE_LEN];
} __PACK__  PVG610_MODEM_CONFIG_FILE_STRUCT;

typedef  __PACK_PREFIX__ struct
{
    BYTE    protectionMode;
    BYTE    phyId;
    BYTE    copyAcmFormWorking;
} __PACK__  PVG610_PROTECTION_TX_MODE_STRUCT;

typedef  __PACK_PREFIX__ struct
{
    BYTE    protectionMode;
    BYTE    phyId;
} __PACK__  PVG610_PROTECTION_RX_MODE_STRUCT;

typedef __PACK_PREFIX__ struct{
    BOOLEAN enableRx;
    BOOLEAN enableTx;
} __PACK__ PVG610_ACM_ENABLE_STRUCT;

typedef __PACK_PREFIX__ struct{
    BYTE    eventsMask;
    BYTE    periodicTimerIn50MsecUnits;
} __PACK__ PVG610_UNSOLICITED_UART_MSGS_STRUCT;

typedef __PACK_PREFIX__ struct {
    BYTE        loopbackValue;
    BOOLEAN     loopbackNearEnd;
    UINT32      tributaryMask;
} __PACK__ PVG610_LOOPBACK_GET_STRUCT;





#ifdef WIN32
    #pragma pack( pop, com_structs )
#endif

#endif



