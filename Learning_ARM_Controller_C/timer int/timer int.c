#include <LPC214X.H>
unsigned int a=0xffffffff;
void myISR(void)__irq
{
   	
	IOSET0=a;
	a=~a;
	IOCLR0=a;
		T0IR=0x01;	 
	VICVectAddr=0x00;	
}
  void main()
  {

   	IODIR0=0XFFFFFFFF;
	T0MCR=0x03;
	T0MR0=0x05;
	T0PR=0X00000007;
	//	T0IR=0x01;

	T0TCR=0X02;
	T0TCR=0x01;

   
   VICIntSelect = 0x00000000;		//intrrupt 
   VICIntEnable = 0x000000010;
   
   VICVectAddr0 = (unsigned)myISR;
   VICVectCntl0 = (0x20|4);

   while(1);
    
  }