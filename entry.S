#
#
.macro reg_save base
	sw ra, 0(\base)
	sw sp, 4(\base)
	sw gp, 8(\base)
	sw tp, 12(\base)
	sw t0, 16(\base)
	sw t1, 20(\base)
	sw t2, 24(\base)
	sw s0, 28(\base)
	sw s1, 32(\base)
	sw a0, 36(\base)
	sw a1, 40(\base)
	sw a2, 44(\base)
	sw a3, 48(\base)
	sw a4, 52(\base)
	sw a5, 56(\base)
	sw a6, 60(\base)
	sw a7, 64(\base)
	sw s2, 68(\base)
	sw s3, 72(\base)
	sw s4, 76(\base)
	sw s5, 80(\base)
	sw s6, 84(\base)
	sw s7, 88(\base)
	sw s8, 92(\base)
	sw s9, 96(\base)
	sw s10, 100(\base)
	sw s11, 104(\base)
	sw t3, 108(\base)
	sw t4, 112(\base)
	sw t5, 116(\base)
	sw t6, 120(\base)
.endm

.macro reg_restore base
	lw ra, 0(\base)
	lw sp, 4(\base)
	lw gp, 8(\base)
	lw tp, 12(\base)
	lw t0, 16(\base)
	lw t1, 20(\base)
	lw t2, 24(\base)
	lw s0, 28(\base)
	lw s1, 32(\base)
	lw a0, 36(\base)
	lw a1, 40(\base)
	lw a2, 44(\base)
	lw a3, 48(\base)
	lw a4, 52(\base)
	lw a5, 56(\base)
	lw a6, 60(\base)
	lw a7, 64(\base)
	lw s2, 68(\base)
	lw s3, 72(\base)
	lw s4, 76(\base)
	lw s5, 80(\base)
	lw s6, 84(\base)
	lw s7, 88(\base)
	lw s8, 92(\base)
	lw s9, 96(\base)
	lw s10, 100(\base)
	lw s11, 104(\base)
	lw t3, 108(\base)
	lw t4, 112(\base)
	lw t5, 116(\base)
	lw t6, 120(\base)
.endm


.text
# void switch_to(context_t *next);
# @next: next store in a0 register
# TODO t6 should be store for safe?
.global switch_to
.align 4
switch_to:
	csrrw	t6, mscratch, t6	# swap t6 and mscratch
	beqz	t6, 1f				# prev may be NULL
	reg_save t6					# save prev's context
	
1:
	csrw mscratch, a0
	
	# restore all GP registers
	mv	t6, a0
	reg_restore t6
	
	# do context switching
	ret



.global trap_vector
# trap vector base address must be 4-byte aligned.
.align 4
trap_vector:

	# 保存当前task的上下文
	csrrw t6, mscratch, t6
	reg_save t6
	csrw  mscratch, t6
	
	# 调用中断处理函数(这里把epc获取是为了timer中断进程调度准备)
	csrr a0, mepc
	csrr a1, mcause
	call trap_handler

	# a0是trap_handler的返回值
	# 这里的mepc很可能被改了(schedule的场景)
	csrw mepc, a0

	# 
	csrr t6, mscratch
	reg_restore t6
	
	# 返回trap之前的地址
	mret

.end
