/*
 * Write a program that implements a menu by using an array of pointers to
 * functions. For instance, choosing a from the menu would activate the function
 * pointed to by the first element of the array
 */

#include <stdio.h>

void hello_english(void);
void hello_spanish(void);
void hello_french(void);

int main (void)
{
    char ch;
    void (*p[3]) (void);
    p[0] = hello_english;
    p[1] = hello_spanish;
    p[2] = hello_french;
    printf("Choose a language:\n"
           "a) English\n"
           "b) Spanish\n"
           "c) French\n"
          );
    ch = getchar(); 
    while (ch < 'a' || ch > 'c')
    {
        while (getchar() != '\n')
            continue;
        printf("Invalid input - try again: ");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;
    int idx = ch - 'a';
    (*p[idx])();
    return 0;
}

void hello_english(void)
{
    printf("Hello, world!\n");
    return;
}

void hello_spanish(void)
{
    printf("Hola, mundo!\n");
    return;
}

void hello_french(void)
{
    printf("Bonjour, le monde!\n");
    return;
}
