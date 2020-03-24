/*
 * Write a program that requests the hours worked in a week and then prints the
 * gross pay, the taxes, and the net pay. Assume the following:
 *
 * a. Basic pay rate = $10.00/hr
 * b.  Overtime (in excess of 40 hours) = time and a half 
 * c. Tax rate: #15% of the first $300
 * 20% of the next $150
 * 25% of the rest
 * 
 * Use #define constants, and don’t worry if the example does not conform to
 * current tax law.
 */

#include <stdio.h>

#define WAGE 10
#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25
#define TAX_TIER_1 300
#define TAX_TIER_2 150

int main (void)
{
    float hours = 0;
    float gross_pay = 0, taxes = 0, net_pay = 0;
    printf("Enter the number of hours worked this week: ");
    scanf("%f", &hours);
    
    gross_pay = hours * WAGE;
    // Calculate taxes
    if (gross_pay < TAX_TIER_1)
        taxes = gross_pay * TAX_RATE_1;
    else if (gross_pay < TAX_TIER_1 + TAX_TIER_2)
        taxes = TAX_TIER_1 * TAX_RATE_1 + (gross_pay - TAX_TIER_1) * TAX_RATE_2;
    else
        taxes = TAX_TIER_1 * TAX_RATE_1 + TAX_TIER_2 * TAX_RATE_2 + (gross_pay - TAX_TIER_1 - TAX_TIER_2) * TAX_RATE_3;
    net_pay = gross_pay - taxes;
    printf("Gross: %.2f\nTaxes: %.2f\nNet:  %.2f\n", gross_pay, taxes, net_pay);
    return 0;
}
