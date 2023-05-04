#include "../Minesweeper.h"


void cheat(CELL **grid, int cordY, int cordX, bool reset) {

    static int counter;

    if (reset) {
        counter = 0;
        return;
    }

    if (counter > cheatMap[levelCurrent - 1]){
        printf("You cannot cheat anymore!!!\n");
        return;
    }

    printf("In position (%d, %d) there is a %c!\n", cordY, cordX, grid[cordY][cordX].val);
    counter++;

}



