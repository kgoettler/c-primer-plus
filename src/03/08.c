/*
 * In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 
 * ounces, an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write 
 * a program that requests a volume in cups and that displays the equivalent 
 * volumes in pints, ounces, tablespoons, and teaspoons. Why does a floating-
 * point type make more sense for this application than an integer type?
 */

#include <stdio.h>

#define PINT_TO_CUP 2
#define CUP_TO_OZ 8
#define OZ_TO_TBSP 2
#define TBSP_TO_TSP 3

int main (void)
{
    float amount;
    printf("Enter amount (cups): ");
    scanf("%f", &amount);
    printf("You entered %g cups\n", amount);
    printf("            %g pints\n", amount / PINT_TO_CUP);
    printf("            %g ounces\n", amount * CUP_TO_OZ);
    printf("            %g tablespoons\n", amount * CUP_TO_OZ * OZ_TO_TBSP);
    printf("            %g teaspoons\n", amount * CUP_TO_OZ * OZ_TO_TBSP * TBSP_TO_TSP);
    return 0;
}
