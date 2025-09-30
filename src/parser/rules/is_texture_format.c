/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:55:22 by yoyo              #+#    #+#             */
/*   Updated: 2025/09/30 22:11:31 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_texture_no(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO", 2))
		return (0);
	line += 2;
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	if (ft_strncmp(line, "./", 2) && ft_strncmp(line, "/", 1))
		return (0);
	while (*line && !is_invalid_space(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

int	is_texture_so(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "SO", 2))
		return (0);
	line += 2;
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	if (ft_strncmp(line, "./", 2) && ft_strncmp(line, "/", 1))
		return (0);
	while (*line && !is_invalid_space(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

int	is_texture_we(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "WE", 2))
		return (0);
	line += 2;
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	if (ft_strncmp(line, "./", 2) && ft_strncmp(line, "/", 1))
		return (0);
	while (*line && !is_invalid_space(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

int	is_texture_ea(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "EA", 2))
		return (0);
	line += 2;
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	if (ft_strncmp(line, "./", 2) && ft_strncmp(line, "/", 1))
		return (0);
	while (*line && !is_invalid_space(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}
