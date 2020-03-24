/*
 * Modify exercise 8 so that is uses a function to return the value of the
 * calcuation 
 *
 */

#include <stdio.h>

float calc (float x, float y)
{
    return (x - y) / (x * y);
}

int main (void)
{
    float x, y, res;
    printf("Enter two floating point numbers: ");
    while (scanf("%f %f", &x, &y) == 2)
    {
        res = calc(x, y);
        printf("%f\n", res);
    }
    return 0;
}
