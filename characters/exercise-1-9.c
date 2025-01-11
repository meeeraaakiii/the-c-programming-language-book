#include <stdio.h>

int main() {
    int c;          // Variable to store the current character
    int prev = 0;   // Variable to track the previous character

    while ((c = getchar()) != EOF) { // Read input until End-Of-File
        if (c != ' ' || prev != ' ') {
            putchar(c); // Output the character if it's not a duplicate blank
        }
        prev = c; // Update the previous character
    }

    return 0;
}
