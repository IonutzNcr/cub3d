/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:18:02 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:41:57 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		l;

	l = 0;
	while (s[l])
		l++;
	dest = (char *)malloc(sizeof(char) * l + 1);
	if (!dest)
		return (0);
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (dest - l);
}

// int main()
// {
//     printf("%s : %s \n", ft_strdup("super la vie"), strdup("super la vie"));
//     printf("%s : %s \n", ft_strdup(""), strdup(""));

// }
