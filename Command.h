
//const MAX_SIZE_MES = 256; // ћаксимально возможна€ длина сообщени€  
#define  MAX_SIZE_MES (256)
unsigned char Hex2Char(char);
 /*
unsigned char Hex2Char(char s)

{
  if((s>='0')&&(s<='9')) return s - '0';
  if((s>='a')&&(s<='f')) return s - 'a' + 10;
  if((s>='A')&&(s<='F')) return s - 'A' + 10;
	return 0;
}
 */
class EmbCommand
{
    char m_str[MAX_SIZE_MES];
		int m_index;
		char m_state; // 0-Empty 1-Adding 2-Full
	public:	
		void Init();
		char *GetStr() { return m_str; }
		void SetStr(char *s) {  }
		int IsEmpty() { return !m_state; }
		int IsFull() { if(m_state==2) return 1; else return 0; }
		int Add(char ch); 
		void Empty() { Init(); }
		unsigned char GetAddr();
		unsigned char GetPoint();
		char GetType() { return m_str[0]; }
};
/*
void EmbCommand::Init() 
{ 
	m_state=m_index=0; 
	for(int i=0; i<MAX_SIZE_MES; i++) m_str[i]=0; 
}

int EmbCommand::Add(char ch)
{
  if(m_index<MAX_SIZE_MES)
	{
		switch(m_state)
		{
		  case 0: 
				if((ch!='@')&&(ch!='&')) Init();
				else
				{
					m_state = 1;
					m_str[m_index++] = ch;
					if(ch=='!') m_state = 2;
				}
				break;
			case 1:
				if((ch=='@')||(ch=='&')) Init();
				else 
				{
					m_str[m_index++] = ch;
					if(ch=='!') m_state = 2;
				}
				break;
			case 2: 
				Init();
				break;
		}
	}
	return m_state;
}

unsigned char EmbCommand::GetAddr()
{
  unsigned char i=0;
	if(m_state==2)
	{
    i=Hex2Char(m_str[3]);
		i<<=4;
		i+=Hex2Char(m_str[4]);
	}
	return i;
}

unsigned char EmbCommand::GetPoint()
{
  unsigned char i=0;
	if(m_state==2)
	{
    i=Hex2Char(m_str[1]);
		i<<=4;
		i+=Hex2Char(m_str[2]);
	}
	return i;
}

 */