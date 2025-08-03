
#include "checker.h"

int *sgt_error()
{
    static int error;
    return &error;
}
int set_sgt_error(int error)
{
    *sgt_error() = error;
    return (1);
}
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
    return (error);
}
/*
    RETURN 0 if everything is good return > 0 if error
    print_error cos is a manager ...
*/
int quick_verif(int argc, char *argv[], char *env[])
{
    if (argc != 2 && set_sgt_error(1));
        return (print_error());// Invalid parameter number
    if (!env && set_sgt_error(2))
        return (print_error());// No env found
    if (!is_extension(argc, argv, env) && set_sgt_error(3))
        return (print_error()); // Invalid file extensioin
    if (is_file_empty(argv[1]) && set_sgt_error(4))//potentiellement pb car je check pas s fd fail...
        return (print_error()); // Empty Scene
    return (0);
}

void init_list(t_task *list[6])
{
    int i;

    i = 0;
    while (i < 6)
        list[i]->done = 0;
    list[0]->func = is_texture_NO;
    list[0]->parse = parse_NO;
    list[1]->func = is_texture_SO;
    list[1]->parse = parse_SO;
    list[2]->func = is_texture_WE;
    list[2]->parse = parse_WE;
    list[3]->func = is_texture_EA;
    list[3]->parse = parse_EA;
    list[4]->func = is_ceiling;
    list[4]->parse = parse_ceiling;
    list[5]->func = is_floor;
    list[5]->parse = is_floor;
}

int wgnl(char **line, int fd)
{
    *line = get_next_line(fd);
    return (*line);
}

/*
    check if the list is complete and if the map exist
    return 0 if success
    return 1 if fail
    set error to corresponding error
*/
int last_verif(t_task *liste[6])
{
    if(!checked_list(liste))
        return (set_sgt_error(10));// incomplete config file;
    if (!sgt_map())
        return (set_sgt_error(11)); //missing map
    return (0);

}
/*
    should return 0 if good
    return err if error...
    print err that it...
*/
int hard_verif(int argc, char *argv[], char *env[])
{
    int fd;
    t_task *liste[6];
    char *line;

    init_list(liste);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (perror("Error: "), 1);
    while (wgnl(&line, fd))
    {
        if (*line == '\0')
        {
            free(line);
            continue;
        }
        if (checked_list(liste))
        {
            if(!map_parser(line, fd))
                return(1);
        } 
        else
        {
            if (!asset_checker(liste, line))
            {
                if(!asset_parser(liste, line))
                    return (free(line), empty_gnl(fd), print_error());
            }
            else
                return (free(line), empty_gnl(fd), print_error());
        }
        free(line);
    }
    //TODO:: ici je dois faire plus de verif car potentiellement problematique
    if(last_verif(liste))
        return (print_error());
    return (0);
}

/*
    return 0 if success
    return err if fail
*/
int controller_parser(int argc, char *argv[], char *env[])
{
    int *error;

    error = sgt_error();
    if (quick_verif(argc, argv, env))
        return (*error);
    if (hard_verif(argc, argv, env))
        return (*error);
    return (0);
}