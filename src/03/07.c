/*
 * There are 2.54 centimeters to the inch. Write a program that asks you to
 * enter your height in inches and then displays your height in centimeters.
 * Or, if you prefer, ask for the height in centimeters and convert that to 
 * inches
 */

#include <stdio.h>
#define CM_TO_INCH 2.54

int main (void)
{
    float height;
    printf("Enter height (in): ");
    scanf("%f", &height);
    printf("You are %g cm tall\n", height * CM_TO_INCH);
    return 0;
}
