#ifndef _UART_H
# define _UART_H

// In the reference manual, the UART is defined as USART (synchronous/asynchronous).
// The name reflect the dual functionality of the peripheral

// RCC
#define UART2EN (1U << 17)

// PD5
#define UART2_PIN 5

#endif
