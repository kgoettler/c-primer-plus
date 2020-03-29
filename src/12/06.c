/*
 * Write a program that generates 1000 random numbers in the range 1 - 10. Don't
 * save or print the numbers, but do print how many times each number was
 * produced. Have the program do this for 10 different seed values. Do the
 * numbers appear in equal amounts? You can use the functions from this chapter
 * or the ANSI C rand() and srand() functions, which follow the same format that
 * our functions do. This is one way to examine the randomness of a particular
 * random-number generator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * gen_numbers(int max, int n)
{
    int val;
    // Allocate array, initialize to 0s
    int * arr = malloc(max * sizeof(int));
    for (int i = 0; i < max; i++)
        arr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        val = (rand() % max);
        arr[val] += 1;
    }
    return arr;
}


int main (void)
{
    srand(time(NULL));
    for (int h = 0; h < 10; h++)
    {
        int * arr = gen_numbers(10, 1000);
        for (int i = 0; i < 10; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    return 0;
}
