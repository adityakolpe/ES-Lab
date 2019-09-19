#include<LPC17xx.h>
unsigned int i,j,c=0;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xff0000ff;
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	while(1)
	{
		for(i=0;i<30000;i++);
		c++;
		LPC_GPIO0->FIOPIN = c<<4;
		
	}
}
