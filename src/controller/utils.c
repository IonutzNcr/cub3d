#include "checker.h"

/*
    print error if there is 
    return the error or 0 if there is no error
*/
int print_error()
{
    int error;
    
    error = *sgt_error();
    if (error == P_NUM)
        write(2, "ERROR: Invalid parameter number\n", 32);
    if (error == NO_ENV)
        write(2, "ERROR: No env found\n", 20);
    if (error == INV_EXT)
        write(2, "ERROR: Invalid file extension\n", 30);
    if (error == E_SCENE)
        write(2, "ERROR: Empty scene\n", 19);
    if (error == E_DUPLI)
        write(2, "ERROR: Double config detected\n", 30);
    if (error == INV_LN)
        write(2, "ERROR: Invalid Line\n", 20);
    if (error == EM_FILE)
        write(2, "ERROR: Empty file detected\n", 27);
    if (error == F_MALL)
        write(2, "ERROR: Malloc Fail\n", 19);
    if (error == NO_WALL)
        write(2, "ERROR: NO WALL DETECTED\n", 24);
    if (error == INV_CH)
        write(2, "ERROR: Invalid character in map\n", 32); 
    if (error == PLY_NB)
        write(2, "ERROR: Too many players\n", 24); 
    if (error == NO_PLY)
        write(2, "ERROR: No player detected\n", 26);
    if (error == NO_FILE)
        write(2, "ERROR: INVALID FILE\n", 20); 
    if (error > 13)
        printf("ERROR %d not detected yet\n", error);
    return (error);
}

/*
    wrapper to getnextline to win some lines
*/
char *wgnl(char **line, int fd)
{
    *line = get_next_line(fd);
    if (*line)
        (*line)[ft_strlen(*line) - 1] = '\0';
    return (*line);
}

void init_list(t_task list[6])
{
    int i;

    i = 0;
    while (i < 6)
        list[i++].done = 0;
    list[0].func = is_texture_NO;
    list[0].parse = parse_NO;
    list[1].func = is_texture_SO;
    list[1].parse = parse_SO;
    list[2].func = is_texture_WE;
    list[2].parse = parse_WE;
    list[3].func = is_texture_EA;
    list[3].parse = parse_EA;
    list[4].func = is_ceiling;
    list[4].parse = parse_ceiling;
    list[5].func = is_floor;
    list[5].parse = is_floor;
}
int empty_gnl(int fd)
{
    char *line;

    while (wgnl(&line, fd))
        free(line);
    return (0);
}