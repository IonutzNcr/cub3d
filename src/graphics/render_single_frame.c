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

void	init_map(t_game *game)
{

	int	temp_map[24][24] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

    game->world_map = malloc(24 * sizeof(int *));
    if (!game->world_map)
        exit(1);

    for (int y = 0; y < 24; y++) {
        game->world_map[y] = malloc(24 * sizeof(int));
        if (!game->world_map[y])
            exit(1);
        memcpy(game->world_map[y], temp_map[y], 24 * sizeof(int));
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_verline(t_mlx *mlx, int x, int drawStart, int drawEnd, int color)
{
	for (int y = drawStart; y <= drawEnd; y++)
		my_mlx_pixel_put(mlx->img, x, y, color);
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
			printf("oui\n");
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
		printf("%ld x\n", r->map_x);
		printf("%ld y\n", r->map_y);
		if (game->world_map[r->map_y][r->map_x] > 0)
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
	else if (game->world_map[r->map_x][r->map_y] == 1)
		r->color = 0xFF0000;
	else if (game->world_map[r->map_x][r->map_y] == 2)
		r->color = 0xCCFFCC;
	else if (game->world_map[r->map_x][r->map_y] == 3)
		r->color = 0x0000FF;
	else if (game->world_map[r->map_x][r->map_y] == 4)
		r->color = 0xFFFFFF;
	else
		r->color = 0xFFDE21;
	if (r->side == 1)
		r->color = r->color / 2;
	ft_verline(mlx, i, r->draw_start, r->draw_end, r->color);
}

void	cast_ray(t_game *game, int i, t_mlx *mlx)
{
	t_ray	ray;

	ft_bzero(&ray, sizeof(ray));
	init_ray(game, &ray, i);
	calculate_distances(game, &ray);
	execute_dda(game, &ray);
	calculate_wall_distance(&ray);
	draw_walls(game, &ray, i, mlx);
}


void	render_single_frame(t_game *game, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		cast_ray(game, i, mlx);
		i++;
	}
}

void	start_game_loop(t_game *game, t_mlx *mlx)
{

	
game->pos_x = 12.0;
game->pos_y = 12.0;
game->dir_x = -1.0;   // looking left
game->dir_y = 0.0;
game->plane_x = 0.0;
game->plane_y = 0.66; // FOV 66°
	init_map(game);
	while (1)
	{
		render_single_frame(game, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
		printf("yo\n");
		usleep(1000000);
	}
}
