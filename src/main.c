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

    /*
    init();
    while (tim.c != 'q') {
        update();
        tim.c = getch();
    }
    end();
        */
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

void test_line() {
    Line line = new_line();

    char s[5] = "hello";
    for (int i = 0; i < 5; i++)
        add_char(&line, 0, s[i]);

    add_char(&line, line.size+1, 'l');
    add_char(&line, -1, 'l');

    STR(line.buf, line.size);

    remove_char(&line, -1);
    remove_char(&line, line.size-1);
    remove_char(&line, line.size);

    STR(line.buf, line.size);

}

void test_page() {
    tim.page = new_page();
    
    Line tl = new_line();
    add_char(&tl, 0, 'o');
    add_char(&tl, 0, 'l');
    add_char(&tl, 0, 'l');
    add_char(&tl, 0, 'e');
    add_char(&tl, 0, 'h');

    Line tr = new_line();
    add_char(&tr, 0, 'l');
    add_char(&tr, 0, 'o');
    add_char(&tr, 0, 'l');
    add_char(&tr, 0, 'o');
    add_char(&tr, 0, 'h');
    add_char(&tr, 0, 'e');

    add_line(&tim.page, tl, 0);
    add_line(&tim.page, tr, 0);
    remove_line(&tim.page, 2);
    remove_line(&tim.page, 0);
    remove_line(&tim.page, 0);

    for (int i = 0; i < tim.page.size; i++) {
        for (int j = 0; j < tim.page.lines[i].size; j++) {
            putchar(tim.page.lines[i].buf[j]);
        }
        putchar('\n');
    }
}
