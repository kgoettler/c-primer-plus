/*
 * Write a program that prints a table with each line giving an integer, its
 * square, and its cube. Ask the user to input the lower and upper limits for
 * the table. Use a for loop.
 */

#include <stdio.h>

int main (void)
{
    int min, max;
    printf("Enter lower limit: ");
    scanf("%d", &min);
    printf("Enter upper limit: ");
    scanf("%d", &max);

    for (int i = min; i <= max; i++)
    {
        printf("%-5d %-5d %-5d\n", i, i*i, i*i*i);
    }
    return 0;
}
