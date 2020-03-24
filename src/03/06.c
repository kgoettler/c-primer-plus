/*
 * The mass of a single molecule of water is about 3.0E-23 grams. A quart of
 * water is about 950 grams. Write a program that requests an amount of water
 * in quarts, and displays the number of water molecules in that amount.
 */

#include <stdio.h>

#define SINGLE_WATER 3E-23
#define QUART_TO_GRAMS 950

int main (void)
{
    double amount;
    printf("Enter an amount of water (in quarts): ");
    scanf("%lf", &amount);
    printf("That is %e water molecules\n", amount * QUART_TO_GRAMS / SINGLE_WATER);
    return 0;
}
