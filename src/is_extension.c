

int is_extension(int argc, char *argv[], char *env[])
{
    char *pathfile;

    pathfile = argv[1];
    (void)argc;
    (void)env;
    while (*pathfile != '.')
            pathfile++;
    if (pathfile == '\0')
        return (printf("Error: No extension found\n"), 0);
    if (!ft_strncmp(pathfile, ".cub", 4) && ft_strlen(pathfile) == 4)
        return (1);
    return (printf("Error: No .cub extension found\n"), 0);
}