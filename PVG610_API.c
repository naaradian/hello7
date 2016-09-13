#include "string.h"    //100420
//#include "stdio.h"
#include "endian.h"
#include "hostDriver.h"
#include "utils.h"
#include "hostProtocolStructs.h"
#include "PVG610_API.h"
//___________________________________________________________
#include "hello7.h"
//___________________________________________________________

//#include "start.h"
//#include "hello7.h"
//#include "embisr.h"
//#include "stdlib.h"

//_____________________
#include <mqx.h>
#include <bsp.h>
//______________________________________
//#include "PVG610_API.h"



#ifdef HOST_PROTOCOL_TX_LOG
    FILE *pfHostMsg;
    #define PVG610_HOST_MSG_FILE_NAME  "hostProtocol.log"
#endif
///////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////
#ifndef PVG610_DEVICES_NUM
#ifndef MANY_MODEMS
    #define PVG610_DEVICES_NUM                      1
#else
    #define PVG610_DEVICES_NUM                      (MODEM_QUANTITY << 1)  //two devices provingent in one modem
#endif    
#endif

//100506 #define PVG610_DEFAULT_TIMEOUT_MILLI                1000
//110602#define PVG610_DEFAULT_TIMEOUT_MILLI                5   //100506
//#define PVG610_DEFAULT_TIMEOUT_MILLI                1   //110602
#define PVG610_DEFAULT_TIMEOUT_MILLI                10   //110602
//#define PVG610_DEFAULT_TIMEOUT_MILLI                10   //test
#define PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI          100
//#define PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI          300

#define PVG610_FLASH_OPERATION_TIMEOUT_MILLI        40000 // 40 seconds
#define PVG610_FLASH_POLLING_TIMEOUT_MICRO          50000 // 50 milli
#define PVG610_MAX_TOTAL_NUMBER_OF_SNAPSHOT_PAIRS   4095
// peripherials
#define PVG610_I2C_SLEEP_BEFORE_POLLING_IN_MS       5
#define PVG610_I2C_TIMEOUT_IN_MS                    100
#define PVG610_SPI_SLEEP_BEFORE_POLLING_IN_MS       5
#define PVG610_SPI_TIMEOUT_IN_MS                    100
// max buffer size to send / receive from peripherals
#define PVG610_PERIPHERAL_BUFFER_MAX_LEN            240

#define PVG610_SPI_RX_MSG_SMALLEST_SIZE             8
#define PVG610_SPI_RX_MSG_SMALL_SIZE                20
#define PVG610_SPI_RX_MSG_MEDIUM_SIZE               42
#define PVG610_SPI_RX_MSG_LARGE_SIZE                125
#define PVG610_SPI_RX_MSG_LARGEST_SIZE              256
  
///////////////////////////////////////////////////////////////////////////////
// Enums
///////////////////////////////////////////////////////////////////////////////

/*
typedef enum
{
    PVG610_RXH_IDLE_E,
    PVG610_RXH_FLAG_FOUND_E,
    PVG610_RXH_IN_MSG_E,
    PVG610_RXH_ESC_CODE_DETECTED_E,
    PVG610_RXH_IGNORE_E,
} PVG610_RXH_STATE_MACHINE_ENUM;
*/

#define    PVG610_RXH_IDLE_E (0)
#define     PVG610_RXH_FLAG_FOUND_E (1)
#define     PVG610_RXH_IN_MSG_E (2)
#define     PVG610_RXH_ESC_CODE_DETECTED_E (3)
#define     PVG610_RXH_IGNORE_E (4)
    
    
#define  PVG610_RXH_STATE_MACHINE_ENUM BYTE






///////////////////////////////////////////////////////////////////////////////
// Structs
///////////////////////////////////////////////////////////////////////////////
typedef struct
{
    BYTE                            pTxMsg[PVG610_HOST_PROTOCOL_MAX_MSG_LEN + 4];
    BYTE                            pRxMsg[PVG610_HOST_PROTOCOL_MAX_MSG_LEN + 4];
                                    
    BYTE                            pStuffedBuff[2 * PVG610_HOST_PROTOCOL_MAX_MSG_LEN + 2];
    UINT16                          stuffedBuffLen;
                                    
    BYTE                            commandSeqNum;
                                    
    // configuration                
    UINT32                          rxTimeoutMilli;
    PVG610_COM_MEDIA_ENUM           media;
    UINT32                          systemClockInHz;
                                    
    // who am i                     
    BYTE                            deviceIndex;
                                    
    // tx params                    
    UINT32                          txTotalMsgSize;
    UINT32                          txPayloadSize;
    BYTE                            txOpcode;

    // rx params
    UINT32                          rxTotalMsgSize;
    BYTE                            rxOpcode;
    BYTE                            rxSequenceNumber;
    BYTE                            rxTaskContext;
    PVG610_ERROR_MSG_ENUM           rxNackReason;
    PVG610_RXH_STATE_MACHINE_ENUM   rxState;

} PVG610_DATABASE_STRUCT;


///////////////////////////////////////////////////////////////////////////////
// Globals
///////////////////////////////////////////////////////////////////////////////
PVG610_DATABASE_STRUCT gPvg610Database[PVG610_DEVICES_NUM];


///////////////////////////////////////////////////////////////////////////////
// Tables
///////////////////////////////////////////////////////////////////////////////
/*
const INT16 pvg610FdfTable[] ={
    0, 0,0,0,0,0,0,2047,0,0,0,0,0,0
    ,0, 0,0,-1,2,-6,16,2045,-12,4,-1,0,0,0
    ,0, 0,0,-2,5,-13,32,2042,-24,7,-2,1,0,0
    ,0, 0,1,-3,7,-19,49,2039,-36,11,-3,1,0,0
    ,0, 0,1,-3,10,-25,66,2036,-48,15,-4,1,0,0
    ,0, 0,1,-4,13,-31,83,2032,-59,18,-6,1,0,0
    ,0, 0,1,-5,15,-38,100,2028,-71,22,-7,2,0,0
    ,0, 0,2,-6,18,-44,117,2024,-82,25,-8,2,0,0
    ,0, 0,2,-7,20,-51,135,2019,-92,29,-9,2,0,0
    ,0, 0,2,-8,23,-57,152,2014,-103,32,-10,2,0,0
    ,0, 0,2,-8,25,-63,170,2008,-113,35,-11,3,-1,0
    ,0, 0,2,-9,28,-70,188,2002,-123,38,-12,3,-1,0
    ,0, -1,3,-10,30,-76,207,1996,-133,42,-13,3,-1,0
    ,0, -1,3,-11,33,-83,225,1990,-143,45,-14,3,-1,0
    ,0, -1,3,-12,35,-89,243,1983,-152,48,-15,4,-1,0
    ,0, -1,3,-13,37,-96,262,1975,-161,51,-16,4,-1,0
    ,0, -1,4,-13,40,-102,281,1968,-170,54,-17,4,-1,0
    ,0, -1,4,-14,42,-108,300,1960,-179,57,-18,4,-1,0
    ,0, -1,4,-15,45,-115,319,1951,-187,60,-19,5,-1,0
    ,0, -1,4,-16,47,-121,339,1943,-195,63,-19,5,-1,0
    ,0, -1,4,-17,50,-127,358,1934,-203,65,-20,5,-1,0
    ,0, -1,5,-17,52,-134,378,1924,-211,68,-21,5,-1,0
    ,0, -1,5,-18,54,-140,397,1915,-218,71,-22,6,-1,0
    ,0, -1,5,-19,57,-146,417,1905,-226,73,-23,6,-1,0
    ,0, -1,5,-20,59,-152,437,1894,-233,76,-24,6,-1,0
    ,0, -1,5,-21,61,-159,457,1884,-239,78,-24,6,-1,0
    ,0, -1,6,-21,63,-165,477,1873,-246,81,-25,6,-1,0
    ,0, -1,6,-22,66,-171,498,1861,-252,83,-26,7,-1,0
    ,0, -1,6,-23,68,-177,518,1850,-258,85,-27,7,-1,0
    ,0, -1,6,-23,70,-183,538,1838,-264,87,-27,7,-1,0
    ,0, -1,6,-24,72,-188,559,1826,-270,89,-28,7,-1,0
    ,0, -1,7,-25,74,-194,579,1813,-275,91,-29,7,-1,0
    ,0, -1,7,-25,76,-200,600,1800,-280,93,-29,7,-1,0
    ,0, -1,7,-26,78,-206,621,1787,-285,95,-30,8,-1,0
    ,0, -1,7,-27,80,-211,642,1774,-290,97,-31,8,-1,0
    ,0, -1,7,-27,82,-217,662,1760,-294,99,-31,8,-1,0
    ,0, -1,7,-28,84,-222,683,1746,-298,100,-32,8,-2,0
    ,0, -1,8,-29,86,-228,704,1732,-302,102,-32,8,-2,0
    ,0, -1,8,-29,88,-233,725,1717,-306,104,-33,8,-2,0
    ,0, -1,8,-30,90,-238,746,1703,-309,105,-33,9,-2,0
    ,0, -2,8,-30,92,-243,767,1688,-313,106,-34,9,-2,0
    ,0, -2,8,-31,93,-248,788,1672,-316,108,-34,9,-2,0
    ,0, -2,8,-31,95,-253,809,1657,-318,109,-35,9,-2,0
    ,0, -2,8,-32,97,-258,830,1641,-321,110,-35,9,-2,0
    ,0, -2,8,-32,98,-262,851,1625,-323,111,-35,9,-2,0
    ,0, -2,9,-33,100,-267,872,1609,-326,112,-36,9,-2,0
    ,0, -2,9,-33,101,-271,893,1593,-327,113,-36,9,-2,0
    ,0, -2,9,-34,103,-276,914,1576,-329,114,-36,9,-2,0
    ,0, -2,9,-34,104,-280,935,1559,-331,115,-37,9,-2,0
    ,0, -2,9,-35,105,-284,956,1542,-332,116,-37,10,-2,0
    ,0, -2,9,-35,107,-288,977,1525,-333,116,-37,10,-2,0
    ,0, -2,9,-35,108,-292,998,1507,-334,117,-37,10,-2,0
    ,0, -2,9,-36,109,-295,1019,1489,-335,117,-38,10,-2,0
    ,0, -2,9,-36,110,-299,1040,1471,-335,118,-38,10,-2,0
    ,0, -2,9,-36,111,-302,1060,1453,-335,118,-38,10,-2,0
    ,0, -2,10,-37,112,-305,1081,1435,-335,118,-38,10,-2,0
    ,0, -2,10,-37,113,-308,1102,1416,-335,119,-38,10,-2,0
    ,0, -2,10,-37,114,-311,1122,1398,-335,119,-38,10,-2,0
    ,0, -2,10,-37,114,-314,1143,1379,-334,119,-38,10,-2,0
    ,0, -2,10,-38,115,-317,1163,1360,-334,119,-38,10,-2,0
    ,0, -2,10,-38,116,-319,1183,1341,-333,119,-38,10,-2,0
    ,0, -2,10,-38,116,-322,1203,1322,-332,119,-38,10,-2,0
    ,0, -2,10,-38,117,-324,1223,1302,-331,118,-38,10,-2,0
    ,0, -2,10,-38,117,-326,1243,1283,-329,118,-38,10,-2,0
    ,0, -2,10,-38,118,-327,1263,1263,-327,118,-38,10,-2,0
    ,0, -2,10,-38,118,-329,1283,1243,-326,117,-38,10,-2,0
    ,0, -2,10,-38,118,-331,1302,1223,-324,117,-38,10,-2,0
    ,0, -2,10,-38,119,-332,1322,1203,-322,116,-38,10,-2,0
    ,0, -2,10,-38,119,-333,1341,1183,-319,116,-38,10,-2,0
    ,0, -2,10,-38,119,-334,1360,1163,-317,115,-38,10,-2,0
    ,0, -2,10,-38,119,-334,1379,1143,-314,114,-37,10,-2,0
    ,0, -2,10,-38,119,-335,1398,1122,-311,114,-37,10,-2,0
    ,0, -2,10,-38,119,-335,1416,1102,-308,113,-37,10,-2,0
    ,0, -2,10,-38,118,-335,1435,1081,-305,112,-37,10,-2,0
    ,0, -2,10,-38,118,-335,1453,1060,-302,111,-36,9,-2,0
    ,0, -2,10,-38,118,-335,1471,1040,-299,110,-36,9,-2,0
    ,0, -2,10,-38,117,-335,1489,1019,-295,109,-36,9,-2,0
    ,0, -2,10,-37,117,-334,1507,998,-292,108,-35,9,-2,0
    ,0, -2,10,-37,116,-333,1525,977,-288,107,-35,9,-2,0
    ,0, -2,10,-37,116,-332,1542,956,-284,105,-35,9,-2,0
    ,0, -2,9,-37,115,-331,1559,935,-280,104,-34,9,-2,0
    ,0, -2,9,-36,114,-329,1576,914,-276,103,-34,9,-2,0
    ,0, -2,9,-36,113,-327,1593,893,-271,101,-33,9,-2,0
    ,0, -2,9,-36,112,-326,1609,872,-267,100,-33,9,-2,0
    ,0, -2,9,-35,111,-323,1625,851,-262,98,-32,8,-2,0
    ,0, -2,9,-35,110,-321,1641,830,-258,97,-32,8,-2,0
    ,0, -2,9,-35,109,-318,1657,809,-253,95,-31,8,-2,0
    ,0, -2,9,-34,108,-316,1672,788,-248,93,-31,8,-2,0
    ,0, -2,9,-34,106,-313,1688,767,-243,92,-30,8,-2,0
    ,0, -2,9,-33,105,-309,1703,746,-238,90,-30,8,-1,0
    ,0, -2,8,-33,104,-306,1717,725,-233,88,-29,8,-1,0
    ,0, -2,8,-32,102,-302,1732,704,-228,86,-29,8,-1,0
    ,0, -2,8,-32,100,-298,1746,683,-222,84,-28,7,-1,0
    ,0, -1,8,-31,99,-294,1760,662,-217,82,-27,7,-1,0
    ,0, -1,8,-31,97,-290,1774,642,-211,80,-27,7,-1,0
    ,0, -1,8,-30,95,-285,1787,621,-206,78,-26,7,-1,0
    ,0, -1,7,-29,93,-280,1800,600,-200,76,-25,7,-1,0
    ,0, -1,7,-29,91,-275,1813,579,-194,74,-25,7,-1,0
    ,0, -1,7,-28,89,-270,1826,559,-188,72,-24,6,-1,0
    ,0, -1,7,-27,87,-264,1838,538,-183,70,-23,6,-1,0
    ,0, -1,7,-27,85,-258,1850,518,-177,68,-23,6,-1,0
    ,0, -1,7,-26,83,-252,1861,498,-171,66,-22,6,-1,0
    ,0, -1,6,-25,81,-246,1873,477,-165,63,-21,6,-1,0
    ,0, -1,6,-24,78,-239,1884,457,-159,61,-21,5,-1,0
    ,0, -1,6,-24,76,-233,1894,437,-152,59,-20,5,-1,0
    ,0, -1,6,-23,73,-226,1905,417,-146,57,-19,5,-1,0
    ,0, -1,6,-22,71,-218,1915,397,-140,54,-18,5,-1,0
    ,0, -1,5,-21,68,-211,1924,378,-134,52,-17,5,-1,0
    ,0, -1,5,-20,65,-203,1934,358,-127,50,-17,4,-1,0
    ,0, -1,5,-19,63,-195,1943,339,-121,47,-16,4,-1,0
    ,0, -1,5,-19,60,-187,1951,319,-115,45,-15,4,-1,0
    ,0, -1,4,-18,57,-179,1960,300,-108,42,-14,4,-1,0
    ,0, -1,4,-17,54,-170,1968,281,-102,40,-13,4,-1,0
    ,0, -1,4,-16,51,-161,1975,262,-96,37,-13,3,-1,0
    ,0, -1,4,-15,48,-152,1983,243,-89,35,-12,3,-1,0
    ,0, -1,3,-14,45,-143,1990,225,-83,33,-11,3,-1,0
    ,0, -1,3,-13,42,-133,1996,207,-76,30,-10,3,-1,0
    ,0, -1,3,-12,38,-123,2002,188,-70,28,-9,2,0,0
    ,0, -1,3,-11,35,-113,2008,170,-63,25,-8,2,0,0
    ,0, 0,2,-10,32,-103,2014,152,-57,23,-8,2,0,0
    ,0, 0,2,-9,29,-92,2019,135,-51,20,-7,2,0,0
    ,0, 0,2,-8,25,-82,2024,117,-44,18,-6,2,0,0
    ,0, 0,2,-7,22,-71,2028,100,-38,15,-5,1,0,0
    ,0, 0,1,-6,18,-59,2032,83,-31,13,-4,1,0,0
    ,0, 0,1,-4,15,-48,2036,66,-25,10,-3,1,0,0
    ,0, 0,1,-3,11,-36,2039,49,-19,7,-3,1,0,0
    ,0, 0,1,-2,7,-24,2042,32,-13,5,-2,0,0,0
    ,0, 0,0,-1,4,-12,2045,16,-6,2,-1,0,0,0
};
    */
///////////////////////////////////////////////////////////////////////////////
// Prototypes
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610RawDataSend              (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pBuff, UINT32 buffLen);
                                                     
void                  pvg610MessageBuild             (PVG610_DATABASE_STRUCT *pDbRecord, BYTE opcode, BYTE modemIndex, BYTE *pSentParamsBuff, UINT32 sentParamsLen);
extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceive      (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pSentParamsBuff, UINT32 sentParamsLen, PVG610_COM_OPCODE_ENUM opcode, BYTE  modemIndex);
extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceiveS      (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pSentParamsBuff, UINT32 sentParamsLen, PVG610_COM_OPCODE_ENUM opcode, BYTE  modemIndex);
extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceiveR      (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pSentParamsBuff, UINT32 sentParamsLen, PVG610_COM_OPCODE_ENUM opcode, BYTE  modemIndex);
extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceive1      (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pSentParamsBuff, UINT32 sentParamsLen, PVG610_COM_OPCODE_ENUM opcode, BYTE  modemIndex);
PVG610_ERROR_MSG_ENUM pvg610BuildSend                (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pSentParamsBuff, UINT32 sentParamsLen, PVG610_COM_OPCODE_ENUM opcode, BYTE modemIndex);
PVG610_ERROR_MSG_ENUM pvg610MessageSend              (PVG610_DATABASE_STRUCT *pDbRecord);
void                  pvg610MessageStuff             (PVG610_DATABASE_STRUCT *pDbRecord);
void                  pvg610UartMessageSend          (PVG610_DATABASE_STRUCT *pDbRecord);
unsigned char         pvg610SpiMessageSend           (PVG610_DATABASE_STRUCT *pDbRecord);
void                  pvg610DpramMessageSend         (PVG610_DATABASE_STRUCT *pDbRecord);

PVG610_ERROR_MSG_ENUM pvg610MessageReceive           (PVG610_DATABASE_STRUCT *pDbRecord);
PVG610_ERROR_MSG_ENUM pvg610MessageReceive1           (PVG610_DATABASE_STRUCT *pDbRecord);
PVG610_ERROR_MSG_ENUM pvg610UartMessageReceive       (PVG610_DATABASE_STRUCT *pDbRecord);
PVG610_ERROR_MSG_ENUM pvg610SpiMessageReceive        (PVG610_DATABASE_STRUCT *pDbRecord);
PVG610_ERROR_MSG_ENUM pvg610SpiMessageReceive1        (PVG610_DATABASE_STRUCT *pDbRecord);
UINT32                pvg610SpiEstimatedRxMsgSizeGet (PVG610_COM_OPCODE_ENUM opcode);
PVG610_ERROR_MSG_ENUM pvg610DpramMessageReceive      (PVG610_DATABASE_STRUCT *pDbRecord);

PVG610_ERROR_MSG_ENUM pvg610RxMessageParse           (PVG610_DATABASE_STRUCT *pDbRecord);
BOOLEAN               pvg610RxMessageValidityCheck   (PVG610_DATABASE_STRUCT *pDbRecord);
PVG610_ERROR_MSG_ENUM pvg610RxStateMachine           (PVG610_DATABASE_STRUCT *pDbRecord, BYTE val, BOOLEAN *isComplete);

PVG610_ERROR_MSG_ENUM pvg610FwSendAndJump            (PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pBuffer);
BOOLEAN               pvg610IsAlive                  (PVG610_DATABASE_STRUCT *pDbRecord, UINT32 timeInMs, UINT32 tries);
                                                     
PVG610_ERROR_MSG_ENUM pvg610MessageRelay             (BYTE srcDeviceIndex, BYTE destDeviceIndex);
PVG610_ERROR_MSG_ENUM pvg610MessageForward           (BYTE deviceIndex, BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen);

PVG610_ERROR_MSG_ENUM pvg610FlashFwOperation         (BYTE deviceIndex, PVG610_COM_OPCODE_ENUM opcode, PVG610_FIRMWARE_INDEX_ENUM fwIndex);
PVG610_ERROR_MSG_ENUM pvg610FlashConfigFileOperation (BYTE deviceIndex, BYTE modemIndex, PVG610_COM_OPCODE_ENUM opcode);
PVG610_ERROR_MSG_ENUM pvg610FlashFinish              (BYTE deviceIndex, BYTE modemIndex, UINT32 startTime);


//----------------------------------------------------
// Init functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
PVG610_ERROR_MSG_ENUM PVG610_API_Open(void)
{
    pvg610HostOpen();
    return PVG610_SUCCESS_MSG_E;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_Close(void)
{
    pvg610HostClose();
    return PVG610_SUCCESS_MSG_E;
}

PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPhyRegGet(BYTE                           deviceIndex,
                                                 BYTE                           modemIndex,
                                                 BYTE                           phyId,
                                                 BYTE                           regAddress,
                                                 UINT16                         *value)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_NET_ETH_PHY_REG_GET_STRUCT phyRegGet;

 //   pvg610HostApiMutexGet(deviceIndex);
    phyRegGet.phyId      = phyId;
    phyRegGet.regAddress = regAddress;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&phyRegGet,
                                 sizeof(PVG610_NET_ETH_PHY_REG_GET_STRUCT),
                                 PVG610_COM_NET_ETH_PHY_REG_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        // get phy register read value
        memcpy((BYTE*)value, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(UINT16));
    }

 //   pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}






PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPhyRegSet(BYTE                           deviceIndex,
                                                 BYTE                           modemIndex,
                                                 BYTE                           phyId, 
                                                 BYTE                           regAddress, 
                                                 UINT16                         val)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_NET_ETH_PHY_REG_SET_STRUCT phyRegSet;

  //  pvg610HostApiMutexGet(deviceIndex);
    phyRegSet.phyId      = phyId;
    phyRegSet.regAddress = regAddress;
    phyRegSet.val        = val;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&phyRegSet,
                                 sizeof(PVG610_NET_ETH_PHY_REG_SET_STRUCT),
                                 PVG610_COM_NET_ETH_PHY_REG_SET_OPCODE_E,
                                 modemIndex);

 //   pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}



//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Communication Control Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
PVG610_ERROR_MSG_ENUM PVG610_API_ComConfigure(BYTE deviceIndex, PVG610_COM_MEDIA_ENUM media, UINT32 systemClockInHz)
{
    UINT32 endianTest = 1;
#ifdef HOST_PROTOCOL_TX_LOG
    pfHostMsg = fopen(PVG610_HOST_MSG_FILE_NAME , "w");
#endif
    if (deviceIndex > PVG610_DEVICES_NUM)
    {
        return(PVG610_INVALID_DEVICE_INDEX_E);
    }

    if (media > PVG610_COM_MEDIA_MAX_E)
    {
        return(PVG610_INVALID_MEDIA_E);
    }

    if (((BYTE*)&endianTest)[0] == 1)
    {
        // little endian
        pvg610EndianConversionConfigure(FALSE);
    }
    else
    {
        // big endian
        pvg610EndianConversionConfigure(TRUE);
    }

    // initialize device in database
    gPvg610Database[deviceIndex].media = media;
    gPvg610Database[deviceIndex].rxState = PVG610_RXH_IDLE_E;
    gPvg610Database[deviceIndex].rxTotalMsgSize = 0;
    gPvg610Database[deviceIndex].commandSeqNum = 1;
    gPvg610Database[deviceIndex].rxTimeoutMilli = PVG610_DEFAULT_TIMEOUT_MILLI;
    gPvg610Database[deviceIndex].deviceIndex = deviceIndex;
//    printf("\n\r configure : %d", deviceIndex);
    gPvg610Database[deviceIndex].systemClockInHz = systemClockInHz;

    return PVG610_SUCCESS_MSG_E;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ComTimeoutSet(BYTE deviceIndex, UINT32 timeoutInMilli)
{
    gPvg610Database[deviceIndex].rxTimeoutMilli = timeoutInMilli;
    return PVG610_SUCCESS_MSG_E;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ComMessageRelay(BYTE deviceIndexSrc, BYTE deviceIndexDest)
{
    return pvg610MessageRelay(deviceIndexSrc, deviceIndexDest);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ComMessageForward(BYTE deviceIndex, BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen)
{
     return pvg610MessageForward(deviceIndex, pReqBuffer, reqLen, pRespBuffer, pRespLen);
}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Boot, Flash Handling and Firmware Upgrade Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
// Flash - header
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_FlashHeaderBurn(BYTE deviceIndex, BYTE *pBuffer, UINT16 len)
{
    PVG610_ERROR_MSG_ENUM  retVal;
    UINT32                 startTime = pvg610HostTickGet();

    if (len > PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN)
    {
        return PVG610_ERROR_CFG_FILE_LEN_TOO_BIG_E;
    }

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 pBuffer,
                                 len,
                                 PVG610_COM_FLASH_HEADER_BURN_START_OPCODE_E,
                                 0);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = pvg610FlashFinish(deviceIndex, 0, startTime);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// Flash - fw
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareBurn(BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex, BYTE *pBuffer, UINT32 len)
{
    PVG610_ERROR_MSG_ENUM                   retVal;
    PVG610_COM_FLASH_FW_BURN_START_STRUCT   fwStart;
    UINT32                                  bytesToSend;
    UINT32                                  offset = 0;
    UINT32                                  startTime = pvg610HostTickGet();

    fwStart.fwIndex = firmwareIndex;
    fwStart.totalLen = len;
 
 // printEthStringAdd(1,0);
 #ifdef PRINT_USART_DATA
 print_flag = 1;
 #endif

    

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&fwStart,
                                 sizeof(PVG610_COM_FLASH_FW_BURN_START_STRUCT),
                                 PVG610_COM_FLASH_FW_BURN_START_OPCODE_E,
                                 0);
  //   printEthStringAdd(1,1);
     
    #ifdef PRINT_USART_DATA
 print_flag = 0;
 #endif
 
                             
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
  //   printEthStringAdd(1,0x1A);
  //     printEthStringAdd(1,retVal);

        return retVal;
    }
 //    printEthStringAdd(1,2);

    while (offset < len)
    {
        bytesToSend = MIN(len-offset, PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN);
  // delay_mcs(5);
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     &pBuffer[offset],
                                     bytesToSend,
                                     PVG610_COM_FLASH_DATA_OPCODE_E,
                                     0);
        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            offset += bytesToSend;
        }
        else if (retVal == PVG610_PERIPHERAL_NOT_READY_E)
        {
            if ( (pvg610HostTickGet() - startTime) > PVG610_FLASH_OPERATION_TIMEOUT_MILLI)
            {
                return PVG610_FLASH_TIMEOUT_E;
            }

            pvg610HostSleep(PVG610_FLASH_POLLING_TIMEOUT_MICRO);
        }
        else
        {
    //      printEthStringAdd(1,0x3a);
    //        printEthStringAdd(1,len>>16);      //9c
    //          printEthStringAdd(1,len>>8);      //9c
    //           printEthStringAdd(1,len); 
    //        printEthStringAdd(1,offset>>16);  //c0
    //          printEthStringAdd(1,offset>>8);  //c0
    //          printEthStringAdd(1,offset);  //c0



            return retVal;
        }
       //   printEthStringAdd(1,3);

    }
    

    retVal = pvg610FlashFinish(deviceIndex, 0, startTime);
  //    printEthStringAdd(1,4);
  //      printEthStringAdd(1,retVal);

    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareErase(BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex)
{
    return pvg610FlashFwOperation(deviceIndex, PVG610_COM_FLASH_FW_ERASE_START_OPCODE_E, firmwareIndex);
}

/////////////////////////////////////////////////////////////////////////////////
// Flash - info get
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_FlashInfoGet(BYTE deviceIndex, PVG610_FLASH_INFO_STRUCT *pFlashInfo)
{
    PVG610_ERROR_MSG_ENUM retVal;
    UINT32 startTime = pvg610HostTickGet();

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_FLASH_INFO_GET_START_OPCODE_E,
                                 0);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = pvg610FlashFinish(deviceIndex, 0, startTime);
    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pFlashInfo, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_FLASH_INFO_STRUCT));
    }

    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_FlashFirmwareReload(BYTE deviceIndex, PVG610_FIRMWARE_INDEX_ENUM firmwareIndex)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_MODEM_VERSION_STRUCT  ver;

    retVal = pvg610FlashFwOperation(deviceIndex, PVG610_COM_FLASH_FW_LOAD_START_OPCODE_E, firmwareIndex);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = pvg610BuildSend(&gPvg610Database[deviceIndex],
                       NULL,
                       0,
                       PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E,
                       0);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    // sleep 3 seconds
    pvg610HostSleep(3000000);

    retVal = PVG610_API_VersionGet(deviceIndex, &ver);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        retVal = PVG610_FW_NOT_ALIVE_E;
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// pBuffer - pointer to the FW file that includes:
//           1. reserved field for burn number
//           2. header
//           3. boot fw code padded with zeroes
//           3. fw data records * N
//           4. checksum
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_FirmwareFromHostBoot(BYTE deviceIndex, BYTE *pBuffer, UINT32 len, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    UINT32 receivedChecksum;
  //   UINT32 calcChecksum;
     
  //   printf("\n\rPVG610_API_FirmwareFromHostBoot");
    //    return 1;    //100420
// printf("\n\r ....1");
 // zcvxgvzx
  // return 0;    
    
// printEthStringAdd(1,1); 
//ok   printEthLongHex(0x1);
//ok    return 1; //t
// sanity check
    if (len < PVG610_BOOT_FW_SIZE_BYTES)
    {
//   printEthStringAdd(1,0x1a);
     //   printf("\n\r ....1a");
        return(PVG610_BOOT_DATA_TOO_SMALL_E);
    }

// compare the received checksum to the calculated checksum (not calculated on
// burn number and checksum fields.
    memcpy(&receivedChecksum,&pBuffer[len-PVG610_CHECKSUM_LEN] ,PVG610_CHECKSUM_LEN);
    
    
    
//   printEthLongHex(receivedChecksum);
//   printEthStringAdd(1,receivedChecksum >> 24);
//   printEthStringAdd(1,receivedChecksum >> 16);
//   printEthStringAdd(1,receivedChecksum >> 8);
//   printEthStringAdd(1,receivedChecksum >> 0);
      
   //    calcChecksum =  pvg610ChecksumCalc(0, &pBuffer[4], len - 4 - PVG610_CHECKSUM_LEN, TRUE);
       
  //     printEthStringAdd(1,calcChecksum >> 24);
  //    printEthStringAdd(1,calcChecksum >> 16);
  //     printEthStringAdd(1,calcChecksum >> 8);
  //      printEthStringAdd(1,calcChecksum >> 0); 
       
    
  //   printf("calc %X   rec %X", calcChecksum,  receivedChecksum);

    
    if (pvg610ChecksumCalc(0, &pBuffer[4], len - 4 - PVG610_CHECKSUM_LEN, TRUE) != receivedChecksum) // exclude burn number and checksum fields.
    {
 //    printf("calc %X   rec %X", calcChecksum,  receivedChecksum);
    
//     printEthStringAdd(1,0x1b);
 #ifndef TEST_BMDN
        return(PVG610_ERROR_CFG_FILE_CRC_E);
 #endif       
    }
//  printEthStringAdd(1,2);
// printf("\n\r...2");
  
    // start critical section
    pvg610HostMutexGet(deviceIndex);
    
//ok  printEthLongHex(0x2);
//ok    return 1; //t
    

    do
    {
         // reset the 610
        pvg610HostDeviceReset(deviceIndex, resetType);     //
         //       printEthStringAdd(1,3);
 //ok printEthLongHex(0x3);
  //ok  return 1; //t
        // inject boot fw - burn number and SW header are skipped.
    retVal = pvg610RawDataSend(&gPvg610Database[deviceIndex], &pBuffer[4 + sizeof(PVG610_BOOT_HEADER_MSG_STRUCT)], PVG610_BOOT_FW_SIZE_BYTES);
  //  retVal = 1; //t  
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
// 110118 #ifndef TEST_BMDN
     //       printf("retVal != PVG610_SUCCESS_MSG_E");
            break;
//110118 #endif            
        }
 //      printEthStringAdd(1,4);
     //  printf("\n\r 4");

//#ifdef TEST_SPI



  //      return(0);
//#endif           
       
       
//#ifdef TEST_BMDN
  //t      return(0);
//#endif           
//       printf("\n\r 4");
 
//  printEthLongHex(0x4);
//   return 1; //t without pdc transmit all work
       

        // flush pending rx data
        if (gPvg610Database[deviceIndex].media == PVG610_COM_MEDIA_UART_E)
        {
            pvg610HostUartReceiverFlush(deviceIndex);
        }
    //        printEthStringAdd(1,5);
            
//no  printEthLongHex(0x5);
//no    return 1; //t
            

        // wait up to 1 second for boot fw
 //t100504       for(long is = 0; is < 100; is++)
//t100504        {
              pvg610HostSleep( 10000);      //10ms
 //t100504       }
         
        if (pvg610IsAlive(&gPvg610Database[deviceIndex], PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
        {
           //      printEthStringAdd(1,6);
       //   printf("\n\r 4a");
              //   printEthLongHex(0x6);
       //    pvg610HostSleep( 3000);
       
#ifdef TEST_SPI
   //ok     return(0);
#endif             
     
              
            // send FW and jump
            retVal = pvg610FwSendAndJump(&gPvg610Database[deviceIndex], pBuffer);
            
            if (retVal != PVG610_SUCCESS_MSG_E)
            {
            //    printf("retVal != PVG610_SUCCESS_MSG_E");
             //    printEthStringAdd(1,0x6A);
            //      printEthStringAdd(1,retVal);
                  
                break;
                
                
            }
           //       printEthStringAdd(1,7);
                  
//  pvg610HostSleep( 3000);
                  
            // wait up to 3 seconds for fw
            
    //          for(is = 0; is < 300; is++)
    //    {
              pvg610HostSleep( 10000);      //10ms
    //    }

     // printf      
            
            if (!pvg610IsAlive(&gPvg610Database[deviceIndex], PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
            {
                retVal = PVG610_FW_NOT_ALIVE_E;
        //           printEthStringAdd(1,0x8A);
            }
     //            printEthStringAdd(1,8);
        }
        else
        {
    //    printf("PVG610_BOOT_FW_NOT_ALIVE_E");
            retVal = PVG610_BOOT_FW_NOT_ALIVE_E;
        }
    } while(0);
  //         printEthStringAdd(1,9);
    // end critical section
    pvg610HostMutexRelease(deviceIndex);
    
//printf("\n\r 5");
    
    return(retVal);
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_FirmwareFromHostReload(BYTE deviceIndex, BYTE *pBuffer, UINT32 len)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    UINT32 offset = sizeof(UINT32); // skip the burn number
    INT32 totalLen;
    UINT32 receivedChecksum;

    if (len < PVG610_BOOT_FW_SIZE_BYTES)
    {
        return(PVG610_BOOT_DATA_TOO_SMALL_E);
    }

    // compare the received checksum to the calculated checksum (not calculated on
    // burn number and checksum fields.
    memcpy(&receivedChecksum,&pBuffer[len-PVG610_CHECKSUM_LEN] ,PVG610_CHECKSUM_LEN);
    if (pvg610ChecksumCalc(0, &pBuffer[4], len - 4 - 4, TRUE) != receivedChecksum) // exclude burn number and checksum fields.
    {
        return(PVG610_ERROR_CFG_FILE_CRC_E);
    }

    // start critical section
 //    printEthStringAdd(1,0);
    
    pvg610HostMutexGet(deviceIndex);

    do
    {
        // start message
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     NULL,
                                     0,
                                     PVG610_COM_START_TRANSFERRING_BOOT_FW_OPCODE_E,
                                     0);
                                     
   //    printEthStringAdd(1,1);
       
  //    printEthStringAdd(1,retVal);
                                     
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        // skip the SW header
        offset += sizeof(PVG610_BOOT_HEADER_MSG_STRUCT);

        // data messages
        totalLen = PVG610_BOOT_FW_SIZE_BYTES;
        
     //     printEthStringAdd(1,2);
 //     printEthStringAdd(1,totalLen); 
      
 //        totalLen =   8*1024; //for test
    //     printEthStringAdd(1,3);
         
   //   printEthStringAdd(1,totalLen>>24); 
   //   printEthStringAdd(1,totalLen>>16); 
    //  printEthStringAdd(1,totalLen>>8); 
  //    printEthStringAdd(1,totalLen); 
      
//        pvg610IsAlive(&gPvg610Database[deviceIndex], PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10); //my
        
         pvg610HostSleep(10000);


      
        while (totalLen > 0)
        {
            len = (totalLen > PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN) ?  PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN: totalLen;
           
            retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                         (BYTE*)&pBuffer[offset],
                                         len,
                                         PVG610_COM_BOOT_FW_DATA_MSG_OPCODE_E,
                                         0);
            if (retVal != PVG610_SUCCESS_MSG_E)
            {
         //     printEthStringAdd(1,4);
         //     printEthStringAdd(1,retVal);
                break;
            }

            offset += len;
            totalLen -= len;
        }

        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        // jump message
        retVal = pvg610BuildSend(&gPvg610Database[deviceIndex],
                           NULL,
                           0,
                           PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E,
                           0);
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        // wait up to 1 second for boot fw
        if (pvg610IsAlive(&gPvg610Database[deviceIndex], PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
        {
            // send FW and jump
            retVal = pvg610FwSendAndJump(&gPvg610Database[deviceIndex], pBuffer);
            if (retVal != PVG610_SUCCESS_MSG_E)
            {
                break;
            }

            // wait up to 3 seconds for fw
            if (!pvg610IsAlive(&gPvg610Database[deviceIndex], PVG610_BOOT_IS_ALIVE_TIMEOUT_MILLI, 10))
            {
                retVal = PVG610_FW_NOT_ALIVE_E;
            }
        }
        else
        {
            retVal = PVG610_BOOT_FW_NOT_ALIVE_E;
        }
    } while(0);

    // end critical section
    pvg610HostMutexRelease(deviceIndex);
    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Configuration File Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
// Config file APIs
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromHostLoad (BYTE                deviceIndex,
                                    BYTE       modemIndex,
                                    BYTE       *pBuffer,
                                    UINT16     len) // in bytes
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    UINT16 bytesToSet;
    PVG610_COM_CFG_FILE_CHUNK_STRUCT   cfgFileChunk;
    UINT16 bytesSetSoFar = 0;

    cfgFileChunk.position = PVG610_COM_CONFIG_FILE_START_E;

    while ((len > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
 //   printf("len = %d", len);
        bytesToSet = (UINT16)MIN((PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1),len);
        memcpy((BYTE*)cfgFileChunk.pBuffer,&pBuffer[bytesSetSoFar],bytesToSet);

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&cfgFileChunk,
                                     (UINT16)(bytesToSet+sizeof(BYTE)), // 1 byte for position
                                     PVG610_COM_LOAD_CONFIG_FILE_OPCODE_E,
                                     modemIndex);

        len -= bytesToSet;
        bytesSetSoFar += bytesToSet;

        if (len<= (PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-1))
        {
            cfgFileChunk.position = PVG610_COM_CONFIG_FILE_END_E;
        }
        else
        {
            cfgFileChunk.position = PVG610_COM_CONFIG_FILE_MIDDLE_E;
        }
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromEmbeddedGet(BYTE     deviceIndex,
                                                           BYTE     modemIndex,
                                                           BYTE     *pBuffer,
                                                           UINT16   len,
                                                           UINT16   *pReadLen)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_MODEM_CONFIG_FILE_HEADER_STRUCT header;
    BYTE chunkLen;
    UINT16 offset = 0;

    // get config file header
 //   printf("\n\r PVG610_API_ConfigFileFromEmbeddedGet");
 //ok   return 0;       //t
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&offset,
                                 sizeof(UINT16),
                                 PVG610_COM_CONFIG_FILE_FROM_EMBEDDED_GET_OPCODE_E,
                                 modemIndex);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return(retVal);
    }
  //  printf("\n\r 1");
 //   printf("\n\r &p %X ",&gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN]);
 //   printf("\n\r len %X",gPvg610Database[deviceIndex].rxTotalMsgSize-PVG610_HOST_PROTOCOL_HEADER_LEN-PVG610_CHECKSUM_LEN);
  
    if(!gPvg610Database[deviceIndex].rxTotalMsgSize)
    { /* Body */
     return 1;
    } /* Endbody */
    memcpy (pBuffer, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], gPvg610Database[deviceIndex].rxTotalMsgSize-PVG610_HOST_PROTOCOL_HEADER_LEN-PVG610_CHECKSUM_LEN);
    chunkLen = gPvg610Database[deviceIndex].rxTotalMsgSize - PVG610_HOST_PROTOCOL_HEADER_LEN - PVG610_CHECKSUM_LEN;
    offset += chunkLen;
 //    printf("\n\r 2");

 //   return 0;
     
    if (chunkLen < sizeof(PVG610_MODEM_CONFIG_FILE_HEADER_STRUCT))
    {
        return(PVG610_ERROR_CFG_FILE_LEN_TOO_SMALL_E);
    }
   //    printf("\n\r 3");

    // check if length in header is bigger than requested len.
    memcpy((BYTE*)&header, pBuffer, sizeof(PVG610_MODEM_CONFIG_FILE_HEADER_STRUCT));
    if (header.totalLength > len)
    {
        return(PVG610_ERROR_CFG_FILE_LEN_TOO_BIG_E);
    }
 //     printf("\n\r 4");

    // get config file data
    while ((offset < header.totalLength) && (retVal == PVG610_SUCCESS_MSG_E))
    {
 //    printf("\n\r 5");

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&offset,
                                     sizeof(UINT16),
                                     PVG610_COM_CONFIG_FILE_FROM_EMBEDDED_GET_OPCODE_E,
                                     modemIndex);
        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            memcpy(pBuffer + offset, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], gPvg610Database[deviceIndex].rxTotalMsgSize-PVG610_HOST_PROTOCOL_HEADER_LEN-PVG610_CHECKSUM_LEN);
            chunkLen = gPvg610Database[deviceIndex].rxTotalMsgSize - PVG610_HOST_PROTOCOL_HEADER_LEN - PVG610_CHECKSUM_LEN;
            offset += chunkLen;
        }
    }

    *pReadLen = offset;
  //   printf("\n\r 6");

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
// Flash - config file
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileToFlashBurn(BYTE deviceIndex, BYTE modemIndex)
{
    return pvg610FlashConfigFileOperation(deviceIndex, modemIndex, PVG610_COM_CFG_FILE_TO_FLASH_BURN_START_OPCODE_E);
}

PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromFlashLoad(BYTE deviceIndex, BYTE modemIndex)
{
    return pvg610FlashConfigFileOperation(deviceIndex, modemIndex, PVG610_COM_CFG_FILE_FROM_FLASH_LOAD_START_OPCODE_E);
}

PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileFromFlashErase(BYTE deviceIndex, BYTE modemIndex)
{
    return pvg610FlashConfigFileOperation(deviceIndex, modemIndex, PVG610_COM_CFG_FILE_FROM_FLASH_ERASE_START_OPCODE_E);
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ConfigFileRun (BYTE deviceIndex,
                                                BYTE modemIndex)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_RUN_CONFIG_FILE_OPCODE_E,
                                 modemIndex);
    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Direct Setup Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_registerRead                                           //
//                                                                           //
//  PARAMETERS:                                                              //
//              modemIndex  - [in] modem index                                 //
//              offset    - [in] register offset from modem base address     //
//              xpicSlave - [in] is xpic Slave                               //
//              pVal - [out] register value                                  //
//                                                                           //
//  DESCRIPTION:                                                             //
//                                                                           //
//  RETURNS:    PVG610_ERROR_MSG_ENUM                                               //
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRead(BYTE                deviceIndex,
                                              BYTE                modemIndex,
                                              UINT16              offset,
                                              BOOLEAN             xpicSlave,
                                              UINT16              *pVal)
{
    PVG610_ERROR_MSG_ENUM               retVal;
    PVG610_COM_READ_REGISTER_STRUCT     registerToRead;

    registerToRead.offset    = offset;
    registerToRead.xpicSlave = xpicSlave;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&registerToRead,
                                 sizeof(PVG610_COM_READ_REGISTER_STRUCT),
                                 PVG610_COM_REGISTER_READ_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pVal, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(UINT16));
    }

    return retVal;
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_registerWrite                                          //
//                                                                           //
//  PARAMETERS:                                                              //
//              modemIndex - [in] modem index                                  //
//              offset   - [in] register offset from modem base address      //
//              xpicSlave- [in] is xpic Slave                                //
//              val - [in] register value                                    //
//                                                                           //
//  DESCRIPTION:                                                             //
//                                                                           //
//  RETURNS:    PVG610_ERROR_MSG_ENUM                                               //
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterWrite(BYTE               deviceIndex,
                                               BYTE               modemIndex,
                                               UINT16             offset,
                                               BOOLEAN            xpicSlave,
                                               UINT16             val)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_COM_WRITE_REGISTER_STRUCT registerToWrite;

    registerToWrite.offset      = offset;
    registerToWrite.value       = val;
    registerToWrite.xpicSlave   = xpicSlave;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&registerToWrite,
                                 sizeof(PVG610_COM_WRITE_REGISTER_STRUCT),
                                 PVG610_COM_REGISTER_WRITE_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeRead(BYTE               deviceIndex,
                                                   BYTE               modemIndex,
                                                   UINT16             offset,
                                                   BOOLEAN            xpicSlave,
                                                   UINT16             len,
                                                   BOOLEAN            increment,
                                                   UINT16             *pBuffer)
{
    PVG610_ERROR_MSG_ENUM                      retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_READ_REGISTER_RANGE_STRUCT      registerRangeToRead;
    PVG610_COM_READ_REGISTER_RANGE_RES_STRUCT  *pReturnedRegisterRange = (PVG610_COM_READ_REGISTER_RANGE_RES_STRUCT *)&gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN];
    UINT16                              wordsToGet;
    UINT32                              wordsReadSoFar = 0;

    registerRangeToRead.increment = increment;
    registerRangeToRead.offset    = offset;
    registerRangeToRead.xpicSlave = xpicSlave;


    while ((len > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
        wordsToGet = (UINT16)MIN((PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-PVG610_COM_REGISTER_RANGE_HEADER_SIZE)/2,len);

        registerRangeToRead.len = wordsToGet;

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&registerRangeToRead,
                                     (UINT16)(PVG610_COM_REGISTER_RANGE_HEADER_SIZE),
                                     PVG610_COM_REGISTER_RANGE_READ_OPCODE_E,
                                     modemIndex);
        if (increment == TRUE)
        {
            registerRangeToRead.offset += wordsToGet;
        }

        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            memcpy(pBuffer+wordsReadSoFar , (BYTE*)pReturnedRegisterRange->pDataBuffer, wordsToGet*2);
        }

        len -= wordsToGet;
        wordsReadSoFar += wordsToGet;
    }

    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeWrite(BYTE              deviceIndex,
                                                    BYTE              modemIndex,
                                                    UINT16            offset,
                                                    BOOLEAN           xpicSlave,
                                                    UINT16            len,
                                                    BOOLEAN           increment,
                                                    UINT16            *pBuffer)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_WRITE_REGISTER_RANGE_STRUCT registerRangeToWrite;

    UINT16 wordsToSet;
    UINT32 wordsWrittenSoFar = 0;

    registerRangeToWrite.increment = increment;
    registerRangeToWrite.offset    = offset;
    registerRangeToWrite.xpicSlave = xpicSlave;

    while ((len > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
        wordsToSet = (UINT16)MIN((PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-PVG610_COM_REGISTER_RANGE_HEADER_SIZE)/2,len);

        registerRangeToWrite.len = wordsToSet;
        memcpy((BYTE*)registerRangeToWrite.pDataBuffer,(BYTE*)(pBuffer+wordsWrittenSoFar),wordsToSet*2);

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE *)&registerRangeToWrite,
                                     (UINT16)(PVG610_COM_REGISTER_RANGE_HEADER_SIZE + wordsToSet*2),
                                     PVG610_COM_REGISTER_RANGE_WRITE_OPCODE_E,
                                     modemIndex);
        if (increment == TRUE)
        {
            registerRangeToWrite.offset += wordsToSet;
        }

        len -= wordsToSet;
        wordsWrittenSoFar += wordsToSet;
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_MultipleRegistersRead(BYTE               deviceIndex,
                                                       BYTE               modemIndex,
                                                       UINT16             *pOffset,
                                                       BOOLEAN            xpicSlave,
                                                       UINT16             len,
                                                       UINT16             *pBuffer)
{
    PVG610_ERROR_MSG_ENUM                      retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_READ_MULTIPLE_REGISTERS_STRUCT  registersToRead;
    PVG610_COM_READ_REGISTER_RANGE_RES_STRUCT  *pReturnedRegisterRange = (PVG610_COM_READ_REGISTER_RANGE_RES_STRUCT *)&gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN];
    UINT16                              wordsToGet;
    UINT32                              wordsReadSoFar = 0;
    UINT16                              ix;

    while ((len > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
        wordsToGet = (UINT16)MIN((PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_MULTIPLE_REGISTERS_HEADER_SIZE)/2,len);

        registersToRead.xpicSlave   = xpicSlave;
        registersToRead.len         = wordsToGet;

        for (ix=0; ix<wordsToGet; ix++)
        {
            registersToRead.offset[ix] = pOffset[wordsReadSoFar + ix];
        }

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&registersToRead,
                                     (UINT16)(PVG610_COM_MULTIPLE_REGISTERS_HEADER_SIZE + wordsToGet * sizeof(UINT16)),
                                     PVG610_COM_MULTIPLE_REGSITERS_READ_OPCODE_E,
                                     modemIndex);

        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            memcpy(pBuffer+wordsReadSoFar , (BYTE*)pReturnedRegisterRange->pDataBuffer, wordsToGet*2);
        }

        len -= wordsToGet;
        wordsReadSoFar += wordsToGet;
    }
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RegisterRangeFromRomWrite(BYTE deviceIndex,
                                                           BYTE modemIndex,
                                                           UINT16 offset,
                                                           BOOLEAN xpicSlave,
                                                           UINT16 len,
                                                           BOOLEAN increment,
                                                           BYTE tableIndex)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_COM_WRITE_FROM_ROM_STRUCT romToWrite;

    romToWrite.offset       = offset;
    romToWrite.xpicSlave    = xpicSlave;
    romToWrite.increment    = (BYTE)increment;
    romToWrite.len          = len;
    romToWrite.tableIndex   = tableIndex;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&romToWrite,
                                 sizeof(PVG610_COM_WRITE_FROM_ROM_STRUCT),
                                 PVG610_COM_FROM_ROM_WRITE_OPCODE_E,
                                 modemIndex);
    return retVal;

}

//----------------------------------------------------
// the fifo is build from 2 registers.
// we Write the low register first and then the high
// the lenInDword is the number of reads from the high +
//                   the number of reads from the low register
// buffer is in format of Low reg ,high reg , low, high and so on...
//----------------------------------------------------
PVG610_ERROR_MSG_ENUM PVG610_API_DwordFifoRead(BYTE deviceIndex, BYTE modemIndex, UINT16 offsetLow, UINT16 offsetHigh, BOOLEAN xpicSlave, UINT16 lenInDword, UINT32*pBuffer)
{
    PVG610_ERROR_MSG_ENUM             retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_DWORD_FIFO_STRUCT      dwordFifoToRead;

    UINT16                     dwordsToGet;
    UINT32                     dwordsReadSoFar = 0;

    dwordFifoToRead.offsetLow = offsetLow;
    dwordFifoToRead.offsetHigh = offsetHigh;
    dwordFifoToRead.xpicSlave = xpicSlave;

    while ((lenInDword > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
        // buffer contains only UINT32 fifo data without header
        dwordsToGet = (UINT16)MIN(PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN / sizeof(UINT32),lenInDword);

        dwordFifoToRead.lenInDword = dwordsToGet;

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&dwordFifoToRead,
                                     (UINT16)(PVG610_COM_DWORD_FIFO_HEADER_SIZE),
                                     PVG610_COM_DWORD_FIFO_READ_OPCODE_E,
                                     modemIndex);

        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            memcpy((BYTE*)(pBuffer+dwordsReadSoFar) , &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], dwordsToGet*sizeof(UINT32));
        }

        lenInDword -= dwordsToGet;
        dwordsReadSoFar += dwordsToGet;
    }
    return retVal;
}

//----------------------------------------------------
// the fifo is build from 2 registers.
// we Write the low register first and then the high
// the lenInDword is the number of reads from the high +
//                   the number of reads from the low register
// buffer is in format of Low reg ,high reg , low, high and so on...
//----------------------------------------------------
PVG610_ERROR_MSG_ENUM PVG610_API_DwordFifoWrite (BYTE deviceIndex, BYTE modemIndex, UINT16 offsetLow, UINT16 offsetHigh, BOOLEAN xpicSlave, UINT16 lenInDword, UINT32*pBuffer)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_DWORD_FIFO_STRUCT dwordFifoToWrite;

    UINT16  dwordsToSet;
    UINT32  dwordsWrittenSoFar = 0;

    dwordFifoToWrite.offsetLow = offsetLow;
    dwordFifoToWrite.offsetHigh = offsetHigh;
    dwordFifoToWrite.xpicSlave = xpicSlave;

    while ((lenInDword > 0) && (retVal == PVG610_SUCCESS_MSG_E))
    {
        dwordsToSet = (UINT16)MIN((PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN-PVG610_COM_DWORD_FIFO_HEADER_SIZE)/sizeof(UINT32),lenInDword);

        dwordFifoToWrite.lenInDword = dwordsToSet;
        memcpy((BYTE*)dwordFifoToWrite.pDataBuffer,(BYTE*)(pBuffer+dwordsWrittenSoFar),dwordsToSet*sizeof(UINT32));

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE *)&dwordFifoToWrite,
                                     (UINT16)(PVG610_COM_DWORD_FIFO_HEADER_SIZE + dwordsToSet*sizeof(UINT32)),
                                     PVG610_COM_DWORD_FIFO_WRITE_OPCODE_E,
                                     modemIndex);
        lenInDword -= dwordsToSet;
        dwordsWrittenSoFar += dwordsToSet;
    }
    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Status and Performance Monitoring Functions (general)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_VersionGet(BYTE deviceIndex, PVG610_MODEM_VERSION_STRUCT *pVer)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
#ifdef PRINT_USART_DATA    
//now        printEthLongHex(val);
print_flag  = 1;
//        printEthStringAdd(1,val); 
#endif          

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],    //spi
                                 NULL,
                                 0,
                                 PVG610_COM_VERSION_GET_OPCODE_E,
                                 0);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
  //    printf("ver - ok ");
        memcpy(pVer, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_VERSION_STRUCT));
    }
    else{ /* Body */
 //      printf("ver - bad ");
   } /* Endbody */

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_AlarmEnableSet(BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsMask)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)pAlarmsMask,
                                 sizeof(PVG610_ALARMS_STRUCT),
                                 PVG610_COM_ALARM_ENABLE_SET_OPCODE_E,
                                 0);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_AlarmEnableGet(BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsMask)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_ALARM_ENABLE_GET_OPCODE_E,
                                 0);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy ((BYTE*)pAlarmsMask, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_ALARMS_STRUCT));
    }

    return retVal;

}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_AlarmStatusGet(BYTE deviceIndex, PVG610_ALARMS_STRUCT *pAlarmsStatus)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_ALARM_STATUS_GET_OPCODE_E,
                                 0);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy ((BYTE*)pAlarmsStatus, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_ALARMS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_HostInfoSet(BYTE deviceIndex, PVG610_HOST_INFO_STRUCT *pInfo)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)pInfo,
                                 sizeof(PVG610_HOST_INFO_STRUCT),
                                 PVG610_COM_HOST_INFO_SET_OPCODE_E,
                                 0);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_HostInfoGet(BYTE deviceIndex, PVG610_HOST_INFO_STRUCT *pInfo)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_HOST_INFO_GET_OPCODE_E,
                                 0);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy ((BYTE*)pInfo, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_HOST_INFO_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_SysInfoParamsGet(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_SYS_INFO_PARAMS_STRUCT *pSi)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_SYS_INFO_PARAMS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pSi, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_SYS_INFO_PARAMS_STRUCT));
    }

    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Status and Performance Monitoring Functions (modem)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGet(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
//               retVal = pvg610BuildSendAndReceive1(&gPvg610Database[deviceIndex],

                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pMs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_STATUS_STRUCT));
    }

    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGetS(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceiveS(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_STATUS_GET_OPCODE_E,
                                 modemIndex);
    /*
    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pMs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_STATUS_STRUCT));
    }
    */
    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_ModemStatusGetR(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_STATUS_STRUCT *pMs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceiveR(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pMs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_STATUS_STRUCT));
    }

    return retVal;
}



/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_AcmCountersGet(BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_COUNTERS_STRUCT *pMc)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_ACM_COUNTERS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pMc, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_ACM_COUNTERS_STRUCT));
    }

    return retVal;

}
  
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcquireCountersGet  (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT *pAc)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pAc, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_ACQUIRE_COUNTERS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemFecCountersGet (BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_FEC_COUNTERS_STRUCT *pFc)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pFc, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_FEC_COUNTERS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqImbalanceStatusGet(BYTE deviceIndex,
                                                           BYTE modemIndex,
                                                           PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT *pIs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pIs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT));
    }

    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemSlaveIqImbalanceStatusGet(BYTE deviceIndex,
                                                                BYTE modemIndex,
                                                                PVG610_IQ_IMBALANCE_STRUCT *pSlaveIqImb)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_SLAVE_IQ_IMBALANCE_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pSlaveIqImb, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_IQ_IMBALANCE_STRUCT));
    }

    return retVal;
}
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqImbalanceTxTxSet(BYTE deviceIndex,
                                                               BYTE modemIndex,
                                                               INT16 diffPhaseTenthsDeg,     // in 0.1 deg resolution
                                                               INT16 diffGainTenthsDB,        // in 0.1 dB resolution
                                                               INT16 dcLeakageITenthsPercent, // in 0.1 percent resolution
                                                               INT16 dcLeakageQTenthsPercent) // in 0.1 percent resolution
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_IQ_IMBALANCE_STRUCT iqImbTxTx;

    iqImbTxTx.diffPhaseTenthsDeg = diffPhaseTenthsDeg;
    iqImbTxTx.diffGainTenthsDB = diffGainTenthsDB;
    iqImbTxTx.dcLeakageITenthsPercent = dcLeakageITenthsPercent;
    iqImbTxTx.dcLeakageQTenthsPercent = dcLeakageQTenthsPercent;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&iqImbTxTx,
                                 sizeof(PVG610_IQ_IMBALANCE_STRUCT),
                                 PVG610_COM_MODEM_IQ_IMBALANCE_TXTX_SET_OPCODE_E,
                                 modemIndex);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemEqualizerStatusGet(BYTE                           deviceIndex,
                                                         BYTE                           modemIndex,
                                                         BOOLEAN                        xpicSlave,
                                                         PVG610_MODEM_EQU_STATUS_STRUCT *pEs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 &xpicSlave,
                                 sizeof(BOOLEAN),
                                 PVG610_COM_MODEM_EQUALIZER_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pEs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_EQU_STATUS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemXpicStatusGet(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_XPIC_STATUS_STRUCT *pXs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_XPIC_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pXs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_XPIC_STATUS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemPredistortionCoefsGet(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREDISTORTION_STRUCT *pPs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pPs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_PREDISTORTION_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemPreemphasisCoefsGet(BYTE deviceIndex, BYTE modemIndex, PVG610_MODEM_PREEMPHASIS_STRUCT *pPs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pPs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MODEM_PREEMPHASIS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemIqSamplesGet(BYTE deviceIndex,  BYTE modemIndex,
                                                   UINT16 numIqPairs, INT16 *pBuffer,
                                                   BOOLEAN xpicSlave, PVG610_TEST_BUS_ENUM testBusSel)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_IQ_SAMPLES_REC_STRUCT iqSamplesRecParams;
    PVG610_COM_IQ_SAMPLES_GET_STRUCT iqSamplesGetParams;
    UINT16 numIqPairsChuckSize = 60;// since max ret_buffer_size is 256, and 60 pairs add up to (60*4bytes+header)
    UINT16 bufferIndex = 0;

    if (numIqPairs > PVG610_MAX_TOTAL_NUMBER_OF_SNAPSHOT_PAIRS)
    {
        return(PVG610_IQ_SAMPLES_GET_ERROR_E);
    }
    iqSamplesRecParams.totalNumOfPairs  = numIqPairs;
    iqSamplesRecParams.testBusSel       = (BYTE)testBusSel;
    iqSamplesRecParams.xpicSlave = xpicSlave;

    iqSamplesGetParams.xpicSlave = xpicSlave;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&iqSamplesRecParams,
                                 sizeof(PVG610_COM_IQ_SAMPLES_REC_STRUCT),
                                 PVG610_COM_MODEM_IQ_SAMPLES_REC_OPCODE_E,
                                 modemIndex);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    pvg610HostSleep(4000); // 4 msec, to ensure snapshot recording is done

    // start receiving data, assuming that by the time the msgs
    // reach destination, all required data has been recorded already (takes uSec)
    // otherwise, return with PVG610_IQ_SAMPLES_GET_ERROR_E
    while (numIqPairs > 0)
    {
        if (numIqPairs < numIqPairsChuckSize)
        {
            iqSamplesGetParams.numOfPairs = numIqPairs;
        }
        else
        {
            iqSamplesGetParams.numOfPairs = numIqPairsChuckSize;
        }
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&iqSamplesGetParams,
                                 sizeof(PVG610_COM_IQ_SAMPLES_GET_STRUCT),
                                 PVG610_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E,
                                 modemIndex);
        if (retVal != PVG610_SUCCESS_MSG_E)

        {
            return (retVal);
        }

        memcpy (pBuffer+bufferIndex, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], iqSamplesGetParams.numOfPairs * 2 * sizeof(UINT16));
        bufferIndex += (iqSamplesGetParams.numOfPairs) * 2;
        if (numIqPairs < 60)
        {
            numIqPairs = 0; // out of while loop
        }
        else
        {
            numIqPairs -= numIqPairsChuckSize;
        }
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionStatusGet (BYTE deviceIndex, BYTE modemIndex, PVG610_PROTECTION_STATUS_STRUCT *pPs)
{
    PVG610_ERROR_MSG_ENUM retVal;// = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_PROTECTION_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pPs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_PROTECTION_STATUS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_AcmConfigurationGet (BYTE deviceIndex, BYTE modemIndex, PVG610_ACM_COFIGURATION_STRUCT *pCs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_ACM_CONFIGURATION_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(pCs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_ACM_COFIGURATION_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmProfileMaskGet(BYTE   deviceIndex,
                                                        BYTE   modemIndex,
                                                        UINT16 *profilesMask)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_ACM_PROFILE_MASK_GET_OPCODE_E,
                                 modemIndex);
     if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(profilesMask, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(UINT16));
    }

    return retVal;
}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Status / Performance Monitoring Functions - networking
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1AlarmsGet(BYTE                         deviceIndex,
                                                BYTE                         modemIndex,
                                                UINT32                       e1IndexMask,
                                                PVG610_NET_E1_ALARMS_STRUCT  *pStat)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1IndexMask,
                                 sizeof(UINT32),
                                 PVG610_COM_NET_E1_ALARM_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pStat, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], pvg610BitCount(e1IndexMask) * sizeof(PVG610_NET_E1_ALARMS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PmGet(BYTE                     deviceIndex,
                                            BYTE                     modemIndex,
                                            UINT32                   e1IndexMask,
                                            PVG610_NET_E1_PM_STRUCT  *pPm,
                                            UINT16                   *pOneSecondPeriodCounter)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    UINT32         tmpMask = 0;

    // make sure the mask is up to 21 E1's
    e1IndexMask &= 0x1FFFFF;

    // if E1 PMs don't fit in one host protocol message - split to two
    if (pvg610BitCount(e1IndexMask) > (PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN/sizeof(PVG610_NET_E1_PM_STRUCT)))
    {
        // first get up to 11 E1's
        tmpMask = e1IndexMask & 0x7FF;

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&tmpMask,
                                     sizeof(UINT32),
                                     PVG610_COM_NET_E1_PM_GET_OPCODE_E,
                                     modemIndex);

        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }

        // get E1 PMs
        memcpy((BYTE*)pPm, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], pvg610BitCount(tmpMask) * sizeof(PVG610_NET_E1_PM_STRUCT));

        // change mask to get up to 10 remaining E1's
        e1IndexMask &= 0x1FF800;
    }

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1IndexMask,
                                 sizeof(UINT32),
                                 PVG610_COM_NET_E1_PM_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        // get E1 PMs
        memcpy((BYTE*)(pPm + pvg610BitCount(tmpMask)), &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], pvg610BitCount(e1IndexMask) * sizeof(PVG610_NET_E1_PM_STRUCT));

        // get seconds counter
        memcpy(pOneSecondPeriodCounter,
               &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN + pvg610BitCount(e1IndexMask)*sizeof(PVG610_NET_E1_PM_STRUCT)],
               sizeof(UINT16));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1AlarmsGet(BYTE                           deviceIndex,
                                                  BYTE                           modemIndex,
                                                  BYTE                           stm1IndexMask,
                                                  PVG610_NET_STM1_ALARMS_STRUCT  *pStat)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&stm1IndexMask,
                                 sizeof(BYTE),
                                 PVG610_COM_NET_STM1_ALARM_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy((BYTE*)pStat, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], pvg610BitCount(stm1IndexMask) * sizeof(PVG610_NET_STM1_ALARMS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PmGet(BYTE                deviceIndex,
                                    BYTE                          modemIndex,
                                    BYTE                          stm1IndexMask,
                                    PVG610_NET_STM1_PM_STRUCT     *pPm,
                                    UINT16                        *pOneSecondPeriodCounter)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    // clear non-relevant bits
    stm1IndexMask &= 0x3;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&stm1IndexMask,
                                 sizeof(BYTE),
                                 PVG610_COM_NET_STM1_PM_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        // get STM1 PMs
        memcpy((BYTE*)pPm, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], pvg610BitCount(stm1IndexMask) * sizeof(PVG610_NET_STM1_PM_STRUCT));

        // get seconds counter
        memcpy(pOneSecondPeriodCounter,
               &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN + pvg610BitCount(stm1IndexMask)*sizeof(PVG610_NET_STM1_PM_STRUCT)],
               sizeof(UINT16));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetEthPmGet(BYTE           deviceIndex,
                                   BYTE                     modemIndex,
                                   PVG610_NET_ETH_PM_STRUCT *pPm,
                                   UINT16                   *pOneSecondPeriodCounter)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_NET_ETH_PM_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        // get ethernet PM
        memcpy((BYTE*)pPm, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_NET_ETH_PM_STRUCT));

        // get seconds counter
        memcpy(pOneSecondPeriodCounter,
               &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN + sizeof(PVG610_NET_ETH_PM_STRUCT)],
               sizeof(UINT16));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetEthStatusGet(BYTE                           deviceIndex,
                                                 BYTE                           modemIndex,
                                                 PVG610_NET_ETH_STATUS_STRUCT   *pEs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    BYTE sleepCycles = 10;
    BYTE ethPhyTransactionDone = 0;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)pEs,
                                 sizeof(PVG610_NET_ETH_STATUS_STRUCT),
                //                 NULL,
               //                  0,
                                 PVG610_COM_NET_ETH_STATUS_GET_OPCODE_E,
                                 modemIndex);


    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    while (sleepCycles > 0)
    {
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                          //           NULL,
                          //           0,
                                 (BYTE*)pEs,
                                 sizeof(PVG610_NET_ETH_STATUS_STRUCT),
                                     
                                     PVG610_COM_NET_ETH_STATUS_GET_DONE_OPCODE_E,
                                     modemIndex);

        // if error or transaction completed, exit
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }

        ethPhyTransactionDone = gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN + sizeof(PVG610_NET_ETH_STATUS_STRUCT)];

        // if transaction complete copy reply and exit
        if (ethPhyTransactionDone)
        {
            memcpy((BYTE*)pEs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_NET_ETH_STATUS_STRUCT));
            return PVG610_SUCCESS_MSG_E;
        }

        //sleep 1msec, then try again
        pvg610HostSleep(1000);
        sleepCycles--;
    }

    return PVG610_ETHERNET_TIMEOUT_E;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetFifoStatusGet(BYTE                           deviceIndex,
                                                  BYTE                           modemIndex,
                                                  PVG610_NET_FIFOS_STATUS_STRUCT *pFs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_NET_FIFO_STATUS_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        // get net fifo status
        memcpy((BYTE*)pFs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_NET_FIFOS_STATUS_STRUCT));
    }

    return retVal;
}


PVG610_ERROR_MSG_ENUM PVG610_API_EthernetPauseSet(BYTE      deviceIndex,
                                                  BYTE      modemIndex,
                                                  BYTE      pauseMode)
{
    PVG610_ERROR_MSG_ENUM retVal;

  //  pvg610HostApiMutexGet(deviceIndex);
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&pauseMode,
                                 sizeof(BYTE),
                                 PVG610_ETH_PAUSE_SET_OPCODE_E,
                                 modemIndex);
    
  //  pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}


PVG610_ERROR_MSG_ENUM PVG610_API_EthernetVlanSet(BYTE       deviceIndex,
                                                 BYTE       modemIndex,
                                                 BYTE       lowPriority)
{
    PVG610_ERROR_MSG_ENUM retVal;

 //   pvg610HostApiMutexGet(deviceIndex);
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&lowPriority,
                                 sizeof(BYTE),
                                 PVG610_ETH_VLAN_SET_OPCODE_E,
                                 modemIndex);

 //   pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_EthernetLargeFrameSet(BYTE         deviceIndex,
                                                       BYTE         modemIndex,
                                                       UINT16       macMaxPkt)
{
    PVG610_ERROR_MSG_ENUM retVal;

 //   pvg610HostApiMutexGet(deviceIndex);
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&macMaxPkt,
                                 sizeof(UINT16),
                                 PVG610_ETH_LARGE_FRAME_SET_OPCODE_E,
                                 modemIndex);

  //  pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// Ethernet
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_EthernetInBandControlSet(BYTE      deviceIndex,
                                                          BYTE      modemIndex,
                                                          BYTE      inBandControl)
{
    PVG610_ERROR_MSG_ENUM retVal;

  //  pvg610HostApiMutexGet(deviceIndex);
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&inBandControl,
                                 sizeof(BYTE),
                                 PVG610_ETH_IN_BAND_CONTROL_SET_OPCODE_E,
                                 modemIndex);

   // pvg610HostApiMutexRelease(deviceIndex);
    return retVal;
}




//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Operative Functions (general)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_DeviceReset(BYTE deviceIndex, PVG610_DEVICE_RESET_TYPE_ENUM resetType)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    pvg610HostDeviceReset(deviceIndex, resetType);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION:           PVG610_API_BlockReset                                     //
//                                                                             //
//  PARAMETERS:         BYTE    deviceIndex -   [in] device index              //
//                      BYTE    modemIndex  -   [in] modem index               //
//                      PVG610_BLOCK_RESET_ENUM block- [in] address in the memory     //
//                                                                             //
//  DESCRIPTION:        this function resets an internal block inside the PVG  //
//                                                                             //
//  RETURNS:            PVG610_ERROR_MSG_ENUM                                         //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_BlockReset(BYTE deviceIndex, BYTE modemIndex, PVG610_BLOCK_RESET_ENUM block)
{
     //Send the MSG to the FW
     return pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],         //database - to be filled
                                (BYTE*)&block,                      //block number
                                sizeof(BYTE),                       //size of data
                                PVG610_COM_BLOCK_RESET_OPCODE_E,           //opcode
                                modemIndex);                        //dev index
}

///////////////////////////////////////////////////////////////////////////////
// Actions
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_BlocksHardReset(BYTE deviceIndex, BYTE modemIndex)
{

    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_HARD_RESET_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_LoopbackSet(BYTE                   deviceIndex,
                                             BYTE                   modemIndex,
                                             PVG610_LOOPBACK_STRUCT *lb)
{
    PVG610_ERROR_MSG_ENUM retVal;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
//    retVal = pvg610BuildSendAndReceive1(&gPvg610Database[deviceIndex],
                                 (BYTE *)lb,
                                 sizeof(PVG610_LOOPBACK_STRUCT),
                                 PVG610_COM_LOOPBACK_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}



PVG610_ERROR_MSG_ENUM PVG610_API_LoopbackGet(BYTE deviceIndex,
                BYTE modemIndex, PVG610_LOOPBACK_TYPE_ENUM *loopbackValue,
                 BOOLEAN *loopbackNearEnd, UINT32 *tributaryMask)
{                                                                        
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_LOOPBACK_GET_STRUCT lgs;

 //   pvg610HostApiMutexGet(deviceIndex);

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 0,
                                 0,
                                 PVG610_COM_LOOPBACK_GET_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(&lgs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_LOOPBACK_GET_STRUCT));
        *loopbackValue = lgs.loopbackValue;
        *loopbackNearEnd = lgs.loopbackNearEnd;
        *tributaryMask = lgs.tributaryMask;
    }
 
 //   pvg610HostApiMutexRelease(deviceIndex);

    return retVal;
}



/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_TransmitterModeSet(BYTE                           deviceIndex,
                                                    BYTE                           modemIndex,
                                                    PVG610_TRANSMITTER_MODE_STRUCT *tx)
{
    PVG610_ERROR_MSG_ENUM retVal;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)tx,
                                 sizeof(PVG610_TRANSMITTER_MODE_STRUCT),
                                 PVG610_COM_TRANSMITTER_MODE_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Operative Functions (Modem)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcquireStart(BYTE                                deviceIndex,
                                                   BYTE                                modemIndex,
                                                   PVG610_ACQUIRE_MODE_ENUM            acqMode,
                                                   PVG610_SPECTRAL_INVERSION_MODE_ENUM siMode)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_COM_ACQUIRE_STRUCT  acquireParams;

    acquireParams.acqMode =    acqMode;
    acquireParams.siMode  =    siMode;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&acquireParams,
                                 sizeof(PVG610_COM_ACQUIRE_STRUCT),
                                 PVG610_COM_ACQUIRE_START_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemPreemphasisCoefsSet(BYTE                            deviceIndex,
                                                          BYTE                            modemIndex,
                                                          PVG610_MODEM_PREEMPHASIS_STRUCT *pPs)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)pPs,
                                 sizeof(PVG610_MODEM_PREEMPHASIS_STRUCT),
                                 PVG610_COM_MODEM_PREEMPHASIS_COEFS_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemPredistortionCoefsSet(BYTE                              deviceIndex,
                                                            BYTE                              modemIndex,
                                                            PVG610_MODEM_PREDISTORTION_STRUCT *pPs)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)pPs,
                                 sizeof(PVG610_MODEM_PREDISTORTION_STRUCT),
                                 PVG610_COM_MODEM_PREDISTORTION_COEFS_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_TxByteClkSync(BYTE deviceIndex, BYTE modemIndex)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_SYNC_TX_BYTE_CLK_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
// xpic delay
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_XpicDelaySet(BYTE deviceIndex,
                                    BYTE modemIndex,
                                    BYTE delay)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&delay,
                                 sizeof(BYTE),
                                 PVG610_COM_XPIC_DELAY_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// set the xpic slave mute/unmute
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_XpicSlaveMuteSet (BYTE deviceIndex, BYTE modemIndex, BOOLEAN mute)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&mute,
                                 sizeof(BYTE),
                                 PVG610_COM_MODEM_XPIC_SLAVE_MUTE_SET_OPCODE_E,
                                 modemIndex);

    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
// preamble set (0 or 1)
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_PreambleSet(BYTE deviceIndex,
                                             BYTE modemIndex,
                                             BYTE index)
{
    PVG610_ERROR_MSG_ENUM retVal;

    if (index > 1)
    {
        return PVG610_INVALID_PARAMS_E;
    }

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&index,
                                 sizeof(BYTE),
                                 PVG610_COM_PREAMBLE_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// IQ delay set
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_IqDelaySet(BYTE  deviceIndex,
                                                  BYTE modemIndex,
                                                  PVG610_IQ_DELAY_MODE_ENUM mode,
                                                  BYTE  fdfTableIndex,
                                                  INT16 fdfIntDelay)
{
    PVG610_ERROR_MSG_ENUM retVal;
const INT16 pvg610FdfTable[] ={
    0, 0,0,0,0,0,0,2047,0,0,0,0,0,0
    ,0, 0,0,-1,2,-6,16,2045,-12,4,-1,0,0,0
    ,0, 0,0,-2,5,-13,32,2042,-24,7,-2,1,0,0
    ,0, 0,1,-3,7,-19,49,2039,-36,11,-3,1,0,0
    ,0, 0,1,-3,10,-25,66,2036,-48,15,-4,1,0,0
    ,0, 0,1,-4,13,-31,83,2032,-59,18,-6,1,0,0
    ,0, 0,1,-5,15,-38,100,2028,-71,22,-7,2,0,0
    ,0, 0,2,-6,18,-44,117,2024,-82,25,-8,2,0,0
    ,0, 0,2,-7,20,-51,135,2019,-92,29,-9,2,0,0
    ,0, 0,2,-8,23,-57,152,2014,-103,32,-10,2,0,0
    ,0, 0,2,-8,25,-63,170,2008,-113,35,-11,3,-1,0
    ,0, 0,2,-9,28,-70,188,2002,-123,38,-12,3,-1,0
    ,0, -1,3,-10,30,-76,207,1996,-133,42,-13,3,-1,0
    ,0, -1,3,-11,33,-83,225,1990,-143,45,-14,3,-1,0
    ,0, -1,3,-12,35,-89,243,1983,-152,48,-15,4,-1,0
    ,0, -1,3,-13,37,-96,262,1975,-161,51,-16,4,-1,0
    ,0, -1,4,-13,40,-102,281,1968,-170,54,-17,4,-1,0
    ,0, -1,4,-14,42,-108,300,1960,-179,57,-18,4,-1,0
    ,0, -1,4,-15,45,-115,319,1951,-187,60,-19,5,-1,0
    ,0, -1,4,-16,47,-121,339,1943,-195,63,-19,5,-1,0
    ,0, -1,4,-17,50,-127,358,1934,-203,65,-20,5,-1,0
    ,0, -1,5,-17,52,-134,378,1924,-211,68,-21,5,-1,0
    ,0, -1,5,-18,54,-140,397,1915,-218,71,-22,6,-1,0
    ,0, -1,5,-19,57,-146,417,1905,-226,73,-23,6,-1,0
    ,0, -1,5,-20,59,-152,437,1894,-233,76,-24,6,-1,0
    ,0, -1,5,-21,61,-159,457,1884,-239,78,-24,6,-1,0
    ,0, -1,6,-21,63,-165,477,1873,-246,81,-25,6,-1,0
    ,0, -1,6,-22,66,-171,498,1861,-252,83,-26,7,-1,0
    ,0, -1,6,-23,68,-177,518,1850,-258,85,-27,7,-1,0
    ,0, -1,6,-23,70,-183,538,1838,-264,87,-27,7,-1,0
    ,0, -1,6,-24,72,-188,559,1826,-270,89,-28,7,-1,0
    ,0, -1,7,-25,74,-194,579,1813,-275,91,-29,7,-1,0
    ,0, -1,7,-25,76,-200,600,1800,-280,93,-29,7,-1,0
    ,0, -1,7,-26,78,-206,621,1787,-285,95,-30,8,-1,0
    ,0, -1,7,-27,80,-211,642,1774,-290,97,-31,8,-1,0
    ,0, -1,7,-27,82,-217,662,1760,-294,99,-31,8,-1,0
    ,0, -1,7,-28,84,-222,683,1746,-298,100,-32,8,-2,0
    ,0, -1,8,-29,86,-228,704,1732,-302,102,-32,8,-2,0
    ,0, -1,8,-29,88,-233,725,1717,-306,104,-33,8,-2,0
    ,0, -1,8,-30,90,-238,746,1703,-309,105,-33,9,-2,0
    ,0, -2,8,-30,92,-243,767,1688,-313,106,-34,9,-2,0
    ,0, -2,8,-31,93,-248,788,1672,-316,108,-34,9,-2,0
    ,0, -2,8,-31,95,-253,809,1657,-318,109,-35,9,-2,0
    ,0, -2,8,-32,97,-258,830,1641,-321,110,-35,9,-2,0
    ,0, -2,8,-32,98,-262,851,1625,-323,111,-35,9,-2,0
    ,0, -2,9,-33,100,-267,872,1609,-326,112,-36,9,-2,0
    ,0, -2,9,-33,101,-271,893,1593,-327,113,-36,9,-2,0
    ,0, -2,9,-34,103,-276,914,1576,-329,114,-36,9,-2,0
    ,0, -2,9,-34,104,-280,935,1559,-331,115,-37,9,-2,0
    ,0, -2,9,-35,105,-284,956,1542,-332,116,-37,10,-2,0
    ,0, -2,9,-35,107,-288,977,1525,-333,116,-37,10,-2,0
    ,0, -2,9,-35,108,-292,998,1507,-334,117,-37,10,-2,0
    ,0, -2,9,-36,109,-295,1019,1489,-335,117,-38,10,-2,0
    ,0, -2,9,-36,110,-299,1040,1471,-335,118,-38,10,-2,0
    ,0, -2,9,-36,111,-302,1060,1453,-335,118,-38,10,-2,0
    ,0, -2,10,-37,112,-305,1081,1435,-335,118,-38,10,-2,0
    ,0, -2,10,-37,113,-308,1102,1416,-335,119,-38,10,-2,0
    ,0, -2,10,-37,114,-311,1122,1398,-335,119,-38,10,-2,0
    ,0, -2,10,-37,114,-314,1143,1379,-334,119,-38,10,-2,0
    ,0, -2,10,-38,115,-317,1163,1360,-334,119,-38,10,-2,0
    ,0, -2,10,-38,116,-319,1183,1341,-333,119,-38,10,-2,0
    ,0, -2,10,-38,116,-322,1203,1322,-332,119,-38,10,-2,0
    ,0, -2,10,-38,117,-324,1223,1302,-331,118,-38,10,-2,0
    ,0, -2,10,-38,117,-326,1243,1283,-329,118,-38,10,-2,0
    ,0, -2,10,-38,118,-327,1263,1263,-327,118,-38,10,-2,0
    ,0, -2,10,-38,118,-329,1283,1243,-326,117,-38,10,-2,0
    ,0, -2,10,-38,118,-331,1302,1223,-324,117,-38,10,-2,0
    ,0, -2,10,-38,119,-332,1322,1203,-322,116,-38,10,-2,0
    ,0, -2,10,-38,119,-333,1341,1183,-319,116,-38,10,-2,0
    ,0, -2,10,-38,119,-334,1360,1163,-317,115,-38,10,-2,0
    ,0, -2,10,-38,119,-334,1379,1143,-314,114,-37,10,-2,0
    ,0, -2,10,-38,119,-335,1398,1122,-311,114,-37,10,-2,0
    ,0, -2,10,-38,119,-335,1416,1102,-308,113,-37,10,-2,0
    ,0, -2,10,-38,118,-335,1435,1081,-305,112,-37,10,-2,0
    ,0, -2,10,-38,118,-335,1453,1060,-302,111,-36,9,-2,0
    ,0, -2,10,-38,118,-335,1471,1040,-299,110,-36,9,-2,0
    ,0, -2,10,-38,117,-335,1489,1019,-295,109,-36,9,-2,0
    ,0, -2,10,-37,117,-334,1507,998,-292,108,-35,9,-2,0
    ,0, -2,10,-37,116,-333,1525,977,-288,107,-35,9,-2,0
    ,0, -2,10,-37,116,-332,1542,956,-284,105,-35,9,-2,0
    ,0, -2,9,-37,115,-331,1559,935,-280,104,-34,9,-2,0
    ,0, -2,9,-36,114,-329,1576,914,-276,103,-34,9,-2,0
    ,0, -2,9,-36,113,-327,1593,893,-271,101,-33,9,-2,0
    ,0, -2,9,-36,112,-326,1609,872,-267,100,-33,9,-2,0
    ,0, -2,9,-35,111,-323,1625,851,-262,98,-32,8,-2,0
    ,0, -2,9,-35,110,-321,1641,830,-258,97,-32,8,-2,0
    ,0, -2,9,-35,109,-318,1657,809,-253,95,-31,8,-2,0
    ,0, -2,9,-34,108,-316,1672,788,-248,93,-31,8,-2,0
    ,0, -2,9,-34,106,-313,1688,767,-243,92,-30,8,-2,0
    ,0, -2,9,-33,105,-309,1703,746,-238,90,-30,8,-1,0
    ,0, -2,8,-33,104,-306,1717,725,-233,88,-29,8,-1,0
    ,0, -2,8,-32,102,-302,1732,704,-228,86,-29,8,-1,0
    ,0, -2,8,-32,100,-298,1746,683,-222,84,-28,7,-1,0
    ,0, -1,8,-31,99,-294,1760,662,-217,82,-27,7,-1,0
    ,0, -1,8,-31,97,-290,1774,642,-211,80,-27,7,-1,0
    ,0, -1,8,-30,95,-285,1787,621,-206,78,-26,7,-1,0
    ,0, -1,7,-29,93,-280,1800,600,-200,76,-25,7,-1,0
    ,0, -1,7,-29,91,-275,1813,579,-194,74,-25,7,-1,0
    ,0, -1,7,-28,89,-270,1826,559,-188,72,-24,6,-1,0
    ,0, -1,7,-27,87,-264,1838,538,-183,70,-23,6,-1,0
    ,0, -1,7,-27,85,-258,1850,518,-177,68,-23,6,-1,0
    ,0, -1,7,-26,83,-252,1861,498,-171,66,-22,6,-1,0
    ,0, -1,6,-25,81,-246,1873,477,-165,63,-21,6,-1,0
    ,0, -1,6,-24,78,-239,1884,457,-159,61,-21,5,-1,0
    ,0, -1,6,-24,76,-233,1894,437,-152,59,-20,5,-1,0
    ,0, -1,6,-23,73,-226,1905,417,-146,57,-19,5,-1,0
    ,0, -1,6,-22,71,-218,1915,397,-140,54,-18,5,-1,0
    ,0, -1,5,-21,68,-211,1924,378,-134,52,-17,5,-1,0
    ,0, -1,5,-20,65,-203,1934,358,-127,50,-17,4,-1,0
    ,0, -1,5,-19,63,-195,1943,339,-121,47,-16,4,-1,0
    ,0, -1,5,-19,60,-187,1951,319,-115,45,-15,4,-1,0
    ,0, -1,4,-18,57,-179,1960,300,-108,42,-14,4,-1,0
    ,0, -1,4,-17,54,-170,1968,281,-102,40,-13,4,-1,0
    ,0, -1,4,-16,51,-161,1975,262,-96,37,-13,3,-1,0
    ,0, -1,4,-15,48,-152,1983,243,-89,35,-12,3,-1,0
    ,0, -1,3,-14,45,-143,1990,225,-83,33,-11,3,-1,0
    ,0, -1,3,-13,42,-133,1996,207,-76,30,-10,3,-1,0
    ,0, -1,3,-12,38,-123,2002,188,-70,28,-9,2,0,0
    ,0, -1,3,-11,35,-113,2008,170,-63,25,-8,2,0,0
    ,0, 0,2,-10,32,-103,2014,152,-57,23,-8,2,0,0
    ,0, 0,2,-9,29,-92,2019,135,-51,20,-7,2,0,0
    ,0, 0,2,-8,25,-82,2024,117,-44,18,-6,2,0,0
    ,0, 0,2,-7,22,-71,2028,100,-38,15,-5,1,0,0
    ,0, 0,1,-6,18,-59,2032,83,-31,13,-4,1,0,0
    ,0, 0,1,-4,15,-48,2036,66,-25,10,-3,1,0,0
    ,0, 0,1,-3,11,-36,2039,49,-19,7,-3,1,0,0
    ,0, 0,1,-2,7,-24,2042,32,-13,5,-2,0,0,0
    ,0, 0,0,-1,4,-12,2045,16,-6,2,-1,0,0,0
};
    
    
    
    const INT16  *pFdfTable = pvg610FdfTable;
    PVG610_IQ_DELAY_STRUCT iqDelay;

    if (fdfTableIndex >= sizeof(pvg610FdfTable)/(14*sizeof(UINT16)))
    {
        return PVG610_INVALID_PARAMS_E;
    }

    iqDelay.mode = (BYTE)mode;
    iqDelay.fdfIntDelay = fdfIntDelay;

    // calc the place of the index in fdf table
    pFdfTable += 14 * fdfTableIndex;

    memcpy((BYTE*)iqDelay.fdfValues, (BYTE*)pFdfTable, 14 * sizeof(UINT16));

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&iqDelay,
                                 sizeof(PVG610_IQ_DELAY_STRUCT),
                                 PVG610_COM_IQ_DELAY_SET_OPCODE_E,
                                 modemIndex);

    return retVal;
}

// set the UnsolicitedUartMsgs parameters
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_UnsolicitedUartMsgsSet (BYTE deviceIndex, 
                                                         BYTE modemIndex, 
                                                         BYTE eventsMask, 
                                                         BYTE periodicTimerIn50MsecUnits)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_UNSOLICITED_UART_MSGS_STRUCT unsolicitedUartMsgs;

    unsolicitedUartMsgs.eventsMask = eventsMask;
    unsolicitedUartMsgs.periodicTimerIn50MsecUnits = periodicTimerIn50MsecUnits;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&unsolicitedUartMsgs,
                                 sizeof(PVG610_UNSOLICITED_UART_MSGS_STRUCT),
                                 PVG610_COM_UNSOLICITED_UART_MSGS_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
// set the rx frequency offset
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_RxFreqOffsetSet(BYTE  deviceIndex,
                                                 BYTE  modemIndex,
                                                 INT32 offsetInKHz)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&offsetInKHz,
                                 sizeof(INT32),
                                 PVG610_COM_MODEM_RX_FREQ_OFFSET_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// set the tx frequency offset
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_TxFreqOffsetSet(BYTE  deviceIndex,
                                                 BYTE  modemIndex,
                                                 INT32 offsetInKHz)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&offsetInKHz,
                                 sizeof(INT32),
                                 PVG610_COM_MODEM_TX_FREQ_OFFSET_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Operative Functions (ACM)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmEngineEnable(BYTE    deviceIndex,
                                                      BYTE    modemIndex,
                                                      BOOLEAN enableRx,
                                                      BOOLEAN enableTx)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_ACM_ENABLE_STRUCT    enableTxRx;

    enableTxRx.enableRx = enableRx;
    enableTxRx.enableTx = enableTx;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&enableTxRx,
                                 sizeof(PVG610_ACM_ENABLE_STRUCT),
                                 PVG610_COM_ACM_ENGINE_ENABLE_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmProfileEnable(BYTE   deviceIndex,
                                                       BYTE   modemIndex,
                                                       UINT16 profilesMask)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&profilesMask,
                                 sizeof(UINT16),
                                 PVG610_COM_ACM_PROFILE_ENABLE_OPCODE_E,
                                 modemIndex);

    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_ModemGpmDynamicAllocationSet (BYTE   deviceIndex,
                                                    BYTE   modemIndex,
                                                    UINT32 profile, 
                                                    UINT32 gpiBwKbps, 
                                                    UINT32 ethBwKbps, 
                                                    UINT32 pdhMask)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_ACM_GPM_DYNAMIC_ALLOCATION_SET_STRUCT   acmGpmDynamicAllocationParams;

    acmGpmDynamicAllocationParams.profile = profile;
    acmGpmDynamicAllocationParams.gpiBwKbps = gpiBwKbps;
    acmGpmDynamicAllocationParams.ethBwKbps = ethBwKbps;
    acmGpmDynamicAllocationParams.pdhMask = pdhMask;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&acmGpmDynamicAllocationParams,
                                 sizeof(PVG610_ACM_GPM_DYNAMIC_ALLOCATION_SET_STRUCT),
                                 PVG610_COM_ACM_GPM_DYNAMIC_ALLOCATION_SET_OPCODE,
                                 modemIndex);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmSwitch(BYTE                    deviceIndex,
                                                BYTE                    modemIndex,
                                                PVG610_ACM_PROFILE_ENUM acmProfile,
                                                BOOLEAN                 isLocal)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_COM_ACM_SWITCH_STRUCT       acmSwitchParam;

    acmSwitchParam.acmProfile = (BYTE)acmProfile;
    acmSwitchParam.isLocal    = isLocal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&acmSwitchParam,
                                 sizeof(PVG610_COM_ACM_SWITCH_STRUCT),
                                 PVG610_COM_ACM_SWITCH_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmImproveIfNeeded(BYTE   deviceIndex,
                                                         BYTE   modemIndex)

{
    return pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 0,
                                 0,
                                 PVG610_COM_ACM_IMPROVE_OPCODE_E,
                                 modemIndex);
}



/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmTddSwitch(BYTE                     deviceIndex,
                                                  BYTE                      modemIndex,
                                                  PVG610_ACM_PROFILE_ENUM   localAcmProfile,
                                                  PVG610_ACM_PROFILE_ENUM   remoteAcmProfile)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_COM_ACM_TDD_SWITCH_STRUCT       acmTddSwitchParam;

    acmTddSwitchParam.localAcmProfile   = (BYTE)localAcmProfile;
    acmTddSwitchParam.remoteAcmProfile  = (BYTE)remoteAcmProfile;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&acmTddSwitchParam,
                                 sizeof(PVG610_COM_ACM_TDD_SWITCH_OPCODE_E),
                                 PVG610_COM_ACM_TDD_SWITCH_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// set acm Engine Threshold value
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmThresholdSet ( BYTE                     deviceIndex, 
                                                        BYTE                     modemIndex,
                                                        PVG610_ACM_TABLE_ENUM    engineTable, 
                                                        PVG610_ACM_PROFILE_ENUM  profile, 
                                                        INT16                    mseTenthsVal, 
                                                        BYTE                     ldpcMantissaTenths,
                                                        BYTE                     ldpcExponent,
                                                        PVG610_ACM_CRITERIA_ENUM criteria, 
                                                        PVG610_ACM_PROFILE_ENUM  nextProfile)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_ACM_THRESHOLD_SET_STRUCT acmThresholdSetStruct;

    acmThresholdSetStruct.isChannelImproveTable = (BOOLEAN)engineTable;
    acmThresholdSetStruct.profile               = (BYTE)profile;
    acmThresholdSetStruct.mseTenthsVal          = mseTenthsVal;
    acmThresholdSetStruct.ldpcMantissaTenths    = ldpcMantissaTenths;
    acmThresholdSetStruct.ldpcExponent          = ldpcExponent;
    acmThresholdSetStruct.criteria              = (BYTE)criteria;
    acmThresholdSetStruct.nextProfile           = (BYTE)nextProfile;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&acmThresholdSetStruct,
                                 sizeof(PVG610_ACM_THRESHOLD_SET_STRUCT),
                                 PVG610_COM_ACM_THRESHOLD_SET_E,
                                 modemIndex);
    return retVal;

}
 /*
/////////////////////////////////////////////////////////////////////////////////
// Get ACM Engine Threshold value
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ModemAcmThresholdGet (BYTE                     deviceIndex, 
                                                       BYTE                     modemIndex, 
                                                       PVG610_ACM_TABLE_ENUM    engineTable, 
                                                       PVG610_ACM_PROFILE_ENUM  profile, 
                                                       INT16                    *mseTenthsVal, 
                                                       BYTE                     *ldpcMantissaTenths, 
                                                       BYTE                     *ldpcExponent, 
                                                       PVG610_ACM_CRITERIA_ENUM *criteria, 
                                                       PVG610_ACM_PROFILE_ENUM  *nextProfile)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    PVG610_ACM_THRESHOLD_STRUCT acmThresholdGetStruct;

    acmThresholdGetStruct.isChannelImproveTable = (BOOLEAN)engineTable;
    acmThresholdGetStruct.profile               = (BYTE)profile;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&acmThresholdGetStruct,
                                 sizeof(PVG610_ACM_THRESHOLD_STRUCT),
                                 PVG610_COM_ACM_THRESHOLD_GET_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(&acmThresholdGetStruct, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_ACM_THRESHOLD_STRUCT));
        *mseTenthsVal       = acmThresholdGetStruct.mseTenthsVal;
        *ldpcMantissaTenths = acmThresholdGetStruct.ldpcMantissaTenths;
        *ldpcExponent       = acmThresholdGetStruct.ldpcExponent;
        *criteria           = acmThresholdGetStruct.criteria;
        *nextProfile        = acmThresholdGetStruct.nextProfile;
    }

    return retVal;
}
     */

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Operative Functions (networking)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1Stm1SignalsForce(BYTE                          deviceIndex,
                                                       BYTE                          modemIndex,
                                                       PVG610_NET_TRIB_INDEX_ENUM    ifIndex,
                                                       PVG610_NET_TEST_SIGNAL_ENUM   signal,
                                                       BOOLEAN                       toTheAir)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_NET_E1_STM1_SIGNALS_FORCE_STRUCT e1Stm1SignalsForce;

    e1Stm1SignalsForce.ifIndex  = ifIndex;
    e1Stm1SignalsForce.signal   = signal;
    e1Stm1SignalsForce.toTheAir = toTheAir;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1Stm1SignalsForce,
                                 sizeof(PVG610_NET_E1_STM1_SIGNALS_FORCE_STRUCT),
                                 PVG610_COM_NET_E1_STM1_SIGNALS_FORCE_E,
                                 modemIndex);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1CableConfig(BYTE                               deviceIndex,
                                                  BYTE                               modemIndex,
                                                  PVG610_NET_TRIB_INDEX_ENUM         e1Index,
                                                  PVG610_NET_E1_CABLE_CONFIG_ENUM    cableConfig)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_NET_E1_CABLE_CONFIG_STRUCT e1CableConfig;

    e1CableConfig.e1Index     = e1Index;
    e1CableConfig.cableConfig = cableConfig;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1CableConfig,
                                 sizeof(PVG610_NET_E1_CABLE_CONFIG_STRUCT),
                                 PVG610_COM_NET_E1_CABLE_CONFIG_E,
                                 modemIndex);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetTributaryHizSet(BYTE deviceIndex, BYTE modemIndex, PVG610_NET_TRIB_INDEX_ENUM ifIndex, BOOLEAN hiz)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_COM_NET_TRIBUTARY_HIZ_SET_STRUCT tributaryHiz;

    tributaryHiz.ifIndex = ifIndex;
    tributaryHiz.hiz     = hiz;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&tributaryHiz,
                                 sizeof(PVG610_COM_NET_TRIBUTARY_HIZ_SET_STRUCT),
                                 PVG610_COM_NET_TRIBUTARY_HIZ_SET_E,
                                 modemIndex);

    return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PrbsMonitorConnect(BYTE                        deviceIndex,
                                                         BYTE                        modemIndex,
                                                         BOOLEAN                     connect,
                                                         PVG610_NET_TRIB_INDEX_ENUM  e1Index,
                                                         BOOLEAN                     fromTheAir)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_COM_NET_PRBS_CONNECT_STRUCT e1PrbsMonitorConnect;

    e1PrbsMonitorConnect.connect    = connect;
    e1PrbsMonitorConnect.ifIndex    = e1Index;
    e1PrbsMonitorConnect.fromTheAir = fromTheAir;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1PrbsMonitorConnect,
                                 sizeof(PVG610_COM_NET_PRBS_CONNECT_STRUCT),
                                 PVG610_COM_NET_E1_PRBS_MONITOR_CONNECT_E,
                                 modemIndex);

    return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PrbsMonitorConnect(BYTE                          deviceIndex,
                                                           BYTE                          modemIndex,
                                                           BOOLEAN                       connect,
                                                           PVG610_NET_TRIB_INDEX_ENUM    stm1Index,
                                                           BOOLEAN                       fromTheAir)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_COM_NET_PRBS_CONNECT_STRUCT stm1PrbsMonitorConnect;

    stm1PrbsMonitorConnect.connect      = connect;
    stm1PrbsMonitorConnect.ifIndex      = stm1Index;
    stm1PrbsMonitorConnect.fromTheAir   = fromTheAir;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&stm1PrbsMonitorConnect,
                                 sizeof(PVG610_COM_NET_PRBS_CONNECT_STRUCT),
                                 PVG610_COM_NET_STM1_PRBS_MONITOR_CONNECT_E,
                                 modemIndex);

    return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetE1PrbsGeneratorConnect(BYTE                       deviceIndex,
                                                          BYTE                        modemIndex,
                                                          BOOLEAN                     connect,
                                                          PVG610_NET_TRIB_INDEX_ENUM  e1Index,
                                                          BOOLEAN                     fromTheAir)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_COM_NET_PRBS_CONNECT_STRUCT e1PrbsGeneratorConnect;

    e1PrbsGeneratorConnect.connect    = connect;
    e1PrbsGeneratorConnect.ifIndex    = e1Index;
    e1PrbsGeneratorConnect.fromTheAir = fromTheAir;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&e1PrbsGeneratorConnect,
                                 sizeof(PVG610_COM_NET_PRBS_CONNECT_STRUCT),
                                 PVG610_COM_NET_E1_PRBS_GENERATOR_CONNECT_E,
                                 modemIndex);

    return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetStm1PrbsGeneratorConnect(BYTE                          deviceIndex,
                                                             BYTE                          modemIndex,
                                                             BOOLEAN                       connect,
                                                             PVG610_NET_TRIB_INDEX_ENUM    stm1Index,
                                                             BOOLEAN                       fromTheAir)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_COM_NET_PRBS_CONNECT_STRUCT stm1PrbsGeneratorConnect;

    stm1PrbsGeneratorConnect.connect      = connect;
    stm1PrbsGeneratorConnect.ifIndex      = stm1Index;
    stm1PrbsGeneratorConnect.fromTheAir   = fromTheAir;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&stm1PrbsGeneratorConnect,
                                 sizeof(PVG610_COM_NET_PRBS_CONNECT_STRUCT),
                                 PVG610_COM_NET_STM1_PRBS_GENERATOR_CONNECT_E,
                                 modemIndex);

    return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetGpiPrbsGeneratorCommand (BYTE                        deviceIndex,
                                                             BYTE                        modemIndex,
                                                             PVG610_GPI_BER_COMMAND_ENUM        command)
{
    PVG610_ERROR_MSG_ENUM retVal;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                       (BYTE*)&command,
                                       1,
                                       PVG610_COM_NET_GPI_PRBS_GENERATOR_COMMAND_E,
                                       modemIndex);
    return retVal;
}
   
////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetGpiErrorsGet (BYTE                                      deviceIndex,
                                                  BYTE                                      modemIndex,
                                                  PVG610_NET_PRBS_GPI_ERRORS_INFO_STRUCT    *pGpi)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                       NULL,
                                       0,
                                       PVG610_COM_NET_GPI_ERRORS_GET_E,
                                       modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy ((BYTE*)pGpi, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_NET_PRBS_GPI_ERRORS_INFO_STRUCT));
    }

    return retVal;
}
 
////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetPrbsErrorsGet (BYTE                   deviceIndex,
                                         BYTE                   modemIndex,
                                         PVG610_NET_PRBS_ERRORS_STRUCT *pPrbs)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                       NULL,
                                       0,
                                       PVG610_COM_NET_PRBS_ERRORS_GET_E,
                                       modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy ((BYTE*)pPrbs, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_NET_PRBS_ERRORS_STRUCT));
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_NetEthParamsSet(BYTE                           deviceIndex,
                                                 BYTE                           modemIndex,
                                                 PVG610_NET_ETH_STATUS_STRUCT   *pEs)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)pEs,
                                 sizeof(PVG610_NET_ETH_STATUS_STRUCT),
                                 PVG610_COM_NET_ETH_PARAMS_SET_OPCODE_E,
                                 modemIndex);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// Networking operative Functions
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_MailboxMessageSend(BYTE deviceIndex, BYTE modemIndex, PVG610_MAILBOX_MESSAGE_STRUCT *pMbx)
{
    PVG610_ERROR_MSG_ENUM retVal;

//    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
    retVal = pvg610BuildSendAndReceive1(&gPvg610Database[deviceIndex],
                                 (BYTE *)pMbx,
                                 pMbx->msgLen + sizeof(pMbx->msgLen),
                                 PVG610_COM_MAILBOX_MESSAGE_SEND_OPCODE_E,
                                 modemIndex);
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_MailboxMessageReceive(BYTE deviceIndex, BYTE modemIndex, PVG610_MAILBOX_MESSAGE_STRUCT *pMbx)
{
    PVG610_ERROR_MSG_ENUM retVal;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
   // printf("\n\r received!");
        memcpy ((BYTE*)pMbx, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(PVG610_MAILBOX_MESSAGE_STRUCT));
    }
 //   else{ /* Body */
   // printf("\n\r is do not receive!");
//   } /* Endbody */

    return retVal;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Operative Functions (protection)
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionTxModeSet (BYTE                        deviceIndex,
                                                      BYTE                        modemIndex,
                                                      PVG610_PROTECTION_MODE_ENUM protectionMode,
                                                      BYTE                        phyId,
                                                      BOOLEAN                     copyAcmFormWorking)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_PROTECTION_TX_MODE_STRUCT protectionTxModeSet;
#ifdef TEST_PROT    
#ifdef USART0_TRY_PDC_1T	
 printfp("\n\r PVG610_API_ProtectionTxModeSet");
 printfpd(" %d", deviceIndex);
 printfp(" protectionMode: ");
 printfpd("%d", protectionMode);
 printfp(" phyId: ");
 printfpd("%d", phyId);
 
#endif
#endif      
    protectionTxModeSet.protectionMode      = (BYTE)protectionMode;
    protectionTxModeSet.phyId               = phyId;
    protectionTxModeSet.copyAcmFormWorking  = (BYTE)copyAcmFormWorking;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&protectionTxModeSet,
                                 sizeof(PVG610_PROTECTION_TX_MODE_STRUCT),
                                 PVG610_COM_PROTECTION_TX_MODE_SET_E,
                                 modemIndex);
 /*                                
#ifdef USART0_TRY_PDC_1T	
 printfp("...");
 printfpd("%d", retVal);
#endif
  */                               
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionRxModeSet (BYTE                        deviceIndex,
                                                      BYTE                        modemIndex,
                                                      PVG610_PROTECTION_MODE_ENUM protectionMode,
                                                      BYTE                        phyId)
{
    PVG610_ERROR_MSG_ENUM retVal;
    PVG610_PROTECTION_RX_MODE_STRUCT protectionRxModeSet;
#ifdef TEST_PROT     
#ifdef USART0_TRY_PDC_1T	
 printfp("\n\r PVG610_API_ProtectionRxModeSet");
 printfpd(" %d", deviceIndex);
 printfp(" protectionMode: ");
 printfpd("%d", protectionMode);
 printfp(" phyId: ");
 printfpd("%d", phyId);
 
#endif
#endif     

    protectionRxModeSet.protectionMode      = (BYTE)protectionMode;
    protectionRxModeSet.phyId               = phyId;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&protectionRxModeSet,
                                 sizeof(PVG610_PROTECTION_RX_MODE_STRUCT),
                                 PVG610_COM_PROTECTION_RX_MODE_SET_E,
                                 modemIndex);
  /*                               
#ifdef USART0_TRY_PDC_1T	
 printfp("...");
 printfpd("%d", retVal);
#endif
     */                            
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionRxForceSet (BYTE                        deviceIndex,
                                                       BYTE                        modemIndex,
                                                       PVG610_PROTECTION_MODE_ENUM protectionMode)
{
    PVG610_ERROR_MSG_ENUM retVal;
   /* 
#ifdef USART0_TRY_PDC_1T	
 printfp("\n\r PVG610_API_ProtectionRxForceSet");
 printfpd(" %d", deviceIndex);
 printfp(" protectionMode: ");
 printfpd(" %d", protectionMode);
#endif
       */

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&protectionMode,
                                 sizeof(BYTE),
                                 PVG610_COM_PROTECTION_RX_FORCE_SET_E,
                                 modemIndex);
  /*                               
#ifdef USART0_TRY_PDC_1T	
 printfp("...");
 printfpd("%d", retVal);
#endif
       */                          
    return retVal;
}

PVG610_ERROR_MSG_ENUM PVG610_API_ProtectionSysModeSet (BYTE                        deviceIndex,
                                                       BYTE                        modemIndex,
                                                       BOOLEAN                     enable)
{
    PVG610_ERROR_MSG_ENUM   retVal;
    BYTE                    byteEnable;

    byteEnable = (BYTE)enable;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&byteEnable,
                                 sizeof(BYTE),
                                 PVG610_COM_PROTECTION_SYS_MODE_SET_E,
                                 modemIndex);
    return retVal;
}




//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Peripheral Access Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610PeripheralTransaction
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610PeripheralTransaction(BYTE                   deviceIndex,
                                                  BYTE                   slaveAddress,
                                                  BYTE                   *txBuffer,
                                                  BYTE                   txBufferLen,
                                                  BYTE                   *rxBuffer,
                                                  BYTE                   rxBufferLen,
                                                  BYTE                   dataFrameSize,
                                                  BYTE                   phasePolarity,
                                                  BYTE                   frequency,
                                                  PVG610_COM_OPCODE_ENUM startTransactionOpcode,
                                                  PVG610_COM_OPCODE_ENUM isTransactionCompleteOpcode,
                                                  UINT32                 sleepTimeInMili,
                                                  UINT32                 timeoutInMili,
                                                  BYTE                   maxAddress)
{
    PVG610_ERROR_MSG_ENUM           retVal;
    UINT32                          sleepCycles;
    PVG610_PERIPHERAL_RX_STRUCT     *rxPeripheral;
    UINT32                  len,    sleepInUsec = sleepTimeInMili * 1000;
    PVG610_PERIPHERAL_TX_STRUCT     peripheral;

    if (((INT32)txBufferLen + (INT32)rxBufferLen > PVG610_PERIPHERAL_BUFFER_MAX_LEN))
    {
        return PVG610_PERIPHERAL_TOO_MANY_BYTES_E;
    }
    if (((INT32)txBufferLen + (INT32)rxBufferLen == 0))
    {
        return PVG610_PERIPHERAL_TRANSACTION_LEN_CANNOT_BE_ZERO_E;
    }
    if (slaveAddress > maxAddress)
    {
        return PVG610_PERIPHERAL_INVALID_SLAVE_ADDRESS_E;
    }

    peripheral.dataFrameSize = dataFrameSize;
    peripheral.phasePolarity = phasePolarity;
    peripheral.frequency     = frequency;
    peripheral.slaveAddress  = slaveAddress;
    peripheral.txBufferLen   = txBufferLen;
    peripheral.rxBufferLen   = rxBufferLen;
    memcpy((BYTE*)peripheral.txBuffer, txBuffer, txBufferLen);
    len = 6 + txBufferLen; // get size of header + the tx buffer size
          
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&peripheral,
                                 len,
                                 startTransactionOpcode,
                                 0);

    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    // get pointer to the start of the data
    rxPeripheral = (PVG610_PERIPHERAL_RX_STRUCT*)&gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN];

    // wait till transaction is complete
    sleepCycles = timeoutInMili / sleepTimeInMili;

    while (sleepCycles > 0)
    {
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     NULL,
                                     0,
                                     isTransactionCompleteOpcode,
                                     0);

        // if error or transaction completed (first rx byte is true) exit
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }

        // if transaction complete copy rx buffer and exit
        if (rxPeripheral->transactionComplete)
        {
            // copy rx buffer
            memcpy ((BYTE*)rxBuffer, (BYTE*)rxPeripheral->rxBuffer, rxBufferLen);

            return PVG610_SUCCESS_MSG_E;
        }

        // sleep a bit
        pvg610HostSleep(sleepInUsec);

        sleepCycles--;
    }

    return PVG610_PERIPHERAL_TIMEOUT_E;
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_I2CTransaction
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_I2CTransaction(BYTE                      deviceIndex,
                                                BYTE                      slaveAddress,
                                                BYTE                      *txBuffer,
                                                BYTE                      txBufferLen,
                                                BYTE                      *rxBuffer,
                                                BYTE                      rxBufferLen,
                                                PVG610_I2C_FREQUENCY_ENUM frequency)
{
    return pvg610PeripheralTransaction(deviceIndex,
                                       slaveAddress,
                                       txBuffer,
                                       txBufferLen,
                                       rxBuffer,
                                       rxBufferLen,
                                       0, // not relevant
                                       0, // not relevant
                                       (BYTE)frequency,
                                       PVG610_COM_I2C_TRANSACTION_START_OPCODE_E,
                                       PVG610_COM_I2C_IS_TRANSACTION_COMPLETE_OPCODE_E,
                                       PVG610_I2C_SLEEP_BEFORE_POLLING_IN_MS,
                                       PVG610_I2C_TIMEOUT_IN_MS,
                                       0x7F);
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_SPITransaction
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_SPITransaction(BYTE                            deviceIndex,
                                                BYTE                            slaveAddress,
                                                BYTE                            *txBuffer,
                                                BYTE                            txBufferLen,
                                                BYTE                            *rxBuffer,
                                                BYTE                            rxBufferLen,
                                                PVG610_SPI_DATA_FRAME_SIZE_ENUM dataFrameSize,
                                                PVG610_SPI_PHASE_POLARITY_ENUM  phasePolarity,
                                                PVG610_SPI_FREQUENCY_ENUM       frequency)
{

    return pvg610PeripheralTransaction(deviceIndex,
                                       slaveAddress,
                                       txBuffer,
                                       txBufferLen,
                                       rxBuffer,
                                       rxBufferLen,
                                       (BYTE)dataFrameSize,
                                       (BYTE)phasePolarity,
                                       (BYTE)frequency,
                                       PVG610_COM_SPI_TRANSACTION_START_OPCODE_E,
                                       PVG610_COM_SPI_IS_TRANSACTION_COMPLETE_OPCODE_E,
                                       PVG610_SPI_SLEEP_BEFORE_POLLING_IN_MS,
                                       PVG610_SPI_TIMEOUT_IN_MS,
                                       0x7);
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_GPIOIntConfig
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_GPIOIntConfig(BYTE                      deviceIndex,
                                               BYTE                      bitIndex,
                                               PVG610_GPIO_INT_ENUM      intType)

{
    PVG610_ERROR_MSG_ENUM          retVal;
    PVG610_GPIO_INT_CONFIG_STRUCT  gpioIntConfigParams;

    gpioIntConfigParams.bitIndex = bitIndex;
    gpioIntConfigParams.intType  = (BYTE)intType;


    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&gpioIntConfigParams,
                                 sizeof(PVG610_GPIO_INT_CONFIG_STRUCT),
                                 PVG610_GPIO_INT_CONFIG_OPCODE_E,
                                 0);

    return retVal;
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_GPIORead
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_GPIORead(BYTE    deviceIndex,
                                          UINT16  mask,
                                          UINT16  *readData)
{
    PVG610_ERROR_MSG_ENUM          retVal;
    PVG610_GPIO_WRITE_STRUCT       gpioReadParams;

    gpioReadParams.mask = mask;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&gpioReadParams,
                                 sizeof(PVG610_GPIO_READ_STRUCT),
                                 PVG610_GPIO_READ_OPCODE_E,
                                 0);
    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy(readData, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], sizeof(UINT16));
    }
    return retVal;
}

///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: PVG610_API_GPIOWrite
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_GPIOWrite(BYTE   deviceIndex,
                                           UINT16 mask,
                                           UINT16 data)
{
    PVG610_ERROR_MSG_ENUM          retVal;
    PVG610_GPIO_WRITE_STRUCT       gpioWriteParams;

    gpioWriteParams.mask = mask;
    gpioWriteParams.data = data;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&gpioWriteParams,
                                 sizeof(PVG610_GPIO_WRITE_STRUCT),
                                 PVG610_GPIO_WRITE_OPCODE_E,
                                 0);
    return retVal;
}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
// Debug Functions
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_GeneralControlSet(BYTE      deviceIndex,
                                                   BYTE      modemIndex,
                                                   UINT32    opcode,
                                                   BYTE      length,
                                                   BYTE      *data)
{
    PVG610_ERROR_MSG_ENUM retVal;

    PVG610_COM_GENERAL_CONTROL_STRUCT generalControl;

    generalControl.opcode = opcode;
    length = MIN(length, sizeof(generalControl.pDataBuffer));
    generalControl.length = length;
    memcpy((BYTE*)generalControl.pDataBuffer, data, length);
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE *)&generalControl,
                                 (BYTE)(PVG610_COM_GENERAL_CONTROL_HEADER_SIZE + length),
                                 PVG610_COM_GENERAL_CONTROL_SET_OPCODE_E,
                                 modemIndex);
    return retVal;
}


/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_GeneralControlGet(BYTE       deviceIndex,
                                                   BYTE       modemIndex,
                                                   UINT32     opcode,
                                                   BYTE       *length,
                                                   BYTE       *data)
{
    PVG610_ERROR_MSG_ENUM              retVal;
    PVG610_COM_GENERAL_CONTROL_STRUCT  *pGeneralControl = (PVG610_COM_GENERAL_CONTROL_STRUCT *)&gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN];

    *length = 0;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                      (BYTE *)&opcode,   // send the opcode
                                      sizeof(UINT32),
                                      PVG610_COM_GENERAL_CONTROL_GET_OPCODE_E,
                                      modemIndex);
    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        *length = MIN(pGeneralControl->length, PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_GENERAL_CONTROL_HEADER_SIZE);
        memcpy(data, (BYTE*)pGeneralControl->pDataBuffer, *length);
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// get debug msg. if no data to return, the len will be 0
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_DebugMsgGet (BYTE              deviceIndex,
                                              BYTE              modemIndex,
                                              BYTE              *pBuffer,
                                              UINT32            *len) // in bytes
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_DEBUG_PVG610_OPCODE_E,
                                 modemIndex);

    if (retVal == PVG610_SUCCESS_MSG_E)
    {
        memcpy (pBuffer, &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], gPvg610Database[deviceIndex].rxTotalMsgSize-PVG610_HOST_PROTOCOL_HEADER_LEN-PVG610_CHECKSUM_LEN);
        *len = gPvg610Database[deviceIndex].rxTotalMsgSize - PVG610_HOST_PROTOCOL_HEADER_LEN - PVG610_CHECKSUM_LEN;
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION:           memory set                                             //
//                                                                             //
//  PARAMETERS:         BYTE    deviceIndex -   [in] device index              //
//                      BYTE    modemIndex  -   [in] modem index               //
//                      UINT32  address     -   [in] address in the memory     //
//                      UINT32  len         -   [in] number of bytes to fill   //
//                                                  (to write)                 //
//                      BYTE    *data       -   [in] a pointer to the data     //
//                                                   buffer to be written      //
//                      BYTE    mode         -  [in] two modes are available:  //
//                                                   0 - Fill the memory with  //
//                                                       a certain value       //
//                                                   1 - Fill the memory with  //
//                                                       data (usually from    //
//                                                       file)                 //
//                                                                             //
//  DESCRIPTION:        the function writes a buffer of bytes at a specifid    //
//                      location (address in the memory)                       //
//                                                                             //
//  RETURNS:            PVG610_ERROR_MSG_ENUM                                  //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_MemorySet(BYTE       deviceIndex,
                                           BYTE       modemIndex,
                                           UINT32     address,
                                           UINT32     len,
                                           BYTE       *data,
								           BYTE       mode)
{
    PVG610_ERROR_MSG_ENUM              retVal = PVG610_INVALID_PARAMS_E;
    PVG610_COM_MEMORY_SET_STRUCT       writeMemory;
    UINT16                             ix;
	UINT32                             maxBytesToWrite, bytesToWrite, totalBytesWrite = 0;
        
	//A max size for each chunk (each MSG)
	maxBytesToWrite = PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - PVG610_COM_GENERAL_CONTROL_HEADER_SIZE;

	//A loop to write all bytes
	while (len > totalBytesWrite)
    {
		//Decide how much bytes to send in the current chunk 
		//(also take care of the remaining part)
        bytesToWrite = MIN(maxBytesToWrite, (len - totalBytesWrite));
        writeMemory.len = (BYTE)bytesToWrite;

		//Initialize the pMemory struct
		writeMemory.address = address;				//Initialize the address field (start address)

        //same value for the all memory range
		if(mode == 0)
		{
			for(ix = 0; ix < bytesToWrite; ix++)			//Initialize the data field (data to be written)
			{
				writeMemory.data[ix] = *data;
			}
		}
        //each memory byte has its own value
		else
		{
			//Initialize the data field (data to be written)
	        memcpy((BYTE*)writeMemory.data, data, bytesToWrite);
		}
		//Send the MSG to the FW
		retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],      //database - to be filled
							(BYTE*)&writeMemory,             //struct contains all msg params
							sizeof(PVG610_COM_MEMORY_SET_STRUCT),   //size of the struct
							PVG610_COM_MEMORY_SET_OPCODE_E,         //opcode
							modemIndex);                     //dev index
        //exit the loop upon error
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }
		//Update byte counter and set the next address
		totalBytesWrite += bytesToWrite;
        address += bytesToWrite;
	}
	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// memory get
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_MemoryGet(BYTE       deviceIndex,
                                           BYTE       modemIndex,
                                           UINT32     address,
                                           UINT32     len,
                                           BYTE       *data)
{

    PVG610_ERROR_MSG_ENUM              retVal = PVG610_INVALID_PARAMS_E;
    PVG610_COM_MEMORY_GET_STRUCT       pMemory;
    UINT32                      maxBytesToRead, bytesToRead, totalBytesRead = 0;


    maxBytesToRead = PVG610_HOST_PROTOCOL_MAX_PAYLOAD_LEN - sizeof(PVG610_COM_MEMORY_GET_STRUCT);

    pMemory.address = address;

    // loop to read all the bytes
    while (len > totalBytesRead)
    {
        bytesToRead = MIN(maxBytesToRead, (len - totalBytesRead));
        pMemory.len = (BYTE)bytesToRead;

        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     (BYTE*)&pMemory,
                                     sizeof(PVG610_COM_MEMORY_GET_STRUCT),
                                     PVG610_COM_MEMORY_GET_OPCODE_E,
                                     modemIndex);

        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            memcpy(&data[totalBytesRead], &gPvg610Database[deviceIndex].pRxMsg[PVG610_HOST_PROTOCOL_HEADER_LEN], bytesToRead);
        }

        totalBytesRead += bytesToRead;
        pMemory.address += bytesToRead;
    }

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
// TxRxOperationStar
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM PVG610_API_TxRxOperationStart(BYTE     deviceIndex,
                                                    BYTE     modemIndex)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 PVG610_COM_TX_RX_START_OPCODE_E,
                                 modemIndex);
    return retVal;
}


//  //////////////////    //////////////////    //////////////////    /////////
///  ////////////////  //  ////////////////  //  ////////////////  //  ////////
////  //////////////  ////  //////////////  ////  //////////////  ////  ///////
/////  ////////////  //////  ////////////  //////  ////////////  //////  //////
//////  //////////  ////////  //////////  ////////  //////////  ////////  /////
///////  ////////  //////////  ////////  //////////  ////////  //////////  ////
////////  //////  ////////////  //////  ////////////  //////  ////////////  ///
/////////  ////  //////////////  ////  //////////////  ////  //////////////  //
//////////  //  ////////////////  //  ////////////////  //  ////////////////  /
///////////    //////////////////    //////////////////    //////////////////


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610RawDataSend
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610RawDataSend(PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pBuff, UINT32 buffLen)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    UINT32 chunkLen, sleepTimeMicro;

    switch (pDbRecord->media)
    {
    case PVG610_COM_MEDIA_UART_E:
    
  //  printEthLongHex((unsigned long)pDbRecord->deviceIndex);
    
       pvg610HostUartDataSend(pDbRecord->deviceIndex, pBuff, buffLen);
      
        break;

    case PVG610_COM_MEDIA_SPI_E:
        // it takes 330 system clocks to the FW to handle 1 byte.
        sleepTimeMicro = (330 * 256)/(pDbRecord->systemClockInHz/1000000);
   //     printf("\n\r buffLen : %d", buffLen);
        
        while (buffLen > 0)
        {
        
            chunkLen = MIN(buffLen, 256);
            
        //   printf("\n\r bufflen = %d chnklen = %d",buffLen, chunkLen);
            if(!(pvg610HostSpiDataSend(pDbRecord->deviceIndex, pBuff, chunkLen))) return (PVG610_MEDIA_NOT_INITIALIZED_E);
            buffLen -= chunkLen;
            pBuff += chunkLen;
            pvg610HostSleep(sleepTimeMicro);  //????? can make little
        }
        break;

    case PVG610_COM_MEDIA_DPRAM_E:
        // it takes 558 system clocks to the FW to handle 1 Word.
        sleepTimeMicro = (558 * 256)/(pDbRecord->systemClockInHz/1000000);
        while (buffLen > 0)
        {
            chunkLen = MIN(buffLen, 512);
            pvg610HostDpramDataWrite(pDbRecord->deviceIndex, PVG610_DPRAM_TX_WDATA_REG, pBuff, chunkLen);
            buffLen -= chunkLen;
            pBuff += chunkLen;
            pvg610HostSleep(sleepTimeMicro);
        }
        break;

    default:
        retVal = PVG610_MEDIA_NOT_INITIALIZED_E;
        break;
    }

    return(retVal);
}


///////////////////////////////////////////////////////////////////////////////
// Build request message
///////////////////////////////////////////////////////////////////////////////
void pvg610MessageBuild(PVG610_DATABASE_STRUCT   *pDbRecord,
                        BYTE                     opcode,
                        BYTE                     modemIndex,
                        BYTE                     *pSentParamsBuff,
                        UINT32                   sentParamsLen)
{
    UINT32 checksum;
//printEthStringAdd(0,0);
   // copy message payload
    memcpy (pDbRecord->pTxMsg + PVG610_HOST_PROTOCOL_HEADER_LEN, pSentParamsBuff, sentParamsLen);
    pDbRecord->txTotalMsgSize = sentParamsLen + PVG610_HOST_PROTOCOL_HEADER_LEN + PVG610_CHECKSUM_LEN;
//printEthStringAdd(1,pDbRecord->txTotalMsgSize);   //08
    // handle endian conversion if necessary

    
    pvg610RequestParamSwap((PVG610_COM_OPCODE_ENUM)opcode, pDbRecord->pTxMsg + PVG610_HOST_PROTOCOL_HEADER_LEN, pDbRecord->txTotalMsgSize - PVG610_HOST_PROTOCOL_HEADER_LEN);

    // build header
    pDbRecord->pTxMsg[PVG610_OPCODE_OFFSET_E] = opcode;  //0 ->4
    pDbRecord->pTxMsg[PVG610_TASK_CONTEXT_AND_SEQ_NUM_OFFSET_E] = (pDbRecord->commandSeqNum & 0x0F) | ((modemIndex << 4) & 0xF0); //1 >0  8 -4-4 = 0
    pDbRecord->pTxMsg[PVG610_NACK_REASON_OFFSET_E] = 0;    //2 >0
    pDbRecord->pTxMsg[PVG610_MSG_LEN_OFFSET_E] = (BYTE)(pDbRecord->txTotalMsgSize - PVG610_HOST_PROTOCOL_HEADER_LEN - PVG610_CHECKSUM_LEN); //3   = 0



//printEthStringAdd(1,pDbRecord->pTxMsg[PVG610_MSG_LEN_OFFSET_E]);  //00

    // insert checksum
//t    checksum = pvg610ChecksumCalc(0, pDbRecord->pTxMsg, pDbRecord->txTotalMsgSize - PVG610_CHECKSUM_LEN, TRUE);
    checksum = pvg610ChecksumCalc(0, pDbRecord->pTxMsg, pDbRecord->txTotalMsgSize - PVG610_CHECKSUM_LEN, TRUE);
    memcpy((void*)(pDbRecord->pTxMsg + pDbRecord->txTotalMsgSize - PVG610_CHECKSUM_LEN), (void*)&checksum, PVG610_CHECKSUM_LEN);

//printEthStringAdd(1,pDbRecord->pTxMsg);//    20
//printEthStringAdd(1,pDbRecord->txTotalMsgSize); // 00
//printEthStringAdd(1,PVG610_CHECKSUM_LEN); // 4
//printEthStringAdd(1,pDbRecord->pTxMsg + pDbRecord->txTotalMsgSize - PVG610_CHECKSUM_LEN); //20
//printEthStringAdd(1,(checksum>>24));  //de
//printEthStringAdd(1,(checksum>>16));
//printEthStringAdd(1,(checksum>>8));
//printEthStringAdd(1,checksum);

//printEthStringAdd(2,0);

    
}



///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610BuildSendAndReceive                                            //
///////////////////////////////////////////////////////////////////////////////
extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceive(PVG610_DATABASE_STRUCT *pDbRecord,
                                                BYTE                    *pSentParamsBuff,
                                                UINT32                  sentParamsLen,
                                                PVG610_COM_OPCODE_ENUM  opcode,
                                                BYTE                    modemIndex)
{
 //bad       printEthStringAdd(1,'a');
 //   return 0;

    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
  //?need   delay_mcs(100);
  
  //bad  return;

    pvg610HostMutexGet(pDbRecord->deviceIndex);

    do
    {
 //   delay_mcs(100);

    
        // clear rx message size for the response
        pDbRecord->rxState = PVG610_RXH_IDLE_E;
        pDbRecord->rxTotalMsgSize = 0;
        
     //     printEthStringAdd(1,sentParamsLen>>24);
     //     printEthStringAdd(1,sentParamsLen>>16);
     //     printEthStringAdd(1,sentParamsLen>>8);
     //     printEthStringAdd(1,sentParamsLen>>0);    //0xf4

 //bad      return;
        pvg610MessageBuild(pDbRecord, (BYTE)opcode, modemIndex, pSentParamsBuff, sentParamsLen);
   //delay_mcs(100);
   
 //bad  return; //t
       
        retVal = pvg610MessageSend(pDbRecord);   //spi
      //      printEthLongHex(0x31); //hier
       //     printEthStringAdd(1,0x31);
       //       printEthStringAdd(1,opcode);

        if (retVal != PVG610_SUCCESS_MSG_E)
        {
       //      printEthLongHex(0);
         //   printEthStringAdd(1,0x41);
          //    printEthStringAdd(1,retVal);
          
     //      printEthStringAdd(1,0x31);
     //         printEthStringAdd(1,opcode);
 
      //   printfp(" 1 "); 
      //     printfpd(" %ld", time1);
 
//100505 #ifndef TEST_BMDN      
            break;
//100505 #endif // TEST_BMDN           
        }
        
        
    //        printEthLongHex(0x32); //hier
    //need add delay!
//t    delay_mcs(20000);
 //somtime ok      delay_mcs(5000);
#ifdef BMDN_CONNECT_USART 
  delay_mcs(1000);
#else
//t101026  delay_mcs(1000);    //for test 100621
//t101027   delay_mcs(100);  // t101026
#endif  
// delay_mcs(1050);
 //delay_mcs(10000);
// delay_mcs(2000);
// delay_mcs(900);
 //delay_mcs(1); //t 110503

 
 
 
//somtime ok delay_mcs(500);


       
   //    delay_mcs(20000);

 //             printEthStringAdd(1,0x32);
 //01 02 03 04 05 31 32 33 34 06 21 31 32 33 34 22 23 26 31 32 35 09 
 
       //  return(PVG610_SUCCESS_MSG_E); //t110602 
  //       printfp(" 2 "); 
    //       printfpd(" %ld", time1);

        retVal = pvg610MessageReceive(pDbRecord);      //hier slowly!  make this 6 ms!!!!
        
      //    printfp(" 3 "); 
      //    printfpd(" %ld", time1);
     //   return(PVG610_SUCCESS_MSG_E); //t110602 

        
        
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
    //     printEthLongHex(2);  //hier
//100505        printf("\n\r error : 0x%X", retVal);     
//110118 #ifndef MAKET_PLATA       
      //      printEthStringAdd(1,0x35);
       //     printEthStringAdd(1,retVal);
//100505#ifndef TEST_SPI 
//#ifdef USART0_TRY_PDC_1T 
//            printfp("\n\r != break");  //t
//#endif           
            break;
//100505#endif            
            
//110118 #endif //MAKET_PLATA 
     //    printf("\n\r error : 0x%X", retVal);           
        }
        
    //      printEthLongHex(0x33);
    //         printEthStringAdd(1,0x33);

        pvg610ResponseParamSwap((PVG610_COM_OPCODE_ENUM)pDbRecord->rxOpcode,
                          pDbRecord->pRxMsg+PVG610_HOST_PROTOCOL_HEADER_LEN,
                          pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] - PVG610_CHECKSUM_LEN);

        pDbRecord->commandSeqNum++;
        
        
          //   printEthStringAdd(1,pDbRecord->rxOpcode);
     //        printEthStringAdd(1,0x34);

        retVal = pDbRecord->rxNackReason;
    } while(0);

    pvg610HostMutexRelease(pDbRecord->deviceIndex);
    return(retVal);
}
//________________________________________________________________________________________

PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceiveS(PVG610_DATABASE_STRUCT *pDbRecord,
                                                BYTE                    *pSentParamsBuff,
                                                UINT32                  sentParamsLen,
                                                PVG610_COM_OPCODE_ENUM  opcode,
                                                BYTE                    modemIndex)
{
 //bad       printEthStringAdd(1,'a');
 //   return 0;

    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
  //?need   delay_mcs(100);
  
  //bad  return;

    pvg610HostMutexGet(pDbRecord->deviceIndex);

  //  do
  //  {
 //   delay_mcs(100);

    
        // clear rx message size for the response
        pDbRecord->rxState = PVG610_RXH_IDLE_E;
        pDbRecord->rxTotalMsgSize = 0;
        
     //     printEthStringAdd(1,sentParamsLen>>24);
     //     printEthStringAdd(1,sentParamsLen>>16);
     //     printEthStringAdd(1,sentParamsLen>>8);
     //     printEthStringAdd(1,sentParamsLen>>0);    //0xf4

 //bad      return;
        pvg610MessageBuild(pDbRecord, (BYTE)opcode, modemIndex, pSentParamsBuff, sentParamsLen);
   //delay_mcs(100);
   
 //bad  return; //t
       
        retVal = pvg610MessageSend(pDbRecord);   //spi
      //      printEthLongHex(0x31); //hier
       //     printEthStringAdd(1,0x31);
       //       printEthStringAdd(1,opcode);

    //    if (retVal != PVG610_SUCCESS_MSG_E)
    //    {
       //      printEthLongHex(0);
         //   printEthStringAdd(1,0x41);
          //    printEthStringAdd(1,retVal);
          
     //      printEthStringAdd(1,0x31);
     //         printEthStringAdd(1,opcode);
 
          
          
//100505 #ifndef TEST_BMDN      
      //      break;
//100505 #endif // TEST_BMDN           
      //  }
        
   //    } while(0)  
//__________________________________________________Send only
        return retVal;


//__________________________________________________        
 }

PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceiveR(PVG610_DATABASE_STRUCT *pDbRecord,
                                                BYTE                    *pSentParamsBuff,
                                                UINT32                  sentParamsLen,
                                                PVG610_COM_OPCODE_ENUM  opcode,
                                                BYTE                    modemIndex)
{
 //bad       printEthStringAdd(1,'a');
 //   return 0;

    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
  //?need   delay_mcs(100);
#ifdef BMDN_CONNECT_USART 
  delay_mcs(1000);
#else
//t101026  delay_mcs(1000);    //for test 100621
//t101027   delay_mcs(100);  // t101026
#endif  
// delay_mcs(1050);
 //delay_mcs(10000);
// delay_mcs(2000);
// delay_mcs(900);
// delay_mcs(1);

          do
    {

 
 
//somtime ok delay_mcs(500);


       
   //    delay_mcs(20000);

 //             printEthStringAdd(1,0x32);
 //01 02 03 04 05 31 32 33 34 06 21 31 32 33 34 22 23 26 31 32 35 09 
        retVal = pvg610MessageReceive(pDbRecord);
        
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
    //     printEthLongHex(2);  //hier
//100505        printf("\n\r error : 0x%X", retVal);     
//110118 #ifndef MAKET_PLATA       
      //      printEthStringAdd(1,0x35);
       //     printEthStringAdd(1,retVal);
//100505#ifndef TEST_SPI            
            break;
//100505#endif            
            
//110118 #endif //MAKET_PLATA 
     //    printf("\n\r error : 0x%X", retVal);           
        }
        
    //      printEthLongHex(0x33);
    //         printEthStringAdd(1,0x33);

        pvg610ResponseParamSwap((PVG610_COM_OPCODE_ENUM)pDbRecord->rxOpcode,
                          pDbRecord->pRxMsg+PVG610_HOST_PROTOCOL_HEADER_LEN,
                          pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] - PVG610_CHECKSUM_LEN);

        pDbRecord->commandSeqNum++;
        
        
          //   printEthStringAdd(1,pDbRecord->rxOpcode);
     //        printEthStringAdd(1,0x34);

        retVal = pDbRecord->rxNackReason;
    } while(0);

    pvg610HostMutexRelease(pDbRecord->deviceIndex);
    return(retVal);
}



//________________________________________________________________________________________



extern "C" PVG610_ERROR_MSG_ENUM pvg610BuildSendAndReceive1(PVG610_DATABASE_STRUCT *pDbRecord,
                                                BYTE                    *pSentParamsBuff,
                                                UINT32                  sentParamsLen,
                                                PVG610_COM_OPCODE_ENUM  opcode,
                                                BYTE                    modemIndex)
{
// unsigned char *test;

 //bad       printEthStringAdd(1,'a');
 //   return 0;

    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
  //?need   delay_mcs(100);
  
  //bad  return;

    pvg610HostMutexGet(pDbRecord->deviceIndex);

    do
    {
 //   delay_mcs(100);

    
        // clear rx message size for the response
        pDbRecord->rxState = PVG610_RXH_IDLE_E;
        pDbRecord->rxTotalMsgSize = 0;
        
     //     printEthStringAdd(1,sentParamsLen>>24);
     //     printEthStringAdd(1,sentParamsLen>>16);
     //     printEthStringAdd(1,sentParamsLen>>8);
     //     printEthStringAdd(1,sentParamsLen>>0);    //0xf4

 //bad      return;
        pvg610MessageBuild(pDbRecord, (BYTE)opcode, modemIndex, pSentParamsBuff, sentParamsLen);
   //delay_mcs(100);
   
 //bad  return; //t
   //     printf("\n\r");
   //     test = pDbRecord->pTxMsg;
   //     for(unsigned long im =0; im <sentParamsLen; im++)
   //     { 
   //       printf(" % 02X",      *test++);
   //       }
       
        retVal = pvg610MessageSend(pDbRecord);   //spi
      //      printEthLongHex(0x31); //hier
       //     printEthStringAdd(1,0x31);
       //       printEthStringAdd(1,opcode);

        if (retVal != PVG610_SUCCESS_MSG_E)
        {
       //      printEthLongHex(0);
         //   printEthStringAdd(1,0x41);
          //    printEthStringAdd(1,retVal);
          
       //    printEthStringAdd(1,0x31);
       //       printEthStringAdd(1,opcode);
 
          
          
//100505 #ifndef TEST_BMDN      
            break;
//100505 #endif // TEST_BMDN           
        }
        
//ok quickly!!!! return 0; //t100506       
    //        printEthLongHex(0x32); //hier
    //need add delay!
//t    delay_mcs(20000);
 //somtime ok      delay_mcs(5000);
 
//  delay_mcs(1000);
//t101027  delay_mcs(20);   //t100507
  
// delay_mcs(1050);
 //delay_mcs(10000);
// delay_mcs(2000);
// delay_mcs(900);

 
 
 
//somtime ok delay_mcs(500);


       
   //    delay_mcs(20000);

 //             printEthStringAdd(1,0x32);
 //01 02 03 04 05 31 32 33 34 06 21 31 32 33 34 22 23 26 31 32 35 09  
 
         retVal = pvg610MessageReceive1(pDbRecord);
         
//slow!!!return 0; //t 100506         
        
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
    //     printEthLongHex(2);  //hier
    //    printf("\n\r error : 0x%X", retVal);     
//#ifndef MAKET_PLATA       
    //        printEthStringAdd(1,0x35);
        //    printEthStringAdd(1,retVal);
//100505#ifndef TEST_SPI            
            break;
//100505#endif            
            
//#endif //MAKET_PLATA 
     //    printf("\n\r error : 0x%X", retVal);           
        }
        
    //      printEthLongHex(0x33);
    //         printEthStringAdd(1,0x33);

        pvg610ResponseParamSwap((PVG610_COM_OPCODE_ENUM)pDbRecord->rxOpcode,
                          pDbRecord->pRxMsg+PVG610_HOST_PROTOCOL_HEADER_LEN,
                          pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] - PVG610_CHECKSUM_LEN);

        pDbRecord->commandSeqNum++;
        
        
          //   printEthStringAdd(1,pDbRecord->rxOpcode);
     //        printEthStringAdd(1,0x34);

        retVal = pDbRecord->rxNackReason;
    } while(0);

    pvg610HostMutexRelease(pDbRecord->deviceIndex);
    return(retVal);
}
 


///////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610BuildSend                                                      //
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610BuildSend(PVG610_DATABASE_STRUCT    *pDbRecord,
                                      BYTE                      *pSentParamsBuff,
                                      UINT32                    sentParamsLen,
                                      PVG610_COM_OPCODE_ENUM    opcode,
                                      BYTE                      modemIndex)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    pvg610MessageBuild(pDbRecord, (BYTE)opcode, modemIndex, pSentParamsBuff, sentParamsLen);

    retVal = pvg610MessageSend(pDbRecord);

    pDbRecord->commandSeqNum++;

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610MessageSend
/////////////////////////////////////////////////////////////////////////////////

PVG610_ERROR_MSG_ENUM pvg610MessageSend(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    switch (pDbRecord->media)
    {
    case PVG610_COM_MEDIA_UART_E:
        pvg610UartMessageSend(pDbRecord);
        break;

    case PVG610_COM_MEDIA_SPI_E:
        if(!(pvg610SpiMessageSend(pDbRecord))) return (PVG610_MEDIA_NOT_INITIALIZED_E);
        break;

    case PVG610_COM_MEDIA_DPRAM_E:
        pvg610DpramMessageSend(pDbRecord);
        break;

    default:
        retVal = PVG610_MEDIA_NOT_INITIALIZED_E;
        break;
    }
    
    
 //     pvg610SpiMessageSend(pDbRecord);
    
    

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610MessageStuff
/////////////////////////////////////////////////////////////////////////////////
void pvg610MessageStuff(PVG610_DATABASE_STRUCT *pDbRecord)
{
    UINT16  ix;
    UINT32  tmpLen = 0;
    UINT32  buffLen = pDbRecord->txTotalMsgSize;
    BYTE    *pBuff = pDbRecord->pTxMsg;
    BYTE    *pStuffedBuff = pDbRecord->pStuffedBuff;

    tmpLen = 0;

    pStuffedBuff[tmpLen] = 0x7E;
    tmpLen++;
    for (ix=0; ix<buffLen; ix++)
    {
        if (pBuff[ix] == 0x7E)
        {
            pStuffedBuff[tmpLen] = 0x7D;
            pStuffedBuff[tmpLen+1] = 0x5E;
            tmpLen += 2;
        }
        else if (pBuff[ix] == 0x7D)
        {
            pStuffedBuff[tmpLen] = 0x7D;
            pStuffedBuff[tmpLen+1] = 0x5D;
            tmpLen += 2;
        }
        else
        {
            pStuffedBuff[tmpLen] = pBuff[ix];
            tmpLen++;
        }
    }
    pStuffedBuff[tmpLen] = 0x7E;
    tmpLen++;

    pDbRecord->stuffedBuffLen = tmpLen;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610UartMessageSend
/////////////////////////////////////////////////////////////////////////////////
void pvg610UartMessageSend(PVG610_DATABASE_STRUCT *pDbRecord)
{
#ifdef HOST_PROTOCOL_TX_LOG
    UINT32 i;
#endif
    pvg610MessageStuff(pDbRecord);

#ifdef HOST_PROTOCOL_TX_LOG
    fprintf(pfHostMsg,"Tx ");
    for (i=0; i<pDbRecord->stuffedBuffLen; i++) {fprintf(pfHostMsg,"%02X ",pDbRecord->pStuffedBuff[i]);}
    fprintf(pfHostMsg,"\n");
#endif
    pvg610HostUartReceiverFlush(pDbRecord->deviceIndex);
    pvg610HostUartDataSend(pDbRecord->deviceIndex, pDbRecord->pStuffedBuff, pDbRecord->stuffedBuffLen);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610SpiMessageSend
/////////////////////////////////////////////////////////////////////////////////
unsigned char pvg610SpiMessageSend(PVG610_DATABASE_STRUCT *pDbRecord)
{
    pvg610MessageStuff(pDbRecord);
    
    
    if(pDbRecord->pTxMsg[PVG610_OPCODE_OFFSET_E] == PVG610_COM_BOOT_DATA_MSG_OPCODE_E)
    { 
  //   printEthStringAdd(1,0x18);
  //   printEthStringAdd(1,pDbRecord->stuffedBuffLen>>8);
  //   printEthStringAdd(1,pDbRecord->stuffedBuffLen);
     }
    
    if(!(pvg610HostSpiDataSend(pDbRecord->deviceIndex, pDbRecord->pStuffedBuff, pDbRecord->stuffedBuffLen))) return 0;
 return 1;
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610DpramMessageSend
/////////////////////////////////////////////////////////////////////////////////
void pvg610DpramMessageSend(PVG610_DATABASE_STRUCT *pDbRecord)
{
    UINT16 level, ix, temp;

    // flush tx side - just in case
    pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_TX_LEVEL_REG, (BYTE*)&level, sizeof(UINT16));
    for (ix=0; ix<level; ix++)
    {
        pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_TX_RDATA_REG, (BYTE*)&temp, sizeof(UINT16));
    }

    // flush rx side - just in case
    pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_RX_LEVEL_REG, (BYTE*)&level, sizeof(UINT16));
    for (ix=0; ix<level; ix++)
    {
        pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_RX_RDATA_REG, (BYTE*)&temp, sizeof(UINT16));
    }

    // flush interrupt - just in case
    pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_TO_EXT_STATUS_REG, (BYTE*)&temp, sizeof(UINT16));

    // write message
    pvg610HostDpramDataWrite(pDbRecord->deviceIndex, PVG610_DPRAM_TX_WDATA_REG, pDbRecord->pTxMsg, pDbRecord->txTotalMsgSize);

    // indicate write_done_to_int
    temp = (1<<PVG610_DPRAM_WRITE_DONE_BIT_E);
    pvg610HostDpramDataWrite(pDbRecord->deviceIndex, PVG610_DPRAM_DONE_REG, (BYTE*)&temp, sizeof(UINT16));
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: receiveMessage                                                   //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610MessageReceive(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    /* 110131  to work quickly
    switch (pDbRecord->media)
    {
    case PVG610_COM_MEDIA_UART_E:
        retVal = pvg610UartMessageReceive(pDbRecord);
        break;

    case PVG610_COM_MEDIA_SPI_E:
    */
        retVal = pvg610SpiMessageReceive(pDbRecord);
     /*   
        break;
     
    case PVG610_COM_MEDIA_DPRAM_E:
        retVal = pvg610DpramMessageReceive(pDbRecord);
        break;

    default:
        retVal = PVG610_MEDIA_NOT_INITIALIZED_E;
        break;
    }
          */
       return  retVal;
    }
    
    
/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: receiveMessage1                                                   //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610MessageReceive1(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;

    switch (pDbRecord->media)
    {
    case PVG610_COM_MEDIA_UART_E:
        retVal = pvg610UartMessageReceive(pDbRecord);
        break;

    case PVG610_COM_MEDIA_SPI_E:
        retVal = pvg610SpiMessageReceive1(pDbRecord);
        break;

    case PVG610_COM_MEDIA_DPRAM_E:
        retVal = pvg610DpramMessageReceive(pDbRecord);
        break;

    default:
        retVal = PVG610_MEDIA_NOT_INITIALIZED_E;
        break;
    }

       return  retVal;
    }

 //////////////////////////////
//  FUNCTION: pvg610SpiEstimatedRxMsgSizeGet                                   //
/////////////////////////////////////////////////////////////////////////////////
UINT32 pvg610SpiEstimatedRxMsgSizeGet (PVG610_COM_OPCODE_ENUM opcode)
{
    switch(opcode)
    {
	case PVG610_COM_FLASH_INFO_GET_START_OPCODE_E:					
	case PVG610_COM_REGISTER_READ_OPCODE_E:					
	case PVG610_COM_VERSION_GET_OPCODE_E:					
	case PVG610_COM_ALARM_ENABLE_GET_OPCODE_E:					
	case PVG610_COM_ALARM_STATUS_GET_OPCODE_E:					
	case PVG610_COM_SYS_INFO_PARAMS_GET_OPCODE_E:					
	case PVG610_COM_ACM_COUNTERS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_FEC_COUNTERS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_XPIC_STATUS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_PREDISTORTION_COEFS_GET_OPCODE_E:					
	case PVG610_COM_NET_STM1_ALARM_GET_OPCODE_E:					
	case PVG610_COM_NET_STM1_PM_GET_OPCODE_E:					
	case PVG610_COM_NET_ETH_STATUS_GET_DONE_OPCODE_E:					
	case PVG610_COM_NET_PRBS_ERRORS_GET_E:					
	case PVG610_COM_MAILBOX_MESSAGE_RECEIVE_OPCODE_E:					
	case PVG610_GPIO_READ_OPCODE_E:	  
   case PVG610_COM_NET_GPI_ERRORS_GET_E: 
   case PVG610_COM_MODEM_IQ_IMBALANCE_TXTX_SET_OPCODE_E:
   case PVG610_COM_MODEM_SLAVE_IQ_IMBALANCE_STATUS_GET_OPCODE_E:
        return PVG610_SPI_RX_MSG_SMALL_SIZE;
 
	case PVG610_COM_HOST_INFO_GET_OPCODE_E:					
	case PVG610_COM_MODEM_STATUS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_ACQUIRE_COUNTERS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_IQ_IMBALANCE_STATUS_GET_OPCODE_E:	 
	case PVG610_COM_NET_E1_ALARM_GET_OPCODE_E:					
       return PVG610_SPI_RX_MSG_MEDIUM_SIZE;
	
	case PVG610_COM_MODEM_EQUALIZER_STATUS_GET_OPCODE_E:					
	case PVG610_COM_MODEM_PREEMPHASIS_COEFS_GET_OPCODE_E:					
	case PVG610_COM_NET_ETH_PM_GET_OPCODE_E:					
	case PVG610_COM_NET_FIFO_STATUS_GET_OPCODE_E:					
        return PVG610_SPI_RX_MSG_LARGE_SIZE;
    
	case PVG610_COM_CONFIG_FILE_FROM_EMBEDDED_GET_OPCODE_E:					
    case PVG610_COM_REGISTER_RANGE_READ_OPCODE_E:					
    case PVG610_COM_MULTIPLE_REGSITERS_READ_OPCODE_E:					
    case PVG610_COM_DWORD_FIFO_READ_OPCODE_E:					
    case PVG610_COM_MODEM_IQ_SAMPLES_GET_OPCODE_E:					
    case PVG610_COM_NET_E1_PM_GET_OPCODE_E:					
	case PVG610_COM_GENERAL_CONTROL_GET_OPCODE_E:					
	case PVG610_COM_DEBUG_PVG610_OPCODE_E:					
	case PVG610_COM_MEMORY_GET_OPCODE_E:					
        return PVG610_SPI_RX_MSG_LARGEST_SIZE;
    
	default:
        return PVG610_SPI_RX_MSG_SMALLEST_SIZE;    //most harmeless size (common enought and small enough)
    }
}





/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610UartMessageReceive                                         //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610UartMessageReceive(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM      retVal = PVG610_SUCCESS_MSG_E;
    BYTE                val;
    BOOLEAN             isComplete = FALSE;
    BOOLEAN             timeout = FALSE;
    UINT32              startTime;
    UINT32              bytesRead;
    UINT16              timeRemainingInMilli = pDbRecord->rxTimeoutMilli;

    startTime = pvg610HostTickGet();
#ifdef PRINT_USART_DATA    
//printEthStringAdd(0,0);
//if(print_flag)
 //       printEthStringAdd(1,0x44); 
#endif

  while (!isComplete)
    {

    timeRemainingInMilli = pDbRecord->rxTimeoutMilli - (pvg610HostTickGet() - startTime);
        timeout = (pvg610HostTickGet() - startTime) > pDbRecord->rxTimeoutMilli;
        if (timeout)
        {
            return(PVG610_ERROR_IN_COM_RECEIVE_E);
        }
        // get and process 1 byte at a time
        pvg610HostUartDataReceive(pDbRecord->deviceIndex, &val, 1, timeRemainingInMilli, &bytesRead);
        if (bytesRead != 1)
        {
#ifdef PRINT_USART_DATA  
//printEthStringAdd(1,0x66);  
// printEthStringAdd(2,0); 
//if(print_flag)
 //       printEthStringAdd(1,0x55);    
#endif

        
            return(PVG610_ERROR_IN_COM_RECEIVE_E);
        }
#ifdef PRINT_USART_DATA    
//now        printEthLongHex(val);
if(print_flag)
 //       printEthStringAdd(1,val); 
#endif        
        

        retVal = pvg610RxStateMachine(pDbRecord, val, &isComplete);
//#ifdef PRINT_USART_DATA    
//        printEthLongHex(retVal);
    //    printEthStringAdd(1,val); 
//#endif            
        
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
#ifdef PRINT_USART_DATA   
//printEthStringAdd(1,0x66); 
//if(print_flag)
 //       printEthStringAdd(1,0x55); 
//printEthStringAdd(2,0);    
#endif
        
        
        
            return(retVal);
        }
    }
#ifdef PRINT_USART_DATA   
if(print_flag)
   //     printEthStringAdd(1,0x33); 
//printEthStringAdd(2,0);    
#endif

    return(PVG610_SUCCESS_MSG_E);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610SpiMessageReceive                                          //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610SpiMessageReceive(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM   retVal = PVG610_SUCCESS_MSG_E;
	BYTE                    txBuf[PVG610_SPI_RX_MSG_LARGEST_SIZE], rxBuf[PVG610_SPI_RX_MSG_LARGEST_SIZE];
    BOOLEAN                 isComplete = FALSE;
    BOOLEAN                 timeout = FALSE;
    UINT32                  startTime;
    UINT32                  ix;
    UINT32                  estimatedMsgSize;

    memset(txBuf, 0x7E, sizeof(txBuf));
    startTime = pvg610HostTickGet();
    while (!isComplete)
    {
        // what's the time?
        timeout = (pvg610HostTickGet() - startTime) > pDbRecord->rxTimeoutMilli;
        
        if (timeout)
        {
        //    printfp("out");
            return(PVG610_ERROR_IN_COM_RECEIVE_E);
        }
        // if nothing received yet, sleep for a while
        if (pDbRecord->rxState == PVG610_RXH_IDLE_E)
        {
       //     pvg610HostSleep(100);
      //110125      pvg610HostSleep(200);   //100517
       //       pvg610HostSleep(300);
       //       pvg610HostSleep(50);
       
        //    pvg610HostSleep(10000);  //t
        }
        if (pDbRecord->rxState ==  PVG610_RXH_IN_MSG_E)
        {
            estimatedMsgSize =  pvg610SpiEstimatedRxMsgSizeGet((PVG610_COM_OPCODE_ENUM)pDbRecord->pTxMsg[PVG610_OPCODE_OFFSET_E]);
        }
        else
        {
            estimatedMsgSize =  PVG610_SPI_RX_MSG_SMALLEST_SIZE;
        }
  //      printEthLongHex(4); //hier
        
        pvg610HostSpiDataReceive(pDbRecord->deviceIndex, txBuf, rxBuf, estimatedMsgSize);
  //       printEthStringAdd(0,0);
         //         printf("\n\r r: ");
        for (ix=0; ix < estimatedMsgSize && (!isComplete); ix++)
        {
 //        printEthStringAdd(1,ix);
 //        printEthStringAdd(1,rxBuf[ix]);
   //      printf(" %02X",rxBuf[ix]);
 
            retVal = pvg610RxStateMachine(pDbRecord, rxBuf[ix], &isComplete);
            
          //   printEthStringAdd(1,ix);
          //    printEthStringAdd(1,retVal);
          //      printEthStringAdd(1,isComplete);

            if (retVal != PVG610_SUCCESS_MSG_E)
            {
     //        printEthStringAdd(1,0x99);
    //        printEthStringAdd(2,0);
                return(retVal);
            }
        }
    //        printEthStringAdd(1,0x77);     //hier
   //     printEthStringAdd(2,0);
    }
    return(PVG610_SUCCESS_MSG_E);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610SpiMessageReceive                                          //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610SpiMessageReceive1(PVG610_DATABASE_STRUCT *pDbRecord)
{
    PVG610_ERROR_MSG_ENUM   retVal = PVG610_SUCCESS_MSG_E;
	BYTE                    txBuf[PVG610_SPI_RX_MSG_LARGEST_SIZE], rxBuf[PVG610_SPI_RX_MSG_LARGEST_SIZE];
    BOOLEAN                 isComplete = FALSE;
    BOOLEAN                 timeout = FALSE;
    UINT32                  startTime;
    UINT32                  ix;
    UINT32                  estimatedMsgSize;

    memset(txBuf, 0x7E, sizeof(txBuf));
    startTime = pvg610HostTickGet();
//quickly!!! return 0; //100605    
    //  printf("\n\rt %d", pDbRecord->rxTimeoutMilli);
   while (!isComplete)    //if comment - quckly!
    {
        // what's the time?
   //100506     timeout = (pvg610HostTickGet() - startTime) > pDbRecord->rxTimeoutMilli;
        timeout = (pvg610HostTickGet() - startTime) > pDbRecord->rxTimeoutMilli;
      //  printf(" %d", timeout);
        if (timeout)
        {
            return(PVG610_ERROR_IN_COM_RECEIVE_E);
        }
        // if nothing received yet, sleep for a while
        if (pDbRecord->rxState == PVG610_RXH_IDLE_E)
        {
  //t110125         pvg610HostSleep(50);
      //      pvg610HostSleep(1000);
        //    pvg610HostSleep(1000);    //101230 ???
       
        //    pvg610HostSleep(10000);  //t
        }
        if (pDbRecord->rxState ==  PVG610_RXH_IN_MSG_E)
        {
            estimatedMsgSize =  pvg610SpiEstimatedRxMsgSizeGet((PVG610_COM_OPCODE_ENUM)pDbRecord->pTxMsg[PVG610_OPCODE_OFFSET_E]);
        }
        else
        {
            estimatedMsgSize =  PVG610_SPI_RX_MSG_SMALLEST_SIZE;
        }
  //      printEthLongHex(4); //hier
        
        pvg610HostSpiDataReceive(pDbRecord->deviceIndex, txBuf, rxBuf, estimatedMsgSize);
  //       printEthStringAdd(0,0);
 //       printf("\n\r r:");
        for (ix=0; ix < estimatedMsgSize && (!isComplete); ix++)
        {
// #ifdef USART0_TRY_PDC_1T
// printfpd("\n\r1 %ld", time1keep);
// printfpd("\n\ra %ld", time1);
// printfpd("\n\rix>%ld ", ix);
//#endif
       
 //        printEthStringAdd(1,ix);
     //    printEthStringAdd(1,rxBuf[ix]);
  //         printf(" %02X",rxBuf[ix]);
            retVal = pvg610RxStateMachine(pDbRecord, rxBuf[ix], &isComplete);
  //             retVal =  PVG610_SUCCESS_MSG_E; //110201
          //   printEthStringAdd(1,ix);
          //    printEthStringAdd(1,retVal);
          //      printEthStringAdd(1,isComplete);

            if (retVal != PVG610_SUCCESS_MSG_E)
            {
     //        printEthStringAdd(1,0x99);
    //        printEthStringAdd(2,0);
                return(retVal);
            }
        }
    //        printEthStringAdd(1,0x77);     //hier
   //     printEthStringAdd(2,0);
    }
    return(PVG610_SUCCESS_MSG_E);
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610DpramMessageReceive                                              //
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610DpramMessageReceive(PVG610_DATABASE_STRUCT *pDbRecord)
{
    BOOLEAN timeout = FALSE;
    UINT16 msgLen;

    // wait for response
    timeout = pvg610HostDpramWait(pDbRecord->deviceIndex, (UINT16)pDbRecord->rxTimeoutMilli);
    if (timeout)
    {
        return(PVG610_ERROR_IN_COM_RECEIVE_E);
    }

    // read response length
    pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_RX_LEVEL_REG, (BYTE*)&msgLen, sizeof(UINT16));
    pDbRecord->rxTotalMsgSize = msgLen * sizeof(UINT16);

    // read response
    pvg610HostDpramDataRead(pDbRecord->deviceIndex, PVG610_DPRAM_RX_RDATA_REG, pDbRecord->pRxMsg, pDbRecord->rxTotalMsgSize);

    // check response
    return(pvg610RxMessageParse(pDbRecord));
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610RxStateMachine
////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610RxStateMachine(PVG610_DATABASE_STRUCT   *pDbRecord,
                              BYTE                  val,
                              BOOLEAN               *isComplete)

{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    BYTE *pBuff = pDbRecord->pRxMsg;

    *isComplete = FALSE;
    
      //   printEthStringAdd(1,pDbRecord->rxState);
       //      printEthStringAdd(1,val);

    

    switch (pDbRecord->rxState)
    {
    case PVG610_RXH_IDLE_E:
        if (val == 0x7E)
        {
            pDbRecord->rxState = PVG610_RXH_FLAG_FOUND_E;
        }
        break;

    case PVG610_RXH_FLAG_FOUND_E:
        if (val == 0x7D)
        {
            pDbRecord->rxState = PVG610_RXH_ESC_CODE_DETECTED_E;
        }
        else if (val != 0x7E)
        {
            pBuff[pDbRecord->rxTotalMsgSize] = val;
            pDbRecord->rxTotalMsgSize++;
            pDbRecord->rxState = PVG610_RXH_IN_MSG_E;
        }
        break;

    case PVG610_RXH_IN_MSG_E:
        if (val == 0x7D)
        {
            pDbRecord->rxState = PVG610_RXH_ESC_CODE_DETECTED_E;
        }
        else if (val == 0x7E)
        {
            pDbRecord->rxState = PVG610_RXH_IDLE_E; 
             
         //   printEthStringAdd(1,0x22);      //hier

            retVal = pvg610RxMessageParse(pDbRecord);
            if (retVal == PVG610_SUCCESS_MSG_E)
            {
                *isComplete = TRUE;
            }
            return(retVal);
        }
        else
        {
            pBuff[pDbRecord->rxTotalMsgSize] = val;
            pDbRecord->rxTotalMsgSize++;
        }
        break;

    case PVG610_RXH_ESC_CODE_DETECTED_E:
        if (val == 0x5E)
        {
            pBuff[pDbRecord->rxTotalMsgSize] = 0x7E;
            pDbRecord->rxTotalMsgSize++;
            pDbRecord->rxState = PVG610_RXH_IN_MSG_E;
        }
        else if (val == 0x5D)
        {
            pBuff[pDbRecord->rxTotalMsgSize] = 0x7D;
            pDbRecord->rxTotalMsgSize++;
            pDbRecord->rxState = PVG610_RXH_IN_MSG_E;
        }
        else
        {
            pDbRecord->rxTotalMsgSize = 0;
            pDbRecord->rxState = PVG610_RXH_IGNORE_E;
            retVal = PVG610_ERROR_IN_COM_RECEIVE_E;  // FLAG/other while escaped - must be an error
        }
        break;

    case PVG610_RXH_IGNORE_E:
        // not supposed to happen, but we'll allow it for now
        if (val == 0x7E)
        {
            pDbRecord->rxState = PVG610_RXH_IDLE_E;
        }
        break;
    }


    // if message is too long, ignore it
    if (pDbRecord->rxTotalMsgSize > PVG610_HOST_PROTOCOL_MAX_MSG_LEN)
    {
        pDbRecord->rxTotalMsgSize = 0;
        pDbRecord->rxState = PVG610_RXH_IGNORE_E;
        retVal = PVG610_ERROR_IN_COM_RECEIVE_E;
    }

    return(retVal);
}

///////////////////////////////////////////////////////////////////////////////
// Checks if there is an error in the msg buffer.
// return FALSE if error, else TRUE.
///////////////////////////////////////////////////////////////////////////////
BOOLEAN pvg610RxMessageValidityCheck(PVG610_DATABASE_STRUCT *pDbRecord)
{
    UINT32 checksum;
 //   printEthStringAdd(1,0x31);

    if (pDbRecord->media == PVG610_COM_MEDIA_DPRAM_E)
    {
        // Because the DPRAM works in 16 bits entries, fix the total length of the message according to the actual length
        // If the difference is 1 byte, assume that the last byte is padding
        if ((pDbRecord->rxTotalMsgSize - (pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] + PVG610_HOST_PROTOCOL_HEADER_LEN + PVG610_CHECKSUM_LEN)) == 1)
        {
            pDbRecord->rxTotalMsgSize--;
        }
    }
   //    printEthStringAdd(1,0x32);

    // check if at least header len and checksum len exist
    if (pDbRecord->rxTotalMsgSize < (PVG610_HOST_PROTOCOL_HEADER_LEN + PVG610_CHECKSUM_LEN))
    {
        return FALSE;
    }
    //ok    printEthStringAdd(1,0x33);   //hier last  ok
      //   printEthStringAdd(1,pDbRecord->rxTotalMsgSize);    //0x21
         
      //     printEthStringAdd(1,pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] );    //hier  0x3f
      //      printEthStringAdd(1, PVG610_HOST_PROTOCOL_HEADER_LEN);     //04
      //    printEthStringAdd(1, PVG610_CHECKSUM_LEN);   //04
   
    // check if at least header len and checksum len exist
    if ((UINT32)pDbRecord->rxTotalMsgSize !=
        (UINT32)(pDbRecord->pRxMsg[PVG610_MSG_LEN_OFFSET_E] + PVG610_HOST_PROTOCOL_HEADER_LEN + PVG610_CHECKSUM_LEN))
    {
        return FALSE;
    }
//ok       printEthStringAdd(1,0x34);  //to hier do mot go
    // compare the message checksum to the calculated checksum
    memcpy((void*)&checksum, pDbRecord->pRxMsg + pDbRecord->rxTotalMsgSize - PVG610_CHECKSUM_LEN, PVG610_CHECKSUM_LEN);
    if (checksum == pvg610ChecksumCalc(0, pDbRecord->pRxMsg, pDbRecord->rxTotalMsgSize - PVG610_CHECKSUM_LEN, TRUE))
    {
 //ok     printEthStringAdd(1,0x35);
        return TRUE;
        
    }
 //ok     printEthStringAdd(1,0x36);
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
// Parses host protocol message
///////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM  pvg610RxMessageParse(PVG610_DATABASE_STRUCT *pDbRecord)
{


    if (pvg610RxMessageValidityCheck(pDbRecord))
    {
        // save rx parameters in the host protocol database
        pDbRecord->rxOpcode = (PVG610_COM_OPCODE_ENUM)pDbRecord->pRxMsg[PVG610_OPCODE_OFFSET_E];
        pDbRecord->rxSequenceNumber =  pDbRecord->pRxMsg[PVG610_TASK_CONTEXT_AND_SEQ_NUM_OFFSET_E] & 0xF;
        pDbRecord->rxTaskContext = (BYTE)((pDbRecord->pRxMsg[PVG610_TASK_CONTEXT_AND_SEQ_NUM_OFFSET_E] >> 4) & 0x0F);
        pDbRecord->rxNackReason = (PVG610_ERROR_MSG_ENUM)(pDbRecord->pRxMsg[PVG610_NACK_REASON_OFFSET_E]);

        return PVG610_SUCCESS_MSG_E;
    }

    // will be silently discarded
    return PVG610_INVALID_MSG_RX_E;
}


/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610FwSendAndJump
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610FwSendAndJump(PVG610_DATABASE_STRUCT *pDbRecord, BYTE *pBuffer)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_BOOT_HEADER_MSG_STRUCT *pHeader;
    PVG610_BOOT_DATA_RECORD_HEADER_STRUCT *pRecordHeader;
    PVG610_BOOT_DATA_RECORD_HEADER_STRUCT nullRecordHeader = {0,0,0};
    INT32 totalLen;
    UINT32 offset = sizeof(UINT32); // skip the burn number
    UINT16 size;
    BOOLEAN bigEndian;
    
 //ok   return;
 //     printf("\n\rpvg610FwSendAndJump");

    bigEndian = pvg610IsBigEndian();
    
//ok    return;
 //01 02 03 04 05 31 32 33 34 06 21 31 32 33 34 22 23 26 31 32 35 09    
  //   printEthStringAdd(1,0x21);

    // header message
    pHeader = (PVG610_BOOT_HEADER_MSG_STRUCT *)&pBuffer[offset];
 //ok   return;
 
    retVal = pvg610BuildSendAndReceive(pDbRecord,
                                 (BYTE*)pHeader,
                                 sizeof(PVG610_BOOT_HEADER_MSG_STRUCT),
                                 PVG610_COM_BOOT_HEADER_MSG_OPCODE_E,
                                 0);
                                 
                                 
//  ok  return 0;
                                 
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
#ifndef MAKET_PLATA    
#ifndef TEST_BMDN
        return(retVal);
#endif        
#endif //  MAKET_PLATA       
        
    }
   //  printEthStringAdd(1,0x22);
     
    // skip the SW header and the boot fw
    offset += sizeof(PVG610_BOOT_HEADER_MSG_STRUCT) + PVG610_BOOT_FW_SIZE_BYTES;

    // data messages
    if (bigEndian)
    {
        totalLen = pvg610EndianConversion((BYTE*)&pHeader->totalLength, sizeof(UINT32)) - PVG610_BOOT_FW_SIZE_BYTES;
    }
    else
    {
        totalLen = pHeader->totalLength - PVG610_BOOT_FW_SIZE_BYTES;
    }
    
 //    printEthStringAdd(1,0x23);
//  printEthStringAdd(1,pHeader->totalLength >> 24);   //02 
//printEthStringAdd(1,pHeader->totalLength >> 16);    //ff
//printEthStringAdd(1,pHeader->totalLength >> 8);     //e0
//printEthStringAdd(1,pHeader->totalLength >> 0);     //00
   
     
//   totalLen = 1000; //for test  
     
     
// printEthStringAdd(1,totalLen >> 24);   //02 
//printEthStringAdd(1,totalLen >> 16);    //ff
//printEthStringAdd(1,totalLen >> 8);     //e0
//printEthStringAdd(1,totalLen >> 0);     //00
    
  //ok  return 0;  
  
    //  printf("\n\r %d",totalLen );

    
    while (totalLen > 0)
    {
    
  //  printf("\n\r %d",totalLen );
    wd_reset();
  //  return(0); //t
        // if address bytes are all 0 ==> zero padding reached ==> no more data records to send.
      
   //    printEthStringAdd(1,pBuffer[offset]);
    //     printEthStringAdd(1,nullRecordHeader.address);

//#ifndef MAKET_PLATA      //!!!!!!!!!!!!!!!!!!maiby need olweis
        if (!memcmp(&pBuffer[offset],&nullRecordHeader, 4))
        {
            offset += totalLen;
        //    break;
     //     printEthStringAdd(1,0x75);  
             break;
        }
//#endif
        
   //     printEthStringAdd(1,0x26);     //ok

        
        pRecordHeader = (PVG610_BOOT_DATA_RECORD_HEADER_STRUCT*)&pBuffer[offset];

        if (bigEndian)
        {
            size = pvg610EndianConversion((BYTE*)&pRecordHeader->size, sizeof(UINT16));
        }
        else
        {
            size = pRecordHeader->size;
        }
//  01 02 03 04 05 31 32 33 34 06 21 31 32 33 34 22 23 26 31 32 09 

#ifdef PRINT_USART_DATA   
//printEthStringAdd(1,0x72); 
//print_flag   = 1; //make printing on
/*       
printEthStringAdd(1,totalLen >> 24);    
printEthStringAdd(1,totalLen >> 16); 
printEthStringAdd(1,totalLen >> 8); 
printEthStringAdd(1,totalLen >> 0); 

printEthStringAdd(1,0x73); 
//print_flag   = 1; //make printing on
       
printEthStringAdd(1,offset >> 24);    
printEthStringAdd(1,offset >> 16); 
printEthStringAdd(1,offset >> 8); 
printEthStringAdd(1,offset >> 0); 

 */
#endif

        retVal = pvg610BuildSendAndReceive(pDbRecord,
                                    (BYTE*)&pBuffer[offset],
                                     sizeof(PVG610_BOOT_DATA_RECORD_HEADER_STRUCT) + size,
                                     PVG610_COM_BOOT_DATA_MSG_OPCODE_E,
                                     0);
                                     
                                     
   //ok      return 0; //t
         
       //   printEthStringAdd(1,0x27);
          
       //     printEthStringAdd(1,PVG610_COM_BOOT_DATA_MSG_OPCODE_E);

          
 //         printEthLongHex(0x10 * retVal);
          
                   
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
#ifndef MAKET_PLATA 
#ifndef TEST_BMDN        
            return(retVal);
#endif
#endif            
        }

      //    printEthStringAdd(1,0x28);   //not

        if (totalLen < 0)
        {
            return(PVG610_BOOT_DATA_TOO_BIG_E);
        }
        //    printEthStringAdd(1,0x29);


        offset += sizeof(PVG610_BOOT_DATA_RECORD_HEADER_STRUCT) + size;
        totalLen -= sizeof(PVG610_BOOT_DATA_RECORD_HEADER_STRUCT) + size;
        
   //    OperateBuffers_usart1t(); //100415 
        
//      break; //t
    }
    
   //      printEthStringAdd(1,0x24);
         
    //     printEthStringAdd(1,size >> 24);    
//printEthStringAdd(1,size >> 16); 
//printEthStringAdd(1,size >> 8); 
//printEthStringAdd(1,size >> 0);       //ec


    // checksum message
    retVal = pvg610BuildSendAndReceive(pDbRecord,
                                 (BYTE*)&pBuffer[offset],
                                 sizeof(UINT32),
                                 PVG610_COM_BOOT_CHECKSUM_MSG_OPCODE_E,
                                 0);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
 #ifndef MAKET_PLATA   
#ifndef TEST_BMDN  
        return(retVal);
 #endif       
 #endif     
    }
    
  //     printEthStringAdd(1,0x25);


    // jump message
    retVal = pvg610BuildSend(pDbRecord,
                       NULL,
                       0,
                       PVG610_COM_JUMP_TO_FW_MSG_OPCODE_E,
                       0);

   return retVal;
}

/////////////////////////// //////////////////////////////////////////////////////
//  FUNCTION: pvg610IsAlive
/////////////////////////////////////////////////////////////////////////////////
BOOLEAN pvg610IsAlive(PVG610_DATABASE_STRUCT *pDbRecord, UINT32 timeInMs, UINT32 tries)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_MODEM_VERSION_STRUCT ver;
    UINT32 savedTimeOutMilli;

    // save the current timeout val
    savedTimeOutMilli = pDbRecord->rxTimeoutMilli;
    // set the new timeout val
    pDbRecord->rxTimeoutMilli = timeInMs; // 1 sec

    // Sleep 100 ms anyway
    pvg610HostSleep((UINT32)timeInMs * 1000);
  
  //  pvg610HostSleep((UINT32)timeInMs * 10);      //t

    while(tries)
    {
         pvg610HostSleep((UINT32)timeInMs * 1000); 
         
   //    printEthStringAdd(1,tries*0x10);
       
        retVal = PVG610_API_VersionGet(pDbRecord->deviceIndex, &ver);
        
   //     printEthStringAdd(1,retVal);
 
        if (retVal == PVG610_INVALID_MSG_OPCODE_E || retVal == PVG610_SUCCESS_MSG_E)
        {
            // restore timeout
            pDbRecord->rxTimeoutMilli = savedTimeOutMilli;
            return TRUE;
        }

        tries--;
    }

    // restore timeout
    pDbRecord->rxTimeoutMilli = savedTimeOutMilli;
    return(FALSE);
}

/////////////////////////////////////////////////////////////////////////////////
//  FUNCTION: pvg610MessageRelay
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610MessageRelay(BYTE srcDeviceIndex, BYTE destDeviceIndex)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_DATABASE_STRUCT *pSource = &gPvg610Database[srcDeviceIndex];
    PVG610_DATABASE_STRUCT *pDest = &gPvg610Database[destDeviceIndex];

    // clear rx message size for the source request
    pSource->rxState = PVG610_RXH_IDLE_E;
    pSource->rxTotalMsgSize = 0;

    // receive from source
    retVal = pvg610MessageReceive(pSource);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return(retVal);
    }

    pvg610HostMutexGet(destDeviceIndex);

    do
    {
        // copy RX source to TX dest
        memcpy(pDest->pTxMsg, pSource->pRxMsg, pSource->rxTotalMsgSize);
        pDest->txTotalMsgSize = pSource->rxTotalMsgSize;

        // clear rx message size for the dest response
        pDest->rxState = PVG610_RXH_IDLE_E;
        pDest->rxTotalMsgSize = 0;

        // send to dest
        retVal = pvg610MessageSend(pDest);
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        if (pSource->rxOpcode == PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E ||
            pSource->rxOpcode == PVG610_COM_JUMP_TO_FW_MSG_OPCODE_E)
        {
            // these cases are not expected to return an answer
            break;
        }

        // receive from dest
        retVal = pvg610MessageReceive(pDest);
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        // copy RX source to TX dest
        memcpy(pSource->pTxMsg, pDest->pRxMsg, pDest->rxTotalMsgSize);
        pSource->txTotalMsgSize = pDest->rxTotalMsgSize;

        // send response back to source
        retVal = pvg610MessageSend(pSource);

    } while(0);

    pvg610HostMutexRelease(destDeviceIndex);

    return(retVal);
}

PVG610_ERROR_MSG_ENUM pvg610MessageForward(BYTE deviceIndex, BYTE *pReqBuffer, INT32 reqLen, BYTE *pRespBuffer, INT32 *pRespLen)
{
    PVG610_ERROR_MSG_ENUM retVal = PVG610_SUCCESS_MSG_E;
    PVG610_DATABASE_STRUCT *pDest = &gPvg610Database[deviceIndex];

    pvg610HostMutexGet(deviceIndex);

    do
    {
        // boot message - GUI may chop to chunks of 512 byte
        if (reqLen > PVG610_HOST_PROTOCOL_MAX_MSG_LEN)
        {
            retVal = pvg610RawDataSend(pDest, pReqBuffer, reqLen);
            *pRespLen = 0;
            break;
        }

        // copy RX req to TX dest
        memcpy(pDest->pTxMsg, pReqBuffer, reqLen);
        pDest->txTotalMsgSize = reqLen;

        // clear rx message size for the dest response
        pDest->rxState = PVG610_RXH_IDLE_E;
        pDest->rxTotalMsgSize = 0;

        // send to dest
        retVal = pvg610MessageSend(pDest);
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        if (pReqBuffer[PVG610_OPCODE_OFFSET_E] == PVG610_COM_BOOT_FW_JUMP_MSG_OPCODE_E ||
            pReqBuffer[PVG610_OPCODE_OFFSET_E] == PVG610_COM_JUMP_TO_FW_MSG_OPCODE_E)
        {
            // these cases are not expected to return an answer
            *pRespLen = 0;
            break;
        }

        // receive from dest
        retVal = pvg610MessageReceive(pDest);
        if (retVal != PVG610_SUCCESS_MSG_E)
        {
            break;
        }

        // copy RX source to TX dest
        memcpy(pRespBuffer, pDest->pRxMsg, pDest->rxTotalMsgSize);
        *pRespLen = pDest->rxTotalMsgSize;

    } while(0);

    pvg610HostMutexRelease(deviceIndex);

    return(retVal);
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610FlashConfigFileOperation(BYTE deviceIndex, BYTE modemIndex, PVG610_COM_OPCODE_ENUM opcode)
{
    PVG610_ERROR_MSG_ENUM  retVal;
    UINT32                 startTime = pvg610HostTickGet();

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 NULL,
                                 0,
                                 opcode,
                                 modemIndex);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = PVG610_PERIPHERAL_NOT_READY_E;
    while (retVal == PVG610_PERIPHERAL_NOT_READY_E)
    {
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     NULL,
                                     0,
                                     PVG610_COM_FLASH_FINISH_OPCODE_E,
                                     modemIndex);
       if (retVal == PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }
        else if (retVal == PVG610_PERIPHERAL_NOT_READY_E)
        {
            if ((pvg610HostTickGet() - startTime) > PVG610_FLASH_OPERATION_TIMEOUT_MILLI)
            {
                return PVG610_FLASH_TIMEOUT_E;
            }
            pvg610HostSleep(PVG610_FLASH_POLLING_TIMEOUT_MICRO);
        }
    }


    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610FlashFwOperation(BYTE deviceIndex, PVG610_COM_OPCODE_ENUM opcode, PVG610_FIRMWARE_INDEX_ENUM fwIndex)
{
    PVG610_ERROR_MSG_ENUM  retVal;
    UINT32                 startTime = pvg610HostTickGet();

    retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                 (BYTE*)&fwIndex,
                                 sizeof(BYTE),
                                 opcode,
                                 0);
    if (retVal != PVG610_SUCCESS_MSG_E)
    {
        return retVal;
    }

    retVal = pvg610FlashFinish(deviceIndex, 0, startTime);

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
PVG610_ERROR_MSG_ENUM pvg610FlashFinish(BYTE deviceIndex, BYTE modemIndex, UINT32 startTime)
{
    PVG610_ERROR_MSG_ENUM  retVal;

    retVal = PVG610_PERIPHERAL_NOT_READY_E;
    while (retVal == PVG610_PERIPHERAL_NOT_READY_E)
    {
        retVal = pvg610BuildSendAndReceive(&gPvg610Database[deviceIndex],
                                     NULL,
                                     0,
                                     PVG610_COM_FLASH_FINISH_OPCODE_E,
                                     modemIndex);
        if (retVal == PVG610_SUCCESS_MSG_E)
        {
            return retVal;
        }
        else if (retVal == PVG610_PERIPHERAL_NOT_READY_E)
        {
            if ((pvg610HostTickGet() - startTime) > PVG610_FLASH_OPERATION_TIMEOUT_MILLI)
            {
                return PVG610_FLASH_TIMEOUT_E;
            }
            pvg610HostSleep(PVG610_FLASH_POLLING_TIMEOUT_MICRO);
        }
    }

    return retVal;
}



///////////////////////////////////////////////////////////////////////////////
// Peipherals
///////////////////////////////////////////////////////////////////////////////

void SendAndJump(unsigned char * pBuffer)
{
//ok return; //t  
 pvg610FwSendAndJump(&gPvg610Database[0],  pBuffer);
  
}
