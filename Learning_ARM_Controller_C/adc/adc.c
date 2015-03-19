#include <LPC214X.H>
void adc_init();
void adc_read();
 void main()
 {
   adc_init();
   while(1)
   adc_read();

 } 


void adc_init()
{
PINSEL1=0x01000000;
IO1DIR=0xFFFF0000;
AD0CR=0x01200A02;
}
void adc_read()
{
	unsigned int a;
	AD0CR=0x01200A02;
	do
	{
	a=AD0GDR;
	a=a&0X80000000;
	}
	while(a==0x00);
	a=AD0GDR;
	a=a<<0x10;
	IO1CLR=0xffff0000;
	IO1SET=a;

}