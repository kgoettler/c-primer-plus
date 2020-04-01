/*
 * Modify Listing 13.1 so that it solicits the user to enter the filename and
 * reads the user's response instead of using command-line arguments
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    int ch;
    char filename[1024];
    FILE *fp;
    unsigned long count = 0;
    if (argc != 1)
    {
        printf("Usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("Enter the filename: ");
    scanf("%s", filename);
    while((ch = getchar()) != '\n')
        continue;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);
    return 0;
}
