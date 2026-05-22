#include "gpio.h"
#include "utils.h"

//PC13 pin -

int
main(){
	volatile t_rcc	*rcc = (t_rcc *)RCC_BASE;
	volatile t_gpio	*gpioa = (t_gpio *)GPIOA_BASE;
	volatile t_gpio	*gpioc = (t_gpio *)GPIOC_BASE;

	led_init(rcc, gpioa);	
	button_init(rcc, gpioc);	
	bool btn_state = false;
	while(1){
		btn_state = get_button_state(gpioc);
		if (btn_state)
			led_on(gpioa);
		else
			led_off(gpioa);
	}
}
