/*
 * Write a program that takes two command-line arguments. The first is a string;
 * the second is the name of a file. The program should then search the file,
 * printing all lines containing the string. Because this task is line oriented
 * rather than character oriented, use fgets() instead of getc(). Use the
 * standard C library function strstr() (briefly described in exercise 7 of
 * Chapter 11) to search each line for the string. Assume no lines are longer
 * than 255 characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

int main (int argc, char * argv[])
{
    char * substr;
    char line[MAXLEN];
    FILE * fp;
    if (argc != 3)
    {
        printf("usage: %s string file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("error opening %s for reading\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAXLEN, fp) != NULL)
        if ((substr = strstr(line, argv[1])))
            fputs(line, stdout);
    if (fclose(fp) != 0)
    {
        printf("error closing %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
