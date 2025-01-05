#include <stdio.h>

void main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8; // lower limit of the temperature scale
    upper = 150; // upper limit
    step = 5; // step size

    celsius = lower;

    printf("     C    F\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%6.1f\t%3.0f\n", celsius, fahr);
        celsius = celsius + step; 
    }
}