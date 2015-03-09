#include <LPC214X.h>
void main()
{
 int i;
 unsigned long int a;
 IODIR0=0xfffffffe;
 while(1)
   {
   while(!((a=IOPIN0)&(0x00000001)));
   while((a=IOPIN0)&(0x00000001));
   for(i=0;i<1000;i++);
   if(IOSET0==0xfffffffe) 
   IOCLR0=0XFFFFFFFF;
   else
   IOSET0=0XFFFFFFFFE;
   a=0;
   }
}
