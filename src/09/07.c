/*
 * Write a program that reads characters from the standard input to end-of-file.
 * For each character, have the program report whether it is a letter. If it is
 * a letter, also report its numerical location in the alphabet. For example, c
 * and C would both be letter 3. Incorporate a function that takes a character
 * as an argument and returns the numerical location if the character is a
 * letter and that returns –1 otherwise.
 */

#include <stdio.h>

// 65 A
// 97 a

int alpha_loc(char ch)
{
    if (65 <= ch && ch < 91)
        return ch - 64;
    else if (97 <= ch && ch < 123)
        return ch - 96;
    else
        return -1;
}

int main (void)
{
    char ch;
    int loc;
    while ((ch = getchar()) != EOF)
    {
        printf("%c", ch);
        loc = alpha_loc(ch);
        if (loc > -1)
            printf(" | %d", loc);
        printf("\n");
    }
    return 0;
}
