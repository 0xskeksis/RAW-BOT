// #include <stdio.h>
//




#include "memory_map.h"

void
delay(void){
	for (volatile int i = 0; i < 100000; i++)
	{}
}

int
main(){
	volatile t_gpio	*gpioa = (t_gpio *)GPIOA_BASE;
	volatile t_rcc	*rcc = (t_rcc *)RCC_BASE;

	
	rcc->ahb1enr |= 1 << 0; // useless but 
	gpioa->moder |= (1U << 10);
	gpioa->moder &= ~(1U << 11);
	while(1){
		gpioa->odr = 1 << 5;
		delay();
		gpioa->odr = 0;
		delay();
	}
}
