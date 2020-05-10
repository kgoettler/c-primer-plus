/*
 * Write a function that converts a binary string to a numeric value. That is,
 * if you have:
 *
 * char * pbin = "01001001";
 *
 * you can pass pbin as an argument to the function and have the function return
 * an int of value 25.
 */

#include <stdio.h>
#include <string.h>

int power(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int bin_to_int(char * str)
{
    int res;
    int len;
    len = strlen(str);
    res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            res += power(2, (len - 1) - i);
        }
    }
    return res;
}


int main (void)
{
    char inp[128];
    int out;
    printf("Input binary number: ");
    scanf("%s", inp);
    while (getchar() != '\n')
        continue;
    out = bin_to_int(inp);
    printf("%s in base 10: %d\n", inp, out);
    return 0;
}
