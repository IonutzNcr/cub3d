/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:49:54 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 00:29:50 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	clear_all(t_ctx *ctx, int i, int is)
{
	t_mlx	*mlx;
	int k;

	k = 0;
	remove_map();
	remove_assets();
	mlx = *sgt_mlx();
	while (k < i)
	{
		mlx_destroy_image(mlx->mlx, ctx->game->textures[k]);
		k++;
	}
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	if (is && set_sgt_error(LOAD_ERR))
		print_error();
	exit(0);
}
