// Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
#include <stdio.h>

#define MAXLINE 1000 // maximum input line length
#define THRESHOLD 80 // minimum line length to print

int getLine(char line[], int maxline);

// print all input lines longer than 80 characters
int main() {
    char line[MAXLINE]; // current input line
    int len;            // current line length

    while((len = getLine(line, MAXLINE)) > 0) {
        if(len > THRESHOLD) {
            printf("Long line (%d characters): %s", len, line);
        }
    }
    return 0;
}

// read a line into s, return its length
int getLine(char s[], int lim) {
    int c, i;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
