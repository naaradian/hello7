#ifndef _FWID_H
#define _FWID_H

/*
The f/w identification structure, located at offset 4 of the binary ROM
image, is defined as follows -
*/

    #define ES_SUPPORT_IN_FW 0x01
    #define PS_SUPPORT_IN_FW 0x02
    #define TS_SUPPORT_IN_FW 0x04
    #define MUX_SUPPORT_IN_FW 0x06
    #define VIDEO_SUPPORT_IN_FW 0x07
    #define MPEG1_AUDIO_SUPPORT_IN_FW 0x08
    #define DOLBY_AUDIO_SUPPORT_IN_FW 0x10
    #define AUDIO_SUPPORT_IN_FW 0x18
    #define API_SUPPORT_IN_FW 0x20
	#define FW_ID_SIGNATURE_1 0xAA55BB66
	#define FW_ID_SIGNATURE_2 0xCC44DD33

#pragma pack(1)
    typedef struct _fwIdentificationStructure
    {
        int signature1;     /* 0xAA55BB66 - to indicate presence of valid
                        identification structure */
        int firmwareFlags;
                        /*
                        bit 0 -> elementary stream support, 1=supported
                        bit 1 -> program stream support, 1=supported
                        bit 2 -> transport stream support, 1=supported
                        bit 3 -> MPEG-1 audio, 1=supported
                        bit 4 -> Dolby AC-3 audio, 1=supported
                        */
        int releaseVersion;    /* Release version */
        int addressOfPCILock;
                        /* Offset within SDS memory where the value of
                         0x1234 has to be written to start the encoding
                         process */
        int addressOfOtherIntSignature;
                        /* Offset within SDS memory where video Java
                           writes a 1 (2) every time an audio (VBI) 
						   interrupt is generated. */
        int addressOfSoftRegisters;
                        /* Offset within SDS memory where the soft
                         registers are stored */

        int videoFeedbackStartAddress;
                        /* Offset within SDS memory, where AVO will write
                           back the encoded data. */
        int videoFeedbackSize;
                        /* Number of bytes of video data that has to be
                           transferred from SDS memory to PCI memory on
                           each video interrupt */
        int videoBufferCount;   /* Number of video ping-pong buffers */

                        /* Next 3 values are meaningful for elementary
                        stream f/w only. For any other f/w, the next 3
                        fields can be set to 0 */

        int audioDataStartAddress;
                        /* Offset within SDS memory, where audio JAVA
                         will store the encoded data */
        int audioDataSize;
                        /* Number of bytes of audio data that has to be
                         transferred from SDS memory to PCI memory on
                         each audio interrupt */
        int audioBufferCount;
                        /* Number of audio ping-pong buffers */

        int vbiFeedbackStartAddress;
                        /* Offset within SDS memory, where JAVA
                         will store the VBI data */
        int vbiFeedbackSize;
                        /* Number of bytes of VBI data that has to be
                         transferred from SDS memory to PCI memory on
                         each VBI interrupt */
        int vbiBufferCount;
                        /* Number of VBI ping-pong buffers */

        int signature2;
                        /* 0xCC44DD33 - to indicate presence of valid
                        identification structure */
                        /* Both signature 1 and signature 2 have to be
                            present */
        int ReleaseDate;
                        /* Release date */
}
	FW_IDENTIFICATION_STRUCTURE;

#pragma pack()

#endif //_FWID_H