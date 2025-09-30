/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:11:36 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:11:37 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	quick_verif(int argc, char *argv[], char *env[])
{
	if (argc != 2 && set_sgt_error(P_NUM))
		return (print_error());
	if ((!env || !*env) && set_sgt_error(NO_ENV))
		return (print_error());
	if (!is_extension(argc, argv, env) && set_sgt_error(INV_EXT))
		return (print_error());
	if (is_file_empty(argv[1]) && set_sgt_error(E_SCENE))
		return (print_error());
	return (0);
}

int	last_verif(t_task liste[6])
{
	if (!checked_list(liste))
		return (set_sgt_error(10));
	if (!*sgt_map())
		return (set_sgt_error(11));
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
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		if (checked_list(liste))
		{
			if (mapper(line, fd))
				return (1);
		}
		else
		{
			if (!asset_checker(liste, line))
			{
				if (asset_parser(liste, line))
					return (remove_assets(), free(line), empty_gnl(fd),
						print_error());
			}
			else
				return (remove_assets(), free(line), empty_gnl(fd),
					print_error());
			free(line);
		}
	}
	if (last_verif(liste))
		return (free_singleton(), print_error());
	return (0);
}
