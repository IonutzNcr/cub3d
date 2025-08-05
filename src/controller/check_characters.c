#include "checker.h"


/*
    valid ch N S E W 1 0
    ret 1 si c invalid
    ret 0 si c valid
*/
static int is_invalid_ch(char ch)
{
    if (ch == '1' || ch == '0' || ch == 'N' || ch == 'S'
        || ch == 'E' || ch == 'W')
            return (0);
    return (1);
}

static int is_player(char ch)
{
     if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
        return (1);
    return (0);
}

int check_characters()
{
    int cply;
    int k;
    int i;
    char *row;

    i = 0;
    k = count_elements(*sgt_map());
    cply = 0;
    while (i < k)
    {
        row = *get_row(i++);
        while (row && *row)
        {
            if (is_invalid_ch(*row) && set_sgt_error(13))// invalid character in map
                return (*sgt_error());
            if (is_player(*row))
                cply++;
            if (cply > 1 && set_sgt_error(15))// too many player
                return (*sgt_error());
            row++;
        }
    }
    if(cply == 0 && set_sgt_error(16)) // No player detected
        return (*sgt_error());
    return (0);
}
