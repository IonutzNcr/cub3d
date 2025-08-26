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

#include "header_main.h"

void	init_t_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
}

int   main(int argc, char **argv, char **env)
{
//	if (parser(argc, argv, env))
//		return (1);
	t_game	game;
	t_mlx	mlx;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&mlx, sizeof(t_mlx));
	init_t_mlx(&mlx);
	start_game_loop(&game, &mlx);
	free_singleton();
	printf("SUCCESS\n");
	return (0);
}
