/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:14:06 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:08 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

// int main()
// {
//     printf("%d:%d\n", ft_isalpha('*'), isalpha('*'));
//     printf("%d:%d\n", ft_isalpha('c'), isalpha('c'));
//     printf("%d:%d\n", ft_isalpha('Z'), isalpha('Z'));
//     printf("%d:%d\n", ft_isalpha(55), isalpha(55));
//     printf("%d:%d\n", ft_isalpha(555), isalpha(555));
// }
