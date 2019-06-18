#include "hello7.h"
#include "api16.h"

long SendApiCmd(FW_API_MAILBOX* Box)
{
  int i;
  long l;

  if(ivac_mem_read(MAILBOX)&1) {}//printff("Full");
  ivac_mem_write(MAILBOX,0x01);
  ivac_mem_write(MAILBOX+1,Box->commandCode);
  ivac_mem_write(MAILBOX+2,Box->returnCode);
  ivac_mem_write(MAILBOX+3,Box->timeToLive);
  for(i=0;i<16;i++) ivac_mem_write(MAILBOX+i+4,Box->parameterBuffer[i]);
  for(i=0;i<3;i++)  ivac_mem_write(i+0x55,0);// 55-57
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
  for(i=0;i<4;i++)  ivac_mem_write(i+0x50,0);// 50-53
  delay_mcs(135);
//	for(i=0;i<20;i++) wd_res();
  ivac_mem_write(0x044,0x03);
	for(i=0;i<20;i++) wd_res();
  while((ivac_mem_read(MAILBOX) & 0x4) != 0x4){
    i++; wd_res();	 
    if(i>500){ // printff("Err command rd");
     return -1; }
  };
  ivac_mem_read(MAILBOX+1);
  l=ivac_mem_read(MAILBOX+2);
  ivac_mem_read(MAILBOX+3);
  for(i=0;i<16;i++) Box->parameterBuffer[i]=ivac_mem_read(MAILBOX+i+4);// 44-54
  delay_mcs(135);
 // for(i=0;i<20;i++) wd_res();
  for(i=0;i<16;i++) ivac_mem_read(i+0x54);// 54-64
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
	ivac_mem_write(MAILBOX,0);
	ivac_mem_write(MAILBOX,0);
//  Box->returnCode=l;
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
  return l;
}

long SendApiCmd3(FW_API_MAILBOX* Box)
{
  int i;
  long l;

  if(ivac_mem_read(MAILBOX)&1) {} //port printff("Full");
  ivac_mem_write(MAILBOX,0x01);
  ivac_mem_write(MAILBOX+1,Box->commandCode);
  ivac_mem_write(MAILBOX+2,Box->returnCode);
  ivac_mem_write(MAILBOX+3,Box->timeToLive);
  for(i=0;i<16;i++) ivac_mem_write(MAILBOX+i+4,Box->parameterBuffer[i]);
  for(i=0;i<3;i++)  ivac_mem_write(i+0x55,0);// 55-57
  delay_mcs(135);
 // for(i=0;i<20;i++) wd_res();
  for(i=0;i<4;i++)  ivac_mem_write(i+0x50,0);// 50-53

 // for(i=0;i<370;i++) wd_res();	    // wait 2.5 ms (7.125us * N)
  delay_mcs(2700);
  ivac_mem_write(0x044,0x03);
  
  //	for(i=0;i<370;i++) wd_res();	    // wait 2.5 ms (7.125us * N)
  delay_mcs(2700);
  while((ivac_mem_read(MAILBOX) & 0x4) != 0x4){
    i++; wd_res();	 
    if(i>500){ //port  printff("Err command rd"); 
    return -1; }
  };
  ivac_mem_read(MAILBOX+1);
  l=ivac_mem_read(MAILBOX+2);
  ivac_mem_read(MAILBOX+3);
  for(i=0;i<16;i++) Box->parameterBuffer[i]=ivac_mem_read(MAILBOX+i+4);// 44-54
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
  for(i=0;i<16;i++) ivac_mem_read(i+0x54);// 54-64
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
	ivac_mem_write(MAILBOX,0);
	ivac_mem_write(MAILBOX,0);
//  Box->returnCode=l;
  delay_mcs(135);
//  for(i=0;i<20;i++) wd_res();
  return l;
}

long ApiCmd_NoOp()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_NoOperation;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetAudioPID()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetAudioPID;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=AudioPID;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVideoPID()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVideoPID;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=VideoPID;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetAuxPID()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetAuxPID;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=AuxPID;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetAspectRatio(unsigned long l)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetAspectRatio;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=l;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetGOPStructure(unsigned long l,unsigned long b)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetGOPStructure;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=l; // GOP IBBPBB
  Box.parameterBuffer[1]=b;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetClosedGOP(unsigned long l)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetClosedGOP;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=l; // on/off
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetStreamOutputPort()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetStreamOutputPort;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=1; //0 - Memory /1-Streaming/2-Serial
	Box.parameterBuffer[1]=2; // ?????
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetStreamOutputType(unsigned long val)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetStreamOutputType;
  Box.returnCode=0x00;
  Box.timeToLive=0x0;
  Box.parameterBuffer[0]=val; //0 - Program /1-Transport
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVideoBitrate(unsigned long p0,unsigned long rate,unsigned long p2)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVideoBitrate;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=p0;        //0 - VBR /1-CBR
  Box.parameterBuffer[1]=rate;  // in bps
  Box.parameterBuffer[2]= p2;//20480;  //Mux rate of 400 bps.
  Box.parameterBuffer[3]=0;//p2;// 20480;  //Mux rate of 400 bps.
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVideoFrameRate()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVideoFrameRate;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=1; //PAL
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVSyncLineCount()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVSyncLineCount;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=288;//0xef;//261;
  Box.parameterBuffer[1]=288;//0xef;//262;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVideoResolution()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVideoResolution;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=576; // 720/576
  Box.parameterBuffer[1]=720; // 720/576
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetInverseTelecine(unsigned long l)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetInverseTelecine;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=l;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetVBIInfo(unsigned long l)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetVBIInfo;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=l;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_Encoder_InputInit()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_InputInit;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  return SendApiCmd(&Box);
}

DWORD ApiCmd_StartCapture(unsigned long v0,unsigned long v1)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++)
  {
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_StartCapture;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=v0; //Mpeg
  Box.parameterBuffer[1]=v1; //Mpeg
  return SendApiCmd3(&Box);
}

DWORD ApiCmd_StopCapture(unsigned long v0,unsigned long v1,unsigned long v2)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_StopCapture;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=v0; //0-stop at end of GOP 1-stop immediately
  Box.parameterBuffer[1]=v1; //Mpeg
  Box.parameterBuffer[2]=v2; //Mpeg

  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetMPEGAudioEncodingParameters(unsigned long v0)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetMPEGAudioEncodingParameters;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=v0;//0x00c9; //b9       
  return SendApiCmd(&Box);
}

DWORD ApiCmd_EventNotification()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_EventNotification;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=0x0;        
  Box.parameterBuffer[1]=0x0; 
  Box.parameterBuffer[2]=0x10000000; 
  Box.parameterBuffer[3]=0xffffffff; 
  return SendApiCmd(&Box);
}

DWORD ApiCommand_IndexTblParams()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=IndexTblParams;
  Box.returnCode=0x00;
  Box.timeToLive=0x0;
  Box.parameterBuffer[0]=7;        
  Box.parameterBuffer[1]=400;        
//	printff("out0=%X  out1=%X",Box.parameterBuffer[0],Box.parameterBuffer[1]);
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetMiscParameters(int val,int param)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetMiscParameters;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=val;        
  Box.parameterBuffer[1]=param; 
  return SendApiCmd(&Box);
}
/*
DWORD ApiCmd_SetMiscParameters2(int val,int param,int param2)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetMiscParameters;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=val;        
  Box.parameterBuffer[1]=param; 
  Box.parameterBuffer[2]=param2; 
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetSCR(unsigned long val)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetMiscParameters;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=1;        
  Box.parameterBuffer[1]=val; 
  Box.parameterBuffer[2]=0; 
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetAudioMute()
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetAudioMute;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=1;        
  return SendApiCmd(&Box);
}

DWORD ApiCmd_SetSkipInputFrame(unsigned long val)
{
  FW_API_MAILBOX Box;
  for(int i=0;i<16;i++){
    Box.parameterBuffer[i]=0;
  }
  Box.mailBoxFlag=0x00;
  Box.commandCode=Encoder_SetSkipInputFrame;
  Box.returnCode=0x00;
  Box.timeToLive=0x60000;
  Box.parameterBuffer[0]=val;        
  return SendApiCmd(&Box);
}


long SendApiCmd2(FW_API_MAILBOX* Box)
{
  int i;
  long l;

  if(ivac_mem_read(MAILBOX)&1) printff("Full");
  ivac_mem_write(MAILBOX,0x01);
  ivac_mem_write(MAILBOX+1,Box->commandCode);
  ivac_mem_write(MAILBOX+2,Box->returnCode);
  ivac_mem_write(MAILBOX+3,Box->timeToLive);
  for(i=0;i<15;i++)  ivac_mem_write(MAILBOX+i+4,Box->parameterBuffer[i]);
  ivac_mem_write(0x044,0x03);
  while((ivac_mem_read(MAILBOX) & 0x4) != 0x4){
    i++; wd_res();	 
    if(i>500){  printff("Err command rd"); return -1; }
  };
  ivac_mem_read(MAILBOX+1);
  l=ivac_mem_read(MAILBOX+2);
  ivac_mem_read(MAILBOX+3);
  for(i=0;i<15;i++)   Box->parameterBuffer[i]=ivac_mem_read(MAILBOX+i+4);
	printff("out0=%X  out1=%X",Box->parameterBuffer[0],Box->parameterBuffer[1]);
	ivac_mem_write(MAILBOX,0);
	ivac_mem_write(MAILBOX,0);
  Box->returnCode=l;
  return l;
}


*/