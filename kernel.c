#include "defs.h"
#include "riscv.h"
#include "task.h"

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
	printf("ARCH: riscv32_ima");

	mem_page_init();

	// 初始化进程,会创建0号进程.
	sched_init();

	// trap初始化必须在0号进程后.
	trap_init();

	// 调度进程.
	schedule();

	panic("unreach code");
}
