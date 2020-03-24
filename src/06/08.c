/*
 * Write a program that requests two floating-point numbers and prints the value
 * of their difference divided by their product. Have the program loop through
 * pairs of input values until the user enters nonnumeric input.
 */

#include <stdio.h>

int main (void)
{
    float x, y;
    printf("Enter two floating point numbers: ");
    while (scanf("%f %f", &x, &y) == 2)
    {
        printf("%f\n", (x - y) / (x * y));
    }
    return 0;
}
