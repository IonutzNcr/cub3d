/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:08 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/30 16:32:09 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	load_textures(t_ctx *ctx)
{
	int			i;
	t_assets	*assets;
	t_game		*t;

	t = ctx->game;
	i = -1;
	assets = sgt_assets();
	ctx->game->textures[0] = mlx_xpm_file_to_image(ctx->mlx->mlx,
			assets->file_NO, &ctx->game->tex_width[0], &t->tex_height[0]);
	ctx->game->textures[1] = mlx_xpm_file_to_image(ctx->mlx->mlx,
			assets->file_SO, &ctx->game->tex_width[1], &t->tex_height[1]);
	ctx->game->textures[2] = mlx_xpm_file_to_image(ctx->mlx->mlx,
			assets->file_WE, &ctx->game->tex_width[2], &t->tex_height[2]);
	ctx->game->textures[3] = mlx_xpm_file_to_image(ctx->mlx->mlx,
			assets->file_EA, &ctx->game->tex_width[3], &t->tex_height[3]);
	while (++i < TEXTURE_COUNT)
	{
		if (!ctx->game->textures[i])
			clear_all();
		ctx->game->tex_addr[i] = mlx_get_data_addr(ctx->game->textures[i],
				&ctx->game->bits_per_pixel[i],
				&ctx->game->line_length[i],
				&ctx->game->endian[i]);
	}
}
