#include <LPC214X.H>
 #include "DELAY.h"
 #include"R_LCD.h"
 void main()
 {
 char cm[4]={0x0e,0x01,0x06,0x80};
 int i;
 char val[15]="RANJITH REMASAN";

 
 IODIR0|=0X00003C00;
 IODIR1|=0X01C00000;
 delay_ms(20);
 command4bit(0X03);
 delay_ms(10);
 command4bit(0X03); 
 delay_ms(10);
 command4bit(0X03); 
 delay_ms(10);
 command4bit(0X02);
 delay_ms(10);
 command(0X28);
  delay_ms(10);
 for(i=0;i<4;i++)
 {
 command(cm[i]);
 delay_ms(5);
 }
 while(1)

 {
for(i=0;i<15;i++)
 {
 display(val[i]);
 delay_ms(50);
 }
delay_ms(1000);
command(0x01);
delay_ms(10);
}
//display_string(1,0xc0," cat");
// display_string(0,0x85," rat");
// delay_ms(2000);
// display_string(1,0xc0,"lcd worked");
 

 


 }


 

 

 
 