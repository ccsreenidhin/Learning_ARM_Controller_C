#include <LPC214X.H>
#include"SEREAL.h"
 unsigned int a=0;
 unsigned char c;
void FIQ_Handler(void)__fiq
{
   	
    c=getc0();
	
	a=1;	 
	VICVectAddr=0x00;	
}
  void main()
  {
  uart0_init();
 

   VICIntSelect = 0x000000040;		//intrrupt 
   VICIntEnable = 0x000000040;
   
  // VICVectAddr= (unsigned)myISR;
  // VICVectCntl0 = (0x20|4);

   while(1)
   {

   if(a==1)
   {
   	putc0(c) ;
	a=0;
	}
   
   }

    
  }
