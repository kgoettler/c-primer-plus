/*
 * Design and test a function that reads the first word from a line of input
 * into an array and discards the rest of the line. It should skip over leading
 * whitespace. Define a word as a sequence of characters with no blanks, tabs,
 * or newlines in it. Use getchar().
 */

#include <stdio.h>
#include <ctype.h>

#define SIZE 80

void read_word(char arr[])
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
    } while ((ch = getchar()) != EOF && !isspace(ch) && i < SIZE-1);

}

int main (void)
{
    char word[SIZE];
    read_word(word);
    printf("%s\n", word);
    return 0;
}
