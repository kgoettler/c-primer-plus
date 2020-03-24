/*
 * Write a program that accepts a positive integer as input and then displays
 * all the prime numbers smaller than or equal to that number.
 */

#include <stdio.h>

int isprime(int i)
{
    for (int j = 2; j * j <= i; j++)
    {
        if (i % j == 0)
            return 0;
    }
    return 1;
}

int main (void)
{
    unsigned int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Primes <= %d: \n", num);
    for (int i = 2; i < num; i++)
    {
        if (isprime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
