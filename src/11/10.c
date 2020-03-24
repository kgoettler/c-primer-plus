/*
 * Write a function that takes a string as an argument and removes the spaces
 * from the string. Test it in a program that uses a loop to read lines until
 * you enter an empty line. The program should apply the function to each input
 * string and display the result.
 */

#include <stdio.h>
#include <string.h>
#include "s_gets.c"

void remove_spaces(char * str)
{
    int i = 0, idx = 0;
    size_t len = strlen(str);
    while (i < len)
        if (str[i] == ' ')
            i++;
        else
            str[idx++] = str[i++];
    while (idx < len)
        str[idx++] = '\0';
    return;
}

int main (void)
{
    char str[1024];
    char ch;

    // Grab first character
    str[0] = getchar();
    if (str[0] == '\n' || str[0] == '\0')
        return 0;
    
    // Now grab additional characters
    int i = 1;
    while ((ch = getchar()) != EOF)
    {
        str[i] = ch;
        if(ch == '\n' && str[i - 1] == '\n')
            break;
        i++;
    }
    printf("%s", str);
    remove_spaces(str);
    printf("%s", str);
    return 0;
}
