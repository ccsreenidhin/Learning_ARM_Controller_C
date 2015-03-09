#include<LPC214X.h>
void main()
{
unsigned int x,y;
 PINSEL0=0x15400000;
 
 IODIR0=0XFFFFFFFF;
  while(1)
  {
  AD0CR=0x01200402;
    while(!(x&(0x80000000)))
    {
     x=AD0GDR;
    }
x=((x>>6)&0x03ff);
if(x!=y)
{
IOCLR0=y;
IOSET0=x;
y=x;
} 
}
}