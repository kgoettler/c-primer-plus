/*
 * Write a program that uses one printf() call to print your first name and
 * last name on one line, uses a second printf() call to print your first and
 * last names on two separate lines, and uses a pair of printf() calls to print
 * your first and last names on one line. The output should look something like this
 *
 * Ken Goettler
 * Ken
 * Goettler
 * Ken Goettler
 *
 */

#include <stdio.h>

#define FIRST_NAME "Ken"
#define LAST_NAME "Goettler"

int main (void)
{
    printf("%s %s\n", FIRST_NAME, LAST_NAME);
    printf("%s\n%s\n", FIRST_NAME, LAST_NAME);
    printf("%s", FIRST_NAME);
    printf(" %s\n", LAST_NAME);
}
