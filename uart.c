#include "defs.h"
#include "types.h"
#include "platform.h"

/**
 * uart的控制寄存器被内存映射在了UART0所在的地址
 */
#define UART_REG(reg) ((volatile uint8_t *)(UART0 + reg))

#define RHR 0	// 
#define THR 0	// 
#define DLL 0	// 
#define IER 1	// 中断禁用寄存器(写模式)
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

/**
 * LSR BIT 0:
 *	0:
 *	1:
 *
 * LSR BIT 5:
 *	0:
 *	1:
 */
#define LSR_RX_READY (1 << 0)
#define LSR_TX_IDLE  (1 << 5)

void uart_init(void)
{
	// 禁用中断
	uart_write_reg(IER, 0x00);

	uint8_t lcr = uart_read_reg(LCR);
	uart_write_reg(LCR, lcr | (1 << 7));
	uart_write_reg(DLL, 0x3);
	uart_write_reg(DLM, 0x00);

	lcr = 0;
	uart_write_reg(LCR, lcr | (3 << 0));
}

static void uart_putc(char ch)
{
	while((uart_read_reg(LSR) & LSR_TX_IDLE) == 0);
	uart_write_reg(THR, ch);
}

void uart_puts(char *s)
{
	while(*s) 
		uart_putc(*s++);
}
