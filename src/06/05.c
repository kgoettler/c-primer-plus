/*
 * Have a program request the user to enter an uppercase letter. Use nested
 * loops to produce a pyramid pattern like this:
 *
 *     A 
 *    ABA 
 *   ABCBA 
 *  ABCDCBA 
 * ABCDEDCBA
 *
 * The pattern should extend to the character entered. For example, the
 * preceding pattern would result from an input value of E. Hint: Use an outer
 * loop to handle the rows. Use three inner loops in a row, one to handle the
 * spaces, one for printing letters in ascending order, and one for printing
 * letters in descending order. If your system doesn’t use ASCII or a similar
 * system that represents letters in strict number order, see the suggestion in
 * programming exercise 3.
 */

#include <stdio.h>

int main (void)
{
    char c;
    printf("Enter an uppercase character: ");
    scanf("%c", &c);

    for (char i = 'A'; i <= c; i++)
    {
        for (char j = c; j > i; j--)
        {
            printf(" ");
        }
        for (char j = 'A'; j <= i; j++)
        {
            printf("%c", j);
        }
        for (char j = i-1; j >= 'A'; j--)
        {
            printf("%c", j);
        }
        for (char j = c; j > i; j--)
        {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
