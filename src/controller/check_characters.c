#include "checker.h"


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
        row = get_row(i++);
        while (*row)
        {
            if (is_invalid_ch(*row) && set_sgt_error(13))// invalid character in map
                return (*sgt_error());
            if (is_character(*row))
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
