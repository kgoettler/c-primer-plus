/*
 * Use nested loops to produce the following pattern:
 *
 * $
 * $$
 * $$$
 * $$$$
 * $$$$$
 */

#include <stdio.h>

int main (void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%s", "$");
        printf("\n");
    }
    return 0;
}
