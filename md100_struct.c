//_________________________________________________

struct Mode100SE
{

	unsigned char mode;		  //15

//___________________________________________________________________________line

	unsigned char interf; // 16 2 high - num STM1, another - num E1
 //	unsigned long rateEth;	 
 unsigned char rateEth0;	//17
 unsigned char rateEth1;   //18
 unsigned char rateEth2;   //19
 unsigned char rateEth3;   //20

  //	unsigned long extTypeRate; //21 22 23|||| 24  3 high - type, another - rate
   unsigned char	extTypeRate0;
   unsigned char	extTypeRate1;
   unsigned char	extTypeRate2;
   unsigned char	extTypeRate3;



  //	unsigned short blockSize;	//25  26
   unsigned char blockSize0;
   unsigned char blockSize1;


	unsigned char coderate0;   //27
	unsigned char coderate1;	//28
	unsigned char coderate2;	//29
	unsigned char coderate3;   //30


	unsigned char code_type; //type_code; 31

//_____________________________________________
 //	unsigned char code_rate;
////
  //	unsigned long portrate;
	 unsigned char portrate0;
 unsigned char portrate1;
 unsigned char portrate2;
 unsigned char portrate3;

	unsigned char port_mode;
////
	unsigned char mparam1;
	unsigned char mparam2;
	unsigned char mparam3;
	unsigned char mparam4;
	unsigned char mparam5;



};

struct Emb4100SECfg
{

	unsigned char conf_number;		//0
   unsigned char conf_number1;		//1

	unsigned char numMode;		   //2
	unsigned char numProvCode; //3 // 1 lowest num Provogent, next - ldpc(1)/rs(0)
 unsigned char rateSymbol0;		 //4
 unsigned char rateSymbol1;		//5
 unsigned char rateSymbol2;		 //6
 unsigned char rateSymbol3;		 //7

	unsigned char acm_status;	  //8
	unsigned char alfa;			 //9
	unsigned char param1;
	unsigned char param2;
	unsigned char param3;
	unsigned char param4;
	unsigned char param5;	   //14

Mode100SE 	mode15504[16];
};

union  uConfigTxtData100
{
  Emb4100SECfg  emb4md15504cfg;
  unsigned char Data[TXT_REAL_LEN_100];	   //need check
};



