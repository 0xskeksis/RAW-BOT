#include "gpio.h"
#include <stdbool.h>
#include <stdint.h>
#include "memory_map.h"

void
gpio_init(t_gpio *port, uint8_t pin, uint32_t mode){
	uint32_t	value = mode << (pin * 2);
	uint32_t	mask = 0b11 << (pin * 2);

	port->moder &= ~mask;
	port->moder |= value;
}

void
gpio_write(t_gpio *port, uint8_t pin, uint8_t pin_mode){
	pin += (!pin_mode * 16);
	port->bsrr = (1UL << pin);
}

bool
gpio_read(t_gpio *port, uint32_t pin){
	return (!(port->idr & (1UL << pin)));
}

void
led_on(t_gpio *gpioa){
	gpio_write(gpioa, LED_PIN, 1);
}

void
led_off(t_gpio *gpioa){
	gpio_write(gpioa, LED_PIN, 0);
}

bool
get_button_state(t_gpio *gpioc){
	return gpio_read(gpioc, BTN_PIN);
}


