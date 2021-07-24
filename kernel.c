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
		
	printf("kuiperos_riscv booting...\n");

	mem_page_init();

    while(1) {
		delay(300000);
		printf("hello world from kuipero2, current_cpu:0 \n");
	};
}
