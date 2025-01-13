// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.
#include <stdio.h>

#define MAXLINE 1000 // maximum input line length

int getLine(char line[], int maxline);

// print all input lines longer than 80 characters
int main() {
    char line[MAXLINE]; // current input line
    int len;            // current line length

    while((len = getLine(line, MAXLINE)) != 0) {
        if (len != -1) {
            printf("'%s'\n", line);
        }
    }
    return 0;
}

// read a line into s, return its length
int getLine(char s[], int lim) {
    int c, i, lastNonBlankNonTrailingIndex;
    lastNonBlankNonTrailingIndex = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if ((i < lim - 1)) {
            if (c != ' ' && c != '\t') {
                lastNonBlankNonTrailingIndex = i;
                s[i] = c;
            } else {
                s[i] = c;
            }
        }
    }
    if(c == '\n') {
        if (i != lastNonBlankNonTrailingIndex) {
            i = lastNonBlankNonTrailingIndex+1;
        }
    }
    if (lastNonBlankNonTrailingIndex == 0) {
        s[lastNonBlankNonTrailingIndex] = '\0';
        return -1;
    } else {
        s[i] = '\0';
    }
    return i;
}
