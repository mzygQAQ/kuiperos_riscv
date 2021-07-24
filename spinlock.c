#include "spinlock.h"

void spinlock_init(spinlock_t *lock)
{
	lock->locked = 0;
	lock->name   = "default";
	lock->cpu    = NULL;
}


void spinlock_lock(spinlock_t *lock)
{
	lock->locked = 1;
}

void spinlock_unlock(spinlock_t *lock)
{
	lock->locked = 0;
}
void spinlock_lock_irq(spinlock_t *lock)
{

}
void spinlock_unlock_irq(spinlock_t *lock)
{

}

void spinlock_lock_irqsave(spinlock_t *lock)
{

}

void spinlock_unlock_irqrestore(spinlock_t *lock)
{

}



