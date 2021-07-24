#include "defs.h"
#include "task.h"
#include "riscv.h"

// entry.S
extern void switch_to(context_t *next);

// task0是kuiperos用户台的0号进程,当kuiperos找不到
// 可以调度的进程时,将会调度0号进程.
extern void task0(void);

#define STACK_SIZE 4096
uint8_t task_stack[STACK_SIZE];
context_t ctx_task;

void sched_init()
{
	w_mscratch(0);
	
	// 栈从高地质往低地址
	ctx_task.sp = (register_t)(task_stack + STACK_SIZE - 1);
	ctx_task.ra = (register_t)task0;
}

void schedule()
{
	context_t *next = &ctx_task;
	switch_to(next);
}


void task0(void)
{
	printf("Task0 Created.\n");
	while(1){
		printf("Task0 Running.\n");
		delay(15000000);
	}
}

