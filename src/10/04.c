/*
 * Write a function that returns the largest value stored in an array-of-double
 * Test the function in a simple program
 */

#include <stdio.h>

double max(double *arr, int n)
{
    double max = *arr;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main (void)
{
    double test[5] = {100, 200, 10000, 500, 300};
    printf("%lf\n", max(test, 5));
    return 0;
}
