typedef struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monthnum;
} month_t;

int days(char * month);