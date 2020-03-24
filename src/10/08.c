/*
 * Use a copy function from Exerise 2 to copy the third through fifth elements
 * of a seven-element array into a three-element array. The function itself need
 * not be altered; just choose the right actual arguments. (The actual arguments
 * need not be an array name and array size. They only  have to be the adderss
 * of an array element and a number of elements to process
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
    double src[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double dest[3];
    copy_ptr(dest, &src[2], 3);
    for (int i = 0; i < 3; i++)
        printf("%lf\n", dest[i]);
    return 0;
}
