/*
 * Write a program that reads a single word into a character array and then
 * prints the word backward. Hint: Use strlen() (Chapter 4) to compute the index
 * of the last character in the array.
 */

#include <stdio.h>
#include <string.h>

int main (void)
{
    char str[40];
    printf("Enter a string: ");
    scanf("%s", str);
    size_t len = strlen(str);
    for (int i = len-1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

