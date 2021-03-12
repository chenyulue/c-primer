#define SIZE 19

typedef struct player_st {
    int player_num;
    struct {
        char first_name[40];
        char last_name[40];
    };
    int bats;
    int hits;
    int walks;
    int RBIs;
    float batavg;
} Player;

int read_info(FILE * fp, Player * players, int num);
void show_info(const Player * players, int num, int total);
char * s_gets(char * str, int num);