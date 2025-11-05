/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:49:54 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 00:11:46 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	clear_all(t_ctx *ctx, int i)
{
	t_mlx	*mlx;
	int k;

	k = 0;
	remove_map();
	remove_assets();
	printf("haaaaahaah\n");
	mlx = *sgt_mlx();
	while (k < i)
	{
		printf("k = %d\n", k);
		mlx_destroy_image(mlx->mlx, ctx->game->textures[k]);
		k++;
	}
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	printf("haaaaahaah1\n");
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	printf("haaaaahaah1.6\n");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	printf("haaaaahaah1.6\n");
	mlx_destroy_display(mlx->mlx);
	printf("haaaaahaah2\n");
	mlx_loop_end(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	exit(0);
}
