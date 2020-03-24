/*
 * Write a program that converts your age in years to days and displays both
 * values. At this point, don't worry about fractional years and leap years
 */

#include <stdio.h>

#define AGE 26

int main (void)
{
    int age_days = AGE * 365;
    printf("Age in years: %d\n", AGE);
    printf("Age in days:  %d\n", age_days);
    return 0;
}
