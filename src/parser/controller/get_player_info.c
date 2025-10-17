/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:58:32 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/17 16:21:21 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	get_player_utils(t_player *player, char **map, int p, int i)
{
	player->x = i;
	player->y = p;
	player->orientation = get_player_orientation(map[p][i]);
	map[p][i] = '0';
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
	p = -1;
	while (++p < k)
	{
		while (map[p][i])
		{
			if (is_player(map[p][i]))
			{
				get_player_utils(player, map, p, i);
				return (0);
			}
			i++;
		}
		i = 0;
	}
	return (1);
}
