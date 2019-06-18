//file: pwg710.cpp

#define DELAY_710	(9000)



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
 case 0: addr_status = 	form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send =  form_addr + SPI_SEND_ADDR; type_channel = CHANNEL_710A; break;
 case 1: addr_status =  form_addr + ADDR_STATUS1; addr_data = form_addr +  SPI_PORT_ADDR; addr_type = form_addr  + SPI_ADR; addr_send = form_addr  + SPI_SEND_ADDR; type_channel =  CHANNEL_710B; break;
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

extern "C" void LoadReg(unsigned char dev, unsigned char reg, unsigned char val)
{
 unsigned char Buff[2];
 Buff[0] = reg;
 Buff[1] = val;
 WriteSpi710(dev, 2, &Buff[0]);
}

#include "programregs.cpp"
 /*
extern "C" void ProgramRegs(unsigned char dev)
{
//1.
  LoadReg(dev,0,0); //reset set all regs to default walue
  delay_mcs(5l);
  LoadReg(dev,1,0x11);
  LoadReg(dev,2,0x4);
  LoadReg(dev,3,0x8);
//  LoadReg(dev,4,0x);
  LoadReg(dev,5,0x0);
  LoadReg(dev,6,0x2);
  LoadReg(dev,7,0x0);
  LoadReg(dev,8,0x14);
  LoadReg(dev,9,0x1);
  LoadReg(dev,10,0x8);
  LoadReg(dev,11,0x58);
// LoadReg(dev,12,0x);
  LoadReg(dev,13,0x0);
//  LoadReg(dev,14,0x);
  LoadReg(dev,15,0x8);
//  LoadReg(dev,16,0x);
  LoadReg(dev,17,0x0);
  LoadReg(dev,18,0x6);
  LoadReg(dev,19,0x0);
  LoadReg(dev,20,0x12);
  LoadReg(dev,21,0x1);
  LoadReg(dev,22,0x8);
  LoadReg(dev,23,0x5B);
  LoadReg(dev,24,0x0);
  LoadReg(dev,25,0x2);
  LoadReg(dev,26,0xff);
  LoadReg(dev,27,0x0);
  LoadReg(dev,28,0x0);
  LoadReg(dev,29,0x14);
  LoadReg(dev,30,0x20);
  LoadReg(dev,31,0xFF);
  LoadReg(dev,32,0xF0);
  LoadReg(dev,33,0x1);
  LoadReg(dev,34,0x18);
  LoadReg(dev,35,0x0);
  LoadReg(dev,36,0x0);
  LoadReg(dev,37,0x0);
  LoadReg(dev,38,0x78);
}

  */

//need check right comparing - imitate temp
extern "C" void LoadReg5(unsigned char dev, signed char temp)
{
 unsigned char code;
   if(temp < (signed char)(-10))  code = 0x8;
 else if(temp < (signed char)10)  code = 0x19;
 else if(temp < (signed char)30)  code = 0x2a;
 else if(temp < (signed char)55)  code = 0x3b;
 else if(temp < (signed char)75)  code = 0x4c;
 else if(temp < (signed char)95)  code = 0x5d;
 else if(temp < (signed char)115) code = 0x6e;
 else 							  code = 0x7f;
 
 LoadReg(dev,5,code);
}

extern "C" void LoadReg17(unsigned char dev, signed char temp)
{
 unsigned char code;
   if(temp < (signed char)(-10))  code = 0x8;
 else if(temp < (signed char)10)  code = 0x19;
 else if(temp < (signed char)30)  code = 0x2a;
 else if(temp < (signed char)55)  code = 0x3b;
 else if(temp < (signed char)75)  code = 0x4c;
 else if(temp < (signed char)95)  code = 0x5d;
 else if(temp < (signed char)115) code = 0x6e;
 else 							  code = 0x7f;
 
 LoadReg(dev,17,code);
}

extern "C" void SetLoop710(unsigned char dev, unsigned char bbloop, unsigned char ifloop)
{
 LoadReg(dev,37, (bbloop + (ifloop<<1)));
}


#ifndef PROG_PU_M710
#define STATUS710_PORT	(0x14)
#else
#define STATUS710_PORT	(0x1B)
#endif


extern "C" unsigned char GetMidBand(unsigned char dev)
{
#ifdef D_710
  printfp("\n\rGetMidBand\n\r");
#endif
 unsigned long min_band, max_band, mid_band;
 unsigned char Reg4Val = 0;
 unsigned char status;
 unsigned char mask = 1;
 if(dev) mask = 2;
// wd_reset();

 max_band = 0x3f;



 while(Reg4Val <= 0x3f)
 {
 wd_reset();

   LoadReg(dev,4,Reg4Val);
  // delay_mcs(14);
   delay_mcs(DELAY_710);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif
#ifdef D_710
  printfpd(" s: %02X",status);
#endif
   if(status) {min_band = (unsigned long)Reg4Val; break;}
   Reg4Val++;
#ifdef D_710
  printfpd(" %X",Reg4Val);
#endif
 }
 //  printfpd("\n\r1 %X",min_band);

 while(Reg4Val <= 0x3f)
 {
 wd_reset();

   LoadReg(dev,4,Reg4Val);
//   delay_mcs(14);
    delay_mcs(DELAY_710);

//   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif
#ifdef D_710
   printfpd(" s: %02X",status);
#endif
   if(!status) {max_band = (unsigned long)Reg4Val; break;}
   Reg4Val++;
#ifdef D_710
 printfpd(" %X",Reg4Val);
#endif

 }
 //  printfpd("\n\r2 %X",max_band);
  mid_band = (max_band + min_band)>>1;
 //  delay_mcs(10000);
#ifdef D_710
   printfpd("\n\r2 %X",mid_band);
#endif

  return  (unsigned char)mid_band;
}

extern "C" unsigned char GetMidBand1(unsigned char dev)
{
// wd_reset();

 unsigned long min_band, max_band, mid_band;
 unsigned char Reg4Val = 0;
 unsigned char status;
 unsigned char mask = 1;
 if(dev) mask = 2;
  max_band = 0x3f;

 while(Reg4Val <= 0x3f)
 {
 wd_reset();

   LoadReg(dev,4,Reg4Val);
   delay_mcs(14);
//ok   delay_mcs(100000);
  delay_mcs(DELAY_710);

 //  status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif

 //  printfpd(" s: %02X",status);

   if(status) {min_band = (unsigned long)Reg4Val; break;}
   Reg4Val++;
 //  printfpd(" %X",Reg4Val);
 }
 //  printfpd("\n\r1 %X",min_band);

 while(Reg4Val <= 0x3f)
 {
 wd_reset();

   LoadReg(dev,4,Reg4Val);
   delay_mcs(14);
//ok    delay_mcs(100000);
 delay_mcs(DELAY_710);

//   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif


   if(!status) {max_band = (unsigned long)Reg4Val; break;}
   Reg4Val++;
// printfpd(" %X",Reg4Val);

 }
//   printfpd("\n\r2 %X",max_band);
  mid_band = (max_band + min_band)>>1;
   delay_mcs(DELAY_710);

  return  (unsigned char)mid_band;
}

 /* 120110
extern "C" unsigned char GetMidBand_XLO(unsigned char dev, unsigned char reg12start)
{
 //wd_reset();

 unsigned long min_band, max_band, mid_band;
 unsigned char Reg12Val = reg12start;

 unsigned char Reg14Val;// = 8;
 unsigned char Reg16Val = 0;
 unsigned char status;
 unsigned char mask = 1;
 unsigned char statusflag = 0;

 if(dev) mask = 2;

  LoadReg(dev,16,Reg16Val);
  LoadReg(dev,13,0);

  while(Reg12Val < 0x10)
 {
 wd_reset();
   Reg14Val = Reg12Val<<1;
   LoadReg(dev,12,Reg12Val);
//   delay_mcs(10000);
   LoadReg(dev,14,Reg14Val);
   delay_mcs(10000);

   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
  //  printfpd(" s: %02X",status);

   if(!status) { 
   
   //	  printfpd("\n\r3 %02X",Reg12Val);

   break;}
   Reg12Val++;
  // printfpd(" 12:%02X",Reg12Val);

 }

 while(Reg16Val < 0x1f)
 {
 wd_reset();
   LoadReg(dev,16,Reg16Val);
   delay_mcs(10000);
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
  //  printfpd(" s: %02X",status);

   if(status) {min_band = (unsigned long)Reg16Val;
 //   printfpd("\n\r4 %X",min_band);
	 statusflag = 1;

    break;}
   Reg16Val++;
 //    printfpd(" 16:%02X",Reg16Val);

 }
 if(statusflag)
 {
 while(Reg16Val < 0x1f)
 {
 wd_reset();
   LoadReg(dev,16,Reg16Val);
   delay_mcs(10000);
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
 //   printfpd(" s: %02X",status);

   if(!status) {max_band = (unsigned long)Reg16Val; 
 //  printfpd("\n\r5 %X",max_band);

   break;}
   Reg16Val++;
   //  printfpd(" 16:%02X",Reg16Val);

 }
  mid_band = (max_band + min_band)>>1;
  LoadReg(dev,16, mid_band);
  return  1;
  }
  else
  {
   return 0;
  }
}
120110 */

extern "C" unsigned char GetMidBand_XLO(unsigned char dev, unsigned char reg12start)	//120110
{
 //wd_reset();
#ifdef D_710
  printfp("\n\rGetMidBand_XLO\n\r");
#endif


 unsigned long min_band, max_band, mid_band;
 unsigned char Reg12Val = reg12start;

 unsigned char Reg14Val;// = 8;
 unsigned char Reg16Val = 0;
 unsigned char status;
 unsigned char mask = 1;
 unsigned char statusflag = 0;
		max_band = 0x1f;
 if(dev) mask = 2;

  LoadReg(dev,16,Reg16Val);
  LoadReg(dev,13,0);

//_____________________________________120110    
   Reg14Val = Reg12Val<<1;
   LoadReg(dev,12,Reg12Val);
//   delay_mcs(10000);
   LoadReg(dev,14,Reg14Val);
  // delay_mcs(DELAY_710);
//_____________________________________120110


  /*

  while(Reg12Val < 0x10)
 {
 wd_reset();
   Reg14Val = Reg12Val<<1;
   LoadReg(dev,12,Reg12Val);
//   delay_mcs(10000);
   LoadReg(dev,14,Reg14Val);
   delay_mcs(10000);

   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
  //  printfpd(" s: %02X",status);

   if(!status) { 
   
   //	  printfpd("\n\r3 %02X",Reg12Val);

   break;}
   Reg12Val++;
  // printfpd(" 12:%02X",Reg12Val);

 }
   */


 while(Reg16Val < 0x1f)
 {
 wd_reset();
   LoadReg(dev,16,Reg16Val);
   delay_mcs(DELAY_710);
  // status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif

#ifdef D_710
    printfpd(" s: %02X",status);
#endif
   if(status) {min_band = (unsigned long)Reg16Val;
#ifdef D_710
    printfpd("\n\r4 %X",min_band);
#endif
	 statusflag = 1;

    break;}
   Reg16Val++;
#ifdef D_710
    printfpd(" 16:%02X",Reg16Val);
#endif
 }
 if(statusflag)
 {
 while(Reg16Val < 0x1f)
 {
 wd_reset();
   LoadReg(dev,16,Reg16Val);
   delay_mcs(DELAY_710);
//   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#ifndef PROG_PU_M710
   status = (inportb(BLOCK_SWEEP1 + STATUS710_PORT) & mask);
#else
	status = (inportb(STATUS710_PORT) & mask);
#endif
#ifdef D_710
    printfpd(" s: %02X",status);
#endif
   if(!status) {max_band = (unsigned long)Reg16Val; 
#ifdef D_710
  printfpd("\n\r5 %X",max_band);
#endif
   break;}
   Reg16Val++;
#ifdef D_710
   printfpd(" 16:%02X",Reg16Val);
#endif
 }
  mid_band = (max_band + min_band)>>1;
  LoadReg(dev,16, mid_band);
#ifdef D_710
   printfpd("\n\rok: %X",mid_band);
#endif
  return  1;
  }
  else
  {
#ifdef D_710
  printfp("\n\rno\n\r");
#endif
   return 0;
  }
}



extern "C" void Calibrate_VCO(unsigned char dev, signed char temp)
{
// unsigned long mid_band;
 LoadReg(dev,38,0x74);
 LoadReg5(dev, temp);  //load code of temp
// mid_band = GetMidBand(dev);

//final settings
 LoadReg(dev,4, GetMidBand(dev));
 LoadReg(dev,5, 0);
 LoadReg(dev,38, 0x78);
}



extern "C" void Calibrate_XLO(unsigned char dev, signed char temp)
{
// unsigned long mid_band;
 unsigned char Reg12Val = 4;

 LoadReg(dev,38,0x70);
 LoadReg17(dev, temp);  //load code of temp
// mid_band = GetMidBand(dev);

//final settings
 //LoadReg(dev,16, GetMidBand_XLO(dev));
 //printfp("\n\r XLO \n\r");
  while(Reg12Val < 0x10)
 {
  //  printfpd("R12: %02X",Reg12Val);

    if(GetMidBand_XLO(dev,Reg12Val++)) break;

 }


 LoadReg(dev,17, 0);
 LoadReg(dev,38, 0x78);
}

 


extern "C" void Calibrate(unsigned char dev, signed char temp)
{
#ifdef D_710
  printfp("\n\rCalibrate\n\r");
#endif

 Calibrate_VCO(dev, temp);
 Calibrate_XLO(dev, temp);
}

#ifdef PROG_PU_M710
#define ADDR_TX	  (0x19)
#define ADDR_RX	  (0x24)
#endif
 //head 
extern "C" void PVG710_Init(unsigned char dev)
{
  signed char temp = GetTemp();
//1.
  ProgramRegs(dev);
//2.
  temp = GetTemp();
//  printfpd("\n\rt %d", temp);
//3.
  Calibrate(dev, temp);
#ifdef PROG_PU_M710
if(!dev)
{
#endif
#ifdef PROG_MD310
#ifndef PROG_BMDN6

if(!dev)
{
#else //PROG_BMDN6
if(1)
{
#endif
#endif

 LoadReg(dev,24,0x0); //after calibration power up to all tx

#ifdef PROG_PU_M710
}
else
{
 LoadReg(dev,12,0x0);
 LoadReg(dev,13,0xff);
 LoadReg(dev,14,0x0);
 LoadReg(dev,24,0x0);
 LoadReg(dev,24,0xf);
 LoadReg(dev,38,0x74);

}
#endif

#ifdef PROG_MD310
}
else
{
 LoadReg(dev,12,0x0);
 LoadReg(dev,13,0xff);
 LoadReg(dev,14,0x0);
 LoadReg(dev,24,0x0);

 LoadReg(dev,24,0xf);
 LoadReg(dev,38,0x74);
}
#endif

#ifdef PROG_PU_M710
//filters
   LoadReg(dev,ADDR_TX,0x8);
   LoadReg(dev,ADDR_RX,0x2);
#endif
}

