#ifndef EXPERT_H
#define EXPERT_H
#include "DSP281x_Device.h"
//#include "kbd.h"
//#include "disp.h"

#ifdef __cplusplus
extern "C" {
#endif
//unsigned int Data1 = 0;
//char cLogo[]            = "** BER tester **";
extern Uint16 t1;	//for test
extern void InitBer(void);
extern void InitRemote(void);
struct Expert_REGS   {
						unsigned int   DINS;
						unsigned int   DDRAM;
						unsigned int   NOTUSED1;
						unsigned int   NOTUSED2;
                        unsigned int   KBDData;  
                        unsigned int   NOTUSED3;  
                        unsigned int   LED;
                        unsigned int   NOTUSED4;
                        unsigned int   XILR0;
                        unsigned int   XILR1;
                        unsigned int   XILR2;
    				 };
extern volatile struct Expert_REGS ExpertRegs;   

struct Expert_STORAGE   {
						char		   EMPTY;
						char		   CMD;
						char		   Clk0; //four butes for signed long Clk 
						char		   Clk1;
						char		   Clk2;
						char		   Clk3;
						char		   Clk4;
						char		   Clk5;
						char		   Clk6;
						char		   Clk7;
						char		   InsBer;
						char		   PolRt;
						char		   InType;	
						char		   PatType;	
						char		   Timing;	
						char		   Synce;
						char		   Loop;
						char		   PolRd;	
						char		   PolTt;
						char		   PolSd;
						char		   Rem0; //four butes for signed long Clk 
						char		   Rem1;
						char		   Rem2;
						char		   Rem3;
						char		   Rem4;
						char		   Rem5;
						char		   Rem6;
						char		   Rem7;	
						char		   RemBits;	
						char		   RemParity;																	
		  				};
extern volatile struct Expert_STORAGE ExpertStorage; 
extern void memcpy8(char* , char* , unsigned int);

 
#ifdef __cplusplus
}
#endif /* extern "C" */     
     
#endif // EXPERT_H


