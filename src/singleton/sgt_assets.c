#include "checker.h"

t_assets *sgt_assets()
{
    static t_assets assets;
    return &assets;
}