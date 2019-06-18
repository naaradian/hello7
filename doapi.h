/*************************************************************************/
/** This file and the information contain herein is provided "AS IS"    **/
/** without warranty of any kind, either expressed or implied,          **/
/** including but not limited to the implied warranties of              **/
/** merchantability and/or fitness for a particular purpose.            **/
/**                                                                     **/
/** This code cannot be redistributed or reused in any form whatsoever  **/
/** without the explicit approval of Conexant Systems, Inc.             **/
/**                                                                     **/
/** Copyright (C) 2002 Conexant Systems, Inc.                           **/
/** All rights reserved.                                                **/
/*************************************************************************/


#ifndef _DOAPI_H
#define _DOAPI_H

#include <fwid.h>

#pragma pack(1)

enum eReturnCodes {
        RC_SUCCESS                              = 0x00000000,   /* Successful completion */
        RC_ERROR_INVALIDPARAMETER               = 0x88000000,   /* One or more of the formal parameters are out of range */
        RC_ERROR_UNKOWN                         = 0x88000001,   /* Unknown error */
        RC_ERROR_ROM_DOWNLOAD_FILEOPEN          = 0x88000010,   /* Error openning the rom file */
        RC_ERROR_ROM_DOWNLOAD_DATATXFER         = 0x88000020,   /* Error transferring the rom image to the device */
        RC_ERROR_DEVICE_UNINITIALIZED           = 0x88000100,   /* Error initializing the device */
        RC_ERROR_DEVICE_MEMWRITE                = 0x88000200,   /* Error writing to iVAC memory */
        RC_ERROR_DEVICE_MEMREAD                 = 0x88000400,   /* Error reading from iVAC memory */
};

#define DECODER_CMD_OFFSET  0
#define GRAPHICS_CMD_OFFSET  64
#define ENCODER_CMD_OFFSET   128

typedef enum eApiCommandCode
{
    ApiCommand_NoOperation                      = DECODER_CMD_OFFSET  +  0,	
    ApiCommand_StartPlayback                    = DECODER_CMD_OFFSET  +  1, 
    ApiCommand_StopPlayback                     = DECODER_CMD_OFFSET  +  2,
    ApiCommand_SetTrickMode                     = DECODER_CMD_OFFSET  +  3,   
    ApiCommand_SlowMotion                       = DECODER_CMD_OFFSET  +  4,
    ApiCommand_Step                             = DECODER_CMD_OFFSET  +  5,
    ApiCommand_SelectAudioStream                = DECODER_CMD_OFFSET  +  6,
    ApiCommand_SetStreamInputType               = DECODER_CMD_OFFSET  +  7,
    ApiCommand_SetDmaBlockSize                  = DECODER_CMD_OFFSET  +  8,
    ApiCommand_GetDmaTransferInfo               = DECODER_CMD_OFFSET  +  9,
    ApiCommand_GetDmaTransferStatus             = DECODER_CMD_OFFSET  +  10,
    ApiCommand_SetDmaFromHostLinkAddress        = DECODER_CMD_OFFSET  +  11,
    ApiCommand_SetDmaToHostLinkAddress          = DECODER_CMD_OFFSET  +  12,
    ApiCommand_PausePlayback                    = DECODER_CMD_OFFSET  +  13,
    ApiCommand_StopDecFirmware                  = DECODER_CMD_OFFSET  +  14,
    ApiCommand_GetBitStreamInfo                 = DECODER_CMD_OFFSET  +  15,
    ApiCommand_SetDiplayMode                    = DECODER_CMD_OFFSET  +  16,
    ApiCommand_GetDecoderFWVersion              = DECODER_CMD_OFFSET  +  17,
    ApiCommand_GetCurrentFrameInfo              = DECODER_CMD_OFFSET  +  21,
    ApiCommand_SetAudioModeChangeAction         = DECODER_CMD_OFFSET  +  22,
    ApiCommand_SetEventNotification             = DECODER_CMD_OFFSET  +  23,
    ApiCommand_SetNumberOfDisplayBuffers        = DECODER_CMD_OFFSET  +  24,
    ApiCommand_ExtractVBIData                   = DECODER_CMD_OFFSET  +  25,
	ApiCommand_SetDecoderMode					= DECODER_CMD_OFFSET  +  26, //0x1A
    ApiCommand_SetPTAudioDelayFrames            = DECODER_CMD_OFFSET  +  31, //0x1F
    ApiCommand_SetTransportPIDs                 = DECODER_CMD_OFFSET  +  32,
    
    ApiCommand_GetGraphicsBufferSpace           = GRAPHICS_CMD_OFFSET  +  1, //0x41
    ApiCommand_GetOSDPixelFormat                = GRAPHICS_CMD_OFFSET  +  2, //0x42
    ApiCommand_SetOSDPixelFormat                = GRAPHICS_CMD_OFFSET  +  3, //0x43
    ApiCommand_GetOSDState                      = GRAPHICS_CMD_OFFSET  +  4, //0x44
    ApiCommand_SetOSDState                      = GRAPHICS_CMD_OFFSET  +  5, //0x45
    ApiCommand_GetOSDDisplayedBuffer            = GRAPHICS_CMD_OFFSET  +  6, //0x46
    ApiCommand_SetOSDDisplayedBuffer            = GRAPHICS_CMD_OFFSET  +  7, //0x47
    ApiCommand_GetOSDScreenCoordinates          = GRAPHICS_CMD_OFFSET  +  8, //0x48
    ApiCommand_SetOSDScreenCoordinates          = GRAPHICS_CMD_OFFSET  +  9, //0x49
    ApiCommand_GetGlobalAlpha                   = GRAPHICS_CMD_OFFSET  +  10, //0x4a
    ApiCommand_SetGlobalAlpha                   = GRAPHICS_CMD_OFFSET  +  11, //0x4b
    ApiCommand_GetOSDCLUTData                   = GRAPHICS_CMD_OFFSET  +  12, //0x4c
    ApiCommand_SetOSDCLUTData                   = GRAPHICS_CMD_OFFSET  +  13, //0x4d
    ApiCommand_MoveOSDBuffer                    = GRAPHICS_CMD_OFFSET  +  14, //0x4e
    ApiCommand_GetOSDDeflickerState             = GRAPHICS_CMD_OFFSET  +  15, //0x4f
    ApiCommand_SetOSDDeflickerState             = GRAPHICS_CMD_OFFSET  +  16, //0x50      
    ApiCommand_GetBLTState                      = GRAPHICS_CMD_OFFSET  +  17, //0x51
    ApiCommand_BLTCopy                          = GRAPHICS_CMD_OFFSET  +  18, //0x52
    ApiCommand_BLTFillColor                     = GRAPHICS_CMD_OFFSET  +  19, //0x53
    ApiCommand_BLTExpandText                    = GRAPHICS_CMD_OFFSET  +  20, //0x54
    ApiCommand_ExcuteBLTCmdList                 = GRAPHICS_CMD_OFFSET  +  21, //0x55
    ApiCommand_SetVideoScreenCoordinates        = GRAPHICS_CMD_OFFSET  +  22, //0x56
    ApiCommand_SetOSDChromaKey                  = GRAPHICS_CMD_OFFSET  +  32, //0x60
    ApiCommand_GetLocalAlphaConstant            = GRAPHICS_CMD_OFFSET  +  33, //0x61
    ApiCommand_SetLocalAlphaConstant            = GRAPHICS_CMD_OFFSET  +  34, //0x62


    Encoder_NoOperation                         = ENCODER_CMD_OFFSET +  0,  //0x80
    Encoder_StartCapture                        = ENCODER_CMD_OFFSET +  1,  //0x81
    Encoder_StopCapture                         = ENCODER_CMD_OFFSET +  2,  //0x82
    Encoder_SetVideoFrameRate                   = ENCODER_CMD_OFFSET + 15,  //0x8f
    Encoder_SetVideoResolution                  = ENCODER_CMD_OFFSET + 17,  //0x91
    Encoder_SetVideoBitrate                     = ENCODER_CMD_OFFSET + 21,  //0x95
    Encoder_SetGOPStructure                     = ENCODER_CMD_OFFSET + 23,  //0x97
    Encoder_SetAspectRatio                      = ENCODER_CMD_OFFSET + 25,  //0x99
    Encoder_SetClosedGOP                        = ENCODER_CMD_OFFSET + 69,  //0xc5

    Encoder_SetInverseTelecine                  = ENCODER_CMD_OFFSET + 49,  //0xb1

    // Dynamic Noise Reduction
    Encoder_SetDnrMode                          = ENCODER_CMD_OFFSET + 27,  //0x9b
    Encoder_SetStaticDnrParams                  = ENCODER_CMD_OFFSET + 29,  //0x9d
    Encoder_SetDnrMedianCoring                  = ENCODER_CMD_OFFSET + 31,  //0x9f
    Encoder_SetSpatialFilterType                = ENCODER_CMD_OFFSET + 33,  //0xa1
    Encoder_SetSpatialFilterCoeff               = ENCODER_CMD_OFFSET + 35,  //0xa3
    Encoder_SetDnrNltfParams                    = ENCODER_CMD_OFFSET + 39,  //0xa7

    // Scene Change Detect
    Encoder_SetDnrSceneChangeDetect             = ENCODER_CMD_OFFSET + 37,  //0xa5

    Encoder_SetStreamOutputType                 = ENCODER_CMD_OFFSET + 57,  //0xb9
    Encoder_SetStreamOutputPort                 = ENCODER_CMD_OFFSET + 59,  //0xbb
    Encoder_SetMPEGAudioEncodingParameters      = ENCODER_CMD_OFFSET + 61,  //0xbd
    Encoder_StopFirmware                        = ENCODER_CMD_OFFSET + 67,  //0xC3
    ApiCommand_GetEncoderFWVersion              = ENCODER_CMD_OFFSET + 68,  //0xC4
    Encoder_GetDataXferStatus                   = ENCODER_CMD_OFFSET + 70,  //0xC6 
    ApiCommand_IndexTblParams                   = ENCODER_CMD_OFFSET + 71,  //0xc7
    //Encoder DMA transfer
    Encoder_SetDmaBlockSize                     = ENCODER_CMD_OFFSET + 73,  //0xc9
    Encoder_GetDmaTransferInfo                  = ENCODER_CMD_OFFSET + 74,  //0xca
    Encoder_GetDmaTransferStatus                = ENCODER_CMD_OFFSET + 75,  //0xcb
    Encoder_SetDmaToHostLinkAddress             = ENCODER_CMD_OFFSET + 76,  //0xcc
    Encoder_SetVBILineInfo                      = ENCODER_CMD_OFFSET + 55,  //0xb7
    Encoder_SetVBIInfo                          = ENCODER_CMD_OFFSET + 72,  //0xc8
    Encoder_InputInit                           = ENCODER_CMD_OFFSET + 77,  //0xcd
    Encoder_SetSkipInputFrame                   = ENCODER_CMD_OFFSET + 80,  //0xd0
    Encoder_SceneChangeDetection                = ENCODER_CMD_OFFSET + 81,  //0xd1
    Encoder_PauseResumeEncoder                  = ENCODER_CMD_OFFSET + 82,  //0xd2
    Encoder_InputRefresh                        = ENCODER_CMD_OFFSET + 83,  //0xd3
	Encoder_SetCopyRight						= ENCODER_CMD_OFFSET + 84,  //0xd4
	Encoder_EventNotification					= ENCODER_CMD_OFFSET + 85,  //0xd5
	Encoder_SetVSyncLineCount					= ENCODER_CMD_OFFSET + 86,  //0xd6
	Encoder_ProvidePlaceHolder					= ENCODER_CMD_OFFSET + 88,  //0xd8
	Encoder_SetVideoMute						= ENCODER_CMD_OFFSET + 89,  //0xd9
	Encoder_SetAudioMute						= ENCODER_CMD_OFFSET + 90,  //0xda
	Encoder_SetVerCropLine						= ENCODER_CMD_OFFSET + 91,  //0xdb
	Encoder_SetMiscParameters					= ENCODER_CMD_OFFSET + 92,  //0xdc

} API_COMMAND_CODE;

#pragma pack()

#endif //_DOAPI_H

