/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:58:45 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 00:58:49 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_walls(void)
{
	if (is_r1_wall() || is_lr_wall() || is_c1_wall() || is_lc_wall())
	{
		set_sgt_error(NO_WALL);
		return (*sgt_error());
	}
	return (0);
}

static void	init_map_list(mapf *liste)
{
	liste[0] = check_walls;
	liste[1] = check_characters;
}

int	map_checker(void)
{
	mapf		liste[2];
	int			i;

	i = 0;
	init_map_list(liste);
	while (i < 2)
		if (liste[i++]())
			return (*sgt_error());
	return (0);
}
