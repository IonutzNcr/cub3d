#ifndef CHECKER_H
    #define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
# include "../libft/libft.h"



enum e_err
{
    P_NUM = 1,
    NO_ENV,
    INV_EXT,
    E_SCENE,
    E_DUPLI,
    INV_LN,
    EM_FILE,
    F_MALL,
    NO_WALL,
    INV_CH,
    PLY_NB,
    NO_PLY,
    NO_FILE,


};

typedef int(*check)(char *line);
typedef int (*mapf)(void);

typedef struct s_task
{
    check func;
    check parse;
    int done;
} t_task;

typedef struct s_map_task
{
    check func;
} t_map_task;

typedef struct s_assets {
    char *file_NO;
    char *file_SO;
    char *file_WE;
    char *file_EA;
    int floor;
    int ceiling;
} t_assets;

typedef struct s_player
{
    double x;
    double y;
    double orientation;
} t_player;

int is_extension(int argc, char *argv[], char *env[]);
int is_file_empty(char *file);
int set_sgt_error(int error);
int *sgt_error();
int *sgt_line();
t_assets *sgt_assets();
char ***sgt_map();
int get_player_info();
t_player *sgt_player();

/*this is ok...*/
int   is_texture_NO(char *line);
int   is_texture_SO(char *line);
int   is_texture_WE(char *line);
int   is_texture_EA(char *line);
int is_ceiling(char *line);
int is_floor(char *line);

int asset_checker(t_task *liste, char *line);

int checked_list(t_task liste[6]);
void free_split(char **arg);
int parse_floor(char *line);
int parse_ceiling(char *line);
int parse_NO(char *line);
int parse_SO(char *line);
int parse_WE(char *line);
int parse_EA(char *line);
int asset_parser(t_task liste[6], char *line);
int is_invalid_space(char ch);
int print_error(void);
void init_list(t_task list[6]);
char *wgnl(char **line, int fd);
int parser(int argc, char *argv[], char *env[]);
int last_verif(t_task liste[6]);
int quick_verif(int argc, char *argv[], char *env[]);
int hard_verif(char *argv[]);
int empty_gnl(int fd);
int mapper(char *line, int fd);

int add_line(char *line);
int remove_map();
void remove_assets();
void free_singleton();
void *ft_remalloc(void *old, int n_size, int old_size);

int map_parser(char *line);
int map_checker();
int count_elements(char **argv);

int check_characters();
char **get_row(int row);
int map_fixer();


#endif
