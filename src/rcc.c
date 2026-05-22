#include "memory_map.h"

void
rcc_enable(t_rcc *rcc, uint8_t value){
	rcc->ahb1enr |= value;
}
