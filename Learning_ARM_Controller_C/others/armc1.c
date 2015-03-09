#include <LPC214X.h>
void main()
{
int i;
IODIR0=0xffffffff;
while(1)
{
IOSET0=0xffffffff;
for(i=0;i<1000;i++)
for(i=0;i<1000;i++);
IOCLR0=0xffffffff;
for(i=0;i<1000;i++)
for(i=0;i<1000;i++);
}

}