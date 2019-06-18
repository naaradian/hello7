//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : dataflash.c
//* Object              : High level functions for the dataflash
//* Creation            : HIi   10/10/2003
//*----------------------------------------------------------------------------

#include <stdio.h> 
#include <string.h> 
#include <dataflash.h>
//#include <at91rm9200.h>
//____________________
//#include <mqx.h>
//#include <bsp.h>
//#include <log.h>
//#include <klog.h>
//#include <rtcs.h>
//#include <enet.h>
#include "hello7.h"     //t
//#include "io_prv.h"
//#include "psp_prv.h"
//#include "spi_pol.h"
//#include "spi_polpv.h"
//___________________
//extern pointer fh_ptr;

#define PART_SIZE (200) //max length why i can send through spi continuosly
extern "C" AT91PS_DataFlash AT91F_DataflashSelectx (AT91PS_DataFlash pFlash,
										unsigned int *addr);


AT91S_DATAFLASH_INFO dataflash_info[CFG_MAX_DATAFLASH_BANKS];
#ifdef XIL_FLASH

AT91S_DATAFLASH_INFO dataflash_infox[CFG_MAX_DATAFLASH_BANKSX];  //need init
int csx[][CFG_MAX_DATAFLASH_BANKSX] = {
	{CFG_DATAFLASH_LOGIC_ADDR_CS0X, 0},	/* Logical adress, CS */
   {CFG_DATAFLASH_LOGIC_ADDR_CS1X, 1},
   {CFG_DATAFLASH_LOGIC_ADDR_CS2X, 2},
   {CFG_DATAFLASH_LOGIC_ADDR_CS3X, 3},
   {CFG_DATAFLASH_LOGIC_ADDR_CS4X, 4},
   {CFG_DATAFLASH_LOGIC_ADDR_CS5X, 5},
   {CFG_DATAFLASH_LOGIC_ADDR_CS6X, 6},
   {CFG_DATAFLASH_LOGIC_ADDR_CS7X, 7},
   {CFG_DATAFLASH_LOGIC_ADDR_CS8X, 8},
   {CFG_DATAFLASH_LOGIC_ADDR_CS9X, 9},
   {CFG_DATAFLASH_LOGIC_ADDR_CS10X,10},
   {CFG_DATAFLASH_LOGIC_ADDR_CS11X, 11},
   {CFG_DATAFLASH_LOGIC_ADDR_CS12X, 12},
   {CFG_DATAFLASH_LOGIC_ADDR_CS13X, 13},
   {CFG_DATAFLASH_LOGIC_ADDR_CS14X, 14},
   {CFG_DATAFLASH_LOGIC_ADDR_CS15X, 15},
   
};
static AT91S_DataFlash DataFlashInstx;
#endif

static AT91S_DataFlash DataFlashInst;

int cs[][CFG_MAX_DATAFLASH_BANKS] = {
	{CFG_DATAFLASH_LOGIC_ADDR_CS0, 0},	/* Logical adress, CS */
 //	{CFG_DATAFLASH_LOGIC_ADDR_CS3, 3}
   {CFG_DATAFLASH_LOGIC_ADDR_CS1, 1},
     {CFG_DATAFLASH_LOGIC_ADDR_CS2, 2}   //160316

   
};

int AT91F_DataflashInit (void)
{
// printfp1("\n\r AT91F_DataflashInit ");

	int i;
	int dfcode;
//______________________________________________________________init_global_data

   cs[0][0] = CFG_DATAFLASH_LOGIC_ADDR_CS0;
   cs[0][1] = 0;
//   cs[1][0] = CFG_DATAFLASH_LOGIC_ADDR_CS3;
//   cs[1][1] = 3;
   cs[1][0] = CFG_DATAFLASH_LOGIC_ADDR_CS1;
   cs[1][1] = 1;
   
   cs[2][0] = CFG_DATAFLASH_LOGIC_ADDR_CS2;
   cs[2][1] = 2;

   
   
   
 
//______________________________________________________________		
	AT91F_SpiInit ();

	for (i = 0; i < CFG_MAX_DATAFLASH_BANKS; i++) {
		dataflash_info[i].Desc.state = IDLE;
		dataflash_info[i].id = 0;
		dataflash_info[i].Device.pages_number = 0;
     // if(i == 1)
     // { 
     //    for(int j = 0; j < 1000; j++ )
     //		dfcode = AT91F_DataflashProbe (cs[i][1], &dataflash_info[i].Desc);
     // }
     // else
          dfcode = AT91F_DataflashProbe (cs[i][1], &dataflash_info[i].Desc);

         if(start_main_loop)
      {
  //        printfpd1(" dfcode = %d ", dfcode);
     }


		switch (dfcode) {
		case AT45DB161:
       if(start_main_loop)
      {
    //      printfp1("   AT45DB161 ");
     }          

			dataflash_info[i].Device.pages_number = 4096;
			dataflash_info[i].Device.pages_size = 528;
			dataflash_info[i].Device.page_offset = 10;
			dataflash_info[i].Device.byte_mask = 0x300;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;
         
		case AT45DB041E:
       if(start_main_loop)
      {
   //       printfp1("   AT45DB041E ");
     }          

 	      dataflash_info[i].Device.pages_number = 2048;
			dataflash_info[i].Device.pages_size = 264;//264;
			dataflash_info[i].Device.page_offset =9;// ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x00;// - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;      
         
			break;
         

		case AT45DB321:
      if(start_main_loop)
      {
   //       printfp1("   AT45DB321 ");
     }

			dataflash_info[i].Device.pages_number = 8192;
			dataflash_info[i].Device.pages_size = 528;
			dataflash_info[i].Device.page_offset = 10;
			dataflash_info[i].Device.byte_mask = 0x300;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;

		case AT45DB642:
   //   printfp("   AT45DB642 ");
    if(start_main_loop)
      {
   //       printfp1("   AT45DB642 ");
     }


			dataflash_info[i].Device.pages_number = 8192;   //32768
			dataflash_info[i].Device.pages_size = 1056;    //264
			dataflash_info[i].Device.page_offset = 11;    //9 ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x700;  //0x100 - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;
         
      case AT45DB641E:
   //     printfp("   AT45DB641E ");
     if(start_main_loop)
      {
   //       printfp1("   AT45DB641E ");
     }


			dataflash_info[i].Device.pages_number = 32768;
			dataflash_info[i].Device.pages_size = 264;//264;
			dataflash_info[i].Device.page_offset =9;// ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x00;// - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;      
         
         
		case AT45DB128:
			dataflash_info[i].Device.pages_number = 16384;
			dataflash_info[i].Device.pages_size = 1056;
			dataflash_info[i].Device.page_offset = 11;
			dataflash_info[i].Device.byte_mask = 0x700;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;

		default:
        //          printfp("Flash Is Not Found");
          if(start_main_loop)
      {
   //     printfp1("Flash Is Not Found");
     }


      
                   if(!i)
                   {
                   //  printfp("  wrong flash");

                   dev_restart();   //zero flash shold be good!!!
                   }
		break;
		}
	}			
	return (1);
}


int AT91F_DataflashInit1 (void)   //for test only cs2
{
// printfp("\n\r AT91F_DataflashInit ");

	int i;
	int dfcode;
//______________________________________________________________init_global_data

   cs[0][0] = CFG_DATAFLASH_LOGIC_ADDR_CS0;
   cs[0][1] = 0;
//   cs[1][0] = CFG_DATAFLASH_LOGIC_ADDR_CS3;
//   cs[1][1] = 3;
   cs[1][0] = CFG_DATAFLASH_LOGIC_ADDR_CS1;
   cs[1][1] = 1;
   
   cs[2][0] = CFG_DATAFLASH_LOGIC_ADDR_CS2;
   cs[2][1] = 2;

   
   
   
 
//______________________________________________________________		
	AT91F_SpiInit ();

 //	for (i = 1; i < 2; i++) {
 	for (i = 2; i < 3; i++) {
		dataflash_info[i].Desc.state = IDLE;
		dataflash_info[i].id = 0;
		dataflash_info[i].Device.pages_number = 0;
		dfcode = AT91F_DataflashProbe (cs[i][1], &dataflash_info[i].Desc);

		switch (dfcode) {
		case AT45DB161:
   //       printfp("   AT45DB161 ");

			dataflash_info[i].Device.pages_number = 4096;
			dataflash_info[i].Device.pages_size = 528;
			dataflash_info[i].Device.page_offset = 10;
			dataflash_info[i].Device.byte_mask = 0x300;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;

		case AT45DB321:
   //     printfp("   AT45DB321 ");

			dataflash_info[i].Device.pages_number = 8192;
			dataflash_info[i].Device.pages_size = 528;
			dataflash_info[i].Device.page_offset = 10;
			dataflash_info[i].Device.byte_mask = 0x300;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;

		case AT45DB642:
   //   printfp("   AT45DB642 ");

			dataflash_info[i].Device.pages_number = 8192;   //32768
			dataflash_info[i].Device.pages_size = 1056;    //264
			dataflash_info[i].Device.page_offset = 11;    //9 ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x700;  //0x100 - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;
         
      case AT45DB641E:
   //     printfp("   AT45DB641E ");

			dataflash_info[i].Device.pages_number = 32768;
			dataflash_info[i].Device.pages_size = 264;//264;
			dataflash_info[i].Device.page_offset =9;// ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x00;// - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;      
         
         
		case AT45DB128:
			dataflash_info[i].Device.pages_number = 16384;
			dataflash_info[i].Device.pages_size = 1056;
			dataflash_info[i].Device.page_offset = 11;
			dataflash_info[i].Device.byte_mask = 0x700;
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;

		default:
        //          printfp("Flash Is Not Found");

      
                   if(!i)
                   {
                   //  printfp("  wrong flash");

                   dev_restart();   //zero flash shold be good!!!
                   }
		break;
		}
	}			
	return (1);
}


#ifdef XIL_FLASH

int AT91F_DataflashInitx (void)
{
  //	printfp ("AT91F_DataflashInitx");
#ifdef DEBUG_WRITE_XIL
  printfp("\n\rAT91F_DataflashInitx ");
#endif
  

	int i;
	int dfcode;
//______________________________________________________________init_global_data

   csx[0][0] = CFG_DATAFLASH_LOGIC_ADDR_CS0X;
   csx[0][1] = 0 + XIL_FLASH_OFFSET;
   csx[1][0] = CFG_DATAFLASH_LOGIC_ADDR_CS1X;
 //  csx[1][1] = 1 + XIL_FLASH_OFFSET;
   csx[1][1] = IF_FLASH_OFFSET;
   csx[2][0] = CFG_DATAFLASH_LOGIC_ADDR_CS2X;
   csx[2][1] = 2 + XIL_FLASH_OFFSET;
   csx[3][0] = CFG_DATAFLASH_LOGIC_ADDR_CS3X;
   csx[3][1] = 3 + XIL_FLASH_OFFSET;
   csx[4][0] = CFG_DATAFLASH_LOGIC_ADDR_CS4X;
   csx[4][1] = 4 + XIL_FLASH_OFFSET;
   csx[5][0] = CFG_DATAFLASH_LOGIC_ADDR_CS5X;
   csx[5][1] = 5 + XIL_FLASH_OFFSET;
   csx[6][0] = CFG_DATAFLASH_LOGIC_ADDR_CS6X;
   csx[6][1] = 6 + XIL_FLASH_OFFSET;
   csx[7][0] = CFG_DATAFLASH_LOGIC_ADDR_CS7X;
   csx[7][1] = 7 + XIL_FLASH_OFFSET;
   csx[8][0] = CFG_DATAFLASH_LOGIC_ADDR_CS8X;
   csx[8][1] = 8 + XIL_FLASH_OFFSET;
   csx[9][0] = CFG_DATAFLASH_LOGIC_ADDR_CS9X;
   csx[9][1] = 9 + XIL_FLASH_OFFSET;
   csx[10][0] = CFG_DATAFLASH_LOGIC_ADDR_CS10X;
   csx[10][1] = 10 + XIL_FLASH_OFFSET;
   csx[11][0] = CFG_DATAFLASH_LOGIC_ADDR_CS11X;
   csx[11][1] = 11 + XIL_FLASH_OFFSET;
   csx[12][0] = CFG_DATAFLASH_LOGIC_ADDR_CS12X;
   csx[12][1] = 12 + XIL_FLASH_OFFSET;
   csx[13][0] = CFG_DATAFLASH_LOGIC_ADDR_CS13X;
   csx[13][1] = 13 + XIL_FLASH_OFFSET;
   csx[14][0] = CFG_DATAFLASH_LOGIC_ADDR_CS14X;
   csx[14][1] = 14 + XIL_FLASH_OFFSET;
   csx[15][0] = CFG_DATAFLASH_LOGIC_ADDR_CS15X;
   csx[15][1] = 15 + XIL_FLASH_OFFSET;
  
  
//______________________________________________________________		
//	AT91F_SpiInit ();

 //	for (i = 0; i < CFG_MAX_DATAFLASH_BANKSX; i++) {
#ifndef PROG_MD310_SATI2
  for (i = 0; i < 2; i++) {
#else  
#ifndef PROG_ODU1
  for (i = 1; i < 2; i++) {     //141119
#else
  for (i = 0; i < 1; i++) { 
#endif  
  
  
#endif  
  
//t 	for (i = 0; i < 1; i++) { 
		dataflash_infox[i].Desc.state = IDLE;
		dataflash_infox[i].id = AT45DB041;
		dataflash_infox[i].Device.pages_number = 2048;
      
 //__________________________________________________
 	dataflash_infox[i].Device.pages_number = 2048;
			dataflash_infox[i].Device.pages_size = 264;
			dataflash_infox[i].Device.page_offset = 9; //?
	  		dataflash_infox[i].Device.byte_mask = 0x700;
    // 		dataflash_infox[i].Device.byte_mask = 0x300;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = AT45DB041;
 
 
 
 //__________________________________________________     
      
      
      
      
  //     printfpd ("\n\r csx[i][1] : %d", csx[i][1]);
  
 // printfp ("  code : ");
#ifdef REAL_PROBE 
 	dfcode = AT91F_DataflashProbex (csx[i][1], &dataflash_infox[i].Desc);
 //   dfcode = AT45DB041; //t
#else    
   dfcode = AT45DB041;   //141119
#endif   
   
//   printfpd ("\n\r__________code : 0x%x", dfcode);
#ifdef DEBUG_WRITE_XIL
  printfpd("\n\r__________code : 0x%x", dfcode);
#endif
   
      
        /*
  
  for(unsigned j = 0; j < 5; j ++)
  { 
 		dfcode = AT91F_DataflashProbex (csx[i][1], &dataflash_infox[i].Desc);
       printfpd ("c: %x ", dfcode);
         printfpd ("j: %d ", j);

      if(dfcode == AT45DB041) j = 5;
      if(!(j % 10))  printfp (" \n\r");
  }    
          */
      

		switch (dfcode) {
      
      case AT45DB041:       //0x1c
 #ifdef DEBUG_WRITE_XIL
      printfp("\n\rselect flash  AT45DB041");
#endif      
      
			dataflash_infox[i].Device.pages_number = 2048;
			dataflash_infox[i].Device.pages_size = 264;
			dataflash_infox[i].Device.page_offset = 9; //?
  //160622	  		dataflash_infox[i].Device.byte_mask = 0x700;
  //t	  		dataflash_infox[i].Device.byte_mask = 0x0;  //160622
            	dataflash_infox[i].Device.byte_mask = 0x100; 
    // 		dataflash_infox[i].Device.byte_mask = 0x300;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
			break;

      
		case AT45DB161:
   //     printfp("\n\r AT45DB161");
			dataflash_infox[i].Device.pages_number = 4096;
			dataflash_infox[i].Device.pages_size = 528;
			dataflash_infox[i].Device.page_offset = 10;
			dataflash_infox[i].Device.byte_mask = 0x300;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
			break;
         
         
         
		case AT45DB041E:
       if(start_main_loop)
      {
          printfp("   AT45DB041E ");
     }          

 	      dataflash_info[i].Device.pages_number = 2048;
			dataflash_info[i].Device.pages_size = 264;//264;
			dataflash_info[i].Device.page_offset =9;// ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x00;// - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;      
         
			break;
         
         

		case AT45DB321:
   //     printfp("\n\r AT45DB321");
			dataflash_infox[i].Device.pages_number = 8192;
			dataflash_infox[i].Device.pages_size = 528;
			dataflash_infox[i].Device.page_offset = 10;
			dataflash_infox[i].Device.byte_mask = 0x300;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
			break;
         
    case AT45DB641E:
   //     printfp("   AT45DB641E ");

			dataflash_info[i].Device.pages_number = 32768;
			dataflash_info[i].Device.pages_size = 264;//264;
			dataflash_info[i].Device.page_offset =9;// ????   9 bits can make byte address in page
			dataflash_info[i].Device.byte_mask = 0x00;// - one bit in 3 byte used for byte address
			dataflash_info[i].Device.cs = cs[i][1];
			dataflash_info[i].Desc.DataFlash_state = IDLE;
			dataflash_info[i].logical_address = cs[i][0];
			dataflash_info[i].id = dfcode;
			break;      
         
         

		case AT45DB642:
    //    printfp("\n\r AT45DB642");
			dataflash_infox[i].Device.pages_number = 8192;
			dataflash_infox[i].Device.pages_size = 1056;
			dataflash_infox[i].Device.page_offset = 11;
			dataflash_infox[i].Device.byte_mask = 0x700;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
			break;
		case AT45DB128:
   //     printfp("\n\r AT45DB128");
			dataflash_infox[i].Device.pages_number = 16384;
			dataflash_infox[i].Device.pages_size = 1056;
			dataflash_infox[i].Device.page_offset = 11;
			dataflash_infox[i].Device.byte_mask = 0x700;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
			break;

		default:
   //     printfp("\n\r default mem1");
 #ifdef DEBUG_WRITE_XIL
      printfp("\n\rselect flash  UNDEFINED (((((!!!!!");
#endif        
          
	      dataflash_infox[i].Device.pages_number = 0;
	 		dataflash_infox[i].Device.pages_size = 0;
	 		dataflash_infox[i].Device.page_offset = 0;
	 		dataflash_infox[i].Device.byte_mask = 0x700;
	 		dataflash_infox[i].Device.cs = csx[i][1];
	 		dataflash_infox[i].Desc.DataFlash_state = IDLE;
	 		dataflash_infox[i].logical_address = csx[i][0];
	 		dataflash_infox[i].id = dfcode;
         
     
          /*
  		   dataflash_infox[i].Device.pages_number = 2048;
			dataflash_infox[i].Device.pages_size = 264;
			dataflash_infox[i].Device.page_offset = 9; //?
	  		dataflash_infox[i].Device.byte_mask = 0x700;
    // 	dataflash_infox[i].Device.byte_mask = 0x300;
			dataflash_infox[i].Device.cs = csx[i][1];
			dataflash_infox[i].Desc.DataFlash_state = IDLE;
			dataflash_infox[i].logical_address = csx[i][0];
			dataflash_infox[i].id = dfcode;
           */
         
         
      
			break;
		}
	}	  //for		
	return (1);
}


#endif

 /*
void AT91F_DataflashPrintInfo(void)
{
	int i;
     // _io_set_handle(IO_STDOUT, fh_ptr);  
        printfp("\n\rAT91F_DataflashPrintInfo");
	for (i = 0; i < CFG_MAX_DATAFLASH_BANKS; i++) {
		if (dataflash_info[i].id != 0) {
			printf ("DataFlash:");
			switch (dataflash_info[i].id) {
			case AT45DB161:
				printfp ("AT45DB161\n\r");
				break;

			case AT45DB321:
				printfp ("AT45DB321\n\r");
				break;

			case AT45DB642:
				printf ("AT45DB642\n\r");
				break;
            
			case AT45DB128:				
				printfp ("AT45DB128\n\r");
				break;
            
          case AT45DB641E:
           printfp ("AT45DB641E\n\r");
				break;


			}
      }
	}
}
      */
  
/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataflashSelect 					*/
/* Object              : Select the correct device				*/
/*------------------------------------------------------------------------------*/
AT91PS_DataFlash AT91F_DataflashSelect (AT91PS_DataFlash pFlash,
										unsigned int *addr)
{
	char addr_valid = 0;
	int i;
 

	for (i = 0; i < CFG_MAX_DATAFLASH_BANKS; i++){ 
 //  if(start_main_loop)
//{
   

   
//        return 0;
//
  //     printfpd("\n\r addr = 0x%X", (*addr & 0xFF000000));
  //     printfpd(" dataflash_info[i].logical_address: 0x%X",   dataflash_info[i].logical_address);
//#endif 
 //}

   
   
   
		if ((*addr & 0xFF000000) == dataflash_info[i].logical_address) {
			addr_valid = 1;
			break;
		}
      
      
      }
      
// #ifdef TEST_HANGING      
//if(start_main_loop)
//{
   

 //     printfp("\n\rAT91F_DataflashSelect ");
 //     OperateBuffers_usart0t();
//        return 0;
//
  //     printfpd("  i =  %d",   i);
  //     printfpd("pages : %d",   dataflash_info[i].Device.pages_number);
//#endif 
 //}
if (!dataflash_info[i].Device.pages_number) {         //my
		pFlash = (AT91PS_DataFlash) 0;
      
  //     printfp("\n\r___________zero pages!!!");

		return pFlash;
	}
              
      
      
	if (!addr_valid) {
		pFlash = (AT91PS_DataFlash) 0;
		return pFlash;
	}
	pFlash->pDataFlashDesc = &(dataflash_info[i].Desc);
	pFlash->pDevice = &(dataflash_info[i].Device);
	*addr -= dataflash_info[i].logical_address;
	return (pFlash);
}


#ifdef XIL_FLASH

/*------------------------------------------------------------------------------*/
/* Function Name       : AT91F_DataflashSelectx 					*/
/* Object              : Select the correct device				*/
/*------------------------------------------------------------------------------*/
extern "C" AT91PS_DataFlash AT91F_DataflashSelectx (AT91PS_DataFlash pFlash,
										unsigned int *addr)
{
// printfp("\n\r AT91F_DataflashSelectx");
#ifdef DEBUG_WRITE_XIL
 printfp("\n\r AT91F_DataflashSelectx");
#endif


	char addr_valid = 0;
	int i;                       
//     printfpd("\n\ra: %X",(*addr & 0xFF000000));
 //    printfpd("\n\rf: %X",(dataflash_infox[0].logical_address));


//	for (i = 0; i < CFG_MAX_DATAFLASH_BANKSX; i++)
#ifdef PROG_MD310_SATI2	
 //141107	for (i = 0; i < 1; i++)
// for (i = 0; i < CFG_MAX_DATAFLASH_BANKSX; i++)
#ifndef MAKET_PLATA

 for (i = 0; i < 2; i++)
#else
  for (i = 0; i < 0; i++)

#endif 
 
 
 
#else
 for (i = 0; i < 1; i++)
#endif 
 {
  //   printfpd("\n\ri: %d", i);
    //   printfpd(" logical_address : %x", dataflash_infox[i].logical_address);

		if ((*addr & 0xFF000000) == dataflash_infox[i].logical_address)
       {      //need init!!!!
			addr_valid = 1;
#ifdef DEBUG_WRITE_XIL
// printfpd("\n\r AT91F_DataflashSelectx");
  printfpd("\n\ri: %d", i);
    printfp("  addr valid!");

#endif
         
   //      printfp("\n\r addr valid!");
		break;
		}
   }
      
	if (!addr_valid) 
   {
  //   printfp("\n\r addr NOT valid!");
#ifdef DEBUG_WRITE_XIL
// printfpd("\n\r AT91F_DataflashSelectx");
      printfp("\n\r addr NOT valid!");

#endif
  
		pFlash = (AT91PS_DataFlash) 0;
		return pFlash;
	}
 //  printfp("\n\r AT91F_DataflashSelectx");
	pFlash->pDataFlashDesc = &(dataflash_infox[i].Desc);
	pFlash->pDevice = &(dataflash_infox[i].Device);
	*addr -= dataflash_infox[i].logical_address;
   
 //   printfpd("\n\ri: %d",i);
 //    printfpd(" pn: %d",dataflash_infox[i].Device.pages_number);
 #ifdef DEBUG_WRITE_XIL
// printfpd("\n\r AT91F_DataflashSelectx");
//  printfpd("\n\ri: %d", i);
        printfpd("\n\rhave pages number: %d",dataflash_infox[i].Device.pages_number);
        printfpd("\n\rhave pages_size : %d", dataflash_infox[i].Device.pages_size); 

#endif


	return (pFlash);
}
#endif


/*------------------------------------------------------------------------------*/
/* Function Name       : addr_dataflash 					*/
/* Object              : Test if address is valid				*/
/*------------------------------------------------------------------------------*/
int addr_dataflash (unsigned long addr)
{
	int addr_valid = 0;
	int i;

	for (i = 0; i < CFG_MAX_DATAFLASH_BANKS; i++) {
		if ((((int) addr) & 0xFF000000) ==
			dataflash_info[i].logical_address) {
			addr_valid = 1;
			break;
		}
	}

	return addr_valid;
}

/*------------------------------------------------------------------------------*/
/* Function Name       : read_dataflash 					*/
/* Object              : dataflash memory read					*/
/*------------------------------------------------------------------------------*/
int read_dataflash (unsigned long addr, unsigned long size, char *result)
{
	unsigned int AddrToRead = addr;
	AT91PS_DataFlash pFlash = &DataFlashInst;
   
// AT91RM9200_AIC_REG_STRUCT_PTR aic_ptr = (AT91RM9200_AIC_REG_STRUCT_PTR)AT91RM9200_AIC_BASE;      //my
  unsigned int imr =  ReadAis();
//  aic_ptr->IDCR = 0xFFFFFFFFl;
   
   

	pFlash = AT91F_DataflashSelect (pFlash, &AddrToRead);
   
   WriteAis(imr);
   
	if (pFlash == 0)
   {    
      if(start_main_loop) printfp("\n\rpFlash == 0!");	
		return -1;
   }
   
    	return (AT91F_DataFlashRead (pFlash, AddrToRead, size, result));
  //  return (0); //t
}

/*-----------------------------------------------------------------------------*/
/* Function Name       : write_dataflash1 				       */
/* Object              : write a block in dataflash			       */
/*-----------------------------------------------------------------------------*/
int write_dataflash1 (unsigned long addr_dest, unsigned int addr_src,
		     unsigned int size)
{
	unsigned int AddrToWrite = addr_dest;
	AT91PS_DataFlash pFlash = &DataFlashInst;
//unsigned int imr;
//#ifdef TEST_REMOTE_FF
//			  printfp("\n\rwrite dataflash");
//#endif
#ifdef TEST_HANGING      
       printfp("\n\rwrite dataflash1 ");
       OperateBuffers_usart0t();
 //      return 0;
#endif       

//hier hangt on second flash if do not have property state 
//t  imr =  ReadAis();  //hier crash
    //   return 0;     //t

 	pFlash = AT91F_DataflashSelect (pFlash, &AddrToWrite);
   
#ifdef TEST_HANGING      
      printfp("\n\rWriteAis1 ");
      OperateBuffers_usart0t();
    //    return 0;
//
#endif        
  //t   WriteAis(imr);
	if (AddrToWrite == -1)
		return -1;
      
   if(!pFlash){ /* Body */
   
     printfp("\n\rreturn to zero!!! ");
     return -1;

} /* Endbody */
      
 //  return 0;   

	return AT91F_DataFlashWrite (pFlash, (unsigned char *) addr_src, AddrToWrite, size);
}



/*-----------------------------------------------------------------------------*/
/* Function Name       : write_dataflash 				       */
/* Object              : write a block in dataflash			       */
/*-----------------------------------------------------------------------------*/
int write_dataflash (unsigned long addr_dest, unsigned int addr_src,
		     unsigned int size)
{
	unsigned int AddrToWrite = addr_dest;
	AT91PS_DataFlash pFlash = &DataFlashInst;
//#ifdef TEST_REMOTE_FF
//			  printfp("\n\rwrite dataflash");
//#endif
//#ifdef TEST_HANGING      
//       printfp("\n\rwrite dataflash ");
//       OperateBuffers_usart0t();
   //ok    return 0;
//#endif       

//hier hangt on second flash if do not have property state 
    unsigned int imr =  ReadAis();
	pFlash = AT91F_DataflashSelect (pFlash, &AddrToWrite);
//#ifdef TEST_HANGING      
 //     printfp("\n\rWriteAis ");
   //   OperateBuffers_usart0t();
//        return 0;
//
//#endif        
     WriteAis(imr);
     
 if(!pFlash){ 
   
   //  printfp("\n\rreturn to zero!!! ");
     return -1;

}
     
	if (AddrToWrite == -1)
		return -1;

	return AT91F_DataFlashWrite (pFlash, (unsigned char *) addr_src, AddrToWrite, size);
}

/*-----------------------------------------------------------------------------*/
/* Function Name       : write_dataflash 				       */
/* Object              : write a block in dataflash			       */
/*-----------------------------------------------------------------------------*/
int check_dataflash (unsigned long addr_dest)
{
	unsigned int AddrToWrite = addr_dest;
	AT91PS_DataFlash pFlash = &DataFlashInst;
//#ifdef TEST_REMOTE_FF
//			  printfp("\n\rwrite dataflash");
//#endif
//#ifdef TEST_HANGING      
//       printfp("\n\rwrite dataflash ");
//       OperateBuffers_usart0t();
   //ok    return 0;
//#endif

//       

//hier hangt on second flash if do not have property state 
 //   unsigned int imr =  ReadAis();
   // AT91F_DataflashSelect (pFlash, &AddrToWrite);
   AT91F_DataflashInit(); //make this after reset xilinx
   pFlash = AT91F_DataflashSelect (pFlash, &AddrToWrite);
//   pFlash = AT91F_DataflashSelect (pFlash, &AddrToWrite);
//#ifdef TEST_HANGING      
 //     printfp("\n\rWriteAis ");
   //   OperateBuffers_usart0t();
//        return 0;
//
//#endif        
  //   WriteAis(imr);
     
 if(!pFlash){ 
   
     printfp("\n\rreturn to zero!!! ");
     return 1;

}
    return 0; 
}


#ifdef XIL_FLASH
/*------------------------------------------------------------------------------*/
/* Function Name       : read_dataflashx 					*/
/* Object              : dataflash memory read					*/
/*------------------------------------------------------------------------------*/
int read_dataflashx (unsigned long addr, unsigned long size, char *result)
{
  int ret = 0;
	unsigned int AddrToRead = addr;
   
   char*  part_result = result;
   
   unsigned int part_size = PART_SIZE;
   unsigned int wait_read_size = size;
   
   
	AT91PS_DataFlash pFlash = &DataFlashInstx;

	pFlash = AT91F_DataflashSelectx (pFlash, &AddrToRead);
	if (pFlash == 0)
   { 
 //      printfp("\n\r do not found flash memory ");
   		return -1;
    }
    else{ /* Body */
 //      printfp("\n\r found flash memory ");

   } /* Endbody */
   
   
   
   
      
    while(wait_read_size > PART_SIZE)
    {
   //  printfpd(" %d", wait_read_size);
    
    ret |=AT91F_DataFlashReadx (pFlash, AddrToRead, part_size, part_result);
    
    wait_read_size -=  PART_SIZE;
    AddrToRead += PART_SIZE;
    part_result +=  PART_SIZE;
    } 
      

 	ret |=AT91F_DataFlashReadx (pFlash, AddrToRead, wait_read_size, part_result);
   
   return ret;
  //  return (0); //t
}


//#define PART_SIZE (256 - 8) //max length why i can send through spi continuosly

/*-----------------------------------------------------------------------------*/
/* Function Name       : write_dataflashx 				       */
/* Object              : write a block in dataflash			       */
/*-----------------------------------------------------------------------------*/
int write_dataflashx (unsigned long addr_dest, unsigned int addr_src,
		     unsigned int size)
{

   int ret = 0;
	unsigned int AddrToWrite = addr_dest;
   unsigned int part_addr_src = addr_src;
   unsigned int part_size = PART_SIZE;
   unsigned int wait_write_size = size;
   
	AT91PS_DataFlash pFlash = &DataFlashInstx;   
 //  printfp("\n\rwrite_dataflashx start");
  // return; //t141107
#ifdef DEBUG_WRITE_XIL
     printfpd ("\n\r write_dataflashx start  size : %d", size);
#endif  
   
	pFlash = AT91F_DataflashSelectx (pFlash, &AddrToWrite);
   
	if (AddrToWrite == -1)
{
#ifdef DEBUG_WRITE_XIL
        printfp("\n\rdo not have access to flash");

#endif  

  
  return -1;
 
}
#ifdef DEBUG_WRITE_XIL
        printfp("\n\rflash is found");

#endif  



	  //  printfp("\n\rwrite_dataflashx next");
 
  //   return; //t141107
     
    while(wait_write_size > PART_SIZE)
    { 
    wd_reset();
    #ifdef DEBUG_WRITE_XIL
     OperateBuffers_usart0t();
#endif  

    
      wait_write_size -=  PART_SIZE;
      ret |= AT91F_DataFlashWritex (pFlash, (unsigned char *) part_addr_src, AddrToWrite, part_size);
      AddrToWrite +=  PART_SIZE;
      part_addr_src += PART_SIZE;
     } 
     part_size =  wait_write_size;
   ret |= AT91F_DataFlashWritex (pFlash, (unsigned char *) part_addr_src, AddrToWrite, wait_write_size);
 //ok return 0; //t
 
 
 return ret;
}



#endif