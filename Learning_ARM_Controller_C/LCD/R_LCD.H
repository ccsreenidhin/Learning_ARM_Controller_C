   void command4bit(char c)
 {
 int dd;
 dd=c;
 dd=dd<<10;
 IOCLR0=0X00003C00;//clearing p0.10 to p0.13
 IOCLR1=0X01000000;// command register selected
 IOCLR1=0X00800000;// rw=0,write mode selected
 IOSET0=(dd&0x00003C00);
 IOSET1=0X00400000;// en=1,
 delay_ms(1);
 IOCLR1=0X00400000;//en=0

} void command(char c)
 {
 int dd;
 dd=c;
 dd=dd<<6;
 IOCLR0=0x00003C00;
 IOCLR1=0X01000000;
 IOCLR1=0X00800000;
 IOSET0=(dd&0x00003C00); 
 IOSET1=0X00400000;
 delay_ms(1);
 IOCLR1=0X00400000;
 dd=c;
 dd=dd<<10;
 IOCLR0=0x00003C00;
 IOCLR1=0X01000000;
 IOCLR1=0X00800000;
 IOSET0=(dd&0x00003C00); 
 IOSET1=0X00400000;
 delay_ms(1);
 IOCLR1=0X00400000;
 }

 void display(char c)
 {
 int dd;
 dd=c;
 dd=dd<<6;
 IOCLR0=0x00003C00;
 IOSET1=0X01000000;// data register selected
 IOCLR1=0X00800000;
 IOSET0=(dd&0x00003C00); 
 IOSET1=0X00400000;
 delay_ms(1);
 IOCLR1=0X00400000;
 dd=c;
 dd=dd<<10;
 IOCLR0=0x00003C00;
 IOSET1=0X01000000;// data register selected
 IOCLR1=0X00800000;
 IOSET0=(dd&0x00003C00); 
 IOSET1=0X00400000;
 delay_ms(1);
 IOCLR1=0X00400000;
 }
 void display_string(char clr,char pos, char *h)
 {
 int n;
 if(clr==1)
 {
 command(0x01);
 delay_ms(5);
 }
 command(pos);
 delay_ms(5);
 for(n=0;h[n]!='\0';n++)
 {
 display(h[n]);
 }


 }

 void init_lcd(void)
 {
 char cm[4]={0x0e,0x01,0x06,0x80};
 int i;
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
 }