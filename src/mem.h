#ifndef MEM_H
#define MEM_H

typedef struct {
	int c;
} Tim;

typedef struct {
	char* buf;
	int size;
	int cap;
} Line;

typedef struct {
	Line* line;
	int size;
	int cap;
} Page;

Line new_line();
void add_char(Line* line, int at, char c);
void remove_char(Line* line, int at);

#endif
