#include <stdio.h>

int main () {
    
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF)
        cnt += 1;
    printf("Total number of characters: %d\n", cnt);
}
