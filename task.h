#ifndef __KUIPEROS_TASK_H__
#define __KUIPEROS_TASK_H__

#include "types.h"
#include "spinlock.h"

typedef struct context {
	/* x0 always be 0 */
	register_t ra;	// x1
	register_t sp;	// x2
	register_t gp;	// x3
	register_t tp;	// x4
	register_t t0;	// x5
	register_t t1;	// x6
	register_t t2;	// x7
	register_t s0;	// x8
	register_t s1;	// x9
	register_t a0;	// x10
	register_t a1;	// x11
	register_t a2;	// x12
	register_t a3;	// x13
	register_t a4;	// x14
	register_t a5;	// x15
	register_t a6;	// x16
	register_t a7;	// x17
	register_t s2;	// x18
	register_t s3;	// x19
	register_t s4;	// x20
	register_t s5;	// x21
	register_t s6;	// x22
	register_t s7;	// x23
	register_t s8;	// x24
	register_t s9;	// x25
	register_t s10;	// x26
	register_t s11;	// x27
	register_t t3;	// x28
	register_t t4;	// x29
	register_t t5;	// x30
	register_t t6;	// x31
} context_t;

#define TASK_STACK_SZ 4096
struct task_struct {
	// int32_t pid;
	// spinlock_t lock;
	context_t ctx;
	uint8_t stack[TASK_STACK_SZ];
};

void sched_init();
void schedule();

int task_create(void (*task_routine)(void));
void task_yield();

#endif
