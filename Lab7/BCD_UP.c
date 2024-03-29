#include<LPC17xx.h>
#include<stdio.h>

unsigned long LED[] = {0x3F0, 0x060, 0x5B0, 0x4F0, 0x660, 0x6D0, 0x7D0, 0x070, 0x7F0, 0x6F0};
unsigned int j, s=0, dig0=0, dig1=0, dig2=0, dig3=0;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL3 &= 0XFFC03FFF;
	LPC_GPIO0->FIODIRL |= 0x0FF0;
	LPC_GPIO1->FIODIRH |= 0x0780;
	LPC_GPIO0->FIOMASKL |= 0xF00F;
	LPC_GPIO1->FIOMASKH |= 0xF87F;
	
	while(1)
	{
		LPC_GPIO1->FIOPINH = 0x0000;
		LPC_GPIO0->FIOPINL = LED[dig0];
		for(j=0;j<100;j++);
		LPC_GPIO1->FIOPINH = 0xFFFF;
		
		LPC_GPIO1->FIOPINH = 0x0080;
		LPC_GPIO0->FIOPINL = LED[dig1];
		for(j=0;j<100;j++);
		LPC_GPIO1->FIOPINH = 0xFFFF;
		
		LPC_GPIO1->FIOPINH = 0x0100;
		LPC_GPIO0->FIOPINL = LED[dig2];
		for(j=0;j<100;j++);
		LPC_GPIO1->FIOPINH = 0xFFFF;
		
		LPC_GPIO1->FIOPINH = 0x0180;
		LPC_GPIO0->FIOPINL = LED[dig3];
		for(j=0;j<100;j++);
		LPC_GPIO1->FIOPINH = 0xFFFF;
		
		if(dig0==0xA)
		{
			dig0=0;
			dig1++;
		
		if(dig1==0xA)
		{
			dig1=0;
			dig2++;
		
		if(dig2==0xA)
		{
			dig2=0;
			dig3++;
		
		if(dig3==0xA)
		{
			
			dig3=0;
		}}}}
	  for(j=0;j<100;j++);
		s++;
		if(s==200)
	  {
			dig0++;
			s=0;
		}		
	}
}
