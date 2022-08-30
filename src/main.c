#include <ncurses.h>
#include <stdio.h>

void update();
void init();
void end();

int c = -1;

int main(int argc, char** argv) {
    init();
    while (c != 'q') {
        update();
        c = getch();
    }
    end();
}

void update() {
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
