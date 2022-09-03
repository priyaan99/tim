#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
} Size;

typedef struct {
	char* buf;
	int size;
	size_t cap;
} Line;

typedef struct {
	Line* lines;
	int size;
	int cap;
} Page;

typedef struct {
	int c;
	Page page;
	Size curpos;
	Size pagepos;
	Size wsize;
	char* filename;
} Tim;

Line new_line();
void add_char(Line* line, int at, char c);
void remove_char(Line* line, int at);

Page new_page();
void add_line(Page* page, Line line, int at);
void remove_line(Page* page, int at);

void free_line_buf(char* buf);
void free_page_line(Line* line);
void free_page(Page* page);

#endif
