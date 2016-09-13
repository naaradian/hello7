//file: Temperature.cpp

#define TEMP_SEND	(0)

 extern "C" unsigned char WriteSpiDmu(unsigned char dev, unsigned long length_of_data, unsigned char * BufferData)
{
//printfp("\n\r WriteSpiDmu :");
//unsigned long do_not_hangt = 0xfffffl;
unsigned long do_not_hangt = 0xfffl; //101221
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr;
//unsigned char readtmp;

//form_addr = BLOCK_SWEEP1 * ((dev>>1)+1);

form_addr = 0;


switch(dev)
{
 case DDS_IF: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_DDSIF; break;
 case DDS_SYMB: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_DDSSYMB; break;
// case 2: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_TEMPERATURE; break;
 case CH_FILTR: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_FILTR; break;

 default : addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = 0; break;
}


if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;

write_xil_char(addr_send, SEND_ALL);   // 0xff
//delay_mcs(1000);
//printf("\n\rwrite  deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

write_xil_char(addr_type , type_channel);
//delay_mcs(1000);

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

lentmp = length_of_data;
BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 write_xil_char(addr_data, * BufferDataTmp++);
// delay_mcs(1000);
}
//__________________________________

write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 return 1;
 }
}
 return 0;

}


//__________________________________________________
//#define PROG_PU_M710

unsigned char * ReadSpiDmu(unsigned dev)
//extern "C" unsigned char WriteSpi710(unsigned char dev, unsigned long length_of_data, unsigned char * BufferData)
{

static unsigned char ReadBuffer[2];//[MAX_SP_LEN];

// unsigned char dev = 0;
//unsigned long do_not_hangt = 0xfffffl;
unsigned long do_not_hangt = 0xfffl; //101221
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr;
//unsigned char readtmp;
form_addr = 0;

switch(dev)
{
// case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_T; break; //CHANNEL_710A; break;
// case 1: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_T; break;// CHANNEL_710B; break;
 //default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
//}

 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_DDSIF; break;
 case 1: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_DDSSYMB; break;
 case 2: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_TEMPERATURE; break;
 case 3: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_FILTR; break;
 default : addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = 0; break;


}



//if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;

write_xil_char(addr_send, SEND_ALL);
//delay_mcs(1000);
//printf("\n\rwrite  deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

write_xil_char(addr_type , type_channel);
//delay_mcs(1000);

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

lentmp = 2;//length_of_data;
//BufferDataTmp =  BufferData;

while(lentmp--)
{
// printf(".%02X", * BufferDataTmp);
 write_xil_char(addr_data, TEMP_SEND);//* BufferDataTmp++);
// delay_mcs(1000);
}
//__________________________________

write_xil_char(addr_status, GO_BIT);
//delay_mcs(1000);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT))
 {
 break;//return 1;
 }
}



 //return 0;
lentmp = 2;
BufferDataTmp =  ReadBuffer;

#ifdef TEST_PRINT_TEMPERATURE
 printfp("\n\r");
#endif


while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
#ifdef TEST_PRINT_TEMPERATURE
 printfpd(" %02X",* BufferDataTmp);
#endif

BufferDataTmp++;
}

//_______________________________________
//write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}



//__________________________________________________
//#else

unsigned char * ReadSpiTempDmu() //(unsigned char deviceindex, unsigned long length_of_data)
{
static unsigned char ReadBuffer[2];//[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffl;
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr;//,form_addrs;
form_addr = 0;

 addr_status = form_addr + ADDR_STATUS1;
  addr_data = form_addr +  SPI_PORT_ADDR;
   addr_type =  form_addr + SPI_ADR;
    addr_send = form_addr + SPI_SEND_ADDR;
   // type_channel = CHANNEL_T;
    // break;


write_xil_char(addr_send, SEND_ALL);
//delay_mcs(1000);
//printf("\n\rread : deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

//write_xil_char(addr_type , CHANNEL_T);	

write_xil_char(addr_type ,  CHANNEL_TEMPERATURE);	

//write_xil_char(addr_type , CHANNEL_710A);	//test
//delay_mcs(1000);

write_xil_char(addr_status, RESET_BIT);
//delay_mcs(1000);

//lentmp = TEMP_LENTH;//length_of_data;


//while(lentmp--)
//{
 write_xil_char(addr_data, TEMP_SEND);
//}
 write_xil_char(addr_data, TEMP_SEND);	//sended two bytes


write_xil_char(addr_status, GO_BIT);

while(do_not_hangt--)
{
 if(!(read_xil_char(addr_status) & GO_BIT)) break;
}

//printf(" %X - %X", do_not_hangt, read_xil_char(addr_status));

lentmp = 2;
BufferDataTmp =  ReadBuffer;
 printfp ("\n\r temp :");
while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
 printfpd(" %02X",* BufferDataTmp);
BufferDataTmp++;
}
 printfp("\n\r");
//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}



//#endif

signed long GetTempDmu()
{
 signed long ret;


// signed char sign = 1;
// ret = 0;
unsigned char * ReadData =	ReadSpiTempDmu();
// unsigned char * ReadData =	ReadSpiDmu(2);

 if((*ReadData) &  MASK_BIT_7)
 {
 //	sign = -1;
 // printfpd("\n\r>%02X", (* ReadData));
	ret =  (* ReadData & (~MASK_BIT_7)) << 8;
	ReadData++;
 // printfpd("\n\r>%02X", (* ReadData));

	ret += * ReadData;
  //	ret >>= 2;
	ret >>= 7;
	ret -= 128;
 }
  else
   {
   	ret =  (* ReadData ) << 8;
//  printfpd("\n\r>%02X", (* ReadData));

	ReadData++;
//  printfpd("\n\r>%02X", (* ReadData));

	ret += * ReadData;
 //	ret >>= 2;
	ret >>= 7;
 }
return ret;
}