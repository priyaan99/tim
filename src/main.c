#include <ncurses.h>
#include <stdio.h>

#include "common.h"
#include "fileio.h"
#include "mem.h"

void update();
void input();
void init();
void end();

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

void input() {
	tim.c = getch();
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
	tim.filename = "main.c";

	tim.curpos.row = 0;
	tim.curpos.col = 0;

	tim.pagepos.row = 0;
	tim.pagepos.col = 0;

	tim.page = new_page();

	read_file(&tim.page, tim.filename);
}

void end() {
	// TODO: Free Mem
    endwin();
}
