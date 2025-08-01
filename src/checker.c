#include "checker.h"

/*
give the actual line wich is parse
*/
int *sgt_line()
{
    static int line;
    return &line;
}

/*
return 0 si checker good else if not 
*/
int asset_checker(t_task *liste, char *line)
{
    int i;

    i = 0;
    while (i < 6)
    {
        if (!liste[i].func(line))
        {
            if (liste[i].done && set_sgt_error(5))// duplicata error
                return (*sgt_error());
            else
            {
                liste[i].done = 1;
                return (0);
            }
        }
        else
            continue;
    }
    set_sgt_error(6); // invalid line
    return (*sgt_error());
}
