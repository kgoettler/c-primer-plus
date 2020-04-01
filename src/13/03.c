/*
 * Write a file copy program that prompts the user to enter the name of a text
 * file to act as the source file, and the name of an output file. The program
 * should use the toupper() function from ctype.h to convert all text to
 * uppercase as it's written to the output file. Use standard I/O and the text
 * mode.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char * argv[])
{
    char ch;
    char in_file[1024];
    char out_file[1024];
    FILE * inp;
    FILE * out;
    if (argc != 1)
    {
        printf("usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("Enter the input file: ");
    scanf("%s", in_file);
    while ((ch = getchar()) != '\n')
        continue;
    printf("Enter the out file: ");
    scanf("%s", out_file);
    while ((ch = getchar()) != '\n')
        continue;
    if ((inp = fopen(in_file, "r")) == NULL)
    {
        printf("Error opening %s for reading\n", in_file);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen(out_file, "w")) == NULL)
    {
        printf("Error opening %s for writing\n", out_file);
        exit(EXIT_FAILURE);
    }
    
    while ((ch = getc(inp)) != EOF)
        putc(toupper(ch), out);

    fclose(inp);
    fclose(out);
    return 0;
}
