/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:18:36 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:42:12 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*join;
	char	*tmp;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	join = (char *)malloc(i + k + 1);
	if (!join)
		return (0);
	tmp = join;
	while (i--)
		*join++ = *s1++;
	while (k--)
		*join++ = *s2++;
	*join = '\0';
	return (tmp);
}
