/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:33:19 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/05 17:17:56 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_extension(int argc, char *argv[], char *env[])
{
	char	*pathfile;
    int i;

    i = 0;
	pathfile = argv[1];
	(void)argc;
	(void)env;
	while (pathfile[i] && pathfile[i] != '.')
		i++;
	if (pathfile[i] == '\0')
		return (0);
	if (!ft_strncmp(&pathfile[i], ".cub", 4) && ft_strlen(&pathfile[i]) == 4)
		return (1);
	return (0);
}
