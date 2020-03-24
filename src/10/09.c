/*
 * Write a program that initializes a two-dimensional 3×5 array-of-double and
 * uses a VLA- based function to copy it to a second two-dimensional array. Also
 * provide a VLA-based function to display the contents of the two arrays. The
 * two functions should be capable, in general, of processing arbitrary N×M
 * arrays. (If you don’t have access to a VLA-capable compiler, use the
 * traditional C approach of functions that can process an N×5 array).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to fill array with random values later

#define ROWS 3
#define COLS 5

void print_array(int rows, int cols, int arr[rows][cols])
{

    printf("[\n");
    for (int i = 0; i < rows; i++) 
    {
        printf(" [");
        for (int j = 0; j < cols; j++) 
        {
            printf("%d, ", *(*(arr+i) + j));
        }
        printf("]\n");
    }
    printf("]\n");
    return;
}

void copy_vla(int rows, int cols, int src[rows][cols], int dest[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            dest[i][j] = src[i][j];
    return;
}

int main(void)
{
    int test[ROWS][COLS];
    int copy[ROWS][COLS];
    
    // Fill array with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            test[i][j] = (int) (rand() % 10);

    print_array(ROWS, COLS, test);
    copy_vla(ROWS, COLS, test, copy);
    print_array(ROWS, COLS, copy);
    
    return 0;
} 



