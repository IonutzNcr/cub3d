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


void draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx)
{
	int	tex_num;
	double	wall_x;
	int     tex_x;
	int     tex_y;
	int     y;

	r->line_height = (int)(SCREEN_HEIGHT / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_end >= SCREEN_HEIGHT)
		r->draw_end = SCREEN_HEIGHT - 1;
	if (r->side == 0)
		wall_x = game->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = game->pos_x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			tex_num = 0;
		else
			tex_num = 1;
	}
	else
	{
		if (r->ray_dir_y > 0)
			tex_num = 2;
		else
			tex_num = 3;
	}
	tex_x = (int)(wall_x * (double)game->tex_width[tex_num]);
	if ((r->side == 0 && r->ray_dir_x < 0) || (r->side == 1 && r->ray_dir_y > 0))
		tex_x = game->tex_width[tex_num] - tex_x - 1;
	for (y = r->draw_start; y < r->draw_end; y++)
	{
		int d = (y * 256 - SCREEN_HEIGHT * 128 + r->line_height * 128);
		tex_y = ((d * game->tex_height[tex_num]) / r->line_height) / 256;
		char *tex_ptr = game->tex_addr[tex_num] + (tex_y * game->line_length[tex_num]
			+ tex_x * (game->bits_per_pixel[tex_num] / 8));
		int color = *(unsigned int *)tex_ptr;
		if (r->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(mlx->img, i, y, color);
    }
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
	else if (keycode == 65361)
		ctx->mlx->left_arrow = 1;
	else if (keycode == 65363)
		ctx->mlx->right_arrow = 1;
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
	else if (keycode == 65361)
		ctx->mlx->left_arrow = 0;
	else if (keycode == 65363)
		ctx->mlx->right_arrow = 0;
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int	check_wall_colision(double *wall_dist)
{
	if (*wall_dist < 0.15)
		return (0);
	return (1);
}

int	handle_movement(t_ctx *ctx)
{
	t_mlx	*m = ctx->mlx;
	t_game	*g = ctx->game;
	double	move_speed = 0.05;
	double	rot_speed = 0.05;
	double old_dir_x, old_plane_x;
	double	new_x;
	double	new_y;
	double	radius = 0.25;

	printf("ray_dir_x %f\n", ctx->ray->ray_dir_x);
	printf("ray_dir_y %f\n", ctx->ray->ray_dir_y);

	if (m->w)
	{
		new_x = g->pos_x + g->dir_x * move_speed;
		new_y = g->pos_y + g->dir_y * move_speed;
		if (g->dir_x > 0)
		{
			if (g->world_map[(int)g->pos_y][(int)(new_x + radius)] == '0')
				g->pos_x = new_x;
		}
		else
		{
			if (g->world_map[(int)g->pos_y][(int)(new_x - radius)] == '0')
				g->pos_x = new_x;
		}
		if (g->dir_y > 0)
		{
			if (g->world_map[(int)(new_y + radius)][(int)g->pos_x] == '0')
				g->pos_y = new_y;
		}
		else
		{
			if (g->world_map[(int)(new_y - radius)][(int)g->pos_x] == '0')
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
	if (m->a)
	{
		new_x = g->pos_x - g->plane_x * move_speed;
		new_y = g->pos_y - g->plane_y * move_speed;
		if (g->world_map[(int)g->pos_y][(int)new_x] == '0')
			g->pos_x = new_x;
		if (g->world_map[(int)new_y][(int)g->pos_x] == '0')
			g->pos_y = new_y;
	}
	if (m->d)
	{
		new_x = g->pos_x + g->plane_x * move_speed;
		new_y = g->pos_y + g->plane_y * move_speed;
		if (g->world_map[(int)g->pos_y][(int)new_x] == '0')
			g->pos_x = new_x;
		if (g->world_map[(int)new_y][(int)g->pos_x] == '0')
			g->pos_y = new_y;
	}
	if (m->left_arrow)
	{
		double angle = -rot_speed;
		old_dir_x = g->dir_x;
		g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
		g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);
		old_plane_x = g->plane_x;
		g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
		g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
	}
	if (m->right_arrow)
	{
		double angle = rot_speed;
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

void    load_textures(t_ctx *ctx)
{
	int	i;
	t_assets *assets;

	i = -1;
	assets = sgt_assets();
	ctx->game->textures[0] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_NO, &ctx->game->tex_width[0], &ctx->game->tex_height[0]);
	ctx->game->textures[1] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_SO, &ctx->game->tex_width[1], &ctx->game->tex_height[1]);
	ctx->game->textures[2] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_WE, &ctx->game->tex_width[2], &ctx->game->tex_height[2]);
	ctx->game->textures[3] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_EA, &ctx->game->tex_width[3], &ctx->game->tex_height[3]);
	while(++i < TEXTURE_COUNT)
	{
		if (!ctx->game->textures[i])
		{
			printf("Error: failed to load texture %d\n", i);
			exit(1);
		}
		ctx->game->tex_addr[i] = mlx_get_data_addr(ctx->game->textures[i],
			&ctx->game->bits_per_pixel[i],
			&ctx->game->line_length[i],
			&ctx->game->endian[i]);
	}
}

/*
void	load_textures(t_ctx *ctx)
{
	t_assets	*assets;
	void	*images[4];
	int	img_width;
	int	img_height;

	assets = sgt_assets();
	printf("%s\n", assets->file_NO);
	images[0] = mlx_xpm_file_to_image(ctx->mlx->mlx, assets->file_NO, &img_width, &img_height);
	//images[0] = assets->file_NO;
	images[1] = assets->file_SO;
	images[2] = assets->file_WE;
	images[3] = assets->file_EA;
	ctx->game->textures = images;
}
*/
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
	
	load_textures(&ctx);
	ray.time = 0;
	ray.oldtime = 0;
	ray.frametime = 0;
	init_map(game);

	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_press, &ctx);
	mlx_hook(mlx->mlx_win, 3, 1L<<1, key_release, &ctx);
	mlx_loop_hook(mlx->mlx, loop_hook, &ctx);
	mlx_loop(mlx->mlx);
}
