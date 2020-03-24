/*
 * Write and test a function called larger_of() that replaces the contents of
 * two double variables with the maximum of the two values. For example,
 * larger_of(x,y) would reset both x and y to the larger of the two.
 */

#include <stdio.h>

void larger_of(double *x, double *y)
{
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}

int main (void)
{
    double x = 2.0, y = 4.0;
    printf("x = %lf, y = %lf\n", x, y);
    larger_of(&x, &y);
    printf("x = %lf, y = %lf\n", x, y);
    return 0;
}
