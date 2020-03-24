#include <stdio.h>

int main(void)
{
    char first_name[30];
    char last_name[30];
    printf("Enter your first name:\n");
    scanf("%s", first_name);
    printf("Enter your last name:\n");
    scanf("%s", last_name);
    printf("%s, %s\n", last_name, first_name);
    return 0;
}
