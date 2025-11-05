/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:38:28 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/05 12:57:15 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_lc_wall(void)
{
	char	**map;
	int		i;
	int		k;
	int		j;

	i = 0;
	map = *sgt_map();
	j = ft_strlen(map[0]);
	k = count_elements(map);
	while (i < k)
		if (map[i++][j - 1] != '1')
			return (1);
	return (0);
}

int	is_c1_wall(void)
{
	char	**map;
	int		k;

	map = *sgt_map();
	k = count_elements(map);
	while (k--)
		if (map[k][0] != '1')
			return (1);
	return (0);
}

int	is_lr_wall(void)
{
	char	**map;
	int		i;
	int		k;

	i = 0;
	map = *sgt_map();
	k = count_elements(map);
	while (map[k - 1][i])
		if (map[k - 1][i++] != '1')
			return (1);
	return (0);
}

int	is_r1_wall(void)
{
	char	**map;
	int		i;

	i = 0;
	map = *sgt_map();
	while (map[0][i])
		if (map[0][i++] != '1')
			return (1);
	return (0);
}



