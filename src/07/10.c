/*
 * The 1988 United States Federal Tax Schedule was the simplest in recent times.
 * It had four categories, and each category had two rates. Here is a summary
 * (dollar amounts are taxable income):
 *
 * Category                           Tax
 * Single                             15% of first $17,850 plus 28% of excess
 * Head of Household                  15% of first $23,900 plus 28% of excess
 * Married, Joint                     15% of first $29,750 plus 28% of excess
 * Married, Separate                  15% of first $14,875 plus 28% of excess
 * For example, a single wage earner with a taxable income of $20,000 owes 0.15
 * × $17,850 + 0.28 × ($20,000−$17,850). Write a program that lets the user
 * specify the tax category and the taxable income and that then calculates the
 * tax. Use a loop so that the user can enter several tax cases.
 */

#include <stdio.h>

int main (void)
{
    int option; 
    float income, tax, limit_1;
    query:
    printf("*****************************************************************\n");
    printf("Enter your tax bracket:\n");
    printf("1) Single                      2) Head of Household\n");
    printf("3) Married, Joint              4) Married, Separate\n");
    printf("5) Quit\n");
    printf("*****************************************************************\n");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            limit_1 = 17850;
            break;
        case 2:
            limit_1 = 23900;
            break;
        case 3:
            limit_1 = 29750;
            break;
        case 4:
            limit_1 = 14875;
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
            goto query;
    }
    
    if (option == 5)
        return 0;

    printf("Enter taxable income: ");
    scanf("%f", &income);
    
    if (income > limit_1)
        tax = (limit_1 * 0.15) + ((income - limit_1) * .28);
    else
        tax = income * 0.15;

    printf("Income: %.2f\n", income);
    printf("Tax:    %.2f\n", tax);
    goto query;
}





        

