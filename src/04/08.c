/*
 * Write a program that asks the user to enter the number of miles traveled and
 * the number of gallons of gasoline consumed. It should then calculate and
 * display the miles-per-gallon value, showing one place to the right of the
 * decimal. Next, using the fact that one gallon is about 3.785 liters and one
 * mile is about 1.609 kilometers, it should convert the mile- per-gallon value
 * to a liters-per-100-km value, the usual European way of expressing fuel
 * consumption, and display the result, showing one place to the right of the
 * decimal. Note that the U. S. scheme measures the distance traveled per amount
 * of fuel (higher is better), whereas the European scheme measures the amount
 * of fuel per distance (lower is better). Use symbolic constants (using const
 * or #define) for the two conversion factors.
 */

#include <stdio.h>

#define MI_TO_KM 1.609
#define GAL_TO_L 3.785

int main (void)
{
    float miles, gallons;
    float mpg, lpkm;
    printf("Enter the number of miles driven: ");
    scanf("%f", &miles);
    printf("Enter the number of gallons of gasoline consumed: ");
    scanf("%f", &gallons);

    mpg = miles / gallons;
    lpkm = (gallons * GAL_TO_L) / (miles * MI_TO_KM) * 100;
    printf("Fuel efficiency: %.3f mpg (%.3f L/100km)\n", mpg, lpkm);
    return 0;
}

