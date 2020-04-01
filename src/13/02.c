/*
 * Write a file-copy program that takes the original filename and the copy file
 * from the command line. Use standard I/O and the binary mode, if possible.
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    int ch;
    FILE *inp;
    FILE *out;

    if (argc != 3)
    {
        printf("usage: %s input output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((inp = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen(argv[2], "w")) == NULL)
    {
        printf("Error opening %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    while ((ch = getc(inp)) != EOF)
        putc(ch, out);

    fclose(inp);
    fclose(out);
    return 0;
}
