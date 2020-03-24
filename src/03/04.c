/*
 * Write a program that reads in a floating-point number and prints it first 
 * in decimal-point notation, then in exponential notation, and then, if your 
 * system supports it, p notation. Have the output use the following format 
 * (the actual number of digits displayed for the exponent depends on the 
 * system):
 */

#include <stdio.h>

int main (void)
{
    float f;
    printf("Enter a floating-point value: ");
    scanf("%f", &f);
    printf("fixed-point notation: %f\n", f);
    printf("exponential notation: %e\n", f);
    printf("p notation: %a\n", f);
    return 0;
}

