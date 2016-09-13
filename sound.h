#ifndef _sound_h_
#define _sound_h_ 
extern "C" void set_audio(int ,int );
void WRBUS( unsigned int ,unsigned int ,unsigned int ,unsigned char );
void Init_sound(void);
void  itoa(long , char *, int );

extern int nTS1[4];// = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 1 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
extern int nTS2[4];// = {0,0,0,0}; // номер TS1,TS2,TS3,TS4 для 2 потока  ::если задействованы 4 TS все номера(nTS1-4)!=0  !!!
extern int n_line;// = 0;
extern int n_slot;// = 15;


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
#define SET_DELAY_TIME      0x80      //

#endif
