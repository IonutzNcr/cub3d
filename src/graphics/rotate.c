/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:05:18 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/15 20:06:17 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

int	handle_rotation_key(int keycode, t_ctx *ctx)
{
	double	rot_speed;
	double	angle;

	rot_speed = get_rot_speed(ctx->game);
	angle = 0;
	if (keycode == LEFT_ARROW)
		angle = -rot_speed;
	else if (keycode == RIGHT_ARROW)
		angle = rot_speed;
	else
		return (0);
	rotate_player(ctx->game, angle);
	render_single_frame(ctx->game, ctx->mlx, ctx->ray);
	mlx_put_image_to_window(ctx->mlx->mlx, ctx->mlx->mlx_win,
		ctx->mlx->img->img, 0, 0);
	return (0);
}

int	key_press(int keycode, t_ctx *ctx)
{
	if (keycode == LEFT_ARROW)
		ctx->mlx->left_arrow = 1;
	else if (keycode == RIGHT_ARROW)
		ctx->mlx->right_arrow = 1;
	return (0);
}

int	key_release(int keycode, t_ctx *ctx)
{
	if (keycode == LEFT_ARROW)
		ctx->mlx->left_arrow = 0;
	else if (keycode == RIGHT_ARROW)
		ctx->mlx->right_arrow = 0;
	return (0);
}

void	handle_rotation(t_ctx *ctx, double rot_speed)
{
	if (ctx->mlx->left_arrow)
		rotate_player(ctx->game, -rot_speed);
	else if (ctx->mlx->right_arrow)
		rotate_player(ctx->game, rot_speed);
}
