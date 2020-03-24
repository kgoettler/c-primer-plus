/*
 * Write a function that replaces the contents of a string with the string
 * reversed. Test the function in a complete program that uses a loop to provide
 * input values for feeding to the function.
 */

#include <stdio.h>
#include <string.h>
#include "s_gets.c"

void reverse_string(char * str)
{
    char buf;
    size_t len = strlen(str);
     
    for (int i = 0; i < len / 2; i++)
    {
        buf = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = buf;
    }
    return;
}

int main (void)
{
    char input[1024];
    while (1)
    {
        printf("Enter a string to reverse: ");
        s_gets(input, 1024);
        if (input[0] == '\0')
            break;
        reverse_string(input);
        printf("%s\n", input);
    }
    printf("Goodbye\n");
    return 0;
}
