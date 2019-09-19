#include<LPC17xx.h>
unsigned int i,j,sw=0,c=1;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x0000ff0;
	
	LPC_PINCON->PINSEL4 &= 0xfffffffc; // picked CND because easier to calc
	LPC_GPIO2->FIODIR |= 0x00000000;	// DIR set for input all pins;
	
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1)
			sw=1;
		else
			sw=0;
		
		if(sw==0)
			c=c<<1;
		
		
		for(j=0;j<40000;j++);
		LPC_GPIO0->FIOPIN = c<<4;
		
		
	}
}