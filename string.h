#ifndef __KUIPEROS_STRING_H_
#define __KUIPEROS_STRING_H_

#include "types.h"

void* memcpy(void *dst, const void* src, size_t num);
void* memmov(void *dst, const void* src, size_t num);

char* strcpy(char *dst, const char* src);
char* strncpy(char *dst, const char* src, size_t num);

char* strcat(char *dst, const char* src);
char* strncat(char *dst, const char* src, size_t num);


void* memset(void* ptr, int value, size_t num);
size_t strlen(const char *str);

#endif
