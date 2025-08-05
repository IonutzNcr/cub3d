#include "checker.h"


static int fix_length()
{
    int max_lenght;
    char **map;
    char *row;
    int curr_lenght;


    map = *sgt_map();
    max_lenght = find_max_lenght(map);
    while(*map)
    {
        curr_lenght = ft_strlen(*map);
        row = ft_remalloc(*map, max_lenght, curr_lenght);
        if (!row && set_sgt_error(12))// malloc fail...
            return(12);
        fill_row(row, max_lenght);
        free(*map);
        *map = row;
        map++;
    }
    return (0);
}

/*
    REPLACE space by 1 inside the map...
*/
static void replace_space()
{   
    char **map;
    char *row;

    map = sgt_map();
    while (*map)
    {
        row = *map;
        while(*row)
        {
            if (*row == ' ')
                *row = '1';
            row++;
        }
        map++;
    }
}

/*
    ret error if malloc problem or other problem..
    ret 0 if success
*/
int map_fixer()
{
    replace_space();
    if (fix_length())
        return (*sgt_error());
    return (0);
}