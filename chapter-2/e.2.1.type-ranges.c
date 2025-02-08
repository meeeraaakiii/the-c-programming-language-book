// Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from standard headers
// and by direct computation. Harder if you compute them: determine the ranges of the various
// floating-point types.

#include <stdio.h>
#include <limits.h>

void determineTypesRanges() {
    // unsigned
    unsigned short uc = 0;
    printf("unsigned short: 0 - %u\n", --uc);
    unsigned short us = 0;
    printf("unsigned short: 0 - %u\n", --us);
    unsigned int ui = 0;
    printf("unsigned int: 0 - %u\n", --ui);
    unsigned long long ul = 0;
    printf("unsigned long: 0 - %llu\n", --ul);

    // signed
    signed short scMax = uc/2;
    signed short scMin = uc/2 + 1;
    printf("signed short: %d - %d\n", scMin, scMax);
    signed short ssMax = us/2;
    signed short ssMin = us/2 + 1;
    printf("signed short: %d - %d\n", ssMin, ssMax);
    signed int siMax = ui/2;
    signed int siMin = ui/2 + 1;
    printf("signed int: %d - %d\n", siMin, siMax);
    signed long long slMax = ul/2;
    signed long long slMin = ul/2 + 1;
    printf("signed long: %lld - %lld\n", slMin, slMax);
    // reading memory
    printf("signed long: %lld - %lld - %lld - %lld - %lld\n", slMin, slMax);
    printf("signed long: %lld - %lld - %lld - %lld - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x - %02x \n", slMin, slMax);
}

int main() {
    determineTypesRanges();

    return 0;
}
