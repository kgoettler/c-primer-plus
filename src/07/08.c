/*
 * Modify assumption a. in exercise 7 so that the program presents a menu of pay
 * rates from which to choose. Use a switch to select the pay rate. The
 * beginning of a run should look something like this:
 *
 * ***************************************************************** 
 * Enter the number corresponding to the desired pay rate or action: 
 * 1) $8.75/hr                         2) $9.33/hr
 * 3) $10.00/hr                        4) $11.20/hr
 * 5) quit 
 * *****************************************************************
 *
 * If choices 1 through 4 are selected, the program should request the hours
 * worked. The program should recycle until 5 is entered. If something other
 * than choices 1 through 5 is entered, the program should remind the user what
 * the proper choices are and then recycle. Use #defined constants for the
 * various earning rates and tax rates.
 */

#include <stdio.h>

#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25
#define TAX_TIER_1 300
#define TAX_TIER_2 150

int main (void)
{
    float wage;
    float hours;
    float gross_pay, net_pay, taxes;
    int option = 0;
    
    do
    {
        query:
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr                         2) $9.33/hr\n");
        printf("3) $10.00/hr                        4) $11.20/hr\n");
        printf("5) Quit\n");
        printf("*****************************************************************\n");
        scanf("%d", &option);
        
        switch (option)
        {
            case 1:
                wage = 8.75;
                break;
            case 2:
                wage = 9.33;
                break;
            case 3:
                wage = 10;
                break;
            case 4:
                wage = 11.20;
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid option\n");
                goto query;
        }
        if (option == 5)
            break;

        printf("Enter hours worked: ");
        scanf("%f", &hours);
        
        // Calculate gross pay
        if (hours > 40)
            gross_pay = (hours - 40) * wage * 1.5 + 40 * wage;
        else
            gross_pay = hours * wage;

        // Calculate taxes
        if (gross_pay < TAX_TIER_1)
            taxes = gross_pay * TAX_RATE_1;
        else if (gross_pay < TAX_TIER_1 + TAX_TIER_2)
            taxes = TAX_TIER_1 * TAX_RATE_1 + (gross_pay - TAX_TIER_1) * TAX_RATE_2;
        else
            taxes = TAX_TIER_1 * TAX_RATE_1 + TAX_TIER_2 * TAX_RATE_2 + (gross_pay - TAX_TIER_1 - TAX_TIER_2) * TAX_RATE_3;

        // Calculate net pay
        net_pay = gross_pay - taxes;

        // Print
        printf("Gross: %.2f\nTaxes: %.2f\nNet:  %.2f\n", gross_pay, taxes, net_pay);
    } while (1);
    return 0;
}
