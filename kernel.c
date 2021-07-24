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
	uart_puts("KuiperOs2 based on RISCV32 is booting...\n");

	uint64_t cpuid = r_mhartid();
    while(1) {
		delay(100000);
		uart_puts("hello world from kuipero2, current_cpu:");
		uart_puts("\n");
	};
}
