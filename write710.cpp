extern "C" unsigned char WriteSpi710(unsigned char dev, unsigned long length_of_data, unsigned char * BufferData)
{

//unsigned long do_not_hangt = 0xfffffl;
unsigned long do_not_hangt = 0xfffl; //101221
// unsigned long do_not_hangt = 0xfl;		//t


unsigned long lentmp;
unsigned char * BufferDataTmp;
unsigned long addr_status, addr_data, type_channel, addr_type, addr_send;
//deviceindex : 0 -15 - prowingents 0,1 - 0 block 2,3 - 1 block; and so waiter, 16 - 23 - syntezers 16 - 0 block
unsigned long form_addr;
//unsigned char readtmp;
#ifndef PROG_PU_M710
form_addr = BLOCK_SWEEP1 * ((dev>>1)+1);
#else
form_addr = 0;
#endif

switch(dev)
{
 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_T; break; //CHANNEL_710A; break;
 case 1: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel = CHANNEL_T; break;// CHANNEL_710B; break;
 default: addr_status =   0; addr_data = 0; addr_type = 0; type_channel = CHANNEL_A;break;
}


if((length_of_data > MAX_SP_LEN) || (!length_of_data)) return 0;

write_xil_char(addr_send, SEND_ALL);
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
