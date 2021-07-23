#include "string.h"

void* memcpy(void *dst, const void* src, size_t num)
{
	return NULL;
}
void* memmov(void *dst, const void* src, size_t num)
{
	return NULL;
}

char* strcpy(char *dst, const char* src)
{
	return NULL;
}

char* strncpy(char *dst, const char* src, size_t num)
{
	return NULL;
}

char* strcat(char *dst, const char* src)
{
	return NULL;
}

char* strncat(char *dst, const char* src, size_t num)
{
	return NULL;
}


void* memset(void* ptr, int value, size_t num)
{
	return NULL;
}

size_t strlen(const char *str)
{
	size_t len = 0;
	while(*str++) 
		len++;
	return len;
}



