/*
 * Write a program that behaves like the modification of Listing 12.13, which we
 * discussed after showing the output of Listing 12.13. That is, have the
 * program produce output like the following:
 *  Enter the number of sets; enter q to stop: 18 
 *  How many sides and how many dice? 6 3
 *  Here are 18 sets of 3 6-sided throws.
 *  12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
 *  13 8 14
 * How many sets? Enter q to stop: q
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(int sides, int rolls)
{
    int out = 0;
    for (int i = 0; i < rolls; i++)
        out += (rand() % sides) + 1;
    return out;
}

int main (void)
{
    int dice, sets, sides;
    srand((unsigned int) time(0));
    while(1)
    {
        // Get sets
        printf("Enter the number of sets; enter q (or non numeric character) to stop: ");
        if (scanf("%d", &sets) != 1 || sets <= 0)
            break;
        
        // Get sides + number of dice
        printf("How many sides and how many dice? ");
        if (scanf("%d %d", &sides, &dice) != 2)
            break;
        
        // Allocate array to hold the dice rolls + roll
        int * rolls = malloc(sets * sizeof(int));
        for (int i = 0; i < sets; i++)
            rolls[i] = roll(sides, dice);
        
        // Print
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (int i = 0; i < sets; i++)
            printf("%d ", rolls[i]);
        printf("\n");
        
        // Free dice rolls array
        free(rolls);
    }
    printf("Done\n");
    return 0;
}
