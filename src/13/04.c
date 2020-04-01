/*
 * Write a program that sequentially displays onscreen all the files listed in
 * the command line. Use argc to control a loop.
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    char ch;
    FILE * fp;

    if (argc == 1)
    {
        printf("usage: %s [file1] [file2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Cannot open %s for reading\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        
        if (fclose(fp) != 0)
        {
            printf("Cannot close %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
