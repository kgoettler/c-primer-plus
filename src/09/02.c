/*
 * Devise a function chlin(ch, i ,j) that prints the requested character in
 * columns i through j. Test it in a simple driver
 */

#include <stdio.h>

void chline(char ch, int i, int j);

int main (void)
{
    char ch;
    int i, j;

    printf("Enter a character, and two integers: \n");
    while (scanf("%c %d %d", &ch, &i, &j) != 3)
    {
        while (getchar() != '\n')
        {}
        printf("Error reading input.\nEnter a character and two integers: \n");
    }
    chline(ch, i, j);
    return 0;
}

void chline (char c, int i, int j)
{
    int k;
    for (k = 0; k < i; k++)
        printf(" ");
    for (k = i; k <= j; k++)
        printf("%c", c);
    return;
}
