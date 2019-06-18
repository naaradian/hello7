#ifndef DISP_H
#define DISP_H
#include <stdarg.h>
#include <stdio.h>
#include "Expert.h"
#ifdef __cplusplus
extern "C" {
#endif
//#include "DSP281x_Device.h"
extern "C" void ins_disp(char);
extern "C" int fill_disp(const char *);
extern "C" void InitDisp(void);
extern "C" void Hello(void);
extern "C" void gotoxy(Uint16, Uint16);
extern "C" void _setcursortype(Uint16);
extern "C" int  cprintf(char const near *form, ...);
extern "C" void printL(char, char, unsigned long);
extern "C" void MDelay(unsigned long);
//extern "C" void GetRem(unsigned char);
#ifdef __cplusplus
}
#endif /* extern "C" */     
//extern Uint16 t; 

     
#endif // DISP_H