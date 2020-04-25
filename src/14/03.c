/*
 * Revise the book-listing program in Listing 14.2 so that it prints the book
 * descriptions in the order entered, then alphabetized by title, and then in
 * order of increased value.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10             /* maximum number of books */
struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
void sort_by_title(struct book * arr[], int n);
void sort_by_value(struct book * arr[], int n);

int main(void)
{
    struct book library[MAXBKS]; /* array of structures     */
    struct book * plib[MAXBKS]; /* array of pointers to structs */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (struct book);
    
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    
    rewind(pbooks);            /* go to start of file     */
    while (count < MAXBKS &&  fread(&library[count], size,
                                    1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title,
               library[count].author, library[count].value);
        plib[count] = &library[count];
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        plib[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue;                /* clear input line  */
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    
    if (count > 0)
    {
        // Print in order entered
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);

        // Print alphabetized by title
        printf("\n");
        puts("Here is the list of your books (sorted alphabetically):");
        sort_by_title(plib, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",plib[index]->title,
                   plib[index]->author, plib[index]->value);

        // Print by value
        printf("\n");
        puts("Here is the list of your books (sorted by value):");
        sort_by_value(plib, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",plib[index]->title,
                   plib[index]->author, plib[index]->value);
    }
    else
    	puts("No books? Too bad.\n");
    
    puts("Bye.\n");
    fclose(pbooks);
    
    return 0;
}

void sort_by_title(struct book * arr[], int n)
{
    struct book * tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j]->title, arr[i]->title) < 0)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    return;
}

void sort_by_value(struct book * arr[], int n)
{
    struct book * tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j]->value) > (arr[i]->value))
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    return;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
