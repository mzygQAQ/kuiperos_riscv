#include "defs.h"
#include <stdarg.h>

static char out_buf[1024];

static int _vsnprintf(char *out, size_t n, const char*s, va_list vl)
{
	BOOL format  = FALSE;
	BOOL longarg = FALSE;
	size_t pos   = 0;
	
	for(;*s; s++) {
		if(format){
			switch(*s){
			case 'l':
				break;
			case 'p':
				break;
			case 'x':
				break;
			case 'd':
				break;
			case 's': {
				const char* s2= va_arg(vl, const char*);
				while(*s2){
					if(out && pos < n) {
						out[pos] = *s2;
					}
					pos++;
					s2++;
				}
				longarg = FALSE;
				format  = FALSE;
				break;
			}
			case 'c':
				if(out && pos < n){
					// int or char ?
					out[pos] = (char)va_arg(vl, int);
					pos++;
					longarg = FALSE;
					format  = FALSE;
					break;
				}
			default:
				break;	
			}// switch
		} else if(*s == '%') {
			format = TRUE;
		} else {
			if(out && pos < n) {
				out[pos]= *s;
			}
			pos++;
		}
	}// for
	if(out && pos < n) {
		out[pos] = 0;
	} else if(out && n) {
		out[n-1] = 0;
	}
	return pos;
}

static int _vprintf(const char*s , va_list vl)
{
	int res = _vsnprintf(NULL, -1, s, vl);
	if(res + 1 >= sizeof(out_buf)) {
		uart_puts("error: output string size overflow\n");
		while(1){}
	}
	_vsnprintf(out_buf, res+1, s, vl);
	uart_puts(out_buf);
	return res;
}

int printf(const char *fmt, ...)
{
	int res = 0;
	va_list vl;
	va_start(vl, fmt);
	res = _vprintf(fmt,vl);
    va_end(vl);	
	return res;
}


void panic(char *s)
{
	printf("panic:");
	printf(s);
	printf("\n");
	while(1);
}
