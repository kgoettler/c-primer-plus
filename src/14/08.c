/*
 * The Colossus Airlines fleet consists of one plane with a seating capacity of
 * 12. It makes one flight daily. Write a seating reservation program with the
 * following features:
 *
 * a. The program uses an array of 12 structures. Each structure should hold a
 * seat identification number, a marker that indicates whether the seat is
 * assigned, the last name of the seat holder, and the first name of the seat
 * holder.
 *
 * b. The program displays the following menu:
 *   To choose a function, enter its letter label:
 *   a) Show number of empty seats
 *   b) Show list of empty seats
 *   c) Show alphabetical list of seats
 *   d) Assign a customer to a seat assignment e) Delete a seat assignment
 *   f) Quit
 *
 * c. The program successfully executes the promises of its menu. Choices d) and
 * e) require additional input, and each should enable the user to abort an
 * entry.
 *
 * d. After executing a particular function, the program shows the menu again,
 * except for choice f)
 *
 * e. Data is saved in a file between runs. When the program is restarted, it
 * first loads in the data, if any, from the file.
 */

#include <stdio.h>
#include <string.h>

#define PLANE_SIZE 3
#define NAME_LENGTH 128

struct seat {
    unsigned int seat_num;
    int reserved;
    char last_name[NAME_LENGTH];
    char first_name[NAME_LENGTH];
};

void create_plane(struct seat plane[], int n);
int read_data(char * filename, struct seat plane[], int n);
int write_data(char * filename, struct seat plane[], int n);
char get_option(void);
void assign_seat(struct seat plane[], int n);
void delete_seat(struct seat plane[], int n);
void print_empty_seat_count(struct seat plane[], int n);
void print_empty_seat_numbers(struct seat plane[], int n);
void print_alphabetical_seats(struct seat plane[], int n);
char * s_gets(char * st, int n);

int main (void)
{
    char ch;
    char * in_file = "08_data.dat";
    struct seat plane[PLANE_SIZE];
    create_plane(plane, PLANE_SIZE);
    int res = read_data(in_file, plane, PLANE_SIZE);
    if (res != 0)
    {
        printf("No data found\n");
    }
    // Open file, and read in data (if available)
    while ((ch = get_option()) != 'f')
    {
        switch (ch)
        {
            case 'a':
                print_empty_seat_count(plane, PLANE_SIZE);
                break;
            case 'b':
                print_empty_seat_numbers(plane, PLANE_SIZE);
                break;
            case 'c':
                print_alphabetical_seats(plane, PLANE_SIZE);
                break;
            case 'd':
                assign_seat(plane, PLANE_SIZE);
                break;
            case 'e':
                delete_seat(plane, PLANE_SIZE);
                break; 
        }
    }
    res = write_data(in_file, plane, PLANE_SIZE);
    printf("Goodbye\n");
    return 0;
}

void create_plane(struct seat plane[], int n)
{
    for (int i = 0; i < n; i++)
    {
        plane[i].seat_num = i+1;
        plane[i].reserved = 0;
        strcpy(plane[i].first_name, "");
        strcpy(plane[i].last_name, "");
    }
    return;
}

int read_data(char * filename, struct seat plane[], int n)
{
    FILE * fp;
    size_t size = sizeof (struct seat);
    if ((fp = fopen(filename, "r+b")) == NULL)
        return 1;
    int count = 0;
    while (count < n &&  fread(&plane[count], size, 1, fp) == 1)
        count++;
    return 0;
}

int write_data(char * filename, struct seat plane[], int n)
{
    FILE * fp;
    size_t size = sizeof (struct seat);
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        printf("Cannot open file %s for writing\n", filename);
        return 1;
    }
    for (int i = 0; i < n; i++)
        fwrite(&plane[i], size, 1, fp);
    return 0;
}

void assign_seat(struct seat plane[], int n)
{
    int num = 0;
    char first_name[NAME_LENGTH];
    char last_name[NAME_LENGTH];
    for (int i = 0; i < n; i++)
    {
        if (plane[i].reserved == 0)
            printf("(%d, <empty>)\n", plane[i].seat_num);
    }
    printf("Enter seat number to assign (enter -1 to abort: ");
    scanf("%d", &num);
    while (getchar() != '\n')
        continue;
    num--;
    if (num >= 0 && num < PLANE_SIZE)
    {
        do {
            printf("Enter the first name: ");
        } while (s_gets(first_name, NAME_LENGTH) == NULL);
        do {
            printf("Enter the last name: ");
        } while (s_gets(last_name, NAME_LENGTH) == NULL);
        strncpy(plane[num].first_name, first_name, NAME_LENGTH);
        strncpy(plane[num].last_name, last_name, NAME_LENGTH);
        plane[num].reserved = 1;
    }
    return;
}

void delete_seat(struct seat plane[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (plane[i].reserved == 1)
            printf("(%d, %s %s)\n",
                    plane[i].seat_num,
                    plane[i].first_name,
                    plane[i].last_name
                );
    }
    int num = 0;
    printf("Enter seat number to delete (enter -1 to abort): ");
    scanf("%d", &num);
    while (getchar() != '\n')
        continue;
    num--;
    if (num >= 0 && num < PLANE_SIZE)
    {
        plane[num].first_name[0] = '\0';
        plane[num].last_name[0] = '\0';
        plane[num].reserved = 0;
    }
    return;
}

void print_alphabetical_seats(struct seat plane[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (plane[i].reserved == 1)
            printf("(%d, %s %s)\n",
                    plane[i].seat_num,
                    plane[i].first_name,
                    plane[i].last_name
                );
        else
            printf("(%d, <empty>)\n", plane[i].seat_num);
    }
    return;
}

void print_empty_seat_numbers(struct seat plane[], int n)
{
    printf("Empty seat numbers:\n");
    for (int i = 0; i < n; i++)
        if (plane[i].reserved == 0)
            printf("%d\n", plane[i].seat_num);
    return;
}

void print_empty_seat_count(struct seat plane[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (plane[i].reserved == 0)
            count++;
    printf("Empty seats: %d\n", count);
    return;
}

char get_option(void)
{
    char ch = '\0';
    printf("To choose a function, enter its letter label:\n"
         "a) Show number of empty\n"
         "b) Show list of empty seats\n"
         "c) Show alphabetical list of seats\n"
         "d) Assign a customer to a seat assignment\n"
         "e) Delete a seat assignment\n"
         "f) Quit\n"
         "Input: "
        );
    ch = getchar();
    while (ch < 'a' || ch > 'f')
    {
        while (getchar() != '\n')
            continue;
        printf("Invalid input - try again: ");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;
    return ch;
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
