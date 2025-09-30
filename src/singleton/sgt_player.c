#include "checker.h"

t_player	*sgt_player(void)
{
	static t_player player;
	return (&player);
}