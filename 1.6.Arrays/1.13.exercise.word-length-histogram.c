// Print a histogram of lengths of words in the input. Words up to 20 characters until we learn dynamic memory.

#include <stdio.h>

#define MAX_WORD_LENGTH 20 // Maximum word length to track
#define IN   1 // inside a word
#define OUT  0 // outside a word

void main() {
    int character, length = 0, state = OUT;
    int wordLengths[MAX_WORD_LENGTH]; // Array to count word lengths
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        wordLengths[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n' || character == '\t') {
            // blank character
            if (state == IN) {
                // were inside of the word, getting outside
                // record length
                if (length < MAX_WORD_LENGTH) {
                        wordLengths[length]++;
                }
                // reset length
                length = 0;
            }
            // now outside of the word
            state = OUT;
        } else {
            // non-blank character, entering the word or inside the word already
            state = IN;
            ++length;
        }
    }

    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        int lengthOfTheCurrentWord = wordLengths[i];
        printf("%d: ", i);
        for (int barCounter = 0; barCounter < lengthOfTheCurrentWord; barCounter++) {
            putchar('|');
        }
        putchar('\n');
    }
}
