#include "memory_map.h"

void
rcc_enable(uint32_t value, volatile uint32_t *_register){
	(*_register) |= value;
}
