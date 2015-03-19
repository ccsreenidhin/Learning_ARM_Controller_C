void adc_init()
{
PINSEL1=0x01000000;
IO1DIR=0xFFFF0000;
AD0CR=0x01200A02;
}
void adc_read()
{
	unsigned int a;
	do
	{
	a=AD0GDR;
	a=a&0X80000000;
	}
	while(a==0)
	a=AD0GDR;
	a=a<<6;
	IO1CLR=0xffff0000
	IO1SET=b;
}