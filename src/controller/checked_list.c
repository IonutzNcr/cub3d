#include "checker.h"

/*
    return 1 if all task in the list has been done ...abort
    return 0 if there are at least one task undone
    does not set error or print error
*/
int checked_list(t_task *liste[6])
{
    int i;
    
    i = 0;
    while (i < 6)
        if (!liste[i++]->done)
            return (0);
    return (1);
}