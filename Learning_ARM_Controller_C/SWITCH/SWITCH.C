#include <LPC214X.H>
  void main()
  {

	IODIR0=0XFFFFFFFE;
	IODIR1=0XFFFFFFFF;

	while(1)
	{
	
		if(IOPIN0=IOPIN0&0X00000001)
		{
			IOSET1=0XFFFF0000;
		}
		else
		{
		 IOCLR1=0XFFFF0000;
		} 

    }
	}