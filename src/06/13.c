/*
 *  Write a program that creates an eight-element array of ints and sets the
 *  elements to the first eight powers of 2 and then prints the values. Use a
 *  for loop to set the values, and, for variety, use a do while loop to display
 *  the values.
 */

#include <stdio.h>

int main (void)
{
    int arr[8];
    int tmp = 0;

    for (int i = 0; i < 8; i++)
    {
        arr[i] = 1;
        for (int j = 0; j < i; j++)
            arr[i] *= 2;
    }
    int i = 0;
    do {
        printf("%d ", arr[i++]);
    } while (i < 8);
    printf("\n");

    return 0;
}
