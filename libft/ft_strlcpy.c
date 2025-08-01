/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:36 by inicoara          #+#    #+#             */
/*   Updated: 2025/04/01 18:28:41 by inicoara         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	if (siz > ft_strlen(src))
	{
		while (i < ft_strlen(src))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (i < siz - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main()
 {
//     //test 1 classique dest = src
//     char const *t0 = "Je suis";
//     char const *c0 = "Je suis"; //8 or 7 if not null
//     char dest0[5];
//     char destc0[5];
//     printf("return (%ld: %ld\n", ft_strlcpy(dest0,  t0, 3), strlcpy(destc0,
		c0, 3)));
//     printf("copy %s: copy2 %s\n", dest0, destc0);
//     //strlcpy(destc0, c0, 4);
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	printf("%d\n", ft_strlcpy(dest, src, -1) == strlen(src));
	printf("%d\n", !strcmp(src, dest));
	printf("%d\n", dest[strlen(src) + 1] == 'A');
 }*/
