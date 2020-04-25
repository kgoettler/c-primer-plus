/*
 * Write a function called transform() that takes four arguments: the name of a
 * source array containing type double data, the name of a target array of type
 * double, an int representing the number of array elements, and the name of a
 * function (or, equivalently, a pointer to a function). The transform()
 * function should apply the indicated function to each element in the source
 * array, placing the return value in the target array. For example, the call
 *
 * transform(source, target, 100, sin);
 *
 * would set target[0] to sin(source[0]), and so on, for 100 elements. Test the
 * function in a program that calls transform() four times, using two functions
 * from the math.h library and two suitable functions of your own devising as
 * arguments to successive calls of the transform() function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARR_SIZE 10

double negate (double x)
{
    return (double) -1 * x;
}

double one_minus (double x)
{
    return 1 - x;
}

void transform(double source[], double target[], int n, double (*f) (double))
{
    for (int i = 0; i < n; i++)
        target[i] = (*f)(source[i]);
    return;
}

int main (void)
{
    double source[ARR_SIZE];
    double dest[ARR_SIZE];
    srand(time(0));
    double (*p[4]) (double);
    p[0] = &asin;
    p[1] = &acos;
    p[2] = &negate;
    p[3] = &one_minus;

    for (int i = 0; i < ARR_SIZE; i++)
        source[i] = (double) rand() / (double) RAND_MAX;
    for (int i = 0; i < 4; i++)
    {
        transform(source, dest, ARR_SIZE, p[i]);
        for (int j = 0; j < ARR_SIZE; j++)
            printf("f%d(%lf) = %lf\n", i+1, source[j], dest[j]);
    }
    return 0;
}
