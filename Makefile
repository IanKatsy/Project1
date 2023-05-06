CC=gcc

SRC=$(wildcard src/*.c)

.PHONY: all
all: $(OBJS) Minesweeper

.run: Minesweeper
	./Minesweeper
	rm Minesweeper

.clean:
	rm Minesweeper

Minesweeper:
	$(CC) Minesweeper.c $(SRC) -o Minesweeper