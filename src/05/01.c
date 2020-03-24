/*
 * Write a program that converts time in minutes to time in hours and minutes.
 * Use #define or const to create a symbolic constant for 60. Use a while loop
 * to allow the user to enter values repeatedly and terminate the loop if a
 * value for the time of 0 or less is entered.
 */

#include <stdio.h>

const int hr_to_min = 60;

int main (void)
{
    int min = 1;
    while (min > 0)
    {
        printf("Enter a time in minutes (0 to exit): ");
        scanf("%d", &min);
        printf("%d minutes is %d hours, %d minutes\n", min, min / hr_to_min, min % hr_to_min);
    }
    return 0;
}
