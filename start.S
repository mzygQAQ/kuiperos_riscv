#include "platform.h"

.equ STACK_SIZE, MAXNUM_CPU * 1024

.section .text
.global _start

_start:
	
	# 判断当前CPU是否是0号CPU,只允许第一个CPU运行内核
	csrr t0, mhartid
	mv   tp, t0
	bnez t0, park	

	# 为每个CPU核心初始化栈
	slli t0, t0, 10
	la   sp, stacks + STACK_SIZE

	add  sp, sp, t0

	j start_kernel

park:
	wfi
	j park

stacks:
	.skip STACK_SIZE

.end
