//#include "rbuff.cpp"

#define COM_BUFFER_SIZE 384
#define ACT_BUFFER_SIZE 384

template<class T,int Size> class TRBuffer
{
    unsigned BuffSize;
    unsigned Head;
    unsigned Tail;
    T Buff[Size];
  public:
    void Init();
    void Add(T elem);
    T Get();
    unsigned Used();
    unsigned Free();
};
/*
#define timer0vect 0x20
#define timer1vect 0x48
#define timer2vect 0x4c
#define int0vect   0x30
#define int1vect   0x34
#define int2vect   0x38
#define int3vect   0x3c
#define int4vect   0x40
#define dma0vect   0x28
#define dma1vect   0x2c
#define serial0vect 0x44
#define serial1vect 0x42
*/
class EmbIsr
{
	static num;
	protected:
    void InitIRQ(int irq);
  public:
    virtual void IsrXX() {}
};

class EmbCOM : public EmbIsr
{
	protected:
    unsigned state;
		unsigned char con,port;
    TRBuffer<char,COM_BUFFER_SIZE> trsbuf;
    TRBuffer<char,ACT_BUFFER_SIZE> rcvbuf;
  public:
    virtual int Init(unsigned rate);
		void EmptyReceive() { rcvbuf.Init(); };
		void EmptyTrans() { trsbuf.Init(); };
    virtual void IsrXX();
    unsigned GetSpeed();
    void SetSpeed(unsigned);
    unsigned char Receive();
    virtual void Trans(unsigned char ch);
    virtual void TransInit();
    unsigned UsedReceive() { return rcvbuf.Used(); }
    unsigned FreeReceive() { return rcvbuf.Free(); }
    unsigned UsedTrans()   { return trsbuf.Used(); }
    unsigned FreeTrans()   { return trsbuf.Free(); }
};

#ifdef IncEmbRS485

const RS485_CTRL = 0x0605;
const RS485_DATA = 0x0604;
const RS485_IRQ  = 0x10;

struct EmbRS485Bit
{
  int IRQ_trans		: 1;
  int IRQ_receive	: 1;
  int error				: 1;
  int dirCTS			: 1;
  int trans				: 1;
  int receive			: 1;
  int reset1			: 1;
  int reset0			: 1;
};

union Emb485Bit
{
  EmbRS485Bit bit;
  unsigned char byte;
};


class EmbRS485 : public EmbCOM
{
	public:
    int Init(unsigned rate);
    void IsrXX();
    void Trans(unsigned char ch);
//    void TransInit();
};
#endif

#ifdef IncEmbRS232

class EmbRS232 : public EmbCOM
{
	public:
    int Init(unsigned rate);
    void IsrXX();
    void Trans(unsigned char ch);
    void TransInit();
};
#endif

#ifdef IncNMI

class EmbNMI0 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI1 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI2 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI3 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI4 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI5 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};

class EmbNMI6 : public EmbIsr
{
  public:
    int Init();
    void IsrXX();
};
#endif

class EmbIsrINT0 : public EmbIsr
{
	protected:
		void EOI();
		void Disable();
		void Enable();
  public:
    void Init();
    virtual void IsrXX();
};

class EmbIsrINT1 : public EmbIsr
{
	protected:
		void EOI();
		void Disable();
		void Enable();
  public:
    void Init();
    virtual void IsrXX();
};

class EmbIsrINT2 : public EmbIsr
{
	protected:
    void Init();
		void EOI();
		void Disable();
		void Enable();
  public:
    virtual void IsrXX();
};

class EmbIsrINT3 : public EmbIsr
{
	protected:
    void Init();
		void EOI();
		void Disable();
		void Enable();
  public:
    virtual void IsrXX();
};

class EmbIsrINT4 : public EmbIsr
{
	protected:
		void EOI();
		void Disable();
		void Enable();
  public:
    void Init();
    virtual void IsrXX();
};


#ifdef IncEmbTimer

struct EmbTimerCallback
{
	unsigned long interval;
	unsigned long count;
	void (*callback)();
};

class EmbTimer : public EmbIsr
{
		EmbTimerCallback *embTimerCallback0;
		EmbTimerCallback *embTimerCallback1;
		EmbTimerCallback *embTimerCallback2;
		EmbTimerCallback *embTimerCallback3;
		EmbTimerCallback *embTimerCallback4;
	  unsigned long counter;
  public:
    int Init(int ms); // в мкс
    void IsrXX();
		void SetCallBack0(EmbTimerCallback *e);
		void SetCallBack1(EmbTimerCallback *e);
		void SetCallBack2(EmbTimerCallback *e);
		void SetCallBack3(EmbTimerCallback *e);
		void SetCallBack4(EmbTimerCallback *e);
};
#endif

#ifdef IncEmbIndicator

const INDICATOR_CTRL = 0x0601;
const INDICATOR_DATA = 0x0600;
const INDICATOR_IRQ  = 0x0E;
const INDICATOR_SIZE = 24;
const INDICATOR_SIZE_COMMAND = 34;

struct EmbIndCtrlBit
{
  int IRQ_trans		: 1;
  int IRQ_receive	: 1;
  int error				: 1;
  int dirCTS			: 1;
  int trans				: 1;
  int receive			: 1;
  int reset1			: 1;
  int reset0			: 1;
};

union EmbIndCtrl
{
  EmbIndCtrlBit bit;
  unsigned char byte;
};

struct EmbIndicatorCommand
{
  char str[INDICATOR_SIZE_COMMAND];
	char size;
}; 

const IndFrequNone = 0;
const IndFrequ1250Hz = 4;
const IndFrequ1000Hz = 5;
const IndFrequ833Hz = 6;
const IndFrequ714Hz = 7;
const IndFrequ625Hz = 8;
const IndFrequ500Hz = 10;
const IndFrequ416Hz = 12;
const IndFrequ333Hz = 15;
const IndFrequ200Hz = 25;

struct EmbSound
{
  char frequ;
	char pause;
  char sound;
};

class EmbIndicator : public EmbIsr
{
		TRBuffer<char,256> m_TBuff;
		TRBuffer<char,16> m_RBuff;
	  char r_state;
    char str0[INDICATOR_SIZE+1];
    char str1[INDICATOR_SIZE+1];
		EmbIndCtrl eic;
  public:
    int Init(); 
		unsigned Used() { return m_RBuff.Used(); }
		char Get() { return m_RBuff.Get(); } // 'N' норма, 'X' - ошибка обмена, 0-N - нажата кнопка
    void IsrXX();
		void Receipt();
		void Cursor(char mode,unsigned char addr);
		void Reset();
		void SetStr0(char *str);
		void SetStr1(char *str);
		void SetLtDiod(char mode,char number);
		void Sound0(char frequ);
		void SoundRing();
		void SoundAlarm();
		void Sound1(char mode,EmbSound s1);
		void Sound2(char mode,EmbSound s1,EmbSound s2);
		void Sound3(char mode,EmbSound s1,EmbSound s2,EmbSound s3);
		void Sound4(char mode,EmbSound s1,EmbSound s2,EmbSound s3,EmbSound s4);
};
#endif

struct RTClockCtrl
{
	int w					: 1;
	int r					: 1;
	int s					: 1;
	int calibrate : 5;
};

struct RTime
{
	unsigned char ctrl;
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char mon;
	unsigned char year;
};

union RTUnion
{
	unsigned long value;
	RTime rt_time;
};

class EmbRTClock
{
	public:
		void Init();
		void StartClock();
		void SetTimeDate(RTUnion *r);
		void GetTimeDate(RTUnion *r);
		char *GetTimeDateStr(char *str);
		char *GetDateStr(char *str);
		char *GetTimeStr(char *str);

};

unsigned char EmbGetPoint() { return *((unsigned char far*)0x80001FF0); }
unsigned char EmbGetAddr() { return *((unsigned char far*)0x80001FF1); }
void EmbSetPoint(unsigned char b) { *((unsigned char far*)0x80001FF0) = b; }
void EmbSetAddr(unsigned char b) { *((unsigned char far*)0x80001FF1) = b; }

#ifdef IncEmbSerialACT8

class EmbSerialACT8Receive : public EmbIsrINT0
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuff;
  public:
		void Init() { EmbIsrINT0::Init(); m_RBuff.Init(); } 
		void Empty() { m_RBuff.Init(); }
		void ReceiveInit(); 
		unsigned Used() { return m_RBuff.Used(); }
		char Get() { return m_RBuff.Get(); }
    void IsrXX();
};

class EmbSerialACT8Send : public EmbIsrINT1
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuff;
  public:
		void Init();
		void Empty() { m_TBuff.Init(); } 
 	  unsigned Used() { return m_TBuff.Used(); }
		void TransInit(); 
 	  void Add(unsigned char byte);
    void IsrXX();
};

class EmbSerialACT8Control : public EmbIsrINT3
{
	  int busy;
  public:
		void Init() { EmbIsrINT3::Init(); busy = 0; } 
		int Send(unsigned command) { if(!busy) { outport(0x500,command); busy = 1; return 1; } return 0;}
    void IsrXX();
};

#endif

#ifdef IncEmbSerialMF20

class EmbSerialMF20Receive
{
  public:
		void Init() {} 
		void Empty() {}
    void ReceiveInit() {} 
		unsigned Used() { return 0; }
		char Get() { return 0; }
    void IsrXX() {}
};

class EmbSerialMF20Send
{
		TRBuffer<unsigned char,ACT_BUFFER_SIZE> m_TBuff;
  public:
    void Init() {}
		void Empty() {} 
 	  unsigned Used() { return 0; }
    void TransInit() {} 
 	  void Add(unsigned char byte) {} ;
    void IsrXX() {}
};

class EmbSerialMF20Control
{
	  int busy;
  public:
		void Init() { busy = 0; } 
		int Send(unsigned command) { return 0; }
    void IsrXX() {}
};

#endif

#ifdef IncEmbSerialACT155

struct EmbSerialACT155IRQ
{
  int IRQ_RX_mod		: 1;
  int IRQ_TX_mod		: 1;
  int IRQ_RX_trans	: 1;
  int IRQ_TX_trans  : 1;
  int IRQ_RX_power  : 1;
  int IRQ_TX_power	: 1;
  int reserv			  : 1;
  int IRQ_status	  : 1;
};

union UnEmbSerialACT155IRQ
{
	EmbSerialACT155IRQ bit;
	unsigned char byte;
};

struct EmbSerialACT155Status
{
  int SynMod				: 1;
  int BAMod					: 1;
  int AISMod				: 1;
  int reserv				: 1;
  int SynTrans		  : 1;
  int BATrans				: 1;
  int AISTrans			: 1;
  int LosTransFrequ	: 1;
};

union UnEmbSerialACT155Status
{
	EmbSerialACT155Status bit;
	unsigned char byte;
};

class EmbSerialACT155 : public EmbIsrINT1
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffPower;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffPower;
  public:
		unsigned long count;

		void Init(); 
		void Empty() 
		{ 
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
			m_RBuffPower.Init(); 
			m_TBuffPower.Init(); 
		}
 	  unsigned UsedSendMod() { return m_TBuffMod.Used(); }
		unsigned UsedMod() { return m_RBuffMod.Used(); }
 	  unsigned UsedSendTransit() { return m_TBuffTransit.Used(); }
		unsigned UsedTransit() { return m_RBuffTransit.Used(); }
 	  unsigned UsedTransPower() { return m_TBuffPower.Used(); }
		unsigned UsedPower() { return m_RBuffPower.Used(); }

 	  void AddMod(unsigned char byte);
		unsigned char GetMod() { return m_RBuffMod.Get(); }
 	  void AddTransit(unsigned char byte);
		unsigned char GetTransit() { return m_RBuffTransit.Get(); }
 	  void AddPower(unsigned char byte);
		unsigned char GetPower() { return m_RBuffPower.Get(); }

    void IsrXX();
};

#endif

#ifdef IncEmbSerialMD34

struct EmbSerialMD34IRQ
{
  int IRQ_RX_mod		: 1;
  int IRQ_TX_mod		: 1;
  int IRQ_RX_trans	: 1;
  int IRQ_TX_trans  : 1;
  int IRQ_RX_power  : 1;
  int IRQ_TX_power	: 1;
  int reserv			  : 1;
  int IRQ_status	  : 1;
};

union UnEmbSerialMD34IRQ
{
	EmbSerialMD34IRQ bit;
	unsigned char byte;
};

struct EmbSerialMD34Status
{
  int SynMod				: 1;
  int BAMod					: 1;
  int AISMod				: 1;
  int reserv				: 1;
  int SynTrans		  : 1;
  int BATrans				: 1;
  int AISTrans			: 1;
  int LosTransFrequ	: 1;
};

union UnEmbSerialMD34Status
{
	EmbSerialMD34Status bit;
	unsigned char byte;
};

class EmbSerialMD34 : public EmbIsrINT3
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffTransit;
  public:
		unsigned long count;

		void Init(); 
		void Empty() 
		{ 
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
		}
 	  unsigned UsedSendMod() { return m_TBuffMod.Used(); }
		unsigned UsedMod() { return m_RBuffMod.Used(); }
 	  unsigned UsedSendTransit() { return m_TBuffTransit.Used(); }
		unsigned UsedTransit() { return m_RBuffTransit.Used(); }

 	  void AddMod(unsigned char byte);
		unsigned char GetMod() { return m_RBuffMod.Get(); }
 	  void AddTransit(unsigned char byte);
		unsigned char GetTransit() { return m_RBuffTransit.Get(); }

    void IsrXX();
};

#endif

#ifdef IncEmbSerialMD2

struct EmbSerialMD2IRQ
{
  int IRQ_RX_mod		: 1;
  int IRQ_TX_mod		: 1;
  int IRQ_RX_trans	: 1;
  int IRQ_TX_trans  : 1;
  int IRQ_RX_power  : 1;
  int IRQ_TX_power	: 1;
  int reserv			  : 1;
  int IRQ_status	  : 1;
};

union UnEmbSerialMD2IRQ
{
	EmbSerialMD2IRQ bit;
	unsigned char byte;
};

struct EmbSerialMD2Status
{
  int SynMod				: 1;
  int BAMod					: 1;
  int AISMod				: 1;
  int reserv				: 1;
  int SynTrans		  : 1;
  int BATrans				: 1;
  int AISTrans			: 1;
  int LosTransFrequ	: 1;
};

union UnEmbSerialMD2Status
{
	EmbSerialMD2Status bit;
	unsigned char byte;
};

class EmbSerialMD2 : public EmbIsrINT1
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffTransit;
  public:
		unsigned long count;

		void Init(); 
		void Empty() 
		{ 
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
		}
 	  unsigned UsedSendMod() { return m_TBuffMod.Used(); }
		unsigned UsedMod() { return m_RBuffMod.Used(); }
 	  unsigned UsedSendTransit() { return m_TBuffTransit.Used(); }
		unsigned UsedTransit() { return m_RBuffTransit.Used(); }

 	  void AddMod(unsigned char byte);
		unsigned char GetMod() { return m_RBuffMod.Get(); }
 	  void AddTransit(unsigned char byte);
		unsigned char GetTransit() { return m_RBuffTransit.Get(); }

    void IsrXX();
};

#endif

#ifdef IncEmbSerialPU_M

struct EmbSerialPU_MIRQ
{
  int IRQ_RX_mod		: 1;
  int IRQ_TX_mod		: 1;
  int IRQ_RX_trans	: 1;
  int IRQ_TX_trans  : 1;
  int IRQ_RX_UD1		: 1;
  int IRQ_TX_UD1		: 1;
  int IRQ_RX_UD2		: 1;
  int IRQ_TX_UD2	  : 1;
};

union UnEmbSerialPU_MIRQ
{
	EmbSerialPU_MIRQ bit;
	unsigned char byte;
};

struct EmbSerialPU_MStatus
{
  int SynMod				: 1;
  int BAMod					: 1;
  int AISMod				: 1;
  int reserv				: 1;
  int SynTrans		  : 1;
  int BATrans				: 1;
  int AISTrans			: 1;
  int LosTransFrequ	: 1;
};

union UnEmbSerialPU_MStatus
{
	EmbSerialPU_MStatus bit;
	unsigned char byte;
};

class EmbSerialPU_M : public EmbIsrINT1
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffTransit;
		TRBuffer<char,UPD_BUFFER_SIZE> m_RBuffUD1;
		TRBuffer<char,UPD_BUFFER_SIZE> m_TBuffUD1;
		TRBuffer<char,UPD_BUFFER_SIZE> m_RBuffUD2;
		TRBuffer<char,UPD_BUFFER_SIZE> m_TBuffUD2;
  public:
		unsigned long count;

		void Init(); 
		void Empty() 
		{ 
//			Disable();
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
			m_RBuffUD1.Init(); 
			m_TBuffUD1.Init(); 
			m_RBuffUD2.Init(); 
			m_TBuffUD2.Init(); 
//			Enable();
		}
		
		void EmptyMod() 
		{ 
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
		}

		void EmptyTransit() 
		{ 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
		}

		void EmptyUD1() 
		{ 
			m_RBuffUD1.Init(); 
			m_TBuffUD1.Init(); 
		}

		void EmptyUD2() 
		{ 
			m_RBuffUD2.Init(); 
			m_TBuffUD2.Init(); 
		}

 	  unsigned UsedSendMod() { return m_TBuffMod.Used(); }
		unsigned UsedSendFree() { return  m_TBuffMod.Free(); }
		unsigned UsedMod() { return m_RBuffMod.Used(); }
 	  unsigned UsedSendTransit() { return m_TBuffTransit.Used(); }
		unsigned UsedTransit() { return m_RBuffTransit.Used(); }
 	  unsigned UsedSendUD1() { return m_TBuffUD1.Used(); }
		unsigned UsedUD1() { return m_RBuffUD1.Used(); }
 	  unsigned UsedSendUD2() { return m_TBuffUD2.Used(); }
		unsigned UsedUD2() { return m_RBuffUD2.Used(); }

 	  void AddMod(unsigned char byte);
		unsigned char GetMod() { return m_RBuffMod.Get(); }
 	  void AddTransit(unsigned char byte);
		unsigned char GetTransit() { return m_RBuffTransit.Get(); }
 	  void AddUD1(unsigned char byte);
		unsigned char GetUD1() { return m_RBuffUD1.Get(); }
 	  void AddUD2(unsigned char byte);
		unsigned char GetUD2() { return m_RBuffUD2.Get(); }

    void IsrXX();
};

#endif

#ifdef IncEmbSerialMD34AVT

struct EmbSerialMD34IRQ
{
  int IRQ_RX_mod		: 1;
  int IRQ_TX_mod		: 1;
  int IRQ_RX_trans	: 1;
  int IRQ_TX_trans  : 1;
  int IRQ_RX_power  : 1;
  int IRQ_TX_power	: 1;
  int reserv			  : 1;
  int IRQ_status	  : 1;
};

union UnEmbSerialMD34IRQ
{
	EmbSerialMD34IRQ bit;
	unsigned char byte;
};

struct EmbSerialMD34Status
{
  int SynMod				: 1;
  int BAMod					: 1;
  int AISMod				: 1;
  int reserv				: 1;
  int SynTrans		  : 1;
  int BATrans				: 1;
  int AISTrans			: 1;
  int LosTransFrequ	: 1;
};

union UnEmbSerialMD34Status
{
	EmbSerialMD34Status bit;
	unsigned char byte;
};

class EmbSerialMD34AVT : public EmbIsrINT1
{
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffMod;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffTransit;
		TRBuffer<char,ACT_BUFFER_SIZE> m_RBuffPower;
		TRBuffer<char,ACT_BUFFER_SIZE> m_TBuffPower;
  public:
		unsigned long count;

		void Init(); 
		void Empty() 
		{ 
			m_RBuffMod.Init(); 
			m_TBuffMod.Init(); 
			m_RBuffTransit.Init(); 
			m_TBuffTransit.Init(); 
			m_RBuffPower.Init(); 
			m_TBuffPower.Init(); 
		}
 	  unsigned UsedSendMod() { return m_TBuffMod.Used(); }
		unsigned UsedMod() { return m_RBuffMod.Used(); }
 	  unsigned UsedSendTransit() { return m_TBuffTransit.Used(); }
		unsigned UsedTransit() { return m_RBuffTransit.Used(); }

 	  unsigned UsedSendPower() { return m_TBuffPower.Used(); }
		unsigned UsedPower() { return m_RBuffPower.Used(); }

 	  void AddMod(unsigned char byte);
		unsigned char GetMod() { return m_RBuffMod.Get(); }
 	  void AddTransit(unsigned char byte);
		unsigned char GetTransit() { return m_RBuffTransit.Get(); }
 	  void AddPower(unsigned char byte);
		unsigned char GetPower() { return m_RBuffPower.Get(); }

    void IsrXX();
};

#endif

	