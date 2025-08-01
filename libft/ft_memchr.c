/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:15:19 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:15:21 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (0);
}

// int main()
// {
//      int i = 0;
//     char const arr[4] = {'a', 'b', 'c', '\0'};
//     char const parr[4] = {'a', 'b', 'c', '\0'};
//     char *tmp = ft_memchr(arr, 'b', 4 * sizeof(char));
//     char *tmp2 = memchr(arr, 'b', 4 * sizeof(char));
//     printf("arr: %s parr: %s \n", tmp, tmp2);
// }
