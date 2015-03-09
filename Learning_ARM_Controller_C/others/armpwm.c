#include"LPC214X.h"
void main()
{
  PINSEL0=0X02;
  PWMPR=15000;
  PWMMR0=0X0A;
  PWMMR1=0X05;
  PWMMCR=0X02;
  PWMLER=0X03;
  PWMPCR=(1<<9);
  PWMTCR=(1<<0); 
  PWMTCR=(1<<2); 
  PWMTCR=(1<<0)|(1<<3); 
  while(1)
  {
  }
}