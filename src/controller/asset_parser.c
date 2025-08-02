#include "checker.h"


int asset_parser(t_task *liste[6], char *line)
{
    int i;

    i = 0;
    while (i < 6)
    {
        if (liste[i]->done == 1)
        {
            if (liste[i]->parse(line))
                return (print_error(), 0);
            liste[i]->done++;
            return(1);
        }
        i++;
    }
    set_sgt_error(12);//asset parser error means duplicata i guess...
    return (0);
}