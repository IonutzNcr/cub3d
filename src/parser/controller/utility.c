/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:03:44 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 07:07:37 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_split(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

int	count_elements(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_singleton(void)
{
	remove_map();
	remove_assets();
}
