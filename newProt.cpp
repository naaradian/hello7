static current_command_state;
static current_command_counter;

static bool flagFE;
static bool flagFC;

static unsigned char msg[64];
static unsigned char data[32];

extern "C" unsigned char OperateCommand(unsigned char * pData)
{
//// Test ////
	for(int i=0; i<32; i++) data[i]=i;
//////////////
	unsigned  char ret;
	unsigned char addr=2;
	ret = 0; 
	unsigned char rch;// = * pData; 
	switch(* pData)
	{
		case 0xFE:  
			if(flagFE)
			{
				current_command_state = RECEIVE_COMMAND;
				current_command_data_counter = 0;
				current_command_counter = 0;
				flagFE=false;
			}
			else
			{
				flagFE=true;
			}
      return;
		case 0xFC:       
			if(flagFC)
			{
				current_command_state = WAITING_COMMAND;
				current_command_counter = 0;
				flagFC=false;
			}
			else
			{
				flagFC=true;
			}
      return;   
		default:
			if(!(* pData)) 
			{
				if(flagFE)
				{
					rch=0xFE;
					flagFE=false;
				}
				else
				{
					if(flagFC) 
					{
						rch=0xFC;
						flagFC=false;
					}
					else
					{
						rch = * pData;
					}
				}
			}
	}

	if(current_command_state == RECEIVE_COMMAND
	{
		msg[current_command_counter]=rch;
		if(current_command_counter<64) current_command_counter++;
		else
		{
			current_command_state = WAITING_COMMAND;
			current_command_counter = 0;
		}
	}
	if(msg[1]==addr)
	{
		switch(msg[0])
		{
			case 0x43: 
				if(current_command_counter>3)
				{
					crc = 0;
					for(i=0; i<3; i++) crc += msg[i];
					if(msg[4]==crc)
					{
						if(msg[2]<32)
						{
							data[msg[2]]=msg[3];
							answer[0]=addr;
							answer[1]=0x00; // норма
							answer[2]=0x00; // crc
							ansewr_len=3;
						}
						else
						{
							answer[0]=addr;
							answer[1]=0x02; // неверный код операции
							answer[2]=0x02; // crc
							ansewr_len=3;
						}
					}
					else
					{
						answer[0]=addr;
						answer[1]=0x01; // контрольная сумма не совпала
						answer[2]=0x01; // crc
						ansewr_len=3;
					}
				}
				break;
			case 0x44: 
				if(current_command_counter>4)
				{
					crc = 0;
					for(i=0; i<4; i++) crc += msg[i];
					if(msg[5]==crc)
					{
						if(msg[3]-msg[2]<32)
						{
							for(i=0; i<msg[3]-msg[2]; i++) data[msg[2]+i]=msg[4];
							answer[0]=addr;
							answer[1]=0x00; // норма
							answer[2]=0x00; // crc
							ansewr_len=3;
						}
						else
						{
							answer[0]=addr;
							answer[1]=0x02; // неверный код операции
							answer[2]=0x02; // crc
							ansewr_len=3;
						}
					}
					else
					{
						answer[0]=addr;
						answer[1]=0x01; // контрольная сумма не совпала
						answer[2]=0x01; // crc
						ansewr_len=3;
					}
				}
				break;
			case 0x48: 
				if(current_command_counter>4)
				{
					crc = 0;
					for(i=0; i<4; i++) crc += msg[i];
					if(msg[5]==crc)
					{
						if(msg[3]-msg[2]<32)
						{
							for(i=0; i<msg[3]-msg[2]; i++) data[msg[2]+i]=msg[4];
							answer[0]=addr;
							answer[1]=0x00; // норма
							j=0;
							crc = 0;
							for(i=0; i<msg[3]-msg[2]; i++)
							{
								answer[2+j]=data[msg[2]+i];
								crc += answer[2+j];
								if(answer[2+j]==0xFE) answer[2+j++]=0x00;
								if(answer[2+j]==0xFC) answer[2+j++]=0x00;
								j++;
							}
							answer[2+j]=crc; // crc
							ansewr_len=3+j;
						}
						else
						{
							answer[0]=addr;
							answer[1]=0x02; // неверный код операции
							answer[2]=0x02; // crc
							ansewr_len=3;
						}
					}
					else
					{
						answer[0]=addr;
						answer[1]=0x01; // контрольная сумма не совпала
						answer[2]=0x01; // crc
						ansewr_len=3;
					}
				}
				break;
		}
	}
}