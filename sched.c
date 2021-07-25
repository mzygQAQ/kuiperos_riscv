#include "task.h"
#include "riscv.h"
#include "defs.h"
#include "list.h"
#include "spinlock.h"

// entry.S
extern void switch_to(context_t *next);

// first user/application in kuiperos/unix
extern void task0(void);
extern void task1(void);
extern void task2(void);

#define NMAX_TASK  32
struct task_struct _tasks[NMAX_TASK];
uint32_t _task_offset = 0;
uint32_t _task_exec	  = 0;

void sched_init()
{

	// clear mscratch
	w_mscratch(0);
	
	// create process 0
	task_create(task0);
	task_create(task1);
	task_create(task2);
}

void schedule()
{
	uint32_t next_task_idx = (_task_exec++) % _task_offset;
	context_t *next = &(_tasks[next_task_idx].ctx);
	switch_to(next);
}

int task_create(void (*task_routine)(void))
{
	_tasks[_task_offset].ctx.ra = (register_t)task_routine;
	_tasks[_task_offset].ctx.sp	= (register_t)(_tasks[_task_offset].stack + TASK_STACK_SZ - 1);
	_task_offset++;
	return _task_offset - 1;
}

void task_yield()
{
	schedule();
}

void task0(void)
{
	printf("Task0 Created.\n");
	while(1){
		printf("Task0 Running.\n");
		delay(10000000);
		task_yield();
	}
}

void task1(void)
{
	printf("Task1 Created.\n");
	while(1){
		printf("Task1 Running.\n");
		delay(10000000);
		task_yield();
	}
}

void task2(void)
{
	printf("Task2 Created.\n");
	while(1){
		printf("Task2 Running.\n");
		delay(10000000);

		// trigger exception
		uint32_t *ptr = NULL;
		*ptr =1;

		
		printf("Task2 returned from trap excetion!!!!!!!!\n");

		task_yield();
	}
}

