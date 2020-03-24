/*
 * Write a program that reads input up to EOF and reports the number of words,
 * the number of uppercase letters, the number of lowercase letters, the number
 * of punctuation characters, and the number of digits. Use the ctype.h family
 * of functions.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "s_gets.c"

int main (void)
{
    int i, n_upper, n_lower, n_punct, n_digits = 0;
    char str[1024];
    char ch;
    while ((ch = getchar()) != EOF && i < 1024)
        str[i++] = ch;
    i = 0;
    while (str[i] != '\0')
    {
        if (isupper(str[i]))
            n_upper++;
        else if (islower(str[i]))
            n_lower++;
        else if (ispunct(str[i]))
            n_punct++;
        else if (isdigit(str[i]))
            n_digits++;
        i++;
    }
    printf("\n");
    printf("Uppercase characters:   %d\n", n_upper);
    printf("Lowercase characters:   %d\n", n_lower);
    printf("Punctuation characters: %d\n", n_punct);
    printf("Digits:                 %d\n", n_digits);
    return 0;
}

