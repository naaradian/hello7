//file prm_pch.cpp
#include "start.h"
#include "hello7.h"
#include "embisr.h"
#include <mqx.h>
#include <bsp.h>



extern int ecount2;

extern "C" void LoadDDSN2()
{
unsigned char * pData;
static unsigned char DataDDS[LEN_DATA_DDS];//

// 0,  0, 0x88
//  00;  01H, 00H  
//  00;  02H, 02H  
//  00;  03H, 19H  
//  00;  04H, 00H  
//  00;  05H, 00H  


//0,  0, 0x88

pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x88;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  01H, 00H 

pData = DataDDS;
*pData++ = 0;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  02H, 02H    

pData = DataDDS;
*pData++ = 0;   *pData++ = 2;	 *pData = 2;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);


//  00;  03H, 19H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 3;	 *pData = 0x19;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00;  04H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00;  05H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  10H,0D0H  

pData = DataDDS;
#ifdef GEN_100
*pData++ = 0;   *pData++ = 0x10;	 *pData = 0xD0;
#else
*pData++ = 0;   *pData++ = 0x10;	 *pData = 0x80;
#endif
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  12H, 00H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x12;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
 
//  00H,  13H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x13;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  20H, 12H 
  
pData = DataDDS;

#ifdef GEN_100
*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x12;
#else
//*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x3;
//*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x4; //7200
*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x2; //73...
#endif

SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  22H, 04H  

pData = DataDDS;
#ifdef GEN_100
*pData++ = 0;   *pData++ = 0x22;	 *pData = 4;
#else
*pData++ = 0;   *pData++ = 0x22;	 *pData = 3;
#endif
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  04H, 00H 
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  01H,  05H, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  06H, 01H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 6;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0A6H, 63H         ;;;189,22 MHZ      
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA6;	 *pData = 0x63;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                  
//  01H, 0A7H, 0CBH              ;;     
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA7;	 *pData = 0xCB;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                        
//  01H, 0A8H, 3CH    
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA8;	 *pData = 0x3C;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                          
//  01H, 0A9H, 03H  
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA9;	 *pData = 3;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                            
//  01H, 0AAH, 34H   
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAA;	 *pData = 0x34;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                           
//  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAB;	 *pData = 0x45;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ACH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAC;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ADH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAD;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  00H, 05H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 0;	 *pData = 5;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  01H, 00H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0BH,0FFH  

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xB;	 *pData = 0xFF;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0CH, 01H 

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xC;	 *pData = 3;  //max I
//*pData++ = 4;   *pData++ = 0xC;	 *pData = 1;  //max I
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

  
   
//  04H,  0EH, 10H 
  
pData = DataDDS;
*pData++ = 4;   *pData++ = 0xE;	 *pData = 0x10;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  00H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 0;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  01H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  02H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 2;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  03H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 3;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  04H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  05H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  06H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 6;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  07H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 7;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  08H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 8;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  09H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 9;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);




//test ok *pData++ = 0x55;   *pData++ = 0xAA;	 *pData = 0x99;

// = 
//{
/*
  0,  0, 0x88
  00;  01H, 00H  
  00;  02H, 02H  
  00;  03H, 19H  
  00;  04H, 00H  
  00;  05H, 00H  
  00H,  10H,0D0H  
  00H,  12H, 00H  
  00H,  13H, 00H  
  00H,  20H, 12H  
  00H,  22H, 04H  
  01H,  04H, 00H  
  01H,  05H, 00H  
  01H,  06H, 01H  
  01H, 0A6H, 63H         ;;;189,22 MHZ                                      
  01H, 0A7H, 0CBH              ;;                                           
  01H, 0A8H, 3CH                                                            
  01H, 0A9H, 03H                                                            
  01H, 0AAH, 34H                                                            
  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 
  00H,  05H, 01H  
  01H, 0ACH, 00H  
  01H, 0ADH, 00H  
  02H,  00H, 05H  
  02H,  01H, 00H  
  04H,  0BH,0FFH  
  04H,  0CH, 01H  
  04H,  0EH, 10H  
  05H,  00H, 00H  
  05H,  01H, 00H  
  05H,  02H, 00H  
  05H,  03H, 00H  
  05H,  04H, 00H  
  05H,  05H, 00H  
  05H,  06H, 00H  
  05H,  07H, 00H  
  05H,  08H, 00H  
  05H,  09H, 00H  
  00H,  05H, 01H  
  */
//};


//test okSendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
}

//_________________________________________________________________________

extern "C" void LoadDDSN2_test()	   //for test
{
unsigned char * pData;
static unsigned char DataDDS[LEN_DATA_DDS];//

// 0,  0, 0x88
//  00;  01H, 00H  
//  00;  02H, 02H  
//  00;  03H, 19H  
//  00;  04H, 00H  
//  00;  05H, 00H  


//0,  0, 0x88

pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x88;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  01H, 00H 

pData = DataDDS;
*pData++ = 0;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  02H, 02H    

pData = DataDDS;
*pData++ = 0;   *pData++ = 2;	 *pData = 2;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);


//  00;  03H, 19H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 3;	 *pData = 0x19;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00;  04H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00;  05H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  10H,0D0H  

pData = DataDDS;
//*pData++ = 0;   *pData++ = 0x10;	 *pData = 0xD0;
*pData++ = 0;   *pData++ = 0x10;	 *pData = 0x80;	   //101115
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  12H, 00H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x12;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
 
//  00H,  13H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x13;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  20H, 12H 
  
pData = DataDDS;
//101115 *pData++ = 0;   *pData++ = 0x20;	 *pData = 0x12;
//101203 *pData++ = 0;   *pData++ = 0x20;	 *pData = 0x03;
*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x04;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  22H, 04H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x22;	 *pData = 3;
//*pData++ = 0;   *pData++ = 0x22;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  04H, 00H 
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  01H,  05H, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  06H, 01H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 6;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0A6H, 63H         ;;;189,22 MHZ      
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA6;	 *pData = 0x63;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                  
//  01H, 0A7H, 0CBH              ;;     
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA7;	 *pData = 0xCB;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                        
//  01H, 0A8H, 3CH    
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA8;	 *pData = 0x3C;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                          
//  01H, 0A9H, 03H  
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA9;	 *pData = 3;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                            
//  01H, 0AAH, 34H   
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAA;	 *pData = 0x34;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                           
//  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAB;	 *pData = 0x45;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ACH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAC;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ADH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAD;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  00H, 05H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 0;	 *pData = 5;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  01H, 00H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0BH,0FFH  

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xB;	 *pData = 0xFF;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0CH, 01H 

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xC;	 *pData = 3;  //max I
//*pData++ = 4;   *pData++ = 0xC;	 *pData = 1;  //max I
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

  
   
//  04H,  0EH, 10H 
  
pData = DataDDS;
*pData++ = 4;   *pData++ = 0xE;	 *pData = 0x10;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  00H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 0;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  01H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 1;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  02H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 2;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  03H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 3;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  04H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 4;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  05H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 5;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  06H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 6;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  07H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 7;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  08H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 8;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  09H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 9;	 *pData = 0;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);




//test ok *pData++ = 0x55;   *pData++ = 0xAA;	 *pData = 0x99;

// = 
//{
/*
  0,  0, 0x88
  00;  01H, 00H  
  00;  02H, 02H  
  00;  03H, 19H  
  00;  04H, 00H  
  00;  05H, 00H  
  00H,  10H,0D0H  
  00H,  12H, 00H  
  00H,  13H, 00H  
  00H,  20H, 12H  
  00H,  22H, 04H  
  01H,  04H, 00H  
  01H,  05H, 00H  
  01H,  06H, 01H  
  01H, 0A6H, 63H         ;;;189,22 MHZ                                      
  01H, 0A7H, 0CBH              ;;                                           
  01H, 0A8H, 3CH                                                            
  01H, 0A9H, 03H                                                            
  01H, 0AAH, 34H                                                            
  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 
  00H,  05H, 01H  
  01H, 0ACH, 00H  
  01H, 0ADH, 00H  
  02H,  00H, 05H  
  02H,  01H, 00H  
  04H,  0BH,0FFH  
  04H,  0CH, 01H  
  04H,  0EH, 10H  
  05H,  00H, 00H  
  05H,  01H, 00H  
  05H,  02H, 00H  
  05H,  03H, 00H  
  05H,  04H, 00H  
  05H,  05H, 00H  
  05H,  06H, 00H  
  05H,  07H, 00H  
  05H,  08H, 00H  
  05H,  09H, 00H  
  00H,  05H, 01H  
  */
//};


//test okSendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
}


extern "C" void LoadDDSN3()
{
unsigned char * pData;
static unsigned char DataDDS[LEN_DATA_DDS];//

// 0,  0, 0x88
//  00;  01H, 00H  
//  00;  02H, 02H  
//  00;  03H, 19H  
//  00;  04H, 00H  
//  00;  05H, 00H  


//0,  0, 0x88

pData = DataDDS;
*pData++ = 0;   *pData++ = 0;	 *pData = 0x88;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  01H, 00H 

pData = DataDDS;
*pData++ = 0;   *pData++ = 1;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

// 00;  02H, 02H    

pData = DataDDS;
*pData++ = 0;   *pData++ = 2;	 *pData = 2;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);


//  00;  03H, 19H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 3;	 *pData = 0x19;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00;  04H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 4;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00;  05H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  10H,0D0H  

pData = DataDDS;
//*pData++ = 0;   *pData++ = 0x10;	 *pData = 0xD0;
*pData++ = 0;   *pData++ = 0x10;	 *pData = 0x80;	   //101115
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  12H, 00H 
  
pData = DataDDS;
*pData++ = 0;   *pData++ = 0x12;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
 
//  00H,  13H, 00H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x13;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  20H, 12H 
  
pData = DataDDS;
//101115 *pData++ = 0;   *pData++ = 0x20;	 *pData = 0x12;
//101203 *pData++ = 0;   *pData++ = 0x20;	 *pData = 0x03;
//*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x04;
*pData++ = 0;   *pData++ = 0x20;	 *pData = 0x03;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  22H, 04H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 0x22;	 *pData = 3;
//*pData++ = 0;   *pData++ = 0x22;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  04H, 00H 
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 4;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  01H,  05H, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 5;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H,  06H, 01H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 6;	 *pData = 1;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0A6H, 63H         ;;;189,22 MHZ      
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA6;	 *pData = 0x63;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                  
//  01H, 0A7H, 0CBH              ;;     
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA7;	 *pData = 0xCB;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                        
//  01H, 0A8H, 3CH    
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA8;	 *pData = 0x3C;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                          
//  01H, 0A9H, 03H  
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xA9;	 *pData = 3;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                            
//  01H, 0AAH, 34H   
  
pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAA;	 *pData = 0x34;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
                                                           
//  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAB;	 *pData = 0x45;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ACH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAC;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  01H, 0ADH, 00H  

pData = DataDDS;
*pData++ = 1;   *pData++ = 0xAD;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  00H, 05H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 0;	 *pData = 5;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  02H,  01H, 00H  

pData = DataDDS;
*pData++ = 2;   *pData++ = 1;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0BH,0FFH  

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xB;	 *pData = 0xFF;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  04H,  0CH, 01H 

pData = DataDDS;
*pData++ = 4;   *pData++ = 0xC;	 *pData = 3;  //max I
//*pData++ = 4;   *pData++ = 0xC;	 *pData = 1;  //max I
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

  
   
//  04H,  0EH, 10H 
  
pData = DataDDS;
*pData++ = 4;   *pData++ = 0xE;	 *pData = 0x10;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  00H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 0;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  01H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 1;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  02H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 2;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  03H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 3;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  04H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 4;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  05H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 5;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  06H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 6;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  07H, 00H  

pData = DataDDS;
*pData++ = 5;   *pData++ = 7;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);

//  05H,  08H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 8;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  05H,  09H, 00H 
  
pData = DataDDS;
*pData++ = 5;   *pData++ = 9;	 *pData = 0;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
   
//  00H,  05H, 01H  

pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);




//test ok *pData++ = 0x55;   *pData++ = 0xAA;	 *pData = 0x99;

// = 
//{
/*
  0,  0, 0x88
  00;  01H, 00H  
  00;  02H, 02H  
  00;  03H, 19H  
  00;  04H, 00H  
  00;  05H, 00H  
  00H,  10H,0D0H  
  00H,  12H, 00H  
  00H,  13H, 00H  
  00H,  20H, 12H  
  00H,  22H, 04H  
  01H,  04H, 00H  
  01H,  05H, 00H  
  01H,  06H, 01H  
  01H, 0A6H, 63H         ;;;189,22 MHZ                                      
  01H, 0A7H, 0CBH              ;;                                           
  01H, 0A8H, 3CH                                                            
  01H, 0A9H, 03H                                                            
  01H, 0AAH, 34H                                                            
  01H, 0ABH, 45H              ;;;26,6 ��� 22 22 22 22 22 22 (����� 100 ���) 
  00H,  05H, 01H  
  01H, 0ACH, 00H  
  01H, 0ADH, 00H  
  02H,  00H, 05H  
  02H,  01H, 00H  
  04H,  0BH,0FFH  
  04H,  0CH, 01H  
  04H,  0EH, 10H  
  05H,  00H, 00H  
  05H,  01H, 00H  
  05H,  02H, 00H  
  05H,  03H, 00H  
  05H,  04H, 00H  
  05H,  05H, 00H  
  05H,  06H, 00H  
  05H,  07H, 00H  
  05H,  08H, 00H  
  05H,  09H, 00H  
  00H,  05H, 01H  
  */
//};


//test okSendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
}

//_________________________________________________________________________




unsigned char ascii[] = {
//0:
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xD5,0xDA,
0x20,0x20,0x32,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//32:
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x20,
//64:
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x20,0x5d,0x5e,0x20,
//96
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
//
//128:
0x20,0x20,0x27,0x20,0xca,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0xca,0xcb,0xdf,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//160:
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xfd,0xa2,0x20,0x20,0xc8,0x20,0x2d,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0xfe,0xdf,0xb5,0x20,0x20,0xc9,0x20,0x20,0x20,0x20,
//192:
0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,0xa8,
0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
//224:
0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,0xbe,
0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,0xc1,0xe6,0xc2,0xc4,0x62,0xc5,0xc6,0xc7
//256
};

void AsciiInit()
{
//0
for(int i = 0; i <= 14; i++)
{
 ascii[i] = 0x20;
}
ascii[15] = 0xD5;  ascii[16] = 0xDA; 

//16
ascii[17] = 0x20;	 ascii[18] = 0x20;	 ascii[19] = 0x32;
for(i = 20; i <= 33; i++)
{
 ascii[i] = 0x20;
}
for(i = 32; i <= 62; i++)
{
 ascii[i] = (i - 1);
}
 ascii[63] = 0x20;

for(i = 64; i <= 91; i++)
{
 ascii[i] = (i - 1);
}
ascii[92] = 0x20;	 ascii[93] = 0x5d;	 ascii[94] = 0x5e;	 ascii[95] = 0x20;
//96
for(i = 96; i <= 127; i++)
{
 ascii[i] = (i - 1);
}
//128
for(i = 128; i <= 129; i++)
{
 ascii[i] = 0x20;
}
ascii[130] = 0x27;	 ascii[131] = 0x20;	ascii[132] = 0xca;

for(i = 133; i <= 146; i++)
{
 ascii[i] = 0x20;
}

ascii[147] = 0xca; ascii[148] = 0xcb; ascii[149] = 0xdf;

for(i = 150; i <= 166; i++)
{
 ascii[i] = 0x20;
}

ascii[167] = 0xfd; ascii[168] = 0xa2;

for(i = 169; i <= 170; i++)
{
 ascii[i] = 0x20;
}
ascii[171] = 0xc8; ascii[172] = 0x20; ascii[173] = 0x2d;

for(i = 174; i <= 181; i++)
{
 ascii[i] = 0x20;
}

ascii[182] = 0xfe; ascii[183] = 0xdf; ascii[184] = 0xb5;

for(i = 185; i <= 186; i++)
{
 ascii[i] = 0x20;
}
ascii[187] = 0xc9;

for(i = 188; i <= 191; i++)
{
 ascii[i] = 0x20;
}
//192
ascii[192] = 0x41;	ascii[193] = 0xa0;	 ascii[194] = 0x42;	 ascii[195] = 0xa1;	
ascii[196] = 0xe0;	ascii[197] = 0x45;	 ascii[198] = 0xa3;	 ascii[199] = 0xc4;
ascii[200] = 0xa5;  ascii[201] = 0xa6;	 ascii[201] = 0x4b;	 ascii[203] = 0xa7;
ascii[204] = 0x4d;	ascii[205] = 0x48;	 ascii[206] = 0x4f;  ascii[207] = 0xa8;

ascii[208] = 0x50;	ascii[209] = 0x43;	 ascii[210] = 0x54;	 ascii[211] = 0xa9;
ascii[212] = 0xaa;	ascii[213] = 0x58;	 ascii[214] = 0xe1;	 ascii[215] = 0xab;
ascii[216] = 0xac;	ascii[217] = 0xe2;	 ascii[218] = 0xad;	 ascii[219] = 0xae;	 
ascii[220] = 0x62;	ascii[221] = 0xaf;	 ascii[222] = 0xb0;	 ascii[223] = 0xb1;
//224
ascii[224] = 0x61;	ascii[225] = 0xb2;	 ascii[226] = 0xb3;	 ascii[227] = 0xb4;
ascii[228] = 0xe3;  ascii[229] = 0x65;	 ascii[230] = 0xb6;	 ascii[231] = 0xb7;
ascii[232] = 0xb8;	ascii[233] = 0xb9;	 ascii[234] = 0xba;	 ascii[235] = 0xbb;
ascii[236] = 0xbc;	ascii[237] = 0xbd;	 ascii[238] = 0x6f;	 ascii[239] = 0xbe;

ascii[240] = 0x70;	ascii[241] = 0x63;	 ascii[242] = 0xbf;	 ascii[243] = 0x79;
ascii[244] = 0xe4;	ascii[245] = 0x78;	 ascii[246] = 0xe5;	 ascii[247] = 0xc0;
ascii[248] = 0xc1;	ascii[249] = 0xe6;	 ascii[250] = 0xc2;	 ascii[251] = 0xc4;	
ascii[252] = 0x62;	ascii[253] = 0xc5;	 ascii[254] = 0xc6;	 ascii[255] = 0xc7; 

}
union u2uc
{
    unsigned short u;
	unsigned char uc[2];
};
unsigned char HexChar(unsigned char s)
{
  if(s<=9) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 'x';
}
void ConvertToWin1251(char *str)
{
	int i=0;
	unsigned char ch;
  while(str[i])
	{
		ch=str[i];
		str[i]=ascii[ch];
		i++;
		if(i>=24)
		{
			str[i]=0; 
			return;
		}
	}
}
unsigned char Modify5A(unsigned char byte)
{
	switch(byte)
	{
		case 0x00: return 0x5A;
		case 0x01: return 0x55; 
		case 0x02: return 0xA5; 
		case 0x03: return 0xAA; 
		default: return 0;
	}

}
struct MsgStatus
{
	unsigned char readyToSend : 1;
	unsigned char isRS232 : 1;
	unsigned char isRS485 : 1;
	unsigned char reserved : 5;
};

struct DmuStatus
{
	unsigned long status;
	unsigned long mode;
	unsigned long freq;
	unsigned long rate;
	unsigned long rezerv;
};

union DmuStatusu
{
	DmuStatus dmustatus;
	unsigned char byte[20];
};




union UnMsgStatus
{
	MsgStatus msgStatus;
	unsigned char byte;
};

struct TOM // [TR�00MEK]
{
	unsigned char K : 1; // K - ������� ��������� ������ ���������, ��������������� � "1" ��� ��������� ������ ���������;
	unsigned char E : 1; // E - ��� ������ � CRC, ��������������� � "1" ���� �� �������� CRC;
	unsigned char M : 1; // M - ��� ��������, ��������������� � "1" ��� ������� ������ "��������� ��������";
	unsigned char reserved : 2;
	unsigned char C : 1; // R - ������� ��������� �� RS-485 (��� ������ �������)
	unsigned char R : 1; // C - ��������������� � "1" ���� ��� ������ ���������� ������������� � �������.
	unsigned char T : 1; // T - ��� �������; 
//	TOM() { reserved=0; T=R=C=M=E=K=0; }
};

union UnTOM
{
	unsigned char byte;
	TOM tom;
};
//___________________________________________________________________________________
struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[270];
	unsigned char TOM()		{   return body[0]; 			}
	unsigned char Cycle()	{   return body[1]; 			}
	unsigned short AddrI()	{	return body[3]  + (body[2]<<8);}		// 2
	unsigned short AddrS()	{	return body[5]  + (body[4]<<8);}		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);}		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;}
 	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}
 	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }
	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 270-counter; }
	int short IsEnd();
	int short IsEndOfHeader();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned short ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }
	void SetDir(unsigned char d) { dir= d; } // dir = 1 ������ � West, dir=2 ������ � East
	void Copy(EmbMsg m);
};

void EmbMsg::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsg::Init()
{
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
}

unsigned short EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned short EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
		return 1;
	}
	else
	  return 0;
}

int short EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsg::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned short EmbMsg::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
 		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
}

unsigned short EmbMsg::CalcCRC()
{
  int i;
	unsigned c=0;
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			body[Length()+11]=(c>>8)&0xFF;
			body[Length()+12]=c&0xFF;
			return c;
		}
		else return 0;
 } 

//___________________________________________________________________________________
#ifdef PROG_PRM_PCH_N

#define MAX_LEN	(270)

struct EmbMsgN
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned short counter;
	unsigned char body[ MAX_LEN];
	unsigned char STARTN()		{   return body[0]; 			}
	unsigned char Cycle()	{   return body[1]; 			}
	unsigned short AddrI()	{	return body[3]  + (body[2]<<8);}		// 2
	unsigned short AddrS()	{	return body[5]  + (body[4]<<8);}		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);}		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;}
 	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}
 	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length() + 11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }
	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }
	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return  MAX_LEN-counter; }
	int short IsEnd();
	int short IsEndOfHeader();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned short ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }
	void SetDir(unsigned char d) { dir= d; } // dir = 1 ������ � West, dir=2 ������ � East
	void Copy(EmbMsg m);
//__________________________________________________________________
	unsigned char ParseN(void);
	void SendAns(void);
	void SetCommandN(unsigned long);
	void RunCommandN1(void);
	void RunCommandN2(unsigned short);
	void RunCommandN3(unsigned char);
	void RunCommandN4(void);

	void SetStartAns(void);
	void SetStopAns(void);
	unsigned long GetAnsLen(void){return current_posa;}
	unsigned char GetAns(unsigned long pos){return ans[pos];}
    void AddToAns(unsigned char);
	unsigned char ChkCRCN(unsigned long);
//	void SetFreqN(unsigned short);
//	void SetAttN(unsigned char);

	unsigned long current_posr;
	unsigned long current_posw;
	unsigned char parsed_now;
	unsigned char ans[MAX_LEN];
	unsigned long current_posa; //answer
	unsigned char alarm;
 //	unsigned char lock;
//	unsigned char flagatt;
//	unsigned short curFreq;
//	unsigned char curAtt;
//	unsigned char curLev;

//___________________________________________________________________
};
//___________________________________________

#define START_COMMAND	(0xAA)
#define STOP_COMMAND	(0x55)
#define MY_ADDRESS		(0x01) //make in future
#define BRD_ADDRESS		(0xFF) //addr for all
#define MASK_REQUEST	(0x80)
#define	COMM1_LEN		(1)
#define	COMM2_LEN		(1)
#define	COMM3_LEN		(1)
#define	COMM4_LEN		(4)
unsigned char SetFreqN(unsigned short);
unsigned char SetAttN(unsigned char);
unsigned char GetLevN(void);
unsigned char GetAttN(void);
unsigned short GetFreqN(void);
unsigned short GetLockN(void);
unsigned char GetAlarmN(void);
void TransN(unsigned char);




void EmbMsgN::AddToAns(unsigned char data)
{
 if(current_posa < MAX_LEN)
 ans[current_posa++] = data;
}

void EmbMsgN::SetStartAns(void)
{
 AddToAns(START_COMMAND);
// ans[current_posa++] = MY_ADDRESS;
}

void EmbMsgN::SetStopAns(void)
{
 AddToAns(STOP_COMMAND);
}

unsigned char EmbMsgN::ChkCRCN(unsigned long pos)
{
 unsigned char crc = 0;
 unsigned long i;

 for(i = pos;	i < (pos + body[pos + 1] + 2); i++)
{
  crc += body[i];
//  printf("i : %d  body[i] %0x%02X", i, body[i]);
}
 crc += 1;
// printf("crc = 0x%02X", crc);
 if(crc  == body[i+1])
  return 1; //temporary
 else
  return 0;
}

void EmbMsgN::RunCommandN1(void)
{
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM1_LEN);
curcrc += COMM1_LEN;
AddToAns(GetAlarmN());
curcrc += GetAlarmN();
AddToAns(curcrc+1);
}



void EmbMsgN::RunCommandN2(unsigned short freq)
{
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM2_LEN);
curcrc += COMM2_LEN;
SetFreqN(freq);
AddToAns(GetLockN());
curcrc += GetLockN();
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN3(unsigned char att)
{
unsigned char curcrc = 0; 
unsigned char flag;

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM3_LEN);
curcrc += COMM3_LEN;
flag = SetAttN(att);
AddToAns(flag);
curcrc += flag;
AddToAns(curcrc+1);
}

void EmbMsgN::RunCommandN4()
{
unsigned short curLev = GetLevN();
unsigned char curAtt = GetAttN();
unsigned short curFreq = GetFreqN();
unsigned char curcrc = 0; 

AddToAns(MY_ADDRESS);
curcrc += MY_ADDRESS;
AddToAns(COMM4_LEN);
curcrc += COMM4_LEN;
AddToAns(curFreq>>8);
curcrc += curFreq>>8;
AddToAns(curFreq & 0xf);  
curcrc += curFreq& 0xf;
AddToAns(curAtt);
curcrc += curAtt;
AddToAns(curLev);
curcrc += curLev;
AddToAns(curcrc+1);
}

void EmbMsgN::SetCommandN(unsigned long pos)
{
 switch(body[pos++])
 {
  case 1	: RunCommandN1(); break;
  case 2	: RunCommandN2((body[pos] << 8) + body[pos +1]); break;
  case 3	: RunCommandN3(body[pos]); break;
  case 4	: RunCommandN4(); break;
  default 	: break;
 }
}

unsigned char EmbMsgN::ParseN(void)
{
parsed_now = 1;
unsigned long current_posr = 0;
unsigned long len;
unsigned char flag = 0;
//printf("\n\r 1");
// TransN('1');
printf("\n\r>%d  - %d ",current_posr, current_posw);
 while(current_posr < current_posw)
 {
 // current_posr++;
 printf(" %02X", body[current_posr++]);
printf("\n\r 1");
 //	if(0)
// TransN(body[current_posr]);
   if(body[current_posr++] ==  START_COMMAND)
   {
printf(" 2");
//TransN('2');

	len = body[current_posr + 1];
	if(body[current_posr] & MASK_REQUEST)
	{
printf(" 3");
//TransN('3');
     if(((body[current_posr] & 0xF) == (unsigned char)MY_ADDRESS) ||  (body[current_posr] == (unsigned char)BRD_ADDRESS))
     {
printf(" 4");
//TransN('4');
 	   if(ChkCRCN(current_posr))	  //now in current_posr is addr
 //	   if(1)
	   {
 		printf("C");
//TransN('5');
	     flag = 1;
	     SetStartAns();
         SetCommandN(current_posr + 2);
	   }   //crc
     }	  //address
	 else	//address
	 {
//printf(" addr = 0x%02X" , body[current_posr]); //for debug
	 }
	} //Mask_request
	 else	//address
	 {
 //     printf("m"); //for debug
	 }

	  current_posr += len + 2;
	  if(current_posr > MAX_LEN) break;
   }  //start
 }	//while
 if(flag)
 {
  SetStopAns();
//  SendAns();
 }
 // Init();
parsed_now = 0;  
 return flag;	 
} 
//____________________________________


void EmbMsgN::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsgN::Init()
{
	counter=0;
//t  for(int i=0; i<MAX_LEN; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
//___________________________________________
 current_posr = 0;
 current_posw = 0;
 parsed_now = 0;
 current_posa = 0;
//t for(i=0; i<MAX_LEN; i++) ans[i]=0;
// alarm = 0;
// lock = 0;
// flagatt = 0;
}

unsigned short EmbMsgN::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned short EmbMsgN::Add(unsigned char byte)
{
//_______________________________________
//t  if(parsed_now) return 0;
//_______________________________________ 
  if(counter<MAX_LEN)
	{
//________________________________
		current_posw++;
//________________________________
		body[counter++]=byte;
		return 1;
	}
	else
	    return 0;
}

int short EmbMsgN::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsgN::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned short EmbMsgN::ChkCRC()
{
  int i;
	unsigned c=0, b=0;
 		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();	
			if(b==c) return 1;
			else return 0;
		}
}

unsigned short EmbMsgN::CalcCRC()
{
  int i;
	unsigned c=0;
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			body[Length()+11]=(c>>8)&0xFF;
			body[Length()+12]=c&0xFF;
			return c;
		}
		else return 0;
 } 
 
#endif // PROG_PRM_PCH_N 
/////////////////////
#define   EmbMsgBuffer_Size (32)
struct EmbMsgBuffer
{
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
   EmbMsg Buff[EmbMsgBuffer_Size];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned short Used();
    unsigned short Free();
};

void EmbMsgBuffer::Init()
{
  BuffSize = EmbMsgBuffer_Size;
  Head = 0;
  Tail = 0;
}

void EmbMsgBuffer::Add(EmbMsg &msg)
{
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize)
  {
   
   Head = 0;
   }
}

void EmbMsgBuffer::Get(EmbMsg &msg)
{
  if(++Tail < BuffSize) 
	{
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[Tail-1].body[i];
	}
	else
	{
		Tail = 0;
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[BuffSize-1].body[i];
	}
}

unsigned short EmbMsgBuffer::Used()
{
  int n = Head - Tail;

  if( n >= 0 )
  {
    return n;
   }
  else
  {	 
   return n+BuffSize;
  }
}

unsigned short EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}
/////////////////////
struct Emb2TypeVer
{
	unsigned short type;
	unsigned short softVer;
	unsigned short ctrlNumber;
	unsigned short ctrlYear;
	unsigned short ctrlVer1;
	unsigned short ctrlVer2;
	unsigned char signature_hardware[16];
	unsigned char signature_software[16];
};

union UnEmb2TypeVer
{
	Emb2TypeVer emb2TypeVer;
	unsigned char byte[44];
};

struct StateBMD155
{
	unsigned char state;  // ��� 0: "0" - ���������� ����� � ���1, "1" - �����
									// ��� 1: "0" - ���������� ����� � ���2, "1" - �����
									// ��� 1: "0" - ���������� ����� ��, "1" - �����
	unsigned char state2;  // ��������� ����� �����������
	unsigned char ppu1_bytes[16];
	unsigned char ppu2_bytes[16];														// 34
	unsigned long count_no_correct_block1;									// 42
	unsigned long count_no_correct_block2;									// 46
	unsigned long count_no_correct_result;									// 50
	unsigned long count_notRS1;															// 54
	unsigned long count_notRS2;															// 58
	unsigned long count_block;															// 62
	unsigned char mod; // ��������� ����� �����������       // 63
	unsigned char dem1; // ��������� ����� �����������      // 64
	unsigned char dem2; // ��������� ����� �����������      // 65
	unsigned char state_dem1; // ��������� ����� �����������// 66
	unsigned char state_dem2; // ��������� ����� �����������// 67
	unsigned char statePI; // ��������� ����� �����������		// 68	
	unsigned char loopPI; // ��������� �������							// 69
	unsigned char demPI; // ��������� �������������					// 70
};

union UnStateBMD155
{
	StateBMD155 stateBMD155;
	unsigned char byte[72];
};
	
struct StatePUM
{
	unsigned char ver;						// 1   //0
	unsigned char reserv; 				// 2	   //1
	unsigned char reserv1;	 //my					// 1 //2
	unsigned char reserv2;	 //my						 //3
	unsigned long ulBlock;				// 6	 +2		  //4 5 6 7
	unsigned long ulErrOut;				// 10	 +2		 //8,9,10,11
	unsigned long ulErrAfterRS1;	// 14		 +2
	unsigned long ulErrAfterRS2;	// 18	    +2
	unsigned long ulErrBeforeRS1;	// 22	   +2
	unsigned long ulErrBeforeRS2;	// 26	   +2
	unsigned char state[16];			// 42	 +2
};

union UnStatePUM
{
	StatePUM statePUM;
	unsigned char byte[44];
};

struct Command
{
	unsigned char chan;
	unsigned char command;
	unsigned char par;
	unsigned char done;
};

struct Emb2NetStat
{
	unsigned long selfPacketSend; // 4
	unsigned long selfPacketRecv; // 4
	unsigned long allPacketRecv;  // 4
	unsigned short requestMarker; // 2
	unsigned short genMarker;     // 2
	unsigned short highID;        // 2
	unsigned short buffModPd;        // 2
	unsigned short buffModPm;        // 2
	unsigned short buffTransPd;        // 2
	unsigned short buffTransPm;        // 2
	unsigned short buff232Pd;        // 2
	unsigned short buff232Pm;        // 2
	unsigned short markerTime; //2 
	unsigned char ready_transit; //1 
	unsigned char ready_mod; //1 
};

union UnEmb2NetStat
{
	Emb2NetStat emb2NetStat;
	unsigned char byte[32];
};

struct LtDiod
{
	unsigned char alarmIn1		 : 1;	
	unsigned char alarmSync1  : 1; 	
	unsigned char alarmLevel1 : 1; 
	unsigned char alarmBoard1 : 1; 
	unsigned char alarmIn2		 : 1; 
	unsigned char alarmSync2  : 1; 
	unsigned char alarmLevel2 : 1; 
	unsigned char alarmBoard2 : 1; 	
}; 

union UnLtDiod
{
	unsigned char byte;
	LtDiod ltDiod;
};

struct BmdState
{
	unsigned char alarmIn1		: 1; 
	unsigned char alarmSync1 : 1; 
	unsigned char alarmIn2   : 1; 
	unsigned char alarmSync2 : 1; 
	unsigned char reserv			: 4; 
}; 

union UnBmdState
{
	unsigned char byte;
	BmdState bmdState;
};
////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0;
unsigned long cntflag6;


void Callback0()
{
  time1++;
}

EmbTimerCallback embTimerCallback0;
EmbMsgBuffer rBuffEmbMsg;
EmbMsgBuffer tBuffEmbMsgWest;
EmbMsgBuffer tBuffEmbMsgEast;
EmbMsg embMsg232;
EmbMsg embMsg232E;
EmbMsg embMsgWest;
EmbMsg embMsgEast;
EmbMsg embMsgAns;
EmbMsg embMsgTemp;
EmbMsg *embMsgRequest;
EmbRS232 embRS232;
EmbRS485 embRS485;
EmbMsg embMsg485E;
EmbSerialMD34AVT embSerialACT155;

#ifdef PROG_PRM_PCH_N
EmbMsgN embMsg485;	//091113
#endif
 
	char ch;
	long f_len;
	unsigned char flagRequest=0;
//	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned long timerun;
	unsigned char breakflag;

#ifdef PRM_PCH_DEBUG1
	unsigned long time1start=0, time1finish=0;
#endif //PRM_PCH_DEBUG1

	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned long time1test=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];
    unsigned char * bt;
	unsigned short addr1;
	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
	unsigned char mode5A=0, mode5AWest=0, mode5AEast=0;
	unsigned char mode5A232E = 0;
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;
	unsigned char cycle=0;
	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned short err_tr=0;
	unsigned short err_md=0;
	UnStateBMD155 unStateBMD155;
	UnEmb2TypeVer unEmb2TypeVer; 
	UnStatePUM unStatePUM;
	UnEmb2NetStat unEmb2NetStat;
	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;
	long count_notRS1;
	long count_notRS2;
	long err_tmp;
	int rrr=0;
	int i232;
	unsigned short aI, aS, aR;
	UnLtDiod unLtDiod;
	UnBmdState unBmdState;
	unsigned long send41, send42, received1, received2, good1, good2, bad1, bad2;		//t
	unsigned char   setf1, setatt1, setf2, setatt2, modescan1, modescan2;
	signed long curval1, curval2;


char ProtocolFromModACT155()
{
	int ic=0;
	static char test23 = 0;
	while(embSerialACT155.UsedMod())
	{
			switch(westByte)
			{
			case 0x55: time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgWest.Init(); break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgWest.Init();	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // �������� ����� ���!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
					if(mode5AWest) { embMsgWest.Add(Modify5A(westByte)); mode5AWest=0;	}
					else embMsgWest.Add(westByte);
				}
			}

			if(embMsgWest.IsEnd())
			{
 
				if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
				{
  		   	if(1)
   		   	{
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgWest.FullSize(); i++) 
					{
						switch(embMsgWest.body[i])
						{
					 	case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgWest.body[i]);						}
							}
					 }
				   embSerialACT155.AddTransit(0x55);

				}
					
				if(embMsgWest.AddrS()==SelfID())
				{
					embMsgWest.SetDir(1);
				    rBuffEmbMsg.Add(embMsgWest);
					embMsgWest.Init();
				}
				recieveWest = 0;
			}
//		if(!recieveWest)
		{
			if(tBuffEmbMsgWest.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgWest.Get(embMsgA);


				embSerialACT155.AddTransit(0x55);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgA.body[i]);
					}
  				}
				    embSerialACT155.AddTransit(0x55);
			}
 		}  //is end
	}	  //while
 return 0;
}

char ProtocolFromTransitACT155()
{
	int ic=0;

	while(embSerialACT155.UsedTransit())
	{
 		eastByte = embSerialACT155.GetTransit();
		switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit = time3Marker = time1;  break; // �������� ����� ���!
						// ���� � ������� ���� ����� �� ��������, �� �������� ���
				case 0x5A: mode5AEast=1; ready_transit=1; break;
				default:
					if(markerEast==1)	markerEast=2; 
					if(recieveEast==1)
					{
						if(mode5AEast) { embMsgEast.Add(Modify5A(eastByte)); mode5AEast=0;	}
						else embMsgEast.Add(eastByte); 
					}
		}
		if(embMsgEast.IsEnd())
		{
			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{
  			 if(1)
   		   	{
   	  			embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgEast.FullSize(); i++) 
				{

					switch(embMsgEast.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgEast.body[i]);
					}
				}
			   embSerialACT155.AddMod(0x55);
			 }
				countSend++;
			}

		
	 	 	if(embMsgEast.AddrS()==SelfID())
			{
					embMsgEast.SetDir(2);
				    rBuffEmbMsg.Add(embMsgWest);
				embMsgEast.Init();
			}
		}	 //is end
//		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
				embSerialACT155.AddMod(0x55);
				embSerialACT155.AddMod(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgA.body[i]);
					}
 				}
				embSerialACT155.AddMod(0x55);
			}
	  		}  //(1)
			}	 //while
	return 0;
}
void Check2InitTransitMod()
{
	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
		// ���� ��������� ��������� ready_transit ��� ready_mod �� "0" � "1"
		// �� time3Marker = 0; ��� ����� 2355 ����� � �������� 64�*8/11=46545
	if(time1-time3BlankMod>500) 
	{
		recieveWest=0; 
		time3BlankMod = time1;
		embSerialACT155.AddTransit(0x55);
	}
	if(time1-time3BlankTransit>500)
	{
		recieveEast=0; 
		time3BlankTransit = time1;
		embSerialACT155.AddMod(0x55);
	}
	if((time1-time3highID)>10000) 
	{
		time3highID=time1;
	}		
		if(unEmb2NetStat.emb2NetStat.buffModPm<embSerialACT155.UsedMod()) unEmb2NetStat.emb2NetStat.buffModPm = embSerialACT155.UsedMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPm<embSerialACT155.UsedTransit()) unEmb2NetStat.emb2NetStat.buffTransPm = embSerialACT155.UsedTransit();
		if(unEmb2NetStat.emb2NetStat.buffModPd<embSerialACT155.UsedSendMod()) unEmb2NetStat.emb2NetStat.buffModPd = embSerialACT155.UsedSendMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPd<embSerialACT155.UsedSendTransit()) unEmb2NetStat.emb2NetStat.buffTransPd = embSerialACT155.UsedSendTransit();
		if(unEmb2NetStat.emb2NetStat.buff232Pm<embRS232.UsedReceive()) unEmb2NetStat.emb2NetStat.buff232Pm = embRS232.UsedReceive();
		if(unEmb2NetStat.emb2NetStat.buff232Pd<embRS232.UsedTrans()) unEmb2NetStat.emb2NetStat.buff232Pd = embRS232.UsedTrans();
//		if(!recieveEast)
		{
 				if(!embSerialACT155.UsedSendMod()) 
				{	
   					if(tBuffEmbMsgEast.Used())
					{
	 					EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);
  						embSerialACT155.AddMod(0x55);
						embSerialACT155.AddMod(0xAA);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
							case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
							case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
							case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
							default: embSerialACT155.AddMod(embMsgA.body[i]);
							}
	   					}
						embSerialACT155.AddMod(0x55);
					}
				}
		}

//		if(!recieveWest)
		{
			if(!embSerialACT155.UsedSendTransit()) 
			{	


				if(tBuffEmbMsgWest.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					tBuffEmbMsgWest.Get(embMsgA);
					embSerialACT155.AddTransit(0x55);
					embSerialACT155.AddTransit(0xAA);
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgA.body[i]);
						}
			   //			ResetWatchDog();
					}
					embSerialACT155.AddTransit(0x55);
				}
			}
  		}
 	}

unsigned long ErrResSNMP;
unsigned long timeres;
unsigned char start_count;
union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
//	unsigned char uc[2];
	unsigned char uc[4];
};
unsigned char * addrRAM;
unsigned long shift;
unsigned long len;
unsigned short temp_crc;
UL2UC ul2uc;
UI2UC ui2uc;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct EmbMsgUD
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];
	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned short CRC() {	return body[body[1]+2]; }
	unsigned char Body(int i) { return body[i+2]; }
	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }
	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 64-counter; }
	int  short IsEnd();
	unsigned short ChkCRC();
	unsigned short TestCRC();
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsgUD::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++)
#ifndef TEST_RECEIVE
   body[i]=0;
#else // TEST_RECEIVE
   body[i]=0x97;
#endif //TEST_RECEIVE



}

unsigned short EmbMsgUD::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsgUD::IsEnd()
{
  if(counter>2)
		if(counter==Length()+3)
			return 1;
	return 0;
} 

unsigned short EmbMsgUD::ChkCRC()
{
  //	printf("\n\r CRC(): %02X , TestCRC : %02X", CRC(),TestCRC());	 //for test
	if(CRC()==TestCRC()) return 1;
	else 
	return 0;
}

unsigned short EmbMsgUD::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
	 	body[Length()+2]=c+1;
	return (unsigned char)(c+1);
	}
	else return 0;
} 

unsigned short EmbMsgUD::TestCRC()
{
  int i;
	unsigned char c=0;
	if(body[1]<64) 
	{
		for(i=0; i<body[1]; i++) c += body[i+2];
	 	return (unsigned char)(c+1);
	}
	else return 0;
}
//>>>>>>>>>>>added types

struct Emb5CommandRecieverSetFrequ
{
	unsigned char number; // ��� ������ ��� (1..2)
	unsigned long frequ;  // ����� ��������������� ������� ������ 
				// � ���������� ����� ����� 100���
  //	unsigned char lock;
};


union UnEmb5CommandRecieverSetFrequ
{
	Emb5CommandRecieverSetFrequ emb5commandrecieversetfrequ;
 	unsigned char byte[5];
 //	unsigned char byte[6]; //added lock
};

struct Emb5CommandRPUSetAtt
{
 	unsigned char number; 	 // ��� ������ ��� (1..2)	
	unsigned char stepAtt; // ���������� ��� ����������� 
				 //(����� ����� ���������� � �������� ����������))
};

union UnEmb5CommandRPUSetAtt
{
	Emb5CommandRPUSetAtt emb5commandrpusetatt; 	 // 	
	unsigned char byte[2];
};



	
struct Emb5CommandRecieverSetAtt
{
	unsigned char number; 	 // ��� ������ ��� (1..2)	
	unsigned char stepAtt; // ���������� ��� ����������� 
				 //(����� ����� ���������� � �������� ����������))
};

union UnEmb5CommandRecieverSetAtt
{
	Emb5CommandRecieverSetAtt emb5commandrecieversetatt; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[2];
};

struct Emb5CommandRecieverSetSendStatus
{
	unsigned char number; 		// ��� ������ ��� (1..2)
	unsigned char getGenStatus; 	// 0 � ���������� ��������� ��������� �������, 
					// 1 � ��������� ��������� ��������� �������, 
					// 2 � ����������� ������ �������
};

union UnEmb5CommandRecieverSetSendStatus
{
	Emb5CommandRecieverSetSendStatus emb5commandrecieversetsendstatus; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[2];
};


struct Emb5GetRPUState
{
	unsigned char number; 	 // ��� ������ ��� (1..2)	
};

union UnEmb5GetRPUState
{
	Emb5GetRPUState emb5getrpustate; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[1];
};


struct Emb5Acknowledge
{
	unsigned char number; 		// ��� ������ ��� (1..2)
	unsigned char AcknowledgeType; // ��� �������������� ������� (��. ������� 2.2)
}; // 1 ����


union UnEmb5Acknowledge
{
	Emb5Acknowledge emb5acknowledge; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[2];
};


struct Emb5Exception
{
	unsigned char number; 		// ��� ������ ��� (1..2)
   	unsigned short ExceptionCode; // ��� ������: 0 � ���� ��� ���������� �������;
//	unsigned char rezerved;
          // 1 � ������ ����������
};

union UnEmb5Exception
{
	Emb5Exception emb5exception; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[3];
};


struct Emb5StatusReciever
{
	unsigned char number; // ��� ������ ��� (1..2)
	unsigned char type; // �������� ��� 1..3
	unsigned char status; // ��. ���� �������� <status>
	unsigned char stepAtt; // ��� �����������
	unsigned long frequ; // ����� ��������������� ������� ������ � ����� 100���
	unsigned short signalLevel; // ������� ������� �� ����� ��� � dbm
   	unsigned char genStatus; // ��������� ������� ��������� 
				  // (0 -����, 1- ���, 2- ��������� ������)
	unsigned char lock;
}; // 12 ����

union UnEmb5StatusReciever
{
	Emb5StatusReciever emb5statusreciever; 	 // ��� ������ ��� (1..2)	
   //	unsigned char byte[11];
	unsigned char byte[12];
};

struct Emb5ScanFreq
{
 unsigned char number;
 unsigned long frequStart;	   //? long after short - wil be work?
 unsigned short step;
 unsigned short numOfStep; //2...500
};

union UnEmb5ScanFreq
{
	Emb5ScanFreq emb5scanfreq; 	 // 	
	unsigned char byte[9];
};


struct Emb5StatusFrequScan
{
unsigned char number;
unsigned long frequStart;
unsigned short step;
unsigned short numOfStep;
unsigned char att;
unsigned short level[501];
};

union UnEmb5StatusFrequScan
{
	Emb5StatusFrequScan emb5statusfrequscan; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[1016];
};

struct EmbUpDownStatus
{
 //unsigned long number;
 unsigned long sendup;
 unsigned long received;
 unsigned long crc_ok;
 unsigned long crc_bad;
};

union UnEmbUpDownStatus
{
	EmbUpDownStatus embupdownstatus; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[20];
};

//status
//{
//	��� 0 � ������ ����(1)/���(0) ����������� (������� ������������)
//	��� 1 � ������;
//	��� 2 � ������;
//	��� 3 � ������;
//	��� 4 � ������;
//	��� 5 � ������;
//	��� 6 � ������;
//	��� 7 � ������;
//}

//struct Emb2TypeVer
//{
//	unsigned short type;       // ��� ���������� ���-�� (� ������������� ��� ��������
//	unsigned short softVer;    // ������ �� ���-��
//	unsigned short ctrlNumber; // ��� ������������� ����������
//	unsigned short ctrlYear;   // ��������� ���������� ��� ��������
//	unsigned short ctrlVer1;   // ��������� ���������� ��� ��������
//	unsigned short ctrlVer2;   // ��������� ���������� ��� ��������
//	unsigned char signature_hardware[16]; // ��������� ������, ���� �����������
//	unsigned char signature_software[16]; // ������������ �������  ������� ����
//}; // 44 �����


//signature_hardware[0] = �������� ������ �� ����� 1;
//signature_hardware[1] = ��� ������� �� ����� 1;
//signature_hardware[2] = ������� �� ����� 1;
//signature_hardware[3] = ������ �� ���;
//signature_hardware[4] = �������� ������ �� ����� 3;
//signature_hardware[5] = ��� ������� �� ����� 3;
//signature_hardware[6] = ������� �� ����� 3;
//signature_hardware[7]  = ������;
//signature_hardware[8] = �������� ������ �� ����� 2;
//signature_hardware[9] =  ��� ������� �� ����� 2;
//signature_hardware[10] =  ������� �� ����� 2;
//signature_hardware[11] =  ������ �� ���;
//signature_hardware[12] = ������;
//signature_hardware[13] = ������;
//signature_hardware[14] = ������;
//signature_hardware[15] = ������;

struct Emb5RPUState
{
	unsigned char number; // ��� ������ ��� (1..2)
	unsigned char type; // �������� ��� 1..3
	unsigned char u48; // ������� ���������� ������� +48� �������
	unsigned char u48min; // ������� ����. +48� ����������� �� ������ � �������� ������
	unsigned char u48max; // ������� ����. +48� ������������ �� ������ � �������� ������
	unsigned char u24; // ������� ���������� ������� +24� �������
	unsigned char u24min; // ������� ����. +24� ����������� �� ������ � �������� ������
	unsigned char u24max; // ������� ����. +24� ������������ �� ������ � �������� ������
	unsigned char u7; // ������� ���������� ������� +7� �������
	unsigned char u7min; // ������� ����. +7� ����������� �� ������ � �������� ������
	unsigned char u7max; // ������� ����. +7� ������������ �� ������ � �������� ������
	unsigned char u5; // ������� ���������� ������� +5� �������
	unsigned char u5min; // ������� ����. +5� ����������� �� ������ � �������� ������
	unsigned char u5max; // ������� ����. +5� ������������ �� ������ � �������� ������
	unsigned char u_5; // ������� ���������� ������� -5� �������
	unsigned char u_5min; // ������� ����. -5� ����������� �� ������ � �������� ������
	unsigned char u_5max; // ������� ����. -5� ������������ �� ������ � �������� ������	
	unsigned char temp; // ������� ����������� �������
	unsigned char temp_min; // ������� ����������� ����������� �� ������ � �������� ������
	unsigned char temp_max; // ������� ����������� ������������ �� ������ � �������� ������
}; // 20 ����


union UnEmb5RPUState
{
	Emb5RPUState emb5rpustate; 	 // ��� ������ ��� (1..2)	
	unsigned char byte[20];
};
//<<<<<<<<<<<added types

UnEmbUpDownStatus 	embUpDownStatus1;
UnEmbUpDownStatus 	embUpDownStatus2;

UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ1;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ2;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt1;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt2;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt1;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt2;





UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus1;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus2;

UnEmb5GetRPUState emb5GetRPUState1;
UnEmb5GetRPUState emb5GetRPUState2;

UnEmb5Acknowledge	emb5Acknowledge1;
UnEmb5Acknowledge	emb5Acknowledge2;

UnEmb5Exception emb5Exception1;
UnEmb5Exception emb5Exception2;

UnEmb5StatusReciever emb5StatusReciever1;
UnEmb5StatusReciever emb5StatusReciever2;

UnEmb5RPUState emb5RPUState1;
UnEmb5RPUState emb5RPUState2;

UnEmb5ScanFreq	 emb5ScanFreq1;
UnEmb5ScanFreq	 emb5ScanFreq2;

UnEmb5StatusFrequScan  emb5StatusFrequScan1;
UnEmb5StatusFrequScan  emb5StatusFrequScan2;

EmbMsgUD embMsgUD_1;
EmbMsgUD embMsgUD_2;
EmbMsgUD embMsgUDRequest_1;
EmbMsgUD embMsgUDRequest_2;

unsigned ans1=0, ans2=0;
unsigned short delay1, delay2;  //my

unsigned short countMod;
unsigned short countTransit;

#ifdef TEST_RECEIVE
unsigned long sendp;
unsigned long receivep, receivepb;
unsigned long delta, delta_old;
unsigned long st_count;
unsigned char pped;
unsigned char countt, countr;
unsigned long countsend;

unsigned long countr_bad,countr_ok, countr_all, countta;



#endif //TEST_RECEIVE
unsigned char isreceived1;
unsigned char isreceived2;
unsigned char isreceived3;
unsigned char isreceived4;
unsigned char isreceived5;
unsigned char isreceived6;







unsigned short requestMod=0;
unsigned short requestTransit=0;

//#ifdef PRM_PCH_THREE_LINES

UnEmbUpDownStatus 	embUpDownStatus3;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ3;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt3;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt3;

UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus3;
UnEmb5GetRPUState emb5GetRPUState3;
UnEmb5Acknowledge	emb5Acknowledge3;
UnEmb5Exception emb5Exception3;
UnEmb5StatusReciever emb5StatusReciever3;
UnEmb5RPUState emb5RPUState3;
UnEmb5ScanFreq	 emb5ScanFreq3;
UnEmb5StatusFrequScan  emb5StatusFrequScan3;
EmbMsgUD embMsgUD_3;
EmbMsgUD embMsgUDRequest_3;
unsigned ans3=0;
unsigned short delay3;  //my
unsigned short countPower=0;
unsigned short requestPower=0;
unsigned char   setf3, setatt3, modescan3;
unsigned char  ready_power, old_ready_power; 
unsigned long  time3old;
signed long curval3;
unsigned char request3;
unsigned char markerPower;
unsigned long time3BlankPower;
unsigned char delete_msgPower;
unsigned char recievePower;
unsigned char mode5APower;
EmbMsgBuffer tBuffEmbMsgPower;

//#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
unsigned short countTransit4,  countTransit5, countTransit6;
unsigned short requestTransit4,requestTransit5, requestTransit6;
unsigned short fl1,fl2,fl3,fl4,fl5,fl6;

 unsigned char start4, start5,start6;


//___________________________
unsigned char mode5AWest2;
unsigned short countMod2=0;
unsigned char mode5AWest3;
unsigned short countMod3=0;

//___________________________




UnEmbUpDownStatus 	embUpDownStatus4;
UnEmbUpDownStatus 	embUpDownStatus5;
UnEmbUpDownStatus 	embUpDownStatus6;

UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ4;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ5;
UnEmb5CommandRecieverSetFrequ emb5CommandRecieverSetFrequ6;

UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt4;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt5;
UnEmb5CommandRecieverSetAtt emb5CommandRecieverSetAtt6;

UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt4;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt5;
UnEmb5CommandRPUSetAtt emb5CommandRPUSetAtt6;

UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus4;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus5;
UnEmb5CommandRecieverSetSendStatus emb5CommandRecieverSetSendStatus6;

UnEmb5GetRPUState emb5GetRPUState4;
UnEmb5GetRPUState emb5GetRPUState5;
UnEmb5GetRPUState emb5GetRPUState6;

UnEmb5Acknowledge	emb5Acknowledge4;
UnEmb5Acknowledge	emb5Acknowledge5;
UnEmb5Acknowledge	emb5Acknowledge6;


UnEmb5Exception emb5Exception4;
UnEmb5Exception emb5Exception5;
UnEmb5Exception emb5Exception6;

UnEmb5StatusReciever emb5StatusReciever4;
UnEmb5StatusReciever emb5StatusReciever5;
UnEmb5StatusReciever emb5StatusReciever6;

UnEmb5RPUState emb5RPUState4;
UnEmb5RPUState emb5RPUState5;
UnEmb5RPUState emb5RPUState6;

UnEmb5ScanFreq	 emb5ScanFreq4;
UnEmb5ScanFreq	 emb5ScanFreq5;
UnEmb5ScanFreq	 emb5ScanFreq6;

UnEmb5StatusFrequScan  emb5StatusFrequScan4;
UnEmb5StatusFrequScan  emb5StatusFrequScan5;
UnEmb5StatusFrequScan  emb5StatusFrequScan6;

EmbMsgUD embMsgUD_4;
EmbMsgUD embMsgUD_5;
EmbMsgUD embMsgUD_6;

EmbMsgUD embMsgUDRequest_4;
EmbMsgUD embMsgUDRequest_5;
EmbMsgUD embMsgUDRequest_6;


unsigned ans4=0;
unsigned ans5=0;
unsigned ans6=0;

unsigned short delay4;  //my
unsigned short delay5; 
unsigned short delay6; 


unsigned short countPower4=0;
unsigned short countPower5=0;
unsigned short countPower6=0;

unsigned short requestPower4=0;
unsigned short requestPower5=0;
unsigned short requestPower6=0;

unsigned char   setf4, setatt4, modescan4;
unsigned char   setf5, setatt5, modescan5;
unsigned char   setf6, setatt6, modescan6;

unsigned char  ready_power4, old_ready_power4; 
unsigned char  ready_power5, old_ready_power5;
unsigned char  ready_power6, old_ready_power6;

unsigned long  time4old;
unsigned long  time5old;
unsigned long  time6old;

signed long curval4;
signed long curval5;
signed long curval6;
#endif //PRM_PCH_SIX_LINES

//#ifdef PROG_PRM_PCH_L
unsigned char NeedWriteID;
unsigned char test_shift_mode;

//#endif //PROG_PRM_PCH_L

unsigned char Band1, Band2, Band3, Band4, Band5, Band6;

extern "C" signed short ConvVal(unsigned short val)
{
 /*
float fval = (float)val;
// fval *= 0.0221; 
// fval -= 98.2;
 fval *= 0.0227; 
 fval -= 91.649;
return (signed short)fval;
 */
//signed short fval = val * 0.0227 - 91.649;
signed char fval = (val & 0xFFF) * 0.0227 - 91.649;
return 	fval;
//return 	val & 0x0fff;
}

extern "C" void ParseUD_1()
{
 if(modescan1)
 {
 if(curval1 >= 0)
 {
 emb5StatusFrequScan1.emb5statusfrequscan.level[curval1] = ConvVal( (((unsigned short)embMsgUD_1.Body(2)&0x0F) << 8) + 	embMsgUD_1.Body(1));
 }
 else
 {
 }
  return;
 }
 		
 if(start1) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[2] = 1; //have power on 1
 switch(embMsgUD_1.Body(0))
 {
  case 0: if(start1) 
  {unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = embMsgUD_1.Body(1) & DEVICE_TYPE_MASK;
    	   Band1 = embMsgUD_1.Body(1);}	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever1.emb5statusreciever.status =  embMsgUD_1.Body(2) >> 4;
			emb5StatusReciever1.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_1.Body(2)&0x0F) << 8) + embMsgUD_1.Body(1));
			emb5StatusReciever1.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_1.Body(3));
			emb5StatusReciever1.emb5statusreciever.lock =  (unsigned short)embMsgUD_1.Body(2) >> 7;
 			break;
  case 22:	emb5RPUState1.emb5rpustate.temp =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.temp_min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.temp_max =  embMsgUD_1.Body(3); break;
  case 23:	emb5RPUState1.emb5rpustate.u48 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u48min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u48max =  embMsgUD_1.Body(3);  break;
  case 24:	emb5RPUState1.emb5rpustate.u24 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u24min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u24max =  embMsgUD_1.Body(3); break;
  case 25:	emb5RPUState1.emb5rpustate.u7 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u7min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u7max =  embMsgUD_1.Body(3);	break;
  case 26:	emb5RPUState1.emb5rpustate.u5 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u5min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u5max =  embMsgUD_1.Body(3);	 break;
  case 27:	emb5RPUState1.emb5rpustate.u_5 =  embMsgUD_1.Body(1);
			emb5RPUState1.emb5rpustate.u_5min =  embMsgUD_1.Body(2);
			emb5RPUState1.emb5rpustate.u_5max =  embMsgUD_1.Body(3);  break;

#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[0] =  embMsgUD_1.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[2] =  embMsgUD_1.Body(1);	break;
  case 30:	WriteStatus1 = embMsgUD_1.Body(1); break;
  case 31:	ReadStatus1[0] = embMsgUD_1.Body(1); 
			ReadStatus1[1] = embMsgUD_1.Body(2); 
			ReadStatus1[2] = embMsgUD_1.Body(3); break;
  case 32:	ReadAtt1[0] = embMsgUD_1.Body(1); 
			ReadAtt1[1] = embMsgUD_1.Body(2); 
			ReadAtt1[2] = embMsgUD_1.Body(3); break;
#endif	// PROG_PRM_PCH_L_61

  default : break;
 }
}

extern "C" void ParseUD_2()	 //need make!
{

if(modescan2)
 {
 if(curval2 >= 0)
 {
  emb5StatusFrequScan2.emb5statusfrequscan.level[curval2] = ConvVal( (((unsigned short)embMsgUD_2.Body(2)&0x0F) << 8) + 	embMsgUD_2.Body(1));
 }
 else
 {
  }
  return;
 }		
 if(start2) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[10] = 1; //have power on 2

 switch(embMsgUD_2.Body(0))
 {
  case 0: if(start2)
   { unEmb2TypeVer.emb2TypeVer.signature_hardware[8] = embMsgUD_2.Body(1) & DEVICE_TYPE_MASK; 
   		  Band2 = embMsgUD_2.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever2.emb5statusreciever.status =  embMsgUD_2.Body(2) >> 4;
			emb5StatusReciever2.emb5statusreciever.signalLevel =  ConvVal((((unsigned short)embMsgUD_2.Body(2)&0x0F)  << 8) + 	embMsgUD_2.Body(1));
 		   	emb5StatusReciever2.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_2.Body(3));  //	break;
 		break;	   //for test
  case 22:	emb5RPUState2.emb5rpustate.temp =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.temp_min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.temp_max =  embMsgUD_2.Body(3);
  case 23:	emb5RPUState2.emb5rpustate.u48 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u48min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u48max =  embMsgUD_2.Body(3);
  case 24:	emb5RPUState2.emb5rpustate.u24 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u24min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u24max =  embMsgUD_2.Body(3);
  case 25:	emb5RPUState2.emb5rpustate.u7 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u7min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u7max =  embMsgUD_2.Body(3);
  case 26:	emb5RPUState2.emb5rpustate.u5 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u5min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u5max =  embMsgUD_2.Body(3);
  case 27:	emb5RPUState2.emb5rpustate.u_5 =  embMsgUD_2.Body(1);
			emb5RPUState2.emb5rpustate.u_5min =  embMsgUD_2.Body(2);
			emb5RPUState2.emb5rpustate.u_5max =  embMsgUD_2.Body(3);
#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[8] =  embMsgUD_2.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[10] =  embMsgUD_2.Body(1);	break;
  case 30:	WriteStatus2 = embMsgUD_2.Body(1); break;
  case 31:	ReadStatus2[0] = embMsgUD_2.Body(1); 
			ReadStatus2[1] = embMsgUD_2.Body(2); 
			ReadStatus2[2] = embMsgUD_2.Body(3); break;
  case 32:	ReadAtt2[0] = embMsgUD_2.Body(1); 
			ReadAtt2[1] = embMsgUD_2.Body(2); 
			ReadAtt2[2] = embMsgUD_2.Body(3); break;

#endif	// PROG_PRM_PCH_L_61
  default : break;
 }
}

#ifdef PRM_L_KEEP_FREQ
unsigned long DelayWriteTime;
#endif

unsigned char beforemodulsk;

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
extern "C" void Init_PRM_PCH(void)
{
// return; //t
#ifdef PRM_L_KEEP_FREQ
 DelayWriteTime = 0;
#endif

 //  embMsg485.Init();   //091113


if(!CheckSymbolRate(GetSymbolRate()))
{SetSymbolRate(MAX_SYMBOL_RATE);}

if(!CheckFreqPCh(GetFreqPCh()))
{SetFreqPCh(MAX_FREQPCH2);}

if(!CheckModulSK(GetModulSK()))
{SetModulSK(MODUL7);}


//oadSymbolRate(GetSymbolRate());

/*
if(!CheckSymbolRate(unsigned long rate)
if(!CheckSymbolRate(unsigned long rate)
*/




//#ifdef PROG_PRM_PCH_L
 NeedWriteID = 0;
 test_shift_mode = 0;
//#endif //PROG_PRM_PCH_L


//char any;
 

AsciiInit();
EmbInit(); //my
  time1=0;

  flagRequest=0;
 // serr=0xFF; crc_temp=0;
  i=0;
  time1old=0; time2old=0;
  timerun=0;
  breakflag = 0;
   request1=0; request2=0;
  time3Marker=0; time3BlankTransit=0; time3BlankMod=0;
  time1test=0;
  markerWest=0; markerEast=0; ready_transit=0; ready_mod=0; dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  old_ready_transit=0; old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  delete_msgWest=0; delete_msgEast=0; recieveWest=0; recieveEast=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0; mode5AWest=0; mode5AEast=0; 
  mode5A232E = 0;  //1021
  mode5A485E = 0;  //1021
  mode5A485  = 0;  //1021
  cycle=0;
	ttbb=0;
	mtbb=0;
	count_tr=0;
	count_md=0;
	err_tr=0;
	err_md=0;
	rrr=0;
  	embSerialACT155.Init();
    embTimer.Init(10); // *0,1 ms ���� ���������� ���������� �� �������
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // ����� ������� 1 ��� �� N ������������ �������
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}
	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=0;
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;
 	unEmb2TypeVer.emb2TypeVer.type       = 0x0901;
 	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;  //add suppourt protocol	rs232 from ethernet protocol 888
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();	//was 0
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();	//was 0



for(i=0; i<16; i++)
	{
  		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}

   unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = 1; //temporaru now one channel


   unEmb2TypeVer.emb2TypeVer.signature_software[0] =  GetSymbolRate();
   unEmb2TypeVer.emb2TypeVer.signature_software[1] =  GetSymbolRate() >> 8;
   unEmb2TypeVer.emb2TypeVer.signature_software[2] =  GetSymbolRate() >> 16;
   unEmb2TypeVer.emb2TypeVer.signature_software[3] =  GetSymbolRate() >> 24;
   unEmb2TypeVer.emb2TypeVer.signature_software[4] =  GetFreqPCh();
   unEmb2TypeVer.emb2TypeVer.signature_software[5] =  GetFreqPCh() >> 8;
   unEmb2TypeVer.emb2TypeVer.signature_software[6] =  GetFreqPCh() >> 16;
   unEmb2TypeVer.emb2TypeVer.signature_software[7] =  GetFreqPCh() >> 24;
   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  GetModulSK();


	/*
 	bt = (unsigned char *)(NVRAM_BASE);

	unEmb2TypeVer.emb2TypeVer.signature_software[0] = *bt;
	unEmb2TypeVer.emb2TypeVer.signature_software[1] = *(bt+1);
	unEmb2TypeVer.emb2TypeVer.signature_software[2] = *(bt+2);
	unEmb2TypeVer.emb2TypeVer.signature_software[3] = *(bt+3);
	unEmb2TypeVer.emb2TypeVer.signature_software[4] = *(bt+4);
	unEmb2TypeVer.emb2TypeVer.signature_software[5] = *(bt+5);
	unEmb2TypeVer.emb2TypeVer.signature_software[6] = *(bt+6);
	unEmb2TypeVer.emb2TypeVer.signature_software[7] = *(bt+7);
	unEmb2TypeVer.emb2TypeVer.signature_software[8] = *(bt+8);
	unEmb2TypeVer.emb2TypeVer.signature_software[9] = *(bt+9);
	unEmb2TypeVer.emb2TypeVer.signature_software[10] = *(bt+10);
	unEmb2TypeVer.emb2TypeVer.signature_software[11] = *(bt+11);
	unEmb2TypeVer.emb2TypeVer.signature_software[12] = *(bt+12);
	unEmb2TypeVer.emb2TypeVer.signature_software[13] = *(bt+13);
	unEmb2TypeVer.emb2TypeVer.signature_software[14] = *(bt+14);
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15); 
	*/

//#ifdef PROG_PRM_PCH_L_61
//   unEmb2TypeVer.emb2TypeVer.signature_software[14] = test_shift_mode;
//#endif

 //	embMsgTemp.Init();

//#ifdef PROG_PRM_PCH_S

//#ifndef PROG_PRM_PCH_L
 
//#endif //PROG_PRM_PCH_L
/*
 if(GetTestMode() != 0x8el)   //restart only rtcs
  {

//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();
//   for(long i2 = 0; i2 < 100000; i2++) //test
 LoadSymbolRate(GetSymbolRate());

 LoadDDSN3();

 LoadFreqPCh(GetFreqPCh());
 }
*/

//ok  return;
 beforemodulsk = 0xff; //
 LoadModulSK();

#ifdef 	PROG_PRM_PCH_DEM_XIL

 m_load_xilinx5(3,0); //load xil 3,4 to file 3

#ifdef PROG_PRM_PCH_DEM_XIL_CHN
 m_load_xilinx4(1,0);
#else

 if(GetModulSK() == MODUL7)	 //128qam
 {
    m_load_xilinx4(1,0);
 }
 else
 {
    m_load_xilinx4(2,0);
 }
#endif

#endif // PROG_PRM_PCH_DEM_XIL

}

extern "C" void LoadDDSs(void)
{

//#endif //PROG_PRM_PCH_L
 if(GetTestMode() != 0x8el)   //restart only rtcs
  {

//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();
//   for(long i2 = 0; i2 < 100000; i2++) //test
 LoadSymbolRate(GetSymbolRate());

 LoadDDSN3();

 LoadFreqPCh(GetFreqPCh());


 }



}

extern "C" void ClearMod()
{
while(embSerialACT155.UsedMod())
		{
   			 embSerialACT155.GetMod();
		} 
}

extern "C" void ClearTransit()
{
while(embSerialACT155.UsedTransit())
		{
   		   embSerialACT155.GetTransit();
		} 
}





#ifdef PROG_PRM_PCH_C

extern "C" void CheckPower()
{
unsigned char tmppp;
   	 tmppp =  inportb(LED_PORT);
	if(!(inportb(POWER_PORT) & ALL_CH_POWER_ON))
	{
     tmppp &= ALARM_POWER;
	 }
	else
	{
     tmppp |= NO_ALARM_POWER;
	}

   if(!(inportb(POWER_PORT) & ( CH1_MASK + CH2_MASK + CH3_MASK)))
   {
  	  tmppp |= NO_ALARM_INPUT + NO_ALARM_PM;
    }
 	 outportb(LED_PORT, tmppp);
}

#endif


extern "C" void ScanState()
{
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 volatile unsigned int status;

 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 16, AT91RM9200_PIO_PERIPHERAL_IO, 0);  //lock
 _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 0);  //freq
  status = pio_ptr->PDSR; //wait line init hier zero
     if(!(status & MASK_BIT_16))
      { 
	  unEmb2TypeVer.emb2TypeVer.signature_software[9] |=  MASK_BIT_0;
      }
	  else
	  {
	  unEmb2TypeVer.emb2TypeVer.signature_software[9] &=  ~(MASK_BIT_0);
	  }

     if(!(status & MASK_BIT_17))
      { 
	  unEmb2TypeVer.emb2TypeVer.signature_software[9] |=  MASK_BIT_1;
      }
	  else
	  {
	  unEmb2TypeVer.emb2TypeVer.signature_software[9] &=  ~(MASK_BIT_1);
	  }



}

#define SCAN_TIME_PERIOD (250)

extern "C" void PRM_PCH()
 {
//ok  return;


  static unsigned long timescan;
	   if(GetNeedWriteDevId())
		   {
	  // 	   printfp("\n\r Write!!"); //t
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }
	 if( (time1 - timescan) > SCAN_TIME_PERIOD)
	 {
	   	timescan = time1;
  		ScanState();
	 }
return;
 
}

#ifdef PROG_PRM_PCH_N

extern "C" void Remote_PRM_PCH(void)
{
 #include checkremoteprm_pch.inc
 #include answerprm_pch.inc
}

#endif //PROG_PRM_PCH_N





//}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : none
* Comments         :
*    This routine is used to port embisr to be called from timer isr
*END*----------------------------------------------------------------------*/

extern "C" void time_notify_core(void)	// called frequency = 1 ms
 {
 //hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;
   	TimerCounter1 ++;
 	timeres++; 
  } 

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq1(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq1
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq1()
{
}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{
#ifdef IncEmbSerialMD34AVT
  embSerialACT155.IsrXX();
#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
   my_int_enable_irq0();
}
//#ifdef PROG_BMD155

//__________________________________________________________________________________
struct EmbHittite
{
	unsigned bit0: 1;
	unsigned bit1: 1;
	unsigned bit2: 1;
	unsigned bit3: 1;
	unsigned bit4: 1;
	unsigned bit5: 1;
	unsigned bit6: 1;
	unsigned bit7: 1;
};

union UnEmbHittite
{
	EmbHittite eh;
	unsigned char b;
};

typedef	unsigned long long __int64;


//void CPRmP4Dlg::Formula8(unsigned long f)




/*
unsigned char *	Formula8(unsigned long f)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_in=f*10;
	unsigned long f_tm;
 //	unsigned long f_sint;
 //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];
	UnEmbHittite ueh;
	ueh.b=0;
////////////// DDS /////////////////
		double Fdds0 = 190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
 //		double Fdds_fl;
		unsigned char N;
////////////////////////////////////
	double dk = 2.980232239;
//	double temp_dbl;
	if((f_in>=1770000)&&(f_in<2650000))
	{
		b[0]=6;
		b[1]=0;

		if((f_in>=1770000)&&(f_in<1902500)) b[1]=0x01;
		if((f_in>=1902500)&&(f_in<2042500)) b[1]=0x04;	
		if((f_in>=2042500)&&(f_in<2177500)) b[1]=0x10;		
		if((f_in>=2177500)&&(f_in<2307500)) b[1]=0x08;		
		if((f_in>=2307500)&&(f_in<2650000)) b[1]=0x02;

		if(f_in<2175000)
		{
			f_tm = f_in - 548000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[2] = 0x01;	 // Eiiiooaoi? K
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[4] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[3] = ueh.b;	
			b[5]= 0x00;
			/// DDS
			df = Fdds/Fbase_dds;
//			__int64 u64base = 281474976710656;
		   __int64 u64base = (__int64)(2814749l);
				 u64base *=    (__int64)(100000000l);
				 u64base +=    (__int64)(76710656l);




			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[6] = (high>>8)&0xFF;
			b[7] = high&0xFF;
			b[8] = (low>>24)&0xFF;
			b[9] = (low>>16)&0xFF;
			b[10] = (low>>8)&0xFF;
			b[11] = low&0xFF;
		}
		else
		{
			f_tm = f_in - 1048000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[2] = 0x02;	 // Eiiiooaoi? K
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[4] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[3] = ueh.b;	
			b[5]= 0x00;
			/// DDS
			df = Fdds/Fbase_dds;
//			__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64)(76710656l);



			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[6] = (high>>8)&0xFF;
			b[7] = high&0xFF;
			b[8] = (low>>24)&0xFF;
			b[9] = (low>>16)&0xFF;
			b[10] = (low>>8)&0xFF;
			b[11] = low&0xFF;
		}
	}

	if((f_in<1770000))
	{
		b[0]=6;
		b[1]=0;

		if((f_in>=260000)&&(f_in<1050000)) b[1]=0x01;
		if((f_in>=1050000)&&(f_in<1770000)) b[1]=0x02;	

		if(f_in<1050000)
		{
			f_tm = f_in + 1442000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[2] = 0x01;	 // Eiiiooaoi? K
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[4] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[3] = ueh.b;	
			b[5]= 0x00;
			/// DDS
			df = Fdds/Fbase_dds;
//			__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64)(76710656l);


			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[6] = (high>>8)&0xFF;
			b[7] = high&0xFF;
			b[8] = (low>>24)&0xFF;
			b[9] = (low>>16)&0xFF;
			b[10] = (low>>8)&0xFF;
			b[11] = low&0xFF;
		}
		else
		{
			f_tm = f_in + 842000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[2] = 0x02;	 // Eiiiooaoi? K
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[4] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[3] = ueh.b;	
			b[5]= 0x00;
			/// DDS
			df = Fdds/Fbase_dds;
//			__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[6] = (high>>8)&0xFF;
			b[7] = high&0xFF;
			b[8] = (low>>24)&0xFF;
			b[9] = (low>>16)&0xFF;
			b[10] = (low>>8)&0xFF;
			b[11] = low&0xFF;
		}
	}
	if((f_in>=2650000))
	{
		b[0]=6;

		if(f_in<3000000)
		{
			f_tm = f_in - 518000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[1] = 0x02;	 // Eiiiooaoi?
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[3] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[2] = ueh.b;	
			/// DDS
			df = Fdds/Fbase_dds;
 //			__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[4] = (high>>8)&0xFF;
			b[5] = high&0xFF;
			b[6] = (low>>24)&0xFF;
			b[7] = (low>>16)&0xFF;
			b[8] = (low>>8)&0xFF;
			b[9] = low&0xFF;
		}
		else
		{
			if((f_in>3000000)&&(f_in<3500000))
			{
				f_tm = f_in - 848000;//1050000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[1] = 0x02;	 // Eiiiooaoi?
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[3] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[2] = ueh.b;	
				/// DDS
				df = Fdds/Fbase_dds;
//				__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[4] = (high>>8)&0xFF;
				b[5] = high&0xFF;
				b[6] = (low>>24)&0xFF;
				b[7] = (low>>16)&0xFF;
				b[8] = (low>>8)&0xFF;
				b[9] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//1050000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[1] = 0x02;	 // Eiiiooaoi?
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[3] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[2] = ueh.b;	
				/// DDS
				df = Fdds/Fbase_dds;
 //				__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);

				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[4] = (high>>8)&0xFF;
				b[5] = high&0xFF;
				b[6] = (low>>24)&0xFF;
				b[7] = (low>>16)&0xFF;
				b[8] = (low>>8)&0xFF;
				b[9] = low&0xFF;
			}
		}
	}
 return b;
}

*/
/*
unsigned char *Formula9(unsigned long f, unsigned char m_band)
{


 //if(GetTestMode() == 0x5D)
// {
//   printf("\n\r mband = %d", m_band);
//  printEthLongHex(m_band);
// }

	unsigned char ver = (m_band>>2)&0x3F;

// if(GetTestMode() == 0x5D)
// {
//   printf("\n\r mband = %d", m_band);
//  printEthLongHex(ver);
// }

	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_in=f*10;
	unsigned long f_tm;
//	unsigned long f_sint;
 //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];
	UnEmbHittite ueh;
	ueh.b=0;
////////////// DDS /////////////////
		double Fdds0 = 190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
 //		double Fdds_fl;
		unsigned char N;
////////////////////////////////////
	double dk = 2.980232239;
//	double temp_dbl;
	if((f_in>=1770000)&&(f_in<2650000))
	{
	  if(ver==4)
	  {
			unsigned char att= 0x00;

			if((f_in>=1770000)&&(f_in<1790000)) att=1;
			if((f_in>=1790000)&&(f_in<1830000)) att=2;
			if((f_in>=1830000)&&(f_in<1870000)) att=3;
			if((f_in>=1870000)&&(f_in<1910000)) att=4;
			if((f_in>=1910000)&&(f_in<1930000)) att=5;
			if((f_in>=1930000)&&(f_in<2080000)) att=6;	 
			if((f_in>=2080000)&&(f_in<2120000)) att=2;	
			if((f_in>=2120000)&&(f_in<2160000)) att=3;	
			if((f_in>=2160000)&&(f_in<2180000)) att=4;	
			if((f_in>=2180000)&&(f_in<2250000)) att=5;
			if((f_in>=2250000)&&(f_in<2340000)) att=7;
			if((f_in>=2340000)&&(f_in<2360000)) att=5;
			if((f_in>=2360000)&&(f_in<2380000)) att=7;
			if((f_in>=2380000)&&(f_in<2400000)) att=5;
			if((f_in>=2400000)&&(f_in<2430000)) att=6;
			if((f_in>=2430000)&&(f_in<2450000)) att=4;
			if((f_in>=2450000)&&(f_in<2460000)) att=6;
			if((f_in>=2460000)&&(f_in<2470000)) att=4;
			if((f_in>=2470000)&&(f_in<2490000)) att=3;
			if((f_in>=2490000)&&(f_in<2510000)) att=4;
			///
			if((f_in>=2530000)&&(f_in<2540000)) att=1;
			if((f_in>=2540000)&&(f_in<2560000)) att=3;
			if((f_in>=2560000)&&(f_in<2590000)) att=1;
			if((f_in>=2590000)&&(f_in<2630000)) att=3;
			if((f_in>=2630000)&&(f_in<2650000)) att=4;	  
														
			b[0]=7;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
			if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
			if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
			if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
			if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2160000)
			{
				f_tm = f_in - 568000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2; 
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*2;
				b[2] = 0x02; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1068000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2;  
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*2;
				b[2] = 0x01; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}

	  if(ver==3)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1850000)) att=0x40;
			if((f_in>=1850000)&&(f_in<2040000)) att=0x50;
			if((f_in>=2040000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2200000)) att=0x50;
			if((f_in>=2200000)&&(f_in<2400000)) att=0x60;
			if((f_in>=2400000)&&(f_in<2450000)) att=0x50;	 
			if((f_in>=2450000)&&(f_in<2470000)) att=0x40;	
			if((f_in>=2470000)&&(f_in<2500000)) att=0x30;	
			if((f_in>=2500000)&&(f_in<2510000)) att=0x20;	
			if((f_in>=2510000)&&(f_in<2650000)) att=0x10;
															
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}

	  if(ver==2)
	  {

			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2030000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2400000)) att=0x30;
			if((f_in>=2400000)&&(f_in<2470000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	  if((ver==1)||(ver==0))
	  {
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2300000)) att=0x30;
			if((f_in>=2300000)&&(f_in<2400000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}

	if((f_in<1770000))
	{
	  if(ver==4)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<420000))   att=10;
			if((f_in>=420000)&&(f_in<450000))   att=9;
			if((f_in>=450000)&&(f_in<480000))   att=8;
			if((f_in>=480000)&&(f_in<580000))   att=7;
			if((f_in>=580000)&&(f_in<620000))   att=8;
			if((f_in>=620000)&&(f_in<650000))   att=9;
			if((f_in>=650000)&&(f_in<710000))   att=10;
			if((f_in>=710000)&&(f_in<750000))   att=9;
			if((f_in>=750000)&&(f_in<780000))   att=8;
			if((f_in>=780000)&&(f_in<800000))   att=7;
			if((f_in>=800000)&&(f_in<840000))   att=6;
			if((f_in>=840000)&&(f_in<970000))   att=5;
			if((f_in>=970000)&&(f_in<1000000))  att=4;
			if((f_in>=1000000)&&(f_in<1020000)) att=3;
			if((f_in>=1020000)&&(f_in<1030000)) att=4;
			if((f_in>=1030000)&&(f_in<1060000)) att=5;
			if((f_in>=1060000)&&(f_in<1090000)) att=5;
			if((f_in>=1090000)&&(f_in<1120000)) att=5;
			if((f_in>=1120000)&&(f_in<1210000)) att=4;
			if((f_in>=1210000)&&(f_in<1280000)) att=3;
			if((f_in>=1280000)&&(f_in<1300000)) att=4;
			if((f_in>=1300000)&&(f_in<1340000)) att=5;
			if((f_in>=1340000)&&(f_in<1390000)) att=6;
			if((f_in>=1390000)&&(f_in<1490000)) att=7;
			if((f_in>=1490000)&&(f_in<1640000)) att=6;
			if((f_in>=1640000)&&(f_in<1660000)) att=5;
			if((f_in>=1660000)&&(f_in<1700000)) att=3;
			if((f_in>=1700000)&&(f_in<1770000)) att=2;	  

			b[0]=7;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x02;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x01;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1452000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*4;
				b[2] = 0x01; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 692000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*4;
				b[2] = 0x02; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
	  }

	  if(ver==2)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x10;
			if((f_in>=1020000)&&(f_in<1160000)) att=0x10;
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }

	  if(ver==1)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x40;
			if((f_in>=560000)&&(f_in<740000)) att=0x30;
			if((f_in>=740000)&&(f_in<810000)) att=0x40;
			if((f_in>=810000)&&(f_in<830000)) att=0x30;	
			if((f_in>=830000)&&(f_in<880000)) att=0x20;	
			if((f_in>=880000)&&(f_in<960000)) att=0x30;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x30;
			if((f_in>=1110000)&&(f_in<1260000)) att=0x10;
			if((f_in>=1260000)&&(f_in<1460000)) att=0x20;	
			if((f_in>=1460000)&&(f_in<=1760000)) att=0x20;	
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }

	  if(ver==0)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x50;
			if((f_in>=560000)&&(f_in<660000)) att=0x40;
			if((f_in>=660000)&&(f_in<760000)) att=0x30;
			if((f_in>=760000)&&(f_in<910000)) att=0x40;	
			if((f_in>=910000)&&(f_in<960000)) att=0x50;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x40;	
			if((f_in>=1110000)&&(f_in<1610000)) att=0x30;	
			if((f_in>=1610000)&&(f_in<1650000)) att=0x20;	
			if((f_in>=1650000)&&(f_in<1760000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1050000)) b[1]=0x01;
			if((f_in>=1050000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1050000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }
	}
	if((f_in>=2650000)&&(f_in<40150000))
	{
		if(ver==4)
		{
			unsigned char att= 0x00;
			*/
			/*
			if((f_in>=2650000)&&(f_in<2900000)) att=0x60;	
			if((f_in>=2900000)&&(f_in<3200000)) att=0x70;
			if((f_in>=3200000)&&(f_in<3350000)) att=0x80;
			if((f_in>=3350000)&&(f_in<3700000)) att=0x70;
			if((f_in>=3700000)&&(f_in<3800000)) att=0x60;
			if((f_in>=3800000)&&(f_in<3850000)) att=0x50;
			if((f_in>=3850000)&&(f_in<3900000)) att=0x40;
			if((f_in>=3900000)&&(f_in<3950000)) att=0x30;
			if((f_in>=3950000)&&(f_in<4000000)) att=0x20;
			if(f_in>=4000000) att=0x10;	
			*/
		  /*
		   	if((f_in>=2650000)&&(f_in<3000000)) att=10;	
			if((f_in>=3000000)&&(f_in<3060000)) att=9;
			if((f_in>=3060000)&&(f_in<3190000)) att=8;
			if((f_in>=3190000)&&(f_in<3280000)) att=7;
			if((f_in>=3280000)&&(f_in<3350000)) att=6;
			if((f_in>=3350000)&&(f_in<3470000)) att=5;
			if((f_in>=3470000)&&(f_in<3540000)) att=4;
			if((f_in>=3540000)&&(f_in<3590000)) att=3;
			if((f_in>=3590000)&&(f_in<3710000)) att=2;
			if(f_in>=3710000) att=0;	  
				
				
			b[0]=7;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2790000)) b[1]=0x02;
			if((f_in>=2790000)&&(f_in<2940000)) b[1]=0x20;	
			if((f_in>=2940000)&&(f_in<3100000)) b[1]=0x01;		
			if((f_in>=3100000)&&(f_in<3265000)) b[1]=0x10;		
			if((f_in>=3265000)&&(f_in<3440000)) b[1]=0x40;
			if((f_in>=3440000)&&(f_in<3620000)) b[1]=0x80;		
			if((f_in>=3620000)&&(f_in<3810000)) b[1]=0x04;		
			if((f_in>=3810000)&&(f_in<4010000)) b[1]=0x08;
			
			if(f_in<3310000)//<3000000)
			{
				f_tm = f_in - 828000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*4;
				b[2] = 0x03; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;

			}
			else
			{
				f_tm = f_in - 1588000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*4;
				b[2] = 0x04; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}

		if(ver!=4)
		{
			unsigned char att= 0x00;
			
			//		if((f_in>=3000000)&&(f_in<3200000)) att=0x30;
			if((f_in>=2650000)&&(f_in<2900000)) att=0x60;	
			if((f_in>=2900000)&&(f_in<3200000)) att=0x70;
			if((f_in>=3200000)&&(f_in<3350000)) att=0x80;
			if((f_in>=3350000)&&(f_in<3700000)) att=0x70;
			if((f_in>=3700000)&&(f_in<3800000)) att=0x60;
			if((f_in>=3800000)&&(f_in<3850000)) att=0x50;
			if((f_in>=3850000)&&(f_in<3900000)) att=0x40;
			if((f_in>=3900000)&&(f_in<3950000)) att=0x30;
			if((f_in>=3950000)&&(f_in<4000000)) att=0x20;
			if(f_in>=4000000) att=0x10;	
				
				
				b[0]=6;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2750000)) b[1]=0x01;
			if((f_in>=2750000)&&(f_in<2870000)) b[1]=0x02;	
			if((f_in>=2870000)&&(f_in<3010000)) b[1]=0x04;		
			if((f_in>=3010000)&&(f_in<3170000)) b[1]=0x08;		
			if((f_in>=3170000)&&(f_in<3350000)) b[1]=0x10;
			if((f_in>=3350000)&&(f_in<3550000)) b[1]=0x20;		
			if((f_in>=3550000)&&(f_in<3770000)) b[1]=0x40;		
			if((f_in>=3770000)&&(f_in<4010000)) b[1]=0x80;
			
			if(f_in<3200000)//<3000000)
			{
				f_tm = f_in - 518000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x04+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//				__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}
	if((f_in>=4010000))
	{
//	  if(ver==4)
	  {
//			double Fdds0 = 190000000.0; // ��������������� ���������� ��� 4 ������ 
			unsigned char att= 0x00;
															
			b[0]=7;
			b[1]=0;
			
			if(f_in<4800000)
			{
				f_tm = f_in - 568000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // ����������� ��� ����������� � 2 ����
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*8;
	  //100923			b[2] = 0x01; // Commut K
				b[2] = 0x02; // Commut K		//100923

				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1068000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // ����������� ��� ����������� � 2 ����
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds*8;
	//100923			b[2] = 0x02; // Commut K
				b[2] = 0x01; // Commut K  //100923
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
	}
 return b;
}
  */
#include "formula9.c"
 /*	 

unsigned char *Formula8(unsigned long f, unsigned char m_band)
{


 //if(GetTestMode() == 0x5D)
// {
//   printf("\n\r mband = %d", m_band);
//  printEthLongHex(m_band);
// }

	unsigned char ver = (m_band>>2)&0x3F;

// if(GetTestMode() == 0x5D)
// {
//   printf("\n\r mband = %d", m_band);
//  printEthLongHex(ver);
// }

	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_in=f*10;
	unsigned long f_tm;
//	unsigned long f_sint;
 //	unsigned long r03;
 //	unsigned long r04;
	static unsigned char b[16];
	UnEmbHittite ueh;
	ueh.b=0;
////////////// DDS /////////////////
		double Fdds0 = 190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
 //		double Fdds_fl;
		unsigned char N;
////////////////////////////////////
	double dk = 2.980232239;
//	double temp_dbl;
	if((f_in>=1770000)&&(f_in<2650000))
	{
	  if(ver==3)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1850000)) att=0x40;
			if((f_in>=1850000)&&(f_in<2040000)) att=0x50;
			if((f_in>=2040000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2200000)) att=0x50;
			if((f_in>=2200000)&&(f_in<2400000)) att=0x60;
			if((f_in>=2400000)&&(f_in<2450000)) att=0x50;	 
			if((f_in>=2450000)&&(f_in<2470000)) att=0x40;	
			if((f_in>=2470000)&&(f_in<2500000)) att=0x30;	
			if((f_in>=2500000)&&(f_in<2510000)) att=0x20;	
			if((f_in>=2510000)&&(f_in<2650000)) att=0x10;
															
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}

	  if(ver==2)
	  {

			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2030000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2400000)) att=0x30;
			if((f_in>=2400000)&&(f_in<2470000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	  if((ver==1)||(ver==0))
	  {
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2300000)) att=0x30;
			if((f_in>=2300000)&&(f_in<2400000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}

	if((f_in<1770000))
	{
	  if(ver==2)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x10;
			if((f_in>=1020000)&&(f_in<1160000)) att=0x10;
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }

	  if(ver==1)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x40;
			if((f_in>=560000)&&(f_in<740000)) att=0x30;
			if((f_in>=740000)&&(f_in<810000)) att=0x40;
			if((f_in>=810000)&&(f_in<830000)) att=0x30;	
			if((f_in>=830000)&&(f_in<880000)) att=0x20;	
			if((f_in>=880000)&&(f_in<960000)) att=0x30;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x30;
			if((f_in>=1110000)&&(f_in<1260000)) att=0x10;
			if((f_in>=1260000)&&(f_in<1460000)) att=0x20;	
			if((f_in>=1460000)&&(f_in<=1760000)) att=0x20;	
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }

	  if(ver==0)
	  {
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x50;
			if((f_in>=560000)&&(f_in<660000)) att=0x40;
			if((f_in>=660000)&&(f_in<760000)) att=0x30;
			if((f_in>=760000)&&(f_in<910000)) att=0x40;	
			if((f_in>=910000)&&(f_in<960000)) att=0x50;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x40;	
			if((f_in>=1110000)&&(f_in<1610000)) att=0x30;	
			if((f_in>=1610000)&&(f_in<1650000)) att=0x20;	
			if((f_in>=1650000)&&(f_in<1760000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1050000)) b[1]=0x01;
			if((f_in>=1050000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1050000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
	  }
	}
	if((f_in>=2650000))
	{
		unsigned char att= 0x00;

//		if((f_in>=3000000)&&(f_in<3200000)) att=0x30;
		if((f_in>=2650000)&&(f_in<2900000)) att=0x60;	
		if((f_in>=2900000)&&(f_in<3200000)) att=0x70;
		if((f_in>=3200000)&&(f_in<3350000)) att=0x80;
		if((f_in>=3350000)&&(f_in<3700000)) att=0x70;
		if((f_in>=3700000)&&(f_in<3800000)) att=0x60;
		if((f_in>=3800000)&&(f_in<3850000)) att=0x50;
		if((f_in>=3850000)&&(f_in<3900000)) att=0x40;
		if((f_in>=3900000)&&(f_in<3950000)) att=0x30;
		if((f_in>=3950000)&&(f_in<4000000)) att=0x20;
		if(f_in>=4000000) att=0x10;	


		b[0]=6;
		b[1]=0;

		if((f_in>=2650000)&&(f_in<2750000)) b[1]=0x01;
		if((f_in>=2750000)&&(f_in<2870000)) b[1]=0x02;	
		if((f_in>=2870000)&&(f_in<3010000)) b[1]=0x04;		
		if((f_in>=3010000)&&(f_in<3170000)) b[1]=0x08;		
		if((f_in>=3170000)&&(f_in<3350000)) b[1]=0x10;
		if((f_in>=3350000)&&(f_in<3550000)) b[1]=0x20;		
		if((f_in>=3550000)&&(f_in<3770000)) b[1]=0x40;		
		if((f_in>=3770000)&&(f_in<4010000)) b[1]=0x80;

		if(f_in<3200000)//<3000000)
		{
			f_tm = f_in - 518000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[2] = 0x04+att;	 // Eiiiooaoi? K
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[4] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[3] = ueh.b;	
			b[5]= 0x00;
			/// DDS
			df = Fdds/Fbase_dds;
 //			__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[6] = (high>>8)&0xFF;
			b[7] = high&0xFF;
			b[8] = (low>>24)&0xFF;
			b[9] = (low>>16)&0xFF;
			b[10] = (low>>8)&0xFF;
			b[11] = low&0xFF;
		}
		else
		{
			if((f_in>=3000000)&&(f_in<3200000))
			{
				f_tm = f_in - 848000;//1050000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
//				__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{		  
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
//				__int64 u64base = 281474976710656;
  		__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
//			}
		}
	}
 return b;
}

 */

/*
unsigned char * Formula7(unsigned long f)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_in=f*10;
	unsigned long f_tm;
	unsigned long f_sint;
	unsigned long r03;
	unsigned long r04;
	static unsigned char b[12];
	UnEmbHittite ueh;
	ueh.b=0;
////////////// DDS /////////////////
		double Fdds0 = 190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
  //		double Fdds_fl;
		unsigned char N;
////////////////////////////////////
	double dk = 2.980232239;
	double temp_dbl;
	if((f_in>=1770000)&&(f_in<2650000))
	{
		b[0]=1;	
		if(f_in<2200000)
		{
			f_tm = f_in - 548000;//548000;
			f_sint = f_tm/2;
			r03=f_sint/5000;
			temp_dbl=f_sint%5000;
			r04=(unsigned)(temp_dbl*10000)/dk;
			b[1] = 0x02;//0x02;	
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			b[3] = r03&0x7F;
			ueh.eh.bit0 = (r03&0x80)>>7;
			b[4] = r04&0x7F;
			ueh.eh.bit1 = (r04&0x80)>>7;
			b[5] = (r04>>8)&0x7F;
			ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
			b[6] = (r04>>16)&0x7F;
			ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
			b[2] = ueh.b;	
		}
		else
		{
			if((f_in>=2100000)&&(f_in<2340000))
			{
				f_tm = f_in - 1048000;//1050000;
				f_sint = f_tm/2;			
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0x01;	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
			}
			else
			{	  
				f_tm = f_in - 1048000;//848000;
				f_sint = f_tm/2;			
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0x01; //0x04	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
		 //	}
		}
	}
	if((f_in>=2650000))
	{
		b[0]=5;

		if(f_in<3000000)
		{
			f_tm = f_in - 518000;//550000;
			double Ftemp = f_tm * 10000.0;
			Fsint = (f_tm * 10000.0)/2; // *2 yoi R
			N = Fsint/Fdds0;  
			Fint = N*Fdds0;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/N;
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = N*Fdds;
			b[1] = 0x02;	 // Eiiiooaoi?
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			ueh.eh.bit3 = 0;
			ueh.eh.bit2 = 0;
			ueh.eh.bit1 = 0;
			b[3] = N&0x7F;
			ueh.eh.bit0 = (N&0x80)>>7;
			b[2] = ueh.b;	
			/// DDS
			df = Fdds/Fbase_dds;
	//t		__int64 u64base =   (__int64)(281474976710656l);
			  __int64 u64base = (__int64)(2814749l);
				 u64base *=    (__int64)(100000000l);
				 u64base +=    (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[4] = (high>>8)&0xFF;
			b[5] = high&0xFF;
			b[6] = (low>>24)&0xFF;
			b[7] = (low>>16)&0xFF;
			b[8] = (low>>8)&0xFF;
			b[9] = low&0xFF;
		}
		else
		{
				if((f_in>=3000000)&&(f_in<3200000))
				{
				f_tm = f_in - 848000;//1050000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[1] = 0x04;	 // Eiiiooaoi?
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[3] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[2] = ueh.b;	
				/// DDS
				df = Fdds/Fbase_dds;
 //				__int64 u64base = 281474976710656;
			  __int64 u64base = (__int64)2814749l;
			   u64base *= (__int64)100000000l;
			   u64base += (__int64)76710656l;


				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[4] = (high>>8)&0xFF;
				b[5] = high&0xFF;
				b[6] = (low>>24)&0xFF;
				b[7] = (low>>16)&0xFF;
				b[8] = (low>>8)&0xFF;
				b[9] = low&0xFF;
				}
				else
				{
				
				f_tm = f_in - 1048000;//1050000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				Ftemp = N*Fdds;
				b[1] = 0x01;	 // Eiiiooaoi?
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[3] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[2] = ueh.b;	
				/// DDS
				df = Fdds/Fbase_dds;
  //				__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)2814749l;
				 u64base *=  (__int64)100000000l;
				 u64base +=  (__int64)76710656l;

				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[4] = (high>>8)&0xFF;
				b[5] = high&0xFF;
				b[6] = (low>>24)&0xFF;
				b[7] = (low>>16)&0xFF;
				b[8] = (low>>8)&0xFF;
				b[9] = low&0xFF;
			}
		}
	}

	if((f_in<1770000))
	{
		b[0]=3;
		if((f_in>=1150000)&&(f_in<1770000))
		{
			
			f_tm = f_in - 350000;//550000;
			f_sint = f_tm/2;
			r03=f_sint/5000;
			temp_dbl=f_sint%5000;
			r04=(unsigned)(temp_dbl*10000)/dk;
			b[1] = 0xF3;	
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			b[3] = r03&0x7F;
			ueh.eh.bit0 = (r03&0x80)>>7;
			b[4] = r04&0x7F;
			ueh.eh.bit1 = (r04&0x80)>>7;
			b[5] = (r04>>8)&0x7F;
			ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
			b[6] = (r04>>16)&0x7F;
			ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
			b[2] = ueh.b;	
		}
		else
		{
			if((f_in>=800000)&&(f_in<1150000))
			{
				
				f_tm = f_in - 350000;//550000;
				f_sint = f_tm;
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0xF6;	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
			}
			else
			{
				if((f_in>=600000)&&(f_in<800000))
				{
					
					f_tm = f_in - 200000;//550000;
					f_sint = f_tm;
					r03=f_sint/5000;
					temp_dbl=f_sint%5000;
					r04=(unsigned)(temp_dbl*10000)/dk;
					b[1] = 0xF8;	
					ueh.eh.bit7 = 1;
					ueh.eh.bit6 = 0;
					ueh.eh.bit5 = 0;
					ueh.eh.bit4 = 0;
					b[3] = r03&0x7F;
					ueh.eh.bit0 = (r03&0x80)>>7;
					b[4] = r04&0x7F;
					ueh.eh.bit1 = (r04&0x80)>>7;
					b[5] = (r04>>8)&0x7F;
					ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
					b[6] = (r04>>16)&0x7F;
					ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
					b[2] = ueh.b;	
				}
				else // if((f_in>260000)&&(f_in<600000))
				{
					f_tm = f_in + 200000;//550000;
					f_sint = f_tm;
					r03=f_sint/5000;
					temp_dbl=f_sint%5000;
					r04=(unsigned)(temp_dbl*10000)/dk;
					b[1] = 0xFE;	
					ueh.eh.bit7 = 1;
					ueh.eh.bit6 = 0;
					ueh.eh.bit5 = 0;
					ueh.eh.bit4 = 0;
					b[3] = r03&0x7F;
					ueh.eh.bit0 = (r03&0x80)>>7;
					b[4] = r04&0x7F;
					ueh.eh.bit1 = (r04&0x80)>>7;
					b[5] = (r04>>8)&0x7F;
					ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
					b[6] = (r04>>16)&0x7F;
					ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
					b[2] = ueh.b;	
				}
			}
		}
	}
 return b;
}

  */
/*
unsigned char * Formula6(unsigned long f)
{
	unsigned long f_in=f*10;
	unsigned long f_tm;
	unsigned long f_sint;
	unsigned long r03;
	unsigned long r04;
	static unsigned char b[8];
	UnEmbHittite ueh;
	ueh.b=0;

	double dk = 2.980232239;
	double temp_dbl;
	if((f_in>=1770000)&&(f_in<=2650000))
	{
		b[0]=1;	
		if(f_in<1970000)
		{
			f_tm = f_in - 548000;//550000;
			f_sint = f_tm/2;
			r03=f_sint/5000;
			temp_dbl=f_sint%5000;
			r04=(unsigned)(temp_dbl*10000)/dk;
			b[1] = 0x02;	
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			b[3] = r03&0x7F;
			ueh.eh.bit0 = (r03&0x80)>>7;
			b[4] = r04&0x7F;
			ueh.eh.bit1 = (r04&0x80)>>7;
			b[5] = (r04>>8)&0x7F;
			ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
			b[6] = (r04>>16)&0x7F;
			ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
			b[2] = ueh.b;	
		}
		else
		{
			if((f_in>1970000)&&(f_in<2340000))
			{
				f_tm = f_in - 848000;//1050000;
				f_sint = f_tm/2;			
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0x04;	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
			}
			else
			{
				f_tm = f_in - 1048000;//1050000;
				f_sint = f_tm/2;			
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0x01;	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
			}
		}
	}
	if((f_in>2650000))
	{
		b[0]=2;
			f_tm = f_in - 1508000;
			f_sint = f_tm/4;
			r03=f_sint/5000;
			temp_dbl=f_sint%5000;
			r04=(unsigned)(temp_dbl*10000)/dk;
			b[1] = 0x02;	
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			b[3] = r03&0x7F;
			ueh.eh.bit0 = (r03&0x80)>>7;
			b[4] = r04&0x7F;
			ueh.eh.bit1 = (r04&0x80)>>7;
			b[5] = (r04>>8)&0x7F;
			ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
			b[6] = (r04>>16)&0x7F;
			ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
			b[2] = ueh.b;	
	}

	if((f_in<1770000))
	{
		b[0]=3;
		if((f_in>1150000)&&(f_in<1770000))
		{
			
			f_tm = f_in - 350000;//550000;
			f_sint = f_tm/2;
			r03=f_sint/5000;
			temp_dbl=f_sint%5000;
			r04=(unsigned)(temp_dbl*10000)/dk;
			if(f_in<1450000) b[1] = 0x00;	
			else  b[1] = 0x20;	
			ueh.eh.bit7 = 1;
			ueh.eh.bit6 = 0;
			ueh.eh.bit5 = 0;
			ueh.eh.bit4 = 0;
			b[3] = r03&0x7F;
			ueh.eh.bit0 = (r03&0x80)>>7;
			b[4] = r04&0x7F;
			ueh.eh.bit1 = (r04&0x80)>>7;
			b[5] = (r04>>8)&0x7F;
			ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
			b[6] = (r04>>16)&0x7F;
			ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
			b[2] = ueh.b;	
		}
		else
		{
			if((f_in>800000)&&(f_in<1150000))
			{
				
				f_tm = f_in - 350000;//550000;
				f_sint = f_tm;
				r03=f_sint/5000;
				temp_dbl=f_sint%5000;
				r04=(unsigned)(temp_dbl*10000)/dk;
				b[1] = 0x02;	
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				b[3] = r03&0x7F;
				ueh.eh.bit0 = (r03&0x80)>>7;
				b[4] = r04&0x7F;
				ueh.eh.bit1 = (r04&0x80)>>7;
				b[5] = (r04>>8)&0x7F;
				ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
				b[6] = (r04>>16)&0x7F;
				ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
				b[2] = ueh.b;	
			}
			else
			{
				if((f_in>600000)&&(f_in<800000))
				{
					
					f_tm = f_in - 200000;//550000;
					f_sint = f_tm;
					r03=f_sint/5000;
					temp_dbl=f_sint%5000;
					r04=(unsigned)(temp_dbl*10000)/dk;
					b[1] = 0x12;	
					ueh.eh.bit7 = 1;
					ueh.eh.bit6 = 0;
					ueh.eh.bit5 = 0;
					ueh.eh.bit4 = 0;
					b[3] = r03&0x7F;
					ueh.eh.bit0 = (r03&0x80)>>7;
					b[4] = r04&0x7F;
					ueh.eh.bit1 = (r04&0x80)>>7;
					b[5] = (r04>>8)&0x7F;
					ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
					b[6] = (r04>>16)&0x7F;
					ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
					b[2] = ueh.b;	
				}
				else // if((f_in>260000)&&(f_in<600000))
				{
					f_tm = f_in + 200000;//550000;
					f_sint = f_tm;
					r03=f_sint/5000;
					temp_dbl=f_sint%5000;
					r04=(unsigned)(temp_dbl*10000)/dk;
					b[1] = 0x16;	
					ueh.eh.bit7 = 1;
					ueh.eh.bit6 = 0;
					ueh.eh.bit5 = 0;
					ueh.eh.bit4 = 0;
					b[3] = r03&0x7F;
					ueh.eh.bit0 = (r03&0x80)>>7;
					b[4] = r04&0x7F;
					ueh.eh.bit1 = (r04&0x80)>>7;
					b[5] = (r04>>8)&0x7F;
					ueh.eh.bit2 = ((r04>>8)&0x80)>>7;
					b[6] = (r04>>16)&0x7F;
					ueh.eh.bit3 = ((r04>>16)&0x80)>>7;
					b[2] = ueh.b;	
				}
			}
		}
	}
 return b;

}
*/


extern "C" void  ParseCommand1()
{
	 add_char_TCP_buff(TYPE_AUTO);
	 for(long i = 0; i < 44; i++)
	 {
	   add_char_TCP_buff(unEmb2TypeVer.byte[i]);
	 }
	 breakflag =1; 
}

extern "C" void  GetCode1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  GetCode2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}



extern "C" void  GetLockLevel1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  GetLockLevel2()
{

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  GetTemp1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  GetTemp2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  Get48_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  Get48_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  Get24_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  Get24_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  Get7_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  Get7_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  Get5_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  Get5_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  Get5M_1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//
				embMsgUDRequest_1.SetLength(1); //?????
				embMsgUDRequest_1.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  Get5M_2()
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//
				embMsgUDRequest_2.SetLength(1); //?????
				embMsgUDRequest_2.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}



//extern "C" void  SetSymbolRate1(unsigned long freq)
//{
/*
static unsigned char b2_keep = 0;
unsigned char * b = Formula9(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ,Band1);
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }
//____________________________________________________________________________
//	printf("\n\r freq1 = %ld" , emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FORMULA_LEN); //em
			    for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , b[i]);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
*/

//}




extern "C" void  SetAtt1()
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetAttRPU1(unsigned char val)
{

AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);
#ifdef PROG_PRM_PCH_L_61
	_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);
#endif

//____
//added 14
//____

  val >>= 1;

  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_15;} else{pio_ptr->SODR = MASK_BIT_15;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_17;} else{pio_ptr->SODR = MASK_BIT_17;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_19;} else{pio_ptr->SODR = MASK_BIT_19;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_22;} else{pio_ptr->SODR = MASK_BIT_22;}

#ifdef PROG_PRM_PCH_L_61
   pio_ptr->CODR = MASK_BIT_14; //set olweis to zero 14
#endif
}


extern "C" void  SetAttRPU1_5bits(unsigned char val)
{

AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 17, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 19, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 22, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   

//____
//added 14
//____

  val >>= 1;
  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_14;} else{pio_ptr->SODR = MASK_BIT_14;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_15;} else{pio_ptr->SODR = MASK_BIT_15;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_17;} else{pio_ptr->SODR = MASK_BIT_17;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_19;} else{pio_ptr->SODR = MASK_BIT_19;}
  if(!(val & MASK_BIT_4)) { pio_ptr->CODR = MASK_BIT_22;} else{pio_ptr->SODR = MASK_BIT_22;}
  
}





//extern "C" void  SetAttRPU2()
//{
			   
//}

//extern "C" void  SetAttRPU3()
//{
			   
//}

extern "C" void  SetAttRPU4(unsigned char val)
{

 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);
#ifdef PROG_PRM_PCH_L_61
	_at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);
#endif


//___________________
// +7
//_____________________

val >>= 1;


  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_8;} else{pio_ptr->SODR = MASK_BIT_8;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_10;} else{pio_ptr->SODR = MASK_BIT_10;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_12;} else{pio_ptr->SODR = MASK_BIT_12;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_13;} else{pio_ptr->SODR = MASK_BIT_13;}
#ifdef PROG_PRM_PCH_L_61
   pio_ptr->CODR = MASK_BIT_7; //set olweis to zero 7
#endif
			   
}

extern "C" void  SetAttRPU4_5bits(unsigned char val)
{

 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 7, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 8, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 10, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1);
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1);




//___________________
// +7
//_____________________

val >>= 1;

  if(!(val & MASK_BIT_0)) { pio_ptr->CODR = MASK_BIT_7;} else{pio_ptr->SODR = MASK_BIT_7;}
  if(!(val & MASK_BIT_1)) { pio_ptr->CODR = MASK_BIT_8;} else{pio_ptr->SODR = MASK_BIT_8;}
  if(!(val & MASK_BIT_2)) { pio_ptr->CODR = MASK_BIT_10;} else{pio_ptr->SODR = MASK_BIT_10;}
  if(!(val & MASK_BIT_3)) { pio_ptr->CODR = MASK_BIT_12;} else{pio_ptr->SODR = MASK_BIT_12;}
  if(!(val & MASK_BIT_4)) { pio_ptr->CODR = MASK_BIT_13;} else{pio_ptr->SODR = MASK_BIT_13;}
			   
}


//extern "C" void  SetAttRPU5()
//{
			   
//}
//extern "C" void  SetAttRPU6()
//{
			   
//}




extern "C" void  SetFreq2()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ,Band2);
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i, b[i]);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  SetAtt2()
{

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_2.SetBody(1, emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  KeepParam(unsigned long dataparam , unsigned long addrparam)
{
 unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;		  
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
   bt++;
   dataparam >>= 8;
   *(bt + addrparam + NVRAM_PARAMETERS_STORAGE) = dataparam & 0xff;
}

extern "C" unsigned long  RestoreParam(unsigned long addrparam)
{
 unsigned long dataparam = 0;
 unsigned char * bt;
  bt = (unsigned char *)(NVRAM_BASE);
   dataparam = *(bt + addrparam + NVRAM_PARAMETERS_STORAGE);		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 8;		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 16;		  
   bt++;
   dataparam += (*(bt + addrparam + NVRAM_PARAMETERS_STORAGE)) << 24;	
 return  dataparam;
}

extern "C" void  RestoreParameters()
{

   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ1_ADDR);
   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ2_ADDR);
   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT1_ADDR);
//091104   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT2_ADDR);
//091104   emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT1_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU1();
   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT2_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU2();


#ifdef PRM_PCH_THREE_LINES
   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ3_ADDR);
   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT3_ADDR);
//091104   emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT3_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt;
 //	 SetAttRPU3();


#endif //PRM_PCH_THREE_LINES


#ifdef PRM_PCH_SIX_LINES
//_______________________________________________________________________________________________
   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ4_ADDR);
   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT4_ADDR);
   emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT4_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt;
   //	 SetAttRPU4();

   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ5_ADDR);
   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT5_ADDR);
   emb5StatusReciever5.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT5_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU5();


   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ = RestoreParam(FREQ6_ADDR);
   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
   emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt =  RestoreParam(ATT6_ADDR);
   emb5StatusReciever6.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;   
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  RestoreParam(ATT6_ADDR_RPU);
    unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt;
  //	 SetAttRPU6();

//_______________________________________________________________________________________________
#endif //PRM_PCH_SIX_LINES






}

extern "C" unsigned char CheckSymbolRate(unsigned long rate)
{
//printfp("\n\rCheckSymbolRate");
//printfpd(" %d", rate);

  	 if((rate > MAX_SYMBOL_RATE) || (rate < MIN_SYMBOL_RATE))
			 {
	   //		 printfp("ret 0");
			 return 0;
			 }
			 return 1;
}

extern "C" unsigned char * FormulaDMU1_0(unsigned long f)	 //symbol rate dds2
{
	static unsigned char b[16];
////////////// DDS /////////////////
#ifdef GEN_100
  	double Fbase_dds = 700000000.0;
#else
	double Fbase_dds 	 = 737280000.0;	 //96.16*8
#endif

	double df;
	double Fdds;
////////////////////////////////////
	double Ftemp = f;
	Fdds = f;
	df = Fdds/Fbase_dds;
	__int64 u64base =  (__int64)(2814749l);
	u64base *= (__int64)(100000000l);
	u64base += (__int64) (76710656l);
	__int64 u64result = u64base*df;
	unsigned long low = u64result&0xFFFFFFFF;
	unsigned long high = (u64result>>32)&0xFFFFFFFF;
	b[0] = (high>>8)&0xFF;
	b[1] = high&0xFF;
	b[2] = (low>>24)&0xFF;
	b[3] = (low>>16)&0xFF;
	b[4] = (low>>8)&0xFF;
	b[5] = low&0xFF;
	return b;
}




extern "C" void LoadSymbolRate(unsigned long rate)
{
unsigned char * pData;
static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//

//101118 unsigned char * b = FormulaDMU1_0(rate);
unsigned char * b = FormulaDMU1_0((rate << 2));	 //101118

DataDDS[0] = 0x61;
DataDDS[1] = 0xAB;
DataDDS[2] = *b++;
DataDDS[3] = *b++;
DataDDS[4] = *b++;
DataDDS[5] = *b++;
DataDDS[6] = *b++;
DataDDS[7] = *b;

//SendToDDS(SENDED_DDS_FREQ_LEN, (unsigned long)b);
SendToDDS(SENDED_DDS_FREQ_LEN,  (unsigned long)&DataDDS[0]);
pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);
}




extern "C" void  ParseCommand2(char *IPBuff)
{
unsigned char chn = IPBuff[1];

		unsigned long tmp = (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2];
		if(CheckSymbolRate(tmp))
		{
		   SetSymbolRate(tmp);
		   LoadSymbolRate(tmp);
 		   SetNeedWriteDevId();
		   unEmb2TypeVer.emb2TypeVer.signature_software[0] =  IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[1] =  IPBuff[3];
		   unEmb2TypeVer.emb2TypeVer.signature_software[2] =  IPBuff[4];
		   unEmb2TypeVer.emb2TypeVer.signature_software[3] =  IPBuff[5];
		   add_char_TCP_buff(TYPE_RUN_OK);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(IPBuff[0]);

		 }
		 else
		 {
		   add_char_TCP_buff(TYPE_RUN_BAD);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
		 }
		 breakflag = 1;
}



#define CORR_MASK (0x7F)

extern "C" unsigned char MakeAtt(unsigned char inpval)
{
  unsigned char outval;
  unsigned char ht;
//  unsigned char lt;
/*
  if(inpval > 60) {lt = 0xf; ht = 0xf;}
  else if(inpval >= 30) {	ht = 0xf; lt = ((inpval - 30) >> 1);}
  else{ht = inpval >> 1; lt = 0;}
  outval = (ht << 4) + lt;
  outval &= CORR_MASK;
*/
  if(inpval <= 30) ht = inpval >> 1;
  else ht = 0x0f;
  outval = ht << 4;
  return outval;
}

extern "C" unsigned char MakeAttBack(unsigned char inpval)
{
  unsigned char outval;
  unsigned char ht;
  unsigned char lt;

  lt = inpval & 0xf;
  ht = (inpval & 0xf0) >> 4;
/*
  if(lt) {outval = ((lt << 1) + 30);}
  else 	 {outval = ht << 1;}
*/
  outval = ht << 1;
  return outval;
}

extern "C" unsigned char CheckFreqPCh(unsigned long freq)
{

// printfp("\n\rCheckFreqPCh");
// printfpd(" %d", freq);


  	 if(((freq <= MAX_FREQPCH1) && (freq >= MIN_FREQPCH1))
  	 ||  ((freq <= MAX_FREQPCH2) && (freq >= MIN_FREQPCH2)))
			 return 1;
			 return 0;
}


unsigned char * FormulaDMU2_0(unsigned long f)
{
	static unsigned char c[16];
////////////// DDS /////////////////
	double Fbase_dds = 700000000.0;
	double df;
	double Fdds;
////////////////////////////////////
	Fdds = f<<1;
	df = Fdds/Fbase_dds;
	__int64 u64base =  (__int64)(2814749l);
	u64base *= (__int64)(100000000l);
	u64base += (__int64) (76710656l);
	__int64 u64result = u64base*df;
	unsigned long low = u64result&0xFFFFFFFF;
	unsigned long high = (u64result>>32)&0xFFFFFFFF;
	c[0] = (high>>8)&0xFF;
	c[1] = high&0xFF;
	c[2] = (low>>24)&0xFF;
	c[3] = (low>>16)&0xFF;
	c[4] = (low>>8)&0xFF;
	c[5] = low&0xFF;

 return c;
}

extern "C" void LoadFreqPCh(unsigned long freq)
{
unsigned char * pData;
static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//
unsigned char * b = FormulaDMU2_0(freq);

DataDDS[0] = 0x61;
DataDDS[1] = 0xAB;
DataDDS[2] = *b++;
DataDDS[3] = *b++;
DataDDS[4] = *b++;
DataDDS[5] = *b++;
DataDDS[6] = *b++;
DataDDS[7] = *b;

//SendToDDS(SENDED_DDS_FREQ_LEN, (unsigned long)b);
SendToDDS3(SENDED_DDS_FREQ_LEN,  (unsigned long)&DataDDS[0]);
pData = DataDDS;
*pData++ = 0;   *pData++ = 5;	 *pData = 1;
SendToDDS3(LEN_DATA_DDS,  (unsigned long)&DataDDS[0]);



}


extern "C" void  ParseCommand3(char *IPBuff)
{
	unsigned char chn = IPBuff[1];
		unsigned long tmp = (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2];
		if(CheckFreqPCh(tmp))
		{
		   SetFreqPCh(tmp);
		   LoadFreqPCh(tmp);
		   LoadModulSK(); //it depended from freq
 		   SetNeedWriteDevId();
		   unEmb2TypeVer.emb2TypeVer.signature_software[4] =  IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[5] =  IPBuff[3];
		   unEmb2TypeVer.emb2TypeVer.signature_software[6] =  IPBuff[4];
		   unEmb2TypeVer.emb2TypeVer.signature_software[7] =  IPBuff[5];
		   add_char_TCP_buff(TYPE_RUN_OK);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(IPBuff[0]);
 		 }
		 else
		 {
		   add_char_TCP_buff(TYPE_RUN_BAD);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
		 }
		  breakflag = 1;

}



extern "C" unsigned char CheckModulSK(unsigned long modul)
{
  	 if(
  	  (modul == MODUL1) ||
  	  (modul == MODUL2) ||
  	  (modul == MODUL3) ||
  	  (modul == MODUL4) ||
  	  (modul == MODUL5) ||
  	  (modul == MODUL6) ||
  	  (modul == MODUL7) ||
  	  (modul == MODUL8) ||
  	  (modul == MODUL11)  ||
  	  (modul == MODUL41)  ||
  	  (modul == MODUL51)  ||
  	  (modul == MODUL61)  ||
  	  (modul == MODUL71)  ||
  	  (modul == MODUL81)      )
			 return 1;
			 return 0;
}

extern "C" void LoadModulSK()
{

AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
unsigned char b12, b13, b14, b15;
unsigned char modulsk;

   pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;

   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 12, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 13, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 14, AT91RM9200_PIO_PERIPHERAL_IO, 1); 
   _at91rm9200_pio_set(AT91RM9200_PIO_PORT_B, 15, AT91RM9200_PIO_PERIPHERAL_IO, 1); 

	modulsk = GetModulSK();
   switch(modulsk)
   {
	 case MODUL1 :  b14 = 0; b13 = 0;	b12 = 0;   break;
	 case MODUL2 :  b14 = 0; b13 = 0;	b12 = 1;   break;
	 case MODUL3 :  b14 = 0; b13 = 1;	b12 = 0;   break;
	 case MODUL4 :  b14 = 0; b13 = 1;	b12 = 1;   break;
	 case MODUL5 :  b14 = 1; b13 = 0;	b12 = 0;   break;
	 case MODUL6 :  b14 = 1; b13 = 0;	b12 = 1;   break;
	 case MODUL7 :  b14 = 1; b13 = 1;	b12 = 0;   break;
	 case MODUL8 :  b14 = 1; b13 = 1;	b12 = 1;   break;
  //added - need check!!!
	 case MODUL11 :  b14 = 0; b13 = 0;	b12 = 0;   break;
	 case MODUL41 :  b14 = 0; b13 = 1;	b12 = 1;   break;
	 case MODUL51 :  b14 = 1; b13 = 0;	b12 = 0;   break;
	 case MODUL61 :  b14 = 1; b13 = 0;	b12 = 1;   break;
	 case MODUL71 :  b14 = 1; b13 = 1;	b12 = 0;   break;
	 case MODUL81 :  b14 = 1; b13 = 1;	b12 = 1;   break;


	 default   :  b14 = 0; b13 = 0;	b12 = 0;    break;
   }

   if(GetFreqPCh() <= MAX_FREQPCH1)	{b15 = 0;}
   else {b15 = 1;}

  if(b12) { pio_ptr->SODR = MASK_BIT_12;} else{pio_ptr->CODR = MASK_BIT_12;}
  if(b13) { pio_ptr->SODR = MASK_BIT_13;} else{pio_ptr->CODR = MASK_BIT_13;}
  if(b14) { pio_ptr->SODR = MASK_BIT_14;} else{pio_ptr->CODR = MASK_BIT_14;}
  if(b15) { pio_ptr->SODR = MASK_BIT_15;} else{pio_ptr->CODR = MASK_BIT_15;}

#ifdef 	PROG_PRM_PCH_DEM_XIL
#ifndef  PROG_PRM_PCH_DEM_XIL_CHN
 if(beforemodulsk != modulsk)
 {
   if(modulsk != MODUL7)
   {
	  if(beforemodulsk == MODUL7)
	  {
		SetNeedReloadXil(1);
	  }
   }
   else
   {
	   SetNeedReloadXil(0);
   }
 beforemodulsk = modulsk;
 }
#endif
#endif //PROG_PRM_PCH_DEM_XIL

 /*
printfp("\n\r");
printfpd("b12 = %d", b12);
printfpd(" b13 = %d", b13);
printfpd(" b14 = %d", b14);
printfpd(" b15 = %d", b15);
 */
}


extern "C" void  ParseCommand4(char *IPBuff)
{
   unsigned char chn = IPBuff[1];

		unsigned long tmp = IPBuff[2];
		if(CheckModulSK(tmp))
		{
		   SetModulSK(tmp);
		   LoadModulSK();
 		   SetNeedWriteDevId();
		   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];
 		   add_char_TCP_buff(TYPE_RUN_OK);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(IPBuff[0]);
		 }
		 else
		 {
		   add_char_TCP_buff(TYPE_RUN_BAD);
		   add_char_TCP_buff(IPBuff[1]);
		   add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
		 }
		  breakflag = 1;
}
 /*
extern "C" void   FillStatus(DmuStatusu *dmu, unsigned char)
{
   dmu.dmustatus.status = unEmb2TypeVer.emb2TypeVer.signature_software[9];
   dmu->dmustatus->mode = GetModulSK();
   dmu->dmustatus->freq = GetFreqPCh();
   dmu->dmustatus->rate = GetSymbolRate();
}

*/
extern "C" void  ParseCommand5(char *IPBuff)
{
	DmuStatusu dmustatusu;
  //	FillStatus( &dmustatusu, IPBuff[1]);
	 
	// 	unsigned long tmp = IPBuff[1];

 dmustatusu.dmustatus.status = unEmb2TypeVer.emb2TypeVer.signature_software[9];
 dmustatusu.dmustatus.mode = GetModulSK();
 dmustatusu.dmustatus.freq = GetFreqPCh();
  dmustatusu.dmustatus.rate = GetSymbolRate();
   dmustatusu.dmustatus.rezerv = 0xFFFFFFFF;

 add_char_TCP_buff(TYPE_STATUS);
 add_char_TCP_buff(IPBuff[1]);
 //	 printfp("\n\r");
	 for(long i = 0; i < 20; i++)
	 {
	   add_char_TCP_buff(dmustatusu.byte[i]);
  //	   printfpd(" %02X",dmustatusu.byte[i] );
	 }
	 breakflag =1; 
}



extern "C" void  ParseCommand6(char *IPBuff)
{
 breakflag =1; 

	 add_char_TCP_buff(CODE_RPU_STATE);
	 long i;
	switch(IPBuff[1])
	{
case  1 :  for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState1.byte[i]);
	 		}
  			break;
case  2 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState2.byte[i]);
	 		}
 			break;
#ifdef PRM_PCH_THREE_LINES

case  3 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState3.byte[i]);
	 		}
			break;
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES

case  4 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState4.byte[i]);
	 		}
			break;

case  5 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState5.byte[i]);
	 		}
			break;
case  6 :   for(i = 0; i < 20; i++)
	 		{
	   		add_char_TCP_buff(emb5RPUState6.byte[i]);
	 		}
			break;
#endif // PRM_PCH_SIX_LINES
default : 
 	add_char_TCP_buff(TYPE_RUN_BAD);
	add_char_TCP_buff(IPBuff[1]);
  break;

	 }
}

extern "C" void  ParseCommand7(char *IPBuff)
{
  	 breakflag =1; 
	switch(IPBuff[1])
	{
case  1 : 
		 if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

 			emb5ScanFreq1.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq1.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq1.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
		 //	printf("\n\r 8 : 0x%x 9 : 0x%x", IPBuff[8],IPBuff[9]);
		 //   message = 	IPBuff[8] +  (IPBuff[9] << 8) + 1;
			if(emb5ScanFreq1.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq1.emb5scanfreq.numOfStep = MAX_STEPS;
 			emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq1.emb5scanfreq.frequStart;
   			emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan1.emb5statusfrequscan.number =   emb5ScanFreq1.emb5scanfreq.number;
			emb5StatusFrequScan1.emb5statusfrequscan.frequStart =   emb5ScanFreq1.emb5scanfreq.frequStart;
			emb5StatusFrequScan1.emb5statusfrequscan.step =   emb5ScanFreq1.emb5scanfreq.step;
			emb5StatusFrequScan1.emb5statusfrequscan.numOfStep =   emb5ScanFreq1.emb5scanfreq.numOfStep;
			emb5StatusFrequScan1.emb5statusfrequscan.att =   emb5StatusReciever1.emb5statusreciever.stepAtt;
			modescan1 = 1; //start scan	channel1
   			curval1 = -2;
			emb5ScanFreq1.emb5scanfreq.numOfStep += (unsigned short)2; //to have last data(first answer is emty ) and +1 have last receive - modescan setted to zero in requests 
  		    delay1 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq1.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan1.emb5statusfrequscan.level[i] = ConvVal(0);
				}
 			break;
case  2 : 
 		  if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

 			emb5ScanFreq2.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq2.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq2.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq2.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq2.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq2.emb5scanfreq.frequStart;
   			emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan2.emb5statusfrequscan.number =   emb5ScanFreq2.emb5scanfreq.number;
			emb5StatusFrequScan2.emb5statusfrequscan.frequStart =   emb5ScanFreq2.emb5scanfreq.frequStart;
			emb5StatusFrequScan2.emb5statusfrequscan.step =   emb5ScanFreq2.emb5scanfreq.step;
			emb5StatusFrequScan2.emb5statusfrequscan.numOfStep =   emb5ScanFreq2.emb5scanfreq.numOfStep;
			emb5StatusFrequScan2.emb5statusfrequscan.att =   emb5StatusReciever2.emb5statusreciever.stepAtt;
		    modescan2 = 1; //start scan channel2
  	        curval2 = -2;
		   	emb5ScanFreq2.emb5scanfreq.numOfStep += (unsigned short)2;
	  		delay2 = SCAN_DELAY;
	  		for(i = 0; i < emb5ScanFreq2.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan2.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
#ifdef PRM_PCH_THREE_LINES
case  3 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq3.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq3.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq3.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq3.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq3.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq3.emb5scanfreq.frequStart;
   			emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan3.emb5statusfrequscan.number =   emb5ScanFreq3.emb5scanfreq.number;
			emb5StatusFrequScan3.emb5statusfrequscan.frequStart =   emb5ScanFreq3.emb5scanfreq.frequStart;
			emb5StatusFrequScan3.emb5statusfrequscan.step =   emb5ScanFreq3.emb5scanfreq.step;
			emb5StatusFrequScan3.emb5statusfrequscan.numOfStep =   emb5ScanFreq3.emb5scanfreq.numOfStep;
			emb5StatusFrequScan3.emb5statusfrequscan.att =   emb5StatusReciever3.emb5statusreciever.stepAtt;
		    modescan3 = 1; //start scan channel2
	    	curval3 = -2;
		   	emb5ScanFreq3.emb5scanfreq.numOfStep += (unsigned short)2;
			delay3 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq3.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan3.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//__________________________________________________________________4
case  4 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq4.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq4.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq4.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq4.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq4.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq4.emb5scanfreq.frequStart;
   			emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan4.emb5statusfrequscan.number =   emb5ScanFreq4.emb5scanfreq.number;
			emb5StatusFrequScan4.emb5statusfrequscan.frequStart =   emb5ScanFreq4.emb5scanfreq.frequStart;
			emb5StatusFrequScan4.emb5statusfrequscan.step =   emb5ScanFreq4.emb5scanfreq.step;
			emb5StatusFrequScan4.emb5statusfrequscan.numOfStep =   emb5ScanFreq4.emb5scanfreq.numOfStep;
			emb5StatusFrequScan4.emb5statusfrequscan.att =   emb5StatusReciever4.emb5statusreciever.stepAtt;
		    modescan4 = 1; //start scan channel2
	    	curval4 = -2;
		   	emb5ScanFreq4.emb5scanfreq.numOfStep += (unsigned short)2;
			delay4 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq4.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan4.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
//__________________________________________________________________________________4

//__________________________________________________________________5
case  5 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq5.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq5.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq5.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq5.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq5.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq5.emb5scanfreq.frequStart;
   			emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan5.emb5statusfrequscan.number =   emb5ScanFreq5.emb5scanfreq.number;
			emb5StatusFrequScan5.emb5statusfrequscan.frequStart =   emb5ScanFreq5.emb5scanfreq.frequStart;
			emb5StatusFrequScan5.emb5statusfrequscan.step =   emb5ScanFreq5.emb5scanfreq.step;
			emb5StatusFrequScan5.emb5statusfrequscan.numOfStep =   emb5ScanFreq5.emb5scanfreq.numOfStep;
			emb5StatusFrequScan5.emb5statusfrequscan.att =   emb5StatusReciever5.emb5statusreciever.stepAtt;
		    modescan5 = 1; //start scan channel2
	    	curval5 = -2;
		   	emb5ScanFreq5.emb5scanfreq.numOfStep += (unsigned short)2;
			delay5 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq5.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan5.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
//__________________________________________________________________________________5

//__________________________________________________________________6
case  6 : 
 		if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])
		   {
			  add_char_TCP_buff(TYPE_RUN_OK);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
		    add_char_TCP_buff(IPBuff[1]);
     		add_char_TCP_buff(CODE_COMMAND_7);

			emb5ScanFreq6.emb5scanfreq.frequStart =  IPBuff[2] +  (IPBuff[3] << 8) +  (IPBuff[4] << 16)	+    (IPBuff[5] << 24);
			emb5ScanFreq6.emb5scanfreq.step = IPBuff[6] +  (IPBuff[7] << 8);
			emb5ScanFreq6.emb5scanfreq.numOfStep = 	IPBuff[8] +  (IPBuff[9] << 8);
			if(emb5ScanFreq6.emb5scanfreq.numOfStep > MAX_STEPS) emb5ScanFreq6.emb5scanfreq.numOfStep = MAX_STEPS;
			emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ =  emb5ScanFreq6.emb5scanfreq.frequStart;
   			emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
			emb5StatusFrequScan6.emb5statusfrequscan.number =   emb5ScanFreq6.emb5scanfreq.number;
			emb5StatusFrequScan6.emb5statusfrequscan.frequStart =   emb5ScanFreq6.emb5scanfreq.frequStart;
			emb5StatusFrequScan6.emb5statusfrequscan.step =   emb5ScanFreq6.emb5scanfreq.step;
			emb5StatusFrequScan6.emb5statusfrequscan.numOfStep =   emb5ScanFreq6.emb5scanfreq.numOfStep;
			emb5StatusFrequScan6.emb5statusfrequscan.att =   emb5StatusReciever6.emb5statusreciever.stepAtt;
		    modescan6 = 1; //start scan channel2
	    	curval6 = -2;
		   	emb5ScanFreq6.emb5scanfreq.numOfStep += (unsigned short)2;
			delay6 = SCAN_DELAY;
			for(i = 0; i < emb5ScanFreq6.emb5scanfreq.numOfStep; i++)
				{
	  				emb5StatusFrequScan6.emb5statusfrequscan.level[i] = ConvVal(0);
				}
		    break;
//__________________________________________________________________________________4


#endif //PRM_PCH_SIX_LINES
default :  	  add_char_TCP_buff(TYPE_RUN_BAD);
		      add_char_TCP_buff(IPBuff[1]);
     		  add_char_TCP_buff(CODE_COMMAND_7);
 break;
	 }
}
extern "C" void  ParseCommand8(char *IPBuff)
{
 //	 add_char_TCP_buff(REQUEST_SCAN);
	 long i;
 breakflag =1; 
	switch(IPBuff[1])
	{
case  1 : 
		   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan1 = 0;
			delay1 = NO_SCAN_DELAY;
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan1.emb5statusfrequscan.att);		//9
		 	for(i = 14; i <  ((emb5StatusFrequScan1.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan1.byte[i]);
	 		}
 			break;
case  2 : 
			if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan2 = 0;
  			delay2 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan2.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan2.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan2.byte[i]);
	 		}
			break;

#ifdef PRM_PCH_THREE_LINES

case  3 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan3 = 0;
		    delay3 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan3.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan3.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan3.byte[i]);
	 		}
			break;
#endif // PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//________________________________________________________________4
case  4 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan4 = 0;
  			delay4 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan4.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan4.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan4.byte[i]);
	 		}
			break;
//_____________________________________________________________________________________4

//________________________________________________________________5
case  5 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan5 = 0;
  			delay5 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan5.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan5.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan5.byte[i]);
	 		}
			break;
//_____________________________________________________________________________________5

//________________________________________________________________6
case  6 : 
	   if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])
		   {
			   add_char_TCP_buff(REQUEST_SCAN);
		   }
		   else
		   {
			  add_char_TCP_buff(TYPE_RUN_BAD);
		   }	
			modescan6 = 0;
  			delay6 = NO_SCAN_DELAY;
		  	add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.number);		  //0
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart);	   //1
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>8);	//2
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>16);	 //3
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.frequStart>>24);	 //4
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.step);			 //5
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.step>>8);		 //6
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.numOfStep);		 //7
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.numOfStep>>8);	  //8
			add_char_TCP_buff(emb5StatusFrequScan6.emb5statusfrequscan.att);		//9

	 	for(i = 14; i < ((emb5StatusFrequScan6.emb5statusfrequscan.numOfStep << 1) + 14) ; i++)
	 	 	{
	   			add_char_TCP_buff(emb5StatusFrequScan6.byte[i]);
	 		}
			break;
//_____________________________________________________________________________________4

#endif // PRM_PCH_SIX_LINES
default : 
		   add_char_TCP_buff(TYPE_RUN_BAD);
  			break;
	 }
}

extern "C" void  ParseCommand9(char *IPBuff)
{
 breakflag =1; 

   add_char_TCP_buff(TYPE_RUN_9);
   add_char_TCP_buff(IPBuff[1]);

	 long i;
	switch(IPBuff[1])
	{
case  1 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus1.byte[i]);
				embUpDownStatus1.byte[i] = 0l;
	 		}
 			break;
case  2 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus2.byte[i]);
				embUpDownStatus2.byte[i] = 0l;
	 		}
			break;
#ifdef PRM_PCH_THREE_LINES

case  3 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus3.byte[i]);
				embUpDownStatus3.byte[i] = 0l;
	 		}
			break;
#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//___________________________________________________________________4
case  4 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus4.byte[i]);
				embUpDownStatus4.byte[i] = 0l;
	 		}
			break;
//____________________________________________________________________4
//___________________________________________________________________5
case  5 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus5.byte[i]);
				embUpDownStatus5.byte[i] = 0l;
	 		}
			break;
//____________________________________________________________________5
//___________________________________________________________________6
case  6 : 
		 	for(i = 0; i <  16; i++)
	 	 	{
	   			add_char_TCP_buff(embUpDownStatus6.byte[i]);
				embUpDownStatus6.byte[i] = 0l;
	 		}
			break;
//____________________________________________________________________6

#endif //PRM_PCH_SIX_LINES
default :   break;
	 }
}

#define CODE_33 (0x21)

extern "C" void  ParseCommand33(char *IPBuff)
{
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(CODE_33);
   test_shift_mode = IPBuff[1];
   unEmb2TypeVer.emb2TypeVer.signature_software[14] = test_shift_mode;
}


extern "C" void  ParseCommand11(char *IPBuff)
{
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];

// if(GetTestMode() == 0x50)
// {
//  printf("\n\r %02X", IPBuff[2]);
// }

		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;

   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		   SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);	 //need change
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
 unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2];
 unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2]<<1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
 	     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
 unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2]<<1;
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

 //  add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
   add_char_TCP_buff(ATT_RPU_CODE);


}





//_______________________________________________________________________
#ifdef PROG_PRM_PCH_L_61
//_____________________________________________________________________

extern "C" void  SetAtt1_12(unsigned char val)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_1.SetBody(1, val);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetAtt2_12(unsigned char val)
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_2.SetBody(1, val);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
extern "C" void  SetAtt3_12(unsigned char val)
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_3.SetBody(1, val);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  SetAtt4_12(unsigned char val)
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_4.SetBody(1, val);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  SetAtt5_12(unsigned char val)
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_5.SetBody(1, val);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  SetAtt6_12(unsigned char val)
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT_12);	//
			    embMsgUDRequest_6.SetBody(1, val);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  SetAtt1_13(unsigned char val)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_1.SetBody(1, val);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetAtt2_13(unsigned char val)
{
				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_2.SetLength(2); //?????
				embMsgUDRequest_2.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_2.SetBody(1, val);	//
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
extern "C" void  SetAtt3_13(unsigned char val)
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_3.SetBody(1, val);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  SetAtt4_13(unsigned char val)
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_4.SetBody(1, val);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  SetAtt5_13(unsigned char val)
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_5.SetBody(1, val);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  SetAtt6_13(unsigned char val)
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT_13);	//
			    embMsgUDRequest_6.SetBody(1, val);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}




extern "C" void  ParseCommand12(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetAtt1_12( IPBuff[2]);
	 //	   unEmb2TypeVer.emb2TypeVer.signature_software[0] = IPBuff[2];
 		   break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		    SetAtt2_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[8] = IPBuff[2];
	  		break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
		    SetAtt3_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[4] = IPBuff[2];
			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		    SetAtt4_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[1] = IPBuff[2];

			break;

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
		    SetAtt5_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[9] = IPBuff[2];



			break;

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		    SetAtt6_12( IPBuff[2]);
	 //	    unEmb2TypeVer.emb2TypeVer.signature_software[5] = IPBuff[2];
			break;

#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}

extern "C" void  ParseCommand13(char *IPBuff)
{
 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetAtt1_13( IPBuff[2]);
	//	   unEmb2TypeVer.emb2TypeVer.signature_software[2] = IPBuff[2];
 		   break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
		    SetAtt2_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[10] = IPBuff[2];
	  		break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
		    SetAtt3_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[6] = IPBuff[2];
			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
		    SetAtt4_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[3] = IPBuff[2];

			break;

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
		    SetAtt5_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[11] = IPBuff[2];



			break;

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
		    SetAtt6_13( IPBuff[2]);
	//	    unEmb2TypeVer.emb2TypeVer.signature_software[7] = IPBuff[2];
			break;

#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


extern "C" void  ParseCommand14(char *IPBuff)
{
  breakflag =1;
   add_char_TCP_buff(TYPE_RUN_OK);
   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
//		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
//		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
//		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
// if(GetTestMode() == 0x50)
// {
//  printf("\n\r %02X", IPBuff[2]);
// }
		   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;

//091025   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT1_ADDR_RPU); //need change
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT2_ADDR_RPU);
  //	   KeepParam(unEmb2TypeVer.emb2TypeVer.signature_software[12] , ATT3_ADDR_RPU);
		   SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_software[12]);	 //need change
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

 			break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
 //		   emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
 //		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
    	   unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
  //		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
  //	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
  //	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
	        delay3 = NO_SCAN_DELAY;
 //  emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
  //		   emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt = IPBuff[2];
  //		   emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt = IPBuff[2];
	      unEmb2TypeVer.emb2TypeVer.signature_software[12] = IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = IPBuff[2] >> 1;
   	//091025 	   emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
//		   KeepParam(emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt , ATT1_ADDR_RPU); //need change
//	   KeepParam(emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt , ATT2_ADDR_RPU);
//	   KeepParam(emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt , ATT3_ADDR_RPU);
		    SetAttRPU1_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[12]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 //		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
 //  emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //  emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];

   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   //			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
  //			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
  //		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________

case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
  			delay5 = NO_SCAN_DELAY;
 //	     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
//   emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
//   emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];

 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   	//		KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
	//		KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
	//	KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;



//_________________________________________

//_________________________________________

case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
  //		     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt = IPBuff[2];  
 //  emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
 //  emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt = IPBuff[2]; 
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[2]>>1;
 			unEmb2TypeVer.emb2TypeVer.signature_software[13] = IPBuff[2];
 
   //			emb5StatusReciever4.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;   
   //			KeepParam(emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt , ATT4_ADDR_RPU);
   //			KeepParam(emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt , ATT5_ADDR_RPU);
   //		KeepParam(emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt , ATT6_ADDR_RPU);   							  
		    SetAttRPU4_5bits(unEmb2TypeVer.emb2TypeVer.signature_hardware[13]);
#ifdef	   PROG_PRM_PCH_L
 		   SetNeedWriteDevId();
#endif     // PROG_PRM_PCH_L

			break;
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}

 //  add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
   add_char_TCP_buff(ATT_RPU5_CODE);


}


//_____________________________________________________________________







unsigned char WriteStatus1,WriteStatus2,WriteStatus3,WriteStatus4,WriteStatus5,WriteStatus6;
unsigned char ReadStatus1[3], ReadStatus2[3], ReadStatus3[3], ReadStatus4[3], ReadStatus5[3], ReadStatus6[3];
unsigned char ReadAtt1[3], ReadAtt2[3], ReadAtt3[3], ReadAtt4[3], ReadAtt5[3], ReadAtt6[3]; 

extern "C" void  GetAtt1(void)
{
  ReadAtt1[0] = 0;
  ReadAtt1[1] = 0;
  ReadAtt1[2] = 0;


				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  GetAtt2(void)
{
  ReadAtt2[0] = 0;
  ReadAtt2[1] = 0;
  ReadAtt2[2] = 0;


				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
extern "C" void  GetAtt3(void)
{
  ReadAtt3[0] = 0;
  ReadAtt3[1] = 0;
  ReadAtt3[2] = 0;


				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  GetAtt4(void)
{
  ReadAtt4[0] = 0;
  ReadAtt4[1] = 0;
  ReadAtt4[2] = 0;


				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  GetAtt5(void)
{
  ReadAtt5[0] = 0;
  ReadAtt5[1] = 0;
  ReadAtt5[2] = 0;


				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  GetAtt6(void)
{
  ReadAtt6[0] = 0;
  ReadAtt6[1] = 0;
  ReadAtt6[2] = 0;


				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(GET_ATT_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_GETATT);
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  GetFlash1(char *pAddrData)
{
  ReadStatus1[0] = 0;
  ReadStatus1[1] = 0;
  ReadStatus1[2] = 0;


				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  GetFlash2(char *pAddrData)
{
  ReadStatus2[0] = 0;
  ReadStatus2[1] = 0;
  ReadStatus2[2] = 0;

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}
extern "C" void  GetFlash3(char *pAddrData)
{
  ReadStatus3[0] = 0;
  ReadStatus3[1] = 0;
  ReadStatus3[2] = 0;

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_3.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  GetFlash4(char *pAddrData)
{
  ReadStatus4[0] = 0;
  ReadStatus4[1] = 0;
  ReadStatus4[2] = 0;

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_4.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  GetFlash5(char *pAddrData)
{
  ReadStatus5[0] = 0;
  ReadStatus5[1] = 0;
  ReadStatus5[2] = 0;

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_5.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  GetFlash6(char *pAddrData)
{
  ReadStatus6[0] = 0;
  ReadStatus6[1] = 0;
  ReadStatus6[2] = 0;

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(GET_FLASH_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_GETFLASH);
			    for(long i = 1; i < GET_FLASH_LEN; i++)
				{
				 embMsgUDRequest_6.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}





extern "C" void  SetFlash1(char *pAddrData)
{
  WriteStatus1 = 0;

				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FLASH_LEN); //em
				embMsgUDRequest_1.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();
}

extern "C" void  SetFlash2(char *pAddrData)
{
WriteStatus2 = 0;

				embMsgUDRequest_2.Init();
				embMsgUDRequest_2.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_2.SetLength(FLASH_LEN); //em
				embMsgUDRequest_2.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_2.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_2.CalcCRC();
				embMsgUDRequest_2.SetReadyToSend();
}

extern "C" void  SetFlash3(char *pAddrData)
{
WriteStatus3 = 0;

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_3.SetLength(FLASH_LEN); //em
				embMsgUDRequest_3.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_3.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  SetFlash4(char *pAddrData)
{
WriteStatus4 = 0;

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_4.SetLength(FLASH_LEN); //em
				embMsgUDRequest_4.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_4.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  SetFlash5(char *pAddrData)
{
 WriteStatus5 = 0;
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_5.SetLength(FLASH_LEN); //em
				embMsgUDRequest_5.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_5.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  SetFlash6(char *pAddrData)
{
  WriteStatus6 = 0;
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_6.SetLength(FLASH_LEN); //em
				embMsgUDRequest_6.SetBody(0 , CODE_SETFLASH);
			    for(long i = 1; i < FLASH_LEN; i++)
				{
				 embMsgUDRequest_6.SetBody(i , *pAddrData++);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}





extern "C" void  ParseCommand30(char *IPBuff)
{
 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   SetFlash1(&IPBuff[2]);	 //
 			break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 SetFlash2(&IPBuff[2]);	 //

		   			break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  SetFlash3(&IPBuff[2]);	 //

			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  SetFlash4(&IPBuff[2]);	 //

			break;


case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 SetFlash5(&IPBuff[2]);	 //

 
			break;



case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  SetFlash6(&IPBuff[2]);	 //

			break;
//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


extern "C" void  ParseCommand31(char *IPBuff)
{
 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   GetFlash1(&IPBuff[2]);	 //
 			break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 GetFlash2(&IPBuff[2]);	 //

		   			break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  GetFlash3(&IPBuff[2]);	 //

			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  GetFlash4(&IPBuff[2]);	 //

			break;


case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 GetFlash5(&IPBuff[2]);	 //

 
			break;



case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  GetFlash6(&IPBuff[2]);	 //

			break;


//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}

extern "C" void  ParseCommand32(char *IPBuff)
{
 // breakflag =1;
//   add_char_TCP_buff(TYPE_RUN_OK);
//   add_char_TCP_buff(IPBuff[1]);
//   add_char_TCP_buff(ATT_RPU_CODE);
//	  unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = IPBuff[1]; //for test

 	switch(IPBuff[1])
	{
case  1 : 
		   modescan1 = 0;
		   countMod = 0;
	       delay1 = NO_SCAN_DELAY;
		   GetAtt1();	 //
 			break;
case  2 : 
		   
		    modescan2 = 0;
			countMod2 = 0;
			delay2 = NO_SCAN_DELAY;
			 GetAtt2();	 //

		   			break;

#ifdef PRM_PCH_THREE_LINES
case  3 : 
			 modescan3 = 0; 
			countMod3 = 0;
			delay3 = NO_SCAN_DELAY;
	     	  GetAtt3();	 //

			break;

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//_________________________________________

case  4 : 
		   
		    modescan4 = 0;
			countTransit4 = 0;
		    delay4 = NO_SCAN_DELAY;
 			  GetAtt4();	 //

			break;


case  5 : 
		   
		    modescan5 = 0;
			countTransit5 = 0;
			delay5 = NO_SCAN_DELAY;
			 GetAtt5();	 //

 
			break;



case  6 : 
		    modescan6 = 0;
			countTransit6 = 0;
  			delay6 = NO_SCAN_DELAY;
 			  GetAtt6();	 //

			break;


//_________________________________________




#endif	// PRM_PCH_SIX_LINES


default : 
		 break;
	}
}


#endif// PROG_PRM_PCH_L_61
//_______________________________________________________________________
	/*
extern "C" unsigned char Roulette1(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette1 code: %d" , requestMod);
#endif// PRM_PCH_DEBUG

 if(start1){ delay1 = ROULETTE_DELAY;}
 switch(requestMod++)
 {
   case 0: GetCode1(); break;
   case 1: GetCode1(); break; //GetLockLevel1(); break;
   case 2: GetCode1(); break; //GetTemp1(); break;
   case 3: GetCode1(); break; //Get48_1(); break;
   case 4: GetCode1(); break; //Get24_1(); break;
   case 5: GetCode1(); break; //Get7_1(); break;
   case 6: GetCode1(); break;//Get5_1(); break;
   case 7: GetCode1(); break; //Get5M_1(); break;
   case 9: if(!setf1) { SetFreq1(); setf1 = 1;break; } 	return 0;
   case 8: if(!setatt1) { SetAtt1(); setatt1 = 1;break;} return 0;
#ifndef PROG_PRM_PCH_C
    default :  requestMod = 0; return 0;	  //to have cycle requests
#else 
   default :  	if(start1)
				{
   	  //			tmp = inportb(POWER_PORT);
				ClearMod();
				outportb(POWER_PORT,  CH2_MASK);  
				requestMod = 11;
				start1 = 0;
				delay1 = NO_SCAN_DELAY;
				delay2 = time1 + START_TIMEOUT;
				}
				else
				{
	   		 requestMod = 11;
				}
				return 0;
#endif
 }
 return 1;
}	
  */
extern "C" unsigned char Roulette2(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette2 code: %d" , requestTransit);
#endif// PRM_PCH_DEBUG
if(start2){ delay2 = ROULETTE_DELAY;}
   switch(requestTransit++)
 {
   case 0: GetCode2();	break;
   case 1: GetCode2();	break; //GetLockLevel2(); break;
   case 2: GetCode2();	break; //GetTemp2(); break;
   case 3: GetCode2();	break; //Get48_2(); break;
   case 4: GetCode2();	break; //Get24_2(); break;
   case 5: GetCode2();	break; //Get7_2();break;
   case 6: GetCode2();	break; //Get5_2(); break;
   case 7: GetCode2();	break; //Get5M_2(); break;
   case 9: if(!setf2) {SetFreq2(); setf2 = 1; break;} 	 return 0;
   case 8: if(!setatt2) {SetAtt2(); setatt2 = 1;  break;}    return 0;
#ifndef PROG_PRM_PCH_C

   default :  requestTransit = 0; return 0;	  //to have cycle
#else 
   default :  	if(start2)
				{
   		//		tmp = inportb(POWER_PORT);
#ifdef PROG_PRM_PCH_S
				ClearMod();
#endif
 			    outportb(POWER_PORT, (CH3_MASK));  
				requestTransit = 11;
				start2 = 0;
				delay2 = NO_SCAN_DELAY;
				delay3 = time1 + START_TIMEOUT;
				}
				else
				{
 				 requestTransit = 11;
				}
				return 0;
#endif
 }
  return 1;
}	
 /*
extern "C" void MakeNextStepScan1()
{
 SetFreq1();
 //____________________________________________________________________________
 //	printf("\n\rstepnum = %d  stepfreq = 0x%X freq1 = 0x%lX" ,emb5ScanFreq1.emb5scanfreq.numOfStep, emb5ScanFreq1.emb5scanfreq.step, emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
 //	printf("\n\r0x%lX", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________

 if(emb5ScanFreq1.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ += emb5ScanFreq1.emb5scanfreq.step;
   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
   curval1++;
 }
 else
 {
   modescan1 = 0; //stop scan channel1  //this was be lost!!!!
   delay1 = NO_SCAN_DELAY;
 }
}
*/

extern "C" void MakeNextStepScan2()
{
 SetFreq2();
 if(emb5ScanFreq2.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ += emb5ScanFreq2.emb5scanfreq.step;
   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
   curval2++;
 }
 else
 {
 modescan2 = 0; //start scan channel2
 delay2 = NO_SCAN_DELAY;
 }
}

#ifdef PROG_PRM_PCH_C

extern "C" void AlarmPmOn(void)
{
//printf("\n\r1");
 unsigned char data;
 data =  inportb(LED_PORT);
#ifdef PROG_PRM_PCH_S
 outportb(LED_PORT, (data & ALARM_INPUT));
#else
 outportb(LED_PORT, (data & ALARM_PM));
#endif


}



extern "C" void AlarmPmOff(void)
{
//printf("\n\r2");

 unsigned char data;
 data =  inportb(LED_PORT);
 #ifdef PROG_PRM_PCH_S
 outportb(LED_PORT, (data | NO_ALARM_INPUT));
 #else
 outportb(LED_PORT, (data | NO_ALARM_PM));
#endif
}

#ifdef PROG_PRM_PCH_S

extern "C" void AlarmPmOn2(void)
{
//printf("\n\r3");

 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_POWER));
}



extern "C" void AlarmPmOff2(void)
{
//printf("\n\r4");

 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_POWER));
}


#endif // PROG_PRM_PCH_S


extern "C" void CheckAlarmsPm(void)
{
 #ifndef PROG_PRM_PCH_S
 switch(inportb(POWER_PORT) & 0xF)
 {
  case 1:  if(countMod < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 2:  if(countTransit < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 4:  if(countPower < ENABLED_LOSS) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  default: AlarmPmOff(); 
 }

#else // PROG_PRM_PCH_S
 //printf("\n\r %d %d %d %d %d %d", fl1,fl2, fl3,fl4,fl5,fl6);
#ifndef  PROG_PRM_PCH_N
    switch(inportb(POWER_PORT) & 0xF)
 {
  case 1:  if(fl1) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 2:  if(fl2) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  case 4:  if(fl3) AlarmPmOff();
		   else	 AlarmPmOn();
		   break;
  default: AlarmPmOff(); 
 }



  switch(inportb(POWER_PORT2) & 0xF)
 {
  case 1:  if(fl4) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
  case 2:  if(fl5) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
  case 4:  if(fl6) AlarmPmOff2();
		   else	 AlarmPmOn2();
		   break;
//091113  default: AlarmPmOff(); 
  default: AlarmPmOff2();  //091113
 }
#else // PROG_PRM_PCH_N
   
#endif 	// PROG_PRM_PCH_N
#endif //	PROG_PRM_PCH_S
}



extern "C" void PrintMessages()
{
 switch (message)
 {
  case 1 : printf("\n\rpower on channel 1");  break;
  case 2 : printf("\n\rpower on channel 2");  break;
  case 3 : printf("\n\rpower on channel 3");  break;
  default : break;

 }
 if(message)  printf("\n\r m = %d" , message);
 message = 0;
}




extern "C" void SetPower(unsigned char channel)
{
// message = channel;
switch(channel)
{
 case 1:  outportb(POWER_PORT, CH1_MASK);  break;
 case 2:  outportb(POWER_PORT, CH2_MASK);  break;
 case 3:  outportb(POWER_PORT, CH3_MASK);  break;
#ifdef PROG_PRM_PCH_S
 case 4:  outportb(POWER_PORT2, CH4_MASK);  break;
 case 5:  outportb(POWER_PORT2, CH5_MASK);  break;
 case 6:  outportb(POWER_PORT2, CH6_MASK);  break;
#endif //PROG_PRM_PCH_S
 default : break;
}
}
#endif 	PROG_PRM_PCH_C

extern "C" void AlarmsOn1(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_MASK1));
}

extern "C" void AlarmsOff1(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_MASK1));
}

extern "C" void AlarmsOn2(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data & ALARM_MASK2));
}

extern "C" void AlarmsOff2(void)
{
 unsigned char data;
 data =  inportb(LED_PORT);
 outportb(LED_PORT, (data | NO_ALARM_MASK2));
}


#ifdef PRM_PCH_THREE_LINES

extern "C" void AlarmsOn3(void)
{
 unsigned char data;
 data =  inportb(LED_PORT3);
 outportb(LED_PORT3, (data & ALARM_MASK3));
}

extern "C" void AlarmsOff3(void)
{
 unsigned char data;
 data =  inportb(LED_PORT3);
 outportb(LED_PORT3, (data | NO_ALARM_MASK3));
}

extern "C" void ParseUD_3()	 //need make!
{
if(modescan3)
 {
 if(curval3 >= 0)
 {
   emb5StatusFrequScan3.emb5statusfrequscan.level[curval3] = ConvVal( (((unsigned short)embMsgUD_3.Body(2)&0x0F) << 8) + 	embMsgUD_3.Body(1));
 }
 else
 {
  }
  return;
 }
 if(start3) //100401		
 unEmb2TypeVer.emb2TypeVer.signature_hardware[6] = 1; //have power on 3
 switch(embMsgUD_3.Body(0))
 {
  case 0:  if(start3)
   {unEmb2TypeVer.emb2TypeVer.signature_hardware[4] = embMsgUD_3.Body(1) & DEVICE_TYPE_MASK; 
  		   Band3 = embMsgUD_3.Body(1);}	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever3.emb5statusreciever.status =  embMsgUD_3.Body(2) >> 4;
			emb5StatusReciever3.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_3.Body(2)&0x0F)  << 8) + 	embMsgUD_3.Body(1));
 		   	emb5StatusReciever3.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_3.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState3.emb5rpustate.temp =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.temp_min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.temp_max =  embMsgUD_3.Body(3);
  case 23:	emb5RPUState3.emb5rpustate.u48 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u48min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u48max =  embMsgUD_3.Body(3);
  case 24:	emb5RPUState3.emb5rpustate.u24 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u24min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u24max =  embMsgUD_3.Body(3);
  case 25:	emb5RPUState3.emb5rpustate.u7 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u7min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u7max =  embMsgUD_3.Body(3);
  case 26:	emb5RPUState3.emb5rpustate.u5 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u5min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u5max =  embMsgUD_3.Body(3);
  case 27:	emb5RPUState3.emb5rpustate.u_5 =  embMsgUD_3.Body(1);
			emb5RPUState3.emb5rpustate.u_5min =  embMsgUD_3.Body(2);
			emb5RPUState3.emb5rpustate.u_5max =  embMsgUD_3.Body(3);
#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[4] =  embMsgUD_3.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[6] =  embMsgUD_3.Body(1);	break;
 case 30:	WriteStatus3 = embMsgUD_3.Body(1); break;
 case 31:	ReadStatus3[0] = embMsgUD_3.Body(1); 
			ReadStatus3[1] = embMsgUD_3.Body(2); 
			ReadStatus3[2] = embMsgUD_3.Body(3); break;
  case 32:	ReadAtt3[0] = embMsgUD_3.Body(1); 
			ReadAtt3[1] = embMsgUD_3.Body(2); 
			ReadAtt3[2] = embMsgUD_3.Body(3); break;


#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan3()
{
 SetFreq3();
 if(emb5ScanFreq3.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ += emb5ScanFreq3.emb5scanfreq.step;
   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
   curval3++;
 }
 else
 {
 modescan3 = 0; //start scan channel2
 delay3 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette3(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette3 code: %d" , requestPower);
#endif// PRM_PCH_DEBUG
if(start3){ delay3 = ROULETTE_DELAY;}
   switch(requestPower++)
 {
   case 0: GetCode3();	break;
   case 1: GetCode3();	break; //GetLockLevel3();    		break;
   case 2: GetCode3();	break; //GetTemp3(); break;
   case 3: GetCode3();	break; //Get48_3(); break;
   case 4: GetCode3();	break; //Get24_3(); break;
   case 5: GetCode3();	break; //Get7_3();break;
   case 6: GetCode3();	break; //Get5_3(); break;
   case 7: GetCode3();	break; //Get5M_3(); break;
   case 9: if(!setf3) {SetFreq3(); setf3 = 1; break;} 	 return 0;
   case 8: if(!setatt3) {SetAtt3(); setatt3 = 1;  break;}    return 0;
#ifndef PROG_PRM_PCH_C
   default :  requestPower = 0; return 0;	  //to have cycle
#else  // PROG_PRM_PCH_C
   default :  	if(start3)
				{
#ifdef PROG_PRM_PCH_S
				ClearMod();
#endif
   			    outportb(POWER_PORT, 0);  
				requestPower = 11;
				delay3 = NO_SCAN_DELAY;
				start3 = 0;
				}
				else
				{
					requestPower = 11;
				}
				return 0;
#endif	// PROG_PRM_PCH_C
 }

  return 1;
}

extern "C" void  SetFreq3()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ,Band3);
 if((b2_keep & 0xf) != (b[2] & 0xf)) 
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_3.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}
extern "C" void  SetAtt3()
{

				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_3.SetLength(2); //?????
				embMsgUDRequest_3.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_3.SetBody(1, emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  GetCode3()
{
 			embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  GetLockLevel3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  GetTemp3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  Get48_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get24_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}


extern "C" void  Get7_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get5_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

extern "C" void  Get5M_3()
{
				embMsgUDRequest_3.Init();
				embMsgUDRequest_3.SetAddr(0);//
				embMsgUDRequest_3.SetLength(1); //?????
				embMsgUDRequest_3.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_3.CalcCRC();
				embMsgUDRequest_3.SetReadyToSend();
}

#endif //PRM_PCH_THREE_LINES

#ifdef PRM_PCH_SIX_LINES
//____________________________________________________________________________>>_4
extern "C" void ParseUD_4()	 //need make!
{

if(modescan4)
 {
 if(curval4 >= 0)
 {
   emb5StatusFrequScan4.emb5statusfrequscan.level[curval4] = ConvVal( (((unsigned short)embMsgUD_4.Body(2)&0x0F) << 8) + 	embMsgUD_4.Body(1));
 }
 else
 {
  }
  return;
 }
 if(start4) //100401		
 unEmb2TypeVer.emb2TypeVer.signature_hardware[3] = 1; //have power on 4
 switch(embMsgUD_4.Body(0))
 {
  case 0: if(start4)
   {unEmb2TypeVer.emb2TypeVer.signature_hardware[1] = embMsgUD_4.Body(1) & DEVICE_TYPE_MASK; 
  		  Band4 = embMsgUD_4.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever4.emb5statusreciever.status =  embMsgUD_4.Body(2) >> 4;
			emb5StatusReciever4.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_4.Body(2)&0x0F)  << 8) + 	embMsgUD_4.Body(1));
 		   	emb5StatusReciever4.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_4.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState4.emb5rpustate.temp =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.temp_min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.temp_max =  embMsgUD_4.Body(3);
  case 23:	emb5RPUState4.emb5rpustate.u48 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u48min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u48max =  embMsgUD_4.Body(3);
  case 24:	emb5RPUState4.emb5rpustate.u24 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u24min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u24max =  embMsgUD_4.Body(3);
  case 25:	emb5RPUState4.emb5rpustate.u7 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u7min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u7max =  embMsgUD_4.Body(3);
  case 26:	emb5RPUState4.emb5rpustate.u5 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u5min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u5max =  embMsgUD_4.Body(3);
  case 27:	emb5RPUState4.emb5rpustate.u_5 =  embMsgUD_4.Body(1);
			emb5RPUState4.emb5rpustate.u_5min =  embMsgUD_4.Body(2);
			emb5RPUState4.emb5rpustate.u_5max =  embMsgUD_4.Body(3);
#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[1] =  embMsgUD_4.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[3] =  embMsgUD_4.Body(1);	break;

  case 30:	WriteStatus4 = embMsgUD_4.Body(1); break;
  case 31:	ReadStatus4[0] = embMsgUD_4.Body(1); 
			ReadStatus4[1] = embMsgUD_4.Body(2); 
			ReadStatus4[2] = embMsgUD_4.Body(3); break;
  case 32:	ReadAtt4[0] = embMsgUD_4.Body(1); 
			ReadAtt4[1] = embMsgUD_4.Body(2); 
			ReadAtt4[2] = embMsgUD_4.Body(3); break;

#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan4()
{
 SetFreq4();
 if(emb5ScanFreq4.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ += emb5ScanFreq4.emb5scanfreq.step;
   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
   curval4++;
 }
 else
 {
 modescan4 = 0; //start scan channel2
 delay4 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette4(void)
{
//unsigned char tmp;

#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette4 code: %d" , requestTransit4);
#endif// PRM_PCH_DEBUG
if(start4){ delay4 = ROULETTE_DELAY;}
   switch(requestTransit4++)
 {
   case 0:  GetCode4();	break;
   case 1:  GetCode4(); break; //GetLockLevel4();	     		break;
   case 2:  GetCode4(); break; //GetTemp4(); break;
   case 3:  GetCode4(); break; //Get48_4(); break;
   case 4:  GetCode4(); break; //Get24_4(); break;
   case 5:  GetCode4(); break; //Get7_4();break;
   case 6:  GetCode4(); break; //Get5_4(); break;
   case 7:  GetCode4(); break; //Get5M_4(); break;
   case 9: if(!setf4) {SetFreq4(); setf4 = 1; break;} 	 return 0;
   case 8: if(!setatt4) {SetAtt4(); setatt4 = 1;  break;}    return 0;
   default :  	if(start4)
				{
#ifdef PROG_PRM_PCH_S
				ClearTransit();
#endif
   				outportb(POWER_PORT2, CH5_MASK);  
				requestTransit4 = 11;
				start4 = 0;
				delay4 = NO_SCAN_DELAY;
				delay5 = time1 + START_TIMEOUT;
				}
				else
				{
					requestTransit4 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq4()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ,Band4);
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_4.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}
extern "C" void  SetAtt4()
{

				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_4.SetLength(2); //?????
				embMsgUDRequest_4.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_4.SetBody(1, emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  GetCode4()
{
 			embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  GetLockLevel4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  GetTemp4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  Get48_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get24_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


extern "C" void  Get7_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get5_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}

extern "C" void  Get5M_4()
{
				embMsgUDRequest_4.Init();
				embMsgUDRequest_4.SetAddr(0);//
				embMsgUDRequest_4.SetLength(1); //?????
				embMsgUDRequest_4.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_4.CalcCRC();
				embMsgUDRequest_4.SetReadyToSend();
}


//____________________________________________________________________________<<_4

//____________________________________________________________________________>>_5


extern "C" void ParseUD_5()	 //need make!
{

if(modescan5)
 {
 if(curval5 >= 0)
 {
   emb5StatusFrequScan5.emb5statusfrequscan.level[curval5] = ConvVal( (((unsigned short)embMsgUD_5.Body(2)&0x0F) << 8) + 	embMsgUD_5.Body(1));
 }
 else
 {
  }
  return;
 }		


 if(start5) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[11] = 1; //have power on 5
 switch(embMsgUD_5.Body(0))
 {
  case 0:  if(start5)
   { unEmb2TypeVer.emb2TypeVer.signature_hardware[9] = embMsgUD_5.Body(1) & DEVICE_TYPE_MASK; 
  		   Band5 = embMsgUD_5.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever5.emb5statusreciever.status =  embMsgUD_5.Body(2) >> 4;
			emb5StatusReciever5.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_5.Body(2)&0x0F)  << 8) + 	embMsgUD_5.Body(1));
 		   	emb5StatusReciever5.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_5.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState5.emb5rpustate.temp =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.temp_min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.temp_max =  embMsgUD_5.Body(3);
  case 23:	emb5RPUState5.emb5rpustate.u48 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u48min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u48max =  embMsgUD_5.Body(3);
  case 24:	emb5RPUState5.emb5rpustate.u24 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u24min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u24max =  embMsgUD_5.Body(3);
  case 25:	emb5RPUState5.emb5rpustate.u7 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u7min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u7max =  embMsgUD_5.Body(3);
  case 26:	emb5RPUState5.emb5rpustate.u5 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u5min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u5max =  embMsgUD_5.Body(3);
  case 27:	emb5RPUState5.emb5rpustate.u_5 =  embMsgUD_5.Body(1);
			emb5RPUState5.emb5rpustate.u_5min =  embMsgUD_5.Body(2);
			emb5RPUState5.emb5rpustate.u_5max =  embMsgUD_5.Body(3);
#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[9] =  embMsgUD_5.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[11] =  embMsgUD_5.Body(1);	break;

 case 30:	WriteStatus5 = embMsgUD_5.Body(1); break;
 case 31:	ReadStatus5[0] = embMsgUD_5.Body(1); 
			ReadStatus5[1] = embMsgUD_5.Body(2); 
			ReadStatus5[2] = embMsgUD_5.Body(3); break;
  case 32:	ReadAtt5[0] = embMsgUD_5.Body(1); 
			ReadAtt5[1] = embMsgUD_5.Body(2); 
			ReadAtt5[2] = embMsgUD_5.Body(3); break;


#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan5()
{
 SetFreq5();
 if(emb5ScanFreq5.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ += emb5ScanFreq5.emb5scanfreq.step;
   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
   curval5++;
 }
 else
 {
 modescan5 = 0; //start scan channel2
 delay5 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette5(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette5 code: %d" , requestTransit5);
#endif// PRM_PCH_DEBUG
  if(start5){ delay5 = ROULETTE_DELAY;}
   switch(requestTransit5++)
 {
   case 0: GetCode5();	break;
   case 1: GetCode5();	break; //GetLockLevel5();	break;
   case 2: GetCode5();	break; //GetTemp5(); break;
   case 3: GetCode5();	break; //Get48_5(); break;
   case 4: GetCode5();	break; //Get24_5(); break;
   case 5: GetCode5();	break; //Get7_5();break;
   case 6: GetCode5();	break; //Get5_5(); break;
   case 7: GetCode5();	break; //Get5M_5(); break;
   case 9: if(!setf5) {SetFreq5(); setf5 = 1; break;} 	 return 0;
   case 8: if(!setatt5) {SetAtt5(); setatt5 = 1;  break;}    return 0;
   default :  	if(start5)
				{
#ifdef PROG_PRM_PCH_S
				ClearTransit();
#endif
   			 	outportb(POWER_PORT2, CH6_MASK);  
				requestTransit5 = 11;
				start5 = 0;
				delay5 = NO_SCAN_DELAY;
				delay6 = time1 + START_TIMEOUT;
				}
				else
				{
					requestTransit5 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq5()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ,Band5);
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_5.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}
extern "C" void  SetAtt5()
{

				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_5.SetLength(2); //?????
				embMsgUDRequest_5.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_5.SetBody(1, emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  GetCode5()
{
 			embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  GetLockLevel5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  GetTemp5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  Get48_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get24_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


extern "C" void  Get7_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get5_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}

extern "C" void  Get5M_5()
{
				embMsgUDRequest_5.Init();
				embMsgUDRequest_5.SetAddr(0);//
				embMsgUDRequest_5.SetLength(1); //?????
				embMsgUDRequest_5.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_5.CalcCRC();
				embMsgUDRequest_5.SetReadyToSend();
}


//____________________________________________________________________________<<_5

//____________________________________________________________________________>>_6


extern "C" void ParseUD_6()	 //need make!
{

if(modescan6)
 {
 if(curval6 >= 0)
 {
   emb5StatusFrequScan6.emb5statusfrequscan.level[curval6] = ConvVal( (((unsigned short)embMsgUD_6.Body(2)&0x0F) << 8) + 	embMsgUD_6.Body(1));
 }
 else
 {
  }
  return;
 }		


 if(start6) //100401
 unEmb2TypeVer.emb2TypeVer.signature_hardware[7] = 1; //have power on 6
 switch(embMsgUD_6.Body(0))
 {
  case 0: if(start6)
  { unEmb2TypeVer.emb2TypeVer.signature_hardware[5] = embMsgUD_6.Body(1) & DEVICE_TYPE_MASK; 
  		  Band6 = embMsgUD_6.Body(1); }	break;	   //hardvare 0
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 20:
  case 21: 	emb5StatusReciever6.emb5statusreciever.status =  embMsgUD_6.Body(2) >> 4;
			emb5StatusReciever6.emb5statusreciever.signalLevel =  ConvVal( (((unsigned short)embMsgUD_6.Body(2)&0x0F)  << 8) + 	embMsgUD_6.Body(1));
 		   	emb5StatusReciever6.emb5statusreciever.stepAtt =  MakeAttBack(embMsgUD_6.Body(3));  //	break;
			break;	   //for test
  case 22:	emb5RPUState6.emb5rpustate.temp =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.temp_min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.temp_max =  embMsgUD_6.Body(3);
  case 23:	emb5RPUState6.emb5rpustate.u48 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u48min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u48max =  embMsgUD_6.Body(3);
  case 24:	emb5RPUState6.emb5rpustate.u24 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u24min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u24max =  embMsgUD_6.Body(3);
  case 25:	emb5RPUState6.emb5rpustate.u7 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u7min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u7max =  embMsgUD_6.Body(3);
  case 26:	emb5RPUState6.emb5rpustate.u5 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u5min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u5max =  embMsgUD_6.Body(3);
  case 27:	emb5RPUState6.emb5rpustate.u_5 =  embMsgUD_6.Body(1);
			emb5RPUState6.emb5rpustate.u_5min =  embMsgUD_6.Body(2);
			emb5RPUState6.emb5rpustate.u_5max =  embMsgUD_6.Body(3);
#ifdef PROG_PRM_PCH_L_61
  case 28:	unEmb2TypeVer.emb2TypeVer.signature_software[5] =  embMsgUD_6.Body(1);	break;
  case 29:	unEmb2TypeVer.emb2TypeVer.signature_software[7] =  embMsgUD_6.Body(1);	break;

  case 30:	WriteStatus6 = embMsgUD_6.Body(1); break;
  case 31:	ReadStatus6[0] = embMsgUD_6.Body(1); 
			ReadStatus6[1] = embMsgUD_6.Body(2); 
			ReadStatus6[2] = embMsgUD_6.Body(3); break;
  case 32:	ReadAtt6[0] = embMsgUD_6.Body(1); 
			ReadAtt6[1] = embMsgUD_6.Body(2); 
			ReadAtt6[2] = embMsgUD_6.Body(3); break;

#endif	// PROG_PRM_PCH_L_61

  default : break;

 }
}

extern "C" void MakeNextStepScan6()
{
 SetFreq6();
 if(emb5ScanFreq6.emb5scanfreq.numOfStep--)
 {
   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ += emb5ScanFreq6.emb5scanfreq.step;
   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
   curval6++;
 }
 else
 {
 modescan6 = 0; //start scan channel2
 delay6 = NO_SCAN_DELAY;
 }
}

extern "C" unsigned char Roulette6(void)
{
//unsigned char tmp;
#ifdef PRM_PCH_DEBUG
// printf("\n\rroulette6 code: %d" , requestTransit6);
#endif// PRM_PCH_DEBUG
  if(start6){ delay6 = ROULETTE_DELAY;}
   switch(requestTransit6++)
 {
   case 0: GetCode6();	break;
   case 1: GetCode6();	break;//GetLockLevel6();    		break;
   case 2: GetCode6();	break;//GetTemp6(); break;
   case 3: GetCode6();	break;//Get48_6(); break;
   case 4: GetCode6();	break;//Get24_6(); break;
   case 5: GetCode6();	break;//Get7_6();break;
   case 6: GetCode6();	break;//Get5_6(); break;
   case 7: GetCode6(); 	break;//Get5M_6(); break;
   case 9: if(!setf6) {SetFreq6(); setf6 = 1; break;} 	 return 0;
   case 8: if(!setatt6) {SetAtt6(); setatt6 = 1;  break;}    return 0;
   default :  	if(start6)
				{
#ifdef PROG_PRM_PCH_S
				ClearTransit();
#endif
   			    outportb(POWER_PORT2, 0);  
				requestTransit6 = 11;
				delay6 = NO_SCAN_DELAY;
				start6 = 0;
				}
				else
				{
					requestTransit6 = 11;
				}
				return 0;

 }
  return 1;
}

extern "C" void  SetFreq6()
{
static unsigned char b2_keep = 0;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ,Band6);
 if((b2_keep & 0xf) != (b[2] & 0xf))
 {
	b2_keep = b[2]; timewait = (unsigned long)LONG_RUN_TIME;
 }

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(FORMULA_LEN); //?????
				for(long i = 0; i < FORMULA_LEN; i++)
				{
  				 embMsgUDRequest_6.SetBody(i,  b[i]);	//temporary
				}
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}
extern "C" void  SetAtt6()
{

				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_6.SetLength(2); //?????
				embMsgUDRequest_6.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_6.SetBody(1, emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  GetCode6()
{
 			embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_CODE);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  GetLockLevel6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_LOCK_LEVEL);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  GetTemp6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_TEMP);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  Get48_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_48);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get24_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_24);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}


extern "C" void  Get7_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_7);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get5_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_5);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}

extern "C" void  Get5M_6()
{
				embMsgUDRequest_6.Init();
				embMsgUDRequest_6.SetAddr(0);//
				embMsgUDRequest_6.SetLength(1); //?????
				embMsgUDRequest_6.SetBody(0,CODE_5M);	//
			   	embMsgUDRequest_6.CalcCRC();
				embMsgUDRequest_6.SetReadyToSend();
}
//____________________________________________________________________________<<_6
#endif //PRM_PCH_SIX_LINES

#ifdef 	PROG_PRM_PCH_L


extern "C" unsigned long GetAttRPU(unsigned char num)
{
switch(num)
{
case 1:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 2:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 3:    return unEmb2TypeVer.emb2TypeVer.signature_software[12];
case 4:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];
case 5:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];
case 6:    return unEmb2TypeVer.emb2TypeVer.signature_software[13];


default :  return 0;
}
}


extern "C" void RestoreFreq(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever1.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
		   break;
case 2:	   emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever2.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
		   break;
case 3:	   emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever3.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
		   break;
case 4:    emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever4.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
		   break;
case 5:	   emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever5.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
		   break;
case 6:	   emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ = val;
   		   emb5StatusReciever6.emb5statusreciever.frequ =  emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;
		   break;


default :  break;
}
}

extern "C" void RestoreAtt(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:     emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt =  val;
   	   //		emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 2:	    emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 3:	    emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 4:     emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt =  val;
   	   //		emb5StatusReciever1.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 5:	    emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever2.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;   
 	   		break;
case 6:	    emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt =  val;
   	 //		emb5StatusReciever3.emb5statusreciever.stepAtt =  emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;   
 	   		break;

default :  break;
}
}

extern "C" void RestoreAttRPU(unsigned char num, unsigned long val)
{
switch(num)
{
case 1:   	unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
		    emb5CommandRPUSetAtt1.emb5commandrpusetatt.stepAtt =  val>>1;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	   //		SetAttRPU1();


 	   		break;
case 2:	    emb5CommandRPUSetAtt2.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	   //		SetAttRPU2();
			unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
 	   		break;
case 3:	    emb5CommandRPUSetAtt3.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[12] = val>>1;
	  //		SetAttRPU3();
			unEmb2TypeVer.emb2TypeVer.signature_software[12] = val;
 	   		break;
case 4:     emb5CommandRPUSetAtt4.emb5commandrpusetatt.stepAtt =  val>>1;
   			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	   //		SetAttRPU1();
		   unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;

 	   		break;
case 5:	    emb5CommandRPUSetAtt5.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	   //		SetAttRPU2();
			unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;
 	   		break;
case 6:	    emb5CommandRPUSetAtt6.emb5commandrpusetatt.stepAtt =  val>>1;
			unEmb2TypeVer.emb2TypeVer.signature_hardware[13] = val>>1;
	  //		SetAttRPU3();
			unEmb2TypeVer.emb2TypeVer.signature_software[13] = val;
 	   		break;

default :  break;
}
}


extern "C" unsigned long GetFreq(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
case 2:    return emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ;
case 3:    return emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ;
case 4:    return emb5CommandRecieverSetFrequ4.emb5commandrecieversetfrequ.frequ;
case 5:    return emb5CommandRecieverSetFrequ5.emb5commandrecieversetfrequ.frequ;
case 6:    return emb5CommandRecieverSetFrequ6.emb5commandrecieversetfrequ.frequ;



default :  return 0;
}
}

extern "C" unsigned long GetAtt(unsigned char num)
{
switch(num)
{
case 1:    return emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt;
case 2:    return emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt;
case 3:    return emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt;
case 4:    return emb5CommandRecieverSetAtt4.emb5commandrecieversetatt.stepAtt;
case 5:    return emb5CommandRecieverSetAtt5.emb5commandrecieversetatt.stepAtt;
case 6:    return emb5CommandRecieverSetAtt6.emb5commandrecieversetatt.stepAtt;



default :  return 0;
}
}



extern "C" void MakeKeepTest(void)
{
    printf("\n\r freq1 = %lX att1 = %lX", emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);
    printf("\n\r freq2 = %lX att2 = %lX", emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt);
    printf("\n\r freq3 = %lX att3 = %lX", emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ, emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt);
    emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = 0x12345671;
    emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt = 0x12345672;
    emb5CommandRecieverSetFrequ2.emb5commandrecieversetfrequ.frequ  = 0x12345673;
    emb5CommandRecieverSetAtt2.emb5commandrecieversetatt.stepAtt  = 0x12345674;
    emb5CommandRecieverSetFrequ3.emb5commandrecieversetfrequ.frequ  = 0x12345675;
    emb5CommandRecieverSetAtt3.emb5commandrecieversetatt.stepAtt   = 0x12345676;
	SetNeedWriteDevId();
}




#endif // PROG_PRM_PCH_L

extern "C" void SetNeedWriteDevId(void)
{
//printf("\n\rSetWriteDevId");

  NeedWriteID = 1;

#ifdef PRM_L_KEEP_FREQ
DelayWriteTime = time1;
#endif

}

extern "C" void ClearNeedWriteDevId(void)
{
  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{

#ifdef PRM_L_KEEP_FREQ

  if(DelayWriteTime > time1)
  {

     DelayWriteTime = time1;
  }

  if((time1 - DelayWriteTime) < DELAY_TIME_TO_WRITE)
  {
   return 0;
   }
  #endif
 // if(NeedWriteID) printf("\n\rWriteDevId"); //t


  return NeedWriteID;
}



#ifdef PROG_PRM_PCH_N
unsigned char SetFreqN(unsigned short freq)
{
 emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ = freq;

unsigned char * b = Formula9(emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ); //
//____________________________________________________________________________
//	printf("\n\r freq1 = %ld" , emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ);
//____________________________________________________________________________
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//emgUDRequest_1.Init();
 		     	embMsgUDRequest_1.SetLength(FORMULA_LEN); //em
			    for(long i = 0; i < FORMULA_LEN; i++)
				{
				 embMsgUDRequest_1.SetBody(i , b[i]);	//temporary
				}
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReadyToSend();

//_________________________________________
   breakflag = 0;
   timerun = time1;
  while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________

return breakflag;
}

unsigned char SetAttN(unsigned char att)
{
				embMsgUDRequest_1.Init();
				embMsgUDRequest_1.SetAddr(0);//embMsg.Body(0));
				embMsgUDRequest_1.SetLength(2); //?????
				embMsgUDRequest_1.SetBody(0,CODE_SET_ATT);	//
			    embMsgUDRequest_1.SetBody(1, emb5CommandRecieverSetAtt1.emb5commandrecieversetatt.stepAtt);	//
		  		embMsgUDRequest_1.CalcCRC();
				embMsgUDRequest_1.SetReaeaToSend();

//_________________________________________
   breakflag = 0;
   timerun = time1;
	while((time1-timerun) < RUN_TIME)
	{
	  if(breakflag) break;
  //	  message++; 
	  PRM_PCH();
	}
//_________________________________________
 return breakflag;
}

unsigned char GetLevN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.signalLevel;
}

unsigned char GetAttN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.stepAtt;
}

unsigned short GetFreqN(void)
{
  return  emb5CommandRecieverSetFrequ1.emb5commandrecieversetfrequ.frequ;
}

unsigned short GetLockN(void)
{
  return  emb5StatusReciever1.emb5statusreciever.lock;
}

unsigned char GetAlarmN(void)
{
 if(fl1)
 return 0;
 else return 1;
}

void TransN(unsigned char send)
{
  embRS485.Trans(send);
}




#endif	 //PROG_PRM_PCH_N

extern "C" unsigned char device_found(unsigned char channel)
{
 switch(channel)
 {
  case 1 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[2])	 return 1; 
  case 2 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[10])	 return 1;
  case 3 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[6])	 return 1;
  case 4 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[3])	 return 1;
  case 5 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[11])	 return 1;
  case 6 : if(unEmb2TypeVer.emb2TypeVer.signature_hardware[7])	 return 1;
  default: return 0;
 }
}

extern "C" void print_signature(void)
{
  printf("\n\r");
  for(i=0; i<16; i++)
	{
	  printf(" %02X",	unEmb2TypeVer.emb2TypeVer.signature_hardware[i]);
	}
}






