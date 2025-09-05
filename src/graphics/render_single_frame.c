/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_single_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:20:43 by leothoma          #+#    #+#             */
/*   Updated: 2025/08/27 00:20:44 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307

void	init_map(t_game *game)
{
	char **map = *sgt_map();
	game->world_map = map;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_verline(t_mlx *mlx, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y < drawEnd)
	{
		my_mlx_pixel_put(mlx->img, x, y, color);
		y++;
	}
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

void	execute_dda(t_game *game, t_ray *r)
{
	int	i;

	i = 0;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
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
		if (game->world_map[r->map_y][r->map_x] != '0')
			r->hit = 1;
	}
}

void	calculate_wall_distance(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

void	draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx)
{
	r->line_height = (int)(SCREEN_HEIGHT / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_end >= SCREEN_HEIGHT)
		r->draw_end = SCREEN_HEIGHT - 1;
	if (game->world_map[r->map_y][r->map_x] == '1')
		r->color = 0xFF0000;
	else if (game->world_map[r->map_y][r->map_x] == '2')
		r->color = 0xCCFFCC;
	else if (game->world_map[r->map_y][r->map_x] == '3')
		r->color = 0x0000FF;
	else if (game->world_map[r->map_y][r->map_x] == '4')
		r->color = 0xFFFFFF;
	else
		r->color = 0xFFDE21;
	if (r->side == 1)
		r->color = r->color / 2;
	ft_verline(mlx, i, r->draw_start, r->draw_end, r->color);
}

void	handle_time(t_ray *ray, struct timeval *tv)
{
	ray->oldtime = ray->time;
	gettimeofday(tv, NULL);
	ray->time = tv->tv_sec * 1000 + tv->tv_usec / 1000;
	ray->frametime = (ray->time - ray->oldtime) / 1000.0;
}

void	cast_ray(t_game *game, int i, t_mlx *mlx, t_ray *ray)
{
	ft_bzero(ray, sizeof(t_ray));
	init_ray(game, ray, i);
	calculate_distances(game, ray);
	execute_dda(game, ray);
	calculate_wall_distance(ray);
	draw_walls(game, ray, i, mlx);
}

void	fill_background(t_mlx *mlx, t_game *game)
{
	//haut de l'ecrant
	game->floor_color = sgt_assets()->floor;
	game->ceiling_color= sgt_assets()->ceiling;
	for (int i = 0; i < SCREEN_HEIGHT / 2; i++)
	{
		for(int j = 0; j < SCREEN_WIDTH; j++)
		{
			my_mlx_pixel_put(mlx->img, j, i, game->floor_color);
		}
	}
	//bas de l'ecrant
	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			my_mlx_pixel_put(mlx->img, j, i, game->ceiling_color);
		}
	}
}

void	render_single_frame(t_game *game, t_mlx *mlx, t_ray *ray)
{
	int	i;
	struct timeval tv;
	ft_bzero(mlx->img->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->img->bits_per_pixel / 8));
	i = 0;
	fill_background(mlx, game);
	while (i < SCREEN_WIDTH)
	{
		cast_ray(game, i, mlx, ray);
		i++;
	}
	handle_time(ray, &tv);
}

int key_press(int keycode, t_ctx *ctx)
{
	if (keycode == 119)
		ctx->mlx->w = 1;
	else if (keycode == 115)
		ctx->mlx->s = 1;
	else if (keycode == 97)
		ctx->mlx->a = 1;
	else if (keycode == 100)
		ctx->mlx->d = 1;
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int key_release(int keycode, t_ctx *ctx)
{
	if (keycode == 119)
		ctx->mlx->w = 0;
	else if (keycode == 115)
		ctx->mlx->s = 0;
	else if (keycode == 97)
		ctx->mlx->a = 0;
	else if (keycode == 100)
		ctx->mlx->d = 0;
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int	handle_movement(t_ctx *ctx)
{
	t_mlx	*m = ctx->mlx;
	t_game	*g = ctx->game;
	//double move_speed = 0.05;
	//double rot_speed = 0.02;
	double	move_speed = 0.1;
	double	rot_speed = 0.1;
	double old_dir_x, old_plane_x;
	double	new_x;
	double	new_y;

	if (m->w)
	{
		new_x = g->pos_x + g->dir_x * move_speed;
		new_y = g->pos_y + g->dir_y * move_speed;
		if (g->world_map[(int)g->pos_y][(int)new_x] == '0')
		{
			g->pos_x = new_x;
		}
		if (g->world_map[(int)new_y][(int)g->pos_x] == '0')
		{
			g->pos_y = new_y;
		}
	}
	if (m->s)
	{
		new_x = g->pos_x - g->dir_x * move_speed;
		new_y = g->pos_y - g->dir_y * move_speed;
		if (g->world_map[(int)g->pos_y][(int)new_x] == '0')
			g->pos_x = new_x;
		if (g->world_map[(int)new_y][(int)g->pos_x] == '0')
			g->pos_y = new_y;
	}

if (m->a) // rotate left
{
    double angle = -rot_speed; // 👈 inversion
    old_dir_x = g->dir_x;
    g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
    g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);

    old_plane_x = g->plane_x;
    g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
    g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
}

if (m->d) // rotate right
{
    double angle = rot_speed; // 👈 normal
    old_dir_x = g->dir_x;
    g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
    g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);

    old_plane_x = g->plane_x;
    g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
    g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
}
	return (0);
}


int	loop_hook(t_ctx *ctx)
{
	handle_movement(ctx);
	render_single_frame(ctx->game, ctx->mlx, ctx->ray);
	mlx_put_image_to_window(ctx->mlx->mlx, ctx->mlx->mlx_win, ctx->mlx->img->img, 0, 0);
	return (0);
}

void	load_textures(t_game *game)
{
	t_assets	*assets;
	void	*images[4];

	assets = sgt_assets();
	images[0] = assets->file_NO;
	images[1] = assets->file_SO;
	images[2] = assets->file_WE;
	images[3] = assets->file_EA;
	game->textures = images;
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
	game->dir_x = cos(sgt_player()->orientation * M_PI / 180);   // looking left
	game->dir_y = sin(sgt_player()->orientation * M_PI / 180);
	game->plane_x = -game->dir_y * 0.66;
	game->plane_y = game->dir_x * 0.66; // FOV 66°
	
	load_textures(game);
	ray.time = 0;
	ray.oldtime = 0;
	ray.frametime = 0;
	init_map(game);

	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_press, &ctx);
	mlx_hook(mlx->mlx_win, 3, 1L<<1, key_release, &ctx);
	mlx_loop_hook(mlx->mlx, loop_hook, &ctx);
	mlx_loop(mlx->mlx);
}
