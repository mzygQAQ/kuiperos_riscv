#include "uart.h"
#include "types.h"

void start_kernel(void)
{
	uart_init();
	uart_puts("KuiperOs is booting...\n");

    while(1){};
}
