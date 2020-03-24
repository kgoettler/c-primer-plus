/*
 * Write a program that declares a 3x5 array of int and initializes it to 
 * some values of your choice. Have the pgraom print the values, double all
 * the values, and then display the new values. Write a function to do the 
 * displaying and a second function to do the doubling. Have the functions take
 * the array name and the number of rows as arguments
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

void print_array(int arr[][COLS], int rows)
{

    printf("[\n");
    for (int i = 0; i < rows; i++) 
    {
        printf(" [");
        for (int j = 0; j < COLS; j++) 
        {
            printf("%d, ", *(*(arr+i) + j));
        }
        printf("],\n");
    }
    printf("]\n");
    return;
}

void scale_array_by_2(int arr[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = arr[i][j] * 2;
    return;
}

int main(void)
{
    int test[ROWS][COLS] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
    };

    print_array(test, ROWS);
    scale_array_by_2(test, ROWS);
    print_array(test, ROWS);

    return 0;
}
