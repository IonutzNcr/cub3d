/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:11:48 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:11:50 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (8);
	if (c >= '0' && c <= '9')
		return (8);
	return (0);
}

// int main()
// {
//     printf("%d:%d\n", ft_isalnum('*'), isalnum('*'));
//     printf("%d:%d\n", ft_isalnum('W'), isalnum('W'));
//     printf("%d:%d\n", ft_isalnum('9'), isalnum('9'));
//     printf("%d:%d\n", ft_isalnum(55), isalnum(55));
//     printf("%d:%d\n", ft_isalnum(555), isalnum(555));
//     printf("%d:%d\n", ft_isalnum(' '), isalnum(' '));
// }
