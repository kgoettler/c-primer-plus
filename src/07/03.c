/*
 * Write a program that reads integers until 0 is entered. After input
 * terminates, the program should report the total number of even integers
 * (excluding the 0) entered, the average value of the even integers, the total
 * number of odd integers entered, and the average value of the odd integers.
 */

#include <stdio.h>

int main (void)
{
    float even_sum = 0, odd_sum = 0;
    float even_avg = 0, odd_avg = 0;
    int even_cnt = 0, odd_cnt = 0;
    int i;
    printf("Begin entering numbers: \n");
    while (scanf("%d", &i) == 1 && i != 0)
    {
        if (i % 2 == 0)
        {
            even_sum += i;
            even_cnt++;
        }
        else
        {
            odd_sum += i;
            odd_cnt++;
        }
    }
    even_avg = even_sum / even_cnt;
    odd_avg = odd_sum / odd_cnt;
    printf("Evens:\n");
    printf("\tCount:   %d\n", even_cnt);
    if (even_cnt > 0)
        printf("\tAverage: %f\n\n", even_avg);
    printf("Odds:\n");
    printf("\tCount:   %d\n", odd_cnt);
    if (odd_cnt > 0)
        printf("\tAverage: %f\n\n", odd_avg);
    return 0;
}
