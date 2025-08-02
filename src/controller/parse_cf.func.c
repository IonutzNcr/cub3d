#include "checker.h"

//return 0 if success return 0 > if fail..
int parse_floor(char *line)
{
    int cmb;
    char **rgb;
    int i;
    char tmp;
    t_assets *assets;

    i = 0;
    while(*line && !ft_isdigit(*line))
        line++;
    assets = sgt_assets();
    //assets->floor = -1;
    while (line[i] != ' ' && line[i] != '\0')
        i++;
    tmp = line[i];
    line[i] = '\0';
    rgb = ft_split(line, ',');
    line[i] = tmp;
    if (!rgb && set_sgt_error(10)) //Malloc failed
        return (1);
        
    return (0);
}
