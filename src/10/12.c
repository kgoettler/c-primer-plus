/*
 * Rewrite the rain program in Listing 10.7 so that the main tasks are performed
 * by functions instead of in main()
 */

#include <stdio.h>

void print_annual_totals(const float rain[][12], int years)
{
    int i,j;
    float subtot, tot;
    printf(" YEAR     RAINFALL   (inches)\n");
    for (i = 0, tot = 0; i < years; i++)
    {
        for (j = 0, subtot = 0; j < 12; j++) {
            subtot += rain[i][j];
        }
        printf("%5d %15.1f\n", 2010 + i, subtot);
        tot += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", tot / years);
    return;
}

void print_monthly_averages(const float rain[][12], int years)
{
    int i, j;
    float subtot;
    
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (i = 0; i < 12; i++)
    {
        for (j = 0, subtot = 0; j < years; j++)
            subtot += rain[j][i];
        printf("%4.1f ", subtot/years);
    }
    printf("\n");

    return;
}

int main (void)
{
    const float rain[5][12] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3}, 
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}, 
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2}, 
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2},
    };

    print_annual_totals(rain, 5);
    print_monthly_averages(rain, 5);
    
    return 0;
}
