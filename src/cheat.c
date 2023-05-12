#include "../Minesweeper.h"


void cheat(CELL **grid, COORDS coords, bool reset) {

    static int counter;

    if (reset) {
        counter = 0;
        return;
    }

    if (counter > cheatMap[levelCurrent]){
        printf("You cannot cheat anymore!!!\n");
        return;
    }

    printf("In position (%d, %d) there is a %c!\n",
           coords.cordY,
           coords.cordX,
           grid[coords.cordY][coords.cordX].val);

    counter++;
    cheatCount++;

}



