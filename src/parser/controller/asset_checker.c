#include "checker.h"


/*
return 0 si checker good
return > 0 if eror found...
set singleton error
doestn print error
*/
int asset_checker(t_task *liste, char *line)
{
    int i;

    i = -1;
    while (++i < 6)
    {
        if (liste[i].func(line))
        {
            if (liste[i].done && set_sgt_error(E_DUPLI))// duplicata error
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
    set_sgt_error(INV_LN); // invalid line
    return (*sgt_error());
}
