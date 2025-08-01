/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:45 by inicoara          #+#    #+#             */
/*   Updated: 2025/05/25 21:56:14 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/*int main()
 {
	char s[] = "test";
	//  printf("%s : %s\n", ft_strchr("ionut le bg", 't'), strchr("ionut le bg",
	//		't'));
	//  printf("%d \n", ft_strchr("", 't') == strchr("", 't'));
	//   printf("%d \n", ft_strchr("ionut le bg", 255) == strchr("ionut le bg",
	//		255));
	printf("%d \n", ft_strchr(s, '\0') == s + 5);
 }*/
