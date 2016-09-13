#ifndef KBD_H
#define KBD_H
#include "DSP281x_Device.h"
//#include "Expert.h"
//#ifdef __cplusplus
//extern "C" {
//#endif
extern "C" void OperateKbd(void);
//extern "C" void TCPParser(unsigned char*);
extern "C" char* TCPAnswer();
extern "C" void GetFlash(unsigned char);
extern "C" char GetState(void);
//extern "C" void TCPSetRemBuf();
extern "C" Uint16 GetKey(void);
extern "C" void Message(char * ,  char*);
//extern "C" void Ring(unsigned long);
extern Uint32 KbdTimeOut;
extern unsigned long ProgModeTimeOut;
extern const unsigned long ProgModeTime;
extern Uint32 ScanCnt;
extern unsigned int State;
extern unsigned int bytecnt;

enum Keys
 {
    Enter = 0,
    Left,
    Right,
    Up,
    Down,
    Esc,
    Update,
    None
 };
  
//#ifdef __cplusplus
//}
//#endif /* extern "C" */     
     
#endif // KBD_H