/*
 * Write a program that creates a strucutre template with two members according
 * to the following criteria:
 *
 * a. The first member is a social security number. The second member is a
 * structure with three members. Its first member contains a first name, its
 * second member contains a middle name, and its final member contains a last
 * name. Create and initialize an array of five such structures. Have the
 * program print the data in this format:
 *
 * Dribble, Flossie M. -- 302039823
 *
 * Only the initial letter of the middle name is printed, and a period is added.
 * Neither the initial (of course) nor the period should be printed if the
 * middle name member is empty. Write a function to do the printing; pass the
 * structure array to the function.
 *
 * b. Modify part a. by passing the structure value instead of the address
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

struct person {
    char first[MAXLEN];
    char middle[MAXLEN];
    char last[MAXLEN];
};
struct citizen {
    unsigned int ssn;
    struct person name;
};
void print_citizen(struct citizen inp);
int main (void)
{
    struct citizen people[5] = {
        {
            123456785,
            {
                "Michael",
                "Gary",
                "Scott",
            }
        },
        {
            123456786,
            {
                "Dwight",
                "Kurt",
                "Schrute",
            }
        },
        {
            123456787,
            {
                "Pamela",
                "Morgan",
                "Beesly",
            }
        },
        {
            123456788,
            {
                "Jim",
                "Duncan",
                "Halpert",
            }
        },
        {
            123456789,
            {
                "Andrew",
                "",
                "Bernard",
            }
        }
    };
    
    for (int i = 0; i < 5; i++)
        print_citizen(people[i]);
    return 0;
}

void print_citizen(struct citizen inp)
{
    char mi[5] = " ";

    if (strlen(inp.name.middle) != 0)
        sprintf(mi, " %c. ", inp.name.middle[0]);

    printf("%s, %s%s-- %d\n", inp.name.last, inp.name.first, mi, inp.ssn);
    return;
}
