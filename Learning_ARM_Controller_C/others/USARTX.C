#include<LPC214X.h>
void main()
{
 PINSEL0=0X05;
 U0LCR=0X83;
 U0DLM=0X00;
 U0DLL=97;
	U0LCR&=~(1<<7);
while(1)
 {
	U0THR='A';
	while(!(U0LSR&(1<<6)));

  }
}