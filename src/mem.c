#include "mem.h"
#include "common.h"

Line new_line() {
	Line l;
	l.size = 0;
	l.cap = 12;
	l.buf = (char*) malloc(sizeof(char)*l.cap);

	LOG(":: newline of size [%d] of cap [%d]\n", l.size, l.cap);

	return l;
}

void add_char(Line* line, int at, char c) {
	LOG("ADDCHAR() for char [%c] at [%d]\n", c, at);
	if (at < 0 || at > line->size) {
		LOG("add_char() :: index out of bound at [%d]", at);
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
	LOG("REMOVE_CHAR() at [%d]\n", at);
	if (at < 0 || at >= line->size) {
		LOG("remove_char() :: index out of bound at [%d]", at);
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












