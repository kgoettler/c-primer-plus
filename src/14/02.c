/*
 * Write a program that prompts the user to enter the day, month, and year. The
 * month can be a month number, a month name, or a month abbreviation. The
 * program then should return the total number of days in the year up through
 * the given day. (Do take leap years into account.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct month {
    char name[128];
    int days;
};

const struct month normal_year[12] = {
    {"January", 31},
    {"Feburary", 28},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31},
};

const struct month leap_year[12] = {
    {"January", 31},
    {"Feburary", 29},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31},
};

int check_leap_year(int year);
int calculate_days_to_date(int month, int day, int year);
char * s_gets(char * st, int n);

int main (void)
{
    int year = 2020;
    int month = 2;
    int day = 1;
    int d = calculate_days_to_date(month, day, year);
    printf("Days from 01/01/%d until %d/%d/%d: %d\n", year, month+1, day, year, d);
    return 0;
}

int check_leap_year(int year)
{
    int is_leap;
    if (year % 4 != 0)
        is_leap = 0;
    else if (year % 100 != 0)
        is_leap = 1;
    else if (year % 400 != 0)
        is_leap = 0;
    else
        is_leap = 1;
    return is_leap;
}

int calculate_days_to_date(int month, int day, int year)
{
    // Determine if leap year
    const struct month (*yp);
    if (check_leap_year(year) == 1)
        yp = leap_year;
    else
        yp = normal_year;
        
    int is_leap = check_leap_year(year);
   
    // Calculate total number of days
    int tot = 0;
    for (int i = 0; i <= month; i++)
        tot += yp[i].days;
    tot -= (yp[month].days - day);
    return tot;
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
