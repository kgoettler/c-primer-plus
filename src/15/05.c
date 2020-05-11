/*
 * Write a function that rotates the bits of an unsigned int by a specified
 * number of bits to the left. For instance, rotate_1(x,4) would move the bits
 * in x four places to the left, and the bits lost from the left end would
 * reappear at the right end. That is, the bit moved out of the high-order
 * position is placed in the low-order position. Test the function in a program
 */

#include <stdio.h>
#include <limits.h>

char * itobs(int n, char * ps);
unsigned int rotate_1(unsigned int n, unsigned int nbits);

int main (void)
{
    unsigned int input, output;
    char bs[128];
    input = 223;
    printf("%s (%d)\n", itobs(input, bs), input);
    printf("%s\n", itobs(rotate_1(input, (unsigned int) 28), bs));
    return 0;
}

unsigned int rotate_1(unsigned int n, unsigned int nbits)
{
    unsigned int out;
    const static int size = CHAR_BIT * sizeof(int);
    nbits = nbits % size;
    out = (n << nbits) | (n >> (size - nbits));
    return out;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
    ps[size] = '\0';

    return ps;
}
