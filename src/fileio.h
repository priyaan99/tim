#ifndef FILEIO_H
#define FILEIO_H

#include "mem.h"

void read_file(Page* page, const char* filename);
void write_file(Page* page, const char* filename);

#endif
