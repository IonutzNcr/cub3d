/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compute2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:44:30 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 17:04:11 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

AABB	aabb_from_cell(int mx, int my)
{
	AABB	b;

	b.x0 = (double)mx;
	b.y0 = (double)my;
	b.x1 = b.x0 + 1.0;
	b.y1 = b.y0 + 1.0;
	return (b);
}

GridBounds	compute_grid_bounds(double cx, double cy, double r)
{
	GridBounds	gb;

	gb.min_mx = (int)floor(cx - r) - 1;
	gb.max_mx = (int)floor(cx + r) + 1;
	gb.min_my = (int)floor(cy - r) - 1;
	gb.max_my = (int)floor(cy + r) + 1;
	return (gb);
}

ClosestPoint	closest_point_on_aabb(double cx, double cy, AABB b)
{
	ClosestPoint	cp;

	cp.nx = clampd(cx, b.x0, b.x1);
	cp.ny = clampd(cy, b.y0, b.y1);
	return (cp);
}

Penetration	make_penetration(double cx, double cy, ClosestPoint cp,
		double radius)
{
	Penetration	p;

	p.vx = cx - cp.nx;
	p.vy = cy - cp.ny;
	p.d2 = p.vx * p.vx + p.vy * p.vy;
	p.r2 = radius * radius;
	return (p);
}

int	has_overlap(Penetration *pn)
{
	if (pn->d2 >= pn->r2 - 1e-12)
		return (0);
	return (1);
}