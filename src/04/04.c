/*
 * Write a program that requests your height in inches and your name, and then
 * displays the information in the following form:
 *  Dabney, you are 6.208 feet tall
 * Use type float, and use / for division. If you prefer, request the height in
 * centimeters and display it in meters.
 */

#include <stdio.h>

int main (void)
{
    char name[30];
    float value;
    
    printf("Enter your first name:\n");
    scanf("%s", name);
    printf("Enter your height in inches:\n");
    scanf("%f", &value);
    printf("%s, you are %1.3f feet tall\n", name, value / (float) 12);
    return 0;
}
