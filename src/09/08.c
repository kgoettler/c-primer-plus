/*
 * Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
 * function that returned the result of raising a type double number to a
 * positive integer value. Improve the function so that it correctly handles
 * negative powers. Also, build into the function that 0 to any power other than
 * 0 is 0 and that any number to the 0 power is 1. (It should report that 0 to
 * the 0 is undefined, then say it’s using a value of 1.) Use a loop. Test the
 * function in a program.
 */

#include <stdio.h>

double power(double base, int pow)
{
    double res = 0;
    if (base == 0)
    {
        if (pow == 0)
        {
            printf("Warning: 0 ** 0 is undefined. Using 1.\n");
            res = 1;
        }
    }
    else
    {
        res = 1;
        if (pow < 0)
        {
            for (int i = 0; i > pow; i--)
                res *= base;
            res = 1 / res;
        }
        else
        {
            for (int i = 0; i < pow; i++)
                res *= base;
        }
    }
    return res;
}

int main (void)
{
    double bases[5] = {2, 2, 2, 0, 0};
    int powers[5] = {3, 8, -4, 1, 0};
    printf("Testing power function\n");
    for (int i = 0; i < 5; i++)
        printf("%.0lf ^ %d = %lf\n", bases[i], powers[i], power(bases[i], powers[i]));
    return 0;
}
