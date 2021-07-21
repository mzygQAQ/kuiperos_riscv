#ifndef __KUIPEROS_MUTEX_H__
#define __KUIPEROS_MUTEX_H__

#include "types.h"
#include "spinlock.h"

typedef struct mutex_s {
	uint8_t locked;
	spinlock_t splock;

	char *name;
	int pid;
} mutex_t;

void mutex_init(mutex_t *mtx);
void mutex_lock(mutex_t *mtx);
void mutex_unlock(mutex_t *mtx);

#endif
