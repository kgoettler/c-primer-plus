/*
 * Write a program that fits the following recipe:
 * 
 * a. Externally define a name structure template with two members: a string to
 * hold the first name and a string to hold the second name.
 * 
 * b. Externally define a student structure template with three members: a name
 * structure, a grade array to hold three floating-point scores, and a variable
 * to hold the average of those three scores.
 *
 * c. Have the main() function declare an array of CSIZE (with CSIZE = 4)
 * student structures and initialize the name portions to names of your choice.
 * Use functions to perform the tasks described in parts d., e., f., and g.
 *
 * d. Interactively acquire scores for each student by prompting the user with a
 * student name and a request for scores. Place the scores in the grade array
 * portion of the appropriate structure. The required looping can be done in
 * main() or in the function, as you prefer.
 *
 * e. Calculate the average score value for each structure and assign it to the proper member.
 *
 * f. Print the information in each structure.
 *
 * g. Print the class average for each of the numeric structure members.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSIZE 4
#define MAXLEN 256

struct name {
    char first[MAXLEN];
    char last[MAXLEN];
};
struct student {
    struct name name;
    double grade[3];
    double avg;
};

void get_scores(struct student * inp);
void calc_average(struct student * inp);
void print_student(struct student * inp);
double calc_class_average(struct student inp[], int n, int idx);

int main (void)
{
    struct student class[CSIZE] = {
        {{"Michael", "Scott"}, {90, 95, 100}, 0},
        {{"Dwight", "Schrute"}, {80, 85, 90}, 0},
        {{"Pam", "Beesly"}, {70, 75, 80}, 0},
        {{"Jim", "Halpert"}, {60, 65, 70}, 0},
    };
    for (int i = 0; i < CSIZE; i++)
    {
        calc_average(&class[i]);
        print_student(&class[i]);
    }

    for (int i = 0; i < 3; i++)
        printf("Class Average on #%d: %lf\n", (i+1), calc_class_average(class, CSIZE, i));

    return 0;
}

void get_scores(struct student * inp)
{
    printf("Enter 3 scores for %s %s: ", inp->name.first, inp->name.last);
    scanf("%lf %lf %lf", &(inp->grade[0]), &(inp->grade[1]), &(inp->grade[2]));
    while (getchar() != '\n')
        continue;
    return;
}

void calc_average(struct student * inp)
{
    double tot = 0;
    for (int i = 0; i < 3; i++)
        tot += inp->grade[i];
    tot = tot / 3;
    inp->avg = tot;
    return;
}

void print_student(struct student * inp)
{
    printf("%s %s\nGrades: %.2lf %.2lf %.2lf\nAverage: %.2lf\n", 
            inp->name.first,
            inp->name.last,
            inp->grade[0],
            inp->grade[1],
            inp->grade[2],
            inp->avg
        );
    return;
}

double calc_class_average(struct student inp[], int n, int idx)
{
    double tot = 0;
    for (int i = 0; i < n; i++)
        tot += inp[i].grade[idx];
    tot = tot / n;
    return tot;
}
