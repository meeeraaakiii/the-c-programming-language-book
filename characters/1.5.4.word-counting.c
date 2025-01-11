// Count lines, words and characters in input

#include <stdio.h>

#define IN   1 // inside a word
#define OUT  0 // outside a word

void main() {
    int character, numberOfLines, numberOfWords, numberOfCharacters, state;

    state = OUT;
    numberOfLines = numberOfWords = numberOfCharacters = 0;
    while ((character = getchar()) != EOF) {
        ++numberOfCharacters;
        if (character == '\n')
            ++numberOfLines;
        if (character == ' ' || character == '\n' || character == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++numberOfWords;
        }
    }
    printf("numberOfLines: %d, numberOfWords: %d, numberOfCharacters: %d", numberOfLines, numberOfWords, numberOfCharacters);
}
