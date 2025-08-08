#include "checker.h"


/*
    check the last colon to see if is only composed by 1 = wall
    return 0 if succes
    return 1 if failure
*/
int is_lc_wall()
{
    char **map;
    int i;
    int k;
    int j;

    i = 0;
    map = *sgt_map();
    j = ft_strlen(map[0]);
    k = count_elements(map);
    while (i < k)
        if(map[i++][j - 1] != '1')
            return (1);
    return (0);
}

/*
    check the first colon to see if is only composed by 1 = wall
    return 0 if succes
    return 1 if failure
*/
int is_c1_wall()
{
    char **map;
    int k;

    map = *sgt_map();
    k = count_elements(map);
    while (k--)
        if(map[k][0] != '1')
            return (1);
    return (0);
}
/*
    check the last row to see if is only composed by 1 = wall
    return 0 if succes
    return 1 if failure
*/
int is_lr_wall()
{
    char **map;
    int i;
    int k;

    i = 0;
    map = *sgt_map();
    k = count_elements(map);
    while (map[k - 1][i])
        if(map[k - 1][i++] != '1')
            return (1);
    return (0);
}
/*
    check the first row to see if is only composed by 1 = wall
    return 0 if succes
    return 1 if failure
*/
int is_r1_wall()
{
    char **map;
    int i;

    i = 0;
    map = *sgt_map();
    while (map[0][i])
        if(map[0][i++] != '1')
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
        set_sgt_error(NO_WALL);// Missing walls;
        return (*sgt_error());
    }
    return (0);
}

static void init_map_list(mapf *liste)
{
    liste[0] = check_walls;
    liste[1] = check_characters;
}

int map_checker()
{
    mapf liste[2];
    int i;

    i = 0;
    init_map_list(liste);
    while (i < 2)
        if (liste[i++]())
            return (*sgt_error());
    return (0);
}