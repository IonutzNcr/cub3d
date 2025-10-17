/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:28:06 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/07 14:14:18 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	init_map(t_game *game)
{
	char	**map;

	map = *sgt_map();
	game->world_map = map;
}

void	init_ray(t_game *game, t_ray *r, int i)
{
	r->camera_x = 2.0 * i / (double)SCREEN_WIDTH - 1;
	r->ray_dir_x = game->dir_x + game->plane_x * r->camera_x;
	r->ray_dir_y = game->dir_y + game->plane_y * r->camera_x;
	r->map_x = (int)game->pos_x;
	r->map_y = (int)game->pos_y;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
	r->hit = 0;
}
