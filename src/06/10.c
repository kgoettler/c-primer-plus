/*
 * Write a program that requests lower and upper integer limits, calculates the
 * sum of all the integer squares from the square of the lower limit to the
 * square of the upper limit, and displays the answer. The program should then
 * continue to prompt for limits and display answers until the user enters an
 * upper limit that is equal to or less than the lower limit. A sample run
 * should look something like this:
 *
 * Enter lower and upper integer limits: 5 9
 * The sums of the squares from 25 to 81 is 255 
 * Enter next set of limits: 3 25 
 * The sums of the squares from 9 to 625 is 5520 
 * Enter next set of limits: 5 5 Done
 */

#include <stdio.h>

int main (void)
{
    int x, y, tot = 0;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d %d", &x, &y) == 2 && x < y)
    {
        for (int i = x; i <= y; i++)
        {
            tot += (i * i);
        }
        printf("The sum of squares from %d to %d is %d\n", x*x, y*y, tot);
        printf("Enter the next set of limits: ");
        tot = 0;
    }
    printf("Done\n");
    return 0;
}
