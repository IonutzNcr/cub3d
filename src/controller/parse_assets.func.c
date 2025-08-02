#include "checker.h"

//iif there are other sgn_assets this one is the right one
int sgt_assets()
{
    static t_assets assets;
    return &assets;
}

//return 0 if success return 0 > if fail..
int parse_NO(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    assets = sgt_assets();
    assets->fd_NO = fd;
    return (0);
}

int parse_SO(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    assets = sgt_assets();
    assets->fd_SO = fd;
    return (0);
}

int parse_WE(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    assets = sgt_assets();
    assets->fd_WE = fd;
    return (0);
}
int parse_EA(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    assets = sgt_assets();
    assets->fd_EA = fd;
    return (0);
}