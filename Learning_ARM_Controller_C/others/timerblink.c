#include<LPC214X.h>
void main()
{ 
  PINSEL0=0X00;
  T0CTCR=0X00;
  T0PR=	0X03A97;
  IODIR0=0XFFFFFFFF;
  while(1)
  {
   T0TC=0X00;
   T0TCR=0X01;
   while(!(T0TC==0X03E8));
   if(IOSET0==0XFFFFFFFF)
   IOCLR0=0XFFFFFFFF;
   else
   IOSET0=0XFFFFFFFF;
   T0TCR=0X02;
  }
}