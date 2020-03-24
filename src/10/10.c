/*
 * Write a function that sets each elemnt in an array to the sum of the 
 * corresponding elements in two other arrays. That is, if array 1 has the
 * values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6, the 
 * function assigns array 3 the values 3, 4, 9, and 14. The function should
 * take three array names and an array size as arguments. Test the function
 * in a simple program
 */

#include <stdio.h>

#define SIZE 5

void print_array(int *arr, int size)
{

    printf("[");
    for (int i = 0; i < size; i++) 
        printf("%d, ", *(arr+i));
    printf("]\n");
    return;
}

void sum_array(int *arr1, int *arr2, int *arr3, int size)
{
    for (int i = 0; i < size; i++)
        arr3[i] = arr1[i] + arr2[i];
    return;
}

int main(void)
{
    int arr1[SIZE] = {1,2,3,4,5};
    int arr2[SIZE] = {2,3,4,5,6};
    int arr3[SIZE];
    print_array(arr1, SIZE);
    print_array(arr2, SIZE);
    sum_array(arr1, arr2, arr3, SIZE);
    print_array(arr3, SIZE);
    return 0;
}

