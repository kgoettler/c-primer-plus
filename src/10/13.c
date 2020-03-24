#include <stdio.h>

void print_array(double arr[][5], int rows)
{

    printf("[\n");
    for (int i = 0; i < rows; i++) 
    {
        printf(" [");
        for (int j = 0; j < 5; j++) 
        {
            printf("%lf, ", *(*(arr+i) + j));
        }
        printf("],\n");
    }
    printf("]\n");
    return;
}

double array_mean1d(double vals[], int size)
{
    double mean = 0;
    for (int i = 0; i < size; i++)
        mean += vals[i];
    mean = mean / (double) size;
    return mean;
}

double array_mean2d(double vals[][5], int rows)
{
    double mean = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 5; j++)
            mean += vals[i][j];
    mean = mean / (double) (rows * 5);
    return mean;
}

double array_max(double vals[][5], int rows)
{
    double max = vals[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 5; j++)
            if (vals[i][j] > max)
                max = vals[i][j];
    return max;
}

void read_array(double vals[][5], int rows)
{
    for (int i = 0; i < rows; i++) 
    {
        printf("Enter five double values (%d of %d):\n", i, rows);
        scanf("%lf %lf %lf %lf %lf", &vals[i][0], &vals[i][1], &vals[i][2],
              &vals[i][3], &vals[i][4]);
    }
    return;
}

int main (void)
{
    double vals[3][5];
    read_array(vals, 3);
    print_array(vals, 3);
    for (int i = 0; i < 3; i++)
        printf("The mean of row %d is: %lf\n", i, array_mean1d(vals[i], 5));
    printf("The mean of the entire array is: %lf\n", array_mean2d(vals, 3));
    printf("The maximum of the entire array is: %lf\n", array_max(vals, 3));

    return 0;
}
