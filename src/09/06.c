/*
 * Write and test a function that takes the addresses of three double variables
 * as arguments and that moves the value of the smallest variable into the first
 * variable, the middle value to the second variable, and the largest value into
 * the third variable.
 */

#include <stdio.h>

void order(double *x, double *y, double *z)
{
    double temp_1;
    do {
        temp_1 = *x;
        if (temp_1 > *y)
        {
            *x = *y;
            *y = temp_1;
        }
        if (*z < *y)
        {
            temp_1 = *y;
            *y = *z;
            *z = temp_1;
        }
    } while (*x > *y || *y > *z);
    
    return;
}

int main (void)
{
    double x = 3.0, y = 2.0, z = 1.0;
    printf("%lf %lf %lf\n", x, y, z);
    order(&x, &y, &z);
    printf("%lf %lf %lf\n", x, y, z);
    return 0;
}
