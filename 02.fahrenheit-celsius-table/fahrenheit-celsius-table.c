#include <stdio.h>

// print Fahrenheit-Celsius table
// 0, 10, ..., 300

void main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; // lower limit of the temperature scale
    upper = 300; // upper limit
    step = 10; // step size

    fahr = lower;

    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
