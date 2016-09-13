//программа установки звуковых каналов KOM2 и DEC2
#include "EMBISR.H"

//#define ENCODER   //test
//#define  DECODER    //test 



int nTS1[4];// = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 1 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
int nTS2[4];// = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 2 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
int n_line;// = 0;
int n_slot;// = 15;  


//**************************************************************************************
//  запись в блоки KOM2 и DEC2   
//  скорость потока(256,128,64,), номер линии(4-43), занимаемые TS (1-31)
//  передается :номер канала звука,
//  используется: 
//             - номер текущего слота n_slot
//             - буфет номеров выбранных TS  (nTS1[4] или nTS2[4]) 1 или 2 канала звука 
//               в зависимости от скорости выбираеся 4,2 или 1 TS
//             - номер линии
//
//--------------------------------------------------------------------------------------
// adres matrix TS:
//
//               0:  BADR+n_slot*16+8(HIGH+LOW)
//               1:  BADR+n_slot*16+9(HIGH+LOW)
//               2:  BADR+n_slot*16+A(HIGH+LOW)     WINDOW = 0xf (для записи данных) 
//               3:  BADR+n_slot*16+B(HIGH+LOW)
//
//               matrix TS:  // установка 1 в соответствующей позиции использует данный TS для потока
//               adr             bit 7    6    5    4    3    2    1    0       
//               08                  TS7  TS6  TS5  TS4  TS3  TS2  TS1  TS0   
//               09                  TS15 TS14 TS13 TS12 TS11 TS10 TS9  TS8
//               0A                  TS23 TS22 TS21 TS20 TS19 TS18 TS17 TS16
//               0B                  TS31 TS30 TS29 TS28 TS27 TS26 TS25 TS24
//               ---------------------  
// adres nLine   :   BADR+n_slot*16+0(HIGH+LOW)     LINE =0x0a  (для записи данных)
// 
//**************************************************************************************
//**************************************************************************************
#define EN_LINE        0x80
#define WINDOW         0x0f      //адрес в "окне"
#define NLINE1         0x0a      //адрес регистра номера линии потока 1 для KOM2,DEC2 
#define NLINE2         0x0b      //адрес регистра номера линии потока 2 для KOM2,DEC2 
#define SA             0x08      //адрес регистра-мультиплексора скорости потока 1  
#define SB             0x09      //адрес регистра-мультиплексора скорости потока 2  
#define STOP_KODER     0x10      //остановить кодер DSP33
#define SET_SPEED      0x20      //установить скорость кодера 21=64K  24=128K  28=256K
#define PUSK_KODER     0x50      //запустить кодер  
#define GET_DELAY_TIME      0x40      //

void  itoa(long value, char *strP, int radix)
{
  //      return  __longtoa (value, strP, radix, (radix == 10), 'a');
  if(radix == 10)
  {
    sprintf(strP, "%d",value);
  }
  else
  {
    sprintf(strP, "%X",value);

  }

}


// для телевизионных кодеров/декодеров:n_slot=15; 

void out_compare_ind(int bt1,int bt2);
// базовый адрес портов в-в 0x500 до 0x5ff
unsigned char RDBUS( unsigned int BADR,unsigned int SLOT,unsigned int ADR )  // FUNC FOR  READ DATA ON FLEX BUS
{	
  unsigned int busadr;      // shift on 4 - module selecktor
  unsigned int adr ;        // addr  of bus data window
  
  busadr=(SLOT*16) | 0x0500;      // shift on 4 - module selecktor
  adr = (busadr  | ADR);        // addr  of bus data window

  outportb(busadr | 0x001, BADR/256);      // set base H adr
  outportb(busadr , BADR);               // set base L adr
  return ( inportb( adr )); 
}

void WRBUS( unsigned int BADR,unsigned int SLOT,unsigned int ADR,unsigned char data )  // FUNC FOR  write DATA ON FLEX BUS
{
  unsigned int busadr;      // shift on 4 - module selecktor
  unsigned int adr ;        // addr  of bus data window

  busadr=(SLOT*16) | 0x0500;      // shift on 4 - module selecktor
  adr = (busadr  | ADR);        // addr  of bus data window

  outportb(busadr | 0x01, BADR/256);      // set base H adr
  outportb(busadr, BADR);               // set base L adr
  outportb( adr, data );	
}


void wr_set_zv(int n_chenal_zv,int n_line,int speedf)
{
 int i,a,a1;
 unsigned char b;//,b1;
 int nTS[4];
 unsigned char matrix[4];    // матрица установки TS 
 
for (i=0;i<4;i++)  //переписать в буфер 
  {
   if (n_chenal_zv==1) nTS[i]=nTS1[i];
   else nTS[i]=nTS2[i];  
   matrix[i]=0;  
  }

      //заполнение  матрици используемых TS
      for (i=0;i<4;i++)
      {         
        //if (nTS[i]!=0) a=8+fmod(nTS[i],8); // high + low adress  
        if ((nTS[i]!=0)&&(nTS[i]<32))
         { 
          a=(int)(nTS[i]/8); //адрес в матрице  
          b=0x01;
          b=b<<(nTS[i]%8);                //data
          matrix[a]|=b;
         }
      }
      //запись матрици используемых TS      
      if (n_chenal_zv==1)
       { 
        for (i=0;i<4;i++)
         {
          WRBUS((i+8),n_slot,WINDOW,matrix[i]);
          b=RDBUS((i+8),n_slot,WINDOW);
          //b=0x37;              //тест на ошибку
          a=(int)(b);   
          a1=(int)matrix[i]; 
          if (b!=matrix[i]) out_compare_ind(a,a1);
         }   
       }
              
       else 
        { 
          for (i=0;i<4;i++) 
          { 
           WRBUS((i+12),n_slot,WINDOW,matrix[i]);
           b=RDBUS((i+12),n_slot,WINDOW);
           a=(int)(b);   
           a1=(int)matrix[i]; 
           if (b!=matrix[i]) out_compare_ind(a,a1);
          } 
        }   
      //запись номера линии
      if (n_chenal_zv==1) 
       {   
        WRBUS(0,n_slot,NLINE1,(unsigned char)(n_line|EN_LINE));
        b=(RDBUS(0,n_slot,NLINE1))&0xBF;
        a=(int)(b);   
        a1=(int)(n_line|EN_LINE);
        if (b!=(unsigned char)(n_line|EN_LINE)) out_compare_ind(a,a1);
       }
      else 
       { 
        WRBUS(0,n_slot,NLINE2,(unsigned char)(n_line|EN_LINE));
        b=(RDBUS(0,n_slot,NLINE1))&0xBF;
        a=(int)(b);   
        a1=(int)(n_line|EN_LINE);  
        if (b!=(unsigned char)(n_line|EN_LINE)) out_compare_ind(a,a1);
        }


       // переключить синхронизацию на выбранную скорость 
       if (speedf==256) {a=3; b=0x08;}
       if (speedf==128) {a=1; b=0x04;}
       if (speedf==64)  {a=0; b=0x01;}
       if (n_chenal_zv==1)  WRBUS(0,n_slot,SA,(unsigned char)(a));
       else WRBUS(0,n_slot,SB,(unsigned char)(a));     
   
}


void out_compare_ind(int bt1,int bt2)
{        
   int i;
   char str1[5]={' ',' ',' ',' ',' '};     //строка для преобразований itoa  
   char str[25];

   
  for(i=0; i<25; i++) str[i]=0;
  itoa(bt1,str1,10);
  str[0]=str1[0];
  str[1]=str1[1];
  str[3]=str1[2];
  str[4]=str1[3];
}

/* 090527

void set_audio(int rate,int mode)
{
//остановить кодер 
//  i=0; //для 0 канала
//  i=4; //для 1 канала   
  WRBUS(0,n_slot,WINDOW,(unsigned char)(STOP_KODER));
	if(rate){
		nTS1[0]=4; nTS1[1]=5; nTS1[2]=6; nTS1[3]=7; 
	}else{
		nTS1[0]=4; nTS1[1]=5; nTS1[2]=6; nTS1[3]=8; 
	}
	n_line = 20;
	wr_set_zv(1,n_line,256);

 //error ? if(mode=1)
   if(mode==1)
  {
    WRBUS(4,n_slot,WINDOW,(unsigned char)(STOP_KODER));
	if(rate){
		nTS2[0]=8; nTS2[1]=9; nTS2[2]=10; nTS2[3]=11; 
	}else{
		nTS2[0]=9; nTS2[1]=10; nTS2[2]=12; nTS2[3]=13; 
	}
	wr_set_zv(2,n_line,256);
  }
}

*/
unsigned long get_audio(int rate,int nch)  //from sergey
{
  printf("\n\r get_audio rate : %d , sound : %d", rate , nch );
  char c;
  int error=0;
//____________________________________________________
 outportb(0xf1,0x00); 
  if(rate){
    outportb(0xf0,0x0c);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0c = %x (0x00)",c); error=1; }
    outportb(0xf0,0x0d);    if((c=inportb(0xff))!=0x0f){ printf("\n\rset_audio_reg_0x0d = %x (0x0f)",c); error=1; }
    outportb(0xf0,0x0e);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0e = %x (0x00)",c); error=1; }
    outportb(0xf0,0x0f);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0f = %x (0x00)",c); error=1; }
    outportb(0xf0,0x08);    if((c=inportb(0xff))!=0xf0){ printf("\n\rset_audio_reg_0x08 = %x (0xf0)",c); error=1; }
    outportb(0xf0,0x09);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x09 = %x (0x00)",c); error=1; }	
    outportb(0xf0,0x0a);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0a = %x (0x00)",c); error=1; }	
    outportb(0xf0,0x0b);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0b = %x (0x00)",c); error=1; }	
  }else{
    outportb(0xf0,0x0c);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0c = %x (0x00)",c); error=1; }
    outportb(0xf0,0x0d);    if((c=inportb(0xff))!=0x36){ printf("\n\rset_audio_reg_0x0d = %x (0x36)",c); error=1; }
    outportb(0xf0,0x0e);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0e = %x (0x00)",c); error=1; }
    outportb(0xf0,0x0f);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0f = %x (0x00)",c); error=1; }
    outportb(0xf0,0x08);    if((c=inportb(0xff))!=0x70){ printf("\n\rset_audio_reg_0x08 = %x (0x70)",c); error=1; }
    outportb(0xf0,0x09);    if((c=inportb(0xff))!=0x01){ printf("\n\rset_audio_reg_0x09 = %x (0x01)",c); error=1; }	
    outportb(0xf0,0x0a);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0a = %x (0x00)",c); error=1; }	
    outportb(0xf0,0x0b);    if((c=inportb(0xff))!=0x00){ printf("\n\rset_audio_reg_0x0b = %x (0x00)",c); error=1; }	

    outportb(0xf0,0x00);	   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!set neytral address!!!
  }
  return error;
}


void set_audio(int rate,int nch)  //from sergey
{
  printf("\n\r set_audio rate : %d , sound : %d", rate , nch );
//____________________________________________________
 outportb(0xf1,0x00); 
  if(rate){
    outportb(0xf0,0x0c);    outportb(0xff,0x00);
    outportb(0xf0,0x0d);    outportb(0xff,0x0f);
    outportb(0xf0,0x0e);    outportb(0xff,0x00);
    outportb(0xf0,0x0f);    outportb(0xff,0x00);
    outportb(0xf0,0x08);    outportb(0xff,0xf0);
    outportb(0xf0,0x09);    outportb(0xff,0x00);	
    outportb(0xf0,0x0a);    outportb(0xff,0x00);	
    outportb(0xf0,0x0b);    outportb(0xff,0x00);	
  }else{
    outportb(0xf0,0x0c);    outportb(0xff,0x00);
    outportb(0xf0,0x0d);    outportb(0xff,0x36);
    outportb(0xf0,0x0e);    outportb(0xff,0x00);
    outportb(0xf0,0x0f);    outportb(0xff,0x00);
    outportb(0xf0,0x08);    outportb(0xff,0x70);	
    outportb(0xf0,0x09);    outportb(0xff,0x01);
    outportb(0xf0,0x0a);    outportb(0xff,0x00);
    outportb(0xf0,0x0b);    outportb(0xff,0x00);

    outportb(0xf0,0x00);	   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!set neytral address!!!
  }
//______________________________________________________>>>>
}



