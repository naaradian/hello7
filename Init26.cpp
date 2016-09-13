// Версия для SDI
// 
// 
// 
#include "hello7.h"
#include "embisr.h"
#include "Basic.h"
#include "command.h"
#include "init26.h"
#include "CS24REGS.H"

#define Mem_Cfg             0x3000
#define FBufLuma0_index     0x0
#define FBufLuma1_index     0x2

#define RBuff_index          0x8
#define  OSD_index     0x9 //b'1001'
#define User_Data_index   0xa
#define  ATs_index     0xb //b'1011'

#define VBI0_index     0xd //b'1101'
#define VBI1_index     0xe //b'1110'

#define IRL            0x500
#define IRH            0x501
#define RESb           0x502
//090820 #define Tx34           0x503
#define Slot           0x504
#define Spi            0x505
#define IntReg         0x507
#define Mode1          0x506

#define HDhi          0x509
#define HDhilo        0x50a
#define HDlolo        0x508

union DW
{
//  unsigned  int i[2];
  unsigned short int i[2];
  unsigned long l;
};

//#define noDEBUG
#define DECODER
#define AUDIO1
/*
const PT_NULL    = 0;
const PT_ERR1    = 1;
const PT_ERR2    = 2;
const PT_ERR_PSP = 3;
const PT_CTRL    = 4;
const PT_RING    = 5;
const PT_SOUND   = 6;
const PT_ADDR    = 7;
const PT_POINT   = 8;
*/
#define  PT_NULL     (0)
#define  PT_ERR1     (1)
#define  PT_ERR2     (2)
#define  PT_ERR_PSP  (3)
#define  PT_CTRL     (4)
#define  PT_RING     (5)
#define  PT_SOUND    (6)
#define  PT_ADDR     (7)
#define  PT_POINT    (8)


//port #include "audiodec.cpp"
//#define ReedS 0x0
#define ReedS 0x38
// Need init!!!!!!!!!!!!!!!!!!!!!!!!!!!!
extern char dpd_state;

int debug=0;

int alarm=0;
int pwm_print=0;

int cnt=0;
int cnt1=0;
int cnt2=0;
unsigned buff3=0;

int flag_t=0;


unsigned buff2=0;
unsigned int rbuff_size=0;
int prf=1;

EmbCS24Int EmbCS24;
EmbRepairInt EmbRepair;


#define TS_synck    (1)// Наличие синхронизации к транспортному потоку
#define AV_synck    (2)// Наличие синхронизации видео к звуковому сопровождению
#define E14norma    (4)// Наличие синхронизации к потокам Е1 и выравнивания
#define RS_synck    (8)// Наличие синхронизации деинтерливера и декодера Рида-Соломона

#define Play       (16)//Декодер в режиме декодирования
#define Skipped    (32)//Пропуск кадра
#define Freez      (64)//Декодер в режиме стоп-кадра
#define Overflow   (128)//Ошибка преполнения видео буфера

#define PWM_error  (0x0100)//Ошибка синхронизации видео
#define PCR_error  (0x0200)//Ошибка переполнения счетчика синхро-кода или смена последовательности синхро-кода
#define VRB_error  (0x0400)//Ошибка заполнения буфера
#define NMI_error  (0x0800)//Ошибка прерывания

#define Hold_error (0x1000)//Останов кодера
#define VRBc_error (0x2000)//Обьем буфера не изменяется
#define Load_error (0x4000)//Ошибка инициализации декодера MPEG2
#define TS_error   (0x8000)//Ошибка демультиплексора

//unsigned Ret_code=0;

typedef union {
  unsigned char c[4];
  unsigned long dw;
}dwword;

typedef union {
//  unsigned int i[2];
  unsigned short int i[2];
  unsigned long dw;
}pcr_word;

typedef union {
  unsigned char c[2];
 // unsigned int w;
  unsigned short int w;
}sword;


 void SetPrint(unsigned short int m,int r)
{
  unsigned char  *p;
  unsigned short int  *pt;
  unsigned char  *ts;
  unsigned short int print_ptr=0;

 // Disable();
	pt = (unsigned short int *)0x10000030;//0x80001FF8;

  print_ptr=*pt;

  ts = (unsigned char *)0x10007ff8;//0x80001FF8;
  p  = (unsigned char *)0x10000100;//0x80001FF8;
  
	if(print_ptr > 0x7e00) print_ptr = 0;

  switch(r){
    case 0:    *(p+print_ptr)=0xff; break;
    case 1:    *(p+print_ptr)=0xee; break;
    case 2:    *(p+print_ptr)=0xdd; break;
    case 3:    *(p+print_ptr)=0xcc; break;
    case 4:    *(p+print_ptr)=0xbb; break;
    case 5:    *(p+print_ptr)=0xaa; break;
    case 6:    *(p+print_ptr)=0xfa; break;
    default:   *(p+print_ptr)=0xfe;
  }
  print_ptr++;
  *(p+print_ptr)=(unsigned char)((m>>8) & 0x00ff);
  print_ptr++;
  *(p+print_ptr)=(unsigned char)(m & 0x00ff);
  print_ptr++;

  *ts=0x40;
  ts = (unsigned char *)0x10007ffe;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts-=2;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
	*(p+print_ptr)=*ts; ts--;  print_ptr++;
  *ts=0x0;
  
	*pt=print_ptr;
//  Enable();
}


unsigned char GetMode()
{
  unsigned char  *p;
 // p = (unsigned char *)0x10000000;//0x80001FF8;
  p = (unsigned char *)0x10000014;//0x80001FF8;
  return *p;
}

void SetMode(unsigned char m)
{
/*
  unsigned char  *p;
  p = (unsigned char *)0x10000000;//0x80001FF8;
  *p=m;
 */
  SetRate(m); //for snmp
}

unsigned char GetVideoStandart()
{
  unsigned char  *p;
  p = (unsigned char *)0x10000001;//0x80001FF8;
  return *p;
}

void SetVideoStandart(unsigned char m)
{
/*
  unsigned char  *p;
  p = (unsigned char *)0x10000001;//0x80001FF8;
  *p=m;
  */
  SetVideo(m); //for snmp

}

unsigned char GetTestSignal()
{
  unsigned char  *p;
  p = (unsigned char *)0x10000002;//0x80001FF8;
  return *p;
}

void SetTestSignal(unsigned char m)
{
/*
  unsigned char  *p;
  p = (unsigned char *)0x10000002;//0x80001FF8;
  *p=m;
  */
  SetTestSignal1(m);
}

unsigned char GetSound()
{
  unsigned char  *p;
  p = (unsigned char *)0x10000003;//0x80001FF8;
  return *p;
}

void SetSound(unsigned char m)
{
/*
  unsigned char  *p;
  p = (unsigned char *)0x10000003;//0x80001FF8;
  *p=m;
  */
  SetSound1(m);
}

//unsigned int GetStat()
unsigned char GetStat()
{
  unsigned char  *p;
  p = (unsigned char *)0x10000004;//0x80001FF8;
  return *p;
}						  

void SetStat(unsigned int m)
{
/*
//  unsigned short int  *p;
  unsigned char  *p;
//  p = (unsigned short int *)0x10000004;//0x80001FF8;
  p = (unsigned char *)0x10000004;//0x80001FF8;
  *p=m;
  */
  SetState1(m);
}

unsigned int GetErr()
{
  unsigned char *p;
//  p = (unsigned char *)0x10000005;//0x80001FF8;
  p = (unsigned char *)0x1000000C;//to use MDataC
  return *p;
}
/*
void SetErr(unsigned int m)
{
  SetErr1(m);
}
   */
 //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<? address +1 but types short int - 2 bytes!
//enum video_standard { PAL=0, SECAM=1, YC=2};
//enum test_signal {OFF=0, BARS=1, L1=2, L2=3, L3=4, L4=5};

// Инициализация платы кодера ПАЛ/СЕКАМ

void wd_res()
{
 // outport(0xffe6,0xaaaa);
//  outport(0xffe6,0x5555);
//  outportb(0x6fb,0);
  wd_reset();
}

void SetE14()
{
 // int i,j;
  unsigned int rate=GetMode();
  unsigned int s=GetSound();
  set_audio(rate,s);
  if(get_audio(rate,s)){
	  delay_mcs(50l);
	  set_audio(rate,s);
	  delay_mcs(5l);
	  if(get_audio(rate,s))	printff("\n\r Error set audio");
  }
//  for(i=0;i<50;i++){ for(j=0;j<2000;j++); wd_res();}
  delay_mcs(50l);
  switch(rate)
  {
    case 1: outportb(0x03,0 | ReedS); 
            if(s) outportb(0x04,12); else outportb(0x04,8);//Slot_4E1); 
            break;
    case 0: outportb(0x03,7 | ReedS); 
            if(s) outportb(0x04,14); else outportb(0x04,9);//outportb(0x504,Slot_3E1);
            break;
   }
}


unsigned int read16(unsigned char Host_Addr)
{
//my_int_disable_irq0();
 // asm { cli }
  _int_disable();
  sword Host_Data;
  outportb(IRL,Host_Addr);
  Host_Data.c[0]=inportb(HDlolo);
  Host_Data.c[1]=inportb(HDhi);
 // asm { sti }
//my_int_enable_irq0();
 _int_enable();
  return Host_Data.w;
}

void write16(unsigned char Host_Addr,unsigned short int Host_Data)
{
 // asm { cli }
// my_int_disable_irq0();
 _int_disable();
  sword hd;
  hd.w=Host_Data;
  outportb(IRL,Host_Addr);
  outportb(HDhi,hd.c[1]);
  outportb(HDlolo,hd.c[0]);
 _int_enable();	  //ok


//my_int_enable_irq0();

//  asm { sti }
}

unsigned long read32(unsigned char Host_Addr)
{
  dwword l;
//  asm { cli }
//my_int_disable_irq0();
 _int_disable();

  outportb(IRL,Host_Addr);
  l.c[0]=inportb(HDlolo);
  l.c[1]=inportb(HDhi);
 //t   delay_mcs(100);
  delay_mcs(1);

  l.c[2]=inportb(HDhilo);
  l.c[3]=inportb(HDhi);
 //t   delay_mcs(100);
  delay_mcs(1);

  //asm { sti }
//my_int_enable_irq0();
 _int_enable();

  return l.dw;
}

void  write32(unsigned char Host_Addr,unsigned long Host_Data)
{
  dwword l;
 // asm { cli }
 _int_disable();
//my_int_disable_irq0();
  l.dw=Host_Data;
  outportb(IRL,Host_Addr);
  outportb(HDhi,l.c[3]);
  outportb(HDhilo,l.c[2]);
  delay_mcs(1);	//t 
  outportb(HDhi,l.c[1]);
  outportb(HDlolo,l.c[0]);
  delay_mcs(1);   //t
 // read32(Host_Addr);
 // asm { sti }
  _int_enable();

 //my_int_enable_irq0();
}


void EmbRepairInt::Init_IRQ()
{
/*
  unsigned int c;
  EmbIsr::InitIRQ(0x0d);
  outport(i1con,0x0010);        // 0-регистр управления (разрешения) прерываниями
  c=inport(imask);              // Маска перываний - чтение (?)
  outport(imask,c&0xffdf);      // Ввод маски прерываний (?)
  */
};

void EmbRepairInt::Init()
{
  outportb(IntReg,0x01);
  inportb(IntReg);
}

void EmbRepairInt::IsrXX()
{
  unsigned int c;
  c=inportb(IntReg);
  if(c & 0x01){    // E14 Норма
    if(inportb(Tx34)&0x40){     
      Ret_code |= E14norma;
    }else{   
      Ret_code &= ~(unsigned)E14norma;
    }
  }
  if(c & 0x02){  
    if(inportb(Tx34)&0x10){     Ret_code |= RS_synck;
    }else{   Ret_code &= ~RS_synck;}
  }
  outportb(IntReg,0x01);
 //port outport(0xff22,0x000d);            
}



void EmbCS24Int::Init_IRQ()
{
/*
  unsigned int c;
  EmbIsr::InitIRQ(0x0c);
  outport(i0con,0x0011);        // 0-регистр управления (разрешения) прерываниями
  c=inport(imask);              // Маска перываний - чтение (?)
  outport(imask,c&0xffef);      // Ввод маски прерываний (?)
  */
}

void EmbCS24Int::Init()
{
  count=0;
  N=0;
  M=0;
  offset=0; signal=0; dt=0; dt1=0;
  flag=0; fdt=0; e=0x520;


	delta2=0;
  //	delta=0
  mask_val=0x0023;
  VRB=0;
  VRBpr=0;
  VRBct=0;
  dPCR=0;
  dPCRpr=0;
  dPCRct=0;
//  PCR_high=0;
  PCR=0;
	int i;
	fn=0;
	flag2=0;
	for(i=0;i<16;i++) bf[i]=0;
// printff("\n\r 2411");

  write16(mask,0x0c04);
  write16(mask1,0x0823);
//  write16(mask, 0x0000);
//  write16(mask1,0x0001);

//  write32(aud1_isr,0xffffffff);
//  write32(aud1_imr,0x00000800);
//  write16(aud1_imr,0x0800);
  write32(location,fend_stat_imask);     write32(data_transfer,0x00004633);//write32(data_transfer,0x00006303);
//  write32(location,fend_stat_imask);     write32(data_transfer,0x00004000);//write32(data_transfer,0x00006303);
  write32(location,queue_imask);         write32(data_transfer,0x00000000);
  write32(location,audio1_status_imask); write32(data_transfer,0x00000000);
  write32(location,audio2_status_imask); write32(data_transfer,0x00000000);
  write32(location,video_status_imask);  write32(data_transfer,0x00000000);
//  write32(location,general_mask);        write32(data_transfer,0x80000000);
  write32(location,general_mask);        write32(data_transfer,0x82000000);
  write32(location,interrupt_mask2);     write32(data_transfer,0x00000000);
  write32(location,pcr_stc_threshold);   write32(data_transfer,0x00000000);
  write32(location,pwm);                 write32(data_transfer,1140);//0x800);
  write32(location,fend_stat);           read32(data_transfer);
  write32(location,fend_stat);           write32(data_transfer,0xffffffff);

  read16(host_int);
  read16(host_int1);
  read32(interrupt_reg);
  write32(interrupt_reg,0xffffffff);
  read32(interrupt_reg);
  read16(aud1_isr);

}

union word{
  unsigned char c[2];
 //port unsigned int i;
 unsigned short int i;
};

  
void EmbCS24Int::IsrXX()
{
  unsigned int g,j,k,l;
//  long d;
  int i;
//  pcr_word r;
//  char str[40];
//  unsigned int vstc[3];
//  char* s;
	unsigned long z;
	DW w;
	EmbDWord r;
	word v;
//			outportb(RESb,0x0f);

  HostInt=read16(host_int);
  HostInt1=read16(host_int1);
  TransInt=read32(interrupt_reg);
  write32(interrupt_reg,0xffffffff);
  write32(location,fend_stat);    Front_end_stat=read32(data_transfer);
  write32(location,fend_stat);     write32(data_transfer,0xffffffff);


  if(HostInt&0x0400){ // Picture start
    buff2=read16(fifo);
	bf[fn]=(read16(fifo)>>4)& 0x0fff;
	if(fn==15){	fn=0; N=0; } else fn++;
	buff3=0;
	for(i=0;i<16;i++) buff3+=bf[i];
  }
  if(HostInt&0x0004){ //
    Ret_code|= Overflow;
  }
  if(HostInt&0x0800){ // Picture Skipped Interrupt
    if(N>1){  Ret_code|= Skipped;  }
    if(flag2 > 30) N++;
  }
  if(HostInt1 & 0x4000){ // Freeze Frame Status
//    Ret_code |= Freez;
  }
  if(HostInt1 & 0x0800){ // PTS read
	  PTS2=read16(sync_pts2);
	  PTS1=read16(sync_pts1) & 0xfffe;
	  PTS0=read16(sync_pts0) & 0xfffe;
	  STC2=read16(sync_stc2);
	  STC1=read16(sync_stc1) & 0xfffe;
	  STC0=read16(sync_stc0) & 0xfffe ;//| ((STC1<<13)&0xe000);
//      write32(location,stc_low);       STCh=read32(data_transfer);
//      write32(location,stc_high);      STCh=read32(data_transfer);
//      write32(location,stc_low);       read32(data_transfer);
	  g=(STC0>>2) & 0x00003fff;
      if(STC1 & 0x0002) g|=0x4000;
	  if(STC1 & 0x0004) g|=0x8000;
	  w.i[0]= g;
      w.i[1]= (STC1>>3) & 0x00001fff;
      if(STC2 & 0x0002) w.i[1]|=0x2000;
	  if(STC2 & 0x0004) w.i[1]|=0x4000;
	  if(STC2 & 0x0008) w.i[1]|=0x8000;
//090709			z=w.l;
	  z = ((unsigned long)w.i[1] << 16) + (unsigned long)w.i[0];
	  
	  STCh=z;

	  g=(PTS0>>2) & 0x00003fff;
      if(PTS1 & 0x0002) g|=0x4000;
	  if(PTS1 & 0x0004) g|=0x8000;
	  w.i[0]= g;
      w.i[1]= (PTS1>>3) & 0x00001fff;
      if(PTS2 & 0x0002) w.i[1]|=0x2000;
	  if(PTS2 & 0x0004) w.i[1]|=0x4000;
	  if(PTS2 & 0x0008) w.i[1]|=0x8000;
//090709			z=w.l;
	  z = ((unsigned long)w.i[1] << 16) + (unsigned long)w.i[0];
//	   deltaPTS=z-STCh;//PTS1;
	  deltaPTS =	read16(pts_delta);
  }

  if(HostInt1&0x0002){ // Audio1 Interrupt
  }
  if(HostInt1&0x0001){ // Transport Interrupt Summary
    if(TransInt&0x02000000){ // PCR Interrupt
        PCR=PCR_high;
        if((Ret_code & Play) && (flag==3)){
	      write32(location,pcr_stc_delta); delta=read32(data_transfer);
	      write32(location,pcr_high);      PCR_high=read32(data_transfer);
	      write32(location,pcr_low);       PCR_low=read32(data_transfer);
	      if(PCR > PCR_high){
	        Ret_code|= TS_error;
	      }
	      r.l=delta &  0x0003ffff;
//			d=r.l>>4;
	      if(delta & 0x00080000) {
	        Ret_code|= PCR_error;
	      }
//        v.c[1]=r.c[2]; 
	      v.c[0]=(r.c[1]<<4 & 0xf0)|(r.c[0]>>4 & 0x0f); 
	      v.c[1]=(r.c[2]<<4 & 0xf0)|(r.c[1]>>4 & 0x0f); 
		  d=v.i;
	      tr=(v.i>>4)&0x03ff;//v.i&0x03ff;//
		  t= (v.i>>11)&0x0007;

	//    tr=(int)(d & 0x00003fff);
	//	  t= (v.i>>3)&0x007f;

	      if(delta & 0x00040000){  e+=t; } else { tr=-tr; e-=t; }
	      signal=e+tr;
		  if(signal<0)     PWM=-signal|0x800; else PWM=signal;

	      if(signal>0x7ff){ 
	        PWM=0x7ff;
	        Ret_code|= PWM_error;
	      }
	      if(signal<-2047){ 
	        PWM=0x800;
	        Ret_code|= PWM_error;
	      }
	      write32(location,pwm);
		  write32(data_transfer,PWM);
	      pwm_print=0;
	    }
	    if(flag==2){
			write32(location,pcr_high);      STC_high=read32(data_transfer);
	        write32(location,pcr_low);       STC_low=read32(data_transfer);
			STC_high -= 0x00002100;

			k=(unsigned) (STC_high<<1) &0x0000fffe;
			k=(k<<1) & 0x0000fffe;
			if(STC_low & 0x00000200) k|=2;
			j=(unsigned) (STC_high>>16) &0x0000ffff;
			j=(j<<1) & 0x0000fffe;
			j=(j<<1) & 0x0000fffe;
			j=(j<<1) & 0x0000fffe;
			l=0;
			if(STC_high & 0x00004000) j|=2;
			if(STC_high & 0x00008000) j|=4;
			if(STC_high & 0x20000000) l=2;
			if(STC_high & 0x40000000) l|=4;
			if(STC_high & 0x80000000) l|=8;

			write16(sync_stc2,l);
	        write16(sync_stc1,j);
	        write16(sync_stc0,k);
	        Ret_code |= AV_synck;
	        Ret_code |= TS_synck;
	        Ret_code |= Play;
			outportb(RESb,0x0f);
	        flag=3;
			  write16(mask,0x0c04);
			  write16(mask1,0x0823);
			  write32(location,fend_stat_imask);     write32(data_transfer,0x00006303);
			  write32(location,general_mask);        write32(data_transfer,0x82000000);
		}else{
		  if(flag < 3 ) flag++;
		}
        

    }
    if(TransInt&0x80000000){ // PCR Interrupt
      if(Front_end_stat&0x00004000){ // First PSR
//		write16(mask,0x0c04);
//		write16(mask1,0x0823);
  		write32(location,general_mask);        write32(data_transfer,0x82000000);

/*
	      if((!flag)){
					write32(location,pcr_high);      STC_high=read32(data_transfer);
	        		write32(location,pcr_low);       STC_low=read32(data_transfer);
					STC_high -= 0x00002100;

					k=(unsigned) (STC_high<<1) &0x0000fffe;
					k=(k<<1) & 0x0000fffe;
					if(STC_low & 0x00000200) k|=2;

					j=(unsigned) (STC_high>>16) &0x0000ffff;
					j=(j<<1) & 0x0000fffe;
					j=(j<<1) & 0x0000fffe;
					j=(j<<1) & 0x0000fffe;
					l=0;
					if(STC_high & 0x00004000) j|=2;
					if(STC_high & 0x00008000) j|=4;
					if(STC_high & 0x20000000) l=2;
					if(STC_high & 0x40000000) l|=4;
					if(STC_high & 0x80000000) l|=8;

					write16(sync_stc2,l);
	        		write16(sync_stc1,j);
	        		write16(sync_stc0,k);
	        
				  STCv2=read16(sync_stc2);
				  STCv1=read16(sync_stc1) & 0xfffe;
				  STCv0=read16(sync_stc0) & 0xfffe ;//| ((STC1<<13)&0xe000);


//					mask_val=0x0021;
	        Ret_code |= AV_synck;
	        Ret_code |= TS_synck;
	        Ret_code |= Play;
	        flag=1;
	      }
*/
      }
      if(Front_end_stat&0x00000640){ // Overflow Interrupt
        Ret_code|= Overflow;
      }
      if(Front_end_stat&0x00000001){ // Sync lock Interrupt
        Ret_code |= TS_synck;
      }
      if(Front_end_stat&0x00000002){ // Sync lost Interrupt
        Ret_code &= 0xfffe;//TS_synck;
      }
    }
  }
/*
  write16(mask,0x0c04);
  write16(mask1,0x0823);
  write32(location,fend_stat_imask);     write32(data_transfer,0x00006303);
  write32(location,general_mask);        write32(data_transfer,0x82000000);
*/
}

extern "C" int read_dataflash (unsigned long , unsigned long , char *);
extern  uchar TFTP_Buffer[TFTP_BUFFER_SIZE];

void Load_Video_Code()
{
  unsigned char* ptr;
  unsigned char lo,hi;
  register int i;

  write16(wr_protect,0x0001);// Enable instruction store load
  write16(proc_iaddr,0x0000);// Set instruction store address for each 16-bit word in buffer
//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(VIDEO_ADDRESS + HEADER_SIZE), (unsigned int)VIDEO_SIZE, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________




//port   ptr=(unsigned char*)VideoMicrocodePtr;
  ptr=(unsigned char*)(&TFTP_Buffer[0]);

//? >>>>>>>>>>>>>>>>>>>>>>what need ?
/*port
  asm{  cli
        push   ds
        mov  ax,CS24_VLOAD_SEG
        mov  ds,ax
  }
   */
  outportb(IRL,proc_idata);
  for(i=0;i<3072;i++){

//________________________________________________________
//  if(i < 9) printf("\n\r i = %d  data0 : 0x%X", i, *ptr);
//  if(i > 3068) printf("\n\r i = %d  data : 0x%X", i, *ptr);
//__________________________________________________________

    hi=*ptr++;
//________________________________________________________
// if(i < 9) printf("\n\r i = %d  data1 : 0x%X", i, *ptr);
// if(i > 3068) printf("\n\r i = %d  data : 0x%X", i, *ptr);
//__________________________________________________________


    lo=*ptr++;
    outportb(HDhi,hi);
    outportb(HDlolo,lo);
  }
/* 
port
  asm{ pop  ds
       sti  }
*/
  write16(proc_iaddr,0x0000);// Set starting instruction store address back to '0'
  write16(wr_protect,0x0000);// Disable instruction store load
//  write16(chip_control,0x0002);// Start video processor
}

int Chek_Video_Code()
{
  unsigned char* ptr;
  unsigned char lo,hi;
  //port register sword i;
  sword i;

  write16(wr_protect,0x0001);// Enable instruction store load
  write16(proc_iaddr,0x0000);// Set instruction store address for each 16-bit word in buffer

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(VIDEO_ADDRESS + HEADER_SIZE), (unsigned int)VIDEO_SIZE, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________
  ptr=(unsigned char*)(&TFTP_Buffer[0]);

//port  ptr=(unsigned char*)VideoMicrocodePtr;
   /* port ? what need
  asm{  cli
        push   ds
        mov  ax,CS24_VLOAD_SEG
        mov  ds,ax
  }
  */
  for(i.w=0;i.w<3072;i.w++){
    outportb(IRL,proc_iaddr);
    outportb(HDhi,i.c[1]);
    outportb(HDlolo,i.c[0]);
    hi=*ptr++;
    lo=*ptr++;
    outportb(IRL,proc_idata);
    if(inportb(HDlolo)!=lo)break;
    if(inportb(HDhi)!=hi)break;
  }
  /* port what need ?
  asm{ pop  ds
       sti  }
	   */
  write16(proc_iaddr,0x0000);// Set starting instruction store address back to '0'
  write16(wr_protect,0x0000);// Disable instruction store load

  if(i.w<3072){
    return 1;
  }
  return 0;
}

void Load_Audio1_Code()
{
  unsigned char* ptr;
  unsigned char lo,hi;
  register int i;

//___________________________________________________________________________
 // read_dataflash ((unsigned int)XilDataAddressD, (unsigned int)XilSizeToDownloadD, (char *)(&TFTP_Buffer[0]));
  read_dataflash ((unsigned int)(AUDIO_ADDRESS + HEADER_SIZE), (unsigned int)AUDIO_SIZE, (char *)(&TFTP_Buffer[0]));
//___________________________________________________________________________

//port   ptr=(unsigned char*)AudioMicrocodePtr;
  ptr=(unsigned char*)(&TFTP_Buffer[0]);
 
//  read32p(aud1_ctrl0);
  write32(aud1_ctrl0,0x00000008);// reset the audio instruction store address to 0
//  read32p(aud1_ctrl0);
 /* port what need
  asm{  cli
  push   ds
  mov  ax,CS24_ALOAD_SEG
  mov  ds,ax
  }
  */
  outportb(IRL,aud1_mdr);
//  for(i=0;i<14336;i++){
  for(i=0;i<7168;i++){
    hi=*ptr++;
    lo=*ptr++;
    outportb(HDhi,hi);
    outportb(HDhilo,lo);
    hi=*ptr++;
    lo=*ptr++;
//    outportb(HDhi,0);
//    outportb(HDhilo,0);
    outportb(HDhi,hi);
    outportb(HDlolo,lo);
  }
  /* port
  asm{  pop  ds
        sti  }
		*/
  write32(aud1_ctrl0,0x00000000);// Disable instruction store load
//  read32p(aud1_ctrl0);
}


void TestWrite()
{
	for (long i = 0; i < 1000000; i++)
	{
	  write16(chip_control,0x0000);	   
	  wd_reset();
	}

}



void Init_CS24()
{
  int i,j;
 // unsigned t;
  unsigned char ch;
 // unsigned mask_val,rate_size;
 // unsigned rate_size;
  int rate=1;
//	int ks=0,rs=0;
 // unsigned r;
//  int synck_set=1,asynck_set=1;
//	unsigned int StatChek=3;
  int error_type=0;
//*********************************************************
// Reset
//*********************************************************
//	wd_res();
  embIndicator.SetLtDiod(1,1);
  embIndicator.SetLtDiod(0,2);
  embIndicator.SetLtDiod(0,3);


//  outportb(RESb,0x04);
  outportb(RESb,0x0a);
  printff("\n\r Start!");
	i=0; 
	for(ch=0x01;ch;ch<<=1){
		outportb(IRL,ch);
		if(inportb(IRL)!=ch){ error_type|=i; printff("Xilinx err=%i,i");}
		i++;
	}
	if(error_type){
  //? need		asm{ db 0fah, 0eah, 00h, 0ah, 00h, 27h};
	}
//		
//  printff("\n\r Xilinx test ok!");
  SetE14();
//  spi_init();
  ch=GetTestSignal();
 //  spi_tst(ch);
  ch=GetVideoStandart();
//  spi_std(ch);

  delay_mcs(10l);
  outportb(RESb,0x09);
  outportb(RESb,0x0b);
  delay_mcs(10l);  
  outportb(RESb,0x09);
//  outportb(RESb,0x0b);

/*
//  for(i=0;i<20;i++){ for(j=0;j<2000;j++); wd_res();}
  outportb(IRL,chip_control);
  outportb(HDhi,0);
  outportb(HDlolo,4);
  */
  write16(chip_control,0x4);
  i=read16(chip_control);
//  printff("\n\r Wait 0x8004 = %X",i);

//  write16(chip_control,0x0004);
//	for(i=0;i<1000;i++){ wd_res();}
//  for(i=0;i<5;i++){ for(j=0;j<2000;j++); wd_res();}

  write16(chip_control,0x0000);
   //	i=0;
  i=read16(mask);
//  printff("\n\r CNT =%X",i);
//	for(i=0;i<1000;i++){ wd_res();}
//	for(i=0;i<5;i++){ for(j=0;j<2000;j++); wd_res();}
//  write16(chip_mode,0x0480);
// debug	Test CS24 int regs
	i=0;
	write16(mask,0xAAAA);
	i=read16(mask);
	if(i!=0xAAAA)printff("\n\r Wait 0xAAAA = %X",i);

	write16(mask,0x5555);
	i=read16(mask);
	if(i!=0x5555)printff("\n\r Wait 0x5555 = %X",i);

    write16(mask,0x1234);
	i=read16(mask);
	if(i!=0x1234)printff("\n\r Wait 0x1234 = %X",i);

	/*
	for(t=0x0001;t;t<<=1){
		write16(mask,t);
		i=read16(mask);
	  if(i!=t) printff("\n\r CSreg err=%X",i);// Ret_code|= Load_error;
		//i++;
	}
	*/
  printff("\n\r CS test ok!");

// return; //for test
  
//	if(error_type) Ret_code|= Load_error;// error(2,error_type);

//*********************************************************
// Memory setup
// 8 MB of memory, Video PAL, Audio1, and Transport
//*********************************************************		   
  write16(base_addr_indx,Mem_Cfg | RBuff_index);    //1. Rate buffer Base Address Index
  write16(base_addr,0x0000);   	                      //Rate buffer Memory Base Address starting at memory location 0.
  write16(rb_size,0x9000);		                      //2. Buffer size=1179648 bytes decimal
  write16(base_addr_indx,Mem_Cfg | FBufLuma0_index);//3. Frame Buffer Luminance 0 Index
  write16(base_addr,0x2400);                        //4. Frame Buffer Luminance 0
  write16(base_addr_indx,Mem_Cfg | User_Data_index);//5. User Data Base Address Index
  write16(base_addr,0x7428);
  write16(base_addr_indx,Mem_Cfg | VBI0_index);     //7. VBI 0 Base Index
  write16(base_addr,0x742C);
  write16(base_addr_indx,Mem_Cfg | VBI1_index);     //9. VBI 1 Base Index
  write16(base_addr,0x7594);
  write16(base_addr_indx,Mem_Cfg | OSD_index);      //11. OSD Base Address Index
  write16(base_addr,0x76FC);
  write16(base_addr_indx,Mem_Cfg | ATs_index);      //13. Audio/Transport Base Address Index
  write16(base_addr,0xA000);  
                      //14. Audio/Transport Base Address starting at 5242880 bytes decimal.
  write32(aud1_seg3_r,0xF0000000);
  write32(aud1_seg2_r,0x00000200);
  write32(aud1_seg1_r,0x00000210);
  write32(aud1_offsets,0x0007000E); //Audio 1 Offsets
//*********************************************************
// Set chip mode, interface control
//*********************************************************
//  write16(chip_mode,0x00a2);
  write16(chip_mode,0x0480);
//- Byte-Swap mode (bit 1) -> if using x86 host processor
  write16(infc_ctl,0x0000); // !!!!
//- External Data Mode (bit 4)-> '1' = compressed data fed from the host
//*********************************************************
// Set display mode
//*********************************************************
//  write(disp_mode, (Addr 20) = x'2000' ERROR!!!
  write16(disp_mode,0x8500);
// Set Sync mode (bits 15-13) : '100'b, which sets up: CCIR 656
// Set PAL/NTSC mode (bit 10) bit  : 1  (PAL)
// Set Enable 8-bit Display Output Mode (bit 8) : 1
// Set Diseble YCbCr Clipping (bits 7,6) : '00'b
// Set Singl Field Mode (bits 5,4) : '00'b (display normally)
// Set Display Fofmat (bits 3-1) : '000'b
// Set 16-9 Monitor (bit 0) : 0
  write16(disp_dly,0x0017);
  write16(disp_tbor,0x0000);
  write16(osd_mode,0x0000);
//*********************************************************
// Transport demultiplexer setup
//*********************************************************
  write32(location,configuration1);
  write32(data_transfer,0x00020037);//0x00020012);//!!!!!
  write32(location,configuration2);
  write32(data_transfer,0x00000033);//7f);

  write32(location,packet_buffer_level);
  write32(data_transfer,0x84840000);

//Set video PID
  write32(location,0x011f);
  write32(data_transfer,0x0000012c);
  write32(location,0x223f);
  write32(data_transfer,0x00000000);
//Set audio PID
  write32(location,0x011e);
//  write32(data_transfer,0x0000012f);
  write32(data_transfer,0x0000012d);
  write32(location,0x223d);
  write32(data_transfer,0x00000000);

//Set PCR PID
  write32(location,0x01ff);
  write32(data_transfer,0x00000065); 
  write32(location,pcr_stc_threshold);
  write32(data_transfer,0x00000000);
//  write32(location,control1);
//  write32(data_transfer,0x00000008);

//*********************************************************
//Load video instruction storage
//*********************************************************
//  printff("\n\r...Start Load Video");

  Load_Video_Code();
  i = Chek_Video_Code();
  if(i)	{ printff("\n\r...Check_Video_Code : Error!"); }
  else{ printff("\n\r...Check_Video_Code : Ok!");}

  write16(chip_control,0x004a);// Start video processor
//	printff("\n\r...Start Load Audio");
  Load_Audio1_Code();

  write16(chip_control,0x004a);// Start video processor

//********* Set Audio master !!!	********************

// Start audio and video decoders
//	Disable();
  write32(aud1_ctrl0,0x00000246);
  write32(aud1_ctrl1,0x00000003);
  write32(aud1_ctrl2,0x000002c1);
//  write16(chip_control,0x004b);
//  write32(aud1_ctrl0,0x00000746);
  write16(aud1_imr,0x0800);
  write16(aud1_dsr,0x2000);
//	read16(aud1_isr);
  EmbCS24.Init();
  EmbRepair.Init();
	ch=GetStateSynce();
	if(ch & 0x40){	Ret_code |= E14norma;	}else{ Ret_code &= ~E14norma;}
	if(ch & 0x10){	Ret_code |= RS_synck;	}else{ Ret_code &= ~RS_synck;}
 //	Enable();

  write32(location,control1);
  write32(data_transfer,0x00000008);
//  write16(chip_control,0x004b);
//  write32(aud1_ctrl0,0x00000746);
	
  i=0; j=0;
  while(!EmbCS24.flag){	
		if(i>32000){delay_mcs(1l);
		}else{
			printf("\n\rflag set error");	//090820
			break;
    //090820		printf("\n\rflag set error");	
		}
		i++; 
	}
  write16(chip_control,0x004b);
  write32(aud1_ctrl0,0x00000746);

	i=0;
	write16(command,0);  // Normal play
	write16(cmd_addr,0);
	write16(cmd_data,0);
	write16(cmd_stat,1);
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>32000){  i=0; delay_mcs(1l); printf("\n\rcommand error"); return;}	i++;}
	printff("\n\r...End of InitCS24");
    
    outportb(RESb,0x0b);

}


//__________________________________________________________________




//__________________________________________________________________




int CS24_reset_buff()
{
	int i;// при замене на long завис БУ   - at188 
  //	Disable();

    outportb(RESb,0x09);


  	prf=1;
//   disable both audio and video sync
	write16(chip_control,0x001b);   //video
	write32(aud1_ctrl0,0x00000046); //audio
// Reset Audio Rate Buffer
  	write32(location,audio1_ch_change);
	write32(data_transfer,0x0000012d);
	EmbCS24.flag=0;
	i=0;
	while(read16(aud1_dsr)&0x8000){	if(i>3200000) return 1;	i++; }
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 2;	i++; }
	write16(command,0x0e); // Freeze Frame
	write16(cmd_addr,0);
	write16(cmd_data,0);
	write16(cmd_stat,1);
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 3;	i++; }
//  printf("Freeze Frame");
  	write16(disp_mode,0x8520);
//  write16(disp_mode,0x8500);
//Set video PID = NULL
  	write32(location,0x1fff);
  	write32(data_transfer,0x000001ff);
  	write16(proc_iaddr,0x8200);// Set instruction store address for each 16-bit word in buffer
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 4;	i++; }
	write16(command,0x10); // Reset Rate Buffer
	write16(cmd_addr,0);
	write16(cmd_data,0);
	write16(cmd_stat,1);
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 5;	i++; }
  	write32(location,0x01ff);
	write32(data_transfer,0x00000065);
//Set audio PID
	write32(location,0x011e);
	write32(data_transfer,0x0000012d);
	write16(chip_control,0x004b);
	write32(aud1_ctrl0,0x00000746);
	write16(aud1_imr,0x0800);
	write16(aud1_dsr,0x2000);
	read16(aud1_isr);
//Set video PID 
  	write32(location,0x012c);
  	write32(data_transfer,0x000001ff);
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 6;	i++; }
	write16(command,0);  // Normal play
	write16(cmd_addr,0);
	write16(cmd_data,0);
	write16(cmd_stat,1);
	outportb(IRL,cmd_stat);
	i=0;
	while(inportb(HDlolo)&0x01){	if(i>3200000) return 7;	i++; }
	char ch;
	EmbCS24.Init();                              //// !!!!!!!!!!!!!!!!
  	EmbRepair.Init();
	ch=GetStateSynce();
	if(ch & 0x40){	Ret_code |= E14norma;	}else{ Ret_code &= ~E14norma;}
	if(ch & 0x10){	Ret_code |= RS_synck;	}else{ Ret_code &= ~RS_synck;}
 //	Enable();
	write16(disp_mode,0x8500);

    outportb(RESb,0x0b);

	return 0;
}


char *add_str(char *target, char *source)
{
  int j=0,i=0;
  while(target[i]) i++;
  while(source[j]) target[i+j]=source[j++];
  return target;
}


int test_rb()
{
  unsigned int rb;
  int i=0;
  rb=read16(fifo);

  if(cnt1>40){ Ret_code|= VRBc_error; }
  if(cnt2>40){ Ret_code|= Hold_error; }

  if((Ret_code & E14norma)&&(Ret_code & RS_synck)){
    if(rbuff_size==rb)   cnt1++; else  cnt1=0;
  }else{ cnt1=0; }
  rbuff_size=rb;
  if((Ret_code & 0x001f) == 0x001f){
     cnt=0;  alarm=1;
  }else{
	 if(cnt>20){  alarm=0; }else cnt++;
  }
  if(((Ret_code & 0x001f) == 0x000d)||((Ret_code & 0x001f) == 0x000c)){
    i=1; cnt2++;
  }else{ cnt2=0; i=0;}
  return i;
}



void test_str(char *s1)
{
    char str[25];
  	unsigned int rbuff_size;
    itoa(Ret_code,str,16);
    add_str(s1,str);
    rbuff_size=read16(fifo);
    itoa(rbuff_size,str,16);
//    add_str(s1," ");
    add_str(s1,str);
}
//extern unsigned long  deltaPTS;

void UpdateStatusBarNew(char *s1)
{
 // unsigned int rbuff_size,PTSdelta;
//  unsigned long t;
  long delta=0;
  char str[40];
//	DW w;
	
	if(debug){
//	if(1){
		debug--;
    itoa(Ret_code,str,16);
    add_str(s1,str);
    add_str(s1," ");
		
    ltoa(buff3,str,16);
    add_str(s1,str);
//    add_str(s1," pcr");
//    add_str(s1," stc=");
    add_str(s1," d");

  //  ltoa(EmbCS24.PWM,str,16);
    ltoa(EmbCS24.deltaPTS,str,16); 
//    ltoa(EmbCS24.STCh,str,16);
//    ltoa(EmbCS24.PCR_high,str,16);
    add_str(s1,str);

    add_str(s1," S");
//    ltoa(inportb(Mode1),str,16);
    ltoa(EmbCS24.STCh,str,16);
//    ltoa(EmbCS24.delta,str,16);
    add_str(s1,str);
		s1[23]=0;
	}else{

  if(GetMode())  add_str(s1,"4E1");
  else add_str(s1,"3E1");
  add_str(s1," ");
  switch(GetVideoStandart())
  {
 //   case 0:  add_str(s1,"PAL"); break;
 //   case 1: add_str(s1,"SECAM"); break;
     case 0:  add_str(s1,"SECAM"); break;
    case 1: add_str(s1,"PAL"); break;
    case 2: add_str(s1,"Y/C"); break;
  }
  if(GetTestSignal())
  {
    add_str(s1," Тест=");
    switch(GetTestSignal())
    {
      case 0:  add_str(s1,"Выкл"); break;
      case 1: add_str(s1,"BARS"); break;
      case 2: add_str(s1,"L1"); break;
      case 3:  add_str(s1,"L2"); break;
      case 4: add_str(s1,"L3"); break;
      case 5: add_str(s1,"L4"); break;
    }
  }
//  if(!(Ret_code & E14norma)) add_str(s1," Нет Потока");
  s1[23]=0;
	}
}

//void CS24(char *a, char *c, EmbCommand &embCommand2, EmbCommand &embCommand3, EmbTreeTVM &embTree, char far *dpd)

  unsigned b, key;
  int counter;//,
  char start_key;
  int rate;
  unsigned int CS24stat;
  unsigned long x,y,z,q;
  DW w;
  int ks,rs;
  int r;
  int al;
  unsigned g;
  unsigned char dev_addr, dev_point, addr_flag, point_flag;
  char str[25];
  char s1[64];
  char s2[128];
  int ctrl_flag;
  int ctrl_counter;
  EmbTreePoint *current;
  EmbTreePoint *parent;
  unsigned pt_key;
  char ch;

void CS24()
{
 counter=0;
 start_key=0;
  rate=1;
  b=0;
  key=0;
  CS24stat=0x0000;
  ks=0;
  rs=0;
  al=1;

  SetPrint(0,0);
  rate=GetMode();
 // char ch;

//090601 change_ports  ch=ich=itb(Tx34);
   ch = GetStateSynce(); //090601 change_ports

  if(ch & 0x40){  Ret_code |= E14norma;  }else{ Ret_code &= ~E14norma;}
  if(ch & 0x10){  Ret_code |= RS_synck;  }else{ Ret_code &= ~RS_synck;}

  embIndicator.Cursor(0,0xd7);
  //  char str[25];
 //   char s1[64];
 //   char s2[128];
    ctrl_flag=0;
    ctrl_counter=0;
  //  EmbTreePoint *current;
 //   EmbTreePoint *parent;
  pt_key=0;

  for(i=0; i<25; i++) s1[i]  = 0;
  for(i=0; i<25; i++) s2[i]  = 0;
  for(i=0; i<25; i++) str[i] = 0;

//printf("\n\r... Start CS24");
  if(!dpd_state) return;   //new 
  embTree.Down();
  current = embTree.Current();  
  parent = current->Parent();
  CreateASCIIZ(dpd+embTree.Company(),str);
  add_str(str,"  ");
  CreateASCIIZ(dpd+embTree.City(),s2);
  add_str(str,s2);
  CopyInd0ToRemote(str);
  ConvertToWin1251(str);
//  CopyInd0ToRemote(str);
  embIndicator.SetStr0(str);
  for(i=0; i<25; i++) str[i]=0;
  CreateASCIIZ(dpd+embTree.Name(),str);
  add_str(str,"   ");
  CreateASCIIZ(dpd+embTree.Version(),s1);
  add_str(str,s1);
  add_str(str,"  ");
  CreateASCIIZ(dpd+embTree.Date(),s2);
  add_str(str,s2);
  CopyInd1ToRemote(str);
  ConvertToWin1251(str);
 // CopyInd1ToRemote(str);
  embIndicator.SetStr1(str);

  embIndicator.Cursor(0,0x81);

  dev_addr = EmbGetAddr();
  dev_point = EmbGetPoint();
  addr_flag=0;
  point_flag=0;
}


//  for(;;)
void dtvm()
  {
//unsigned char i2cdata;

/////////////////////////////////  MAX  ///////////////////////////////////////
#ifdef KTVM_PROT2
 if(GetRemoteMode() & 1l)
	{
//#include "remotemux.inc"
 	remote_prot2();
	}
	else
	{
 //	printEthLongHex(0x34);
#endif // KTVM_PROT2


/*
		if(embRS232.UsedTrans()>32) embRS232.TransInit(); 
    if(embRS232.UsedReceive())
    {
      if(embCommand2.Add(embRS232.Receive())==2)
      {
        if(embCommand2.GetType()=='@')
        {
          if((embCommand2.GetAddr()==0xFF)&&(embCommand2.GetPoint()==0xFF))
          {
          }
          else
          {
            if((embCommand2.GetAddr()==0)&&(embCommand2.GetPoint()==0))
            {
              embTree.SetRequest(embCommand2.GetStr());
              embTree.CommandDecoder();
              embTree.GetAnswer(a);
              i=0;
              a[1] = HexChar(EmbGetPoint()>>4);
              a[2] = HexChar(EmbGetPoint()&0x0F);
              a[3] = HexChar(EmbGetAddr()>>4);
              a[4] = HexChar(EmbGetAddr()&0x0F);
              while(a[i]) embRS232.Trans(a[i++]);
              embCommand2.Empty();
              for(i=0; i<128; i++) a[i]=0;
            }
            else
            {
              if((embCommand2.GetAddr()==EmbGetAddr())&&(embCommand2.GetPoint()==EmbGetPoint()))
              {
                embTree.SetRequest(embCommand2.GetStr());
                embTree.CommandDecoder();
                embTree.GetAnswer(a);
                i=0;
                while(a[i]) embRS232.Trans(a[i++]);
                embCommand2.Empty();
                for(i=0; i<128; i++) a[i]=0;
              }
            }
          }
        }
      }
    }*/
////// 485
    if(embRS485.UsedReceive())
    {
      if(embCommand3.Add(embRS485.Receive())==2)
      {
        if(embCommand3.GetType()=='@')
        {
          if((embCommand3.GetAddr()==0xFF)&&(embCommand3.GetPoint()==0xFF))
          {
          }
          else
          {
            if((embCommand3.GetAddr()==EmbGetAddr())&&(embCommand3.GetPoint()==EmbGetPoint()))
            {
              for(i=0; i<128; i++) a[i]=0;
              embTree.SetRequest(embCommand3.GetStr());
              embTree.CommandDecoder();
              embTree.GetAnswer(a);
              i=0;
              while(a[i]) embRS485.Trans(a[i++]);
              embCommand3.Empty();
              for(i=0; i<128; i++) a[i]=0;
            }
          }
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////
#ifdef KTVM_PROT2
} //GetRemotemode
#endif // KTVM_PROT2


 //   wd_res();

 if(!dpd_state) return;

    if(embIndicator.Used())
    {
      b=embIndicator.Get();
      if(('0'<b)&&(b<='6')) 
      { 
        key=b; 
        start_key=1;
      }
    } 
////////  вставить псевдо нажатие по таймеру  ///
    counter++;
    if(start_key)
      if(!key)
        if(!(counter%500))
        {
          key=0xFF;      
        }
/////////////////////////////////////////////////
    if(key)
    {
  //	 printEthLongHex(key);
      if(key!=0xFF) embIndicator.Receipt();
      current = embTree.Current();  
      if(current) parent = current->Parent();
      
      switch(key)
      {
        case 0x31: //embIndicator.SetStr1("Esc");
//*****************************************************
//090601 change_ports   ch=inportb(Tx34);
	  		ch = GetStateSynce();
			if(ch & 0x40){  Ret_code |= E14norma;  }else{ Ret_code &= ~E14norma;}
  			if(ch & 0x10){  Ret_code |= RS_synck;  }else{ Ret_code &= ~RS_synck;}
// i2cdata = ReadDataI2C(ADDR_READ_I2C);
 //	printf("\n\r> i2c: 0x%X ", i2cdata);	
			debug=50;
			printff("deltaPTS=%x%x",(unsigned)((EmbCS24.deltaPTS>>16) & 0x0000ffff),(unsigned)(EmbCS24.deltaPTS & 0x0000ffff));
			printff("PWM=%x",(unsigned)(EmbCS24.PWM));
//*****************************************************
      	    break; // Esc
       	case 0x32: //embIndicator.SetStr1("Up");
            if(ctrl_flag|addr_flag|point_flag)
            {
              if(addr_flag)
              {
                embIndicator.Cursor(2,0xD7);
                dev_addr++;
              }
              if(point_flag)
              {
                embIndicator.Cursor(2,0xD7);
                dev_point++;
              }
              else
              {
                embIndicator.Cursor(2,0xD7);
                EmbParameter *par = current->Parameter();
                EmbSet *embSet = embTree.GetSets(par->Type()-12);
                ctrl_counter++;
                if(ctrl_counter>=embSet->NumItem()) ctrl_counter=0;
              }
            }
            else
            {
              ctrl_counter=0;
              if(parent->Parent()) embTree.Up();   
            }
///                   if(ks) if(!rate) rate=1; 
            break; // Up           
        case 0x33: //embIndicator.SetStr1("Enter");
          switch(pt_key)
          {
            case PT_ADDR:  
              if(!addr_flag) 
              {
                addr_flag=1;
                embIndicator.Cursor(2,0xD7);
              }
              else 
              {
                pt_key = PT_NULL;
                addr_flag=0;
                EmbSetAddr(dev_addr);
                embIndicator.Cursor(0,0xD7);
              }
              break;
            case PT_POINT:
              if(!point_flag) 
              {
                point_flag=1;
                embIndicator.Cursor(2,0xD7);
              }
              else 
              {
                pt_key = PT_NULL;
                point_flag=0;
                EmbSetPoint(dev_point);
                embIndicator.Cursor(0,0xD7);
              }
              break;
//______________________________________________________________________________________>> Protokol
		    case PT_CTRL:
			  if(!ctrl_flag) 
			  {
			  	ctrl_flag=1;
			  	embIndicator.Cursor(2,0xD7);
			  	if(embTree.LexCmp(current->Name(),"Протокол"))
			  	{
			  	  ctrl_counter = EmbGetProt();// 1-выкл  0-вкл
   			  	}
//_________________________________________________________>>>>>>>>>>>>>>>>>>>>>>>>>test
					//		 	 else	 if(embTree.LexCmp(current->Name(),"звук"))
					//		   		{
					 //			 	  ctrl_counter = EmbGetSound();// 1-выкл  0-вкл
   					  //			 	}
//_________________________________________________________<<<<<<<<<<<<<<<<<<<<<<<<<<test
			  	else
				{
				  ctrl_counter = embTree.GetParameterNum();
				}

							 //	ctrl_counter = embTree.GetParameterNum();
			  }
			  else 
			  {
			  	pt_key = PT_NULL;
			  	ctrl_flag=0;
			  	embIndicator.Cursor(0,0xD7);
			  	EmbParameter *par = current->Parameter();
			  	if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
			  	if(par->Type()-12<embTree.CountSets())
			    {
			  	  char str_par[32];
			  	  EmbSet *embSet = embTree.GetSets(par->Type()-12);
			      CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
				  embTree.SetParameter(str_par);
//___________________________________________________________________________________>>>test
							 //		if(embTree.LexCmp(current->Name(),"звук"))
							  //		{
							  //		   if(ctrl_counter){ MakeSoundLock(); EmbSetSound(1);} // 1-выкл  0-вкл
							  //			else {  MakeSoundUnLock(); 
							   //			EmbSetSound(0);}
 
							  //	 	}
//____________________________________________________________________________________<<<test
				  if(embTree.LexCmp(current->Name(),"Протокол"))
				  {
				    if(ctrl_counter) {SetProtokol(1);}// 1-выкл  0-вкл
				    else{ SetProtokol(0); }
				  }
	  		    }
			  }
			  break;

//______________________________________________________________________________________<<Protokiol
            default:
              if(ctrl_flag)
              {
                rs=1; ks=0;
                embIndicator.Cursor(0,0xd7);
                EmbParameter *par = current->Parameter();
                if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
                  if(par->Type()-12<embTree.CountSets())
                  {
                    char str_par[32];
                    EmbSet *embSet = embTree.GetSets(par->Type()-12);
                    CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
                    embTree.SetParameter(str_par);
                    ctrl_flag=0;
                  }
              }
              else
              { 
                ks=1; 
                embIndicator.Cursor(2,0xd7);
                ctrl_flag=1;
              }
            break; // Enter          
          }
          break;
        case 0x34: //embIndicator.SetStr1("Left");
          ctrl_flag = 0;
          embIndicator.Cursor(0,0xD7);
          embTree.Left(); 
          break; // Left

        case 0x35: //embIndicator.SetStr1("Down");
            if(ctrl_flag|addr_flag|point_flag)
            {
              if(addr_flag)
              {
                embIndicator.Cursor(2,0xD7);
                dev_addr--;
              }
              if(point_flag)
              {
                embIndicator.Cursor(2,0xD7);
                dev_point--;
              }
              else
              {
                embIndicator.Cursor(2,0xD7);
                EmbParameter *par = current->Parameter();
                EmbSet *embSet = embTree.GetSets(par->Type()-12);
                ctrl_counter--;
                if(ctrl_counter<0) ctrl_counter=embSet->NumItem()-1;
              }
            }
            else
            {
              ctrl_counter=0;
              embTree.Down();
            }
//                   if(ks)if(rate) rate=0; 
          break; // Down
        case 0x36: //embIndicator.SetStr1("Right");
            ctrl_flag = 0;
            embIndicator.Cursor(0,0xD7);
            embTree.Right(); 
          break; // Right
      }
      current = embTree.Current();
      if(current) parent = current->Parent();
      for(i=0; i<25; i++) s1[i]  = 0;
      for(i=0; i<25; i++) s2[i]  = 0;
      for(i=0; i<25; i++) str[i] = 0;

      UpdateStatusBarNew(s1);
	  CopyInd0ToRemote(s1);
      ConvertToWin1251(s1);
  //	  CopyInd0ToRemote(s1);
      embIndicator.SetStr0(s1);
      CreateASCIIZ(dpd+current->Name(),s2);
      pt_key = PT_NULL;
      if(!current->Child()) 
      {
        add_str(s2," : ");
///////////////////////   Управление  /////////////////////
//      if(current->Name())
        if(embTree.LexCmp(current->Name(),"Адр_Станции_Сист"))
        {
          BYTE i;
          pt_key = PT_POINT;
          if(!point_flag) dev_point = EmbGetPoint();
          char ch_p[8];
          itoa(dev_point,ch_p,10); 
          add_str(s2,ch_p);
          int fl1=0;
          for(i=0; i<24; i++)
          {
            if(!s2[i]) fl1=1;
            if(fl1) s2[i]=' ';
          }
          s2[23] = 0x7E;
          s2[24] = 0;
        }
//___________________________________________________________________________________


  	else if(embTree.LexCmp(current->Name(),"Протокол"))
					  {
					  EmbParameter *par = current->Parameter();
				   //		pt_key = PT_PROG;
						if(!ctrl_flag) ctrl_counter =  EmbGetProt();
				//		printEthLongHex(ctrl_counter);
						pt_key  =  PT_CTRL;
						if(par->Type()-12<embTree.CountSets())
						{
							BYTE i;
							char str_par[32];
							EmbSet *embSet = embTree.GetSets(par->Type()-12);
							CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
							add_str(s2, str_par);
							int fl1=0;
							for(i=0; i<24; i++)
							{
								if(!s2[i]) fl1=1;
								if(fl1) s2[i]=' ';
							}
						  s2[23] = 0x7E;
						  s2[24] = 0;
						}
					  }

 
//___________________________________________________________________________________

        else
        {
          if(embTree.LexCmp(current->Name(),"Адр_Устр_Сист"))
          {
            BYTE i;
            pt_key = PT_ADDR;
            if(!addr_flag) dev_addr = EmbGetAddr();
            char ch_p[8];
            itoa(dev_addr,ch_p,10);
            add_str(s2,ch_p);
            int fl1=0;
            for(i=0; i<24; i++)
            {
              if(!s2[i]) fl1=1;
              if(fl1) s2[i]=' ';
            }
            s2[23] = 0x7E;
            s2[24] = 0;
          }
//_____________________________________________________________
  		  else if(embTree.LexCmp(current->Name(),"Версия"))
		  {
			   FillProgVersion1(&s2[8] , 8);
		  }
//_____________________________________________________________
  		  else if(embTree.LexCmp(current->Name(),"Вход_E1"))
		  {
			   FillSynceVersion1(&s2[10] , 6);
		  }
//____________________________________________________________
//_____________________________________________________________
  		  else if(embTree.LexCmp(current->Name(),"Звук_Синхр."))
		  {
			   FillSound(&s2[10] , 6);
		  }
//____________________________________________________________


          else
          {
            EmbParameter *par = current->Parameter();
            if((par->accessType.access==2)||(par->accessType.access==3)) // 2-write 3-read-write
            {
              if(!ctrl_flag) ctrl_counter = embTree.GetParameterNum();
              pt_key =  PT_CTRL;
              if(par->Type()-12<embTree.CountSets())
              {
                BYTE i;
                char str_par[32];
                EmbSet *embSet = embTree.GetSets(par->Type()-12);
                CreateASCIIZ(dpd+embSet->SetItem(ctrl_counter)->Name(),str_par);
                add_str(s2, str_par);
                int fl1=0;
                for(i=0; i<24; i++)
                {
                  if(!s2[i]) fl1=1;
                  if(fl1) s2[i]=' ';
                }
                s2[23] = 0x7E;
                s2[24] = 0;
              }
            }
			  else if(embTree.LexCmp(current->Name(),"Вход_E1"))
		  {
			   FillSynceVersion1(&s2[10] , 6);
		  }
			  else if(embTree.LexCmp(current->Name(),"Звук_Синхр."))
		  {
			   FillSound(&s2[10] , 6);
		  }
          }
        }
      }
	  CopyInd1ToRemote(s2);
      ConvertToWin1251(s2);
   //	  CopyInd1ToRemote(s2);
      embIndicator.SetStr1(s2);
      key=0;
    }
/*
    if(al!=alarm){					  ?????
	  al=alarm;
      if(al){  outportb(RESb,3);}
	  else  {  outportb(RESb,1);}//embIndicator.SetLtDiod(1,1);
	}
*/

//  outportb(RESb,0x0b); //  Test !!!!!
//  outportb(RESb,0x09);


    if(CS24stat!=Ret_code)
    {
	printf("\n\r Ret_code: %X", Ret_code);
      CS24stat = Ret_code;
      SetPrint(CS24stat,1);
      SetStat(CS24stat);
//_____________________________________________________________operate leds
      if(CS24stat & E14norma){// & (unsigned)E14norma){
        embIndicator.SetLtDiod(0,1);
		outportb(XILINX_ALARM_REGISTER, ~(ALARM_RELE));
        if((CS24stat & 0x0013)==0x0013)
        {
          embIndicator.SetLtDiod(0,2);
          embIndicator.SetLtDiod(1,3);
      //    tscount++;
        }else
        {
          embIndicator.SetLtDiod(1,2);
          embIndicator.SetLtDiod(0,3);
     //     tscount++;
        }
      }else{
		outportb(XILINX_ALARM_REGISTER, ALARM_RELE);
        embIndicator.SetLtDiod(1,1); // alarm
        embIndicator.SetLtDiod(0,2);
        embIndicator.SetLtDiod(0,3);
      }
    } //!= ret_code
	if(CS24stat & 0x9480){ // Overflow
	    printf("\n\r CS24_reset_buff= %x",CS24stat);
	    prf=1;
	    cnt=0;
	    cnt1=0;
 	    cnt2=0;
	    Ret_code=0x0000;
	    if((r=CS24_reset_buff()))	  //make  == from =
	    {
		   printf("\n\r CS24_restart= %x",CS24stat);
	 	   restart();
		   return;
		 }
	}

	if(EmbCS24.flag!=flag_t){
	   printf("\n\rflag=%x f=%x",EmbCS24.flag,flag_t);
		flag_t=EmbCS24.flag;
	}
	if(CS24stat & 0x6b20){

    outportb(RESb,0x09);
    outportb(RESb,0x0b);

	   prf=1;
	   cnt=0;
	   cnt1=0;
	   cnt2=0;
	   printf("\n\rReset=%x",CS24stat);
	   Ret_code=0x0000;
	   _int_disable();
	   EmbCS24.Init();
	   _int_enable();
    }
  }




//not need }

 /*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{
  EmbCS24.IsrXX();	//this use in irq1?
  EmbRepair.IsrXX();	//this use in irq0?	 //t
  IntFlag |= INT0_FLAG;
  Stephany19++;
 //t my_int_enable_irq0();
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq0();
 }

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
//  EmbCS24.IsrXX();	//this use in irq1?
 //IntFlag |= INT1_FLAG;
 //t my_int_enable_irq0();
 if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
 {
   InterruptWatchDog++;
   my_int_enable_irq1();
 }

}



extern "C" void testprint()
{
 if(tsee[0])
 {

 tsee[0] = 	0;	  // finish print
  printf("\n\r PTS2  	: 0x%lX", tsee[1]);
  printf("\n\r PTS1  	: 0x%lX", tsee[2]);
  printf("\n\r PTS0  	: 0x%lX", tsee[3]);
  printf("\n\r CTS2  	: 0x%lX", tsee[4]);
  printf("\n\r CTS1  	: 0x%lX", tsee[5]);
  printf("\n\r CTS0  	: 0x%lX", tsee[6]);
  printf("\n\r buff3 	: 0x%lX", tsee[7]);
  printf("\n\r z 		: 0x%lX", tsee[8]);
  printf("\n\r deltaPTS : 0x%lX", tsee[9]);
  printf("\n\r STCh 	: 0x%lX", tsee[10]);
 }
}
















