#include "uart.h"
#include "types.h"
#include "platform.h"

/**
 * uart的控制寄存器被内存映射在了UART0所在的地址
 */
#define UART_REG(reg) ((volatile uint8_t *)(UART0 + reg))

#define RHR 0
#define THR 0
#define DLL 0
#define IER 1
#define DLM 1
#define FCR 2
#define ISR 2
#define LCR 3
#define MCR 4
#define LSR 5
#define MSR 6
#define SPR 7

#define uart_read_reg(reg)      (*(UART_REG(reg)))
#define uart_write_reg(reg,v)   (*(UART_REG(reg)) = (v))

static uint8_t _bit_count(uint8_t n)
{
	uint8_t ret = 0;
	for(int i = 0; i < 8; i++)
	{
		if((n >> i) & 0x1) ret++;
	}	
	return ret;
}

void uart_init(void)
{

}

static void uart_putc(char c)
{
	
}

void uart_puts(char *s)
{
	while(*s) 
		uart_putc(*s++);
}
