/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:01:04 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/30 17:01:07 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	calculate_wall_distance(t_game *g, t_ray *r)
{
	const double		big = 1e30;
	double				denom;

	if (r->side == 0)
	{
		if (r->ray_dir_x != 0.0)
				denom = r->ray_dir_x;
		else
				denom = 1.0 / big;
	}
	else
	{
		if (r->ray_dir_y != 0.0)
				denom = r->ray_dir_y;
		else
				denom = 1.0 / big;
	}
	if (r->perp_wall_dist < 1e-6)
		r->perp_wall_dist = 1e-6;
}

int	check_wall_colision(double *wall_dist)
{
	if (*wall_dist < 0.15)
		return (0);
	return (1);
}

void	fill_background(t_mlx *mlx, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	game->floor_color = sgt_assets()->floor;
	game->ceiling_color = sgt_assets()->ceiling;
	while (++i < SCREEN_HEIGHT / 2)
	{
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(mlx->img, j, i, game->floor_color);
			j++;
		}
		j = 0;
	}
	i = (SCREEN_HEIGHT / 2) - 1;
	j = -1;
	while (++i < SCREEN_HEIGHT)
	{
		while (++j < SCREEN_WIDTH)
			my_mlx_pixel_put(mlx->img, j, i, game->ceiling_color);
		j = -1;
	}
}
