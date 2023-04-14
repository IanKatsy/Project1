CC=gcc

SRC=$(wildcard src/*.c)
OBJS=$(patsubst %.c,%.o,$(SRC))

.PHONY: all
all: $(OBJS) Minesweeper

.clean: all
	rm $(OBJS)
	rm Minesweeper

Minesweeper: $(OBJS)
	$(CC) -o Minesweeper $(OBJS)

object: $(SRC)
	$(CC) -c $(SRC)
