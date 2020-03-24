/*
 * Write and test a Fibonacci() function that uses a loop instead of recursion
 * to calculate Fibonacci numbers.
 */

#include <stdio.h>

unsigned long Fibonacci(unsigned x)
{
    unsigned long a = 1, b = 1, tot;
    if (x <= 2)
    {
        return a;
    }
    else
    {
        for (int i = 3; i <= x; i++)
        {
            tot = a + b;
            a = b;
            b = tot;
        }
        return tot;
    }
}

// To check
unsigned long Fibonacci_r(unsigned x)
{
    if (x > 2)
        return Fibonacci_r(x - 1) + Fibonacci_r(x - 2);
    else
        return 1;
}

int main (void)
{
    for (unsigned i = 1; i < 10; i++)
        printf("%u: %lu %lu\n", i, Fibonacci_r(i), Fibonacci(i));
    return 0;
}
