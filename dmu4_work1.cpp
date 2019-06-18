#ifdef	PROG_PRM_PCH_DEM_XIL_CHN_DMU4

#define MAX_SIZE_DIFF_FILE9 (524288l)
#define MAX_SIZE_PREV_FILE9 (2048)

#define MAX_SIZE_DIFF_FILE8 (65536)
#define MAX_SIZE_PREV_FILE8 (256)

#define MAX_SIZE_DIFF_FILE7 (16384)
#define MAX_SIZE_PREV_FILE7 (256)

#define MAX_SIZE_DIFF_FILE6 (4096)
#define MAX_SIZE_PREV_FILE6 (64)

#define MAX_SIZE_DIFF_FILE5 (1024)
#define MAX_SIZE_PREV_FILE5 (64)

#define MAX_SIZE_DIFF_FILE4 (256)
#define MAX_SIZE_PREV_FILE4 (16)

#define MAX_SIZE_DIFF_FILE3 (16)
#define MAX_SIZE_PREV_FILE3 (4)

#define MAX_SIZE_DIFF_FILE2 (16)
#define MAX_SIZE_PREV_FILE2 (4)

#define MAX_SIZE_DIFF_FILE1 (2)
#define MAX_SIZE_PREV_FILE1 (1)


#define MAX_SIZE_COMM_FILE9 (525440)
#define MAX_SIZE_COMM_FILE8 (65792)
#define MAX_SIZE_COMM_FILE7 (16448)
#define MAX_SIZE_COMM_FILE6 (4160)
#define MAX_SIZE_COMM_FILE5 (1060)
#define MAX_SIZE_COMM_FILE4 (272)
#define MAX_SIZE_COMM_FILE3 (20)
#define MAX_SIZE_COMM_FILE2 (20)
#define MAX_SIZE_COMM_FILE1 (2)



 /*
#define ADDR9 192			//main header
#define ADDR8 526336
#define ADDR7 592736
#define ADDR6 609792
#define ADDR5 614560
#define ADDR4 616228
#define ADDR3 617108
#define ADDR2 617108
#define ADDR1 617736

   */

// extern unsigned char TFTP_Buffer1[TFTP_BUFFER_SIZE];
 extern unsigned char TFTP_Buffer1[TFTP_BUFFER_SIZE1];
extern "C" void WriteRamToFlash()
{
unsigned long addr_src;
 addr_src = (unsigned long)&TFTP_Buffer1[0];
 unsigned long addr_dest;
 addr_dest = DecFileDataAddress;
 char Dat[2];
 Dat[0] = 0x55;
 Dat[1]	= 0xAA;

  switch(writed_modul)
  {
   case MODUL9: addr_dest += ADDR9;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE9); break;
   case MODUL8: addr_dest += ADDR8;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE8); break;
   case MODUL7: addr_dest += ADDR7;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE7); break;
   case MODUL6: addr_dest += ADDR6;   
      				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE6); break;
   case MODUL5: addr_dest += ADDR5;   
      				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE5); break;
   case MODUL4: addr_dest += ADDR4;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE4); break;
   case MODUL3: addr_dest += ADDR3;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE3); break;
   case MODUL2: addr_dest += ADDR2;   
   				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE2); break;
   case MODUL1: addr_dest += ADDR1;
   			   //	printfp("addrr_dest :");
			   //	printfpd(" %X",addr_dest );
      		   //	printfp("addrr_src :");
			   //	printfpd(" %X",addr_src );
			//	write_dataflash(addr_dest,(unsigned int) &Dat[0],  2); 
				write_dataflash (addr_dest, addr_src,  MAX_SIZE_COMM_FILE1); 
   				
   				break;

  }
  delay_mcs(1000l);
}


extern "C" void FillDecFileData(void)
{
 char * pData;
 int i;
 read_dataflash ((unsigned int)DecFileDataAddressD,(unsigned int)TBUFF1_VALUE, (char *)(&TFTP_Buffer[0]));
 pData =  (char *)(&TFTP_Buffer[0]);
 for(i = 0; i < TBUFF1_VALUE; i++)
 {
  DecFileData.Value[i] = *pData++;
 }
}


extern "C" void ReadFlashToRam(unsigned long addr, unsigned long size)
{
   read_dataflash ((unsigned int)addr,  (unsigned int)size, (char *)(&TFTP_Buffer[0]));
}


extern "C" char CheckDoneShort5(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK5);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK5);
  }
  return ret;
}

extern "C" char CheckDoneShort6(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK6);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK6);
  }
  return ret;
}
extern "C" char CheckDoneShort7(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK7);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK7);
  }
  return ret;
}
extern "C" char CheckDoneShort8(void)
{
  char ret;
 uint_32 status;
 AT91RM9200_PIO_REG_STRUCT_PTR  pio_ptr;
 pio_ptr = (AT91RM9200_PIO_REG_STRUCT_PTR) AT91RM9200_PIOB_BASE;
 status = pio_ptr->PDSR; //t
  if(status & 0x20l)
  {
  	 ret = 1;
	 SetBufferState((uint_32)DONE_OK8);
  }
  else
  {
	 ret = 0;
	 ClearBufferState((uint_32)DONE_OK8);
  }
  return ret;
}




#endif
