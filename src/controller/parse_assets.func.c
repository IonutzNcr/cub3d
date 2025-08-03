#include "checker.h"

/*
    return 0 if success
    return err if error found...
    set sgt error 
    set assets sgt if no error
*/
int parse_NO(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    if (is_file_empty(line) && set_sgt_error(EM_FILE))//empty .xmp file
        return (close(fd), *sgt_error());
    assets = sgt_assets();
    assets->fd_NO = fd;
    return (0);
}
/*
    return 0 if success
    return err if error found...
    set sgt error 
    set assets sgt if no error
*/
int parse_SO(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    if (is_file_empty(line) && set_sgt_error(EM_FILE))//empty .xmp file
        return (close(fd), *sgt_error());
    assets = sgt_assets();
    assets->fd_SO = fd;
    return (0);
}
/*
    return 0 if success
    return err if error found...
    set sgt error 
    set assets sgt if no error
*/
int parse_WE(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    if (is_file_empty(line) && set_sgt_error(EM_FILE))//empty .xmp file
        return (close(fd), *sgt_error());
    assets = sgt_assets();
    assets->fd_WE = fd;
    return (0);
}
/*
    return 0 if success
    return err if error found...
    set sgt error 
    set assets sgt if no error
*/
int parse_EA(char *line)
{
    int fd;
    t_assets *assets;

    while(*line && (*line != '/' && *line != '.' ))
        line++;
    fd = open(line, O_RDONLY);
    if (fd == -1 && set_sgt_error(8))// FAIIL TO OPEN ASSETS
        return (*sgt_error());
    if (is_file_empty(line) && set_sgt_error(EM_FILE))//empty .xmp file
        return (close(fd), *sgt_error());
    assets = sgt_assets();
    assets->fd_EA = fd;
    return (0);
}