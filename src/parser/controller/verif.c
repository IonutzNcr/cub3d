/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:55:44 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/06 16:27:25 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_file_valid(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	quick_verif(int argc, char *argv[], char *env[])
{
	if (argc != 2 && set_sgt_error(P_NUM))
		return (print_error());
	if ((!env || !*env) && set_sgt_error(NO_ENV))
		return (print_error());
	if (!is_extension(argc, argv, env) && set_sgt_error(INV_EXT))
		return (print_error());
	if (!is_file_valid(argv[1]) && set_sgt_error(NO_FILE))
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
