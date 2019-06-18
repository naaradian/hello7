//remote.h
#ifndef RMT_H
#define RMT_H
#include "DSP281x_Device.h"
//#include "Expert.h"

#ifdef __cplusplus
extern "C" {
#endif
class Remote
{
	public:
//	Uint16  Control(Uint16);
//	void	Operate(Uint16);
	int16 RBuffSize; //it aet to 128 in constructor
	int16 TBuffSize; //it aet to 128 in constructor	
	char RBuff[128];
	char * pRBuff;
	char TBuff[128];
	char * pTBuff;
	char IdCommand;
//	char ReadChar(void);
//	void Receive(void);
	void Receive(unsigned char);
	void Transmit(void);
	void ParseBuffer(char *, const char *);
	void RunCommand(char*);
	void SendChar(char*);
	void ReplacePC(void);
	Remote();
};
extern Remote UsedRemote;  
#ifdef __cplusplus
}
#endif /* extern "C" */     
     
#endif // RMT_H