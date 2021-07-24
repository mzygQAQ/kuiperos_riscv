#include "defs.h"
#include "riscv.h"

void delay(uint64_t n)
{
	while(n != 0){
		asm volatile("nop");
		n--;
	}
}

static BOOL g_kernel_started_ = FALSE;

void kmain(void)
{
	uart_init();
	uart_puts("KuiperOs2 booting...\n");

	// test printf
	printf("hello\n");
	printf("msg:%s\n", "page fault");
	printf("rc:%c\n", 65);




	mem_page_init();

    while(1) {
		delay(300000);
		uart_puts("hello world from kuipero2, current_cpu:");
		uart_puts("\n");
	};
}
