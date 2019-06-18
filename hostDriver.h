#ifndef _HOST_DRIVER_H_
#define _HOST_DRIVER_H_

#include "defs610.h"
#include "PVG610_API.h"


#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------
    Defintions needed for DPRAM
------------------------------------------------------*/
#define PVG610_DPRAM_TX_WDATA_REG                   0xf006  // TX write data register
#define PVG610_DPRAM_RX_WDATA_REG                   0xf010  // TX write data register
#define PVG610_DPRAM_TX_RDATA_REG                   0xf007  // TX read data register
#define PVG610_DPRAM_TX_LEVEL_REG                   0xf00a  // tx level
#define PVG610_DPRAM_RX_RDATA_REG                   0xf017  // rx read data register
#define PVG610_DPRAM_RX_LEVEL_REG                   0xf01a  // rx level
#define PVG610_DPRAM_DONE_REG                       0xf020  // DPRAM access done
#define PVG610_DPRAM_TO_EXT_STATUS_REG              0xf024  // Interrupt status - external host
#define PVG610_DPRAM_TO_EXT_STATUS_NS_REG           0xf025  // Interrupt status - external host (non sticky)
#define PVG610_DPRAM_TO_EXT_INT_MASK_REG            0xf027  // DPRAM to external host interrupts mask register

#define PVG610_DPRAM_WRITE_DONE_BIT_E               0
#define PVG610_DPRAM_READ_DONE_BIT_E                1

/*------------------------------------------------------
    General functions
------------------------------------------------------*/
void    pvg610HostDeviceReset      (BYTE deviceIndex, PVG610_DEVICE_RESET_TYPE_ENUM resetType);
void    pvg610HostSleep            (UINT32 sleepTimeMicro);
UINT32  pvg610HostTickGet          (void);
void    pvg610HostMutexGet         (BYTE deviceIndex);
void    pvg610HostMutexRelease     (BYTE deviceIndex);

/*------------------------------------------------------
    UART functions
------------------------------------------------------*/
void    pvg610HostUartReceiverFlush(BYTE deviceIndex);
void    pvg610HostUartDataSend     (BYTE deviceIndex, BYTE *pBuff, UINT32 buffLen);
void    pvg610HostUartDataReceive  (BYTE deviceIndex, /*@out@*/ BYTE *pBuff, UINT32 buffLen, UINT16 timeoutMilli, /*@out@*/ UINT32 *pReadBytes);

/*------------------------------------------------------
    SPI functions
------------------------------------------------------*/
unsigned char    pvg610HostSpiDataSend      (BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen);
void    pvg610HostSpiDataSendx      (BYTE deviceIndex, BYTE *pTxBuff, UINT32 buffLen);
void    pvg610HostSpiDataReceive   (BYTE deviceIndex, BYTE *pTxBuff, /*@out@*/ BYTE *pRxBuff, UINT32 buffLen);

/*------------------------------------------------------
    DPRAM functions
------------------------------------------------------*/
void    pvg610HostDpramDataWrite   (BYTE deviceIndex, UINT16 indirectAddress, BYTE *pBuff, UINT32 buffLen);
void    pvg610HostDpramDataRead    (BYTE deviceIndex, UINT16 indirectAddress, /*@out@*/ BYTE *pBuff, UINT32 buffLen);
BOOLEAN pvg610HostDpramWait        (BYTE deviceIndex, UINT16 timeoutMilli);

#ifdef __cplusplus
}
#endif

#endif  /*_HOST_DRIVER_H_*/



