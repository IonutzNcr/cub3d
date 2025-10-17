/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:18:25 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/07 14:16:26 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	try_move_with_radius(t_game *g, t_vec2 new_pos, t_vec2 dir,
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

void	move_with_dir(t_game *g, t_vec2 dir, double speed, double radius)
{
	t_vec2	new_pos;
	t_vec2	move;

	move.x = dir.x * speed;
	move.y = dir.y * speed;
	new_pos.x = g->pos_x + move.x;
	new_pos.y = g->pos_y + move.y;
	try_move_with_radius(g, new_pos, move, radius);
}

void	rotate_player(t_game *g, double angle)
{
	static double	prev_angle;
	static double	cos_a;
	static double	sin_a;
	double			old_dir_x;
	double			old_plane_x;

	if (prev_angle == 0.0 && cos_a == 0.0 && sin_a == 0.0)
	{
		prev_angle = 0.0;
		cos_a = 1.0;
		sin_a = 0.0;
	}
	if (angle != prev_angle)
	{
		cos_a = cos(angle);
		sin_a = sin(angle);
		prev_angle = angle;
	}
	old_dir_x = g->dir_x;
	g->dir_x = g->dir_x * cos_a - g->dir_y * sin_a;
	g->dir_y = old_dir_x * sin_a + g->dir_y * cos_a;
	old_plane_x = g->plane_x;
	g->plane_x = g->plane_x * cos_a - g->plane_y * sin_a;
	g->plane_y = old_plane_x * sin_a + g->plane_y * cos_a;
}
