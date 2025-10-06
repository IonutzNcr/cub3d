/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:12 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/06 17:26:19 by inicoara         ###   ########.fr       */
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

void	handle_rotation(t_ctx *ctx, double rot_speed, double dt)
{
	double	angle;
	int		dir;

	if (!ctx->mlx->left_arrow && !ctx->mlx->right_arrow)
		return ;
	dir = 0;
	if (ctx->mlx->left_arrow)
		dir = -1;
	else if (ctx->mlx->right_arrow)
		dir = 1;
	if (dir == 0)
		return ;
	angle = rot_speed * dt * (double)dir;
	rotate_player(ctx->game, angle);
}

int	handle_movement(t_ctx *ctx, double dt)
{
	double	move_speed;
	double	rot_speed;
	double	radius;

	move_speed = get_move_speed(ctx->game);
	rot_speed = get_rot_speed(ctx->game);
	radius = 0.25;
	handle_translation(ctx, move_speed, radius);
	handle_rotation(ctx, rot_speed, dt);
	return (0);
}
