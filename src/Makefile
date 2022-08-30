CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -DDEBUG 
LIB=-lncurses
OBJS=main.o mem.o
NAME=tim

all: tim

run: tim
	./$(NAME)

tim: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

main.o: main.c mem.c mem.h common.h
	$(CC) -c $< $(CFLAGS) 

mem.o: mem.c mem.h common.h
	$(CC) -c $< $(CFLAGS) 

clean:
	rm $(OBJS) $(NAME)
