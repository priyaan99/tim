#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
	#define LOG(...) fprintf(stdout, __VA_ARGS__)
#else 
	#define LOG(...) 
#endif

#endif
