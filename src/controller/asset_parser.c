#include "checker.h"

/*
    return 0 if is good
    return err if is bad
    does not set up error because it is managed by the parses func.
*/
int asset_parser(t_task *liste[6], char *line)
{
    int i;

    i = 0;
    while (i < 6)
    {
        if (liste[i]->done == 1)
        {
            if (liste[i]->parse(line))
                return (*sgt_error());
            liste[i]->done++;
            return(0);
        }
        i++;
    }
    set_sgt_error(E_DUPLI);//asset parser error means duplicata i guess...
    return (*sgt_error());
}