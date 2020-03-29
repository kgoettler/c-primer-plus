/*
 * Rewrite the program in Listing 12.4 so that it does use global variables
 */

#include <stdio.h>

void critic (int * units)
{
    /* optional redeclaration omitted */
    printf("No luck, my friend. Try again.\n");
    scanf("%d", units);
}

int main (void)
{
    int units = 0;
    int * units_p = &units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(units_p);
    printf("You must have looked it up!\n");
    return 0;
}
