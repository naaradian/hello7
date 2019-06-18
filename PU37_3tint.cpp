// программа  тестирования каналов PU37
// зделана пакетное тестирование канала UP0 остальные каналы пока блокир на передачу
// необх корр остальных каналов

//#ifndef __TINY__
//#define __TINY__
//#endif
//#include <stdarg.h>
//#include <dos.h>
//#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
//#define IncEmbRS232
//#define IncEmbRS485
//#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
////////////////////////////////////////////
//#include "command.h"
//#include "longtoa.cas"                   //@@@@@@@@@@@@@@@@
//#include "Ltoa1.c"
//#include "embisr.cpp"
//#include "basic'.h"

//#include "basic'.cpp"

//void Enable() { asm { sti } }
//void Disable() { asm { cli } }

//EmbRS232 embRS232;
//#include "screen3.cpp"

//________________________________________________________________________________________

#include "hello7.h"
#include "menu1.h"

//#include <command.h>
//#include <string.h>
//#include "EMBISR.H"
extern "C" void delay_mcs (uint_32);
extern char * pxilinx; //need make  pxilinx = (char*)(0x30000000);
extern "C" void outport(unsigned int,  unsigned char);	  //in autodetect so use xilinx
extern "C" void outportb(unsigned int , unsigned char );
extern "C" unsigned char inportb(unsigned int );
extern "C" void my_int_enable_irq0(void);
//#define  ScreenAddString   printf
extern unsigned int  IntFlag;

//________________________________________________________________________________________



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// BASE ADRESS 600

//void wr_cosv(unsigned char slot, unsigned int addr,unsigned char data)
//{ 
//  outportb(0x500|((unsigned char) (slot*16 & 0xf0))|0x01, (unsigned char) (addr>>8 ));   // base H adr
//  outportb(0x500|((unsigned char) (slot*16 & 0xf0))|0x00,(unsigned char) addr);           // base L adr
//  outportb(0x500|(slot*16 & 0xf0)|0x0f,data);                       // read from window
//} 













