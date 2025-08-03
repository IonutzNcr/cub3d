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
    close(fd);
    assets = sgt_assets();
    assets->file_NO = ft_strdup(line);
    if (!assets->file_NO && set_sgt_error(F_MALL))//malloc fail
        return (*sgt_error());
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
    close(fd);
    assets = sgt_assets();
    assets->file_SO = ft_strdup(line);
    if (!assets->file_SO && set_sgt_error(F_MALL))//malloc fail
        return (*sgt_error());
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
    close(fd);
    assets = sgt_assets();
    assets->file_WE = ft_strdup(line);
    if (!assets->file_WE && set_sgt_error(F_MALL))//malloc fail
        return (*sgt_error());
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
    close(fd);
    assets = sgt_assets();
    assets->file_EA = ft_strdup(line);
    if (!assets->file_EA && set_sgt_error(F_MALL))//malloc fail
        return (*sgt_error());
    return (0);
}