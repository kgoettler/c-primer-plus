/*
 * Write a program that reads two binary strings as command-line arguments and
 * prints the results of applying the ~ operator to each number and the results
 * of applying the &, |, and ^ operators to the pair. Show the results as binary
 * strings. (If you don't have a command-line environment available, have the
 * program read the strings interactively.)
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128

int power(int a, int b);
int bstoi(char * str);
char * itobs(int n, char * ps);
void print_results(int num1, int num2);

int main (int argc, char **argv)
{
    char s1[MAXLEN], s2[MAXLEN];
    int num1, num2;
    if (argc != 3)
    {
        puts("usage: %s binnum binnum\n");
        exit(1);
    }
    num1 = bstoi(argv[1]);
    num2 = bstoi(argv[2]);
    itobs(num1, s1);
    itobs(num2, s2);
    print_results(num1, num2);
    
    return 0;
}

void print_results(int num1, int num2)
{
    char buf[MAXLEN];
    printf("A: %s\n", itobs(num1, buf));
    printf("B: %s\n", itobs(num2, buf));
    printf("~A: %s\n", itobs(~num1, buf));
    printf("~B: %s\n", itobs(~num2, buf));
    printf("A & B: %s\n", itobs(num1 & num2, buf));
    printf("A | B: %s\n", itobs(num1 | num2, buf));
    printf("A ^ B: %s\n", itobs(num1 ^ num2, buf));
    return;
}

int power(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int bstoi(char * str)
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

char * itobs(int n, char * ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
    ps[size] = '\0';

    return ps;
}
