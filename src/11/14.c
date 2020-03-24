/*
 * Write a power-law program that works on a command-line basis. The first
 * command-line argument should be the type double number to be raised to a
 * certain power, and the second argument should be the integer power.
 */

#include <stdio.h>
#include <stdlib.h>

double power(double x, int y)
{
    double res = 1;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}

int main (int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: power x y\n");
        return 1;
    }
    double x = atof(argv[1]);
    int y = atoi(argv[2]);
    double res = power(x, y);
    printf("%lf ^ %d = %lf\n", x, y, res);
    return 0;
}
