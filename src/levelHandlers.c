#include "../Minesweeper.h"

CELL **genLevel(COORDS coords) {

    int i, j;
    CELL **table;

    float percentMap[] = {
            .10, .15, .20, .25
    };

    int mul = dimH * dimV, bombs = roundCstm(percentMap[levelCurrent] * mul);

    /*
     * malloc() a dimV * dimH 2 dimensional array.
     * */

    table = malloc(dimV * sizeof(CELL *));
    if (table == NULL) {
        perror("malloc() returned a NULL pointer");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < dimV; i++) {
        table[i] = malloc(sizeof(CELL) * dimH);
        if (table[i] == NULL) {
            perror("malloc() returned a NULL pointer");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < dimV; i++) {
        for (j = 0; j < dimH; j++) {
            table[i][j] = CELL_SET;
        }
    }

    int bombCount = 0;

    while (bombCount != bombs) {
        int x = (dimH - 1) * random(), y = (dimV - 1) * random();

        if (table[y][x].val == CHAR_IS_BOMB || (coords.cordX == x && coords.cordY == y))
            continue;

        table[y][x].val = '@';

        /*
         * Math is very lovely
         * */

        /*
         * Top left
         * */
        if (y > 0 && x > 0) {
            if (table[y - 1][x - 1].val != CHAR_IS_BOMB) {
                if (table[y - 1][x - 1].val == '.')
                    table[y - 1][x - 1].val = '1';
                else
                    table[y - 1][x - 1].val++;
            }
        }

        /*
         * Top
         * */
        if (y > 0) {
            if (table[y - 1][x].val != CHAR_IS_BOMB) {
                if (table[y - 1][x].val == CHAR_EMPTY)
                    table[y - 1][x].val = '1';
                else
                    table[y - 1][x].val++;
            }
        }

        /*
         * Top right
         * */
        if (y > 0 && x < (dimH - 1)) {
            if (table[y - 1][x + 1].val != CHAR_IS_BOMB) {
                if (table[y - 1][x + 1].val == CHAR_EMPTY)
                    table[y - 1][x + 1].val = '1';
                else
                    table[y - 1][x + 1].val++;
            }
        }

        /*
         * Left
         * */
        if (x > 0) {
            if (table[y][x - 1].val != CHAR_IS_BOMB) {
                if (table[y][x - 1].val == CHAR_EMPTY)
                    table[y][x - 1].val = '1';
                else
                    table[y][x - 1].val++;
            }
        }

        /*
         * Right
         * */
        if (x < (dimH - 1)) {
            if (table[y][x + 1].val != CHAR_IS_BOMB) {
                if (table[y][x + 1].val == CHAR_EMPTY)
                    table[y][x + 1].val = '1';
                else
                    table[y][x + 1].val++;
            }
        }

        /*
         * Bottom left
         * */
        if (x > 0 && y < (dimV - 1)) {
            if (table[y + 1][x - 1].val != CHAR_IS_BOMB) {
                if (table[y + 1][x - 1].val == CHAR_EMPTY)
                    table[y + 1][x - 1].val = '1';
                else
                    table[y + 1][x - 1].val++;
            }
        }

        /*
         * Bottom
         * */
        if (y < (dimV - 1)) {
            if (table[y + 1][x].val != CHAR_IS_BOMB) {
                if (table[y + 1][x].val == CHAR_EMPTY)
                    table[y + 1][x].val = '1';
                else
                    table[y + 1][x].val++;
            }
        }

        /*
         * Bottom right
         * */
        if (y < (dimV - 1) && x < (dimH - 1)) {
            if (table[y + 1][x + 1].val != CHAR_IS_BOMB) {
                if (table[y + 1][x + 1].val == CHAR_EMPTY)
                    table[y + 1][x + 1].val = '1';
                else
                    table[y + 1][x + 1].val++;
            }
        }


        bombCount++;
    }

    return table;
}

void freeGrid(CELL **grid) {

    int i;

    for (i = 0; i < dimV; i++) {
        free(grid[i]);
    }
    free(grid);

}

int countOpenCell(CELL **grid) {

    int i, j, ret = 0;

    for (i = 0; i < dimV; i++) {
        for (j = 0; j < dimH; j++) {
            if (grid[i][j].isFound)
                ret++;
        }
    }

    return ret;
}

int countFreeCell(CELL **grid) {

    int i, j, ret = 0;

    for (i = 0; i < dimV; i++) {
        for (j = 0; j < dimH; j++) {
            if (grid[i][j].val != '@')
                ret++;
        }
    }

    return ret;
}
