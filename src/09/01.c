/*
 * Devise a function called min(x,y) that returns the smaller of two double
 * values. Test the function with a simple driver.
 */

#include <stdio.h>

double min (double x, double y)
{
    if (x > y)
        return y;
    return x;
}

int main (void)
{
    double x, y;
    printf("Enter two doubles: ");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        while (getchar() != '\n')
        {}
        printf("Error reading values\nEnter two doubles: ");
    }
    printf("%lf is smaller\n", min(x,y));
    return 0;
}
