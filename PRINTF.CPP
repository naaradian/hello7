//#include <stdarg.h>
//#include <dos.h>

const unsigned int debug_port=0xff80;
//#define debug_port    1
//#define debug_rate    5
//#define debug_parity  'n'
//#define sReceive   6
//#define sTransmit  4
#define sReceive   4
#define sTransmit  5
#define sStatus    2

union word{
  unsigned char c[2];
  unsigned int i;
};

void out_str(char* str)
{
  int i=0;
  do{
    while(!(inportb(debug_port+sStatus)&0x20));//{
    outportb(debug_port+sTransmit,str[i++]);
  } while(str[i]);
}

/*
char* int2hex(int w,char* s)
{
  char c;
  word r;

  r.i=w;
  c=r.c[1];
  if(((c&0xf0)>>4)>9) *s++=((c&0xf0)>>4)+87;
    else s[0]=((c&0xf0)>>4)+48;
  if((c&0x0f)>9) *s++=(c&0x0f)+87;
    else *s++=(c&0x0f)+48;
  c=r.c[0];
  if(((c&0xf0)>>4)>9) *s++=((c&0xf0)>>4)+87;
    else *s++=((c&0xf0)>>4)+48;
  if((c&0x0f)>9) *s++=(c&0x0f)+87;
    else *s++=(c&0x0f)+48;
  return s;
}

char* int2char(int v,char* s)
{
  int r,w;
  int i,j;
  int rs;

  if(v<0){
    *s++='-';
    w=v*(-1);
  }else w=v;
  rs=0;
  j=10000;
  for(i=5;i;i--){
    r=(w-rs)/j;
    rs+=(r*j);
    if(rs)*s++=r+48;
    j/=10;
  }
  return s;
}

*/
char* uint2char(unsigned int v,char* s)
{
  unsigned int r,w;
  unsigned int i,j;
  unsigned int rs;

  w=v;
  rs=0;
  j=10000;
  for(i=5;i;i--){
    r=(w-rs)/j;
    rs+=(r*j);
    if(rs)*s++=r+48;
    j/=10;
  }
  return s;
}

void printf(char *format ...)
{
	/*
  char* p;
  char cp;
  char* s;
  char str[80];
  int i,v;
  int* ip;

  p=format;
  va_list ap;
  s=str;
  i=0;
  *s++='&'; *s++='T'; s+=2;
  va_start(ap,format);
  for(;;){
    while((*p!='%')&&*p){
      *s++=*p++;
      if((s-str)>73) return;
    }
    if(!*p) break;
    p++;
    switch(*p++){
      case'i': v=va_arg(ap,int);
	       s=uint2char(v,s);
	       break;
      case'u': v=va_arg(ap,int);
	       s=int2char(v,s);
	       break;
      case'x': v=va_arg(ap,int);
	       s=int2hex(v,s);
	       break;
      case'c': cp=va_arg(ap,char);
	       *s++=cp;
    }
  }
  *s=0;
  i=s-str-4;
  int2hex(i,str);
  str[0]='&'; str[1]='T';
  out_str(str);
  va_end(ap);
	*/
}

void sprintf(char* str,char *format ...)
{
	/*
  char* p;
  char cp;
  char* s;
//  char str[80];
  int i,v;
  int* ip;

  p=format;
  va_list ap;
  s=str;
  i=0;
//  *s++='&'; *s++='T'; s+=2;
  va_start(ap,format);
  for(;;){
    while((*p!='%')&&*p){
      *s++=*p++;
      if((s-str)>73) return;
    }
    if(!*p) break;
    p++;
    switch(*p++){
      case'i': v=va_arg(ap,int);
	       s=uint2char(v,s);
	       break;
      case'u': v=va_arg(ap,int);
	       s=int2char(v,s);
	       break;
      case'x': v=va_arg(ap,int);
	       s=int2hex(v,s);
	       break;
      case'c': cp=va_arg(ap,char);
	       *s++=cp;
    }
  }
  *s=0;
//  i=s-str-4;
//  int2hex(i,str);
//  str[0]='&'; str[1]='T';
//  out_str(str);
  va_end(ap);
	*/
}
/*
void main()
{
  int j,i,a;
  long l;
  a=30;
//  for(;;){
//    for(j=0;j<30000;j++)
//      for(i=0;i<30000;i++) l=i*j;
    printf("Test N %u",a++);
//  }
}
*/