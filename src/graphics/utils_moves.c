/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:15:10 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/07 14:48:37 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

double	get_move_speed(t_game *g)
{
	if (g->move_speed > 0.0)
		return (g->move_speed);
	return (0.07);
}

double	get_rot_speed(t_game *g)
{
	if (g->rotation_speed > 0.0)
		return (g->rotation_speed);
	return (0.05);
}

t_offset	compute_offset(double dx, double dy, double radius)
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

int	tile_x(double x)
{
	return ((int)floor(x));
}

int	tile_y(double y)
{
	return ((int)floor(y));
}
