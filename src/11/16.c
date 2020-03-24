/*
 * Write a program that reads input until end-of-file and echoes it to the
 * display. Have the program recognize and implement the following command-line
 * arguments:
 *
 * -p    Print input as is
 * -u    Map input to all uppercase
 * -l    Map input to all lowercase
 *
 * Also, if there are no command-line arguments, let the program behave as if
 * the -p argument had been used.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
    return;
}

void ToLower(char * str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
    return;
}

int main (int argc, char * argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-p") && strcmp(argv[1], "-l") && strcmp(argv[1], "-u"))
        {
            printf("usage: 16.o [-p|-l|-u] input\n");
            exit(1);
        }
    }

    char inp[1024];
    char ch;
    int i = 0;
    while ((ch = getchar()) != EOF && i < 1024)
    {
        inp[i] = ch;
        i++;
    }
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-p") == 0))
    {
        printf("%s\n", inp);
    }
    else if (strcmp(argv[1], "-u") == 0)
    {
        ToUpper(inp);
        printf("%s\n", inp);
    }
    else if (strcmp(argv[1], "-l") == 0)
    {
        ToLower(inp);
        printf("%s\n", inp);
    }
    return 0;
}
