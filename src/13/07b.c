/*
 * Write a program that opens two files. You can obtain the filenames either by
 * using command-line arguments or by soliciting the user to enter them
 *
 * b. Modify the program so that lines with the same line number are printed on
 * the same line
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
    char ch;
    FILE * f1, * f2;
    FILE ** fp;
    
    if (argc != 3)
    {
        printf("usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("error opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(argv[2], "r")) == NULL)
    {
        printf("error opening %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    fp = &f1;
    while (feof(*fp) == 0)
    {
        while ((ch = getc(*fp)) != EOF && ch != '\n')
            fputc(ch, stdout);
        // Switch pointer if other is not at EOF
        if (*fp == f1 && feof(f2) == 0)
        {
            fp = &f2;
        }
        else if (*fp == f2 && feof(f1) == 0)
        {
            fp = &f1;
            fputc('\n', stdout);
        }
    }
    fputc('\n', stdout);
    return 0;
}
