/*
 * Write a program that requests a type double number and prints the value of
 * the number cubed. Use a function of your own design to cube the value and
 * print it. The main() program should pass the entered value to this function.
 */

#include <stdio.h>

double cube(double x)
{
    return (x * x * x);
}

int main (void)
{
    double num;
    printf("Enter a double: ");
    scanf("%lf", &num);
    printf("%lf\n", cube(num));
    return 0;
}
