// ���������  ������������ ������� PU37
// c������ �������� ������������ ������ UP0 ��������� ������ ���� ������ �� ��������
// ����� ���� ��������� �������
// c�������������� ��������
//#ifndef __TINY__
//#define __TINY__
//#endif
//#include <stdarg.h>
//#include <dos.h>
//#include "start.h"
////////////////////////////////////////////
////    ������ ��������� Emb-�������    ////
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// BASE ADRESS 600
//unsigned char	an[] =	{0x23, 0x00, 0xff, 0x10 };
// from file AK4_TAB.h

//unsigned char	ab1[] =	{ 0x45,0x60,0xBF,0x25,0x52,0x2A,0x64,0x3F,0x89,0x00};   // IM-Filter part 1 
//unsigned char	ab2[] =	{ 0x45,0x68,0x53,0x02,0x49,0x8A,0x07,0xF6,0x04,0x00};   // IM-Filter part 2 
//unsigned char	ab3[] =	{ 0x45,0x18,0x08,0xB0,0xC5,0x42,0x3E,0xFB,0x72,0x07 };  // FRR-Filter    
   
//unsigned char	ab4[] =	{ 0x45,0x28,0x43,0x8a,0xBc,0x27,0x88,0x00,0x00,0x00 }; // AR-Filter - ������ 20
    
//unsigned char	ab5[] =	{ 0x45,0x48,0x96,0x38,0x29,0x96,0xC9,0x2B,0x8B,0x00 }; /// LPR-Filter       
//unsigned char	ab6[] =	{0x45,0x20,0x08,0x90,0x3F,0xBC,0x75,0x28,0x72,0x07}; // FRX-Filter       

//unsigned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x00,0x00,0x00,0x00}; // AX-Filter -������ 20
//unsigned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x85,0x50,0xc0,0x1a}; // AX-Filter -������ 20


//unsigned char	ab8[] =	{ 0x45,0x50,0x96,0x38,0x29,0xF5,0xFA,0x2B,0x8B,0x00}; // LPX-Filter       
//unsigned char	ab9[] =	{ 0x45,0x00,0x30,0x9B,0x88,0x80,0x00,0xC8,0x32,0x80}; // TH-Filter part 1 
//unsigned char	ab10[] =	{ 0x45,0x08,0x80,0x00,0x80,0x00,0x67,0x35,0x5A,0x01 }; // TH-Filter part 2 
//unsigned char	ab11[] =	{ 0x45,0x10,0x22,0xAD,0xB2,0x2A,0x24,0xDC,0x88,0x00};  // TH-Filter part 3 

//unsigned char	ab12[] =	{ 0x45,0x80,0xF9,0x29,0x9B,0x2A,0x1A,0x22,0xC1,0x32}; // DC-Parameter     
//unsigned char	ab13[] =	{ 0x45,0x70,0x32,0x3B,0x1B,0xC0,0xC3,0xB2,0xAC,0x02}; // Ringing          
//unsigned char	ab14[] =	{ 0x45,0x90,0x3E,0xE5,0x2E,0xBA,0x81,0x2A,0xBA,0x8A }; // LP-Filters       
//unsigned char	ab15[] =	{ 0x45,0x88,0x7B,0x01,0x2C,0x7B,0xB3,0x47,0x7B,0x01}; // Hook Levels      
//unsigned char	ab16[] =	{ 0x45,0x78,0x00,0xC0,0x6D,0x7A,0xB3,0x48,0x08,0x00}; // Ramp Generator   
//unsigned char	ab17[] =	{ 0x45,0x58,0x4A,0x41,0x34,0xDB,0x0E,0xA2,0x2A,0x00}; // TTX    
//unsigned char	ab18[] =	{0x45,0x38,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG1              
//unsigned char	ab19[] =	{0x45,0x40,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG2              
//unsigned char	ab20[] =	{ 0x45,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};  // Reserved

//signed char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xC0,0x04}; // AX-Filter -������ 29--- OLD---------------------------------!!

//unsigned char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xb0,0x27}; // AX-Filter -������ 20

//unsigned char	a14[] =	{ 0x46, 0x30, 0x07,0x10,0x79,0x11,0x02,0xFB,0x60,0x00,0x00,0x00 }; //DTMF POP
//unsigned char	a15[] =	{ 0x46,0x4A,0x00 };
//unsigned char	a16[] =	{0x44, 0x21, 0x00, 0x16, 0x06, 0x00, 0x00,  0x16, 0x06, 0x00 }; //pcmr,pcmx- line A
//unsigned char	a23[] =	{0x4c, 0x21, 0x80, 0x96, 0x86, 0x80, 0x80,  0x96, 0x86, 0x80 }; //pcmr,pcmx- line B
//unsigned char	a16[] =	{0x44, 0x21, 0x16, 0x16, 0x06, 0x00, 0x16,  0x016, 0x06, 0x00 }; //pcmr,pcmx
//unsigned char	a17[] =	{ 0x44, 0x1A, 0x00 }; // DSCR
//unsigned char	a18[] =	{ 0x44, 0x2B, 0x04 }; //TSTR3
//unsigned char	a19[] =	{ 0x44, 0x15, 0x01, 0x20, 0x07, 0x00, 0x03 };// bcr1-5
//unsigned char	a21[] =	{ 0x44,0x06,0x80 };  //XCR
//unsigned char	a20[] =	{ 0x44,0x1c,0x22 };  //LMCR1
//unsigned char	a24[] =	{ 0x44,0x11,0xbf };  //mack

//unsigned char	ac[] =	{ 0xC4,0x07,0xff,0x00,0x00,0x00,0x00 };  // request intreg
//unsigned char	ac1[] =	{ 0xC4,0x09,0xff,0x00, 0x00}; //0x00,0x00 };  // request intreg



// �������
// AKTIV
//unsigned char	a22[] =	{ 0x02 };  // AKTIV mode -- ����������� ���������
//unsigned char	a221[] =	{ 0x44,0x1c,0x22 };  // LMCR1
//unsigned char	a222[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x04); // off hook

// PAUSE
//unsigned char	a26[] =	{ 0x02 }; // RING pause MODE -- ��������� ���
//unsigned char	a261[] =	{ 0x44,0x1c,0xAA };  // LMCR1
//unsigned char	a262[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x04); // off hook

// RING
//unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- ������ ������
//unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
//unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x00); // �n hook

// WAIT
//unsigned char	a28[] =	{ 0x07 }; // power dnv mode -- �������� �������� ������
//outportb(0x511, 0x00); // on hook

// void main()










