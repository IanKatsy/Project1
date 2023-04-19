CC=gcc

SRC=$(wildcard src/*.c)
OBJS=$(patsubst %.c,%.o,$(SRC))

.PHONY: all
all: $(OBJS) Minesweeper

.clean: all
	rm $(OBJS)
	rm Minesweeper

Minesweeper: $(OBJS)
	$(CC) $(OBJS) Minesweeper.c -o Minesweeper

object: $(SRC)
	$(CC) -c $(SRC)
