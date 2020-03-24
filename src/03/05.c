/*
 * There are approximately 3.156E7 seconds in a year. Write a program that
 * requests your age in years and then displays the equivalent number of
 * seconds
 */

#include <stdio.h>
#define YEAR_TO_SEC 3.156E7

int main (void)
{
    double age_yrs;
    printf("Enter your age: ");
    scanf("%lf", &age_yrs);
    printf("You have been alive for %f seconds\n", age_yrs * YEAR_TO_SEC);
    return 0;
}
