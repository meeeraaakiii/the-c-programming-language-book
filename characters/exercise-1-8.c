#include <stdio.h>
#include <stdbool.h>

// count amount of input lines
void main() {
    int c, blancCount, tabCount, newlineCount;

    blancCount = 0;
    tabCount = 0;
    newlineCount = 0;
    bool blankFlag = true;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            // set blank flag to false if line contains anything
            blankFlag = false;
        }
        if (c == '\n') {
            // if blank flag was already true and we have a newline here - line is blank
            if (blankFlag == true)
                ++blancCount;
            // set blank line flag to true so that if next char is \n we could know if line is blank
            blankFlag = true;
            ++newlineCount;
        } else if (c == '\t') {
            ++tabCount;
        }
    }
    printf("blancCount: %d, tabCount: %d newlineCount: %d\n", blancCount, tabCount, newlineCount);
}
