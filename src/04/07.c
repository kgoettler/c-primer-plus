/*
 * Write a program taht sets a type double variable to 1.0/3.0 and type float
 * variable to 1.0/3.0. Display each result three times - once showing four 
 * digits to the right of the decimal, once showing 12 digits to the right of
 * the decimal, and once showing 16 digits to the right of the decimal. Also
 * have the program include float.h and display the values of FLT_DIG and 
 * DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these values?
 */

#include <stdio.h>
#include <float.h>

int main (void)
{
    double d = 1.0/3.0;
    float f = 1.0/3.0;
    printf("%.4f\n", d);
    printf("%.16f\n", d);
    printf("%.12f\n", d);
    printf("%.4f\n", f);
    printf("%.16f\n", f);
    printf("%.12f\n", f);

    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);
    return 0;
}
