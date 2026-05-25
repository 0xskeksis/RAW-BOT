#include "raw_bot.h"

#define DBG_UART_BAUDRATE	115200
#define SYS_FREQ			16000000
#define APB1_CLK			SYS_FREQ
#define CR1_UE				(1U << 13)
#define CR1_TE				(1U << 3)
#define SR_TXE				(1u << 7)

static void uart_write(volatile t_uart *uart, int c){
	while (!(uart->sr & SR_TXE)){}

	uart->dr = (c & 0xFF);
}

int
_io_putchar(volatile t_uart *uart, int c){
	uart_write(uart, c);
	return c;
}

void
_io_putstr(volatile t_uart *uart, char *str){
	while (*str)
		_io_putchar(uart, *str++);
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate){
	return ((periph_clk + (baudrate/2U))/baudrate);
}

static void uart_set_baudrate(t_uart *uart, uint32_t periph_clk, uint32_t baudrate){
	uart->brr = compute_uart_bd(periph_clk, baudrate);
}

void
uart_init(t_gpio *gpioa, t_rcc *rcc, volatile t_uart *uart){
	rcc_enable(GPIOAEN, &rcc->ahb1enr);
	gpio_init(gpioa, 2, PIN_STATE_ALTERNATE);
	
	gpioa->afrl |= (1U << 8);
	gpioa->afrl |= (1U << 9);
	gpioa->afrl |= (1U << 10);
	gpioa->afrl &= ~(1U << 11);

	rcc_enable(UART2EN, &rcc->apb1enr);
	uart_set_baudrate(uart, APB1_CLK, DBG_UART_BAUDRATE);
	uart->cr1 = CR1_TE;
	uart->cr1 |= CR1_UE;
}


