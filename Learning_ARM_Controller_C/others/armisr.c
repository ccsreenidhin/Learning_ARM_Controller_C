#include<LPC214X.h>

void myISR(void)__irq
{
EXTINT=0X01;
if(IOSET1==0X0FF)
IOCLR1=0X0FF;
else
IOSET1=0X0FF;
VICVectAddr=0x00;
}

void init_vect();
void main()
{
PINSEL0=0X0c;
IODIR0=0x00;
IODIR1=0X0FF;
//INTWAKE=0X01;
EXTMODE=0x01;
EXTPOLAR=0X01;
init_vect();
while(1);
}

void init_vect()
{
unsigned int x=14;
VICVectCntl0=(1<<5)|x;
VICVectAddr0=(unsigned)myISR;
VICIntEnable|=(1<<14);

}


