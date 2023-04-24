/*
    *   IOANNIS KATSIYIANNIS
    *   AM: 2022202200081
    *   Email:  dit22081@go.uop.gr
    *
    *   HLIAS DRAKOS
    *   AM: 2022202200042
    *   Email: dit22042@go.uop.gr
*/

#include "Minesweeper.h"

int main(void) {

    int i, dimV, dimH;
    char *getCmd;

    srand(time(NULL));

#ifdef MS_DEBUG_INFO

    printf("%*s", WIDTH_DEFAULT, MS_ONE);
    printf("%*s", WIDTH_DEFAULT, MS_TWO);
    printf("%*s", WIDTH_DEFAULT, MS_THREE);
    printf("%*s", WIDTH_DEFAULT, MS_FOUR);
    printf("%*s", WIDTH_DEFAULT, MS_FIVE);
    printf("%*s", WIDTH_DEFAULT, MS_SIX);
    printf("%*s", WIDTH_DEFAULT, MS_SEVEN);
    printf("%*s", WIDTH_DEFAULT, MS_EIGHT);

    putchar('\n');

#endif

    /*
     * Gets the dimensions of the grid,
     * limits based on Microsoft's minesweeper from Windows Xp.
     * */

    do {
        printf("Enter number of Rows (%d <= R <= %d): ", MS_MIN_GRID_Y, MS_MAX_GRID_Y);
        scanf("%d", &dimV);
    } while (dimV < MS_MIN_GRID_Y || dimV > MS_MAX_GRID_Y);

    do {
        printf("Enter number of Columns (%d <= C <= %d): ", MS_MIN_GRID_X, MS_MAX_GRID_X);
        scanf("%d", &dimH);
    } while (dimV < MS_MIN_GRID_X || dimV > MS_MAX_GRID_X);

    /*
     * malloc() a dimV * dimH 2 dimensional array.
     * */

    CELL **table = malloc(dimV * sizeof(CELL *));
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

    printGrid(NULL, dimV, dimH);

    getCmd = readString("0 Blocks are open!\nMake your move(s): ");

    CMD cmd = parseStr(getCmd);

    if (!cmd.cmdCode) {
        for (i = 0; i < dimV; i++) {
            free(table[i]);
        }
        free(*table);
        free(getCmd);
        return EXIT_SUCCESS;
    }

}

