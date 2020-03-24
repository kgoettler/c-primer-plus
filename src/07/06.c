/*
 * Write a program that reads input up to # and reports the number of times that
 * the sequence ei occurs.
 */

#include <stdio.h>

int main (void)
{
    char ch;
    int flag = 0, cnt = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == 'e')
        {
            flag = 1;
        }
        else if (ch == 'i' && flag == 1)
        {
            cnt++;
            flag = 0;
        }
        else 
        {
            flag = 0;
        }
    }
    printf("Pattern \'ei\' encountered %d times\n", cnt);
    return 0;
}
