/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:23:03 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 14:31:00 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static char	*ft_null_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	char		*tmp;
	long long	expression;

	expression = ft_strlen(s) - 1 - start + 1;
	if (expression <= 0)
		return (ft_null_str());
	if ((size_t)expression >= len)
		substr = (char *)malloc(len + 1);
	else
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - 1 - start + 1
					+ 1));
	if (!substr)
		return (0);
	tmp = substr;
	while (s[start] && len--)
	{
		*substr++ = s[start++];
	}
	*substr = '\0';
	return (tmp);
}
