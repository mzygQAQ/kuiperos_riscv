#include "defs.h"
#include "spinlock.h"

#define BUFSZ 256

typedef struct console_s
{
	spinlock_t lock;
	char       buf[BUFSZ];
	uint64_t   read_index;
	uint64_t   write_index;
	uint64_t   edit_index;
} console_t;

// global unique cosnole instance
console_t cons;

void console_init()
{
	spinlock_init(&cons.lock);
	uart_init();

	// TODO
}

