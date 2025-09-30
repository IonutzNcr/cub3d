/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:47:14 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/01 01:48:50 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	free_one(char *line)
{
	free(line);
	return (1);
}

static int	clear_valgrind(char *line, int fd)
{
	remove_assets();
	free(line);
	empty_gnl(fd);
	return (print_error());
}

static int	hard_verif2(t_task liste[6], char *line, int fd)
{
	if (!asset_checker(liste, line))
	{
		if (asset_parser(liste, line))
			return (clear_valgrind(line, fd));
	}
	else
		return (clear_valgrind(line, fd));
	free(line);
	return (0);
}

int	hard_verif(char *argv[])
{
	int		fd;
	t_task	liste[6];
	char	*line;

	init_list(liste);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error: "), 1);
	while (wgnl(&line, fd))
	{
		if (*line == '\0' && free_one(line))
			continue ;
		if (checked_list(liste))
		{
			if (mapper(line, fd))
				return (1);
		}
		else if (hard_verif2(liste, line, fd))
			return (1);
	}
	if (last_verif(liste))
		return (free_singleton(), print_error());
	return (0);
}
