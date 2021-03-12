#include <stdio.h>
#include <string.h>

#define eatline while (getchar() != '\n')

/* Masks for the fond ID and font size */
#define IDMASKE 0x000000ff
#define SIZEMASKE 0x00007f00
#define ALIGNMASK 0x00030000
/* Alignment */
#define LEFT 0x00000000
#define CENTER 0x00010000
#define RIGHT 0x00020000
#define UNDEFINED 0x00030000
/* Off and On for the Bold, Italic and Underline */
#define ON 1
#define OFF 0
/* Bold, Italic and Underline */
#define BOLD 0x00040000
#define ITALIC 0x00080000
#define UNDERLINE 0x00100000

struct font_st {
    unsigned int ID        : 8;
    unsigned int size      : 7;
    unsigned int           : 1;
    unsigned int alignment : 2;
    unsigned int bold      : 1;
    unsigned int italic    : 1;
    unsigned int underline : 1;
    unsigned int           : 3;
};

typedef union view_un {
    struct font_st font_prop;
    unsigned int font;
} Font;

void show_font_info(const Font * ft);
int menu(void);
void update(Font * ft, int code);
unsigned int get_number (unsigned int max);
unsigned int get_alignment (char * choices);
void toggle(Font * ft, int code);

int main(void)
{
    Font info = {{1, 12, LEFT, OFF, OFF, OFF}};
    int code;

    show_font_info(&info);
    printf("\n");
    while ((code = menu()) != -1)
    {
        update(&info, code);
        show_font_info(&info);
        printf("\n");
    }

    return 0;
}

void show_font_info(const Font * ft)
{
    char alignment[7];
    switch (ft->font & ALIGNMASK)
    {
        case LEFT: strcpy(alignment, "left"); break;
        case CENTER: strcpy(alignment, "center"); break;
        case RIGHT: strcpy(alignment, "right");
    }
    printf("%3s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%3u %4u %9s %3s %3s %3s\n", ft->font_prop.ID, ft->font_prop.size, alignment,
            ft->font_prop.bold ? "on" : "off", ft->font_prop.italic ? "on" : "off", ft->font_prop.underline ? "on" : "off");
}

int menu(void)
{
    int choice;
    char available_choices[] = "fsabiuq";

    printf("f) change font      s) change size      a) change alignment\n");
    printf("b) toggle bold      i) toggle italic    u) toggle underline\n");
    printf("q) quit\n?> ");
    while ((choice = getchar()) != EOF && choice != 'q')
    {
        if (strchr(available_choices, choice))
        {
            eatline;
            return choice;
        }
        else if (choice == '\n')
            continue;
        else
        {
            eatline;
            printf("Invalid input: only \"%s\" are acceptable.\n", available_choices);
            printf("Enter again (Ctrl+Z or \"q\" to quit)\n?> ");
        }
    }
    return -1;
}

void update(Font * ft, int code)
{
    unsigned int num;
    unsigned int algn;

    switch (code)
    {
        case 'f':
            printf("Enter font ID (0-255): ");
            num = get_number(255);
            ft->font = (ft->font & ~IDMASKE) | num;
            break;
        case 's':
            printf("Enter font size (0-127): ");
            num = get_number(127);
            ft->font = (ft->font & ~SIZEMASKE) | (num << 8);
            break;
        case 'a':
            printf("Select alignment:\n");
            printf("l) left     c) center       r) right\n");
            algn = get_alignment("lcr");
            if (algn != UNDEFINED)
                ft->font = (ft->font & ~ALIGNMASK) | algn;
            break;
        default:
            toggle(ft, code);
    }
}

unsigned int get_number (unsigned int max)
{
    unsigned int ret_num;
    int status;

    while ((status = scanf("%u", &ret_num)) != 1 || ret_num > max)
    {
        char ch;
        if (status != 1)
        {
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number.\n");
        } else
        {
            eatline;
            printf("%u is too large.\n", ret_num);
        }
        printf("Enter a number from 0 to %u: ", max);
    }
    return ret_num;
}

unsigned int get_alignment (char * choices)
{
    char ch;

    while ((ch = getchar()) != EOF)
    {
        eatline;
        switch (ch)
        {
            case 'l':
                return LEFT;
            case 'c':
                return CENTER;
            case 'r':
                return RIGHT;
            case '\n':
                continue;
            default:
                printf("%c is not a valid choice. Only \"%s\" is acceptable.\n", ch, choices);
        }
    }
    return UNDEFINED;
}

void toggle(Font * ft, int code)
{
    switch (code)
    {
        case 'b':
            ft->font ^= BOLD;
            break;
        case 'i':
            ft->font ^= ITALIC;
            break;
        case 'u':
            ft->font ^= UNDERLINE;
    }
}