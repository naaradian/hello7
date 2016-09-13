#include "EMBISR.H"
#include "basic.h"	   //port

//_______________________________________________________________________
void  ltoa(long value, char *strP, int radix)
{
  //      return  __longtoa (value, strP, radix, (radix == 10), 'a');
  if(radix == 10)
  {
    sprintf(strP, "%ld",value);
  }
  else
  {
    sprintf(strP, "%lX",value);

  }

}


static char freeM[MEMORY_HEAP];
//need Init!!!!!!!!!!!!!!!!
//port static unsigned int freePtr=0;
static unsigned int freePtr=0;

void InitFreePtr(void)
{
 freePtr=0;

}

void* AllocMemory(int size)
{
	void* p;
	p=freeM+freePtr;
	freePtr+=size;
	return p;
}
int FreeMemory(void *) { return 0; }
// ------------------------  PS  ------------------------------
//port char far* StrCopy(char far *dest,char far *source)
char * StrCopy(char  *dest,char  *source)
{
	do
	{
		*dest++=*source;
	}while(*source++);
	return dest-1;
}

//port int StrCmp(char far *s,char far *l)
int StrCmp(char  *s,char  *l)
{
	int i=0;
	do
	{
		if(s[i]!=l[i]) return 0;
	}while(s[i++]);
	return 1;
}

char LowHalfByte(char s)
{
  s &= 0x0F;
	if(s<10) return s + '0';
	else return s + 'A' - 10;
}

char HighHalfByte(char s)
{
  s = (s>>4)&0x0F;
	char b = s + 'a';
	if(s<10) return s + '0';
	else return s + 'A' - 10;
}

//   ----------------------   End Of PS   --------------------------
void EmbAlarmView::Init() 
{ 
	for(int i=0; i<MAX_VIEW; i++) embTreePoint[i]=0; 
}


//char far *CreateASCIIZ(char far *lex, char far *asciiz)
char *CreateASCIIZ(char *lex, char *asciiz)
{
 	int i=0;
	while((lex[i]!=0)&&(lex[i]!=' ')&&(lex[i]!='\t')&&(lex[i]!='.')&&(lex[i]!='\n')
	&& (i < 25) //my
	)
	asciiz[i]=lex[i++];
	asciiz[i]=0;
	return asciiz;
}

//port int BitSet(int index,WORD val,BYTE addr,WORD far *body)
int BitSet(int index,WORD val,BYTE addr,WORD *body)
{
	int i;
	BYTE v,mask;
	DBYTE db;
	db.i=val;
	mask=0xfe;
	for(i=index;i;i--){ mask<<=1; mask&=0xfe; }
	mask<<=addr-1;
	v=db.b[0];
	v=(v<<(addr-1))&(mask^0xffff);
	db.b[0]&=mask;
	db.b[0]|=v;
	*body=db.i;
	return 0;
}

int EmbParameter::Set(WORD val)
{
	DBYTE db;
	if(accessType.access==1) return -1;
	if((accessType.access==2)||(accessType.access==3))
	{
		switch(accessType.type)
		{
			case typeAggregate: return -2;
			case typeBOOL:  BitSet(1,val,addr.Bit,&body); break;
			case typeBIT_2: BitSet(2,val,addr.Bit,&body); break;
			case typeBIT_3: BitSet(3,val,addr.Bit,&body); break;
			case typeBIT_4: BitSet(4,val,addr.Bit,&body); break;
			case typeBIT_5: BitSet(5,val,addr.Bit,&body); break;
			case typeBIT_6: BitSet(6,val,addr.Bit,&body); break;
			case typeBIT_7: BitSet(7,val,addr.Bit,&body); break;
			case typeBYTE:  body=val; db.i=val; break;
			case typeWORD:  body=val; db.i=val; break;
//		case typeDWORD:
			case typeSTRING: break;
		}
	}
	if(accessType.access==3)
	{
		db.i = body;
		outportb(addr.BaseAddr+addr.Offset,db.b[0]);
		if(accessType.type==typeWORD)
			outportb(addr.BaseAddr+addr.Offset+1,db.b[1]);
	}
	return 0;
}

BYTE GetBitFromByte(BYTE value, BYTE addr, BYTE num)
{
	value=value>>addr;
	switch(num)
	{
		case 0: return value;
		case 1: return value&0x01;
		case 2: return value&0x03;
		case 3: return value&0x07;
		case 4: return value&0x0F;
		case 5: return value&0x1F;
		case 6: return value&0x3F;
		case 7: return value&0x7F;
	}
	return 0;
}

BYTE SetBitIntoByte(BYTE source, BYTE value, BYTE addr, BYTE num)
{
	BYTE temp=0;
	switch(num)
	{
		case 0: temp=0x0; break;
		case 1: temp=0x01; break;
		case 2: temp=0x03; break;
		case 3: temp=0x07; break;
		case 4: temp=0x0F; break;
		case 5: temp=0x1F; break;
		case 6: temp=0x3F; break;
		case 7: temp=0x7F; break;
	}
	temp = temp<<addr;
	value = (value<<addr);
	temp = 0xFF ^ temp;
	source = source & temp;
	source = source | value;
	return source;
}

int EmbParameter::Update()
{
	DBYTE db;
	if(!accessType.access) return -1;
	if((accessType.access==1)||(accessType.access==3))
	{
   		db.b[0]=inportb(addr.BaseAddr+addr.Offset);
   //		db.b[0]=inportb_dir(addr.BaseAddr+addr.Offset);	  //port
   		if(accessType.type==typeWORD) db.b[1]=inportb(addr.BaseAddr+addr.Offset+1);
   //		if(accessType.type==typeWORD) db.b[1]=inportb_dir(addr.BaseAddr+addr.Offset+1);	  //port

		else db.b[1]=0;
		switch(accessType.type)
		{
   			case typeAggregate: return -2;
			case typeBOOL:   body=GetBitFromByte(db.b[0],addr.Bit, 1); break;
			case typeBIT_2:  body=GetBitFromByte(db.b[0],addr.Bit, 2); break;
			case typeBIT_3:  body=GetBitFromByte(db.b[0],addr.Bit, 3); break;
			case typeBIT_4:  body=GetBitFromByte(db.b[0],addr.Bit, 4); break;
			case typeBIT_5:  body=GetBitFromByte(db.b[0],addr.Bit, 5); break;
			case typeBIT_6:  body=GetBitFromByte(db.b[0],addr.Bit, 6); break;
			case typeBIT_7:  body=GetBitFromByte(db.b[0],addr.Bit, 7); break;
			case typeBYTE:   body=db.b[0]; break;
			case typeWORD:   body=db.i; break;
			case typeSTRING: break;
		}
	}
	return db.b[0];
}

int EmbParameter::Equal(WORD v)
{
	switch(Type())
	{
		case typeBOOL: case typeBIT_2: case typeBIT_3: case typeBIT_4:
		case typeBIT_5:	case typeBIT_6: case typeBIT_7: case typeBYTE: if(Get()==v) return 1; break;
		case typeWORD: if(Get()==v) return 1; break;
		default: if(Get()==v) return 1; break;
	}
	return 0;
}

int EmbParameter::Less(WORD v)
{
	switch(Type())
	{
		case typeBOOL: case typeBIT_2: case typeBIT_3: case typeBIT_4:
		case typeBIT_5:	case typeBIT_6: case typeBIT_7: case typeBYTE:
			if(Get()<v) return 1; break;
		case typeWORD: if(Get()<(WORD)v) return 1; break;
	}
	return 0;
}

int EmbParameter::Greate(WORD v)
{
	switch(Type())
	{
		case typeBOOL: case typeBIT_2: case typeBIT_3: case typeBIT_4:
		case typeBIT_5:	case typeBIT_6: case typeBIT_7: case typeBYTE:
			if(Get()>v) return 1; break;
		case typeWORD: if(Get()>v) return 1; break;
	}
	return 0;
}


int EmbTreePoint::IsAlarm()
{
	if(child==0)
	{
		if(typeOfView.alarm!=0)
		{
			switch(typeOfView.alarm)
			{
				case 1: if(parameter.Equal(typeOfView.value)) return 1; break;
				case 2: if(parameter.Less(typeOfView.value)) return 1; break;
				case 3: if(parameter.Greate(typeOfView.value)) return 1; break;
			}
		}
	}
	return 0;
}

int EmbTreePoint::IsChildAlarm()
{
	if(child)
	{
		EmbTreePoint *temp = child;
		while(temp)
		{
			if(temp->child) { if(temp->IsChildAlarm()) return 1; }
			else if(temp->IsAlarm()) return 1;
			temp = temp->brotherR;
		}
	}
	return 0;
}

EmbAlarmView* EmbTree::FindAlarmChild(EmbAlarmView* temp)
{
//	EmbAlarmView temp;
	temp->Init();
	for(int i=0; i<countTreePoint; i++)
	{
		if((treePoint+i)->IsAlarm())
		{
			if(!temp->embTreePoint[(treePoint+i)->typeOfView.pos])
				temp->embTreePoint[(treePoint+i)->typeOfView.pos] = treePoint+i;
			else
			{
				if(temp->embTreePoint[(treePoint+i)->typeOfView.pos]->typeOfView.level<(treePoint+i)->typeOfView.level)
					temp->embTreePoint[(treePoint+i)->typeOfView.pos] = treePoint+i;
			}
		}
	}
	return temp;
}

EmbTreePoint *EmbTree::Up()
{
	if(!current) return 0;
	if(current->parent) current = current->parent;	
	return current;
}

EmbTreePoint *EmbTree::Down()
{
 //0xe1a01ba1 
 // printEthLongHex((unsigned long)current);

	if(!current) return 0;
      //t
	if(current->child) 
	{
		if(current->child->IsHide()) 
		{
			EmbTreePoint *temp=current->child;
			if(temp) 
			{
				while(temp->brotherR)
				{
					temp=temp->brotherR;
					if(!temp->IsHide()) 
					{
						current = temp;
						break;
					}
				}
			}
		}
		else current = current->child;	
	}
	return current;
}

EmbTreePoint *EmbTree::Left()
{
	if(!current) return 0;
	if(current->brotherL)
 	{
		if(!current->brotherL->IsHide()) 
			current = current->brotherL;
		else 
		{
			EmbTreePoint *temp=current->brotherL;
			if(temp) 
			{
				while(temp->brotherL)
				{
					temp=temp->brotherL;
					if(!temp->IsHide()) 
					{
						current = temp;
						break;
					}
				}
				if(current!=temp)
				{
					if(current->parent)
					{
						EmbTreePoint *temp=current->parent->child;
						if(temp) 
						{
							while(temp->brotherR) temp=temp->brotherR;
							current = temp;
						}
					}
				}
			}
		}
	}
	else 
	{
		if(current->parent)
		{
			EmbTreePoint *temp=current->parent->child;
			if(temp) 
			{
				while(temp->brotherR) temp=temp->brotherR;
				current = temp;
			}
		}
	}
	return current;
}

EmbTreePoint *EmbTree::Right()
{
	if(!current) return 0;
	if(current->brotherR) 
	{
		if(!current->brotherR->IsHide()) current = current->brotherR;
		else 
		{
			EmbTreePoint *temp=current->brotherR;
			if(temp) 
			{
				while(temp->brotherR)
				{
					temp=temp->brotherR;
					if(!temp->IsHide()) 
					{
						current = temp;
						break;
					}
					if(current!=temp)
					{
						if(current->parent)
							if(current->parent->child)
								if(!current->parent->child->IsHide()) current = current->parent->child;
								else 
								{
									EmbTreePoint *temp=current->parent->child;
									if(temp) 
									{
										while(temp->brotherR)
										{
											temp=temp->brotherR;
											if(!temp->IsHide()) 
											{
												current = temp;
												break;
											}
										}
									}
								}
					}
				}
			}
		}
	}
	else 
	{
		if(current->parent)
			if(current->parent->child)
				if(!current->parent->child->IsHide()) current = current->parent->child;
				else 
				{
					EmbTreePoint *temp=current->parent->child;
					if(temp) 
					{
						while(temp->brotherR)
						{
							temp=temp->brotherR;
							if(!temp->IsHide())
							{
								current = temp;
								break;
							}
						}
					}
				}
	}
	return current;
}
#ifdef PROG_MPC35

void EmbTree::Outportb(int port, unsigned char value)
{
  unsigned char  *ctrl;
  ctrl = (unsigned char *)(NVRAM_BASE);
  port &= 0xff; //0227


  //	if(port==0x506)

  //	if(port==0x546)
	if(port  == 0x46)	//0227
  {
		if(value&0x20)
		{
		  com_err1=0;
		  com_err2=0;
     //t com_psp = com_psp - com_psp_last_read; //inport(0x518);
	  com_psp = 0; //t
		}
    psp_number = value&0x1F;
  }
//  if(port == 0x55E)
  else if(port == 0x5E) //0227
{
	  *(ctrl+85)=value;
   //	  Out(0x64E,*(ctrl+85));
   //	  Out(0,*(ctrl+85));
}
  else  if(( port >= 0x40) && (port < 0x58))	   //0227
  {
      *(ctrl + (port - 0x40)) = value;	 //0227
  //	    printf("->%X", value);

   }
		outportb(port,value);
}

unsigned EmbTree::Inport(int port)
{
 // if(port==0x518)
  if(port==0x558)
	{
		if(com_psp>0xFFFF) return 0xFFFF;
		else return 1234;//com_psp;
	}
//  if(port==0x51A)
  if(port==0x55A)
	{
		if(com_err1>0xFFFF) return 0xFFFF;
		else return 1234;//com_err1;
	}
 // if(port==0x51C)
  if(port==0x55C)
	{
		if(com_err2>0xFFFF) return 0xFFFF;
		else return 2345;//com_err2;
	}
	return 5;
 //	return inport(port);	
}

unsigned char EmbTree::Inportb(int port)
{
 // if(port==0x518)
  if(port==0x558)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF00;
	}
 // if(port==0x519)
  if(port==0x559)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF;
	}
 // if(port==0x51A)
  if(port==0x55A)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF;
	}
 // if(port==0x51B)
  if(port==0x55B)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF00;
	}
 // if(port==0x51C)
  if(port==0x55C)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF;
	}
//  if(port==0x51D)
  if(port==0x55D)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF00;
	}
	return inportb(port);	
}


#endif // PROG_MPC35

#ifdef PROG_BMD35

void EmbTree::Init2()
{
  int i=0; 
  for(i=0; i<3; i++) rate[i]=rate1[i]=rate2[i]=rate3[i]=0;
}



void EmbTree::SaveStateACT34()
{
 int i;
 unsigned char * ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
 ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
  *(ctrl+64) = Inportb(0x649);
  *(ctrl+65) = Inportb(0x64A);
  *(ctrl+66) = Inportb(0x64B);
  *(ctrl+67) = Inportb(0x64C);
  *(ctrl+68) = Inportb(0x64D);
  *(ctrl+69) = Inportb(0x64E);
  *(ctrl+70) = Inportb(0x64F);
  *(ctrl+71) = Inportb(0x650);
  *(ctrl+72) = Inportb(0x651);
  *(ctrl+73) = Inportb(0x652);
//________________________________add
  *(ctrl+85) = Inportb(0x65E);
  //*(ctrl+85) = Inportb(0);
//________________________________add

 //  printEthString("SaveStateACT34\n\r", 23);
}

void EmbTree::RestoreStateACT34()
{
	unsigned i;//, j, com;
	unsigned char * ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) outportb(0x640+i,*(ctrl+i));

  outportb(0x640,(*ctrl)&0x7F);
  Outportb(0x649,*(ctrl+64));
  Outportb(0x64A,*(ctrl+65));
  Outportb(0x64B,*(ctrl+66));
  Outportb(0x64C,*(ctrl+67));
  Outportb(0x64D,*(ctrl+68));
  Outportb(0x64E,*(ctrl+69));
  Outportb(0x64F,*(ctrl+70));
  Outportb(0x650,*(ctrl+71));
  Outportb(0x651,*(ctrl+72));
  Outportb(0x652,*(ctrl+73));
//________________________________add
  Outportb(0x65E,*(ctrl+85));
//  Outportb(0,*(ctrl+85));	//t
//________________________________add

//   printEthString("RestoreStateACT34\n\r", 23);
 //  SetProtokol((*ctrl + 64)&MASK_BIT_5); //now keep hier

}





void EmbTree::Out(int port, unsigned char value)
{
  int i=0, n=0, true_value=0, num8k=0, temp_b=0;
 	unsigned char  * ctrl;
  //t	ctrl = (unsigned char * )(NVRAM_BASE + 0x100);
	ctrl = (unsigned char * )(NVRAM_BASE);
	ctrl += 100l;
 //	unsigned char far *ctrl;
 //	ctrl = (unsigned char far*)0x80000100;
  port &= 0xff; //090302

  if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
		/*
    switch(value)
    {
      case 0: true_value=0; num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate1);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate1[i];  
        ctrl[i]=rate[i];
        ctrl[i+3]=rate1[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x010,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x020,rate1[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x021,rate1[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x022,rate1[2]); // коммутатор
    }
    else
    {
      for(i=0; i<3; i++)
      {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
      }
    }
	*/
	}
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x008,true_value); // Тип
    */	
  }
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF) 
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate2);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate2[i];  
        ctrl[i]=rate[i];
        ctrl[i+6]=rate2[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x110,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x120,rate2[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x121,rate2[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x122,rate2[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
      }
	  */
	}
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x108,true_value); // Тип
	*/
  }
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate3[i]; // сбросили предыдущую установку общей
      rate3[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {  
        SetBusy8k(n, rate);
        SetBusy8k(n, rate3);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate3[i];  
        ctrl[i]=rate[i];
        ctrl[i+9]=rate3[i];
      }
      save_e14_reg(0x510,0x511,0x51F,0x010,true_value); // Скорость
      save_e14_reg(0x510,0x511,0x51F,0x020,rate3[0]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x021,rate3[1]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x022,rate3[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
        rate[i]^=rate3[i]; // сбросили предыдущую установку общей
        rate3[i]=0;        // скорости занятой этим каналом
      }
	  */
	}
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x510,0x511,0x51F,0x008,true_value); // Тип
	*/
  }
  if(port==0x4F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	 /*
    outportb(0x507,0x94); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
		*/
	}
  if(port==0x50) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	/*
    outportb(0x507,0x84); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	  */
	}
  if(port==0x51) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[50,0]
	{
	/*
    outportb(0x507,0x95); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
	  */
	}
  if(port==0x52) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	/*
    outportb(0x507,0x85); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	  */
	}
 //___________________________________________add
// if(port==0x65E) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
  //	{
	//  outportb(0x65E,value);
	//  outportb(0, value);
 //  	}
//____________________________________________add

}




unsigned EmbTree::Inport(int port)
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 // go back return *(char *)port; //t1120
//<<<<<<<<<<<<<<<<<<<<<<<
 port &= 0xff;	   //090302
  if(port==0x58)
	{
		if(com_psp>0xFFFF) return 0xFFFF;
		else return 1234;//com_psp;
	}
  if(port==0x5A)
	{
		if(com_err1>0xFFFF) return 0xFFFF;
		else return 1234;//com_err1;
	}
  if(port==0x5C)
	{
		if(com_err2>0xFFFF) return 0xFFFF;
		else return 2345;//com_err2;
	}
  	return 5;
  //	return inport(port);	
}




unsigned char EmbTree::Inportb(int port)
{
   int i=0;
  unsigned char true_value=0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 //go back  return *(char *)port; //t1120
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   port &= 0xff; //090302
  if(port==0x58)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF00;
	}
  if(port==0x59)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF;
	}
  if(port==0x5A)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF;
	}
  if(port==0x5B)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF00;
	}
  if(port==0x5C)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF;
	}
  if(port==0x5D)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF00;
	}
/////
    if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
	 /* 090318

    switch(load_e14_reg(0x520,0x521,0x52F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;
		*/

	 return (inportb(port));
	}
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
		*/
	 
    return 1;		 //rs232
	}
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x110))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
	 */
	 return 0;
  }
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x108))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
	*/
	return 0;
  }
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
	/*
    switch(load_e14_reg(0x510,0x511,0x51F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
	   */
	return 0;
 
  }
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
	 /*
    switch(load_e14_reg(0x510,0x511,0x51F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
	*/
	return 0;
  }
  if(port==0x4F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	/*
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x01;
    if(true_value) return 1; 
    else return 0;
	*/
	 return 0;
	}
  if(port==0x50) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	/*
    outportb(0x507,0xA0); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	 */
	   return 1;
	}
  if(port==0x51) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[336,0]
	{
	/*
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x02;
    if(true_value) return 1; 
    else return 0;
	*/
	return 0;
	}
  if(port==0x52) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	 /*
    outportb(0x507,0xA1); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	*/
	return 1;
	}
/////
	  return inportb(port);	
}


void EmbTree::Outportb(int port, unsigned char value)
{

//__________________________________________________________________  temp

//for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//  *(ctrl+64) = Inportb(0x649);
//  *(ctrl+65) = Inportb(0x64A);
//  *(ctrl+66) = Inportb(0x64B);
//  *(ctrl+67) = Inportb(0x64C);
//  *(ctrl+68) = Inportb(0x64D);
//  *(ctrl+69) = Inportb(0x64E);
//  *(ctrl+70) = Inportb(0x64F);
//  *(ctrl+71) = Inportb(0x650);
//  *(ctrl+72) = Inportb(0x651);
//  *(ctrl+73) = Inportb(0x652);
//________________________________add
//  *(ctrl+85) = Inportb(0x65E);



//__________________________________________________________________   temp




 unsigned char  *ctrl;
   //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//go back   *((char *)port) = value; return; //t1120
 //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 // printEthLongHex(port);
//   printEthLongHex(value);


	port &= 0xff; //0227
 // if(port==0x646)
  if(port==0x46)
  {
		if(value&0x20)
		{
		  com_err1=0;
		  com_err2=0;
		  com_psp = com_psp - com_psp_last_read;
		}
    psp_number = value&0x1F;
  }

 // if(port==0x649) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
  if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
  {
  value &= 0x0f; //090319  !!!!!!!!!!!!!!!!!!!!!!!

 //   Out(0x649,0);
	 /* 0319
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
	   */
    *(ctrl+64)=value;

  //  Out(0x649,*(ctrl+64));
	/*	 0319
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/ 
  }
 // if(port==0x64A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
  {
  /* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    *(ctrl+65)=value;
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
  {
  /* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    *(ctrl+66)=value;
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
  {
	/* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    *(ctrl+67)=value;
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
  {
  /* 	0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    *(ctrl+68)=value;
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
  {
  /*	0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    *(ctrl+69)=value;
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64F) Out(port,value);
 // if(port==0x650) Out(port,value);
 // if(port==0x651) Out(port,value);
 // if(port==0x652) Out(port,value);
 //  if(port==0x4F) Out(port,value);

//  if(port==0x50) Out(port,value);
//  if(port==0x51) Out(port,value);
//  if(port==0x52) Out(port,value);

//if(port == 0x65E)
if(port == 0x5E)
{
	  *(ctrl+85)=value;
   //  Out(0x64E,*(ctrl+85));
   //  Out(0,*(ctrl+85));
}

// 090302
  if(( port >= 0x40) && (port < 0x58))	   //0227
  {
      *(ctrl + (port - 0x40)) = value;	 //0227
  //	    printf("->%X", value);
   }



  outportb(port,value);

}
#endif //PROG_BMD35

#ifdef PROG_PROV

void EmbTree::Init2()
{
  int i=0; 
  for(i=0; i<3; i++) rate[i]=rate1[i]=rate2[i]=rate3[i]=0;
}



void EmbTree::SaveStateACT34()
{
 int i;
 unsigned char * ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
 ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
  *(ctrl+64) = Inportb(0x649);
  *(ctrl+65) = Inportb(0x64A);
  *(ctrl+66) = Inportb(0x64B);
  *(ctrl+67) = Inportb(0x64C);
  *(ctrl+68) = Inportb(0x64D);
  *(ctrl+69) = Inportb(0x64E);
  *(ctrl+70) = Inportb(0x64F);
  *(ctrl+71) = Inportb(0x650);
  *(ctrl+72) = Inportb(0x651);
  *(ctrl+73) = Inportb(0x652);
//________________________________add
  *(ctrl+85) = Inportb(0x65E);
  //*(ctrl+85) = Inportb(0);
//________________________________add

 //  printEthString("SaveStateACT34\n\r", 23);
}

void EmbTree::RestoreStateACT34()
{
	unsigned i;//, j, com;
	unsigned char * ctrl;
  //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);

	for(i=0; i<24; i++) outportb(0x640+i,*(ctrl+i));

  outportb(0x640,(*ctrl)&0x7F);
  Outportb(0x649,*(ctrl+64));
  Outportb(0x64A,*(ctrl+65));
  Outportb(0x64B,*(ctrl+66));
  Outportb(0x64C,*(ctrl+67));
  Outportb(0x64D,*(ctrl+68));
  Outportb(0x64E,*(ctrl+69));
  Outportb(0x64F,*(ctrl+70));
  Outportb(0x650,*(ctrl+71));
  Outportb(0x651,*(ctrl+72));
  Outportb(0x652,*(ctrl+73));
//________________________________add
  Outportb(0x65E,*(ctrl+85));
//  Outportb(0,*(ctrl+85));	//t
//________________________________add

//   printEthString("RestoreStateACT34\n\r", 23);
 //  SetProtokol((*ctrl + 64)&MASK_BIT_5); //now keep hier

}





void EmbTree::Out(int port, unsigned char value)
{
  int i=0, n=0, true_value=0, num8k=0, temp_b=0;
 	unsigned char  * ctrl;
  //t	ctrl = (unsigned char * )(NVRAM_BASE + 0x100);
	ctrl = (unsigned char * )(NVRAM_BASE);
	ctrl += 100l;
 //	unsigned char far *ctrl;
 //	ctrl = (unsigned char far*)0x80000100;
  port &= 0xff; //090302

  if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
		/*
    switch(value)
    {
      case 0: true_value=0; num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate1);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate1[i];  
        ctrl[i]=rate[i];
        ctrl[i+3]=rate1[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x010,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x020,rate1[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x021,rate1[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x022,rate1[2]); // коммутатор
    }
    else
    {
      for(i=0; i<3; i++)
      {
      rate[i]^=rate1[i]; // сбросили предыдущую установку общей
      rate1[i]=0;        // скорости занятой этим каналом
      }
    }
	*/
	}
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x008,true_value); // Тип
    */	
  }
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF) 
      {
        SetBusy8k(n, rate);
        SetBusy8k(n, rate2);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate2[i];  
        ctrl[i]=rate[i];
        ctrl[i+6]=rate2[i];
      }
      save_e14_reg(0x520,0x521,0x52F,0x110,true_value); // Скорость
      save_e14_reg(0x520,0x521,0x52F,0x120,rate2[0]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x121,rate2[1]); // коммутатор
      save_e14_reg(0x520,0x521,0x52F,0x122,rate2[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
      rate[i]^=rate2[i]; // сбросили предыдущую установку общей
      rate2[i]=0;        // скорости занятой этим каналом
      }
	  */
	}
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x520,0x521,0x52F,0x108,true_value); // Тип
	*/
  }
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0;  num8k=0;  break; // 0=Off
      case 1: true_value=7;  num8k=1;  break; // 1=1200
      case 2: true_value=8;  num8k=1;  break; // 2=2400
      case 3: true_value=10; num8k=1;  break; // 3=4800
      case 4: true_value=12; num8k=2;  break; // 4=9600
      case 5: true_value=14; num8k=3;  break; // 5=19200
      case 6: true_value=15; num8k=5;  break; // 6=28800
      case 7: true_value=16; num8k=6;  break; // 7=38400
      case 8: true_value=19; num8k=8;  break; // 8=57600
      case 9: true_value=21; num8k=16; break; // 9=115200
    }
    for(i=0; i<3; i++)
    {
      rate[i]^=rate3[i]; // сбросили предыдущую установку общей
      rate3[i]=0;        // скорости занятой этим каналом
    }
    n=0;
    for(i=0; i<num8k; i++)
    {
      n=FindFree8k(n, rate);
      if(n!=0xFF)
      {  
        SetBusy8k(n, rate);
        SetBusy8k(n, rate3);
      }
    }
    if(n!=0xFF)
    {
      for(i=0; i<3; i++) // раскарячиваем коммутатор потоков 8k под нужную скорость
      {
        rate[i]|=rate3[i];  
        ctrl[i]=rate[i];
        ctrl[i+9]=rate3[i];
      }
      save_e14_reg(0x510,0x511,0x51F,0x010,true_value); // Скорость
      save_e14_reg(0x510,0x511,0x51F,0x020,rate3[0]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x021,rate3[1]); // коммутатор
      save_e14_reg(0x510,0x511,0x51F,0x022,rate3[2]); // коммутатор
    }		
    else
      for(i=0; i<3; i++)
      {
        rate[i]^=rate3[i]; // сбросили предыдущую установку общей
        rate3[i]=0;        // скорости занятой этим каналом
      }
	  */
	}
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
	/*
    switch(value)
    {
      case 0: true_value=0x00;  break; // 0=Off
      case 1: true_value=0x02;  break; // 1=RS-232
      case 2: true_value=0x05;  break; // 2=RS-485
      case 3: true_value=0x06; break; // 3=V,36
      case 4: true_value=0x0E; break; // 4=V,35
    }
    save_e14_reg(0x510,0x511,0x51F,0x008,true_value); // Тип
	*/
  }
  if(port==0x4F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	 /*
    outportb(0x507,0x94); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
		*/
	}
  if(port==0x50) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	/*
    outportb(0x507,0x84); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	  */
	}
  if(port==0x51) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[50,0]
	{
	/*
    outportb(0x507,0x95); 
 	  for(i=0; i<20000; i++);
    outportb(0x507,value&0x01);
 	  for(i=0; i<20000; i++);
	  */
	}
  if(port==0x52) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
	{
	/*
    outportb(0x507,0x85); 
 	  for(i=0; i<20000; i++);
    switch(value)
    {
      case 0: outportb(0x507,0x0A); break;
      case 1: outportb(0x507,0x14); break;
      case 2: outportb(0x507,0x1D); break;
    }
 	  for(i=0; i<20000; i++);
	  */
	}
 //___________________________________________add
// if(port==0x65E) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[40,0]
  //	{
	//  outportb(0x65E,value);
	//  outportb(0, value);
 //  	}
//____________________________________________add

}




unsigned EmbTree::Inport(int port)
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 // go back return *(char *)port; //t1120
//<<<<<<<<<<<<<<<<<<<<<<<
 port &= 0xff;	   //090302
  if(port==0x58)
	{
		if(com_psp>0xFFFF) return 0xFFFF;
		else return 1234;//com_psp;
	}
  if(port==0x5A)
	{
		if(com_err1>0xFFFF) return 0xFFFF;
		else return 1234;//com_err1;
	}
  if(port==0x5C)
	{
		if(com_err2>0xFFFF) return 0xFFFF;
		else return 2345;//com_err2;
	}
  	return 5;
  //	return inport(port);	
}




unsigned char EmbTree::Inportb(int port)
{
   int i=0;
  unsigned char true_value=0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 //go back  return *(char *)port; //t1120
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   port &= 0xff; //090302
  if(port==0x58)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF00;
	}
  if(port==0x59)
	{
    com_psp_last_read=com_psp;
		if(com_psp>0xFFFF) return 0xFF;
		else return com_psp&0xFF;
	}
  if(port==0x5A)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF;
	}
  if(port==0x5B)
	{
		if(com_err1>0xFFFF) return 0xFF;
		else return com_err1&0xFF00;
	}
  if(port==0x5C)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF;
	}
  if(port==0x5D)
	{
		if(com_err2>0xFFFF) return 0xFF;
		else return com_err2&0xFF00;
	}
/////
    if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
	{
	 /* 090318

    switch(load_e14_reg(0x520,0x521,0x52F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;
		*/

	 return (inportb(port));
	}
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
		*/
	 
    return 1;		 //rs232
	}
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x110))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
	 */
	 return 0;
  }
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
	{
	 /*
    switch(load_e14_reg(0x520,0x521,0x52F,0x108))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
	*/
	return 0;
  }
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
	{
	/*
    switch(load_e14_reg(0x510,0x511,0x51F,0x010))
    {
      case 0: true_value=0;  break; // 0=Off
      case 7: true_value=1;  break; // 1=1200
      case 8: true_value=2;  break; // 2=2400
      case 10: true_value=3; break; // 3=4800
      case 12: true_value=4; break; // 4=9600
      case 14: true_value=5; break; // 5=19200
      case 15: true_value=6; break; // 6=28800
      case 16: true_value=7; break; // 7=38400
      case 19: true_value=8; break; // 8=57600
      case 21: true_value=9; break; // 9=115200
    }
    return true_value;	
	   */
	return 0;
 
  }
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
	{
	 /*
    switch(load_e14_reg(0x510,0x511,0x51F,0x008))
    {
      case 0x00: true_value=0;  break; // 0=Off
      case 0x02: true_value=1;  break; // 1=RS-232
      case 0x05: true_value=2;  break; // 2=RS-485
      case 0x06: true_value=3; break; // 3=V,36
      case 0x0E: true_value=4; break; // 4=V,35
    }
    return true_value;
	*/
	return 0;
  }
  if(port==0x4F) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	/*
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x01;
    if(true_value) return 1; 
    else return 0;
	*/
	 return 0;
	}
  if(port==0x50) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	/*
    outportb(0x507,0xA0); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	 */
	   return 1;
	}
  if(port==0x51) // Тип			Канал_ТЛФ2.3	read-write	typeTLF	Reg[336,0]
	{
	/*
    outportb(0x507,0x9C); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    true_value&=0x02;
    if(true_value) return 1; 
    else return 0;
	*/
	return 0;
	}
  if(port==0x52) // Тип			Канал_ТЛФ1.3	read-write	typeTLF	Reg[320,0]
	{
	 /*
    outportb(0x507,0xA1); 
 	  for(i=0; i<20000; i++);
    true_value=inportb(0x507);
    switch(true_value)
    {
      case 0x0A: return 0;
      case 0x14: return 1;
      case 0x1D: return 2;
      default: return 0;
    }
	*/
	return 1;
	}
/////
	  return inportb(port);	
}


void EmbTree::Outportb(int port, unsigned char value)
{

//__________________________________________________________________  temp

//for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//	for(i=0; i<24; i++) *(ctrl+i) = inportb(0x640+i);
//  *(ctrl+64) = Inportb(0x649);
//  *(ctrl+65) = Inportb(0x64A);
//  *(ctrl+66) = Inportb(0x64B);
//  *(ctrl+67) = Inportb(0x64C);
//  *(ctrl+68) = Inportb(0x64D);
//  *(ctrl+69) = Inportb(0x64E);
//  *(ctrl+70) = Inportb(0x64F);
//  *(ctrl+71) = Inportb(0x650);
//  *(ctrl+72) = Inportb(0x651);
//  *(ctrl+73) = Inportb(0x652);
//________________________________add
//  *(ctrl+85) = Inportb(0x65E);



//__________________________________________________________________   temp




 unsigned char  *ctrl;
   //	ctrl = (unsigned char far*)0x80000000;
	ctrl = (unsigned char *)(NVRAM_BASE);
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//go back   *((char *)port) = value; return; //t1120
 //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 // printEthLongHex(port);
//   printEthLongHex(value);


	port &= 0xff; //0227
 // if(port==0x646)
  if(port==0x46)
  {
		if(value&0x20)
		{
		  com_err1=0;
		  com_err2=0;
		  com_psp = com_psp - com_psp_last_read;
		}
    psp_number = value&0x1F;
  }

 // if(port==0x649) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
  if(port==0x49) // Скорость	Канал_ПД1.1	read-write	typeRATE	Reg[10,0]
  {
  value &= 0x0f; //090319  !!!!!!!!!!!!!!!!!!!!!!!

 //   Out(0x649,0);
	 /* 0319
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
	   */
    *(ctrl+64)=value;

  //  Out(0x649,*(ctrl+64));
	/*	 0319
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/ 
  }
 // if(port==0x64A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
  if(port==0x4A) // Тип_Интерф	Канал_ПД1.2	read-write	typeType	Reg[11,0]
  {
  /* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    *(ctrl+65)=value;
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
  if(port==0x4B) // Скорость	Канал_ПД2.1	read-write	typeRATE	Reg[20,0]
  {
  /* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    *(ctrl+66)=value;
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
  if(port==0x4C) // Тип_Интерф	Канал_ПД2.2	read-write	typeType	Reg[21,0]
  {
	/* 0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    *(ctrl+67)=value;
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
  if(port==0x4D) // Скорость	Канал_ПД3.1	read-write	typeRATE	Reg[30,0]
  {
  /* 	0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    *(ctrl+68)=value;
    Out(0x64D,*(ctrl+68));
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
  if(port==0x4E) // Тип_Интерф	Канал_ПД3.2	read-write	typeType	Reg[31,0]
  {
  /*	0319
    Out(0x649,0);
    Out(0x64A,0);
    Out(0x64B,0);
    Out(0x64C,0);
    Out(0x64D,0);
    Out(0x64E,0);
    Out(0x649,*(ctrl+64));
    Out(0x64A,*(ctrl+65));
    Out(0x64B,*(ctrl+66));
    Out(0x64C,*(ctrl+67));
    Out(0x64D,*(ctrl+68));
    *(ctrl+69)=value;
    Out(0x64E,*(ctrl+69));
	*/
  }
 // if(port==0x64F) Out(port,value);
 // if(port==0x650) Out(port,value);
 // if(port==0x651) Out(port,value);
 // if(port==0x652) Out(port,value);
 //  if(port==0x4F) Out(port,value);

//  if(port==0x50) Out(port,value);
//  if(port==0x51) Out(port,value);
//  if(port==0x52) Out(port,value);

//if(port == 0x65E)
if(port == 0x5E)
{
	  *(ctrl+85)=value;
   //  Out(0x64E,*(ctrl+85));
   //  Out(0,*(ctrl+85));
}

// 090302
  if(( port >= 0x40) && (port < 0x58))	   //0227
  {
      *(ctrl + (port - 0x40)) = value;	 //0227
  //	    printf("->%X", value);
   }



  outportb(port,value);

}
#endif PROG_PROV



#ifdef PROG_KTVM
unsigned char EmbTree::Inportb(int port)
{
	switch(port)
	{	
		case 0x601: return 0;
		case 0x602: return GetMode();
		case 0x603: return GetVideoIn();
		case 0x604: return GetStopKadr();
		case 0x605: return GetSound();
		case 0x606: return GetStat();
		case 0x607: return 0;
		case 0x608: return EmbGetPoint();
		case 0x609: return EmbGetAddr();
		default: return inportb(port);	
	}
}


void EmbTree::Outportb(int port, unsigned char value)
{
 //	int i,j;
	switch(port)
	{	
		case 0x601: 
			if(value)
			{
				//				restart();
	outportb(MIRes,0x4f); // Reset on
	outportb(MIRes,0x4f); // Reset on
	outportb(MIRes,0x47); // Reset on
				StopCapture();
/*				SetPrint(en_sts,4);
			  for(i=0;i<5000;i++) wd_res(); 
*/			  
					start_ktvm();
			}
		break;
		case 0x602: 
	  //t		if(GetMode()!=value)
	  //t		{
	  //	  printf("\n\r 602 : getmode : %x  value : %x", GetMode(), value);

				StopCapture();
//				for(i=0;i<400;i++){	for(j=0;j<200;j++);	wd_res();	}
				SetMode(value);
	   			start_ktvm();
		//t	}
		break;
		case 0x603: 
			SetVideoIn(value);
//			spi_in(value);
		break;
		case 0x604: 
			SetStopKadr(value);	   //not used in menu	
//			spi_stop(value);
		break;
		case 0x605: 
			if(GetSound()!=value)
			{
				StopCapture();
				en_sts &= ~start_ok;
//				for(i=0;i<400;i++){	for(j=0;j<200;j++);	wd_res();	}
				SetSound(value);
				start_ktvm();
			}
		break;
		case 0x606: 
		break;
		case 0x607: 
		break;
		case 0x608: 
			EmbSetPoint(value);
		break;
		case 0x609: 
			EmbSetAddr(value);
		break;
		default:
	 //		lastport = port;
			outportb(port,value);
		break;
	}
}
#endif PROG_KTVM

#ifdef PROG_DTVM
void EmbTree::Outportb(int port, unsigned char value)
{
  //	int i;
 //	unsigned char oldval;
	switch(port)
	{	
		case 0x601: 
//			if(value)
			if(value & 0x80)
			{/*
				outportb(0x6FF,0x00);
				outportb(port,0x80);
				for(i=0; i<1000; i++)
				{
					outport(0xffe6,0xaaaa);
					outport(0xffe6,0x5555);
					//outportb(0x6FA,0x00);
				}
				outportb(port,0x00);
				unsigned x = inport(piodat0);
				outport(piodat0, x | 0x0001);
//				asm { db 0fah, 0eah, 0b3h,07h,00h,27h; } //версия БУ 137
				asm { db 0fah, 0eah, 0b7h,07h,00h,27h; } //версия БУ 138
				*/
//				EmbCS24.Init();
//				Enable();
 //port		    SetPrint(buff3,6);
 //port	        SetPrint(Ret_code,6);
//				printff("Mres buff=%x",buff3);
//	      if(CS24_reset_buff()){
//	      SetPrint(0,6);
		    m_load_xilinx3((char)XILINXPG, 1); //for full restart
		    restart();
//				}
			}
		break;
		case 0x602: 				  //rate
		  //	if(GetMode()!=value)
		  //	{
			  SetMode(value);
		   	  SetE14();
			  //	dtvm_init1();
		  //	}

		break;
		case 0x603: 
			 /*	   NOW not used
			SetVideoStandart(value);
			spi_std(value); for(i=1000;i;i--) wd_res();
			spi_std(value); for(i=1000;i;i--) wd_res();
			spi_std(value);
			 */
		break;
		case 0x604: 	 //now maked sound
			  /* Now not used
			SetTestSignal(value);
			spi_tst(value); for(i=1000;i;i--) wd_res();
			spi_tst(value); for(i=1000;i;i--) wd_res();
			spi_tst(value);
			*/
			    SetSound(value);
		   	   	SetE14();
		   	//	dtvm_init1();
 		break;
		case 0x605: 
			 /* Now changed
			if(GetSound()!=value)
			{
  			   SetSound(value);
			   SetE14();
			}
			*/
		  //	 oldval =  (GetTestSignal() << 1) +  GetVideoStandart();
		   //    printEthLongHex(value);
		  	   SetTestSignal((value & 0x4) >> 2);
		  	   SetVideoStandart(value & 0x1);
			   outportb(5 , value);
				
		break;
		case 0x608: 
			EmbSetPoint(value);
		break;
		case 0x609: 
			EmbSetAddr(value);
		break;
		default:
 //			lastport = port;
			outportb(port,value);
		break;
	}


}

//unsigned EmbTreeTVM::Inport(int port)

//unsigned char EmbTreeTVM::Inportb(int port)
unsigned char EmbTree::Inportb(int port)
{
	switch(port)
	{	
		case 0x601: return 0; 

		case 0x602: return GetMode();

		case 0x603: return GetVideoStandart(); 

		case 0x604: return  GetSound();// GetTestSignal();	

		case 0x605: //return GetSound();
					 return( (GetTestSignal() << 2) +  GetVideoStandart());
					 

		case 0x606: return GetStat();	 

		case 0x607: return GetErr();	  

		case 0x608: return EmbGetPoint();	

		case 0x609: return EmbGetAddr();	

		default: return inportb(port);	
	}
}

#endif //PROG_DTVM

void EmbTree::Enter()
{

}

unsigned long temp;

char EmbTree::SetCfg(char *cfg_txt,int size)
{
	unsigned i;
	unsigned startPosTree,endPosTree,currPos;
	unsigned startPosSet,endPosSet;
	unsigned startPosView,endPosView;
	unsigned startTemp,endTemp;

	i=startPosSet=endPosSet=currPos=0;
	cfg = (unsigned char *)cfg_txt;
//     printEthLongHex('3');
	startTemp = FindLex(0,size,"Company:");
 //   printEthLongHex(startTemp);
	if (startTemp > MAX_COMPANY) return 0;	//my : if dpd is not writed
	endTemp = FindEndStr(startTemp,size);
	startTemp=FindNextLexEnd(startTemp,endTemp);
	company = FindNextLex(startTemp,endTemp);

	startTemp = FindLex(0,size,"City:");
	endTemp = FindEndStr(startTemp,size);
	startTemp=FindNextLexEnd(startTemp,endTemp);
	city = FindNextLex(startTemp,endTemp);

	startTemp = FindLex(0,size,"Name:");
	endTemp = FindEndStr(startTemp,size);
	startTemp=FindNextLexEnd(startTemp,endTemp);
	name = FindNextLex(startTemp,endTemp);

	startTemp = FindLex(0,size,"Version:");
	endTemp = FindEndStr(startTemp,size);
	startTemp=FindNextLexEnd(startTemp,endTemp);
	version = FindNextLex(startTemp,endTemp);

	startTemp = FindLex(0,size,"Date:");
	endTemp = FindEndStr(startTemp,size);
	startTemp=FindNextLexEnd(startTemp,endTemp);
	date = FindNextLex(startTemp,endTemp);

	startTemp = FindLex(0,size,"Register:");
	endTemp = FindEndStr(startTemp,size);
	i = FindLex(startTemp,endTemp,"[");
	numOfRegister = GetNum(i+1);

	startTemp = FindLex(0,size,"Base:");
	endTemp = FindEndStr(startTemp,size);
	i = FindLex(startTemp,endTemp,"[");
 //	base_addr = GetNum(i+1);
	baseaddr = GetNum(i+1);
 //ok	printEthLongHex(baseaddr); //t
	startPosView = FindLex(0,size,"Indicator:");
	startPosView = FindLex(startPosView,size,"{");
	startPosView = FindEndStr(startPosView,size);
	endPosView = FindLex(startPosView,size,"}");
	countView = 0;
	currPos = startPosView;
//ok	return; //t 
	while(currPos<endPosView)
	{
		if((currPos = FindString(++currPos,size))<endPosView) countView++;
	}
 // 	printEthLongHex(countView);
 //  return; //t08
	if(countView<MAX_VIEW)
	{

   		viewPos = (EmbViewPos*)AllocMemory(countView*sizeof(EmbViewPos));
 //0x201242f3		printEthLongHex((unsigned long)viewPos);
	 //		 printEthLongHex((unsigned long)viewPos->Clear(););
   		viewPos->Clear();	 //hier fall
	}
  //	else return;
	else return 0;
	currPos = startPosView;
//   return; //t08
	for(i=0; i<countView; i++)
	{
		currPos = ReadViewPos(currPos,endPosView,viewPos+i);
	}

	startPosSet = FindLex(0,size,"Sets:");
	startPosSet = FindLex(startPosSet,size,"{");
	startPosSet = FindEndStr(startPosSet,size);
	endPosSet = FindLex(startPosSet,size,"}");
	countSets = 0;
	currPos = startPosSet;
	while(currPos<endPosSet)
	{
		if((currPos = FindString(++currPos,size))<endPosSet) countSets++;
	}
  //bad 	return; //t08
	if(countSets<MAX_SET)
		sets = (EmbSet*)AllocMemory(countSets*sizeof(EmbSet));
	else
	   //	return;
		return 0;
	currPos = startPosSet;
	for(i=0; i<countSets; i++) sets[i].Clear();
	for(i=0; i<countSets; i++)
	{
		currPos = ReadSet(currPos,endPosSet,sets+i);
	}

	i=startPosTree=endPosTree=countTreePoint=currPos=0;
	startPosTree = FindLex(0,size,"Tree:");
	startPosTree = FindLex(startPosTree,size,"{");
	startPosTree = FindEndStr(startPosTree,size);
	endPosTree = FindLex(startPosTree,size,"}");
	countTreePoint = 0;
	currPos = startPosTree;
 //bad	return; //t
	while(currPos<endPosTree)
	{
		if((currPos = FindString(++currPos,size))<endPosTree) countTreePoint++;
	}
	temp = countTreePoint*sizeof(EmbTreePoint);
	if(countTreePoint*sizeof(EmbTreePoint)<MEMORY_HEAP) 
		treePoint = (EmbTreePoint*)AllocMemory(countTreePoint*sizeof(EmbTreePoint));
	else
	 //	return;
		return 0;
	currPos = startPosTree;
	for(i=0; i<countTreePoint; i++) treePoint[i].Clear();
	for(i=0; i<countTreePoint; i++)
	{
		currPos = ReadTreePoint(currPos,endPosTree,treePoint+i);
	}
	current = treePoint;
 //0x20143b3c	printEthLongHex((unsigned long)current);
   return 1;
}

//int EmbTree::GetNum(int start)
unsigned long  EmbTree::GetNum(int start)
{
 //	int i=start, value=0;
   unsigned long i=start, value=0l;
	while((cfg[i]>='0')&&(cfg[i]<='9'))
	{
		value = (value*10l) + cfg[i]-'0';
		i++;
	}
	return value;
}

unsigned EmbTree::FindLex(int start, int end,char * lex)
{
	unsigned i=0,j=0,flag=0,length=0;
	for(i=0; i<128; i++) if(lex[i]==0) { length=i; break; }
	for(i=start; i<end; i++)
	{
		if(lex[0]==cfg[i]){ flag=1; j=1; }
		if(flag) while(lex[j]==cfg[i+j]) j++;
		if(j==length) return i;
		else flag=0;
	}
	return end;
}

int EmbTree::CountString(int start,int end)
{
	int i=0,count=0,flag=0;
	for(i=start; i<end; i++)
	{
		if(cfg[i]>0x40) flag=1;
		if((cfg[i]=='\n')&&flag) count++;
	}
	return count;
}

int EmbTree::FindString(int start,int end)
{
	int i=0,flag=0;
	for(i=start; i<end; i++)
	{
		if(cfg[i]>0x40) flag=1;
		if((cfg[i]=='\n')&&flag) return i;
	}
	return end;
}

int EmbTree::FindStartStr(int start,int end)
{
	for(int i=start; i<end; i++)
	{
		if(cfg[i]>0x20) return i;
	}
	return end;
}

int EmbTree::FindEndStr(int start,int end)
{
	for(int i=start; i<end; i++)
	{
		if(cfg[i]=='\n') return i+1;
	}
	return end;
}

int EmbTree::FindNextLex(int start,int end)
{
	for(int i=start; i<end; i++) if(!((cfg[i]==' ')||(cfg[i]=='\t')||(cfg[i]=='\n'))) return i;
	return start;
}

int EmbTree::FindNextLexEnd(int start,int end)
{
	for(int i=start; i<end; i++) if((cfg[i]==' ')||(cfg[i]=='\t')||(cfg[i]=='\n')) return i+1;
	return start;
}

//port int EmbTree::LexCmp(int start,char far *lex)
int EmbTree::LexCmp(int start,char *lex)
{
	int i,length=0;
	for(i=0; i<128; i++) 
		if((lex[i]==0)||(lex[i]==' ')||(lex[i]=='\t')||(lex[i]=='.')||(lex[i]=='\n')) { length=i; break; }
	for(i=start; i<start+length; i++) 
		if(lex[i-start]!=cfg[i]) 
			return 0;
	return 1;	
}

int EmbTree::LexCmpTableSet(int start)
{
	int i=0,j=0,length=0,flag=0;
	for(i=0; i<countSets; i++)
	{
		for(j=0; j<128; j++) if((cfg[sets[i].name+j]==0)||(cfg[sets[i].name+j]==' ')||(cfg[sets[i].name+j]=='\t')) { length=j; break; }
		flag=1;
		for(j=start; j<start+length; j++) if(cfg[sets[i].name+j-start]!=cfg[j]) flag = 0;
		if(flag) 
			return i;
	}
	return -1;	
}

int EmbTree::LexCmpTableView(int start)
{
	int i=0,j=0,length=0,flag=0;
	for(i=0; i<countView; i++)
	{
		for(j=0; j<128; j++) if((cfg[viewPos[i].name+j]==0)||(cfg[viewPos[i].name+j]==' ')||(cfg[viewPos[i].name+j]=='\t')) { length=j; break; }
		flag=1;
		for(j=start; j<start+length; j++) if(cfg[viewPos[i].name+j-start]!=cfg[j]) flag = 0;
		if(flag) 
			return i;
	}
	return -1;	
}

int	EmbTree::SetTreePointParent(int start,EmbTreePoint *t)
{
	EmbTreePoint *temp;
	int i;
	for(i=0; i<countTreePoint; i++)
	{
	 if(treePoint[i].name!=0)
		if(LexCmp(start,(char *)(cfg+treePoint[i].name))) 
		{
			if(t != treePoint+i) t->parent = treePoint+i;
			else return 0;
			if(!t->parent->child) 
			{
				t->parent->child = t;
//				return 1;
			}
			else
			{
				if(!t->parent->child->brotherR) 
				{ 
					t->parent->child->brotherR = t; 
					t->brotherL=t->parent->child; 
//					return 2; 
				}
				else 
				{
					temp=t->parent->child;
					while(temp->brotherR) 
						temp=temp->brotherR;
					temp->brotherR = t;
					t->brotherL = temp;
					return 3;
				}
			}
			
		}
	}
	return 0;
}

int	EmbTree::ReadTreePoint(int start,int end,EmbTreePoint *treePoint)
{
	unsigned i=start, k, j=0, endStr=0;
	unsigned long access=0, addr=0, offset=0, type=0;

	i = FindStartStr(i,end);
	endStr = FindEndStr(i,end);
	i=FindNextLex(i,endStr);
	treePoint->name = i;
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);

	SetTreePointParent(i,treePoint);

	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	if(LexCmp(i,"not-accessible")) access=0;
	if(LexCmp(i,"read-only")) access=1;
	if(LexCmp(i,"write-only")) access=2;
	if(LexCmp(i,"read-write")) access=3;
//	treePoint->parameter.SetAccess(a);
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	if(LexCmp(i,"aggregate")) type = 0; //treePoint->parameter.SetType(0);
	else
	{
		treePoint->child = 0;
		type = SetTreePointType(i,endStr,treePoint);
		j=FindLex(i,endStr,"Reg[");
		if(j!=i) 
		{
			addr = GetNum(j+4);
//			treePoint->parameter.SetAddrReg(GetNum(j));
			j=FindLex(j,endStr,",");
			offset = GetNum(j+1);
//			treePoint->parameter.SetAddrBit(GetNum(j));
		 //	treePoint->parameter.Init(access,type,base_addr,addr,offset);
			treePoint->parameter.Init(access,type,baseaddr,addr,offset);
		}
	}
	j=FindLex(i,endStr,"Hide");
	if(j!=endStr) treePoint->typeOfView.hide = 1;
	else treePoint->typeOfView.hide = 0;

	j=FindLex(i,endStr,"View[");
	if(j!=endStr) 
	{
		j=FindLex(j,endStr,"[");
		j++;

		treePoint->typeOfView.pos = LexCmpTableView(j)+1;
		if((k=FindLex(j,endStr,"="))!=endStr) { treePoint->typeOfView.alarm = 1; j=k; }
		if((k=FindLex(j,endStr,"<"))!=endStr) { treePoint->typeOfView.alarm = 2; j=k; }
		if((k=FindLex(j,endStr,">"))!=endStr) { treePoint->typeOfView.alarm = 3; j=k; }
		treePoint->typeOfView.value = GetNum(j+1);
		j=FindLex(j,endStr,",");
		treePoint->typeOfView.level = GetNum(j+1);
	}
	else
	{
		treePoint->typeOfView.alarm = 0;
		treePoint->typeOfView.pos = 0;
	}
	return endStr;
}

int	EmbTree::ReadViewPos(int start,int end,EmbViewPos *view)
{
	int i=start, endStr=0;

	i = FindStartStr(i,end);
	endStr = FindEndStr(i,end);
	i=FindNextLex(i,endStr);
	view->name = i;
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	view->x = GetNum(i);				
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	view->y = GetNum(i);				
	i=FindLex(i,endStr,"[");
	i=FindNextLex(i+1,endStr);
	view->prefix = i;
	return endStr;
}

int	EmbTree::ReadSet(int start,int end,EmbSet *set)
{
	int i=start, j=0, endStr=0;

	i = FindStartStr(i,end);
	endStr = FindEndStr(i,end);
	i=FindNextLex(i,endStr);
	set->name = i;
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	set->basic_type = GetBasicType(i,endStr);
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);
	i=FindNextLexEnd(i,endStr);
	j=i;
	while(j<=endStr)
	{
		j = FindLex(j,endStr,"=");
		if(j!=endStr) set->numItem++;
		j++;
	}
	set->setItem = (EmbSetItem*)AllocMemory(set->numItem*sizeof(EmbSetItem));
//	SetTreePointParent(i,treePoint);

	for(j=0; j<set->numItem; j++)
	{
		set->setItem[j].Clear();   // ??? - PS
		set->setItem[j].value = GetNum(i);
	  i = FindLex(i,endStr,"=");
		set->setItem[j].name=i+1;
		i=FindNextLexEnd(i,endStr);
	}

	i=FindNextLexEnd(i,endStr);
	i=FindNextLex(i,endStr);

	return endStr;
}

int	EmbTree::GetBasicType(int start,int /*end*/)
{
	if(LexCmp(start,"BOOL")) return typeBOOL;
	if(LexCmp(start,"BIT_2")) return typeBIT_2;
	if(LexCmp(start,"BIT_3")) return typeBIT_3;
	if(LexCmp(start,"BIT_4")) return typeBIT_4;
	if(LexCmp(start,"BIT_5")) return typeBIT_5;
	if(LexCmp(start,"BIT_6")) return typeBIT_6;
	if(LexCmp(start,"BIT_7")) return typeBIT_7;
	if(LexCmp(start,"BYTE"))  return typeBYTE;
	if(LexCmp(start,"WORD"))  return typeWORD;
	if(LexCmp(start,"FUNC")) return typeFUNC;
	if(LexCmp(start,"STRING"))return typeSTRING;
	return 0;
}

int	EmbTree::SetTreePointType(int start,int /*end*/,EmbTreePoint */*treePoint*/)
{
	if(LexCmp(start,"BOOL")) return typeBOOL;//treePoint->parameter.SetType(typeBOOL);
	if(LexCmp(start,"BIT_2")) return typeBIT_2;//treePoint->parameter.SetType(typeBIT_2);
	if(LexCmp(start,"BIT_3")) return typeBIT_3;//treePoint->parameter.SetType(typeBIT_3);
	if(LexCmp(start,"BIT_4")) return typeBIT_4;//treePoint->parameter.SetType(typeBIT_4);
	if(LexCmp(start,"BIT_5")) return typeBIT_5;//treePoint->parameter.SetType(typeBIT_5);
	if(LexCmp(start,"BIT_6")) return typeBIT_6;//treePoint->parameter.SetType(typeBIT_6);
	if(LexCmp(start,"BIT_7")) return typeBIT_7;//treePoint->parameter.SetType(typeBIT_7);
	if(LexCmp(start,"BYTE"))  return typeBYTE;//treePoint->parameter.SetType(typeBYTE);
	if(LexCmp(start,"WORD"))  return typeWORD;//treePoint->parameter.SetType(typeWORD);
	if(LexCmp(start,"FUNC")) return typeFUNC;//treePoint->parameter.SetType(typeDWORD);
	if(LexCmp(start,"STRING"))return typeSTRING;//treePoint->parameter.SetType(typeSTRING);
	int i = LexCmpTableSet(start);
	if(i>=0) return 12+i; //treePoint->parameter.SetType(12+i);
	return 0;
}

char *EmbTree::ViewParameter(char *str)
{
	DBYTE db;
	if(current)
	{
		if(!current->Child())
		{
			EmbParameter* embParameter = current->Parameter();
			db.i=embParameter->Get();
			if(embParameter->Type()==typeAggregate) str[0]=0;
			if(embParameter->Type()<=typeWORD)
			{
				db.b[0]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
				if(embParameter->accessType.type==typeWORD) 
					db.b[1]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
				else 
					db.b[1]=0;	
				ltoa(db.i,str,10);
			}
			else
			{
				if(embParameter->Type()-12<countSets)
				{
					EmbSet *embSet = sets+(embParameter->Type()-12);
					BYTE value=0,type=0; 
//					if(!embParameter->accessType.access) return -1;
//					if((embParameter->accessType.access==1)||(embParameter->accessType.access==3))
					{
						db.b[0]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
						if(embParameter->accessType.type==typeWORD) 
							db.b[1]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
						else 
							db.b[1]=0;

						
						if(embParameter->accessType.type<12) type=embParameter->accessType.type;
						else type=embSet->Basic_Type();
						
						switch(type)
						{
						case typeAggregate: value=0; break;
						case typeBOOL:   value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 1); break;
						case typeBIT_2:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 2); break;
						case typeBIT_3:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 3); break;
						case typeBIT_4:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 4); break;
						case typeBIT_5:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 5); break;
						case typeBIT_6:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 6); break;
						case typeBIT_7:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 7); break;
						case typeBYTE:   value=db.b[0]; break;
						case typeWORD:   value=db.i; break;
						case typeSTRING: value=0; break;
						}
					}
					str[0]=0;
					for(int i=0; i<embSet->numItem; i++)
						if(value==embSet->setItem[i].Value())
							CreateASCIIZ((char*)(cfg+embSet->setItem[i].Name()),str);
				}
				else str[0]=0;
			}
		}
	}
	return str;
}

unsigned EmbTree::GetParameterNum()
{
	DBYTE db;
	unsigned value=0,type=0; 
	if(current)
	{
   //0x201253c0		printEthLongHex((unsigned long)current);	//t

		if(!current->Child())
		{

 //--		printEthLongHex((unsigned long)current);

			EmbParameter* embParameter = current->Parameter();
	   	 //	printEthLongHex((unsigned long)embParameter->addr.BaseAddr+embParameter->addr.Offset);
			db.i=embParameter->Get();
			if(embParameter->Type()==typeAggregate) value=0;
			if(embParameter->Type()<=typeWORD)
			{
 //	printEthLongHex((unsigned long)embParameter->addr.BaseAddr+embParameter->addr.Offset);
	   		 	value=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);	  //hier fall!!!
		  //			value = * (char *)(embParameter->addr.BaseAddr+embParameter->addr.Offset);	  //t
		 // 		  printEthLongHex((unsigned long)value);

				if(embParameter->accessType.type==typeWORD) 
					value=Inport(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
				else 
					value=0;
				 //	printEthLongHex((unsigned long)value);
		
			}
			else
			{
			 		  //	printEthLongHex((unsigned long)2);
				if(embParameter->Type()-12<countSets)
				{
					EmbSet *embSet = sets+(embParameter->Type()-12);
//					if(!embParameter->accessType.access) return -1;
//					if((embParameter->accessType.access==1)||(embParameter->accessType.access==3))
					{
						db.b[0]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
				//		 printEthLongHex((unsigned long)db.b[0]);
				   //		 printEthLongHex((unsigned long)embParameter->addr.BaseAddr+embParameter->addr.Offset);

						if(embParameter->accessType.type==typeWORD) 
							db.b[1]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
						else 
							db.b[1]=0;

						
						if(embParameter->accessType.type<12) type=embParameter->accessType.type;
						else type=embSet->Basic_Type();
				   //	   printEthLongHex((unsigned long)type);  //!!!!!	
						switch(type)
						{
						case typeAggregate: value=0; break;
						case typeBOOL:   value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 1); break;
						case typeBIT_2:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 2); break;
						case typeBIT_3:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 3); break;
						case typeBIT_4:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 4); break;
						case typeBIT_5:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 5); break;
						case typeBIT_6:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 6); break;
						case typeBIT_7:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 7); break;
						case typeBYTE:   value=db.b[0]; break;
						case typeWORD:   value=db.i; break;
						case typeSTRING: value=0; break;
						}
				  //	    printEthLongHex((unsigned long)value);	 //!!!!
					}
				}
			}
		}
	}

	return value;
}

int EmbTree::TestTypeParameter(WORD *value,char *str)
{
	int err=0;
	char str_par[32];
	WORD num_bit=0;
	if(comPoint)
	{
		if(!comPoint->Child())
		{
			EmbParameter* embParameter = comPoint->Parameter();
			switch(embParameter->Type())
			{
				case typeAggregate: return 10;
				case typeBOOL	 : num_bit=1;	 		 break;
				case typeBIT_2 : num_bit=3;	 		 break;
				case typeBIT_3 : num_bit=7;	     break;
				case typeBIT_4 : num_bit=0x0f;	 break;
				case typeBIT_5 : num_bit=0x1f;	 break;
				case typeBIT_6 : num_bit=0x3f;	 break;
				case typeBIT_7 : num_bit=0x7f;	 break;
				case typeBYTE	 : num_bit=0xff;	 break;
				case typeWORD	 : num_bit=0xffff;	     break;
//				case typeDWORD : num_bit=0xffffffff;	 break;
//				case typeSTRING: CreateASCIIZ(cfg+(*(WORD*)embParameter.Get()),str); break;
				default:
					if(embParameter->Type()-12<countSets)
					{
						BYTE i;
						EmbSet *embSet = sets+(embParameter->Type()-12);
						for(i=0;i<embSet->numItem;i++)
						{
							CreateASCIIZ((char*)(cfg+embSet->setItem[i].Name()),str_par);
							if(StrCmp(str_par,str))
							{
								*value=(unsigned long)i;
								return 0;
							}
						}
						return 12;
					}
					else return 11;
//					break;
			}
			if(!num_bit)
				return 11;
//			char2int(value,str,&err);
//			*value=atoi(str);
			if(err)
				return err;
			if(*value>num_bit)
			{
				*value=0;
				return 13;
			}
			else return 0;
		}
	}
	return 11;
}
//void EmbTree::SetRequest(char far* m)
void EmbTree::SetRequest(char * m)
{
	for(int i=0; i<128; i++) request[i]=0;
	StrCopy(request,m);
}

void EmbTree::GetAnswer(char* m)
{
	StrCopy(m,answer);
	for(int i=0; i<128; i++) answer[i]=0;
}

int EmbTree::Send(EmbCOM* theCom)
{
	int i=0;
//	printf(answer);
	while(answer[i++]);
	if(theCom->UsedTrans()>128-i) return 0;
	i=0;
	while(answer[i]) theCom->Trans(answer[i++]);
//	theCom->Trans2();
	return 1;
}
// --------------------------------------------------------------------
char *EmbTree::GetFullCommand(EmbTreePoint *etp, char *str)
{
	char ch[8][32];
 //port 	char far *chTemp;
	char  *chTemp;

	int i;
	for(i=0; i<8; i++) ch[i][0] = 0;
	i=0;
	chTemp = str;
	EmbTreePoint *temp=etp;
	while(temp->Parent())
	{
		CreateASCIIZ((char*)(cfg+temp->Name()),ch[i]);
		temp = temp->Parent();
		i++;
	}
	for(i=7; i>=0; i--)
	{
		if(!(ch[i][0]==0))
		{
			chTemp = StrCopy(chTemp," ");
			chTemp = StrCopy(chTemp,ch[i]);
		}
	}
	return str;
}
/*
char* GetComLex(char* source,char *dest)
{
//	int i=0;
	char* s;
	char* d;
	s=source; d=dest;
	while(*s==32) s++;
	do
	{
		*d++=*s++;
	}while((*s!='!')&&(*s!=32)&&*s);
	*d=0;
	return s;
}
*/

// ==================================================================
//t int EmbTree::LexCmpInCommand(int start,int /*end*/,char *lex,char far *command)
int EmbTree::LexCmpInCommand(int start,int /*end*/,char *lex,char * command)
{
	int i,length=0;
	for(i=0; i<128; i++)
		if((lex[i]==0)||(lex[i]==' ')||(lex[i]=='\t')||(lex[i]=='.')||(lex[i]=='\n')) { length=i; break; }
	for(i=start; i<start+length; i++)
		if(lex[i-start]!=command[i])
			return 0;
	return 1;
}

//int EmbTree::FindSizeCommand(int max,char far *command)
int EmbTree::FindSizeCommand(int max,char *command)
{
	int i = 0;
	while((command[i]!='!')&&(command[i]!=0))
	{
		i++;
		if(i==max) return max;
	}
	return i;
}

//int EmbTree::FindNextLexInCommand(int start,int /*end*/,char far *command)
int EmbTree::FindNextLexInCommand(int start,int /*end*/,char *command)
{
	int i = start;
	while((command[i]!='!')&&(command[i]!=0))
	{
		if(!((command[i]==' ')||(command[i]=='\t')||(command[i]=='!'))) return i;
		i++;
	}
	return start;
}

//int EmbTree::FindNextLexEndInCommand(int start,int /*end*/,char far *command)
int EmbTree::FindNextLexEndInCommand(int start,int /*end*/,char  *command)
{
	int i = start;
	while((command[i]!='!')&&(command[i]!=0))
	{
		if((command[i]==' ')||(command[i]=='\t')||(command[i]=='!')) return i+1;
		i++;
	}
	return start;
}
extern "C" void printEthString(char * , unsigned long );
char *EmbTree::ViewComParameter(char *str)
{
	DBYTE db;
	if(comPoint)
	{
   //		printEthString(comPoint, 40); return 0;

	//	 printEthLongHex(comPoint->name); str[0]=0;   return 0;


		if(!comPoint->Child())
		{
			EmbParameter* embParameter = comPoint->Parameter();
			db.i=embParameter->Get();
			if(embParameter->Type()==typeAggregate) str[0]=0;

			if(embParameter->Type()<=typeWORD)
			{
				db.b[0]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
				if(embParameter->accessType.type==typeWORD) 
					db.b[1]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
				else 
					db.b[1]=0;	
				ltoa(db.i,str,10);
			}
			else
			{
				if(embParameter->Type()-12 < countSets)
				{
					EmbSet *embSet = sets+(embParameter->Type()-12);
					BYTE value=0,type=0; 
//					if(!embParameter->accessType.access) return -1;
//					if((embParameter->accessType.access==1)||(embParameter->accessType.access==3))
					{
						db.b[0]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
						if(embParameter->accessType.type==typeWORD) 
							db.b[1]=Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset+1);
						else 
							db.b[1]=0;

						
						if(embParameter->accessType.type<12) type=embParameter->accessType.type;
						else type=embSet->Basic_Type();
						if(type==typeSTRING)
						{
							for(int j=0; j<numOfRegister; j++)
							{
					  //			value=Inportb(base_addr+j);
								value=Inportb(baseaddr+j);
							  str[j*3] = HighHalfByte(value);
							  str[j*3+1] = LowHalfByte(value);
							  str[j*3+2] = '.';
							}
							str[numOfRegister*3-1]=0;
							return str;
						}

						switch(type)
						{
						case typeAggregate: value=0; break;
						case typeBOOL:   value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 1); break;
						case typeBIT_2:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 2); break;
						case typeBIT_3:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 3); break;
						case typeBIT_4:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 4); break;
						case typeBIT_5:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 5); break;
						case typeBIT_6:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 6); break;
						case typeBIT_7:  value=GetBitFromByte(db.b[0],embParameter->addr.Bit, 7); break;
						case typeBYTE:   value=db.b[0]; break;
						case typeWORD:   value=db.i; break;
						case typeSTRING: return str;
						}
					}
					str[0]=0;
					for(int i=0; i<embSet->numItem; i++)
						if(value==embSet->setItem[i].Value())
							CreateASCIIZ((char*)(cfg+embSet->setItem[i].Name()),str);
				}
				else str[0]=0;
			}
		}
	}
	return str;
}

int EmbTree::SetComParameter(char *str)
{
	WORD temp,value;// ,sword;
	BYTE sbyte;
	if(comPoint)
	{
		if(!comPoint->Child())
		{
			EmbParameter* embParameter = comPoint->Parameter();
			BYTE type=0;
			if(embParameter->Type()-12<countSets)
			{
				EmbSet *embSet = sets+(embParameter->Type()-12);
				if(embParameter->accessType.type<12) type=embParameter->accessType.type;
				else type=embSet->Basic_Type();		
				for(int i=0; i<embSet->numItem; i++)
				{
				 //	delay_mcs(100);	 //0227

					if(LexCmp(embSet->setItem[i].Name(),str))
					{
						temp = embSet->setItem[i].Value();
						sbyte = Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
					 //   printf("%d", type);	
				  //	    printEthLongHex(type);	
						switch(type)
						{
							//								case typeAggregate: break;
						case typeBOOL:   value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 1); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); 
					//	printf(" 0x%X", embParameter->addr.BaseAddr+embParameter->addr.Offset,temp);
						break;
						case typeBIT_2:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 2); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); 
				   //		printf(" 0x%X", embParameter->addr.BaseAddr+embParameter->addr.Offset,temp);
						break;
						case typeBIT_3:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 3); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_4:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 4); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_5:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 5); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_6:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 6); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_7:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 7); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBYTE:   Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); 
						
								   //		printf(" 0x%X", embParameter->addr.BaseAddr+embParameter->addr.Offset,temp);

										break;
//						case typeWORD:   outport(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); break;
						case typeWORD:   Outport(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); break;
							//								case typeSTRING: break;
						}//					if(!embParameter->accessType.access) return -1;
						return 1;
					}
				}
				return 0;
			}
		}
	}
}

int EmbTree::SetParameter(char *str)
{
	WORD temp,value;//,sword;
	BYTE sbyte;
	if(current)
	{
		if(!current->Child())
		{
			EmbParameter* embParameter = current->Parameter();
			BYTE type=0;
			if(embParameter->Type()-12<countSets)
			{
				EmbSet *embSet = sets+(embParameter->Type()-12);
				if(embParameter->accessType.type<12) type=embParameter->accessType.type;
				else type=embSet->Basic_Type();		
				for(int i=0; i<embSet->numItem; i++)
				{
					if(LexCmp(embSet->setItem[i].Name(),str))
					{
						temp = embSet->setItem[i].Value();
						sbyte = Inportb(embParameter->addr.BaseAddr+embParameter->addr.Offset);
						switch(type)
						{
							//								case typeAggregate: break;
						case typeBOOL:   value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 1); 
										 Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value);
					  //	*(char*)(embParameter->addr.BaseAddr+embParameter->addr.Offset) = value;
						 break;
						case typeBIT_2:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 2); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_3:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 3); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_4:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 4); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_5:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 5); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_6:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 6); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBIT_7:  value=SetBitIntoByte(sbyte, temp, embParameter->addr.Bit, 7); Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,value); break;
						case typeBYTE:   Outportb(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); value=temp; break;
//						case typeWORD:   outport(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); break;
						case typeWORD:   Outport(embParameter->addr.BaseAddr+embParameter->addr.Offset,temp); value=temp; break;
							//								case typeSTRING: break;
						}//					if(!embParameter->accessType.access) return -1;
						return value;
					}
				}
				return 0;
			}
		}
	}
}

int EmbTree::CommandDecoder()
{
  //	WORD value;
	char str[160];
	int res;
	int i=0,j=0;
	int counter=5;
	int typeCom = 0;
	int end = FindSizeCommand(128,request);	
	if(end==0)
	{
		i=1;
		answer[0]='&';
		answer[i++]='F';
		answer[i++]='a';
		answer[i++]='u';
		answer[i++]='l';
		answer[i++]='t';
		answer[i]='!';
		return 0;
	}

	counter=FindNextLexInCommand(counter,end,request);

	if(LexCmpInCommand(counter,end,"Set",request)) typeCom='s';
	if(LexCmpInCommand(counter,end,"Get",request))  typeCom='g';
  //	if(LexCmpInCommand(counter,end,"Get",request))  {typeCom='g'; return;}
	if(LexCmpInCommand(counter,end,"Action",request)) typeCom='a';
  //ok	 printEthLongHex(typeCom);	  //0x73 = "s"
	if(!typeCom) 
	{
		i=4;
		answer[0]='&';
		answer[i++]='F';
		answer[i++]='a';
		answer[i++]='u';
		answer[i++]='l';
		answer[i++]='t';
		answer[i++]=' ';
		answer[i++]='t';
		answer[i++]='y';
		answer[i++]='p';
		answer[i++]='e';
		answer[i]='!';
		return 0;
	}

 // printEthString(request, 128);
 //	 printf("%s", request);
	counter=FindNextLexEndInCommand(counter,end,request);
	counter=FindNextLexInCommand(counter,end,request);

	comPoint=treePoint;
	
	comPoint=comPoint->Child();
  CreateASCIIZ((char*)(cfg+comPoint->Name()),str);
//  printEthString(cfg+comPoint->Name(), 30);
  //	  printEthString(str, 100);

  //ok	if(typeCom=='g') return 0;
// #ifdef TEST_REMOTE_FF
//			  printfp("\n\r>5");
//#endif

  while(counter<=end)
	{
		while(!LexCmpInCommand(counter,end,str,request))
		{
	  //	printf("1");
			comPoint=comPoint->BrotherR();
			if(comPoint) CreateASCIIZ((char*)(cfg+comPoint->Name()),str);
			else 
			{
				counter=FindNextLexEndInCommand(counter,end,request);
				for(i=0; i<counter; i++) answer[i]=request[i];
				answer[i++]='?';
				answer[i]='!';
				answer[0]='&';

				  //	 printf("%s",answer);

				return 0;
			}
		}
		if(comPoint->Child()) 
		{
	   //ok	 printEthLongHex(110); return 0;
  //	   printf("2");

			comPoint=comPoint->Child();
			counter=FindNextLexEndInCommand(counter,end,request);
			counter=FindNextLexInCommand(counter,end,request);
			CreateASCIIZ((char*)(cfg+comPoint->Name()),str);
		}
		else
		{

//#ifdef TEST_REMOTE_FF
//			  printfp("\n\r>6");
//#endif

	  //ok	 printEthLongHex(111); return 0;
		 //	printf("3");
		 //	printf("%c" ,typeCom);

			switch(typeCom)
			{
		  				case 'a':
		//		printf("4");

					return 0;
				case 'g':
	  //			printf("5");


				 //	printEthString(cfg+comPoint->Name(), 30); return 0;

					counter=FindNextLexEndInCommand(counter,end,request);

		   // no		  	 printEthLongHex(counter); //return 0;	//0xd

					for(i=0; i<counter; i++) answer[i]=request[i];

		 			ViewComParameter(str);	  //hier fall

		  // no	  		printEthString(str, 10);// return 0;

					answer[i++]=' ';
					j=0;
					while(str[j]) answer[i++] = str[j++];
					answer[i]='!';
					answer[0]='&';

			  //		 printf("g :%s",answer);

					return 0;
				case 's':
		 //		printf(" 6: ");

				 //	 printEthString(request, 100);
					counter=FindNextLexEndInCommand(counter,end,request);
					counter=FindNextLexInCommand(counter,end,request);
					CreateASCIIZ(request+counter,str);
					res = SetComParameter(str);
					counter=FindNextLexEndInCommand(counter,end,request);
					for(i=0; i<counter; i++) answer[i]=request[i];
					if(res)
					{
						answer[i]='O';
						answer[i+1]='k';
						answer[i+2]='!';
						answer[0]='&';
					}
					else
					{
						answer[i]='F';
						answer[i+1]='a';
						answer[i+2]='u';
						answer[i+3]='l';
						answer[i+4]='t';
						answer[i+5]='!';
						answer[0]='&';
					}
			  // 		 printf("s :%s",answer);
				  //	 SaveStateACT34(); //my 090227
					return 0;
			}
		}
	}
  //	 printf("%s",answer);
//#ifdef TEST_REMOTE_FF
//			  printfp("\n\r>6");
//#endif

	return 0;
}


