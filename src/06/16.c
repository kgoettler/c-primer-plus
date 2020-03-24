/*
 * Daphne invests $100 at 10% simple interest. (That is, every year, the
 * investment earns an interest equal to 10% of the original investment.)
 * Deirdre invests $100 at 5% interest compounded annually. (That is, interest
 * is 5% of the current balance, including previous addition of interest.) Write
 * a program that finds how many years it takes for the value of Deirdre’s
 * investment to exceed the value of Daphne’s investment. Also show the two
 * values at that time.
 */

#include <stdio.h>

int main (void)
{
    float deirdre_p = 100, daphne_p = 100;
    float deirdre_r = 0.05, daphne_r = 0.10;
    float deirdre_bal = deirdre_p;
    float daphne_bal = daphne_p;
    int years = 0;
    while (deirdre_bal <= daphne_bal)
    {
        // Simple interest for Daphne
        daphne_bal += daphne_p * daphne_r;

        // Compound interest for Deirdre
        deirdre_bal *= (1.0 + deirdre_r);
        years++;
    }
    printf("Years: %d\n", years);
    printf("Daphne:  %.2f\n", daphne_bal);
    printf("Deirdre: %.2f\n", deirdre_bal);
    return 0;
}
