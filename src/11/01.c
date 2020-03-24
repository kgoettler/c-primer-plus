/*
 * Design and test a function that fetches the next n characters from input
 * (including blanks, tabs, and newlines), storing the results in an array whose
 * adderess is passed as an argument
 */

#include <stdio.h>

void fetch(int n, char arr[])
{
	char ch;
	for (int i = 0; i < n; i++)
	{
		if ((ch = getchar()) == EOF)
			break;
		*(arr + i) = ch;
	}
    return;
}

int main (void)
{
    int n = 20;
    char arr[20];
    fetch(n, arr);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
    printf("\n");
    return 0;
}
