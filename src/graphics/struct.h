/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:25:39 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 18:27:09 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_aabb
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
}			t_aabb;

typedef struct s_grindBounds
{
	int		min_mx;
	int		max_mx;
	int		min_my;
	int		max_my;
}			t_gridBounds;

typedef struct s_closestPoint
{
	double	nx;
	double	ny;
}			t_closestPoint;

typedef struct s_penetration
{
	double	vx;
	double	vy;
	double	d2;
	double	r2;
}			t_penetration;

typedef struct s_offset
{
	double	x;
	double	y;
}	t_offset;

typedef struct s_tilepos
{
	int	x;
	int	y;
}	t_tilepos;

#endif