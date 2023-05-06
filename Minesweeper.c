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

    int i;
    char *getCmd, *level;

    srand(time(NULL));

#ifdef MS_DEBUG_INFO
    {
        printf("%*s", WIDTH_DEFAULT, MS_ONE);
        printf("%*s", WIDTH_DEFAULT, MS_TWO);
        printf("%*s", WIDTH_DEFAULT, MS_THREE);
        printf("%*s", WIDTH_DEFAULT, MS_FOUR);
        printf("%*s", WIDTH_DEFAULT, MS_FIVE);
        printf("%*s", WIDTH_DEFAULT, MS_SIX);
        printf("%*s", WIDTH_DEFAULT, MS_SEVEN);
        printf("%*s", WIDTH_DEFAULT, MS_EIGHT);

        putchar('\n');
    }
#endif

    /*
     * Gets the dimensions of the grid,
     * limits based on Microsoft's minesweeper from Windows Xp.
     * */

    do {
        printf("Enter number of Rows (%d <= R <= %d): ", MS_MIN_GRID_Y, MS_MAX_GRID_Y);
        scanf("%d", &dimV);
        clearStdin();
    } while (dimV < MS_MIN_GRID_Y || dimV > MS_MAX_GRID_Y);

    do {
        printf("Enter number of Columns (%d <= C <= %d): ", MS_MIN_GRID_X, MS_MAX_GRID_X);
        scanf("%d", &dimH);
        clearStdin();
    } while (dimV < MS_MIN_GRID_X || dimV > MS_MAX_GRID_X);

    do {

         level = readString("Enter the starting level\n"
                   "Easy, Normal, Hard, Impossible: ");

        strToUpper(level);

        switch (strlen(level)) {
            case 4:
                if (!strcmp(level, LV_EASY)) {
                    levelCurrent = 1;
                    break;
                }

                if (!strcmp(level, LV_HARD)) {
                    levelCurrent = 3;
                    break;
                }

                printf("Available levels are: "
                       "\n Easy, Normal, Hard, Impossible.");

                break;

            case 6:
                if (!strcmp(level, LV_NORM)) {
                    levelCurrent = 2;
                    break;
                }

                printf("Available levels are: "
                       "\n Easy, Normal, Hard, Impossible.");

                break;

            case 10:
                if (!strcmp(level, LV_IMPB)) {
                    levelCurrent = 4;
                    break;
                }

                printf("Available levels are: "
                       "\n Easy, Normal, Hard, Impossible.");

                break;
            default:
                printf("Available levels are: "
                       "\n Easy, Normal, Hard, Impossible.");
        }

    } while (!levelCurrent);

    clearScreen();

    levelCurrent--;

    for (i = 0; i < levelCurrent; i++) {
        dimH += LEVEL_STEP;
        dimV += LEVEL_STEP;
    }

    printGrid(NULL);

    getCmd = readString("0 Blocks are open!\n"
                        "Make your move(s): ");

    CMD cmd = parseStr(getCmd);

    free(getCmd);

    if (!cmd.cmdCode) {
        return EXIT_SUCCESS;
    }

    for ( ; ; ) {
        CELL **grid = genLevel(cmd.cords);

        bool breakCheck = false;
        bool openRet;

        for ( ; ; ) {
            switch (cmd.cmdCode) {
                case 1:
                    if (grid[cmd.cords.cordY][cmd.cords.cordX].isFound) {
                        printf("Can't open a found cell!\n");
                        break;
                    }

                    openRet = openCell(grid, cmd.cords);
                    if (openRet) {
                        explosion(grid);
                        breakCheck = true;
                    }

                    break;
                case 2:
                    markCell(grid, cmd.cords);
                    break;
                case 3:
                    cheat(grid, cmd.cords, false);
                    break;

                default:
                    break;
            }

            if (breakCheck)
                break;



        }

        freeGrid(grid);

        if (++levelCurrent == 4) {
            break;
        }
    }


    return 0;
}

