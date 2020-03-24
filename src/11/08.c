/*
 * Write a function called string_in() that takes two string pointers as
 * arguments. If the second string is contained in the first string, have the
 * function return the address at which the contained string begins. For
 * instance, string_in("hats", "at") would return the address of the a in hats.
 * Otherwise, have the function return the null pointer. Test the function in a
 * complete program that uses a loop to provide input values for feeding to the
 * function.
 */

#include <stdio.h>
#include <string.h>
#include "s_gets.c"

#define SIZE 80

/**
 * Checks to see if s2 is contained in s1
 *
 * This is a manual implementation
 */
char * string_in(char * s1, char * s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    int i = 0;
    char * out = NULL;
    while (i < len1)
    {
        if (s1[i] == s2[0])
        {
            int j = 1;
            while (s1[i+j] == s2[j] && j < len2)
                j++;
            if (j == len2)
            {
                out = &s1[i];
                break;
            }
        }
        if (out != NULL)
            break;
        i++;   
    }
    return out;
}

int main (void)
{
    
    char s1[SIZE];
    char s2[SIZE];
    while (1)
    {
        printf("Enter string to search: ");
        s_gets(s1, SIZE);
        if (s1[0] == '\0')
            break;
        printf("Enter substring: ");
        s_gets(s2, SIZE);
        char * res = string_in(s1, s2);
        if (res != NULL)
            printf("Match!\n%s\n", res);
        else
            printf("No match.\n");
    }
    printf("Goodbye\n");
    return 0;
}
