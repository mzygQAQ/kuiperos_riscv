#ifndef __KUIPEROS_RISCV_H__
#define __KUIPEROS_RISCV_H__

#include "types.h"

static inline register_t r_mhartid()
{
	register_t x;
	asm volatile("csrr %0, mhartid" : "=r" (x) );
	return x;
}

static inline void w_mscratch(register_t x)
{
	asm volatile("csrw mscratch, %0" : : "r" (x));
}

static inline void w_mtvec(register_t x)
{
	// lower2bit mode, upper30bit (4aligned)address
	asm volatile("csrw mtvec, %0" : : "r" (x));
}




static inline register_t r_mstatus()
{
	register_t x;
	// fixme
	return x;
}

static inline void w_mstatus(register_t x)
{
	// fixme
}

#endif
