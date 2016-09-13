#ifndef ENDIAN_H
#define ENDIAN_H

#include "defs610.h"
#include "hostProtocolOpcodes.h"
#include "hostProtocolStructs.h"

///////////////////////////////////////////////////////////////////////////////
// ENUM
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// External function decleration
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
// Configure endian swapping
///////////////////////////////////////////////////////////////////////////////
void pvg610EndianConversionConfigure(BOOLEAN enabled);

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610RequestParamSwap(PVG610_COM_OPCODE_ENUM    opcode,
                            BYTE                      *pMsgBuffer,
                            UINT32                    msgBufferLen);
                                                
///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void pvg610ResponseParamSwap(PVG610_COM_OPCODE_ENUM    opcode,
                             BYTE                      *pMsgBuffer,
                             UINT32                    msgBufferLen);

#ifdef __cplusplus
}
#endif

#endif

