#ifndef __KUIPEROS_DEFS_H__
#define __KUIPEROS_DEFS_H__

#include "types.h"

// uart.c NS16550a
void uart_init(void);
void uart_putc(char ch);
void uart_puts(char *s);

// kernel.c
void delay(uint64_t n);


#endif
