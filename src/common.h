#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
	#define LOG(...) fprintf(stdout, __VA_ARGS__)
	#define STR(pointer, size) \
		for (int i = 0; i < size; i++) putchar(pointer[i]); \
		putchar('\n')
#else 
	#define LOG(...) 
	#define STR(...)
#endif

#endif
