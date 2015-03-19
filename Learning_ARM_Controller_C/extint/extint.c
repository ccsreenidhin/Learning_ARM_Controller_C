#include <LPC214X.H>
unsigned int a;
void ext(void)__irq 
	{
	IOSET1=a;
	a=~a;
	IOCLR1=a;
	EXTINT=0X01;
	VICVectAddr=0X00;
	}
void main()
	{
	a=0xFFFFFFFF;
	IODIR1=0XFFFFFFFF;
	IOCLR1=0XFFFFFFFF;
	PINSEL0=0X0000000C;
	VICIntSelect=0X00000000;
	EXTMODE=0X01;
	EXTPOLAR=0X01;
	VICVectCntl0=0X20|14;
	VICVectAddr0=(unsigned)ext;
	VICIntEnable=0X00004000;
	while(1);
	}