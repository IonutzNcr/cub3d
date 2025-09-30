#include "checker.h"

static int	is_player(char p)
{
	if (p == 'S' || p == 'N' || p == 'E' || p == 'W')
		return (1);
	return (0);
}
static double	get_player_orientation(char p)
{
	if (p == 'S')
		return (-90);
	if (p == 'N')
		return (90);
	if (p == 'E')
		return (0);
	return (180);
}

int	get_player_info(void)
{
	t_player	*player;
	char		**map;
	int			k;
	int			i;
	int			p;

	player = sgt_player();
	map = *sgt_map();
	k = count_elements(map);
	i = 0;
	p = 0;
	while (p < k)
	{
		while (map[p][i])
		{
			if (is_player(map[p][i]))
			{
				player->x = i;
				player->y = p;
				player->orientation = get_player_orientation(map[p][i]);
				map[p][i] = '0';
				return (0);
			}
			i++;
		}
		p++;
		i = 0;
	}
	return (1);
}
