//#ifndef __TINY__
//#define __TINY__
//#endif
#include "start.h"
#include "hello7.h"
#include "embisr.h"
 



unsigned char ascii[] = {
//0:
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xD5,0xDA,
0x20,0x20,0x32,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//32:
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x20,
//64:
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x20,0x5d,0x5e,0x20,
//96
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
//
//128:
0x20,0x20,0x27,0x20,0xca,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0xca,0xcb,0xdf,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
//160:
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xfd,0xa2,0x20,0x20,0xc8,0x20,0x2d,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0xfe,0xdf,0xb5,0x20,0x20,0xc9,0x20,0x20,0x20,0x20,
//192:
0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,0xa8,
0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
//224:
0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,0xbe,
0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,0xc1,0xe6,0xc2,0xc4,0x62,0xc5,0xc6,0xc7
//256
};
//port

void AsciiInit()
{
//0
for(int i = 0; i <= 14; i++)
{
 ascii[i] = 0x20;
}
ascii[15] = 0xD5;  ascii[16] = 0xDA; 

//16
ascii[17] = 0x20;	 ascii[18] = 0x20;	 ascii[19] = 0x32;
for(i = 20; i <= 33; i++)
{
 ascii[i] = 0x20;
}
for(i = 32; i <= 62; i++)
{
 ascii[i] = (i - 1);
}
 ascii[63] = 0x20;

for(i = 64; i <= 91; i++)
{
 ascii[i] = (i - 1);
}
ascii[92] = 0x20;	 ascii[93] = 0x5d;	 ascii[94] = 0x5e;	 ascii[95] = 0x20;
//96
for(i = 96; i <= 127; i++)
{
 ascii[i] = (i - 1);
}
//128
for(i = 128; i <= 129; i++)
{
 ascii[i] = 0x20;
}
ascii[130] = 0x27;	 ascii[131] = 0x20;	ascii[132] = 0xca;

for(i = 133; i <= 146; i++)
{
 ascii[i] = 0x20;
}

ascii[147] = 0xca; ascii[148] = 0xcb; ascii[149] = 0xdf;

for(i = 150; i <= 166; i++)
{
 ascii[i] = 0x20;
}

ascii[167] = 0xfd; ascii[168] = 0xa2;

for(i = 169; i <= 170; i++)
{
 ascii[i] = 0x20;
}
ascii[171] = 0xc8; ascii[172] = 0x20; ascii[173] = 0x2d;

for(i = 174; i <= 181; i++)
{
 ascii[i] = 0x20;
}

ascii[182] = 0xfe; ascii[183] = 0xdf; ascii[184] = 0xb5;

for(i = 185; i <= 186; i++)
{
 ascii[i] = 0x20;
}
ascii[187] = 0xc9;

for(i = 188; i <= 191; i++)
{
 ascii[i] = 0x20;
}
//192
ascii[192] = 0x41;	ascii[193] = 0xa0;	 ascii[194] = 0x42;	 ascii[195] = 0xa1;	
ascii[196] = 0xe0;	ascii[197] = 0x45;	 ascii[198] = 0xa3;	 ascii[199] = 0xc4;
ascii[200] = 0xa5;  ascii[201] = 0xa6;	 ascii[201] = 0x4b;	 ascii[203] = 0xa7;
ascii[204] = 0x4d;	ascii[205] = 0x48;	 ascii[206] = 0x4f;  ascii[207] = 0xa8;

ascii[208] = 0x50;	ascii[209] = 0x43;	 ascii[210] = 0x54;	 ascii[211] = 0xa9;
ascii[212] = 0xaa;	ascii[213] = 0x58;	 ascii[214] = 0xe1;	 ascii[215] = 0xab;
ascii[216] = 0xac;	ascii[217] = 0xe2;	 ascii[218] = 0xad;	 ascii[219] = 0xae;	 
ascii[220] = 0x62;	ascii[221] = 0xaf;	 ascii[222] = 0xb0;	 ascii[223] = 0xb1;
//224
ascii[224] = 0x61;	ascii[225] = 0xb2;	 ascii[226] = 0xb3;	 ascii[227] = 0xb4;
ascii[228] = 0xe3;  ascii[229] = 0x65;	 ascii[230] = 0xb6;	 ascii[231] = 0xb7;
ascii[232] = 0xb8;	ascii[233] = 0xb9;	 ascii[234] = 0xba;	 ascii[235] = 0xbb;
ascii[236] = 0xbc;	ascii[237] = 0xbd;	 ascii[238] = 0x6f;	 ascii[239] = 0xbe;

ascii[240] = 0x70;	ascii[241] = 0x63;	 ascii[242] = 0xbf;	 ascii[243] = 0x79;
ascii[244] = 0xe4;	ascii[245] = 0x78;	 ascii[246] = 0xe5;	 ascii[247] = 0xc0;
ascii[248] = 0xc1;	ascii[249] = 0xe6;	 ascii[250] = 0xc2;	 ascii[251] = 0xc4;	
ascii[252] = 0x62;	ascii[253] = 0xc5;	 ascii[254] = 0xc6;	 ascii[255] = 0xc7; 

}



union UL2UC
{
	unsigned long ul;
	unsigned char uc[4];
};

union UI2UC
{
	unsigned long ui;
 //	unsigned char uc[2];
	unsigned char uc[4];
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

struct EmbMsg485
{
	unsigned char readyToSend;
	unsigned short counter;
	unsigned char body[64];

	unsigned char Addr()	{	return body[0];	 }
	unsigned char Length() {	return body[1];	 }
	unsigned short CRC() {	return body[body[1]+2]+1; }
	unsigned char Body(int i) { return body[i+2]; }

	void SetAddr(unsigned char byte) { body[0]=byte|0x10; }
	void SetLength(unsigned char byte) { body[1]=byte;	}
	void SetBody(int i, unsigned char byte) { body[i+2]=byte; }

	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 64-counter; }
	int short IsEnd();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned char IsReadyToSend() { return readyToSend; }	
	void SetReadyToSend() { readyToSend=1; }
};

void EmbMsg485::Init()
{
	counter=0;
	readyToSend=0;
  for(int i=0; i<64; i++) body[i]=0;
}

unsigned short EmbMsg485::Add(unsigned char byte)
{
  if(counter<64)
	{
		body[counter++]=byte;
	}
	else
	  return 0;
}

int short EmbMsg485::IsEnd()
{
  if(counter>2)
		if(counter==Length()+3)
			return 1;
	return 0;
} 

unsigned short EmbMsg485::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}

unsigned short EmbMsg485::CalcCRC()
{
  int i;
	unsigned short c=0;
	if(Length()<64) 
	{
		for(i=0; i<Length()+2; i++) c += body[i];
		body[Length()+2]=c+1;
		return c+1;
	}
	else return 0;
} 

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
	unsigned short counter;
	unsigned char body[270];
// Start/8	TOM/8	Cycle/8	AddrI/16	AddrS/16	Type/8	Length/16	 BODY/ Length	CRC/16	Blank/8
	unsigned char TOM()	{ return body[0]; }
	unsigned char Cycle()	{ return body[1]; }
	unsigned short AddrI()	{	return body[3] + (body[2]<<8);	 }	// 2
	unsigned short AddrS()	{	return body[5] + (body[4]<<8);	 }		// 2
	unsigned short AddrR()	{	return body[10] + (body[9]<<8);	 }		// 2
	void SetAddrI(unsigned short word) { body[3]=word&0xFF; body[2]=(word>>8)&0xFF;	}
	void SetAddrS(unsigned short word) { body[5]=word&0xFF; body[4]=(word>>8)&0xFF;	}
	void SetAddrR(unsigned short word) { body[10]=word&0xFF; body[9]=(word>>8)&0xFF;	}

	void SetRS485() { UnTOM unTOM; unTOM.byte = body[0]; unTOM.tom.R=1; body[0] = unTOM.byte; }
	unsigned char IsRS485() { UnTOM unTOM; unTOM.byte = body[0]; if(unTOM.tom.R) return 1; return 0; }
	void SetType(unsigned char byte) { body[6]=byte; }
	void SetLength(unsigned short word) { if(IsRS485()) word+=2; body[8]=word&0xFF; body[7]=(word>>8)&0xFF;	}


	unsigned char Type()	{ return body[6]; }		// 1
	unsigned short Length() {	return body[8] + (body[7]<<8);	 }			// 2
	unsigned short FullSize(); 			// 2
//	unsigned CRC() {	if(Length()<256) return body[Length()+1] + (body[Length()]<<8);	else return 0; }
//	unsigned short CRC() {	if(Length()<256) return body[Length()+10] + (body[Length()+9]<<8);	else return 0; }
	unsigned short CRC() {	if(Length()<256) return body[Length()+12] + (body[Length()+11]<<8);	else return 0; }
	unsigned char Body(int i) { if(IsRS485()) return body[i+11]; else return body[i+9]; }
	unsigned char BodyR(int i) { return body[i+11]; }

	void SetTOM(unsigned char byte) { body[0]=byte; }
	void SetCycle(unsigned char byte) { body[1]=byte; }


	void SetBody(int i, unsigned char byte) { if(IsRS485()) body[i+11]=byte; else body[i+9]=byte; }
	void SetBodyR(int i, unsigned char byte) { body[i+11]=byte; }

//	void SetCRC() { if(Length()<256) { body[Length()+1]=CalculateCRC()&0xFF; body[Length()]=(CalculateCRC()>>8)&0xFF; }

	void Init();
	unsigned short Add(unsigned char byte);
	unsigned short Used() { return counter; }
	unsigned short IsFree() { return 270-counter; }
	int short IsEnd();
	int short IsEndOfHeader();
	unsigned short ChkCRC();
	unsigned short CalcCRC();
	unsigned short ReCalcCRC();
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

unsigned short EmbMsg::FullSize() 
{	
	if(Length()<256) return Length() + 13;	 
//101210	else return counter;
	else return 0; //101210 to do not resend bad messages
}

unsigned short EmbMsg::Add(unsigned char byte)
{
  if(counter<270)
	{
		body[counter++]=byte;
		return 1;
	}
	else
	  return 0;
}

int short EmbMsg::IsEnd()
{
	if(body[0])
		if(counter>10)
			if(counter==Length()+13)
				return 1;
	return 0;
}

int short EmbMsg::IsEndOfHeader()
{
  if(counter==9) return 1;
	if(counter>9) return 2;
	return 0;
}
/*
unsigned short EmbMsg::ChkCRC()
{
	if(CRC()==CalcCRC()) return 1;
	else return 0;
}
 */
unsigned short EmbMsg::ChkCRC()
{
  int i;
	unsigned short c=0, b=0;
 //	if(typeOfProtocol==2)
   //	{
		if(Length()<=256) 
		{
			for(i=0; i<Length()+11; i++) c += body[i];
			b = CRC();
	 //		printfp("\n\r b:");
	 //		printfpd("%X", b);
	 //		printfp("\n\r c:");
	 //		printfpd("%X", c);
	
			if(b==c) return 1;
			else return 0;
		}
   //	}
	else return 0;
}


unsigned short EmbMsg::CalcCRC()
{
  int i;
	unsigned short c=0;
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
    unsigned short BuffSize;
    unsigned short Head;
    unsigned short Tail;
    EmbMsg Buff[16];
  public:
    void Init();
    void Add(EmbMsg&);
    void Get(EmbMsg&);
    unsigned short Used();
    unsigned short Free();
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

unsigned short EmbMsgBuffer::Used()
{
  int short n = Head - Tail;
  if( n >= 0 ) return n;
  else return n+BuffSize;
}

unsigned short EmbMsgBuffer::Free()
{
  int n = Tail - Head;
  if( n > 0 ) return n;
  else return n+BuffSize;
}


struct Emb2TypeVer
{
	unsigned short type;
	unsigned short softVer;
	unsigned short ctrlNumber;
	unsigned short ctrlYear;
	unsigned short ctrlVer1;
	unsigned short ctrlVer2;
	unsigned char signature_hardware[16];
	unsigned char signature_software[16];
};

union UnEmb2TypeVer
{
	Emb2TypeVer emb2TypeVer;
	unsigned char byte[44];
};


struct StateDev
{
   unsigned char byte[DEV_INFO_SIZE];
};

StateDev statedev[DEVCONFIG_QUANTITY];

//________________________________________________________________<< new
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

////////////////////////
	EmbTimer embTimer;
////////////////////////


#ifdef RS485_MSG_BUFF

	   EmbMsgBuffer tBuffRS485;
	   unsigned long time_lastsend_rs485;
	   unsigned char flag_wait_rs485;
#endif



//___________________________________________________________________need init!!!
unsigned long time1=0,time2=0,time3=0,time4=0,time5=60;
unsigned char flagADUC1=0, flagADUC2=0;

//______________________________________________________________added of  me
 UL2UC ul2uc;
 UI2UC ui2uc;
 unsigned short temp_crc;
 unsigned char * addrRAM;
 unsigned long shift;
 unsigned long len;

//____________________________________________________________<< added of me

void Callback0()
{
  time1++;
  time2++;
  time3++;
  time4++;
  time5++;
}

//--------------------------------------------------
	EmbTimerCallback embTimerCallback0;

	EmbMsg embMsg;
	EmbMsg embMsgAns;
    EmbMsg embMsg485F; //usart1 from tuts
	EmbMsg embMsg485E; //for ethernet
	EmbMsg485 embMsg485Request;
	unsigned char ss=0;
	EmbMsg *embMsgRequest;
	EmbRS232 embRS232;	//usart0
	EmbRS485 embRS485;	//usart1
	EmbMsg embMsg232;	 //added 090406
	unsigned short aI, aS, aR;	  //added 090406
	unsigned char mode5A485;    //added 090406
	unsigned char mode5A485E;    //added 090406

	UL2UC ul2uc;
	UI2UC ui2uc;
	char ch;
	long f_len;

//___________________________________________________________________need init!!!!
	unsigned char flagRequest=0;
	unsigned char stemp, serr=0xFF, crc_temp=0;
	unsigned long i=0;
	unsigned long time1old=0, time2old=0;
	unsigned char flagsend; //101203
	unsigned long time1old485;
	unsigned char request1=0, request2=0;
 //	unsigned long time3Marker=0, time3BlankTransit=0, time3BlankMod=0;
	unsigned char powerInFar[9];
	unsigned char flag_start_power = 0, powerInBuff[4];
  //	unsigned char markerWest=0, markerEast=0, ready_transit=0, ready_mod=0, dir=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
  //	unsigned char old_ready_transit=0, old_ready_mod=0; // 0 - "Transit->Mod", 1 - "Mod->Transit"
	unsigned char delete_msgWest=0, delete_msgEast=0, recieveWest=0, recieveEast=0;
	unsigned countSend=0, countRecv=0;
	unsigned long time3highID=0;
	char s1[25],s2[25];

	unsigned char send1[16];
	unsigned char send2[16];
 //	unsigned char err_ppu1, tst_ppu1; 
 //	unsigned char err_ppu2, tst_ppu2; 
	unsigned char byte;//, westByte, eastByte; 
	unsigned char mode5A=0, mode5AWest=0, mode5AUp1=0, mode5AUp2=0, mode5AEast=0; 
	unsigned char cycle=0;
	unsigned char i232=0, iTrans=0, iMod=0;
	unsigned char ans1=0, ans2=0, addr485=0;
	unsigned char cur_req_pointer;
	unsigned char cur_req_addr;
	unsigned char cur_ans_pointer;
	unsigned char cur_rem_pointer;

	unsigned char cur_req_quantity;
	unsigned char devans[DEVCONFIG_QUANTITY];
	unsigned char devstate[DEVCONFIG_QUANTITY];
	UnEmb2TypeVer unEmb2TypeVer; 
	UnEmb2NetStat unEmb2NetStat;
	long count_block;
	long count_no_correct_block1;
	long count_no_correct_block2;
	long count_no_correct_result;

	long count_notRS1;
	long count_notRS2;
	long err_tmp;
	unsigned short addr1;
	unsigned char  *bt;

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
void SaveFile()
{
						//  <Адрес в флэш-памяти/32><Фрагмент файла/Nх8>
						//	Передача файла.
//	Фрагмент: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><Тело фрагмента/Nх8><CRC/16>
//	Ответ: <Адрес в памяти/32><смещение/16><N длина фрагмента/16><CRC фрагмента/16>						ul2uc.uc[0] = embMsg.Body(0);
	ul2uc.uc[0] = embMsgRequest->Body(0);
	ul2uc.uc[1] = embMsgRequest->Body(1);
	ul2uc.uc[2] = embMsgRequest->Body(2);
	ul2uc.uc[3] = embMsgRequest->Body(3);
  //	addrRAM = (unsigned char far *)ul2uc.ul;
//t	addrRAM = (unsigned char *)ul2uc.ul;
   	addrRAM = (unsigned char *)(NVRAM_BASE);

	ui2uc.uc[0] = embMsgRequest->Body(4);
	ui2uc.uc[1] = embMsgRequest->Body(5);
	ui2uc.uc[2] = 0;
	ui2uc.uc[3] = 0;

	shift = ui2uc.ui;
	ui2uc.uc[0] = embMsgRequest->Body(6);
	ui2uc.uc[1] = embMsgRequest->Body(7);
	ui2uc.uc[2] = 0;
	ui2uc.uc[3] = 0;

	len = ui2uc.ui;
	temp_crc=0;
	for(i=0; i<len; i++) temp_crc += embMsgRequest->Body(i+8);
	ui2uc.uc[0] = embMsgRequest->Body(len+8);
	ui2uc.uc[1] = embMsgRequest->Body(len+9);
	ui2uc.uc[2] = 0;
	ui2uc.uc[3] = 0;

	if(ui2uc.ui==temp_crc) for(i=0; i<len; i++) *(addrRAM+i+shift)= embMsgRequest->Body(i+8);
	/// формируем ответ ///
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
}


#define PARAMETERS_DISPLACEMENT (0x1000)
#define PARAMETERS_DISPLACEMENT1 (0x1100)


extern "C" void SavePortsFromNVRAM()
{
	unsigned char  *bt;
 	bt = (unsigned char *)(NVRAM_BASE);

	outportb(0x501 ,*(bt + PARAMETERS_DISPLACEMENT + 0x1));
	outportb(0x502 ,*(bt + PARAMETERS_DISPLACEMENT + 0x2));
	outportb(0x503 ,*(bt + PARAMETERS_DISPLACEMENT + 0x3));

	outportb(0x512 ,*(bt + PARAMETERS_DISPLACEMENT + 0x12));
	outportb(0x513 ,*(bt + PARAMETERS_DISPLACEMENT + 0x13));
	outportb(0x514 ,*(bt + PARAMETERS_DISPLACEMENT + 0x14));
	outportb(0x515 ,*(bt + PARAMETERS_DISPLACEMENT + 0x15));

	outportb(0x520 ,*(bt + PARAMETERS_DISPLACEMENT + 0x20));
	outportb(0x521 ,*(bt + PARAMETERS_DISPLACEMENT + 0x21));
	outportb(0x522 ,*(bt + PARAMETERS_DISPLACEMENT + 0x22));
	outportb(0x523 ,*(bt + PARAMETERS_DISPLACEMENT + 0x23));
	outportb(0x524 ,*(bt + PARAMETERS_DISPLACEMENT + 0x24));
	outportb(0x525 ,*(bt + PARAMETERS_DISPLACEMENT + 0x25));

//#ifdef PROG_PU_M_MUX
	 outportb3(0x37 ,*(bt + PARAMETERS_DISPLACEMENT1 + 0x37));
	 for(long i = 0; i < 0x10; i++)
	 {
	  outportb3((0x90 + i) ,*(bt + PARAMETERS_DISPLACEMENT1 + 0x90 + i));
	 }
//#endif //PROG_PU_M_MUX

}

extern "C" void SaveParameterToNVRAM(unsigned long current_port, unsigned char parameter)
{
  unsigned char  *bt;
  bt = (unsigned char *)(NVRAM_BASE);
  if((current_port >= 0x501) && (current_port <= 0x525))
  {
 //  printEthLongHex(parameter);
	*(bt + PARAMETERS_DISPLACEMENT + (current_port - 0x500)) = parameter;
  }
//#ifdef PROG_PU_M_MUX
  if((current_port < 0x100))
  {
	*(bt + PARAMETERS_DISPLACEMENT1 + current_port) = parameter;
  }
//#endif //PROG_PU_M_MUX
}

							  


void WritePort()
{
			outportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8), embMsgRequest->Body(4));
			SaveParameterToNVRAM(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8) , embMsgRequest->Body(4));
			embMsgAns.SetType(0x0A);
			embMsgAns.SetBody(0,embMsgRequest->Body(0));
			embMsgAns.SetBody(1,embMsgRequest->Body(1));
			embMsgAns.SetBody(2,0);
			embMsgAns.SetBody(3,8);
			embMsgAns.SetBody(4,embMsgRequest->Body(4));
			embMsgAns.SetLength(5);
}

void ReadPort()
{
 			inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8));
			embMsgAns.SetType(0x0B);
			embMsgAns.SetBody(0,embMsgRequest->Body(0));
			embMsgAns.SetBody(1,embMsgRequest->Body(1));
			embMsgAns.SetBody(2,0);
			embMsgAns.SetBody(3,8);
			embMsgAns.SetBody(4,inportb(embMsgRequest->Body(0)+(embMsgRequest->Body(1)<<8)));
			embMsgAns.SetLength(5);
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////  M A I N  //////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//void main()

int rrr=0;
unsigned countUD1=0;
unsigned countUD2=0;

unsigned long ErrResSNMP;
unsigned char start_count;
unsigned char NeedWriteID;

unsigned long ch1ok, ch2ok, ch1bad, ch2bad, ansnum;
unsigned char Packet[32];

#ifdef USE_USART2
EmbRS232 embRS232S;


EmbMsg485 embMsg232S;

unsigned char mode5AS;
unsigned long time1old232S;
EmbMsg485 embMsg485RequestS;
#endif // USE_USART2


extern "C" void SetTestConfig()
{
                  Setudevconfig(0,1);		//1 device
				  Setudevconfig(1,0);		//rezerv
				  Setudevconfig(2,2);		//addr = 1 101117	   type = 2
				  Setudevconfig(3,1);		//upc type = 2 101117	addr = 1
                  SetNeedWriteDevId();
}
#define PACKET_SIZE	(31) //0....31
extern "C" unsigned char CheckPacket(unsigned char * packet)
{
 unsigned char checksum;
 checksum = 0;
 for(long i = 0; i < (PACKET_SIZE); i++)	  //
 {
  checksum += packet[i];
 }
  checksum += 1;
  if(checksum == packet[PACKET_SIZE])
  {
  	 return 1;
  }
  else
  {
   	return 0;
  }
}

 extern "C" void Init_UPS()
{
 unsigned char tmp;



 ch1ok = 0l;
 ch2ok = 0l;
 ch1bad = 0l;
 ch2bad = 0l;
 ansnum = 0l;

  NeedWriteID = 0;
 for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
  devans[in] = 0;
  devstate[in] = 0;
   for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
  }


//__________________________________________________101108
ans1=0; 
 ans2=0;
 embMsg485Request.Init();
// addr485=1;
 ss=0;
 
#ifdef RS485_MSG_BUFF
	   tBuffRS485.Init();
	   time_lastsend_rs485 = 0;
	   flag_wait_rs485 = 0;
#endif //RS485_MSG_BUFF


#ifdef USE_RS125
 parse_status = 0l;
 rs125_send_timer = 0l;
for(im = 0; im < PERIOD_OF_KEEP; im++)
{
 oct_res_sub[im] = 0;
 oct_tr_sub[im] = 0;
 oct_res_ser[im] = 0;
 oct_tr_ser[im] = 0;
 }
#endif //


ErrResSNMP = 0l;
start_count = 0;
//_______________________________________________
// mode5A232E = 0;
 mode5A485E = 0;
 mode5A485 = 0;
//________________________________________________
 flagRequest=0;
 serr=0xFF;
 crc_temp=0;
 i=0;
 time1old=0;
 time1old485 = 0;
 time2old=0;
 flagsend = 0; //101203
 request1=0;
 request2=0;
 countSend=0;
 countRecv=0;
 time3highID=0;
 mode5A=0;
 cycle=0;
 i232=0;
 iTrans=0;
 iMod=0;
 ans1=0;
 ans2=0;
 addr485=0;
 cur_req_pointer = 0;
 cur_req_quantity = 0;


//________________________________________________

AsciiInit();
EmbInit();	 //embrs232 embrs485

//__________________________________________________<< init _tlf

//void InitMain()
//{

	unEmb2NetStat.emb2NetStat.allPacketRecv=0;	// +
	unEmb2NetStat.emb2NetStat.genMarker=0;			// +
	unEmb2NetStat.emb2NetStat.highID=0;         // +
	unEmb2NetStat.emb2NetStat.requestMarker=0;  // +
	unEmb2NetStat.emb2NetStat.selfPacketRecv=0; // +
	unEmb2NetStat.emb2NetStat.selfPacketSend=0; // +
	unEmb2TypeVer.emb2TypeVer.softVer    = SOFT_VER;  //add suppourt protocol	rs232 from ethernet protocol 888
 //	unEmb2TypeVer.emb2TypeVer.type       = 0x0010;
	unEmb2TypeVer.emb2TypeVer.type       = 0x0403;	 //110411
	unEmb2TypeVer.emb2TypeVer.ctrlNumber = SelfID();
	unEmb2TypeVer.emb2TypeVer.ctrlYear   = SelfYear();

#ifndef COUNT_BUFF_ERR
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = SelfVer1();
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = SelfVer2();
#else
	unEmb2TypeVer.emb2TypeVer.ctrlVer1   = 0;
	unEmb2TypeVer.emb2TypeVer.ctrlVer2   = 0;
#endif

	for(i=0; i<16; i++)
	{
		unEmb2TypeVer.emb2TypeVer.signature_software[i] = 0;
		unEmb2TypeVer.emb2TypeVer.signature_hardware[i] = 0;
	}

	tmp =  read_nvram_char(RESTARTS_NVRAM_ADDRESS);
	write_nvram_char(RESTARTS_NVRAM_ADDRESS, (tmp + 1));


 //	bt = (unsigned char far*)0x80000000;
	bt = (unsigned char *)(NVRAM_BASE);


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
//}

	 embMsg.Init();
	 embMsgAns.Init();
     embMsg485F.Init();	 //added 090406
	 embMsg232.Init();	 //added 090406
	embTimer.Init(10); // *0,1 ms темп следования прерываний от таймера
	embTimerCallback0.callback = &Callback0;
	embTimerCallback0.interval = 1; // вызов функции 1 раз за N срабатываний таймера
	embTimerCallback0.count = 0;
	embTimer.SetCallBack0(&embTimerCallback0);

#ifdef USE_USART2
 mode5AS = 0;
 Set_Usart2_To_RS485();
 time1old232S = 0l;
 embMsg485RequestS.Init();

#endif // USE_USART2
//110411_____________________
        Setudevconfig(0,1);		//1 device
		Setudevconfig(1,0);		//rezerv
		Setudevconfig(2,2);		//addr = 1 101117	   type = 2
		Setudevconfig(3,1);		//upc type = 2 101117	addr = 1
//___________110411

} //add this

extern "C" void SetNeedWriteDevId(void)
{

  NeedWriteID = 1;
}


extern "C" void ClearNeedWriteDevId(void)
{

  NeedWriteID = 0;
}

extern "C" unsigned char GetNeedWriteDevId(void)
{

  return NeedWriteID;
}



extern "C" void UPS()
{

   if(GetNeedWriteDevId())
		   {
	   //	   printf("\n\r Write!!"); //t
			 WriteDevId();
			 ClearNeedWriteDevId();
		   }

//////////////////////////////////////////////////
		i232=0;
#include ups_remote1.c

#ifdef USE_USART2
 Remote_PRM_PCHS();
#endif
}
//}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : emb_use_irq0(void)
* Returned Value   : none
* Comments         :
*    This routine is used to use irq0
*END*----------------------------------------------------------------------*/
extern "C" void emb_use_irq0()
{

#ifdef IncEmbSerialACT155
 //	  Stephany19++; 
  //   embSerialACT155.IsrXX();
 IntFlag |= INT0_FLAG;
#endif // IncEmbSerialACT155

// if(InterruptWatchDog < (unsigned long)INTERRUPT_WAIT)
// {
//   InterruptWatchDog++;
   my_int_enable_irq0();
// }

}

/*FUNCTION*-------------------------------------------------------------------
* 
* Function Name    : time_notify_core(void)
* Returned Value   : none
* Comments         :
*    This routine is used to port embisr to be called from timer isr
*END*----------------------------------------------------------------------*/

extern "C" void time_notify_core(void)	// called frequency = 1 ms
 {
// hier need call EmbTimer::IsrXX for any exemplar, declared as type EmbTimer
    embTimer.IsrXX();
	TimerCounter ++;

//_________________________________________
//    TimerISR();
//_________________________________________


 } 


//#ifdef PROG_BMD155
extern  "C" unsigned long TypeVer(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.type;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.softVer;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long CtrlNumberS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlYear;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlNumber;
//ret = 0x12345678;
return ret;
}

extern  "C" unsigned long CtrlVerS(void)
{
static unsigned long ret;
ret =  (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer1;
ret <<=16;
ret += (unsigned long)unEmb2TypeVer.emb2TypeVer.ctrlVer2;
//ret = 0x12345678;
return ret;
}	  
  /*
#ifdef COUNT_BUFF_ERR

extern "C" unsigned long GetCounter1()
{ 
 return unEmb2TypeVer.emb2TypeVer.ctrlVer1;
}

extern "C" unsigned long GetCounter2()
{ 
 return unEmb2TypeVer.emb2TypeVer.ctrlVer2;
}

 
#endif

 */
//__________________________________________________usart2
#ifdef USE_USART2

extern "C" void Remote_PRM_PCHS(void)
{
//////////////////////////////////////////////////
//char cntbuff = 0;

//______________________________________EDIK
while(embRS232S.UsedReceive())
  {
  	byte = embRS232S.Receive();
	if(GetTestMode() == 0x50)
      				{
                		printfp("-");
               			printfpd("%02X",byte);
      				}        
    switch(byte)
	 {
	 	case 0xAA: embMsg232S.Init(); stemp++; break; // Пакет
	 	case 0x5A: mode5AS=1; break;
	 	default:
	 	if(mode5AS) 
			{
				embMsg232S.Add(Modify5A(byte));
				mode5AS=0;
			}
	     	else embMsg232S.Add(byte);
			}
		 if(embMsg232S.IsEnd())
			{
                
           if((embMsg232S.Addr() > DEVCONFIG_QUANTITY) || (!embMsg232S.Addr())) break;
            if(GetTestMode() == 0x50)
				{ 
     					printfp("\n\r");
				}     
           cur_ans_pointer = GetDevPointer(embMsg232S.Addr());
        if(cur_ans_pointer != BAD_POINTER)
            {
           		devans[embMsg232S.Addr() - 1] = 0;
             	devstate[embMsg232S.Addr() - 1] = 1; 
            for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[embMsg232S.Addr() - 1].byte[i] = embMsg232S.Body(i);  //addr from 1 to 16
       			if(GetTestMode() == 0x50)
      				{
                		printfp("_");
               			printfpd("%X",embMsg232S.body[i]);
      				}               
             }	//for
           }  //if ! bad pointer
		}	//Is end
} //while
 
         if(time1-time1old232S > PUMV485_REQUEST_DELAY) //t
		{
		 //	send41++;
			if(embMsg485RequestS.IsReadyToSend())
			{
 				time1old232S = time1;

   	
			   embRS232S.Trans2(0xFF);
				embRS232S.Trans2(0xAA);
				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
					case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
					case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
					case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
					default: embRS232S.Trans2(embMsg485RequestS.body[i]);
					}
				}
		   	    embMsg485RequestS.Init();
			   }  //is ready
			else
			{
				time1old232S = time1;
				ss++;
  //          SendTraceRequest();
            cur_req_quantity = GetDevQuantity();
            if(cur_req_quantity)   //not zero
            {
               if(cur_req_pointer >= cur_req_quantity) //pointer get from zero and quantity used from one
               {
                 cur_req_pointer = 0;
               }
            cur_req_addr = GetDevAddr(cur_req_pointer);
            if((cur_req_addr <= DEVCONFIG_QUANTITY) && cur_req_addr)    
            {
            devans[cur_req_addr - 1]++;   //addresses 1...16 devans 0 ... 15
               
            embMsg485RequestS.Init();
      //t      embMsg485Request.SetAddr(cur_req_addr);
            embMsg485RequestS.SetAddr(1);    //t
				embMsg485RequestS.SetLength(1);
				embMsg485RequestS.SetBody(0,0x00);
				embMsg485RequestS.CalcCRC();
            
		      embRS232S.Trans2(0xFF);
				embRS232S.Trans2(0xAA);
			        if(GetTestMode() == 0x50)
					{           
             			printfp("\n\r");
 					}    
     
  				for(i=0; i<embMsg485RequestS.Length()+3; i++) 
				{
					switch(embMsg485RequestS.body[i])
					{
					case 0x5A: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x00); break;
					case 0x55: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x01); break;
					case 0xA5: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x02); break;
					case 0xAA: embRS232S.Trans2(0x5A); embRS232S.Trans2(0x03); break;
					default: embRS232S.Trans2(embMsg485RequestS.body[i]);
       						if(GetTestMode() == 0x50)
							{
                				printfp(".");
               					printfpd("%X", embMsg485RequestS.body[i]);
							}               
					}
				}
            
               } //correct addr
			embMsg485RequestS.Init();
            cur_req_pointer++;
            } 	//cur_req_quantity
		}	//not ready
}	 //time
      
////////////////////////////////////////////////
	 //	if(ans1>=200)
    
  for(long in = 0; in < DEVCONFIG_QUANTITY; in++)
  {
   if(devans[in] > MAX_NOT_ANSWERS_Q)
   {
      devstate[in] = 0;
     for(i = 0; i < DEV_INFO_SIZE; i++)
            {
             statedev[in].byte[i] = 0; 
            }
   }         
  }

    
   /////////////////////////////////////////////////	UPP



//______________________________________EDIK

											 
}


//__________________________________________________usart2
#endif



#ifdef PD_DS

extern "C" void  ParseCommand1()
{
  //	 add_char_TCP_buff(TYPE_AUTO);

add_char_TCP_buff(0x01);
add_char_TCP_buff(0x00);
add_char_TCP_buff(0xff);
add_char_TCP_buff(0xff);





	 for(long i = 0; i < 44; i++)
	 {
	   add_char_TCP_buff(unEmb2TypeVer.byte[i]);
	 }
   //	 breakflag =1; 
}


#define	PD_C2_SIZE (2) //for test
extern "C" void  ParseCommand2(char *IPBuff)
{

unsigned wd = 10000l;

while(embRS232S.UsedReceive()) //clear buffer
  {
  	byte = embRS232S.Receive();
 //	  add_char_TCP_buff(byte);
  }


	add_char_TCP_buff(0x02);
	add_char_TCP_buff(0x00);
	add_char_TCP_buff(0xff);
	add_char_TCP_buff(0xff);

  //	for(unsigned i=0; i< BACO_SIZE; i++)
	for(unsigned i=0; i< PD_C2_SIZE; i++)
   	    {
	   //	    cbaco.byte[i] = IPBuff[i+4];   //
	      embRS232S.Trans2(IPBuff[i+4]);

    	}
  //	CfgCardBaco();
  //	KeepCBaco();
    OperateBuffers_usart2t();


//while((wd--))
//  {
delay_mcs(10000);

  OperateBuffers_usart2();
 // }

while(embRS232S.UsedReceive())
  {
  	byte = embRS232S.Receive();
	add_char_TCP_buff(byte);
  }



  // add_char_TCP_buff(0x00);

	  
}



#endif