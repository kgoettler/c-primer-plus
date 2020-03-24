/*
 * Generalize the to_binary() function of Listing 9.8 to a to_base_n() function
 * that takes a second argument in the range 2–10. It then should print the
 * number that is its first argument to the number base given by the second
 * argument. For example, to_ base_n(129,8) would display 201, the base-8
 * equivalent of 129. Test the function in a complete program.
 */

#include <stdio.h>

void base_n (int n, int b)
{
    int r;
    r = n % b; 
    if (n >= b)
        base_n(n / b, b); 
    printf("%d", r);
    return;
}

int main (void)
{
    int value = 25;
    int bases[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 9; i++)
    {
        base_n(value, bases[i]);
        printf("\n");
    }
    return 0;
}
