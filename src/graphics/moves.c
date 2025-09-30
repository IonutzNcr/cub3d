/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:12 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 18:26:05 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

static void	handle_translation(t_ctx *ctx, double move_speed, double radius)
{
	if (ctx->mlx->w)
		move_with_dir(ctx->game, (t_vec2){ctx->game->dir_x, ctx->game->dir_y},
			move_speed, radius);
	if (ctx->mlx->s)
		move_with_dir(ctx->game, (t_vec2){-ctx->game->dir_x, -ctx->game->dir_y},
			move_speed, radius);
	if (ctx->mlx->a)
		move_with_dir(ctx->game, (t_vec2){-ctx->game->plane_x,
			-ctx->game->plane_y}, move_speed, radius);
	if (ctx->mlx->d)
		move_with_dir(ctx->game, (t_vec2){ctx->game->plane_x,
			ctx->game->plane_y}, move_speed, radius);
}

static void	handle_rotation(t_ctx *ctx, double rot_speed)
{
	double	angle;

	if (!ctx->mlx->left_arrow && !ctx->mlx->right_arrow)
		return ;
	angle = rot_speed;
	if (ctx->mlx->left_arrow)
		angle = -rot_speed;
	rotate_player(ctx->game, angle);
}

int	handle_movement(t_ctx *ctx)
{
	double	move_speed;
	double	rot_speed;
	double	radius;

	move_speed = get_move_speed(ctx->game);
	rot_speed = get_rot_speed(ctx->game);
	radius = 0.25;
	handle_translation(ctx, move_speed, radius);
	handle_rotation(ctx, rot_speed);
	return (0);
}
