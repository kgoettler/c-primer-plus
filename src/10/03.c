/*
 * Write a function that returns the largest value stored in an array-of-int.
 * Test the function in a simple program
 */

#include <stdio.h>

int max(int *arr, int n)
{
    int max = *arr;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main (void)
{
    int test[5] = {100, 200, 10000, 500, 300};
    printf("%d\n", max(test, 5));
    return 0;
}
