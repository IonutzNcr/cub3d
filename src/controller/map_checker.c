#include "checker.h"



int is_lc_wall()
{
    char **map;
    int i;
    int k;

    k = count_elements(map);
    i = 0;
    map = *sgt_map();
    while (map[k][i])
        if(map[k][i++] != 1)
            return (1);
    return (0);
}

int is_c1_wall()
{
    char **map;
    int k;

    k = count_elements(map);
    map = *sgt_map();
    while (k--)
        if(map[k][0] != 1)
            return (1);
    return (0);
}

int is_lr_wall()
{
    char **map;
    int i;
    int k;

    k = count_elements(map);
    i = 0;
    map = *sgt_map();
    while (map[k][i])
        if(map[k][i++] != 1)
            return (1);
    return (0);
}

int is_r1_wall()
{
    char **map;
    int i;

    i = 0;
    map = *sgt_map();
    while (map[0][i])
        if(map[0][i++] != 1)
            return (1);
    return (0);
}
/*
    check if r1 lr and c1 and cl are only 1 == wall
    return err if no and set sgt_error to the corresponding error
    return 0 if success
*/
int check_walls()
{
    if (is_r1_wall() || is_lr_wall() || is_c1_wall() || is_lc_wall())
    {
        set_sgt_error(15);// Missing walls;
        return (*sgt_error());
    }
    return (0);
}



int map_checker()
{
    mapf liste[5];
    int i;

    i = 0;
    init_map_list(liste);
    while (i < 5)
        if (liste[i]())
            return (*sgt_error());
    return (0);
}