#include <ncurses.h>
#include <stdio.h>

#include "common.h"
#include "fileio.h"
#include "mem.h"

void update();
void input();
void init();
void end();

static void print_buf();

Tim tim;

int main(int argc, char** argv) {
    LOG("%s %d\n", argv[0], argc);

    init();
    while (tim.c != 'q') {
        update();
		input();
    }
    end();
	LOG("%d %d - wsize\n", tim.wsize.row, tim.wsize.col);
	LOG("%d %d - curpos\n", tim.curpos.row, tim.curpos.row);
	LOG("%d %d - pagepos\n", tim.pagepos.row, tim.pagepos.row);
}

static void normal() {
	if (tim.c == 'k' && tim.pagepos.row + tim.curpos.row > 0) {
		if (tim.curpos.row == 0) tim.pagepos.row--;
		else tim.curpos.row--;
		tim.curpos.col = 0;
	}
	if (tim.c == 'j' && tim.pagepos.row + tim.curpos.row < tim.page.size-1) {
		// if curpos is end line in widow
		if (tim.curpos.row == tim.wsize.row-2) tim.pagepos.row++;
		else tim.curpos.row++;

		tim.curpos.col = 0;
	}
}

static void insert() {
}

static void cmd() {
}

void input() {
	tim.c = getch();

	// on window size changed
	if (tim.c == 410) {
		// reset curpos so not out of screen
		if (tim.curpos.row > tim.wsize.row-1) tim.curpos.row = tim.wsize.row-1;
		return;
	};

	if (tim.mode == NORMAL) 
	{
		normal();
	}
	if (tim.mode == INSERT) 
	{
		insert();
	}
	if (tim.mode == CMD)
	{
		cmd();
	}
}

static void print_buf() {
	int row = 0;
	int prow = tim.pagepos.row;

	while (row < tim.wsize.row && prow < tim.page.size) {

		int col = 0;
		int pcol = tim.pagepos.col;

		while (col < tim.wsize.col && pcol < tim.page.lines[prow].size) {
			addch(tim.page.lines[prow].buf[pcol]);

			col++;
			pcol++;
		}

		row++;
		prow++;
	}
	move(tim.curpos.row, tim.curpos.col);
}

void update() {
	getmaxyx(stdscr, tim.wsize.row, tim.wsize.col);
    clear();

	print_buf();

    refresh();
}

void init() {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

	getmaxyx(stdscr, tim.wsize.row, tim.wsize.col);
	tim.filename = "test";

	tim.curpos.row = 5;
	tim.curpos.col = 0;

	tim.pagepos.row = 0;
	tim.pagepos.col = 0;

	tim.page = new_page();
	tim.mode = NORMAL;

	read_file(&tim.page, tim.filename);
}

void end() {
	// TODO: Free Mem
    endwin();
}
