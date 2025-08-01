#include "checker.h"

int checked_list(t_task *liste[6])
{
    int i;
    
    i = 0;
    while (i < 6)
        if (!liste[i++]->done)
            return (0);
    return (1);
}