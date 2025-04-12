/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/

#include <stdio.h>

int hex_digit_to_int(char c) {
    // if it's a digit, also can use #include <ctype.h> to import int isdigit(int c)
    // return it's integer value by subtracting '0' char value from the char value
    if (c >= '0' && c <= '9') return c - '0';
    // same gooes for a - f but add 10 to it since a stands for 10 and f stands for 15
    else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    // and A - F
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else return -1;
}

int htoi(const char *s) {
    int result = 0, digit;

    // Skip optional 0x or 0X
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
    }

    while (*s) {
        digit = hex_digit_to_int(*s);
        if (digit == -1) break;
        result = result * 16 + digit;
        s++;
    }

    return result;
}

int main() {
    printf("%d\n", htoi("0x1A"));   // 26
    printf("%d\n", htoi("FF"));     // 255
    printf("%d\n", htoi("0XFF"));   // 255
    printf("%d\n", htoi("123"));    // 291
    printf("%d\n", htoi("0x123"));  // 291
    printf("%d\n", htoi("0X123"));  // 291
    printf("%d\n", htoi("0"));      // 0
    return 0;
}