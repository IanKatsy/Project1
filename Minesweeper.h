#ifndef PROJECT1_MINESWEEPER_H
#define PROJECT1_MINESWEEPER_H

#define CL_OUT_WRK

#define MS_MIN_GRID_X 9
#define MS_MIN_GRID_Y 9
#define MS_MIN_MINE 10

#define MS_MAX_GRID_X 30
#define MS_MAX_GRID_Y 24
#define MS_MAX_MINE 667

#ifdef CL_OUT_WRK

#define ONE     "\e[0;34m1\e[0;0m"
#define TWO     "\e[0;32m2\e[0;0m"
#define THREE   "\e[0;31m3\e[0;0m"
#define FOUR    "\e[0;94m4\e[0;0m"
#define FIVE    "\e[0;91m5\e[0;0m"
#define SIX     "\e[0;36m6\e[0;0m"
#define SEVEN   "\e[0;35m7\e[0;0m"
#define EIGHT   "\e[0;37m8\e[0;0m"

#else

#define ONE     "1"
#define TWO     "2"
#define THREE   "3"
#define FOUR    "4"
#define FIVE    "5"
#define SIX     "6"
#define SEVEN   "7"
#define EIGHT   "8"

#endif /*CL_OUT_WRK*/

#define CHAR_NOT_TOUCHED    '#'
#define CHAR_IS_BOMB        '@'
#define CHAR_EMPTY          '.'

#define WIDTH_DEFAULT 2

/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct cell_c {
    char val;
    bool isFound;
    bool isMarked;
} CELL;

typedef struct command_g {
    int cmdCode;
    int posX;
    int posY;
} CMD;

#define random() {(float) rand() / (float) RAND_MAX + 1}

char *readString(char *msg);

void clearScreen(void);

void printGrid(CELL **grid, int rows, int cons);

void mark(CELL **grid, int cordY, int cordX);

CMD parseStr(const char *str);

int handleCords(int *cordTwo, const char *str); /*inside parseStr.c*/

#endif /*PROJECT1_MINESWEEPER_H*/
