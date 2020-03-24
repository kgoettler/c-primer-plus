/*
 * Design and test a function like that described in Programming Exercise 3
 * except that it accepts a second parameter specifying the maximum number of
 * characters that can be read.
 */

#include <stdio.h>

#include <stdio.h>
#include <ctype.h>

void read_word(char arr[], int size)
{
    char ch; 
    int i = 0;
    // Skip leading whitespace
    while ((ch = getchar()) != EOF && isspace(ch))
        continue;
    if (ch == EOF)
        return;
    // Copy string
    do
    {
        arr[i++] = ch;
    } while ((ch = getchar()) != EOF && !isspace(ch) && i < size-1);
    arr[i] = '\0';
}

int main (void)
{
    int size = 80;
    char word[size];
    read_word(word, size);
    printf("%s\n", word);
    return 0;
}

