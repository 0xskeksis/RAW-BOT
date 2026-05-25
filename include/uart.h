#ifndef _UART_H
# define _UART_H

// In the reference manual, the UART is defined as USART (synchronous/asynchronous).
// The name reflect the dual functionality of the peripheral

// RCC
#define UART2EN (1U << 17)

// PD5
#define UART2_PIN 5

#include "memory_map.h"

void
uart_init(t_gpio *gpiod, t_rcc *rcc, volatile t_uart *uart);

int
_io_putchar(volatile t_uart *uart, int c);

void
_io_putstr(volatile t_uart *uart, char *str);

#endif
