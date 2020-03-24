/*
 * Chuckie Lucky won a million dollars (after taxes), which he places in an
 * account that earns 8% a year. On the last day of each year, Chuckie withdraws
 * $100,000. Write a program that finds out how many years it takes for Chuckie
 * to empty his account.
 */

#include <stdio.h>

int main (void)
{
    float chuckie_bal = 1000000;
    float chuckie_r = 0.08;
    int years = 0;
    while (chuckie_bal > 0)
    {
        chuckie_bal *= (1.0 + chuckie_r);
        chuckie_bal -= 100000;
        years++;
    }
    printf("After %d years, Chuckie's account is empty.\n", years);
    return 0;
}
