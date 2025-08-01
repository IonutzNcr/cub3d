/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:28 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 12:31:16 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count_line(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (!(*(s + 1) == c) && *(s + 1))
				l++;
		}
		else if (l == 0)
			l++;
		s++;
	}
	return (l);
}

static char	*ft_create_line(char **tab, char const *s, char c)
{
	int			words;
	char const	*tmp;
	char		*line;
	int			i;

	words = 0;
	tmp = s;
	i = 0;
	while (!(*s == c) && *s)
	{
		words++;
		s++;
	}
	line = (char *)malloc(sizeof(char) * words + 1);
	if (!line)
		return (0);
	while (words--)
		line[i++] = *tmp++;
	line[i] = '\0';
	*tab = line;
	return ((char *)--s);
}

char	**ft_freechakal(int i, char **tmp)
{
	while (i--)
	{
		free(tmp[i]);
	}
	free(tmp);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	if (!s)
		return (0);
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_count_line(s, c) + 1));
	if (!tmp)
		return (0);
	tmp2 = tmp;
	while (*s)
	{
		if (!(*s == c))
		{
			s = ft_create_line(tmp, s, c);
			if (!s)
				return (ft_freechakal(i, tmp2));
			i++;
			tmp++;
		}
		s++;
	}
	*tmp = 0;
	return (tmp2);
}
