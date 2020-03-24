/*
 * Using if else statements, write a program that reads input up to #, replaces
 * each period with an exclamation mark, replaces each exclamation mark
 * initially present with two exclamation marks, and reports at the end the
 * number of substitutions it has made.
 */

#include <stdio.h>

int main (void)
{
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            cnt++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            cnt++;
        }
        else
        {
            putchar(ch);
        }
    }
    printf("\n");
    printf("Number of substitutions: %d\n", cnt);
    return 0;
}
