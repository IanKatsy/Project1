#include "../Minesweeper.h"

void printGrid(CELL **grid) {

    int i, j, printRet = 0;

    printRet += printf("%4c", ' ');

    for (i = 0; i < dimH; i++) {
        printRet += printf("%*d", WIDTH_DEFAULT, i + 1);
    }
    putchar('\n');

    for (i = 0; i < printRet; i++) {
        putchar('-');
    }
    putchar('\n');

    for (i = 0; i < dimV; i++) {

        printf("%*d| ", WIDTH_DEFAULT, i + 1);

        for (j = 0; j < dimH; j++) {
            if (grid != NULL) {
                if (grid[i][j].isMarked) {
                    printf("%*c ", WIDTH_DEFAULT, CHAR_IS_BOMB);
                } else if (grid[i][j].isFound == 0) {
                    printf("%*c", 2, CHAR_NOT_TOUCHED);
                } else {
                    switch (grid[i][j].val) {
                        case CHAR_EMPTY:
                            printf("%*c", WIDTH_DEFAULT, CHAR_EMPTY);
                            break;

                        case '1':
                            printf("%*s", WIDTH_DEFAULT, MS_ONE);
                            break;

                        case '2':
                            printf("%*s", WIDTH_DEFAULT, MS_TWO);
                            break;

                        case '3':
                            printf("%*s", WIDTH_DEFAULT, MS_THREE);
                            break;

                        case '4':
                            printf("%*s", WIDTH_DEFAULT, MS_FOUR);
                            break;

                        case '5':
                            printf("%*s", WIDTH_DEFAULT, MS_FIVE);
                            break;

                        case '6':
                            printf("%*s", WIDTH_DEFAULT, MS_SIX);
                            break;

                        case '7':
                            printf("%*s", WIDTH_DEFAULT, MS_SEVEN);
                            break;

                        case '8':
                            printf("%*s", WIDTH_DEFAULT, MS_EIGHT);
                            break;

                    }
                }
            } else {
                printf("%*c", 2, CHAR_NOT_TOUCHED);
            }
        }

        putchar('\n');

    }

}
void explosion(CELL **grid) {
    int i, j;

    for (i = 0; i < dimV; i++) {
        for (j = 0; j < dimH; j++) {
            if (grid[i][j].isMarked && grid[i][j].val == '@') {
                printf("%*s", WIDTH_DEFAULT, EXPL_BOMB_FOUND);
            } else if (grid[i][j].isMarked && grid[i][j].val != '@') {
                printf("%*s", WIDTH_DEFAULT, EXPL_ISNT_BOMB);
            } else if (grid[i][j].isMarked == 0 && grid[i][j].val == '@') {
                printf("%*s", WIDTH_DEFAULT, EXPL_BOMB_HIDDEN);
            } else {
                switch (grid[i][j].val) {
                    case CHAR_EMPTY:
                        printf("%*c", WIDTH_DEFAULT, CHAR_EMPTY);
                        break;

                    case '1':
                        printf("%*s", WIDTH_DEFAULT, MS_ONE);
                        break;

                    case '2':
                        printf("%*s", WIDTH_DEFAULT, MS_TWO);
                        break;

                    case '3':
                        printf("%*s", WIDTH_DEFAULT, MS_THREE);
                        break;

                    case '4':
                        printf("%*s", WIDTH_DEFAULT, MS_FOUR);
                        break;

                    case '5':
                        printf("%*s", WIDTH_DEFAULT, MS_FIVE);
                        break;

                    case '6':
                        printf("%*s", WIDTH_DEFAULT, MS_SIX);
                        break;

                    case '7':
                        printf("%*s", WIDTH_DEFAULT, MS_SEVEN);
                        break;

                    case '8':
                        printf("%*s", WIDTH_DEFAULT, MS_EIGHT);
                        break;

                }
            }
        }
    }
}