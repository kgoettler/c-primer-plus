/*
 * Write a program that opens a text file whose name is obtained interactively.
 * Set up a loop that asks the user to enter a file position. The program then
 * should print the part of the file starting at that position and proceed to
 * the next newline character. Let negative or nonnumeric input terminate the
 * user-input loop.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    FILE * fp;
    char fname[1024];
    char ch;
    long int pos;

    printf("Enter a filename: ");
    scanf("%s", fname);
    while (getchar() != '\n')
        continue;
    
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Error opening %s for reading\n", fname);
        exit(EXIT_FAILURE);
    }

    printf("Enter a file position: ");
    if (scanf("%ld", &pos) != 1 || pos < 0)
    {
        printf("Done\n");
        return 0;
    }
    fseek(fp, pos, SEEK_SET);
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);
    return 0;
}
