#include "checker.h"

int sgt_assets()
{
    static t_assets assets;
    return &assets;
}