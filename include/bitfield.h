#ifndef _BITFIELD_H
# define _BITFIELD_H


#define CLEAR_FIELD(target, pin, width) \
    ((target) & ~(((1UL << (width)) - 1) << ((pin) * (width))))

#define SET_FIELD(target, pin, width, value) \
    ( \
        ((target) & ~(((1UL << (width)) - 1) << ((pin) * (width)))) \
        | (((value) & ((1UL << (width)) - 1)) << ((pin) * (width))) \
    )	

#endif
