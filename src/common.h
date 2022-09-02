#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LI long int
#define I int

#ifdef DEBUG
	#define LOG(...) fprintf(stdout, __VA_ARGS__)
	#define STR(pointer, size) \
		for (int i = 0; i < size; i++) putchar(pointer[i]); \
		putchar('\n')
#else 
	#define LOG(...) 
	#define STR(...)
#endif

//#define DEBUG_EXTRA

#ifdef DEBUG_EXTRA
	#define LOGx(...) fprintf(stdout, __VA_ARGS__)
	#define STRx(pointer, size) \
		for (int i = 0; i < size; i++) putchar(pointer[i]); \
		putchar('\n')
#else
	#define STRx(...)
	#define LOGx(...) 
#endif

#endif
