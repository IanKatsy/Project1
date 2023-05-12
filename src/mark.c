#include "../Minesweeper.h"

void markCell(CELL **grid, COORDS coords) { /* is used to mark and unmark a cell */

    if (grid[coords.cordY][coords.cordX].isMarked) {
        printf("Removed mark at: (%d, %d)!\n", coords.cordY + 1, coords.cordX + 1);
    } else {
        printf("Marked position (%d, %d).\n"
               "Use mark() again to remove the mark!\n",
               coords.cordY + 1,
               coords.cordX + 1);
    }

    grid[coords.cordY][coords.cordX].isMarked = !grid[coords.cordY][coords.cordX].isMarked;

}
