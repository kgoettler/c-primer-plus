/*
 * The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for
 * $1.15 per pound, and carrots for $1.09 per pound. It gives a 5% discount for
 * orders of $100 or more prior to adding shipping costs. It charges $6.50
 * shipping and handling for any order of 5 pounds or under, $14.00 shipping and
 * handling for orders over 5 pounds and under 20 pounds, and $14.00 plus $0.50
 * per pound for shipments of 20 pounds or more. Write a program that uses a
 * switch statement in a loop such that a response of a lets the user enter the
 * pounds of artichokes desired, b the pounds of beets, c the pounds of carrots,
 * and q allows the user to exit the ordering process. The program should keep
 * track of cumulative totals. That is, if the user enters 4 pounds of beets and
 * later enters 5 pounds of beets, the program should use report 9 pounds of
 * beets. The program then should compute the total charges, the discount, if
 * any, the shipping charges, and the grand total. The program then should
 * display all the purchase information: the cost per pound, the pounds ordered,
 * and the cost for that order for each vegetable, the total cost of the order,
 * the discount (if there is one), the shipping charge, and the grand total of
 * all the charges.
 */

#include <stdio.h>
#include <stdlib.h>

#define PRICE_A 2.05
#define PRICE_B 1.15
#define PRICE_C 1.09

int main (void)
{
    char ch; 
    float a = 0, b = 0, c = 0, weight = 0;
    float cost_a, cost_b, cost_c, cost, discount, amt, shipping;
    printf("Select a product (q to checkout)\n");
    printf("a) Artichokes\nb) Beets\nc) Carrots\n");
    query:
    while ((ch = getchar()) != 'q')
    {
        amt = 0;
        switch (ch)
        {
            case 'a':
                printf("Enter amount of artichokes: ");
                scanf("%f", &amt);
                a += amt;
                break;
            case 'b':
                printf("Enter amount of beets: ");
                scanf("%f", &amt);
                b += amt;
                break;
            case 'c':
                printf("Enter amount of carrots: ");
                scanf("%f", &amt);
                c += amt;
                break;
            default:
                printf("Invalid product code. Please enter a, b, or c (or q to quit)\n");
        }
        printf("a) Artichokes\nb) Beets\nc) Carrots\n");
        while ((ch = getchar()) != '\n')
        {}
    }

    // Calculate costs + total weight
    weight = a + b + c; 
    cost_a = a * PRICE_A;
    cost_b = b * PRICE_B;
    cost_c = c * PRICE_C;
    cost = cost_a + cost_b + cost_c;
    
    if (weight <= 5)
        shipping = 6.50;
    else if (weight < 20)
        shipping = 14.00;
    else
        shipping = 14 + (0.5 * weight);
    
    printf("Order Checkout\n");
    printf("Item           Cost/lb     Amount       Total Cost\n");
    printf("--------------------------------------------------\n");
    printf("Artichokes     %.2f/lb     %5.2f lbs     %-5.2f\n", PRICE_A, a, cost_a);
    printf("Beets          %.2f/lb     %5.2f lbs     %-5.2f\n", PRICE_B, b, cost_b);
    printf("Carrots        %.2f/lb     %5.2f lbs     %-5.2f\n", PRICE_C, c, cost_c);
    printf("Subtotal                                 %-5.2f\n", cost);
    
    if (cost > 100)
    {
        discount = 0.05 * cost;
        cost -= discount;
        printf("Discount                               -%5.2f\n", discount);
    }
    printf("Shipping                                 %5.2f\n", shipping);
    printf("--------------------------------------------------\n");
    printf("Grand total                              %5.2f\n", cost + shipping);
    return 0;
}
