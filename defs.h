#ifndef __KUIPEROS_DEFS_H__
#define __KUIPEROS_DEFS_H__

#include "types.h"

// uart.c NS16550a
void uart_init(void);
void uart_putc(char ch);
void uart_puts(char *s);

// kernel.c
void delay(uint64_t n);

// mem.c
void  mem_page_init();
void* mem_page_alloc(int npages);
void  mem_page_free(void *p);

// 

// macros

#if defined(__GNUC__) && __GNUC__ >=4
#define LIKELY(x)	(__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define LIKELY(x)	(x)
#define UNLIKELY(x)	(x)
#endif

#endif
