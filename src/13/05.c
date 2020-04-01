/*
 * Modify the program in Listing 13.5 so that it uses a command-line interface
 * instead of an interactive interface.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE * source, FILE * dest);

int main (int argc, char * argv[])
{
    FILE *fa, *fs;
    int files = 0;
    int ch;

    if (argc == 1)
    {
        printf("usage: %s input1 [input2] ... output\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((fa = fopen(argv[argc-1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[argc-1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 1; i < argc-1; i++)
    {
        if (strcmp(argv[i], argv[argc-1]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[argc-1]);
            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[i]);
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[argc-1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append (FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}
