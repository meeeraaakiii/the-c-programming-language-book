#include <stdio.h>

void main() {
    // post-increment
    for (int i = 0; i < 10; i++) {
        putchar('0'+i);
    }
    // pre-increment
    putchar('\n');
    for (int i = 0; i < 10; ++i) {
        putchar('0'+i);
    }
    putchar('\n');

    // no difference between them because increment is executed as a standalone statement
    // and it's return value is not used
}