#ifndef _RCC_H
# define _RCC_H

#include "memory_map.h"


void
rcc_enable(uint32_t value, volatile uint32_t *_register);

#endif
