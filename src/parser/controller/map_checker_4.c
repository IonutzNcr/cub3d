/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:56:54 by yoyo              #+#    #+#             */
/*   Updated: 2025/11/05 22:04:43 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_walls(void)
{
	char		**map;
	char		**map_tmp;
	t_player	player;
	int			is_out;

	get_player_info();
	map = *sgt_map();
	map_tmp = copy_map(map);
	if (!map_tmp && set_sgt_error(F_MALL))
		return (*sgt_error());
	player = *sgt_player();
	is_out = 0;
	ft_searchpath(player.x, player.y, map_tmp, &is_out);
	while (!is_out)
	{
		player = find_new_zero(map_tmp);
		if (player.x == 0 && player.y == 0)
			break ;
		ft_searchpath(player.x, player.y, map_tmp, &is_out);
	}
	ft_free_map_null(map_tmp);
	if (is_out && set_sgt_error(NO_WALL))
		return (*sgt_error());
	return (0);
}

int	can_move(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'N'
		|| map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == '-')
		return (1);
	return (0);
}

int	is_on_edge(int x, int y)
{
	char	**map;
	int		width;
	int		height;

	map = *sgt_map();
	width = ft_strlen(map[0]);
	height = count_elements(map);
	if (x == 0 || x == width || y == height || y == 0)
		return (1);
	return (0);
}

void	ft_searchpath(int x, int y, char **map, int *is_out)
{
	while (1)
	{
		if ((map[y][x] == '-' || is_on_edge(x, y)) && ++(*is_out))
			break ;
		if (map[y][x] == '1')
			break ;
		if (can_move(x, y, map))
			map[y][x] = '1';
		if (can_move(x + 1, y, map))
			ft_searchpath(x + 1, y, map, is_out);
		if (can_move(x - 1, y, map))
			ft_searchpath(x - 1, y, map, is_out);
		if (can_move(x, y + 1, map))
			ft_searchpath(x, y + 1, map, is_out);
		if (can_move(x, y - 1, map))
			ft_searchpath(x, y - 1, map, is_out);
		break ;
	}
}
