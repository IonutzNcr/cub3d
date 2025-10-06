/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:10:00 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/06 16:54:37 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

static void	compute_wall_params(t_game *game, t_ray *r)
{
	double	temp;

	if (r->perp_wall_dist <= 1e-6)
		r->perp_wall_dist = 1e-6;
	temp = SCREEN_HEIGHT / r->perp_wall_dist;
	r->line_height = (int)temp;
	r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_end >= SCREEN_HEIGHT)
		r->draw_end = SCREEN_HEIGHT - 1;
	if (r->side == 0)
	{
		temp = r->perp_wall_dist * r->ray_dir_y;
		r->wall_x = game->pos_y + temp;
	}
	else
	{
		temp = r->perp_wall_dist * r->ray_dir_x;
		r->wall_x = game->pos_x + temp;
	}
	temp = floor(r->wall_x);
	r->wall_x = r->wall_x - temp;
}

static void	compute_tex_params(t_game *game, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->tex_num = 0;
		else
			r->tex_num = 1;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->tex_num = 2;
		else
			r->tex_num = 3;
	}
	r->tex_x = (int)(r->wall_x * (double)game->tex_width[r->tex_num]);
	if (r->tex_x < 0)
		r->tex_x = 0;
	if (r->tex_x >= game->tex_width[r->tex_num])
		r->tex_x = game->tex_width[r->tex_num] - 1;
	if ((r->side == 0 && r->ray_dir_x < 0)
		|| (r->side == 1 && r->ray_dir_y > 0))
		r->tex_x = game->tex_width[r->tex_num] - r->tex_x - 1;
}

static void	draw_wall_column(t_game *game, t_ray *r, int i, t_mlx *mlx)
{
	int					y;
	int					tex_y;
	int					d;
	char				*tex_ptr;
	unsigned int		color;

	if (i < 0 || i >= SCREEN_WIDTH)
		return ;
	y = r->draw_start - 1;
	while (++y <= r->draw_end)
	{
		d = y * 256 - SCREEN_HEIGHT * 128 + r->line_height * 128;
		tex_y = d * game->tex_height[r->tex_num] / r->line_height / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= game->tex_height[r->tex_num])
			tex_y = game->tex_height[r->tex_num] - 1;
		tex_ptr = game->tex_addr[r->tex_num]
			+ (tex_y * game->line_length[r->tex_num]
				+ r->tex_x * (game->bits_per_pixel[r->tex_num] / 8));
		color = *(unsigned int *)tex_ptr;
		if (r->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		my_mlx_pixel_put(mlx->img, i, y, color);
	}
}

void	draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx)
{
	r->wall_x = 0;
	compute_wall_params(game, r);
	compute_tex_params(game, r);
	draw_wall_column(game, r, i, mlx);
}
