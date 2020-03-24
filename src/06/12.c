/*
 * Consider these two infinite series:
 *
 * 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
 * 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
 *
 * Write a program that evaluates running totals of these two series up to some
 * limit of number of terms. Hint: –1 times itself an odd number of times is –1,
 * and –1 times itself an even number of times is 1. Have the user enter the
 * limit interactively; let a zero or negative value terminate input. Look at
 * the running totals after 100 terms, 1000 terms, 10,000 terms. Does either
 * series appear to be converging to some value?
 *
 * ANSWER: 
 * - The first series does not converge
 * - The second series converges to ln(2)
 */

#include <stdio.h>
#include <stdlib.h> // for exit()

int main (void)
{
    int limit = 0;
    float sign = 1.0f;
    float series_1 = 0, series_2 = 0;
    printf("Enter an integer limit: ");
    scanf("%d", &limit);
    
    if (limit <= 0)
        exit(0);

    for (int i = 1; i < limit; i++)
    {
        series_1 += 1.0f / i;
        series_2 += 1.0f / i * sign;
        sign *= -1;
    }

    printf("The %dth partial sum of series 1: %f\n", limit, series_1);
    printf("The %dth partial sum of series 2: %f\n", limit, series_2);
    return 0;
}
