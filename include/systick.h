#ifndef _SYSTICK_H
# define _SYSTICK_H

#define ONE_MSEC_LOAD 16000

#define CTRL_ENABLE (1U << 0)
#define CTRL_CLCKSRC (1U << 2)
#define CTRL_COUNTFLAG (1U << 16)

#include "memory_map.h"

void	systick_msec_delay(t_systick *systick, uint32_t delay);

#endif
