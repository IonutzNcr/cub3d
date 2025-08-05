#include "checker.h"

/*
    remalloc and copy the old array content inside a new one 
    return the new one or NULL if fail
    note: does not free the old one is your job to free it
*/
void *ft_remalloc(void *old, int n_size, int old_size)
{
    void *map;
    unsigned char *dest;
    unsigned char *src;  

    src = old;
    map = malloc(n_size);
    if (!map)
        return (0);
    dest = map;
    while (old_size--)
        dest[old_size] = src[old_size];
    return (map); 
}

/*
    return l'addresse du pointeur de la row.. 
    return null if row not inside the map...

*/
char **get_row(int row)
{
    char **map;
    int k;

    map = *sgt_map();
    k = count_elements(map);
    if (row > k - 1)
        return (NULL);
    return (&map[row]);
}

/*
    always return 0 
    solo purpose is to free the map using the singleton
*/
int remove_map()
{
    char **map;
    int i;

    i = 0;
    map = *sgt_map();
    if (!map)
        return (0);
    while (map[i])
        free(map[i++]);
    free(map);
    *sgt_map() = 0;
    return (0);
}
/*
    add a line to the map
    return err if fail to malloc
    return 0 in case of success
*/
int add_line(char *line)
{
    char **map;
    int nb;

    if(!*sgt_map())
    {
        map = malloc(sizeof(char *) * (1 + 1));
        if (!map)
            return (10);//malloc fail
        *map = line;
        *(map + 1) = 0;
        *sgt_map() = map;
    }
    else
    {
        nb = count_elements(*sgt_map());
        map = ft_remalloc(*sgt_map(), (nb + 1) * sizeof(char *), nb * sizeof(char *));
        if (!map)
            return (10);//malloc fail
        free(*sgt_map());
        map[nb] = line;
        map[nb+1] = 0;
        *sgt_map() = map;
    }
}

/*
    return the adresse of a pointer to a pointer
*/
char ***sgt_map()
{
    static char **map;
    return (&map);
}

