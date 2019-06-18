#ifndef _init26_h_
#define _init26_h_ 

class EmbCS24Int : public EmbIsr
{
  unsigned int  HostInt;
  unsigned int  HostInt1;
  unsigned long TransInt;
  unsigned long Front_end_stat;
  unsigned long QueuInt;
  unsigned long Audio1Stat;
  unsigned long VideoStat;
  unsigned long Audio1Int;
  unsigned long Audio2Int;
  public:
	unsigned long STCh,STCl,PTSh;
  unsigned PTS0,PTS1,PTS2,STC0,STC1,STC2,STCv0,STCv1,STCv2;
//  unsigned long delta;
//  unsigned long PWM;
  unsigned long PTShi;
  unsigned long PTSlo;
  unsigned long STChi;
  unsigned long STClo;
  unsigned long PCR_low;
  unsigned long PCR;
  unsigned long STC_high;
  unsigned long STC_low;
  unsigned long d;
  long dt1,dt,offset;
  int signal,e;
	int t,tr,delta2;
  int N,M;

  unsigned long PCR_high;
  unsigned long delta;
  unsigned long deltaPTS;
  unsigned long PWM;

	unsigned int tl,th;
	unsigned int bf[16];
	int fn,flag2;

  int flag,fdt;
  int mask_val;
  int count;
  unsigned VRB,VRBpr,VRBct;
  unsigned dPCR,dPCRpr,dPCRct;
//    unsigned stat;
//    unsigned mode;
    void Init();
    void Init_IRQ();
    void IsrXX();
};

class EmbRepairInt : public EmbIsr
{
  public:
  void Init(); 
  void Init_IRQ(); 
  void IsrXX();
};

//#ifdef IncNMI
 /*
class EmbNMI0 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};

class EmbNMI1 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};

class EmbNMI3 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};

class EmbNMI4 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};

class EmbNMI5 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};

class EmbNMI6 : public EmbIsr
{
  public:
  //  int Init();
    void IsrXX();
};
*/
//#endif
 /*

class EmbCS24_NMI0_Int : public EmbNMI0
{
    void IsrXX();
};

class EmbCS24_NMI1_Int : public EmbNMI1
{
    void IsrXX();
};

class EmbCS24_NMI3_Int : public EmbNMI3
{
    void IsrXX();
};

class EmbCS24_NMI4_Int : public EmbNMI4
{
    void IsrXX();
};

class EmbCS24_NMI5_Int : public EmbNMI5
{
    void IsrXX();
};

class EmbCS24_NMI6_Int : public EmbNMI6
{
    void IsrXX();
};


class EmbNMI2 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};
 */
extern unsigned long i;
extern char a[128];
extern EmbTreePoint *current;
extern void set_audio(int ,int );
extern unsigned long get_audio(int ,int );

extern  EmbIndicator embIndicator;
extern  void  itoa(long , char *, int );
extern void  ltoa(long , char *, int);
extern EmbTree  embTree;
extern char  *dpd;
extern void ConvertToWin1251(char *);
extern EmbRS485 embRS485;
extern  EmbCommand embCommand3;
//extern int tscount;
extern EmbTimer embTimer;
extern "C" void  my_int_enable_irq1(void);
#endif
