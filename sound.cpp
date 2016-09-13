#include "sound.h"
#include "EMBISR.H"



//_______________________________________________________________________
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

//_______________________________________________________________________



//программа установки звуковых каналов KOM2 и DEC2
//#define ENCODER   //test
//#define  DECODER    //test 

int nTS1[4] = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 1 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
int nTS2[4] = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 2 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
int n_line = 0;
int n_slot = 15;  

void Init_sound()	//NEED THIS INCLUDE IN INIT KTVM
{
 nTS1[0] = 0; // номер TS1,TS2,TS3,TS4 для 1 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
 nTS1[1] = 0;
 nTS1[2] = 0; 
 nTS1[3] = 0; 

 nTS2[0] = 0;
 nTS2[1] = 0;
 nTS2[2] = 0; 
 nTS2[3] = 0;
 
 //nTS2[4] = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 2 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!

 n_line = 0;
 //n_slot = 15; 
 n_slot = 4; //090629 
}

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

// для телевизионных кодеров/декодеров:n_slot=15; 

void out_compare_ind(int bt1,int bt2);
// базовый адрес портов в-в 0x500 до 0x5ff
unsigned char RDBUS( unsigned int BADR,unsigned int SLOT,unsigned int ADR )  // FUNC FOR  READ DATA ON FLEX BUS
{	
  unsigned int busadr;      // shift on 4 - module selecktor
  unsigned int adr ;        // addr  of bus data window
  
  busadr=(SLOT*16);// 090629 | 0x0500;      // shift on 4 - module selecktor
  adr = (busadr  | ADR);        // addr  of bus data window

  outportb(busadr | 0x001, BADR/256);      // set base H adr
  outportb(busadr , BADR);               // set base L adr
  return ( inportb( adr )); 
}

void WRBUS( unsigned int BADR,unsigned int SLOT,unsigned int ADR,unsigned char data )  // FUNC FOR  write DATA ON FLEX BUS
{
  unsigned int busadr;      // shift on 4 - module selecktor
  unsigned int adr ;        // addr  of bus data window

  busadr=(SLOT*16);// 090629 | 0x0500;      // shift on 4 - module selecktor
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


void set_audio1(int rate,int mode)	   //it was
{
//остановить кодер 
//  i=0; //для 0 канала
//  i=4; //для 1 канала   
  WRBUS(0,n_slot,WINDOW,(unsigned char)(STOP_KODER));
	if(rate){	nTS1[0]=4; nTS1[1]=5; nTS1[2]=6; nTS1[3]=7; // 4E1
	}else{		nTS1[0]=4; nTS1[1]=5; nTS1[2]=6; nTS1[3]=8; }//3E1
	n_line = 20;
	wr_set_zv(1,n_line,256);

  if(mode==1){
    WRBUS(4,n_slot,WINDOW,(unsigned char)(STOP_KODER));
	  if(rate){  nTS2[0]=8; nTS2[1]=9;  nTS2[2]=10; nTS2[3]=11; // 4E1
		}else{	   nTS2[0]=9; nTS2[1]=10; nTS2[2]=12; nTS2[3]=13;}// 3E1
	  wr_set_zv(2,n_line,256);
  }//else{  nTS2[0]=0; nTS2[1]=0;  nTS2[2]=0; nTS2[3]=0;} 
}
/*
void set_audio(int rate,int nch)  //from sergey
{
  printf("\n\r ... void set_audio");

  int i;
  for(i=0;i<8;i++){
    outportb(0xf0,i+0x08);
    outportb(0xff,0 );	
  }

 
    outportb(0xF0,0x0c);
 //   outportb(0xff,0xf0);	
    outportb(0xff,0x0f);	
    outportb(0xf0,0x0d);
    outportb(0xff,0x00);	
   
    //канал 1 4е1
      outportb(0xf0,0x08);
      outportb(0xff,0x00);	
      outportb(0xf0,0x09);
      outportb(0xff,0xf0);
      
     for(i=0;i<8;i++){

    outportb(0xf0,i+0x08);

    printf("\n\r i = %d f0 = 0x%X",i ,inportb(0xf0 ));	
	 printf(" ff = 0x%X",inportb(0xff ));	
  }
  	      	
  
}

*/

#define ADDR_AUDIO	 (0x40)

extern "C" void set_audio(int rate,int nch)  //from sergey
{
  printf("\n\r ... void set_audio");

//  int i;
/*09.08.09
 WRBUS(0,n_slot,WINDOW,(unsigned char)(STOP_KODER));
 delay_mcs(50000l);
 WRBUS(4,n_slot,WINDOW,(unsigned char)(STOP_KODER));
*/ 
/*
  for(i=0;i<8;i++){
    outportb(0xf0,i+0x08);
    outportb(0xff,0 );	
  }
*/	
  if(rate){
  //eaiae 0 4a1
    outportb(0x40,0x08);
    outportb(0x4f,0xf0);	
    outportb(0x40,0x09);
    outportb(0x4f,0x00);	
    if(nch){
    //eaiae 1 4a1
      outportb(0x40,0x0c);
      outportb(0x4f,0x00);	
      outportb(0x40,0x0d);
      outportb(0x4f,0x0f);	
    }
	else  //need check!
	{
	  outportb(0x40,0x0c);
      outportb(0x4f,0x00);	
      outportb(0x40,0x0d);
      outportb(0x4f,0x00);	
  	}
  }else{
  //eaiae 0 3a1
    outportb(0x40,0x08);
    outportb(0x4f,0x70);	
    outportb(0x40,0x09);
    outportb(0x4f,0x01);	
    if(nch){
    //eaiae 1 3a1
      outportb(0x40,0x0c);
      outportb(0x4f,0x00);	
      outportb(0x40,0x0d);
      outportb(0x4f,0x36);	
    }
	else   //need check!
	{
	  outportb(0x40,0x0c);
      outportb(0x4f,0x00);	
      outportb(0x40,0x0d);
      outportb(0x4f,0x00);	
  	}
  }
  outportb(0x40,0x0e);
  outportb(0x4f,0x00);	
  outportb(0x40,0x0f);
  outportb(0x4f,0x00);	
/*
  for(i=0;i<8;i++){
    outportb(0x40,i+0x08);
    printf("\n\r i = %d f0 = 0x%X",i ,inportb(0x40 ));	
	  printf(" ff = 0x%X",inportb(0x4f ));	
  }
*/
  outportb(0x40,0);
}





