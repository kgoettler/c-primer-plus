/*
 * Modify and test the function in exercise 1 so that it stops after n
 * characters or after the first blank, tab, or newline, whichever comes first.
 * (Don't just use scanf())
 */

#include <stdio.h>

void fetch(int n, char arr[])
{
	char ch;
    int cnt = 0;
	for (int i = 0; i < n; i++)
	{
        ch = getchar();
		if ((ch == EOF) | (ch == ' ') | (ch == '\t') | (ch == '\n'))
			break;
		*(arr + i) = ch;
        cnt = i+1;
	}
    for (int i = cnt; i < n; i++)
        *(arr + i) = ' ';
    return;
}

int main (void)
{
    int n = 20;
    char arr[20];
    fetch(n, arr);
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
    printf("\n");
    return 0;
}
