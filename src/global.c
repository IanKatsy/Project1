#include "../Minesweeper.h"

int levelCurrent = 0, dimV = 0, dimH = 0;

int cheatMap[] = {
        5, 3, 1, 0
};

CELL CELL_EMPTY = {'.', false, false};

CELL CELL_DEBUG = {'.', true, false};
