/*
 * Use the character classification functions to prepare an implementation of
 * atoi(); have this version return the value of 0 if the input string is not a
 * pure number.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atoi_canon(char * num)
{
    int res = 0;
    int digits = 1;
    for (int i = strlen(num)-1; i >= 0; i--)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            printf("%s is not a pure number\n", num);
            exit(1);
        }
        res += ((num[i] - '0') * digits);
        digits *= 10;
    }
    return res;
}

int main (void)
{
    char * test1 = "1234";
    int test1_int = atoi_canon(test1);
    printf("%d\n", test1_int);
    char * test2 = "1A";
    int test2_int = atoi_canon(test2);
    return 0;
}
