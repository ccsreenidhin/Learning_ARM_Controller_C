#include <LPC214X.H>
#include "serial.h"

 void main()
 {
 char a[]="";

 	uart0_init();
	uart1_init();

	while(1)
	{
		gets0(a);
		puts0(a);
		puts1(a);
	}
 }
 