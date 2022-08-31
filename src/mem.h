#ifndef MEM_H
#define MEM_H

typedef struct {
	char* buf;
	int size;
	int cap;
} Line;

typedef struct {
	Line* lines;
	int size;
	int cap;
} Page;

typedef struct {
	int c;
	Page page;
} Tim;

Line new_line();
void add_char(Line* line, int at, char c);
void remove_char(Line* line, int at);

Page new_page();
void add_line(Page* page, Line line, int at);
void remove_line(Page* page, int at);

#endif
