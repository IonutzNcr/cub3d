/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:49:54 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/30 15:49:55 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	clear_all(t_ctx *ctx)
{
	t_mlx	*mlx;

	remove_map();
	remove_assets();
	mlx = *sgt_mlx();
	mlx_destroy_image(mlx->mlx, ctx->game->textures[0]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[1]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[2]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[3]);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	exit(0);
}
