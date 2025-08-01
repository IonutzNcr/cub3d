/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:14:39 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:41 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

// int main()
// {
//     printf("%d:%d\n", ft_isdigit('0'), isdigit('0'));
//     printf("%d:%d\n", ft_isdigit('1'), isdigit('1'));
//     printf("%d:%d\n", ft_isdigit('9'), isdigit('9'));
//     printf("%d:%d\n", ft_isdigit(55), isdigit(55));
//     printf("%d:%d\n", ft_isdigit(555), isdigit(555));
// }
