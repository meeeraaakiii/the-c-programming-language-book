/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)
*/

#include <stdio.h>

#define MAX_STACK 1024

// Stack for storing opening symbols
char stack[MAX_STACK];
int top = -1;

void push(char c) {
    if (top < MAX_STACK - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    int c;
    int in_single_quote = 0, in_double_quote = 0, in_comment = 0, prev = 0;

    while ((c = getchar()) != EOF) {
        // Handle comments
        if (!in_single_quote && !in_double_quote) {
            if (!in_comment && c == '/' && prev == '/') {
                in_comment = 1; // Single-line comment
            } else if (!in_comment && c == '*' && prev == '/') {
                in_comment = 2; // Multi-line comment
            } else if (in_comment == 2 && c == '/' && prev == '*') {
                in_comment = 0; // End of multi-line comment
                c = 0; // Prevent further processing
            } else if (in_comment == 1 && c == '\n') {
                in_comment = 0; // End of single-line comment
            }
        }

        if (in_comment) {
            prev = c;
            continue;
        }

        // Handle quotes
        if (c == '\\' && (in_single_quote || in_double_quote)) {
            getchar(); // Skip escaped character
            continue;
        }

        if (c == '"' && !in_single_quote) {
            in_double_quote = !in_double_quote;
        }
        if (c == '\'' && !in_double_quote) {
            in_single_quote = !in_single_quote;
        }

        // Ignore checks inside quotes
        if (in_single_quote || in_double_quote) {
            prev = c;
            continue;
        }

        // Handle brackets, braces, and parentheses
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            char expected = (c == ')') ? '(' : (c == ']') ? '[' : '{';
            if (pop() != expected) {
                printf("Syntax Error: Unmatched %c\n", c);
                return 1;
            }
        }
        prev = c;
    }

    if (top != -1) {
        printf("Syntax Error: Unmatched %c\n", stack[top]);
        return 1;
    }

    if (in_single_quote) {
        printf("Didn't close single quote\n");
        return 1;
    }

    if (in_double_quote) {
        printf("Didn't close double quote\n");
        return 1;
    }

    if (in_comment == 2) {
        printf("Didn't close multi-line comment\n");
        return 1; 
    }

    printf("No syntax errors detected.\n");
    return 0;
}
