// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define SPACES_PER_TAB     2 // amount of spaces per tab
#define MAX_LINE_LENGTH 1000 // maximum line length

int entab(int maxLineLength);

int main() {
    entab(MAX_LINE_LENGTH);
    return 0;
}

// read a line into s, return its length
int entab(int maxLineLength) {
    int c, i, spaceCounter;
    spaceCounter = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < maxLineLength - 1) {
            if (c == ' ') {
                // count spaces but don't print anything
                spaceCounter++;
                if (spaceCounter % SPACES_PER_TAB == 0) {
                    // unless amount of spaces reached - then print tab
                    putchar('\t');
                    // reset the space counter
                    spaceCounter = 0;
                }
            } else {
                for (int i = 0; i < spaceCounter; i++) {
                    // not enough spaces for a tab, print all spaces
                    putchar(' ');
                }
                // reset counter
                spaceCounter = 0;

                // current character
                putchar(c);
            }
        }
    }
    putchar('\n');

    return i;
}