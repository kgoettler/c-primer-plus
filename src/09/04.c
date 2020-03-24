/*
 * The harmonic mean of two numbers is obtained by taking the inverses of the
 * two numbers, averaging them, and taking the inverse of the result. Write a
 * function that takes two double arguments and returns the harmonic mean of the
 * two numbers.
 */

#include <stdio.h>

double harmonic_mean(double x, double y);

int main (void)
{
    double x, y;
    char msg[] = "Enter two doubles: \n";
    printf("%s", msg);
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        while (getchar() != '\n')
        {}
        printf("Error reading input.\n%s", msg);
    }
    printf("Harmonic mean of %lf and %lf: %lf\n", x, y, harmonic_mean(x,y));
    return 0;
}

double harmonic_mean(double x, double y)
{
    double hmean = 1 / (((1 / x) + (1 / y)) / 2);
    return hmean;
}
