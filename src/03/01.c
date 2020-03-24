/*
 * Find out what your system does with integer overflow, floating-point 
 * overflow, and floating-point underflow by using the experimental approach;
 * that is, write programs having these problems. (You can check the discussion
 * in Chapter 4 of limits.h and float.h to get guidance on the largest and 
 * smallest values.)
 * TODO: Fix
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (void)
{
    float float_over = FLT_MAX;
    float float_under = -FLT_MAX;
    int int_over = INT_MAX;
    
    printf("int = %d\n", int_over+1);
    printf("long (over) = %f\n", float_over+1);
    printf("long (under) = %f\n", float_under-1);
    return 0;
}
