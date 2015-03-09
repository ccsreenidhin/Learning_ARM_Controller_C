#include<LPC214X.h>
void main()
{
char ch;
PINSEL0=0X05;
U0LCR=0X83;
U0DLM=0X00;
U0DLL=97;
U0LCR=0X03;
  while(1)
  {
  while(!(U0LSR&(0X01)));
  ch=U0RBR;
 // U0THR=ch;
//  while(!(U0LSR&(1<<6)));
  } 
}