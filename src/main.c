/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:57:16 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/07 17:19:21 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include <mlx.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct s_game {
    void *mlx;
    void *win;

	int	move_forard;
	int	move_backwards;
	int	rotation_left;
	int	rotation_right;
	double	move_speed;
	double	rotation_speed;
}   t_game;

static	int on_keydown(int key, t_game * game)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W || key == KEY_UP)
		game->move_foward = 1;
	return (0);
}

static	int on_keyup(int key, t_game * game)
{
	if (key == KEY_W || key == KEY_UP)
		game->move_foward = 0;
	return (0);
}


void	init_mlx(int screen_width, int screen_height)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screen_width, screen_height, "cub3d");
}

void verLine(t_game *game, int x, int drawStart, int drawEnd, int color)
{
    for (int y = drawStart; y <= drawEnd; y++)
        mlx_pixel_put(game->mlx, game->win, x, y, color);
}

void	start_game_loop(t_game *game)
{

	int worldMap[mapWidth][mapHeight]=
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

	double	pos_x = 22;	// position de start aribitraire
	double	pos_y = 12;

	double	dir_x = 0;	// L'angle ou on regarde
	double	dir_y = 0;

	double	plane_x = 0;	//pas sur
	double	plane_y = 0.66;

	double	time = 0;	//pour calculer une mouvement speed constante entre chaque frame
	double	oldtime = 0;

	//init_mlx(screenWidth, screenHeight);
	
	while (1)
	{
		for (int i = 0; i < screenWidth; i++)
		{
			double	camera_x = 2.0 * i / (double)screenWidth - 1;
			double	ray_dir_x = dir_x + plane_x * camera_x;
			double	ray_dir_y = dir_y + plane_y * camera_x;
			
			int	map_x = (int)pos_x;
			int	map_y = (int)pos_y;

			double	side_dist_x;
			double	side_dist_y;

			double	delta_dist_x;
			if (ray_dir_x == 0)
				delta_dist_x = 1e30;
			else
				delta_dist_x = fabs(1.0 / ray_dir_x);
			double	delta_dist_y;
			if (ray_dir_y == 0)
				delta_dist_y = 1e30;
			else
				delta_dist_y = fabs(1.0 / ray_dir_y);

			double	perp_wall_dist;
			int	step_x;
			int	step_y;

			int	hit = 0;
			int	side;

			if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = -1;
				side_dist_y = (pos_y - map_y) * delta_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
			}
			while (hit == 0)
			{
				if (side_dist_x < side_dist_y)
				{
					side_dist_x += delta_dist_x;
					map_x += step_x;
					side = 0;
				}
				else
				{
					side_dist_y += delta_dist_y;
					map_y += step_y;
					side = 1;
				}
				if (worldMap[map_x][map_y] > 0)
					hit = 1;
			}
			if (side == 0)
				perp_wall_dist = (side_dist_x - delta_dist_x);
			else
				perp_wall_dist = (side_dist_y - delta_dist_y);

			int	line_height = (int)(screenHeight / perp_wall_dist);
			int	draw_start = -line_height / 2 + screenHeight / 2;
			if (draw_start < 0)
				draw_start = 0;
			int	draw_end = line_height / 2 + screenHeight / 2;
			if(draw_end >= screenHeight)
				draw_end = screenHeight - 1;

			int color;

			if (worldMap[map_x][map_y] == 1)
				 color = 0xFF0000; // red
			else if (worldMap[map_x][map_y] == 2)
				color = 0xCCFFCC; // green
			else if (worldMap[map_x][map_y] == 3)
				color = 0x0000FF;
			else if (worldMap[map_x][map_y] == 4)
				color = 0xFFFFFF;
			else
				color = 0xFFDE21;

			if (side == 1)
				color = color / 2;
			verLine(game, i, draw_start, draw_end, color);
		}
		mlx_hook(game.win, ON_KEYDOWN, MASK_KEYDOWN, on keydown, &)
	}
	(void)worldMap;
}

int   main(int argc, char **argv, char **env)
{
//	if (parser(argc, argv, env))
//		return (1);
	t_game game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, screenWidth, screenHeight, "cub3d");
	game.move_foward = 0;
	game.move_backward = 0;

	start_game_loop(&game);
	mlx_loop(game.mlx);
	free_singleton();
	printf("SUCCESS\n");
	return (0);
}
