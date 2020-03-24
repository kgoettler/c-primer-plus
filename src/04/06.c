/*
 * Write a program that requests the user’s first name and then the user’s 
 * last name. Have it print the entered names on one line and the number of 
 * letters in each name on the following line. Align each letter count with the
 * end of the corresponding name, as in the following:
 *  Melissa Honeybee
 *        7        8
 * Next, have it print the same information, but with the counts aligned with 
 * the beginning of each name.
 *  Melissa Honeybee 
 *  7       8
 */

#include <stdio.h>
#include <string.h>

int main (void)
{

    char fname[30], lname[30];
    size_t fname_len, lname_len;

    printf("Enter your first name: ");
    scanf("%30s", fname);
    printf("Enter your last name: ");
    scanf("%30s", lname);

    fname_len = strlen(fname);
    lname_len = strlen(lname);
    
    printf("%s %s\n", fname, lname);
    printf("%*zu %*zu", (int) fname_len, fname_len, (int) lname_len, lname_len);
    printf("\n");

    printf("%s %s\n", fname, lname);
    printf("%-*zu %-*zu", (int) fname_len, fname_len, (int) lname_len, lname_len);
    printf("\n");

    return 0;
}
