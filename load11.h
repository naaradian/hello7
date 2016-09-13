#ifndef _load11_h_
#define _load11_h_ 
void StopCapture(void);
int start_ktvm(void);
unsigned char GetMode(void);
void SetMode(unsigned char);
void SetVideoIn(unsigned char);
void SetStopKadr(unsigned char);
unsigned char GetSound(void);
void SetSound(unsigned char);
unsigned char GetVideoIn(void);
void SetVideoIn(unsigned char);
unsigned char GetStopKadr(void);
unsigned char GetStat(void);

//extern  EmbCommand embCommand2;
//extern  EmbCommand embCommand3;

extern char a[128];
extern char c[128];
extern char  *dpd;

 /*
#define MIData (0x510)
#define MICmd  (0x511)
#define MISts  (0x512)
#define MIRes  (0x513)
#define MISet  (0x514)
#define MISlt  (0x515)
//const int MIPll  = 0x516;
#define MIInt  (0x517)
#define MIBuff (0x516)

#define MIRD  (0x00)
#define MIWR  (0x20)
#define MIRq  (0x40)
#define MICS  (0x80)

#define MIRST  (0x08)
#define MIRDY  (0x02)
#define MIROM  (0x01)
#define MILDC  (8)
#define MIRSTA (0x10)
   */
#ifdef IncEmbIndicator
extern  EmbIndicator embIndicator;
#endif
#ifdef IncEmbRS485
extern "C" EmbRS485 embRS485;
#endif

//#define MAX_PARAMS 16

//#include "sound.cpp"

//typedef struct {
//    unsigned long mailBoxFlag; /* Bit 0 = 0 -> empty, 1 -> full */
                       /* Bit 1 = 1 -> input parameters have been set,
                                = 0 -> input parameters are not valid */
                       /* Bit 2 = 1 - > if the call has been processed,
                                = 0 - >otherwise */
//    unsigned long commandCode;  /* Each API function will have a command code */
//    unsigned long returnCode;   /* Return code = 0 for success, -1 for failure */
//    unsigned long timeToLive;   /* Explained later */
//    unsigned long parameterBuffer[MAX_PARAMS];
                      /* Same buffer will be shared between input and
                         output */
//} FW_API_MAILBOX;

typedef unsigned char BYTE;
typedef unsigned short WORD; //port
//typedef unsigned  WORD; //
typedef unsigned long DWORD;

extern DWORD MAILBOX;

int ivac_mem_write(unsigned long ,unsigned long );
unsigned long ivac_mem_read(unsigned long);

DWORD ApiCmd_SetStreamOutputPort(void);
DWORD ApiCmd_SetMiscParameters(int ,int );
DWORD ApiCmd_EventNotification(void);
DWORD ApiCmd_SetVideoFrameRate(void);
DWORD ApiCmd_SetVideoResolution(void);
DWORD ApiCmd_SetAspectRatio(unsigned long);
DWORD ApiCmd_SetStreamOutputType(unsigned long);
DWORD ApiCmd_SetVideoBitrate(unsigned long ,unsigned long ,unsigned long );
DWORD ApiCmd_SetGOPStructure(unsigned long ,unsigned long );
DWORD ApiCmd_SetInverseTelecine(unsigned long);
DWORD ApiCmd_SetClosedGOP(unsigned long);
DWORD ApiCmd_SetMPEGAudioEncodingParameters(unsigned long);
DWORD ApiCmd_Encoder_InputInit(void);
DWORD ApiCommand_IndexTblParams(void);
DWORD ApiCmd_StartCapture(unsigned long ,unsigned long );
DWORD ApiCmd_StopCapture(unsigned long ,unsigned long ,unsigned long );



#endif
