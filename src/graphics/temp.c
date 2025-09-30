/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:50:04 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 17:51:27 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"
#define EPSILON 1e-6

static int	handle_normal_push(t_vec2 *c, t_penetration *pn, double radius)
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

static void	resolve_degenerate(t_vec2 *c, double radius, t_aabb box)
{
	t_vec2	box_center;
	t_vec2	axis_delta;

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

static int	push_out_of_wall(t_vec2 *c, double radius, t_aabb box)
{
	t_closestPoint	cp;
	t_penetration	pn;

	cp = closest_point_on_aabb(c->x, c->y, box);
	pn = make_penetration(c->x, c->y, cp, radius);
	if (!has_overlap(&pn))
		return (0);
	if (handle_normal_push(c, &pn, radius))
		return (1);
	resolve_degenerate(c, radius, box);
	return (1);
}

static int	resolve_neighborhood(t_game *g, t_vec2 *c, double radius)
{
	t_gridBounds	gb;
	int				changed_any;
	int				my;
	int				mx;
	t_aabb			b;

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
	t_vec2	c;
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
