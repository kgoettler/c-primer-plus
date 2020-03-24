/*
 * Write a program that reads input until encountering the # character and then
 * reports the number of spaces read, the number of newline characters read, and
 * the number of all other characters read
 */

#include <stdio.h>

int main (void)
{
    char c;
    unsigned int spaces = 0, newlines = 0, other = 0;
    while ((c = getchar()) != '#')
    {
        if (c == ' ')
            spaces++;
        else if (c == '\n')
            newlines++;
        else
            other++;
    }
    printf("Read %d spaces, %d newlines, %d other characters\n", spaces, newlines, other);
    return 0;
}
