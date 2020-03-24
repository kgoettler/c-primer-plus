/*
 * Design and test a function that searches the string specified by the first
 * function parameter for the first occurrence of a character specified by the
 * second function parameter. Have the function return a pointer to the
 * character if successful, and a null if the character is not found in the
 * string. (This duplicates the way that the library strchr() function works.)
 * Test the function in a complete program that uses a loop to provide input
 * values for feeding to the function.
 */

#include <stdio.h>
#include <string.h>

char * strchr1(char * word, char ch)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
            return &s[i];
    }
    return NULL;
}

int main(void)
{

    return 0;
}
