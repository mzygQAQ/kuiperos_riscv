#ifndef __KUIPEROS_RISCV_H__
#define __KUIPEROS_RISCV_H__

#include "types.h"

static inline uint64_t r_mhartid()
{
	uint64_t x;
	asm volatile("csrr %0, mhartid" : "=r" (x) );
	return x;
}

static inline void w_mscratch(register_t x)
{
	asm volatile("csrw mscratch, %0" : : "r" (x));
}

#endif
