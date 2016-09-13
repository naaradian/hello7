///////////////////////////////////////////////////////////////////////////////
// Только для КСС: Команды управления ОПУ Запрос: <тип команды/8>
// Типы команд: 
// 1. Запрос состояния <номер ОПУ на стыке/8> 
// 2. Передать в порт 485 команду для ОПУ <число байт N/8><текст команды/N*8>
///////////////////////////////////////////////////////////////////////////////

#define STR_UST_LEN (64)
#define	theSerial.Data (StrToPdcTu1)

int Parse(unsigned char , char *);
unsigned Hex2Char(char);



unsigned char send_command;
unsigned char flag_ust_recv;
static unsigned char flag_ust_recv_start;
static unsigned char flag_ust_recv_index;
static unsigned char flag_ust_recv_end;
static unsigned char flag_ust_trns;
static unsigned char acorrect, bcorrect, ccorrect;


static unsigned char flag_addr_index;


static char answerUst[STR_UST_LEN];
char command_str[STR_UST_LEN];

unsigned char numa[3], numb[3], numc[3];

//int CEmbTerminalDlg::Ustir() // вызывать раз в 200 мс
int Ustir() // вызывать раз в 200 мс
{

unsigned char * pData;

unsigned char CommandBuf[10];
// unsigned char flag_crtl
 static unsigned long it;
	if(send_command)
	{
   //	printEthLongHex(command_str[0])
		StrToPdcTu1(0,command_str); // послать полученную по команде 0x53 поледовательность в 485
		send_command=0;
  /*
 pData = &command_str[0];
   for(unsigned i = 0; i < 8; i++)
  { 
  printEthLongHex(*pData++);
   }
	*/
	}
	else
	{

		it++;
	//	printEthLongHex(it);
		switch(it%3) // автоматический опрос все остальное время
		{

		case 0:
  CommandBuf[0] =  'q';
 CommandBuf[1] =  numa[0];
 CommandBuf[2] =  numa[1];
 CommandBuf[3] =  numa[2];
 CommandBuf[4] =  '\r';
 CommandBuf[5] =  '\0';
    StrToPdcTu1(0,CommandBuf); break; 


		
  //		 StrToPdcTu1(0,"qa\r"); break; 
		case 1: 
  CommandBuf[0] =  'q';
 CommandBuf[1] =  numb[0];
 CommandBuf[2] =  numb[1];
 CommandBuf[3] =  numb[2];
 CommandBuf[4] =  '\r';
 CommandBuf[5] =  '\0';
    StrToPdcTu1(0,CommandBuf); break; 

		
	//	StrToPdcTu1(0,"qb\r"); break;
		case 2:
  CommandBuf[0] =  'q';
 CommandBuf[1] =  numc[0];
 CommandBuf[2] =  numc[1];
 CommandBuf[3] =  numc[2];
 CommandBuf[4] =  '\r';
 CommandBuf[5] =  '\0';
    StrToPdcTu1(0,CommandBuf); break; 
		
 //		 StrToPdcTu1(0,"qc\r"); break;

		}
	}
	return 0;

}

//int CEmbTerminalDlg::RecvUstir(char c) 
//RecvUstir(char c) 
RecvUstir(unsigned char c) 
{ // Ответ на qa: "TA 00 0000 0000 0100 00 C8 1C"
//T 512 00 0000 0000 0100 00 C8 1C

//printfp("\n\r");
//printfpd(" %c", c);
	if((c=='T')&&(!flag_ust_recv))
	{
//printfp("\n\r start");

		flag_ust_recv_start=1;
		flag_ust_recv=0;
		flag_addr_index = 0;
		 acorrect  = 1; bcorrect = 1; ccorrect = 1;


	}
	else
	{
		if(flag_ust_recv_start)
		{
	   //		flag_ust_recv_start=0;
			flag_ust_recv_index=0;
		   if(flag_addr_index < 2)
			{	
  //			printfp(" <2");
		  	    flag_addr_index++;
			  return;
			}

			if(flag_addr_index == 2)
			{
	//		printfp(" ==2");
			  if(c != numa[0])	acorrect = 0;
			  if(c != numb[0])	bcorrect = 0;
			  if(c != numc[0])	ccorrect = 0;

			   /*
			 switch(c)
			 {
				case numa[0]: flag_ust_recv=1; break;
				case numb[0]: flag_ust_recv=2; break;
				case numc[0]: flag_ust_recv=3; break;
				default: flag_ust_recv=0;
			 }
			 */
			  flag_addr_index++;
			  return;
			}
		if(flag_addr_index == 3)
			{
	  //		printfp(" ==3");
		      if(c != numa[1])	acorrect = 0;
			  if(c != numb[1])	bcorrect = 0;
			  if(c != numc[1])	ccorrect = 0;

			  flag_addr_index++;
			  return;
			}
        if(flag_addr_index == 4)
			{
              if(c != numa[2])	acorrect = 0; 
			  if(c != numb[2])	bcorrect = 0;
			  if(c != numc[2])	ccorrect = 0;

		 if(acorrect)  { flag_ust_recv=1; flag_ust_recv_start = 0;}
 	     if(bcorrect)  { flag_ust_recv=2; flag_ust_recv_start = 0;}
	     if(ccorrect)  { flag_ust_recv=3; flag_ust_recv_start = 0;}
			 flag_addr_index++; //TO GET OUT BAUND
			 return;
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
				  //		printfp(" ans+ ");
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
	unsigned char rezerv;
	unsigned short x;
	unsigned short y;
	unsigned short flags;
	unsigned char current;
	unsigned char voltage;
	unsigned char temp; 
} e4ust[3];
 /*
unsigned Hex2Char(char s)
{
  if((s>='0')&&(s<='9')) return s - '0';
  if((s>='a')&&(s<='f')) return s - 'a' + 10;
  if((s>='A')&&(s<='F')) return s - 'A' + 10;
	return 0;
}
*/
// разборка ответа
//int CEmbTerminalDlg::Parse(unsigned char flag_ust_recv, char *answerUst)
	 /* 111109
int Parse(unsigned char flag_ust_recv, char *answerUst)
{ // Ответ на qa: "TA 00 0000 0000 0100 00 C8 1C"
// printEthLongHex(answerUst[26]);
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
  //  printEthLongHex(e4ust[flag_ust_recv-1].temp);

	}
	return 0;
}
	*/
   /*
int Parse(unsigned char flag_ust_recv, char *answerUst)
{ // Ответ на q512: "T 512 00 0000 0000 0100 00 C8 1C"
	int i=0;
	if(flag_ust_recv)
	{
	*/
	   /*
		e4ust[flag_ust_recv-1].mode = (Hex2Char(answerUst[4])<<4) + Hex2Char(answerUst[5]);
		e4ust[flag_ust_recv-1].x = (Hex2Char(answerUst[7])<<12) + (Hex2Char(answerUst[8])<<8) + (Hex2Char(answerUst[9])<<4) + Hex2Char(answerUst[10]);
		e4ust[flag_ust_recv-1].y = (Hex2Char(answerUst[12])<<12) + (Hex2Char(answerUst[13])<<8) + (Hex2Char(answerUst[14])<<4) + Hex2Char(answerUst[15]);
		e4ust[flag_ust_recv-1].flags = (Hex2Char(answerUst[17])<<12) + (Hex2Char(answerUst[18])<<8) + (Hex2Char(answerUst[19])<<4) + Hex2Char(answerUst[20]);
		e4ust[flag_ust_recv-1].current = (Hex2Char(answerUst[22])<<4)	+ Hex2Char(answerUst[23]);
		e4ust[flag_ust_recv-1].voltage = (Hex2Char(answerUst[25])<<4)	+ Hex2Char(answerUst[26]);
		e4ust[flag_ust_recv-1].temp = (Hex2Char(answerUst[28])<<4)	+ Hex2Char(answerUst[29]);
		  */
			 /*
		e4ust[flag_ust_recv-1].mode = (Hex2Char(answerUst[5])<<4) + Hex2Char(answerUst[6]);		e4ust[flag_ust_recv-1].x = (Hex2Char(answerUst[7])<<12) + (Hex2Char(answerUst[8])<<8) + (Hex2Char(answerUst[9])<<4) + Hex2Char(answerUst[10]);
		e4ust[flag_ust_recv-1].y = (Hex2Char(answerUst[13])<<12) + (Hex2Char(answerUst[14])<<8) + (Hex2Char(answerUst[15])<<4) + Hex2Char(answerUst[16]);
		e4ust[flag_ust_recv-1].flags = (Hex2Char(answerUst[18])<<12) + (Hex2Char(answerUst[19])<<8) + (Hex2Char(answerUst[20])<<4) + Hex2Char(answerUst[21]);
		e4ust[flag_ust_recv-1].current = (Hex2Char(answerUst[23])<<4)	+ Hex2Char(answerUst[24]);
		e4ust[flag_ust_recv-1].voltage = (Hex2Char(answerUst[26])<<4)	+ Hex2Char(answerUst[27]);
		e4ust[flag_ust_recv-1].temp = (Hex2Char(answerUst[29])<<4)	+ Hex2Char(answerUst[30]);

	}
	return 0;
}
		 */
int Parse(unsigned char flag_ust_recv, char *answerUst)
{ // Ответ на qa: "TA 00 0000 0000 0100 00 C8 1C"
// printEthLongHex(answerUst[26]);
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
  //  printEthLongHex(e4ust[flag_ust_recv-1].temp);

	}
	return 0;
}