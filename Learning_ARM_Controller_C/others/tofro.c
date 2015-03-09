#include<LPC214X.h>
void main()
{
 unsigned int i;
 unsigned int long a=1;
 IODIR0=0XFFFFFFFF;
 while(1)
  {
  a=0X00000001;
  while(a!=0x80000000)
   {
    IOCLR0=0XFFFFFFFF;
    a=a<<1;

    IOSET0=a;
    for(i=0;i<1000000;i++);
   }
   a=0X80000000;
   if(a==0X80000000)
   {
    while(a!=0x00000001)
    {
	IOCLR0=0XFFFFFFFF;
	a=a>>1;
    IOSET0=a;
    for(i=0;i<1000000;i++);
    }
   }
  }
}