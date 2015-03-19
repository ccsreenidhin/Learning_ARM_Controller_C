#include <LPC214X.H>
#include"DELAY.H"
  void main()
  {
    int I;
	IODIR0=0XFFFFFFFF;

	while(1)
	{
		 IOSET0=0XFFFFFFFF;
		 delay_ms(2)
		 IOCLR0=0XFFFFFFFF;
		 delay_ms(2)
	}
  }
