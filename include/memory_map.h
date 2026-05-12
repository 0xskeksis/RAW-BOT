#ifndef _MEMORY_MAP_H
# define _MEMORY_MAP_H

#include <stdint.h>

enum e_pin_state{
    PIN_STATE_INPUT = 0,
    PIN_STATE_OUTPUT,
    PIN_STATE_ALTERNATE,
    PIN_STATE_ANALOG,
};

#define CLEAR_FIELD(target, pin, width) \
    ((target) & ~(((1UL << (width)) - 1) << ((pin) * (width))))

#define SET_FIELD(target, pin, width, value) \
    ( \
        ((target) & ~(((1UL << (width)) - 1) << ((pin) * (width)))) \
        | (((value) & ((1UL << (width)) - 1)) << ((pin) * (width))) \
    )	

typedef volatile struct _periphericals {
    uint32_t moder;
    uint32_t otyper;
    uint32_t ospeeder;
    uint32_t pupdr;
    uint32_t idr;
    uint32_t odr;
    uint32_t bsr;
    uint32_t lckr;
    uint32_t afrl;
    uint32_t afrh;
} t_periphericals;

#endif
