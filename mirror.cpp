//file : mirror.cpp

#define MIRROR_PORT	(0)

extern "C" unsigned char MirrorTest()
{
 unsigned char ret = 1;
 unsigned char test = 0x5A;
 outportb(MIRROR_PORT, test);
 if(test != inportb(MIRROR_PORT))  ret = 0;
 test = 0xA5;
 outportb(MIRROR_PORT, test);
 if(test != inportb(MIRROR_PORT))  ret = 0;

//printfpd("\n\r>%d", ret); //for test
 return ret;
}

#ifdef TEST_BUS

extern "C" unsigned char TestBus(void)
{
printfp("\n\r TestBus");

 unsigned char ret = 0;
 unsigned i;
 unsigned long tmp;

   AT91RM9200_MC_REG_STRUCT_PTR mc_ptr;   //memory controller
 	mc_ptr = (AT91RM9200_MC_REG_STRUCT_PTR) AT91RM9200_MC_BASE;

  //	mc_ptr->EBI.SMC.CSR[2] = 0x12014300l;	   //tdf = 3
//  mc_ptr->EBI.SMC.CSR[2] = 0x12014000l;	  //tdf = 0

//ok  tmp = 0x12014084l;
//ok  tmp = 0x11014081l;
//wrong  tmp = 0x00014081l;
 //wrong tmp = 0x01014081l;
  tmp = 0x11014081l;


 for(i = 0 ; i < 5; i++)
{
 
 


mc_ptr->EBI.SMC.CSR[2]  = tmp;

  printfpd("\n\r i = %d ", i);
  printfpd(" csr : 0x%08X ", mc_ptr->EBI.SMC.CSR[2]);


 if (MirrorTest())
{
  printfp("...ok");
   ret = 1;
}
else
{
   printfp("...wrong");
}

 tmp += 1;
// tmp += 1 << 28;
// tmp += 1 << 24;

  
}

 tmp = 0x11014081l;


 for(i = 0 ; i < 5; i++)
{
 
 


mc_ptr->EBI.SMC.CSR[2]  = tmp;

  printfpd("\n\r i = %d ", i);
  printfpd(" csr : 0x%08X ", mc_ptr->EBI.SMC.CSR[2]);


 if (MirrorTest())
{
  printfp("...ok");
   ret = 1;
}
else
{
   printfp("...wrong");
}

// tmp += 1;
// tmp += 1 << 28;
 tmp += 1 << 24;

  
}

tmp = 0x11014081l;


 for(i = 0 ; i < 5; i++)
{
 
 


mc_ptr->EBI.SMC.CSR[2]  = tmp;

  printfpd("\n\r i = %d ", i);
  printfpd(" csr : 0x%08X ", mc_ptr->EBI.SMC.CSR[2]);


 if (MirrorTest())
{
  printfp("...ok");
   ret = 1;
}
else
{
   printfp("...wrong");
}

// tmp += 1;
 tmp += 1 << 28;
// tmp += 1 << 24;

  
}

tmp = 0x11014081l;


 for(i = 0 ; i < 5; i++)
{
 
 


mc_ptr->EBI.SMC.CSR[2]  = tmp;

  printfpd("\n\r i = %d ", i);
  printfpd(" csr : 0x%08X ", mc_ptr->EBI.SMC.CSR[2]);


 if (MirrorTest())
{
  printfp("...ok");
   ret = 1;
}
else
{
   printfp("...wrong");
}

// tmp += 1;
 tmp += 1 << 8;
// tmp += 1 << 24;

  
}











  mc_ptr->EBI.SMC.CSR[2] = 0x12014384l;


return ret;
}

#endif
