/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cf.func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:02:48 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/17 15:46:07 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_floor(char *line)
{
	int			cmb;
	char		**rgb;
	int			i;
	char		tmp;
	t_assets	*assets;

	i = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	assets = sgt_assets();
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	tmp = line[i];
	line[i] = '\0';
	rgb = ft_split(line, ',');
	line[i] = tmp;
	if (!rgb && set_sgt_error(10))
		return (1);
	cmb = ((atoi(rgb[0]) << 16) | (atoi(rgb[1]) << 8) | (atoi(rgb[2])));
	assets->floor = cmb;
	free_split(rgb);
	return (0);
}

int	parse_ceiling(char *line)
{
	int			cmb;
	char		**rgb;
	int			i;
	char		tmp;
	t_assets	*assets;

	i = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	assets = sgt_assets();
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	tmp = line[i];
	line[i] = '\0';
	rgb = ft_split(line, ',');
	line[i] = tmp;
	if (!rgb && set_sgt_error(10))
		return (1);
	cmb = ((atoi(rgb[0]) << 16) | (atoi(rgb[1]) << 8) | (atoi(rgb[2])));
	assets->ceiling = cmb;
	free_split(rgb);
	return (0);
}
