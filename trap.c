#include "riscv.h"
#include "defs.h"

#define XLEN 32

// mtvec: Machine Trap-Vector Base-Address
// BaseAddress must be 4byte aligned.

/**
 * Direct mode(00): All exceptions set pc to BASE
 */
#define MTVEC_MODE_DIRECT	0

/**
 * Vectored mode(01): Asynchronous interrupts set pc 
 * to BASE+4xcause
 */
#define MTVEC_MODE_VECTORED 1


// mepc: Machine Exception Program Counter
// when trap occured, mepc = rawpc's next inst address
// likes ra in function calls.
// NOTE:
// For exception, mepc pointers to address of exception inst
// For interrupt, mepc pointers to address of next inst.


// mcause: Machine Cause
// [MXLEN-1][MXLEN-2,0]
// exceptionCode: table3.6
#if XLEN == 32
#define TRAP_TYPE_INTERRUPT_MASK 0x80000000
#else
#define TRAP_TYPE_INTERRUPT_MASK 0x8000000000000000
#endif

#define IS_INTERRUPT(x)	(x & TRAP_TYPE_INTERRUPT_MASK)
#define IS_EXCEPTION(x)	(!(IS_INTERRUPT(x)))


// mstatus: Machine Status
// read riscv-isa.pdf to learn more.





#define TRAP_INT_CAUSECODE_SOFAWARE	3	
#define TRAP_INT_CAUSECODE_TIMER    7
#define TRAP_INT_CAUSECODE_EXTERNAL 11


// defined in entry.S
extern void trap_vector(void);

void trap_init()
{
	register_t trap_vec_addr = (register_t)trap_vector;
	// TODO(guoxiang): assert 4byte-aligned
	w_mtvec(trap_vec_addr | MTVEC_MODE_DIRECT);
}

register_t trap_handler(register_t epc, register_t cause)
{	
	register_t return_addr = epc;
	register_t cause_code  = cause & 0xfff;
	if(IS_INTERRUPT(cause)){
		printf("interrupt happends.........\n");

	} else {
		printf("exception happends.........\n");
		// panic("OOPS! exception!!!!");
		return_addr += 4;
	}

	delay(10000000);
	return return_addr;
}
