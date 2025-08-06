#include "checker.h"

/*
    return err if error
    return 0 if good
*/
int mapper(char *line, int fd)
{
    if (map_parser(line))
        return(free(line), empty_gnl(fd), print_error());
    free(line);
    while (wgnl(&line, fd))
    {
        if (*line == '\0' && set_sgt_error(13)) // empty line in map
            return (free_singleton() ,*sgt_error());
        if (map_parser(line))
            return(free_singleton() ,free(line), empty_gnl(fd), print_error());
        free(line);
    }
    if (map_fixer() || map_checker())
        return (free_singleton(), print_error());
    return (0);
}
