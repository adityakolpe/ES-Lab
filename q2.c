#include<LPC17xx.h>
unsigned int i,j,sw=0,c=0;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x0000ff0;
	
	LPC_PINCON->PINSEL4 &= 0xfcffffff; // picked CNB
	LPC_GPIO2->FIODIR |= 0x00000000;	// DIR set for input all pins;
	
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
			sw=1;
		else
			sw=0;
		
		if(sw==0)
			c++;
		else
			c--;
		
		for(j=0;j<50000;j++);
		LPC_GPIO0->FIOPIN = c<<4;
		
		
	}
}