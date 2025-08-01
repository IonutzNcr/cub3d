/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:20:16 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:20:17 by inicoara         ###   ########.fr       */
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

// char ft_toupper(unsigned int p, char s)
// {
//     if(s >= 'a' && s <= 'z')
//         return (s + ('A' - 'a'));

//     return (s);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	char	*tmp;
	int		i;

	i = 0;
	l = ft_strlen(s);
	tmp = (char *)malloc(l + 1);
	if (!tmp)
		return (0);
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

// int main(void)
// {
//     printf("%s \n", ft_strmapi("trop BIen wtf", ft_toupper));
// }
