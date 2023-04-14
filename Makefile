C_COMPILER=gcc
C_FLAG=-Wall -std=c90

OBJS=readString.o clearTerm.o printGrid.o mark.o parseStr.o

.PHONY: all
all: $(OBJS) Minesweeper

.clean: all
	rm readString.o
	rm Minesweeper

Minesweeper: $(OBJS)
	printf Building main.o!
	$(C_COMPILER) main.c -o Minesweeper $(OBJS) $(C_FLAG)

readString.o: readString.c
	printf Building readString.o!
	$(C_COMPILER) -c readString.c $(C_FLAG)

clearTerm.o: clearTerm.c
	printf Building clearTerm!
	$(C_COMPILER) clearTerm.c -c $(C_FLAG)

printGrid.o: printGrid.c
	printf Building printGrid!
	$(C_COMPILER) printGrid.c -c $(C_FLAG)

mark.o: mark.c
	printf Building mark.o!
	$(C_COMPILER) mark.c -c

parseStr.o: parseStr.c
	printf Building parseStr.o!
	$(C_COMPILER) parseStr.c -c