/*
 * Write a function that takes two int arguments: a value and a bit position.
 * Have the function return 1 if that particular bit position is 1, and have it
 * return 0 otherwise. Test the function in a program.
 */

#include <stdio.h>
#include <stdlib.h>

int n_bit_on(int n, int bitnum);

int main (void)
{
    int n, bitnum;
    printf("%d %d %d %d\n", n_bit_on(15, 0), n_bit_on(15, 1), n_bit_on(15, 2), n_bit_on(15, 3));
    printf("%d\n", n_bit_on(16, 0));
    return 0;
}

int n_bit_on(int n, int bitnum)
{
    if ((n >> bitnum) % 2 == 1)
        return 1;
    return 0;
}
