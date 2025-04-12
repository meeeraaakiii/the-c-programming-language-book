// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
// for loop in question:
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    // s[i] = c;

#include <stdio.h>

int main()
{
    int lim = 10;
    char s[lim];
    for (int i=0; i <= lim-1; ++i) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            putchar('\n');
            break;
        }
        s[i] = c;
    }
    printf(s);
    putchar('\n');
    return 0;
}
