/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:59:53 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 06:20:23 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/* 
static int checked_empty_line(char *line)
{
	int is_empty;

	is_empty = 0;
	printf("line = %s\n", line);
	printf("len = %d\n", ft_strlen(line));
	if (*line == '\0')
	{
		is_empty = 1;
	}
	return (is_empty);
} */

int	mapper(char *line, int fd)
{
	if (map_parser(line))
		return (free_singleton(), free(line), empty_gnl(fd), print_error());
	free(line);
	while (wgnl(&line, fd))
	{
		if (*line == '\0' && set_sgt_error(13))
			return (free_singleton(), free(line), empty_gnl(fd), print_error());
		if (map_parser(line))
			return (free_singleton(), free(line), empty_gnl(fd), print_error());
		free(line);
	}
	if (map_fixer() || map_checker())
		return (free_singleton(), print_error());
	return (0);
}
