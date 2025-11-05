/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:58:45 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/05 19:19:19 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_map_list(t_mapf *liste)
{
	liste[1] = check_walls;
	liste[0] = check_characters;
}

int	map_checker(void)
{
	t_mapf		liste[2];
	int			i;

	i = 0;
	init_map_list(liste);
	while (i < 2)
		if (liste[i++]())
			return (*sgt_error());
	return (0);
}
