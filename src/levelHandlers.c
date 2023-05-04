#include "../Minesweeper.h"

CELL **genLevel(int dimV, int dimH, int level) {

    level--;
    int i, j;
    CELL **table;

    float percentMap[] = {
            .10, .15, .20, .25
    };

    for (i = 0; i < level; i++) {
        dimH += LEVEL_STEP;
        dimV += LEVEL_STEP;
    }

    int mul = dimH * dimV, bombs = roundCstm(percentMap[level] * mul);

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
        int x = dimH * random(), y = dimV * random();

        if (table[y][x].val == '@')
            continue;
        else {
            table[y][x].val = '@';

            /*
             * Math is very lovely
             * */

            /*
             * Top left
             * */
            if (y > 0 && x > 0) {
                if (table[y - 1][x - 1].val != '@') {
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
                if (table[y - 1][x].val != '@') {
                    if (table[y - 1][x].val == '.')
                        table[y - 1][x].val = '1';
                    else
                        table[y - 1][x].val++;
                }
            }

            /*
             * Top right
             * */
            if (y > 0 && x < dimH) {
                if (table[y - 1][x + 1].val != '@') {
                    if (table[y - 1][x + 1].val == '.')
                        table[y - 1][x + 1].val = '1';
                    else
                        table[y - 1][x + 1].val++;
                }
            }

            /*
             * Left
             * */
            if (x > 0) {
                if (table[y][x - 1].val != '@') {
                    if (table[y][x - 1].val == '.')
                        table[y][x - 1].val = '1';
                    else
                        table[y][x - 1].val++;
                }
            }

            /*
             * Right
             * */
            if (x < dimH) {
                if (table[y][x + 1].val != '@') {
                    if (table[y][x + 1].val == '.')
                        table[y][x + 1].val = '1';
                    else
                        table[y][x + 1].val++;
                }
            }

            /*
             * Bottom left
             * */
            if (x > 0 && y < dimV) {
                if (table[y + 1][x - 1].val != '@') {
                    if (table[y + 1][x - 1].val == '.')
                        table[y + 1][x - 1].val = '1';
                    else
                        table[y + 1][x - 1].val++;
                }
            }

            /*
             * Bottom
             * */
            if (y < dimV) {
                if (table[y + 1][x].val != '@') {
                    if (table[y + 1][x].val == '.')
                        table[y + 1][x].val = '1';
                    else
                        table[y + 1][x].val++;
                }
            }

            /*
             * Bottom right
             * */
            if (y < dimV && x < dimH) {
                if (table[y + 1][x].val != '@') {
                    if (table[y + 1][x].val == '.')
                        table[y + 1][x].val = '1';
                    else
                        table[y + 1][x].val++;
                }
            }
        }

        bombCount++;
    }

    return table;
}
