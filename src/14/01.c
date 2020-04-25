/*
 * Redo Review Question 5, but make the argument the spelled-out name of the
 * month instead of the month number. (Dont' forget about strcmp().) Test the
 * function in a simple program
 */

#include <stdio.h>
#include <string.h>

struct month {
    char name[128];
    int days;
};

struct month months[12] = {
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

int cumulative_days(char * name)
{
    int tot = 0;
    for (int i = 0; i < 12; i++)
    {
        tot += months[i].days;
        if (strcmp(months[i].name, name) == 0)
            break;
    }
    return tot;
}

int main (void)
{

    for (int i = 0; i < 12; i++)
        printf("Days from January -> %s: %d\n", months[i].name, cumulative_days(months[i].name));
    return 0;
}
