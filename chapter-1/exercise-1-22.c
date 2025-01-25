/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 10 // largest allowed length for a line (unless there are no spaces in it)

int fold(int maxLineLength) {
    int i, c, counter = 0;
    for (int i = 0;(c = getchar()) != EOF && c != '\n'; i++) {
        counter++;
        if (counter >= 10 && c == ' ') {
            counter = 0;
            putchar('\n');
            continue;
        }
        putchar(c);
    }
    putchar('\n');
    return 0;
}

int main() {
    fold(MAX_LINE_LENGTH);
    return 0;
}
