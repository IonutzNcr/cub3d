/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:30:45 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/06 17:11:04 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

void	handle_time(t_ray *ray, struct timeval *tv)
{
	ray->oldtime = ray->time;
	gettimeofday(tv, NULL);
	ray->time = tv->tv_sec * 1000 + tv->tv_usec / 1000;
	ray->frametime = (ray->time - ray->oldtime) / 1000.0;
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000L + tv.tv_usec / 1000L;
	return (ms);
}

t_mlx	**sgt_mlx(void)
{
	static void	*sgt_mlx;

	return ((t_mlx **)&sgt_mlx);
}
