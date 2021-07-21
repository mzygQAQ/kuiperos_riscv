#ifndef __KUIPEROS_SPINLOCK_H__
#define __KUIPEROS_SPINLOCK_H__

#include "types.h"

struct cpu;

typedef struct spinlock_s {
	uint8_t	locked;
	char*	name;
	struct cpu 	*cpu;
} spinlock_t;

void spinlock_init(spinlock_t *lock);
void spinlock_lock(spinlock_t *lock);
void spinlock_unlock(spinlock_t *lock);

#endif
