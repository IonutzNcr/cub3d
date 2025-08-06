#include "checker.h"



void remove_assets()
{
    t_assets *assets;

    assets = sgt_assets();
    if(assets->file_EA)
        free(assets->file_EA);
    if(assets->file_NO)
        free(assets->file_NO);
    if(assets->file_SO)
        free(assets->file_SO);
    if(assets->file_WE)
        free(assets->file_WE);
}

t_assets *sgt_assets()
{
    static t_assets assets;
    return &assets;
}