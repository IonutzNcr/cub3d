/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:01:04 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/10 21:52:53 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	calculate_wall_distance(t_game *g, t_ray *r)
{
	double	denom;

	if (r->side == 0)
		denom = r->ray_dir_x;
	else
		denom = r->ray_dir_y;
	if (fabs(denom) < 1e-12)
		denom = 1e-12;
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - g->pos_x + (1 - r->step_x) * 0.5)
			/ denom;
	else
		r->perp_wall_dist = (r->map_y - g->pos_y + (1 - r->step_y) * 0.5)
			/ denom;
	if (r->perp_wall_dist < 1e-6)
		r->perp_wall_dist = 1e-6;
}

int	check_wall_colision(double *wall_dist)
{
	if (*wall_dist < 0.05)
		return (0);
	return (1);
}

void	fill_background(t_mlx *mlx, t_game *game)
{
	int		*pixels;
	int		y;
	int		x;
	int		color;

	pixels = (int *)mlx->img->addr;
	game->floor_color = sgt_assets()->floor;
	game->ceiling_color = sgt_assets()->ceiling;

	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		color = (y < SCREEN_HEIGHT / 2)
			? game->floor_color   // ← même logique que ton code
			: game->ceiling_color;
		for (x = 0; x < SCREEN_WIDTH; x++)
			pixels[y * SCREEN_WIDTH + x] = color;
	}
}

