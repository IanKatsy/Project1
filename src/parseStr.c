#include "../Minesweeper.h"

CMD parseStr(const char *str) {
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

            if (!strncmp(str, "exit", cmdLen))
                break;

            if (!strncmp(str, "open", cmdLen)) {
                getY = handleCords(&getX, ptr);

                command_p.cmdCode = 1;
                command_p.posX = getX;
                command_p.posY = getY;

                break;
            }

            if (!strncmp(str, "mark", cmdLen)) {
                getY = handleCords(&getX, ptr);

                command_p.cmdCode = 2;
                command_p.posX = getX;
                command_p.posY = getY;

                break;
            }


            break;
        case 5:
            break;
        default:
            command_p.cmdCode = -1;
    }

    return command_p;
}

int handleCords(int *cordTwo, const char *str) {

    int cordX, cordY, digCntr = 0, parCntr = 0;
    char *ptr = str;

    while (!isdigit(*ptr)) {

        if (*ptr == '(')
            parCntr++;

        ptr++;
    }

    if (parCntr != 1) {
        printf("Format: 'command(cordY, cordX)'");
        *cordTwo = -1;
        return -1;
    }

    digCntr++;

    cordY = (int) strtol(ptr, NULL, 10);

    return cordY;
}