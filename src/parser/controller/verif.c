#include "checker.h"

/*
    RETURN 0 if everything is good return > 0 if error
    print_error cos is a manager ...
*/
int quick_verif(int argc, char *argv[], char *env[])
{
    if (argc != 2 && set_sgt_error(P_NUM))
        return (print_error());// Invalid parameter number
    if (!env && set_sgt_error(NO_ENV))
        return (print_error());// No env found
    if (!is_extension(argc, argv, env) && set_sgt_error(INV_EXT))
        return (print_error()); // Invalid file extensioin
    if (is_file_empty(argv[1]) && set_sgt_error(E_SCENE))//potentiellement pb car je check pas s fd fail...
        return (print_error()); // Empty Scene
    return (0);
}

/*
    check if the list is complete and if the map exist
    return 0 if success
    return 1 if fail
    set error to corresponding error
*/
int last_verif(t_task liste[6])
{
    if(!checked_list(liste))
        return (set_sgt_error(10));// incomplete config file;
    if (!*sgt_map())
        return (set_sgt_error(11)); //missing map
    return (0);

}
/*
    should return 0 if good
    return err if error...
    print err that it...
*/
int hard_verif(char *argv[])
{
    int fd;
    t_task liste[6];
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
            if(mapper(line, fd))
                return(1);
        } 
        else
        {
            if (!asset_checker(liste, line))
            {
                if(asset_parser(liste, line))
                    return (remove_assets() ,free(line), empty_gnl(fd), print_error());
            }
            else
                return (remove_assets(), free(line), empty_gnl(fd), print_error());
            free(line);
        }
    }
    if(last_verif(liste))
        return (free_singleton(), print_error());
    return (0);
}
