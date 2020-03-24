/*
 * Write a program that initializes a two-dimensional array-of-double and uses
 * one of the copy functions from exercise 2 to copy it to a second
 * two-dimensional array. (Because a two-dimensional array is an array of
 * arrays, a one-dimensional copy function can be used with each subarray.)
 */

#include <stdio.h>

void copy_ptr(double *target, double *source, int n)
{
    for (int i = 0; i < n; i++)
        *(target + i) = *(source + i);
    return;
}

int main (void)
{
    double src[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
    };
    double dest[3][3];

    for (int i = 0; i < 3; i++)
        copy_ptr(dest[i], src[i], 3);
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%lf\n", dest[i][j]);
    return 0;
}
    

