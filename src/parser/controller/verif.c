/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:55:44 by inicoara          #+#    #+#             */
/*   Updated: 2025/10/01 03:05:13 by inicoara         ###   ########.fr       */
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
    printf("argv[1] %s\n", argv[1]);
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
