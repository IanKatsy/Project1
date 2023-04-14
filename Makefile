C_COMPILER=gcc
# C_FLAG=-Wall -std=c90

SRC=$(wildcard src/*.c)
OBJS=$(patsubst %.c,%.o,$(SRC))

.PHONY: all
all: $(OBJS) Minesweeper

.clean: all
	rm $(OBJS)
	rm Minesweeper

Minesweeper: $(OBJS)
	printf Building main.o!
	$(C_COMPILER) main.c -o Minesweeper $(OBJS) $(C_FLAG)

readString.o: src/readString.c
	printf Building readString.o!
	$(C_COMPILER) -c readString.c $(C_FLAG)

clearTerm.o: src/clearTerm.c
	printf Building clearTerm!
	$(C_COMPILER) clearTerm.c -c $(C_FLAG)

printGrid.o: src/printGrid.c
	printf Building printGrid!
	$(C_COMPILER) printGrid.c -c $(C_FLAG)

mark.o: src/mark.c
	printf Building mark.o!
	$(C_COMPILER) mark.c -c

parseStr.o: src/parseStr.c
	printf Building parseStr.o!
	$(C_COMPILER) parseStr.c -c