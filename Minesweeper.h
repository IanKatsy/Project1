#ifndef PROJECT1_MINESWEEPER_H
#define PROJECT1_MINESWEEPER_H

//// #define MS_DEBUG_INFO 0
//
//#if MS_DEBUG_INFO
//
//#define CELL_DEBUG_SET
//
//#endif

#define MS_MIN_GRID_X 9
#define MS_MIN_GRID_Y 9
#define MS_MIN_MINE 10

#define MS_MAX_GRID_X 30
#define MS_MAX_GRID_Y 24
#define MS_MAX_MINE 667

#define CL_OUT_WRK

#ifdef CL_OUT_WRK

#define ANSI_RESET_ALL          "\x1b[0m"

#define ANSI_COLOR_BLACK        "\x1b[30m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_WHITE        "\x1b[37m"

#define ANSI_BACKGROUND_BLACK   "\x1b[40m"
#define ANSI_BACKGROUND_RED     "\x1b[41m"
#define ANSI_BACKGROUND_GREEN   "\x1b[42m"
#define ANSI_BACKGROUND_YELLOW  "\x1b[43m"
#define ANSI_BACKGROUND_BLUE    "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN    "\x1b[46m"
#define ANSI_BACKGROUND_WHITE   "\x1b[47m"

#define ANSI_STYLE_BOLD         "\x1b[1m"
#define ANSI_STYLE_ITALIC       "\x1b[3m"
#define ANSI_STYLE_UNDERLINE    "\x1b[4m"

#define MS_ONE              ANSI_COLOR_BLUE                         " 1"     ANSI_RESET_ALL
#define MS_TWO              ANSI_COLOR_GREEN                        " 2"     ANSI_RESET_ALL
#define MS_THREE            ANSI_COLOR_RED                          " 3"     ANSI_RESET_ALL
#define MS_FOUR             ANSI_COLOR_BLUE     ANSI_STYLE_BOLD     " 4"     ANSI_RESET_ALL
#define MS_FIVE             ANSI_COLOR_RED      ANSI_STYLE_BOLD     " 5"     ANSI_RESET_ALL
#define MS_SIX              ANSI_COLOR_CYAN                         " 6"     ANSI_RESET_ALL
#define MS_SEVEN            ANSI_COLOR_MAGENTA                      " 7"     ANSI_RESET_ALL
#define MS_EIGHT            ANSI_COLOR_WHITE                        " 8"     ANSI_RESET_ALL

#define EXPL_BOMB_FOUND     ANSI_COLOR_GREEN                        " @"     ANSI_RESET_ALL
#define EXPL_BOMB_HIDDEN    ANSI_COLOR_RED                          " @"     ANSI_RESET_ALL
#define EXPL_ISNT_BOMB      ANSI_COLOR_RED                          " X"     ANSI_RESET_ALL

#endif /*CL_OUT_WRK*/

#define CHAR_NOT_TOUCHED    '#'
#define CHAR_IS_BOMB        '@'
#define CHAR_EMPTY          '.'

#define WIDTH_DEFAULT 2

#define LV_EASY "EASY"
#define LV_NORM "NORMAL"
#define LV_HARD "HARD"
#define LV_IMPB "IMPOSSIBLE"

/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


extern int levelCurrent, dimV, dimH;

extern const char *level_name[];

typedef struct minesweeper_cell {
    char val;
    bool isFound;
    bool isMarked;
} CELL;

typedef struct coordinate_tuple {
    int cordY;
    int cordX;
} COORDS;

extern COORDS placeholderCoords;

#define COORDS_DEF_VAL placeholderCoords

typedef struct command_return {
    int cmdCode;
    COORDS cords;
} CMD;

#define random() (float) rand() / (float) RAND_MAX + 1

char *readString(char *msg);

void clearStdin(void); /*util.c*/

void strToUpper(char *string); /*util.c*/

int roundCstm(double x); /*util.c*/

void printGrid(CELL **grid);

void explosion(CELL **grid);

bool openCell(CELL **grid, COORDS coords);

void markCell(CELL **grid, COORDS coords);

void cheat(CELL **grid, COORDS coords, bool reset);

extern int cheatMap[];
extern int cheatCount;

CMD parseStr(char *str);

COORDS handleCoords(char *str); /*inside parseStr.c*/

#define BAD_RET_COORDS { \
    printf("Format: 'command(cordY, cordX)', coords must be within level bounds!\n"); \
    return COORDS_DEF_VAL;     \
    }

CELL **genLevel(COORDS coords);

#define LEVEL_STEP 5

extern CELL CELL_EMPTY;

extern CELL CELL_DEBUG;

#ifdef CELL_DEBUG_SET

#define CELL_SET CELL_DEBUG;

#else

#define CELL_SET CELL_EMPTY;

#endif

void freeGrid(CELL **grid);

int countOpenCell(CELL **grid);

int countFreeCell(CELL **grid);

#endif /*PROJECT1_MINESWEEPER_H*/
