#include "checker.h"

/*
    check extension is .cub
    print errors...
    used in quick_verif
    return 0 if error
    retirm 1 if success
*/
int is_extension(int argc, char *argv[], char *env[])
{
    char *pathfile;

    pathfile = argv[1];
    (void)argc;
    (void)env;
    while (*pathfile && *pathfile != '.')
            pathfile++;
    if (pathfile == '\0')
        return (write(2,"Error: No extension found\n", 26), 0);
    if (!ft_strncmp(pathfile, ".cub", 4) && ft_strlen(pathfile) == 4)
        return (1);
    return (write(2,"Error: No .cub extension found\n", 31), 0);
}