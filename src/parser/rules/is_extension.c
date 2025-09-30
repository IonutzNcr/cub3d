/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:33:19 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:33:20 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_extension(int argc, char *argv[], char *env[])
{
	char	*pathfile;

	pathfile = argv[1];
	(void)argc;
	(void)env;
	while (*pathfile && *pathfile != '.')
		pathfile++;
	if (*pathfile == '\0')
		return (0);
	if (!ft_strncmp(pathfile, ".cub", 4) && ft_strlen(pathfile) == 4)
		return (1);
	return (0);
}
