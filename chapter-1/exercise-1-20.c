// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define SPACES_PER_TAB     2 // amount of spaces per tab
#define MAX_LINE_LENGTH 1000 // maximum line length

int getLine(char s[], int maxCharLength);

int main() {
    int c, len;
    char line[MAX_LINE_LENGTH];

    while((len = getLine(line, MAX_LINE_LENGTH)) > 0) {
        printf("'%s'\n", line);
    }
    return 0;
}

// read a line into s, return its length
int getLine(char s[], int maxCharLength) {
    int c, i, realCounter;
    realCounter = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < maxCharLength - 1) {
            if (c == '\t') {
                for (int k = 0; k < SPACES_PER_TAB; k++) {
                    s[realCounter] = ' ';
                    realCounter++;
                }
            } else {
                s[realCounter] = c;
                realCounter++;
            }
        }
    }
    s[realCounter] = '\0';
    return realCounter;
}