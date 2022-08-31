#include "mem.h"
#include "common.h"

Line new_line() {
	Line l;
	l.size = 0;
	l.cap = 12;
	l.buf = (char*) malloc(sizeof(char)*l.cap);

	LOG("\n:: newline of size [%d] of cap [%d]\n", l.size, l.cap);

	return l;
}

void add_char(Line* line, int at, char c) {
	LOG("\nADDCHAR() for char [%c] at [%d]\n", c, at);
	if (at < 0 || at > line->size) {
		LOG("add_char() :: index out of bound at [%d]\n", at);
		return;
	}

	if (line->size+1 >= line->cap) {
		line->cap = line->cap * 2;
		line->buf = (char*) realloc(line->buf, sizeof(char)*line->cap);
		LOG("addchar() :: line realloc new size [%d]\n", line->cap);
	}

	memmove(line->buf+at+1, line->buf+at, line->size-at);
	line->buf[at] = c;
	line->size++;
}

void remove_char(Line* line, int at) {
	LOG("\nREMOVE_CHAR() at [%d]\n", at);
	if (at < 0 || at >= line->size) {
		LOG("remove_char() :: index out of bound at [%d]\n", at);
		return;
	}

	if (line->size+1 >= line->cap) {
		line->cap = line->cap * 2;
		line->buf = (char*) realloc(line->buf, sizeof(char)*line->cap);
		LOG("remove_char() :: line realloc new size [%d]\n", line->cap);
	}

	memmove(line->buf+at, line->buf+at+1, line->size-at);
	line->size--;
}

Page new_page() {
	Page t;
	t.size = 0;
	t.cap = 12;
	t.lines = (Line*) malloc(sizeof(Line)*t.cap);

	LOG("NEW_PAGE");

	return t;
}

void add_line(Page* page, Line line, int at) {
	LOG("\nADD_LINE at [%d]\n", at);
	STR(line.buf, line.size);
	LOG("line size [%d]\t\n", line.size);
	if (at < 0 || at > page->size) {
		LOG("add_line :: index out of bound at [%d]\n", at);
		return;
	}

	if (page->size+1 >= page->cap) {
		page->cap = page->cap * 2;
		page->lines = (Line*) realloc(page->lines, sizeof(Line)*page->cap);
		LOG("add_line :: realloc page with size [%d]\n", at);
	}

	for (int i = page->size; i > at; i--) {
		page->lines[i] = page->lines[i-1];
		LOG("copy i-[%d] to i-[%d]\n", i-1, i);
	}

	page->lines[at] = line;
	page->size += 1;

	/*
	memmove(page->lines+at+1, page->lines+at, page->size-at);
	page->lines[at] = line;
	page->size++;
	*/
}

void remove_line(Page* page, int at) {
	LOG("\nREMOVE_LINE\n");
	if (at < 0 || at >= page->size) {
		LOG("remove_line :: index out of bound at [%d]\n", at);
		return;
	}

	page->lines[at].buf[page->lines[at].size-1] = '\0';
	LOG("freeing line at [%d] is - [%s]\n", at, page->lines[at].buf);
	free(page->lines[at].buf);

	for (int i = at; i < page->size-1; i++) {
		page->lines[i] = page->lines[i+1];
	}

	//memmove(page->lines+at, page->lines+at+1, page->size-at);
	page->size--;
}









