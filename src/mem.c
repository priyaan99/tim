#include "mem.h"
#include "common.h"

Line new_line() {
	Line l;
	l.size = 0;
	l.cap = 12;
	l.buf = (char*) malloc(sizeof(char)*l.cap);

	LOGx("\n:: newline of size [%d] of cap [%d]\n", l.size, l.cap);

	return l;
}

void add_char(Line* line, int at, char c) {
	LOG("\nADDCHAR() for char [%c] at [%d]\n", c, at);
	if (at < 0 || at > line->size) {
		LOGx("add_char() :: index out of bound at [%d]\n", at);
		return;
	}

	if (line->size+1 >= line->cap) {
		line->cap = line->cap * 2;
		line->buf = (char*) realloc(line->buf, sizeof(char)*line->cap);
		LOGx("addchar() :: line realloc new size [%d]\n", line->cap);
	}

	memmove(line->buf+at+1, line->buf+at, line->size-at);
	line->buf[at] = c;
	line->size++;
}

void remove_char(Line* line, int at) {
	LOG("\nREMOVE_CHAR() at [%d]\n", at);
	if (at < 0 || at >= line->size) {
		LOGx("remove_char() :: index out of bound at [%d]\n", at);
		return;
	}

	if (line->size+1 >= line->cap) {
		line->cap = line->cap * 2;
		line->buf = (char*) realloc(line->buf, sizeof(char)*line->cap);
		LOGx("remove_char() :: line realloc new size [%d]\n", line->cap);
	}

	memmove(line->buf+at, line->buf+at+1, line->size-at);
	line->size--;
}

Page new_page() {
	Page t;
	t.size = 0;
	t.cap = 2;
	t.lines = (Line*) malloc(sizeof(Line)*t.cap);

	LOG("NEW_PAGE\n");

	return t;
}

void add_line(Page* page, Line line, int at) {
	LOG("\nADD_LINE at [%d]\n", at);
	STRx(line.buf, line.size);
	LOGx("line size [%d]\t\n", line.size);
	if (at < 0 || at > page->size) {
		LOGx("add_line :: index out of bound at [%d]\n", at);
		return;
	}

	if (page->size >= page->cap) {
		page->cap = page->cap * 2;
		page->lines = (Line*) realloc(page->lines, sizeof(Line)*page->cap);
		LOGx("add_line :: realloc page with size [%d]\n", page->cap);
	}

	for (int i = page->size; i > at; i--) {
		page->lines[i] = page->lines[i-1];
		LOGx("copy i-[%d] to i-[%d]\n", i-1, i);
	}

	page->lines[at] = line;
	page->size += 1;
}

void remove_line(Page* page, int at) {
	LOG("\nREMOVE_LINE\n");
	if (at < 0 || at >= page->size) {
		LOGx("remove_line :: index out of bound at [%d]\n", at);
		return;
	}

	page->lines[at].buf[page->lines[at].size-1] = '\0';
	LOGx("freeing line at [%d] is - [%s]\n", at, page->lines[at].buf);
	free(page->lines[at].buf);

	for (int i = at; i < page->size-1; i++) {
		page->lines[i] = page->lines[i+1];
	}

	//memmove(page->lines+at, page->lines+at+1, page->size-at);
	page->size--;
}

void free_line_buf(char* buf) {
	free(buf);
	LOGx("-> freed line buf\n");
}
void free_page_line(Line* line) {
	free_line_buf(line->buf);
	//free(line);
	LOGx("\tfreed page line\n");
}

void free_page(Page* page) {
	for (int i = 0; i < page->size; i++) {
		free_page_line(page->lines+i);
	}
}
