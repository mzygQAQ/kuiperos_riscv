#ifndef __KUIPEROS_LIST_H__
#define __KUIPEROS_LIST_H__

#include "types.h"

struct list_head {
  struct list_head *next;
  struct list_head *prev;
};

#define LIST_HEAD_INIT(name)                                                   \
  { &(name), &(name) }

#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr)                                                    \
  do {                                                                         \
    (ptr)->next = (ptr);                                                       \
    (ptr)->prev = (ptr);                                                       \
  } while (0)

static inline void __list_add(struct list_head *new_ele,
                                  struct list_head *prev,
                                  struct list_head *next) {
  next->prev = new_ele;
  new_ele->next = next;
  new_ele->prev = prev;
  prev->next = new_ele;
}

static inline void list_add(struct list_head *new_ele,
                                struct list_head *head) {
  __list_add(new_ele, head, head->next);
}

static inline void list_add_tail(struct list_head *new_ele,
                                     struct list_head *head) {
  __list_add(new_ele, head->prev, head);
}

static inline BOOL list_is_empty(struct list_head *head) {
  return head == head->next;
}

static inline void __list_del(struct list_head *prev,
                                  struct list_head *next) {
  next->prev = prev;
  prev->next = next;
}

static inline void list_del(struct list_head *entry) {
  __list_del(entry->prev, entry->next);
}

static inline void list_del_init(struct list_head *entry) {
  __list_del(entry->prev, entry->next);
  INIT_LIST_HEAD(entry);
}

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_foreach(pos, head) \
  for (pos = (head)->next; pos != (head); pos = pos->next)



#endif
