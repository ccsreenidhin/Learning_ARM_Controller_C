#include <LPC214X.H>

 void main()
 {
 	IODIR0=0XFFFFFFFF;
	T0PR=0X00003A97;
	T0TCR=0X02;
	
	T0TCR=0x01;

	while(1)
	{
		IOSET0=0xFFFFFFFF;
		while(T0TC<1);
		IOCLR0=0xFFFFFFFF;
		T0TC=0x00;
		while(T0TC<1);
		T0TC=0x00;
		
	   
	}
 }
 