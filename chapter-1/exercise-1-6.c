#include <stdio.h>

// copy input to output, second version
void main() {
    int c, isNotEOF;
    while (1) {
        c = getchar();
        isNotEOF = c != EOF;
        printf("character: '%c', isNotEOF: %d\n", c, isNotEOF);
        if (isNotEOF != 1) {
            break;
        }
    }
}
