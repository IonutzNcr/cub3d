/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:20:46 by inicoara          #+#    #+#             */
/*   Updated: 2025/03/18 18:20:59 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	unsigned int	t;

	t = 0;
	while (*s++)
		t++;
	return (t);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n--)
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (*--s1 - *--s2);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (*big && i++ + ft_strlen(little) <= len)
	{
		if (!ft_strncmp(big, little, ft_strlen(little)))
			return ((char *)big);
		big++;
	}
	return (NULL);
}

// int main()
// {
//     const char *tmp = "Super la ie";
//     printf("%s, %s\n", ft_strnstr(tmp, "la", 3), strnstr(tmp, "la", 3));
//     printf("%d\n", ft_strnstr(tmp, "la", 3) == strnstr(tmp, "la", 3));
//       printf("%s, %s\n", ft_strnstr(tmp, "", 10), strnstr(tmp, "la", 10));
//     printf("%d\n", ft_strnstr(tmp, "", 10) == strnstr(tmp, "", 10));

// }
