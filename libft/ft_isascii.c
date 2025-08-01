/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:14:28 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:30 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int main()
// {
//     int i = 0;
//     while (ft_isascii(i) ==  isascii(i) && i < 128)
//         i++;
//     printf("%d\n", i);
//     printf("%d:%d\n", ft_isascii('0'), isascii('0'));
//     printf("%d:%d\n", ft_isascii(' '), isascii(' '));

// }
