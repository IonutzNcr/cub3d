/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:14:47 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:43:13 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_strncat(char *dst, const char *src, size_t n)
{
	int	i;
	int	k;

	if (n <= 0)
		return ;
	i = 0;
	k = ft_strlen(dst);
	while (n--)
		dst[k++] = src[i++];
	dst[k] = '\0';
	return ;
}
