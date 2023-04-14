#include "Minesweeper.h"

char *readString(char *msg) {

    if (msg != NULL) {
        printf("%s", msg);
    }

    char *str = NULL, *cp;
    char ch;
    int len = 0;

    do {
        ch = getchar();

        if (ch == '\n') {
            ch = '\0';
        }

        len++;

        cp = realloc(str, len);

        if (cp == NULL) {
            perror("realloc() returned a NULL pointer");
            exit(EXIT_FAILURE);
        }

        str = cp;

        str[len - 1] = ch;

    } while (ch != '\0');

    return str;
}
