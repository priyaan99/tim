CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -DDEBUG 
LIB=-lncurses
OBJS=main.o
NAME=tim

all: tim

run: tim
	./$(NAME)

tim: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

main.o: main.c
	$(CC) -c $< $(CFLAGS) 

clean:
	rm $(OBJS) $(NAME)
