/*
 * Modify Listing 14.14 so that as each record is read from the file and shown
 * to you, you are given the chance to delete the record or to modify its
 * contents. If you delete the record, use the vacated array position for the
 * next record to be read. To allow changing the existing contents, you’ll need
 * to use the "r+b" mode instead of the "a+b" mode, and you’ll have to pay more
 * attention to positioning the file pointer so that appended records don’t
 * overwrite existing records. It’s simplest to make all changes in the data
 * stored in program memory and then write the final set of information to the
 * file. One approach to keeping track is to add a member to the book structure
 * that indicates whether it is to be deleted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10             /* maximum number of books */
char * s_gets(char * st, int n);
struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* array of structures     */
    int to_keep[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (struct book);
    
    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    

    char keep, option;
    rewind(pbooks);            /* go to start of file     */
    while (count < MAXBKS &&  fread(&library[count], size,
                                    1, pbooks) == 1)
    {
        keep = '\0';
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title,
               library[count].author, library[count].value);
        printf("Keep [k], modify [m], or delete [d]: ");
        while (keep != 'k' && keep != 'm' && keep != 'd')
        {
            scanf("%c", &keep);
            while (getchar() != '\n')
                continue;
        }
        if (keep == 'k')
        {
            to_keep[count] = 1;
        }
        else if (keep == 'm')
        {
            option = '\0';
            printf("Which field would you like to modify?\n");
            printf("a) Title\nb) Author\nc) Price\nEnter: ");
            while (option != 'a' && option != 'b' && option != 'c')
            {
                scanf("%c", &option);
                while (getchar() != '\n')
                    continue;
            }
            if (option == 'a')
            {
                do {
                    printf("Enter the new title: ");
                } while (s_gets(library[count].title, MAXTITL) == NULL);
            }
            else if (option == 'b')
            {
                do {
                    printf("Enter the new author: ");
                } while (s_gets(library[count].author, MAXAUTL) == NULL);
            }
            else if (option == 'c')
            {
                do {
                    printf("Enter the new price: ");
                } while (scanf("%f", &library[count].value) != 1);
                while (getchar() != '\n')
                    continue;
            }
            to_keep[count] = 1;
        }
        else
        {
            to_keep[count] = 0;
        }
        count++;
    }
    
    // Remove entries that aren't to be kept
    int i = 0;
    while (i < count)
    {
        if (to_keep[i] == 0)
        {
            for (int j = i+1; j < count; j++)
            {
                library[i] = library[j];
                to_keep[i] = to_keep[j];
            }
            count -= 1;
        }
        else
        {
            i++;
        }
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
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;                /* clear input line  */
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    }
    else
    	puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    
    return 0;
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
