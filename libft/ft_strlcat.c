/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:09 by inicoara          #+#    #+#             */
/*   Updated: 2025/03/18 18:28:05 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	long unsigned int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	index_start;
	size_t	index_src;
	size_t	tmpldst;

	if (siz == 0)
		return (ft_min(ft_strlen(dst), siz) + ft_strlen(src));
	if (siz <= ft_strlen(dst))
		return (ft_min(ft_strlen(dst), siz) + ft_strlen(src));
	index_start = ft_strlen(dst);
	tmpldst = index_start;
	index_src = 0;
	while (index_start < siz - 1 && src[index_src])
	{
		dst[index_start++] = src[index_src++];
	}
	dst[index_start] = '\0';
	return (tmpldst + ft_strlen(src));
}

/*int main()
{
	 char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
 dest[0] = 'B';
	printf("%d\n",ft_strlcat(dest, src, -1) == 14);
}*/
