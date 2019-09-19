#include<LPC17xx.h>

unsigned int i, j;
unsigned long LED = 0x00000010;

int main(void)
{
	SystemInit();	/*Add these two functions for its
									internal operations*/
	
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;	/*Configure Port0 pins
								P0.4-P0.11 as GPIO function*/
	
	LPC_GPIO0->FIODIR |= 0x00000FF0; /*Configure P0.4-P0.11 as 
								output ports*/
	
	while(1)
	{
		LED = 0x00000010; /*Initial value on the LED*/
		
		for(i = 1; i < 9; ++i)
		{
			LPC_GPIO0->FIOSET = LED;
			
			for(j = 0; j < 10000; ++j);
			LED <<= 1;
			
		}
		
		LED = 0x00000010;
		
		for(i = 1; i < 9; ++i)
		{
			LPC_GPIO0->FIOCLR = LED;
			
			for(j = 0; j < 10000; ++j);
			LED <<= 1;
			
		}
		
	}
}