void delay_us(unsigned int dly)
{
int a,b;

/*
CPU clk cclk = 60MHz.
Time period of cclk = 1/(60*10^6)  seconds
M.cycle =  1 cclk time period.
M.cycle = 1/(60*10^6)  seconds
*/
for(b=0;b<dly;b++)
{

for(a=0;a<10;a++)	//in this loop there are 6 instructions getting
{					// executed 10 times. (a<10, ; , and a++)
;			 // so time to execute this loop is
}	 // 10*6*(1/( 60*10^6) )
	 // = (10*6*1)/( 60*10^6) )
	 // = 1/(10^6) = 1 usec
}



}

void delay_ms(unsigned int dly)
{
int a,b,c;

for(b=0;b<dly;b++)
{
for(c=0;c<1000;c++ )
{

for(a=0;a<10;a++)	//in this loop there are 6 instructions getting
{					// executed 10 times. (a<10, ; , and a++)
;			 // so time to execute this loop is
}	 // 10*6*(1/( 60*10^6) )
	 // = (10*6*1)/( 60*10^6) )
	 // = 1/(10^6) = 1 usec
}
}

}