#ifndef __KUIPEROS_TYPES_H__
#define __KUIPEROS_TYPES_H__

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef uint64_t size_t;
typedef uint32_t register_t;

typedef int BOOL;

#define TRUE  1
#define FALSE 0
#define NULL ((void*)0)

#define ACCESS_ONCE(x) (*(__volatile__ typeof(x))(&(x)))

#define offsetof(type, member) ((size_t) & (((type *)0)->member))

#define container_of(ptr, type, member)                                        \
  ({                                                                           \
    const typeof(((type *)0)->member) *__mptr = (ptr);                         \
    (type *)((char *)__mptr - offsetof(type, member));                         \
  })

#if defined(__GNUC__) && __GNUC__ >=4
#define LIKELY(x)    (__builtin_expect((x), 1))
#define UNLIKELY(x)  (__builtin_expect((x), 0))
#else
#define LIKELY(x)	 (x)
#define UNLIKELY(x)	 (x)
#endif



#endif
