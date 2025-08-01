/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:07 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/22 17:20:18 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + i));
	s = s + i - 1;
	while (i-- > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}

/* int main()
 {
		printf("%s : %s\n", ft_strrchr("ionut le tbg",  256),
			strrchr("ionut le tbg",  256));
		printf("%d \n", ft_strrchr("", 't') == strrchr("", 't'));
		printf("%d \n", ft_strrchr("ionut le bg", 255) == strrchr("ionut le bg",
				255));

		printf("%d \n", ft_strrchr("ionut le bg", 0) == strrchr("ionut le bg",
				0));
 }*/
