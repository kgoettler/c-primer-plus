/*
 * Write a program that asks you to enter an ASCII code value, such as 66, and
 * then prints the character having that ASCII code
 */

#include <stdio.h>

int main (void)
{
    int ascii;
    printf("Enter an integer value: ");
    scanf("%d", &ascii);
    printf("%c\n", ascii);
    return 0;
}
