/*
 * Write a program that creates an array with 26 elements and stores the 26
 * lowercase letter in it. Also have it show the array contents.
 */

#include <stdio.h>

int main (void)
{
    char arr[26];
    char ch;
    int idx = 0;
    for (ch = 'a'; ch < ('a' + 26); ch++)
        arr[idx++] = ch;
    for (int i = 0; i < 26; i++)
        printf("%c\n", arr[i]);
    return 0;
}
         
