#include<LPC214X.h>
void main()
{
unsigned int long o,a=0X00000004;
int i;
IODIR0=0XFFFFFFFC;
while(1)
{
o=(IOPIN0&(0x00000003));
 switch(o)
   {
    case 0:{IOCLR0=0XFFFFFFFF;break;}
    case 1:{IOCLR0=0XFFFFFFFF;a=a<<1;if(a==0X80000000) a=0x00000004;IOSET0=a;for(i=0;i<10000;i++);break;}
    case 2:{IOCLR0=0XFFFFFFFF;a=a>>1;if(a==0X00000004) a=0x80000000;IOSET0=a;for(i=0;i<10000;i++);break;}
    case 3:{IOSET0=0XFFFFFFFC;break;}
	//default:{o&=0;break;}
}
}

}