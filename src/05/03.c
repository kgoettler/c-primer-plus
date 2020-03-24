/*
 * Write a program that asks the user to enter the number of days and then
 * converts that value to weeks and days. For example, it would convert 18 days
 * to 2 weeks, 4 days. Display results in the following format:
 *
 * 18 days are 2 weeks, 4 days.
 *
 * Use a while loop to allow the user to repeatedly enter day values; terminate
 * the loop when the user enters a nonpositive value, such as 0 or -20.
 */

#include <stdio.h>

#define DAYS_TO_WEEKS 7

int main (void)
{
    int days = 1;
    int weeks, rem_days;
    while (days > 0)
    {
        printf("Input a number of days: ");
        scanf("%d", &days);
        weeks = days / DAYS_TO_WEEKS;
        rem_days = days - (weeks * DAYS_TO_WEEKS);
        printf("%d days is %d weeks, %d days\n", days, weeks, rem_days);
    }
    return 0;
}
