/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:57:16 by yoyo              #+#    #+#             */
/*   Updated: 2025/11/06 00:29:05 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"

int	init_t_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->img = malloc(sizeof(t_img));
	if (!(mlx->img))
		return (0);
	mlx->mlx_win = mlx_new_window(mlx->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!mlx->mlx_win)
		return (0);
	mlx->img->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img->img)
		return (0);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel,
			&mlx->img->line_length, &mlx->img->endian);
	if (!mlx->img->addr)
		return (0);
	*sgt_mlx() = mlx;
	return (1);
}

void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
	{
		if (mlx->img->img)
			mlx_destroy_image(mlx->mlx, mlx->img->img);
		free(mlx->img);
		mlx->img = NULL;
	}
	if (mlx->mlx_win)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx->mlx_win = NULL;
	}
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_game	game;
	t_mlx	mlx;

	if (parser(argc, argv, env))
		return (1);
	get_player_info();
	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&mlx, sizeof(t_mlx));
	if (!init_t_mlx(&mlx))
	{
		free_mlx(&mlx);
		free_singleton();
		return (1);
	}
	start_game_loop(&game, &mlx);
	free_singleton();
	return (0);
}
