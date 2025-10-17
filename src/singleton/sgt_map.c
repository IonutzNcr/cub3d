/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:28:50 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:29:21 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_remalloc(void *old, int n_size, int old_size)
{
	void			*map;
	unsigned char	*dest;
	unsigned char	*src;

	if (n_size == 0)
		return (0);
	src = old;
	map = malloc(n_size);
	if (!map)
		return (0);
	dest = map;
	while (old_size--)
		dest[old_size] = src[old_size];
	return (dest);
}

char	**get_row(int row)
{
	char	**map;
	int		k;

	map = *sgt_map();
	k = count_elements(map);
	if (row > k - 1)
		return (NULL);
	return (&map[row]);
}

int	remove_map(void)
{
	char	**map;
	int		i;

	i = 0;
	map = *sgt_map();
	if (!map)
		return (0);
	while (map[i])
		free(map[i++]);
	free(map);
	*sgt_map() = 0;
	return (0);
}

int	add_line(char *line)
{
	char	**map;
	int		nb;

	if (!*sgt_map())
	{
		map = malloc(sizeof(char *) * (1 + 1));
		if (!map)
			return (10);
		*map = ft_strdup(line);
		*(map + 1) = 0;
		*sgt_map() = map;
	}
	else
	{
		nb = count_elements(*sgt_map());
		map = ft_remalloc(*sgt_map(), (nb + 2) * sizeof(char *), (nb + 1)
				* sizeof(char *));
		if (!map)
			return (10);
		free(*sgt_map());
		*(map + nb) = ft_strdup(line);
		*(map + nb + 1) = 0;
		*sgt_map() = map;
	}
	return (0);
}

char	***sgt_map(void)
{
	static char	**map;

	return (&map);
}
