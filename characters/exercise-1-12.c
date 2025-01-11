// Print input one word per line

#include <stdio.h>

#define IN   1 // inside a word
#define OUT  0 // outside a word

void main() {
    int character, state;

    state = OUT;
    while ((character = getchar()) != EOF) {
        // if (character == '\n')
            // ++numberOfLines;
        if (character == ' ' || character == '\n' || character == '\t') {
            state = OUT;
            // print newline instead of that character
            putchar('\n');
        } else if (state == OUT) {
            state = IN;
            // print the character itself
            putchar(character);
        } else {
            // print the character itself
            putchar(character);
        }
    }
}
