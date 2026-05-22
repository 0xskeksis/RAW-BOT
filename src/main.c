#include "gpio.h"
#include "memory_map.h"
#include "raw_bot.h"

int
main(){
	volatile t_rcc	*rcc = (t_rcc *)RCC_BASE;
	volatile t_gpio	*gpioa = (t_gpio *)GPIOA_BASE;
	volatile t_gpio	*gpioc = (t_gpio *)GPIOC_BASE;

	rcc_enable(GPIOAEN, &rcc->ahb1enr);
	gpio_init(gpioa, 5, PIN_STATE_OUTPUT);

	rcc_enable(GPIOCEN, &rcc->ahb1enr);

	gpio_init(gpioc, 13, PIN_STATE_INPUT);
	bool btn_state = false;
	while(1){
		btn_state = get_button_state(gpioc);
		if (btn_state)
			led_on(gpioa);
		else
			led_off(gpioa);
	}
}
