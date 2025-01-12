#include <stdio.h>

float convertToFahr(float celsius);

void main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8; // lower limit of the temperature scale
    upper = 150; // upper limit
    step = 5; // step size

    celsius = lower;

    printf("     C    F\n");
    while (celsius <= upper) {
        fahr = convertToFahr(celsius);
        printf("%6.1f\t%3.0f\n", celsius, fahr);
        celsius = celsius + step; 
    }
}

float convertToFahr(float celsius) {
    return (9.0/5.0) * celsius + 32;
}
