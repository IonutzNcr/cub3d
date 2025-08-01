#include "checker.h"

/* int parser_regex(char *reg, char *line)
{
    
} */



void fill_assets_texture(int fd, char *direction, t_assets *assets)
{
    if (!ft_strncmp(direction, "NO", 2))
        assets->fd_NO = fd;
    if (!ft_strncmp(direction, "SO", 2))
        assets->fd_SO = fd;
    if (!ft_strncmp(direction, "WE", 2))
        assets->fd_WE = fd;
    if (!ft_strncmp(direction, "EA", 2))
        assets->fd_EA = fd;
}

int checker(char *line, char *direction, t_assets *assets)
{
    
}

