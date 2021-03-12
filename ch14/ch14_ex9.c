#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAPACITY 12
#define FLTNUM 4

typedef struct name_st {
    char first[40];
    char last[40];
} Name;

typedef struct seat_st {
    Name name;
    char id[3];
    bool assigned;
} Seat;

void top_menu(void);
void sub_main(Seat seatarr[][CAPACITY], char code);
void menu(char code);
int show_empty(const Seat seats[], int num, bool list);
void show_seats(const Seat seats[], int num);
void assign_seat(Seat seats[], int num);
void delete_assignment(Seat seats[], int num);
void confirm_assignment(Seat seats[], int num);
char * get_name (const Seat * s);
char * s_gets(char * st, int n);

int main(void)
{
    Seat seatarr[FLTNUM][CAPACITY];
    FILE * pseat;
    int count = 0;
    char code[2];
    char * s;

    if ((pseat = fopen("flights.dat", "r+b")) == NULL)
    {
        if ((pseat = fopen("flights.dat", "w+b")) == NULL)
        {
            fputs("Can't open the seats.dat file", stderr);
            exit(EXIT_FAILURE);
        }
        printf("Enter the seat ID:\n");
        while (count < CAPACITY)
        {
            char id[3];
            scanf("%s", id);
            for (int i = 0; i < FLTNUM; i++)
            {
                strcpy(seatarr[i][count].id, id);
                seatarr[i][count].name.first[0] = '\0';
                seatarr[i][count].name.last[0] = '\0';
                seatarr[i][count].assigned = false;
            }
            count++;
        }
        while (getchar() != '\n')
            continue;
    } else
    {
        /*for (int i = 0; i < FLTNUM; i++)
        {
            while (count < CAPACITY && fread(&seatarr[i][count], sizeof (Seat), 1, pseat) == 1)
            {
                count++;
            }            
        }*/
        fread(seatarr, sizeof (Seat), CAPACITY * FLTNUM, pseat);
    }
    top_menu();
    while ((s = s_gets(code, 2)) != NULL && tolower(code[0]) != '5')
    {
        if (code[0] != '1' && code[0] != '2' && code[0] != '3' && code[0] != '4')
        {
            printf("Only 1 to 5 are allowed. Input Again: ");
            continue;
        }
        printf("\n");
        sub_main(seatarr, code[0]);
        top_menu();
    }
   
    fseek(pseat, 0, SEEK_SET);
    fwrite(seatarr, sizeof (Seat), CAPACITY * FLTNUM, pseat);
    if (fclose(pseat) != 0)
        fputs("Error in closing the file seats.dat.\n", stderr);
    printf("Bye!\n");

    return 0;
}

void sub_main(Seat seatarr[][CAPACITY], char choice)
{
    char * s;
    char code[2];
    char ch[] = {choice, '\0'};
    int index = atoi(ch) - 1;

    menu(choice);
    while ((s = s_gets(code, 2)) != NULL && tolower(code[0]) != 'g')
    {
        switch (tolower(code[0]))
        {
            case 'a':
                printf("The number of empty seats is %d.\n", show_empty(seatarr[index], CAPACITY, 0));
                printf("\n");
                menu(choice);
                break;
            case 'b':
                printf("The list of empty seats are:\n");
                show_empty(seatarr[index], CAPACITY, 1);
                printf("\n");
                menu(choice);
                break;
            case 'c':
                printf("%-10s %-20s %-5s\n", "ID", "Holder Name", "Assigned");
                printf("=========================================\n");
                show_seats(seatarr[index], CAPACITY);
                printf("\n");
                menu(choice);
                break;
            case 'd':
                assign_seat(seatarr[index], CAPACITY);
                printf("\n");
                menu(choice);
                break;
            case 'e':
                delete_assignment(seatarr[index], CAPACITY);
                printf("\n");
                menu(choice);
                break;
            case 'f':
                confirm_assignment(seatarr[index], CAPACITY);
                printf("\n");
                menu(choice);
                break;
            case '\n':
                continue;
        }
    }
}

void top_menu(void)
{
    printf("Choose your flights:\n");
    printf("1) Flight 102       2) Flight 311\n");
    printf("3) Flight 444       4) Flight 519\n");
    printf("5) Quit\n");
    printf("Which flight? ");
}

void menu(char code)
{
    char flights[15];
    switch (code)
    {
        case '1': strcpy(flights, "Flight 102"); break;
        case '2': strcpy(flights, "Flight 311"); break;
        case '3': strcpy(flights, "Flight 444"); break;
        case '4': strcpy(flights, "Flight 519");
    }
    printf("The chosen flights is %s.\nTo choose a function, enter its letter label:\n", flights);
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Confirm a seat assignment\n");
    printf("g) Quit\n");
    printf("Enter your choice: ");
}

int show_empty(const Seat seats[], int num, bool list)
{
    int empty_total = 0;
    int i;

    for (i = 0; i < num; i++)
    {
        if (!(seats[i].assigned))
        {
            empty_total++;
            if (list)
            {
                printf("%s\n", seats[i].id);
            }
        }
    }

    return empty_total;
}
void show_seats(const Seat seats[], int num)
{
    int i, j;
    const Seat *seatp[CAPACITY];
    char * name;

    for (i = 0; i < num; i++)
        seatp[i] = &seats[i];
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(seatp[i]->id, seatp[j]->id) > 0)
            {
                const Seat * tmp = seatp[j];
                seatp[j] = seatp[i];
                seatp[i] = tmp;
            }
        }
    }
    for (i = 0; i < num; i++)
    {   name = get_name(seatp[i]);
        printf("%-10s %-20s %-5s\n", seatp[i]->id, name, seatp[i]->assigned ? "true" : "false");
        free(name);
    }
}
void assign_seat(Seat seats[], int num)
{
    int empty, i;
    char order[3], yes[2];
    char * s;
    
    printf("The list of empty seats:\n");
    empty = show_empty(seats, num, true);
    if (!empty)
    {
        printf("No empty seats available.\nBye!");
        return;
    }
    tryagain: printf("Enter the seat ID to order (Ctrl+Z to abort):  ");
    while ((s = s_gets(order, 3)) != NULL && order[0] == '\0')
        continue;
    if (s == NULL)
        return;
    for (i = 0; i < num; i++)
    {
        if (strcmp(order, seats[i].id) == 0 && seats[i].assigned == false)
        {
            printf("The seat %s is available. \nYes (y) to order / No (n) to abort. ", order);
            while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
                continue;
            if (s == NULL)
                return;
            if (tolower(yes[0]) == 'y')
            {
                seats[i].assigned = true;
                printf("Enter your first name and last name: ");
                scanf("%s %s", seats[i].name.first, seats[i].name.last);
                while (getchar() != '\n')
                    continue;
                printf("Reservation Done!\n");
                return;
            } else
                return;
        } else if (strcmp(order, seats[i].id) == 0)
        {
            printf("The seat %s is not avaible.\nBye!\n", order);
            return;
        }
    }
    printf("The seat id doesn't exist. Try again (y/n): ");
    while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
        continue;
    if (s == NULL)
        return;
    if (tolower(yes[0]) == 'y')
        goto tryagain;
    else
        return;

}
void delete_assignment(Seat seats[], int num)
{
    char id[3], yes[2];
    char * s;
    int i;

    tryagain: printf("Enter the seat ID you want to delete (Ctrl + Z to abort): ");
    while ((s = s_gets(id, 3)) != NULL && id[0] == '\0')
        continue;
    if (s == NULL)
        return;
    for (i = 0; i < num; i++)
    {
        if (strcmp(id, seats[i].id) == 0 && seats[i].assigned)
        {
            char first[40], last[40];
            
            printf("Please enter your full name to validation: ");
            scanf("%s %s", first, last);
            while (getchar() != '\n')
                continue;
            if (strcmp(first, seats[i].name.first) == 0 && strcmp(last, seats[i].name.last) == 0)
            {
                seats[i].assigned = false;
                seats[i].name.first[0] = '\0';
                seats[i].name.last[0] = '\0';
                printf("Delete Done!\n");
                return;
            } else
            {
                printf("The name entered does not conform to the information reserved.\nBye.\n");
                return;
            }
        } else if (strcmp(id, seats[i].id) == 0)
        {
            printf("The seat is not reserved. Please check your input.\nBye!\n");
            return;
        }
    }
    printf("The seat ID doesn't exist. Try again (y/n): ");
    while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
        continue;
    if (s == NULL)
        return;
    if (tolower(yes[0]) == 'y')
        goto tryagain;
    else
        return;    

}

void confirm_assignment(Seat seats[], int num)
{
    char first[40], last[40];
    int i;

    printf("Input your full name to confirm your seat assignment:\n");
    scanf("%s %s", first, last);
    while (getchar() != '\n')
        continue;
    for (i = 0; i < num; i++)
    {
        if (!strcmp(seats[i].name.first, first) && !strcmp(seats[i].name.last, last) && seats[i].assigned)
        {   
            printf("The seat %s has been reserved for you.\n", seats[i].id);
            return;
        }
    }
    printf("You has not made a reservation for the seat.\n");
}

char * get_name(const Seat * s)
{
    const char * first = s->name.first;
    const char * last = s->name.last;
    char * name = malloc(sizeof(first) + sizeof(last) + 2);

    strcpy(name, first);
    strcat(name, " ");
    strcat(name, last);

    return name;
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