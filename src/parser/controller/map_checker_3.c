/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:53:10 by yoyo              #+#    #+#             */
/*   Updated: 2025/11/05 22:02:35 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_free_map_null(char **map)
{
	char	**tmp;

	if (map)
	{
		tmp = map;
		while (*tmp)
			free(*tmp++);
		free(map);
	}
	return (0);
}

char	**copy_map(char **map)
{
	int		i;
	int		y;
	char	**copy;

	y = count_elements(map);
	copy = malloc(sizeof(char *) * (y + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < y)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (ft_free_map_null(copy));
		i++;
	}
	copy[i] = 0;
	return (copy);
}

static void	set_player(t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
	player->orientation = 0;
}

t_player	find_new_zero(char **map)
{
	int			y;
	int			x;
	t_player	player;
	int			k;

	k = count_elements(map);
	y = 0;
	x = 0;
	while (y < k)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				set_player(&player, x, y);
				return (player);
			}
			x++;
		}
		y++;
	}
	set_player(&player, 0, 0);
	return (player);
}
