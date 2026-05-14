#ifndef _GPIO_H
# define _GPIO_H

/*
 *@brief:
 *	GPIO enum and functions
 */

#include "memory_map.h"

enum e_gpio_value
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1,
};

void
gpio_config(t_gpio *port, uint32_t pin, uint8_t mode){

}

void
gpio_write(t_gpio *port, uint32_t pin, uint8_t value){

}

uint8_t
gpio_read(t_gpio *port, uint32_t pin){

}

#endif
