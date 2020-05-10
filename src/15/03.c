/*
 * Write a function that takes an int argument and returns the number of "on"
 * bits in the argument. Test the function in a program.
 */

#include <stdio.h>
#include <stdlib.h>

int onbits(int n);

int main (void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;
    printf("On bits in %d: %d\n", n, onbits(n));
    return 0;
}

int onbits(int n)
{
    int cnt;
    while (n != 0)
    {
        if (n % 2 == 1)
            cnt += 1;
        n = n >> 1;
    }
    return cnt;
}
