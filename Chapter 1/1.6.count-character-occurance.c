// Count digits, white space, others
#include <stdio.h>

void main() {
    int character, i, numberOfBlankChars, numberOfOtherChars;
    int ndigit[10];

    numberOfBlankChars = numberOfOtherChars = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }
    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9') {
            ++ndigit[character-'0'];
        } else if (character == ' ' || character == '\n' || character == '\t') {
            ++numberOfBlankChars;
        } else {
            ++numberOfOtherChars;
        }
    }
    printf("digits:");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", numberOfBlankChars, numberOfOtherChars);
}
