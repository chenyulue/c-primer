#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

typedef struct book_st {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} Book;
char * s_gets(char * st, int n);
void update(Book * book);

int main(void)
{
    Book library[MAXBKS];
    int count = 0, deleted = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (Book);
    int choice;

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        if ((pbooks = fopen("book.dat", "w+b")) == NULL)
        {   
            fprintf(stderr, "Can't open book.dat file.\n");
            exit(1);
        }
    }

    rewind(pbooks);
    puts("Current contents of book.dat:");
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author,
                library[count].value);
        count++;
        printf("Delete(D) or modify(M) it? (<Enter> to skip) ");
        while ((choice = toupper(getchar())) != 'D' && choice != 'M' && choice != '\n')
        {
            printf("Enter D or M (<Enter> to skip): ");
        }
        switch (choice)
        {
            case 'D': 
                count--;
                deleted++;
                while (getchar() != '\n')
                    continue;
                break;
            case 'M': 
                while (getchar() != '\n')
                    continue;
                update(&library[count]); 
                break;
            case '\n': 
                break;
        }
    }
    if (deleted > 0)
    {
        fseek(pbooks, 0, SEEK_SET);
        fwrite(library, size, count, pbooks);
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.data file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    puts("Press <Enter> at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
            library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
                    library[index].value);
        fwrite(&library[filecount], size, count - filecount, pbooks);
    } else
    {
        puts("No books? Too bad.\n");
    }
    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void update(Book * book)
{
    char title[40];
    char author[40];
    float value;

    printf("Enter the new title, author and value by order (<Enter> at a newline to skip)\n");
    s_gets(title, 40);
    s_gets(author, 40);
    if (title[0] != '\0')
        strcpy(book->title, title);
    if (author[0] != '\0')
        strcpy(book->author, author);
    if (scanf("%f", &value) == 1)
        book->value = value;
    while (getchar() != '\n')
        continue;
}