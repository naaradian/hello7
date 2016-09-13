unsigned char * ReadSpiTemp() //(unsigned char deviceindex, unsigned long length_of_data)
{
static unsigned char ReadBuffer[2];//[MAX_SP_LEN];
unsigned long do_not_hangt = 0xfffl;
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr;//,form_addrs;
#ifndef PROG_PU_M710
form_addr = BLOCK_SWEEP1;
#else
form_addr = 0;

#endif

 addr_status = form_addr + ADDR_STATUS1;
  addr_data = form_addr +  SPI_PORT_ADDR;
   addr_type =  form_addr + SPI_ADR;
    addr_send = form_addr + SPI_SEND_ADDR;
   // type_channel = CHANNEL_T;
    // break;


write_xil_char(addr_send, SEND_ALL);
//delay_mcs(1000);
//printf("\n\rread : deviceindex = %d  addr_send : 0x%X,   addr_type : 0x%X ad :0x%X as :0x%X ", deviceindex, addr_send, addr_type, addr_data, addr_status);

write_xil_char(addr_type , CHANNEL_T);
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

while(lentmp--)
{
 * BufferDataTmp = read_xil_char(addr_data);
// printf(" %02X",* BufferDataTmp);
BufferDataTmp++;
}

//_______________________________________
write_xil_char(addr_type , 0);
//_______________________________________
return 	ReadBuffer;
}

