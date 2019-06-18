//********************* FILE DESCRIPTION *******************************
//
//  THIS SDK INCLUDING CODE, BINARIES, AND INFORMATION IS PROVIDED "AS IS" WITHOUT 
//  WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED 
//  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
// FILE NAME:  DOAPI.H
//
// COPYRIGHT:		    Company Confidential
//		          Copyright (c) iCompression, Inc. 1997,1998,1999
//			             All Rights Reserved
//
// VERSION: Pre-release
//
// FUNCTION: FW Maibox interface prototypes and defines
//
// DEPENDENCIES: NONE
// RESTRICTIONS: NONE
//
// EXTERNAL REFERENCES:  none.
//
// MODIFICATION HISTORY:
// DATE			DEVELOPER		CHANGE DESCRIPTION
// 01/30/98		Deb Chatterjee	Original creation
// 02/10/98		A. Mobini		Translation to 'C' and separation of OS dependencies
//**********************************************************************

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

typedef char CHAR;
typedef unsigned char UCHAR;
typedef unsigned char BYTE;
typedef BYTE * PBYTE;
typedef short SHORT;
typedef long LONG;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#define VOID void
#define HANDLE VOID *

/*
#define open _open
#define read _read
#define filelength _filelength
#define close _close

#pragma pack(1)
*/

enum eMailboxAPIReturnCodes {
	API_RC_SUCCESS					= 0,	/* Successful completion */
	API_RC_ERROR_UNKNOWN		= -1	/* Unknow error occurred. Call did not complete */
};

enum eReturnCodes {
	RC_SUCCESS						 	= 0x00000000,	/* Successful completion */
	RC_ERROR_INVALIDPARAMETER		 	= 0x88000000,	/* One or more of the formal parameters are out of range */
	RC_ERROR_UNKOWN					 	= 0x88000001,	/* Unknown error */
	RC_ERROR_ROM_DOWNLOAD_FILEOPEN		= 0x88000010,	/* Error openning the rom file */
	RC_ERROR_ROM_DOWNLOAD_DATATXFER		= 0x88000020,	/* Error transferring the rom image to the device */
	RC_ERROR_DEVICE_UNINITIALIZED	 	= 0x88000100,	/* Error initializing the device */
	RC_ERROR_DEVICE_MEMWRITE		 	= 0x88000200,	/* Error writing to iVAC memory */
	RC_ERROR_DEVICE_MEMREAD			 	= 0x88000400,	/* Error reading from iVAC memory */
};

typedef enum
{
	WDM_DRIVER						= 0x00,
	VXD_DRIVER						= 0x01
} DRIVER_TYPE;

typedef enum
{
	//RESERVED_1						= 0x00,
	IVAC_PCI						= 0x01,
	//RESERVED_2						= 0x02,
	IVAC_USB						= 0x03
} BOARD_TYPE;

typedef enum
{
	//RESERVED						= 0x00,
	PHILIPS_7114					= 0x01,
	MICRONAS						= 0x02
} DIGITIZER_TYPE;

typedef enum
{
	BOARD_6MEG						= 0x00,
	BOARD_12MEG						= 0x01
} BOARD_MEMORY;

typedef enum
{
	SUPPORTED_AUDIOSAMPLINGRATE_32		= 1,
	SUPPORTED_AUDIOSAMPLINGRATE_44		= 2,
	SUPPORTED_AUDIOSAMPLINGRATE_48		= 4
} SUPPORTED_AUDIO_FREQUENCIES;

typedef enum
{
	VIDEO_INPUT_SYNC_EMBEDDED			= 0, //656
	VIDEO_INPUT_SYNC_SEPARATE			= 1, //601
} DIGITAL_VIDEO_INPUT_FORMAT;

typedef enum 
{
	TSA5522		= 0x00,
	TEMIC		= 0x01,
	FI1236		= 0x02,
	TSCH6_C2	= 0x03,
	TSCH6_C0	= 0x04,
	NO_TUNER	= 0xFF
} TUNER_TYPE;

typedef struct
{
	BOARD_TYPE					eBoardType;				// iVAC PCI, iVAC USB
	DIGITIZER_TYPE				eDigitizer;				// 7114, Micronas
	BOARD_MEMORY				eBoardMemory;			// 6 Meg, 12 Meg
	BYTE						bSupportedAudioFreq;	// Bitmask indicating which of 32, 44.1 and, 
														// 48 KHz frequencies are supported. the value 
														// is a OR between any of the values in 
														// SUPPORTED_AUDIO_FREQUENCIES
	DIGITAL_VIDEO_INPUT_FORMAT	eDigitalVideoFormat;	// Sync embedded or separate
	BYTE						bAudioDigitizerInput;	// Which input to the audio digitizer is used
	TUNER_TYPE					eTunerType;				// TV Tuner
} BOARD_DESCRIPTION;

#define MAX_VERSION_SIZE 10 // "xx.yy.zzz"

typedef struct
{
	union
	{
		DWORD			dwFWVersion;
		struct
		{
			DWORD			dwSubBuildNum	: 16;
			DWORD			dwBuildNum		: 8;
			DWORD			dwMajorRel		: 8;
		} FWVerNumbers;
	};
} FW_VERSION;

typedef struct
{
	char			DriverVersion[MAX_VERSION_SIZE]; //xx.yy.zzz
	char			FWVersion[MAX_VERSION_SIZE]; //xx.yy.zzz
} VERSION_INFO;

typedef enum
{
	CABLE		= 0x00,
	AIR			= 0x01
} TV_SIGNAL_TYPE;

typedef struct
{
	TUNER_TYPE		TunerType;
	WORD			wChannel;
	TV_SIGNAL_TYPE	eType;
} TV_CHANNEL;

typedef enum
{
	GPIO_INPUT		= 0x00,
	GPIO_OUTPUT		= 0x01
} GPIO_DIRECTION;

typedef struct
{
	BYTE			bBitNumber; // between 8 and 12
	GPIO_DIRECTION	Direction;
} GPIO_BIT_DIRECTION;

typedef struct
{
	GPIO_DIRECTION	Direction;
} GPIO_BYTE_DIRECTION;

typedef struct
{
	BYTE			bBitNumber; // between 8 and 12
	BOOL			bValue;		// 0 or 1
} GPIO_BIT_VALUE;

typedef struct
{
	BYTE			bValue;		// value of the GPIOs 0:7
} GPIO_BYTE_VALUE;

typedef struct
{
	BYTE			bBitDirection;	// Bitmask containing the direction of GPIO[8:12]
	BYTE			bByteDirection;	// 0 or 1 representing the direction of GPIO[0:7]
	BYTE			bBitValue;		// Bitmask containing the value of GPIO[8:12]
	BYTE			bByteValue;		// Value of GPIO[0:7]
} GPIO_STATUS;

// This could be viewed as a bit mask where the first bit specifies
// whether the odd field is required, and the second specifies whether 
// the even field is required
typedef enum 
{
	ODD_ONLY		= 1,
	EVEN_ONLY		= 2,
	BOTH_FIELDS		= 3,
	NEITHER_FIELD	= 0
} VBI_REQUEST;

typedef enum
{
	ODD		= 1,
	EVEN	= 2
} FIELD_POLARITY;

// The structure VBI_LINE_INFO needs to be passed from the application 
// to notify the driver which VBI lines are being captured.
// wLineStartOffset and wLineStartOffset specify the offset 
// where the sliced VBI data of line wLineNumber of the 
// bPolarity field starts and ends
typedef struct
{
	WORD			wLineNumber;
	FIELD_POLARITY	Polarity;
	WORD			wLineStartOffset;
	WORD			wLineEndOffset;
} VBI_LINE_INFO;

// wAlignedLineStartOffset and wAlignedLineStartOffset are DWORD aligned
typedef struct
{
	VBI_REQUEST		Requested;
	WORD			wLineStartOffset;
	WORD			wLineEndOffset;
	WORD			wAlignedLineStartOffset;
	WORD			wAlignedLineEndOffset;
} EXTENDED_VBI_INFO;

// Bit0: 0->Read, 1->Write
// Bit2-1: Address width
//			00-> 8 bits
//			01-> 16 bits
//			10-> 24 bits
//			11-> 32 bits
// Bit4-3: Data width
//			00-> 8 bits
//			01-> 16 bits
//			10-> 24 bits
//			11-> 32 bits
// Bit 5:   Address non available
typedef enum
{
	ADDRESS0_DATA8		= 0x20,
	ADDRESS0_DATA16		= 0x28,
	ADDRESS0_DATA24		= 0x30,
	ADDRESS0_DATA32		= 0x38,

	ADDRESS8_DATA8		= 0x00,
	ADDRESS8_DATA16		= 0x08,
	ADDRESS8_DATA24		= 0x10,
	ADDRESS8_DATA32		= 0x18,

	ADDRESS16_DATA8		= 0x02,
	ADDRESS16_DATA16	= 0x0A,
	ADDRESS16_DATA24	= 0x12,
	ADDRESS16_DATA32	= 0x1A,

	ADDRESS24_DATA8		= 0x04,
	ADDRESS24_DATA16	= 0x0C,
	ADDRESS24_DATA24	= 0x14,
	ADDRESS24_DATA32	= 0x1C,

	ADDRESS32_DATA8		= 0x06,
	ADDRESS32_DATA16	= 0x0E,
	ADDRESS32_DATA24	= 0x16,
	ADDRESS32_DATA32	= 0x1E,
} I2C_MODE;

typedef struct
{
	DWORD			dwChipID;		// Chip ID of the device we want to access
	BYTE			bModeInfo;		// Address and data width (one of I2C_MODE enums)
	DWORD			dwAddress;		// Address of the register
} I2C_REGISTER;

typedef enum
{
	MEMORY_SIZE_MASK				= 0x0001,
	AUDIO_DIGITIZER_MASK			= 0x000E,
	VIDEO_INPUT_FORMAT_MASK			= 0x0010,
	VIDEO_DIGITIZER_MASK			= 0x00E0,
	AUDIO_INPUT_MASK				= 0x0300,
	TUNER_TYPE_MASK					= 0x1C00,
	AUDIO_PROGRAM_MASK				= 0x2000
} SUBVENDOR_ID_MASK;

typedef enum
{
	MEMORY_6_VAL					= 0x0000,
	MEMORY_12_VAL					= 0x0001,
	AUDIO_DIG_MIC_32_VAL			= 0x0000,
	AUDIO_DIG_MIC_48_VAL			= 0x0002,
	AUDIO_DIG_CRYSTAL_VAL			= 0x0004,
	VIDEO_INPUT_FORMAT_656_VAL		= 0x0000,
	VIDEO_INPUT_FORMAT_601_VAL		= 0x0010,
	VIDEO_DIG_7111_VAL				= 0x0000,
	VIDEO_DIG_7114_VAL				= 0x0020,
	VIDEO_DIG_MICRONAS_VAL			= 0x00E0,
	AUDIO_SCART1_VAL				= 0x0000,
	AUDIO_SCART2_VAL				= 0x0100,
	AUDIO_SCART3_VAL				= 0x0200,
	TUNER_NONE_VAL					= 0x0000,
	TUNER_TEMIC_VAL					= 0x0400,
	TUNER_FI1236_VAL				= 0x0800,
	TUNER_TSCH6_C2_VAL				= 0x0C00,
	TUNER_TSCH6_C0_VAL				= 0x1000,
	AUDIO_THROUGH_I2C_VAL			= 0x0000,
	AUDIO_THROUGH_GPIO_VAL			= 0x2000,
} SUBDEVICE_ID_VALUES;

typedef enum
{
	MPEG_COMPLIANT					= 0x01,
	NON_MPEG_COMPLIANT			= 0x00
} MPEG_COMPLIANCE;

typedef enum 
{
	//RESERVED_1									= 0x00,
	PROP_STREAMOUTPUT_OLD_PROGRAM	= 0x01,
	PROP_STREAMOUTPUT_PROGRAM			= 0x03,
	PROP_STREAMOUTPUT_TRANSPORT		= 0x02,
	//RESERVED_2									= 0x03,	//Not yet implemented
	PROP_STREAMOUTPUT_MPEG1				= 0x04
} OUTPUT_TYPE;

typedef enum 
{
	PROP_VIDEOINPUT_YC					= 0x00,
	PROP_VIDEOINPUT_COMPOSITE		= 0x01,
	PROP_VIDEOINPUT_TV					= 0x02
} VIDEO_INPUT_TYPE;

typedef enum 
{
	PROP_AUDIOINPUTMODE_LEFTHIGH		= 0x00,
	PROP_AUDIOINPUTMODE_LEFTLOW			= 0x01
} AUDIO_INPUT_MODE;

typedef enum
{
	PROP_VIDEORESOLUTION_720x480		= 0,
	PROP_VIDEORESOLUTION_720x576		= 0, // For PAL
	PROP_VIDEORESOLUTION_480x480		= 1,
	PROP_VIDEORESOLUTION_480x576		= 1, // For PAL
	PROP_VIDEORESOLUTION_352x480		= 2,
	PROP_VIDEORESOLUTION_352x576		= 2, // For PAL
	PROP_VIDEORESOLUTION_352x240		= 2, // For NTSC MPEG1
	PROP_VIDEORESOLUTION_352x288		= 2,  // For PAL MPEG1
	PROP_VIDEORESOLUTION_320x240		= 3  // For NTSC MPEG1
} VIDEO_RESOLUTION;

typedef enum
{
	PROP_TVFORMAT_NTSC	= 0,
	PROP_TVFORMAT_PAL		= 1
} TV_ENCODE_FORMAT;

typedef enum
{
	PROP_AUDIOSAMPLINGRATE_32		= 0x02,
	PROP_AUDIOSAMPLINGRATE_44		= 0x00,
	PROP_AUDIOSAMPLINGRATE_48		= 0x01,
	PROP_AUDIOSAMPLINGRATE_UNSUPPORTED = 0x10
} SAMPLING_RATE;

typedef enum
{	
	PROP_AUDIOOUTPUTMODE_MONO			= 0x03,
	PROP_AUDIOOUTPUTMODE_STEREO		= 0x00,
	PROP_AUDIOOUTPUTMODE_DUAL			= 0x02,
	PROP_AUDIOOUTPUTMODE_JOINT		= 0x01
} AUDIO_OUTPUT_MODE;

typedef enum 
{
	CAPTURE_SUCCEEDED						= 0x00000000,	/* Successful completion */
	CAPTURE_NOTSET							= 0x00000001,   /* The information is not available */
	CAPTURE_ERROR_UNKNOWN				= 0x88000000,	/* Unknown error */
	CAPTURE_ERROR_NOVSYNC				= 0x88000001,	/* The VSync is not locked by the digitizer */
	CAPTURE_ERROR_FW_HUNG				= 0x80000002	/* The firmware is not responding */
} CAPTURE_ERROR;

typedef struct
{
	DWORD					dwTime;
	CAPTURE_ERROR	dwCaptureError;
} CAPTURE_STATUS;

typedef enum
{
	RC_VIDEOENCODINGMODE_CBR	= 0x00,
	RC_VIDEOENCODINGMODE_VBR	= 0x01
}  BITRATE_MODE;

typedef struct
{
	BITRATE_MODE	bEncodingMode;	// Variable or Constant bit rate
	WORD			wBitrate;		// Actual bitrate in 1/400 mbits/sec
	BYTE			bVariance;		// 1-100 as a percentage of variance
} VIDEO_BITRATE;

typedef enum
{
	DATARATE_LAYERII_192		= 0x0A,
	DATARATE_LAYERII_224		= 0x0B,
	DATARATE_LAYERII_384		= 0x0E
} AUDIO_DATARATE_LAYER_II;


typedef struct {
    DWORD mailBoxFlag; /* Bit 0 = 0 -> empty, 1 -> full */
                     /* Bit 1 = 1 -> input parameters have been set,
                              = 0 -> input parameters are not valid */
                     /* Bit 2 = 1 - > if the call has been processed,
                              = 0 - >otherwise */
    DWORD commandCode;  /* Each API function will have a command code */
    DWORD returnCode;   /* Return code = 0 for success, -1 for failure */
    DWORD timeToLive;   /* Explained later */
    DWORD parameterBuffer[MAX_PARAMS];
                      /* Same buffer will be shared between input and
                         output */
   //port 	PVOID pHwDevExt;
} FW_API_MAILBOX;

typedef enum eApiCommandCode
{
	ApiCommand_NoOperation = 0,                //(0x00)
	ApiCommand_StartCapture = 1,               //(0x01)
	ApiCommand_StopCapture = 2,                //(0x02)
	ApiCommand_SetVideoResolution = 15,        //(0x0F)
	ApiCommand_GetVideoResolution = 16,        //(0x10)
	ApiCommand_SetVideoBitRate = 17,           //(0x11)
	ApiCommand_GetVideoBitRate = 18,           //(0x12)
	ApiCommand_SetTVEncodingFormat = 23,       //(0x17)
	ApiCommand_GetTVEncodingFormat = 24,       //(0x18)
	ApiCommand_SetStreamOutputType = 27,       //(0x1B)
	ApiCommand_GetStreamOutputType = 28,       //(0x1C)
	ApiCommand_SetAudioSamplingRate = 31,      //(0x1F)
	ApiCommand_GetAudioSamplingRate = 32,      //(0x20)
	ApiCommand_SetAudioDataRate = 33,          //(0x21)
	ApiCommand_GetAudioDataRate = 34,          //(0x22)
	ApiCommand_SetAudioOutputMode = 35,        //(0x23)
	ApiCommand_GetAudioOutputMode = 36,        //(0x24)
	ApiCommand_SetVideoInputType = 45,         //(0x2D)
	ApiCommand_GetVideoInputType = 46,         //(0x2E)
	ApiCommand_SetI2CDevices = 55,             //(0x37)
	ApiCommand_GetI2CDevices = 56,             //(0x38)
	ApiCommand_SetVideoMemoryMode = 57,        //(0x39)
	ApiCommand_GetVideoMemoryMode = 58,        //(0x3A)
	ApiCommand_SetDigitalVideoInputFormat = 59,//(0x3B)
	ApiCommand_GetDigitalVideoInputFormat = 60,//(0x3C)
	ApiCommand_WriteI2C = 65,                  //(0x41)
	ApiCommand_ReadI2C = 66,                   //(0x42)
	ApiCommand_InitializeI2C = 67,             //(0x43)
	ApiCommand_SetVBILineInfo = 69,            //(0x45)
	ApiCommand_SetGPIOBitDirection = 73,       //(0x49)
	ApiCommand_GetGPIOBitDirection = 74,       //(0x4A)
	ApiCommand_SetGPIOByteDirection = 75,      //(0x4B)
	ApiCommand_GetGPIOByteDirection = 76,      //(0x4C)
	ApiCommand_SetGPIOBitValue = 77,           //(0x4D)
	ApiCommand_GetGPIOBitValue = 78,           //(0x4E)
	ApiCommand_SetGPIOByteValue = 79,          //(0x4F)
	ApiCommand_GetGPIOByteValue = 80,          //(0x50)
	ApiCommand_GetAvailableByteCount = 84,     //(0x54)
	ApiCommand_LimitPesPacketSize = 85,        //(0x55)
	ApiCommand_WriteI2C_MC = 90,               //(0x5A)
	ApiCommand_ReadI2C_MC = 91,                //(0x5B)
	ApiCommand_SetVBIDataMuxMode = 92,				 //(0x5C)
	ApiCommand_SetParallelPortOutputMode = 93, //(0x5D)
	ApiCommand_GetParallelPortOutputMode = 94, //(0x5E)
} API_COMMAND_CODE;

/*
	typedef enum eApiCommandCode
{
	ApiCommand_NoOperation = 0, 
	ApiCommand_StartCapture = 1, 
	ApiCommand_StopCapture = 2, 
	ApiCommand_SetVideoResolution = 15,
	ApiCommand_GetVideoResolution = 16,
	ApiCommand_SetVideoBitRate = 17,
	ApiCommand_GetVideoBitRate = 18,
	ApiCommand_SetTVEncodingFormat = 23,
	ApiCommand_GetTVEncodingFormat = 24,
	ApiCommand_SetStreamOutputType = 27,
	ApiCommand_GetStreamOutputType = 28,
	ApiCommand_SetAudioSamplingRate = 31,
	ApiCommand_GetAudioSamplingRate = 32,
	ApiCommand_SetAudioDataRate = 33,
	ApiCommand_GetAudioDataRate = 34,
	ApiCommand_SetAudioOutputMode = 35,
	ApiCommand_GetAudioOutputMode = 36,
	ApiCommand_SetVideoInputType = 45,
	ApiCommand_GetVideoInputType = 46,
	ApiCommand_SetI2CDevices = 55,
	ApiCommand_GetI2CDevices = 56,
	ApiCommand_SetVideoMemoryMode = 57,
	ApiCommand_GetVideoMemoryMode = 58,
	ApiCommand_SetDigitalVideoInputFormat = 59,
	ApiCommand_GetDigitalVideoInputFormat = 60,
	ApiCommand_WriteI2C = 65,
	ApiCommand_ReadI2C = 66,
	ApiCommand_InitializeI2C = 67,
	ApiCommand_SetVBILineInfo = 69,
	ApiCommand_SetGPIOBitDirection  = 73,
	ApiCommand_GetGPIOBitDirection  = 74,
	ApiCommand_SetGPIOByteDirection = 75,
	ApiCommand_GetGPIOByteDirection = 76,
	ApiCommand_SetGPIOBitValue   = 77,
	ApiCommand_GetGPIOBitValue   = 78,
	ApiCommand_SetGPIOByteValue  = 79,
	ApiCommand_GetGPIOByteValue  = 80,
	ApiCommand_GetFWVersion = 82,
	ApiCommand_SetAudioInputMode = 97
} API_COMMAND_CODE;

*/