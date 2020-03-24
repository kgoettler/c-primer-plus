/*
 * Write a function that takes three arguments: a character and two integers.
 * The character is to be printed. The first integer specifies the number of
 * times that the character is to be printed on a line, and the second integer
 * specifies the number of lines that are to be printed. Write a program that
 * makes use of this function.
 */

#include <stdio.h>

void draw_grid(char c, int n, int nrows);

int main (void)
{
    char c;
    int n, nrows;
    printf("Enter a character, and two integers: \n");
    while (scanf("%c %d %d", &c, &n, &nrows) != 3)
    {
        while (getchar() != '\n')
        {}
        printf("Error reading input.\nEnter a character and two integers: \n");
    }

    draw_grid(c, n, nrows);
    return 0;
}

void draw_grid(char c, int n, int nrows)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    return;
}
