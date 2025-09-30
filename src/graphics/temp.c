/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:50:04 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 16:31:18 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header_main.h"
#define EPSILON 1e-6

static  int tile_x(double x)
{ return (int)floor(x); }
static  int tile_y(double y)
{ return (int)floor(y); }

static  int is_open_cell(t_game *g, int my, int mx)
{
    if (my < 0 || mx < 0)
		return 0;
    if (my >= g->map_height || mx >= g->map_width)
        return 0;
    return (g->world_map[my][mx] == '0');
}


static double clampd(double v, double a, double b) {
    if (v < a) {
        return a;
    }
    if (v > b) {
        return b;
    }
    return v;
}

static  int inside_map(const t_game *g, int my, int mx) {
    return (my >= 0 && my < g->map_height && mx >= 0 && mx < g->map_width);
}

static AABB aabb_from_cell(int mx, int my) {
    AABB b;
    b.x0 = (double)mx;
    b.y0 = (double)my;
    b.x1 = b.x0 + 1.0;
    b.y1 = b.y0 + 1.0;
    return (b);
}

static GridBounds compute_grid_bounds(double cx, double cy, double r) 
{
    GridBounds gb;
    gb.min_mx = (int)floor(cx - r) - 1;
    gb.max_mx = (int)floor(cx + r) + 1;
    gb.min_my = (int)floor(cy - r) - 1;
    gb.max_my = (int)floor(cy + r) + 1;
    return (gb);
}

static ClosestPoint closest_point_on_aabb(double cx, double cy, AABB b)
{
    ClosestPoint cp;
    cp.nx = clampd(cx, b.x0, b.x1);
    cp.ny = clampd(cy, b.y0, b.y1);
    return (cp);
}

static Penetration make_penetration(double cx, double cy,
                                    ClosestPoint cp, double radius)
{
    Penetration p;
    p.vx = cx - cp.nx;
    p.vy = cy - cp.ny;
    p.d2 = p.vx * p.vx + p.vy * p.vy;
    p.r2 = radius * radius;
    return p;
}

static int	has_overlap(Penetration *pn)
{
	if (pn->d2 >= pn->r2 - 1e-12)
		return (0);
	return (1);
}

static int	handle_normal_push(Vec2 *c, Penetration *pn, double radius)
{
	double	dist;
	double	push_len;

	if (pn->d2 <= EPSILON * EPSILON)
		return (0);
	dist = sqrt(pn->d2);
	push_len = radius - dist;
	c->x += (pn->vx / dist) * push_len;
	c->y += (pn->vy / dist) * push_len;
	return (1);
}

static void	compute_box_center(AABB box, Vec2 *box_center)
{
	box_center->x = 0.5 * (box.x0 + box.x1);
	box_center->y = 0.5 * (box.y0 + box.y1);
}

static void	compute_axis_delta(Vec2 *c, Vec2 *box_center, Vec2 *axis_delta)
{
	axis_delta->x = fabs(c->x - box_center->x);
	axis_delta->y = fabs(c->y - box_center->y);
}

static void	resolve_degenerate(Vec2 *c, double radius, AABB box)
{
	Vec2	box_center;
	Vec2	axis_delta;

	compute_box_center(box, &box_center);
	compute_axis_delta(c, &box_center, &axis_delta);
	if (axis_delta.x > axis_delta.y)
	{
		if (c->x > box_center.x)
			c->x = box.x1 + radius + EPSILON;
		else
			c->x = box.x0 - radius - EPSILON;
	}
	else
	{
		if (c->y > box_center.y)
			c->y = box.y1 + radius + EPSILON;
		else
			c->y = box.y0 - radius - EPSILON;
	}
}

static int	push_out_of_wall(Vec2 *c, double radius, AABB box)
{
	ClosestPoint	cp;
	Penetration		pn;

	cp = closest_point_on_aabb(c->x, c->y, box);
	pn = make_penetration(c->x, c->y, cp, radius);
	if (!has_overlap(&pn))
		return (0);
	if (handle_normal_push(c, &pn, radius))
		return (1);
	resolve_degenerate(c, radius, box);
	return (1);
}

static int	resolve_neighborhood(t_game *g, Vec2 *c, double radius)
{
	GridBounds	gb;
	int			changed_any;
	int			my;
	int			mx;
	AABB		b;

	gb = compute_grid_bounds(c->x, c->y, radius);
	changed_any = 0;
	my = gb.min_my;
	while (my <= gb.max_my)
	{
		mx = gb.min_mx;
		while (mx <= gb.max_mx)
		{
			if (inside_map(g, my, mx) && !is_open_cell(g, my, mx))
			{
				b = aabb_from_cell(mx, my);
				if (push_out_of_wall(c, radius, b))
					changed_any = 1;
			}
			mx++;
		}
		my++;
	}
	return (changed_any);
}
void	fix_position_near_walls(t_game *g, double radius)
{
	Vec2	c;
	int		iter;
	int		changed;

	c.x = g->pos_x;
	c.y = g->pos_y;
	iter = 0;
	while (iter < 3)
	{
		changed = resolve_neighborhood(g, &c, radius);
		if (!changed)
			break ;
		iter++;
	}
	g->pos_x = c.x;
	g->pos_y = c.y;
}

// Test de déplacement avec "rayon" pour éviter de s'accrocher aux coins.
// dx/dy = vecteur de déplacement (nouvelle position - ancienne position)
static void try_move_with_radius(t_game *g, double new_x, double new_y,
                                 double dx, double dy, double radius)
{
    double off_x = (dx > 0.0) ? radius : (dx < 0.0 ? -radius : 0.0);
    double off_y = (dy > 0.0) ? radius : (dy < 0.0 ? -radius : 0.0);

    // Test axe X
    int test_mx = tile_x(new_x + off_x);
    int cur_my  = tile_y(g->pos_y);
    if (is_open_cell(g, cur_my, test_mx))
        g->pos_x = new_x;

    // Test axe Y (en utilisant pos_x possiblement mis à jour pour permettre le "sliding")
    int test_my = tile_y(new_y + off_y);
    int cur_mx  = tile_x(g->pos_x);
    if (is_open_cell(g, test_my, cur_mx))
        g->pos_y = new_y;
    
    fix_position_near_walls(g, radius);
}

int handle_movement(t_ctx *ctx)
{
    t_mlx  *m = ctx->mlx;
    t_game *g = ctx->game;

    // Utilise les vitesses du jeu si elles sont renseignées, sinon des défauts
    double move_speed = (g->move_speed     > 0.0) ? g->move_speed     : 0.05;
    double rot_speed  = (g->rotation_speed > 0.0) ? g->rotation_speed : 0.05;
    double radius = 0.25;

    double old_dir_x, old_plane_x;

    // --- Avancer (W)
    if (m->w) {
        double dx = g->dir_x * move_speed;
        double dy = g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Reculer (S)
    if (m->s) {
        double dx = -g->dir_x * move_speed;
        double dy = -g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe gauche (A) : utilise le plan (perpendiculaire à dir)
    if (m->a) {
        double dx = -g->plane_x * move_speed;
        double dy = -g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe droit (D)
    if (m->d) {
        double dx =  g->plane_x * move_speed;
        double dy =  g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Rotation
    if (m->left_arrow || m->right_arrow) {
        double angle = m->left_arrow ? -rot_speed : rot_speed;

        old_dir_x   = g->dir_x;
        g->dir_x    = g->dir_x * cos(angle) - g->dir_y * sin(angle);
        g->dir_y    = old_dir_x * sin(angle) + g->dir_y * cos(angle);

        old_plane_x = g->plane_x;
        g->plane_x  = g->plane_x * cos(angle) - g->plane_y * sin(angle);
        g->plane_y  = old_plane_x * sin(angle) + g->plane_y * cos(angle);
    }

    return 0;
}


