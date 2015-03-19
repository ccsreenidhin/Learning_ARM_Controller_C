void uart0_init(void)
{
 PINSEL0 &=0XFFFFFFF0;	// CLEARING BIT0-BIT 3
 PINSEL0 |=0X00000005;// CONFIGURE P0.0 &P0.1
 U0LCR=0X80;//DLAB=1(FOR ENABLING)
 U0DLL=97; //  BAUD RATE SET UP
 U0DLM=0;
 U0FCR=0X01;//FIFO ENABLING
 U0LSR=0X01;// RBR CONTAIN VALID DATA
 U0LCR=0X03;//8 BIT CHARACTER LENGTH
 U0TER=0X80;//ENABLING UART TRANSMISSION
 U0IER=0x01;//enable int
}

void uart1_init(void)
{
 PINSEL0 &=0XFFF0FFFF;	// CLEARING BIT16-BIT 19
 PINSEL0 |=0X00050000;// CONFIGURE P0.8.0 &P0.9
 U1LCR=0X80;//DLAB=1(FOR ENABLING)
 U1DLL=97; //  BAUD RATE SET UP
 U1DLM=0;
 U1FCR=0X01;//FIFO ENABLING
 U1LSR=0X01;// RBR CONTAIN VALID DATA
 U1LCR=0X03;//8 BIT CHARACTER LENGTH
 U1TER=0X80;//ENABLING UART TRANSMISSION
 U1IER=0x01;
}

void putc0(char x)
{
char f;

U0THR=x;
do
{
f=U0LSR;
f=f&0x40;
}
while( f==0);

}

void putc1(char x)
{
char f;

U1THR=x;
do
{
f=U1LSR;
f=f&0x40;
}
while( f==0);

}

char getc0(void)
{
char m,f;

do
{
f=U0LSR;
f=f&0x01;
}
while( f==0);
m=U0RBR;

return(m);
}

 char getc1(void)
{
char m,f;

do
{
f=U1LSR;
f=f&0x01;
}
while( f==0);
m=U1RBR;

return(m);
}


 void puts0(char *i)
   {
   
      while(*i)
      {   
      putc0(*i++);
      
      }
      
   }


   void gets0(char *j)
      {
      char c;
         while(1)
         {
         c=getc0();
            if(c==0x0D)
            break;
         else   
         *j++=c;
         
         }
         *j='\0';
         
      }



void puts1(char *i)
   {
   
      while(*i)
      {   
      putc1(*i++);
      
      }
      
   }


   void gets1(char *j)
      {
      char c;
         while(1)
         {
         c=getc1();
            if(c==0x0D)
            break;
         else   
         *j++=c;
         
         }
         *j='\0';
         
      }



void clear_rxfifo_uart0(void)
{
char f;
U0FCR |=0X02;

do
{
f=U0FCR;
f=f&0x02;
}
while(f==0x02);

}
 void clear_rxfifo_uart1(void)
{
char f;
U1FCR |=0X02;

do
{
f=U1FCR;
f=f&0x02;
}
while(f==0x02);
}
