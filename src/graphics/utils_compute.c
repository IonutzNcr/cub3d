/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:40:12 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 17:51:11 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

int	is_open_cell(t_game *g, int my, int mx)
{
	if (my < 0 || mx < 0)
		return (0);
	if (my >= g->map_height || mx >= g->map_width)
		return (0);
	return (g->world_map[my][mx] == '0');
}

double	clampd(double v, double a, double b)
{
	if (v < a)
	{
		return (a);
	}
	if (v > b)
	{
		return (b);
	}
	return (v);
}

int	inside_map(const t_game *g, int my, int mx)
{
	return (my >= 0 && my < g->map_height && mx >= 0 && mx < g->map_width);
}

void	compute_box_center(t_aabb box, t_vec2 *box_center)
{
	box_center->x = 0.5 * (box.x0 + box.x1);
	box_center->y = 0.5 * (box.y0 + box.y1);
}

void	compute_axis_delta(t_vec2 *c, t_vec2 *box_center, t_vec2 *axis_delta)
{
	axis_delta->x = fabs(c->x - box_center->x);
	axis_delta->y = fabs(c->y - box_center->y);
}
