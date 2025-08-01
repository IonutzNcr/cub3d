/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:05 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:39:20 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && s + n >= d)
	{
		i = n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
