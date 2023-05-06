#include "../Minesweeper.h"

void markCell(CELL **grid, COORDS coords) { /* is used to mark and unmark a cell */

    if (grid[coords.cordY][coords.cordX].isMarked) {
        printf("Removed mark at: (%d, %d)!\n", coords.cordY, coords.cordX);
    } else {
        printf("Marked position (%d, %d). Use mark() again to remove the mark!\n", coords.cordY, coords.cordX);
    }

    grid[coords.cordY][coords.cordX].isMarked = !grid[coords.cordY][coords.cordX].isMarked;

}
