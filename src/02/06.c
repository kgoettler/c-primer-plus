/*
 * Write a program that creates an integer variable called toes. Have the
 * program set toes to 10. Also have the program calculate what twice toes
 * is and what toes squared is. The proram shouuld print all three variables,
 * identifying them.
 */

#include <stdio.h>

int main(void)
{
    int toes = 10;
    int toes_x2 = toes * 2;
    int toes_sq = toes * toes;
    printf("toes     = %d\ntoes*2   = %d\ntoes^2   = %d\n", toes, toes_x2, toes_sq);
    return 0;
}
