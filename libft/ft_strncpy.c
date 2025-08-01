/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:01:24 by inicoara          #+#    #+#             */
/*   Updated: 2025/04/18 14:19:40 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*
	Copy src inot dest...
	copy n character into dst + 1 which is null character
	Assuming that the dst has always enouph space to add
	a null character.
    If n <= 0 it does nothing
*/
void	ft_strncpy(char *dst, const char *src, size_t n)
{
	int	i;

	if (n <= 0)
		return ;
	i = 0;
	while (n--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}
