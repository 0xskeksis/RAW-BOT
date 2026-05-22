#ifndef _GPIO_H
# define _GPIO_H

/*
 *@brief:
 *	GPIO enum and functions
 */

#include "memory_map.h"
#include <stdbool.h>

#define GPIOAEN (1 << 0)
#define GPIOBEN (1 << 1)
#define GPIOCEN (1 << 2)


enum e_gpio_value
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1,
};

void led_init(t_rcc *rcc, t_gpio *gpioa);
void led_off(t_gpio *gpioa);
void led_on(t_gpio *gpioa);

void button_init(t_rcc *rcc, t_gpio *gpioa);
bool get_button_state(t_gpio *gpioc);

#endif
