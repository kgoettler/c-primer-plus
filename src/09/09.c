/*
 * Redo Programming Exercise 8, but this time use a recursive function
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
            res *= ((1/base) * power(base, pow+1));
        }
        else if (pow > 0)
        {
            res *= (base * power(base, pow-1));
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
