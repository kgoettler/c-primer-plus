/*
 * Design a bit-field structure that holds the following information
 *
 * Font ID: A number in [0, 255]
 * Font Size: A number in [0, 127]
 * Alignment: A number in the range [0, 2] representing the choices Left,
 * Center, and Right
 * Bold: Off (0) or on (1)
 * Italic: Off (0) or on (1)
 * Underline: Off (0) or on (1)
 *
 * Use this structure in a program that displays the font parameters and uses a
 * looped menu to let the user change parameters. For example, a sample run
 * might look like this:
 *
 * ID  SIZE  ALIGNMENT   B   I   U
 *  1    12       left  off off off
 * f) change font     s) change size     a) change alignment
 * b) toggle bold     i) toggle italic   u) toggle underline
 *
 * The program should use the & operator and suitable masks to ensure that the
 * ID and size entries are converted to the specified range
 */

#include <stdio.h>
#include <limits.h>

enum {
    LEFT=0,
    CENTER=1,
    RIGHT=2,
};

struct font {
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

int process_input(struct font * f, char inp);
void show_menu(void);
void show_font(struct font * f);

int main (void)
{
    int res, inp;
    struct font f = {1, 12, CENTER, 0, 1, 0};
    res = 1;
    while (res == 1)
    {
        show_font(&f);
        show_menu();
        inp = getchar();
        while (getchar() != '\n')
            continue;
        res = process_input(&f, inp);
    }
    return 0;
}

int process_input(struct font * f, char inp)
{
    unsigned int val;
    switch (inp)
    {
        case 'f':
            while (1)
            {
                printf("Enter the font ID (0 - 255): ");
                scanf("%d", &val);
                while (getchar() != '\n')
                    continue;
                if (val < 0 || val > 255)
                    printf("Invalid input\n");
                else
                    break;
            }
            f->id = val;
            break;
        case 's':
            while (1)
            {
                printf("Enter font size (0-127): ");
                scanf("%d", &val);
                while (getchar() != '\n')
                    continue;
                if (val < 0 || val > 127)
                    printf("Invalid input\n");
                else
                    break;
            }
            f->size = val;
            break;
        case 'a':
            while (1)
            {
                printf("Select alignment:\n");
                printf("l) left  c) center  r) right\n");
                scanf("%d", &val);
                if (val == 'l')
                {
                    val = LEFT;
                    break;
                }
                else if (val == 'c')
                {
                    val = CENTER;
                    break;
                }
                else if (val == 'r')
                {
                    val = RIGHT;
                    break;
                }
                else
                    printf("Invalid input\n");
            }
            f->alignment = val;
            break;
        case 'b':
            f->bold = ~f->bold;
            break;
        case 'i':
            f->italic = ~f->italic;
            break;
        case 'u':
            f->underline = ~f->underline;
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid input. Try again\n");
    }
    return 1;
}

void show_menu(void)
{
    printf("  f) change font     s) change size     a) change alignment\n"
           "  b) toggle bold     i) toggle italic   u) toggle underline\n");
    return;
}

void show_font(struct font * f)
{
    printf(" ID  SIZE  ALIGNMENT   B   I   U\n");
    printf("%3d %4d   ", f->id, f->size);
    if (f->alignment == 0)
        printf("     left ");
    else if (f->alignment == 1)
        printf("   center ");
    else
        printf("    right ");

    if (f->bold)
        printf(" on ");
    else
        printf(" off ");
    if (f->italic)
        printf(" on ");
    else
        printf("off ");
    if (f->underline)
        printf(" on ");
    else
        printf("off ");
    printf("\n");
    return;
}

