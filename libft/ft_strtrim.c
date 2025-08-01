/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:24 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 15:14:07 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static int	is_inset(char c, char const *set)
{
	int	l;
	int	i;

	i = 0;
	l = ft_strlen(set);
	while (i < l)
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		index_start;
	int		index_end;
	char	*dix;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (is_inset(s1[i], set))
		i++;
	index_start = i;
	while (is_inset(s1[k], set))
		k--;
	index_end = k;
	if (i == ft_strlen(s1))
		dix = (char *)malloc(sizeof(char) * 1);
	else
		dix = (char *)malloc(sizeof(char) * (index_end - index_start + 1) + 1);
	if (!dix)
		return (0);
	i = 0;
	while (index_start <= index_end && s1[index_start])
		dix[i++] = s1[index_start++];
	dix[i] = '\0';
	return (dix);
}
