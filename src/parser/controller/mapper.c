/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:59:53 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 00:59:57 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	mapper(char *line, int fd)
{
	if (map_parser(line))
		return (free(line), empty_gnl(fd), print_error());
	free(line);
	while (wgnl(&line, fd))
	{
		if (*line == '\0' && set_sgt_error(13)) // empty line in map
			return (free_singleton(), *sgt_error());
		if (map_parser(line))
			return (free_singleton(), free(line), empty_gnl(fd), print_error());
		free(line);
	}
	if (map_fixer() || map_checker())
		return (free_singleton(), print_error());
	return (0);
}
