/*
 * Write a function that reverses the contents of an array of double and test it
 * in a simple program.
 */

#include <stdio.h>

void reverse_array(double *arr, int n)
{
    double tmp;
    for (int i = 0, ni = n-1; i <= ni; i++, ni--)
    {
        tmp = arr[ni];
        arr[ni] = arr[i];
        arr[i] = tmp;
    }
    return;
}

int main (void)
{
    double test[5] = {100, 200, 10000, 500, 300};
    for (int i = 0; i < 5; i++)
        printf(" %lf ", test[i]);
    printf("\n");
    reverse_array(test, 5);
    for (int i = 0; i < 5; i++)
        printf(" %lf ", test[i]);
    printf("\n");
    return 0;
}
