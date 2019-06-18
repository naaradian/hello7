#define EMB



/*port 
const MEMORY_HEAP	= 8192;
const MAX_SET       = 53;
const MAX_VIEW      = 32;
*/
//need INIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// #define MEMORY_HEAP	 (8192)
#define MEMORY_HEAP	 (30000)
#define MAX_SET      (53)
#define MAX_VIEW     (32)
//________________________________________________________________
void StopCapture(void);
int start_ktvm(void);
unsigned char GetMode(void);
void SetMode(unsigned char);
void SetVideoIn(unsigned char);
void SetStopKadr(unsigned char);
unsigned char GetSound(void);
void SetSound(unsigned char);
unsigned char GetVideoIn(void);
void SetVideoIn(unsigned char);
unsigned char GetStopKadr(void);
unsigned char GetStat(void);
extern unsigned char en_sts;
//________________________________________________________________

void* AllocMemory(int size);
int FreeMemory(void *o);

extern "C" unsigned char inportb_dir(unsigned long );
extern "C" unsigned short inport_dir(unsigned long );
extern "C" void outportb_dir(unsigned long , unsigned char);



extern "C" void outport(unsigned int , unsigned char );	  //in autodetect so use xilinx

extern "C" void outportb(unsigned int , unsigned char );
	  
extern "C" unsigned char inportb(unsigned int );
 //make as empty
extern "C" unsigned short inport(unsigned int);

 /* port
typedef unsigned char BYTE;
typedef unsigned short WORD; //port
//typedef unsigned  WORD; //
typedef unsigned long DWORD;
  */
//char* char2int(WORD* r,char* str,int* err);
/*	port
const typeAggregate = 0;
const typeBOOL = 1;
const typeBIT_2 = 2;
const typeBIT_3 = 3;
const typeBIT_4 = 4;
const typeBIT_5 = 5;
const typeBIT_6 = 6;
const typeBIT_7 = 7;
const typeBYTE  = 8;
const typeWORD  = 9;
const typeFUNC = 10;
const typeSTRING= 11;
*/
 
#define  typeAggregate  (0)
#define  typeBOOL   	(1)
#define  typeBIT_2  	(2)
#define  typeBIT_3  	(3)
#define  typeBIT_4  	(4)
#define  typeBIT_5  	(5)
#define  typeBIT_6  	(6)
#define  typeBIT_7  	(7)
#define  typeBYTE   	(8)
#define  typeWORD   	(9)
#define  typeFUNC   	(10)
#define  typeSTRING 	(11)


///////  From PS  ////////
//port int BitSet(int index,void *val,BYTE addr,void far* body);
int BitSet(int index,void *val,BYTE addr,void * body);
/*
void FuncSelector(char *funcName)
{
  

}
*/

union DBYTE
{
  unsigned char b[2];
//port   unsigned int i;
  unsigned short int i;	 //port
};

class EmbTree;
class EmbSet;

struct EmbAccessType
{
	unsigned short access : 2; // 0-not-accessible, 1-read-only, 2-write-only, 3-read-write
	unsigned short type   : 6; 
};								

struct EmbAddr
{
	unsigned long BaseAddr    : 32;			   //long -my
	unsigned long Offset	  : 32; // 0...16383  - адрес регистра		 long - my
	unsigned long Bit        : 32; //  0...7			- адрес бита
};

class EmbParameter
{
	public:		
		EmbAccessType accessType;
		EmbAddr addr;
		WORD    body;

		int Set(WORD);
		int Update(void);
	   //	  int Update();
	  		int Action();

		WORD Get(){return body;}
		   
		void Init(int Access,int Type,unsigned long Base,unsigned long OffsetAddr,int BitAddr)
		{
			accessType.access = Access;
			accessType.type = Type;
			addr.BaseAddr = Base;
			addr.Offset = OffsetAddr;
			addr.Bit = BitAddr;
			body=0;
		}

		void SetAccess(int a) { accessType.access = a; }
		void SetType(int t) { accessType.type = t; }
	//	void SetAddrBase(int a) { addr.BaseAddr = a; }
		void SetAddrBase(unsigned long a) { addr.BaseAddr = a; }
	  //	void SetAddrOffset(int a) { addr.Offset = a; }
		void SetAddrOffset(unsigned long a) { addr.Offset = a; }
		void SetAddrBit(int t) { addr.Bit = t; }
		int Type() { return accessType.type; }
		int Equal(WORD);
		int Less(WORD);
		int Greate(WORD);
};

union EmbWord
{
	WORD i;
	BYTE c[2];
};

union EmbDWord
{
	DWORD l;
	BYTE c[4];
};
//////////////////////////
class EmbSetItem
{
	friend EmbTree;
	friend EmbSet;
		int name;
		int value;
	public:
//		EmbSetItem() { Clear(); }
		void Clear() { name=value=0; }
		int Name() { return name; }
		int Value() { return value; }
};

class EmbSet
{
/* port
	friend EmbTree;
	  int basic_type;
		int name;
		int numItem;
		EmbSetItem *setItem;
	public:
//		EmbSet() { Clear(); } 
		void Clear() { numItem=0; setItem=0; }
		int Basic_Type() { return basic_type; }
		int NumItem() { return numItem; }
		EmbSetItem *SetItem(int i) { return setItem+i; }
		*/
   friend EmbTree;
	public:	 //port
	    short int basic_type;
		short int name;
		short int numItem;
		EmbSetItem *setItem;
 //port	public:
//		EmbSet() { Clear(); } 
		void Clear() { numItem=0; setItem=0; }
		short int Basic_Type() { return basic_type; }
		short int NumItem() { return numItem; }
		EmbSetItem *SetItem(int i) { return setItem+i; }


};

class EmbViewPos
{
	friend EmbTree;
		int name;
		BYTE x;
		BYTE y;
		int prefix;
	public:
//		EmbViewPos() { name=0; x=y=0; }
		void Clear() { name=0; x=y=0; }
		void Init(int n, BYTE ix, BYTE iy);
		int Name() { return name; }
		int Prefix() { return prefix; }
		BYTE X() { return x; }
		BYTE Y() { return y; }
};

struct TypeOfView
{
	int alarm		 : 2;	// none = 0; "=" = 1; "<" = 2; ">" = 3;
	int level		 : 6; // Level 0 - 64
	int hide		 : 1;	// if true hide ON, else OFF
	int pos			 : 5; // number of ViewPos, 0 is standart view, other pos of POPUP
	int reserved : 2; // reserved
	int value		 : 8; // Value 0...255
//	TypeOfView() { Clear(); }
	void Clear() { value=reserved=level=alarm=hide=pos=0; }
};

class EmbTreePoint
{
	protected:
	friend EmbTree;
		unsigned name;
		EmbTreePoint *parent;
		EmbTreePoint *child;
		EmbTreePoint *brotherL;
		EmbTreePoint *brotherR;
		EmbParameter parameter;
		TypeOfView typeOfView;
	public:
		EmbTreePoint *Parent() { return parent; }
		EmbTreePoint *Child() { return child; }
		EmbTreePoint *BrotherL() { return brotherL; }
		EmbTreePoint *BrotherR() { return brotherR; }
		EmbParameter *Parameter() { return &parameter; }
		int Name() { return name; }
//		EmbTreePoint() { Clear(); }
		int IsHide() {  if(typeOfView.hide) return 1; return 0; }
		int IsAlarm();
		int IsChildAlarm();
		void Clear() { parent = child = brotherL = brotherR = 0; name=0; typeOfView.Clear(); }
};

//port char far *CreateASCIIZ(char far *bytes, char far *asciiz);
//port char  * CreateASCIIZ(char far *bytes, char far *asciiz);
char  * CreateASCIIZ(char  *bytes, char  *asciiz);
struct EmbAlarmView
{
	EmbTreePoint *embTreePoint[MAX_VIEW];
	void Init();
//	EmbAlarmView() { for(int i=0; i<MAX_VIEW; i++) embTreePoint[i]=0; }
};

class EmbTree
{
 public:		 //port
  //port		unsigned char far *cfg;
	unsigned char *cfg;	 //port 
		char request[128];
		char answer[128];
		int numOfSets;
		EmbTreePoint *treePoint;
		EmbTreePoint *current;
		EmbTreePoint *comPoint;
		EmbSet *sets;
		EmbViewPos *viewPos;
		unsigned countTreePoint;
		int countSets;
		int countView;
//  ---------------
		int company;
		int city;
		int name;
		int version;
   		int date;
  //t		int base_addr;
		int baseaddr;	//t
		int numOfRegister;
//  ---------------
   //		int GetNum(int start);
		unsigned long  GetNum(int start);
		unsigned FindLex(int start, int end,char * lex);
		int FindString(int startPosTree,int size);
		int FindEndStr(int i,int end);
		int FindStartStr(int i,int end);
		int CountString(int start,int end);
		int FindNextLex(int start,int end);
		int FindNextLexEnd(int start,int end);
		int LexCmpTableSet(int start);
		int LexCmpTableView(int start);

		int GetBasicType(int start,int end);
   /* port
		int FindSizeCommand(int max,char far *command);
		int FindNextLexInCommand(int start,int end,char far *command);
		int FindNextLexEndInCommand(int start,int end,char far *command);
		int LexCmpInCommand(int start,int end,char *lex,char far *command);
   */		
    
		int FindSizeCommand(int ,char*);
		int FindNextLexInCommand(int ,int ,char*);
		int FindNextLexEndInCommand(int ,int ,char*);
		int LexCmpInCommand(int ,int ,char*,char*);
   		
		int	ReadTreePoint(int ,int,EmbTreePoint *);
		int	ReadSet(int,int ,EmbSet *);
		int	ReadViewPos(int ,int ,EmbViewPos *);
		int SetTreePointParent(int ,EmbTreePoint *);
		int SetTreePointType(int ,int ,EmbTreePoint *);
  //port:	public:
  //port		int LexCmp(int start,char far *lex);
		int LexCmp(int start,char  *lex);
//		EmbTree() {}
//		~EmbTree() {}
	  	EmbTreePoint *Current() { return current; }
	 	EmbTreePoint *Up();
		EmbTreePoint *Down();
		EmbTreePoint *Left();
	 	EmbTreePoint *Right();
   		void Enter(); // virtual ???
		unsigned CountTreePoint() { return countTreePoint; }
		int CountSets()  { return countSets; }
		EmbSet *GetSets(int i) { return sets+i; }
//  ---------------------------------------------------
		int IsParameter() { if(current) if(current->parameter.Type()) return 1; return 0; }
		int IsChildAlarm() { if(current) return current->IsChildAlarm(); else return 0; }
		EmbAlarmView* FindAlarmChild(EmbAlarmView*);
		EmbParameter GetParameter() { if(current) return current->parameter; }
		EmbViewPos *GetViewPos(int i) { if(i<MAX_VIEW) return viewPos+i; return 0; }
		char *ViewParameter(char *);
		unsigned GetParameterNum();
		int SetComParameter(char *str);
		int SetParameter(char *str);

	  //port	void SetCfg(char far * cfg, int size);
	   //	void SetCfg(char * cfg, int size);
		char SetCfg(char * cfg, int size);

		char *FullName();
		int GetNumOfTreePoint() { return countTreePoint; }
		EmbTreePoint *GetTreePoint() { return treePoint; }
//  --------------------- PS --------------------------
		void ResetComCurrent() { comPoint=treePoint; }
		void ResetCurrent() { current=treePoint; }
  	 //	void SetRequest(char far * );
		void SetRequest(char * );
  		void GetAnswer(char* m);
		int CommandDecoder();
		int Send(EmbCOM	*theCom);
		char *ViewComParameter(char *);
		int TestTypeParameter(WORD *,char *);
//  ---------------------------------------------------
//		int CommandDecoder2(char* com);
		char *GetFullCommand(EmbTreePoint *etp, char *str);
//	---------------------------------------------------
		int Company() { return company; }
		int City() { return city; }
		int Name() { return name; }
		int Version() { return version; }
		int Date() { return date; }
	//port 	int Base() { return base_addr; }
	//	int Base() { return baseaddr; }
		unsigned long Base() { return baseaddr; }

 //t  	  	virtual unsigned Inport(int port) { return inport(port); }
 //t		unsigned Inport(int port) { return inport(port); }	 //t
//	unsigned Inport(int port) { return 0x77; }	 //t
//			virtual unsigned Inport(int port) { return (unsigned)inport_dir(port); }	//port
//t	  	virtual unsigned char Inportb(int port) { return inportb(port); }

#ifndef PROG_BMD35
#ifndef PROG_PROV
#ifndef PROG_MPC35
  		 unsigned short Inport(int port) { return inport(port); }	//port
#endif //no PROG_MPC35
#endif //no PROG_BMD35
#endif //no PROG_PROV

   	 // 	unsigned char Inportb(int port) { return 0x78; }   //t
	 //	virtual unsigned char Inportb(int port) { return inportb_dir(port); } //port
		unsigned char Inportb(int);
	//port   	virtual void Outport(int port,unsigned value) { outport(port,value); }
	   	 void Outport(int port,unsigned value) { outport(port,value); }	 //port
//port		virtual void Outportb(int port, unsigned char value) { outportb(port,value); }
		void Outportb(int , unsigned char ); //port { outportb(port,value); }
	 //	virtual void Outportb(int port, unsigned char value) { outportb_dir(port,value); } //port

#ifdef PROG_BMD35
 	unsigned char rate[3];
    unsigned char rate1[3];
    unsigned char rate2[3];
    unsigned char rate3[3];

  //	public:
	unsigned long com_err1;
	unsigned long com_err2;
	unsigned long com_psp;
    unsigned long com_psp_last_read;
	unsigned long err1;
	unsigned long err2;
	void ClearErr1() { err1 = 1; }
	void ClearErr2() { err2 = 1; }
	unsigned long Err1() { return err1; }
	unsigned long Err2() { return err2; }
    unsigned Inport(int port);// { return inport(port); }
 //  unsigned char Inportb(int short port);// { return inportb(port); }
//    void Outport(int port,unsigned value) { outport(port,value); }
 //   void Outportb(int short port, unsigned char value); //{ outportb(port,value); }
    void Out(int   port, unsigned char value);
    void Init2();
    void SaveStateACT34();
    void RestoreStateACT34();

#endif //PROG_BMD35

#ifdef PROG_PROV
 	unsigned char rate[3];
    unsigned char rate1[3];
    unsigned char rate2[3];
    unsigned char rate3[3];

  //	public:
	unsigned long com_err1;
	unsigned long com_err2;
	unsigned long com_psp;
    unsigned long com_psp_last_read;
	unsigned long err1;
	unsigned long err2;
	void ClearErr1() { err1 = 1; }
	void ClearErr2() { err2 = 1; }
	unsigned long Err1() { return err1; }
	unsigned long Err2() { return err2; }
    unsigned Inport(int port);// { return inport(port); }
 //  unsigned char Inportb(int short port);// { return inportb(port); }
//    void Outport(int port,unsigned value) { outport(port,value); }
 //   void Outportb(int short port, unsigned char value); //{ outportb(port,value); }
    void Out(int   port, unsigned char value);
    void Init2();
    void SaveStateACT34();
    void RestoreStateACT34();

#endif //PROG_PROV


#ifdef PROG_MPC35
		unsigned long com_err1;
		unsigned long com_err2;
		unsigned long com_psp;
    	unsigned long com_psp_last_read;
	  	unsigned long err1;
	  	unsigned long err2;
		void ClearErr1() { err1 = 1; }
		void ClearErr2() { err2 = 1; }
		unsigned long Err1() { return err1; }
		unsigned long Err2() { return err2; }
    	unsigned Inport(int port);// { return inport(port); }
 //  		unsigned char Inportb(int port);// { return inportb(port); }
//    void Outport(int port,unsigned value) { outport(port,value); }
  //  	void Outportb(int port, unsigned char value); //{ outportb(port,value); }
#endif //PROG_MPC35



};

//#endif
extern void SetPrint(unsigned short int m,int r);
extern unsigned buff3;
extern unsigned int Ret_code;
extern void restart(void);
extern void SetE14(void);
extern void SetVideoStandart(unsigned char);
extern void spi_std(unsigned);
extern void wd_res(void);
extern void SetTestSignal(unsigned char);
extern void spi_tst(unsigned);
extern unsigned char GetVideoStandart(void);
extern unsigned char GetTestSignal(void);
extern unsigned int GetErr(void);