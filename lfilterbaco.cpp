//lfilterbaco.cpp



#define FILTER_SIZE		(1216)
#define MODE_PORT		(4)
#define DATA_PORT		(8)
#define CNT_PORT		(9)



void LoadFiltersBaco1()
{
  unsigned char* ptr;
  register int i;
  unsigned char command = 0;
  read_dataflash ((unsigned int)(AUDIO_ADDRESS + HEADER_SIZE), (unsigned int)FILTER_SIZE, (char *)(&TFTP_Buffer[0]));
  ptr=(unsigned char*)(&TFTP_Buffer[0]);
   command = 0;
   outportb(CNT_PORT,command);

  for(i=0;i < FILTER_SIZE ; i+=4){
   command = MASK_BIT_4;
 //  printfpd("\n\r %x ", *ptr);
   outportb(DATA_PORT,*ptr++);
   outportb(CNT_PORT,command);
   command++;
//    printfpd(" %x ", *ptr);
   outportb(DATA_PORT,*ptr++);
   outportb(CNT_PORT,command);
   command++;
 //   printfpd(" %x ", *ptr);
   outportb(DATA_PORT,*ptr++);
   outportb(CNT_PORT,command);
   command++;
   command |= MASK_BIT_3;
  // printfpd(" %x ", *ptr);
   outportb(DATA_PORT,*ptr++);
   outportb(CNT_PORT,command);
  }
  command = 0;
  outportb(CNT_PORT,command);

}

extern "C" void LoadFiltersBaco()
{
  unsigned char* ptr;
  register int i;
  unsigned char command = 0;
  unsigned long size;
   int l_base;


 // read_dataflash ((unsigned int)(AUDIO_ADDRESS + HEADER_SIZE), (unsigned int)FILTER_SIZE, (char *)(&TFTP_Buffer[0]));
 // ptr=(unsigned char*)(&TFTP_Buffer[0]);
 
 for(unsigned is=1; is < NUM_OF_SLOT; is+=2)	//only nechet
	{

  	l_base = 0x500 + is * 16;



     ptr =  (unsigned char *)(NVRAM_BASE);// + BACO_OFFSET_FILTER);
	 ptr += (unsigned long)BACO_OFFSET_FILTER;
	 size =	(unsigned long)(*ptr++);
	 size += (unsigned long)((*ptr++) << 8);
	 size += (unsigned long)((*ptr++) << 16);
	 size += (unsigned long)((*ptr++) << 24);

   size <<= 2;  //size in words

   if(size > MAX_FILTER_SIZE)
 {
  printfpd("\n\rload filter size too big : %d", size);
 }
 else
 {
  printfpd("\n\rload filter size OK : %d", size);

   command = 0;
   outportb(l_base + CNT_PORT,command);

//  for(i=0; i < (size >> 2) ; i+=4){
  for(i=0; i < size ; i+=4){
   command = MASK_BIT_4;
 //  printfpd("\n\r %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
 //   printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
//    printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
   command |= MASK_BIT_3;
//   printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
  }
  command = 0;
  outportb(l_base + CNT_PORT,command);
 }
 } //for
 }


extern "C" void LoadFreqBaco()
{
  unsigned char* ptr;
  register int i;
  unsigned char command = 0;
 // unsigned long size;
   int l_base;

 
 for(unsigned is=1; is < NUM_OF_SLOT; is+=2)	//only nechet
	{

  	l_base = 0x500 + is * 16;



     ptr =  (unsigned char *)(NVRAM_BASE);// + BACO_OFFSET_FILTER);
	 ptr += (unsigned long)BACO_OFFSET_FREQ;
  //{
 // printfp("\n\rload offset freq ");

//   command = 0;
   command = MASK_BIT_2;	  //load offset
   outportb(l_base + CNT_PORT,command);

//  for(i=0; i < (size >> 2) ; i+=4){
 // for(i=0; i < size ; i+=4){
   command |= MASK_BIT_4;
 //  printfpd("\n\r %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
 //   printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
//    printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr++);
   outportb(l_base + CNT_PORT,command);
   command++;
   command |= MASK_BIT_3;
//   printfpd(" %x ", *ptr);
   outportb(l_base + DATA_PORT,*ptr);
   outportb(l_base + CNT_PORT,command);
//  }
  command = 0;
  outportb(l_base + CNT_PORT,command);

 }	//slot
}


extern "C" void LoadModeBaco(unsigned char mode)
{
 // unsigned char* ptr;
 // register int i;
 // unsigned char command = 0;
 // unsigned long size;
   int l_base;


 // read_dataflash ((unsigned int)(AUDIO_ADDRESS + HEADER_SIZE), (unsigned int)FILTER_SIZE, (char *)(&TFTP_Buffer[0]));
 // ptr=(unsigned char*)(&TFTP_Buffer[0]);
 
 for(unsigned is=1; is < NUM_OF_SLOT; is+=2)	//only nechet
	{

  	l_base = 0x500 + is * 16;



 //    ptr =  (unsigned char *)(NVRAM_BASE);// + BACO_OFFSET_FILTER);
 //	 ptr += (unsigned long)BACO_OFFSET_FREQ;
  //{
 // printfp("\n\rload mode ");

 //  command = 0;
   outportb(l_base + MODE_PORT,mode);


 }	//slot
}








