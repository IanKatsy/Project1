#include "../Minesweeper.h"

void clearStdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void strToUpper(char *string) {

    size_t len = strlen(string);
    int i;

    for (i = 0; i < len; i++) {
        if (isalpha(*(string + i))) {
            *(string + i) = (char) toupper(*(string + i));
        }
    }

}

int roundCstm(double x) {
    return x - (int) x < 0.5 ? (int) x : (int) x + 1;
}