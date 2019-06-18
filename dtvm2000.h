#ifndef _dtvm2000_h_
#define _dtvm2000_h_ 

extern int test_rb(void);
extern int debug;
extern int alarm;
extern int pwm_print;
extern int cnt;
extern int cnt1;
extern int cnt2;
extern unsigned buff3;
extern unsigned buff2;
extern unsigned int rbuff_size;
extern int prf;

extern "C" void ReadDPD(char * );
extern void InitFreePtr(void);
extern  void Init_CS24(void);
extern  void CS24(void);

extern EmbCS24Int EmbCS24;
extern EmbRepairInt EmbRepair;
/*
extern EmbCS24_NMI0_Int EmbCS24_NMI0;
extern EmbCS24_NMI1_Int EmbCS24_NMI1;
extern EmbCS24_NMI1_Int EmbCS24_NMI;
extern EmbCS24_NMI3_Int EmbCS24_NMI3;
extern EmbCS24_NMI4_Int EmbCS24_NMI4;
extern EmbCS24_NMI5_Int EmbCS24_NMI5;
extern EmbCS24_NMI6_Int EmbCS24_NMI6;
 */
extern EmbTreePoint *current;

extern unsigned b;
extern unsigned key;
extern int counter;
// extern int start;
extern int rate;
extern  unsigned int CS24stat;
extern int ks;
extern int rs;
extern int al;
extern unsigned char dev_addr;
extern unsigned char  dev_point;
extern unsigned char  addr_flag;
extern unsigned char  point_flag;



#endif
