#include "../Minesweeper.h"

bool openCell(CELL **grid, COORDS coords) {

    int y = coords.cordY, x = coords.cordX;

    if (grid[y][x].isMarked) {
        return false;
    }

    if (grid[y][x].isFound) {
        return false;
    }

    grid[y][x].isFound = true;

    if (grid[y][x].val == CHAR_IS_BOMB)
        return true;

    if (grid[y][x].val == CHAR_EMPTY) {

        /*
        * Math is very lovely
        * */

        /*
         * Top left
         * */
        if (y > 0 && x > 0) {
            COORDS tL = {coords.cordY - 1, coords.cordX - 1};
            openCell(grid, tL);
        }

        /*
         * Top
         * */
        if (y > 0) {
            COORDS t = {coords.cordY - 1, coords.cordX};
            openCell(grid, t);
        }

        /*
         * Top right
         * */
        if (y > 0 && x < dimH - 1) {
            COORDS tR = {coords.cordY - 1, coords.cordX + 1};
            openCell(grid, tR);
        }

        /*
         * Left
         * */
        if (x > 0) {
            COORDS l = {coords.cordY, coords.cordX - 1};
            openCell(grid, l);
        }

        /*
         * Right
         * */
        if (x < dimH - 1) {
            COORDS r = {coords.cordY, coords.cordX + 1};
            openCell(grid, r);
        }

        /*
         * Bottom left
         * */
        if (x > 0 && y < dimV - 1) {
            COORDS bL = {coords.cordY + 1, coords.cordX - 1};
            openCell(grid, bL);
        }

        /*
         * Bottom
         * */
        if (y < dimV - 1) {
            COORDS b = {coords.cordY + 1, coords.cordX};
            openCell(grid, b);
        }

        /*
         * Bottom right
         * */
        if (y < dimV - 1 && x < dimH - 1) {
            COORDS bR = {coords.cordY + 1, coords.cordX + 1};
            openCell(grid, bR);
        }
    }

    return false;
}