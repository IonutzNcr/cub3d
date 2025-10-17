/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:26:46 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/07 14:14:02 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

static void	dda_step(t_game *game, t_ray *r)
{
	if (r->side_dist_x < r->side_dist_y
		|| (r->side_dist_x == r->side_dist_y
			&& fabs(r->ray_dir_x) > fabs(r->ray_dir_y)))
	{
		r->side_dist_x += r->delta_dist_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_dist_y += r->delta_dist_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
	if (r->map_x < 0 || r->map_x >= game->map_width || r->map_y < 0
		|| r->map_y >= game->map_height)
	{
		r->hit = 1;
		r->perp_wall_dist = 1e9;
	}
	if (game->world_map[r->map_y][r->map_x] != '0')
		r->hit = 1;
}

void	execute_dda(t_game *game, t_ray *r)
{
	int	h;
	int	w;
	int	k;

	h = game->map_height;
	w = game->map_width;
	k = 0;
	while (k < w * h + 10 && r->hit == 0)
	{
		dda_step(game, r);
		if (r->hit)
			break ;
		k++;
	}
}
