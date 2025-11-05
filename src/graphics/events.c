/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:51:07 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 00:12:35 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

int	key_press(int keycode, t_ctx *ctx)
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
	{
		clear_all(ctx, 4);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, t_ctx *ctx)
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

int	mouse_press(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	clear_all(ctx, 4);
	return (0);
}
