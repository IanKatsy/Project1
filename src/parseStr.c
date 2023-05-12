#include "../Minesweeper.h"

/*
 * file specific defines
 * */

#ifdef MS_DEBUG_INFO
#define SHOW_CORD_REC(x) printf("%d \n", x);
#elif
#define SHOW_CORD_REC(x)
#endif
CMD parseStr(char *str) {
    CMD command_p = {
        0, 0, 0
    };

    char *ptr = str;

    int getX, getY;

    while (isalpha(*ptr))
        ptr++;

    size_t cmdLen = ptr - str;

    switch (cmdLen) {

        case 4:

            if (!strncmp(str, "EXIT", cmdLen)) {
                command_p.cmdCode = 0;
                break;
            }

            if (!strncmp(str, "OPEN", cmdLen)) {

                command_p.cmdCode = 1;
                command_p.cords = handleCoords(ptr);

                break;
            }

            if (!strncmp(str, "MARK", cmdLen)) {

                command_p.cmdCode = 2;
                command_p.cords = handleCoords(ptr);

                break;
            }

            break;
        case 5:

            if (!strncmp(str, "CHEAT", cmdLen)) {
                command_p.cmdCode = 3;
                command_p.cords = handleCoords(ptr);
            }

            break;
        default:
            command_p.cmdCode = -1;
    }

    return command_p;
}

COORDS handleCoords(char *str) {

    /*
     * A very sad mess :(
     * */

    COORDS coords = {
            -1,
            -1
    };

    int digCntr = 0, parCntr = 0;
    size_t buffOverflowCheck = strlen(str);
    char *ptr = str;
    bool postParenthesesHandle = false;

    /*
     * Check for first parentheses
     * */

    while (!isdigit(*ptr) && buffOverflowCheck != ptr - str) {
        if (*ptr == '(')
            parCntr++;

        if (isalnum(*ptr))
            BAD_RET_COORDS;

        ptr++;
    }

    /*
     * Bad input handle
     * */

    if (parCntr != 1 || buffOverflowCheck == ptr - str)
        BAD_RET_COORDS;

    /*
     * First coordinate
     * */

    digCntr++;
    coords.cordY = (int) strtol(ptr, &ptr, 10);
    SHOW_CORD_REC(coords.cordY)

    while (*ptr != ',' || buffOverflowCheck != ptr - str)
        ptr++;

    /*
     * Bad input handle
     * */

    if (buffOverflowCheck == ptr - str)
        BAD_RET_COORDS;

    /*
     * Second coordinate
     * */

    digCntr++;
    coords.cordX = (int) strtol(ptr, &ptr, 10);
    SHOW_CORD_REC(coords.cordX)

    /*
     * Check for second parentheses
     * */

    while (!isdigit(*ptr) && buffOverflowCheck != ptr - str) {
        if (*ptr == ')')
            parCntr++;

        if (isalpha(*ptr))
            BAD_RET_COORDS;

        ptr++;
    }

    /*
     * Bad input handle
     * */

    if (parCntr != 2 || buffOverflowCheck == ptr - str)
        BAD_RET_COORDS;

    if (digCntr != 2)
        BAD_RET_COORDS;

    while (buffOverflowCheck != ptr - str) {
        if (!isspace(*ptr) && !isblank(*ptr))
            postParenthesesHandle = true;
    }

    if (postParenthesesHandle)
        BAD_RET_COORDS;

    if (coords.cordY > dimV || coords.cordY < 1)
        BAD_RET_COORDS;

    if (coords.cordX > dimH || coords.cordX < 1)
        BAD_RET_COORDS;

    return coords;
}