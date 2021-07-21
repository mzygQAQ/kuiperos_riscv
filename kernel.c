#include "defs.h"

void delay(uint64_t n)
{
	while(n != 0){
		asm volatile("nop");
		n--;
	}
}

void kmain(void)
{
	uart_init();
	uart_puts("KuiperOs is booting...\n");

    while(1) {
		delay(1000000);
		uart_puts("hello world fron kuiperos\n");
	};
}
