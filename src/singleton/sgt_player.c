#include "checker.h"

t_player *sgt_player()
{
    static t_player player;
    return (&player);
}