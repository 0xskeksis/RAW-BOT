ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .isr_vector 0x08000000 :
    {
		. = ALIGN(4);
        KEEP(*(.isr_vector))
		. = ALIGN(4);
    } > FLASH

    .text :
    {
		. = ALIGN(4);
        *(.text*)
    } > FLASH

    .data :
    {
        _data_load = LOADADDR(.data);
        _data_start = .;
        *(.data*)
        _data_end = .;
    } > RAM AT > FLASH

    .bss (NOLOAD) :
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > RAM

    /* stack pointer = top of RAM */
    _stack_end = ORIGIN(RAM) + LENGTH(RAM);
	/DISCARD/ :
    {
        *(.ARM.exidx*)
        *(.ARM.attributes)
    }
}
