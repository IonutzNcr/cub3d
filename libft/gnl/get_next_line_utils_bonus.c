/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:08:15 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/27 18:34:44 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **a, char **b)
{
	if (a)
	{
		free(*a);
		*a = NULL;
	}
	if (b)
	{
		free(*b);
		*b = NULL;
	}
	return ((void *) NULL);
}

ssize_t	ft_index_line(char *s, char c)
{
	ssize_t	i;
	ssize_t	psx;

	if (!s)
		return (-1);
	i = 0;
	psx = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			psx = i;
			break ;
		}
		i++;
	}
	return (psx);
}
