#ifndef __TINY__
#define __TINY__
#endif
#include "start.h"
////////////////////////////////////////////
////    Секция включения Emb-классов    ////
////////////////////////////////////////////
#define IncEmbRS232
#define IncEmbRS485
#define IncEmbTimer
//#define IncEmbNMI
//#define IncEmbIndicator
#define IncEmbSerialMD34AVT
////////////////////////////////////////////
#include "longtoa.cas"
#include "Ltoa1.c"
#include "stdlib.h"
//#include "command.h"
#include "embisr.cpp"
//#include "basic'.h"
//#include "basic'.cpp"

void Enable() { asm { sti } }
void Disable() { asm { cli } }

void ResetWatchDog()
{
	outport(wdtcon,0xAAAA);
	outport(wdtcon,0x5555);
	outportb(0x6FB,0x55);
};

union u2uc
{
  unsigned u;
	unsigned char uc[2];
};

unsigned char HexChar(unsigned char s)
{
  if(s<=9) return s + '0';
  if((s>=0x0A)&&(s<=0x0F)) return s + 'A' - 10;
	return 'x';
}

void ConvertToWin1251(char *str)
{
	int i=0;
	unsigned char ch;
  while(str[i])
	{
		ch=str[i];
		str[i]=ascii[ch];
		i++;
		if(i>=24)
		{
			str[i]=0; 
			return;
		}
	}
}

unsigned SelfID() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000A; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF); 
}

unsigned SelfYear() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF0008; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}

unsigned SelfVer1() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000C; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}

unsigned SelfVer2() 
{ 
	unsigned far *ctrl = (unsigned far*)0xFFFF000E; 
	return ((*ctrl&0x00FF)<<8)+(((*ctrl)>>8)&0x00FF);  
}

unsigned char Modify5A(unsigned char byte)
{
	switch(byte)
	{
		case 0x00: return 0x5A;
		case 0x01: return 0x55; 
		case 0x02: return 0xA5; 
		case 0x03: return 0xAA; 
		default: return 0;
	}

}
// 	unsigned CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }
struct MsgStatus
{
	unsigned readyToSend : 1;
	unsigned isRS232 : 1;
	unsigned isRS485 : 1;
	unsigned reserved : 5;
};

union UnMsgStatus
{
	MsgStatus msgStatus;
	unsigned char byte;
};

struct TOM // [TRС00MEK]
{
	int K : 1; // K - признак получения пакета адресатом, устанавливается в "1" при получении пакета адресатом;
	int E : 1; // E - бит ошибки в CRC, устанавливается в "1" если не сходится CRC;
	int M : 1; // M - бит монитора, устанавливаемый в "1" при проходе кадром "активного монитора";
	int reserved : 2;
	int C : 1; // R - признак сообщение из RS-485 (был запрос маркера)
	int R : 1; // C - устанавливается в "1" если это запрос компьютера подключенного к станции.
	int T : 1; // T - бит маркера; 
//	TOM() { reserved=0; T=R=C=M=E=K=0; }
};

union UnTOM
{
	unsigned char byte;
	TOM tom;
};

struct EmbMsg
{
	unsigned char dir;
	UnMsgStatus readyToSend;
	unsigned counter;
	unsigned char body[270];
// Start/8	TOM/8	Cycle/8	AddrI/16	AddrS/16	Type/8	Length/16	 BODY/ Length	CRC/16	Blank/8
	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned AddrR()	{	return body[10] + (body[9]<<8);	 }		// 2
	void SetAddrI(unsigned word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;	}

	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}


	unsigned char Type()	{ return body[6]; }		// 1
	unsigned Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned FullSize(); 			// 2
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
	unsigned CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }


	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

	void Init();
	unsigned Add(unsigned char byte);
	unsigned Used() { return counter; }
	unsigned IsFree() { return 270-counter; }
	int IsEnd();
	int IsEndOfHeader();
	unsigned ChkCRC();
	unsigned CalcCRC();
	unsigned ReCalcCRC();
	unsigned char IsReadyToSend() { return readyToSend.msgStatus.readyToSend; }	
	void SetReadyToSend(unsigned char i) { readyToSend.msgStatus.readyToSend=i; }
//	unsigned char IsRS485() { return readyToSend.msgStatus.isRS485; } 
//	void SetRS485(unsigned char i) { readyToSend.msgStatus.isRS485=i; } 
	unsigned char IsRS232() { return readyToSend.msgStatus.isRS232; } 
	void SetRS232(unsigned char i) { readyToSend.msgStatus.isRS232=i; } 
	unsigned char Dir() { return dir; }

	void SetDir(unsigned char d) { dir= d; } // dir = 1 пришел с West, dir=2 прищел с East

	void Copy(EmbMsg m);
};

void EmbMsg::Copy(EmbMsg m)
{
	for(int i=0; i<270; i++) body[i]=m.body[i];
} 

void EmbMsg::Init()
{
	counter=0;
  for(int i=0; i<270; i++) body[i]=0;
	readyToSend.msgStatus.readyToSend=0;
}

unsigned EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
	else return counter;
}

unsigned EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
		return 1;
	}
	else
	  return 0;
}

int EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int EmbMsg::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}

unsigned EmbMsg::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned EmbMsg::CalcCRC()
{
  int i;
	unsigned c=0;
	if(Length()<=256) 
	{
		for(i=0; i<Length()+11; i++) c += body[i];
		body[Length()+11]=(c>>8)&0xFF;
		body[Length()+12]=c&0xFF;
		return c;
	}
	else return 0;
} 
/////////////////////
struct EmbMsgBuffer
{
    unsigned BuffSize;
    unsigned Head;
    unsigned Tail;
    EmbMsg Buff[16];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned Used();
    unsigned Free();
};

void EmbMsgBuffer::Init()
{
  BuffSize = 16;
  Head = 0;
  Tail = 0;
}

void EmbMsgBuffer::Add(EmbMsg &msg)
{
	for(int i=0; i<msg.FullSize(); i++) Buff[Head].body[i] = msg.body[i];
	Head++;
  if(Head == BuffSize) Head = 0;
}

void EmbMsgBuffer::Get(EmbMsg &msg)
{
  if(++Tail < BuffSize) 
	{
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[Tail-1].body[i];
	}
	else
	{
		Tail = 0;
		for(int i=0; i<msg.FullSize(); i++) msg.body[i] = Buff[BuffSize-1].body[i];
	}
}

unsigned EmbMsgBuffer::Used()
{
  int n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
}

unsigned EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}
/////////////////////
struct Emb2TypeVer
{
	unsigned type;
	unsigned softVer;
	unsigned ctrlNumber;
	unsigned ctrlYear;
	unsigned ctrlVer1;
	unsigned ctrlVer2;
	unsigned char signature_hardware[16];
	unsigned char signature_software[16];
};

union UnEmb2TypeVer
{
	Emb2TypeVer emb2TypeVer;
	unsigned char byte[44];
};

struct StateBMD155
{
	unsigned char state;  // Бит 0: "0" - остутсвтие связи с ППУ1, "1" - норма
									// Бит 1: "0" - остутсвтие связи с ППУ2, "1" - норма
									// Бит 1: "0" - остутсвтие связи ПИ, "1" - норма
	unsigned char state2;  // Состояние платы интерфейсов
	unsigned char ppu1_bytes[16];
	unsigned char ppu2_bytes[16];														// 34
	unsigned long count_no_correct_block1;									// 42
	unsigned long count_no_correct_block2;									// 46
	unsigned long count_no_correct_result;									// 50
	unsigned long count_notRS1;															// 54
	unsigned long count_notRS2;															// 58
	unsigned long count_block;															// 62
	unsigned char mod; // Состояние платы интерфейсов       // 63
	unsigned char dem1; // Состояние платы интерфейсов      // 64
	unsigned char dem2; // Состояние платы интерфейсов      // 65
	unsigned char state_dem1; // Состояние платы интерфейсов// 66
	unsigned char state_dem2; // Состояние платы интерфейсов// 67
	unsigned char statePI; // Состояние платы интерфейсов		// 68	
	unsigned char loopPI; // Состояние шлейфов							// 69
	unsigned char demPI; // Состояние демодуляторов					// 70
};

union UnStateBMD155
{
	StateBMD155 stateBMD155;
	unsigned char byte[72];
};
	
struct StatePUM
{
	unsigned char ver;						// 1
	unsigned char reserv; 				// 2
	unsigned long ulBlock;				// 6
	unsigned long ulErrOut;				// 10
	unsigned long ulErrAfterRS1;	// 14
	unsigned long ulErrAfterRS2;	// 18
	unsigned long ulErrBeforeRS1;	// 22
	unsigned long ulErrBeforeRS2;	// 26
	unsigned char state[16];			// 42
};

union UnStatePUM
{
	StatePUM statePUM;
	unsigned char byte[42];
};

struct Command
{
	unsigned char chan;
	unsigned char command;
	unsigned char par;
	unsigned char done;
};

struct Emb2NetStat
{
	unsigned long selfPacketSend; // 4
	unsigned long selfPacketRecv; // 4
	unsigned long allPacketRecv;  // 4
	unsigned short requestMarker; // 2
	unsigned short genMarker;     // 2
	unsigned short highID;        // 2
	unsigned short buffModPd;        // 2
	unsigned short buffModPm;        // 2
	unsigned short buffTransPd;        // 2
	unsigned short buffTransPm;        // 2
	unsigned short buff232Pd;        // 2
	unsigned short buff232Pm;        // 2
	unsigned short markerTime; //2 
	unsigned char ready_transit; //1 
	unsigned char ready_mod; //1 
};

union UnEmb2NetStat
{
	Emb2NetStat emb2NetStat;
	unsigned char byte[32];
};

struct Emb4AvtFrequMode
{
	unsigned char type;
	unsigned char reserv;
	unsigned short ctrlBUK;
	unsigned char numOfFrequ[2];
	unsigned char frequ[160];
};

union UnEmb4AvtFrequMode
{
	Emb4AvtFrequMode emb4AvtFrequMode;
	unsigned char byte[166];
};
/////////////////////
struct Emb2PSMode
{
	unsigned char fpd1;
	unsigned char fpm1;
	unsigned char fpd2;
	unsigned char fpm2;
};

union UnEmb2PSMode
{
	Emb2PSMode emb2PSMode;
	unsigned char byte[4];
};

union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
	unsigned char uc[2];
};

//	EmbIndicator embIndicator;
////////////////////////
	EmbTimer embTimer;
////////////////////////

unsigned long time1=0,time2=0;
unsigned char flagADUC1=0, flagADUC2=0;

void Callback0()
{
  time1++;
  time2++;
}

	EmbTimerCallback embTimerCallback0;

	EmbMsgBuffer rBuffEmbMsg;	
	EmbMsgBuffer tBuffEmbMsgWest;
	EmbMsgBuffer tBuffEmbMsgEast;
	EmbMsgBuffer tBuffEmbMsg485;

	EmbMsg embMsg232;
	EmbMsg embMsg485;
	EmbMsg embMsgWest;
	EmbMsg embMsgEast;
	EmbMsg embMsgAns;
	EmbMsg embMsgTemp;
	EmbMsg embMsgRandMode;
//	EmbMsgCover embMsgCoverRequest;
	EmbMsg *embMsgRequest;

	EmbRS232 embRS232;	
	EmbRS485 embRS485;
	EmbSerialMD34AVT embSerialACT155;

	unsigned ctrlRandMode;
	unsigned char randMasterMode;
	unsigned char	frequRandPd;
	unsigned char	frequRandPm;
	unsigned char powerByte;
	unsigned char counterPower;

	char ch;
	long f_len;
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned long time485=0,timeRand=0;
	unsigned char request1=0, request2=0;
	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0, recievePower=0;
	unsigned HighID=0, countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];
	unsigned char far* bt;
	unsigned addr1;

	unsigned char send1[16];
	unsigned char send2[16];
	unsigned char powerMes[16];
	unsigned char err_ppu1; 
	unsigned char err_ppu2; 
	unsigned char byte, westByte, eastByte;
	unsigned char mode5A=0, mode5AWest=0, mode5AEast=0, mode5APower=0; 
	unsigned char cycle=0;
	unsigned char trunk;
	unsigned char frequSelfPd[2];
	unsigned char frequSelfPm[2];

	unsigned char ttbb=0;
	unsigned char mtbb=0;
	unsigned long count_tr=0;
	unsigned long count_md=0;
	unsigned err_tr=0;
	unsigned err_md=0;

	UnStateBMD155 unStateBMD155;
	UnEmb2TypeVer unEmb2TypeVer; 
	UnStatePUM unStatePUM;
	UnEmb2NetStat unEmb2NetStat;
	UnEmb4AvtFrequMode far * unEmb4AvtFrequMode;
	UnEmb2PSMode  unEmb2PSMode;

	unsigned char far *addrRAM;
	unsigned shift;
	unsigned len;
	unsigned temp_crc;
	UL2UC ul2uc;
	UI2UC ui2uc;

	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;
	long count_notRS1;
	long count_notRS2;
	long err_tmp;

	int i232;
	unsigned aI, aS, aR;

void SendPower(unsigned char t, unsigned char frequ1, unsigned char frequ2)
{
// <Blank><Trunk[1...8]><P_Input><CRC>
	unsigned char crc;
	unsigned char powerstr[16];
	if(t) 
	{
		unEmb2PSMode.emb2PSMode.fpd2 = frequ1;
		unEmb2PSMode.emb2PSMode.fpm2 = frequ2;
	}
	else
	{
		unEmb2PSMode.emb2PSMode.fpd1 = frequ1;
		unEmb2PSMode.emb2PSMode.fpm1 = frequ2;
	}

	embSerialACT155.AddPower(0xAA); // Start
	powerstr[0] = (SelfID()>>8)&0xFF; // SelfCtrlHigh
	powerstr[1] = SelfID()&0xFF; // SelfCtrlLow
	powerstr[2] = 0x01; // Mode 1-Random 0-Const
	powerstr[3] = t; // Trunk
	powerstr[4] = frequ1; // Fpd
	powerstr[5] = frequ2; // Fpm
	for(i=0; i<6; i++)
	{
		switch(powerstr[i]) // Pвх
		{
			case 0x5A: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x00); break;
			case 0x55: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x01); break;
			case 0xA5: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x02); break;
			case 0xAA: embSerialACT155.AddPower(0x5A); embSerialACT155.AddPower(0x03); break;
			default: embSerialACT155.AddPower(powerstr[i]);
		}
	}
	embSerialACT155.AddPower(0x55); // End
}

void ProtocolFromModACT155()
{
	int ic=0;
	while(embSerialACT155.UsedMod())
	{
			ResetWatchDog();
//			if(++ic>16) return;
			westByte = embSerialACT155.GetMod();
			switch(westByte)
			{
			case 0x55: 
				time3BlankMod = time1; ready_mod=1; recieveWest=0; embMsgWest.Init(); break; 			
			case 0xAA: recieveWest = 1; ready_mod=1; time3BlankMod = time1; embMsgWest.Init();	break; 			
			case 0xA5: markerWest  = 1; ready_mod=1; time3BlankMod = time3Marker = time1; break; // Маркеров здесь НЕТ!
			case 0x5A: mode5AWest=1; ready_mod=1; break;
			default:
				if(markerWest==1)	markerWest=2; 
				if(recieveWest==1)
				{
					if(mode5AWest) { embMsgWest.Add(Modify5A(westByte)); mode5AWest=0;	}
					else embMsgWest.Add(westByte);
				}
			}

			if(embMsgWest.IsEnd())
			{
				if((embMsgWest.AddrS()!=SelfID())&&(embMsgWest.AddrI()!=SelfID()))
				{
						// передаем побайтно дальше принимаем пакет
					embSerialACT155.AddTransit(0x55);	
					embSerialACT155.AddTransit(0xAA);	
					for(i=0; i<embMsgWest.FullSize(); i++) 
					{
						switch(embMsgWest.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgWest.body[i]);
						}
					}
				}
					
				if(embMsgWest.AddrS()==SelfID())
				{
					embMsgWest.SetDir(1);
					rBuffEmbMsg.Add(embMsgWest);
					embMsgWest.Init();
				}
				recieveWest = 0;
			}

		if(!recieveWest)
		{
			if(tBuffEmbMsgWest.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgWest.Get(embMsgA);
				embSerialACT155.AddTransit(0x55);
				embSerialACT155.AddTransit(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
					case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
					case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
					case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
					default: embSerialACT155.AddTransit(embMsgA.body[i]);
					}
					ResetWatchDog();
				}
				embSerialACT155.AddTransit(0x55);
			}
		}
	}
}

void ProtocolFromTransitACT155()
{
	int ic=0;
	while(embSerialACT155.UsedTransit())
	{
		ResetWatchDog();
//		if(++ic>16) return;
		eastByte = embSerialACT155.GetTransit();
		switch(eastByte)
		{
				case 0x55: 
					time3BlankTransit = time1; ready_transit=1; recieveEast=0; embMsgEast.Init(); 
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: countRecv++; recieveEast=1; ready_transit=1; time3BlankTransit = time1; embMsgEast.Init(); break; 			
				case 0xA5: 	markerEast =1; ready_transit=1; time3BlankTransit = time3Marker = time1;  break; // Маркеров здесь НЕТ!
					// Если в буффере есть пакет на передачу, то передаем его
				case 0x5A: mode5AEast=1; ready_transit=1; break;
				default:
					if(markerEast==1)	markerEast=2; 
					if(recieveEast==1)
					{
						if(mode5AEast) { embMsgEast.Add(Modify5A(eastByte)); mode5AEast=0;	}
						else embMsgEast.Add(eastByte);
					}
		}

		if(embMsgEast.IsEnd())
		{
			if((embMsgEast.AddrS()!=SelfID())&&(embMsgEast.AddrI()!=SelfID()))
			{
				embSerialACT155.AddMod(0x55);	
				embSerialACT155.AddMod(0xAA);	
				for(i=0; i<embMsgEast.FullSize(); i++) 
				{
					switch(embMsgEast.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgEast.body[i]);
					}
				}
				countSend++;
			}
			
			if(embMsgEast.AddrS()==SelfID())
			{
				embMsgWest.SetDir(2);
				rBuffEmbMsg.Add(embMsgEast);
				embMsgEast.Init();
			}
		}
		if(!recieveEast)
		{
			if(tBuffEmbMsgEast.Used())
			{
				EmbMsg embMsgA;
				embMsgA.Init();
				tBuffEmbMsgEast.Get(embMsgA);
				
				embSerialACT155.AddMod(0x55);
				embSerialACT155.AddMod(0xAA);
				for(i=0; i<embMsgA.FullSize(); i++) 
				{
					switch(embMsgA.body[i])
					{
					case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
					case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
					case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
					case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
					default: embSerialACT155.AddMod(embMsgA.body[i]);
					}
					ResetWatchDog();
				}
				embSerialACT155.AddMod(0x55);
			}
		}
	}
}

void CheckPower()
{
	unsigned char t,k;
	while(embSerialACT155.UsedPower())
	{
		ResetWatchDog();
//		if(++ic>16) return;
		powerByte = embSerialACT155.GetPower();
		if(counterPower>15) counterPower=0;
		switch(powerByte)
		{
				case 0x55: 
					if(counterPower>=6)
					{
						ctrlRandMode = (powerMes[0]<<8)+powerMes[1];
						if(ctrlRandMode>SelfID()) randMasterMode = 0;
						else randMasterMode = 1;
//						embRS232.Trans((unsigned char)'S');
						if(powerMes[2])
						{
							t = powerMes[3];
							if(t<2)
							{
//								embRS232.Trans((unsigned char)'a');
								//							if(frequRandPd[t] != powerMes[3]) 
								{
									// Включаем возможность изменения частоты
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,14);	        		
									embMsgRandMode.SetBody(2,208);				
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
									
									//								frequRandPd[t] = powerMes[3];
									// Посылаем команду на перестройку частоты Пд
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
									embMsgRandMode.SetBody(2,powerMes[5]);			
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
								}
								//							if(frequRandPm[t] != powerMes[4]) 
								{
									//								frequRandPm[t] = powerMes[4];
									// Посылаем команду на перестройку частоты Пм
									embMsgRandMode.Init();
									embMsgRandMode.SetTOM(0x20);
									embMsgRandMode.SetAddrI(SelfID());
									embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
									embMsgRandMode.SetRS485();
									embMsgRandMode.SetAddrR(0x0000);
									embMsgRandMode.SetType(0x09);
									embMsgRandMode.SetLength(3);			
									embMsgRandMode.SetBody(0,t+1);		// Номер ствола	
									embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
									embMsgRandMode.SetBody(2,powerMes[4]);			
									embMsgRandMode.SetCycle(cycle++);
									embMsgRandMode.CalcCRC();
									tBuffEmbMsg485.Add(embMsgRandMode);
								}
							}
						}
					}
					else
					{
//						frequRandPd[t] = 0xFF;
//						frequRandPm[t] = 0xFF;
					}
					counterPower = 0;
					// конец пакета - разбираем пакет
					/*embSerialACT155.AddMod(0x55);	return; */break; 			
				case 0xAA: recievePower=1; counterPower=0;
					// начало пакета 
					break; 			
				case 0xA5: 	 break; // Маркеров здесь НЕТ!
				case 0x5A: mode5APower=1; break;
				default:
					if(recievePower==1)
					{
						if(mode5APower) { powerMes[counterPower++]=Modify5A(powerByte); mode5APower=0;	}
						else powerMes[counterPower++]= powerByte;
					}
		}
	}
}

void RandFrequ()
{
	unsigned rand = inport(0xFF60);
	unsigned char randfrequ;
//	unsigned char input1 = inportb(0x522)&0x02;
//	unsigned char input2 = (inportb(0x522)>>2)&0x02;
//	unsigned char input1rm = (inportb(0x522)>>4)&0x02;
//	unsigned char input2rm = (inportb(0x522)>>6)&0x02;
	unsigned char input1 = inportb(0x523)&0x01;
	unsigned char input2 = (inportb(0x523)>>1)&0x01;
	unsigned char input1rm = (inportb(0x523)>>2)&0x01;
	unsigned char input2rm = (inportb(0x523)>>3)&0x01;

	if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1)
	{
		if(time1-timeRand>2000)
		{
		timeRand = time1;
//		embRS232.Trans((unsigned char)'.');
		if((!input1)&&(!input2)&&(!input1rm)&&(!input2rm))
		{
//			embRS232.Trans((unsigned char)'t');
//			embRS232.Trans(HexChar((inportb(0x522)>>4)&0x0F));	
//			embRS232.Trans(HexChar(inportb(0x522)&0x0F));	
//			embRS232.Trans('.');

			if(randMasterMode)
			{
//					embRS232.Trans((unsigned char)'R');
					// Генерим в датчике случайных чисел номер частотной пары
					rand = inport(0xFF60);
					randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
					frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
					frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
					unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK;
					// Передаем на другую сторону
					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
					// Включаем возможность изменения частоты
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();				
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,14);	        		
					embMsgRandMode.SetBody(2,208);				
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пд
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
					embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пм
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
					embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// устанавливаем время ожидания незахвата
					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
					if(trunk) trunk=0;
					else trunk=1;
			}
		}
		else
		{
			if(input1&&input2)
			{
//				embRS232.Trans((unsigned char)'N');
				// Генерим в датчике случайных чисел номер частотной пары
				rand = inport(0xFF60);
				randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
				frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
				frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
				// Передаем на другую сторону
				SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]);
				// Включаем возможность изменения частоты
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();				
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,14);	        		
				embMsgRandMode.SetBody(2,208);				
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// Посылаем команду на перестройку частоты Пд
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
				embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// Посылаем команду на перестройку частоты Пм
				embMsgRandMode.Init();
				embMsgRandMode.SetTOM(0x20);
				embMsgRandMode.SetRS485();
				embMsgRandMode.SetAddrI(SelfID());
				embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
				embMsgRandMode.SetAddrR(0x0000);
				embMsgRandMode.SetType(0x09);
				embMsgRandMode.SetLength(3);			
				embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
				embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
				embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
				embMsgRandMode.SetCycle(cycle++);
				embMsgRandMode.CalcCRC();
				tBuffEmbMsg485.Add(embMsgRandMode);
				// устанавливаем время ожидания незахвата
				if(trunk) trunk=0;
				else trunk=1;
			}
			else
			{
//				embRS232.Trans((unsigned char)'E');
//				embRS232.Trans(HexChar((inportb(0x522)>>4)&0x0F));	
//				embRS232.Trans(HexChar(inportb(0x522)&0x0F));	
//				embRS232.Trans('.');	
				if(randMasterMode)
				{
					trunk = 2; 
					if(input1||input1rm) trunk=0;
					if(input2||input2rm) trunk=1;
					if(trunk==2) 
					{
//						embRS232.Trans((unsigned char)'e');
						return;
					}
				// Передаем на другую сторону
//					if((frequSelfPd[trunk]==0xFF)||(frequSelfPm[trunk]==0xFF))
					{
//						embRS232.Trans((unsigned char)'+');
						rand = inport(0xFF60);
						randfrequ = rand%unEmb4AvtFrequMode->emb4AvtFrequMode.numOfFrequ[trunk];
						frequSelfPd[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2];
						frequSelfPm[trunk] = unEmb4AvtFrequMode->emb4AvtFrequMode.frequ[trunk*80+randfrequ*2+1];
					}

//					embRS232.Trans((unsigned char)'0'+trunk);

					SendPower(trunk,frequSelfPd[trunk],frequSelfPm[trunk]); // ИЗ ПАМЯТИ!!!
					// Включаем возможность изменения частоты
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();				
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,14);	        		
					embMsgRandMode.SetBody(2,208);				
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пд
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,4);	        // Код частоты Пд		
					embMsgRandMode.SetBody(2,frequSelfPd[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
					// Посылаем команду на перестройку частоты Пм
					embMsgRandMode.Init();
					embMsgRandMode.SetTOM(0x20);
					embMsgRandMode.SetRS485();
					embMsgRandMode.SetAddrI(SelfID());
					embMsgRandMode.SetAddrS(unEmb4AvtFrequMode->emb4AvtFrequMode.ctrlBUK);
					embMsgRandMode.SetAddrR(0x0000);
					embMsgRandMode.SetType(0x09);
					embMsgRandMode.SetLength(3);			
					embMsgRandMode.SetBody(0,trunk+1);		// Номер ствола	
					embMsgRandMode.SetBody(1,5);	        // Код частоты Пм		
					embMsgRandMode.SetBody(2,frequSelfPm[trunk]);			
					embMsgRandMode.SetCycle(cycle++);
					embMsgRandMode.CalcCRC();
					tBuffEmbMsg485.Add(embMsgRandMode);
				}
			}
		}
		}
	}
}

void Check2InitTransitMod()
{

	if(!ready_transit) unEmb2NetStat.emb2NetStat.ready_transit=1;
	if(!ready_mod) unEmb2NetStat.emb2NetStat.ready_mod=1;
		// Если произошло изменение ready_transit или ready_mod из "0" в "1"
		// то time3Marker = 0; под пакет 2355 байта и скорость 64К*8/11=46545
	if(time1-time3BlankMod>500) 
	{
		recieveWest=0; 
		time3BlankMod = time1;
		embSerialACT155.AddTransit(0x55);
	}
	if(time1-time3BlankTransit>500)
	{
		recieveEast=0; 
		time3BlankTransit = time1;
		embSerialACT155.AddMod(0x55);
	}


	if((time1-time3highID)>10000) 
	{
		time3highID=time1;
	}		

		if(unEmb2NetStat.emb2NetStat.buffModPm<embSerialACT155.UsedMod()) unEmb2NetStat.emb2NetStat.buffModPm = embSerialACT155.UsedMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPm<embSerialACT155.UsedTransit()) unEmb2NetStat.emb2NetStat.buffTransPm = embSerialACT155.UsedTransit();
		if(unEmb2NetStat.emb2NetStat.buffModPd<embSerialACT155.UsedSendMod()) unEmb2NetStat.emb2NetStat.buffModPd = embSerialACT155.UsedSendMod();
		if(unEmb2NetStat.emb2NetStat.buffTransPd<embSerialACT155.UsedSendTransit()) unEmb2NetStat.emb2NetStat.buffTransPd = embSerialACT155.UsedSendTransit();
		if(unEmb2NetStat.emb2NetStat.buff232Pm<embRS232.UsedReceive()) unEmb2NetStat.emb2NetStat.buff232Pm = embRS232.UsedReceive();
		if(unEmb2NetStat.emb2NetStat.buff232Pd<embRS232.UsedTrans()) unEmb2NetStat.emb2NetStat.buff232Pd = embRS232.UsedTrans();

		if(!recieveEast)
		{
				if(!embSerialACT155.UsedSendMod()) 
				{	
					if(tBuffEmbMsgEast.Used())
					{
						EmbMsg embMsgA;
						embMsgA.Init();
						tBuffEmbMsgEast.Get(embMsgA);
					
						embSerialACT155.AddMod(0x55);
						embSerialACT155.AddMod(0xAA);
						for(i=0; i<embMsgA.FullSize(); i++) 
						{
							switch(embMsgA.body[i])
							{
							case 0x5A: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x00); break;
							case 0x55: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x01); break;
							case 0xA5: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x02); break;
							case 0xAA: embSerialACT155.AddMod(0x5A); embSerialACT155.AddMod(0x03); break;
							default: embSerialACT155.AddMod(embMsgA.body[i]);
							}
							ResetWatchDog();
						}
						embSerialACT155.AddMod(0x55);
					}
				}
		}

		if(!recieveWest)
		{
			if(!embSerialACT155.UsedSendTransit()) 
			{	
				if(tBuffEmbMsgWest.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					tBuffEmbMsgWest.Get(embMsgA);
					embSerialACT155.AddTransit(0x55);
					embSerialACT155.AddTransit(0xAA);
					for(i=0; i<embMsgA.FullSize(); i++) 
					{
						switch(embMsgA.body[i])
						{
						case 0x5A: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x00); break;
						case 0x55: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x01); break;
						case 0xA5: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x02); break;
						case 0xAA: embSerialACT155.AddTransit(0x5A); embSerialACT155.AddTransit(0x03); break;
						default: embSerialACT155.AddTransit(embMsgA.body[i]);
						}
						ResetWatchDog();
					}
					embSerialACT155.AddTransit(0x55);
				}
			}
		}

}

	unsigned char tlf_number[6];
	unsigned char tlf_counter=0;
	unsigned char tlf_state=0;
	unsigned char presto = 0;
	unsigned char ring_counter = 0;
	unsigned long presto_time =0;
	unsigned long wait_time =0;
	unsigned long presto_ring =0;

unsigned char	ab1[] =	{ 0x45,0x60,0xBF,0x25,0x52,0x2A,0x64,0x3F,0x89,0x00};   // IM-Filter part 1 
unsigned char	ab2[] =	{ 0x45,0x68,0x53,0x02,0x49,0x8A,0x07,0xF6,0x04,0x00};   // IM-Filter part 2 
unsigned char	ab3[] =	{ 0x45,0x18,0x08,0xB0,0xC5,0x42,0x3E,0xFB,0x72,0x07 };  // FRR-Filter    
unsigned char	ab4[] =	{ 0x45,0x28,0x43,0x8a,0xBc,0x27,0x88,0x00,0x00,0x00 }; // AR-Filter - строка 20
unsigned char	ab5[] =	{ 0x45,0x48,0x96,0x38,0x29,0x96,0xC9,0x2B,0x8B,0x00 }; /// LPR-Filter       
unsigned char	ab6[] =	{0x45,0x20,0x08,0x90,0x3F,0xBC,0x75,0x28,0x72,0x07}; // FRX-Filter       
unsigned char	ab7[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27,0x85,0x50,0xc0,0x1a}; // AX-Filter -строка 20
unsigned char	ab8[] =	{ 0x45,0x50,0x96,0x38,0x29,0xF5,0xFA,0x2B,0x8B,0x00}; // LPX-Filter       
unsigned char	ab9[] =	{ 0x45,0x00,0x30,0x9B,0x88,0x80,0x00,0xC8,0x32,0x80}; // TH-Filter part 1 
unsigned char	ab10[] =	{ 0x45,0x08,0x80,0x00,0x80,0x00,0x67,0x35,0x5A,0x01 }; // TH-Filter part 2 
unsigned char	ab11[] =	{ 0x45,0x10,0x22,0xAD,0xB2,0x2A,0x24,0xDC,0x88,0x00};  // TH-Filter part 3 
unsigned char	ab12[] =	{ 0x45,0x80,0xF9,0x29,0x9B,0x2A,0x1A,0x22,0xC1,0x32}; // DC-Parameter     
unsigned char	ab13[] =	{ 0x45,0x70,0x32,0x3B,0x1B,0xC0,0xC3,0xB2,0xAC,0x02}; // Ringing          
unsigned char	ab14[] =	{ 0x45,0x90,0x3E,0xE5,0x2E,0xBA,0x81,0x2A,0xBA,0x8A }; // LP-Filters       
unsigned char	ab15[] =	{ 0x45,0x88,0x7B,0x01,0x2C,0x7B,0xB3,0x47,0x7B,0x01}; // Hook Levels      
unsigned char	ab16[] =	{ 0x45,0x78,0x00,0xC0,0x6D,0x7A,0xB3,0x48,0x08,0x00}; // Ramp Generator   
unsigned char	ab17[] =	{ 0x45,0x58,0x4A,0x41,0x34,0xDB,0x0E,0xA2,0x2A,0x00}; // TTX 
unsigned char	ab18[] =	{0x45,0x38,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG1              
unsigned char	ab19[] =	{0x45,0x40,0x33,0x49,0x22,0x65,0xBB,0x00,0x00,0x00}; // TG2              
unsigned char	ab20[] =	{ 0x45,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};  // Reserved
unsigned char	ab21[] =	{ 0x45,0x30,0xBE,0x04,0xB0,0x27}; // AX-Filter -строка 29
unsigned char	ab22[] =	{ 0x46, 0x30, 0x07,0x10,0x79,0x11,0x02,0xFB,0x60,0x00,0x00,0x00 }; //DTMF POP
unsigned char	ab23[] =	{ 0x46,0x4A,0x00 };
unsigned char	ab24[] =	{0x44, 0x21, 0x00, 0x16, 0x06, 0x00, 0x00,  0x16, 0x06, 0x00 }; //pcmr,pcmx- line A
unsigned char	ab25[] =	{ 0x44, 0x1A, 0x00 }; // DSCR
unsigned char	ab26[] =	{ 0x44, 0x2B, 0x04 }; //TSTR3
unsigned char	ab27[] =	{ 0x44, 0x15, 0x01, 0x20, 0x07, 0x00, 0x03 };// bcr1-5
unsigned char	ab28[] =	{ 0x44,0x06,0x80 };  //XCR
unsigned char	ab29[] =	{ 0x44,0x1c,0x00 };  //LMCR1
unsigned char	ab30[] =	{0x4c, 0x21, 0x80, 0x96, 0x86, 0x80, 0x80,  0x96, 0x86, 0x80 }; //pcmr,pcmx- line B
// AKTIV
unsigned char	a22[] =	{ 0x02 };  // AKTIV mode -- разговорное состояние
unsigned char	a221[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a222[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE
unsigned char	a26[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a261[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a262[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x04); // off hook
// PAUSE 2
unsigned char	a263[] =	{ 0x02 }; // RING pause MODE -- генерация КПВ
unsigned char	a264[] =	{ 0x44,0x1c,0xAA };  // LMCR1
unsigned char	a265[] =	{ 0x44,0x1A,0x05 };  // dscr
//outportb(0x511, 0x00); // off hook
// RING
unsigned char	a272[] =	{ 0x05 }; // RING burst MODE -- выдача звонка
unsigned char	a271[] =	{ 0x44,0x1c,0x22 };  // LMCR1
unsigned char	a27[] =	{ 0x44,0x1A,0x00 };  // dscr
//outportb(0x511, 0x00); // оn hook
// WAIT
unsigned char	a28[] =	{ 0x07 }; // power dnv mode -- ожидание поднятия трубки
//outportb(0x511, 0x00); // on hook
unsigned char aaa[7];
unsigned char aa[] = { 0xC4,0x07,0xFF,0x00,0x00,0x00,0x00 }; 

void InitTLF()
{
	int i;

// сброс кодека
	for(i=0; i<15; i++) outportb(0x511, 0x08); 
	outportb(0x511, 0x00);
	for(i=0; i<10000; i++);

	outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab1); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab2); i++) outportb(0x50F, ab2[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab2); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab3); i++) outportb(0x50F, ab3[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab3); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab4); i++) outportb(0x50F, ab4[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab4); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab5); i++) outportb(0x50F, ab5[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab5); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab6); i++) outportb(0x50F, ab6[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab6); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab7); i++) outportb(0x50F, ab7[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab7); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab8); i++) outportb(0x50F, ab8[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab8); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab9); i++) outportb(0x50F, ab9[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab9); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab10); i++) outportb(0x50F, ab10[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab10); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab11); i++) outportb(0x50F, ab11[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab11); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab12); i++) outportb(0x50F, ab12[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab12); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab13); i++) outportb(0x50F, ab13[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab13); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab14); i++) outportb(0x50F, ab14[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab14); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab15); i++) outportb(0x50F, ab15[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab15); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab16); i++) outportb(0x50F, ab16[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab16); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab17); i++) outportb(0x50F, ab17[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab17); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab18); i++) outportb(0x50F, ab18[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab18); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab19); i++) outportb(0x50F, ab19[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab19); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab20); i++) outportb(0x50F, ab20[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab20); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab21); i++) outportb(0x50F, ab21[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab21); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab22); i++) outportb(0x50F, ab22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab23); i++) outportb(0x50F, ab23[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab23); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab24); i++) outportb(0x50F, ab24[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab24); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab25); i++) outportb(0x50F, ab25[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab25); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab26); i++) outportb(0x50F, ab26[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab27); i++) outportb(0x50F, ab27[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab27); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab28); i++) outportb(0x50F, ab28[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab28); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab29); i++) outportb(0x50F, ab29[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab29); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(ab30); i++) outportb(0x50F, ab30[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(ab30); i++);
}

void Ring()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a272); i++) outportb(0x50F, a272[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a272); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a271); i++) outportb(0x50F, a271[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a271); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a27); i++) outportb(0x50F, a27[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a27); i++);
  outportb(0x511, 0x00); // оn hook
}
void Active()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a222); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a26); i++) outportb(0x50F, a26[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a26); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a261); i++) outportb(0x50F, a261[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a261); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a262); i++) outportb(0x50F, a262[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a262); i++);
	outportb(0x511, 0x04); // off hook
}
void Pause2()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a263); i++) outportb(0x50F, a263[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a263); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a264); i++) outportb(0x50F, a264[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a264); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a265); i++) outportb(0x50F, a265[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a265); i++);
	outportb(0x511, 0x00); // off hook
}

void Wait()
{
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(a22); i++) outportb(0x50F, a22[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a22); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a221); i++) outportb(0x50F, a221[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a221); i++);
	outportb(0x510, 0x02); for(i=0; i<sizeof(a222); i++) outportb(0x50F, a222[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a222); i++);
//	outportb(0x510, 0x02); for(i=0; i<sizeof(a28); i++) outportb(0x50F, a28[i]); outportb(0x510, 0x01); for(i=0; i<200*sizeof(a28); i++);
	outportb(0x511, 0x00); // on hook
}

void Read()
{
// Пример  передачи/приема по SPI
// outportb(0x510, 0x02); for(i=0; i<sizeof(ab1); i++) outportb(0x50F, ab1[i]); outportb(0x510, 0x01);
// while((inportb(0x510) & 0x01)!=0);
// чтение принятых байтов  по адресу  0x50F принимается столько же байт сколько и  передается
	int i;
	outportb(0x510, 0x02); for(i=0; i<sizeof(aa); i++) outportb(0x50F, aa[i]); outportb(0x510, 0x01); inportb(0x510); for(i=0; i<20*sizeof(aa); i++);
	for(i=0; i<7; i++) aaa[i] = inportb(0x50F);
	
}

void InitTypeVer()
{
	int i=0;
	for(i=0; i<16; i++)
	{
		send1[i]=0;
		send2[i]=0;
		unStateBMD155.stateBMD155.ppu1_bytes[i]=0;
		unStateBMD155.stateBMD155.ppu2_bytes[i]=0;
		unStateBMD155.stateBMD155.state=0;
	}

	int rrr=0;

	unStateBMD155.stateBMD155.count_block=0;
	unStateBMD155.stateBMD155.count_no_correct_block1=0;
	unStateBMD155.stateBMD155.count_no_correct_block2=0;
	unStateBMD155.stateBMD155.count_no_correct_result=0;
	unStateBMD155.stateBMD155.count_notRS1=0;
	unStateBMD155.stateBMD155.count_notRS2=0;
	unStateBMD155.stateBMD155.demPI=0;
	unStateBMD155.stateBMD155.loopPI=0;
	unStateBMD155.stateBMD155.statePI=0;

	unEmb2TypeVer.emb2TypeVer.type       = 0x0507;
	unEmb2TypeVer.emb2TypeVer.softVer    = 0x0150;
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = 0;//SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = 0;//SelfVer2();
	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}
	bt = (unsigned char far*)0x80000000;
	unEmb2TypeVer.emb2TypeVer.signature_software[0] = *bt;
	unEmb2TypeVer.emb2TypeVer.signature_software[1] = *(bt+1);
	unEmb2TypeVer.emb2TypeVer.signature_software[2] = *(bt+2);
	unEmb2TypeVer.emb2TypeVer.signature_software[3] = *(bt+3);
	unEmb2TypeVer.emb2TypeVer.signature_software[4] = *(bt+4);
	unEmb2TypeVer.emb2TypeVer.signature_software[5] = *(bt+5);
	unEmb2TypeVer.emb2TypeVer.signature_software[6] = *(bt+6);
	unEmb2TypeVer.emb2TypeVer.signature_software[7] = *(bt+7);
	unEmb2TypeVer.emb2TypeVer.signature_software[8] = *(bt+8);
	unEmb2TypeVer.emb2TypeVer.signature_software[9] = *(bt+9);
	unEmb2TypeVer.emb2TypeVer.signature_software[10] = *(bt+10);
	unEmb2TypeVer.emb2TypeVer.signature_software[11] = *(bt+11);
	unEmb2TypeVer.emb2TypeVer.signature_software[12] = *(bt+12);
	unEmb2TypeVer.emb2TypeVer.signature_software[13] = *(bt+13);
	unEmb2TypeVer.emb2TypeVer.signature_software[14] = *(bt+14);
	unEmb2TypeVer.emb2TypeVer.signature_software[15] = *(bt+15);


}

void UpdatePUNInfo()
{
	unStatePUM.statePUM.state[0] = inportb(0x520);
	unStatePUM.statePUM.state[1] = inportb(0x521);
	unStatePUM.statePUM.state[2] = inportb(0x522);
	unStatePUM.statePUM.state[3] = inportb(0x523);
	unStatePUM.statePUM.state[4] = inportb(0x524);
	unStatePUM.statePUM.state[5] = inportb(0x525);
	unStatePUM.statePUM.state[6] = 0;
	unStatePUM.statePUM.state[7] = 0;
	unStatePUM.statePUM.state[8] = 0;
	unStatePUM.statePUM.state[9] = 0;
	unStatePUM.statePUM.state[10] = 0;
	unStatePUM.statePUM.state[11] = 0;
	unStatePUM.statePUM.state[12] = 0;
	unStatePUM.statePUM.state[13] = 0;
	unStatePUM.statePUM.state[14] = 0;
	unStatePUM.statePUM.state[15] = 0;

		unStateBMD155.stateBMD155.statePI=0;
/////////////////////////////////////////
		unStateBMD155.stateBMD155.mod=0;
		unStateBMD155.stateBMD155.dem1=0;
		unStateBMD155.stateBMD155.dem2=0;
		unStateBMD155.stateBMD155.state_dem1=0;
		unStateBMD155.stateBMD155.state_dem2=0;
}


void CheckTLF()
{
	if(time1 - wait_time >=40) 
	{
		wait_time = time1;
		Read();
		if(aaa[3]&0x40) 
		{
			if(tlf_state) 
			{
				Active();
				tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0;
			}
			tlf_state = 0;
		}
		else 
		{
			if(!tlf_state)
			{
				Wait();
				tlf_state=1;
			}
			if((aaa[3]&0x80)&&(aaa[5]&0x80))
			{
//	unsigned char tlf_number[4];
//	unsigned char tlf_counter=0;
//					Ring();
				switch(aaa[5]&0xFC)
				{
					case 196: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 1; break;
					case 200: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 2; break;
					case 204: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 3; break;
					case 208: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 4; break;
					case 212: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 5; break;
					case 216: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 6; break;
					case 220: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 7; break;
					case 224: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 8; break;
					case 228: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 9; break;
					case 232: tlf_counter++; tlf_number[2]=tlf_number[1]; tlf_number[1]=tlf_number[0]; tlf_number[0] = 0; break;
					case 236: tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0; break;
					default: tlf_counter = 0; presto=0; presto_ring = 0; presto_time = 0; break;
				}

			unStateBMD155.stateBMD155.loopPI = tlf_number[0];
			unStateBMD155.stateBMD155.demPI = (unsigned)tlf_number[1]*10+(unsigned)tlf_number[0];
			unStateBMD155.stateBMD155.statePI = tlf_number[1];

				if(tlf_counter>=2) 
				{
					if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == unEmb2TypeVer.emb2TypeVer.signature_software[1]) // = self_tlf_number
					{
						presto = 1;
						presto_time = 0;
						presto_ring = 0;
						ring_counter = 0;
					}
					else
					{
						if(((unsigned)tlf_number[1]*10+(unsigned)tlf_number[0]) == 99) 
						{
							presto = 2;
							presto_time = 0;
							presto_ring = 0;
							ring_counter = 0;
						}
					}
					for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
					tlf_counter=0;
				}
			}

			if(presto)
			{
				if((!presto_ring)&&(time1-presto_time>2000))
				{
					presto_ring = 1;
					presto_time = time1;
					ring_counter++;
					if(ring_counter>7) 
					{
						presto=0;
						presto_ring = 0;
						presto_time = 0;
						Wait();
					}
				}
				else
				{
					if(time1-presto_time<1400) 
					{
						Ring();
					}
					else 
					{
						presto_ring = 0;
						if(presto==1) Pause();
						else Pause2();
					}
				}
			}
		}
	}
}
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
void main()
{
//	outportb(0x6FF,inportb(0x6FF)|0x10);


///////  Канал транзит  ///////
//	time5=0;
//	outportb(0x5B7, 0x94);
///////////////////////////////
	unEmb4AvtFrequMode = (UnEmb4AvtFrequMode far*)0x80001000;

	tBuffEmbMsgWest.Init();
	tBuffEmbMsgEast.Init();
	rBuffEmbMsg.Init();
	tBuffEmbMsg485.Init();

	ctrlRandMode=0;
	randMasterMode=1;
	frequRandPd=0xFF;
	frequRandPm=0xFF;

	ResetWatchDog();

	embSerialACT155.Init();
	embRS232.Init(384);		// Инициализация RS232 на скорость 38400 кбит/с
	embRS485.Init(384);		// Инициализация RS485 на скорость 38400 кбит/с
///////////////////////////////////////////////////////////////////////////////
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);
//////////////////////
	InitTLF();
//	Ring();
	for(tlf_counter=0; tlf_counter<6; tlf_counter++) tlf_number[tlf_counter] = 0xFF;
	tlf_counter=0;

	InitTypeVer();
///////  Включаем канал транзит 0x95 - 0x00  ///////
///////  "конец" 0x95 - 0x01
//	while(time5<12); // 10 ms
//	outportb(0x5B7, 0x00);
////////////////////////////////////////////////
	Enable(); // Разрешаем все прерывания

	embMsgTemp.Init();

	Wait();
//	Ring();
	presto_time = time1;
	trunk = 0;
	
	for(i=0; i<2; i++)
	{
		frequSelfPd[i] = 0xFF;
		frequSelfPm[i] = 0xFF;
	}
	unEmb2PSMode.emb2PSMode.fpd1 = 0;
	unEmb2PSMode.emb2PSMode.fpm1 = 0;
	unEmb2PSMode.emb2PSMode.fpd2 = 0;
	unEmb2PSMode.emb2PSMode.fpm2 = 0;

	while(1)
	{
	 ResetWatchDog();
///////// Режим случайного выбора частот /////////
	if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1) RandFrequ();

/////////  Плата интерфейсов  ///////////
	unsigned temp1, temp2;
// 526-527	Счётчик ошибок после комбинатора	16 бит
// 528-52A	Счётчик ошибок, исправленных РС в 1 стволе	24 бит
// 52B-52D	Счётчик ошибок, исправленных РС в 2 стволе	24 бит
// 52E-52F	Счётчик ошибок не исправленных РС в 1 стволе	16 бит
// 530-531	Счётчик ошибок не исправленных РС в 2 стволе	16 бит
// 532-533	Счётчик числа принятых пакетов	16 бит

	err_tmp = (unsigned)inportb(0x526) + ((unsigned)inportb(0x527)<<8);
	if(err_tmp>=count_no_correct_result) unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result;
	else unStateBMD155.stateBMD155.count_no_correct_result = err_tmp - count_no_correct_result + 0x10000;
	count_no_correct_result = err_tmp;
	unStatePUM.statePUM.ulErrOut = err_tmp;
//	if(err_tmp>=count_no_correct_result) count_no_correct_result = err_tmp - count_no_correct_result;
//	else count_no_correct_result = count_no_correct_result - err_tmp;

	err_tmp = (unsigned)inportb(0x532) + ((unsigned)inportb(0x533)<<8);
	if(err_tmp>=count_block) unStateBMD155.stateBMD155.count_block = err_tmp - count_block;
	else unStateBMD155.stateBMD155.count_block = err_tmp - count_block + 0x10000;
	count_block = err_tmp;
	unStatePUM.statePUM.ulBlock = err_tmp;
//	if(err_tmp>=count_block) count_block = err_tmp - count_block;
//	else count_block = count_block - err_tmp;

	err_tmp = (unsigned)inportb(0x52E) + ((unsigned)inportb(0x52F)<<8);
	if(err_tmp>=count_notRS1)	unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1;
	else unStateBMD155.stateBMD155.count_notRS1 = err_tmp - count_notRS1 + 0x10000;
	count_notRS1 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS1 = err_tmp;
//	if(err_tmp>=count_notRS1)  count_notRS1= err_tmp - count_notRS1;
//	else count_notRS1 = count_notRS1 - err_tmp;

	err_tmp = (unsigned)inportb(0x530) + ((unsigned)inportb(0x531)<<8); 
	if(err_tmp>=count_notRS2) unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2;//count_notRS2;
	else unStateBMD155.stateBMD155.count_notRS2 = err_tmp - count_notRS2 + 0x10000;
	count_notRS2 = err_tmp;
	unStatePUM.statePUM.ulErrAfterRS2 = err_tmp;
//	if(err_tmp>=count_notRS2) count_notRS2 = err_tmp - count_notRS2;
//	else count_notRS2 = count_notRS2 - err_tmp;

	err_tmp = (unsigned)inportb(0x528) + ((unsigned)inportb(0x529)<<8) + ((unsigned long)inportb(0x52A)<<16);
	if(err_tmp>=count_no_correct_block1) unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1;
	else unStateBMD155.stateBMD155.count_no_correct_block1 = err_tmp - count_no_correct_block1 + 0x1000000;
	count_no_correct_block1 = err_tmp;
	unStatePUM.statePUM.ulErrBeforeRS1 = err_tmp;
//	if(err_tmp>=count_no_correct_block1) count_no_correct_block1 = err_tmp - count_no_correct_block1;
//	else count_no_correct_block1 = count_no_correct_block1 - err_tmp;

	err_tmp = (unsigned)inportb(0x52B) + ((unsigned)inportb(0x52C)<<8) + ((unsigned long)inportb(0x52D)<<16);
	if(err_tmp>=count_no_correct_block2) unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2;
	else unStateBMD155.stateBMD155.count_no_correct_block2 = err_tmp - count_no_correct_block2 + 0x1000000;
	count_no_correct_block2 = err_tmp; 
	unStatePUM.statePUM.ulErrBeforeRS2 = err_tmp;
//	if(err_tmp>=count_no_correct_block2) count_no_correct_block2 = err_tmp - count_no_correct_block2;
//	else count_no_correct_block2 = count_no_correct_block2 - err_tmp;
	UpdatePUNInfo();


//////////////////////////////////////////////////
	CheckTLF();
//////////////////////////////////////////////////
		old_ready_transit=ready_transit;
		old_ready_mod=ready_mod;
//////////////////////////////////////////////////
		ProtocolFromModACT155();
		ProtocolFromTransitACT155();
		Check2InitTransitMod();
		if(unEmb4AvtFrequMode->emb4AvtFrequMode.type==1) CheckPower();
//////////////////////////////////////////////////
		i232=0;
//		embRS485.Trans((unsigned char)'e');

		if(tBuffEmbMsg485.Used()&&(time1-time485>100))
		{
			time485 = time1;
			EmbMsg msg285temp;
			tBuffEmbMsg485.Get(msg285temp);
			embRS485.Trans(0x55);
			embRS485.Trans(0xAA);
			for(i=0; i<msg285temp.FullSize(); i++) 
			{
				switch(msg285temp.body[i])
				{
					case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
					case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
					case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
					case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
					default: embRS485.Trans(msg285temp.body[i]);
				}
			}
			embRS485.Trans(0x55);
		}
		while(embRS232.UsedReceive())
		{

			byte = embRS232.Receive();
			switch(byte)
			{
			case 0x55: 
				embMsg232.Init();
				embRS232.Trans(0x55);
				break; 
			case 0xAA: embMsg232.Init(); break; // Пакет
				//			case 0xA5: break; // Маркеров здесь нет!
			case 0x5A: mode5A=1; break;
			default:
				if(mode5A) 
				{
					embMsg232.Add(Modify5A(byte));
					mode5A=0;
				}
				else embMsg232.Add(byte);
			}
			if(embMsg232.IsEnd()) 
				break;
			if(++i232>10) break;
		}

		if(!embMsg232.IsEnd())
		{
			while(embRS485.UsedReceive())
			{
				byte = embRS485.Receive();
				switch(byte)
				{
				case 0x55: embMsg485.Init(); break; 
				case 0xAA: embMsg485.Init(); break; // Пакет
					//			case 0xA5: break; // Маркеров здесь нет!
				case 0x5A: mode5A=1; break;
				default:
					if(mode5A) 
					{
						embMsg485.Add(Modify5A(byte));
						mode5A=0;
					}
					else embMsg485.Add(byte);
				}
				if(embMsg485.IsEnd()) 
				{
					if(embMsg485.AddrS()==embMsg485.AddrR())
					{
						// ->>	// Ответ в RS-232
							aI = embMsg485.AddrI();
							aS = embMsg485.AddrS();
							aR = embMsg485.AddrR();
							embMsg485.SetAddrI(aR);
							embMsg485.SetAddrS(aI);
							embMsg485.SetAddrR(aS);
							embRS232.Trans(0x55);
							embRS232.Trans(0xAA);
							for(i=0; i<embMsg485.FullSize(); i++) 
							{
								switch(embMsg485.body[i])
								{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsg485.body[i]);
								}
							}
							embRS232.Trans(0x55);
					}
					
					if(embMsg485.AddrR()!=embMsg485.AddrS())
					{
						if(embMsg485.AddrS()==SelfID())
						{

						// ->>	// Транзитом ответ в линию
							if(embMsg485.TOM()&0x01)
							{
								aI = embMsg485.AddrI();
								aS = embMsg485.AddrS();
								aR = embMsg485.AddrR();
								embMsg485.SetAddrI(aS);
								embMsg485.SetAddrS(aR);
								embMsg485.SetAddrR(aI);
								tBuffEmbMsgEast.Add(embMsg485);
								tBuffEmbMsgWest.Add(embMsg485);
								unEmb2NetStat.emb2NetStat.selfPacketSend++;							
							}
							else
							{
								// ->>	// Получили запрос из RS-485
								flagRequest=3;
								embMsg485.SetRS485();
								embMsgRequest = &embMsg485;
							}
						}
					}
				}
				break;
			}
		}
///////////////////////////////
///   Формирование ответа   ///
///////////////////////////////
			if(embMsg232.IsEnd())//&&embMsg.ChkCRC())
			{
				{
				  embMsgRequest = &embMsg232;
					flagRequest=1;
				}
			}
			else
			{
				if(rBuffEmbMsg.Used())
				{
					EmbMsg embMsgA;
					embMsgA.Init();
					rBuffEmbMsg.Get(embMsgA);

					if(embMsgA.TOM()&0x01)
					{
						if(embMsgA.TOM()&0x20)
						{
							if(embMsgA.AddrS()==SelfID())//или равен 0000 или FFFF
							{
										
								embRS232.Trans(0x55);
								embRS232.Trans(0xAA);
								for(i=0; i<embMsgA.FullSize(); i++) 
								{
									switch(embMsgA.body[i])
									{
									case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
									case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
									case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
									case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
									default: embRS232.Trans(embMsgA.body[i]);
									}
								}
								embRS232.Trans(0x55);
								flagRequest = 0;
							}
						}
					}
					else
					{
						if(embMsgA.AddrI()!=embMsgA.AddrS())
						{
							if(embMsgA.AddrS()==SelfID())
							{
								flagRequest=2;
								embMsgRequest = &embMsgA;
							}
						}
					}
				}
			}

			if(flagRequest)//embMsgRequest->IsEnd())
			{
				if((embMsgRequest->AddrS()==0)||(embMsgRequest->AddrS()==SelfID()))
					// &&(embMsgRequest->TOM()|0x01))
				{
					embMsgAns.Init();
					embMsgAns.SetTOM(0x21);
					if(embMsgRequest->IsRS485()) 
					{
						if(flagRequest!=3)
						{
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgRequest->SetAddrI(aS);
							embMsgRequest->SetAddrS(aR);
							embMsgRequest->SetAddrR(aI);
							
							embRS485.Trans(0x55);
							embRS485.Trans(0xAA);
							for(i=0; i<embMsgRequest->FullSize(); i++) 
							{
								switch(embMsgRequest->body[i])
								{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgRequest->body[i]);
								}
							}
							embRS485.Trans(0x55);
							flagRequest = 0;
						}
						else
						{
							embMsgAns.SetRS485();
							aI = embMsgRequest->AddrI();
							if(embMsgRequest->AddrS()) aS = embMsgRequest->AddrS();
							else aS = SelfID();
							aR = embMsgRequest->AddrR();
							embMsgAns.SetAddrI(aR);
							embMsgAns.SetAddrS(aI);
							embMsgAns.SetAddrR(aS);
						}
					}
					else
					{
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(embMsgRequest->AddrI());					
					}
					switch(embMsgRequest->Type())
					{
					case 0x01: // запрос типа
						embMsgAns.SetType(0x01);
						embMsgAns.SetLength(44);
						for(i=0; i<44; i++) embMsgAns.SetBody(i,unEmb2TypeVer.byte[i]);
						break;
					case 0x05: // Загрузка файла (запись в устройство) 
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>						ul2uc.uc[0] = embMsg.Body(0);
						ul2uc.uc[0] = embMsgRequest->Body(0);
						ul2uc.uc[1] = embMsgRequest->Body(1);
						ul2uc.uc[2] = embMsgRequest->Body(2);
						ul2uc.uc[3] = embMsgRequest->Body(3);
						addrRAM = (unsigned char far *)ul2uc.ul;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						shift = ui2uc.ui;
						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						len = ui2uc.ui;
						temp_crc=0;
						for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);
						ui2uc.uc[0] = embMsgRequest->Body(len+8);
						ui2uc.uc[1] = embMsgRequest->Body(len+9);
						if(ui2uc.ui==temp_crc) for(i=0; i<len; i++) *(addrRAM+i+shift)= embMsgRequest->Body(i+8);
						/// формируем ответ ///
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());
						embMsgAns.SetType(0x05);
						embMsgAns.SetLength(10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(8,ui2uc.uc[0]);
						embMsgAns.SetBody(9,ui2uc.uc[1]);
						break;
/*					case 0x06:	//Выгрузка файла (чтение из устройства)
//	Запрос: <Адрес в памяти/32><смещение/16><N длина фрагмента/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
						/// формируем ответ ///
						ul2uc.uc[0] = embMsgRequest->Body(0);
						ul2uc.uc[1] = embMsgRequest->Body(1);
						ul2uc.uc[2] = embMsgRequest->Body(2);
						ul2uc.uc[3] = embMsgRequest->Body(3);
						addrRAM = (unsigned char far *)ul2uc.ul;
						ui2uc.uc[0] = embMsgRequest->Body(4);
						ui2uc.uc[1] = embMsgRequest->Body(5);
						shift = ui2uc.ui;
						ui2uc.uc[0] = embMsgRequest->Body(6);
						ui2uc.uc[1] = embMsgRequest->Body(7);
						len = ui2uc.ui;
						temp_crc=0;
						embMsgAns.SetTOM(0x20);
						embMsgAns.SetAddrI(SelfID());
						embMsgAns.SetAddrS(SelfID());						
						embMsgAns.SetType(0x06);
						embMsgAns.SetLength(len+10);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						embMsgAns.SetBody(3,embMsgRequest->Body(3));
						embMsgAns.SetBody(4,embMsgRequest->Body(4));
						embMsgAns.SetBody(5,embMsgRequest->Body(5));
						embMsgAns.SetBody(6,embMsgRequest->Body(6));
						embMsgAns.SetBody(7,embMsgRequest->Body(7));
						for(i=0; i<len; i++)
						{
							temp_crc += *(addrRAM+i+shift);
							embMsgAns.SetBody(i+8,*(addrRAM+i+shift));
						}
						ui2uc.ui=temp_crc;
						embMsgAns.SetBody(len+8,ui2uc.uc[0]);
						embMsgAns.SetBody(len+9,ui2uc.uc[1]);*/
						break;
					case 0x08: // Запрос состояния
						embMsgAns.SetType(0x08);
						embMsgAns.SetLength(72);
						for(i=0; i<72; i++) embMsgAns.SetBody(i,unStateBMD155.byte[i]);
						unStateBMD155.stateBMD155.count_block=0;
						unStateBMD155.stateBMD155.count_no_correct_block1=0;
						unStateBMD155.stateBMD155.count_no_correct_block2=0;
						unStateBMD155.stateBMD155.count_no_correct_result=0;
						unStateBMD155.stateBMD155.count_notRS1=0;
						unStateBMD155.stateBMD155.count_notRS2=0;
						unStateBMD155.stateBMD155.demPI=0;
						unStateBMD155.stateBMD155.loopPI=0;
						unStateBMD155.stateBMD155.statePI=0;
						break;
/*					case 0x09:
						if(embMsgRequest->Body(1)<=0x10)
						{
							if(embMsgRequest->Body(0)==1)
							{
								send1[0]=embMsgRequest->Body(1);
								send1[1]=embMsgRequest->Body(2);
							}
							if(embMsgRequest->Body(0)==2)
							{
								send2[0]=embMsgRequest->Body(1);
								send2[1]=embMsgRequest->Body(2);
							}
						}
						else
						{
							switch(embMsgRequest->Body(1))
							{
							case 0x11: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFD)|0x02);
								else outportb(0x583,inportb(0x583)&0xFD);
								break;
							case 0x12: 
								if(embMsgRequest->Body(2)) outportb(0x583,(inportb(0x583)&0xFE)|0x01);
								else outportb(0x583,inportb(0x583)&0xFE);
								break;
							}
						}
						embMsgAns.SetType(0x09);
						embMsgAns.SetLength(3);
						embMsgAns.SetBody(0,embMsgRequest->Body(0));
						embMsgAns.SetBody(1,embMsgRequest->Body(1));
						embMsgAns.SetBody(2,embMsgRequest->Body(2));
						break;*/
					case 0x0A:
							outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
							embMsgAns.SetType(0x0A);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,embMsgRequest->Body(4));
							embMsgAns.SetLength(5);
						break;
					case 0x0B:
							inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
							embMsgAns.SetType(0x0B);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,0);
							embMsgAns.SetBody(3,8);
							embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
							embMsgAns.SetLength(5);
						break;
/*						case 0x0D:
							embMsgAns.SetType(0x0D);
							embMsgAns.SetLength(34);
							for(i=0; i<34; i++) embMsgAns.SetBody(i,unEmb2NetStat.byte[i]);
							unEmb2NetStat.emb2NetStat.markerTime = 0;
							unEmb2NetStat.emb2NetStat.buffModPm = 0;
							unEmb2NetStat.emb2NetStat.buffTransPm = 0;
							unEmb2NetStat.emb2NetStat.buffModPd = 0;
							unEmb2NetStat.emb2NetStat.buffTransPd = 0;
							unEmb2NetStat.emb2NetStat.buff232Pm = 0;
							unEmb2NetStat.emb2NetStat.buff232Pd = 0;
							unEmb2NetStat.emb2NetStat.ready_transit=0;
							unEmb2NetStat.emb2NetStat.ready_mod=1;
						break;*/
					case 0x13:
							embMsgAns.SetType(0x13);
							embMsgAns.SetBody(0,embMsgRequest->Body(0));
							embMsgAns.SetBody(1,embMsgRequest->Body(1));
							embMsgAns.SetBody(2,embMsgRequest->Body(2));
							embMsgAns.SetBody(3,0);
							embMsgAns.SetLength(4);
							addr1 = (embMsgRequest->Body(2)<<8) +	embMsgRequest->Body(1);
							bt = (unsigned char far*)0x80000000;
							if(embMsgRequest->Body(0)) *(bt + addr1)= embMsgRequest->Body(3);
							else embMsgAns.SetBody(3, *(bt + addr1));
						break;
					case 0x14: // Запрос состояния
							embMsgAns.SetType(0x14);
							embMsgAns.SetLength(42);
							for(i=0; i<42; i++) embMsgAns.SetBody(i,unStatePUM.byte[i]);
						break;
					case 0x17:
							embMsgAns.SetType(0x17);
							embMsgAns.SetLength(4);		
							for(i=0; i<4; i++) embMsgAns.SetBody(i,unEmb2PSMode.byte[i]);
						break;
					}
					embMsgAns.SetCycle(cycle++);
					embMsgAns.CalcCRC();

					if(flagRequest == 1) 
					{
						embRS232.Trans(0x55);
						embRS232.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS232.Trans(0x5A); embRS232.Trans(0x00); break;
								case 0x55: embRS232.Trans(0x5A); embRS232.Trans(0x01); break;
								case 0xA5: embRS232.Trans(0x5A); embRS232.Trans(0x02); break;
								case 0xAA: embRS232.Trans(0x5A); embRS232.Trans(0x03); break;
								default: embRS232.Trans(embMsgAns.body[i]);
							}
						}
						embRS232.Trans(0x55);

						flagRequest = 0;
					}

					if(flagRequest == 3) 
					{
						embRS485.Trans(0x55);
						embRS485.Trans(0xAA);
						for(i=0; i<embMsgAns.FullSize(); i++) 
						{
							switch(embMsgAns.body[i])
							{
								case 0x5A: embRS485.Trans(0x5A); embRS485.Trans(0x00); break;
								case 0x55: embRS485.Trans(0x5A); embRS485.Trans(0x01); break;
								case 0xA5: embRS485.Trans(0x5A); embRS485.Trans(0x02); break;
								case 0xAA: embRS485.Trans(0x5A); embRS485.Trans(0x03); break;
								default: embRS485.Trans(embMsgAns.body[i]);
							}
						}
						embRS485.Trans(0x55);

						flagRequest = 0;
					}
				}
				else
				{
					if(flagRequest == 1) 
					{
//						if((ready_transit)||(ready_mod))
						{
							tBuffEmbMsgEast.Add(embMsg232);
							tBuffEmbMsgWest.Add(embMsg232);
							unEmb2NetStat.emb2NetStat.selfPacketSend++;
						}
					}
					else
						embMsg232.Init();
				}
		
				if(flagRequest == 2) 
				{
					// поставить в буффер на передачу в сеть в соответствии с dir
//					if((ready_transit)||(ready_mod))
					{
						tBuffEmbMsgEast.Add(embMsgAns);
						tBuffEmbMsgWest.Add(embMsgAns);
						unEmb2NetStat.emb2NetStat.selfPacketSend++;
					}
				}
				flagRequest = 0;
				embMsgRequest = NULL;
			}

	}
}