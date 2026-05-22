#include "gpio.h"
#include <stdbool.h>
#include "memory_map.h"

#define LED_BS5 (1U << 5)
#define LED_BR5 (1U << 21)
#define BTN_PIN (1U << 13)

void
led_init(t_rcc *rcc, t_gpio *gpioa){
	rcc->ahb1enr |= GPIOAEN;
	gpioa->moder |= (1UL << 10);
	gpioa->moder &= ~(1UL << 11);
}

void
led_on(t_gpio *gpioa){
	gpioa->bsrr = LED_BS5;
}

void
led_off(t_gpio *gpioa){
	gpioa->bsrr = LED_BR5;
}

void
button_init(t_rcc *rcc, t_gpio *gpioc){
	rcc->ahb1enr |= GPIOCEN;

	gpioc->moder &= ~(1UL<<26);
	gpioc->moder &= ~(1UL<<27);
}

bool
get_button_state(t_gpio *gpioc){
	return (!(gpioc->idr & BTN_PIN));
}
