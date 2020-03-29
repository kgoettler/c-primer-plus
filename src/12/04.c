/*
 * Write and test in a loop a function that returns the number of times it has
 * been called.
 */

#include <stdio.h>

int count_calls(void)
{
    static int cnt = 0;
    return ++cnt;
}

int main (void)
{
    int count = 0;
    count = count_calls();
    printf("Number of calls: %d\n", count);
    for (int i = 0; i < 10; i++)
        count = count_calls();
    printf("Number of calls: %d\n", count);
    return 0;
}
