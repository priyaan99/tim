#include <ncurses.h>
#include <stdio.h>

#include "common.h"
#include "mem.h"


void update();
void init();
void end();

Tim tim;

int main(int argc, char** argv) {
    LOG("%s %d\n", argv[0], argc);

    init();
    while (tim.c != 'q') {
        update();
        tim.c = getch();
    }
    end();
}

void update() {
    clear();
    addch(tim.c);
    refresh();
}

void init() {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
}

void end() {
    endwin();
}
