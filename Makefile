CC=gcc

SRC= src/cheat.c src/levelHandlers.c src/mark.c src/parseStr.c src/printGrid.c src/readString.c src/util.c

.PHONY: all
all: $(OBJS) Minesweeper

.run: Minesweeper
	./Minesweeper
	rm Minesweeper

.clean:
	rm Minesweeper

Minesweeper:
	$(CC) Minesweeper.c $(SRC) -o Minesweeper