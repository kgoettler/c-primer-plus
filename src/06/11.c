/*
 * Write a program that reads eight integers into an array and then prints them
 * in reverse order.
 */

#include <stdio.h>

#define SIZE 8

int main (void)
{
    int arr[SIZE];
    printf("Enter eight integers: \n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = SIZE-1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
