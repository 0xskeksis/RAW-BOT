#include "raw_bot.h"

void	systick_msec_delay(t_systick *systick, uint32_t delay){
	systick->sysr_rvr = ONE_MSEC_LOAD - 1;

	systick->sysr_cvr = 0;

	systick->sysr_csr |= CTRL_ENABLE;

	for (uint32_t i = 0; i < delay; i++){
		while ((systick->sysr_csr & CTRL_COUNTFLAG) == 0){}
	}
	systick->sysr_csr = 0;
}
