#include <LPC214X.H>
#include"DELAY.H"
  void main()
  {
	unsigned int I,j,a;
	IODIR0=0XFFFFFFFC;
	IODIR1=0XFFFFFFFF;

	while(1)
	{
	
		a=IOPIN0&0X00000003;
		while(a==0X00000001)
		{

		   I=0X00010000;
		for(j=0;j<=15;j++)
	 		{
		
			 	IOSET1=I;
			delay_ms(50);
				IOCLR1=I;
				I=I<<1;
	 		}
    			
			a=IOPIN0&0X00000003;	
		}
		a=IOPIN0&0X00000003;
		while(0X00000002==a)
		{
		  I=0X80000000;
		for(j=0;j<=15;j++)
	 		{
			
			 	IOSET1=I;
				delay_ms(50);
				IOCLR1=I;
				I=I>>1;
	 		}
    			
				a=IOPIN0&0X00000003;
	
		}
		a=IOPIN0&0X00000003;
		while(0X00000003==a)
		{
		 
		
			 	IOSET1=0xFFFFFFFF;
				delay_ms(50);
				IOCLR1=0xFFFFFFFF;
				delay_ms(50);
				
	 		  a=IOPIN0&0X00000003;
    			
			
		}
		a=IOPIN0&0X00000003;
			while(0X00000000==a)
		{
		 
			 	
				IOCLR1=0xFFFFFFFF;
				
				a=IOPIN0&0X00000003;	
	 		
    			
			
		}
				


    }
	}