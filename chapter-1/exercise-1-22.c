/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 10 // Maximum column width before folding

void fold(int maxLineLength) {
    int c, position = 0, lastSpace = -1;
    char buffer[MAX_LINE_LENGTH + 1]; // Buffer to store the current line segment
    int bufIndex = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') { // Reset at new line
            if (bufIndex > 0) {
                buffer[bufIndex] = '\0';
                printf("%s\n", buffer);
            }
            bufIndex = 0;
            position = 0;
            lastSpace = -1;
            continue;
        }

        buffer[bufIndex++] = c;
        position++;

        if (c == ' ') {
            lastSpace = bufIndex - 1; // Store last space position
        }

        if (position >= maxLineLength) {
            if (lastSpace != -1) { // Break at last space
                buffer[lastSpace] = '\0';
                printf("%s\n", buffer);
                bufIndex -= (lastSpace + 1); // Shift remaining characters
                for (int i = 0; i < bufIndex; i++) {
                    buffer[i] = buffer[lastSpace + 1 + i];
                }
                position = bufIndex; // Reset position
            } else { // No spaces, force break
                buffer[bufIndex] = '\0';
                printf("%s\n", buffer);
                bufIndex = 0;
                position = 0;
            }
            lastSpace = -1;
        }
    }

    if (bufIndex > 0) { // Print remaining characters
        buffer[bufIndex] = '\0';
        printf("%s\n", buffer);
    }
}

int main() {
    fold(MAX_LINE_LENGTH);
    return 0;
}
