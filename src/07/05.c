/*
 * Redo Exercise 4 using a switch
 */

#include <stdio.h>

int main (void)
{
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.' :
                putchar('!');
                cnt++;
                break;
            case '!':
                putchar('!');
                putchar('!');
                cnt++;
                break;
            default:
                putchar(ch);
        }
    }
    printf("\n");
    printf("Number of substitutions: %d\n", cnt);
    return 0;
}
