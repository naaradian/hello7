///////////////////////////////////////////////////////////////////////////////
// Только для КСС: Команды управления ОПУ Запрос: <тип команды/8>
// Типы команд: 
// 1. Запрос состояния <номер ОПУ на стыке/8> 
// 2. Передать в порт 485 команду для ОПУ <число байт N/8><текст команды/N*8>
///////////////////////////////////////////////////////////////////////////////

const STR_UST_LEN = 64;
static unsigned char send_command;
static unsigned char flag_ust_recv;
static unsigned char flag_ust_recv_start;
static unsigned char flag_ust_recv_index;
static unsigned char flag_ust_recv_end;
static unsigned char flag_ust_trns;
static char answerUst[STR_UST_LEN];
static char command_str[STR_UST_LEN];

int CEmbTerminalDlg::Ustir() // вызывать раз в 200 мс
{
// unsigned char flag_crtl
	if(send_command)
	{
		theSerial.Data(NUM_SERIAL,command_str); // послать полученную по команде 0x53 поледовательность в 485
		send_command=0;
	}
	else
	{
		it++;
		switch(it%3) // автоматический опрос все остальное время
		{
		case 0: theSerial.Data(NUM_SERIAL,"qa\r"); break; 
		case 1: theSerial.Data(NUM_SERIAL,"qb\r"); break;
		case 2: theSerial.Data(NUM_SERIAL,"qc\r"); break;
		}
	}
	return 0;

}

int CEmbTerminalDlg::RecvUstir(char c) 
{ // Ответ на qa: "TA 00 0000 0000 0100 00 C8 1C"
	if((c=='T')&&(!flag_ust_recv))
	{
		flag_ust_recv_start=1;
		flag_ust_recv=0;
	}
	else
	{
		if(flag_ust_recv_start)
		{
			flag_ust_recv_start=0;
			flag_ust_recv_index=0;
			switch(c)
			{
				case 'A': case 'a': flag_ust_recv=1; break;
				case 'B': case 'b': flag_ust_recv=2; break;
				case 'C': case 'c': flag_ust_recv=3; break;
				default: flag_ust_recv=0;
			}
		}
		else
		{
			if(flag_ust_recv)
			{
				if(flag_ust_recv_index<STR_UST_LEN)
				{
					if(c!=0x0d) // 0x0d='/r'
					{
						if(c!=0x67)
						{
							answerUst[flag_ust_recv_index++]=c;
						}
						else
						{
							flag_ust_recv_start=0;
							flag_ust_recv_index=0;
						}
					}
					else
					{
						answerUst[flag_ust_recv_index++]=0;
						if(flag_ust_recv_index>1) 
							Parse(flag_ust_recv, answerUst);
						flag_ust_recv=0;
					}
				}
				else
				{
					flag_ust_recv_index = flag_ust_recv_start = flag_ust_recv=0;
				}	
			}
		}
	}
	return 0;
}

struct Emb4Ust
{
	unsigned char mode;
	unsigned short x;
	unsigned short y;
	unsigned short flags;
	unsigned char current;
	unsigned char voltage;
	unsigned char temp; 
} e4ust[3];

unsigned Hex2Char(char s)
{
  if((s>='0')&&(s<='9')) return s - '0';
  if((s>='a')&&(s<='f')) return s - 'a' + 10;
  if((s>='A')&&(s<='F')) return s - 'A' + 10;
	return 0;
}
// разборка ответа
int CEmbTerminalDlg::Parse(unsigned char flag_ust_recv, char *answerUst)
{ // Ответ на qa: "TA 00 0000 0000 0100 00 C8 1C"
	int i=0;
	if(flag_ust_recv)
	{
		e4ust[flag_ust_recv-1].mode = (Hex2Char(answerUst[1])<<4) + Hex2Char(answerUst[2]);
		e4ust[flag_ust_recv-1].x = (Hex2Char(answerUst[4])<<12) + (Hex2Char(answerUst[5])<<8) + (Hex2Char(answerUst[6])<<4) + Hex2Char(answerUst[7]);
		e4ust[flag_ust_recv-1].y = (Hex2Char(answerUst[9])<<12) + (Hex2Char(answerUst[10])<<8) + (Hex2Char(answerUst[11])<<4) + Hex2Char(answerUst[12]);
		e4ust[flag_ust_recv-1].flags = (Hex2Char(answerUst[14])<<12) + (Hex2Char(answerUst[15])<<8) + (Hex2Char(answerUst[16])<<4) + Hex2Char(answerUst[17]);
		e4ust[flag_ust_recv-1].current = (Hex2Char(answerUst[19])<<4)	+ Hex2Char(answerUst[20]);
		e4ust[flag_ust_recv-1].voltage = (Hex2Char(answerUst[22])<<4)	+ Hex2Char(answerUst[23]);
		e4ust[flag_ust_recv-1].temp = (Hex2Char(answerUst[25])<<4)	+ Hex2Char(answerUst[26]);
	}
	return 0;
}