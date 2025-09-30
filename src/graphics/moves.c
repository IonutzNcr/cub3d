/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:12 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 16:38:17 by inicoara         ###   ########.fr       */
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

// Test de déplacement avec "rayon" pour éviter de s'accrocher aux coins.
// dx/dy = vecteur de déplacement (nouvelle position - ancienne position)
static void	try_move_with_radius(t_game *g, double new_x, double new_y,
		double dx, double dy, double radius)
{
	double	off_x;
	double	off_y;
	int		test_mx;
	int		cur_my;
	int		test_my;
	int		cur_mx;

	off_x = (dx > 0.0) ? radius : (dx < 0.0 ? -radius : 0.0);
	off_y = (dy > 0.0) ? radius : (dy < 0.0 ? -radius : 0.0);
	// Test axe X
	test_mx = tile_x(new_x + off_x);
	cur_my = tile_y(g->pos_y);
	if (is_open_cell(g, cur_my, test_mx))
		g->pos_x = new_x;
	// Test axe Y (en utilisant pos_x possiblement mis à jour pour permettre le "sliding")
	test_my = tile_y(new_y + off_y);
	cur_mx = tile_x(g->pos_x);
	if (is_open_cell(g, test_my, cur_mx))
		g->pos_y = new_y;
	fix_position_near_walls(g, radius);
}

int	handle_movement(t_ctx *ctx)
{
	t_mlx *m = ctx->mlx;
	t_game *g = ctx->game;

	// Utilise les vitesses du jeu si elles sont renseignées, sinon des défauts
	double move_speed = (g->move_speed > 0.0) ? g->move_speed : 0.05;
	double rot_speed = (g->rotation_speed > 0.0) ? g->rotation_speed : 0.05;
	double radius = 0.25;

	double old_dir_x, old_plane_x;

	// --- Avancer (W)
	if (m->w)
	{
		double dx = g->dir_x * move_speed;
		double dy = g->dir_y * move_speed;
		try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
	}

	// --- Reculer (S)
	if (m->s)
	{
		double dx = -g->dir_x * move_speed;
		double dy = -g->dir_y * move_speed;
		try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
	}

	// --- Strafe gauche (A) : utilise le plan (perpendiculaire à dir)
	if (m->a)
	{
		double dx = -g->plane_x * move_speed;
		double dy = -g->plane_y * move_speed;
		try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
	}

	// --- Strafe droit (D)
	if (m->d)
	{
		double dx = g->plane_x * move_speed;
		double dy = g->plane_y * move_speed;
		try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
	}

	// --- Rotation
	if (m->left_arrow || m->right_arrow)
	{
		double angle = m->left_arrow ? -rot_speed : rot_speed;

		old_dir_x = g->dir_x;
		g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
		g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);

		old_plane_x = g->plane_x;
		g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
		g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
	}

	return (0);
}