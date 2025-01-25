/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 100 // Maximum column width before folding

void removeComments() {
    int c;
    int bufIndex = 0;
    char programBuffer[MAX_LINE_LENGTH]; // Buffer to store the current program
    while (((c = getchar()) != EOF && bufIndex <= MAX_LINE_LENGTH-1)) {
        // if first slash is encountered
        if (c == '/') {
            // get the second character
            c = getchar();
            // if second slash is encountered
            if (c == '/') {
                while ((c = getchar() != '\n' && c != EOF)) {
                    // skip all the lines until newline or end of the file
                    continue;
                }
                programBuffer[bufIndex] = '\n';
                bufIndex++;
            } else if (c == '*') {
                // if we have /*
                while (((c = getchar()) != EOF)) {
                    // read file until *
                    if (c == '*') {
                        c = getchar();
                        // if next char is /
                        if (c == '/') {
                            // break out of this loop, we are out of the comment
                            break;
                        }
                    }
                }
            } else {
                // add a slash and the second character
                programBuffer[bufIndex] = '/';
                bufIndex++;
                programBuffer[bufIndex] = c;
                bufIndex++;
            }
        } else {
            // add character to the program buffer
            programBuffer[bufIndex] = c;
            bufIndex++;
        }
    }
    programBuffer[bufIndex] = '\0';

    // print the whole program
    putchar('\n');
    putchar('\n');
    for (int i = 0; i <= bufIndex; i++) {
        c = programBuffer[i];
        putchar(c);
    }
}

int main() {
    removeComments();
    return 0;
}
