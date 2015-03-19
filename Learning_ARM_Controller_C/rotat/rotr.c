#include <LPC214X.H>
#include"DELAY.H"
  void main()
  {
    int I=000000001,j;
	IODIR0=0XFFFFFFFF;

	while(1)
	{
	 for(j=0;j<=32;j++)
	 {
	 	IOSET0=I;
		delay_ms(50);
		IOCLR0=I;
		I=I<<1;
	 }
    I=0X00000001;
		 
	}
  }