/*
 * Write a program that generates a list of 100 random numbers in the range 1–10
 * in sorted decreasing order. (You can adapt the sorting algorithm from Chapter
 * 11, “Character Strings and String Functions,” to type int. In this case, just
 * sort the numbers themselves.)
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 100

// Selection sort algorithm
void sort(int * arr, int n)
{
    int tmp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return;
}

int main (void)
{
    int arr[LEN];
    for (int i = 0; i < LEN; i++)
        arr[i] = (rand() % 10) + 1;
    sort(arr, LEN);
    return 0;
}
