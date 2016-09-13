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

// port const unsigned long VideoPID = 0x0000012c;
// port const unsigned long AudioPID = 0x0000012d;
//port const unsigned long AuxPID   = 0x00000065;

#define VideoPID (0x0000012c)
#define AudioPID (0x0000012d)
#define AuxPID   (0x00000065)



//enum eReturnCodes {
//port const unsigned long        RC_SUCCESS                              = 0x00000000;   /* Successful completion */
//portconst unsigned long        RC_ERROR_INVALIDPARAMETER               = 0x88000000;   /* One or more of the formal parameters are out of range */
//portconst unsigned long        RC_ERROR_UNKOWN                         = 0x88000001;   /* Unknown error */
//portconst unsigned long        RC_ERROR_ROM_DOWNLOAD_FILEOPEN          = 0x88000010;   /* Error openning the rom file */
//portconst unsigned long        RC_ERROR_ROM_DOWNLOAD_DATATXFER         = 0x88000020;   /* Error transferring the rom image to the device */
//portconst unsigned long        RC_ERROR_DEVICE_UNINITIALIZED           = 0x88000100;   /* Error initializing the device */
//portconst unsigned long        RC_ERROR_DEVICE_MEMWRITE                = 0x88000200;   /* Error writing to iVAC memory */
//portconst unsigned long        RC_ERROR_DEVICE_MEMREAD                 = 0x88000400;   /* Error reading from iVAC memory */
//};

#define 	   RC_SUCCESS  								(0x00000000)   /* Successful completion */
#define        RC_ERROR_INVALIDPARAMETER                (0x88000000)   /* One or more of the formal parameters are out of range */
#define        RC_ERROR_UNKOWN                          (0x88000001)   /* Unknown error */
#define        RC_ERROR_ROM_DOWNLOAD_FILEOPEN           (0x88000010)   /* Error openning the rom file */
#define        RC_ERROR_ROM_DOWNLOAD_DATATXFER          (0x88000020)   /* Error transferring the rom image to the device */
#define        RC_ERROR_DEVICE_UNINITIALIZED            (0x88000100)   /* Error initializing the device */
#define        RC_ERROR_DEVICE_MEMWRITE                 (0x88000200)   /* Error writing to iVAC memory */
#define        RC_ERROR_DEVICE_MEMREAD                  (0x88000400)   /* Error reading from iVAC memory */




#define DECODER_CMD_OFFSET  0
#define GRAPHICS_CMD_OFFSET  64
#define ENCODER_CMD_OFFSET   128

//porttypedef enum eApiCommandCode
//port {
#define    ApiCommand_NoOperation                       (DECODER_CMD_OFFSET  +  0)	
#define    ApiCommand_StartPlayback                     (DECODER_CMD_OFFSET  +  1) 
#define    ApiCommand_StopPlayback                      (DECODER_CMD_OFFSET  +  2)
#define    ApiCommand_SetTrickMode                      (DECODER_CMD_OFFSET  +  3)   
#define    ApiCommand_SlowMotion                        (DECODER_CMD_OFFSET  +  4)
#define    ApiCommand_Step                              (DECODER_CMD_OFFSET  +  5)
#define    ApiCommand_SelectAudioStream                 (DECODER_CMD_OFFSET  +  6)
#define    ApiCommand_SetStreamInputType                (DECODER_CMD_OFFSET  +  7)
#define    ApiCommand_SetDmaBlockSize                   (DECODER_CMD_OFFSET  +  8)
#define    ApiCommand_GetDmaTransferInfo                (DECODER_CMD_OFFSET  +  9)
#define    ApiCommand_GetDmaTransferStatus              (DECODER_CMD_OFFSET  +  10)
#define    ApiCommand_SetDmaFromHostLinkAddress         (DECODER_CMD_OFFSET  +  11)
#define    ApiCommand_SetDmaToHostLinkAddress           (DECODER_CMD_OFFSET  +  12)
#define    ApiCommand_PausePlayback                     (DECODER_CMD_OFFSET  +  13)
#define    ApiCommand_StopDecFirmware                   (DECODER_CMD_OFFSET  +  14)
#define    ApiCommand_GetBitStreamInfo                  (DECODER_CMD_OFFSET  +  15)
#define    ApiCommand_SetDiplayMode                     (DECODER_CMD_OFFSET  +  16)
#define    ApiCommand_GetDecoderFWVersion               (DECODER_CMD_OFFSET  +  17)
#define    ApiCommand_GetCurrentFrameInfo               (DECODER_CMD_OFFSET  +  21)
#define    ApiCommand_SetAudioModeChangeAction          (DECODER_CMD_OFFSET  +  22)
#define    ApiCommand_SetEventNotification              (DECODER_CMD_OFFSET  +  23)
#define    ApiCommand_SetNumberOfDisplayBuffers         (DECODER_CMD_OFFSET  +  24)
#define    ApiCommand_ExtractVBIData                    (DECODER_CMD_OFFSET  +  25)
#define  	ApiCommand_SetDecoderMode				    (DECODER_CMD_OFFSET  +  26) //0x1A
#define    ApiCommand_SetPTAudioDelayFrames             (DECODER_CMD_OFFSET  +  31) //0x1F
#define    ApiCommand_SetTransportPIDs                  (DECODER_CMD_OFFSET  +  32)
    
#define    ApiCommand_GetGraphicsBufferSpace            (GRAPHICS_CMD_OFFSET  +  1) //0x41
#define    ApiCommand_GetOSDPixelFormat                 (GRAPHICS_CMD_OFFSET  +  2) //0x42
#define    ApiCommand_SetOSDPixelFormat                 (GRAPHICS_CMD_OFFSET  +  3) //0x43
#define    ApiCommand_GetOSDState                       (GRAPHICS_CMD_OFFSET  +  4) //0x44
#define    ApiCommand_SetOSDState                       (GRAPHICS_CMD_OFFSET  +  5) //0x45
#define    ApiCommand_GetOSDDisplayedBuffer             (GRAPHICS_CMD_OFFSET  +  6) //0x46
#define    ApiCommand_SetOSDDisplayedBuffer             (GRAPHICS_CMD_OFFSET  +  7) //0x47
#define    ApiCommand_GetOSDScreenCoordinates           (GRAPHICS_CMD_OFFSET  +  8) //0x48
#define    ApiCommand_SetOSDScreenCoordinates           (GRAPHICS_CMD_OFFSET  +  9) //0x49
#define    ApiCommand_GetGlobalAlpha                    (GRAPHICS_CMD_OFFSET  +  10) //0x4a
#define    ApiCommand_SetGlobalAlpha                    (GRAPHICS_CMD_OFFSET  +  11) //0x4b
#define    ApiCommand_GetOSDCLUTData                    (GRAPHICS_CMD_OFFSET  +  12) //0x4c
#define    ApiCommand_SetOSDCLUTData                    (GRAPHICS_CMD_OFFSET  +  13) //0x4d
#define    ApiCommand_MoveOSDBuffer                     (GRAPHICS_CMD_OFFSET  +  14) //0x4e
#define    ApiCommand_GetOSDDeflickerState              (GRAPHICS_CMD_OFFSET  +  15) //0x4f
#define    ApiCommand_SetOSDDeflickerState              (GRAPHICS_CMD_OFFSET  +  16) //0x50      
#define    ApiCommand_GetBLTState                       (GRAPHICS_CMD_OFFSET  +  17) //0x51
#define    ApiCommand_BLTCopy                           (GRAPHICS_CMD_OFFSET  +  18) //0x52
#define    ApiCommand_BLTFillColor                      (GRAPHICS_CMD_OFFSET  +  19) //0x53
#define    ApiCommand_BLTExpandText                     (GRAPHICS_CMD_OFFSET  +  20) //0x54
#define    ApiCommand_ExcuteBLTCmdList                  (GRAPHICS_CMD_OFFSET  +  21) //0x55
#define    ApiCommand_SetVideoScreenCoordinates         (GRAPHICS_CMD_OFFSET  +  22) //0x56
#define    ApiCommand_SetOSDChromaKey                   (GRAPHICS_CMD_OFFSET  +  32) //0x60
#define    ApiCommand_GetLocalAlphaConstant             (GRAPHICS_CMD_OFFSET  +  33) //0x61
#define    ApiCommand_SetLocalAlphaConstant             (GRAPHICS_CMD_OFFSET  +  34) //0x62


#define    Encoder_NoOperation                          (ENCODER_CMD_OFFSET +  0)  //0x80
#define    Encoder_StartCapture                         (ENCODER_CMD_OFFSET +  1)  //0x81
#define    Encoder_StopCapture                          (ENCODER_CMD_OFFSET +  2)  //0x82
    
#define    Encoder_SetAudioPID                          (0x89)
#define    Encoder_SetVideoPID                          (0x8b)
#define    Encoder_SetAuxPID                            (0x8d)

#define    Encoder_SetVideoFrameRate                    (ENCODER_CMD_OFFSET + 15)  //0x8f
#define    Encoder_SetVideoResolution                   (ENCODER_CMD_OFFSET + 17)  //0x91
#define    Encoder_SetVideoBitrate                      (ENCODER_CMD_OFFSET + 21)  //0x95
#define    Encoder_SetGOPStructure                      (ENCODER_CMD_OFFSET + 23)  //0x97
#define    Encoder_SetAspectRatio                       (ENCODER_CMD_OFFSET + 25)  //0x99
#define    Encoder_SetClosedGOP                         (ENCODER_CMD_OFFSET + 69)  //0xc5

#define    Encoder_SetInverseTelecine                   (ENCODER_CMD_OFFSET + 49)  //0xb1

    // Dynamic Noise Reduction
#define    Encoder_SetDnrMode                           (ENCODER_CMD_OFFSET + 27)  //0x9b
#define    Encoder_SetStaticDnrParams                   (ENCODER_CMD_OFFSET + 29)  //0x9d
#define    Encoder_SetDnrMedianCoring                   (ENCODER_CMD_OFFSET + 31)  //0x9f
#define    Encoder_SetSpatialFilterType                 (ENCODER_CMD_OFFSET + 33)  //0xa1
#define    Encoder_SetSpatialFilterCoeff                (ENCODER_CMD_OFFSET + 35)  //0xa3
#define    Encoder_SetDnrNltfParams                     (ENCODER_CMD_OFFSET + 39)  //0xa7

    // Scene Change Detect
#define    Encoder_SetDnrSceneChangeDetect              (ENCODER_CMD_OFFSET + 37)  //0xa5

#define    Encoder_SetStreamOutputType                  (ENCODER_CMD_OFFSET + 57)  //0xb9
#define    Encoder_SetStreamOutputPort                  (ENCODER_CMD_OFFSET + 59)  //0xbb
#define    Encoder_SetMPEGAudioEncodingParameters       (ENCODER_CMD_OFFSET + 61)  //0xbd
#define    Encoder_StopFirmware                         (ENCODER_CMD_OFFSET + 67)  //0xC3
#define    ApiCommand_GetEncoderFWVersion               (ENCODER_CMD_OFFSET + 68)  //0xC4
#define    Encoder_GetDataXferStatus                    (ENCODER_CMD_OFFSET + 70)  //0xC6 
#define    IndexTblParams							    (ENCODER_CMD_OFFSET + 71)  //0xc7
    //Encoder DMA transfer
#define    Encoder_SetDmaBlockSize                      (ENCODER_CMD_OFFSET + 73)  //0xc9
#define    Encoder_GetDmaTransferInfo                   (ENCODER_CMD_OFFSET + 74)  //0xca
#define    Encoder_GetDmaTransferStatus                 (ENCODER_CMD_OFFSET + 75)  //0xcb
#define    Encoder_SetDmaToHostLinkAddress              (ENCODER_CMD_OFFSET + 76)  //0xcc
#define    Encoder_SetVBILineInfo                       (ENCODER_CMD_OFFSET + 55)  //0xb7
#define    Encoder_SetVBIInfo                           (ENCODER_CMD_OFFSET + 72)  //0xc8
#define    Encoder_InputInit                            (ENCODER_CMD_OFFSET + 77)  //0xcd
#define    Encoder_SetSkipInputFrame                    (ENCODER_CMD_OFFSET + 80)  //0xd0
#define    Encoder_SceneChangeDetection                 (ENCODER_CMD_OFFSET + 81)  //0xd1
#define    Encoder_PauseResumeEncoder                   (ENCODER_CMD_OFFSET + 82)  //0xd2
#define    Encoder_InputRefresh                         (ENCODER_CMD_OFFSET + 83)  //0xd3
#define		Encoder_SetCopyRight					    (ENCODER_CMD_OFFSET + 84)  //0xd4
#define		Encoder_EventNotification				    (ENCODER_CMD_OFFSET + 85)  //0xd5
#define		Encoder_SetVSyncLineCount				    (ENCODER_CMD_OFFSET + 86)  //0xd6
#define		Encoder_ProvidePlaceHolder				    (ENCODER_CMD_OFFSET + 88)  //0xd8
#define		Encoder_SetVideoMute					    (ENCODER_CMD_OFFSET + 89)  //0xd9
#define		Encoder_SetAudioMute					    (ENCODER_CMD_OFFSET + 90)  //0xda
#define		Encoder_SetVerCropLine					    (ENCODER_CMD_OFFSET + 91)  //0xdb
#define		Encoder_SetMiscParameters				    (ENCODER_CMD_OFFSET + 92)  //0xdc

//port } API_COMMAND_CODE;

//________________________________________________________________________>>port
/*
#define MAX_PARAMS 8
#define MAX_QUEUED_MAILBOX_COMMANDS 10
#define API_CALL_SUCCESS 0
#define API_CALL_FAILURE 0xFFFFFFFF
#define MAILBOX_ADDRESS_INSIDE_FW 0xED00
#define MAILBOX_SIZE_IN_DWORDS 12
#define MAILBOX_SIZE_IN_BYTES 48
#define MAILBOX_FLAG_MAILBOX_FULL 1
#define MAILBOX_FLAG_PARAMETERS_SET 2
#define MAILBOX_FLAG_MAILBOX_READY 3
#define MAILBOX_FLAG_MAILBOX_DONE 7

*/
// #define  PVOID (void*)

#define MAX_PARAMS 16	
typedef unsigned char BYTE;
typedef unsigned short WORD; //port
//typedef unsigned  WORD; //
typedef unsigned long DWORD;

extern DWORD MAILBOX;

 typedef struct {
    DWORD mailBoxFlag; 
    DWORD commandCode;  
    DWORD returnCode;   
    DWORD timeToLive;   
    DWORD parameterBuffer[MAX_PARAMS];
//                     	PVOID pHwDevExt;
} FW_API_MAILBOX;

int ivac_mem_write(unsigned long ,unsigned long );
unsigned long ivac_mem_read(unsigned long );
void wd_res(void);
extern "C" void delay_mcs (unsigned long);
//________________________________________________________________________<<port




