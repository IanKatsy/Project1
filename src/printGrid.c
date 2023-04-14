#include "../Minesweeper.h"

void printGrid(CELL **grid, int rows, int cons) {

    int i, j;

    printf("%4c", ' ');
    for (i = 0; i < cons; i++) {
        printf(" %d ", i + 1);
    }
    putchar('\n');
    printf("-----------------------------------------------------\n");

    for (i = 0; i < rows; i++) {

        printf("%*d| ", WIDTH_DEFAULT, i + 1);

        for (j = 0; j < cons; j++) {
            if (grid[i][j].isMarked)  {
                printf("%*c ", WIDTH_DEFAULT, CHAR_IS_BOMB);
            } else if (grid[i][j].isFound == 0 || grid == NULL) {
                printf("%*c", 2, CHAR_NOT_TOUCHED);
            } else {
                switch (grid[i][j].val) {
                    case CHAR_EMPTY: printf("%*c", WIDTH_DEFAULT, CHAR_EMPTY); break;

                    case '1': printf("%*s", WIDTH_DEFAULT, MS_ONE);    break;

                    case '2': printf("%*s", WIDTH_DEFAULT, MS_TWO);    break;

                    case '3': printf("%*s", WIDTH_DEFAULT, MS_THREE);  break;

                    case '4': printf("%*s", WIDTH_DEFAULT, MS_FOUR);   break;

                    case '5': printf("%*s", WIDTH_DEFAULT, MS_FIVE);   break;

                    case '6': printf("%*s", WIDTH_DEFAULT, MS_SIX);    break;

                    case '7': printf("%*s", WIDTH_DEFAULT, MS_SEVEN);  break;

                    case '8': printf("%*s", WIDTH_DEFAULT, MS_EIGHT);  break;

                    case CHAR_IS_BOMB:                                      break;
                }
            }
        }
    }

    putchar('\n');
}
