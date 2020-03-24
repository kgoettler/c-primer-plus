/*
 * Write a function that returns the difference between the largest and smallest
 * elements of an array-of-double. Test the function in a simple program
 */

#include <stdio.h>

double range(double *arr, int n)
{
    double min = *arr, max = *arr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    return max - min;
}

int main (void)
{
    double test[5] = {100, 200, 10000, 500, 300};
    printf("%lf\n", range(test, 5));
    return 0;
}
