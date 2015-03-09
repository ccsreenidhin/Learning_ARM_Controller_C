#include<LPC214X.h>

void usartISR(void)__irq
{
char x;
U0LSR=0X00;
x=U0RBR;
U0THR=x;
while(!(U0LSR&(1<<6)));
VICVectAddr=0x00;
}

void init_vect();
void main()
{
PINSEL0=0X05;
U0LCR=0X83;
U0DLM=0X00;
U0DLL=0X61;
U0LCR=0X03;
U0IER=0X01;
init_vect();
while(1);
}

void init_vect()
{
unsigned int x=6;
VICVectCntl3=(1<<5)|x;
VICVectAddr3=(unsigned)usartISR;
VICIntEnable|=(1<<6);
}