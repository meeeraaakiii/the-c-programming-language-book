#include <stdio.h>

// print Fahrenheit-Celsius table
// 0, 10, ..., 300

void main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0; // lower limit of the temperature scale
    upper = 300; // upper limit
    step = 10; // step size

    fahr = lower;

    printf("Celsius  Fahrenheit\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
