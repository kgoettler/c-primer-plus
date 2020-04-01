/*
 * Programs using command-line arguments rely on the user's memory of how to use
 * them correctly. Rewrite the program in Listing 13.2 so that, instead of using
 * command-line arguments, it prompts the user for the required information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024

int main (void)
{

    FILE * in, * out;
    int ch;
    char in_file[LEN], out_file[LEN];
    int count = 0;

    printf("Enter input file: ");
    scanf("%s", in_file);
    while ((ch = getchar()) != '\n')
        continue;
    // Create output filename
    strncpy(out_file, in_file, LEN - 5);
    out_file[LEN-5] = '\0';
    strcat(out_file, ".red");
    
    if ((in = fopen(in_file, "r")) == NULL)
    {
        fprintf(stderr, "Error opening the file \"%s\"\n", in_file);
        exit(1);
    }
    if ((out = fopen(out_file, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
        exit(4);
    }
    return 0;
}

