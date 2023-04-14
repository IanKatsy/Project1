#include "minesweeper.h"

void mark(CELL **grid, int cordY, int cordX) { /* is used to mark and unmark a cell */

    if (grid[cordY][cordX].isMarked) {
        printf("Removed mark at: (%d, %d)!\n", cordY, cordX);
    } else {
        printf("Marked position (%d, %d). Use mark() again to remove the mark!\n", cordY, cordX);
    }

    grid[cordY][cordX].isMarked = !grid[cordY][cordX].isMarked;

}
