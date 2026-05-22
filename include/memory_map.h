#ifndef _MEMORY_MAP_H
# define _MEMORY_MAP_H

/*
 *@brief:
 * Base adresses and registers structs
 */

#include <stdint.h>

#define RCC_BASE	0x40023800

#define GPIOA_BASE	0x40020000
#define GPIOB_BASE	0x40020400
#define GPIOC_BASE	0x40020800
#define GPIOD_BASE	0x40020C00


#define LED_PIN 5
#define BTN_PIN 13

enum e_pin_state{
    PIN_STATE_INPUT = 0,
    PIN_STATE_OUTPUT,
    PIN_STATE_ALTERNATE,
    PIN_STATE_ANALOG,
};

typedef volatile struct _gpio {
    uint32_t moder;
    uint32_t otyper;
    uint32_t ospeeder;
    uint32_t pupdr;
    uint32_t idr;
    uint32_t odr;
    uint32_t bsrr;
    uint32_t lckr;
    uint32_t afrl;
    uint32_t afrh;
} t_gpio;

typedef volatile struct _rcc {
	uint32_t	cr;
	uint32_t	pllcfgr;
	uint32_t	cfgr;
	uint32_t	cir;
	uint32_t	ahb1rstr;
	uint32_t	ahb2rstr;
	uint32_t	ahb3rstr;
	uint32_t	reserved_a;
	uint32_t	apb1rstr;
	uint32_t	apb2rstr;
	uint32_t	reserved_b;
	uint32_t	reserved_c;
	uint32_t	ahb1enr;
	uint32_t	ahb2enr;
	uint32_t	ahb3enr;
	uint32_t	reserved_d;
	uint32_t	apb1enr;
	uint32_t	apb2enr;
	uint32_t	reserved_e;
	uint32_t	reserved_f;
	uint32_t	ahb1lpenr;
	uint32_t	ahb2lpenr;
	uint32_t	ahb3lpenr;
	uint32_t	reserved_g;
	uint32_t	apb1lpenr;
	uint32_t	apb2lpenr;
	uint32_t	reserved_h;
	uint32_t	reserved_i;
	uint32_t	bdcr;
	uint32_t	csr;
	uint32_t	reserved_j;
	uint32_t	reserved_k;
	uint32_t	sscgr;
	uint32_t	plli2scfgr;
	uint32_t	pllsaicfgr;
	uint32_t	dckcfgr;
	uint32_t	ckgatenr;
	uint32_t	dckcfgr2;
}t_rcc;

typedef struct s_systick{
	uint32_t	sysr_csr;
	uint32_t	sysr_rvr;
	uint32_t	sysr_cvr;
	uint32_t	sysr_calib;
}t_systick;


#endif
