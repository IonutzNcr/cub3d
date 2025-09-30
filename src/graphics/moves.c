/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:12 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 18:06:25 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

static int	tile_x(double x)
{
	return (int)floor(x);
}
static int	tile_y(double y)
{
	return (int)floor(y);
}

static t_offset	compute_offset(double dx, double dy, double radius)
{
	t_offset	off;

	off.x = 0.0;
	off.y = 0.0;
	if (dx > 0.0)
		off.x = radius;
	else if (dx < 0.0)
		off.x = -radius;
	if (dy > 0.0)
		off.y = radius;
	else if (dy < 0.0)
		off.y = -radius;
	return (off);
}

static void	try_move_with_radius(t_game *g, t_vec2 new_pos, t_vec2 dir,
		double radius)
{
	t_offset	off;
	t_tilepos	cur;
	t_tilepos	test;

	off = compute_offset(dir.x, dir.y, radius);
	test.x = tile_x(new_pos.x + off.x);
	cur.y = tile_y(g->pos_y);
	if (is_open_cell(g, cur.y, test.x))
		g->pos_x = new_pos.x;
	test.y = tile_y(new_pos.y + off.y);
	cur.x = tile_x(g->pos_x);
	if (is_open_cell(g, test.y, cur.x))
		g->pos_y = new_pos.y;
	fix_position_near_walls(g, radius);
}

static void	move_with_dir(t_game *g, t_vec2 dir, double speed, double radius)
{
	t_vec2	new_pos;
	t_vec2	move;

	move.x = dir.x * speed;
	move.y = dir.y * speed;
	new_pos.x = g->pos_x + move.x;
	new_pos.y = g->pos_y + move.y;
	try_move_with_radius(g, new_pos, move, radius);
}

static void	rotate_player(t_game *g, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->dir_x;
	g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
	g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);
	old_plane_x = g->plane_x;
	g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
	g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
}

int	handle_movement(t_ctx *ctx)
{
	double	move_speed;
	double	rot_speed;
	double	radius;
	double	angle;

	move_speed = 0.05;
	if (ctx->game->move_speed > 0.0)
		move_speed = ctx->game->move_speed;
	rot_speed = 0.05;
	if (ctx->game->rotation_speed > 0.0)
		rot_speed = ctx->game->rotation_speed;
	radius = 0.25;
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
	if (ctx->mlx->left_arrow || ctx->mlx->right_arrow)
	{
		angle = rot_speed;
		if (ctx->mlx->left_arrow)
			angle = -rot_speed;
		rotate_player(ctx->game, angle);
	}
	return (0);
}
