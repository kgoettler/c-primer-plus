/*
 * Write a program that reads input until encountering #. Have the program print
 * each input character and its ASCII decimal code. Print eight character-code
 * pairs per line. Suggestion: Use a character count and the modulus operator
 * (%) to print a newline character for every eight cycles of the loop.
 */

#include <stdio.h>

int main (void)
{
    char ch;
    unsigned int count = 0;
    while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case ' ':
					printf("' ': %3d ", ch);
					break;
			case '\t':
					printf("'\\t': %3d ", ch);
					break;
			case '\n':
					printf("'\\n': %3d ", ch);
					break;
			case '\b':
					printf("'\\b': %3d ", ch);
					break;
			default:
					printf(" %c : %3d ", ch, ch);
		}
		count++;
		if (count % 8 == 0)
			printf("\n");
	}
    return 0;
}
