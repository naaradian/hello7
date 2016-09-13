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
                                                           
//  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 

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
  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 
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
                                                           
//  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 

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
  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 
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
                                                           
//  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 

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
  01H, 0ABH, 45H              ;;;26,6 МГц 22 22 22 22 22 22 (опора 100 МГЦ) 
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

struct TOM // [TRС00MEK]
{
	unsigned char K : 1; // K - признак получения пакета адресатом, устанавливается в "1" при получении пакета адресатом;
	unsigned char E : 1; // E - бит ошибки в CRC, устанавливается в "1" если не сходится CRC;
	unsigned char M : 1; // M - бит монитора, устанавливаемый в "1" при проходе кадром "активного монитора";
	unsigned char reserved : 2;
	unsigned char C : 1; // R - признак сообщение из RS-485 (был запрос маркера)
	unsigned char R : 1; // C - устанавливается в "1" если это запрос компьютера подключенного к станции.
	unsigned char T : 1; // T - бит маркера; 
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
	void SetDir(unsigned char d) { dir= d; } // dir = 1 пришел с West, dir=2 прищел с East
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
/////////////////////
/*
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
*/
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

////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0;
unsigned long cntflag6;


void Callback0()
{
  time1++;
}



DmuStatusu dmustatusu;
DmuStatusu dmustatusu2;
DmuStatusu dmustatusu3;
DmuStatusu dmustatusu4;





EmbTimerCallback embTimerCallback0;
EmbRS232 embRS232;
EmbRS485 embRS485;

 
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
	unsigned long time1test=0;
	unsigned short HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];
    unsigned char * bt;
	unsigned short addr1;
	unsigned char byte;//, westByte, eastByte;
 	unsigned char mode5A=0;//, mode5AWest=0, mode5AEast=0;
 //	unsigned char mode5A232E = 0;
	unsigned char mode5A485E = 0;
	unsigned char mode5A485 = 0;
	unsigned char cycle=0;
	unsigned char ttbb=0;
	unsigned char mtbb=0;
	UnEmb2TypeVer unEmb2TypeVer; 
	long err_tmp;
	int rrr=0;
	int i232;

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
unsigned char NeedWriteID;
unsigned char test_shift_mode;
#ifdef PRM_L_KEEP_FREQ
unsigned long DelayWriteTime;
#endif

unsigned char beforemodulsk;


unsigned long decoder0, test0;
unsigned long decoder1, test1;
unsigned long decoder2, test2;
unsigned long decoder3, test3;

unsigned char flag_write_flash;



/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
extern "C" void Init_PRM_PCH(void)
{
  flag_write_flash = 0;

  /*
  if(GetTestMode() != 0xAA)
  {
  if(ChkDem(CNL1) && ChkDem(CNL2)) //two dem
  {
   if(CheckDoneShort() && CheckDoneShort2() && CheckDoneShort3() && CheckDoneShort4())
   {
     return;
   }
  }

 if((!(ChkDem(CNL1))) && ChkDem(CNL2)) // dem2
  {
   if(CheckDoneShort3() && CheckDoneShort4())
   {
     return;
   }
  }

if((!(ChkDem(CNL2))) && ChkDem(CNL1)) //dem1
  {
   if(CheckDoneShort() && CheckDoneShort2())
   {
     return;
   }
  }
  }		  //no 0xAA

	*/

 SetSelector(CNL1);
 m_load_xilinx5(3,0); //load xil 3,4 to file 3
 m_load_xilinx4(1,0);
 CheckDoneShort();
 CheckDoneShort2();
 
  SetSelector(CNL2);
  m_load_xilinx5(3,0); //load xil 3,4 to file 3	   is reseted
  m_load_xilinx4(1,0);
  CheckDoneShort3();
  CheckDoneShort4();
 /*
  SetSelector(CNL3);
  m_load_xilinx5(3,0); //load xil 3,4 to file 3	   is reseted
  m_load_xilinx4(1,0);
  CheckDoneShort5();
  CheckDoneShort6();

  SetSelector(CNL4);
  m_load_xilinx5(3,0); //load xil 3,4 to file 3	   is reseted
  m_load_xilinx4(1,0);
  CheckDoneShort7();
  CheckDoneShort8();
	*/

 //return;

//ok  return; //t
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

//#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU3
if(!CheckSymbolRate(GetSymbolRate2()))
{SetSymbolRate2(MAX_SYMBOL_RATE);}

if(!CheckFreqPCh(GetFreqPCh2()))
{SetFreqPCh2(MAX_FREQPCH2);}

if(!CheckModulSK(GetModulSK2()))
{SetModulSK2(MODUL7);}
 /*
if(!CheckSymbolRate(GetSymbolRate3()))
{SetSymbolRate3(MAX_SYMBOL_RATE);}

if(!CheckFreqPCh(GetFreqPCh3()))
{SetFreqPCh3(MAX_FREQPCH2);}

if(!CheckModulSK(GetModulSK3()))
{SetModulSK3(MODUL7);}


if(!CheckSymbolRate(GetSymbolRate4()))
{SetSymbolRate4(MAX_SYMBOL_RATE);}

if(!CheckFreqPCh(GetFreqPCh4()))
{SetFreqPCh4(MAX_FREQPCH2);}

if(!CheckModulSK(GetModulSK4()))
{SetModulSK4(MODUL7);}
   */
//#endif
 NeedWriteID = 0;
 test_shift_mode = 0;

AsciiInit();
EmbInit(); //my
  time1=0;

  flagRequest=0;
 // serr=0xFF; crc_temp=0;
  i=0;
  timerun=0;
  breakflag = 0;
   request1=0; request2=0;
  time1test=0;
  HighID=0; countSend=0; countRecv=0;
  time3highID=0;
  mode5A=0; //mode5AWest=0; mode5AEast=0; 
 // mode5A232E = 0;  //1021
  mode5A485E = 0;  //1021
  mode5A485  = 0;  //1021
  cycle=0;
	ttbb=0;
	mtbb=0;
	rrr=0;
   //	embSerialACT155.Init();
    embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

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


//ok return; //150417


 //  unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = 1; //temporaru now one channel
   unEmb2TypeVer.emb2TypeVer.signature_hardware[0] = 2; //temporaru now two channels

   /*
   unEmb2TypeVer.emb2TypeVer.signature_software[0] =  GetSymbolRate();
   unEmb2TypeVer.emb2TypeVer.signature_software[1] =  GetSymbolRate() >> 8;
   unEmb2TypeVer.emb2TypeVer.signature_software[2] =  GetSymbolRate() >> 16;
   unEmb2TypeVer.emb2TypeVer.signature_software[3] =  GetSymbolRate() >> 24;
   unEmb2TypeVer.emb2TypeVer.signature_software[4] =  GetFreqPCh();
   unEmb2TypeVer.emb2TypeVer.signature_software[5] =  GetFreqPCh() >> 8;
   unEmb2TypeVer.emb2TypeVer.signature_software[6] =  GetFreqPCh() >> 16;
   unEmb2TypeVer.emb2TypeVer.signature_software[7] =  GetFreqPCh() >> 24;
   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  GetModulSK();
   */

//ok  return;
 beforemodulsk = 0xff; //
// LoadModulSK();
// return;


// printfp("\n\r1 ");


 LoadModulSKB(CNL1);
 LoadModulSKB(CNL2);
/*
 LoadModulSKB(CNL3);
 LoadModulSKB(CNL4);
 */

//printfp("\n\r2 ");

 LoadDDSs();

//printfp("\n\r2a ");
  
  /* this maked in loaddds
  SetSelector(CNL1);	
  LoadFreqPCh(GetFreqPCh());
  LoadSymbolRate(GetSymbolRate2());	 	
  SetSelector(CNL2);	
  LoadFreqPCh(GetFreqPCh2());
  LoadSymbolRate(GetSymbolRate2());	 
   */	

   	   

/* 
 SetSelector(CNL1);
 m_load_xilinx5(3,0); //load xil 3,4 to file 3
 m_load_xilinx4(1,0);
 
   SetSelector(CNL2);
 m_load_xilinx5(3,0); //load xil 3,4 to file 3
 m_load_xilinx4(1,0);
  	
 */

 LoadBaud(GetSymbolRate(), CNL1);

//printfp("\n\r2b ");

 LoadBaud(GetSymbolRate2(), CNL2);

//printfp("\n\r3 ");
   /*
 LoadBaud(GetSymbolRate3(), CNL3);
 LoadBaud(GetSymbolRate4(), CNL4);
	  */

 SetDecAndTest(CNL1);
 SetDecAndTest(CNL2);
  /*
 SetDecAndTest(CNL3);
 SetDecAndTest(CNL4);
	  */
// if(decoder0) LoadRam(CNL1);
// if(decoder1)  LoadRam(CNL2);
// if(decoder2)  LoadRam(CNL3);
// if(decoder3)  LoadRam(CNL4);	 
//KeepDmu();	  //t

//printfp("\n\r4 ");

RestoreDmu();


LoadBacoDmu(1);
LoadBacoStartZero();



}

extern "C" void ReadFlashToRam(unsigned long , unsigned long );

//qam512
#define   ADDRH_MODUL9 (0)
#define   ADDRM_MODUL9 (0)
#define   ADDRL_MODUL9 (0)
#define   ADDRF_MODUL9 (0xC0500000l + ADDR9 + SIZE_ABS9)
#define   SIZEF_MODUL9 (524288) //two blocks together

#define   ADDRH1_MODUL9 (0xC)
#define   ADDRM1_MODUL9 (0x08)
#define   ADDRL1_MODUL9 (0)
#define   ADDRF1_MODUL9 (0xC0500000l + ADDR9)
#define   SIZEF1_MODUL9 (SIZE_ABS9) //two blocks together

#define   ADDRH12_MODUL9 (0xC)
#define   ADDRM12_MODUL9 (0xC)
#define   ADDRL12_MODUL9 (0)



//qam256
#define   ADDRH_MODUL8 (8)
#define   ADDRM_MODUL8 (0)
#define   ADDRL_MODUL8 (0)
#define   ADDRF_MODUL8 (0xC0500000l + ADDR8 + SIZE_ABS8)
#define   SIZEF_MODUL8 (65536) //two blocks together

#define   ADDRH1_MODUL8 (0xC)
#define   ADDRM1_MODUL8 (0x10)
#define   ADDRL1_MODUL8 (0)
#define   ADDRF1_MODUL8 (0xC0500000l + ADDR8)
#define   SIZEF1_MODUL8 (SIZE_ABS8) //two blocks together


//qam128
#define   ADDRH_MODUL7 (9)
#define   ADDRM_MODUL7 (0)
#define   ADDRL_MODUL7 (0)
#define   ADDRF_MODUL7 (0xC0500000l + ADDR7 + SIZE_ABS7)
#define   SIZEF_MODUL7 (16384) //two blocks together

#define   ADDRH1_MODUL7 (0xC)
#define   ADDRM1_MODUL7 (0x11)
#define   ADDRL1_MODUL7 (0)
#define   ADDRF1_MODUL7 (0xC0500000l + ADDR7)
#define   SIZEF1_MODUL7 (SIZE_ABS7) //two blocks together

//qam64
#define   ADDRH_MODUL6 (0xA)
#define   ADDRM_MODUL6 (0)
#define   ADDRL_MODUL6 (0)
#define   ADDRF_MODUL6 (0xC0500000l + ADDR6 + SIZE_ABS6)
#define   SIZEF_MODUL6 (4096) //two blocks together

#define   ADDRH1_MODUL6 (0xC)
#define   ADDRM1_MODUL6 (0x12)
#define   ADDRL1_MODUL6 (0)
#define   ADDRF1_MODUL6 (0xC0500000l + ADDR6)
#define   SIZEF1_MODUL6 (SIZE_ABS6) //two blocks together



//qam32
#define   ADDRH_MODUL5 (0xA)
#define   ADDRM_MODUL5 (0x10)
#define   ADDRL_MODUL5 (0)
#define   ADDRF_MODUL5 (0xC0500000l + ADDR5 + SIZE_ABS5)
#define   SIZEF_MODUL5 (1024) //two blocks together

#define   ADDRH1_MODUL5 (0xC)
#define   ADDRM1_MODUL5 (0x13)
#define   ADDRL1_MODUL5 (0)
#define   ADDRF1_MODUL5 (0xC0500000l + ADDR5)
#define   SIZEF1_MODUL5 (SIZE_ABS5) //two blocks together


//qam16
#define   ADDRH_MODUL4 (0xA)
#define   ADDRM_MODUL4 (0x20)
#define   ADDRL_MODUL4 (0)
#define   ADDRF_MODUL4 (0xC0500000l + ADDR4 + SIZE_ABS4)
#define   SIZEF_MODUL4 (256) //two blocks together

#define   ADDRH1_MODUL4 (0xC)
#define   ADDRM1_MODUL4 (0x14)
#define   ADDRL1_MODUL4 (0)
#define   ADDRF1_MODUL4 (0xC0500000l + ADDR4)
#define   SIZEF1_MODUL4 (SIZE_ABS4) //two blocks together


//oqpsk
#define   ADDRH_MODUL3 (0xA)
#define   ADDRM_MODUL3 (0x30)
#define   ADDRL_MODUL3 (0)
#define   ADDRF_MODUL3 (0xC0500000l + ADDR3 + SIZE_ABS3)
#define   SIZEF_MODUL3 (16) //two blocks together

#define   ADDRH1_MODUL3 (0xC)
#define   ADDRM1_MODUL3 (0x15)
#define   ADDRL1_MODUL3 (0)
#define   ADDRF1_MODUL3 (0xC0500000l + ADDR3)
#define   SIZEF1_MODUL3 (SIZE_ABS3) //two blocks together

//qpsk
#define   ADDRH_MODUL2 (0xA)
#define   ADDRM_MODUL2 (0x30)
#define   ADDRL_MODUL2 (0)
#define   ADDRF_MODUL2 (0xC0500000l + ADDR2 + SIZE_ABS2)
#define   SIZEF_MODUL2 (16) //two blocks together

#define   ADDRH1_MODUL2 (0xC)
#define   ADDRM1_MODUL2 (0x15)
#define   ADDRL1_MODUL2 (0)
#define   ADDRF1_MODUL2 (0xC0500000l + ADDR2)
#define   SIZEF1_MODUL2 (SIZE_ABS2) //two blocks together


//bpsk
#define   ADDRH_MODUL1 (0xA)
#define   ADDRM_MODUL1 (0x40)
#define   ADDRL_MODUL1 (0)
#define   ADDRF_MODUL1 (0xC0500000l + ADDR1 + SIZE_ABS1)
#define   SIZEF_MODUL1 (2) //two blocks together

#define   ADDRH1_MODUL1 (0xC)
#define   ADDRM1_MODUL1 (0x16)
#define   ADDRL1_MODUL1 (0)
#define   ADDRF1_MODUL1 (0xC0500000l + ADDR1)
#define   SIZEF1_MODUL1 (SIZE_ABS1) //two blocks together

#define   ADDRH1_MODUL (0xC)
#define   ADDRM1_MODUL (0x8)//(0xC)
#define   ADDRL1_MODUL (0)

#define   ADDRH_MODUL (0)
#define   ADDRM_MODUL (0)//(0xC)
#define   ADDRL_MODUL (0)






 /*
#define MODUL11	(0x11)
#define MODUL41	(0x41)
#define MODUL51	(0x51)
#define MODUL61	(0x61)
#define MODUL71	(0x71)
#define MODUL81	(0x81)

 */






#define MDATA_PORT (0xD)
#define SUMM_PORT (0xE)


#ifndef PROG_DMU6

#define ADDRH_PORT (0xA)
#define ADDRM_PORT (0xB)
#define ADDRL_PORT (0xC)

#else

#define ADDRH_PORT (0)	   //temporary set to echo port
#define ADDRM_PORT (0)
#define ADDRL_PORT (0)


#endif



extern  uchar TFTP_Buffer[TFTP_BUFFER_SIZE];
extern char* pxilinx;

extern "C" unsigned char WriteRamToRam(unsigned long size)
{
  unsigned long i;
  unsigned char checksum;//, checksum1;
  unsigned char *pData = &TFTP_Buffer[0];
  char* port;
  unsigned char ret;
  ret = 1;

  checksum = 0;
  port = pxilinx + (MDATA_PORT);

//#ifdef FILES_TEST
//printfp("\n\r size :");
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif
//delay_mcs(10l);

  for(i = 0; i < size; i++)
  {
//   *port = *pData;
   outportb(MDATA_PORT , *pData);

if(GetTestMode() == 0x5A)
{
printfpd(" %02X", *pData);
}

//#ifdef FILES_TEST
//pData--;
//printfpd(" %02X", *pData);
//	delay_mcs(10l);

//printfpd("\n\r %02X",inportb(ADDRL_PORT));
//printfpd(": %02X",inportb(MDATA_PORT));

//#endif

//	delay_mcs(10l);
//   checksum += *pData;
   pData++; 
  }
//  delay_mcs(10l);
	
//#ifdef FILES_TEST
//pData--;
//printfpd(" %02X", *pData);
//#endif

 /*
 checksum1 = inportb(SUMM_PORT);
   
 if(checksum != checksum1)
 {
   printfp("\n\r Write Error checksum cell: ");
   printfpd("%02X ",checksum);
   printfpd("read:%02X",checksum1);
   ret = 0;
 }
 else
 {
  printfp("\n\r Write Ok checksum cell: ");
   printfpd("%02X ",checksum);
   printfpd("read:%02X",checksum1);

 }
  */
unsigned cell_addr =  (inportb(ADDRH_PORT) << 16) +   (inportb(ADDRM_PORT) << 8) +  (inportb(ADDRL_PORT)); 
	
// if(checksum != checksum1)
// if(checksum != checksum1)
//  if(size != cell_addr)
// {
 //  printfp("\n\r Write Error! read size :");
 //  printfpd("addr: %X",cell_addr);
 //  printfpd(" need :%02X",size);
 ///  ret = 0;
 //}


  return ret;
}

extern "C" unsigned char WriteRamToRam512(unsigned long size)
{
  unsigned long i;
  unsigned char checksum;//, checksum1;
  unsigned char *pData = &TFTP_Buffer[0]; //low bytes //[0];
  char* port;
  unsigned char ret;
  ret = 1;

  checksum = 0;
  port = pxilinx + (MDATA_PORT);

//#ifdef FILES_TEST
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif


  for(i = 0; i < (size >> 1); i++)
  {
//#ifdef FILES_TEST
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif

  delay_mcs(1);
   *port = *pData;
   checksum += *pData;

if(GetTestMode() == 0x5A)
{
printfpd(" %02X", *pData);
}

   pData++; 
   pData++;
  }	


  				   outportb(ADDRH_PORT, ADDRH12_MODUL9);
				   outportb(ADDRM_PORT, ADDRM12_MODUL9);
				   outportb(ADDRL_PORT, ADDRL12_MODUL9);

   pData = &TFTP_Buffer[1]; //high bytes //[1]; //low bytes

//#ifdef FILES_TEST
if(GetTestMode() == 0x5A)
{
printfp("\n\r high bytes \n\r");
}
//#endif


  for(i = 0; i < (size >> 1); i++)
  {
//#ifdef FILES_TEST
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif
   delay_mcs(1);

   *port = *pData;
   checksum += *pData;

//#ifdef FILES_TEST
//printfpd(" %d", size);
if(GetTestMode() == 0x5A)
{
printfpd(" %02X", *pData);
}
//#endif



   pData++; 
   pData++; 
  }	



//#ifdef FILES_TEST
//pData--;
//pData--;
//printfpd(" %02X", *pData);
//#endif


 //checksum1 = inportb(SUMM_PORT);
//unsigned cell_addr =  (inportb(ADDRH_PORT) << 16) +   (inportb(ADDRM_PORT) << 8) +  (inportb(ADDRL_PORT)); 
	
// if(checksum != checksum1)
// if(checksum != checksum1)
/*
  if(size != cell_addr)
 {
   printfp("\n\r Write Error! read size :");
   printfpd(" :%02X",cell_addr);
   printfpd(" need :%02X",size);
   ret = 0;
 }
  */

  return ret;
}

extern "C" unsigned char ReadRamToRam(unsigned long size)
{
  unsigned long i;
  unsigned char checksum, checksum1;
  unsigned char *pData = &TFTP_Buffer[0];
  char* port;
  unsigned char ret;
  ret = 1;

  checksum = 0;
  port = pxilinx + (MDATA_PORT);

//#ifdef FILES_TEST
printfp("\n\r size :");
printfpd("%d\n\r", size);
//printfpd(" %02X", *pData);
//#endif
  for(i = 0; i < size; i++)
  {
//   *port = *pData;
delay_mcs(100l);
   *pData = *port;
//#ifdef FILES_TEST
//pData--;
printfpd(" %02X", *pData);
//#endif


   checksum += *pData;
   pData++; 
  }	
//#ifdef FILES_TEST
//pData--;
//printfpd(" %02X", *pData);
//#endif

 
 checksum1 = inportb(SUMM_PORT);
   
 if(checksum != checksum1)
 {
   printfp("\n\r Read Error checksum cell: ");
   printfpd("%02X ",checksum);
   printfpd("read:%02X",checksum1);
   ret = 0;
 }
 else
 {
  printfp("\n\r Read Ok checksum cell: ");
   printfpd("%02X ",checksum);
   printfpd("read:%02X",checksum1);

 }
  
  /*
unsigned cell_addr =  (inportb(ADDRH_PORT) << 16) +   (inportb(ADDRM_PORT) << 8) +  (inportb(ADDRL_PORT)); 
	
// if(checksum != checksum1)
// if(checksum != checksum1)
  if(size != cell_addr)
 {
   printfp("\n\r Write Error! read size :");
   printfpd(" :%02X",cell_addr);
   printfpd(" need :%02X",size);
   ret = 0;
 }
   
 */
  return ret;
}

extern "C" unsigned char ReadRamToRam512(unsigned long size)
{
  unsigned long i;
  unsigned char checksum, checksum1;
  unsigned char *pData = &TFTP_Buffer[1];//[0];
  char* port;
  unsigned char ret;
  ret = 1;

  checksum = 0;
  port = pxilinx + (MDATA_PORT);

//#ifdef FILES_TEST
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif


  for(i = 0; i < (size >> 1); i++)
  {

   *pData = *port;
   checksum += *pData;
//#ifdef FILES_TEST
//printfpd(" %d", size);
printfpd(" %02X", *pData);
//#endif


   pData++; 
   pData++;



  }	
 //  pData--; 
 //  pData--;

// printfpd(" %02X", *pData);


   pData = &TFTP_Buffer[0];//[1]; //low bytes

   				   outportb(ADDRH_PORT, ADDRH12_MODUL9);
				   outportb(ADDRM_PORT, ADDRM12_MODUL9);
				   outportb(ADDRL_PORT, ADDRL12_MODUL9);


//#ifdef FILES_TEST
printfp("\n\r high bytes \n\r");
//#endif


  for(i = 0; i < (size >> 1); i++)
  {
//#ifdef FILES_TEST
//printfpd(" %d", size);
//printfpd(" %02X", *pData);
//#endif

 //  *port = *pData;
   *pData = *port;
//#ifdef FILES_TEST
//printfpd(" %d", size);
printfpd(" %02X", *pData);
//#endif

   checksum += *pData;
   pData++; 
  pData++; 
  }	



//#ifdef FILES_TEST
//pData--;
//pData--;
//printfpd(" %02X", *pData);
//#endif

 
 checksum1 = inportb(SUMM_PORT);
//unsigned cell_addr =  (inportb(ADDRH_PORT) << 16) +   (inportb(ADDRM_PORT) << 8) +  (inportb(ADDRL_PORT)); 
	
// if(checksum != checksum1)
 if(checksum != checksum1)
//  if(size != cell_addr)
 {
   printfp("\n\r Read Error! checksum1 :");
   printfpd(" :%02X",checksum1);
   printfpd(" need :%02X",checksum);
   ret = 0;
 }
  

  return ret;
}

extern "C" void ReadRamData(unsigned char modulsk)
{
//  unsigned char addrh, addrm, addrl;

  switch(modulsk)
  {
   case MODUL9:
   				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
				  ReadRamToRam512(SIZEF_MODUL9);

  				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam512(SIZEF1_MODUL9);

				  
				   
  	 			  break;

   case MODUL8:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
				  ReadRamToRam(SIZEF_MODUL8);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam(SIZEF1_MODUL8);


				  break;

   case MODUL7:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
 				  ReadRamToRam(SIZEF_MODUL7);

 				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
 				  ReadRamToRam(SIZEF1_MODUL7);

		  		  break;

   case MODUL6:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
			  	  ReadRamToRam(SIZEF_MODUL6);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
			  	  ReadRamToRam(SIZEF1_MODUL6);

	 			  break;

   case MODUL5:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
				  ReadRamToRam(SIZEF_MODUL5);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam(SIZEF1_MODUL5);
  	 			  break;

   case MODUL4:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
 			  	  ReadRamToRam(SIZEF_MODUL4);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam(SIZEF1_MODUL4);
	 			  break;

   case MODUL3:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
			  	  ReadRamToRam(SIZEF_MODUL3);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
			  	  ReadRamToRam(SIZEF1_MODUL3);


	 			  break;

  case MODUL2:    outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);

				  ReadRamToRam(SIZEF_MODUL2);

				   
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam(SIZEF1_MODUL2);
					  


  			  	  break;

  case MODUL1:
  				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
				  ReadRamToRam(SIZEF_MODUL1);
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
				  ReadRamToRam(SIZEF1_MODUL1);


//printfpd("\n\r %d" ,SIZEF_MODUL1);
	 			  break;

	 default : break;
  }
}






//extern "C" void SetStartAddr(unsigned char modulsk)
extern "C" void WriteRamData(unsigned char modulsk)
{
//  unsigned char addrh, addrm, addrl;

  switch(modulsk)
  {
   case MODUL9:  
   				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL9, SIZEF_MODUL9);
	 			  if(!WriteRamToRam512(SIZEF_MODUL9))	 //two try
				  {
				   outportb(ADDRH_PORT, ADDRH_MODUL);
				   outportb(ADDRM_PORT, ADDRM_MODUL);
				   outportb(ADDRL_PORT, ADDRL_MODUL);
				   WriteRamToRam512(SIZEF_MODUL9);}

				  outportb(ADDRH_PORT, ADDRH1_MODUL9);
				  outportb(ADDRM_PORT, ADDRM1_MODUL9);
				  outportb(ADDRL_PORT, ADDRL1_MODUL9);
	 			  ReadFlashToRam(ADDRF1_MODUL9, SIZEF1_MODUL9);
				  
	 			  if(!WriteRamToRam512(SIZEF1_MODUL9))	 //two try
				  {
				   outportb(ADDRH_PORT, ADDRH1_MODUL9);
				   outportb(ADDRM_PORT, ADDRM1_MODUL9);
				   outportb(ADDRL_PORT, ADDRL1_MODUL9);
				   WriteRamToRam512(SIZEF1_MODUL9);}
				  
				   /*
				    if(!WriteRamToRam512(SIZEF11_MODUL9))	 //two try
				  {
				   outportb(ADDRH_PORT, ADDRH1_MODUL9);
				   outportb(ADDRM_PORT, ADDRM1_MODUL9);
				   outportb(ADDRL_PORT, ADDRL1_MODUL9);
				   WriteRamToRam512(SIZEF11_MODUL9);}

				    if(!WriteRamToRam512(SIZEF11_MODUL9))	 //two try
				  {
				   outportb(ADDRH_PORT, ADDRH12_MODUL9);
				   outportb(ADDRM_PORT, ADDRM12_MODUL9);
				   outportb(ADDRL_PORT, ADDRL12_MODUL9);
				   WriteRamToRam512(SIZEF11_MODUL9);}

					*/


	 			  break;

   case MODUL8:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL8, SIZEF_MODUL8);
	 			  if(!WriteRamToRam(SIZEF_MODUL8))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 		  	  WriteRamToRam(SIZEF_MODUL8);}

				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL8, SIZEF1_MODUL8);
	 			  if(!WriteRamToRam(SIZEF1_MODUL8))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 		  	  WriteRamToRam(SIZEF1_MODUL8);}


	 			  break;

   case MODUL7:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL7, SIZEF_MODUL7);
	 			  if(!WriteRamToRam(SIZEF_MODUL7))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL7);}


				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL7, SIZEF1_MODUL7);
	 			  if(!WriteRamToRam(SIZEF1_MODUL7))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL7);}

	 			  break;

   case MODUL6:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL6, SIZEF_MODUL6);
	 			  if(!WriteRamToRam(SIZEF_MODUL6))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL6);}

  				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL6, SIZEF1_MODUL6);
	 			  if(!WriteRamToRam(SIZEF1_MODUL6))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL6);}

	 			  break;

   case MODUL5:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL5, SIZEF_MODUL5);
	 			  if(!WriteRamToRam(SIZEF_MODUL5))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL5);}

 				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL5, SIZEF1_MODUL5);
	 			  if(!WriteRamToRam(SIZEF1_MODUL5))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL5);}

	 			  break;

   case MODUL4:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL4, SIZEF_MODUL4);
	 			  if(!WriteRamToRam(SIZEF_MODUL4))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL4);}

				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL4, SIZEF1_MODUL4);
	 			  if(!WriteRamToRam(SIZEF1_MODUL4))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL4);}

	 			  break;


   case MODUL3:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL3, SIZEF_MODUL3);
	 			  if(!WriteRamToRam(SIZEF_MODUL3))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL3);}

 				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL3, SIZEF1_MODUL3);
	 			  if(!WriteRamToRam(SIZEF1_MODUL3))	 //two try
				  {
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL3);}

	  			  break;

  case MODUL2:   outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL2, SIZEF_MODUL2);
	 			  if(!WriteRamToRam(SIZEF_MODUL2))	 //two try
				  {
				  
				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  WriteRamToRam(SIZEF_MODUL2);}

 				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL2, SIZEF1_MODUL2);
	 			  if(!WriteRamToRam(SIZEF1_MODUL2))	 //two try
				  {
				  
				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  WriteRamToRam(SIZEF1_MODUL2);}

	 			  break;

  case MODUL1:
  				  outportb(ADDRH_PORT, ADDRH_MODUL);
				  outportb(ADDRM_PORT, ADDRM_MODUL);
				  outportb(ADDRL_PORT, ADDRL_MODUL);
	 			  ReadFlashToRam(ADDRF_MODUL1, SIZEF_MODUL1);
	 			  if(!WriteRamToRam(SIZEF_MODUL1))	 //two try
				  {
				    outportb(ADDRH_PORT, ADDRH_MODUL);
				  	outportb(ADDRM_PORT, ADDRM_MODUL);
				  	outportb(ADDRL_PORT, ADDRL_MODUL);
				    WriteRamToRam(SIZEF_MODUL1);}

  				  outportb(ADDRH_PORT, ADDRH1_MODUL);
				  outportb(ADDRM_PORT, ADDRM1_MODUL);
				  outportb(ADDRL_PORT, ADDRL1_MODUL);
	 			  ReadFlashToRam(ADDRF1_MODUL1, SIZEF1_MODUL1);
	 			  if(!WriteRamToRam(SIZEF1_MODUL1))	 //two try
				  {
				    outportb(ADDRH_PORT, ADDRH1_MODUL);
				  	outportb(ADDRM_PORT, ADDRM1_MODUL);
				  	outportb(ADDRL_PORT, ADDRL1_MODUL);
				    WriteRamToRam(SIZEF1_MODUL1);}

	 			  break;


	 default : break;
  }



}


//extern "C" void WriteRamData(unsigned char modulsk)
//{
//  SetStartAddr(modulsk);
//}

extern "C" unsigned char SetDecOff()
{
   unsigned char ret, tmp;

   tmp = inportb(DEC_CON_PORT);
   ret = tmp & 	MASK_BIT_0;
   tmp &= ~(MASK_BIT_0);
   outportb(DEC_CON_PORT, tmp);
   return ret;
}

extern "C" void SetDecBack(unsigned char decoder)
{
   unsigned char tmp;
   tmp = inportb(DEC_CON_PORT);
   if(decoder) tmp |= MASK_BIT_0;
   outportb(DEC_CON_PORT, tmp);
}



//#define RAM_LOAD_RATE (10000000)

extern "C" void LoadRam(unsigned char chn)
{
   unsigned char modulsk;
   unsigned long symbolrate;
   unsigned char decoderloc;

 	if(chn <= MAX_CNL)
		{
		 switch(chn)
		 {
		 case CNL1 :   	modulsk = GetModulSK();
		 				symbolrate = GetSymbolRate();
					    SetSelector(CNL1);
					    LoadSymbolRate(RAM_LOAD_RATE);
						decoderloc = SetDecOff();
					    WriteRamData(modulsk);
					   	LoadSymbolRate(symbolrate);
				   		SetDecBack(decoderloc);
					    break;

		 case CNL2 :   	modulsk = GetModulSK2();
		 				symbolrate = GetSymbolRate2();
					    SetSelector(CNL2);	
				   		LoadSymbolRate(RAM_LOAD_RATE);
				   		decoderloc = SetDecOff();
				   		WriteRamData(modulsk);
					 	LoadSymbolRate(symbolrate);
					    SetDecBack(decoderloc);

					    break;
					/*
		 case CNL3 :   	
		 case CNL4 :  
		 		  */
		 default  :     break;
		  }
		 }
}

extern "C" void UnLoadRam(unsigned char chn)
{
   unsigned char modulsk;
   unsigned long symbolrate;
   unsigned char decoderloc;

 	if(chn <= MAX_CNL)
		{
		 switch(chn)
		 {
		 case CNL1 :   	modulsk = GetModulSK();
		 				symbolrate = GetSymbolRate();
					    SetSelector(CNL1);
					    LoadSymbolRate(RAM_LOAD_RATE);
						decoderloc = SetDecOff();
					    ReadRamData(modulsk);
						SetDecBack(decoderloc);
						LoadSymbolRate(symbolrate);
					    break;

		 case CNL2 :   	modulsk = GetModulSK2();
		 				symbolrate = GetSymbolRate2();
					    SetSelector(CNL2);	
				   		LoadSymbolRate(RAM_LOAD_RATE);
						decoderloc = SetDecOff();
				   		ReadRamData(modulsk);
						SetDecBack(decoderloc);
						LoadSymbolRate(symbolrate);

					    break;
					/*
		 case CNL3 :  
		 case CNL4 : 
		 		  */
		 default  :     break;
		  }
		 }
}



#define BAUD_PORT (9)

extern "C" void LoadBaud(unsigned long rate, unsigned char chnl)
{
 unsigned char code;
//code = ((rate * 6l + 5000000l) / 10000000l) + 1;
code = ((((rate/1000000l)) * 6l) + 5l) / 10l + 1;



 if(code > 30) code = 30; 

SetSelector(chnl);
outportb(BAUD_PORT, code);
  /*
printfpd("code :%d",  code);
printfpd("rate :%ld",  rate);
printfpd("chnl: :%d",  chnl);
printfpd("port :%d",  BAUD_PORT);
 */
}

extern "C" void LoadDDSs(void)
{

//#endif //PROG_PRM_PCH_L
 if(GetTestMode() != 0x8el)   //restart only rtcs
  {

  SetSelector(CNL1);
//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();
//   for(long i2 = 0; i2 < 100000; i2++) //test

//printfp("\n\r22a");
 LoadSymbolRate(GetSymbolRate());
//printfp("\n\r22b");

 LoadDDSN3();
//printfp("\n\r22c");

 LoadFreqPCh(GetFreqPCh());
//printfp("\n\r22d");


 SetSelector(CNL2);
//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();

//printfp("\n\r22e");

//   for(long i2 = 0; i2 < 100000; i2++) //test
 LoadSymbolRate(GetSymbolRate2());
//printfp("\n\r22f");

 LoadDDSN3();
//printfp("\n\r22g");

 LoadFreqPCh(GetFreqPCh2());
// printfp("\n\r22h");


  /*
SetSelector(CNL3);
//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();
//   for(long i2 = 0; i2 < 100000; i2++) //test
 LoadSymbolRate(GetSymbolRate3());

 LoadDDSN3();

 LoadFreqPCh(GetFreqPCh3());


SetSelector(CNL4);
//  for(long i1 = 0; i1 < 100000; i1++) //test
 LoadDDSN2();
//   for(long i2 = 0; i2 < 100000; i2++) //test
 LoadSymbolRate(GetSymbolRate4());

 LoadDDSN3();

 LoadFreqPCh(GetFreqPCh4());

  */



 }
}







extern "C" void ScanStateB()
{
 unsigned char status;
 SetSelector(CNL1);
 status = inportb(STATUS_PORT);
 // if(!(status & MASK_BIT_1))// lock
  if((status & MASK_BIT_1))// lock
      { 
	  dmustatusu.dmustatus.status  |=  MASK_BIT_0;
      }
	  else
	  {
	  dmustatusu.dmustatus.status  &=  ~(MASK_BIT_0);
	  }

//     if(!(status & MASK_BIT_0))	 //freq
     if((status & MASK_BIT_0))	 //freq

      { 
	  dmustatusu.dmustatus.status  |=  MASK_BIT_1;
      }
	  else
	  {
	  dmustatusu.dmustatus.status  &=  ~(MASK_BIT_1);
	  }

  SetSelector(CNL2);
  status = inportb(STATUS_PORT);
  //    if(!(status & MASK_BIT_1))// lock
      if((status & MASK_BIT_1))// lock
      { 
	  dmustatusu2.dmustatus.status  |=  MASK_BIT_0;
      }
	  else
	  {
	  dmustatusu2.dmustatus.status  &=  ~(MASK_BIT_0);
	  }

  //   if(!(status & MASK_BIT_0))	 //freq
     if((status & MASK_BIT_0))	 //freq
      { 
	  dmustatusu2.dmustatus.status  |=  MASK_BIT_1;
      }
	  else
	  {
	  dmustatusu2.dmustatus.status  &=  ~(MASK_BIT_1);
	  }
	  /*
  SetSelector(CNL3);
  status = inportb(STATUS_PORT);
  //    if(!(status & MASK_BIT_1))// lock
      if((status & MASK_BIT_1))// lock
      { 
	  dmustatusu3.dmustatus.status  |=  MASK_BIT_0;
      }
	  else
	  {
	  dmustatusu3.dmustatus.status  &=  ~(MASK_BIT_0);
	  }

  //   if(!(status & MASK_BIT_0))	 //freq
     if((status & MASK_BIT_0))	 //freq
      { 
	  dmustatusu3.dmustatus.status  |=  MASK_BIT_1;
      }
	  else
	  {
	  dmustatusu3.dmustatus.status  &=  ~(MASK_BIT_1);
	  }

  SetSelector(CNL4);
  status = inportb(STATUS_PORT);
  //    if(!(status & MASK_BIT_1))// lock
      if((status & MASK_BIT_1))// lock
      { 
	  dmustatusu4.dmustatus.status  |=  MASK_BIT_0;
      }
	  else
	  {
	  dmustatusu4.dmustatus.status  &=  ~(MASK_BIT_0);
	  }

  //   if(!(status & MASK_BIT_0))	 //freq
     if((status & MASK_BIT_0))	 //freq
      { 
	  dmustatusu4.dmustatus.status  |=  MASK_BIT_1;
      }
	  else
	  {
	  dmustatusu4.dmustatus.status  &=  ~(MASK_BIT_1);
	  }

		  */
}

 /*
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

*/

#define SCAN_TIME_PERIOD (250)

 unsigned long GetFreqPCh2();
 unsigned long GetFreqPCh();


extern "C" void PRM_PCH()
 {

unsigned long tmp, tmp1;

    if(flag_write_flash)
	{
	WriteRamToFlash();
	flag_write_flash = 0;
	writed_modul = 0; //to need have before load some
	}



    if(flag_need_load)
	{
  //  Init_PRM_PCH();
  //   delay_mcs(1000l);
  tmp = GetFreqPCh();
  tmp1 = GetSymbolRate();

     LoadBand(tmp, CNL1, tmp1);
  //tmp = GetSymbolRate();
	 LoadBaud(tmp1, CNL1);

  tmp = GetFreqPCh2();
  tmp1 = GetSymbolRate2();

	 LoadBand(tmp, CNL2, tmp1);
 // tmp = GetSymbolRate2();
	 LoadBaud(tmp1, CNL2);
   /*
  tmp = GetFreqPCh3();
	 LoadBand(tmp, CNL3);
  tmp = GetSymbolRate3();
	 LoadBaud(tmp, CNL3);

  tmp = GetFreqPCh4();
	 LoadBand(tmp, CNL4);
  tmp = GetSymbolRate4();
	 LoadBaud(tmp, CNL4);
		*/
	flag_need_load = 0;
	 }
	  

//ok  return;


 // static unsigned long timescan;

	   if(GetNeedWriteDevId())
		   {
	  // 	   printfp("\n\r Write!!"); //t
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }
	  /*
	 if( (time1 - timescan) > SCAN_TIME_PERIOD)
	 {
	   	timescan = time1;
  		ScanStateB();
	 }
		 */
return;
 
}






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
 // embSerialACT155.IsrXX();
#endif // IncEmbSerialMD34AVT
 IntFlag |= INT0_FLAG;
   my_int_enable_irq0();
}
//#ifdef PROG_BMD155

//__________________________________________________________________________________

typedef	unsigned long long __int64;

 
extern "C" void  ParseCommand1()
{
	 add_char_TCP_buff(TYPE_AUTO);
	 for(long i = 0; i < 44; i++)
	 {
	   add_char_TCP_buff(unEmb2TypeVer.byte[i]);
	 }
	 breakflag =1; 
}



extern "C" unsigned char CheckSymbolRate(unsigned long rate)
{
  	 if((rate > MAX_SYMBOL_RATE) || (rate < MIN_SYMBOL_RATE))
			 return 0;
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
unsigned char * b;

//for(unsigned i = 0; i <10; i++)		   //test
//{

b = FormulaDMU1_0((rate << 2));	 //101118

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
//}
}



extern "C" void SetSelector(unsigned char chn)
{

if(chn <= MAX_CNL)
		{
		 switch(chn)
		 {
		 case CNL1 :  outportb(SEL_PORT, CODE_CNL1);
					  break;

		 case CNL2 :  outportb(SEL_PORT, CODE_CNL2);
					  break;
		   /*
		 case CNL3 :  outportb(SEL_PORT, CODE_CNL3);
					  break;

		 case CNL4 :  outportb(SEL_PORT, CODE_CNL4);
					  break;
			   */
		 default  :	   break;	
		  }
		 }
}

#define TRY_TEST  (1000) 

extern "C" void  LoadrateTest()
{

// if((rate > MAX_SYMBOL_RATE) || (rate < MIN_SYMBOL_RATE))


  	unsigned long tmp;// = (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2];


  //	if(GetTestMode() == 0x5A)
	 for(unsigned i = 0; i < TRY_TEST; i++)
	 { 
		 tmp = 	 MIN_SYMBOL_RATE;

		while(tmp < MAX_SYMBOL_RATE)
 	{
 	 	
		printfp("\n\r freq :");
		printfpd("%ld", tmp);
 //		}	

	   		   		   SetSymbolRate(tmp);
					   SetSelector(CNL1);
					   LoadDDSN2();	
					   LoadBaud(tmp, CNL1);
					   LoadSymbolRate(tmp);	
				   //	   LoadDDSN3();


		    		   SetSymbolRate2(tmp);
					   SetSelector(CNL2);
					   LoadDDSN2();
				       LoadBaud(tmp, CNL2);
					   LoadSymbolRate(tmp);
					//   LoadDDSN3();

		  tmp += 1000000l;
		 }		   	
	  }

}


 
extern "C" void  ParseCommand2(char *IPBuff)
{
unsigned char chn = IPBuff[1];

		unsigned long tmp = (IPBuff[5] << 24) + (IPBuff[4] << 16) +  (IPBuff[3] << 8)  + IPBuff[2];
	if(GetTestMode() == 0x5A)
	{	
		printfp("Command2 freq :");
		printfpd("%ld", tmp);
		printfp("channel :");
		printfpd("%ld", chn);
	}	

		if(CheckSymbolRate(tmp) && (chn <= MAX_CNL))
		{
		 switch(chn)
		 {
		 case CNL1 :   SetSymbolRate(tmp);
					   SetSelector(CNL1);
					   LoadDDSN2();	
					   LoadBaud(tmp, CNL1);
					   LoadSymbolRate(tmp);	
				   //	   LoadDDSN3();
				       break;


		 case CNL2 :   SetSymbolRate2(tmp);
					   SetSelector(CNL2);
					   LoadDDSN2();
				       LoadBaud(tmp, CNL2);
					   LoadSymbolRate(tmp);
					//   LoadDDSN3();
				   	   break;
			  /*
		 case CNL3 :   SetSymbolRate3(tmp);
					   SetSelector(CNL3);
					   LoadDDSN2();
				       LoadBaud(tmp, CNL3);
					   LoadSymbolRate(tmp);	 break;

		 case CNL4 :   SetSymbolRate4(tmp);
					   SetSelector(CNL4);
					   LoadDDSN2();
				       LoadBaud(tmp, CNL4);
					   LoadSymbolRate(tmp);	 break;
				   */
		 default  :	   break;	
 
		  }

 		   SetNeedWriteDevId();
			/*
		   unEmb2TypeVer.emb2TypeVer.signature_software[0] =  IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[1] =  IPBuff[3];
		   unEmb2TypeVer.emb2TypeVer.signature_software[2] =  IPBuff[4];
		   unEmb2TypeVer.emb2TypeVer.signature_software[3] =  IPBuff[5];
		   */
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



extern "C" unsigned char CheckFreqPCh(unsigned long freq)
{
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


extern "C" unsigned char ChkDem(unsigned char chnl)
{

  SetSelector(chnl);
  outportb(MIRROR_PORT, 0x55);
  if(0x55 != inportb(MIRROR_PORT))	return 0;
   outportb(MIRROR_PORT, 0xAA);
  if(0xAA != inportb(MIRROR_PORT))	return 0;
   return 1;
}


extern "C" void LoadBand(unsigned long pch, unsigned char chnl, unsigned long freq)
{
//unsigned char * pData;
//static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//
unsigned char lbyte;

lbyte = 0;
   SetSelector(chnl);	
if(pch < DIAP_SELECT)
{
 //outportb(OPTIONDEM_PORT, LOW_BAND);
lbyte |=  LOW_BAND;
}
else
{
// outportb(OPTIONDEM_PORT, HIGH_BAND);
lbyte |=  HIGH_BAND;
}

if(freq < DIAP_SELECT1)
{
 //outportb(OPTIONDEM_PORT, LOW_BAND);
lbyte |=  LOW_BAND1;
}
else
{
// outportb(OPTIONDEM_PORT, HIGH_BAND);
lbyte |=  HIGH_BAND1;
}
   /*
printfpd("chnl : %d", chnl);
printfpd("lbyte : %d", lbyte);

 */
outportb(OPTIONDEM_PORT, lbyte);
}



extern "C" void LoadFreqPCh(unsigned long freq)
{
unsigned char * pData;
static unsigned char DataDDS[SENDED_DDS_FREQ_LEN];//


//delay_mcs(100000l);
if(freq < DIAP_SELECT)
{
// outportb(OPTIONDEM_PORT, LOW_BAND);

  if(start_main_loop)
{
// printfp("LOW_BAND");
 }
}
else
{
// outportb(OPTIONDEM_PORT, HIGH_BAND);
  if(start_main_loop)
{
 // printfp("HIGH_BAND");
 }
}
//delay_mcs(100000l);



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
	  	if(GetTestMode() == 0x5A)
	{	
	    printfp("Command3 freq :");
		printfpd("%ld", tmp);
		printfp("channel :");
		printfpd("%ld", chn);
	}   
	  
	   
		if(CheckFreqPCh(tmp) && (chn <= MAX_CNL))
		{
		 switch(chn)
		 {
		 case CNL1 :    SetFreqPCh(tmp);
					    SetSelector(CNL1);	
						LoadDDSN3();
					    LoadFreqPCh(tmp);
					    LoadBand(tmp, chn, GetSymbolRate());
	
				   //		LoadModulSKB(CNL1); //it depended from freq
 		   		 //		SetNeedWriteDevId();

					    break;


		 case CNL2 :    SetFreqPCh2(tmp);
					    SetSelector(CNL2);
						LoadDDSN3();
					    LoadFreqPCh(tmp);
					    LoadBand(tmp, chn, GetSymbolRate2());

				 //		SetNeedWriteDevId();

					    break;
						/*
	 	case CNL3 :     SetFreqPCh3(tmp);
					    SetSelector(CNL3);
						LoadDDSN3();
					    LoadFreqPCh(tmp);
					    LoadBand(tmp, chn);

				   //		SetNeedWriteDevId();

					    break;




		 case CNL4 :    SetFreqPCh4(tmp);
					    SetSelector(CNL4);
						LoadDDSN3();
					    LoadFreqPCh(tmp);
					    LoadBand(tmp, chn);
	
					 //   LoadModulSKB(CNL2); //it depended from freq
 		   			 //	SetNeedWriteDevId();

					     break;
							 */
		 default  :	   break;	
 
		  }

                  SetNeedWriteDevId();

			/*
	  	   unEmb2TypeVer.emb2TypeVer.signature_software[4] =  IPBuff[2];
		   unEmb2TypeVer.emb2TypeVer.signature_software[5] =  IPBuff[3];
		   unEmb2TypeVer.emb2TypeVer.signature_software[6] =  IPBuff[4];
		   unEmb2TypeVer.emb2TypeVer.signature_software[7] =  IPBuff[5];
		   */
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
	  (modul == MODUL9) ||
  	  (modul == MODUL11)  ||
  	  (modul == MODUL41)  ||
  	  (modul == MODUL51)  ||
  	  (modul == MODUL61)  ||
  	  (modul == MODUL71)  ||
      (modul == MODUL81)  ||
  	  (modul == MODUL91)     
  	  
  	   )
			 return 1;
			 return 0;
}
   /*
extern "C" void LoadModulSKB(unsigned char chn)
{
 unsigned char modulsk;

 if(chn <= MAX_CNL)
		{
		 switch(chn)
		 {
		 case CNL1 :  SetSelector(CNL1);	
					  modulsk = GetModulSK();
					  break;

		 case CNL2 :  SetSelector(CNL2);	
					  modulsk = GetModulSK2();
					  break;
 

		 default  :	   break;	
		  }
		 }
	  outportb(MODUL_PORT, modulsk);

}
	 */
#define BAD_ANS	 (0x99)

extern "C" unsigned char ReadModulSKB(unsigned char chn)
{
 if(chn <= MAX_CNL)
		{
		 SetSelector(chn);
		 return inportb(MODUL_PORT);
	 	}
 return BAD_ANS;
}




/*
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
 

}
*/

extern "C" void  ParseCommand4(char *IPBuff)
{
   unsigned char chn = IPBuff[1];

		unsigned long tmp = IPBuff[2];
		if(GetTestMode() == 0x5A)
	{	
	    printfp("Command4 modul :");
		printfpd("%lX", tmp);
		printfp("channel :");
		printfpd("%ld", chn);
	}
		

		if((CheckModulSK(tmp) && (chn <= MAX_CNL)))
		{
			 switch(chn)
		 {
		 case CNL1 :   SetModulSK(tmp);
				   	   LoadModulSKB(CNL1);
					   SetDecAndTest(CNL1);
 		   			//   SetNeedWriteDevId();					   
					   break;


		 case CNL2 :   SetModulSK2(tmp);
					   LoadModulSKB(CNL2);
					   SetDecAndTest(CNL2);
 		   	   //		   SetNeedWriteDevId();				   
					   break; 
					   /*
		 case CNL3 :   SetModulSK3(tmp);
					   LoadModulSKB(CNL3);
 		   		  //	   SetNeedWriteDevId();				   
					   break;

		 case CNL4 :   SetModulSK4(tmp);
					   LoadModulSKB(CNL4);
 		   			//   SetNeedWriteDevId();				   
					   break;
							*/

		 default  :	   break;	
 
		  }

   SetNeedWriteDevId();	



  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

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
	unsigned i;
    unsigned char chn = IPBuff[1];
  //	 	if(GetTestMode() == 0x5A)
  //	{	
   //     printfp("\n\r Command5:");
   //	   	printfp("channel :");
   //		printfpd("%ld ", chn);
 //	}	

		if (chn <= MAX_CNL)
		{
			 switch(chn)
		 {
		 case CNL1 :  
		 			   	 if(ChkDem(CNL1))
					 //  if(1)
						 {
		 				  ScanStateB();
   						  dmustatusu.dmustatus.mode = GetModulSK();//ReadModulSKB(CNL1);
   						  dmustatusu.dmustatus.freq = GetFreqPCh();
   						  dmustatusu.dmustatus.rate = GetSymbolRate();
   						  dmustatusu.dmustatus.rezerv = 0xFFFFFFFF;
  						  add_char_TCP_buff(TYPE_STATUS);
   						  add_char_TCP_buff(IPBuff[1]);
						  for(i = 0; i < 20; i++)
	 					   {
					  	   add_char_TCP_buff(dmustatusu.byte[i]);
					   //		if(GetTestMode() == 0x5A)
					   //		{	
					   //	  	printfpd("%02X ",dmustatusu.byte[i]);
					   //		}
						   }
						  break;
						  }
						  else
						  {
						   add_char_TCP_buff(TYPE_STATUS);
   						  add_char_TCP_buff(IPBuff[1]);
						  for(i = 0; i < 20; i++)
	 					   {
						   add_char_TCP_buff(0);
					  //	   if(GetTestMode() == 0x5A)
					  //		{
					  //	     printfpd("%02X ",0);
					  //		}
						   }
						  break;

						  }
						   
		  case CNL2 :   
		  				   if(ChkDem(CNL2))
					 //  if(1)
						 {
		  
		  				   ScanStateB();
   						  dmustatusu2.dmustatus.mode = GetModulSK2(); //ReadModulSKB(CNL2);
   						  dmustatusu2.dmustatus.freq = GetFreqPCh2();
   						  dmustatusu2.dmustatus.rate = GetSymbolRate2();
   						  dmustatusu2.dmustatus.rezerv = 0xFFFFFFFF;
  						  add_char_TCP_buff(TYPE_STATUS);
   						  add_char_TCP_buff(IPBuff[1]);
						  for(i = 0; i < 20; i++)
	 					   {
						   add_char_TCP_buff(dmustatusu2.byte[i]);
						   if(GetTestMode() == 0x5A)
							{
					 // 	   printfpd("%02X ",dmustatusu2.byte[i]);
							}
						   }
						  break;
						    }
						  else
						  {
						   add_char_TCP_buff(TYPE_STATUS);
   						  add_char_TCP_buff(IPBuff[1]);
						  for(i = 0; i < 20; i++)
	 					   {
						   add_char_TCP_buff(0);
						   if(GetTestMode() == 0x5A)
							{
					   //	   printfpd("%02X ",0);
							}
						   }
						  break;

						  }

				   /*
	  case CNL3 :   
		  	 						   add_char_TCP_buff(TYPE_STATUS);
   		  
	  case CNL4 :   
		   	   							  */

		   default : 	  break;
		   	  }
		    }
			else
			{
			   add_char_TCP_buff(TYPE_RUN_BAD);
		   	   add_char_TCP_buff(IPBuff[1]);
		   	   add_char_TCP_buff(NOT_CORRECT_PARAMETER);
			}

	 breakflag =1;
}

//#define  DEC_CON_PORT (0xf)

extern "C" void  SetDecAndTest(unsigned char chn)  //test0
{
 	unsigned char tmp;
	tmp = 0;
	 	if(chn <= MAX_CNL)
	   	{
			 SetSelector(chn);	

			 switch(chn)
		 {
		 case CNL1 :   if(decoder0) 	//test
				   //	   if(1)	   //test
		 			   { tmp |=  MASK_BIT_0;	LoadRam(CNL1);
		 			   	 unEmb2TypeVer.emb2TypeVer.signature_hardware[1] |=  MASK_BIT_0;
		 			   }
		 	 		   else {  tmp &= ~(MASK_BIT_0);
						unEmb2TypeVer.emb2TypeVer.signature_hardware[1] &= ~(MASK_BIT_0);
						}
		 			//   if(test0) tmp |=  MASK_BIT_1;
		 	 		//   else   tmp &= ~(MASK_BIT_1);
					   outportb(DEC_CON_PORT, tmp);
				   	   break;


		 case CNL2 :   if(decoder1) {tmp |=  MASK_BIT_0;  LoadRam(CNL2);
		 			    unEmb2TypeVer.emb2TypeVer.signature_hardware[1] |=  MASK_BIT_1;
		 		  		 }
		 	 		   else  { tmp &= ~(MASK_BIT_0);
					   unEmb2TypeVer.emb2TypeVer.signature_hardware[1] &= ~(MASK_BIT_1);
						}
		 		 //	   if(test1) tmp |=  MASK_BIT_1;
		 	 	 //	   else   tmp &= ~(MASK_BIT_1);
				  	   outportb(DEC_CON_PORT, tmp);
					   break;
					  /*
		 case CNL3 :   if(decoder2) { tmp |=  MASK_BIT_0;  LoadRam(CNL3);}
		 	 		   else   tmp &= ~(MASK_BIT_0);
		 		  //	   if(test2) tmp |=  MASK_BIT_1;
		 	 	  //	   else   tmp &= ~(MASK_BIT_1);
					   outportb(DEC_CON_PORT, tmp);
				   	   break;


		 case CNL4 :   if(decoder3) { tmp |=  MASK_BIT_0;	  LoadRam(CNL4);}
		 	 		   else   tmp &= ~(MASK_BIT_0);
		 		  //	   if(test3) tmp |=  MASK_BIT_1;
		 	 	  //	   else   tmp &= ~(MASK_BIT_1);
				  	   outportb(DEC_CON_PORT, tmp);
				   	   break;
						  	*/
		 default  :	   break;	
 
		  }
	  }
}


extern "C" void  ParseCommand9(char *IPBuff)  //test0
{
   unsigned char chn = IPBuff[1];
   unsigned char tmp = IPBuff[2];

		if(GetTestMode() == 0x5A)
	{	
	    printfp("Command9 test :");
		printfpd("%lX", tmp);
		printfp("channel :");
		printfpd("%ld", chn);
	}
		

	 	if(chn <= MAX_CNL)
	   	{
			 switch(chn)
		 {
		 case CNL1 :   test0 = tmp;
		 		 	   SetDecAndTest(CNL1);
				   	   break;


		 case CNL2 :   test1 = tmp;
		 		 	   SetDecAndTest(CNL2);
				   	   break;
						  /*
		 case CNL3 :   test2 = tmp;
		 		 	   SetDecAndTest(CNL3);
				   	   break;


		 case CNL4 :   test3 = tmp;
		 		 	   SetDecAndTest(CNL4);
				   	   break;
						   */

		 default  :	   break;	
 
		  }

   SetNeedWriteDevId();	



  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

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


extern "C" void  ParseCommand8(char *IPBuff)  //
{
   unsigned char chn = IPBuff[1];
   unsigned char tmp = IPBuff[2];

		if(GetTestMode() == 0x5A)
	{	
	    printfp("Command8 decoder :");
		printfpd("%lX", tmp);
		printfp("channel :");
		printfpd("%ld", chn);
	}

	 	if(chn <= MAX_CNL)
	   	{
			 switch(chn)
		 {
		 case CNL1 :   decoder0 = tmp;
		 		 	   SetDecAndTest(CNL1);
					 //  if(tmp) LoadRam(CNL1);
				   	   break;


		 case CNL2 :   decoder1 = tmp;
		 		 	   SetDecAndTest(CNL2);
					 //  if(tmp) LoadRam(CNL2);
				   	   break;
						 /*
		 case CNL3 :   decoder2 = tmp;
		 		 	   SetDecAndTest(CNL3);
					 //  if(tmp) LoadRam(CNL3);
				   	   break;


		 case CNL4 :   decoder3 = tmp;
		 		 	   SetDecAndTest(CNL4);
					//   if(tmp) LoadRam(CNL4);
				   	   break;
						   */

		 default  :	   break;	
 
		  }

   SetNeedWriteDevId();	



  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

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


//_____________________________________baco
#define SIZE_CUDP10CFG (24)

 struct CUDP10Cfg
 {
   unsigned char mac_self[6];
   unsigned char mac_dest[6];
   unsigned char ip_self[4];
   unsigned char ip_dest[4];
   unsigned short port_self;
   unsigned short port_dest;
 };

 union  uCUDP10Cfg
 {
 CUDP10Cfg cfg;
 unsigned char byte[SIZE_CUDP10CFG];
 };


uCUDP10Cfg dmu5;




 struct CBACOCfg
{
	unsigned long numOfBlocks; 		//4
	unsigned short sizeOfBlocks;    //2
	unsigned short frequMain; 		//2
	unsigned short frequSampling; 	//2
	unsigned char passBand; 		//1
	unsigned char amplification; 	//1
	unsigned char typeOfBlock; 		//1
	unsigned char reserv[3]; 		//3
	unsigned char mac_self[6];		// 6 byte = 22
	unsigned char mac_dest[6];		// 6 byte = 28
	unsigned char ip_self[4];		// 4 byte = 32
	unsigned char ip_dest[4];		// 4 byte = 36
	unsigned short port_self;		// 2 byte = 38
	unsigned short port_dest;		// 2 byte = 40

};

extern "C" void	KeepDmu()
{

   printfp("\n\r keep dmu: \n\r");

 for(unsigned i=0; i<SIZE_CUDP10CFG; i++)
 {

    write_nvram_char((BACO_OFFSET_DMU + i), dmu5.byte[i]);
//    write_nvram_char((BACO_OFFSET_DMU + i), i);		 //t

  //	printfpd("\n\r k %d",  i);
  	printfpd("  %x",  dmu5.byte[i]);
   if(!(i% 16)) printfp("\n\r");


 }
}

extern "C" void	RestoreDmu()
{
   printfp("\n\r restore dmu : \n\r");

 for(unsigned i=0; i<SIZE_CUDP10CFG; i++)
 {
    dmu5.byte[i] = (unsigned char)read_nvram_char(BACO_OFFSET_DMU + i);  //	printfpd("\n\r %d",  i);
  if(!(i% 16)) printfp("\n\r");
 	printfpd("  %x",  dmu5.byte[i]);

 }

}



#define BACO_SIZE (320)

union uCBACOCfg
{
	CBACOCfg cbacocfg[8];
   //	unsigned char byte[128];
	unsigned char byte[BACO_SIZE];
};


uCBACOCfg cbaco;
unsigned short start_cbaco;


extern "C" void	KeepCBaco()
{
 for(unsigned i=0; i<BACO_SIZE; i++)
 {
    write_nvram_char((BACO_OFFSET + i), cbaco.byte[i]);

  //	printfpd("\n\r k %d",  i);
  //	printfpd("  %x",  cbaco.byte[i]);

 }
}

extern "C" void	RestoreCBaco()
{

 for(unsigned i=0; i<BACO_SIZE; i++)
 {
    cbaco.byte[i] = (unsigned char)read_nvram_char(BACO_OFFSET + i);
  //	cbaco.byte[i] = i; //t
  //	printfpd("\n\r %d",  i);
 // if(!(i% 16)) printfp("\n\r");
 //	printfpd("  %x",  cbaco.byte[i]);

 }

}

void LoadBacoStartZero(void)
{


#ifdef Debug_Baco1
 printfp("\n\r LoadBacoStartZero ");
#endif


//printfp("\n\r LoadBacoStartZero");
 //unsigned char numbit =   1; //slots 0

 //unsigned char numslot = 0;


 int l_base;

 outportb(SEL_PORT , SEL_TGE01);


 l_base = 0;//0x500; // + numslot * 16;

 //	outportb(l_base + BACO_START_ADDR , 1);
	outportb(l_base + DMU_START_ADDR , 1);

}


void LoadBacoStart(unsigned char numslot)
{
#ifdef Debug_Baco1
printfpd("\n\rLoadBacoStart %d", numslot );
#endif

 unsigned char numbit = 	(numslot - 1) >> 1; //slots 1,3,5,7... struct 0,1,2,3

 int l_base;
 l_base = 0x500 + numslot * 16;

	outportb(l_base + BACO_START_ADDR , start_cbaco & (1 << numbit));




}



void CfgCardBacoStart()
{
//printfp("\n\r CfgCardBacoStart");
#ifdef Debug_Baco1
 printfp("\n\rCfgCardBacoStart ");
#endif

 int l_base;

unsigned ns;

unsigned char Year = ClockReadYear();
unsigned char Month = ClockReadMonth();
unsigned char Date = ClockReadDate();
unsigned char Hours = ClockReadHours();
unsigned char Min = ClockReadMin();
unsigned char Sec = ClockReadSec();






  	for(unsigned i=1; i < NUM_OF_SLOT; i+=2)	//only nechet
	{
	ns =(i-1)>>1;

  	l_base = 0x500 + i * 16;
	outportb(l_base, YEAR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Year);
	outportb(l_base, MONTH_ADDR);
	outportb(l_base + DATA_REG_ADDR , Month);
	outportb(l_base, DAY_ADDR);
	outportb(l_base + DATA_REG_ADDR , Date);
	outportb(l_base, HOUR_ADDR);
	outportb(l_base + DATA_REG_ADDR , Hours);
	outportb(l_base, MIN_ADDR);
	outportb(l_base + DATA_REG_ADDR , Min);
	outportb(l_base, SEC_ADDR);
	outportb(l_base + DATA_REG_ADDR , Sec);

/*
	outportb(l_base, N0_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n0);
	outportb(l_base, N1_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n1);
	outportb(l_base, N2_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n2);
	outportb(l_base, N3_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[ns].n3);
	 */



	 LoadBacoStart(i);
	}

   LoadBacoStartZero();  //synchro start to all in zero slot



}




unsigned short CalcChecksum(unsigned len, unsigned short *pBuf)
{

unsigned long ret = 0;
 printfp("\n\r");
while(len--)
{
 printfpd("\n\r %d ",len);
 printfpd(" %X ",*pBuf);
 ret += *pBuf++;
// printfpd("\n\r %X ",*pBuf);
 printfpd(" %X ", ret);
 printfpd(" %X ", ~(ret));


}

 ret = (ret & 0xffff) + (ret >> 16);
 ret +=  (ret >> 16);


printfpd(" %X ", ~(ret));


return ~(ret);
}







#define HEADER_LEN (10) //16 bit words

extern "C" void TestChecksum()
{
 unsigned short Buffer[HEADER_LEN];
 unsigned short* pBuf =  Buffer;
 unsigned short checksum; 


		/*
 //t* pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = SWAPB(0x4500);	 //ver and header length in words
 * pBuf++  = SWAPB(0x28);	 //full length
 * pBuf++  = SWAPB(0x2503); //identif
 * pBuf++  = SWAPB(0x4000); //dont fragment
 * pBuf++  = SWAPB(0x8006); //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = SWAPB(0x9b9b);// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = SWAPB(0x9b47);// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = SWAPB(0xc35f);//ffff;
 * pBuf++  = SWAPB(0xda33);//0xffff;
	 */
		 /*
 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = 0x28;	 //full length
 * pBuf++  = 0x2503; //identif
 * pBuf++  = 0x4000;//0x4000; //dont fragment
 * pBuf++  = 0x8006; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = 0x9b9b;// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = 0x9b97;// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = 0xc35f;//ffff;
 * pBuf++  = 0xda33;//0xffff;
	   */

 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = 0x4e;	 //full length
 * pBuf++  = 0x04e5; //identif
 * pBuf++  = 0x0000;//0x4000; //dont fragment
 * pBuf++  = 0x8011; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc	  need 0x0107
 * pBuf++  = 0xc0a8;// cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  = 0x0064;// cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  = 0xffff;//ffff;
 * pBuf++  = 0xffff;//0xffff;
   checksum =  CalcChecksum((unsigned)HEADER_LEN, Buffer);
  // Buffer[5]	 = 	   checksum;

  printfpd("\n\rchecksum :  %X", checksum);

  Buffer[5]	 = 	   checksum;
 
    checksum =  CalcChecksum((unsigned)HEADER_LEN, Buffer);

  printfpd("\n\r test %X", checksum);




}




void LoadBacoDmu(unsigned char numslot)
{
// unsigned short Buffer[HEADER_LEN];
// unsigned short* pBuf =  Buffer;

 unsigned char numstruct = 	(numslot - 1) >> 1; //slots 1,3,5,7... struct 0,1,2,3
 int l_base;
// l_base = 0x500 + numslot * 16;
l_base = 0;

 uint_64 sample_max;

 unsigned long sid = SelfID(); 

// unsigned packlen = cbaco.cbacocfg[numstruct].sizeOfBlocks;// 4; //256; // (1024 / 4) 1024 + 30;  //32
 unsigned packlen = 8192 >> 2;

 unsigned udplen = (packlen * 4) + 42;

 unsigned iplen = udplen + 20; // (1024 / 4) 1024 + 30;  //32


 unsigned ipident  = 0x04e5;

 unsigned ipcrc;   //will celling

 unsigned tmp;

//unsigned char tmp0, tmp1, tmp2, tmp3;

 
 //1054 full length


 sample_max = (uint_64)cbaco.cbacocfg[numstruct].numOfBlocks ;//*   (uint_64)cbaco.cbacocfg[numstruct].sizeOfBlocks;	//32
 
  /*
 if(sample_max %  packlen)
 {
  tmp =  sample_max / packlen;
  sample_max = (tmp + 1) * packlen;
 }
  */
//printEthLongHex(cbaco.cbacocfg[numstruct].numOfBlocks);
//printEthLongHex(sample_max);
 // printfpd("\n\rsample_max : %d ",sample_max );
  /*

 * pBuf++  = 0x4500;	 //ver and header length in words
 * pBuf++  = iplen;	 //full length
 * pBuf++  = ipident; //identif
 * pBuf++  = 0x4000; //dont fragment
 * pBuf++  = 0x0206; //time = 2 ip p prot tcp = 6
 * pBuf++  = 0; //hier crc
 * pBuf++  =  cbaco.cbacocfg[numstruct].ip_self[3] << 16 + cbaco.cbacocfg[numstruct].ip_self[2];
 * pBuf++  =  cbaco.cbacocfg[numstruct].ip_self[1] << 16 + cbaco.cbacocfg[numstruct].ip_self[0];
 * pBuf++  =  0xffff;
 * pBuf++  =  0xffff;

  ipcrc = CalcChecksum((unsigned)HEADER_LEN; Buffer);

  */
  //  printfpd("\n\r %d :",numstruct);	  
  //  printfpd(" ip_self[3] : %x ",cbaco.cbacocfg[numstruct].ip_self[3] );	  
  //	printfpd("ip_self[2] : %x ",cbaco.cbacocfg[numstruct].ip_self[2] );
  //	printfpd("ip_self[1] : %x ",cbaco.cbacocfg[numstruct].ip_self[1] );
  //	printfpd("ip_self[0] : %x ",cbaco.cbacocfg[numstruct].ip_self[0] );


 unsigned ip11 = 0x4500;	 //ver and header length in words
 unsigned ip12 = iplen;	 //full length
 unsigned ip21 = 0x04e5; //ipident; //identif
 unsigned ip22 = 0x0000; //dont fragment
 unsigned ip31 = 0x8011; //time = 2 ip p prot tcp = 6
 unsigned ip32 = 0; //hier crc


/*
 unsigned ip41 = ((unsigned)cbaco.cbacocfg[numstruct].ip_self[3] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_self[2];  // 0xc0a8;//
 unsigned ip42 = ((unsigned)cbaco.cbacocfg[numstruct].ip_self[1] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_self[0];	//	  0x32;//0x64
 unsigned ip51 =  ((unsigned)cbaco.cbacocfg[numstruct].ip_dest[3] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_dest[2];  // 0xc0a8;////0xffff;
 unsigned ip52 = ((unsigned)cbaco.cbacocfg[numstruct].ip_dest[1] << 8) + (unsigned)cbaco.cbacocfg[numstruct].ip_dest[0];	//	  0x32;//0x64//0xffff;
*/

 unsigned ip41 = ((unsigned)dmu5.cfg.ip_self[3] << 8) + (unsigned)dmu5.cfg.ip_self[2];  // 0xc0a8;//
 unsigned ip42 = ((unsigned)dmu5.cfg.ip_self[1] << 8) + (unsigned)dmu5.cfg.ip_self[0];	//	  0x32;//0x64
 unsigned ip51 =  ((unsigned)dmu5.cfg.ip_dest[3] << 8) + (unsigned)dmu5.cfg.ip_dest[2];  // 0xc0a8;////0xffff;
 unsigned ip52 = ((unsigned)dmu5.cfg.ip_dest[1] << 8) + (unsigned)dmu5.cfg.ip_dest[0];	//	  0x32;//0x64//0xffff;



 ipcrc = ip11 + ip12 + ip21 + ip22 + ip31 + ip32 + ip41 + ip42 + ip51 + ip52;



 //udplen = 0; //temporary
  ipcrc = (ipcrc & 0xffff) + (ipcrc >> 16);

  ipcrc = ~(ipcrc);


 // printfpd(" ipcrc : %x :",ipcrc);	

 //printEthLongHex(ipcrc);

  //	outportb(l_base, RESET_ADDR);



	outportb(SEL_PORT , SEL_TGE01);


	outportb(l_base + RESET_ADDR , (unsigned char)1);

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)sample_max);

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 8));

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 16));

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 24));

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 32));

	outportb(ADDR_REG_ADDR, SAMPLEMAX_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR , (unsigned char)(sample_max >> 40));

   /*
	outportb(ADDR_REG_ADDR, NUMBLOCKS_ADDR);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].numOfBlocks);


	outportb(ADDR_REG_ADDR, NUMBLOCKS_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].numOfBlocks >> 8);

	outportb(ADDR_REG_ADDR, NUMBLOCKS_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].numOfBlocks >> 16);

	outportb(ADDR_REG_ADDR, NUMBLOCKS_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].numOfBlocks >> 24);

   */
	outportb(ADDR_REG_ADDR, SIZEBLOCKS_ADDR);
	outportb(l_base + DATA_REG_ADDR , packlen);//cbaco.cbacocfg[numstruct].sizeOfBlocks);

	outportb(ADDR_REG_ADDR, SIZEBLOCKS_ADDR+ 1);
	outportb(l_base + DATA_REG_ADDR , packlen >> 8); //cbaco.cbacocfg[numstruct].sizeOfBlocks >>8);


	outportb(ADDR_REG_ADDR, IPLEN_ADDR);
	outportb(l_base + DATA_REG_ADDR , iplen);	 //5 bytes

	outportb(ADDR_REG_ADDR, IPLEN_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , iplen >> 8);	 //


	outportb(ADDR_REG_ADDR, IPIDENT_ADDR);
	outportb(l_base + DATA_REG_ADDR , ipident);	 //4

	outportb(ADDR_REG_ADDR, IPIDENT_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , ipident >> 8);	 //4

	outportb(ADDR_REG_ADDR, IPCRC_ADDR);
	outportb(l_base + DATA_REG_ADDR , ipcrc);	 //4

	outportb(ADDR_REG_ADDR, IPCRC_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , ipcrc >> 8);	 //4

	outportb(ADDR_REG_ADDR, UDPLEN_ADDR);
	outportb(l_base + DATA_REG_ADDR , udplen);	 //4

	outportb(ADDR_REG_ADDR, UDPLEN_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , udplen >> 8);	 //4


  /*
 unsigned char mac_self[6];
   unsigned char mac_dest[6];
   unsigned char ip_self[4];
   unsigned char ip_dest[4];
   unsigned short port_self;
   unsigned short port_dest;
	*/


	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_self[0]);//. 0x90); // cbaco.cbacocfg[numstruct].mac_self[0]);
	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,  dmu5.cfg.mac_self[1]);//.0xe2); //cbaco.cbacocfg[numstruct].mac_self[1]);
	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_self[2]);//. 0xba); //cbaco.cbacocfg[numstruct].mac_self[2]);
	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_self[3]);//. sid >> 8); //cbaco.cbacocfg[numstruct].mac_self[3]);
	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_self[4]);//. sid); //cbaco.cbacocfg[numstruct].mac_self[4]);
	outportb(ADDR_REG_ADDR, MAC_SOURCE_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_self[5]);//. numslot); //cbaco.cbacocfg[numstruct].mac_self[5]);


	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.mac_dest[0]);//.0xff); //cbaco.cbacocfg[numstruct].mac_dest[0]); //	 0xff); //
	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.mac_dest[1]);//.0xff); //0xff); //cbaco.cbacocfg[numstruct].mac_dest[1]); //	 0xff); // 
	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.mac_dest[2]);//.0xff); //0xff); //cbaco.cbacocfg[numstruct].mac_dest[2]); //	 0xff); // 
	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.mac_dest[3]);//.0xff); // 0xff); //cbaco.cbacocfg[numstruct].mac_dest[3]); //  0xff); //
	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR + 4);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.mac_dest[4]);//.0xff); // 0xff); //cbaco.cbacocfg[numstruct].mac_dest[4]); //  0xff); //
	outportb(ADDR_REG_ADDR, MAC_DEST_ADDR + 5);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.mac_dest[5]);//.0xff); //0xff); //cbaco.cbacocfg[numstruct].mac_dest[5]); //	  0xff); // 

 //  tmp0	 = 	cbaco.cbacocfg[numstruct].ip_self[0];
 //  tmp1	 = 	cbaco.cbacocfg[numstruct].ip_self[1];
 //  tmp2	 = 	cbaco.cbacocfg[numstruct].ip_self[2];
 //  tmp3	 = 	cbaco.cbacocfg[numstruct].ip_self[3];


 //  tmp0	 = 	1;
  // tmp1	 = 	2;
 //  tmp2	 = 	3;
 //  tmp3	 = 	4;




  //  printfpd(" ip_self[3] : %x ",tmp0 );	  
  //	printfpd("ip_self[2] : %x ",tmp1 );
 //	printfpd("ip_self[1] : %x ",tmp2 );
  //	printfpd("ip_self[0] : %x ",tmp3 );
    

//   printEthLongHex(tmp0);



	outportb(ADDR_REG_ADDR, IP_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.ip_self[0]);//.0xff); // cbaco.cbacocfg[numstruct].ip_self[0]);   //  50);// //
	outportb(ADDR_REG_ADDR, IP_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.ip_self[1]);//  cbaco.cbacocfg[numstruct].ip_self[1]); //	 0);//
	outportb(ADDR_REG_ADDR, IP_SOURCE_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.ip_self[2]);// cbaco.cbacocfg[numstruct].ip_self[2]);	  //168);//
	outportb(ADDR_REG_ADDR, IP_SOURCE_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.ip_self[3]);// cbaco.cbacocfg[numstruct].ip_self[3]);	 //	192);//


	outportb(ADDR_REG_ADDR, IP_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.ip_dest[0]);// cbaco.cbacocfg[numstruct].ip_dest[0]); //	   0xff); // 
	outportb(ADDR_REG_ADDR, IP_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.ip_dest[1]);// cbaco.cbacocfg[numstruct].ip_dest[1]); //  0xff); //
	outportb(ADDR_REG_ADDR, IP_DEST_ADDR + 2);
	outportb(l_base + DATA_REG_ADDR ,  dmu5.cfg.ip_dest[2]);// cbaco.cbacocfg[numstruct].ip_dest[2]); //	0xff); //
	outportb(ADDR_REG_ADDR, IP_DEST_ADDR + 3);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.ip_dest[3]);//  cbaco.cbacocfg[numstruct].ip_dest[3]); //	0xff); //


	outportb(ADDR_REG_ADDR, UDP_SOURCE_ADDR);
	outportb(l_base + DATA_REG_ADDR , dmu5.cfg.port_self >> 8);	// 0xc3);//
	outportb(ADDR_REG_ADDR, UDP_SOURCE_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.port_self);	 //	  0x50); //


	outportb(ADDR_REG_ADDR, UDP_DEST_ADDR);
	outportb(l_base + DATA_REG_ADDR, dmu5.cfg.port_dest >>8);	 //	  0xc3); //
	outportb(ADDR_REG_ADDR, UDP_DEST_ADDR + 1);
	outportb(l_base + DATA_REG_ADDR ,dmu5.cfg.port_dest); //   0x50); //

	 
	outportb(ADDR_REG_ADDR, YEAR_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadYear());
	outportb(ADDR_REG_ADDR, MONTH_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadMonth());
	outportb(ADDR_REG_ADDR, DAY_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadDate());
	outportb(ADDR_REG_ADDR, HOUR_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadHours());
	outportb(ADDR_REG_ADDR, MIN_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadMin());
	outportb(ADDR_REG_ADDR, SEC_ADDR);
	outportb(l_base + DATA_REG_ADDR , ClockReadSec());
	 

	/*

	outportb(ADDR_REG_ADDR, N0_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n0);
	outportb(ADDR_REG_ADDR, N1_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n1);
	outportb(ADDR_REG_ADDR, N2_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n2);
	outportb(ADDR_REG_ADDR, N3_ADDR);
	outportb(l_base + DATA_REG_ADDR , pbsc->bscd[numstruct].n3);

	  */


 /*
#define NUMBLOCKS_ADDR  (3)	 //low byte of 4 
#define SIZEBLOCKS_ADDR (7)	  //low byte of 2
#define IPLEN_ADDR      (8)	  //low byte of 2
#define IPIDENT_ADDR 	(0xa)	  //low byte of 2
#define IPCRC_ADDR 		(0xc)	  //low byte of 2
#define UDPLEN_ADDR 	(0xe)	  //low byte of 2
#define MAC_SOURCE_ADDR (0x10)	  //low byte of 2
#define MAC_DEST_ADDR 	(0x16)	  //low byte of 2
#define IP_SOURCE_ADDR 	(0x1c)	  //low byte of 2
#define IP_DEST_ADDR 	(0x20)	  //low byte of 2
#defiwww.win2.cn/f
ne UDP_SOURCE_ADDR (0x24)	  //low byte of 2
#define UDP_DEST_ADDR 	(0x26)	  //low byte of 2
*/


//141201	outportb(ADDR_REG_ADDR, SIZEBLOCKS_ADDR + 1);
//	outportb(l_base + DATA_REG_ADDR , cbaco.cbacocfg[numstruct].sizeOfBlocks >> 8);
	

}





	

extern "C" void  ParseCommand10(char *IPBuff)  //
{
   unsigned char chn = IPBuff[1];
 //  unsigned char tmp = IPBuff[2];
   unsigned i;

		if(GetTestMode() == 0x5A)
	{	
	    printfp("Command10 decoder :");
	  		printfp("channel :");
		printfpd("%ld", chn);
	}

	 //	if(chn <= MAX_CNL)
		if(1)
	   	{

		 for(i = 0; i < SIZE_CUDP10CFG; i++)
		 {
		   dmu5.byte[i] =  IPBuff[i+2];
		 }



  			    LoadBacoDmu(1);
				LoadBacoStartZero();
				KeepDmu();

			  // 	KeepCBaco();


   			  //	SetNeedWriteDevId();	



  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

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


unsigned char writed_modul;
 extern unsigned char TFTP_Buffer1[TFTP_BUFFER_SIZE];

 /*
extern "C" void  ParseCommand6(char *IPBuff)  //writeram
{
 //  writed_modul = IPBuff[1];
   unsigned long sweep = (IPBuff[3]<<8) + (IPBuff[4]);
   unsigned long size = (IPBuff[5]<<8) + IPBuff[6];
   unsigned char *pData =  (unsigned char *)(&TFTP_Buffer1[0]);

	if(GetTestMode() == 0x5A)
	{	
	    printfp("Command6 modul :");
		printfpd("%lX", IPBuff[2]);
		printfp("size :");
		printfpd("%ld", size);

	printfp("sweep :");
		printfpd("%ld \n\r", sweep);

	}


  if((!CheckModulSK(IPBuff[2]))	|| ((sweep + size) >= TFTP_BUFFER_SIZE))
	{
	     add_char_TCP_buff(TYPE_RUN_BAD);
		 add_char_TCP_buff(IPBuff[0]);
		 add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
	}
  else
  {
	  writed_modul = IPBuff[2];
 	 pData += sweep;
   for(unsigned long i = 7; i < (size + 7); i++)
   {
    *pData  = IPBuff[i];
	if(GetTestMode() == 0x5A)
	{	
	   
	printfp("data ");
		printfpd(" %02X ", IPBuff[i]);
		printfp("addr ");
	   printfpd(" %d ", (unsigned long)pData);
	   pData++;
	}

   }


  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

 		   add_char_TCP_buff(TYPE_RUN_OK);
		   add_char_TCP_buff(IPBuff[0]);
		     add_char_TCP_buff(IPBuff[1]);

	 	   breakflag = 1;
   }
}

*/




extern "C" void  ParseCommand6(char *IPBuff)  //writeram
{
 //  writed_modul = IPBuff[1];
   unsigned long sweep = (IPBuff[3]<<24) + (IPBuff[4]<<16) +(IPBuff[5]<<8) +(IPBuff[6]);
   unsigned long size = (IPBuff[7]<<24) + (IPBuff[8]<<16) + (IPBuff[9]<<8)+ IPBuff[10];
   unsigned char *pData =  (unsigned char *)(&TFTP_Buffer1[0]);

   	if(GetTestMode() == 0x5A)
   	{	
	    printfp("Command6 modul :");
		printfpd("%lX", IPBuff[2]);
		printfp("size :");
		printfpd("%ld", size);

	printfp("sweep :");
		printfpd("%ld \n\r", sweep);

   	}


  if((!CheckModulSK(IPBuff[2]))	|| ((sweep + size) >= TFTP_BUFFER_SIZE))
	{
	     add_char_TCP_buff(TYPE_RUN_BAD);
		 add_char_TCP_buff(IPBuff[0]);
		 add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
	}
  else
  {
	  writed_modul = IPBuff[2];
 	 pData += sweep;
   for(unsigned long i = 11; i < (size + 11); i++)
   {
    *pData  = IPBuff[i];
   	if(GetTestMode() == 0x5A)
  	{	
 	    printfp("data ");
 		printfpd(" %02X ", IPBuff[i]);
 		printfp("addr ");
 	    printfpd(" %d ", (unsigned long)pData);
	 }
	 pData++;
  	

   }


  	  //	   unEmb2TypeVer.emb2TypeVer.signature_software[8] =  IPBuff[2];

 		   add_char_TCP_buff(TYPE_RUN_OK);
		   add_char_TCP_buff(IPBuff[0]);
		     add_char_TCP_buff(IPBuff[1]);

	 	   breakflag = 1;
   }
}

extern "C" void  ParseCommand7(char *IPBuff)  //write flash
{
	if((!CheckModulSK(writed_modul)))
	{
	     add_char_TCP_buff(TYPE_RUN_BAD);
		 add_char_TCP_buff(IPBuff[0]);
		 add_char_TCP_buff(NOT_CORRECT_PARAMETER);	
	}
  else
  {

   flag_write_flash = 1;
 //  unsigned char chn = IPBuff[1];
 //' unsigned char tmp = IPBuff[2];

	 	if(GetTestMode() == 0x5A)
	 	{	
	    printfp("Command7 ram ");
	 	}
  	   add_char_TCP_buff(TYPE_RUN_OK);
	   // add_char_TCP_buff(IPBuff[1]);
	   add_char_TCP_buff(IPBuff[0]); //dummy
	   add_char_TCP_buff(IPBuff[1]);
  }
	   breakflag = 1;
}

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


extern "C" void print_signature(void)
{
  printf("\n\r");
  for(i=0; i<16; i++)
	{
	  printf(" %02X",	unEmb2TypeVer.emb2TypeVer.signature_hardware[i]);
	}
}






