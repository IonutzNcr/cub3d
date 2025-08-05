void free_split(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
        free(arg[i++]);
    free(arg);
}

int count_elements(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    return (i);
}