/*
 * Many studies suggest that smiling has benefits. Write a program that produces
 * the following output:
 *
 * Smile!Smile!Smile!
 * Smile!Smile!
 * Smile!
 *
 * Have the proram define a function that displays the string Smile! once, and
 * have the program use the function as often as needed.
 */

#include <stdio.h>

void smile(void)
{
    printf("Smile!");
}

int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
    return 0;
}

