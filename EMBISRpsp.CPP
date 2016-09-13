#include <dos.h>
//#include <stdio.h>
#include "embisr.h"
#include "amd_pcb.h"

////////////////////////////////////////////////////////////////
static int nint[17] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
static EmbIsr *comarray[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
static sss=0;
static ttt=0;

#define isr(n,isrn)						\
static void isrn(...)					\
{															\
  asm { pusha; }							\
  if(comarray[n]!=NULL)				\
  {														\
    comarray[n]->IsrXX();			\
	}														\
	asm { popa; pop bp; iret; }	\
}

isr(1,isr1)
isr(2,isr2)
isr(3,isr3)
isr(4,isr4)
isr(5,isr5)
isr(6,isr6)
isr(7,isr7)
isr(8,isr8)
isr(9,isr9)
isr(10,isr10)
isr(11,isr11)
isr(12,isr12)
isr(13,isr13)
isr(14,isr14)
isr(15,isr15)
isr(16,isr16)

static void (* isr_tab [17]) (...) =
  { NULL,isr1,isr2,isr3,isr4,isr5,isr6,isr7,isr8,isr9,isr10,isr11,isr12,isr13,isr14,isr15,isr16 };
///////////////////////////////////////////////////////////////////
template<class T,int Size> void TRBuffer<T,Size>::Init()
{
  BuffSize = Size;
  Head = 0;
  Tail = 0;
}

template<class T,int Size> void TRBuffer<T,Size>::Add(T elem)
{
//	asm { cli } 
  Buff[Head++] = elem;
  if(Head == BuffSize) Head = 0;
//	asm { sti } 
}

template<class T,int Size> T TRBuffer<T,Size>::Get()
{
//	asm { cli } 
  if(++Tail < BuffSize) return Buff[Tail-1];
  Tail = 0;
  return Buff[BuffSize-1];
//	asm { sti } 
}

template<class T,int Size> unsigned TRBuffer<T,Size>::Used()
{
//	asm { cli } 
  int n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
//	asm { sti } 
}

template<class T,int Size> unsigned TRBuffer<T,Size>::Free()
{
//	asm { cli } 
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
//	asm { sti } 
}

/////////////////////////////////////////////////////////////////
void SetVect(int num, int irq, void (*isr)(...))
{
	nint[num]=irq;
	unsigned long *vect_ptr;
	vect_ptr = (unsigned long*)(irq*4);
	*vect_ptr = (unsigned long)isr;
}

int EmbIsr::num=0;

void EmbIsr::InitIRQ(int irq)
{
	num++;
  SetVect(num, irq, isr_tab[num]);
//  SetVect(irq, irq, isr_tab[irq]);
  comarray[num] = this;
}

////////////////////////////  RSCOM  ////////////////////////////
void EmbCOM::IsrXX()
{
}

int EmbCOM::Init(unsigned /*rate*/)//Init(int comN,unsigned rate,char par)
{
	return 0;
}

unsigned char EmbCOM::Receive()
{
	return rcvbuf.Get();
}

////////////////////////////  RS232  ////////////////////////////
#ifdef IncEmbRS232

void EmbRS232::IsrXX()
{
	unsigned char ch,c;
  asm { cli } 
	ch = (unsigned char)(inport(s1cnt+sStatus));	// Чтение статуса канала 1 
	if( ch & 0x10 )					// Прерывание по приему
	{
		rcvbuf.Add((unsigned char)(inport(s1cnt+sReceive)));
	}
	if( ch & 0x20 )								// Прерывание по передаче
	{
		if(trsbuf.Used())						// Если есть чего на передачу
		{
//			outport(s1cnt,sMode);
			outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
			outport(s1cnt+sTransmit,(unsigned int)(trsbuf.Get())); // Если есть чего, то пишем в порт
		}
		else
		{
//			outport(s1cnt,sMode);
			outport(s1cnt,sMode|sRxen|sRxie|sTxen);
			state = 0;
		}
	}
	outport(0xff22,0x0014);						
  asm { sti } 
}

void EmbRS232::Trans(unsigned char ch)
{
  asm { cli } 
	trsbuf.Add(ch);
	if(!state)
	{
//		outport(s1cnt,sMode);
		outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
		state = 1;
	}
  asm { sti } 
};

void EmbRS232::TransInit()
{
	if(!state)
	{
//		outport(s1cnt,sMode);
		outport(s1cnt,sMode|sTxen|sTxie|sRxen|sRxie);
		if(trsbuf.Used()) outport(s1cnt+sTransmit,(unsigned int)(trsbuf.Get())); // Если есть чего, то пишем в порт
		else outport(s1cnt+sTransmit,0x00FF); // Если нет ничего то пишем всякую лабуду

//		inportb(s1cnt+sReceive);
		state = 1;
	}
};

int EmbRS232::Init(unsigned rate)//Init(int comN,unsigned rate,char par)
{
	unsigned int bauddiv,c;
	rcvbuf.Init();
	trsbuf.Init();
	state = 0;
	switch(rate)
	{
//		case 3:    bauddiv=8333; break;  //4.800
//		case 48:   bauddiv=520;  break;  //4.800
//		case 96:   bauddiv=260;  break;  //9.600
//		case 192:  bauddiv=130;  break;  //19.200
		case 384:  bauddiv=25;   break;  //38.400
//		case 576:  bauddiv=43;   break;  //57.600
//		case 1152: bauddiv=22;           //115.200
	}
	con=sMode;  // set mode
	
	int port=s1cnt;
	EmbIsr::InitIRQ(0x14);
	outport(s1con,0x0010);
	c=inport(imask);
	outport(imask,c&0xfbff);

	outport(port+8,bauddiv);
	inport(port+sReceive);
	inport(port+sReceive);
	inport(port+sReceive);
	inport(port+sStatus);
	inport(port+sStatus);
	outport(port,con);
	outport(port,con|sRxen|sRxie);

	return 0;
}

#endif
///////////////////////////   T i m e r   /////////////////////////////
#ifdef IncEmbTimer

void EmbTimer::IsrXX()
{
	asm{ sti }
	ttt++;
	if(embTimerCallback0) 
	{ 
		embTimerCallback0->count++; 
		if(embTimerCallback0->count>=embTimerCallback0->interval) 
		{ 
			embTimerCallback0->count = 0; 
			(*embTimerCallback0->callback)(); 
		}
	}
	if(embTimerCallback1) 
	{ 
		embTimerCallback1->count++; 
		if(embTimerCallback1->count>=embTimerCallback1->interval) 
		{ 
			embTimerCallback1->count = 0; 
			(*embTimerCallback1->callback)(); 
		}
	}
	if(embTimerCallback2) 
	{ 
		embTimerCallback2->count++; 
		if(embTimerCallback2->count>=embTimerCallback2->interval) 
		{ 
			embTimerCallback2->count = 0; 
			(*embTimerCallback2->callback)(); 
		}
	}
	if(embTimerCallback3) 
	{ 
		embTimerCallback3->count++; 
		if(embTimerCallback3->count>=embTimerCallback3->interval) 
		{ 
			embTimerCallback3->count = 0; 
			(*embTimerCallback3->callback)(); 
		}
	}
	if(embTimerCallback4) 
	{ 
		embTimerCallback4->count++; 
		if(embTimerCallback4->count>=embTimerCallback4->interval) 
		{ 
			embTimerCallback4->count = 0; 
			(*embTimerCallback4->callback)(); 
		}
	}
  outport(t2con,0x2001);
	outport(0xff22,0x0008);						
}

int EmbTimer::Init(int ms)//Init(int comN,unsigned rate,char par)
{
	unsigned c;
	embTimerCallback0 = 0;
	embTimerCallback1 = 0;
	embTimerCallback2 = 0;
	embTimerCallback3 = 0;
	embTimerCallback4 = 0;
///
	outport(t0con,0x4000);
	outport(t1con,0x4000);

  outport(t2con,0x6001);
	outport(t2cnt,0x0000);
///
	outport(t2cmpa,800*ms); 
	outport(t2con,0xe001);

	EmbIsr::InitIRQ(0x13);
	c=inport(imask);
	outport(imask,c&0xfffe);
///
	outport(tcucon,0x0000);
///
	return 0;
}

void EmbTimer::SetCallBack0(EmbTimerCallback *e) { embTimerCallback0 = e; }
void EmbTimer::SetCallBack1(EmbTimerCallback *e) { embTimerCallback1 = e; }
void EmbTimer::SetCallBack2(EmbTimerCallback *e) { embTimerCallback2 = e; }
void EmbTimer::SetCallBack3(EmbTimerCallback *e) { embTimerCallback3 = e; }
void EmbTimer::SetCallBack4(EmbTimerCallback *e) { embTimerCallback4 = e; }

#endif
///////////////////////////////////////////////////////////////////////
//////////////////////////       N M I      ///////////////////////////
///////////////////////////////////////////////////////////////////////
#ifdef IncNMI

int EmbNMI0::Init() { EmbIsr::InitIRQ(0x00); return 0; }
void EmbNMI0::IsrXX() {  }
int EmbNMI1::Init() { EmbIsr::InitIRQ(0x01); return 0; }
void EmbNMI1::IsrXX() {  }
int EmbNMI2::Init() { EmbIsr::InitIRQ(0x02); return 0; }
void EmbNMI2::IsrXX() {  }
int EmbNMI3::Init() { EmbIsr::InitIRQ(0x03); return 0; }
void EmbNMI3::IsrXX() {  }
int EmbNMI4::Init() { EmbIsr::InitIRQ(0x04); return 0; }
void EmbNMI4::IsrXX() {  }
int EmbNMI5::Init() { EmbIsr::InitIRQ(0x05); return 0; }
void EmbNMI5::IsrXX() {  }
int EmbNMI6::Init() { EmbIsr::InitIRQ(0x06); return 0; }
void EmbNMI6::IsrXX() {  }

#endif
///////////////////////////////////////////////////////////////////////
////////////                  Indicator                  //////////////
///////////////////////////////////////////////////////////////////////
#ifdef IncEmbIndicator

int EmbIndicator::Init()
{
	unsigned long i;
	unsigned char c;
	EmbIsr::InitIRQ(INDICATOR_IRQ);	// Устанавливаем вектор обработчика прерываний	
	
	outportb(INDICATOR_CTRL,0x48);		// Сброс
	for(i=0; i<20000; i++);
	outportb(INDICATOR_CTRL,0x32);
	for(i=0; i<20000; i++);

	m_RBuff.Init();
	m_TBuff.Init();
	r_state = 0;

	outport(i2con,0x0017);    
	c=inport(imask);              // Маска перываний - чтение (???)
	outport(imask,c&0xffbf);			// Ввод маски прерываний (???)
//	outport(pacs,0x0079);
//	outport(mpcs,0x81bf);

	eic.byte = 0; //inportb(INDICATOR_CTRL);
	eic.bit.dirCTS = 0;
	eic.bit.IRQ_receive = 1;
	eic.bit.IRQ_trans = 0;
	eic.bit.receive = 1;
	eic.bit.trans = 1;
	outportb(INDICATOR_CTRL,eic.byte);

	return 0;	
}

void EmbIndicator::Cursor(char mode,unsigned char addr)
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('C');
		m_TBuff.Add(addr);
		m_TBuff.Add(mode);
  }
}
void EmbIndicator::Reset()
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
		m_TBuff.Add('U');
  }
}
void EmbIndicator::SetStr0(char *str) 
{
	if(m_TBuff.Free())
	{
		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		m_TBuff.Add('U');
		m_TBuff.Add('I');
		m_TBuff.Add(0x80);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) m_TBuff.Add(s[i]);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::SetStr1(char *str) 
{
	if(m_TBuff.Free())
	{
		int i=0;
		char s[24]; 
		for(i=0; i<24; i++) s[i]=' ';
		m_TBuff.Add('U');
		m_TBuff.Add('I');
		m_TBuff.Add(0xC0);
		i=0;
    while(str[i])
		{
			s[i]=str[i++];
			if(i>24) break;
		}
		for(i=0; i<24; i++) m_TBuff.Add(s[i]);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::SetLtDiod(char mode,char number) 
{
	EmbIndCtrl eic;
//	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('L');
		m_TBuff.Add((mode<<4)+number);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::Sound0(char frequ)
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x00);
		m_TBuff.Add(frequ);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}

void EmbIndicator::SoundAlarm()
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x24);
		m_TBuff.Add(0x0A);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x07);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x04);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x02);
		m_TBuff.Add(0x01);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}

void EmbIndicator::SoundRing()
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add(0x22);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x01);
		m_TBuff.Add(0x02);
		m_TBuff.Add(0x01);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}

void EmbIndicator::Sound1(char mode,EmbSound s1) 
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::Sound2(char mode,EmbSound s1,EmbSound s2) 
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::Sound3(char mode,EmbSound s1,EmbSound s2,EmbSound s3) 
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		m_TBuff.Add(s3.frequ);
		m_TBuff.Add((s3.pause<<4)+s3.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}
void EmbIndicator::Sound4(char mode,EmbSound s1,EmbSound s2,EmbSound s3,EmbSound s4) 
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('S');
		m_TBuff.Add((mode<<4)+0x01);
		m_TBuff.Add(s1.frequ);
		m_TBuff.Add((s1.pause<<4)+s1.sound);
		m_TBuff.Add(s2.frequ);
		m_TBuff.Add((s2.pause<<4)+s2.sound);
		m_TBuff.Add(s3.frequ);
		m_TBuff.Add((s3.pause<<4)+s3.sound);
		m_TBuff.Add(s4.frequ);
		m_TBuff.Add((s4.pause<<4)+s4.sound);
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}

void EmbIndicator::Receipt()
{
	if(m_TBuff.Free())
	{
		m_TBuff.Add('U');
		m_TBuff.Add('N');
		EmbIndCtrl eic;
		eic.byte = 0; //inportb(INDICATOR_CTRL);
		eic.bit.dirCTS = 0;
		eic.bit.IRQ_receive = 1;
		eic.bit.IRQ_trans = 1;
		eic.bit.receive = 1;
		eic.bit.trans = 1;
		outportb(INDICATOR_CTRL,eic.byte);
  }
}

void EmbIndicator::IsrXX()
{
//	sss = m_TBuff.Used();
	asm{ sti }
	EmbIndCtrl eic;
	eic.byte = inportb(INDICATOR_CTRL);	// Чтение статуса канала 1 

	if(eic.bit.IRQ_receive)								// Прерывание по приему
	{
		char ch = inportb(INDICATOR_DATA);
		//if(ch=='U') r_state=1;
		//else
		{
			m_RBuff.Add(ch); 
			//r_state = 0; 
		}
	}
	if(eic.bit.IRQ_trans)								// Прерывание по передаче
//	if(eic.byte&0x01)								// Прерывание по передаче
	{
	  if(m_TBuff.Used()) 
		{
			outportb(INDICATOR_DATA,m_TBuff.Get());
		}
		else 
		{
			eic.byte = 0; //inportb(INDICATOR_CTRL);
			eic.bit.dirCTS = 0;
			eic.bit.IRQ_receive = 1;
			eic.bit.IRQ_trans = 0;
			eic.bit.receive = 1;
			eic.bit.trans = 1;
			outportb(INDICATOR_CTRL,eic.byte);
		}
	}
	outport(0xff22,0x000e);						
}
#endif
////////////////////////////  RS485  ////////////////////////////
#ifdef IncEmbRS485

void EmbRS485::IsrXX()
{
	asm{ sti }
  Emb485Bit eic;
	eic.byte = inportb(RS485_CTRL);	// Чтение статуса канала 1 

	if(eic.bit.IRQ_receive)								// Прерывание по приему
	{
		char ch = inportb(RS485_DATA);
		rcvbuf.Add(ch); 
	}
	if(inport(piodat0)&0x0400)//eic.bit.IRQ_trans)								// Прерывание по передаче
	  if(trsbuf.Used()) 
		{
			outportb(RS485_DATA,trsbuf.Get());
		}
		else 
		{
			eic.byte = 0; //inportb(INDICATOR_CTRL);
			eic.bit.IRQ_receive = 1;
			eic.bit.IRQ_trans = 0;
			eic.bit.receive = 1;
			eic.bit.trans = 0;
			outportb(RS485_CTRL,eic.byte);
      outport(piodat0,inport(piodat0)&0xFBFF);    
		}
	outport(0xff22,0x0010);						
}

void EmbRS485::Trans(unsigned char ch)
{
  asm{ cli }
	trsbuf.Add(ch);
  Emb485Bit eic;
	eic.byte = 0; //inportb(INDICATOR_CTRL);
	eic.bit.IRQ_receive = 0;
	eic.bit.IRQ_trans = 1;
	eic.bit.receive = 0;
	eic.bit.trans = 1;
	outportb(RS485_CTRL,eic.byte);
  outport(piodat0,inport(piodat0)|0x400);   
  asm{ sti }
	for(int i=0; i<100; i++);
};

int EmbRS485::Init(unsigned rate)//Init(int comN,unsigned rate,char par)
{
	unsigned int bauddiv,c,i;
	EmbIsr::InitIRQ(RS485_IRQ);	
  rcvbuf.Init();
	trsbuf.Init();
	state = 0;

//  outportb(RS485_CTRL,0x08);		// Сброс
//	for(i=0; i<20000; i++);
//	outportb(RS485_CTRL,0x32);
//	for(i=0; i<20000; i++);
  
	outport(i4con,0x0016);    
	c=inport(imask);              // Маска перываний - чтение (???)
	outport(imask,c&0xfeff);			// Ввод маски прерываний (???)

  Emb485Bit eic;
  eic.byte = 0; //inportb(INDICATOR_CTRL);
	eic.bit.IRQ_receive = 1;
	eic.bit.IRQ_trans = 0;
	eic.bit.receive = 1;
	eic.bit.trans = 1;
  outportb(RS485_CTRL,eic.byte);
//  outportb(RS485_CTRL,0);
	return 0;
}

#endif 
////////////////////////////////////////////////////////////////////
////////////             Real Time Clock              //////////////
////////////////////////////////////////////////////////////////////
void EmbRTClock::Init()
{

}        

void EmbRTClock::StartClock()
{

}

void EmbRTClock::SetTimeDate(RTUnion */*r*/)
{

}

void EmbRTClock::GetTimeDate(RTUnion */*r*/)
{

}

char *EmbRTClock::GetTimeDateStr(char *str)
{

	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
	*ctrl = 0x40;
	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.year>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.year&0x0F)+'0';
  str[2]='/';
  str[3]=((ru->rt_time.mon>>4)&0x01)+'0';
  str[4]=(ru->rt_time.mon&0x0F)+'0';
  str[5]='/';
  str[6]=((ru->rt_time.date>>4)&0x03)+'0';
  str[7]=(ru->rt_time.date&0x0F)+'0';
  str[8]=' ';
  str[9]=((ru->rt_time.hour>>4)&0x0F)+'0';
  str[10]=(ru->rt_time.hour&0x0F)+'0';
  str[11]=':';
  str[12]=((ru->rt_time.min>>4)&0x0F)+'0';
  str[13]=(ru->rt_time.min&0x0F)+'0';
  str[14]=':';
  str[15]=((ru->rt_time.sec>>4)&0x0F)+'0';
  str[16]=(ru->rt_time.sec&0x0F)+'0';
  str[17]=0;
	*ctrl = 0x00;
	return str;
}

char *EmbRTClock::GetTimeStr(char *str)
{

	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
	*ctrl = 0x40;
	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.hour>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.hour&0x0F)+'0';
  str[2]=':';
  str[3]=((ru->rt_time.min>>4)&0x0F)+'0';
  str[4]=(ru->rt_time.min&0x0F)+'0';
  str[5]=':';
  str[6]=((ru->rt_time.sec>>4)&0x0F)+'0';
  str[7]=(ru->rt_time.sec&0x0F)+'0';
  str[8]=0;
	*ctrl = 0x00;
	return str;
}

char *EmbRTClock::GetDateStr(char *str)
{

	unsigned char far *ctrl;
	ctrl = (unsigned char far*)0x80001FF8;
	*ctrl = 0x40;
	RTUnion far *ru;
	ru = (RTUnion far *)0x80001FF8;
  str[0]=((ru->rt_time.year>>4)&0x0F)+'0';
  str[1]=(ru->rt_time.year&0x0F)+'0';
  str[2]='/';
  str[3]=((ru->rt_time.mon>>4)&0x01)+'0';
  str[4]=(ru->rt_time.mon&0x0F)+'0';
  str[5]='/';
  str[6]=((ru->rt_time.date>>4)&0x03)+'0';
  str[7]=(ru->rt_time.date&0x0F)+'0';
  str[8]=0;
	*ctrl = 0x00;
	return str;
}
///////////////////////////////////////////////////////////////////////
////////////                Used Interrupts              //////////////
///////////////////////////////////////////////////////////////////////
unsigned long irq0=0;
unsigned long irq1=0;
unsigned long irq4=0;
unsigned long err0=0;
unsigned long err1=0;
unsigned long err4=0;
unsigned char signal=0;

void EmbIsrINT0::Init() 
{ 
	EmbIsr::InitIRQ(0x0C); 
	outport(i0con,0x0010);    // 0-регистр управления (разрешения) прерываниями
	unsigned c=inport(imask); // Маска перываний - чтение (???)
	outport(imask,c&0xffef);	// Ввод маски прерываний (???)
}
void EmbIsrINT0::EOI() { outport(0xff22,0x000C); }
void EmbIsrINT0::IsrXX() 
{
	EOI();
}

void EmbIsrINT1::Init() 
{ 
	EmbIsr::InitIRQ(0x0D); 
	outport(i1con,0x0015);        // управления (разрешения) прерываниями
	unsigned c=inport(imask);     // Маска перываний - чтение (???)
	outport(imask,c&0xffdf);			// Ввод маски прерываний (???)
}
void EmbIsrINT1::EOI() { outport(0xff22,0x000D); }
void EmbIsrINT1::IsrXX() 
{
  EOI();
}

#ifdef IncEmbSerialACT155

void EmbSerialACT155::IsrXX() 
{
	UnEmbSerialACT155Status status;
	UnEmbSerialACT155IRQ irq,mask;

	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x5A5);
	mask.byte = inportb(0x5A6);

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x5A7,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x5A9,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;
	if(irq.bit.IRQ_TX_power) if(m_TBuffPower.Used()) { outportb(0x5AB,m_TBuffPower.Get());	if(m_TBuffPower.Used()) mask.bit.IRQ_TX_power=0; } else mask.bit.IRQ_TX_power=0;

	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x5A7)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x5A9)); 
	if(irq.bit.IRQ_RX_power) m_RBuffPower.Add(inportb(0x5AB)); 

	outportb(0x5A6,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
	count++;
	EmbIsrINT1::EOI();
}


void EmbSerialACT155::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	m_RBuffPower.Init(); 
	m_TBuffPower.Init(); 
	UnEmbSerialACT155IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
//	mask.bit.IRQ_RX_power=1;
	outportb(0x5A6,mask.byte);
} 


void EmbSerialACT155::AddMod(unsigned char byte)
{ 
	m_TBuffMod.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x5A6,mask.byte);

}
void EmbSerialACT155::AddTransit(unsigned char byte)
{ 
	m_TBuffTransit.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x5A6,mask.byte);

}
void EmbSerialACT155::AddPower(unsigned char byte)
{ 
	m_TBuffPower.Add(byte); 	
	UnEmbSerialACT155IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x5A6,mask.byte);

}

#endif

void EmbIsrINT2::Init() { EmbIsr::InitIRQ(0x0E); }
void EmbIsrINT2::EOI() { outport(0xff22,0x000E); }
void EmbIsrINT2::IsrXX() {}
void EmbIsrINT3::Init() 
{ 
	EmbIsr::InitIRQ(0x0F); 
	outport(i3con,0x0015);        // управления (разрешения) прерываниями
	unsigned c=inport(imask);     // Маска перываний - чтение (???)
	outport(imask,c&0xff7f);			// Ввод маски прерываний (???)
}
void EmbIsrINT3::EOI() { outport(0xff22,0x000F); }
void EmbIsrINT3::IsrXX() {}
void EmbIsrINT4::Init() 
{ 
	EmbIsr::InitIRQ(0x10); 
	outport(i4con,0x0015);        // управления (разрешения) прерываниями
	unsigned c=inport(imask);     // Маска перываний - чтение (???)
	outport(imask,c&0xfeff);			// Ввод маски прерываний (???)
}
void EmbIsrINT4::EOI() 
{ 
	outport(0xff22,0x0010); 
}
void EmbIsrINT4::IsrXX() 
{
	EOI();
}

#ifdef IncEmbSerialACT8

void EmbSerialACT8Receive::IsrXX()
{
	m_RBuff.Add(inportb(0x602)); 
  EOI();
}

void EmbSerialACT8Receive::ReceiveInit()
{
  EmbIsrINT0::Init();
}

void EmbSerialACT8Send::IsrXX()
{
  if(m_TBuff.Used()) outportb(0x602,m_TBuff.Get());
	else 
	{
   	outport(i1con,0x0018);        // управления (разрешения) прерываниями
//		unsigned c=inport(imask);
//		outport(imask,c|0x0020);
	}
	EmbIsrINT1::EOI();
}

void EmbSerialACT8Send::Init() 
{ 
	EmbIsrINT1::Init(); 
	m_TBuff.Init();
} 

void EmbSerialACT8Send::Add(unsigned char byte) 
{ 
	m_TBuff.Add(byte); 
	outport(i1con,0x0015);        // управления (разрешения) прерываниями
}

void EmbSerialACT8Send::TransInit() 
{ 
	outport(i1con,0x0015);        // управления (разрешения) прерываниями
}

void EmbSerialACT8Control::IsrXX()
{
  busy = 0;
	EOI();
}

#endif

#ifdef IncEmbSerialMD34

void EmbSerialMD34::IsrXX() 
{
//	UnEmbSerialMD34Status status;
	UnEmbSerialMD34IRQ irq,mask;
//	asm { cli } 

	irq.byte  = inportb(0x515);
	mask.byte = inportb(0x516);
//	status.byte = inportb(0x514);
	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x517)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x519)); 

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x517,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x519,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;
	outportb(0x516,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
//	count++;
	EmbIsrINT3::EOI();
//	asm { sti } 
}


void EmbSerialMD34::Init() 
{ 
	count=0;
	EmbIsrINT3::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	UnEmbSerialMD34IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	outportb(0x516,mask.byte);
} 

void EmbSerialMD34::AddMod(unsigned char byte)
{ 
	m_TBuffMod.Add(byte); 	
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x516);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x516,mask.byte);

}
void EmbSerialMD34::AddTransit(unsigned char byte)
{	
	m_TBuffTransit.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x516);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x516,mask.byte);
}

#endif

#ifdef IncEmbSerialMD2

void EmbSerialMD2::IsrXX() 
{
//	UnEmbSerialMD2Status status;
	UnEmbSerialMD2IRQ irq,mask;

//	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x5A5);
	mask.byte = inportb(0x5A6);

	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x5A7)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x5A9)); 

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x5A7,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x5A9,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;

	outportb(0x5A6,mask.byte);

	count++;
	EmbIsrINT1::EOI();
}


void EmbSerialMD2::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	outportb(0x5A6,mask.byte);
} 

void EmbSerialMD2::AddMod(unsigned char byte)
{ 
//	asm { cli }
	m_TBuffMod.Add(byte); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x5A6,mask.byte);
//	asm { sti }
}
void EmbSerialMD2::AddTransit(unsigned char byte)
{ 
//	asm { cli }
	m_TBuffTransit.Add(byte); 
	UnEmbSerialMD2IRQ mask;
	mask.byte = inportb(0x5A6);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x5A6,mask.byte);
//	asm { sti }
}

#endif

#ifdef IncEmbSerialPU_M

void EmbSerialPU_M::IsrXX() 
{
		asm { cli } 
//	UnEmbSerialPU_MStatus status;
	UnEmbSerialPU_MIRQ irq,mask;

//	status.byte = inportb(0x5A4);
	irq.byte  = inportb(0x505);
	mask.byte = inportb(0x506);

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x507,m_TBuffMod.Get());	if(!m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x509,m_TBuffTransit.Get());	if(!m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;
	if(irq.bit.IRQ_TX_UD1) if(m_TBuffUD1.Used()) { outportb(0x50B,m_TBuffUD1.Get());	if(!m_TBuffUD1.Used()) mask.bit.IRQ_TX_UD1=0; } else mask.bit.IRQ_TX_UD1=0;
//	if(irq.bit.IRQ_TX_UD2) if(m_TBuffUD2.Used()) { outportb(0x50D,m_TBuffUD2.Get());	if(!m_TBuffUD2.Used()) mask.bit.IRQ_TX_UD2=0; } else mask.bit.IRQ_TX_UD2=0;

	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x507)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x509)); 
	if(irq.bit.IRQ_RX_UD1) m_RBuffUD1.Add(inportb(0x50B)); 
//	if(irq.bit.IRQ_RX_UD2) m_RBuffUD2.Add(inportb(0x50D)); 

	outportb(0x506,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
	count++;
	EmbIsrINT1::EOI();
	asm { sti } 
}


void EmbSerialPU_M::Init() 
{ 
	asm { cli } 
	count=0;
	Empty(); 
	EmbIsrINT1::Init(); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = 0;//inportb(0x5A6);
//	mask.bit.IRQ_RX_mod=1;
//	mask.bit.IRQ_RX_trans=1;
	mask.bit.IRQ_RX_UD1=1;
//	mask.bit.IRQ_RX_UD2=1;
	outportb(0x506,mask.byte);
	asm { sti } 
} 


void EmbSerialPU_M::AddMod(unsigned char byte)
{ 
	m_TBuffMod.Add(byte); 	
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x506,mask.byte);
}
void EmbSerialPU_M::AddTransit(unsigned char byte)
{ 
	m_TBuffTransit.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x506,mask.byte);
}

void EmbSerialPU_M::AddUD1(unsigned char byte)
{ 
	m_TBuffUD1.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_UD1 = 1;
	outportb(0x506,mask.byte);
}

void EmbSerialPU_M::AddUD2(unsigned char byte)
{ 
	m_TBuffUD2.Add(byte); 
	UnEmbSerialPU_MIRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_UD2 = 1;
	outportb(0x506,mask.byte);
}

#endif

#ifdef IncEmbSerialMD34AVT

void EmbSerialMD34AVT::IsrXX() 
{
//	UnEmbSerialMD34Status status;
	UnEmbSerialMD34IRQ irq,mask;
//	asm { cli } 

	irq.byte  = inportb(0x505);
	mask.byte = inportb(0x506);
//	status.byte = inportb(0x514);
	if(irq.bit.IRQ_RX_mod) m_RBuffMod.Add(inportb(0x507)); 
	if(irq.bit.IRQ_RX_trans) m_RBuffTransit.Add(inportb(0x509)); 
	if(irq.bit.IRQ_RX_power) m_RBuffPower.Add(inportb(0x50B)); 

	if(irq.bit.IRQ_TX_mod) if(m_TBuffMod.Used()) { outportb(0x507,m_TBuffMod.Get());	if(m_TBuffMod.Used()) mask.bit.IRQ_TX_mod=0; } else mask.bit.IRQ_TX_mod=0;
	if(irq.bit.IRQ_TX_trans) if(m_TBuffTransit.Used()) { outportb(0x509,m_TBuffTransit.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_trans=0; } else mask.bit.IRQ_TX_trans=0;
	if(irq.bit.IRQ_TX_power) if(m_TBuffPower.Used()) { outportb(0x50B,m_TBuffPower.Get());	if(m_TBuffTransit.Used()) mask.bit.IRQ_TX_power=0; } else mask.bit.IRQ_TX_power=0;
	outportb(0x506,mask.byte);
////
//	mask.bit.IRQ_RX_mod=0;
//	mask.bit.IRQ_RX_trans=0;
//	mask.bit.IRQ_RX_power=0;
//	outportb(0x5A6,mask.byte);
////
//	count++;
	EmbIsrINT1::EOI();
//	asm { sti } 
}


void EmbSerialMD34AVT::Init() 
{ 
	count=0;
	EmbIsrINT1::Init(); 
	m_RBuffMod.Init(); 
	m_TBuffMod.Init(); 
	m_RBuffTransit.Init(); 
	m_TBuffTransit.Init(); 
	m_RBuffPower.Init(); 
	m_TBuffPower.Init(); 
	UnEmbSerialMD34IRQ mask;
	mask.byte = 0;//inportb(0x5A6);
	mask.bit.IRQ_RX_mod=1;
	mask.bit.IRQ_RX_trans=1;
	mask.bit.IRQ_RX_power=1;
	outportb(0x506,mask.byte);
} 

void EmbSerialMD34AVT::AddMod(unsigned char byte)
{ 
	m_TBuffMod.Add(byte); 	
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_mod = 1;
	outportb(0x506,mask.byte);

}
void EmbSerialMD34AVT::AddTransit(unsigned char byte)
{	
	m_TBuffTransit.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_trans = 1;
	outportb(0x506,mask.byte);
}

void EmbSerialMD34AVT::AddPower(unsigned char byte)
{	
	m_TBuffPower.Add(byte);  
	UnEmbSerialMD34IRQ mask;
	mask.byte = inportb(0x506);
	mask.bit.IRQ_TX_power = 1;
	outportb(0x506,mask.byte);
}

#endif