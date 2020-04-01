/*
 * Write a program that takes as command-line arguments a character and zero or
 * more filenames. If no arguments follow the character, have the program read
 * the standard input. Otherwise, have it open each file in turn and report how
 * many times the character appears in each file. The filename and the character
 * itself should be reported along with the count. Include error-checking to see
 * whether the number of arguments is correct and whether the files can be
 * opened. If a file can’t be opened, have the program report that fact and go
 * on to the next file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_char(FILE * fp, char sch)
{
    char ch;
    int count = 0;
    while((ch = getc(fp)) != EOF)
        if (ch == sch)
            count++;
    return count;
}

int main (int argc, char * argv[])
{
    FILE * fp;
    int count;
    if (argc < 2)
    {
        printf("usage: %s char [input1] [input2] ... \n", argv[0]);
        exit(EXIT_FAILURE);
    } 
    else if (argc == 2)
    {
        count = count_char(stdin, *argv[1]);
        printf("Count from STDIN: %d\n", count);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                printf("error opening %s for reading\n", argv[i]);
                continue;
            }
            count = count_char(fp, *argv[1]);
            printf("Count from %s: %d\n", argv[i], count);
            if ((fclose(fp)) != 0)
                printf("error closing %s\n", argv[i]);
        }
    }
    return 0;
}
