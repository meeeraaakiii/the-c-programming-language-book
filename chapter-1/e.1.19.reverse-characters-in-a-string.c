// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
#include <stdio.h>

#define MAXLINE 1000 // maximum input line length
#define THRESHOLD 80 // minimum line length to print

int getLine(char line[], int maxline);
void reverseLine(char line[], int len);

// print all input lines longer than 80 characters
int main() {
    char line[MAXLINE]; // current input line
    int len;            // current line length

    while((len = getLine(line, MAXLINE)) > 0) {
        reverseLine(line, len);
        printf("%s\n", line);
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
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverseLine(char line[], int len) {
    int i, j;
    char temp;
    // reverse the array in place
    // start with len-2 to avoid inserting \0 at the start
    for (i = 0, j = len - 2; i < j; i++, j--) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
    // don't forget null character to terminate the string
    line[len-1] = '\0';
}