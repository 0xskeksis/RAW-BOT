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
#define GPIODEN (1 << 3)


enum e_gpio_value
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1,
};

void led_off(t_gpio *gpioa);
void led_on(t_gpio *gpioa);

bool get_button_state(t_gpio *gpioc);

void	gpio_init(t_gpio *port, uint8_t pin, uint32_t mode);

#endif
