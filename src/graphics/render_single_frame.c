/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_single_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:20:43 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/06 17:19:23 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307

void	calculate_distances(t_game *game, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (game->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - game->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (game->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - game->pos_y) * r->delta_dist_y;
	}
}

void	cast_ray(t_game *game, int i, t_mlx *mlx, t_ray *ray)
{
	ft_bzero(ray, sizeof(t_ray));
	init_ray(game, ray, i);
	calculate_distances(game, ray);
	execute_dda(game, ray);
	calculate_wall_distance(game, ray);
	draw_walls(game, ray, i, mlx);
}

void	render_single_frame(t_game *game, t_mlx *mlx, t_ray *ray)
{
	int					i;
	struct timeval		tv;

	ft_bzero(mlx->img->addr, game->map_width * game->map_height
		* (mlx->img->bits_per_pixel / 8));
	i = 0;
	fill_background(mlx, game);
	while (i < SCREEN_WIDTH)
	{
		cast_ray(game, i, mlx, ray);
		i++;
	}
	handle_time(ray, &tv);
}

int	loop_hook(t_ctx *ctx)
{
	static long	last_time;
	long		current_time;
	double		dt;

	current_time = get_time_ms();
	if (last_time == 0)
		last_time = current_time;
	dt = (current_time - last_time) / 1000.0;
	last_time = current_time;
	handle_movement(ctx, dt);
	render_single_frame(ctx->game, ctx->mlx, ctx->ray);
	mlx_put_image_to_window(ctx->mlx->mlx, ctx->mlx->mlx_win,
		ctx->mlx->img->img, 0, 0);
	return (0);
}

void	start_game_loop(t_game *game, t_mlx *mlx)
{
	t_ray	ray;
	t_ctx	ctx;

	ctx.game = game;
	ctx.mlx = mlx;
	ctx.ray = &ray;
	game->pos_x = sgt_player()->x + 0.5;
	game->pos_y = sgt_player()->y + 0.5;
	game->dir_x = cos(sgt_player()->orientation * M_PI / 180);
	game->dir_y = sin(sgt_player()->orientation * M_PI / 180);
	game->plane_x = -game->dir_y * 0.66;
	game->plane_y = game->dir_x * 0.66;
	game->map_width = ft_strlen(**sgt_map());
	game->map_height = count_elements(*sgt_map());
	load_textures(&ctx);
	ray.time = 0;
	ray.oldtime = 0;
	ray.frametime = 0;
	init_map(game);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_press, &ctx);
	mlx_hook(mlx->mlx_win, 3, 1L << 1, key_release, &ctx);
	mlx_hook(mlx->mlx_win, 17, 0, mouse_press, &ctx);
	mlx_loop_hook(mlx->mlx, loop_hook, &ctx);
	mlx_loop(mlx->mlx);
}
