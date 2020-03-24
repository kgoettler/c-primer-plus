/*
 * Write a program that asks the user to enter a height in centimeters and then
 * displays the height in centimeters and in feet and inches. Fractional
 * centimeters and inches should be allowed, and the program should allow the
 * user to continue entering heights until a nonpositive value is entered. A
 * sample run should look like this:
 *
 * Enter a height in centimeters: 182
 * 182.0 cm = 5 feet, 11.7 inches
 * Enter a height in centimeters (<=0 to quit): 168.7
 * 168.0 cm = 5 feet, 6.4 inches
 * Enter a height in centimeters (<=0 to quit): 0
 * bye
 */

#include <stdio.h>

#define IN_TO_CM 2.54
#define FT_TO_IN 12

int main (void)
{
    float cm, feet, in;
    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0)
    {
        in = cm / IN_TO_CM;
        feet = (int) in / FT_TO_IN;
        in -= feet * FT_TO_IN;
        printf("%.1f cm = %g feet, %.1f inches\n", cm, feet, in);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    return 0;
}
